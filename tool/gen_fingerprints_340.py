# -*- coding: utf-8 -*-
"""Two fingerprint sets for NATIVE-340, runnable from a fixed commit.

  --set receipt : product hashes used by the upstream checker (path it reads:
                  code/s29-fingerprints.json).  Excludes receipts and other
                  fingerprint files so it stays stable across rounds.
  --set round   : the round receipt, includes receipts and the audit page, and
                  records the fixed base head it was produced from.
"""
import argparse, hashlib, json
from pathlib import Path


def collect(unit, include_receipts):
    out = {}
    for p in sorted(unit.rglob("*")):
        if not p.is_file() or p.name.endswith("fingerprints.json"):
            continue
        if not include_receipts and ("-submission.md" in p.name or "-started.md" in p.name):
            continue
        out[p.relative_to(unit).as_posix()] = hashlib.sha256(p.read_bytes()).hexdigest()
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--set", choices=("receipt", "round"), required=True)
    ap.add_argument("--unit", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--base-head", default="")
    a = ap.parse_args()
    files = collect(Path(a.unit), include_receipts=(a.set == "round"))
    if a.set == "receipt":
        # the upstream checker reads this file as a flat {path: sha256} map
        doc = files
    else:
        doc = dict(base_head=a.base_head, count=len(files), files=files)
    Path(a.out).write_text(json.dumps(doc, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("%s: %d files -> %s" % (a.set, len(files), a.out))


if __name__ == "__main__":
    main()
