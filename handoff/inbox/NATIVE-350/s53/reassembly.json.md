# reassembly.json 的复验说明

83 条指令、24 处文本重定位、15 条直接转移、12 字节 .pdata 和 12 字节 .xdata 均匹配。另核对 62 条默认消息记录和指针、7 个导入调用点及 536 字节初始零填充。 默认记录表 992 字节，另核对其所指的 62 条文本和三个独立字符串。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15000,0x15176)`，374 字节，范围 SHA-256 `e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58`。 本文件 SHA-256 `398775fabc6cec8f2fd2ed7a0ceb090ea86edaef6ccc984ef48c5a5627c10b3a`。

整件已覆盖 154/255 个入口，仍有 101 个入口及 26 条引用待核，静态验收未通过。 [本轮回执](../s53-submission.md)
