# 逐文件逆向当前状态

2026-11-19，第 20261119-04 轮。当前处于开发总纲第 2 步。需要逆向的 1,397 个不同原文件中，累计 10 个已通过逐文件归档验收，对应 30 条去重来源。

- **本轮新增 1 件：`AspenTech.CommonShell.Controls.Startup.dll`。** 两个原包成员与安装件字节一致。核对全部 125 个方法、两套资源、四个控件模板与四条命令路径；原版无窗口探针两次各通过 136 项断言。真实宿主操作及视觉效果未验收。[本轮验收记录](../inventories/reverse/20261119-04/README.md)
- **剩余工作：** 33 个未完成、15 个暂存、1,339 个未开始；处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-04/ledger.csv)
- **本机入口：** `.local/reverse-round-20261119-04/`。四份成果及各自说明位于 `01-completed/`；`signoff.json`、`verification.json` 分别记录验收和四份状态视图的逐行核验。[累计归档指纹](../inventories/reverse/20261119-04/artifacts.csv) · [上一轮](../inventories/reverse/20261119-03/README.md)
- **下轮首选 `AspenTech.AspenPlus.MMForms.Flowsheet.dll`。** 安装件版本清单值 `41.0.0.614`，已核实安装件 SHA-256 为 `aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac`。旧 IL 归档仅涵盖按名称去重的 42 个方法，不能按名称推断覆盖率。先核对两个安装包成员，再按全部 117 个方法定义及其令牌建立覆盖表；该项仍为未完成。
