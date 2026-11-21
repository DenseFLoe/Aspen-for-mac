# AspenPlus.exe 原生资源脚本

Aspen Plus V15 主程序 `Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenPlus.exe`，文件版本 `41.0.0.614`，SHA-256 为 `006d17165e434fb9263c5614844352604a72cf727a929a7174f1aca002c39bf9`。Plus 安装包 `ASPE~253.cab` 成员 `aspenplus.exe.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0` 与已读取的安装件指纹一致。

`AspenPlus.exe.native.rc` 长 1,001 字节，SHA-256 为 `4e9e7c8539f5a00615c2d61af44b4cacddc64437281cb99f1494362d11ea324c`。脚本覆盖 Windows 版本、应用清单、图标组和该组的八帧图像。它引用同目录的可编辑 `AspenPlus.exe.manifest` 和原图标 `images/aspen_plus.ico`，图标归档于本机 ZIP。

已通过静态验收。GNU windres 生成的资源叶键与原件一致。八个 RT_ICON、一条 RT_GROUP_ICON 及一条 RT_VERSION 资源与原件逐字节相同。RT_MANIFEST 经 BOM 和换行规范化，XML 内容、权限级别和公共控件依赖一致。验证覆盖资源构建。Windows 重建时核对安装后的图标显示与资源装载。[原生资源验收](../../../../../evidence/native-resources.json)
