# ApwnIPShell.dll s73 续领

NATIVE-342，owner upstream，assigned_seq=73，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x35b60,0x35c91)`，片段 SHA-256 `0285fdb7ca2cf80f7f3e90e73077a87cbc4fe350e4c47466e8855ac6abe290df`。恢复 DLL 入口的分派体及异常范围，逐址核对三处 CFG 调用、回调槽与进入和返回条件。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s69-decision.md)
