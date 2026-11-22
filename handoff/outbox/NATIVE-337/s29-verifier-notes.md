# 验收器 1.5 对 NATIVE-337 s29 的复验差异

候选 [#442 固定提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/86d9f2502e56e3939fbfefdb7508c12812d434e4/handoff/inbox/NATIVE-337)。验收器为 [#441 合入版](https://github.com/DenseFLoe/Aspen-for-mac/tree/ff585268ac8983097b8a229e3d8e49abee61d7e1/tools/reverse_acceptance)，1.5，源树 SHA-256 `4ec54c4d7a7b1b8fdc9b7462a6a0e982956be15d978d680d9a0bc03d1277e853`。

```text
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02 --delivery CANDIDATE_ITEM_DIR
python -B handoff/outbox/NATIVE-337/check-s29.py ORIGINAL CANDIDATE_ITEM_DIR
```

1.5 给出 inconclusive，列出 112 条主表未决以及五项宿主待核。按[原生覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)，提交用于证明原件转移的中间目标也须吻合。1.5 本次未检查 s29 二跳附表中的首跳；独立原件脚本验证 161 行，发现 160 行错填 `0x5cfc`，例如 `0x106c` 原件首跳实际为 `0x4aa3`。建议在可识别的结构化二跳证据中分别核验站点、首跳、IAT 和最终符号，保留不能确定的间接目标。用固定候选回归应逐址定位 160 条失配，`0x12da → 0x5cfc` 的首跳继续匹配；修正这 160 行后该项为 0，整件其余缺口仍须裁定。

[1.5 复验摘要](s29-verifier-summary.json) · [逐址复查](s29-recheck.json)
