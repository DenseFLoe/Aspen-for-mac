# ppexec.dll 第十七号提交

NATIVE-346，owner upstream，assigned_seq=17。固定原件 SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`，41.0.0.605。配套 `atdms.dll` 41.0 Build 609，SHA-256 `0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7`，取自 APrSystem V15.0 已安装 `Engine/Xeq` 原目录。该处 `ppexec.dll` 与固定原件同哈希。

从原件指令逐址确认 19 个直接调用，包括 11 个固定字节数和八个由六组生产者供给的动态调用。复用 532 个原件范围并核对 12,498 条指令。动态调用的计数以 8 字节为单位，跳过非正值，`1..12` 内联，`>=13` 走批量分派。五处表位点已记录 R8 取值条件。配套 `DMS_LENTHM` 的两个 64 位输出和 `DMS_TINFO+0x848` 的初值 64 已核。初始化产生 512 字节。实际生产者的全路径上界仍有缺口。其余注册、加载器槽和导出数据恢复条件见逐址说明。 [证据与输入指纹](s17/evidence.json) · [参数契约](s17/contracts.md) · [逐址表](s17/disposition.csv) · [交付指纹](s17-manifest.sha256)

从仓库根以 Python 3.12.14、Capstone 5.0.7 和 pefile 2024.8.26 复核，并用 Zig 0.13.0 编译局部模型。

~~~text
python -B handoff/inbox/NATIVE-346/s17/check-r8.py <固定ppexec.dll> <配套atdms.dll>
python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original <固定ppexec.dll>
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror -c handoff/inbox/NATIVE-346/s17/r8-arguments.c -o <复验目录>/r8-arguments.obj
~~~

第一条的标准输出与 `s17/evidence.json` 对照。判定器核对 532 个覆盖行、532 个工具入口、3,332 条引用和 0 个已申报入口缺口，退出 2。保留 13 处未决转移，整件继续静态修复。局部 C 源码编译通过。 [C 模型及范围](s17/r8-arguments.c.md)
