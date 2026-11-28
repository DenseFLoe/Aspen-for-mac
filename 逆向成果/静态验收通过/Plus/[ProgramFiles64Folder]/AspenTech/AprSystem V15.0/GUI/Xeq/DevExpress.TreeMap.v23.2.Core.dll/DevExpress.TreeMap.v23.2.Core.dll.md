# DevExpress.TreeMap.v23.2.Core.dll

本件通过本地静态验收，提交总控回读。固定主干 `adbe73b517acac25da87598cce46de033f630ccb` 的对象状态为「待静态验收」。[静态验收标准](https://github.com/DenseFLoe/Aspen-for-mac/blob/adbe73b517acac25da87598cce46de033f630ccb/docs/static-acceptance.md)

## 原件与交付

- Aspen Plus V15.0，文件及程序集版本均为 `23.2.4.0`。安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.TreeMap.v23.2.Core.dll`。原相对路径为 `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/DevExpress.TreeMap.v23.2.Core.dll`。
- 安装原件 41,576 B，SHA-256 `6b2379f21a1c6f408893b9a94e52ca44fa2546024fc35c6cb6e6d56a8dea46c5`。
- 冻结源码包 `DevExpress.TreeMap.v23.2.Core.dll.source-v3.zip`（44,264 B），SHA-256 `67c6146f79f59cb337076b6e54f557703249ba59363611359e8c753075672a0e`。
- 从源码直接回编的 DLL 为 31,232 B，SHA-256 `77087b847b6964e530136ca1b47090dadc7bb509f9f93790a933ba68eae08ccf`。
- 可编辑 C#、编译用 Win32 RES 和程序集公钥复用夜班 v2，v2 SHA-256 `8d7e627d358d808c6354716776dd60cbdb248ae8e0e0fa86643c57f29fa9f970`。Roslyn 直接产生候选程序集。新包仅含源码、必要资源、入口和核验证据。

## 静态实测

- 185 项 MethodDef 逐项吻合，其中 146 个含 CIL 方法体、39 个为原件抽象声明。共核对 7,908 B CIL、3,146 条指令行和 16 个异常区，覆盖分支、调用及其实际令牌绑定、局部变量签名、最大栈与初始化标志。
- 规范化 CLR 元数据一致。覆盖 45 条 TypeDef（含模块）、59 条字段、40 条属性、4 条程序集引用、0 条事件、0 条 CLR 清单资源、0 条 FieldRVA。唯一 Win32 RT_VERSION 资源 `16/1/0` 为 1,074 B，载荷 SHA-256 `54fb76efd5949b46d326811842ee1901ef7dca7f0058babb2b8c57e21fc4b079`。
- PE32/I386 入口同样经 `_CorDllMain` 跳转，重定位与入口保持同一相对位置。对照记录保留编译器产生的 MVID、时间戳、调试记录、节虚拟长度、入口和重定位地址变化。
- 制作方 `/root/producer`。独立复核员 `/root/reviewer` 先记录检查项和预期，再用同一 ZIP 从空目录构建。修改一个方法常量和修改一项版本资源两个单点对照分别触发实现和资源差异。任务负责人从同一 ZIP 另行构建并以 ILDasm 交叉核对。任务根 `RESULT.json` 指向两份证据、独立复核报告和各自指纹。

## 复现与签名

- 构建使用 Windows、Python 3.12、独立 Roslyn `3.11.0-4.21403.6 (ae1fff34)`、`.NET Framework 4.5.2` 的三份引用程序集，以及 `DevExpress.Data.v23.2.dll` 版本 `23.2.4.0`。Roslyn 本身配置使用 `.NET Framework 4.7.2` 运行时，本机实测 `4.8.04161`。构建无需 .NET SDK 或安装的 TreeMap 原件。
- 对照环节额外使用该安装原件、PowerShell 7 和 pefile `2024.8.26`。任务根 `RESULT.json` 的 `reproduce_command` 给出总控从空目录执行的完整命令，产物包括 DLL、`build.json` 和 `comparison.json`。
- 候选保留公开强名身份，128 B 强名槽全部为零，Authenticode 表长为零。原件相应签名区为 128 B 非零数据和 10,344 B 证书表。有效厂商签名及依赖该签名的装载、交互行为留待 Windows 重建对照。

## 总控静态验收

本机安装范围的产品归属为 Plus / Properties。从可编辑 C# 直接回编，核对 185 项方法定义、146 个 CIL 方法体、39 个抽象声明、16 个异常区及 Win32 版本资源。

总控回编产物与任务回执指纹一致。


## 公开复现入口

从源码 ZIP 内的同名说明运行构建和静态比较。文中的任务根 `RESULT.json` 及任务执行路径供本机交接使用。

[源码 ZIP](DevExpress.TreeMap.v23.2.Core.dll.source-v3.zip) · [独立复核](evidence/REVIEW.md) · [总控复跑回执](evidence/controller-receipt.json)
