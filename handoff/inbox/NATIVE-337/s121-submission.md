# NATIVE-337 · T337-R3 最终回执

- **证据提交**：`803c1fbe5cfad56a2f91cffe2fe59e33d26c43db`；**Git tree**：`c048d5212a7f55bae580ef299094adc139be245a`。两者为 Git SHA-1。当前交付副本无 `.git`，此提交在独立本地仓创建，通过根目录的 [`_evidence_T337-R3.bundle`](../../../_evidence_T337-R3.bundle) 随交付提供；不是上游分支 head，未 push。
- **基准**：s117 清单 SHA-256 `4b01f6046cbb6d8f5e7d606e393a8ed217fd417562c7f3bb9d10e3b4c3995e9e`（109 项）；原生原件 `FindComponent.dll` SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。
- **交付**：[`s121-fingerprints.json`](s121-fingerprints.json) 110 项，SHA-256 `100b999b142e8d5950145e42ca045deb6d62891efb8a08ae41f66dd22b821cc9`。唯一新增清单键 `code/README.md`，SHA-256 `60045ac5d600fb350f81ac26a96870de9358428e4656727ee2e881329b71332f`；其余 109 项未变。生成器重跑两次都与提交内清单逐字节一致。
- **边界**：树内有 README、s121 清单与排除记录、脚本及复跑输入；本回执在复跑后写于树外，反向引用证据提交，避免自引用。真实部署 DLL、其元数据和运行时 DISPID **待核**；覆盖检查的 `2` 是存在申报未决项，不是零退出。

## §33 检验器脚本

### §33.1 树内脚本、版本与判据

下表文件均在上述证据提交树内；后列为实际解出字节的 SHA-256，不是本地游离副本或旧回执中的数值。历史回归驱动为树内 `_round_report_T337-R2.md` 的 §2–§4，其 SHA-256 为 `1e49af659d09641b135590a9681b2a1ae782025e0371c484c12a0bd79ffd73c2`。

| 树内路径 | 字节 | SHA-256 | 判据或角色 |
| --- | ---: | --- | --- |
| `qa/mk_fingerprints.py` | 3208 | `d8d048081a41d276ff98a910f9729bd8d3c2ba6b6540ed80df100d5f1c81f04c` | `RULES` 和 `main`：同一生成器，走原有排除规则、排序后重生；§33.3 检查输出字节和路径集 |
| `handoff/assignments/check-native-coverage.py` | 15884 | `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8` | 上游检查器 pin；`main` 核对原件 SHA-256，`verify` 核对覆盖/listing/调用并返回未决状态 |
| `tool/t337_r1_binding.ps1` | 16955 | `af1140bc18eab130699287b1dc2fecb2df20f13dbec0e204463047a8080726c6` | `Read-Deployment` 以实际字节绑定 `CodeBase`；缺原件输出 `CodeBase.PE` 并退出 2 |
| `tool/s117_verify.py` | 7577 | `0069dc3a8237f5550ccf9cf4db8715d0832bd4decfaf7de805a9bd739fa6259e` | `verify_listing`、`verify`：原件两处 listing 字节和附件/CSV 声明 |
| `tool/s117_variants.py` | 3657 | `5629cef61d56b63719ae276b086e0b0e44aa65dab74b1c80fc75a61e0a02fb93` | `main`：四组拒绝含定位 |
| `tool/s113_variants.py` | 3073 | `4e828c9ad5b64f85c179a15216db6c9558326c7ee2ea9a5bd2321a9417d986d6` | `main`：四组历史拒绝 |
| `tool/s113_verify.py` | 6672 | `6b426eaf429b0d17babf9f82cab7e7845a63b1335c381d336f2e0bf9079f2175` | s113 `verify` |
| `tool/s109_counters.py` | 3924 | `ce2c87462340e02fc996f2d0893623c7ced3f0451d5c28bdd22b1af147f488f7` | `main`：四组历史拒绝 |
| `tool/s109_verify.py` | 6407 | `970cdb4fd9e3941ef2112d365d4eff18124548e3e49ed71472827caac1138d60` | s109 验签 |
| `tool/s105_counters.py` | 4096 | `d1a0c6619d56c436d96e0d16faa2f02692a41e272e41323ced8fa3e0c778a4e7` | `main`：四组历史拒绝 |
| `tool/s101_counters.py` | 2557 | `62681e7faa2e99521b345ee96744439ba51d31855516b3b91af157709cd14a20` | `main`：三组历史拒绝 |
| `tool/s101_verify.py` | 5151 | `57d8cdeec3d3369a32d2c86279df8b0a6c7edea7910081efc273b4bdd7a0215a` | s101/s105 验签 |
| `tool/cli_tables.py` | 16051 | `6c15fc62f524ed30cbdadacc1070ad0bb2fe5c20fd7dcf923641cf2475fc9959` | `read` 读取 A/B/D 合成夹具的元数据作独立对照 |
| `tool/pe_reader.py` | 5778 | `5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367` | `PE.filepos`、`parse_asm` |
| `tool/ident.py` | 2150 | `e79c0fe572dfaf07c2c24fecb40b1e8dc2777df29f4f68ce14f9c7a94d442878` | `same_ident` 判等依赖 |
| `_t14/qa/93bf962c/qa/gate.py` | 16338 | `633146c4d885e637e92a3531688dc211c9babcaeb0d10217134420a6977ac181` | `run_l1` 比较上游 pin；`aggregate` 运行登记单元 |
| `_t14/qa/93bf962c/qa/registry.py` | 842 | `7fcf492f3e7e55d68aaf0c5e7da34d72794407b862688ab398019e311f3da14d` | `REGISTRY` 登记 14 个检测单元 |
| `_t14/qa/93bf962c/qa/det_fingerprint_pathset.py` | 7267 | `d0379abfd3df805081b5514ae0acf04e956018cc563b8cec4ac482aae07d3316` | `detect` / `judge`：当前清单的声明路径和内容 |
| `_t14/qa/93bf962c/qa/det_semantic_rebuild.py` | 8210 | `ec67488b57649700199b37d7ea64b733d0018e062f1baa0e5dffcbd8a08cbe78` | `detect`：原件指令语义复核 |

QA 版本：按本地归档标识 `93bf962c` 记录，**与上游 Git 对象的归属待核**；本轮可核的是提交树内 QA 31 文件整组摘要 `33c2f17d710dc8b2f6189b7a42012575408cba18dcc5974c76686bc73d83feaa`，以及 `.local/pylibs` 99 文件整组摘要 `76eec926108117bdbc98c68c036ab932579555957b448ed72ce85dfaa4bd317f`。整组摘要为 `{树根相对路径: 文件 SHA-256}` 以键排序、紧凑 JSON 的 UTF-8 字节做 SHA-256。以下命令也逐项打印 QA 辅助脚本与其余检测器的字节数和 SHA-256：

```bash
python -I -B -X utf8 - "$fixed" <<'PY'
from pathlib import Path
import hashlib, json, sys
root = Path(sys.argv[1]); sha = lambda b: hashlib.sha256(b).hexdigest()
for folder in ('_t14/qa/93bf962c/qa','.local/pylibs'):
    pins = {}
    for p in sorted((root/folder).rglob('*')):
        if not p.is_file(): continue
        data = p.read_bytes(); name = p.relative_to(root).as_posix(); pins[name] = sha(data)
        if p.suffix == '.py' and folder.startswith('_t14/'): print(name, len(data), pins[name])
    digest = sha(json.dumps(pins,sort_keys=True,separators=(',',':')).encode('utf-8'))
    print(folder, f'files={len(pins)} map_sha256={digest}')
for name in ('qa/mk_fingerprints.py', 'handoff/assignments/check-native-coverage.py', '_round_report_T337-R2.md', '_t13/orig/FindComponent.dll'):
    b = (root/name).read_bytes(); print(name, len(b), sha(b))
for p in sorted((root/'tool').glob('*')):
    if p.is_file():
        b = p.read_bytes(); print(p.relative_to(root).as_posix(),len(b),sha(b))
PY
```

### §33.2 解出固定树，核对路径及 Git blob

在交付根目录用 Windows Git Bash、Python 3.13.5 和 PowerShell 7.7.0。先执行这一块设置 `fixed`；后续命令从该固定树取数，不使用工作副本替代脚本或 PE。

```bash
bundle=$(cygpath -am ./_evidence_T337-R3.bundle)
printf '%s  %s\n' 43f19de71a137400740b210b6df6554868f9909ceda8098eabd09a057f82f650 "$bundle" | sha256sum -c - || exit $?
base=$(mktemp -d /tmp/t337-r3-replay.XXXXXXXX) || exit $?
git init -q --bare "$base/git" || exit $?
git -C "$base/git" bundle verify "$bundle" || exit $?
git -C "$base/git" fetch -q "$bundle" refs/heads/evidence/T337-R3:refs/heads/evidence/T337-R3 || exit $?
commit=803c1fbe5cfad56a2f91cffe2fe59e33d26c43db
tree=c048d5212a7f55bae580ef299094adc139be245a
test "$(git -C "$base/git" rev-parse refs/heads/evidence/T337-R3)" = "$commit" || exit 1
test "$(git -C "$base/git" rev-parse "$commit^{tree}")" = "$tree" || exit 1
mkdir "$base/tree" || exit $?
(set -o pipefail; git -C "$base/git" archive "$commit" | tar -xf - -C "$base/tree") || exit $?
fixed=$(cygpath -am "$base/tree")
printf 'fixed commit=%s tree=%s\nfixed archive=%s\n' "$commit" "$tree" "$fixed"
python -I -B -X utf8 - "$fixed" "$base/git" "$commit" <<'PY'
import hashlib, subprocess, sys
from pathlib import Path
root = Path(sys.argv[1]); git = ['git','-C',sys.argv[2]]
entries = {}
for line in subprocess.check_output(git+['ls-tree','-r','-z',sys.argv[3]]).split(b'\0')[:-1]:
    meta,name = line.split(b'\t',1); mode,kind,oid = meta.split()
    assert kind == b'blob' and mode in (b'100644',b'100755'), line
    entries[name.decode('utf-8')] = oid.decode('ascii')
assert entries.keys() == {p.relative_to(root).as_posix() for p in root.rglob('*') if p.is_file()}
for name,want in entries.items():
    b = (root/name).read_bytes(); oid = hashlib.sha1(f'blob {len(b)}\0'.encode('ascii')+b).hexdigest()
    assert oid == want, name
print(f'archive Git-blob SHA-1 checked={len(entries)} mismatches=0')
PY
```

实测 bundle 校验、导入、解出及逐文件校验均退出 `0`，取证原始行：

```text
fixed commit=803c1fbe5cfad56a2f91cffe2fe59e33d26c43db tree=c048d5212a7f55bae580ef299094adc139be245a
fixed archive=C:/tmp/t337-r3-replay.WWKJrqdC/tree
archive Git-blob SHA-1 checked=323 mismatches=0
```

### §33.3 固定树重生清单两次

从固定树复制交付目录到独立临时副本，调用树内生成器两次；比较生成文件、树内固定值、s117 原清单和 README 实算 SHA-256。不覆盖历史清单。实验负组与修前原始输出见[本轮报告](../../../_round_report_T337-R3.md)。

```bash
T337_DROP_README=0 python -I -B -X utf8 - "$fixed/qa/mk_fingerprints.py" "$fixed" <<'PY'
import hashlib, json, os, shutil, subprocess, sys, tempfile
from pathlib import Path
from collections import Counter
rel = Path('handoff/inbox/NATIVE-337')
generator = Path(sys.argv[1]).resolve(strict=True)
source = Path(sys.argv[2]) if len(sys.argv) > 2 else Path('.')
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
print(f'generator sha256={sha(generator)}', flush=True)
with tempfile.TemporaryDirectory(prefix='t337-r3-manifest-') as tmp:
    root = Path(tmp) / rel
    shutil.copytree(source/rel, root)
    published = root / 's121-fingerprints.json'
    pinned = published.read_bytes() if published.is_file() else None
    baseline = json.loads((root/'s117-fingerprints.json').read_bytes())
    layout = root/'code/README.md'
    if os.environ.get('T337_DROP_README') == '1':
        def hashes():
            return {p.relative_to(root).as_posix(): sha(p) for p in root.rglob('*') if p.is_file()}
        before = hashes(); layout.unlink(); after = hashes()
        assert {k for k in before.keys()|after.keys() if before.get(k)!=after.get(k)} == {'code/README.md'}
        print(f'isolated README: {before["code/README.md"]} -> <absent>', flush=True)
    results = []
    for attempt in (1, 2):
        run = subprocess.run([sys.executable, '-I', '-B', '-X', 'utf8', str(generator), '121'], cwd=tmp)
        print(f'run {attempt}: exit={run.returncode}', flush=True)
        run.check_returncode()
        results.append(published.read_bytes())
        print(f'run {attempt}: sha256={sha(published)}', flush=True)
    generated = json.loads(results[-1])
    added = sorted(generated.keys()-baseline.keys())
    removed = sorted(baseline.keys()-generated.keys())
    changed = sorted(k for k in generated.keys() & baseline.keys() if generated[k]!=baseline[k])
    invalid = sorted(k for k,v in generated.items() if not (root/k).is_file() or sha(root/k)!=v)
    print(f's117: entries={len(baseline)} sha256={sha(root/"s117-fingerprints.json")}')
    print(f's121: entries={len(generated)} dirs={dict(sorted(Counter(k.split("/")[0] if "/" in k else "(root)" for k in generated).items()))}')
    print(f'added={added} removed={removed} changed={changed} hash_mismatches={invalid}')
    print('README file='+ (sha(layout) if layout.is_file() else '<absent>') + ' manifest=' + generated.get('code/README.md','<absent>'))
    same = results[0]==results[1]
    print(f'repeat bytes identical={same}; matches checked-in manifest={None if pinned is None else pinned==results[1]}')
    ok = (same and added==['code/README.md'] and not (removed or changed or invalid) and layout.is_file()
          and generated['code/README.md']==sha(layout) and (pinned is None or pinned==results[1]))
    print('PASS: README is covered' if ok else 'FAIL: README is not covered by the intended fixed manifest')
    sys.exit(0 if ok else 1)
PY
rc=$?; printf 'manifest check exit=%s\n' "$rc"; test "$rc" -eq 0
```

```text
generator sha256=d8d048081a41d276ff98a910f9729bd8d3c2ba6b6540ed80df100d5f1c81f04c
fingerprints 110 -> handoff\inbox\NATIVE-337\s121-fingerprints.json
run 1: exit=0
run 1: sha256=100b999b142e8d5950145e42ca045deb6d62891efb8a08ae41f66dd22b821cc9
fingerprints 110 -> handoff\inbox\NATIVE-337\s121-fingerprints.json
run 2: exit=0
run 2: sha256=100b999b142e8d5950145e42ca045deb6d62891efb8a08ae41f66dd22b821cc9
s117: entries=109 sha256=4b01f6046cbb6d8f5e7d606e393a8ed217fd417562c7f3bb9d10e3b4c3995e9e
s121: entries=110 dirs={'(root)': 34, 'code': 31, 'work': 45}
added=['code/README.md'] removed=[] changed=[] hash_mismatches=[]
README file=60045ac5d600fb350f81ac26a96870de9358428e4656727ee2e881329b71332f manifest=60045ac5d600fb350f81ac26a96870de9358428e4656727ee2e881329b71332f
repeat bytes identical=True; matches checked-in manifest=True
PASS: README is covered
manifest check exit=0
```

### §33.4 原件覆盖、listing、部署绑定

```bash
python -I -B -X utf8 "$fixed/handoff/assignments/check-native-coverage.py" NATIVE-337 --original "$fixed/_t13/orig/FindComponent.dll" --submission "$fixed/handoff/inbox/NATIVE-337"
rc=$?; printf 'coverage exit=%s\n' "$rc"; test "$rc" -eq 2
python -I -B -X utf8 "$fixed/tool/s117_verify.py" --folder "$fixed/handoff/inbox/NATIVE-337" --binary "$fixed/_t13/orig/FindComponent.dll" --listing --signature
rc=$?; printf 's117 exit=%s\n' "$rc"; test "$rc" -eq 0
pwsh -NoProfile -NonInteractive -File "$fixed/tool/t337_r1_binding.ps1" -Folder "$fixed/handoff/inbox/NATIVE-337"
rc=$?; printf 'binding exit=%s\n' "$rc"; test "$rc" -eq 2
```

```text
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
coverage exit=2
listing-check: sites=2 conflicts=0
signature-check: conflicts=0
s117 exit=0
```

部署绑定原始输出中 `OK` 比较的是附件与表的声明；没有部署 PE 实测行。完整 stdout 见[本轮报告](../../../_round_report_T337-R3.md) §4。

```text
CODEBASE resolved=C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\AspenTech.AspenPlus.WpfFindComponent.dll
待核 CodeBase.PE TypeDef/InterfaceImpl/MethodDef cannot be verified: Could not find a part of the path 'C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\AspenTech.AspenPlus.WpfFindComponent.dll'.
binding-check: conflicts=0 pending=1
binding exit=2
```

### §33.5 树内 QA gate

```bash
PYTHONPATH='' PYTHONSAFEPATH=1 PYTHONUTF8=1 PYTHONNOUSERSITE=1 python -I -B -X utf8 - "$fixed" <<'PY'
from pathlib import Path
import os, runpy, sys
root = Path(sys.argv[1]); qa = root/'_t14/qa/93bf962c/qa'
sys.path.insert(0,str(qa))
sys.argv = [str(qa/'gate.py'), '--task','NATIVE-337','--item-dir',str(root/'handoff/inbox/NATIVE-337'),
            '--original',str(root/'_t13/orig/FindComponent.dll'),
            '--l1-path',str(root/'handoff/assignments/check-native-coverage.py')]
os.environ.pop('DSH_QA_DEBUG',None)
runpy.run_path(sys.argv[0],run_name='__main__')
PY
rc=$?; printf 'qa gate exit=%s\n' "$rc"; test "$rc" -eq 2
```

原始 stdout（`stats:` 行由 gate 自身限宽，保留原样）：

```text
l1 pin_ok=True exit=2 :: checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
l2 omitted-sites            l1_covers=no      inputs=363   status=pass           defects=0   advisory=0  
       stats: {"native_expected": 363, "native_missing": 0, "prefixed_thunks": 10, "sources": {"native": {"expected": 363, "missing": 0, "prefixed": 10}}, "source":
l2 stale-metrics            l1_covers=no      inputs=10    status=pass           defects=0   advisory=0  
       stats: {"numeric_keys": 10}
l2 row-linkage              l1_covers=partial inputs=11    status=pass           defects=0   advisory=0  
       stats: {"appendix_files": 11}
l2 fingerprint-pathset      l1_covers=no      inputs=110   status=pass           defects=0   advisory=0  
       stats: {"fingerprint_files": 1, "previous_tables": 12, "declared_paths": 110, "with_prefix": 76, "top_level": 34, "receipt_rows": 0, "shrank_paths": 0}
l2 unresolved-no-recovery   l1_covers=no      inputs=112   status=pass           defects=0   advisory=0  
       stats: {"unresolved_rows": 112, "distinct_notes": 101}
l2 symbol-substring         l1_covers=partial inputs=684   status=pass           defects=0   advisory=0  
       stats: {"rows": 684}
l2 wrong-symbol             l1_covers=no      inputs=684   status=pass           defects=0   advisory=0  
       stats: {"iat_dlls": 11, "rows": 684}
l2 byte-mismatch            l1_covers=partial inputs=5055  status=pass           defects=0   advisory=0  
       stats: {"instructions_checked": 5055}
l2 access-flags             l1_covers=no      inputs=0     status=not-applicable defects=0   advisory=0  
       stats: {"skipped": "no CLI metadata (native-only image)"}
l2 clause-semantics         l1_covers=no      inputs=0     status=not-applicable defects=0   advisory=0  
       stats: {"skipped": "no EH clauses decoded from the original"}
l2 eh-boundary              l1_covers=no      inputs=0     status=not-applicable defects=0   advisory=0  
       stats: {"boundary_tables": 0, "rows_checked": 0}
l2 det_access_prose         l1_covers=no      inputs=33    status=pass           defects=0   advisory=0  
       stats: {"documents_checked": 33, "mask": "0..6 MemberAccessMask"}
l2 truncated-hash           l1_covers=no      inputs=16    status=pass           defects=0   advisory=0  
       stats: {"files_scanned": 16}
l2 rebuild-semantics        l1_covers=no      inputs=6083  status=pass           defects=0   advisory=0  
       stats: {"libs": {"capstone": "5.0.7 at capstone", "keystone": "0.9.2", "capstone_path": "C:\\tmp\\t337-r3-replay.WWKJrqdC\\tree\\.local\\pylibs\\capstone\\__
readback: path=calls.csv algo=sha256 value=e473712f657c9b1a
readback: path=coverage.csv algo=sha256 value=3afe1c2a87c9e70c
readback: path=metrics.json algo=sha256 value=72515d6a0d747a62
units: pass=11 fail=0 not-applicable=3 error=0
exit: 2
qa gate exit=2
```

### §33.6 保留回归

从同一证据提交读 R2 §2–§4 命令，在临时副本复跑。C 两侧均待核；A/B/D 夹具配对分别 `0→2`、`0→2`、`0→3`；s117 和历史拒绝脚本定位合计 19 项，两个等价布局通过。完整原始输出及各组前后哈希见[本轮报告](../../../_round_report_T337-R3.md) §5；这些夹具不是实际部署件。

```bash
export PYTHONPATH='' PYTHONSAFEPATH=1 PYTHONUTF8=1 PYTHONNOUSERSITE=1
python -I -B -X utf8 - "$fixed" <<'PY'
import os, re, shutil, subprocess, sys, tempfile
from pathlib import Path
fixed=Path(sys.argv[1]); dll=Path('_t13/orig/FindComponent.dll'); bash=shutil.which('bash')
assert bash
report=(fixed/'_round_report_T337-R2.md').read_text(encoding='utf-8')
with tempfile.TemporaryDirectory(prefix='t337-r3-regressions-') as tmp:
    run=Path(tmp)
    for name in ('tool','handoff/inbox/NATIVE-337'):
        shutil.copytree(fixed/name,run/name)
    (run/dll).parent.mkdir(parents=True); shutil.copyfile(fixed/dll,run/dll)
    for section,title in ((2,'binding C'),(3,'binding A/B/D'),(4,'s117 and history')):
        _,body=report.split(f'\n## {section}. ',1)
        command=re.search(r'^```bash\n(.*?)^```$',body,re.M|re.S)[1]
        print(f'[{title}]',flush=True)
        r=subprocess.run([bash,'--noprofile','--norc','-s'],input=command.encode('utf-8'),cwd=run,env={**os.environ,'BASH_ENV':''})
        print(f'{title} replay exit={r.returncode}',flush=True); r.check_returncode()
PY
rc=$?; printf 'historical replay exit=%s\n' "$rc"; test "$rc" -eq 0
```

若退回，请给出具体脚本与函数/字段、实测与期望差异、最小输入和期望非零退出条件。上游复核状态待核。
