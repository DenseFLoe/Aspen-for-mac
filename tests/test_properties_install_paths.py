"""Installation-target regressions with synthetic metadata, no vendor binaries."""

import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from resolve_properties_install_paths import assembly_spec, choose_result


class AssemblyTargets(unittest.TestCase):
    def setUp(self):
        self.row = dict(msi_file_id='file1', msi_component='component1',
                        relative_path='[TARGETDIR]/Example.dll', size_bytes='42')
        self.names = dict(name='Example', version='1.0.0.0', culture='neutral',
                          publickeytoken='0011223344556677', processorarchitecture='MSIL')
        self.tables = dict(
            File=[dict(File='file1', Component_='component1', FileName='EXAMPL~1.DLL|Example.dll', FileSize='42')],
            Component=[dict(Component='component1', ComponentId='{id}', KeyPath='file1')],
            MsiAssembly=[dict(Component_='component1', File_Manifest='file1', File_Application='', Attributes='0')],
            MsiAssemblyName=[dict(Component_='component1', Name=k, Value=v) for k, v in self.names.items()],
            InstallExecuteSequence=[dict(Action=a) for a in ('MsiPublishAssemblies', 'MsiUnpublishAssemblies')])
        self.spec = assembly_spec(self.row, self.tables)
        self.candidate = dict(self.names, path='cache/Example.dll', sha256='a' * 64, error='')

    def test_gac_requires_assembly_table_not_directory_name(self):
        tables = copy.deepcopy(self.tables)
        tables['MsiAssembly'] = []
        with self.assertRaises(StopIteration):
            assembly_spec(self.row, tables)

    def test_private_assembly_rejected(self):
        self.tables['MsiAssembly'][0]['File_Application'] = 'app.exe'
        with self.assertRaises(ValueError):
            assembly_spec(self.row, self.tables)

    def test_native_assembly_rejected(self):
        self.tables['MsiAssembly'][0]['Attributes'] = '1'
        with self.assertRaises(ValueError):
            assembly_spec(self.row, self.tables)

    def test_file_must_join_correct_component(self):
        self.tables['File'][0]['Component_'] = 'other'
        with self.assertRaises(ValueError):
            assembly_spec(self.row, self.tables)

    def test_manifest_must_identify_this_file(self):
        self.tables['MsiAssembly'][0]['File_Manifest'] = 'other'
        with self.assertRaises(ValueError):
            assembly_spec(self.row, self.tables)

    def test_optional_architecture_is_not_invented(self):
        self.tables['MsiAssemblyName'] = [r for r in self.tables['MsiAssemblyName'] if r['Name'] != 'processorarchitecture']
        spec = assembly_spec(self.row, self.tables)
        self.assertNotIn('ProcessorArchitecture=', spec['identity'])

    def test_same_hash_wrong_version_is_not_a_target(self):
        candidate = dict(self.candidate, version='2.0.0.0')
        with self.assertRaises(ValueError):
            choose_result(self.spec, -1, '', [candidate], 'a' * 64)

    def test_same_name_wrong_architecture_is_not_a_target(self):
        candidate = dict(self.candidate, processorarchitecture='Amd64')
        with self.assertRaises(ValueError):
            choose_result(self.spec, -1, '', [candidate], 'a' * 64)

    def test_different_content_keeps_installed_hash_separate(self):
        result = choose_result(self.spec, 3, self.candidate['path'], [self.candidate], 'b' * 64)
        self.assertEqual(result['installed_sha256'], 'a' * 64)
        self.assertEqual(result['installed_content_relation'], 'different-content')

    def test_disabled_component_gets_no_guessed_physical_path(self):
        result = choose_result(self.spec, -7, '', [], 'a' * 64)
        self.assertEqual(result['target_resolution'], 'gac-component-disabled')
        self.assertEqual(result['installed_path'], '')

    def test_disabled_with_conflicting_evidence_rejected(self):
        with self.assertRaises(ValueError):
            choose_result(self.spec, -7, '', [self.candidate], 'a' * 64)

    def test_shared_gac_present_when_product_registration_unknown(self):
        result = choose_result(self.spec, -1, '', [self.candidate], 'a' * 64)
        self.assertEqual(result['target_resolution'], 'gac-installed-identical')

    def test_ambiguous_unregistered_identity_rejected(self):
        with self.assertRaises(ValueError):
            choose_result(self.spec, -1, '', [self.candidate, dict(self.candidate, path='other/Example.dll')], 'a' * 64)

    def test_registered_path_wins_over_same_name_other_copy(self):
        other = dict(self.candidate, path='other/Example.dll', sha256='b' * 64)
        result = choose_result(self.spec, 3, other['path'], [self.candidate, other], 'a' * 64)
        self.assertEqual(result['installed_path'], other['path'])


if __name__ == '__main__':
    unittest.main()
