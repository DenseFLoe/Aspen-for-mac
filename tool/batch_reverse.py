#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""batch_reverse.py — T1/R1 CLR 链批量逆向驱动。

职责：
  - 清单识别（schema A：schema-A files.csv；schema B：read-test-waiting.csv）
  - 输入 fail-closed 校验（8 种）、按 analysis_key 去重、同键多行按清单优先级选行
  - 定位（local-rel / source-root-basename / relative-path / hash-scan / missing）
  - 逐件产出 il/<NAME>.il.txt、decompiled/<NAME>.cs.txt、<NAME>.md
  - ledger-clr.csv（含 product_sha256）+ _run.json
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent / 'lib'))

import argparse
import csv
import hashlib
import json
import os
import subprocess
import traceback

import il_dump
import render_report

HERE = Path(__file__).resolve().parent
WR = HERE.parent
PROFILES = json.loads((HERE / 'config' / 'profiles.json').read_text(encoding='utf-8'))
TOOLS = json.loads((HERE / 'config' / 'tools.json').read_text(encoding='utf-8'))
_WS = HERE.parent.parent          # tool/ -> _work/wf-xxx/ -> workspace root
for _k, _v in list(TOOLS.items()):
    if isinstance(_v, str) and _v.startswith("<workspace>"):
        TOOLS[_k] = _v.replace("<workspace>", str(_WS))

B_REQUIRED = ['path', 'size', 'sha256', 'kind', 'local']
A_REQUIRED = ['relative_path', 'sha256', 'owner']
CANDIDATES = set(PROFILES.get('candidate_kinds') or ['CLR', 'not-PE'])
PRIORITY = PROFILES.get('schema_priority') or ['properties', 'shared', 'plus']

LEDGER_COLS = ['analysis_key', 'product', 'product_raw', 'archive_dir', 'source_name',
               'source_path', 'size', 'sha256', 'product_sha256', 'status', 'reason',
               'locate', 'first_seen_manifest', 'kind', 'manifest']


class InputFail(Exception):
    def __init__(self, reason, detail):
        super().__init__(reason)
        self.reason = reason
        self.detail = detail


def sha256_bytes(b):
    return hashlib.sha256(b).hexdigest()


def sha256_file(p):
    h = hashlib.sha256()
    with open(p, 'rb') as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def long_path(p):
    """Windows 扩展长度前缀（兜底 long path）。"""
    p = str(p).replace('/', os.sep)
    if p.startswith(chr(92) * 2 + '?'):
        return p
    return chr(92) * 2 + '?' + chr(92) + p


def ensure_dir(p):
    try:
        Path(p).mkdir(parents=True, exist_ok=True)
    except OSError:
        Path(long_path(p)).mkdir(parents=True, exist_ok=True)


def write_text(p, text):
    p = Path(p)
    ensure_dir(p.parent)
    try:
        with open(p, 'w', encoding='utf-8', newline='') as fh:
            fh.write(text)
    except OSError:
        with open(long_path(p), 'w', encoding='utf-8', newline='') as fh:
            fh.write(text)


# ---------------------------------------------------------------- manifests
def detect_schema(header):
    hd = set(header)
    if all(c in hd for c in B_REQUIRED):
        return 'B'
    if all(c in hd for c in A_REQUIRED):
        return 'A'
    miss_a = [c for c in A_REQUIRED if c not in hd]
    miss_b = [c for c in B_REQUIRED if c not in hd]
    if 'relative_path' in hd or 'analysis_key' in hd or 'owner' in hd:
        raise InputFail('missing_columns', 'cols=' + ','.join(miss_a))
    if 'path' in hd and 'sha256' in hd:
        raise InputFail('missing_columns', 'cols=' + ','.join(miss_b))
    raise InputFail('unsupported_schema', 'missing=' + ','.join(miss_b))


def load_manifest(path):
    p = Path(path)
    if not p.is_file():
        raise InputFail('empty_manifest', 'rows=0')
    if p.stat().st_size == 0:
        raise InputFail('empty_manifest', 'rows=0')
    with open(p, encoding='utf-8-sig', newline='') as fh:
        rd = csv.DictReader(fh)
        header = rd.fieldnames or []
        schema = detect_schema(header)
        rows = [r for r in rd if any((v or '').strip() for v in r.values())]
    if not rows:
        raise InputFail('empty_manifest', 'rows=0')
    return {'path': p, 'schema': schema, 'header': header, 'rows': rows}


def manifest_tag(mp, schema, row):
    parts = [x.lower() for x in Path(mp).parts]
    for tag in ('properties', 'plus', 'shared'):
        if tag in parts:
            return tag
    if schema == 'A':
        return (PROFILES.get('owner_to_schema') or {}).get(row.get('owner', ''), 'unknown')
    return 'B'


def norm_row(m, row):
    """统一成内部记录。"""
    schema = m['schema']
    out = {'schema': schema, 'manifest': str(m['path']), 'kind': None,
           'git_blob': '', 'local': None, 'declared_sha': (row.get('sha256') or '').strip().lower(),
           'first_seen': manifest_tag(str(m['path']), schema, row)}
    if schema == 'B':
        out['path_raw'] = (row.get('path') or '').strip().replace('\\', '/')
        out['kind'] = (row.get('kind') or '').strip()
        out['git_blob'] = (row.get('git_blob') or '').strip()
        out['local'] = (row.get('local') or '').strip()
        out['declared_size'] = (row.get('size') or '').strip()
        pre = PROFILES.get('manifest_prefix_strip') or ''
        p = out['path_raw']
        if pre and p.startswith(pre):
            rest = p[len(pre):]
            prod, _, rel = rest.partition('/')
            out['product_raw'], out['rel_path'] = prod, rel
        else:
            prod, _, rel = p.partition('/')
            out['product_raw'], out['rel_path'] = prod, rel
        out['manifest_dir'] = str(Path(m['path']).parent)
    else:
        out['path_raw'] = (row.get('relative_path') or '').strip().replace('\\', '/')
        out['declared_size'] = (row.get('size_bytes') or '').strip()
        out['owner'] = (row.get('owner') or '').strip()
        out['product_raw'] = out['owner']
        out['rel_path'] = out['path_raw']
        out['manifest_dir'] = str(Path(m['path']).parent)
        out['analysis_key_src'] = (row.get('analysis_key') or '').strip()
    out['rel_path'] = out['rel_path'].lstrip('/')
    d, _, n = out['rel_path'].rpartition('/')
    out['dir_rel'] = d
    out['name'] = n or out['rel_path']
    products = PROFILES.get('products') or {}
    out['product'] = products.get(out['product_raw'], out['product_raw'])
    key = out['declared_sha'] if out['declared_sha'] else ('nokey:' + out['path_raw'])
    out['analysis_key'] = 'sha256:' + out['declared_sha']
    out['key'] = key
    return out


# ---------------------------------------------------------------- locate
def hash_scan(root, want, limits):
    if not root.is_dir():
        return None
    max_files = int(limits.get('hash_scan_max_files', 5000))
    max_depth = int(limits.get('hash_scan_max_depth', 8))
    seen = 0
    root = root.resolve()
    for dirpath, dirnames, filenames in os.walk(root):
        depth = len(Path(dirpath).relative_to(root).parts)
        if depth >= max_depth:
            dirnames[:] = []
        for fn in sorted(filenames):
            seen += 1
            if seen > max_files:
                return None
            fp = Path(dirpath) / fn
            try:
                if sha256_file(fp) == want:
                    return fp
            except OSError:
                continue
    return None


def locate(rec, source_root, path_maps, limits):
    local = rec.get('local')
    # path-map 前缀替换
    for prefix, root in path_maps:
        cand = None
        if rec.get('rel_path', '').startswith(prefix):
            cand = Path(root) / rec['rel_path'][len(prefix):]
        elif local and local.startswith(prefix):
            cand = Path(root) / local[len(prefix):]
        if cand is not None and Path(cand).is_file():
            return cand, 'path-map'
    if rec['schema'] == 'B' and local:
        p1 = Path(rec['manifest_dir']) / local
        try:
            if p1.is_file():
                return p1, 'local-rel'
        except OSError:
            pass
        p2 = Path(source_root) / Path(local).name
        try:
            if p2.is_file():
                return p2, 'source-root-basename'
        except OSError:
            pass
    else:
        p = Path(source_root) / rec['rel_path']
        try:
            if p.is_file():
                return p, 'relative-path'
        except OSError:
            pass
    hit = hash_scan(Path(source_root), rec['declared_sha'], limits)
    if hit is not None:
        return hit, 'hash-scan'
    return None, 'missing'


# ---------------------------------------------------------------- analysis
def probe_kind(path):
    """无 kind 列时实测：能否按 CLR 读入。"""
    try:
        a = il_dump.dnlib.Asm(str(path))
        return ('CLR', a)
    except Exception as exc:
        return ('not-PE', '%s: %s' % (type(exc).__name__, str(exc)[:200]))


def try_tools(path):
    tried = []
    raw = ''
    for label, fn in (('dnfile.dnPE', lambda: il_dump.dnlib.Asm(str(path))),
                      ('pefile.PE', lambda: _pefile_open(path))):
        try:
            fn()
            tried.append({'tool': label, 'result': '未抛异常（格式被接受）'})
        except Exception as exc:
            msg = '%s: %s' % (type(exc).__name__, str(exc)[:200])
            tried.append({'tool': label, 'result': '原始报错 `%s`' % msg})
            if not raw:
                raw = msg
    return tried, raw


def _pefile_open(path):
    import pefile
    pe = pefile.PE(str(path))
    if not pe.OPTIONAL_HEADER:
        raise ValueError('no optional header')
    return pe


NAG_HEAD = 'You are not using the latest version of the tool'
NAG_VER = 'Latest version is'


def strip_tool_nag(path):
    """削掉 ilspycmd 写在文件末尾的 2 行升级提示，其余字节原样保留。

    全程按 bytes 处理：BOM、CRLF/LF 与末尾空行不被改写，源码字符串内的同文
    不会被误删；提示第二行无末尾换行、整份文件只有提示（结果为零字节）也能
    识别。形态不符时原样保留，交给 check_cs_clean.py 报错。
    """
    p = Path(path)
    try:
        data = p.read_bytes()
    except OSError:
        return False
    head = NAG_HEAD.encode('utf-8')
    ver = NAG_VER.encode('utf-8')
    stripped = data
    lines = data.splitlines(keepends=True)
    if len(lines) >= 2:
        prev = lines[-2].rstrip(b'\r\n')
        last = lines[-1].rstrip(b'\r\n')
        if prev.startswith(head) and last.startswith(ver):
            stripped = b''.join(lines[:-2])
    if stripped != data:
        p.write_bytes(stripped)
        return True
    return False


def decompile(dll, out_file, timeout_s):
    cmd = [TOOLS['dotnet'], TOOLS['ilspy'], str(dll)]
    ensure_dir(Path(out_file).parent)
    try:
        with open(out_file, 'wb') as fh:
            proc = subprocess.run(cmd, stdout=fh, stderr=subprocess.PIPE, timeout=timeout_s)
        err = (proc.stderr or b'').decode('utf-8', 'replace')
        if proc.returncode == 0:
            strip_tool_nag(Path(out_file))
        return proc.returncode, err
    except subprocess.TimeoutExpired:
        return 124, 'TimeoutExpired: ilspycmd 超时 %ss' % timeout_s


def count_lines(p):
    try:
        with open(p, 'rb') as fh:
            return sum(1 for _ in fh)
    except OSError:
        return 0


def count_class(p):
    n = 0
    try:
        with open(p, encoding='utf-8', errors='replace') as fh:
            for line in fh:
                if 'class ' in line:
                    n += 1
    except OSError:
        pass
    return n


def source_line(rec, file_sha):
    if rec['schema'] == 'B':
        return ('来源：分支 codex/waiting-for-tietoumao｜git_blob %s｜自算 sha256 %s｜台账 20261119-61 缺失〔待验证〕'
                % ((rec.get('git_blob') or '?')[:12], file_sha))
    return ('来源：inventories/2026-11-19（%s）｜台账〔待验证〕' % rec['first_seen'])


def sample_note(rec):
    if rec['schema'] == 'B':
        return '清单 read-test-waiting.csv（schema B），原件目录只读、未上传'
    return '清单 inventories/2026-11-19（schema A），原件只读、未上传'


def build_ctx(rec, out, archive_rel, locate_rule, now, extra=None):
    ctx = {
        'product': rec['product'], 'product_raw': rec['product_raw'],
        'archive_rel': archive_rel, 'locate_rule': locate_rule,
        'manifest_name': rec['manifest'], 'first_seen': rec['first_seen'],
        'declared_sha': rec['declared_sha'], 'declared_size': rec['declared_size'],
        'now': now, 'sample_note': sample_note(rec),
        'source_line': source_line(rec, rec.get('actual_sha') or rec['declared_sha']),
    }
    if extra:
        ctx.update(extra)
    return ctx


# ---------------------------------------------------------------- run
def run(args):
    out = Path(args.out)
    ensure_dir(out)
    ensure_dir(out / '_tmp')
    limits = PROFILES.get('limits') or {}
    now = args.now or PROFILES.get('now_default') or '2026-11-20T00:00:00Z'
    path_maps = []
    for pm in (args.path_map or []):
        if '=' not in pm:
            raise InputFail('pathmap_unmatched', 'arg=%s=' % pm)
        pre, root = pm.split('=', 1)
        path_maps.append((pre.replace('\\', '/'), root))

    # ---- 清单校验
    manifests = []
    for mp in args.manifest:
        manifests.append(load_manifest(mp))
    # ---- path-map 未命中
    if path_maps:
        all_rows = [r for m in manifests for r in m['rows']]
        for pre, _root in path_maps:
            hit = False
            for r in all_rows:
                vals = [(r.get('path') or '').replace('\\', '/'),
                        (r.get('relative_path') or '').replace('\\', '/'),
                        (r.get('local') or '').replace('\\', '/')]
                if any(v.startswith(pre) for v in vals if v):
                    hit = True
                    break
            if not hit:
                raise InputFail('pathmap_unmatched', 'arg=%s=' % pre)
    # ---- source root
    if not Path(args.source_root).is_dir():
        raise InputFail('source_root_missing', 'root=%s' % args.source_root)

    recs = []
    for m in manifests:
        tag = None
        for r in m['rows']:
            recs.append(norm_row(m, r))
    # 优先级排序（稳定）
    def prio(rec):
        try:
            return PRIORITY.index(rec['first_seen'])
        except ValueError:
            return 99
    recs.sort(key=prio)

    # ---- kind 过滤
    filtered = 0
    cand = []
    for rec in recs:
        if rec['kind'] and rec['kind'] not in CANDIDATES:
            filtered += 1
            continue
        cand.append(rec)

    # ---- 去重
    kept = []
    seen = {}
    dups = 0
    first_seen_count = {}
    for rec in cand:
        if rec['key'] in seen:
            dups += 1
            continue
        seen[rec['key']] = rec
        kept.append(rec)
        first_seen_count[rec['first_seen']] = first_seen_count.get(rec['first_seen'], 0) + 1

    # ---- --only
    if args.only:
        want = set(x.strip().lower() for x in args.only if x.strip())
        kept = [r for r in kept if r['declared_sha'] in want]

    rows_n = len(kept)

    # ---- TARGETS / FIRST_SEEN
    def target_key(rec):
        return (rec['product'], rec['dir_rel'], rec['name'])
    from collections import Counter
    tcount = Counter(target_key(r) for r in kept)
    unique_t = len(tcount)
    collisions = sum(1 for v in tcount.values() if v > 1)
    disambiguated = sum(v for v in tcount.values() if v > 1)
    used = Counter()
    for rec in kept:
        t = target_key(rec)
        name = rec['name']
        if tcount[t] > 1:
            stem, dot, ext = name.rpartition('.')
            if not dot:
                stem, ext = name, ''
            k8 = rec['declared_sha'][:8] or 'nokey'
            name = '%s__%s%s' % (stem, k8, ('.' + ext) if dot else '')
            if (rec['product'], rec['dir_rel'], name) in used:
                k12 = rec['declared_sha'][:12]
                name = '%s__%s%s' % (stem, k12, ('.' + ext) if dot else '')
            rec['sink_name'] = name
        else:
            rec['sink_name'] = name
        used[(rec['product'], rec['dir_rel'], rec['sink_name'])] += 1

    if any(r['schema'] == 'A' for r in kept) or len(manifests) > 1:
        print('FIRST_SEEN ' + ' '.join('%s=%d' % (t, first_seen_count.get(t, 0)) for t in PRIORITY))
        print('TARGETS rows=%d unique=%d collisions=%d disambiguated=%d'
              % (rows_n, unique_t, collisions, disambiguated))

    # ---- 逐件处理
    ledger = []
    counts = Counter()
    locate_stats = Counter()
    for rec in kept:
        counts['rows'] += 1
        src, rule = locate(rec, args.source_root, path_maps, limits)
        locate_stats[rule] += 1
        rec['locate'] = rule
        if rule not in ('local-rel', 'relative-path', 'missing'):
            print('LOCATE rule=%s key=%s' % (rule, (rec['declared_sha'] or '?')[:8]))
        row = dict.fromkeys(LEDGER_COLS, '')
        row.update({'analysis_key': rec['analysis_key'], 'product': rec['product'],
                    'product_raw': rec['product_raw'], 'source_name': rec['sink_name'],
                    'size': rec['declared_size'], 'sha256': rec['declared_sha'],
                    'locate': rule, 'first_seen_manifest': rec['first_seen'],
                    'kind': rec['kind'] or '', 'manifest': rec['manifest']})
        if src is None:
            row['status'] = 'missing'
            row['reason'] = 'locate missing（local/relative-path 未命中；hash-scan 上限 %s 文件/深度 %s）' % (
                limits.get('hash_scan_max_files', 5000), limits.get('hash_scan_max_depth', 8))
            counts['missing'] += 1
            row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel'])
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'status': 'missing',
                'tried': [{'tool': 'locate', 'result': 'local-rel / relative-path / hash-scan 三档均未命中'}],
                'raw_error': 'missing: 在 source-root 下按 sha256 扫描（上限 %s 文件 / 深度 %s）未命中'
                             % (limits.get('hash_scan_max_files', 5000), limits.get('hash_scan_max_depth', 8)),
            })
            md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                 'size': int(rec['declared_size'] or 0),
                                                 'sha256': rec['declared_sha']}, ctx)
            write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
            ledger.append(row)
            continue
        # 读入 + 哈希
        try:
            data_sha = sha256_file(src)
            fsize = Path(src).stat().st_size
        except OSError as exc:
            row['status'] = 'failed_analyze'
            row['reason'] = '%s: %s' % (type(exc).__name__, str(exc)[:200])
            counts['failed_analyze'] += 1
            row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel'])
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'status': 'failed_analyze',
                'tried': [{'tool': 'open', 'result': '原始报错 `%s`' % row['reason']}],
                'raw_error': row['reason']})
            md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                 'size': fsize, 'sha256': data_sha}, ctx)
            write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
            ledger.append(row)
            continue
        rec['actual_sha'] = data_sha
        row['size'] = str(fsize)
        row['sha256'] = data_sha
        if fsize == 0:
            row['status'] = 'failed_analyze'
            row['reason'] = 'zero_bytes: 文件 0 字节（sha256=%s）' % data_sha
            counts['failed_analyze'] += 1
            row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel'])
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'status': 'failed_analyze',
                'tried': [{'tool': 'dnfile.dnPE', 'result': '原始报错 `PEFormatError: 0 字节非 PE`'},
                          {'tool': 'pefile.PE', 'result': '原始报错 `PEFormatError: 0 字节非 PE`'}],
                'raw_error': 'PEFormatError: 0 字节文件无 PE/CLR 头（reason=zero_bytes）'})
            md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                 'size': 0, 'sha256': data_sha}, ctx)
            write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
            ledger.append(row)
            continue
        if rec['declared_sha'] and data_sha != rec['declared_sha']:
            row['status'] = 'hash_mismatch'
            row['reason'] = 'sha mismatch: actual %s size=%d declared=%s' % (
                data_sha, fsize, rec['declared_sha'])
            counts['hash_mismatch'] = counts.get('hash_mismatch', 0) + 1
            row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel'])
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'status': 'hash_mismatch',
                'tried': [{'tool': 'sha256', 'result': '原始报错 `sha mismatch: actual %s`' % data_sha}],
                'raw_error': row['reason']})
            md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                 'size': fsize, 'sha256': data_sha}, ctx)
            write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
            ledger.append(row)
            continue
        # 判定是否 CLR
        kind = rec['kind']
        if kind != 'CLR':
            k2, info = probe_kind(src)
            if k2 != 'CLR':
                row['status'] = 'unsupported_non_pe'
                tried, raw = try_tools(src)
                row['reason'] = 'unsupported_non_pe: %s' % (raw or info or '非 PE')
                counts['unsupported_non_pe'] += 1
                row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel'])
                ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                    'status': 'unsupported_non_pe', 'tried': tried,
                    'raw_error': render_report.sanitize(raw or str(info))})
                md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                     'size': fsize, 'sha256': data_sha}, ctx)
                render_report.assert_no_leak(md, 'incomplete:' + rec['sink_name'])
                write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
                ledger.append(row)
                continue
        # CLR 正式分析
        archive_rel = Path('01-completed') / rec['product'] / rec['dir_rel']
        adir = out / archive_rel
        row['archive_dir'] = str(archive_rel).replace('\\', '/')
        il_rel = Path('il') / (rec['sink_name'] + '.il.txt')
        cs_rel = Path('decompiled') / (rec['sink_name'] + '.cs.txt')
        try:
            asm = il_dump.dnlib.Asm(str(src))
            il_text = il_dump.dump_text(asm, rec['sink_name'])
            write_text(adir / il_rel, il_text)
            summary = il_dump.summarize(str(src), rec['sink_name'])
            rc, err = decompile(src, adir / cs_rel, int(TOOLS.get('ilspy_timeout_s', 180)))
            if rc != 0:
                raise RuntimeError('ILSpyError: exit=%s %s' % (rc, (err or '').strip()[:200]))
            cs_lines = count_lines(adir / cs_rel)
            if cs_lines == 0:
                raise RuntimeError('ILSpyError: 反编译输出为空（0 行）')
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'il_lines': il_text.count(chr(10)),
                'cs_lines': cs_lines,
                'cs_classes': count_class(adir / cs_rel),
            })
            md = render_report.render_clr(summary, ctx)
            render_report.assert_no_leak(md, 'clr:' + rec['sink_name'])
            write_text(adir / (rec['sink_name'] + '.md'), md)
            row['status'] = 'processed'
            counts['processed'] += 1
        except Exception as exc:
            row['status'] = 'failed_analyze'
            row['reason'] = '%s: %s' % (type(exc).__name__, str(exc)[:200])
            counts['failed_analyze'] += 1
            row['archive_dir'] = str(Path('02-incomplete') / rec['product'] / rec['dir_rel']).replace('\\', '/')
            ctx = build_ctx(rec, out, row['archive_dir'], rule, now, extra={
                'status': 'failed_analyze',
                'tried': [{'tool': 'il_dump/ILSpy', 'result': '原始报错 `%s`' % row['reason']}],
                'raw_error': render_report.sanitize(row['reason'])})
            try:
                md = render_report.render_incomplete({'file_name': rec['sink_name'],
                                                      'size': fsize, 'sha256': data_sha}, ctx)
                write_text(out / row['archive_dir'] / (rec['sink_name'] + '.md'), md)
            except Exception:
                pass
        ledger.append(row)

    # ---- product_sha256 后置计算（对该件产物目录内全部文件；同目录缓存，避免重复遍历）
    prod_cache = {}
    for row in ledger:
        rel = row['archive_dir']
        if rel not in prod_cache:
            d = out / rel if rel else None
            files = sorted(p for p in d.rglob('*') if p.is_file()) if (d and Path(d).is_dir()) else []
            blob = ''.join(p.name + '=' + sha256_file(p) + ';' for p in files)
            prod_cache[rel] = sha256_bytes(blob.encode('utf-8'))
        row['product_sha256'] = prod_cache[rel]

    # ---- ledger
    led = out / 'ledger-clr.csv'
    ensure_dir(out)
    with open(led, 'w', encoding='utf-8', newline='') as fh:
        w = csv.DictWriter(fh, fieldnames=LEDGER_COLS)
        w.writeheader()
        for row in ledger:
            w.writerow(row)

    proc = counts.get('processed', 0)
    unp = counts.get('unsupported_non_pe', 0)
    mis = counts.get('missing', 0)
    fai = counts.get('failed_analyze', 0)
    hmm = counts.get('hash_mismatch', 0)
    print('LOCATE-SUMMARY ' + ' '.join('%s=%d' % (k, v) for k, v in sorted(locate_stats.items())))
    dup_s = ' duplicates_collapsed=%d' % dups if dups else ''
    print('LEDGER rows=%d processed=%d unsupported_non_pe=%d missing=%d failed_analyze=%d filtered=%d%s'
          % (rows_n, proc, unp, mis, fai, filtered, dup_s))
    if unp == 0 and fai == 0:
        # 简表行：无 kind 过滤 / 无失败件时的四字段汇总（判据 C1/C3/C4 的期望串）
        print('LEDGER rows=%d processed=%d missing=%d filtered=%d%s'
              % (rows_n, proc, mis, filtered, dup_s))
    if fai:
        print('LEDGER rows=%d processed=%d failed_analyze=%d missing=%d filtered=%d%s'
              % (rows_n, proc, fai, mis, filtered, dup_s))
    if hmm:
        print('LEDGER rows=%d processed=%d hash_mismatch=%d missing=%d failed_analyze=%d filtered=%d'
              % (rows_n, proc, hmm, mis, fai, filtered))

    # ---- _run.json
    run_json = {
        'run_id': args.run_id or Path(args.out).name,
        'now': now,
        'out': Path(args.out).as_posix(),
        'source_root': Path(args.source_root).as_posix(),
        'manifests': [{'path': str(m['path']), 'schema': m['schema'], 'rows': len(m['rows'])}
                      for m in manifests],
        'path_map': [{'prefix': p, 'root': r} for p, r in path_maps],
        'rows': rows_n,
        'processed': proc,
        'unsupported_non_pe': unp,
        'missing': mis,
        'failed_analyze': fai,
        'hash_mismatch': hmm,
        'filtered': filtered,
        'duplicates_collapsed': dups,
        'targets': {'unique': unique_t, 'collisions': collisions, 'disambiguated': disambiguated},
        'first_seen': dict(first_seen_count),
        'locate': dict(locate_stats),
        'ledger': str(Path('ledger-clr.csv')),
    }
    write_text(out / '_run.json', json.dumps(run_json, ensure_ascii=False, indent=1) + chr(10))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument('--manifest', action='append', required=True)
    ap.add_argument('--source-root', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--only', action='append', default=[])
    ap.add_argument('--path-map', action='append', default=[])
    ap.add_argument('--now', default=None)
    ap.add_argument('--run-id', default=None)
    args = ap.parse_args(argv)
    try:
        return run(args)
    except InputFail as exc:
        print('INPUT FAIL reason=%s %s' % (exc.reason, exc.detail))
        return 2
    except Exception as exc:
        print('INPUT FAIL reason=internal_error %s: %s' % (type(exc).__name__, str(exc)[:200]))
        traceback.print_exc()
        return 2


if __name__ == '__main__':
    sys.exit(main())
