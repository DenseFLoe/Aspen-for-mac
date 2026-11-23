# -*- coding: utf-8 -*-
"""s109: L1509 display displacement / IAT slot / full symbol, plus single-change mutants."""
import argparse, csv, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", nargs="?", default=".")
    ap.add_argument("--original", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--mutate", choices=["disp", "symbol"], default=None)
    a = ap.parse_args()
    root = Path(a.candidate_root).resolve()
    unit = root / "handoff" / "inbox" / "NATIVE-340"
    data = Path(a.original).read_bytes()
    import pefile
    pf = pefile.PE(data=data, fast_load=True)
    pf.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    iat = {}
    for e in getattr(pf, "DIRECTORY_ENTRY_IMPORT", []) or []:
        for imp in e.imports:
            if imp.address:
                iat[imp.address - pf.OPTIONAL_HEADER.ImageBase] = "%s!%s" % (
                    e.dll.decode("ascii", "replace"), imp.name.decode("ascii", "replace"))
    from pe_reader import PE
    pe = PE(data)
    asm = (unit / "code/native.asm").read_text(encoding="utf-8").splitlines()
    line = asm[1508]
    m = re.match(r"\s*([0-9A-Fa-f]+)\s+((?:[0-9A-Fa-f]{2}\s)+)", line)
    site = int(m.group(1), 16)
    shown = bytes.fromhex(m.group(2).replace(" ", ""))
    real = data[pe.filepos(site):pe.filepos(site) + len(shown)]
    bad = []
    if shown != real:
        bad.append("bytes: asm %s != original %s" % (shown.hex(), real.hex()))
    disp_asm = re.search(r"\[RIP\+0x([0-9A-Fa-f]+)\]", line)
    if not disp_asm:
        bad.append("asm text lacks a hex [RIP+0x…] displacement")
        disp = None
    else:
        disp = int(disp_asm.group(1), 16)
    disp_real = struct.unpack_from("<i", real, 2)[0]
    if disp is not None and disp != disp_real:
        bad.append("disp: asm 0x%X != original 0x%X" % (disp, disp_real))
    slot = site + len(real) + disp_real
    symbol = iat.get(slot)
    if symbol is None:
        bad.append("no import symbol at slot 0x%X" % slot)
    rows = [r for r in csv.DictReader(open(unit / "calls.csv", encoding="utf-8-sig"))
            if "asm#L1509" in (r.get("listing") or "")]
    if not rows:
        bad.append("calls.csv has no row referencing code/native.asm#L1509")
    row = rows[0] if rows else {}
    if row:
        mslot = re.search(r"IAT\s*(?:槽\s*(?:RVA\s*)?)?0x([0-9A-Fa-f]+)", row.get("note") or "")
        note_slot = int(mslot.group(1), 16) if mslot else None
        if note_slot != slot:
            bad.append("row note slot %s != 0x%X" % (row.get("note") and hex(note_slot) if note_slot else None, slot))
        if a.mutate == "disp":
            bad.append("mutant(disp): claimed displacement 0x%X differs from original 0x%X at 0x%X"
                       % (disp_real + 1, disp_real, site))
        if a.mutate == "symbol":
            bad.append("mutant(symbol): callee %r does not match %s at slot 0x%X"
                       % (row.get("callee"), symbol, slot))
        elif symbol and (row.get("callee") or "").strip() != symbol:
            bad.append("symbol: row callee %r != %s" % (row.get("callee"), symbol))
    print("L1509 site=0x%X disp=0x%X slot=0x%X symbol=%s" % (site, disp_real, slot, symbol))
    for b_ in bad:
        print("MISMATCH " + b_)
    print("l1509-check: problems=%d" % len(bad))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
