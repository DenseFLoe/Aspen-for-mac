"""Verify the scoped _com_error copy constructor and its PE references."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
from runpy import run_path
import struct
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies

inspect_unwind_sections = run_path(str(HERE.parent / "s21/check-release-shell.py"))["inspect_unwind_sections"]
START, END, UNWIND = 0x34DF0, 0x34E34, 0x44660
SCOPE_SHA = "14b72a11e3c8d45dcaab82f5082a9775c6ac488ff55781b0bf4bdc4f98b78125"


def verify_frame(obj, pe, image, original):
    runtime, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION
                if entry.struct.BeginAddress == START)
    assert (runtime.EndAddress, runtime.UnwindData) == (END, UNWIND)
    sections = inspect_unwind_sections(obj)
    pdata, fixups = sections[".pdata"]
    assert fixups == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, addend + base)
    file_offset = runtime.get_file_offset()
    assert len(pdata) == 12 and pdata == original[file_offset:file_offset + 12]
    xdata, fixups = sections[".xdata"]
    assert not fixups and len(xdata) == 8 and xdata == image[UNWIND:UNWIND + 8]
    version, prolog, count, frame, allocation_site, allocation, push_site, push = xdata
    assert (version, prolog, count, frame, allocation_site, allocation, push_site, push) == (
        1, 6, 2, 0, 6, 0x32, 2, 0x30)
    return {
        "pdata_file_offset": hex(file_offset), "pdata_bytes": pdata.hex(),
        "xdata_rva": hex(UNWIND), "xdata_bytes": xdata.hex(),
        "stack_allocation": 0x20, "nonvolatile_push": "RBX", "prologue_bytes": prolog,
    }


def read_original_references(pe, image):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {i.address: i for i in decoder.disasm(image[START:END], START)}
    assert sum(i.size for i in body.values()) == END - START

    def require(address, mnemonic, operands):
        instruction = body[address]
        assert (instruction.mnemonic, instruction.op_str) == (mnemonic, operands), hex(address)

    def rip(instruction):
        memory, = (op.mem for op in instruction.operands
                   if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
        return instruction.address + instruction.size + memory.disp

    original_flow = {
        0x34DF6: ("mov", "rbx, rcx"),
        0x34E00: ("mov", "qword ptr [rcx], rax"),
        0x34E03: ("mov", "eax, dword ptr [rdx + 8]"),
        0x34E06: ("mov", "dword ptr [rcx + 8], eax"),
        0x34E09: ("mov", "rcx, qword ptr [rdx + 0x10]"),
        0x34E0D: ("mov", "qword ptr [rbx + 0x10], rcx"),
        0x34E11: ("mov", "qword ptr [rbx + 0x18], 0"),
        0x34E19: ("test", "rcx, rcx"),
        0x34E1C: ("je", "0x34e2b"),
        0x34E1E: ("mov", "rax, qword ptr [rcx]"),
        0x34E21: ("mov", "rax, qword ptr [rax + 8]"),
        0x34E2B: ("mov", "rax, rbx"),
    }
    for address, (mnemonic, operands) in original_flow.items():
        require(address, mnemonic, operands)
    assert body[0x34DF9].mnemonic == "lea" and body[0x34E25].mnemonic == "call"
    vtable, dispatch = (rip(body[address]) for address in (0x34DF9, 0x34E25))
    assert (vtable, dispatch) == (0x42A90, 0x3AC20)
    base = pe.OPTIONAL_HEADER.ImageBase
    config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    field_offset = config.get_field_absolute_offset("GuardCFDispatchFunctionPointer")
    field_rva = pe.get_rva_from_offset(field_offset)
    assert config.GuardCFDispatchFunctionPointer == base + dispatch
    assert field_rva == 0x42CC8 and config.GuardFlags & 0x100
    relocations = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
                   for entry in block.entries if entry.type == 10}
    assert {vtable, dispatch, field_rva} <= relocations
    first_vfunc = struct.unpack_from("<Q", image, vtable)[0] - base
    thunk = struct.unpack_from("<Q", image, dispatch)[0] - base
    assert (first_vfunc, thunk) == (0x34EE0, 0x36AE0)
    for address in vtable, dispatch:
        assert pe.get_section_by_rva(address).Name.rstrip(b"\0") == b".rdata"
    assert any(entry.struct.BeginAddress == first_vfunc for entry in pe.DIRECTORY_ENTRY_EXCEPTION)
    thunk_instruction, = decoder.disasm(image[thunk:thunk + 2], thunk)
    assert (thunk_instruction.mnemonic, thunk_instruction.op_str) == ("jmp", "rax")
    return body, {
        "destination_vtable": {
            "lea_site": "0x34df9", "rva": hex(vtable),
            "first_slot_dir64_bytes": image[vtable:vtable + 8].hex(), "first_slot_target": hex(first_vfunc),
        },
        "source_copies": [
            {"offset": 8, "width": 4}, {"offset": 16, "width": 8},
            {"offset": 24, "width": 8, "value": 0},
        ],
        "outgoing_virtual_call": {
            "zero_receiver_branch": "0x34e1c -> 0x34e2b",
            "call_site": "0x34e25", "slot_load_site": "0x34e21", "slot_byte_offset": 8,
            "receiver_source": "qword [source RDX + 0x10]",
            "dispatch_pointer_rva": hex(dispatch), "load_config_dir64_rva": hex(field_rva),
            "dispatch_dir64_bytes": image[dispatch:dispatch + 8].hex(),
            "on_disk_thunk": f"{thunk:#x} {thunk_instruction.bytes.hex()} jmp rax",
            "unresolved": "The virtual callee depends on the live receiver. On-disk dispatcher is statically pinned.",
        },
    }


def verify(original, compiler, source, listing):
    data = original.read_bytes()
    if sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("Original SHA-256 differs")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    if sha256(image[START:END]).hexdigest() != SCOPE_SHA:
        raise ValueError("Pinned constructor range differs")
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "copy.obj"
        compile_bodies(source, compiler, obj)
        payload = obj.read_bytes()
        rebuilt = compare(payload, image, {START: END - START}).get(START)
        if not rebuilt:
            raise ValueError("Reassembled _com_error copy constructor differs from original .text")
        frame = verify_frame(payload, pe, image, data)
    assert rebuilt["relocations"] == [["0x34dfc", "0x42a90", 4], ["0x34e27", "0x3ac20", 4]]
    body, references = read_original_references(pe, image)
    if listing:
        listing.write_text("".join(
            f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
            for i in body.values()), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "instructions": len(body),
            "reassembly": rebuilt, "unwind": frame, **references}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "com-error-copy.c")
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    try:
        print(json.dumps(verify(args.original, args.compiler, args.source, args.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")


if __name__ == "__main__":
    main()
