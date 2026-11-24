# -*- coding: utf-8 -*-
"""row-linkage detector (module split out of qa/gate.py).

l1_covers: partial
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "partial"
CATEGORY = "row-linkage"


MUTATED_FIXTURE = ("mutated", "fixture", "synthetic", ".mutated.")


def _is_fixture(name):
    low = name.lower()
    return any(tok in low for tok in MUTATED_FIXTURE)


def detect(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 resolves listing refs and cross-checks indirect.csv as a subset, but never
    checks that appendix row references point at the table they claim, nor that a
    per-site column actually varies per site.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    calls = read_csv(cpath) if cpath else []
    row_col = re.compile(r"^(calls_row|calls_line|main_row|calls_row_no)$", re.I)
    site_col = re.compile(r"^(site|rva|address)$", re.I)
    addr_col = re.compile(r"(first_hop|thunk|target|iat_slot|calls_row|candidate_owner|original_host)$", re.I)
    files = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            if fn.endswith(".csv"):
                p = os.path.join(dirpath, fn)
                if cpath and os.path.normpath(p) == os.path.normpath(cpath):
                    continue
                if not is_current(item_dir, p, ctx):
                    continue
                try:
                    rows = read_csv(p)
                except Exception:
                    continue
                if rows:
                    files.append((p, rows))
    for path, rows in files:
        rel = os.path.relpath(path, item_dir)
        cols = list(rows[0].keys())
        for col in cols:
            vals = [(r.get(col) or "").strip() for r in rows]
            nonempty = [v for v in vals if v]
            if row_col.match(col) and not nonempty:
                hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                             "evidence": "column is empty for all %d rows; row linkage undelivered" % len(rows)})
                continue
            if not nonempty:
                continue
            if col.lower() in ("main_table_line", "main_row"):
                asm_like = [v for v in nonempty if re.search(r"\.(asm|il|txt)#L", v, re.I)]
                numeric = [c for c in cols if c != col and any((r.get(c) or "").strip().isdigit() for r in rows)]
                if asm_like and not numeric:
                    hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                                 "evidence": "%d/%d values point at an assembly listing (%s); the column claims a "
                                             "main-table row and the file carries no numeric row column"
                                             % (len(asm_like), len(nonempty), asm_like[0])})
                    continue
            if addr_col.search(col) and len(rows) >= 20 and len(set(nonempty)) == 1 and "0x" in nonempty[0].lower():
                hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                             "evidence": "all %d rows carry the same address-valued placeholder %s; the column "
                                         "cannot be per-site linkage" % (len(rows), nonempty[0])})
        if calls and row_col.search(" ".join(cols)):
            for col in cols:
                if not row_col.match(col):
                    continue
                for r in rows:
                    v = (r.get(col) or "").strip()
                    if not v.isdigit():
                        continue
                    n = int(v)
                    if n < 1 or n > len(calls):
                        hits.append({"severity": "defect", "locator": "%s:%s=%s" % (rel, col, v),
                                     "evidence": "calls.csv has %d rows; referenced row is out of range" % len(calls)})
    return hits, {"appendix_files": len(files)}
