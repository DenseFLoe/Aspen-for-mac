# msvbvm60.dll

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

- `decompiled/URLMON.DLL.c.txt` sha256=e6d17a80dd5c5acbe2527a4823cd1cac25d829eeb1097c49f4fd4bec0f907aa6 bytes=7634758
- `decompiled/mfc42.dll.c.txt` sha256=0a08b5c9a2796574ab20698f69bc32b98c896f2d6559dfaa2983a47be6f09323 bytes=4759453
- `decompiled/msvcrt.dll.c.txt` sha256=9047c0b40ead8fa095a7dfd8feab8b386eb68d1b0cbbab803d64bf521637cd1f bytes=2718434
- `disasm/URLMON.DLL.asm.txt` sha256=239ec929819a5a34309db57f88a06b6b036bffbcc76ef12acaeda4b344e42a3f bytes=11515603
- `disasm/mfc42.dll.asm.txt` sha256=5c6c73ddc6b51143a5e06023dd2ea0a8c30a293b276655d31d941a85a31481e1 bytes=9045283
- `disasm/msvcrt.dll.asm.txt` sha256=fd34bf230ddce733b2af3f1d4d8edc71d1cad325d4a64e7de694d0c41409a312 bytes=5350275
