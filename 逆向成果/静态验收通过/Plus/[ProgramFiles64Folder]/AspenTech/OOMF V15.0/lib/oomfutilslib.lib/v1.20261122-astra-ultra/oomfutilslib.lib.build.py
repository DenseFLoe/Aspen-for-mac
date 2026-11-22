"""Assemble the editable Intel-syntax source into a Microsoft x64 COFF archive.

Usage: python oomfutilslib.lib.build.py input.asm output.lib --asmjit PATH/TO/x64/asmjit.dll
Requires 64-bit Windows Python and the x64dbg edition of AsmJit/AsmTK.
The source is the only build input apart from the instruction assembler.
"""

import argparse
from collections import OrderedDict
import ctypes
from dataclasses import dataclass, field
from functools import lru_cache
import json
from pathlib import Path
import re
import struct


class AssemblerRequest(ctypes.Structure):
    _fields_ = [
        ("x64", ctypes.c_bool), ("cip", ctypes.c_uint64), ("size", ctypes.c_uint),
        ("symbol_callback", ctypes.c_void_p), ("dest", ctypes.c_ubyte * 16),
        ("instr", ctypes.c_char * 256), ("error", ctypes.c_char * 256),
    ]


class Assembler:
    def __init__(self, path):
        self.library = ctypes.CDLL(str(path.resolve()))
        self.call = self.library.XEDParseAssemble
        self.call.argtypes = [ctypes.POINTER(AssemblerRequest)]
        self.call.restype = ctypes.c_int

    @lru_cache(maxsize=8192)
    def instruction(self, line):
        # Local branch operands are relative to a fixed virtual origin.
        request = AssemblerRequest(x64=True, cip=BASE, instr=line.encode("ascii"))
        if self.call(ctypes.byref(request)) != 1:
            raise ValueError(f"{line}: {request.error.decode()}")
        return bytes(request.dest[:request.size])


BASE = 0x100000
SENTINEL = 0x60616263
REGISTERS = "rax rcx rdx rbx rsp rbp rsi rdi r8 r9 r10 r11 r12 r13 r14 r15".split()
RELOCATION = re.compile(r"reloc\(([^(), ]+)(?:, ([^()]+))?\)")
BRANCH = re.compile(r"(short|long) (j[a-z]+) ([.$\w]+)$")


@dataclass
class Section:
    name: str
    flags: int
    lines: list = field(default_factory=list)
    size: int = 0
    data: bytes = b""
    relocations: list = field(default_factory=list)


@dataclass
class Member:
    name: str
    timestamp: int
    index: list = field(default_factory=list)
    symbols: dict = field(default_factory=OrderedDict)
    sections: dict = field(default_factory=OrderedDict)
    labels: dict = field(default_factory=dict)


def parse(path):
    members = []
    timestamp = None
    member = None
    section = None
    for number, raw in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        line = raw.strip()
        if not line or line.startswith(";"):
            continue
        token, _, arg = line.partition(" ")
        if token == ".archive":
            timestamp = int(arg)
        elif token == ".member":
            name, stamp = arg.rsplit(" ", 1)
            member = Member(name, int(stamp))
            members.append(member)
            section = None
        elif token == ".index":
            member.index.extend(arg.split())
        elif token == ".symbol":
            name, kind, scope, *rest = arg.split()
            if name in member.symbols:
                raise ValueError(f"duplicate COFF symbol {name}")
            member.symbols[name] = (kind, scope, rest)
        elif token == ".section":
            name, flags = arg.split()
            section = Section(name, int(flags, 0))
            member.sections[name] = section
        elif section is not None:
            section.lines.append((number, line))
        else:
            raise ValueError(f"unexpected line {number}: {line}")
    if timestamp is None or not members:
        raise ValueError("missing archive header or object declarations")
    return timestamp, members


def expression(text, labels):
    """Evaluate section-relative label arithmetic, without evaluating Python."""
    parts = text.split()
    value = 0
    for i in range(0, len(parts), 2):
        word = parts[i]
        term = labels[word][1] if word in labels else int(word, 0)
        if i and parts[i - 1] not in ("+", "-"):
            raise ValueError(f"invalid expression: {text}")
        value += -term if i and parts[i - 1] == "-" else term
    return value


def unwind_bytes(header, operations, labels, measure):
    function, end_prologue, frame_reg, frame_offset = header.split(", ")
    def units(value, scale):
        value = int(value, 0)
        if value < 0 or value % scale:
            raise ValueError(f"{value} must be a nonnegative multiple of {scale}")
        return value // scale

    def delta(target):
        return 0 if measure else labels[target][1] - labels[function][1]
    ops = bytearray()
    for kind, args in operations:
        at, *values = args.split(", ")
        where = delta(at)
        if kind == ".push_nonvol":
            ops.extend([where, REGISTERS.index(values[0]) << 4])
        elif kind == ".set_fpreg":
            ops.extend([where, 3])
        elif kind == ".save_nonvol":
            reg, offset = values
            ops.extend([where, REGISTERS.index(reg) << 4 | 4])
            ops.extend(struct.pack("<H", units(offset, 8)))
        elif kind == ".alloc_large":
            ops.extend([where, 1])
            ops.extend(struct.pack("<H", units(values[0], 8)))
        elif kind == ".alloc_small":
            ops.extend([where, ((units(values[0], 8) - 1) << 4) | 2])
        else:
            raise ValueError(f"unknown unwind operation {kind}")
    slots = len(ops) // 2
    frame = REGISTERS.index(frame_reg) | (units(frame_offset, 16) << 4)
    return bytes([1, delta(end_prologue), slots, frame]) + ops + bytes((slots % 2) * 2)


def assemble_code(line, pc, member, assembler, measure):
    branch = BRANCH.fullmatch(line)
    if branch:
        width, mnemonic, label = branch.groups()
        distance = 0 if measure else member.labels[label][1] - pc
        if not measure and member.labels[label][0] != ".text":
            raise ValueError(f"branch outside .text: {label}")
        return assembler.instruction(f"{width} {mnemonic} {BASE + distance:#x}"), None
    ref = RELOCATION.search(line)
    if not ref:
        return assembler.instruction(line), None
    symbol, addend = ref.groups()
    if symbol not in member.symbols:
        raise ValueError(f"unknown COFF symbol {symbol}")
    is_call = line.startswith("call ")
    numeric = BASE + 5 + SENTINEL if is_call else SENTINEL
    encoded = assembler.instruction(line[:ref.start()] + hex(numeric) + line[ref.end():])
    marker = struct.pack("<I", SENTINEL)
    offset = 1 if is_call else encoded.index(marker)
    if encoded[offset:offset + 4] != marker:
        raise ValueError(f"missing displacement: {line}")
    trailing = len(encoded) - offset - 4
    if trailing not in (0, 4):
        raise ValueError(f"unexpected REL32 suffix for {line}")
    value = 0 if measure or not addend else expression(addend, member.labels)
    return (encoded[:offset] + struct.pack("<i", value) + encoded[offset + 4:],
            (pc + offset, symbol, 4 + trailing))


def assemble_sections(member, assembler, measure):
    for sec in member.sections.values():
        pc = 0
        data = bytearray()
        relocs = []
        operations = []
        header = None
        member.labels[sec.name] = (sec.name, 0)
        for number, line in sec.lines:
            try:
                cmd, _, arg = line.partition(" ")
                if line.endswith(":"):
                    name = line[:-1]
                    if measure and name in member.labels:
                        raise ValueError(f"duplicate label {name}")
                    if not measure and member.labels[name] != (sec.name, pc):
                        raise ValueError(f"unstable instruction width at {name}")
                    member.labels[name] = (sec.name, pc)
                    continue
                if cmd == ".unwind":
                    header, operations = arg, []
                    continue
                if cmd == ".endunwind":
                    chunk = unwind_bytes(header, operations, member.labels, measure)
                    header = None
                elif header is not None:
                    operations.append((cmd, arg))
                    continue
                elif cmd == ".space":
                    if sec.name != ".bss":
                        raise ValueError("uninitialized storage outside .bss")
                    pc += int(arg, 0)
                    continue
                elif cmd == ".zero":
                    chunk = bytes(int(arg, 0))
                elif cmd == ".ascii":
                    chunk = json.loads(arg).encode("ascii")
                elif cmd in (".byte", ".word", ".dword", ".qword"):
                    size = {".byte": 1, ".word": 2, ".dword": 4, ".qword": 8}[cmd]
                    chunk = b"".join(int(word, 0).to_bytes(size, "little") for word in arg.split(", "))
                elif cmd == ".rva":
                    symbol, sep, addend = arg.partition(", ")
                    value = 0 if measure or not sep else expression(addend, member.labels)
                    chunk = struct.pack("<I", value)
                    relocs.append((pc, symbol, 3))
                else:
                    if sec.name != ".text" or cmd.startswith("."):
                        raise ValueError("invalid section directive")
                    chunk, reloc = assemble_code(line, pc, member, assembler, measure)
                    if reloc is not None:
                        relocs.append(reloc)
                data.extend(chunk)
                pc += len(chunk)
            except Exception as exc:
                raise ValueError(f"line {number}, {member.name} {sec.name}+{pc:#x}: {line}") from exc
        if header is not None:
            raise ValueError("unclosed unwind record")
        if not measure and pc != sec.size:
            raise ValueError(f"unstable size of {sec.name}")
        sec.size, sec.data, sec.relocations = pc, bytes(data), relocs


def object_bytes(member):
    strings = bytearray()
    table = bytearray()
    indices = {}
    sections = list(member.sections.values())
    sec_ids = {s.name: i for i, s in enumerate(sections, 1)}
    for name, (kind, scope, extra) in member.symbols.items():
        indices[name] = len(table) // 18
        spelling = name.encode("ascii")
        if len(spelling) > 8:
            inline = struct.pack("<II", 0, 4 + len(strings))
            strings.extend(spelling + b"\0")
        else:
            inline = spelling.ljust(8, b"\0")
        aux = b""
        if kind == "section":
            s = member.sections[name]
            sec_id, value = sec_ids[name], 0
            aux = struct.pack("<IH12x", s.size, len(s.relocations))
        elif kind in ("external", "common"):
            sec_id, value = 0, int(extra[0], 0) if kind == "common" else 0
        else:
            section_name, value = member.labels[name]
            sec_id = sec_ids[section_name]
        sym_type = 32 if kind == "function" or (kind == "external" and extra == ["function"]) else 0
        storage_class = {"public": 2, "local": 3}[scope]
        table.extend(struct.pack("<8sIhHBB", inline, value, sec_id, sym_type, storage_class, bool(aux)) + aux)
    base = 20 + 40 * len(sections)
    raw, relocation_bytes, headers = bytearray(), bytearray(), bytearray()
    reloc_base = base + sum(len(s.data) for s in sections)
    for sec in sections:
        raw_off = 0 if sec.name == ".bss" else base + len(raw)
        rel_off = reloc_base + len(relocation_bytes) if sec.relocations else 0
        headers.extend(struct.pack("<8sIIIIIIHHI", sec.name.encode("ascii"), 0, 0, sec.size,
                                   raw_off, rel_off, 0, len(sec.relocations), 0, sec.flags))
        raw.extend(sec.data)
        for off, target, kind in sec.relocations:
            relocation_bytes.extend(struct.pack("<IIH", off, indices[target], kind))
    header = struct.pack("<HHIIIHH", 0x8664, len(sections), member.timestamp,
                         reloc_base + len(relocation_bytes), len(table) // 18, 0, 0)
    return header + headers + raw + relocation_bytes + table + struct.pack("<I", 4 + len(strings)) + strings


def ar_member(name, timestamp, mode, payload):
    heading = f"{name:<16}{timestamp:<12}{'':12}{mode:<8}{len(payload):<10}\x60\n"
    if len(heading) != 60:
        raise ValueError(f"invalid archive header for {name}")
    return heading.encode("ascii") + payload + (b"\n" if len(payload) % 2 else b"")


def archive_bytes(timestamp, members, objects):
    longnames = bytearray()
    records = []
    indexed = []
    for i, (member, obj) in enumerate(zip(members, objects)):
        records.append(ar_member(f"/{len(longnames)}", member.timestamp, "100666", obj))
        longnames.extend(member.name.encode("ascii") + b"\0")
        for name in member.index:
            if name not in member.symbols or member.symbols[name][1] != "public":
                raise ValueError(f"invalid archive symbol {name}")
            indexed.append((name, i))
    ordered = sorted(indexed)
    names1 = b"".join(name.encode("ascii") + b"\0" for name, _ in indexed)
    names2 = b"".join(name.encode("ascii") + b"\0" for name, _ in ordered)
    def metadata(offsets):
        first = struct.pack(">I", len(indexed)) + b"".join(struct.pack(">I", offsets[i]) for _, i in indexed) + names1
        second = (struct.pack("<I", len(members)) + b"".join(struct.pack("<I", off) for off in offsets)
                  + struct.pack("<I", len(ordered)) + b"".join(struct.pack("<H", i + 1) for _, i in ordered) + names2)
        return (b"!<arch>\n" + ar_member("/", timestamp, "0", first) + ar_member("/", timestamp, "0", second)
                + ar_member("//", timestamp, "0", longnames))
    pos = len(metadata([0] * len(members)))
    offsets = []
    for rec in records:
        offsets.append(pos)
        pos += len(rec)
    return metadata(offsets) + b"".join(records)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--asmjit", required=True, type=Path)
    args = parser.parse_args()
    timestamp, members = parse(args.source)
    assembler = Assembler(args.asmjit)
    objects = []
    for member in members:
        assemble_sections(member, assembler, True)
        assemble_sections(member, assembler, False)
        objects.append(object_bytes(member))
    args.output.write_bytes(archive_bytes(timestamp, members, objects))


if __name__ == "__main__":
    main()
