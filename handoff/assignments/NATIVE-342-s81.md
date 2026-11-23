# ApwnIPShell.dll s81 续领

NATIVE-342，owner upstream，assigned_seq=81，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x36110,0x3614c)`，片段 SHA-256 `e36318e0d5411b79b2dc3b873af30708f04dab919c8c35fc17c898251a70e10a`。核对相邻 CRT 表遍历的双边界、跳过空槽、指针调度和共享展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s77-decision.md)
