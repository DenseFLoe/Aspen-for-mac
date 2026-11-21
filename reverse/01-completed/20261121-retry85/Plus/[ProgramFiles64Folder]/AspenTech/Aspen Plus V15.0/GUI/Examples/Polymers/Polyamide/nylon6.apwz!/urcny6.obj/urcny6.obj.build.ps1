[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$Nasm,
    [Parameter(Mandatory)][string]$OutputPath
)

$ErrorActionPreference = 'Stop'
$assembler = (Get-Command $Nasm -CommandType Application).Source
$destination = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputPath)
if (Test-Path -LiteralPath $destination) { throw "Output already exists: $destination" }
$stage = Join-Path ([IO.Path]::GetDirectoryName($destination)) ('.urcny6-' + [guid]::NewGuid())
$stagedSource = Join-Path $stage 'urcny6.obj.asm'
$temp = Join-Path $stage 'urcny6.obj'
[void][IO.Directory]::CreateDirectory($stage)

try {
    # NASM on Windows can reject the fully nested archive input path.
    [IO.File]::Copy((Join-Path $PSScriptRoot 'urcny6.obj.asm'), $stagedSource)
    Push-Location -LiteralPath $stage
    try {
        & $assembler -f win64 urcny6.obj.asm -o urcny6.obj
        if ($LASTEXITCODE -ne 0) { throw "NASM exited with code $LASTEXITCODE" }
    } finally {
        Pop-Location
    }

    $bytes = [IO.File]::ReadAllBytes($temp)
    if ([BitConverter]::ToUInt16($bytes, 0) -ne 0x8664 -or
        [BitConverter]::ToUInt16($bytes, 16) -ne 0) {
        throw 'Expected a Windows AMD64 COFF object without an optional header.'
    }

    # Match the original section flags for both read-only unwind tables.
    $sectionCount = [BitConverter]::ToUInt16($bytes, 2)
    $patchedSections = 0
    for ($index = 0; $index -lt $sectionCount; $index++) {
        $section = 20 + 40 * $index
        $name = [Text.Encoding]::ASCII.GetString($bytes, $section, 8).TrimEnd([char]0)
        if ($name -in '.pdata', '.xdata') {
            $flags = [BitConverter]::ToUInt32($bytes, $section + 36)
            $flags = $flags -band ([uint32]::MaxValue -bxor [uint32]0x40)
            [BitConverter]::GetBytes($flags).CopyTo($bytes, $section + 36)
            $patchedSections++
        }
    }

    # Preserve the original function-type marker on these two COFF symbols.
    $symbolTable = [BitConverter]::ToUInt32($bytes, 8)
    $symbolCount = [BitConverter]::ToUInt32($bytes, 12)
    $patchedSymbols = 0
    for ($index = 0; $index -lt $symbolCount;) {
        $symbol = $symbolTable + 18 * $index
        $name = [Text.Encoding]::ASCII.GetString($bytes, $symbol, 8).TrimEnd([char]0)
        if ([BitConverter]::ToUInt32($bytes, $symbol) -eq 0) {
            $stringStart = $symbolTable + 18 * $symbolCount
            $start = $stringStart + [BitConverter]::ToUInt32($bytes, $symbol + 4)
            $length = [Array]::IndexOf($bytes, [byte]0, [int]$start) - $start
            $name = [Text.Encoding]::ASCII.GetString($bytes, $start, $length)
        }
        if ($name -in 'URCNY6', '__ImageBase') {
            [BitConverter]::GetBytes([uint16]0x20).CopyTo($bytes, $symbol + 14)
            $patchedSymbols++
        }
        $index += 1 + $bytes[$symbol + 