# ApwnIPShell.dll s57 续领

NATIVE-342，owner upstream，assigned_seq=57，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x35204,0x35264)，片段 SHA-256 `aac1533de9bf8cdb8662108ffcce0dd34d55507db2a5364cfc5e02b6d53f7762`。恢复 0x35204 的参数与条件分支，核对 0x35223→0x35e80、0x3523c GuardCF 调用的 R9 目标来源、0x3525f→0x362fe 尾边和 0x44e7c 展开。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s53-decision.md)
