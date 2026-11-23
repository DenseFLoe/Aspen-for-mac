# ApwnIPShell.dll s69 续领

NATIVE-342，owner upstream，assigned_seq=69，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x35adc,0x35b60)，片段 SHA-256 `98baaba43113b7361a8183aac6de0ad606107760f29d5d1527ac2abd98adce10`。恢复进程分离路径，核对附加计数 0x54790、状态槽 0x541d0 清零、清理调用和 0x48fe0 展开及处理范围。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-342/s65-decision.md)
