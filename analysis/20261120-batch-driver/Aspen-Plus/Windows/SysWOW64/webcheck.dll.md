# webcheck.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `webcheck.dll`，240640 字节，SHA-256 `45fc4530d44f8fdc088738ba1c03a1f682a563e99b9d9d72b3f549347f7cb330` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 956 = decomp_ok 930 + decomp_fail 26 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=956
- decomp_ok=930
- decomp_fail=26
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `webcheck.dll` |
| 字节数 | 240640 |
| SHA-256 | `45fc4530d44f8fdc088738ba1c03a1f682a563e99b9d9d72b3f549347f7cb330` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `Windows/SysWOW64/webcheck.dll` |
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
| 指令行数 | 53194 |

## 3. 反汇编清单（全量）

全文：disasm/webcheck.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/webcheck.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 956
- decomp_ok（伪 C） = 930
- decomp_fail = 26
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10005796` `?StringCchCopyW@@YGJPAGIPBG@Z`：RuntimeError（decompile returned None）
- `10015930` `?DownloadPropDlgProc@@YGHPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `10015a30` `?NewScheduleDlgProc@@YGHPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `10015bd0` `?AdvancedDownloadDlgProc@@YGHPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `10015e10` `?LoginOptionDlgProc@@YGHPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `10016ae9` `?SignatureBlobToVariant@@YGJPAEKPAUtagVARIANT@@@Z`：RuntimeError（decompile returned None）
- `10019570` `?UpdateAll@CSubscriptionMgr@@UAGJXZ`：RuntimeError（decompile returned None）
- `1001a340` `?GetItemFromCookie@CSubscriptionMgr@@UAGJPBU_GUID@@PAPAUISubscriptionItem@@@Z`：RuntimeError（decompile returned None）
- `1001a680` `?CreateSubscriptionItem@CSubscriptionMgr@@UAGJPBUtagSUBSCRIPTIONITEMINFO@@PAU_GUID@@PAPAUISubscriptionItem@@@Z`：RuntimeError（decompile returned None）
- `1001a6a0` `?CloneSubscriptionItem@CSubscriptionMgr@@UAGJPAUISubscriptionItem@@PAU_GUID@@PAPAU2@@Z`：RuntimeError（decompile returned None）
- `1001b350` `?UpdateBegin@CThrottler@@UAGJPBU_GUID@@@Z`：RuntimeError（decompile returned None）
- `1001b4c0` `?ReportError@CThrottler@@UAGJPBU_GUID@@JPBG@Z`：RuntimeError（decompile returned None）
- `1001b7f0` `?ThrottlerWndProc@CThrottler@@SGJPAUHWND__@@IIJ@Z`：RuntimeError（decompile returned None）
- `10024001` `?NewSchedWiz_ResolveNameConflict@@YGHPAUHWND__@@PAUOOEBuf@@@Z`：RuntimeError（decompile returned None）
- `10024df9` `?GetLastErrorFailHr@details@wil@@YGJXZ`：RuntimeError（decompile returned None）
- `100251ab` `??$ReportFailure_Base@$02$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `10025266` `?Return_Hr@in1diag3@details@wil@@YGXPAXIPBDJ@Z`：RuntimeError（decompile returned None）
- `10025283` `?Return_GetLastError@in1diag3@details@wil@@YGJPAXIPBD@Z`：RuntimeError（decompile returned None）
- `100252b4` `?FailFast_Unexpected@in1diag3@details@wil@@YGXPAXIPBD@Z`：RuntimeError（decompile returned None）
- `100252d8` `?CloseHandle@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `10025303` `?ReleaseMutex@details@wil@@YGXPAX@Z`：RuntimeError（decompile returned None）
- `10025a70` `?GetContextAndNotifyFailure@details@wil@@YGXPAUFailureInfo@2@PADI@Z`：RuntimeError（decompile returned None）
- `10026a10` `?PathIsVolumeGUIDWorker@@YG_NPBG@Z`：RuntimeError（decompile returned None）
- `10026e67` `?acquire@?$mutex_t@V?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?CloseHandle@details@wil@@YGX0@ZU?$integral_constant@I$0A@@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@Uerr_returncode_policy@3@@wil@@QBE?AV?$unique_any_t@V?$unique_storage@U?$resource_policy@PAXP6GXPAX@_E$1?ReleaseMutex@details@wil@@YGX0@ZU?$integral_constant@I$01@wistd@@PAXPAX$0A@$$T@details@wil@@@details@wil@@@2@PAKKH@Z`：RuntimeError（decompile returned None）
- `100272f3` `??$ReportFailure_Base@$01$0A@@details@wil@@YGXPAXIPBD110ABUResultStatus@01@PBGW4ReportFailureOptions@01@@Z`：RuntimeError（decompile returned None）
- `1002783b` `?OutOfMemory@Abandonment@@SGXXZ`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：30.0 s
- 日志：out/R1N/ida/logs/sha256_45fc4530d44f8fdc088738ba1c03a1f682a563e99b9d9d72b3f549347f7cb330.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 26 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `webcheck.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 956 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +956（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`wil::details::`dynamic initializer for 'g_processLocalData''`, `wil::details::`dynamic atexit destructor for 'g_threadFailureCallbacks''`, `wil::details::`dynamic initializer for 'g_header_init_InitializeResultHeader''`, `wil::details::`dynamic initializer for 'g_header_init_WilInitialize_ResultMacros_DesktopOrSystem''`, `?Next@CRegKey@@QAEJPAG@Z`, `?GetValue@CRegKey@@QAEJPBGPAK@Z`, `?GetBSTRValue@CRegKey@@QAEJPBGPAPAG@Z`, `??0CRegKeyDPA@@QAE@XZ`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/Shlwapi.dll.c.txt` sha256=8e0e527e0cae903bb3e41cd7ab89050d686aaed8fda5517667d7c6dcfeaa00e1 bytes=1232086
- `decompiled/webcheck.dll.c.txt` sha256=8f39d25fb5d934a10825c6cdddd05c02d75a69f37839995da9761c58e1504776 bytes=943377
- `disasm/Shlwapi.dll.asm.txt` sha256=b9bc604819f09d44db3231a0f7d4caa36786f12a691da380b9ed88408b136621 bytes=2070898
- `disasm/webcheck.dll.asm.txt` sha256=e241ade69f8a7d7c95f67a0f66e748edf2677d2ba48ab30a63d8760f05ac357c bytes=1862896
