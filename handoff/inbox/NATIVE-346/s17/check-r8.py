"""Reproduce the static R8 argument evidence using the two pinned PE files."""

import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_EDI, X86_REG_ESI, X86_REG_RDI, X86_REG_RIP, X86_REG_RSI, X86_REG_R15, X86_REG_R15D


PPEXEC_SHA256 = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
ATDMS_SHA256 = "0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7"
TABLES_IN_CODE = {0x8EA0: (0x9590, 0xA698), 0xA6C0: (0xABC0, 0xC1C0),
                  0xE040: (0xE3E0, 0xF0F0), 0xF100: (0xF3C0, 0x109C0)}

FIXED_COPY = {0x142E: (0x1422, 0x170), 0x4EF9: (0x4EED, 0xFF),
              0x4FA6: (0x4F9A, 0xFF), 0x6FEE: (0x6FE5, 0xFF),
              0x700A: (0x7001, 0xFF), 0x733A: (0x7334, 0x320),
              0x8A65: (0x8A5C, 0xFF), 0x8A86: (0x8A7A, 0xFF)}
FIXED_FILL = {0x31D7: (0x31CC, 0x3520, 0x31D5), 0x3E95: (0x3E8A, 0x5F8, 0x3E93),
              0x73D6: (0x73CE, 0x320, 0x73D4)}

DYNAMIC = {
    0x7135: dict(kind="copy", producer="DMS_LENTHM arg 2 out", count_load=0x7102,
                 test=0x7109, skip=0x7113, compare=0x711C, small=0x7120,
                 scale=0x712A, count_operand="r8", sites=[0x7135],
                 inputs=[0x676E, 0x70B5, 0x70BC, 0x70C1, 0x70C8, 0x70CF, 0x70D6,
                         0x70DD, 0x70E4, 0x70E7, 0x70EC, 0x70F3, 0x70FA, 0x70FD,
                         0x7115, 0x7122, 0x7126, 0x712E, 0x7180, 0x7184, 0x11522]),
    0x71CC: dict(kind="copy", producer="DMS_LENTHM arg 3 out", count_load=0x7191,
                 test=0x71A3, skip=0x71A6, compare=0x71AF, small=0x71B3,
                 scale=0x71BD, count_operand="rdi", sites=[0x71CC],
                 inputs=[0x676E, 0x70E7, 0x70F3, 0x70FD, 0x71A8, 0x71B5, 0x71B9,
                         0x71C5, 0x71E0, 0x71E5, 0x71F3, 0x11522]),
    0x7E5A: dict(kind="copy", producer="DMS_TINFO + 0x848", count_load=0x7E26,
                 test=0x7E2D, skip=0x7E30, compare=0x7E36, small=0x7E3A,
                 scale=0x7E4C, count_operand="r14", sites=[0x7E5A, 0x7E70, 0x7E86],
                 inputs=[0x726B, 0x7D9E, 0x7DAD, 0x7DBA, 0x7DBF, 0x7DC6, 0x7DCB,
                         0x7DD2, 0x7DDA, 0x7DE1, 0x7DE8, 0x7DED, 0x7DF0, 0x7DF5,
                         0x7DFA, 0x7E45, 0x7E48, 0x7E50, 0x7E57, 0x7E5F, 0x7E62,
                         0x7E66, 0x7E6D, 0x7E75, 0x7E78, 0x7E7C, 0x7E83,
                         0x7EC0, 0x7EC5, 0x7ECE, 0x7ED3, 0x7EDC, 0x7EE1, 0x7F85]),
    0x8013: dict(kind="copy", producer="DMS_PLEX record at DMS_LOCATI result + 0x88 byte displacement",
                 count_load=0x7FB5, test=0x7FDB, skip=0x7FEC, compare=0x7FF1,
                 small=0x7FF5, scale=0x7FFF, count_operand="r14", sites=[0x8013],
                 inputs=[0x7DBF, 0x7DC6, 0x7DCB, 0x7DD2, 0x7DDA, 0x7DE1, 0x7DE8,
                         0x7DED, 0x7FBD, 0x7FC5, 0x7FCC, 0x7FEE, 0x7FF7, 0x7FFB,
                         0x8007, 0x800C, 0x8030, 0x8034, 0x11354]),
    0x565E: dict(kind="fill", producer="DMS_NCOMP qword + 0", count_load=0x563F,
                 test=0x5642, skip=0x5645, compare=0x5652, small=0x5656,
                 scale=0x5658, count_operand="r8", sites=[0x565E],
                 inputs=[0x561E, 0x5623, 0x562A, 0x5631, 0x5638, 0x5647, 0x564B,
                         0x565C, 0x5670, 0x567B]),
    0x79FA: dict(kind="fill", producer="DMS_TINFO + 0x848", count_load=0x79C8,
                 test=0x79DA, skip=0x79DD, compare=0x79DF, small=0x79E3,
                 scale=0x79E5, count_operand="rbx", sites=[0x79FA],
                 inputs=[0x726B, 0x79B0, 0x79C6, 0x79ED, 0x79F4, 0x79F8,
                         0x7A0A, 0x7A20, 0x7A28, 0x7A65, 0x7A88]),
}

DISPATCH = {
    0x91A4: ([0x8D20, 0x8D53, 0x8D78, 0x8D97, 0x8DA2, 0x8DBD, 0x8DCB,
              0x8D00, 0x8EAB, 0x8EB2, 0x8EDA, 0x8EDE, 0x8EE3, 0x8EE7,
              0x8F06, 0x8F0D, 0x8FAC, 0x8FB3, 0x8FBA, 0x8FC0, 0x9036,
              0x9096, 0x909F, 0x9199, 0x91A0], 0x9690, 256, "copy tail after alignment and 256-byte blocks"),
    0xA6E4: ([0x8D20, 0x8D10, 0x8D78, 0x8DA2, 0xA6C4, 0xA6CB, 0xA6D2,
              0xA6E0], 0xBDC0, 128, "input byte count; signed threshold below 128"),
    0xE215: ([0x8DF0, 0x8E23, 0x8E47, 0x8E65, 0x8E6F, 0x8E8A, 0x8E98,
              0x8DD0, 0xE065, 0xE06C, 0xE08A, 0xE08E, 0xE093, 0xE097,
              0xE0B3, 0xE0BA, 0xE0F9, 0xE118, 0xE11F, 0xE121, 0xE20A,
              0xE211], 0xE4E0, 256, "fill tail after alignment and 256-byte blocks"),
    0xF135: ([0x8DF0, 0x8DE0, 0x8E47, 0x8E6F, 0xF10D, 0xF115, 0xF122,
              0xF129, 0xF131], 0x105C0, 128, "input byte count; signed threshold below 128"),
    0x12C93: ([0x8DAB, 0x8DB2, 0x8DB9, 0x1479A, 0x12C70, 0x12C77, 0x12C80,
               0x12C87, 0x12C8B, 0x12C8D, 0x12C90], 0x24040, 184,
               "input byte count; signed threshold at most 8, with 1 taken by a direct branch"),
}


def require(condition, description):
    if not condition:
        raise ValueError(description)


def read_pe(path, digest):
    raw = path.read_bytes()
    require(hashlib.sha256(raw).hexdigest() == digest, f"SHA-256 differs for {path}")
    return pefile.PE(data=raw)


def rip_reference(insn):
    return next(insn.address + insn.size + arg.mem.disp for arg in insn.operands
                if arg.type == X86_OP_MEM and arg.mem.base == X86_REG_RIP)


def describe(insn):
    return {"rva": hex(insn.address), "bytes": insn.bytes.hex(),
            "instruction": f"{insn.mnemonic} {insn.op_str}".strip()}


def scan_verified_ranges(decoder, image, unit):
    spans = json.loads((unit / "reassembly.json").read_text(encoding="utf-8"))["matches"]
    spans += json.loads((unit / "s5/reassembly.json").read_text(encoding="utf-8"))
    instructions = {}
    for item in spans:
        start = int(item["rva"], 16)
        end = start + item["bytes"]
        require(hashlib.sha256(image[start:end]).hexdigest() == item["sha256"], f"span {start:#x}")
        fragments = [(start, end)]
        if start in TABLES_IN_CODE:
            left, right = TABLES_IN_CODE[start]
            fragments = [(start, left), (right, end)]
        for lo, hi in fragments:
            for insn in decoder.disasm(image[lo:hi], lo):
                require(insn.address not in instructions, f"duplicate RVA {insn.address:#x}")
                instructions[insn.address] = insn
    require(len(spans) == 532 and len(instructions) == 12498, "count of prior ranges or instructions")
    return instructions


def collect_imports(pe):
    return {entry.address - pe.OPTIONAL_HEADER.ImageBase: (dll.dll.decode(), entry.name.decode())
            for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports if entry.name}


def reaching_nonvolatile_writes(instructions, start, end, site, register_aliases):
    """Trace direct intraprocedural branches, keeping the Win64 nonvolatile registers across calls."""
    pending = [start]
    visited = set()
    parents = defaultdict(set)
    while pending:
        address = pending.pop()
        if address in visited or not start <= address < end:
            continue
        visited.add(address)
        insn = instructions[address]
        if insn.group(cs.CS_GRP_RET):
            continue
        successors = []
        if insn.group(cs.CS_GRP_JUMP):
            require(insn.operands[0].type == X86_OP_IMM, f"indirect transfer at {address:#x}")
            successors.append(insn.operands[0].imm)
        if insn.mnemonic != "jmp":
            successors.append(address + insn.size)
        for target in successors:
            parents[target].add(address)
            pending.append(target)

    require(site in visited, f"unreachable use {site:#x}")
    pending = list(parents[site])
    visited = set()
    definitions = set()
    while pending:
        address = pending.pop()
        if address in visited:
            continue
        visited.add(address)
        _, writes = instructions[address].regs_access()
        if register_aliases.intersection(writes):
            definitions.add(address)
        else:
            require(address != start, f"register can enter the routine unset at {site:#x}")
            pending.extend(parents[address])
    return definitions


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("atdms", type=Path)
    parser.add_argument("--unit", type=Path, default=Path(__file__).resolve().parents[1])
    args = parser.parse_args()
    pe = read_pe(args.original, PPEXEC_SHA256)
    atdms = read_pe(args.atdms, ATDMS_SHA256)
    image = pe.get_memory_mapped_image()
    at_image = atdms.get_memory_mapped_image()
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    original = scan_verified_ranges(decoder, image, args.unit)

    def at(address):
        return next(decoder.disasm(at_image[address:address + 15], address, 1))

    def evidence(addresses):
        return [describe(original[address]) for address in addresses]

    def direct_calls(target):
        return {addr for addr, insn in original.items() if insn.mnemonic == "call"
                and insn.operands[0].type == X86_OP_IMM and insn.operands[0].imm == target}

    reaching = {}
    for site, register, aliases, writer in [
            (0x7122, "RSI", {X86_REG_RSI, X86_REG_ESI}, 0x676E),
            (0x71B5, "RSI", {X86_REG_RSI, X86_REG_ESI}, 0x676E),
            (0x79C8, "RDI", {X86_REG_RDI, X86_REG_EDI}, 0x726B),
            (0x7E26, "RDI", {X86_REG_RDI, X86_REG_EDI}, 0x726B),
            (0x7FB5, "R15", {X86_REG_R15, X86_REG_R15D}, 0x7DCB)]:
        writes = reaching_nonvolatile_writes(original, 0x65B0, 0x87CC, site, aliases)
        require(writes == {writer}, f"reaching definitions at {site:#x}: {writes}")
        reaching[hex(site)] = {"register": register, "definition": describe(original[writer])}

    contracts = {}
    for site, record in DYNAMIC.items():
        load, test, skip, compare, small, scale = (record[key] for key in
                ("count_load", "test", "skip", "compare", "small", "scale"))
        operand = record["count_operand"]
        require(original[load].mnemonic == "mov" and original[load].operands[1].size == 8,
                f"qword count load at {load:#x}")
        require(original[test].op_str == f"{operand}, {operand}" and original[skip].mnemonic == "jle",
                f"positive count at {site:#x}")
        limit = 13 if original[small].mnemonic == "jb" else 12
        require(original[compare].mnemonic == "cmp" and original[compare].operands[1].imm == limit
                and original[small].mnemonic == ("jb" if limit == 13 else "jbe"),
                f"bulk count threshold at {site:#x}")
        require(original[scale].op_str in {f"{operand}, 3", f"r8, [{operand}*8]"},
                f"scale at {site:#x}")
        addresses = sorted(set(record["inputs"] + [load, test, skip, compare, small, scale] + record["sites"]))
        contracts[hex(site)] = {"kind": record["kind"], "producer": record["producer"],
                                "bulk_min_count": 13, "unit_bytes": 8,
                                "calls": [hex(rva) for rva in record["sites"]],
                                "evidence": evidence(addresses)}

    dynamic_copy = {rva for record in DYNAMIC.values() if record["kind"] == "copy" for rva in record["sites"]}
    dynamic_fill = {rva for record in DYNAMIC.values() if record["kind"] == "fill" for rva in record["sites"]}
    require(direct_calls(0x8D20) == set(FIXED_COPY) | dynamic_copy, "copy caller census")
    require(direct_calls(0x8DF0) == set(FIXED_FILL) | dynamic_fill, "fill caller census")
    fixed = {}
    for site, (load, count, *fill) in sorted((FIXED_COPY | FIXED_FILL).items()):
        require(original[load].op_str == f"r8d, {count:#x}", f"fixed length at {site:#x}")
        fixed[hex(site)] = {"bytes": count, "evidence": evidence([load, *fill, site])}
        if fill:
            require(original[fill[0]].op_str == "edx, edx" and original[fill[0]].mnemonic == "xor",
                    f"fixed fill byte at {site:#x}")
            fixed[hex(site)]["fill_byte"] = 0

    imports = collect_imports(pe)
    bindings = {0x5623: (0x154A0, "DMS_IPOFF1"), 0x5638: (0x154F0, "DMS_NCOMP"),
                0x676E: (0x154F8, "DMS_PLEX"), 0x726B: (0x15278, "DMS_TINFO"),
                0x712E: (0x154D8, "DMS_GLOBAL"), 0x71C5: (0x154E8, "DMS_RGLOB"),
                0x7FC5: (0x152C8, "DMS_PGMNFO"), 0x800C: (0x152C8, "DMS_PGMNFO"),
                0x11354: (0x15508, "DMS_LOCATI"), 0x113D8: (0x15458, "DMS_LOCATM"),
                0x11522: (0x15288, "DMS_LENTHM")}
    exports = {item.name.decode(): item.address for item in atdms.DIRECTORY_ENTRY_EXPORT.symbols if item.name}
    for site, (slot, symbol) in bindings.items():
        require(rip_reference(original[site]) == slot and imports[slot] == ("atdms.dll", symbol)
                and symbol in exports, f"IAT binding at {site:#x}")
    for site, slot, name in [(0x14794, 0x150D0, "memset"), (0x1479A, 0x150B8, "memcpy")]:
        require(rip_reference(original[site]) == slot and imports[slot] == ("VCRUNTIME140.dll", name), name)

    state = {}
    for site, (addresses, table, entries, note) in DISPATCH.items():
        require(original[site].mnemonic in {"jmp", "notrack jmp"}, f"selector at {site:#x}")
        state[hex(site)] = {"kind": note, "table_rva": hex(table), "table_entries": entries,
                            "table_bytes_sha256": hashlib.sha256(image[table:table + 8 * entries]).hexdigest(),
                            "evidence": evidence(addresses + [site])}

    tinfo_count = exports["DMS_TINFO"] + 0x848
    tinfo_refs = set()
    for function in atdms.DIRECTORY_ENTRY_EXCEPTION:
        lo, hi = function.struct.BeginAddress, function.struct.EndAddress
        for insn in decoder.disasm(at_image[lo:hi], lo):
            for operand in insn.operands:
                if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                    if insn.address + insn.size + operand.mem.disp == tinfo_count:
                        tinfo_refs.add(insn.address)
    require(tinfo_refs == {0x4074, 0x15FDE, 0x16278, 0x1627F, 0x1EB51, 0x37E31, 0x3B3C9},
            "decoded .pdata RIP-relative DMS_TINFO+0x848 references")
    require(exports["DMS_APOPEN"] == 0x4040 and rip_reference(at(0x4074)) == tinfo_count
            and at(0x4074).operands[1].imm == 64, "DMS_APOPEN initializes DMS_TINFO+0x848 to 64")
    require(exports["DMS_LENTHM"] == 0x204D0 and exports["DMS_LOCATM"] == 0x207C0
            and exports["DMS_LOCATI"] == 0x20760, "ATDMS procedure RVAs")
    require(rip_reference(at(0x20565)) == exports["DMS_DMS"] + 8, "LENTHM block ratio field")
    require(at(0x20549).op_str == "qword ptr [rsi], rax" and at(0x20554).op_str == "qword ptr [rdi], rax"
            and at(0x2057A).op_str == "qword ptr [rdi], rax" and at(0x2059E).op_str == "qword ptr [rsi], rax"
            and at(0x205B1).op_str == "qword ptr [rdi], rax" and at(0x205B4).op_str == "qword ptr [rsi], 0",
            "DMS_LENTHM producer stores")
    backend = {hex(site): at_image[rip_reference(at(site)):].split(b"\0", 1)[0].decode()
               for site in (0x694E6, 0x69546)}
    require(tuple(backend.values()) == ("Lenthr", "Lenthi"), "alternate backend symbol names")
    for site, rva in [(0x70EC, 0x206E8), (0x70F3, 0x206E0), (0x7102, 0x206E8), (0x7191, 0x206E0)]:
        require(rip_reference(original[site]) == rva, "DMS_LENTHM output alias to count load")

    result = {
        "ppexec_sha256": PPEXEC_SHA256, "atdms_sha256": ATDMS_SHA256,
        "capstone": cs.__version__, "pefile": pefile.__version__,
        "verified_ppexec_code_ranges": 532, "decoded_ppexec_instructions": len(original),
        "fixed_call_lengths": fixed, "dynamic_call_sources": contracts,
        "contract": {"signed_positive_bulk_min_count": 13,
                     "max_count_without_unsigned_multiply_wrap": ((1 << 64) - 1) // 8,
                     "max_count_with_nonnegative_signed_byte_length": ((1 << 63) - 1) // 8},
        "intpp_reaching_nonvolatile_definitions": reaching,
        "dispatch": state,
        "imports": {hex(site): {"slot": hex(slot), "symbol": symbol, "export": hex(exports[symbol])}
                    for site, (slot, symbol) in bindings.items()},
        "atdms": {
            "dms_lenthm": [describe(at(rva)) for rva in
                (0x204D7, 0x204DA, 0x20525, 0x2052A, 0x20531, 0x20537, 0x20544, 0x20549,
                 0x2054F, 0x20554, 0x20559, 0x20563, 0x20565, 0x2056F, 0x20573, 0x2057A,
                 0x2057D, 0x2058E, 0x20592, 0x20595, 0x2059B, 0x2059E, 0x205A3,
                 0x205AA, 0x205B1, 0x205B4, 0x205C5, 0x205CE, 0x694E6, 0x69546)],
            "dms_lenthm_backend_exports": backend,
            "dms_locatm_locati": [describe(at(rva)) for rva in
                (0x207A2, 0x207A9, 0x207AE, 0x207CC, 0x207CF, 0x2080C, 0x2080F, 0x2081C,
                 0x20838, 0x2083E, 0x20863)],
            "dms_tinfo_0x848_rva": hex(tinfo_count),
            "dms_tinfo_0x848_rip_relative_exception_range_references": [describe(at(rva)) for rva in sorted(tinfo_refs)],
            "dms_ncomp_potential_address_escapes": [describe(at(rva)) for rva in
                (0x1F3A6, 0x1F4B6, 0x2E0AC)],
            "dms_pgmnfo_neighbor_export": {"name": "DMS_LMHST", "rva": hex(exports["DMS_LMHST"])},
        },
    }
    print(json.dumps(result, ensure_ascii=True, indent=2))


if __name__ == "__main__":
    main()
