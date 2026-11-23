# ApwnIPShell.dll s77 续领

NATIVE-342，owner upstream，assigned_seq=77，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

恢复 `[0x360d4,0x36110)`，片段 SHA-256 `80de413be0bad692d40a7cfff93d994ee3740475be5a1b5887c0f4e0f2715c42`。恢复指针表遍历，逐址核对起止边界、空槽跳过、CFG 调度、步幅和展开。

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s73-decision.md)
