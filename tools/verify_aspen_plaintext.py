"""Audit APED text exports and publish decoded values into their relational tables.

The encoded source files are moved to a separate local evidence directory.
The delivered storage catalog then contains plaintext pvcValue strings. A full
optional SQL key comparison checks that no stored numeric cells were omitted.
"""
import argparse
import hashlib
import itertools
import json
import math
from pathlib import Path

from export_aspen_catalogs import DATABASES, connect, dumps, sha256, write_json


def rows(path):
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            yield json.loads(line)


def numeric_signature(values):
    # API arrays may expand directional labels or add missing-value padding.
    # This is explicitly a multiset comparison, NOT a validation of direction,
    # formulas, unit conversion, or element-to-position interpretation.
    numbers = sorted(float(value) + 0.0 for value in values if float(value) != 1e35)
    # .NET Framework's decimal parser can differ by one ULP from Python's.
    # The exact decoded decimal string is preserved; comparisons use 14 digits.
    return hashlib.sha256("|".join(format(value, ".14g") for value in numbers).encode()).digest()


def audit_database(root, database, evidence, live_sql):
    folder = root / "aped" / database
    catalog = folder / "storage"
    manifest = json.loads((catalog / "manifest.json").read_text(encoding="utf-8"))
    table = next(t for t in manifest["tables"] if t["table"] == "active_PropValueConst")
    value_summary = json.loads((folder / "values" / "summary.json").read_text(encoding="utf-8"))
    if value_summary["limited_run"] or value_summary["non_numeric"] or value_summary["rows"] != table["rows"]:
        raise ValueError("Incomplete decoded value export")
    for item in manifest["tables"]:
        path = catalog / item["file"]
        if sha256(path) != item["sha256"]:
            raise ValueError("Catalog checksum mismatch: " + str(path))
        if sum(1 for _ in rows(path)) != item["rows"]:
            raise ValueError("Catalog row count mismatch: " + str(path))
    expected = {r["dbcCompoundPropId"] for r in rows(catalog / "active_DatabankCompounds.jsonl")}
    has_values = set()
    for name, key in (("active_PropValueText", "pvtCompoundPropId"), ("active_PropValueLongText", "pvltCompoundPropId")):
        has_values.update(r[key] for r in rows(catalog / (name + ".jsonl")))
    signatures = {}
    count = 0
    sentinel_cells = 0
    decimal_float_rounding_differences = 0
    previous = None
    connection = connect(database) if live_sql else None
    cursor = iter(connection.execute("SELECT pvcCompoundPropId,pvcIndex FROM active_PropValueConst ORDER BY pvcCompoundPropId,pvcIndex")) if connection else None
    plain_path = catalog / "active_PropValueConst.plain.jsonl"
    try:
        with plain_path.open("x", encoding="utf-8", newline="\n") as stream:
            for cp_id, group in itertools.groupby(rows(folder / "values" / "constant-values.jsonl"), lambda r: r["cp_id"]):
                values = []
                for record in group:
                    key = (cp_id, record["element_index"])
                    if previous is not None and key <= previous:
                        raise ValueError("Duplicate or unordered decoded cell")
                    previous = key
                    if cursor is not None and tuple(next(cursor, ())) != key:
                        raise ValueError("Decoded cell identity differs from SQL")
                    value = record["value"]
                    decimal_value = float(record["value_text"])
                    if record["status"] != "decoded_numeric" or not math.isfinite(value) or not math.isclose(decimal_value, value, rel_tol=2e-15, abs_tol=0):
                        raise ValueError("Invalid decoded numeric cell")
                    decimal_float_rounding_differences += decimal_value != value
                    sentinel_cells += value == 1e35
                    values.append(value)
                    stream.write(dumps({"pvcCompoundPropId": cp_id, "pvcIndex": key[1], "pvcValue": record["value_text"]}) + "\n")
                    count += 1
                signatures[cp_id] = numeric_signature(values)
                has_values.add(cp_id)
        if cursor is not None and next(cursor, None) is not None:
            raise ValueError("Missing decoded SQL cells")
    finally:
        if connection:
            connection.close()
    if count != table["rows"]:
        raise ValueError("Decoded count mismatch")
    exported = set()
    matched = differing = non_numeric = 0
    differences = folder / "api-value-differences.jsonl"
    with differences.open("x", encoding="utf-8", newline="\n") as stream:
        for record in rows(folder / "api" / "parameters.jsonl"):
            cp_id = record["cp_id"]
            if cp_id not in expected or cp_id in exported:
                raise ValueError("Unexpected or duplicate API identity")
            exported.add(cp_id)
            if cp_id not in signatures:
                non_numeric += 1
                continue
            value = record["value"]
            if not isinstance(value, list) or not all(isinstance(v, (int, float)) and math.isfinite(v) for v in value):
                raise ValueError("Unexpected API numeric type")
            if numeric_signature(value) == signatures[cp_id]:
                matched += 1
            else:
                differing += 1
                stream.write(dumps({"cp_id": cp_id, "property": record["property"],
                                    "read_bank_id": record["read_bank_id"], "api_value": value,
                                    "status": "api_and_stored_numeric_multisets_differ"}) + "\n")
    failures = list(rows(folder / "api" / "failures.jsonl"))
    failed_ids = {r["cp_id"] for r in failures}
    if len(failed_ids) != len(failures) or exported & failed_ids or exported | failed_ids != expected:
        raise ValueError("API plan coverage mismatch")
    empty = failed_ids - has_values
    unresolved = failed_ids & has_values
    if unresolved:
        raise ValueError(f"Unresolved API reads with stored values: {len(unresolved)}")
    # Preserve the exact source export outside the delivered plaintext package.
    destination = evidence / database
    destination.mkdir(parents=True, exist_ok=False)
    original = catalog / table["file"]
    original.rename(destination / original.name)
    (destination / "source-manifest.json").write_bytes((catalog / "manifest.json").read_bytes())
    plain_path.rename(original)
    table.update(status="decoded_plaintext", sha256=sha256(original), bytes=original.stat().st_size)
    manifest["value_storage_warning"] = "pvcValue is decoded plaintext. Original encoded strings are retained only in a separate local evidence directory."
    # Atomic replacement of the manifest after the new table is complete.
    replacement = catalog / "manifest.new.json"
    write_json(replacement, manifest)
    replacement.replace(catalog / "manifest.json")
    result = {"database": database, "numeric_cells": count, "numeric_parameter_sets": len(signatures),
              "api_parameter_records": len(exported), "api_empty_source_records": sorted(empty),
              "api_unresolved_reads": len(unresolved), "api_numeric_multiset_matches": matched,
              "api_numeric_multiset_differences": differing, "api_text_records": non_numeric,
              "stored_missing_sentinel_cells": sentinel_cells,
              "dotnet_python_decimal_rounding_differences": decimal_float_rounding_differences,
              "unreferenced_parameter_sets_with_values": len(has_values - expected),
              "all_decoded_cell_keys_checked_against_sql": live_sql,
              "comparison_note": "Multiset comparison rounds to 14 significant digits and excludes 1e35 padding; exact decimal text is retained, element order and formulas are not inferred."}
    write_json(folder / "validation.json", result)
    print(dumps(result), flush=True)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, required=True)
    parser.add_argument("--evidence", type=Path, required=True)
    parser.add_argument("--live-sql", action="store_true")
    args = parser.parse_args()
    results = [audit_database(args.root, db, args.evidence, args.live_sql) for db in DATABASES]
    write_json(args.root / "aped-validation.json", results)


if __name__ == "__main__":
    main()
