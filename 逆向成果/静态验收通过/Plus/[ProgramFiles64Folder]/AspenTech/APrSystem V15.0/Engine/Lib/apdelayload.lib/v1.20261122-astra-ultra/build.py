"""Assemble delaylod.obj and write its two-index MS COFF library. Python 3.10+."""
import argparse
import binascii
import hashlib
import struct
import subprocess
import tempfile
from pathlib import Path


def declarations(source):
    sections = []
    symbols = []
    timestamp = member = None
    for line in source.read_text(encoding="utf-8").splitlines():
        if not line.startswith("#@"):
            continue
        kind, definition = line[2:].split(" ", 1)
        if kind == "timestamp":
            timestamp = int(definition)
        elif kind == "member":
            member = definition.encode("ascii") + b"\0"
        elif kind == "section":
            number, name, flags, parent, selection = definition.split()
            if int(number) != 1 + len(sections):
                raise ValueError("Out-of-order section declaration")
            sections.append((name, int(flags, 0), int(parent), int(selection)))
        elif kind == "symbol":
            label, name, section, typ, storage, *value = definition.split()
            symbols.append((label, name, int(section), int(typ), int(storage),
                            int(value[0], 0) if value else 0))
        else:
            raise ValueError(f"Unknown declaration {kind}")
    return timestamp, member, sections, symbols


class GasObject:
    """Labels and relocations in the intermediate AMD64 object produced by GNU as."""

    def __init__(self, data):
        self.data = data
        machine, section_count, _, table, count, optional, _ = struct.unpack_from("<HHIIIHH", data)
        if (machine, optional) != (0x8664, 0):
            raise ValueError("An AMD64 COFF assembler is required")
        strings = table + 18 * count
        self.labels = {}
        self.names = {}
        index = 0
        while index < count:
            at = table + index * 18
            field = data[at:at + 8]
            if field[:4] == bytes(4):
                offset = strings + int.from_bytes(field[4:], "little")
                name = data[offset:data.index(0, offset)]
            else:
                name = field.rstrip(b"\0")
            name = name.decode("ascii")
            value, section, _, _, aux = struct.unpack_from("<IhHBB", data, at + 8)
            self.labels[name] = (section, value)
            self.names[index] = name
            index += 1 + aux
        self.sections = {}
        for index in range(section_count):
            at = 20 + index * 40
            field, _, _, size, raw, rel, _, nrel, _, _ = struct.unpack_from("<8sIIIIIIHHI", data, at)
            name = field.rstrip(b"\0").decode("ascii")
            self.sections[name] = (index + 1, raw, size, rel, nrel)

    def contribution(self, index, symbol_indices):
        section, start, padded_size, relocations, count = self.sections[f".ap{index:02}"]
        end_sec, size = self.labels[f"end_ap{index:02}"]
        if end_sec != section or size > padded_size:
            raise ValueError(f"Invalid contribution length for section {index}")
        data = bytearray(self.data[start:start + size])
        fixes = bytearray()
        for entry in range(count):
            at, target, kind = struct.unpack_from("<IIH", self.data, relocations + 10 * entry)
            prefix, _, name = self.names[target].partition("_")
            if at + 4 > size:
                raise ValueError("Relocation crosses the end of its section")
            if prefix == "rva" and kind in (2, 3, 0x11):
                kind = 3  # IMAGE_REL_AMD64_ADDR32NB
            elif prefix == "tail1" and kind == 4:
                addend = struct.unpack_from("<i", data, at)[0]
                struct.pack_into("<i", data, at, addend + 1)
                kind = 5  # IMAGE_REL_AMD64_REL32_1
            elif prefix != "ref" or kind != 4:
                raise ValueError(f"Unsupported relocation {kind} to {self.names[target]}")
            fixes.extend(struct.pack("<IIH", at, symbol_indices[name], kind))
        return bytes(data), bytes(fixes)


def assemble_coff(gas, sections, symbols, timestamp):
    indices = {}
    count = 0
    for label, *_ in symbols:
        indices[label] = count
        count += 2 if label.startswith("section_") else 1

    contributions = []
    headers = bytearray()
    payload = bytearray()
    for i, (name, flags, _, _) in enumerate(sections, 1):
        data, rels = gas.contribution(i, indices)
        if name == ".chks64":
            # MSVC records the first 64 bits of each file-backed section's SHA-256.
            # The .chks64 entry itself and file-less BSS contributions have zero entries.
            data = b"".join(hashlib.sha256(raw).digest()[:8] if raw else bytes(8)
                            for _, raw, _ in contributions) + bytes(8)
        size = len(data)
        if flags & 0x80:
            if any(data):
                raise ValueError("An uninitialized section contains nonzero data")
            data = b""
        pos = 20 + 40 * len(sections) + len(payload)
        headers.extend(struct.pack("<8sIIIIIIHHI", name.encode(), 0, 0, size,
                                   pos if data else 0, pos + len(data) if rels else 0,
                                   0, len(rels) // 10, 0, flags))
        payload.extend(data + rels)
        contributions.append((size, data, len(rels) // 10))

    entries = bytearray()
    strings = bytearray()
    string_offsets = {}
    for label, name, sec, typ, storage, absolute_value in symbols:
        field = name.encode("ascii")
        if len(field) > 8:
            if field not in string_offsets:
                string_offsets[field] = 4 + len(strings)
                strings.extend(field + b"\0")
            field = struct.pack("<II", 0, string_offsets[field])
        value = absolute_value
        if sec > 0:
            label_section, value = gas.labels[label]
            if label_section != gas.sections[f".ap{sec:02}"][0]:
                raise ValueError(f"Misplaced label {label}")
        is_section = label.startswith("section_")
        entries.extend(struct.pack("<8sIhHBB", field, value, sec, typ, storage, is_section))
        if is_section:
            size, data, nrel = contributions[sec - 1]
            name, _, parent, selection = sections[sec - 1]
            crc = 0
            if name not in (".drectve", ".debug$S", ".chks64") and data:
                crc = binascii.crc32(data, 0xffffffff) ^ 0xffffffff
            entries.extend(struct.pack("<IHHIHBBH", size, nrel, 0, crc, parent, selection, 0, 0))
    table_offset = 20 + len(headers) + len(payload)
    head = struct.pack("<HHIIIHH", 0x8664, len(sections), timestamp, table_offset, count, 0, 0)
    return head + headers + payload + entries + struct.pack("<I", 4 + len(strings)) + strings


def archive(member, obj, symbols, timestamp):
    exports = sorted(name for _, name, sec, _, storage, _ in symbols if sec > 0 and storage == 2)
    names = b"".join(name.encode("ascii") + b"\0" for name in exports)
    n = len(exports)

    def entry(name, data, mode=0):
        header = f"{name:<16}{timestamp:<12}{'':<6}{'':<6}{mode:<8}{len(data):<10}".encode("ascii")
        return header + b"\x60\n" + data + (b"\n" if len(data) % 2 else b"")

    # The linker indices contain archive header offsets, so compute the member position first.
    first_length = 4 + 4 * n + len(names)
    second_length = 12 + 2 * n + len(names)
    member_offset = 8 + sum(60 + size + size % 2 for size in (first_length, second_length, len(member)))
    first = struct.pack(">I", n) + struct.pack(">I", member_offset) * n + names
    second = struct.pack("<III", 1, member_offset, n) + struct.pack("<H", 1) * n + names
    return b"!<arch>\n" + entry("/", first) + entry("/", second) + entry("//", member) + entry("/0", obj, 100666)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--assembler", default="x86_64-w64-mingw32-as")
    parser.add_argument("--object", type=Path, help="also write the COFF object for inspection")
    args = parser.parse_args()
    timestamp, member, sections, symbols = declarations(args.source)
    with tempfile.TemporaryDirectory(dir=args.output.parent) as temp:
        intermediate = Path(temp) / "assembly.obj"
        subprocess.run([args.assembler, "-o", str(intermediate), str(args.source)], check=True)
        obj = assemble_coff(GasObject(intermediate.read_bytes()), sections, symbols, timestamp)
    result = archive(member, obj, symbols, timestamp)
    if args.object:
        args.object.write_bytes(obj)
    args.output.write_bytes(result)


if __name__ == "__main__":
    main()

