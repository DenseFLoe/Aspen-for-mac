"""Verify the four s21 callback sites and the two exception records in the pinned PE."""
import argparse
import csv
from hashlib import sha256
import json
from pathlib import Path
import struct

import capstone as cs
import pefile


EXPECTED = "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011"
ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    args = parser.parse_args()
    data = args.original.read_bytes()
    assert sha256(data).hexdigest() == EXPECTED
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    functions = {entry.struct.BeginAddress: entry
                 for entry in pe.DIRECTORY_ENTRY_EXCEPTION}
    relocations = [(entry.rva, entry.type) for block in pe.DIRECTORY_ENTRY_BASERELOC
                   for entry in block.entries if entry.type]

    def instruction(rva):
        return next(decoder.disasm(image[rva:rva+15], rva, count=1))

    def instruction_row(insn):
        return {"rva":hex(insn.address), "bytes":insn.bytes.hex(),
                "mnemonic":insn.mnemonic, "operands":insn.op_str}

    def instruction_window(start, end):
        insns = list(decoder.disasm(image[start:end],start))
        assert sum(insn.size for insn in insns) == end - start
        return [instruction_row(insn) for insn in insns]

    def rip_target(insn, op):
        return insn.address + insn.size + op.mem.disp

    def checked(rva, mnemonic, operands=None):
        insn = instruction(rva)
        assert insn.mnemonic == mnemonic
        if operands is not None:
            assert insn.op_str == operands
        return insn

    def slot(rva):
        section = pe.get_section_by_rva(rva)
        within_raw = rva + 8 <= section.VirtualAddress + section.SizeOfRawData
        touching_relocations = [
            [hex(site), kind] for site, kind in relocations
            if site < rva + 8 and rva < site + (8 if kind == 10 else 4)
        ]
        return {"rva":hex(rva), "name":section.Name.rstrip(b"\0").decode("ascii"),
                "section_rva":hex(section.VirtualAddress),
                "characteristics":hex(section.Characteristics),
                "virtual_size":hex(section.Misc_VirtualSize),
                "raw_size":hex(section.SizeOfRawData),
                "writable":bool(section.Characteristics & 0x80000000),
                "file_backed":within_raw, "initial_qword":hex(struct.unpack_from("<Q",image,rva)[0]),
                "overlapping_base_relocations":touching_relocations}

    dispatch = slot(0x26268)
    runtime_callback = slot(0x372b8)
    dll_callback = slot(0x29e80)
    assert pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer == base + 0x26268
    assert int(dispatch["initial_qword"], 0) == base + 0x25560
    assert dispatch["overlapping_base_relocations"] == [["0x26268", 10]]
    checked(0x25560, "jmp", "rax")
    assert runtime_callback["name"] == ".data" and runtime_callback["writable"]
    assert not runtime_callback["file_backed"] and runtime_callback["initial_qword"] == "0x0"
    assert dll_callback["name"] == ".rdata" and not dll_callback["writable"]
    assert dll_callback["file_backed"] and dll_callback["initial_qword"] == "0x0"
    assert not runtime_callback["overlapping_base_relocations"]
    assert not dll_callback["overlapping_base_relocations"]

    checked(0x2445f, "call", "0x24c98")
    lea = checked(0x24c98, "lea")
    assert lea.operands[0].reg == cs.x86.X86_REG_RAX
    assert rip_target(lea, lea.operands[1]) == 0x372b8
    checked(0x24c9f, "ret", "")
    checked(0x24464, "mov", "rbx, rax")
    checked(0x24467, "cmp", "qword ptr [rax], 0")
    checked(0x2446b, "je", "0x24491")
    checked(0x2446d, "mov", "rcx, rax")
    checked(0x24470, "call", "0x24b3c")
    checked(0x24475, "test", "al, al")
    checked(0x24477, "je", "0x24491")
    checked(0x24484, "mov", "rax, qword ptr [rbx]")
    load = checked(0x24487, "mov")
    assert load.operands[0].reg == cs.x86.X86_REG_R9
    assert rip_target(load, load.operands[1]) == 0x26268
    checked(0x2448e, "call", "r9")

    checked(0x24b40, "mov", "r8, rcx")
    checked(0x24b75, "sub", "r8, rdx")
    checked(0x24b98, "mov", "ecx, dword ptr [rdx + 0xc]")
    checked(0x24b9e, "jb", "0x24baa")
    checked(0x24ba0, "mov", "eax, dword ptr [rdx + 8]")
    checked(0x24ba8, "jb", "0x24bb2")
    checked(0x24bbb, "cmp", "dword ptr [rdx + 0x24], 0")
    checked(0x24bbf, "jge", "0x24bc5")
    checked(0x24bc1, "xor", "al, al")
    checked(0x24bc3, "jmp", "0x24bcf")
    checked(0x24bc5, "mov", "al, 1")
    checked(0x24bd3, "ret", "")
    signed = struct.unpack("<i", struct.pack("<I", int(runtime_callback["characteristics"], 0)))[0]
    assert signed < 0

    execution = [{
        "site":"0x2448e", "bytes":instruction(0x2448e).bytes.hex(),
        "guard_register":"r9", "guard_definition":"0x24487", "guard_slot":"0x26268",
        "rax_definition":"0x24484", "rax_memory":"0x372b8",
        "entry_path_bypass":"0x2446b if slot is zero; 0x24477 if helper AL is zero",
        "original_section_header_gate":"0x24b3c receives the slot address. The original section "
          "has Characteristics 0xc0000040. Signed comparison at 0x24bbb falls through 0x24bbf, "
          "AL clears at 0x24bc1, and 0x24477 bypasses the call even if the slot becomes nonzero.",
        "trace":instruction_window(0x2445f,0x24491),
        "recheck":"If the in-process section headers differ, confirm slot producer, guard slot "
                  "contents, and callback value reached by the two-hop edge."
    }]
    for start, test, branch, bypass, site in (
        (0x24585,0x2458c,0x2458f,0x24591,0x2459b),
        (0x245fe,0x24605,0x24608,0x24618,0x24612),
        (0x24638,0x2463f,0x24642,0x24644,0x24655),
    ):
        load = checked(start, "mov")
        assert load.operands[0].reg == cs.x86.X86_REG_RAX
        assert rip_target(load, load.operands[1]) == 0x29e80
        checked(test, "test", "rax, rax")
        if branch == 0x24608:
            checked(branch, "je", hex(bypass))
        else:
            taken = int(checked(branch, "jne").op_str, 0)
            assert taken in (0x2459b, 0x2464d)
        transfer = checked(site, "call")
        assert rip_target(transfer,transfer.operands[0]) == 0x26268
        execution.append({
            "site":hex(site), "bytes":transfer.bytes.hex(), "guard_slot":"0x26268",
            "rax_definition":hex(start), "rax_memory":"0x29e80", "null_test":hex(test),
            "null_branch":hex(branch), "initial_zero_successor":hex(bypass),
            "trace":instruction_window(start,site+transfer.size),
            "recheck":"Identify a verified nonzero producer or capture runtime slot, relocation "
                      "and protection state before binding a callback value."
        })

    known_refs = {}
    with (ROOT / "body-ranges.csv").open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream):
            start, last = int(row["start"], 0), int(row["inclusive_end"], 0)
            for insn in decoder.disasm(image[start:last+1], start):
                for op in insn.operands:
                    if op.type != cs.x86.X86_OP_MEM or op.mem.base != cs.x86.X86_REG_RIP:
                        continue
                    target = rip_target(insn, op)
                    if any(target < item + 8 and item < target + op.size
                           for item in (0x29e80, 0x372b8)):
                        known_refs[(insn.address,target)] = {
                            **instruction_row(insn), "target":hex(target),
                            "operand_access":op.access, "address_only":insn.mnemonic == "lea"}
    assert set(known_refs) == {(0x24585,0x29e80), (0x245fe,0x29e80), (0x24638,0x29e80),
                               (0x24801,0x29e80), (0x24c98,0x372b8)}
    assert all(not row["operand_access"] & cs.CS_AC_WRITE for row in known_refs.values())

    handlers = []
    for start, end, flag, expected_scopes in (
        (0x243ac,0x244c2,2,((0x243e4,0x24453,0x25586,0),(0x244b6,0x244c1,0x25586,0))),
        (0x24548,0x24679,1,((0x2457d,0x24663,0x255ca,0x24663),)),
    ):
        entry = functions[start]
        info = entry.unwindinfo
        assert entry.struct.EndAddress == end and info.Flags == flag
        assert info.ExceptionHandler == 0x253cc
        start_info = entry.struct.UnwindData
        scope_table = start_info + 4 + 2 * ((info.CountOfCodes + 1) & ~1) + 4
        num_scopes = struct.unpack_from("<I",image,scope_table)[0]
        regions = tuple(struct.unpack_from("<4I",image,scope_table+4+16*i)
                        for i in range(num_scopes))
        assert regions == expected_scopes, (hex(start),regions)
        handlers.append({"start":hex(start),"end_exclusive":hex(end),"unwind_rva":hex(start_info),
                         "flags":flag,"handler":hex(info.ExceptionHandler),
                         "scope_records":[list(map(hex,region)) for region in regions]})
    print(json.dumps({"original_sha256":EXPECTED, "guard_dispatch":dispatch,
          "guard_initial_stub":{"rva":"0x25560","bytes":"ffe0","instruction":"jmp rax"},
          "callback_slots":[runtime_callback,dll_callback],
          "static_scan":{"source":"recorded original instruction ranges (body-ranges.csv)",
            "references":[row for _,row in sorted(known_refs.items())],
            "finding":"No RIP-relative write overlapping the slots was found in these ranges. "
                      "Alias, external and runtime writes are not excluded."},
          "runtime_slot_section_helper":{
              "address_lookup":instruction_window(0x24b3c,0x24bb2),
              "flags_check":instruction_window(0x24bb2,0x24bd4)},
          "sites":execution,"unwind":handlers},indent=2))


if __name__ == "__main__":
    main()
