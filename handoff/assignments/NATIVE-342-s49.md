# ApwnIPShell.dll s49 续领

NATIVE-342，owner upstream，assigned_seq=49，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x34ee0,0x34f3f)，片段 SHA-256 `5605be7ff7427d7b14a0069c4176e9090765233cb7fbffbdee14555282bd0bcc`。核对 0x34ee0 的对象清理、0x34f09 虚调度、0x34f18 的 LocalFree 调用、0x34f22 的标志分支及 0x34f2c 的外部调用链，逐字节复验范围与 0x44e68 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s45-decision.md)
