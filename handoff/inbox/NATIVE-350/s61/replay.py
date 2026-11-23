"""Reassemble the scoped zedstwu format buffer and bind its original PE edges."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

START, END, UNWIND = 0x18620, 0x18679, 0x1C3F4
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN = "aa193870871de50eecab3943d321eb78b712e74c8633011bf2028630305274f2"
RELOCATIONS = [(0x18640, "local_printf_options", 0x158D8),
               (0x1865F, "stdio_common_vsprintf_thunk", 0x180DE)]
IMPORT = ("api-ms-win-crt-stdio-l1-1-0.dll", "__stdio_common_vsprintf")


def compare_text(payload, region):
    text, symbols, relocations = objects(payload)
    assert (symbols["format_buffer"], symbols["format_buffer_end"]) == (0, len(region))
    assert len(text) == len(region)
    assert relocations == [(rva - START, symbol, 4) for rva, symbol, _ in RELOCATIONS]
    for rva, _, target in RELOCATIONS:
        offset = rva - START
        addend, = struct.unpack_from("<i", text, offset)
        struct.pack_into("<i", text, offset, target - rva - 4 + addend)
    for offset, (actual, expected) in enumerate(zip(text, region)):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + offset:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")


def compare_unwind(payload, pe, image):
    entry, = (item.struct for item in pe.DIRECTORY_ENTRY_EXCEPTION if item.struct.BeginAddress == START)
    assert (entry.EndAddress, entry.UnwindData) == (END, UNWIND)
    pdata, _, relocations = objects(payload, b".pdata")
    assert relocations == [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)]
    assert len(pdata) == 12
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, base + addend)
    assert pdata == entry.__pack__()
    xdata, _, relocations = objects(payload, b".xdata")
    assert not relocations and xdata == image[UNWIND:UNWIND + 16]
    return {"pdata": pdata.hex(), "xdata": xdata.hex(), "xdata_rva": hex(UNWIND)}


def replay(original, zig, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == SPAN
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "format.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "format-buffer.c"), "-o", str(obj)], check=True)
        payload = obj.read_bytes()
    compare_text(payload, region)
    frame = compare_unwind(payload, pe, image)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions = {ins.address: ins for ins in decoder.disasm(region, START)}
    iced = {ins.ip: ins for ins in Decoder(64, region, ip=START)}
    assert sum(ins.size for ins in instructions.values()) == len(region)
    assert [(ins.address, ins.size) for ins in instructions.values()] == [
        (ins.ip, ins.len) for ins in iced.values()]
    for rva, _, target in RELOCATIONS:
        assert instructions[rva - 1].mnemonic == "call"
        assert iced[rva - 1].near_branch_target == target
    getter, ret = list(Decoder(64, image[0x158D8:0x158E0], ip=0x158D8))
    assert (getter.ip_rel_memory_address, ret.len) == (0x22CA0, 1)
    assert image[ret.ip] == 0xC3
    opts_section = pe.get_section_by_rva(0x22CA0)
    assert opts_section.Name.rstrip(b"\0") == b".data"
    raw_end = opts_section.VirtualAddress + opts_section.SizeOfRawData
    virtual_end = opts_section.VirtualAddress + opts_section.Misc_VirtualSize
    assert raw_end <= 0x22CA0 and 0x22CA8 <= virtual_end
    thunk, = list(Decoder(64, image[0x180DE:0x180E4], ip=0x180DE))
    assert image[thunk.ip:thunk.ip + 2] == b"\xff\x25" and thunk.ip_rel_memory_address == 0x19188
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {s.address - base: (d.dll.decode(), s.name.decode())
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    assert imports[0x19188] == IMPORT
    expected = {
        0x18637: ("mov", "r15, qword ptr [rsp + 0x80]"),
        0x18644: ("mov", "rcx, qword ptr [rax]"),
        0x18647: ("or", "rcx, 1"),
        0x1864B: ("mov", "qword ptr [rsp + 0x28], r15"),
        0x18650: ("mov", "qword ptr [rsp + 0x20], rsi"),
        0x18655: ("mov", "rdx, r14"),
        0x18658: ("mov", "r8, rbx"),
        0x1865B: ("mov", "r9, rdi"),
        0x18663: ("test", "eax, eax"),
        0x18665: ("mov", "ecx, 0xffffffff"),
        0x1866A: ("cmovs", "eax, ecx"),
    }
    for site, value in expected.items():
        ins = instructions[site]
        assert (ins.mnemonic, ins.op_str) == value, hex(site)
    if listing:
        listing.write_text("".join(
            f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
            for ins in instructions.values()), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
            "matched_bytes": len(region), "instructions": len(instructions), "unwind": frame,
            "relocations": [(hex(rva), symbol, hex(target)) for rva, symbol, target in RELOCATIONS],
            "options_getter": "0x158d8", "options_storage": "0x22ca0",
            "options_storage_initialization": "loader zero-fill", "options_or_mask": 1,
            "crt_iat": "0x19188", "crt_import": "!".join(IMPORT),
            "crt_register_arguments": ["options | 1", "buffer", "buffer_size", "format"],
            "crt_stack_arguments": ["locale", "va_list"], "negative_return": -1}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    try:
        print(json.dumps(replay(args.original, args.zig, args.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
