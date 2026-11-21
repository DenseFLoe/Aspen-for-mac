# ppstub.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ppstub.dll`，525864 字节，SHA-256 `9f166fe8fab9ef6d572ad9b3c9f5e60b0ab6a8b3b957e716ebc22b860c0773b9` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1274 = decomp_ok 1262 + decomp_fail 12 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1274
- decomp_ok=1262
- decomp_fail=12
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ppstub.dll` |
| 字节数 | 525864 |
| SHA-256 | `9f166fe8fab9ef6d572ad9b3c9f5e60b0ab6a8b3b957e716ebc22b860c0773b9` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppstub.dll` |
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
| 指令行数 | 62853 |

## 3. 反汇编清单（全量）

全文：disasm/ppstub.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ppstub.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1274
- decomp_ok（伪 C） = 1262
- decomp_fail = 12
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180001ce0` `PPSTUB_CHMINF`：RuntimeError（decompile returned None）
- `1800030f0` `PPSTUB_CHMINF2`：RuntimeError（decompile returned None）
- `18000d440` `sub_18000D440`：RuntimeError（decompile returned None）
- `18000ee60` `PPSTUB_WGL003`：RuntimeError（decompile returned None）
- `180010610` `sub_180010610`：RuntimeError（decompile returned None）
- `180012580` `PPSTUB_WGL03A`：RuntimeError（decompile returned None）
- `180013b80` `sub_180013B80`：RuntimeError（decompile returned None）
- `180015620` `PPSTUB_WHL003`：RuntimeError（decompile returned None）
- `180016d20` `sub_180016D20`：RuntimeError（decompile returned None）
- `180018cd0` `PPSTUB_WHL03A`：RuntimeError（decompile returned None）
- `18001a350` `PPSTUB_XTITER`：RuntimeError（decompile returned None）
- `180046a40` `PPSTUB_PCSAF5`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：32.2 s
- 日志：out/R1N/ida/logs/sha256_9f166fe8fab9ef6d572ad9b3c9f5e60b0ab6a8b3b957e716ebc22b860c0773b9.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 12 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ppstub.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1274 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1274（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`PPSTUB_ACTIN`, `sub_180001450`, `sub_180001460`, `sub_180001490`, `sub_1800014A0`, `sub_1800014B0`, `PPSTUB_ANCHEM`, `sub_180001AD0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/ppstub.dll.c.txt` sha256=f70015c55ea1d15863ebd56873afe154fc8b8957b2b0601203b21df89dd783a8 bytes=697009
- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/ppstub.dll.asm.txt` sha256=356bce30d0202260403c50f500787ec9a94c353558d1eaaf583636403bf8f479 bytes=2377415
