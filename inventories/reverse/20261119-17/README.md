# 第 20261119-17 轮 · 案例视图模型与进度窗口

`AspenTech.AspenCxs.CxsViewModel.dll` 通过整件静态逆向验收。它为 Aspen Plus 和 Aspen Properties 的案例界面提供属性读写、变更通知、视图数据序列化和进度显示。两套原版 MSI 的 File 序号分别为 1922、1559。两条包内成员记录与共用安装件均为版本 41.0.0.0、大小 385,576 字节，SHA-256 为 `5c5f2208066ad33ff8d8da9d76c681f2a3c0c3508cdce9391f1aa585849516c0`。[源码、资源及说明](../../../reverse/01-completed/20261119-17/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/)

| 范围 | 静态验收结果 |
| --- | --- |
| 结构与方法 | 旧档选取 7 个顶层类型，涉及 354 个直接方法定义。本轮覆盖 174 个顶层类型、44 个嵌套类型及模块定义。2,439 个方法定义中有 2,371 个 IL 实现及 68 个抽象声明。49,736 条原件指令及 245 个异常处理区间已逐项对照。 |
| 接口与事件 | 46 条显式接口映射均能在恢复的 C# 所生成的元数据中找到。两处弱事件退订的委托比较已按原件修正。8 处抛出 NotImplementedException 的代码均能定位到原件。Roslyn 静态诊断为零错误，保留 11 条警告。 |
| 进度窗口 | 从唯一的 BAML 页面恢复了 10 个对象。进度条与剩余时间文字分别对应连接编号 1 和 2。窗口构造函数订阅 Closed 和 Closing，XAML 的同名说明列出对应处理方法及重建时的页面逻辑路径。 |
| 字符串与版本 | 两份 RESX 覆盖 350 和 2 个字符串，352 个取值方法、资源键及文化字段均已关联。两份托管字符串资源与一份 Windows 版本资源重建后，分别与原件的 25,907、328 和 1,066 字节负载逐字节一致。 |

原件引用的 AspenCxs 版本是 41.0.0.5，本机解析到 41.0.0.57。Windows 重建阶段仍需核对实际版本绑定、属性通知、退订和窗口交互。[本轮验收证据](../../../reverse/01-completed/20261119-17/Plus-Properties/evidence/) · [上轮已核对的 52 个直接调用签名](../../../reverse/01-completed/20261119-16/Plus-Properties/evidence/next-call-signatures.json)

本机归档位于 `.local/reverse-round-20261119-17/01-completed/Plus-Properties/` 下的原安装路径，逐指令 IL 与每个方法的指令及异常区间指纹留在本轮本机 evidence 目录。5 份可编辑成果各配同名说明。本轮更新 3 条不同来源，分别在 Plus 总表、Properties 总表、Properties 重复子表及共用表中涉及 3、2、2、3 行。累计 22 / 1,397 个不同原件通过静态验收，对应 65 条不同来源。[归档指纹](artifacts.csv) · [来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-17/publication.csv)

## 下一轮

接续 `AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll`，SHA-256 为 `4c08d219e3f2495e392635e21111065f6ec9adce1a8be49d0a3dd5eb8d8ca169`。它的 2,395 个方法向本轮组件发出 17,421 条直接调用，涉及的 162 个成员签名均匹配。Flash2 的输入规格与结果汇总页都调用本件的 CxvViewModel.GetValue。旧档单独恢复了 374 个顶层类型中的 3 个。下轮从该程序集的 3,386 个方法定义和界面资源开始，逐项核对静态覆盖。[调用范围和旧档](../../../reverse/01-completed/20261119-17/Plus-Properties/evidence/handoff.json) · [162 个签名对照](../../../reverse/01-completed/20261119-17/Plus-Properties/evidence/next-call-signatures.json)
