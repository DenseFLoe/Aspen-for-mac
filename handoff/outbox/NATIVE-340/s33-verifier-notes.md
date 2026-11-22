# NATIVE-340 s33 验收器复跑对照

固定输入见[s33 裁定](s33-decision.md)。验收器 `verify.py` 1.6 取自 [main 414617e](https://github.com/DenseFLoe/Aspen-for-mac/tree/414617eaf303764aaae2904151e2e018a2af364d/tools/reverse_acceptance)，源树 SHA-256 `27fa0c5ac03241a9fc7dead167bdce426ee914b324b8d6cfd1f6353f75ead640`。任务卡复查使用同提交的 `check-s29-446.ps1`。

```text
pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec --delivery CANDIDATE --reference-evidence CLR_THUNKS_JSON --reference-evidence-sha256 5100064a4214751ba26289aa6566d062bd4118833929a5c4e8ccadafc1bab2e0
```

原生覆盖 v1 要求逐址写明依据。本轮 PS1 输出含原件 IL、finally 子句、槽属性和候选行，但以 0 结束，未判定主表错误的 0x3524、48 个 EH 子句，也未比较节判据的输入与分支极性。正式验收器 1.6 的 `mixed_baseline` 通过，整件因其余未决返回 2，未定位这两处。两项差异均需人工对读原件和主表。候选移除旧 callee 里的额外 COM 描述后，上一轮 [0x20cc CLR 跳板误报](s29-verifier-notes.md) 已消失。

建议先在任务卡复查中输出 MethodDef RVA、逐条 EH 数据节及候选关联的结构化比较，再用原件解码验证 guard 入参、跳转极性和当前节属性。原样 #450 应明确报以上两处。只在候选副本修正第 275/288 行及其派生表、审计页并更新 58 项指纹，再以相同原件与参考数据运行。实测两个版本的 PS1 均返回 0，1.6 均返回 2 且检查输出相同。更新后预期修正版仅保留其余整件未决项。用同一修正版再单独改错 (1) 一个 EH 字段或 (2) guard 极性，各应只定位对应错误。

[候选与对照复跑结果](s33-recheck.json)

巡检期间主干合入 [1.7](https://github.com/DenseFLoe/Aspen-for-mac/tree/fd5d755d824f903e9c5b2682260cc69bf8e1b9ad/tools/reverse_acceptance)，源树 SHA-256 `7ae119806e8934f0e882519f3806b300fc24d8586ebe5475c09da963e157f58f`。用上面相同命令重跑，候选与修正对照仍均返回 2，逐项检查输出相同。
