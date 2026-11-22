"""Recheck ppexec's initialized count and the traced atdms argument routes."""

import argparse
import hashlib
import json
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_MEM, X86_REG_RIP

PPEXEC_SHA = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
ATDMS_SHA = "0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7"
COUNT_OFFSET = 0x848
ATDMS_ROUTES = {
    "DMS_ITSUM_to_DMS_INT2CS": [
        0x1eb48, 0x1eb51, 0x1eb58, 0x1eb5f, 0x1eb66, 0x1eb6d, 0x1eb70, 0x1eb73,
        0x63cff, 0x63d02, 0x63d05, 0x63d0c, 0x63d10, 0x63d38, 0x63d52,
        0x63d68, 0x63d71, 0x6d2e4, 0x63dd3, 0x63de2,
    ],
    "lookup_to_DMS_CPLNKI_and_readers": [
        0x3b3a6, 0x3b3ad, 0x3b3b4, 0x3b3b9, 0x3b3c2, 0x3b3c9, 0x3b3d0,
        0x3b3d7, 0xcc99, 0xcd30, 0xcd33, 0xcd37, 0xcd3f, 0xcd56, 0xcd64,
        0x63e1a, 0xcd69, 0xcd89, 0xcd92, 0x5be9a, 0x5be9f, 0x5bea9,
        0x5bee6, 0x5beec, 0x5c4e7, 0xcdcc, 0xcdd5, 0xd204, 0xd20d,
    ],
    "remaining_local_address_routes": [
        0x15fde, 0x15fe8, 0x37e31, 0x37e3b, 0x3aee3, 0x3b2f2, 0x3b2f8,
        0x60f4c, 0x3b483, 0x3b489, 0x6089f, 0x608cc, 0x608cf, 0x16278,
        0x1627f, 0x162f2, 0x162fb, 0x6169f, 0x616a2, 0x616b8,
    ],
}


class Original:
    def __init__(self, path, expected):
        raw = path.read_bytes()
        actual = hashlib.sha256(raw).hexdigest()
        if actual != expected:
            raise ValueError(f"{path.name}: expected {expected}, got {actual}")
        self.pe = pefile.PE(data=raw)
        self.image = self.pe.get_memory_mapped_image()
        self.decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
        self.decoder.detail = True
        self.exports = {
            sym.name.decode(): sym.address
            for sym in self.pe.DIRECTORY_ENTRY_EXPORT.symbols
            if sym.name
        }

    def instruction(self, rva):
        return next(self.decoder.disasm(self.image[rva:rva + 15], rva))

    def rip_references(self, target):
        references = {}
        for row in self.pe.DIRECTORY_ENTRY_EXCEPTION:
            start, end = row.struct.BeginAddress, row.struct.EndAddress
            for insn in self.decoder.disasm(self.image[start:end], start):
                if target in rip_targets(insn):
                    references[insn.address] = insn
        return [describe(references[rva]) for rva in sorted(references)]


def rip_targets(insn):
    return [
        insn.address + insn.size + op.mem.disp
        for op in insn.operands
        if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP
    ]


def describe(insn):
    row = {
        "rva": hex(insn.address),
        "bytes": bytes(insn.bytes).hex(),
        "instruction": f"{insn.mnemonic} {insn.op_str}".rstrip(),
    }
    targets = rip_targets(insn)
    if targets:
        row["rip_targets"] = [hex(target) for target in targets]
    return row


def check(pp, at):
    table_base = at.exports["DMS_TINFO"]
    count_rva = table_base + COUNT_OFFSET
    count_section = at.pe.get_section_by_rva(count_rva)
    init = at.instruction(0x4074)
    if rip_targets(init) != [count_rva] or init.mnemonic != "mov" or init.operands[0].size != 8:
        raise ValueError("DMS_TINFO count initialization")
    count = init.operands[1].imm

    call_sites = (
        (0x7e5a, 0x7e50, 0x8d20, "DMS_TINFO", 0x2f0, [0x7e3f, 0x7e45, 0x7e48, 0x7e57]),
        (0x7e70, 0x7e66, 0x8d20, "DMS_TINFO", 0x4f8, [0x7e42, 0x7e5f, 0x7e62, 0x7e6d]),
        (0x7e86, 0x7e7c, 0x8d20, "DMS_TINFO", 0xf0, [0x7e3c, 0x7e75, 0x7e78, 0x7e83]),
        (0x79fa, 0x79f4, 0x8df0, "DMS_PGMNFO", 0x18, [0x79e5, 0x79ed, 0x79f8]),
    )
    ranges = []
    for site, destination, target, export, offset, setup in call_sites:
        call = pp.instruction(site)
        dest = pp.instruction(destination)
        actual_offset = dest.operands[1].mem.disp if dest.mnemonic == "lea" else dest.operands[1].imm
        if call.mnemonic != "call" or call.operands[0].imm != target or actual_offset != offset:
            raise ValueError(f"Unexpected call or destination at {site:#x}")
        ranges.append({
            "operation": "copy" if target == 0x8d20 else "fill 0x20",
            "call_rva": hex(site),
            "callee_rva": hex(target),
            "destination_export": export,
            "relative_range": [hex(offset), hex(offset + count * 8)],
            "paired_atdms_range": [hex(at.exports[export] + relative)
                                  for relative in (offset, offset + count * 8)],
            "evidence": [describe(pp.instruction(rva)) for rva in sorted([*setup, destination, site])],
        })

    references = at.rip_references(count_rva)
    expected_refs = [0x4074, 0x15fde, 0x16278, 0x1627f, 0x1eb51, 0x37e31, 0x3b3c9]
    if [int(row["rva"], 16) for row in references] != expected_refs:
        raise ValueError("DMS_TINFO count reference inventory changed")
    return {
        "original_sha256": {"ppexec.dll": PPEXEC_SHA, "atdms.dll": ATDMS_SHA},
        "tools": {"capstone": cs.__version__, "pefile": pefile.__version__},
        "count_export_rva": hex(table_base),
        "count_field_rva": hex(count_rva),
        "count_memory_section": count_section.Name.rstrip(b"\0").decode(),
        "count_is_zero_filled": count_rva - count_section.VirtualAddress >= count_section.SizeOfRawData,
        "initialized_count": count,
        "initialized_bytes": count * 8,
        "direct_rip_references_in_exception_ranges": references,
        "traced_atdms_instructions": {
            path: [describe(at.instruction(rva)) for rva in rvas]
            for path, rvas in ATDMS_ROUTES.items()
        },
        "ppexec_count_loads": [describe(pp.instruction(rva)) for rva in
                              (0x79c8, 0x79da, 0x79df, 0x7e26, 0x7e2d, 0x7e36, 0x7e4c)],
        "initialized_path_destinations": ranges,
        "other_writers_or_layout": "External writes and full source/destination layouts remain open.",
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("ppexec", type=Path)
    parser.add_argument("atdms", type=Path)
    args = parser.parse_args()
    print(json.dumps(check(Original(args.ppexec, PPEXEC_SHA), Original(args.atdms, ATDMS_SHA)), indent=2))


if __name__ == "__main__":
    main()
