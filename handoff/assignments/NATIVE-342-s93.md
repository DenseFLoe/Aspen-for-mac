# ApwnIPShell.dll s93 续领

NATIVE-342，owner upstream，assigned_seq=93，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x366e0,0x369b6)`，片段 SHA-256 `a37241803bea0d69bc7e8d8cce04d9ac893f4c311b0a1d62d17e1a7e50c0a766`。核对邻近未覆盖的 AMD64 例程，共同证实分支、调用、重要数据引用及异常展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s89-decision.md)
