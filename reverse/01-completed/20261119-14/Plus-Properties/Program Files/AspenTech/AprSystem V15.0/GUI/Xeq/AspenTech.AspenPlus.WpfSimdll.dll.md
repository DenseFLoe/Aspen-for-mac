# AspenTech.AspenPlus.WpfSimdll.dll 的 C# 源码

第 20261119-14 轮静态验收通过。Aspen Plus 和 Aspen Properties 均将此件安装在 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfSimdll.dll`。两个 MSI 的 File 序号分别为 1967 和 1604。既有柜成员提取记录与当前安装件的 SHA-256 均为 `0937ef8eb140cbc27ce4a6f06505e81e494e058d396310cd665a5155f09a1720`。文件版本为 41.0.0.614，长度为 133,672 字节。

ILSpy 9.1.0.7988 恢复了 65 个顶层类型和 9 个嵌套类型。按原件元数据核对了 505 个字段、848 个方法、226 个属性和 17 个事件。831 个有方法体的定义中，620 个有可见序列点，136 个自动属性访问器与后备字段逐指令对应，75 个折叠方法在源码末尾按令牌单列。原件还包含 16 个抽象方法和 1 个调用 sbsim.dll 的外部声明。逐项核对了 15,987 条 IL 指令与 56 个异常处理分支。

两个 ConvertBack 方法在原件使用同一方法体，均直接抛出 NotImplementedException。19 个直接程序集引用的身份均已核对。Roslyn 静态检查无语法和类型错误。24 个页面的 URI、字段、事件及绑定已对到英语卫星资源。主件唯一的 Windows 版本资源另附可编辑 RC。C# 成果 SHA-256 为 `25257129fd633c39450d72c821e5e48696b464b7da65a90a28e2a6febf54a0f0`。

本轮 evidence 目录的 code-coverage.json 按定义令牌列出源码行号，focused-checks.json 核对折叠字段、原版异常、宿主入口及外部声明，layout-links.json 和 resources.json 记录页面与版本资源。含原始指令字节的 IL 对照文本及逐方法校验在本机轮次目录的 evidence 下。Windows 重建后再核对窗口展示、报告调度与重新初始化的实际行为。外部求解器实现和卫星程序集分别按各自原件登记。
