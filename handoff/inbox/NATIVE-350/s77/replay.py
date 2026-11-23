"""Reassemble the AMD64 exception filter and verify its PE scope and unwind."""

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

START, END, UNWIND = 0x186F3, 0x1870B, 0x1C1CC
HOST, HOST_END, HOST_UNWIND = 0x15BDC, 0x15C74, 0x1C1AC
ORIGINAL_SHA = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN_SHA = "515c04e0ba3bb82e249e1f52765ba9c74cf63305116d4e5c2393eb92ba558686"


def match_region(obj, image):
    text, symbols, relocations = objects(obj)
    assert symbols["image_section_exception_filter"] == 0
    assert symbols["image_section_exception_filter_padding"] == END - START - 1
    assert symbols["image_section_exception_filter_end"] == len(text) == END - START
    assert not relocations
    for offset, (actual, expected) in enumerate(zip(text, image[START:END])):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + offset:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")


def match_unwind(obj, image, entries):
    pdata, _, relocations = objects(obj, b".pdata")
    xdata, _, xrel = objects(obj, b".xdata")
    assert len(pdata) == 12 and len(xdata) == 8 and not xrel
    assert relocations == [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)]
    start, end, unwind = struct.unpack("<III", pdata)
    assert (start, end, unwind) == (0, END - START, 0)
    rebound = struct.pack("<III", START + start, START + end, UNWIND)
    assert rebound == entries[START].__pack__()
    assert xdata == image[UNWIND:UNWIND + 8]
    assert struct.unpack("<8B", xdata) == (1, 2, 1, 0, 2, 0x50, 0, 0)
    return {"pdata": rebound.hex(), "xdata_rva": hex(UNWIND), "xdata": xdata.hex(),
            "prologue_length": 2, "saved_register": "RBP", "stack_allocation": 0}


def match_scope(pe, image, entries):
    host = entries[HOST]
    assert (host.EndAddress, host.UnwindData) == (HOST_END, HOST_UNWIND)
    version_flags, prologue, codes, _ = struct.unpack_from("<BBBB", image, HOST_UNWIND)
    assert (version_flags, prologue, codes) == (9, 4, 1)
    handler_field = HOST_UNWIND + 4 + 2 * ((codes + 1) & ~1)
    handler, count, begin, end, filter_rva, continuation = struct.unpack_from("<IIIIII", image, handler_field)
    assert (handler, count, begin, end, filter_rva, continuation) == (0x18066, 1, 0x15BE3, 0x15C6D, START, 0x15C6D)
    thunk = Decoder(64, image[handler:handler + 6], ip=handler).decode()
    assert thunk.flow_control == FlowControl.INDIRECT_BRANCH and thunk.is_ip_rel_memory_operand
    iat = thunk.ip_rel_memory_address
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = [(table.dll.decode(), item.name.decode()) for table in pe.DIRECTORY_ENTRY_IMPORT
               for item in table.imports if item.address == base + iat and item.name]
    assert iat == 0x190B0 and imports == [("VCRUNTIME140.dll", "__C_specific_handler")]
    landing = Decoder(64, image[continuation:continuation + 3], ip=continuation).decode()
    assert image[landing.ip:landing.next_ip] == bytes.fromhex("32c0")
    return {"host": [hex(HOST), hex(HOST_END)], "host_unwind_rva": hex(HOST_UNWIND),
            "scope_record_rva": hex(handler_field + 8), "protected_range": [hex(begin), hex(end)],
            "filter_rva": hex(filter_rva), "continuation_rva": hex(continuation),
            "handler_thunk_rva": hex(handler), "iat_rva": hex(iat), "handler": "!".join(imports[0])}


def replay(original, zig, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL_SHA
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == SPAN_SHA
    with TemporaryDirectory() as folder:
        path = Path(folder) / "exception-filter.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "exception-filter.c"), "-o", str(path)], check=True)
        obj = path.read_bytes()
    entries = {row.struct.BeginAddress: row.struct for row in pe.DIRECTORY_ENTRY_EXCEPTION}
    match_region(obj, image)
    unwind = match_unwind(obj, image, entries)
    scope = match_scope(pe, image, entries)
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions = list(disassembler.disasm(region, START))
    decoded = {instruction.ip: instruction for instruction in Decoder(64, region, ip=START)}
    assert sum(instruction.size for instruction in instructions) == len(region)
    assert [(ins.address, ins.size) for ins in instructions] == [(ins.ip, ins.len) for ins in decoded.values()]
    expected = {
        0x186F3: ("push", "rbp"), 0x186F5: ("mov", "rbp, rdx"),
        0x186F8: ("mov", "rax, qword ptr [rcx]"), 0x186FB: ("xor", "ecx, ecx"),
        0x186FD: ("cmp", "dword ptr [rax], 0xc0000005"), 0x18703: ("sete", "cl"),
        0x18706: ("mov", "eax, ecx"), 0x18708: ("pop", "rbp"),
        0x18709: ("ret", ""), 0x1870A: ("int3", ""),
    }
    assert {ins.address: (ins.mnemonic, ins.op_str) for ins in instructions} == expected
    assert decoded[0x186FD].immediate32 == 0xC0000005
    assert decoded[0x18709].flow_control == FlowControl.RETURN
    if listing:
        text_listing = "\n".join(f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip()
                                 for ins in instructions)
        scope_field = int(scope["scope_record_rva"], 0) + 8
        listing.write_text(f"{text_listing}\n{scope_field:#x} {image[scope_field:scope_field + 4].hex()}"
                           f" dd {scope['filter_rva']} ; EH scope filter of 0x15bdc\n",
                           encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL_SHA, "range_sha256": SPAN_SHA, "range": [hex(START), hex(END)],
            "matched_bytes": len(region), "instructions": len(instructions), "executable_instructions": 9,
            "padding_rvas": ["0x1870a"], "relocations": [], "unwind": unwind, "host_scope": scope,
            "return_rule": {"compared_operand": "DWORD PTR [QWORD PTR [RCX]]",
                            "status": hex(decoded[0x186FD].immediate32), "eax_equal": 1, "eax_otherwise": 0}}


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
