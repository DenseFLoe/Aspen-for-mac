# AspenTech.AspenPlus.MMControls.dll 托管源码

第 20261119-19 轮托管代码通过静态逆向验收。此库包含 Aspen Plus 和 Aspen Properties 共用的页面、视图模型、表格、绘图控件及事件接口。Flash2 输入规格页和结果汇总页直接使用其中的 `MMTabPage` 基类。

## 原件与成果

Aspen Plus V15 和 Aspen Properties V15 两套 MSI 的 File 序号分别为 1941 和 1578，均指向各自 `APRS~454.cab` 内的 `aspentech.aspenplus.1.01AE6323_4069_4985_B882_1C2F459EE258`。两个安装包成员与共用安装件的 SHA-256 相同。本轮复用了既有成员指纹，并从 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.MMControls.dll` 读取了实际安装件。原件 1,236,520 字节，文件及程序集版本均为 41.0.0.614，SHA-256 为 `bd4b5cdf3e6c8ede0dbb54b9297581bb79fa7289fe45c71def67b5bf1107842c`。

同目录 `AspenTech.AspenPlus.MMControls.dll.cs` 为整件可编辑 C#，共 2,268,439 字节，SHA-256 为 `9ac5398174227a64663f7270b87a9b279c9d9528147af94cc32f6d32ddf398ed`。ILSpy 9.1.0.7988 读取原件和本机依赖目录，导出源码与原始定义令牌到源码行号的映射，反编译警告为零。按程序集名称、版本、文化和公钥令牌核对了 34 个直接引用。

## 方法与成员核对

原件有 544 个顶层类型、163 个嵌套类型及一个模块定义。2,207 个字段、1,601 个属性、40 个事件和 6,570 个方法定义均可按令牌定位。旧档单独导出的 12 个顶层类型已关联到本轮源码。

| 方法范围 | 验收证据 |
| --- | --- |
| 6,342 个 IL 实现 | 4,585 个方法有直接源码序列点。984 个自动属性访问器逐一核对原件字段、所属属性及实际读写指令。其余 773 个折叠实现按原方法令牌单独展开，附在 C# 文件末尾，逐一核对其可见序列点与方法体界限。 |
| 指令与异常处理 | 独立读取原始 PE，逐项核对 142,939 条指令的偏移、操作码与操作数，以及 124 个 catch、498 个 finally、21 个 fault 区间。C# 中 36 个 NotImplementedException 分支均定位到原件相应方法的构造及抛出指令。 |
| 228 个无 IL 方法 | 原件包含 202 个抽象声明、24 个 CLR 提供的委托方法和两个本机调用声明。使用 Roslyn 内存静态输出核对全部声明的签名、参数标志及实现属性，两个外部目标分别为 gdi32 的 DeleteObject 和 user32 的 GetActiveWindow。243 个显式接口映射也已核对。 |

在 `MMScrollAreaMSDataRetrieverExtensions.GetCellData`（`0x06000644`）中，原件 IL_006a 的类型测试把结果保存在局部变量 3，供后面的两个分支使用。恢复时据此扩大局部变量的 C# 作用域，另在 19 行中转义与 C# 14 上下文关键字冲突的 `field` 标识符。修正后 GetCellData 的静态输出具备与原件相同的 32 个带类型的调用、构造与类型测试操作，按目标和出现次数核对。最终 Roslyn 语法和类型错误均为零。

## 证据与下一阶段

本轮 `managed-audit.json` 汇总覆盖范围、源码指纹、引用身份及本机证据指纹。`source-repairs.json` 记录两处修正的依据。`code-coverage.json`、`il-coverage.json` 和逐指令 IL 留作方法级复查，`focused-checks.json` 记录隐式成员与原件异常分支，`contract-checks.json` 和 `interface-map.json` 记录外部、抽象、委托和接口声明的静态比对。

Windows 重建时需复验表格单元格只读与默认字体分支、Flash2 页面基类交互、资源加载和外部调用，并核对原环境的传递引用绑定。Roslyn 报告 217 个 CS1701 和 33 个 CS1702，涉及 WpfControls.Engineering 引用的 InfragisticsWPF.Editors 21.1.20211.27 与本机 21.2.20212.9，以及 CxsViewModel 引用的 AspenCxs 41.0.0.5 与本机 41.0.0.57。另有 39 个旧 API 和 8 个未使用局部变量警告。
