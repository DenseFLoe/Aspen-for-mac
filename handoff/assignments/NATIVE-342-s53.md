# ApwnIPShell.dll s53 续领

NATIVE-342，owner upstream，assigned_seq=53，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x34f40,0x34f68)，片段 SHA-256 `bc67b3c5c586198379f3f21e843c88a1850124f1e5d5b9eeabe133f2e1ae75b0`。核对局部对象初始化调用 0x34f51→0x34e40、0x34f56 的 0x492b0 数据与 0x34f62→0x362c2 的抛出边，逐字节复验含 INT3 的范围与 0x44e74 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s49-decision.md)
