# NATIVE-340 s33 提交

- 分支：tietoumiao/native-340-s33（基于 #446 / 57a2c23f）
- head：见 #13
- 判定（真实退出码）：check-native-coverage.py exit 2；check-s29-446.ps1 exit 0

## 三条修正

# ① 0x21AE 三点写全
- 空槽判定：0x2187 `cmp qword ptr [rax],0` + 0x218B `jz 0x21B1`；另有 0x2190 `call 0x2874` 的节判据（0x28F3 起 14 字节 `83 7A 24 00 7D 04 32 C0 EB 0A B0 01 EB 06`，0x2197 跳过）。
- 节属性：槽 `0x19B78` 在 `.data`（VA 0x19000，Characteristics 0xC0000040 可写），raw 结束 0x19A00、虚拟结束 0x19B80，即零填充尾部、静态未初始化。
- 单次读取：0x21A4 `mov rax,[rbx]` 对固定槽只读一次；0x21A7 `mov r9,[0x61B8]`=0x48B0；0x21AE `call r9`；0x48B0=`FF E0`(JMP RAX)。

# ② 移除额外 COM vtable 读描述
- 1 处：0x21AE 主表行。旧 callee 的 `COM vtable slot 0` 与旧 note 的「再走对象 vtable 槽 0」按原件删除（0x21A4 之后没有对 RAX 的二次解引用）。

# ③ 0x06000031 IL_0008
- 签名 0x11000043（blob 0101205120610918）；接收者=arg0 对象，函数指针取自 vtable +0x10。
- loc1 来源：0x06000032 的 finally（RVA 0x1B28，1 个 EH 子句）把 loc1 传给 0x06000031；loc1 由 0x06000030 经 CLR 宿主接口取得（clsid {CB2F6723-…} / riid {CB2F6722-…}）。
- 绑定范围：仅 0x06000032 的 finally 路径；该行 class 仍 unresolved（被调函数是运行期指针）。

## 指标与附表
- 未决附表由主表实际生成：托管 13 / 原生 15（`code/s33-unresolved-*.csv`，同步 `code/s25-unresolved-*.csv`）。
- `s29_ctor_rows_added` 由 0 改为 5；external 228 / boundary 303 / unresolved 28；237 槽 / 122 MethodDef / 228 回编桩不变。
- 指纹在 `code/s33-audit.md` 定稿后生成（`code/s29-fingerprints.json`），检查器逐个校验。

## 判定原始输出

~~~
$ python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2

$ pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340
exit code: 0
（pwsh 7.7.0；candidate_asserts_second_vtable_read=false、old_managed_annex_already_bound_sites=[]、
 candidate_s29_ctor_rows_added=5、fingerprint_mismatches=[]）
~~~
