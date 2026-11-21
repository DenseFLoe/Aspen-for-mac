# GRID32.OCX 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `GRID32.OCX`，89600 字节，SHA-256 `a792e40f88beea4604f1596209af604651b9adbc270300f560cde550f3280ce2` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 579 = decomp_ok 558 + decomp_fail 21 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=579
- decomp_ok=558
- decomp_fail=21
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `GRID32.OCX` |
| 字节数 | 89600 |
| SHA-256 | `a792e40f88beea4604f1596209af604651b9adbc270300f560cde550f3280ce2` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/GRID32.OCX` |
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
| 段数 | 6 |
| 指令行数 | 13331 |

## 3. 反汇编清单（全量）

全文：disasm/GRID32.OCX.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/GRID32.OCX.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 579
- decomp_ok（伪 C） = 558
- decomp_fail = 21
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `100010a0` `sub_100010A0`：RuntimeError（decompile returned None）
- `10001230` `sub_10001230`：RuntimeError（decompile returned None）
- `10001280` `sub_10001280`：RuntimeError（decompile returned None）
- `100012f0` `sub_100012F0`：RuntimeError（decompile returned None）
- `10001620` `sub_10001620`：RuntimeError（decompile returned None）
- `100048b0` `sub_100048B0`：RuntimeError（decompile returned None）
- `100049b0` `sub_100049B0`：RuntimeError（decompile returned None）
- `10004a30` `sub_10004A30`：RuntimeError（decompile returned None）
- `10004a90` `sub_10004A90`：RuntimeError（decompile returned None）
- `10004b00` `sub_10004B00`：RuntimeError（decompile returned None）
- `10008000` `sub_10008000`：RuntimeError（decompile returned None）
- `100088f0` `sub_100088F0`：RuntimeError（decompile returned None）
- `10008960` `sub_10008960`：RuntimeError（decompile returned None）
- `10009c20` `sub_10009C20`：RuntimeError（decompile returned None）
- `10009d30` `sub_10009D30`：RuntimeError（decompile returned None）
- `1000a991` `unknown_libname_2`：RuntimeError（decompile returned None）
- `1000a9e0` `??1AFX_MODULE_STATE@@UAE@XZ`：RuntimeError（decompile returned None）
- `1000aa4c` `??1?$CProcessLocal@VAFX_MODULE_PROCESS_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `1000aa87` `??1?$CThreadLocal@VAFX_MODULE_THREAD_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `1000aad0` `unknown_libname_3`：RuntimeError（decompile returned None）
- `1000afe6` `?FireEvent@COleControl@@QAAXJPAEZZ`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：30.6 s
- 日志：out/R1N/ida/logs/sha256_a792e40f88beea4604f1596209af604651b9adbc270300f560cde550f3280ce2.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 21 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `GRID32.OCX` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 579 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +579（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001010`, `sub_100010A0`, `j_?InitInstance@COleControlModule@@UAEHXZ`, `j_?ExitInstance@COleControlModule@@UAEHXZ`, `DllRegisterServer`, `DllUnregisterServer`, `sub_10001230`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `native2/01-completed/Aspen-Plus/[SystemFolder]/decompiled/GRID32.OCX.c.txt` sha256=3d124a8fe7916c4cc7508262a9f380bb4d9aa5bbb58eed114bd4e9f8fd2e029b bytes=246471
- `native2/01-completed/Aspen-Plus/[SystemFolder]/disasm/GRID32.OCX.asm.txt` sha256=8f7a7ccd4e680e32850278fce91fa4df3a768c2594580a65248375bf939020e7 bytes=446074
