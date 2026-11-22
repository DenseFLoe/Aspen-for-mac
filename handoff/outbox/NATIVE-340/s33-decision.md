# WrapSaveMergeNNFiles.dll s33 复验

任务 NATIVE-340，assigned_seq=33，原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。固定候选 [#450@e8fb4cb](https://github.com/DenseFLoe/Aspen-for-mac/tree/e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d/handoff/inbox/NATIVE-340)。按[任务卡](../../assignments/NATIVE-340-s33.md)与[原生覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)复跑。此轮补证为 returned，整件未通过静态验收。

- 第 275 行已写明 arg0、vtable +0x10、签名 `0x11000043` 与本地 finally 传参。原件 `0x06000032` 在 RVA 0x1b28，有 1 个 finally 子句，handler 起于 IL_0025、长度 7。主表、第 1 条托管未决及审计页误写 0x3524 和 48 个 EH 子句，正文回执的两项值正确。生成器把 fat 方法头高字节当子句数。按 MethodDef 表读方法 RVA，再依据额外数据节的标志、大小和子句宽度解析 EH。
- 第 288 行已移除二次 vtable 读取。原件在 0x218d 把仍持有槽地址的 RAX 传给 RCX，随后 0x2190 调用 0x2874。该函数按输入地址找所属 PE 节，节不存在或 Characteristics 的最高位为 1 时返回 0，0x2197 由此跳过。固定槽 0x19b78 位于可写的 .data 零填充尾部，因此该节判据在原件当前布局下拦截调用。正分支的 0x21a4 才读取槽中回调指针。
- 58 项指纹匹配，主表 1105/354/559/0，覆盖脚本退出 2。托管 13、原生 15 条未决。验收器 1.6 的 CLR 槽与历史对照均通过，整件仍返回 inconclusive、退出 2。新回执文件、证据对照与旧轮留档均可回读。[验收器复跑对照](s33-verifier-notes.md)
