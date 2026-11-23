from pathlib import Path
import csv, hashlib, json, os, shutil, subprocess, sys
from collections import Counter
out = Path(__file__).resolve().parent
fixed = out.parent / "fixed"
repo = out.parents[3]
unit = fixed / "handoff/inbox/NATIVE-337"
deps = repo / ".local/patrol-1329/review337/deps"
sys.path.insert(0,str(deps))
import capstone, pefile
def digest(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def rows(p): return list(csv.DictReader(p.open(encoding="utf-8-sig",newline="")))
src = Path(os.environ["ProgramFiles"]) / "AspenTech/AprSystem V15.0/GUI/Xeq/FindComponent.dll"
pe=pefile.PE(str(src))
assert digest(src)=="3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
data=src.read_bytes()
dis=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
def trace(start,size):
    return [f"{i.address:04x} {i.bytes.hex()} {i.mnemonic} {i.op_str}" for i in dis.disasm(pe.get_data(start,size), start)]
iat={hex(i.address-pe.OPTIONAL_HEADER.ImageBase):f"{d.dll.decode()}!{i.name.decode() if i.name else '#'+str(i.ordinal)}" for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
subtools=["tool/s65_counterexamples.py","tool/s73_stations.py","tool/pe_reader.py","tool/s37_two_hop.py","tool/s81_showdialog.py","tool/s69_tests.py"]
manifest=json.loads((out.parent/"fixed-manifest.json").read_bytes())
records=next(v for v in manifest.values() if isinstance(v,list) and v and isinstance(v[0],dict) and "sha256" in v[0] and "path" in v[0] and len(v)>20)
pins={r["path"]:r["sha256"] for r in records}
assert all(digest(fixed/s)==pins[s] for s in subtools)
assert pe.get_data(0x82f8,16)==bytes(16)
assert pe.get_data(0x8308,16).hex()=="0004020000000000c000000000000046"
report={"python":sys.version,"capstone":capstone.__version__,"pefile":pefile.__version__,"main":"6f39d81802e8d60331c0c6706f192ae7d45ac52a","head":manifest["head"],"prior":manifest["prior"],"original_sha256":digest(src),"tools":{s:pins[s] for s in subtools},"showdialog_trace":trace(0x1320,0x163),"factory_trace":trace(0x2330,0xbf),"strings":{"0x78a8":pe.get_data(0x78a8,90).split(b"\0")[0].decode(),"0x7820":pe.get_data(0x7820,22).decode("utf-16-le").rstrip("\0")},"imports":{k:iat[k] for k in ("0x7060","0x70f0","0x70d0","0x7648","0x7650","0x75e0","0x75e8")},"cases":{}}
folder=out/"ordinal-control"
(folder/"code").mkdir(exist_ok=True,parents=True)
shutil.copyfile(unit/"code/native.asm",folder/"code/native.asm")
before=(unit/"calls.csv").read_bytes()
old=b"mfc140.dll!#2344,external,code/native.asm#L28-L28"
assert before.count(old)==1
(folder/"calls.csv").write_bytes(before.replace(old,old.replace(b"#2344",b"#2348")))
offset=pe.get_offset_from_rva(0x4aa3)
assert data[offset:offset+2]==b"\xff\x25"
mutated=out/"pair-input.bin"
mutated.write_bytes(data[:offset+1]+b"\x05"+data[offset+2:])
report["pe_pair"]={"jump":trace(0x4aa3,6),"inc":[f"{i.address:04x} {i.bytes.hex()} {i.mnemonic} {i.op_str}" for i in dis.disasm(mutated.read_bytes()[offset:offset+6],0x4aa3)],"inc_sha256":digest(mutated)}
env={**os.environ,"PYTHONPATH":str(deps),"PYTHONDONTWRITEBYTECODE":"1"}
for case,binary,delivery in (("original",src,unit),("ordinal",src,folder),("inc",mutated,unit)):
    log={}
    for tool,args in (("stations",["tool/s73_stations.py","--csv",str(out/(case+"-stations.csv")),"--json",str(out/(case+"-stations.json"))]),("classify",["tool/s65_counterexamples.py","--folder",str(delivery),"--out",str(out/(case+"-classified.csv"))])):
        command=[sys.executable,"-B",*args,"--binary",str(binary)]
        run=subprocess.run(command,cwd=fixed,env=env,check=True,capture_output=True,text=True)
        log[tool]={"command":subprocess.list2cmdline(command),"exit":run.returncode,"stdout":run.stdout.strip()}
    stations=rows(out/(case+"-stations.csv"))
    classified=rows(out/(case+"-classified.csv"))
    log.update({"counts":[len(stations),dict(Counter(r["category"] for r in classified))],"first_by_station":[r for r in stations if r["first_hop"]=="0x4AA3"],"first_by_classifier":[r for r in classified if r["first_hop"]=="0x4AA3"]})
    report["cases"][case]=log
(out/"result.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")
for case,results in report["cases"].items(): print(case,results["counts"],[(r["site"],r["category"]) for r in results["first_by_classifier"]])
