"""Check the s73 tables, CLI widths and fixed native ingress paths independently."""
from collections import defaultdict
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

import capstone
from capstone.x86_const import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def table(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def metadata_fixture(counts, tables):
    # ECMA-335 table stream with 16-bit heaps. Unknown rows use explicit zeroes.
    valid = sum(1 << index for index in counts)
    stream = struct.pack("<IBBBBQQ", 0, 2, 0, 0, 1, valid, 0)
    stream += b"".join(struct.pack("<I", counts[index]) for index in sorted(counts))
    stream += b"".join(tables[index] for index in sorted(tables))
    version = b"v4.0\0\0\0\0"
    strings = b"\0" + bytes(16) + b"MethodName\0"
    header = struct.pack("<IHHII", 0x424A5342, 1, 1, 0, len(version)) + version + struct.pack("<HH", 0, 2)
    offset = len(header) + 32
    headers = struct.pack("<II", offset, len(stream)) + b"#~\0\0"
    headers += struct.pack("<II", offset + len(stream), len(strings)) + b"#Strings\0\0\0\0"
    return header + headers + stream + strings


def widths(cli_tables):
    results = []
    for count in (8191, 8192):
        parent = (count << 3) | 1
        code = struct.pack("<H" if count < 8192 else "<I", parent)
        data = metadata_fixture({1: count, 10: 1}, {1: bytes(count * 6), 10: code + struct.pack("<HH", 17, 29)})
        observed = cli_tables.read(data, 0)["rows"][10][0]
        results.append({"table": "MemberRef", "target_count": count, "input_sha256": sha256(data).hexdigest(),
                        "expected": {"Class": parent, "Name": "MethodName", "Signature": 29}, "observed": observed})
    for count in (16383, 16384, 32768):
        code = "<H" if count < 32768 else "<I"
        body, declaration = 2, 4
        data = metadata_fixture({6: count, 25: 1}, {6: bytes(count * 14),
                                     25: struct.pack("<H", 1) + struct.pack(code, body) + struct.pack(code, declaration)})
        observed = cli_tables.read(data, 0)["rows"][25][0]
        results.append({"table": "MethodImpl", "target_count": count, "input_sha256": sha256(data).hexdigest(),
                        "expected": {"Class": 1, "MethodBody": body, "MethodDeclaration": declaration},
                        "observed": observed})
    for row in results:
        row["match"] = all(row["observed"][key] == value for key, value in row["expected"].items())
    assert [row["match"] for row in results] == [True, False, True, False, True]
    return results


def native(original, native_functions):
    pe = pefile.PE(str(original), fast_load=False)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    targets = {0x5570, 0x5574, 0x557A, 0x5580, 0x5584, 0x558A, 0x19600, 0x19608, 0x19610, 0x19618}
    refs = defaultdict(dict)
    anchors = {row.struct.BeginAddress: row.struct.EndAddress for row in pe.DIRECTORY_ENTRY_EXCEPTION}
    starts = sorted(set(anchors) | set(int(row["rva"], 16) for row in table(native_functions)))
    for i, start in enumerate(starts):
        default_end = starts[i + 1] if i + 1 < len(starts) else start + 15
        end = min(anchors.get(start, default_end), default_end)
        if start >= end:
            continue
        for ins in decoder.disasm(pe.get_data(start, end - start), start):
            for op in ins.operands:
                if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                    target = ins.address + ins.size + op.mem.disp
                elif op.type == X86_OP_IMM and (ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP)):
                    target = op.imm
                else:
                    continue
                if target in targets:
                    refs[hex(target)][hex(ins.address)] = f"{ins.mnemonic} {ins.op_str}"
    ingress = {}
    for site in (0x5570, 0x5574, 0x557A, 0x5580, 0x5584, 0x558A):
        ins = next(decoder.disasm(pe.get_data(site, 15), site, count=1))
        ingress[hex(site)] = {"bytes": ins.bytes.hex(), "instruction": f"{ins.mnemonic} {ins.op_str}"}
    return {"refs": refs, "decoded_ingress": ingress, "function_starts": len(starts)}


def main():
    root, base, original = (Path(arg).resolve() for arg in sys.argv[1:4])
    fixed, unit = root / "fixed", root / "fixed/handoff/inbox/NATIVE-340"
    checker = base / "handoff/assignments/check-native-coverage.py"
    assert digest(original) == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    assert digest(checker) == "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
    sys.path.insert(0, str(fixed / "tool"))
    import cli_tables
    import audit_340_s73 as audit

    def run(*args):
        result = subprocess.run([sys.executable, "-B", *map(str, args)], cwd=fixed,
                                text=True, encoding="utf-8", capture_output=True)
        def portable(value):
            return value.replace(str(original), "ORIGINAL").replace(str(fixed), "FIXED").replace(
                str(base), "BASE").replace(str(root), "REVIEW")
        return {"command": portable(subprocess.list2cmdline(["python", "-B", *map(str, args)])),
                "exit": result.returncode, "stdout": portable(result.stdout.strip()),
                "stderr": portable(result.stderr.strip())}

    def fingerprints(manifest):
        doc = json.loads(manifest.read_bytes())
        files = doc.get("files", doc)
        observed = {name: digest(unit / name) for name in files if (unit / name).is_file()}
        return {"manifest": manifest.name, "declared": len(files), "read": len(observed),
                "missing": sorted(files.keys() - observed.keys()),
                "mismatch": sorted(name for name, actual in observed.items() if files[name] != actual)}

    fp = [fingerprints(unit / f"code/{name}.json") for name in ("s29-fingerprints", "s73-fingerprints")]
    assert all(not result["mismatch"] and not result["missing"] for result in fp)
    isolated = root / "audit-copy"
    shutil.copytree(unit, isolated, dirs_exist_ok=True)
    aud_runs = []
    tracked = ["calls.csv", *[f"code/s73-{name}" for name in ("method-access.csv", "binding-pairs.csv",
                         "entry-trace.csv", "metadata-decode.csv", "audit.md", "evidence.json")]]
    for _ in range(2):
        result = run("tool/audit_340_s73.py", "--binary", original, "--folder", isolated)
        result["outputs"] = {name: digest(isolated / name) for name in tracked}
        aud_runs.append(result)
    assert aud_runs[0] == aud_runs[1] and aud_runs[0]["exit"] == 0
    comparison = {name: [digest(unit / name), aud_runs[0]["outputs"][name]] for name in tracked}

    clr = json.loads((root / "s73-clr.json").read_bytes())
    il = json.loads((root / "s73-il.json").read_bytes())
    assert il["eh_differences"] == [] and il["eh_clauses"] == 35
    assert len(il["original_sites"]) == 11 and len({x["caller"] for x in il["original_sites"]}) == 8
    methods = {item["token"]: item for item in clr["original"]["methods"]}
    for row in table(unit / "code/s73-method-access.csv"):
        actual = methods[int(row["token"], 16)]
        assert (actual["flags"], actual["implementation"], actual["access"].lower(), actual["il_sha256"]) == (
            int(row["flags"], 16), int(row["impl_flags"], 16), row["access"].lower(), row["il_sha256"])
    delivered_body = unit / "code/s73-il-bodies.bin"
    if delivered_body.exists():
        assert digest(delivered_body) == methods[0x06000056]["il_sha256"]
    import preflight
    access_case = root / "access-positive"
    access_table = access_case / "code/s73-method-access.csv"
    access_table.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(unit / "code/s73-method-access.csv", access_table)
    good_hits, good_stats = preflight.det_access_flags("NATIVE-340", str(access_case), str(original), {})
    assert good_stats["tables_checked"] == 1 and not good_hits
    good_access_sha = digest(access_table)
    rows = table(access_table)
    known = rows[0]["il_sha256"]
    assert len(known) == 64
    rows[0]["il_sha256"] = "0" + known[1:]
    assert rows[0]["il_sha256"] != known
    with access_table.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    bad_hits, bad_stats = preflight.det_access_flags("NATIVE-340", str(access_case), str(original), {})
    assert bad_stats == good_stats and not bad_hits
    assert clr["original"]["member_ref_parent_kinds"] == {"TypeReference": 105, "TypeSpecification": 4}
    assert not clr["original"]["method_bindings"]
    fixups = {item["rva"]: item for item in clr["original"]["fixup_descriptors"]}
    fixup_entries = {hex(key): fixups[key] for key in (0x19600, 0x19608, 0x19610, 0x19618)}
    assert [(row["flags"], row["slots"]) for row in fixup_entries.values()] == [
        (2, [0x06000056]), (10, [0x06000056]), (2, [0x06000057]), (10, [0x06000057])]

    binding_fixture = (root / "CliBindingFixture.dll").read_bytes()
    pe = pefile.PE(data=binding_fixture)
    cor = pe.get_offset_from_rva(pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress)
    off = pe.get_offset_from_rva(struct.unpack_from("<I", binding_fixture, cor + 8)[0])
    meta = cli_tables.read(binding_fixture, off)
    impl = meta["rows"][25]
    actual_bindings = [list(audit.decode_methoddef_orref(row["MethodBody"])) for row in impl]
    fixture_methods = {x["name"]: x for x in clr["fixture"]["methods"]}
    bound, unbound = (fixture_methods[name] for name in ("ILocalBinding.Evaluate", "Unbound"))
    # The delivered positive-proof relation uses any MethodImpl row for every method.
    actual_global = [bool(impl), bool(impl)]
    oracle = [any(row["body"] == method["token"] for row in clr["fixture"]["method_bindings"])
              for method in (bound, unbound)]
    assert oracle == [True, False] and actual_global == [True, True]
    assert actual_bindings == [["MethodDef", bound["token"] & 0xFFFFFF]]

    evidence = {
        "head": json.loads((root / "fixed-manifest.json").read_bytes())["head"],
        "original_sha256": digest(original), "checker_sha256": digest(checker), "fingerprints": fp,
        "tools": {name: digest(fixed / "tool" / name) for name in ("audit_340_s73.py", "cli_tables.py", "md_reader.py", "preflight.py")},
        "coverage": run(checker, "NATIVE-340", "--original", original, "--submission", unit),
        "candidate_audits": aud_runs, "output_hashes_as_submitted_and_rerun": comparison,
        "methods": {hex(token): methods[token] for token in (0x06000056, 0x06000057)},
        "member_ref_parents": clr["original"]["member_ref_parent_kinds"], "method_impl_count": 0,
        "eh_clauses": il["eh_clauses"], "original_sites": il["original_sites"], "fixup_entries": fixup_entries,
        "fixup_directory_rva": hex(clr["original"]["fixup_rva"]),
        "native": native(original, unit / "native-functions.csv"),
        "coded_width_pairs": widths(cli_tables),
        "il_digest_pair": {"expected": [0, 1], "observed": [len(good_hits), len(bad_hits)],
                           "candidate_input_sha256": [good_access_sha, digest(access_table)],
                           "original_il_sha256": known, "replacement": rows[0]["il_sha256"]},
        "binding_pair": {"fixture_sha256": clr["fixture_sha256"], "methods": [bound, unbound],
                         "actual_image_bindings": clr["fixture"]["method_bindings"],
                         "observed_module_wide_predicate": actual_global, "expected_per_method": oracle},
    }
    assert evidence["coverage"]["exit"] == 2
    (root / "s73-recheck.json").write_text(json.dumps(evidence, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print("fingerprints", fp, "coverage", evidence["coverage"], "audit", aud_runs[0]["stdout"],
          "widths", [row["match"] for row in evidence["coded_width_pairs"]],
          "native", evidence["native"], "binding", oracle, actual_global)


if __name__ == "__main__":
    main()
