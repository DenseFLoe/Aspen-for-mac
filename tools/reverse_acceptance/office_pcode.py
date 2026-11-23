"""Original VBA source and cache procedure inventories, without executing VBA."""
from collections import Counter
from importlib import metadata
import io
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile
from types import SimpleNamespace

if __package__:
    from .office_vba import CFB
else:
    from office_vba import CFB


SCOPE = "Original VBA source and cache procedure names and kinds; execution semantics unverified."
MAX_ORIGINAL = 64 * 1024 * 1024
MAX_DUMP = 16 * 1024 * 1024
DEFINITION = re.compile(
    r"^[ \t]*(?:(?:public|private|friend|static|default)\s+)*"
    r"(sub|function|property\s+(?:get|let|set))\s+([^\W\d]\w*)\s*\(",
    re.I,
)
MODULE = re.compile(r"^((?:.*/)?VBA/[^/]+) - [0-9]+ bytes$", re.I)
CACHED = re.compile(r"^[ \t]*FuncDefn\s+\(")
OPAQUE = re.compile(r"<crash>|\bid_[0-9A-Fa-f]{4}\b|Unrecognized opcode")


def procedure(text):
    match = DEFINITION.match(text)
    if match is None:
        return None
    kind, name = match.groups()
    return " ".join(kind.casefold().split()), name.casefold()


def source_rows(compound, host):
    import olefile
    from oletools.olevba import VBA_Project

    with olefile.OleFileIO(io.BytesIO(compound), raise_defects=olefile.DEFECT_INCORRECT) as ole:
        paths = ole.listdir()
        wanted = ("_vba_project_cur", "vba", "dir") if host == "BIFF" else ("vba", "dir")
        directories = [p for p in paths if [v.casefold() for v in p[-2:]] == ["vba", "dir"]]
        if len(directories) != 1 or tuple(v.casefold() for v in directories[0]) != wanted:
            raise ValueError("project root is ambiguous or unsupported")
        if host == "BIFF" and not any(len(p) == 1 and p[0].casefold() in {"book", "workbook"} for p in paths):
            raise ValueError("missing Excel workbook")
        directory = directories[0]
        prefix = "/".join(directory[:-2]) + "/" if directory[:-2] else ""
        project = VBA_Project(ole, prefix, prefix + "PROJECT", "/".join(directory), relaxed=False)
        project.parse_project_stream()
        for _ in project.parse_modules():
            pass
        if not project.modules_count or project.modules_count != len(project.modules):
            raise ValueError("module inventory is incomplete")
        module_names = {module.name.casefold() for module in project.modules}
        if module_names != {name.casefold() for name in project.module_ext}:
            raise ValueError("module declarations disagree")
        sources = {}
        for module in project.modules:
            path = module.code_path.casefold()
            if path in sources or module.code_raw is None:
                raise ValueError("invalid module binding")
            source = module.code_raw.decode(project.codec, errors="strict")
            logical = re.sub(r"[ \t]+_[ \t]*\r?\n", " ", source)
            sources[path] = Counter(row for line in logical.splitlines() if (row := procedure(line)))
        if len(module_names) != len(sources):
            raise ValueError("duplicate module declarations")
        return sources


def compare_dump(sources, dump):
    cached = {}
    unknown = 0
    current = None
    for line in dump.splitlines():
        module = MODULE.fullmatch(line)
        if module:
            current = module[1].casefold()
            if current in cached:
                raise ValueError("duplicate decoded stream")
            cached[current] = Counter()
        elif definition := CACHED.match(line):
            row = procedure(line[definition.end():])
            if current is None or row is None or OPAQUE.search(line[definition.end():].split("(", 1)[0]):
                unknown += 1
            else:
                cached[current][row] += 1
    modules = []
    for path in sorted(sources.keys() | cached.keys()):
        source = sources.get(path, Counter())
        decoded = cached.get(path, Counter())
        modules.append({
            "stream": path,
            "source_declarations": source.total(),
            "decoded_declarations": decoded.total(),
            "matched_name_and_kind": (source & decoded).total(),
            "source_stream_listed": path in sources,
            "cache_stream_listed": path in cached,
        })
    return {
        "modules": modules,
        "matched_name_and_kind": sum(row["matched_name_and_kind"] for row in modules),
        "unclassified_cache_declarations": unknown,
        "opaque_cache_markers": dict(Counter(OPAQUE.findall(dump))),
    }


class LimitedOutput:
    """Bound the cache dump before it reaches the caller."""

    def __init__(self):
        self.total = 0

    def write(self, text):
        self.total += len(text)
        if self.total > MAX_DUMP:
            raise ValueError("p-code output exceeds limit")
        return sys.stdout.write(text)

    def isatty(self):
        return False


def worker(path, layout):
    from pcodedmp import pcodedmp as pc

    if layout == "vba7_x64_contiguous_identifiers":
        stock = pc.getID

        def contiguous(code, identifiers, version, wide):
            index = (code >> 1) - 0x107
            if version == 7 and wide and 0 <= index < len(identifiers):
                return identifiers[index]
            return stock(code, identifiers, version, wide)

        pc.getID = contiguous
    pc.processFile(path, SimpleNamespace(disasmOnly=True, verbose=False), output_file=LimitedOutput())


def check(original, delivery):
    findings = [{"code": "vba_cache_semantics_unverified"}]
    metrics = {}
    result = {"scope": SCOPE, "status": "inconclusive", "metrics": metrics, "findings": findings}
    try:
        metrics["decoder"] = {"package": "pcodedmp", "version": metadata.version("pcodedmp")}
    except metadata.PackageNotFoundError:
        findings.append({"code": "vba_cache_decoder_unavailable"})
        return result
    try:
        if len(original) > MAX_ORIGINAL:
            raise ValueError("original exceeds size limit")
        if not original.startswith(CFB):
            raise ValueError("unsupported VBA cache container")
        compound = original
        sources = source_rows(compound, "BIFF")
    except (ValueError, ImportError, AttributeError, IndexError, KeyError, OSError, TypeError):
        findings.append({"code": "vba_cache_original_project_unverified"})
        return result
    with tempfile.TemporaryDirectory(prefix="aspen-vba-cache-") as scratch:
        path = Path(scratch) / "original.ole"
        path.write_bytes(compound)
        layouts = {}
        environment = dict(os.environ)
        candidate = Path(delivery).resolve()
        paths = [Path(p).resolve() for p in environment.get("PYTHONPATH", "").split(os.pathsep) if p]
        environment["PYTHONPATH"] = os.pathsep.join(str(p) for p in paths if not p.is_relative_to(candidate))
        for layout in ("stock", "vba7_x64_contiguous_identifiers"):
            args = [sys.executable, "-X", "utf8", "-B", str(Path(__file__).resolve()), "--decoder", str(path), layout]
            try:
                run = subprocess.run(args, capture_output=True, timeout=30, cwd=scratch, env=environment)
                if run.returncode or run.stderr or len(run.stdout) > MAX_DUMP:
                    raise ValueError("decoder unavailable or incomplete")
                layouts[layout] = compare_dump(sources, run.stdout.decode("utf-8", errors="strict"))
            except (ValueError, OSError, subprocess.TimeoutExpired):
                layouts[layout] = {"status": "unverified"}
    metrics.update(source_modules=len(sources), source_declarations=sum(rows.total() for rows in sources.values()),
                   layouts=layouts)
    findings.append({"code": "vba_cache_layout_not_authenticated"})
    return result


if __name__ == "__main__" and len(sys.argv) == 4 and sys.argv[1] == "--decoder":
    worker(sys.argv[2], sys.argv[3])
