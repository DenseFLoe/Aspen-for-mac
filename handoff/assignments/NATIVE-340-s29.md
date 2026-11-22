# WrapSaveMergeNNFiles.dll 第二十九号续领

NATIVE-340，owner tietoumiao，assigned_seq=29，自 #13 ACK 起 24 小时。原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。以 [#443 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/ad325a41370aab89f74bff4449cb1d82fdb5884a/handoff/inbox/NATIVE-340) 和 [第二十五号裁定](../outbox/NATIVE-340/s25-decision.md) 续办。

按方法签名及 IL 求值栈校正 `0x06000030` 的两个 GUID 参数，保留已证实的槽位和签名。用原件证据更正 `0x21ae` 的固定回调槽来路，记录空槽与可写节两道前置条件。用相同方法复查相邻的托管 `0x06000031 IL_0008`。分列进入本轮基线与提交现状，重新生成 managed/native 未决表和指标。

补登裁定中列出的五条本模块内 newobj 调用，逐条固定 caller token、IL offset、MethodDef 目标及主表行。

按[标准](../standards/native-coverage-evidence.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE_ITEM_DIR` 及 `pwsh -File handoff/outbox/NATIVE-340/check-s25-443.ps1 -Original ORIGINAL -Unit CANDIDATE_ITEM_DIR` 的同等增量核验。既有已核证的 237 条槽跳和 228 个桩可引用。有改变则复跑受影响部分。交付逐址可复跑证据、更新后的主表与指纹，在 #13 明示固定 head。
