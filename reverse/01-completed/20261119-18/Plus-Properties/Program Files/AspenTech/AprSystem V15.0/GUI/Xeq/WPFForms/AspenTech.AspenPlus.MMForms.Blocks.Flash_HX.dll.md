# AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll 的托管源码

第 20261119-18 轮托管代码静态验收通过。原件实现 Decanter、Flash2、Flash3、Heater、Heatx、HXFlux 和 MHeatx 的 WPF 表单、输入与结果视图模型。Aspen Plus V15 与 Aspen Properties V15 两套 MSI 的 File 序号分别为 1866 和 1503，均指向 APRS~379.cab 中的同一文件名成员。安装相对路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll`。两条包内记录和安装件的大小均为 807,464 字节，程序集及文件版本均为 41.0.0.614，SHA-256 为 `4c08d219e3f2495e392635e21111065f6ec9adce1a8be49d0a3dd5eb8d8ca169`。

ILSpy 9.1.0.7988 使用原件和实际产品引用目录导出整件 C#，成果 SHA-256 为 `8a632315cbdc1348c99790c18d53f1d60fb7d87bd735e27209dc7587398b9912`。原件的 374 个顶层类型、50 个嵌套类型和模块定义，以及 4,206 个字段、2,114 个属性和 3 个事件已逐令牌定位。13 个隐式字段分属自动属性、事件、枚举和闭包。C# 中第 1382 行的 NotImplementedException 可追溯到原件方法 0x06000c13。

3,386 个方法定义中，2,931 个 IL 实现依序列点定位，4 个自动访问器经原始读写指令核对。另有 225 个实例构造函数、218 个类型初始化器和 6 个事件访问器由高层 C# 语法隐含生成，对应原件方法按令牌展开在源码末尾。对这 449 个实现，Roslyn 静态输出与原件的调用目标、字段读写及字面值等有序记录逐项匹配。两个 user32.dll 外部方法 GetSystemMenu 和 EnableMenuItem 的模块、入口、签名和互操作标志均已核对。188 条显式接口映射在静态输出中均有匹配。本机 IL 清单与 3,384 个 IL 方法体的 79,669 条指令及 79 个 catch、9 个 finally 区间逐项相符。

旧档 Flash2 输入视图模型有 466 行 ILSpy 类型诊断，加热器输入视图模型有 665 行。共 1,131 行均已定位到原件偏移及恢复后的 C#。两个视图模型各涉及三个方法，即检查入口已接而出口未接的属性、UpdateComboboxes 及类型初始化器。静态核对覆盖各初始化器的构造及赋值顺序，并核对其余四个方法从入口经 CxvPropertyWatch 的构造和赋值至第一次值转换的调用、字段和字面值。最终代码的 ILSpy 警告、Roslyn 语法和类型错误均为零。18 条 CS1702 警告来自 CxsViewModel 的传递引用，所需 AspenCxs 版本为 41.0.0.5，本机静态解析到 41.0.0.57。

本轮 evidence 中的 code-coverage.json 提供原始定义令牌到 C# 与 IL 的行号，focused-checks.json 记录隐式成员及占位异常检查，folded-validation.json、interface-map.json 和 legacy-diagnostics.json 分别记录折叠方法、接口和旧诊断的核对结果。逐指令 IL 与 il-coverage.json 保存在本机。本说明的验收范围是托管代码。Windows 重建时还需对照卫星资源的装载、实际版本绑定、页面事件和交互行为。

本程序集不内嵌页面。188 个 InitializeComponent 的页面地址、1,839 个控件连接和单独 en-US 卫星库中的布局已核对，逐页记录见本轮 evidence/ui-pages.csv 和 evidence/ui-audit.json。EdrConvertRigorous 窗口的 5 个原版绑定名称已保留，运行时取值和可见性留待 Windows 对照。
