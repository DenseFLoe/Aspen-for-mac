
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Backtest for tool/preflight.py.

Truth comes from out/backtest/dataset.csv (one row per defect an upstream decision
actually raised, keyed by task + round).  Candidate trees come from the local snapshot
index.  Splits are by round time: rounds <= TRAIN_MAX are train, later rounds are test.

Reports, all recomputed:
  - per category recall / precision, train and test separately
  - generalization gap  = train_recall - test_recall
  - anti-memorization: locator/RVA shuffle, file rename, blind unseen head
"""
import argparse
import csv
import json
import os
import re
import shutil
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tool"))
import preflight as pf  # noqa: E402

TRAIN_MAX = 37
# detector -> dataset categories it is allowed to claim
DET_CATEGORY = {
    "det_omitted_sites": ["omitted-sites"],
    "det_stale_metrics": ["stale-metrics"],
    "det_row_linkage": ["row-linkage"],
    "det_fingerprint_pathset": ["fingerprint-pathset", "truncated-hash"],
    "det_unresolved_no_recovery": ["unresolved-no-recovery"],
    "det_symbol_substring": ["symbol-substring"],
    "det_wrong_symbol": ["wrong-symbol"],
    "det_byte_mismatch": ["byte-mismatch"],
    "det_access_flags": ["access-flags"],
    "det_receipt_paths": ["receipt-misstatement"],
    "det_eh_clause": ["clause-semantics"],
    "det_eh_boundary": ["eh-boundary"],
}
# detectors whose verdict depends on addresses inside the *original*, so a candidate-side
# locator shuffle cannot be required to preserve them
ORIGINAL_ANCHORED = {"det_omitted_sites", "det_byte_mismatch", "det_wrong_symbol"}


def load_truth(path):
    truth = {}
    with open(path, encoding="utf-8", newline="") as f:
        for row in csv.DictReader(f):
            key = (row["task"], int(row["round"].lstrip("s")))
            truth.setdefault(key, set()).add(row["category"])
    return truth


def load_candidates(path):
    best = {}
    for row in json.load(open(path, encoding="utf-8")):
        if row["top_round"] <= 0:
            continue
        key = (row["task"], row["top_round"])
        if key not in best or row["files"] > best[key]["files"]:
            best[key] = row
    return best


def predict(task, item_dir, original):
    rep = pf.aggregate(task, item_dir, original)
    cats, detail = set(), {}
    for name, r in rep["l2"].items():
        if not r.get("defects"):
            continue
        for cat in DET_CATEGORY.get(name, []):
            cats.add(cat)
            detail[cat] = r["defects"]
    return cats, detail, rep


def score(pairs):
    """pairs: list of (predicted:set, truth:set, weight)"""
    tp = fp = fn = 0
    per_cat = {}
    for pred, truth, _w in pairs:
        for c in pred & truth:
            tp += 1
            per_cat.setdefault(c, {"tp": 0, "fp": 0, "fn": 0})["tp"] += 1
        for c in pred - truth:
            fp += 1
            per_cat.setdefault(c, {"tp": 0, "fp": 0, "fn": 0})["fp"] += 1
        for c in truth - pred:
            fn += 1
            per_cat.setdefault(c, {"tp": 0, "fp": 0, "fn": 0})["fn"] += 1
    recall = tp / (tp + fn) if tp + fn else None
    precision = tp / (tp + fp) if tp + fp else None
    return {"tp": tp, "fp": fp, "fn": fn, "recall": recall, "precision": precision,
            "per_category": per_cat}


def fmt(x):
    return "n/a" if x is None else "%.2f" % x


# ------------------------------------------------------------ anti-memorization
HEXRE = re.compile(r"0x[0-9A-Fa-f]{3,16}")


def remap_tree(src, dst, delta, rename_asm=False):
    """Copy a candidate item dir, shifting every hex locator by delta consistently.

    The fixture must change *locators only*: declared digests are recomputed afterwards,
    otherwise a hash-consistency detector would fire for a reason unrelated to the shift.
    With rename_asm the listing files get unique new names and every reference follows.
    """
    if os.path.isdir(dst):
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    renames = {}
    if rename_asm:
        n = 0
        for dirpath, _dirs, fns in os.walk(dst):
            for fn in sorted(fns):
                if re.fullmatch(r"native[^/\\]*\.asm", fn, re.I):
                    n += 1
                    new = "x%d.asm" % n
                    os.replace(os.path.join(dirpath, fn), os.path.join(dirpath, new))
                    renames[fn] = new
    CELL = re.compile(r"^0x[0-9a-fA-F]{3,16}$")
    def shifted(text):
        # only whole-token cells are locators; rewriting hex inside file names such as
        # s25-verdict-0x06000030.json would invent paths that do not exist
        out = []
        for line in text.splitlines(keepends=True):
            body = line.rstrip("\r\n")
            if "/" in body or re.search(r"\.(json|csv|asm|md)\b", body):
                out.append(line)
                continue
            out.append(HEXRE.sub(lambda m: "0x%X" % (int(m.group(0), 16) + delta), line))
        return "".join(out)
    for dirpath, _dirs, fns in os.walk(dst):
        for fn in fns:
            low = fn.lower()
            p = os.path.join(dirpath, fn)
            if low.endswith(".csv"):
                try:
                    rows = pf.read_csv(p)
                    fields = list(rows[0].keys()) if rows else []
                except Exception:
                    rows, fields = [], []
                if rows:
                    for r in rows:
                        for k in fields:
                            v = (r.get(k) or "").strip()
                            if CELL.match(v):
                                v = "0x%X" % (int(v, 16) + delta)
                            for a, b in renames.items():
                                v = v.replace(a, b)
                            r[k] = v
                    with open(p, "w", encoding="utf-8", newline="") as f:
                        w = csv.DictWriter(f, fieldnames=fields)
                        w.writeheader()
                        w.writerows(rows)
            if not low.endswith((".asm", ".md", ".json")):
                continue
            try:
                text = pf.read_text(p)
            except Exception:
                continue
            new = shifted(text)
            for a, b in renames.items():
                new = new.replace(a, b)
            if new != text:
                with open(p, "w", encoding="utf-8", newline="") as f:
                    f.write(new)
    # re-certify declared digests so only locators differ from the original tree.
    # metrics.json is itself a declared target, so digest rewriting needs a few passes to
    # converge: rewriting a declared file changes its own digest.
    for _round in range(4):
        fresh = {}
        for dirpath, _dirs, fns in os.walk(dst):
            for fn in fns:
                p = os.path.join(dirpath, fn)
                fresh[os.path.relpath(p, dst).replace("\\", "/")] = pf.sha256_file(p)
        changed = False
        for dirpath, _dirs, fns in os.walk(dst):
            for fn in fns:
                if not (fn.endswith(".json") and ("fingerprint" in fn.lower() or fn == "metrics.json")):
                    continue
                p = os.path.join(dirpath, fn)
                try:
                    doc = json.loads(pf.read_text(p))
                except Exception:
                    continue
                def fix(node, key=""):
                    if isinstance(node, dict):
                        return {k: fix(v, k) for k, v in node.items()}
                    if isinstance(node, list):
                        return [fix(v, key) for v in node]
                    if isinstance(node, str) and re.fullmatch(r"[0-9a-fA-F]{64}", node):
                        rel = key[:-7].replace("\\", "/") if key.endswith("_sha256") else key.replace("\\", "/")
                        cand = [rel] + [prefix + rel + ext for ext in (".csv", ".json", ".md")
                                        for prefix in ("", "code/")]
                        for c in cand:
                            if c in fresh and fresh[c] != node:
                                return fresh[c]
                    return node
                new = fix(doc)
                if new != doc:
                    changed = True
                    with open(p, "w", encoding="utf-8") as f:
                        json.dump(new, f, ensure_ascii=False, indent=1)
        if not changed:
            break
    return dst


def fixture_problems(item_dir):
    """A fixture is only meaningful if its own references resolve.  If they do not, the
    anti-memorization verdict must be fixture-invalid, never 'stable'."""
    problems = []
    cpath = pf.find_one(item_dir, "calls.csv") if hasattr(pf, "find_one") else None
    if cpath is None:
        import preflight_common as C
        cpath = C.find_one(item_dir, "calls.csv")
    import preflight_common as C
    if not cpath:
        return ["no calls.csv in fixture"]
    rows = C.read_csv(cpath)
    if not rows:
        return ["empty calls.csv in fixture"]
    bad = 0
    for r in rows:
        if (r.get("class") or "").strip() == "data":
            continue
        ref = C.resolve_ref(item_dir, r.get("listing", ""))
        if not ref or not os.path.isfile(ref[0]):
            bad += 1
    if bad:
        problems.append("%d/%d non-data listing refs do not resolve to a file" % (bad, len(rows)))
    # every asm listing referenced must yield at least one address
    refs = {(C.resolve_ref(item_dir, r.get("listing", "")) or (None,))[0] for r in rows}
    for path in [p for p in refs if p]:
        if not C.asm_line_rva(path):
            problems.append("%s yields no parseable addresses" % os.path.relpath(path, item_dir))
    return problems


def anti_memorization(task, item_dir, original, rename=False):
    """Same structural defects must survive locator shuffling and file renaming."""
    base_cats, base_detail, _ = predict(task, item_dir, original)
    delta = 0x9D4A0
    with tempfile.TemporaryDirectory() as tmp:
        copy = os.path.join(tmp, "remapped")
        remap_tree(item_dir, copy, delta, rename_asm=rename)
        problems = fixture_problems(copy)
        if problems:
            return {"status": "fixture-invalid", "problems": problems,
                    "baseline": sorted(base_cats), "after": None,
                    "stable": None, "excluded_detectors": sorted(ORIGINAL_ANCHORED)}
        cats, detail, _ = predict(task, copy, original)
    dropped = sorted(base_cats - cats)
    added = sorted(cats - base_cats)
    return {"status": "checked", "baseline": sorted(base_cats), "after": sorted(cats),
            "dropped": dropped, "added": added,
            "stable": not dropped and not added,
            "excluded_detectors": sorted(ORIGINAL_ANCHORED)}


def cross_original_census():
    """A detector anchored on the original must work on *any* original, not one image."""
    out = {}
    for task, path in (("NATIVE-337", "_t13/orig/FindComponent.dll"),
                       ("NATIVE-338", "_t13/orig/Happ.dll"),
                       ("NATIVE-341", "_t13/orig/mmstruct.dll")):
        full = os.path.join(ROOT, path)
        try:
            data = open(full, "rb").read()
            pe = pf.prepared_pe(data)
            slots = pf.iat_slots(pe)
            sites = pf.iat_call_sites(data, pe, slots)
            out[task] = {"iat_slots": len(slots), "census": len(sites)}
        except Exception as exc:
            out[task] = {"error": "%s: %s" % (type(exc).__name__, exc)}
    return out


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--dataset", default="out/backtest/dataset.csv")
    ap.add_argument("--candidates", default="out/backtest/candidates.json")
    ap.add_argument("--json", default="out/backtest/backtest.json")
    ap.add_argument("--blind", nargs="*", default=[], help="item dirs never used for tuning")
    a = ap.parse_args(argv)
    truth = load_truth(os.path.join(ROOT, a.dataset))
    cands = load_candidates(os.path.join(ROOT, a.candidates))
    rows = []
    for (task, rnd), row in sorted(cands.items()):
        item = os.path.join(ROOT, row["path"])
        original = os.path.join(ROOT, pf.TASKS[task]["original"])
        try:
            cats, detail, rep = predict(task, item, original)
        except Exception as exc:
            rows.append({"task": task, "round": rnd, "error": "%s: %s" % (type(exc).__name__, exc)})
            continue
        truth_cats = truth.get((task, rnd), set())
        # L1 exits only 0 (accept) or 2 (declared gaps/unresolved).  Anything else means the
        # checker could not even read the tree, so the snapshot is not a submission and must
        # not be scored as a detector false positive.
        if rep["l1"].get("exit") not in (0, 2):
            rows.append({"task": task, "round": rnd, "split": "excluded",
                         "path": row["path"], "reason": "l1 exit %s" % rep["l1"].get("exit"),
                         "l1_stdout": (rep["l1"].get("stdout") or "")[:200]})
            continue
        rows.append({"task": task, "round": rnd,
                     "split": "train" if rnd <= TRAIN_MAX else "test",
                     "path": row["path"], "predicted": sorted(cats), "truth": sorted(truth_cats),
                     "detail": detail,
                     "l1_exit": rep["l1"].get("exit"), "l1_pin_ok": rep["l1"].get("pin_ok"),
                     "l2_exit": rep["l2_exit"], "warnings": len(rep["warnings"])})
    train = [(set(r["predicted"]), set(r["truth"]), 1) for r in rows if r.get("split") == "train"]
    test = [(set(r["predicted"]), set(r["truth"]), 1) for r in rows if r.get("split") == "test"]
    st, sx = score(train), score(test)
    # second口径: every dataset test instance counts, and a round we have no snapshot for
    # contributes a false negative for each of its categories (the honest lower bound)
    scored_test = {(r["task"], r["round"]) for r in rows if r.get("split") == "test"}
    uncovered = [(t, rnd, cats) for (t, rnd), cats in truth.items()
                 if rnd > TRAIN_MAX and (t, rnd) not in scored_test]
    full = {k: v for k, v in sx.items() if k != "per_category"}
    full["per_category"] = {c: dict(v) for c, v in sx["per_category"].items()}
    for _t, _r, cats in uncovered:
        for c in cats:
            full["fn"] += 1
            per = full["per_category"].setdefault(c, {"tp": 0, "fp": 0, "fn": 0})
            per["fn"] += 1
    full["recall"] = full["tp"] / (full["tp"] + full["fn"]) if full["tp"] + full["fn"] else None
    full["precision"] = full["tp"] / (full["tp"] + full["fp"]) if full["tp"] + full["fp"] else None
    gap = None
    if st["recall"] is not None and sx["recall"] is not None:
        gap = st["recall"] - sx["recall"]
    # anti-memorization on a snapshot that carries several defect classes
    # the fixture subject must actually have findings, otherwise a "stable" verdict is vacuous
    graded = [r for r in rows if r.get("split") in ("train", "test")]
    picks = ([r for r in graded if r.get("split") == "test" and len(r.get("predicted", [])) >= 2][:1]
             or [r for r in graded if len(r.get("predicted", [])) >= 1][:1]
             or graded[:1])
    anti = {}
    if picks:
        p = picks[0]
        item = os.path.join(ROOT, p["path"])
        original = os.path.join(ROOT, pf.TASKS[p["task"]]["original"])
        anti["locator_shuffle"] = anti_memorization(p["task"], item, original, rename=False)
        anti["file_rename"] = anti_memorization(p["task"], item, original, rename=True)
        anti["subject"] = {"task": p["task"], "round": p["round"], "path": p["path"]}
    anti["cross_original"] = cross_original_census()
    blind = []
    for d in a.blind:
        task = "NATIVE-340" if "NATIVE-340" in d else "NATIVE-337"
        original = os.path.join(ROOT, pf.TASKS[task]["original"])
        cats, detail, rep = predict(task, os.path.join(ROOT, d), original)
        blind.append({"task": task, "path": d, "predicted": sorted(cats), "detail": detail,
                      "l1_exit": rep["l1"].get("exit")})
    doc = {"train": st, "test": sx, "test_full": full,
           "uncovered_test_rounds": [{"task": t, "round": r, "categories": sorted(c)}
                                     for t, r, c in uncovered],
           "generalization_gap": gap, "generalization_gap_full":
               (st["recall"] - full["recall"]) if (st["recall"] is not None and full["recall"] is not None) else None,
           "rows": rows,
           "anti_memorization": anti, "blind": blind,
           "train_rounds": sorted({r["round"] for r in rows if r.get("split") == "train"}),
           "test_rounds": sorted({r["round"] for r in rows if r.get("split") == "test"})}
    json.dump(doc, open(os.path.join(ROOT, a.json), "w", encoding="utf-8"),
              ensure_ascii=False, indent=2)
    print("rounds: %d snapshots (train %d / test %d)"
          % (len(rows), len(train), len(test)))
    print("train  recall=%s precision=%s  tp=%d fp=%d fn=%d"
          % (fmt(st["recall"]), fmt(st["precision"]), st["tp"], st["fp"], st["fn"]))
    print("test   recall=%s precision=%s  tp=%d fp=%d fn=%d   (有快照口径)"
          % (fmt(sx["recall"]), fmt(sx["precision"]), sx["tp"], sx["fp"], sx["fn"]))
    print("test   recall=%s precision=%s  tp=%d fp=%d fn=%d   (全 test 段口径, %d 轮无快照计 FN)"
          % (fmt(full["recall"]), fmt(full["precision"]), full["tp"], full["fp"], full["fn"],
             len(uncovered)))
    print("generalization gap (train_recall - test_recall):", fmt(gap))
    cats = sorted(set(list(st["per_category"]) + list(sx["per_category"])))
    print("%-24s %-18s %-18s" % ("category", "train tp/fp/fn", "test tp/fp/fn"))
    for c in cats:
        t = st["per_category"].get(c, {"tp": 0, "fp": 0, "fn": 0})
        x = sx["per_category"].get(c, {"tp": 0, "fp": 0, "fn": 0})
        print("%-24s %-18s %-18s" % (c, "%d/%d/%d" % (t["tp"], t["fp"], t["fn"]),
                                     "%d/%d/%d" % (x["tp"], x["fp"], x["fn"])))
    for key in ("locator_shuffle", "file_rename"):
        if key in anti:
            v = anti[key]
            print("%s status=%s stable=%s dropped=%s added=%s problems=%s"
                  % (key, v.get("status"), v.get("stable"), v.get("dropped"), v.get("added"),
                     v.get("problems")))
    print("cross_original:", json.dumps(anti["cross_original"], ensure_ascii=False))
    for b in blind:
        print("blind %-44s predicted=%s l1_exit=%s" % (b["path"][-44:], b["predicted"], b["l1_exit"]))
    return 0


if __name__ == "__main__":
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass
    sys.exit(main())
