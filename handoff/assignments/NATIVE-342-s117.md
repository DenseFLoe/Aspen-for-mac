# ApwnIPShell.dll s117 续领

NATIVE-342，owner upstream，assigned_seq=117，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

复验 0x1d660 的条件分支、调用参数、相对引用及原件展开，保留限制未核项。范围与输入如下。

- `[0x1d660,0x1d78d)` SHA-256 `90409137645a6989bd82117121f5580af4cff89735f7457bf852051ead7a9de4`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s113-decision.md)
