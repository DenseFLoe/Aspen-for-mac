# AspenTech.AspenPlus.Localization.dll

## 结论

**静态验收通过。** 恢复了可编辑 C#，以及 86 个可按原名重新嵌入的托管资源和 1 个 Win32 版本资源。Windows 产品中的模块装载、COM 调用、本地化和区域性回退还需实机对照。

## 来源与成果

- 产品为 Aspen Plus V15，程序集、文件及产品版本均为 41.0.0.614。安装路径为 [ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.Localization.dll。
- 固定来源为 DenseFLoe/Aspen-for-mac 的 codex/reverse-unsuccessful-85 准备提交 9559b75390876346c69b185dbaaba18692a7af75，仓库路径为 原版文件/Plus/[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.Localization.dll。复用了 .local/aspen-plus-github-inputs-20261120-225559-578/originals 下对应的本机原件，未再次下载。该副本为 40,687,656 字节，SHA-256 为 5b8b5cfef4493ebed8f5a9ed9357613f5d45b43ebc92b66f4455870236e558f9。
- 同一准备提交中的 v0.20261121-w2 制作者报告记录了 dnfile/pefile 的 DOS 头错误。其输入为 133 字节，SHA-256 为 1c98b5d1b3b180c92372915f11c094572c6d52285924b84e8bd25edf04656dbe，与本件原件不同。以完整指纹复验后确认为 AMD64、ILOnly、.NET Framework 4.8，托管原生头大小和入口 RVA 均为零。
- 成果 AspenTech.AspenPlus.Localization.dll.cs 的 SHA-256 为 13a288ba8aaf949af4beb70f1e8aa5a841a4c4d43f434e4dcc42f6033f9cd74e。相邻证据目录中的 resources.json 与 win32-resources.json 给出每份资源的原名、大小和 SHA-256。version.res 封装原 Win32 RT_VERSION 记录，用于回编。该记录的实际字节及标识在 pe-rebuild.json 中有原件与回编件的比对。

## 恢复与复验

- 使用共享 ILSpy 9.1.0.7988（禁用更新检查）、Mono.Cecil 0.11.6、PowerShell 的 Reflection.Metadata 与 ResourceReader，以及本机 Python 和 pefile。整件 ILSpy C# 导出在长时间无产出后停止。按原始 IL 的五指令模式和实际操作数识别 148,055 个字符串 getter，保留可见性、资源键、ResourceManager、culture 字段和 GetString 调用。在隔离副本中暂移这些属性，再用 ILSpy 反编译余下结构和代码，最后合回这批 getter。原件未改动。
- 用已有 Roslyn 5.0.0 预发行构建、C# 10、Release、x64 和本机 .NET Framework 引用回编。私有依赖取原版同目录的 AspenTech.AspenCxs.CxsViewModel 41.0.0.0、Microsoft.Practices.Composite 2.0.1.0 和 Microsoft.Practices.Unity 3.5.0.0。编译所需 System.Runtime 4.0.0.0 取本机 GAC 门面程序集。证据目录内的 build.ps1 接收 Source、Original、Resources、Output，audit.ps1 接收共享 Mono.Cecil.dll、原件和回编件。
- methods.csv.gz 记录原版定义令牌、RVA 与标志。按完整方法标识比对 148,435 个方法，逐条核对 IL 指令、操作数、分支目标、局部变量与异常表，以及方法标志、参数和返回元数据。无缺失、额外或差异的方法。10 个零 RVA 条目均为原件接口声明。覆盖资源查找顺序、异常处理、Culture 回退、HMS 映射字典初始化和 Unity 注册。
- 原版与回编件均有 94 个类型、179 个字段、148,231 个属性和 0 个事件。类型比较的唯一差异是 Roslyn 给 IUnmanagedResourceServer 增加 BeforeFieldInit。两侧接口没有字段或类型初始化器，10 个声明签名与标志相同，互操作自定义属性字节一致。程序集身份、引用和程序集及模块自定义属性一致。比较细节见 rebuild-comparison.txt 和 interface.json。
- 86 个托管资源的名称、可见性及二进制内容一致，资源表计 148,062 项。保留原始 .resources 载荷以保持文本及二进制数据。目录中没有 WPF .g.resources；原程序集包含 XAML 命名空间声明和 ThemeInfo，回编保留其自定义属性。
- 回编件保留版本资源，未继承原签名。原件含 10,280 字节的 Authenticode 证书表，两件均为无强名称程序集。Windows 对照时应单独核验需要原签名的部署或信任行为。
- 资源键名扫描命中一处密码界面标签，复核为普通字符串标签。交付中未发现凭据或项目永久本地保护材料。

交接时已确认本件分析进程退出。命令执行器拒绝删除本件 work/ 中可重建的编译与缓存副本，保留给协调聊天清理。正式成果及证据均已归档。
