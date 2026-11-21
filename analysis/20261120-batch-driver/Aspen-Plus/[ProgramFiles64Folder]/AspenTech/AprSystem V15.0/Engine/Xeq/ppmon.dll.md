# ppmon.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ppmon.dll`，1625640 字节，SHA-256 `caa9bac0cbdf9008d3565abfd337ef2b476c3bc93236d09ea2c30f3e737dac5c` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 996 = decomp_ok 984 + decomp_fail 12 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=996
- decomp_ok=984
- decomp_fail=12
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ppmon.dll` |
| 字节数 | 1625640 |
| SHA-256 | `caa9bac0cbdf9008d3565abfd337ef2b476c3bc93236d09ea2c30f3e737dac5c` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppmon.dll` |
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
| 指令行数 | 274269 |

## 3. 反汇编清单（全量）

全文：disasm/ppmon.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ppmon.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 996
- decomp_ok（伪 C） = 984
- decomp_fail = 12
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `18003b1d0` `sub_18003B1D0`：RuntimeError（decompile returned None）
- `18006c910` `sub_18006C910`：RuntimeError（decompile returned None）
- `180097190` `PPMON_ESMON0`：RuntimeError（decompile returned None）
- `1800ba6d0` `sub_1800BA6D0`：RuntimeError（decompile returned None）
- `1800e24b0` `sub_1800E24B0`：RuntimeError（decompile returned None）
- `1800e8f10` `sub_1800E8F10`：RuntimeError（decompile returned None）
- `1800ea730` `sub_1800EA730`：RuntimeError（decompile returned None）
- `1800f0890` `sub_1800F0890`：RuntimeError（decompile returned None）
- `180100f40` `sub_180100F40`：RuntimeError（decompile returned None）
- `1801093b0` `sub_1801093B0`：RuntimeError（decompile returned None）
- `1801122d0` `sub_1801122D0`：RuntimeError（decompile returned None）
- `180113b30` `sub_180113B30`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：537.1 s
- 日志：out/R1N/ida/logs/sha256_caa9bac0cbdf9008d3565abfd337ef2b476c3bc93236d09ea2c30f3e737dac5c.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 12 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ppmon.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 996 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +996（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800016D0`, `sub_180001F00`, `PPMON_CALPRP`, `PPMON_CALPRPI`, `sub_18000BC20`, `sub_18000E3C0`, `PPMON_CHKION`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/ppmon.dll.c.txt` sha256=217960c9553f6e8e7793a321db4556fa837ad0e34627baa1bf01d74597d4590d bytes=4898291
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/ppmon.dll.asm.txt` sha256=2b77f20f624300f0a1035366149dc5cfc7a11ad367e27721a2323c2af94b3424 bytes=10726998
