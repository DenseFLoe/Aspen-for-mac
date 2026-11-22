# WrapSaveMergeNNFiles.dll

**静态验收未通过。** 原台账状态为“暂存”。旧 C# 按类型选取；528 个顶层类型中 527 个没有独立的选取输出，包括 $_s__CatchableTypeArray$_extraBytes_16。嵌套类型 34 个。

后续核对条件：先列出 CLR 方法和原生代码段/入口的交界，再建立双侧覆盖记录并核验外部调用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)

## 2026-11-22 第九轮复验

主调用表的 271 条已分类记录与上一候选相同。15 条 calli 及 4 处原生间接转移仅列附件。126 个 CLR 跳板、16 处外部构造调用和类型方法范围仍待补。本轮受信检查器退出 0，原件级复验退回续修。[逐件裁定与候选指纹](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/handoff/outbox/NATIVE-340/s9-decision.md)
