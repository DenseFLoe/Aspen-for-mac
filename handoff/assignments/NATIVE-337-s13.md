# FindComponent.dll 第十三号续领

执行方 tietoumiao，NATIVE-337，assigned_seq=13，时限自本轮 #13 ACK 起 24 小时。固定原件为提交 `64670801de54e990f975aaeda06e89340c0e4e08` 中的 `issue-materials/337/FindComponent.dll`，SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。[原件来源与产品路径](NATIVE-337.md) · [第九号候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/0b97dca2387b1e6063b8be9142bd9e759ce3f59e/handoff/inbox/NATIVE-337) · [本次裁定及逐址证据](../outbox/NATIVE-337/s9-decision.md)

以 #392 的 a180dcfd1b6bd39072a4a03b94b908408e6da426 为起点，保留 363 个直接导入站点及原函数集合，核清 13 处间接转移、64 处 COM 槽、161 个调用方到跳板的关联与遗漏的 20 个地址。对照完整反汇编操作数和导入表复核每个差异。 附件 indirect.csv 可记录指令和恢复条件。仍待解析的站点在 calls.csv 保留 unresolved；静态可确定的目标按原件标为 external 或 boundary，并说明方向或槽位。原件、指令边界和逐址调用优先于机械退出码。 对逐址实证表校验 99 个附件位置是否在主调用表正确登记，每一项给出已核实的目标或未决依据。

交付至 `handoff/inbox/NATIVE-337/`，开工与提交用 `s13-started.md`、`s13-submission.md`。按[原生覆盖标准](../standards/native-coverage-evidence.v1.md)自仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-337`。逐址复核仍由上游按固定原件和 PR head 进行，交付后在 #13 通知完整 head。
