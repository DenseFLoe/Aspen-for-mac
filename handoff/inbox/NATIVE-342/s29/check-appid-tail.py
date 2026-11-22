"""Reassemble the APPID dispatch and verify its PE data and argument flow."""

import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys
from tempfile import TemporaryDirectory

import capstone
import pefile
from capstone.x86_const import X86_OP_MEM, X86_OP_REG, X86_REG_RIP


HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies

START = 0x33A20
END = 0x33A38
RANGE_SHA = "beb31f6a8911348a0460514d488e99484ac3fa6dae04c8be473ab625ed79d90a"


def verify(original, compiler, source, listing):
    data = original.read_bytes()
    if hashlib.sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("Original SHA-256 differs")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    original_body = image[START:END]
    if hashlib.sha256(original_body).hexdigest() != RANGE_SHA:
        raise ValueError("Original scope differs")
    if any(entry.struct.BeginAddress < END and entry.struct.EndAddress > START
           for entry in pe.DIRECTORY_ENTRY_EXCEPTION):
        raise ValueError("Unexpected overlapping runtime-function entry")
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "appid-tail.obj"
        compile_bodies(source, compiler, obj)
        payload = obj.read_bytes()
        body = compare(payload, image, {START: END - START}).get(START)
        if body is None:
            raise ValueError("Reassembled APPID dispatch differs from original .text")
        section_count, = struct.unpack_from("<H", payload, 2)
        if any(payload[20 + 40 * index:28 + 40 * index].rstrip(b"\0") in {b".pdata", b".xdata"}
               for index in range(section_count)):
            raise ValueError("Unexpected object unwind sections")

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = list(decoder.disasm(original_body, START))
    assert sum(item.size for item in instructions) == END - START
    load, argument3, receiver, argument2, jump = instructions

    def location(operand):
        if operand.type == X86_OP_REG:
            return decoder.reg_name(operand.reg)
        if operand.type == X86_OP_MEM:
            assert operand.mem.index == 0
            return decoder.reg_name(operand.mem.base), operand.mem.disp, operand.size
        raise ValueError("Unexpected instruction operand")

    assert (load.mnemonic, [location(op) for op in load.operands]) == ("mov", ["rax", ("rdx", 0, 8)])
    assert (receiver.mnemonic, [location(op) for op in receiver.operands]) == ("mov", ["rcx", "rdx"])
    assert (jump.mnemonic, [location(op) for op in jump.operands]) == ("jmp", [("rax", 0x18, 8)])
    args = {}
    for item in (argument2, argument3):
        register, rip_reference = item.operands
        assert item.mnemonic == "lea" and rip_reference.mem.base == X86_REG_RIP
        rva = item.address + item.size + rip_reference.mem.disp
        register_name = location(register)
        section = pe.get_section_by_rva(rva)
        assert section.Name.rstrip(b"\0") == b".rdata" and not section.Characteristics & 0x80000000
        end = rva
        while end + 2 <= section.VirtualAddress + section.Misc_VirtualSize:
            if image[end:end + 2] == b"\0\0":
                break
            end += 2
        else:
            raise ValueError("UTF-16LE data lacks an in-section NUL terminator")
        args[register_name] = {
            "instruction_rva": hex(item.address),
            "data_rva": hex(rva),
            "nul_terminated_utf16le": image[rva:end].decode("utf-16le"),
            "byte_count": end + 2 - rva,
            "sha256": hashlib.sha256(image[rva:end + 2]).hexdigest(),
        }
    assert [(key, value["data_rva"], value["nul_terminated_utf16le"]) for key, value in args.items()] == [
        ("rdx", "0x40e70", "APPID"),
        ("r8", "0x40e20", "{5B52D748-52AB-47EE-8180-D7E0F50C5219}"),
    ]
    entry_address = pe.OPTIONAL_HEADER.ImageBase + START
    incoming = [
        hex(entry.rva)
        for block in pe.DIRECTORY_ENTRY_BASERELOC
        for entry in block.entries
        if entry.type == 10 and struct.unpack_from("<Q", image, entry.rva)[0] == entry_address
    ]
    assert incoming == ["0x429b8"]
    if listing:
        listing.write_text("".join(
            f"{item.address:#x} {item.bytes.hex()} {item.mnemonic} {item.op_str}\n"
            for item in instructions
        ), encoding="utf-8", newline="\n")
    return {
        "original_sha256": ORIGINAL,
        "range": [hex(START), hex(END)],
        "instructions": len(instructions),
        "reassembly": body,
        "unwind": {"pe_runtime_function_entries_overlapping_scope": 0, "object_unwind_sections": 0},
        "receiving_rcx": "entry RDX",
        "data_arguments": args,
        "outgoing_transfer": {"site": hex(jump.address), "operand": "qword ptr [rax + 0x18]",
                              "rax": "qword ptr [entry RDX]", "runtime_target": "unresolved"},
        "incoming_dir64_slots": incoming,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "appid-tail.c")
    parser.add_argument("--listing", type=Path)
    options = parser.parse_args()
    try:
        report = verify(options.original, options.compiler, options.source, options.listing)
    except ValueError as error:
        parser.exit(1, f"{error}\n")
    print(json.dumps(report, indent=2))
