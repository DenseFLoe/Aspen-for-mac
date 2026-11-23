# ApwnIPShell.dll 第四十一号续领

NATIVE-342，owner upstream，assigned_seq=41，自 #13 ACK 起 24 小时。原件 ApwnIPShell.dll 41.0.0.614，SHA-256 ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b。

恢复 [0x34e40,0x34e85) 的 69 字节，片段 SHA-256 dfeaea0ef12e23a31c55b931d22c4df503a8cbdc067c31c4d5f1434aff37af51，原件 unwind 0x44660。复核 0x34e49 的表 0x42a90 和字段初始化，分别核对 0x34e65 的接收对象空值检查和 0x34e6a 的参数低字节检查。确认通过两项检查时 0x34e76 的虚调度槽、实参来源与接收对象表内 +8 的边，记录所需运行证据。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 与局部回编，沿用 [s37 裁定](../outbox/NATIVE-342/s37-decision.md)并保存成对用例。
