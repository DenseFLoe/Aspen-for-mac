# ACMDotNetWrapper.dll

静态验收整件通过，交总控复跑和登记。主干固定提交 `adbe73b517acac25da87598cce46de033f630ccb` 中原对象状态为待静态验收。

| 项目 | 实测 |
| --- | --- |
| 产品与版本 | Aspen Plus V15.0，文件及程序集 `41.0.0.613` |
| 安装原件 | `C:/Program Files/AspenTech/AMSystem V15.0/Bin/ACMDotNetWrapper.dll` |
| 原相对路径 | `[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/ACMDotNetWrapper.dll` |
| 原件 SHA-256 | `8fa9d484b3d3b34afbd4406596cba850ad8ebaf8a992f89e740be84f2fa1a3b7` |
| 源码包 SHA-256 | `97651dff1381e167880503269c82be59ef331ba35ecfb6302a7ce0110d9bcbce` |
| 独立复核报告 SHA-256 | `9f833f3e8dd8f8d4cfb77ca39b2698e6e4a645cbfddcc3b9f94cd348e3573faf` |
| 任务负责人空目录产物 SHA-256 | `c5f49a4e5bfdfe7e47f3a4a6b45b350f1be3daf978b6de7e570c8bd99000c363` |
| 独立复核空目录产物 SHA-256 | `0cf926f634bb4eb60599d926aa500d2dffa421e9478330dceba6246f0a8f9420` |

从历史 v6 复用可编辑 IL 和两份必要资源，恢复程序集 `DebuggableAttribute` 及构造器 `InitLocals`。使用 Windows .NET Framework 4.8 x64 ILAsm 4.8.4161.0 直接汇编，并通过 `/NOCORSTUB` 生成与原件相符的无引导桩结构。每次构建均独立生成元数据和 PE，布局、原始方法体与签名的回放量为零。冻结 ZIP 的 12 个成员仅含源码、资源、入口、测量及比较代码。

独立复核使用 Microsoft ILDasm 及 PE/CLI 字节扫描，对照实装原件和从空目录回编的候选。31 个方法定义、30 个方法体、768 条 CIL 指令、121 处调用或委托绑定、3 个异常区、35 项结构记录及一项托管资源和一项 Win32 版本资源均吻合。唯一无体声明为外部 `user32.dll!GetParent`。原件可执行节全部由 CLR 结构、方法体和零填充解释，本件需恢复的原生实现为零。WinForms 控件初始化、事件绑定、VB 后期绑定和宿主 COM 边界均有逐件证据。

v1 比较器会漏报可执行节间隙中的非零字节。v2 修正后，独立复核分别改变一个调用目标、一个捕获类型、一个托管资源字节和一个可执行节间隙字节。四项单变量对照均由包内比较器和独立比较拒绝。源 IL、资源及构建入口在两版间逐字节一致。

构建从空目录解包后运行 `.\build.ps1 -OutputDirectory .\rebuilt`，输出 `rebuilt/ACMDotNetWrapper.dll`。构建只读包内 IL、`ACMDotNetWrapper.Wrapper.resources`、`original.res` 和系统 ILAsm，无需原件或 .NET SDK。比较入口 `compare.ps1` 需要实装原件、.NET SDK 9.0.321、Cecil 0.11.6.0、Python 3.12.10 和 pefile 2024.8.26，输出 `report/managed.json` 与 `report/pe.json`。可直接使用任务根 `RESULT.json` 中的完整命令。任务根 `review/PLAN.md`、`review/REVIEW.json`、`review/v2/commands.json` 和 `inspection/LEAD-RERUN.json` 保存预期、实测、命令与指纹。制作员 `/root/producer`，独立复核员 `/root/reviewer`。

静态完整性缺口为零。直接汇编产物未签名，MVID 和 COFF 时间戳会随构建变化。原厂签名信任以及 Windows 实机上的 WinForms、ActiveX/COM 加载和交互留待重建对照阶段。

## 总控静态验收

本机安装范围的产品归属为 Plus。从可编辑 IL 直接重建 x64 DLL，核对 31 项定义、30 个 CIL 方法体、768 条 CIL 指令、3 个异常区及两类资源。三次独立回编之间的字节差异仅出现在 COFF 时间戳和 MVID。

ILAsm 独立构建的 COFF 时间戳与 MVID 可变。总控产物与负责人、复核员两份产物均只在这两个字段不同。


## 公开复现入口

从源码 ZIP 内的同名说明运行构建和静态比较。文中的任务根 `RESULT.json` 及任务执行路径供本机交接使用。

[源码 ZIP](ACMDotNetWrapper.dll.source.v2.zip) · [独立复核](evidence/REVIEW.json) · [总控复跑回执](evidence/controller-receipt.json)
