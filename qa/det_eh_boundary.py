
# -*- coding: utf-8 -*-
"""EH section boundary detector (raw / virtual / file are three different limits).

l1_covers: no

L1 parses .pdata for anchors only and never looks at CLI EH data sections.  A reader that
treats the raw-file limit as the virtual limit (or vice versa) will accept a clause that
leaves the readable bytes, which is exactly the class upstream rejected on three rounds.

Truth is recomputed from the pinned original PE section headers plus our own clause decode.
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "eh-boundary"


def _sections(original):
    import pe as pe_reader
    pe = pe_reader.PE(open(original, "rb").read())
    out = []
    for s in pe.secs:
        out.append({"name": s["name"], "rva": s["rva"], "raw": s["raw"], "size": s["size"],
                    "vsize": s.get("vsize", s["size"]),
                    "raw_end": s["rva"] + s["size"], "virt_end": s["rva"] + s.get("vsize", s["size"])})
    return out


def _int(v):
    v = (v or "").strip()
    if not v:
        return None
    try:
        return int(v, 0) if v.lower().startswith("0x") else int(v, 10)
    except ValueError:
        return None


def _flag(v):
    v = (v or "").strip().lower()
    if v in ("true", "1", "yes", "y"):
        return True
    if v in ("false", "0", "no", "n"):
        return False
    return None


MUTATED_FIXTURE = ("mutated", "fixture", "synthetic", ".mutated.")


def _is_fixture(name):
    low = name.lower()
    return any(tok in low for tok in MUTATED_FIXTURE)


def detect(task, item_dir, original, ctx):
    hits = []
    secs = _sections(original)
    tables = rows_checked = 0
    found = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in sorted(fns):
            if not fn.endswith(".csv"):
                continue
            p = os.path.join(dirpath, fn)
            try:
                rows = C.read_csv(p)
            except Exception:
                continue
            if not rows:
                continue
            cols = {c.lower(): c for c in rows[0].keys()}
            if not ({"size", "clauses"} <= set(cols) or
                    {"raw_end", "virt_end"} <= set(cols) or
                    {"in_raw", "in_virtual", "in_file"} <= set(cols)):
                continue
            found.append((C.round_of(os.path.relpath(p, item_dir)) or 0, p, rows))
    newest = max([f[0] for f in found], default=0)
    for _rnd, p, rows in [f for f in found if f[0] == newest]:
            tables += 1
            rel = os.path.relpath(p, item_dir)
            for i, row in enumerate(rows, 2):
                loc = "%s:L%d" % (rel, i)
                rows_checked += 1
                width = _int(row.get(cols.get("clause_width", ""), "")) or _int(row.get(cols.get("entry", ""), ""))
                clauses = _int(row.get(cols.get("clauses", ""), ""))
                size = _int(row.get(cols.get("size", ""), "")) or _int(row.get(cols.get("header_size", ""), ""))
                payload = _int(row.get(cols.get("payload", ""), ""))
                if size is not None and width is not None and clauses:
                    expect = 4 + width * clauses
                    if size != expect:
                        hits.append({"severity": "defect", "locator": loc,
                                     "evidence": "size=%d but 4 + clause_width(%d) x clauses(%d) = %d"
                                                 % (size, width, clauses, expect)})
                if payload is not None and width is not None and clauses and clauses > 1 and width == payload:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "clause_width equals the whole payload (%d) for %d clauses; the "
                                             "per-clause width is %d" % (payload, clauses, payload // clauses)})
                raw_end = _int(row.get(cols.get("raw_end", ""), ""))
                virt_end = _int(row.get(cols.get("virt_end", ""), ""))
                if raw_end is not None or virt_end is not None:
                    rva = _int(row.get(cols.get("rva", ""), "")) or _int(row.get(cols.get("section", ""), ""))
                    sec = next((s for s in secs if rva is not None and s["rva"] <= rva < s["virt_end"]), None)
                    if sec:
                        if raw_end is not None and raw_end != sec["raw_end"]:
                            hits.append({"severity": "defect", "locator": loc,
                                         "evidence": "raw_end=%#x but the original section %s ends its raw data at %#x"
                                                     % (raw_end, sec["name"], sec["raw_end"])})
                        if virt_end is not None and virt_end != sec["virt_end"]:
                            hits.append({"severity": "defect", "locator": loc,
                                         "evidence": "virt_end=%#x but the original section %s has virtual end %#x"
                                                     % (virt_end, sec["name"], sec["virt_end"])})
                in_raw = _flag(row.get(cols.get("in_raw", ""), ""))
                if in_raw is True and raw_end is not None and size is not None and rva is not None:
                    if rva + size > raw_end:
                        hits.append({"severity": "defect", "locator": loc,
                                     "evidence": "row claims in_raw=True although %#x+%d exceeds the raw end %#x"
                                                 % (rva, size, raw_end)})
                in_file = _flag(row.get(cols.get("in_file", ""), ""))
                in_virt = _flag(row.get(cols.get("in_virtual", ""), ""))
                if in_file is True and in_raw is False:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "row claims in_file=True with in_raw=False; the file cannot be "
                                             "readable where the raw mapping ends"})
                if in_virt is True and in_raw is False and in_file is True:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "virtual/virtual/file flags are self-contradictory"})
    return hits, {"boundary_tables": tables, "rows_checked": rows_checked}
