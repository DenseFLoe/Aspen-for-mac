# verified-03.h 说明

本段含 5 个 AMD64 可编辑实现，首个入口 0xa2d0，末个实现右界 0xf57d。通过 code/verified.c 包含本段并按原 RVA 应用 COFF 重定位，逐实现在 reassembly.json 核对字节和指纹。

原件为 Ikc2Bkp.dll 41.0.0.614，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。本文件 SHA-256 为 `9ea8ea579dc2fd3665358887875f1370c584954394361ecaec3d91e0c4bd3376`。原路径、固定输入提交、验证命令、23 个待补入口及下一步见本件目录的 Ikc2Bkp.dll.md。
