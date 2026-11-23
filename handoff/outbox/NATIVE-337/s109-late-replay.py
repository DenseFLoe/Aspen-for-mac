"""Recheck NATIVE-337 s109 against the fixed original and a locally obtained registration record."""
import csv
from fnmatch import fnmatchcase
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys

HEAD="3f789d66013e3f1c171a224bf8ac2f9f96ac086f"
MAIN="19f94421ea3b724df2b27f65f71832db0259f34d"
ORIG_SHA="3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
CHECKER_SHA="27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
REG="s97-registration.json"
TABLE="code/s81-showdialog.csv"
LISTING="code/native.asm"
MANIFEST="s109-fingerprints.json"


def hexsum(path):
    return sha256(path.read_bytes()).hexdigest()


def json_file(path):
    return json.loads(path.read_bytes())


def save(path,data):
    path.write_text(json.dumps(data,indent=2,ensure_ascii=False)+"\n",encoding="utf-8",newline="\n")


def run(fixed,*args):
    proc=subprocess.run([sys.executable,"-B",*map(str,args)],cwd=fixed,capture_output=True,
                        text=True,encoding="utf-8",errors="replace")
    return dict(exit=proc.returncode,stdout=proc.stdout,stderr=proc.stderr)


def replace(path, old, new):
    raw=path.read_bytes()
    assert raw.count(old)==1,(path,old)
    path.write_bytes(raw.replace(old,new))


def mutate(folder,name):
    if name in {"baseline","no-binary"}:
        return None
    if name.startswith("table-"):
        target=folder/TABLE
        if name=="table-rva":
            replace(target,b'rva 0xA848"',b'rva 0xA8480"')
        elif name=="table-sig":
            replace(target,b"id-sig-impl,registration,2001080E",b"id-sig-impl,registration,2001090E")
        else:
            data=target.read_bytes()
            line=next(line for line in data.splitlines(keepends=True) if line.startswith(b"id-sig-impl,"))
            replace(target,line,line.replace(b"2001080E",b"2001090E")+line)
        return TABLE
    if name.endswith("-listing"):
        if name=="vt-listing":
            replace(folder/LISTING,b"000013DD  B8 08 00 00 00",b"000013DD  B8 03 00 00 00")
        else:
            replace(folder/LISTING,b"0000137F  48 8D 15 72 6F 00 00",b"0000137F  48 8D 15 82 6F 00 00")
        return LISTING
    target=folder/REG
    if name=="missing-attachment":
        target.unlink()
        return REG
    data=json_file(target)
    method=data["FindComponentDriver"]["methods"][0]
    iface=data["IFindComponentDriver"]
    if name=="missing-edge":
        data["FindComponentDriver"]["interfaces"]=[]
    elif name=="wrong-edge-suffix":
        join=data["FindComponentDriver"]["interfaces"]
        join[join.index("IFindComponentDriver")]="IFindComponentDriver2"
    elif name=="iface-rva":
        iface["methods"][0]["rva"]="1"
    elif name=="pe-id":
        data["PE"]["sha256"]="0"*64
    elif name=="wrong-clsid":
        data["Registry64"]["CLSID"]="{19DC53C4-47A0-4AE0-9422-5675D014F182}"
    elif name=="impl-namespace":
        data["FindComponentDriver"]["namespace"]="AspenTech.AspenPlus.Other"
    elif name=="impl-name":
        method["name"]="ShowOtherX"
    elif name=="impl-sig":
        method["signature"]="2001090E"
    elif name=="impl-rva":
        method["rva"]="A849"
    elif name=="equivalent-layout":
        target.write_text(json.dumps(data,sort_keys=True,ensure_ascii=False,separators=(",",":"))+"\n",encoding="utf-8")
        return REG
    else:
        raise ValueError(name)
    save(target,data)
    return REG


def check(original,live,out,fixed,checker):
    verifier=fixed/"tool/s109_verify.py"
    assert hexsum(verifier)=="970cdb4fd9e3941ef2112d365d4eff18124548e3e49ed71472827caac1138d60"
    generator=fixed/"tool/s81_showdialog.py"
    unit=fixed/"handoff/inbox/NATIVE-337"
    assert hexsum(original)==ORIG_SHA and hexsum(checker)==CHECKER_SHA
    assert live.read_bytes()==(unit/REG).read_bytes()
    manifest=json_file(unit/MANIFEST)
    actual={p.relative_to(unit).as_posix():hexsum(p) for p in unit.rglob("*") if p.is_file()}
    mismatch={k:{"declared":v,"actual":actual.get(k)} for k,v in manifest.items() if actual.get(k)!=v}
    assert all(x["actual"] is not None for x in mismatch.values()),mismatch
    print("manifest mismatches",mismatch)
    out.mkdir(parents=True,exist_ok=True)
    report={}
    cases={
        "baseline":"0, no conflicts","equivalent-layout":"0, no conflicts",
        "vt-listing":"3, 0x13DD listing","riid-listing":"3, 0x137F listing",
        "impl-sig":"3, signature","impl-name":"3, method","impl-rva":"3, implementation RVA",
        "table-sig":"3, delivery signature","missing-attachment":"3, attachment",
        "missing-edge":"3, InterfaceImpl","iface-rva":"3, interface RVA",
        "pe-id":"3, deployment identity","table-rva":"3, delivery RVA",
        "wrong-edge-suffix":"3, InterfaceImpl targets a different TypeDef",
        "impl-namespace":"3, implementation type identity mismatch",
        "wrong-clsid":"3, registry maps a different CLSID",
        "table-duplicate":"3, conflicting duplicated row",
        "no-binary":"indeterminate or nonzero when the independent input required for judgment is absent",
    }
    for name,expected in cases.items():
        folder=out/name
        shutil.copytree(unit,folder,dirs_exist_ok=True)
        modified=mutate(folder,name)
        hashes={k:actual[k] for k in manifest}
        if modified:
            path=folder/modified
            if path.is_file():
                hashes[modified]=hexsum(path)
            else:
                hashes.pop(modified)
        if modified or mismatch:
            save(folder/MANIFEST,hashes)
        before={p.relative_to(folder).as_posix():hexsum(p) for p in folder.rglob("*") if p.is_file()}
        assert {k for k,v in actual.items() if before.get(k)!=v}==(({modified} if modified else set()) | ({MANIFEST} if modified or mismatch else set()))
        assert all(before.get(k)==v for k,v in hashes.items())
        if name=="no-binary":
            missing=out/"nonexistent.dll"
            assert not missing.exists()
            value=run(fixed,verifier,"--binary",missing,"--folder",folder,"--signature")
        else:
            value=run(fixed,verifier,"--binary",original,"--folder",folder,"--listing","--signature")
        after={p.relative_to(folder).as_posix():hexsum(p) for p in folder.rglob("*") if p.is_file()}
        assert before==after
        report[name]=dict(expected=expected,result=value,changed=modified,old_sha256=actual.get(modified),
                          new_sha256=before.get(modified),manifest_sha256=before[MANIFEST])
        print(name,value["exit"],value["stdout"].strip().replace("\n"," | "))
    coverage=run(fixed,checker,"NATIVE-337","--original",original,"--submission",unit)
    regen=out/"showdialog.csv"
    regenerated=run(fixed,generator,"--binary",original,"--folder",unit,"--out",regen)
    assert regenerated["exit"]==0 and regen.read_bytes()==(unit/TABLE).read_bytes(),regenerated
    with regen.open(encoding="utf-8",newline="") as stream:
        rows=list(csv.DictReader(stream))
    claimed_excluded=["s*-fingerprints.json","s*-submission.md","work/*-gate.txt","work/*-exclusions.txt"]
    outside=sorted(p for p in actual if p not in manifest and not any(fnmatchcase(p,pat) for pat in claimed_excluded))
    summary=dict(main=MAIN,head=HEAD,original_sha256=hexsum(original),checker_sha256=hexsum(checker),
                 verifier_sha256=hexsum(verifier),generator_sha256=hexsum(generator),
                 live_sha256=hexsum(live),live_pe=json_file(live)["PE"],unit_files=len(actual),
                 manifest={"entries":len(manifest),"sha256":hexsum(unit/MANIFEST),"unlisted_outside_claimed_exclusions":outside,
                           "mismatches":mismatch,"included_despite_claimed_exclusions":sorted(p for p in manifest if any(fnmatchcase(p,pat) for pat in claimed_excluded))},
                 generator={"rows":len(rows),"variant_vt":sum(row["item"]=="variant-vt" for row in rows),"sha256":hexsum(regen)},
                 coverage=coverage,cases=report)
    save(out/"s109-recheck.json",summary)
    print("coverage",coverage,"manifest",summary["manifest"],"tools",summary["verifier_sha256"])


if __name__=="__main__":
    original,live,out,fixed,checker=map(lambda p:Path(p).resolve(),sys.argv[1:])
    check(original,live,out,fixed,checker)
