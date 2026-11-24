# -*- coding: utf-8 -*-
"""wrong-symbol detector (module split out of qa/gate.py).

l1_covers: no
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "wrong-symbol"


def detect(task, item_dir, original, ctx):
    """l1_covers: no

    L1 never resolves an IAT slot to an import name, so a callee naming an API the
    original does not import there is invisible to it.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {}
    data = open(original, "rb").read()
    pe = prepared_pe(data)
    names, ordinals = {}, {}
    import pefile
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) or []:
        dll = entry.dll.decode("ascii", "replace").lower()
        for imp in entry.imports:
            if imp.name:
                names.setdefault(dll, set()).add(imp.name.decode("ascii", "replace"))
            if imp.ordinal is not None:
                ordinals.setdefault(dll, set()).add(int(imp.ordinal))
    rows = read_csv(cpath)
    for r in rows:
        callee = (r.get("callee") or "").strip()
        if not callee or "!" not in callee or re.match(r"^0x", callee):
            continue
        dll, member = callee.split("!", 1)
        dll = dll.lower()
        if member.startswith("#"):
            try:
                ordv = int(member[1:])
            except ValueError:
                continue
            if ordv in ordinals.get(dll, ()) or member in names.get(dll, ()):
                continue
        elif member in names.get(dll, ()):
            continue
        elif dll in names and any(member.startswith(n) or n.startswith(member)
                                  for n in names[dll]):
            continue  # prefix variants are a separate category
        hits.append({"severity": "defect", "locator": "calls.csv:%s" % (r.get("listing") or "-"),
                     "evidence": "declares %r, which is not an import of the pinned original" % callee})
    return hits, {"iat_dlls": len(names), "rows": len(rows)}
