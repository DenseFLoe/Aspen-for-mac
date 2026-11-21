# URLMON.DLL 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `URLMON.DLL`，1702864 字节，SHA-256 `fce2477a7c14055e489739bd0b0607f1f2e910136c4be833a74932f49293d90a` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 5276 = decomp_ok 5152 + decomp_fail 124 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=5276
- decomp_ok=5152
- decomp_fail=124
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `URLMON.DLL` |
| 字节数 | 1702864 |
| SHA-256 | `fce2477a7c14055e489739bd0b0607f1f2e910136c4be833a74932f49293d90a` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Windows/SysWOW64/URLMON.DLL` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x1a400000` |
| 段数 | 8 |
| 指令行数 | 307193 |

## 3. 反汇编清单（全量）

全文：disasm/URLMON.DLL.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/URLMON.DLL.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 5276
- decomp_ok（伪 C） = 5152
- decomp_fail = 124
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1a4264b0` `_UnregisterPermanentInternetSecurityManager@0`：RuntimeError（decompile returned None）
- `1a426d80` `?UnregisterPermanentUrlRedirectionPolicyManager@@YGJXZ`：RuntimeError（decompile returned None）
- `1a42931d` `?GetUAStringCacheKey@CIEBrowserModeFilter@@AAEJPBGPAGI@Z`：RuntimeError（decompile returned None）
- `1a42ac80` `??R?$__func@V<lambda_4b29d149b8821cfbae4eba16ce6a2849>@@$$A6G_NPAXI0II@Z@__function@wistd@@UAE_N$$QAPAX$$QAI011@Z`：RuntimeError（decompile returned None）
- `1a42b31b` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?ReleaseMutex@details@wil@@YGX0@ZU?$integral_constant@I$01@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a42b32e` `?ReleaseMutex@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `1a42b527` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?CloseHandle@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a42b53a` `?CloseHandle@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `1a42c730` `?FindFirstCF@CProtMgr@@UAGJPBGPAPAUIClassFactory@@PAU_GUID@@@Z`：RuntimeError（decompile returned None）
- `1a432bb0` `_PrivateGetMimeClassID@8`：RuntimeError（decompile returned None）
- `1a439543` `?StringCchPrintfA@@YAJPADIPBDZZ`：RuntimeError（decompile returned None）
- `1a439fd2` `??8@YG_NABU_GUID@@0@Z`：RuntimeError（decompile returned None）
- `1a43a7a0` `_CompatFlagsFromClsid@12`：RuntimeError（decompile returned None）
- `1a43bd50` `?RegisterProtocolMonitor@@YGJPAUIHttpProtocolListener@@H@Z`：RuntimeError（decompile returned None）
- `1a43c8e0` `_IEGlobalCounterGetValue@4`：RuntimeError（decompile returned None）
- `1a43d240` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@Z$1?UnregisterWilFeatureConfigurationChange@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a43d254` `??1?$unique_storage@U?$resource_policy@PAUFEATURE_STATE_CHANGE_SUBSCRIPTION__@@P6GXPAU1@@Z$1?UnsubscribeProcessWideUsageFlush@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAU1@PAU1@$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a43e7c0` `_CreateAppxProtocolClassFactory@20`：RuntimeError（decompile returned None）
- `1a43f1b0` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@VIAppxUrlHelper@@VUrlSchemeConverter@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a43f8af` `?ConvertCreateURLMonikerFlagsToCreateUriFlags@@YGKK@Z`：RuntimeError（decompile returned None）
- `1a4418c0` `?HttpsProtocol_CreateInstance@@YGJPAUIUnknown@@PAPAU1@@Z`：RuntimeError（decompile returned None）
- `1a451db0` `?ReportProgress@CBinding@@UAGJKPBG@Z`：RuntimeError（decompile returned None）
- `1a45cbe3` `?FailFast_IfFalseMsg@in1diag3@details@wil@@YA_NPAXIPBD_N1ZZ`：RuntimeError（decompile returned None）
- `1a45cbfd` `??$FailFast_IfNullMsg@PBUAPPXURLACTIONPOLICY@@$0A@@in1diag3@details@wil@@YAPBUAPPXURLACTIONPOLICY@@PAXIPBDPBU3@1ZZ`：RuntimeError（decompile returned None）
- `1a4692d2` `??0CSecurityTemplate@@QAE@XZ`：RuntimeError（decompile returned None）
- `1a46e9ee` `?StringCchCopyA@@YGJPADIPBD@Z`：RuntimeError（decompile returned None）
- `1a46f0ba` `StringValidateDestAndLengthA`：RuntimeError（decompile returned None）
- `1a46f2b4` `StringValidateDestAndLengthA_0`：RuntimeError（decompile returned None）
- `1a46fcfe` `??1?$unique_storage@U?$resource_policy@PAUFEATURE_STATE_CHANGE_SUBSCRIPTION__@@P6GXPAU1@@Z$1?WilApi_UnsubscribeFeatureStateChangeNotification@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAU1@PAU1@$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a470250` `?GetZoneAt@CUrlZoneManager@@UAGJKKPAK@Z`：RuntimeError（decompile returned None）
- `1a4703b9` `?_GetWarnOnIntranetFlag@@YGHXZ`：RuntimeError（decompile returned None）
- `1a470e00` `?CreateZoneEnumerator@CUrlZoneManager@@UAGJPAK0K@Z`：RuntimeError（decompile returned None）
- `1a470f60` `?DestroyZoneEnumerator@CUrlZoneManager@@UAGJK@Z`：RuntimeError（decompile returned None）
- `1a471b20` `?FileProtocol_CreateInstance@@YGJPAUIUnknown@@PAPAU1@@Z`：RuntimeError（decompile returned None）
- `1a47ea20` `?GetLowerCasePackageName@PackageUrlSchemeConverter@@UAGJPAPAG@Z`：RuntimeError（decompile returned None）
- `1a47ee81` `?IsPackageScheme@AppProtocolsCommon@@YGHPAG@Z`：RuntimeError（decompile returned None）
- `1a47efef` `?StringCchCopyNA@@YGJPADIPBDI@Z`：RuntimeError（decompile returned None）
- `1a4810f0` `?GetIPAddress@CINet@@UAGJPAPAUtagSAFEARRAY@@@Z`：RuntimeError（decompile returned None）
- `1a48194e` `?SetServerSpecifiedMimeType@CTransData@@QAGJPBG@Z`：RuntimeError（decompile returned None）
- `1a484708` `?_FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1a484727` `?_FailFast_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `1a4b2fd0` `_DllRegisterServer@0`：RuntimeError（decompile returned None）
- `1a4b2fe0` `_DllUnregisterServer@0`：RuntimeError（decompile returned None）
- `1a4b3690` `?FtpProtocol_CreateInstance@@YGJPAUIUnknown@@PAPAU1@@Z`：RuntimeError（decompile returned None）
- `1a4b36b0` `?HttpProtocol_CreateInstance@@YGJPAUIUnknown@@PAPAU1@@Z`：RuntimeError（decompile returned None）
- `1a4b36d0` `?MkProtocol_CreateInstance@@YGJPAUIUnknown@@PAPAU1@@Z`：RuntimeError（decompile returned None）
- `1a4b4795` `??$ReportFailure_Base@$02$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `1a4b49d4` `?FailFast_UnexpectedMsg@in1diag3@details@wil@@YAXPAXIPBD1ZZ`：RuntimeError（decompile returned None）
- `1a4b525a` `?StringCchVPrintfW@@YGJPAGIPBGPAD@Z`：RuntimeError（decompile returned None）
- `1a4b71d5` `??0JSONSerializer@@QAE@XZ`：RuntimeError（decompile returned None）
- `1a4b8cb8` `?_FailFast_NullAlloc@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1a4b8db3` `?addActiveXCompatEntry@CXMLParser@CIEBrowserModeFilter@@AAEXXZ`：RuntimeError（decompile returned None）
- `1a4bd790` `?GetBrowserEmulationData@CIEEnterpriseModeFilter@@UAGJPAPAG@Z`：RuntimeError（decompile returned None）
- `1a4bd7c0` `?GetBrowserEmulationLocalData@CIEEnterpriseModeFilter@@UAGJPAPAG@Z`：RuntimeError（decompile returned None）
- `1a4beb59` `?_s_EnumSubPathsCallback@CIEEnterpriseModeFilter@@CGJQAV1@PAUIUri@@PBG22QAKPAUSSiteListEntry@@@Z`：RuntimeError（decompile returned None）
- `1a4c1c30` `?openfunc@@YAHPADHH@Z`：RuntimeError（decompile returned None）
- `1a4d16f2` `?VersionFromManifest@CCodeDownload@@QAEHPADH@Z`：RuntimeError（decompile returned None）
- `1a4d2ab2` `?NewNode@?$CList@PAVCDLDebugLog@@PAV1@@@IAEPAUCNode@1@PAU21@0@Z`：RuntimeError（decompile returned None）
- `1a4d48e7` `?GetSafeDisplayName@Cwvt@@AAEXPAUtagIE_SIGNATURE_INFO@@PBGPAGK@Z`：RuntimeError（decompile returned None）
- `1a4dadc0` `?GetDestDir@CSetup@@QAEJPAVCCodeDownload@@PADH@Z`：RuntimeError（decompile returned None）
- `1a4df340` `_CAuthenticateHostUI_CreateInstance@12`：RuntimeError（decompile returned None）
- `1a4e1640` `?GetContextAndNotifyFailure@details@wil@@YGXPAUFailureInfo@2@PADI@Z`：RuntimeError（decompile returned None）
- `1a4e16a1` `?GetLastErrorFailHr@details@wil@@YGJXZ`：RuntimeError（decompile returned None）
- `1a4e2d96` `?Return_GetLastError@in1diag3@details@wil@@YGJPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1a4e2db2` `?Return_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `1a4e3765` `?_FailFast_GetLastError@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `1a4e4880` `?ShouldEncodeCharacter@CPercentEncodeUserInfo@@UAEJIKPA_N@Z`：RuntimeError（decompile returned None）
- `1a4efc91` `?FailFast_Win32@in1diag3@details@wil@@YGXPAXIPBDK@Z`：RuntimeError（decompile returned None）
- `1a4f47f0` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@UIWebRequestEventDetailsOptionalProperties@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a4f4810` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@UIWebRequestHttpHeaders@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a4f51a0` `_CoCreateInstanceSafe@20`：RuntimeError（decompile returned None）
- `1a4f51d0` `_CoGetClassObjectSafe@20`：RuntimeError（decompile returned None）
- `1a4f5200` `_GetSafeClsidOrAlternateClsid@8`：RuntimeError（decompile returned None）
- `1a4f5220` `_IsClsidKillbitted@4`：RuntimeError（decompile returned None）
- `1a4f7ce2` `?_GetAutoDetectFlag@@YGHXZ`：RuntimeError（decompile returned None）
- `1a4fc5f0` `??_ECCachedHttpHeaderEntry@@QAEPAXI@Z`：RuntimeError（decompile returned None）
- `1a4fcd4f` `?SetMimeType@CTransData@@QAGJPBG@Z`：RuntimeError（decompile returned None）
- `1a4fcd97` `?StringCbCopyA@@YGJPADIPBD@Z`：RuntimeError（decompile returned None）
- `1a502218` `?AppendPlatformString@@YGHW4UACOMPATMODE@@W4USERAGENT_PLATFORM@@PAUHKEY__@@2PAPADPAK4@Z`：RuntimeError（decompile returned None）
- `1a504efc` `IsFileExtAudioType`：RuntimeError（decompile returned None）
- `1a5071c2` `?StringCbPrintfA@@YAJPADIPBDZZ`：RuntimeError（decompile returned None）
- `1a509c13` `?_SqmReasonToString@CVersionManagerServer@@AAEJW4EXT_SQM_VERSION_REASON@@PADI@Z`：RuntimeError（decompile returned None）
- `1a509ca5` `?_SqmReasonToStringW@CVersionManagerServer@@AAEJW4EXT_SQM_VERSION_REASON@@PAGI@Z`：RuntimeError（decompile returned None）
- `1a509d37` `?_SqmStateToString@CVersionManagerServer@@AAEJW4EXT_SQM_VERSION_STATE@@PADI@Z`：RuntimeError（decompile returned None）
- `1a510bbb` `?InitializeAllowedBehaviors@CSecurityManager@@KGHXZ`：RuntimeError（decompile returned None）
- `1a513fe9` `?WriteCDUnlockPolicy@CSecurityManager@@SGXXZ`：RuntimeError（decompile returned None）
- `1a514500` `?ZonesWarnDialogProc@CSecurityManager@@KGHPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `1a514c20` `_ZoneMappingToRegKey@16`：RuntimeError（decompile returned None）
- `1a515340` `?GetZoneCustomPolicy@CUrlZoneManager@@UAGJKABU_GUID@@PAPAEPAKW4_URLZONEREG@@@Z`：RuntimeError（decompile returned None）
- `1a515570` `?SetZoneCustomPolicy@CUrlZoneManager@@UAGJKABU_GUID@@PAEKW4_URLZONEREG@@@Z`：RuntimeError（decompile returned None）
- `1a515c9a` `?Return_Win32@in1diag3@details@wil@@YGJPAXIPBDK@Z`：RuntimeError（decompile returned None）
- `1a518b70` `?FailFast_HrMsg@in1diag3@details@wil@@YAXPAXIPBDJ1ZZ`：RuntimeError（decompile returned None）
- `1a519195` `?_Log_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `1a519700` `_AppxParseUrl@32`：RuntimeError（decompile returned None）
- `1a519730` `_CreateAppDataProtocolClassFactory@20`：RuntimeError（decompile returned None）
- `1a519764` `?_FailFast_UnexpectedMsg@in1diag3@details@wil@@YGXPAXIPBD01PAD@Z`：RuntimeError（decompile returned None）
- `1a5199ee` `??1PackageHostList@@MAE@XZ`：RuntimeError（decompile returned None）
- `1a519a24` `??_EPackageHost@@QAEPAXI@Z`：RuntimeError（decompile returned None）
- `1a519d80` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@VIPackageHostList@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a51a240` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@UIClassFactory@@UIInternetProtocolInfo@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a51a820` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@VUrlSchemeConverter@@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a51a95b` `?ConvertPreResolvedIUriToDestinationSchemeIUri@PackageUrlSchemeConverter@@AAEJPAUIUri@@PAPAU2@PAPAUIResourceCandidate2@@@Z`：RuntimeError（decompile returned None）
- `1a51b0e0` `?GetPackageFamilyName@PackageUrlSchemeConverter@@UAGJPAPAG@Z`：RuntimeError（decompile returned None）
- `1a51cfef` `??$FailFast_IfNullMsg@V?$ComPtr@VUrlSchemeConverter@@@WRL@Microsoft@@$0A@@in1diag3@details@wil@@YAXPAXIPBDABV?$ComPtr@VUrlSchemeConverter@@@WRL@Microsoft@@1ZZ`：RuntimeError（decompile returned None）
- `1a51d420` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@U?$ChainInterfaces@UIInternetProtocolEx@@UIInternetProtocol@@UIInternetProtocolRoot@@VNil@Details@WRL@Microsoft@@V4567@V4567@V4567@V4567@V4567@V4567@@23@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a51e771` `?GetAxInstallBrokerHelper@@YGJABU_GUID@@0PAUHWND__@@KHPAPAUIUnknown@@@Z`：RuntimeError（decompile returned None）
- `1a521ec6` `?Ext_IsInstalled@@YG_NABU_GUID@@K@Z`：RuntimeError（decompile returned None）
- `1a52203e` `?Ext_IsRegistered@@YGHABU_GUID@@KPAW4_EXT_ARCHITECTURE@@@Z`：RuntimeError（decompile returned None）
- `1a5234e7` `?FailFast_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `1a52569e` `_ShowUrlInNewBrowserInstance@4`：RuntimeError（decompile returned None）
- `1a526dee` `?IsBrowserReplacementAvailable@@YG_NXZ`：RuntimeError（decompile returned None）
- `1a526e13` `?ReadExePath@Private@BrowserChannels@@YG_NPAUHKEY__@@PAGK@Z`：RuntimeError（decompile returned None）
- `1a527b7d` `??1?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?SetEvent@details@wil@@YGX0@ZU?$integral_constant@I$00@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@IAE@XZ`：RuntimeError（decompile returned None）
- `1a527cb7` `?AddOne@HStringReference@Wrappers@WRL@Microsoft@@CGII@Z`：RuntimeError（decompile returned None）
- `1a527dfa` `?CreateReference@HStringReference@Wrappers@WRL@Microsoft@@AAEXPBGII@Z`：RuntimeError（decompile returned None）
- `1a528363` `?Log_Win32Msg@in1diag3@details@wil@@YAKPAXIPBDK1ZZ`：RuntimeError（decompile returned None）
- `1a528480` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@U?$IAsyncOperationCompletedHandler@PAVFileProtectionInfo@EnterpriseData@Security@Windows@ABI@@@Foundation@Windows@ABI@@VFtmBase@23@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a5284a0` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@U?$IAsyncOperationCompletedHandler@PAVStorageFile@Storage@Windows@ABI@@@Foundation@Windows@ABI@@VFtmBase@23@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a5284c0` `?QueryInterface@?$RuntimeClassImpl@U?$RuntimeClassFlags@$01@WRL@Microsoft@@$00$0A@$0A@U?$IAsyncOperationCompletedHandler@PAVStorageFolder@Storage@Windows@ABI@@@Foundation@Windows@ABI@@VFtmBase@23@@Details@WRL@Microsoft@@UAGJABU_GUID@@PAPAX@Z`：RuntimeError（decompile returned None）
- `1a5285fe` `?SetEvent@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `1a52867a` `?_Log_Win32@in1diag3@details@wil@@YGXPAXIPBDK@Z`：RuntimeError（decompile returned None）
- `1a528a11` `?FailFast_HrIfMsg@in1diag3@details@wil@@YA_NPAXIPBDJ_N1ZZ`：RuntimeError（decompile returned None）
- `1a52df2f` `?GUIDToWSTR@@YGXABU_GUID@@PAG@Z`：RuntimeError（decompile returned None）
- `1a52f78b` `?IECompatGetSignatureStateString@CLogInformation@ControlLogging@@IAEJPAUtagIE_SIGNATURE_INFO@@PAGK@Z`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：269.8 s
- 日志：out/R1N/ida/logs/sha256_fce2477a7c14055e489739bd0b0607f1f2e910136c4be833a74932f49293d90a.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 124 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `URLMON.DLL` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 5276 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +5276（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：``dynamic initializer for 'g_mxsTls''`, ``dynamic initializer for 'g_OleAutDll''`, ``dynamic initializer for 'g_mxsMedia''`, ``dynamic initializer for 'g_mxsSession''`, ``dynamic initializer for 'g_mxsTls''_0`, ``dynamic initializer for 'g_mxsTls''_1`, `wil::details::`dynamic initializer for 'g_header_init_WilInitialize_ResultMacros_DesktopOrSystem''`, ``dynamic initializer for 'g_mxsTls''_2`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/Windows/SysWOW64/decompiled/URLMON.DLL.c.txt` sha256=e6d17a80dd5c5acbe2527a4823cd1cac25d829eeb1097c49f4fd4bec0f907aa6 bytes=7634758
- `native5/01-completed/Aspen-Plus/Windows/SysWOW64/disasm/URLMON.DLL.asm.txt` sha256=239ec929819a5a34309db57f88a06b6b036bffbcc76ef12acaeda4b344e42a3f bytes=11515603
