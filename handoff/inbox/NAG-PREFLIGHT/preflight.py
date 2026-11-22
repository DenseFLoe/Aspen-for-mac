"""Verify the pinned #369 mapping and the #370 source-text replacements."""
import argparse
import csv
import gzip
import hashlib
import io
import json
import re
import sys
import time
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from urllib.error import HTTPError, URLError
from urllib.parse import quote
from urllib.request import Request, urlopen


REPO = "DenseFLoe/Aspen-for-mac"
API = "https://api.github.com/repos/" + REPO
RAW = "https://raw.githubusercontent.com/" + REPO
BASE = "a9ea5dfcc5ba8c12ac306e73f79fa02e30e7ea04"
MAPPING = "584a04a3993eba2546bc6802cf4798f30a8e551d"
PATCH = "b7391aa8cabacad7104de1d8c8e83ca5eaa69540"
MAP_HASH = "e2b43c6444b03be1e9f50b45a5091c1c41c9c51f1e575424d52c8be409e1349f"
MAP_PATH = "handoff/fixes/nag-tail/mapping.csv"
TAG = "v0.20261121-w2"
TAIL_LINES = ["You are not using the latest version of the tool, please update.",
              "Latest version is '11.2.0.10050' (yours is '9.1.0.7988')"]
TAIL = re.compile(b"(?m)^" + rb"\r?\n".join(re.escape(s.encode()) for s in TAIL_LINES) + rb"(?:\r?\n)?\Z")


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def get(url):
    for attempt in range(3):
        try:
            req = Request(url, headers={"Accept-Encoding": "gzip", "User-Agent": "Aspen-handoff-preflight"})
            with urlopen(req, timeout=60) as response:
                require(response.status == 200, f"partial response: {url}")
                data = response.read()
                return gzip.decompress(data) if response.headers.get("Content-Encoding") == "gzip" else data
        except (URLError, TimeoutError, OSError) as exc:
            if (isinstance(exc, HTTPError) and exc.code == 404) or attempt == 2:
                raise
            time.sleep(2 ** attempt)


def raw(ref, path):
    return get(f"{RAW}/{ref}/{quote(path)}")


def read_note(path):
    obj = path.split(f"/{TAG}/")[0]
    note = obj + "/" + obj.rsplit("/", 1)[1] + ".归档说明.md"
    try:
        data = raw(PATCH, note)
    except HTTPError as exc:
        if exc.code != 404:
            raise
        return {"note": note, "http": 404}
    pairs = re.findall(r"正式导出 · cs · ([0-9a-fA-F]{12,64})\]\([^\n]*?\.cs\.txt\)（([0-9,]+) 字节）",
                       data.decode("utf-8-sig"))
    return {"note": note, "sha256": sha(data), "cs_fingerprints": [[h, int(s.replace(",", ""))] for h, s in pairs]}


def before(path):
    data = raw(BASE, path)
    match = TAIL.search(data)
    trimmed = data[:match.start()] if match else None
    return {"path": path, "size": len(data), "sha256": sha(data), "lf_sha256": sha(data.replace(b"\r\n", b"\n")),
            "clean_sha256": sha(trimmed) if trimmed is not None else None,
            "clean_lf_sha256": sha(trimmed.replace(b"\r\n", b"\n")) if trimmed is not None else None}


def after(entry):
    data = raw(PATCH, entry["filename"])
    git_sha = hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()
    require(git_sha == entry["sha"], f"head blob mismatch: {entry['filename']}")
    return {"sha": git_sha, "sha256": sha(data), "size": len(data)}


def record(entry, old, note):
    deleted = [line[1:] for line in (entry.get("patch") or "").splitlines() if line.startswith("-")]
    return {"path": entry["filename"], "head_blob": entry["sha"], "status": entry["status"],
            "additions": entry["additions"], "deletions": entry["deletions"],
            "diff_shows_only_tail": entry["additions"] == 0 and entry["deletions"] == 2 and deleted == TAIL_LINES,
            "old": {k: v for k, v in old.items() if k != "path"}, "archive_note": note}


def assemble(mapping, entries, files369, roots, release, new_blobs, old_files, notes):
    by_root = [{e["path"]: e["sha"] for e in tree["tree"]} for tree in roots]
    root_diff = sorted(k for k in by_root[0].keys() | by_root[1].keys() if by_root[0].get(k) != by_root[1].get(k))
    return {"base": BASE, "mapping_head": MAPPING, "patch_head": PATCH,
            "mapping_csv": mapping.decode("utf-8"), "pr369_paths": sorted(f["filename"] for f in files369),
            "changed_root_entries": root_diff,
            "release": {"id": release["id"], "tag": release["tag_name"], "immutable": release["immutable"],
                        "assets": [{k: a[k] for k in ("id", "name", "size", "digest")} for a in release["assets"]]},
            "head_blobs": {b["sha"]: {"sha256": b["sha256"], "size": b["size"]} for b in new_blobs},
            "files": [record(e, old_files[e["filename"]], notes.get(e["filename"])) for e in entries]}


def refresh(jobs):
    def api(path):
        return json.loads(get(API + path))

    def verify_heads():
        for n, head in ((369, MAPPING), (370, PATCH)):
            pr = api(f"/pulls/{n}")
            require(pr["head"]["sha"] == head, f"PR {n} head changed; this preflight is pinned")

    verify_heads()
    files369 = api("/pulls/369/files?per_page=100")
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        pages = pool.map(api, [f"/pulls/370/files?per_page=100&page={n}" for n in range(1, 7)])
        entries = [entry for page in pages for entry in page]
        paths = [e["filename"] for e in entries]
        require(len(set(paths)) == len(paths) == 504 and all(p.endswith(".cs.txt") for p in paths), "unexpected PR diff")
        unique = {e["sha"]: e for e in entries}
        new_blobs = list(pool.map(after, unique.values()))
        old_files = dict(zip(paths, pool.map(before, paths)))
        targets = [p for p in paths if "/正式导出/" in p]
        notes = dict(zip(targets, pool.map(read_note, targets)))
        roots = list(pool.map(api, [f"/git/trees/{ref}" for ref in (BASE, PATCH)]))
    verify_heads()
    return assemble(raw(MAPPING, MAP_PATH), entries, files369, roots, api("/releases/tags/" + TAG),
                    new_blobs, old_files, notes)


def summarize(e):
    require((e["base"], e["mapping_head"], e["patch_head"]) == (BASE, MAPPING, PATCH), "input pins")
    require(sha(e["mapping_csv"].encode("utf-8")) == MAP_HASH, "mapping.csv SHA-256")
    rows = list(csv.DictReader(io.StringIO(e["mapping_csv"], newline="")))
    require(len(rows) == len({r["cache"] for r in rows}) == 455, "mapping row IDs")
    require(all(r["shape"] == "TAIL2" and r["removed"].split(" | ") == TAIL_LINES for r in rows), "mapping rule")
    files, blobs = e["files"], e["head_blobs"]
    require(len(files) == len({r["path"] for r in files}) == 504, "PR370 path coverage")
    require({r["head_blob"] for r in files} == set(blobs), "head blobs")
    wanted, actual = defaultdict(set), defaultdict(set)
    wanted_pairs, observed_pairs = set(), set()
    old_hashes = defaultdict(set)
    result, notes, layout, release = Counter(), Counter(), Counter(), e["release"]
    for row in rows:
        wanted[row["binary"]].add(row["new_sha"])
        wanted_pairs.add((row["binary"], row["old_sha"], row["new_sha"]))
    matching_path_pairs = 0
    for f in files:
        path, old, head = f["path"], f["old"], blobs[f["head_blob"]]
        require(path.endswith(".cs.txt") and f["status"] == "modified", f"out-of-scope change: {path}")
        name, digest = path.rsplit("/", 1)[1][:-7], head["sha256"]
        require(all(re.fullmatch("[0-9a-f]{64}", h) for h in (old["sha256"], digest)), "invalid content hash")
        actual[name].add(digest)
        pair = (name, old["sha256"], digest)
        observed_pairs.add(pair)
        matching_path_pairs += pair in wanted_pairs
        old_hashes[name].add(old["sha256"])
        layout[path.rsplit("/", 2)[1]] += 1
        if old["clean_sha256"] == digest:
            result["byte_exact_tail_only"] += 1
        elif old["clean_lf_sha256"] == digest:
            result["also_normalized_crlf"] += 1
        elif old["clean_sha256"] is None:
            result["specified_old_tail_absent"] += 1
        else:
            result["different_even_after_lf_normalization"] += 1
        note = f["archive_note"]
        if note is not None:
            pairs = note.get("cs_fingerprints", [])
            if any(digest.startswith(h) and head["size"] == size for h, size in pairs):
                notes["matches_head"] += 1
            elif any(old["sha256"].startswith(h) and old["size"] == size for h, size in pairs):
                notes["matches_only_base"] += 1
            else:
                notes["missing_or_other"] += 1
    require(set(wanted) == set(actual), "binary basename coverage")
    absent = [r for r in rows if r["new_sha"] not in actual[r["binary"]]]
    return {"mapping_rows": len(rows), "mapping_line_count_delta_not_two": sum(
                int(r["old_lines"]) - int(r["new_lines"]) != 2 for r in rows),
            "mapping_unique_old": len({r["old_sha"] for r in rows}),
            "mapping_unique_new": len({r["new_sha"] for r in rows}), "paths": len(files),
            "observed_head_blobs": len(blobs), "head_hashes": len({b["sha256"] for b in blobs.values()}),
            "basenames": len(actual), "basenames_with_multiple_expected_new": sum(len(v)>1 for v in wanted.values()),
            "basenames_with_one_observed_blob": sum(len(v)==1 for v in actual.values()),
            "mapping_rows_with_old_sha_among_same_name_base_files": sum(r["old_sha"] in old_hashes[r["binary"]] for r in rows),
            "mapping_rows_with_matching_head": len(rows) - len(absent), "missing_mapping_rows": len(absent),
            "paths_with_matching_mapping_pair": matching_path_pairs,
            "mapping_rows_with_matching_observed_pair": sum(
                (r["binary"], r["old_sha"], r["new_sha"]) in observed_pairs for r in rows),
            "missing_distinct_new_sha": len({r["new_sha"] for r in absent}), "layouts": dict(layout),
            "tail_delta": dict(result), "archive_notes": dict(notes), "release_assets": len(release["assets"]),
            "release_asset_bytes": sum(a["size"] for a in release["assets"]),
            "manifest_or_package_paths_in_pr": sum(not f["path"].endswith(".cs.txt") for f in files)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("--check", action="store_true", help="validate the captured evidence offline")
    group.add_argument("--refresh", action="store_true", help="re-fetch pinned text and metadata and write evidence")
    parser.add_argument("--evidence", type=Path, default=Path(__file__).with_name("evidence.json"))
    parser.add_argument("--jobs", type=int, default=12, help="parallel network requests during refresh")
    args = parser.parse_args()
    if args.refresh:
        evidence = refresh(max(1, min(30, args.jobs)))
        evidence["summary"] = summarize(evidence)
        tmp = args.evidence.with_suffix(".tmp")
        tmp.write_text(json.dumps(evidence, ensure_ascii=False, sort_keys=True, separators=(",", ":")) + "\n",
                       encoding="utf-8")
        tmp.replace(args.evidence)
    else:
        evidence = json.loads(args.evidence.read_text(encoding="utf-8"))
        require(summarize(evidence) == evidence["summary"], "summary differs from evidence")
    print(json.dumps(evidence["summary"], ensure_ascii=False, indent=2))


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
