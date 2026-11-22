# zedstwu.dll 第一轮复验

**退回续修（returned）。** 原件 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，固定候选 `30717e476e2182c3f62db16f48e37c242043a379`，assigned_seq=1。已核对候选清单内全部文件及固定的 254 对旧 ASM/C 函数记录。[逐件报告](../../inbox/NATIVE-350/zedstwu.dll.md) · [原错误报告](https://github.com/DenseFLoe/Aspen-for-mac/issues/350)

旧错误报告点名的内存复制路径和版本资源均通过本次专项复核。重新编译 C 中的可编辑 AMD64 实现，0x16560 至 0x1760a 的 4,266 字节与原件吻合。0x175cf 片段复制三个四字节值，正确保留剩余长度并跳回 0x16e4a。四张表共 217 项，表内地址引用经重定位后均指向相应指令。模式和阈值两个全局量已核对，128 个导入跳板另有 768 字节匹配。800 字节的版本资源由可编辑树重组后完全一致。

旧反汇编中 0x15d08 的条件转移可到 0x180c0，其六字节尾跳指向原件 IAT 槽 0x19150 的 `_crt_at_quick_exit`，候选已补此入口。0x15bd5 的调用指向 0x15d48。被调例程有快速终止和可返回的备用路径。若备用路径返回，下一条 0x15bda 的 INT3 会执行。

运行固定候选的 `verify.py` 和 `check-references.py`，输出分别与 rebuild.json、references-check.json 相同。受信判定器以同一原件返回 2，255 个入口中 130 个已核实，125 个仍为 gap。3,567 条引用包含 44 条未决间接转移。四个业务导出 DSWU_EUDL01、DSWU_IUDL01、DSWU_UDL01I、DSWU_ZUDL01 的实现仍待逐件核验。后续优先按这四个导出的原件区间、调用、数据和原伪代码修复；其余缺口逐址见[覆盖表](../../inbox/NATIVE-350/coverage.csv)。

本轮提交回执 SHA-256 为 `7a487d1362e3e9a0164fb1812c4715ff68b09e2931ca7339b50deef5e7b4764f`，清单为 `09bf616c5fe0db2a081e7722ab4642ac9e70a0ca087eed34c0cfd5728e578ad0`，重组记录为 `6031e9e143142dd2c1eec793977651a35e760f857a8a69ce9114e644e9fd09f0`。
