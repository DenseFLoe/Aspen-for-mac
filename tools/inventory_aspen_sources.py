"""Read-only Aspen installer-first inventory; all evidence stays in a new local path.

Uses Windows Installer's read-only database API and Cabinet FDI, never installs or
executes an input file. Cabinet members are hashed in memory without unpacking to
disk. The two categories describe code recovery, not development completion.
"""

import argparse
import collections
import concurrent.futures
import csv
import ctypes as C
from ctypes import wintypes as W
import datetime as dt
import hashlib
import io
import json
import os
from pathlib import Path
import struct
import zipfile


REVERSE = "01-needs-reverse"
DIRECT = "02-no-reverse"
HEAD_LIMIT = 1024 * 1024
CODE_EXT = {".exe", ".dll", ".ocx", ".sys", ".scr", ".cpl", ".pyd", ".ax",
            ".lib", ".obj", ".o", ".a", ".so", ".dylib", ".class", ".pyc",
            ".pyo", ".wasm", ".dex", ".jar", ".xla", ".xlam", ".xlsm", ".dotm"}
TEXT_EXT = set(".txt .md .xml .json .yaml .yml .ini .cfg .config .csv .tsv .html .htm .css .js .mjs .vbs .vbe .bat .cmd .ps1 .py .c .cpp .h .hpp .f .for .f90 .f95 .cs .vb .bas .sql .reg .url .manifest .sgxml .xaml .xsd .xslt .xsl .rtf .log .cmn .inc .htc .mcwebhelp".split())
DATA_EXT = set(".ico .cur .ani .png .jpg .jpeg .gif .bmp .svg .tif .tiff .webp .emf .wmf .pdf .doc .docx .xls .xlsx .ppt .pptx .chm .hlp .cnt .ttf .otf .woff .woff2 .tlb .olb .pdb .lnk .sqlite .db .mdb .mdf .ldf .bak .bkp .aprbkp .apt .apw .apwz .aprsdf .appdf .dat .bin .tbl .pak .res .resources .sdf .msf .cst .hms .pda .ebs .edr .dllmanifest .cdb .rpt .out .sum .prp .pro .dtd .map .exp .nls .sig .ort .model .gitattributes .gitignore".split())
CONTAINER_EXT = {".cab", ".msi", ".msp", ".msm", ".iso", ".zip", ".7z", ".rar", ".gz", ".tar"}
FIELDS = ["category", "extension", "source", "priority", "scope", "relative_path", "original_path",
          "container", "member", "size_bytes", "sha256", "version", "format", "reason",
          "review", "read_status", "msi_file_id", "msi_component", "msi_version", "msi_size",
          "msi_size_match", "analysis_key", "primary_sha_matches"]


def emit_json(path, value):
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def emit_csv(path, rows, fields=FIELDS):
    with path.open("w", encoding="utf-8-sig", newline="") as stream:
        writer = csv.DictWriter(stream, fields, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def order(row):
    return (row["category"], row["extension"], row.get("priority", 9), row["source"],
            row["relative_path"].casefold())


def pe_info(head):
    """Read bounded PE/CLR metadata, including MethodDef count for resource assemblies."""
    offset = struct.unpack_from("<I", head, 0x3C)[0]
    if head[offset:offset + 4] != b"PE\0\0":
        raise ValueError("MZ without PE signature")
    sections, optional_size = struct.unpack_from("<H12xH", head, offset + 6)
    optional = offset + 24
    magic = struct.unpack_from("<H", head, optional)[0]
    if magic not in (0x10B, 0x20B):
        raise ValueError("unknown optional header")
    directory = optional + (112 if magic == 0x20B else 96)
    section_base = optional + optional_size
    section_rows = [struct.unpack_from("<8sIIIIIIHHI", head, section_base + 40 * i) for i in range(sections)]

    def raw(rva):
        for sec in section_rows:
            if sec[2] <= rva < sec[2] + max(sec[1], sec[3]):
                return sec[4] + rva - sec[2]
        return rva

    has_code = any(s[3] and s[9] & 0x20000000 for s in section_rows)
    cli_rva = struct.unpack_from("<I", head, directory + 14 * 8)[0]
    if not cli_rva:
        return ("PE-native", has_code, None, None)
    cli = raw(cli_rva)
    flags = struct.unpack_from("<I", head, cli + 16)[0]
    methods = None
    try:
        metadata = raw(struct.unpack_from("<I", head, cli + 8)[0])
        if head[metadata:metadata + 4] == b"BSJB":
            version_len = struct.unpack_from("<I", head, metadata + 12)[0]
            streams_header = (metadata + 16 + version_len + 3) & ~3
            streams = struct.unpack_from("<H", head, streams_header + 2)[0]
            pos = streams_header + 4
            for _ in range(streams):
                stream_offset = struct.unpack_from("<I", head, pos)[0]
                end = head.index(b"\0", pos + 8)
                name = head[pos + 8:end]
                pos = (end + 4) & ~3
                if name in (b"#~", b"#-"):
                    tables = metadata + stream_offset
                    valid = struct.unpack_from("<Q", head, tables + 8)[0]
                    if valid & (1 << 6):
                        methods = struct.unpack_from("<I", head, tables + 24 + 4 * (valid & 63).bit_count())[0]
                    else:
                        methods = 0
    except (ValueError, IndexError, struct.error):
        pass
    return ("PE-CLR-IL-only" if flags & 1 else "PE-CLR-mixed", has_code, flags, methods)


def classify(name, head):
    ext = Path(name).suffix.lower() or "(no extension)"
    if head.startswith(b"MZ"):
        try:
            kind, code, flags, methods = pe_info(head)
            if (flags is not None and flags & 1 and methods == 0) or (flags is None and not code):
                return DIRECT, kind, "资源/元数据 PE；无托管方法或无原生可执行区段", ""
            return REVERSE, kind, "含编译代码；托管反编译/原生反汇编，尚未执行", "" if flags is None or methods is not None else "CLR 元数据超出文件头窗口，方法数待核实"
        except (ValueError, IndexError, struct.error):
            return REVERSE, "MZ-unresolved", "程序格式待核实，保守纳入逆向候选", "PE 头未完整解析"
    if head.startswith(b"!<arch>\n"):
        return REVERSE, "COFF/archive", "编译库；区分实现库和仅导入库后决定具体工作", "成员级实现/导入属性待核实"
    if head.startswith((b"\x7fELF", b"\0asm", b"\xca\xfe\xba\xbe", b"dex\n")):
        return REVERSE, "compiled-code", "编译代码，需对应格式的逆向工具", ""
    if head.startswith((b"\0\0\x01\0", b"\0\0\x02\0", b"\x89PNG\r\n\x1a\n", b"GIF87a", b"GIF89a")):
        return DIRECT, "image/resource", "图像/图标，按格式直接读取或提取", ""
    if ext in CODE_EXT:
        return REVERSE, "code-or-macro-candidate", "程序/对象/字节码/宏载体，需进一步检查内部代码", "按后缀保守列入，内部格式待核实"
    if head.startswith(b"MSCF") or ext in CONTAINER_EXT:
        return DIRECT, "container", "容器本身按格式读取；包内程序另列，不能由容器类别推断包内无代码", ""
    if head.startswith((b"PK\x03\x04", b"PK\x05\x06")):
        return DIRECT, "ZIP/container", "按 ZIP 读取；内嵌代码另列", ""
    if ext in TEXT_EXT:
        return DIRECT, "readable-source/config/document", "已有文本/源码/脚本，直接读取，无须反编译", ""
    if ext in DATA_EXT or head.startswith((b"%PDF-", b"SQLite format 3\0", b"ITSF", b"MSFT", b"SLTG", b"\x89PNG", b"GIF8")):
        return DIRECT, "resource/data/document", "按原格式读取/提取/解析；不是可执行逻辑，格式解析可能仍需研究", ""
    if not head:
        return DIRECT, "empty", "空文件，无代码可逆向", ""
    if b"\0" not in head[:4096]:
        for encoding in ("utf-8-sig", "cp1252"):
            try:
                sample = head[:4096].decode(encoding)
                if sum(c.isprintable() or c in "\r\n\t\f" for c in sample) / max(len(sample), 1) > .97:
                    return DIRECT, "text", "文件头可读文本，直接读取", ""
            except UnicodeError:
                pass
    return REVERSE, "unknown-binary", "未知二进制，保守纳入待核实候选，尚未证明含代码", "未知格式；不得认定已完成逆向"


def record(name, head, **fields):
    category, kind, reason, review = classify(name, head)
    return dict(category=category, extension=Path(name).suffix.lower() or "(no extension)",
                format=kind, reason=reason, review=review,
                _zip=head.startswith((b"PK\x03\x04", b"PK\x05\x06")), **fields)


def digest_stream(stream):
    digest = hashlib.sha256()
    head = bytearray()
    length = 0
    while chunk := stream.read(1024 * 1024):
        digest.update(chunk)
        length += len(chunk)
        head.extend(chunk[:max(0, HEAD_LIMIT - len(head))])
    return digest.hexdigest(), bytes(head), length


def file_version(path):
    api = C.WinDLL("version", use_last_error=True)
    dummy = W.DWORD()
    size = api.GetFileVersionInfoSizeW(str(path), C.byref(dummy))
    if not size:
        return ""
    data = C.create_string_buffer(size)
    if not api.GetFileVersionInfoW(str(path), 0, size, data):
        return ""
    pointer = C.c_void_p()
    length = W.UINT()
    if not api.VerQueryValueW(data, "\\", C.byref(pointer), C.byref(length)) or length.value < 16:
        return ""
    fixed = C.cast(pointer, C.POINTER(W.DWORD))
    high, low = fixed[2], fixed[3]
    return f"{high >> 16}.{high & 65535}.{low >> 16}.{low & 65535}"


class MsiReader:
    def __init__(self, path):
        self.api = C.WinDLL("msi")
        self.handle = W.UINT()
        self.check(self.api.MsiOpenDatabaseW(str(path), None, C.byref(self.handle)))

    @staticmethod
    def check(code):
        if code:
            raise OSError(f"Windows Installer API returned {code}")

    def rows(self, table, columns):
        query = "SELECT " + ",".join(f"`{c}`" for c in columns) + f" FROM `{table}`"
        view = W.UINT()
        self.check(self.api.MsiDatabaseOpenViewW(self.handle, query, C.byref(view)))
        try:
            self.check(self.api.MsiViewExecute(view, 0))
            while True:
                item = W.UINT()
                code = self.api.MsiViewFetch(view, C.byref(item))
                if code == 259:
                    return
                self.check(code)
                try:
                    result = {}
                    for i, name in enumerate(columns, 1):
                        count = W.DWORD(32767)
                        buffer = C.create_unicode_buffer(count.value + 1)
                        self.check(self.api.MsiRecordGetStringW(item, i, buffer, C.byref(count)))
                        result[name] = buffer.value
                    yield result
                finally:
                    self.api.MsiCloseHandle(item)
        finally:
            self.api.MsiViewClose(view)
            self.api.MsiCloseHandle(view)

    def close(self):
        self.api.MsiCloseHandle(self.handle)

    def streams(self, table):
        view = W.UINT()
        self.check(self.api.MsiDatabaseOpenViewW(self.handle, f"SELECT `Name`,`Data` FROM `{table}`", C.byref(view)))
        try:
            self.check(self.api.MsiViewExecute(view, 0))
            while True:
                item = W.UINT()
                code = self.api.MsiViewFetch(view, C.byref(item))
                if code == 259:
                    return
                self.check(code)
                try:
                    count = W.DWORD(32767)
                    name = C.create_unicode_buffer(count.value + 1)
                    self.check(self.api.MsiRecordGetStringW(item, 1, name, C.byref(count)))
                    digest = hashlib.sha256()
                    head = bytearray()
                    size = 0
                    while True:
                        data = C.create_string_buffer(1024 * 1024)
                        count = W.DWORD(len(data))
                        self.check(self.api.MsiRecordReadStream(item, 2, data, C.byref(count)))
                        if not count.value:
                            break
                        chunk = data.raw[:count.value]
                        digest.update(chunk)
                        size += count.value
                        head.extend(chunk[:max(0, HEAD_LIMIT - len(head))])
                    yield dict(name=name.value, sha256=digest.hexdigest(), head=bytes(head), size=size)
                finally:
                    self.api.MsiCloseHandle(item)
        finally:
            self.api.MsiViewClose(view)
            self.api.MsiCloseHandle(view)


def scan_msi_streams(path, product_label="Aspen-Plus"):
    reader = MsiReader(path)
    rows = []
    try:
        for table in ("Binary", "Icon"):
            for item in reader.streams(table):
                rows.append(record(item["name"], item["head"], source="installer-msi-stream", priority=1,
                                   scope=product_label + "-installer-stream", relative_path=table + "/" + item["name"],
                                   original_path=str(path), container=str(path), member=table + "/" + item["name"],
                                   size_bytes=item["size"], sha256=item["sha256"], version="", read_status="ok"))
    finally:
        reader.close()
    return rows


def msi_manifest(path):
    reader = MsiReader(path)
    try:
        tables = {table: list(reader.rows(table, fields)) for table, fields in {
            "File": ["File", "Component_", "FileName", "FileSize", "Version", "Sequence"],
            "Media": ["DiskId", "LastSequence", "Cabinet"],
            "Component": ["Component", "Directory_"],
            "Directory": ["Directory", "Directory_Parent", "DefaultDir"],
            "Property": ["Property", "Value"],
        }.items()}
    finally:
        reader.close()
    directories = {r["Directory"]: r for r in tables["Directory"]}
    components = {r["Component"]: r["Directory_"] for r in tables["Component"]}

    def target_dir(key, seen=()):
        if key in seen:
            raise ValueError("MSI directory cycle")
        if key not in directories:
            return "[" + key + "]"
        row = directories[key]
        folder = row["DefaultDir"].split(":")[0].split("|")[-1]
        # Property directories are symbolic roots, not guessed machine paths.
        if key in {"TARGETDIR", "ProgramFiles64Folder", "ProgramFilesFolder", "CommonFiles64Folder",
                   "CommonFilesFolder", "CommonAppDataFolder", "WindowsFolder", "SystemFolder", "System64Folder"}:
            return "[" + key + "]"
        parent = target_dir(row["Directory_Parent"], seen + (key,)) if row["Directory_Parent"] else ""
        return "/".join(x for x in (parent, folder if folder != "." else "") if x)

    media = sorted(tables["Media"], key=lambda r: int(r["LastSequence"]))
    for row in tables["File"]:
        row["target_relative_path"] = target_dir(components[row["Component_"]]) + "/" + row["FileName"].split("|")[-1]
        row["cabinet"] = next((r["Cabinet"] for r in media if int(row["Sequence"]) <= int(r["LastSequence"])), "")
    return tables


class CabinetScanner:
    """Windows Cabinet FDI callbacks. No member bytes are written to disk."""
    def __init__(self):
        self.api = C.CDLL("cabinet")
        heapapi = C.WinDLL("kernel32", use_last_error=True)
        heapapi.GetProcessHeap.restype = C.c_void_p
        heapapi.HeapAlloc.argtypes = [C.c_void_p, W.DWORD, C.c_size_t]
        heapapi.HeapAlloc.restype = C.c_void_p
        heapapi.HeapFree.argtypes = [C.c_void_p, W.DWORD, C.c_void_p]
        heap = heapapi.GetProcessHeap()
        ip = C.c_ssize_t

        class Notification(C.Structure):
            _fields_ = [("cb", C.c_long), ("psz1", C.c_char_p), ("psz2", C.c_char_p),
                        ("psz3", C.c_char_p), ("pv", C.c_void_p), ("hf", ip),
                        ("date", C.c_ushort), ("time", C.c_ushort), ("attribs", C.c_ushort),
                        ("setID", C.c_ushort), ("iCabinet", C.c_ushort),
                        ("iFolder", C.c_ushort), ("fdie", C.c_int)]

        class Error(C.Structure):
            _fields_ = [("operation", C.c_int), ("type", C.c_int), ("present", C.c_int)]

        self.error = Error()
        self.sinks = {}
        self.results = []
        self.failures = []
        self.counter = 1000000
        self.inputs = set()

        def guarded_open(path, flags, mode):
            try:
                fd = os.open(os.fsdecode(path.decode("mbcs")), os.O_RDONLY | os.O_BINARY)
                self.inputs.add(fd)
                return fd
            except OSError as exc:
                self.failures.append(str(exc))
                return -1

        def read(fd, buffer, count):
            try:
                data = os.read(fd, count)
                C.memmove(buffer, data, len(data))
                return len(data)
            except OSError as exc:
                self.failures.append(str(exc))
                return 0xFFFFFFFF

        def write(fd, buffer, count):
            try:
                sink = self.sinks[fd]
                data = C.string_at(buffer, count)
                if sink["size"] == 0 and data.startswith((b"PK\x03\x04", b"PK\x05\x06")):
                    sink["archive"] = bytearray()
                if "archive" in sink:
                    sink["archive"].extend(data)
                sink["hash"].update(data)
                sink["head"].extend(data[:max(0, HEAD_LIMIT - len(sink["head"]))])
                sink["size"] += count
                return count
            except Exception as exc:
                self.failures.append(str(exc))
                return 0xFFFFFFFF

        def close(fd):
            try:
                os.close(fd)
                self.inputs.discard(fd)
                return 0
            except OSError:
                return -1

        def seek(fd, distance, mode):
            try:
                return os.lseek(fd, distance, mode)
            except OSError:
                return -1

        def notify(kind, pointer):
            note = pointer.contents
            if kind == 2:  # fdintCOPY_FILE
                self.counter += 1
                self.sinks[self.counter] = dict(name=note.psz1.decode("utf-8" if note.attribs & 128 else "mbcs"),
                                               expected=note.cb, size=0, hash=hashlib.sha256(), head=bytearray())
                return self.counter
            if kind == 3:  # fdintCLOSE_FILE_INFO
                sink = self.sinks.pop(note.hf)
                sink["sha256"] = sink.pop("hash").hexdigest()
                sink["head"] = bytes(sink["head"])
                self.results.append(sink)
                return 1
            if kind == 1:
                self.failures.append("partial cabinet member: " + note.psz1.decode("mbcs"))
            return 0

        definitions = [
            (C.CFUNCTYPE(C.c_void_p, C.c_ulong), lambda size: heapapi.HeapAlloc(heap, 0, size)),
            (C.CFUNCTYPE(None, C.c_void_p), lambda pointer: heapapi.HeapFree(heap, 0, pointer)),
            (C.CFUNCTYPE(ip, C.c_char_p, C.c_int, C.c_int), guarded_open),
            (C.CFUNCTYPE(C.c_uint, ip, C.c_void_p, C.c_uint), read),
            (C.CFUNCTYPE(C.c_uint, ip, C.c_void_p, C.c_uint), write),
            (C.CFUNCTYPE(C.c_int, ip), close),
            (C.CFUNCTYPE(C.c_long, ip, C.c_long, C.c_int), seek),
        ]
        self.callbacks = [prototype(func) for prototype, func in definitions]
        self.notify = C.CFUNCTYPE(ip, C.c_int, C.POINTER(Notification))(notify)
        self.api.FDICreate.argtypes = [type(c) for c in self.callbacks] + [C.c_int, C.POINTER(Error)]
        self.api.FDICreate.restype = C.c_void_p
        self.api.FDICopy.argtypes = [C.c_void_p, C.c_char_p, C.c_char_p, C.c_int, type(self.notify), C.c_void_p, C.c_void_p]
        self.api.FDICopy.restype = C.c_int
        self.api.FDIDestroy.argtypes = [C.c_void_p]
        self.context = self.api.FDICreate(*self.callbacks, 1, C.byref(self.error))
        if not self.context:
            raise OSError("FDICreate failed")

    def scan(self, path):
        self.results = []
        self.failures = []
        ok = self.api.FDICopy(self.context, path.name.encode("mbcs"), (str(path.parent) + "\\").encode("mbcs"),
                              0, self.notify, None, None)
        if not ok or self.failures or self.sinks:
            raise OSError(f"FDI {self.error.operation}/{self.error.type}: {self.failures}; unclosed={len(self.sinks)}")
        return self.results

    def close(self):
        self.api.FDIDestroy(self.context)
        for fd in list(self.inputs):
            os.close(fd)
        self.inputs.clear()


def physical_file(task):
    source, priority, scope, root, path = task
    common = dict(source=source, priority=priority, scope=scope, relative_path=path.relative_to(root).as_posix(),
                  original_path=str(path), container="", member="")
    before = None
    try:
        before = path.stat()
        with path.open("rb") as stream:
            sha, head, size = digest_stream(stream)
        after = path.stat()
        status = "ok" if (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns) else "changed-during-read"
        return record(path.name, head, **common, size_bytes=size, sha256=sha,
                      version=file_version(path) if head.startswith(b"MZ") else "", read_status=status)
    except (OSError, ValueError) as exc:
        return record(path.name, b"unreadable\0", **common, size_bytes=before.st_size if before else "", sha256="", version="",
                      read_status="error: " + str(exc))


def walk(root, errors):
    def error(exc):
        errors.append(dict(path=str(exc.filename), error=str(exc)))
    for directory, dirs, files in os.walk(root, followlinks=False, onerror=error):
        dirs[:] = sorted(d for d in dirs if not Path(directory, d).is_symlink())
        for name in sorted(files):
            yield Path(directory, name)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--media-root", required=True, type=Path)
    parser.add_argument("--installer", required=True, type=Path)
    parser.add_argument("--product-label", default="Aspen-Plus",
                        help="product scope label; defaults to the historical Aspen Plus scan")
    parser.add_argument("--backup-root", action="append", type=Path, default=[])
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--physical-evidence", type=Path,
                        help="reuse a same-scope physical-files.csv snapshot, preserving its original timestamp and evidence")
    args = parser.parse_args()
    if args.output.exists():
        parser.error("output must be a new path; existing evidence is never overwritten")
    args.output.mkdir(parents=True)
    started = dt.datetime.now(dt.timezone.utc).isoformat()
    errors = []
    manifest = msi_manifest(args.installer)
    emit_json(args.output / "msi-tables.json", manifest)
    by_id = {row["File"].casefold(): row for row in manifest["File"]}
    product = dict((r["Property"], r["Value"]) for r in manifest["Property"])
    emit_json(args.output / "selection.json", dict(primary="installer", primary_path=str(args.installer), product_label=args.product_label,
              fallback="installed files only for supplements and hash comparison", product=product.get("ProductName"),
              version=product.get("ProductVersion"), media_root=str(args.media_root),
              backup_roots=list(map(str, args.backup_root)), started_utc=started))

    if args.physical_evidence:
        selection = json.loads((args.physical_evidence.parent / "selection.json").read_text(encoding="utf-8"))
        if (selection["media_root"] != str(args.media_root) or selection["backup_roots"] != list(map(str, args.backup_root))
                or selection["primary_path"] != str(args.installer)):
            raise ValueError("physical evidence scope differs from requested scope")
        with args.physical_evidence.open(encoding="utf-8-sig", newline="") as stream:
            physical = list(csv.DictReader(stream))
        for row in physical:
            row["priority"] = int(row["priority"])
            if row["size_bytes"]:
                row["size_bytes"] = int(row["size_bytes"])
            elif row["read_status"].startswith("error:"):
                # Directory metadata remains readable for some locked databases.
                try:
                    row["size_bytes"] = Path(row["original_path"]).stat().st_size
                except OSError:
                    pass
            row["_zip"] = False
            if row["format"] == "ZIP/container" or row["extension"] in {".zip", ".jar", ".xlam", ".xlsm", ".docx", ".xlsx", ".pptx"}:
                try:
                    with Path(row["original_path"]).open("rb") as stream:
                        row["_zip"] = stream.read(4) in (b"PK\x03\x04", b"PK\x05\x06")
                except OSError as exc:
                    errors.append(dict(path=row["original_path"], error="ZIP probe: " + str(exc)))
        emit_json(args.output / "physical-evidence.json", dict(path=str(args.physical_evidence.resolve()),
                  sha256=hashlib.sha256(args.physical_evidence.read_bytes()).hexdigest(), started_utc=selection["started_utc"],
                  note="Reuses the original physical scan; not a second fresh scan of these files."))
        print(f"Reusing {len(physical)} physical file records from the documented snapshot", flush=True)
    else:
        tasks = []
        for path in walk(args.media_root, errors):
            scope = args.product_label + "-installer" if path.parent == args.installer.parent else "media-surroundings"
            tasks.append(("installer-media", 1 if scope == args.product_label + "-installer" else 3, scope, args.media_root, path))
        for index, root in enumerate(args.backup_root, 1):
            if not root.is_dir():
                errors.append(dict(path=str(root), error="backup root missing"))
            tasks.extend((f"installed-backup-{index}", 2, "backup-only", root, p) for p in walk(root, errors))
        print(f"Enumerated {len(tasks)} physical files; hashing every readable file", flush=True)
        physical = []
        with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
            for count, row in enumerate(pool.map(physical_file, tasks), 1):
                physical.append(row)
                if count % 2000 == 0:
                    print(f"Physical files {count}/{len(tasks)}", flush=True)
    physical.sort(key=order)
    emit_csv(args.output / "physical-files.csv", physical)

    payload = []
    embedded = []
    zip_results = []
    scanner = CabinetScanner()
    cabinets = sorted(args.installer.parent.glob("*.cab"), key=lambda p: p.name.casefold())
    cabinet_results = []
    try:
        for index, cabinet in enumerate(cabinets, 1):
            try:
                members = scanner.scan(cabinet)
                cabinet_results.append(dict(path=str(cabinet), members=len(members), bytes=sum(m["size"] for m in members), status="ok"))
                for member in members:
                    original = by_id.get(member["name"].casefold())
                    name = original["FileName"].split("|")[-1] if original else member["name"]
                    row = record(name, member["head"], source="installer-payload", priority=1, scope=args.product_label + "-payload",
                                 relative_path=original["target_relative_path"] if original else member["name"],
                                 original_path=str(args.installer), container=str(cabinet), member=member["name"],
                                 size_bytes=member["size"], sha256=member["sha256"], version=original["Version"] if original else "",
                                 read_status="ok" if member["size"] == member["expected"] else "cabinet-size-mismatch",
                                 msi_file_id=original["File"] if original else "", msi_component=original["Component_"] if original else "",
                                 msi_version=original["Version"] if original else "", msi_size=original["FileSize"] if original else "",
                                 msi_size_match=str(member["size"] == int(original["FileSize"])) if original else "unmapped")
                    if original and original["cabinet"].casefold() != cabinet.name.casefold():
                        row["read_status"] = "MSI-cabinet-mismatch"
                    payload.append(row)
                    if "archive" in member:
                        container_path = str(cabinet) + "!/" + member["name"]
                        try:
                            with zipfile.ZipFile(io.BytesIO(member["archive"])) as archive:
                                entries = [i for i in archive.infolist() if not i.is_dir()]
                                for info in entries:
                                    with archive.open(info) as stream:
                                        sha, head, size = digest_stream(stream)
                                    embedded.append(record(info.filename, head, source="installer-payload:zip-member", priority=1,
                                                           scope=args.product_label + "-payload", relative_path=row["relative_path"] + "!/" + info.filename,
                                                           original_path=str(args.installer), container=container_path, member=info.filename,
                                                           size_bytes=size, sha256=sha, version="", read_status="ok"))
                                zip_results.append(dict(path=container_path, members=len(entries), status="ok"))
                        except (OSError, ValueError, zipfile.BadZipFile, RuntimeError) as exc:
                            errors.append(dict(path=container_path, error="ZIP: " + str(exc)))
            except OSError as exc:
                errors.append(dict(path=str(cabinet), error=str(exc)))
                cabinet_results.append(dict(path=str(cabinet), status=str(exc)))
            if index % 200 == 0:
                print(f"Cabinets {index}/{len(cabinets)}; payload files {len(payload)}", flush=True)
    finally:
        scanner.close()
    payload.sort(key=order)
    emit_csv(args.output / "installer-payload.csv", payload)
    emit_json(args.output / "cabinet-results.json", cabinet_results)
    msi_streams = scan_msi_streams(args.installer, args.product_label)
    emit_csv(args.output / "installer-msi-streams.csv", sorted(msi_streams, key=order))

    for row in physical:
        if not row["_zip"]:
            continue
        path = Path(row["original_path"])
        try:
            with zipfile.ZipFile(path) as archive:
                members = [i for i in archive.infolist() if not i.is_dir()]
                for info in members:
                    if info.flag_bits & 1:
                        sha, head, size = "", b"encrypted\0", info.file_size
                        status = "encrypted-member-not-read"
                    else:
                        with archive.open(info) as stream:
                            sha, head, size = digest_stream(stream)
                        status = "ok"
                    embedded.append(record(info.filename, head, source=row["source"] + ":zip-member", priority=row["priority"],
                                           scope=row["scope"], relative_path=row["relative_path"] + "!/" + info.filename,
                                           original_path=str(path), container=str(path), member=info.filename,
                                           size_bytes=size, sha256=sha, version="", read_status=status))
                encrypted = sum(bool(i.flag_bits & 1) for i in members)
                zip_results.append(dict(path=str(path), members=len(members), encrypted_members=encrypted,
                                        status="encrypted-members-not-read" if encrypted else "ok"))
        except (OSError, ValueError, zipfile.BadZipFile, RuntimeError) as exc:
            errors.append(dict(path=str(path), error="ZIP: " + str(exc)))
    embedded.sort(key=order)
    emit_csv(args.output / "embedded-members.csv", embedded)
    emit_json(args.output / "zip-results.json", zip_results)

    primary_hashes = collections.defaultdict(list)
    for row in payload:
        if row["read_status"] == "ok":
            primary_hashes[row["sha256"]].append(row["relative_path"])
    all_rows = sorted(physical + payload + embedded + msi_streams, key=order)
    for row in all_rows:
        row["analysis_key"] = "sha256:" + row["sha256"] if row["sha256"] and row["read_status"] == "ok" else "unverified"
        row["primary_sha_matches"] = len(primary_hashes.get(row["sha256"], [])) if row["priority"] == 2 and row["read_status"] == "ok" else ""
    for category in (REVERSE, DIRECT):
        folder = args.output / category
        folder.mkdir()
        emit_csv(folder / "files.csv", [r for r in all_rows if r["category"] == category])
        emit_csv(folder / "primary-files.csv", [r for r in all_rows if r["category"] == category and r["priority"] == 1])
        emit_csv(folder / "backup-files.csv", [r for r in all_rows if r["category"] == category and r["priority"] == 2])
        emit_csv(folder / "surrounding-media.csv", [r for r in all_rows if r["category"] == category and r["priority"] == 3])

    stats = collections.defaultdict(lambda: [0, 0, 0])
    for row in all_rows:
        cell = stats[row["category"], row["extension"], row["source"]]
        cell[0] += 1
        cell[1] += row["size_bytes"] if isinstance(row["size_bytes"], int) else 0
        cell[2] += bool(row["review"])
    stat_rows = [dict(category=k[0], extension=k[1], source=k[2], files=v[0], bytes=v[1], review=v[2]) for k, v in sorted(stats.items())]
    emit_csv(args.output / "extension-statistics.csv", stat_rows, ["category", "extension", "source", "files", "bytes", "review"])
    seen = collections.Counter(r["msi_file_id"] for r in payload)
    missing = sorted(set(by_id) - {r["msi_file_id"].casefold() for r in payload})
    bad_payload = [r["msi_file_id"] for r in payload if r["read_status"] != "ok" or r["msi_size_match"] != "True"]
    summary = dict(started_utc=started, finished_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                   physical_files=len(physical), payload_files=len(payload), embedded_members=len(embedded), msi_streams=len(msi_streams),
                   physical_bytes=sum(r["size_bytes"] for r in physical if isinstance(r["size_bytes"], int)),
                   categories=dict(collections.Counter(r["category"] for r in all_rows)),
                   priorities={str(priority): dict(collections.Counter(r["category"] for r in all_rows if r["priority"] == priority)) for priority in (1,2,3)},
                   sources={source: dict(collections.Counter(r["category"] for r in all_rows if r["source"] == source)) for source in sorted({r["source"] for r in all_rows})},
                   msi_files=len(by_id), cabinets=len(cabinets), cabinets_ok=sum(r["status"] == "ok" for r in cabinet_results),
                   msi_missing_file_ids=missing, msi_repeated_file_ids=[k for k,v in seen.items() if v != 1],
                   msi_unmapped_members=sum(not r["msi_file_id"] for r in payload), msi_bad_payload=bad_payload,
                   read_errors=[dict(path=r["original_path"], status=r["read_status"]) for r in physical if r["read_status"] != "ok"],
                   encrypted_zip_members=sum(r["read_status"] == "encrypted-member-not-read" for r in embedded),
                   errors=errors, review_candidates=sum(bool(r["review"]) for r in all_rows),
                   backup_physical_sha_matches=sum(bool(r["primary_sha_matches"]) for r in physical),
                   backup_physical_needs_reverse_sha_matches=sum(bool(r["primary_sha_matches"]) for r in physical if r["category"] == REVERSE),
                   unique_verified_hashes=len({r["sha256"] for r in all_rows if r["read_status"] == "ok"}),
                   limitations=[f"安装介质周边其他产品的 ISO/MSI/CAB 只盘点容器文件，不列其内部文件；{args.product_label} 产品全部 CAB 已逐成员读取。",
                                "ZIP 容器枚举一层；更深的嵌套容器须后续按具体来源处理。",
                                "数据库/未知数据格式可能需要格式研究；不因此算作已恢复业务代码。",
                                "资源 PE 判据为 IL-only 且 MethodDef=0，或原生无可执行区段；未完整验证语义。",
                                "逆向类包含未知二进制待核实候选，不表示已证明每个候选都含代码。",
                                "MSI 版本字符串可为伴随文件引用，不等于每个载荷都具有 PE 版本资源。"])
    emit_json(args.output / "summary.json", summary)
    emit_json(args.output / "errors.json", errors)
    lines = ["# Aspen 安装程序优先：全文件扫描清单", "", f"选择：{args.product_label} 产品安装包为主来源；已安装文件仅作备选补充。", "",
             "本轮只盘点、读取文件头和哈希；未安装、未运行、未反编译输入，也未开始 Windows/Mac 编译。", "",
             f"- 主安装器：`{args.installer}`", f"- MSI File 表：{len(by_id):,}；CAB：{len(cabinets):,}；实际载荷：{len(payload):,}。",
             f"- MSI 内嵌 Binary/Icon 流：{len(msi_streams):,}；单独列入两类清单。",
             f"- 全介质与备选目录物理文件：{len(physical):,}；ZIP 内层条目：{len(embedded):,}。",
             "- 物理容器、安装载荷和内层条目分别计数，合计行数不是独立文件内容数。",
             "- 两大类分别见 `01-needs-reverse/files.csv`、`02-no-reverse/files.csv`；均按末级后缀小写字母序排列，同后缀按来源优先级、路径排序，无后缀单列。",
             "- 每类另有 `primary-files.csv`（首选安装器）、`backup-files.csv`（已安装备选）和 `surrounding-media.csv`（其他介质），后续先读首选清单。",
             "- 两类与开发完成/未完成目录无关；尚未反编译的项目没有完成声明。", "",
             "## 按来源统计", "", "| 来源 | 需要逆向（含待核实） | 不需要逆向 |", "| --- | ---: | ---: |"]
    for source, counts in summary["sources"].items():
        lines.append(f"| {source} | {counts.get(REVERSE,0):,} | {counts.get(DIRECT,0):,} |")
    lines += ["", "## 每类按后缀排序", "", "| 大类 | 后缀 | 文件/条目 | 待核实 |", "| --- | --- | ---: | ---: |"]
    grouped = collections.defaultdict(lambda: [0,0])
    for row in stat_rows:
        grouped[row["category"],row["extension"]][0] += row["files"]
        grouped[row["category"],row["extension"]][1] += row["review"]
    for (category, extension), (count, review) in sorted(grouped.items()):
        lines.append(f"| {category} | `{extension}` | {count:,} | {review:,} |")
    lines += ["", "## 验证与边界", "", f"- File 表未匹配：{len(missing)}；载荷大小/来源不一致：{len(bad_payload)}；读取异常：{len(summary['read_errors'])}；其他异常：{len(errors)}。",
              f"- 备选物理文件与主载荷 SHA-256 相同：{summary['backup_physical_sha_matches']:,}；同哈希共用 analysis_key，保留所有来源。",
              f"- ZIP 加密内层条目：{summary['encrypted_zip_members']:,}；已列目录和大小，未读取内容或生成哈希。",
              "- 分类是处理路线：图标/资源直接提取，源码/脚本直接阅读，数据库按原格式解析，程序与未知二进制进入逆向候选。容器本身不逆向不等于内部不含程序。"]
    lines += ["- " + limitation for limitation in summary["limitations"]]
    (args.output / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(json.dumps({key:summary[key] for key in ("physical_files","payload_files","embedded_members","categories","cabinets_ok","msi_files","review_candidates")},ensure_ascii=False), flush=True)


if __name__ == "__main__":
    main()
