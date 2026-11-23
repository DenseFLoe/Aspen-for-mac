"""Run from the Aspen workspace, with oracle.json from the independent s73-clr.ps1 reader."""
import ast
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

here = Path(__file__).resolve().parent
fixed = here.parent / "fixed"
prior = Path(".local/patrol-0357/review340").resolve()
original = Path(".local/acceptance-research/open-clr/WrapSaveMergeNNFiles.dll")
unit = fixed / "handoff/inbox/NATIVE-340"
sys.path.insert(0, str(Path(".local/patrol-1329/review337/deps").resolve()))
sys.path.insert(0, str(prior / "fixed/tool"))
spec = importlib.util.spec_from_file_location("trusted_review", prior / "s73-review.py")
review = importlib.util.module_from_spec(spec)
spec.loader.exec_module(review)
import cli_tables, pefile, preflight

def sha(data):
    return hashlib.sha256(data).hexdigest()

assert sha(original.read_bytes()) == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
for name in ("cli_tables.py", "preflight.py", "md_reader.py", "pe_reader.py"):
    assert (fixed / "tool" / name).read_bytes() == (prior / "fixed/tool" / name).read_bytes()
oracle = json.loads((here / "oracle.json").read_bytes())
methods = {r["token"]: r for r in oracle["original"]["methods"] if r["rva"] and r["implementation"] & 3 == 0}
table = review.table(unit / "code/s77-il-fingerprints.csv")
assert len(table) == len(methods) == 167
checks = {int(row["token"], 16): (row["il_sha256"], int(row["il_len"]), int(row["rva"], 16),
                                    int(row["flags"], 16), row["name"]) for row in table}
assert checks == {token: (r["il_sha256"], r["il_length"], r["rva"], r["flags"], r["name"]) for token, r in methods.items()}
assert not oracle["original"]["method_bindings"]
width_pairs = review.widths(cli_tables)
vtable = review.table(unit / "code/s77-vtable-fixups.csv")
descriptors = oracle["original"]["fixup_descriptors"]
expected_bits = {2: "COR_VTABLE_64BIT", 8: "COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN", 16: "COR_VTABLE_CALL_MOST_DERIVED"}
flags = []
for row in vtable:
    desc = descriptors[int(row["entry"])]
    assert (desc["rva"], desc["count"], desc["flags"], desc["slots"]) == (int(row["slot"],16), 1, int(row["dwFlags"],16), [int(row["method"],16)])
    expected = ",".join(label for bit,label in expected_bits.items() if desc["flags"] & bit)
    flags.append(dict(slot=row["slot"], raw=desc["flags"], expected=expected, actual=row["flags_meaning"]))
fixture = (prior / "CliBindingFixture.dll").read_bytes()
pe = pefile.PE(data=fixture)
cor = pe.get_offset_from_rva(pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress)
md = pe.get_offset_from_rva(struct.unpack_from("<I", fixture, cor+8)[0])
row, = cli_tables.read(fixture, md)["rows"][25]
binding, = oracle["fixture"]["method_bindings"]
source = (fixed / "tool/audit_340_s77.py").read_text(encoding="utf8")
decoder, = [f for f in ast.parse(source).body if getattr(f, "name", "") == "decode_methoddef_orref"]
expr = ast.unparse(decoder.body[0].value.elts[1])
assert expr == "(v >> 1) + 1"
raw = [row["MethodBody"], row["MethodDeclaration"]]
expected = [binding["body"] & 0xffffff, binding["declaration"] & 0xffffff]
actual = [(v >> 1) + 1 for v in raw]
digest_pair = []
for tab in ("s73-method-access.csv", "s77-il-fingerprints.csv"):
    content = (unit / "code" / tab).read_bytes()
    case = here / "paired-input" / tab.removesuffix(".csv")
    path = case / "code" / tab
    path.parent.mkdir(parents=True,exist_ok=True)
    for mutate in (False, True):
        edited = content
        if mutate:
            lines = content.splitlines(keepends=True)
            i, = [i for i,l in enumerate(lines) if l.startswith(b"0x06000056,")]
            old_hash = methods[0x06000056]["il_sha256"].encode()
            lines[i] = lines[i].replace(old_hash, b"0"+old_hash[1:])
            edited = b"".join(lines)
            assert edited != content
        path.write_bytes(edited)
        hits, stats = preflight.det_access_flags("NATIVE-340", str(case), str(original), {})
        digest_pair.append(dict(table=tab, mutated=mutate, sha256=sha(edited), hits=hits, stats=stats))
native = review.native(original, unit / "native-functions.csv")
result = dict(verified_IL=167, slots=flags, flag_source="https://github.com/dotnet/runtime/blob/main/src/coreclr/inc/corhdr.h",
              fixups=len(descriptors), methodimpl=dict(fixture_sha256=sha(fixture), raw=raw, expected=expected,
              observed_from_source=actual, source_expression=expr), widths=width_pairs, digest_pair=digest_pair, native=native)
print(json.dumps(result, indent=2))
