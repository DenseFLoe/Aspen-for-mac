# ApwnIPShell.dll 第五号事件的可接续证据

本轮状态为 working。原件来自固定提交 `64670801de54e990f975aaeda06e89340c0e4e08`，SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。已完成七处分派的原件核验、Ghidra 全件导出、首轮缺口与当前反编译范围的对接。原件级验收仍待实现、调用与资源的逐址核对。

| 旧区间入口 | 原件内可达指令数 | 每张表的输入数 | Ghidra 与表字节共同确认的不同目标数 | 现已定位的业务调用 |
| --- | ---: | --- | --- | --- |
| 0xdad0 | 967 | 26 | 25 | HappGetTree、GRinqusrexp 等出现在导出处理路径。 |
| 0x12bc0 | 602 | 8 | 3 | SimUpdateMessageView、HAProcessTypeIntegrityCheck 与 GRsetrcl 出现在该函数内。 |
| 0x1fe50 | 230 | 20 | 7 | 函数调用 HAFullBlockName 和 CxsRaiseCustomEvent。 |
| 0x21b90 | 771 | 45、117、147 | 3、4、39 | 三处跳表位于同一 Ghidra 函数体，包含 SimReflect 和 HappFireUpdateMessage 等调用。 |
| 0x22ad0 | 298 | 22 | 6 | 函数含 VariantChangeType、ReadClassStm 及 CoCreateInstance。 |

iced-x86 1.21.0 独立解码了比较上限、默认分支、间接跳转、跳表和四张字节选择表。385 个选择值可逐项映射，Ghidra 12.2 读出的七组目标集合均与之相等。已验证 2,868 条可达指令全部与已知表区域分离。以上判断以所列五个原件区间为界，外部被调实现、间接调用和异常处理仍需核对。[逐项结果](s5/switch-review.json) · [Ghidra 分派表](s5/ghidra/switches.tsv)

Ghidra 导出 898 个实际函数入口、13 个分段 C 源文件，按跳板优先登记 174 个跳板、218 个带警告的其他函数及 506 个其他输出。函数名、边界、字节数和源码行均可回读。首轮 801 个 gap 中，694 个对应当前 Ghidra 独立入口，107 个落在其他函数体内部。Ghidra 还提供 192 个首轮未列的入口，两份索引并集共 1,005 个地址。所有地址均回读原件最初 8 字节，首轮的 12 个短函数保留其已有证据。函数体定位只解除源码获取的缺口。[首轮逐址对接](s5/address-map.csv) · [本轮函数和源码行](s5/ghidra/functions.tsv)

下一步先按五个函数内的分支核对实际导入、COM/间接调用与关键数据引用，将原来的 107 个段内入口逐个确认父函数和代码边界，再按同一判据审查 192 个新增入口。在补齐本轮覆盖表与逐址调用证据后提交复验。首轮的 SetHelpFile 调用及指纹继续按原记录复用。

## 复跑

1. 用 Ghidra 12.2 与 JDK 25 执行 `analyzeHeadless <项目目录> Apwn342s5 -import <原件> -max-cpu 2 -analysisTimeoutPerFile 600 -scriptPath <本轮s5目录> -postScript ExportApwnFunctions.java <本轮s5目录>/ghidra`。Windows 运行使用不带点前缀目录名的项目路径。本机的中文安装路径使默认详细日志配置失败，分析进程退出 0，已另行验证实际输出、版本和原件指纹。
2. 执行 `python check-switches.py <原件> <s5-recovery.json> --ghidra-folder <本轮s5目录>/ghidra`，在标准输出获取全部选择值和目标。
3. 执行 `python map-addresses.py <原件> <首轮coverage.csv> <本轮s5目录>`，复查原件字节、全部区间、来源文件及行号，得到逐址映射和汇总。
