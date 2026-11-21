# 网格表单主库

Aspen Plus V15 和独立 Aspen Properties V15 共用 `AspenTech.AspenPlus.MMForms.GridForms.dll`，版本为 41.0.0.614。两套安装包各自的 `APRS~383.cab` 成员与 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms` 的安装件均为 528,424 字节，SHA-256 为 `e404e43bee7f55f6927cfa7d411343a3e37a371a286a9d424c05f3db1f85a614`。[主库来源](../../../../../../evidence/identity.json) · [布局卫星来源](../../../../../../evidence/satellite-identity.json)

第 27 轮通过整件静态逆向验收。完整可编辑 C# 存于本机本轮 `01-completed` 的对应原路径，文件为 `AspenTech.AspenPlus.MMForms.GridForms.dll.cs`，SHA-256 为 `7914812100645a0c5c8978cc28cc5c0de1807d91d2ccfdc4355263f0ec1b806b`。原件有 173 个顶层类型、172 个嵌套类型，以及一个模块定义。ILSpy 9.1.0.7988 导出后，按原始令牌核对了 3,012 个方法体、63 个抽象声明和 9 个由运行时实现的声明。2,372 个方法体直接对应活动源码，243 个折叠方法另作展开核对，397 个自动访问器已核对。共验证 63,237 条 IL 指令、346 个异常处理区、213 个显式接口槽。[逐方法索引](../../../../../../evidence/methods.csv) · [托管核验](../../../../../../evidence/managed-audit.json)

恢复了 22 个迭代器的清理和状态转换逻辑，并核对 7 个内嵌 COM 类型。使用原版引用静态编译，Roslyn 报告 0 个错误和 26 项警告，其中 20 项涉及传递程序集的版本，宿主配置中有对应重定向。另 6 项涉及旧 API、对象哈希和未使用或默认值成员。在 Windows 宿主内仍需对照变量查询、报表复制、引擎调度、事件及界面显示。[操作入口](../../../../../../evidence/control-entrypoints.json) · [报表路径](../../../../../../evidence/report-paths.json)

同轮另归档 30 份可编辑 XAML、PE 版本资源及 14 个按原键名保存的图像。布局已核对 167 个字段、44 次事件订阅和 197 条非空路径。图像原始字节、物性预置表及相关换算源码保存在本机。发布的 C# 选取件保留其他已审查代码，各段可按原始与发布行号及指纹核对。[发布范围](../../../../../../evidence/code-extraction.json) · [布局核验](../../../../../../evidence/ui-audit.json) · [图像索引](../../../../../../evidence/resource-asset-index.csv)
