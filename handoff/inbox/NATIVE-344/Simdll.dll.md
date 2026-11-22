# Simdll.dll 静态复核

原件来自 Plus-Properties 的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll`，PE 版本 41.0.0.614，AMD64，373,288 字节。原件 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。[固定原件](https://github.com/DenseFLoe/Aspen-for-mac/blob/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/344/Simdll.dll) · [工单 #344](https://github.com/DenseFLoe/Aspen-for-mac/issues/344)

整件仍有 959 个原生入口缺口。本轮对 401 个已确定的导入跳板提供可编辑实现并逐字节重组。结合首轮 19 个短函数，1,379 行中已有 420 行通过原指令对照。首轮的业务入口、运行时区间、Ghidra 及原始资源索引保留。[第五号交付](s5-submission.md) · [覆盖表](coverage.csv)

每个新入口完整执行一条六字节的 RIP 相对间接尾跳转，目标为原件导入表的一个指针槽。16 个 DLL 提供 401 个槽，325 项按名、76 项按序号导入。源码经实际 C 编译、对象文件符号定位及 401 处 AMD64 REL32 重定位后，2,406 字节与原件全部相等。重点调用表有 434 项。完整引用索引独立核对 11,299 个不同的类别与指令位置组合，含 1,961 处直接 IAT 转移。[源文件及复查方法](s5/import-thunks.c.md) · [逐指令证据](s5/import-thunks.asm) · [完整引用](references.csv)

本轮附有 50 个资源叶的原始数据及指纹，均按类型、标识与语言逐项核对。12 组图标共指向 14 个图像资源，组内声明与实际内容长度相符。菜单、对话框、字符串等资源的使用方仍需业务代码或框架调用证据。[可还原资源](s5/resources.json) · [资源索引](resources.csv)

继续从首轮确定的 0x31540 主区间及其 0x3163a、0x32580 链式片段复查分支、数据和调用归属，逐址解决剩余 959 项缺口。247 处待定间接转移仍需目标依据。Windows 运行行为留待相应阶段实测。[首轮静态裁定](../../outbox/NATIVE-344/s1-decision.md) · [首轮原始说明](https://github.com/DenseFLoe/Aspen-for-mac/blob/f1ed621740bf27fabf86b4780d9fdcb75df279ca/handoff/inbox/NATIVE-344/Simdll.dll.md)

复查本轮构建与资源使用 `python s5/verify.py <Simdll.dll> <zig>`。全量引用使用 `python verify_references.py <Simdll.dll> <本件目录>`。自仓库根执行 `python handoff/assignments/check-native-coverage.py NATIVE-344 --original <Simdll.dll>`，本轮为 1,379 个入口、434 个引用和 959 项缺口，退出 2。[构建结果](s5/rebuild.json) · [引用结果](crosscheck.json)

本目录当前文件记录在 [artifacts.sha256](artifacts.sha256)。首轮提交、指纹清单和数据可从原提交回读，首轮清单 SHA-256 为 `a38056517ade35d5d9cc34f8de45d90b78792fdff860a18aa68846b6bd3fbe46`。本轮实际更新了覆盖、调用、引用、统计和逐件说明。[固定的首轮清单](https://github.com/DenseFLoe/Aspen-for-mac/blob/f1ed621740bf27fabf86b4780d9fdcb75df279ca/handoff/inbox/NATIVE-344/artifacts.sha256)
