# AdsDataMap.dll 的完整 C#

Aspen Plus V15.0 与独立 Aspen Properties V15.0 共用组件。文件版本 41.0.0.2，程序集版本 41.0.0.0。
原路径为 `[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdsDataMap.dll`，原件 SHA-256 为 `76ed474639f4b3766cbff475a0ed77bd9c5987eb9db4087aa4baf7fdcefea3b6`。
本轮复用 Plus 安装包 `ADataS~6.cab` 中的 `adsdatamap.dll.212AE9E9_21E8_4096_9B20_A67D65149FB9` 提取件。Properties 安装包的同名 CAB 成员及本机共用安装件均有同指纹来源记录。

整件通过静态逆向验收。历史选取件覆盖的 Converters、ConvertersBetweenObjects 和 MapDataSet 已纳入完整源码，同时补齐参数类型、连接转换器、对象与变量映射和撤销栈。

已按令牌核对 110 个类型定义、431 个字段、1,016 个方法、360 个属性和 3 个事件。995 个有方法体的定义覆盖 19,232 条 IL 指令和 96 个异常处理区。自动访问器与事件方法中折叠的 368 个方法和 31 个折叠构造方法均与 Roslyn 内存回编的对应指令一致。编译器生成的迭代器、闭包和委托缓存由本机展开视图与完整 IL 对照。另有 17 个抽象声明和 4 个委托运行时声明。
[托管验收](../../../evidence/managed-audit.json) · [逐方法索引](../../../evidence/methods.csv)

程序集无内嵌托管资源或窗体布局。唯一的 PE 版本资源回编后与原件的 918 字节完全一致。[资源验收](../../../evidence/resources.json)

Roslyn 5.0 内存编译解析了全部七个直接引用，包括共用的 AdbComInterfaces。编译报告 10 条未使用变量或不可达代码警告。构建落地、组件绑定、XML 和压缩映射数据的读写行为留待 Windows 重建对照。本次验收使用安装包提取件及静态元数据。

本成果 SHA-256 为 `e7cae80e558b91c542643a802aca501eca196cb0a09e889ec8bc884fa3a2752e`。
