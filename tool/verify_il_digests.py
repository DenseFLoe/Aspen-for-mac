# -*- coding: utf-8 -*-
"""Read-only IL digest re-check: delivery table vs the original binary, row identity kept."""
import argparse, csv, hashlib, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", required=True)
    ap.add_argument("--table", default="handoff/inbox/NATIVE-340/code/s89-il-digests.csv")
    a = ap.parse_args()
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    import struct
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    truth = {}
    for m in md_reader.parse(data, md_off)["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        truth["0x%08X" % m["token"]] = hashlib.sha256(hdr["il"]).hexdigest()
    with open(a.table, encoding="utf-8-sig", newline="") as fh:
        rows = list(csv.DictReader(fh, strict=True))
    bad = []
    seen = set()
    for r in rows:
        tok = r["token"]
        if tok in seen:
            bad.append((r["row"], tok, "duplicate token row"))
            continue
        seen.add(tok)
        want = truth.get(tok)
        if want is None:
            bad.append((r["row"], tok, "token not in original IL set"))
        elif want != r["sha256"]:
            bad.append((r["row"], tok, "digest differs from original"))
    missing = sorted(set(truth) - seen)
    for tok in missing:
        bad.append(("-", tok, "missing from delivery table"))
    for row, tok, why in bad:
        print("MISMATCH row=%s token=%s %s" % (row, tok, why))
    print("checked %d rows, mismatches %d" % (len(rows), len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
