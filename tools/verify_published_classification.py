"""Verify the published metadata snapshot without opening original product files."""

import argparse
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SNAPSHOT = ROOT / "inventories" / "2026-11-19"
COUNTS = {
    "properties/01-needs-reverse/files.csv": 1866,
    "properties/02-no-reverse/files.csv": 17432,
    "properties/01-needs-reverse/duplicates.csv": 1828,
    "properties/02-no-reverse/duplicates.csv": 10735,
    "properties/03-undetermined/files.csv": 0,
    "plus/01-needs-reverse/files.csv": 3791,
    "plus/02-no-reverse/files.csv": 48187,
    "shared/01-needs-reverse/files.csv": 2534,
    "shared/02-no-reverse/files.csv": 8189,
}


def digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream)
        result = list(reader)
    require(all(None not in row and None not in row.values() for row in result),
            f"Malformed CSV: {path}")
    return result


def identity(row):
    return tuple(row.get(key, "") for key in (
        "owner", "package", "source", "original_path", "relative_path",
        "container", "member", "sha256", "analysis_key"))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check-local-sources", action="store_true")
    args = parser.parse_args()
    manifest = json.loads((SNAPSHOT / "manifest.json").read_text(encoding="utf-8"))
    entries = manifest["files"]
    require(len(entries) == 18, "Unexpected snapshot file count")
    require(len({entry["path"] for entry in entries}) == len(entries), "Duplicate path")
    expected = {"README.md", "manifest.json"} | {entry["path"] for entry in entries}
    actual = {p.relative_to(SNAPSHOT).as_posix() for p in SNAPSHOT.rglob("*") if p.is_file()}
    require(actual == expected, "Unexpected or missing files in snapshot")
    for entry in entries:
        path = SNAPSHOT / entry["path"]
        require(path.resolve().is_relative_to(SNAPSHOT.resolve()), "Unsafe snapshot path")
        require(path.suffix in {".csv", ".json", ".md"}, f"Non-metadata file: {path}")
        require(path.stat().st_size == entry["bytes"], f"Size mismatch: {path}")
        require(digest(path) == entry["sha256"], f"Hash mismatch: {path}")
        if args.check_local_sources:
            source = (ROOT / entry["source"]).resolve()
            require(source.is_relative_to((ROOT / ".local").resolve()), "Unsafe source path")
            require(digest(source) == entry["sha256"], f"Local source changed: {source}")
    catalogs = {path: rows(SNAPSHOT / path) for path in COUNTS}
    for path, count in COUNTS.items():
        catalog = catalogs[path]
        require(len(catalog) == count, f"Row count mismatch: {path}")
        category = path.split("/")[1]
        require(all(row["category"] == category for row in catalog), f"Wrong category: {path}")
        extensions = [row["extension"].lower() for row in catalog]
        require(extensions == sorted(extensions), f"Extension order mismatch: {path}")
        for row in catalog:
            if row["sha256"]:
                require(row["analysis_key"] == "sha256:" + row["sha256"],
                        f"Analysis key mismatch: {path}")
    properties = sum((catalogs[f"properties/{c}/files.csv"] for c in (
        "01-needs-reverse", "02-no-reverse", "03-undetermined")), [])
    require(all("Properties" in row["owner"].split(";") for row in properties),
            "Non-Properties owner")
    ids = [row["record_id"] for row in properties]
    require(len(ids) == len(set(ids)) == 19298, "Overlapping Properties lists")
    for category in ("01-needs-reverse", "02-no-reverse"):
        main_rows = {row["record_id"]: row for row in catalogs[f"properties/{category}/files.csv"]}
        duplicates = catalogs[f"properties/{category}/duplicates.csv"]
        require(all(main_rows.get(row["record_id"]) == row and row["duplicate_type"]
                    for row in duplicates), f"Invalid duplicate subset: {category}")
        plus = {identity(row) for row in catalogs[f"plus/{category}/files.csv"]}
        props = {identity(row) for row in catalogs[f"properties/{category}/files.csv"]}
        for row in catalogs[f"shared/{category}/files.csv"]:
            require(identity(row) in plus, "Shared row absent from Plus index")
            if "Properties" in row["owner"].split(";"):
                require(identity(row) in props, "Shared row absent from Properties index")
    groups = json.loads((SNAPSHOT / "properties/duplicate-groups.json").read_text(encoding="utf-8-sig"))
    require(all(not row["duplicate_type"] or row["sha256"] in groups for row in properties),
            "Missing duplicate group")
    index = json.loads((SNAPSHOT / "source-completion/index.json").read_text(encoding="utf-8-sig"))
    require(len(index["originals"]) == 39, "Original source index count mismatch")
    for category, count in (("completed", 4), ("incomplete", 35)):
        require(sum(row["category"] == category for row in index["originals"]) == count,
                f"Source completion count mismatch: {category}")
    print(json.dumps({"files_verified": len(entries), "csv_rows": COUNTS,
                      "local_sources_verified": args.check_local_sources,
                      "properties_disjoint": True, "duplicates_are_subsets": True,
                      "shared_cross_references": True}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
