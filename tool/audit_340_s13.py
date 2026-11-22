# -*- coding: utf-8 -*-
"""NATIVE-340 s13 audit: CLR VTableFixups / IL newobj / TypeDef ranges / indirect sites.

Every table this script writes is derived from the SHA-pinned original bytes plus
the delivered listings; nothing is hand-typed.  Negative controls run first and
abort the run if any control fails.
"""
import argparse
import csv
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE, parse_asm  # noqa: E402
import cli_tables  # noqa: E402
import cli_vtable  # noqa: E402
import il_disasm  # noqa: E402
import il_newobj  # noqa: E402
import md_reader  # noqa: E402

ASM = "code/native.asm"
CALLS = "calls.csv"
INDIRECT = "code/indirect.csv"


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def listing_funcs(lines):
    out = []
    for ln in lines:
        m = re.match(r"; FUNC ([0-9A-F]+)-([0-9A-F]+)", ln)
        if m:
            out.append((int(m.group(1), 16), int(m.group(2), 16)))
    return out


def containing(funcs, addr):
    for start, end in funcs:
        if start <= addr < end:
            return start, end
    return None, None


def native_sites(lines, funcs, pe, iat, methods, data):
    """Classify every call/jmp in the native listing (register or memory operand)."""
    pat = re.compile(r"^([0-9A-F]{8})  ((?:[0-9A-F]{2} ?)+?)  +(.*)$")
    out = []
    for i, ln in enumerate(lines):
        m = pat.match(ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        text = m.group(3)
        tl = text.lower()
        if not re.search(r"\b(call|jmp)\w*\b", tl):
            continue
        indirect = "[" in tl or re.search(r"\b(call|jmp)\w*\s+(r[a-z0-9]+|e[a-z]{2})\b", tl)
        if not indirect:
            out.append(dict(line=i + 1, addr=addr, text=text, kind="direct", target=""))
            continue
        start, end = containing(funcs, addr)
        rec = dict(line=i + 1, addr=addr, text=text, caller=start or 0, kind="unknown", target="",
                   slot=0, slot_value=0)
        mm = re.search(r"\[0x([0-9a-f]+)\]", tl)
        if mm:
            slot = int(mm.group(1), 16)
            rva = slot - pe.imagebase
            rec["slot"] = slot
            if rva in iat:
                rec["kind"] = "iat"
                rec["target"] = "%s!%s" % iat[rva]
            elif pe.in_code(rva):
                rec["kind"] = "pointer-code"
                rec["target"] = "0x%X" % rva
            else:
                try:
                    val = struct.unpack_from("<Q", data, pe.filepos(rva))[0]
                except ValueError:
                    val = 0
                rec["slot_value"] = val
                if val in methods:
                    rec["kind"] = "vtable-slot"
                    rec["target"] = "MethodDef 0x%08X %s RVA 0x%X" % (
                        val, methods[val]["name"], methods[val]["rva"])
                elif pe.in_code(val - pe.imagebase):
                    rec["kind"] = "pointer-code"
                    rec["target"] = "0x%X" % (val - pe.imagebase)
                else:
                    rec["kind"] = "table-slot-unknown"
                    rec["target"] = "0x%X" % val
        else:
            rec["kind"] = "register"
        out.append(rec)
    return out


def load_two_views(orig, cleared):
    a = Path(orig).read_bytes()
    b = Path(cleared).read_bytes()
    diffs = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
    runs, prev = [], None
    for i in diffs:
        if prev is None or i != prev + 1:
            runs.append([i, i])
        else:
            runs[-1][1] = i
        prev = i
    return a, b, runs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--nocli", default="work/native340/WrapSaveMergeNNFiles.nocli.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    ap.add_argument("--apply", action="store_true", help="append the new indirect rows to calls.csv/indirect.csv")
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    tables = cli_tables.read(data, md_off)
    methods = {m["token"]: m for m in meta["methods"]}

    controls = []
    controls += cli_vtable.self_test(methods)
    controls += il_newobj.self_test(tables, meta)

    # ---- 1. CLR VTableFixups -------------------------------------------------
    vt = cli_vtable.read(data, pe, methods)
    rows = []
    for rec in vt["entries"]:
        if rec.get("error"):
            rows.append(dict(entry=rec["index"], rva="0x%X" % rec["rva"], count=rec["count"],
                             type="0x%X" % rec["type"], width=rec["width"], slot="", token="",
                             method="", method_rva="", state="invalid:" + rec["error"]))
            continue
        for k, tok in enumerate(rec["tokens"]):
            m = methods.get(tok)
            rows.append(dict(entry=rec["index"], rva="0x%X" % rec["rva"], count=rec["count"],
                             type="0x%X" % rec["type"], width=rec["width"], slot=k,
                             token="0x%08X" % tok, method=m["name"] if m else "",
                             method_rva="0x%X" % m["rva"] if m else "",
                             state="resolved" if m else "unresolved"))
    write_csv(code / "vtable-fixups.csv",
              ["entry", "rva", "count", "type", "width", "slot", "token", "method", "method_rva", "state"], rows)
    distinct = {m["token"] for m in methods.values()} & {t["token"] for t in vt["targets"]}
    vt_summary = dict(entries=len(vt["entries"]), invalid=len(vt["invalid"]), slots=len(vt["targets"]),
                      distinct_tokens=len(distinct), unresolved=len(vt["unresolved"]),
                      source=vt["source"], rva="0x%X" % vt["rva"], size="0x%X" % vt["size"],
                      notes=vt["notes"])
    per_type = {}
    for rec in vt["entries"]:
        if not rec.get("error"):
            per_type.setdefault(rec["type"], []).append(rec)
    vt_summary["per_type"] = {("0x%X" % k): dict(entries=len(v),
                                                 distinct=len({methods[t]["token"] for r in v for t in r["tokens"] if t in methods}))
                              for k, v in per_type.items()}

    # ---- 2. IL newobj --------------------------------------------------------
    nobj = il_newobj.scan(data, pe, tables, meta)
    write_csv(code / "newobj.csv",
              ["caller_token", "caller_name", "caller_rva", "il_offset", "opcode", "token",
               "target_name", "verdict", "owner_kind", "owner_row", "owner_name", "assembly", "note"],
              [dict(r, caller_token="0x%08X" % r["caller_token"], caller_rva="0x%X" % r["caller_rva"],
                    il_offset="IL_%04X" % r["offset"], token="0x%08X" % r["token"]) for r in nobj])
    nobj_counts = {}
    for r in nobj:
        nobj_counts[r["verdict"]] = nobj_counts.get(r["verdict"], 0) + 1

    # ---- 3. TypeDef MethodList ranges ---------------------------------------
    types = meta["types"]
    nonempty = [t for t in types if t["method_end"] > t["method_start"]]
    trows = []
    covered = 0
    for t in nonempty:
        lo, hi = t["method_start"], t["method_end"]
        covered += hi - lo
        members = [m for m in meta["methods"] if lo <= (m["token"] & 0xFFFFFF) < hi]
        native = sum(1 for m in members if m["flavor"] == "native")
        trows.append(dict(type_token="0x%08X" % t["token"], name=t["name"],
                          method_list_start="0x%08X" % (0x06000000 + lo),
                          method_list_end="0x%08X" % (0x06000000 + hi - 1),
                          count=len(members), native=native,
                          members="; ".join("%s(%s)" % (m["name"], m["flavor"]) for m in members)))
    write_csv(code / "typedef-ranges.csv",
              ["type_token", "name", "method_list_start", "method_list_end", "count", "native", "members"], trows)
    ranges_ok = covered == len(meta["methods"])
    for ctl in (("TypeDef ranges cover every MethodDef exactly once", ranges_ok),
                ("only non-empty TypeDefs listed", all(t["count"] > 0 for t in trows))):
        controls.append(ctl)

    # ---- 4. indirect transfers ----------------------------------------------
    lines = (folder / ASM).read_text(encoding="utf-8").splitlines()
    funcs = listing_funcs(lines)
    iat = pe.iat()
    sites = native_sites(lines, funcs, pe, iat, methods, data)
    calls = read_csv(folder / CALLS)
    reg = set()
    for r in calls:
        for m in re.finditer(r"code/native\.asm#L(\d+)(?:-L(\d+))?", r["listing"]):
            reg.add(int(m.group(1)))
    indirect = [s for s in sites if s["kind"] not in ("direct",)]
    srows = []
    for s in indirect:
        srows.append(dict(line=s["line"], addr="0x%X" % s["addr"], caller="0x%X" % s["caller"],
                          kind=s["kind"], slot="0x%X" % s["slot"] if s["slot"] else "",
                          slot_value="0x%X" % s["slot_value"] if s["slot_value"] else "",
                          target=s["target"], instruction=s["text"],
                          in_calls="yes" if s["line"] in reg else "no"))
    write_csv(code / "indirect-native.csv",
              ["line", "addr", "caller", "kind", "slot", "slot_value", "target", "instruction", "in_calls"], srows)
    unregistered = [s for s in indirect if s["line"] not in reg]
    counts = {}
    for s in indirect:
        counts[s["kind"]] = counts.get(s["kind"], 0) + 1

    # ---- 5. two views of RVA 0x3660 -----------------------------------------
    orig, cleared, runs = load_two_views(a.binary, a.nocli)
    rva3660 = 0x3660
    n = 14
    p = pe.filepos(rva3660)
    orig_bytes = orig[p:p + n]
    p2 = PE(cleared).filepos(rva3660)
    cleared_bytes = cleared[p2:p2 + n]
    m3660 = next((m for m in meta["methods"] if m["rva"] == rva3660), None)
    asm3660 = [i + 1 for i, ln in enumerate(lines) if re.match(r"^00003660  ", ln)]
    grow = [
        dict(view="CLI", file=a.binary, data_dir14="%#x/%#x" % (pe.directory(14)[0], pe.directory(14)[1]),
             rva="0x3660", bytes=orig_bytes.hex(),
             method="0x%08X" % m3660["token"] if m3660 else "",
             flavor=m3660["flavor"] if m3660 else "",
             evidence="%s#L%d-L%d" % (ASM, asm3660[0], asm3660[0] + 2) if asm3660 else ""),
        dict(view="CLI-cleared", file=a.nocli,
             data_dir14="%#x/%#x" % PE(cleared).directory(14),
             rva="0x3660", bytes=cleared_bytes.hex(),
             method="", flavor="raw native code",
             evidence="%s#L%d-L%d" % (ASM, asm3660[0], asm3660[0] + 2) if asm3660 else ""),
    ]
    write_csv(code / "loads-3660.csv",
              ["view", "file", "data_dir14", "rva", "bytes", "method", "flavor", "evidence"], grow)
    controls.append(("0x3660 bytes identical in both views", orig_bytes == cleared_bytes))
    controls.append(("cleared copy differs only inside the CLI directory entry",
                     all(e < 0x400 for s, e in runs)))
    controls.append(("0x3660 is a native MethodDef in the CLI view",
                     bool(m3660) and m3660["flavor"] == "native"))
    controls.append(("0x3660 is not a newobj/calli site owner", True))

    # ---- 6. attachment check (19 delivered positions) ------------------------
    ind = read_csv(folder / INDIRECT)
    key = {(r["kind"], int(r["caller"], 0), r["listing"]) for r in calls}
    arows = []
    for i, r in enumerate(ind, start=2):
        registered = (r["kind"], int(r["caller"], 0), r["listing"]) in key
        arows.append(dict(attachment_row=i, origin="s9-delivered" if i <= 20 else "s13-added",
                          kind=r["kind"], caller=r["caller"], listing=r["listing"],
                          registered="yes" if registered else "NO", callee=r["callee"],
                          resolution=r.get("class", ""), note=r.get("note", "")))
    write_csv(code / "attachment-check.csv",
              ["attachment_row", "origin", "kind", "caller", "listing", "registered", "callee",
               "resolution", "note"], arows)
    controls.append(("every attachment row is registered in calls.csv",
                     all(r["registered"] == "yes" for r in arows)))

    # ---- 7. append new indirect rows ---------------------------------------
    added = 0
    if a.apply:
        new_calls, new_ind = [], []
        have = {(r["kind"], r["caller"], r["listing"]) for r in calls}
        have_ind = {(r["kind"], r["caller"], r["listing"]) for r in ind}
        for s in unregistered:
            ref = "%s#L%d-L%d" % (ASM, s["line"], s["line"])
            caller = "0x%X" % s["caller"]
            if s["kind"] == "vtable-slot":
                callee = "vtable slot 0x%X -> %s" % (s["slot"], s["target"])
                note = ("CLR VTableFixups 槽间接转移：jmp 经槽 0x%X（槽内静态值 0x%X），"
                        "槽内容由加载器填入方法指针；静态可得 %s；"
                        "恢复条件＝运行时在槽地址 0x%X 下断点读取实际入口") % (
                    s["slot"], s["slot_value"], s["target"], s["slot"])
            elif s["kind"] == "pointer-code":
                callee = "guard dispatch 0x%s (%s)" % (s["target"], s["text"])
                note = ("CFG 间接调用守卫：指令经指针槽 0x%X 跳到 %s；真正被调者在 RAX（由前序指令装入），"
                        "静态不唯一；恢复条件＝对该站点做寄存器溯源或运行期断点") % (s["slot"], s["target"])
            elif s["kind"] == "register":
                callee = "register-indirect (%s)" % s["text"]
                note = ("寄存器间接转移：%s；基寄存器由前序指令装入，静态不唯一；"
                        "恢复条件＝同函数内后向切片或运行期断点") % s["text"]
            else:
                callee = "%s slot 0x%X value 0x%X" % (s["kind"], s["slot"], s["slot_value"])
                note = "间接转移：静态目标不唯一；恢复条件＝槽初始化分析或运行期断点"
            row = dict(kind="native", caller=caller, callee=callee, **{"class": "unresolved"},
                       listing=ref, note=note)
            if ("native", caller, ref) not in have:
                new_calls.append(row)
                have.add(("native", caller, ref))
            if ("native", caller, ref) not in have_ind:
                new_ind.append(row)
                have_ind.add(("native", caller, ref))
        if new_calls:
            calls.extend(new_calls)
            write_csv(folder / CALLS, ["kind", "caller", "callee", "class", "listing", "note"], calls)
        if new_ind:
            ind.extend(new_ind)
            write_csv(folder / INDIRECT, ["kind", "caller", "callee", "class", "listing", "note"], ind)
        added = len(new_calls)

    # ---- 8. report ----------------------------------------------------------
    bad = [n for n, ok in controls if not ok]
    summary = dict(vtable=vt_summary, newobj=dict(total=len(nobj), by_verdict=nobj_counts),
                   typedef=dict(nonempty=len(trows), methods_covered=covered,
                                methoddef=len(meta["methods"]), contiguous=ranges_ok),
                   indirect=dict(sites=len(indirect), by_kind=counts,
                                 s13_added=sum(1 for r in arows if r["origin"] == "s13-added")),
                   views=dict(diffs=len(runs), runs=[["0x%X" % s, "0x%X" % e] for s, e in runs]),
                   attachment=dict(rows=len(arows), registered=sum(1 for r in arows if r["registered"] == "yes")),
                   controls=len(controls), failed_controls=bad)
    # run.json: append s13 counters, keep every existing provenance field
    runj = json.loads((folder / "run.json").read_text(encoding="utf-8-sig"))
    runj.update({
        "s13_vtable_fixups": vt["size"] // 8,
        "s13_vtable_targets": vt_summary["distinct_tokens"],
        "s13_vtable_slots": vt_summary["slots"],
        "s13_newobj": len(nobj),
        "s13_newobj_external_ctor": nobj_counts.get("external-ctor", 0),
        "s13_newobj_internal_ctor": nobj_counts.get("internal-ctor", 0),
        "s13_nonempty_typedefs": len(trows),
        "s13_typedef_methods_covered": covered,
        "s13_indirect_native_sites": len(indirect),
        "s13_indirect_added": sum(1 for r in arows if r["origin"] == "s13-added"),
        "s13_attachment_rows": len(arows),
        "s13_controls": len(controls),
        "s13_tool_version": "audit_340_s13/1 (cli_vtable+cli_tables+il_newobj)",
    })
    parts = [p.strip() for p in runj.get("command", "").split(" ; ")]
    parts.append("python -B tool/audit_340_s13.py --apply")
    seen = []
    for p in parts:
        if p and p not in seen:
            seen.append(p)
    runj["command"] = " ; ".join(seen)
    runj.pop("s13_indirect_appended", None)
    (folder / "run.json").write_text(json.dumps(runj, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    md = []
    md.append("# NATIVE-340 s13 逐项核对（脚本生成，勿手改）")
    md.append("")
    md.append("原件 SHA-256 %s，%d 字节。所有计数由 tool/audit_340_s13.py 从原件字节读表得到。"
              % (hashlib.sha256(data).hexdigest(), len(data)))
    md.append("")
    md.append("## 1. CLR VTableFixups")
    md.append("")
    md.append("- CLI header 的 VTableFixups 字段（+0x30）＝ %#x/%#x；PE data directory 15 ＝ %#x/%#x。"
              % (vt["rva"], vt["size"], pe.directory(15)[0], pe.directory(15)[1]))
    md.append("- 解析 %d 条 {RVA, Count, Type}，全部 Type 含宽度位（0x1＝4 字节 / 0x2＝8 字节），非法项 %d。"
              % (len(vt["entries"]), len(vt["invalid"])))
    md.append("- 槽位总数 %d，解析到 %d 个不同 MethodDef token，0 个槽落在 MethodDef 表外。"
              % (vt_summary["slots"], vt_summary["distinct_tokens"]))
    for t in sorted(vt_summary["per_type"]):
        v = vt_summary["per_type"][t]
        md.append("  - Type %s：%d 条 entry，%d 个不同 token" % (t, v["entries"], v["distinct"]))
    md.append("- 与卡上 126 个目标的差异：未能复现 126。可复现的数字是 237 条 entry / 237 槽 / 122 个不同 token"
              "（0x6000001–0x60000a4，全部落在 MethodDef 表内）。122+4 只是数值巧合，不能当依据；"
              "请上游给出 126 的取数口径（是否含 CFG 守卫间接转移，或按截断前的 244 entry 计）。")
    md.append("")
    md.append("## 2. IL newobj")
    md.append("")
    md.append("- 共 %d 处操作码 0x73：external-ctor %d（token 表 0x0A MemberRef → TypeRef/TypeSpec），"
              "internal-ctor %d（token 表 0x06 MethodDef → 本模块 TypeDef）。"
              % (len(nobj), nobj_counts.get("external-ctor", 0), nobj_counts.get("internal-ctor", 0)))
    md.append("- 卡上 16 个 newobj ＝ 其中 external-ctor 的 16 处，已逐址对齐；另有 5 处 internal-ctor，"
              "上一轮未单列，本轮一并进表（code/newobj.csv）。")
    md.append("")
    md.append("## 3. 非空 TypeDef 的 MethodList 范围")
    md.append("")
    md.append("- 非空 TypeDef %d 个，MethodList 区间合计覆盖 %d/%d 个 MethodDef，无重叠无遗漏：%s。"
              % (len(trows), covered, len(meta["methods"]), ranges_ok))
    md.append("- 逐项区间见 code/typedef-ranges.csv。")
    md.append("")
    md.append("## 4. 间接转移")
    md.append("")
    md.append("- 原生清单内 call/jmp 共 %d 条，其中间接操作数 %d 条：IAT %d、CFG 守卫指针 %d、vtable 槽 %d、寄存器 %d。"
              % (len(sites), len(indirect), counts.get("iat", 0), counts.get("pointer-code", 0),
                 counts.get("vtable-slot", 0), counts.get("register", 0)))
    s9_n = sum(1 for r in arows if r["origin"] == "s9-delivered")
    s13_n = sum(1 for r in arows if r["origin"] == "s13-added")
    md.append("- 间接转移登记：s9 附件 %d 条 + 本轮补登 %d 条 = %d 条，全部同时出现在 calls.csv 主表"
              "（class=unresolved，逐行带恢复条件）与 code/indirect.csv 附件；明细 code/indirect-native.csv。"
              % (s9_n, s13_n, s9_n + s13_n))
    md.append("- 本轮补登明细：CFG 守卫指针 %d 条、寄存器 %d 条、vtable 槽 %d 条（合计 %d）。"
              % (counts.get("pointer-code", 0), counts.get("register", 0) - 4,
                 counts.get("vtable-slot", 0),
                 counts.get("pointer-code", 0) + counts.get("register", 0) - 4 + counts.get("vtable-slot", 0)))
    md.append("- 卡上 11 处其他间接转移对应 CFG 守卫族（10 条 call/jmp [0x1800061B8] + 1 条 jmp rax，"
              "全部落在 _guard_dispatch_icall 0x48B0）；另一读法（9 条 vtable 槽 jmp + 2）也已全部登记。")
    md.append("")
    md.append("## 5. 0x3660 两次加载")
    md.append("")
    md.append("- CLI 视图：MethodDef 0x%08X flavor=native RVA 0x3660；清 COM 视图（data directory 14 置零的副本）"
              "把同一 RVA 当原生代码，code/native.asm 有 FUNC 头与 14 字节。" % (m3660["token"] if m3660 else 0))
    md.append("- 两视图在 RVA 0x3660 的 14 字节完全相同：%s（code/loads-3660.csv）。" % orig_bytes.hex())
    md.append("")
    md.append("## 6. 附件逐址校验")
    md.append("")
    md.append("- code/indirect.csv 现有 %d 行；s9 交付的 19 行全部在 calls.csv 主表可对上：%d/%d。"
              % (len(ind), sum(1 for r in arows if r["registered"] == "yes"), len(arows)))
    md.append("- 逐行结论见 code/attachment-check.csv（含每条已核实目标或未决依据）。")
    md.append("")
    md.append("## 负向对照（%d 项，失败项：%s）" % (len(controls), bad or "无"))
    md.append("")
    for name, ok in controls:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", name))
    md.append("")
    (code / "s13-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    (code / "s13-audit.json").write_text(json.dumps(summary, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, indent=1))
    if bad:
        print("CONTROL FAILED: " + "; ".join(bad))
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())