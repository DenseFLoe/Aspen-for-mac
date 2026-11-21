# CalcExcelAddInRes32.dll 第 1 轮修复

原件 SHA-256 为 `3bfe609cd8bcb0c0abdde6e1160df971dd4a073b67e3e2b15e78a2e62d96a343`，27,176 字节，版本 41.0.0.614。来源为 Aspen Plus V15 安装包 `ASPE~269.cab` 的 `calcexceladdinres32.dll.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`，本轮读取的已安装副本与既有安装包成员记录同指纹。原文件路径见同目录对象说明。

## 已修复的代码

- `100022bc` 的两个条件和一条回滚路径、`100022db` 的两次调用和返回值，均由 Ghidra 12.2 重新导出并按 PE 原始字节核对。五条相对调用全部解析至 `1000292b`，该桩执行 `mov al, 1; ret`。线程附加调用方为 `10001c83`，线程分离调用方为 `10001c7c`。修订版补齐历史的 84 个伪 C 函数加 2 个失败标记，使该视图覆盖历史 86 个汇编入口。
- `100019f0` 清理辅助函数和 `10002a10/50/80` 三个清理入口在 Ghidra 中可见，历史汇编未列出。三个入口分别由原 `.rdata` 中 `100037c8`、`100037f4`、`10003820` 引用。`10002a50` 以 `EBP-0x18` 作接收对象并尾跳至 `100019f0`。其余两处读取父栈帧指针后调用 sized delete 对应项。补充汇编保留读写偏移、实参、栈恢复和尾跳。
- 原 PE 还显示三个异常分派桩 `10002a24/5d/94`，分别由 `10001455/100016d5/10001a15` 的立即数入栈指令引用。分派桩检查 cookie，装入三张带重定位的 `FuncInfo`，尾跳 `100028cb` 对应的 `__CxxFrameHandler3`。补充汇编保留了分派桩、表字段和清理动作指针。
- `100029b0`、`100029c6`、`100029e0` 同属历史汇编的栈探测块。修订版以汇编保留两个对齐入口、逐页读取、交换栈指针及搬移返回地址。原伪 C 对该部分的抽象仅随历史文件保留。

## 静态核对

Ghidra 12.2 用本机 headless 启动器导入原件并对照 IDA 9.5 的原地址清单。机器类型是 `0x014c`，PE32 基址为 `0x10000000`，入口 RVA 为 `0x1f9d`，无 CLR 目录。原 `.text` 的虚拟大小为 6,833 字节，目录同时包含导入、导出及 PE 资源。

按函数起点比较，IDA 为 86 个，Ghidra 为 91 个，共同项为 82 个。Ghidra 多列的 `10001d93`、`10001e4c`、`10001e59` 在历史汇编的两个进程初始化或清理函数中已有指令；`100029c6` 和 `100029e0` 与上面的栈探测块合并处理。IDA 独有的 `10001080`、`10002117`、`100028cb`、`10002925` 继续使用历史汇编与原地址进行复验。

四份 PE 资源都从原件解析并列入指纹表。两个字符串块和版本信息写入资源脚本，清单保留可编辑 XML。复验一组继续确认资源重编后的逐项一致性、其余伪 C 的调用约定及完整性，再作整件静态结论。Windows 行为留到重建对照阶段。

## 成果指纹

- [CalcExcelAddInRes32.dll.c.txt](CalcExcelAddInRes32.dll.c.txt) · SHA-256 `957560fd536f52c46f4a11a96e0ff55c738b204b250f8a80e86d3f2ee14404b9`
- [CalcExcelAddInRes32.dll.x86.asm](CalcExcelAddInRes32.dll.x86.asm) · SHA-256 `53f688389fd358cb18ab985f385ef88965cac96b01e7d4b5dd2cca756c53a24f`
- [CalcExcelAddInRes32.dll.resources.csv](CalcExcelAddInRes32.dll.resources.csv) · SHA-256 `39ba7d3f0b42d333a5ba46e917062317c09ae8c9681c6654958853a6468ca9b0`
- [CalcExcelAddInRes32.dll.rc](CalcExcelAddInRes32.dll.rc) · SHA-256 `3b74363e011522f1999f91b0e8634a25c0bc512a51fcda98af9416a5f225a715`
- [CalcExcelAddInRes32.dll.manifest](CalcExcelAddInRes32.dll.manifest) · SHA-256 `4bb79dcea0a901f7d9eac5aa05728ae92acb42e0cb22e5dd14134f4421a3d8df`
