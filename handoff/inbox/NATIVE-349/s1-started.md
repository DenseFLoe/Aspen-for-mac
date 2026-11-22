# Ikc2Bkp.dll 第一轮开工

执行方 upstream，NATIVE-349，assigned_seq=1。已回读 64670801de54e990f975aaeda06e89340c0e4e08 的 issue-materials/349/Ikc2Bkp.dll，对本地 217128 字节的实件重算 SHA-256 为 bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011。任务卡见 [NATIVE-349](../../assignments/NATIVE-349.md)。

先定位导出 Ikc2Bkp 的 0x44a0–0x4510，再用 Ghidra 与 PE 异常目录对照 220 个原件锚点、其他函数、调用与数据。复验运行任务卡中的 check-native-coverage.py，并逐项列出无法确认的实现。
