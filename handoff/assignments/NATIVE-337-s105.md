# NATIVE-337 s105 续领

owner tietoumiao，assigned_seq=105，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fa42db6](https://github.com/DenseFLoe/Aspen-for-mac/tree/fa42db6e13211e2587134c447ec8ce00457560dc)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

保留已通过的列表两站和实现签名单改、唯一 variant-vt 行、同 DLL 两处真实序号。改正表第 10 行和交付说明中的 24 字节清零，将 vt=VT_EMPTY、24 字节步幅及后续 VT_BSTR 写入分别绑定原件证据。在交付复验入口核对实际交付表和已固定部署元数据，按类型与方法名定位 ShowDialog，核对接口实现关系、签名及实现 RVA。正确与等价布局通过；分别改变实现名、RVA 或交付表签名，或缺少注册附件时，定位冲突或明确待核。更新受影响的交付指纹。保留动态 DISPID 与其余未决。

最小改动位置以固定候选为准。tool/s81_showdialog.py 第 22 行 ITEMS 的 variant-init 改写保证范围，重新生成 code/s81-showdialog.csv 并同步本轮提交回执。tool/s101_verify.py 第 38 行 verify_signature 和第 57 行 main 读取必需附件、真实交付表及独立的部署元数据，按完整类型和 ShowDialog 成员匹配，比较签名和 RVA。缺件、无匹配或矛盾时以非零退出，输出文件、类型、成员与具体字段。仅改单一证据且重算活动清单时，应分别定位 FindComponentDriver.ShowDialog 的 name、rva 或交付表 signature，缺附件时点名 s97-registration.json；正确及等价布局退出 0。对应反例可直接复用 s101-replay.py。 先完成 work/s101-gate.txt，再刷新 s101-fingerprints.json 中该文件的 SHA-256，从固定提交完整回算。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s101-decision.md)
