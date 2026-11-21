# AspenTech.AspenPlus.Infrastructure.dll 的动画光标

来源为 Plus 与 Properties 共用的 AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.Infrastructure.dll，版本 41.0.0.614，原件 SHA-256 为 052e0a0e54d287397457200d4bdb87a0051ecff751f42d941114fa5e3c02908f。

主程序集的 6 个 ManifestResource 均为内嵌的 ACON 动画。JSON 按资源名保存原始帧次序、逐步时长（每秒 60 个时间单位）、热点与上下顺序可读的像素行。每个像素段记录宽度、XOR 颜色与 AND 掩码，可精确表示透明及异或像素。六个资源共 68 帧、76 个播放步骤；每帧均为 32×32、24 位颜色，热点均在左上角。各资源名均与 CustomCusors 中对应的属性 getter 匹配，QueryCursor 通过程序集的 GetManifestResourceStream 读取资源并构造 WPF Cursor。

使用 dnfile 0.18.0 定位资源，对每项 RIFF 目录和单图像 CUR 逐个解码。由已保存的 JSON 读回并重建全部 6 个 ANI，每个资源块均与原件逐字节一致。逐项 SHA-256、动画步序、时长、源记录偏移及回读证明见 cursor-checks.json。JSON 成果 SHA-256 为 2c52e31b8eaafa945729b75e7a129b6d4d6e39a6dab2ac018cd3e80d869deb5e。恢复程序为 AspenTech.AspenPlus.Infrastructure.dll.cursors.py，SHA-256 为 8ab7137ebfad5411d8c7279c5fc41d739870d3695c6e28c31e87fc61a8f4d6b6。

光标图像数据保存在本机。指针展示、系统计时和光标切换事件待 Windows 重建时对照。
