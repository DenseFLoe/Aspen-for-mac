"""Confirm every pending Properties content hash using structures and reader roles.

Writes new local evidence and five lists, preserving all source identities and
the frozen Plus baseline. Classification is separate from decompilation and
content access. No original executable or document is run.
"""

import argparse
import collections
import csv
import ctypes
import hashlib
import io
import json
import os
from pathlib import Path, PurePosixPath
import posixpath
import re
import struct
import subprocess
import sys
import uuid
import xml.etree.ElementTree as ET
import zipfile

from audit_aspen_suffixes import SourceReader, decode_text
from inventory_aspen_sources import DIRECT, REVERSE, emit_json
from organize_properties_classification import PENDING, fingerprint, write_csv


def digest(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


class Sources(SourceReader):
    def __init__(self, sevenzip):
        super().__init__(sevenzip)
        self.zips = {}
        self.contexts = {}

    def archive(self, row):
        container = row['container']
        if container not in self.zips:
            cab, sep, member = container.partition('!/')
            data = self.cabinet(cab, member) if sep else Path(container).read_bytes()
            self.zips[container] = zipfile.ZipFile(io.BytesIO(data))
        return self.zips[container]

    def read(self, row):
        if row['source'].endswith(':zip-member'):
            return self.archive(row).read(row['member'])
        return super().read(row)

    def context(self, row):
        """Resolve each binary part through the workbook's actual XML relationships."""
        key = (row['container'], row['member'])
        if key in self.contexts:
            return self.contexts[key]
        z = self.archive(row)
        member = row['member']
        require(digest(z.read(member)) == row['sha256'], 'package member changed since inventory')
        types = ET.fromstring(z.read('[Content_Types].xml'))
        defaults = {e.get('Extension'): e.get('ContentType') for e in types if e.tag.endswith('Default')}
        overrides = {e.get('PartName').lstrip('/'): e.get('ContentType') for e in types if e.tag.endswith('Override')}
        content_type = overrides.get(member, defaults.get(PurePosixPath(member).suffix.lstrip('.')))
        relations = []
        for name in z.namelist():
            if not name.endswith('.rels'):
                continue
            root = ET.fromstring(z.read(name))
            parent, filename = posixpath.split(name)
            base = posixpath.dirname(parent) if parent.endswith('_rels') else ''
            for e in root:
                if e.get('TargetMode') == 'External':
                    continue
                target = e.get('Target', '')
                resolved = posixpath.normpath(posixpath.join(base, target)).lstrip('/')
                if resolved == member:
                    relations.append(dict(part=name, type=e.get('Type'), id=e.get('Id')))
        require(relations, 'binary part is not referenced by any internal relationship')
        result = dict(container=row['container'], member=member, content_type=content_type, relationships=relations)
        if '/activeX/' in member:
            controls = []
            for relation in relations:
                if not relation['type'].endswith('/activeXControlBinary'):
                    continue
                # XML and BIN numeric suffixes can differ. Follow the relationship,
                # never infer a binding from a matching basename.
                parent, filename = posixpath.split(relation['part'])
                xml_name = posixpath.join(posixpath.dirname(parent), filename[:-5])
                raw = z.read(xml_name)
                root = ET.fromstring(raw)
                attrs = {k.rsplit('}', 1)[-1]: v for k, v in root.attrib.items()}
                require(attrs.get('id') == relation['id'], 'control XML relationship ID mismatch')
                controls.append(dict(part=xml_name, sha256=digest(raw), attributes=attrs))
            require(controls, 'no ActiveX control XML references this binary')
            result['controls'] = controls
        self.contexts[key] = result
        return result


def svg(data):
    root = ET.fromstring(data)
    require(root.tag == '{http://www.w3.org/2000/svg}svg', 'not an SVG root')
    tags = collections.Counter(e.tag.rsplit('}', 1)[-1] for e in root.iter())
    require(set(tags) <= {'svg', 'defs', 'g', 'path', 'use', 'rect'}, 'unexpected active or unreviewed SVG element')
    ids = {e.get('id') for e in root.iter() if e.get('id')}
    references = []
    for e in root.iter():
        for key, value in e.attrib.items():
            key = key.rsplit('}', 1)[-1]
            require(not key.lower().startswith('on'), 'SVG event-handler source requires separate review')
            if key == 'href':
                require(value.startswith('#') and value[1:] in ids, 'unresolved or external SVG reference')
                references.append(value)
    return dict(format='SVG-equation-image', category=DIRECT, basis='完整 XML、绘图节点和全部内部图形引用核验；无脚本或外部对象',
                tags=dict(tags), internal_references=len(references), remaining='公式图像，不等于公式转录或数值计算已验收')


def emf(data):
    require(len(data) >= 88 and data[40:44] == b' EMF', 'invalid EMF header')
    declared, count = struct.unpack_from('<II', data, 48)
    require(declared == len(data), 'EMF declared size mismatch')
    pos, kinds = 0, []
    while pos < len(data):
        kind, size = struct.unpack_from('<II', data, pos)
        require(size >= 8 and size % 4 == 0 and pos + size <= len(data), 'invalid EMF record boundary')
        kinds.append(kind)
        pos += size
    require(kinds[0] == 1 and kinds[-1] == 14 and len(kinds) == count, 'EMF header/EOF/record count mismatch')
    return dict(format='EMF-vector-image', category=DIRECT, basis='全部 EMR 记录边界、文件长度、记录数与 EOF 一致',
                records=count, record_types=dict(collections.Counter(kinds)), remaining='绘制效果与图片语义未作运行验收')


def biff_sheets(data):
    pos, records, sheets = 0, 0, []
    while pos + 4 <= len(data):
        kind, size = struct.unpack_from('<HH', data, pos)
        if kind == 0 and size == 0 and not any(data[pos:]):
            break
        require(pos + 4 + size <= len(data), 'truncated BIFF record')
        if kind == 0x85:
            require(size >= 6, 'invalid BOUNDSHEET record')
            sheets.append(data[pos + 9])
        records += 1
        pos += size + 4
    require(records and pos <= len(data), 'missing BIFF records')
    return dict(records=records, sheet_types=sheets, macro_sheets=sheets.count(1), vb_module_sheets=sheets.count(6))


def office(data, row):
    import olefile
    from oletools.olevba import VBA_Parser
    with olefile.OleFileIO(io.BytesIO(data), raise_defects=olefile.DEFECT_INCORRECT) as ole:
        names = ole.listdir()
        streams = ['/'.join(p) for p in names]
        for name in names:
            require(len(ole.openstream(name).read()) == ole.get_size(name), 'truncated OLE stream')
        workbook = next((n for n in ('Workbook', 'Book') if ole.exists(n)), None)
        biff = biff_sheets(ole.openstream(workbook).read()) if workbook else None
        if row['extension'] == '.doc':
            fib = ole.openstream('WordDocument').read(32)
            require(struct.unpack_from('<H', fib)[0] == 0xa5ec, 'invalid Word FIB')
            require(struct.unpack_from('<H', fib, 2)[0] >= 0xc1, 'legacy WordBasic requires further review')
            require(not struct.unpack_from('<H', fib, 10)[0] & 0x8100, 'encrypted Word document')
        if row['extension'] == '.ppt':
            require(ole.exists('PowerPoint Document') and ole.exists('Current User'), 'missing PPT streams')
        unexpected = [n for n in streams if n.split('/')[-1].lower() in ('package', '\x01ole10native')]
        require(not unexpected, 'embedded package requires separate content review')
    parser = VBA_Parser(row['relative_path'], data=data)
    try:
        has_vba = parser.detect_vba_macros()
        has_xlm = parser.detect_xlm_macros()
        modules = []
        if has_vba:
            for _, member, name, code in parser.extract_macros():
                if member == 'xlm_macro':
                    continue  # oletools may append a BIFF report even when detect_xlm_macros is false.
                modules.append(dict(member=member, filename=name, code=code))
        require(not has_vba or modules, 'VBA present but source extraction produced no modules')
        code_present = has_vba or has_xlm or bool(biff and (biff['macro_sheets'] or biff['vb_module_sheets']))
        return dict(format='OLE-Office-with-code' if code_present else 'OLE-Office-document', category=REVERSE if code_present else DIRECT,
                    basis='完整 OLE 流、VBA 项目和宏检测；Excel 另逐条检查 BIFF 与 BOUNDSHEET 类型',
                    streams=streams, biff=biff, vba=has_vba, xlm=has_xlm,
                    modules=modules, remaining='VBA 源文本已取得；p-code 一致性、窗体二进制、依赖和行为尚未验收' if code_present
                    else '文档/公式/外部加载项引用按可读资源处理；不据此确认 Excel 计算行为')
    finally:
        parser.close()


def binary_part(data, matches, reader):
    contexts = [reader.context(r) for r in matches]
    types = {c['content_type'] for c in contexts}
    require(len(types) == 1, 'same binary content has conflicting package roles')
    content_type = next(iter(types)) or ''
    detail = {}
    if content_type.endswith('printerSettings'):
        require(len(data) >= 72, 'short DEVMODE')
        size, extra = struct.unpack_from('<HH', data, 68)
        require(size >= 72 and size + extra == len(data), 'DEVMODE length mismatch')
        require(all(any(x['type'].endswith('/printerSettings') for x in c['relationships']) for c in contexts), 'printer relationship mismatch')
        kind = 'Excel-DEVMODE-printer-settings'
        detail = dict(dmSize=size, dmDriverExtra=extra, device_name=data[:64].decode('utf-16-le').rstrip('\0'))
    elif content_type == 'application/vnd.ms-office.activeX':
        require(len(data) >= 24, 'short Forms persistence stream')
        guid = str(uuid.UUID(bytes_le=data[:16]))
        known = {'8bd21d30-ec42-11ce-9e0d-00aa006002f3', 'd7053240-ce69-11cd-a777-00dd01143c57',
                 '8bd21d50-ec42-11ce-9e0d-00aa006002f3', '978c9e23-d4b0-11ce-bf2d-00aa003f40d0',
                 '8bd21d10-ec42-11ce-9e0d-00aa006002f3', '4c599241-6926-101b-9992-00000b65c6f9',
                 '8bd21d40-ec42-11ce-9e0d-00aa006002f3'}
        require(guid in known and data[16:18] == b'\x00\x02', 'unknown control persistence format')
        block = struct.unpack_from('<H', data, 18)[0]
        require(20 + block <= len(data), 'Forms property block exceeds stream')
        for c in contexts:
            for control in c['controls']:
                require(control['attributes']['classid'].strip('{}').lower() == guid, 'control XML CLSID mismatch')
                require(control['attributes'].get('persistence') == 'persistStreamInit', 'unknown ActiveX persistence mechanism')
            require(any(x['type'].endswith('/activeXControlBinary') for x in c['relationships']), 'ActiveX relationship mismatch')
        kind = 'MSForms-control-persisted-properties'
        detail = dict(clsid=guid, property_block_bytes=block)
    elif 'vbaProjectSignature' in content_type:
        from cryptography.hazmat.primitives.serialization.pkcs7 import load_der_pkcs7_certificates
        require(len(data) >= 36, 'short signature record')
        size, offset, cert_size, cert_offset = struct.unpack_from('<4I', data)
        # DigSig offsets include the outer eight-byte blob header, absent in this ZIP part.
        start = offset - 8
        require(start >= 36 and start + size <= len(data), 'signature bounds mismatch')
        require(cert_offset - 8 >= start + size and cert_offset - 8 + cert_size <= len(data), 'certificate store bounds mismatch')
        certs = load_der_pkcs7_certificates(data[start:start + size])
        require(certs, 'PKCS#7 record has no certificates')
        require(all(any('vbaProjectSignature' in x['type'] for x in c['relationships']) for c in contexts), 'signature relationship mismatch')
        kind = 'VBA-digital-signature-record'
        detail = dict(signature_bytes=size, certificate_store_bytes=cert_size, certificates=len(certs),
                      signature_authenticity='not verified; parsing establishes data format only')
    else:
        raise ValueError('unreviewed binary package role: ' + content_type)
    return dict(format=kind, category=DIRECT, basis='逐来源核对 Content_Types、关系目标与实际二进制结构；未将 VBA 程序流并入数据',
                contexts=contexts, **detail, remaining='控件状态/打印配置/签名数据；外部控件实现和 VBA 程序分别处理，全部字段语义未验收')


def shortcut(data):
    require(len(data) >= 80 and struct.unpack_from('<I', data)[0] == 76
            and data[4:20] == uuid.UUID('00021401-0000-0000-c000-000000000046').bytes_le, 'invalid Shell Link header')
    flags = struct.unpack_from('<I', data, 20)[0]
    pos = 76
    if flags & 1:
        length = struct.unpack_from('<H', data, pos)[0]
        pos += length + 2
    target = None
    if flags & 2:
        size, header, info_flags, volume, local, network, suffix = struct.unpack_from('<7I', data, pos)
        require(size >= 28 and pos + size <= len(data), 'invalid LinkInfo bounds')
        if local:
            require(local < size, 'invalid local path offset')
            target = data[pos + local:pos + size].split(b'\0', 1)[0].decode('cp1252')
        pos += size
    values = {}
    for bit, label in ((4, 'name'), (8, 'relative_path'), (16, 'working_directory'), (32, 'arguments'), (64, 'icon')):
        if flags & bit:
            chars = struct.unpack_from('<H', data, pos)[0]
            pos += 2
            size = chars * (2 if flags & 128 else 1)
            require(pos + size <= len(data), 'truncated Shell Link StringData')
            values[label] = data[pos:pos + size].decode('utf-16-le' if flags & 128 else 'cp1252')
            pos += size
    blocks = 0
    while pos + 4 <= len(data):
        size = struct.unpack_from('<I', data, pos)[0]
        if not size:
            pos += 4
            break
        require(size >= 8 and pos + size <= len(data), 'invalid Shell Link ExtraData block')
        blocks += 1
        pos += size
    require(pos == len(data), 'Shell Link trailing data')
    return dict(format='Windows-Shell-Link', category=DIRECT, basis='Shell Link 头、LinkInfo、字符串及 ExtraData 块边界全部核验；未打开目标',
                target=target, strings=values, extra_blocks=blocks, remaining='快捷方式路径资源；未执行或迁移链接目标')


def typelib(path):
    require(os.name == 'nt', 'type-library API validation requires Windows')
    oleaut = ctypes.WinDLL('oleaut32')
    pointer = ctypes.c_void_p()
    oleaut.LoadTypeLibEx.argtypes = [ctypes.c_wchar_p, ctypes.c_int, ctypes.POINTER(ctypes.c_void_p)]
    oleaut.LoadTypeLibEx.restype = ctypes.c_long
    require(oleaut.LoadTypeLibEx(str(path.resolve()), 2, ctypes.byref(pointer)) == 0, 'LoadTypeLibEx(REGKIND_NONE) failed')
    table = ctypes.cast(pointer, ctypes.POINTER(ctypes.POINTER(ctypes.c_void_p))).contents
    release = ctypes.WINFUNCTYPE(ctypes.c_ulong, ctypes.c_void_p)(table[2])
    try:
        count = ctypes.WINFUNCTYPE(ctypes.c_uint, ctypes.c_void_p)(table[3])(pointer)
        getkind = ctypes.WINFUNCTYPE(ctypes.c_long, ctypes.c_void_p, ctypes.c_uint, ctypes.POINTER(ctypes.c_int))(table[5])
        kinds = []
        for i in range(count):
            kind = ctypes.c_int()
            require(getkind(pointer, i, ctypes.byref(kind)) == 0 and 0 <= kind.value <= 7, 'unreadable type-info metadata')
            kinds.append(kind.value)
        return dict(format='COM-type-library', category=DIRECT, basis='Windows LoadTypeLibEx(REGKIND_NONE) 及每个 TypeInfo 类型查询成功；无注册、无对象实例化',
                    type_info_count=count, type_kinds=kinds, remaining='接口元数据；方法实现位于另列程序文件')
    finally:
        release(pointer)


def inspect(data, path, row, matches, reader, reader_evidence):
    ext = row['extension']
    if ext == '.svg':
        return svg(data)
    if ext == '.emf':
        return emf(data)
    if ext in ('.xls', '.doc', '.ppt'):
        return office(data, row)
    if ext == '.bin':
        return binary_part(data, matches, reader)
    if ext == '.lnk':
        return shortcut(data)
    if ext == '.tlb':
        return typelib(path)
    if ext in ('.dat', '.aprbkp'):
        text, encoding = decode_text(data)
        require(text is not None and '\0' not in text, 'not a complete readable text file')
        if ext == '.aprbkp':
            require(text.startswith('MM "') and 'VERSION ' in text and 'MACHINE ' in text, 'missing Aspen backup record structure')
        else:
            require((path.name == 'pgDatabases.dat' and set(text.split()) == {'APESV150', 'APV150', 'FACTV150', 'NISTV150'})
                    or (path.name == 'propunits.dat' and 'PROPERTIES-UNITS-TYPES FOLLOW' in text)
                    or (path.name == 'units.dat' and 'CONVERSION' in text.upper()), 'text role not established')
        return dict(format='Aspen-text-property-package' if ext == '.aprbkp' else 'Aspen-text-configuration-table', category=DIRECT,
                    basis='完整正文解码及 MM/版本/机器记录或具体数据库/单位表内容核验；可读内容直接解析',
                    encoding=encoding, lines=len(text.splitlines()),
                    readable_code_markers={s: len(re.findall(s, text, re.I)) for s in ('FORTRAN', 'CALCULATOR', 'SUBROUTINE')},
                    remaining='备份/单位表完整字段语义未验收；可读计算表达式须保留为源文本，不等于模型逻辑已恢复')
    if ext in ('.hms', '.aprsdf'):
        evidence = reader_evidence[path.name]
        require(digest(Path(evidence['path']).read_bytes()) == evidence['sha256'], 'reader changed since static evidence was captured')
        require(evidence['functions'] and evidence['literal'].endswith(path.name), 'missing original reader evidence')
        if ext == '.hms':
            values = struct.unpack_from('<6I', data)
            require(values[0] > 0 and 0 < values[2] < len(data) and 0 < values[4] < len(data), 'invalid help storage bounds')
            fields = dict(header_u32=list(values))
        else:
            values = struct.unpack_from('<4Q', data)
            require(32 <= values[0] < len(data) and values[2] == len(data) - 32 and values[3] == 32, 'invalid SDF storage bounds')
            fields = dict(header_u64=list(values))
        return dict(format='Aspen-help-message-storage' if ext == '.hms' else 'Aspen-SDF-engine-data', category=DIRECT,
                    basis='实际文件头边界加原版读取链：' + evidence['expected_import'], reader_evidence=evidence,
                    confidence='original-reader-role-verified', **fields,
                    remaining='只确认按帮助资源/数据存储解析；内部压缩、索引、字段与全部数值尚未完整解码')
    if ext == '.pdf':
        from pypdf import PdfReader
        pdf = PdfReader(io.BytesIO(data), strict=True)
        pages = len(pdf.pages)
        chars = sum(len(p.extract_text() or '') for p in pdf.pages)
        attachments = list(pdf.attachments)
        require(not attachments, 'PDF attachments require separate review')
        actions = []
        object_ids = {(ident, generation) for generation, ids in pdf.xref.items() for ident in ids if ident}
        object_ids.update((ident, 0) for ident in pdf.xref_objStm)
        for ident, generation in object_ids:
            obj = pdf.get_object(__import__('pypdf').generic.IndirectObject(ident, generation, pdf))
            if isinstance(obj, dict) and any(k in obj for k in ('/JS', '/JavaScript', '/Launch', '/EmbeddedFile', '/RichMedia')):
                actions.append(ident)
        require(not actions, 'active PDF object requires separate review')
        return dict(format='PDF-document', category=DIRECT, basis='PDF 交叉引用、全部页面文本和对象字典核验；无附件或活动代码对象',
                    pages=pages, extracted_text_characters=chars, remaining='本文档仅做内容格式核验，未作为排版交付验收')
    if ext == '.chm':
        command = [str(reader.sevenzip), 't', str(path)]
        test = subprocess.run(command, capture_output=True, timeout=120)
        require(test.returncode == 0, 'CHM full decompression test failed')
        listing = subprocess.run([str(reader.sevenzip), 'l', '-slt', str(path)], capture_output=True, timeout=120, check=True).stdout.decode('utf-8', 'replace')
        names = re.findall(r'^Path = (.+)$', listing.split('----------', 1)[1], re.M)
        code = [n for n in names if PurePosixPath(n).suffix.lower() in ('.exe', '.dll', '.ocx', '.class', '.vbe', '.pyc')]
        require(not code, 'compiled CHM payload requires separate review')
        return dict(format='CHM-help-container', category=DIRECT, basis='7-Zip 全部 LZX 内容测试通过并逐成员枚举；帮助页面、图像和可读脚本按资源解析',
                    members=names, test_output=test.stdout.decode('utf-8', 'replace'), remaining='可读帮助脚本不需反编译；未将帮助内容等同于应用运行逻辑')
    raise ValueError('no content-specific validator for ' + ext)


def load_inventory(root):
    rows = []
    for category in (REVERSE, DIRECT, PENDING):
        with (root / category / 'files.csv').open(encoding='utf-8-sig', newline='') as stream:
            rows.extend(csv.DictReader(stream))
    return rows


def archive_modules(output, row, result):
    modules = result.pop('modules', [])
    exported = []
    for i, module in enumerate(modules, 1):
        relative = row['relative_path'] + f'.{i:02}' + Path(module['filename']).suffix
        path = output / '02-incomplete' / relative
        # Extended-length paths preserve original installer-relative directories on Windows.
        io_path = Path('\\\\?\\' + str(path.resolve())) if os.name == 'nt' else path
        io_path.parent.mkdir(parents=True, exist_ok=True)
        io_path.write_text(module['code'], encoding='utf-8', newline='')
        note = io_path.with_suffix('.md')
        note.write_text('\n'.join([
            '# 原版 VBA 部分恢复（未完成）', '',
            '原文件：`' + row['relative_path'] + '`', '',
            '原始内容 SHA-256：`' + row['sha256'] + '`；版本：' + (row['version'] or '原文件未提供独立版本') + '。', '',
            '来源容器：`' + row['container'] + '`；成员：`' + row['member'] + '`。', '',
            '内部模块：`' + module['member'] + '`；原模块名：`' + module['filename'] + '`。', '',
            '范围/验收：oletools 从原版 OLE/VBA 项目解压得到此源文本，源文件完整哈希已核对。此为代码存在及可恢复证据，未通过完整反编译验收。', '',
            '剩余缺口：p-code 与源文本一致性、窗体资源、引用/外部依赖和运行行为尚未验收。下一步逐项目恢复并对照原版验证；本轮未编译。', ''
        ]), encoding='utf-8')
        exported.append(dict(member=module['member'], filename=module['filename'], category=REVERSE,
                             source_sha256=row['sha256'], source_record_id=row['record_id'], path=path.relative_to(output).as_posix(),
                             sha256=digest(io_path.read_bytes()), note=path.with_suffix('.md').relative_to(output).as_posix(),
                             acceptance='incomplete'))
    result['code_members'] = exported
    return exported


def archive_readers(output, evidence):
    """Partial native disassembly also follows original-name/incomplete/note rules."""
    results = []
    for entry in evidence.values():
        row = min(entry['ownership_sources'], key=lambda r: (int(r['priority']), r['relative_path']))
        for number, function in enumerate(entry['functions'], 1):
            path = output / '02-incomplete' / (row['relative_path'] + f'.{number:02}.asm')
            local = Path('\\\\?\\' + str(path.resolve())) if os.name == 'nt' else path
            local.parent.mkdir(parents=True, exist_ok=True)
            local.write_text('\n'.join(function['disassembly']) + '\n', encoding='utf-8')
            local.with_suffix('.md').write_text('\n'.join([
                '# 原版读取函数局部反汇编（未完成）', '',
                '原文件：`' + row['relative_path'] + '`；实际读取来源：`' + entry['path'] + '`。', '',
                '原文件版本：' + (row['version'] or '未提供独立版本') + '；SHA-256：`' + entry['sha256'] + '`。', '',
                '范围：PE 异常表中的函数 RVA `' + function['begin_rva'] + '` 至 `' + function['end_rva'] + '`（不含结束地址）。', '',
                '验收依据：Capstone 静态反汇编、实际字符串引用及导入解析，确认读取调用 `' + entry['expected_import'] + '`。', '',
                '状态：局部证据，未完成原 DLL 全部反编译；未编译或执行。剩余缺口：完整函数覆盖、控制/数据流恢复、依赖和行为对照。下一步逐 DLL 恢复并分别验收。', ''
            ]), encoding='utf-8')
            results.append(dict(path=path.relative_to(output).as_posix(), note=path.with_suffix('.md').relative_to(output).as_posix(),
                                sha256=digest(local.read_bytes()), source_sha256=entry['sha256'], source_record_id=row['record_id'],
                                acceptance='incomplete', category=REVERSE))
    emit_json(output / 'reader-code-evidence.json', results)
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('inventory', 'plus-baseline', 'output', 'sevenzip', 'module-dir', 'pdf-module-dir', 'sql-evidence', 'reader-evidence'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    require(not args.output.exists(), 'output must be new; historical evidence is immutable')
    require('.local' in args.output.resolve().parts, 'original inputs and recovered code must stay in a local-only path')
    sys.path[:0] = [str(args.module_dir.resolve()), str(args.pdf_module_dir.resolve())]
    rows = load_inventory(args.inventory)
    require(all('Properties' in r['owner'].split(';') for r in rows), 'Properties-only inventory required')
    tracked_inputs = [args.inventory / c / 'files.csv' for c in (REVERSE, DIRECT, PENDING)]
    tracked_inputs += [args.plus_baseline / c / name for c in (REVERSE, DIRECT) for name in ('files.csv', 'primary-files.csv')]
    tracked_inputs += [args.inventory / 'duplicate-groups.json', args.sql_evidence, args.reader_evidence]
    before = [fingerprint(p) for p in tracked_inputs]
    pending = [r for r in rows if r['category'] == PENDING]
    groups = collections.defaultdict(list)
    for row in pending:
        groups[row['sha256'] or row['record_id']].append(row)
    reader = Sources(args.sevenzip)
    reader_evidence = json.loads(args.reader_evidence.read_text(encoding='utf-8-sig'))
    catalog = {r['physical_name'].casefold(): r for r in json.loads(args.sql_evidence.read_text(encoding='utf-8-sig'))['files']}
    args.output.mkdir(parents=True)
    emit_json(args.output / 'input-fingerprints.json', before)
    outcomes, internal = {}, []
    for i, (key, matches) in enumerate(groups.items(), 1):
        row = min(matches, key=lambda r: (int(r['priority']), r['relative_path']))
        name = row['relative_path'].split('/')[-1]
        folder = args.output / 'evidence' / key
        folder.mkdir(parents=True)
        path = folder / name
        try:
            if row['sha256']:
                data = reader.read(row)
                require(digest(data) == row['sha256'] and len(data) == int(row['size_bytes']), 'source content changed; no classification applied')
                path.write_bytes(data)
                result = inspect(data, path, row, matches, reader, reader_evidence)
                result.update(sha256=digest(data), bytes=len(data), content_access='verified-full-file')
                internal.extend(archive_modules(args.output, row, result))
            else:
                record = catalog.get(row['original_path'].casefold())
                require(record and int(record['size_pages']) * 8192 == int(row['size_bytes']), 'SQL catalog path/size identity not established')
                require(record['type_desc'] in ('ROWS', 'LOG'), 'unexpected SQL storage type')
                result = dict(format='SQL-Server-' + record['type_desc'], category=DIRECT,
                              confidence='SQL-catalog-confirmed', content_access='unavailable-no-content-hash',
                              basis='当前只读 sys.master_files 中物理路径、数据库、类型及分配大小对应', sql_catalog=record,
                              remaining='原内容读取限制保留，未取得内容 SHA-256；不得参与同哈希匹配或宣称数据完整解码')
            result.setdefault('confidence', 'content-structure-and-role-verified')
        except Exception as exc:
            result = dict(category=PENDING, confidence='unresolved', format='unresolved', basis=str(exc),
                          remaining='保留未确定状态，继续取得该具体内容的结构或原版读取证据')
        result.update(source_records=matches, evidence_kind='classification-only; code exports remain incomplete')
        evidence = folder / (name + '.inspection.json')
        emit_json(evidence, result)
        (folder / (name + '.inspection.md')).write_text('\n'.join([
            '# 单文件内容与处理路线核验', '',
            '原文件：`' + row['relative_path'] + '`；原路径、组件、版本、所有相同内容来源见同名 JSON。', '',
            'SHA-256：`' + (row['sha256'] or '内容不可读，未生成哈希') + '`。', '',
            '本轮范围：完整可读字节或原版角色证据核验；分类为 `' + result['category'] + '`。', '',
            '验收依据：' + result['basis'] + '。', '',
            '剩余缺口与下一步：' + result['remaining'] + '。', '',
            '处理路线确认与反编译完成分开；本说明不代表程序恢复、编译或行为验收通过。', ''
        ]), encoding='utf-8')
        outcomes[key] = (result, str(evidence.resolve()))
        if i % 250 == 0:
            print(f'Inspected {i}/{len(groups)} content identities', flush=True)
    old_identity = [(r['record_id'], r['sha256'], r['analysis_key'], r['relative_path'], r['owner']) for r in rows]
    for row in rows:
        row['access_limitation'] = row['read_status'] if row['read_status'] != 'ok' else ''
        if row['category'] != PENDING:
            continue
        result, evidence = outcomes[row['sha256'] or row['record_id']]
        row['deep_review_previous_category'] = row['category']
        row['deep_review_previous_evidence'] = row['classification_evidence']
        row['category'] = result['category']
        row['classification_evidence'] = evidence
        row['classification_status'] = result['confidence']
        row['classification_remaining'] = result['remaining']
        row['reason'] = result['basis']
        row['format'] = result['format']
        unresolved = result['category'] == PENDING
        row['classification_review_required'] = str(unresolved)
        row['review'] = result['basis'] if unresolved else ''
        row['uncertainty_reason'] = result['basis'] if unresolved else ''
        row['classification_content_access'] = result.get('content_access', 'inspection-failed')
    require(old_identity == [(r['record_id'], r['sha256'], r['analysis_key'], r['relative_path'], r['owner']) for r in rows], 'source identity changed')
    require(len({r['record_id'] for r in rows}) == len(rows), 'duplicate source identity')
    fields = list(dict.fromkeys(k for r in rows for k in r))
    categories = {c: [r for r in rows if r['category'] == c] for c in (REVERSE, DIRECT, PENDING)}
    for cat, records in categories.items():
        folder = args.output / cat
        folder.mkdir()
        write_csv(folder / 'files.csv', records, fields)
        if cat != PENDING:
            write_csv(folder / 'duplicates.csv', [r for r in records if r['duplicate_type']], fields)
    (args.output / 'duplicate-groups.json').write_bytes((args.inventory / 'duplicate-groups.json').read_bytes())
    emit_json(args.output / 'internal-code-members.json', internal)
    native_parts = archive_readers(args.output, reader_evidence)
    emit_json(args.output / 'sql-catalog.json', json.loads(args.sql_evidence.read_text(encoding='utf-8-sig')))
    emit_json(args.output / 'reader-evidence.json', reader_evidence)
    by_ext = {}
    for ext in sorted({r['extension'] for r in pending}):
        records = [r for r in pending if r['extension'] == ext]
        by_ext[ext] = dict(rows=len(records), unique_readable_hashes=len({r['sha256'] for r in records if r['sha256']}),
                           routes=dict(collections.Counter(r['category'] for r in records)))
    summary = dict(scope='Properties only; Plus frozen', source_rows=len(rows), pending_before=len(pending),
                   primary_pending_before=sum(r['priority'] == '1' for r in pending),
                   inspected_readable_hashes=sum(bool(matches[0]['sha256']) for matches in groups.values()),
                   metadata_only_rows=sum(not r['sha256'] for r in pending),
                   categories={cat: dict(rows=len(records), primary_rows=sum(r['priority'] == '1' for r in records),
                              duplicate_rows=sum(bool(r['duplicate_type']) for r in records)) for cat, records in categories.items()},
                   suffix_results=by_ext, internal_code_members=len(internal), native_reader_partial_results=len(native_parts),
                   unreadable_rows=sum(r['read_status'] != 'ok' for r in rows),
                   unresolved_target_rows=sum(r['target_resolution'] == 'symbolic-target-unresolved' for r in rows),
                   plus_baseline_unchanged=True,
                   limits=['Classification routes only; no complete decompilation or behavior acceptance.',
                           'Metadata-only SQL identities do not establish readable content or duplicate hashes.',
                           'HMS/SDF reader roles established; full binary semantics remain unverified.'])
    require([fingerprint(p) for p in tracked_inputs] == before, 'input/baseline fingerprint changed')
    emit_json(args.output / 'summary.json', summary)
    lines = ['# Aspen Properties 深入分类核验', '',
             '此轮逐一核验全部原未定可读内容哈希，原清单与 Plus 基线只读保留。分类确认不等于反编译完成。', '',
             '| 清单 | 来源记录 | 首选来源 | 文件 |', '| --- | ---: | ---: | --- |']
    for cat, title in ((REVERSE, '需要逆向'), (DIRECT, '不需要逆向'), (PENDING, '尚未确定')):
        records = categories[cat]
        lines.append(f"| {title} | {len(records):,} | {sum(r['priority'] == '1' for r in records):,} | [{cat}/files.csv]({cat}/files.csv) |")
        if cat != PENDING:
            duplicate = [r for r in records if r['duplicate_type']]
            lines.append(f"| {title}中的重复项 | {len(duplicate):,} | {sum(r['priority'] == '1' for r in duplicate):,} | [{cat}/duplicates.csv]({cat}/duplicates.csv) |")
    lines += ['', '重复清单为对应类别的附加子集，两份共用同一 duplicate-groups.json；不再次计数。', '',
              'evidence/<内容哈希或来源ID>/ 中每个原文件均有同名 inspection.json 和 inspection.md，记录完整来源、验收依据与缺口。',
              '02-incomplete/ 保留原安装相对路径，保存本轮新确认 VBA 的部分源文本，每个成果配同名 .md。代码未通过完整性验收，01-completed/ 无程序完成件。',
              'internal-code-members.json 单列内部 VBA 模块；它们是父文件的内部成员，不加到原 19,298 条来源行或重复清单的分母。',
              '8 个 MDF/LDF 身份由当前 SQL 系统目录确认；内容及哈希仍不可读，以 access_limitation 独立记录。98 条符号安装目标未解析，独立于分类状态。',
              '所有原版数据、代码、二进制和详细证据仅本地保存；旧快照、受保护数据库和公式目录未改动。', '']
    (args.output / 'README.md').write_text('\n'.join(lines), encoding='utf-8')
    print(json.dumps(summary, ensure_ascii=False))


if __name__ == '__main__':
    main()
