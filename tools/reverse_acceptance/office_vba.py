"""Compare existing exported VBA module files to the source streams of an Excel host."""
import codecs
import hashlib
import io
import posixpath
import zipfile
from collections import Counter
from pathlib import Path
from xml.etree import ElementTree


SCOPE = ("Excel host's one declared VBA project: bidirectional comparison of .bas/.cls/.frm "
         "source text, including Attribute records and blank lines. Does not check p-code, "
         "XLM, workbook formulas, references, UserForm design, ActiveX, host behaviour or embedded objects.")
EXT = {".bas", ".cls", ".frm", ".vba"}
DIRECTORIES = {"vba", "vba-src"}
CFB = bytes.fromhex("d0cf11e0a1b11ae1")


class Unverified(ValueError):
    """A finite diagnostic code only; third-party exception text can include input text."""


def _compound(data):
    if data.startswith(CFB):
        return data, "BIFF", None
    if not data.startswith(b"PK"):
        raise Unverified("unsupported_excel_container")
    with zipfile.ZipFile(io.BytesIO(data)) as z:
        names=z.namelist()
        if len(names)!=len({n.casefold() for n in names}):
            raise Unverified("duplicate_opc_part_name")
        if not {"_rels/.rels", "xl/workbook.xml", "xl/_rels/workbook.xml.rels"}.issubset(names):
            raise Unverified("no_supported_excel_workbook_part")
        ns="{http://schemas.openxmlformats.org/package/2006/relationships}"
        def relationships(name):
            xml=z.read(name)
            if b"<!DOCTYPE" in xml.upper():
                raise Unverified("unsupported_relationship_xml")
            return ElementTree.fromstring(xml).findall(ns+"Relationship")
        root_type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"
        hosts=[r for r in relationships("_rels/.rels") if r.get("Type")==root_type]
        if (len(hosts)!=1 or hosts[0].get("TargetMode","Internal")!="Internal" or
                posixpath.normpath(hosts[0].get("Target","").lstrip("/"))!="xl/workbook.xml"):
            raise Unverified("primary_workbook_not_bound")
        reltype="http://schemas.microsoft.com/office/2006/relationships/vbaProject"
        choices=[r for r in relationships("xl/_rels/workbook.xml.rels") if r.get("Type")==reltype]
        if len(choices)!=1 or choices[0].get("TargetMode","Internal")!="Internal":
            raise Unverified("single_embedded_vba_project_not_verified")
        target=choices[0].get("Target","")
        path=posixpath.normpath(target.lstrip("/") if target.startswith("/") else posixpath.join("xl",target))
        if path not in names or not path.startswith("xl/"):
            raise Unverified("vba_relationship_target_unavailable")
        return z.read(path), "OOXML", sum(n.startswith("xl/macrosheets/") and n.endswith(".xml") for n in names)


def _original(data):
    compound, host, xlm = _compound(data)
    import olefile
    from oletools.olevba import VBA_Project

    with olefile.OleFileIO(io.BytesIO(compound), raise_defects=olefile.DEFECT_INCORRECT) as ole:
        paths=ole.listdir()
        if host=="BIFF" and not any(len(p)==1 and p[0].casefold() in ("book","workbook") for p in paths):
            raise Unverified("biff_workbook_stream_unverified")
        dirs=[p for p in paths if [s.casefold() for s in p[-2:]]==["vba","dir"]]
        if len(dirs)!=1:
            raise Unverified("single_declared_vba_project_unverified")
        directory=dirs[0]; parts=directory[:-2]
        base="/".join(parts)+"/" if parts else ""
        if host=="BIFF" and [p.casefold() for p in parts] != ["_vba_project_cur"]:
            raise Unverified("linked_biff_project_unverified")
        if host=="OOXML" and parts:
            raise Unverified("unexpected_embedded_project_root")
        project=VBA_Project(ole,base,base+"PROJECT","/".join(directory),relaxed=False)
        project.parse_project_stream()
        for _ in project.parse_modules():
            pass
        if not project.modules_count or project.modules_count!=len(project.modules):
            raise Unverified("incomplete_original_module_table")

        modules={}
        streams=set()
        for m in project.modules:
            if not m.filename or not m.name or m.code_raw is None:
                raise Unverified("unreadable_declared_module")
            if m.name.casefold() not in {name.casefold() for name in project.module_ext}:
                raise Unverified("module_host_binding_unverified")
            if Path(m.filename).name!=m.filename or Path(m.filename).suffix.lower() not in EXT:
                raise Unverified("unsupported_module_filename")
            key=m.filename.casefold()
            stream=m.code_path.casefold()
            if key in modules or stream in streams:
                raise Unverified("ambiguous_original_module_or_stream")
            m.code_raw.decode(project.codec,errors="strict")
            modules[key]=bytes(m.code_raw)
            streams.add(stream)
        if {m.name.casefold() for m in project.modules}!={n.casefold() for n in project.module_ext}:
            raise Unverified("project_and_dir_module_sets_differ")
        for p in paths:
            if [v.casefold() for v in p[:-1]] != [v.casefold() for v in directory[:-1]]:
                continue
            leaf=p[-1].casefold()
            if "/".join(p).casefold() not in streams and leaf not in {"dir","_vba_project"} and not leaf.startswith("__srp_"):
                raise Unverified("unaccounted_vba_storage_stream")
        return modules, project.codec, host, xlm


def _relation(raw, delivered, codec):
    if raw==delivered:
        return "exact_bytes"
    original=raw.decode(codec,errors="strict").replace("\r\n","\n")
    if delivered.startswith(codecs.BOM_UTF8):
        try:
            if delivered.decode("utf-8-sig",errors="strict").replace("\r\n","\n")==original:
                return "explicit_utf8_text"
        except UnicodeError:
            pass
    # Preserve bare CR, blank lines, and final newline. The original code page
    # is known. BOM-less guesses cannot resolve a genuine non-ASCII ambiguity.
    try:
        if delivered.decode(codec,errors="strict").replace("\r\n","\n")==original:
            return "project_codepage_text"
    except UnicodeError:
        pass
    try:
        if delivered.decode("utf8",errors="strict").replace("\r\n","\n")==original:
            return "unverified_encoding"
    except UnicodeError:
        pass
    return "different"


def check(original: bytes, delivery: Path) -> dict:
    result={"scope":SCOPE,"status":"pass","metrics":{},"findings":[]}
    metrics=result["metrics"]
    def finding(status, code, module=None):
        row={"status":status,"code":code}
        if module is not None:
            row["module_name_sha256"]=hashlib.sha256(module.encode("utf8")).hexdigest()
        result["findings"].append(row)
        if status=="fail" or result["status"]=="pass":
            result["status"]=status

    try:
        modules,codec,host,xlm=_original(original)
    except Unverified as exc:
        finding("inconclusive",exc.args[0])
        return result
    except Exception as exc:
        # The raw exception from a workbook parser may include protected text.
        finding("inconclusive","vba_reader_"+type(exc).__name__)
        return result
    metrics.update(host=host,project_codepage=codec,declared_modules=len(modules),
                   original_module_bytes=sum(map(len,modules.values())),host_xlm_parts=xlm)
    try:
        root=Path(delivery).resolve()
        candidates=[p for p in root.iterdir() if p.is_dir() and p.name.casefold() in DIRECTORIES]
        if len(candidates)!=1:
            finding("inconclusive","editable_vba_directory_missing_or_ambiguous")
            return result
        directory=candidates[0]
        if directory.resolve().parent!=root or directory.is_symlink() or getattr(directory,"is_junction",lambda:False)():
            finding("fail","editable_source_outside_delivery")
            return result
        files={}
        # These published layouts have one flat directory of editable modules.
        # A nested directory makes its module namespace ambiguous.
        for path in directory.iterdir():
            if path.is_dir():
                finding("inconclusive","nested_vba_delivery_requires_mapping")
                continue
            if path.suffix.casefold() not in EXT:
                continue
            key=path.name.casefold()
            if not path.is_file() or path.resolve().parent!=directory.resolve() or path.is_symlink():
                finding("fail","editable_source_outside_delivery",key)
            elif key in files:
                finding("fail","duplicate_delivered_module",key)
            else:
                files[key]=path
        metrics["delivered_modules"]=len(files)
        for key in sorted(modules.keys()-files.keys()):
            finding("fail","missing_editable_module",key)
        for key in sorted(files.keys()-modules.keys()):
            finding("fail","extra_editable_module",key)
        counts=Counter()
        for key in sorted(modules.keys() & files.keys()):
            relation=_relation(modules[key],files[key].read_bytes(),codec)
            counts[relation]+=1
            if relation=="different":
                finding("fail","editable_module_text_differs",key)
            elif relation=="unverified_encoding":
                finding("inconclusive","editable_encoding_unverified",key)
        metrics["comparisons"]=dict(sorted(counts.items()))
    except (OSError,UnicodeError) as exc:
        finding("inconclusive","vba_delivery_"+type(exc).__name__)
    return result

