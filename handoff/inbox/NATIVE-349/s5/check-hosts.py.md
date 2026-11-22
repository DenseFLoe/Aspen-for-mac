# check-hosts.py 说明

本脚本核对 Ikc2Bkp.dll 41.0.0.614 的第五号分配，原件 SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。运行 `python -B s5/check-hosts.py <原件> <Zig>`。脚本调用 reassemble.py，对照 185 个实现的字节与重定位，独立解码两个宿主的逐指令后继和四条展开链接，核对首轮 23 个缺口及 15 个未决站点的本轮归属。脚本指纹见 SHA256SUMS.txt。适用范围和剩余缺口见[逐件报告](../Ikc2Bkp.dll.md)。
