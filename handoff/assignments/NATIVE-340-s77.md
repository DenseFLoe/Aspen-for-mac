# NATIVE-340 s77 续领

owner tietoumiao，assigned_seq=77，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 3b440bf](https://github.com/DenseFLoe/Aspen-for-mac/tree/3b440bf0a4bf207d479eccc148232062a7f1a6a0)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

按编码标记位修正两种列宽，提供 8191／8192 与 16383／16384／32768 配对。用含具体 MethodImpl 的同型两个方法逐 token 验正负绑定。访问检测按 token 重算完整 IL 指纹。基于 VTableFixups 目录核对 0x19600/08/10/18 的 0x2／0xA 标记及本模块可追踪的生产者，保留 11 站和 35 EH。仍无证据的运行时改写和 arg0 依赖写明恢复条件。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s73-decision.md)
