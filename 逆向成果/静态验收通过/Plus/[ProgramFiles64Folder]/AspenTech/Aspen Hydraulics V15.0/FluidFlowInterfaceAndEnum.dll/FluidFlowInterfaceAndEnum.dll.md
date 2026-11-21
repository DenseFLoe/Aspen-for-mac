# FluidFlowInterfaceAndEnum.dll

2026-11-21，静态验收一组第 1 轮，**静态验收通过**。

- 原件来自 Plus 安装包 `FluidF~1.cab` 的 `FluidFlowInterfaceAndEnum.dl.3DBD9727_47A7_4C81_9D8D_6892422E034D`，路径为 `[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/FluidFlowInterfaceAndEnum.dll`。原件 32,192 字节，文件版本 41.0.0.99，SHA-256 为 `174cc8931a4b82045464e38ca610b3eaff6958180db349a68428c2209969ff6c`。
- 原件为 IL-only，程序集版本 41.0.0.0，公钥标记 `b05689b39deefbcd`，面向 .NET Framework 4.8。现存 W2 C# 的 Git blob 为 `a15e8cfa83330243a31764e0f1f24c068c58205a`。去掉末尾两行 ILSpy 更新提示并统一换行后，逐字对照本轮用 ILSpy 9.1.0.7988 从原件重新导出的 C#，正文一致。
- [可编辑 C#](FluidFlowInterfaceAndEnum.dll.cs) 的 SHA-256 为 `1f61f059e8f56b23db8460f74a9ab0752537303de7cb6d1e28bb9df4bb22eff4`。取完整正文，移除三行历史签名设置以便无签名编译。用 Roslyn 4.8.0-3.23524.11 和 C# 10，引用 Windows .NET Framework 的 `mscorlib.dll` 及同来源 `Data.dll`、`PropertyUtilities.dll` 编译。两份 Aspen 引用的 SHA-256 分别为 `a98aafc96c942cf2f9e6a2bb6ac3286fdd38c989948f3262fc25fc5d04217ad5` 和 `2beb41f3d8832cf1c481d70e8865e1acbbf84f35ac7b85579e75c666ee76b6ce`。原版的三个程序集引用标识均与编译样本吻合。
- 用 ILSpy 随附的 Mono.Cecil 核对 18 个作用域内类型、81 个字段、34 个属性和 72 个 MethodDef，共 205 条语义记录。比较类型作用域、基类型、接口继承、成员属性和标志、参数与返回类型、属性访问器和枚举常量，差异为 0。原版的 10 个接口带 `BeforeFieldInit`，接口无静态构造，比较时屏蔽此标志。原版 72 个方法都是无方法体的抽象声明。W2 IL 清单的 72 个令牌、方法所属类型、名称、RVA 与方法体有无均吻合。
- `pefile` 2024.8.26 核对两件 PE 均只含 `RT_VERSION/1/0`。958 字节版本资源逐字节吻合，SHA-256 为 `6f3ed1b61233245d2a25af26fd15aaabdfad3114036e25163a2e1d12996e7f54`。CLR 均无清单资源，原版无 P/Invoke。
- 强名称绑定和运行行为留待 Windows 重建阶段对照。
