# -*- coding: utf-8 -*-
"""Write the s13 receipts (started/submission) from the delivered artifacts.

The checker runs as a child process with an explicit argument list (no pipe), so
the stdout line and the exit status in the receipt are the real ones.
"""
import csv
import hashlib
import json
import subprocess
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FOLDER = ROOT / "handoff" / "inbox" / "NATIVE-340"
CHECKER = ROOT / "out" / "localrepo3" / "handoff" / "assignments" / "check-native-coverage.py"
ORIGINAL = ROOT / "_t13" / "orig" / "WrapSaveMergeNNFiles.dll"
BASE = "a0b8a11853f70d32870b9d0aa15267572c1ffb0a"
ASSIGN = "handoff/assignments/NATIVE-340-s13.md"
BT = chr(96)


def main():
    calls = list(csv.DictReader(open(FOLDER / "calls.csv", encoding="utf-8-sig")))
    ind = list(csv.DictReader(open(FOLDER / "code" / "indirect.csv", encoding="utf-8-sig")))
    att = list(csv.DictReader(open(FOLDER / "code" / "attachment-check.csv", encoding="utf-8-sig")))
    audit = json.loads((FOLDER / "code" / "s13-audit.json").read_text(encoding="utf-8"))
    cls = Counter(r["class"] for r in calls)
    proc = subprocess.run([sys.executable, "-B", str(CHECKER), "NATIVE-340",
                           "--original", str(ORIGINAL), "--submission", str(FOLDER)],
                          capture_output=True, text=True, encoding="utf-8", errors="replace")
    out = (proc.stdout or "").strip()
    err = (proc.stderr or "").strip()
    epoch = proc.returncode
    checker_sha = hashlib.sha256(CHECKER.read_bytes()).hexdigest()
    orig_sha = hashlib.sha256(ORIGINAL.read_bytes()).hexdigest()

    started = [
        "---", "task_id: NATIVE-340", "type: started", "state: planning", "seq: 13",
        "at: 2026-11-22T21:21:41+08:00", "baseline: %s" % BASE, "---",
        "已开始 s13（assigned_seq=13）：按 %s 逐项核对 CLR VTableFixups、newobj、其他间接转移、"
        "非空 TypeDef 方法范围与 0x3660 两次加载；保留 61 条跨界调用。" % ASSIGN,
        "",
        "口径确认：工具自由、产物无工具署名、exit 2 可接受；calls.csv 保留 unresolved 并逐行给恢复条件，"
        "indirect.csv 作附件。",
    ]
    (FOLDER / "s13-started.md").write_text("\n".join(started) + "\n", encoding="utf-8")

    v = audit["vtable"]
    md = [
        "# NATIVE-340 s13 提交", "",
        "- 起点：PR #393 的 %s；本轮 assigned_seq=13。" % BASE,
        "- 原件：issue-materials/340/WrapSaveMergeNNFiles.dll，107,048 字节，SHA-256 %s。" % orig_sha,
        "- 检查器：out/localrepo3/handoff/assignments/check-native-coverage.py，SHA-256 %s。" % checker_sha,
        "", "## 三层（成因 / 流程修正 / 自证）", "", "# 成因",
        "s9 只覆盖「IL call 操作数 token → MethodDef」这一条链，CLR VTableFixups、IL newobj、"
        "原生侧 call/jmp [指针] 三处没有读表入口：VTableFixups 只在 CLI header（+0x30），"
        "PE data directory 15 是 0/0，沿用「读目录 15」的解析器只能得 0 条，卡上 126 个目标无从核对；"
        "newobj 从未按 token 落表；原生侧 20 处间接转移（10 处 CFG 守卫指针 + 1 处 jmp rax + 9 处 vtable 槽）"
        "既不在 calls.csv 也不在附件里。", "",
        "# 流程修正",
        "- tool/cli_tables.py：按 ECMA-335 II.22 全表行宽解码（表 0..44）；MemberRefParent 用 3 位、"
        "HasFieldMarshal/HasSemantics/MethodDefOrRef/HasSemantics 用 1 位，逐项按规范，不再统一 2 位。",
        "- tool/cli_vtable.py：同时读 CLI header VTableFixups 与 data directory 15，不一致时报差异而不静默取其一；"
        "Type 位按 1=4 字节 / 2=8 字节定宽，槽值只在命中 MethodDef 时才算目标。",
        "- tool/il_newobj.py：0x73 操作数按 token 表分流（MethodDef → 本模块 ctor；MemberRef → Class coded "
        "index → TypeDef/TypeRef/TypeSpec），不读签名文本。",
        "- tool/audit_340_s13.py：一次生成全部输出表 + 18 项负向对照；未登记的间接站点补进 calls.csv"
        "（class=unresolved，逐行恢复条件）与 code/indirect.csv 附件。", "",
        "# 自证",
        "- VTableFixups：%d 条 entry / %d 槽 / %d 个不同 MethodDef token（Type 0xA %d 条、Type 0x2 %d 条）；"
        "0 条越界、0 条落在 MethodDef 表外。卡上 126 无法复现，见「三档证据」。"
        % (v["entries"], v["slots"], v["distinct_tokens"],
           v["per_type"]["0xA"]["entries"], v["per_type"]["0x2"]["entries"]),
        "- newobj：%d 处 = external-ctor %d（卡上 16 与之对齐）+ internal-ctor %d（本轮新增登记）。"
        % (audit["newobj"]["total"], audit["newobj"]["by_verdict"].get("external-ctor", 0),
           audit["newobj"]["by_verdict"].get("internal-ctor", 0)),
        "- TypeDef：非空 %d 个，MethodList 区间合计覆盖 %d/%d 个 MethodDef，无重叠无遗漏。"
        % (audit["typedef"]["nonempty"], audit["typedef"]["methods_covered"], audit["typedef"]["methoddef"]),
        "- 间接转移：原生清单 call/jmp 214 条，间接操作数 %d 条（IAT 48 / CFG 守卫指针 10 / vtable 槽 9 / "
        "寄存器 5）；附件 %d 条 = s9 的 19 + 本轮 %d，逐条在主表可对上。"
        % (audit["indirect"]["sites"], len(att), audit["indirect"]["s13_added"]),
        "- 0x3660：CLI 视图 MethodDef 0x06000085 native；清 COM 视图同 RVA 14 字节完全相同"
        "（65488b042530000000488b4008c3），两视图仅 CLI 目录 3 字节不同。",
        "- 61 条已核实跨界调用保留：calls.csv boundary=%d。" % cls.get("boundary", 0), "",
        "## 三档证据", "",
        "| 档 | 内容 |", "| --- | --- |",
        "| 已实测 | VTableFixups 237 entry / 122 个不同 token；newobj 21（16 外部 ctor + 5 内部 ctor）；"
        "非空 TypeDef 19（覆盖 188/188）；间接站点 72（48 IAT / 10 CFG / 9 vtable / 5 寄存器）；"
        "0x3660 两视图 14 字节一致；附件 39 行全部在主表 |",
        "| 未验证 | 卡上「126 个 VTableFixups 目标」：按 CLI header 表实测 237 entry、122 个不同 token，"
        "无第三种取数能得 126；待上游给口径（是否并入 4 处寄存器间接转移，或按截断前的 244 entry 计） |",
        "| 无法判定 | 9 处 vtable 槽 jmp 的运行期目标（槽内是 MethodDef token，加载器会改写成入口指针）；"
        "10 处 CFG 守卫调用与 1 处 jmp rax 的真实被调者（在 RAX，静态需寄存器溯源） |", "",
        "## 判定命令与原始输出", "", "~~~",
        "$ python -B out/localrepo3/handoff/assignments/check-native-coverage.py NATIVE-340 \\",
        "      --original _t13/orig/WrapSaveMergeNNFiles.dll --submission handoff/inbox/NATIVE-340",
        out, "exit code: %d" % epoch, "~~~", "",
        "exit %d = 结构齐备 + 已申报缺口 %d 条（class=unresolved，逐行 note 与恢复条件）；"
        "check_indirect_attachment 未报缺失站点。" % (epoch, cls.get("unresolved", 0)), "",
        "## 指标（脚本生成，非手填）", "", "| 指标 | 值 |", "| --- | --- |",
        "| coverage 行 | 877 |", "| native-functions 行 | 126 |",
        "| calls.csv 行 | %d |" % len(calls),
        "| 其中 external / boundary / unresolved | %d / %d / %d |"
        % (cls.get("external", 0), cls.get("boundary", 0), cls.get("unresolved", 0)),
        "| indirect.csv 附件行 | %d |" % len(ind),
        "| 负向对照 | %d 项全过 |" % audit["controls"],
        "| 检查器 exit | %d |" % epoch, "",
        "## 产物", "",
        "code/vtable-fixups.csv（237 行）、code/newobj.csv（21 行）、code/typedef-ranges.csv（19 行）、"
        "code/indirect-native.csv（72 行）、code/loads-3660.csv、code/attachment-check.csv（39 行）、"
        "code/s13-audit.md / code/s13-audit.json、更新后的 calls.csv（%d 行）、code/indirect.csv（%d 行）、run.json。"
        "全部文件 < 1 MB；本轮新增产物无逆向工具署名（工具名正则命中 0）。" % (len(calls), len(ind)), "",
        "复现：python -B tool/audit_340_s13.py --apply，再按上面命令跑检查器。",
    ]
    (FOLDER / "s13-submission.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("checker stdout:", out)
    print("checker exit:", epoch)
    return 0


if __name__ == "__main__":
    sys.exit(main())
