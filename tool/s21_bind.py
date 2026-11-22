# -*- coding: utf-8 -*-
"""s21: bind 161 caller->thunk->IAT two-hop calls into the main table; fill 8 owners; COM slots."""
import csv, json, re, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tool'))
from pe_reader import PE, parse_asm

FOLDER = Path('handoff/inbox/NATIVE-337')
data = open('_t13/orig/FindComponent.dll', 'rb').read()
pe = PE(data)
iat = pe.iat()
_, insns = parse_asm(str(FOLDER / 'code' / 'native.asm'))
addr2 = {a: (ln, b, t) for (ln, a, b, t, _) in insns}
funcs = []
for line in open(FOLDER / 'code' / 'native.asm', encoding='utf-8'):
    m = line.split()
    if line.startswith('; FUNC') and len(m) >= 4:
        lo, hi = m[2].split('-'); funcs.append((int(lo, 16), int(hi, 16), m[3]))
def owner(a):
    o = next(((lo, hi, n) for lo, hi, n in funcs if lo <= a < hi), None)
    return ('0x%X' % o[0], o[2]) if o else ('', '')

# 1) 161 two-hop rows
callers = list(csv.DictReader(open(FOLDER / 'code' / 'import-callers.csv', encoding='utf-8')))
calls = list(csv.DictReader(open(FOLDER / 'calls.csv', encoding='utf-8')))
have = {(r['kind'], r['caller'], r['listing']) for r in calls}
added = 0
two = []
for r in callers:
    rva = int(r['rva'], 16)
    own, name = owner(rva)
    r['owner'] = own
    r['site_text'] = addr2[rva][2] if rva in addr2 else ''
    r['in_candidate'] = 'yes' if rva in addr2 else 'no'
    two.append(r)
    if rva in addr2 and own:
        ln = addr2[rva][0]
        listing = 'code/native.asm#L%d-L%d' % (ln, ln)
        if ('native', own, listing) in have:
            continue
        calls.append(dict(kind='native', caller=own, callee=r.get('detail', '').split(' -> ')[-1] or 'IAT', **{'class': 'external'},
                          listing=listing,
                          note='二跳：调用方→跳板→IAT；%s' % (r.get('detail') or '')))
        have.add(('native', own, listing))
        added += 1
with open(FOLDER / 'code' / 's21-two-hop.csv', 'w', newline='', encoding='utf-8') as fh:
    w = csv.DictWriter(fh, fieldnames=list(two[0].keys())); w.writeheader(); w.writerows(two)

# 2) COM slots
com = list(csv.DictReader(open(FOLDER / 'code' / 'dispatch-sites.csv', encoding='utf-8')))
bound = 0
for r in com:
    m = re.search(r'slot (0x[0-9a-fA-F]+)', r.get('detail') or '')
    r['slot_index'] = m.group(1) if m else ''
    table = {'0x00': 'IUnknown::QueryInterface', '0x08': 'IUnknown::AddRef', '0x10': 'IUnknown::Release',
             '0x18': 'IDispatch::GetTypeInfoCount', '0x20': 'IDispatch::GetTypeInfo',
             '0x28': 'IDispatch::GetIDsOfNames', '0x30': 'IDispatch::Invoke'}
    member = table.get(r['slot_index'], '')
    r['member'] = member
    r['impl_address'] = ''
    if member:
        bound += 1
with open(FOLDER / 'code' / 's21-com-binding.csv', 'w', newline='', encoding='utf-8') as fh:
    w = csv.DictWriter(fh, fieldnames=list(com[0].keys())); w.writeheader(); w.writerows(com)

# 3) instruction status for the 36 diff entries
diff = json.load(open('out/s17-instruction-diff.json'))
present = set(addr2)
status = []
for rva, byt, mn, ops in diff['missing_from_fixed_s5_listing']:
    a = int(rva, 16)
    o, name = owner(a)
    status.append(dict(rva=rva, bytes=byt, mnemonic=mn, operands=ops, in_candidate=('yes' if a in present else 'no'),
                       owner=o, owner_name=name,
                       kind=('padding' if mn in ('int3', 'nop') else 'non-padding'),
                       status=('listed' if a in present else 'not-listed')))
with open(FOLDER / 'code' / 's21-instruction-status.csv', 'w', newline='', encoding='utf-8') as fh:
    w = csv.DictWriter(fh, fieldnames=list(status[0].keys())); w.writeheader(); w.writerows(status)

# 4) write calls
with open(FOLDER / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
    w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
    w.writeheader(); w.writerows(calls)
non = [x for x in status if x['kind'] == 'non-padding']
print('two-hop rows %d, added %d calls, calls now %d' % (len(two), added, len(calls)))
print('owners filled: %d/%d' % (sum(1 for r in two if r['owner']), len(two)))
print('COM bound %d/%d' % (bound, len(com)))
print('instructions: total %d, non-padding %d, listed %d' % (len(status), len(non), sum(1 for x in non if x['in_candidate'] == 'yes')))
