"""Reconcile the six data files at the immutable T9 review head (Python 3.9+)."""
import argparse
import csv
import hashlib
import io
import json
import re
from collections import Counter, defaultdict
from pathlib import Path
from urllib.request import urlopen

HEAD = "db544a6fdfb04ec60d182c311aa47d13a61d744b"
URL = f"https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/{HEAD}/handoff/review/t9-1000/"
SHA256 = {
    "selection.csv": "d5de1f69c1c56e375883aec40369e73caaa240f38b4fb73e0f7e7e873022506c",
    "ledger-1000.csv": "1312903e8fdf474cf985c356809495d3b80c5f141b289684134ae167fce70663",
    "README.md": "453dc4ac06f99b96ff319d00bf2d7049dde96362c473a5edf4c01638012e51e1",
    "stats.md": "888b636a3d91c5d7a9214bde38c6bebbad4e49d33abc1349312772e35e74e70d",
    "failures.md": "083cc7a9690633e34006b836c3846a860d4aa779d3a44d956e976916d6cf2863",
    "validation.md": "f6d94bc8fa6b680b5455e0ed3cf9acb7857eb31f64af5abf9301c05f4dd5b963",
}
RESULT = Path(__file__).resolve().parents[1] / "inbox/T9-368-RECONCILE/reconciliation.json"
STATES = ("pass", "fail", "partial", "blocked")


def inputs(folder):
    texts = {}
    for name, digest in SHA256.items():
        if folder is None:
            with urlopen(URL + name, timeout=60) as response:
                raw = response.read()
        else:
            raw = (folder / name).read_bytes()
        if hashlib.sha256(raw).hexdigest() != digest:
            raise ValueError(f"Input fingerprint changed: {name}")
        texts[name] = raw.decode("utf-8-sig")
    return texts


def index_csv(text):
    rows = list(csv.DictReader(io.StringIO(text, newline=""), strict=True))
    indexed = {int(row["idx"]): row for row in rows}
    if len(rows) != 1000 or set(indexed) != set(range(1000)):
        raise ValueError("Expected exactly one row per idx from 0 to 999")
    return indexed


def verdicts(rows):
    counts = Counter(row["verdict"] for row in rows)
    if set(counts) - set(STATES):
        raise ValueError("Unknown ledger verdict")
    return {state: counts[state] for state in STATES}


def reconcile(files):
    selection = index_csv(files["selection.csv"])
    ledger = index_csv(files["ledger-1000.csv"])
    rows = list(ledger.values())
    identity_fields = ("shard", "state", "product", "name", "item_dir")
    codes = defaultdict(set)
    blank_paths = []
    for idx, row in ledger.items():
        if any(row[key] != selection[idx][key] for key in identity_fields):
            raise ValueError(f"Selection/ledger identity mismatch at {idx}")
        if not row["relative_path"]:
            blank_paths.append(idx)
        elif row["item_dir"] != f"逆向成果/{row['state']}/{row['relative_path']}":
            raise ValueError(f"Inconsistent relative path at {idx}")
        if (int(row["shard"]) != idx % 12 or
                not row["item_dir"].startswith(f"逆向成果/{row['state']}/{row['product']}/") or
                row["item_dir"].rsplit("/", 1)[-1] != row["name"] or
                not re.fullmatch("[0-9a-f]{64}", row["sha256"])):
            raise ValueError(f"Invalid path, shard or recorded fingerprint at {idx}")
        if row["verdict"] == "fail" and not row["fail_codes"]:
            raise ValueError(f"Missing reason at {idx}")
        for code in filter(None, row["fail_codes"].split(";")):
            codes[code].add(idx)
    dirs = len({r["item_dir"] for r in rows})
    shas = len({r["sha256"] for r in rows})
    if dirs != 1000 or shas != 1000:
        raise ValueError("Unexpected repeated path or recorded hash on pinned head")

    product_matrix = {p: verdicts(r for r in rows if r["product"] == p)
                      for p in sorted({r["product"] for r in rows})}
    archive_matrix = {s: verdicts(r for r in rows if r["state"] == s)
                      for s in sorted({r["state"] for r in rows})}
    totals = verdicts(rows)
    docs = {}
    for name in ("README.md", "stats.md", "failures.md", "validation.md"):
        lines = files[name].replace("*", "").splitlines()
        summary = next(line for line in lines if "pass" in line and "fail" in line and
                       re.search(r"pass\s+\d+", line))
        docs[name] = {"summary": {k: int(v) for k, v in re.findall(
            r"(pass|fail|partial|blocked)\s+(\d+)", summary)}}
        if name in {"stats.md", "failures.md"}:
            table = {m[1]: int(m[2]) for line in lines
                     if (m := re.match(r"^\| (\w+_\w+) \| (\d+) \|", line))}
            docs[name]["code_table"] = table
            docs[name]["codes_missing_from_table"] = sorted(set(codes) - set(table))
        if name == "stats.md":
            matrix = {}
            for line in lines:
                cells = [x.strip() for x in line.strip("|").split("|")]
                if cells[0] in product_matrix and len(cells) == 6:
                    matrix[cells[0]] = dict(zip(STATES, map(int, cells[2:])))
            docs[name]["product_matrix"] = matrix
            docs[name]["different_products"] = sorted(
                p for p in product_matrix if matrix.get(p) != product_matrix[p])
        if name == "failures.md":
            detail = defaultdict(set)
            stale = set()
            group = None
            for line in lines:
                if line.startswith("## "):
                    group = None
                if match := re.match(r"^### (\w+)（", line):
                    group = match[1]
                if group and re.match(r"^\| \d+ \|", line):
                    cells = line.split("|")
                    idx = int(cells[1].strip())
                    detail[group].add(idx)
                    if cells[5].strip() != ledger[idx]["verdict"]:
                        stale.add(idx)
            docs[name]["missing_idx_by_code"] = {
                code: len(ids - detail[code]) for code, ids in sorted(codes.items())}
            docs[name]["stale_detail_verdict_indices"] = sorted(stale)
        if name == "validation.md":
            line = next(line for line in lines if line.startswith("| R3 "))
            docs[name]["R3_fail_count"] = int(re.search(r"(\d+) 件 fail", line)[1])
        if name == "README.md":
            line = next(line for line in lines if "partial: tier_b_incomplete" in line)
            docs[name]["partial_claims"] = {
                code: int(n) for n, code in re.findall(
                    r"(\d+) 件[^；]*?partial: (tier_b_incomplete|analyze_failed)", line)}
    evidence_ids = (4, 311, 893, 916, 982)
    return {
        "pr": 368, "head": HEAD, "input_sha256": SHA256,
        "matched_rows": len(rows), "unique_item_dirs": dirs, "unique_recorded_sha256": shas,
        "blank_relative_path_indices": sorted(blank_paths),
        "verdicts": totals, "by_product": product_matrix, "by_archive_state": archive_matrix,
        "code_counts": {k: len(v) for k, v in sorted(codes.items())},
        "kind_counts": dict(Counter(r["kind"] for r in rows)),
        "tier_b_counts": dict(Counter(r["tier_b"] for r in rows)),
        "tier_a_counts": dict(Counter(r["tier_a"] for r in rows)),
        "document_claims": docs,
        "examples": [{k: ledger[i][k] for k in ("idx", "product", "name", "sha256",
                       "item_dir", "tier_a", "tier_b", "verdict", "fail_codes")} for i in evidence_ids],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input-dir", type=Path, help="directory holding the six original blobs")
    parser.add_argument("--emit", type=Path, help="write freshly calculated JSON for inspection")
    args = parser.parse_args()
    actual = reconcile(inputs(args.input_dir))
    if args.emit:
        args.emit.write_text(json.dumps(actual, ensure_ascii=False, indent=2, sort_keys=True) + "\n",
                             encoding="utf-8")
    else:
        if json.loads(RESULT.read_text(encoding="utf-8-sig")) != actual:
            raise ValueError("Submitted reconciliation differs from fixed data")
    print("T9 reconciliation: 1000 matched identities;", actual["verdicts"],
          "; inconsistent product rows:", actual["document_claims"]["stats.md"]["different_products"])


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError, KeyError, csv.Error) as exc:
        raise SystemExit(str(exc))
