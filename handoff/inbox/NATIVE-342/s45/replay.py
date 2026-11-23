"""Replay the scoped object cleanup and bind its PE data and import references."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
from runpy import run_path
import struct
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
START, END, UNWIND = 0x34E90, 0x34ED4, 0x44660
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SCOPE = "83775a03ae2ae71bffd68eec65a47da50fe4e46b9805833aa6062f1a1c73d913"
FIXUPS = [[0x34E99, 0x42A90, 4], [0x34EB5, 0x3AC20, 4], [0x34ECA, 0x3A2F0, 4]]


def compare_text(previous, obj, image):
    section_count, = struct.unpack_from("<H", obj, 2)
    text_header, = (pos for pos in range(20, 20 + 40 * section_count, 40)
                    if obj[pos:pos + 8] == b".text\0\0\0")
    size, offset = struct.unpack_from("<II", obj, text_header + 16)
    fixup_count, = struct.unpack_from("<H", obj, text_header + 32)
    assert size == END - START and fixup_count == len(FIXUPS)
    rebuilt = previous["compare"](obj, image, {START: size}).get(START)
    if not rebuilt:
        # The expected REL32 layout is used only to locate the first differing byte.
        text = bytearray(obj[offset:offset + size])
        for site, target, _ in FIXUPS:
            pos = site - START
            addend, = struct.unpack_from("<i", text, pos)
            struct.pack_into("<i", text, pos, target - site - 4 + addend)
        for pos, (actual, expected) in enumerate(zip(text, image[START:END])):
            if actual != expected:
                raise ValueError(f"Reassembled byte differs at RVA {START + pos:#x}: "
                                 f"{actual:#04x} instead of {expected:#04x}")
        raise ValueError("Reassembled cleanup has a symbol or relocation mismatch")
    assert rebuilt["relocations"] == [[hex(site), hex(target), kind] for site, target, kind in FIXUPS]
    return rebuilt


def compare_unwind(sections, pe, image, original):
    entry, = (item.struct for item in pe.DIRECTORY_ENTRY_EXCEPTION if item.struct.BeginAddress == START)
    assert (entry.EndAddress, entry.UnwindData) == (END, UNWIND)
    pdata, fixups = sections[".pdata"]
    assert fixups == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, base + addend)
    file_offset = entry.get_file_offset()
    assert len(pdata) == 12 and pdata == original[file_offset:file_offset + 12]
    xdata, fixups = sections[".xdata"]
    assert not fixups and len(xdata) == 8 and xdata == image[UNWIND:UNWIND + 8]
    assert tuple(xdata) == (1, 6, 2, 0, 6, 0x32, 2, 0x30)
    return {
        "pdata_file_offset": hex(file_offset), "pdata": pdata.hex(),
        "pdata_addr32nb": 3, "xdata": xdata.hex(), "xdata_rva": hex(UNWIND),
        "prologue_bytes": 6, "push": "RBX", "stack_allocation": 32,
    }


def inspect_original(pe, image, listing):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {ins.address: ins for ins in decoder.disasm(image[START:END], START)}
    assert sum(ins.size for ins in body.values()) == END - START
    expected = {
        0x34E9D: ("mov", "rbx, rcx"),
        0x34EA0: ("mov", "qword ptr [rcx], rax"),
        0x34EA3: ("mov", "rcx, qword ptr [rcx + 0x10]"),
        0x34EA7: ("test", "rcx, rcx"),
        0x34EAA: ("je", "0x34eb9"),
        0x34EAC: ("mov", "rax, qword ptr [rcx]"),
        0x34EAF: ("mov", "rax, qword ptr [rax + 0x10]"),
        0x34EB9: ("mov", "rcx, qword ptr [rbx + 0x18]"),
        0x34EBD: ("test", "rcx, rcx"),
        0x34EC0: ("je", "0x34ece"),
        0x34EC2: ("add", "rsp, 0x20"),
        0x34EC6: ("pop", "rbx"),
        0x34ECE: ("add", "rsp, 0x20"),
        0x34ED2: ("pop", "rbx"),
        0x34ED3: ("ret", ""),
    }
    for site, pair in expected.items():
        assert (body[site].mnemonic, body[site].op_str) == pair, hex(site)
    targets = []
    for site, mnemonic in ((0x34E96, "lea"), (0x34EB3, "call"), (0x34EC7, "jmp")):
        ins = body[site]
        assert ins.mnemonic == mnemonic
        memory, = (op.mem for op in ins.operands
                   if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
        assert ins.address + ins.disp_offset == FIXUPS[len(targets)][0]
        targets.append(ins.address + ins.size + memory.disp)
    vtable, dispatch, import_slot = targets
    assert targets == [target for _, target, _ in FIXUPS]
    assert all(pe.get_section_by_rva(rva).Name.rstrip(b"\0") == b".rdata" for rva in targets)
    base = pe.OPTIONAL_HEADER.ImageBase
    config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    field_rva = pe.get_rva_from_offset(config.get_field_absolute_offset("GuardCFDispatchFunctionPointer"))
    assert config.GuardFlags & 0x100 and config.GuardCFDispatchFunctionPointer == base + dispatch
    assert field_rva == 0x42CC8
    dir64 = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
             for entry in block.entries if entry.type == 10}
    assert {vtable, dispatch, field_rva} <= dir64
    first_method, thunk = [struct.unpack_from("<Q", image, rva)[0] - base
                           for rva in (vtable, dispatch)]
    assert (first_method, thunk) == (0x34EE0, 0x36AE0)
    assert any(item.struct.BeginAddress == first_method for item in pe.DIRECTORY_ENTRY_EXCEPTION)
    original_thunk, = decoder.disasm(image[thunk:thunk + 2], thunk)
    assert (original_thunk.mnemonic, original_thunk.op_str) == ("jmp", "rax")
    library, name = next((lib.dll, imp.name)
                         for lib in pe.DIRECTORY_ENTRY_IMPORT for imp in lib.imports
                         if imp.address - base == import_slot)
    assert (library, name) == (b"KERNEL32.dll", b"LocalFree")
    name_rva, = struct.unpack_from("<Q", image, import_slot)
    assert image[name_rva + 2:name_rva + 3 + len(name)] == name + b"\0"
    if listing:
        listing.write_text("".join(
            f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
            for ins in body.values()), encoding="utf-8", newline="\n")
    return {
        "instructions": len(body),
        "vtable": {
            "rva": hex(vtable), "first_entry_bytes": image[vtable:vtable + 8].hex(),
            "first_entry_rva": hex(first_method),
        },
        "virtual_call": {
            "site": "0x34eb3", "null_receiver_branch": "0x34eaa -> 0x34eb9",
            "receiver": "qword [object RCX + 0x10]",
            "target": "qword [qword [receiver] + 0x10]",
            "load_config_field_rva": hex(field_rva), "dispatch_slot": hex(dispatch),
            "dispatch_slot_bytes": image[dispatch:dispatch + 8].hex(),
            "on_disk_thunk": f"{thunk:#x} {original_thunk.bytes.hex()} jmp rax",
            "unresolved": "The receiver virtual table and final target are runtime values.",
        },
        "tail_jump": {
            "site": "0x34ec7", "null_buffer_branch": "0x34ec0 -> 0x34ece",
            "argument": "qword [object RBX + 0x18]", "import_slot": hex(import_slot),
            "import_name_rva": hex(name_rva), "import_name": f"{library.decode()}!{name.decode()}",
            "iat_bytes": image[import_slot:import_slot + 8].hex(),
        },
    }


def replay(original, zig, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == SCOPE
    previous = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "cleanup.obj"
        previous["compile_bodies"](HERE / "com-error-cleanup.c", zig, obj)
        payload = obj.read_bytes()
    rebuilt = compare_text(previous, payload, image)
    frame = compare_unwind(previous["inspect_unwind_sections"](payload), pe, image, data)
    return {
        "original_sha256": ORIGINAL, "range_sha256": SCOPE, "range": [hex(START), hex(END)],
        "reassembly": rebuilt, "unwind": frame, **inspect_original(pe, image, listing),
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
