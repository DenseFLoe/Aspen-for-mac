# -*- coding: utf-8 -*-
"""NATIVE-340 mixed-assembly evidence builder (native view + CLR metadata + IL bodies).

All product files are generated here. Chain:
  Ghidra (analyzeHeadless + ExportEvidence.java on the CLI-cleared copy) -> native funcs/bytes/pseudo-C
  tool/md_reader.py -> TypeDef/MethodDef tables (original file)
  tool/il_disasm.py -> IL method bodies + call tokens (original file bytes)
"""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402
import md_reader  # noqa: E402
import il_disasm  # noqa: E402

MANUAL_C = '''/* FUNC 00003660 sub_180003660_manual (14 bytes, hand-decoded; no function was created by the analyzer) */
void *sub_180003660(void)
{
    unsigned char *peb = (unsigned char *)__readgsqword(0x30);  /* mov rax, gs:[30h] */
    return *(void **)(peb + 8);                                 /* mov rax, [rax+8]; retn */
}'''


def load_dump(dumpdir):
    funcs, order = {}, []
    for row in csv.DictReader(open(Path(dumpdir) / 'funcs.tsv', encoding='utf-8'), delimiter='\t'):
        e = int(row['entry'], 16)
        funcs[e] = dict(rva=e, end=int(row['end'], 16), name=row['name'], decompile_ok=int(row['decomp']),
                        cfile=row['cfile'], instr=[])
        order.append(e)
    for row in csv.DictReader(open(Path(dumpdir) / 'instr.tsv', encoding='utf-8'), delimiter='\t'):
        e = int(row['entry'], 16)
        if e in funcs:
            funcs[e]['instr'].append(dict(rva=int(row['addr'], 16), bytes=row['bytes'], text=row['text']))
    order.sort()
    return [funcs[e] for e in order]


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding='utf-8', newline='\n')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--binary', default='issue-materials/340/WrapSaveMergeNNFiles.dll')
    ap.add_argument('--dump', default='work/gh340')
    ap.add_argument('--out', default='handoff/inbox/NATIVE-340')
    ap.add_argument('--sha', default='869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec')
    a = ap.parse_args()
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    base = pe.imagebase
    cli = pe.directory(14)[0]
    meta = md_reader.parse(data, pe.filepos(struct.unpack_from('<I', data, pe.filepos(cli) + 8)[0]))
    types, methods = meta['types'], meta['methods']
    mby = {m['token']: m for m in methods}
    funcs = load_dump(a.dump)
    funcs = [f for f in funcs if f['instr'] and f['instr'][0]['rva'] == f['rva']]
    manual = dict(rva=0x3660, end=0x366e, name='sub_180003660_manual', decompile_ok=0, cfile='',
                  instr=[dict(rva=0x3660, bytes='65488b042530000000', text='mov rax, gs:[30h]'),
                         dict(rva=0x3669, bytes='488b4008', text='mov rax, [rax+8]'),
                         dict(rva=0x366d, bytes='c3', text='retn')])
    if not any(f['rva'] == 0x3660 for f in funcs):
        funcs.append(manual)
        funcs.sort(key=lambda f: f['rva'])
    out = Path(a.out)
    code = out / 'code'

    # native asm / c
    asm, c = [], []
    asm_span, c_span, instr_line = {}, {}, {}
    asm.append('; NATIVE-340 native disassembly; EA / SIZE / INSTR with real bytes; imagebase %#x' % base)
    c.append('/* NATIVE-340 reconstructed pseudo-C (editable; native view with CLI COM directory cleared, RVA unchanged) */')
    for f in funcs:
        rva, end = f['rva'], f['end']
        asm.append('')
        asm.append('; FUNC %08X-%08X %s (%d bytes)' % (rva, end, f['name'], end - rva))
        asm_span[rva] = [len(asm) + 1, None]
        for ins in f['instr']:
            spaced = ' '.join(ins['bytes'][i:i+2] for i in range(0, len(ins['bytes']), 2)).upper()
            asm.append('%08X  %s  %s' % (ins['rva'], spaced, ins['text']))
            instr_line[ins['rva']] = len(asm)
        asm_span[rva][1] = len(asm)
        c.append('')
        c.append('/* ---- FUNC %08X %s (%d bytes) ---- */' % (rva, f['name'], end - rva))
        c_span[rva] = [len(c) + 1, None]
        if f is manual:
            txt = MANUAL_C
        else:
            cf = Path(a.dump) / f['cfile']
            txt = cf.read_text(encoding='utf-8', errors='replace') if cf.exists() else '/* decompile-unavailable */'
            if not txt.strip():
                txt = '/* decompile-unavailable */'
        c.extend(txt.rstrip('\n').split('\n'))
        c_span[rva][1] = len(c)
    write(code / 'native.asm', '\n'.join(asm) + '\n')
    write(code / 'native.c', '\n'.join(c) + '\n')

    def containing(rva):
        for f in funcs:
            if f['rva'] <= rva < f['end']:
                return f
        return None

    # metadata.asm / types.cs / methods.il
    ml = ['; NATIVE-340 CLR metadata (563 TypeDef / 188 MethodDef from the original CLI tables)']
    type_line, type_methods = {}, {}
    for t in types:
        lo, hi = t['method_start'], t['method_end']
        type_line[t['token']] = len(ml) + 1
        members = [m for m in methods if lo <= m['token'] - 0x06000000 < hi]
        type_methods[t['token']] = members
        ml.append('0x%08X  TypeDef  %s  MethodList 0x060000%02X-0x060000%02X (%d members)'
                  % (t['token'], t['name'], lo - 1, hi - 2, hi - lo))
        for m in members:
            ml.append('    0x%08X  MethodDef  %s  flavor=%s rva=0x%X' % (m['token'], m['name'], m['flavor'], m['rva']))
    write(code / 'metadata.asm', '\n'.join(ml) + '\n')

    def san(n):
        s = ''.join(ch if (ch.isalnum() or ch == '_') else '_' for ch in n)
        return s if s and not s[0].isdigit() else 'T_' + s

    tl = ['/* NATIVE-340 TypeDef declarations with original member ownership (MethodList from CLI tables) */']
    tspan = {}
    for t in types:
        tspan[t['token']] = [len(tl) + 1, None]
        tl.append('// TypeDef 0x%08X  %s  MethodList=%d members' % (t['token'], t['name'], len(type_methods[t['token']])))
        tl.append('public class %s {  /* metadata name: %s */' % (san(t['name'].rpartition('.')[2]), t['name']))
        for m in type_methods[t['token']]:
            tl.append('    // 0x%08X  %s  flavor=%s rva=0x%X' % (m['token'], m['name'], m['flavor'], m['rva']))
            tl.append('    public extern void %s();' % san(m['name']))
        tl.append('}')
        tspan[t['token']][1] = len(tl)
    write(code / 'types.cs', '\n'.join(tl) + '\n')

    token_names = {m['token']: m['name'] for m in methods}
    il = ['/* NATIVE-340 MethodDef bodies: IL disassembly from original bytes (tool/il_disasm.py) */']
    mspan = {}
    il_calls = []
    for m in methods:
        mspan[m['token']] = [len(il) + 1, None]
        il.append('// MethodDef 0x%08X  %s  flavor=%s rva=0x%X' % (m['token'], m['name'], m['flavor'], m['rva']))
        if m['flavor'] == 'IL' and m['rva']:
            body = il_disasm.body(data, pe.filepos, m['rva'])
            il.append('.method /* %s */ cil managed { ' % m['name'])
            for off, name, operand, size in il_disasm.decode(body, token_names):
                line = '  IL_%04X: %-9s %s' % (off, name, operand)
                il.append(line.rstrip())
                if name in ('call', 'callvirt', 'calli'):
                    il_calls.append((m, off, name, operand, len(il)))
            il.append('}')
        elif m['flavor'] == 'native':
            il.append('.method /* %s */ pinvokeimpl native, body in code/native.c at RVA 0x%X' % (m['name'], m['rva']))
        else:
            il.append('.method /* %s */ declaration only, no RVA (import/runtime implementation)' % m['name'])
        mspan[m['token']][1] = len(il)
    write(code / 'methods.il', '\n'.join(il) + '\n')

    # native-functions.csv
    with open(out / 'native-functions.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.writer(fh)
        w.writerow(['rva', 'name'])
        for f in funcs:
            w.writerow(['0x%X' % f['rva'], f['name']])

    # anchors: .pdata + entry + exports + native MethodDef RVAs
    anchors = set()
    pe_off = struct.unpack_from('<I', data, 60)[0]
    anchors.add(struct.unpack_from('<I', data, pe_off + 24 + 16)[0])
    uw, usz = pe.directory(3)
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        anchors.add(struct.unpack_from('<I', data, off)[0])
    exp, _ = pe.directory(0)
    if exp:
        q = pe.filepos(exp)
        _, n, _, fn, _, _ = struct.unpack_from('<IIIIII', data, q + 16)
        for i in range(n):
            t = struct.unpack_from('<I', data, pe.filepos(fn) + 4 * i)[0]
            if pe.in_code(t):
                anchors.add(t)
    for m in methods:
        if m['flavor'] == 'native' and m['rva']:
            anchors.add(m['rva'])

    rows, covered = [], set()
    for key in sorted(anchors):
        f = next((x for x in funcs if x['rva'] == key), None) or containing(key)
        if not f or not any(ins['rva'] == key for ins in f['instr']):
            rows.append(dict(kind='native', key='0x%X' % key, state='gap', first_bytes='', listing='', source='',
                             note='分析器未在该地址解码指令；恢复条件＝在该地址重新反汇编并确认函数边界'))
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
                         note='分析器识别函数 %s (%d 字节)' % (f['name'], f['end'] - f['rva'])))
    for t in types:
        mset = type_methods[t['token']]
        rows.append(dict(kind='type', key=t['token'], state='covered', first_bytes='',
                         listing='code/metadata.asm#L%d-L%d' % (type_line[t['token']], type_line[t['token']]),
                         source='code/types.cs#L%d-L%d' % tuple(tspan[t['token']]),
                         note='TypeDef 声明：%s；MethodList 0x060000%02X-0x060000%02X（%d 个成员，types.cs 逐成员）'
                              % (t['name'], t['method_start'] - 1, t['method_end'] - 2, len(mset))))
    for m in methods:
        ss = 'code/methods.il#L%d-L%d' % tuple(mspan[m['token']])
        if not m['rva']:
            rows.append(dict(kind='method', key=m['token'], state='declaration', first_bytes='', listing=ss, source=ss,
                             note='无 RVA，仅元数据声明（flavor=%s）' % m['flavor']))
        elif m['flavor'] == 'native':
            f = containing(m['rva'])
            src = 'code/native.c#L%d-L%d' % tuple(c_span[f['rva']]) if f else ss
            note = '原生实现 MethodDef，RVA 0x%X 对应 %s' % (m['rva'], f['name'] if f else '?')
            if m['rva'] == 0x3660:
                note += '（分析器未建函数；14 字节手工解码并给可编辑实现）'
            rows.append(dict(kind='method', key=m['token'], state='covered', first_bytes='', listing=ss, source=src, note=note))
        else:
            rows.append(dict(kind='method', key=m['token'], state='covered', first_bytes='', listing=ss, source=ss,
                             note='IL 方法体，RVA 0x%X（原件 IL 字节）' % m['rva']))
    with open(out / 'coverage.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'key', 'state', 'first_bytes', 'listing', 'source', 'note'])
        w.writeheader(); w.writerows(rows)

    # calls: IL side from decoded tokens + native side from PE import slots
    calls = []
    for (m, off, name, operand, ln) in il_calls:
        tok = int(operand.split()[0], 16) if operand.startswith('0x') else 0
        tgt = mby.get(tok)
        if name == 'calli':
            calls.append(dict(kind='method', caller='0x%X' % m['token'], callee='calli@IL_%04X' % off, **{'class': 'unresolved'},
                              listing='code/methods.il#L%d-L%d' % (ln, ln),
                              note='IL calli：经函数指针间接调用（IL_%04X，签名 token 0x%08X），静态不可唯一确定；恢复条件＝指针表初始化分析或运行期断点' % (off, tok)))
        elif tgt is not None and tgt['flavor'] == 'native':
            calls.append(dict(kind='method', caller='0x%X' % m['token'],
                              callee='0x%08X %s (native RVA 0x%X)' % (tok, tgt['name'], tgt['rva']), **{'class': 'boundary'},
                              listing='code/methods.il#L%d-L%d' % (ln, ln),
                              note='托管→原生边界：IL_%04X 操作码 %s，操作数 token 0x%08X → 原生 MethodDef RVA 0x%X；签名中的 mscorlib 修饰不参与目标判定'
                                   % (off, name, tok, tgt['rva'])))
        elif tgt is not None:
            pass
        else:
            calls.append(dict(kind='method', caller='0x%X' % m['token'], callee='token 0x%08X' % tok, **{'class': 'external'},
                              listing='code/methods.il#L%d-L%d' % (ln, ln),
                              note='IL 调用本模块外成员（token 不在 MethodDef 表），IL_%04X' % off))
    iat = pe.iat()
    _, insns = parse_asm(str(code / 'native.asm'))
    sites = 0
    for (ln, addr, b, text, raw) in insns:
        o = 1 if (len(b) > 1 and 0x40 <= b[0] <= 0x4F) else 0
        if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
            disp = int.from_bytes(b[o + 2:o + 6], 'little', signed=True)
            tgt = addr + len(b) + disp
            own = containing(addr)
            if tgt in iat and own:
                sites += 1
                lib, nm = iat[tgt]
                calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='%s!%s' % (lib, nm), **{'class': 'external'},
                                  listing='code/native.asm#L%d-L%d' % (ln, ln),
                                  note='导入%s；IAT 槽 RVA 0x%X（%s!%s）；指令 RVA 0x%X' % ('call' if (b[o + 1] >> 3) == 2 else 'jmp', tgt, lib, nm, addr)))
            continue
        if len(b) >= o + 2 and b[o] == 0xFF:
            mr = b[o + 1]
            ind = ((mr & 0xF8) == 0xD0) or ((mr & 0xC0) != 0xC0 and (mr & 0xC7) != 0x05 and ((mr >> 3) & 7) in (2, 4))
            own = containing(addr)
            if ind and own:
                calls.append(dict(kind='native', caller='0x%X' % own['rva'], callee='indirect@0x%X' % addr, **{'class': 'unresolved'},
                                  listing='code/native.asm#L%d-L%d' % (ln, ln),
                                  note='间接转移：目标不在指令内（%s），指令 RVA 0x%X；恢复条件＝运行期断点或指针表初始化分析' % (text.split(';')[0].strip()[:60], addr)))
    with open(out / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(calls)

    n_il = sum(1 for m in methods if m['flavor'] == 'IL' and m['rva'])
    n_nat = sum(1 for m in methods if m['flavor'] == 'native')
    n_decl = sum(1 for m in methods if not m['rva'])
    stats = dict(rows=len(rows), funcs=len(funcs), anchors=len(anchors),
                 external=sum(1 for x in calls if x['class'] == 'external'), boundary=sum(1 for x in calls if x['class'] == 'boundary'),
                 unresolved=sum(1 for x in calls if x['class'] == 'unresolved'), data=0,
                 gaps=sum(1 for r in rows if r['state'] == 'gap'), iat_sites=sites,
                 methoddef=len(methods), il_bodies=n_il, native_bodies=n_nat, declarations=n_decl,
                 typedefs=len(types))
    run = dict(original_sha256=a.sha,
               tool_version='Ghidra 12.1.4 (headless analysis + Decompiler) + Python stdlib readers',
               command='support/analyzeHeadless <proj> <name> -import <CLI-cleared copy> -scriptPath tool/ghidra_scripts -postScript ExportEvidence.java <dump> <anchors> ; python -B tool/gen_340_evidence.py --binary %s --dump %s' % (a.binary, a.dump),
               scope='563 TypeDef；188 MethodDef = 167 IL 体 + 19 原生实现（含 0x3660 手工解码 1 项）+ 2 无 RVA 声明；75 个原生锚点；跨界/外部/间接转移逐址登记',
               limitations='静态分析，无运行期动态验证；原生视图来自清 CLI COM 目录的副本（RVA 不变），first_bytes 全部取自原件固定哈希文件；IL 体由原件字节自行反汇编（tool/il_disasm.py）。',
               native_reported_count=len(funcs), analyzed_at='2026-11-22', imagebase='0x%X' % base)
    write(out / 'run.json', json.dumps(run, ensure_ascii=False, indent=1))
    write(out / 'metrics.json', json.dumps(stats, ensure_ascii=False, indent=1))
    print(json.dumps(stats, ensure_ascii=False))


if __name__ == '__main__':
    main()
