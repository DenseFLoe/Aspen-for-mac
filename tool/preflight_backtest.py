
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
    """Copy a candidate item dir, shifting every hex locator by delta consistently and
    optionally renaming the listing file.  Structure must stay identical."""
    if os.path.isdir(dst):
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    mapping = {}
    for dirpath, _dirs, fns in os.walk(dst):
        for fn in fns:
            old = os.path.join(dirpath, fn)
            new_name = fn
            if rename_asm and re.fullmatch(r"native.*\.asm", fn, re.I):
                new_name = "x.asm"
                new = os.path.join(dirpath, new_name)
                os.replace(old, new)
                mapping[fn] = new_name
            if new_name.lower().endswith((".csv", ".asm", ".md")):
                p = os.path.join(dirpath, new_name)
                try:
                    text = pf.read_text(p)
                except Exception:
                    continue
                text = HEXRE.sub(lambda m: "0x%X" % (int(m.group(0), 16) + delta), text)
                if rename_asm and mapping:
                    for a, b in mapping.items():
                        text = text.replace(a, b)
                with open(p, "w", encoding="utf-8", newline="") as f:
                    f.write(text)
    return dst


def anti_memorization(task, item_dir, original, rename=False):
    """Same structural defects must survive locator shuffling and file renaming."""
    base_cats, base_detail, _ = predict(task, item_dir, original)
    delta = 0x9D4A0
    with tempfile.TemporaryDirectory() as tmp:
        copy = os.path.join(tmp, "remapped")
        remap_tree(item_dir, copy, delta, rename_asm=rename)
        cats, detail, _ = predict(task, copy, original)
    dropped = sorted(base_cats - cats)
    added = sorted(cats - base_cats)
    return {"baseline": sorted(base_cats), "after": sorted(cats),
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
        rows.append({"task": task, "round": rnd,
                     "split": "train" if rnd <= TRAIN_MAX else "test",
                     "path": row["path"], "predicted": sorted(cats), "truth": sorted(truth_cats),
                     "detail": detail,
                     "l1_exit": rep["l1"].get("exit"), "l1_pin_ok": rep["l1"].get("pin_ok"),
                     "l2_exit": rep["l2_exit"], "warnings": len(rep["warnings"])})
    train = [(set(r["predicted"]), set(r["truth"]), 1) for r in rows if r.get("split") == "train"]
    test = [(set(r["predicted"]), set(r["truth"]), 1) for r in rows if r.get("split") == "test"]
    st, sx = score(train), score(test)
    gap = None
    if st["recall"] is not None and sx["recall"] is not None:
        gap = st["recall"] - sx["recall"]
    # anti-memorization on a snapshot that carries several defect classes
    picks = [r for r in rows if r.get("split") == "test" and len(r.get("truth", [])) >= 2][:1] or \
            [r for r in rows if len(r.get("truth", [])) >= 2][:1]
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
    doc = {"train": st, "test": sx, "generalization_gap": gap, "rows": rows,
           "anti_memorization": anti, "blind": blind,
           "train_rounds": sorted({r["round"] for r in rows if r.get("split") == "train"}),
           "test_rounds": sorted({r["round"] for r in rows if r.get("split") == "test"})}
    json.dump(doc, open(os.path.join(ROOT, a.json), "w", encoding="utf-8"),
              ensure_ascii=False, indent=2)
    print("rounds: %d snapshots (train %d / test %d)"
          % (len(rows), len(train), len(test)))
    print("train  recall=%s precision=%s  tp=%d fp=%d fn=%d"
          % (fmt(st["recall"]), fmt(st["precision"]), st["tp"], st["fp"], st["fn"]))
    print("test   recall=%s precision=%s  tp=%d fp=%d fn=%d"
          % (fmt(sx["recall"]), fmt(sx["precision"]), sx["tp"], sx["fp"], sx["fn"]))
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
            print("%s stable=%s dropped=%s added=%s" % (key, v["stable"], v["dropped"], v["added"]))
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
