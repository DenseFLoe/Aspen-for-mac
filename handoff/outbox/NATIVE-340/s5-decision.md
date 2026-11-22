# NATIVE-340 第五号分配的复验裁定

**returned**。该轮 11 份交付可归档为补证。WrapSaveMergeNNFiles.dll 仍为静态验收未通过。执行方 tietoumiao，assigned_seq=5，候选提交 `a0b8a11853f70d32870b9d0aa15267572c1ffb0a`。[产物 PR #393](https://github.com/DenseFLoe/Aspen-for-mac/pull/393) · [首轮退回项](s1-decision.md)

原件来自提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/340/WrapSaveMergeNNFiles.dll`，实测 107,048 字节，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。使用 main `2ffe7e14d34002d992c29b14a6bf3e23e04f0256` 的原生覆盖标准、续领卡和检查器。从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original issue-materials/340/WrapSaveMergeNNFiles.dll`，退出 2，输出 `checked 1007 coverage rows, 256 tool-native entries, 293 call records, 0 declared gaps`。

## 已核实的补正

- 原件有 563 个 TypeDef、188 个 MethodDef，后者分为 167 个 IL 方法体、19 个原生实现、2 个无 RVA 声明。交付已注明分析器记录 255 项、手工补入 RVA 0x3660 一项。0x3660 和方法 0x06000085 的覆盖行现指向同一个可编辑实现。
- 从原件 IL 方法头和指令解出操作码与 token，重新核对首轮 24 条记录，均为本模块 IL 调用原生 MethodDef；上轮误报的 12 条 external 均已修正。此次 61 条 IL 到原生的直接调用全部匹配，15 处 calli 全有行号。51 处直接指向原件 IAT 的原生调用或跳转也已登记，包括首轮点名的四处 KERNEL32 调用。
- 以 System.Reflection.Metadata 读取各类型的实际 MethodDef 列表，与 `types.cs`、`metadata.asm` 中每个类型下面逐项列出的子 token 对比。563 个类型、188 个方法逐项吻合。WrapCall 有 0x060000A1 和 0x060000A2 两个子项。

## 剩余缺口与恢复条件

1. **纠正 RVA 0x3660 的含义。** 原件连续 14 字节为 `65488b042530000000488b4008c3`。C 的两次取值与原指令吻合。Windows x64 头文件 `winnt.h` 的 `NtCurrentTeb` 以 `__readgsqword(FIELD_OFFSET(NT_TIB,Self))` 取得当前 TEB。64 位 NT_TIB 的 Self 偏移是 0x30，StackBase 偏移是 8。返回值为当前线程的 StackBase。请同步纠正 `native.c` 中的变量名和 ImageBaseAddress 注释、提交说明中的 PEB 解释，保留原来的两次读取。
2. **补齐原生到托管的边界。** 原件与交付原生清单的 1,462 行指令字节相符。清单中有 141 处非 IAT 间接调用或跳转，交付登记 4 处，遗漏 137 处。原件 CLR 头的 VTableFixups 位于 RVA 0x16600，长 1,896 字节。对其中每个槽读取宽度和原始 token，再与间接跳转目标槽相交，能将 126 处遗漏确定为跳向有 IL 方法体的 MethodDef。例如 RVA 0x5004 跳向槽 0x19018，对应 token 0x06000001、IL 方法体 RVA 0x10a0。请将这 126 处登记为 native → managed，余下 11 处写明可确定的中转层或列为未决。[137 处缺行](s5-missing-native.csv) · [126 处跨界对应](s5-native-fixup-targets.csv)
3. **补齐 16 处外部构造器调用。** 直接解码 167 个原始 IL 方法体，对调用 token 追踪到 MemberRef 及其外部程序集，含泛型 TypeSpec。交付已有 162 条托管 external，此外 16 条 `newobj` 调用外部构造器，均可定位。如 0x0600001B 的 IL_003B 调用 mscorlib 的 ArgumentException 构造器，请按 IL 位置和外部成员登记。[16 处原件位置](s5-missing-managed.csv)
4. **修正方法范围和声明。** `metadata.asm` 的 19 个非空类型标题都把首末 MethodDef token 各减一。首个标题甚至写 0x06000000；WrapCall 标题写 A0–A1，子行与原件均为 A1–A2。请从同一组真实 token 生成标题并明确空类型没有方法。同时区分类型成员索引和可编辑声明。`types.cs` 把 WrapCall.WrapperSaveMergennFiles 声明为无参，原件 0x060000A1 的方法签名 `20 02 01 0f 20 71 04 0f 20 71 04` 有两个显式参数。若保留可编辑声明，应与原签名对应。[19 个类型范围](s5-methodlist-ranges.csv)

按上述固定输入修订调用表、范围、声明说明及指纹后，提交新的 PR head。上游逐项复核已知差异。原先核实的 61 条托管到原生调用和 188 个成员归属可直接沿用。

## 本轮 SHA-256

| 文件 | SHA-256 |
| --- | --- |
| 主干检查器 | `6e21abd6043b2905eccbce2cdf2a21a8c773ff31070938fdf27cc5bb7c9d7241` |
| s5-started.md | `69936392cc70417f21f41d71e1717fc3c98216da1a4cb3d125fbf3ef9b519ab4` |
| s5-submission.md | `9064c2394a7d965275946a2e1519ed659b0b472e191fc1eb67b692e4bfbecbd3` |
| calls.csv | `33a5f423eb811d97bc9c98844aa40706a06b0f90f3e719943989c3f7c40f3f1e` |
| coverage.csv | `d878fa1d237d50cf52c5500a40b6d922d8e8842f98c31c949be99cff9377591f` |
| native.c | `2c338f270e13e45c454eec88a7346bffd1591000c52d0632321e6cf36b2b5798` |
| metadata.asm | `2cfe0ad832d668bd96ac5c744ac2704981f136bccb6751dfc8affd36cbc93c6b` |
| types.cs | `900e984b8c18ed6f8ba736d1065f578f479a78779c68d9e568cfb552e17c76f8` |
| s5-methodlist-ranges.csv | `b1fe9275eb4da01cf7af5fac8bd71118d0be97b9abba2c4a66d6da08855a0194` |
| s5-missing-managed.csv | `2db1e4c61aa2c0e5b1d36445e5918ea4d1196037fe51b58b2a4cbb774c004a40` |
| s5-missing-native.csv | `03c1efef42da33e85f713e6f78e2d984677d9ef77fe5e96c25bdb0c6b1b29819` |
| s5-native-fixup-targets.csv | `c5b93ac648c941b5a788ac856af8f96c232dd230d09830d8b81664b6c18d33f3` |
