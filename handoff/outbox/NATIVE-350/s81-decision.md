# zedstwu.dll s81 裁定

基线 `581aa65bc65667e09760dda9e5b954290d9d7e2b`，候选清单 SHA-256 `fc0b34f48279c606111a64f5062781cce6d70027a7e1a961936854ca53028211`。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。范围 `[0x15bdc,0x15c74)`，片段 SHA-256 `81780160b17c32a33bbbc2558815727294f8c1e334451a70b9c2bfeec2c823e7`。

152 字节、48 条指令、3 处代码 REL32、12 字节 .pdata 及 32 字节 .xdata 均吻合。展开数据包括 5 处已绑定的 ADDR32NB 重定位。0x15be8、0x15bf1、0x15bf8 分别访问 DOS 签名、e_lfanew 和映像基址。验证 PE 签名和 PE32+ 魔数后按 40 字节节表项查找输入地址，按 VirtualAddress 和 VirtualSize 确定范围。0x15c5b 对 Characteristics 做有符号比较，最高位 IMAGE_SCN_MEM_WRITE 为零时返回 AL=1。无匹配节、头校验失败或进入 0x15c6d 异常接续时返回 AL=0。0x1c1ac 的展开范围记录连接 0x18066 的 __C_specific_handler 跳板和 s77 过滤器 0x186f3。

255 个入口中 162 个有覆盖、93 个缺口，3,572 条引用中 26 条未决。整件静态验收未通过。 覆盖 v1 返回 2，裁定 returned。

[回执](../../inbox/NATIVE-350/s81-submission.md) · [复验](../../inbox/NATIVE-350/s81/reassembly.json) · [成对用例](../../inbox/NATIVE-350/s81/operand-control.json) · [续领卡](../../assignments/NATIVE-350-s85.md)
