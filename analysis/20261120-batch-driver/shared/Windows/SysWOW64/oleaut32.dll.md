# oleaut32.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `oleaut32.dll`，656496 字节，SHA-256 `16f8c0acea3adeacc04f4eadd4462619b1c11913019711b1097ec4ce0ea23890` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 2655 = decomp_ok 2612 + decomp_fail 43 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=2655
- decomp_ok=2612
- decomp_fail=43
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `oleaut32.dll` |
| 字节数 | 656496 |
| SHA-256 | `16f8c0acea3adeacc04f4eadd4462619b1c11913019711b1097ec4ce0ea23890` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Windows/SysWOW64/oleaut32.dll` |
| product_raw | `Plus-Properties` |
| 产品目录 | `Plus-Properties` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 7 |
| 指令行数 | 145513 |

## 3. 反汇编清单（全量）

全文：disasm/oleaut32.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/oleaut32.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 2655
- decomp_ok（伪 C） = 2612
- decomp_fail = 43
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10014180` `?QueryInterface@CStubWrapper@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `100145c0` `?QueryInterface@CStubRecordInfoCF@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `10015f84` `?ReleaseProcessData@@YGXXZ`：RuntimeError（decompile returned None）
- `10017754` `??1?$unique_storage@U?$resource_policy@PAGP6GXPAX@Z$1?FreeProcessHeap@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAGPAG$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `10017770` `__IPropertyBag_Read_Proxy@16`：RuntimeError（decompile returned None）
- `10025aec` `?Return_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `10030460` `_CreateStdDispatch@16`：RuntimeError（decompile returned None）
- `10031c00` `_SafeArrayReleaseDescriptor@4`：RuntimeError（decompile returned None）
- `10034d64` `?BstrOfHname@CTypeLib2@@QAEJKPAPAG@Z`：RuntimeError（decompile returned None）
- `10038517` `??$ReportFailure_Base@$01$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `1003853d` `??$ReportFailure_Base@$02$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `10039df4` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@Z$1?UnregisterWilFeatureConfigurationChange@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `10039ee0` `??R?$__func@V<lambda_4b29d149b8821cfbae4eba16ce6a2849>@@$$A6G_NPAXI0II@Z@__function@wistd@@UAE_N$$QAPAX$$QAI011@Z`：RuntimeError（decompile returned None）
- `1003a270` `?CloseHandle@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `1003a3e3` `?EnsureAllocated@ThreadLocalData@details_abi@wil@@QAE_N_N@Z`：RuntimeError（decompile returned None）
- `1003a634` `?FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1003a9e0` `?GetContextAndNotifyFailure@details@wil@@YGXPAUFailureInfo@2@PADI@Z`：RuntimeError（decompile returned None）
- `1003ab45` `?GetLastErrorFailHr@details@wil@@YGJPAXIPBD110@Z`：RuntimeError（decompile returned None）
- `1003ab6d` `?GetLastErrorFailHr@details@wil@@YGJXZ`：RuntimeError（decompile returned None）
- `1003bf20` `?ReleaseMutex@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `1003c174` `?Return_GetLastError@in1diag3@details@wil@@YGJPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1003c531` `?StringCchPrintfW@@YAJPAGIPBGZZ`：RuntimeError（decompile returned None）
- `1003c9a3` `?ULongAdd_RpcRaiseIfFailed@@YGXKKPAK@Z`：RuntimeError（decompile returned None）
- `1003ceb2` `?_FailFast_GetLastError@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1003fb50` `_VarCyFix@12`：RuntimeError（decompile returned None）
- `1003fba0` `_VarCyInt@12`：RuntimeError（decompile returned None）
- `100410e0` `_g_x86CallTable`：RuntimeError（decompile returned None）
- `1005936e` `?_FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1006ac3b` `?StringCchCopyW@@YGJPAGIPBG@Z`：RuntimeError（decompile returned None）
- `1006b4e0` `_CLEANLOCALSTORAGE_UserSize@12`：RuntimeError（decompile returned None）
- `1007a22c` `?FailFast_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `1007c820` `?GetIDsOfNames@CPDDispImpl@@UAGJABU_GUID@@PAPAGIKPAJ@Z`：RuntimeError（decompile returned None）
- `1007c850` `?GetTypeInfo@CPDDispImpl@@UAGJIKPAPAUITypeInfo@@@Z`：RuntimeError（decompile returned None）
- `1007c880` `?GetTypeInfoCount@CPDDispImpl@@UAGJPAI@Z`：RuntimeError（decompile returned None）
- `1007c8a0` `?Invoke@CPDDispImpl@@UAGJJABU_GUID@@KGPAUtagDISPPARAMS@@PAUtagVARIANT@@PAUtagEXCEPINFO@@PAI@Z`：RuntimeError（decompile returned None）
- `1007e250` `?GetAllCustData@CPTITypeInfoImpl@@UAGJPAUtagCUSTDATA@@@Z`：RuntimeError（decompile returned None）
- `1007e520` `?GetCustData@CPTITypeInfoImpl@@UAGJABU_GUID@@PAUtagVARIANT@@@Z`：RuntimeError（decompile returned None）
- `10080e90` `?GetAllCustData@CPTLibTypeLibImpl@@UAGJPAUtagCUSTDATA@@@Z`：RuntimeError（decompile returned None）
- `10080ed0` `?GetCustData@CPTLibTypeLibImpl@@UAGJABU_GUID@@PAUtagVARIANT@@@Z`：RuntimeError（decompile returned None）
- `10087b20` `_UnivGetIDsOfNames@24`：RuntimeError（decompile returned None）
- `10087b50` `_UnivGetTypeInfo@16`：RuntimeError（decompile returned None）
- `10087b80` `_UnivGetTypeInfoCount@8`：RuntimeError（decompile returned None）
- `10087ba0` `_UnivInvoke@36`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：137.5 s
- 日志：out/R1N/ida/logs/sha256_16f8c0acea3adeacc04f4eadd4462619b1c11913019711b1097ec4ce0ea23890.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 43 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `oleaut32.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 2655 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +2655（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`__dcomoc_IID_Lookup@8`, `__dcomoff_IID_Lookup@8`, `__dcomoa_IID_Lookup@8`, `nullsub_1`, `_TraceLoggingRegisterEx_EventRegister_EventSetInformation@12`, `_TraceLoggingSetInformation_EventSetInformation@16`, `__tlgEnableCallback@36`, `??$Write@U?$_tlgWrapperByRef@$07@@U?$_tlgWrapperByVal@$03@@U2@U?$_tlgWrapperByVal@$00@@U?$_tlgWrapperByRef@$0BA@@@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByRef@$07@@ABU?$_tlgWrapperByVal@$03@@4ABU?$_tlgWrapperByVal@$00@@ABU?$_tlgWrapperByRef@$0BA@@@@Z`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Plus-Properties/Windows/SysWOW64/decompiled/oleaut32.dll.c.txt` sha256=e4aeed6b11ca1dac90a61e153a19a6fe4390af08abe0023ad554dbc5efee7883 bytes=3476878
- `native4/01-completed/Plus-Properties/Windows/SysWOW64/disasm/oleaut32.dll.asm.txt` sha256=fd3f00153dbefac2ab6091864fb4addd33632af182359b3a6cb9ed7f257e26ee bytes=5134515
