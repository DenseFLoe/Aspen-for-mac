# AdsAccessor.dll 完整 C# 源码

Aspen Plus V15.0 与独立 Aspen Properties V15.0 共用组件。文件版本 41.0.0.2，程序集版本 41.0.0.0。
原路径为 `[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdsAccessor.dll`。原件 SHA-256 为 `0d3d2d8cf2e86b2d2c3b65942c461c35c7c8ece41aa2978b740e2a2714fe4b8c`。
本轮复用 Plus 安装包 `ASPEN_~2.cab` 的 `adsaccessor.dll.212AE9E9_21E8_4096_9B20_A67D65149FB9` 提取件。Properties 安装包的同名成员及本机共用安装件均有同指纹来源记录。

整件通过静态逆向验收。源码包含 Aspen Data Share 的记录、通知、枚举和访问器，其中包括属性读写及共享数据树的遍历。

核对 954 个类型定义、8,613 个字段、20,069 个方法定义、7,549 个属性及 1 个事件。20,046 个 IL 方法共 161,619 条指令和 8 个异常处理区。19 个抽象方法和 4 个运行时委托方法按原件声明保留。Roslyn 5 Release 静态回编解析了全部引用，报告零诊断。逐方法核对了 995 个被 C# 折叠的实现及 14 个显式接口槽。[托管验收](../../../evidence/managed-audit.json) · [逐方法索引](../../../evidence/methods.csv)

Roslyn 5 给四个无静态构造器的接口增加了 BeforeFieldInit 标志，并生成了两个编译器特性类型。两个迭代器的 MoveNext 有指令排列差异，且它们原来的 Dispose 为空，回编后会重置状态。原版状态机和验证过的 IL 可供 Windows 重建时保留并复验原行为。[托管验收](../../../evidence/managed-audit.json)

程序集没有 CLR 清单资源或布局。唯一 PE 资源为 918 字节的版本块，版本资源声明回编后与原件逐字节一致。COM 激活、共享记录的读写、通知和迭代器的运行行为留到 Windows 对照阶段。[资源验收](../../../evidence/resources.json)

本成果 SHA-256 为 `fdbfff321636b7f9ce246b563cfe251d062dc2ba6bed8d271bc11ad35e1d5f51`。
