# AspenTech.NGP.UnitOperationBlock.dll

## 静态验收结论

通过。已交付完整可编辑 C# 和用于回编的 Win32 版本资源。回编后原有 319 个方法签名与方法体全部得到核对。Windows 加载、单元模型注册、结晶模块初始化、Plex 数据读写及仿真行为留待 Windows 重建对照阶段。

## 原件

| 项目 | 值 |
| --- | --- |
| 产品 | Aspen Plus V15 |
| 安装路径 | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.UnitOperationBlock.dll` |
| 文件版本 | `41.0.0.39` |
| CLR 程序集版本 | `41.0.0.0`，`PublicKeyToken=null` |
| 大小 | 4,535,336 字节 |
| SHA-256 | `ddd1a2de405c21b649800a33d2d948b326a340ee07982e0b69448bdae8f2904d` |
| 来源 | `DenseFLoe/Aspen-for-mac`，`codex/reverse-unsuccessful-85` 固定提交 `9559b75390876346c69b185dbaaba18692a7af75` |
| 仓库路径 | `原版文件/Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AspenTech.NGP.UnitOperationBlock.dll` |

按 GitHub LFS 媒体地址取得原件并校验 SHA-256。本机已有同指纹副本，先用它开始源码导出，最终核验使用固定提交下载件。Plus 安装清单将此件定位于 `ENGINE~1.cab` 的 `aspentech.ngp.unitoperationb.9DD71637_68A3_4F40_BE0C_34ABF98F3116` 成员。

旧制作者报告的输入为 132 字节，SHA-256 为 `b7470359c4e5af21fbd567fb009e9c54a6d70a06c99647b880995a935ec37eeb`。用原件的 SHA-256 和大小生成 Git LFS v1 文本，长度和 SHA-256 均与报告中的输入完全吻合。这解释了旧报告的 `DOS Header magic not found`。 [旧报告](https://github.com/DenseFLoe/Aspen-for-mac/blob/9559b75390876346c69b185dbaaba18692a7af75/%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E6%9C%AA%E6%88%90%E5%8A%9F/Plus/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/Engine/Xeq/AspenTech.NGP.UnitOperationBlock.dll/v0.20261121-w2/%E5%88%B6%E4%BD%9C%E8%80%85%E6%8A%A5%E5%91%8A/AspenTech.NGP.UnitOperationBlock.dll.md)

## 工具与操作

1. 以 pefile 2024.8.26 和 Mono.Cecil 确认 PE/CLR 结构。目标为 IL-only，原生导入仅为 CLR 启动入口 `mscoree.dll!_CorDllMain`，没有本件原生实现需要交给 Ghidra。托管清单资源数为 0。
2. 使用本批共享 ILSpy 9.1.0.7988，参数为 `--disable-updatecheck -p -o <隔离源码目录> -r <V15 Engine/Xeq> <原件>`。共导出 105 份 C# 文件。保留程序集声明和实现，将文件级命名空间合并到单个 C# 交付件。恢复原件的 .NET Framework 4.8 目标声明和可空性范围，包括 `GetLocations` 的匿名委托，由编译器重新生成 `NullableAttribute`、`NullableContextAttribute` 和模块 `RefSafetyRulesAttribute(11)`。
3. 用本机 Roslyn 4.8.0（.NET SDK 8.0.100 附带）从交付 C# 和 `.win32.res` 回编。编译参数为 `/noconfig /nostdlib+ /target:library /optimize+ /debug:portable /deterministic+ /langversion:12`，用 `/out:` 指定原程序集文件名、用 `/win32res:` 载入随附资源。框架引用取 Windows .NET Framework 4.8 的 `mscorlib.dll`、`System.dll`、`System.Core.dll`。三个 Aspen 引用取已安装 V15 的同一 `Engine/Xeq` 目录。编译完成，存在一条原有私有字段 `plexDocument` 未使用的告警。
4. 使用 Mono.Cecil 和本机 `CanonicalBodies.cs` 比较方法。按完整方法签名与泛型元数匹配，规范化短指令、局部变量和跳转目标，保留操作数、常量与异常处理边界。以原始定义令牌、回编定义令牌和可获取的源码行号记录。编译器生成的方法可无源码序列点。

## 验收证据

- 原件和回编件均有 120 条 TypeDef（含 `<Module>`）、319 个方法、88 个字段、52 个属性、0 个事件。319 个方法均有 IL。318 个方法在常规规范化后逐指令匹配。
- `CrystalBlock::.ctor()`（`0x0600001e`）的全部指令单独核对。原件在创建 `GEN` 的 `SizeArea` 后保存一个局部引用，10 次为属性设置器重新装载该引用，最后一次将同一引用传给已有列表的 `Add`。回编件以 10 条 `dup` 保留同一个栈引用，最后由 `Add` 消耗。两份方法均无分支和异常处理器，仅替换该段引用保留方式并重编号局部槽后，指令序列完全匹配。
- 961 项语义元数据记录中 953 项一致。8 项差异均为编译器生成的 `<PrivateImplementationDetails>` 下静态数组容器的可见性，原件为 `NestedAssembly`，回编为 `NestedPrivate`。容器显式布局、大小、对齐、10 个 FieldRVA 数据片段及其引用均一致。该差异不影响本件的代码和对外程序集绑定，若以反射枚举私有编译器类型，仍可观察到可见性标记不同。
- 外部类型和成员引用集合按完整签名与所属程序集一致，无同签名跨作用域歧义。原件和回编件唯一的 PE 资源 `RT_VERSION/1/0` 数据均为 1,162 字节，内容指纹一致。随附 `.win32.res` 用于保留该版本块。
- 回编 DLL 的 SHA-256 是 `24f77fb04e892888a0c4628f465242f63d31d8cb69c6a091d1454c79978af22b`，构建产物保留在本次隔离工作目录内。

| V15 直接引用 | SHA-256 |
| --- | --- |
| `AspenTech.NGP.Infrastructure.dll` | `3e360a5dcdf5347db0af25e0a45830022b5df5edbba035fdeb77f1e87f40dbdf` |
| `AspenTech.AspenPlus.Engine.Structures.dll` | `f11a69eb9b44250f1f6bc69878b6a72bcb6eab1181badf8ba114e337e30610ac` |
| `AspenTech.NGP.PhysicalProperties.dll` | `afe464d6c72920c6842d1018e7c32955b56427d12389b61da301b4ebd521cce2` |

同目录 CSV 记录原版和回编方法的对应关系。同目录 JSON 记录 PE、静态数据、外部引用、元数据差异与 Crystal 构造函数的复核结果。本次正式交付未发现凭据或项目永久本地保护材料。`InternalsVisibleTo` 中的值是程序集公钥。核验输入随本批输入清理规则处理。

## 交付指纹

| 文件 | SHA-256 |
| --- | --- |
| `AspenTech.NGP.UnitOperationBlock.dll.cs` | `e293aaf608758da3649260c6579194fea07ad552e02ca1c2465959ba50393ecc` |
| `AspenTech.NGP.UnitOperationBlock.dll.win32.res` | `eaf23327b0bb3d501d8c3a0b3a5f82c67403e00173bcb3fc54c7d2a956b14e67` |
| `AspenTech.NGP.UnitOperationBlock.dll.methods.csv` | `cbf7810b51f4be5bdefe084871057ca0e08b8a2a8360ff742927c5c3d49dd904` |
| `AspenTech.NGP.UnitOperationBlock.dll.evidence.json` | `d6edc355b7ae7886f17707d5bcd2501f9574b3dd8db5d477806ac3581eeb4b80` |
