"""Re-run three clean, paired ILSpy project builds (Windows, Python 3.11+)."""
import argparse
import csv
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import xml.etree.ElementTree as ET
from collections import Counter
from contextlib import nullcontext
from pathlib import Path

sys.dont_write_bytecode = True
import scan

HERE = Path(__file__).resolve().parent
SAMPLES = ("AspenTech.AspenPlus.Engine.Structures", "AspenTech.AspenPlus.HybridModelUtilities",
           "AspenTech.AspenPlus.CustomModels")


def sha(path):
    with path.open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def manifest(folder, files):
    rows = [f"{p.relative_to(folder).as_posix()}\t{sha(p)}\n" for p in sorted(files)]
    return hashlib.sha256("".join(rows).encode()).hexdigest()


def test_sample(args, sample, node, dependencies, direct_names, files, scratch, env):
    run = scratch / sample
    refs = run / "refs"
    src = run / "export"
    refs.mkdir(parents=True)
    src.mkdir()
    # Make the decompiler's copy independent of the installed sibling directories.
    original = run / (sample + ".dll")
    shutil.copyfile(files[node["sha256"]], original)
    bindings = {}
    for dep in dependencies:
        name = dep["identity"]["name"]
        dest = refs / (name + Path(dep["path"]).suffix)
        if dest.exists() and sha(dest) != dep["sha256"]:
            raise ValueError(f"conflicting binaries for {name}")
        shutil.copyfile(files[dep["sha256"]], dest)
        bindings[name] = dest
    cmd = [args.dotnet, args.ilspy, "--disable-updatecheck", "-p", "-r", refs, "-o", src, original]
    subprocess.run(cmd, check=True, env=env)
    project = next(src.glob("*.csproj"))
    generated = ET.parse(project)
    root = generated.getroot()
    if root.findtext(".//TargetFramework") != "net48":
        raise ValueError("Expected net48")
    props = ET.SubElement(root, "PropertyGroup")
    settings = {
        "GenerateTargetFrameworkAttribute": "false", "SignAssembly": "false",
        "AssemblySearchPaths": "{HintPathFromItem};{TargetFrameworkDirectory}",
        "UseSharedCompilation": "false", "AutomaticallyUseReferenceAssemblyPackages": "false",
    }
    for key, value in settings.items():
        ET.SubElement(props, key).text = value
    pack = args.refroot / ".NETFramework" / "v4.8"
    # Keep framework References. Strip exporter-generated hints that point back into the installation.
    for group in root.findall("ItemGroup"):
        for ref in group.findall("Reference"):
            name = ref.get("Include").split(",")[0]
            if not (pack / (name + ".dll")).is_file():
                group.remove(ref)
            else:
                hint = ref.find("HintPath")
                if hint is not None:
                    ref.remove(hint)
    # The exporter omits several framework references in WPF projects. Explicit
    # framework refs and the netstandard 2.0 facade are identical in BOTH arms.
    existing = {r.get("Include") for r in root.findall(".//Reference")}
    framework = ET.SubElement(root, "ItemGroup")
    for name in sorted(set(direct_names) - existing - {"mscorlib"}):
        if (pack / (name + ".dll")).is_file():
            ET.SubElement(framework, "Reference", {"Include": name})
    facade = ET.SubElement(framework, "Reference", {"Include": "netstandard"})
    ET.SubElement(facade, "HintPath").text = str(pack / "Facades/netstandard.dll")
    pkg = run / "NuGet.Config"
    pkg.write_text("<configuration><packageSources><clear/></packageSources></configuration>", encoding="utf-8")
    source_files = list(src.rglob("*.cs"))
    resources = [p for p in src.rglob("*") if p.is_file() and p != project and p.suffix != ".cs"]
    row = dict(sample=original.name, sha256=sha(original), bytes=original.stat().st_size,
               node_id=node["id"], references_added=len(bindings), cs_files=len(source_files),
               cs_manifest_sha256=manifest(src, source_files), other_files=len(resources),
               other_manifest_sha256=manifest(src, resources))
    evidence = {}
    for mode in ("before", "after"):
        folder = run / mode
        shutil.copytree(src, folder)
        target = folder / project.name
        if mode == "after":
            group = ET.SubElement(root, "ItemGroup")
            for name, path in sorted(bindings.items()):
                ref = ET.SubElement(group, "Reference", {"Include": name})
                ET.SubElement(ref, "HintPath").text = "../refs/" + path.name
                ET.SubElement(ref, "Private").text = "false"
        generated.write(target, encoding="utf-8", xml_declaration=True)
        if manifest(folder, folder.rglob("*.cs")) != row["cs_manifest_sha256"]:
            raise ValueError("source changed")
        cmd = [args.dotnet, "build", target, "-c", "Release", "--configfile", pkg,
               "--nologo", "--disable-build-servers", "-v:minimal", "-clp:NoSummary",
               f"-p:TargetFrameworkRootPath={args.refroot}{os.sep}",
               f"-p:FrameworkPathOverride={pack}", "-p:PreferredUILang=en-US"]
        result = subprocess.run(cmd, cwd=run, env=env, capture_output=True, encoding="utf-8", errors="replace")
        log = result.stdout + result.stderr
        (run / (mode + ".log")).write_text(log, encoding="utf-8")
        diagnostics = []
        diag_lines = []
        for ln in log.splitlines():
            found = re.search(r": (error|warning) ([A-Z]+\d+): (.*)", ln)
            if found:
                diag_lines.append(ln.replace(str(run), "<sample>"))
                diagnostics.append((found[1], found[2], found[3].split(" [")[0].replace(str(run), "<sample>")))
        errors = [item for item in diagnostics if item[0] == "error"]
        if result.returncode and not errors:
            raise RuntimeError(log[-2000:])
        if result.returncode == 0 and not (folder / "bin/Release/net48" / original.name).is_file():
            raise RuntimeError("build returned 0 without the target DLL")
        report = args.out / (sample + "." + mode + ".txt")
        report.write_text("\n".join(sorted(diag_lines)) + "\n", encoding="utf-8")
        row[mode + "_exit"] = result.returncode
        row[mode + "_errors"] = len(errors)
        counts = Counter((severity, code) for severity, code, _ in diagnostics)
        evidence[mode] = [
            {"level": level, "code": code, "count": count,
             "examples": list(dict.fromkeys(msg for lv, c, msg in diagnostics if (lv,c) == (level,code)))[:3]}
            for (level,code), count in sorted(counts.items())]
    print(sample, row["before_errors"], row["after_errors"], flush=True)
    return row, evidence


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for param in ("dotnet", "ilspy", "refroot", "inventory-dir", "out"):
        parser.add_argument("--" + param, type=Path, required=True)
    parser.add_argument("--media-dir", type=Path)
    parser.add_argument("--work-dir", type=Path, help="Keep the complete run in a new, previously nonexistent folder")
    args = parser.parse_args()
    if not (args.refroot / ".NETFramework/v4.8/mscorlib.dll").is_file():
        parser.error("--refroot must be the build folder of the net48 reference pack")
    args.out.mkdir(parents=True, exist_ok=True)
    graph = json.loads((HERE / "closure.json").read_text(encoding="utf-8"))
    inventory, fingerprints = scan.read_inventories(args.inventory_dir)
    if fingerprints != graph["inventories"]:
        raise ValueError("inventory fingerprint mismatch")
    nodes = {n["id"]: n for n in graph["nodes"]}
    roots = {r["id"]: r for r in graph["roots"]}
    with (HERE / "assemblyrefs.csv").open(encoding="utf-8", newline="") as f:
        edges = list(csv.DictReader(f))
    samples = []
    for sample in SAMPLES:
        candidates = [n for n in nodes.values() if n["identity"]["name"] == sample]
        if len(candidates) != 1:
            raise ValueError(f"expected one inventory node for {sample}")
        node, = candidates
        deps = [nodes[i] for i in roots[node["id"]]["reachable"] if nodes[i]["sha256"] != node["sha256"]]
        samples.append((sample, node, deps, [e["ref_name"] for e in edges if int(e["source_id"]) == node["id"]]))
    needed = {n["sha256"] for _, node, deps, _ in samples for n in [node, *deps]}
    if args.work_dir:
        args.work_dir.mkdir(parents=True, exist_ok=False)
        work = nullcontext(args.work_dir)
    else:
        work = tempfile.TemporaryDirectory(prefix="aspen-clr-build-")
    with work as temp:
        scratch = Path(temp).resolve()
        files, _ = scan.find_binaries([item for item in inventory if item[2]["sha256"] in needed], scratch, args.media_dir)
        env = dict(os.environ, DOTNET_CLI_UI_LANGUAGE="en-US", VSLANG="1033", DOTNET_NOLOGO="true",
                   DOTNET_CLI_TELEMETRY_OPTOUT="1", DOTNET_CLI_HOME=str(temp), NUGET_PACKAGES=str(scratch / "packages"))
        rows, diagnoses = [], {}
        for sample, node, deps, direct_names in samples:
            row, diag = test_sample(args, sample, node, deps, direct_names, files, scratch, env)
            rows.append(row)
            diagnoses[sample] = diag
        with (args.out / "build-results.csv").open("w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(f, fieldnames=list(rows[0]), lineterminator="\n")
            writer.writeheader()
            writer.writerows(rows)
        (args.out / "build-diagnostics.json").write_text(json.dumps(diagnoses, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()



