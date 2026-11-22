# NATIVE-350 第一号分配交付

owner 为 upstream，assigned_seq=1。固定原件 `zedstwu.dll` 的 SHA-256 为 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，来源提交为 `ad53650f6071f83b133ede7bf847bc5096cd3b56`。[分配卡](../../assignments/NATIVE-350.md) · [开工回执](s1-started.md)

本轮修复 0x175cf 复制三组四字节后将剩余长度传入 0x16e4a 的控制流。实际 C 编译产物覆盖 4,266 字节连续复制实现与 128 个独立导入跳板。模式和阈值、四张共 217 项的跳转表以及 800 字节的 VERSIONINFO 编辑源均与原件核对。0x15bda 的 INT3 及前一 fastfail 的处理器分支和备用返回路径已定位。[逐件说明](zedstwu.dll.md) · [代码与数据验证](rebuild.json)

静态覆盖检查为 255 个入口、3,567 条引用、125 个缺口，退出 2。原件四个业务导出及 44 处间接转移仍应继续修复和复验，整件提交上游裁定。[逐址缺口](coverage.csv) · [引用核验](references-check.json) · [交付指纹](artifacts.sha256)
