# Microsoft.Practices.ServiceLocation.dll

**本件通过本地静态验收。** 正式核验入口为 C# 5、Windows x64 原生 csc 4.8.4161.0 与 `.NETPortable v4.0 Profile136` 参考程序集。归档是制作员 `/root/producer` 和独立复核员 `/root/reviewer` 核验的同一份源码 ZIP。

## 原件与交付

- Aspen Plus V15.0，文件和程序集版本均为 1.2.0.0。任务使用主干对象对应的 PSV Legacy Recall Server 安装副本，路径为 `[CommonFiles64Folder]/AspenTech Shared/PSV Legacy Recall Server/V15.0/Microsoft.Practices.ServiceLocation.dll`。原件为 18,120 字节，SHA-256 `78ac70411c71b7a0c68fe8746edd3f3a8cd3f72044b329a40ab53c57891be37d`，GUI/Xeq 安装副本同指纹。
- 源码归档为 `Microsoft.Practices.ServiceLocation.dll.20261128-b01.source.zip`，32,022 字节，10 项成员，SHA-256 `6b81cf93e25c7cbdd5e7ab221320359a9b35ca73df251f1176a9c65da35949ea`。包内有整份可编辑 C#、必要资源、两条构建入口和逐项静态证据。源码恢复了空的 AssemblyCulture 声明，保留原件的中性程序集文化及相关元数据引用。
- 基线为 GitHub `main` 的固定提交 `adbe73b517acac25da87598cce46de033f630ccb`。主干对象、总表及规则的 Git 指纹见本任务根 `BASELINE.json`。[固定主干验收标准](https://github.com/DenseFLoe/Aspen-for-mac/blob/adbe73b517acac25da87598cce46de033f630ccb/docs/static-acceptance.md)

## 静态验收

- 独立复核和任务负责人分别从空目录解包、编译并与安装原件比较。核对 44 项 MethodDef，其中 32 个有 CIL 方法体、8 项抽象声明、4 项委托运行时声明。764 字节 CIL 共 286 条指令，涵盖 57 条 `call`、`callvirt` 或 `newobj` 及 4 个异常区。独立复核比对了 20 张非空 CLI 元数据表、两条 Profile136 可重定向引用及程序集公钥。
- 591 字节托管资源目录和 1,224 字节 Win32 资源目录逐字节吻合。Win32 唯一资源为 `RT_VERSION/1/0`，载荷为 1,136 字节。PE 的 CLR 启动跳转指向 `mscoree.dll!_CorDllMain`。
- 桌面 .NET Framework 4.0 对照也从同一 C# 直接编译。44 项方法吻合，比较器正确报告 `mscorlib` 和 `System` 两条绑定的版本、公钥令牌和可重定向标志差异。独立复核分别改变调用、托管资源、Win32 资源和单条引用标志，四项对照均检出预期差异。
- 任务负责人空目录得到的 Profile136 DLL 为 11,264 字节，SHA-256 `cbf7e3e7c7d35be02265825360961fee5ba82e411d347ce336c35d03feb48bc5`。编译产物的 COFF 时间戳和 MVID 随构建变化，将这两处归零后，各次 Profile136 产物 SHA-256 均为 `18f1110b23879b935639a46f8842dd32f2e17c4c9c38670f1046e16f299fbee2`。

## 复现和后续

- 任务根 `RESULT.json` 给出可直接执行的 PowerShell 命令、工具和输入路径。编译使用包内源码、资源、原生 csc 和两项目标参考程序集。安装原件与 ILDASM 用于静态比较。独立计划、原始命令和结果在 `review/`，任务负责人复跑记录在 `controller/replay/`。
- 当前静态范围已闭合。C# 直接回编采用原程序集公开密钥延迟签名。原件的强名签名、Authenticode 和 CodeView 与回编布局的差异已留证，签名信任、宿主加载和 Windows 行为留待重建对照阶段验证。

## 总控静态验收

本机安装范围的产品归属为 Plus / Properties。从可编辑 C# 使用 Profile136 参考程序集直接回编。32 个 CIL 方法体、12 个无体声明、程序集绑定及两类资源与原件吻合。

三次独立回编的差异限于 COFF 时间戳和 MVID。这两个字段归一化后的产物指纹一致。桌面 .NET 4.0 对照检出程序集引用差异。


## 公开复现入口

从源码 ZIP 内的同名说明运行构建和静态比较。文中的任务根 `RESULT.json` 及任务执行路径供本机交接使用。

[源码 ZIP](Microsoft.Practices.ServiceLocation.dll.20261128-b01.source.zip) · [独立复核](evidence/REVIEW.md) · [总控复跑回执](evidence/controller-receipt.json)
