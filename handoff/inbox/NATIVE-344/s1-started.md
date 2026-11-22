# NATIVE-344 开工及首批核对

owner upstream，assigned_seq=1。使用已回读的 `issue-materials/344/Simdll.dll`，输入提交 `64670801de54e990f975aaeda06e89340c0e4e08`，373,288 字节，实际 SHA-256 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。

原件导出表把 ordinal 93 的 `submit_proprun` 定位到 RVA 0x39c00。其运行时范围为 [0x39c00, 0x39cd3)，完整解码 49 条指令。0x39c79 的 `e8 42 6d fd ff` 直接调用 RVA 0x109c0，旧标签 `sub_109c0` 对应该未命名导出之外的内部地址。运行时表将其单列为 [0x109c0, 0x10a0f)，完整解码 24 条指令。逐指令有 10 处直接调用，其中 6 处经跳板绑定到 mmg.dll 导入。该导出另读取 mmg.dll 的 prop_retrieve_results 和 topfinfo 数据项。

证据文件 `s1-entry-evidence.json`（SHA-256 `7ead58779d16f89e4fabea21f49626549a0e4a897ef31af406c850cfd46ad435`）列出两个区间的原始字节摘要、每个调用点、指令字节、目标和可核对的 IAT 槽。当前仍在开工阶段。可从内部调用 0x31540、0x22a50、0x15a10 及全件 911 个入口锚点继续，核对控制流和可编辑实现，再完成逐址覆盖表。
