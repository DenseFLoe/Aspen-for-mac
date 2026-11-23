"""Reproduce s101 checks; positional arguments: main checker, candidate root, original, fresh registration JSON, output directory."""
import csv
from collections import Counter
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys

checker,fixed,original,registration,out=(Path(p).resolve() for p in sys.argv[1:])
unit=fixed/'handoff/inbox/NATIVE-337'
listing='code/native.asm'
reg='s97-registration.json'
table='code/s81-showdialog.csv'
manifest='s101-fingerprints.json'
tools={n:fixed/'tool'/n for n in ('s101_verify.py','s81_showdialog.py','pe_reader.py')}
def digest(path):
    return sha256(path.read_bytes()).hexdigest()
def rows(path):
    with path.open(encoding='utf-8-sig',newline='') as stream:
        return list(csv.DictReader(stream))
def run(*args):
    p=subprocess.run([sys.executable,'-B',*map(str,args)],cwd=fixed,capture_output=True,text=True,encoding='utf8',errors='replace')
    return {'exit':p.returncode,'stdout':p.stdout.strip(),'stderr':p.stderr.strip()}
def write(path,obj):
    path.write_text(json.dumps(obj,indent=2,ensure_ascii=False)+'\n',encoding='utf8')
def edit(path,a,b):
    data=path.read_bytes()
    assert data.count(a)==1
    path.write_bytes(data.replace(a,b))
assert digest(original)=='3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02'
assert registration.read_bytes()==(unit/reg).read_bytes()
base=json.loads((unit/manifest).read_bytes())
bad={key:{'declared':h,'actual':digest(unit/key)} for key,h in base.items() if digest(unit/key)!=h}
paths={p.relative_to(unit).as_posix() for p in unit.rglob('*') if p.is_file()}
coverage=run(checker,'NATIVE-337','--original',original,'--submission',unit)
assert coverage['exit']==2
cases={}
for case,expected in [
    ('correct','accept'),
    ('equivalent-json-layout','accept'),
    ('vt-listing','refuse 0x13DD'),
    ('riid-listing','refuse 0x137F'),
    ('impl-signature','refuse implementation signature'),
    ('impl-name','refuse missing implementation ShowDialog'),
    ('impl-rva','refuse false implementation RVA'),
    ('missing-registration','refuse or record missing evidence'),
    ('delivered-table-signature','refuse contradiction between delivered table and source'),
]:
    folder=out/case
    shutil.copytree(unit,folder)
    path=folder/reg
    changed=reg
    if case=='equivalent-json-layout':
        path.write_text(json.dumps(json.loads(path.read_bytes()),sort_keys=True),encoding='utf8')
    elif case=='vt-listing':
        changed=listing
        edit(folder/listing,b'000013DD  B8 08 00 00 00',b'000013DD  B8 03 00 00 00')
    elif case=='riid-listing':
        changed=listing
        edit(folder/listing,b'0000137F  48 8D 15 72 6F 00 00',b'0000137F  48 8D 15 82 6F 00 00')
    elif case in ('impl-signature','impl-name','impl-rva'):
        split=b'"FindComponentDriver": {'
        prefix,impl=path.read_bytes().split(split)
        a,b={'impl-signature':(b'2001080E',b'2001090E'),'impl-name':(b'ShowDialog',b'ShowOtherX'),'impl-rva':(b'A848',b'A849')}[case]
        assert impl.count(a)==1
        path.write_bytes(prefix+split+impl.replace(a,b))
    elif case=='missing-registration':
        path.unlink()
    elif case=='delivered-table-signature':
        changed=table
        edit(folder/table,b'id-sig-impl,registration,2001080E',b'id-sig-impl,registration,2001090E')
    document=dict(base)
    if case!='correct':
        if (folder/changed).exists(): document[changed]=digest(folder/changed)
        else: document.pop(changed)
        write(folder/manifest,document)
    assert {k for k,h in document.items() if digest(folder/k)!=h}==set(bad)
    result=run(tools['s101_verify.py'],'--binary',original,'--folder',folder,'--listing','--signature')
    generated=folder/'generated.csv'
    generator=run(tools['s81_showdialog.py'],'--binary',original,'--folder',folder,'--out',generated)
    assert generator['exit']==0
    records=rows(generated)
    cases[case]={'expected':expected,'actual':result,'manifest_sha256':digest(folder/manifest),'listing_sha256':digest(folder/listing),'registration_sha256':digest(path) if path.exists() else None,'table_sha256':digest(folder/table),'generated_sha256':digest(generated),'generated_matches_delivered':generated.read_bytes()==(folder/table).read_bytes(),'changed_input':changed if case!='correct' else None,'rows':len(records),'variant_vt_rows':sum(r['item']=='variant-vt' for r in records)}
record=json.loads(registration.read_bytes())
report={'head':'fa42db6e13211e2587134c447ec8ce00457560dc','main':'263497c50f7a59ea343f2cf80ba41a168dce7af1','prior':'ff5aa8a36cfe444e9f540414b59a2bd1b441c680','pr':445,'task':'NATIVE-337','original_sha256':digest(original),'checker_sha256':digest(checker),'tools_sha256':{k:digest(v) for k,v in tools.items()},'coverage':coverage,'call_classes':dict(Counter(r['class'] for r in rows(unit/'calls.csv'))),'manifest':{'matched':len(base)-len(bad),'declared_paths':len(base),'mismatches':bad,'sha256':digest(unit/manifest),'unit_paths':len(paths),'excluded':sorted(paths-set(base))},'registration':{'fresh_matches_candidate':True,'sha256':digest(registration),'deployment':record['PE'],'verified_methods':{k:record[k]['methods'] for k in ('IFindComponentDriver','FindComponentDriver')},'implemented_interfaces':record['FindComponentDriver']['interfaces']},'baseline_table':{r['item']:r['meaning'] for r in rows(unit/table) if r['item'] in {'variant-vt','variant-init','id-sig-impl'}},'controls':cases}
write(out/'s101-recheck.json',report)
print(coverage,report['manifest'])
for k,v in cases.items():print(k,v['actual']['exit'],v['generated_matches_delivered'],v['actual']['stdout'].splitlines()[:2])
