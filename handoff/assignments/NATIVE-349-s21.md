# Ikc2Bkp.dll 第二十一号续领

NATIVE-349，owner upstream，assigned_seq=21，本轮 #13 ACK 后 24 小时。原件 SHA-256 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。[来源](NATIVE-349.md) · [第十七号裁定](../outbox/NATIVE-349/s17-decision.md)

从第十七号候选 `8bb3dd8f0ac743c92a1f9468d5c62eea4428849e` 继续。原件异常目录将两个入口限定为 [0x243ac,0x244c2) 的 278 字节和 [0x24548,0x24679) 的 305 字节。分别恢复两段并核对后继。跟踪 0x2448e 的 R9，以及 0x2459b、0x24612、0x24655 的 RAX 来路。核对已回编的 200 个范围和既有引用。

从仓库根执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>`，按[上游原生补证标准](../standards/native-coverage-upstream.v1.md)交 s21 回执、重组结果与逐址来源。仍无法静态绑定的位置记录缺的输入和复验条件。
