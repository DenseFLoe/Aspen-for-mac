# check-crt.py 说明

使用 Zig 0.13.0、pefile 2024.8.26 及 Capstone 5.0.6。逐件复验 187 个重组实现、四个 CHAININFO 入口、两个新增宿主的调用、数据、返回后继、17 个旧入口缺口及 15 个未决转移。

原件为 Ikc2Bkp.dll 41.0.0.614，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。本文件 SHA-256 为 `224baef9b15b5ea1242fcb6a7c6eb139e7a1a4e8815c64b8b683b6ec076fe56f`。来源、核对命令和剩余缺口见[逐件静态核验](../Ikc2Bkp.dll.md)。
