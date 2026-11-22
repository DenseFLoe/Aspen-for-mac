# zedstwu.dll 第五号续领

NATIVE-350，owner upstream，assigned_seq=5；自本卡 #13 ACK 起 24 小时。输入为 [原件、原路径、版本和旧代码](NATIVE-350.md) 所列固定提交 `ad53650f6071f83b133ede7bf847bc5096cd3b56`，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。沿用[第一轮裁定](../outbox/NATIVE-350/s1-decision.md)和固定候选 `30717e476e2182c3f62db16f48e37c242043a379`。

本轮修复四个业务导出。已在原件独立核实 DSWU_EUDL01 的 0x2320–0x237a 原始范围，0x2344 和 0x236f 经导入表分别调用 zeuosutl.dll 的 UU_EOERR 和 UU_STAT01。DSWU_IUDL01 在 0x2380 开始连续写入八字节字段。补齐两者的输入、布局、实际数据及可编辑实现并重新比对。DSWU_UDL01I 在 0x9327 从 ppexec.dll 的 PPEXEC_PPROY 数据导入取地址，0x932e 的首字段用于浮点运算。以此核对业务导出的调用及数据，保留已验证的复制片段、表和资源。按第一轮覆盖表逐址标明其余缺口和恢复条件。

交付到 `handoff/inbox/NATIVE-350/`，附 `s5-started.md`、`s5-submission.md`、源码和指纹。在仓库根运行 `python handoff/assignments/check-native-coverage.py NATIVE-350`，可加 `--original <已核指纹原件>`。依[上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)及[整件静态标准](../../docs/static-acceptance.md)复验。
