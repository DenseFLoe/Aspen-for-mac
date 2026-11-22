"""Replay the pinned #373 write paths with controlled ILSpy stdout on Windows."""
import ast
import base64
import hashlib
import json
import os
import platform
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from types import SimpleNamespace


ROOT = Path(__file__).resolve().parents[3]
INBOX = ROOT / "handoff/inbox/NAG-GENERATOR-373"
HEAD = "8f5034f02722916e442881a6bd112baef419d1a7"
SOURCES = {
    "tool/b2_wave.py": "627fc3becb7cd89f2bf90027b68047f28fa5f20e06514c0a1f274b3fbb4956b3",
    "tool/batch_reverse.py": "2a33353dbb07e24f15b2a4f30c8d69883ef29688f849ad327d723f1102c6534e",
    "tool/check_cs_clean.py": "f6989df348c2d3052337f9483b40489dd7512eb20afeb98a83b15eb15c291b85",
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def b64(data):
    return base64.b64encode(data).decode("ascii")


def fixture_process(argv, **kwargs):
    # Only the IL lister and external ILSpy calls are substituted. stdout mode,
    # encoding, newline translation, output handles and real process rc stay intact.
    if "--out" in argv:
        Path(argv[argv.index("--out") + 1]).write_bytes(b"stub IL\n")
        return subprocess.CompletedProcess(argv, 0, "", "")
    if argv[0] not in ("dotnet", "fixture-dotnet"):
        raise ValueError(argv)
    emit = "import sys,pathlib; sys.stdout.buffer.write(pathlib.Path(sys.argv[1]).read_bytes())"
    return subprocess.run([sys.executable, "-I", "-B", "-c", emit, argv[-1]], **kwargs)


def load_functions(path, functions):
    tree = ast.parse((ROOT / path).read_bytes(), filename=path)
    selected = []
    for item in tree.body:
        if isinstance(item, ast.FunctionDef) and item.name in functions:
            selected.append(item)
        if isinstance(item, ast.Assign) and isinstance(item.targets[0], ast.Name):
            if item.targets[0].id in {"NAG_HEAD", "NAG_VER"}:
                selected.append(item)
    ns = dict(Path=Path, os=os, sys=sys, time=time, subprocess=SimpleNamespace(
        run=fixture_process, PIPE=subprocess.PIPE, TimeoutExpired=subprocess.TimeoutExpired),
        TOOLS={"dotnet": "fixture-dotnet", "ilspy": "fixture-ilspy"},
        ILSPY="fixture-ilspy", PYLIB="", CLR_STATUS="processed", write_clr_md=lambda *_: None)
    exec(compile(ast.Module(body=selected, type_ignores=[]), path, "exec"), ns)
    return ns


def produce(path, ns, directory, data):
    directory.mkdir()
    fixture = directory / "stdout.bin"
    fixture.write_bytes(data)
    if path == "tool/b2_wave.py":
        ns.update(WR=directory, SRC=directory)
        it = dict(rel=fixture.name, name="fixture", dir="item", key="fixture", product="test")
        status = ns["run_clr_one"](it)["status"]
        target = ns["clr_dir"](it) / "decompiled/fixture.cs.txt"
    else:
        target = directory / "decompiled/fixture.cs.txt"
        rc, err = ns["decompile"](fixture, target, 10)
        assert not err, err
        status = f"decompile_rc={rc}"
    # For a skipped write the observed output stream has zero bytes. Presence
    # and gate rc are recorded separately so this cannot pass as an empty file.
    return (target.read_bytes() if target.exists() else b""), target, status


def gate(directory):
    process = subprocess.run(
        [sys.executable, "-I", "-B", str(ROOT / "tool/check_cs_clean.py"), str(directory)],
        capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=10)
    if process.returncode not in (0, 1, 2) or "CHECK_CS_CLEAN" not in process.stdout:
        raise ValueError((process.returncode, process.stdout, process.stderr))
    return process.returncode, process.stdout.splitlines()[-1]


def main():
    if os.name != "nt":
        raise SystemExit("Windows required to reproduce text-mode output")
    # All descendants inherit a restricted environment. Only the verified scanner,
    # Python's fixed byte emitter and the selected definitions above are executed.
    essential = {k: os.environ[k] for k in ("SYSTEMROOT", "WINDIR", "TEMP", "TMP") if k in os.environ}
    os.environ.clear()
    os.environ.update(essential)
    actual = {p: sha((ROOT / p).read_bytes()) for p in SOURCES}
    assert actual == SOURCES
    fixture_bytes = (INBOX / "fixtures.json").read_bytes()
    fixture_doc = json.loads(fixture_bytes)
    assert fixture_doc["pr_head"] == HEAD
    archived = (ROOT / "sample.cs.txt").read_bytes()
    assert sha(archived) == "2ceba82a4d3bb35449fb475d8946274afa91dd04f5914f2fd245f09d75336886"
    inputs = {name: base64.b64decode(data, validate=True) for name, data in fixture_doc["inputs"].items()}
    result = {}
    log = ["NAG-GENERATOR-373 s1 actual stdout replay",
           f"Python {platform.python_version()}; Windows {platform.version()}; os.linesep={os.linesep!r}",
           f"main=7f909cc1e03e785e1165c110ac857a6ba9a3888a PR373={HEAD}",
           "Process environment allowlist: SYSTEMROOT WINDIR TEMP TMP. Python -I -B.",
           "External ILSpy stdout injected by a real child process writing exact input bytes; no original DLL execution.",
           "B2: unmodified run_clr_one and strip_tool_nag, stub IL side product and report, real text-mode pipe and write_text.",
           "batch: unmodified decompile and strip_tool_nag, real binary stdout file and rewrite; outer manifest not invoked.",
           "gate: full unmodified tool/check_cs_clean.py invoked in a separate process on single-case directories.",
           "Both phases use fresh targets. For a missing artifact, present=false, base64 empty, and the real gate scans its empty directory.",
           "A missing first output is replayed with a zero-byte stream. Its missing-file status remains separately visible.",
           f"fixtures_sha256={sha(fixture_bytes)}", *(f"{p} sha256={h}" for p, h in SOURCES.items()),
           f"archived_stdout_sha256={sha(archived)} bytes={len(archived)} CRLF={archived.count(bytes([13,10]))} LF={archived.count(bytes([10]))}",
           "Archived sample ends in ILSpy upgrade 11.2.0.10050 / current 9.1.0.7988. Additional sample measurements follow fixtures."]
    with tempfile.TemporaryDirectory(dir=ROOT) as scratch:
        for path, funcs in (
            ("tool/b2_wave.py", {"strip_tool_nag", "run_clr_one", "ensure", "clr_dir"}),
            ("tool/batch_reverse.py", {"strip_tool_nag", "decompile", "long_path", "ensure_dir"})):
            ns = load_functions(path, funcs)
            result[path] = {}
            for name, data in {**inputs, "extra-archived-stdout": archived}.items():
                case = Path(scratch) / Path(path).stem / name
                raw = case / "raw"
                raw.mkdir(parents=True)
                (raw / "fixture.cs.txt").write_bytes(data)
                raw_rc, raw_line = gate(raw)
                once, first, status1 = produce(path, ns, case / "first", data)
                twice, second, status2 = produce(path, ns, case / "second", once)
                after_rc, after_line = gate(first.parent)
                log.append(f"{path}/{name} raw={sha(data)} raw_gate={raw_rc} [{raw_line}] "
                           f"once={sha(once)} bytes={len(once)} present={first.exists()} status={status1} "
                           f"after_gate={after_rc} [{after_line}] twice={sha(twice)} bytes={len(twice)} "
                           f"present={second.exists()} status={status2}")
                if name in inputs:
                    result[path][name] = dict(once_b64=b64(once), twice_b64=b64(twice),
                                              once_present=first.exists(), twice_present=second.exists(),
                                              raw_gate_exit=raw_rc, after_gate_exit=after_rc)
    log_bytes = ("\n".join(log) + "\n").encode("utf-8")
    (INBOX / "run.log").write_bytes(log_bytes)
    report = dict(pr_head=HEAD, sources_sha256=actual, fixtures_sha256=sha(fixture_bytes),
                  run_log_sha256=sha(log_bytes), producers=result)
    (INBOX / "results.json").write_bytes((json.dumps(report, indent=2) + "\n").encode("utf-8"))


if __name__ == "__main__":
    main()
