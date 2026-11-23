"""Offline verification of submitted Aspen reverse-engineering results."""
import argparse
import csv
import hashlib
import importlib
import importlib.metadata
import io
import json
import os
import re
import stat
import sys
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
# Items are manually reviewed approvals, held alongside the verifier, never in the submission.
APPROVALS = json.loads((HERE / "accepted_archives.json").read_text(encoding="utf-8"))
EXIT = {"pass": 0, "fail": 1, "inconclusive": 2}
VERSION = "1.0"
IMPLEMENTATION = "1.9"
ARCHIVE_REPLAY_BASIS = "previous_whole_item_static_acceptance_replayed"
FRESH_BUILD_BASIS = "fresh_source_build_full_file_exact_and_item_evidence"
CFB_MAGIC = bytes.fromhex("d0cf11e0a1b11ae1")
HEX = re.compile(r"[0-9a-fA-F]{64}")
REGION_DELTA = re.compile(r"s[1-9][0-9]*/reassembly-delta\.json")
REFERENCE_TYPES = {"instruction_listing", "clr_thunks"}
SNAPSHOT = "773260c1033e524cebe000699409f5708bebfda0"
SOURCE_LISTS = {
    "plus": "97f64d168dbc33f6281233f59e411c0efe69e7224400bde58c76220b98b6d2c3",
    "properties": "8706fcc38d4d089e0bc18b97f4cc6a2ee732ffe0d0e166a18c8b220f750983b4",
    "shared": "834e6d51a86d531607e2ce630b173546fbe450fc4d13f9c12009e48f96f5b03d",
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def digest_file(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def finding(code, **fields):
    return {"code": code, **fields}


def section(scope, status, findings=(), **metrics):
    return {"scope": scope, "status": status, "findings": list(findings), "metrics": metrics}


def component(module, *args):
    # The dispatch table is verifier-owned. Candidate input never selects executable code.
    try:
        result = importlib.import_module(module).check(*args)
        if not isinstance(result.get("findings"), list):
            raise ValueError("missing verifier findings")
        declared = result.get("status")
        levels = {declared} if isinstance(declared, str) and declared in EXIT else set()
        malformed = not levels or not isinstance(result.get("scope"), str) or not isinstance(result.get("metrics"), dict)
        for issue in result["findings"]:
            if not isinstance(issue, dict) or not isinstance(issue.get("code"), str):
                malformed = True
                continue
            for key in ("severity", "status"):
                if key in issue:
                    if isinstance(issue[key], str) and issue[key] in EXIT:
                        levels.add(issue[key])
                    else:
                        malformed = True
        if malformed:
            # Discard unusable entries, keeping the findings we can substantiate.
            result["findings"] = [i for i in result["findings"] if isinstance(i, dict) and isinstance(i.get("code"), str)]
            result["findings"].append(finding("malformed_component_result"))
            result["scope"] = result.get("scope") if isinstance(result.get("scope"), str) else module
            result["metrics"] = result.get("metrics") if isinstance(result.get("metrics"), dict) else {}
            levels.add("inconclusive")
        strongest = "fail" if "fail" in levels else "inconclusive" if "inconclusive" in levels else "pass"
        if strongest != declared:
            result["findings"].append(finding("component_status_conflict", reported=declared,
                                              effective=strongest))
            result["status"] = strongest
        return result
    except Exception as exc:
        # Keep results from independent checks, including contradictions found earlier.
        return section(module, "inconclusive", [finding("check_unavailable", error=type(exc).__name__, message=str(exc))])


def strict_object(pairs):
    data = {}
    for key, value in pairs:
        if key in data:
            raise ValueError(f"duplicate JSON key: {key}")
        data[key] = value
    return data


def load_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"), object_pairs_hook=strict_object)


def digest_arg(value):
    if not isinstance(value, str) or not HEX.fullmatch(value):
        raise ValueError("expected a 64-digit SHA-256 from the reference inventory")
    return value.lower()


def tree_files(folder):
    """Reject links, junctions, special files and inaccessible subtrees."""
    def raise_error(error):
        raise error

    def check(path, directory):
        info = path.lstat()
        if (getattr(info, "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT
                or not (stat.S_ISDIR(info.st_mode) if directory else stat.S_ISREG(info.st_mode))):
            raise ValueError(f"unsupported linked or special entry: {path.name}")

    check(folder, True)
    files = {}
    for base, dirs, names in os.walk(folder, onerror=raise_error):
        for name in dirs:
            check(Path(base) / name, True)
        for name in names:
            path = Path(base) / name
            check(path, False)
            files[path.relative_to(folder).as_posix()] = path
    return files


def fingerprints(files):
    return {name: digest_file(files[name]) for name in sorted(files)}


def tree_id(hashes):
    # UTF-8 JSON sorted by relative POSIX filename, with no optional whitespace.
    return sha(json.dumps(hashes, sort_keys=True, ensure_ascii=False, separators=(",", ":")).encode("utf-8"))


def verifier_identity():
    # Bind a CLI report to the verifier inputs present at startup on this machine.
    names = ("verify.py", "accepted_archives.json", "coverage_table.py", "native_sites.py", "native_targets.py",
             "target_witness.py", "native_exports.py", "native_regions.py", "clr_fixups.py", "import_routes.py",
             "com_call_sites.py", "bounded_switches.py",
             "historical_listing.py", "fh4.py", "mixed_baseline.py", "callback_paths.py",
             "pe_resources.py", "version_resource.py", "fresh_cs.py", "compile_fresh_cs.ps1", "managed.py",
             "ManagedEvidence.cs", "coff.py", "office_vba.py", "office_forms.py", "biff_workbook.py",
             "office_project.py", "office_pcode.py")
    paths = {name: HERE / name for name in names}
    helper = "handoff/assignments/check-native-coverage.py"
    paths[helper] = HERE.parents[1] / helper
    hashes, unavailable = {}, []
    for name, path in paths.items():
        try:
            hashes[name] = digest_file(path)
        except OSError:
            unavailable.append(name)
    packages = {}
    for name in ("iced-x86", "pefile", "olefile", "oletools"):
        try:
            packages[name] = importlib.metadata.version(name)
        except importlib.metadata.PackageNotFoundError:
            packages[name] = None
    return dict(version=IMPLEMENTATION, source_tree_sha256=tree_id(hashes), unavailable_files=unavailable,
                python=sys.version.split()[0], packages=packages)


def replay(approval, files, hashes=None):
    if hashes is None:
        hashes = fingerprints(files)
    expected = approval["files"]
    missing = sorted(expected.keys() - hashes.keys())
    extra = sorted(hashes.keys() - expected.keys())
    changed = sorted(p for p in expected.keys() & hashes.keys() if hashes[p] != expected[p])
    differences = [finding(code, path=path) for code, paths in (
        ("approved_asset_missing", missing), ("asset_not_in_baseline", extra),
        ("approved_asset_digest_changed", changed)) for path in paths]
    return section("unchanged_previously_accepted_archive", "inconclusive" if differences else "pass",
                   differences, original_commit=approval["commit"], archive=approval["archive"],
                   expected=len(expected), matched=len(expected) - len(missing) - len(changed))


def fields_in(note):
    """One value per labelled line. Free prose never supplies an identity."""
    fields = {}
    for line in note.splitlines():
        match = re.fullmatch(r"([A-Za-z][A-Za-z0-9 -]*):[ \t]*(.*)", line.strip())
        if match:
            key, value = match.groups()
            key = key.casefold()
            if key in fields:
                raise ValueError("duplicate note field: " + key)
            fields[key] = value.strip()
    return fields


def file_notes(files, expected, product, original_path, build):
    """Verify the accompanying records for the fresh-C# whole-item route."""
    issues = []
    if not product or not original_path:
        return section("item_provenance_and_documentation", "inconclusive",
                       [finding("trusted_product_and_original_path_required")])
    name = original_path.replace("\\", "/").rsplit("/", 1)[-1]
    main_note = name + ".md"
    def match_note(path, contract):
        if path not in files:
            issues.append(finding("missing_note", path=path))
            return
        try:
            fields = fields_in(files[path].read_text(encoding="utf-8-sig"))
        except (UnicodeError, ValueError) as exc:
            issues.append(finding("invalid_note_fields", path=path, message=str(exc)))
            return
        for field, required in contract.items():
            if required is None or fields.get(field) != required:
                issues.append(finding("note_field_not_verified", field=field, path=path))

    match_note(main_note, {"product": product, "original path": original_path,
                           "original sha-256": expected, "assembly version": build.get("assembly_version"),
                           "verification profile": build.get("profile"), "scope": "whole-pe-static",
                           "evidence": "fresh-source-build", "static gaps": "none"})
    sources = sorted(p for p in files if p.startswith("fresh-cs/") and p.lower().endswith(".cs"))
    allowed = {main_note, *sources}
    for source in sources:
        short = str(Path(source).with_suffix(".md")).replace("\\", "/")
        explanations = {short, source + ".md"}
        allowed.update(explanations)
        existing = sorted(explanations & files.keys())
        compiled_hash = build.get("source_sha256", {}).get(Path(source).name)
        if compiled_hash != digest_file(files[source]):
            issues.append(finding("source_not_bound_to_compilation", path=source))
        for p in existing or [short]:
            match_note(p, {"source": source, "source sha-256": compiled_hash})
    for path in sorted(files.keys() - allowed):
        issues.append(finding("extra_artifact_outside_fresh_proof", path=path))
    return section("item_provenance_and_documentation", "inconclusive" if issues else "pass",
                   issues, sources=len(sources), product=product, original_path=original_path)


def provider_binding(path, expected):
    if path is None and expected is None:
        return None
    if path is None or expected is None:
        raise ValueError("supply both provider path and reference provider SHA-256")
    return Path(path), digest_arg(expected)


def reference_binding(path, expected):
    if path is None and expected is None:
        return None
    if path is None or expected is None:
        raise ValueError("supply both reference evidence path and its independent SHA-256")
    return Path(path), digest_arg(expected)


def read_reference_file(path, expected, delivery, limit):
    path = path.resolve(strict=True)
    if path.is_relative_to(delivery) or not path.is_file():
        raise ValueError("reference evidence must be outside the candidate delivery")
    with path.open("rb") as stream:
        contents = stream.read(limit + 1)
    if len(contents) > limit or sha(contents) != digest_arg(expected):
        raise ValueError(f"reference file does not match its trusted identity: {path.name}")
    return contents


def reference_material(binding, original_sha, delivery):
    path, claimed = binding
    delivery = delivery.resolve(strict=True)
    material = json.loads(read_reference_file(path, claimed, delivery, 1 << 20), object_pairs_hook=strict_object)
    if (not isinstance(material, dict) or material.keys() != {"schema", "original_sha256", "files"}
            or material["schema"] != "static-reference-evidence-v1" or material["original_sha256"] != original_sha
            or not isinstance(material["files"], dict) or not material["files"]
            or material["files"].keys() - REFERENCE_TYPES):
        raise ValueError("invalid reference manifest or original identity")
    output = {}
    for name, info in material["files"].items():
        if not isinstance(info, dict) or info.keys() != {"path", "sha256"} or not isinstance(info["path"], str):
            raise ValueError(f"invalid reference member: {name}")
        child = path.parent / info["path"]
        output[name] = read_reference_file(child, info["sha256"], delivery, 8 << 20)
    return output


def has_callback_witness(files):
    if "s13/disposition.csv" in files:
        return True
    packet = files.get("s13/evidence.json")
    if packet is None:
        return False
    try:
        if packet.stat().st_size > 8 << 20:
            return False
        doc = load_json(packet)
    except (OSError, ValueError):
        return False
    return isinstance(doc, dict) and bool(doc.keys() & {"optional_callback", "local_callback"})


def evaluate(original, expected, delivery, rebuilt=None, assembler=None, product=None, original_path=None, provider=None,
             delivery_sha256=None, reference_evidence=None):
    expected = digest_arg(expected)
    result = {"schema": VERSION, "scope": "whole_item_static", "expected_sha256": expected,
              "status": "inconclusive", "checks": [], "findings": []}
    if delivery_sha256 is not None:
        result["expected_delivery_sha256"] = delivery_sha256 = digest_arg(delivery_sha256)
    checks = result["checks"]
    notes = result["findings"]
    try:
        data = original.read_bytes()
    except OSError as exc:
        notes.append(finding("original_unavailable", message=str(exc)))
        return result
    result["observed_sha256"] = sha(data)
    if result["observed_sha256"] != expected:
        notes.append(finding("original_identity_mismatch"))
        return result
    if data.startswith(b"version https://git-lfs.github.com/spec/v1\n") or data.startswith(b"version https://git-lfs.github.com/spec/v1\r\n"):
        notes.append(finding("original_is_lfs_pointer"))
        return result
    if not delivery.is_dir():
        notes.append(finding("delivery_directory_unavailable"))
        return result
    try:
        files = tree_files(delivery)
        first_snapshot = fingerprints(files)
    except (OSError, ValueError) as exc:
        notes.append(finding("delivery_tree_unverifiable", message=str(exc)))
        return result
    result.update(delivery_sha256=tree_id(first_snapshot), delivery_files=len(files))
    if delivery_sha256 is not None and result["delivery_sha256"] != delivery_sha256:
        notes.append(finding("delivery_identity_mismatch", expected=delivery_sha256, observed=result["delivery_sha256"]))
        return result
    references = {}
    if reference_evidence is not None:
        result["reference_evidence_sha256"] = reference_evidence[1]
        try:
            references = reference_material(reference_evidence, expected, delivery)
        except (OSError, ValueError) as exc:
            checks.append(section("reference_evidence", "inconclusive", [finding("reference_unverifiable", message=str(exc))]))
    if not files:
        result["status"] = "fail"
        notes.append(finding("empty_submission"))
        return result

    approved = next((a for a in APPROVALS if a["sha256"] == expected), None)
    approved_match = False
    if approved:
        entry = replay(approved, files, first_snapshot)
        if ((product and product != approved["product"])
                or (original_path and original_path != approved["original_path"])):
            entry["status"] = "inconclusive"
            entry["findings"].append(finding("approval_does_not_cover_this_product_path"))
        checks.append(entry)
        approved_match = entry["status"] == "pass"

    if "run.json" in files:
        try:
            report = load_json(files["run.json"])
            if not isinstance(report, dict):
                raise ValueError("run.json must be a JSON object")
            if "original_sha256" in report and digest_arg(report["original_sha256"]) != expected:
                result["status"] = "fail"
                notes.append(finding("submission_bound_to_different_original"))
                return result
            if set(files) == {"run.json"} and "original_sha256" in report:
                result["status"] = "fail"
                notes.append(finding("only_run_metadata_no_implementation"))
                return result
        except (UnicodeError, ValueError) as exc:
            checks.append(section("submission_identity", "fail", [finding("invalid_run_record", message=str(exc))]))
    if len(files) == 1:
        sole_file = next(iter(files.values()))
        if sole_file.stat().st_size == len(data) and digest_file(sole_file) == expected and data.startswith((b"MZ", b"!<arch>\n")):
            result["status"] = "fail"
            notes.append(finding("original_binary_only_no_editable_delivery"))
            return result

    if data.startswith(b"MZ") and ("coverage.csv" in files or "native-functions.csv" in files):
        for name in ("coverage.csv", "calls.csv", "run.json"):
            if name not in files:
                checks.append(section("native_handoff", "fail", [finding("missing_protocol_file", path=name)]))
        if "coverage.csv" in files:
            checks.append(component("coverage_table", data, files))

    if data.startswith(b"MZ") and ("instruction_listing" in references or files.keys() & {
            "calls.csv", "target-evidence.json", "code/indirect.csv", "code/indirect-resolved.csv", "code/import-callers.csv"}):
        checks.append(component("native_sites", data, delivery, provider, references.get("instruction_listing")))
    if data.startswith(b"MZ") and "s5/business-evidence.json" in files:
        checks.append(component("native_exports", data, delivery, assembler))
    if data.startswith(b"MZ") and ("s13/callee-evidence.json" in files or
                                  ("reassembly.json" in files and "code/verified.c" in files) or
                                  any(REGION_DELTA.fullmatch(path) for path in files)):
        checks.append(component("native_regions", data, delivery, assembler))
    if data.startswith(b"MZ") and files.keys() & {"code/com-call-sites.csv", "code/s25-idispatch-slots.csv"}:
        checks.append(component("com_call_sites", data, delivery))
    if data.startswith(b"MZ") and "code/vtable-fixups.csv" in files:
        checks.append(component("clr_fixups", data, delivery))
    if data.startswith(b"MZ") and ("clr_thunks" in references or files.keys() & {"code/newobj.csv", "code/vtable-fixups.csv"}):
        checks.append(component("mixed_baseline", data, delivery, references.get("clr_thunks")))
    if data.startswith(b"MZ") and has_callback_witness(files):
        checks.append(component("callback_paths", data, delivery))
    if data.startswith(b"MZ") and files.keys() & {"resources.csv", "s5/resources.json", "s5-data/version-resource.json",
                                                 "native-functions.csv", "coverage.csv", "calls.csv"}:
        checks.append(component("pe_resources", data, delivery))
    if any(entry.is_dir() and entry.name.casefold() in {"vba", "vba-src"} for entry in delivery.iterdir()):
        checks.append(component("office_vba", data, delivery))
    if data.startswith(CFB_MAGIC):
        if "workbook.json" in files:
            checks.append(component("biff_workbook", data, delivery))
        if "project.json" in files and any(name.startswith("project/") for name in files):
            checks.append(component("office_project", data, delivery))
            checks.append(component("office_pcode", data, delivery))
    if rebuilt:
        checks.append(component("managed", data, rebuilt))
    if data.startswith(b"\x64\x86") and any(
            "/" not in name and name.casefold().endswith(".s") for name in files):
        checks.append(component("coff", data, delivery, assembler))

    fresh_pass = False
    if (delivery / "fresh-cs").is_dir():
        filename = (original_path or original.name).replace("\\", "/").rsplit("/", 1)[-1]
        built = component("fresh_cs", data, delivery, filename)
        notes_check = file_notes(files, expected, product, original_path, built["metrics"])
        checks.extend((built, notes_check))
        fresh_pass = built["status"] == notes_check["status"] == "pass"

    # A component pass can never authorize a whole-item pass. An actual contradiction takes precedence.
    if any(c["status"] == "fail" for c in checks):
        result["status"] = "fail"
    elif approved_match and all(c["status"] == "pass" for c in checks):
        result["status"] = "pass"
        result["basis"] = ARCHIVE_REPLAY_BASIS
    elif fresh_pass and all(c["status"] == "pass" or c["scope"] == "unchanged_previously_accepted_archive" for c in checks):
        result["status"] = "pass"
        result["basis"] = FRESH_BUILD_BASIS
    else:
        notes.append(finding("whole_item_proof_outstanding",
                             required="original-derived coverage, editable implementation, logic/data/resources and reviewable per-file evidence"))
    try:
        unchanged = digest_file(original) == expected and fingerprints(tree_files(delivery)) == first_snapshot
    except (OSError, ValueError):
        unchanged = False
    if not unchanged:
        result.update(status="inconclusive")
        result.pop("basis", None)
        notes.append(finding("inputs_changed_during_verification"))
    elif result["status"] == "pass":
        result["verified_artifacts_sha256"] = first_snapshot
    return result


def item(original, expected, delivery, rebuilt=None, assembler=None, product=None, original_path=None, provider=None,
         delivery_sha256=None, reference_evidence=None):
    try:
        return evaluate(original, expected, delivery, rebuilt, assembler, product, original_path, provider, delivery_sha256,
                        reference_evidence)
    except (OSError, UnicodeError, ValueError, csv.Error, ImportError) as exc:
        return {"schema": VERSION, "scope": "whole_item_static", "status": "inconclusive",
                "expected_sha256": expected, "findings": [finding("unverifiable_input", message=str(exc))],
                "checks": []}


def inventory(path, expected):
    data = path.read_bytes()
    if sha(data) != digest_arg(expected):
        raise ValueError("inventory SHA-256 mismatch")
    reader = csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline=""), strict=True)
    header = reader.fieldnames or []
    if len(header) != len(set(header)) or not {"产品", "原路径", "原件SHA256"} <= set(header):
        raise ValueError("invalid inventory column names")
    entries = {}
    for row in reader:
        if None in row or None in row.values():
            raise ValueError(f"malformed inventory row {reader.line_num}")
        key = (row["产品"], row["原路径"], digest_arg(row["原件SHA256"]))
        if not key[0].strip() or not key[1].strip() or key in entries:
            raise ValueError(f"empty or duplicate inventory identity on row {reader.line_num}")
        entries[key] = row.get("状态")
    if not entries:
        raise ValueError("empty inventory")
    return entries


def complete_denominator(folder, expected):
    """Union the frozen source lists by content. Keep all original row links."""
    origins = {}
    names = {}
    owner_sets = {}
    for group, trusted_sha in SOURCE_LISTS.items():
        data = (folder / (group + "-scope.csv")).read_bytes()
        if sha(data) != trusted_sha:
            raise ValueError("wrong original source list: " + group)
        rows = csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline=""), strict=True)
        for i, row in enumerate(rows, 2):
            digest = digest_arg(row["sha256"])
            origins.setdefault(digest, {}).setdefault(group, []).append(i)
            names.setdefault(digest, row["relative_path"])
            owner_sets.setdefault(digest, set()).add(group)
    indexed = {k[2] for k in expected}
    if indexed - origins.keys():
        raise ValueError("project inventory and frozen source lists disagree on original identities")
    missing = sorted(origins.keys() - indexed)
    for digest in missing:
        groups = owner_sets[digest]
        product = "Plus-Properties" if "shared" in groups or {"plus", "properties"} <= groups else (
            "Plus" if "plus" in groups else "Properties")
        expected[(product, names[digest], digest)] = None
    summary = {"source_commit": SNAPSHOT, "lists": SOURCE_LISTS, "raw_source_rows":
               sum(len(rows) for groups in origins.values() for rows in groups.values()),
               "distinct_source_contents": len(origins), "absent_from_project_inventory": missing}
    return summary, origins


def project(inventory_path, inventory_sha, input_path, assembler, source_scopes=None):
    expected = inventory(inventory_path, inventory_sha)
    input_inventory_rows = len(expected)
    scope = "all_rows_of_pinned_inventory"
    reconciliation, origins = None, {}
    if source_scopes is not None:
        reconciliation, origins = complete_denominator(source_scopes, expected)
        scope = "all_distinct_contents_in_pinned_reverse_lists_and_project_inventory"
    bindings = load_json(input_path)
    if not isinstance(bindings, list):
        raise ValueError("inputs must be a JSON array")
    chosen = {}
    for record in bindings:
        required = {"product", "path", "sha256", "original", "delivery"}
        optional = {"rebuilt", "provider", "provider_sha256", "delivery_sha256", "reference_evidence",
                    "reference_evidence_sha256"}
        if not isinstance(record, dict) or not required <= record.keys() or record.keys() - required - optional:
            raise ValueError("invalid fields in input binding")
        if any(not isinstance(value, str) or not value.strip() for value in record.values()):
            raise ValueError("input binding fields must be nonempty strings")
        key = (record["product"], record["path"], digest_arg(record["sha256"]))
        if "delivery_sha256" in record:
            digest_arg(record["delivery_sha256"])
        if key not in expected or key in chosen:
            raise ValueError(f"unexpected or duplicate input binding: {key}")
        provider = provider_binding(record.get("provider"), record.get("provider_sha256"))
        reference = reference_binding(record.get("reference_evidence"), record.get("reference_evidence_sha256"))
        if provider:
            provider = input_path.resolve().parent / provider[0], provider[1]
        if reference:
            reference = input_path.resolve().parent / reference[0], reference[1]
        chosen[key] = record, provider, reference

    rows = []
    counts = Counter()
    pass_by_basis = Counter({ARCHIVE_REPLAY_BASIS: 0, FRESH_BUILD_BASIS: 0})
    for (product, path, digest), prior_status in expected.items():
        row = {"product": product, "path": path, "sha256": digest, "inventory_status": prior_status}
        if origins:
            row["source_rows"] = origins[digest]
        binding = chosen.get((product, path, digest))
        if binding is None:
            row.update(status="inconclusive", reason="no_input_binding")
        else:
            bound, provider, reference = binding
            parent = input_path.resolve().parent
            rebuilt = parent / bound["rebuilt"] if "rebuilt" in bound else None
            proof = item(parent / bound["original"], digest, parent / bound["delivery"], rebuilt, assembler,
                         product, path, provider, delivery_sha256=bound.get("delivery_sha256"), reference_evidence=reference)
            row.update(status=proof["status"], proof=proof)
            if proof["status"] == "pass":
                pass_by_basis[proof["basis"]] += 1
        counts[row["status"]] += 1
        rows.append(row)
    status = "fail" if counts["fail"] else "inconclusive" if counts["inconclusive"] else "pass"
    return {"schema": VERSION, "scope": scope, "inventory_sha256": inventory_sha.lower(),
            "input_inventory_rows": input_inventory_rows, "reconciliation": reconciliation,
            "status": status, "items_expected": len(expected), "items_bound": len(chosen),
            "distinct_originals": len({key[2] for key in expected}),
            "counts": {key: counts[key] for key in EXIT}, "pass_by_basis": dict(pass_by_basis), "rows": rows}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    single = sub.add_parser("item", help="check an existing delivery against one reference original")
    single.add_argument("--original", type=Path, required=True)
    single.add_argument("--sha256", required=True, help="trusted original SHA-256")
    single.add_argument("--delivery", type=Path, required=True)
    single.add_argument("--delivery-sha256", help="trusted digest of the exact delivery tree")
    single.add_argument("--product", help="product in the trusted inventory")
    single.add_argument("--original-path", help="original logical path in that inventory")
    single.add_argument("--rebuilt", type=Path, help="existing CLR rebuild for a scoped comparison")
    single.add_argument("--provider", type=Path, help="independent PE that provides a registered import")
    single.add_argument("--provider-sha256", help="trusted SHA-256 of that provider PE")
    single.add_argument("--reference-evidence", type=Path, help="independently supplied reference-evidence manifest")
    single.add_argument("--reference-evidence-sha256", help="trusted SHA-256 of that manifest")
    batch = sub.add_parser("project", help="verify each row of a frozen project inventory")
    batch.add_argument("--inventory", type=Path, required=True)
    batch.add_argument("--inventory-sha256", required=True)
    batch.add_argument("--inputs", type=Path, required=True)
    batch.add_argument("--source-scopes", type=Path, help="directory with plus/properties/shared-scope.csv from the pinned original inventories")
    for cmd in (single, batch):
        cmd.add_argument("--assembler", type=Path, help="trusted Zig for COFF reassembly and native export comparison")
    args = parser.parse_args()
    verifier = verifier_identity()
    try:
        if args.command == "item":
            provider = provider_binding(args.provider, args.provider_sha256)
            reference = reference_binding(args.reference_evidence, args.reference_evidence_sha256)
            result = item(args.original, args.sha256, args.delivery, args.rebuilt, args.assembler, args.product,
                          args.original_path, provider, args.delivery_sha256, reference)
        else:
            result = project(args.inventory, args.inventory_sha256, args.inputs, args.assembler, args.source_scopes)
    except (OSError, UnicodeError, ValueError, csv.Error) as exc:
        result = {"schema": VERSION, "scope": args.command, "status": "inconclusive",
                  "findings": [finding("invalid_verification_inputs", message=str(exc))]}
    result["verifier"] = verifier
    print(json.dumps(result, ensure_ascii=True, indent=2, allow_nan=False))
    return EXIT[result["status"]]


if __name__ == "__main__":
    sys.exit(main())
