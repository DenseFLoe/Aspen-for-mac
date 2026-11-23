"""Recheck the fixed FindComponent s117 candidate and paired evidence controls."""

import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys


ORIGINAL_SHA = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
CHECKER_SHA = "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
VERIFIER_SHA = "0069dc3a8237f5550ccf9cf4db8715d0832bd4decfaf7de805a9bd739fa6259e"
UNIT = "handoff/inbox/NATIVE-337"
REG = "s97-registration.json"
TABLE = "code/s81-showdialog.csv"
LISTING = "code/native.asm"
MANIFEST = "s117-fingerprints.json"


def sha(path):
    return sha256(path.read_bytes()).hexdigest()


def write_json(path, data):
    path.write_text(json.dumps(data, ensure_ascii=False, indent=2) + "\n", encoding="utf8", newline="\n")


def replace(path, old, new):
    data = path.read_bytes()
    assert data.count(old) == 1, (path, old)
    path.write_bytes(data.replace(old, new))


def mutate(folder, name):
    reg = folder / REG
    table = folder / TABLE
    listing = folder / LISTING
    if name in ("baseline", "signature-only-baseline", "missing-original"):
        return None
    if name == "missing-attachment":
        reg.unlink()
        return REG
    if name in ("table-signature", "table-rva", "table-duplicate"):
        if name == "table-rva":
            replace(table, b'rva 0xA848"', b'rva 0xA8480"')
        elif name == "table-signature":
            replace(table, b"id-sig-impl,registration,2001080E", b"id-sig-impl,registration,2001090E")
        else:
            row = next(row for row in table.read_bytes().splitlines(keepends=True) if row.startswith(b"id-sig-impl,"))
            replace(table, row, row.replace(b"2001080E", b"2001090E") + row)
        return TABLE
    if name in ("variant-listing", "riid-listing"):
        old, new = ((b"000013DD  B8 08 00 00 00", b"000013DD  B8 03 00 00 00") if name == "variant-listing"
                    else (b"0000137F  48 8D 15 72 6F 00 00", b"0000137F  48 8D 15 82 6F 00 00"))
        replace(listing, old, new)
        return LISTING
    if name == "json-duplicate":
        raw = reg.read_bytes()
        old = b'"signature": "2001080E"'
        assert raw.count(old) == 2
        reg.write_bytes(raw.replace(old, b'"signature": "2001090E", ' + old, 1))
        return REG
    if name == "wrong-registry-class":
        old = b'"class": "AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver"'
        replace(reg, old, old[:-1] + b'2"')
        return REG
    doc = json.loads(reg.read_bytes())
    if name == "wrong-codebase":
        doc["Registry64"]["codeBase"] = "file:///missing-deployment/FindComponent.dll"
        write_json(reg, doc)
        return REG
    if name == "attachment-missing-signature":
        del doc["IFindComponentDriver"]["methods"][0]["signature"]
        write_json(reg, doc)
        return REG
    impl = doc["FindComponentDriver"]
    iface = doc["IFindComponentDriver"]
    method = impl["methods"][0]
    fields = {
        "wrong-edge-suffix": (impl, "interfaces", ["IFindComponentDriver2"]),
        "wrong-edge-case": (impl, "interfaces", ["ifindcomponentdriver"]),
        "missing-edge": (impl, "interfaces", []),
        "wrong-namespace": (impl, "namespace", "Other.Namespace"),
        "wrong-clsid": (doc["Registry64"], "CLSID", "{00000000-0000-0000-0000-000000000000}"),
        "wrong-pe-sha": (doc["PE"], "sha256", "0" * 64),
        "iface-rva": (iface["methods"][0], "rva", "1"),
        "impl-rva": (method, "rva", "A849"),
        "impl-signature": (method, "signature", "2001090E"),
        "impl-name": (method, "name", "ShowOtherX"),
    }
    if name == "equivalent-layout":
        reg.write_text(json.dumps(doc, sort_keys=True, ensure_ascii=False, separators=(",", ":")) + "\n", encoding="utf8")
    else:
        node, key, value = fields[name]
        node[key] = value
        write_json(reg, doc)
    return REG


def file_map(folder):
    return {p.relative_to(folder).as_posix(): sha(p) for p in folder.rglob("*") if p.is_file()}


def check(original, live, out, fixed, checker):
    verifier = fixed / "tool/s117_verify.py"
    unit = fixed / UNIT
    assert (sha(original), sha(checker), sha(verifier)) == (ORIGINAL_SHA, CHECKER_SHA, VERIFIER_SHA)
    assert live.read_bytes() == (unit / REG).read_bytes()
    before = file_map(unit)
    manifest = json.loads((unit / MANIFEST).read_bytes())
    mismatch = {p: [digest, before.get(p)] for p, digest in manifest.items() if before.get(p) != digest}
    assert not mismatch
    out.mkdir(parents=True, exist_ok=True)

    def run(*args, cwd=fixed):
        result = subprocess.run([sys.executable, "-B", *map(str, args)], cwd=cwd, capture_output=True,
                                text=True, encoding="utf8", errors="replace")
        return {"command": [str(p) for p in args], "exit": result.returncode,
                "stdout": result.stdout, "stderr": result.stderr}

    cases = {
        "baseline": [0, "conflicts=0"],
        "signature-only-baseline": [0, "conflicts=0"],
        "equivalent-layout": [0, "conflicts=0"],
        "variant-listing": [3, "site=0x13DD"],
        "riid-listing": [3, "site=0x137F"],
        "wrong-edge-suffix": [3, "field=InterfaceImpl"],
        "wrong-edge-case": [3, "field=InterfaceImpl"],
        "missing-edge": [3, "field=InterfaceImpl"],
        "wrong-namespace": [3, "field=namespace"],
        "wrong-clsid": [3, "field=CLSID"],
        "wrong-pe-sha": [3, "field=sha256"],
        "iface-rva": [3, "field=rva"],
        "impl-rva": [3, "field=rva"],
        "impl-signature": [3, "field=signature"],
        "impl-name": [3, "field=method"],
        "table-rva": [3, "field=rva"],
        "table-signature": [3, "field=signature"],
        "table-duplicate": [3, "duplicate"],
        "json-duplicate": [3, "field=duplicate_key"],
        "missing-attachment": [3, "field=attachment"],
        "wrong-registry-class": [3, "field=class"],
        "wrong-codebase": [3, "codeBase"],
        "attachment-missing-signature": [3, "field=signature"],
        "missing-original": [3, "missing independent input"],
    }
    report = {}
    for name, expected in cases.items():
        folder = out / name
        shutil.copytree(unit, folder, dirs_exist_ok=True)
        changed = mutate(folder, name)
        entries = manifest.copy()
        path = folder / changed if changed else None
        if changed:
            if path.is_file():
                entries[changed] = sha(path)
            else:
                entries.pop(changed)
            write_json(folder / MANIFEST, entries)
        candidate = file_map(folder)
        expected_changes = {changed, MANIFEST} if changed else set()
        assert {p for p, digest in before.items() if candidate.get(p) != digest} == expected_changes
        assert all(candidate[p] == digest for p, digest in entries.items())
        if name == "missing-original":
            missing = out / "unavailable-independent-input.dll"
            assert not missing.exists()
            result = run(verifier, "--binary", missing, "--folder", folder, "--signature")
        elif name == "signature-only-baseline":
            result = run(verifier, "--binary", original, "--folder", folder, "--signature")
        else:
            result = run(verifier, "--binary", original, "--folder", folder, "--listing", "--signature")
        assert candidate == file_map(folder)
        report[name] = {"expected": expected, "result": result, "changed": changed,
                        "sha256": [before.get(changed), candidate.get(changed)],
                        "manifest_sha256": candidate[MANIFEST]}
        print(name, result["exit"], result["stdout"].strip().replace("\n", " | "))

    coverage = run(checker, "NATIVE-337", "--original", original, "--submission", unit)
    assert coverage["exit"] == 2 and "307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps" in coverage["stdout"]
    audit = run("tool/s117_variants.py")
    regen_root = out / "generation"
    regen_item = regen_root / UNIT
    shutil.copytree(unit, regen_item, dirs_exist_ok=True)
    generation = run(fixed / "qa/mk_fingerprints.py", "117", cwd=regen_root)
    assert generation["exit"] == 0
    regenerated = json.loads((regen_item / MANIFEST).read_bytes())
    gen_diff = {p: [manifest.get(p), regenerated.get(p)] for p in sorted(set(manifest) | set(regenerated))
                if manifest.get(p) != regenerated.get(p)}
    generated_table = out / "generated-showdialog.csv"
    generator = run("tool/s81_showdialog.py", "--binary", original, "--folder", unit, "--out", generated_table)
    assert generator["exit"] == 0 and generated_table.read_bytes() == (unit / TABLE).read_bytes()
    summary = {"head": "ea4a5c7ffc59c27075030fb4b8726f534d23c153", "original_sha256": sha(original),
               "coverage_sha256": sha(checker), "verifier_sha256": sha(verifier), "registration_sha256": sha(live),
               "manifest": {"checked": len(manifest), "sha256": before[MANIFEST],
                            "receipt_pins_manifest": before[MANIFEST] in (unit / "s117-submission.md").read_text(encoding="utf8"),
                            "generation": generation, "regenerated_count": len(regenerated), "changes": gen_diff},
               "audit": audit, "coverage": coverage, "table": {"generator": generator, "sha256": sha(generated_table)},
               "unresolved": sum(row["class"] == "unresolved" for row in csv.DictReader(
                   (unit / "calls.csv").read_text(encoding="utf8").splitlines())),
               "cases": report}
    assert before == file_map(unit)
    write_json(out / "s117-recheck.json", summary)
    print("manifest", summary["manifest"])
    print("coverage", coverage)


if __name__ == "__main__":
    check(*map(lambda arg: Path(arg).resolve(), sys.argv[1:]))
