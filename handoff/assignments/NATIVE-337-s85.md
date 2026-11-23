# NATIVE-337 s85 续领

owner tietoumiao，assigned_seq=85，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 661da2d](https://github.com/DenseFLoe/Aspen-for-mac/tree/661da2d59e2eb20cccdd6932e1dba5c8cde53a16)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

先更正 0x1389 的 Windows x64 ABI 参数位置、DISPPARAMS 的两项 32 位计数以及结果低 32 位的表述，继续从 0x13dd–0x13fa 复核 VARIANT 实参和初始化，再核对两条 Release 与结果清理。以能追溯的类注册数据或类型库绑定 ShowDialog；若仍缺，将外部类型保留为未决。把 RIP 相对 FF /4 检查接入实际站点枚举和分类，保留 161 站，并用同位移 JMP/INC 和同 DLL 错误 IAT 身份两组成对用例复跑。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-337/s81-decision.md)
