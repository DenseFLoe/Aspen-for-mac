# -*- coding: utf-8 -*-
"""s65: classify the 161 two-hop sites into three counterexample categories.

  missing-row        : no main-table row resolves for the site (path+line absent)
  multiple-equivalent: more than one candidate row exists on the same (path,line)
  contradiction      : exactly one row resolves, but its callee/note does not carry
                       the import symbol derived from the original binary
"""
import argparse, csv, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm  # noqa: E402


def same_symbol(declared, symbol):
    """Exact identity: full library name + name/ordinal (no substring matching)."""
    return (declared or '').strip().lower() == (symbol or '').strip().lower()


def pdata_hosts(data, pe):
    out = []
    uw, usz = pe.directory(3)
    if not uw:
        return out
    p = pe.filepos(uw)
    for off in range(p, p + usz, 12):
        b, e = struct.unpack_from('<II', data, off)
        out.append((b, e))
    return out


def thunk_slot(data, pe, rva):
    try:
        p = pe.filepos(rva)
    except ValueError:
        return None
    b = data[p:p + 8]
    o = 1 if b and 0x40 <= b[0] <= 0x4F else 0
    if len(b) >= o + 6 and b[o] == 0xFF and (b[o + 1] & 0xC7) == 0x05:
        return rva + o + 6 + struct.unpack_from('<i', b, o + 2)[0]
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--folder', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--binary', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--out', default='handoff/inbox/NATIVE-337/code/s65-counterexamples.csv')
    ap.add_argument('--reference', default='handoff/inbox/NATIVE-337/code/s37-two-hop.csv')
    a = ap.parse_args()
    folder, data = Path(a.folder), open(a.binary, 'rb').read()
    pe = PE(data)
    iat = pe.iat()
    hosts = pdata_hosts(data, pe)
    owner_ranges = []
    addr2line = {}
    for fn in sorted((folder / 'code').rglob('native*.asm')):
        for ln in open(fn, encoding='utf-8'):
            m = ln.split() if ln.startswith('; FUNC') else []
            if len(m) >= 3:
                lo, hi = m[2].split('-')
                owner_ranges.append((int(lo, 16), int(hi, 16)))
        rel = fn.relative_to(folder).as_posix()
        _, insns = parse_asm(str(fn))
        for (ln, addr, b, text, raw) in insns:
            addr2line[addr] = (rel, ln)

    def owner_of(rva):
        hits = [lo for lo, hi in owner_ranges if lo <= rva < hi]
        return max(hits) if hits else 0

    calls = list(csv.DictReader(open(folder / 'calls.csv', encoding='utf-8')))
    by_key = {}
    for idx, r in enumerate(calls, start=2):
        ref = r['listing']
        if '#L' not in ref:
            continue
        fpart, lpart = ref.split('#L', 1)
        by_key.setdefault((fpart, int(lpart.split('-')[0])), []).append(idx)

    seen_sites = set()
    rows = []
    for addr in sorted(addr2line):
        seen_sites.add(addr)
        try:
            p = pe.filepos(addr)
        except ValueError:
            continue
        raw = data[p:p + 5]
        if len(raw) < 5 or raw[0] not in (0xE8, 0xE9):
            continue
        hop = addr + 5 + struct.unpack_from('<i', raw, 1)[0]
        slot = thunk_slot(data, pe, hop)
        if slot not in iat:
            continue
        lib, nm = iat[slot]
        sym = '%s!%s' % (lib, nm)
        asm = addr2line[addr]
        cands = by_key.get((asm[0], asm[1]), [])
        ok = [i for i in cands if same_symbol(calls[i - 2].get('callee', ''), sym)]
        category = ''
        detail = ''
        if not cands:
            category = 'missing-row'
            detail = 'no calls.csv row references %s#L%d' % (asm[0], asm[1])
        elif len(cands) > 1:
            category = 'multiple-equivalent'
            detail = 'candidates=' + ','.join(str(i) for i in cands) + '; symbol-matching=' + ','.join(str(i) for i in ok)
        elif not ok:
            chosen = calls[cands[0] - 2]
            category = 'contradiction'
            detail = 'declared=%r note=%r; original=%s' % (chosen.get('callee', ''), chosen.get('note', '')[:60], sym)
        rows.append(dict(category=category or 'ok', site='0x%X' % addr, first_hop='0x%X' % hop,
                         iat_slot='0x%X' % slot, import_symbol=sym,
                         asm='%s#L%d' % (asm[0], asm[1]),
                         calls_row=(ok[0] if len(ok) == 1 else (cands[0] if len(cands) == 1 else '')),
                         candidates=','.join(str(i) for i in cands), detail=detail))
    # stations present in the fixed reference but absent from the current listing
    ref = Path(a.reference)
    if ref.exists():
        for r in csv.DictReader(open(ref, encoding='utf-8')):
            if r.get('site'):
                addr = int(r['site'], 16)
                if addr not in seen_sites:
                    rows.append(dict(category='missing-listing', site='0x%X' % addr,
                                     first_hop=r.get('first_hop', ''), iat_slot=r.get('iat_slot', ''),
                                     import_symbol=r.get('import_symbol', ''), asm=r.get('asm', ''),
                                     calls_row='', candidates='',
                                     detail='reference site absent from current listing (instruction removed?)'))
    out = Path(a.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    with open(out, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['category', 'site', 'first_hop', 'iat_slot', 'import_symbol',
                                           'asm', 'calls_row', 'candidates', 'detail'])
        w.writeheader(); w.writerows(rows)
    from collections import Counter
    print('sites', len(rows), 'categories', dict(Counter(r['category'] for r in rows)))
    for cat in ('missing-row', 'multiple-equivalent', 'contradiction'):
        sample = [r for r in rows if r['category'] == cat][:3]
        for r in sample:
            print(' ', cat, r['site'], r['import_symbol'], r['asm'], r['detail'][:100])


def self_test():
    """Inject one anomaly per category and prove the classifier detects each."""
    import shutil, tempfile
    base = Path('handoff/inbox/NATIVE-337')
    root = Path(tempfile.mkdtemp(prefix='s65-'))
    results = {}
    for name, mutate in (
        ('missing-row', 'drop'),
        ('multiple-equivalent', 'dup'),
        ('contradiction', 'wrong'),
    ):
        d = root / name
        shutil.copytree(base, d, ignore=shutil.ignore_patterns('*.prev.csv'))
        rows = list(csv.DictReader(open(d / 'calls.csv', encoding='utf-8')))
        hit = next((r for r in rows if r['listing'].startswith('code/native.asm#L28-')), None)
        if hit is None:
            raise SystemExit('self-test: no row for code/native.asm#L28')
        if mutate == 'drop':
            rows.remove(hit)
        elif mutate == 'dup':
            rows.insert(rows.index(hit), dict(hit))
        else:
            hit['callee'] = 'KERNEL32.dll!GetLastError'
        with open(d / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
            w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
            w.writeheader(); w.writerows(rows)
        out = d / 's65-self.csv'
        subprocess = __import__('subprocess')
        r = subprocess.run([sys.executable, '-B', 'tool/s65_counterexamples.py', '--folder', str(d), '--out', str(out)],
                           capture_output=True, text=True)
        cats = {}
        for row in csv.DictReader(open(out, encoding='utf-8')):
            cats[row['category']] = cats.get(row['category'], 0) + 1
        results[name] = (count := cats.get(name, 0))
        print('SELFTEST %-20s hits=%d %s' % (name, count, 'PASS' if count >= 1 else 'FAIL'))
    print('SELFTEST overall', 'PASS' if all(v >= 1 for v in results.values()) else 'FAIL')
    return 0 if all(v >= 1 for v in results.values()) else 1


if __name__ == '__main__':
    if '--self-test' in sys.argv:
        sys.exit(self_test())
    main()
