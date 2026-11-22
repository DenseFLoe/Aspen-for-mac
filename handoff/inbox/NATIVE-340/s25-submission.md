# NATIVE-340 s25 提交

- 分支：tietoumiao/native-340-s25（基于 #438 @ 24fdc60d）
- head：见 #13
- 上游脚本：`check-s21-438.py` exit **0**（独立回编 122 + 106 桩、237 槽全对上）
- 受信判定器：exit **2**（结构齐备 + 已申报未决）

## 必做前置（原始输出）

```
$ python -B out/localrepo3/handoff/assignments/check-native-coverage.py NATIVE-340 --original _t13/orig/WrapSaveMergeNNFiles.dll --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 554 call records, 0 declared gaps
exit code: 2

$ python -B out/up340/check-s21-438.py <原件> handoff/inbox/NATIVE-340 <checker> .local/zigpkg/ziglang/zig.exe <work>
{"verified_slots": 237, "methoddef_targets": 122, "extra_predecessors": 111,
 "recompiled": [{"path": "code/native-fixup-sites.c", "functions": 122},
                {"path": "code/native-fixup-sites-s21.c", "functions": 106}],
 "call_table": {"boundary": 298, "external": 228, "unresolved": 28},
 "metrics_fixup_edges_ok": 237, "metrics_fixup_edges_verified": 237}
exit code: 0
```

它报的唯一差异项就是指标不一致（`metrics_fixup_edges_ok=126` vs `verified=237`）与 28 条未决；本轮已修。

## 三项（成因 / 修正 / 自证）

# 1) 两个 15 分开
code/s25-unresolved-managed.csv（15 条，全部 IL calli，逐条带调用方方法名）与
code/s25-unresolved-native.csv（15 条 = 4 寄存器间址 + 9 CFG 守卫调用 + 2 守卫跳板）分开出表，没有合并成一列。

# 2) MethodDef 0x06000030 四项
| 项 | IL_0041 | IL_004F |
| --- | --- | --- |
| 原件 IL | IL_0041 calli 0x11000044 | IL_004F calli 0x11000043 |
| 槽 | 0x68（IL_0038 ldc.i4.s 0x68 + conv.i8 + add + ldind.i8） | 0x10（IL_004A ldc.i4.s 0x10 同构） |
| 签名 | 0x11000044 blob 01022051206108180f0f1187fc（int32 modopt(CallConvCdecl,IsLong)(native int, ptr ptr valuetype)） | 0x11000043 blob 0101205120610918（uint32 modopt(...)(native int)） |
| 对象生产路径 | loc0 = IntPtr::ToPointer(RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(FromGUID(GUID), GUID)) | 同一 loc0 |

字段证据：0x04000055/0x04000056 的字段名即 GUID 文本（…cb2f6723… / …cb2f6722…）→ CLSID {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E} / IID {CB2F6723-…}（CLR 宿主接口）。
两条已从 unresolved 改为 external：callee 写明 COM vtable 槽 + 签名令牌，note 写明 **运行期依赖＝接口实际实现**（静态只到槽）。剩余托管未决 13、原生 15。

# 3) 原生 R9
0x21A7 的 `4C 8B 0D 0A 40 00 00` = `mov r9, qword ptr [0x1800061B8]`，槽值 `0x1800048B0` = `_guard_dispatch_icall`；同函数 0x21A4 `48 8B 03` = `mov rax,[rbx]` 才是真正被调者（CFG 守卫后的对象 vtable 槽 0x0，对象来自 0x1800029D0）。
**R9 来源已查到**，该行保留 unresolved（对象类型运行期），note 写全链与恢复条件。

# 4) 指标对齐（此前只对了一套）
| 指标 | 旧 | 新 |
| --- | --- | --- |
| fixup_edges_ok | 126 | **237** |
| fixup_edges_verified | 237 | 237 |
| fixup_edges_historical | 无 | 126 |
| fixup_edges_s21 | 无 | 111 |
| fixup_edges_total | 无 | 237 |

code/s25-audit.md 与 metrics.json 同步；上游脚本现在读到的两值一致（237/237）。

## 沿用（未重做）
#438 的 237 条槽跳转、228 个回编桩、1105 条 coverage、354 个原生入口全部保留；本轮只动 3 条调用记录 + 指标。

## 产物
calls.csv（554 行：external 228 / boundary 298 / unresolved 28）、metrics.json、run.json、
code/s25-unresolved-managed.csv、code/s25-unresolved-native.csv、code/s25-verdict-0x06000030.json、
code/s25-audit.md、code/s25-fingerprints.json（逐文件 SHA-256）。

复现：`python -B tool/audit_340_s25.py` → 上面两条判定命令。
