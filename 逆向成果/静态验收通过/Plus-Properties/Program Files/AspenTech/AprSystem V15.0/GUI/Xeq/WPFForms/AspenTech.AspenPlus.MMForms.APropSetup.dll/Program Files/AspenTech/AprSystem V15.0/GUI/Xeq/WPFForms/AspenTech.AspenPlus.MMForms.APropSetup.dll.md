# AspenTech.AspenPlus.MMForms.APropSetup.dll.cs

第 20261119-06 轮，原版逐文件逆向归档已完成。Aspen Plus 与独立 Aspen Properties 共用本件。

原安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.APropSetup.dll`，版本 `41.0.0.614`，原件 SHA-256 为 `6287a414f51e5c0288a096e4614fa892cc76b030fe536b4f43a6ca7331c231e0`。两产品各自 MSI 的 APRS~369.cab 成员与安装件逐字节一致。两个原包的英文卫星均在各自的 APRS~341.cab。轮次根目录 identity.json 记录 MSI、CAB、成员、序号和指纹。

这份可编辑 C# 覆盖 22 个表单、22 个视图模型和 1 个 WPF 生成的辅助类。用 ILSpy 9.1.0.7988 读取完整程序集，解析原安装目录及 .NET Framework 4.8 的 WPF 引用。核对 45 个类型、440 个字段、174 个属性和 298 个有 IL 实现的方法。253 个方法的非隐藏序列点对应源码；23 个隐式公共无参构造器的指令只调用各自基类的无参构造；22 个静态构造器可按原存储顺序定位到字段初始化式。轮次根目录 code-coverage.json 给出每个方法令牌、RVA、实现长度、源码行与映射方式。Roslyn 5 解析出 45 个类型、0 条语法诊断。

历史 .01.cs 的第 28–162 行共有 135 条 ILSpy 提示，指向 MMAPr_Setup_Setup_Global_ViewModel 的静态构造器 0x0600005c。old-diagnostic.json 列出 123 个不同指令偏移的归属统计和四份初始化表达式的指纹。定点读取该方法的 302 条指令，对照恢复源码第 995–1169 行，四个注册调用的类型、取值、属性赋值和集合项顺序一致。其余构造器按常规成员结构核对。

本份成果 SHA-256 为 `2283db3c96eb2cc15dbc15bb78c0024aa8461801c9e48b8aabd6d9ffed2c4213`。本轮 signoff.json 关联正式成果、说明和验收证据。当前判定限于静态恢复；实际界面、模型写回和运行行为留待 Windows 重建对照阶段。
