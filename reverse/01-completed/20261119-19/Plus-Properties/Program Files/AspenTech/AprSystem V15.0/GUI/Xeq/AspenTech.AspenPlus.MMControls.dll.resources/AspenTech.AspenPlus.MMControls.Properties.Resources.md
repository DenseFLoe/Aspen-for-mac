# 中性语言资源

原件为 Aspen Plus 与 Aspen Properties V15 共用安装目录 `AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMControls.dll`，版本 41.0.0.614，SHA-256 `bd4b5cdf3e6c8ede0dbb54b9297581bb79fa7289fe45c71def67b5bf1107842c`。本轮来源记录核对安装包及安装位置。

静态验收通过。原清单为 `AspenTech.AspenPlus.MMControls.Properties.Resources.resources`，SHA-256 `7a2b3a52bbb882c8ab0b2253ff6b55279b986d070aba5dc03c922517f1ef0254`。264 个字符串键逐一对照原 ResourceReader 的长度前缀、UTF-8 文本指纹和恢复 RESX 的读回值。另有两个 System.Drawing.Bitmap，分别以 ResXFileRef 引用 `serialized/UpArrow.bmp`、`serialized/DownArrow.bmp`。同名 g.resources BMP 的调色板字节与序列化副本有差异，各自独立还原。Windows 重建时，将本轮本机图像包内容展开在此 RESX 旁。

成果为 `AspenTech.AspenPlus.MMControls.dll.resources/AspenTech.AspenPlus.MMControls.Properties.Resources.resx`，SHA-256 `7d25ea1c89017861a5666c95cbcffb513c9271f4b48df89b51e9a8eeb27313fb`。
