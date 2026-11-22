# NATIVE-344 第五号分配交付

owner 为 upstream，assigned_seq=5。固定原件在 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/344/Simdll.dll`。373,288 字节，SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。第五号任务卡对应提交 `35b0ed3f4ec7c4e3f9b83779d372b4ea2304baf2`。[任务卡](../../assignments/NATIVE-344-s5.md) · [开工回执](s5-started.md)

401 个六字节入口已交付可编辑源码、指令、IAT 槽、导入标识和源行对应。直接编译本轮 C 文件得到 401 个符号及 401 个 AMD64 REL32 重定位。按 RVA 还原后，2,406 字节与原件逐一相等。保留首轮 19 个已核实叶函数。本轮覆盖表共有 420 个 covered 和 959 个 gap。[源码与构建说明](s5/import-thunks.c.md) · [覆盖表](coverage.csv)

首轮 33 条重点引用与 401 个入口的导入尾跳均已登记。完整引用索引保留首轮 11,254 条，补入原先遗漏的 45 个位置。iced-x86 1.21.0 从原件独立解码，11,299 组类别及指令地址唯一。直接 IAT 转移 1,961 处，其余类别及 247 处待定间接转移沿用首轮。[复核输出](crosscheck.json)

本轮可从交付文件直接恢复 9 类、50 个资源的 20,368 字节。重新读取 PE 资源目录，核对键、RVA、长度、代码页和全部内容。12 组图标的 14 条资源引用已与相同语言的 14 个实际图像及其长度对应。菜单、对话框与其他业务用途的调用和数据关系仍待核对。[资源及组内引用](s5/resources.json) · [复跑结果](s5/rebuild.json)

运行 `python handoff/assignments/check-native-coverage.py NATIVE-344 --original <Simdll.dll>` 输出 `checked 1379 coverage rows, 1379 tool-native entries, 434 call records, 959 declared gaps`，退出 2。剩余原件入口仍按覆盖表逐址保留，整件提交上游复验。[逐件说明](Simdll.dll.md) · [当前交付指纹](artifacts.sha256)
