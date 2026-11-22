# WrapSaveMergeNNFiles.dll 第四十五号续领

NATIVE-340，owner tietoumiao，assigned_seq=45，自 #13 ACK 起 24 小时。固定原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。输入 [#450 @ 106eb83](https://github.com/DenseFLoe/Aspen-for-mac/tree/106eb83d05ac50c9e14e7eb079014857a9117ab3)、[s41 裁定](../outbox/NATIVE-340/s41-decision.md) 和 [s41 标准](NATIVE-340-s41.md)。

保留原件确认的分支及 EH 结论。生成器按解出的条件码、比较操作数和 AL 返回值生成主表、附表及审计。同一输入条件分支由 jge 改为 jl 时，固定负 Characteristics 应变为取跳、AL=1，消费端不跳过。只改返回立即数 1→2 时，证据表须反映新值。如果控制校验失败，以非零退出并给出失败项。区分 PE 节头 Characteristics 和进程内存页保护。

用语义有效的 small、fat EH 条款做配对，包含 CLR 方法头 MoreSects 清除的对照。校验 try/handler 范围在 IL 内。测试有后续数据节的输入，读取已声明的各段。若有当前支持范围外的节，报告具体范围并停止该件判定。

从新 head 原样复跑两套指纹命令，提交文件选择规则、纳入的路径和完整摘要，覆盖实际存在的 `code/README.md`。对照 [s41 任务卡](NATIVE-340-s41.md) 两个判定命令，将回执、工具、控制结果及固定新 head 交 #13。
