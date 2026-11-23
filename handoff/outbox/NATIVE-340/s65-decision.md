# NATIVE-340 s65 复验退回

固定原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。固定 [#450 @ ba2c5d5](https://github.com/DenseFLoe/Aspen-for-mac/tree/ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e)。

覆盖 v1 退出 2，1105 覆盖行、354 原生入口、559 调用、0 申报缺口。四个 filter 的偏移与边界、七个 catch 的类型和两处 calli 签名均对照原件复验。仍有 13 条托管与 15 条原生未决调用。独立 IL 读取从八个方法核实 11 个站点向 0x06000056 提供指针，交付三处未列，且遗漏了一个可证目标 0x06000006。0x06000057 在本模块直接 MethodDef 引用中无站点。保留整件未通过，要求补齐所有站点、同步调用主表和证据附表，再按实际来源推进未决路径。 [独立复验](s65-verifier-notes.md)
