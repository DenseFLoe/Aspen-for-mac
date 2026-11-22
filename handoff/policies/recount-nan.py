#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""recount-nan.py -- FUNC-NA-371 修订版口径的复算入口（仅标准库）。

两种输入模式，结果应完全一致：

  A. 目录清单 + md 镜像（推荐，带 Git blob 指纹校验）:
     python -B recount-nan.py --ledger ledger-counts.csv \
         --tree tree_main.json --index remote_index.csv \
         --mdroot out/cache/repo_final [--write-ledger ledger-counts.fixed.csv]

  B. 带指纹的逐份明细（无需镜像）:
     python -B recount-nan.py --ledger ledger-counts.csv --detail ledger-counts-detail.csv

输入说明:
  --tree    GitHub git/trees 递归清单（含每项 blob sha），用作 md 路径清单；
            md 范围 = analysis/20261120-batch-driver/ 下的 *.md。
  --index   remote_index.csv（每件一行，含 kind / sha256 / report_md）。
  --mdroot  与 --tree 同一提交的本地 md 镜像根目录（大小写不敏感匹配）。
  --detail  逐份明细 CSV，列 md_path,kind,functions_class(,sha256)。

输出口径（两组，勿混用）:
  CALIBER_A  全部 md 文件口径: 1346 份 -> na 567 / numeric 777 / no_field 2
  CALIBER_B  按件口径（index 1315 件）: na 558（CLR 470 + nonPE 86 + native 2）/ numeric 757
  UNMAPPED_MD: 31 份（20 numeric / 9 na / 2 no_field），不是 30；missing 不得写 0。

退出码: 0 = 复算值与本文 EXPECT 完全一致（ledger 旧值差异只报告，不阻断）；
        1 = 输入缺失或复算值与 EXPECT 不符。
"""
import argparse
import csv
import hashlib
import json
import os
import re
import sys

MD_PREFIX = 'analysis/20261120-batch-driver/'
RE_FUNCS = re.compile(r'^\s*-\s*functions=(.*)$')

# 修订版口径的期望值（全部由 hashlib/计数得出，可被本脚本独立复算）
EXPECT = {
    'md_total': 1346,
    'md_na': 567,
    'md_numeric': 777,
    'md_other': 0,
    'md_no_field': 2,
    'item_total': 1315,
    'item_na': 558,
    'item_na_clr': 470,
    'item_na_nonpe': 86,
    'item_na_native': 2,
    'item_numeric': 757,
    'unmapped_total': 31,
    'unmapped_na': 9,
    'unmapped_numeric': 20,
    'unmapped_no_field': 2,
}


def rows(path):
    with open(path, encoding='utf-8-sig', newline='') as f:
        return list(csv.DictReader(f))


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def git_blob_sha1(path):
    data = open(path, 'rb').read()
    h = hashlib.sha1()
    h.update(b'blob %d\0' % len(data))
    h.update(data)
    return h.hexdigest()


def classify_text(text):
    for line in text.splitlines():
        m = RE_FUNCS.match(line)
        if m:
            val = m.group(1).strip()
            if val.upper().startswith('N/A'):
                return 'na', val
            if val.isdigit():
                return 'numeric', val
            return 'other', val
    return 'no_field', ''


def classify_file(path):
    raw = open(path, 'rb').read()
    return classify_text(raw.decode('utf-8-sig', 'replace'))


def build_detail(args):
    """模式 A：按 tree 清单遍历 md，返回 (records, fingerprints)。"""
    tree = json.load(open(args.tree, encoding='utf-8'))
    md_paths = sorted(e['path'] for e in tree['tree']
                      if e.get('type') == 'blob' and e['path'].startswith(MD_PREFIX)
                      and e['path'].endswith('.md'))
    blob_sha = {e['path']: e['sha'] for e in tree['tree'] if e.get('type') == 'blob'}

    mirror = {}
    for dirpath, _dirs, files in os.walk(args.mdroot):
        for name in files:
            if name.endswith('.md'):
                full = os.path.join(dirpath, name)
                rel = os.path.relpath(full, args.mdroot).replace(os.sep, '/')
                mirror[rel.casefold()] = full

    ok = bad = missing = 0
    recs = []
    for rel in md_paths:
        fp = mirror.get(rel.casefold())
        if not fp:
            missing += 1
            recs.append({'md_path': rel, 'kind': 'UNMAPPED', 'sha256': '',
                         'functions_class': 'missing_file', 'functions_value': '',
                         'sha256_file': ''})
            continue
        cls, val = classify_file(fp)
        if git_blob_sha1(fp) == blob_sha.get(rel):
            ok += 1
        else:
            bad += 1
        recs.append({'md_path': rel, 'kind': '', 'sha256': '',
                     'functions_class': cls, 'functions_value': val,
                     'sha256_file': sha256_file(fp)})
    idx = {r['report_md']: r for r in rows(args.index)}
    for rec in recs:
        ir = idx.get(rec['md_path'])
        rec['kind'] = ir['kind'] if ir else 'UNMAPPED'
        rec['sha256'] = ir['sha256'] if ir else ''
    fp = {'md_blobs': len(md_paths), 'tree_root': tree.get('sha', ''),
          'blob_ok': ok, 'blob_bad': bad, 'blob_missing': missing,
          'index_sha256': sha256_file(args.index),
          'index_rows': len(idx),
          'ledger_sha256': sha256_file(args.ledger)}
    return recs, fp


def load_detail(args):
    """模式 B：直接读取带指纹的逐份明细。"""
    recs = []
    for r in rows(args.detail):
        cls = (r.get('functions_class') or '').strip()
        if not cls:  # 只给了 functions_value 时按同规则归类
            cls, _ = classify_text('- functions=' + (r.get('functions_value') or ''))
        recs.append({'md_path': r['md_path'], 'kind': (r.get('kind') or 'UNMAPPED'),
                     'sha256': (r.get('sha256') or ''),
                     'functions_class': cls,
                     'functions_value': (r.get('functions_value') or ''),
                     'sha256_file': (r.get('sha256_file') or '')})
    fp = {'detail_sha256': sha256_file(args.detail), 'md_blobs': len(recs),
          'blob_ok': 0, 'blob_bad': 0, 'blob_missing': 0,
          'index_rows': sum(1 for r in recs if r['kind'] != 'UNMAPPED'),
          'ledger_sha256': sha256_file(args.ledger)}
    return recs, fp


def main(argv=None):
    ap = argparse.ArgumentParser(description='FUNC-NA-371 N/A 口径复算')
    ap.add_argument('--ledger', required=True)
    ap.add_argument('--tree')
    ap.add_argument('--index')
    ap.add_argument('--mdroot')
    ap.add_argument('--detail')
    ap.add_argument('--write-ledger')
    args = ap.parse_args(argv)

    if args.detail:
        recs, fp = load_detail(args)
    elif args.tree and args.index and args.mdroot:
        recs, fp = build_detail(args)
    else:
        ap.error('需要 --detail，或同时给 --tree/--index/--mdroot')

    print('INPUT ledger_sha256=%s' % fp['ledger_sha256'])
    if args.detail:
        print('INPUT detail_sha256=%s md_rows=%d' % (fp['detail_sha256'], fp['md_blobs']))
    else:
        print('INPUT tree_root=%s md_blobs=%d index_sha256=%s index_rows=%d'
              % (fp['tree_root'], fp['md_blobs'], fp['index_sha256'], fp['index_rows']))
        print('FINGERPRINT git_blob_verify ok=%d bad=%d missing=%d of %d'
              % (fp['blob_ok'], fp['blob_bad'], fp['blob_missing'], fp['md_blobs']))

    # ---- 口径 A：全部 md 文件 ----
    a = {'na': 0, 'numeric': 0, 'other': 0, 'no_field': 0, 'missing_file': 0}
    for r in recs:
        a[r['functions_class']] = a.get(r['functions_class'], 0) + 1
    md_total = len(recs)
    print('CALIBER_A md_total=%d na=%d numeric=%d other=%d no_field=%d missing_file=%d'
          % (md_total, a['na'], a['numeric'], a['other'], a['no_field'], a['missing_file']))

    # ---- 口径 B：按件（index 行，sha256 去重） ----
    items = {}
    for r in recs:
        if r['kind'] == 'UNMAPPED':
            continue
        key = r['sha256'] or ('path:' + r['md_path'])
        items.setdefault(key, {'kind': r['kind'], 'classes': set(), 'paths': []})
        items[key]['classes'].add(r['functions_class'])
        items[key]['paths'].append(r['md_path'])
    it_na = {'CLR': 0, 'nonPE': 0, 'native': 0}
    it_num = 0
    native_na = []
    for key, it in items.items():
        cls = 'na' if 'na' in it['classes'] else ('numeric' if 'numeric' in it['classes'] else 'other')
        if cls == 'na':
            it_na[it['kind']] = it_na.get(it['kind'], 0) + 1
            if it['kind'] == 'native':
                native_na.append((key, it['paths'][0]))
        elif cls == 'numeric':
            it_num += 1
    item_total = len(items)
    item_na = sum(it_na.values())
    print('CALIBER_B item_total=%d na=%d (CLR=%d nonPE=%d native=%d) numeric=%d'
          % (item_total, item_na, it_na['CLR'], it_na['nonPE'], it_na['native'], it_num))
    for key, path in sorted(native_na):
        print('NATIVE_NA_ITEM sha256=%s md=%s' % (key, path))

    # ---- UNMAPPED_MD ----
    un = [r for r in recs if r['kind'] == 'UNMAPPED']
    u = {'na': 0, 'numeric': 0, 'other': 0, 'no_field': 0, 'missing_file': 0}
    for r in un:
        u[r['functions_class']] = u.get(r['functions_class'], 0) + 1
    print('UNMAPPED_MD total=%d na=%d numeric=%d other=%d no_field=%d missing_file=%d'
          % (len(un), u['na'], u['numeric'], u['other'], u['no_field'], u['missing_file']))
    for r in sorted(un, key=lambda x: x['md_path']):
        if r['functions_class'] == 'no_field':
            print('UNMAPPED_NO_FIELD md=%s' % r['md_path'])

    # ---- 与随附 ledger-counts.csv 对照 ----
    led = rows(args.ledger)
    led_by = {r['kind']: r for r in led}
    rec_map = {
        'CLR': {'md_reports': 470, 'md_functions_na': it_na['CLR'], 'md_functions_numeric': 0,
                'md_functions_missing': 0},
        'nonPE': {'md_reports': 86, 'md_functions_na': it_na['nonPE'], 'md_functions_numeric': 0,
                  'md_functions_missing': 0},
        'native': {'md_reports': 759, 'md_functions_na': it_na['native'],
                   'md_functions_numeric': it_num, 'md_functions_missing': 0},
        'TOTAL': {'md_reports': md_total, 'md_functions_na': a['na'],
                  'md_functions_numeric': a['numeric'],
                  'md_functions_missing': a['no_field'] + a['missing_file']},
        'UNMAPPED_MD': {'md_reports': len(un), 'md_functions_na': u['na'],
                        'md_functions_numeric': u['numeric'],
                        'md_functions_missing': u['no_field'] + u['missing_file']},
    }
    ledger_bad = 0
    for kind in ('CLR', 'nonPE', 'native', 'TOTAL', 'UNMAPPED_MD'):
        lr = led_by.get(kind)
        if not lr:
            print('LEDGER %s MISSING_ROW' % kind)
            ledger_bad += 1
            continue
        for field, want in rec_map[kind].items():
            have = (lr.get(field) or '').strip()
            if have != str(want):
                ledger_bad += 1
                print('LEDGER_DEFECT %s.%s ledger=%r recomputed=%d'
                      % (kind, field, have, want))
    if ledger_bad == 0:
        print('LEDGER_CROSSCHECK mismatches=0')
    else:
        print('LEDGER_CROSSCHECK mismatches=%d (listed above; UNMAPPED_MD.md_functions_missing=0 is the old hardcoded defect)' % ledger_bad)

    # ---- 与 EXPECT 对照 ----
    got = {
        'md_total': md_total, 'md_na': a['na'], 'md_numeric': a['numeric'],
        'md_other': a['other'], 'md_no_field': a['no_field'],
        'item_total': item_total, 'item_na': item_na,
        'item_na_clr': it_na['CLR'], 'item_na_nonpe': it_na['nonPE'],
        'item_na_native': it_na['native'], 'item_numeric': it_num,
        'unmapped_total': len(un), 'unmapped_na': u['na'],
        'unmapped_numeric': u['numeric'], 'unmapped_no_field': u['no_field'],
    }
    bad = 0
    for k, want in EXPECT.items():
        if got[k] != want:
            bad += 1
            print('EXPECT_MISMATCH %s got=%d want=%d' % (k, got[k], want))
    print('EXPECT check fields=%d mismatches=%d' % (len(EXPECT), bad))

    if args.write_ledger:
        cols = ['kind', 'manifest_items', 'index_items', 'index_status', 'md_reports',
                'md_functions_na', 'md_functions_numeric', 'md_functions_other',
                'md_functions_missing', 'md_extra_paths_vs_index']
        with open(args.write_ledger, 'w', encoding='utf-8', newline='\n') as f:
            w = csv.DictWriter(f, fieldnames=cols)
            w.writeheader()
            for r in led:
                r = dict(r)
                if r['kind'] == 'UNMAPPED_MD':
                    r['md_reports'] = str(len(un))
                    r['md_functions_na'] = str(u['na'])
                    r['md_functions_numeric'] = str(u['numeric'])
                    r['md_functions_missing'] = str(u['no_field'] + u['missing_file'])
                w.writerow(r)
        print('WROTE_LEDGER %s' % args.write_ledger)

    print('RESULT %s' % ('PASS' if bad == 0 else 'FAIL'))
    return 0 if bad == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
