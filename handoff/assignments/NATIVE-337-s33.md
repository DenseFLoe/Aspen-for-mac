# FindComponent.dll 第三十三号续领

NATIVE-337，owner tietoumiao，assigned_seq=33，自 #13 ACK 起 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。沿用 [#442 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/86d9f2502e56e3939fbfefdb7508c12812d434e4/handoff/inbox/NATIVE-337) 已证实的 64 个位移、成员和工厂。 [第二十九号裁定](../outbox/NATIVE-337/s29-decision.md)

逐址从原件重算 161 条首跳及 IAT。在 `0x12da` 分列原件异常宿主 `0x11e0` 与候选宿主 `0x12bd`。将 16 个对象槽以及 64 个 COM 附表的 calls.csv 行号与 ASM 行号分列。按本轮实际主表重算类别计数及 SHA-256，单列直接 IAT 与附表规模，记录六个已修成员及未决恢复条件。对已知槽补原件可推出的对象来源，仍缺实际实现时逐项记录恢复条件。

按[原生覆盖标准](../standards/native-coverage-evidence.v1.md)执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE_ITEM_DIR` 和 `python -B handoff/outbox/NATIVE-337/check-s29.py ORIGINAL CANDIDATE_ITEM_DIR`，复核至少 `0x106c`、`0x12da` 和 `0x4706` 三处。更新本轮验证入口使它选择本轮指纹，保留历史收据。交付开工、提交、逐址证据、主表计数及指纹，在 #13 给出固定 head。
