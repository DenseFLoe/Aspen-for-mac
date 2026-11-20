#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""il_dump.py — 全程序集 IL 清单 + 元数据摘要（dnfile + ECMA-335 自解析，无需 Ghidra）。

用法：
  python tool/il_dump.py --dll <文件> [--out <*.il.txt>] [--json <摘要.json>]

输出文本约定：每个 MethodDef 一行，以 "MD " 开头（判据 C2 用 grep -L '^MD '）；
有 IL 体的方法其后跟全部指令，行首为 IL_XXXX 偏移。
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent / 'lib'))

import argparse
import collections
import hashlib
import json

try:
    import dnfile  # noqa: F401
except ModuleNotFoundError:  # 依赖目录由 tool/config/tools.json 的 pythonpath 给出
    _cfg = json.loads((Path(__file__).resolve().parent / 'config' / 'tools.json').read_text(encoding='utf-8'))
    sys.path.insert(0, _cfg.get('pythonpath', ''))

import dnlib
import iltab

CALL_OPS = ('call', 'callvirt', 'newobj', 'ldftn', 'ldvirtftn', 'jmp')


# ---------------------------------------------------------------- signatures
def _method_sig(asm, mi):
    try:
        d = asm.method_sig_text(mi)
    except Exception:
        return None, []
    if not d:
        return None, []
    return d.get('ret'), list(d.get('params') or [])


def _memberref_sig(asm, mr):
    try:
        d = dnlib.parse_methsig(asm, asm.sig_blob(mr.Signature))
    except Exception:
        return None, []
    if not d:
        return None, []
    return d.get('ret'), list(d.get('params') or [])


def resolve_call(asm, tok):
    """call/callvirt/newobj 的操作数 -> '名称空间.类型::方法(参数类型, ...)'。"""
    tag = tok >> 24
    idx = (tok & 0xFFFFFF) - 1
    try:
        if tag == 0x06:
            name = asm.method_name(idx)
            _, ps = _method_sig(asm, idx)
        elif tag == 0x0A:
            mr = asm.md.MemberRef.rows[idx]
            name = '%s::%s' % (asm.memberref_parent_name(mr.Class), mr.Name.value)
            _, ps = _memberref_sig(asm, mr)
        elif tag == 0x2B:
            ms = asm.md.MethodSpec.rows[idx]
            inner = asm._resolve_coded_method(ms.Method)
            return inner + ('()' if not inner.endswith(')') else '')
        else:
            return 'token_%08X' % tok
    except Exception:
        return 'token_%08X' % tok
    return '%s(%s)' % (name, ', '.join(ps))


# ---------------------------------------------------------------- method body
def body_info(asm, mi):
    """返回方法体头信息；无方法体返回 None。"""
    m = asm.methods[mi]
    if not m.struct.Rva:
        return None
    try:
        b = asm.body(mi)
    except Exception:
        return None
    if not b:
        return None
    off = b['file_offset']
    if b['header_size'] == 1:
        form, word = 'tiny', asm.raw[off]
    else:
        form, word = 'fat', int.from_bytes(asm.raw[off:off + 2], 'little')
    return {'rva': b['rva'], 'off': off, 'form': form, 'word': word,
            'code': b['code_size'], 'maxstack': b['maxstack'],
            'il': b['il'], 'localvarsig': b['localvarsig']}


def classify(m):
    flags = m.struct.Flags
    impl = m.struct.ImplFlags
    if flags & 0x2000:
        return 'pinvoke'
    if flags & 0x0400:
        return 'abstract'
    if (impl & 3) == 3:
        return 'runtime'
    if m.struct.Rva:
        return 'il'
    return 'other'


# ---------------------------------------------------------------- PE resource
def version_resource(path):
    try:
        import pefile
        pe = pefile.PE(path)
    except Exception:
        return None
    out = None
    try:
        for e in pe.DIRECTORY_ENTRY_RESOURCE.entries:
            if getattr(e, 'id', None) != 16:
                continue
            for e2 in e.directory.entries:
                for e3 in e2.directory.entries:
                    d = e3.data.struct
                    data = pe.get_data(d.OffsetToData, d.Size)
                    out = {'size': len(data), 'sha256': hashlib.sha256(data).hexdigest(),
                           'rva': hex(d.OffsetToData), 'name_id': e2.id, 'lang': e3.id}
                    break
                if out:
                    break
            if out:
                break
    except Exception:
        pass
    imps = []
    try:
        for d in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []) or []:
            imps.append({'dll': d.dll.decode('ascii', 'replace'),
                         'symbols': [s.name.decode('ascii', 'replace') if s.name else ('#%d' % s.ordinal) for s in d.imports]})
    except Exception:
        pass
    try:
        pe.close()
    except Exception:
        pass
    return {'version': out, 'imports': imps}


# ---------------------------------------------------------------- summary
def summarize(path, display_name=None):
    a = dnlib.Asm(path)
    raw = a.raw
    pe = a.pe_info()
    grouping = collections.Counter()
    header_dist = collections.Counter()
    calls = collections.OrderedDict()
    errors = 0
    il_bytes = 0
    il_methods = 0
    for mi in range(len(a.methods)):
        m = a.methods[mi]
        grouping[classify(m)] += 1
        bi = body_info(a, mi)
        if not bi:
            continue
        il_methods += 1
        il_bytes += len(bi['il'])
        header_dist['%s 0x%02X' % (bi['form'], bi['word']) if bi['form'] == 'tiny'
                   else 'fat 0x%04X' % bi['word']] += 1
        try:
            insns = iltab.decode(a, bi['il'])
        except Exception:
            errors += 1
            continue
        for ins in insns:
            if ins['kind'] != 'meth' or not ins['operand']:
                continue
            tgt = resolve_call(a, ins['operand'][1])
            rec = calls.setdefault(tgt, {'count': 0, 'sites': []})
            rec['count'] += 1
            if len(rec['sites']) < 8:
                rec['sites'].append(ins['off'])
    pinvoke = []
    try:
        implmap_rows = list(a.md.ImplMap.rows)
    except Exception:
        implmap_rows = []
        errors += 1
    for im in implmap_rows:
        try:
            row = im.MemberForwarded.row
            if type(row).__name__ != 'MethodDefRow':
                continue
            mi = a.method_index(row)
            try:
                scope = im.ImportScope.row.Name.value
            except Exception:
                scope = '?'
            ret, ps = _method_sig(a, mi)
            mv = getattr(im.struct, 'MappingFlags', 0)
            pinvoke.append({'token': '0x%08X' % a.method_token(mi),
                            'method': a.method_name(mi),
                            'library': scope, 'entry': im.ImportName.value,
                            'flags': '0x%04X' % int(mv),
                            'implflags': '0x%04X' % a.methods[mi].struct.ImplFlags,
                            'sig': '%s(%s)' % (ret or '?', ', '.join(ps))})
        except Exception:
            errors += 1
            continue
    streams = [{'name': s['name'], 'offset': s['offset'], 'size': s['size']} for s in a.streams['streams']]
    try:
        n_res = len(a.md.ManifestResource.rows)
    except Exception:
        n_res = 0
    vres = version_resource(path)
    clr = pe['clr']
    clr['runtime_version_string'] = a.streams['version_string']
    return {
        'display': display_name or Path(path).name,
        'file_name': Path(path).name,
        'size': len(raw),
        'sha256': hashlib.sha256(raw).hexdigest(),
        'pe': pe,
        'clr': clr,
        'streams': streams,
        'grouping': dict(grouping),
        'header_dist': [{'header': k, 'count': v} for k, v in header_dist.most_common()],
        'calls': [{'target': k, 'count': v['count'], 'sites': v['sites']}
                  for k, v in sorted(calls.items(), key=lambda kv: (-kv[1]['count'], kv[0]))],
        'pinvoke': pinvoke,
        'manifest_resources': n_res,
        'imports': (vres or {}).get('imports') or [],
        'version_resource': (vres or {}).get('version'),
        'method_count': len(a.methods),
        'il_method_count': il_methods,
        'il_bytes': il_bytes,
        'decode_errors': errors,
    }


# ---------------------------------------------------------------- IL text
def dump_text(asm, display_name):
    lines = ['# IL 清单（全量）',
             '# 件: %s' % display_name,
             '# sha256: %s' % hashlib.sha256(asm.raw).hexdigest(),
             '# 字节数: %d' % len(asm.raw),
             '# 生成: tool/il_dump.py + tool/lib/dnlib.py + tool/lib/iltab.py'
             '（dnfile 0.18.0，ECMA-335 自解析，未用 Ghidra）',
             '# MethodDef 总数: %d' % len(asm.methods),
             '# 约定: 每个 MethodDef 一行以 "MD " 开头；其后为该方法体全部指令。',
             '']
    hits = 0
    for mi in range(len(asm.methods)):
        name = asm.method_name(mi) + '()'
        try:
            ret, ps = _method_sig(asm, mi)
            if ret is not None:
                name = '%s(%s) : %s' % (asm.method_name(mi), ', '.join(ps), ret)
        except Exception:
            pass
        grp = classify(asm.methods[mi])
        bi = body_info(asm, mi)
        if bi is None:
            lines.append('MD 0x%08X rva=0x00000000 body=none group=%s %s'
                         % (asm.method_token(mi), grp, name))
            continue
        hits += 1
        if bi['form'] == 'tiny':
            hdr = 'tiny hdrword=0x%02X' % bi['word']
        else:
            hdr = 'fat hdrword=0x%04X maxstack=%d localvarsig=0x%08X' % (
                bi['word'], bi['maxstack'], bi['localvarsig'])
        lines.append('MD 0x%08X rva=0x%08X off=0x%08X %s code=%d %s'
                     % (asm.method_token(mi), bi['rva'], bi['off'], hdr,
                        bi['code'], name))
        try:
            insns = iltab.decode(asm, bi['il'])
        except Exception as exc:
            lines.append('  # IL 解码失败: %s: %s' % (type(exc).__name__, exc))
            lines.append('  # 原始字节: %s' % bi['il'].hex())
            continue
        for ins in insns:
            lines.append('  IL_%04X  %-14s %s' % (
                ins['off'], ins['raw'],
                iltab.text(asm, ins['op'], ins['kind'], ins['operand'], ins['off'])))
    if hits == 0:
        lines.append('MD (none) body=none 说明: 本程序集无任何 IL 方法体')
    return '\n'.join(lines) + '\n'


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument('--dll', required=True)
    ap.add_argument('--out')
    ap.add_argument('--json')
    ns = ap.parse_args(argv)
    a = dnlib.Asm(ns.dll)
    text = dump_text(a, Path(ns.dll).name)
    if ns.out:
        Path(ns.out).parent.mkdir(parents=True, exist_ok=True)
        Path(ns.out).write_text(text, encoding='utf-8')
        print('IL DUMP file=%s lines=%d' % (ns.out, text.count('\n')))
    else:
        sys.stdout.write(text)
    if ns.json:
        s = summarize(ns.dll)
        Path(ns.json).write_text(json.dumps(s, ensure_ascii=False, indent=1), encoding='utf-8')
        print('IL SUMMARY file=%s methods=%d il=%d' % (ns.json, s['method_count'], s['il_method_count']))
    return 0


if __name__ == '__main__':
    sys.exit(main())
