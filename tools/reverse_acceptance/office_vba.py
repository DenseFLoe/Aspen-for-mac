"""Compare existing exported VBA module files to the source streams of an Excel host."""
import codecs
import hashlib
import io
import posixpath
import zipfile
from collections import Counter
from pathlib import Path
from xml.etree import ElementTree
import struct

if __package__:
    from . import office_forms
else:
    import office_forms


SCOPE = ("Declared Excel VBA module source and, for manifest-backed exported UserForms, "
         "designer frame, resource extent and logical stream/class tree; excludes workbook, p-code and runtime.")
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


def _original(data, forms=None):
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
            if forms is not None and key.endswith(".frm"):
                # PROJECT binds BaseClass to this module; dir independently binds its source stream.
                declarations = ole.openstream(base+"PROJECT").read().decode(project.codec).splitlines()
                form_decl = "BaseClass=" + m.name
                prefix = (*parts, m.name)
                if declarations.count(form_decl) == 1 and ole.exists(list(prefix)):
                    try:
                        form_tree = office_forms.tree(ole, prefix)
                        forms[key] = (m.name, tuple(m.code_path.split("/")), m.textoffset, prefix, *form_tree)
                    except (office_forms.FormIssue, OSError, ValueError):
                        pass
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

    forms = {}
    try:
        modules,codec,host,xlm=_original(original, forms)
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
        resources=set()
        # These published layouts have one flat directory of editable modules.
        # A nested directory makes its module namespace ambiguous.
        for path in directory.iterdir():
            if path.is_dir():
                finding("inconclusive","nested_vba_delivery_requires_mapping")
                continue
            if path.suffix.casefold() == ".frx":
                if path.name.casefold() in resources:
                    finding("fail", "duplicate_form_resource")
                resources.add(path.name.casefold())
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
        declared_forms = {key for key in modules if key.endswith(".frm")}
        declared_resources = {Path(key).with_suffix(".frx").name for key in declared_forms}
        for key in sorted(resources - declared_resources):
            finding("fail", "orphan_form_resource", key)
        document = None
        export_manifest = False
        if declared_forms and (root / "project.json").exists():
            try:
                document = office_forms.manifest(root)
                manifested = [row["file"].casefold() for row in document.get("modules", [])
                              if "form" in row or row.get("role") == "BaseClass"]
                export_manifest = bool(manifested or resources)
                if export_manifest:
                    office_forms.require(document["original_sha256"] == hashlib.sha256(original).hexdigest(),
                                         "form_manifest_original_differs")
                    expected = {f"{directory.name}/{key}".casefold() for key in declared_forms}
                    office_forms.require(len(manifested) == len(expected) and set(manifested) == expected,
                                         "form_manifest_module_set_differs")
                else:
                    document = None
            except office_forms.FormIssue as exc:
                finding(exc.status, exc.args[0])
                document = None
            except (OSError, TypeError, ValueError, KeyError, AttributeError, RecursionError):
                finding("inconclusive", "unreadable_form_manifest")
                document = None
        for key in sorted(modules.keys() & files.keys()):
            path=files[key]
            if key in declared_forms and path.stat().st_size > office_forms.LIMIT:
                finding("inconclusive", "form_member_size_limit", key)
                continue
            data = path.read_bytes()
            if key in declared_forms and (export_manifest or data.startswith(b"VERSION ")
                                          or path.with_suffix(".frx").name.casefold() in resources):
                if document is None or key not in forms:
                    finding("inconclusive", "form_binding_unavailable", key)
                    continue
                try:
                    office_forms.check_form(root, directory.name, path.name, data, modules[key], codec,
                                            forms[key], document)
                    counts["verified_form_export"] += 1
                except office_forms.FormIssue as exc:
                    finding(exc.status, exc.args[0], key)
                except (OSError, TypeError, ValueError, KeyError, IndexError, AttributeError, struct.error):
                    finding("inconclusive", "unsupported_form_representation", key)
                continue
            relation=_relation(modules[key],data,codec)
            counts[relation]+=1
            if relation=="different":
                finding("fail","editable_module_text_differs",key)
            elif relation=="unverified_encoding":
                finding("inconclusive","editable_encoding_unverified",key)
        metrics["comparisons"]=dict(sorted(counts.items()))
    except (OSError,UnicodeError) as exc:
        finding("inconclusive","vba_delivery_"+type(exc).__name__)
    return result

