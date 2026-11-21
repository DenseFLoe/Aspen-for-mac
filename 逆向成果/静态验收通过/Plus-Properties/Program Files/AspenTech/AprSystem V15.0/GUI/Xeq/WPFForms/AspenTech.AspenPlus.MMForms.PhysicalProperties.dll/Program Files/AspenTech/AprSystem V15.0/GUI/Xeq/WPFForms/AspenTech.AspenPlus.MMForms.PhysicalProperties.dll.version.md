# 物性表单程序集的 Windows 版本资源

Aspen Plus V15 与独立的 Aspen Properties V15 共同安装 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PhysicalProperties.dll`。两个原版 MSI 的 File 序号分别为 1876 和 1513，均指向各自 `APRS~389.cab` 中的成员 `aspentech.aspenplus.37.01AE6323_4069_4985_B882_1C2F459EE258`。本轮只读核对 MSI 的 File、Media 和原包指纹，复用各安装包已有解包记录。两个包成员和安装件均为 1,021,992 字节，文件及程序集版本均为 41.0.0.614，SHA-256 为 `65ce3da43613a061e2b316c518ef9c6f530ef74cc106544313a3cf70373d45a9`。[来源](../../../../../../evidence/identity.json)

同目录的 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.version.rc` 已通过静态验收，SHA-256 为 `54f8b0ede5164b0ad21bdd4426311f082627f81ad9d7e1750bfdfbea55057d75`。主库有 1 个 Win32 RT_VERSION 资源，名称 ID 为 1、语言 ID 为 0、文件偏移为 1,009,752。RC 保留固定版本字段、11 个字符串与语言及代码页 0/1200。GNU windres 2.39 回编后，1,198 字节的版本块与原件逐字节相同，SHA-256 为 `5749f13eed387ed15998ec11f94324694b5ba106f79ee320798413f9818c152b`。pefile 2024.8.26 回读的字段一致。dnfile 0.18.0 确认主库的 CLR 资源区和清单资源行数均为零。[版本块与回读](../../../../../../evidence/resources.json)

页面和图片来自 en-US 卫星程序集。该卫星在两个原版包的成员与安装件同 SHA-256，为 `e34abb6976c613c377efe1ced99c0f1585c393b237b61e47ffb5ce39ccb7ca1c`。Windows 的 Authenticode 检查对主库和卫星均返回 Valid，签名者为 Aspentech Corporation，两者均带时间戳证书。两份 PE 证书表长度均为 10,280 字节，CLR 强名称签名区均为空。文件属性页的实际展示留待 Windows 重建对照。[卫星来源](../../../../../../evidence/satellite-identity.json) · [签名](../../../../../../evidence/signing.json)
