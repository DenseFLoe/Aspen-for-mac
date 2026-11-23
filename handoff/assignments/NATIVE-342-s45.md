# ApwnIPShell.dll s45 续领

NATIVE-342，owner upstream，assigned_seq=45，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x34e90,0x34ed4)，片段 SHA-256 `83775a03ae2ae71bffd68eec65a47da50fe4e46b9805833aa6062f1a1c73d913`。核对 0x34e90 的相邻构造例程、0x34eb3 的调度边、完整代码与 0x44660 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s41-decision.md)
