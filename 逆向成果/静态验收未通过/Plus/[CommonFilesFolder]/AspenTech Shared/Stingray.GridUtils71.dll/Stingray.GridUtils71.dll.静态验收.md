# Stingray.GridUtils71.dll 第 2 轮静态验收

验收日期为 2026-11-21，结论为**未通过**，复验组为 4。

原件为 `Plus/[CommonFilesFolder]/AspenTech Shared/Stingray.GridUtils71.dll`，文件版本 `1.0.1.1`，SHA-256 为 `04ef7136488b4b977f182f365d7755635f31a281726d7ddab86971625fdff9cb`。使用本机已有安装包提取件，并以 SHA-256 对照主线活动清单。第一份交付基于 [W2 发布包](https://github.com/DenseFLoe/Aspen-for-mac/releases/tag/v0.20261121-w2)，两个正式导出的 Git blob 已与主线原目录核对。

用 dnfile 0.18.0 读取原件方法令牌和 RVA，并按 ECMA-335 方法头逐一比较 W2 IL 指令偏移和字节。215 条 MethodDef 全部对应，其中 214 项有方法体，1 项原件无方法体。4,151 条指令、10,444 字节与原件一致。原件有 7 个方法带方法体附加区段，逐字节统计覆盖 IL 指令流。另核对 C# 文本、托管资源表和 PE 资源目录。 [核对数据](Stingray.GridUtils71.dll.静态验收.json)。

C# 第 2250–2251 行是未注释的 ILSpy 版本提示，当前源码存在语法错误。原件包含托管资源 `Stingray.Grid.GridControl.ico`，W2 交付只有 C#、IL 和历史报告，缺少该资源和 PE 版本资源的重建输入。

移除工具提示，补齐资源并核对源码覆盖后送回第四组复验。 Windows 运行对照留在重建阶段。
