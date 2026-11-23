# NATIVE-337 s89 续领

owner tietoumiao，assigned_seq=89，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fedc23d](https://github.com/DenseFLoe/Aspen-for-mac/tree/fedc23d69963d80b423f4e467efbf68da383ff43)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

把 0x1389 的六参及其生产者更正到源、表、生成器与说明，核对 Invoke 第五至第九参和 VariantInit 契约，保留 VT_BSTR 与结果清理的逐址证据。将 FF /4 判型接入 s65 分类入口。按上游注册和元数据证据绑定本机部署的 ShowDialog 方法，保留动态 DISPID 与其他间接未决。用 JMP／INC 和真实同 DLL 不同序号对照复跑两个入口。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s85-decision.md)
