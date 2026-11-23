# NATIVE-337 s73 续领

owner tietoumiao，assigned_seq=73，自 #13 ACK 起 24 小时。原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，固定 [#445 @ 12bca3ef](https://github.com/DenseFLoe/Aspen-for-mac/tree/12bca3ef1f92a7f3bc9ec9f575caff37bf62a610)。

提交从原件导出的站集及其可复跑命令。将候选每站清单行的地址和完整指令字节与原件核对。保持三布局均为 161 站和原有调用表关联。第 28 行单改一字节位移应报 0x106C 字节差异。删同站清单指令时，即使旧站表缺失，也应报告该站缺证或拒绝缺少可验证的基准输入。刷新回执所有工具指纹。

对 0x1320 函数中 0x1389、0x1396、0x1444、0x1457 四个未决调用，从原件恢复接收者、调用槽和初始化路径。能绑定的给出目标和数据来源，其余写明已证边界及所需输入。按[覆盖证据 v1](../standards/native-coverage-evidence.v1.md)复跑 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE` 及[独立用例](../outbox/NATIVE-337/s69-verifier-notes.md)，在 #13 固定新 head、范围和证据。
