"""Verify ppexec.dll callback sources and the original PE section gate."""

import argparse
import json
import runpy
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP


SELECTORS = {0x91A4: 0x8EA0, 0xA6E4: 0xA6C0, 0xE215: 0xE040, 0xF135: 0xF100, 0x12C93: 0x12C70}
COPY_LENGTHS = {0x142E: 0x1422, 0x4EF9: 0x4EED, 0x4FA6: 0x4F9A, 0x6FEE: 0x6FE5,
                0x700A: 0x7001, 0x7135: 0x712A, 0x71CC: 0x71BD, 0x733A: 0x7334,
                0x7E5A: 0x7E57, 0x7E70: 0x7E6D, 0x7E86: 0x7E83, 0x8013: 0x7FFF,
                0x8A65: 0x8A5C, 0x8A86: 0x8A7A}
FILL_LENGTHS = {0x31D7: 0x31CC, 0x3E95: 0x3E8A, 0x565E: 0x5658, 0x73D6: 0x73CE,
                0x79FA: 0x79E5}


def inspect(original, unit, trace_script):
    trace_module = runpy.run_path(str(trace_script))
    trace = trace_module["trace"](original, unit)
    pe = pefile.PE(data=original.read_bytes())
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    instructions, _ = trace_module["scan"](image, unit)
    describe = trace_module["describe"]
    load_config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct

    def target(site):
        insn = instructions[site]
        operand = insn.operands[0]
        assert operand.type == X86_OP_IMM
        return operand.imm

    def rip(site):
        insn = instructions[site]
        return next(insn.address + insn.size + op.mem.disp for op in insn.operands
                    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)

    def text(site):
        return describe(instructions[site])["instruction"]

    def length_producers(wrapper, lengths):
        callers = {i.address for i in instructions.values() if i.group(cs.CS_GRP_CALL)
                   and i.operands[0].type == X86_OP_IMM and i.operands[0].imm == wrapper}
        assert callers == set(lengths)
        destinations = {"r8", "r8d"}
        return [dict(call=describe(instructions[site]), length=describe(instructions[producer]))
                for site, producer in lengths.items()
                if instructions[producer].op_str.split(",", 1)[0] in destinations]

    def section_result(rva):
        section = next(s for s in pe.sections if
                       s.VirtualAddress <= rva < s.VirtualAddress + s.Misc_VirtualSize)
        return dict(section=section.Name.rstrip(b"\0").decode(), start=hex(section.VirtualAddress),
                    end_exclusive=hex(section.VirtualAddress + section.Misc_VirtualSize),
                    characteristics=hex(section.Characteristics),
                    raw_backed=rva+8 <= section.VirtualAddress + section.SizeOfRawData,
                    accepted_by_122f4=not bool(section.Characteristics & 0x80000000))

    assert target(0x11C27) == 0x12450 and rip(0x12450) == 0x22148
    assert text(0x11C2C) == "mov rbx, rax" and text(0x11C35) == "mov rcx, rax"
    assert target(0x11C38) == 0x122F4
    expected = {
        0x122F8: "mov r8, rcx", 0x1232D: "sub r8, rdx",
        0x12350: "mov ecx, dword ptr [rdx + 0xc]", 0x12358: "mov eax, dword ptr [rdx + 8]",
        0x12373: "cmp dword ptr [rdx + 0x24], 0", 0x12379: "xor al, al",
        0x1237D: "mov al, 1", 0x11C3D: "test al, al",
        0x11C4C: "mov rax, qword ptr [rbx]", 0x11C56: "call r9",
    }
    assert all(text(site) == expected_text for site, expected_text in expected.items())
    assert target(0x12377) == 0x1237D and instructions[0x12377].mnemonic == "jge"
    assert target(0x11C3F) == 0x11C59 and instructions[0x11C3F].mnemonic == "je"
    assert rip(0x11C4F) == 0x15D00
    slot = section_result(0x22148)
    readonly = section_result(0x15D18)
    assert not slot["accepted_by_122f4"] and readonly["accepted_by_122f4"]
    assert not slot["raw_backed"] and not section_result(0x20A80)["raw_backed"]

    tracked = {*SELECTORS.values(), 0x12188, 0x12450, 0x1283C, 0x20A80, 0x22148,
               0x14C40, 0x14C60, 0x15D00, 0x15D08, 0x15D10, 0x15D18, 0x15D20, 0x1479A}
    raw_rel32 = {}
    raw_text_size = 0
    for section in pe.sections:
        if section.Characteristics & 0x20000000:
            start = section.VirtualAddress
            end = start + min(section.Misc_VirtualSize, section.SizeOfRawData)
            raw_text_size += end - start
            for site in range(start, end - 4):
                if image[site] in (0xE8, 0xE9):
                    dest = site + 5 + int.from_bytes(image[site+1:site+5], "little", signed=True)
                    if dest in tracked:
                        raw_rel32[site] = dest
    assert raw_rel32 == {0x11C27: 0x12450, 0x14E06: 0x12188}
    dir64 = {entry.rva: int.from_bytes(image[entry.rva:entry.rva+8], "little") - base
             for block in pe.DIRECTORY_ENTRY_BASERELOC for entry in block.entries if entry.type == 10}
    entry_refs = {a: sorted(i.address for i in instructions.values()
                           if a in set(trace_module["instruction_references"](i))) for a in tracked}
    exports = {e.address: e.name.decode() if e.name else str(e.ordinal)
               for e in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    assert not tracked.intersection(exports)
    assert not entry_refs[0x1283C] and 0x1283C not in dir64.values()
    assert rip(0x14C60) == 0x15D00 and dir64[0x15D00] == 0x14C40
    assert dir64[0x15D08] == dir64[0x15D10] == 0x14C60
    assert load_config.GuardMemcpyFunctionPointer - base == 0x15D20 and dir64[0x15D20] == 0x1479A
    assert rip(0x1479A) == 0x150B8
    imports = {s.address-base: [d.dll.decode(), s.name.decode()] for d in pe.DIRECTORY_ENTRY_IMPORT
               for s in d.imports if s.name}
    assert [part.lower() for part in imports[0x150B8]] == ["vcruntime140.dll", "memcpy"]
    assert target(0x8D78) == 0x8D10 and rip(0x8D10) == 0xA6C0
    assert target(0x8D97) == 0x8D00 and rip(0x8D00) == 0x8EA0
    assert rip(0x8DAB) == 0x12C70 and rip(0x8DB2) == 0x1479A
    assert rip(0x8D20) == rip(0x8DBD) == 0x20A90
    assert target(0x8E47) == 0x8DE0 and rip(0x8DE0) == 0xF100
    assert target(0x8E65) == 0x8DD0 and rip(0x8DD0) == 0xE040
    assert rip(0x8DF0) == rip(0x8E8A) == 0x20A98
    assert text(0x8DA2) == text(0x8E6F) == "mov r8, rsi"
    copy_lengths, fill_lengths = length_producers(0x8D20, COPY_LENGTHS), length_producers(0x8DF0, FILL_LENGTHS)
    assert len(copy_lengths) == 14 and len(fill_lengths) == 5

    selector_scope = []
    table = json.loads((unit / "s9/selector-bounds.json").read_text(encoding="utf-8"))["selectors"]
    for site, entry in SELECTORS.items():
        selector_scope.append({"entry": hex(entry), "site": hex(site), "length_register": "R8",
                               "normal_index_inclusive": table[hex(site)]["normal_index_inclusive"],
                               "entry_references": [describe(instructions[r]) for r in entry_refs[entry]],
                               "pointer_relocations": [hex(r) for r, t in dir64.items() if t == entry],
                               "caller_length_declaration": None})

    export_intervals = [dict(name=name, rva=hex(rva), at_or_above_slot=(rva >= 0x22148))
                        for rva, name in sorted(exports.items())
                        if pe.get_section_by_rva(rva).Name.rstrip(b"\0") == b".data"]
    assert len(export_intervals) == 26 and not any(e["at_or_above_slot"] for e in export_intervals)
    return {
        "original_sha256": trace["original_sha256"],
        "verified_code_ranges": trace["range_count"],
        "verified_instructions": trace["decoded_instructions"],
        "executable_byte_scan": raw_text_size,
        "matching_rel32_sites": {hex(k): hex(v) for k, v in sorted(raw_rel32.items())},
        "optional_callback": {"site": "0x11c56", "slot": "0x22148", "section": slot,
                              "readonly_control": readonly, "normal_original_gate": "inactive",
                              "evidence": [describe(instructions[r]) for r in
                                           (0x11C27,0x12450,0x11C35,0x11C38,0x12353,0x12360,
                                            0x12373,0x12377,0x12379,0x11C3D,0x11C3F,0x11C56)]},
        "local_callback": trace["local_callback"],
        "registered_callback": {"slot": "0x20a80", "section": section_result(0x20A80),
                                "writer": "0x1283c", "writer_reference_sites": [],
                                "reader_sites": ["0x127e8", "0x12804", "0x12941"]},
        "load_config_slots": {hex(i): {"original_target": hex(dir64[i]) if i in dir64 else None,
                                       "decoded_references": [hex(j) for j in entry_refs[i]]}
                              for i in (0x15D00,0x15D08,0x15D10,0x15D18,0x15D20)},
        "guard_memcpy_import": {"thunk": "0x1479a", "iat": "0x150b8", "import": imports[0x150B8]},
        "wrapper_length_sources": {"copy_0x8d20": copy_lengths, "fill_0x8df0": fill_lengths,
                                   "copy_cache_slot": "0x20a90", "fill_cache_slot": "0x20a98",
                                   "preserved_argument_register": "R8"},
        "selectors": selector_scope,
        "data_export_labels": export_intervals,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("unit", type=Path)
    parser.add_argument("trace_script", type=Path)
    args = parser.parse_args()
    print(json.dumps(inspect(args.original, args.unit, args.trace_script), indent=2))
