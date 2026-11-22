"""Verify an existing native PE resource inventory and its delivered payloads."""
import base64
import binascii
import csv
import hashlib
import json
import re
import struct
from pathlib import Path
if __package__:
    from .version_resource import encode as encode_version
else:
    from version_resource import encode as encode_version


SCOPE = ("PE resource identities, code pages, RVAs and payloads, including exact bytes rebuilt "
         "from supported editable VERSIONINFO documents. Source-level use and UI behaviour are outside this check.")
FIELDS = {"type", "name", "language", "bytes", "code_page", "rva", "sha256"}


def _rows(original):
    import pefile

    with pefile.PE(data=original, fast_load=True) as pe:
        dirs = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if len(dirs) <= 2:
            if pe.OPTIONAL_HEADER.NumberOfRvaAndSizes > 2:
                raise ValueError("declared resource directory entry cannot be read")
            return {}
        directory = dirs[2]
        base, size = directory.VirtualAddress, directory.Size
        if not base and not size:
            return {}
        if not base or size < 16:
            raise ValueError("invalid PE resource directory")

        def raw(rva, count):
            sections = [s for s in pe.sections if rva >= s.VirtualAddress and
                        rva + count <= s.VirtualAddress + min(s.SizeOfRawData, s.Misc_VirtualSize or s.SizeOfRawData)]
            if len(sections) != 1:
                raise ValueError("unmapped or ambiguous PE resource range")
            s = sections[0]
            off = s.PointerToRawData + rva - s.VirtualAddress
            if off + count > len(original):
                raise ValueError("truncated PE resource range")
            return original[off:off + count]

        # Parse every declared entry (the high-level pefile resource parser can
        # truncate corrupt tables). All table/name/data-descriptor offsets are
        # relative to the resource directory RVA, while payload addresses are RVAs.
        image = raw(base, size)

        def inside(off, size):
            if off < 0 or off + size > len(image):
                raise ValueError("out-of-directory PE resource entry")

        def label(value):
            if value >> 31:
                offset = value & 0x7fffffff
                inside(offset, 2)
                length = 2 * struct.unpack_from("<H", image, offset)[0]
                inside(offset + 2, length)
                return ("name", image[offset+2:offset+2+length].decode("utf-16le", errors="strict"))
            if value > 65535:
                raise ValueError("reserved numeric resource ID bits")
            return ("id", str(value))

        output = {}
        seen = set()

        def walk(offset, path):
            if offset in seen:
                raise ValueError("shared or cyclic resource directory requires independent review")
            seen.add(offset)
            inside(offset, 16)
            named, ids = struct.unpack_from("<HH", image, offset + 12)
            inside(offset + 16, 8 * (named+ids))
            for i in range(named+ids):
                name, nxt = struct.unpack_from("<II", image, offset+16+8*i)
                if bool(name >> 31) != (i < named):
                    raise ValueError("named/numeric resource count mismatch")
                key = (*path, label(name))
                if len(key) < 3:
                    if not nxt >> 31:
                        raise ValueError("short resource path")
                    walk(nxt & 0x7fffffff, key)
                    continue
                if nxt >> 31:
                    raise ValueError("unexpected resource subtree below language")
                inside(nxt,16)
                rva, length, cp, reserved = struct.unpack_from("<IIII",image,nxt)
                if reserved or key in output:
                    raise ValueError("invalid or duplicate original resource leaf")
                payload = raw(rva, length) if length else b""
                output[key] = (rva, length, cp, hashlib.sha256(payload).hexdigest(), payload)

        walk(0, ())
        return output


def _unique_object(pairs):
    out = {}
    for key, val in pairs:
        if key in out:
            raise ValueError("duplicate JSON property " + key)
        out[key] = val
    return out


def _number(x):
    if type(x) is int and x >= 0:
        return x
    if isinstance(x, str):
        if re.fullmatch(r"[0-9]+", x):
            return int(x)
        if re.fullmatch(r"0[xX][0-9a-fA-F]+", x):
            return int(x, 16)
    raise ValueError("expected an unsigned integer")


def check(original: bytes, delivery: Path) -> dict:
    result = {"status":"pass", "scope":SCOPE, "metrics":{}, "findings":[]}
    metrics = result["metrics"]

    def finding(status, code, **details):
        result["findings"].append({"code":code, "status":status, **details})
        if status == "fail" or result["status"] == "pass":
            result["status"] = status

    try:
        originals = _rows(original)
    except Exception as err:
        finding("inconclusive", "original_resource_directory_unverified", reason=str(err))
        return result
    keyed = {}
    for typed, item in originals.items():
        key = tuple(value for kind, value in typed)
        if key in keyed:
            finding("inconclusive", "csv_resource_identity_ambiguous", key=key)
            return result
        keyed[key] = item
        if any(kind == "name" and re.fullmatch(r"[0-9]+", value) for kind, value in typed):
            finding("inconclusive", "numeric_text_resource_name_untyped_in_csv", key=key)
    metrics.update(original_leaves=len(keyed), original_payload_bytes=sum(r[1] for r in keyed.values()),
                   resource_types=len({key[0] for key in keyed}), delivered_payloads=0, delivered_payload_bytes=0)
    root = Path(delivery).resolve()

    def check_rows(rows, layer, with_payload):
        seen = set()
        for i,row in enumerate(rows,1):
            if not isinstance(row,dict) or not FIELDS.issubset(row) or None in row:
                raise ValueError(f"resource row {i} lacks expected fields")
            parts = [row[f] for f in ("type","name","language")]
            if any(type(v) not in (int,str) for v in parts):
                raise ValueError(f"invalid resource identifier at row {i}")
            key = tuple(map(str,parts))
            if key in seen:
                finding("fail","duplicate_resource",layer=layer,key=key)
                continue
            seen.add(key)
            if key not in keyed:
                finding("fail","extra_resource",layer=layer,key=key)
                continue
            ref = keyed[key]
            observed = (_number(row["rva"]),_number(row["bytes"]),_number(row["code_page"]),row["sha256"])
            if not isinstance(observed[3],str) or not re.fullmatch(r"[0-9a-fA-F]{64}", observed[3]):
                raise ValueError(f"invalid SHA-256 at row {i}")
            observed = (*observed[:3], observed[3].lower())
            for name, expected, actual in zip(("rva","bytes","code_page","sha256"),ref,observed):
                if expected != actual:
                    finding("fail","resource_descriptor_mismatch",layer=layer,key=key,field=name,
                            expected=expected,actual=actual)
            if with_payload:
                try:
                    value = row.get("content_base64")
                    if not isinstance(value,str) or len(value) != 4*((ref[1]+2)//3):
                        raise ValueError("size or encoding mismatch")
                    blob = base64.b64decode(value,validate=True)
                    if blob != ref[4]:
                        raise ValueError("bytes differ from original")
                except (ValueError,binascii.Error) as err:
                    finding("fail","resource_payload_mismatch",layer=layer,key=key,reason=str(err))
                else:
                    metrics["delivered_payloads"] += 1
                    metrics["delivered_payload_bytes"] += len(blob)
        for key in sorted(keyed.keys() - seen):
            finding("fail","missing_resource",layer=layer,key=key)
        metrics[layer + "_unique"] = len(seen)

    layers = (("inventory","resources.csv"),("payload","s5/resources.json"))
    supplied_tables = any((root / name).is_file() for _, name in layers)
    versions = {key: value for key, value in originals.items() if key[0] == ("id", "16")}
    verified = set()
    models = {}
    for relative in ("version.json", "s5-data/version-resource.json"):
        path = root / relative
        if not path.is_file():
            continue
        try:
            if not path.resolve().is_relative_to(root):
                raise ValueError("version document outside delivery")
            if path.stat().st_size > 2 * 1024 * 1024:
                finding("inconclusive", "version_document_limit", path=relative)
                continue
            doc = json.loads(path.read_text(encoding="utf-8-sig"), object_pairs_hook=_unique_object)
            if relative == "version.json":
                # This generic filename is also used for unrelated application metadata.
                if not isinstance(doc, dict) or not {"key", "type"} <= doc.keys():
                    continue
                if len(versions) != 1:
                    finding("inconclusive" if versions else "fail", "version_leaf_not_unique",
                            path=relative, original_version_leaves=len(versions))
                    continue
                key, = versions
                node = doc
            else:
                if not isinstance(doc, dict) or doc.keys() != {"resource_type", "id", "language", "code_page", "root"}:
                    raise ValueError("invalid wrapped version document")
                key = tuple(("id", str(_number(doc[k]))) for k in ("resource_type", "id", "language"))
                if key not in versions:
                    finding("fail", "version_resource_identity", path=relative, key=key)
                    continue
                if _number(doc["code_page"]) != versions[key][2]:
                    finding("fail", "version_code_page", path=relative, original=versions[key][2], claimed=doc["code_page"])
                node = doc["root"]
            rva, length, code_page, expected_sha, raw = versions[key]
            rebuilt = encode_version(node)
            model = dict(key=key, rva=hex(rva), bytes=length, code_page=code_page,
                         original_sha256=expected_sha, rebuilt_sha256=hashlib.sha256(rebuilt).hexdigest())
            models[relative] = model
            if raw == rebuilt:
                verified.add(key)
                model["bytes_match"] = True
            else:
                model["bytes_match"] = False
                at = next((i for i,(a,b) in enumerate(zip(raw, rebuilt)) if a != b), min(length, len(rebuilt)))
                finding("fail", "version_resource_bytes", path=relative, offset=at, rva=hex(rva + at),
                        original=raw[at:at+1].hex() or None, rebuilt=rebuilt[at:at+1].hex() or None)
        except (ValueError, OSError, RecursionError) as err:
            finding("inconclusive", "version_model_unverified", path=relative, reason=str(err))
    metrics.update(version_models=models, rebuilt_version_leaves=len(verified),
                   rebuilt_version_bytes=sum(versions[k][1] for k in verified))

    if not supplied_tables:
        for key in sorted(originals.keys() - verified):
            finding("inconclusive", "resource_bytes_unverified", key=key, rva=hex(originals[key][0]))
        return result

    for layer,relative in layers:
        target = (root/relative).resolve()
        if not target.is_relative_to(root):
            finding("fail","resource_file_outside_delivery",layer=layer)
            continue
        if not target.is_file():
            finding("inconclusive","resource_evidence_missing",layer=layer)
            continue
        try:
            if layer=="inventory":
                with target.open(encoding="utf-8-sig",newline="") as f:
                    reader=csv.DictReader(f,strict=True)
                    header=reader.fieldnames or []
                    if len(set(header))!=len(header) or not FIELDS.issubset(header):
                        raise ValueError("missing or duplicate resource inventory columns")
                    check_rows(reader,layer,False)
            else:
                doc=json.loads(target.read_text(encoding="utf-8-sig"), object_pairs_hook=_unique_object)
                if not isinstance(doc,dict) or not isinstance(doc.get("resources"),list):
                    raise ValueError("expected a resources array")
                check_rows(doc["resources"],layer,True)
        except (ValueError,OSError,csv.Error) as err:
            finding("fail","malformed_resource_evidence",layer=layer,reason=str(err))
    if not keyed:
        finding("inconclusive","no_original_resource_leaves")
    return result

