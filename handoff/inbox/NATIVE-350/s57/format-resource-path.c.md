# format-resource-path.c

## 入参与返回

0x1503B 取原件 `%lu/%s` 的地址，0x15042 取 `irc_msg.dll`，0x1504E 将栈缓冲地址置于 RCX，0x15051 把 GetThreadLocale 的 EAX 结果置于 R8D。0x15054 调用本件。

0x18558 计算 Windows x64 第三个寄存器参数的 home 槽，0x1855D 与 0x18560 写入 R8 与 R9。0x18573 把可变参数列表首址保存在帧内，0x18578 把它作为外呼的第 5 参数。0x1858A 传入缓冲地址、size_t 全一、格式指针、NULL locale 和可变参数列表。0x1865E 通过 0x180DE 和 IAT 0x19188 调用 __stdio_common_vsprintf；0x1866A 将负值归为 -1。0x1858F 将格式化返回值存入 ESI，0x18599 核验以 RSP 混合的 cookie，0x1859E 恢复返回值。

[指令](instructions.lst) · [回编数据](reassembly.json) · [复跑](check-format-source.py.md)

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x18550,0x185a6)`，86 字节，片段 SHA-256 `48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351`。 本文件 SHA-256 `4e9b254c727a83491597e9a871bd237c4f6f756d327d3dc564104a2ad4a54fed`。

整件覆盖 155/255 个入口，仍缺 100 个入口和 26 条引用，静态验收未通过。 [回执](../s57-submission.md)
