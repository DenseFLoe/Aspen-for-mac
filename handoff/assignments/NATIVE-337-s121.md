# NATIVE-337 s121 续领

owner tietoumiao，assigned_seq=121，自 #13 ACK 起 24 小时。FindComponent.dll 原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，[上轮固定头](https://github.com/DenseFLoe/Aspen-for-mac/tree/ea4a5c7ffc59c27075030fb4b8726f534d23c153)。

从独立注册表快照和部署 PE 实际解析完整类型与方法绑定，覆盖缺部署原件、错误 codeBase 对照，补 code/README.md 和最终证据头回执。从注册项 CodeBase 实际定位独立部署 PE，用 PE 元数据的 TypeDef、InterfaceImpl、MethodDef 核对身份、接口边、签名和 RVA，并与交付表比较；保留 s117 的等价输入和已定位拒绝组。新增配对组应保留完整附件，只撤去独立部署 PE 或只改附件 codeBase，重算受影响的交付指纹，报告缺依赖或矛盾。固定清单应能用同一生成器重生并覆盖 code/README.md；最终回执引用含本轮脚本与交付的证据提交，按固定树复跑并记录实际基准哈希、命令与退出。动态 DISPID 和 112 条未决沿各自恢复条件保留。[上轮复核和测例](../outbox/NATIVE-337/s117-verifier-notes.md)
