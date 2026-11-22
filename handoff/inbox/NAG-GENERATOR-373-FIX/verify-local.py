"""Local equivalence proof for the twenty assertions while pr_head is pending.

Runs the trusted validator's own check() with (a) a placeholder 40-hex code head
and (b) a digest function resolving the three sources from this working tree, so
only the behavioural assertions remain. Expected output: PASS with no failures.
"""
import hashlib
import importlib.util
import json
import shutil
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
INBOX = Path(__file__).resolve().parent
SPEC = ROOT / "handoff/assignments/check-generator-revision.py"


def main():
    spec = importlib.util.spec_from_file_location("revision_validator", SPEC)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    scratch = Path(tempfile.mkdtemp(dir=str(ROOT)))
    try:
        work = scratch / "inbox"
        shutil.copytree(INBOX, work)
        report = json.loads((work / "results.json").read_bytes())
        report["pr_head"] = "0123456789abcdef0123456789abcdef01234567"
        (work / "results.json").write_bytes((json.dumps(report, indent=2) + "\n").encode("utf-8"))

        def digest_at(ref, path):
            return hashlib.sha256((ROOT / path).read_bytes()).hexdigest()

        refs, failures = module.check(work, None, digest_at)
        print("refs: %s" % refs)
        print("failures: %s" % failures)
        print("PASS" if not failures else "FAIL")
        return 0 if not failures else 1
    finally:
        shutil.rmtree(scratch)


if __name__ == "__main__":
    raise SystemExit(main())
