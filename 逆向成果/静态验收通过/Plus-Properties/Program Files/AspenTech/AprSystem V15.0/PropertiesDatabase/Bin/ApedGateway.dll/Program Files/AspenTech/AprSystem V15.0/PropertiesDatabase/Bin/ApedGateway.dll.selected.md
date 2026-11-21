# ApedGateway.dll 的 C# 选取件

本机原件为 `C:/Program Files/AspenTech/AprSystem V15.0/PropertiesDatabase/Bin/ApedGateway.dll`。
文件版本 `41.0.0.11`，程序集版本 `41.0.0.1`。原件 SHA-256 为 `f96569b43f1c5eb0975aaee3c85da45adfbade739006679f57d3d2b5c52922ba`。
Plus、独立 Properties、Enterprise Database Server 三个安装包各有一条 Bin 成员和一条 GAC 投递成员。加上本机件，共七条同指纹来源。
三个 Bin 成员依次位于 `DBMGR4~4.cab`、`DBMGR4~6.cab`、`DBMGR4~4.cab`，GAC 投递成员均位于各包的 `DBMGR~60.cab`。

整件已通过静态逆向验收。选取件包含原来的 129 个顶层类型中的 126 个。数据库连接与维护、身份验证相关的三个类型及其实现保存在本机完整 C# 中。
选取件首行为说明，原 C# 行号加一即可定位。省略区间及指纹见选取记录。运行时签名、绑定及行为留待 Windows 重建对照。
[选取记录](../../../../../evidence/code-extraction.json) · [托管验收](../../../../../evidence/managed-audit.json)

归档成果 SHA-256 为 `3e97ffaf7bff543c120be08c94ebb2e7402ac871ea77cf0fdcee5146dd3c0cb8`。
