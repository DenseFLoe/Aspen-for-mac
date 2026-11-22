# ppexec.dll 第十七号续领

NATIVE-346，owner upstream，assigned_seq=17，本轮 #13 ACK 后 24 小时。沿用 [第十三号固定原件](NATIVE-346-s13.md)，SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。基线候选 `0765fced4f86d2d5543dd3d5a9548631fb7eb88f` 及 [19 个调用方和两个分派器的证据](../inbox/NATIVE-346/s13/evidence.json)。

优先从 0x7135、0x71cc、0x7e5a、0x8013、0x565e、0x79fa 的原件生产者回查 count 到 R8 的单位、有效范围和乘八边界。对固定长度调用分别给出原版数值。将实际能确认的调用参数契约回填 0x91a4、0xa6e4、0xe215、0xf135、0x12c93 五个分派位置；缺外部声明时记录确切输入来源。沿用 0x121c0 与 0x11c56 的已验证结论。其余注册、加载器槽和数据类型按逐址题目保留恢复条件。

用 [上游补证标准](../standards/native-coverage-upstream.v1.md) 从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original <固定原件>`，提交 s17 双回执、输入指纹、原件逐址证据和可运行的复核命令。
