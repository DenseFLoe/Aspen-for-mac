# 自定义表单库日语卫星的界面字符串

Aspen Plus V15 与独立 Aspen Properties V15 安装到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/ja-JP/AspenTech.AspenPlus.MMForms.CustomForms.resources.dll`。两套原版 MSI 的 File 序号分别为 2180 与 1817，安装包内成员均为 `aspentech.aspenplus.mmforms.5.01AE6323_4069_4985_B882_1C2F459EE258`。既有提取记录与安装件 SHA-256 均为 `697a773b7e0bc9254833bc49db679191080e350dfde95bad04db224722e3c986`，共 16,424 字节，文件与程序集版本均为 41.0.0.614。[来源](../../../../../../evidence/satellite-ja-JP-identity.json)

同目录 `AspenTech.AspenPlus.MMForms.CustomForms.resources.dll.Properties.Resources.resx` 通过静态验收，SHA-256 为 `6cfdafa750578af0f7f7838a754fcdcae82017e1faf93b53fb8fbbd14d57426a`。原始清单名为 `AspenTech.AspenPlus.MMForms.CustomForms.Properties.Resources.ja-JP.resources`。恢复 25 个字符串键、原始大小写、空格与占位符。通过 .NET Framework 的 ResXResourceReader 读取 RESX，ResourceWriter 回编，ResourceReader 再读。全部键、类型、值一致，回编资源流与原始资源流的 SHA-256 均为 `3034f2d8abf63c88ba428c47e935bf46db90cf2a9f715c0bcb97757f893ac43b`。中性表中的 `NewGridNamePattern` 在日语卫星中缺失。保留原版的键集合。[逐表核验](../../../../../../evidence/string-catalogs.json)

主库代码与布局在已定位的调用处读取外部 Localization 程序集的文本。静态分析已核对默认日语回退顺序，实际显示随运行文化而定，留到 Windows 重建时核对。[调用与键](../../../../../../evidence/localization.json) · [日语回退](../../../../../../evidence/japanese-fallback.json)
