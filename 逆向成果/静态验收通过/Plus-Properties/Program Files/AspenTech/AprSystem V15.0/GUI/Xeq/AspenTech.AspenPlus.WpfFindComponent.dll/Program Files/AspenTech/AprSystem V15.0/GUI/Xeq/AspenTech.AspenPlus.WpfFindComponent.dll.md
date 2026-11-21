# AspenTech.AspenPlus.WpfFindComponent.dll.cs

第 20261119-07 轮，整件静态归档状态为**已完成**。本件由 Aspen Plus 和独立 Aspen Properties 共用。

原件安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/AspenTech.AspenPlus.WpfFindComponent.dll`，版本为 `41.0.0.614`，SHA-256 为 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5`。两套安装介质的主件均来自各自的 `APRS~479.cab`，英文资源卫星来自各自的 `APRS~409.cab`。读取两份 MSI 文件表和介质表，复核当前柜指纹，并按成员键复用了各自原包的已解包成员指纹。来源与行号见本轮 `identity.json`。

这份可编辑 C# 包含 60 个顶层类型和 28 个嵌套类型，覆盖 732 个字段、184 个属性和 10 个事件。ILSpy 9.1 导出源码。按原 MethodDef 逐一对照 889 个有 IL 方法体的定义、12 个抽象接口方法和 2 个 User32 导入。653 个实现直接对应源码序列点，8 个异步方法与各自的状态机对应，130 个自动属性访问器逐指令核对了后备字段，98 个折叠实现另有定点展开。C# 末尾的注释附录保留 22 个编译器合成类型的结构与折叠实现；主动执行的源码部分由 Roslyn 解析出 66 个显式类型，语法诊断为零。每个原始成员的令牌和源码位置见轮次根目录的 code-coverage.json。

PubChemAgent 静态构造器（0x060001f6）中，旧 C# 第 8133–8136 行留下四条类型推断诊断。对照原件中连续 61 字节的 13 条指令，已经还原创建 HTTP 客户端、设置服务基址和添加接受的媒体类型这三条语句。原程序集引用 System.Net.Http 4.2.0.0，本机反编译器静态解析到同公钥标记的 4.0.0.0。已按原始签名逐个核查涉及的 7 项外部成员引用。两个转换器在 ConvertBack 抛出 NotImplementedException 的实现也已对照原始 newobj、throw 指令，保留原行为。定点证据见 old-diagnostic.json。

下一步在 Windows 重建对照阶段复验宿主提供的数据上下文、页面交互、实际加载的程序集版本及联网查询结果。本轮验收依据为原文件静态恢复。

本份成果 SHA-256 为 `e870e4a753ff4a0be3d319c518b03484c8a28847ba0985ad42f357ac5ab9a0ad`。轮次根目录的 `signoff.json` 同时登记成果、同名说明和验收证据的指纹。
