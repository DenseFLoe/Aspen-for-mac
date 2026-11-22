# Ikc2Bkp.dll 第十七号续领

NATIVE-349，owner upstream，assigned_seq=17，本轮开工起 24 小时。原件 [Ikc2Bkp.dll](NATIVE-349.md) SHA-256 为 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011，版本 41.0.0.614。沿用第十三号候选 71af42aa2df54844b0bb73397a747c052e6168b1 及[裁定](../outbox/NATIVE-349/s13-decision.md)。

对照原件异常目录，恢复 0x249c0、[0x24f00,0x251bc) 内的八个缺口及 0x25560、0x25580 两个跳板。核对两张空指针区间、Guard CF 槽、初始值、可写性和回调的原件来源。复验既有 189 个范围，记录每个新实现与其范围的重组结果。无法静态绑定的站点保留逐址恢复条件。

遵守[原生覆盖证据标准](../standards/native-coverage-upstream.v1.md)。从仓库根执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>`。按同件目录中的等价编译和证据命令复跑。交 s17 开工、提交回执和指纹。
