#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""check_upload.py -- R4 upload gate.

Modes:
  --build-fixtures <staging> --out <dir>     build the 13-file fixture staging tree
  --self-test --out <dir>                    8 negative cases, writes 05-upload-gate.md
  --staging S --ledger L --origins O --allowlist-out A --out D
                                             gate: fail-closed, emits allowlist on success

Hard rules (rev5 / r3-b I7): --out and --allowlist-out are ALWAYS explicit;
missing either => exit 2 (no default output directory, so T4 cannot write out/R4).
files=0 => exit 2 (no empty green).  findings>0 => exit 1, no allowlist written.
"""
from __future__ import annotations

import argparse
import csv
import gzip
import hashlib
import json
import os
import re
import shutil
import sys

_BS = chr(92)
ALLOWED_EXT = (".md", ".csv", ".py", ".json", ".java", ".tsv", ".txt", ".txt.gz")
SINGLE_MAX = 5 * 1024 * 1024
TOTAL_MAX = 64 * 1024 * 1024
META_NAMES = ("readme.md", "index.md", "index.csv", "archive-ledger.csv")
NAME_BLOCK = ("_cred.py", "gh.py", "git-auth.sh", "err.tmp", "tok.tmp",
              "repo.tar.gz", "state.json")
FIXED_SENTENCE = "\u504f\u79bb\u4ed3\u5e93 AGENTS"

# --- leak rules (built from fragments on purpose: this file is itself uploaded) ---
DRIVE_RE = re.compile(r"(?<![A-Za-z])[A-Za-z]:[\\/]")  # drive letter at token boundary; scheme URLs excluded by lookbehind
USERS_RE = re.compile("Us" + "ers" + re.escape(_BS * 2))
WORKSPACE_RE = re.compile("deep" + "seek" + "har" + "ness" + chr(32) + "work" + "space")
USER_RE = re.compile("34" + "218")
TOKEN1_RE = re.compile("gh" + "o_" + "[A-Za-z0-9]{20,}")
TOKEN2_RE = re.compile("git" + "hub_" + "pat" + "_" + "[A-Za-z0-9_]{20,}")
AUTH_RE = re.compile("Auth" + "oriz" + "ation:")
BEARER_RE = re.compile("Bea" + "rer" + chr(32) + "[^" + re.escape(_BS) + r"\s]{10,}")

LEAK_RULES = (
    ("abspath", DRIVE_RE),
    ("users_path", USERS_RE),
    ("workspace_name", WORKSPACE_RE),
    ("username", USER_RE),
    ("token_prefix_1", TOKEN1_RE),
    ("token_prefix_2", TOKEN2_RE),
    ("auth_header", AUTH_RE),
    ("bearer_token", BEARER_RE),
)

PRODUCT_DIRS = (("aspen-properties", "clr"), ("aspen-plus", "native"), ("shared", "nonpe"))


def sha256_bytes(b):
    return hashlib.sha256(b).hexdigest()


def ext_of(rel):
    low = rel.lower()
    if low.endswith(".txt.gz"):
        return ".txt.gz"
    return os.path.splitext(low)[1]


def payload_bytes(path, ext):
    if ext == ".txt.gz":
        # bounded decompression: a gz bomb must not eat memory; a >limit result is
        # already TOO_BIG so no allowlist is emitted for it.
        with gzip.open(path, "rb") as f:
            return f.read(SINGLE_MAX + 1)
    with open(path, "rb") as f:
        return f.read()


def collect_files(staging):
    out = []
    for root, _dirs, files in os.walk(staging):
        for name in files:
            p = os.path.join(root, name)
            rel = os.path.relpath(p, staging).replace(os.sep, "/")
            out.append((rel, p))
    out.sort()
    return out


def path_problem(rel):
    if not (rel.startswith("analysis/") or rel.startswith("tools/")):
        return "not-under-analysis-or-tools"
    if ":" in rel:
        return "colon"
    if ".." in rel:
        return "dotdot"
    if any(seg == "" for seg in rel.split("/")):
        return "empty-segment"
    return None


def name_blocked(rel):
    base = rel.rsplit("/", 1)[-1].lower()
    for bad in NAME_BLOCK:
        if base == bad:
            return base
    if base.endswith(".pyc"):
        return base
    return None


def scan_leaks(text):
    hits = []
    for label, rx in LEAK_RULES:
        if rx.search(text):
            hits.append(label)
    return hits


def load_origins(path):
    shas = set()
    if not path:
        return shas
    with open(path, newline="", encoding="utf-8-sig") as f:
        rd = csv.DictReader(f)
        if not rd.fieldnames:
            return shas
        key = None
        for fld in rd.fieldnames:
            if (fld or "").strip().lower() == "sha256":
                key = fld
                break
        if key is None:
            return shas
        for row in rd:
            v = (row.get(key) or "").strip().lower()
            if v:
                shas.add(v)
    return shas


def load_ledger(path):
    with open(path, newline="", encoding="utf-8-sig") as f:
        rd = csv.DictReader(f)
        fields = [(x or "").strip() for x in (rd.fieldnames or [])]
        col = None
        for fld in fields:
            if fld.lower() == "report_md":
                col = fld
                break
        if col is None:
            for fld in fields:
                if "report" in fld.lower():
                    col = fld
                    break
        rows = []
        for row in rd:
            rows.append({(k or "").strip(): (v or "").strip() for k, v in row.items()})
        return rows, col


def kind_of(rel):
    low = rel.lower()
    for seg, kind in PRODUCT_DIRS:
        if ("/" + seg + "/") in low:
            return kind
    return None


def is_meta(rel):
    base = rel.rsplit("/", 1)[-1].lower()
    return base in META_NAMES


def run_gate(staging, ledger, origins, allowlist_out, out_dir, quiet=False):
    res = {"exit": 2, "findings": [], "files": 0,
           "products": {"clr": 0, "native": 0, "nonpe": 0}, "bytes": 0}
    if not os.path.isdir(staging):
        print("INPUT FAIL staging-missing=%s" % staging)
        return res
    files = collect_files(staging)
    if not files:
        print("GATE UPLOAD_FAIL files=0 findings=0")
        return res
    if not origins or not os.path.isfile(origins):
        # fail-closed: without origins the D4 origin-hash defence would silently
        # disappear, which is exactly an empty green.
        print("INPUT FAIL missing --origins (origin-hash defence cannot be skipped)"
              if not origins else "INPUT FAIL origins-missing=%s" % origins)
        return res
    if not ledger or not os.path.isfile(ledger):
        print("INPUT FAIL ledger-missing=%s" % ledger)
        return res

    findings = []
    try:
        rows, col = load_ledger(ledger)
    except Exception as e:
        print("INPUT FAIL ledger-unreadable=%s: %s" % (ledger, str(e)[:120]))
        return res
    if col is None:
        findings.append("LEDGER_MISMATCH missing-report_md-column")
        rows = []
        ledge_md = []
    else:
        ledge_md = [r.get(col, "") for r in rows if r.get(col, "")]

    if col is not None:
        if len(set(ledge_md)) != len(rows):
            findings.append("LEDGER_MISMATCH duplicate-report_md rows=%d uniq=%d"
                            % (len(rows), len(set(ledge_md))))
        for m in ledge_md:
            if not os.path.isfile(os.path.join(staging, m.replace("/", os.sep))):
                findings.append("LEDGER_MISMATCH missing-on-disk path=%s" % m)

    listed = set(m.replace("\\", "/") for m in ledge_md)
    origins_set = load_origins(origins)

    companions = set()
    for m in listed:
        base = m.rsplit("/", 1)[-1]
        if base.lower().endswith(".md"):
            stem = base[:-3]
            parent = m.rsplit("/", 1)[0] if "/" in m else ""
            for sub in ("il", "decompiled", "disasm"):
                companions.add(parent + "/" + sub + "/" + stem + ".")

    def is_companion(rel):
        for marker in companions:
            if rel.startswith(marker):
                rest = rel[len(marker):]
                if "/" not in rest and rest:
                    return True
        return False

    total = 0
    seen_records = []
    product_reports = []
    for rel, path in files:
        ext = ext_of(rel)
        prob = path_problem(rel)
        blocked = name_blocked(rel)
        if prob:
            findings.append("FORBID path=%s reason=%s" % (rel, prob))
        if blocked:
            findings.append("FORBID name=%s path=%s" % (blocked, rel))
        if ext not in ALLOWED_EXT:
            findings.append("FORBID ext=%s path=%s" % (ext, rel))
        try:
            raw = payload_bytes(path, ext)
        except Exception as e:
            findings.append("UNREADABLE path=%s err=%s" % (rel, type(e).__name__))
            continue
        size = len(raw)
        total += size
        if size > SINGLE_MAX:
            findings.append("TOO_BIG size=%d path=%s" % (size, rel))
        digest = sha256_bytes(raw)
        seen_records.append({"path": rel, "sha256": digest, "bytes": size})
        if digest in origins_set:
            findings.append("ORIGIN_HASH match=%s path=%s" % (digest, rel))
        if not (rel in listed or is_meta(rel) or rel.startswith("tools/") or is_companion(rel)):
            findings.append("UNLISTED path=%s" % rel)
        if ext in ALLOWED_EXT:
            text = raw.decode("utf-8", "replace")
            for label in scan_leaks(text):
                findings.append("LEAK %s path=%s" % (label, rel))
            if rel.startswith("analysis/") and ext == ".md" and FIXED_SENTENCE not in text:
                findings.append("NO_DEVIATION_SENTENCE path=%s" % rel)
        if rel.startswith("analysis/") and ext == ".md" and not is_meta(rel):
            product_reports.append(rel)

    if total > TOTAL_MAX:
        findings.append("TOO_MUCH total=%d" % total)

    if col is not None and len(product_reports) != len(rows):
        findings.append("LEDGER_MISMATCH md-count=%d rows=%d"
                        % (len(product_reports), len(rows)))
    for rel in product_reports:
        if rel not in listed:
            findings.append("LEDGER_MISMATCH unlisted-report path=%s" % rel)

    products = {"clr": 0, "native": 0, "nonpe": 0}
    for rel in product_reports:
        k = kind_of(rel)
        if k in products:
            products[k] += 1

    res["findings"] = findings
    res["files"] = len(files)
    res["bytes"] = total
    res["products"] = products

    if findings:
        for line in findings:
            print(line)
        print("GATE UPLOAD_FAIL files=%d findings=%d" % (len(files), len(findings)))
        res["exit"] = 1
        return res

    if allowlist_out:
        os.makedirs(os.path.dirname(os.path.abspath(allowlist_out)), exist_ok=True)
        doc = {"count": len(seen_records),
               "files": sorted(seen_records, key=lambda r: r["path"]),
               "products": dict(products)}
        with open(allowlist_out, "w", encoding="utf-8", newline="\n") as f:
            json.dump(doc, f, ensure_ascii=False, indent=2, sort_keys=True)
            f.write("\n")
    print("GATE UPLOAD_OK files=%d findings=0 products clr=%d native=%d nonpe=%d"
          % (len(files), products["clr"], products["native"], products["nonpe"]))
    print("GATE BYTES total=%d files=%d" % (total, len(seen_records)))
    res["exit"] = 0
    return res


def _write(p, text, newline="\n"):
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w", encoding="utf-8", newline=newline) as f:
        f.write(text)


def build_fixtures(staging, out_dir):
    staging = os.path.abspath(staging)
    fixtures_dir = os.path.dirname(staging)
    os.makedirs(staging, exist_ok=True)
    base = "analysis/20261120-batch-driver"
    ap = base + "/Aspen-Properties/[Example]"
    plus = base + "/Aspen-Plus/[Example]"
    sh = base + "/shared/[Example]"
    sent = FIXED_SENTENCE + "\uff1a\u672c\u6b21\u4ea7\u7269\u4ec5\u4f9b\u5ba1\u9605\u3002\n"

    readme = "# batch-driver\n\n" + sent + "".join(
        "## section %d\n\nbody %d\n\n" % (i, i) for i in range(1, 8))
    _write(os.path.join(staging, base, "README.md"), readme)

    idx = ("# INDEX\n\n" + sent + "\n| name | kind | product |\n| --- | --- | --- |\n"
           "| clr.dll | clr | Aspen-Properties |\n"
           "| native.dll | native | Aspen-Plus |\n"
           "| obj.obj | nonPE | shared |\n")
    _write(os.path.join(staging, base, "INDEX.md"), idx)

    _write(os.path.join(staging, base, "index.csv"),
           "product,kind,name,size,sha256,status,il,decompiled,disasm\n"
           "Aspen-Properties,clr,clr.dll,1024,aaa,processed,yes,yes,no\n"
           "Aspen-Plus,native,native.dll,2048,bbb,processed,no,yes,yes\n"
           "shared,nonPE,obj.obj,512,ccc,unsupported_non_pe,no,no,no\n")

    _write(os.path.join(staging, base, "archive-ledger.csv"),
           "product,kind,status,report_md,sha256,size\n"
           "Aspen-Properties,clr,processed," + ap + "/clr.dll.md,,\n"
           "Aspen-Plus,native,processed," + plus + "/native.dll.md,,\n"
           "shared,nonPE,unsupported_non_pe," + sh + "/obj.md,,\n")

    _write(os.path.join(staging, ap, "clr.dll.md"),
           "# clr.dll\n\n" + sent + "\n## 1 summary\n## 2 hashes\n## 3 il\n## 4 decompiled\n"
           "## 5 calls\n## 6 strings\n## 7 refs\n## 8 risks\n## 9 notes\n")
    _write(os.path.join(staging, ap, "il/clr.dll.il.txt"),
           "// IL dump\nMD 06000001 1\nMD 06000002 2\n")
    _write(os.path.join(staging, ap, "decompiled/clr.dll.cs.txt"),
           "public class Example {\n    public void Run() { }\n}\n")
    _write(os.path.join(staging, plus, "native.dll.md"),
           "# native.dll\n\n" + sent + "\n## 1 summary\n## 2 hashes\n## 3 disasm\n## 4 decompiled\n"
           "## 5 calls\n## 6 strings\n## 7 refs\n## 8 risks\n## 9 notes\n")
    _write(os.path.join(staging, plus, "disasm/native.dll.asm.txt"),
           "FUNC 00401000 main\n  push ebp\nFUNC 00401100 helper\n")
    _write(os.path.join(staging, plus, "decompiled/native.dll.c.txt"),
           "// FUNC 00401000 main\nint main(void) { return 0; }\n")
    _write(os.path.join(staging, sh, "obj.md"),
           "# obj.obj\n\n" + sent + "\nstatus: unsupported_non_pe\n## 1 summary\n## 2 hashes\n")
    _write(os.path.join(staging, "tools/aspen_batch/gate_tool.py"),
           "# placeholder tool file\nprint('gate')\n")

    ctxt = os.path.join(staging, plus, "decompiled/native.dll.c.txt")
    with open(ctxt, "rb") as f:
        payload = f.read()
    gz_path = os.path.join(staging, plus, "decompiled/native.dll.c.txt.gz")
    os.makedirs(os.path.dirname(gz_path), exist_ok=True)
    fh = open(gz_path, "wb")
    with gzip.GzipFile(filename="", mode="wb", fileobj=fh, mtime=0) as gz:
        gz.write(payload)
    fh.close()

    n = len(collect_files(staging))
    os.makedirs(fixtures_dir, exist_ok=True)
    origin_payload = ("MZfabricated-origin-binary-for-gate-test" + chr(0) * 32).encode("utf-8")
    with open(os.path.join(fixtures_dir, "origin_payload.bin"), "wb") as f:
        f.write(origin_payload)
    _write(os.path.join(fixtures_dir, "origins.csv"),
           "sha256,size\n" + sha256_bytes(origin_payload) + ",%d\n" % len(origin_payload))
    print("FIXTURE files=%d" % n)
    return n


def do_selftest(out_dir):
    out_dir = os.path.abspath(out_dir)
    root = os.path.join(out_dir, "runs", "selftest")
    shutil.rmtree(root, ignore_errors=True)
    os.makedirs(root, exist_ok=True)
    base_staging = os.path.join(root, "base", "fixtures", "staging")
    build_fixtures(base_staging, root)
    base_origins = os.path.join(root, "base", "fixtures", "origins.csv")
    ledger_rel = "analysis/20261120-batch-driver/archive-ledger.csv"
    payload_src = os.path.join(root, "base", "fixtures", "origin_payload.bin")

    base = run_gate(base_staging, os.path.join(base_staging, ledger_rel), base_origins,
                    os.path.join(root, "base-allow.json"), root)
    lines = []
    lines.append("# R4 upload gate report")
    lines.append("")
    lines.append("tool: tool/check_upload.py ; paths WR-relative (WR = _work/wf-20261120-aspen-batch).")
    lines.append("judgement: fail-closed; --out and --allowlist-out are explicit args.")
    lines.append("")
    lines.append("## baseline (clean 13-file fixture)")
    lines.append("")
    lines.append("exit=%d findings=%d files=%d" % (base["exit"], len(base["findings"]), base["files"]))
    lines.append("")

    def inj_dll(st):
        _write(os.path.join(st, "tools/aspen_batch/bad.dll"), "MZfake\n")

    def inj_exe(st):
        _write(os.path.join(st, "tools/aspen_batch/bad.exe"), "MZfake\n")

    def inj_db(st):
        _write(os.path.join(st, "tools/aspen_batch/bad.db"), "sqlite\n")

    def inj_big(st):
        p = os.path.join(st, "tools/aspen_batch/big.txt")
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "wb") as f:
            f.write(b"A" * (6 * 1024 * 1024))

    def inj_cred(st):
        _write(os.path.join(st, "tools/aspen_batch/_cred.py"), "# fake\n")

    def inj_cs(st):
        _write(os.path.join(st, "tools/aspen_batch/src.cs"), "public class X { }\n")

    def inj_leak(st):
        p = os.path.join(st, "analysis/20261120-batch-driver/Aspen-Plus/[Example]/native.dll.md")
        with open(p, "a", encoding="utf-8", newline="\n") as f:
            f.write("\npath: Z:" + _BS + "example" + _BS + "fixtures" + _BS + "sample.txt\n")

    def inj_origin(st):
        with open(payload_src, "rb") as f:
            data = f.read()
        p = os.path.join(st, "tools/aspen_batch/origin_copy.txt")
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "wb") as f:
            f.write(data)

    cases = [
        (1, "extra .dll", "FORBID ext=.dll", inj_dll),
        (2, "extra .exe", "FORBID ext=.exe", inj_exe),
        (3, "extra .db", "FORBID ext=.db", inj_db),
        (4, "6MB single file (limit 5MB)", "TOO_BIG size=", inj_big),
        (5, "blocked file name", "FORBID name=", inj_cred),
        (6, "uncompressed .cs source", "FORBID ext=.cs", inj_cs),
        (7, "drive-prefix absolute path in .md", "LEAK abspath", inj_leak),
        (8, "content hash equals original binary", "ORIGIN_HASH match=", inj_origin),
    ]

    passed = 0
    for num, desc, expect, fn in cases:
        croot = os.path.join(root, "case%d" % num)
        st = os.path.join(croot, "staging")
        shutil.copytree(base_staging, st)
        shutil.copy2(base_origins, os.path.join(croot, "origins.csv"))
        fn(st)
        r = run_gate(st, os.path.join(st, ledger_rel), os.path.join(croot, "origins.csv"),
                     os.path.join(croot, "allowlist.json"), croot)
        joined = "\n".join(r["findings"])
        hit = expect in joined
        ok = (r["exit"] == 1) and hit and len(r["findings"]) == 1
        if ok:
            passed += 1
        matched = [x for x in r["findings"] if expect in x]
        lines.append("- case %d | %s | expect <" % (num, desc) + expect + "> | exit=%d findings=%d | %s | %s"
                     % (r["exit"], len(r["findings"]),
                        ("hit: " + matched[0]) if matched else "MISS",
                        "PASS" if ok else "FAIL"))
        lines.append("")
        print("CASE %d expect=%s exit=%d findings=%d %s"
              % (num, expect, r["exit"], len(r["findings"]), "PASS" if ok else "FAIL"))
        shutil.rmtree(croot, ignore_errors=True)

    verdict = "SELFTEST cases=%d passed=%d" % (len(cases), passed)
    lines.append("## summary")
    lines.append("")
    lines.append(verdict)
    lines.append("")
    report = os.path.join(out_dir, "05-upload-gate.md")
    os.makedirs(out_dir, exist_ok=True)
    with open(report, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines))
    shutil.rmtree(root, ignore_errors=True)
    print(verdict)
    return 0 if passed == len(cases) else 1


def main(argv=None):
    ap = argparse.ArgumentParser(add_help=True)
    ap.add_argument("--build-fixtures", dest="build_fixtures")
    ap.add_argument("--self-test", dest="self_test", action="store_true")
    ap.add_argument("--staging")
    ap.add_argument("--ledger")
    ap.add_argument("--origins")
    ap.add_argument("--allowlist-out", dest="allowlist_out")
    ap.add_argument("--out", dest="out")
    a = ap.parse_args(argv)

    if not a.out:
        print("INPUT FAIL missing --out (explicit output dir required)", file=sys.stderr)
        return 2

    if a.build_fixtures:
        build_fixtures(a.build_fixtures, a.out)
        return 0

    if a.self_test:
        return do_selftest(a.out)

    if not a.allowlist_out:
        print("INPUT FAIL missing --allowlist-out (explicit allowlist path required)", file=sys.stderr)
        return 2
    if not a.staging:
        print("INPUT FAIL missing --staging", file=sys.stderr)
        return 2
    if not a.ledger:
        print("INPUT FAIL missing --ledger", file=sys.stderr)
        return 2
    r = run_gate(a.staging, a.ledger, a.origins, a.allowlist_out, a.out)
    return r["exit"]


if __name__ == "__main__":
    sys.exit(main())
