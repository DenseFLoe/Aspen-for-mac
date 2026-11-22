# Simdll.dll 的提交入口与分派逻辑

原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。[逐条指令](focus.asm)保留原始字节和 RVA，[开工证据](../s1-entry-evidence.json)另列两个入口的区间摘要、导出序号和每个外部跳板的实际 IAT 槽。

| 入口 RVA | 核对的机器逻辑 |
| --- | --- |
| 0x39c00 | 导出 submit_proprun。先置 prop_retrieve_results，读取 topfinfo 所指记录，保存 0x380、0x15c、0x708、0x150 四处值，临时向 0x380 写入 0x2d9。调用 0x109c0 后，重新读取导入指针，按原次序写回并调用 GRsetpgc、GRsetnec、GRsetcpt，返回内部调用结果。 |
| 0x109c0 | 向模块内 0x51c00 写 1。调用 0x31540 后以 (1, 1, 0, NULL) 调用分派器。分派器返回非零即返回 0，返回零才调用 GRsetgfl 及 0x15a10(9, NULL)，以最后一次调用是否返回零产生布尔结果。 |
| 0x22a50 | 对原参数减 1 作无符号范围判断，19 个跳表槽始于 RVA 0x22b4c。入口 1/2/5 分别选用 0x210b0/0x21e70/0x20c70。操作 7、17 共用 0x20e10，8、18 共用 0x20ae0。操作 12 读取 SkipEngineLoadOnDocumentLoad，已置位时调用 CreateApwnLibrariesTest 并返回 0。无设置或设置值为 0 时调用 0x21b80。其余有效操作及返回值见 C 文件。 |

导入声明只表达本调用点可见的寄存器与结果。例如 GRinqgpd 入口处 RCX 为当前记录指针，实际原型仍需依赖侧证据。0x31540 和 0x15a10 均跨多条 x64 unwind 记录，仍须核对完整实现、间接调用及全局状态归属。三个入口在覆盖表保留 gap。
