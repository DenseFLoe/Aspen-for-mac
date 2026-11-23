# ApwnIPShell.dll s101 续领

NATIVE-342，owner upstream，assigned_seq=101，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x36a18,0x36ac8)`，片段 SHA-256 `10f027a5d2a931866854b85dee9e83f9fa8488615fc60cd3c6ee3a8e757ff201`。核对 PE 映像头部、节表半开范围和可写属性的判定、异常筛选路径及完整展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s97-decision.md)
