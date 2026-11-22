# ApwnIPShell.dll 第二十一号续领

NATIVE-342，owner upstream，assigned_seq=21，自 #13 ACK 起 24 小时。固定原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。沿用 [s17 调用证据](../inbox/NATIVE-342/s17/reassembly.json)。

恢复 [0x33a40,0x33ab2)，114 字节，范围 SHA-256 `7b5986b8aa4ed44fe9ccf110c39114be1baebd28550f8017567a8473f4653199`，unwind RVA 0x48e38。核对 0x33a71 的间接描述符调用、0x33a87 对已恢复清理体的直调，以及 0x33a9a 释放原对象前的标志分支。按原件核对范围内的内部转移、数据引用和调用边界。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付可编辑实现、逐字节回编、异常目录及调用证据。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及新增回编命令。
