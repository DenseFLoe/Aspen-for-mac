# 逐文件逆向当前状态

2026-11-20，第 20261119-56 轮。1,397 个不同原件中，**58 件通过静态验收**，覆盖 165 条不同来源。另有 19 件暂存、1,320 件未开始。[累计台账](../inventories/reverse/20261119-56/ledger.csv) · [历轮成果](../reverse/01-completed/README.md)

- **DatabaseConfiguration 的 Npgsql.dll 已通过静态验收。** 逐令牌核对 7,256 个方法定义，7,132 个方法体的规范化 IL 全部匹配，29 条托管字符串及 Windows 版本资源均逐字节复现。[本轮记录](../inventories/reverse/20261119-56/README.md)
- **下一件为 DatabaseSetup 的 Npgsql.dll。** 已定位独立 Aspen Properties 安装包成员，SHA-256 与本轮原件不同。[下一轮](../inventories/reverse/20261119-56/README.md#下一轮)
- **流程图宿主继续暂存。** 取得三个原版流程图程序集的类型定义或等效接口声明后恢复。[恢复条件](../inventories/reverse/20261119-13/README.md)
