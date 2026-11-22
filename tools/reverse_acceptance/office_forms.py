"""Verify an editable MSForms UserForm export against its owning VBA project storage."""
import hashlib
import io
import json
from pathlib import Path
import re
import stat
import struct
import uuid

FORM_CLASS = "C62A69F0-16DC-11CE-9E98-00AA00574A4F"
FRAME = ("\x03VBFrame",)
COMP = ("\x01CompObj",)
LIMIT = 16 << 20


class FormIssue(ValueError):
    def __init__(self, code, status="inconclusive"):
        super().__init__(code)
        self.status = status


def require(ok, code):
    if not ok:
        raise FormIssue(code, "fail")


def read_member(root, relative, limit=LIMIT):
    parts = relative.split("/")
    path = root
    for part in parts:
        if (not part or part in (".", "..") or part.endswith((" ", ".")) or Path(part).is_reserved()
                or any(ord(c) < 32 or c in '<>:"/\\|?*' for c in part)):
            raise FormIssue("unsupported_form_delivery_path")
        path = path / part
        if path.is_symlink() or getattr(path.lstat(), "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT:
            raise FormIssue("linked_form_delivery_path")
    if not path.is_file() or not path.resolve().is_relative_to(root):
        raise FormIssue("unsupported_form_delivery_path")
    with path.open("rb") as stream:
        data = stream.read(limit + 1)
    if len(data) > limit:
        raise FormIssue("form_member_size_limit")
    return data


def manifest(root):
    def unique(pairs):
        result = {}
        for key, value in pairs:
            if key in result:
                raise FormIssue("ambiguous_form_manifest")
            result[key] = value
        return result
    return json.loads(read_member(root, "project.json", 2 << 20).decode("utf-8-sig"), object_pairs_hook=unique)


def tree(ole, prefix):
    """Compare logical stream content and every storage CLSID, including empty children."""
    prefix = tuple(prefix)
    paths = [tuple(p) for p in ole.listdir(streams=True, storages=True)]
    classes = {(): ole.direntries[ole._find(prefix)].clsid if prefix else ole.root.clsid}
    streams = {}
    total = 0
    for path in paths:
        if path[:len(prefix)] != prefix or path == prefix:
            continue
        suffix = path[len(prefix):]
        entry = ole.direntries[ole._find(path)]
        if entry.entry_type == 1:
            classes[suffix] = entry.clsid
        else:
            total += entry.size
            if total > LIMIT:
                raise FormIssue("form_resource_size_limit")
            data = ole.openstream(path).read()
            if len(data) != entry.size:
                raise FormIssue("form_resource_truncated")
            streams[suffix] = data if suffix in (FRAME, COMP) else hashlib.sha256(data).digest()
    return classes, streams


def _declared_paths(rows, prefix):
    result = {}
    for row in rows:
        path = tuple(row["path"])
        if tuple(s.casefold() for s in path[:len(prefix)]) != tuple(s.casefold() for s in prefix):
            continue
        require(path[:len(prefix)] == prefix and path[len(prefix):] not in result, "form_manifest_duplicate_path")
        result[path[len(prefix):]] = row
    return result


def _exported_compobj(native):
    # For an unregistered design storage the external Forms.Form.1 presentation fills
    # the class GUID and ANSI ProgID. All other native CompObj fields must be preserved.
    if len(native) < 44 or native[12:28] != bytes(16):
        raise FormIssue("unsupported_native_form_compobj")
    offset = 28
    for _ in range(2):
        size, = struct.unpack_from("<I", native, offset)
        offset += 4 + size
    if native[offset:offset + 4] != bytes(4):
        raise FormIssue("unsupported_native_form_progid")
    progid = b"Forms.Form.1\0"
    return (native[:12] + uuid.UUID(FORM_CLASS).bytes_le + native[28:offset]
            + struct.pack("<I", len(progid)) + progid + native[offset + 4:])


def _frame(raw, source, name, spec, codec):
    # Preserve all lines in both the native frame and source, except for the named
    # export transformations. No generic stripping of designer or Attribute records.
    lines = source.split(b"\r\n")
    try:
        stop = lines.index(b"End")
    except ValueError:
        raise FormIssue("unsupported_form_envelope")
    frame, code = lines[:stop], lines[stop+1:]
    ident = name.encode(codec)
    require(len(frame) >= 2 and frame[0] == b"VERSION 5.00" and
            frame[1].rstrip() == b"Begin {" + FORM_CLASS.encode() + b"} " + ident,
            "form_designer_identity_differs")
    marker = re.compile(rb'\s*OleObjectBlob\s*=\s*"' + re.escape(ident) + rb'\.frx":0000\s*')
    links = [i for i, line in enumerate(frame) if marker.fullmatch(line)]
    require(len(links) == 1, "form_resource_link_differs")
    del frame[links[0]]
    type_info = spec["type_info_line"].encode(codec)
    require(re.fullmatch(rb"[ \t]*TypeInfoVer[ \t]*=[ \t]*[0-9]+", type_info), "form_type_info_invalid")
    require(b"\r\n".join([*frame, type_info, b"End", b""]) == raw, "form_designer_fields_differ")
    require(code and code[0] == b'Attribute VB_Name = "' + ident + b'"', "form_source_identity_differs")
    previous = 0
    for attr in spec["native_attributes"]:
        index = attr["index"]
        line = attr["line"].encode(codec)
        require(type(index) is int and previous < index <= len(code) and
                re.fullmatch(rb"Attribute VB_(?:Base|TemplateDerived|Customizable) = [^\r\n]+", line)
                and all(v.startswith(b"Attribute VB_") for v in code[:index]), "invalid_native_form_attribute")
        code.insert(index, line)
        previous = index
    geometry = {}
    for line in frame:
        field = re.fullmatch(rb"[ \t]*Client(Height|Width|Left|Top)[ \t]*=[ \t]*([0-9]{1,8})[ \t]*", line)
        if field:
            geometry[field[1]] = int(field[2])
    if set(geometry) != {b"Width", b"Height", b"Left", b"Top"}:
        raise FormIssue("unsupported_form_frame_geometry")
    # This profile covers equal side and bottom borders, measured in twips.
    extent = (geometry[b"Width"] + 2 * geometry[b"Left"],
              geometry[b"Height"] + geometry[b"Top"] + geometry[b"Left"])
    return b"\r\n".join(code), extent


def check_form(root, folder, filename, source, original, codec, info, document):
    import olefile
    name, code_path, offset, prefix, original_classes, original_streams = info
    rows = [r for r in document["modules"] if r["name"].casefold() == name.casefold()
            or r["file"].casefold() == f"{folder}/{filename}".casefold()
            or r["stream"] == list(code_path)]
    require(len(rows) == 1, "ambiguous_form_manifest_binding")
    row = rows[0]
    require(row["name"] == name and row["role"] == "BaseClass" and row["stream"] == list(code_path)
            and row["file"] == f"{folder}/{filename}" and row["original_text_offset"] == offset,
            "form_manifest_binding_differs")
    spec = row["form"]
    require(spec["file"] == f"{folder}/{name}.frx", "form_manifest_resource_differs")
    classes = _declared_paths(document["storages"], prefix)
    require({p:r["clsid"] for p,r in classes.items()} == original_classes, "form_storage_manifest_differs")
    resources = _declared_paths(document["resources"], prefix)
    require(set(resources) == {COMP}, "form_resource_manifest_differs")
    path = "/".join(("project", *prefix, "01_CompObj"))
    require(resources[COMP]["file"] == path, "form_compobj_path_differs")
    require(read_member(root, path) == original_streams[COMP], "native_form_compobj_differs")
    restored, extent = _frame(original_streams[FRAME], source, name, spec, codec)
    require(restored == original, "form_module_text_differs")
    frx = read_member(root, spec["file"])
    tag, size, zero1, zero2, cx, cy = struct.unpack_from("<6I", frx)
    require((tag,size,zero1,zero2) == (0x8424C,len(frx)-24,0,0), "invalid_frx_header")
    if (cx, cy) != extent:
        raise FormIssue("frx_extent_not_confirmed")
    with olefile.OleFileIO(io.BytesIO(frx[24:]), raise_defects=olefile.DEFECT_INCORRECT) as blob:
        frx_classes, frx_streams = tree(blob, ())
    if original_classes[()] not in ("", FORM_CLASS):
        raise FormIssue("unsupported_form_storage_class")
    require(frx_classes == {**original_classes, (): FORM_CLASS}, "frx_storage_classes_differ")
    expected = original_streams.copy()
    del expected[FRAME]
    expected[COMP] = _exported_compobj(expected[COMP])
    require(frx_streams == expected, "frx_logical_streams_differ")
