"""VERSIONINFO decode and re-encode as in the NATIVE-346 s5 resource check."""
import hashlib
import struct

FIXED_FIELDS = ("signature struct_version file_version_ms file_version_ls product_version_ms "
                "product_version_ls flags_mask flags os type subtype date_ms date_ls").split()


def digest(data):
    return hashlib.sha256(data).hexdigest()


def align(n):
    return (n + 3) & ~3


def read_version(raw, start, limit):
    size, count, kind = struct.unpack_from("<3H", raw, start)
    end = start + size
    if not 6 < size or end > limit:
        raise ValueError("version block extent")
    pos = start + 6
    while pos + 2 <= end and raw[pos:pos+2] != b"\0\0":
        pos += 2
    name = raw[start+6:pos].decode("utf-16le")
    value_start = align(pos+2)
    value_end = value_start + count * (2 if kind == 1 else 1)
    if value_end > end:
        raise ValueError(name)
    value = raw[value_start:value_end]
    entry = {"key": name, "type": kind}
    if name == "VS_VERSION_INFO":
        entry["fixed"] = dict(zip(FIXED_FIELDS, struct.unpack("<13I", value)))
    elif kind == 1 and count:
        entry["text"] = value.decode("utf-16le")
    elif count:
        entry["words"] = list(struct.unpack(f"<{count//2}H", value))
    subs = []
    pos = value_end
    while align(pos) < end:
        child, pos = read_version(raw, align(pos), end)
        subs.append(child)
    if subs:
        entry["children"] = subs
    return entry, end


def encode_version(node):
    if "fixed" in node:
        value = struct.pack("<13I", *(node["fixed"][name] for name in FIXED_FIELDS))
    elif "text" in node:
        value = node["text"].encode("utf-16le")
    elif "words" in node:
        value = struct.pack(f"<{len(node['words'])}H", *node["words"])
    else:
        value = b""
    count = len(value) // (2 if node["type"] == 1 else 1)
    body = bytearray(struct.pack("<3H", 0, count, node["type"]))
    body.extend((node["key"]+"\0").encode("utf-16le"))
    body.extend(bytes(align(len(body))-len(body)))
    body.extend(value)
    for child in node.get("children", []):
        body.extend(bytes(align(len(body))-len(body)))
        body.extend(encode_version(child))
    struct.pack_into("<H", body, 0, len(body))
    return bytes(body)


