"""Content-boundary and package-relationship regressions; no proprietary fixtures."""

import hashlib
import io
from pathlib import Path
import struct
import sys
import unittest
import uuid
import zipfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from confirm_properties_pending import Sources, biff_sheets, binary_part, emf, shortcut, svg


class FormatChecks(unittest.TestCase):
    def test_svg_internal_reference(self):
        self.assertEqual(svg(b'<svg xmlns="http://www.w3.org/2000/svg"><defs><path id="x"/></defs><use href="#x"/></svg>')['internal_references'], 1)

    def test_svg_script_not_accepted_as_image(self):
        with self.assertRaises(ValueError):
            svg(b'<svg xmlns="http://www.w3.org/2000/svg"><script/></svg>')

    def test_svg_external_reference_not_accepted(self):
        with self.assertRaises(ValueError):
            svg(b'<svg xmlns="http://www.w3.org/2000/svg"><use href="https://example.com/a"/></svg>')

    def test_svg_event_not_accepted(self):
        with self.assertRaises(ValueError):
            svg(b'<svg xmlns="http://www.w3.org/2000/svg" onload="x()"/>')

    def test_svg_missing_definition_not_accepted(self):
        with self.assertRaises(ValueError):
            svg(b'<svg xmlns="http://www.w3.org/2000/svg"><use href="#missing"/></svg>')

    def drawing(self):
        raw = bytearray(108)
        struct.pack_into('<II', raw, 0, 1, 88)
        raw[40:44] = b' EMF'
        struct.pack_into('<II', raw, 48, len(raw), 2)
        struct.pack_into('<II', raw, 88, 14, 20)
        return raw

    def test_emf_complete_records(self):
        self.assertEqual(emf(self.drawing())['records'], 2)

    def test_emf_truncated_record(self):
        raw = self.drawing()
        struct.pack_into('<I', raw, 92, 24)
        with self.assertRaises(ValueError):
            emf(raw)

    def test_emf_wrong_record_count(self):
        raw = self.drawing()
        struct.pack_into('<I', raw, 52, 3)
        with self.assertRaises(ValueError):
            emf(raw)

    def test_biff_macro_sheet_identified(self):
        record = struct.pack('<HH', 0x85, 6) + b'\0' * 5 + b'\1'
        self.assertEqual(biff_sheets(record)['macro_sheets'], 1)

    def test_biff_normal_sheet(self):
        self.assertEqual(biff_sheets(struct.pack('<HH', 0x85, 6) + b'\0' * 6)['macro_sheets'], 0)

    def test_biff_truncated(self):
        with self.assertRaises(ValueError):
            biff_sheets(struct.pack('<HH', 0x85, 60) + b'\0' * 6)

    def test_shell_link_terminal_block(self):
        data = bytearray(80)
        struct.pack_into('<I', data, 0, 76)
        data[4:20] = uuid.UUID('00021401-0000-0000-c000-000000000046').bytes_le
        self.assertEqual(shortcut(data)['extra_blocks'], 0)

    def test_shell_link_unknown_trailing_bytes(self):
        data = bytearray(81)
        struct.pack_into('<I', data, 0, 76)
        data[4:20] = uuid.UUID('00021401-0000-0000-c000-000000000046').bytes_le
        with self.assertRaises(ValueError):
            shortcut(data)


class PackageChecks(unittest.TestCase):
    def package(self, classid='D7053240-CE69-11CD-A777-00DD01143C57', relid='rId1'):
        data = uuid.UUID('d7053240-ce69-11cd-a777-00dd01143c57').bytes_le + b'\x00\x02\x04\x00' + b'\0' * 4
        buffer = io.BytesIO()
        with zipfile.ZipFile(buffer, 'w') as z:
            z.writestr('[Content_Types].xml', '<Types><Override PartName="/xl/activeX/activeX5.bin" ContentType="application/vnd.ms-office.activeX"/></Types>')
            z.writestr('xl/activeX/activeX5.bin', data)
            z.writestr('xl/activeX/activeX41.xml', f'<ocx xmlns:r="urn:rel" classid="{{{classid}}}" persistence="persistStreamInit" r:id="{relid}"/>')
            z.writestr('xl/activeX/_rels/activeX41.xml.rels', '<Relationships><Relationship Id="rId1" Type="urn:example/activeXControlBinary" Target="activeX5.bin"/></Relationships>')
        reader = Sources(Path('unused-sevenzip'))
        reader.zips['fixture'] = zipfile.ZipFile(io.BytesIO(buffer.getvalue()))
        row = dict(container='fixture', member='xl/activeX/activeX5.bin', sha256=hashlib.sha256(data).hexdigest())
        return data, row, reader

    def test_relationship_not_numeric_basename_binds_control(self):
        data, row, reader = self.package()
        result = binary_part(data, [row], reader)
        self.assertEqual(result['clsid'], 'd7053240-ce69-11cd-a777-00dd01143c57')
        self.assertEqual(result['contexts'][0]['controls'][0]['part'], 'xl/activeX/activeX41.xml')

    def test_changed_binary_member_rejected(self):
        _, row, reader = self.package()
        row['sha256'] = '0' * 64
        with self.assertRaises(ValueError):
            reader.context(row)

    def test_control_clsid_conflict_rejected(self):
        data, row, reader = self.package(classid='00000000-0000-0000-0000-000000000000')
        with self.assertRaises(ValueError):
            binary_part(data, [row], reader)

    def test_relationship_id_conflict_rejected(self):
        _, row, reader = self.package(relid='rId2')
        with self.assertRaises(ValueError):
            reader.context(row)

    def test_truncated_control_properties_rejected(self):
        data, row, reader = self.package()
        data = data[:18] + b'\xff\xff' + data[20:]
        with self.assertRaises(ValueError):
            binary_part(data, [row], reader)


if __name__ == '__main__':
    unittest.main()
