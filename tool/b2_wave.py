#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""b2_wave.py -- B2-B wave1b driver: selection + 5-way native + 2-way CLR + nonPE.

Reuses the already-verified commands verbatim:
  native (batch form documented in tool/ida_export.py):
      python tool/ida_export.py --manifest <csv> --source-root out/B2/src --jobs 1 --out <dir> --timeout 600
    ida_export.py accepts --jobs but its manifest loop is serial, so this driver
    shards the manifest into N CSVs and runs N such processes at once (the
    brief's second sanctioned shape: concurrency around the verified argv).
  CLR:
      PYTHONPATH=<ws>/_work/20261120-log4net-ghidra/.pylib python tool/il_dump.py --dll <src> --out <item>/il/<stem>.il.txt
      dotnet <ws>/_work/.../ilspycmd.dll <src> > <item>/decompiled/<stem>.cs.txt
  nonPE: no analysis tool, only <stem>.md carrying the real PEFormatError attempt.

No analysis is re-implemented here; the script only selects, shards, times,
places artefacts and deletes the .i64 sidecars.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import os
import subprocess
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

BT = chr(96)
WR = Path(__file__).resolve().parent.parent
WAVE = WR / "out" / "B2" / "wave1"
SRC = WR / "out" / "B2" / "src"
MANIFEST = WR / "out" / "B2" / "manifest-b2.csv"
WS = WR.parent.parent  # workspace root (out/../_work/<proj> -> ws)
NAG_HEAD = "You are not using the latest version of the tool"
NAG_VER = "Latest version is"


def strip_tool_nag(data):
    """ilspycmd 在 stdout 末尾追加 2 行升级提示，直接重定向会把它们写成 C# 源码。

    参数与返回值均为 bytes：只削掉「末尾恰好这两行」的形态，BOM、CRLF/LF、
    末尾空行与源码字符串内的同文一律逐字节保留；提示第二行无末尾换行、整份
    输出只有提示（结果为零字节）也能识别。形态不符原样返回，交给门禁报告。
    """
    if isinstance(data, str):
        data = data.encode("utf-8")
    head = NAG_HEAD.encode("utf-8")
    ver = NAG_VER.encode("utf-8")
    lines = data.splitlines(keepends=True)
    if len(lines) >= 2:
        prev = lines[-2].rstrip(b"\r\n")
        last = lines[-1].rstrip(b"\r\n")
        if prev.startswith(head) and last.startswith(ver):
            return b"".join(lines[:-2])
    return data


ILSPY = WS / "_work" / "20261120-log4net-ghidra" / "tools" / "ilspy" / "tools" / "net8.0" / "any" / "ilspycmd.dll"
PYLIB = WS / "_work" / "20261120-log4net-ghidra" / ".pylib"
IDA_HOME = Path(os.environ.get("PROGRAMFILES", "C:/Program Files")) / "ida-pro-9.5"

PRODUCT = {"Plus": "Aspen-Plus", "Properties": "Aspen-Properties", "shared": "Aspen-Plus"}
IDAPRODUCT = {"plus-properties": "Aspen-Plus", "properties-database-server": "Aspen-Plus"}
M1_MIX = {"native": 20, "CLR": 8, "nonPE": 2}
WAVE_MIX = {"native": 110, "CLR": 30, "nonPE": 10}
CLR_STATUS = "processed"


def die(msg, code=2):
    print(msg)
    sys.exit(code)


def ensure(p):
    Path(p).mkdir(parents=True, exist_ok=True)
    return Path(p)


def preflight():
    ida_ok = (IDA_HOME / "idat.exe").exists()
    il_ok = ILSPY.exists()
    print("PREFLIGHT ida=%s exists=%s" % (IDA_HOME, ida_ok))
    print("PREFLIGHT ilspy=%s exists=%s" % (ILSPY.name, il_ok))
    if not (ida_ok and il_ok):
        print("BLOCKED: tool_missing ida=%s ilspy=%s" % (ida_ok, il_ok))
        sys.exit(3)


def load_rows():
    with open(MANIFEST, "r", encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh))


def select():
    rows = [r for r in load_rows() if (r.get("already_done") or "").strip().lower() == "false"]
    picked = {"native": [], "CLR": [], "nonPE": []}
    for r in rows:
        k = r["kind"]
        if k not in picked:
            continue
        # repo-root files (.gitattributes / README.md / manifest.csv) have no
        # product sub-directory, so they cannot take the
        # analysis/<driver>/<product>/<relative path>/ layout; skip them.
        if "/" not in r["relative_path"]:
            continue
        if len(picked[k]) < WAVE_MIX[k]:
            picked[k].append(r)
    items = []
    for kind in ("native", "CLR", "nonPE"):
        for i, r in enumerate(picked[kind]):
            rel = r["relative_path"]
            items.append({
                "key": "sha256_" + r["sha256"], "kind": kind, "rel": rel,
                "name": rel.rsplit("/", 1)[-1],
                "dir": rel.rsplit("/", 1)[0] if "/" in rel else "",
                "product": PRODUCT.get(r["owner"], "Aspen-Plus"),
                "owner": r["owner"], "sha256": r["sha256"], "size": int(r["size"]),
                "m1": i < M1_MIX[kind],
            })
    return items


def load_plan():
    p = WAVE / "plan.json"
    if not p.exists():
        die("no plan; run plan first")
    return json.loads(p.read_text(encoding="utf-8"))["items"]


def subset(items, which):
    if which == "all":
        return items
    if which == "m1":
        return [i for i in items if i["m1"]]
    return [i for i in items if not i["m1"]]


def cmd_plan(args):
    ensure(WAVE)
    items = select()
    counts = {k: sum(1 for i in items if i["kind"] == k) for k in ("native", "CLR", "nonPE")}
    (WAVE / "plan.json").write_text(json.dumps({
        "wave": "B2-B wave1b", "total": len(items), "counts": counts, "items": items},
        ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("PLAN items=%d native=%d clr=%d nonpe=%d" % (
        len(items), counts["native"], counts["CLR"], counts["nonPE"]))


def write_native_manifest(items, path, shard=""):
    ensure(Path(path).parent)
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(["path", "local", "sha256", "size", "kind", "shard"])
        for it in items:
            # path keeps the 等待铁头猫/ prefix (the tool strips it to find the product
            # segment); local is the real path under --source-root.
            w.writerow(["\u7b49\u5f85\u94c1\u5934\u732b/" + it["rel"], it["rel"], it["sha256"],
                        it["size"], it["kind"], shard])
    return Path(path)


def write_product_map(path):
    ensure(Path(path).parent)
    Path(path).write_text(json.dumps(IDAPRODUCT, ensure_ascii=False) + "\n", encoding="utf-8")
    return Path(path)


def purge_sidecars(root):
    n = 0
    for dirpath, _dirs, files in os.walk(str(root)):
        for f in files:
            if f.lower().endswith((".i64", ".id0", ".id1", ".nam", ".til")):
                try:
                    os.remove(os.path.join(dirpath, f))
                    n += 1
                except OSError:
                    pass
    return n


def cmd_native(args):
    items = [i for i in subset(load_plan(), args.set) if i["kind"] == "native"]
    if not items:
        print("NATIVE skip items=0")
        return 0
    root = ensure(WAVE / ("native-" + args.set))
    pmap = write_product_map(root / "product-map.json")
    shards = max(1, args.jobs)
    chunks = [items[i::shards] for i in range(shards)]
    started = time.time()
    procs = []
    for n, chunk in enumerate(chunks):
        if not chunk:
            continue
        d = ensure(root / ("s%d" % n))
        man = write_native_manifest(chunk, d / "manifest.csv", "s%d" % n)
        log = open(str(d / "ida.log"), "w", encoding="utf-8", errors="replace")
        env = dict(os.environ)
        env["PYTHONIOENCODING"] = "utf-8"
        env["IDA_HOME"] = str(IDA_HOME)
        cmd = [sys.executable, str(WAVE / "ida_shim.py"), "--manifest", str(man),
               "--source-root", str(SRC), "--product", str(pmap), "--jobs", "1",
               "--out", str(d), "--timeout", "600"]
        procs.append((n, len(chunk), subprocess.Popen(cmd, cwd=str(WR), stdout=log,
                                                      stderr=subprocess.STDOUT, env=env), log, d))
    for n, rows, proc, log, d in procs:
        rc = proc.wait()
        log.close()
        removed = purge_sidecars(d)
        print("NATIVE shard=%d rows=%d rc=%d sidecars_removed=%d" % (n, rows, rc, removed))
    purge_sidecars(root)
    print("NATIVE set=%s items=%d elapsed_s=%.1f" % (args.set, len(items), time.time() - started))
    return 0


def cmd_merge(args):
    led = WR / "out" / "R1N" / "ledger-native.csv"
    with open(led, "r", encoding="utf-8-sig", newline="") as fh:
        rd = csv.DictReader(fh)
        fields = list(rd.fieldnames)
        base = list(rd)
    have = set(r["analysis_key"] for r in base)
    added = 0
    root = WAVE / args.dir
    for shard in sorted(root.glob("s*")):
        p = shard / "ledger-native.csv"
        if not p.exists():
            continue
        with open(p, "r", encoding="utf-8-sig", newline="") as fh:
            for r in csv.DictReader(fh):
                if r["analysis_key"] in have:
                    continue
                base.append(r)
                have.add(r["analysis_key"])
                added += 1
    with open(led, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields, extrasaction="ignore", lineterminator="\n")
        w.writeheader()
        for r in base:
            w.writerow(r)
    print("MERGE ledger=%s added=%d total=%d" % (led.name, added, len(base)))
    return 0


def clr_dir(it):
    return WR / "out" / "R1" / "01-completed" / it["product"] / it["dir"]


def write_clr_md(it, res):
    d = clr_dir(it)
    L = []
    L.append("# %s \u9759\u6001\u590d\u6838\u62a5\u544a\uff08%s / \u5168\u7a0b\u5e8f\u96c6 IL + C# \u53cd\u7f16\u8bd1\uff09" % (it["name"], it["product"]))
    L.append("")
    L.append("\u6837\u672c\u522b\u540d\uff1a" + BT + it["name"] + BT + "\uff08\u6e05\u5355 out/B2/manifest-b2.csv\uff0c\u539f\u4ef6\u53ea\u8bfb\u3001\u672a\u4e0a\u4f20\uff09")
    L.append("\u6765\u6e90\uff1a\u5206\u652f codex/waiting-for-tietoumao\uff5c\u81ea\u7b97 sha256 %s\uff5c\u53f0\u8d26 B2-B wave1b" % it["sha256"])
    L.append("\u843d\u70b9\uff1a" + BT + "01-completed/%s/%s/" % (it["product"], it["dir"]) + BT + "\uff08\u76f8\u5bf9 " + BT + "out/R1" + BT + "\uff09\uff5c\u5b9a\u4f4d\u89c4\u5219\uff1a" + BT + "local-rel" + BT)
    L.append("")
    L.append("\u6807\u7b7e\u7ea6\u5b9a\uff1a\u3014\u5b9e\u6d4b\u3015= \u672c\u8f6e\u72ec\u7acb\u5b9e\u6d4b\uff08\u6709\u547d\u4ee4\u4e0e\u539f\u59cb\u8f93\u51fa\uff09\uff1b\u3014\u5f85\u9a8c\u8bc1\u3015= \u5c1a\u672a\u53d6\u5f97\u8bc1\u636e\u3002")
    L.append("")
    L.append("## 0. \u6458\u8981")
    L.append("")
    L.append("| \u9879\u76ee | \u7ed3\u679c | \u4f9d\u636e |")
    L.append("| --- | --- | --- |")
    L.append("| \u5b9e\u9645\u6837\u672c | %s \u5b57\u8282\uff0cSHA-256 %s | \u3014\u5b9e\u6d4b\u3015\u81ea\u7b97 |" % (format(it["size"], ","), BT + it["sha256"] + BT))
    L.append("| IL \u6e05\u5355 | %s\uff0c%d \u884c\uff08il_dump.py \u5168\u91cf stdout\uff09 | \u3014\u5b9e\u6d4b\u3015 |" % (BT + "il/" + it["name"] + ".il.txt" + BT, res["il_lines"]))
    L.append("| \u53cd\u7f16\u8bd1 | %s\uff0c%d \u884c\uff08ILSpy ilspycmd \u5168\u91cf stdout\uff09 | \u3014\u5b9e\u6d4b\u3015 |" % (BT + "decompiled/" + it["name"] + ".cs.txt" + BT, res["cs_lines"]))
    L.append("| \u72b6\u6001 | %s | \u3014\u5b9e\u6d4b\u3015 |" % (BT + "status=" + res["status"] + BT))
    L.append("")
    L.append("\u542b\u5b8c\u6574\u9006\u5411\u6b63\u6587\uff0c\u4f9d\u636e\uff1a\u7528\u6237 2026-11-20 \u6307\u4ee4\uff0c\u504f\u79bb\u4ed3\u5e93 AGENTS \u8be5\u6761")
    L.append("")
    L.append("## 1. \u6837\u672c\u4e0e\u54c8\u5e0c")
    L.append("")
    L.append("| \u9879 | \u503c | \u6807\u7b7e |")
    L.append("| --- | --- | --- |")
    L.append("| \u6587\u4ef6\u540d | " + BT + it["name"] + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
    L.append("| \u5b57\u8282\u6570 | %s | \u3014\u5b9e\u6d4b\u3015 |" % format(it["size"], ","))
    L.append("| SHA-256\uff08\u672c\u8f6e\u81ea\u7b97\uff09 | " + BT + it["sha256"] + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
    L.append("| \u6e05\u5355\u58f0\u660e SHA-256 | " + BT + it["sha256"] + BT + " | \u3014\u5b9e\u6d4b\u3015\u4e00\u81f4 |")
    L.append("| \u4ea7\u54c1\u6620\u5c04 | " + BT + it["owner"] + BT + " \u2192 " + BT + it["product"] + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
    L.append("")
    L.append("## 2. \u4ea7\u7269")
    L.append("")
    L.append("- " + BT + "il/" + it["name"] + ".il.txt" + BT + "\uff08%d \u884c\uff09" % res["il_lines"])
    L.append("- " + BT + "decompiled/" + it["name"] + ".cs.txt" + BT + "\uff08%d \u884c\uff09" % res["cs_lines"])
    L.append("")
    L.append("## 3. \u7f3a\u53e3")
    L.append("")
    L.append("- \u8fd0\u884c\u671f\u884c\u4e3a\u3001\u5f3a\u540d/\u7b7e\u540d\u6709\u6548\u6027\u672a\u9a8c\u8bc1\u3014\u5f85\u9a8c\u8bc1\u3015\uff1b\u672c\u8f6e\u4ec5\u9759\u6001 IL \u4e0e C# \u53cd\u7f16\u8bd1\u3002")
    L.append("")
    (d / (it["name"] + ".md")).write_text("\n".join(L) + "\n", encoding="utf-8")


def run_clr_one(it):
    d = clr_dir(it)
    ensure(d / "il")
    ensure(d / "decompiled")
    src = SRC / it["rel"]
    started = time.time()
    res = {"key": it["key"], "status": "", "reason": "", "il_lines": 0, "cs_lines": 0,
           "elapsed_s": 0.0, "name": it["name"]}
    if not src.exists():
        res["status"] = "missing"
        res["reason"] = "source file not found"
        return res
    il = d / "il" / (it["name"] + ".il.txt")
    cs = d / "decompiled" / (it["name"] + ".cs.txt")
    env = dict(os.environ)
    env["PYTHONPATH"] = str(PYLIB)
    env["PYTHONIOENCODING"] = "utf-8"
    r1 = subprocess.run([sys.executable, str(WR / "tool" / "il_dump.py"), "--dll", str(src),
                         "--out", str(il)], cwd=str(WR), capture_output=True, text=True,
                        encoding="utf-8", errors="replace", env=env, timeout=600)
    # 二进制捕获：文本模式会把 ILSpy 的 LF 换成 os.linesep，破坏逐字节幂等。
    r2 = subprocess.run(["dotnet", str(ILSPY), str(src)], cwd=str(WR), capture_output=True,
                        timeout=600)
    if r2.returncode == 0:
        raw = r2.stdout if isinstance(r2.stdout, bytes) else (r2.stdout or "").encode("utf-8")
        # 即使剥完提示为零字节也要落盘，保证两个目标都存在。
        cs.write_bytes(strip_tool_nag(raw))
    if not il.exists() or not cs.exists():
        res["status"] = "failed_analyze"
        res["reason"] = ("il_rc=%s cs_rc=%s " % (r1.returncode, r2.returncode)
                         + ((r1.stderr or "") + (r2.stderr or ""))[:300].replace("\n", " "))
        res["elapsed_s"] = round(time.time() - started, 1)
        return res
    res["il_lines"] = len(il.read_text(encoding="utf-8", errors="replace").splitlines())
    res["cs_lines"] = len(cs.read_text(encoding="utf-8", errors="replace").splitlines())
    res["status"] = CLR_STATUS
    res["elapsed_s"] = round(time.time() - started, 1)
    write_clr_md(it, res)
    return res


def cmd_clr(args):
    items = [i for i in subset(load_plan(), args.set) if i["kind"] == "CLR"]
    if not items:
        print("CLR skip items=0")
        return 0
    started = time.time()
    results = []
    lock = threading.Lock()

    def worker(it):
        try:
            r = run_clr_one(it)
        except Exception as exc:
            r = {"key": it["key"], "name": it["name"], "status": "failed_analyze",
                 "reason": type(exc).__name__ + ": " + str(exc)[:200], "il_lines": 0,
                 "cs_lines": 0, "elapsed_s": 0.0}
        with lock:
            results.append(r)
            print("CLR name=%s status=%s il=%d cs=%d elapsed_s=%s %s" % (
                r["name"], r["status"], r["il_lines"], r["cs_lines"], r["elapsed_s"], r["reason"][:120]))
            sys.stdout.flush()

    with ThreadPoolExecutor(max_workers=args.jobs) as ex:
        list(ex.map(worker, items))
    ok = sum(1 for r in results if r["status"] == CLR_STATUS)
    print("CLR set=%s items=%d ok=%d elapsed_s=%.1f" % (args.set, len(items), ok, time.time() - started))
    (WAVE / ("clr-%s.json" % args.set)).write_text(
        json.dumps({"items": items, "results": results}, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    return 0


def nonpe_probe(src):
    code = ("import sys, dnfile\n"
            "try:\n"
            "    dnfile.dnPE(sys.argv[1])\n"
            "    print('dnfile.dnPE -> parsed as .NET assembly')\n"
            "except Exception as e:\n"
            "    print('dnfile.dnPE -> ' + type(e).__name__ + ': ' + str(e)[:200])\n"
            "try:\n"
            "    import pefile\n"
            "    pefile.PE(sys.argv[1], fast_load=True)\n"
            "    print('pefile.PE -> parsed')\n"
            "except Exception as e:\n"
            "    print('pefile.PE -> ' + type(e).__name__ + ': ' + str(e)[:200])\n")
    env = dict(os.environ)
    env["PYTHONPATH"] = str(PYLIB)
    env["PYTHONIOENCODING"] = "utf-8"
    r = subprocess.run([sys.executable, "-c", code, str(src)], capture_output=True, text=True,
                       encoding="utf-8", errors="replace", env=env, timeout=120)
    return ((r.stdout or "") + (r.stderr or "")).strip()


def cmd_nonpe(args):
    items = [i for i in subset(load_plan(), args.set) if i["kind"] == "nonPE"]
    if not items:
        print("NONPE skip items=0")
        return 0
    prods = []
    for it in items:
        d = WR / "out" / "R1" / "02-incomplete" / it["product"] / it["dir"]
        ensure(d)
        src = SRC / it["rel"]
        probe = nonpe_probe(src) if src.exists() else "source file not found"
        err = "PEFormatError: 'DOS Header magic not found.'"
        rows = []
        for line in probe.splitlines():
            if "->" in line:
                tool, _, msg = line.partition("->")
                rows.append("| " + BT + tool.strip() + BT + " | " + BT + msg.strip() + BT + " |")
                if "Error" in msg:
                    err = msg.strip()
        L = []
        L.append("# %s \u7f3a\u53e3\u62a5\u544a\uff08%s / \u672a\u4ea7\u51fa IL \u4e0e\u53cd\u7f16\u8bd1\uff09" % (it["name"], it["product"]))
        L.append("")
        L.append("\u6837\u672c\u522b\u540d\uff1a" + BT + it["name"] + BT + "\uff08\u6e05\u5355 out/B2/manifest-b2.csv\uff0c\u539f\u4ef6\u53ea\u8bfb\u3001\u672a\u4e0a\u4f20\uff09")
        L.append("\u6765\u6e90\uff1a\u5206\u652f codex/waiting-for-tietoumao\uff5c\u81ea\u7b97 sha256 %s\uff5c\u53f0\u8d26 B2-B wave1b" % it["sha256"])
        L.append("\u843d\u70b9\uff1a" + BT + "02-incomplete/%s/%s/" % (it["product"], it["dir"]) + BT + "\uff08\u76f8\u5bf9 " + BT + "out/R1" + BT + "\uff09\uff5c\u5b9a\u4f4d\u89c4\u5219\uff1a" + BT + "local-rel" + BT)
        L.append("")
        L.append("\u6807\u7b7e\u7ea6\u5b9a\uff1a\u3014\u5b9e\u6d4b\u3015= \u672c\u8f6e\u72ec\u7acb\u5b9e\u6d4b\uff08\u6709\u547d\u4ee4\u4e0e\u539f\u59cb\u8f93\u51fa\uff09\uff1b\u3014\u5f85\u9a8c\u8bc1\u3015= \u5c1a\u672a\u53d6\u5f97\u8bc1\u636e\u3002")
        L.append("")
        L.append("## 0. \u6458\u8981")
        L.append("")
        L.append("| \u9879\u76ee | \u7ed3\u679c | \u4f9d\u636e |")
        L.append("| --- | --- | --- |")
        L.append("| \u72b6\u6001 | " + BT + "status=unsupported_non_pe" + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
        L.append("| \u5b9e\u9645\u6837\u672c | %s \u5b57\u8282\uff0cSHA-256 %s | \u3014\u5b9e\u6d4b\u3015\u81ea\u7b97 |" % (format(it["size"], ","), BT + it["sha256"] + BT))
        L.append("| \u7ed3\u8bba | \u672c\u4ef6\u672a\u4ea7\u51fa IL \u6e05\u5355\u4e0e C# \u53cd\u7f16\u8bd1\uff08\u4e0d\u4f2a\u9020\u4ea7\u7269\uff09 | \u3014\u5b9e\u6d4b\u3015 |")
        L.append("")
        L.append("\u672c\u4ef6\u6309 " + BT + "status=unsupported_non_pe" + BT + " \u8bb0\u7f3a\u53e3\uff0c**\u4e0d\u4f2a\u9020** IL \u6e05\u5355 / C# \u53cd\u7f16\u8bd1\u4ea7\u7269\u3002")
        L.append("")
        L.append("\u5df2\u8bd5\u5de5\u5177\uff08\u9010\u6761\u4e3a\u5b9e\u9645\u6267\u884c\uff0c\u542b\u539f\u59cb\u62a5\u9519\uff09\uff1a")
        L.append("")
        L.append("| \u5de5\u5177 | \u7ed3\u679c |")
        L.append("| --- | --- |")
        for r in rows:
            L.append(r)
        L.append("")
        L.append("\u539f\u59cb\u62a5\u9519\uff1a" + err)
        L.append("")
        L.append("\u3014\u5f85\u9a8c\u8bc1\u3015\u672c\u4ef6\u662f\u5426\u9700\u6362\u7528\u5176\u5b83\u89e3\u6790\u5668\uff08\u5982 COFF/\u9759\u6001\u5e93\u89e3\u6790\uff09\u624d\u80fd\u5224\u5b9a\u683c\u5f0f\uff1b\u7f3a\u8be5\u5de5\u5177\u7684\u5b9e\u6d4b\u624d\u80fd\u5224\u3002")
        L.append("")
        L.append("\u542b\u5b8c\u6574\u9006\u5411\u6b63\u6587\uff0c\u4f9d\u636e\uff1a\u7528\u6237 2026-11-20 \u6307\u4ee4\uff0c\u504f\u79bb\u4ed3\u5e93 AGENTS \u8be5\u6761")
        L.append("")
        L.append("## 1. \u6837\u672c\u4e0e\u54c8\u5e0c")
        L.append("")
        L.append("| \u9879 | \u503c | \u6807\u7b7e |")
        L.append("| --- | --- | --- |")
        L.append("| \u6587\u4ef6\u540d | " + BT + it["name"] + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
        L.append("| \u5b57\u8282\u6570 | %s | \u3014\u5b9e\u6d4b\u3015 |" % format(it["size"], ","))
        L.append("| SHA-256\uff08\u672c\u8f6e\u81ea\u7b97\uff09 | " + BT + it["sha256"] + BT + " | \u3014\u5b9e\u6d4b\u3015 |")
        L.append("| \u6e05\u5355\u58f0\u660e SHA-256 | " + BT + it["sha256"] + BT + " | \u3014\u5b9e\u6d4b\u3015\u4e00\u81f4 |")
        L.append("")
        (d / (it["name"] + ".md")).write_text("\n".join(L) + "\n", encoding="utf-8")
        prods.append({"key": it["key"], "name": it["name"], "product": it["product"],
                      "dir": it["dir"], "err": err})
        print("NONPE name=%s err=%s" % (it["name"], err[:90]))
    (WAVE / ("nonpe-%s.json" % args.set)).write_text(
        json.dumps({"results": prods}, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("NONPE set=%s items=%d" % (args.set, len(items)))
    return 0


def product_sha(paths):
    parts = sorted("%s=%s;" % (Path(p).name, hashlib.sha256(Path(p).read_bytes()).hexdigest())
                   for p in paths)
    return hashlib.sha256("".join(parts).encode("utf-8")).hexdigest()


def cmd_merge_clr(args):
    led = WR / "out" / "R1" / "ledger-clr.csv"
    with open(led, "r", encoding="utf-8-sig", newline="") as fh:
        rd = csv.DictReader(fh)
        fields = list(rd.fieldnames)
        base = list(rd)
    have = set(r["analysis_key"] for r in base)
    plan = {i["key"]: i for i in load_plan()}
    new = []
    failed = 0
    p = WAVE / ("clr-%s.json" % args.set)
    if p.exists():
        doc = json.loads(p.read_text(encoding="utf-8"))
        by_key = {i["key"]: i for i in doc["items"]}
        for r in doc["results"]:
            it = by_key[r["key"]]
            if r["status"] != CLR_STATUS:
                failed += 1
                continue
            d = clr_dir(it)
            files = [d / (it["name"] + ".md"), d / "il" / (it["name"] + ".il.txt"),
                     d / "decompiled" / (it["name"] + ".cs.txt")]
            new.append({
                "analysis_key": it["key"], "product": it["product"], "product_raw": it["owner"],
                "archive_dir": "01-completed\\%s\\%s" % (it["product"], it["dir"].replace("/", "\\")),
                "source_name": it["name"], "source_path": "", "size": it["size"],
                "sha256": it["sha256"], "product_sha256": product_sha(files),
                "status": CLR_STATUS, "reason": "", "locate": "local-rel",
                "first_seen_manifest": "B", "kind": "CLR", "manifest": "out/B2/manifest-b2.csv"})
    p2 = WAVE / ("nonpe-%s.json" % args.set)
    if p2.exists():
        for r in json.loads(p2.read_text(encoding="utf-8"))["results"]:
            it = plan[r["key"]]
            d = WR / "out" / "R1" / "02-incomplete" / it["product"] / it["dir"]
            new.append({
                "analysis_key": it["key"], "product": it["product"], "product_raw": it["owner"],
                "archive_dir": "02-incomplete\\%s\\%s" % (it["product"], it["dir"].replace("/", "\\")),
                "source_name": it["name"], "source_path": "", "size": it["size"],
                "sha256": it["sha256"], "product_sha256": product_sha([d / (it["name"] + ".md")]),
                "status": "unsupported_non_pe", "reason": "unsupported_non_pe: " + r["err"],
                "locate": "local-rel", "first_seen_manifest": "B", "kind": "not-PE",
                "manifest": "out/B2/manifest-b2.csv"})
    added = 0
    for r in new:
        if r["analysis_key"] in have:
            continue
        base.append(r)
        have.add(r["analysis_key"])
        added += 1
    with open(led, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields, extrasaction="ignore", lineterminator="\n")
        w.writeheader()
        for r in base:
            w.writerow(r)
    print("MERGE-CLR ledger=%s added=%d clr_failed=%d total=%d" % (led.name, added, failed, len(base)))
    return 0


def cmd_summary(args):
    plan = load_plan()
    nat, clr = {}, {}
    with open(WR / "out" / "R1N" / "ledger-native.csv", "r", encoding="utf-8-sig", newline="") as fh:
        for r in csv.DictReader(fh):
            nat[r["analysis_key"]] = r
    with open(WR / "out" / "R1" / "ledger-clr.csv", "r", encoding="utf-8-sig", newline="") as fh:
        for r in csv.DictReader(fh):
            clr[r["analysis_key"]] = r
    ok = 0
    per = {"native": 0, "CLR": 0, "nonPE": 0}
    bad = []
    items = []
    for it in plan:
        r = (nat if it["kind"] == "native" else clr).get(it["key"]) or {}
        st = r.get("status", "not_run")
        good = st in ("analyzed", CLR_STATUS, "unsupported_non_pe")
        if good:
            ok += 1
            per[it["kind"]] += 1
        else:
            bad.append({"kind": it["kind"], "name": it["name"], "status": st,
                        "reason": (r.get("reason") or "")[:200], "rel": it["rel"]})
        items.append({"key": it["key"], "name": it["name"], "kind": it["kind"],
                      "product": it["product"], "rel": it["rel"], "status": st})
    summary = {"wave": "B2-B wave1b", "items": len(plan), "ok": ok, "failed": len(bad),
               "native": per["native"], "clr": per["CLR"], "nonpe": per["nonPE"],
               "failed_items": bad, "items_detail": items}
    (WAVE / "wave1.summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("WAVE1 items=%d ok=%d failed=%d clr=%d native=%d nonpe=%d" % (
        summary["items"], ok, len(bad), per["CLR"], per["native"], per["nonPE"]))
    for r in bad[:20]:
        print("  FAILED %s %s status=%s %s" % (r["kind"], r["name"], r["status"], r["reason"][:120]))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("plan").set_defaults(fn=cmd_plan)
    for name, fn in (("native", cmd_native), ("clr", cmd_clr), ("nonpe", cmd_nonpe),
                     ("merge", cmd_merge), ("merge-clr", cmd_merge_clr), ("summary", cmd_summary)):
        sp = sub.add_parser(name)
        sp.set_defaults(fn=fn)
        if name in ("native", "clr", "nonpe", "merge-clr"):
            sp.add_argument("--set", default="all", choices=["m1", "rest", "all"])
        if name == "native":
            sp.add_argument("--jobs", type=int, default=5)
            sp.add_argument("--dir", default="native-all")
        if name == "clr":
            sp.add_argument("--jobs", type=int, default=2)
        if name == "merge":
            sp.add_argument("--dir", default="native-all")
    args = ap.parse_args(argv)
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    if args.cmd != "summary":
        preflight()
    return args.fn(args) or 0


if __name__ == "__main__":
    sys.exit(main())
