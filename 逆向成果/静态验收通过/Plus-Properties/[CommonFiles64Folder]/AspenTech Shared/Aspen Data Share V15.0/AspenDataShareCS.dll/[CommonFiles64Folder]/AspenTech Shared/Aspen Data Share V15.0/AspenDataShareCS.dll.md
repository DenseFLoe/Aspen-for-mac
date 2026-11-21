# AspenDataShareCS.dll 完整 C# 源码

Aspen Plus V15.0 与独立 Aspen Properties V15.0 共用此程序集。文件版本为 41.0.0.2，程序集版本为 41.0.0.0，目标为 .NET Framework 4.8。原路径为 `[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AspenDataShareCS.dll`。两份产品安装包的 `ASPEN_~5.cab` 都含成员 `aspendatasharecs.dll.212AE9E9_21E8_4096_9B20_A67D65149FB9`。本轮使用已有的 Plus 包提取件，大小 2,261,032 字节，SHA-256 为 `2edf2cf9ce11e6d6c6b7a6c7df2f2ba5c2018a5929076f2c8b20cbe9d912e8d5`。另有同指纹的本机共用安装记录。[三条来源记录](../../../evidence/sources.json)

整件通过静态逆向验收。C# 实现了按 Aspen Data Share 接口读写对象和属性、访问子对象、遍历记录及发送变更通知的托管代码。核对了全部 954 个类型定义（含模块占位）、8,613 个字段、7,549 个属性、1 个事件和 20,069 个方法。20,046 个方法带有 IL 方法体，共 161,619 条指令、8 个异常处理区。另外 19 个方法是抽象声明，4 个由委托运行时提供。逐方法索引给出原件定义令牌与源码行的对应关系。[托管核验](../../../evidence/managed-audit.json) · [逐方法索引](../../../evidence/methods.csv)

ILSpy 恢复的两个迭代器经现代 C# 编译器重新生成时会改变提前释放后的枚举状态。源码将它们写为显式的 `RecordEnumerator` 和 `ChildEnumerator`，保留原件的空 `Dispose()`。这两个私有类型及其编译器生成字段使用合法 C# 名称，`MoveNext` 显式实现原接口。回编同时生成了两种编译器特性，并给四个接口加上了 `BeforeFieldInit` 标记。核对中保留这些元数据差异。[托管核验](../../../evidence/managed-audit.json)

用 Roslyn 5 按 Release 配置静态回编，三个直接引用按程序集身份解析。对含字符串或目标接口调用的 16,230 个方法，按签名定位原方法与回编方法，比较各方法中字符串、调用指令及目标成员的顺序。9,281 次字符串加载和 14,375 个指向 AdbComInterfaces 的方法操作数全部一致，其中包含 8,302 个不同的 GUID 字符串。[接口调用核验](../../../evidence/selector-check.json)

唯一的 Windows 版本资源已独立回编并逐字节核对。程序集没有内嵌布局。Windows 重建阶段需用原版 COM 宿主对照对象及属性读写、记录和子对象枚举、提前释放后再次迭代的行为。[资源核验](../../../evidence/resources.json)

本成果 SHA-256 为 `1476ce05030be0c5b3fde26aeada960f3d1d18652d4e1f42c26b7af075cbf83b`。
