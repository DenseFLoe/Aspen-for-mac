import hashlib
import json
import re
from pathlib import Path

import olefile
from oletools.olevba import VBA_Project, decompress_stream

root = Path(__file__).resolve().parent
original = root.parent / "input" / "vbaProject.bin"
stage = root / "stage" / "source"
stage.mkdir(parents=True, exist_ok=True)
protected = {"CMG", "DPB", "GC"}


def digest(data):
    return hashlib.sha256(data).hexdigest()


assert digest(original.read_bytes()) == "4e0bf2a2925b54c25f94911bdcce38a391f65ccb4667ea10841545c6dda8ba6f"
with olefile.OleFileIO(original, raise_defects=olefile.DEFECT_INCORRECT) as ole:
    project = VBA_Project(ole, "", "PROJECT", "VBA/dir", relaxed=False)
    project.parse_project_stream()
    list(project.parse_modules())
    source_modules = []
    streams = {
        "/".join(entry): ole.openstream(entry).read()
        for entry in ole.listdir()
    }
    storage = ["/".join(entry) for entry in ole.listdir(streams=False, storages=True)]
    assert not ole.parsing_issues
    project_lines = streams["PROJECT"].decode(project.codec, errors="strict").splitlines()
    items = {}
    for line in project_lines:
        kind, _, name = line.partition("=")
        if kind in {"Document", "Module", "Class", "BaseClass"}:
            items[name.split("/", 1)[0]] = kind
    assert len(items) == len(project.modules) == 5
    for module in project.modules:
        stream = streams[module.code_path]
        source = module.code_raw
        assert 0 < module.textoffset < len(stream)
        assert source == decompress_stream(stream[module.textoffset:])
        assert re.fullmatch(r"[\w-]+\.(bas|cls)", module.filename)
        assert source.decode(project.codec, errors="strict") == module.code
        assert re.search(rb'^Attribute VB_Name = "' + module.name.encode(project.codec) + rb'"\r?$', source, re.M)
        assert items[module.name] in {"Document", "Module", "Class"}
        assert module.type == (0x21 if items[module.name] == "Module" else 0x22)
        assert module.filename.endswith(".bas" if items[module.name] == "Module" else ".cls")
        (stage / module.filename).write_bytes(source)
        source_modules.append(dict(
            name=module.name, stream=module.code_path, filename=module.filename,
            source_offset=module.textoffset, source_bytes=len(source), source_sha256=digest(source),
            source_lines=len(source.splitlines()), stream_sha256=digest(stream), module_type=hex(module.type),
        ))
    assert set(items) == {module["name"] for module in source_modules}
    assert storage == ["VBA"]
    remaining = set(streams) - {module["stream"] for module in source_modules}
    core = {"PROJECT", "PROJECTwm", "VBA/dir", "VBA/_VBA_PROJECT"}
    assert remaining - core == {"VBA/__SRP_" + str(index) for index in (0, 1, 2, 3, 6, 7)}
    name_pairs = b"".join(
        name.encode(project.codec) + b"\0" + name.encode("utf-16le") + b"\0\0"
        for name in items
    )
    assert streams["PROJECTwm"] == name_pairs + b"\0\0"
    metadata = dict(
        project=project.projectname, codepage=project.codepage, codec=project.codec,
        vba_cache_version=hex(int.from_bytes(streams["VBA/_VBA_PROJECT"][2:4], "little")),
        modules=source_modules, storages=storage, project_items=items,
        project_stream_non_protection_records=[
            line for line in project_lines if line.partition("=")[0] not in protected
        ],
        project_protection_record_names=sorted(
            line.partition("=")[0] for line in project_lines if line.partition("=")[0] in protected
        ),
        projectwm_verified_name_pairs=list(items),
        streams=[
            {"path": name, "size": len(data), "sha256": digest(data)}
            for name, data in streams.items()
        ],
    )
    (root / "structure.json").write_text(json.dumps(metadata, indent=2, ensure_ascii=False), encoding="utf-8")
    print("CFB stream inventory and exact source verified:", len(streams), len(source_modules))

