# zedstwu.dll s89 裁定

基线 `6f39d81802e8d60331c0c6706f192ae7d45ac52a`，候选清单 `f14c09b0bf82f362dda6b03188b4a34880964ceed3936c1f11b32032fac3366f`。

zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 范围 `[0x15c98,0x15cc1)`，片段 SHA-256 `1288ab854e40c127977a18655e781a4fc0e5dc84feb93677bd678af3e1ea5938`。

回编 41 字节、14 条解码指令、3 处 REL32、12 字节 .pdata、8 字节 .xdata 均匹配。0x22cc0 为零或 DL 为零时两次调用 0x184f8，之间从 BL 恢复 CL。被调体只写 AL=1；包装函数也只声明 AL 的布尔返回。标志是可写节的零填充，0x15b1c 在 ECX 为零时置 1；可执行原始区域的 RIP 相对扫描只找到该写点及 0x15c9e 读点，计算地址和运行时写入有待相应证据。

255 个入口中 164 个覆盖、91 个缺口，3572 条引用中 26 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-350/s89-submission.md) · [回编](../../inbox/NATIVE-350/s89/reassembly.json) · [成对复跑](../../inbox/NATIVE-350/s89/operand-control.json) · [续领](../../assignments/NATIVE-350-s93.md)
