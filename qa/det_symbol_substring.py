# -*- coding: utf-8 -*-
"""symbol-substring detector (module split out of qa/gate.py).

l1_covers: partial
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "partial"
CATEGORY = "symbol-substring"


def detect(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 checks that the listing contains the address, not that the symbol bound to a
    site is the exact imported identity.  Two symbols where one is a prefix of the
    other bound to the same site are a conflation risk.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {}
    rows = read_csv(cpath)
    by_site = {}
    for r in rows:
        key = tuple((r.get("listing") or "").split("#")[0:2])
        by_site.setdefault(key, []).append((r.get("callee") or "").strip())
    for site, callees in by_site.items():
        callees = [c for c in callees if c]
        for i, a in enumerate(callees):
            for b in callees[i + 1:]:
                if a != b and (a.startswith(b) or b.startswith(a)):
                    hits.append({"severity": "defect", "locator": "calls.csv:%s" % (site[0] or "-"),
                                 "evidence": "same site binds two prefix-relative symbols %r and %r" % (a, b)})
    # a callee that is a prefix-extension of an import the original really has (for example
    # OLEAUT32.dll!#23440 where the IAT holds #2344) is a conflation, not an unknown symbol
    try:
        data = open(original, "rb").read()
        known = set(C.iat_slots(C.prepared_pe(data)).values())
    except Exception:
        known = set()
    for r in rows:
        callee = (r.get("callee") or "").strip()
        if not callee or "!" not in callee or callee in known:
            continue
        dll, _, member = callee.partition("!")
        for k in known:
            kdll, _, kmember = k.partition("!")
            if kdll.lower() != dll.lower():
                continue
            if member != kmember and (member.startswith(kmember) or kmember.startswith(member)):
                hits.append({"severity": "defect", "locator": "calls.csv:%s" % (r.get("listing") or "-"),
                             "evidence": "%r is a prefix-extension of the import %r the original really has"
                                         % (member, kmember)})
                break
    for r in rows:
        callee, note = (r.get("callee") or "").strip(), r.get("note") or ""
        for m in re.finditer(r"([A-Za-z0-9_.\-]+!(?:#[0-9]+|[A-Za-z0-9_@?$.]+)|#[0-9]+)", note):
            sym = m.group(1)
            if callee and sym != callee and (sym.startswith(callee) or callee.startswith(sym)):
                hits.append({"severity": "defect", "locator": "calls.csv:%s" % (r.get("listing") or "-"),
                             "evidence": "note symbol %r is a prefix-relative variant of callee %r" % (sym, callee)})
    return hits, {"rows": len(rows)}
