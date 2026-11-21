# WpfPLAnalysis.dll 第 2 轮静态验收

验收日期为 2026-11-21，结论为**未通过**，复验组为 4。

原件为 `Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/WpfPlotWizards/WpfPLAnalysis.dll`，文件版本 `41.0.0.614`，SHA-256 为 `02d2245cc40aa4a028d16cc1d3aac6954e7738f9636d32ab49b3af477cca4f81`。使用本机已有安装包提取件，并以 SHA-256 对照主线活动清单。第一份交付基于 [W2 发布包](https://github.com/DenseFLoe/Aspen-for-mac/releases/tag/v0.20261121-w2)，两个正式导出的 Git blob 已与主线原目录核对。

用 dnfile 0.18.0 读取原件方法令牌和 RVA，并按 ECMA-335 方法头逐一比较 W2 IL 指令偏移和字节。553 条 MethodDef 全部对应，其中 459 项有方法体，94 项原件无方法体。23,705 条指令、72,372 字节与原件一致。原件有 7 个方法带方法体附加区段，逐字节统计覆盖 IL 指令流。另核对 C# 文本、托管资源表和 PE 资源目录。 [核对数据](WpfPLAnalysis.dll.静态验收.json)。

C# 第 7984–7985 行是未注释的 ILSpy 版本提示，当前源码存在语法错误。另有 16 处 `Unknown result type` 注释。原件有 21 项托管资源（20 个 ICO 和 `WpfPLAnalysis.Text.Analysispwr.txt`），其中 `Analysispwr.txt` 在交付 C# 第 2643 行读取。W2 交付只有 C#、IL 和历史报告，缺少上述资源的可重建输入。C# 还引用 11 个 XAML URI，需查清这些布局的来源和重建方式。

移除工具提示，核对涉及未知类型的方法与原 IL，补齐托管资源并查明 XAML 依赖后送回第四组复验。 Windows 运行对照留在重建阶段。
