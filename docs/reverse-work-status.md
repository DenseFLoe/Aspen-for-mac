# 逐文件逆向当前状态

2026-11-19，第 20261119-06 轮。当前处于原版逐文件逆向归档阶段。1,397 个不同原件中，累计 **12 件已完成**，对应 36 条去重来源。其余为 31 件未完成、15 件暂存、1,339 件未开始，处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-06/ledger.csv)

- **本轮完成 `AspenTech.AspenPlus.MMForms.APropSetup.dll`。** Plus 与独立 Properties 的原包成员和安装件内容一致。已核对全部 298 个方法实现，补齐旧档覆盖之外的表单和视图模型，解决同一静态构造器中的 135 条反编译诊断。22 页布局和 243 个控件连接均已定位。[本轮验收记录](../inventories/reverse/20261119-06/README.md)
- **本机归档**位于 `.local/reverse-round-20261119-06/`。整件 C#、22 页 XAML 布局包和各自的同名说明在 `01-completed/`。本轮的 `signoff.json` 与 `verification.json` 分别记录静态验收和四份状态视图的增量核验。报告默认页的一处标签目标沿用原值，实际焦点行为留待 Windows 对照阶段。[归档指纹](../inventories/reverse/20261119-06/artifacts.csv)
- **下轮首选 `AspenTech.AspenPlus.WpfFindComponent.dll`**，台账状态为未完成。已核对安装件 SHA-256 为 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5`。旧整件 C# 第 8133–8136 行的四条诊断均在 `PubChemAgent` 的静态构造器内。先核实两套原包成员，再对照该方法使用的 HTTP 类型及构造调用，随后核查其余方法和资源。
