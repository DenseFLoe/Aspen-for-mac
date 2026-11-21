# 网格表单控件库的 Windows 版本资源

Aspen Plus V15 和独立 Aspen Properties V15 共同安装 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMForms.GridForms.Controls.dll`。两个 MSI 的 File 序号分别为 1944、1581，均落在各产品的 `APRS~457.cab` 中，成员键为 `aspentech.aspenplus.52.01AE6323_4069_4985_B882_1C2F459EE258`。核对原包指纹、File 和 Media 表，复用两套包各自的已解包指纹。包成员与安装件均为 87,080 字节，文件及程序集版本均为 41.0.0.614，SHA-256 为 `9ebf2c982799bf58d7408f28056d35ce0488344be272212b285b518463582266`。[来源](../../../../../evidence/identity.json)

同目录的 `AspenTech.AspenPlus.MMForms.GridForms.Controls.dll.version.rc` 已通过静态验收，SHA-256 为 `61ee84e88bd0e9bd56121792886b8f05e67089479e1ee4930f11cc1c403fd9f8`。主件含一个 Win32 版本块，资源类型 16、名称 1、语言 0，起始文件偏移为 74,840。RC 保留固定版本字段、全部 11 个字符串和翻译项 0/1200。GNU windres 2.39 回编后，1,222 字节的版本块与原件逐字节一致，SHA-256 为 `fedb9b49b694868d59ba5a60f2b70bf106b5a613ae5743f7e505bf6b0aea1b60`。pefile 2024.8.26 回读的版本字段一致。主件的 CLR 资源区和清单资源行数均为零。[资源核验](../../../../../evidence/resources.json)

Windows 对主件及其 en-US 卫星返回有效的 Aspentech Corporation Authenticode 签名，均带时间戳证书。两个 PE 的证书表各占 10,280 字节，CLR 强名称签名区均为空。版本在 Windows 文件属性中的实际呈现留待重建对照。[签名核验](../../../../../evidence/signing.json)
