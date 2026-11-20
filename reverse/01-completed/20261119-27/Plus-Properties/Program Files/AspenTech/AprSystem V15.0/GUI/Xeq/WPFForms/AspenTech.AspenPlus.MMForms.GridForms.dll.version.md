# 网格表单主库的 Windows 版本资源

Aspen Plus V15 和独立 Aspen Properties V15 共同安装 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.GridForms.dll`。在各自 MSI 中，File 序号分别为 1870 和 1507，均定位到各自 `APRS~383.cab` 的 `aspentech.aspenplus.50.01AE6323_4069_4985_B882_1C2F459EE258` 成员。本轮核对两套原包及 CAB 指纹并复用既有成员提取记录。两份成员与安装件均为 528,424 字节，文件和程序集版本均为 41.0.0.614，SHA-256 为 `e404e43bee7f55f6927cfa7d411343a3e37a371a286a9d424c05f3db1f85a614`。[来源](../../../../../../evidence/identity.json)

同目录的 `AspenTech.AspenPlus.MMForms.GridForms.dll.version.rc` 已通过静态验收，SHA-256 为 `cad44e57b8305341f79b97902fcf206560e1e3ab1c1019d913abb4a0a29684ac`。主库有一个 Win32 版本资源，类型 16、名称 1、语言 0，于文件偏移 516,184 开始。RC 保留固定字段、全部 11 个字符串和翻译项 0/1200。GNU windres 2.39 回编的 1,134 字节与原版版本块逐字节一致，SHA-256 为 `ef3dc02b2a7241f40b3e56425f983226b06c3e2fdbce5647d524d214bf5c4c5a`。pefile 2024.8.26 回读的字段一致。主库的 CLR 资源区为空，清单资源行数为零。[资源核验](../../../../../../evidence/resources.json)

Windows 对主库和 en-US 卫星均返回有效的 Aspentech Corporation Authenticode 签名，两者均带时间戳证书。两个 PE 的证书表各占 10,280 字节，CLR 强名称签名区均为空。版本在 Windows 文件属性中的实际显示留待重建对照。[签名核验](../../../../../../evidence/signing.json)

