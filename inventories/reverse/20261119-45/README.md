# 第 20261119-45 轮 · .NET 8 版 APED Core

`PropertiesDatabase/DatabaseConfiguration/AspenTech.APED.Core.dll` 暂存。它面向 .NET 8，与第 44 轮 .NET Framework 4.8 副本的程序集引用和 15 个方法实现有差异。2,521 个方法定义已核对，唯一的 Windows 版本资源已逐字节复原。一条独立 Aspen Properties 安装包来源已同步。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本机成果指纹](artifacts.csv)

C# 12 静态回编通过，57 处事务赋值和 7 处委托构造已对齐。1,762 个方法体经规范化比较一致，另有 65 个复用逐方法证据，剩余 31 个回编差异有待确认。回编采用 NuGet 的 .NET 8 权限程序集资产，27 条引用版本兼容警告留待 Windows 重建验收。源码、IL 及复核证据保存在本机。

累计 **47 / 1,397** 件通过静态验收，覆盖 **148 条不同来源**。另有 19 件暂存。

## 下一轮

处理同一安装目录中的 `DatabaseConfiguration.dll`，核对代码及界面资源。[下一件来源](next.json)
