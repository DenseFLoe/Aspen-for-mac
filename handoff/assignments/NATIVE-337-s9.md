# NATIVE-337 第九号事件续领

owner 为 tietoumiao，assigned_seq=9，时限为本轮 #13 ACK 后 24 小时。固定输入为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/337/FindComponent.dll`，SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。前轮补件为 [#392](https://github.com/DenseFLoe/Aspen-for-mac/pull/392) 的 `a180dcfd1b6bd39072a4a03b94b908408e6da426`。

依[第五轮裁定及逐址证据](../outbox/NATIVE-337/s5-decision.md)补 13 处间接转移，为 64 处 COM 调用注明工厂、接口成员与运行时才能绑定的部分，关联 161 条可追到 IAT 的调用方和跳板，并同步数据引用计数。沿用核实过的 363 个直接 IAT 位置及函数映射。按[原生覆盖标准](../standards/native-coverage-evidence.v1.md)从仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-337`。在 `handoff/inbox/NATIVE-337/` 提交修订及 `s9-started.md`、`s9-submission.md`，在 #13 报产物 PR 和完整 head。
