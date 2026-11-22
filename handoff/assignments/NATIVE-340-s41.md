# WrapSaveMergeNNFiles.dll 第四十一号续领

NATIVE-340，owner tietoumiao，assigned_seq=41，自 #13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。复用 [#450@88bbe313](https://github.com/DenseFLoe/Aspen-for-mac/tree/88bbe3130f561d2cdd76b3652cfbc3ab3a901a23) 与 [s37 裁定](../outbox/NATIVE-340/s37-decision.md)。

保留 MethodDef RVA `0x3524`、EH RVA `0x3568` 和 finally 标签范围。追踪真实 `jge` 目的及落空分支，更新主表、三个原生未决附表和审计，准确说明 .data 固定槽被节门禁跳过，以及 `0x21A4` 单次读取所在分支。生成器从原件提取分支和返回值。EH 读取器按 ECMA-335 处理 small 和 fat，使用两种有效布局及 MoreSects 控制。补可从固定提交运行的两套当轮指纹生成命令，保留旧版作为历史。

按[原生覆盖证据 v1](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE` 与 `pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE`。逐项对照原件的两个分支值、真实槽、方法及 EH 字段，并提交控制项结果、产物和固定 PR head。
