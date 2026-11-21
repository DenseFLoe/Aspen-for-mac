# 第 20261119-47 轮 · DatabaseConfiguration.exe

独立 Aspen Properties 的数据库配置启动器通过静态验收，覆盖 1 条安装包来源。x64 原生 AppHost 与 .NET 8.0.8 模板逐字节核对。复现的 GUI 启动器与原件的 6 个 PE 区段一致，覆盖 413 条 x64 展开记录、同目录 DLL 绑定和 11 项 Windows 资源。差异限于签名和校验和。

生成脚本调用同版 .NET SDK 的 HostWriter。原件签名经 Windows 验证为有效，实际启动留待 Windows 重建验收。[逐件说明](../../../reverse/01-completed/20261119-47/Properties/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/PropertiesDatabase/DatabaseConfiguration/DatabaseConfiguration.exe.md) · [发布清单](../../../reverse/01-completed/20261119-47/publication.csv) · [累计台账](ledger.csv) · [来源增量](status-delta.csv) · [归档指纹](artifacts.csv)

累计 **49 / 1,397** 件通过静态验收，覆盖 **150 条不同来源**。另有 19 件暂存，1,329 件未开始。

## 下一轮

复核同目录的 `Microsoft.Extensions.Configuration.Abstractions.dll`，优先用同版官方包核对。[下一件来源](next.json)
