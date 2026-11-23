# NATIVE-340 s73 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 5ca17f4987251f32be4772955c8b9be3185b9c62
- 本轮 head：见 #13

## 1. 更正：Flags / ImplFlags / 访问级别

| token | 名称 | Flags | ImplFlags | 访问 | Static | HasSecurity |
| --- | --- | --- | --- | --- | --- | --- |
| 0x06000056 | `___CxxCallUnwindDtor` | **0x4013** | **0x0** | **assembly** | 是 | 是 |
| 0x06000057 | `___CxxCallUnwindDelDtor` | **0x4013** | **0x0** | **assembly** | 是 | 是 |

根因：`md_reader` 之前完全没有解析 MethodDef 的 Flags/ImplFlags，审计里 `m.get("flags",0)` 取到默认 0 →
被误读成 privatescope。现按行布局（RVA、ImplFlags、Flags、Name、Signature、ParamList）读取，
`0x4013 & 7 = 3 = Assembly`。三处（访问表、主表、报告）已同步。

## 2. IL SHA-256（完整 64 字符）

两方法 IL 体相同：`cf6b47445b3281297d160b230f3d5a4c08006679b0b937098c432073b5ee0b0d`（28 字节）。

## 3. 元数据编码解码

MemberRefParent（3 位 tag：TypeDef 0 / TypeRef 1 / ModuleRef 2 / MethodDef 3 / TypeSpec 4）与
MethodDefOrRef（1 位：MethodDef 0 / MemberRef 1）已解码成「表 + 行号」，单元配对与实况：

- 单元配对：17→TypeRef[2]、11→MethodDef[1]、27→MethodDef[3]、33→TypeRef[4]；3→MemberRef[1]、2→MethodDef[1]、0x1C→MethodDef[14]。
- 实况：109 条 MemberRef 的父全是 **TypeRef 105 / TypeSpec 4**（无 MethodDef 父）；**MethodImpl 表 0 行**（声明列/实现列解码为空）。
- 可见性配对：0x06000056（assembly）与一个 public IL 方法，两者均无 MemberRef/MethodImpl 绑定；预期/实测/输入 SHA-256 见 `code/s73-binding-pairs.csv`。

## 4. 0x06000057 的入口来路

| stub | jmp 目标 | 槽 | 槽初值 | 说明 |
| --- | --- | --- | --- | --- |
| 0x5574 | 0x19600 | 0x19600 | 0x06000056 | 0x56 入口 1 |
| 0x557A | 0x19608 | 0x19608 | 0x06000056 | 0x56 入口 2 |
| 0x5580 | 0x558A（`eb 08`） | - | - | 跳到入口 2 |
| **0x5584** | **0x19610** | **0x19610** | **0x06000057** | **0x57 入口 1** |
| **0x558A** | **0x19618** | **0x19618** | **0x06000057** | **0x57 入口 2** |

两方法各有两条 `jmp [slot]` 入口，槽初值是 MethodDef token（即 CLR fixup/precode 未修补前的占位），
首次调用由运行时改写为实际入口。arg0 来源仍只在本模块的 11 个站点可见；外部调用者与运行期写入者留未决，
查找范围＝本模块外的 IL/导出与运行时 precode（行为测试留 Windows 阶段）。

## 5. 复核

8 方法 / 11 站点（0x0600001F IL_0087 的 `ldloca.s 0x4` 现写明是**局部 4**）、35 个 EH 子句、
AL 三态 0/1、删一站后证据指纹变化并定位、两套指纹刷新。

## 6. 判定（真实退出码）

```
check-native-coverage.py  exit 2   1105 / 354 / 559 / 0（未决：13 托管 + 15 原生）
pwsh check-s29-446.ps1    exit 0  指纹 77 项、无差异
audit_340_s73.py ×2       exit 0   连跑两次逐字节一致
```
