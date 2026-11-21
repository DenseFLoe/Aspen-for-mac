# 第 20261119-46 轮 · DatabaseConfiguration.dll

独立 Aspen Properties 的 .NET 8 数据库配置组件通过静态验收，覆盖 1 条安装包来源。95 个方法定义已逐令牌核对，C# 静态回编通过，77 个方法体规范化后相同，14 个差异已逐项核对。2 个 WinForms 初始化方法一致，2 份 CLR 资源和 11 项 PE 资源逐字节一致。 五条编译警告见验收证据。Windows 重建阶段需将两个窗体资源和 PE 资源并入重建工程，并对照窗体操作与数据库配置行为。 [累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本机成果指纹](artifacts.csv)

两处窗体初始化代码共恢复 30 项控件字段及 15 处事件绑定。两个窗体共用一个图标。GitHub 发布清单收录了 C#、RESX、RC、应用清单和验收证据。原图和带原始指令字节的 IL 存在本机。[发布清单](../../../reverse/01-completed/20261119-46/publication.csv)

累计 **48 / 1,397** 件通过静态验收，覆盖 **149 条不同来源**。另有 19 件暂存。

## 下一轮

复核同目录的原生启动文件 `DatabaseConfiguration.exe`，并核对它与托管程序集的交接。[下一件来源](next.json)
