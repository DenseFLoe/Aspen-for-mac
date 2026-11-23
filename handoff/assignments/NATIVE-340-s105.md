# NATIVE-340 s105 续领

owner tietoumiao，assigned_seq=105，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。主干基线 19f94421ea3b724df2b27f65f71832db0259f34d，固定候选 [#450 @ 9c949d3f](https://github.com/DenseFLoe/Aspen-for-mac/commit/9c949d3f2caa5e90a793e1976057418a0cf4f6be)。

保留已通过的六组 ImplMap、八组阈值和两项清单定位。把宽度夹具接到 read()，只破坏实际取值时应定位错误及紧邻列。站点脚本直接比对原件字节、指令位移、导入符号以及半开 FUNC 区间。仅修改 L1509 一个字节或一行目标，各自应拒绝并定位；对 0x477D、0x47D1、0x4894 的实际归属附证据，证据不足时写明待核。用当前 calls.csv 重算 metrics.calls_sha256 及受影响清单。回执逐脚本给出字节数、SHA-256、命令、输入指纹、原始输出及退出码。保留 0x06000057 arg0 恢复条件和 28 条未决。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附固定提交及回执。[上轮裁定](../outbox/NATIVE-340/s101-decision.md)

续领输入包含相同实现及补交后的[固定回执 f38c2df8](https://github.com/DenseFLoe/Aspen-for-mac/commit/f38c2df80fd991dab0bb23fdbe3e36f7ba864796)。保留已核实的七份脚本指纹，修复 QA 命令的带空格路径传参，在从指定头取得且指纹核对的输入上复跑。
