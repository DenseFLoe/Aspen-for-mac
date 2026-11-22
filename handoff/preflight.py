"""Read a candidate's queue and reporting data without checking out its code."""
import base64
import hashlib
import json
import os
from pathlib import Path
import re
import runpy
import shutil
import subprocess
import tempfile
from urllib.request import Request, urlopen


HERE = Path(__file__).resolve().parent
TABLES = {"assignments/tasks.csv", "ledger/events.csv"}
METHODS = "inbox/ROUNDTRIP-9/methods.csv"
RECEIPT = re.compile(r"inbox/[A-Za-z0-9_-]+/s[1-9][0-9]*-(?:started|submission)\.md")


def snapshot(repository, revision, token, dest):
    if not re.fullmatch(r"[\w.-]+/[\w.-]+", repository, re.ASCII) or not re.fullmatch(r"[a-f0-9]{40}", revision):
        raise ValueError("invalid GitHub repository or SHA")

    def get(route):
        headers = {"User-Agent": "aspen-handoff-preflight", "Accept": "application/vnd.github+json"}
        if token:
            headers["Authorization"] = "Bearer " + token
        req = Request(f"https://api.github.com/repos/{repository}/git/{route}", headers=headers)
        with urlopen(req, timeout=30) as response:
            return json.load(response)

    def tree(sha, recursive=False):
        listing = get("trees/" + sha + ("?recursive=1" if recursive else ""))
        if listing.get("truncated"):
            raise ValueError("GitHub returned an incomplete tree")
        return {entry["path"]: entry for entry in listing["tree"]}

    root = tree(revision).get("handoff")
    if not root or root["mode"] != "040000":
        raise ValueError("expected a handoff tree")
    entries = tree(root["sha"], recursive=True)
    if not TABLES <= entries.keys():
        raise ValueError("missing assignments or ledger")
    for path, entry in entries.items():
        # Paths outside this allowlist are never materialized or executed.
        receipt = RECEIPT.fullmatch(path)
        if path not in TABLES and path != METHODS and not receipt:
            if entry["mode"] == "120000" and (path == "inbox" or re.fullmatch(r"inbox/[A-Za-z0-9_-]+", path)):
                raise ValueError("receipt directory must not be a symlink")
            continue
        sha = entry["sha"]
        if entry["mode"] not in {"100644", "100755"} or entry["type"] != "blob" or not re.fullmatch(r"[a-f0-9]{40}", sha):
            raise ValueError(f"expected a regular data blob at {path}")
        target = dest / "handoff" / path
        target.parent.mkdir(parents=True, exist_ok=True)
        if receipt:
            # dispatch checks marker presence only. Keep receipts and workbooks
            # out of runner logs, and avoid one request per historical receipt.
            target.touch()
            continue
        result = get("blobs/" + sha)
        if result["encoding"] != "base64":
            raise ValueError(f"unexpected Git blob encoding for {path}")
        data = base64.b64decode("".join(result["content"].split()), validate=True)
        actual = hashlib.sha1(f"blob {len(data)}\0".encode() + data).hexdigest()
        if actual != sha or len(data) != entry["size"]:
            raise ValueError(f"blob mismatch at {path}")
        target.write_bytes(data)


def inspect(root):
    dispatch = runpy.run_path(str(HERE / "dispatch.py"))
    project = dispatch["project"]
    for owner in ("upstream", "tietoumiao"):
        report = project(root, owner)
        if not report["ok"]:
            raise ValueError("queue errors: " + json.dumps(report["issues"], ensure_ascii=True))
        print(owner, " ".join(f"{q}={len(report[q])}" for q in dispatch["QUEUES"]), flush=True)

    methods = root / "handoff" / METHODS
    roundtrip = [item for q in dispatch["QUEUES"] for item in report[q] if item["task_id"] == "ROUNDTRIP-9"]
    if not methods.is_file():
        if any(i["state"] == "accepted" for i in roundtrip):
            raise ValueError("accepted ROUNDTRIP-9 has no methods.csv")
        print("ROUNDTRIP-9 has no methods.csv. Upstream reviews any blocker report.")
        return
    # Stage only the baseline and script from the trusted checkout alongside
    # candidate methods. The checker's relative paths are fixed by its contract.
    shutil.copyfile(HERE / "inbox/ROUNDTRIP-9/scheme-C.csv", methods.with_name("scheme-C.csv"))
    script = root / "handoff/assignments/check-roundtrip.ps1"
    shutil.copyfile(HERE / "assignments" / script.name, script)
    result = subprocess.run(["pwsh", "-NoProfile", "-NonInteractive", "-File", str(script)],
                            cwd=HERE, capture_output=True, text=True)
    if result.returncode:
        # PowerShell errors may quote untrusted method names. Emit a JSON
        # string so line breaks cannot inject GitHub workflow commands.
        raise ValueError("ROUNDTRIP-9: " + json.dumps(result.stderr[:4000], ensure_ascii=True))
    print("ROUNDTRIP-9: trusted method-table check passed.")


if __name__ == "__main__":
    with tempfile.TemporaryDirectory() as folder:
        candidate = Path(folder)
        snapshot(os.environ["CANDIDATE_REPO"], os.environ["CANDIDATE_SHA"], os.environ.pop("GH_READ_TOKEN", ""), candidate)
        inspect(candidate)
