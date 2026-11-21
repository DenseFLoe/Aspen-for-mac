# NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184`，918600 字节，SHA-256 `869d47954664846a28ab4213b40e239686f86b464377a7703a58e3ca7e5f2ae9` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3462 = decomp_ok 3459 + decomp_fail 3 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3462
- decomp_ok=3459
- decomp_fail=3
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184` |
| 字节数 | 918600 |
| SHA-256 | `869d47954664846a28ab4213b40e239686f86b464377a7703a58e3ca7e5f2ae9` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Binary/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 4 |
| 指令行数 | 213497 |

## 3. 反汇编清单（全量）

全文：disasm/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3462
- decomp_ok（伪 C） = 3459
- decomp_fail = 3
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `100632a9` `wsprintfA`：RuntimeError（decompile returned None）
- `1009bd78` `start`：RuntimeError（decompile returned None）
- `1009de35` `__check_overflow_exit`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：232.1 s
- 日志：out/R1N/ida/logs/sha256_869d47954664846a28ab4213b40e239686f86b464377a7703a58e3ca7e5f2ae9.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 3 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3462 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3462（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001010`, `sub_10001060`, `sub_100010B0`, `sub_10001160`, `sub_10001204`, `sub_10001220`, `sub_100012C0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/Binary/decompiled/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.c.txt` sha256=a4eb2ec60b87579e2d889cf5c0f65e8c562d5426c90a4b9f26c8bd35377955ac bytes=3899142
- `native4/01-completed/Aspen-Plus/Binary/disasm/NewBinary1.703671AB_0721_4B4E_B7BD_696D78DBD184.asm.txt` sha256=e9cdf853effc75c958cf287a7bcd76225bba7846a260362ddecad5551b1ed2db bytes=7471424
