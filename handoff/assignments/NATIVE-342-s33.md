# ApwnIPShell.dll 第三十三号续领

NATIVE-342，owner upstream，assigned_seq=33，自 #13 ACK 起 24 小时。原件 ApwnIPShell.dll 41.0.0.614，SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 [0x33c33,0x33cac)，121 字节，片段 SHA-256 `87b725fd5792c416ea82a6a2cb11b5318097b65171ec325027e1c55487cee1dc`。核对 .pdata 覆盖 [0x33c33,0x33caa)、unwind 0x48e58 及 0x33caa 的尾转移。追踪入口参数保存、0x366e0 调用与 0x49320 描述符。记录能够由固定原件确认的调用范围与未决点。

按 [上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md) 交付。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 及新增局部回编和成对用例。沿用 [s29 裁定](../outbox/NATIVE-342/s29-decision.md)。
