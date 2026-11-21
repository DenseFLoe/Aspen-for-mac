# System.Data.SQLite.Linq.dll 静态验收

**静态验收未通过**。缺字符串资源、四份 EF 架构或映射资源及 PE 版本资源重建输入。发布 IL 缺已定位的异常处理区段，C# 文本末尾混入两行未注释的工具提示。

- 原件来自 Aspen Plus V15.0（64 位）。原路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/System.Data.SQLite.Linq.dll`，介质记录为 `APRS~562.cab` 中的 `system.data.sqlite.linq.dll.01AE6323_4069_4985_B882_1C2F459EE258`。复用与介质清单同指纹的本地原件，大小为 206,520 字节，SHA-256 为 `a409e2bf0b5c7c7507e4dba46e6bbf0d1a01a75bda68a81067d11c9dabea42b9`。
- 文件版本为 `1.0.118.0`，程序集版本为 `1.0.118.0`。PE 为 I386，CLR 标志为 `ILOnly, StrongNameSigned`。
- 用 .NET 8.0.100 SDK 的 `System.Reflection.Metadata` 读取 PE 与 CLR 元数据。原件有 33 条 TypeDef。发布 IL 的 470 个 `MD` 令牌与原件 MethodDef 一一对应。将各段 `IL_` 记录的十六进制指令按顺序拼接，与 `PEReader.GetMethodBody(rva).GetILBytes()` 比较，456 个方法体全部相同；另有 14 条原件 MethodDef 无方法体。
- 以 `dotnet ilspycmd.dll <同指纹原件>` 运行 ILSpy CLI 9.1.0.7988。统一换行、去掉文件末尾空白及版本提示后，重新导出的 C# 与发布 C# 一致。发布 C# 第 5269、5270 行是未注释的版本提示。

## 原件资源与交付缺口

C# 的 `SQLiteProviderServices` 从程序集读取提供程序清单、存储架构和映射。同一 SHA-256 也出现在 Aspen Properties V15（64 位）介质的同名 CAB 成员中，在现行总表和活动清单中共用这一个归档对象。

交付目录中只有 C#、IL 与报告。以下原件资源的内容和重建输入缺失。CLR 资源按 ManifestResource 记录和 CLR 资源目录读取，PE 资源用 pefile 2024.8.26 读取。

| 原件资源 | 字节数 | SHA-256 |
| --- | ---: | --- |
| `System.Data.SQLite.Properties.resources` | 2,024 | `f2f9e9242c1302bfe05e0bbcf4769279726c76046cd49b44559999b8676bcd89` |
| `System.Data.SQLite.SQLiteProviderServices.StoreSchemaDefinition.ssdl` | 26,880 | `cc41eb6ef92448aabba59ca019c30a896b8b12774a4350b53c0cddb29c469413` |
| `System.Data.SQLite.Common.ConceptualSchemaDefinition.csdl` | 11,916 | `c48fbb839ddf2eebd2dcb9452768bbc4853bc6ae7574e639edcb721903f8b266` |
| `System.Data.SQLite.SQLiteProviderServices.ProviderManifest.xml` | 39,784 | `e8c3bfa30a99ed33bc593609e1731d9d4504543e13caf28db1c6f2e6ab050b32` |
| `System.Data.SQLite.SQLiteProviderServices.StoreSchemaMapping.msl` | 21,106 | `119b3589bbc69e384d09e015d0d1979232477f1d79a5bdebfc2970bc5acac857` |
| PE `RT_VERSION (16) / 1 / 0` | 1,068 | `831e83fb9584863f5d47e11966aee2cd0f4b433407485293b0bf0eb5ecfc43e5` |

原件有 53 个异常处理区段。用 `PEReader.GetMethodBody(rva).ExceptionRegions` 可以复查。例如 `GenerateUpdateSql`（`0x06000001`）有 1 个区段，首段类型为 `Finally`。发布 IL 的该方法记录给出指令，缺用于恢复该区段的边界和处理信息。

## 交付指纹与复验

- [发布 C#](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/System.Data.SQLite.Linq.dll.cs.txt)的 SHA-256 为 `2c13d64aee903b4e5f4d2f8b005eedf55dc239281758575b63df636ac22360e7`。
- [发布 IL](v0.20261121-w2/%E6%AD%A3%E5%BC%8F%E5%AF%BC%E5%87%BA/System.Data.SQLite.Linq.dll.il.txt)的 SHA-256 为 `cbf25730f9daff551abfed228b751d50ae809a7785cf5609b1b1fea6e65d238b`。

修复时提供上述 CLR 资源及 PE 版本资源的重建输入，清除 C# 尾部工具提示，并在 IL 证据中补齐异常处理区段。随后按同一原件 SHA-256 复核成员、方法体、异常区段及资源内容。Windows 运行对照留到后续重建阶段。
