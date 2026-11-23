# -*- coding: utf-8 -*-
"""NATIVE-340 s61: EH header-first boundary checks + candidate/actual branch values."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "817183580e8e59b82c3389a2cdf0a01c6ecb1e96"
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
KINDS = {0: "catch", 1: "filter", 2: "finally", 4: "fault"}
FIXTURE_KINDS = [0x81, 0xC1] * 4 + [0x81, 0x41]   # upstream normal: 276 bytes, last fat
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


def fixture(kinds):
    """Same construction as the upstream s57 review fixture (no PE headers)."""
    il = bytes([0, 0xDE, 1, 0xDC]) * len(kinds) + b"\x2a"
    data = bytearray(struct.pack("<HHII", 0x300B, 8, len(il), 0) + il)
    data += bytes(-len(data) % 4)
    for i, kind in enumerate(kinds):
        fields = (2, 4 * i, 3, 4 * i + 3, 1, 0)
        clause = struct.pack("<IIIIII" if kind & 0x40 else "<HHBHBI", *fields)
        data += bytes([kind, 4 + len(clause), 0, 0]) + clause
    return bytes(data)


def inspect(raw_trim=0, virtual_trim=0, file_trim=0):
    rva = 0x2400
    full = fixture(FIXTURE_KINDS)
    data = full[:len(full) - file_trim]
    raw, virt = len(full) - raw_trim, len(full) - virtual_trim
    pe = method_body._FakePE(data, [dict(rva=rva, size=raw, raw=0, vsize=virt,
                                         exec=True, name=".text", hdr=0x80)])
    rec = dict(full_len=len(full), raw=raw, virtual=virt, file=len(data),
               sha=hashlib.sha256(data).hexdigest())
    try:
        hdr = method_body.header(data, pe, rva)
        secs = method_body.data_sections(data, pe, hdr)
        rec.update(sections=len(secs), rvas=["0x%X" % s["rva"] for s in secs],
                   widths=[s["size"] - 4 for s in secs], more=[s["more"] for s in secs],
                   error="")
    except Exception as exc:
        rec.update(sections=0, error="%s: %s" % (type(exc).__name__, exc))
    return rec


def branch_runs(data, pe):
    runs = [("original", gate(data, pe))]
    a = bytearray(data); a[pe.filepos(GATE["jcc_addr"])] = 0x7C
    runs.append(("jge->jl", gate(bytes(a), PE(bytes(a)))))
    b2 = bytearray(data); b2[pe.filepos(0x28FD) + 1] = 0x02
    runs.append(("al=1->2", gate(bytes(b2), PE(bytes(b2)))))
    return runs


def branch_rows(runs):
    rows = []
    for label, g in runs:
        rows.append(dict(run=label, jcc_cc=g["jcc_cc"], jcc_taken=g["jcc_taken"],
                         candidate_al=g["al_immediates"].get(g["jcc"]["target"]),
                         fallthrough_al=g["al_immediates"].get(g["jcc"]["fallthrough"]),
                         actual_al=g["al_for_slot"], skipped=g["slot_skipped"]))
    return rows


def branch_note(runs):
    b, j, i = runs[0][1], runs[1][1], runs[2][1]
    return (
        "R9 全链 + 分支三态（由原件字节解码；候选路径值与实际执行值分开记）："
        "① 0x217F call 0x29D0 -> lea rax,[rip+0x171A1] 得槽地址 0x19B78；0x2184 mov rbx,rax；"
        "0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽则不调用）。"
        "② 0x218D mov rcx,rax（槽地址作为 arg0）→ 0x2190 call 0x2874。"
        "③ 0x28F3 cmp dword ptr [rdx+0x24],0（节 Characteristics）；0x28F7 指令 0x%s=%s -> 目标 0x%s、落空 0x%s。"
        "④ 0x2195 test al,al + 0x2197 jz 0x21B1（正分支 %s；al==0 跳过）。"
        "⑤ 固定槽 0x19B78 在 %s（Characteristics 0x%X，signed=%d，可写=%s）。"
        "⑥ 三态（实际执行路径）：原件 %s 落空 -> 候选路径 al=%s、实际 al=%s、跳过=%s；"
        "注入 jge->jl -> 取跳，实际 al=%s、跳过=%s；"
        "注入 0x28FE 立即数 1->2 -> 仍落空，候选路径 al=%s、实际 al=%s、跳过=%s。"
        "⑦ 单次读取与调用只在正分支 %s（0x21A4 mov rax,[rbx]；0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0，"
        "0x48B0: FF E0 = JMP RAX；0x21AE call r9）。"
        "静态未决：回调槽写入者与被调实现；恢复条件＝在 0x21AE 读 RAX，或在 0x19B78 下断点看写入者/节保护。%s"
        % (b["jcc_opcode"][2:], b["jcc_cc"], b["jcc"]["target"][2:], b["jcc"]["fallthrough"][2:],
           b["positive_branch"], b["section"]["name"], int(b["section"]["characteristics"], 16),
           b["section"]["signed"], b["section"]["writable"],
           b["jcc_cc"], b["al_immediates"].get(b["jcc"]["target"]), b["al_for_slot"],
           "真" if b["slot_skipped"] else "假",
           j["al_for_slot"], "假" if not j["slot_skipped"] else "真",
           i["al_immediates"].get(i["jcc"]["target"]), i["al_for_slot"],
           "真" if i["slot_skipped"] else "假",
           b["positive_branch"], CALIBER))


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

    # ---- fixtures: 276-byte chain at RVA 0x2400 ---------------------------
    full = inspect()
    raw_short = inspect(raw_trim=26)
    virt_short = inspect(virtual_trim=26)
    file_short = inspect(file_trim=26)
    ctl = [
        ("full 276 bytes reads 10 sections, last RVA 0x24F8",
         full["sections"] == 10 and full["rvas"][-1] == "0x24F8"
         and full["widths"] == [12, 24] * 5 and full["more"][-1] is False),
        ("file 250 bytes -> FILE error at offset 0xFA",
         "FILE" in file_short["error"] and "0xfa" in file_short["error"].lower()),
        ("raw 250 bytes -> RAW error, first invalid RVA 0x24FA",
         "RAW" in raw_short["error"] and "0x24fa" in raw_short["error"].lower()),
        ("virtual 250 bytes -> VIRTUAL error, first invalid RVA 0x24FA",
         "VIRTUAL" in virt_short["error"] and "0x24fa" in virt_short["error"].lower()),
    ]

    # ---- real image: 25 sections, 35 clauses, 0x0600000B row ---------------
    rows, clauses = [], []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if not hdr["more_sections"]:
            continue
        for i, s in enumerate(method_body.data_sections(data, pe, hdr)):
            sec = method_body.section_of(pe, s["rva"])
            width = 24 if s["fat"] else 12
            raw_end = sec["rva"] + sec["size"]
            virt_end = sec["rva"] + sec.get("vsize", sec["size"])
            rows.append(dict(method="0x%08X" % m["token"], index=i, header_kind="0x%X" % s["kind"],
                             header_size=s["size"], clause_width=width, payload=s["size"] - 4,
                             clauses=len(s["clauses"]),
                             types=",".join(KINDS.get(c["flags"], hex(c["flags"])) for c in s["clauses"]),
                             more=s["more"], raw_end="0x%X" % raw_end, virt_end="0x%X" % virt_end,
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
    key = next(r for r in rows if r["method"].lower() == "0x0600000b")
    ctl += [
        ("real image: 25 sections / 35 clauses", len(rows) == 25 and len(clauses) == 35),
        ("0x0600000B reports raw_end 0x4A00 and virt_end 0x4968",
         key["raw_end"].lower() == "0x4a00" and key["virt_end"].lower() == "0x4968"),
        ("0x0600000B reports clause width 24 and 2 clauses",
         key["clause_width"] == 24 and key["clauses"] == 2
         and key["payload"] == 24 * key["clauses"]),
        ("every section inside raw/virtual/file", all(r["in_raw"] and r["in_virtual"] and r["in_file"] for r in rows)),
    ]

    runs = branch_runs(data, pe)
    brows = branch_rows(runs)
    ctl += [
        ("branch three states: actual AL 0/1/0", [b["actual_al"] for b in brows] == [0, 1, 0]),
        ("branch three states: skipped true/false/true", [b["skipped"] for b in brows] == [True, False, True]),
        ("imm injection keeps candidate AL 2 but actual AL 0", brows[2]["candidate_al"] == 2
         and brows[2]["actual_al"] == 0),
    ]

    calls = read_csv(folder / "calls.csv")
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["note"] = branch_note(runs)
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽；原件解码为跳过，0x21A4/0x21AE 只在正分支执行）")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"], note=r["note"],
                  reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate([x for x in calls if x["class"] == "unresolved" and x["kind"] == "native"], start=1)]
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv", "s37-unresolved-native.csv",
                 "s41-unresolved-native.csv", "s45-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)

    # the upstream s57 verifier reads these canonical names; keep them refreshed and
    # also write the s61 round copies with the same data.
    canonical = [dict(run=r["run"], jcc_cc=r["jcc_cc"], jcc_taken=r["jcc_taken"],
                      al_at_target=r["candidate_al"], al_at_fallthrough=r["fallthrough_al"],
                      al_for_slot=r["actual_al"], slot_skipped=r["skipped"]) for r in brows]
    for name in ("s57-branch-facts.csv", "s61-branch-facts.csv"):
        write_csv(code / name, ["run", "jcc_cc", "jcc_taken", "al_at_target", "al_at_fallthrough",
                                "al_for_slot", "slot_skipped"], canonical)
    for name in ("s57-eh-sections.csv", "s61-eh-sections.csv"):
        write_csv(code / name, ["method", "index", "header_kind", "header_size", "clause_width",
                                "payload", "clauses", "types", "more", "raw_end", "virt_end",
                                "in_raw", "in_virtual", "in_file"], rows)
    for name in ("s57-clauses.csv", "s61-clauses.csv"):
        write_csv(code / name, ["method", "section", "index", "flags", "type", "try_offset",
                                "try_length", "handler_offset", "handler_length", "class_token"], clauses)
    write_csv(code / "s61-fixtures.csv",
              ["case", "full_len", "raw", "virtual", "file", "sections", "error"],
              [dict(case="full", **full), dict(case="raw_trim26", **raw_short),
               dict(case="virtual_trim26", **virt_short), dict(case="file_trim26", **file_short)])
    counts = {}
    for c in clauses:
        counts[c["type"]] = counts.get(c["type"], 0) + 1
    md = ["# NATIVE-340 s61 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 276 字节夹具（RVA 0x2400，交替 small/fat）", "",
          "| 用例 | raw | virtual | file | 节数 | 错误 |", "| --- | ---: | ---: | ---: | ---: | --- |"]
    for case, rec in (("full", full), ("raw_trim26", raw_short), ("virtual_trim26", virt_short),
                      ("file_trim26", file_short)):
        md.append("| %s | %d | %d | %d | %d | `%s` |"
                  % (case, rec["raw"], rec["virtual"], rec["file"], rec["sections"],
                     (rec["error"] or "-").replace("|", "\\|")))
    md += ["", "## 2. 原件 0x0600000B", "",
           "| raw_end | virt_end | 单子句宽度 | 子句数 | 负载 |", "| --- | --- | ---: | ---: | ---: |",
           "| %s | %s | %d | %d | %d |" % (key["raw_end"], key["virt_end"], key["clause_width"],
                                          key["clauses"], key["payload"]), "",
           "25 节 / 35 条子句：%s。" % "、".join("%s %d" % (k, v) for k, v in sorted(counts.items())), "",
           "## 3. 分支三态（候选路径值 vs 实际值）", "",
           "| 运行 | jcc | taken | 候选 al | 落空 al | 实际 al | 跳过 |", "| --- | --- | --- | ---: | ---: | ---: | --- |"]
    for r in brows:
        md.append("| %s | %s | %s | %s | %s | %s | %s |"
                  % (r["run"], r["jcc_cc"], r["jcc_taken"], r["candidate_al"],
                     r["fallthrough_al"], r["actual_al"], r["skipped"]))
    md += ["", "## 4. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s61-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    for case, rec in (("full", full), ("raw", raw_short), ("virtual", virt_short), ("file", file_short)):
        print(case, "->", rec["sections"], rec["error"][:160])
    print("0x0600000B", key["raw_end"], key["virt_end"], key["clause_width"], key["clauses"])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
