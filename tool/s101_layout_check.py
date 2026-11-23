# -*- coding: utf-8 -*-
"""1c/1d: read() == layout_for() and new layout == pre-merge baseline, keyed by (table, column)."""
import argparse, importlib.util, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))


def keyed(rows):
    return {(r["table"], r["column"]): r for r in rows}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--baseline", default="_t14/layout-baseline-38b6814d.json")
    ap.add_argument("--original", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    a = ap.parse_args()
    import cli_tables
    from pe_reader import PE
    data = Path(a.original).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    R = cli_tables.read(data, off)["layout"]
    L = cli_tables.layout_for(data, off)["layout"]
    bad = 0
    kr, kl = keyed(R), keyed(L)
    if set(kr) != set(kl):
        print("1c key-set mismatch read=%d layout_for=%d" % (len(kr), len(kl)))
        bad += 1
    for k in sorted(set(kr) & set(kl)):
        if kr[k] != kl[k]:
            print("1c MISMATCH %s.%s read=%r layout_for=%r" % (k[0], k[1], kr[k], kl[k]))
            bad += 1
    base = json.loads(Path(a.baseline).read_text(encoding="utf-8"))
    kb = keyed(base["layout"])
    if set(kb) != set(kr):
        print("1d key-set mismatch baseline=%d new=%d" % (len(kb), len(kr)))
        bad += 1
    for k in sorted(set(kb) & set(kr)):
        if kb[k] != kr[k]:
            print("1d MISMATCH %s.%s baseline=%r new=%r" % (k[0], k[1], kb[k], kr[k]))
            bad += 1
    print("layout-check: columns=%d 1c_diffs=%d 1d_diffs=%d"
          % (len(kr), sum(1 for k in set(kr) | set(kl) if kr.get(k) != kl.get(k)),
             sum(1 for k in set(kr) | set(kb) if kr.get(k) != kb.get(k))))
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
