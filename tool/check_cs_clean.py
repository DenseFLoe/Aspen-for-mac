#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Scan .cs.txt dumps for the ilspycmd upgrade notice that must never reach delivery.

Usage: python tool/check_cs_clean.py <dir> [<dir> ...]
Exit: 0 clean, 1 hits, 2 no files
"""
import sys
from pathlib import Path

NAG_HEAD = "You are not using the latest version of the tool"
NAG_VER = "Latest version is"


def scan(root):
    hits, total = [], 0
    for p in Path(root).rglob("*.cs.txt"):
        total += 1
        try:
            tail = p.read_text(encoding="utf-8", errors="replace").splitlines()[-3:]
        except OSError:
            continue
        if any(ln.startswith(NAG_HEAD) for ln in tail) or any(ln.startswith(NAG_VER) for ln in tail):
            hits.append(p)
    return total, hits


def main(argv=None):
    argv = argv if argv is not None else sys.argv[1:]
    if not argv:
        print("usage: check_cs_clean.py <dir> [...]")
        return 2
    grand = 0
    bad = 0
    for d in argv:
        total, hits = scan(d)
        grand += total
        bad += len(hits)
        print("%s files=%d nag_hits=%d" % (d, total, len(hits)))
        for h in hits[:5]:
            print("   HIT %s" % h)
    if grand == 0:
        print("CHECK_CS_CLEAN no_files")
        return 2
    print("CHECK_CS_CLEAN files=%d hits=%d %s" % (grand, bad, "OK" if bad == 0 else "FAIL"))
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
