# ifmsmn.exe 第 2 轮静态验收

验收日期为 2026-11-21，结论为**未通过**，复验组为 4。

原件为 `Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ifmsmn.exe`，文件版本 `41.0 Build 605`，SHA-256 为 `066c1c3bd87dc68d8da10cd5971820c7369ca4db479e45686d2e695a41ffb671`。使用本机已有安装包提取件，并以 SHA-256 对照主线活动清单。第一份交付基于 [W2 发布包](https://github.com/DenseFLoe/Aspen-for-mac/releases/tag/v0.20261121-w2)，两个正式导出的 Git blob 已与主线原目录核对。

用 pefile 2024.8.26 核对原件 PE 架构、入口及资源，对照两份 W2 导出的函数起始地址、伪 C 警告和数据引用。原件为 AMD64，入口 VA 为 `0x1400030f8`。 [核对数据](ifmsmn.exe.静态验收.json)。

IDA 9.5 的伪 C 与反汇编均列出 199 个函数地址，地址和顺序一致。伪 C 在 `0x140001000` 与 `0x1400029c0` 标记常量内存写入警告。函数直接引用 `IFMS_LUNITS` 和业务数据地址，例如 `unk_14000754C`，交付中缺少这些数据的类型、定义及初始化。原件还有一项 PE 版本资源。

核对两处警告对应的实际访问并补全业务数据定义、初始化与版本资源重建输入，再送回第四组复验。 Windows 运行对照留在重建阶段。
