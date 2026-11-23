# NATIVE-340 s105 裁定

原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。主干基线 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`，固定候选 [#450 @ 6d93c598](https://github.com/DenseFLoe/Aspen-for-mac/commit/6d93c5981ddf3ad71907e9a814d739f874b4c218)。

裁定 returned。六组 ImplMap、167 条 IL 摘要、活动清单 154 项、回执八份脚本和 calls 指纹已核对。站点脚本能拒绝错字节、错导入名和错引用。只改显示位移、导入名后缀、遗漏引用或 FUNC 排他终点，脚本仍报零冲突。三条端点已在回执标待核，calls.csv 三行仍未同步。实际 read() 取宽变体仍漏报，QA 命令回执仍记参数解析错误。

正式覆盖 1105 / 354 / 578 / 0、退出 2。保留 28 条未决及 0x06000057 arg0 的恢复条件。[复验手记](s105-verifier-notes.md) · [原始输出及输入指纹](s105-recheck.json) · [原交付说明](../../inbox/NATIVE-340/s105-submission.md) · [续领卡](../../assignments/NATIVE-340-s109.md)。
