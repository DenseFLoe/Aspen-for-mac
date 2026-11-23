# ApwnIPShell.dll s61 续领

NATIVE-342，owner upstream，assigned_seq=61，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，来源 `issue-materials/342/ApwnIPShell.dll`，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x352f4,0x35418)，片段 SHA-256 `4a6776f7c5a98e67967fae31a7dc3b68f427afebe72913f0f191aa4022a7f443`。相邻两处 CRT 帮助函数分别核对。0x352f4–0x3537f 核对初始化保护、两张退出表与 0x44660 展开。0x35380–0x35418 核对 PE 节范围、可写位测试、异常处理器及 0x48f28 展开。0x3537f 的 INT3 单列为填充。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s57-decision.md)
