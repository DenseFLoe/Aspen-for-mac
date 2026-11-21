# Microsoft.Extensions.Primitives.dll 静态验收

状态为**静态验收未通过**。缺两项托管资源和 PE 版本资源重建输入，C# 尾部混入未注释的工具输出。

- 原件来自 Aspen Plus V15.0（64 位）安装介质，原路径为 `[CommonFilesFolder]/AspenTech Shared/Microsoft.Extensions.Primitives.dll`。介质索引为 `DBMGR~10.cab` 的 `microsoft.extensions.primiti.00C8CD4F_F851_484A_A03B_6432F5895243`。从对应已安装位置只读复用，字节数为 49,936，SHA-256 为 `3c6ea55594433e2f0340227bd1588fbab1ba8a10c99319b528cc5573259340cb`，与介质清单和 GitHub 原件登记一致。
- 文件版本为 `8.0.23.53103`，程序集版本为 `8.0.0.0`，CLR Flags 为 `0x9`，原件强名签名区为 128 字节。
- 使用 dnfile 0.18.0 / pefile 2024.8.26 读取原件。核对 50 条 TypeDef、97 条 Field 和 290 条 MethodDef。发布 IL 的所有 MethodDef 按令牌、名称及 RVA 对应，287 个 IL 方法体按偏移拼接原始指令字节后与 PE 一致。另有 3 个原版抽象声明，RVA 为零。
- 用 ILSpy CLI 9.1.0.7988 直接读取同指纹原件输出 C# 和 IL。C# 与发布文本逐行一致，末尾有两行未注释的工具提示，移除前不能直接作为 C# 输入。

## 原件资源与交付缺口

- CLR ManifestResource `FxResources.Microsoft.Extensions.Primitives.SR.resources`，1,012 字节，SHA-256 为 `9c481fe5f18e6b755368f195232b05973f59db4a23ca6089e9693fb0e3bd82b8`。当前目录没有相应资源输入。
- CLR ManifestResource `ILLink.Substitutions.xml`，534 字节，SHA-256 为 `dfb7cb6a820ed69224654a44e1e2abc5c0f660e09a7079b30a798ea23bea6640`。当前目录没有相应资源输入。
- PE `RT_VERSION/1/0`，1,552 字节，SHA-256 为 `c410c570a04e84ad608b94b4d1ce8d871e7fd5b947ea0841d385df59f57bfe05`。C# 版本特性提供了部分字段，归档缺少重建该 PE 资源的输入。
- 原件有 5 个方法头设置了额外区段标志，涉及 `0x0600000A`、`0x0600005A`、`0x0600006A`、`0x0600006B`、`0x06000105`。指令字节比较不包含方法体后面的区段。
- 导出中 `System.SR` 通过 `ResourceManager` 获取字符串，并处理 `MissingManifestResourceException`。需恢复资源名、键和值，以及链接器替换配置。

## 交付定位与复验

- [C# 导出](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Extensions.Primitives.dll.cs.txt)，Git blob 为 `c839e1ecf1cd3ecf442c79d6f67e27c9eced2399`。
- [IL 清单](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/Microsoft.Extensions.Primitives.dll.il.txt)，Git blob 为 `f1836e03adf3015e9cda41e1544460b081fc8a5a`。
- 复核 C# 末尾第 2352 至 2353 行的提示是否已清理，按原件资源清单和指纹复核资源输入与逻辑。保留原交付文件并给出清理后的可编辑版本。
- Windows 重建阶段验证程序集引用、强名绑定及运行行为。
