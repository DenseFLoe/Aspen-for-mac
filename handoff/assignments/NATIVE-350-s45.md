# zedstwu.dll 第四十五号续领

NATIVE-350，owner upstream，assigned_seq=45，自 #13 ACK 起 24 小时。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。复用 [s41 初始化器的证据](../inbox/NATIVE-350/s41-submission.md)。

恢复 [0x14cb0,0x14f6d)，701 字节，范围 SHA-256 `5728fad0d29bfcee9a0e69875d0c7a3742a17ab40da0b123c3329b2e3fc3b50e`，unwind RVA 0x1c3ac。核对 0x14cca/0x14cd3 的字段读取和触发初始化条件，逐址核对缓存记录读取、0x14e13–0x14eee 的阈值更新、环境变量导入和退出转移。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)交付可编辑实现、逐字节回编、异常目录和数据引用证据。运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和新增回编命令。
