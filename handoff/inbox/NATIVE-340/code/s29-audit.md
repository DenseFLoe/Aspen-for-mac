# NATIVE-340 s29 更正与核验（脚本生成）

## 事实断言：13 项，失败 0 项

- PASS field 0x04000055 is GUID cb2f6723 at RVA 0x6330（_GUID_cb2f6723_ab3a_11d2_9c40_00c04fa30a3e @ 0x6330）
- PASS field 0x04000056 is GUID cb2f6722 at RVA 0x6320（_GUID_cb2f6722_ab3a_11d2_9c40_00c04fa30a3e @ 0x6320）
- PASS 0x6330 bytes are GUID cb2f6723（bytes）
- PASS 0x6320 bytes are GUID cb2f6722（bytes）
- PASS IL_0003 reads field 0x04000056 (cb2f6722) first and stashes it at IL_000D（ldc.i4.0  | conv.i8  | stloc.0  | ldsflda 0x04000056 | call 0x0600002F | stloc.3  | ldsflda 0x04000055 | call 0x0600002F | ldloc.3  | call 0x0A000039 | stloc.s 0x4 | ldloca.s 0x4）
- PASS callee is GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid)（GetRuntimeInterfaceAsIntPtr）
- PASS 0x29D0 is lea rax,[rip+disp] -> 0x19B78（bytes 488d05a1710100 -> 0x19b78）
- PASS qword[0x1800061B8] == 0x1800048B0（slot value）
- PASS 0x48B0 is FF E0 (JMP RAX)（bytes）
- PASS 0x19B78 sits in the zero-filled tail of writable .data（raw ends 0x19a00, virtual ends 0x19b80）
- PASS 0x2187/0x218B guard the empty slot before the read（cmp qword ptr [rax],0 ; jz）
- PASS 0x21A7 loads R9 from [0x1800061B8]（mov r9,[rip+0x400a]）
- PASS five in-module ctor newobj sites（5）

## CLSID / IID（按原件压栈次序）

- 调用：System.Runtime.InteropServices.RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid)
- 次序：IL pushes arg1 first (stashed at IL_000D) then arg0, reloaded at IL_0018
- arg0 clsid = {CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}，字段 0x04000055（_GUID_cb2f6723_ab3a_11d2_9c40_00c04fa30a3e）@ 0x6330，16 字节 23672fcb3aabd2119c4000c04fa30a3e
- arg1 riid = {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}，字段 0x04000056（_GUID_cb2f6722_ab3a_11d2_9c40_00c04fa30a3e）@ 0x6320，16 字节 22672fcb3aabd2119c4000c04fa30a3e

## R9 链

- R9 = qword[0x1800061B8] = 0x1800048B0 (JMP RAX); RAX = qword[0x19B78]; 0x19B78 = LEA at 0x29D0 (48 8D 05 A1 71 01 00); slot lies in the zero-filled tail of writable .data; 0x2187/0x218B reject the empty slot before the single read
- 槽 0x19B78 由 0x1800029D0 (lea rax,[rip+0x171A1]) 返回；空槽先拦：0x2187 cmp qword ptr [rax], 0 / 0x218B jz 0x21B1；单次读取：0x21A4 mov rax, [rbx]；守卫跳板：0x48B0 FF E0 JMP RAX；未决原因：callback slot writer and object type are runtime values

## 计数

| 指标 | 值 |
| --- | --- |
| rows | 1105 |
| funcs | 354 |
| external | 228 |
| boundary | 303 |
| unresolved | 28 |
| managed_to_managed_ctor_edges | 5 |
| slot_jumps_original | 237 |
| distinct_methoddef_targets | 122 |
| fixup_edges | 237 |
| fixup_stubs_added | 228 |

指纹：53 个文件，code/s29-fingerprints.json。
