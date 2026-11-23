"""Static controls on pinned paths. Outputs JSON to stdout. Needs pefile."""
import csv, hashlib, importlib.util, io, json, re, shutil, struct, subprocess, sys
from pathlib import Path
from tempfile import TemporaryDirectory
import pefile

def sha(b):
    return hashlib.sha256(b).hexdigest()

def load(path,name):
    spec=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m

def run(*args):
    r=subprocess.run([sys.executable,"-B",*map(str,args)],capture_output=True,encoding="utf8",errors="replace")
    return dict(exit=r.returncode,stdout=r.stdout.strip(),stderr=r.stderr.strip())

def change(raw,a,b):
    assert raw.count(a)==1,a
    return raw.replace(a,b)

def main():
    C,P,O,K,W,SDK=map(lambda x:Path(x).resolve(),sys.argv[1:])
    unit=C/"handoff/inbox/NATIVE-340"
    raw=O.read_bytes()
    assert sha(raw)=="869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    r=dict(head="9c949d3f2caa5e90a793e1976057418a0cf4f6be",parent="38b6814d15332a90258f2caa42169b6f52e5bad4",
           original=sha(raw),checker=sha(K.read_bytes()),strict_width_probe=sha(W.read_bytes()))
    c=load(C/"tool/cli_tables.py","cur")
    p=load(P/"tool/cli_tables.py","prev")
    builder=load(W,"fixture").metadata_fixture
    r["implmap"]=[]
    for tbl,count in [(4,1),(6,1),(4,16383),(4,16384),(6,32767),(6,32768)]:
        val=(count<<1)+(tbl==6)
        stream=builder({tbl:count,26:1,28:1},{tbl:bytes((6 if tbl==4 else 14)*count),26:bytes(2),28:struct.pack("<H",0)+struct.pack("<H" if count<32768 else "<I",val)+struct.pack("<HH",17,1)})
        row=c.read(stream,0)["rows"][28][0]
        want={"MemberForwarded":val,"ImportName":"MethodName","ImportScope":1}
        r["implmap"].append(dict(count=count,target=tbl,input_sha256=sha(stream),decoded=row["_decoded"]["MemberForwarded"],expected=want,
            observed=row,match=all(row[k]==v for k,v in want.items()) and row["_decoded"]["MemberForwarded"]==(tbl,count)))
    pe=pefile.PE(data=raw)
    clr=pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
    md=pe.get_offset_from_rva(struct.unpack("<I",pe.get_data(clr+8,4))[0])
    now=c.read(raw,md);past=p.read(raw,md)
    r["original_implmap"]=[(x["MemberForwarded"],x["_decoded"]["MemberForwarded"]) for x in now["rows"][28]]
    sdk=json.loads(SDK.read_bytes());assert sdk["sha256"]==sha(raw)
    kinds={"TypeDefinition":2,"TypeReference":1,"ModuleReference":26,"MethodDefinition":6,"TypeSpecification":27,"MemberReference":10}
    r["pe_reader"]={}
    for section,tbl,skey,ckey in [("refs",10,"parent","Class"),("cattrs",12,"type","Type")]:
        assert len(sdk[section])==len(now["rows"][tbl])
        r["pe_reader"][section]=dict(count=len(sdk[section]),mismatch=[i for i,(x,y) in enumerate(zip(sdk[section],now["rows"][tbl]),1) if (kinds[x[skey+"_kind"]],x[skey+"_rid"])!=y["_decoded"][ckey]])
    manifests={}
    r["fingerprints"]={}
    for name in ["s29","s101"]:
        obj=json.loads((unit/f"code/{name}-fingerprints.json").read_bytes())
        entries=obj.get("files",obj)
        manifests[name]=obj
        r["fingerprints"][name]={"count":len(entries),"mismatch":[p for p,h in entries.items() if sha((unit/p).read_bytes())!=h]}
    r["coverage"]=run(K,"NATIVE-340","--original",O,"--submission",unit)
    calls=(unit/"calls.csv").read_bytes();asm=(unit/"code/native.asm").read_bytes()
    r["metrics_calls"]=[json.loads((unit/"metrics.json").read_bytes())["calls_sha256"],sha(calls)]
    lines=asm.decode("utf-8-sig").splitlines()
    bounds={int(m[1],16):int(m[2],16) for s in lines if (m:=re.match(r"; FUNC ([0-9A-F]+)-([0-9A-F]+)",s))}
    imports={i.address-pe.OPTIONAL_HEADER.ImageBase:d.dll.decode()+"!"+(i.name.decode() if i.name else "#"+str(i.ordinal)) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    r["iat"]=[]
    for x in list(csv.DictReader(io.StringIO(calls.decode("utf-8-sig"))))[-19:]:
        n=int(x["listing"].split("#L")[1]);s=lines[n-1]
        m=re.fullmatch(r"([0-9A-F]+)  ([0-9A-F ]+?)  JMP qword ptr \[RIP\+(0x[0-9A-Fa-f]+|[0-9]+)\]",s)
        a=int(m[1],16);b=bytes.fromhex(m[2]);ref=pe.get_data(a,len(b))
        off=int.from_bytes(ref[-4:],"little",signed=True);slot=a+len(ref)+off
        caller=int(x["caller"],0)
        r["iat"].append(dict(line=n,site=hex(a),inside=caller<=a<bounds[caller],end=hex(bounds[caller]),pending="待核" in x["note"],bytes_match=b==ref,
           note_match=int(re.search(r"@0x([0-9A-Fa-f]+)",x["note"])[1],16)==a,disp_match=int(m[3],0)==off,symbol_match=x["callee"]==imports[slot]))
    with TemporaryDirectory(dir=Path.cwd()) as tmp:
        t=Path(tmp);sam=t/"handoff/inbox/NATIVE-340";shutil.copytree(unit,sam)
        (t/"tool").mkdir()
        args=["--original",O,"--baseline",t/"baseline.json"]
        (t/"baseline.json").write_text(json.dumps({"layout":past["layout"]}),encoding="utf8")
        r["layout"]=run(C/"tool/s101_layout_check.py",*args)
        r["sites"]=[]
        cases=[("relocated",None,None,None,0),("wrong_caller","calls.csv",b"native,0x2B74,KERNEL32.dll!GetModuleHandleW,",b"native,0x3660,KERNEL32.dll!GetModuleHandleW,",1),
           ("wrong_listing","calls.csv",b"#L1509,IAT thunk",b"#L1510,IAT thunk",1),
           ("wrong_listing_byte","code/native.asm",b"00004711  FF 25 E9",b"00004711  FF 25 EA",1),
           ("wrong_callee","calls.csv",b"0x3660,KERNEL32.dll!QueryPerformanceCounter,external,code/native.asm#L1509",b"0x3660,KERNEL32.dll!GetStartupInfoW,external,code/native.asm#L1509",1)]
        for label,sub,old,new,expect in cases:
            for file in ["calls.csv","code/native.asm","metrics.json","code/s29-fingerprints.json","code/s101-fingerprints.json"]:
                (sam/file).write_bytes((unit/file).read_bytes())
            if sub:
                (sam/sub).write_bytes(change((unit/sub).read_bytes(),old,new))
            for name in ["s29","s101"]:
                path=f"code/{name}-fingerprints.json"
                obj=json.loads((unit/path).read_bytes());d=obj.get("files",obj)
                for filename in d:
                    d[filename]=sha((sam/filename).read_bytes())
                (sam/path).write_text(json.dumps(obj,ensure_ascii=False,indent=1)+"\n",encoding="utf8")
            r["sites"].append(dict(case=label,expected=expect,input_sha256={f:sha((sam/f).read_bytes()) for f in ["calls.csv","code/native.asm","code/s29-fingerprints.json","code/s101-fingerprints.json"]},
                        **run(C/"tool/s97-site-owners.py",t)))
        r["width"]=[]
        for f in ["s101_width_fixtures.py","cli_tables.py"]:
            shutil.copyfile(C/"tool"/f,t/"tool"/f)
        parser=t/"tool/cli_tables.py"
        for label,mut in [("strict_intact",False),("force_actual_coded_read_width_to_two",True)]:
            if mut:
                data=parser.read_bytes()
                find=b'raw = int.from_bytes(data[off:off + width], "little")'
                parser.write_bytes(change(data,find,b'width = 2 if isinstance(column_spec(i,name),tuple) and column_spec(i,name)[0]=="coded" else width\n                '+find))
            ext=run(W,t)
            r["width"].append(dict(case=label,parser_sha256=sha(parser.read_bytes()),delivered=run(t/"tool/s101_width_fixtures.py"),
                           independent_exit=ext["exit"],fixtures=[{k:v for k,v in x.items() if k in ["table","target_count","input_sha256","match"]} for x in json.loads(ext["stdout"])]))
        tbl=unit/"code/s89-il-digests.csv"
        r["digest"]=[]
        for label,content in [("intact",tbl.read_bytes()),("wrong_one",None)]:
            if content is None:
                b=tbl.read_bytes();row=list(csv.DictReader(io.StringIO(b.decode("utf-8-sig"))))[66]
                assert b.count(row["sha256"].encode())==1
                content=b.replace(row["sha256"].encode(),b"0"*64)
            f=t/"digest.csv";f.write_bytes(content)
            r["digest"].append(dict(case=label,input_sha256=sha(content),**run(C/"tool/verify_il_digests.py","--binary",O,"--table",f)))
    print(json.dumps(r,ensure_ascii=False,indent=2))

if __name__=="__main__":
    main()
