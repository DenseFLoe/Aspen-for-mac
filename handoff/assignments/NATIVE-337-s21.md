# FindComponent.dll 第二十一号续领

NATIVE-337，owner tietoumiao，assigned_seq=21，本轮 #13 ACK 后 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，来源见[原任务](NATIVE-337.md)。沿用 #422 候选 `cc6f30c82bcc107e769672705cfe4bd8fea025c2` 中的 363 个直接导入、13 个已登记的 Guard CF 转移、两个寄存器来源及 303 个覆盖键。[第十七号裁定](../outbox/NATIVE-337/s17-decision.md)

落实 64 处 COM 调用的接口来源、槽与可证实的成员签名。只能证明到接口槽的，登记静态依据及取得实现地址的恢复条件。把 161 条已确认的二跳绑定与对应调用方和源代码关联。其中八个候选未归属的位置见[原件差异](../outbox/NATIVE-337/s17-instruction-diff.json)，先依据候选汇编及原件的调用后继解决归属。恢复九处非填充指令或证明等效控制流，说明 27 处填充差异。提交回执的各类引用计数从实际表生成。

按[原生覆盖证据标准](../standards/native-coverage-evidence.v1.md)执行 `python handoff/assignments/check-native-coverage.py NATIVE-337 --original <固定原件>`。交 s21 开工、提交回执和相应逐址证据，在 #13 报固定候选 head。
