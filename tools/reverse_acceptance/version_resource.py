"""Verify editable VERSIONINFO nodes by rebuilding the exact original resource bytes."""
import struct


FIXED = ("signature", "struct_version", "file_version_ms", "file_version_ls", "product_version_ms",
         "product_version_ls", "flags_mask", "flags", "os", "type", "subtype", "date_ms", "date_ls")


def integer(value, largest):
    if type(value) is not int or not 0 <= value <= largest:
        raise ValueError("unsigned integer outside the version resource field")
    return value


def encode(node, depth=0):
    # Each VERSIONINFO block has a WORD length. The known JSON schema uses
    # UTF-16 code units for text lengths and byte counts for binary values.
    if depth > 16:
        raise ValueError("unsupported version resource nesting")
    if not isinstance(node, dict) or not {"key", "type"} <= node.keys():
        raise ValueError("version block needs a key and a type")
    fields = node.keys() - {"key", "type", "children"}
    if fields not in (set(), {"fixed"}, {"text"}, {"words"}):
        raise ValueError("unsupported or conflicting version value fields")
    key, kind = node["key"], integer(node["type"], 1)
    if not isinstance(key, str) or not key or "\x00" in key or len(key) > 32767:
        raise ValueError("invalid UTF-16 version key")
    if depth == 0 and (key != "VS_VERSION_INFO" or kind != 0):
        raise ValueError("invalid VS_VERSION_INFO root")
    value = b""
    if "fixed" in fields:
        fixed = node["fixed"]
        if depth or kind or not isinstance(fixed, dict) or fixed.keys() != set(FIXED):
            raise ValueError("invalid VS_FIXEDFILEINFO fields")
        value = struct.pack("<13I", *(integer(fixed[k], 0xffffffff) for k in FIXED))
    elif "text" in fields:
        text = node["text"]
        if kind != 1 or not isinstance(text, str) or len(text) > 32767:
            raise ValueError("invalid version text")
        value = text.encode("utf-16-le")
    elif "words" in fields:
        words = node["words"]
        if kind != 0 or not isinstance(words, list) or len(words) > 32767:
            raise ValueError("invalid version word array")
        value = b"".join(struct.pack("<H", integer(i, 65535)) for i in words)
    children = node.get("children", [])
    if not isinstance(children, list):
        raise ValueError("invalid version children")
    data = bytearray(6)
    data.extend((key + "\x00").encode("utf-16-le"))
    data.extend(bytes(-len(data) % 4))
    data.extend(value)
    for child in children:
        data.extend(bytes(-len(data) % 4))
        data.extend(encode(child, depth + 1))
        if len(data) > 65535:
            raise ValueError("version block exceeds WORD length")
    struct.pack_into("<3H", data, 0, integer(len(data), 65535), len(value) // (2 if kind else 1), kind)
    return bytes(data)
