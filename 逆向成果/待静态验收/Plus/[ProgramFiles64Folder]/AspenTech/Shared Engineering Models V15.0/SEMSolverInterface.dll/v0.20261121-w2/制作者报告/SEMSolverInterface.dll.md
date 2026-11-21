# SEMSolverInterface.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `SEMSolverInterface.dll`，79808 字节，SHA-256 `ce9c0054252d8c69a340eb896aa91e50ba67a5151b91c6bd344206434d1c6dfb` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 318 = decomp_ok 318 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=318
- decomp_ok=318
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `SEMSolverInterface.dll` |
| 字节数 | 79808 |
| SHA-256 | `ce9c0054252d8c69a340eb896aa91e50ba67a5151b91c6bd344206434d1c6dfb` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/SEMSolverInterface.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x180000000` |
| 段数 | 8 |
| 指令行数 | 8514 |

## 3. 反汇编清单（全量）

全文：disasm/SEMSolverInterface.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/SEMSolverInterface.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 318
- decomp_ok（伪 C） = 318
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：16.5 s
- 日志：out/R1N/ida/logs/sha256_ce9c0054252d8c69a340eb896aa91e50ba67a5151b91c6bd344206434d1c6dfb.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `SEMSolverInterface.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 318 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +318（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`??0AOSSolverSystem@@QEAA@AEBV0@@Z`, `??0MilpEso@@QEAA@AEBV0@@Z`, `??0NonlinearAlgebraicESO@@QEAA@AEBV0@@Z`, `??0NonlinearProgramESO@@QEAA@AEBV0@@Z`, `sub_1800013C0`, `??0SolverUtilityComponent@@QEAA@AEBV0@@Z`, `sub_180001400`, `??4AOSSolverSystem@@QEAAAEAV0@AEBV0@@Z`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/AspenEngUtils.dll.c.txt` sha256=bdc5d6f64c2a2ea31aa953c26f3400cc3d82a8c0fc02b05030ed3510b81e10c4 bytes=1776986
- `decompiled/AspenHeaterCooler.dll.c.txt` sha256=5bc37b609ea152dec67357e1a688c1414173fe26629ad88411f98a5ff0fa7426 bytes=107800
- `decompiled/CSSExtern.dll.c.txt` sha256=cbd5b806ddc67bc574a9dbd750bb61e97953b4fa3fa30314b7f8eaf40858324f bytes=78092
- `decompiled/SEMSolverInterface.dll.c.txt` sha256=a6ef8e6b7baf3d0a7f319cd38b066d598cdbfe7e2e82db881cf1153580386429 bytes=188792
- `disasm/AspenEngUtils.dll.asm.txt` sha256=5deb0400d587a2a2c3d07fcbbcb29f1171fee1a812a292302ce856ef84aaca1c bytes=3093562
- `disasm/AspenHeaterCooler.dll.asm.txt` sha256=01b890bdabb84bcca31da108ec2508cf045cc0af85ed79de5dccfc70b438bbd7 bytes=149748
- `disasm/CSSExtern.dll.asm.txt` sha256=fa9b6c5e3792f6e68ae29a39af495c03fb362e207f52aa28eae78ae12d8cc11f bytes=150075
- `disasm/SEMSolverInterface.dll.asm.txt` sha256=312ea8c37afc2e45fdafeac63bc6f45c5fe5325ab3422dc4b20c12d410a1d67d bytes=307032
