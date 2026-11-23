# ApwnIPShell.dll s89 调度目标静态溯源

原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。解析原件连续范围 `[0x363e8,0x36486)`，片段 SHA-256 `6be749bf85b5c92db686660f2da8b2161ad70dc1dc2321ea35740d61b1b0dbd0`。用 Capstone 5.0.6 AMD64 解码下列指令，以指令末地址加位移求目标 RVA。用 pefile 2024.8.26 检查导入槽与字符串原字节。

| 原件指令 | 指令字节 | 目标 RVA | 证据 |
| --- | --- | --- | --- |
| `0x36408` | `488d0dd9c70000` | `0x42be8` | KERNEL32.DLL（UTF-16LE） |
| `0x3640f` | `ff15ab3e0000` | `0x3a2c0` | KERNEL32.dll!GetModuleHandleW |
| `0x36422` | `488d15dfc70000` | `0x42c08` | AcquireSRWLockExclusive（ASCII） |
| `0x3642c` | `ff15ce3e0000` | `0x3a300` | KERNEL32.dll!GetProcAddress |
| `0x36437` | `488d15e2c70000` | `0x42c20` | ReleaseSRWLockExclusive（ASCII） |
| `0x3643e` | `488905fbe30100` | `0x54840` | 保存获取锁的函数指针 |
| `0x36448` | `ff15b23e0000` | `0x3a300` | KERNEL32.dll!GetProcAddress |
| `0x36453` | `488905eee30100` | `0x54848` | 保存释放锁的函数指针 |

正路径下，本轮范围的 `0x36673` 与 `0x366c7` 分别通过 `0x3ac20` 调度两个已命名的锁函数。磁盘调度槽为 `0x36ae0` 的 `jmp rax`。已固定动态解析的模块、函数名与写入路径。实际装载时的槽绑定与函数地址仍待 Windows 对照，保留原有未决状态。

[原件段回编结果](../../inbox/NATIVE-342/s89/reassembly.json) · [前序引用清单](../../inbox/NATIVE-342/s5/code/references.asm#L7789-L7800)
