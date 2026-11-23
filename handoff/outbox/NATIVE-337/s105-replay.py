"""Recheck NATIVE-337 s105 using only a candidate tree, trusted main checker, original, live metadata and a new output directory."""
import csv
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
from collections import Counter
checker,fixed,original,live,out=map(lambda x:Path(x).resolve(),sys.argv[1:])
unit=fixed/'handoff/inbox/NATIVE-337'
listing,reg,table,manifest='code/native.asm','s97-registration.json','code/s81-showdialog.csv','s105-fingerprints.json'
checker_file=fixed/'tool/s101_verify.py'
generator=fixed/'tool/s81_showdialog.py'
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def document(p):return json.loads(p.read_bytes())
def write(p,x):p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def run(*args):
    r=subprocess.run([sys.executable,'-B',*map(str,args)],capture_output=True,text=True,encoding='utf8',errors='replace',cwd=fixed)
    return {'exit':r.returncode,'stdout':r.stdout.strip(),'stderr':r.stderr.strip()}
def csv_rows(p):
    with p.open(encoding='utf-8-sig',newline='') as f:return list(csv.DictReader(f))
def replace(p,a,b):
    d=p.read_bytes()
    assert d.count(a)==1
    p.write_bytes(d.replace(a,b))
def operate(doc,case):
    impl=doc['FindComponentDriver'];iface=doc['IFindComponentDriver']
    if case=='equivalent-json-layout':return
    if case=='missing-relation':impl['interfaces'].remove('IFindComponentDriver')
    elif case=='false-interface-rva':iface['methods'][0]['rva']='1'
    elif case=='false-pe-sha':doc['PE']['sha256']='0'+doc['PE']['sha256'][1:-1]+'4'
    else:
        fld,val={'impl-name':('name','ShowOtherX'),'impl-rva':('rva','A849'),'impl-signature':('signature','2001090E')}[case]
        impl['methods'][0][fld]=val
assert digest(original)=='3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02'
assert digest(checker)=='27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8'
assert digest(checker_file)=='57d8cdeec3d3369a32d2c86279df8b0a6c7edea7910081efc273b4bdd7a0215a'
assert digest(fixed/'tool/pe_reader.py')=='5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367'
assert digest(generator)=='efc2a76909c2b8950c4eb1213cc460e1afa4c04227c1799c8c75648f75d8ef55'
assert live.read_bytes()==(unit/reg).read_bytes()
out.mkdir(parents=True,exist_ok=True)
base=document(unit/manifest)
unit_files={p.relative_to(unit).as_posix() for p in unit.rglob('*') if p.is_file()}
def mismatch(root,records):return {p:[h,digest(root/p) if (root/p).is_file() else None] for p,h in records.items() if not (root/p).is_file() or h!=digest(root/p)}
bad=mismatch(unit,base); assert not bad,bad
cases={}
for case,expected in [('baseline','accept'),('equivalent-json-layout','accept'),('vt-listing','locate 0x13DD'),('riid-listing','locate 0x137F'),('impl-signature','locate signature'),('impl-name','locate name'),('impl-rva','locate rva'),('table-signature','locate signature'),('missing-attachment','name missing registration'),('missing-relation','locate missing implemented interface'),('false-interface-rva','locate interface RVA'),('false-pe-sha','locate deployment PE identity conflict'),('table-rva-prefix','locate exact delivered RVA')]:
    folder=out/case;shutil.copytree(unit,folder);changed=reg
    src=folder/reg
    if case=='baseline':changed=None
    elif case.startswith('table-'):
        changed=table
        a,b=(b'id-sig-impl,registration,2001080E',b'id-sig-impl,registration,2001090E') if case=='table-signature' else (b'rva 0xA848"',b'rva 0xA8480"')
        replace(folder/table,a,b)
    elif case in ('vt-listing','riid-listing'):
        changed=listing
        a,b=(b'000013DD  B8 08 00 00 00',b'000013DD  B8 03 00 00 00') if case=='vt-listing' else (b'0000137F  48 8D 15 72 6F 00 00',b'0000137F  48 8D 15 82 6F 00 00')
        replace(folder/listing,a,b)
    elif case=='missing-attachment':src.unlink()
    else:
        doc=document(src);operate(doc,case)
        src.write_text(json.dumps(doc,sort_keys=case=='equivalent-json-layout',indent=2,ensure_ascii=False)+'\n',encoding='utf8')
    h=dict(base)
    if changed:
        if (folder/changed).exists():h[changed]=digest(folder/changed)
        else:h.pop(changed)
        write(folder/manifest,h)
        assert not mismatch(folder,h)
    change={n for n in unit_files if not (folder/n).is_file() or digest(unit/n)!=digest(folder/n)}
    assert change==({changed,manifest} if changed else set()),(case,change)
    pre=digest(folder/changed) if changed and (folder/changed).exists() else None
    result=run(checker_file,'--binary',original,'--folder',folder,'--listing','--signature')
    assert not mismatch(folder,h)
    cases[case]=dict(expected=expected,actual=result,changed=changed,baseline_sha256=digest(unit/changed) if changed else None,changed_sha256=pre,activity_manifest_sha256=digest(folder/manifest))
generated=out/'regenerated.csv'
g=run(generator,'--binary',original,'--folder',unit,'--out',generated)
assert g['exit']==0 and generated.read_bytes()==(unit/table).read_bytes()
rows=csv_rows(generated)
# Map the native x64 PE section containing the loop directly; read raw bytes independently of candidate tools.
b=original.read_bytes(); pe=struct.unpack_from('<I',b,60)[0];sect=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sec=next((rva,raw) for rva,n,raw in (struct.unpack_from('<III',b,sect+i*40+12) for i in range(struct.unpack_from('<H',b,pe+6)[0])) if rva<=0x13c0<rva+n)
def octets(a,l):
    v,o=sec;j=o+a-v;return b[j:j+l].hex()
loop={hex(a):octets(a,l) for a,l in [(0x13c2,4),(0x13c6,5),(0x13cb,4),(0x13cf,6),(0x13dd,5),(0x13e2,5),(0x13e7,5)]}
old=document(unit/'s101-fingerprints.json')
report=dict(head='8a261635459e2e862b034ed3fd3a6d02dcc10dd9',main='44c22e3daac712802e8a7e865a42c301f70b714b',task='NATIVE-337',pr=445,original_sha256=digest(original),checker_sha256=digest(checker),tools_sha256={p.name:digest(p) for p in [checker_file,fixed/'tool/pe_reader.py',generator,fixed/'tool/s105_counters.py']},fresh_evidence_sha256=digest(live),live_pe=document(live)['PE'],live_implements=document(live)['FindComponentDriver']['interfaces'],current_manifest={'count':len(base),'sha256':digest(unit/manifest),'unit_files':len(unit_files),'excluded':sorted(unit_files-set(base)),'mismatches':bad},old_manifest={'count':len(old),'mismatches':mismatch(unit,old),'work/s101-gate.txt':{'declared':old.get('work/s101-gate.txt'),'actual':digest(unit/'work/s101-gate.txt')}},calls=dict(Counter(x['class'] for x in csv_rows(unit/'calls.csv'))),coverage=run(checker,'NATIVE-337','--original',original,'--submission',unit),generator=dict(exit=g['exit'],table_matched=True,sha256=digest(generated),rows=len(rows),variant_vt_rows=sum(r['item']=='variant-vt' for r in rows)),loop_bytes=loop,cases=cases)
write(out/'s105-recheck.json',report)
for name,data in cases.items():print(name, data['actual']['exit'],data['actual']['stdout'].replace('\n',' | '))
print(report['coverage'],report['old_manifest'],report['generator'], report['calls'])
