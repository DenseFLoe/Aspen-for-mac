# -*- coding: utf-8 -*-
"""NATIVE-340 s45: adversarial injection proof + expanded EH controls + fingerprint rules."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import gate_evidence_340 as GE  # noqa: E402

BASE_HEAD = "106eb83d05ac50c9e14e7eb079014857a9117ab3"     # #450 head after s41


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    ap.add_argument("--expect-skip", default="", help="deliberate expectation for the fail-path demo")
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    by = {m["token"]: m for m in md_reader.parse(data, md_off)["methods"]}

    ctl = []
    ctl += method_body.synthetic_tests()
    ctl += method_body.self_test(data, pe, by[0x06000032]["rva"], by[0x06000031]["rva"])

    base = GE.table(data, pe)
    d_cc = GE.inject(data, cc="jl")
    pe_cc = PE(d_cc)
    inj_cc = GE.table(d_cc, pe_cc)
    d_al = GE.inject(data, al_imm=2)
    pe_al = PE(d_al)
    inj_al = GE.table(d_al, pe_al)

    # ① the table follows the decoded opcode/operands, not a remembered conclusion
    ctl.append(("baseline cc decoded from bytes", base["jcc_cc"] == "jge" and base["jcc_opcode"] == "0x7D"))
    ctl.append(("baseline cmp operand decoded", base["cmp_operand"] == "dword ptr [rdx+0x24]" and base["cmp_imm"] == "0x0"))
    ctl.append(("baseline: jge not taken on negative Characteristics -> al=0 -> skipped",
                base["slot_skipped"] is True and base["al_for_slot"] == 0))
    # ② injection 1: jge -> jl with the same fixed negative Characteristics
    ctl.append(("inject jge->jl changes the condition code", inj_cc["jcc_cc"] == "jl"))
    ctl.append(("inject jge->jl flips to taken", inj_cc["condition"].endswith("taken=True")
                and base["condition"].endswith("taken=False")))
    ctl.append(("inject jge->jl yields al=1", inj_cc["al_for_slot"] == 1))
    ctl.append(("inject jge->jl makes the consumer not skip", inj_cc["slot_skipped"] is False))
    # ③ injection 2: the AL immediate 1 -> 2 must show up in the table
    ctl.append(("inject al imm 1->2 changes the immediate", inj_al["al_immediates"].get("0x28FD") == 2))
    ctl.append(("inject al imm keeps the branch structure", inj_al["jcc_target"] == base["jcc_target"]
                and inj_al["jcc_fallthrough"] == base["jcc_fallthrough"]))
    # ④ Characteristics vs page protection are separate fields
    ctl.append(("Characteristics and page protection are separate",
                "section_characteristics" in base and "page_protection" in base
                and "runtime" in base["page_protection"]
                and base["section_characteristics"] not in base["page_protection"]))

    if a.expect_skip:
        want = a.expect_skip == "1"
        if bool(base["slot_skipped"]) != want:
            print("CONTROL FAILED: slot_skipped=%s (expected %s)" % (base["slot_skipped"], want))
            print("FAILED ITEMS: [slot_skipped]")
            return 1

    failed = [n for n, ok in ctl if not ok]
    print("controls:", ctl)
    if failed:
        for n in failed:
            print("FAILED ITEM: %s" % n)
        return 1

    # ---- injection table --------------------------------------------------
    fields = ["set", "jcc_opcode", "jcc_cc", "jcc_target", "jcc_fallthrough", "taken_al",
              "fallthrough_al", "cmp_operand", "cmp_imm", "condition", "al_immediates",
              "al_for_slot", "slot_skipped", "section_characteristics", "page_protection"]
    rows = []
    for name, t in (("baseline", base), ("inject_cc_jl", inj_cc), ("inject_al_imm_2", inj_al)):
        rows.append(dict(set=name, jcc_opcode=t["jcc_opcode"], jcc_cc=t["jcc_cc"],
                         jcc_target=t["jcc_target"], jcc_fallthrough=t["jcc_fallthrough"],
                         taken_al=t["taken_al"], fallthrough_al=t["fallthrough_al"],
                         cmp_operand=t["cmp_operand"], cmp_imm=t["cmp_imm"],
                         condition=t["condition"], al_immediates=json.dumps(t["al_immediates"], ensure_ascii=False),
                         al_for_slot=t["al_for_slot"], slot_skipped=t["slot_skipped"],
                         section_characteristics=t["section_characteristics"],
                         page_protection=t["page_protection"]))
    write_csv(code / "s45-injection.csv", fields, rows)

    # ---- main table: add the Characteristics vs page-protection distinction --
    calls = read_csv(folder / "calls.csv")
    touched = []
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["note"] = row["note"].rstrip("。") + (
                "。口径：此处判据是 PE 节头 Characteristics(+0x24) 的符号位（文件内属性），"
                "不等于进程内存页保护（PAGE_*，运行期由 VirtualProtect/VirtualQuery 决定）；"
                "本行只陈述文件属性与静态分支，不对运行期页保护下结论")
            touched.append("0x20CC")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)

    unresolved = [r for r in calls if r["class"] == "unresolved"]
    managed = [r for r in unresolved if r["kind"] == "method"]
    native = [r for r in unresolved if r["kind"] == "native"]
    mrows = [dict(index=i, caller=r["caller"], callee_name=r["callee"], callee=r["callee"],
                  listing=r["listing"], note=r["note"], reason="IL calli：目标为运行期函数指针")
             for i, r in enumerate(managed, start=1)]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate(native, start=1)]
    for name in ("s25", "s33", "s37", "s41", "s45"):
        write_csv(code / (name + "-unresolved-managed.csv"),
                  ["index", "caller", "callee_name", "callee", "listing", "note", "reason"], mrows)
        write_csv(code / (name + "-unresolved-native.csv"),
                  ["index", "caller", "callee", "listing", "note", "reason"], nrows)

    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1

    md = ["# NATIVE-340 s45 反例注入与 EH 扩展（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 反例注入（同一输入，改一个字节）", "",
          "| 注入 | 条件码 | 取跳 | 目标 | AL 立即数 | al_for_slot | 消费端跳过 |",
          "| --- | --- | --- | --- | --- | --- | --- |",
          "| 基线 | `%s` | %s | `%s` | `%s` | %s | **%s** |"
          % (base["jcc_cc"], base["condition"].split("taken=")[1], base["jcc_target"],
             json.dumps(base["al_immediates"]), base["al_for_slot"], base["slot_skipped"]),
          "| 条件码 jge→jl | `%s` | %s | `%s` | `%s` | %s | **%s** |"
          % (inj_cc["jcc_cc"], inj_cc["condition"].split("taken=")[1], inj_cc["jcc_target"],
             json.dumps(inj_cc["al_immediates"]), inj_cc["al_for_slot"], inj_cc["slot_skipped"]),
          "| 返回立即数 1→2 | `%s` | %s | `%s` | `%s` | %s | **%s** |"
          % (inj_al["jcc_cc"], inj_al["condition"].split("taken=")[1], inj_al["jcc_target"],
             json.dumps(inj_al["al_immediates"]), inj_al["al_for_slot"], inj_al["slot_skipped"]), "",
          "结论：条件码、比较操作数、两条分支的 AL 返回值都由字节解出；改 0x28F7 的 opcode 或 0x28FE 的立即数，"
          "证据表随之变化，说明生成器没有把结论写死。", "",
          "## 2. PE 节头 Characteristics ≠ 进程内存页保护", "",
          "- `Characteristics` = 文件内节属性（本件 `%s`，符号位置位）；判据读的是它。"
          % base["section_characteristics"],
          "- `页保护` = 运行期 `PAGE_*`（VirtualProtect/VirtualQuery），文件里没有编码；"
          "本条只对文件属性与静态分支下结论，不对运行期页保护下结论。", "",
          "## 3. EH 读器扩展（ECMA-335）", "",
          "- small（12B `u2/u2/u1/u2/u1/u4`）与 fat（24B）两种子句布局；more(0x80) 位可串联多个数据节，逐个读取；",
          "- 校验 try/handler 范围必须落在 IL 内，越界拒绝；",
          "- 遇到支持范围外的节类型，抛 `UnsupportedSection` 并报出具体 RVA/kind/size，该件停止判定。", "",
          "合成测试 9 项 + 真件 5 项 + 注入断言 10 项，共 %d 条控制：%s"
          % (len(ctl), "全部 PASS" if not failed else "失败 %s" % failed), "",
          "## 4. 计数", "",
          "| 指标 | 值 |", "| --- | --- |",
          "| external / boundary / unresolved | %d / %d / %d |" % (classes.get("external", 0),
                                                                 classes.get("boundary", 0),
                                                                 classes.get("unresolved", 0)),
          "| 未决托管 / 原生 | %d / %d |" % (len(managed), len(native)), ""]
    (code / "s45-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")

    metrics = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
    metrics.update(dict(s45_controls=len(ctl), s45_controls_failed=len(failed),
                        s45_inject_cc_target=inj_cc["jcc_target"], s45_inject_cc_skip=inj_cc["slot_skipped"],
                        s45_inject_al_imm=inj_al["al_immediates"].get("0x28FD"),
                        s45_calls_sha256=hashlib.sha256((folder / "calls.csv").read_bytes()).hexdigest()))
    (folder / "metrics.json").write_text(json.dumps(metrics, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    runj = json.loads((folder / "run.json").read_text(encoding="utf-8-sig"))
    runj.update({"s45_base_head": BASE_HEAD, "s45_injection": {
        "baseline": {k: base[k] for k in ("jcc_cc", "jcc_target", "al_for_slot", "slot_skipped")},
        "cc_jl": {k: inj_cc[k] for k in ("jcc_cc", "jcc_target", "al_for_slot", "slot_skipped")},
        "al_imm_2": {"al_immediates": inj_al["al_immediates"]}}})
    (folder / "run.json").write_text(json.dumps(runj, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("rows touched:", touched, "classes:", classes)
    return 0


if __name__ == "__main__":
    sys.exit(main())
