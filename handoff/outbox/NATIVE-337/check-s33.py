"""Compare NATIVE-337 s33 annexes and receipt with the fixed original and current tables."""

import argparse
from collections import Counter, defaultdict
import hashlib
from importlib.util import module_from_spec, spec_from_file_location
import json
from pathlib import Path
import re
import struct

import capstone
from capstone import x86
import pefile


def compare(original, item, trusted):
    spec = spec_from_file_location("s21", trusted)
    earlier = module_from_spec(spec)
    spec.loader.exec_module(earlier)
    baseline = earlier.verify(original, item)
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    addresses, owners = earlier.listing(item / "code/native.asm", image)
    reverse_addresses = {site: line for line, site in addresses.items()}
    imports = {}
    for library in pe.DIRECTORY_ENTRY_IMPORT:
        for symbol in library.imports:
            label = f"#{symbol.ordinal}" if symbol.import_by_ordinal else symbol.name.decode()
            imports[symbol.address - pe.OPTIONAL_HEADER.ImageBase] = library.dll.decode() + "!" + label

    def decode(site):
        return next(decoder.disasm(image[site:site + 16], site, count=1))

    def asm_site(reference):
        match = re.fullmatch(r"code/native\.asm#L(\d+)(?:-L\d+)?", reference)
        return addresses.get(int(match[1])) if match else None

    def table(name):
        return earlier.rows(item / name)

    def pdata(site):
        return next((entry for entry in pe.DIRECTORY_ENTRY_EXCEPTION
                     if entry.struct.BeginAddress <= site < entry.struct.EndAddress), None)

    def original_host(site):
        entry = pdata(site)
        return entry.struct.BeginAddress if entry else 0

    calls = table("calls.csv")
    by_site = defaultdict(list)
    for number, row in enumerate(calls, 2):
        by_site[asm_site(row["listing"])].append((number, row))
    counts, examples, thunks, mismatches = Counter(), [], Counter(), []
    seen = set()
    s33 = table("code/s33-two-hop.csv")
    for row in s33:
        site = int(row["site"], 16)
        assert site not in seen, row
        seen.add(site)
        caller = decode(site)
        assert caller.mnemonic in ("call", "jmp") and caller.operands[0].type == x86.X86_OP_IMM
        thunk = caller.operands[0].imm
        jump = decode(thunk)
        slot = earlier.rip_target(jump)
        assert jump.mnemonic == "jmp" and slot in imports
        symbol = imports[slot]
        matching_rows = [number for number, call in by_site[site]
                         if call["class"] == "external" and call["callee"] == symbol]
        want = {
            "first_hop": thunk, "iat_slot": slot, "import_symbol": symbol,
            "main_class": "external", "original_host": original_host(site),
            "candidate_owner": owners[site], "asm": site, "calls_row": matching_rows,
        }
        have = {
            **{key: int(row[key], 16) if row[key] else None
               for key in ("first_hop", "iat_slot", "candidate_owner")},
            "original_host": int(row["original_host"], 16) if row["original_host"] else 0,
            "import_symbol": row["import_symbol"], "main_class": row["main_class"],
            "asm": asm_site(row["asm"]), "calls_row": int(row["calls_row"]) if row["calls_row"] else None,
        }
        for field in want:
            counts[field] += have[field] in want[field] if field == "calls_row" else have[field] == want[field]
        different = {field: {"candidate": have[field], "original_or_listing": want[field]}
                     for field in want if field != "calls_row" and have[field] != want[field]}
        if different:
            mismatches.append({"site": hex(site), "fields": different,
                               "original_instruction": caller.bytes.hex(),
                               "actual_thunk_instruction": jump.bytes.hex()})
        counts["main_symbol_matches"] += bool(matching_rows)
        counts["rows"] += 1
        thunks[thunk] += 1
        if site in {0x106c, 0x1072, 0x12da} or want["candidate_owner"] != have["candidate_owner"]:
            examples.append({
                "site": hex(site), "first_hop": hex(thunk), "iat_slot": hex(slot), "symbol": symbol,
                "expected_original_host": hex(want["original_host"]), "expected_listing_owner": hex(want["candidate_owner"]),
                "claimed_listing_owner": row["candidate_owner"], "asm_line": reverse_addresses[site],
                "expected_calls_rows": matching_rows, "claimed_calls_row": row["calls_row"],
            })
    assert seen == {int(r["rva"], 16) for r in table("code/s21-two-hop.csv")}

    dual = []
    for row in table("code/s33-dual-host.csv"):
        site = int(row["site"], 16)
        entry = pdata(site)
        expected = [entry.struct.BeginAddress, entry.struct.EndAddress]
        dual.append({
            "site": hex(site), "original_host_matches": [int(v, 16) for v in row["original_host"].split("-")] == expected,
            "owner_matches": int(row["candidate_owner"], 16) == owners[site],
            "claimed_owner": row["candidate_owner"], "actual_owner": hex(owners[site]),
            "asm_matches": asm_site(row["asm"]) == site,
            "main_table_rows_at_site": [number for number, call in by_site[site]],
        })

    def check_annotation(name, key):
        fields = Counter()
        detail = []
        for row in table("code/" + name):
            site = int(row[key], 16)
            insn = decode(site)
            assert insn.mnemonic == "call" and insn.operands[0].type == x86.X86_OP_MEM
            disp = insn.operands[0].mem.disp
            fields["rows"] += 1
            fields["slot_matches"] += disp == int(row["disp"], 16)
            fields["asm_line_matches"] += asm_site(row["asm_line"]) == site
            fields["calls_row_matches"] += any(int(row["calls_row"]) == number and call["class"] == "unresolved"
                                               and int(call["callee"].split("@")[1], 16) == site
                                               for number, call in by_site[site])
            if "member" in row:
                fields["member_matches"] += row["member"] == earlier.MEMBERS[disp]
                fields["recovery_nonblank"] += bool(row["recovery"].strip())
                if row["member_fixed"].startswith("yes"):
                    detail.append({"site": hex(site), "flag": row["member_fixed"], "member": row["member"]})
            else:
                source = int(row["source_insn_rva"], 16)
                load = decode(source)
                assert load.mnemonic == "mov" and load.operands[0].reg == x86.X86_REG_RAX
                assert load.operands[1].type == x86.X86_OP_MEM
                assert source < site and insn.operands[0].mem.base == x86.X86_REG_RAX
                assert not any(x86.X86_REG_RAX in decode(p).regs_access()[1]
                               for p in reverse_addresses if source < p < site)
                detail.append({"site": hex(site), "source": hex(source), "load": load.op_str,
                               "slot": hex(disp), "asm_line": row["asm_line"], "calls_row": int(row["calls_row"])})
        return dict(fields), detail

    dispatch, dispatch_rows = check_annotation("s25-0x4706-dispatches.csv", "insn_rva")
    com, fixed = check_annotation("s25-idispatch-slots.csv", "site")
    fragment = pdata(0x4706)
    unwind = fragment.unwindinfo
    assert unwind.Flags & 4
    chain_pos = fragment.struct.UnwindData + 4 + 2 * ((unwind.CountOfCodes + 1) & ~1)
    chain = struct.unpack_from("<III", image, chain_pos)

    metrics = json.loads((item / "metrics.json").read_text(encoding="utf-8-sig"))
    computed = {
        "funcs": len(table("native-functions.csv")), "rows": len(table("coverage.csv")),
        "gaps": sum(row["state"] == "gap" for row in table("coverage.csv")),
        "calls_total": len(calls), **Counter(row["class"] for row in calls),
        "direct_iat": baseline["direct_iat"]["sites"], "indirect_annex": len(table("code/indirect.csv")),
        "two_hop_rows": len(s33), "com_rows": com["rows"], "dispatch_rows": dispatch["rows"],
    }
    metrics_error = {field: [metrics.get(field), value] for field, value in computed.items()
                     if metrics.get(field) != value}
    files = {"coverage_sha256": "coverage.csv", "calls_sha256": "calls.csv",
             "native_functions_sha256": "native-functions.csv"}
    sha_results = {name: metrics[field] == hashlib.sha256((item / name).read_bytes()).hexdigest()
                   for field, name in files.items()}
    submission = (item / "s33-submission.md").read_text(encoding="utf-8-sig")
    receipt_digests = re.findall(r"(?i)\b[a-f0-9]{64}\b", submission)
    return {
        "original_sha256": baseline["original_sha256"],
        "listing_instructions": baseline["listing_rows_checked"],
        "two_hop": dict(counts), "examples": examples, "mismatches": mismatches, "dual_host": dual,
        "thunks_used_at_more_than_five_sites": {hex(thunk): count for thunk, count in thunks.most_common()
                                               if count > 5},
        "com": com, "fixed_members": fixed, "com_factory_proof": baseline["com"]["factories"],
        "dispatch": dispatch, "dispatch_rows": dispatch_rows,
        "fragment": [hex(x) for x in (fragment.struct.BeginAddress, fragment.struct.EndAddress,
                                     fragment.struct.UnwindData)],
        "chained_parent": [hex(x) for x in chain],
        "metrics": metrics, "metrics_mismatches": metrics_error, "metrics_sha_matches": sha_results,
        "submission_digest_count": len(receipt_digests),
        "submission_claims_zero_iat": bool(re.search(r"\| IAT .*?\| 0 \|", submission)),
        "unresolved": baseline["remaining_unresolved"],
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("candidate", type=Path)
    parser.add_argument("--trusted-s21", type=Path, default=Path(__file__).with_name("check-s21.py"))
    args = parser.parse_args()
    result = compare(args.original, args.candidate, args.trusted_s21)
    print(json.dumps(result, indent=2))
    two_hop = result["two_hop"]
    fields = ("first_hop", "iat_slot", "import_symbol", "main_class", "original_host",
              "candidate_owner", "asm", "calls_row", "main_symbol_matches")
    annotations = (result["com"], result["dispatch"])
    valid = all(two_hop[field] == two_hop["rows"] for field in fields)
    valid &= all(row["owner_matches"] and row["original_host_matches"] and row["asm_matches"]
                 for row in result["dual_host"])
    valid &= all(row["rows"] == row["calls_row_matches"] == row["asm_line_matches"]
                 for row in annotations)
    valid &= not result["metrics_mismatches"] and all(result["metrics_sha_matches"].values())
    valid &= not result["submission_claims_zero_iat"]
    raise SystemExit(0 if valid else 2)
