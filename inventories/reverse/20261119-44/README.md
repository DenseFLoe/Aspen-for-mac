# 第 20261119-44 轮 · 数据库目录中的 APED 共用组件

`PropertiesDatabase/Bin/AspenTech.APED.Core.dll` 暂存。与引擎目录的同名文件相比，5,695 个不同字节全部位于 PE 校验和字段和 Authenticode 证书表。代码、元数据、资源及重定位内容逐字节相同。修正后的 C# 静态回编通过，2,521 个方法定义已核对。原件指纹保持独立，七条来源状态已同步。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本机成果指纹](artifacts.csv)

本轮从 139 个回编差异中复核确认 111 个，剩余 28 个。修正了 56 个方法中的 57 处事务赋值顺序，并核对了回滚与释放路径。源码、指令和逐方法证据保存在本机。数据库行为留到 Windows 重建阶段比对。

累计 **47 / 1,397** 件通过静态验收，覆盖 **148 条不同来源**。另有 18 件暂存。

## 下一轮

核对 Aspen Properties 安装包 `PropertiesDatabase/DatabaseConfiguration` 下的同名异指纹原件。先比较 PE 区域，再确认可复用证据。[下一件来源](next.json)
