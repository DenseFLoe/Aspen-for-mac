"""Join a stage-2 ledger to the frozen needs-reverse lists, keeping every source row."""

import argparse
import csv
import json
import re
import tempfile
from collections import Counter, defaultdict
from pathlib import Path

from organize_properties_classification import record_id
from verify_published_classification import ROOT, SNAPSHOT, digest, require, rows


VIEWS = (
    "plus/01-needs-reverse/files.csv",
    "properties/01-needs-reverse/files.csv",
    "properties/01-needs-reverse/duplicates.csv",
    "shared/01-needs-reverse/files.csv",
)
STATUSES = {"未开始", "处理中", "未完成", "暂存", "已完成", "待复核"}
STAGE = "原版逐文件逆向归档"


def verify_artifacts(directory, ledger, verify_local):
    seen = set()
    accepted = set()
    for entry in rows(directory / "artifacts.csv"):
        sha = entry["original_sha256"]
        require(sha in ledger, f"Unknown artifact owner: {sha}")
        artifact = Path(entry["artifact"])
        note = Path(entry["note"])
        require(artifact not in seen and note not in seen, f"Duplicate archive entry: {artifact}")
        seen.update((artifact, note))
        require(note == artifact.with_suffix(".md"), f"Missing matching note name: {artifact}")
        status = ledger[sha]["status"]
        folder = "01-completed" if status == "已完成" else "02-incomplete"
        require(folder in artifact.parts and artifact.parts[0] == ".local", str(artifact))
        for path, field in ((artifact, "artifact_sha256"), (note, "note_sha256")):
            require(not path.is_absolute() and ".." not in path.parts, str(path))
            require(re.fullmatch("[0-9a-f]{64}", entry[field]), f"Invalid fingerprint: {path}")
            if verify_local:
                require(digest(ROOT / path) == entry[field], f"Archive changed: {path}")
        if status == "已完成":
            accepted.add(sha)
    require(accepted == {s for s, r in ledger.items() if r["status"] == "已完成"},
            "Completed content without an accepted artifact")


def build(directory, output, verify_local):
    ledger_rows = rows(directory / "ledger.csv")
    ledger = {r["original_sha256"]: r for r in ledger_rows}
    require(len(ledger) == len(ledger_rows), "Duplicate original hash")
    evidence_hashes = {}
    for sha, entry in ledger.items():
        require(re.fullmatch("[0-9a-f]{64}", sha) and entry["analysis_key"] == "sha256:" + sha, sha)
        require(entry["stage"] == STAGE and entry["status"] in STATUSES, f"Invalid status: {sha}")
        require(all(entry[k] for k in ("round", "original_path", "basis", "evidence")), sha)
        if entry["status"] in {"暂存", "未完成", "待复核"}:
            require(entry["resume"], f"Missing recovery condition: {sha}")
        evidence = Path(entry["evidence"])
        require(not evidence.is_absolute() and ".." not in evidence.parts and
                evidence.parts[0] == ".local" and re.fullmatch("[0-9a-f]{64}", entry["evidence_sha256"]),
                f"Invalid evidence reference: {sha}")
        if verify_local:
            if evidence not in evidence_hashes:
                evidence_hashes[evidence] = digest(ROOT / evidence)
            require(evidence_hashes[evidence] == entry["evidence_sha256"], f"Evidence changed: {evidence}")
    verify_artifacts(directory, ledger, verify_local)

    manifest = json.loads((SNAPSHOT / "manifest.json").read_text(encoding="utf-8"))
    inputs = {e["path"]: e["sha256"] for e in manifest["files"]}
    ids_by_hash = defaultdict(set)
    all_source_ids = {}
    view_stats = {}
    for name in VIEWS:
        source = SNAPSHOT / name
        require(digest(source) == inputs[name], f"Source fingerprint changed: {name}")
        originals = rows(source)
        statuses = Counter()
        source_ids = set()
        view_rows = []
        for row in originals:
            sha = row["sha256"]
            source_id = record_id(row)
            require(row.get("record_id", source_id) == source_id and source_id not in source_ids, name)
            require(all_source_ids.setdefault(source_id, sha) == sha, source_id)
            require(row["analysis_key"] == "sha256:" + sha and row["category"] == "01-needs-reverse", name)
            source_ids.add(source_id)
            ids_by_hash[sha].add(source_id)
            entry = ledger.get(sha)
            status = entry["status"] if entry else "未开始"
            statuses[status] += 1
            view_rows.append(dict(row, reverse_record_id=source_id, reverse_status=status,
                                  reverse_round=entry["round"] if entry else ""))
        view_stats[name] = {"rows": len(originals), "by_status": statuses, "source_sha256": inputs[name]}
        if output:
            dest = output / name
            dest.parent.mkdir(parents=True, exist_ok=True)
            with dest.open("x", newline="", encoding="utf-8-sig") as stream:
                writer = csv.DictWriter(stream, fieldnames=view_rows[0].keys())
                writer.writeheader()
                writer.writerows(view_rows)
            view_stats[name]["view_sha256"] = digest(dest)

    for sha, entry in ledger.items():
        require(sha in ids_by_hash, f"No matching needs-reverse source: {sha}")
        require(set(entry["record_ids"].split("|")) == ids_by_hash[sha], f"Source coverage: {sha}")
    by_content = Counter(ledger[s]["status"] if s in ledger else "未开始" for s in ids_by_hash)
    by_source = Counter(ledger[s]["status"] if s in ledger else "未开始" for s in all_source_ids.values())
    return {"unique_contents": len(ids_by_hash), "content_status": by_content,
            "unique_sources": len(all_source_ids), "source_status": by_source, "views": view_stats}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("ledger_directory", type=Path)
    parser.add_argument("--output", type=Path, help="Publish complete views to a new local directory")
    parser.add_argument("--verify-local", action="store_true", help="Check archived output, notes and evidence")
    args = parser.parse_args()
    if args.output:
        destination = args.output.resolve()
        if destination.exists():
            parser.error("choose a new output directory")
        destination.parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(dir=destination.parent) as work:
            staging = Path(work) / "views"
            summary = build(args.ledger_directory, staging, True)
            (staging / "summary.json").write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n",
                                                  encoding="utf-8")
            staging.rename(destination)
    else:
        summary = build(args.ledger_directory, None, args.verify_local)
    print(json.dumps(summary, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
