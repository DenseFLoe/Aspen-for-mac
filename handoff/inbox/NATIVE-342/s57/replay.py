"""Compare the CRT exception filter's COFF reconstruction and original callback bindings."""

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
START, END, UNWIND = 0x35204, 0x35264, 0x44E7C
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
SPAN = "aac1533de9bf8cdb8662108ffcce0dd34d55507db2a5364cfc5e02b6d53f7762"
FIXUPS = [(0x35224, 0x35E80), (0x3523E, 0x3AC20), (0x35260, 0x362FE)]
NEXT_RANGE = [(0x352F4, 0x3537F, 0x44660), (0x35380, 0x35418, 0x48F28)]


def require(condition, message):
    if not condition:
        raise ValueError(message)


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
    require((size, relocation_count) == (END - START, len(FIXUPS)),
            f"Unexpected COFF layout: {size} bytes, {relocation_count} relocations")
    match = compare(obj, image, {START: size}).get(START)
    if match:
        require(match["relocations"] == [[hex(at), hex(to), 4] for at, to in FIXUPS],
                "Reassembled scope has a COFF relocation mismatch")
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


def compare_unwind(sections, entry, original, image):
    require((entry.EndAddress, entry.UnwindData) == (END, UNWIND), "Original unwind bounds differ")
    pdata, fixups = sections[".pdata"]
    require(fixups == [(0, ".text"), (4, ".text"), (8, ".xdata")], "Unexpected .pdata relocations")
    for offset, base in ((0, START), (4, START), (8, UNWIND)):
        addend, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, addend + base)
    file_offset = entry.get_file_offset()
    require(len(pdata) == 12 and pdata == original[file_offset:file_offset + 12], "Original .pdata differs")
    xdata, fixups = sections[".xdata"]
    require(not fixups and len(xdata) == 20 and xdata == image[UNWIND:UNWIND + 20], "Original .xdata differs")
    require(xdata.hex() == "0114080014640800145407001434060014321070", "Unwind fields differ")
    return {
        "pdata_file_offset": hex(file_offset), "pdata_bytes": pdata.hex(), "xdata_rva": hex(UNWIND),
        "xdata_bytes": xdata.hex(), "prologue_bytes": 20, "stack_allocation": 0x20,
        "push": "RDI", "saved_register_offsets_after_prologue": {"RBX": 0x30, "RBP": 0x38, "RSI": 0x40},
    }


def inspect_original(pe, image, entries, listing):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = {i.address: i for i in decoder.disasm(image[START:END], START)}
    require(sum(i.size for i in body.values()) == END - START, "Original code was not fully decoded")
    flow = {
        0x35218: ("mov", "rdi, r9"), 0x3521B: ("mov", "rsi, r8"),
        0x3521E: ("mov", "ebx, edx"), 0x35220: ("mov", "rbp, rcx"),
        0x35223: ("call", "0x35e80"), 0x35228: ("test", "eax, eax"),
        0x3522A: ("jne", "0x35242"), 0x3522C: ("cmp", "ebx, 1"),
        0x3522F: ("jne", "0x35242"), 0x35231: ("mov", "r8, rsi"),
        0x35234: ("xor", "edx, edx"), 0x35236: ("mov", "rcx, rbp"),
        0x35239: ("mov", "rax, rdi"), 0x3523C: ("call", "qword ptr [rip + 0x59de]"),
        0x35242: ("mov", "rdx, qword ptr [rsp + 0x58]"),
        0x35247: ("mov", "ecx, dword ptr [rsp + 0x50]"), 0x3525F: ("jmp", "0x362fe"),
    }
    for address, expected in flow.items():
        require((body[address].mnemonic, body[address].op_str) == expected, f"Original flow differs at {address:#x}")

    test_helper = list(decoder.disasm(image[0x35E80:0x35E8C], 0x35E80))
    require([(i.mnemonic, i.op_str) for i in test_helper] == [
        ("xor", "eax, eax"), ("cmp", "dword ptr [rip + 0x1ca28], eax"),
        ("setne", "al"), ("ret", ""),
    ], "UCRT flag reader differs")
    flag = rip_target(test_helper[1])
    require(flag == 0x528B0 and pe.get_section_by_rva(flag).Name.rstrip(b"\0") == b".data", "UCRT flag storage differs")

    base = pe.OPTIONAL_HEADER.ImageBase
    config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    slot = rip_target(body[0x3523C])
    require(slot == 0x3AC20 and base + slot == config.GuardCFDispatchFunctionPointer, "GuardCF slot differs")
    field = pe.get_rva_from_offset(config.get_field_absolute_offset("GuardCFDispatchFunctionPointer"))
    dir64 = {e.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for e in block.entries if e.type == 10}
    require({field, slot} <= dir64, "GuardCF field or slot lacks DIR64")
    dispatcher = struct.unpack_from("<Q", image, slot)[0] - base
    require(dispatcher == 0x36AE0 and image[dispatcher:dispatcher + 2] == b"\xff\xe0", "Disk dispatcher differs")

    caller = entries[0x395FA]
    require(caller.EndAddress == 0x39630, "Caller original .pdata range differs")
    caller_body = {i.address: i for i in decoder.disasm(image[caller.BeginAddress:caller.EndAddress], caller.BeginAddress)}
    lea = caller_body[0x39611]
    target = rip_target(lea)
    site = caller_body[0x39623]
    require((lea.mnemonic, lea.reg_name(lea.operands[0].reg), target) == ("lea", "r9", 0x35974)
            and (site.mnemonic, site.op_str) == ("call", "0x35204") and target in entries,
            "Original R9 callback producer differs")
    require(all("r9" not in [i.reg_name(r) for r in i.regs_access()[1]]
                for address, i in caller_body.items() if lea.address < address < site.address),
            "Original caller overwrites R9 before the call")

    thunk, = decoder.disasm(image[0x362FE:0x36304], 0x362FE)
    iat = rip_target(thunk)
    imports = {i.address - base: (dll.dll, i.name) for dll in pe.DIRECTORY_ENTRY_IMPORT for i in dll.imports}
    dll = b"api-ms-win-crt-runtime-l1-1-0.dll"
    require((thunk.mnemonic, iat, imports[iat]) == ("jmp", 0x3A778, (dll, b"_seh_filter_dll")), "CRT filter import differs")
    if listing:
        listing.write_text("".join(
            f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
            for i in body.values()), encoding="utf-8", newline="\n")
    return {
        "instructions": len(body),
        "ucrt_flag": {"helper": "0x35e80", "dword_rva": hex(flag), "disk_bytes": image[flag:flag + 4].hex(),
                      "condition": "EAX = ([flag] != 0); call callback only when EAX is zero and original EDX is 1"},
        "callback": {"site": "0x3523c", "register_chain": "entry R9 -> RDI -> RAX",
                     "arguments": ["entry RCX", 0, "entry R8"],
                     "known_original_caller": {"site": hex(site.address), "producer": hex(lea.address), "r9_rva": hex(target)},
                     "load_config_dir64_rva": hex(field), "slot_dir64_rva": hex(slot),
                     "disk_dispatcher": f"{dispatcher:#x}: jmp rax",
                     "limit": "The fixed callback is bound for the documented caller; other incoming and live dispatch paths remain outside this scope."},
        "tail_filter": {"site": "0x3525f", "thunk": "0x362fe", "iat": hex(iat),
                        "import": dll.decode() + "!_seh_filter_dll",
                        "arguments": ["low dword of original fifth argument", "original sixth argument"]},
    }


def next_scope(image, entries):
    verified = []
    for begin, end, unwind in NEXT_RANGE:
        entry = entries[begin]
        require((entry.EndAddress, entry.UnwindData) == (end, unwind), "Follow-up .pdata bounds differ")
        verified.append({"range": [hex(begin), hex(end)], "unwind_rva": hex(unwind),
                         "sha256": sha256(image[begin:end]).hexdigest()})
    require(image[0x3537F] == 0xCC, "Follow-up alignment padding differs")
    return {"range": ["0x352f4", "0x35418"], "ranges": verified, "padding": "0x3537f: int3",
            "sha256": sha256(image[0x352F4:0x35418]).hexdigest()}


def replay(original, zig, listing):
    original_bytes = original.read_bytes()
    require(sha256(original_bytes).hexdigest() == ORIGINAL, "Original SHA-256 differs")
    pe = pefile.PE(data=original_bytes)
    image = pe.get_memory_mapped_image()
    require(sha256(image[START:END]).hexdigest() == SPAN, "Scope SHA-256 differs")
    tools = run_path(str(HERE.parent / "s37/check-com-error-copy.py"))
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "filter.obj"
        tools["compile_bodies"](HERE / "dll-exception-filter.c", zig, obj)
        compiled = obj.read_bytes()
    entries = {e.struct.BeginAddress: e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    return {
        "original_sha256": ORIGINAL, "range_sha256": SPAN, "range": [hex(START), hex(END)],
        "reassembly": compare_code(tools["compare"], compiled, image),
        "unwind": compare_unwind(tools["inspect_unwind_sections"](compiled), entries[START], original_bytes, image),
        **inspect_original(pe, image, entries, listing),
        "follow_up": next_scope(image, entries),
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
