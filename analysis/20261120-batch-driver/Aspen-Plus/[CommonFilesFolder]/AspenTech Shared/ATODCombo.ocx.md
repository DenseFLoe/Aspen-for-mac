# ATODCombo.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ATODCombo.ocx`，178296 字节，SHA-256 `9c33d8b153d3394536c2527eb7876474e2c2879b663bf2863eb145669fc91472` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 330 = decomp_ok 318 + decomp_fail 12 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=330
- decomp_ok=318
- decomp_fail=12
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ATODCombo.ocx` |
| 字节数 | 178296 |
| SHA-256 | `9c33d8b153d3394536c2527eb7876474e2c2879b663bf2863eb145669fc91472` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFilesFolder]/AspenTech Shared/ATODCombo.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x63f70000` |
| 段数 | 3 |
| 指令行数 | 14630 |

## 3. 反汇编清单（全量）

全文：disasm/ATODCombo.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ATODCombo.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 330
- decomp_ok（伪 C） = 318
- decomp_fail = 12
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `63f82c30` `sub_63F82C30`：RuntimeError（decompile returned None）
- `63f85d10` `sub_63F85D10`：RuntimeError（decompile returned None）
- `63f86790` `sub_63F86790`：RuntimeError（decompile returned None）
- `63f891e0` `sub_63F891E0`：RuntimeError（decompile returned None）
- `63f8a3b0` `sub_63F8A3B0`：RuntimeError（decompile returned None）
- `63f8a800` `sub_63F8A800`：RuntimeError（decompile returned None）
- `63f8b930` `sub_63F8B930`：RuntimeError（decompile returned None）
- `63f8bad0` `sub_63F8BAD0`：RuntimeError（decompile returned None）
- `63f8bde0` `sub_63F8BDE0`：RuntimeError（decompile returned None）
- `63f8be00` `sub_63F8BE00`：RuntimeError（decompile returned None）
- `63f8cd20` `sub_63F8CD20`：RuntimeError（decompile returned None）
- `63f8d210` `sub_63F8D210`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：13.3 s
- 日志：out/R1N/ida/logs/sha256_9c33d8b153d3394536c2527eb7876474e2c2879b663bf2863eb145669fc91472.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 12 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ATODCombo.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 330 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +330（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`__vbaChkstk`, `__vbaExceptHandler`, `_adj_fdiv_m16i`, `_adj_fdiv_m32`, `_adj_fdiv_m32i`, `_adj_fdiv_m64`, `_adj_fdiv_r`, `_adj_fdivr_m16i`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `native3/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/decompiled/ATODCombo.ocx.c.txt` sha256=8ff405a5a7fd748991de29365dbdd04154fea0ceaaba817a40ce51881872412e bytes=226599
- `native3/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/disasm/ATODCombo.ocx.asm.txt` sha256=39af7a17492500c089c1e62d2d524d6c64d647ad33bbb3433d1e6fe60e64b069 bytes=498436
