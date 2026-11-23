# NATIVE-340 s109 续领

owner tietoumiao，assigned_seq=109，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。主干基线 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`，固定候选 [#450 @ 6d93c598](https://github.com/DenseFLoe/Aspen-for-mac/commit/6d93c5981ddf3ad71907e9a814d739f874b4c218)。

保留 s105 已核的 167 条 IL 摘要、六组 ImplMap、metrics 三摘要、两份活动清单和八份脚本指纹。用同一固定原件核对 L1509 显示位移、槽与完整导入符号，缺引用报缺，单改位移或符号后缀应拒绝且点名。用实际 FUNC 结束地址报告 0x477D、0x47D1、0x4894 的区间冲突，在调用表和回执同时标明待核或补足归属。让宽度夹具比较 read() 的实际行值和邻列，只改读取逻辑时应定位并退出非零。最终回执逐脚本固定输入、原始输出、退出及 QA 引号化命令，保留 0x06000057 arg0 的恢复条件和 28 条未决。

    python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE

[上轮裁定](../outbox/NATIVE-340/s105-decision.md) · [成对复跑](../outbox/NATIVE-340/s105-verifier-notes.md)。
