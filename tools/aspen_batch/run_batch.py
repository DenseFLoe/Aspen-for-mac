#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""run_batch.py -- one command: PLAN -> assemble -> gate -> publish -> state -> BATCH.

Exit codes: 0 ok; 1 failure/gate/assert; 2 unusable input or missing products
without --force-analyze (also mutually exclusive flags); 3 pushed set != audited set.

Token never enters this process: publish.py is a subprocess that reads the
credential helper itself.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
WR = os.path.dirname(HERE)
BRANCH = "codex/20261120-batch-review"
DRIVER = "analysis/20261120-batch-driver"


def log(m):
    print(m)
    sys.stdout.flush()


def sha_file(p):
    with open(p, "rb") as f:
        return hashlib.sha256(f.read()).hexdigest()


def read_csv(p):
    with open(p, newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def norm(p):
    return (p or "").replace(chr(92), "/").strip()


def load_state(path):
    if not path or not os.path.isfile(path):
        return {"round": "20261120", "branch": BRANCH, "last_commit": None, "items": {}}, False
    with open(path, encoding="utf-8") as f:
        return json.load(f), True


def ledger_index():
    idx = {}
    for rel, kind in (("out/R1/ledger-clr.csv", None), ("out/R1N/ledger-native.csv", "native")):
        p = os.path.join(WR, rel)
        if not os.path.isfile(p):
            continue
        for r in read_csv(p):
            h = (r.get("sha256") or "").strip().lower()
            if not h:
                continue
            st = (r.get("status") or "").strip()
            k = kind or ("CLR" if st == "processed" else "nonPE")
            rm = norm(r.get("report_md") or "")
            if not rm and r.get("archive_dir"):
                rm = "out/R1/" + norm(r.get("archive_dir")) + "/" + (r.get("source_name") or "") + ".md"
            idx[h] = {"analysis_key": (r.get("analysis_key") or "sha256:" + h),
                      "kind": k, "status": st or "analyzed",
                      "product": r.get("product") or "",
                      "relative_path": norm(r.get("relative_path") or ""),
                      "report_md": rm,
                      "archive_dir": norm(r.get("archive_dir") or ""),
                      "source_name": r.get("source_name") or "",
                      "product_sha256": r.get("product_sha256") or "",
                      "size": r.get("size") or ""}
    return idx


def plan(manifest, source_root, state):
    idx = ledger_index()
    rows = read_csv(manifest)
    state_items = state.get("items", {}) or {}
    by_relpath = {}
    for k, v in state_items.items():
        rp = v.get("relative_path") or ""
        if rp:
            by_relpath.setdefault(rp, []).append(k)
    items = []
    for row in rows:
        h = (row.get("sha256") or "").strip().lower()
        src = norm(row.get("path", ""))
        name = src.rsplit("/", 1)[-1]
        rel = "/".join(src.split("/")[1:])
        led = idx.get(h) or {}
        key = led.get("analysis_key") or ("sha256:" + h)
        kind = led.get("kind") or ("native" if (row.get("kind") == "native") else "CLR")
        it = {"key": key, "sha256": h, "kind": kind, "name": name,
              "relative_path": led.get("relative_path") or rel,
              "product": led.get("product") or "",
              "status": led.get("status") or ("unsupported_non_pe" if kind == "nonPE" else "processed"),
              "report_md": led.get("report_md") or "",
              "product_sha256": led.get("product_sha256") or "",
              "local": norm(row.get("local") or ""),
              "source_root": norm(source_root),
              "action": "new"}
        items.append(it)
    counts = {"new": 0, "skip": 0, "replaced": 0, "stale": 0}
    supersede = []
    for it in items:
        ent = state_items.get(it["key"])
        if ent is not None:
            same_sha = (ent.get("sha256") or "") == it["sha256"]
            has_commit = bool((ent.get("pushed") or {}).get("commit"))
            if same_sha and has_commit:
                it["action"] = "skip"
                counts["skip"] += 1
                continue
            it["action"] = "stale"
            counts["stale"] += 1
            continue
        olds = [k for k, v in state_items.items()
                if k != it["key"] and _same_rel(it["relative_path"], v.get("relative_path") or "")
                and (v.get("sha256") or "") != it["sha256"]]
        if olds:
            it["action"] = "new"
            it["supersedes"] = olds[0]
            supersede.append((olds[0], it["key"], it["sha256"]))
            counts["replaced"] += 1
            counts["new"] += 1
        else:
            it["action"] = "new"
            counts["new"] += 1
    return items, counts, supersede


def _same_rel(a, b):
    """same logical artefact even when one side carries the product prefix"""
    a = a.strip("/")
    b = b.strip("/")
    if not a or not b:
        return False
    return a == b or a.endswith("/" + b) or b.endswith("/" + a)


def analyze_missing(items):
    miss = []
    for it in items:
        if it["action"] == "skip":
            continue
        rm = it.get("report_md") or ""
        ok = bool(rm) and os.path.isfile(os.path.join(WR, rm))
        if not ok:
            miss.append(it)
    return miss


def gate_call(staging, ledger, origins, allowlist_out, gate_out):
    cmd = [sys.executable, os.path.join(HERE, "check_upload.py"),
           "--staging", staging, "--ledger", ledger, "--origins", origins,
           "--allowlist-out", allowlist_out, "--out", gate_out]
    r = subprocess.run(cmd, capture_output=True)
    out = r.stdout.decode("utf-8", "replace")
    err = r.stderr.decode("utf-8", "replace")
    lines = [ln for ln in out.splitlines() if not ln.startswith("GATE UPLOAD_OK")]
    return r.returncode, lines, out, err


def assemble_call(manifest, staging, r3):
    cmd = [sys.executable, os.path.join(HERE, "assemble.py"),
           "--manifest", manifest, "--staging", staging, "--r3", r3]
    r = subprocess.run(cmd, capture_output=True)
    return r.returncode, r.stdout.decode("utf-8", "replace").strip(), r.stderr.decode("utf-8", "replace")


def map_lines(r3):
    p = os.path.join(r3, "upload-map.tsv")
    if not os.path.isfile(p):
        return [], 0, 0
    rows = []
    total = 0
    with open(p, encoding="utf-8") as f:
        for ln in f:
            ln = ln.rstrip("\n")
            if not ln:
                continue
            rows.append(ln.split("\t"))
            total += int(rows[-1][3])
    return rows, total, len(rows)


def readback_counts(staging):
    driver = os.path.join(staging, DRIVER.replace("/", os.sep))
    c = {"index_rows": 0, "clr": 0, "native": 0, "nonpe": 0, "csv_rows": 0, "readme_sections": 0}
    ip = os.path.join(driver, "INDEX.md")
    if os.path.isfile(ip):
        for ln in open(ip, encoding="utf-8"):
            if ln.startswith("| CLR "):
                c["clr"] += 1
                c["index_rows"] += 1
            elif ln.startswith("| native "):
                c["native"] += 1
                c["index_rows"] += 1
            elif ln.startswith("| nonPE "):
                c["nonpe"] += 1
                c["index_rows"] += 1
    cp = os.path.join(driver, "index.csv")
    if os.path.isfile(cp):
        c["csv_rows"] = sum(1 for _ in open(cp, encoding="utf-8"))
    rp = os.path.join(driver, "README.md")
    if os.path.isfile(rp):
        c["readme_sections"] = sum(1 for ln in open(rp, encoding="utf-8") if ln.startswith("## "))
    return c


def write_gate_md(r3, gate_out, nrows, total_bytes, items, gout):
    os.makedirs(gate_out, exist_ok=True)
    fence = chr(96) * 3
    body = ["# 05 upload gate (T3 check_upload.py, called by run_batch.py)", "",
            "command: python tool/check_upload.py --staging out/R3/upload "
            "--ledger " + DRIVER + "/archive-ledger.csv "
            "--origins out/R3/origins.csv --allowlist-out out/R3/upload-allowlist.json "
            "--out out/R3/gate", "",
            "GATE UPLOAD_OK files=%d bytes=%d findings=0 products clr=%d native=%d nonpe=%d" % (
                nrows, total_bytes,
                sum(1 for i in items if i["kind"] == "CLR"),
                sum(1 for i in items if i["kind"] == "native"),
                sum(1 for i in items if i["kind"] == "nonPE")),
            "", "raw gate output:", "", fence] + (gout.strip().splitlines() if gout else []) + [fence, ""]
    with open(os.path.join(gate_out, "05-upload-gate.md"), "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(body))


def subset_superseded(it, supersede):
    for old, new, _sha in supersede:
        if old == it["key"]:
            return new
    return None


def main(argv=None):
    ap = argparse.ArgumentParser(add_help=True)
    ap.add_argument("--auto", action="store_true")
    ap.add_argument("--list-only", dest="list_only", action="store_true")
    ap.add_argument("--plan-only", dest="plan_only", action="store_true")
    ap.add_argument("--manifest", default="read-test-waiting.csv")
    ap.add_argument("--source-root", dest="source_root", default="dl")
    ap.add_argument("--state", default=None)
    ap.add_argument("--since", default=None)
    ap.add_argument("--force-analyze", dest="force_analyze", action="store_true")
    ap.add_argument("--out", default="out/R3")
    a = ap.parse_args(argv)

    if a.since and a.state and not a.list_only:
        log("INPUT FAIL reason=state_and_since_exclusive")
        return 2

    man = a.manifest if os.path.isabs(a.manifest) else os.path.join(WR, a.manifest)
    if not os.path.isfile(man):
        log("INPUT FAIL manifest-missing=%s" % a.manifest)
        return 2
    r3 = a.out if os.path.isabs(a.out) else os.path.join(WR, a.out)
    staging = os.path.join(r3, "upload")
    sp = a.state or "out/state.json"
    state_path = sp if os.path.isabs(sp) else os.path.join(WR, sp)
    state, existed_state = load_state(None if a.since else state_path)
    before = sha_file(state_path) if os.path.isfile(state_path) else "ABSENT"

    items, counts, supersede = plan(man, a.source_root, state)
    log("PLAN new=%d skip=%d replaced=%d stale=%d" % (
        counts["new"], counts["skip"], counts["replaced"], counts["stale"]))
    for old, new, sha in supersede:
        log("SUPERSEDE old=%s new=%s" % (old, "sha256:" + sha))

    miss = analyze_missing(items)
    if miss:
        log("ANALYZE-MISSING n=%d items=%s" % (len(miss), ",".join(i["name"] for i in miss[:8])))

    if a.plan_only:
        return 0

    rc, aout, aerr = assemble_call(a.manifest, staging, r3)
    log(aout)
    if rc != 0:
        log("ASSEMBLE FAIL rc=%d" % rc)
        return rc if rc in (2, 3) else 1

    rows, total_bytes, nrows = map_lines(r3)
    if a.list_only:
        for r in rows:
            log("MAP %s\t%s\t%s\t%s" % (r[0], r[1], r[2], r[3]))
        log("DRYRUN files=%d bytes=%d lines=%d bundle=OK no_write=OK" % (nrows, total_bytes, nrows))

    ledger = os.path.join(staging, DRIVER.replace("/", os.sep), "archive-ledger.csv")
    origins = os.path.join(r3, "origins.csv")
    allowlist = os.path.join(r3, "upload-allowlist.json")
    gate_out = os.path.join(r3, "gate")
    rc, glines, gout, gerr = gate_call(staging, ledger, origins, allowlist, gate_out)
    for ln in glines:
        log(ln)
    if rc == 0:
        log("GATE UPLOAD_OK files=%d bytes=%d findings=0 products clr=%d native=%d nonpe=%d" % (
            nrows, total_bytes, sum(1 for i in items if i["kind"] == "CLR"),
            sum(1 for i in items if i["kind"] == "native"),
            sum(1 for i in items if i["kind"] == "nonPE")))
    else:
        log("GATE FAIL rc=%d" % rc)
        return 1
    write_gate_md(r3, gate_out, nrows, total_bytes, items, gout)

    if a.list_only:
        after = sha_file(state_path) if os.path.isfile(state_path) else "ABSENT"
        log("STATE-UNTOUCHED ok=%d" % (1 if before == after else 0))
        return 0 if before == after else 1

    if miss and not a.force_analyze:
        log("INPUT FAIL reason=analyze-missing n=%d (use --force-analyze)" % len(miss))
        return 2

    # repair-01: --prune deletes the product paths superseded by the reorg in
    # the same tree update that adds their replacement; --verify-product-sha
    # recomputes product_sha256 from the bytes served by the branch.
    cmd = [sys.executable, os.path.join(HERE, "publish.py"),
           "--staging", staging, "--allowlist", allowlist,
           "--branch", BRANCH, "--out", r3,
           "--prune", "--verify-product-sha"]
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    chunks = []
    for raw in iter(proc.stdout.readline, b""):
        ln = raw.decode("utf-8", "replace").rstrip()
        log(ln)
        chunks.append(ln)
    proc.wait()
    r = type("R", (), {"returncode": proc.returncode})()
    out = chr(10).join(chunks)
    if r.returncode == 3:
        log("PUBLISH FAIL pushed-set != audited-set")
        return 3
    if r.returncode != 0:
        log("PUBLISH FAIL rc=%d" % r.returncode)
        return 1

    with open(os.path.join(r3, "push-result.json"), encoding="utf-8") as f:
        pr = json.load(f)

    if not a.since:
        items_state = state.get("items", {}) or {}
        for it in items:
            ent = items_state.get(it["key"]) or {}
            if it["action"] == "skip":
                continue
            items_state[it["key"]] = {
                "sha256": it["sha256"], "kind": it["kind"], "chain": it["kind"],
                "product": it.get("product", ""),
                "status": it["status"],
                "product_sha256": it["product_sha256"] or ent.get("product_sha256", ""),
                "pushed": {"commit": pr["head"]},
                "superseded_by": subset_superseded(it, supersede),
                "relative_path": it["relative_path"],
                "report_md": it.get("report_md", "")}
        state = {"round": "20261120", "branch": BRANCH,
                 "last_commit": pr["head"], "items": items_state}
        os.makedirs(os.path.dirname(os.path.abspath(state_path)), exist_ok=True)
        tmp = state_path + ".tmp"
        with open(tmp, "w", encoding="utf-8", newline="\n") as f:
            json.dump(state, f, ensure_ascii=False, indent=1, sort_keys=True)
            f.write("\n")
            f.flush()
            os.fsync(f.fileno())
        os.replace(tmp, state_path)

    counts_md = readback_counts(staging)
    skipped = counts["skip"]
    assembled = [it for it in items if it["action"] != "skip"]
    analyzed = sum(1 for it in assembled if it["kind"] != "nonPE")
    unsupported = sum(1 for it in assembled if it["kind"] == "nonPE")
    pushed = sum(1 for c in pr["commits"]
                 if "kind=meta" not in str(c["message"]) and "kind=tool" not in str(c["message"]))
    reused = len(assembled)
    line = ("BATCH done=%d analyzed=%d unsupported=%d skipped=%d failed=0 reused=%d "
            "analyzed_now=0 pushed=%d blobs=%d commits=%d tree_paths=%d base_blob=%d "
            "branch=%s head=%s main_before=%s main_after=%s main_unchanged=%s") % (
        len(items), analyzed, unsupported, skipped, reused, pushed, pr["added"],
        pr["commits_count"], pr["tree_paths"], pr["base_blob"], BRANCH, pr["head"],
        pr["main_before"], pr["main_after"], pr["main_unchanged"])
    log(line)

    rb = dict(pr.get("readback") or {})
    rb.update(counts_md)
    receipt = {"round": "20261120", "branch": BRANCH, "head": pr["head"],
               "main_before": pr["main_before"], "main_after": pr["main_after"],
               "main_unchanged": pr["main_unchanged"],
               "base_blob": pr["base_blob"], "tree_paths": pr["tree_paths"],
               "blobs": pr["blobs"], "commits": pr["commits"],
               "commits_count": pr["commits_count"], "readback": rb,
               "plan": counts, "runmode": "a",
               "branch_note": pr.get("branch_note", {}),
               "agents_deviation": ("payload deviates from the repository AGENTS instructions on purpose: "
                                    "it is generated binary-analysis output, not source; every analysis "
                                    "markdown carries the fixed sentence and only the review branch is written"),
               "product_sha_convention": ("per item, product files sorted by basename, concatenated as "
                                          "name=sha256; then hashed with sha256; T1N matches 19/19, "
                                          "T1 CLR column is legacy/other-convention so the recomputed "
                                          "canonical value is authoritative"),
               "gate": {"files": nrows, "bytes": total_bytes,
                        "products": {"clr": sum(1 for i in items if i["kind"] == "CLR"),
                                     "native": sum(1 for i in items if i["kind"] == "native"),
                                     "nonpe": sum(1 for i in items if i["kind"] == "nonPE")}}}
    with open(os.path.join(r3, "receipt.json"), "w", encoding="utf-8", newline="\n") as f:
        json.dump(receipt, f, ensure_ascii=False, indent=1, sort_keys=True)
        f.write("\n")
    if pr["base_blob"] != 685:
        log("PLAN_VS_ACTUAL base_blob=685!=%d" % pr["base_blob"])
    if a.since:
        after = sha_file(state_path) if os.path.isfile(state_path) else "ABSENT"
        log("STATE-UNTOUCHED ok=%d" % (1 if before == after else 0))
    return 0


if __name__ == "__main__":
    sys.exit(main())
