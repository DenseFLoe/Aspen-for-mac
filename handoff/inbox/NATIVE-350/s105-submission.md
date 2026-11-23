# NATIVE-350 s105 交付

upstream，assigned_seq=105，交付 UTC 2026-11-23T08:03:32Z，基线 `263497c50f7a59ea343f2cf80ba41a168dce7af1`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15e90,0x15eca)`，片段 SHA-256 `06e4fb35ab14c9fe4c5e1bd9b106ce05a66e5b36f27cd04c8441446ffdb831b8`。

回编 58 字节、12 条解码指令、2 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。原件经 0x1807e 和 IAT 0x190d0 调用 memset 将 0x68 字节清零，经 IAT 0x19078 调用 GetStartupInfoW，由 STARTUPINFOW.dwFlags 的低位决定返回 wShowWindow 或 SW_SHOWDEFAULT（10）。Win32 布局见 [Microsoft STARTUPINFOW](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow)。

255 个入口中 168 个覆盖、87 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。

复跑 `python -B handoff/inbox/NATIVE-350/s105/replay.py ORIGINAL ZIG`。Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26、iced-x86 1.21.0。[清单](s105/manifest.sha256) SHA-256 `37f87505c77976bd1591d7b4d19da4f3649e7a24d9ff414bd260ed91ab27dc40`。
