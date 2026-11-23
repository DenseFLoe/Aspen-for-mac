# NATIVE-340 s85 补证复核

候选 [#450 固定提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/d2e8dff2dae22284e9c37e57cc7e71dc7cc4b732) 仅修改三份 s85 回执及指纹附件，与 s89 任务分开处理。WrapSaveMergeNNFiles.dll 的 SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。重新计算 s85 清单的 140 个 SHA-256，全部吻合。主干覆盖 v1 复跑退出 2，仍为 1,105 行覆盖、354 个原生入口、559 条引用、0 个声明缺口。s85 已退回，s89 续领沿用。

QA 固定提交 `27007e5a9590b294795f23d43181306b4111b2e5` 中，`qa/det_omitted_sites.py` 的 SHA-256 为 `2424b60278d5ed26226f1a2432a14c78f096e7085a021437370235a566333d1c`。在 s85 候选上重放该单元，捕获 67 个原生 IAT 转移站点，其中 19 处无对应清单站点，含 0x4711 到 `KERNEL32.dll!QueryPerformanceCounter`。`prefixed_thunks=2`，已纳入 67 个站点。19 处应逐站核对实现与引用，属于历史交付缺口。[逐站输出](s85-qa-omitted-sites.json)

## 托管 calli 复跑

`python -B s85-qa-calli-control.py QA ORIGINAL CANDIDATE`。QA 为固定提交的 `qa/` 目录，需 pefile 和 Capstone。CANDIDATE 为上述固定提交的 `handoff/inbox/NATIVE-340/`。

原件两条托管 `calli` 都在 `IL_0004`，归属 MethodDef `0x06000056` 和 `0x06000057`。配对保留原件和同一份 IL 列表，第二组只删 `0x06000057` 的登记行，更新清单输入指纹。按覆盖证据 v1，第二组应多报一条归属该 token 的缺项。实测两组各报 13 个其他 calli 缺项，均未报 `0x06000057 IL_0004`。该工具的列表引用分支仅按偏移匹配，共用偏移会掩盖某个方法中漏列的转移。

建议从证据的 MethodDef 上下文解析归属，按 `(MethodDef token, IL offset)` 比对。回归使用同一原件和这两组输入，预期两组分别报告 13 和 14 个缺项，并明确列出第二组新增的 `0x06000057 IL_0004`。[复跑程序](s85-qa-calli-control.py) · [固定输出](s85-qa-calli-control.json)

[QA 检测器源码](https://github.com/DenseFLoe/Aspen-for-mac/blob/27007e5a9590b294795f23d43181306b4111b2e5/qa/det_omitted_sites.py) · [s85 裁定](s85-decision.md) · [s89 续领](../../assignments/NATIVE-340-s89.md)
