"""One positive static proof: freshly compiled editable C# reproduces the entire PE."""
import hashlib
import os
from pathlib import Path
import re
import stat
import subprocess
import tempfile


SCOPE = "whole PE byte equivalence from submitted C# under fixed Roslyn 5.0/.NET Framework mscorlib"
PROFILE = "roslyn-5.0-netfx48-csharp12-release-anycpu-v1"
DRIVER = Path(__file__).with_name("compile_fresh_cs.ps1")
# A trusted local installation supplies both Roslyn libraries. Never choose a
# compiler, response file, project, analyzer or reference from a submission.
POWERSHELLS = (
    Path.home() / ".cache/codex-runtimes/codex-primary-runtime/dependencies/native/powershell",
    Path("C:/Program Files/PowerShell/7"),
)
PINNED = {
    "pwsh.exe": "2a6769a3330dc1084d0154bfde7d164ab750ca7f700f313f9d417c1be78b2233",
    "pwsh.dll": "682c403fd13e667ff9c67f28750c8fedec8ad60f962662d83642b48a6c3f2154",
    "System.Management.Automation.dll": "e767f5c26347b254dd06fa0b65e18424cc4eb93fc3102c5a8fdd9dd88355db97",
    "Microsoft.CodeAnalysis.dll": "e7a25cbdec95390e9672659872189da368032625d784c25569617617932c145f",
    "Microsoft.CodeAnalysis.CSharp.dll": "5e9323e98d99f669acd10705c40d985dbabeaf0984285ed32922f91df223124b",
}
REFERENCE = Path("C:/Windows/Microsoft.NET/Framework64/v4.0.30319/mscorlib.dll")
REFERENCE_SHA = "cbc11526803d1fdd3dbdd42c3899d18feec58eaf572941302c51d6710721e90a"
MAX_FILES = 256
MAX_TOTAL = 16 * 1024 * 1024


def _fingerprint(path):
    with path.open("rb") as reader:
        return hashlib.file_digest(reader, "sha256").hexdigest()


def _toolchain():
    if not REFERENCE.is_file() or _fingerprint(REFERENCE) != REFERENCE_SHA:
        return None
    for folder in POWERSHELLS:
        if all((folder / p).is_file() and _fingerprint(folder / p) == h for p, h in PINNED.items()):
            return folder
    return None


def _regular(path, want_dir=False):
    info = path.lstat()
    if getattr(info, "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT:
        return False
    return stat.S_ISDIR(info.st_mode) if want_dir else stat.S_ISREG(info.st_mode)


def check(original: bytes, delivery: Path, name: str) -> dict:
    metrics = {"profile": PROFILE, "original_sha256": hashlib.sha256(original).hexdigest()}

    def result(status, code=None, **detail):
        findings = [{"code": code, **detail}] if code else []
        return {"status": status, "scope": SCOPE, "findings": findings, "metrics": metrics}

    if not isinstance(name, str) or len(name) > 220 or not re.fullmatch(r"[\w][\w. -]*\.dll", name, re.I):
        return result("inconclusive", "fresh_cs_unsupported_name")
    if not original.startswith(b"MZ"):
        return result("inconclusive", "fresh_cs_original_not_pe")
    root = Path(delivery) / "fresh-cs"
    try:
        if not root.exists():
            return result("inconclusive", "fresh_cs_not_supplied")
        if not _regular(root, want_dir=True):
            return result("fail", "fresh_cs_invalid_source_directory")
        paths = []
        for p in root.iterdir():
            if not _regular(p):
                return result("inconclusive", "fresh_cs_unsupported_entry", path=p.name)
            if p.suffix.lower() == ".cs":
                paths.append(p)
            elif p.suffix.lower() != ".md":
                return result("fail", "fresh_cs_unexpected_input", path=p.name)
        if not paths:
            return result("fail", "fresh_cs_missing_sources")
        if len(paths) > MAX_FILES or sum(p.stat().st_size for p in paths) > MAX_TOTAL:
            return result("inconclusive", "fresh_cs_source_limit")
        host = _toolchain()
        if not host:
            return result("inconclusive", "fresh_cs_pinned_compiler_unavailable")
        with tempfile.TemporaryDirectory(prefix="aspen-csharp-proof-") as tmp:
            scratch = Path(tmp)
            folder = scratch / "src"
            folder.mkdir()
            sources = {}
            total = 0
            for p in sorted(paths):
                with p.open("rb") as reader:
                    source = reader.read(MAX_TOTAL - total + 1)
                total += len(source)
                if total > MAX_TOTAL:
                    return result("inconclusive", "fresh_cs_source_limit")
                (folder / p.name).write_bytes(source)
                sources[p.name] = hashlib.sha256(source).hexdigest()
            metrics.update(source_sha256=sources, source_count=len(sources),
                           reference_sha256=REFERENCE_SHA, compiler_sha256=PINNED["Microsoft.CodeAnalysis.CSharp.dll"])
            output = scratch / "result.dll"
            env = {k: v for k, v in os.environ.items() if k.upper() in
                   {"SYSTEMROOT", "WINDIR", "LOCALAPPDATA", "USERPROFILE", "TEMP", "TMP"}}
            env["PSModulePath"] = str(host / "Modules")
            run = subprocess.run([str(host / "pwsh.exe"), "-NoProfile", "-NoLogo", "-NonInteractive", "-File",
                                  str(DRIVER.resolve()), name[:-4], str(folder), str(REFERENCE), str(output)],
                                 env=env, cwd=scratch, stdin=subprocess.DEVNULL, capture_output=True, timeout=90)
            if run.returncode:
                detail = run.stderr[-1000:].decode("utf-8", "replace").strip()
                # A reference, language or build setting outside this profile
                # may still produce the original. A compile error cannot prove otherwise.
                return result("inconclusive", "fresh_cs_profile_compile_error", diagnostic=detail)
            version = run.stdout.decode("ascii", "replace").strip()
            if not re.fullmatch(r"\d+\.\d+\.\d+\.\d+", version):
                return result("inconclusive", "fresh_cs_assembly_version_unreadable")
            metrics["assembly_version"] = version
            rebuilt = output.read_bytes()
    except (OSError, RuntimeError, subprocess.TimeoutExpired) as exc:
        return result("inconclusive", "fresh_cs_check_unavailable", reason=str(exc))
    metrics.update(original_bytes=len(original), rebuilt_bytes=len(rebuilt),
                   rebuilt_sha256=hashlib.sha256(rebuilt).hexdigest())
    if rebuilt != original:
        first = next((i for i, (a, b) in enumerate(zip(original, rebuilt)) if a != b),
                     min(len(original), len(rebuilt)))
        return result("inconclusive", "fresh_cs_pe_differs", first_file_offset=first)
    return result("pass")

