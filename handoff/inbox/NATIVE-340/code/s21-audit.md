# NATIVE-340 s21 逐项核对（脚本生成，勿手改）

上游 out/up340/s17-recheck.json 的 111 条逐址证据 + 本交付的 126 条已核定边，合起来覆盖原件的全部槽跳转。

## 1. 111 条有直接前驱的槽跳转

- 逐址校验（指令字节==证据、jmp 目标==slot、slot 在 VTableFixups 内且 Type==flags、槽值==token、token 的 MethodDef RVA==证据）：**111/111 通过，0 条失败**。
- 登记状态：missing 106、unresolved 5（后者原在 calls.csv，本轮按同一证据升级为 boundary）。
- 调用者证据：每个 site 都在 .nep 内被一条直接跳转命中（前驱形态统计：eb08 x111），逐条 predecessor_rva / predecessor_bytes 见 code/s21-extra-sites.csv。
- 逐项字段：.nep 源 RVA、指令字节、槽 RVA、flags、方法令牌、方法 RVA、前驱 RVA 与字节。

## 2. 三个量分开

| 量 | 值 | 依据 |
| --- | --- | --- |
| 原件槽跳转总数 | 237 | code/vtable-fixups.csv（237 entry / 237 槽）；126 已核定 + 111 本轮 = 237 全部进表 |
| 不同 MethodDef | 122 | 126 条边里有 4 个 token 各出现两次 |
| 运行期真正落点 | 未定（0 个静态已知） | 槽由 CLR 加载器改写，静态只能读到 MethodDef token；恢复条件写在各 boundary 行的 note |

## 3. 122 桩改造与回编

- code/native-fixup-sites.c 由「只有注释的空壳」改为 **naked 尾跳实现**：函数体唯一指令是 `jmp *fixup_slot_XXXX(%rip)`，无 prologue/epilogue、不碰参数与返回，语义上等价于原件的 `jmp qword ptr [rip+slot]`。
- 每个桩的注释记录接口（参数/返回由被调方继承）与动态边界（槽由加载器填运行期入口）。
- 回编：`zig cc -target x86_64-windows-gnu -O2 -c` 编译两个 C 文件，再解析 AMD64 COFF，逐个符号校验「6 字节 FF 25 + 指令+2 处 REL32 重定位指向该桩的 slot 符号」。

| 文件 | 桩数 | 回编通过 | 失败 | 目标文件 SHA-256 |
| --- | --- | --- | --- | --- |
| code/native-fixup-sites.c | 122 | 122 | 0 | e433fb88a91b63210e0081559b0b6cde |
| code/native-fixup-sites-s21.c | 106 | 106 | 0 | 6b0aea0f5c0747d109207be6e48b25e5 |

回编链：C 的 `jmp *slot(%rip)` -> COFF 里 `FF 25 00 00 00 00` + REL32(slot) -> 链接后 disp = slot - (stub+6)，即原件同一尾跳。逐桩结果见 code/recompile-verify.json。

## 4. 0x0a000019 的 TypeSpec 属主

- 原元数据：MemberRef 0x0A000019 的 Class 是 TypeSpec#2；TypeSpec#2 签名 15 12 80 8D 01 1C = GENERICINST CLASS TypeDefOrRef(TypeRef#35 LinkedList1) genargc 1 arg ELEMENT_TYPE_OBJECT。
- TypeRef#35 = System.Collections.Generic.LinkedList`1，ResolutionScope = AssemblyRef#4 System。
- 结论：[System]System.Collections.Generic.LinkedList<System.Object>::.ctor()，已写入 code/newobj.csv 与 calls.csv 对应行。

## 5. 0x3660 说明

- 源码与说明移除未经原件支持的 PEB 命名，改为寄存器/地址语义：GS:[0x30] 取得一个指针，[RAX+0x8] 一次间接加载，随后 ret（14 字节）。

## 6. 当前计数

| 指标 | 值 |
| --- | --- |
| rows | 1105 |
| funcs | 354 |
| external | 226 |
| boundary | 298 |
| unresolved | 30 |
| gaps | 0 |
| slot_jumps_original | 237 |
| distinct_methoddef_targets | 122 |
| runtime_landing_known | 0 |
| fixup_edges | 237 |
| fixup_edges_verified | 237 |
| fixup_stubs_added | 228 |
| fixup_stubs_s17 | 122 |
| fixup_stubs_s21 | 106 |

calls 行数：554（external 226 / boundary 298 / unresolved 30）。
