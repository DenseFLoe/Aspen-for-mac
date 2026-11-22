"""Verify byte-exact legacy ILSpy tail deletions against #416 and its release asset."""

import argparse
import csv
import gzip
import hashlib
import io
import json
import re
import time
import zipfile
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from urllib.error import HTTPError, URLError
from urllib.parse import quote
from urllib.request import Request, urlopen


REPOSITORY = "DenseFLoe/Aspen-for-mac"
RAW = "https://raw.githubusercontent.com/" + REPOSITORY
API = "https://api.github.com/repos/" + REPOSITORY
MAIN = "39be5a38e08c3dabe62daf3976660d18fe9a446f"
CANDIDATE = "2c9038f5357801b8ce35c53f43e5d39bb761f144"
OLD_EVIDENCE_BLOB = "e5615919a5335352163953fc1693d264bac684b4"
RELEASE = {
    "id": 779023128,
    "url": "https://github.com/DenseFLoe/Aspen-for-mac/releases/download/v0.20261121-w2/nag-tail-v2-oversize.zip",
    "size": 4750767,
    "digest": "ce449ca0bce4b066303d32c5d6bb23fa4ea104f9b7deb56658390871ac8f1d95",
}
TAIL = re.compile(
    rb"(?m)^You are not using the latest version of the tool, please update\.\r?\n"
    rb"Latest version is '11\.2\.0\.10050' \(yours is '9\.1\.0\.7988'\)(?:\r?\n)?\Z")
MAP_SHA256 = "e2b43c6444b03be1e9f50b45a5091c1c41c9c51f1e575424d52c8be409e1349f"


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha256(raw):
    return hashlib.sha256(raw).hexdigest()


def git_blob(raw):
    return hashlib.sha1(b"blob " + str(len(raw)).encode("ascii") + b"\0" + raw).hexdigest()


def get(url):
    request = Request(url, headers={"Accept-Encoding": "gzip", "User-Agent": "Aspen-handoff-NAG416"})
    for attempt in range(4):
        try:
            with urlopen(request, timeout=35) as response:
                require(response.status == 200, f"incomplete response {response.status}: {url}")
                body = response.read()
                return gzip.decompress(body) if response.headers.get("Content-Encoding") == "gzip" else body
        except (URLError, TimeoutError, OSError) as exc:
            if attempt == 3 or isinstance(exc, HTTPError) and exc.code == 404:
                raise
            time.sleep(2 ** attempt)


def read_asset(release, path):
    body = path.read_bytes() if path.exists() else get(release["url"])
    require(len(body) == release["size"] and sha256(body) == release["digest"], "release asset fingerprint differs")
    if not path.exists():
        path.write_bytes(body)
    with zipfile.ZipFile(io.BytesIO(body)) as archive:
        members = [item for item in archive.infolist() if not item.is_dir()]
        require(len({item.filename for item in members}) == len(members), "duplicate ZIP member")
        require(sum(item.file_size for item in members) <= 200_000_000, "unexpected ZIP size")
        return {item.filename: archive.read(item) for item in members}


def capture():
    def verify_head():
        current = json.loads(get(API + "/pulls/416"))["head"]["sha"]
        require(current == CANDIDATE, f"PR 416 head changed to {current}")

    verify_head()
    evidence = get(f"{RAW}/{MAIN}/handoff/inbox/NAG-PREFLIGHT/evidence.json")
    require(git_blob(evidence) == OLD_EVIDENCE_BLOB, "prior preflight evidence blob")
    previous = json.loads(evidence)
    records = {row["path"]: row["old"] for row in previous["files"]}
    paths = sorted(records)
    indices = {path: index for index, path in enumerate(paths)}
    with ThreadPoolExecutor(max_workers=5) as pool:
        urls = [f"{API}/pulls/416/files?per_page=100&page={i}" for i in range(1, 6)]
        changes = [entry for raw in pool.map(get, urls) for entry in json.loads(raw)]
    mapping = get(f"{RAW}/{previous['mapping_head']}/handoff/fixes/nag-tail/mapping.csv").decode("utf-8")
    verify_head()
    return {
        "before": previous["base"], "mapping": previous["mapping_head"], "main": MAIN,
        "candidate": CANDIDATE, "paths": paths,
        "inline": [[indices[e["filename"]], e["sha"], e["status"], e["additions"], e["deletions"]]
                   for e in changes],
        "old_evidence": [[records[p][key] for key in ("sha256", "clean_sha256", "size")] for p in paths],
        "release": RELEASE, "mapping_csv": mapping,
    }


def verify(config, asset, jobs):
    paths = config["paths"]
    inline = {row[0]: row[1:] for row in config["inline"]}
    require(len(paths) == len(set(paths)) == 504, "previous PR path count")
    require(len(inline) == len(config["inline"]) == 498 and set(inline) <= set(range(504)), "inline diff scope")
    require(all(spec[1:] == ["modified", 0, 2] for spec in inline.values()), "unexpected inline edit")
    require(sha256(config["mapping_csv"].encode("utf-8")) == MAP_SHA256, "mapping SHA-256")
    mapping = list(csv.DictReader(io.StringIO(config["mapping_csv"], newline="")))
    require(len(mapping) == 455, "mapping row count")
    zip_by_name = {Path(name).name: name for name in asset if name.endswith(".cs.txt.fixed")}
    require(len(zip_by_name) == 6, "expected six unique .cs.txt.fixed members")

    def inspect(pair):
        index, path = pair
        row = {"path": path, "delivery": "inline" if index in inline else "asset"}
        try:
            raw = get(f"{RAW}/{config['main']}/{quote(path)}")
            match = TAIL.search(raw)
            if not match:
                return {**row, "error": "exact terminal pair missing in main", "old_sha256": sha256(raw)}
            trimmed = raw[:match.start()]
            old = [sha256(raw), sha256(trimmed), len(raw)]
            require(old == config["old_evidence"][index], "main differs from the previous fixed base")
            row.update(old_sha256=old[0], clean_sha256=old[1], old_bytes=len(raw), clean_bytes=len(trimmed),
                       eol="CRLF" if b"\r\n" in match.group() else "LF", expected_blob=git_blob(trimmed),
                       clean_lf_sha256=sha256(trimmed.replace(b"\r\n", b"\n")))
            if index in inline:
                claimed_blob = inline[index][0]
                require(row["expected_blob"] == claimed_blob, "cleaned bytes differ from candidate Git blob")
                row.update(blob=claimed_blob, matches=True)
            else:
                name = zip_by_name.get(Path(path).name + ".fixed")
                require(name is not None, "no filename identity in release asset")
                row.update(member=name, asset_sha256=sha256(asset[name]))
                require(asset[name] == trimmed, "release asset bytes differ")
                row["matches"] = True
            return row
        except (URLError, TimeoutError, OSError, ValueError) as exc:
            return {**row, "error": str(exc)}

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        records = list(pool.map(inspect, enumerate(paths)))
    identities = {(Path(row["path"]).name.removesuffix(".cs.txt"), row["old_sha256"], row["clean_sha256"])
                  for row in records if row.get("matches")}
    mapped = [row for row in mapping if (row["binary"], row["old_sha"], row["new_sha"]) in identities]
    lf_identities = {(Path(row["path"]).name.removesuffix(".cs.txt"), row["old_sha256"], row["clean_lf_sha256"])
                     for row in records if row.get("matches")}
    unmatched_lf = [row["cache"] for row in mapping
                    if (row["binary"], row["old_sha"], row["new_sha"]) not in lf_identities]
    return {
        "pins": {key: config[key] for key in ("before", "mapping", "main", "candidate", "release")},
        "counts": dict(Counter(row["delivery"] for row in records if row.get("matches"))),
        "eol": dict(Counter(row["eol"] for row in records if row.get("matches"))),
        "mapping_matched": len(mapped), "mapping_total": len(mapping),
        "mapping_matched_after_lf_normalization": len(mapping) - len(unmatched_lf),
        "mapping_unmatched_after_lf_normalization": unmatched_lf,
        "errors": [row for row in records if row.get("error")], "zip_members": sorted(asset), "records": records,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("inputs", type=Path)
    parser.add_argument("out", type=Path)
    parser.add_argument("--jobs", type=int, default=16)
    parser.add_argument("--refresh", action="store_true", help="recapture metadata while PR 416 stays on this head")
    args = parser.parse_args()
    if args.refresh:
        config = capture()
        args.inputs.write_text(json.dumps(config, ensure_ascii=False) + "\n", encoding="utf-8")
    else:
        config = json.loads(args.inputs.read_bytes())
    require((config["main"], config["candidate"], config["release"]) == (MAIN, CANDIDATE, RELEASE), "unexpected input pins")
    asset = read_asset(config["release"], args.out.with_suffix(".zip"))
    result = verify(config, asset, max(1, min(args.jobs, 24)))
    args.out.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: result[key] for key in ("counts", "eol", "mapping_matched", "mapping_total", "errors", "zip_members")}, ensure_ascii=True))
    return int(bool(result["errors"]) or result["mapping_matched"] != result["mapping_total"])


if __name__ == "__main__":
    raise SystemExit(main())
