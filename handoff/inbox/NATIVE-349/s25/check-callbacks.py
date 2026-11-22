"""Check original Ikc2Bkp exception callback and references to its writable slot."""

import argparse
import csv
import hashlib
import json
import struct
from pathlib import Path

import capstone
from capstone import x86
import pefile


ORIGINAL_SHA256 = "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011"
FILTER = 0x255CA
DISPATCH = 0x249C0
CALLBACK = 0x2435C
GUARD_SLOT = 0x26268
CALLBACK_SLOT = 0x34980
RANGES = ((0x2435C, 0x243AC), (0x249C0, 0x24A20), (0x25024, 0x2505B),
          (0x2505C, 0x25077), (0x2516C, 0x251BC), (0x253A8, 0x253B4),
          (0x255CA, 0x255FF))


def checked_instruction(instructions, site, mnemonic, operands=None):
    instruction = instructions[site]
    assert instruction.mnemonic == mnemonic, hex(site)
    if operands is not None:
        assert instruction.op_str == operands, hex(site)
    return instruction


def rip_target(instruction, operand):
    assert operand.type == x86.X86_OP_MEM and operand.mem.base == x86.X86_REG_RIP
    return instruction.address + instruction.size + operand.mem.disp


def instruction_row(instruction):
    return {
        "rva": hex(instruction.address),
        "bytes": instruction.bytes.hex(),
        "mnemonic": instruction.mnemonic,
        "operands": instruction.op_str,
    }


def scan_recorded_ranges(decoder, image, ranges):
    observed = {}
    section_bytes = set()
    with ranges.open(encoding="utf-8-sig", newline="") as handle:
        for row in csv.DictReader(handle):
            start, last = int(row["start"], 0), int(row["inclusive_end"], 0)
            for item in decoder.disasm(image[start:last + 1], start):
                observed[item.address] = item
                section_bytes.update(range(item.address, item.address + item.size))
    return observed, len(section_bytes)


def check(original, ranges):
    raw = original.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == ORIGINAL_SHA256
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    image_base = pe.OPTIONAL_HEADER.ImageBase
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    observed, decoded_bytes = scan_recorded_ranges(decoder, image, ranges)

    local = {}
    for start, end in RANGES:
        items = list(decoder.disasm(image[start:end], start))
        assert sum(item.size for item in items) == end - start
        local.update((item.address, item) for item in items)

    def op(site, mnemonic, operands=None):
        return checked_instruction(local, site, mnemonic, operands)

    lea = op(0x255E1, "lea")
    assert lea.operands[0].reg == x86.X86_REG_R9 and rip_target(lea, lea.operands[1]) == CALLBACK
    for site in (0x255E8, 0x255EC, 0x255EF):
        assert x86.X86_REG_R9 not in op(site, "mov").regs_access()[1]
    op(0x255F3, "call", "0x249c0")
    op(0x249D4, "mov", "rdi, r9")
    op(0x249DF, "call", "0x253a8")
    op(0x249E4, "test", "eax, eax")
    op(0x249E6, "jne", "0x249fe")
    op(0x249E8, "cmp", "ebx, 1")
    op(0x249EB, "jne", "0x249fe")
    op(0x249F5, "mov", "rax, rdi")
    assert all(x86.X86_REG_RDI not in i.regs_access()[1] for i in local.values()
               if 0x249D4 < i.address < 0x249F5 or 0x253A8 <= i.address < 0x253B4)
    guard = op(0x249F8, "call")
    assert rip_target(guard, guard.operands[0]) == GUARD_SLOT
    assert pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer == image_base + GUARD_SLOT
    assert struct.unpack_from("<Q", image, GUARD_SLOT)[0] - image_base == 0x25560
    assert bytes(image[0x25560:0x25562]) == b"\xff\xe0"

    fixed_relocations = [(e.rva, e.type) for block in pe.DIRECTORY_ENTRY_BASERELOC
                         for e in block.entries if e.type]
    assert (GUARD_SLOT, 10) in fixed_relocations
    guard_flag = op(0x253AA, "cmp")
    flag_rva = rip_target(guard_flag, guard_flag.operands[0])
    assert flag_rva == 0x321A0
    op(0x253B0, "setne", "al")
    op(0x253B3, "ret", "")
    entry = next(row for row in pe.DIRECTORY_ENTRY_EXCEPTION if row.struct.BeginAddress == 0x24548)
    unwind = entry.unwindinfo
    scope_rva = entry.struct.UnwindData + 8 + 2 * ((unwind.CountOfCodes + 1) & ~1)
    assert struct.unpack_from("<5I", image, scope_rva) == (1, 0x2457D, 0x24663, FILTER, 0x24663)

    references = []
    flag_references = []
    direct_edges = []
    for item in sorted(observed.values(), key=lambda insn: insn.address):
        for operand in item.operands:
            if item.group(capstone.CS_GRP_BRANCH_RELATIVE) and operand.type == x86.X86_OP_IMM:
                if operand.imm == DISPATCH:
                    direct_edges.append({**instruction_row(item), "target": hex(operand.imm)})
            if operand.type != x86.X86_OP_MEM or operand.mem.base != x86.X86_REG_RIP:
                continue
            target = rip_target(item, operand)
            if target < CALLBACK_SLOT + 8 and CALLBACK_SLOT < target + max(operand.size, 1):
                references.append({**instruction_row(item), "target": hex(target), "size": operand.size,
                                   "access": operand.access, "address_only": item.mnemonic == "lea"})
            if target < flag_rva + 4 and flag_rva < target + max(operand.size, 1):
                flag_references.append({**instruction_row(item), "target": hex(target),
                                        "access": operand.access, "address_only": item.mnemonic == "lea"})
            if item.mnemonic == "lea" and target == DISPATCH:
                direct_edges.append({**instruction_row(item), "target": hex(target)})

    assert [ref["rva"] for ref in flag_references] == ["0x253aa"], flag_references
    assert flag_references[0]["access"] == capstone.CS_AC_READ
    flag_start = pe.get_section_by_rva(flag_rva)
    assert flag_start.Name.rstrip(b"\x00") == b".data" and flag_start.Characteristics & 0x80000000
    assert flag_rva + 4 <= flag_start.VirtualAddress + flag_start.SizeOfRawData
    assert struct.unpack_from("<I", image, flag_rva)[0] == 1

    assert [edge["rva"] for edge in direct_edges] == ["0x255f3"], direct_edges
    assert [ref["rva"] for ref in references] == ["0x25044", "0x25060", "0x251a5"], references
    assert all(ref["access"] == capstone.CS_AC_READ and not ref["address_only"] for ref in references)
    slot = pe.get_section_by_rva(CALLBACK_SLOT)
    assert slot.Name.rstrip(b"\x00") == b".data" and slot.Characteristics & 0x80000000
    assert slot.VirtualAddress + slot.SizeOfRawData <= CALLBACK_SLOT
    assert CALLBACK_SLOT + 8 <= slot.VirtualAddress + slot.Misc_VirtualSize
    assert struct.unpack_from("<Q", image, CALLBACK_SLOT)[0] == 0
    assert all(not (site < CALLBACK_SLOT + 8 and site + (8 if kind == 10 else 4) > CALLBACK_SLOT)
               for site, kind in fixed_relocations)
    pointers = {}
    for target in (DISPATCH, CALLBACK_SLOT):
        sites = [hex(site) for site, kind in fixed_relocations if kind == 10
                 and struct.unpack_from("<Q", image, site)[0] == image_base + target]
        assert not sites, (hex(target), sites)
        pointers[hex(target)] = sites

    text = pe.get_section_by_rva(DISPATCH)
    start = text.VirtualAddress
    end = start + text.Misc_VirtualSize
    rel32 = [hex(site) for site in range(start, end-4)
             if image[site] in (0xE8, 0xE9)
             and site + 5 + struct.unpack_from("<i", image, site + 1)[0] == DISPATCH]
    assert rel32 == ["0x255f3"], rel32

    checks = []
    for load, test, gate, edge, bypass in (
        (0x25044, 0x2504B, 0x2504E, 0x25050, 0x25056),
        (0x25060, 0x25067, 0x2506A, 0x2506C, 0x25072),
        (0x251A5, 0x251AC, 0x251AF, 0x251B1, 0x251B7),
    ):
        load_insn = op(load, "mov")
        assert load_insn.operands[0].reg == x86.X86_REG_RAX
        assert rip_target(load_insn, load_insn.operands[1]) == CALLBACK_SLOT
        op(test, "test", "rax, rax")
        op(gate, "je", hex(bypass))
        call = op(edge, "call")
        assert rip_target(call, call.operands[0]) == GUARD_SLOT
        checks.append({"read_rva": hex(load), "guard_call_rva": hex(edge),
                       "initial_zero_bypass": hex(bypass), "nonnull_target": "unresolved"})

    return {
        "original_sha256": ORIGINAL_SHA256,
        "ranges_sha256": hashlib.sha256(ranges.read_bytes()).hexdigest(),
        "recorded_scan": {"instructions": len(observed), "decoded_bytes": decoded_bytes},
        "rel32_scan": {"start": hex(start), "end_exclusive": hex(end), "edges_to_0x249c0": rel32},
        "dir64_pointer_locations": pointers,
        "filter_route": {"scope_rva": hex(scope_rva), "scope_host": "0x24548", "filter": hex(FILTER),
                         "observed_entries": direct_edges, "guard_call": "0x249f8",
                         "guard_slot": hex(GUARD_SLOT), "initial_dispatch_stub": "0x25560",
                         "caller_target": hex(CALLBACK), "guard_flag_rva": hex(flag_rva),
                         "guard_flag_initial_dword": struct.unpack_from("<I", image, flag_rva)[0],
                         "guard_flag_observed_references": flag_references,
                         "condition": "helper returns zero and incoming EDX equals one",
                         "original_initial_state": "flag is one; the branch at 0x249e6 bypasses the call"},
        "writable_slot": {"rva": hex(CALLBACK_SLOT), "section": ".data",
                          "raw_end_exclusive": hex(slot.VirtualAddress + slot.SizeOfRawData),
                          "initial_qword": "0x0", "overlapping_baseref_count": 0,
                          "observed_references": references, "guards": checks,
                          "producer": "unresolved beyond RIP-relative references and DIR64 pointers"},
        "verified_windows": [{"start": hex(start), "end_exclusive": hex(end),
                              "sha256": hashlib.sha256(image[start:end]).hexdigest(),
                              "instructions": [instruction_row(item) for address, item in local.items()
                                               if start <= address < end]}
                             for start, end in RANGES],
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("--ranges", type=Path, default=Path(__file__).resolve().parents[1] / "body-ranges.csv")
    arguments = parser.parse_args()
    print(json.dumps(check(arguments.original, arguments.ranges), ensure_ascii=True, indent=2))
