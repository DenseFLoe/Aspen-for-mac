# 自定义表单库的 Windows 版本资源

Aspen Plus V15 与独立 Aspen Properties V15 安装到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.CustomForms.dll`。两套原版 MSI 的 File 序号分别为 1920 与 1557，安装包内成员均为 `aspentech.aspenplus.104.01AE6323_4069_4985_B882_1C2F459EE258`。既有提取记录与安装件 SHA-256 均为 `ca9a063e500a53615bce87c85606d7e37ea76269cf26d3f291e0b693cf3d5a0e`，共 123,944 字节，文件与程序集版本均为 41.0.0.614。[来源](../../../../../evidence/identity.json)

同目录 `AspenTech.AspenPlus.MMForms.CustomForms.dll.version.rc` 通过版本资源静态验收，SHA-256 为 `4ab4f30afffc63aa8796f33cfb7cebbde7a6d995789bd3476b44ca7eaa2a6500`。资源类型 16、名称 1、语言 0，文件偏移 111,704，保留全部 13 个固定字段、11 个字符串和翻译项 0/1200。GNU windres 2.39 回编的 1,134 字节与原版逐字节一致，SHA-256 为 `589d4f6bcefeda533eae634b6e43872bb555d18220015a829bd451a694450ffe`。pefile 2024.8.26 回读字段全部相符。Windows 文件属性中的版本显示留待重建阶段对照。[资源核验](../../../../../evidence/resources.json) · [签名核验](../../../../../evidence/signing.json)
