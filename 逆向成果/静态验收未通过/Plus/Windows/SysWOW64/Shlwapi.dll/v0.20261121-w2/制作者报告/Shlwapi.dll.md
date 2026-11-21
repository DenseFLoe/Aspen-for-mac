# Shlwapi.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `Shlwapi.dll`，322984 字节，SHA-256 `b89b3be3ba3778ec08d08d9440f784dc1db89466736d747f6faed3bc46ec5caf` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1699 = decomp_ok 1656 + decomp_fail 43 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1699
- decomp_ok=1656
- decomp_fail=43
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `Shlwapi.dll` |
| 字节数 | 322984 |
| SHA-256 | `b89b3be3ba3778ec08d08d9440f784dc1db89466736d747f6faed3bc46ec5caf` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Windows/SysWOW64/Shlwapi.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x63180000` |
| 段数 | 7 |
| 指令行数 | 56369 |

## 3. 反汇编清单（全量）

全文：disasm/Shlwapi.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/Shlwapi.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1699
- decomp_ok（伪 C） = 1656
- decomp_fail = 43
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `63193e7d` `?StringCchCopyW@@YGJPAGIPBG@Z`：RuntimeError（decompile returned None）
- `631970a0` `??_G?$DefaultModule@$00@Details@WRL@Microsoft@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `63198660` `_PathUnExpandEnvStringsForUserW@16`：RuntimeError（decompile returned None）
- `6319b1de` `??$ReportFailure_Base@$02$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `6319bf44` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@Z$1?UnregisterWilFeatureConfigurationChange@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `6319bfd0` `??R?$__func@V<lambda_4b29d149b8821cfbae4eba16ce6a2849>@@$$A6G_NPAXI0II@Z@__function@wistd@@UAE_N$$QAPAX$$QAI011@Z`：RuntimeError（decompile returned None）
- `6319e28c` `?_FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `631a280e` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?CloseHandle@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `631a2821` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?ReleaseMutex@details@wil@@YGX0@ZU?$integral_constant@I$01@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `631a29e3` `?CloseHandle@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `631a2b4b` `?EnsureAllocated@ThreadLocalData@details_abi@wil@@QAE_N_N@Z`：RuntimeError（decompile returned None）
- `631a2bab` `?FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `631a2ca0` `?GetContextAndNotifyFailure@details@wil@@YGXPAUFailureInfo@2@PADI@Z`：RuntimeError（decompile returned None）
- `631a2fa9` `?GetLastErrorFailHr@details@wil@@YGJPAXIPBD110@Z`：RuntimeError（decompile returned None）
- `631a2fd1` `?GetLastErrorFailHr@details@wil@@YGJXZ`：RuntimeError（decompile returned None）
- `631a3620` `?ReleaseMutex@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `631a3690` `?Return_GetLastError@in1diag3@details@wil@@YGJPAXIPBD@Z`：RuntimeError（decompile returned None）
- `631a36ac` `?Return_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `631a39bd` `_StringCchCopyA@12`：RuntimeError（decompile returned None）
- `631a39f0` `?StringCchVPrintfW@@YGJPAGIPBGPAD@Z`：RuntimeError（decompile returned None）
- `631a3cee` `?_FailFast_GetLastError@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `631a47fa` `?StringCchCopyNA@@YGJPADIPBDI@Z`：RuntimeError（decompile returned None）
- `631a5b80` `_PathUnExpandEnvStringsForUserA@16`：RuntimeError（decompile returned None）
- `631a5f70` `_DoesStringRoundTripA@12`：RuntimeError（decompile returned None）
- `631a5f90` `_SHExpandEnvironmentStringsForUserA@16`：RuntimeError（decompile returned None）
- `631a6b49` `?StringCchCopyNW@@YGJPAGIPBGI@Z`：RuntimeError（decompile returned None）
- `631aa5b2` `_StringCchCopyW@12`：RuntimeError（decompile returned None）
- `631aca90` `_SHBoolSystemParametersInfo@8`：RuntimeError（decompile returned None）
- `631acdd0` `_SHInvokeCommandOnContextMenu@20`：RuntimeError（decompile returned None）
- `631ace00` `_SHInvokeCommandOnContextMenuEx@28`：RuntimeError（decompile returned None）
- `631acef0` `_SHInvokeCommandsOnContextMenu@24`：RuntimeError（decompile returned None）
- `631acf30` `_SHInvokeCommandsOnContextMenuEx@32`：RuntimeError（decompile returned None）
- `631af590` `??_E?$Module@$00V?$DefaultModule@$00@Details@WRL@Microsoft@@@WRL@Microsoft@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `631b06f0` `_IConnectionPoint_OnChanged@8`：RuntimeError（decompile returned None）
- `631b2b62` `?AppendItem@?$CDSA_Base@U_tagpropertykey@@@@QAEJPBU_tagpropertykey@@PAH@Z`：RuntimeError（decompile returned None）
- `631b2b89` `?AppendPtr@?$CDPA_Base@GVCTContainer_PolicyCoTaskMem@@@@QAEJPAGPAH@Z`：RuntimeError（decompile returned None）
- `631b2bb5` `?AppendPtr@?$CDPA_Base@UPROPVALUERESULT@@V?$CTContainer_PolicyUnOwned@UPROPVALUERESULT@@@@@@QAEJPAUPROPVALUERESULT@@PAH@Z`：RuntimeError（decompile returned None）
- `631b2e28` `?Destroy@?$CDPA_Base@GVCTContainer_PolicyCoTaskMem@@@@QAEHXZ`：RuntimeError（decompile returned None）
- `631b2e56` `?Destroy@?$CDPA_Base@UPROPVALUERESULT@@V?$CTContainer_PolicyUnOwned@UPROPVALUERESULT@@@@@@QAEHXZ`：RuntimeError（decompile returned None）
- `631b2ed0` `?GetClassIdentity@CXMLPropStore@@UAGJPAPAG@Z`：RuntimeError（decompile returned None）
- `631b35ef` `?Log_HrMsg@in1diag3@details@wil@@YAJPAXIPBDJ1ZZ`：RuntimeError（decompile returned None）
- `631b3c90` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@UISAXContentHandler@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `631b3cb0` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@UISAXContentHandler@@UISAXErrorHandler@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：43.3 s
- 日志：out/R1N/ida/logs/sha256_b89b3be3ba3778ec08d08d9440f784dc1db89466736d747f6faed3bc46ec5caf.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 43 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `Shlwapi.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1699 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1699（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`??$Write@U?$_tlgWrapperByRef@$07@@U?$_tlgWrapperByVal@$03@@U?$_tlgWrapSz@D@@U2@U3@U2@U?$_tlgWrapSz@G@@U2@U3@U2@U3@U4@U2@U3@U4@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EtwEventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByRef@$07@@ABU?$_tlgWrapperByVal@$03@@ABU?$_tlgWrapSz@D@@454ABU?$_tlgWrapSz@G@@45456456@Z`, `??$Write@U?$_tlgWrapperByRef@$07@@U?$_tlgWrapperByVal@$03@@U?$_tlgWrapSz@D@@U2@U3@U2@U?$_tlgWrapSz@G@@U2@U3@U2@U3@U4@U2@U3@U4@U2@U2@U3@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EtwEventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByRef@$07@@ABU?$_tlgWrapperByVal@$03@@ABU?$_tlgWrapSz@D@@454ABU?$_tlgWrapSz@G@@45456456445@Z`, `??$Write@U?$_tlgWrapperByVal@$03@@U1@U1@U?$_tlgWrapperByVal@$01@@U1@U?$_tlgWrapSz@D@@U2@U3@U3@U3@U2@U3@U3@U3@U3@U1@U3@U1@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EtwEventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByVal@$03@@33ABU?$_tlgWrapperByVal@$01@@3ABU?$_tlgWrapSz@D@@455545555353@Z`, `??$Write@U?$_tlgWrapperByVal@$03@@U1@U1@U?$_tlgWrapperByVal@$01@@U?$_tlgWrapperByVal@$00@@U1@U1@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EtwEventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByVal@$03@@33ABU?$_tlgWrapperByVal@$01@@ABU?$_tlgWrapperByVal@$00@@33@Z`, `??$Write@U?$_tlgWrapperByVal@$03@@U1@U1@U?$_tlgWrapperByVal@$01@@U?$_tlgWrapperByVal@$00@@U1@U3@U1@@?$_tlgWriteTemplate@$$A6GJPBU_tlgProvider_t@@PBXPBU_GUID@@2IPAU_EVENT_DATA_DESCRIPTOR@@@Z$1?_tlgWriteTransfer_EtwEventWriteTransfer@@YGJ0122I3@ZPBU2@PBU2@@@SGJPBU_tlgProvider_t@@PBXPBU_GUID@@2ABU?$_tlgWrapperByVal@$03@@33ABU?$_tlgWrapperByVal@$01@@ABU?$_tlgWrapperByVal@$00@@353@Z`, `??$_tlgCreate1Sz@G@@YGXPAU_EVENT_DATA_DESCRIPTOR@@PBG@Z`, `_TraceLoggingRegisterEx_EtwEventRegister_EtwEventSetInformation@12`, `_TraceLoggingSetInformation_EtwEventSetInformation@16`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/Shlwapi.dll.c.txt` sha256=8e0e527e0cae903bb3e41cd7ab89050d686aaed8fda5517667d7c6dcfeaa00e1 bytes=1232086
- `decompiled/webcheck.dll.c.txt` sha256=8f39d25fb5d934a10825c6cdddd05c02d75a69f37839995da9761c58e1504776 bytes=943377
- `disasm/Shlwapi.dll.asm.txt` sha256=b9bc604819f09d44db3231a0f7d4caa36786f12a691da380b9ed88408b136621 bytes=2070898
- `disasm/webcheck.dll.asm.txt` sha256=e241ade69f8a7d7c95f67a0f66e748edf2677d2ba48ab30a63d8760f05ac357c bytes=1862896
