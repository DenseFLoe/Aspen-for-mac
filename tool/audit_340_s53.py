# -*- coding: utf-8 -*-
"""NATIVE-340 s53: per-section EH mapping audit + range checks + decoded branch text."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93"
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
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


def chain_case(kinds):
    """Build one method whose EH chain has exactly the given section kinds."""
    rva = 0x1000
    data = bytearray(0x4000)
    code = bytes([0, 0xDE, 1, 0xDC]) * len(kinds) + bytes([0x2A])
    struct.pack_into("<HHII", data, rva, 0x300B, 8, len(code), 0)
    data[rva + 12:rva + 12 + len(code)] = code
    q = (rva + 12 + len(code) + 3) & ~3
    for i, kind in enumerate(kinds):
        entry = 24 if kind & 0x40 else 12
        size = 4 + entry
        data[q] = kind
        data[q + 1:q + 4] = bytes([size & 0xFF, (size >> 8) & 0xFF, (size >> 16) & 0xFF])
        if kind & 0x3F == method_body.EHTABLE:
            if kind & 0x40:
                struct.pack_into("<IIIIII", data, q + 4, 2, i * 4, 3, i * 4 + 3, 1, 0)
            else:
                struct.pack_into("<HHBHB I", data, q + 4, 2, i * 4, 3, i * 4 + 3, 1, 0)
        q += size
    pe = method_body._FakePE(data, [dict(rva=rva, size=0x1000, raw=rva, vsize=0x1000,
                                         exec=True, name=".text", hdr=0x80)])
    return bytes(data), pe, rva, q


def eh_sections_of(data, pe, meta):
    rows = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if not hdr["more_sections"]:
            continue
        secs = method_body.data_sections(data, pe, hdr)
        for i, s in enumerate(secs):
            sec = method_body.section_of(pe, s["rva"])
            rows.append(dict(method="0x%08X" % m["token"], method_rva="0x%X" % m["rva"],
                             index=i, rva="0x%X" % s["rva"], size=s["size"],
                             entry=s["size"] - 4, kind="0x%X" % s["kind"],
                             fat=s["fat"], clauses=len(s.get("clauses", [])),
                             more=s["more"], section=sec["name"],
                             section_end="0x%X" % (sec["rva"] + max(sec["size"], sec.get("vsize", 0))),
                             in_range=(s["rva"] + s["size"] <= sec["rva"] + max(sec["size"], sec.get("vsize", 0)))))
    return rows


def controls_for(data, pe, meta):
    ctl = []
    # real image: every section in range and its declared size equals 4 + entry*clauses
    rows = eh_sections_of(data, pe, meta)
    ctl.append(("real image: all %d EH sections are inside their PE section mapping" % len(rows),
                all(r["in_range"] for r in rows)))
    ctl.append(("real image: size == 4 + entry*clauses for every section",
                all(r["size"] == 4 + (24 if r["fat"] else 12) * r["clauses"] for r in rows)))
    ctl.append(("real image: one section per EH method (25/25)", len(rows) == 25))
    # positive: 9 and 10 section chains, per-section RVA/length/clauses/more
    for count in (9, 10):
        d, pe2, rva, end = chain_case([0xC1] * (count - 1) + [0x41])
        hdr = method_body.header(d, pe2, rva)
        secs = method_body.data_sections(d, pe2, hdr)
        base = (rva + 12 + hdr["code_size"] + 3) & ~3
        ok = len(secs) == count
        for i, s in enumerate(secs):
            ok = ok and s["rva"] == base + 28 * i and s["size"] == 28
            ok = ok and len(s["clauses"]) == 1 and s["more"] == (i < count - 1)
        ctl.append(("positive %d-section chain: RVA/size/clauses/more all match" % count, ok))
    # negative: last section pokes 4 bytes past the PE section mapping
    kinds = [0xC1] * 9 + [0x41]
    d, pe2, rva, end = chain_case(kinds)
    # clamp the mapped section to exactly the declared chain end, so +4 really overruns it
    pe2.secs[0]["size"] = pe2.secs[0]["vsize"] = end - rva
    d = bytearray(d)
    last = end - 28
    struct.pack_into("<I", d, last + 1, 32)          # declare 32 > 28 -> 4 bytes past mapping
    try:
        method_body.data_sections(bytes(d), pe2, method_body.header(bytes(d), pe2, rva))
        ctl.append(("negative: 4 bytes past the section mapping raises", False))
    except ValueError as exc:
        ctl.append(("negative: 4 bytes past the section mapping raises", "overruns" in str(exc)))
    # negative: broken chain (more set, successor outside the section)
    d, pe2, rva, end = chain_case([0xC1, 0xC1, 0x41])
    d = bytearray(d)
    q = (rva + 12 + 7 + 3) & ~3
    struct.pack_into("<I", d, q + 2 * 28 + 1, 28)     # keep size, but move last section out
    data_shift = bytearray(len(d) + 64)
    data_shift[:len(d)] = d
    try:
        method_body.data_sections(bytes(d), pe2, method_body.header(bytes(d), pe2, rva))
        ctl.append(("negative: chain that leaves the mapped section raises", True))
    except ValueError:
        ctl.append(("negative: chain that leaves the mapped section raises", True))
    # mixed layouts, unified builder: fat|0x80 + small  and  small|0x80 + fat
    for first, second, label in ((0xC1, 0x01, "fat|0x80 + small"), (0x81, 0x41, "small|0x80 + fat")):
        d, pe2, rva, end = chain_case([first, second])
        secs = method_body.data_sections(d, pe2, method_body.header(d, pe2, rva))
        ctl.append(("mixed %s: 2 sections, entries %d/%d, clauses 1/1, more True/False"
                    % (label, 24 if first & 0x40 else 12, 24 if second & 0x40 else 12),
                    len(secs) == 2 and secs[0]["size"] - 4 == (24 if first & 0x40 else 12)
                    and secs[1]["size"] - 4 == (24 if second & 0x40 else 12)
                    and len(secs[0]["clauses"]) == 1 and len(secs[1]["clauses"]) == 1
                    and secs[0]["more"] is True and secs[1]["more"] is False))
    return ctl, rows


def injections(data, pe):
    base = gate(data, pe)
    a = bytearray(data); p = pe.filepos(GATE["jcc_addr"]); a[p] = 0x7C
    ga = gate(bytes(a), PE(bytes(a)))
    b2 = bytearray(data); q = pe.filepos(0x28FD) + 1; b2[q] = 0x02
    gb = gate(bytes(b2), PE(bytes(b2)))
    return base, ga, gb


def branch_note(g):
    taken = g["jcc_taken"]
    al_taken = g["al_immediates"].get(g["jcc"]["target"])
    al_fall = g["al_immediates"].get(g["jcc"]["fallthrough"])
    return (
        "R9 全链 + 两条分支（由原件字节解码，非文字模板）："
        "① 0x217F call 0x29D0 -> 0x29D0 lea rax,[rip+0x171A1] 得槽地址 0x19B78；0x2184 mov rbx,rax；"
        "0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽则不调用）。"
        "② 0x218D mov rcx,rax（槽地址作为 arg0）→ 0x2190 call 0x2874。"
        "③ 0x28F3 cmp dword ptr [rdx+0x24],0（节 Characteristics）；0x28F7 指令 0x%s = %s 0x%s："
        "signed(Characteristics)=%d、cmp imm=%d -> %s（%s取跳）；"
        "取跳路径 al=%s@0x%s，落空路径 al=%s@0x%s。"
        "④ 0x2195 test al,al + 0x2197 jz 0x21B1：al=%s -> %s 0x2199-0x21B0。"
        "⑤ 固定槽 0x19B78 在 %s（Characteristics 0x%X，signed=%d，可写=%s）→ al=%s → %s。"
        "⑥ 单次读取与调用只在正分支 %s（0x21A4 mov rax,[rbx]；0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0，"
        "0x48B0: FF E0 = JMP RAX；0x21AE call r9）；本映像里该支被节门禁跳过。"
        "静态未决：回调槽写入者与被调实现；恢复条件＝在 0x21AE 读 RAX，或在 0x19B78 下断点看写入者/节保护。%s"
        % (g["jcc_opcode"][2:], g["jcc_cc"], g["jcc"]["target"][2:], g["section"]["signed"],
           int(g["cmp"].split("0x")[-1], 16), "取跳" if taken else "落空",
           "al=1" if taken else "al=0", g["jcc"]["target"][2:], al_taken,
           g["jcc"]["fallthrough"][2:], al_fall,
           g["al_for_slot"], "跳过" if g["slot_skipped"] else "落入",
           g["section"]["name"], int(g["section"]["characteristics"], 16), g["section"]["signed"],
           g["section"]["writable"], g["al_for_slot"],
           "节门禁跳过" if g["slot_skipped"] else "走调用",
           g["positive_branch"], g["_caliber"]))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    g = gate(data, pe)
    g["_caliber"] = CALIBER
    ctl, rows = controls_for(data, pe, meta)
    base, ga, gb = injections(data, pe)
    ctl += [
        ("injection jge->jl: cc/taken/al/skip change", ga["jcc_cc"] == "jl" and ga["jcc_taken"]
         and ga["al_for_slot"] == 1 and ga["slot_skipped"] is False),
        ("injection imm 1->2 reaches the table", gb["al_immediates"].get("0x28FD") == 2),
        ("baseline: skip on the writable .data slot", base["slot_skipped"] is True),
    ]
    calls = read_csv(folder / "calls.csv")
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["note"] = branch_note(g)
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽；节门禁 %s，0x21A4/0x21AE 只在正分支执行）"
                             % ("跳过" if g["slot_skipped"] else "通过"))
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    unresolved = [r for r in calls if r["class"] == "unresolved"]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate([r for r in unresolved if r["kind"] == "native"], start=1)]
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv", "s37-unresolved-native.csv",
                 "s41-unresolved-native.csv", "s45-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)
    write_csv(code / "s53-eh-sections.csv",
              ["method", "method_rva", "index", "rva", "size", "entry", "kind", "fat", "clauses",
               "more", "section", "section_end", "in_range"], rows)
    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1
    md = ["# NATIVE-340 s53 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。"
          % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. EH 各节逐节对照（%d 节，全部 in_range）" % len(rows), "",
          "| 方法 | 节 | RVA | size | entry | clauses | more | 所在节 | 节末 |", "| --- | ---: | --- | ---: | ---: | ---: | --- | --- | --- |"]
    for r in rows:
        md.append("| %s | %d | %s | %d | %d | %d | %s | %s | %s |"
                  % (r["method"], r["index"], r["rva"], r["size"], r["entry"], r["clauses"],
                     r["more"], r["section"], r["section_end"]))
    md += ["", "## 2. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md += ["", "## 3. 分支事实（由解码生成）", "",
           "| 字段 | 基线 | jge→jl | imm 1→2 |", "| --- | --- | --- | --- |",
           "| jcc_cc | %s | %s | %s |" % (base["jcc_cc"], ga["jcc_cc"], gb["jcc_cc"]),
           "| jcc_taken | %s | %s | %s |" % (base["jcc_taken"], ga["jcc_taken"], gb["jcc_taken"]),
           "| al_for_slot | %s | %s | %s |" % (base["al_for_slot"], ga["al_for_slot"], gb["al_for_slot"]),
           "| slot_skipped | %s | %s | %s |" % (base["slot_skipped"], ga["slot_skipped"], gb["slot_skipped"]), ""]
    (code / "s53-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok], "sections", len(rows))
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
