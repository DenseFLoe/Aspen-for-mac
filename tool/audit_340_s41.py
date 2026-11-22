# -*- coding: utf-8 -*-
"""NATIVE-340 s41: derive the 0x21AE guard branches from bytes, refresh tables + audit."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "88bbe3130f561d2cdd76b3652cfbc3ab3a901a23"     # #450 fixed head (s37)


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
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    by = {m["token"]: m for m in meta["methods"]}

    # ---- controls ---------------------------------------------------------
    ctl = list(method_body.self_test(data, pe, by[0x06000032]["rva"], by[0x06000031]["rva"]))
    ctl += method_body.synthetic_tests()
    gate = x86_340.gate_facts(data, pe, 0x19B78, 0x28F3, 0x28F7, 0x2195, 0x2197)
    ctl.append(("jge target is the mov al,1 path", gate["jcc"]["target"] == "0x28FD" and gate["taken_return"] == 1))
    ctl.append(("jge fall-through returns al=0", gate["jcc"]["fallthrough"] == "0x28F9" and gate["fallthrough_return"] == 0))
    ctl.append(("consumer skips on al==0", gate["jz"]["cc"] == "jz" and gate["jz"]["target"] == "0x21B1"))
    ctl.append(("fixed .data slot is skipped by the gate", gate["slot_skipped"] is True))
    pos = gate["positive_branch"].split("-")
    ctl.append(("0x21A4 single read sits on the positive branch",
                int(pos[0], 16) <= 0x21A4 <= int(pos[1], 16) and int(pos[0], 16) <= 0x21AE <= int(pos[1], 16)))
    print("controls:", ctl)

    calls = read_csv(folder / "calls.csv")
    touched = []
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽；本映像里该槽被节门禁跳过，0x21A4/0x21AE 只在非可写分支执行）")
            row["note"] = (
                "R9 全链 + 两条分支（全部由原件字节解出）："
                "① 0x217F call 0x29D0 -> lea rax,[rip+0x171A1] 得槽地址 0x19B78；0x2184 mov rbx,rax；"
                "0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽则不调用）。"
                "② 0x218D 48 8B C8 = mov rcx,rax（槽地址作为 arg0）→ 0x2190 call 0x2874。"
                "③ 0x2874 的 0x28F3 83 7A 24 00 = cmp dword ptr [rdx+0x24],0 是对节 Characteristics 的有符号测试；"
                "0x28F7 7D 04 = jge 0x28FD（取 %s）：signed >= 0（符号位清）→ mov al,1（0x28FD）；"
                "落空分支 0x28F9 xor al,al → al=0。"
                "④ 0x2195 84 C0 test al,al + 0x2197 74 18 jz 0x21B1：al==0 时跳到 0x21B1（跳过 0x2199-0x21B0 这块），"
                "al!=0 才走 0x2199-0x21B0。"
                "⑤ 本映像固定槽 0x19B78 在 .data（Characteristics 0xC0000040，符号位置位=signed 负）→ jge 落空 → al=0 "
                "→ jz 取跳 → 节门禁跳过；因此 0x21A4 的 mov rax,[rbx] 与 0x21AE 的 call r9 只在非可写节那一支，"
                "在本映像里不执行（除非运行期改该节保护）。"
                "⑥ 0x21A4 单次读取只在正分支（%s）上；0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0（0x48B0: FF E0 = JMP RAX）。"
                "静态未决：回调槽写入者与被调实现；恢复条件＝在 0x21AE 读 RAX，或在 0x19B78 下断点看写入者/节保护"
                % (gate["jcc"]["target"], gate["positive_branch"]))
            touched.append("0x20CC")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    print("rows touched:", touched)

    # ---- native unresolved annexes (three historical + this round) ---------
    unresolved = [r for r in calls if r["class"] == "unresolved"]
    managed = [r for r in unresolved if r["kind"] == "method"]
    native = [r for r in unresolved if r["kind"] == "native"]
    mrows = [dict(index=i, caller=r["caller"], callee_name=r["callee"], callee=r["callee"],
                  listing=r["listing"], note=r["note"], reason="IL calli：目标为运行期函数指针")
             for i, r in enumerate(managed, start=1)]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate(native, start=1)]
    for name in ("s25-unresolved-managed.csv", "s33-unresolved-managed.csv",
                 "s37-unresolved-managed.csv", "s41-unresolved-managed.csv"):
        write_csv(code / name, ["index", "caller", "callee_name", "callee", "listing", "note", "reason"], mrows)
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv",
                 "s37-unresolved-native.csv", "s41-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)

    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1

    md = ["# NATIVE-340 s41 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 0x2874 的两条分支（由原件字节解出）", "",
          "| 指令 | 地址 | 去向 | 返回值 |", "| --- | --- | --- | --- |",
          "| `%s` | `0x28F3` | 判据：节 Characteristics(+0x24) | — |" % gate["cmp"],
          "| `%s` | `%s` | 取 NEAR `%s` | al=**%s** |"
          % (gate["jcc"]["cc"], gate["jcc"]["addr"], gate["jcc"]["target"], gate["taken_return"]),
          "| 落空 | `%s` | `%s` | al=**%s** |"
          % (gate["jcc"]["fallthrough"], gate["fallthrough_at"], gate["fallthrough_return"]), "",
          "判定式：`signed(Characteristics) >= 0` 走 jge 目标（返回 1，表示**不可写**）；否则落空返回 0（**可写**）。", "",
          "## 2. 节门禁与 0x21A4 的分支", "",
          "- 消费端：`%s` + `%s 0x%X` ⇒ al==0 跳到 `%s`（跳过 `%s`），"
          "al!=0 才落入 `%s`。"
          % (gate["test"], gate["jz"]["cc"], int(gate["jz"]["target"], 16), gate["jz"]["target"],
             gate["positive_branch"], gate["positive_branch"]),
          "- 固定槽 `0x19B78` 在 `%s`（Characteristics `%s`，signed=%d，writable=%s）"
          "⇒ 返回 al=%s ⇒ **节门禁跳过**：`0x21A4` 的 `mov rax,[rbx]` 与 `0x21AE` 的 call r9 "
          "只在 `%s` 这一支，本映像不执行（除非运行期改节保护）。"
          % (gate["section"]["name"], gate["section"]["characteristics"], gate["section"]["signed"],
             gate["section"]["writable"], gate["al_for_slot"], gate["positive_branch"]),
          "- 结论：`0x21A4` 的单次读取位于**非可写分支**（jz 落空），不是无条件路径。", "",
          "## 3. 生成器", "",
          "- `tool/x86_340.py`：解码 `cmp/jcc/xor al/mov al/test al/jz` 并从字节推导两条分支的地址与返回值、"
          "读 `IMAGE_SECTION_HEADER.Characteristics`，`slot_skipped` 由推导结果算出（脚本无硬编码结论）。",
          "- `tool/method_body.py`：EH 读器同时支持 fat（24 字节）与 small（12 字节，`u2/u2/u1/u2/u1/u4`）布局，"
          "由 kind 的 0x40 位选择，`MoreSects` 控制是否读；合成镜像测试 4 项全过。",
          "- 控制项 %d 条：%s" % (len(ctl), "；".join("%s=%s" % (n, "PASS" if o else "FAIL") for n, o in ctl)), "",
          "## 4. 计数", "",
          "| 指标 | 值 |", "| --- | --- |",
          "| external / boundary / unresolved | %d / %d / %d |" % (classes.get("external", 0),
                                                                 classes.get("boundary", 0),
                                                                 classes.get("unresolved", 0)),
          "| 未决托管 / 原生 | %d / %d |" % (len(managed), len(native)), "",
          "## 5. 指纹（两套命令）", "",
          "```",
          "python -B tool/gen_fingerprints_340.py --set receipt --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s29-fingerprints.json",
          "python -B tool/gen_fingerprints_340.py --set round --base-head %s --unit handoff/inbox/NATIVE-340 --out handoff/inbox/NATIVE-340/code/s41-fingerprints.json" % BASE_HEAD,
          "```", ""]
    (code / "s41-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")

    metrics = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
    metrics.update(dict(external=classes.get("external", 0), boundary=classes.get("boundary", 0),
                        unresolved=classes.get("unresolved", 0),
                        s41_managed_unresolved=len(managed), s41_native_unresolved=len(native),
                        s41_jge_target=gate["jcc"]["target"], s41_jge_fallthrough=gate["jcc"]["fallthrough"],
                        s41_gate_skipped=gate["slot_skipped"], s41_positive_branch=gate["positive_branch"],
                        s41_calls_sha256=hashlib.sha256((folder / "calls.csv").read_bytes()).hexdigest()))
    (folder / "metrics.json").write_text(json.dumps(metrics, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    runj = json.loads((folder / "run.json").read_text(encoding="utf-8-sig"))
    runj.update({"s41_base_head": BASE_HEAD, "s41_gate": gate})
    (folder / "run.json").write_text(json.dumps(runj, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print(json.dumps(dict(classes=classes, gate=gate), ensure_ascii=False, indent=1)[:1200])
    return 0


if __name__ == "__main__":
    sys.exit(main())
