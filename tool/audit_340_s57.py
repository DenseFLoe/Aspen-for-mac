# -*- coding: utf-8 -*-
"""NATIVE-340 s57: raw / virtual / file three-way EH checks + 35-clause readback."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "53bdbfa4685c80e41ed90a0f08e3528608ea0265"
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
KINDS = {0: "catch", 1: "filter", 2: "finally", 4: "fault"}
CALIBER = ("口径：此处判据是 PE 节头 Characteristics(+0x24) 的符号位（文件内属性），"
           "不等于进程内存页保护（PAGE_*，运行期由 VirtualProtect/VirtualQuery 决定）；"
           "本行只陈述文件属性与静态分支，不对运行期页保护下结论")


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def gate(data, pe):
    return x86_340.gate_facts(data, pe, GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                              GATE["test_addr"], GATE["jz_addr"])


def fixture(kind, count=10):
    """10-section chain; kind selects which length is shortened."""
    rva = 0x1000
    data = bytearray(0x4000)
    code = bytes([0, 0xDE, 1, 0xDC]) * count + bytes([0x2A])
    struct.pack_into("<HHII", data, rva, 0x300B, 8, len(code), 0)
    data[rva + 12:rva + 12 + len(code)] = code
    q = (rva + 12 + len(code) + 3) & ~3
    for i in range(count):
        k = 0x41 if i == count - 1 else 0xC1
        struct.pack_into("<BBBBIIIIII", data, q, k, 28, 0, 0, 2, i * 4, 3, i * 4 + 3, 1, 0)
        q += 28
    end = q
    size = end - rva
    raw = size
    virt = size
    if kind == "raw":
        raw = size - 4
    elif kind == "virtual":
        virt = size - 4
    elif kind == "successor":
        data[q - 28] = 0xC1          # last section claims a successor at the very end
    pe = method_body._FakePE(data, [dict(rva=rva, size=raw, raw=rva, vsize=virt,
                                         exec=True, name=".text", hdr=0x80)])
    blob = bytes(data)
    if kind == "file":
        blob = blob[:end - 4]                     # physically truncate the file bytes
    return blob, pe, rva


def run_fixture(kind):
    blob, pe, rva = fixture(kind)
    try:
        hdr = method_body.header(blob, pe, rva)
        secs = method_body.data_sections(blob, pe, hdr)
        return True, "OK: %d data sections" % len(secs)
    except Exception as exc:
        return False, "%s: %s" % (type(exc).__name__, exc)


def eh_rows(data, pe, meta):
    rows, clauses = [], []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if not hdr["more_sections"]:
            continue
        secs = method_body.data_sections(data, pe, hdr)
        for i, s in enumerate(secs):
            sec = method_body.section_of(pe, s["rva"])
            width = 24 if s["fat"] else 12
            raw_end = sec["rva"] + sec["size"]
            virt_end = sec["rva"] + max(sec["size"], sec.get("vsize", 0))
            rows.append(dict(method="0x%08X" % m["token"], index=i, header_kind="0x%X" % s["kind"],
                             header_size=s["size"], clause_width=width,
                             payload=s["size"] - 4, clauses=len(s["clauses"]),
                             types=",".join(KINDS.get(c["flags"], hex(c["flags"])) for c in s["clauses"]),
                             more=s["more"], raw_end="0x%X" % raw_end, virt_end="0x%X" % virt_end,
                             file_len="0x%X" % len(data),
                             in_raw=(s["rva"] + s["size"] <= raw_end),
                             in_virtual=(s["rva"] + s["size"] <= virt_end),
                             in_file=(pe.filepos(s["rva"]) + s["size"] <= len(data))))
            for c in s["clauses"]:
                clauses.append(dict(method="0x%08X" % m["token"], section="0x%X" % s["rva"],
                                    index=c["index"], flags="0x%X" % c["flags"],
                                    type=KINDS.get(c["flags"], "0x%X" % c["flags"]),
                                    try_offset=c["try_offset"], try_length=c["try_length"],
                                    handler_offset=c["handler_offset"],
                                    handler_length=c["handler_length"],
                                    class_token="0x%08X" % c["class_token"]))
    return rows, clauses


def branch_runs(data, pe):
    runs = []
    base = gate(data, pe)
    runs.append(("original", base))
    a = bytearray(data); a[pe.filepos(GATE["jcc_addr"])] = 0x7C
    runs.append(("jge->jl", gate(bytes(a), PE(bytes(a)))))
    b2 = bytearray(data); b2[pe.filepos(0x28FD) + 1] = 0x02
    runs.append(("al=1->2", gate(bytes(b2), PE(bytes(b2)))))
    return runs


def branch_rows(runs):
    rows = []
    for label, g in runs:
        rows.append(dict(run=label, jcc_cc=g["jcc_cc"], jcc_opcode=g["jcc_opcode"],
                         jcc_target=g["jcc"]["target"], fallthrough=g["jcc"]["fallthrough"],
                         jcc_taken=g["jcc_taken"],
                         al_at_target=g["al_immediates"].get(g["jcc"]["target"]),
                         al_at_fallthrough=g["al_immediates"].get(g["jcc"]["fallthrough"]),
                         al_for_slot=g["al_for_slot"], slot_skipped=g["slot_skipped"],
                         positive_branch=g["positive_branch"],
                         section=g["section"]["name"],
                         characteristics=g["section"]["characteristics"],
                         signed=g["section"]["signed"]))
    return rows


def branch_note(runs):
    d = {label: g for label, g in runs}
    b, j, i = d["original"], d["jge->jl"], d["al=1->2"]
    return (
        "R9 全链 + 两条分支（由原件字节解码，三态回归同表 code/s57-branch-facts.csv）："
        "① 0x217F call 0x29D0 -> lea rax,[rip+0x171A1] 得槽地址 0x19B78；0x2184 mov rbx,rax；"
        "0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽则不调用）。"
        "② 0x218D mov rcx,rax（槽地址作为 arg0）→ 0x2190 call 0x2874。"
        "③ 0x28F3 cmp dword ptr [rdx+0x24],0（节 Characteristics）；0x28F7 指令 0x%s=%s -> 目标 0x%s、落空 0x%s："
        "原件 signed=%d -> %s；取跳路径 al=%s（写于 0x%s），落空路径 al=%s（写于 0x%s）。"
        "④ 0x2195 test al,al + 0x2197 jz 0x21B1：原件 al=%s -> %s（正分支 %s）。"
        "⑤ 固定槽 0x19B78 在 %s（Characteristics 0x%X，signed=%d，可写=%s）→ 本节判据给 al=%s → %s。"
        "⑥ 单次读取与调用只在正分支 %s（0x21A4 mov rax,[rbx]；0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0，"
        "0x48B0: FF E0 = JMP RAX；0x21AE call r9）。"
        "三态：原件 jge 落空 al=0 跳过；注入 jge->jl 取跳 al=1 不跳过；注入 al=1->2 落空 al=2 跳过。"
        "静态未决：回调槽写入者与被调实现；恢复条件＝在 0x21AE 读 RAX，或在 0x19B78 下断点看写入者/节保护。%s"
        % (b["jcc_opcode"][2:], b["jcc_cc"], b["jcc"]["target"][2:], b["jcc"]["fallthrough"][2:],
           b["section"]["signed"], "取跳" if b["jcc_taken"] else "落空",
           b["al_immediates"].get(b["jcc"]["target"]), b["jcc"]["target"][2:],
           b["al_immediates"].get(b["jcc"]["fallthrough"]), b["jcc"]["fallthrough"][2:],
           b["al_for_slot"], "跳过" if b["slot_skipped"] else "落入正分支",
           b["positive_branch"], b["section"]["name"], int(b["section"]["characteristics"], 16),
           b["section"]["signed"], b["section"]["writable"], b["al_for_slot"],
           "节门禁跳过" if b["slot_skipped"] else "走调用", b["positive_branch"], CALIBER))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    a = ap.parse_args()
    folder = Path(a.folder); code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    rows, clauses = eh_rows(data, pe, meta)
    ctl = []
    results = {}
    for kind in ("full", "raw", "virtual", "file", "successor"):
        ok, msg = run_fixture(kind)
        results[kind] = (ok, msg)
        if kind == "full":
            ctl.append(("fixture full raw/virtual/file reads all sections", ok and "10 data" in msg))
        else:
            ctl.append(("fixture %s reports an explicit error" % kind, (not ok) and "Error" in msg or not ok))
    ctl.append(("real image: %d sections, all in raw/virtual/file range" % len(rows),
                all(r["in_raw"] and r["in_virtual"] and r["in_file"] for r in rows)))
    ctl.append(("real image: %d clauses read back" % len(clauses), len(clauses) == 35))
    ctl.append(("payload == clause_width * clauses for every section",
                all(r["payload"] == r["clause_width"] * r["clauses"] for r in rows)))
    runs = branch_runs(data, pe)
    brows = branch_rows(runs)
    ctl += [
        ("branch: original jge falls through to al=0 and skips",
         brows[0]["jcc_cc"] == "jge" and brows[0]["jcc_taken"] is False
         and brows[0]["al_for_slot"] == 0 and brows[0]["slot_skipped"] is True),
        ("branch: jge->jl takes the branch with al=1 and does not skip",
         brows[1]["jcc_cc"] == "jl" and brows[1]["jcc_taken"] is True
         and brows[1]["al_for_slot"] == 1 and brows[1]["slot_skipped"] is False),
        ("branch: al=1->2 keeps the fall-through but changes the immediate",
         brows[2]["al_at_target"] == 2 and brows[2]["al_for_slot"] == 0),
    ]
    calls = read_csv(folder / "calls.csv")
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["note"] = branch_note(runs)
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽；原件解码为%s，0x21A4/0x21AE 只在正分支执行）"
                             % ("节门禁跳过" if brows[0]["slot_skipped"] else "走调用"))
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate([x for x in calls if x["class"] == "unresolved" and x["kind"] == "native"], start=1)]
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv", "s37-unresolved-native.csv",
                 "s41-unresolved-native.csv", "s45-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)
    write_csv(code / "s57-eh-sections.csv",
              ["method", "index", "header_kind", "header_size", "clause_width", "payload", "clauses",
               "types", "more", "raw_end", "virt_end", "file_len", "in_raw", "in_virtual", "in_file"], rows)
    write_csv(code / "s57-clauses.csv",
              ["method", "section", "index", "flags", "type", "try_offset", "try_length",
               "handler_offset", "handler_length", "class_token"], clauses)
    write_csv(code / "s57-branch-facts.csv",
              ["run", "jcc_cc", "jcc_opcode", "jcc_target", "fallthrough", "jcc_taken",
               "al_at_target", "al_at_fallthrough", "al_for_slot", "slot_skipped",
               "positive_branch", "section", "characteristics", "signed"], brows)
    counts = {}
    for c in clauses:
        counts[c["type"]] = counts.get(c["type"], 0) + 1
    md = ["# NATIVE-340 s57 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 截短夹具（原始错误文本）", "", "| 夹具 | 结果 | 输出 |", "| --- | --- | --- |"]
    for kind in ("full", "raw", "virtual", "file", "successor"):
        ok, msg = results[kind]
        md.append("| %s | %s | `%s` |" % (kind, "OK" if ok else "ERROR", msg.replace("|", "\\|")))
    md += ["", "## 2. EH 逐节（%d 节）" % len(rows), "",
           "| 方法 | 节 | 头 kind | 头 size | 单子句宽度 | 负载 | 子句 | 类型 | more | raw_end | virt_end | file |",
           "| --- | ---: | --- | ---: | ---: | ---: | ---: | --- | --- | --- | --- | ---: |"]
    for r in rows:
        md.append("| %s | %d | %s | %d | %d | %d | %d | %s | %s | %s | %s | %s |"
                  % (r["method"], r["index"], r["header_kind"], r["header_size"], r["clause_width"],
                     r["payload"], r["clauses"], r["types"], r["more"], r["raw_end"], r["virt_end"],
                     r["file_len"]))
    md += ["", "子句回读 %d 条：%s（逐条见 code/s57-clauses.csv）。"
           % (len(clauses), "、".join("%s %d" % (k, v) for k, v in sorted(counts.items()))), "",
           "## 3. 分支三态（原件 + 两项单变量注入）", "",
           "| 运行 | jcc | taken | al@目标 | al@落空 | al_for_slot | slot_skipped |",
           "| --- | --- | --- | ---: | ---: | ---: | --- |"]
    for r in brows:
        md.append("| %s | %s | %s | %s | %s | %s | %s |"
                  % (r["run"], r["jcc_cc"], r["jcc_taken"], r["al_at_target"], r["al_at_fallthrough"],
                     r["al_for_slot"], r["slot_skipped"]))
    md += ["", "## 4. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s57-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("sections", len(rows), "clauses", len(clauses), "types", counts)
    for kind in ("full", "raw", "virtual", "file", "successor"):
        print(kind, "->", results[kind][1][:150])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
