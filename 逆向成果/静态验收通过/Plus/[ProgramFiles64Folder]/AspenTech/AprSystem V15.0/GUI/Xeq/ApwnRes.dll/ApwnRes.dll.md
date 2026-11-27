# ApwnRes.dll 静态验收

**静态验收通过。** 交付包含可编辑的 x64 汇编、PE 头与元数据、232 项资源以及从源码组装 DLL 的 Python 脚本。

- 产品 Aspen Plus / Aspen Properties V15.0，文件版本 `41.0 Build 614`。
- 安装相对路径 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/ApwnRes.dll`。
- 原件 SHA-256 `1ef6c43d2f4f4846d6279db0ce1ac2ad8c19157f3db8bcce4b3218a1fdd9bdae`。
- 源码包 SHA-256 `1bfb7ecc50b52aa0edc7c5cab67e9db69e4b07c97aa729627d88a0f2667fa6d4`。
- 独立复编的无签名 DLL 为 5,680,128 字节，SHA-256 `6188c4a8f7ab48b9907e780d3c3ff4d7b2cf4ef85f603fff068be5b856dadc13`。

六个 PE 节的文件内容逐字节一致。核验覆盖 58 个代码范围内的 927 条解码指令、26 项导入、35 条展开记录、8 条异常作用域记录、320 字节加载配置和 232 项资源。代码、位图资源和异常作用域的三项单变量改动均触发了预期拒绝。

原件尾部 10,280 字节的 Authenticode 证书作身份记录。复编产物清空证书目录并重算 PE 校验和，其余文件字节逐一吻合。Windows 运行对照留待重建阶段。

[源码及资源](ApwnRes.dll.source.zip) · [静态比较与独立复验](evidence/static-review.json) · [历史交付说明](ApwnRes.dll.归档说明.md)
