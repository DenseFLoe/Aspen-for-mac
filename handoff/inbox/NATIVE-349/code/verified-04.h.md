# verified-04.h 说明

本段含 3 个 AMD64 可编辑实现，首个入口 0xf580，末个实现右界 0x13e7f。通过 code/verified.c 包含本段并按原 RVA 应用 COFF 重定位，逐实现在 reassembly.json 核对字节和指纹。

原件为 Ikc2Bkp.dll 41.0.0.614，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。本文件 SHA-256 为 `e978722e05eeec00d6cabe172c76ba143432b5faecc2de79aff0a1ce4b9d16f8`。原路径、固定输入提交、验证命令、23 个待补入口及下一步见本件目录的 Ikc2Bkp.dll.md。
