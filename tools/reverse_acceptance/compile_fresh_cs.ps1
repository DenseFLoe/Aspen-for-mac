param([string]$Name, [string]$Folder, [string]$Reference, [string]$Output)
$ErrorActionPreference = 'Stop'
[void][Reflection.Assembly]::LoadFrom((Join-Path $PSHOME 'Microsoft.CodeAnalysis.dll'))
[void][Reflection.Assembly]::LoadFrom((Join-Path $PSHOME 'Microsoft.CodeAnalysis.CSharp.dll'))
$references = [Microsoft.CodeAnalysis.MetadataReference[]]@(
    [Microsoft.CodeAnalysis.MetadataReference]::CreateFromFile($Reference))
$trees = [Collections.Generic.List[Microsoft.CodeAnalysis.SyntaxTree]]::new()
$tokens = [Threading.CancellationToken]::None
$parse = [Microsoft.CodeAnalysis.CSharp.CSharpParseOptions]::Default.WithLanguageVersion(
    [Microsoft.CodeAnalysis.CSharp.LanguageVersion]::CSharp12)
$paths = [IO.Directory]::GetFiles($Folder, '*.cs')
[Array]::Sort($paths, [StringComparer]::Ordinal)
foreach ($p in $paths) {
    $u = [Text.UTF8Encoding]::new($false, $true)
    $source = [IO.File]::ReadAllText($p, $u)
    $tree = [Microsoft.CodeAnalysis.CSharp.CSharpSyntaxTree]::ParseText(
        $source, $parse, [IO.Path]::GetFileName($p), $u, $tokens)
    $trees.Add($tree)
}
$options = [Microsoft.CodeAnalysis.CSharp.CSharpCompilationOptions]::new(
    [Microsoft.CodeAnalysis.OutputKind]::DynamicallyLinkedLibrary).WithOptimizationLevel(
    [Microsoft.CodeAnalysis.OptimizationLevel]::Release).WithDeterministic($true)
$unit = [Microsoft.CodeAnalysis.CSharp.CSharpCompilation]::Create($Name, $trees.ToArray(), $references, $options)
$stream = [IO.File]::Create($Output)
try {
    $emit = $unit.Emit($stream, $null, $null, $null, $null,
        [Microsoft.CodeAnalysis.Emit.EmitOptions]::Default, $tokens)
} finally {
    $stream.Dispose()
}
if (-not $emit.Success) {
    $emit.Diagnostics | Where-Object Severity -eq 'Error' | Select-Object -First 5 | ForEach-Object {
        [Console]::Error.WriteLine($_.Id)
    }
    exit 3
}
[Console]::WriteLine($unit.Assembly.Identity.Version.ToString())
