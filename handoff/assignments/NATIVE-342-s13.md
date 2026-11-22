# ApwnIPShell.dll 第十三号续领

NATIVE-342，owner upstream，assigned_seq=13，#13 ACK 起 24 小时。原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，沿用[s9 裁定与回编证据](../outbox/NATIVE-342/s9-decision.md)。

恢复已注册的退出回调 `[0x397c0,0x3980e)`，78 字节，范围 SHA-256 `bd270f5ab561e9e801385f5289f0496648d6219bceb4e269f0c9dc483ddacad6`，unwind RVA 为 `0x44660`。证明 `0x397ea` 走 `[rax+0x38]` 且参数为 0、`0x39809` 尾转移至 `0x33ac0`，共享可写槽为 `0x527b0/0x527b8`。按原件记录初始指针链以及运行期未决条件。通过可编辑源回编比较与[原生覆盖 v1](../standards/native-coverage-upstream.v1.md)命令 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL` 后提交。
