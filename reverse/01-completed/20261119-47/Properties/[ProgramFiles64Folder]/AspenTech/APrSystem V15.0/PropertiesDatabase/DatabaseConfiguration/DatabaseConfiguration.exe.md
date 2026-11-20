# DatabaseConfiguration.exe · 原生 GUI 启动器

原件来自独立 Aspen Properties V15.0 x64 的 `DBASEC~3.cab`，版本 `1.0.0.0`，528,936 字节。包内成员为 `databaseconfiguration.exe.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。原件 SHA-256 为 `2addbcc2b2014e86312de219f289dfd29dfae5af6adc7619c2ea6d24513e0d14`。[来源记录](evidence/sources.json)

状态为**已完成静态验收**。唯一可执行区段 `.text` 与微软 .NET 8.0.8 win-x64 AppHost 模板字节一致，入口 RVA 为 `0x11240`，无 TLS 回调。413 条原生展开记录与模板一致，逐条检查了代码范围及展开信息位置。PE 解析器在同一组链式展开数据上对原件和模板发出相同的三条提示，相关数据逐字节相同。[AppHost 模板](https://www.nuget.org/packages/Microsoft.NETCore.App.Host.win-x64/8.0.8) · [展开范围](evidence/unwind-ranges.csv)

从 EXE 所在目录解析 `DatabaseConfiguration.dll`，再通过 `hostfxr_main_startupinfo` 交给 .NET，也保留标准 AppHost 的旧接口回退。单文件包头偏移为 0。随包配置声明 `net8.0`，两个共享框架的基线均为 `8.0.0`。原生实现可从对应的 .NET 源码核对。[原生入口](https://github.com/dotnet/runtime/blob/08338fcaa5c9b9a8190abb99222fed12aaba956c/src/native/corehost/corehost.cpp) · [Windows 启动组件](https://github.com/dotnet/runtime/tree/08338fcaa5c9b9a8190abb99222fed12aaba956c/src/native/corehost/apphost)

## 生成启动器

使用 PowerShell 7 与 .NET SDK 8.0.400 中的 `Microsoft.NET.HostModel.dll`。脚本绑定同目录托管程序集，设置 GUI 子系统，并从该 DLL 复制 Win32 图标、版本和应用清单。Windows 重建阶段可以将 `-ManagedAssembly` 指向重建的 DLL。

```powershell
./DatabaseConfiguration.exe.ps1 -HostModelPath 'C:/sdk/8.0.400/Microsoft.NET.HostModel.dll' `
    -AppHostTemplate 'C:/hostpack/runtimes/win-x64/native/apphost.exe' `
    -ManagedAssembly 'C:/input/DatabaseConfiguration.dll' -OutputDirectory 'C:/output'
```

本轮使用第 46 轮保留的原版 DLL 试生成 518,656 字节的启动器。所有 6 个 PE 区段逐字节一致，包含 8 个图标图像、1 个图标组、1 个版本资源和 1 份清单。整文件差异限于 PE 校验和、证书目录和 10,280 字节的原版 Authenticode 证书块。原版签名经 Windows 验证为有效。生成的启动器为未签名产物。[静态对照](evidence/apphost-audit.json) · [第 46 轮 DLL](../../../../../../../../../inventories/reverse/20261119-46/README.md)

Windows 重建阶段需使用重建的 DLL 及配套配置验证实际启动、窗体和运行时错误提示。脚本 SHA-256 为 `fe09b164baeda83d433571bc6220afa226dfcd28124ee6495342ac9d7961d168`。
