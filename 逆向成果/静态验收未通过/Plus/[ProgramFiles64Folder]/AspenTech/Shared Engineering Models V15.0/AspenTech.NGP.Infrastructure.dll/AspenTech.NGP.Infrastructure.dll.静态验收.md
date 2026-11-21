# AspenTech.NGP.Infrastructure.dll 静态验收

状态为**静态验收未通过**。缺 PE 版本资源重建输入，IL 清单未列异常处理区段，C# 尾部混入未注释的工具输出。

- 原件来自 Aspen Plus V15.0（64 位）安装介质，原路径为 `[ProgramFiles64Folder]/AspenTech/Shared Engineering Models V15.0/AspenTech.NGP.Infrastructure.dll`。介质索引为 `SNGINE~9.cab` 的 `aspentech.ngp.infrastructure.208797FB_D4FD_4EAC_8DB4_85ECD58538FC`。从对应已安装位置只读复用，字节数为 508,352，SHA-256 为 `56162f7698cde1e27214299e899318096e3b9e16ce893b3102b7486792ba1f8d`，与介质清单和 GitHub 原件登记一致。
- 文件版本为 `41.0.0.39`，程序集版本为 `41.0.0.0`，CLR Flags 为 `0x9`，原件强名签名区为 128 字节。
- 使用 dnfile 0.18.0 / pefile 2024.8.26 读取原件。核对 150 条 TypeDef、547 条 Field 和 938 条 MethodDef。发布 IL 的所有 MethodDef 按令牌、名称及 RVA 对应，187 个 IL 方法体按偏移拼接原始指令字节后与 PE 一致。另有 751 个原版抽象声明，RVA 为零。
- 用 ILSpy CLI 9.1.0.7988 直接读取同指纹原件输出 C# 和 IL。C# 与发布文本逐行一致，末尾有两行未注释的工具提示，移除前不能直接作为 C# 输入。

## 原件资源与交付缺口

- CLR 无 ManifestResource 项。
- PE `RT_VERSION/1/0`，1,138 字节，SHA-256 为 `047054f8985eb9d717a36726cc26cf33bb2c9149fe1e25a5e6898a252d7a64c0`。C# 版本特性提供了部分字段，归档缺少重建该 PE 资源的输入。
- 原件有 1 个方法头设置了额外区段标志，涉及 `0x0600038B`。指令字节比较不包含方法体后面的区段。
- `SymbolLookupTable.ConvertKeywordToInteger`（`0x0600038B`）在本机 ILSpy 输出里有 `.try` 和 `finally`，发布 IL 清单列出指令和跳转，但缺少对应区段范围。补交区段记录后核对异常路径。20261119-42 的同名引擎 DLL 哈希为 `3e360a5dcdf5347db0af25e0a45830022b5df5edbba035fdeb77f1e87f40dbdf`，本件使用单独证据。

## 交付定位与复验

- [C# 导出](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.NGP.Infrastructure.dll.cs.txt)，Git blob 为 `2cdfe430f619b0ae2dad49a988e86f921ea07006`。
- [IL 清单](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/AspenTech.NGP.Infrastructure.dll.il.txt)，Git blob 为 `9f192e57df3ae56f26604e2f8a8a6fe53a4c2238`。
- 复核 C# 末尾第 44223 至 44224 行的提示是否已清理，按原件资源清单和指纹复核资源输入与逻辑。保留原交付文件并给出清理后的可编辑版本。
- Windows 重建阶段验证程序集引用、强名绑定及运行行为。
