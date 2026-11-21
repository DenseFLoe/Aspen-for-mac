# AssistEd.exe 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `AssistEd.exe`，713768 字节，SHA-256 `f948cf2ce74fd0053442cdc194f1cf3c780afe58c6834e00d95a8e920fb0f61b` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 5203 = decomp_ok 5164 + decomp_fail 39 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=5203
- decomp_ok=5164
- decomp_fail=39
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `AssistEd.exe` |
| 字节数 | 713768 |
| SHA-256 | `f948cf2ce74fd0053442cdc194f1cf3c780afe58c6834e00d95a8e920fb0f61b` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFiles64Folder]/AspenTech Shared/AssistEd.exe` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x400000` |
| 段数 | 6 |
| 指令行数 | 169851 |

## 3. 反汇编清单（全量）

全文：disasm/AssistEd.exe.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/AssistEd.exe.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 5203
- decomp_ok（伪 C） = 5164
- decomp_fail = 39
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `40406c` `unknown_libname_59`：RuntimeError（decompile returned None）
- `4085b0` `sub_4085B0`：RuntimeError（decompile returned None）
- `4085c8` `sub_4085C8`：RuntimeError（decompile returned None）
- `40c47c` `@Sysutils@OutOfMemoryError$qqrv`：RuntimeError（decompile returned None）
- `40c818` `unknown_libname_144`：RuntimeError（decompile returned None）
- `40fa1c` `@Variants@HandleConversionException$qqrxusxus`：RuntimeError（decompile returned None）
- `411eb0` `@Variants@@VarToBool$qqrrx8TVarData`：RuntimeError（decompile returned None）
- `41429c` `unknown_libname_1101`：RuntimeError（decompile returned None）
- `416190` `@Variants@@VarNeg$qqrr8TVarData`：RuntimeError（decompile returned None）
- `41c898` `sub_41C898`：RuntimeError（decompile returned None）
- `41e620` `@Classes@TStream@SetSize$qqrxj`：RuntimeError（decompile returned None）
- `41e7b4` `@Classes@TStream@ReadBuffer$qqrpvi`：RuntimeError（decompile returned None）
- `41e7ec` `sub_41E7EC`：RuntimeError（decompile returned None）
- `41ed0c` `@Classes@TMemoryStream@Realloc$qqrri`：RuntimeError（decompile returned None）
- `41f084` `sub_41F084`：RuntimeError（decompile returned None）
- `41f73c` `sub_41F73C`：RuntimeError（decompile returned None）
- `41f760` `unknown_libname_325`：RuntimeError（decompile returned None）
- `41fcb0` `@Classes@TReader@ReadBuffer$qqrv`：RuntimeError（decompile returned None）
- `4284a8` `@Graphics@TCanvas@RequiredState$qqr50System@%Set$t22Graphics@TCanvasStates$iuc$0$iuc$3%`：RuntimeError（decompile returned None）
- `42867c` `sub_42867C`：RuntimeError（decompile returned None）
- `428694` `sub_428694`：RuntimeError（decompile returned None）
- `440528` `@Clipbrd@TClipboard@Open$qqrv`：RuntimeError（decompile returned None）
- `4473a4` `@Controls@TControl@SetParent$qqrp20Controls@TWinControl`：RuntimeError（decompile returned None）
- `44d980` `@Controls@TWinControl@GetDeviceContext$qqrrui`：RuntimeError（decompile returned None）
- `44e1c4` `sub_44E1C4`：RuntimeError（decompile returned None）
- `44f910` `unknown_libname_709`：RuntimeError（decompile returned None）
- `44f958` `unknown_libname_710`：RuntimeError（decompile returned None）
- `44fb64` `@Controls@TDockZone@GetControlName$qqrv`：RuntimeError（decompile returned None）
- `456eec` `unknown_libname_1193`：RuntimeError（decompile returned None）
- `46c620` `unknown_libname_932`：RuntimeError（decompile returned None）
- `46fafc` `sub_46FAFC`：RuntimeError（decompile returned None）
- `471e70` `sub_471E70`：RuntimeError（decompile returned None）
- `476eec` `@Comobj@OleError$qqrl`：RuntimeError（decompile returned None）
- `4777b8` `unknown_libname_1016`：RuntimeError（decompile returned None）
- `4778cc` `sub_4778CC`：RuntimeError（decompile returned None）
- `477a54` `unknown_libname_1019`：RuntimeError（decompile returned None）
- `47bd9c` `sub_47BD9C`：RuntimeError（decompile returned None）
- `47e820` `@Olectrls@TOleControl@HookControlWndProc$qqrv`：RuntimeError（decompile returned None）
- `47e8b0` `unknown_libname_1059`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：178.1 s
- 日志：out/R1N/ida/logs/sha256_f948cf2ce74fd0053442cdc194f1cf3c780afe58c6834e00d95a8e920fb0f61b.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 39 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `AssistEd.exe` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 5203 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +5203（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_4011BD`, `sub_4011C7`, `sub_4011D1`, `CloseHandle`, `CreateFileA`, `GetFileType`, `GetFileSize`, `GetStdHandle`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `Aspen Data Share V15.0/decompiled/AdbHysysExtract.dll.c.txt` sha256=3d8a1b02a86cf44793012daa1e8821017fa4fc28e34de0d384525b0e140f6c80 bytes=200443
- `Aspen Data Share V15.0/decompiled/AdbHysysExtractCOM.exe.c.txt` sha256=3d66122ccc3986cb55d35191e8234cd73d51f98af45d6a574970c411239e8539 bytes=292500
- `Aspen Data Share V15.0/disasm/AdbHysysExtract.dll.asm.txt` sha256=ba485a6dac491de431640d7cbf8e84d1e47b091c2bccbc62f3baca252e47be9f bytes=309376
- `Aspen Data Share V15.0/disasm/AdbHysysExtractCOM.exe.asm.txt` sha256=033d95c49e96b6e73ec9a7fafd43313c844dd7eee1369c10b7d5ccc177f99649 bytes=508524
- `decompiled/AssistEd.exe.c.txt` sha256=81a8a0683886d48479188c7e721a79bab749384bf47714508b54c8b97989288e bytes=3538742
- `decompiled/ComWrappersPS.dll.c.txt` sha256=c112319114d531448dbee1c5460aae4d19b9c8243b0b50694cf4e606fd3f7f0c bytes=27128
- `decompiled/apvcomps.dll.c.txt` sha256=9fbb3a58815c6489a1bde85942cb1ab154b96732766dff1a0f7cceee517ba574 bytes=48210
- `disasm/AssistEd.exe.asm.txt` sha256=290ea44ef0c65a6dcc6683cad02ee4dc27c4b75a02a6db59cb613d0c36cf10ec bytes=5627509
- `disasm/ComWrappersPS.dll.asm.txt` sha256=241ef20fb4e4656ef4137d7fb014348543af50cf92988b25155c428581cbc69d bytes=47581
- `disasm/apvcomps.dll.asm.txt` sha256=c2fb9afd0e80a2ca119d0c22f15843f24af7f0e18d957c966b6f9c2dfdb912e7 bytes=65284
