# NATIVE-342 s33 静态复验裁定

upstream 对 ApwnIPShell.dll 41.0.0.614 原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b` 与基线 `2d13d4e28bffd770252e8e0c4bb491bdf256a4f6` 复验。固定 [s33 成果清单](../../inbox/NATIVE-342/s33/manifest.sha256) SHA-256 `d1e6beab98f5fcbfd5636936d7a52a66e6dc8086cb820bd509f3c82fef976b79`。

0x33c33–0x33cac 的 23 条指令完整回编。两处 REL32 回填后与原件 121 字节逐字节一致。另回编 .pdata 12 字节及 .xdata 8 字节，覆盖范围在 0x33caa 结束，随后两字节为独立尾跳。

包装函数保存并恢复 RCX、RDX、R8、R9 及 XMM0–3。0x33c6d 以 RCX=0x49320 描述符地址、RDX=入口 RAX 的延迟导入槽地址调用 0x366e0。描述符绑定 HAPP.dll，31 个初始 IAT 槽的 DIR64、INT 序号及同一包装入口逐项相符。首项是 0x52f80 → 0x33cac → 本包装函数，对应序号 58。0x36965 写回选定的指针，0x36995 将 RBX 搬入 RAX；包装函数恢复参数后在 0x33caa 跳至该返回值。外部函数实现、运行期指针和解析器中的回调路径待核。

`python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 输出 `checked 1005 coverage rows, 1005 tool-native entries, 7433 call records, 289 declared gaps`、退出 2；局部回编退出 0。覆盖台账新增 1 个入口。1,005 个入口中 716 个有覆盖、289 个缺口。7,433 条调用和数据引用中有 636 条未决。整件静态验收未通过。 本轮登记 returned，保留现有覆盖和未决清单。下一轮优先恢复 0x34df0–0x34e34 的独立包装函数，具体范围见 [s37 任务卡](../../assignments/NATIVE-342-s37.md)。

[逐指令和原件数据证据](../../inbox/NATIVE-342/s33/reassembly.json) · [验收器复核](s33-verifier-notes.md)
