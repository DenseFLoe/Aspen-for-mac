# Simdll.dll 静态复核

原件是 Plus-Properties 的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/simdll.dll`。PE 版本资源 41.0.0.614，AMD64，373,288 字节，SHA-256 为 `9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601`。[固定输入提交](https://github.com/DenseFLoe/Aspen-for-mac/blob/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials/344/Simdll.dll) · [工单 #344](https://github.com/DenseFLoe/Aspen-for-mac/issues/344)

整件仍为静态验收未通过。本轮定位了原报告的两个入口，另恢复 19 个简单叶函数，并核对内部 19 项分派表。三个重点业务入口已有可编辑控制流模型，依赖侧原型和更深被调实现继续保留在缺口中。[业务源码及逐项解读](code/simdll.c.md) · [叶函数](code/leaves.c.md)

原件异常目录、代码导出、程序入口去重共 911 个锚点。858 个运行时区间中 278 个带有链式 unwind 信息。[区间表](runtime-ranges.csv)记录各段归属、完整区间的字节摘要和从入口能静态遍历的指令字节数。比如 0x31540 主范围接续 0x3163a 和 0x32580 两个从属范围，0x15a10 主范围接续 0x15ab8 和 0x15b25。代码导出 273 个序号对应 166 个唯一入口，单个 0x1370 有 101 个导出序号。

独立 Capstone 遍历产生 1,316 个锚点与直达调用候选。按每个区间的直接控制流解码，0x22a8d 的间接分派使用原始的 19 项 DWORD 表继续展开。其他无法静态绑定的间接跳转停在该指令。[引用索引](references.csv)以十六进制“区间或候选入口:指令 RVA”保存目标关系。独立使用 iced-x86 1.21.0 解码和原始 PE 描述符复查的 11,254 条记录包含 2,334 个直达内部调用、1,916 处直接 IAT 转移、2,221 处经 IAT 跳板的转移、4,147 个 RIP 相对数据引用、388 个跨区间分支、1 个已解析分派及 247 处未决间接转移。IAT 导入按原件的名称或序号区分，引用计数包含调用及尾跳转。

Ghidra 12.2 在同一原件识别 1098 个函数入口。其中 63 个入口扩充了独立遍历，281 个原件锚点或调用目标只出现在独立遍历中。别名和分段 unwind 都可能影响工具计数。导出器按跳板优先归类，结果为 generated=364, thunk=434, warning=300。含 WARNING 字样的输出覆盖 720 个入口，含跳板。可按 [Ghidra 函数表](ghidra/functions.tsv) 的 RVA、原件区间和源码行定位。独立复查已逐行验证源位置及区间字节数。[交叉核对结果](crosscheck.json)

Ghidra 的三个入口均能定位相同的状态字段、分支和跳表操作。0x39c00 的自动返回表达式给出 CONCAT71 和未知高位，原件在 0x39c88 保存 EAX、在 0x39cbd 原样写回 EAX；0x109c0 两个出口分别返回 0 或归一化到 0/1 的 32 位结果。外部调用参数的原型仍需依赖侧证据。

使用 JDK 25 与 Ghidra 12.2 的 analyzeHeadless，执行 `analyzeHeadless <项目目录> Sim344 -import <原件> -max-cpu 2 -analysisTimeoutPerFile 600 -scriptPath <本交付目录> -postScript ExportSimFunctions.java <本交付目录>/ghidra`。本机使用不含点前缀目录名的项目路径。中文安装路径使默认控制台日志配置加载异常，分析进程正常退出；版本、输入指纹、函数边界和 C 文件均从实际项目回读验证。

任务覆盖表共有 1379 个地址。19 个叶函数已逐条对应原件，其余 1360 个地址的缺口、源码索引和恢复条件见 [coverage.csv](coverage.csv)。原件资源树含 9 种类型、50 个资源叶节点，[资源表](resources.csv)已按类型、名称、语言、长度、代码页和每份原始内容的 SHA-256 定位。恢复整件需交付必要资源，复查窗口、菜单等资源与代码引用，绑定剩余间接目标，审查链式区间、类型、数据和外部调用契约，并逐个排除遗漏实现。没有运行 Windows 产品。

## 复查

`python handoff/assignments/check-native-coverage.py NATIVE-344 --original <Simdll.dll>` 对原件与交付检查，预期退出 2。该命令检查 33 个已逐行挂接的重点引用。全范围的引用按 `python verify_references.py <Simdll.dll> <本交付目录>` 复核，预期退出 0。两份人工或叶函数 C 模型分别以 Zig 0.13.0 的 x86_64-windows-gnu C11 编译器生成本地静态对象，编译检查成功。

Capstone 5.0.6、pefile 2024.8.26 与 `recover.py <Simdll.dll> <输出目录>` 可再生遍历、叶函数及表格。在带有已导出的 `ghidra/functions.tsv` 的输出目录内运行即可合并两套入口。完整的证据与产物指纹见[本轮清单](artifacts.sha256)。
