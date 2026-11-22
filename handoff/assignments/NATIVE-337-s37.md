# FindComponent.dll 第三十七号续领

NATIVE-337，owner tietoumiao，assigned_seq=37，#13 ACK 起 24 小时。固定原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，以 [#445](https://github.com/DenseFLoe/Aspen-for-mac/tree/bd362e3f3493abdda0d5aa3171a25fae5f6f14c7/handoff/inbox/NATIVE-337) 与[本轮裁定](../outbox/NATIVE-337/s33-decision.md)为输入。

对 161 条统一以原件和现主表重生成首跳、IAT、导入和 calls_row。补 17 个首跳、18 个 IAT 及符号和 161 个 calls_row，修正 `0x12da` 两份附表的候选宿主为 `0x12bd`。保留已证的 16 条对象槽、64 条 COM、合法 thunk 共用及各未决恢复条件。回执固定当前附表、生成器、候选主表与真实 363 处直接 IAT。

运行 `python -B handoff/outbox/NATIVE-337/check-s33.py ORIGINAL CANDIDATE`，要求本轮相关附表各项逐址全匹配，再按[原生覆盖 v1](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。交付本轮开工与提交回执和固定 PR head。
