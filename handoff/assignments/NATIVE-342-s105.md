# ApwnIPShell.dll s105 续领

NATIVE-342，owner upstream，assigned_seq=105，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

同时恢复 JMP RAX 调度跳板及相邻 RIP 间接尾转移，固定磁盘槽指纹、可证绑定和两项展开。范围与输入如下。

- `[0x36ae0,0x36ae2)` SHA-256 `b5916d40205265465cce91e2cd0704bf6e1e36263acfe53c729a06f296e9f353`
- `[0x36b00,0x36b06)` SHA-256 `b6206a5791a0ede089b6f2e3701dbd3309d75fdd471507ab91cbf91da67795dd`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s101-decision.md)
