# check.py 静态证据说明

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。成果 SHA-256 为 `b16d7732a0407adc1fe1c9db40309341b320cfc7046bf5a868a7dce9a7d14520`。

读取原件 SHA-256、AMD64 异常目录和指令，复跑可达范围、链式 unwind、三个运行期导出查询和回调缺口；复用 s5/reassemble.py 的 COFF REL32 对照。将 JSON 标准输出与 reassembly.json 比对。需 Python 3.11、Capstone 5.0.6、pefile 2024.8.26 与 Zig 0.13.0。未执行原件。
