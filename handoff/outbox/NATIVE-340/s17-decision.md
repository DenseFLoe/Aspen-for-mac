# WrapSaveMergeNNFiles.dll 第十七号复验

**退回续修。** NATIVE-340，assigned_seq=17。收到 [#430 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/5671a75cd2ec9e5b9d1ca1ec09bbafa321700f13/handoff/inbox/NATIVE-340) 及 [#13 回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7081354563)。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。受信判定器实际退出 2，999 个覆盖记录、248 个原生入口、448 条调用。35 条 unresolved 含 15 条托管、20 条原生记录。

- 派单的 126 个原生跳转逐个核对原件指令、槽、标志、MethodDef token 和方法体 RVA，主表和原件一致。61 条既有跨界边保留。全解码 `.nep` 的 1,952 字节后，另发现 111 个有直接跳转前驱的槽跳转，其中 106 个漏登，5 个仍 unresolved。例如 `0x5000` 经 `EB 08` 跳到 `0x500a`，后者经 `0x19020` 指向 `0x06000001`（RVA `0x10a0`）。原件总计 237 个槽跳转及 122 个不同 MethodDef。[逐址清单](s17-recheck.json)
- 本轮恢复的 122 个汇编记录与原件字节匹配。对应的 C 函数体均只有注释，调用后会直接返回。仍需保留真实间接尾跳语义的可编辑实现和核验证据。指标文件 `fixup_stubs_added`、`coverage_added` 均仍为 0。
- 16 个外部 `newobj` 和 5 个本模块构造调用的原件位置、操作码和 token 相符。外部成员中 15 个属主及名称正确。`0x0600009d` 的 `IL_0001`（`0x0a000019`）缺 TypeSpec 属主，原元数据为 `[System]System.Collections.Generic.LinkedList<System.Object>::.ctor()`。[元数据复查](s17-constructors.json)
- `0x3660` 已恢复 `GS:[0x30]` 后再读取 `[RAX+8]` 的两级语义。源码和说明中的 PEB 命名缺乏原件支持，改用寄存器及地址含义。

[候选和上游输入指纹](s17-candidate-blobs.json)。本轮登记回执和原件核验证据，保留 #430 的共享工具变更供另审。
