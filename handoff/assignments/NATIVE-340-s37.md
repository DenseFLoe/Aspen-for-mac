# WrapSaveMergeNNFiles.dll 第三十七号续领

NATIVE-340，owner tietoumiao，assigned_seq=37，#13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。沿用 [#450@e8fb4cb](https://github.com/DenseFLoe/Aspen-for-mac/tree/e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d/handoff/inbox/NATIVE-340)及[s33 裁定](../outbox/NATIVE-340/s33-decision.md)。

修正生成器读取 MethodDef RVA 和 EH 数据节的方式。用 `0x06000032` 的 0x1b28、1 个 finally 子句以及 IL_0025–IL_002c 验证结果。还原 0x218d 传递槽地址、0x2874 对该地址所在节的有符号属性测试、0x2197 的极性与固定 .data 槽的结论。保留 0x21a4 正分支单次读取的范围。重生成当前主表、未决附表、审计页和新回执指纹，引用旧版回执的固定 head。

按[原生覆盖证据 v1](../standards/native-coverage-evidence.v1.md)复跑 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE` 与 `pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE`。要求逐项比对独立报告的原件字段与候选字段。提交当前开工、产物和固定 PR head。
