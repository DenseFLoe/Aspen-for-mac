# -*- coding: utf-8 -*-
"""Resolve register/table indirect transfers against the original PE.

For each unresolved site in calls.csv: read the instruction bytes from the listing,
recover the operand form, then
  * RIP-relative table slot: read the 8-byte pointer at the target;
  * register-indirect: backward slice within the function for the base register.
Progressively reclassifies to external (target is an IAT slot / import thunk) and
records a resolution column for the rest.
"""
import argparse, csv, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402

REGS = ['rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15']


def modrm_reg(m):
    return (m >> 3) & 7


def operand_base(b, o):
    """Return (reg_index, disp, rip) for a mod/rm memory operand, else None."""
    if len(b) < o + 2:
        return None
    m = b[o + 1]
    mod = m >> 6
    rm = m & 7
    if mod == 3:
        return None
    if rm == 4:  # SIB
        sib = b[o + 2]
        base = sib & 7
        disp_off = o + 3
        if base == 5 and mod == 0:
            disp = struct.unpack_from('<i', b, disp_off)[0]
            return ('rip', disp, disp_off + 4)
        if base == 4:
            return None
        disp = 0
        if mod == 1:
            disp = struct.unpack_from('<b', b, disp_off)[0]
        elif mod == 2:
            disp = struct.unpack_from('<i', b, disp_off)[0]
        return (base, disp, disp_off)
    if rm == 5 and mod == 0:
        return ('rip', struct.unpack_from('<i', b, o + 2)[0], o + 6)
    disp = 0
    if mod == 1:
        disp = struct.unpack_from('<b', b, o + 2)[0]
    elif mod == 2:
        disp = struct.unpack_from('<i', b, o + 2)[0]
    return (rm, disp, o + 2)


def text_reg(text):
    m = re.search(r'\b(r[a-z0-9]+|e[a-z]{2})\b', text.lower())
    return m.group(1) if m else None


def resolve(asm_path, dll, rows, functions):
    pe = PE(open(dll, 'rb').read())
    iat = pe.iat()
    lines, insns = parse_asm(asm_path)
    by_addr = {a: (ln, b, t) for (ln, a, b, t, _) in insns}
    out = []
    for r in rows:
        m = re.search(r'#L(\d+)', r['listing'])
        if not m:
            out.append(dict(r, resolved='', verdict='unresolved')); continue
        ln = int(m.group(1))
        addr = None
        for (l2, a, b, t, _) in insns:
            if l2 == ln:
                addr, byt, txt = a, b, t
                break
        if addr is None:
            out.append(dict(r, resolved='', verdict='unresolved')); continue
        o = 1 if (len(byt) > 1 and 0x40 <= byt[0] <= 0x4F) else 0
        base = operand_base(byt, o)
        verdict, resolved = 'unresolved', ''
        if base:
            reg, disp, _ = base
            if reg == 'rip':
                slot = addr + len(byt) + disp
                try:
                    val = struct.unpack_from('<Q', open(dll, 'rb').read(), pe.filepos(slot))[0]
                except Exception:
                    val = 0
                if val in iat:
                    verdict = 'external'
                    resolved = 'IAT 0x%X %s!%s' % (val, iat[val][0], iat[val][1])
                elif val and pe.in_code(val):
                    resolved = 'internal RVA 0x%X' % val
                    verdict = 'resolved-internal'
                else:
                    resolved = 'table slot 0x%X value 0x%X' % (slot, val)
            else:
                # backward slice inside the same function
                fn = next((f for f in functions if f[0] <= addr < f[1]), None)
                src = 'no provenance'
                if fn:
                    for (l2, a2, b2, t2, _) in reversed(insns):
                        if a2 >= addr or a2 < fn[0]:
                            continue
                        if text_reg(t2) == REGS[reg] if reg < len(REGS) else False:
                            src = t2
                            break
                resolved = 'base %s %s' % (REGS[reg] if reg < len(REGS) else '?', src[:60])
        out.append(dict(r, resolved=resolved, verdict=verdict))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    a = ap.parse_args()
    folder = Path(a.folder)
    ind = list(csv.DictReader(open(folder / 'code' / 'indirect.csv', encoding='utf-8')))
    lines, insns = parse_asm(str(folder / 'code' / 'native.asm')) if (folder / 'code' / 'native.asm').exists() else parse_asm(str(sorted((folder / 'code').glob('native-*.asm'))[0]))
    funcs = []
    for ln in open(str(folder / 'code' / 'native.asm'), encoding='utf-8', errors='ignore') if (folder / 'code' / 'native.asm').exists() else []:
        pass
    # function ranges from FUNC headers across chunks
    import glob
    for fn in sorted(glob.glob(str(folder / 'code' / 'native*.asm'))):
        for ln in open(fn, encoding='utf-8', errors='ignore'):
            m = re.match(r'; FUNC ([0-9A-F]+)-([0-9A-F]+)', ln)
            if m:
                funcs.append((int(m.group(1), 16), int(m.group(2), 16)))
    res = resolve(str(folder / 'code' / 'native.asm'), a.binary, ind, funcs)
    from collections import Counter
    print(Counter(r['verdict'] for r in res))
    with open(folder / 'code' / 'indirect-resolved.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=list(res[0].keys()))
        w.writeheader(); w.writerows(res)


if __name__ == '__main__':
    main()
