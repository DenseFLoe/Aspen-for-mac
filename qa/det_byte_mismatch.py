# -*- coding: utf-8 -*-
"""byte-mismatch detector (module split out of qa/gate.py).

l1_covers: partial
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "partial"
CATEGORY = "byte-mismatch"


def detect(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 compares first_bytes only at coverage entry points.  A listing line that claims
    bytes differing from the original at the same RVA is invisible to it.
    """
    hits = []
    code = os.path.join(item_dir, "code")
    if not os.path.isdir(code):
        return hits, {"skipped": "no code/ directory"}
    data = open(original, "rb").read()
    import pefile
    pe = pefile.PE(data=data, fast_load=True)

    def filepos(rva):
        return pe.get_offset_from_rva(rva)
    checked = 0
    for dirpath, _dirs, fns in os.walk(code):
        for fn in sorted(fns):
            if not re.search(r"native.*\.asm$", fn, re.I):
                continue
            if not is_current(item_dir, os.path.join(dirpath, fn), ctx):
                continue
            try:
                ins = C.parse_asm(os.path.join(dirpath, fn))
            except Exception:
                continue
            for (ln, addr, blob, _text) in ins:
                try:
                    start = filepos(addr)
                except Exception:
                    continue
                orig = data[start:start + len(blob)].hex()
                checked += 1
                if blob.hex() != orig:
                    hits.append({"severity": "defect",
                                 "locator": "%s#L%d" % (os.path.relpath(os.path.join(dirpath, fn), item_dir), ln),
                                 "evidence": "0x%X candidate bytes %s, original %s" % (addr, blob.hex(), orig)})
    return hits, {"instructions_checked": checked}
