"""Scan SHA-verified CLR assembly metadata from the published inventories on Windows."""
import argparse
import csv
import ctypes
import hashlib
import io
import json
import os
import struct
import subprocess
import tempfile
from collections import Counter, defaultdict
from pathlib import Path, PurePosixPath, PureWindowsPath


PIN = "7ba3491dda331a04fa25298ba9bb7cee809bb0da"
PRODUCTS = ("plus", "properties", "shared")
FOLDERS = {
    "[ProgramFiles64Folder]": "Program Files",
    "[ProgramFilesFolder]": "Program Files (x86)",
    "[CommonFiles64Folder]": "Program Files/Common Files",
    "[CommonFilesFolder]": "Program Files (x86)/Common Files",
}
FIELDS = ("name", "version", "culture", "public_key_token", "content_type")
MANIFEST_HASHES = {
    "plus": "97f64d168dbc33f6281233f59e411c0efe69e7224400bde58c76220b98b6d2c3",
    "properties": "8706fcc38d4d089e0bc18b97f4cc6a2ee732ffe0d0e166a18c8b220f750983b4",
    "shared": "834e6d51a86d531607e2ce630b173546fbe450fc4d13f9c12009e48f96f5b03d",
}
EDGE_FIELDS = ["assembly", "ref_name", "ref_version", "resolved_path", "resolve_status",
               "ref_public_key_token", "ref_culture", "ref_content_type", "ref_flags",
               "edge_id", "source_id", "assemblyref_rid", "status", "rule", "target_id", "candidate_ids"]


def file_digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def read_inventories(folder):
    items = []
    summaries = {}
    for name in PRODUCTS:
        raw = (folder / (name + ".csv")).read_bytes()
        rows = list(csv.DictReader(io.StringIO(raw.decode("utf-8-sig"), newline="")))
        selected = [(i, row) for i, row in enumerate(rows, 2)
                    if row["format"].startswith("PE-CLR-")]
        summaries[name] = {"file_sha256": hashlib.sha256(raw).hexdigest(), "rows": len(rows),
                           "clr_rows": len(selected)}
        if summaries[name]["file_sha256"] != MANIFEST_HASHES[name]:
            raise ValueError(f"{name}.csv content does not match {PIN}")
        for i, row in selected:
            items.append((name, i, row))
    return items, summaries


def msi_stream(path, member):
    """Read an original Binary table stream using read-only Windows Installer handles."""
    msi = ctypes.WinDLL("msi.dll")
    u32 = ctypes.c_uint32
    ptr = ctypes.byref
    handles = []

    def checked(code):
        if code:
            raise OSError(code, f"MSI stream {member}")

    try:
        db = u32()
        checked(msi.MsiOpenDatabaseW(str(path), None, ptr(db)))
        handles.append(db)
        view = u32()
        table, name = member.split("/", 1)
        if table != "Binary" or "'" in name:
            raise ValueError(member)
        checked(msi.MsiDatabaseOpenViewW(db, "SELECT `Data` FROM `Binary` WHERE `Name`='" + name + "'", ptr(view)))
        handles.append(view)
        checked(msi.MsiViewExecute(view, 0))
        rec = u32()
        checked(msi.MsiViewFetch(view, ptr(rec)))
        handles.append(rec)
        data = bytearray()
        buf = ctypes.create_string_buffer(65536)
        while True:
            size = u32(len(buf))
            checked(msi.MsiRecordReadStream(rec, 1, buf, ptr(size)))
            data.extend(buf.raw[:size.value])
            if size.value < len(buf):
                return bytes(data)
    finally:
        for handle in reversed(handles):
            msi.MsiCloseHandle(handle)


def canonical(row):
    path = row["relative_path"].replace("\\", "/")
    first, sep, rest = path.partition("/")
    if first == "[TARGETDIR]" and row.get("target_resolution") == "gac-installed-identical":
        return PureWindowsPath(row["installed_path"]).as_posix().split(":/", 1)[-1]
    return FOLDERS.get(first, first) + sep + rest


def product(row):
    if "Database-Server" in row["scope"]:
        return ["Properties Enterprise Database Server"]
    return row["owner"].split(";")


def source_path(value, media):
    path = Path(value)
    if media and path.suffix.casefold() in (".msi", ".cab"):
        return media / path.parent.name / path.name
    return path


def find_binaries(items, scratch, media):
    by_hash = defaultdict(list)
    for _, _, row in items:
        by_hash[row["sha256"]].append(row)
    files = {}
    methods = Counter()
    for digest, rows in sorted(by_hash.items()):
        paths = {}
        for row in rows:
            if row["source"] == "installed-owned":
                paths[Path(row["original_path"])] = None
            if row.get("installed_path"):
                paths[Path(row["installed_path"])] = None
            path = canonical(row)
            if path.startswith("Program Files"):
                paths[Path(os.environ["SystemDrive"] + "/") / path] = None
        for path in paths:
            if path.is_file() and file_digest(path) == digest:
                files[digest] = path
                methods["installed_sha_match"] += 1
                break
        if digest in files:
            continue
        seen = set()
        errors = []
        for row in rows:
            pair = (row["container"], row["member"])
            if pair in seen or not pair[0]:
                continue
            seen.add(pair)
            path = source_path(pair[0], media)
            if not path.is_file():
                continue
            try:
                if row["source"] == "installer-msi-stream":
                    data = msi_stream(path, pair[1])
                elif row["source"] == "installer-payload":
                    data = subprocess.run(["tar.exe", "-xOf", str(path), pair[1]],
                                          capture_output=True, check=True).stdout
                else:
                    continue
                if hashlib.sha256(data).hexdigest() != digest:
                    raise ValueError("member digest differs")
                out = scratch / digest
                out.write_bytes(data)
                files[digest] = out
                methods[row["source"]] += 1
                break
            except (OSError, ValueError, subprocess.SubprocessError) as exc:
                errors.append(str(exc))
        if digest not in files:
            raise ValueError(f"Missing verified bytes for {digest}, {rows[0]['relative_path']}: {errors}")
    return files, dict(sorted(methods.items()))


def metadata(files, scratch):
    if not files:
        return {}
    input_list = scratch / "inputs.json"
    entries = [{"sha256": k, "path": str(v)} for k, v in sorted(files.items())]
    input_list.write_text(json.dumps(entries), encoding="utf-8")
    cmd = ["pwsh", "-NoProfile", "-File", str(Path(__file__).with_name("read-metadata.ps1")),
           "-InputList", str(input_list)]
    result = subprocess.run(cmd, stdout=subprocess.PIPE, check=True, encoding="utf-8")
    data = [json.loads(line) for line in result.stdout.splitlines()]
    return {row["sha256"]: row for row in data}


def make_nodes(items, data):
    # Some mirrored Plus rows omit the resolved GAC path that Properties records.
    known = {(r["sha256"], r["relative_path"].casefold()): canonical(r) for _, _, r in items
             if r.get("target_resolution") == "gac-installed-identical"}
    groups = {}
    for name, index, row in items:
        digest = row["sha256"]
        path = known.get((digest, row["relative_path"].casefold()), canonical(row))
        # Unknown install target and Binary streams have no physical sibling directory.
        context = row["scope"] if path.startswith(("[TARGETDIR]/", "Binary/")) else ""
        key = (path.casefold(), context, digest)
        node = groups.setdefault(key, {"path": path, "sha256": digest, "context": context,
                                       "products": set(), "origins": defaultdict(list)})
        node["products"].update(product(row))
        node["origins"][name].append(index)
    nodes = []
    for index, key in enumerate(sorted(groups)):
        node = groups[key]
        node["id"] = index
        node["products"] = sorted(node["products"])
        node["product"] = ";".join(node["products"])
        node["identity"] = data[node["sha256"]]["identity"]
        nodes.append(node)
    return nodes


def identity_key(identity):
    return tuple(str(identity[f]).casefold() for f in FIELDS)


def has_clr_header(path):
    """Use PE headers only; extensions do not distinguish managed executables."""
    with path.open("rb") as stream:
        if stream.read(2) != b"MZ":
            return False
        stream.seek(60)
        pointer = stream.read(4)
        if len(pointer) != 4:
            return False
        stream.seek(struct.unpack("<I", pointer)[0])
        header = stream.read(24)
        if len(header) != 24 or not header.startswith(b"PE\0\0"):
            return False
        optional = stream.read(struct.unpack_from("<H", header, 20)[0])
        if len(optional) < 2:
            return False
        offset = {0x10b: 96, 0x20b: 112}.get(struct.unpack_from("<H", optional)[0])
        if offset is None or len(optional) < offset + 15 * 8:
            return False
        count = struct.unpack_from("<I", optional, offset - 4)[0]
        address, size = struct.unpack_from("<II", optional, offset + 14 * 8)
        return count >= 15 and address != 0 and size != 0


def directory_inputs(library, product_options, selected_roots):
    def checked(value):
        path = Path(value).resolve(strict=True)
        path.relative_to(library)
        return path

    def fail(error):
        raise error

    library = library.resolve(strict=True)
    if not library.is_dir():
        raise ValueError("--library requires a directory")
    product_dirs = []
    for option in product_options:
        name, sep, value = option.partition("=")
        if not sep or not name or not value:
            raise ValueError("--product must be NAME=DIRECTORY")
        folder = checked(value)
        if not folder.is_dir():
            raise ValueError(f"product directory missing: {value}")
        product_dirs.append((name, folder))
    roots = [checked(value) for value in selected_roots] or [library]
    files, nodes, selected = {}, [], []
    file_count = 0
    for folder, _, filenames in os.walk(library, onerror=fail):
        for name in filenames:
            path = Path(folder) / name
            if not path.is_file():
                continue
            file_count += 1
            if not has_clr_header(path):
                continue
            digest = file_digest(path)
            files[digest] = path
            products = sorted({name for name, base in product_dirs if path.is_relative_to(base)})
            if not product_dirs:
                products = ["library"]
            nodes.append({"path": path.relative_to(library).as_posix(), "sha256": digest,
                          "products": products, "product": ";".join(products), "context": "", "origins": {}})
    nodes.sort(key=lambda n: (n["path"].casefold(), n["path"], n["sha256"]))
    for i, node in enumerate(nodes):
        node["id"] = i
        path = library / node["path"]
        if any(path.is_relative_to(root) for root in roots):
            selected.append(i)
    return nodes, files, selected, {"directory_file_count": file_count}


def build_edges(nodes, data):
    by_identity = defaultdict(list)
    by_name = defaultdict(list)
    for n in nodes:
        by_identity[identity_key(n["identity"])].append(n)
        by_name[n["identity"]["name"].casefold()].append(n)
    directories = [str(PurePosixPath(n["path"]).parent).casefold() for n in nodes]
    edges = []
    for node in nodes:
        source = node["id"]
        for rid, ref in enumerate(data[node["sha256"]]["refs"], 1):
            exact = by_identity.get(identity_key(ref), [])
            directory = [n for n in exact if not node["context"] and not n["context"]
                         and directories[source] == directories[n["id"]]]
            same_product = [n for n in exact if set(n["products"]).intersection(node["products"])]
            candidates = directory or same_product or exact
            rule = "same_directory" if directory else "same_product" if same_product else "whole_library" if exact else ""
            status = "resolved"
            target = ""
            if candidates:
                if len({n["sha256"] for n in candidates}) == 1:
                    target = candidates[0]["id"]
                else:
                    status = "ambiguous_identity"
            else:
                candidates = by_name.get(ref["name"].casefold(), [])
                status = "identity_mismatch" if candidates else "name_absent"
            edge = {"edge_id": len(edges), "source_id": source, "assemblyref_rid": rid}
            edge.update({"ref_" + k: v for k, v in ref.items()})
            edge.update(status=status, rule=rule, target_id=target,
                        candidate_ids=" ".join(str(n["id"]) for n in candidates))
            edge.update(assembly=node["path"], resolved_path=nodes[target]["path"] if target != "" else "",
                        resolve_status=status)
            edges.append(edge)
    return edges


def closures(root_ids, edges):
    out = defaultdict(list)
    for e in edges:
        out[e["source_id"]].append(e)
    roots = []
    for root in root_ids:
        seen = {root}
        stack = list(seen)
        gaps = set()
        while stack:
            for e in out[stack.pop()]:
                target = e["target_id"]
                if target == "":
                    gaps.add(e["edge_id"])
                elif target not in seen:
                    seen.add(target)
                    stack.append(target)
        roots.append({"id": root, "reachable": sorted(seen), "unresolved": sorted(gaps)})
    return roots


def main():
    p = argparse.ArgumentParser(description=__doc__)
    source = p.add_mutually_exclusive_group(required=True)
    source.add_argument("--inventory-dir", type=Path, help="pinned plus.csv, properties.csv, shared.csv")
    source.add_argument("--library", type=Path, help="recursively inspect this directory for managed PE files")
    p.add_argument("--product", action="append", default=[], metavar="NAME=DIRECTORY",
                   help="directory mode: assign same-product search scopes; repeatable")
    p.add_argument("--root", action="append", default=[], metavar="FILE_OR_DIRECTORY",
                   help="directory mode: restrict reported transitive roots; defaults to all; repeatable")
    p.add_argument("--media-dir", type=Path, help="optional relocated aspenonesuite directory")
    p.add_argument("--out", type=Path, required=True)
    args = p.parse_args()
    if args.inventory_dir and (args.product or args.root):
        p.error("--product and --root require --library")
    if args.library and args.media_dir:
        p.error("--media-dir requires --inventory-dir")
    manifests = {}
    with tempfile.TemporaryDirectory(prefix="aspen-clr-verified-") as temp:
        scratch = Path(temp)
        if args.inventory_dir:
            items, manifests = read_inventories(args.inventory_dir)
            files, methods = find_binaries(items, scratch, args.media_dir)
            scope = {"clr_inventory_records": len(items)}
        else:
            nodes, files, selected, scope = directory_inputs(args.library, args.product, args.root)
            methods = {"library_file": len(files)}
        data = metadata(files, scratch)
    if args.inventory_dir:
        skipped = {digest: item["skip"] for digest, item in data.items() if "skip" in item}
        if skipped:
            raise ValueError(f"Inventory lists CLR entries without assembly definitions: {skipped}")
        nodes = make_nodes(items, data)
        selected = [n["id"] for n in nodes]
    else:
        selected_ids = set(selected)
        selected = []
        assemblies = []
        skips = Counter()
        for node in nodes:
            item = data[node["sha256"]]
            if "skip" in item:
                skips[item["skip"]] += 1
                continue
            if node["id"] in selected_ids:
                selected.append(len(assemblies))
            node["id"] = len(assemblies)
            node["identity"] = item["identity"]
            assemblies.append(node)
        nodes = assemblies
        scope["skipped_cli_occurrences"] = dict(sorted(skips.items()))
        data = {digest: item for digest, item in data.items() if "skip" not in item}
    edges = build_edges(nodes, data)
    roots = closures(selected, edges)
    summary = {**scope, "unique_source_sha256": len(data), "library_node_count": len(nodes),
               "root_count": len(roots), "assemblyref_rows_by_unique_source": sum(len(r["refs"]) for r in data.values()),
               "assemblyref_edges": len(edges), "status_counts": dict(sorted(Counter(e["status"] for e in edges).items())),
               "rule_counts_resolved": dict(sorted(Counter(e["rule"] for e in edges if e["status"] == "resolved").items())),
               "roots_with_unresolved": sum(bool(r["unresolved"]) for r in roots),
               "roots_fully_resolved": sum(not r["unresolved"] for r in roots)}
    args.out.mkdir(parents=True, exist_ok=True)
    with (args.out / "assemblyrefs.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=EDGE_FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(edges)
    gaps = [{"edge_id": e["edge_id"], "source_id": e["source_id"], "assemblyref_rid": e["assemblyref_rid"],
             "name": e["ref_name"], "version": e["ref_version"], "culture": e["ref_culture"],
             "public_key_token": e["ref_public_key_token"], "content_type": e["ref_content_type"],
             "flags": e["ref_flags"], "status": e["status"],
             "candidate_ids": [int(i) for i in e["candidate_ids"].split()]} for e in edges if e["target_id"] == ""]
    graph = {"schema_version": 1, "inventory_commit": PIN if args.inventory_dir else None,
             "inventories": manifests, "summary": summary,
             "nodes": nodes, "roots": roots, "unresolved_edges": gaps}
    with (args.out / "closure.json").open("w", encoding="utf-8", newline="\n") as stream:
        # One record per source or closure, keeping human diffs small.
        for key in ("schema_version", "inventory_commit", "inventories", "summary"):
            stream.write(("{" if key == "schema_version" else ",\n") + json.dumps(key) + ":" + json.dumps(graph[key], ensure_ascii=False))
        for key in ("nodes", "roots", "unresolved_edges"):
            stream.write(",\n" + json.dumps(key) + ":[\n")
            stream.write(",\n".join(json.dumps(r, ensure_ascii=False, separators=(",", ":")) for r in graph[key]))
            stream.write("\n]")
        stream.write("}\n")
    print(json.dumps({"summary": summary, "actual_read_methods": methods}, sort_keys=True))


if __name__ == "__main__":
    main()
