"""Synthetic resources test format boundaries without proprietary input files."""
import json
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from scan_aspen_ui import parse_baml, parse_dialog, parse_menu, managed_entries


def w(text):
    return text.encode('utf-16-le')+b'\0\0'


def s(text):
    data = text.encode()
    assert len(data) < 128
    return bytes([len(data)])+data


def variable(kind, payload):
    assert len(payload) < 126
    return bytes([kind, len(payload)+1])+payload


class ResourceTests(unittest.TestCase):
    def test_resource_set_utf16_names_utf8_values_and_opaque_objects(self):
        def encoded(data):
            n=len(data); prefix=bytearray()
            while n>=128: prefix.append((n&127)|128); n>>=7
            return bytes(prefix)+bytes([n])+data
        name1=encoded('按钮'.encode('utf-16-le'))+struct.pack('<I',0)
        value1=b'\x01'+encoded(('查找化合物'*40).encode('utf-8'))
        name2=encoded('opaque'.encode('utf-16-le'))+struct.pack('<I',len(value1))
        header=struct.pack('<IIIIII',0xbeefcace,1,0,2,2,1)+s('Unloaded.Custom.Type')
        header+=b'\0'*((-len(header))%8)
        header+=struct.pack('<IIII',0,0,0,len(name1))
        data=header+struct.pack('<I',len(header)+4+len(name1)+len(name2))+name1+name2+value1+b'\x40arbitrary'
        entries=list(managed_entries(data))
        self.assertEqual(entries,[('按钮','查找化合物'*40,1),('opaque',None,64)])

    def test_dialog_coordinates_and_ordinals(self):
        data = struct.pack('<IIHhhhh', 0, 0, 1, 0, 0, 200, 100)+w('')+w('')+w('标题')
        data += b'\0'*((-len(data)) % 4)
        data += struct.pack('<IIhhhhH', 0x50010001, 0, 10, 20, 60, 14, 7)
        data += b'\xff\xff\x80\x00'+w('确定')+b'\0\0'
        result = parse_dialog(data)
        self.assertEqual(result['title'], '标题')
        self.assertEqual(result['controls'][0]['rect'], [10,20,60,14])
        self.assertEqual(result['controls'][0]['type'], 'Button')
        with self.assertRaises(ValueError): parse_dialog(data[:-1])

    def test_extended_dialog_font_and_large_control_id(self):
        data = struct.pack('<HHIIIHhhhh', 1, 0xffff, 0, 0, 0x40, 1, 0, 0, 200, 100)
        data += w('')+w('')+w('Test')+struct.pack('<HHBB', 9,400,0,1)+w('Segoe UI')
        data += b'\0'*((-len(data)) % 4)
        data += struct.pack('<IIIhhhhI', 0,0,0,1,2,50,10,70000)+w('CustomGrid')+w('')+b'\0\0'
        result = parse_dialog(data)
        self.assertEqual(result['font']['point'], 9)
        self.assertEqual(result['controls'][0]['id'], 70000)

    def test_standard_creation_data_includes_size_word(self):
        data = struct.pack('<IIHhhhh',0,0,1,0,0,100,100)+w('')+w('')+w('')
        data += b'\0'*((-len(data))%4)
        data += struct.pack('<IIhhhhH',0,0,1,2,30,20,1)+w('Button')+w('Go')
        data += struct.pack('<H',4)+b'AB'
        self.assertEqual(parse_dialog(data)['controls'][0]['text'],'Go')

    def test_nested_menu_and_disabled_command(self):
        data = b'\0\0\0\0'+struct.pack('<H',0x90)+w('File')
        data += struct.pack('<HH',0x83,42)+w('Save')
        result = parse_menu(data)['items'][0]
        self.assertEqual(result['text'], 'File')
        self.assertEqual(result['items'][0]['id'], 42)
        self.assertEqual(result['items'][0]['state'] & 3, 3)

    def test_baml_hierarchy_localized_static_reference_and_truncation(self):
        known={'types':{'1':'Grid','2':'Button','602':'StaticExtension'}, 'properties':{'1':'ContentControl.Content'}}
        data = struct.pack('<I',12)+'MSBAML'.encode('utf-16-le')+b'\0'*12
        data += b'\x01'+b'\0'*6
        data += variable(29,struct.pack('<hh',0,0)+s('Aspen.Resources'))
        data += variable(31,struct.pack('<hhB',0,0,0)+s('Caption'))
        data += b'\x03'+struct.pack('<hB',-1,0)+b'\x03'+struct.pack('<hB',-2,0)
        data += b'\x23'+struct.pack('<hHh',-1,602,0)+b'\x04\x04\x02'
        result = parse_baml(data,known)['nodes']
        self.assertEqual(result[1]['parent'],0)
        self.assertEqual(result[1]['properties']['ContentControl.Content']['member'],'Resources.Caption')
        with self.assertRaises(ValueError): parse_baml(data[:-1],known)
        with self.assertRaises(ValueError): parse_baml(data[:-1]+b'\xff',known)


if __name__ == '__main__': unittest.main()
