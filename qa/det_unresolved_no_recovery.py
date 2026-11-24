# -*- coding: utf-8 -*-
"""unresolved-no-recovery detector (module split out of qa/gate.py).

l1_covers: no
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "unresolved-no-recovery"


def detect(task, item_dir, original, ctx):
    """l1_covers: no

    L1 requires a note only for coverage state=gap rows, never for class=unresolved
    call rows, and never checks that the note is site-specific.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {"skipped": "calls.csv missing"}
    calls = read_csv(cpath)
    total = sum(1 for r in calls if (r.get("class") or "").strip() == "unresolved")
    groups = {}
    for i, r in enumerate(calls, 2):
        if (r.get("class") or "").strip() != "unresolved":
            continue
        note = (r.get("note") or "").strip()
        if not note:
            hits.append({"severity": "defect", "locator": "calls.csv:L%d" % i,
                         "evidence": "unresolved row without recovery text"})
            continue
        groups.setdefault(note, []).append(i)
    for note, rows in groups.items():
        if len(rows) < 5 or len(rows) < 0.5 * max(total, 1):
            continue
        hits.append({"severity": "defect", "locator": "calls.csv:L%d-L%d" % (rows[0], rows[-1]),
                     "evidence": "%d/%d unresolved rows share one identical recovery sentence starting '%s'"
                                 % (len(rows), total, note[:48])})
    return hits, {"unresolved_rows": total, "distinct_notes": len(groups)}
