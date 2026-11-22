"""Recheck FindComponent.dll s21 static evidence. Requires capstone and pefile.

Usage: python check-s21.py ORIGINAL_DLL CANDIDATE_ITEM_DIR [--output report.json]
The verifier reads the original PE, candidate CSV, listing and C source as data.
"""
import argparse
import csv
import hashlib
import json
import re
import uuid
from collections import Counter, defaultdict
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP

ORIGINAL_SHA256 = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
LISTING_ROW = re.compile(r"^([0-9A-Fa-f]{8})  ((?:[A-Fa-f0-9]{2} )*[A-Fa-f0-9]{2})  ")
MEMBERS = {0x10: "IUnknown::Release", 0x28: "IDispatch::GetIDsOfNames", 0x30: "IDispatch::Invoke"}


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def require(condition, description):
    if not condition:
        raise ValueError(description)


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def listing(path, image):
    addresses = {}
    regions = {}
    region = None
    for number, line in enumerate(path.read_text(encoding="utf-8-sig").splitlines(), 1):
        header = re.match(r"; FUNC ([0-9A-Fa-f]+)-", line)
        if header:
            region = int(header[1], 16)
        match = LISTING_ROW.match(line)
        if match:
            site = int(match[1], 16)
            data = bytes.fromhex(match[2])
            require(image[site:site + len(data)] == data, f"listing bytes at {site:#x}")
            addresses[number] = site
            regions[site] = region
    return addresses, regions


def rip_target(insn, operand=0):
    op = insn.operands[operand]
    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
        return insn.address + insn.size + op.mem.disp
    return None


def source_span(reference, lines):
    start, end = map(int, re.fullmatch(r"code/native\.c#L(\d+)-L(\d+)", reference).groups())
    return "\n".join(lines[start-1:end])


def verify(original, folder):
    require(digest(original) == ORIGINAL_SHA256, "original SHA-256 mismatch")
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True

    def decode(site):
        return next(decoder.disasm(image[site:site + 16], site, count=1))

    imports = {}
    for dll in pe.DIRECTORY_ENTRY_IMPORT:
        for symbol in dll.imports:
            ident = f"#{symbol.ordinal}" if symbol.import_by_ordinal else symbol.name.decode()
            imports[symbol.address - pe.OPTIONAL_HEADER.ImageBase] = dll.dll.decode() + "!" + ident

    address, region = listing(folder / "code/native.asm", image)
    starts = set(address.values())
    c_lines = (folder / "code/native.c").read_text(encoding="utf-8-sig").splitlines()
    coverage = {int(row["key"], 16): row for row in rows(folder / "coverage.csv")}
    calls = rows(folder / "calls.csv")

    def reference_site(row):
        line = int(re.fullmatch(r"code/native\.asm#L(\d+)-L\d+", row["listing"])[1])
        return address.get(line)

    by_site = defaultdict(list)
    for row in calls:
        by_site[reference_site(row)].append(row)

    direct = {}
    for site in starts:
        insn = decode(site)
        if insn.mnemonic in ("call", "jmp") and rip_target(insn) in imports:
            direct[site] = imports[rip_target(insn)]
    direct_matches = sum(any(row["class"] == "external" and row["callee"] == symbol
                             for row in by_site[site]) for site, symbol in direct.items())

    two_hop = rows(folder / "code/s21-two-hop.csv")
    two_hop_sites = set()
    region_diff = []
    for row in two_hop:
        site, owner = (int(row[key], 16) for key in ("rva", "owner"))
        thunk, slot, symbol = re.fullmatch(r"(0x\w+) -> IAT (0x\w+) -> (.+)", row["detail"]).groups()
        transfer = decode(site)
        thunk = int(thunk, 16)
        slot = int(slot, 16)
        require(transfer.mnemonic in {"call", "jmp"} and transfer.operands[0].type == X86_OP_IMM
                and transfer.operands[0].imm == thunk, f"first hop at {site:#x}")
        tail = decode(thunk)
        require(tail.mnemonic == "jmp" and rip_target(tail) == slot and imports.get(slot) == symbol,
                f"second hop at {site:#x}")
        require(any(r["class"] == "external" and r["callee"] == symbol and int(r["caller"], 16) == owner
                    for r in by_site[site]), f"main two-hop reference at {site:#x}")
        require(owner in coverage and source_span(coverage[owner]["source"], c_lines).strip(),
                f"owner C reference at {site:#x}")
        if owner != region[site]:
            region_diff.append({"site": hex(site), "owner": hex(owner), "listing_region": hex(region[site])})
        two_hop_sites.add(site)

    com = rows(folder / "code/s21-com-binding.csv")
    com_sites = set()
    factories = Counter()
    dispatch_names = {}
    for row in com:
        site, owner, slot = (int(row[key], 16) for key in ("rva", "owner", "slot_index"))
        insn = decode(site)
        require(insn.mnemonic == "call" and insn.operands[0].type == X86_OP_MEM
                and insn.operands[0].mem.disp == slot and MEMBERS.get(slot) == row["member"],
                f"COM slot at {site:#x}")
        factory, caller = re.search(r"factory (0x\w+) via (0x\w+)", row["detail"]).groups()
        call = decode(int(caller, 16))
        require(call.mnemonic == "call" and call.operands[0].type == X86_OP_IMM
                and call.operands[0].imm == int(factory, 16) and region[site] == owner,
                f"factory call at {caller}")
        factories[factory] += 1
        source = source_span(coverage[owner]["source"], c_lines)
        dispatch_names[hex(owner)] = re.search(r'L"(Show[^"]*)"', source)[1]
        com_sites.add(site)

    factory_proof = {}
    for factory in factories:
        start = int(factory, 16)
        block = [decode(s) for s in sorted(starts) if region[s] == start]
        iid_load = [i for i in block if i.mnemonic == "lea" and i.op_str.startswith("r9,")
                    and rip_target(i, 1) == 0x8308]
        create = [i for i in block if i.mnemonic == "call" and
                  imports.get(rip_target(i), "").lower().endswith("!cocreateinstance")]
        require(len(iid_load) == len(create) == 1 and iid_load[0].address < create[0].address,
                f"IID / CoCreateInstance at {factory}")
        factory_proof[factory] = {"sites": factories[factory], "iid_load": hex(iid_load[0].address),
                                  "create": hex(create[0].address)}

    instruction_status = defaultdict(list)
    for row in rows(folder / "code/s21-instruction-status.csv"):
        site = int(row["rva"], 16)
        insn = decode(site)
        require(insn.bytes.hex() == row["bytes"] and insn.mnemonic == row["mnemonic"],
                f"instruction at {site:#x}")
        require((site in starts) == (row["in_candidate"] == "yes"), f"listing presence at {site:#x}")
        instruction_status[row["kind"]].append({"rva": hex(site), "listed": site in starts})

    ref_audit = {}
    for path in ["code/indirect.csv", "code/indirect-resolved.csv", "calls.csv"]:
        indirect = [r for r in rows(folder / path) if r["callee"].startswith("indirect@")]
        mismatches = []
        for row in indirect:
            actual = reference_site(row)
            expected = int(row["callee"].split("@")[1], 16)
            if actual != expected:
                mismatches.append({"expected": hex(expected), "ref": row["listing"],
                                   "actual": hex(actual) if actual is not None else None})
        ref_audit[path] = {"tested": len(indirect), "stale": len(mismatches), "examples": mismatches[:3]}

    guard = {int(r["rva"], 16) for r in rows(folder / "code/guardcf-sites.csv")}
    guard_refs = {reference_site(r) for r in calls if "GuardCF" in r["callee"]}
    register = {int(r["call_rva"], 16) for r in rows(folder / "code/register-operands.csv")}
    unresolved = {reference_site(r) for r in calls if r["class"] == "unresolved"}
    other = unresolved - com_sites - guard - register
    other_owners = Counter(hex(region[s]) for s in other)
    names = ["s21-started.md", "s21-submission.md", "coverage.csv", "native-functions.csv", "calls.csv"]
    return {
        "original_sha256": ORIGINAL_SHA256, "candidate_hashes": {name: digest(folder / name) for name in names},
        "listing_rows_checked": len(address), "call_classes": dict(Counter(r["class"] for r in calls)),
        "direct_iat": {"sites": len(direct), "match_main": direct_matches},
        "two_hop": {"verified_original_and_main": len(two_hop_sites), "rows": len(two_hop),
                    "annex_primary_class": dict(Counter(r["primary_class"] for r in two_hop)),
                    "owner_region_differences": region_diff},
        "com": {"unique_sites": len(com_sites), "members": dict(Counter(r["member"] for r in com)),
                "blank_impl": sum(not r["impl_address"] for r in com),
                "factory_iid": str(uuid.UUID(bytes_le=image[0x8308:0x8318])),
                "factories": factory_proof, "dispatch_names_in_candidate_c": dispatch_names},
        "instruction_rows": dict(instruction_status), "indirect_listing_refs": ref_audit,
        "remaining_unresolved": {"guard_annex_matches_main": len(guard & guard_refs),
                                 "register_sites": sorted(map(hex, register)), "other_memory_sites": len(other),
                                 "other_by_listing_region": dict(sorted(other_owners.items())),
                                 "other_rvas": [hex(s) for s in sorted(other)]},
        "submitted_metrics": json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig")),
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("candidate", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    report = json.dumps(verify(args.original, args.candidate), indent=2, ensure_ascii=False) + "\n"
    if args.output:
        args.output.write_text(report, encoding="utf-8")
    else:
        print(report, end="")


if __name__ == "__main__":
    main()
