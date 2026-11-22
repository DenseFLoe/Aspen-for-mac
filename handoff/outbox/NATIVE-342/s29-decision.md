# ApwnIPShell.dll s29 裁定

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。基线 `e3b3049622bbefa9241099561a8fadd35a9b25c1`，候选文件以交付清单 SHA-256 `81cc20f66fe43ca6fcbde1b5d65aee71c44c41d3e018803e771680cfd1fce660` 固定。

范围 [0x33a20,0x33a38) 回编一致，24 字节、5 条指令、2 处 REL32。核对了 APPID 与 GUID 两项只读引用、入口参数转发、虚表 +0x18 尾转移，以及 DIR64 0x429b8 的入站槽。尾转移的实际目标仍待证。

覆盖 v1 退出 2，715/1005 个入口已覆盖，290 个入口缺口、636 条未决引用。整件裁定 returned。[交付](../../inbox/NATIVE-342/s29-submission.md) · [局部复验及对照](s29-verifier-notes.md) · [续领卡](../../assignments/NATIVE-342-s33.md)
