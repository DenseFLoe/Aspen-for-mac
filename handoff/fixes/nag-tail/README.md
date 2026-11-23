# nag-tail 修复台账（455 份 .cs.txt 尾部 ilspycmd 提示）

## 缺陷

`ilspycmd` 在 stdout **末尾**额外打印两行升级提示，我方 dump 直接把 stdout 重定向成 `.cs.txt`，于是这两行被当源码交付：

```text
You are not using the latest version of the tool, please update.
Latest version is '11.2.0.10050' (yours is '9.1.0.7988')
```

这两行**不是合法 C#**（未注释），会直接导致编译失败。上游 #353 指出的是同一缺陷的一个实例。

## 实测形态（全量扫描，非抽样）

| 项 | 值 |
| --- | ---: |
| 命中文件 | **455** |
| 形态异常 | **0**（全部为「末尾恰好 2 行」） |
| 去重后新内容 SHA-256 | 426（29 组是同内容多目录） |
| 落进 T9 1,000 件的件数 | 457 |

## 修复规则（确定性，无歧义）

1. 断言 `lines[-2]` 以 `You are not using the latest version` 开头、`lines[-1]` 以 `Latest version is` 开头；
2. 删除这 2 行，其余行**逐字不动**；
3. 重新计算 SHA-256，写入 `mapping.csv`；
4. 任何断言失败的样本一律不自动修，人工看（本次 0 例）。

## mapping.csv

列：`cache,binary,old_lines,new_lines,old_sha,new_sha,removed,shape`。

- `old_sha` / `new_sha` 为 `.cs.txt` 内容指纹，可用于逐件核对替换是否精确；
- `shape` 全为 `TAIL2`。

## 判据补丁（防再次误判）

T9 的 A6/B4 原来只匹配「行首工具名」横幅：

```python
BANNER = re.compile(r'^(ILSpy|dnSpy|dnfile|Ghidra|IDA|ida64|idat|Hex-Rays|IDA Pro)\b...')
```

补一条句式匹配（大小写不敏感、行首起始）：

```python
NAG = re.compile(r'^You are not using the latest version of the tool\b', re.I)
```

命中即 `fail: tool_nag_tail`。

## 修正后的 T9 结论

| 结论 | 原报 | 更正 |
| --- | ---: | ---: |
| pass | 978 | **530** |
| fail | 15 | **463** |
| partial | 7 | 7 |

> 这 448 件的 `pass` 是判据漏洞造成的误判，不是产物本身合格。
