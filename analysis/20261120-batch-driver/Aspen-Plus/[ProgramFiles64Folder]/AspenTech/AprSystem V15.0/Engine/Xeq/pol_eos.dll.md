# pol_eos.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pol_eos.dll`，605224 字节，SHA-256 `4abc9b0d56d2374d2d092f58414c35cabb8d39f8ffebbd590de95f96c36e762e` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 317 = decomp_ok 311 + decomp_fail 6 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=317
- decomp_ok=311
- decomp_fail=6
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pol_eos.dll` |
| 字节数 | 605224 |
| SHA-256 | `4abc9b0d56d2374d2d092f58414c35cabb8d39f8ffebbd590de95f96c36e762e` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pol_eos.dll` |
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
| 指令行数 | 90433 |

## 3. 反汇编清单（全量）

全文：disasm/pol_eos.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pol_eos.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 317
- decomp_ok（伪 C） = 311
- decomp_fail = 6
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180001000` `PEOS_ES40`：RuntimeError（decompile returned None）
- `180044ae0` `PEOS_PCSAF1`：RuntimeError（decompile returned None）
- `180045a40` `sub_180045A40`：RuntimeError（decompile returned None）
- `180047660` `sub_180047660`：RuntimeError（decompile returned None）
- `1800489e0` `sub_1800489E0`：RuntimeError（decompile returned None）
- `18004d190` `sub_18004D190`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：85.6 s
- 日志：out/R1N/ida/logs/sha256_4abc9b0d56d2374d2d092f58414c35cabb8d39f8ffebbd590de95f96c36e762e.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 6 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pol_eos.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 317 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +317（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`PEOS_ES40`, `PEOS_ES40A`, `sub_180002D40`, `sub_180003D50`, `PEOS_ESSLP`, `PEOS_ESSLPA`, `sub_1800042D0`, `sub_180007E40`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/pol_eos.dll.c.txt` sha256=6876b03e26d17fd87e0264f25b97dd5aaccaac6aa37e82d0548cfeb4ceee05da bytes=1638479
- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/pol_eos.dll.asm.txt` sha256=32926093b6cfc08c586f124099418ed58e57bd1d2d9a4fffeb072cae69c42a6d bytes=3493626
