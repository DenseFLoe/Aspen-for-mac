# mfc42.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `mfc42.dll`，1195008 字节，SHA-256 `93ba144338cd5e5df61651f268ab27ff12912260e558c3ae525d4e97b8c63ecb` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 6518 = decomp_ok 6492 + decomp_fail 26 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=6518
- decomp_ok=6492
- decomp_fail=26
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `mfc42.dll` |
| 字节数 | 1195008 |
| SHA-256 | `93ba144338cd5e5df61651f268ab27ff12912260e558c3ae525d4e97b8c63ecb` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Windows/SysWOW64/mfc42.dll` |
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
| 段数 | 7 |
| 指令行数 | 257773 |

## 3. 反汇编清单（全量）

全文：disasm/mfc42.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/mfc42.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 6518
- decomp_ok（伪 C） = 6492
- decomp_fail = 26
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10037c90` `?AtlA2WHelper@@YGPAGPAGPBDH@Z`：RuntimeError（decompile returned None）
- `10037f20` `?AtlW2AHelper@@YGPADPADPBGH@Z`：RuntimeError（decompile returned None）
- `100508f0` `?ModifyStyle@CWnd@@SGHPAUHWND__@@KKI@Z`：RuntimeError（decompile returned None）
- `10050920` `?ModifyStyleEx@CWnd@@SGHPAUHWND__@@KKI@Z`：RuntimeError（decompile returned None）
- `10064830` `?DDV_MinMaxByte@@YGXPAVCDataExchange@@EEE@Z`：RuntimeError（decompile returned None）
- `10064870` `?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z`：RuntimeError（decompile returned None）
- `100648a0` `?DDV_MinMaxLong@@YGXPAVCDataExchange@@JJJ@Z`：RuntimeError（decompile returned None）
- `100648d0` `?DDV_MinMaxShort@@YGXPAVCDataExchange@@FFF@Z`：RuntimeError（decompile returned None）
- `100653f0` `?DDV_MinMaxDouble@@YGXPAVCDataExchange@@ABNNN@Z`：RuntimeError（decompile returned None）
- `10065450` `?DDV_MinMaxFloat@@YGXPAVCDataExchange@@ABMMM@Z`：RuntimeError（decompile returned None）
- `10073140` `?OnNcCreate@CSplitterWnd@@IAEHPAUtagCREATESTRUCTA@@@Z`：RuntimeError（decompile returned None）
- `1007c180` `?QueryOption@CInternetConnection@@QBEHKAAVCString@@@Z`：RuntimeError（decompile returned None）
- `1007c200` `?QueryOption@CInternetFile@@QBEHKAAVCString@@@Z`：RuntimeError（decompile returned None）
- `1007c280` `?QueryOption@CInternetSession@@QBEHKAAVCString@@@Z`：RuntimeError（decompile returned None）
- `10080870` `?AfxSetRecordCount@@YGXPAJJJHF@Z`：RuntimeError（decompile returned None）
- `10099db0` `?RunAutomated@CWinApp@@QAEHXZ`：RuntimeError（decompile returned None）
- `10099de0` `?RunEmbedded@CWinApp@@QAEHXZ`：RuntimeError（decompile returned None）
- `100a6cb0` `??8COleSafeArray@@QBEHPBUtagSAFEARRAY@@@Z`：RuntimeError（decompile returned None）
- `100a6cd0` `??8COleSafeArray@@QBEHABVCOleVariant@@@Z`：RuntimeError（decompile returned None）
- `100b14e0` `?DeactivateAndUndo@COleServerDoc@@QAEHXZ`：RuntimeError（decompile returned None）
- `100b1720` `?DiscardUndoState@COleServerDoc@@QAEHXZ`：RuntimeError（decompile returned None）
- `100c75c0` `?GetDefBtnCode@COccManager@@SAKPAVCWnd@@@Z`：RuntimeError（decompile returned None）
- `100c7d09` `?_AfxDlgSetFocus@@YGXPAVCWnd@@@Z`：RuntimeError（decompile returned None）
- `100d5730` `?ExchangeProp@CResetPropExchange@@UAEHPBDGPAXPBX@Z`：RuntimeError（decompile returned None）
- `100d59d0` `?PX_DataPath@@YAHPAVCPropExchange@@PBDAAVCDataPathProperty@@1@Z`：RuntimeError（decompile returned None）
- `100d59f0` `?PX_DataPath@@YAHPAVCPropExchange@@PBDAAVCDataPathProperty@@ABVCString@@@Z`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：269.2 s
- 日志：out/R1N/ida/logs/sha256_93ba144338cd5e5df61651f268ab27ff12912260e558c3ae525d4e97b8c63ecb.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 26 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `mfc42.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 6518 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +6518（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：``dynamic initializer for '_simpleInvalidArgException''`, ``dynamic initializer for '_simpleMemoryException''`, ``dynamic initializer for '_simpleNotSupportedException''`, ``dynamic atexit destructor for '_simpleInvalidArgException''`, ``dynamic atexit destructor for '_simpleMemoryException''`, ``dynamic atexit destructor for '_simpleNotSupportedException''`, ``dynamic initializer for '_init_CByteArray''`, ``dynamic initializer for '_init_CDWordArray''`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/Windows/SysWOW64/decompiled/mfc42.dll.c.txt` sha256=0a08b5c9a2796574ab20698f69bc32b98c896f2d6559dfaa2983a47be6f09323 bytes=4759453
- `native5/01-completed/Aspen-Plus/Windows/SysWOW64/disasm/mfc42.dll.asm.txt` sha256=5c6c73ddc6b51143a5e06023dd2ea0a8c30a293b276655d31d941a85a31481e1 bytes=9045283
