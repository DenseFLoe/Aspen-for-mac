"""Check a BIFF8 project's editable CFB directory, OVBA metadata, host bindings and raw resources."""
import hashlib
import io
import json
from pathlib import Path
import re
import struct

if __package__:
    from . import biff_workbook, office_forms
else:
    import biff_workbook
    import office_forms

SCOPE = "BIFF8 project metadata, Document bindings, storage classes/state and mapped raw resources"
ROOT = ("_VBA_PROJECT_CUR",)
VBA = ROOT + ("VBA",)
DIR = VBA + ("dir",)
PROJECT = ROOT + ("PROJECT",)


class Unsupported(ValueError):
    pass


class Mismatch(ValueError):
    pass


def need(condition, reason):
    if not condition:
        raise Unsupported(reason)


def match(condition, reason):
    if not condition:
        raise Mismatch(reason)


def record(data, pos):
    tag, size = struct.unpack_from("<HI", data, pos)
    end = pos + 6 + size
    need(end <= len(data), "ovba_record_range")
    return tag, data[pos+6:end], end


def offset_fields(data, start, modules, codec):
    """Parse the PROJECTMODULES suffix from the reference parser's record boundary."""
    tag, count, pos = record(data, start)
    need(tag == 15 and count == struct.pack("<H", len(modules)), "ovba_module_count")
    tag, cookie, pos = record(data, pos)
    need(tag == 0x13 and len(cookie) == 2, "ovba_project_cookie")
    fields = {}
    for module in modules:
        tag, name, pos = record(data, pos)
        need(tag == 0x19 and name.decode(codec) == module.name, "ovba_module_name_record")
        seen = set()
        while True:
            tag, value, pos = record(data, pos)
            need(tag in {0x47,0x1a,0x32,0x1c,0x48,0x31,0x1e,0x2c,0x21,0x22,0x25,0x28,0x2b}
                 and tag not in seen, "unsupported_ovba_module_record")
            seen.add(tag)
            if tag == 0x31:
                need(value == struct.pack("<I", module.textoffset), "ovba_source_offset")
                fields[module.name] = pos-4
            if tag == 0x2b:
                need(not value and module.name in fields, "ovba_module_terminator")
                break
    need(data[pos:] == struct.pack("<HI", 0x10, 0), "ovba_project_terminator")
    return fields


def declarations(raw, codec):
    roles = {}
    for line in raw.decode(codec).split("\r\n"):
        if line.startswith("["):
            break
        role, _, declaration = line.partition("=")
        if role in {"Document","Module","Class","BaseClass"}:
            name = declaration
            if role == "Document":
                parts = re.fullmatch(r"([^/]+)/&H[0-9A-Fa-f]{8}", declaration)
                need(parts, "unsupported_document_declaration")
                name = parts[1]
            need(name and name not in roles, "ambiguous_project_declaration")
            roles[name] = role
    return roles


def name_map(raw, codec):
    pos, names = 0, set()
    while pos < len(raw) - 2:
        end = raw.index(0, pos)
        name = raw[pos:end].decode(codec)
        pos = end + 1
        end = pos
        while end+2 <= len(raw) and raw[end:end+2] != bytes(2):
            end += 2
        need(end+2 <= len(raw) and raw[pos:end].decode("utf-16le") == name and name not in names,
             "unsupported_projectwm_mapping")
        names.add(name)
        pos = end+2
    need(raw[pos:] == bytes(2), "projectwm_terminator")
    return names


def host_names(records):
    """Map VBA CodeName to workbook or BoundSheet8 target, excluding nested charts."""
    pos, current, sheet_start = 0, None, None
    targets, names = {}, {}
    for tag, raw in records:
        if tag == 0x0809:
            need(current is None and raw[:2] == b"\0\x06", "unsupported_nested_biff_host")
            current, = struct.unpack_from("<H", raw, 2)
            need(current in (5,16), "unsupported_biff_host_kind")
            sheet_start = pos
        elif tag == 0x0085:
            need(current == 5 and len(raw)>=8 and raw[5] == 0, "unsupported_boundsheet_host")
            address, = struct.unpack_from("<I",raw)
            need(address not in targets, "duplicate_boundsheet_host")
            targets[address] = raw[6:]  # actual sheet name including its string flags
        elif tag == 0x01ba:
            need(current in (5,16) and len(raw)>=3 and raw[2] in (0,1), "unsupported_codename_record")
            length, wide = struct.unpack_from("<HB",raw)
            need(0 < length <= 31 and len(raw)==3+length*(1+wide), "unsupported_codename_length")
            name = raw[3:].decode("utf-16le" if wide else "latin-1")
            identity = ("Workbook",) if current == 5 else ("Worksheet",targets[sheet_start])
            need(name not in names and identity not in names.values(), "ambiguous_biff_codename")
            names[name] = identity
        elif tag == 10:
            current = None
        pos += 4+len(raw)
    need(current is None and len(names)==1+len(targets) and ("Workbook",) in names.values(),
         "incomplete_biff_codename_bindings")
    return names


def compare(ole, original, root, metrics):
    from oletools.olevba import VBA_Project

    doc = office_forms.manifest(root)
    match(doc["original_sha256"] == hashlib.sha256(original).hexdigest(), "project_original_identity")
    paths = {tuple(p) for p in ole.listdir()}
    need(DIR in paths and PROJECT in paths, "unsupported_project_root")
    workbooks = [p for p in paths if len(p)==1 and p[0].casefold() in {"workbook","book"}]
    need(len(workbooks)==1, "ambiguous_workbook_stream")
    workbook = workbooks[0]
    classes = {tuple(p):ole.direntries[ole._find(p)] for p in ole.listdir(streams=False,storages=True)}
    classes[()] = ole.root
    storages = {tuple(row["path"]):row for row in doc["storages"]}
    match(len(storages)==len(doc["storages"]) and set(storages)==set(classes), "storage_inventory_differs")
    for path, entry in classes.items():
        row = storages[path]
        need(not (row.keys()-{"path","clsid","state"}), "unsupported_storage_metadata")
        match(row["clsid"] == entry.clsid, "storage_class_differs")
        # This package profile has no writer for nonzero application state.
        need(entry.dwUserFlags == 0, "nonzero_storage_state_requires_representation")
        match(type(row.get("state",0)) is int and row.get("state",0)==0, "storage_state_differs")
    metrics["storages_including_root"] = len(classes)
    base = "/".join(ROOT)+"/"
    project = VBA_Project(ole,base,"/".join(PROJECT),"/".join(DIR),relaxed=False)
    original_dir = project.dir_stream.getvalue()
    start = project.dir_stream.tell()-2
    project.parse_project_stream()
    for _ in project.parse_modules():
        pass
    fields = offset_fields(original_dir,start,project.modules,project.codec)
    normalized = bytearray(original_dir)
    for field in fields.values():
        normalized[field:field+4] = bytes(4)
    need((root/"project/dir.records").is_file(), "missing_project_dir_records")
    match(bytes(normalized)==office_forms.read_member(root,"project/dir.records"), "project_dir_records_differ")
    metrics["parsed_module_offset_fields"] = len(fields)
    metrics["exact_project_info_and_reference_bytes"] = start
    raw_project = ole.openstream(PROJECT).read()
    roles = declarations(raw_project,project.codec)
    need(set(roles)==set(fields) and len(fields)==len(project.modules), "project_dir_declarations_disagree")
    wm = ROOT+("PROJECTwm",)
    if wm in paths:
        need(name_map(ole.openstream(wm).read(),project.codec)==set(fields), "projectwm_module_set")
    modules = {r["name"]:r for r in doc["modules"]}
    match(len(modules)==len(doc["modules"]) and set(modules)==set(roles), "manifest_module_set_differs")
    code_paths, forms = set(), set()
    source_dirs = [p for p in root.iterdir() if p.is_dir() and p.name.casefold() in {"vba","vba-src"}]
    need(len(source_dirs)==1, "module_source_directory_ambiguous")
    source_dir = source_dirs[0]
    source_files = [p for p in source_dir.iterdir() if p.is_file()]
    sources = {p.name.casefold(): p for p in source_files}
    need(len(sources) == len(source_files), "duplicate_casefolded_source_files")
    for module in project.modules:
        name, role = module.name, roles[module.name]
        path = tuple(module.code_path.split("/"))
        need(Path(module.filename).name == module.filename and not re.search(r'[:/\\]', module.filename),
             "unsupported_original_module_filename")
        need(path == VBA+(module.streamname,) and path not in code_paths and path in paths, "ambiguous_module_path")
        need(module.type == (0x21 if role=="Module" else 0x22), "project_dir_module_role")
        attribute = ('Attribute VB_Name = "'+name+'"').encode(project.codec)
        need(module.code_raw.split(b"\r\n",1)[0]==attribute, "source_module_identity_unverified")
        row = modules[name]
        candidate = sources.get(module.filename.casefold())
        match(row["role"]==role and row["stream"]==list(path)
              and candidate is not None and not candidate.is_symlink()
              and candidate.resolve().parent == source_dir.resolve()
              and row["file"] == candidate.relative_to(root).as_posix()
              and type(row["dir_offset_field"]) is int and row["dir_offset_field"]==fields[name]
              and type(row["original_text_offset"]) is int and row["original_text_offset"]==module.textoffset,
              "manifest_module_binding_differs")
        code_paths.add(path)
        if role == "BaseClass":
            need(ROOT+(name,) in classes, "original_form_storage_missing")
            forms.add(ROOT+(name,))
    orig_hosts = host_names((t,v) for _,t,v in biff_workbook._original_records(ole.openstream(workbook).read()))
    need(set(orig_hosts)=={n for n,r in roles.items() if r=="Document"}, "original_document_host_unverified")
    need((root/"workbook.json").is_file(), "missing_workbook_record_listing")
    listed = json.loads(office_forms.read_member(root,"workbook.json"),object_pairs_hook=biff_workbook._unique)
    match(host_names(biff_workbook._claimed_records(listed))==orig_hosts, "editable_document_hosts_differ")
    metrics["document_hosts"] = len(orig_hosts)
    header_path = VBA+("_VBA_PROJECT",)
    header = ole.openstream(header_path).read(7)
    need(len(header)==7 and header[:2]==bytes.fromhex("cc61") and header[4]==0, "unknown_original_vba_header")
    srp = {p for p in paths-code_paths if p[:-1]==VBA and re.fullmatch(r"__SRP_[a-fA-F0-9]{1,25}",p[-1])}
    form_data = {p for p in paths if p[:len(ROOT)+1] in forms and p[len(ROOT)+1:]!=("\x01CompObj",)}
    routed = code_paths|form_data|srp|{DIR,header_path,workbook}
    expected = paths-routed
    resources = {tuple(r["path"]):r["file"] for r in doc["resources"]}
    match(len(resources)==len(doc["resources"]) and set(resources)==expected, "project_resource_inventory_differs")
    filenames = [name.casefold() for name in resources.values()]
    match(len(filenames)==len(set(filenames)) and "project/dir.records" not in filenames, "aliased_project_resource")
    for path, filename in resources.items():
        match(filename.startswith("project/"), "project_resource_outside_directory")
        data = office_forms.read_member(root,filename)
        if path == PROJECT and data != raw_project:
            match(declarations(data,project.codec)==roles, "project_document_or_module_binding_differs")
        match(data==ole.openstream(path).read(), "project_declaration_bytes_differ" if path==PROJECT
              else "project_resource_bytes_differ")
    mapped = set(resources.values()) | {"project/dir.records"}
    present = {p.relative_to(root).as_posix() for p in (root/"project").rglob("*") if p.is_file()}
    match(mapped == present, "project_resource_file_inventory_differs")
    metrics.update(original_streams=len(paths),raw_resources_exact=len(expected),form_streams_routed=len(form_data),
                   original_cache_version=struct.unpack_from("<H",header,2)[0],original_srp_streams=len(srp),
                   original_cache_prefix_bytes=sum(m.textoffset for m in project.modules),declared_modules=len(modules))


def check(original, delivery):
    metrics = {}
    status, code = "pass", None
    try:
        import olefile
        need(len(original)<=biff_workbook.MAX_INPUT, "compound_size_limit")
        with olefile.OleFileIO(io.BytesIO(original),raise_defects=olefile.DEFECT_INCORRECT) as ole:
            compare(ole,original,Path(delivery).resolve(strict=True),metrics)
    except Mismatch as issue:
        status, code = "fail", str(issue)
    except Unsupported as issue:
        status, code = "inconclusive", str(issue)
    except (ImportError,ValueError,AttributeError,KeyError,TypeError,IndexError,OSError,RuntimeError,struct.error):
        status, code = "inconclusive", "project_representation_unavailable"
    return {"scope":SCOPE, "status":status, "metrics":metrics, "findings":[{"code":code}] if code else []}
