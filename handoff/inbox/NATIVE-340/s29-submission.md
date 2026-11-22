# NATIVE-340 s29 提交

- 分支：tietoumiao/native-340-s29（基于 tietoumiao/native-340-s25 @ ad325a41）
- head：见 #13
- 判定：`python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <固定原件> --submission handoff/inbox/NATIVE-340` → exit 2

## 三条更正（都由原件字节重新推导，脚本 13 项断言全过）

### ① CLSID / IID 参数文本（上一版反了）

按原件 IL 的压栈次序：

| IL | 指令 | 作用 |
| --- | --- | --- |
| IL_0003 | `ldsflda 0x04000056`（RVA 0x6320，GUID cb2f6722） | 取 **riid** 值 |
| IL_0008 | `call 0x0600002F`（`<CrtImplementationDetails>.FromGUID`） | 转 IntPtr |
| IL_000D | `stloc.3` | **暂存第二参数（riid）** |
| IL_000E | `ldsflda 0x04000055`（RVA 0x6330，GUID cb2f6723） | 取 **clsid** 值 |
| IL_0018 | `ldloc.3` | **重载 riid**，成为最后一压的实参 |

`GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid)` 的 arg0 = clsid、arg1 = riid，
所以最后一压的是 riid、先留在栈上的是 clsid：

- **clsid = {CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}**，字段 `0x04000055` @ RVA 0x6330
- **riid = {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}**，字段 `0x04000056` @ RVA 0x6320

上一版把两者写反，本轮 calls.csv 两条 calli 的 note/callee 已按上表重写。

### ② 0x21AE 的 R9 全链

```
0x217F  call 0x1800029D0            -> RAX = 0x19B78
        0x29D0: 48 8D 05 A1 71 01 00   lea rax, [rip+0x171A1]   ; 槽地址由该 LEA 返回
0x2184  mov rbx, rax
0x2187  cmp qword ptr [rax], 0      ; 先拦空槽
0x218B  jz  0x21B1                  ; 空则跳过
0x21A4  mov rax, [rbx]              ; 对固定回调槽 0x19B78 的单次读取
0x21A7  mov r9, [0x1800061B8]       ; = 0x1800048B0
0x21AE  call r9                     ; 0x48B0: FF E0 = JMP RAX
```

槽 0x19B78 位于**可写 .data 的零填充尾部**（raw 到 0x19A00，虚拟到 0x19B80，未初始化），
因此静态只能确认「固定槽 + 单次读取 + 空槽先拦」，写入者与被调实现仍是运行期。

### ③ 五条本模块构造调用

| caller MethodDef | newobj token | 目标 |
| --- | --- | --- |
| 0x06000020 | 0x060000A2 | WrapSaveMergeNNFiles.WrapCall::.ctor |
| 0x0600002B | 0x060000AE | ModuleLoadExceptionHandlerException::.ctor |
| 0x0600002C | 0x060000AC | ModuleLoadException::.ctor |
| 0x0600002D | 0x060000AB | ModuleLoadException::.ctor |
| 0x060000B4 | 0x060000B5 | ModuleUninitializer::.ctor |

class=boundary（managed -> managed，本模块），逐条带 IL 偏移与目标 TypeDef，见 `code/internal-ctor-sites.il`。

## 指标

| 指标 | 值 |
| --- | --- |
| calls 行 | 559（external 228 / boundary 303 / unresolved 28） |
| boundary 分解 | 298 旧 + 5 本模块构造 |
| coverage / native-functions | 1105 / 354（未变） |
| 237 槽跳转 / 122 MethodDef / 228 桩 | 沿用未重做 |
| 断言 | 13 项全过 |

## 判定命令与原始输出

```
$ python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original _t13/orig/WrapSaveMergeNNFiles.dll --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2
```

## 产物

code/s29-verdict-0x06000030.json（13 项事实断言 + 参数绑定 + R9 链）、code/internal-ctor-sites.il、
code/s29-audit.md、code/s29-fingerprints.json、更新后的 calls.csv / metrics.json。
## 上游脚本（必跑，5 参数形式）

```
$ PYTHONPATH=.local/pylibs python -B handoff/outbox/NATIVE-340/check-s21-438.py <原件> handoff/inbox/NATIVE-340 \
      handoff/assignments/check-native-coverage.py .local/zigpkg/ziglang/zig.exe <work>
exit code: 0
verified_slots 237 / methoddef_targets 122 / extra_predecessors 111
call_table {boundary: 303, external: 228, unresolved: 28}
metrics_fixup_edges_ok 237 / metrics_fixup_edges_verified 237
recompiled code/native-fixup-sites.c 122 + code/native-fixup-sites-s21.c 106 (verified_source_site_count 228)
remaining 28
```

脚本对 native.c 的 `PEB` 断言、`0x3660` 14 字节断言、237 槽逐址断言、228 桩独立回编断言全部通过。
（本机 `python` 缺 pefile/capstone，脚本需 `PYTHONPATH=.local/pylibs`；Zig 需把 cache 指到工作区内。）
