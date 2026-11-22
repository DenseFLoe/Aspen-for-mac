"""Rebuild the AMD64 capability query and verify its PE references and unwind data."""
from argparse import ArgumentParser
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE = "53ab68e5de47e6beb36cf37ba805cf09edc3eaa8a738b5670451109abd5b5dc2"
START, END = 0x148d0, 0x14902


def rip_target(ins):
    memory = next(
        operand.mem for operand in ins.operands
        if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP
    )
    return ins.address + ins.size + memory.disp


def branch_target(ins):
    assert ins.operands[0].type == X86_OP_IMM
    return ins.operands[0].imm


def decode_at(decoder, image, address):
    return next(decoder.disasm(image[address:address + 15], address, 1))


def rebuild(image, zig, ins, ready, table, initializer):
    with TemporaryDirectory() as temporary:
        obj = Path(temporary) / "query.obj"
        subprocess.run(
            [str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
             "-c", str(HERE / "capability-query.c"), "-o", str(obj)],
            check=True,
        )
        co = obj.read_bytes()

    text, symbols, fixes = objects(co)
    start, end = symbols["capability_query"], symbols["capability_query_end"]
    expected = {
        "capability_ready": (ins[0x148e1].address + ins[0x148e1].disp_offset, ready),
        "initialize_capability_records": (ins[0x148ea].address + ins[0x148ea].imm_offset, initializer),
        "capability_records": (ins[0x148f2].address + ins[0x148f2].disp_offset, table),
    }
    assert end - start == END - START
    assert {symbol for _, symbol, _ in fixes} == expected.keys()
    assert len(fixes) == len(expected)
    relocations = []
    for offset, symbol, kind in fixes:
        site, target = expected[symbol]
        assert site == START + offset - start and 4 <= kind <= 9
        addend = struct.unpack_from("<i", text, offset)[0]
        struct.pack_into("<i", text, offset, target + addend - (site + kind))
        relocations.append({"field_rva": hex(site), "symbol": symbol, "kind": kind,
                            "addend": addend, "target_rva": hex(target)})
    assert text[start:end] == image[START:END]

    unwind, _, unwind_fixes = objects(co, b".xdata")
    directory, _, directory_fixes = objects(co, b".pdata")
    assert not unwind_fixes
    assert directory_fixes == [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)]
    return relocations, unwind, directory


def evidence(original, zig, destination):
    source = original.read_bytes()
    assert sha256(source).hexdigest() == ORIGINAL
    pe = pefile.PE(data=source)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == RANGE
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    decoded = list(decoder.disasm(region, START))
    assert sum(instruction.size for instruction in decoded) == len(region)
    assert [(i.address, i.size) for i in decoded] == [(i.ip, i.len) for i in Decoder(64, region, ip=START)]
    ins = {instruction.address: instruction for instruction in decoded}

    operands = {
        0x148d7: ("lea", "ecx, [rsi - 4]"), 0x148da: ("xor", "eax, eax"),
        0x148dc: ("cmp", "ecx, -3"), 0x148df: ("jb", "0x148fc"),
        0x148e8: ("jne", "0x148ef"), 0x148ef: ("shl", "esi, 2"),
        0x148f9: ("mov", "eax, dword ptr [rax + rsi*4]"),
    }
    for location, required in operands.items():
        assert (ins[location].mnemonic, ins[location].op_str) == required, hex(location)
    assert ins[0x148e1].mnemonic == "cmp" and ins[0x148e1].operands[0].size == 4
    assert ins[0x148e1].operands[1].imm == 0 and ins[0x148ea].mnemonic == "call"
    ready, table = rip_target(ins[0x148e1]), rip_target(ins[0x148f2])
    initializer = branch_target(ins[0x148ea])
    assert (ready, table, initializer) == (0x235fc, 0x235f0, 0x14910)

    pe_entries = {entry.struct.BeginAddress: entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION}
    runtime = pe_entries[START]
    assert (runtime.EndAddress, runtime.UnwindData) == (END, 0x1c388)
    init_runtime = pe_entries[initializer]
    next_region = image[initializer:init_runtime.EndAddress]
    assert init_runtime.EndAddress == 0x14cab and init_runtime.UnwindData == 0x1c390
    write = decode_at(decoder, image, 0x14c80)
    assert write.mnemonic == "mov" and write.operands[0].size == 4
    assert rip_target(write) == ready and write.operands[1].imm == 1

    initial_slots = []
    for key, address in [(None, ready), *((key, table + 16 * key) for key in (1, 2, 3))]:
        section = pe.get_section_by_rva(address)
        end_of_raw = section.VirtualAddress + section.SizeOfRawData
        end_of_virtual = section.VirtualAddress + section.Misc_VirtualSize
        assert section.Name.rstrip(b"\x00") == b".data" and section.Characteristics & 0x80000000
        assert end_of_raw <= address and address + 4 <= end_of_virtual
        value = struct.unpack_from("<I", image, address)[0]
        assert value == 0
        initial_slots.append({"key": key, "rva": hex(address), "width": 4, "loader_initial_value": value})

    relocations, unwind, directory = rebuild(image, zig, ins, ready, table, initializer)
    assert unwind == image[runtime.UnwindData:runtime.UnwindData + len(unwind)]
    for offset, section_rva in ((0, START), (4, START), (8, runtime.UnwindData)):
        addend = struct.unpack_from("<I", directory, offset)[0]
        struct.pack_into("<I", directory, offset, section_rva + addend)
    offset = runtime.get_file_offset()
    assert directory == source[offset:offset + 12]
    if destination:
        destination.mkdir(parents=True, exist_ok=True)
        (destination / "instructions.lst").write_text(
            "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n" for i in decoded),
            encoding="utf-8", newline="\n",
        )

    return {
        "original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": RANGE,
        "matched_bytes": len(region), "instructions": len(ins),
        "coff_text_relocations": relocations, "coff_pdata_relocations": 3,
        "unwind_rva": hex(runtime.UnwindData), "unwind_bytes": unwind.hex(),
        "unsigned_gate": "((uint32_t)key - 4u) >= 0xfffffffdu",
        "accepted_u32_keys": [1, 2, 3], "outside_keys_return": 0,
        "ready_test_rva": "0x148e1", "skip_initialization_if_nonzero_rva": "0x148e8",
        "initialize_call_rva": "0x148ea", "initializer_rva": hex(initializer),
        "initializer_ready_store": {"rva": hex(write.address), "value": 1},
        "record_base_rva": hex(table), "record_stride": 16, "field_offsets": [0],
        "data_section_raw_end": hex(end_of_raw), "data_section_virtual_end": hex(end_of_virtual),
        "zero_filled_dwords": initial_slots,
        "next_range": {
            "start_rva": hex(initializer), "end_rva": hex(init_runtime.EndAddress),
            "unwind_rva": hex(init_runtime.UnwindData),
            "sha256": sha256(next_region).hexdigest(), "size": len(next_region),
        },
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    arguments = parser.parse_args()
    print(json.dumps(evidence(arguments.original, arguments.zig, arguments.evidence_dir), indent=2))
