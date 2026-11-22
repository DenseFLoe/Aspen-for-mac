# FindComponent.dll 第九轮复验

**退回续修（returned）。** 候选 #404，提交 `0b97dca2387b1e6063b8be9142bd9e759ce3f59e`，assigned_seq=9。固定原件取自 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/337/FindComponent.dll`，SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。已逐项从候选 Git 树核验并回读本件 inbox。[完整候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/0b97dca2387b1e6063b8be9142bd9e759ce3f59e/handoff/inbox/NATIVE-337) · [原件比对和交付指纹](s9-recheck.json)

用主干 4eeb881f52d7510b0f072304dc81c08c5b0bbce7 的受信检查器和固定原件复跑，机械退出 0，结果为 280 行覆盖、280 个分析入口、403 条主表调用、0 个申报入口缺口。原先列为未决的 99 条原生转移按 caller 与反汇编行完整移入附件，主表对这些站点的覆盖为零。对两版覆盖表、可编辑 C 及原始指令逐项比较，覆盖和 C 内容相同，反汇编的差异只有空行和标记说明。原有 403 条其余调用记录逐字段相同。

对照已收 #392，基线的 363 处直接 IAT 仍缺 8 处，20 个旧覆盖地址仍未列出。前次列出的 13 处其他间接转移、64 处可判定 COM 接口调用和 161 处调用方与导入跳板的关联仍需逐址核对。指令及数据的旧逐址复验仍可按相同输入重放。[前次地址明细](pr394-addresses.csv) · [前次实件复验](pr394-decision.md)

附件 indirect.csv 可记录指令和恢复条件。仍待解析的站点在 calls.csv 保留 unresolved；静态可确定的目标按原件标为 external 或 boundary，并说明方向或槽位。原件、指令边界和逐址调用优先于机械退出码。本轮回执按原字节归档，下一轮见[第十三号任务卡](../../assignments/NATIVE-337-s13.md)。
