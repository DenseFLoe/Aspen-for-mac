# reassemble.py 说明

从可编辑 AMD64 源码构建 COFF，解析符号与重定位，按每个原 RVA 对照字节；遇到缺失或不等的已申报实现即失败。

原件为 Ikc2Bkp.dll 41.0.0.614，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。本文件 SHA-256 为 `4a4711b45bc110b345eb066c17fdd4eecc3f510c12e7f7e2e11df837265ea0e2`。原路径、固定输入提交、验证命令、本轮 17 个待补入口及下一步见本件目录的 Ikc2Bkp.dll.md。
