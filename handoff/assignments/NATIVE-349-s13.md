# Ikc2Bkp.dll 第十三号续领

NATIVE-349，owner upstream，assigned_seq=13，ACK 后 24 小时。固定原件 SHA-256 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`，沿用[来源卡](NATIVE-349.md)。基线候选为 `a65e08d7c459587bb734926974c7e9a902284437`，含 187 个已回编入口、145,279 字节、5,347 个重定位。[第九号裁定](../outbox/NATIVE-349/s9-decision.md)

补核两个原件异常目录宿主。第一处 `[0x24b3c,0x24bd4)` 长 152 字节，48 条指令，末尾 `0x24bd3 RET`。区间 SHA-256 `9baf6a09164b23b74d36219006eca5149601522248884dbe9339eb159fe38153`。第二处 `[0x24ea4,0x24eff)` 长 91 字节，27 条指令，包含三个直接目标 `0x253d8`、`0x253de`、`0x254b0`；尾部 `0x24efe INT3` 位于区间内。区间 SHA-256 `e0edde68973a2c8f78d3ecc9ec511e199a8d1d0bf25f2eeb7c0e73388576c341`。恢复两段可编辑实现并重组字节；复查第一处的寄存器、数据引用和返回路径及第二处的调用后继与尾部归属。在覆盖表和调用表登记两个宿主、原剩余入口和未决转移去向。

沿用[原生补证标准](../standards/native-coverage-upstream.v1.md)。从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <固定原件>`。保留已验证代码和资源，在本件 inbox 写 `s13-started.md`、`s13-submission.md` 和同名说明，通过 #13 通知完整候选提交。
