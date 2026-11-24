# NATIVE-340 S113 提交回执 · T340-R1

比对基准：本地 `../g340` 的 `tietoumiao/native-340-s33` @ `db209d73e787346373ec3a4c156eceed864f6f70`。本轮文件只在工作副本中；没有声称该提交包含 S113，也没有生成或推送新提交。以下命令从 **当前交付工作副本根目录**在 Git Bash 运行；`exit=` 是紧接进程记录的退出码，`child_exit=` 是包装器捕获的脚本退出码。

## 1. 数据源 schema

```bash
python -I -B -X utf8 - <<'PY'
import csv,json
from pathlib import Path
u=Path('handoff/inbox/NATIVE-340')
for name in ('calls.csv','coverage.csv','native-functions.csv','code/s89-il-digests.csv'):
    with (u/name).open(encoding='utf-8-sig',newline='') as f: print(name,csv.DictReader(f).fieldnames)
for name in ('code/s29-fingerprints.json','code/s109-fingerprints.json'):
    d=json.loads((u/name).read_bytes()); print(name, list(d) if 'files' in d else 'flat path -> SHA-256', len(d.get('files',d)))
d=json.loads(Path('../../_t14/layout-baseline-38b6814d.json').read_bytes()); print('layout keys:', list(d['layout'][0]))
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
calls.csv ['kind', 'caller', 'callee', 'class', 'listing', 'note']
coverage.csv ['kind', 'key', 'state', 'first_bytes', 'listing', 'source', 'note']
native-functions.csv ['rva', 'name']
code/s89-il-digests.csv ['row', 'token', 'name', 'rva', 'il_len', 'sha256']
code/s29-fingerprints.json flat path -> SHA-256 102
code/s109-fingerprints.json ['base_head', 'count', 'files'] 155
layout keys: ['table', 'column', 'width', 'rule', 'row_size', 'rows']
exit=0
```

下文 `U` 表示 `handoff/inbox/NATIVE-340`，`DLL` 表示 `_t13/orig/WrapSaveMergeNNFiles.dll`；命令均写实际路径，不依赖这两个简写。站点脚本使用 `native-functions.csv` 的起点作归类；该表没有结束列，不把其归类当作 ASM 真实区间的证据。

## 2. 逐脚本命令与实际输出

### `tool/cli_tables.py` — 解析库

输入：DLL 的 CLI 元数据；库无 CLI，通过 `read()` 取数并打印 `ImplMap.MemberForwarded` 布局。

```bash
python -I -B -X utf8 - <<'PY'
import struct, sys
from pathlib import Path
sys.path.insert(0, 'tool')
import cli_tables as c
from pe_reader import PE
d = Path('_t13/orig/WrapSaveMergeNNFiles.dll').read_bytes()
p = PE(d); off = p.filepos(struct.unpack_from('<I', d, p.filepos(p.directory(14)[0])+8)[0]); r = c.read(d, off)
print('stream=%s columns=%d' % (r['stream'], len(r['layout'])))
print(next(x for x in r['layout'] if (x['table'], x['column']) == ('ImplMap', 'MemberForwarded')))
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
stream=#~ columns=85
{'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 1 bits, max rows 698 < 2**15 -> 2', 'row_size': 8, 'rows': 15}
exit=0
```

### `tool/s101_width_fixtures.py` — 四个合成 `#~` 夹具

输入：脚本内 A/B/C/D 行数与布局期望、`tool/cli_tables.py`。`NEGATIVE` 是检测到预期反例，不是脚本失败。

```bash
python -I -B -X utf8 "tool/s101_width_fixtures.py"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
fixture A: MemberRefParent=2 MethodDefOrRef=2
fixture B: MemberRefParent=4 MethodDefOrRef=4
fixture C: MemberRefParent=4 MethodDefOrRef=2
fixture D: MemberRefParent=4 MethodDefOrRef=2
NEGATIVE detected: MemberRefParent expected 4 got 2
NEGATIVE(D) detected: MemberRefParent expected 4 got 2
width-fixtures: cases=4 failures=0
exit=0
```

B/D 反例各起一进程，对等字节的独立输入副本只改 `coded_width`；宽度变化，夹具字节不变。

```bash
python -I -B -X utf8 - <<'PY'
import hashlib, importlib.util, subprocess, sys
from pathlib import Path
for tag, refs, defs in [('B',8192,32768),('D',100,8192)]:
    print(f'fixture {tag}',flush=True)
    subprocess.run([sys.executable,'-I','-B','-X','utf8','-c', '''import hashlib,sys
sys.path.insert(0,'tool')
from s101_width_fixtures import build, load
n,m=map(int,sys.argv[1:]); ct=load(); base=build(n,m); broken=bytes(bytearray(base))
f=lambda b:dict(ct.layout_for(b,0)['columns'][10])['Class']
normal=f(base); ct.coded_width=lambda *args:2; variant=f(broken)
sha=lambda b:hashlib.sha256(b).hexdigest()
print(f'input_before={sha(base)} input_after={sha(broken)} width={normal}->{variant}')
raise SystemExit((normal,variant)!=(4,2))''',str(refs),str(defs)],check=True)
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
fixture B
input_before=53ae739750c6b89fbdf36d1fb8db0b3cd8d53eef239dad4bd96a143d35bb7da9 input_after=53ae739750c6b89fbdf36d1fb8db0b3cd8d53eef239dad4bd96a143d35bb7da9 width=4->2
fixture D
input_before=fef1d76bd87a57eac306d0bc7fe3ed84166a2ac6f54c2131d714ea7d5367381c input_after=fef1d76bd87a57eac306d0bc7fe3ed84166a2ac6f54c2131d714ea7d5367381c width=4->2
exit=0
```

### `tool/s101_layout_check.py` — 1c/1d 布局逐键比对

输入：DLL、`tool/cli_tables.py`、本地旧基线 `../../_t14/layout-baseline-38b6814d.json`。1c 零差异；1d 一处规则字段差异，宽度仍为 2，**保留退出 1**。

```bash
python -I -B -X utf8 "tool/s101_layout_check.py" --baseline "../../_t14/layout-baseline-38b6814d.json" --original "_t13/orig/WrapSaveMergeNNFiles.dll"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
1d MISMATCH ImplMap.MemberForwarded baseline={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 2 bits, max rows 698 < 2**14 -> 2', 'row_size': 8, 'rows': 15} new={'table': 'ImplMap', 'column': 'MemberForwarded', 'width': 2, 'rule': 'coded tag 1 bits, max rows 698 < 2**15 -> 2', 'row_size': 8, 'rows': 15}
layout-check: columns=85 1c_diffs=0 1d_diffs=1
exit=1
```

### `tool/s101_layout_baseline.py` — 旧布局生成器离线重放

输入：同一 DLL、上述旧基线和同目录缓存的 `old_head/cli_tables_38b6814d.py`。用已比对 SHA-256 的缓存字节回应生成器的两个 `gh.call`，不联网，不覆盖基线。新旧 JSON 仅 `command` 字段不同；旧解析器与远端提交的独立绑定 **待核**，离线重放不证明其远端来源。

```bash
python -I -B -X utf8 - <<'PY'
import base64, hashlib, json, shutil, subprocess, sys, tempfile
from pathlib import Path
cache = Path('../../_t14'); old = (cache/'old_head/cli_tables_38b6814d.py').read_bytes()
fixed = json.loads((cache/'layout-baseline-38b6814d.json').read_bytes())
dll = Path('_t13/orig/WrapSaveMergeNNFiles.dll').resolve(); sha = lambda b: hashlib.sha256(b).hexdigest()
assert sha(old) == fixed['source_sha256'] and sha(dll.read_bytes()) == fixed['original_sha256']
shim = '''import base64,runpy,sys,types
from pathlib import Path
source, head, dll = sys.argv[1:]
gh = types.ModuleType('gh'); gh.REPO = 'offline'; raw = Path(source).read_bytes()
def call(method, path):
    assert method == 'GET'
    if path == f'/repos/offline/git/trees/{head}?recursive=1':
        return {'tree':[{'type':'blob','path':'tool/cli_tables.py','sha':'cached-parser'}]}
    if path == '/repos/offline/git/blobs/cached-parser':
        return {'content':base64.b64encode(raw)}
    raise AssertionError(path)
gh.call = call; sys.modules['gh'] = gh
sys.argv = ['tool/s101_layout_baseline.py','--head',head,'--out','baseline.json','--original',dll]
runpy.run_path(sys.argv[0],run_name='__main__')'''
with tempfile.TemporaryDirectory(prefix='t340-r1-baseline-') as tmp:
    root = Path(tmp); (root/'tool').mkdir()
    for f in ('s101_layout_baseline.py', 'pe_reader.py'): shutil.copyfile(Path('tool')/f,root/'tool'/f)
    print('cached source sha256='+sha(old),flush=True)
    rc = subprocess.run([sys.executable,'-I','-B','-X','utf8','-c',shim,str((cache/'old_head/cli_tables_38b6814d.py').resolve()),fixed['head'],str(dll)],cwd=root).returncode
    print(f'child_exit={rc}')
    if rc: raise SystemExit(rc)
    new = json.loads((root/'baseline.json').read_bytes())
    diff = sorted(k for k in fixed.keys()|new.keys() if fixed.get(k)!=new.get(k))
    print('layout_replay: differing_keys='+str(diff))
    raise SystemExit(diff != ['command'])
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
cached source sha256=3ca027e7ce2187e5537d2540efbbf7fb9e32450b2849eb95ed9779f4a864fed1
baseline: head 38b6814d columns 85 stream #~ heap 0x00 -> baseline.json
child_exit=0
layout_replay: differing_keys=['command']
exit=0
```

### `tool/s93-width-controls.py` — 列规格与邻列偏移

输入：本地 `tool/cli_tables.py` 的列规格、脚本内 `EXPECT` 与 `PAIRS`。这是规格/偏移测试，不是原件字段值断言。

```bash
python -I -B -X utf8 "tool/s93-width-controls.py" "."; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
width-controls: pairs=3 mismatches=0
exit=0
```

### `tool/s97-site-owners.py` — 站点归类

输入：`U/code/native.asm`、`U/native-functions.csv`、`U/calls.csv`。该脚本不读 DLL。

```bash
python -I -B -X utf8 "tool/s97-site-owners.py" "."; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
attribution: checked=67 mismatches=0
exit=0
```

### `tool/s105-site-evidence.py` — 站点证据比对

输入：上述 ASM 和两个 CSV、DLL、`../../.local/pylibs` 的 `pefile` 与 `tool/pe_reader.py`。此脚本的 67 条结果不代替完整路径或严格符号匹配的验证。

```bash
python -I -B -X utf8 -c 'import runpy,sys; sys.path.append(sys.argv.pop(1)); del sys.argv[0]; runpy.run_path(sys.argv[0],run_name="__main__")' "../../.local/pylibs" "tool/s105-site-evidence.py" "." --original "_t13/orig/WrapSaveMergeNNFiles.dll"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
site-evidence: checked=67 mismatches=0
exit=0
```

### `tool/s109-l1509-check.py` — 显示位移、槽与符号

输入：`U/code/native.asm` 第 1509 行、`U/calls.csv` 的关联行、DLL、`pefile` 与 `tool/pe_reader.py`。

```bash
python -I -B -X utf8 -c 'import runpy,sys; sys.path.append(sys.argv.pop(1)); del sys.argv[0]; runpy.run_path(sys.argv[0],run_name="__main__")' "../../.local/pylibs" "tool/s109-l1509-check.py" "." --original "_t13/orig/WrapSaveMergeNNFiles.dll"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
L1509 site=0x4711 disp=0x18E9 slot=0x6000 symbol=KERNEL32.dll!QueryPerformanceCounter
l1509-check: problems=0
exit=0
```

反例分别从原始输入另建临时副本，改一个显示字段，不用脚本的 `--mutate` 开关。不改 DLL。

```bash
python -I -B -X utf8 - <<'PY'
import csv, hashlib, subprocess, sys, tempfile
from pathlib import Path
unit = Path('handoff/inbox/NATIVE-340')
inputs = {p: (unit / p).read_bytes() for p in ('code/native.asm', 'calls.csv')}
dll = Path('_t13/orig/WrapSaveMergeNNFiles.dll')
lib = str(Path('../../.local/pylibs').resolve())
launcher = 'import runpy,sys; sys.path.append(sys.argv.pop(1)); del sys.argv[0]; runpy.run_path(sys.argv[0],run_name="__main__")'
cmd = [sys.executable, '-I', '-B', '-X', 'utf8', '-c', launcher, lib, 'tool/s109-l1509-check.py']
sha = lambda b: hashlib.sha256(b).hexdigest()
assert {'listing', 'callee', 'note'} <= set(csv.DictReader(inputs['calls.csv'].decode('utf-8-sig').splitlines()).fieldnames)
expect = [('disp','code/native.asm',b'[RIP+0x18E9]',b'[RIP+0x18EA]',b'MISMATCH disp:'), ('symbol','calls.csv',b'KERNEL32.dll!QueryPerformanceCounter',b'KERNEL32.dll!QueryPerformanceCounterX',b'MISMATCH symbol:')]
print('original sha256='+sha(dll.read_bytes()),flush=True)
for tag, rel, old, new, marker in expect:
    with tempfile.TemporaryDirectory(prefix='t340-r1-') as tmp:
        root = Path(tmp); cand = root / unit; (cand/'code').mkdir(parents=True)
        for p, b in inputs.items(): (cand / p).write_bytes(b)
        path = cand / rel; before = path.read_bytes(); lines = before.splitlines(keepends=True)
        idx = 1508 if tag == 'disp' else next(i for i, line in enumerate(lines) if b'code/native.asm#L1509' in line and old in line)
        assert old in lines[idx]; lines[idx] = lines[idx].replace(old,new,1); path.write_bytes(b''.join(lines))
        after = path.read_bytes(); changed = sorted(p for p,b in inputs.items() if (cand/p).read_bytes()!=b)
        print(f'{tag}: {rel} line={idx+1} before={sha(before)} after={sha(after)} changed={changed}',flush=True)
        r = subprocess.run([*cmd,str(root),'--original',str(dll)],capture_output=True,check=False)
        sys.stdout.buffer.write(r.stdout); sys.stderr.buffer.write(r.stderr)
        print(f'child_exit={r.returncode}',flush=True)
        assert changed == [rel] and r.returncode == 1 and marker in r.stdout
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
original sha256=869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
disp: code/native.asm line=1509 before=082c73d29348a04571ad59636cc6b6c385522a8f3238d4278b73587cf599b620 after=5161835d7c9d3ed9f79e4ef447fa8bbe848c2ee6411e2cd243951f19629f2444 changed=['code/native.asm']
L1509 site=0x4711 disp=0x18E9 slot=0x6000 symbol=KERNEL32.dll!QueryPerformanceCounter
MISMATCH disp: asm 0x18EA != original 0x18E9
l1509-check: problems=1
child_exit=1
symbol: calls.csv line=562 before=0356c8a3dc5fa3b5d3233ce0444e27bf261f14995834ec751fc2f1bf5917e7e5 after=703d26f825066c690b91bd911c8a8888457fbfaad823bbd1858f2109e0205602 changed=['calls.csv']
L1509 site=0x4711 disp=0x18E9 slot=0x6000 symbol=KERNEL32.dll!QueryPerformanceCounter
MISMATCH symbol: row callee 'KERNEL32.dll!QueryPerformanceCounterX' != KERNEL32.dll!QueryPerformanceCounter
l1509-check: problems=1
child_exit=1
exit=0
```

### `tool/s109-read-mutate.py` — `read()` 行步长取值路径

输入：独立的 DLL 临时副本和交付头匹配的 `cli_tables.py`。唯一变体是 `read()` 的 `_mutate_row_size`；原件哈希不动。此脚本定位五个字段的变化，不是五个正常字段的独立真值断言。

```bash
python -I -B -X utf8 - <<'PY'
import hashlib, shutil, subprocess, sys, tempfile
from pathlib import Path
original = Path('_t13/orig/WrapSaveMergeNNFiles.dll')
script = Path('tool/s109-read-mutate.py').resolve()
with tempfile.TemporaryDirectory(prefix='t340-r1-read-') as d:
    p = Path(d)/original; p.parent.mkdir(parents=True); shutil.copyfile(original,p)
    sha = lambda: hashlib.sha256(p.read_bytes()).hexdigest(); before = sha()
    print('input_before='+before,flush=True)
    r = subprocess.run([sys.executable,'-I','-B','-X','utf8',str(script)],cwd=d)
    print('input_after='+sha()); print(f'child_exit={r.returncode}'); assert before == sha()
    raise SystemExit(r.returncode)
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
input_before=869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
LOCATED MemberRef[3].Class: normal=41 mutated=2763
LOCATED MemberRef[3].Name: normal='.ctor' mutated='bute'
LOCATED MethodDef[5].Flags: normal=19 mutated=4300
LOCATED CustomAttribute[7].Type: normal=107 mutated=35
LOCATED TypeDef[9].TypeName: normal='_SID_NAME_USE' mutated='vc.cppcli.attributes.?A0x12ee35f2'
read-mutate: fields=5 changed=5
input_after=869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec
child_exit=0
exit=0
```

### `tool/verify_il_digests.py` — IL 摘要逐 token 复验

输入：DLL、`U/code/s89-il-digests.csv`、`tool/pe_reader.py`、`tool/md_reader.py`、`tool/method_body.py`。

```bash
python -I -B -X utf8 "tool/verify_il_digests.py" --binary "_t13/orig/WrapSaveMergeNNFiles.dll" --table "handoff/inbox/NATIVE-340/code/s89-il-digests.csv"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
checked 167 rows, mismatches 0
exit=0
```

### 脚本来源逐项核对

命令输出 `path bytes SHA-256 MATCH/DIFF`。前 14 行均用本地字节重新计算 Git blob ID，并与固定提交的树条目逐个相比；额外的 `s113*.py` 仅列适用范围，不当作本任务运行记录。

```bash
GIT_NO_LAZY_FETCH=1 GIT_ALLOW_PROTOCOL= python -I -B -X utf8 - <<'PY'
import ast,hashlib,subprocess
from pathlib import Path
repo='../g340'; head='db209d73e787346373ec3a4c156eceed864f6f70'; names=('cli_tables','s101_width_fixtures','s101_layout_check','s101_layout_baseline','s93-width-controls','s97-site-owners','s105-site-evidence','s109-l1509-check','s109-read-mutate','verify_il_digests','gen_fingerprints_340','pe_reader','md_reader','method_body')
paths=[f'tool/{n}.py' for n in names]
raw=subprocess.check_output(['git','-C',repo,'ls-tree','-rz',head,'--',*paths]).decode()
entries={p:meta.split()[2] for row in raw.split('\0') if row for meta,p in [row.split('\t',1)]}
for p in paths:
 b=Path(p).read_bytes(); oid=hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
 print(p,len(b),hashlib.sha256(b).hexdigest(),'MATCH' if oid==entries.get(p) else f'DIFF {oid} != {entries.get(p)}')
for p in sorted(Path('tool').glob('s113*.py')):
 print(p.as_posix(), sorted({t.value for t in ast.walk(ast.parse(p.read_bytes())) if isinstance(t,ast.Constant) and isinstance(t.value,str) and ('NATIVE-337' in t.value or 'FindComponent.dll' in t.value)}))
PY
```

```text
tool/cli_tables.py 16051 6c15fc62f524ed30cbdadacc1070ad0bb2fe5c20fd7dcf923641cf2475fc9959 MATCH
tool/s101_width_fixtures.py 3215 85145a458b4c4f1c9ff8dc3d0eeadadca2d81b5b2254e27af90027958b095a95 MATCH
tool/s101_layout_check.py 1949 35835a05362b4ba5b851970bb0ef6f95e86dcba35b83ddec7238a4054353b523 MATCH
tool/s101_layout_baseline.py 2777 5492909e8428993e051ede50e97ccab968420aebc8aeb281e3f80bc445560e72 MATCH
tool/s93-width-controls.py 3134 8374898c760cce153ca2b5ab541a6a261c3a9d848ae230544dfb79aa4635e551 MATCH
tool/s97-site-owners.py 2475 3dc305a25b38bde1689d6803476c45a73d44c9dff1d1b199a70b3e74a926ffce MATCH
tool/s105-site-evidence.py 3610 600975699de15c7ff150a336ac792726c40383e5229f835acdb727dd0e68c1ed MATCH
tool/s109-l1509-check.py 3647 9c9f5927e14d8949ce297830ef88931a5c5f28398745bee0531fc602fce1e41e MATCH
tool/s109-read-mutate.py 1472 fb24bc6697bc6891f68fb33d46b77328e8df07b897525fb3bb06f77830295b5c MATCH
tool/verify_il_digests.py 1958 3693094d52e76e40ba43aee56cbb6d379defde219a43ce10d3a27c654a25aec6 MATCH
tool/gen_fingerprints_340.py 2966 5188fa302d3cc798e4e7b90f63ebee6c06fa7c2a6990b91577932a5f621a8ef4 MATCH
tool/pe_reader.py 5778 5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367 MATCH
tool/md_reader.py 3139 e2f16c8bfe0bfb77766a4c4d19f59561d4d2b8bbee751565341ef0c80ecfc2b4 MATCH
tool/method_body.py 15040 02b89ef611474f7fdda0a2f75fb10587e14a643d93b32de239a8e7b0bd3b00f3 MATCH
tool/s113_substring_audit.py []
tool/s113_variants.py ['_t13/orig/FindComponent.dll', 'handoff/inbox/NATIVE-337']
tool/s113_verify.py ['_t13/orig/FindComponent.dll', 'handoff/inbox/NATIVE-337']
```

## 3. QA 与 L1：含空格路径已加引号

输入：本轮 `U`、DLL、本地 `../../_t14/qa/93bf962c` 缓存及 `../../.local/pylibs`，L1 为 `../../out/localrepo3/handoff/assignments/check-native-coverage.py`。执行时核对缓存目录 31 个文件的合成 SHA-256 和 L1 的完整 SHA-256，固定 L2 导入为该缓存，避免加载工作区外层的同名 `qa` 检测器。缓存缺上游 `MANIFEST`，远端 pin 对照 **待核**。

```bash
PYTHONPATH="$(pwd -W)/../../.local/pylibs" PYTHONSAFEPATH=1 PYTHONUTF8=1 python -I -B -X utf8 -c 'import hashlib,pathlib,sys; q=pathlib.Path(sys.argv[1]).resolve(); l1=pathlib.Path(sys.argv[2]).resolve(); sha=lambda b:hashlib.sha256(b).hexdigest(); assert sha(l1.read_bytes())=="27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"; h=hashlib.sha256(); [h.update(p.name.encode()+b"\0"+hashlib.sha256(p.read_bytes()).digest()) for p in sorted((q/"qa").iterdir()) if p.is_file()]; assert h.hexdigest()=="d0ecb9fea2e9356b3981204865f4cc7748cb77f280b07d08f71416761030ac62"; sys.path.insert(0,str(q)); from qa import gate; sys.path.remove(str(pathlib.Path(gate.ROOT)/"qa")); sys.path.insert(0,str(q/"qa")); raise SystemExit(gate.main(["--l1-path",str(l1),*sys.argv[3:]]))' "$(pwd -W)/../../_t14/qa/93bf962c" "$(pwd -W)/../../out/localrepo3/handoff/assignments/check-native-coverage.py" --task "NATIVE-340" --item-dir "$(pwd -W)/handoff/inbox/NATIVE-340" --original "$(pwd -W)/_t13/orig/WrapSaveMergeNNFiles.dll"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
l1 pin_ok=True exit=2 :: checked 1105 coverage rows, 354 tool-native entries, 578 call records, 0 declared gaps
l2 omitted-sites            l1_covers=no      inputs=319   status=pass           defects=0   advisory=0  
       stats: {"native_expected": 67, "native_missing": 0, "prefixed_thunks": 2, "sources": {"native": {"expected": 67, "missing": 0, "prefixed": 2}, "vtablefixups"
l2 stale-metrics            l1_covers=no      inputs=10    status=pass           defects=0   advisory=0  
       stats: {"numeric_keys": 10}
l2 row-linkage              l1_covers=partial inputs=10    status=pass           defects=0   advisory=0  
       stats: {"appendix_files": 10}
l2 fingerprint-pathset      l1_covers=no      inputs=154   status=pass           defects=0   advisory=0  
       stats: {"fingerprint_files": 1, "previous_tables": 22, "declared_paths": 154, "with_prefix": 95, "top_level": 59, "receipt_rows": 0, "shrank_paths": 0}
l2 unresolved-no-recovery   l1_covers=no      inputs=28    status=pass           defects=0   advisory=0  
       stats: {"unresolved_rows": 28, "distinct_notes": 19}
l2 symbol-substring         l1_covers=partial inputs=578   status=pass           defects=0   advisory=0  
       stats: {"rows": 578}
l2 wrong-symbol             l1_covers=no      inputs=578   status=pass           defects=0   advisory=0  
       stats: {"iat_dlls": 6, "rows": 578}
l2 byte-mismatch            l1_covers=partial inputs=1501  status=pass           defects=0   advisory=0  
       stats: {"instructions_checked": 1501}
l2 access-flags             l1_covers=no      inputs=527   status=pass           defects=0   advisory=0  
       stats: {"method_access_tables": 5, "rows_checked": 334, "methods_in_original": 188}
l2 clause-semantics         l1_covers=no      inputs=35    status=pass           defects=0   advisory=0  
       stats: {"clause_tables": 1, "rows_checked": 35, "methods_with_eh": 25, "decode_errors": 0}
l2 eh-boundary              l1_covers=no      inputs=25    status=pass           defects=0   advisory=0  
       stats: {"boundary_tables": 1, "rows_checked": 25}
l2 det_access_prose         l1_covers=no      inputs=49    status=pass           defects=0   advisory=0  
       stats: {"documents_checked": 49, "mask": "0..6 MemberAccessMask"}
l2 truncated-hash           l1_covers=no      inputs=15    status=pass           defects=0   advisory=0  
       stats: {"files_scanned": 15}
l2 rebuild-semantics        l1_covers=no      inputs=6035  status=pass           defects=0   advisory=2  
       stats: {"libs": {"capstone": "5.0.7 at capstone", "keystone": "0.9.2", "capstone_path": "D:\\deepseekharness workspace\\_work\\wf-20261120-aspen-batch\\.loca
     - [advisory] rva=0x1756 :: cannot re-assemble 'jmp ptr [rax]': Invalid operand (KS_ERR_ASM_INVALIDOPERAND)
     - [advisory] rva=0x4349 :: cannot re-assemble 'jmp ptr [rsi]': Invalid operand (KS_ERR_ASM_INVALIDOPERAND)
readback: path=calls.csv algo=sha256 value=0356c8a3dc5fa3b5
readback: path=coverage.csv algo=sha256 value=fd5d2d3946b87611
readback: path=metrics.json algo=sha256 value=c2ced879dfdaa7e7
units: pass=14 fail=0 not-applicable=0 error=0
exit: 2
exit=2
```

QA 的 `154` 不是完整清单项数。逐项检查的 `156` 涵盖未进入 QA 路径统计的两个文件：

```bash
python -I -B -X utf8 - <<'PY'
import json,sys
from pathlib import Path
sys.path.insert(0,str(Path('../../_t14/qa/93bf962c/qa').resolve()))
from det_fingerprint_pathset import _declared_json
p=Path('handoff/inbox/NATIVE-340/code/s113-fingerprints.json'); doc=json.loads(p.read_bytes())
a=doc['files']; b=dict(_declared_json(doc))
print(f'manifest={len(a)} qa_declared={len(b)} qa_omits={sorted(a.keys()-b.keys())}')
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
manifest=156 qa_declared=154 qa_omits=['code/s73-il-bodies.bin', 'code/types.cs']
exit=0
```

单独复跑 L1，确认退出 `2` 来自检查程序，不是 argparse 参数错误：

```bash
PYTHONSAFEPATH=1 PYTHONUTF8=1 python -I -B -X utf8 "../../out/localrepo3/handoff/assignments/check-native-coverage.py" "NATIVE-340" --original "$(pwd -W)/_t13/orig/WrapSaveMergeNNFiles.dll" --submission "$(pwd -W)/handoff/inbox/NATIVE-340"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
checked 1105 coverage rows, 354 tool-native entries, 578 call records, 0 declared gaps
exit=2
```

L1 对仍有 `unresolved` 的交付使用退出 `2`（本地 L1 第 295 行）。按实际表头统计该类并重算 `metrics.json` 的三个摘要：

```bash
python -I -B -X utf8 - <<'PY'
import csv, hashlib, json
from collections import Counter
from pathlib import Path
u = Path('handoff/inbox/NATIVE-340'); m = json.loads((u/'metrics.json').read_bytes())
for k,p in (('calls_sha256','calls.csv'),('coverage_sha256','coverage.csv'),('native_functions_sha256','native-functions.csv')):
    h = hashlib.sha256((u/p).read_bytes()).hexdigest()
    print(k,h,h==m[k]); assert h==m[k]
with (u/'calls.csv').open(encoding='utf-8-sig', newline='') as f:
    r=csv.DictReader(f); assert 'class' in r.fieldnames; counts=Counter(row['class'] for row in r)
print(f'unresolved={counts["unresolved"]} metrics={m["unresolved"]}'); assert counts['unresolved']==m['unresolved']
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
calls_sha256 0356c8a3dc5fa3b5d3233ce0444e27bf261f14995834ec751fc2f1bf5917e7e5 True
coverage_sha256 fd5d2d3946b876117fd59fe7a91829730fdd9a19e7ed58fd69d7dc941a7885a0 True
native_functions_sha256 737e83da0c37379bb178b5920445a239e6d0ed757f465bd9581f681ff3548ccd True
unresolved=28 metrics=28
exit=0
```

## 4. 重算活动清单与逐项核对

- 上游扁平清单 [`code/s29-fingerprints.json`](code/s29-fingerprints.json)：102 项。不含 `fingerprints` 文件和开工/提交回执；重算与交付头的现有清单字节相同，不改写。
- 本轮清单 [`code/s113-fingerprints.json`](code/s113-fingerprints.json) 和[逐项索引](code/s113-fingerprints.md)：156 项。不含 `fingerprints` 文件；包含本回执。`base_head` 是比对基准，不是声称已经提交的 S113 头。
- 交付目录与基准头相比：196 → 199，只有 `s113-submission.md`、`code/s113-fingerprints.json`、`code/s113-fingerprints.md` 三个新增；没有删除或已有文件字节变化。
- 历史 `code/s109-fingerprints.json` 与基准头相比有一项内容差异：`s109-submission.md`，清单声明 `6b20a3486f45a0f6b976ef4c4db6621856b8315da3e0603a513644973e5885db`，头实际 `c7c07c6065375fb679a93a757191f9552cf3692f834e7fd22974162174b635f7`。历史清单保留；其声明所指旧 blob 字节未能回读，成因 **待核**，不回填推断。

### `tool/gen_fingerprints_340.py` — 临时目录重算

输入：最终 `U`、固定比对基准。临时生成两套清单与当轮 Markdown 索引，和此工作副本逐字节核对；不覆盖交付文件。

```bash
python -I -B -X utf8 - <<'PY'
import hashlib, json, subprocess, sys, tempfile
from pathlib import Path
head='db209d73e787346373ec3a4c156eceed864f6f70'
u=Path('handoff/inbox/NATIVE-340').resolve(); gen=Path('tool/gen_fingerprints_340.py').resolve()
with tempfile.TemporaryDirectory(prefix='t340-r1-manifests-') as tmp:
    for form, dest, extra in [('receipt','s29-fingerprints.json',[]),('round','s113-fingerprints.json',['--base-head',head,'--rules-out','s113-fingerprints.md'])]:
        r=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(gen),'--set',form,'--unit',str(u),'--out',dest,*extra],cwd=tmp)
        print(f'child_exit={r.returncode}'); assert r.returncode==0
        for name in [dest]+extra[3:]:
            a=(Path(tmp)/name).read_bytes(); b=(u/'code'/name).read_bytes()
            print(f'{name}: bytes_equal={a==b}'); assert a==b
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
receipt: 102 files -> s29-fingerprints.json
rules -> s113-fingerprints.md
round: 156 files -> s113-fingerprints.json
child_exit=0
s29-fingerprints.json: bytes_equal=True
child_exit=0
s113-fingerprints.json: bytes_equal=True
s113-fingerprints.md: bytes_equal=True
exit=0
```

### 从交付头逐项核对

下面同一条检查先跑红、定稿重算后再跑绿；[轮次报告](../../../_round_report_T340-R1.md)保留两段原始输出。Git 树路径及 blob ID 为主；只有本地字节重算的 Git blob SHA-1 命中头时才用本地字节计算该头的清单 SHA-256。若不命中则从本地 Git 对象读回，不以工作副本冒充头内字节。检查涵盖全部普通文件，包括 `.bin`，不限于 QA 探测器支持的扩展名。`DIFF` 的箭头为预期值 → 声明值。

```bash
GIT_NO_LAZY_FETCH=1 GIT_ALLOW_PROTOCOL= python -I -B -X utf8 - <<'PY'
from pathlib import Path
import hashlib, json, re, subprocess
u = Path('handoff/inbox/NATIVE-340'); head = 'db209d73e787346373ec3a4c156eceed864f6f70'
receipt = 's113-submission.md'; flat = 'code/s29-fingerprints.json'; prior = 'code/s109-fingerprints.json'; round_file = 'code/s113-fingerprints.json'; index = 'code/s113-fingerprints.md'
required = {receipt, round_file, index}
prefix = u.as_posix() + '/'
def git(*args): return subprocess.check_output(['git', '-C', '../g340', *args])
def sha(b): return hashlib.sha256(b).hexdigest()
def oid(b): return hashlib.sha1(b'blob ' + str(len(b)).encode() + b'\0' + b).hexdigest()
def choose(paths, receipts): return {p for p in paths if 'fingerprints' not in Path(p).name and (receipts or not any(t in Path(p).name for t in ('-started.md', '-submission.md')))}
def diff(label, want, got):
    missing = sorted(want.keys() - got.keys()); extra = sorted(got.keys() - want.keys()); changed = sorted(p for p in want.keys() & got.keys() if want[p] != got[p])
    print(f'{label}: expected={len(want)} actual={len(got)} missing={len(missing)} extra={len(extra)} changed={len(changed)}')
    for p in missing: print(f'  MISSING {p} {want[p]}')
    for p in extra: print(f'  EXTRA {p} {got[p]}')
    for p in changed: print(f'  DIFF {p} {want[p]} -> {got[p]}')
    return set(missing), set(extra), set(changed)
tracked = {}
for row in git('ls-tree', '-rz', head, '--', prefix).decode().split('\0'):
    if not row: continue
    meta, path = row.split('\t', 1); mode, kind, obj = meta.split()
    if kind == 'blob': tracked[path[len(prefix):]] = obj
local = {p.relative_to(u).as_posix(): p.read_bytes() for p in u.rglob('*') if p.is_file()}
print('HEAD', head)
base_delta = diff('HEAD -> local (Git blob SHA-1)', tracked, {p: oid(b) for p,b in local.items()})
def head_bytes(p):
    if p in local and oid(local[p]) == tracked[p]: return local[p]
    b = git('cat-file', 'blob', tracked[p]); assert oid(b) == tracked[p]; return b
head_sha = {p: sha(head_bytes(p)) for p in tracked}; disk_sha = {p: sha(b) for p,b in local.items()}
old = json.loads(head_bytes(prior))
print(f'S109 manifest: count={old["count"]} entries={len(old["files"])} base_head={old["base_head"]}')
diff('HEAD receipt manifest (SHA-256)', {p: head_sha[p] for p in choose(tracked, False)}, json.loads(head_bytes(flat)))
diff('HEAD S109 round manifest (SHA-256)', {p: head_sha[p] for p in choose(tracked, True)}, old['files'])
errors = [f'missing local {p}' for p in sorted(required - local.keys())]
if base_delta != (set(), required, set()): errors.append('unexpected HEAD-to-local delta')
for p, receipts in ((flat, False), (round_file, True)):
    if p not in local: continue
    doc = json.loads(local[p]); entries = doc['files'] if receipts else doc
    if receipts and (doc['count'] != len(entries) or doc['base_head'] != head): errors.append(f'metadata mismatch {p}')
    if any(diff(f'local {p} (SHA-256)', {p: disk_sha[p] for p in choose(local, receipts)}, entries)): errors.append(f'path/hash mismatch {p}')
if index in local and round_file in local:
    rows = re.findall(r'^\| `([^`]+)` \| `([\da-f]{64})` \|\r?$', local[index].decode(), re.M)
    if len(rows) != len(dict(rows)) or any(diff('local S113 Markdown index (SHA-256)', json.loads(local[round_file])['files'], dict(rows))): errors.append('index mismatch')
for error in errors: print(f'FAIL {error}')
print('S113 local acceptance:', 'FAIL' if errors else 'PASS')
raise SystemExit(bool(errors))
PY
rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc"); exit "$rc"
```

旧 blob 待核项可独立复查（单纯读本地对象，不触发懒加载）：

```bash
GIT_NO_LAZY_FETCH=1 GIT_ALLOW_PROTOCOL= git -C "../g340" cat-file -t "a1d9b0836836682e6f98d7d15c8e2a8a2416b2e1:handoff/inbox/NATIVE-340/s109-submission.md"; rc=$?; printf 'exit=%s\n' "$rc"; (exit "$rc")
```

```text
fatal: git cat-file: could not get object info
exit=128
```
