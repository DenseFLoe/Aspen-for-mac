# -*- coding: utf-8 -*-
"""Width controls: coded-index widths AND the neighbouring column offset (single-source spec)."""
import argparse, importlib.util, sys
from pathlib import Path

EXPECT = {
    ("MemberRef", "Class"): (3, [2, 1, 26, 6, 27], 0),
    ("MethodImpl", "MethodBody"): (1, [6, 10], 0),
    ("MethodImpl", "MethodDeclaration"): (1, [6, 10], 0),
    ("CustomAttribute", "Type"): (3, [6, 10], 2),
    ("CustomAttribute", "Parent"): (5, [6, 4, 1, 2, 8, 9, 10, 0, 14, 23, 20, 17, 26, 27, 32, 35,
                                        38, 39, 40, 42, 43, 44], 0),
}
PAIRS = [("MemberRef", "Class", [8191, 8192]),
         ("CustomAttribute", "Type", [8191, 8192]),
         ("MethodImpl", "MethodBody", [16383, 16384, 32767, 32768])]


def load_module(path):
    spec = importlib.util.spec_from_file_location("cli_tables_probe", path)
    mod = importlib.util.module_from_spec(spec)
    sys.modules["cli_tables_probe"] = mod
    spec.loader.exec_module(mod)
    return mod


def width_of(kind, rows):
    bits, targets = kind[1], kind[2]
    return 2 if rows < (1 << (16 - bits)) else 4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", nargs="?", default=".")
    ap.add_argument("--lib", help="path to a cli_tables.py to check (default: <root>/tool/cli_tables.py)")
    a = ap.parse_args()
    root = Path(a.candidate_root).resolve()
    lib = Path(a.lib).resolve() if a.lib else root / "tool" / "cli_tables.py"
    ct = load_module(lib)
    ids = {v[0]: k for k, v in ct.TABLES.items()}
    bad = []
    for (table, column), (bits, targets, offset) in EXPECT.items():
        kind = ct.column_spec(ids[table], column)
        if not isinstance(kind, tuple) or kind[0] != "coded":
            bad.append((table, column, "not coded", kind)); continue
        got = (kind[1], list(kind[2]), kind[3] if len(kind) > 3 else 0)
        if got != (bits, targets, offset):
            bad.append((table, column, "spec %r != %r" % (got, (bits, targets, offset)), kind))
    for table, column, rows_list in PAIRS:
        tid = ids[table]
        spec = ct.TABLES[tid][1]
        names = [n for n, _ in spec]
        idx = names.index(column)
        def offset_of_next(rows):
            widths = [width_of(k, rows) if isinstance(k, tuple) and k[0] == "coded" else 2
                      for _, k in spec]
            return sum(widths[:idx + 1]), widths[idx]

        for lo, hi in zip(rows_list, rows_list[1:]):
            (o1, w1), (o2, w2) = offset_of_next(lo), offset_of_next(hi)
            if (w2 - w1) not in (0, 2) or (o2 - o1) != (w2 - w1):
                bad.append((table, "%s -> %s" % (column, names[idx + 1]) if idx + 1 < len(names) else column,
                            "next column offset did not follow width (w %d->%d, off %d->%d)"
                            % (w1, w2, o1, o2), lo))
    for table, column, why, extra in bad:
        print("MISMATCH table=%s column=%s %s (%r)" % (table, column, why, extra))
    print("width-controls: pairs=%d mismatches=%d" % (len(PAIRS), len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
