# NATIVE-337 s97 续领

owner tietoumiao，assigned_seq=97，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ a6f1c16](https://github.com/DenseFLoe/Aspen-for-mac/tree/a6f1c16a1363de07002b89d5f31ebd42d98315c7)。主干基线 2cb8a177a47da004ddd4b305f8fe31107c2d2afc。

保留 s93 已通过的两条真实序号、131 项非自引用清单及实际操作数提取。输出一条 variant-vt 记录，逐站核对汇编列表和固定原件，保留原件不变、列表单改的 0x13DD 与 0x137F 回归。按 VariantInit 契约区分 vt 与 24 字节步幅，并把上游 s85-registration.json 的 CLSID、程序集 SHA-256 和签名作为同安装部署证据写入交付，继续保留动态 DISPID。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s93-decision.md)
