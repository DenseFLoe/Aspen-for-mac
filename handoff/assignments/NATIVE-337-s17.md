# FindComponent.dll 第十七号续领

NATIVE-337，owner tietoumiao，assigned_seq=17，ACK 后 24 小时。固定原件为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/337/FindComponent.dll`，SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。在 [#411 的固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/43017ac0901a450784de1678b55d2f501641b75c/handoff/inbox/NATIVE-337) 上续修，#392 基线为 `a180dcfd1b6bd39072a4a03b94b908408e6da426`。

保留已实证的 363 个直接 IAT 站点和附件中的 99 个地址。按[第十三号裁定](../outbox/NATIVE-337/s13-decision.md)及[逐址表](../outbox/NATIVE-337/s13-sites.csv)补 13 个历史 GuardCF 记录、两个寄存器操作数的来源和 161 个调用方到导入跳板的二跳。对 64 个 COM 站点保留可证接口来源、槽、成员和目标已知程度；动态目标仍未知则保留 unresolved，写明恢复条件。补回 13 个旧覆盖入口的位置或逐项说明宿主归属，核清 3 个段内键与六条遗漏指令。由实际最终文件生成产物指纹，核对表中未决数量。

按[原生覆盖证据 v1](../standards/native-coverage-evidence.v1.md)执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <固定原件>`，交付到 `handoff/inbox/NATIVE-337/`，分别写 `s17-started.md`、`s17-submission.md`，在 #13 指向完整候选 head。任务续接保留原 owner。
