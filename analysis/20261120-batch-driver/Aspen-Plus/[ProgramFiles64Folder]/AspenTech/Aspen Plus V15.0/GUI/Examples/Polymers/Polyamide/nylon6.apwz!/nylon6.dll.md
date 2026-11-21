# nylon6.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `nylon6.dll`，15360 字节，SHA-256 `6b190a0187713bc2e2620b2c2994d8e7248747c529ebca8f78c39e06b2ff60c6` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 63 = decomp_ok 63 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=63
- decomp_ok=63
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `nylon6.dll` |
| 字节数 | 15360 |
| SHA-256 | `6b190a0187713bc2e2620b2c2994d8e7248747c529ebca8f78c39e06b2ff60c6` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/nylon6.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry | 0x8664 / 5 / 0x288C |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x180000000` |
| 段数 | 5 |
| 指令行数 | 1990 |

## 3. 反汇编清单（全量）

全文：disasm/nylon6.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/nylon6.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 63
- decomp_ok（伪 C） = 63
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：IDAPython 导出脚本（本地保留，未随产物发布；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：2.0 s
- 日志：out/R1N/ida/logs/sha256_6b190a0187713bc2e2620b2c2994d8e7248747c529ebca8f78c39e06b2ff60c6.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `nylon6.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 63 |
| Ghidra 12.1.4 基线 FUNC | 63 |
| 差值 | +0（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：`FUN_180001058`, `FUN_180001191`, `FUN_180002550`, `FUN_1800025a0`, `FUN_1800026b4`, `dllmain_dispatch`, `dllmain_raw`, `entry`
- 仅 IDA 有：`sub_180001191`, `?dllmain_crt_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z`, `?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z`, `?dllmain_crt_process_detach@@YAH_N@Z`, `sub_180002740`, `?dllmain_raw@@YAHQEAUHINSTANCE__@@KQEAX@Z`, `DllEntryPoint`, `__xi_z`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: repo:analysis/20261120-batch-driver/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/（仓内产物，不在 Release 包）

- `Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/decompiled/nylon6.dll.c.txt` sha256=dc86b263989924d234888fda305475324f704d06334567af5f9404cf71a78fcd bytes=40966
- `Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polyamide/nylon6.apwz!/disasm/nylon6.dll.asm.txt` sha256=450c9504b6c297bbcc8479037a70fa5987632c5a4fb43db535a593d7f92cda5f bytes=73444
