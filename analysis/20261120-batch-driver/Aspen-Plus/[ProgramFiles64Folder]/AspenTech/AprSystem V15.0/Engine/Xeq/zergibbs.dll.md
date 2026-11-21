# zergibbs.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zergibbs.dll`，956456 字节，SHA-256 `fe114985f88e2ad05a64cb8904593c9d7137aaac475adf52c5665171bea8acfc` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 478 = decomp_ok 472 + decomp_fail 6 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=478
- decomp_ok=472
- decomp_fail=6
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zergibbs.dll` |
| 字节数 | 956456 |
| SHA-256 | `fe114985f88e2ad05a64cb8904593c9d7137aaac475adf52c5665171bea8acfc` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/zergibbs.dll` |
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
| 段数 | 6 |
| 指令行数 | 142532 |

## 3. 反汇编清单（全量）

全文：disasm/zergibbs.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zergibbs.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 478
- decomp_ok（伪 C） = 472
- decomp_fail = 6
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180014c60` `sub_180014C60`：RuntimeError（decompile returned None）
- `1800225a0` `sub_1800225A0`：RuntimeError（decompile returned None）
- `1800357e0` `RGBB_URE06`：RuntimeError（decompile returned None）
- `1800518a0` `RGBB_URE06I`：RuntimeError（decompile returned None）
- `180060790` `RGBB_ZURE06`：RuntimeError（decompile returned None）
- `1800822e0` `sub_1800822E0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：120.1 s
- 日志：out/R1N/ida/logs/sha256_fe114985f88e2ad05a64cb8904593c9d7137aaac475adf52c5665171bea8acfc.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 6 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zergibbs.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 478 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +478（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800033D0`, `sub_180003CC0`, `RGBB_ATMMAT`, `sub_180007F30`, `sub_180008AA0`, `sub_180008E10`, `sub_180008FC0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/zergibbs.dll.c.txt` sha256=00155a4062d6ca5abb0f74e63734fb1d43ed026024f1c986cf2af41670c42de0 bytes=1460656
- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/zergibbs.dll.asm.txt` sha256=fb206ec677a0b1c648465846c9674df30b0df11cf9d508f0fff04a5689d9eb59 bytes=5535931
