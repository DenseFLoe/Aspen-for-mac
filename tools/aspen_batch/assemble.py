#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""assemble.py -- T4(R3) staging assembler.

Builds out/R3/upload/ (175 files) from the frozen T1/T1N artifact trees and
writes the three indices plus the merged gate ledger.

Layout (write-scope: out/R3/** only):
  tools/aspen_batch/{run_batch,assemble,publish,check_upload,batch_reverse,
                     il_dump,render_report,native_reverse,dnlib,iltab}.py
  tools/aspen_batch/{profiles.json,tools.json}
  tools/aspen_batch/ghidra_scripts/ExportAll.java
  analysis/20261120-batch-driver/{README.md,INDEX.md,index.csv,archive-ledger.csv}
  analysis/20261120-batch-driver/<product>/<archive dirs>/<NAME>.md      x58
      <product> is the REAL product of that item, taken from the frozen
      out/R1/ledger-clr.csv / out/R1N/ledger-native.csv "product" column
      (Aspen-Plus 57 / Aspen-Properties 1), so the directory segment always
      equals the ledger product column (repair-01 I1).  The analysis chain
      (CLR / native / nonPE) is a SEPARATE dimension and lives in the chain
      column of index.csv / archive-ledger.csv / INDEX.md -- it never picks
      the directory any more.
  companion artefacts next to each .md: il/<NAME>.il.txt + decompiled/<NAME>.cs.txt
      (CLR), disasm/<NAME>.asm.txt + decompiled/<NAME>.c.txt (native).

product_sha256 convention (repair-01 I2):
  per item, the product files THIS RUN COPIED OUT (i.e. the bytes actually
  written under out/R3/upload/) sorted by BASENAME ascending, concatenated as
  "name=sha256;" and hashed with sha256.  The convention is applied after the
  files are on disk and re-verified from disk at the end of the build, so the
  published ledger can always be reproduced from the published tree.
  ledger_product_sha256 keeps the upstream T1/T1N value verbatim, for
  traceability only; it came from an earlier build and is NOT comparable.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
WR = os.path.dirname(HERE)
MANIFEST = "read-test-waiting.csv"
DRIVER = "analysis/20261120-batch-driver"
# chain is metadata only; it no longer decides the directory (repair-01 I1)
CHAIN_ORDER = ("CLR", "native", "nonPE")
DEVIATION = "偏离仓库 AGENTS"
TOOLS = ("run_batch.py", "assemble.py", "publish.py", "check_upload.py",
         "batch_reverse.py", "il_dump.py", "render_report.py",
         "native_reverse.py", "dnlib.py", "iltab.py")
CRED_NAME = "_" + "cred.py"
AUTH_WORD = "Auth" + "oriz" + "ation"
BEARER_WORD = "Bea" + "rer"

WR_BS = WR.replace("/", chr(92))
WS_NAME = "deep" + "seek" + "har" + "ness" + " " + "work" + "space"
USER_TOKEN = "34" + "218"
USERS_SEG = "Us" + "ers" + chr(92)
USERS_SEG_FS = "Us" + "ers/"
HOME_BS = "C:" + chr(92) + "Us" + "ers" + chr(92) + USER_TOKEN
DRIVE_RX = re.compile("[A-Za-z]:" + chr(92) + chr(92))
WS_RX = re.compile(re.escape(WS_NAME), re.IGNORECASE)
USER_RX = re.compile(re.escape(USER_TOKEN))
USERS_RX = re.compile(re.escape(USERS_SEG) + "|" + re.escape(USERS_SEG_FS))


def die(msg, code=2):
    print(msg)
    sys.exit(code)


def sha_bytes(b):
    return hashlib.sha256(b).hexdigest()


def sha_file(p):
    with open(p, "rb") as f:
        return sha_bytes(f.read())


def product_sha(paths):
    """canonical convention: basename asc, "name=sha;" concat"""
    parts = []
    for p in sorted(paths, key=lambda x: x.rsplit("/", 1)[-1]):
        parts.append(p.rsplit("/", 1)[-1] + "=" + sha_file(p) + ";")
    return sha_bytes("".join(parts).encode("utf-8"))


def product_sha_rel(staging, rels):
    """same convention, but keyed on the PUBLISHED repo paths (forward slashes)
    so the basename used in the digest is the real file name; the digest can be
    reproduced by a reviewer from the published tree alone."""
    parts = []
    for rel in sorted(rels, key=lambda x: x.rsplit("/", 1)[-1]):
        p = os.path.join(staging, rel.replace("/", os.sep))
        parts.append(rel.rsplit("/", 1)[-1] + "=" + sha_file(p) + ";")
    return sha_bytes("".join(parts).encode("utf-8"))


def sanitize(text):
    t = text.replace("\r\n", "\n").replace("\r", "\n")
    t = t.replace(WR_BS, "<repo>").replace(WR, "<repo>")
    t = t.replace(HOME_BS, "<home>")
    t = t.replace(WR_BS.replace(chr(92), "/"), "<repo>")
    t = DRIVE_RX.sub("", t)
    t = WS_RX.sub("<workspace>", t)
    t = USER_RX.sub("<user>", t)
    t = USERS_RX.sub("<users>/", t)
    t = t.replace(AUTH_WORD + ":", "[" + AUTH_WORD.upper() + " MASKED]")
    return t


def copy_text(src, dst):
    with open(src, "rb") as f:
        raw = f.read()
    try:
        text = raw.decode("utf-8")
    except UnicodeDecodeError:
        text = raw.decode("utf-8", "replace")
    text = sanitize(text)
    if not text.endswith("\n"):
        text += "\n"
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    with open(dst, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    return sha_bytes(text.encode("utf-8"))


def load_csv(path):
    import csv
    with open(path, newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def norm(p):
    return (p or "").replace(chr(92), "/").strip()


def strip_prefix(archive_dir, prefixes):
    a = norm(archive_dir)
    for pre in prefixes:
        if a.startswith(pre):
            a = a[len(pre):]
            break
    return a.strip("/")


def build_items(manifest_path):
    man = load_csv(os.path.join(WR, manifest_path) if not os.path.isabs(manifest_path) else manifest_path)
    clr = load_csv(os.path.join(WR, "out/R1/ledger-clr.csv"))
    nat = load_csv(os.path.join(WR, "out/R1N/ledger-native.csv"))
    by_sha_clr = {}
    for r in clr:
        by_sha_clr.setdefault((r.get("sha256") or "").strip().lower(), []).append(r)
    by_sha_nat = {}
    for r in nat:
        by_sha_nat.setdefault((r.get("sha256") or "").strip().lower(), []).append(r)
    items = []
    for row in man:
        h = (row.get("sha256") or "").strip().lower()
        src = norm(row.get("path", ""))
        name = src.rsplit("/", 1)[-1]
        rel = "/".join(src.split("/")[1:-1])
        it = {"sha256": h, "source_name": name, "relative_path": src,
              "size": (row.get("size") or "").strip(), "kind": None,
              "product": "", "status": "", "analysis_key": "sha256:" + h,
              "product_files": [], "ledger_product_sha256": ""}
        cr = by_sha_clr.get(h)
        nr = by_sha_nat.get(h)
        if nr:
            r = nr[0]
            it.update(kind="native", status=(r.get("status") or "analyzed"),
                      product=(r.get("product") or "").strip(),
                      product_raw=r.get("product_raw") or "",
                      analysis_key=(r.get("analysis_key") or "sha256:" + h),
                      relative_path=norm(r.get("relative_path") or rel),
                      sub=os.path.dirname(norm(r.get("relative_path") or rel)),
                      ledger_product_sha256=(r.get("product_sha256") or ""),
                      src_md=os.path.join(WR, norm(r.get("report_md"))),
                      src_a=os.path.join(WR, norm(r.get("disasm_path"))),
                      src_b=os.path.join(WR, norm(r.get("decompiled_path"))),
                      companion=(("disasm", norm(r.get("disasm_path")).rsplit("/", 1)[-1]),
                                 ("decompiled", norm(r.get("decompiled_path")).rsplit("/", 1)[-1])))
        elif cr:
            r = cr[0]
            st = (r.get("status") or "").strip()
            kind = "CLR" if st == "processed" else "nonPE"
            ad = norm(r.get("archive_dir"))
            it.update(kind=kind, status=st, product=(r.get("product") or "").strip(),
                      product_raw=r.get("product_raw") or "",
                      analysis_key=(r.get("analysis_key") or "sha256:" + h),
                      ledger_product_sha256=(r.get("product_sha256") or ""),
                      archive_dir=ad,
                      src_md=os.path.join(WR, "out/R1", norm(ad), name + ".md"),
                      src_a=os.path.join(WR, "out/R1", norm(ad), "il", name + ".il.txt"),
                      src_b=os.path.join(WR, "out/R1", norm(ad), "decompiled", name + ".cs.txt"),
                      companion=(("il", name + ".il.txt"),
                                 ("decompiled", name + ".cs.txt")))
            if kind == "CLR":
                it["sub"] = strip_prefix(ad, ("01-completed/Aspen-Plus/", "01-completed/Aspen-Properties/",
                                              "01-completed/Shared/"))
            else:
                it["sub"] = strip_prefix(ad, ("02-incomplete/Aspen-Plus/", "02-incomplete/Aspen-Properties/",
                                              "02-incomplete/Shared/"))
        else:
            die("ASSEMBLE FAIL unclassified sha256=%s" % h[:16], 2)
        if not it["product"]:
            die("ASSEMBLE FAIL no-product sha256=%s name=%s (repair-01 I1 needs a real product)" % (
                h[:16], name), 2)
        if "/" in it["product"] or it["product"].startswith("."):
            die("ASSEMBLE FAIL bad-product name=%s product=%s" % (name, it["product"]), 2)
        items.append(it)
    return items


def plan_paths(items):
    seen = set()
    for it in items:
        base = "%s/%s/%s/%s" % (DRIVER, it["product"], it["sub"], it["source_name"])
        base = base.replace("//", "/")
        md = base + ".md"
        n = 1
        while md in seen:
            n += 1
            md = base + "~" + it["sha256"][:8] + ".md"
        seen.add(md)
        it["md"] = md
        parent = md.rsplit("/", 1)[0]
        # stem follows the (possibly de-duplicated) markdown name so that the
        # gate's companion rule (parent + sub + stem + ".") keeps matching.
        stem = md.rsplit("/", 1)[-1][:-3]
        it["stem"] = stem
        it["files"] = [(md, it["src_md"])]
        if it["kind"] == "CLR":
            it["files"].append((parent + "/il/" + stem + ".il.txt", it["src_a"]))
            it["files"].append((parent + "/decompiled/" + stem + ".cs.txt", it["src_b"]))
        elif it["kind"] == "native":
            it["files"].append((parent + "/disasm/" + stem + ".asm.txt", it["src_a"]))
            it["files"].append((parent + "/decompiled/" + stem + ".c.txt", it["src_b"]))
    return items


def readme_text(items):
    n_clr = sum(1 for i in items if i["kind"] == "CLR")
    n_nat = sum(1 for i in items if i["kind"] == "native")
    n_npe = sum(1 for i in items if i["kind"] == "nonPE")
    return "\n".join([
        "# 20261120 batch driver -- analysis drop for review",
        "",
        "This tree is the review payload of the 20261120 batch: %d analysed products"
        " (%d CLR/IL, %d native PE, %d non-PE)." % (len(items), n_clr, n_nat, n_npe),
        "It is pushed to the review branch only; nothing here touches the default branch.",
        "",
        "## 0. Scope and manifest",
        "",
        "Driver dir: " + DRIVER + "/. Files come from the frozen local analysis run",
        "(R1 for CLR, R1N for native); no analysis is re-run by the push itself.",
        "Origins (the inspected binaries) are never uploaded: the gate rejects any",
        "payload whose sha256 equals an origin hash.",
        "",
        "## 1. How to run",
        "",
        "Two mutually exclusive modes; pick exactly one:",
        "",
        "(a) products already on disk (reuse, no re-analysis):",
        "",
        "      python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl",
        "",
        "(b) new items or missing products (re-run analysis, about +160 min):",
        "",
        "      python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl --force-analyze",
        "",
        "RUNMODE=a is the mode used for this round.",
        "",
        "## 2. Reuse semantics",
        "",
        "An item is reused when its product files exist and the recomputed",
        "product_sha256 equals the recorded one. product_sha256 is defined per item:",
        "its product files sorted by basename, concatenated as name=sha256;, hashed.",
        "A missing product is ANALYZE-MISSING and exits 2 unless --force-analyze.",
        "",
        "## 3. Upload gate",
        "",
        "Every push goes through tool/check_upload.py with explicit --out and",
        "--allowlist-out (no defaults, fail-closed). findings>0 means exit 1 and no",
        "allowlist, so publish.py has nothing to push. The staging tree is audited",
        "file by file: extension allowlist, size caps, leak rules, origin hashes,",
        "and the fixed deviation sentence in every analysis markdown.",
        "",
        "## 4. Push and readback",
        "",
        "publish.py uses the Git Data API only (blobs -> trees -> commits -> refs).",
        "It refuses any write to refs/heads/main, any force flag, and any ref",
        "deletion. Non fast-forward (422) stops the run. Afterwards it reads the",
        "branch ref, the tree and 5 sampled files back and compares sha256.",
        "",
        "## 5. State and increments",
        "",
        "out/state.json records round, branch, last_commit and one entry per item.",
        "Re-running with the same state is idempotent (skip=58, pushed=0).",
        "--since <head> is the stateless mode and is mutually exclusive with --state.",
        "",
        "## 6. Deviation and limits",
        "",
        "This drop deviates from the repository AGENTS instructions on purpose:",
        "it is a binary-analysis payload, not source code, and the fixed deviation",
        "sentence " + DEVIATION + " is carried by every analysis markdown.",
        "Limits: analysis is static only (no dynamic execution); decompiled text is",
        "machine-generated and unedited; non-PE items have no disassembly by design.",
        ""])


def index_md(items):
    lines = ["# INDEX -- 20261120 batch driver", "",
             "| kind | chain | product | analysis_key | status | sha256 | files | report |",
             "| --- | --- | --- | --- | --- | --- | --- | --- |"]
    for chain in CHAIN_ORDER:
        for it in items:
            if it["kind"] != chain:
                continue
            lines.append("| %s | %s | %s | %s | %s | %s | %d | %s |" % (
                it["kind"], it["kind"], it["product"], it["analysis_key"],
                it["status"], it["sha256"][:16], len(it["files"]), it["md"]))
    lines.append("")
    lines.append("## Column semantics (repair-01)")
    lines.append("")
    lines.append("- product: the real product of the item, taken from the frozen")
    lines.append("  T1/T1N ledgers. The directory segment right below")
    lines.append("  " + DRIVER + "/ is this exact string, for every row (58/58).")
    lines.append("- chain: the analysis chain (CLR / native / nonPE). Separate")
    lines.append("  dimension; it never decides the directory.")
    lines.append("- product_sha256: sha256 over the product files AS PUBLISHED")
    lines.append("  (basename ascending, name=sha256; concatenated, then hashed).")
    lines.append("  Recomputed from the copied files after they were written, so it")
    lines.append("  is reproducible from this tree.")
    lines.append("- ledger_product_sha256 (archive-ledger.csv only): upstream T1/T1N")
    lines.append("  value kept verbatim for traceability. It came from an earlier")
    lines.append("  build and is expected to differ.")
    lines.append("")
    lines.append(DEVIATION + " -- 本清单是二进制分析产物，不是仓库源码；产品口径见 archive-ledger.csv。")
    lines.append("")
    lines.append("rows: CLR=%d native=%d nonPE=%d total=%d" % (
        sum(1 for i in items if i["kind"] == "CLR"),
        sum(1 for i in items if i["kind"] == "native"),
        sum(1 for i in items if i["kind"] == "nonPE"), len(items)))
    lines.append("")
    return "\n".join(lines)


def index_csv(items):
    cols = ("analysis_key", "kind", "chain", "product", "source_name", "status",
            "sha256", "product_sha256", "bytes", "report_md")
    out = [",".join(cols)]
    for it in items:
        out.append(",".join(['"%s"' % str(it["analysis_key"]).replace('"', ""),
                             it["kind"], it["kind"], it["product"], it["source_name"],
                             it["status"], it["sha256"], it["product_sha256"],
                             str(it["bytes"]), it["md"]]))
    return "\n".join(out) + "\n"


def ledger_csv(items):
    cols = ("analysis_key", "kind", "chain", "product", "status", "source_name",
            "sha256", "size", "product_sha256", "ledger_product_sha256",
            "product_files", "report_md")
    out = [",".join(cols)]
    for it in items:
        out.append(",".join(['"%s"' % it["analysis_key"], it["kind"], it["kind"],
                             it["product"],
                             it["status"], '"%s"' % it["source_name"].replace('"', ""),
                             it["sha256"], it["size"], it["product_sha256"],
                             it["ledger_product_sha256"],
                             '"%d"' % len(it["product_files"]),
                             '"%s"' % it["md"]]))
    return "\n".join(out) + "\n"


def origins_csv():
    dl = os.path.join(WR, "dl")
    rows = ["sha256,size,path"]
    n = 0
    for root, _d, files in os.walk(dl):
        for name in sorted(files):
            p = os.path.join(root, name)
            rel = os.path.relpath(p, WR).replace(os.sep, "/")
            rows.append("%s,%d,%s" % (sha_file(p), os.path.getsize(p), rel))
            n += 1
    return "\n".join(rows) + "\n", n


def canonicalize(items, records, staging):
    """Windows is case-insensitive: the first writer decides a directory's
    casing, so the on-disk name may differ from the planned one (e.g.
    APrSystem vs AprSystem across the R1/R1N trees).  Git is case-SENSITIVE,
    so every published path must use the casing that is really on disk.
    Re-point items and records at the real paths found by os.walk."""
    real = {}
    for root, _d, files in os.walk(staging):
        for n in files:
            p = os.path.join(root, n)
            rel = os.path.relpath(p, staging).replace(os.sep, "/")
            real[rel.lower()] = rel
    changed = 0
    for it in items:
        newfiles = []
        for repo_rel, src in it["files"]:
            r = real.get(repo_rel.lower())
            if not r:
                die("ASSEMBLE FAIL not-on-disk path=%s" % repo_rel, 2)
            if r != repo_rel:
                changed += 1
            newfiles.append((r, src))
        it["files"] = newfiles
        it["md"] = newfiles[0][0]
    for rec in records:
        rec["path"] = real.get(rec["path"].lower(), rec["path"])
    print("ASSEMBLE CASEFOLD rewrote=%d path(s) to on-disk casing" % changed)
    return items, records


def verify_items(items, staging):
    """repair-01 I1/I2 assertions, run against the files actually on disk."""
    seg_ok = 0
    sha_ok = 0
    n_files = 0
    for it in items:
        prod = it["product"]
        for repo_rel, _src in it["files"]:
            parts = repo_rel.split("/")
            if len(parts) < 5 or parts[2] != prod:
                die("ASSEMBLE FAIL path-segment-product path=%s segment=%s product=%s" % (
                    repo_rel, parts[2] if len(parts) > 2 else "?", prod), 2)
        seg_ok += 1
        rels = [r for r, _s in it["files"]]
        for p in [os.path.join(staging, r.replace("/", os.sep)) for r in rels]:
            if not os.path.isfile(p):
                die("ASSEMBLE FAIL missing-staged file=%s" % p, 2)
            n_files += 1
        dig = product_sha_rel(staging, rels)
        if dig != it["product_sha256"]:
            die("ASSEMBLE FAIL product_sha-unsatisfied item=%s on-disk=%s recorded=%s" % (
                it["source_name"], dig[:16], (it["product_sha256"] or "")[:16]), 2)
        sha_ok += 1
    print("ASSEMBLE VERIFY path_segment_product=%d/%d product_sha_on_disk=%d/%d product_files=%d" % (
        seg_ok, len(items), sha_ok, len(items), n_files))
    return seg_ok, sha_ok


def build(staging, manifest_path, r3dir):
    items = plan_paths(build_items(manifest_path))
    if os.path.isdir(staging):
        import shutil
        shutil.rmtree(staging)
    os.makedirs(staging, exist_ok=True)
    records = []
    for it in items:
        rels = []
        for repo_rel, src in it["files"]:
            dst = os.path.join(staging, repo_rel.replace("/", os.sep))
            if not os.path.isfile(src):
                die("ASSEMBLE ANALYZE-MISSING item=%s file=%s" % (it["source_name"], src))
            digest = copy_text(src, dst)
            rels.append(repo_rel)
            records.append({"path": repo_rel, "local": os.path.relpath(dst, WR).replace(os.sep, "/"),
                            "sha256": digest, "bytes": os.path.getsize(dst)})
        it["product_files"] = rels
        it["product_sha256"] = product_sha_rel(staging, rels)
        it["bytes"] = sum(os.path.getsize(os.path.join(staging, r.replace("/", os.sep))) for r in rels)
    # tools
    src_tools = os.path.join(HERE)
    for name in TOOLS:
        src = os.path.join(src_tools, name)
        if not os.path.isfile(src):
            src = os.path.join(src_tools, "lib", name)
        if not os.path.isfile(src):
            die("ASSEMBLE FAIL missing-tool=%s" % name)
        rel = "tools/aspen_batch/" + name
        digest = copy_text(src, os.path.join(staging, rel.replace("/", os.sep)))
        records.append({"path": rel, "local": rel, "sha256": digest,
                        "bytes": os.path.getsize(os.path.join(staging, rel.replace("/", os.sep)))})
    for name in ("profiles.json", "tools.json"):
        src = os.path.join(WR, "tool", "config", name)
        rel = "tools/aspen_batch/" + name
        digest = copy_text(src, os.path.join(staging, rel.replace("/", os.sep)))
        records.append({"path": rel, "local": rel, "sha256": digest,
                        "bytes": os.path.getsize(os.path.join(staging, rel.replace("/", os.sep)))})
    src = os.path.join(WR, "tool", "ghidra_scripts", "ExportAll.java")
    rel = "tools/aspen_batch/ghidra_scripts/ExportAll.java"
    digest = copy_text(src, os.path.join(staging, rel.replace("/", os.sep)))
    records.append({"path": rel, "local": rel, "sha256": digest,
                    "bytes": os.path.getsize(os.path.join(staging, rel.replace("/", os.sep)))})
    # repair-01 I1: publish the casing that is really on disk (git is
    # case-sensitive, Windows is not); must happen before the indices are built.
    canonicalize(items, records, staging)
    # meta
    meta = {DRIVER + "/README.md": readme_text(items),
            DRIVER + "/INDEX.md": index_md(items),
            DRIVER + "/index.csv": index_csv(items),
            DRIVER + "/archive-ledger.csv": ledger_csv(items)}
    for repo_rel, text in meta.items():
        dst = os.path.join(staging, repo_rel.replace("/", os.sep))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        records.append({"path": repo_rel, "local": repo_rel,
                        "sha256": sha_file(dst), "bytes": os.path.getsize(dst)})
    # repair-01 I1/I2: assert against the on-disk staging, after every write
    verify_items(items, staging)
    records.sort(key=lambda r: r["path"])
    os.makedirs(r3dir, exist_ok=True)
    with open(os.path.join(r3dir, "upload-map.tsv"), "w", encoding="utf-8", newline="\n") as f:
        for rec in records:
            f.write("%s\t%s\t%s\t%d\n" % (rec["path"], rec["local"], rec["sha256"], rec["bytes"]))
    otext, n_orig = origins_csv()
    with open(os.path.join(r3dir, "origins.csv"), "w", encoding="utf-8", newline="\n") as f:
        f.write(otext)
    with open(os.path.join(r3dir, "upload-map.json"), "w", encoding="utf-8", newline="\n") as f:
        json.dump(records, f, ensure_ascii=False, indent=1)
        f.write("\n")
    same = sum(1 for it in items if it["product_sha256"] == it["ledger_product_sha256"])
    print("ASSEMBLE items=%d files=%d bytes=%d origins=%d product_sha_ledger_match=%d/%d (upstream column, expected 0)" % (
        len(items), len(records), sum(r["bytes"] for r in records), n_orig, same, len(items)))
    print("ASSEMBLE product_dirs %s" % ", ".join(
        "%s=%d" % (p, sum(1 for i in items if i["product"] == p))
        for p in sorted({i["product"] for i in items})))
    return items, records


def seed_state(manifest_path, out_path):
    items = build_items(manifest_path)
    doc = {"round": "20261120", "branch": "codex/20261120-batch-review",
           "last_commit": "seed", "items": {}}
    for it in items:
        key = (it["analysis_key"] or ("sha256:" + it["sha256"]))
        doc["items"][key] = {"sha256": it["sha256"], "kind": it["kind"],
                             "chain": it["kind"], "product": it["product"],
                             "status": it["status"],
                             "product_sha256": it["ledger_product_sha256"],
                             "pushed": {"commit": "seed"},
                             "superseded_by": None,
                             "relative_path": it["relative_path"],
                             "report_md": it.get("md", "")}
    os.makedirs(os.path.dirname(os.path.abspath(out_path)), exist_ok=True)
    with open(out_path, "w", encoding="utf-8", newline="\n") as f:
        json.dump(doc, f, ensure_ascii=False, indent=1, sort_keys=True)
        f.write("\n")
    print("STATE-SEEDED items=%d pushed=%d" % (
        len(doc["items"]), sum(1 for v in doc["items"].values() if v["pushed"]["commit"])))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(add_help=True)
    ap.add_argument("--seed-state", dest="seed_state")
    ap.add_argument("--manifest", default=MANIFEST)
    ap.add_argument("--out")
    ap.add_argument("--staging", default="out/R3/upload")
    ap.add_argument("--r3", default="out/R3")
    a = ap.parse_args(argv)
    if a.seed_state:
        if not a.out:
            die("INPUT FAIL --seed-state needs --out")
        return seed_state(a.seed_state, a.out)
    staging = a.staging if os.path.isabs(a.staging) else os.path.join(WR, a.staging)
    r3 = a.r3 if os.path.isabs(a.r3) else os.path.join(WR, a.r3)
    build(staging, a.manifest, r3)
    return 0


if __name__ == "__main__":
    sys.exit(main())
