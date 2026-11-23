"""Replay pinned NATIVE-340 QA gate controls without modifying the candidate."""
from importlib import import_module
from hashlib import sha256
import json
from pathlib import Path
import sys
from tempfile import TemporaryDirectory
from types import SimpleNamespace

VERSION = "3517b5ed973193e1fb5a8b29eca1ac17228af9d5"
GATE_SHA = "5aeb8613c274bf843002bab720d13d2496a155ccb91476d5b9b50f660a1ef6b1"
DET_SHA = "d0379abfd3df805081b5514ae0acf04e956018cc563b8cec4ac482aae07d3316"
ORIGINAL_SHA = "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"


def digest(data):
    return sha256(data).hexdigest()


def apply_gate(gate, detector, item, original):
    gate.load_detectors = lambda: [detector]
    result = gate.aggregate("NATIVE-340", str(item), str(original))
    return {"exit":result["exit"],"l2_exit":result["l2_exit"],"units":result["units"],
            "detector":result["l2"][detector.__name__]}


def unreadable(_task, _dir, _original, _ctx):
    raise ValueError("fixture detector input could not be read")


def valid(_task, _dir, _original, _ctx):
    return [], {"rows": 1}


def main(qa, original, item):
    folder=qa.resolve()/"qa"
    sys.path.insert(0,str(folder))
    assert digest((folder/"gate.py").read_bytes())==GATE_SHA
    assert digest((folder/"det_fingerprint_pathset.py").read_bytes())==DET_SHA
    assert digest(original.read_bytes())==ORIGINAL_SHA
    gate=import_module("gate")
    pathset=import_module("det_fingerprint_pathset")
    access=import_module("det_access_flags")
    gate.run_l1=lambda *_:{"exit":0}
    fixture=SimpleNamespace(__name__="fixture",CATEGORY="fixture",L1_COVERS="no")
    paths=("coverage.csv","code/types.cs","code/s73-il-bodies.bin")
    source={p:(item/p).read_bytes() for p in paths}
    report=json.loads((item/"code/s81-fingerprints.json").read_bytes())["files"]
    declared={p:report[p] for p in paths}
    assert all(digest(source[p])==h for p,h in declared.items())
    results={"qa_head":VERSION,"gate_sha256":GATE_SHA,"pathset_sha256":DET_SHA,
             "original_sha256":ORIGINAL_SHA,"declared":declared}
    with TemporaryDirectory() as temp:
        root=Path(temp)
        negative={"good":[],"cs":["code/types.cs"],"bin":["code/s73-il-bodies.bin"],
                  "csv":["coverage.csv"]}
        for name, changes in negative.items():
            work=root/name
            for p,data in source.items():
                dst=work/p
                dst.parent.mkdir(parents=True,exist_ok=True)
                dst.write_bytes(data+(bytes([10]) if p in changes else b""))
            (work/"s81-fingerprints.json").write_text(json.dumps(declared),encoding="ascii")
            results[name]={"observed_sha256":{p:digest((work/p).read_bytes()) for p in paths},
                           **apply_gate(gate,pathset,work,original)}
        for name,fn in (("normal_detector",valid),("raising_detector",unreadable)):
            fixture.detect=fn
            results[name]=apply_gate(gate,fixture,root,original)
        for name,token in (("access_valid","0x06000001"),("access_unbound","0x0600FFFF")):
            work=root/name
            work.mkdir()
            table=work/"access.csv"
            table.write_text(f"token,flags,access\n{token},0x0813,Assembly\n",encoding="ascii",newline="\n")
            results[name]={"csv_sha256":digest(table.read_bytes()),**apply_gate(gate,access,work,original)}
    print(json.dumps(results,indent=2))


if __name__=="__main__":
    main(*map(Path,sys.argv[1:]))
