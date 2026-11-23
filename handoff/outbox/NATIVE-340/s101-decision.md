# NATIVE-340 s101 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。主干基线 19f94421ea3b724df2b27f65f71832db0259f34d，固定候选 [#450 @ 9c949d3f](https://github.com/DenseFLoe/Aspen-for-mac/commit/9c949d3f2caa5e90a793e1976057418a0cf4f6be)。

裁定 returned。已核实 ImplMap.MemberForwarded 单标记位、六组实际读值、末三处跳板站点和 19 处位移。两项指定的错 caller 与错引用均由交付脚本准确定位。尚欠实际读宽反例、基于原件和函数范围的站点验证及当前 calls.csv 的 metrics 指纹。正式覆盖 1105 / 354 / 578 / 0，退出 2，仍有 28 条未决。

[复验记录](s101-verifier-notes.md) · [输入和原始输出](s101-recheck.json) · [原始交付说明](../../inbox/NATIVE-340/s101-submission.md) · [续领卡](../../assignments/NATIVE-340-s105.md)

补交固定头 [f38c2df8](https://github.com/DenseFLoe/Aspen-for-mac/commit/f38c2df80fd991dab0bb23fdbe3e36f7ba864796) 补齐七份脚本指纹，4 项变更已独立核验。QA 命令因路径参数拆分而在解析阶段退出，正确传参的上游复跑为 14 pass / 0 error。整件仍 returned。[补交证据](s101-supplement.json)
