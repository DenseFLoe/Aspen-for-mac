param([string]$Source, [string]$Original, [string]$Resources, [string]$Output)
$ErrorActionPreference='Stop'
Add-Type -Path (Join-Path $PSHOME 'Microsoft.CodeAnalysis.dll')
Add-Type -Path (Join-Path $PSHOME 'Microsoft.CodeAnalysis.CSharp.dll')
$framework='C:/Windows/Microsoft.NET/Framework64/v4.0.30319'
$references=[Collections.Generic.List[Microsoft.CodeAnalysis.MetadataReference]]::new()
foreach($file in 'mscorlib.dll','System.dll','System.Core.dll','System.Xaml.dll','WPF/WindowsBase.dll','WPF/PresentationFramework.dll','WPF/PresentationCore.dll') {
    $references.Add([Microsoft.CodeAnalysis.MetadataReference]::CreateFromFile((Convert-Path -LiteralPath "$framework/$file")))
}
$references.Add([Microsoft.CodeAnalysis.MetadataReference]::CreateFromFile("C:/Windows/Microsoft.NET/assembly/GAC_MSIL/System.Runtime/v4.0_4.0.0.0__b03f5f7f11d50a3a/System.Runtime.dll"))
$side=Split-Path -LiteralPath $Original
foreach($file in 'AspenTech.AspenCxs.CxsViewModel.dll','Microsoft.Practices.Composite.dll','Microsoft.Practices.Unity.dll') {
    $references.Add([Microsoft.CodeAnalysis.MetadataReference]::CreateFromFile((Convert-Path -LiteralPath "$side/$file")))
}
$parse=[Microsoft.CodeAnalysis.CSharp.CSharpSyntaxTree]::ParseText([IO.File]::ReadAllText($Source), [Microsoft.CodeAnalysis.CSharp.CSharpParseOptions]::Default.WithLanguageVersion([Microsoft.CodeAnalysis.CSharp.LanguageVersion]::CSharp10))
$options=[Microsoft.CodeAnalysis.CSharp.CSharpCompilationOptions]::new([Microsoft.CodeAnalysis.OutputKind]::DynamicallyLinkedLibrary)
$options=$options.WithOptimizationLevel([Microsoft.CodeAnalysis.OptimizationLevel]::Release).WithPlatform([Microsoft.CodeAnalysis.Platform]::X64)
$assembly=[Microsoft.CodeAnalysis.CSharp.CSharpCompilation]::Create('AspenTech.AspenPlus.Localization',[Microsoft.CodeAnalysis.SyntaxTree[]]@($parse),$references,$options)
$result=$assembly.GetDiagnostics()
$result | Group-Object Id | ForEach-Object { "$($_.Name): $($_.Count)"; $_.Group[0].ToString() }
if (@($result | Where-Object Severity -eq Error).Count -gt 0) { exit 1 }
$stream=[IO.File]::Create($Output)
try {
    $embedded=[Collections.Generic.List[Microsoft.CodeAnalysis.ResourceDescription]]::new()
    foreach($resourceFile in Get-ChildItem -LiteralPath $Resources -Filter '*.resources') {
        $resourcePath=$resourceFile.FullName
        $provider={ [IO.File]::OpenRead($resourcePath) }.GetNewClosure()
        $embedded.Add([Microsoft.CodeAnalysis.ResourceDescription]::new($resourceFile.Name,[Func[IO.Stream]]$provider,$true))
    }
    $win32=[IO.File]::OpenRead((Join-Path (Split-Path -LiteralPath $Resources) "version.res"))
    try { $emission=$assembly.Emit($stream, $null, $null, $win32, $embedded, $null, [Threading.CancellationToken]::None) } finally { $win32.Dispose() }
    $emission.Diagnostics | ForEach-Object ToString
    if (!$emission.Success) { exit 1 }
} finally { $stream.Dispose() }



