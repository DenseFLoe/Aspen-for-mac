# -*- coding: utf-8 -*-
"""stale-metrics detector (module split out of qa/gate.py).

l1_covers: no
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "stale-metrics"


def detect(task, item_dir, original, ctx):
    """l1_covers: no

    L1 reads run.json only and never recomputes metrics.json.  Numeric disagreements
    are defects; stale file hashes are advisory because some rounds pin a baseline.
    """
    hits = []
    mpath = find_one(item_dir, "metrics.json")
    cpath = find_one(item_dir, "calls.csv")
    covpath = find_one(item_dir, "coverage.csv")
    npath = find_one(item_dir, "native-functions.csv")
    if not mpath or not cpath:
        return hits, {"skipped": "metrics.json or calls.csv missing"}
    metrics = json.loads(read_text(mpath))
    calls = read_csv(cpath)
    actual = {"calls": len(calls), "calls_total": len(calls)}
    for cls in ("external", "boundary", "data", "unresolved"):
        actual[cls] = sum(1 for r in calls if (r.get("class") or "").strip() == cls)
    if covpath:
        cov = read_csv(covpath)
        actual["coverage_rows"] = len(cov)
        actual["rows"] = len(cov)
        actual["gaps"] = sum(1 for r in cov if (r.get("state") or "").strip() == "gap")
    if npath:
        actual["funcs"] = len(read_csv(npath))
    for key, want in sorted(actual.items()):
        if key not in metrics or isinstance(metrics[key], bool):
            continue
        got = metrics[key]
        if not isinstance(got, (int, float)) or int(got) == int(want):
            continue
        hits.append({"severity": "defect",
                     "locator": "metrics.json:%s" % key,
                     "evidence": "metrics declares %s=%s; the tables on disk recompute to %d" % (key, got, want),
                     "l1_said": "L1 does not read metrics.json", "we_said": "%s=%d" % (key, want)})
    for key in sorted(metrics):
        if not key.endswith("_sha256"):
            continue
        rel = key[:-7]
        cand = [os.path.join(item_dir, rel + ext) for ext in (".csv", ".json", ".md")]
        cand += [os.path.join(item_dir, "code", rel + ext) for ext in (".csv", ".json", ".md")]
        target = next((p for p in cand if os.path.isfile(p)), None)
        if not target:
            continue
        real = sha256_file(target)
        if real != str(metrics[key]).lower():
            rel = os.path.relpath(target, item_dir).replace("\\", "/")
            certified = False
            for dirpath, _dirs, fns in os.walk(item_dir):
                for fn in fns:
                    if not (re.search(r"fingerprint", fn, re.I) and fn.endswith(".json")):
                        continue
                    p = os.path.join(dirpath, fn)
                    if not is_current(item_dir, p, ctx):
                        continue
                    try:
                        body = json.loads(read_text(p))
                    except Exception:
                        continue
                    stack = [body]
                    while stack:
                        node = stack.pop()
                        if isinstance(node, dict):
                            for k, v in node.items():
                                if k.replace("\\", "/") == rel and isinstance(v, str) and v.lower() == real:
                                    certified = True
                                else:
                                    stack.append(v)
                        elif isinstance(node, list):
                            stack.extend(node)
            hits.append({"severity": "advisory" if certified else "defect",
                         "locator": "metrics.json:%s" % key,
                         "evidence": "declares %s..., disk has %s...%s" % (
                             str(metrics[key])[:16], real[:16],
                             " (superseded by this round's fingerprint table)" if certified else ""),
                         "l1_said": "L1 does not read metrics.json", "we_said": real})
    return hits, {"numeric_keys": len(actual)}
