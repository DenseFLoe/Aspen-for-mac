"""Verify the FindComponent s17 handoff against the original PE and fixed s5 evidence."""

import argparse
import csv
import hashlib
import json
import re
import struct
from collections import Counter
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_RIP


ORIGINAL_SHA256 = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def report(original, candidate, baseline, reference):
    assert digest(original) == ORIGINAL_SHA256
    pe = pefile.PE(str(original))
    base = pe.OPTIONAL_HEADER.ImageBase
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    imports = {
        item.address - base: lib.dll.decode().lower() + "!" +
        (f"#{item.ordinal}" if item.import_by_ordinal else item.name.decode().lower())
        for lib in pe.DIRECTORY_ENTRY_IMPORT for item in lib.imports
    }

    def decode(rva):
        return next(decoder.disasm(pe.get_data(rva, 15), rva, count=1))

    def rip(insn, operand=0):
        op = insn.operands[operand]
        if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
            return insn.address + insn.size + op.mem.disp

    def listings(unit):
        result = {}
        for line, content in enumerate((unit / "code/native.asm").read_text(encoding="utf-8-sig").splitlines(), start=1):
            match = re.match(r"^([0-9a-f]{8})  ((?:[0-9a-f]{2} )*[0-9a-f]{2})  ", content, re.I)
            if match:
                rva, raw = int(match[1], 16), bytes.fromhex(match[2])
                assert pe.get_data(rva, len(raw)) == raw, f"listing mismatch at {rva:#x}"
                result[line] = rva
        return result

    def import_sites(assembly):
        result = {}
        for site in sorted(set(assembly.values())):
            insn = decode(site)
            if insn.mnemonic in ("call", "jmp") and (slot := rip(insn)) in imports:
                result[site] = imports[slot]
        return result

    current = listings(candidate)
    base_lines = listings(baseline)
    original_sites = import_sites(base_lines)
    new_sites = import_sites(current)
    assert original_sites == new_sites and len(new_sites) == 363
    current_addresses = set(current.values())
    calls = rows(candidate / "calls.csv")
    call_index = {}
    for call in calls:
        line = int(re.search(r"#L(\d+)", call["listing"])[1])
        call_index.setdefault(current[line], []).append(call)
    declarations = {site: call["callee"].lower() for site, records in call_index.items()
                    for call in records if call["class"] == "external"}
    external_drift = {hex(site): [new_sites.get(site), declarations.get(site)]
                      for site in sorted(new_sites.keys() | declarations.keys())
                      if new_sites.get(site) != declarations.get(site)}

    guard = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer - base
    thunk = struct.unpack("<Q", pe.get_data(guard, 8))[0] - base
    assert (guard, thunk) == (0x7670, 0x6050)
    assert decode(thunk).mnemonic == "jmp" and decode(thunk).op_str == "rax"
    register_sources = []
    for site, origin, slot in ((0x4A7C, 0x4A64, 0xB6F8), (0x53F2, 0x53EB, 0x7670)):
        call, load = decode(site), decode(origin)
        assert call.operands[0].type == X86_OP_REG and call.operands[0].reg == load.operands[0].reg
        assert load.mnemonic == "mov" and rip(load, 1) == slot
        register_sources.append({"call": hex(site), "load": hex(origin), "slot": hex(slot),
                                 "call_classes": [c["class"] for c in call_index.get(site, [])]})

    checks = {"omitted": [], "com": [], "thunk": []}
    for row in rows(reference):
        category = row["category"]
        site = int(row["rva"], 0)
        insn = decode(site)
        assert insn.bytes.hex() == row["original_bytes"]
        item = {"site": hex(site), "in_listing": site in current_addresses,
                "call_classes": [call["class"] for call in call_index.get(site, [])]}
        if category == "omitted":
            assert site == thunk or rip(insn) == guard
            item["asm"] = insn.mnemonic + " " + insn.op_str
        if category == "thunk":
            assert insn.operands[0].type == X86_OP_IMM and insn.mnemonic in ("call", "jmp")
            target = insn.operands[0].imm
            slot = rip(decode(target))
            item.update(thunk=hex(target), slot=hex(slot), original_import=imports[slot],
                        earlier_import=row["expected"].lower())
        checks[category].append(item)

    com_rows = rows(candidate / "code/dispatch-sites.csv")
    by_com_site = {int(row["rva"], 0): row for row in com_rows}
    assert len(by_com_site) == len(com_rows) == len(checks["com"])
    for item in checks["com"]:
        site = int(item["site"], 0)
        declaration = by_com_site[site]["detail"]
        slot = re.search(r"slot (0x[0-9a-f]+)", declaration, re.I)
        operand = decode(site).operands[0]
        item["slot_displacement"] = hex(operand.mem.disp) if operand.type == X86_OP_MEM else None
        item["candidate_slot_displacement"] = slot[1].lower() if slot else None
        item["membership_note"] = declaration

    thunk_rows = rows(candidate / "code/import-callers.csv")
    appendix = {int(row["rva"], 0): row for row in thunk_rows}
    assert len(appendix) == len(thunk_rows) == len(checks["thunk"])
    for item in checks["thunk"]:
        row = appendix[int(item["site"], 0)]
        item["appendix_in_candidate"] = row["in_candidate"]
        item["appendix_owner"] = row["owner"]
        item["appendix_detail"] = row["detail"]

    coverage = {int(row["key"], 0) for row in rows(candidate / "coverage.csv")}
    base_coverage = {int(row["key"], 0) for row in rows(baseline / "coverage.csv")}
    metrics = json.loads((candidate / "metrics.json").read_text(encoding="utf-8-sig"))
    metric_drift = {}
    for name in ("calls", "coverage", "native-functions"):
        actual = digest(candidate / (name + ".csv"))
        declared = metrics.get(name.replace("-", "_") + "_sha256")
        if actual != declared:
            metric_drift[name] = {"actual_sha256": actual, "declared_sha256": declared}
    return {
        "original_sha256": ORIGINAL_SHA256, "historical_address_table_sha256": digest(reference),
        "instruction_records": len(current), "call_counts": dict(Counter(row["class"] for row in calls)),
        "direct_iat_sites": len(new_sites), "external_drift": external_drift,
        "coverage_key_count": len(coverage), "baseline_keys_missing": [hex(x) for x in sorted(base_coverage - coverage)],
        "baseline_instructions_missing": [hex(x) for x in sorted(set(base_lines.values()) - current_addresses)],
        "reference_groups": checks, "register_sources": register_sources, "metric_fingerprint_drift": metric_drift,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("original", "candidate", "baseline", "reference"):
        parser.add_argument(name, type=Path)
    print(json.dumps(report(**vars(parser.parse_args())), indent=2))
