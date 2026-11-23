# NATIVE-340 s85 续领

owner tietoumiao，assigned_seq=85，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ f847024](https://github.com/DenseFLoe/Aspen-for-mac/tree/f8470240a320318bd82ef58f9f0e84e311022be1)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

以原件四槽为回归输入，按 corhdr.h 用 0x08 FROM_UNMANAGED_RETAIN_APPDOMAIN 与 0x10 CALL_MOST_DERIVED。将实际表流读取改为逐列计算编码宽度，从 #~/#- 表流头读取 HeapSizes。使用固定原件和给出 SHA-256 的真实 MethodImpl 样本，按原始值右移 tag bits 得 RID，与 PEReader 核对端点，禁止用同一套互逆错误公式作唯一证据。复跑 MemberRefParent、MethodDefOrRef、CustomAttributeType 三种边界及正负摘要集合，输出额外、重复、缺失和摘要不符的 token。保留已核定 167 个 IL 摘要、11 处调用、35 条 EH 及 arg0 恢复条件。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s81-decision.md)
