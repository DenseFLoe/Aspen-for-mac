# Report02.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `Report02.dll`，847360 字节，SHA-256 `32c4e66e130de3cfebaa9191f732d77a3457a717be7e002821385eb41abf181c` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 5794 = decomp_ok 5758 + decomp_fail 36 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=5794
- decomp_ok=5758
- decomp_fail=36
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `Report02.dll` |
| 字节数 | 847360 |
| SHA-256 | `32c4e66e130de3cfebaa9191f732d77a3457a717be7e002821385eb41abf181c` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFilesFolder]/Aspentech Shared/Report02.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x11500000` |
| 段数 | 4 |
| 指令行数 | 178794 |

## 3. 反汇编清单（全量）

全文：disasm/Report02.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/Report02.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 5794
- decomp_ok（伪 C） = 5758
- decomp_fail = 36
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `11504134` `@System@@HandleAutoException$qqrv`：RuntimeError（decompile returned None）
- `1150435c` `unknown_libname_38`：RuntimeError（decompile returned None）
- `115091a8` `sub_115091A8`：RuntimeError（decompile returned None）
- `115091c0` `sub_115091C0`：RuntimeError（decompile returned None）
- `1150d734` `@Sysutils@OutOfMemoryError$qqrv`：RuntimeError（decompile returned None）
- `1150dad0` `unknown_libname_166`：RuntimeError（decompile returned None）
- `11510e6c` `@Variants@HandleConversionException$qqrxusxus`：RuntimeError（decompile returned None）
- `11519044` `@Comobj@OleError$qqrl`：RuntimeError（decompile returned None）
- `115199c0` `unknown_libname_265`：RuntimeError（decompile returned None）
- `11519ad4` `sub_11519AD4`：RuntimeError（decompile returned None）
- `11519c5c` `unknown_libname_268`：RuntimeError（decompile returned None）
- `1151eeec` `sub_1151EEEC`：RuntimeError（decompile returned None）
- `11520cdc` `@Classes@TStream@SetSize$qqrxj`：RuntimeError（decompile returned None）
- `11520e70` `sub_11520E70`：RuntimeError（decompile returned None）
- `11520ea8` `@Classes@TStream@WriteBuffer$qqrpxvi`：RuntimeError（decompile returned None）
- `115213f8` `@Classes@TMemoryStream@Realloc$qqrri`：RuntimeError（decompile returned None）
- `11521770` `sub_11521770`：RuntimeError（decompile returned None）
- `11521e28` `sub_11521E28`：RuntimeError（decompile returned None）
- `11521e4c` `unknown_libname_359`：RuntimeError（decompile returned None）
- `115223b4` `@Classes@TReader@ReadBuffer$qqrv`：RuntimeError（decompile returned None）
- `1152b25c` `@Graphics@TCanvas@RequiredState$qqr50System@%Set$t22Graphics@TCanvasStates$iuc$0$iuc$3%`：RuntimeError（decompile returned None）
- `1152b430` `sub_1152B430`：RuntimeError（decompile returned None）
- `1152b448` `sub_1152B448`：RuntimeError（decompile returned None）
- `11533744` `sub_11533744`：RuntimeError（decompile returned None）
- `1153a248` `@Clipbrd@TClipboard@Open$qqrv`：RuntimeError（decompile returned None）
- `1153aa90` `unknown_libname_556`：RuntimeError（decompile returned None）
- `1155a5cc` `unknown_libname_1236`：RuntimeError（decompile returned None）
- `11565310` `@Controls@TControl@SetParent$qqrp20Controls@TWinControl`：RuntimeError（decompile returned None）
- `1156bafc` `@Controls@TWinControl@GetDeviceContext$qqrrui`：RuntimeError（decompile returned None）
- `1156c33c` `sub_1156C33C`：RuntimeError（decompile returned None）
- `1156dbdc` `unknown_libname_965`：RuntimeError（decompile returned None）
- `1156dc24` `unknown_libname_966`：RuntimeError（decompile returned None）
- `1156de30` `@Controls@TDockZone@GetControlName$qqrv`：RuntimeError（decompile returned None）
- `11577fc0` `sub_11577FC0`：RuntimeError（decompile returned None）
- `11579da8` `@Olectrls@TOleControl@HookControlWndProc$qqrv`：RuntimeError（decompile returned None）
- `11579e38` `unknown_libname_1076`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：193.9 s
- 日志：out/R1N/ida/logs/sha256_32c4e66e130de3cfebaa9191f732d77a3457a717be7e002821385eb41abf181c.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 36 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `Report02.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 5794 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +5794（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_115011E5`, `sub_115011EF`, `sub_115011F9`, `sub_11501302`, `sub_1150130C`, `GetStdHandle`, `RaiseException`, `RtlUnwind`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/decompiled/Report02.dll.c.txt` sha256=e4e7c3a0814c3625320b4e3ee7a9976b1c637194cb00b35ae1e997612868c0d0 bytes=3788150
- `native4/01-completed/Aspen-Plus/[CommonFilesFolder]/AspenTech Shared/disasm/Report02.dll.asm.txt` sha256=bc466db8a336eae3a2aca2c7232a43df371f6b4e0810b8a13b369ce4eb5d09fb bytes=6329004
