# ApwnIPShell.dll 第十七号续领

NATIVE-342，owner upstream，assigned_seq=17，自 #13 ACK 起 24 小时。固定原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。沿用 [s13 的尾转移证据](../inbox/NATIVE-342/s13/tail-transfer.csv)。

恢复尾转移目的 `[0x33ac0,0x33b80)`，192 字节，范围 SHA-256 `c72a98919f6453c002592f4a2ea5a26bc1eb0665d514772c2d3d5fcc8a12aa62`。以原件异常目录核对 0x33ac0 到 0x33b70 的八个入口及片段之间的帧与控制流关系，追查 0x33b14 与 0x33b4d 的间接调用。按可证范围登记未决条件。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)提交可编辑实现、逐字节回编、异常目录及调用证据。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及本轮新增回编命令。
