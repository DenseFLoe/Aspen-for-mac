# InfragisticsWPF.Persistence.dll

Aspen Plus V15.0，文件版本和程序集版本 21.2.20212.9。本任务静态验收通过，静态缺口为空。

- 实装原件位于 `C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\InfragisticsWPF.Persistence.dll`，57,384 字节，SHA-256 `dd19c93a74c439a27e214e36e2532b63b7dc5053925b02b80065ff477f84283e`。固定主干 `adbe73b517acac25da87598cce46de033f630ccb` 仍为待静态验收。
- 制作和独立复核分别由 `/root/producer` 与 `/root/reviewer` 执行。冻结源码包 SHA-256 `daf1136f30311946f905d4932c01e66bd36358d1211066010478f7198403e41c`，18 个载荷加指纹表均已核对。构建输入来自登记的 v9 可编辑 C#、公开密钥和两项编译资源，证据解析用到登记 v9 的现有 CLR 解析器。
- 直接回编生成 47,104 字节 DLL，SHA-256 `d6f03f543ce438fb993ae9e2a3837e9a3163bed886df588cf94761252f3979c0`。232 项声明、231 个方法体、29 个异常子句和 1,086 个方法操作数一致。完整 CLR 元数据仅去除物理 RVA 与 MVID 后比较。ImplMap 和 P/Invoke 均为 0，PE 启动导入 `mscoree.dll!_CorDllMain` 一致。
- 托管字符串和 Win32 VERSIONINFO 各一项，资源身份和载荷一致。WPF 覆盖 3 个附加属性、4 个持久化事件、相应回调、访问器及持久化树。未发现本件内嵌的独立 XAML/BAML 布局。
- 独立复核报告位于任务根下 `review/REVIEW.md`，SHA-256 `05fe2f7cd120e4bd7f4aa93189944b692a19c4197b6fa4b6afb0111f4859938a`。改动 CIL、调用绑定、托管资源和 Win32 资源的四项独立控制均按预期检出差异。任务负责人另从空目录复跑，比较报告位于 `coordinator-run/out/static.json`。

按任务根 `RESULT.json` 的 `reproduce_command` 从项目根运行。直接构建需要 Windows、Python 3.12.10、Roslyn 3.4.0-beta4-19568-04、.NET Framework 4.7.2 运行时、8 项 .NET Framework 4.0 引用程序集和版本 21.2.20212.9 的 `InfragisticsWPF.dll`。构建无需 SDK 或实装原件。静态比较将只读访问实装原件。归档内的同名说明保留了制作方冻结送审时的状态。

回编件使用公开密钥并保留空强名槽。原件认证签名、Windows 宿主加载及持久化行为留待重建对照。

## 总控静态验收

本机安装范围的产品归属为 Plus / Properties。从可编辑 C# 直接回编，核对 231 个 CIL 方法体、1 项抽象声明、29 个异常子句、托管字符串和 Win32 版本资源。

总控回编产物与任务回执指纹一致。


## 公开复现入口

从源码 ZIP 内的同名说明运行构建和静态比较。文中的任务根 `RESULT.json` 及任务执行路径供本机交接使用。

[源码 ZIP](InfragisticsWPF.Persistence.dll.source.zip) · [独立复核](evidence/REVIEW.md) · [总控复跑回执](evidence/controller-receipt.json)
