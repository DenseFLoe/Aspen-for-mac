# Npgsql.dll

独立 Aspen Properties V15.0 x64 的 DatabaseSetup 使用 `DATABA~2.cab` 成员 `npgsql.dll3.DEA401F6_A35E_4C40_96BF_A7CCDD6EF46D`。文件与程序集版本均为 8.0.3.0，大小为 1,415,208 字节，SHA-256 为 `02ea73194ff5407d521c8c4cf679b6c3814418d12c6a935c8cede0fbf67d6cb8`。Windows 签名检查返回 `Valid`，签名者为 Aspentech Corporation。[安装包来源](evidence/sources.json)

**已通过静态验收。** 与第 56 轮原件相比，仅 PE 校验和及 Authenticode 证书表有差异，复用已核验的 7,256 个方法定义、7,132 个 IL 方法体、29 条托管字符串和 Windows 版本资源。 两个安装包原件在证书表前只有校验和中的两个字节不同。将 PE 校验和与 Security Directory 归零并移除证书表后，两个原件与上游 NuGet 的 net8.0 程序集逐字节一致。归一化后的 SHA-256 为 `68655f1ba023af58623a76282dab3f25911ecd68893b57e1ad066c71574602f7`。[本轮 PE 对照](evidence/acceptance.json) · [第 56 轮逐方法核对](https://github.com/DenseFLoe/Aspen-for-mac/blob/f562e4993f14272c63e9ffb35a6e4365d1872877/reverse/01-completed/20261119-56/Properties/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/PropertiesDatabase/DatabaseConfiguration/evidence/methods.csv)

本轮沿用第 56 轮已回编核验的可编辑 C#、RESX 和 PostgreSQL 许可证。源码包含 .NET 8 生效分支和生成的连接字符串及日志代码。回编参数、资源逻辑名及强名称签名输入见第 56 轮逐件说明。[第 56 轮逐件说明](https://github.com/DenseFLoe/Aspen-for-mac/blob/f562e4993f14272c63e9ffb35a6e4365d1872877/reverse/01-completed/20261119-56/Properties/%5BProgramFiles64Folder%5D/AspenTech/APrSystem%20V15.0/PropertiesDatabase/DatabaseConfiguration/Npgsql.dll.md)

Windows 加载、PostgreSQL 交互与重建件的签名处理留到 Windows 重建阶段核对。

文件 SHA-256 为 `6fe6576f0ac399f488da77ff984e7f41b9784ef3079554704c7ed7c04819bf43`。
