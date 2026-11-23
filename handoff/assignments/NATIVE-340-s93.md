# NATIVE-340 s93 续领

owner tietoumiao，assigned_seq=93，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 05917da](https://github.com/DenseFLoe/Aspen-for-mac/tree/05917da0d1002cc17640c123cf67cd684117863e)。主干基线 54d8dd1dcb8bbbee003535a8270638fb4da6e187。

保留 #~ HeapSizes、两套清单及 167 个 IL 摘要。更正实际 parser 模式中的 MemberRefParent、MethodDefOrRef 和 CustomAttributeType，保留现行布局和阈值两侧的读表对照。加只读摘要复验入口，将本轮 s89 交付表与原件比较并保留行身份，单改的一条应定位并拒绝。逐站对照已列出的 19 个原生 IAT 转移并更新对应清单，保留无法定位的修复条件。继续提供 PEReader 工程及 arg0 的静态恢复证据。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s89-decision.md)
