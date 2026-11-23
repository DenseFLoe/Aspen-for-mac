# NATIVE-340 s89 re-run dependencies

| dep | version / source | use |
| --- | --- | --- |
| Python | 3.13 | all scripts |
| pefile | 2024.8.26 | qa gate IAT/byte checks |
| .NET SDK | 9.0.302 | PEReader endpoint check |
| System.Reflection.Metadata | in-box .NET 9 | PEReader |
| capstone | qa gate dependency | linear disassembly census |

Commands:

python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission handoff/inbox/NATIVE-340
cd _tools/qa/27007e5a && PYTHONPATH=<repo>/.local/pylibs python -B -m qa.gate --task NATIVE-340 --head HEAD
dotnet run -c Release -- ORIGINAL    # _t14/pereader project
python -B tool/audit_340_s89.py --binary ORIGINAL --folder handoff/inbox/NATIVE-340
