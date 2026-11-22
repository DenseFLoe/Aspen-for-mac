import hashlib
import io
import json
import re
import sys
import zipfile
from pathlib import Path
from types import SimpleNamespace
from xml.etree import ElementTree as ET

root = Path(__file__).resolve().parent
sys.path.insert(0, str(root / "deps"))
import olefile
from oletools.olevba import VBA_Project
from pcodedmp.pcodedmp import processFile

original = root.parent / "input" / "vba_caller.xlsm"
stage = root / "stage"
stage.mkdir(exist_ok=True)
for kind in ("source", "ooxml"):
    (stage / kind).mkdir(exist_ok=True)

def digest(data):
    return hashlib.sha256(data).hexdigest()

assert digest(original.read_bytes()) == "10b51a5d9521fb78e6d1d90ad9ec3a46e9afa2e397a7f91ba8dddc9ab8f43dc0"
with zipfile.ZipFile(original) as package:
    assert package.testzip() is None
    parts = package.namelist()
    assert len(parts) == len(set(parts))
    for name in parts:
        if name == "xl/vbaProject.bin":
            continue
        raw = package.read(name)
        ET.fromstring(raw)
        target = (stage / "ooxml" / name).resolve()
        assert target.is_relative_to(stage / "ooxml")
        target.parent.mkdir(exist_ok=True, parents=True)
        target.write_bytes(raw)
    compound = package.read("xl/vbaProject.bin")

with olefile.OleFileIO(io.BytesIO(compound), raise_defects=olefile.DEFECT_INCORRECT) as ole:
    project = VBA_Project(ole, "", "PROJECT", "VBA/dir", relaxed=False)
    project.parse_project_stream()
    list(project.parse_modules())
    project_raw = ole.openstream("PROJECT").read()
    metadata = project_raw.decode(project.codec, errors="strict")
    modules = []
    for module in project.modules:
        source = module.code_raw
        assert re.fullmatch(r"[\w-]+\.(bas|cls|frm|vba)", module.filename)
        assert source.decode(project.codec, errors="strict") == module.code
        (stage / "source" / module.filename).write_bytes(source)
        stream = ole.openstream(module.code_path).read()
        modules.append(dict(name=module.name, stream=module.code_path, filename=module.filename,
                            source_offset=module.textoffset, source_bytes=len(source),
                            source_sha256=digest(source), source_lines=len(source.splitlines()),
                            stream_sha256=digest(stream), module_type=hex(module.type)))
    streams = [{"path": "/".join(entry), "size": ole.get_size(entry),
                "sha256": digest(ole.openstream(entry).read())} for entry in ole.listdir()]
    storage = ["/".join(parts) for parts in ole.listdir(streams=False, storages=True)]
    project_keys = [line.split("=", 1)[0] for line in metadata.splitlines() if "=" in line]
    project_version = int.from_bytes(ole.openstream("VBA/_VBA_PROJECT").read()[2:4], "little")
    (root / "project.private.txt").write_text(metadata, encoding="utf-8")
    (root / "structure.json").write_text(json.dumps(
        dict(parts=parts, project=project.projectname, codepage=project.codepage, codec=project.codec,
             vba_cache_version=hex(project_version), modules=modules, streams=streams, storages=storage,
             project_keys=project_keys), indent=2, ensure_ascii=False), encoding="utf-8")
    print("Project", project.projectname, project.codepage, len(modules))
    print("PROJECT record names:", sorted(set(project_keys)))
    print("CFB storages:", storage)
    for row in streams:
        print("stream", row["path"], row["size"])
    for module in modules:
        print("module", module["filename"], module["source_offset"], module["source_lines"])

with (root / "pcode.private.txt").open("w", encoding="utf-8") as result:
    processFile(str(original), SimpleNamespace(disasmOnly=True, verbose=False), output_file=result)

