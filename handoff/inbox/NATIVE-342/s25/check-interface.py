"""Reassemble the interface wrapper and compare its PE code and unwind records."""

import argparse
import hashlib
import json
from pathlib import Path
import runpy
import struct
import sys
from tempfile import TemporaryDirectory
from uuid import UUID

import capstone
from capstone.x86_const import X86_OP_MEM, X86_REG_RIP
import pefile


HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies

START = 0x339A0
END = 0x33A14
RANGE_SHA = "b65931ff6417863e4cdce73dd1727829bf80a45b7e38b90f735d512b2ce930d7"


def verify(original, zig, source, listing):
    data = original.read_bytes()
    if hashlib.sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("Original SHA-256 differs")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    if hashlib.sha256(image[START:END]).hexdigest() != RANGE_SHA:
        raise ValueError("Original scope differs")
    runtime, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION
                if entry.struct.BeginAddress == START)
    unwind = runtime.UnwindData
    assert (runtime.EndAddress, unwind) == (END, 0x48E28)
    assert image[unwind:unwind + 4] == bytes((1, 0x27, 6, 0))

    inspect = runpy.run_path(str(HERE.parent / "s21/check-release-shell.py"))["inspect_unwind_sections"]
    with TemporaryDirectory() as temp:
        obj = Path(temp) / "interface.obj"
        compile_bodies(source, zig, obj)
        payload = obj.read_bytes()
        body = compare(payload, image, {START: END - START}).get(START)
        if body is None:
            raise ValueError("Reassembled interface wrapper differs from original .text")
        sections = inspect(payload)
    pdata, relocations = sections[".pdata"]
    xdata, unwind_relocations = sections[".xdata"]
    assert relocations == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    assert unwind_relocations == []
    for offset, symbol in relocations:
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, addend + {".text": START, ".xdata": unwind}[symbol])
    offset = runtime.get_file_offset()
    assert len(pdata) == 12 and pdata == data[offset:offset + 12], ".pdata mismatch"
    assert len(xdata) == 16 and xdata == image[unwind:unwind + 16], ".xdata mismatch"

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = list(decoder.disasm(image[START:END], START))
    assert sum(instruction.size for instruction in instructions) == END - START
    references = {}
    for instruction in instructions:
        for operand in instruction.operands:
            if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                references[instruction.address] = instruction.address + instruction.size + operand.mem.disp
    assert references == {0x339CE: 0x42978, 0x339E0: 0x42AF8, 0x339E7: 0x3AB68}
    image_base = pe.OPTIONAL_HEADER.ImageBase
    binding, = ((module.dll.decode(), entry.name.decode()) for module in pe.DIRECTORY_ENTRY_IMPORT
                for entry in module.imports if entry.address - image_base == 0x3AB68)
    assert binding == ("ole32.dll", "CoCreateInstance")
    if listing:
        listing.write_text("".join(
            f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n" for i in instructions
        ), encoding="utf-8", newline="\n")
    return {
        "original_sha256": ORIGINAL,
        "range": [hex(START), hex(END)],
        "instructions": len(instructions),
        "reassembly": body,
        "unwind": {"pdata_hex": pdata.hex(), "pdata_relocations": len(relocations),
                   "xdata_rva": hex(unwind), "xdata_hex": xdata.hex(), "xdata_relocations": 0},
        "iid": str(UUID(bytes_le=image[0x42978:0x42988])),
        "clsid": str(UUID(bytes_le=image[0x42AF8:0x42B08])),
        "import": "!".join(binding),
        "rip_references": {hex(site): hex(target) for site, target in references.items()},
        "indirect": {"site": "0x339ff", "operand": "[rdx+8]",
                     "abi_slot": 1, "runtime_target": "unresolved"},
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "create-interface.c")
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.original, args.zig, args.source, args.listing), indent=2))
