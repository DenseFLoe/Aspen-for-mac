# NATIVE-337 s93 续领

owner tietoumiao，assigned_seq=93，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 157af57](https://github.com/DenseFLoe/Aspen-for-mac/tree/157af573f9b13fc4744eac14f50c2e9ae373d921)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

沿用原件核实过的六参、Invoke 五栈参和 FF /4 实现。把 s85 上游注册和部署元数据绑定到 ShowDialog 的解释、生成器和交付表，保留动态 DISPID。按 Microsoft 契约写 VariantInit 的 vt 和元素步幅，原件决定操作数、IID 和 VT 语义，重放 0x13DD 与 0x137F 的单改反例。修正 s37 唯一行的真实导入校验并重放两个固定同 DLL 真实序号配对。清单排除自身，用回执独立固定其完整 SHA-256。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s89-decision.md)
