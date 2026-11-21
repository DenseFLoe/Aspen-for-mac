# System.Data.SqlClient.dll 静态验收

**静态验收未通过**。缺字符串资源、SQL 元数据 XML 和 PE 版本资源重建输入。发布 IL 缺已定位的异常处理区段，C# 文本末尾混入两行未注释的工具提示。

- 原件来自 Aspen Properties V15（64 位）。原路径为 `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/PropertiesDatabase/DatabaseConfiguration/System.Data.SqlClient.dll`，介质记录为 `DBASEC~7.cab` 中的 `system.data.sqlclient.dll3.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。复用与介质清单同指纹的本地原件，大小为 268,320 字节，SHA-256 为 `eb4c01207fb5882cbb29d285c8be55134b91d347d4221d522638d383e046c06a`。
- 文件版本为 `4.700.23.52603`，程序集版本为 `4.6.1.6`。PE 为 I386，CLR 标志为 `ILOnly, StrongNameSigned`。
- 用 .NET 8.0.100 SDK 的 `System.Reflection.Metadata` 读取 PE 与 CLR 元数据。原件有 64 条 TypeDef。发布 IL 的 1224 个 `MD` 令牌与原件 MethodDef 一一对应。将各段 `IL_` 记录的十六进制指令按顺序拼接，与 `PEReader.GetMethodBody(rva).GetILBytes()` 比较，1202 个方法体全部相同；另有 22 条原件 MethodDef 无方法体。
- 以 `dotnet ilspycmd.dll <同指纹原件>` 运行 ILSpy CLI 9.1.0.7988。统一换行、去掉文件末尾空白及版本提示后，重新导出的 C# 与发布 C# 一致。发布 C# 第 5657、5658 行是未注释的版本提示。
- 原件有 24 条转发，C# 有 24 处 `TypeForwardedTo`。

## 原件资源与交付缺口

例如 `SqlDataRecord` 构造器抛出 `PlatformNotSupportedException` 的实现可见于该原件的 `0x06000004` 指令序列。该观察仅适用于此 SHA-256 的 DatabaseConfiguration 根目录变体。

交付目录中只有 C#、IL 与报告。以下原件资源的内容和重建输入缺失。CLR 资源按 ManifestResource 记录和 CLR 资源目录读取，PE 资源用 pefile 2024.8.26 读取。

| 原件资源 | 字节数 | SHA-256 |
| --- | ---: | --- |
| `FxResources.System.Data.SqlClient.SR.resources` | 57,218 | `2e939b55677530446e0fcfc1d31d42b0e8fa8ca1340b250103a741d5a016bc6f` |
| `System.Data.SqlClient.SqlMetaData.xml` | 96,204 | `f320fef978b4a63083fd64260b490001d6027602d2faa785168758d4e94449f2` |
| PE `RT_VERSION (16) / 1 / 0` | 1,080 | `8ecc3913b88f6f962b25ef989f164bdf36efacc39fd70cfad7f54403898a443f` |

原件有 1 个异常处理区段。用 `PEReader.GetMethodBody(rva).ExceptionRegions` 可以复查。例如 `GetResourceString`（`0x060000D6`）有 1 个区段，首段类型为 `Catch`。发布 IL 的该方法记录给出指令，缺用于恢复该区段的边界和处理信息。

## 交付指纹与复验

- [发布 C#](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/System.Data.SqlClient.dll.cs.txt)的 SHA-256 为 `17028b0d32b96c58e5f597d1f69774a1290da80b629491cdffbeff2f611f613b`。
- [发布 IL](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/System.Data.SqlClient.dll.il.txt)的 SHA-256 为 `2e77a48f82cd8c8199f23987034cd717d5aba93358c9c8bbe8505386eef86627`。

修复时提供上述 CLR 资源及 PE 版本资源的重建输入，清除 C# 尾部工具提示，并在 IL 证据中补齐异常处理区段。随后按同一原件 SHA-256 复核成员、方法体、异常区段及资源内容。Windows 运行对照留到后续重建阶段。
