"""Recheck NATIVE-340 s17 against the original CLI/PE, including the whole .nep section."""
import argparse
import csv
import hashlib
import json
import re
import runpy
import struct
from collections import Counter
from pathlib import Path
import capstone
import pefile


def rows(path):
    with path.open(encoding='utf-8-sig', newline='') as stream:
        return list(csv.DictReader(stream))


def file_hash(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def review(original, unit, trusted, prior):
    data = original.read_bytes()
    digest = file_hash(original)
    assert digest == '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec'
    checker = trusted / 'assignments/check-native-coverage.py'
    records, pos, imagebase = runpy.run_path(str(checker))['inspect'](data)
    methods = {r['key']: r for r in records if r['kind'] == 'method'}
    pe = pefile.PE(data=data)
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
    table, size = struct.unpack_from('<II', data, pos(directory) + 48)
    slots = {}
    for i in range(table, table + size, 8):
        slot, count, flags = struct.unpack_from('<IHH', data, pos(i))
        assert count == 1 and flags & 2
        token, = struct.unpack_from('<Q', data, pos(slot))
        assert token in methods and slot not in slots
        slots[slot] = (token, flags)
    nep = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.nep')
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    block = pe.get_data(nep.VirtualAddress, nep.Misc_VirtualSize)
    insns = list(decoder.disasm(block, nep.VirtualAddress))
    assert sum(i.size for i in insns) == nep.Misc_VirtualSize
    direct_sites = set()
    fixups = {}
    for i in insns:
        b = bytes(i.bytes)
        if b.startswith(b'\xff\x25'):
            assert i.mnemonic == 'jmp' and i.size == 6
            slot = i.address + 6 + struct.unpack_from('<i', b, 2)[0]
            token, flags = slots[slot]
            fixups[i.address] = (b, slot, token, flags)
        elif b == b'\xeb\x08':
            direct_sites.add(i.address + 10)
        else:
            assert b in (b'\x0f\x0b', b'\xcc')
    assert len(fixups) == len(slots) == len({r[1] for r in fixups.values()}) == 237
    assert direct_sites <= fixups.keys()
    assigned = {int(r['site_rva'], 0): r for r in rows(trusted / 'outbox/NATIVE-340/s5-native-fixup-targets.csv')}
    declared = {int(r['site_rva'], 0): r for r in rows(unit / 'code/fixup-targets.csv')}
    assert assigned.keys() == declared.keys()
    calls = rows(unit / 'calls.csv')
    files = {f: (unit / f).read_text(encoding='utf-8').splitlines()
             for f in ['code/native-fixup-sites.asm', 'code/native.asm', 'code/newobj-sites.il']}
    native_call_sites = {}
    for r in calls:
        if r['kind'] != 'native': continue
        file, start, end = re.fullmatch(r'(.+)#L(\d+)-L(\d+)', r['listing']).groups()
        if file not in files or start != end: continue
        line = files[file][int(start)-1]
        match = re.match(r'\s*([0-9A-Fa-f]{8})\s+', line)
        if match and int(match[1],16) in fixups:
            site = int(match[1],16)
            assert site not in native_call_sites
            native_call_sites[site] = (r, line)
    for site in assigned:
        b, slot, token, flags = fixups[site]
        for row in [assigned[site], declared[site]]:
            assert [int(row[k],0) for k in ['fixup_slot_rva','method_token','flags','method_rva']] == [slot,token,flags,methods[token]['rva']]
        call, line = native_call_sites[site]
        assert b.hex(' ').upper() in line.upper() and f'0x{imagebase+slot:x}' in line.lower()
        target = call['callee'].lower()
        assert call['class'] == 'boundary' and int(call['caller'],0) == site and f'0x{slot:x}' in target and f'0x{token:08x}' in target and f"0x{methods[token]['rva']:x}" in target
    cov = rows(unit/'coverage.csv')
    covered_stubs = {int(r['key'],0) for r in cov if r['source'].startswith('code/native-fixup-sites.c#') and r['state']=='covered'}
    stub_c = (unit/'code/native-fixup-sites.c').read_text(encoding='utf-8')
    c_clean = re.sub(r'/\*.*?\*/','',stub_c,flags=re.S)
    empty = {int(k,16) for k in re.findall(r'void fixup_stub_([0-9A-Fa-f]+)\(void\)\s*\{\s*\}', c_clean)}
    assert covered_stubs == empty and len(empty) == 122
    constructors = rows(unit/'code/newobj.csv')
    external = {}
    for r in calls:
        if r['listing'].startswith('code/newobj-sites.il#'):
            assert r['kind']=='method' and r['class']=='external'
            n = int(re.search(r'#L(\d+)',r['listing'])[1])
            listed = files['code/newobj-sites.il'][n-1]
            token = int(re.search(r'newobj\s+(0x[\da-f]+)',listed,re.I)[1],0)
            offset = int(re.search(r'IL_([\da-f]+)',listed,re.I)[1],16)
            caller = int(r['caller'],0)
            assert f'0x{token:08x}' in r['callee'].lower() and f'0x{caller:08x}' in files['code/newobj-sites.il'][n-2].lower()
            external[caller,offset] = token
    for r in constructors:
        caller, token = (int(r[key],0) for key in ('caller_token','token'))
        off = int(r['il_offset'][3:],16)
        body = pos(methods[caller]['rva'])
        h = 1 if data[body]&3 == 2 else (struct.unpack_from('<H',data,body)[0]>>12)*4
        assert struct.unpack_from('<BI',data,body+h+off)==(0x73,token)
        if r['verdict']=='external-ctor': assert external[caller,off]==token
        else: assert (caller,off) not in external and methods[token]['name']=='.ctor'
    prior_calls = rows(prior/'calls.csv')
    assert all(r in calls for r in prior_calls if r['class']=='boundary')
    extra = []
    for site in sorted(fixups.keys()-assigned.keys()):
        b,slot,token,flags=fixups[site]
        extra.append(dict(site=hex(site), instruction=b.hex(), slot=hex(slot), flags=hex(flags),
                          method=f'0x{token:08x}', method_rva=hex(methods[token]['rva']),
                          direct_jump_target=site in direct_sites,
                          candidate_class=native_call_sites[site][0]['class'] if site in native_call_sites else 'missing'))
    metrics=json.loads((unit/'metrics.json').read_text(encoding='utf-8'))
    assert all(file_hash(unit/f)==metrics[k] for f,k in [('calls.csv','calls_sha256'),('coverage.csv','coverage_sha256'),('native-functions.csv','native_functions_sha256')])
    return dict(original_sha256=digest, checker_sha256=file_hash(checker), head='5671a75cd2ec9e5b9d1ca1ec09bbafa321700f13',
                nep_size=len(block), nep_slot_jumps=len(fixups), nep_direct_jumps=len(direct_sites),
                distinct_methods=len({r[2] for r in fixups.values()}), assigned_verified=len(assigned), extra_sites=len(extra),
                extra_disposition=dict(Counter(r['candidate_class'] for r in extra)), extra_direct_targets=sum(r['direct_jump_target'] for r in extra),
                stubs_marked_covered_with_empty_c=len(empty), calls=dict(Counter(r['class'] for r in calls)),
                residual_by_kind=dict(Counter(r['kind'] for r in calls if r['class']=='unresolved')),
                prior_boundary_preserved=sum(r['class']=='boundary' for r in prior_calls),
                original_newobj=len(constructors), external_call_rows_verified=len(external), internal_ctors=len(constructors)-len(external),
                metrics_stubs_added=metrics['fixup_stubs_added'],metrics_coverage_added=metrics['coverage_added'],
                extra_site_evidence=extra)


if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for arg in ['original','unit','trusted','prior']:
        parser.add_argument(arg,type=Path)
    print(json.dumps(review(**vars(parser.parse_args())), indent=2))
