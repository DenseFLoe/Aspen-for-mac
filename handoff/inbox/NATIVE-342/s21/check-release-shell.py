"""Reassemble the release wrapper and compare PE bytes, relocations and ABI evidence."""

from argparse import ArgumentParser
from hashlib import sha256
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

START, END = 0x33A40, 0x33AB2
RANGE_SHA = "7b5986b8aa4ed44fe9ccf110c39114be1baebd28550f8017567a8473f4653199"


def inspect_unwind_sections(obj):
    """Get only the metadata payload and image-relative relocations from AMD64 COFF."""
    machine, count, _, table_offset, symbols, optional, _ = struct.unpack_from("<HHIIIHH", obj)
    assert (machine, optional) == (0x8664, 0)
    names = {}
    symbol = 0
    while symbol < symbols:
        offset = table_offset + symbol * 18
        name = obj[offset:offset + 8]
        if not any(name[:4]):
            string_table = table_offset + symbols * 18
            address = string_table + struct.unpack_from("<I", name, 4)[0]
            name = obj[address:obj.index(0, address)]
        names[symbol] = name.rstrip(b"\0").decode("ascii")
        symbol += 1 + obj[offset + 17]

    sections = {}
    for index in range(count):
        name, _, _, size, raw, fixup, _, fixup_count, _, _ = struct.unpack_from(
            "<8sIIIIIIHHI", obj, 20 + 40 * index)
        label = name.rstrip(b"\0").decode("ascii")
        if label not in (".xdata", ".pdata"):
            continue
        relocations = []
        for record in range(fixup_count):
            offset, symbol, kind = struct.unpack_from("<IIH", obj, fixup + record * 10)
            assert kind == 3, "Expected IMAGE_REL_AMD64_ADDR32NB"
            relocations.append((offset, names[symbol]))
        sections[label] = (bytearray(obj[raw:raw + size]), relocations)
    return sections


def compare_unwind(obj, pe, image, original):
    runtime, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION
                if entry.struct.BeginAddress == START)
    unwind = runtime.UnwindData
    assert (runtime.EndAddress, unwind) == (END, 0x48E38)
    flags, prolog, count, frame = struct.unpack_from("<BBBB", image, unwind)
    assert (flags & 7, flags >> 3, prolog, count, frame) == (1, 3, 15, 6, 0)
    handler_offset = 4 + 2 * ((count + 1) & ~1)
    handler, metadata = struct.unpack_from("<II", image, unwind + handler_offset)
    assert (handler, metadata) == (0x36298, 0x48E50)
    sections = inspect_unwind_sections(obj)
    assert sections[".pdata"][1] == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    assert sections[".xdata"][1] == [(handler_offset, "rva_36298"),
                                      (handler_offset + 4, "rva_48e50")]
    targets = {".text": START, ".xdata": unwind, "rva_36298": handler, "rva_48e50": metadata}
    for body, relocations in sections.values():
        for offset, symbol in relocations:
            addend, = struct.unpack_from("<I", body, offset)
            struct.pack_into("<I", body, offset, targets[symbol] + addend)
    pdata, xdata = (sections[key][0] for key in (".pdata", ".xdata"))
    offset = runtime.get_file_offset()
    assert len(pdata) == 12 and pdata == original[offset:offset + 12], ".pdata mismatch"
    assert len(xdata) == handler_offset + 8 and xdata == image[unwind:unwind + len(xdata)], ".xdata mismatch"
    return {
        "pdata_bytes": pdata.hex(), "pdata_relocations": len(sections[".pdata"][1]),
        "xdata_rva": hex(unwind), "xdata_bytes": xdata.hex(),
        "xdata_relocations": len(sections[".xdata"][1]), "flags": ["EHANDLER", "UHANDLER"],
        "prologue_bytes": prolog, "stack_allocation": 32,
        "saves": {"RBX": "[post-prologue RSP+0x30]", "RSI": "[post-prologue RSP+0x38]",
                  "RDI": "pushed before the stack allocation"},
        "handler_rva": hex(handler), "handler_data_rva": hex(metadata),
        "handler_data_prefix": image[metadata:metadata + 8].hex(),
    }


def trace_original(pe, image):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = {i.address: i for i in decoder.disasm(image[START:END], START)}
    assert sum(i.size for i in instructions.values()) == END - START

    def at(address):
        return next(decoder.disasm(image[address:address + 15], address, 1))

    def rip(inst):
        memory, = [op.mem for op in inst.operands if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP]
        return inst.address + inst.size + memory.disp

    transfers = {i.address: i.operands[0].imm for i in instructions.values()
                 if (i.group(capstone.CS_GRP_JUMP) or i.group(capstone.CS_GRP_CALL))
                 and i.operands[0].type == X86_OP_IMM}
    assert transfers == {0x33A65: 0x33A84, 0x33A6D: 0x33A7B, 0x33A82: 0x33A67,
                         0x33A87: 0x33AC0, 0x33A90: 0x33A9F, 0x33A9A: 0x35134}
    rip_reads = {i.address: rip(i) for i in instructions.values()
                 if any(op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP for op in i.operands)}
    assert rip_reads == {0x33A54: 0x527B0, 0x33A5B: 0x527B8, 0x33A74: 0x527B8}
    operands = {
        0x33A4F: ("mov", "esi, edx"), 0x33A51: ("mov", "rdi, rcx"),
        0x33A62: ("cmp", "rbx, r8"), 0x33A65: ("jae", "0x33a84"),
        0x33A67: ("mov", "rax, qword ptr [rbx]"), 0x33A6D: ("je", "0x33a7b"),
        0x33A6F: ("xor", "ecx, ecx"), 0x33A71: ("call", "qword ptr [rax + 0x38]"),
        0x33A7B: ("add", "rbx, 8"), 0x33A82: ("jb", "0x33a67"),
        0x33A84: ("mov", "rcx, rdi"), 0x33A8C: ("test", "sil, 1"),
        0x33A90: ("je", "0x33a9f"), 0x33A92: ("mov", "edx, 0x48"),
        0x33A97: ("mov", "rcx, rdi"), 0x33A9F: ("mov", "rax, rdi"),
    }
    for address, expected in operands.items():
        assert (instructions[address].mnemonic, instructions[address].op_str) == expected, hex(address)

    base = pe.OPTIONAL_HEADER.ImageBase
    links = {rva: struct.unpack_from("<Q", image, rva)[0] - base
             for rva in (0x527B0, 0x527B8, 0x49310, 0x40AC8)}
    assert links == {0x527B0: 0x49310, 0x527B8: 0x49318, 0x49310: 0x40A90, 0x40AC8: 0x12E0}
    rebases = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
               for entry in block.entries if entry.type == 10}
    assert links.keys() <= rebases
    assert all(pe.get_section_by_rva(rva).Characteristics & 0x80000000 for rva in (0x527B0, 0x527B8))
    assert (at(0x12E0).mnemonic, at(0x12E0).op_str) == ("ret", "0")
    assert at(0x35134).mnemonic == "jmp" and at(0x35134).operands[0].imm == 0x34F80
    assert rip(at(0x34F80)) == 0x3A9E0 and rip(at(0x36298)) == 0x3A688
    names = {item.address - base: f"{descriptor.dll.decode()}!{item.name.decode() if item.name else '#' + str(item.ordinal)}"
             for descriptor in pe.DIRECTORY_ENTRY_IMPORT for item in descriptor.imports}
    assert names[0x3A9E0] == "mfc140.dll!#1487"
    assert names[0x3A688] == "VCRUNTIME140_1.dll!__CxxFrameHandler4"
    return instructions, {
        "transfer_targets": {hex(site): hex(target) for site, target in transfers.items()},
        "rip_reads": {hex(site): hex(target) for site, target in rip_reads.items()},
        "indirect": {"site": "0x33a71", "null_descriptor_branch": "0x33a6d",
                     "operand": "[rax+0x38]", "rcx": 0, "stride": 8,
                     "initial_receiver_links": {hex(site): hex(target) for site, target in links.items()},
                     "runtime_target": "unresolved"},
        "cleanup": {"site": "0x33a87", "target": "0x33ac0", "rcx": "original RCX"},
        "release": {"test_site": "0x33a8c", "skip_branch": "0x33a90", "required_flag_mask": 1,
                    "call_site": "0x33a9a", "rcx": "original RCX", "edx": 0x48,
                    "thunks": ["0x35134", "0x34f80"], "iat": "0x3a9e0", "import": names[0x3A9E0]},
        "handler_binding": {"site": "0x36298", "iat": "0x3a688", "import": names[0x3A688]},
        "rax_on_return": "original RCX",
    }


def verify(original, zig, source, evidence_dir):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == RANGE_SHA
    instructions, transfers = trace_original(pe, image)
    with TemporaryDirectory() as temp:
        obj = Path(temp) / "release-shell.obj"
        compile_bodies(source, zig, obj)
        payload = obj.read_bytes()
        matched = compare(payload, image, {START: END - START}).get(START)
        if not matched:
            raise ValueError("Reassembled release wrapper differs from original .text")
        frames = compare_unwind(payload, pe, image, data)
    assert len(matched["relocations"]) == 5
    next_entry, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION if entry.struct.BeginAddress == 0x339A0)
    next_bytes = image[next_entry.BeginAddress:next_entry.EndAddress]
    if evidence_dir:
        evidence_dir.mkdir(parents=True, exist_ok=True)
        (evidence_dir / "instructions.lst").write_text("".join(
            f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
            for i in instructions.values()), encoding="utf-8", newline="\n")
    return {
        "original_sha256": ORIGINAL, "range": [hex(START), hex(END)],
        "instructions": len(instructions), "reassembly": matched, "unwind": frames,
        **transfers,
        "next_candidate": {"range": [hex(next_entry.BeginAddress), hex(next_entry.EndAddress)],
                           "size": len(next_bytes), "unwind_rva": hex(next_entry.UnwindData),
                           "sha256": sha256(next_bytes).hexdigest()},
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "release-shell.c")
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.original, args.zig, args.source, args.evidence_dir), indent=2))
