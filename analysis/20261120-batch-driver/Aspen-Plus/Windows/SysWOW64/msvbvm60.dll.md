# msvbvm60.dll

## 必填字段（T0 口径，逐项可按名检索）

- functions=N/A（native：未产出 native 函数统计，见 md 内 reason）
- decomp_ok=N/A（native：无函数级反编译统计）
- decomp_fail=N/A（native：无函数级反编译统计）


## 0. 摘要
- status=failed_analyze
- reason=ida_timeout 900s
- tool=IDA 9.5 + Hex-Rays
- prevtool=Ghidra 12.1.4
- sha256=898288bd3b21d0e7d5f406df2e0b69a5bbfa4f241baf29a2cdf8a3cf4d4619f2
- size=1436032
- 原始终端行：
```
ITEM msvbvm60.dll status=failed_analyze reason=Timeout: idat.exe exceeded 900s
```
- 该件为 VB6 运行时（msvbvm/VB6 VM），IDA 9.5 在 900 s 内未完成自动分析，建议单独离线分析。
- 偏离仓库 AGENTS：本件仅记录失败与原始原因，未伪造反汇编/伪 C 正文。

## 1. 缺口与待验证
- 全函数反汇编与伪 C 未产出〔待验证：需单件离线分析或更大超时〕
- decompile 语义未复核〔无法判定〕

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[SystemFolder]/decompiled/msvbvm60.dll.c.txt` sha256=1c0dbd7525fb13a4dc9e63560926feaea3757df334866f2b5af4902b2170327b bytes=5560983
- `native5/01-completed/Aspen-Plus/[SystemFolder]/disasm/msvbvm60.dll.asm.txt` sha256=c4f91180fa4763f5eee8ad7926b6be365a6674688e28cb591ef1771c33e88bb5 bytes=9662881
