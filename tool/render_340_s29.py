# -*- coding: utf-8 -*-
"""Render code/s29-audit.md and refresh code/s29-fingerprints.json from the artifacts."""
import hashlib, json, sys
from pathlib import Path

folder = Path(sys.argv[1] if len(sys.argv) > 1 else "handoff/inbox/NATIVE-340")
code = folder / "code"
v = json.loads((code / "s29-verdict-0x06000030.json").read_text(encoding="utf-8-sig"))
m = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
files = {}
for p in sorted(folder.rglob("*")):
    if p.is_file() and p.name != "s29-fingerprints.json":
        files[p.relative_to(folder).as_posix()] = hashlib.sha256(p.read_bytes()).hexdigest()
(code / "s29-fingerprints.json").write_text(json.dumps(files, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
b = v["parameter_binding"]
md = []
md.append("# NATIVE-340 s29 更正与核验（脚本生成）")
md.append("")
md.append("## 事实断言：%d 项，失败 %d 项" % (len(v["facts"]), len(v["problems"])))
md.append("")
for f in v["facts"]:
    md.append("- %s %s（%s）" % ("PASS" if f["ok"] else "FAIL", f["fact"], f["detail"]))
md.append("")
md.append("## CLSID / IID（按原件压栈次序）")
md.append("")
md.append("- 调用：%s" % b["call"])
md.append("- 次序：%s" % b["note"])
md.append("- arg0 clsid = %s，字段 %s（%s）@ %s，16 字节 %s"
          % (b["arg0_clsid"]["guid"], b["arg0_clsid"]["field"], b["arg0_clsid"]["field_name"],
             b["arg0_clsid"]["field_rva"], b["arg0_clsid"]["bytes_at_rva"]))
md.append("- arg1 riid = %s，字段 %s（%s）@ %s，16 字节 %s"
          % (b["arg1_riid"]["guid"], b["arg1_riid"]["field"], b["arg1_riid"]["field_name"],
             b["arg1_riid"]["field_rva"], b["arg1_riid"]["bytes_at_rva"]))
md.append("")
md.append("## R9 链")
md.append("")
md.append("- %s" % v["r9_chain"]["expression"])
md.append("- 槽 %s 由 %s 返回；空槽先拦：%s；单次读取：%s；守卫跳板：%s；未决原因：%s"
          % (v["r9_chain"]["slot_rva"], v["r9_chain"]["slot_holder"],
             " / ".join(v["r9_chain"]["null_guard"]), v["r9_chain"]["single_read"],
             v["r9_chain"]["guard_thunk"], v["r9_chain"]["unresolved_reason"]))
md.append("")
md.append("## 计数")
md.append("")
md.append("| 指标 | 值 |")
md.append("| --- | --- |")
for k in ("rows", "funcs", "external", "boundary", "unresolved", "managed_to_managed_ctor_edges",
          "slot_jumps_original", "distinct_methoddef_targets", "fixup_edges", "fixup_stubs_added"):
    if k in m:
        md.append("| %s | %s |" % (k, m[k]))
md.append("")
md.append("指纹：%d 个文件，code/s29-fingerprints.json。" % len(files))
(code / "s29-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
print("wrote s29-audit.md and %d fingerprints" % len(files))
