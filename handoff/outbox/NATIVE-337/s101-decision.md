# NATIVE-337 s101 裁定

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fa42db6](https://github.com/DenseFLoe/Aspen-for-mac/tree/fa42db6e13211e2587134c447ec8ce00457560dc)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

固定头比 s97 新增六次提交，13 条路径有变化。177 个范围内文件逐项核对，交付清单 146/147 匹配。work/s101-gate.txt 仍列上一固定头指纹。补件已修正覆盖检查器的长度与指纹。正确列表、等价 JSON 与现场元数据重放通过。两处列表单改和实现签名的单字节改动均定位并退出 3。另有 4 个证据反例仍退出 0，包括实现名称或 RVA 改错、注册附件缺失、交付表签名与正确附件不一致。交付表与提交说明仍将 VariantInit 的保证扩大到 24 字节。原件覆盖 307/307/684/0，exit 2，112 条未决。

裁定 returned。覆盖命令、输入和实测见[复验记录](s101-verifier-notes.md)。交付复验证据 SHA-256 057575ace952abaa71118fe5f46e5ccf60e46afe179fbd24a714f36f0afdfe95。

[开工证据](../../outbox/NATIVE-337/s101-started-evidence.md) · [交付回执](../../inbox/NATIVE-337/s101-submission.md) · [续领卡](../../assignments/NATIVE-337-s105.md)
