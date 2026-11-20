# AspenTech.AspenPlus.MMForms.Setup.dll

此文件为模拟设置表单主库的完整可编辑 C#，已通过原版逐文件静态验收。Aspen Plus V15 和 Aspen Properties V15 共用 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Setup.dll`，文件及程序集版本均为 41.0.0.614。两套 MSI 在各自的 `APRS~398.cab` 中安装此成员，File 序号分别为 1885、1522。两份既有成员指纹与本机安装件一致，原件 376,872 字节，SHA-256 为 `247fbcc9e14b3021b744cfcdfd19c333b12cb5f7501e14036b868d7684887f40`。C# 成果 SHA-256 为 `18012cdc5e40c34f2e78d726ccd355dd84442421556630f0a09cd0d3925ce5d5`。[主库身份](../../../../../../evidence/identity.json) · [签名](../../../../../../evidence/signing.json)

## 托管代码

已按定义令牌核对 1,595 个方法体和 2 项无方法体的 COM 声明，覆盖 37,776 条 IL 指令。四个列表迭代器保留原状态转换及异常清理。Roslyn 静态编译为 0 个错误、7 个警告。 使用 ILSpy 9.1.0.7988 整库恢复，核对 158 个顶层类型、29 个嵌套类型、1,870 个字段、828 个属性及 8 个事件。其中 1,377 个方法有直接源码映射，6 个自动访问器逐项匹配后备字段，212 个折叠成员均有对应实现。104 个显式接口映射及 85 个异常处理区均已核对。两个 `ConvertBack` 方法由原件主动抛出 `NotImplementedException`。[托管验收](../../../../../../evidence/managed-audit.json)

四个选择列表迭代器恢复为显式 C#，核对了其 36 个方法及 `MoveNext` 的异常清理路径。优先级对话框初始化的三个列宽整数转为双精度后可精确表示，比较指令时按这项编译器差异核对。另有两组由静态数据区初始化的控件参数，已按原始字节与 C# 数组元素核对。旧稿在 5 份逐类型导出中留有 667 条诊断。已逐条对应至 13 个原始方法内的指令偏移和恢复源码位置。 [折叠成员](../../../../../../evidence/folded-members.json) · [旧稿诊断](../../../../../../evidence/legacy-diagnostics.json)

## 表单与资源

主库声明 76 页，布局位于 en-US 卫星程序集。可编辑 XAML 保存在本目录的 `en-US/AspenTech.AspenPlus.MMForms.Setup.resources.dll/` 下，逐份说明列出原 BAML 与恢复 XAML 的指纹。已核对 2,429 个对象、878 处字段连接、4 处连接器事件和 2 处构造函数事件。四个图标的键和指纹见布局证据。主库只嵌入版本资源，已从可编辑 RC 回编并逐字节核对。关联范围限于主库实际使用的布局、资源及接口。[页面清单](../../../../../../evidence/ui-pages.csv) · [布局证据](../../../../../../evidence/ui-audit.json) · [本地化](../../../../../../evidence/localization.json) · [版本说明](AspenTech.AspenPlus.MMForms.Setup.dll.version.md)

在 `Flowsheet` 模式下更改全局流量基准时，原方法检查并按需启用对应的物流报告选项。闪蒸方法选择及温压上下限可从视图模型追到原始数据路径。[三页令牌与指令偏移](../../../../../../evidence/setup-options.json)

## 重建与复验

构建此 C# 时，对原安装的 `Interop.Happ.dll` 设置 `EmbedInteropTypes=true`（编译器参数 `/link`）。该设置可重现 `IHNode.Export` 之前的 51 个 COM 槽位、方法属性及 BStr 参数。另需引用 `AspenTech.Visualisation.CommonShell.Infrastructure.Wpf.dll`。Roslyn 的 7 项警告包括 5 项宿主版本绑定提示、1 项旧 API、1 项未使用字段。实际程序集装载及 COM 调用留待 Windows 重建阶段。[编译引用与接口元数据](../../../../../../evidence/managed-audit.json)

原布局有 2 个未匹配的标签目标和 4 条未在相应视图模型继承链找到同名属性的路径，已保留原写法。Windows 阶段对照这些数据上下文、页面呈现和实际交互。本机逐令牌记录位于 `.local/work-20261119-23-code/code-coverage.json`，原始指令清单位于同目录的 `AspenTech.AspenPlus.MMForms.Setup.dll.instructions.il`。签核见 `.local/reverse-round-20261119-23/signoff.json`。[布局验收](../../../../../../evidence/ui-audit.json)
