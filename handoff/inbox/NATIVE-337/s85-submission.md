# NATIVE-337 s85 提交（ABI 与计数更正 + VARIANT 复核 + FF/4 接入枚举）

- 基线：#445 @ 661da2d；分支沿用，head 前移。

## ① 三处表述更正（已改 tool/s81_showdialog.py 与 code/s81-showdialog.csv）
1. **0x1389 参数位置（Windows x64 ABI）**：RCX=this(RDI)、RDX=rgszNames、R8=cNames、R9=lcid，**第 5 个参数 rgDispId 在栈上 [RSP+0x20]**；不再写「lcid=R9D」这类与栈参混排的句子。
2. **DISPAPARAMS 两个计数**：`[RSP+0x60]` 是**两个 32 位字段**被一条 qword store 写入 —— **cArgs = 1（低 dword）/ cNamedArgs = 0（高 dword）**，不再合并成一个数字。
3. **返回值只取低 32 位**：`0x1449 CMOVNS ESI,[RSP+0x88]` → `0x1469 MOV EAX,ESI`，函数返回 `int`，**只有 RAX 的低 32 位有意义**（高位未定义，调用方按 int 使用）。

## ② VARIANT 实参（0x13dd–0x13fa）
| 项 | 证据 | 结论 |
| --- | --- | --- |
| 初始化（清零范围） | 0x13CF `CALL [0x1800070f0]` = **OLEAUT32.dll!#8 = VariantInit**；循环 0x13C0–0x13DB：元素 = `[RSP+0x68 + i*0x18]`，计数取 `[RSP+0x60]`（cArgs=1） | 24 字节 VARIANT 数组被 VariantInit 清零（本轮实为 1 个元素） |
| vt | 0x13DD `MOV EAX,8` → 0x13E2 `MOV word [RSP+0x68],AX` | **vt = 8 = VT_BSTR**（16 位字段） |
| 联合体 | 0x13E7 `MOV qword [RSP+0x70],RBP` | `union.bstrVal = RBP`（前面构造的 BSTR 指针）；VariantInit 之后只写 vt(2B) + union 指针(8B) |
| 传参 | 0x13AC `LEA RAX,[RSP+0x68]` → 0x13B1 `MOV [RSP+0x50],RAX` | rgvarg 指向该 VARIANT，cArgs=1 |

**清理顺序**（Invoke 返回后）：0x1449 取结果低 32 位 → 0x1451 `MOV RDX,[RDI]` → 0x1454 `MOV RCX,RDI` → **0x1457 Release** → 0x145B `LEA RCX,[RSP+0x80]` → **0x1463 `CALL [0x1800070d0]` = OLEAUT32!#9 = VariantClear(pVarResult)** → 0x1469 `MOV EAX,ESI` 返回。失败路径 0x1396 的 Release 在 0x1399 返回 0 之前，无 VariantClear（此时 VARIANT 尚未构造）。

## ③ ShowDialog 绑定
仍**无**可追溯的类注册数据或类型库落到该 CLSID/ProgID（0x2330 走 CLSIDFromProgID→CoCreateInstance，ProgID 来自 0x2399 附近的字符串，但注册表值不在静态件里）。按卡要求：**外部类型保留为未决**，不硬绑。已证边界：工厂链、IID_IDispatch、槽位与成员；所需输入：目标机注册表 `HKCR\<ProgID>\CLSID` 或该组件的类型库 IDL。

## ④ 工具侧：FF/4 判型接入实际枚举
- `tool/s73_stations.py` 与 `tool/s37_two_hop.py` 的 thunk 识别由 `(modrm & 0xC7) == 0x05` 改为**同时要求 `reg == 4`**（`FF /4 mod=00 rm=101`）；此前 `FF /0`（INC）会与 `jmp [rip+disp32]` 撞型。
- 接入后站数：**161 → 161（变化 0）**。`xor`：`rows 161; discovered_from_listing=161`，`stations 161`。
- 配对 1（同位移 JMP/INC）：`PAIR jmp-vs-inc : jmp=jmp inc=inc PASS`。
- 配对 2（同 DLL 不同 IAT 身份）：新增 T6，把 0x106C 的 callee 从 `mfc140.dll!#2344` 改成 `#2345` → `contradiction=1, site=0x106C`（整串判等，前缀/同库不同序号都不认）。

## 判定（原始 stdout）
~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~
exit code: 2（112 条未决已申报）

## 指纹
- 见 work/s85-tools.txt
