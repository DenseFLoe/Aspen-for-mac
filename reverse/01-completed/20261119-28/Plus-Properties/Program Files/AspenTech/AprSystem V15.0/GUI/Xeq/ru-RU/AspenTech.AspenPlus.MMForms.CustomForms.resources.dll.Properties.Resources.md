# 自定义表单库俄语卫星的界面字符串

Aspen Plus V15 与独立 Aspen Properties V15 安装到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ru-RU/AspenTech.AspenPlus.MMForms.CustomForms.resources.dll`。两套原版 MSI 的 File 序号分别为 2199 与 1836，安装包内成员均为 `aspentech.aspenplus.mmforms.8.01AE6323_4069_4985_B882_1C2F459EE258`。既有提取记录与安装件 SHA-256 均为 `5326835c02ef0846571d109acc546ab6ee4ed8926b46798ef2850101e46a18a8`，共 16,424 字节，文件与程序集版本均为 41.0.0.614。[来源](../../../../../../evidence/satellite-ru-RU-identity.json)

同目录 `AspenTech.AspenPlus.MMForms.CustomForms.resources.dll.Properties.Resources.resx` 通过静态验收，SHA-256 为 `3dfaac00ad1f2d7b7332a2c6c837712d7238d363ab493a0276c6f08bd22b8bfe`。原始清单名为 `AspenTech.AspenPlus.MMForms.CustomForms.Properties.Resources.ru-RU.resources`。恢复 26 个字符串键、原始大小写、空格与占位符。通过 .NET Framework 的 ResXResourceReader 读取 RESX，ResourceWriter 回编，ResourceReader 再读。全部键、类型、值一致，回编资源流与原始资源流的 SHA-256 均为 `20458d8d81a5caea477fb2df37c0d0b2e5e8714f303011119cd54d95961975d7`。键集合与中性表一致。[逐表核验](../../../../../../evidence/string-catalogs.json)

主库代码与布局在已定位的调用处读取外部 Localization 程序集的文本。静态分析已核对默认日语回退顺序，实际显示随运行文化而定，留到 Windows 重建时核对。[调用与键](../../../../../../evidence/localization.json) · [日语回退](../../../../../../evidence/japanese-fallback.json)
