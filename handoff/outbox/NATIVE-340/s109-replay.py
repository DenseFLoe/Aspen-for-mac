"""Independent s109 replay. Arguments: fixed candidate, original, main coverage, s105 replay, s93 independent widths, QA root."""
import csv
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import pefile

def load(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def run(cwd, *args):
    p = subprocess.run([sys.executable, "-B", *map(str,args)], cwd=cwd, capture_output=True,
                       encoding="utf8", errors="replace")
    return dict(exit=p.returncode, stdout=p.stdout.strip(), stderr=p.stderr.strip())

def main():
    candidate, original, checker, previous, widths, qa = (Path(x).resolve() for x in sys.argv[1:])
    prev = load(previous, "s105")
    fixture = load(widths, "width_fixture")
    unit_rel = Path("handoff/inbox/NATIVE-340")
    unit = candidate / unit_rel
    pe = pefile.PE(data=original.read_bytes())
    assert digest(original) == prev.ORIGINAL_SHA and digest(checker) == prev.CHECKER_SHA
    receipt = (unit / "s109-submission.md").read_text("utf8")
    scripts = re.findall(r"^\| (tool/[^ |]+) \| ([0-9,]+) B \| ([0-9a-f]{64}) \|", receipt,re.M)
    manifests = tuple(f"code/s{n}-fingerprints.json" for n in (29,101,105,109))
    out = dict(original_sha256=digest(original), checker_sha256=digest(checker), receipt_sha256=digest(unit/"s109-submission.md"),
        script_rows=[dict(path=p, declared=h, bytes=int(s.replace(",","")), observed=digest(candidate/p),
                     match=h==digest(candidate/p) and int(s.replace(",",""))==(candidate/p).stat().st_size) for p,s,h in scripts],
        manifests={n:prev.manifest(unit,n) for n in manifests}, sites=prev.native_evidence(unit, pe))
    metrics=json.loads((unit/"metrics.json").read_bytes())
    out["metrics"]={n:{"observed":digest(unit/n),"declared":metrics[k]} for n,k in (
        ("calls.csv","calls_sha256"),("coverage.csv","coverage_sha256"),("native-functions.csv","native_functions_sha256"))}
    out["summary"]={k:metrics[k] for k in ("rows","funcs","external","boundary","data","unresolved","gaps")}
    out["main"]=run(candidate,checker,"NATIVE-340","--original",original,"--submission",unit)
    out["il"]=run(candidate,candidate/"tool/verify_il_digests.py","--binary",original,"--table",unit/"code/s89-il-digests.csv")
    cli=load(candidate/"tool/cli_tables.py","candidate_cli")
    out["implmap"]=[]
    for table,count in ((4,1),(6,1),(4,16383),(4,16384),(6,32767),(6,32768)):
        rid=(count<<1)+(table==6)
        row=bytes(2)+struct.pack("<H" if count<32768 else "<I",rid)+struct.pack("<HH",17,1)
        data=fixture.metadata_fixture({table:count,26:1,28:1},{table:bytes((6 if table==4 else 14)*count),26:bytes(2),28:row})
        observed=cli.read(data,0)["rows"][28][0]
        out["implmap"].append(dict(table=table,count=count,fixture_sha256=hashlib.sha256(data).hexdigest(),
             match=(observed["MemberForwarded"],observed["ImportName"],observed["ImportScope"],observed["_decoded"]["MemberForwarded"])==(rid,"MethodName",1,(table,count))))
    with TemporaryDirectory(dir=Path.cwd()) as scratch:
        root=Path(scratch)
        work=root/unit_rel
        shutil.copytree(unit,work)
        shutil.copytree(candidate/"tool",root/"tool")
        orig_path=root/"_t13/orig/WrapSaveMergeNNFiles.dll"
        orig_path.parent.mkdir(parents=True)
        shutil.copyfile(original,orig_path)
        site=candidate/"tool/s109-l1509-check.py"
        site_orig=candidate/"tool/s105-site-evidence.py"
        out["qa_command"]=["python","-B","-m","qa.gate","--task","NATIVE-340","--item-dir","ITEM","--original","ORIGINAL","--l1-path","CHECKER"]
        q=run(qa,"-m","qa.gate","--task","NATIVE-340","--item-dir",unit,"--original",original,"--l1-path",checker,"--json",root/"qa.json")
        if (root/"qa.json").exists():
            gate=json.loads((root/"qa.json").read_bytes())
            out["qa"]={"exit":q["exit"],"units":gate["units"],"stdout":q["stdout"],"stderr":q["stderr"],
                       "checks":{k:{"state":v.get("state",v.get("status")),"hits":v.get("hits",[]),"stats":v.get("stats",{})} for k,v in gate["l2"].items()}}
        else:
            out["qa"]=q
        listing=b"0x3660,KERNEL32.dll!QueryPerformanceCounter,external,code/native.asm#L1509"
        out["controls"]=[]
        for label,p,old,new in (
            ("relocated",None,None,None),
            ("display_disp","code/native.asm",b"00004711  FF 25 E9 18 00 00  JMP qword ptr [RIP+0x18E9]",b"00004711  FF 25 E9 18 00 00  JMP qword ptr [RIP+0x18E8]"),
            ("callee_suffix","calls.csv",listing,listing.replace(b"Counter",b"Counter_x")),
            ("missing_ref","calls.csv",listing,listing.replace(b"code/native.asm#L1509",b"")),
            ("missing_file_same_line","calls.csv",listing,listing.replace(b"code/native.asm",b"bad/native.asm")),
            ("end_plus_six","code/native.asm",b"; FUNC 00004777-0000477D _CxxThrowException",b"; FUNC 00004777-00004783 _CxxThrowException"),
        ):
            for name in (*manifests,"metrics.json","calls.csv","code/native.asm"):
                shutil.copyfile(unit/name,work/name)
            if p:
                path=work/p
                assert path.read_bytes().count(old)==1
                path.write_bytes(path.read_bytes().replace(old,new))
                if p=="calls.csv":
                    meta=dict(metrics,calls_sha256=digest(path))
                    (work/"metrics.json").write_text(json.dumps(meta,ensure_ascii=False,indent=1)+"\n",encoding="utf8")
                for m in manifests:
                    prev.refresh(work,m)
            ctrl=dict(case=label, input_sha256={n:digest(work/n) for n in (*manifests,"metrics.json","calls.csv","code/native.asm")},
                      site=run(root,site,root,"--original",original), all_sites=run(root,site_orig,root,"--original",original),
                      main=run(root,checker,"NATIVE-340","--original",original,"--submission",work))
            if label in ("relocated","end_plus_six"):
                ctrl["end_relation"]=next(row for row in prev.native_evidence(work,pe) if row["site"]=="0x477d")
            out["controls"].append(ctrl)
        out["read_controls"]=[]
        for broken in (False,True):
            parser=root/"tool/cli_tables.py"
            if broken:
                raw=parser.read_bytes()
                line=b'raw = int.from_bytes(data[off:off + width], "little")'
                assert raw.count(line)==1
                parser.write_bytes(raw.replace(line,b'width = 2 if isinstance(column_spec(i,name),tuple) and column_spec(i,name)[0]=="coded" else width\n                '+line))
            ind=run(root,widths,root)
            out["read_controls"].append(dict(forced_coded_two_bytes=broken,parser_sha256=digest(parser),
               original_stride=run(root,root/"tool/s109-read-mutate.py"), delivery_width=run(root,root/"tool/s101_width_fixtures.py"),
               independent_exit=ind["exit"], independent=json.loads(ind["stdout"])))
    print(json.dumps(out,ensure_ascii=False,indent=2))

if __name__=="__main__":
    main()
