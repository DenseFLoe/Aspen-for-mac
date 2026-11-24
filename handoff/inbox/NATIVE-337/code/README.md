# NATIVE-337 · FindComponent.dll 静态逆向交付

本目录是静态分析证据，不是可编译源码，也未验证部署机上的 COM 调用。原件是 `_t13/orig/FindComponent.dll`；原件 SHA-256 和分析范围见 [`run.json`](../run.json)。

| 从哪里查 | 内容 |
| --- | --- |
| [`coverage.csv`](../coverage.csv)、[`native-functions.csv`](../native-functions.csv) | 按 `kind,key` 查覆盖状态和 listing；按 `rva` 查分析器登记的函数。 |
| [`calls.csv`](../calls.csv)、[`metrics.json`](../metrics.json) | 按 `caller,callee,class` 查调用和数据引用；未决目标的恢复条件在 `note`，不是 CSV 列 `recovery`。 |
| [`native.asm`](native.asm)、[`native.c`](native.c) | 汇编 listing 与反编译文本；`listing` 给出对应文件和行号。 |
| [`s33-two-hop.csv`](s33-two-hop.csv)、[`s33-dual-host.csv`](s33-dual-host.csv) | 历史二跳证据和原件/候选宿主对照；后续二跳补证见 [`s37-two-hop.csv`](s37-two-hop.csv)。 |
| [`s81-showdialog.csv`](s81-showdialog.csv)、[`s97-registration.json`](../s97-registration.json) | 调用侧与登记附件对照：签名在 `instruction`，方法 RVA 在 `meaning`；`Registry64.codeBase` 是附件中的部署路径，不是从上述原生原件读到的。 |

真实 `CodeBase` 部署 DLL 与运行时 DISPID 待核；不得用附件声明、同名文件或合成 PE 替代真实部署字节。`tool/s117_verify.py` 的通过只表示 listing 与声明核对通过；`tool/t337_r1_binding.ps1` 才尝试读取实际部署 PE。

[`s121-fingerprints.json`](../s121-fingerprints.json) 是本轮清单，键为交付项内相对路径，值为文件字节的 SHA-256；本 README 纳入清单。历史 [`s117-fingerprints.json`](../s117-fingerprints.json) 原样保留。本轮基准、复跑命令和退出码见最终回执 `s121-submission.md` 的 §33。
