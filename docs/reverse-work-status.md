# 逐文件逆向当前状态

2026-11-28，本轮逐件静态验收 5 件，通过 5 件，确认未通过 0 件。主干累计通过 254 件，本机安装范围累计 240 件。[本轮归档](../reverse/01-completed/20261128-codex-five/README.md)。

2026-11-27，ApwnRes.dll 的完整 x64 汇编、PE 元数据和 232 项资源通过静态验收。主干累计 249 件通过，本机安装范围累计 235 项通过。见[本轮归档](../reverse/01-completed/20261127-apwnres-native/README.md)。

2026-11-27，Mollier-01.xls 的 BIFF8/VBA 源码通过整件静态复验。从交付包重建的工作簿与安装原件逐字节一致。主干累计 248 件通过，本机安装范围累计 234 项通过。见[本轮归档](../reverse/01-completed/20261127-mollier-biff8/README.md)。

2026-11-27，AspenTech.AspenPlus.MMForms.SummaryGrid.dll 以完整 IL 和原件资源通过方法实现、COM 声明和资源核对。主干累计 247 件通过，本机安装范围累计 233 项通过。见[本轮归档](../reverse/01-completed/20261127-summarygrid-il/README.md)。

2026-11-27，Interop.MMLocal.dll 以完整 IL 和原件资源通过 COM 声明及编组核对。主干累计 246 件通过，本机安装范围累计 232 项通过。见[本轮归档](../reverse/01-completed/20261127-mmlocal-il/README.md)。

2026-11-27 从本地回编成果新增 78 件托管静态验收归档。主干累计 245 件通过，本机安装范围视图累计 231 项通过。见[本轮归档](../reverse/01-completed/20261127-managed-source/README.md)。

2026-11-26，PfsDotNetActiveXCtrl.dll 通过逐件静态验收。复核覆盖 67 个方法定义、界面布局及两项资源，归档回放复现安装原件。主干本机逐件总表累计 153 项通过。[逐件证据与指纹](../reverse/01-completed/20261126-codex-resume-wpf/README.md)。

2026-11-26 接手续跑，AspenTech.Dashboard.Contracts.dll 和 AxASCGridLib410.dll 通过逐件静态验收。两件均从源码复编并按原件布局重放，回放 PE 与各自安装原件逐字节相同。主干本机逐件总表累计 152 项通过。[逐件结论与指纹](../reverse/01-completed/20261126-codex-resume/README.md)。

2026-11-26 新增 74 个本机 .NET 原件的逐件静态验收归档。主干本机逐件总表累计 150 项通过。见[本轮说明](../reverse/01-completed/20261126-static-source/README.md)。

**现阶段核心工作**为[批量静态验收、修复与复验](static-acceptance.md)。以 GitHub 主干的[逆向成果目录](../逆向成果/)与[逐件总表](../逆向成果/逐件总表.csv)为准。

自 2026-11-24 起，新件以本机安装的 Aspen Plus 和 Aspen Properties 为共同基准。当前分类见[本机安装统一清单](installed-baseline.md)。下方保留历史状态。

2026-11-21，主分支已统一整理逐件归档与协作者交付。按原件查看代码、报告与状态，请打开[逆向成果](../逆向成果/README.md)或[逐件总表](../逆向成果/逐件总表.csv)。下方记录本地逐轮验收的最近一轮。

2026-11-20，第 20261119-61 轮。1,397 个不同原件中，**63 件通过静态验收**，覆盖 170 条不同来源。另有 19 件暂存、1,315 件未开始。[累计台账](../inventories/reverse/20261119-61/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **DatabaseSetup 的 SetupAPEDPostgreSQLDatabases.dll 已通过静态验收。** 37 个方法体的规范化 IL、171 条语义元数据记录和两项 PE 资源均吻合。完整源码含凭据，仅本地留存。[本轮记录](../inventories/reverse/20261119-61/README.md)
- **第 61 轮原定后续项为 DatabaseSetup 的 SetupAPEDPostgreSQLDatabases.exe。** 原安装包成员及指纹已定位。[下一轮](../inventories/reverse/20261119-61/README.md#下一轮)
- **流程图宿主继续暂存。** 取得三个原版流程图程序集的类型定义或等效接口声明后恢复。[恢复条件](../inventories/reverse/20261119-13/README.md)
