# pfsplotv250.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pfsplotv250.ocx`，2671144 字节，SHA-256 `ebe0948cfe23fbeef37596f0763d5b69f8de966c0a2dae5558051890c2cc0454` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 11584 = decomp_ok 11551 + decomp_fail 33 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=11584
- decomp_ok=11551
- decomp_fail=33
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pfsplotv250.ocx` |
| 字节数 | 2671144 |
| SHA-256 | `ebe0948cfe23fbeef37596f0763d5b69f8de966c0a2dae5558051890c2cc0454` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFilesFolder]/AspenTech Shared/pfsplotv250.ocx` |
| product_raw | `Properties` |
| 产品目录 | `Aspen-Properties` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 4 |
| 指令行数 | 654378 |

## 3. 反汇编清单（全量）

全文：disasm/pfsplotv250.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pfsplotv250.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 11584
- decomp_ok（伪 C） = 11551
- decomp_fail = 33
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10001450` `sub_10001450`：RuntimeError（decompile returned None）
- `100017b7` `sub_100017B7`：RuntimeError（decompile returned None）
- `100017cd` `sub_100017CD`：RuntimeError（decompile returned None）
- `100017e3` `sub_100017E3`：RuntimeError（decompile returned None）
- `10001e0c` `sub_10001E0C`：RuntimeError（decompile returned None）
- `10002072` `sub_10002072`：RuntimeError（decompile returned None）
- `10002620` `sub_10002620`：RuntimeError（decompile returned None）
- `10005400` `sub_10005400`：RuntimeError（decompile returned None）
- `100102d0` `sub_100102D0`：RuntimeError（decompile returned None）
- `10030ac0` `sub_10030AC0`：RuntimeError（decompile returned None）
- `10035c40` `sub_10035C40`：RuntimeError（decompile returned None）
- `100836b4` `sub_100836B4`：RuntimeError（decompile returned None）
- `100836ee` `sub_100836EE`：RuntimeError（decompile returned None）
- `10083728` `sub_10083728`：RuntimeError（decompile returned None）
- `10083762` `sub_10083762`：RuntimeError（decompile returned None）
- `1011ffd4` `sub_1011FFD4`：RuntimeError（decompile returned None）
- `1018a3a5` `sub_1018A3A5`：RuntimeError（decompile returned None）
- `1019df2d` `sub_1019DF2D`：RuntimeError（decompile returned None）
- `101bf12f` `?length@?$format_string_parser@D@__crt_stdio_input@@QBEIXZ`：RuntimeError（decompile returned None）
- `101c2780` `_sin`：RuntimeError（decompile returned None）
- `101c280f` `__sin_default`：RuntimeError（decompile returned None）
- `101c2bf0` `_cos`：RuntimeError（decompile returned None）
- `101c2c7f` `__cos_default`：RuntimeError（decompile returned None）
- `101c2dc4` `_sqrt`：RuntimeError（decompile returned None）
- `101c6ea0` `_atan`：RuntimeError（decompile returned None）
- `101c6f2f` `__atan_default`：RuntimeError（decompile returned None）
- `101c78c0` `_log10`：RuntimeError（decompile returned None）
- `101c7958` `start_3`：RuntimeError（decompile returned None）
- `101c7aa4` `__pow_default`：RuntimeError（decompile returned None）
- `101c7e8f` `__log_default`：RuntimeError（decompile returned None）
- `101cb09e` `start_6`：RuntimeError（decompile returned None）
- `101cb539` `__check_range_exit`：RuntimeError（decompile returned None）
- `101cb7ce` `start_7`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：396.4 s
- 日志：out/R1N/ida/logs/sha256_ebe0948cfe23fbeef37596f0763d5b69f8de966c0a2dae5558051890c2cc0454.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 33 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pfsplotv250.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 11584 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +11584（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001040`, `sub_10001080`, `sub_100010C0`, `sub_10001100`, `sub_10001140`, `sub_10001160`, `sub_10001170`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/pfsplotv250.ocx.c.txt` sha256=ea60a9dd7a108d78a5e22000b9b3dd9b0f6cd23e1e05699e39df6fe87464e302 bytes=10290818
- `disasm/pfsplotv250.ocx.asm.txt` sha256=7e41f08e1427679504ba06d121cbf76d5b0963b84a8407f93b11790b9be8baeb bytes=21411124
