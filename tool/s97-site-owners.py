# -*- coding: utf-8 -*-
"""Attribution check: site from the real listing + original bytes + function intervals."""
import argparse, csv, re, sys
from pathlib import Path

BLOCK = (0x4711, 0x476A)


def asm_rva(asm_lines, lineno):
    if 1 <= lineno <= len(asm_lines):
        m = re.match(r"\s*([0-9A-Fa-f]{6,16})\s+((?:[0-9A-Fa-f]{2}\s)+)", asm_lines[lineno - 1])
        if m:
            return int(m.group(1), 16)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", nargs="?", default=".")
    a = ap.parse_args()
    unit = Path(a.candidate_root).resolve() / "handoff" / "inbox" / "NATIVE-340"
    asm = (unit / "code/native.asm").read_text(encoding="utf-8").splitlines()
    starts = sorted(int(r["rva"], 16) for r in csv.DictReader(
        open(unit / "native-functions.csv", encoding="utf-8-sig")))
    rows = list(csv.DictReader(open(unit / "calls.csv", encoding="utf-8-sig")))
    bad, checked = [], 0
    for r in rows:
        if r.get("class") != "external":
            continue
        m = re.search(r"code/native\.asm#L(\d+)", r.get("listing") or "")
        if not m:
            continue
        checked += 1
        lineno = int(m.group(1))
        listing_rva = asm_rva(asm, lineno)
        note = r.get("note") or ""
        site_m = re.search(r"(?:指令 RVA|thunk @|原件)\s*(0x[0-9A-Fa-f]+)", note)
        site = int(site_m.group(1), 16) if site_m else listing_rva
        if listing_rva is not None and site is not None and listing_rva != site:
            bad.append((r["listing"], r["caller"],
                        "listing line points at 0x%X but the site is 0x%X" % (listing_rva, site)))
            continue
        owner = max((s for s in starts if s <= site), default=None)
        claimed = int(r["caller"], 16)
        if owner is not None and claimed != owner:
            bad.append((r["listing"], "0x%X" % claimed,
                        "site 0x%X must name census FUN_0x%X" % (site, owner)))
        if (BLOCK[0] <= site <= BLOCK[1] or site == 0x2BCF) and "待核" not in note:
            bad.append((r["listing"], "0x%X" % claimed,
                        "site 0x%X needs an explicit 待核依据 note" % site))
    for listing, owner, why in bad:
        print("MISMATCH listing=%s owner=%s %s" % (listing, owner, why))
    print("attribution: checked=%d mismatches=%d" % (checked, len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
