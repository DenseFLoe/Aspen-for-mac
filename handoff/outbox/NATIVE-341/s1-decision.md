# NATIVE-341 第一号分配复验

**裁定 returned。** 原件为 Plus-Properties 的 mmstruct.dll，530,472 字节，SHA-256 为 `bb9a2422bffe3a6aaa6c2a533ef7b4ef25d14092560d519bc93b94e216ce4870`。实际分配为 `assigned_seq=1`，候选将本次补交标为 s9。按 [#402 的提交](https://github.com/DenseFLoe/Aspen-for-mac/commit/b6d41c2c8d5df88be8eef96ab665a61f801ba58a) 逐件裁定。整件静态验收未通过。

主干 `773260c1033e524cebe000699409f5708bebfda0` 的检查器 SHA-256 为 `1dd8066c1c791e74e8f169dddadea00976986ed275b07025a8d0bc1da80b2480`。在该版本的仓库结构内放入固定提交的候选，运行 `python handoff/assignments/check-native-coverage.py NATIVE-341 --original <mmstruct.dll>`。退出码 0，检查 2,015 条覆盖、2,015 个工具入口、4,409 条引用和 0 项申报缺口。原件异常目录、入口及导出合计 1,665 个锚点。逐条对照 80,724 个清单地址的完整指令字节，Capstone 5.0.6 解码长度吻合。3,461 处直接导入跳转或调用均与原件 IAT 和符号相符。

- 旧提交 `a8c10755a5c15681f929c9957e4056b06fdb5bdb` 中的 1,034 条未决转移全部从 calls.csv 移至 code/indirect.csv，仅改变类别。按相同反汇编范围独立解码，共有 1,119 处非直接 IAT 的间接调用或跳转。另有 85 处在两张表均缺失。可确定的转移按实际目标登记，其余在主表以 unresolved 登记，并给出查过的路径和恢复条件。
- 有 16 处漏项可以从本件的动态导入初始化静态绑定。从 `0x103b` 的 LoadLibraryA 取得 sorresdll.dll，`0x1041` 写入模块指针。随后 `0x1012` 的 GetProcAddress 查找 GetSorResStringEx，`0x1018` 将结果写入 `0x79fa0`。原件 `0x5530`、`0x557a` 等 16 处间接调用均使用此槽位，逐址清单在 JSON 的 resolved_indirect 中。
- 另有 1,007 处指向 133 个已知单跳 IAT 跳板的调用或跳转。需保留调用点、跳板、槽位、最终导入符号的联系。已有 948 条数据引用；`0x44474` 和 `0x44481` 装入同一临界区对象 `0x9b868`，对应 EnterCriticalSection 和 LeaveCriticalSection，均缺数据关联。整件复验还需补齐必要资源及可编辑实现。

[逐址清单](s1-addresses.csv) 包含 85 个漏项、1,007 个跳板调用位置和 6 个具名 API 相关数据引用。原件、候选各文件指纹、旧版比对、16 个动态导入调用点及 13 个资源叶的大小和哈希见[独立复核记录](s1-audit.json)。补交可沿用已核实的直接 IAT 证据。
