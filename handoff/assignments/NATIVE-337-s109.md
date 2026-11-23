# NATIVE-337 s109 续领

owner tietoumiao，assigned_seq=109，自 #13 ACK 起 24 小时。原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。候选 [#445 @ 8a26163](https://github.com/DenseFLoe/Aspen-for-mac/tree/8a261635459e2e862b034ed3fd3a6d02dcc10dd9)。主干基线 44c22e3daac712802e8a7e865a42c301f70b714b。

保留 28 行再生表、唯一 variant-vt 和七个已可定位的错误。修改 tool/s101_verify.py 的 verify_signature 第 65–110 行，把独立固定的部署程序集或其可核验来源、身份和元数据回读作为实际输入。由该证据取得完整类型、接口实现边、接口及实现 ShowDialog 的签名与 RVA，对照附件及交付表。将第 107 行的子串判断改为完整数值比较，错误应点名对象、字段、预期及实测；缺证据明确待核。

按 s105-replay.py 独立副本成对复验。正确与等价布局通过。只删除 InterfaceImpl、只改接口方法 RVA 0→1、只改附件 PE SHA-256、只改交付表 A848→A8480 时，分别定位该项冲突。更新活动清单，用最终可回读提交重算脚本和交付材料指纹、核对所列排除规则。修复 tool/s101_counters.py 的旧格式匹配，tool/s105_counters.py 将输入完整性纳入退出码。回执中记录命令、最终固定树的实际输入指纹和输出。原件覆盖与动态 DISPID、112 个未决调用继续逐项记录。

`python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT`

[本轮裁定](../outbox/NATIVE-337/s105-decision.md) · [四个单改变体](../outbox/NATIVE-337/s105-verifier-notes.md)
