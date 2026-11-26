# AspenTech.Dashboard.Contracts.dll

**静态验收通过。**

原件来自本机 Aspen Plus V15.0 的 AprSystem，文件版本与产品版本均为 `41.0.0.19`。原相对路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.Dashboard.Contracts.dll`。原件为 20,520 B，SHA-256 为 `d91c7a16092771b7e83848ebf98f1be36d6573e59d82fae98ffacba8634fba93`。本机安装统一清单也记录了 Aspen Properties 的共用归属。

[可编辑 C# 源码](AspenTech.Dashboard.Contracts.dll.cs)由 ILSpy 9.1 导出。使用 .NET 9.0.321 自带 Roslyn 和 .NET Framework 4.8 引用静态回编，记录 `ATVInterfacesVB.dll` 与 `Microsoft.Practices.Unity.dll` 等依赖的文件名和指纹。按声明类型和签名对照原件与直接回编件的 56 个 MethodDef，其中 20 个有方法体，36 个是接口抽象声明。20 个方法体逐一配对，按原件成员重绑令牌。原件中共用方法 RVA 的两个构造器在回放中恢复共用位置。

直接回编件为 10,240 B，SHA-256 为 `51127ebe964cdefee632dd6671557f946ffe52091be7ec0cb3693a6bcf2ea9df`。分别从直接回编件和原件中读取托管资源流及 Win32 资源目录。两边均有 1 项托管资源和 1 项 Win32 版本资源，内容逐字节相等。[逐方法、资源和编译输入核查](evidence/AspenTech.Dashboard.Contracts.dll.static.json)

独立复核和本次接手均用固定指纹的 v4 归档从空目录运行包内的 `token_replay.py`。在准备 Python 的 `pefile` 依赖及证据中列明的编译器与引用后，执行 `py -3 token_replay.py <v4归档路径> <空输出目录>`。本次退出码 0，回放产物的 SHA-256 与本机原件相同。v4 本机证据包 SHA-256 为 `590414aadf1825e3de454a9a70f0e9f08ff139a98033835a4d90b8bb3780938b`。最终映像回放原件 CLR 元数据、CodeView 记录和证书表以复现原布局，20 个方法体来自源码复编。本阶段验证证书表字节，运行行为和签名有效性留待后续检查。

[历史归档说明](AspenTech.Dashboard.Contracts.dll.%E5%BD%92%E6%A1%A3%E8%AF%B4%E6%98%8E.md) · [原分支的逐件报告](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/AspenTech.Dashboard.Contracts.dll.md)
