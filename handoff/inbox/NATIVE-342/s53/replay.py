"""Compare the scoped COFF reconstruction and original C++ exception bindings."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
from runpy import run_path
import struct
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
START, END, UNWIND = 0x34F40, 0x34F68, 0x44E74
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SPAN = "bc67b3c5c586198379f3f21e843c88a1850124f1e5d5b9eeabe133f2e1ae75b0"
FIXUPS = [(0x34F52, 0x34E40), (0x34F59, 0x492B0), (0x34F63, 0x362C2)]


def rip_target(instruction):
    memory, = (arg.mem for arg in instruction.operands
               if arg.type == X86_OP_MEM and arg.mem.base == X86_REG_RIP)
    return instruction.address + instruction.size + memory.disp


def compare_code(compare, obj, image):
    count, = struct.unpack_from("<H", obj, 2)
    offset, = (off for off in range(20, 20 + 40 * count, 40)
               if obj[off:off + 8] == b".text\0\0\0")
    size, file_offset = struct.unpack_from("<II", obj, offset + 16)
    relocation_count, = struct.unpack_from("<H", obj, offset + 32)
    if (size, relocation_count) != (END - START, len(FIXUPS)):
        raise ValueError(f"Unexpected COFF layout: {size} bytes, {relocation_count} relocations")
    match = compare(obj, image, {START: size}).get(START)
    if match:
        assert match["relocations"] == [[hex(at), hex(to), 4] for at, to in FIXUPS]
        return match
    candidate = bytearray(obj[file_offset:file_offset + size])
    for address, target in FIXUPS:
        offset = address - START
        addend, = struct.unpack_from("<i", candidate, offset)
        struct.pack_into("<i", candidate, offset, target - address - 4 + addend)
    for i, (actual, expected) in enumerate(zip(candidate, image[START:END])):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + i:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")
    raise ValueError("Reassembled scope has a COFF symbol or relocation mismatch")


def compare_unwind(sections, pe, original, image):
    entry, = (e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION if e.struct.BeginAddress == START)
    assert (entry.EndAddress, entry.UnwindData) == (END, UNWIND)
    pdata, fixups = sections[".pdata"]
    assert fixups == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, addend + base)
    file_offset = entry.get_file_offset()
    assert len(pdata) == 12 and pdata == original[file_offset:file_offset + 12]
    xdata, fixups = sections[".xdata"]
    assert not fixups and xdata == image[UNWIND:UNWIND + 8]
    assert xdata.hex() == "0104010004820000"
    return {"pdata_file_offset": hex(file_offset), "pdata": pdata.hex(), "xdata_rva": hex(UNWIND),
            "xdata": xdata.hex(), "prologue_bytes": 4, "stack_allocation": 72}


def inspect_original(pe, image, listing):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = list(decoder.disasm(image[START:END], START))
    actual = [(i.address, i.mnemonic, i.op_str) for i in instructions]
    assert actual == [
        (0x34F40, "sub", "rsp, 0x48"), (0x34F44, "mov", "r8, rdx"),
        (0x34F47, "xor", "r9d, r9d"), (0x34F4A, "mov", "edx, ecx"),
        (0x34F4C, "lea", "rcx, [rsp + 0x20]"), (0x34F51, "call", "0x34e40"),
        (0x34F56, "lea", "rdx, [rip + 0x14353]"), (0x34F5D, "lea", "rcx, [rsp + 0x20]"),
        (0x34F62, "call", "0x362c2"), (0x34F67, "int3", ""),
    ]
    assert sum(i.size for i in instructions) == END - START
    constructor, throw_data, throw_call = (instructions[index] for index in (5, 6, 8))
    assert constructor.operands[0].type == throw_call.operands[0].type == X86_OP_IMM
    throw_info = rip_target(throw_data)
    target = throw_call.operands[0].imm
    assert (constructor.operands[0].imm, throw_info, target) == (0x34E40, 0x492B0, 0x362C2)
    assert image[0x34E67:0x34E6C] == bytes.fromhex("4584c97410")
    thunk, = decoder.disasm(image[target:target + 6], target)
    assert thunk.mnemonic == "jmp"
    slot = rip_target(thunk)
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {imp.address - base: (dll.dll, imp.name)
               for dll in pe.DIRECTORY_ENTRY_IMPORT for imp in dll.imports}
    assert (slot, imports[slot]) == (0x3A640, (b"VCRUNTIME140.dll", b"_CxxThrowException"))

    attributes, destructor, forward, types = struct.unpack_from("<4I", image, throw_info)
    assert (attributes, destructor, forward, types) == (0, 0x34E90, 0, 0x492D0)
    count, first = struct.unpack_from("<2I", image, types)
    assert (count, first) == (1, 0x492E0)
    properties, descriptor, mdisp, pdisp, vdisp, size, copy = struct.unpack_from("<IIiiiII", image, first)
    assert (properties, descriptor, mdisp, pdisp, vdisp, size, copy) == (0, 0x529D8, 0, -1, 0, 32, 0x34DF0)
    name = image[descriptor + 16:descriptor + 33]
    assert name == b".?AV_com_error@@\0"

    if listing:
        listing.write_text("".join(
            f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
            for i in instructions), encoding="utf-8", newline="\n")
    return {
        "instructions": len(instructions), "call_setup_instructions": len(instructions) - 1,
        "constructor": {"site": "0x34f51", "target": "0x34e40", "rcx": "RSP + 0x20",
                        "edx": "initial ECX", "r8": "initial RDX", "r9d": 0,
                        "constructor_skips_addref": "0x34e67 test r9b,r9b; 0x34e6a je 0x34e7c"},
        "throw": {"site": "0x34f62", "rcx": "RSP + 0x20", "rdx": hex(throw_info),
                  "thunk": hex(target), "iat": hex(slot), "target": "VCRUNTIME140.dll!_CxxThrowException",
                  "following_int3": "0x34f67"},
        "throw_info": {"rva": hex(throw_info), "attributes": attributes, "destructor": hex(destructor),
                       "forward_rva": forward, "catchable_array": hex(types), "type_count": count,
                       "catchable_type": hex(first), "type_descriptor": hex(descriptor),
                       "raw_type_name": name.rstrip(b"\0").decode("ascii"), "object_size": size,
                       "copy_constructor": hex(copy)},
    }


def replay(original, zig, listing):
    original_bytes = original.read_bytes()
    assert sha256(original_bytes).hexdigest() == ORIGINAL
    pe = pefile.PE(data=original_bytes)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == SPAN
    tools = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "throw.obj"
        tools["compile_bodies"](HERE / "com-error-throw.c", zig, obj)
        compiled = obj.read_bytes()
    return {
        "original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
        "reassembly": compare_code(tools["compare"], compiled, image),
        "unwind": compare_unwind(tools["inspect_unwind_sections"](compiled), pe, original_bytes, image),
        **inspect_original(pe, image, listing),
    }


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
