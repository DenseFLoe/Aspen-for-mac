"""Rebuild the pinned CRT on-exit and PE section helpers and verify their COFF bindings."""

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
START, SPLIT, END = 0x352F4, 0x35380, 0x35418
SPAN = "4a6776f7c5a98e67967fae31a7dc3b68f427afebe72913f0f191aa4022a7f443"
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
FUNCTIONS = [(START, SPLIT - 1, 0x44660), (SPLIT, END, 0x48F28)]
FIXUPS = {
    0x352FC: (0x541E1, -1), 0x3530B: (0x35E80, 0), 0x3531A: (0x541E8, 0),
    0x3531F: (0x36310, 0), 0x3532A: (0x54200, 0), 0x3532F: (0x36310, 0),
    0x3533F: (0x42AB0, 0), 0x3534B: (0x541E8, 0), 0x35352: (0x541F8, 0),
    0x3535A: (0x54200, 0), 0x35361: (0x54210, 0), 0x35367: (0x541E1, -1),
    0x3537A: (0x35E94, 0), 0x3538F: (0, 0), 0x35398: (0x3C, 0), 0x3539F: (0, 0),
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def compare_code(compare, obj, image):
    count, = struct.unpack_from("<H", obj, 2)
    header, = (at for at in range(20, 20 + 40 * count, 40)
               if obj[at:at + 8] == b".text\0\0\0")
    size, file_offset = struct.unpack_from("<II", obj, header + 16)
    relocation_count, = struct.unpack_from("<H", obj, header + 32)
    require((size, relocation_count) == (END - START, len(FIXUPS)), "COFF code size or relocation count differs")
    obj_code = bytearray(obj[file_offset:file_offset + size])
    require(obj_code[SPLIT - START - 1] == image[SPLIT - 1] == 0xcc, "Alignment byte at 0x3537f differs")
    results = compare(obj, image, {START: SPLIT - START, SPLIT: END - SPLIT})
    if len(results) != 2:
        # Diagnose a code operand mismatch after mapping the pinned expected targets.
        for address, (target, _) in FIXUPS.items():
            offset = address - START
            addend, = struct.unpack_from("<i", obj_code, offset)
            struct.pack_into("<i", obj_code, offset, target + addend - (address + 4))
        for offset, (actual, expected) in enumerate(zip(obj_code, image[START:END])):
            require(actual == expected, f"Reassembled byte differs at RVA {START + offset:#x}: "
                                        f"{actual:#04x} instead of {expected:#04x}")
        raise ValueError("COFF symbol or relocation target differs")
    for rva, match in results.items():
        end = rva + match["bytes"]
        expected = []
        for address, (target, addend) in FIXUPS.items():
            if rva <= address < end:
                expected.append([hex(address), hex(target), 4])
                require(struct.unpack_from("<i", obj_code, address - START)[0] == addend,
                        f"COFF addend differs at {address:#x}")
        require(match["relocations"] == expected, f"COFF fixups differ at {rva:#x}")
    return list(results.values())


def compare_unwind(sections, entries, original, image):
    pdata, pdata_fixups = sections[".pdata"]
    xdata, xdata_fixups = sections[".xdata"]
    require(pdata_fixups == [(offset, symbol) for offset in (0, 12)
                            for offset, symbol in ((offset, ".text"), (offset + 4, ".text"),
                                                   (offset + 8, ".xdata"))], "Unexpected .pdata COFF relocations")
    require(xdata_fixups == [(16, "rva_362e0"), (24, ".text"), (28, ".text"),
                            (32, "rva_3959e"), (36, ".text")], "Unexpected .xdata COFF relocations")
    require(len(pdata) == 24 and len(xdata) == 40, "Unexpected metadata size")

    def relocate(data, offset, base):
        addend, = struct.unpack_from("<I", data, offset)
        struct.pack_into("<I", data, offset, base + addend)

    target_rvas = {".text": START, "rva_362e0": 0x362E0, "rva_3959e": 0x3959E}
    for offset, symbol in xdata_fixups:
        relocate(xdata, offset, target_rvas[symbol])
    rows = []
    for index, (begin, end, unwind) in enumerate(FUNCTIONS):
        entry = entries[begin]
        require((entry.EndAddress, entry.UnwindData) == (end, unwind), f"Unwind bounds differ at {begin:#x}")
        offset = index * 12
        relocate(pdata, offset, START)
        relocate(pdata, offset + 4, START)
        relocate(pdata, offset + 8, unwind - (8 if index else 0))
        pbytes = pdata[offset:offset + 12]
        xbytes = xdata[8:] if index else xdata[:8]
        at = entry.get_file_offset()
        require(pbytes == original[at:at + 12] and xbytes == image[unwind:unwind + len(xbytes)],
                f"COFF unwind differs at {begin:#x}")
        rows.append({"function": hex(begin), "end": hex(end), "pdata_file_offset": hex(at),
                     "pdata_bytes": pbytes.hex(), "xdata_rva": hex(unwind), "xdata_bytes": xbytes.hex()})
    require(xdata[:8].hex() == "0106020006320230"
            and xdata[8:16].hex() == "0904010004220000", "Unwind opcode fields differ")
    handler, count, begin, end, filter_, landing = struct.unpack_from("<6I", xdata, 16)
    require((handler, count, begin, end, filter_, landing) ==
            (0x362E0, 1, 0x35387, 0x35411, 0x3959E, 0x35411), "SEH scope differs")
    return rows, {"handler": hex(handler), "record_count": count, "range": [hex(begin), hex(end)],
                  "filter": hex(filter_), "landing": hex(landing)}


def inspect_original(pe, image, entries, listing):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {i.address: i for i in decoder.disasm(image[START:END], START)}
    require(sum(i.size for i in body.values()) == END - START, "Original code was not fully decoded")

    def rip(instruction):
        memory, = (arg.mem for arg in instruction.operands
                   if arg.type == X86_OP_MEM and arg.mem.base == X86_REG_RIP)
        return instruction.address + instruction.size + memory.disp

    references = {0x352FA: 0x541E1, 0x35317: 0x541E8, 0x35327: 0x54200, 0x3533B: 0x42AB0,
                  0x35347: 0x541E8, 0x3534F: 0x541F8, 0x35356: 0x54200, 0x3535E: 0x54210,
                  0x35365: 0x541E1, 0x3538C: 0, 0x35395: 0x3C, 0x3539C: 0}
    require(all(rip(body[site]) == target for site, target in references.items()), "RIP-relative target differs")
    flow = {0x35303: ("jne", "0x3536c"), 0x35305: ("cmp", "ecx, 1"), 0x35308: ("ja", "0x35374"),
            0x3530A: ("call", "0x35e80"), 0x35311: ("je", "0x3533b"), 0x35315: ("jne", "0x3533b"),
            0x3531E: ("call", "0x36310"), 0x35325: ("jne", "0x35337"), 0x3532E: ("call", "0x36310"),
            0x35335: ("je", "0x35365"), 0x35374: ("mov", "ecx, 5"), 0x35379: ("call", "0x35e94"),
            0x3537E: ("int3", ""), 0x3537F: ("int3", ""), 0x353A6: ("cmp", "dword ptr [rcx], 0x4550"),
            0x353B3: ("cmp", "word ptr [rcx + 0x18], ax"), 0x353BC: ("movzx", "edx, word ptr [rcx + 0x14]"),
            0x353C7: ("movzx", "eax, word ptr [rcx + 6]"), 0x353DC: ("mov", "ecx, dword ptr [rdx + 0xc]"),
            0x353E4: ("mov", "eax, dword ptr [rdx + 8]"), 0x353E7: ("add", "eax, ecx"),
            0x353E9: ("cmp", "r8, rax"), 0x353EC: ("jb", "0x353f6"), 0x353EE: ("add", "rdx, 0x28"),
            0x353FF: ("cmp", "dword ptr [rdx + 0x24], 0"), 0x35403: ("jge", "0x35409"),
            0x35411: ("xor", "al, al")}
    for site, expected in flow.items():
        instruction = body[site]
        require((instruction.mnemonic, instruction.op_str) == expected, f"Original instruction differs at {site:#x}")

    imports = {imp.address - pe.OPTIONAL_HEADER.ImageBase: (dll.dll.decode(), imp.name.decode())
               for dll in pe.DIRECTORY_ENTRY_IMPORT for imp in dll.imports if imp.name}
    thunks = {0x36310: (0x3A770, "api-ms-win-crt-runtime-l1-1-0.dll", "_initialize_onexit_table"),
              0x362E0: (0x3A630, "VCRUNTIME140.dll", "__C_specific_handler")}
    for site, (slot, dll, name) in thunks.items():
        thunk, = decoder.disasm(image[site:site + 6], site)
        require((thunk.mnemonic, rip(thunk), imports[slot]) == ("jmp", slot, (dll, name)),
                f"External thunk differs at {site:#x}")
    crt_flag = next(decoder.disasm(image[0x35E82:0x35E88], 0x35E82))
    require(rip(crt_flag) == 0x528B0, "CRT flag helper differs")
    require(image[0x42AB0:0x42AC0] == b"\xff" * 16 and image[0x541E1] == 0,
            "On-exit table source or initialization flag differs")
    for rva in (0x541E1, 0x541E8, 0x541F8, 0x54200, 0x54210):
        require(pe.get_section_by_rva(rva).Name.rstrip(b"\0") == b".data", f"Writable data has moved at {rva:#x}")
    filter_body = list(decoder.disasm(image[0x3959E:0x395B5], 0x3959E))
    require([(i.mnemonic, i.op_str) for i in filter_body[2:7]] ==
            [("mov", "rax, qword ptr [rcx]"), ("xor", "ecx, ecx"), ("cmp", "dword ptr [rax], 0xc0000005"),
             ("sete", "cl"), ("mov", "eax, ecx")], "SEH exception filter differs")
    require((pe.DOS_HEADER.e_magic, pe.NT_HEADERS.Signature, pe.OPTIONAL_HEADER.Magic) ==
            (0x5A4D, 0x4550, 0x20B), "Pinned original PE headers differ")

    if listing:
        lines = [f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() for i in body.values()]
        listing.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")
    next_entry = entries[0x359C4]
    require((next_entry.EndAddress, next_entry.UnwindData) == (0x35ADA, 0x48FA4), "Follow-up entry differs")
    return {
        "instructions_in_function_ranges": sum(i != 0x3537F for i in body),
        "alignment_padding": "0x3537f: cc",
        "original_data_references": {hex(site): hex(target) for site, target in references.items()},
        "onexit": {
            "initialization_flag": "0x541e1", "ucrt_helper": "0x35e80 -> dword 0x528b0",
            "call_sites": ["0x3531e", "0x3532e"], "thunk": "0x36310", "iat": "0x3a770",
            "table_bases": ["0x541e8", "0x54200"], "non_ucrt_sentinel": "three qwords of -1 per table",
            "validation": "Uninitialized with unsigned mode > 1: call RVA 0x35e94 with 5, then INT3 at 0x3537e.",
            "return": "AL = 1 on prior initialization or successful setup, AL = 0 on initializer failure.",
        },
        "image_query": {
            "input": "VA in RCX, subtract image base into R8",
            "headers": "DOS signature 0x5a4d; e_lfanew at +0x3c; NT signature 0x4550; PE32+ magic 0x20b",
            "section_table": "NT headers + 0x18 + SizeOfOptionalHeader; NumberOfSections records of size 0x28.",
            "matching_range": "[VirtualAddress, uint32(VirtualAddress + VirtualSize))",
            "return": "AL = 1 for a matching section with IMAGE_SCN_MEM_WRITE clear. AL = 0 otherwise.",
            "exception": "0x362e0 -> IAT 0x3a630 VCRUNTIME140.dll!__C_specific_handler; 0x3959e handles 0xc0000005.",
        },
        "follow_up": {"range": ["0x359c4", "0x35ada"], "unwind_rva": "0x48fa4",
                      "sha256": sha256(image[0x359C4:0x35ADA]).hexdigest()},
    }


def replay(original, compiler, listing):
    raw = original.read_bytes()
    require(sha256(raw).hexdigest() == ORIGINAL, "Original SHA-256 differs")
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    require(sha256(image[START:END]).hexdigest() == SPAN, "Scope SHA-256 differs")
    tools = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "crt.obj"
        tools["compile_bodies"](HERE / "crt-init-image.c", compiler, obj)
        compiled = obj.read_bytes()
    entries = {e.struct.BeginAddress: e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    code = compare_code(tools["compare"], compiled, image)
    unwind, scope = compare_unwind(tools["inspect_unwind_sections"](compiled), entries, raw, image)
    return {"original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
            "reassembly": code, "unwind": unwind, "seh_scope": scope,
            **inspect_original(pe, image, entries, listing)}


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
