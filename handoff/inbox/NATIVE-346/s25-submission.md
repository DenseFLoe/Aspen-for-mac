# ppexec.dll 第二十五号提交

NATIVE-346，assigned_seq=25。原件 ppexec.dll 41.0.0.605，SHA-256 `d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a`。配套 atdms.dll 41.0 Build 609，SHA-256 `0c61338f85a6131106008e3ab802a1bdd2157b0ad49c1046f0c3e224daabcdd7`。

固定两个查找键的来路、三个 64 位 PLEX 字段、循环与批量复制的地址关系。配套库中定位两类通用描述符写入、ATLOOK 描述符计数和 PCS 外部查找条件。三处具体源记录容量及生产者仍待证，主表 13 个未决继续记录。 [参数契约](s25/contracts.md) · [指令证据](s25/evidence.json) · [本轮指纹](s25-manifest.sha256)

```text
python -B handoff/inbox/NATIVE-346/s21/check-tinfo.py PPEXEC ATDMS
python -B handoff/inbox/NATIVE-346/s25/check-plex.py PPEXEC ATDMS
python -B handoff/assignments/check-native-coverage.py NATIVE-346 --original PPEXEC
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror -c handoff/inbox/NATIVE-346/s25/plex-copy-record.c -o plex-copy-record.obj
```

Python 3.12.14、Capstone 5.0.7、pefile 2024.8.26、Zig 0.13.0。两份原件对照及 C 模型编译退出 0。主干 `c260f73c2d5043aaa8731e688b0662d4f6ab3bd0` 的覆盖检查器 `e0b5e9c4617c9fdff9ba8d3179b60f7abad52979` 退出 2，532 个覆盖行、532 个工具入口、3,332 条调用、0 个申报入口缺口。
