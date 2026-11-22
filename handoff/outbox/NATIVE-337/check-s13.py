"""Replay the FindComponent.dll s13 review against the pinned AMD64 PE."""
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


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def listings(folder, image):
    lines = {}
    for line_number, line in enumerate((folder / "code/native.asm").read_text(encoding="utf-8-sig").splitlines(), 1):
        match = re.match(r"^([0-9a-f]{8})  ((?:[0-9a-f]{2} )*[0-9a-f]{2})  ", line, re.I)
        if match:
            site = int(match[1], 16)
            data = bytes.fromhex(match[2])
            assert image.get_data(site, len(data)) == data, hex(site)
            lines[line_number] = site
    return lines


def references(path, lines):
    return [(lines[int(row["listing"].split("#L")[1].split("-")[0])], row) for row in rows(path)]


def review(original, candidate, baseline, prior, checker):
    original_sha = sha(original)
    assert original_sha == "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
    image = pefile.PE(str(original))
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    base_va = image.OPTIONAL_HEADER.ImageBase
    imports = {member.address - base_va: dll.dll.decode() + "!" +
               (f"#{member.ordinal}" if member.import_by_ordinal else member.name.decode())
               for dll in image.DIRECTORY_ENTRY_IMPORT for member in dll.imports}

    def decode(site):
        return next(decoder.disasm(image.get_data(site, 15), site, count=1))

    def rip_target(ins):
        operand = ins.operands[0]
        if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
            return ins.address + ins.size + operand.mem.disp

    def iat_sites(lines):
        result = {}
        for site in set(lines.values()):
            ins = decode(site)
            if ins.mnemonic in ("call", "jmp"):
                slot = rip_target(ins)
                if slot in imports:
                    result[site] = (slot, imports[slot].lower())
        return result

    candidate_lines = listings(candidate, image)
    baseline_lines = listings(baseline, image)
    chosen_sites = iat_sites(candidate_lines)
    baseline_sites = iat_sites(baseline_lines)
    call_rows = references(candidate / "calls.csv", candidate_lines)
    external = {site: row["callee"].lower() for site, row in call_rows if row["class"] == "external"}
    actual_symbols = {site: symbol for site, (_, symbol) in chosen_sites.items()}
    symbol_differences = {hex(site): [external.get(site), actual_symbols.get(site)]
                          for site in sorted(external.keys() | actual_symbols.keys())
                          if external.get(site) != actual_symbols.get(site)}
    reported = {int(row["site_rva"], 16): (int(row["iat_slot"], 16), row["import"].lower())
                for row in rows(candidate / "code/site-diff.csv") if row["present_in_current"] == "yes"}
    def slots(records):
        return {site: slot for site, (slot, _) in records.items()}

    assert slots(reported) == slots(baseline_sites) == slots(chosen_sites) and len(chosen_sites) == 363

    unresolved = {site for site, row in call_rows if row["class"] == "unresolved"}
    annex = {site for site, _ in references(candidate / "code/indirect.csv", candidate_lines)}
    derived = {site for site, _ in references(candidate / "code/indirect-resolved.csv", candidate_lines)}
    assert unresolved == annex == derived and len(unresolved) == 99
    register_calls = {hex(site): decode(site).op_str for site in sorted(unresolved)
                      if decode(site).operands[0].type == X86_OP_REG}
    assert len(register_calls) == 2

    guard_config = image.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    guard_slot = guard_config.GuardCFDispatchFunctionPointer - base_va
    guard_thunk = struct.unpack("<Q", image.get_data(guard_slot, 8))[0] - base_va
    load_cfg = decode(0x53EB)
    assert load_cfg.mnemonic == "mov" and load_cfg.operands[0].reg == decode(0x53F2).operands[0].reg
    assert load_cfg.operands[1].mem.base == X86_REG_RIP
    assert load_cfg.address + load_cfg.size + load_cfg.operands[1].mem.disp == guard_slot
    classes = {site: row["class"] for site, row in call_rows}
    historical = rows(prior)
    guard_edges = []
    com_sites = []
    caller_edges = []
    historical_symbol_differences = []
    for row in historical:
        site = int(row["rva"], 16)
        ins = decode(site)
        assert ins.bytes.hex() == row["original_bytes"]
        if row["category"] == "omitted":
            assert site not in unresolved and ins.mnemonic == row["expected"]
            assert (site == guard_thunk) or (rip_target(ins) == guard_slot)
            guard_edges.append([hex(site), ins.bytes.hex(), ins.mnemonic, ins.op_str, classes.get(site)])
        elif row["category"] == "com":
            assert site in unresolved
            com_sites.append(site)
        elif row["category"] == "thunk":
            assert ins.operands[0].type == X86_OP_IMM and ins.mnemonic in ("call", "jmp")
            target = ins.operands[0].imm
            slot = rip_target(decode(target))
            assert slot in imports
            if imports[slot].lower() != row["expected"].lower():
                historical_symbol_differences.append([hex(site), row["expected"], imports[slot]])
            caller_edges.append([hex(site), hex(target), hex(slot), imports[slot], classes.get(site), site in candidate_lines.values()])

    candidate_entries = {int(row["key"], 0) for row in rows(candidate / "coverage.csv")}
    baseline_entries = {int(row["key"], 0) for row in rows(baseline / "coverage.csv")}
    counts = Counter(row["class"] for _, row in call_rows)
    artifacts = {path.relative_to(candidate).as_posix(): sha(path) for path in sorted(candidate.rglob("*"))
                 if path.is_file() and path.name != "s5-started.md"}
    metrics = json.loads((candidate / "metrics.json").read_text(encoding="utf-8-sig"))
    metric_differences = {}
    for artifact in ("coverage", "calls", "native-functions"):
        path = f"{artifact}.csv"
        declared = metrics[artifact.replace("-", "_") + "_sha256"]
        if artifacts[path] != declared:
            metric_differences[path] = {"actual": artifacts[path], "declared": declared}
    return {
        "candidate": "43017ac0901a450784de1678b55d2f501641b75c",
        "baseline": "a180dcfd1b6bd39072a4a03b94b908408e6da426",
        "original_sha256": original_sha,
        "checker_sha256": sha(checker),
        "prior_address_list_sha256": sha(prior),
        "instruction_records_verified": {"candidate": len(candidate_lines), "baseline": len(baseline_lines)},
        "direct_iat_sites": len(chosen_sites),
        "direct_iat_symbol_differences": symbol_differences,
        "calls_by_class": dict(counts),
        "coverage_entries": {"baseline": len(baseline_entries), "candidate": len(candidate_entries),
                             "missing": [hex(site) for site in sorted(baseline_entries - candidate_entries)]},
        "unresolved_register_calls": register_calls,
        "guard_dispatch": {"slot_rva": hex(guard_slot), "disk_thunk_rva": hex(guard_thunk),
                           "edges": guard_edges, "extra_call": "0x53f2 loads GuardCF slot at 0x53eb"},
        "com_unresolved": len(com_sites),
        "caller_to_import_trampoline": caller_edges,
        "historical_symbol_differences": historical_symbol_differences,
        "candidate_metric_fingerprint_differences": metric_differences,
        "artifact_sha256": artifacts,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("original", "candidate", "baseline", "prior", "checker"):
        parser.add_argument(name, type=Path)
    print(json.dumps(review(**vars(parser.parse_args())), indent=2))
