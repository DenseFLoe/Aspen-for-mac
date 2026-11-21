# AdbDataModel.dll 完整 C# 源码

Aspen Plus V15.0 与独立 Aspen Properties V15.0 共用组件。文件版本 41.0.0.2，程序集版本 41.0.0.0。
原路径为 `[CommonFiles64Folder]/AspenTech Shared/Aspen Data Share V15.0/AdbDataModel.dll`。原件 SHA-256 为 `7633ddafb2930d8af2ccd13bbe751ca40b04c37452b36fb4fe5b1c362cd8ff40`。
本轮复用 Plus 安装包 `ADataS~3.cab` 的 `adbdatamodel.dll.212AE9E9_21E8_4096_9B20_A67D65149FB9` 提取件。Properties 安装包的同名成员及本机共用安装件均有同指纹来源记录。

整件通过静态逆向验收。组件包含 Aspen Data Share 的数据记录、属性持有对象、设备汇总和实参转换器。

核对 1,170 个类型定义、9,032 个字段、2,766 个方法定义、194 个属性及 2 个事件。2,745 个方法体共 63,448 条 IL 指令和 62 个异常处理区。另有 9 个抽象方法和 12 个运行时委托方法。逐令牌核对 443 个由 C# 隐式生成的实现，包括构造器、属性访问器和事件访问器。核对 Finalize 的 MethodImpl 映射、一种顺序布局和 2,056 项互操作特性。[托管验收](../../../evidence/managed-audit.json) · [逐方法索引](../../../evidence/methods.csv)

ILSpy 9.1 的 C# 经 Roslyn 5 Release 在内存回编。129 条编译警告来自 30 处保持原样的关闭调试分支和 99 处未使用的局部变量。9 个直接引用均按原版身份解析。AdbCsLayer 间接引用的 System.IO.Compression 4.2.0.0 在本机未找到同身份文件，留待 Windows 重建核对绑定。[托管验收](../../../evidence/managed-audit.json)

五个设备汇总 lambda 的生成名称改变，回编用无参 GetValueOrDefault 取得同一零默认值。匿名对象的 Equals 增加同引用快速返回。两处原版字符串哈希分派还原为 C# switch，编译后的字符串常量集合与原版一致。原始实现留在本机 IL 中，供 Windows 对照设备成本和重量汇总、属性写入和清除、转换器及匿名对象比较。[托管验收](../../../evidence/managed-audit.json)

程序集没有 CLR 清单资源或界面布局。唯一 PE 资源为 930 字节的版本块，资源声明回编后与原件逐字节一致。[资源验收](../../../evidence/resources.json)

本成果 SHA-256 为 `3b156e342d2cadaa3bc0464642c3c2ebbc429134457eef67399996f5e75492b5`。
