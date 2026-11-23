# ApwnIPShell.dll s89 续领

NATIVE-342，owner upstream，assigned_seq=89，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x3664c,0x366df)`，片段 SHA-256 `86e2bd47334735f5ba5edb3f83e44a8de321ce45b480a48a36b370b30fff1246`。核对邻近未覆盖的 AMD64 例程、每条分支和调用及异常展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s85-decision.md)
