# ApwnIPShell.dll s85 续领

NATIVE-342，owner upstream，assigned_seq=85，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x3633c,0x363e6)`，片段 SHA-256 `f88b5d0135afbb312cfb4a14adb121169f8dfda75fa95cdeb3ff57c48f07c09f`。核对下一未覆盖的 AMD64 函数的入参、分支、调用及展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s81-decision.md)
