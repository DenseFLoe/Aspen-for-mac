# 2026-11-28 Aspen 逐件静态验收

- [WpfPLRPlug.dll](../../../%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E9%9D%99%E6%80%81%E9%AA%8C%E6%94%B6%E9%80%9A%E8%BF%87/Plus/%5BProgramFiles64Folder%5D/AspenTech/AprSystem%20V15.0/GUI/Xeq/WpfPlotWizards/WpfPLRPlug.dll/) 从可编辑 C# 和提取的资源直接回编，核对 458 项方法定义、387 个 CIL 方法体、71 个 COM 声明、19 个异常子句及 8 个 WPF 页面。现有英语卫星程序集用于界面对照，独立编译产物未签名。
- [AdvancedFileDialogLib.dll](../../../%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E9%9D%99%E6%80%81%E9%AA%8C%E6%94%B6%E9%80%9A%E8%BF%87/Plus/%5BProgramFiles64Folder%5D/AspenTech/AprSystem%20V15.0/GUI/Xeq/AdvancedFileDialogLib.dll/) 独立 IL 装配覆盖 42 项方法定义、5 个方法体、2 条异常子句和 Win32 版本资源。总控从定版 ZIP 分别复跑了独立装配和布局回放。独立产物未签名，使用原件数据回放的产物逐字节一致。
- [Interop.SECSERVEROBJECTLib.dll](../../../%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E9%9D%99%E6%80%81%E9%AA%8C%E6%94%B6%E9%80%9A%E8%BF%87/Plus/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20CXS%20V15.0/SummaryGrid/Interop.SECSERVEROBJECTLib.dll/) 从完整 IL 与版本资源 JSON 独立回编，核对 290 个无体声明、135 条方法绑定、418 条封送记录和 Win32 版本资源。新产物保留程序集公钥，签名及布局差异已登记。
- [WpfPLData.dll](../../../%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E9%9D%99%E6%80%81%E9%AA%8C%E6%94%B6%E9%80%9A%E8%BF%87/Plus/%5BProgramFiles64Folder%5D/AspenTech/AprSystem%20V15.0/GUI/Xeq/WpfPlotWizards/WpfPLData.dll/) 从可编辑 IL 回编 145 个 CIL 方法体，校正令牌和方法头后使用原 PE 布局与 CLR 元数据生成逐字节一致的 DLL。已核对 211 项方法定义、10 项托管资源和 DataCurve 界面绑定。核验工具由源码即时构建。
- [WpfPLBatchSep.dll](../../../%E9%80%86%E5%90%91%E6%88%90%E6%9E%9C/%E9%9D%99%E6%80%81%E9%AA%8C%E6%94%B6%E9%80%9A%E8%BF%87/Plus/%5BProgramFiles64Folder%5D/AspenTech/AprSystem%20V15.0/GUI/Xeq/WpfPlotWizards/WpfPLBatchSep.dll/) 从可编辑 IL 重建主 DLL 和 en-US 卫星，核对 841 项方法定义、789 个方法体、121 个异常区及 14 个 WPF 页面。卫星嵌入原 BAML，两个回编产物的资源和指纹已在总控空目录复核。

[成果指纹](成果指纹.csv)
