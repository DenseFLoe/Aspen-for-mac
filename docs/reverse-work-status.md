# 逐文件逆向当前状态

2026-11-19，第 20261119-05 轮。当前处于开发总纲第 2 步。需要逆向的 1,397 个不同原文件中，累计 11 个已通过逐文件归档验收，对应 33 条去重来源。

- **本轮新增 1 件：`AspenTech.AspenPlus.MMForms.Flowsheet.dll`。** 两个原包成员与安装件逐字节一致；117 个方法定义含 115 个 IL 实现、2 个外部 COM 声明。核对三页布局的 445 条 BAML 记录、11 处接线和 8 个绑定；原版无窗口探针两次各通过 111 项断言。资源卫星不另计完成；真实宿主操作未验收。[本轮验收记录](../inventories/reverse/20261119-05/README.md)
- **剩余工作：** 32 个未完成、15 个暂存、1,339 个未开始；处理中和待复核均为 0。[累计台账](../inventories/reverse/20261119-05/ledger.csv)
- **本机入口：** `.local/reverse-round-20261119-05/`。四份成果及各自说明位于 `01-completed/`；`signoff.json`、`verification.json` 分别记录验收和四份状态视图的逐行核验。[累计归档指纹](../inventories/reverse/20261119-05/artifacts.csv) · [上一轮](../inventories/reverse/20261119-04/README.md)
- **下轮首选 `AspenTech.AspenPlus.MMForms.APropSetup.dll`（仍未完成）。** 同为 Plus/Properties 共用的表单，已核实安装件 SHA-256 为 `6287a414f51e5c0288a096e4614fa892cc76b030fe536b4f43a6ca7331c231e0`，共 298 个方法定义。旧档只单独选取 45 个顶层类型中的 2 个，且有 1 份含 ILSpy 诊断。先核对两套安装包，再按令牌定位该诊断并核查完整代码和页面依赖。
