# -*- coding: utf-8 -*-
"""A4 计数推导：从台账 + main 树 + md 必填字段推导 functions 计数。只读输入，输出到 out/policies/。"""
import csv, json, re, os, collections, hashlib

WF = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))  # out/policies -> out
OUT = os.path.join(WF, 'policies')
MAN = os.path.join(WF, 'B2', 'manifest-b2.csv')
IDX = os.path.join(WF, 'tickets', 'remote_index.csv')
TREE = os.path.join(WF, 'tickets', 'tree_main.json')
MDROOT = os.path.join(WF, 'cache', 'repo_final')
CLR_L = os.path.join(WF, 'R1', 'ledger-clr.csv')
NAT_L = os.path.join(WF, 'R1N', 'ledger-native.csv')

def rows(p):
    with open(p, encoding='utf-8-sig', newline='') as f:
        return list(csv.DictReader(f))

man = rows(MAN); idx = rows(IDX)
clr_l = rows(CLR_L); nat_l = rows(NAT_L)
tree = json.load(open(TREE, encoding='utf-8'))
blobs = [e['path'] for e in tree['tree'] if e.get('type') == 'blob']
md_paths = sorted(p for p in blobs if p.startswith('analysis/20261120-batch-driver/') and p.endswith('.md'))

kinds = collections.Counter(r['kind'] for r in man)
status = collections.Counter(r['status'] for r in idx)
by_kind_status = collections.Counter((r['kind'], r['status']) for r in idx)
idx_md = {r['report_md']: r for r in idx}
manifest_by_key = {r['sha256']: r for r in man}

# 逐份 md 读必填字段（本地 main 镜像 out/cache/repo_final，字节与 GitHub main 一致）
RE_NA = re.compile(r'^\s*-\s*functions=N/A')
RE_NUM = re.compile(r'^\s*-\s*functions=(\d+)')
RE_ANY = re.compile(r'^\s*-\s*functions=(.*)$')
recs = []
for rel in md_paths:
    fp = os.path.join(MDROOT, rel.replace('/', os.sep))
    val, cls = None, 'missing_file'
    raw = b''
    if os.path.exists(fp):
        raw = open(fp, 'rb').read()
        txt = raw.decode('utf-8-sig', 'replace')
        for ln in txt.splitlines():
            m = RE_ANY.match(ln)
            if m:
                val = m.group(1).strip()
                cls = 'na' if RE_NA.match(ln) else ('numeric' if RE_NUM.match(ln) else 'other')
                break
        else:
            cls = 'no_field'
    ir = idx_md.get(rel)
    recs.append({'md_path': rel, 'kind': ir['kind'] if ir else 'UNMAPPED',
                 'status': ir['status'] if ir else 'UNMAPPED',
                 'sha256': ir['sha256'] if ir else '',
                 'functions_class': cls, 'functions_value': val or '',
                 'bytes': len(raw), 'sha256_file': hashlib.sha256(raw).hexdigest() if raw else ''})

field = collections.Counter((r['kind'], r['functions_class']) for r in recs)
# 按件（sha256 去重）看：同件多路径副本是否同类
per_item = {}
for r in recs:
    if r['kind'] == 'UNMAPPED':
        continue
    per_item.setdefault(r['sha256'], set()).add(r['functions_class'])
item_kinds = {r['sha256']: r['kind'] for r in recs if r['kind'] != 'UNMAPPED'}
per_item_kind = collections.Counter((item_kinds[k], '/'.join(sorted(v))) for k, v in per_item.items())
unmapped = [r for r in recs if r['kind'] == 'UNMAPPED']
extra_md = [r['md_path'] for r in recs if r['kind'] != 'UNMAPPED' and r['md_path'] not in idx_md]
dup_items = {k: v for k, v in collections.Counter(r['sha256'] for r in recs if r['kind'] != 'UNMAPPED').items() if v > 1}

out_rows = []
for k in ('CLR', 'nonPE', 'native'):
    sub = [r for r in recs if r['kind'] == k]
    c = collections.Counter(r['functions_class'] for r in sub)
    out_rows.append({
        'kind': k,
        'manifest_items': kinds[k],
        'index_items': sum(1 for r in idx if r['kind'] == k),
        'index_status': ';'.join('%s=%d' % (s, n) for (kk, s), n in sorted(by_kind_status.items()) if kk == k),
        'md_reports': len(sub),
        'md_functions_na': c.get('na', 0),
        'md_functions_numeric': c.get('numeric', 0),
        'md_functions_other': c.get('other', 0),
        'md_functions_missing': c.get('no_field', 0) + c.get('missing_file', 0),
        'md_extra_paths_vs_index': len([r for r in sub if r['md_path'] not in idx_md]),
    })
out_rows.append({
    'kind': 'TOTAL',
    'manifest_items': sum(kinds.values()),
    'index_items': len(idx),
    'index_status': ';'.join('%s=%d' % (s, n) for s, n in sorted(status.items())),
    'md_reports': len(recs),
    'md_functions_na': sum(1 for r in recs if r['functions_class'] == 'na'),
    'md_functions_numeric': sum(1 for r in recs if r['functions_class'] == 'numeric'),
    'md_functions_other': sum(1 for r in recs if r['functions_class'] == 'other'),
    'md_functions_missing': sum(1 for r in recs if r['functions_class'] in ('no_field', 'missing_file')),
    'md_extra_paths_vs_index': len(extra_md),
})
out_rows.append({
    'kind': 'UNMAPPED_MD',
    'manifest_items': 0, 'index_items': 0, 'index_status': '',
    'md_reports': len(unmapped),
    'md_functions_na': sum(1 for r in unmapped if r['functions_class'] == 'na'),
    'md_functions_numeric': sum(1 for r in unmapped if r['functions_class'] == 'numeric'),
    'md_functions_other': sum(1 for r in unmapped if r['functions_class'] == 'other'),
    'md_functions_missing': 0,
    'md_extra_paths_vs_index': len(unmapped),
})

cols = ['kind', 'manifest_items', 'index_items', 'index_status', 'md_reports',
        'md_functions_na', 'md_functions_numeric', 'md_functions_other',
        'md_functions_missing', 'md_extra_paths_vs_index']
with open(os.path.join(OUT, 'ledger-counts.csv'), 'w', encoding='utf-8', newline='\n') as f:
    w = csv.DictWriter(f, fieldnames=cols)
    w.writeheader()
    for r in out_rows:
        w.writerow(r)

# 逐份明细（可按 sha/路径复核）
with open(os.path.join(OUT, 'ledger-counts-detail.csv'), 'w', encoding='utf-8', newline='\n') as f:
    w = csv.DictWriter(f, fieldnames=['md_path', 'kind', 'status', 'sha256', 'functions_class', 'functions_value', 'bytes', 'sha256_file'])
    w.writeheader()
    for r in sorted(recs, key=lambda x: (x['kind'], x['md_path'])):
        w.writerow(r)

print('manifest kinds', dict(kinds), 'rows', len(man))
print('index status', dict(status), 'rows', len(idx))
print('tree md', len(md_paths))
print('field by kind x class', dict(field))
print('item-level (dedup by sha) kind -> classes', dict(per_item_kind))
print('md paths not in index', len(extra_md))
print('items with >1 md path', len(dup_items), 'sum extra paths', sum(v - 1 for v in dup_items.values()))
print('unmapped md sample', unmapped[:5])
print('field rows', out_rows)
# 台账交叉
print('ledger-clr rows', len(clr_l), dict(collections.Counter(r['kind'] for r in clr_l)))
print('ledger-native rows', len(nat_l), dict(collections.Counter(r['status'] for r in nat_l)))
print('ledger sha in index: clr', sum(1 for r in clr_l if r['sha256'] in manifest_by_key), '/', len(clr_l))
print('ledger sha in index: native', sum(1 for r in nat_l if r['sha256'] in manifest_by_key), '/', len(nat_l))
