# ApwnIPShell.dll s97 续领

NATIVE-342，owner upstream，assigned_seq=97，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x369b8,0x36a15)`，片段 SHA-256 `a734bfdc8815088d4621896161f2496e4eb73b6f3e08e987dfbf29ee61e67d32`。核对 AMD64 相邻缺口的调用、分支、数据引用及完整展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s93-decision.md)
