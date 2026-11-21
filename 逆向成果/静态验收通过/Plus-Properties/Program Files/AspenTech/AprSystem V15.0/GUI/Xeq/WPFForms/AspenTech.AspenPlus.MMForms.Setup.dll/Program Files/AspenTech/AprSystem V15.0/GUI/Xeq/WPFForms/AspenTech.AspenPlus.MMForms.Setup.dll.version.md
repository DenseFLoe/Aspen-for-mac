# 模拟设置表单程序集的 Windows 版本资源

此 RC 已通过静态资源验收。Aspen Plus V15 与 Aspen Properties V15 共用 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Setup.dll`。两个 MSI 均从各自的 `APRS~398.cab` 安装成员 `aspentech.aspenplus.41.01AE6323_4069_4985_B882_1C2F459EE258`，File 序号分别为 1885、1522。两套 MSI 和 CAB 的当前指纹与原盘点记录相符，原盘点的两个已解包成员和当前安装件均为 376,872 字节，版本 41.0.0.614，SHA-256 为 `247fbcc9e14b3021b744cfcdfd19c333b12cb5f7501e14036b868d7684887f40`。[来源与清单位置](../../../../../../evidence/identity.json)

同目录的 `AspenTech.AspenPlus.MMForms.Setup.dll.version.rc` 恢复了固定版本信息、11 个字符串以及语言与代码页 0/1200，文件 SHA-256 为 `89ea91e42f26ce2d80e5a6426815f44b46c2c028ab0e19b8a2d5ca81483a6a6b`。用 dnfile 0.18.0 和 pefile 2024.8.26 遍历资源目录，主库仅有一个 RT_VERSION，名称 ID 为 1，语言 ID 为 0。用 GNU windres 2.39 编译 RC 后回读，版本块的 1,102 字节与原版完全相同，SHA-256 为 `3674776c98a35b51e7e533c64a16443c476c072620ed48de0dafe83ffeda4469`。主库 CLR 资源区 RVA 和长度均为 0，ManifestResource 表为 0 行。[资源位置和回读证据](../../../../../../evidence/resources.json)

en-US 卫星程序集的两份包成员和已安装文件均为 359,464 字节，版本 41.0.0.614，SHA-256 为 `0b7b7ce7294630f92a23d77a62b57687f310a799d655850cc54e8d35241e9aee`。卫星程序集有 0 个方法定义和 1 份 CLR 清单资源。Windows 对两份安装件的 Authenticode 签名均返回 Valid，签名者为 Aspentech Corporation，均带时间戳证书。两者的 PE 证书表分别占 10,280 字节，CLR 强名称签名区均为空。原版签名随原件保留，重建件的文件属性显示留待 Windows 对照。[卫星来源](../../../../../../evidence/satellite-identity.json) · [签名核验](../../../../../../evidence/signing.json)
