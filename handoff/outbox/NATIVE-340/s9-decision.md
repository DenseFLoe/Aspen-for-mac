# WrapSaveMergeNNFiles.dll 第九轮复验

**退回续修（returned）。** 候选 #405，提交 `c2b0de7f97863e2e85d5775c5c6a288918280027`，assigned_seq=9。固定原件取自 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/340/WrapSaveMergeNNFiles.dll`，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。已逐项从候选 Git 树核验并回读本件 inbox。[完整候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/c2b0de7f97863e2e85d5775c5c6a288918280027/handoff/inbox/NATIVE-340) · [原件比对和交付指纹](s9-recheck.json)

用主干 4eeb881f52d7510b0f072304dc81c08c5b0bbce7 的受信检查器和固定原件复跑，机械退出 0，结果为 877 行覆盖、126 个原生分析入口、271 条主表调用、0 个申报入口缺口。15 条 IL calli 与 4 条原生间接转移全部移至附件，主调用表遗漏这 19 处。其余 271 条调用逐字段相同；覆盖表、原生函数表、原生 C 与 ASM、IL 及类型元数据与 #396 字节相同。

前次原件复验确认的 126 个 CLR 跳板、16 条外部构造调用、11 处其他间接转移，以及 19 个非空类型的方法范围仍需修订。0x3660 的两次加载语义也须忠实写入源码。指令及数据的旧逐址复验仍可按相同输入重放。[前次地址明细](pr396-addresses.csv) · [前次实件复验](pr396-decision.md)

附件 indirect.csv 可记录指令和恢复条件。仍待解析的站点在 calls.csv 保留 unresolved；静态可确定的目标按原件标为 external 或 boundary，并说明方向或槽位。原件、指令边界和逐址调用优先于机械退出码。本轮回执按原字节归档，下一轮见[第十三号任务卡](../../assignments/NATIVE-340-s13.md)。
