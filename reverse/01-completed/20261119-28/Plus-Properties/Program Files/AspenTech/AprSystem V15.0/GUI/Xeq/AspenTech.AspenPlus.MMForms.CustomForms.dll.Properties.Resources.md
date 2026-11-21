# 自定义表单库主库中性表的界面字符串

Aspen Plus V15 与独立 Aspen Properties V15 安装到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.CustomForms.dll`。两套原版 MSI 的 File 序号分别为 1920 与 1557，安装包内成员均为 `aspentech.aspenplus.104.01AE6323_4069_4985_B882_1C2F459EE258`。既有提取记录与安装件 SHA-256 均为 `ca9a063e500a53615bce87c85606d7e37ea76269cf26d3f291e0b693cf3d5a0e`，共 123,944 字节，文件与程序集版本均为 41.0.0.614。[来源](../../../../../evidence/identity.json)

同目录 `AspenTech.AspenPlus.MMForms.CustomForms.dll.Properties.Resources.resx` 通过静态验收，SHA-256 为 `d72b605a3da042436d14b670f117de1989ec83c5a48fbc33f07bfde9a0008082`。原始清单名为 `AspenTech.AspenPlus.MMForms.CustomForms.Properties.Resources.resources`。恢复 26 个字符串键、原始大小写、空格与占位符。通过 .NET Framework 的 ResXResourceReader 读取 RESX，ResourceWriter 回编，ResourceReader 再读。全部键、类型、值一致，回编资源流与原始资源流的 SHA-256 均为 `ea351970aad0bf629728c5dd377b562a14e79ae97ddc7fd4e73b98fbac471884`。中性表包含 `NewGridNamePattern`，原值为 `Tab {0}`。[逐表核验](../../../../../evidence/string-catalogs.json)

主库代码与布局在已定位的调用处读取外部 Localization 程序集的文本。静态分析已核对默认日语回退顺序，实际显示随运行文化而定，留到 Windows 重建时核对。[调用与键](../../../../../evidence/localization.json) · [日语回退](../../../../../evidence/japanese-fallback.json)
