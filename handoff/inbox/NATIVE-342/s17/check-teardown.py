"""Reassemble the shared teardown and compare its code, frame and transfers."""

from argparse import ArgumentParser
from hashlib import sha256
import csv
import json
from pathlib import Path
import struct
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies

START, END = 0x33AC0, 0x33B80
RANGE_SHA256 = "c72a98919f6453c002592f4a2ea5a26bc1eb0665d514772c2d3d5fcc8a12aa62"


def original_imports(pe):
    base = pe.OPTIONAL_HEADER.ImageBase
    names = {}
    for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
        for item in descriptor.imports:
            name = item.name.decode("ascii") if item.name else f"#{item.ordinal}"
            names[item.address - base] = f"{descriptor.dll.decode('ascii')}!{name}"
    return names


def parse_frames(pe, image):
    frames = {}
    for entry in pe.DIRECTORY_ENTRY_EXCEPTION:
        start, end, unwind = (entry.struct.BeginAddress, entry.struct.EndAddress,
                              entry.struct.UnwindData)
        if not START <= start < END:
            continue
        version_flags, prolog, slot_count, frame = struct.unpack_from("<BBBB", image, unwind)
        version, flags = version_flags & 7, version_flags >> 3
        assert version == 1 and flags in (0, 4) and frame == 0
        slot = 0
        codes = []
        while slot < slot_count:
            offset, op_info = struct.unpack_from("<BB", image, unwind + 4 + slot * 2)
            op, info = op_info & 15, op_info >> 4
            assert offset <= prolog
            if op == 0:
                code = ["PUSH_NONVOL", info]
            elif op == 2:
                code = ["ALLOC_SMALL", (info + 1) * 8]
            elif op == 4:
                assert slot + 1 < slot_count
                slot += 1
                saved_at, = struct.unpack_from("<H", image, unwind + 4 + slot * 2)
                code = ["SAVE_NONVOL", info, saved_at * 8]
            else:
                raise ValueError(f"Unexpected operation at unwind RVA {unwind:#x}")
            codes.append([offset, *code])
            slot += 1
        bound = unwind + 4 + ((slot_count + 1) & ~1) * 2
        chain = struct.unpack_from("<III", image, bound) if flags == 4 else None
        frames[start] = {
            "begin": hex(start), "end": hex(end), "unwind_rva": hex(unwind),
            "unwind_bytes": image[unwind:bound + (12 if chain else 0)].hex(),
            "prolog_bytes": prolog, "codes": codes,
            "chain": [hex(v) for v in chain] if chain else None,
        }
    spans = sorted(frames)
    assert len(spans) == 8 and spans[0] == START
    assert [int(frames[start]["end"], 16) for start in spans] == spans[1:] + [END]
    for child in frames.values():
        if child["chain"]:
            parent_begin, parent_end, parent_unwind = child["chain"]
            assert int(parent_begin, 16) < int(child["begin"], 16)
            parent = frames[int(parent_begin, 16)]
            assert (parent["end"], parent["unwind_rva"]) == (parent_end, parent_unwind)
    assert [frames[rva]["chain"][0] if frames[rva]["chain"] else None for rva in spans] == [
        None, "0x33ac0", "0x33ad5", "0x33af8", "0x33af8", "0x33ad5", "0x33ac0", "0x33ac0",
    ]
    return list(frames.values())


def trace_original(image, pe, decoder):
    instructions = {i.address: i for i in decoder.disasm(image[START:END], START)}
    assert sum(i.size for i in instructions.values()) == END - START
    inherited_sites = [
        (0x33ACF, "0x33b68"), (0x33AE6, "0x33b41"), (0x33AF6, "0x33b70"),
        (0x33B04, "0x33b34"), (0x33B2D, "0x33b10"), (0x33B48, "0x33b50"),
    ]
    for address, destination in inherited_sites:
        inst = instructions[address]
        assert inst.group(capstone.CS_GRP_JUMP) and inst.op_str == destination
    observed = {
        0x33AC8: ("cmp", "dword ptr [rcx + 8], 0"),
        0x33AE2: ("cmp", "qword ptr [rcx + 0x10], r15"),
        0x33AEB: ("lea", "rbp, [rcx + 8]"),
        0x33AEF: ("cmove", "rbp, r15"),
        0x33AFD: ("mov", "rdi, qword ptr [rbp + 8]"),
        0x33B10: ("mov", "rcx, qword ptr [rdi + 8]"),
        0x33B14: ("call", "qword ptr [rdi]"),
        0x33B16: ("mov", "rbx, qword ptr [rdi + 0x10]"),
        0x33B1A: ("mov", "edx, 0x18"),
        0x33B39: ("mov", "qword ptr [rbp + 8], r15"),
        0x33B3D: ("mov", "qword ptr [rsi + 0x10], r15"),
        0x33B41: ("mov", "rcx, qword ptr [rsi + 0x40]"),
        0x33B4A: ("mov", "rax, qword ptr [rcx]"),
        0x33B4D: ("call", "qword ptr [rax + 0x10]"),
        0x33B50: ("lea", "rcx, [rsi + 0x18]"),
        0x33B5F: ("mov", "dword ptr [rsi + 8], r15d"),
        0x33B70: ("mov", "edx, 1"),
        0x33B75: ("mov", "ecx, 0xc0000005"),
    }
    for address, expected in observed.items():
        assert (instructions[address].mnemonic, instructions[address].op_str) == expected

    def rip_destination(inst):
        operand, = [op for op in inst.operands if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP]
        return inst.address + inst.size + operand.mem.disp

    def at(rva):
        return next(decoder.disasm(image[rva:rva + 15], rva, 1))

    tags = original_imports(pe)
    bounds = {
        "0x33b22": {"target": "0x35134", "iat": "0x3a9e0", "import": tags[0x3A9E0]},
        "0x33b54": {"iat": "0x3a360", "import": tags[0x3A360]},
        "0x33b7a": {"target": "0x33b80", "iat": "0x3a1d0", "import": tags[0x3A1D0]},
    }
    for site, target in ((0x33B22, 0x35134), (0x33B7A, 0x33B80)):
        inst = instructions[site]
        assert inst.mnemonic == "call" and inst.operands[0].type == X86_OP_IMM
        assert inst.operands[0].imm == target
    assert at(0x35134).operands[0].imm == 0x34F80
    for site, target in ((0x34F80, 0x3A9E0), (0x33B54, 0x3A360), (0x33B86, 0x3A1D0)):
        assert rip_destination(at(site)) == target

    # The callback and one other cleanup caller both reach this shared frame.
    assert rip_destination(at(0x397FD)) == 0x540E0 and at(0x39809).operands[0].imm == START
    predecessor = next(inst for inst in decoder.disasm(image[0x33A40:0x33AB2], 0x33A40)
                       if inst.mnemonic == "call" and inst.operands[0].type == X86_OP_IMM
                       and inst.operands[0].imm == START)
    assert rip_destination(at(0x1239)) == 0x540E8
    assert image[0x540E0:0x54128] == bytes(0x48)

    return instructions, {
        "branches": [[hex(site), target] for site, target in inherited_sites],
        "imports": bounds,
        "indirect": [
            {"site": "0x33b14", "operand": "[rdi]", "list_head": "[rsi+0x10]",
             "argument": "[rdi+0x08]", "next": "[rdi+0x10]", "target": "unresolved"},
            {"site": "0x33b4d", "operand": "[rax+0x10]", "receiver": "[rsi+0x40]",
             "table": "[receiver]", "target": "unresolved"},
        ],
        "callers": {"tail": "0x39809", "tail_argument_address": "0x540e0",
                    "cleanup_call": hex(predecessor.address)},
        "next_candidate": {"range": ["0x33a40", "0x33ab2"],
                           "sha256": sha256(image[0x33A40:0x33AB2]).hexdigest()},
    }


def write_evidence(destination, instructions, frames):
    destination.mkdir(parents=True, exist_ok=True)
    listing = "".join(
        f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
        for i in instructions.values()
    )
    (destination / "instructions.lst").write_text(listing, encoding="utf-8", newline="\n")
    with (destination / "unwind.csv").open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, lineterminator="\n")
        writer.writerow(["begin", "end", "unwind_rva", "unwind_bytes", "parent_begin",
                         "parent_end", "parent_unwind_rva"])
        for frame in frames:
            writer.writerow([frame[key] for key in ("begin", "end", "unwind_rva", "unwind_bytes")]
                            + (frame["chain"] or ["", "", ""]))


def verify(original, compiler, evidence_dir):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == RANGE_SHA256
    frames = parse_frames(pe, image)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions, transfer_report = trace_original(image, pe, decoder)
    with TemporaryDirectory() as temp:
        obj = Path(temp) / "teardown.obj"
        compile_bodies(HERE / "teardown.c", compiler, obj)
        matched = compare(obj.read_bytes(), image, {START: END - START})[START]
    if evidence_dir:
        write_evidence(evidence_dir, instructions, frames)
    return {
        "original_sha256": ORIGINAL, "range": [hex(START), hex(END)],
        "instructions": len(instructions), "reassembly": matched, "frames": frames,
        **transfer_report,
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.original, args.compiler, args.evidence_dir), indent=2))
