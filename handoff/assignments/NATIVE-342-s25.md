# ApwnIPShell.dll 第二十五号续领

NATIVE-342，owner upstream，assigned_seq=25，自 #13 ACK 起 24 小时。固定原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。沿用 [s21 回编证据](../inbox/NATIVE-342/s21/reassembly.json)。

恢复 [0x339a0,0x33a14)，116 字节，范围 SHA-256 `b65931ff6417863e4cdce73dd1727829bf80a45b7e38b90f735d512b2ce930d7`，unwind RVA 0x48e28。核对输出地址为空时的 HRESULT、0x339e7 的 CoCreateInstance 参数和写入槽位、0x339ff 的间接引用计数调用以及早退和异常目录。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付可编辑实现、逐字节回编、异常目录及调用证据。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及新增回编命令。
