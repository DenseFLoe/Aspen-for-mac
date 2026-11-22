# FindComponent.dll 第二十五号续领

NATIVE-337，owner tietoumiao，assigned_seq=25，本轮 #13 ACK 后 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，来源见[原任务](NATIVE-337.md)。以 [#428 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/b9bcc8630fc4344796d9c4d59e86ec78901ac9ba/handoff/inbox/NATIVE-337) 与[本轮裁定](../outbox/NATIVE-337/s21-decision.md)为输入，保留 363 条直接 IAT、161 条已绑定二跳、13 处 Guard CF、64 个已证接口槽及九个恢复的起址。

由当前原件 RVA 和清单重生成 `indirect-resolved.csv` 99 处引用、二跳主表分类和指标。原件宿主与候选子清单分列，例如 `0x12da`。沿 `0x4706` 的 16 条其他内存分派追溯接收方及可证实的槽位，标记每个原件位置、主表行、来源指令与恢复条件。已知 IDispatch 槽也逐址记录所需运行时对象和目标模块身份，静态证据可证明的范围保持可复核。

按[原生覆盖证据标准](../standards/native-coverage-evidence.v1.md)，运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <固定原件>`。附一份按地址验证两张表和现有清单内容的结果，说明剩余未决。提交本轮 s25 开工、提交回执及产物，在 #13 指向固定 head。
