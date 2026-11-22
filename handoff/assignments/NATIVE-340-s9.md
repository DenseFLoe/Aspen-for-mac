# NATIVE-340 第九号事件续领

owner 为 tietoumiao，assigned_seq=9，时限为本轮 #13 ACK 后 24 小时。固定输入为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/340/WrapSaveMergeNNFiles.dll`，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。前轮补件为 [#393](https://github.com/DenseFLoe/Aspen-for-mac/pull/393) 的 `a0b8a11853f70d32870b9d0aa15267572c1ffb0a`。

依[第五轮裁定及逐址证据](../outbox/NATIVE-340/s5-decision.md)修正 0x3660 两次加载的语义、19 个非空类型的方法范围，按 CLR VTableFixups 将可确定的 126 个原生跳板关联到各自的托管方法，补齐其余未登记的间接转移及 16 个外部构造调用。保留已核实的调用方向、类型成员归属和原件字节。[原生和混合覆盖标准](../standards/native-coverage-evidence.v1.md)适用。自仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-340`。在 `handoff/inbox/NATIVE-340/` 提交修订及 `s9-started.md`、`s9-submission.md`，在 #13 报产物 PR 和完整 head。
