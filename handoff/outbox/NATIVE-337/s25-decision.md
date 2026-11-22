# FindComponent.dll 第二十五号复验

**退回续修。** NATIVE-337，assigned_seq=25，固定候选 [#436 @ `fb049d7760ecdc038a6a468f5afa6d5c391a612c`](https://github.com/DenseFLoe/Aspen-for-mac/pull/436)，[#13 回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7082036429)。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。候选逐件目录 37 份文件的 Git blob 和 SHA-256 已回读；复跑使用主干 `75359eecbb1c28f9c9696cf6c38960d295e3b164` 的判定器。退出 2。307 个覆盖键、307 个工具入口、684 条调用、0 个申报入口缺口，实际 524 external、48 data、112 unresolved。[文件清单](s25-candidate-blobs.json) · [逐址复验](s25-recheck.json)

- 独立核对 5,055 条清单字节。363 处直接 IAT、161 条二跳和 13 处 Guard CF 登记保持。99 条间接引用在主表和两份附表都已指向当前原件位置。逐字段对照候选自带的 `indirect-resolved.prev.csv`，99 条均只改变 `listing`，`resolved` 和 `verdict` 未变。
- `0x4706` 的 16 个内存调用逐址核实槽位、RAX 的读取来源及主表行。PE 异常目录的 `[0x4706,0x4988)` 是展开链的片段，`0x93e8` 指回 `[0x4690,0x4706)`。表中 16 处宿主与候选的差异有原件依据，具体实现地址仍取决于运行期对象。
- `0x12da` 是直接调用 `0x5cfc`。原件异常范围为 `[0x11e0,0x1319)`，候选指令所在文件的第 208 行位于 `[0x12bd,0x130d)` 子清单。附表没有这项直接调用；按任务卡增记其映射。
- 新 IDispatch 附表 64 个 `disp` 都为空，58 个成员名吻合。原件的 `0x18a1`、`0x1a01`、`0x2021`、`0x2195` 为 Invoke（`+0x30`），`0x1948`、`0x20c9` 为 GetIDsOfNames（`+0x28`）。六项分别误记为 GetTypeInfoCount 或 GetTypeInfo。已有原件证据对应 16 GetIDsOfNames、32 Release、16 Invoke。
- 二跳附表 161 行仍标 `primary_class=absent`，主表均已有核对过的 external 行。指标仍填 external 363、indirect 99。363 可作为直接 IAT 数，99 是间接附表行数。请据主表重算分类并分别登记两个专项数。

复跑命令为 `python -B handoff/outbox/NATIVE-337/check-s25.py ORIGINAL CANDIDATE_ITEM_DIR`。[s25 开工](../../inbox/NATIVE-337/s25-started.md) · [s25 提交](../../inbox/NATIVE-337/s25-submission.md)
