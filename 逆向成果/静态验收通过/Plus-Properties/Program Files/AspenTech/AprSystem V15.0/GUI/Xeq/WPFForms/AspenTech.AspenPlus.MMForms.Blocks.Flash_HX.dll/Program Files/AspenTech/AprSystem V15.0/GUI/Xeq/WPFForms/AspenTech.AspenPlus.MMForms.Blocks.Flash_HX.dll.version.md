# Flash_HX 的 Windows 版本资源

原件为 Aspen Plus 和 Aspen Properties V15 共用的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll`。两个 MSI 的包内成员均为 `aspentech.aspenplus.17.01AE6323_4069_4985_B882_1C2F459EE258`。本轮直接读取与两条包内记录同哈希的已安装文件。版本 41.0.0.614，807,464 字节，SHA-256 为 `4c08d219e3f2495e392635e21111065f6ec9adce1a8be49d0a3dd5eb8d8ca169`。

同目录的 `AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll.version.rc` 通过版本资源静态验收。它保留 RT_VERSION 的名称 ID 1、语言 ID 0、固定字段、11 项字符串和语言/代码页对 0/1200。成果 SHA-256 为 `f1d4d6c5d3b2bb9e5c8f72215087cf2c7608b5501d0190779e9e84ffdac00387`。

dnfile 0.18.0 和 pefile 2024.8.26 核对 PE 资源目录，仅有一个 1,166 字节的版本资源叶。GNU windres 2.39 从 RC 重新生成该叶，回读固定字段与字符串一致，整个负载逐字节相同，SHA-256 为 `94a123314af5d15415a7c378cd03e3900c371b1db2a54717e97c7f6aae4535ef`。本轮 `evidence/resources.json` 记录原件偏移、字段值及回读指纹。

原件没有 ManifestResource 表，CLR 资源 RVA 和大小均为零。界面文字有 100 个外部取值器引用，分属同版本 `AspenTech.AspenPlus.Localization.dll` 的 3 个类型。本轮 `evidence/localization.json` 将 51 个调用方法中的 211 条调用指令关联到外部方法、资源表及字符串键，100 个键均已在对应资源表中查到。版本资源范围内无待补字段；Windows 重建时可用本 RC 设置目标文件的版本信息，并核对交付程序集及语言包的实际加载。
