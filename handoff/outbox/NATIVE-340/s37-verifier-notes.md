# NATIVE-340 s37 验收器对照

[#450 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/88bbe3130f561d2cdd76b3652cfbc3ab3a901a23/handoff/inbox/NATIVE-340)、[原件字节与反汇编](s37-original-evidence.json)、[本轮实测](s37-verifier-replay.json)。沿用 [s33 的诊断](s33-verifier-notes.md)，本轮增加可在同一原件上隔离验证的分支极性案例。

```text
python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE
pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original ORIGINAL -Unit CANDIDATE
python -B tools/reverse_acceptance/verify.py item --original ORIGINAL --sha256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec --delivery CANDIDATE --reference-evidence CLR_THUNKS_JSON --reference-evidence-sha256 5100064a4214751ba26289aa6566d062bd4118833929a5c4e8ccadafc1bab2e0
```

三工具取自主干 `b04042ca387010579df70bbfccbf882460435824`。覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`；任务卡 PS1 SHA-256 `dff64661655f764c261e84c6724b1dd602bb2a802ae3aea893b0115ddb3bb68c`；正式验收器 1.8 源树 SHA-256 `faa318d5bd6b8001f92e735d585709d1b921c496f4084e395ca1de43cf01c5f5`。

用同一原件与参考数据，保留候选 CLR、源码及主表行数，只在副本修正第 288 行和派生附件的 guard 极性，刷新其变动指纹。原候选与修正版均得到覆盖 1105/354/559/0 退出 2，PS1 退出 0，正式验收器 1.8 退出 2、mixed_baseline 通过。逆向覆盖证据 v1 要求原件调用结论与候选逐项吻合。两份输出均未指出这处极性差异，仍需人工逐跳复核。PS1 核旧版入口的 58 条指纹，本轮独立另验新清单 65 条。

建议任务卡检查先结构化解析原件两条分支的返回值，再比较候选实际宣告以及固定槽的节属性。注册此对照后，原候选应定位 0x2197 极性错误，修正版应解除该项并保留其余未决。正式验收器可复用同一组字段及配对用例。本轮同步了报告，验收器更新留待独立评审。
