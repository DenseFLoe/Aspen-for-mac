# WrapSaveMergeNNFiles.dll 第二十一号复验

**退回续修。** NATIVE-340，assigned_seq=21，[#438 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/24fdc60ded7fc4c37184124a25657a6d09dda8ba/handoff/inbox/NATIVE-340)，[#13 回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7082174855)，原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。42 份逐件文件按候选 Git blob 与 SHA-256 回读。[文件清单](s21-candidate-blobs.json)

- 原件 `.nep` 逐址解码，237 个槽跳转均能在主表找到原指令、槽和 MethodDef。第十七号的 126 条已查边与新纳入的 111 条均过核对；后者的 `EB 08` 前驱与跳转目标逐项一致。共有 122 个不同 MethodDef，加载后真正落点待运行时取证。
- Zig 0.13.0 独立编译两份 C 源，分别核对 122 与 106 个桩。各桩编出一条经 RIP 相对槽的 JMP，COFF REL32 绑定到正确槽符号，在原地址重定位后字节均与原件相符。[编译与槽跳转报告](s21-recheck.json)
- 对原件 MemberRef `0x0a000019` 解析 TypeSpec 签名 `1512808D011C`，得到 `[System]System.Collections.Generic.LinkedList<System.Object>::.ctor`，候选保留类型名的泛型元数，两种写法指向同一构造函数。候选 `0x3660` 的可编辑实现为读取 `GS:[0x30]` 后解引用 `+0x8`，地址及原件 14 字节一致。[构造函数复核](s21-constructors.json)
- 主干 `2b94f3746bd9f53b478a9d1946e1d0451b046d44` 的判定器退出 2，1105 个覆盖行、354 个原生工具入口、554 条调用、0 个申报入口缺口。主表是 226 external、298 boundary、30 unresolved（15 托管、15 原生）。`fixup_edges_ok=126` 与同表 `fixup_edges_verified=237` 使用不明口径，需分别写字段含义或按全量重生成。下轮从已定位的两条 `calli` 和原生 `0x21ae` 深入追踪调用数据。

复跑命令为 `python -B handoff/outbox/NATIVE-340/check-s21-438.py ORIGINAL CANDIDATE_ITEM_DIR handoff/assignments/check-native-coverage.py ZIG WORK_DIR`。Windows 行为待其阶段验证。[开工](../../inbox/NATIVE-340/s21-started.md) · [提交](../../inbox/NATIVE-340/s21-submission.md)
