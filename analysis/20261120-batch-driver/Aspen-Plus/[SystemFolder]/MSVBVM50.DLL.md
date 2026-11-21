# MSVBVM50.DLL

## 必填字段（T0 口径，逐项可按名检索）

- functions=N/A（native：未产出 native 函数统计，见 md 内 reason）
- decomp_ok=N/A（native：无函数级反编译统计）
- decomp_fail=N/A（native：无函数级反编译统计）


## 0. 摘要
- status=failed_analyze
- reason=ida_timeout 900s
- tool=IDA 9.5 + Hex-Rays
- prevtool=Ghidra 12.1.4
- sha256=4aef0066e8e4bad65018ec85d46b902303155ec2d8f049f3803e571005a90ff0
- size=1347344
- 原始终端行：
```
ITEM MSVBVM50.DLL status=failed_analyze reason=Timeout: idat.exe exceeded 900s
```
- 该件为 VB6 运行时（msvbvm/VB6 VM），IDA 9.5 在 900 s 内未完成自动分析，建议单独离线分析。
- 偏离仓库 AGENTS：本件仅记录失败与原始原因，未伪造反汇编/伪 C 正文。

## 1. 缺口与待验证
- 全函数反汇编与伪 C 未产出〔待验证：需单件离线分析或更大超时〕
- decompile 语义未复核〔无法判定〕

## dumps

dumps: 无（本轮未产出 dump（未分析项，见 md 内 status 与原因））
