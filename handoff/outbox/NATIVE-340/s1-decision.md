# NATIVE-340 第一轮补证裁定

| 项目 | 结果 |
| --- | --- |
| 任务、执行方、分配序号 | NATIVE-340，tietoumiao，1 |
| PR 与复验提交 | #387，`62c68c514c8bcbe5435c6cbc2fcf570388a9a980` |
| 受信标准和检查器 | main `7f909cc1e03e785e1165c110ac857a6ba9a3888a`，`native-coverage-evidence.v1.md`；检查器 SHA-256 `62b06e0a1987cfe9806d83b4e57d2097f0c39b5fc8b4e7298fb7c44c47457426` |
| 原件 | WrapSaveMergeNNFiles.dll，107,048 字节，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec` |
| 开工及提交回执 SHA-256 | `778ed3b8ace013fe3a434a1c20971288291ddacd1d9719edc8a0a113a88ff4aa`、`408ba384ed174e3177955f0bda9a296e95730fcb650c62c4dcc2871eecd46028` |
| 裁定 | 补证退回（returned）。整件沿用既有静态验收未通过状态。 |

上游以同哈希原件运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original original.dll`，退出码 0，输出 `checked 1007 coverage rows, 256 tool-native entries, 24 call records, 0 declared gaps`。75 个原件地址锚点均已索引。按原件 CLI 表实读有 563 个 TypeDef 和 188 个 MethodDef，其中 167 个有 IL 实现、19 个有原生实现、2 个无 RVA。交付摘要把含两项无 RVA 声明的 169 行都计作 IL 方法体。

## 逐项退回依据与恢复条件

1. `coverage.csv` 第 50、953 行将 RVA `0x3660`、原生 MethodDef `0x06000085` 标为 covered。两行均指向 `code/native.c` 第 1006 行，内容仅为反编译失败注释。`code/native.asm` 第 1369–1372 行可定位手工解码的 14 字节。补上相符的可编辑实现，或将两条标为 gap 并说明恢复条件。将分析器发现的 255 项与 1 项人工补入的入口分别记数。
2. 针对 `calls.csv` 全部 24 行，上游从固定原件按 caller 取 MethodDef 方法体，读取引用行对应 IL 偏移的 call 操作数，再解析目标 token。24 项均直接调用本模块的原生 MethodDef，其中 12 项被误标为对 mscorlib 的 external。例为 `code/methods.il` 第 22 行，调用方 `0x06000001` 在 IL_0018 的原始操作码为 `28`，目标为 `0x06000084`，对应原生 RVA `0x476B`。签名中的 mscorlib 修饰符不能判定调用目标。按 token、跳板及实际导入逐址重建外部与跨界调用。
3. 24 条调用记录全部来自 managed caller，漏掉 `code/native.asm` 第 483、486、489、493 行可定位的四处 KERNEL32 导入调用。`code/methods.il` 有 15 处 calli，调用表没有给出这些位置的依据或恢复条件。补齐两侧外部和跨界调用表，不能唯一确定的目标按标准登记 unresolved，给出调用位置和缺件。
4. 类型证据未保存成员归属。例如原件 TypeDef `0x02000007`（WrapCall）的 MethodList 对应 `0x060000A1` 和 `0x060000A2`。交付 `code/types.cs` 第 14–15 行只有空类；`code/metadata.asm` 第 725–726 行只有方法名、token 与 RVA。补齐类型到成员的原件映射，核对声明与实现，修正方法体计数。

修订时保留首轮证据，在新分配轮次提交修订回执和固定 head，上游以该 head、同一原件与标准复验。
