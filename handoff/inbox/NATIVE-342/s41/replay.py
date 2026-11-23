"""Replay the ApwnIPShell constructor against the original PE."""

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
START, END, UNWIND = 0x34E40, 0x34E85, 0x44660
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SCOPE = "dfeaea0ef12e23a31c55b931d22c4df503a8cbdc067c31c4d5f1434aff37af51"


def compare_unwind(sections, pe, image):
    entry, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION if entry.struct.BeginAddress == START)
    assert (entry.EndAddress, entry.UnwindData) == (END, UNWIND)
    pdata, relocations = sections[".pdata"]
    assert relocations == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    assert len(pdata) == 12
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, base + addend)
    assert pdata == entry.__pack__()
    xdata, relocations = sections[".xdata"]
    assert not relocations and xdata == image[UNWIND:UNWIND + 8]
    return {"pdata": pdata.hex(), "xdata": xdata.hex(), "xdata_rva": hex(UNWIND)}


def replay(original, zig, listing):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    code = image[START:END]
    assert sha256(code).hexdigest() == SCOPE
    previous = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "constructor.obj"
        previous["compile_bodies"](HERE / "com-error-construct.c", zig, obj)
        payload = obj.read_bytes()
    rebuilt = previous["compare"](payload, image, {START: len(code)}).get(START)
    if not rebuilt:
        raise ValueError("Constructor bytes differ at RVA 0x34e40")
    assert rebuilt["relocations"] == [["0x34e4c", "0x42a90", 4], ["0x34e78", "0x3ac20", 4]]
    frame = compare_unwind(previous["inspect_unwind_sections"](payload), pe, image)

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {ins.address: ins for ins in decoder.disasm(code, START)}
    assert sum(ins.size for ins in body.values()) == len(code)
    exact = {
        0x34E46: ("mov", "dword ptr [rcx + 8], edx"),
        0x34E50: ("mov", "qword ptr [rcx], rax"),
        0x34E56: ("mov", "qword ptr [rcx + 0x10], r8"),
        0x34E5A: ("mov", "qword ptr [rcx + 0x18], 0"),
        0x34E62: ("test", "r8, r8"),
        0x34E65: ("je", "0x34e7c"),
        0x34E67: ("test", "r9b, r9b"),
        0x34E6A: ("je", "0x34e7c"),
        0x34E6C: ("mov", "rax, qword ptr [r8]"),
        0x34E6F: ("mov", "rcx, r8"),
        0x34E72: ("mov", "rax, qword ptr [rax + 8]"),
        0x34E7C: ("mov", "rax, rbx"),
    }
    for site, expected in exact.items():
        assert (body[site].mnemonic, body[site].op_str) == expected, hex(site)
    targets = []
    for site, mnemonic in ((0x34E49, "lea"), (0x34E76, "call")):
        ins = body[site]
        assert ins.mnemonic == mnemonic
        memory, = (op.mem for op in ins.operands
                   if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
        targets.append(ins.address + ins.size + memory.disp)
    vtable, dispatch = targets
    assert (vtable, dispatch) == (0x42A90, 0x3AC20)
    base = pe.OPTIONAL_HEADER.ImageBase
    config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    assert config.GuardFlags & 0x100 and config.GuardCFDispatchFunctionPointer == base + dispatch
    slots = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
             for entry in block.entries if entry.type == 10}
    assert {vtable, dispatch} <= slots
    first_vfunc, dispatcher = [struct.unpack_from("<Q", image, r)[0] - base for r in targets]
    assert (first_vfunc, dispatcher) == (0x34EE0, 0x36AE0)
    ins, = decoder.disasm(image[dispatcher:dispatcher + 2], dispatcher)
    assert (ins.mnemonic, ins.op_str) == ("jmp", "rax")
    if listing:
        listing.write_text("".join(
            f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
            for ins in body.values()), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range_sha256": SCOPE, "range": [hex(START), hex(END)],
            "instructions": len(body), "reassembly": rebuilt, "unwind": frame,
            "destination_vtable": hex(vtable), "first_vfunc": hex(first_vfunc),
            "skip_on": ["R8 == 0", "R9B == 0"], "call_site": "0x34e76",
            "receiver": "R8 (passed as RCX)", "target": "qword [qword [R8] + 8]",
            "dispatch_slot": hex(dispatch), "on_disk_dispatcher": hex(dispatcher),
            "runtime_gap": "Live receiver virtual table and final target are undetermined."}


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
