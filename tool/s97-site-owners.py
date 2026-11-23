# -*- coding: utf-8 -*-
"""Site-owner check: IAT-thunk call rows name a census function and flag pending evidence."""
import argparse, csv, re, sys
from pathlib import Path

BLOCK = (0x4711, 0x476A)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", nargs="?", default=".")
    a = ap.parse_args()
    root = Path(a.candidate_root).resolve()
    unit = root / "handoff" / "inbox" / "NATIVE-340"
    starts = sorted(int(r["rva"], 16) for r in csv.DictReader(
        open(unit / "native-functions.csv", encoding="utf-8-sig")))
    rows = list(csv.DictReader(open(unit / "calls.csv", encoding="utf-8-sig")))
    bad, checked = [], 0
    for r in rows:
        if "IAT thunk" not in (r.get("note") or ""):
            continue
        checked += 1
        m = re.search(r"@?(0x[0-9A-Fa-f]+)", r["note"])
        rva = int(m.group(1), 16) if m else None
        owner = max((s for s in starts if s <= rva), default=None)
        claimed = int(r["caller"], 16)
        if owner is None:
            bad.append((r["listing"], r["caller"], "no census function at/below 0x%X" % rva)); continue
        if claimed != owner:
            bad.append((r["listing"], "0x%X" % claimed,
                        "site 0x%X must name census FUN_0x%X" % (rva, owner)))
        need_pending = BLOCK[0] <= rva <= BLOCK[1] or rva == 0x2BCF
        if need_pending and "待核" not in (r.get("note") or ""):
            bad.append((r["listing"], "0x%X" % claimed,
                        "site 0x%X needs an explicit 待核依据 note" % rva))
    for listing, owner, why in bad:
        print("MISMATCH listing=%s owner=%s %s" % (listing, owner, why))
    print("site-owners: checked=%d mismatches=%d" % (checked, len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
