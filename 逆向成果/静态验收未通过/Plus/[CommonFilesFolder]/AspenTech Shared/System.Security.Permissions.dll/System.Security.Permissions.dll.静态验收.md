# System.Security.Permissions.dll 静态验收

2026-11-21，三组第 2 轮。结论为**静态验收未通过**，交入修复清单，复验组为 3。

原路径为 `Plus/[CommonFilesFolder]/AspenTech Shared/System.Security.Permissions.dll`。原件 SHA-256 为 `006d4d13c4c4c8327b3a94dc502d0e91114c1c495b408f6b78c6b30a3062a14f`。

原件来自 Aspen Plus V15 安装包 `DBMGR~20.cab` 的成员 `system.security.permissions..00C8CD4F_F851_484A_A03B_6432F5895243`，共 31,392 字节。原件为 I386 IL-only、强命名程序集，程序集版本 8.0.0.0，文件版本 8.0.23.53103。复用已有安装包提取件，按 SHA-256 核对到本组清单。

## 核对结果

- 用 PowerShell 7.6.9 的 `System.Reflection.Metadata` 和 `PEReader` 从原件逐项读取 MethodDef、RVA 和方法体。与 W2 IL 清单逐条对照，56 个定义均有方法体，880 个 IL 指令字节一致。原件还有 15 个 TypeDef（包含模块项）、20 个 FieldDef。
- 用 ILSpy 9.1.0.7988 重新导出 C#。统一换行后，正式导出仅在文件末尾多了两行 ILSpy 版本更新提示。C# 的 SHA-256 为 `6a7418771804b0d08069dbf3157c26f9d170c302b511b048a2c7d3b12f99bf45`，IL 清单为 `dc72cf8421a3ca47e66be095e91b84f75d28d0bd82a34824c803f1faa7f31db9`。
- 原件 CLR 清单中的 `FxResources.System.Security.Permissions.SR.resources` 为 1,113 字节，包含八个消息键，SHA-256 为 `95d715f29f6b8210c1c79fab680e38e759ec9bd46bbf5d970bddb6592cbf4383`。导出的 `System.SR.get_ResourceManager`（`0x0600000E`）以 `FxResources.System.Security.Permissions.SR` 为资源类型，`get_PlatformNotSupported_CAS`（`0x06000016`）查询其中的同名键。两份正式导出均缺少对应资源定义。
- 原件还嵌入 526 字节的 `ILLink.Substitutions.xml`，SHA-256 为 `f80a629fb59c31c1ab5e888f376c3272804c64b24c0aa51893839f185a099815`。正式交付目录没有这份链接器替换配置。

## 复查与修复

从原件的 CLR 资源目录按 `ManifestResource.Offset` 读取嵌入项，先读四字节长度，再用 `ResourceReader` 枚举 `.resources` 键。将其中的八条消息恢复为可编辑资源，保留资源基名和链接器配置，并去掉 C# 末尾的工具提示。复验时确认原程序集的类型转发、资源绑定与修订交付一致。Windows 运行行为留待后续阶段。
