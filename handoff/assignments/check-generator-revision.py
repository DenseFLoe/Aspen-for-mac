"""Verify a revised #373 generator as data against the original twenty cases."""
import argparse
import base64
import hashlib
import json
import re
import runpy
import sys
from pathlib import Path
from urllib.error import URLError
from urllib.parse import quote
from urllib.request import urlopen


ROOT = Path(__file__).resolve().parents[2]
BASE_CHECK = Path(__file__).with_name("check-generator-373.py")
BASE_DIGEST = "6874518534d9cbda2747902a5152b4ac127b36fd5f244d4ddf30fe69f9f6e95a"
REPO_RAW = "https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac"


def sha(data):
    return hashlib.sha256(data).hexdigest()


def remote_sha(ref, path):
    url = f"{REPO_RAW}/{ref}/{quote(path)}"
    hasher = hashlib.sha256()
    with urlopen(url, timeout=30) as response:
        for block in iter(lambda: response.read(65536), b""):
            hasher.update(block)
    return hasher.hexdigest()


def require(condition, reason):
    if not condition:
        raise ValueError(reason)


def commit_id(value):
    require(isinstance(value, str) and re.fullmatch(r"[0-9a-f]{40}", value), "full lower-case commit SHA required")
    return value


def check(folder, expected_head, digest_at=remote_sha):
    require(sha(BASE_CHECK.read_bytes()) == BASE_DIGEST, "trusted baseline validator bytes changed")
    baseline = runpy.run_path(str(BASE_CHECK))
    fixture = (folder / "fixtures.json").read_bytes()
    require(fixture == baseline["fixtures"](), "fixed fixture bytes differ from original task")
    result = json.loads((folder / "results.json").read_bytes(), object_pairs_hook=baseline["unique_fields"])
    code_head = commit_id(result["pr_head"])
    refs = [code_head]
    if expected_head is not None and commit_id(expected_head) != code_head:
        refs.append(expected_head)
    declared = result["sources_sha256"]
    require(isinstance(declared, dict) and set(declared) == set(baseline["SOURCES"]), "expected the three production paths")
    helpers = result.get("additional_sources_sha256", {})
    require(isinstance(helpers, dict), "additional_sources_sha256 must be an object")
    for path in helpers:
        require(re.fullmatch(r"tool/(?:[A-Za-z0-9_]+/)*[A-Za-z0-9_]+\.py", path)
                and path not in declared, "invalid additional generator source path")
    for path, digest in {**declared, **helpers}.items():
        require(isinstance(digest, str) and re.fullmatch(r"[0-9a-f]{64}", digest), f"invalid SHA-256 for {path}")
        for ref in refs:
            require(digest_at(ref, path) == digest, f"source SHA-256 differs at {ref}/{path}")
    log = (folder / "run.log").read_bytes()
    require(result["fixtures_sha256"] == sha(fixture) and log.strip() and result["run_log_sha256"] == sha(log),
            "fixture or log SHA-256 mismatch")
    producers = result["producers"]
    require(set(producers) == set(baseline["PRODUCERS"]), "producer identities mismatch")
    failures = []
    if code_head == baseline["HEAD"]:
        failures.append("submitted code identity is the original returned head")
    for producer in baseline["PRODUCERS"]:
        rows = producers[producer]
        require(set(rows) == set(baseline["CASES"]), f"{producer}: expected the ten fixed cases")
        for name, (_, expected, raw_rc, after_rc) in baseline["CASES"].items():
            row = rows[name]
            key = f"{producer}/{name}"
            for phase in ("once", "twice"):
                actual = base64.b64decode(row[f"{phase}_b64"], validate=True)
                present = row[f"{phase}_present"]
                require(type(present) is bool, f"{key}/{phase}: expected file-presence boolean")
                if not present or actual != expected:
                    failures.append(f"{key}/{phase}: present={present}, bytes={sha(actual)}, expected={sha(expected)}")
            for field, expected_rc in (("raw_gate_exit", raw_rc), ("after_gate_exit", after_rc)):
                rc = row[field]
                require(type(rc) is int, f"{key}/{field}: expected integer exit code")
                if rc != expected_rc:
                    failures.append(f"{key}/{field}: {rc}, expected {expected_rc}")
    return refs, failures


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inbox", type=Path, default=ROOT / "handoff/inbox/NAG-GENERATOR-373-FIX")
    parser.add_argument("--expected-head", help="independent current PR head; also verify its actual source bytes")
    args = parser.parse_args()
    try:
        refs, failures = check(args.inbox, args.expected_head)
    except (ValueError, KeyError, TypeError, OSError, URLError) as exc:
        print(f"missing or invalid evidence: {exc}", file=sys.stderr)
        return 2
    if failures:
        print("\n".join(failures), file=sys.stderr)
        return 1
    print(f"2 producers x 10 fixed cases matched. Source SHA-256 verified at {', '.join(refs)}.")
    print("Upstream still verifies current PR head, full diff, observed write paths and run provenance.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
