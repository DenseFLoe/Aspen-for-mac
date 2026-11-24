
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Local preflight gate: L1 oracle (pinned) + L2 detectors.

Layer contract
  L1  the upstream checker, invoked verbatim and pinned by sha256.  Its exit code is
      authoritative.
  L2  our own detectors, one module per category under det_*.py, each declaring
      L1_COVERS in {yes, no, partial}.

Failure policy (this is the part the gate is judged on)
  * The pin is verified BEFORE the checker is executed.  A missing checker or a sha256
    mismatch is a gate failure: the checker is not run, and the result cannot be 0.
  * An L1 that could not be run is never silently replaced by the L2 verdict.  Only an
    explicit --skip-l1 is allowed to fall back, and the report says so.
  * A detector that fails to import, raises, or returns an explicit error is a gate
    failure.  Exceptions are not "notes".
  * A unit that examined nothing is not-applicable, never pass.  A run where every unit
    is not-applicable is itself a gate failure: nothing was checked.
"""
import argparse
import hashlib
import importlib
import json
import os
import subprocess
import sys
import tempfile

def _find_repo_root(start):
    cur = os.path.abspath(start)
    for _ in range(8):
        if any(os.path.exists(os.path.join(cur, m)) for m in
               (".git", "_t13", "handoff", "issue-materials", "out")):
            return cur
        parent = os.path.dirname(cur)
        if parent == cur:
            break
        cur = parent
    return os.path.dirname(os.path.abspath(start))


ROOT = _find_repo_root(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "qa") if os.path.isdir(os.path.join(ROOT, "qa")) else os.path.join(ROOT, "qa"))
from fetch import git_blob_sha1

# pin the vendored decoder stack once, before any detector imports capstone: two capstone
# 5.0.7 builds can decode a couple of skipdata boundaries differently (5,926 vs 5,928)
_vendor_dir = os.path.join(ROOT, ".local", "pylibs")
if os.path.isdir(_vendor_dir):
    if _vendor_dir in sys.path:
        sys.path.remove(_vendor_dir)
    sys.path.insert(0, _vendor_dir)

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
VALID_COVERS = {"yes", "no", "partial"}
EXIT_FAIL = 2


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def _covers(mod, name):
    raw = str(getattr(mod, "L1_COVERS", "")).strip().lower()
    if raw not in VALID_COVERS:
        return None, "invalid l1_covers %r for %s (must be one of %s)" % (
            getattr(mod, "L1_COVERS", None), name, sorted(VALID_COVERS))
    return raw, None


def load_detectors():
    """Import every module named in the registry.  A registered module that cannot be
    imported, or that exposes nothing callable, becomes a broken unit: it must be visible
    in the report and must not silently disappear."""
    reg = importlib.import_module("registry")
    seen, mods = set(), []
    for name in getattr(reg, "REGISTRY", []):
        if name in seen:
            continue
        seen.add(name)
        try:
            mod = importlib.import_module(name)
        except Exception as exc:
            mods.append({"name": name, "broken": "import failed: %s: %s" % (type(exc).__name__, exc)})
            continue
        if callable(getattr(mod, "detect", None)):
            mods.append(mod)
            continue
        reg_map = getattr(mod, "REGISTRY", None)
        if isinstance(reg_map, dict):
            for sub, fn in reg_map.items():
                if not callable(fn):
                    mods.append({"name": "%s:%s" % (name, sub), "broken": "registry entry is not callable"})
                    continue
                shim = type("Fragment", (), {})()
                shim.__name__ = "%s:%s" % (name, sub)
                shim.detect = fn
                shim.L1_COVERS = getattr(mod, "L1_COVERS", "no")
                shim.CATEGORY = sub
                shim.SOURCE = getattr(mod, "SOURCE", "?")
                mods.append(shim)
            continue
        mods.append({"name": name, "broken": "module exposes neither detect() nor REGISTRY"})
    return mods


def run_l1(task, item_dir, original, l1_path=None):
    """Verify the pin first, then run.  A pin problem means the checker is NOT executed and
    the gate fails: an unverified oracle is not an oracle."""
    path = l1_path or os.path.join(ROOT, L1_PIN["path"])
    seg = {"path": L1_PIN["path"], "sha256": None, "pin_ok": False, "argv": None,
           "exit": None, "stdout": "", "stderr": "", "authoritative": True,
           "ran": False, "status": None}
    if not os.path.isfile(path):
        seg["status"] = "missing"
        seg["error"] = "checker not found: " + path
        seg["exit"] = EXIT_FAIL
        return seg
    seg["sha256"] = sha256_file(path)
    seg["pin_ok"] = seg["sha256"] == L1_PIN["sha256"]
    if not seg["pin_ok"]:
        seg["status"] = "pin-mismatch"
        seg["error"] = "checker sha256 %s does not match the pin %s; not executed" % (
            seg["sha256"], L1_PIN["sha256"])
        seg["exit"] = EXIT_FAIL
        return seg
    argv = [sys.executable, "-B", path, task, "--original", original, "--submission", item_dir]
    seg["argv"] = argv
    proc = subprocess.run(argv, capture_output=True, text=True)
    seg["ran"] = True
    seg["exit"] = proc.returncode
    seg["stdout"] = (proc.stdout or "").strip()
    seg["stderr"] = (proc.stderr or "").strip()
    seg["status"] = "ran"
    if seg["exit"] not in (0, 1, 2):
        seg["error"] = "checker exited %s (not a verdict)" % seg["exit"]
    return seg


def check_head(item_dir, head):
    """Compare the delivery tree with a committed head by git blob identity."""
    sys.path.insert(0, str(ROOT))
    import gh
    tree = gh.call("GET", "/repos/%s/git/trees/%s?recursive=1" % (gh.REPO, head))
    if tree.get("truncated"):
        return [], {"error": "git tree for %s is truncated; the comparison would be partial" % head[:8]}
    prefix = "handoff/inbox/" + os.path.basename(os.path.abspath(item_dir)) + "/"
    want = {t["path"][len(prefix):]: t["sha"] for t in tree.get("tree", [])
            if t.get("type") == "blob" and t.get("path", "").startswith(prefix)}
    have = {}
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            p = os.path.join(dirpath, fn)
            rel = os.path.relpath(p, item_dir).replace(os.sep, "/")
            with open(p, "rb") as f:
                have[rel] = git_blob_sha1(f.read())
    if not want and not have:
        return [], {"error": "head %s declares no files and the item tree is empty" % head[:8]}
    hits = []
    for rel in sorted(set(want) - set(have)):
        hits.append({"severity": "defect", "locator": rel, "origin": "t14",
                     "evidence": "algo=git-blob-sha1 declared in head %s but missing on disk" % head[:8]})
    for rel in sorted(set(have) - set(want)):
        hits.append({"severity": "defect", "locator": rel, "origin": "t14",
                     "evidence": "algo=git-blob-sha1 on disk but not in head %s" % head[:8]})
    for rel in sorted(set(want) & set(have)):
        if want[rel] != have[rel]:
            hits.append({"severity": "defect", "locator": rel, "origin": "t14",
                         "evidence": "algo=git-blob-sha1 blob differs from head %s" % head[:8]})
    return hits, {"head": head, "declared": len(want), "on_disk": len(have)}


INPUT_KEYS = {
    "det_omitted_sites": "census",
    "det_stale_metrics": "numeric_keys",
    "det_row_linkage": "appendix_files",
    "det_fingerprint_pathset": "comparisons",
    "det_unresolved_no_recovery": "unresolved_rows",
    "det_symbol_substring": "rows",
    "det_wrong_symbol": "rows",
    "det_byte_mismatch": "instructions_checked",
    "det_access_flags": "rows_checked",
    "det_receipt_paths": "bound_rows",
    "det_eh_clause": "rows_checked",
    "det_eh_boundary": "rows_checked",
    "det_truncated_hash": "digests_compared",
    "det_access_prose": "documents_checked",
    "det_semantic_rebuild": "inputs_checked",
}


def unit_status(name, stats, defects):
    """Strict: the unit must publish a declared counter, as a positive int.  A missing or
    mistyped counter is an error, not something to paper over by summing other integers."""
    if isinstance(stats, dict) and stats.get("error"):
        return 0, "error"
    if isinstance(stats, dict) and stats.get("skipped"):
        return 0, "not-applicable"
    key = INPUT_KEYS.get(name)
    if key is None and ":" in name:
        key = INPUT_KEYS.get(name.split(":", 1)[0])
    if key is None:
        return 0, "error"
    if not isinstance(stats, dict) or key not in stats:
        return 0, "error"
    n = stats[key]
    if isinstance(n, bool) or not isinstance(n, int):
        return 0, "error"
    if defects:
        return n, "fail"
    return n, ("pass" if n > 0 else "not-applicable")


def aggregate(task, item_dir, original, l1_path=None, skip_l1=False):
    problems = []
    l1seg = {"skipped": True, "exit": None, "authoritative": False, "ran": False,
             "status": "skipped"}
    if not skip_l1:
        l1seg = run_l1(task, item_dir, original, l1_path)
        if not l1seg.get("ran"):
            problems.append("L1 did not run: %s" % l1seg.get("error", l1seg.get("status")))
        elif l1seg.get("exit") not in (0, 1, 2):
            problems.append("L1 exited %s, which is not a verdict" % l1seg.get("exit"))
    want_sha = TASKS.get(task, {}).get("original_sha256")
    got_sha = sha256_file(original)
    if want_sha and got_sha != want_sha:
        problems.append("original sha256 %s does not match the declared %s" % (got_sha, want_sha))
    reports, warnings, l2_exit, ctx = {}, [], 0, {}
    for mod in load_detectors():
        if isinstance(mod, dict):
            reports[mod["name"]] = {"name": mod["name"], "l1_covers": "no", "hits": [],
                                    "error": mod["broken"], "status": "error",
                                    "inputs_checked": 0, "defects": 0, "advisory": 0}
            l2_exit = EXIT_FAIL
            problems.append("%s: %s" % (mod["name"], mod["broken"]))
            continue
        name = mod.__name__
        covers, cover_err = _covers(mod, name)
        if cover_err:
            reports[name] = {"name": name, "l1_covers": str(getattr(mod, "L1_COVERS", "?")),
                             "hits": [], "error": cover_err, "status": "error",
                             "inputs_checked": 0, "defects": 0, "advisory": 0}
            l2_exit = EXIT_FAIL
            problems.append(cover_err)
            continue
        try:
            hits, stats = mod.detect(task, item_dir, original, ctx)
        except Exception as exc:
            reports[name] = {"name": name, "l1_covers": covers, "hits": [],
                             "error": "%s: %s" % (type(exc).__name__, exc), "status": "error",
                             "inputs_checked": 0, "defects": 0, "advisory": 0}
            l2_exit = EXIT_FAIL
            problems.append("%s raised %s: %s" % (name, type(exc).__name__, exc))
            continue
        if not isinstance(hits, list):
            reports[name] = {"name": name, "l1_covers": covers, "hits": [],
                             "error": "detect() did not return a hit list", "status": "error",
                             "inputs_checked": 0, "defects": 0, "advisory": 0}
            l2_exit = EXIT_FAIL
            problems.append("%s returned a non-list hit collection" % name)
            continue
        origin = getattr(mod, "SOURCE", "t16")
        for h in hits:
            h.setdefault("origin", origin)
        defects = [h for h in hits if h.get("severity") == "defect"]
        n_in, status = unit_status(name, stats, len(defects))
        reports[name] = {"name": name, "category": getattr(mod, "CATEGORY", name),
                         "l1_covers": covers, "origin": origin, "hits": hits,
                         "defects": len(defects), "advisory": len(hits) - len(defects),
                         "inputs_checked": n_in, "status": status, "stats": stats}
        if status == "error":
            l2_exit = EXIT_FAIL
            problems.append("%s: %s" % (name, (stats or {}).get("error", "no usable input counter")))
            continue
        if defects:
            if covers == "no" or not l1seg.get("ran"):
                l2_exit = EXIT_FAIL
            else:
                warnings.append({"detector": name, "l1_covers": covers,
                                 "l1_said": "L1 exited %s" % l1seg.get("exit"),
                                 "we_said": "%d defects" % len(defects), "hits": defects})

    roll = {"pass": 0, "fail": 0, "not-applicable": 0, "error": 0}
    for rep in reports.values():
        roll[rep.get("status", "error")] = roll.get(rep.get("status", "error"), 0) + 1
    if not reports:
        problems.append("no detector units loaded")
    elif roll["pass"] + roll["fail"] + roll["error"] == 0:
        problems.append("every unit was not-applicable: nothing was checked")

    algorithms = {"readback": "sha256", "declared_fingerprint": "sha256",
                  "head_compare": "git-blob-sha1"}
    l1_exit = l1seg.get("exit")
    if problems:
        final = EXIT_FAIL
    elif l1seg.get("ran") and l1_exit not in (0, None):
        final = l1_exit
    else:
        final = l2_exit
    return {"task": task, "algorithms": algorithms, "units": roll, "problems": problems,
            "item_dir": os.path.abspath(item_dir), "original": os.path.abspath(original),
            "original_sha256": got_sha, "l1": l1seg, "l2": reports, "l2_exit": l2_exit,
            "warnings": warnings, "exit": final,
            "l1_authoritative": bool(l1seg.get("ran"))}


CORE_TABLES = ("calls.csv", "coverage.csv", "metrics.json")


def emit_algorithms(rep, item_dir):
    import common as C
    algo = rep.get("algorithms", {})
    for name in CORE_TABLES:
        p = C.find_one(item_dir, name)
        if not p:
            continue
        print("readback: path=%s algo=%s value=%s" % (name, algo.get("readback", "sha256"),
                                                      C.sha256_file(p)[:16]))
    if rep.get("against_head"):
        print("headcompare: head=%s algo=%s files_declared=%s files_on_disk=%s"
              % (rep["against_head"]["stats"].get("head", "")[:8],
                 algo.get("head_compare", "git-blob-sha1"),
                 rep["against_head"]["stats"].get("declared"),
                 rep["against_head"]["stats"].get("on_disk")))


def main(argv=None):
    ap = argparse.ArgumentParser(description="L1 (pinned oracle) + L2 detectors")
    ap.add_argument("--task", choices=sorted(TASKS), default="NATIVE-337")
    ap.add_argument("--item-dir")
    ap.add_argument("--folder", help="alias of --item-dir")
    ap.add_argument("--head", help="full 40-character repository head SHA; fetch the task inbox first")
    ap.add_argument("--repo", default=None)
    ap.add_argument("--cache", default=None)
    ap.add_argument("--original")
    ap.add_argument("--binary", help="alias of --original")
    ap.add_argument("--l1-path")
    ap.add_argument("--against-head")
    ap.add_argument("--skip-l1", action="store_true")
    ap.add_argument("--json")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    item_dir = a.item_dir or a.folder or os.path.join(ROOT, "handoff", "inbox", a.task)
    fetched = None
    if a.head:
        import fetch
        cache = a.cache or os.path.join(ROOT, "_tools", "qa", "cache")
        try:
            owner, name, head, task = fetch.cache_key(a.repo or fetch.DEFAULT_REPO, a.head, a.task)
            repo = "%s/%s" % (owner, name)
            dest = os.path.join(cache, owner, name, head, task)
            item_dir = fetch.fetch_head(head, task, dest, repo=repo)
        except Exception as exc:
            # a fetch failure is a gate failure, not a traceback: nothing was checked
            print("fetch failed for head %s: %s: %s" % (a.head, type(exc).__name__, exc),
                  file=sys.stderr)
            return EXIT_FAIL
        fetched = {"repo": repo, "head": head, "task": task, "cache": os.path.realpath(dest)}
    item_dir = os.path.abspath(item_dir)
    original = os.path.abspath(a.original or a.binary or os.path.join(ROOT, TASKS[a.task]["original"]))
    l1_path = os.path.abspath(a.l1_path or os.path.join(ROOT, L1_PIN["path"]))
    print("paths: item_dir=%s original=%s l1=%s" % (item_dir, original, l1_path), file=sys.stderr)
    report_path = os.path.abspath(a.json) if a.json else None
    if report_path:
        from common import path_is_within
        if (path_is_within(item_dir, report_path)
                or path_is_within(os.path.realpath(item_dir), os.path.realpath(report_path))):
            print("report path must be outside the candidate tree: %s" % report_path, file=sys.stderr)
            return EXIT_FAIL
    head_hits, head_stats = ([], {})
    if a.against_head:
        head_hits, head_stats = check_head(item_dir, a.against_head)
    rep = aggregate(a.task, item_dir, original, l1_path, a.skip_l1)
    if fetched:
        rep["fetched"] = fetched
    if a.against_head:
        rep["against_head"] = dict(stats=head_stats, hits=head_hits, defects=len(head_hits))
        if head_stats.get("error"):
            rep["problems"].append("head comparison failed: %s" % head_stats["error"])
            rep["exit"] = EXIT_FAIL
        elif head_hits:
            rep["exit"] = EXIT_FAIL
    if report_path:
        with tempfile.TemporaryDirectory(dir=os.path.dirname(report_path)) as staging:
            staged_report = os.path.join(staging, "report.json")
            with open(staged_report, "w", encoding="utf-8") as f:
                json.dump(rep, f, ensure_ascii=False, indent=2)
            os.replace(staged_report, report_path)
    if not a.quiet:
        print("l1 pin_ok=%s ran=%s exit=%s :: %s" % (rep["l1"].get("pin_ok"),
                                                     rep["l1"].get("ran"), rep["l1"].get("exit"),
                                                     (rep["l1"].get("stdout") or "")[:120]))
        for name, r in rep["l2"].items():
            print("l2 %-24s l1_covers=%-7s inputs=%-6s status=%-14s defects=%-3d advisory=%-3d"
                  % (r.get("category", name), r["l1_covers"], r.get("inputs_checked", "?"),
                     r.get("status", "?"), r.get("defects", 0), r.get("advisory", 0)))
            if r.get("error"):
                print("     ! %s" % r["error"][:140])
            elif r.get("stats"):
                print("       stats: %s" % json.dumps(r["stats"], ensure_ascii=False)[:150])
            for h in r.get("hits", [])[:3]:
                print("     - [%s] %s :: %s" % (h.get("severity"), h["locator"], h["evidence"][:120]))
        for p in rep["problems"]:
            print("problem: %s" % p)
        if rep["warnings"]:
            print("warnings: %d" % len(rep["warnings"]))
        if rep.get("against_head"):
            print("head %s: declared=%d on_disk=%d defects=%d"
                  % (rep["against_head"]["stats"].get("head", "")[:8],
                     rep["against_head"]["stats"].get("declared", 0),
                     rep["against_head"]["stats"].get("on_disk", 0),
                     rep["against_head"]["defects"]))
        emit_algorithms(rep, item_dir)
        print("units: pass=%d fail=%d not-applicable=%d error=%d"
              % (rep["units"]["pass"], rep["units"]["fail"],
                 rep["units"]["not-applicable"], rep["units"]["error"]))
        print("exit:", rep["exit"])
    return rep["exit"]


if __name__ == "__main__":
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass
    sys.exit(main())
