# FindComponent.dll

**静态验收未通过。** 原台账状态为“暂存”。原名归档只针对 11 个按名称去重的原生函数。已读取符号包括 gxElectrolyteWizard、gxReorderComp；整文件覆盖尚待建立。

后续核对条件：先建立本 PE 的代码段、入口与函数边界表，再用 gxElectrolyteWizard 的已存 RVA/指令交叉核对其余函数及数据引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)

## 2026-11-22 第九轮复验

主调用表的 403 条已分类记录与上一候选相同，99 处原生间接转移仅列附件，8 处直接导入和 20 个以前覆盖的地址仍待补。本轮受信检查器退出 0，原件级复验退回续修。[逐件裁定与候选指纹](https://github.com/DenseFLoe/Aspen-for-mac/blob/main/handoff/outbox/NATIVE-337/s9-decision.md)
