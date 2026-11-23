"""Static replay of the AMD64 CRT process-attach routine."""
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
START, END, UNWIND = 0x359C4, 0x35ADA, 0x48FA4
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SPAN = "b800253ad5cbaf49cc76bae0c845822204ad369d8d006ab2e2f10f386153102a"


def require(condition, message):
    if not condition:
        raise ValueError(message)


def metadata(obj, original, pe, image, helpers):
    runtime, = (e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION if e.struct.BeginAddress == START)
    require((runtime.EndAddress, runtime.UnwindData) == (END, UNWIND), "Runtime range or unwind RVA differs")
    sections = helpers["inspect_unwind_sections"](obj)
    targets = {".text": START, ".xdata": UNWIND, "rva_362e0": 0x362e0, "rva_395b6": 0x395b6}
    expected = {
        ".pdata": [(0, ".text"), (4, ".text"), (8, ".xdata")],
        ".xdata": [(20, "rva_362e0"), (28, ".text"), (32, ".text"), (36, "rva_395b6"),
                   (44, ".text"), (48, ".text"), (52, "rva_395b6")],
    }
    records = {}
    file_offset = runtime.get_file_offset()
    for name, (section, relocations) in sections.items():
        require(relocations == expected[name], f"{name} relocation differs")
        for loc, symbol in relocations:
            addend, = struct.unpack_from("<I", section, loc)
            struct.pack_into("<I", section, loc, addend + targets[symbol])
        original_bytes = original[file_offset:file_offset+12] if name == ".pdata" else image[UNWIND:UNWIND+60]
        require(section == original_bytes, f"{name} content differs")
        records[name] = {"bytes": section.hex(), "image_relative_fixups": relocations}
    records[".pdata"]["file_offset"] = hex(file_offset)
    records[".xdata"]["rva"] = hex(UNWIND)
    records["termination_scopes"] = [["0x359fc", "0x35a6b", "0x395b6", 0],
                                     ["0x35ace", "0x35ad9", "0x395b6", 0]]
    return records


def replay(original, compiler, listing):
    raw = original.read_bytes()
    require(sha256(raw).hexdigest() == ORIGINAL, "Original SHA-256 differs")
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    require(sha256(image[START:END]).hexdigest() == SPAN, "Original range differs")
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = list(decoder.disasm(image[START:END], START))
    require(sum(i.size for i in body) == END - START, "Incomplete decode")
    helpers = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        path = Path(directory) / "attach.obj"
        helpers["compile_bodies"](HERE / "crt-attach.c", compiler, path)
        obj = path.read_bytes()
    match = helpers["compare"](obj, image, {START: END - START}).get(START)
    require(match, "Reassembled process-attach body differs from pinned .text")
    def rip(i):
        mem, = (o.mem for o in i.operands if o.type == X86_OP_MEM and o.mem.base == X86_REG_RIP)
        return i.address + i.size + mem.disp
    relocations = []
    for i in body:
        if i.mnemonic == "call" and i.op_str.startswith("0x"):
            offset, target = i.imm_offset, i.operands[0].imm
        elif "rip" in i.op_str:
            offset, target = i.disp_offset, rip(i)
        else:
            continue
        relocations.append([hex(i.address + offset), hex(target), 4])
    require(match["relocations"] == relocations and len(relocations) == 22, "REL32 bindings differ")
    unwind = metadata(obj, raw, pe, image, helpers)
    imports = {i.address - pe.OPTIONAL_HEADER.ImageBase: d.dll.decode() + "!" + i.name.decode()
               for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
    bindings = {}
    for thunk, slot, name in [(0x36334, 0x3a758, "api-ms-win-crt-runtime-l1-1-0.dll!_initterm_e"),
                              (0x3632e, 0x3a7a8, "api-ms-win-crt-runtime-l1-1-0.dll!_initterm"),
                              (0x362e0, 0x3a630, "VCRUNTIME140.dll!__C_specific_handler")]:
        jump, = decoder.disasm(image[thunk:thunk+6], thunk)
        require((jump.mnemonic, rip(jump), imports[slot]) == ("jmp", slot, name), "Wrong import")
        bindings[hex(thunk)] = [hex(slot), name]
    base = pe.OPTIONAL_HEADER.ImageBase
    guard = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer - base
    sec = pe.get_section_by_rva(0x54870)
    producer, ret = decoder.disasm(image[0x360cc:0x360d4], 0x360cc)
    require((producer.mnemonic, rip(producer), ret.mnemonic) == ("lea", 0x54870, "ret"), "Callback slot differs")
    require(sec.Characteristics & 0x80000000 and sec.VirtualAddress + sec.SizeOfRawData <= 0x54870
            and image[0x54870:0x54878] == bytes(8), "Expected writable zero-filled callback slot")
    require(guard == 0x3ac20 and struct.unpack_from("<Q", image, guard)[0] == base + 0x36ae0
            and image[0x36ae0:0x36ae2] == bytes.fromhex("ffe0"), "Guard dispatcher differs")
    cleanup = [(i.mnemonic, i.op_str) for i in decoder.disasm(image[0x395b6:0x395cc], 0x395b6)]
    require(cleanup[3] == ("mov", "cl, byte ptr [rbp + 0x40]") and cleanup[-1] == ("jmp", "0x35418"),
            "Termination funclet differs")
    if listing:
        listing.write_text("".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip()+"\n"
                                   for i in body), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
            "instructions": len(body), "reassembly": [match], "unwind": unwind, "thunks": bindings,
            "state": {"slot": "0x541d0", "requires": 0, "enter": 1, "initialized": 2},
            "initializers": {"0x35a39": ["0x3acc0", "0x3acc8", "_initterm_e"],
                             "0x35a59": ["0x3ac48", "0x3acb8", "_initterm"]},
            "conditional_call": {"site": "0x35aa6", "R9": "GuardCFDispatchFunctionPointer at RVA 0x3ac20",
                                 "disk_dispatch": "0x36ae0 jmp rax", "RAX": "qword at RVA 0x54870",
                                 "arguments": ["original RCX", 2, "original RDX"],
                                 "preconditions": "Non-null callback and 0x35380 verifies non-writable slot section.",
                                 "limitation": "The mapped original slot is zero and its section is writable. No live callback identity is evidenced."},
            "follow_up": {"range": ["0x35adc", "0x35b60"], "sha256": sha256(image[0x35adc:0x35b60]).hexdigest()}}


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

