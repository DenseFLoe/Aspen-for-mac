# reassembly.json 的复验说明

RVA `[0x14cb0,0x14f6d)`，701 字节，范围 SHA-256 `5728fad0d29bfcee9a0e69875d0c7a3742a17ab40da0b123c3329b2e3fc3b50e`。190 条指令、36 处文本重定位、20 条直接控制转移、12 字节 .pdata 与 16 字节 .xdata 均已对照。64 字节初始阈值和 21 字节环境变量名另从可编辑 C 回编核对。 其中 lea 的宽度为地址宽度，未读取该地址的数据。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，版本 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 文件 SHA-256 `841e12e9d0a64a978374d50fd290b1aab2d06edf63ec08e16994b4ec1f6ee9ac`。

整件覆盖 152/255 个入口，尚余 103 个入口缺口和 26 条未决引用，静态验收未通过。 后续追踪见[本轮回执](../s45-submission.md)。
