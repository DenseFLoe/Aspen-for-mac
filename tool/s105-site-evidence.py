# -*- coding: utf-8 -*-
"""s105: site rows vs the original (bytes, displacement, import symbol, half-open FUNC interval)."""
import argparse, csv, hashlib, json, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", nargs="?", default=".")
    ap.add_argument("--original", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    a = ap.parse_args()
    root = Path(a.candidate_root).resolve()
    unit = root / "handoff" / "inbox" / "NATIVE-340"
    data = Path(a.original).read_bytes()
    import pefile
    from pe_reader import PE
    pe = PE(data)
    pf = pefile.PE(data=data, fast_load=True)
    pf.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    iat = {}
    for entry in getattr(pf, "DIRECTORY_ENTRY_IMPORT", []) or []:
        dll = entry.dll.decode("ascii", "replace")
        for imp in entry.imports:
            if imp.address:
                iat[imp.address - pf.OPTIONAL_HEADER.ImageBase] = dll + "!" + imp.name.decode("ascii", "replace")
    asm = (unit / "code/native.asm").read_text(encoding="utf-8").splitlines()
    starts = sorted(int(r["rva"], 16) for r in csv.DictReader(
        open(unit / "native-functions.csv", encoding="utf-8-sig")))

    def line_rva(n):
        m = re.match(r"\s*([0-9A-Fa-f]{6,16})\s+", asm[n - 1])
        return int(m.group(1), 16) if m else None

    def line_bytes(n):
        m = re.match(r"\s*[0-9A-Fa-f]{6,16}\s+((?:[0-9A-Fa-f]{2}\s)+)", asm[n - 1])
        return bytes.fromhex(m.group(1).replace(" ", "")) if m else b""

    bad, checked = [], 0
    for r in csv.DictReader(open(unit / "calls.csv", encoding="utf-8-sig")):
        if r.get("class") != "external":
            continue
        m = re.search(r"code/native\.asm#L(\d+)", r.get("listing") or "")
        if not m:
            continue
        checked += 1
        n = int(m.group(1))
        site = line_rva(n)
        bts = line_bytes(n)
        real = data[pe.filepos(site):pe.filepos(site) + len(bts)]
        if bts != real:
            bad.append((r["listing"], "byte mismatch at 0x%X: listing=%s original=%s"
                        % (site, bts.hex(), real.hex())))
            continue
        if len(bts) >= 6 and bts[0] in (0x48, 0xFF):
            base = 0 if bts[0] == 0x48 else -1
            disp = struct.unpack_from("<i", bts, (1 if bts[0] == 0x48 else 0) + 2)[0]
            target = site + len(bts) + disp
            sym = iat.get(target, "?")
            if sym != "?" and sym not in (r.get("callee") or ""):
                bad.append((r["listing"], "symbol mismatch at 0x%X: IAT 0x%X is %s, row says %s"
                            % (site, target, sym, r.get("callee"))))
        owner = max((s for s in starts if s <= site), default=None)
        nxt = min((s for s in starts if s > site), default=None)
        if owner is None or (nxt is not None and site >= nxt):
            bad.append((r["listing"], "site 0x%X outside any [start,end) interval" % site))
        elif int(r["caller"], 16) != owner:
            bad.append((r["listing"], "site 0x%X owner %s != row caller %s"
                        % (site, hex(owner), r["caller"])))
    for listing, why in bad:
        print("MISMATCH listing=%s %s" % (listing, why))
    print("site-evidence: checked=%d mismatches=%d" % (checked, len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
