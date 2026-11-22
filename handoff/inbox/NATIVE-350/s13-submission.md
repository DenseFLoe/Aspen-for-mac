# zedstwu.dll 第十三号提交

NATIVE-350，assigned_seq=13，owner upstream。固定原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。[原件来源和本件说明](zedstwu.dll.md) · [本轮文件指纹](s13-manifest.sha256)

原版 DSWU_UDL01I 经 0x7a9a 调用 0x9c40。该宿主在 0xb922 和 0x9e67 处分别调用 0x1000、0xb980。两个异常目录范围用 Capstone 与 iced-x86 核对原件指令边界和 RIP 相对引用，再从可编辑内联汇编用 Zig 0.13.0 重组。共 5,217 字节、891 条指令、364 处 COFF 重定位，全部与原件一致。逐址核对 31 处导入调用和 332 处数据引用。

运行 `python -B s13/check-callees.py <zedstwu.dll> <zig>` 可重放函数对照。仓库根的 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <zedstwu.dll>` 退出 2。全件 255 个入口中有 138 个已核、117 个缺口，44 处间接转移未决。相邻的 0xcc00 与 0xccd0 及其注册和数据契约仍需核对。
