"""Verify submitted caller -> jump thunk -> PE import routes."""
from collections import Counter, defaultdict
import re

if __package__:
    from . import native_sites
else:
    import native_sites


TABLE = "code/import-callers.csv"
FIELDS = {"group", "rva", "primary_class", "primary_callee", "in_candidate", "owner", "detail"}
RVA = r"0x[0-9a-fA-F]{1,8}"
IDENT = r"[^\s!]+![^\s!]+"
DETAIL = re.compile(rf"({RVA})\s*->\s*IAT\s+({RVA})\s*->\s*({IDENT})", re.I)


def import_identity(label):
    dll, _, symbol = label.strip().partition("!")
    return dll.casefold(), symbol


def hex_or_none(value):
    return hex(value) if value is not None else None


def claims(root, report):
    submitted = defaultdict(list)
    for number, row in native_sites.csv_rows(root, TABLE, FIELDS, numbered=True):
        where = f"{TABLE}#L{number}"
        match = re.fullmatch(RVA, row["rva"].strip(), re.I)
        if not match:
            report("fail", "import_route_invalid_site", "Expected a hexadecimal call-site RVA.", line=where)
            continue
        site = int(match[0], 16)
        owner = row["owner"].strip()
        detail = DETAIL.fullmatch(row["detail"].strip())
        if row["group"] != "import-callers" or not detail or (owner and not re.fullmatch(RVA, owner, re.I)):
            report("fail", "import_route_invalid_claim", "Expected an owner RVA or blank and a thunk -> IAT -> DLL!symbol route.",
                   site, where)
            submitted[site].append({"source": where, "detail": row["detail"], "valid": False})
            continue
        submitted[site].append({"source": where, "valid": True, "owner_rva": hex(int(owner, 16)) if owner else None,
                                "thunk_rva": hex(int(detail[1], 16)), "iat_rva": hex(int(detail[2], 16)),
                                "import": detail[3], "primary_class": row["primary_class"],
                                "primary_callee": row["primary_callee"], "in_candidate": row["in_candidate"]})
    return submitted


def evidence(site, pe, bits, x86, decode, slot_of, imports):
    """Decode an exact site and its actual direct operand, without searching for another path."""
    base = pe.OPTIONAL_HEADER.ImageBase
    ins = decode(site)
    out = {"site_rva": hex(site), "instruction": None, "thunk_rva": None, "thunk_instruction": None,
           "iat_rva": None, "import": None}
    if ins is None or ins.is_invalid:
        return out, None
    out["instruction"] = {"text": str(ins), "bytes": pe.get_data(site, ins.len).hex(" ")}
    if (ins.flow_control not in (x86.FlowControl.CALL, x86.FlowControl.UNCONDITIONAL_BRANCH)
            or ins.op0_kind not in (x86.OpKind.NEAR_BRANCH16, x86.OpKind.NEAR_BRANCH32, x86.OpKind.NEAR_BRANCH64)):
        return out, None
    thunk = ins.near_branch_target - base
    out["thunk_rva"] = hex(thunk)
    jump = decode(thunk)
    if jump is None or jump.is_invalid:
        return out, thunk
    out["thunk_instruction"] = {"text": str(jump), "bytes": pe.get_data(thunk, jump.len).hex(" ")}
    if (jump.mnemonic != x86.Mnemonic.JMP or jump.flow_control != x86.FlowControl.INDIRECT_BRANCH
            or jump.op0_kind != x86.OpKind.MEMORY or x86.MemorySizeExt.size(jump.memory_size) != bits // 8):
        return out, thunk
    slot = slot_of(jump)
    out["iat_rva"] = hex_or_none(slot)
    if slot in imports:
        out["import"] = "!".join(imports[slot])
    return out, thunk


def audit(root, pe, bits, x86, decode, slot_of, imports, owners, proven, by_file, primary, report):
    try:
        submitted = claims(root, report)
    except (ValueError, OSError, native_sites.csv.Error) as exc:
        report("fail" if not isinstance(exc, OSError) else "inconclusive", "import_routes_unreadable", str(exc), line=TABLE)
        return {"sites": [], "counts": {"confirmed": 0, "unresolved": 0, "contradicted": 0}}
    if not submitted:
        report("inconclusive", "import_routes_empty", "No valid caller addresses were submitted.", line=TABLE)

    listings = defaultdict(list)
    for file, (line_numbers, addresses, _) in by_file.items():
        for line, site in zip(line_numbers, addresses):
            if site in submitted:
                listings[site].append(f"{file}#L{line}")
    unwind = [(r.struct.BeginAddress, r.struct.EndAddress)
              for r in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())]
    directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
    if len(directories) <= 3 or directories[3].Size != 12 * len(unwind):
        unwind = []
    rows = []
    for site, records in sorted(submitted.items()):
        main = primary.get(site, [])
        actual, thunk = evidence(site, pe, bits, x86, decode, slot_of, imports)
        containing = [entry for entry, end in unwind if entry <= site < end]
        actual["owner_rva"] = hex_or_none(containing[0]) if len(containing) == 1 else None
        caller_proven = site in proven
        thunk_proven = thunk in proven
        result = {"site_rva": hex(site), "decision": "unresolved", "route_status": "unresolved",
                  "owner_status": "unresolved", "reported": records, "original": actual, "reasons": [],
                  "site_boundary_confirmed": caller_proven, "thunk_boundary_confirmed": thunk_proven,
                  "verified_listings": listings.get(site, []),
                  "listing_owner_rvas": [hex(rva) for rva in sorted(owners.get(site, ()))],
                  "main_rows": main}
        rows.append(result)
        if len(records) != 1 or not records[0]["valid"]:
            result["decision"] = "contradicted"
            result["reasons"].append("duplicate_site" if len(records) != 1 else "invalid_claim")
            if len(records) != 1:
                report("fail", "import_route_duplicate", "Multiple claims for the same caller RVA.", site, records[-1]["source"])
            continue

        claim, = records
        if not main:
            result["main_registration"] = "absent"
        elif actual["import"] is None:
            result["main_registration"] = "unverified"
        else:
            iid = import_identity(actual["import"])
            result["main_registration"] = ("matches_original" if len(main) == 1 and main[0]["classification"] == "external"
                                           and import_identity(main[0]["callee"]) == iid else "differs_from_original")

        differences = []
        for field in ("thunk_rva", "iat_rva", "import"):
            a, given = actual[field], claim[field]
            same = a == given if field != "import" or a is None else import_identity(a) == import_identity(given)
            if a is not None and not same:
                differences.append({"field": field, "original": a, "reported": given,
                                    "boundary_confirmed": caller_proven and (field == "thunk_rva" or thunk_proven)})
        result["route_differences"] = differences
        certified = [d for d in differences if d["boundary_confirmed"]]
        if caller_proven and thunk is None:
            result["route_status"] = "contradicted"
            result["reasons"].append("original_caller_is_not_direct_call_or_jump")
            report("fail", "import_route_caller_kind", "Original caller is neither a direct CALL nor an unconditional direct JMP.",
                   site, claim["source"])
        elif certified:
            result["route_status"] = "contradicted"
            for difference in certified:
                code = "import_route_" + difference["field"] + "_mismatch"
                result["reasons"].append(code)
                report("fail", code,
                       f"Original {difference['field']} {difference['original']} differs from submitted {difference['reported']}.",
                       site, claim["source"])
        elif not (caller_proven and thunk_proven):
            result["reasons"].append("original_route_boundary_unverified")
        elif not actual["import"]:
            result["reasons"].append("original_thunk_or_import_unverified")
        elif not listings.get(site):
            result["reasons"].append("verified_caller_listing_missing")
        else:
            result["route_status"] = "confirmed"

        if not claim["owner_rva"] or not actual["owner_rva"]:
            result["reasons"].append("owner_not_submitted" if not claim["owner_rva"] else "original_owner_unverified")
        elif claim["owner_rva"] == actual["owner_rva"]:
            result["owner_status"] = "confirmed"
        else:
            result["owner_status"] = "contradicted"
            result["reasons"].append("import_route_owner_mismatch")
            report("fail", "import_route_owner_mismatch",
                   f"Original exception metadata assigns {actual['owner_rva']} instead of {claim['owner_rva']}.",
                   site, claim["source"])
        if "contradicted" in (result["route_status"], result["owner_status"]):
            result["decision"] = "contradicted"
        elif result["route_status"] == result["owner_status"] == "confirmed":
            result["decision"] = "confirmed"

    counts = Counter(row["decision"] for row in rows)
    chain = Counter(row["route_status"] for row in rows)
    missing = sum(r.get("main_registration") == "absent" for r in rows)
    if counts["unresolved"]:
        report("inconclusive", "import_routes_unresolved",
               f"{counts['unresolved']} submitted routes lack independent boundary, owner or import evidence.", line=TABLE)
    if missing:
        report("inconclusive", "import_routes_not_in_main",
               f"{missing} submitted routes have no calls.csv control row; see per-site evidence.", line=TABLE)
    return {"scope": "Submitted direct CALL or JMP -> one indirect JMP -> static PE import identity.",
            "sites": rows, "counts": {s: counts[s] for s in ("confirmed", "unresolved", "contradicted")},
            "chain_counts": {s: chain[s] for s in ("confirmed", "unresolved", "contradicted")},
            "unregistered_sites": missing}
