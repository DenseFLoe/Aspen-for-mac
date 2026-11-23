# ApwnIPShell.dll s65 续领

NATIVE-342，owner upstream，assigned_seq=65，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x359c4,0x35ada)，片段 SHA-256 `b800253ad5cbaf49cc76bae0c845822204ad369d8d006ab2e2f10f386153102a`。恢复 CRT 进程附加路径，核对状态槽 0x541d0、两组 _initterm 边与 0x48fa4 展开；追查 0x35aa6 的 R9 产生链，仍无绑定则保留该站为未决。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s61-decision.md)
