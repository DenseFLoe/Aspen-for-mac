# NATIVE-340 s25 逐址核验（脚本生成，勿手改）

## 1. 未决两族（分开列）

- 托管 15 条：code/s25-unresolved-managed.csv（全部是 IL calli）
- 原生 15 条：code/s25-unresolved-native.csv（4 处寄存器间址 + 9 处 CFG 守卫调用 + 2 处守卫跳板）

## 2. MethodDef 0x06000030 四项核对

| 项 | IL_0041 | IL_004F |
| --- | --- | --- |
| 原件 IL | IL_0041 0x29 calli 0x11000044 | IL_004F 0x29 calli 0x11000043 |
| 槽 | 0x68 | 0x10 |
| 签名令牌 / blob | 0x11000044 / 01022051206108180f0f1187fc | 0x11000043 / 0101205120610918 |
| 对象生产路径 | 同一 loc0：loc0 = IntPtr::ToPointer(RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(FromGUID(GUID), GUID)) -> raw COM interface pointer for CLSID {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E} / IID {CB2F6723-AB3A-11D2-9C40-00C04FA30A3E} (CLR hosting interface) | 同一 loc0 |

IL 路径：IL_0003 ldsflda 0x04000056 ; IL_0008 call 0x0600002F ; IL_000E ldsflda 0x04000055 ; IL_0013 call 0x0600002F ; IL_0019 call 0x0A000039 ; IL_0020 ldloca.s 0x4 ; IL_0022 call 0x0A00001D

## 3. 原生 R9 来源

- 0x21A7 mov r9, qword ptr [rip+0x400a] -> [0x1800061B8] -> _guard_dispatch_icall (0x0x48B0)
- 真正被调者：RAX = qword ptr [RBX] (set at 0x21A4: 48 8B 03), RBX from 0x1800029D0
- 结论：CFG 守卫后的对象 vtable 槽 0x0 调用；R9 已查明，剩余变量是对象类型（运行期）

## 4. 指标对齐（全量 / 历史子集）

| 指标 | 值 | 含义 |
| --- | --- | --- |
| fixup_edges_total | 237 | 原件 .nep 全部槽跳转 |
| fixup_edges_ok | 237 | 全量逐址验证通过（126 + 111） |
| fixup_edges_verified | 237 | 同上，供上游脚本读取 |
| fixup_edges_historical | 126 | s17 已交付的历史子集 |
| fixup_edges_s21 | 111 | s21 补登子集 |

## 5. 本轮主表变化

- 2 条托管 calli -> external（槽 0x68 / 0x10，签名令牌与 blob 逐条登记）
- 1 条原生 0x21AE -> 保留 unresolved，note 写入完整 R9 链（守卫 0x48B0 + RAX=[RBX]）
- 计数：external 228 / boundary 298 / unresolved 28
