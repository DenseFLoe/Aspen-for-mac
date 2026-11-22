# FindComponent.dll 第五十七号续领

NATIVE-337，owner tietoumiao，assigned_seq=57，自 #13 ACK 起 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。固定输入 [#445 @ 32ce7e38](https://github.com/DenseFLoe/Aspen-for-mac/tree/32ce7e38ca2ec72a31007b09c66ec847285e3071) 与 [s53 退回依据](../outbox/NATIVE-337/s53-decision.md)。

按[原生覆盖证据 v1](../standards/native-coverage-evidence.v1.md)修复清单到调用表的关联。保留已有四项对照，追加[两种布局对照](../outbox/NATIVE-337/s53-verifier-notes.md)并提交固定输入及产物指纹。拆分后仍须是 161 站，0x106C 关联第 525 行，0x12DA 关联第 528 行。修正回执的实际附表路径。执行 `python -B tool/s45_tests.py`、双布局生成命令及 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。在 #13 指向新 head 和实测。
