# mmg.dll

**静态验收未通过。** 原台账状态为“暂存”。原名归档只针对 29 个按名称去重的原生函数。已读取符号包括 CleanIwpInputParameters、GREODisconnectStream；整文件覆盖尚待建立。

后续核对条件：先建立本 PE 的代码段、入口与函数边界表，再用 CleanIwpInputParameters 的已存 RVA/指令交叉核对其余函数及数据引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `5236861792e45d8a9b62c393efd96e8ea2320d46ed16f1b7abbc2e7d5f603508`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)
