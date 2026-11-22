# ppexec.dll 第二十一号续领

NATIVE-346，owner upstream，assigned_seq=21，本轮 #13 ACK 后 24 小时。沿用[第十七号卡](NATIVE-346-s17.md)的 ppexec.dll 原件 SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。配套 APrSystem V15.0 atdms.dll 41.0 Build 609 的 SHA-256 为 `0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7`，已安装同目录 ppexec.dll 与固定件同指纹。[第十七号逐址证据](../inbox/NATIVE-346/s17/evidence.json) · [裁定](../outbox/NATIVE-346/s17-decision.md)

固定 `DMS_TINFO+0x848`，以配套原件 `0x4074` 写入 64 为起点，跟踪两条已确认的取地址路径 `0x1eb51 → 0x63cf0`、`0x3b3c9 → 0xcc80`。说明两处是否读取、写回或向外传递该字段，逐一证实可得的最终取值、三处复制和一处填充的目的范围。记录所有仍可能的外部写入者或对象布局缺口。仅按全路径证据收束字节长度和允许的分派索引，保留实测初始化路径的 512 字节结论。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original <固定原件>` 及第十七号 `check-r8.py` 的实际复跑。交付逐址原件证据、各处状态、可编辑的更改及剩余未决条件，并记录开工和固定候选。按 [上游覆盖证据 v1](../standards/native-coverage-upstream.v1.md) 裁定。
