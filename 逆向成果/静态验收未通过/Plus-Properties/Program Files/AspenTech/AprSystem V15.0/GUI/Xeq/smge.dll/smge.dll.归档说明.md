# smge.dll

**静态验收未通过。** 原台账状态为“暂存”。原名归档只针对 38 个按名称去重的原生函数。已读取符号包括 CheckFlowSecGen、IsFlowSecComplete；整文件覆盖尚待建立。

后续核对条件：先建立本 PE 的代码段、入口与函数边界表，再用 CheckFlowSecGen 的已存 RVA/指令交叉核对其余函数及数据引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `81740da615da890fa0d5f2f65a3883ea4e64acc0a7069646b40f00fc80658995`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)
