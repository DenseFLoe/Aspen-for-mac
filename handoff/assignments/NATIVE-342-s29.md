# ApwnIPShell.dll 第二十九号续领

NATIVE-342，owner upstream，assigned_seq=29，自 #13 ACK 起 24 小时。原件 ApwnIPShell.dll 41.0.0.614，SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x33a20,0x33a38)，24 字节，范围 SHA-256 `beb31f6a8911348a0460514d488e99484ac3fa6dae04c8be473ab625ed79d90a`。原件异常目录在该范围没有条目。核对 0x33a23 和 0x33a2d 的两处只读引用，以及 0x33a34 的虚表尾转移和入口参数来源。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及新增局部回编命令，按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付。沿用 [s25 裁定](../outbox/NATIVE-342/s25-decision.md)。
