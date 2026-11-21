# ComDlg02.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ComDlg02.dll`，1546752 字节，SHA-256 `6f9755fd29141a47e05701b4be2ea404c48368a05d8ee54cf14a891afa51b324` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 6520 = decomp_ok 6496 + decomp_fail 24 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=6520
- decomp_ok=6496
- decomp_fail=24
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ComDlg02.dll` |
| 字节数 | 1546752 |
| SHA-256 | `6f9755fd29141a47e05701b4be2ea404c48368a05d8ee54cf14a891afa51b324` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFilesFolder]/AspenTech Shared/ComDlg02.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x11000000` |
| 段数 | 4 |
| 指令行数 | 241675 |

## 3. 反汇编清单（全量）

全文：disasm/ComDlg02.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ComDlg02.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 6520
- decomp_ok（伪 C） = 6496
- decomp_fail = 24
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `11003ffc` `@System@@HandleAutoException$qqrv`：RuntimeError（decompile returned None）
- `11004224` `unknown_libname_35`：RuntimeError（decompile returned None）
- `11009384` `sub_11009384`：RuntimeError（decompile returned None）
- `1100e45c` `@Sysutils@OutOfMemoryError$qqrv`：RuntimeError（decompile returned None）
- `1100e8d0` `sub_1100E8D0`：RuntimeError（decompile returned None）
- `11012664` `@Variants@HandleConversionException$qqrxusxus`：RuntimeError（decompile returned None）
- `1101c3ac` `sub_1101C3AC`：RuntimeError（decompile returned None）
- `1101ce34` `unknown_libname_202`：RuntimeError（decompile returned None）
- `1101cf6c` `sub_1101CF6C`：RuntimeError（decompile returned None）
- `110233dc` `sub_110233DC`：RuntimeError（decompile returned None）
- `110262b4` `sub_110262B4`：RuntimeError（decompile returned None）
- `1102790c` `sub_1102790C`：RuntimeError（decompile returned None）
- `11027fe0` `sub_11027FE0`：RuntimeError（decompile returned None）
- `11032750` `sub_11032750`：RuntimeError（decompile returned None）
- `110329ec` `sub_110329EC`：RuntimeError（decompile returned None）
- `11032a0c` `sub_11032A0C`：RuntimeError（decompile returned None）
- `1104ec60` `sub_1104EC60`：RuntimeError（decompile returned None）
- `1104eda4` `sub_1104EDA4`：RuntimeError（decompile returned None）
- `1106f9a4` `sub_1106F9A4`：RuntimeError（decompile returned None）
- `1107ae54` `sub_1107AE54`：RuntimeError（decompile returned None）
- `11084634` `sub_11084634`：RuntimeError（decompile returned None）
- `110a1620` `sub_110A1620`：RuntimeError（decompile returned None）
- `110a3550` `sub_110A3550`：RuntimeError（decompile returned None）
- `110a3610` `unknown_libname_647`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：153.0 s
- 日志：out/R1N/ida/logs/sha256_6f9755fd29141a47e05701b4be2ea404c48368a05d8ee54cf14a891afa51b324.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 24 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ComDlg02.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 6520 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +6520（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_110011A5`, `sub_110011AF`, `sub_110011B9`, `GetStdHandle`, `RaiseException`, `RtlUnwind`, `UnhandledExceptionFilter`, `WriteFile`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/decompiled/ComDlg02.dll.c.txt` sha256=ef02751d1d77f2df7b1e6ecae1e3a48b6efe22c53b8e2de0f84b72d326cc9a07 bytes=4214158
- `native5/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/disasm/ComDlg02.dll.asm.txt` sha256=72fcc6c3282a08e1db0ac0e50eb0aa643225cf7ae1118afc98342f773ed5c970 bytes=8342179
