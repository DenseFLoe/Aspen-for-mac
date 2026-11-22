# ROUNDTRIP-9 · 逐方法重报（267 行）

交付：`methods.csv`（267 行）+ `scheme-C.csv`（9 行）+ 本说明。
判据：`handoff/standards/roundtrip-equivalence.v1.md`（C + A 双项）；校验：`handoff/assignments/check-roundtrip.ps1`。

## 0. 一句话结论

- **267 行 / `(sample, method)` 唯一 / `raw=equal` 恰好 246**，与 PR #372 一致，**无口径漂移**。
- 21 行 `different` 全部带可定位证据（双端 `orig2.il.txt:L…` / `built2.il.txt:L…` + 关键 IL 原文）。
- **`rule` 21 行全留空**。原因见 §2：按 v1 标准，这 21 行没有一行是**单一**白名单条款可解释的；类别 3、4 已被否决，类别 1/2/5 全都与「非白名单改写」同现 → 按「多种差异同现 rule 留空、保守记待核」执行。
- 上游脚本本地实跑 **exit 0**（见 §5）。

## 1. 计数（上游脚本第 7 步的同口径输出）

| sample | methods | raw_equal | adjusted_equal | review |
| --- | ---: | ---: | ---: | ---: |
| AdbComInterfaces | 66 | 66 | 66 | 0 |
| AdbConfigOptions | 18 | 17 | 17 | 1 |
| AdvancedFileDialogLib | 42 | 40 | 40 | 2 |
| AspenTech.HtmlHelp.Logging | 12 | 10 | 10 | 2 |
| AspenTech.HtmlHelp.StrongNameInvoke | 17 | 14 | 14 | 3 |
| Microsoft.Practices.ServiceLocation | 41 | 32 | 32 | 9 |
| SLMServerCLS | 15 | 15 | 15 | 0 |
| System.Buffers | 31 | 27 | 27 | 4 |
| System.Security.Principal.Windows | 25 | 25 | 25 | 0 |
| **合计** | **267** | **246** | **246** | **21** |

`rule` 分布：`1`=0 行、`2`=0 行、`5`=0 行、**空=21 行**（其中无一行填 3/4）。
`adjusted_equal = raw_equal + rule∈{1,2,5} 的 different 行 = 246 + 0 = 246`；`review = 21`。

## 2. 为什么 21 行 rule 全空（本轮最需要上游看的判断）

v1 标准「本轮重报」写明：**多种差异同现时 rule 留空并逐项写明，保守记为待核**；且 3、4 已从白名单移除。逐条核过原件/重编 IL 后，实际情况是：

| 归类 | 行数 | 说明 |
| --- | ---: | --- |
| 类别 3（字符串 switch 哈希 vs 长度+字符） | 1 | `CHtmlHelpLogging::GetLCIDForLog`；已否决 → 留空 + 缺证 |
| 类别 4（逐项写入 vs `InitializeArray`） | 1 | `_DAdvancedFileDialogEvents_EventProvider::Init`；已否决 → 留空 + 缺证 |
| 含类别 1/2/5 元素、但**与其他改写同现** | 5 | ServiceLocation 状态机 4 个成员 + `GetAllInstances()`：编号差异与 `dup` 链/块结构重写/判断次序互换同现，不满足「仅归一生成编号」 |
| 纯非白名单改写（1–5 全不覆盖） | 14 | 分支极性反转（`brfalse`→`brtrue.s`）、`dup` 集合构造、局部槽省略/重编号、`ceq+ceq`→`cgt.un`、`IntPtr::op_Explicit` 被删等 |

**结构性原因**：A 口径基线本身已把方法签名里的 `d__<数字>` 归一为 `d__N`，所以「纯类别 1」的差异不会落进这 21 行；剩下能落进来的必然是「编号 + 别的改写」或「3/4」，于是 rule 只能是空。这不是偷懒留空——每行 evidence 都写明了它属于哪一类、以及为什么不能只归到某一类。

**有待上游裁定的一点**：`<GetAllInstances>d__0`1::.ctor` 的方法体差异**只有**类别 5（线程 ID 两 API），但类名 `d__0`→`d__6`（类别 1，名称层，不改方法体）同时存在。按「多重差异同现 → 留空」我们填了空；若上游认为「名称层类别 1 不计入同现」，这一行可改判 `rule=5`（届时 `adjusted_equal=247`、`review=20`）。我们不做单方面放宽。

## 3. 21 行 `different` 逐条（证据要点；全文见 CSV）

| # | sample | method | 类别 |
| ---: | --- | --- | --- |
| 1 | AdbConfigOptions | `DebugLog::WriteDebug(string)` | 非白名单：守卫极性反转 + `StreamWriter` 接收者求值顺序前移 |
| 2 | AdvancedFileDialogLib | `_DAdvancedFileDialogEvents_EventProvider::Finalize()` | 非白名单：局部槽重编号 + 分支极性 + 末段 `leave` 折叠 |
| 3 | AdvancedFileDialogLib | `_DAdvancedFileDialogEvents_EventProvider::Init()` | **类别 4** + built 少 `castclass` |
| 4 | AspenTech.HtmlHelp.Logging | `CHtmlHelpLogging::GetLCIDForLog(string)` | **类别 3**（10 个 case 逐条对表、无碰撞路径） |
| 5 | AspenTech.HtmlHelp.Logging | `CHtmlHelpLogging::HelpDisplayLangHandle(string)` | 非白名单：null 早退块序（`brtrue.s`+`leave.s` → `brfalse.s`） |
| 6-8 | StrongNameInvoke | `HtmlHelpInitWrap` ×2 + `HtmlHelpInitWrapDisplay` | 非白名单：空对象早退极性 + `object[n]` 由 `stloc/ldloc` 改 `dup` 链 |
| 9 | ServiceLocation | `<GetAllInstances>d__0`1::.ctor(int32)` | 类别 5（唯一方法体差异）+ 类别 1 名称层 → 同现留空 |
| 10 | ServiceLocation | `…d__0`1::MoveNext()` | 类别 1+2 + 非白名单重写（`switch`→`brfalse.s`/`beq.s` 链、`<>4__this` 缓存、finally 前 `ldnull`+`stfld` 清理） |
| 11 | ServiceLocation | `…GetEnumerator()` | 类别 5 + 判断次序互换（threadId 与 `<>1__state` 对调）→ 不满足「替换以外控制流一致」 |
| 12 | ServiceLocation | `…Dispose()` | 类别 1+2 + `ldc.i4.1/sub/switch`→`beq.s`/`bne.un.s` + 新增 `stfld` 清理 |
| 13 | ServiceLocation | `Properties::get_ResourceManager()` | 非白名单：`ReferenceEquals`+`brfalse` → `brtrue.s`；`stloc/ldloc` 省为 `stsfld` |
| 14 | ServiceLocation | `ServiceLocator::get_IsLocationProviderSet()` | 非白名单：`ceq/ldc.i4.0/ceq` → `cgt.un` |
| 15-16 | ServiceLocation | `FormatActivateAllExceptionMessage` / `FormatActivationExceptionMessage` | 非白名单：数组暂存 `stloc/ldloc` → `dup` 复用栈顶 |
| 17 | ServiceLocation | `ServiceLocatorImplBase::GetAllInstances()` | 类别 1（`newobj TypeSpec` d__0→d__6）+ `stloc/ldloc`→`dup` |
| 18-19 | System.Buffers | `ArrayPoolEventSource::BufferAllocated` / `BufferRented` | 非白名单：5/4 处 `IntPtr::op_Explicit` 被删，外部成员集 5→4 |
| 20 | System.Buffers | `DefaultArrayPool`1::.ctor` | 非白名单：局部槽合并 / 重编号（省 2 条） |
| 21 | System.Buffers | `Utilities::GetMaxSizeForBucket(int32)` | 非白名单：返回表达式折叠（去 `stloc/ldloc`，8→6） |

## 4. 缺证清单（拿不出标准要求的粒度，登记缺证，不补推通过率）

1. `CHtmlHelpLogging::GetLCIDForLog`（类别 3）：两侧 10 个字符串 case 与目标分支、null/default、哈希常量互异性已静态核对（无碰撞路径），**未做运行期字符串对照**；`ComputeStringHash` 对 null 返回 0 依赖 CLR 局部零初始化。
2. `_DAdvancedFileDialogEvents_EventProvider::Init`（类别 4）：长度 16 / 元素 `System.Byte` / 索引顺序与原件源字面量 `byte[16]{214,108,17,121,…}` 逐字节吻合、填充在 `Guid::.ctor` 之前且数组未外泄；但 **dump 无 FieldRVA 表，`ldtoken (0x04000005)` 指向的 RVA 实际 16 字节无法核对**。要关掉这条需补 FieldRVA 读取。

## 5. 校验（本地等价 + 上游原脚本实跑）

- 上游 `check-roundtrip.ps1` 原文，在本地按它自己的相对路径布局（`assignments/` + `inbox/ROUNDTRIP-9/`）实跑：**exit 0**，输出 9 样本的 methods / raw_equal / adjusted_equal / review 表（即 §1）。
- 我方加严校验 `validate.py`（复刻脚本全部 throw + `rule` 只允许 1/2/5 + evidence 必须含 `orig2/built2.il.txt:L<行号>` + 逐样本方法数）：**RESULT: PASS**；19 条 WARN 是「rule 空且 evidence 未写『缺证』」的提示项，对应 §2 的「非白名单改写」行（它们不缺证据，是缺条款），非失败。

## 6. C 口径（`scheme-C.csv`）

9 行，`only_orig=0 / only_built=0`，9/9 件签名投影完全相等（267 = 267）。与 `out/p2/scheme-C.csv` 逐行逐列一致，并经独立复算脚本重算确认。
**C 全过不等于本批放行**：C 只覆盖结构完整；`AdbComInterfaces` 整件 66 条为空方法体（接口/导入），对 A 口径只提供签名层证据。

## 7. 证据分级

- 〔已实测〕267 行由双端 IL dump 现算；246/21 拆分；C 9/9；上游脚本 exit 0；21 条不同方法的指令数、外部成员集、关键 IL 原文与行号。
- 〔未验证〕类别 3 的运行期字符串行为；类别 4 的 RVA 实际字节（缺 FieldRVA 表）；`AdbComInterfaces` 66 条空体的指令级等价（无指令可比）。
- 〔无法判定〕本轮只有 9 件样本，不外推到 1,315 件；编译器/目标框架一变，1/2/5 白名单需重审。

## 8. 复跑

```
cd _work/wf-20261120-aspen-batch
python out/rt9/gen_base.py     # 267 行骨架（含双端行号锚）
python out/rt9/merge.py        # 合并 21 条定因片段 -> out/rt9/methods.csv + scheme-C.csv
python out/rt9/validate.py     # 加严等价校验（RESULT: PASS）
pwsh -NoProfile -File out/rt9/_stage/assignments/check-roundtrip.ps1   # 上游原脚本，exit 0
```