# 逐文件逆向当前状态

2026-11-19，第 20261119-03 轮。当前处于开发总纲第 2 步。需要逆向的 1,397 个不同原文件中，累计 9 个已通过逐文件归档验收，对应 27 条去重来源。

- **本轮新增 1 件：`AspenTech.AspenPlus.Printing.dll`。** 两个安装包成员与本机安装件字节一致。已核对 44 个方法的指令与异常区、分页迭代器、预览布局和控件连接。两个独立进程直接调用原版，各通过 98 项无界面断言；未测试真实打印机或模态预览。[本轮验收记录](../inventories/reverse/20261119-03/README.md)
- **剩余工作：** 34 个未完成、15 个暂存、1,339 个未开始；处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-03/ledger.csv)
- **本机入口：** `.local/reverse-round-20261119-03/`。4 份成果及各自说明在 `01-completed/`；`signoff.json` 记录验收和证据指纹，`views/` 与 `verification.json` 保存四份完整状态视图及逐行核验结果。[累计归档指纹](../inventories/reverse/20261119-03/artifacts.csv) · [上一轮](../inventories/reverse/20261119-02/README.md)
- **下轮首选 `AspenTech.CommonShell.Controls.Startup.dll`。** 清单版本 `14.0.0.0`，安装件 SHA-256 为 `6476bbd3d22073fd098b52bafea482b1f8b87a001ac31c472ada76b90ce18414`。它有 Plus、Properties 及安装件三条来源；旧 C# 仅覆盖 15 个顶层类型中的 2 个。两包均定位到 `APRS~620.cab`。下轮先读取两个成员核对字节，再按 125 个方法、2 个嵌套类型和 2 个资源集对照，当前仍为未完成。
