# NATIVE-337 s101 续领

owner tietoumiao，assigned_seq=101，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ ff5aa8a](https://github.com/DenseFLoe/Aspen-for-mac/tree/ff5aa8a36cfe444e9f540414b59a2bd1b441c680)。主干基线 54d8dd1dcb8bbbee003535a8270638fb4da6e187。

保留两站 listing_matches 和唯一 variant-vt 行、同 DLL 两条真实序号、139 项已核指纹；在正式证据复验入口拒绝 0x13DD 或 0x137F 单改的矛盾列表，定位站点。修正表、回执中 VariantInit 的契约为仅保证 vt=VT_EMPTY，保留原件的 24 字节步幅及后续 VT_BSTR 写入。分别列出 PE 身份指纹、强名称字段、接口与实现的实例 int32 ShowDialog(string) 签名（2001080E），核对类、接口和实现 RVA。正确证据通过；保持原件和安装程序集不变、仅改实现签名并更新受影响的交付指纹，应定位冲突或待核。保留动态 DISPID 及其他未决调用。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s97-decision.md)
