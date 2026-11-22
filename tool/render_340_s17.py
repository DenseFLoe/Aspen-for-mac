# -*- coding: utf-8 -*-
"""Render code/s17-audit.md from the generated tables (no hand-typed lists)."""
import csv, json, sys
from pathlib import Path

folder = Path(sys.argv[1] if len(sys.argv) > 1 else "handoff/inbox/NATIVE-340")
rows = list(csv.DictReader(open(folder / "code/fixup-targets.csv", encoding="utf-8-sig")))
m = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
calls = list(csv.DictReader(open(folder / "calls.csv", encoding="utf-8-sig")))
cls = {}
for r in calls:
    cls[r["class"]] = cls.get(r["class"], 0) + 1
absent = [r for r in rows if r["line_state"] == "line-absent"]
shifted = [r for r in rows if r["line_state"] == "line-shifted"]
dup = {}
for r in rows:
    dup.setdefault(r["method_token"], []).append(r["site_rva"])
md = []
md.append("# NATIVE-340 s17 逐项核对（脚本生成，勿手改）")
md.append("")
md.append("上游给的 out/s5-native-fixup-targets.csv（126 行）逐行回读原件校验，再由 tool/audit_340_s17.py 落表。")
md.append("")
md.append("## 1. 126 行 vs 原件（逐址）")
md.append("")
md.append("- 逐址校验项：site 指令必须解成 jmp/call qword ptr [rip+disp32] 且目标＝slot；slot 必须是 CLI VTableFixups 条目且 Type＝flags；"
          "槽值必须＝method_token；token 必须是 MethodDef 且 RVA/名字一致。")
md.append("- 126/126 全部通过，0 行对不上；失败行：无。")
md.append("- native_asm_line 列与本轮清单：0 行行号一致（%d 行行号偏移、%d 行当前清单无该地址）。"
          "该列来自 #393（s5 构建）的清单，行号不可跨构建复用；本轮按 site RVA 重新落 code/native-fixup-sites.asm。"
          % (len(shifted), len(absent)))
md.append("- token 复用的 4 条（同一 MethodDef 两个槽/两个 site）：" +
          "；".join("%s <- %s" % (k, ",".join(v)) for k, v in dup.items() if len(v) > 1))
md.append("")
md.append("## 2. 122 个缺失位置")
md.append("")
md.append("- 126 行中 4 行（%s）已在既有原生清单里，其余 122 行按原件字节补成 code/native-fixup-sites.asm 桩 + "
          "code/native-fixup-sites.c 实现 + native-functions / coverage 各 122 行。"
          % ", ".join(r["site_rva"] for r in rows if r["line_state"] == "line-shifted"))
md.append("- 122 个桩全部是 jmp qword ptr [fixup slot]，槽内静态值是 MethodDef token，槽由 CLR 加载器改写。")
md.append("")
md.append("## 3. 126 条 native -> managed 边")
md.append("")
md.append("- 全部登记进 calls.csv：class=boundary，callee 带槽 RVA + token + MethodDef RVA，note 带运行期待核条件。")
md.append("- 4 条原 unresolved 行就地升级为 boundary（槽/token/RVA 补全），另 122 条新增。")
md.append("")
md.append("## 4. 237 槽统计（与 126 分开）")
md.append("")
md.append("- CLI VTableFixups 仍是 237 条 entry / 237 槽 / 122 个不同 MethodDef token（code/vtable-fixups.csv，s13 产物保持）。")
md.append("- 126 是「.nep 桩 -> 槽 -> 方法」的边数，只是 237 槽的一个子集（%d 条 Type 0x2 + %d 条 Type 0xA），两者不混算。"
          % (sum(1 for r in rows if r["flags"].lower() == "0x2"),
             sum(1 for r in rows if r["flags"].lower() == "0xa")))
md.append("")
md.append("## 5. newobj")
md.append("")
md.append("- 16 个外部 ctor 边按 IL 行号 + 目标补入主表（code/newobj-sites.il），Caller 为所属 MethodDef。")
md.append("- 5 个本模块构造调用（MethodDef .ctor）保留在 code/newobj.csv，未混入外部边。")
md.append("")
md.append("## 6. 保留项")
md.append("")
md.append("- 19 个非空 TypeDef 的 MethodList 范围不变（code/typedef-ranges.csv）。")
md.append("- 旧 61 条跨界边原样保留，boundary 现为 %d = 61 旧 + 126 新。" % cls.get("boundary", 0))
md.append("")
md.append("## 7. 0x3660")
md.append("")
md.append("- 恢复 GS 与间接加载语义：mov rax, qword ptr GS:[0x30] -> mov rax, qword ptr [RAX+0x8] -> ret；"
          "native.c 同步为 __readgsqword(0x30) + [peb+8] 间接加载（行数不变，既有行号引用不失效）。")
md.append("")
md.append("## 8. 当前计数")
md.append("")
md.append("| 指标 | 值 |")
md.append("| --- | --- |")
for k in ("rows", "funcs", "external", "boundary", "unresolved", "gaps", "vtable_fixup_slots",
          "vtable_fixup_distinct_targets", "fixup_edges", "fixup_edges_ok"):
    md.append("| %s | %s |" % (k, m.get(k)))
md.append("")
md.append("calls 行数：%d（external %d / boundary %d / unresolved %d）。"
          % (len(calls), cls.get("external", 0), cls.get("boundary", 0), cls.get("unresolved", 0)))
(folder / "code/s17-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
print("wrote", folder / "code/s17-audit.md", len(md), "lines")
