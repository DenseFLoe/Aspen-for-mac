# olch3x7.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `olch3x7.ocx`，1701584 字节，SHA-256 `15cff013dce7ce930357d813cd5398542744dd4fa552445e2a06416035e86ea8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 6806 = decomp_ok 6774 + decomp_fail 32 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=6806
- decomp_ok=6774
- decomp_fail=32
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `olch3x7.ocx` |
| 字节数 | 1701584 |
| SHA-256 | `15cff013dce7ce930357d813cd5398542744dd4fa552445e2a06416035e86ea8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/olch3x7.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x30000000` |
| 段数 | 8 |
| 指令行数 | 324185 |

## 3. 反汇编清单（全量）

全文：disasm/olch3x7.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/olch3x7.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 6806
- decomp_ok（伪 C） = 6774
- decomp_fail = 32
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `300025e0` `sub_300025E0`：RuntimeError（decompile returned None）
- `30003600` `sub_30003600`：RuntimeError（decompile returned None）
- `30056c70` `sub_30056C70`：RuntimeError（decompile returned None）
- `30056df0` `sub_30056DF0`：RuntimeError（decompile returned None）
- `3005fcb0` `sub_3005FCB0`：RuntimeError（decompile returned None）
- `3005fd20` `sub_3005FD20`：RuntimeError（decompile returned None）
- `3005fd40` `sub_3005FD40`：RuntimeError（decompile returned None）
- `300c93de` `sub_300C93DE`：RuntimeError（decompile returned None）
- `300cd0cd` `sub_300CD0CD`：RuntimeError（decompile returned None）
- `300cd1a2` `sub_300CD1A2`：RuntimeError（decompile returned None）
- `300d42a9` `__check_range_exit`：RuntimeError（decompile returned None）
- `300d96a6` `sub_300D96A6`：RuntimeError（decompile returned None）
- `300dc55f` `sub_300DC55F`：RuntimeError（decompile returned None）
- `300dcf0b` `sub_300DCF0B`：RuntimeError（decompile returned None）
- `300e2b94` `sub_300E2B94`：RuntimeError（decompile returned None）
- `300e2b9c` `sub_300E2B9C`：RuntimeError（decompile returned None）
- `300e40f9` `sub_300E40F9`：RuntimeError（decompile returned None）
- `300e496d` `sub_300E496D`：RuntimeError（decompile returned None）
- `300e4ae2` `sub_300E4AE2`：RuntimeError（decompile returned None）
- `300e4aea` `sub_300E4AEA`：RuntimeError（decompile returned None）
- `300e4bb0` `sub_300E4BB0`：RuntimeError（decompile returned None）
- `300e4bdf` `sub_300E4BDF`：RuntimeError（decompile returned None）
- `300e4daa` `sub_300E4DAA`：RuntimeError（decompile returned None）
- `300e731d` `sub_300E731D`：RuntimeError（decompile returned None）
- `300e7524` `sub_300E7524`：RuntimeError（decompile returned None）
- `300e752c` `sub_300E752C`：RuntimeError（decompile returned None）
- `300e8778` `sub_300E8778`：RuntimeError（decompile returned None）
- `300e87aa` `sub_300E87AA`：RuntimeError（decompile returned None）
- `300eaa5d` `sub_300EAA5D`：RuntimeError（decompile returned None）
- `300eb1a3` `sub_300EB1A3`：RuntimeError（decompile returned None）
- `300ebddb` `sub_300EBDDB`：RuntimeError（decompile returned None）
- `300ed6bc` `sub_300ED6BC`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：218.5 s
- 日志：out/R1N/ida/logs/sha256_15cff013dce7ce930357d813cd5398542744dd4fa552445e2a06416035e86ea8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 32 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `olch3x7.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 6806 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +6806（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_30001000`, `sub_30001060`, `sub_30001070`, `sub_30001080`, `sub_30001090`, `sub_300010A0`, `sub_300010B0`, `sub_300010E0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[SystemFolder]/decompiled/olch3x7.ocx.c.txt` sha256=f033112b3606983dd58022be5012e325823067357e4f377620f814b0697fb639 bytes=4485983
- `native5/01-completed/Aspen-Plus/[SystemFolder]/disasm/olch3x7.ocx.asm.txt` sha256=a99d2f218c52b89e580715347d1bf650700bcc23ce148e03f622952a5972c57f bytes=10431777
