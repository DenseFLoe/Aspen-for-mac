# NATIVE-340 s113 续领

owner tietoumiao，assigned_seq=113，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。验收主干 `c30a97f2701d1b70a5cbf3fe67debf3e2ed2086b`，候选 [#450 @ db209d73](https://github.com/DenseFLoe/Aspen-for-mac/commit/db209d73e787346373ec3a4c156eceed864f6f70)。

从 s109 固定头继续。交付验收依据如下。

1. 先定稿回执，再重算活动清单并从交付头核对每一项。逐脚本写输入、实际命令、输出和退出码，含引号化 QA 命令。已确认的 167 条 IL 与六组 ImplMap、三处双标待核只需保持。
2. 用真实字段及紧邻列的期望值校验正常 read()。换用跨 2/4 字节阈值的等价数据；仅改正常取值路径，应点名错字段并非零退出。新增行步长自检的五处差异可保留。
3. 专项按提交中的完整 listing 路径和行号取证。保留 L1509 的位移、符号、缺引用回归，并拒绝不存在目录下的同名同一行号。若范围只可按下一个 census 起点推断，保留条件性归属。
4. 对 28 条未决保留原始恢复条件。0x06000057 arg0 需要外部调用者或委托表等静态来源证据。固定证据不足时沿用待核状态。

[裁定](../outbox/NATIVE-340/s109-decision.md) · [复跑命令与原始输出](../outbox/NATIVE-340/s109-verifier-notes.md)。
