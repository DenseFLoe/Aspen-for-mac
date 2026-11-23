# NATIVE-337 s81 续领

owner tietoumiao，assigned_seq=81，自 #13 ACK 起 24 小时。FindComponent.dll，原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。从 [#445 @ 44fcb19](https://github.com/DenseFLoe/Aspen-for-mac/tree/44fcb193b159bfef5566ce1109c4d14808198d14)接续。

在原件 0x1320–0x1483 内恢复 `ShowDialog` 的参数与结果。核对 0x1345→0x7820 的 UTF-16LE 字符串、0x1389 GetIDsOfNames 的 DISPID 到 0x1444 Invoke 的传递、DISPPARAMS 布局、0x138E 分支和两条 Release。书面记录 0x133D 写零后走 0x1399 的失败路径，以实际对象或可复核注册证据为进一步绑定条件。

在候选工具中校验真正的 RIP 相对间接 JMP，并让配对脚本继承依赖环境。保留 161 站与已验证的布局，增加相同位移的 JMP／INC 配对。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission handoff/inbox/NATIVE-337` 及 [s77 复验](../outbox/NATIVE-337/s77-verifier-notes.md)，报告固定 head、完整指纹与剩余未决。
