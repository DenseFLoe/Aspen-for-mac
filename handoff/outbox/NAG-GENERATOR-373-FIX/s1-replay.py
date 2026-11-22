"""Run from the upstream audit snapshot on Windows. Reads pinned trees as ordinary files."""
import argparse
import hashlib
import json
import runpy
import subprocess
import sys
import tempfile
from pathlib import Path

HEAD = "a33cf8764c14fe76e43c961ebfb7cdfc84d910ec"
MAIN = "773260c1033e524cebe000699409f5708bebfda0"
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--main-tree", type=Path, required=True)
parser.add_argument("--candidate-tree", type=Path, required=True)
parser.add_argument("--output", type=Path, required=True)
args = parser.parse_args()
CANDIDATE = args.candidate_tree.resolve()
assert sys.platform == "win32"
baseline = runpy.run_path(str(args.main_tree / "handoff/assignments/check-generator-373.py"))
replay = runpy.run_path(str(args.main_tree / "handoff/inbox/NAG-GENERATOR-373/replay.py"))
for fn in ("load_functions", "gate"):
    replay[fn].__globals__["ROOT"] = CANDIDATE

sha = lambda data: hashlib.sha256(data).hexdigest()
first, second = baseline["FIRST"], baseline["VERSION"]
sample = (CANDIDATE / "handoff/inbox/NAG-GENERATOR-373-FIX/sample.cs.txt").read_bytes()
assert sha(sample) == "2ceba82a4d3bb35449fb475d8946274afa91dd04f5914f2fd245f09d75336886"
sample_out = sample.removesuffix(first + b"\n" + second + b"\n")
assert sha(sample_out) == "17564b44f55a10b21387cbf528a82a392fcf6a7384810bb0a94eb17e3222fe1e"
literal = b'const string message = @"status:\n' + first + b'\n' + second + b'";\n'
incomplete = b"class C {}\n" + first + b"\nLatest version is\n"
bom_diagnostic = b"\xef\xbb\xbf" + first + b"\r\n"
extra = {
    "archived-ilspy-stdout": (sample, sample_out, 1, 0),
    "legal-verbatim-string-at-eof": (literal, literal, 0, 0),
    "missing-version-payload": (incomplete, incomplete, 1, 1),
    "bom-before-bare-diagnostic": (bom_diagnostic, bom_diagnostic, 1, 1),
}
cases = {**baseline["CASES"], **extra}
observations = []
with tempfile.TemporaryDirectory(prefix="gen401-") as scratch:
    for path, funcs in (
        ("tool/b2_wave.py", {"strip_tool_nag", "run_clr_one", "ensure", "clr_dir"}),
        ("tool/batch_reverse.py", {"strip_tool_nag", "decompile", "long_path", "ensure_dir"}),
    ):
        ns = replay["load_functions"](path, funcs)
        for name, (raw, expected, raw_rc, after_rc) in cases.items():
            case = Path(scratch) / Path(path).stem / name
            (case / "before").mkdir(parents=True)
            (case / "before/input.cs.txt").write_bytes(raw)
            before, _ = replay["gate"](case / "before")
            once, a, _ = replay["produce"](path, ns, case / "once", raw)
            twice, b, _ = replay["produce"](path, ns, case / "twice", once)
            after, _ = replay["gate"](a.parent)
            ok = (before, after, once, twice, a.is_file(), b.is_file()) == (raw_rc, after_rc, expected, expected, True, True)
            row = dict(producer=path, case=name, passed=ok, raw_sha256=sha(raw), expected_sha256=sha(expected), once_sha256=sha(once), twice_sha256=sha(twice),
                       expected_bytes=len(expected), once_bytes=len(once), twice_bytes=len(twice), once_present=a.is_file(), twice_present=b.is_file(),
                       expected_gate=[raw_rc, after_rc], actual_gate=[before, after])
            if not ok:
                row.update(input_utf8=raw.decode("utf-8"), actual_utf8=once.decode("utf-8"))
            observations.append(row)
def failed_process(argv, **kwargs):
    if "--out" in argv:
        return replay["fixture_process"](argv, **kwargs)
    assert argv[0] == "dotnet"
    return subprocess.run([sys.executable, "-I", "-B", "-c",
                           "import sys;sys.stderr.buffer.write(b'fixture error');sys.exit(1)"], **kwargs)


ns = replay["load_functions"]("tool/b2_wave.py", {"strip_tool_nag", "run_clr_one", "ensure", "clr_dir"})
ns["subprocess"].run = failed_process
with tempfile.TemporaryDirectory(prefix="gen401-stderr-") as scratch:
    try:
        _, _, outcome = replay["produce"]("tool/b2_wave.py", ns, Path(scratch) / "once", b"class C {}\n")
    except TypeError as exc:
        outcome = f"TypeError: {exc}"
result = dict(head=HEAD, main=MAIN, measurements=observations,
              b2_failed_stdout_process=dict(child_exit=1, stderr="fixture error", expected="failed_analyze", observed=outcome))
args.output.write_bytes((json.dumps(result, indent=2, ensure_ascii=True) + "\n").encode())
for item in observations:
    if not item["passed"]:
        print(item["producer"], item["case"], item["expected_bytes"], item["once_bytes"], item["actual_gate"])
print("matched", sum(o["passed"] for o in observations), "of", len(observations))
print("B2 nonzero ILSpy exit:", outcome)
