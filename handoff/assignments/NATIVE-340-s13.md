# WrapSaveMergeNNFiles.dll 第十三号续领

执行方 tietoumiao，NATIVE-340，assigned_seq=13，时限自本轮 #13 ACK 起 24 小时。固定原件为提交 `64670801de54e990f975aaeda06e89340c0e4e08` 中的 `issue-materials/340/WrapSaveMergeNNFiles.dll`，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。[原件来源与产品路径](NATIVE-340.md) · [第九号候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/c2b0de7f97863e2e85d5775c5c6a288918280027/handoff/inbox/NATIVE-340) · [本次裁定及逐址证据](../outbox/NATIVE-340/s9-decision.md)

以 #393 的 a0b8a11853f70d32870b9d0aa15267572c1ffb0a 为起点，逐项核对 126 个 CLR VTableFixups 目标、16 个 newobj、11 处其他间接转移、19 个非空 TypeDef 的方法范围及 0x3660 两次加载。保留已核实的 61 条跨界调用。 附件 indirect.csv 可记录指令和恢复条件。仍待解析的站点在 calls.csv 保留 unresolved；静态可确定的目标按原件标为 external 或 boundary，并说明方向或槽位。原件、指令边界和逐址调用优先于机械退出码。 对逐址实证表校验 19 个附件位置是否在主调用表正确登记，每一项给出已核实的目标或未决依据。

交付至 `handoff/inbox/NATIVE-340/`，开工与提交用 `s13-started.md`、`s13-submission.md`。按[原生覆盖标准](../standards/native-coverage-evidence.v1.md)自仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-340`。逐址复核仍由上游按固定原件和 PR head 进行，交付后在 #13 通知完整 head。
