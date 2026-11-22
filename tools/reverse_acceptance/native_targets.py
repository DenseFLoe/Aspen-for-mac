"""Check submitted indirect transfers and verify supported indirect CALL target claims."""
import bisect
from collections import Counter, defaultdict
import hashlib
import json
import re

if __package__:
    from . import native_sites, target_witness
else:
    import native_sites
    import target_witness


SCHEMA = "indirect-call-targets-v1"
LEGACY = "code/indirect-resolved.csv"
INDEX = "code/indirect.csv"
CLAIMS = "target-evidence.json"
FIELDS = {"kind", "caller", "callee", "class", "listing", "note"}
RVA = re.compile(r"0x[0-9a-f]{1,8}", re.I)
SITE = re.compile(r"indirect@(0x[0-9a-f]{1,8})", re.I)
BASE_HINT = re.compile(r"base\s+([a-z0-9]+)(?:\s+(.*))?", re.I)
TRANSFER_LABEL = re.compile(r"(?:^|\()\s*(callq?|jmpq?)\s+\S", re.I)


def address(value):
    if not isinstance(value, str) or not RVA.fullmatch(value):
        raise ValueError("expected a hexadecimal 32-bit RVA")
    return int(value, 16)


def unique_object(pairs):
    out = {}
    for key, val in pairs:
        if key in out:
            raise ValueError("duplicate key: " + key)
        out[key] = val
    return out


def listed_sites(ref, by_file):
    parsed = native_sites.parse_ref(ref)
    if not parsed or parsed[0] not in by_file:
        return set()
    path, lo, hi = parsed
    lines, addresses, last = by_file[path]
    if hi > last:
        return set()
    return set(addresses[bisect.bisect_left(lines, lo):bisect.bisect_right(lines, hi)])


def operand(ins, pe, x86, fmt):
    if ins.op0_kind == x86.OpKind.REGISTER:
        return {"kind": "register", "register": fmt.format_register(ins.op0_register).lower()}
    if ins.op0_kind != x86.OpKind.MEMORY:
        return {"kind": "other"}
    def register(value):
        return None if value == x86.Register.NONE else fmt.format_register(value).lower()
    out = {"kind": "memory", "base": register(ins.memory_base), "index": register(ins.memory_index),
           "scale": ins.memory_index_scale, "segment_override": register(ins.segment_prefix)}
    if ins.is_ip_rel_memory_operand:
        out["slot_rva"] = hex(ins.ip_rel_memory_address - pe.OPTIONAL_HEADER.ImageBase)
    else:
        # iced represents a sign-extended displacement as an unsigned 64-bit value.
        disp = ins.memory_displacement
        out["displacement"] = disp if disp < 1 << 63 else disp - (1 << 64)
    return out


def label(value):
    """A concrete target identifier in the supported CSV spellings."""
    if not isinstance(value, str):
        return None
    value = value.strip()
    match = re.fullmatch(r"(?:rva\s*[:=]?\s*)?(0x[0-9a-f]{1,8})", value, re.I)
    if match:
        return ("rva", int(match[1], 16))
    if re.fullmatch(r"[^\s!]+![^\s!]+", value):
        dll, symbol = value.split("!")
        return ("import", dll.casefold(), symbol)
    return None


def read_legacy(root, path, by_file, records, managed, report):
    fields = FIELDS | ({"resolved", "verdict"} if path == LEGACY else set())
    native_rows = managed_rows = False
    for line, row in native_sites.csv_rows(root, path, fields, numbered=True):
        where = f"{path}#L{line}"
        kind = row["kind"].strip().casefold()
        if kind == "method":
            managed.append({"source": where, "caller": row["caller"], "callee": row["callee"],
                            "listing": row["listing"]})
            managed_rows = True
            continue
        native_rows = True
        hint = SITE.fullmatch(row["callee"].strip())
        sites = listed_sites(row["listing"], by_file)
        if hint:
            site = address(hint[1])
        elif len(sites) == 1:
            site, = sites
        else:
            report("inconclusive", "indirect_target_site_unverified", "Cannot identify a unique native transfer site.", line=where)
            continue
        item = {"source": where, "listing": row["listing"], "callee": row["callee"],
                "classification": row["class"], "note": row["note"]}
        if path == LEGACY:
            item.update(verdict=row["verdict"].strip().lower(), resolved=row["resolved"].strip())
        try:
            item["owner"] = address(row["caller"].strip())
        except ValueError:
            item["owner"] = None
        if kind != "native" or item["owner"] is None:
            item["issue"] = "invalid_identity"
        elif sites and site not in sites:
            item["issue"] = "listing_points_to_different_site"
        elif sites != {site}:
            item["issue"] = "listing_site_not_unique"
        records[site][path].append(item)
    return native_rows or not managed_rows


def read_claims(root, original, records, report):
    path = native_sites.safe_path(root, CLAIMS)
    with path.open(encoding="utf-8-sig") as f:
        doc = json.load(f, object_pairs_hook=unique_object)
    if not isinstance(doc, dict) or doc.keys() != {"schema", "original_sha256", "claims"} or doc["schema"] != SCHEMA:
        raise ValueError("invalid indirect-call target evidence schema")
    if doc["original_sha256"] != hashlib.sha256(original).hexdigest():
        report("fail", "indirect_target_original_mismatch", "Evidence is bound to a different original.", line=CLAIMS)
        return
    if not isinstance(doc["claims"], list):
        raise ValueError("claims must be an array")
    for index, claim in enumerate(doc["claims"]):
        where = f"{CLAIMS}#/claims/{index}"
        try:
            if not isinstance(claim, dict):
                raise ValueError("claim must be an object")
            site = address(claim.get("site"))
        except ValueError as exc:
            report("fail", "indirect_target_invalid_claim", str(exc), line=where)
            continue
        indexed = {"source": where, "claim": claim}
        records[site][CLAIMS].append(indexed)
        try:
            required = {"site", "owner", "target", "external"}
            if not required <= claim.keys() or claim.keys() - required - {"witness"}:
                raise ValueError("incorrect claim fields")
            indexed["owner"] = address(claim["owner"])
            internal, external = claim["target"], claim["external"]
            if internal is not None:
                address(internal)
                if external is not None:
                    raise ValueError("claim specifies both an internal and an imported target")
            elif external is not None:
                if not isinstance(external, dict) or external.keys() != {"iat_rva", "import"}:
                    raise ValueError("expected external import and iat_rva")
                address(external["iat_rva"])
                if not label(external["import"]) or label(external["import"])[0] != "import":
                    raise ValueError("expected DLL!symbol or DLL!#ordinal")
            if claim.get("witness") is not None and not isinstance(claim["witness"], dict):
                raise ValueError("witness must be an object")
        except ValueError as exc:
            indexed["issue"] = str(exc)


def site_record(site, primary, entries, proven_starts, report):
    row = {"site_rva": hex(site), "main_rows": [{**r, "owner": hex(r["owner"])} for r in primary],
           "original_boundary_confirmed": site in proven_starts, "operand": None,
           "evidence": dict(entries), "decision": "unresolved", "confirmed_target": None, "reasons": []}

    def flag(code, message, source=None, level="fail"):
        row["reasons"].append(code)
        if level == "fail":
            row["decision"] = "contradicted"
        report(level, code, message, site, source)

    return row, flag


def check_registration(site, primary, entries, owner_set, mnemonic, flag):
    for item in primary:
        hint = SITE.fullmatch(item["callee"].strip())
        if hint and address(hint[1]) != site:
            flag("indirect_target_site_mismatch", "Main-table transfer address differs from its listing.", item["source"])
    for path, records in entries.items():
        if len(records) != 1:
            flag("indirect_target_duplicate", "Duplicate site records in " + path, records[-1]["source"])
        for record in records:
            source = record["source"]
            if "issue" in record:
                uncertain = record["issue"] == "listing_site_not_unique"
                flag("indirect_target_evidence_reference", record["issue"], source,
                     "inconclusive" if uncertain else "fail")
            if owner_set is not None and record.get("owner") not in owner_set:
                flag("indirect_target_owner_mismatch", "Evidence owner disagrees with the owner at this site.", source)
    for record in [*primary, *entries.get(INDEX, []), *entries.get(LEGACY, [])]:
        labels = sorted({match.casefold().removesuffix("q") for match in TRANSFER_LABEL.findall(record["callee"])})
        if any(declared != mnemonic for declared in labels):
            flag("indirect_target_transfer_kind_mismatch",
                 f"CSV labels the transfer {'/'.join(labels).upper()}. The original instruction is {mnemonic.upper()}.",
                 record["source"])


def audit(root, original, pe, bits, x86, instructions, owners, main_rows, report, result, proven_starts, by_file):
    evidence = defaultdict(lambda: defaultdict(list))
    supplied = set()
    managed = []
    # A separately supplied index preserves sites even if removed from the resolution table or calls.csv.
    for path in (INDEX, LEGACY, CLAIMS):
        if not native_sites.safe_path(root, path).is_file():
            continue
        supplied.add(path)
        try:
            if path == CLAIMS:
                read_claims(root, original, evidence, report)
            elif not read_legacy(root, path, by_file, evidence, managed, report):
                supplied.remove(path)
        except (ValueError, OSError, RecursionError, native_sites.csv.Error) as exc:
            report("inconclusive" if isinstance(exc, OSError) else "fail", "indirect_target_evidence_unreadable",
                   str(exc), line=path)
    sites = set(evidence) | {site for site, rows in main_rows.items() if any(not r["known_iat"] for r in rows)}
    rows_out = []
    jumps = []
    fmt = x86.Formatter(x86.FormatterSyntax.INTEL)
    ranges = defaultdict(set)
    for func in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ()):
        ranges[func.struct.BeginAddress].add(func.struct.EndAddress)
    for site in sorted(sites):
        entries = evidence[site]
        primary = main_rows.get(site, [])
        ins = instructions.get(site)
        if ins is not None and ins.flow_control == x86.FlowControl.INDIRECT_BRANCH:
            legacy_entries = {path: records for path, records in entries.items() if path != CLAIMS}
            if primary or legacy_entries:
                jump, flag = site_record(site, primary, legacy_entries, proven_starts, report)
                jumps.append(jump)
                jump["original_mnemonic"] = "jmp"
                jump["operand"] = operand(ins, pe, x86, fmt)
                jump["original_bytes"] = pe.get_data(site, ins.len).hex(" ")
                jump_owners = {r["owner"] for r in primary} or owners.get(site) or None
                check_registration(site, primary, legacy_entries, jump_owners, "jmp", flag)
                if not jump["reasons"]:
                    jump["reasons"].append("jump_target_resolution_outside_scope")
            if CLAIMS not in entries:
                continue
            # Structured evidence claims CALLs even when it cites a genuine JMP.
            entries, primary = {CLAIMS: entries[CLAIMS]}, []
        row, flag = site_record(site, primary, entries, proven_starts, report)
        rows_out.append(row)

        if ins is None or ins.flow_control != x86.FlowControl.INDIRECT_CALL:
            flag("indirect_target_not_a_verified_call", "No matching original-backed indirect CALL at the cited address.",
                 level="inconclusive" if ins is None else "fail")
            continue
        op = row["operand"] = operand(ins, pe, x86, fmt)
        row["original_bytes"] = pe.get_data(site, ins.len).hex(" ")
        owner_set = {r["owner"] for r in primary}
        if len(primary) != 1:
            flag("indirect_target_primary_registration", f"Expected one calls.csv control row, observed {len(primary)}.")
        if owners.get(site) and not owner_set <= owners[site]:
            flag("indirect_target_owner_unverified", "Primary owner disagrees with the submitted listing owner.",
                 level="inconclusive")
        check_registration(site, primary, entries, owner_set, "call", flag)
        if any(r["classification"] == "unresolved" for r in primary):
            row["missing_legacy_records"] = [p for p in (INDEX, LEGACY) if p in supplied and not entries.get(p)]
        legacy_labels = [r["callee"] for r in [*primary, *entries.get(INDEX, [])] if label(r["callee"])]
        for e in entries.get(LEGACY, []):
            hint = BASE_HINT.fullmatch(e["resolved"])
            if hint:
                e["base_matches_operand"] = op.get("base") == hint[1].casefold()
                if not e["base_matches_operand"]:
                    flag("indirect_target_base_mismatch", "Claimed base register differs from the cited instruction.", e["source"],
                         "fail" if site in proven_starts else "inconclusive")
                elif hint[2]:
                    e["definition_status"] = "no_instruction_address_supplied"
            if label(e["callee"]):
                legacy_labels.append(e["callee"])
            if label(e["resolved"]):
                legacy_labels.append(e["resolved"])
            elif not hint and e["resolved"]:
                e["basis_status"] = "unverified_free_text"
            if e["verdict"] not in ("", "unresolved") and not (label(e["resolved"]) or label(e["callee"])):
                e["verdict_status"] = "no_concrete_target_declared"
        if len({label(v) for v in legacy_labels}) > 1:
            flag("indirect_target_claim_conflict", "Submitted CSV records identify different targets.")
        claims = entries.get(CLAIMS, [])
        submitted = claims[0] if len(claims) == 1 and "issue" not in claims[0] else None
        # Old CSVs can name an import without JSON. Its exact slot is part of the
        # cited original CALL, so the PE import directory can check that claim.
        if not claims and len(primary) == 1 and op.get("slot_rva") and legacy_labels:
            ident = legacy_labels[0]
            if label(ident)[0] == "import":
                slot = op["slot_rva"]
                entry = primary[0]["owner"]
                submitted = {"source": "CSV claim and cited original CALL operand", "owner": entry,
                             "claim": {"site": hex(site), "owner": hex(entry), "target": None,
                                       "external": {"iat_rva": slot, "import": ident},
                                       "witness": {"kind": "iat", "slot_rva": slot}}}
        if submitted is not None:
            claim = submitted["claim"]
            target = (claim["external"] or {}).get("import") or claim["target"]
            if any(label(v) != label(target) for v in legacy_labels) and target is not None:
                flag("indirect_target_claim_conflict", "Main or legacy target and structured target disagree.", submitted["source"])
            witness = claim.get("witness")
            if witness:
                if site not in proven_starts:
                    row["reasons"].append("original_call_boundary_unverified")
                    continue
                if witness.get("kind") in ("readonly_table", "guard_dispatch"):
                    definition = witness.get("definition_rva")
                    if isinstance(definition, str) and RVA.fullmatch(definition):
                        definition = int(definition, 16)
                    if type(definition) is not int or definition not in proven_starts:
                        row["reasons"].append("original_definition_boundary_unverified")
                        continue
                entry = submitted["owner"]
                containing = {start for start, ends in ranges.items() if any(start <= site < stop for stop in ends)}
                if containing and entry not in containing:
                    flag("indirect_target_original_owner", "Original exception metadata assigns the site to another owner.",
                         submitted["source"])
                elif len(containing) > 1 or (not containing and entry != pe.OPTIONAL_HEADER.AddressOfEntryPoint):
                    flag("indirect_target_original_owner_unverified", "Cannot confirm a unique original owner for this claim.",
                         submitted["source"], "inconclusive")
                ends = ranges.get(entry, set())
                end = next(iter(ends)) if len(ends) == 1 else site + ins.len
                proof = target_witness.verify(pe, entry, end, site, claim, x86)
                row["witness_result"] = proof
                if proof["status"] == "fail":
                    flag(proof["code"], proof["message"], submitted["source"])
                elif proof["status"] == "pass" and not row["reasons"]:
                    row.update(decision="confirmed", confirmed_target={"target": proof.get("target"), "external": proof.get("external"),
                               "binding_scope": proof["binding_scope"], "whole_program_unique": False})
                else:
                    row["reasons"].append(proof["code"] if proof["status"] != "pass" else "scope_or_registration_unverified")
        if row["decision"] == "unresolved" and not row["reasons"]:
            row["reasons"].append("target_witness_required")
    counts = Counter(row["decision"] for row in rows_out)
    result["indirect_call_targets"] = {
        "scope": "Submitted indirect CALL targets. A static import identity or an owner-entry proof has the scope recorded per site.",
        "sites": rows_out, "counts": {key: counts[key] for key in ("confirmed", "unresolved", "contradicted")}}
    jump_counts = Counter(row["decision"] for row in jumps)
    result["indirect_jump_targets"] = {
        "scope": "Submitted indirect JMP sites. This check verifies registration and instruction kind.",
        "sites": jumps, "counts": {key: jump_counts[key] for key in ("unresolved", "contradicted")}}
    result["managed_indirect_records"] = {
        "scope": "Managed records declared in legacy indirect transfer tables. IL verification is outside this check.",
        "count": len(managed), "records": managed}
    if counts["unresolved"] and supplied:
        report("inconclusive", "indirect_call_targets_unresolved",
               f"{counts['unresolved']} submitted call sites still lack conclusive target evidence.")
