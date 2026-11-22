# ppexec.dll 第二十一号提交

NATIVE-346，assigned_seq=21，原件 ppexec.dll 41.0.0.605，SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。配套 atdms.dll 41.0 Build 609，来自同一套 APrSystem V15.0 已安装 Engine/Xeq，SHA-256 `0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7`。

实查的两条地址传递均用于读取计数，DMS_CPLNKI 另外向两个本机帮助程序传递地址作为长度输入。在原件已知的 64 项初始化路径，核清 3 个复制和 1 个填充目的区，各 512 字节。仍有 13 个未决转移，外部写入者、源记录容量及其他动态计数上界继续保留。 [原件参数及缺口](s21/contracts.md) · [逐址证据](s21/evidence.json) · [交付指纹](s21-manifest.sha256)

Python 3.12.14，Capstone 5.0.7，pefile 2024.8.26，Zig 0.13.0。固定主干 `ff585268ac8983097b8a229e3d8e49abee61d7e1` 的覆盖检查器，Git blob `e0b5e9c4617c9fdff9ba8d3179b60f7abad52979`。

```text
python -B handoff/inbox/NATIVE-346/s17/check-r8.py PPEXEC ATDMS
python -B handoff/inbox/NATIVE-346/s21/check-tinfo.py PPEXEC ATDMS
python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original PPEXEC
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror -c handoff/inbox/NATIVE-346/s21/tinfo-destinations.c -o tinfo-destinations.obj
```

两份指令复验退出 0，覆盖检查器核对 532 个覆盖行、532 个工具入口、3,332 条调用和 0 个申报入口缺口，退出 2。C 局部模型编译通过。
