"""Recheck fixed NATIVE-337 inputs. Arguments: checker candidate original fresh-reg output-dir."""
import csv
from collections import Counter
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def run(cwd, *args):
    result = subprocess.run([sys.executable, "-B", *map(str, args)], cwd=cwd, capture_output=True, text=True, encoding="utf-8", errors="replace")
    return {"exit": result.returncode, "stdout": result.stdout.strip(), "stderr": result.stderr.strip()}


def csv_rows(path):
    with path.open(encoding="utf-8-sig", newline="") as f:
        return list(csv.DictReader(f))


def pe_offset(data, rva):
    p = struct.unpack_from("<I", data, 0x3c)[0]
    count = struct.unpack_from("<H", data, p + 6)[0]
    opt = struct.unpack_from("<H", data, p + 20)[0]
    for i in range(count):
        vsize, va, rawsize, off = struct.unpack_from("<IIII", data, p + 24 + opt + 40 * i + 8)
        if va <= rva < va + min(vsize, rawsize):
            return off + rva - va
    raise ValueError(rva)


def replace_once(data, old, new):
    assert data.count(old) == 1
    return data.replace(old,new)


def main():
    checker, fixed, original, registration, out = map(lambda x: Path(x).resolve(), sys.argv[1:])
    unit = fixed / "handoff/inbox/NATIVE-337"
    script = fixed / "tool/s81_showdialog.py"
    source = unit / "code/native.asm"
    declared = unit / "code/s81-showdialog.csv"
    reg = unit / "s97-registration.json"
    assert digest(original) == "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
    raw = original.read_bytes()
    checks = {}
    for rva, n in ((0x13DD,5),(0x137F,7),(0x82F8,16),(0x8308,16)):
        p = pe_offset(raw, rva)
        checks[hex(rva)] = raw[p:p+n].hex()
    assert checks == {"0x13dd":"b808000000","0x137f":"488d15726f0000","0x82f8":"00"*16,"0x8308":"0004020000000000c000000000000046"}
    assert 0x137f + 7 + 0x6f72 == 0x82f8 and 0x137f + 7 + 0x6f82 == 0x8308
    coverage = run(fixed, checker,"NATIVE-337","--original",original,"--submission",unit)
    assert coverage["exit"] == 2
    classes = dict(Counter(r["class"] for r in csv_rows(unit / "calls.csv")))
    manifest_path = unit / "s97-fingerprints.json"
    manifest = json.loads(manifest_path.read_bytes())
    all_paths = {p.relative_to(unit).as_posix() for p in unit.rglob("*") if p.is_file()}
    assert set(manifest) <= all_paths
    exclusions = sorted(all_paths - set(manifest))
    assert all(digest(unit / name) == value for name,value in manifest.items())
    assert reg.read_bytes() == registration.read_bytes()
    metadata = json.loads(reg.read_bytes())
    methods = {name:metadata[name]["methods"][0] for name in ("IFindComponentDriver","FindComponentDriver")}
    assert all(row["signature"] == "2001080E" and row["name"] == "ShowDialog" and row["params"] == ["dialogName"] for row in methods.values())
    assert methods["FindComponentDriver"]["rva"] == "A848" and metadata["FindComponentDriver"]["interfaces"] == ["IFindComponentDriver"]
    split = b'"FindComponentDriver": {'
    prefix, impl = reg.read_bytes().split(split)
    altered = prefix + split + replace_once(impl,b'2001080E',b'2001090E')
    asm = source.read_bytes()
    cases = {
        "exact":(asm,reg.read_bytes()),
        "vt-8-to-3":(replace_once(asm,b"000013DD  B8 08 00 00 00",b"000013DD  B8 03 00 00 00"),reg.read_bytes()),
        "riid-to-IDispatch":(replace_once(asm,b"0000137F  48 8D 15 72 6F 00 00",b"0000137F  48 8D 15 82 6F 00 00"),reg.read_bytes()),
        "impl-return-uint32":(asm,altered),
    }
    controls = {}
    for name,(listing, evidence) in cases.items():
        fixture = out / name
        (fixture / "code").mkdir(exist_ok=True,parents=True)
        listing_file = fixture / "code/native.asm"
        reg_file = fixture / "s97-registration.json"
        listing_file.write_bytes(listing)
        reg_file.write_bytes(evidence)
        table = fixture / "output.csv"
        result = run(fixed,script,"--binary",original,"--folder",fixture,"--out",table)
        entries = csv_rows(table)
        relevant = {"calls-riid","variant-vt","variant-init","deploy-clsid","deploy-assembly-sha256","deploy-signature"}
        controls[name] = {"exit":result["exit"],"listing_sha256":digest(listing_file),"registration_sha256":digest(reg_file),"output_sha256":digest(table),"rows":len(entries),"variant_vt_count":sum(r["item"]=="variant-vt" for r in entries),"rows_evidence":[r for r in entries if r["item"] in relevant]}
    assert controls["exact"]["output_sha256"] == digest(declared)
    report = {"original_sha256":digest(original),"checker_sha256":digest(checker),"generator_sha256":digest(script),"coverage":coverage,"calls_classes":classes,"fixture_original_rvas":checks,"manifest":{"paths":len(manifest),"sha256":digest(manifest_path),"errors":0,"excluded":exclusions},"deployment":{"fresh_registry_and_installed_metadata_equals_candidate":True,"sha256":digest(reg),"registry":metadata["Registry64"],"assembly":metadata["PE"],"methods":methods},"controls":controls}
    (out / "s97-recheck.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")
    print("coverage",coverage,"classes",classes,"manifest",report["manifest"])
    for name, c in controls.items():
        print(name,c["exit"],c["rows"],c["variant_vt_count"],c["output_sha256"],[(r["item"],r["meaning"].split("listing_matches=")[-1]) for r in c["rows_evidence"] if "listing_matches=" in r["meaning"]])


if __name__ == "__main__":
    main()
