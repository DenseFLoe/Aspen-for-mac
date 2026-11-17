"""Synthetic formula-export checks; no installed Aspen data is required."""
import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import extract_aspen_formulas as export


class FormulaExportTest(unittest.TestCase):
    def fixture(self, root):
        topic = root / 'help/sample/Content/html'
        topic.mkdir(parents=True)
        (topic/'topic.htm').write_text(
            '<html><title>Sample</title><body><p>x<sup>2</sup> '
            '<img src="Equation1.svg"></p></body></html>', encoding='utf-8')
        (topic/'Equation1.svg').write_text(
            '<svg xmlns="http://www.w3.org/2000/svg" '
            'xmlns:xlink="http://www.w3.org/1999/xlink">'
            '<g><use xlink:href="#MJMATHI-78"/></g></svg>', encoding='utf-8')
        return root/'help'

    def test_export_and_reject_existing_output_without_changing_it(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            help_root = self.fixture(root)
            output = root/'export'
            index = export.Extractor(str(help_root), str(output)).run(None, None)
            self.assertEqual(len(index), 1)
            text = (output/index[0]['output']).read_text(encoding='utf-8')
            self.assertIn('x^2 x', text)
            before = {str(p): p.read_bytes() for p in output.rglob('*') if p.is_file()}
            with self.assertRaises(FileExistsError):
                export.Extractor(str(help_root), str(output)).run(None, None)
            self.assertEqual(before, {str(p): p.read_bytes() for p in output.rglob('*') if p.is_file()})

    def test_reject_protected_database_output_before_creating_directory(self):
        with tempfile.TemporaryDirectory() as tmp:
            help_root = self.fixture(Path(tmp))
            protected = Path(export.__file__).resolve().parents[1]/'.local/property-database'
            with mock.patch.object(Path, 'mkdir') as mkdir:
                with self.assertRaisesRegex(ValueError, 'protected'):
                    export.Extractor(str(help_root), str(protected/'new-export')).run(None, None)
                mkdir.assert_not_called()

    def test_missing_help_does_not_create_empty_export(self):
        with tempfile.TemporaryDirectory() as tmp:
            output = Path(tmp)/'export'
            with self.assertRaises(FileNotFoundError):
                export.Extractor(str(Path(tmp)/'missing'), str(output)).run(None, None)
            self.assertFalse(output.exists())

    def test_fluid_manifest_covers_all_file_types_and_exact_bytes(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            fluids = root/'engine/Dat/fluids'
            fluids.mkdir(parents=True)
            for suffix in ('FLD', 'PPF', 'BNC'):
                (fluids/('sample.'+suffix)).write_bytes(b'coefficient=1.234567890123456789\r\n')
            export.copy_fluids(str(root/'engine'), str(root/'output'))
            records = json.loads((root/'output/engine-fluids/manifest.json').read_text())
            self.assertEqual(len(records), 3)
            for record in records:
                copied = (root/'output/engine-fluids'/record['file']).read_bytes()
                self.assertEqual(copied, (fluids/record['file']).read_bytes())
                self.assertEqual(hashlib.sha256(copied).hexdigest(), record['sha256'])

    def test_direct_copy_helpers_reject_existing_and_protected_outputs(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            fluids = root/'engine/Dat/fluids'
            fluids.mkdir(parents=True)
            (fluids/'test.FLD').write_bytes(b'original')
            images = root/'help/Safety_Datasheets/Content/GeneratedImages'
            images.mkdir(parents=True)
            (images/'Equation1.png').write_bytes(b'original-png')
            protected = Path(export.__file__).resolve().parents[1]/'.local/property-database'
            for function, source in ((export.copy_fluids, root/'engine'),
                                     (export.copy_safety_images, root/'help')):
                with self.assertRaisesRegex(ValueError, 'protected'):
                    function(str(source), str(protected/'new-export'))
                function(str(source), str(root/'output'))
                with self.assertRaises(FileExistsError):
                    function(str(source), str(root/'output'))
            self.assertEqual((root/'output/engine-fluids/test.FLD').read_bytes(), b'original')
            self.assertEqual((root/'output/safety-datasheets-equation-images/Equation1.png').read_bytes(), b'original-png')

    def test_topic_basename_collision_refuses_overwrite(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            help_root = self.fixture(root)
            html = help_root/'sample/Content/html'
            (html/'topic.html').write_bytes((html/'topic.htm').read_bytes())
            with self.assertRaises(FileExistsError):
                export.Extractor(str(help_root), str(root/'output')).run(None, None)
            self.assertTrue((root/'output/topics/sample/topic.txt').exists())

    def test_flat_image_collision_preserves_first_file(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            images = root/'help/Safety_Datasheets/Content/GeneratedImages'
            images.mkdir(parents=True)
            (images/'Equation1.png').write_bytes(b'original')
            (images/'nested').mkdir()
            (images/'nested/Equation1.png').write_bytes(b'different')
            with self.assertRaises(FileExistsError):
                export.copy_safety_images(str(root/'help'), str(root/'output'))
            self.assertEqual((root/'output/safety-datasheets-equation-images/Equation1.png').read_bytes(), b'original')


if __name__ == '__main__':
    unittest.main()
