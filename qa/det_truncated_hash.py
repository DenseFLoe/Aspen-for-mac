
# -*- coding: utf-8 -*-
"""truncated-hash detector: a digest that is shorter than sha256 cannot identify a file.

l1_covers: no

L1 never inspects digest strings inside candidate tables.  Upstream rejected a delivery
whose il_sha256 carried only the first 32 hex characters; the same shape can appear in any
current-round csv/json column whose name mentions a hash.
"""
import csv
import os
import re

import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "truncated-hash"

HEX = re.compile(r"^[0-9a-fA-F]+$")


def _report(rel, where, value):
    return {"severity": "defect", "locator": "%s:%s" % (rel, where),
            "evidence": "digest has %d hex chars; a full sha256 has 64" % len(value.strip())}


def detect(task, item_dir, original, ctx):
    hits, errors = [], []
    found = parsed = compared = 0

    def compare(rel, where, value):
        nonlocal compared
        if HEX.fullmatch(value):
            compared += 1
            if len(value) != 64:
                hits.append(_report(rel, where, value))

    for dirpath, dirs, fns in os.walk(item_dir):
        dirs.sort()
        for fn in sorted(fns):
            low = fn.lower()
            if not low.endswith((".csv", ".json")):
                continue
            p = os.path.join(dirpath, fn)
            if not C.is_current(item_dir, p, ctx):
                continue
            rel = os.path.relpath(p, item_dir)
            found += 1
            is_csv = low.endswith(".csv")
            try:
                doc = C.read_csv(p) if is_csv else C.read_json(p)
            except (OSError, ValueError, csv.Error, RecursionError) as exc:
                errors.append("%s: %s" % (rel, exc))
                continue
            parsed += 1
            if is_csv:
                for i, row in enumerate(doc, 2):
                    for col, value in row.items():
                        if col and ("sha" in col.lower() or "digest" in col.lower()):
                            compare(rel, "L%d:%s" % (i, col), (value or "").strip())
                continue
            stack = [doc]
            while stack:
                node = stack.pop()
                if isinstance(node, dict):
                    for k, v in node.items():
                        if isinstance(v, str) and ("sha" in k.lower() or "digest" in k.lower()):
                            compare(rel, k, v)
                        else:
                            stack.append(v)
                elif isinstance(node, list):
                    stack.extend(node)
    stats = {"files_found": found, "files_parsed": parsed, "digests_compared": compared}
    if errors:
        stats["error"] = "; ".join(errors)
    return hits, stats
