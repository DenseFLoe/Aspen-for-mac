# ppexec.dll 第二十五号续领

NATIVE-346，owner upstream，assigned_seq=25，从 #13 ACK 起 24 小时。原件 ppexec.dll SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`，配套 atdms.dll SHA-256 `0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7`。沿用 [本轮范围和配置](../inbox/NATIVE-346/s21/contracts.md) 中已经证实的 512 字节初始化路径。

用 ppexec 的 `0x7de8` DMS_LOCATI 调用及三处复制 `0x7e5a / 0x7e70 / 0x7e86` 追溯源记录。逐项核对偏移 `+0x20 / +0x38 / +0x60` 的原件计算和已知写入者，找到已证的分配或边界记录。区分已知配套库中可读到的记录结构、具体调用方以及无法约束的外部写入。可证部分补入可编辑布局说明，其余逐项列恢复条件。执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original PPEXEC` 和 `python -B handoff/inbox/NATIVE-346/s21/check-tinfo.py PPEXEC ATDMS`，按[上游覆盖证据 v1](../standards/native-coverage-upstream.v1.md)裁定。
