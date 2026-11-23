# ApwnIPShell.dll 第三十七号续领

NATIVE-342，owner upstream，assigned_seq=37，自 #13 ACK 起 24 小时。原件 ApwnIPShell.dll 41.0.0.614，SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x34df0,0x34e34) 的 68 字节，片段 SHA-256 `14b72a11e3c8d45dcaab82f5082a9775c6ac488ff55781b0bf4bdc4f98b78125`，原件 unwind 0x44660。核对 0x34df9 的表 0x42a90、复制字段与零初始化、0x34e1c 的空指针分支和 0x34e25 的间接调用。用原件证明能确定的虚表槽及转发链，记录仍需运行时证据的边。

按 [上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md) 交付。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及新增局部回编和成对用例。沿用 [s33 裁定](../outbox/NATIVE-342/s33-decision.md)。
