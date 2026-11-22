# Simdll.dll 指令证据

从 SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601` 的原件以 Capstone 解码。列为模块 RVA、原字节、助记符与操作数，跳转操作数使用 ImageBase 0x180000000。三个业务函数和 19 个简短叶函数各有入口标记。分派函数的跳表属数据，19 个目标由原件的 19 个 DWORD 核对。[再生脚本](../recover.py) · [引用复核](../verify_references.py)
