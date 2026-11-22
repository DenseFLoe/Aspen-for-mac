# Simdll.dll 第一轮复验

**returned**。上游对 `assigned_seq=1` 的候选提交 `c2caf377a8b15f04c1baf6e80f61a65e14b7194c` 进行了逐件复验。48 份交付材料已从该提交树按 blob 指纹回读。整件仍为静态验收未通过。[逐件报告](../../inbox/NATIVE-344/Simdll.dll.md)

从 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/344/Simdll.dll` 核实原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。受信上游判定器版本为 `e7f800d9aecad9cab1f14f3bec4852d36ee3ca3f`。运行 `python handoff/assignments/check-native-coverage.py NATIVE-344 --original <原件>` 得到 1,379 行入口覆盖、33 条重点引用和 1,360 项申报缺口，退出 2。

Ghidra 12.2 从原件导出 1,098 个函数，独立遍历将两套入口合并至 1,379 个，覆盖了 911 个原件锚点。19 个短叶函数已逐指令核对。业务入口 submit_proprun 在 0x39c79 调用 0x109c0，0x22a50 的分派可由原件 19 个表项复核。本轮另用 iced-x86 复跑 `verify_references.py`，核对 11,254 个不同类别与地址组合，其中 247 处间接转移待绑定。50 个资源叶已记录指纹。

续修时优先对照 0x31540 等原件入口和对应的链式异常表区间，核清跨区间控制流、调用方和数据归属，把对应实现与原件分支逐条关联。自动反编译给出的函数须继续处理跳转表和恢复警告。按各 RVA 的缺口列说明哪些已补齐，再重跑同一判定器和引用复核。[覆盖表](../../inbox/NATIVE-344/coverage.csv) · [资源与代码指纹表](../../inbox/NATIVE-344/artifacts.sha256)

提交回执 SHA-256 为 `bf3d5fe1fe36bb3b34c0f5fb6d949efa3bd77098b8c3be2babd9a8f9210d2292`，整套指纹表的 SHA-256 为 `a38056517ade35d5d9cc34f8de45d90b78792fdff860a18aa68846b6bd3fbe46`。
