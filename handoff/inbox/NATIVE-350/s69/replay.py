"""Reassemble the zedstwu detach cleanup funclet and verify its PE bindings."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from iced_x86 import Decoder, FlowControl
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

START, END, UNWIND = 0x18690, 0x186A9, 0x1C120
CALL_SITE, CALL_TARGET = 0x1869C, 0x15C74
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN = "a54e4ac5b75e2d5ec0f89911437c11b2337c7e57f480b9eff0b262da1f5c3a7f"


def compare_text(payload, region):
    text, symbols, relocations = objects(payload)
    assert (symbols["detach_cleanup"], symbols["detach_cleanup_padding"],
            symbols["detach_cleanup_end"]) == (0, len(region) - 1, len(region))
    assert len(text) == len(region)
    displacement = CALL_SITE + 1
    offset = displacement - START
    assert relocations == [(offset, "crt_cleanup_helper", 4)]
    addend, = struct.unpack_from("<i", text, offset)
    struct.pack_into("<i", text, offset, CALL_TARGET - displacement - 4 + addend)
    for index, (actual, expected) in enumerate(zip(text, region)):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + index:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")
    return {"site_rva": hex(CALL_SITE), "relocation_rva": hex(displacement),
            "relocation_type": "IMAGE_REL_AMD64_REL32", "symbol": "crt_cleanup_helper",
            "target_rva": hex(CALL_TARGET)}


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
    assert len(xdata) == 8 and not relocations and xdata == image[UNWIND:UNWIND + len(xdata)]
    return {"pdata": pdata.hex(), "xdata": xdata.hex(), "xdata_rva": hex(UNWIND),
            "prologue_length": 6, "stack_allocation": 32, "saved_register": "RBP"}


def replay(original, zig, listing):
    original_bytes = original.read_bytes()
    assert sha256(original_bytes).hexdigest() == ORIGINAL
    pe = pefile.PE(data=original_bytes)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == SPAN
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "attach-cleanup.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "detach-cleanup.c"), "-o", str(obj)], check=True)
        payload = obj.read_bytes()
    relocation = compare_text(payload, region)
    unwind = compare_unwind(payload, pe, image)

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions = list(decoder.disasm(region, START))
    iced = {ins.ip: ins for ins in Decoder(64, region, ip=START)}
    assert sum(ins.size for ins in instructions) == len(region)
    assert [(ins.address, ins.size) for ins in instructions] == [(ins.ip, ins.len) for ins in iced.values()]
    assert [(ins.mnemonic, ins.op_str) for ins in instructions] == [
        ("push", "rbp"), ("sub", "rsp, 0x20"), ("mov", "rbp, rdx"),
        ("mov", "cl, byte ptr [rbp + 0x20]"), ("call", "0x15c74"), ("nop", ""),
        ("add", "rsp, 0x20"), ("pop", "rbp"), ("ret", ""), ("int3", ""),
    ]
    call = iced[CALL_SITE]
    assert (call.flow_control, call.near_branch_target) == (FlowControl.CALL, CALL_TARGET)

    target, = (item.struct for item in pe.DIRECTORY_ENTRY_EXCEPTION if item.struct.BeginAddress == CALL_TARGET)
    callee = {ins.address: ins for ins in decoder.disasm(image[CALL_TARGET:target.EndAddress], CALL_TARGET)}
    assert (callee[0x15C7A].mnemonic, callee[0x15C7A].op_str) == ("mov", "bl, cl")
    assert (callee[0x15C87].mnemonic, callee[0x15C87].op_str) == ("test", "bl, bl")
    if listing:
        listing.write_text("".join(
            f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
            for ins in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
            "matched_bytes": len(region), "instructions": len(instructions),
            "executable_instructions": len(instructions) - 1, "unwind": unwind,
            "relocations": [relocation],
            "byte_input": {"site_rva": "0x18699", "original_base_register": "RDX",
                           "offset": "0x20", "size": 1, "destination_register": "CL"},
            "padding": {"rva": hex(END - 1), "bytes": "cc", "instruction": "int3"},
            "target_consumes_cl": {"save_rva": "0x15c7a", "test_rva": "0x15c87"}}


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
