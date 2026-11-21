# AspenTech.AspenPlus.Infrastructure.dll 的 C# 源码

第 20261119-15 轮整件静态验收通过。Plus 与 Properties 均安装到 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.Infrastructure.dll`。两个 MSI 的 File 序号分别为 1934 和 1571。原件 400,936 字节，版本 41.0.0.614，两个安装包成员及共用安装件的 SHA-256 均为 `052e0a0e54d287397457200d4bdb87a0051ecff751f42d941114fa5e3c02908f`。

ILSpy 9.1.0.7988 导出 C#。333 个顶层类型、17 个嵌套类型及单独的模块定义均有原件令牌记录，覆盖 613 个字段、1,407 个方法、426 个属性和 6 个事件。1,199 个带 IL 的方法中，412 个由序列点定位，584 个自动属性访问器对到实际字段与指令，203 个折叠实现附在源码末尾。另有 191 个抽象方法、14 个运行时方法和 3 个 P/Invoke。12,278 条指令及 77 个异常处理分支已核对。

按原件 COM 元数据恢复 IHNode.Name 和 IHPlotVal.YAxisTitle 的可选索引参数，保留 IHPlotVal 三组标题访问器之间的实际槽位次序。嵌入的事件接口带 Import 标志且没有 GuidAttribute，C# 中单独注明，精确保留该标志和属性元数据须在 Windows 重建时核对。Roslyn 静态检查的语法及类型错误为零。原件的六处 ConvertBack 方法直接抛出 NotImplementedException。

源码 SHA-256 为 `a10a17a82d65713eec2408a3ba39ae5dbec43b4a10723b2859ee78cbce18f7cd`。本轮 evidence 中的 code-coverage.json 按令牌给出源码及 IL 行号，focused-checks.json 说明折叠定义和 COM 差异，identity.json 及 handoff.json 对应原件归属和历史成果。逐指令 IL 与校验表在本机轮次目录的 evidence 下。

两个窗口的外置布局与本件的连接方法核对见 layout-links.json。六个嵌入动画光标及版本资源各有本机成果与说明。Windows 重建阶段需复核 COM 调度、窗口与光标交互及消息事件。
