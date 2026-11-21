# Interop.Happ.dll

2026-11-21，静态验收一组第 1 轮，**静态验收未通过**。修复后交回一组复验。

- 原件来自 Plus 安装包 `CONVER~1.cab` 的 `interop.happ.dll.1D11B5FC_1A1C_4DD8_9532_F20DAEBA859C`，路径为 `[ProgramFiles64Folder]/AspenTech/Converter V15.0/Interop.Happ.dll`。原件 112,072 字节，文件版本 21.0.0.0，SHA-256 为 `07adeeecea88b51eb0fcd72c9b3d4f86e39011662532ffedd89f6a8fce644c23`。
- 原件为 IL-only，程序集版本 21.0.0.0，公钥标记 `b05689b39deefbcd`。Mono.Cecil 核对 105 个类型定义（除 `<Module>`）、327 个字段、432 个属性、65 个事件、1,412 个 MethodDef。交付 IL 的 1,412 个令牌、声明类型、方法名、RVA 及方法体有无与原件相符。原件有 44 个 IL 方法体，无 P/Invoke 和托管资源。PE 仅含 `RT_VERSION/1/0`（684 字节，SHA-256 `fe23932cb791132ebc218f90d04541e759ef7aa0bf18ea898569893e797af56d`）。
- C# 交付 Git blob `b4d2e06c1ac106929f2d207124e18ab12608ffa4`。移除文件末尾两行 ILSpy 更新提示后，以 Roslyn 4.8.0-3.23524.11、Windows .NET Framework 的 `mscorlib.dll`、`System.dll`、`System.Core.dll` 离线编译。结果为 52 个错误和 1 个警告。原交付第 5525 行附近的 13 个委托承载原版的 `TypeLibType(FHidden)`，C# 报 CS0592。第 7939 行的 `IAPHappEvents_EventProvider` 用普通 `add_*`、`remove_*` 方法承载 13 个接口事件，编译报告 26 个 CS0470 和 13 个 CS0535。例如 `OnDialogSuppressed` 的接口添加访问器为 `0x06000055`，提供者的对应实现为 `0x06000568`（RVA `0x248C`，121 字节）。第 8876 行的 `Finalize` 还产生 CS0465 警告。
- 16 处局部变量解码提示覆盖 `0x06000559` 至 `0x06000566`、`0x06000582` 和 `0x06000584`。ILSpy 9.1.0.7988 显示空局部变量签名，Mono.Cecil 在这 16 个原版方法中均读到 0 个局部变量。
- 修复时依据原版 COM 元数据和 44 个方法体，恢复事件访问器、委托属性及结束清理语义。修订后逐项对照事件映射、GUID、封送属性与方法 IL。运行行为留待 Windows 对照阶段。
