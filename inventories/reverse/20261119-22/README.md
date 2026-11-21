# 第 20261119-22 轮 · 结果汇总表单

`AspenTech.AspenPlus.MMForms.Results_Summary.dll` 已通过整件静态验收。物料流汇总页的格式选择、物流表、复制按钮和表格控件均已定位。热流汇总页的显示选项和两个结果区也已与原版字段对应。[完整 C#](../../../reverse/01-completed/20261119-22/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Results_Summary.dll.cs) · [逐件说明](../../../reverse/01-completed/20261119-22/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Results_Summary.dll.md) · [页面清单](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/ui-pages.csv)

| 范围 | 静态核对结果 |
| --- | --- |
| 来源 | 两套原版安装包的既有成员指纹与安装件一致，版本 41.0.0.614。主库与 en-US 卫星程序集的 Authenticode 签名均通过本机验证。[主库身份](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/identity.json) · [卫星身份](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/satellite-identity.json) · [签名](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/signing.json) |
| 托管代码 | 1,732 个方法体、2 个抽象声明和 32,790 条 IL 指令。174 个折叠方法的调用、字段及字面量序列与静态生成结果一致，38 个显式接口映射已核对。[托管验收](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/managed-audit.json) · [折叠成员](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/folded-members.json) |
| 旧稿诊断 | 运行状态汇总视图模型的静态初始化中，185 条旧诊断全部定位到原指令及恢复代码。[逐条映射](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/legacy-diagnostics.json) |
| 页面和本地化 | 38 个页面与加载地址逐一匹配，220 个控件连接可回查字段，物料流汇总页的 2 个复制事件在构造函数中挂接。已定位代码和布局引用的 3 张资源表。[布局核对](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/ui-audit.json) · [资源引用](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/localization.json) |
| 版本资源 | 主库唯一的 PE 资源为版本信息。可编辑 RC 回编的 1,166 字节与原件一致。[资源证据](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/resources.json) |

Roslyn 静态检查无错误。两款宿主的配置解释了 12 条 CS1702 版本提示，另有 2 条未使用局部变量警告。动态列、复制行为及实际装载留待 Windows 重建对照。分析工具的 22 项现有测试及 UI 资源目录校验均通过。[程序集绑定证据](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/managed-audit.json)

本轮新增 1 件通过验收的原件，涉及 3 条不同来源。Plus、Properties、Properties 重复子清单和共用索引分别更新 3、2、2、3 行。累计 27 / 1,397 件静态验收完成，覆盖 80 条来源。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [本轮来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-22/publication.csv)

## 下一轮

接续 `AspenTech.AspenPlus.MMForms.Setup.dll`。从全局设置、物流报告及闪蒸选项三页进入，沿其原始令牌核对全部 1,597 个方法定义。[下一件指纹和页面令牌](../../../reverse/01-completed/20261119-22/Plus-Properties/evidence/next.json)
