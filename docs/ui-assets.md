# UI 图片来源与复核

2026-11-14，从本机 Aspen Plus V15 (41.0.0.614) 已安装资源与当前空案例界面提取 **97 个图标**：79 个内嵌 PNG，18 个截图裁片。仅保存使用到的图像，不包含原始 DLL、EXE、安装包、许可证或工具。

`ui/icons/aspen-v15.png` 是无缩放、无损 RGBA 图集；`manifest.json` 逐项记录来源资源名、SHA-256 或截图裁片坐标以及图集矩形。PNG 原始透明度保留；截图裁片保留原版背景，适用于浅蓝功能区。小图标按 16px、大图标按 32px 显示，Qt 根据禁用状态生成灰显图像。少数裁片尺寸为 17–37px，由按钮适配显示；高 DPI 下不宣称原生矢量精度。

内嵌 PNG 来源为 `AspenTech.Visualisation.CommonImages.Wpf.dll` 的 `.g.resources`，用 dnfile 仅解析资源数据。截图来自 computer-use 对原版窗口的直接观察。完整截图和资源枚举保留在本机忽略目录 `.local/`；上传的图片只包含此任务相关界面。

这些是原产品图像，版权归其原权利人所有；本仓库未为其授予新的许可。按钮图像并不代表已连接 Aspen 计算服务。

图标接口参考 [Qt QIcon 文档](https://doc.qt.io/qt-6/qicon.html)。本机验证工具采用 [aqtinstall 官方项目 CLI](https://aqtinstall.readthedocs.io/en/latest/cli.html) 安装隔离的 Qt 套件，工具均留在 `.local-tools/`。
