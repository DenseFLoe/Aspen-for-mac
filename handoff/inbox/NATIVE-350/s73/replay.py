"""Reassemble two AMD64 fragments and check their original PE bindings."""

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

START, MIDDLE, END = 0x186A9, 0x186BD, 0x186F3
ORIGINAL_SHA = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN_SHA = "aa7c30e248012be77ecefdc2b6d6a0935f7bd5b1e442a705eec07623bde18aab"
FRAGMENTS = ((START, MIDDLE, 0x1C128, 0x20), (MIDDLE, END, 0x1C160, 0x30))
FIXUPS = (
    (0x186B7, 1, "detach_runtime", 0x15B00, "tailjump"),
    (0x186D4, 3, "cleanup_callback", 0x1540C, "address"),
    (0x186E6, 1, "cleanup_and_filter", 0x15A70, "call"),
)
ARGUMENTS = (
    (1, 0x186E2, "rcx", "qword ptr [rbp + 0x60]"),
    (2, 0x186DF, "edx", "dword ptr [rbp + 0x68]"),
    (3, 0x186DB, "r8", "qword ptr [rbp + 0x70]"),
    (4, 0x186D4, "r9", "original callback at RVA 0x1540c"),
    (5, 0x186D0, "[rsp + 0x20]", "dword read through original RCX"),
    (6, 0x186CB, "[rsp + 0x28]", "original RCX pointer"),
)


def match_region(code, image):
    text, symbols, relocations = objects(code)
    for symbol, rva in {
        "detach_tail": START,
        "detach_tail_padding": MIDDLE - 1,
        "detach_tail_end": MIDDLE,
        "exception_cleanup": MIDDLE,
        "exception_cleanup_padding": END - 1,
        "exception_cleanup_end": END,
    }.items():
        assert symbols[symbol] == rva - START
    assert len(text) == END - START
    expected = [(site + disp - START, name, 4) for site, disp, name, _, _ in FIXUPS]
    assert relocations == expected
    for site, displacement, _, target, _ in FIXUPS:
        relocation = site + displacement
        offset = relocation - START
        addend, = struct.unpack_from("<i", text, offset)
        struct.pack_into("<i", text, offset, target - relocation - 4 + addend)
    for index, (actual, expected) in enumerate(zip(text, image[START:END])):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + index:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")


def match_unwind(code, pe, image):
    entries = {row.struct.BeginAddress: row.struct for row in pe.DIRECTORY_ENTRY_EXCEPTION}
    pdata, _, relocations = objects(code, b".pdata")
    xdata, _, xrel = objects(code, b".xdata")
    assert len(pdata) == 24 and len(xdata) == 16 and not xrel
    assert relocations == [
        (12 * index + field, section, 3)
        for index in range(len(FRAGMENTS))
        for field, section in ((0, ".text"), (4, ".text"), (8, ".xdata"))
    ]
    results = []
    for index, (begin, end, unwind, stack) in enumerate(FRAGMENTS):
        address, finish, local_unwind = struct.unpack_from("<III", pdata, index * 12)
        assert local_unwind == index * 8
        rebound = struct.pack("<III", START + address, START + finish, unwind)
        expected = struct.pack("<III", begin, end, unwind)
        assert rebound == expected == entries[begin].__pack__()
        unwind_bytes = xdata[local_unwind:local_unwind + 8]
        assert unwind_bytes == image[unwind:unwind + 8]
        results.append({"range": [hex(begin), hex(end)], "pdata": rebound.hex(),
                        "xdata_rva": hex(unwind), "xdata": unwind_bytes.hex(),
                        "prologue_length": 6, "stack_allocation": stack, "saved_register": "RBP"})
    return results


def check_bindings(pe, image, decoder, iced):
    results = []
    for site, displacement, symbol, target, kind in FIXUPS:
        instruction = iced[site]
        if kind == "address":
            assert instruction.is_ip_rel_memory_operand
            assert instruction.ip_rel_memory_address == target
        else:
            flow = FlowControl.CALL if kind == "call" else FlowControl.UNCONDITIONAL_BRANCH
            assert (instruction.flow_control, instruction.near_branch_target) == (flow, target)
        results.append({"rva": hex(site), "target": hex(target), "kind": kind, "symbol": symbol,
                        "relocation": "IMAGE_REL_AMD64_REL32", "relocation_rva": hex(site + displacement)})

    arguments_and_frame = {
        0x186C3: ("mov", "rbp, rdx"),
        0x186C6: ("mov", "rax, qword ptr [rcx]"),
        0x186C9: ("mov", "edx, dword ptr [rax]"),
        0x186CB: ("mov", "qword ptr [rsp + 0x28], rcx"),
        0x186D0: ("mov", "dword ptr [rsp + 0x20], edx"),
        0x186DB: ("mov", "r8, qword ptr [rbp + 0x70]"),
        0x186DF: ("mov", "edx, dword ptr [rbp + 0x68]"),
        0x186E2: ("mov", "rcx, qword ptr [rbp + 0x60]"),
    }
    actual = {ins.address: (ins.mnemonic, ins.op_str)
              for ins in decoder.disasm(image[MIDDLE:END], MIDDLE)}
    assert all(actual[rva] == label for rva, label in arguments_and_frame.items())
    callee = {ins.address: (ins.mnemonic, ins.op_str)
              for ins in decoder.disasm(image[0x15A70:0x15AD0], 0x15A70)}
    assert callee[0x15A84] == ("mov", "rdi, r9")
    assert callee[0x15AA5] == ("mov", "rax, rdi")
    assert callee[0x15AAE] == ("mov", "rdx, qword ptr [rsp + 0x58]")
    assert callee[0x15AB3] == ("mov", "ecx, dword ptr [rsp + 0x50]")
    tail = Decoder(64, image[0x15ACB:0x15AD0], ip=0x15ACB).decode()
    assert tail.near_branch_target == 0x18096
    thunk = Decoder(64, image[0x18096:0x1809C], ip=0x18096).decode()
    slot = thunk.ip_rel_memory_address
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = [(table.dll.decode(), item.name.decode()) for table in pe.DIRECTORY_ENTRY_IMPORT
               for item in table.imports if item.address == base + slot and item.name]
    assert len(imports) == 1
    library, name = imports[0]
    return results, {"argument_4_saved_at": "0x15a84", "argument_4_used_at": "0x15aa5",
                     "argument_6_read_at": "0x15aae", "argument_5_read_at": "0x15ab3",
                     "tailjump_rva": "0x15acb", "iat_thunk_rva": "0x18096",
                     "iat_rva": hex(slot), "import": f"{library}!{name}"}


def replay(original, zig, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL_SHA
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == SPAN_SHA
    with TemporaryDirectory() as folder:
        obj = Path(folder) / "cleanup-fragments.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "cleanup-fragments.c"), "-o", str(obj)], check=True)
        code = obj.read_bytes()
    match_region(code, image)
    unwind = match_unwind(code, pe, image)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions = list(decoder.disasm(region, START))
    iced = {ins.ip: ins for ins in Decoder(64, region, ip=START)}
    assert sum(ins.size for ins in instructions) == len(region)
    assert [(ins.address, ins.size) for ins in instructions] == [(ins.ip, ins.len) for ins in iced.values()]
    paddings = [ins.address for ins in instructions if ins.mnemonic == "int3"]
    assert paddings == [MIDDLE - 1, END - 1]
    fixups, callee = check_bindings(pe, image, decoder, iced)
    if listing:
        listing.write_text("".join(f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
                                   for ins in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL_SHA, "range_sha256": SPAN_SHA,
            "range": [hex(START), hex(END)], "matched_bytes": len(region),
            "instructions": len(instructions), "executable_instructions": len(instructions) - len(paddings),
            "padding_rvas": [hex(rva) for rva in paddings], "unwind": unwind, "relocations": fixups,
            "call_arguments": [{"argument": n, "rva": hex(rva), "location": location, "value": value}
                               for n, rva, location, value in ARGUMENTS], "callee_evidence": callee}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--listing", type=Path)
    options = parser.parse_args()
    try:
        print(json.dumps(replay(options.original, options.zig, options.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
