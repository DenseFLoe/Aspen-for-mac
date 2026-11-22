# ApwnIPShell.dll s25 裁定

原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。固定候选 `be0e14614394ef9af5f59311d560578191dc2f8d`。回编核实 35 条指令、116 字节和 3 处 REL32，.pdata 12 字节和 .xdata 16 字节均吻合。空输出路径返回 0x80004003，创建调用 IAT 为 0x3ab68，第五参数指向缓存槽。0x339ff 符合 AddRef 槽位，具体实现仍待定位。

覆盖证据 v1 返回 2，1,005 个入口中有 714 个已覆盖，291 个缺口，7,433 条引用中 636 条未决。局部静态证据通过，整件裁定 returned。继续核对 0x33a20 的数据地址、ABI 跳转及指针来源。

[本轮交付](../../inbox/NATIVE-342/s25-submission.md) · [续领卡](../../assignments/NATIVE-342-s29.md)。
