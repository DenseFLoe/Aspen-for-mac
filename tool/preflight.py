
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Local preflight for NATIVE-337 / NATIVE-340.

Layer contract:

  L1  the upstream checker, invoked verbatim and pinned by sha256.  Its exit code is
      authoritative: nothing here may reinterpret or override it.
  L2  our own detectors, one module per category under tool/det_*.py.  Each module
      declares, in its docstring and as L1_COVERS:

        yes      L1 covers the category fully  -> cross-check only, never changes exit
        partial  L1 covers it partly           -> cross-check; disagreement is a warning
        no       L1 does not cover it          -> may contribute to the aggregate exit

This file holds only the L1 segment, the registry loader, the aggregation rule and the
CLI, so contributors add a tool/det_*.py plus one REGISTRY line instead of editing shared
code.  Detection inputs are the pinned original binary and the candidate item directory;
no upstream decision text, issue comment, sample sha256 or round-number branch is read.
"""
import argparse
import hashlib
import importlib
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tool"))

L1_PIN = {
    "path": "out/localrepo3/handoff/assignments/check-native-coverage.py",
    "sha256": "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8",
}
TASKS = {
    "NATIVE-337": {"original": "_t13/orig/FindComponent.dll",
                   "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"},
    "NATIVE-340": {"original": "_t13/orig/WrapSaveMergeNNFiles.dll",
                   "original_sha256": "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"},
}


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def load_detectors():
    """Import every module named in tool/det_registry.py, dedupe by module name."""
    reg = importlib.import_module("det_registry")
    seen, mods = set(), []
    for name in reg.REGISTRY:
        if name in seen:
            continue
        seen.add(name)
        try:
            mod = importlib.import_module(name)
        except Exception as exc:
            mods.append(type("Broken", (), {"__name__": name, "detect": None,
                                            "L1_COVERS": "no", "CATEGORY": name,
                                            "SOURCE": "?", "IMPORT_ERROR": "%s: %s" % (type(exc).__name__, exc)})())
            continue
        if callable(getattr(mod, "detect", None)):
            mods.append(mod)
    return mods


def run_l1(task, item_dir, original, l1_path=None):
    """Invoke the pinned upstream checker verbatim.  Its exit code is authoritative."""
    path = l1_path or os.path.join(ROOT, L1_PIN["path"])
    seg = {"path": L1_PIN["path"], "sha256": None, "pin_ok": False, "argv": None,
           "exit": None, "stdout": "", "stderr": "", "authoritative": True}
    if not os.path.isfile(path):
        seg["error"] = "checker not found: " + path
        return seg
    seg["sha256"] = sha256_file(path)
    seg["pin_ok"] = seg["sha256"] == L1_PIN["sha256"]
    argv = [sys.executable, "-B", path, task, "--original", original, "--submission", item_dir]
    seg["argv"] = argv
    proc = subprocess.run(argv, capture_output=True, text=True)
    seg["exit"] = proc.returncode
    seg["stdout"] = (proc.stdout or "").strip()
    seg["stderr"] = (proc.stderr or "").strip()
    return seg


def aggregate(task, item_dir, original, l1_path=None, skip_l1=False):
    l1seg = {"skipped": True, "exit": None, "authoritative": True}
    if not skip_l1:
        l1seg = run_l1(task, item_dir, original, l1_path)
    reports, warnings, l2_exit, ctx = {}, [], 0, {}
    for mod in load_detectors():
        name = mod.__name__
        if getattr(mod, "detect", None) is None:
            reports[name] = {"category": getattr(mod, "CATEGORY", name), "l1_covers": "no",
                             "error": getattr(mod, "IMPORT_ERROR", "import failed"), "hits": []}
            continue
        try:
            hits, stats = mod.detect(task, item_dir, original, ctx)
        except Exception as exc:
            reports[name] = {"category": getattr(mod, "CATEGORY", name),
                             "l1_covers": getattr(mod, "L1_COVERS", "no"),
                             "error": "%s: %s" % (type(exc).__name__, exc), "hits": []}
            continue
        origin = getattr(mod, "SOURCE", "t16")
        for h in hits:
            h.setdefault("origin", origin)
        defects = [h for h in hits if h.get("severity") == "defect"]
        covers = getattr(mod, "L1_COVERS", "no")
        reports[name] = {"category": getattr(mod, "CATEGORY", name), "l1_covers": covers,
                         "origin": origin, "hits": hits, "defects": len(defects),
                         "advisory": len(hits) - len(defects), "stats": stats}
        if covers in ("yes", "partial") and defects:
            warnings.append({"detector": name, "l1_covers": covers,
                             "l1_said": "L1 accepts this submission (exit %s)" % l1seg.get("exit"),
                             "we_said": "%d defects" % len(defects), "hits": defects})
        elif covers == "no" and defects:
            l2_exit = max(l2_exit, 2)
    return {"task": task, "item_dir": os.path.abspath(item_dir),
            "original": os.path.abspath(original), "original_sha256": sha256_file(original),
            "l1": l1seg, "l2": reports, "l2_exit": l2_exit, "warnings": warnings,
            "exit": l1seg.get("exit") if l1seg.get("exit") not in (None, 0) else l2_exit,
            "l1_authoritative": True}


def main(argv=None):
    ap = argparse.ArgumentParser(description="L1 (upstream, pinned) + L2 (tool/det_*.py)")
    ap.add_argument("--task", choices=sorted(TASKS), default="NATIVE-337")
    ap.add_argument("--item-dir")
    ap.add_argument("--folder", help="alias of --item-dir")
    ap.add_argument("--original")
    ap.add_argument("--binary", help="alias of --original")
    ap.add_argument("--l1-path")
    ap.add_argument("--skip-l1", action="store_true")
    ap.add_argument("--json")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    item_dir = a.item_dir or a.folder
    if not item_dir:
        ap.error("--item-dir is required")
    original = a.original or a.binary or os.path.join(ROOT, TASKS[a.task]["original"])
    rep = aggregate(a.task, item_dir, original, a.l1_path, a.skip_l1)
    if a.json:
        with open(a.json, "w", encoding="utf-8") as f:
            json.dump(rep, f, ensure_ascii=False, indent=2)
    if not a.quiet:
        print("l1 pin_ok=%s exit=%s :: %s" % (rep["l1"].get("pin_ok"), rep["l1"].get("exit"),
                                              (rep["l1"].get("stdout") or "")[:150]))
        for name, r in rep["l2"].items():
            print("l2 %-24s l1_covers=%-7s defects=%-3d advisory=%-3d"
                  % (r.get("category", name), r["l1_covers"], r.get("defects", 0), r.get("advisory", 0)))
            if r.get("stats"):
                print("       stats: %s" % json.dumps(r["stats"], ensure_ascii=False)[:150])
            for h in r.get("hits", [])[:3]:
                print("     - [%s] %s :: %s" % (h.get("severity"), h["locator"], h["evidence"][:120]))
        if rep["warnings"]:
            print("warnings: %d (L1 says accepted, we say defect)" % len(rep["warnings"]))
        print("exit:", rep["exit"])
    return rep["exit"]


if __name__ == "__main__":
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass
    sys.exit(main())
