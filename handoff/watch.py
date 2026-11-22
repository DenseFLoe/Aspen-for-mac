"""Read the public handoff queue at immutable tree IDs and wake a local worker on change."""
import argparse
import base64
import hashlib
import json
import os
import re
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from http.client import IncompleteRead, RemoteDisconnected
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen

import dispatch

API = "https://api.github.com/repos/DenseFLoe/Aspen-for-mac/"
ISSUE = "https://github.com/DenseFLoe/Aspen-for-mac/issues/13"
HINT = re.compile(r"([A-Za-z0-9_-]+)/s[1-9][0-9]*-(started|submission)\.md")


def request(endpoint, cached=None):
    headers = {"Accept": "application/vnd.github+json", "User-Agent": "Aspen-handoff-reader"}
    token = os.getenv("GH_TOKEN") or os.getenv("GITHUB_TOKEN")
    if token:
        headers["Authorization"] = "Bearer " + token
    if cached and cached[0]:
        headers["If-None-Match"] = cached[0]
    for attempt in range(3):
        try:
            with urlopen(Request(API + endpoint, headers=headers), timeout=25) as resp:
                return resp.headers.get("ETag"), json.load(resp)
        except HTTPError as exc:
            if exc.code == 304 and cached:
                return cached
            if exc.code not in (500, 502, 503, 504) or attempt == 2:
                raise
        except (URLError, TimeoutError, IncompleteRead, RemoteDisconnected):
            if attempt == 2:
                raise
        time.sleep(2 ** attempt)


def read_file(directory_sha, name):
    entries = request("git/trees/" + directory_sha)[1]["tree"]
    item = next(e for e in entries if e["path"] == name and e["mode"] == "100644")
    blob = request("git/blobs/" + item["sha"])[1]
    contents = base64.b64decode(blob["content"])
    checksum = hashlib.sha1(b"blob " + str(len(contents)).encode() + b"\0" + contents).hexdigest()
    if checksum != item["sha"]:
        raise ValueError(f"Git blob fingerprint mismatch for {name}")
    return contents


def observe(cache):
    endpoints = ["contents/handoff?ref=main", "issues/13"]
    with ThreadPoolExecutor(max_workers=2) as pool:
        pending = [pool.submit(request, url, cache.get(url)) for url in endpoints]
        results = [future.result() for future in pending]
    cache.update(zip(endpoints, results))
    entries, issue = (r[1] for r in results)
    identities = {e["name"]: e["sha"] for e in entries}
    issue_state = {"url": ISSUE, "updated_at": issue["updated_at"], "comments": issue["comments"]}
    fingerprint = hashlib.sha256(json.dumps([identities, issue_state], sort_keys=True).encode()).hexdigest()
    return fingerprint, identities, issue_state


def queue_snapshot(trees, owner):
    with ThreadPoolExecutor(max_workers=3) as pool:
        tasks = pool.submit(read_file, trees["assignments"], "tasks.csv")
        ledger = pool.submit(read_file, trees["ledger"], "events.csv")
        inbox = pool.submit(request, "git/trees/" + trees["inbox"] + "?recursive=1")
        inbox_tree = inbox.result()[1]
        if inbox_tree.get("truncated"):
            raise ValueError("Incomplete inbox tree: inspect the task folders before claiming")
        with tempfile.TemporaryDirectory(prefix="aspen-handoff-") as tmp:
            root = Path(tmp)
            handoff = root / "handoff"
            for parent, name, future in [("assignments", "tasks.csv", tasks), ("ledger", "events.csv", ledger)]:
                directory = handoff / parent
                directory.mkdir(parents=True)
                (directory / name).write_bytes(future.result())
            for entry in inbox_tree["tree"]:
                if entry["mode"] == "100644" and HINT.fullmatch(entry["path"]):
                    receipt = handoff / "inbox" / entry["path"]
                    receipt.parent.mkdir(parents=True, exist_ok=True)
                    receipt.touch()
            return dispatch.project(root, owner)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--owner", required=True, help="assigned owner, e.g. upstream or tietoumiao")
    parser.add_argument("--after", help="last successfully processed cursor; wait for the next change")
    parser.add_argument("--timeout", type=int, default=1800, help="seconds to wait; 0 probes once")
    parser.add_argument("--interval", type=int, help="poll seconds; defaults to 60 authenticated, 180 public")
    args = parser.parse_args()
    if args.after and not re.fullmatch(r"[0-9a-f]{64}", args.after):
        parser.error("--after expects the SHA-256 cursor from a previous successful read")
    interval = args.interval if args.interval is not None else (
        60 if os.getenv("GH_TOKEN") or os.getenv("GITHUB_TOKEN") else 180)
    if interval <= 0 or args.timeout < 0:
        parser.error("interval must be positive and timeout non-negative")
    deadline = time.monotonic() + args.timeout
    cache = {}
    while True:
        try:
            cursor, trees, issue = observe(cache)
            if cursor != args.after:
                queues = queue_snapshot(trees, args.owner)
                if not queues["ok"]:
                    print(json.dumps({"ok": False, "issues": queues["issues"]}, ensure_ascii=False))
                    return 2
                print(json.dumps({"ok": True, "changed": True, "cursor": cursor, "issue": issue,
                                  "queues": queues}, ensure_ascii=False))
                return 0
            if time.monotonic() >= deadline:
                print(json.dumps({"ok": True, "changed": False, "cursor": cursor}))
                return 0
            delay = interval
        except (OSError, IncompleteRead, ValueError, KeyError, StopIteration) as exc:
            # Consumers can retry the same cursor. A failed or partial read never acknowledges work.
            if not args.after or time.monotonic() >= deadline:
                print("handoff read failed: " + str(exc), file=sys.stderr)
                return 2
            delay = max(interval, 60)
            if isinstance(exc, HTTPError) and exc.code in (403, 429):
                retry = exc.headers.get("Retry-After", "")
                reset = exc.headers.get("X-RateLimit-Reset", "")
                if retry.isdigit():
                    delay = max(delay, int(retry))
                if reset.isdigit() and exc.headers.get("X-RateLimit-Remaining") == "0":
                    delay = max(delay, int(reset) - time.time() + 1)
        time.sleep(min(delay, max(0, deadline - time.monotonic())))


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    sys.exit(main())
