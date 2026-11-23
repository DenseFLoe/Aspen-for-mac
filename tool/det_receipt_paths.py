# -*- coding: utf-8 -*-
"""receipt-misstatement detector (module split out of tool/preflight.py).

l1_covers: no
"""
import json
import os
import re

from preflight_common import *  # noqa: F401,F403
import preflight_common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "receipt-misstatement"


def detect(task, item_dir, original, ctx):
    """l1_covers: no

    L1 never reads the submissions.  Every code/... path and every sha256 named by the latest
    receipt must exist in the delivery or in tool/.
    """
    import hashlib
    hits = []
    root = os.path.dirname(os.path.dirname(os.path.abspath(item_dir)))
    mds = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            if re.match(r"s\d+-submission\.md$", fn):
                mds.append(os.path.join(dirpath, fn))
    if not mds:
        return hits, {"skipped": "no submission receipts"}
    mds.sort(key=lambda p: int(re.match(r"s(\d+)", os.path.basename(p)).group(1)))
    text = read_text(mds[-1])
    for rel in re.findall(r"code/[A-Za-z0-9_./-]+\.(?:csv|asm|json)", text):
        if not os.path.exists(os.path.join(item_dir, rel)):
            hits.append({"severity": "defect", "locator": os.path.basename(mds[-1]),
                         "evidence": "receipt names missing file %s" % rel})
    # A bare sha256 in prose may legitimately identify the pinned original, the trusted
    # checker or a tool build, so only hashes bound to a delivery path in a table row are
    # judged here; det_fingerprint_pathset owns the declared-path comparison.
    bound = 0
    for line in text.splitlines():
        m = re.match(r"[ \t]*\|[ \t]*([^|]+?)[ \t]*\|[ \t]*([0-9a-fA-F]{64})[ \t]*\|", line)
        if not m:
            continue
        label = (m.group(1) or "").replace(chr(96), "").strip()
        if not re.search(r"[/\\]|.(csv|json|asm|c|il|md|ps1|py|txt)$", label):
            continue
        bound += 1
        if not os.path.exists(os.path.join(item_dir, label)):
            hits.append({"severity": "defect", "locator": os.path.basename(mds[-1]),
                         "evidence": "receipt binds sha256 %s... to %s, which is absent from the delivery"
                                     % (m.group(2)[:16], label)})
    return hits, {"receipt": os.path.basename(mds[-1]), "bound_rows": bound}
