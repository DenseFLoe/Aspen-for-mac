# 第 20261119-16 轮 · Plus 与 Properties 共用的案例操作组件

`AspenTech.AspenCxs.dll` 通过整件静态验收。上轮基础组件调用本件读取案例文件路径、发出案例操作及读取消息。Plus 和 Properties 两个原版 MSI 的 File 序号分别为 1736 和 1373。两份既有包内成员记录与共用安装件均对应版本 41.0.0.57、大小 265,256 字节，SHA-256 为 `84fdfccb7a92901d723ef284490cfe88d64c22758aeb75b2a2f6876255b57206`。[源码、资源与说明](../../../reverse/01-completed/20261119-16/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/)

| 范围 | 核验结果 |
| --- | --- |
| 结构 | 旧档选取 8 个顶层类型，涉及 238 个方法定义。本轮覆盖 164 个顶层类型、4 个嵌套类型及模块定义，含 671 个字段、385 个属性和 9 个事件。 |
| 方法 | 1,654 个定义中有 1,480 个 IL 实现、170 个抽象声明、4 个原生导入。已逐项对照 40,791 条指令和 310 个异常处理分支。两个条件分支抛出的 NotImplementedException 均可在原件定位。 |
| 接口与下拉编辑器 | 13 个 COM 导入接口共 100 个方法及访问器，槽位顺序已核对。Units、UnitsSpec 和 DisplayValue 三处属性绑定到两个下拉编辑器，已核对列表初始化、点击处理及选中值返回。 |
| 可编辑资源 | 唯一的托管资源包含一个字符串，唯一的 Windows 资源记录版本信息。从 RESX 和 RC 重建后，340 字节与 952 字节的资源负载分别与原件逐字节一致。 |

C# 源码中已修正反编译产生的一处同名局部变量。Roslyn 检查为零错误，保留五个未使用变量警告和一条隐藏提示。Windows 重建时仍需对照案例操作、COM 调度、事件和程序集的实际版本绑定。[逐项验收证据](../../../reverse/01-completed/20261119-16/Plus-Properties/evidence/)

本机正式成果位于 `.local/reverse-round-20261119-16/01-completed/Plus-Properties/` 下的原安装路径，逐指令 IL 留在本轮本机 evidence 目录。本轮涉及 3 条不同来源，在 Plus 总表、Properties 总表、Properties 重复子表及共用表中分别更新 3、2、2、3 行。累计 21 / 1,397 个不同原件通过静态验收，对应 62 条不同来源。[归档指纹](artifacts.csv) · [来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-16/publication.csv)

## 下一轮

接续 `AspenTech.AspenCxs.CxsViewModel.dll`，SHA-256 为 `5c5f2208066ad33ff8d8da9d76c681f2a3c0c3508cdce9391f1aa585849516c0`。其 132 个方法向本轮组件发出 450 条直接调用。所引用的 AspenCxs 版本是 41.0.0.5，现装版本是 41.0.0.57，涉及的 52 个成员签名均逐项匹配。旧档仅单独恢复 CxsViewModel 的 174 个顶层类型中的 7 个。优先补齐该程序集的方法及必要资源。[调用与旧档证据](../../../reverse/01-completed/20261119-16/Plus-Properties/evidence/handoff.json) · [52 个签名对照](../../../reverse/01-completed/20261119-16/Plus-Properties/evidence/next-call-signatures.json)
