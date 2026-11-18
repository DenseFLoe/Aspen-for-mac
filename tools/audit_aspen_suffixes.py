"""Investigate inventory uncertainties without executing original Aspen inputs.

All evidence, original samples, and revised inventories go to a new local path.
Full-file structure validation is distinguished from suffix-level sampling.
"""

import argparse
import collections
import concurrent.futures
import csv
import ctypes
import datetime
import hashlib
import io
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import zipfile
import zlib

from inventory_aspen_sources import DIRECT, REVERSE, MsiReader, emit_json, pe_info


def load_rows(root):
    rows = []
    for category in (REVERSE, DIRECT):
        with (root / category / "files.csv").open(encoding="utf-8-sig", newline="") as stream:
            rows.extend(csv.DictReader(stream))
    return rows


def identity(row):
    return row["sha256"] or row["source"] + "|" + row["relative_path"]


def choose_samples(rows):
    unresolved = [r for r in rows if r["review"] or r["read_status"] != "ok"]
    selected = {}
    # Examine all unresolved primary files, then distinct representatives of every
    # remaining suffix. Hash-identical installed copies share the primary evidence.
    for row in sorted(unresolved, key=lambda r: (int(r["priority"]), r["relative_path"].casefold())):
        if row["priority"] == "1":
            selected.setdefault(identity(row), row)
    groups = collections.defaultdict(list)
    for row in unresolved:
        groups[row["extension"]].append(row)
    for ext, matches in sorted(groups.items()):
        unique = {}
        for row in sorted(matches, key=lambda r: (int(r["priority"]), r["relative_path"].casefold())):
            unique.setdefault(identity(row), row)
        available = sorted(unique.values(), key=lambda r: (int(r["priority"]), int(r["size_bytes"] or 0), r["relative_path"].casefold()))
        for row in available[:2]:
            selected.setdefault(identity(row), row)
        if len(available) > 2:
            selected.setdefault(identity(available[-1]), available[-1])
    # Include contrasting readable VBA and library examples, not just uncertain
    # extensions as a whole. The full primary set already includes these when present.
    for name in ("ApwnShell.resources.dll", "ApwnShell.dll", "nl2sol.lib", "sastream.lib"):
        matches = [r for r in rows if r["relative_path"].split("/")[-1].casefold() == name.casefold() and r["read_status"] == "ok"]
        for row in sorted(matches, key=lambda r: (int(r["priority"]), r["relative_path"].casefold()))[:1]:
            selected.setdefault(identity(row), row)
    return unresolved, sorted(selected.values(), key=lambda r: (r["extension"], int(r["priority"]), r["relative_path"].casefold()))


class SourceReader:
    def __init__(self, sevenzip):
        self.sevenzip = sevenzip
        self.stream_cache = {}

    def cabinet(self, path, member):
        result = subprocess.run([str(self.sevenzip), "x", "-so", "-y", str(path), member],
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=180)
        if result.returncode:
            raise OSError(f"7-Zip exit {result.returncode}: {result.stderr.decode('utf-8', 'replace')[-400:]}")
        return result.stdout

    def read(self, row):
        if row["read_status"] == "encrypted-member-not-read":
            raise PermissionError("encrypted ZIP member: content is unavailable without a password")
        source = row["source"]
        if source == "installer-payload":
            return self.cabinet(row["container"], row["member"])
        if source == "installer-msi-stream":
            msi = row["container"]
            if msi not in self.stream_cache:
                reader = MsiReader(Path(msi))
                try:
                    self.stream_cache[msi] = {}
                    for table in ("Binary", "Icon"):
                        for item in reader.streams(table):
                            if len(item["head"]) == item["size"]:
                                self.stream_cache[msi][table + "/" + item["name"]] = item["head"]
                finally:
                    reader.close()
            return self.stream_cache[msi][row["member"]]
        if source.endswith(":zip-member"):
            cabinet, separator, outer = row["container"].partition("!/")
            if separator:
                data = self.cabinet(cabinet, outer)
                with zipfile.ZipFile(io.BytesIO(data)) as archive:
                    return archive.read(row["member"])
            with zipfile.ZipFile(row["container"]) as archive:
                return archive.read(row["member"])
        return Path(row["original_path"]).read_bytes()


def decode_text(data):
    for encoding in ("utf-8-sig", "utf-16", "utf-16-le", "cp1252"):
        try:
            text = data.decode(encoding)
        except (UnicodeError, LookupError):
            continue
        if not text:
            continue
        ratio = sum(c.isprintable() or c in "\r\n\t\f\x1a" for c in text) / len(text)
        # Avoid treating arbitrary CJK codepoints obtained from byte pairs as text.
        ascii_ratio = sum(ord(c) < 128 and (c.isprintable() or c.isspace()) for c in text) / len(text)
        if ratio > .97 and (not encoding.startswith("utf-16") or data.startswith((b"\xff\xfe", b"\xfe\xff")) or ascii_ratio > .65):
            return text, encoding
    return None, None


def coff_object(data):
    if len(data) < 20:
        return None
    if data[:6] == b"\0\0\xff\xff\0\0":
        string_size = struct.unpack_from("<I", data, 12)[0]
        machine = struct.unpack_from("<H", data, 6)[0]
        type_bits = struct.unpack_from("<H", data, 18)[0]
        if 2 <= string_size <= len(data) - 20 and machine in (0x14C, 0x8664, 0x1C0, 0xAA64) and type_bits & 3 <= 2:
            strings = data[20:20 + string_size].split(b"\0")
            if len(strings) >= 3 and strings[0] and strings[1]:
                return dict(kind="short-import", dll=strings[1].decode("ascii", "replace"))
    machine, count, _, symbols, symbol_count, optional, _ = struct.unpack_from("<HHIIIHH", data)
    if machine not in (0x14C, 0x8664, 0x1C0, 0xAA64) or not 0 < count < 8192 or 20 + optional + count * 40 > len(data):
        return None
    sections = []
    for i in range(count):
        pos = 20 + optional + 40 * i
        name = data[pos:pos + 8].split(b"\0", 1)[0].decode("ascii", "replace")
        length, offset = struct.unpack_from("<II", data, pos + 16)
        flags = struct.unpack_from("<I", data, pos + 36)[0]
        if length and offset + length > len(data):
            return None
        sections.append(dict(name=name, size=length, code=bool(flags & 0x20 and length)))
    # Traditional import descriptor members use .idata and .debug sections.
    import_only = all(s["name"].startswith((".idata", ".debug", ".drectve")) or s["size"] == 0 for s in sections)
    return dict(kind="coff-object", machine=hex(machine), sections=sections,
                import_descriptor=import_only and any(s["name"].startswith(".idata") for s in sections),
                code_bytes=sum(s["size"] for s in sections if s["code"]), symbols=symbol_count)


def coff_archive(data):
    pos = 8
    results = []
    while pos < len(data):
        header = data[pos:pos + 60]
        if len(header) != 60 or header[-2:] != b"`\n":
            raise ValueError("invalid archive member header")
        length = int(header[48:58])
        start = pos + 60
        if start + length > len(data):
            raise ValueError("truncated archive member")
        name = header[:16].decode("ascii").strip()
        if name not in ("/", "//", "/SYM64/"):
            result = coff_object(data[start:start + length])
            results.append(dict(name=name, **(result or dict(kind="unresolved-object"))))
        pos = start + length + (length & 1)
    counts = collections.Counter(r["kind"] for r in results)
    code = sum(bool(r.get("code_bytes")) for r in results)
    all_imports = bool(results) and all(r["kind"] == "short-import" or r.get("import_descriptor") for r in results)
    return dict(members=len(results), member_kinds=dict(counts), code_members=code,
                import_only=all_imports, member_details=results)


def ole_inspect(data, olefile):
    with olefile.OleFileIO(io.BytesIO(data)) as compound:
        streams = compound.listdir(streams=True, storages=False)
        result = dict(root_clsid=compound.root.clsid, streams=["/".join(p) for p in streams])
        result["vba"] = any("vba" in [p.casefold() for p in stream] or any(p.casefold() in ("_vba_project", "projectwm") for p in stream) for stream in streams)
        result["stream_headers"] = []
        for path in streams[:30]:
            head = compound.openstream(path).read(256)
            result["stream_headers"].append(dict(name="/".join(path), head_hex=head[:24].hex(), size=compound.get_size(path)))
        return result


def inspect(data, name, olefile):
    result = dict(bytes=len(data), head_hex=data[:64].hex())
    if data.startswith(b"MZ"):
        offset = struct.unpack_from("<I", data, 0x3C)[0]
        if data[offset:offset + 2] == b"NE":
            count = struct.unpack_from("<H", data, offset + 0x1C)[0]
            table = offset + struct.unpack_from("<H", data, offset + 0x22)[0]
            segments = [struct.unpack_from("<HHHH", data, table + i * 8) for i in range(count)]
            code = sum(bool(s[0]) and not s[2] & 1 for s in segments)
            result.update(format="NE-Win16", segments=count, code_segments=code, proposed_category=REVERSE if code else DIRECT,
                          confidence="structure-verified", finding="NE 16 位程序，存在代码段" if code else "NE 资源/数据段")
            return result
        import pefile
        with pefile.PE(data=data, fast_load=True) as pe:
            kind, has_code, flags, methods = pe_info(data)
            result.update(format=kind, code_sections=has_code, clr_flags=flags, method_definitions=methods,
                          machine=hex(pe.FILE_HEADER.Machine), sections=[s.Name.rstrip(b"\0").decode("ascii", "replace") for s in pe.sections])
        resource = (flags is not None and flags & 1 and methods == 0) or (flags is None and not has_code)
        result.update(proposed_category=DIRECT if resource else REVERSE, confidence="structure-verified",
                      finding="资源/元数据 PE，方法数为零或无可执行区段" if resource else "完整 PE/CLR 结构确认含编译代码")
        if flags is not None and flags & 1 and methods is None:
            result.update(confidence="unresolved", finding="完整文件仍未取得托管方法表；保留程序候选与待核实标记")
        return result
    if data.startswith(b"!<arch>\n"):
        archive = coff_archive(data)
        result.update(format="COFF-archive", archive=archive)
        if archive["import_only"]:
            result.update(proposed_category=DIRECT, confidence="structure-verified", finding="所有有效成员均为短导入记录或导入描述符，无实现代码成员")
        elif archive["code_members"]:
            result.update(proposed_category=REVERSE, confidence="structure-verified", finding="归档中存在实际 COFF 代码区段")
        else:
            result.update(proposed_category=REVERSE, confidence="unresolved", finding="COFF 归档存在尚未判明的成员")
        return result
    obj = coff_object(data)
    if obj:
        result.update(format="COFF-object", object=obj, proposed_category=REVERSE if obj.get("code_bytes") else DIRECT,
                      confidence="structure-verified", finding="COFF 对象，存在代码区段" if obj.get("code_bytes") else "COFF 导入/数据对象")
        return result
    if zipfile.is_zipfile(io.BytesIO(data)):
        with zipfile.ZipFile(io.BytesIO(data)) as archive:
            names = archive.namelist()
            vba = [n for n in names if n.casefold().endswith("vbaproject.bin")]
            vba_details = []
            for member in vba:
                vba_details.append(dict(member=member, **ole_inspect(archive.read(member), olefile)))
            code_names = [n for n in names if Path(n).suffix.lower() in {".dll", ".exe", ".obj", ".class"}]
            result.update(format="ZIP", members=names, vba_projects=vba_details, embedded_code_names=code_names,
                          proposed_category=REVERSE if vba or code_names else DIRECT, confidence="container-verified",
                          finding="包含 VBA 项目或嵌入代码；程序部分需单独处理" if vba or code_names else "已验证 ZIP 容器结构，按格式提取内容")
        return result
    if data.startswith(b"\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1"):
        ole = ole_inspect(data, olefile)
        result.update(format="OLE-compound", compound=ole, proposed_category=REVERSE if ole["vba"] else None,
                      confidence="container-verified" if ole["vba"] else "needs-stream-analysis",
                      finding="包含 VBA 结构" if ole["vba"] else "已识别 OLE 容器，需根据内部流用途决定")
        return result
    if data.startswith(b"RIFF") and data[8:12] == b"AVI ":
        result.update(format="RIFF-AVI", declared_size=struct.unpack_from("<I", data, 4)[0] + 8,
                      proposed_category=DIRECT, confidence="structure-verified", finding="AVI 媒体资源")
        return result
    if data.startswith((b"BM", b"\xff\xd8\xff")):
        from PIL import Image
        with Image.open(io.BytesIO(data)) as picture:
            picture.load()
            result.update(format=picture.format, dimensions=list(picture.size), image_mode=picture.mode,
                          proposed_category=DIRECT, confidence="structure-verified", finding="完整解码为图像资源")
        return result
    text, encoding = decode_text(data)
    if text is not None:
        result.update(format="text", encoding=encoding, lines=len(text.splitlines()),
                      text_preview="\n".join(text.splitlines()[:5])[:600], proposed_category=DIRECT,
                      confidence="decoded-full-file", finding="完整文件可解码为文本，按源码/配置/数据直接读取")
        return result
    if len(data) > 2 and data[0] == 0x78:
        try:
            raw = zlib.decompress(data)
            result.update(format="zlib", expanded_bytes=len(raw), expanded_head=raw[:64].hex())
        except zlib.error:
            pass
    result.setdefault("format", "unresolved-binary")
    result.update(proposed_category=None, confidence="unresolved", finding="需进一步检查内部格式及所属程序的读取方式")
    result["ascii_strings"] = [m.decode("ascii") for m in re.findall(rb"[\x20-\x7e]{10,100}", data[:131072])[:16]]
    return result


def framed_zlib(data):
    """Validate Aspen Economic Evaluation name/size/size/zlib framed members."""
    stream = io.BytesIO(data)
    members = []
    while stream.tell() < len(data):
        name = stream.readline(256)
        if not name:
            break
        if name in (b"\n", b"\r\n"):
            continue
        name = name.rstrip(b"\r\n").decode("ascii")
        size = int(stream.readline(32))
        compressed_size = int(stream.readline(32))
        if not 0 <= size <= 128 * 1024 * 1024 or not 0 <= compressed_size <= len(data):
            raise ValueError("framed member length out of bounds")
        block = stream.read(compressed_size)
        raw = zlib.decompress(block) if compressed_size else b""
        if len(raw) != size:
            raise ValueError("framed member expanded length mismatch")
        members.append(dict(name=name, size=size, compressed_size=compressed_size,
                            sha256=hashlib.sha256(raw).hexdigest(), embedded_program=raw.startswith((b"MZ", b"!<arch>\n", b"\x7fELF")),
                            head_hex=raw[:24].hex()))
    if not members:
        raise ValueError("no framed members")
    return members


def refine_inspection(data, row, result):
    """Narrow rules combine verified structure with owning product/context.

    Rules apply to inspected content hashes only. A matching suffix never changes
    an uninspected file, and opaque contents retain a review flag.
    """
    ext = row["extension"]
    path = row["relative_path"].replace("\\", "/")
    lower = path.casefold()
    if result["format"].startswith(("PE-", "NE-", "COFF-")):
        return result

    def set_result(kind, category, finding, confidence="structure-and-role-verified", **extra):
        result.update(format=kind, proposed_category=category, finding=finding, confidence=confidence, **extra)

    compound = result.get("compound")
    if compound and not compound["vba"]:
        streams = compound["streams"]
        roots = {s.split("/", 1)[0] for s in streams}
        if ext == ".acml" and "Root" in roots and any(s.startswith("InstanceData_") for s in streams):
            set_result("ACM-model-library", REVERSE, "模型语言库；原版帮助确认模型语言以加密形式存于 ACML，保留模型代码解析任务；非原生 DLL",
                       owner_help="acmhowto/Content/html/Controlling_Access_to_Model_Libraries.htm")
        elif ext == ".apm" and "CONTENTS" in roots and any(s.endswith("/TEMPLATE") for s in streams):
            set_result("Aspen-model-template", DIRECT, "模型模板容器：参数、连接与已读到的输入模板；外部计算程序另列")
        elif ext in {".apr", ".ppr"} and {"IWB", "IWD"}.issubset(roots):
            set_result("Aspen-resource-dictionary", DIRECT, "界面/模型资源字典；APR 含图标与模型目录，按 OLE 格式提取")
        elif ext == ".apvar" and {"BLOCK", "STREAM", "PROPERTIES"}.issubset(roots):
            set_result("Aspen-variable-metadata", DIRECT, "BLOCK/STREAM/PROPERTIES 变量与属性定义表，按元数据读取")
        elif "VisioDocument" in roots:
            set_result("Visio-document", DIRECT, "Visio 绘图资源；该样本无 VBA 存储")
        elif ext == ".ipt" and any("Pm" in s or "RSe" in s for s in streams):
            set_result("Inventor-part", DIRECT, "Inventor CAD 零件与几何数据存储；该样本无 VBA 存储")
        elif ext == ".dpp" and "Cases" in roots:
            set_result("Aspen-Dynamics-project", DIRECT, "动态模拟案例容器；程序引擎与案例数据分别处理")
        elif not streams:
            set_result("empty-OLE-container", DIRECT, "有效但无数据流的 OLE 容器")
    if data.startswith(b"SimulationCase10\x1a"):
        set_result("HYSYS-simulation-case", DIRECT, "已确认 HYSYS 案例/模板格式；作为输入数据解析，不作为独立程序反编译",
                   remaining_scope="内部扩展和脚本未完整审计；发现嵌入程序时须另列")
    elif data.startswith(b"HyconCaseV3.00K"):
        set_result("Energy-Analyzer-case", DIRECT, "能量分析案例，含流股/热力数据与工作簿配置")
    elif data.startswith(b"-ComponentList--\x1a"):
        set_result("HYSYS-component-list", DIRECT, "明确的 ComponentList 数据格式")
    elif data.startswith(b"NETDOC_V="):
        set_result("HYSYS-network-model-data", DIRECT, "NETDOC 版本与传热/侵蚀配置记录，按网络模型数据解析")
    elif ext in {".izp", ".szp"} and data.startswith((b"CASHFLOW.ICS\n", b"ANA_MISC.TMP\n")):
        members = framed_zlib(data)
        native = any(m["embedded_program"] for m in members)
        set_result("economic-zlib-bundle", REVERSE if native else DIRECT,
                   "逐成员通过长度与 zlib 校验；包含经济评价数据文件" if not native else "压缩内容含嵌入程序，需单独逆向",
                   compressed_members=members)
    elif ext == ".converters" and Path(path).name.casefold() == "ads.converters":
        # Original AdsDataMap.MapDataSet.ReadFromXml skips one byte, then uses
        # DeflateStream and reads a length-prefixed descriptor plus DataSet XML.
        import xml.etree.ElementTree as ET
        raw = zlib.decompress(data[1:], -15)
        length = struct.unpack_from("<I", raw)[0]
        descriptor = ET.fromstring(raw[4:4 + length])
        dataset = ET.fromstring(raw[4 + length:])
        set_result("Ads-XML-data-map", DIRECT, "按原版读取链成功解压并解析表描述和 DataSet XML；属于映射配置数据",
                   descriptor_root=descriptor.tag, descriptor_tables=len(descriptor.findall(".//Table")),
                   dataset_root=dataset.tag, dataset_rows=len(dataset), decoded_bytes=len(raw),
                   reader_evidence="AdsDataMap.MapDataSet.ReadFromXml")
    elif ext == ".data" and data.startswith(b"\xff\xfe" + "STREAM_STORAGE_SIGNATURE".encode("utf-16-le")) and "!/xl/model/" in path:
        set_result("spreadsheet-tabular-data-model", DIRECT, "Excel xl/model 中的表格数据模型流，具有标准存储标记和备份元数据",
                   remaining_scope="数据模型完整解码未验收")
    elif ext == ".idx" and "/Hyprotech/COMThermo/Databases/" in path:
        schema = b"PName" in data and b"CName" in data and b"MW" in data and b"Double" in data
        pairs = list(struct.iter_unpack("<II", data)) if len(data) % 8 == 0 else []
        unique_ids = bool(pairs) and all(item[0] > 0 for item in pairs) and len({item[0] for item in pairs}) == len(pairs)
        monotonic = unique_ids and pairs[0][1] == 0 and all(a[1] < b[1] for a, b in zip(pairs, pairs[1:]))
        if schema or monotonic:
            set_result("COMThermo-property-index", DIRECT, "物性数据库字段类型表，或唯一编号与严格递增偏移组成的索引（编号不要求连续）",
                       confidence="paired-database-role-verified", schema_fields=schema, offset_records=len(pairs) if monotonic else 0,
                       remaining_scope="未宣称全部索引字段已解码")
    elif data.startswith(b"TAPE") and "APED V15.0/" in path:
        set_result("SQL-Server-backup-candidate", DIRECT, "APED 数据库备份介质头；数据库备份身份另由 SQL HEADERONLY 只读核实",
                   confidence="backup-signature-and-role", remaining_scope="依赖 SQL 元数据核验，不把备份当可执行代码")
    elif ext == ".pb" and "meipreload/" in lower:
        fields = protobuf_fields(data)
        set_result("protobuf-media-preload", DIRECT, "WebView2 媒体预载资源，完整通过 Protobuf 线格式边界校验", protobuf_fields=fields)
    elif ext in {".psc", ".ptb"} and data.startswith(b"vr 8"):
        set_result("HYSYS-encoded-script-component", REVERSE, "vr 8 编码的脚本/项目组件；正文未解码，保留逆向候选",
                   confidence="format-family-only", remaining_scope="仍需核实编码内容与实际逻辑，不按后缀直接认定全部含代码")
    elif ext == ".pj" and data.startswith(b"Use File:") and "Help/" in path:
        set_result("help-authoring-project", DIRECT, "帮助文档的页面布局项目元数据")
    elif ext == ".sdb" and data.startswith(b"~\r\n"):
        set_result("HYSYS-localization-dictionary", DIRECT, "以键值和本地化提示组成的字符串字典；编码仍按语言分别处理")
    elif "/dat/lan/" in lower and ext in {".eng", ".chi", ".fre", ".ger", ".ita", ".spa", ".reng"}:
        set_result("EDR-language-resource-or-index", DIRECT, "EDR 语言目录中的消息正文或配套数值索引；样本包含资源标识、翻译文本或偏移表",
                   confidence="role-evidence", remaining_scope="语言编码和全部索引字段未完整解码")
    elif ext in {".si", ".us"} and "/dat/pda/" in lower and len(data) % 4 == 0:
        floats = struct.unpack("<" + "f" * (len(data) // 4), data)
        import math
        finite = sum(math.isfinite(v) for v in floats)
        if finite == len(floats):
            set_result("EDR-unit-table", DIRECT, "PDA 的 SI/US 成对数值表；长度与完整浮点数组一致",
                       confidence="role-and-numeric-layout", numeric_values=len(floats), remaining_scope="各列单位语义未完整验收")
    elif ext == ".thd" and data.startswith(b"\x01\0\0\0") and "/aspen energy analyzer " in "/" + lower:
        strings = re.findall(rb"[\x20-\x7e]{8,160}", data[:131072])
        if any(b"N = " in s or b"Thermodyn" in s or b"T/K" in s for s in strings):
            set_result("thermodynamic-observation-data", DIRECT, "热物性观测数据，含文献、温度/压力条件及数据点数量",
                       confidence="role-and-record-content", remaining_scope="完整记录布局尚未验收")
    elif ext == ".the" and data.startswith(b"\x01\0\0\0") and "/aspen energy analyzer " in "/" + lower:
        companion = Path(row["original_path"]).with_suffix(".thd")
        if companion.is_file():
            set_result("thermodynamic-data-index", DIRECT, "与同名 THD 配套的热物性数值/索引文件",
                       confidence="paired-dataset-role", remaining_scope="索引全部字段语义未确认")
    elif ext == ".pcl" and "/prp/" in lower and b"ALUMINUM" in data[:131072]:
        set_result("property-component-list", DIRECT, "固定宽度的化合物名称与物性数据表",
                   confidence="role-and-record-content", remaining_scope="全部物性字段未完整解码")
    elif ext == ".aprpdf" and ("/dat/props/" in lower or "/refsys/refreactor/" in lower):
        set_result("Aspen-property-data-packet", DIRECT, "物性计算数据包；样本位于物性数据目录并包含性质/单位/计算条件记录",
                   confidence="role-evidence", remaining_scope="尚未完整解码数据包，非 PDF 文档或可执行程序")
    elif ext == ".wrk" and "/workbooks/" in lower and data.startswith(b"\xff\xff\xff\xff") and b"MaterialStreamObject" in data:
        set_result("HYSYS-workbook-layout", DIRECT, "工作簿中的流股对象、属性列和显示布局数据",
                   confidence="role-and-record-content", remaining_scope="序列化字段尚未全部映射")
    elif ext == ".hcc" and "ecodatabase" in lower and b"DEFAULT" in data:
        set_result("economic-settings-database", DIRECT, "经济分析默认配置数据库",
                   confidence="role-and-record-content", remaining_scope="完整数据库格式未解析")
    elif ext == ".hud" and ("utildatabase" in lower or "processutilities" in lower) and b"Steam" in data:
        set_result("process-utility-database", DIRECT, "公用工程数据库，样本含蒸汽等公用工程记录",
                   confidence="role-and-record-content", remaining_scope="完整数据库格式未解析")
    elif ext == ".prf" and data.startswith(bytes.fromhex("7f22aa524516093f091259")) and b"AppExtensionFilePath" in data:
        set_result("application-preferences", DIRECT, "应用偏好设置：路径、名称和图标等配置项",
                   confidence="role-and-record-content", remaining_scope="配置序列化字段未全部映射")
    elif ext == ".aal" and Path(path).name == "AspenAssayLibrary.aal" and "/AspenAssayManagement/" in path:
        set_result("HYSYS-assay-database", DIRECT, "原版帮助明确 .aal 为 assay 数据库，保存原油评价数据；按数据库格式研究",
                   confidence="owner-documentation-and-role", owner_help="HYSYSAssayMgr/Content/html/dialogs/Create_Custom_Library_Dialog_Box.htm",
                   remaining_scope="该数据库内部编码未完整解码")
    elif ext == ".idx" and Path(path).name.casefold() == "tabular.idx" and data.startswith(struct.pack("<i", -10000)):
        values = [x[0] for x in struct.iter_unpack("<i", data[4:])]
        offsets = [v for v in values if v >= 0]
        if (offsets and all(v == -32767 or v >= 4 for v in values)
                and all(a < b for a, b in zip(offsets, offsets[1:])) and all((v - 4) % 1484 == 0 for v in offsets)):
            set_result("HYSYS-tabular-index", DIRECT, "表格配套索引：有效偏移按 1484 字节记录递增，空项为 -32767",
                       confidence="role-and-numeric-layout", index_offsets=len(offsets), empty_slots=values.count(-32767),
                       remaining_scope="索引语义未完整映射")
    return result


def protobuf_fields(data):
    def varint(pos):
        value = shift = 0
        while pos < len(data) and shift < 70:
            byte = data[pos]
            pos += 1
            value |= (byte & 127) << shift
            if byte < 128:
                return value, pos
            shift += 7
        raise ValueError("invalid protobuf varint")
    pos = count = 0
    while pos < len(data):
        tag, pos = varint(pos)
        if not tag >> 3:
            raise ValueError("protobuf zero field")
        wire = tag & 7
        if wire == 0:
            _, pos = varint(pos)
        elif wire in (1, 5):
            pos += 8 if wire == 1 else 4
        elif wire == 2:
            size, pos = varint(pos)
            pos += size
        else:
            raise ValueError("unsupported protobuf wire type")
        if pos > len(data):
            raise ValueError("protobuf field exceeds input")
        count += 1
    return count


def access_error(path):
    api = ctypes.WinDLL("kernel32", use_last_error=True)
    api.CreateFileW.argtypes = [ctypes.c_wchar_p, ctypes.c_uint32, ctypes.c_uint32, ctypes.c_void_p,
                               ctypes.c_uint32, ctypes.c_uint32, ctypes.c_void_p]
    api.CreateFileW.restype = ctypes.c_void_p
    api.CloseHandle.argtypes = [ctypes.c_void_p]
    handle = api.CreateFileW(str(path), 0x80000000, 7, None, 3, 0x80, None)
    if handle == ctypes.c_void_p(-1).value:
        return ctypes.get_last_error()
    api.CloseHandle(handle)
    return 0


def materialize(row, reader, output):
    key = identity(row)
    label = hashlib.sha256(key.encode("utf-8")).hexdigest()[:16]
    folder = output / "samples" / label
    folder.mkdir(parents=True)
    original_name = re.sub(r'[<>:"/\\|?*]', "_", row["relative_path"].split("/")[-1])
    result = dict(source_record=row, sample_directory=folder.relative_to(output).as_posix())
    try:
        data = reader.read(row)
        digest = hashlib.sha256(data).hexdigest()
        if row["sha256"] and digest != row["sha256"]:
            raise ValueError("current source SHA-256 differs from inventory; no classification applied")
        path = folder / original_name
        path.write_bytes(data)
        result.update(local_input=path.relative_to(output).as_posix(), sha256=digest, read_status="ok")
    except (OSError, ValueError, KeyError, zipfile.BadZipFile, subprocess.SubprocessError) as exc:
        result.update(read_status="unavailable", error=str(exc))
        if row["read_status"].startswith("error:"):
            result["windows_error"] = access_error(row["original_path"])
    return result


def write_csv(path, rows, fields):
    with path.open("w", encoding="utf-8-sig", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def finalize(rows, unresolved, results, output, inventory, sql_evidence=None):
    by_hash = {r["sha256"]: r for r in results if r["read_status"] == "ok"}
    sql = json.loads(sql_evidence.read_text(encoding="utf-8-sig")) if sql_evidence else {}
    catalog = {r["physical_name"].casefold(): r for r in sql.get("files", [])}
    backups = {r["file_name"].casefold(): r for r in sql.get("backups", [])}
    if sql:
        emit_json(output / "sql-metadata.json", sql)
    revised = []
    changes = []
    for original in rows:
        row = dict(original, previous_category=original["category"],
                   classification_status=original.get("classification_status") or "baseline",
                   classification_evidence=original.get("classification_evidence", ""),
                   classification_remaining=original.get("classification_remaining", ""))
        sample = by_hash.get(row["sha256"]) if row["sha256"] else None
        if sample:
            finding = sample["inspection"]
            row["classification_evidence"] = sample["sample_directory"] + "/inspection.json"
            proposed = finding.get("proposed_category")
            if proposed in (DIRECT, REVERSE):
                row.update(category=proposed, format=finding["format"], reason=finding["finding"],
                           classification_status=finding["confidence"], classification_remaining=finding.get("remaining_scope", ""))
                row["review"] = (finding.get("remaining_scope") or original["review"] or finding["finding"]) if finding["confidence"] in {"format-family-only", "unresolved"} else ""
            elif row["review"]:
                row["classification_status"] = "sampled-unresolved"
        elif row["review"]:
            row["classification_status"] = "not-sampled"
        if row["original_path"].casefold() in catalog and row["extension"] in {".mdf", ".ldf"}:
            item = catalog[row["original_path"].casefold()]
            row.update(category=DIRECT, format="SQL-Server-" + item["type_desc"], reason="SQL sys.master_files 确认数据库数据/日志文件",
                       review="", classification_status="SQL-catalog-confirmed", classification_evidence="sql-metadata.json",
                       classification_remaining="原始内容仍不可读，未生成内容 SHA-256")
        if row["extension"] == "(no extension)" and row["source"] == "installed-backup-5" and row["relative_path"].startswith("APED V15.0/"):
            item = backups.get(Path(row["original_path"]).name.casefold())
            if item and item["backup_type"] == 1:
                row.update(category=DIRECT, format="SQL-Server-database-backup", reason="SQL HEADERONLY 确认完整数据库备份；未执行恢复",
                           review="", classification_status="SQL-header-confirmed", classification_evidence="sql-metadata.json")
        if row["read_status"] == "encrypted-member-not-read":
            row["classification_status"] = "encrypted-content-unavailable"
            row["review"] = "仅列出加密成员的名称与大小；内容未读取，不能按后缀推定内部实现"
            row["classification_remaining"] = row["review"]
        if row["category"] != original["category"]:
            changes.append(row)
        revised.append(row)
    key = lambda r: (r["category"], r["extension"], int(r["priority"]), r["source"], r["relative_path"].casefold())
    revised.sort(key=key)
    fields = list(revised[0])
    for category in (REVERSE, DIRECT):
        folder = output / category
        folder.mkdir()
        write_csv(folder / "files.csv", [r for r in revised if r["category"] == category], fields)
        for name, priority in (("primary-files.csv", "1"), ("backup-files.csv", "2"), ("surrounding-media.csv", "3")):
            write_csv(folder / name, [r for r in revised if r["category"] == category and r["priority"] == priority], fields)
    write_csv(output / "category-changes.csv", sorted(changes, key=key), fields)
    write_csv(output / "remaining-review.csv", [r for r in revised if r["review"]], fields)
    matrix = []
    for item in results:
        row = item["source_record"]
        finding = item.get("inspection", {})
        matrix.append(dict(extension=row["extension"], source=row["source"], priority=row["priority"], file=row["relative_path"],
                           sha256=item.get("sha256", ""), sample_directory=item["sample_directory"], format=finding.get("format", "unavailable"),
                           proposed_category=finding.get("proposed_category"), confidence=finding.get("confidence", "unavailable"),
                           finding=finding.get("finding", item.get("error", ""))))
    write_csv(output / "sample-matrix.csv", matrix, list(matrix[0]))
    suffix_rows = []
    for ext in sorted({r["extension"] for r in unresolved}):
        selected = [r for r in matrix if r["extension"] == ext]
        original = [r for r in unresolved if r["extension"] == ext]
        suffix_rows.append(dict(extension=ext, original_uncertain_records=len(original), samples=len(selected),
                                reverse_samples=sum(r["proposed_category"] == REVERSE for r in selected),
                                direct_samples=sum(r["proposed_category"] == DIRECT for r in selected),
                                unavailable_or_unresolved=sum(r["proposed_category"] not in (DIRECT, REVERSE) for r in selected),
                                sample_formats="; ".join(sorted({r["format"] for r in selected}))))
    write_csv(output / "suffix-statistics.csv", suffix_rows, list(suffix_rows[0]))
    counts = collections.Counter((r["category"], r["extension"], r["source"]) for r in revised)
    statistics = [dict(category=c, extension=e, source=s, files=n) for (c,e,s),n in sorted(counts.items())]
    write_csv(output / "extension-statistics.csv", statistics, ["category", "extension", "source", "files"])
    primary_before = [r for r in unresolved if r["priority"] == "1"]
    primary_payload = [r for r in revised if r["source"] == "installer-payload"]
    primary_after = [r for r in revised if r["priority"] == "1" and r["review"]]
    summary = dict(baseline_inventory=str(inventory.resolve()), baseline_rows=len(rows), output_rows=len(revised),
                   suffix_groups=len(suffix_rows), samples=len(results), samples_readable=sum(r["read_status"] == "ok" for r in results),
                   primary_uncertain_before=len(primary_before), primary_uncertain_after=len(primary_after),
                   categories_before=dict(collections.Counter(r["category"] for r in rows)),
                   categories_after=dict(collections.Counter(r["category"] for r in revised)), category_moves=len(changes),
                   primary_payload_categories=dict(collections.Counter(r["category"] for r in primary_payload)),
                   primary_payload_uncertain_after=sum(bool(r["review"]) for r in primary_payload),
                   primary_moves=sum(r["priority"] == "1" for r in changes),
                   primary_lib_categories=dict(collections.Counter(r["category"] for r in primary_payload if r["extension"] == ".lib")),
                   primary_dll_categories=dict(collections.Counter(r["category"] for r in primary_payload if r["extension"] == ".dll" and r["classification_status"] != "baseline")),
                   review_after=sum(bool(r["review"]) for r in revised), encrypted_members=sum(r["read_status"] == "encrypted-member-not-read" for r in revised),
                   metadata_confirmed_sql_files=sum(r["classification_status"] == "SQL-catalog-confirmed" for r in revised),
                   metadata_confirmed_sql_backups=sum(r["classification_status"] == "SQL-header-confirmed" for r in revised),
                   unresolved_suffix_samples=[r for r in suffix_rows if r["unavailable_or_unresolved"]],
                   policy="Only inspected content hashes or explicit SQL metadata update file classifications. Never extrapolate from suffix alone.",
                   limits=["同后缀不同哈希的未抽样文件保留原状态；抽样结论不等于全后缀验收。",
                           "分类验收只回答处理路线；不表示已完成反编译、模型解密、完整格式解码、编译或行为验证。",
                           "加密 ZIP 成员只枚举元数据，分类保持候选与读取限制。",
                           "数据库分类由系统目录及只读 HEADERONLY 核验；原始 MDF/LDF 内容和哈希仍不可读。"])
    assert summary["output_rows"] == summary["baseline_rows"]
    assert set(r["extension"] for r in matrix) >= set(r["extension"] for r in unresolved)
    emit_json(output / "summary.json", summary)
    lines = ["# Aspen 待核实后缀抽样与分类复核", "", "首选来源仍为原版安装包；备选文件只用于缺项与不同格式补样。原清单未覆盖。", "",
             f"- 原清单 {len(rows):,} 条；涉及 {len(suffix_rows)} 种待核实后缀，选取 {len(results)} 个不同内容/受限样本。",
             f"- 首选来源原有 {len(primary_before)} 条待核实，复核后仍有 {len(primary_after)} 条分类未定。",
             f"- 主 CAB 载荷共 {len(primary_payload):,} 个：需要逆向 {summary['primary_payload_categories'].get(REVERSE,0):,}，不需要逆向 {summary['primary_payload_categories'].get(DIRECT,0):,}。",
             f"- 本轮调整 {len(changes):,} 条分类，其中首选来源 {summary['primary_moves']:,} 条；所有调整保留原分类与证据链接。", "",
             "## 首选重点结论", "", "| 后缀/内容 | 处理分类 | 依据 |", "| --- | --- | --- |",
             f"| .lib | {summary['primary_lib_categories'].get(DIRECT,0)} 个导入库不需逆向；{summary['primary_lib_categories'].get(REVERSE,0)} 个实现库需逆向 | 对主来源全部库成员进行结构检查 |",
             "| .dll | 含方法/机器代码的程序需逆向；方法数为零的卫星资源不需逆向 | 读取完整 PE/CLR 元数据，另识别 NE 旧程序 |",
             "| .acml | 需要逆向/解析模型语言 | OLE 模型结构与原版帮助对加密模型语言的说明 |",
             "| .apm / .apr / .apvar | 不需程序反编译；按模型模板、资源与变量元数据解析 | 内部配置、图标、模板和变量表 |",
             "| Ads.Converters | 不需程序反编译；按映射配置读取 | 原版读取链及实际 Deflate/XML 解析均通过 |",
             "| .xlsm / .xla | 有 VBA/嵌入程序的文件需单列程序部分；无宏的工作簿不需逆向 | 核对压缩包关系与 VBA 存储 |",
             "| .obj | 需要逆向 | 实际 COFF 对象与代码区段 |",
             "| .izp / .szp | 不需程序反编译；按经济评价压缩数据包读取 | 逐成员长度、zlib 校验与嵌入程序头检查 |",
             "| MSI 中无常规后缀的图片 | 不需要逆向 | 图像解码器完整读取 BMP/JPEG |", "",
             "## 全后缀样本结论", "", "| 后缀 | 原待核实记录 | 样本 | 需逆向样本 | 不需逆向样本 | 未定/不可读 |", "| --- | ---: | ---: | ---: | ---: | ---: |"]
    for r in suffix_rows:
        lines.append(f"| `{r['extension']}` | {r['original_uncertain_records']} | {r['samples']} | {r['reverse_samples']} | {r['direct_samples']} | {r['unavailable_or_unresolved']} |")
    lines += ["", "## 文件与边界", "",
              "- 两大类目录下的 files.csv 是完整新清单；primary-files.csv、backup-files.csv、surrounding-media.csv 分别供首选、备选和周边介质使用。各类内部按后缀名排序。",
              "- sample-matrix.csv 为逐样本判定；samples/*/inspection.json 和同名说明保留每个样本的来源、SHA-256、结构检查与缺口。",
              "- category-changes.csv 记录分类变化；remaining-review.csv 保留未判明和加密条目。",
              "- 主来源分类核实使用全部原待核实内容哈希；其他来源按后缀取不同内容样本。同哈希来源引用同一证据，不按后缀批量改未检查文件。"]
    lines += ["- " + s for s in summary["limits"]]
    (output / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--sevenzip", required=True, type=Path)
    parser.add_argument("--olefile-module-dir", required=True, type=Path)
    parser.add_argument("--sample-evidence", type=Path, help="reuse SHA-verified samples from an earlier new-path audit")
    parser.add_argument("--sql-evidence", type=Path, help="read-only sys.master_files and HEADERONLY evidence")
    args = parser.parse_args()
    if args.output.exists():
        parser.error("output must be a new path")
    args.output.mkdir(parents=True)
    sys.path.insert(0, str(args.olefile_module_dir.resolve()))
    import olefile
    rows = load_rows(args.inventory)
    unresolved, samples = choose_samples(rows)
    emit_json(args.output / "scope.json", dict(inventory=str(args.inventory.resolve()),
              time_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), unresolved_records=len(unresolved),
              extensions=sorted({r["extension"] for r in unresolved}), samples=len(samples),
              rule="all unresolved primary hashes + up to three distinct representatives per suffix; no suffix-only bulk reclassification"))
    reader = SourceReader(args.sevenzip)
    materialized = []
    # Prime the MSI stream cache sequentially before independent archive reads.
    if not args.sample_evidence:
        for row in samples:
            if row["source"] == "installer-msi-stream":
                reader.read(row)
                break
    print(f"Selected {len(samples)} distinct samples covering {len({r['extension'] for r in unresolved})} suffix groups", flush=True)
    if args.sample_evidence:
        materialized = json.loads((args.sample_evidence / "inspections.json").read_text(encoding="utf-8"))
        expected = {identity(row) for row in samples}
        if {identity(item["source_record"]) for item in materialized} != expected:
            raise ValueError("cached sample selection differs from the current inventory scope")
        for item in materialized:
            item.pop("inspection", None)
            if item["read_status"] == "ok":
                item["local_input"] = str((args.sample_evidence / item["local_input"]).resolve())
            (args.output / item["sample_directory"]).mkdir(parents=True)
    else:
        with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
            for index, item in enumerate(pool.map(lambda row: materialize(row, reader, args.output), samples), 1):
                materialized.append(item)
                if index % 50 == 0:
                    print(f"Read and SHA-256 verified {index}/{len(samples)} samples", flush=True)
    results = []
    sql = json.loads(args.sql_evidence.read_text(encoding="utf-8-sig")) if args.sql_evidence else {}
    catalog = {r["physical_name"].casefold(): r for r in sql.get("files", [])}
    for index, item in enumerate(materialized, 1):
        if item["read_status"] == "ok":
            path = args.output / item["local_input"]
            try:
                data = path.read_bytes()
                if hashlib.sha256(data).hexdigest() != item["sha256"]:
                    raise ValueError("cached input SHA-256 mismatch")
                item["inspection"] = refine_inspection(data, item["source_record"], inspect(data, path.name, olefile))
            except Exception as exc:
                item["inspection"] = dict(format="inspection-failed", confidence="unresolved", proposed_category=None, error=str(exc))
        elif item["source_record"]["original_path"].casefold() in catalog:
            record = catalog[item["source_record"]["original_path"].casefold()]
            item["inspection"] = dict(format="SQL-Server-" + record["type_desc"], confidence="SQL-catalog-confirmed",
                                      proposed_category=DIRECT, finding="系统目录确认数据库数据/日志文件；原始内容仍不可读",
                                      metadata_evidence="sql-metadata.json", raw_content_unavailable=True)
        folder = args.output / item["sample_directory"]
        emit_json(folder / "inspection.json", item)
        (folder / "inspection.md").write_text("# 单文件结构核验\n\n原来源：`" + item["source_record"]["relative_path"] + "`\n\n"
              "本轮只验证哈希、文件格式和处理分类，不构成完整反编译或编译验收。\n\n"
              "详细结构、判定与剩余项见同目录 inspection.json；原输入仅本地保存。\n", encoding="utf-8")
        results.append(item)
        if index % 50 == 0:
            print(f"Inspected {index}/{len(materialized)} samples", flush=True)
    emit_json(args.output / "inspections.json", results)
    summary = finalize(rows, unresolved, results, args.output, args.inventory, args.sql_evidence)
    print(json.dumps({k: summary[k] for k in ("samples", "suffix_groups", "primary_uncertain_before", "primary_uncertain_after", "primary_payload_categories", "category_moves")},ensure_ascii=False), flush=True)


if __name__ == "__main__":
    main()
