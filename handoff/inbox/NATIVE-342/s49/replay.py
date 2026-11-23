"""Reassemble the deleting-destructor scope and verify original PE references."""
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
START, END, UNWIND = 0x34EE0, 0x34F3F, 0x44E68
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SCOPE = "5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc"
FIXUPS = [(0x34EED, 0x42A90), (0x34F0B, 0x3AC20), (0x34F1A, 0x3A2F0), (0x34F2D, 0x35134)]


def rip_target(ins):
    memory, = (op.mem for op in ins.operands if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
    return ins.address + ins.size + memory.disp


def compare_text(helpers, obj, image):
    sec_count, = struct.unpack_from("<H", obj, 2)
    header, = (pos for pos in range(20, 20 + 40 * sec_count, 40) if obj[pos:pos + 8] == b".text\0\0\0")
    size, offset = struct.unpack_from("<II", obj, header + 16)
    count, = struct.unpack_from("<H", obj, header + 32)
    if (size, count) != (END - START, len(FIXUPS)):
        raise ValueError(f"Unexpected COFF code layout: {size} bytes, {count} relocations")
    match = helpers["compare"](obj, image, {START: size}).get(START)
    if match:
        assert match["relocations"] == [[hex(site), hex(target), 4] for site, target in FIXUPS]
        return match
    # Expected layout is used here only to report the first differing byte.
    relocated = bytearray(obj[offset:offset + size])
    for site, target in FIXUPS:
        pos = site - START
        addend, = struct.unpack_from("<i", relocated, pos)
        struct.pack_into("<i", relocated, pos, target - site - 4 + addend)
    for pos, (actual, expected) in enumerate(zip(relocated, image[START:END])):
        if actual != expected:
            raise ValueError(f"Reassembled byte differs at RVA {START + pos:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")
    raise ValueError("Reassembled scope has a COFF symbol or relocation mismatch")


def compare_unwind(sections, pe, image, original):
    entry, = (item.struct for item in pe.DIRECTORY_ENTRY_EXCEPTION if item.struct.BeginAddress == START)
    assert (entry.EndAddress, entry.UnwindData) == (END, UNWIND)
    pdata, relocations = sections[".pdata"]
    assert relocations == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, base + addend)
    file_offset = entry.get_file_offset()
    assert len(pdata) == 12 and pdata == original[file_offset:file_offset + 12]
    xdata, relocations = sections[".xdata"]
    assert not relocations and len(xdata) == 12 and xdata == image[UNWIND:UNWIND + 12]
    assert xdata.hex() == "010a04000a3406000a320670"
    return {"pdata_file_offset": hex(file_offset), "pdata_bytes": pdata.hex(),
            "xdata_rva": hex(UNWIND), "xdata_bytes": xdata.hex(), "pdata_addr32nb": 3,
            "prologue_bytes": 10, "pushed": "RDI", "stack_allocation": 32,
            "saved_rbx_offset_from_final_rsp": 48}


def inspect_original(pe, image, listing):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {ins.address: ins for ins in decoder.disasm(image[START:END], START)}
    assert len(body) == 27 and sum(ins.size for ins in body.values()) == END - START
    expected = {
        0x34EF1: ("mov", "rbx, rcx"), 0x34EF4: ("mov", "qword ptr [rcx], rax"),
        0x34EF7: ("mov", "edi, edx"), 0x34EF9: ("mov", "rcx, qword ptr [rcx + 0x10]"),
        0x34EFD: ("test", "rcx, rcx"), 0x34F00: ("je", "0x34f0f"),
        0x34F02: ("mov", "rax, qword ptr [rcx]"), 0x34F05: ("mov", "rax, qword ptr [rax + 0x10]"),
        0x34F0F: ("mov", "rcx, qword ptr [rbx + 0x18]"),
        0x34F13: ("test", "rcx, rcx"), 0x34F16: ("je", "0x34f1e"),
        0x34F1E: ("test", "dil, 1"), 0x34F22: ("je", "0x34f31"),
        0x34F24: ("mov", "edx, 0x20"), 0x34F29: ("mov", "rcx, rbx"),
        0x34F31: ("mov", "rax, rbx"), 0x34F34: ("mov", "rbx, qword ptr [rsp + 0x30]"),
        0x34F39: ("add", "rsp, 0x20"), 0x34F3D: ("pop", "rdi"), 0x34F3E: ("ret", ""),
    }
    for site, pair in expected.items():
        assert (body[site].mnemonic, body[site].op_str) == pair, hex(site)
    relocations = []
    for site, mnemonic in ((0x34EEA, "lea"), (0x34F09, "call"), (0x34F18, "call")):
        ins = body[site]
        assert ins.mnemonic == mnemonic
        relocations.append((site + ins.disp_offset, rip_target(ins)))
    call = body[0x34F2C]
    assert call.mnemonic == "call" and call.operands[0].type == X86_OP_IMM
    callee = call.operands[0].imm
    relocations.append((call.address + call.imm_offset, callee))
    assert relocations == FIXUPS
    vtable, dispatch, buffer_slot, _ = (target for _, target in relocations)
    assert all(pe.get_section_by_rva(rva).Name.rstrip(b"\0") == b".rdata"
               for rva in (vtable, dispatch, buffer_slot))
    branch, = decoder.disasm(image[callee:callee + 5], callee)
    assert branch.mnemonic == "jmp" and branch.operands[0].type == X86_OP_IMM
    import_thunk = branch.operands[0].imm
    tail, = decoder.disasm(image[import_thunk:import_thunk + 6], import_thunk)
    assert tail.mnemonic == "jmp"
    delete_slot = rip_target(tail)
    assert (callee, import_thunk, delete_slot) == (0x35134, 0x34F80, 0x3A9E0)

    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {imp.address - base: (library.dll, imp.name, imp.ordinal)
               for library in pe.DIRECTORY_ENTRY_IMPORT for imp in library.imports}
    assert imports[buffer_slot] == (b"KERNEL32.dll", b"LocalFree", None)
    assert imports[delete_slot] == (b"mfc140.dll", None, 1487)
    assert struct.unpack_from("<Q", image, delete_slot)[0] == ((1 << 63) | 1487)
    name_rva, = struct.unpack_from("<Q", image, buffer_slot)
    assert image[name_rva + 2:name_rva + 12] == b"LocalFree\0"
    config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    field = pe.get_rva_from_offset(config.get_field_absolute_offset("GuardCFDispatchFunctionPointer"))
    assert field == 0x42CC8 and config.GuardFlags & 0x100 and config.GuardCFDispatchFunctionPointer == base + dispatch
    dir64 = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for entry in block.entries if entry.type == 10}
    assert {vtable, dispatch, field} <= dir64
    assert struct.unpack_from("<Q", image, vtable)[0] == base + START
    thunk = struct.unpack_from("<Q", image, dispatch)[0] - base
    first, = decoder.disasm(image[thunk:thunk + 2], thunk)
    assert (thunk, first.mnemonic, first.op_str) == (0x36AE0, "jmp", "rax")
    if listing:
        listing.write_text("".join(
            f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
            for ins in body.values()), encoding="utf-8", newline="\n")
    return {
        "instructions": len(body), "vtable": {"rva": hex(vtable), "first_entry_rva": hex(START)},
        "virtual_call": {"site": "0x34f09", "receiver": "qword [object + 0x10]",
                         "target": "qword [qword [receiver] + 0x10]",
                         "dispatch_slot": hex(dispatch), "load_config_field": hex(field),
                         "on_disk_dispatch_thunk": hex(thunk), "target_known": False},
        "buffer_free": {"site": "0x34f18", "argument": "qword [object + 0x18]",
                        "condition": "argument is nonzero", "import_slot": hex(buffer_slot),
                        "target": "KERNEL32.dll!LocalFree"},
        "conditional_release": {"condition_site": "0x34f22", "condition": "(DIL & 1) != 0",
                                "call_site": "0x34f2c", "arguments": ["RCX = object", "EDX = 0x20"],
                                "chain": [hex(callee), hex(import_thunk), hex(delete_slot), "mfc140.dll!#1487"]},
    }


def replay(original, zig, source, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == SCOPE
    helpers = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "cleanup.obj"
        helpers["compile_bodies"](source, zig, obj)
        compiled = obj.read_bytes()
    return {
        "original_sha256": ORIGINAL, "range_sha256": SCOPE, "range": [hex(START), hex(END)],
        "reassembly": compare_text(helpers, compiled, image),
        "unwind": compare_unwind(helpers["inspect_unwind_sections"](compiled), pe, image, data),
        **inspect_original(pe, image, listing),
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "com-error-deleting-destructor.c")
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    try:
        print(json.dumps(replay(args.original, args.zig, args.source, args.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
