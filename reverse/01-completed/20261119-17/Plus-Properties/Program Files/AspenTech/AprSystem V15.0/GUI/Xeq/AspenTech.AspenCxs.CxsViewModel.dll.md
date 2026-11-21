# AspenTech.AspenCxs.CxsViewModel.dll 的 C# 源码

第 20261119-17 轮通过整件静态逆向验收。本库为案例界面提供属性声明、值读写、变更通知、视图数据序列化及进度窗口。来源为 Aspen Plus V15 和 Aspen Properties V15 原版安装包，MSI File 序号分别为 1922、1559。共用安装路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.CxsViewModel.dll`，程序集及文件版本均为 41.0.0.0。两个包成员与安装件均为 385,576 字节，SHA-256 均为 `5c5f2208066ad33ff8d8da9d76c681f2a3c0c3508cdce9391f1aa585849516c0`。 本文件 SHA-256 为 `4677b44539b35b29d09a654eec9a0c45e83acde108e4702a257b5be9d750492b`。

ILSpy 9.1.0.7988 按程序集导出 C#。以原件元数据令牌逐项核对 174 个顶层类型、44 个嵌套类型、1 个模块、930 个字段、1,000 个属性和 27 个事件。2,439 个方法定义含 2,371 个 IL 实现和 68 个抽象声明。1,654 个实现按序列点定位，542 个自动访问器按原字段与指令核对，175 个被反编译器折叠的实现另附在源码末尾。6 个抽象访问器由 C# 事件声明表达。49,736 条原件指令、194 个 finally、49 个 catch 和 2 个 fault 区间与本机 IL 清单逐项相符。

两个弱事件退订分支比较委托时已补显式类型转换。Roslyn 对两处选择的运算符均为原 IL 调用的 Delegate.op_Equality。原件出现的 8 处 NotImplementedException 已对应源码行。46 条显式接口方法映射已与 Roslyn 内存输出的元数据对照，其中包含序列化、快速取值、弱事件和窗口控件连接。最终 C# 的语法及类型诊断为零错误，保留 11 条编译器警告。

程序集的版本差异为AspenTech.AspenCxs（声明 41.0.0.5，静态解析 41.0.0.57）。全部 352 个字符串读取方法、两个命名控件、两个窗口事件及版本资源的依据见本轮 evidence 中的 resource-getters.json、layout-checks.json 及 resources.json。同目录的资源说明给出逻辑资源名和重建步骤。code-coverage.json 按令牌给出源码位置，focused-checks.json 解释隐式成员及修正。逐指令 IL 及异常区间清单位于本机轮次 evidence。Windows 重建阶段仍需对照实际版本绑定、属性通知、取消订阅和进度窗口运行行为。
