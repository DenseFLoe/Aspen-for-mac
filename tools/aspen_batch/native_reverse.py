#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""T1N / R1-NATIVE chain driver.

Reads read-test-waiting.csv, routes kind=native (19 items), stages each original
PE as <safe_key>__<NAME>, runs Ghidra analyzeHeadless with tool/ghidra_scripts/ExportAll.java
(one JVM per sample so that every __raw/<safe_key>/import.log carries its own
"Headless startup complete" line), then assembles

  out/<root>/01-completed/<Product>/<DIR>/disasm/<NAME>.asm.txt
  out/<root>/01-completed/<Product>/<DIR>/decompiled/<NAME>.c.txt
  out/<root>/01-completed/<Product>/<DIR>/<NAME>.md

plus ledger-native.csv and _run.json.  Contract: 01-plan.md 3.3 / taskbook T1N 5.

No network access, no git, read-only on the original files (dl/ is never modified).
"""

import argparse
import csv
import hashlib
import json
import os
import posixpath
import re
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

WR = Path(__file__).resolve().parent.parent            # .../wf-20261120-aspen-batch
WORKSPACE = WR.parents[1]                              # .../<workspace>
DEFAULT_GHIDRA = WORKSPACE / "tools" / "ghidra" / "ghidra_12.1.4_PUBLIC"
DEFAULT_JDK = WORKSPACE / "tools" / "jdk" / "jdk-21.0.12.1+1"
SCRIPTS_REL = "tool/ghidra_scripts"
DEFAULT_PRODUCT_MAP = {"plus": "Aspen-Plus", "properties": "Aspen-Properties", "shared": "shared"}
DEV_SENTENCE = "含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条"
LONG_PATH_MARK = 250
BT = chr(96)


def bt(text):
    return BT + text + BT


# ---------------------------------------------------------------- long paths
def lp(path):
    """Windows extended-length prefix for paths >= 250 chars (C5 fallback)."""
    s = os.fspath(path)
    if os.name != "nt":
        return s
    s = os.path.abspath(s)
    if len(s) >= LONG_PATH_MARK and not s.startswith("\\\\?\\"):
        if s.startswith("\\\\"):
            return "\\\\?\\UNC\\" + s[2:]
        return "\\\\?\\" + s
    return s


def ensure_dir(path):
    os.makedirs(lp(path), exist_ok=True)


def write_text(path, text):
    ensure_dir(os.path.dirname(os.fspath(path)))
    with open(lp(path), "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)


def read_text(path):
    with open(lp(path), "r", encoding="utf-8", errors="replace") as fh:
        return fh.read()


def sha256_file(path):
    h = hashlib.sha256()
    with open(lp(path), "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


# ---------------------------------------------------------------- redaction
def make_redactor(extra_roots):
    roots = []
    named = [(WR, "<WR>"), (DEFAULT_GHIDRA, "<GHIDRA>"), (DEFAULT_JDK, "<JDK>"),
             (WORKSPACE, "<WS>")] + [(r, "<WR>") for r in extra_roots]
    for root, token in named:
        s = os.path.abspath(os.fspath(root))
        for form in (s, s.replace("\\", "/"), s.replace("/", "\\")):
            if form:
                roots.append((form, token))
    roots.sort(key=lambda pair: len(pair[0]), reverse=True)

    def redact(text, generic_paths=False):
        for form, token in roots:
            text = text.replace(form, token)
        if generic_paths:
            text = re.sub(r"[A-Za-z]:[\\/][^\s\"'<>|;,)]*", "<abs-path>", text)
            text = re.sub(r"\b<user>\b", "<uid>", text)
            text = re.sub(r"/[cC]/<users>/[^\s\"'<>|;,)]*", "<user-path>", text)
        text = re.sub(r"C:[\\/]Users[\\/][^\s\"'<>|;,)]*", "<user-path>", text, flags=re.I)
        return text

    return redact


# ---------------------------------------------------------------- manifest
def load_manifest(path):
    with open(path, "r", encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh))


def split_path(row):
    """waiting-cat/<Product_raw>/<DIR...>/<NAME> -> (product_raw, relative_path)."""
    parts = [p for p in row["path"].split("/") if p != ""]
    if parts and parts[0] == "等待铁头猫":
        parts = parts[1:]
    if len(parts) < 2:
        raise ValueError("unexpected manifest path: " + row["path"])
    return parts[0], "/".join(parts[1:])


def analysis_key(sha):
    return "sha256_" + sha


def discover_bash(explicit=None):
    """Find an MSYS/Git bash; System32\bash.exe is WSL and cannot run analyzeHeadless."""
    if explicit:
        return explicit
    bad = ("system32", "windowsapps")
    seen = []
    for d in os.environ.get("PATH", "").split(os.pathsep):
        if not d:
            continue
        cand = Path(d) / "bash.exe"
        if cand.exists():
            seen.append(str(cand))
    seen.append("bash")
    for cand in seen:
        low = cand.lower()
        if any(b in low for b in bad):
            continue
        try:
            probe = subprocess.run([cand, "-c", "echo BASH-OK"], capture_output=True, timeout=60)
        except (OSError, subprocess.SubprocessError):
            continue
        if probe.returncode == 0 and b"BASH-OK" in probe.stdout:
            return cand
    return "bash"


def resolve_local(source_root, local):
    """The manifest 'local' column already carries its own dl/ prefix; accept both shapes."""
    for cand in (Path(source_root) / local, Path(local), WR / local):
        if cand.exists():
            return cand
    return Path(source_root) / local


def build_items(rows, args, product_map):
    items = []
    for row in rows:
        if row.get("kind") != "native":
            continue
        sha = (row.get("sha256") or "").strip().lower()
        product_raw, rel = split_path(row)
        product = product_map.get(product_raw.lower(), product_raw)
        item = {
            "sha256": sha,
            "size": int(row["size"]),
            "kind": row["kind"],
            "machine": row.get("machine", ""),
            "sections": row.get("sections", ""),
            "entry": row.get("entry", ""),
            "product_raw": product_raw,
            "product": product,
            "relative_path": rel,
            "name": posixpath.basename(rel),
            "dir": posixpath.dirname(rel),
            "analysis_key": analysis_key(sha),
            "local": row.get("local", ""),
            "status": "pending",
            "funcs": 0, "decomp_ok": 0, "decomp_fail": 0,
            "asm_lines": 0, "c_lines": 0, "elapsed_s": 0.0,
            "reason": "", "product_sha256": "", "paths": {},
        }
        items.append(item)
    return items


# ---------------------------------------------------------------- ghidra run
def run_ghidra(item, args, redact):
    safe = item["analysis_key"]
    out_root = Path(args.out)
    stage_dir = out_root / "stage"
    stage_name = safe + "__" + item["name"]
    stage_path = stage_dir / stage_name
    exp_dir = stage_dir / "exp" / safe
    raw_dir = out_root / "__raw" / safe
    log_path = raw_dir / "import.log"
    proj_dir = out_root / "ghidra-proj" / safe
    src = resolve_local(args.source_root, item["local"])

    ensure_dir(stage_dir)
    ensure_dir(raw_dir)
    ensure_dir(proj_dir)
    if exp_dir.exists():
        shutil.rmtree(lp(exp_dir), ignore_errors=True)
    ensure_dir(exp_dir)

    with open(lp(stage_path), "wb") as dst, open(lp(src), "rb") as s:
        shutil.copyfileobj(s, dst)
    item["staged"] = stage_path.relative_to(WR).as_posix()

    env = dict(os.environ)
    env["JAVA_HOME"] = str(args.jdk)
    env["APPDATA"] = str(WR / "home" / "AppData" / "Roaming")
    env["LOCALAPPDATA"] = str(WR / "home" / "AppData" / "Local")
    env["PATH"] = str(Path(args.jdk) / "bin") + os.pathsep + env.get("PATH", "")
    tmp_dir = WR / "home" / "AppData" / "Local" / "tmp"
    env["TMP"] = env["TEMP"] = env["TMPDIR"] = str(tmp_dir)
    for key in ("APPDATA", "LOCALAPPDATA", "JAVA_HOME"):
        ensure_dir(env[key])
    ensure_dir(tmp_dir)

    cmd = [
        args.bash, str(Path(args.ghidra) / "support" / "analyzeHeadless"),
        proj_dir.relative_to(WR).as_posix(), "aspen_native",
        "-deleteProject",
        "-import", stage_path.relative_to(WR).as_posix(),
        "-scriptPath", SCRIPTS_REL,
        "-postScript", "ExportAll.java", os.path.abspath(exp_dir),
        "-analysisTimeoutPerFile", "600",
    ]
    started = time.time()
    timed_out = False
    stdout, stderr, rc = "", "", None
    # The Ghidra -analysisTimeoutPerFile flag only bounds auto-analysis; JVM start-up,
    # import and the postScript also count against the 600 s per-item budget, so the
    # outer wall clock is enforced here and the whole process tree is killed on expiry.
    proc = subprocess.Popen(cmd, cwd=str(WR), env=env, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, text=True, encoding="utf-8", errors="replace")
    try:
        stdout, stderr = proc.communicate(timeout=args.timeout)
        rc = proc.returncode
    except subprocess.TimeoutExpired:
        timed_out = True
        if os.name == "nt":
            subprocess.run(["taskkill", "/PID", str(proc.pid), "/T", "/F"],
                           capture_output=True, timeout=120)
        else:
            proc.kill()
        try:
            stdout, stderr = proc.communicate(timeout=120)
        except subprocess.TimeoutExpired:
            stdout, stderr = "", ""
        rc = None
    item["elapsed_s"] = round(time.time() - started, 1)

    log = redact("$ " + " ".join(cmd) + "\n" + stdout + stderr, generic_paths=True)
    write_text(log_path, log)
    item["import_log"] = log_path.relative_to(WR).as_posix()

    if timed_out:
        item["status"] = "failed_analyze"
        item["reason"] = "Timeout: analyzeHeadless exceeded %ss (analysisTimeoutPerFile=600)" % args.timeout
        return item

    if (exp_dir / (stage_name + ".timeout")).exists():
        item["status"] = "failed_analyze"
        item["reason"] = "Ghidra analysisTimeoutOccurred (analysisTimeoutPerFile=600)"
        return item

    asm_src = exp_dir / (stage_name + ".asm.txt")
    c_src = exp_dir / (stage_name + ".c.txt")
    if not asm_src.exists() or not c_src.exists():
        item["status"] = "failed_analyze"
        tail = [ln for ln in log.splitlines() if ln.strip()][-6:]
        item["reason"] = ((("ExitCode%d: " % rc) if rc is not None else "") +
                          "ExportAll produced no output; log tail: " + " | ".join(tail))[:400]
        return item

    asm_text = redact(read_text(asm_src))
    c_text = redact(read_text(c_src))
    item["asm_text"] = asm_text
    item["c_text"] = c_text
    item["asm_src"] = asm_src
    item["c_src"] = c_src
    item["funcs"] = sum(1 for ln in asm_text.splitlines() if ln.startswith("FUNC "))
    entries = sum(1 for ln in c_text.splitlines()
                  if ln.startswith("// FUNC ") or ln.startswith("// DECOMP-FAIL "))
    item["decomp_fail"] = sum(1 for ln in c_text.splitlines() if ln.startswith("// DECOMP-FAIL "))
    item["decomp_ok"] = sum(1 for ln in c_text.splitlines() if ln.startswith("// FUNC "))
    item["asm_lines"] = len(asm_text.splitlines())
    item["c_lines"] = len(c_text.splitlines())
    item["identity_ok"] = (item["funcs"] == entries)
    for ln in asm_text.splitlines()[:3]:
        if ln.startswith("# LANG "):
            item["lang"] = ln[7:].strip()
        elif ln.startswith("# BASE "):
            item["base"] = ln[7:].strip()
        elif ln.startswith("# BLOCKS "):
            item["blocks"] = ln[9:].strip()
    if item["funcs"] == 0:
        item["status"] = "failed_analyze"
        item["reason"] = "ExportAll wrote no FUNC blocks"
        return item
    item["status"] = "analyzed"
    return item


# ---------------------------------------------------------------- assembly
def render_md(item, redact):
    lines = []
    a = lines.append
    name = item["name"]
    a("# " + name + " 静态复核报告（native / T1N）")
    a("")
    a("## 0. 摘要")
    a("")
    a("| 项目 | 结果 |")
    a("| --- | --- |")
    a("| 样本 | " + bt(name) + "，" + str(item["size"]) + " 字节，SHA-256 " + bt(item["sha256"]) + " |")
    a("| 链 | T1N（native，Ghidra 全函数反汇编 + 全函数伪 C） |")
    a("| 函数 | FUNC " + str(item["funcs"]) + " = //FUNC " + str(item.get("decomp_ok", 0))
      + " + //DECOMP-FAIL " + str(item["decomp_fail"]) + " |")
    a("| 证据等级 | 〔实测〕analyzeHeadless 单件跑通，正文见同目录 disasm/ 与 decompiled/ |")
    a("")
    a(DEV_SENTENCE)
    a("")
    a("## 1. 样本与哈希")
    a("")
    a("| 项 | 值 |")
    a("| --- | --- |")
    a("| 名称 | " + bt(name) + " |")
    a("| 字节数 | " + str(item["size"]) + " |")
    a("| SHA-256 | " + bt(item["sha256"]) + " |")
    a("| 清单 | read-test-waiting.csv（kind=native） |")
    a("| 原始相对路径（清单 path，去掉产品段） | " + bt(item["relative_path"]) + " |")
    a("| product_raw | " + bt(item["product_raw"]) + " |")
    a("| 产品目录 | " + bt(item["product"]) + " |")
    a("| machine / sections / entry | " + str(item["machine"]) + " / " + str(item["sections"])
      + " / " + str(item["entry"]) + " |")
    a("| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |")
    a("")
    a("## 2. PE 导入摘要（语言/基址/块）")
    a("")
    a("| 项 | 值 |")
    a("| --- | --- |")
    a("| Ghidra 语言 id | " + bt(str(item.get("lang", "?"))) + " |")
    a("| 镜像基址 | " + bt(str(item.get("base", "?"))) + " |")
    a("| 函数块数（# BLOCKS） | " + str(item.get("blocks", "?")) + " |")
    a("| 指令行数 | " + str(item["asm_lines"]) + " |")
    a("")
    a("## 3. 反汇编清单（全量）")
    a("")
    a("全文：disasm/" + name + ".asm.txt（逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，无抽样）。")
    a("")
    a("## 4. 反编译伪 C（Ghidra）")
    a("")
    a("全文：decompiled/" + name + ".c.txt（逐函数 // FUNC <addr> <name> + C 正文 + // ENDFUNC；"
      "反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。")
    a("")
    a("## 5. 函数统计（FUNC 数 = //FUNC 数 + //DECOMP-FAIL 数）")
    a("")
    a("- FUNC（asm） = " + str(item["funcs"]))
    a("- // FUNC（伪 C） = " + str(item.get("decomp_ok", 0)))
    a("- // DECOMP-FAIL = " + str(item["decomp_fail"]))
    a("- 恒等式：" + ("成立〔实测〕" if item.get("identity_ok") else "**不成立**〔如实上报〕"))
    a("")
    a("## 6. 工具与环境")
    a("")
    a("- Ghidra 12.1.4 PUBLIC headless（support/analyzeHeadless，bash 调），JDK 21，-analysisTimeoutPerFile 600")
    a("- 脚本：tool/ghidra_scripts/ExportAll.java（本仓从零写）")
    a("- 单件耗时（含 JVM 启动）：%.1f s" % item["elapsed_s"])
    a("- 日志：__raw/" + item["analysis_key"] + "/import.log")
    a("")
    a("## 7. 缺口与待验证")
    a("")
    a("- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕")
    a("- 反编译失败函数 " + str(item["decomp_fail"]) + " 个（// DECOMP-FAIL 行可逐一核对）。")
    a("")
    a("## 8. 结论")
    a("")
    a("- " + bt(name) + " 全函数反汇编与全函数伪 C 已落盘，FUNC == //FUNC + //DECOMP-FAIL "
      + ("成立" if item.get("identity_ok") else "不成立") + "。")
    a("")
    return redact("\n".join(lines))


def product_sha256(paths):
    """<basename>=<sha256>; sorted ascending, joined, then sha256."""
    parts = sorted("%s=%s;" % (p.name, sha256_file(p)) for p in paths)
    return hashlib.sha256("".join(parts).encode("utf-8")).hexdigest()


def assemble(item, args, redact):
    out_root = Path(args.out)
    base = out_root / "01-completed" / item["product"] / item["dir"]
    asm_dst = base / "disasm" / (item["name"] + ".asm.txt")
    c_dst = base / "decompiled" / (item["name"] + ".c.txt")
    md_dst = base / (item["name"] + ".md")

    write_text(asm_dst, item["asm_text"])
    write_text(c_dst, item["c_text"])
    write_text(md_dst, render_md(item, redact))

    item["paths"] = {
        "disasm": asm_dst.relative_to(WR).as_posix(),
        "decompiled": c_dst.relative_to(WR).as_posix(),
        "report_md": md_dst.relative_to(WR).as_posix(),
    }
    item["product_sha256"] = product_sha256([asm_dst, c_dst, md_dst])
    for p in (item.get("asm_src"), item.get("c_src")):
        if p is not None and p.exists():
            os.remove(lp(p))
    exp_parent = out_root / "stage" / "exp" / item["analysis_key"]
    if exp_parent.exists():
        shutil.rmtree(lp(exp_parent), ignore_errors=True)
    return item


LEDGER_FIELDS = [
    "analysis_key", "chain", "name", "product", "product_raw", "relative_path",
    "sha256", "size", "kind", "machine", "sections", "entry", "status",
    "funcs", "decomp_ok", "decomp_fail", "asm_lines", "c_lines",
    "disasm_path", "decompiled_path", "report_md", "product_sha256",
    "import_log", "elapsed_s",
]


def write_ledger(items, out_root):
    path = out_root / "ledger-native.csv"
    ensure_dir(out_root)
    with open(lp(path), "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=LEDGER_FIELDS, extrasaction="ignore", lineterminator="\n")
        w.writeheader()
        for it in items:
            w.writerow({
                "analysis_key": it["analysis_key"], "chain": "T1N", "name": it["name"],
                "product": it["product"], "product_raw": it["product_raw"],
                "relative_path": it["relative_path"], "sha256": it["sha256"],
                "size": it["size"], "kind": it["kind"], "machine": it.get("machine", ""),
                "sections": it.get("sections", ""), "entry": it.get("entry", ""),
                "status": it["status"], "funcs": it["funcs"],
                "decomp_ok": it.get("decomp_ok", 0), "decomp_fail": it["decomp_fail"],
                "asm_lines": it["asm_lines"], "c_lines": it["c_lines"],
                "disasm_path": it["paths"].get("disasm", ""),
                "decompiled_path": it["paths"].get("decompiled", ""),
                "report_md": it["paths"].get("report_md", ""),
                "product_sha256": it["product_sha256"],
                "import_log": it.get("import_log", ""), "elapsed_s": it["elapsed_s"],
            })
    return path


def main(argv=None):
    ap = argparse.ArgumentParser(description="T1N native chain (Ghidra all-function disasm + decompiled C)")
    ap.add_argument("--manifest", action="append", required=True)
    ap.add_argument("--source-root", default="dl")
    ap.add_argument("--out", required=True)
    ap.add_argument("--only", action="append", default=[])
    ap.add_argument("--product", default=None)
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--timeout", type=int, default=600)
    ap.add_argument("--ghidra", default=str(DEFAULT_GHIDRA))
    ap.add_argument("--jdk", default=str(DEFAULT_JDK))
    ap.add_argument("--bash", default=None)
    args = ap.parse_args(argv)
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
        sys.stderr.reconfigure(encoding="utf-8", errors="replace")
    args.bash = discover_bash(args.bash)
    print("BASH " + args.bash)

    if not Path(args.ghidra, "support", "analyzeHeadless").exists():
        print("ERROR ghidra analyzeHeadless not found", file=sys.stderr)
        return 2
    if not Path(args.jdk).exists():
        print("ERROR JDK not found", file=sys.stderr)
        return 2

    rows = []
    for m in args.manifest:
        rows.extend(load_manifest(m))
    if not rows:
        print("ERROR empty manifest", file=sys.stderr)
        return 2

    product_map = dict(DEFAULT_PRODUCT_MAP)
    if args.product:
        product_map.update({k.lower(): v for k, v
                            in json.loads(Path(args.product).read_text(encoding="utf-8")).items()})

    items = build_items(rows, args, product_map)
    native_total = len(items)
    filtered = len(rows) - native_total

    only = set(args.only)
    if only:
        items = [it for it in items if it["sha256"] in only or it["analysis_key"] in only]
        if not items:
            print("ERROR --only matched no native row: " + ",".join(sorted(only)), file=sys.stderr)
            return 2

    args.out = str(Path(args.out).resolve())
    args.source_root = str(Path(args.source_root).resolve())
    out_root = Path(args.out)
    ensure_dir(out_root)
    redact = make_redactor([out_root])

    ready = []
    for it in items:
        src = resolve_local(args.source_root, it["local"])
        if not src.exists():
            it["status"] = "missing"
            it["reason"] = "source file not found"
            continue
        size = src.stat().st_size
        sha = sha256_file(src)
        if size != it["size"] or sha.lower() != it["sha256"]:
            it["status"] = "hash_mismatch"
            it["reason"] = "size=%d sha256=%s" % (size, sha)
            continue
        ready.append(it)

    jobs = max(1, min(args.jobs, len(ready) or 1))
    with ThreadPoolExecutor(max_workers=jobs) as ex:
        list(ex.map(lambda it: run_ghidra(it, args, redact), ready))

    for it in ready:
        if it["status"] == "analyzed":
            assemble(it, args, redact)

    write_ledger(items, out_root)
    run_json = {
        "chain": "T1N",
        "manifest": args.manifest,
        "source_root": os.path.relpath(args.source_root, WR),
        "out": out_root.as_posix().split("/")[-1],
        "rows": len(items),
        "native_total": native_total,
        "filtered": filtered,
        "processed": sum(1 for it in items if it["status"] == "analyzed"),
        "failed_analyze": sum(1 for it in items if it["status"] == "failed_analyze"),
        "missing": sum(1 for it in items if it["status"] == "missing"),
        "hash_mismatch": sum(1 for it in items if it["status"] == "hash_mismatch"),
        "funcs_total": sum(it["funcs"] for it in items),
        "decomp_fail_total": sum(it["decomp_fail"] for it in items),
        "asm_lines_total": sum(it["asm_lines"] for it in items),
        "invocation": "per-sample analyzeHeadless (same fixed command string, one -import per run) so each __raw/<analysis_key>/import.log has its own 'Headless startup complete'",
        "product_sha256_rule": "<basename>=<sha256>; for the 3 artifacts, sorted ascending, then sha256 of the joined string",
        "items": [
            {"analysis_key": it["analysis_key"], "name": it["name"], "product": it["product"],
             "relative_path": it["relative_path"], "status": it["status"],
             "funcs": it["funcs"], "decomp_fail": it["decomp_fail"],
             "elapsed_s": it["elapsed_s"], "reason": it["reason"],
             "product_sha256": it["product_sha256"]}
            for it in items
        ],
    }
    write_text(out_root / "_run.json", json.dumps(run_json, ensure_ascii=False, indent=2) + "\n")

    funcs = sum(it["funcs"] for it in items)
    decomp_fail = sum(it["decomp_fail"] for it in items)
    asm_lines = sum(it["asm_lines"] for it in items)
    print("NATIVE files=%d funcs=%d decomp_fail=%d asm_lines=%d" % (len(items), funcs, decomp_fail, asm_lines))
    print("LEDGER rows=%d processed=%d failed_analyze=%d filtered=%d"
          % (len(items), run_json["processed"], run_json["failed_analyze"], filtered))
    ok = sum(1 for it in items if it.get("identity_ok"))
    analyzed = sum(1 for it in items if it["status"] == "analyzed")
    print("FUNC-MATCH files=%d ok=%d fails=%d" % (analyzed, ok, analyzed - ok))
    for it in items:
        if it["status"] != "analyzed":
            print("ITEM %s status=%s reason=%s" % (it["name"], it["status"], it["reason"][:200]))
    return 0 if all(it["status"] == "analyzed" for it in items) else 1


if __name__ == "__main__":
    sys.exit(main())
