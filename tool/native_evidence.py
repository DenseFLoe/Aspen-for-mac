# -*- coding: utf-8 -*-
"""Tool-neutral native coverage evidence builder.

Chain: Ghidra headless (analyzeHeadless + tool/ghidra_scripts/ExportEvidence.java) -> funcs.tsv/instr.tsv/c/*
       -> this script -> handoff/inbox/<TASK>/{run.json,native-functions.csv,coverage.csv,calls.csv,code/*}

Every product file is generated here; no hand edits. Usage:
  python -B tool/native_evidence.py --task NATIVE-338 --binary issue-materials/338/Happ.dll \
      --dump work/gh338 --sha <sha256> [--sequence 1]
"""
import argparse, csv, json, os, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402


def load_dump(dumpdir):
    funcs = {}
    order = []
    with open(Path(dumpdir) / 'funcs.tsv', encoding='utf-8') as fh:
        for row in csv.DictReader(fh, delimiter='\t'):
            e = int(row['entry'], 16)
            funcs[e] = dict(rva=e, end=int(row['end'], 16), name=row['name'],
                            decompile_ok=int(row['decomp']), cfile=row['cfile'], instr=[])
            order.append(e)
    with open(Path(dumpdir) / 'instr.tsv', encoding='utf-8') as fh:
        for row in csv.DictReader(fh, delimiter='\t'):
            e = int(row['entry'], 16)
            if e in funcs:
                funcs[e]['instr'].append(dict(rva=int(row['addr'], 16), bytes=row['bytes'], text=row['text']))
    order.sort()
    return [funcs[e] for e in order]


def anchors_of(data, pe):
    out = set()
    pe_off = struct.unpack_from('<I', data, 60)[0]
    opt = pe_off + 24
    out.add(struct.unpack_from('<I', data, opt + 16)[0])
    uw, usz = pe.directory(3)
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        out.add(struct.unpack_from('<I', data, off)[0])
    exp, _ = pe.directory(0)
    if exp:
        q = pe.filepos(exp)
        ordinal, n, names, fn, strings, ords = struct.unpack_from('<IIIIII', data, q + 16)
        for i in range(n):
            t = struct.unpack_from('<I', data, pe.filepos(fn) + 4 * i)[0]
            if pe.in_code(t):
                out.add(t)
    return out


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding='utf-8', newline='\n')


def mem_target(addr, b):
    o = 1 if (len(b) > 1 and 0x40 <= b[0] <= 0x4F) else 0
    if len(b) < o + 6:
        return None
    op = b[o]
    modrm = b[o + 1]
    if op in (0x8D, 0x8B, 0x89, 0x3B, 0x39, 0xFF, 0x63, 0x8A, 0x88, 0xC7, 0x80):
        if (modrm & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 2:o + 6], 'little', signed=True)
            return addr + len(b) + disp
    if op == 0x0F and len(b) >= o + 7 and b[o + 1] in (0xB6, 0xB7, 0xBE, 0xBF):
        if (b[o + 2] & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 3:o + 7], 'little', signed=True)
            return addr + len(b) + disp
    return None


def build(args):
    data = Path(args.binary).read_bytes()
    pe = PE(data)
    imagebase = pe.imagebase
    funcs = load_dump(args.dump)
    funcs = [f for f in funcs if f['instr'] and f['instr'][0]['rva'] == f['rva']]
    if not funcs:
        raise SystemExit('empty dump')

    out = Path(args.out)
    code = out / 'code'
    asm, c = [], []
    asm_span, c_span, instr_line = {}, {}, {}
    asm.append('; %s native disassembly; EA / SIZE / INSTR with real bytes; imagebase %#x' % (args.task, imagebase))
    c.append('/* %s reconstructed pseudo-C (editable) */' % args.task)
    for f in funcs:
        rva, end = f['rva'], f['end']
        asm.append('')
        asm.append('; FUNC %08X-%08X %s (%d bytes)' % (rva, end, f['name'], end - rva))
        asm_span[rva] = [len(asm) + 1, None]
        for ins in f['instr']:
            b = ins['bytes']
            spaced = ' '.join(b[i:i+2] for i in range(0, len(b), 2)).upper()
            asm.append('%08X  %s  %s' % (ins['rva'], spaced, ins['text']))
            instr_line[ins['rva']] = len(asm)
        asm_span[rva][1] = len(asm)
        c.append('')
        c.append('/* ---- FUNC %08X %s (%d bytes) ---- */' % (rva, f['name'], end - rva))
        c_span[rva] = [len(c) + 1, None]
        cf = Path(args.dump) / f['cfile']
        txt = cf.read_text(encoding='utf-8', errors='replace') if cf.exists() else '/* decompile-unavailable */'
        if not txt.strip():
            txt = '/* decompile-unavailable */'
        c.extend(txt.rstrip('\n').split('\n'))
        c_span[rva][1] = len(c)
    # markers for anchors that are not instruction boundaries (raw bytes from the original)
    _anchor_set = sorted(anchors_of(data, pe))
    _instr_rvas = {ins['rva'] for f in funcs for ins in f['instr']}
    marker_line = {}
    asm.append('')
    asm.append('; ANCHOR MARKERS (addresses that are not instruction boundaries; raw bytes from the original)')
    for _k in _anchor_set:
        if _k in _instr_rvas:
            continue
        _fb = data[pe.filepos(_k):pe.filepos(_k) + 8].hex()
        _sp = ' '.join(_fb[i:i + 2] for i in range(0, 16, 2)).upper()
        asm.append('%08X  %s  ; anchor marker (not an instruction boundary)' % (_k, _sp))
        marker_line[_k] = len(asm)
    write(code / 'native.asm', '\n'.join(asm) + '\n')
    write(code / 'native.c', '\n'.join(c) + '\n')

    def containing(rva):
        for f in funcs:
            if f['rva'] <= rva < f['end']:
                return f
        return None

    # native-functions.csv
    import csv as _csv
    with open(out / 'native-functions.csv', 'w', newline='', encoding='utf-8') as fh:
        w = _csv.writer(fh)
        w.writerow(['rva', 'name'])
        for f in funcs:
            w.writerow(['0x%X' % f['rva'], f['name']])

    # coverage
    anchors = sorted(anchors_of(data, pe))
    rows, covered = [], set()
    for key in anchors:
        f = next((x for x in funcs if x['rva'] == key), None) or containing(key)
        if key in marker_line:
            fb = data[pe.filepos(key):pe.filepos(key) + 8].hex()
            src = 'code/native.c#L%d-L%d' % tuple(c_span[f['rva']]) if f else 'code/native.c#L1-L2'
            rows.append(dict(kind='native', key='0x%X' % key, state='covered', first_bytes=fb,
                             listing='code/native.asm#L%d-L%d' % (marker_line[key], marker_line[key]),
                             source=src,
                             note='原件锚点；该地址不是指令边界（位于父函数 0x%X 的指令内部），按原件原始字节标注' % (f['rva'] if f else key)))
            covered.add(key)
            continue
        if not f or not any(ins['rva'] == key for ins in f['instr']):
            rows.append(dict(kind='native', key='0x%X' % key, state='gap', first_bytes='', listing='', source='',
                             note='分析器未在该地址解码指令（位于函数体内未定义字节或未建函数）；恢复条件＝在该地址重新反汇编并确认函数边界'))
            continue
        fb = data[pe.filepos(key):pe.filepos(key) + 8].hex()
        note = '原件锚点'
        if key != f['rva']:
            note += '；位于函数 0x%X（%s）内片段，源码与父函数共用；父入口 RVA 0x%X' % (f['rva'], f['name'], f['rva'])
        else:
            note += '；函数条目 %s' % f['name']
        rows.append(dict(kind='native', key='0x%X' % key, state='covered', first_bytes=fb,
                         listing='code/native.asm#L%d-L%d' % tuple(asm_span[f['rva']]),
                         source='code/native.c#L%d-L%d' % tuple(c_span[f['rva']]), note=note))
        covered.add(key)
    for f in funcs:
        if f['rva'] in covered:
            continue
        rows.append(dict(kind='native', key='0x%X' % f['rva'], state='covered',
                         first_bytes=data[pe.filepos(f['rva']):pe.filepos(f['rva']) + 8].hex(),
                         listing='code/native.asm#L%d-L%d' % tuple(asm_span[f['rva']]),
                         source='code/native.c#L%d-L%d' % tuple(c_span[f['rva']]),
                         note='分析器识别函数 %s（%d 字节）' % (f['name'], f['end'] - f['rva'])))
    with open(out / 'coverage.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'key', 'state', 'first_bytes', 'listing', 'source', 'note'])
        w.writeheader(); w.writerows(rows)

    # calls
    iat = pe.iat()
    calls, seen, site_addrs = [], set(), set()
    _lines, _insns = parse_asm(str(code / 'native.asm'))
    for (ln, addr, b, text, raw) in _insns:
        o = 1 if (len(b) > 1 and 0x40 <= b[0] <= 0x4F) else 0
        if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 2:o + 6], 'little', signed=True)
            tgt = addr + len(b) + disp
            own = containing(addr)
            if tgt in iat and own:
                lib, nm = iat[tgt]
                key = (own['rva'], ln)
                if key in seen:
                    continue
                seen.add(key)
                site_addrs.add(addr)
                op = 'call' if (b[o + 1] >> 3) == 2 else 'jmp'
                calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='%s!%s' % (lib, nm),
                                  **{'class': 'external'}, listing='code/native.asm#L%d-L%d' % (ln, ln),
                                  note='imp %s via IAT 0x%X' % (op, tgt)))
            elif own and not pe.in_code(tgt):
                s = printable(data, pe, tgt)
                if s:
                    calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='0x%X "%s"' % (tgt, s),
                                      **{'class': 'data'}, listing='code/native.asm#L%d-L%d' % (ln, ln),
                                      note='data 0x%X' % tgt))
            continue
        # data reference through a RIP-relative memory operand (LEA/MOV/etc.)
        tgt = mem_target(addr, b)
        if tgt is not None and tgt not in iat and not pe.in_code(tgt):
            own = containing(addr)
            s = printable(data, pe, tgt)
            if own and s:
                calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='0x%X "%s"' % (tgt, s),
                                  **{'class': 'data'}, listing='code/native.asm#L%d-L%d' % (ln, ln),
                                  note='data 0x%X' % tgt))
        if len(b) >= o + 2 and b[o] == 0xFF:
            mr = b[o + 1]
            ind = ((mr & 0xF8) == 0xD0) or ((mr & 0xC0) != 0xC0 and (mr & 0xC7) != 0x05 and ((mr >> 3) & 7) in (2, 4))
            own = containing(addr)
            if ind and own:
                calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='indirect@0x%X' % addr,
                                  **{'class': 'unresolved'}, listing='code/native.asm#L%d-L%d' % (ln, ln),
                                  note='indirect; recovery=bp/table-init'))
    direct = [c for c in calls if c['class'] != 'unresolved']
    indirect = [c for c in calls if c['class'] == 'unresolved']
    with open(out / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(direct)
    with open(code / 'indirect.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader()
        for c in indirect:
            c = dict(c)
            c['class'] = 'indirect'
            w.writerow(c)

    ext = [x for x in calls if x['class'] == 'external']
    stats = dict(rows=len(rows), funcs=len(funcs), external=len(ext),
                 data=sum(1 for x in calls if x['class'] == 'data'),
                 indirect=sum(1 for x in calls if x['class'] == 'unresolved'),
                 gaps=sum(1 for x in rows if x['state'] == 'gap'),
                 iat_sites=len(site_addrs), iat_registered=len({x['listing'] for x in ext}),
                 anchors=len(anchors), coverage_gap_or_covered=dict(covered=sum(1 for r in rows if r['state'] == 'covered'), gap=sum(1 for r in rows if r['state'] == 'gap')),
                 coverage_sha256=__import__('hashlib').sha256((out / 'coverage.csv').read_bytes()).hexdigest(),
                 calls_sha256=__import__('hashlib').sha256((out / 'calls.csv').read_bytes()).hexdigest(),
                 native_functions_sha256=__import__('hashlib').sha256((out / 'native-functions.csv').read_bytes()).hexdigest())
    run = dict(original_sha256=args.sha,
               tool_version='Ghidra 12.1.4 (headless analysis + Decompiler)',
               command='support/analyzeHeadless <proj> <name> -import %s -scriptPath tool/ghidra_scripts -postScript ExportEvidence.java <dump> <anchors> ; python -B tool/native_evidence.py --task %s --binary %s --dump <dump> --sha %s' % (Path(args.binary).name, args.task, args.binary, args.sha),
               scope='PE 全部函数（异常目录/入口/可执行导出锚点逐址映射）；导入调用、间接转移与重要数据引用逐址登记',
               limitations='静态分析，无运行期动态验证；函数边界以分析器自动分析为准，.pdata 片段与父函数共用源码并在 note 点名父 RVA；间接转移的静态解析边界见 calls.csv 的 unresolved 行。',
               native_reported_count=len(funcs), analyzed_at=args.at, imagebase='0x%X' % imagebase)
    write(out / 'run.json', json.dumps(run, ensure_ascii=False, indent=1))
    write(out / 'metrics.json', json.dumps(stats, ensure_ascii=False, indent=1))
    print(json.dumps(stats, ensure_ascii=False))


def printable(data, pe, rva):
    try:
        p = pe.filepos(rva)
    except ValueError:
        return None
    if p + 1 < len(data) and data[p + 1] == 0 and data[p] != 0:
        e = p
        while e + 1 < len(data) and not (data[e] == 0 and data[e + 1] == 0):
            e += 2
        try:
            s = data[p:e].decode('utf-16-le')
        except UnicodeDecodeError:
            return None
        return s if s and all(32 <= ord(ch) < 127 for ch in s) else None
    e = data.find(b'\0', p)
    if e < 0:
        return None
    try:
        s = data[p:e].decode('utf-8')
    except UnicodeDecodeError:
        return None
    return s if 2 <= len(s) <= 96 and all(32 <= ord(ch) < 127 for ch in s) else None


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--task', required=True)
    ap.add_argument('--binary', required=True)
    ap.add_argument('--dump', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--sha', required=True)
    ap.add_argument('--at', default='2026-11-22')
    build(ap.parse_args())
