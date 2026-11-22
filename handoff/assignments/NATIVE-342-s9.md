# ApwnIPShell.dll 第九号续领

NATIVE-342，owner upstream，assigned_seq=9，自 #13 ACK 起 24 小时。原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，取 [固定原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/342/ApwnIPShell.dll)及 [s5 固定候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/20488adec7e3bfbe702ce1e6a275a1039547962e/handoff/inbox/NATIVE-342)。[已有裁定](../outbox/NATIVE-342/s5-decision.md)

先核对 `0x11f0/0x1570/0x15ab/0x15f6` 的范围、共享段和指令边界，仅为本轮四处入口建立可编辑实现或定位到已回编宿主。覆盖行须指向当前原件清单和源码，无法证明的间接转移逐址写恢复条件。按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL`，及 s5 的 `reassemble.py` 或本轮对照命令。保留独立回执和新指纹。
