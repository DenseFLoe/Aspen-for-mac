# 验收器 1.5 对 NATIVE-340 s25 的复验差异

候选 [#443 固定提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/ad325a41370aab89f74bff4449cb1d82fdb5884a/handoff/inbox/NATIVE-340)。验收器为 [#441 合入版](https://github.com/DenseFLoe/Aspen-for-mac/tree/ff585268ac8983097b8a229e3d8e49abee61d7e1/tools/reverse_acceptance)，1.5，源树 SHA-256 `4ec54c4d7a7b1b8fdc9b7462a6a0e982956be15d978d680d9a0bc03d1277e853`。从受信主干运行下列命令，项目按 [原生覆盖证据 v1](../../standards/native-coverage-evidence.v1.md) 和整件静态标准裁定。

```text
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec --delivery CANDIDATE_ITEM_DIR
```

1. `mixed_baseline` 将 126 条已登记 CLR 槽边全部报为缺失或错误。独立重看全部 126 项后，calls.csv 引用的单行证据与原件六字节、调用方、槽和 token 均对应。例如 `0x5004` 的边引用 `code/native-fixup-sites.asm#L5-L5`。验收器只索引 `code/native.asm` 且期待固定格式的 callee 字符串。建议按路径加行号索引已限定的证据文件，用数值 RVA、原件指令和 CLR 槽证明 token；对格式缺失与已验证不符分别报错。固定候选复跑应为 126 条历史边匹配。另将其中 0x5004 的槽 RVA 改一项，应逐址报告一条失配。
2. 同一检查将 21 个 `newobj` 报为主表缺失或错误。16 个外部构造调用实际经 `code/newobj-sites.il` 登记，其中一例为 `0x0600009d IL_0001`。其余 5 个本模块内构造调用确实缺少主表登记。建议按调用方 token、IL offset 和目标 token 链接经验证的 IL 证据。回归应显示 16 条已证，5 条缺失。此修正与 C 源证据需求相互独立，整件仍未通过。

[1.5 复验摘要](s25-verifier-summary.json) · [原件独立复验](s25-decision.md)
