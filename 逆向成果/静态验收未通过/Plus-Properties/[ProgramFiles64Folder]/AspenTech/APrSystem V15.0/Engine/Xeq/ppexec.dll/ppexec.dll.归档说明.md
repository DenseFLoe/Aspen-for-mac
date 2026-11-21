# ppexec.dll

**静态验收未通过。** 原台账状态为“暂存”。只核验调用 DMS_ASGOPN 的函数（RVA 0x65b0` 至 `0x87cc`）；整 DLL 的代码段、函数边界和关键数据引用仍缺覆盖记录。

后续核对条件：先建 PE 代码段/入口和异常目录函数边界对照表，以已保存的 DMS_ASGOPN 调用作局部锚点，再核对其他函数边界与引用。

本目录公开逐件说明。局部逆向正文仅在本地保存。

原件 SHA-256 为 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。[原轮次记录](https://github.com/DenseFLoe/Aspen-for-mac/tree/main/inventories/reverse/20261119-01)
