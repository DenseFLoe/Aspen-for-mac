"""Independent controlled assembly and acceptance checks for the fresh C# profile."""
import hashlib
from pathlib import Path
import subprocess
import tempfile
import unittest

if __package__:
    from . import fresh_cs
else:
    import fresh_cs


SOURCE = b"""public static class Balance
{
    public static double LimitedDifference(double inlet, double outlet)
    {
        double difference = inlet - outlet;
        return difference < 0.0 ? 0.0 : difference;
    }
}""" + b"\r\n"
EXPECTED = "f3c11dcf4ddebe24045d075a90fd9fac6900fe93d66cee8064f432bf71ea1fb8"
# Separate producer uses the C# API directly. It neither reads nor calls the
# verifier's PowerShell driver. Add-Type only loads this fixed fixture builder.
PRODUCER = r"""
param([string]$Folder, [string]$Output, [string]$Reference)
$ErrorActionPreference='Stop'
$c=[Reflection.Assembly]::LoadFrom((Join-Path $PSHOME 'Microsoft.CodeAnalysis.CSharp.dll'))
$b=[Reflection.Assembly]::LoadFrom((Join-Path $PSHOME 'Microsoft.CodeAnalysis.dll'))
$refs=@($c.Location,$b.Location)+(Get-ChildItem -File -LiteralPath (Join-Path $PSHOME 'ref')).FullName
Add-Type -ReferencedAssemblies $refs -CompilerOptions '/nowarn:1701' -TypeDefinition @'
using System;
using System.IO;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;

public static class FixtureProducer {
    public static void Build(string path, string output, string reference) {
        var utf8 = new UTF8Encoding(false, true);
        var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path, utf8),
            CSharpParseOptions.Default.WithLanguageVersion(LanguageVersion.CSharp12), "Balance.cs", utf8);
        var options = new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary,
            optimizationLevel: OptimizationLevel.Release, deterministic: true);
        var unit = CSharpCompilation.Create("ControlledBalance", new[] {tree},
            new[] {MetadataReference.CreateFromFile(reference)}, options);
        using (var stream = File.Create(output)) {
            if (!unit.Emit(stream).Success) throw new Exception("Fixture build failed.");
        }
    }
}
'@
[FixtureProducer]::Build((Join-Path $Folder 'Balance.cs'), $Output, $Reference)
"""


class FreshCsControls(unittest.TestCase):
    def test_whole_item_requires_exact_identity_and_bound_editable_sources(self):
        import verify
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            original = root / "ControlledBalance.dll"
            original.write_bytes(self.original)
            delivery = root / "delivery"
            src = delivery / "fresh-cs"
            src.mkdir(parents=True)
            (src / "Balance.cs").write_bytes(SOURCE)
            (src / "Balance.cs.md").write_text(
                "Source: fresh-cs/Balance.cs\nSource SHA-256: " + hashlib.sha256(SOURCE).hexdigest())
            item_note = delivery / "ControlledBalance.dll.md"
            note = (f"Product: QA-Fixture\nOriginal path: Cases/ControlledBalance.dll\nOriginal SHA-256: {EXPECTED}\n"
                    f"Assembly version: 0.0.0.0\nVerification profile: {fresh_cs.PROFILE}\nScope: whole-pe-static\n"
                    "Evidence: fresh-source-build\nStatic gaps: none")
            item_note.write_text(note)
            def evaluate():
                return verify.item(original, EXPECTED, delivery, product="QA-Fixture", original_path="Cases/ControlledBalance.dll")
            self.assertEqual(evaluate()["basis"], "fresh_source_build_full_file_exact_and_item_evidence")
            item_note.write_text(note.replace("Product: QA-Fixture", "Product: wrong-QA-Fixture"))
            self.assertEqual(evaluate()["status"], "inconclusive")

    @classmethod
    def setUpClass(cls):
        host = fresh_cs._toolchain()
        if not host:
            raise unittest.SkipTest("pinned local Windows Roslyn 5.0/reference unavailable")
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            (root / "Balance.cs").write_bytes(SOURCE)
            script = root / "produce.ps1"
            script.write_text(PRODUCER, encoding="utf-8")
            output = root / "ControlledBalance.dll"
            subprocess.run([str(host / "pwsh.exe"), "-NoProfile", "-NonInteractive", "-File",
                            str(script), str(root), str(output), str(fresh_cs.REFERENCE)], cwd=root,
                           stdin=subprocess.DEVNULL, capture_output=True, check=True, timeout=60)
            cls.original = output.read_bytes()
            if hashlib.sha256(cls.original).hexdigest() != EXPECTED:
                raise AssertionError("independent controlled original differs from published fixture digest")

    def run_case(self, files, original=None, name="ControlledBalance.dll"):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            src = root / "fresh-cs"
            src.mkdir()
            for path, data in files.items():
                (src / path).write_bytes(data)
            return fresh_cs.check(self.original if original is None else original, root, name)

    def test_rebuilt_twice_from_source(self):
        for _ in range(2):
            result = self.run_case({"Balance.cs": SOURCE, "Balance.cs.md": b"fixture"})
            self.assertEqual(result["status"], "pass")
            self.assertEqual(result["metrics"]["rebuilt_sha256"], EXPECTED)
            self.assertEqual(result["metrics"]["assembly_version"], "0.0.0.0")

    def test_same_size_source_edit(self):
        changed = SOURCE.replace(b"inlet - outlet", b"inlet + outlet")
        result = self.run_case({"Balance.cs": changed})
        self.assertEqual(result["status"], "inconclusive")
        self.assertEqual(result["findings"][0]["code"], "fresh_cs_pe_differs")

    def test_copied_original_is_not_a_source(self):
        result = self.run_case({"ControlledBalance.dll": self.original})
        self.assertEqual(result["status"], "fail")
        self.assertEqual(result["findings"][0]["code"], "fresh_cs_unexpected_input")

    def test_changed_tail_in_original(self):
        changed = self.original[:-1] + bytes([self.original[-1] ^ 1])
        result = self.run_case({"Balance.cs": SOURCE}, original=changed)
        self.assertEqual(result["findings"][0]["first_file_offset"], len(self.original) - 1)

    def test_response_file_rejected(self):
        result = self.run_case({"Balance.cs": SOURCE, "args.rsp": b"-target:module"})
        self.assertEqual(result["status"], "fail")

    def test_compile_error_is_inconclusive(self):
        result = self.run_case({"Balance.cs": b"invalid CS syntax"})
        self.assertEqual(result["findings"][0]["code"], "fresh_cs_profile_compile_error")

    def test_rejects_output_path(self):
        result = self.run_case({"Balance.cs": SOURCE}, name="../ControlledBalance.dll")
        self.assertEqual(result["findings"][0]["code"], "fresh_cs_unsupported_name")

