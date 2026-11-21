# 反应表单程序集

原件为 Aspen Plus 和 Aspen Properties V15 共用的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Reactions.dll`。版本 `41.0.0.614`，大小 900,136 字节，原件 SHA-256 `c1ba8b04798c7fe48a8e8bad7b04ab893985ca22430704a19072a9f1ec458358`。两套 MSI 的 `APRS~395.cab` 均含成员 `aspentech.aspenplus.39.01AE6323_4069_4985_B882_1C2F459EE258`。使用同指纹的已安装原件。

本轮通过整件静态逆向验收。ILSpy 9.1 恢复了完整 C#。原件共有 488 个类型定义（含模块伪类型）、4,128 个字段、2,405 个属性、16 个事件及 4,166 个方法定义。逐令牌核对 108,427 条指令、60 个异常处理区及 183 个显式接口槽。其中 3,395 个方法有可见源码映射，441 个编译器生成或折叠方法有展开映射，余下 330 个构造方法通过 Roslyn 内存回编的有序指令语义对照。旧稿 10 条诊断已关联原 IL 偏移并在新稿消失。Roslyn 静态检查零错误，3 条未用局部变量警告。

主库使用 en-US 卫星回退。全部 148 个页面 URI 与原版页面配对，1,506 个控件连接和 1 次事件注册已对照。另存页面节点、本地原图及 PE 版本 RC。

[方法和对应行号](../../../../../../evidence/methods.csv) · [托管验收](../../../../../../evidence/managed-audit.json) · [卫星布局核验](../../../../../../evidence/ui-audit.json)

Windows 阶段对照页面加载、数据绑定、输入校验、事件和资源回退行为。此处的编译用于静态元数据与构造指令核对。完整源码、含公式的展示逻辑、原指令字节、原图及完整节点记录均保存在本机。

归档 SHA-256 为 `e580ce27efe8047675ee51cc02efd162f8e944c93c1fcd584c6d7f104fb33aac`。
