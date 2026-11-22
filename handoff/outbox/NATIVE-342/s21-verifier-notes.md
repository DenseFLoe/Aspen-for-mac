# NATIVE-342 s21 验收器复验

延续 [s13 操作数检查缺口](s13-verifier-notes.md)。原件与验收器固定在 [基线 183ec4a](https://github.com/DenseFLoe/Aspen-for-mac/tree/183ec4aeb38f5463a99aadc2fbdbbc3326ce243a)，覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

    python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s21/check-release-shell.py ORIGINAL ZIG --evidence-dir OUTPUT

仅把 [release-shell.c](../../inbox/NATIVE-342/s21/release-shell.c) 的 `test sil, 1` 改为 `test sil, 2`，刷新指纹表和回执的摘要。任务卡要求释放条件与原件一致。本次两版覆盖检查都退出 2，报告 292 个缺口，没指出新增的释放条件差异。独立回编正确版退出 0，改动版退出 1 并报告代码字节不同。[成对结果](s21-mask-control.json)

建议本轮已覆盖入口存在固定范围回编证据时，将回编与覆盖联合报告。回归沿用这个单变量输入，正确版记录 114 字节一致和整件待补。改动版另报 0x33a8c 所在片段不符，不能继续记录该覆盖证据为通过。
