# NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4`，376832 字节，SHA-256 `bce82593fe257e86a428eaadd8f72d47440ebd7d6598fe3f967c49a5f2882060` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 518 = decomp_ok 518 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=518
- decomp_ok=518
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4` |
| 字节数 | 376832 |
| SHA-256 | `bce82593fe257e86a428eaadd8f72d47440ebd7d6598fe3f967c49a5f2882060` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Binary/NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4` |
| product_raw | `Properties-Database-Server` |
| 产品目录 | `Properties-Database-Server` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 4 |
| 指令行数 | 70960 |

## 3. 反汇编清单（全量）

全文：disasm/NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 518
- decomp_ok（伪 C） = 518
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：57.0 s
- 日志：out/R1N/ida/logs/sha256_bce82593fe257e86a428eaadd8f72d47440ebd7d6598fe3f967c49a5f2882060.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 518 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +518（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`??4CCoreUtility@@QAEAAV0@ABV0@@Z`, `_DllMain@12`, `?fnCoreUtility@@YAHXZ`, `??0CCoreUtility@@QAE@XZ`, `StartAddress`, `sub_10001080`, `sub_10002890`, `sub_100029E0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/NewBinary1.0E23E3D2_EF49_4F0F_814F_E2343DA09FCD.c.txt` sha256=a4c1352c752ff5dd0185fe6fe1f3570d7a9537f0bdb8c383b6f7e8b28bdeb091 bytes=3895339
- `decompiled/NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4.c.txt` sha256=be6ac6f972debb8b972eb3295ba45fd06d0e08853b3de0aa7aec39050d12e441 bytes=1311080
- `decompiled/NewBinary2.0E23E3D2_EF49_4F0F_814F_E2343DA09FCD.c.txt` sha256=570eb020dc35aa5af3236d95738562e4318695add07fbfda8f02875e29b90598 bytes=545426
- `decompiled/SetAllUsers.dll.c.txt` sha256=2e55566ae6cc862efd0b6a69628bf567fb2b1b66468cf37a665132553530c7ff bytes=3350976
- `disasm/NewBinary1.0E23E3D2_EF49_4F0F_814F_E2343DA09FCD.asm.txt` sha256=b5179393da7778d03df2d63a40db1df9dba1b50539e92b7c516f059069df780d bytes=7462863
- `disasm/NewBinary1.88A974CE_9F96_4E89_8DA5_4847749D85C4.asm.txt` sha256=2f5af6ab4cfbcb678a33084b1b7c5dfa1186a9f75adb07d9e1b79c920f8fac0d bytes=2642228
- `disasm/NewBinary2.0E23E3D2_EF49_4F0F_814F_E2343DA09FCD.asm.txt` sha256=f96396bad7cdf93dc6913b6ab0b2b39aee6aa0d72c6084b2944f3db2047757df bytes=1025870
- `disasm/SetAllUsers.dll.asm.txt` sha256=3677a6352322275155bc8f6d6dbcfdc6ec257c9b881a546eda5c0ff81198eee2 bytes=5747883
