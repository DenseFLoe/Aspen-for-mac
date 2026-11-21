# Delete only the disposable scratch directory of one static-review lane and round.
[CmdletBinding()]
param(
    [Parameter(Mandatory)][ValidateSet('audit-1', 'audit-2', 'audit-3', 'audit-4', 'repair')]
    [string] $Lane,
    [Parameter(Mandatory)][ValidatePattern('\A[A-Za-z0-9][A-Za-z0-9_-]{0,95}\z')]
    [string] $Round
)

$ErrorActionPreference = 'Stop'
if ($Round -match '^(CON|PRN|AUX|NUL|COM[0-9]|LPT[0-9])$') {
    throw 'Round must be an ordinary directory name.'
}

$root = [IO.Directory]::GetParent($PSScriptRoot).FullName
$parent = [IO.Path]::GetFullPath((Join-Path $root ".local/static-review/$($Lane.ToLowerInvariant())/$Round"))
$scratch = [IO.Path]::GetFullPath((Join-Path $parent 'scratch'))
if ([IO.Path]::GetDirectoryName($scratch) -ne $parent -or [IO.Path]::GetFileName($scratch) -cne 'scratch') {
    throw "Unexpected scratch path: $scratch"
}

function Assert-OrdinaryPath([string] $Path) {
    # Check the whole chain, including workspace ancestors and links with missing targets.
    $chain = [Collections.Generic.Stack[string]]::new()
    for ($p = $Path; $p; $p = [IO.Path]::GetDirectoryName($p)) {
        $chain.Push($p)
    }
    foreach ($p in $chain) {
        try {
            $attributes = [IO.File]::GetAttributes($p)
        } catch [IO.FileNotFoundException] {
            return $false
        } catch [IO.DirectoryNotFoundException] {
            return $false
        }
        if ($attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw "Refusing reparse point: $p"
        }
    }
    return $true
}

if (-not (Assert-OrdinaryPath $scratch)) {
    Write-Output "Already clear: $scratch"
    return
}
if (-not [IO.Directory]::Exists($scratch)) {
    throw "Expected a directory: $scratch"
}

# Inspect the full tree before removing anything. Enumerate one level at a time.
$pending = [Collections.Generic.Stack[string]]::new()
$directories = [Collections.Generic.Stack[string]]::new()
$files = [Collections.Generic.List[string]]::new()
$pending.Push($scratch)
while ($pending.Count) {
    $dir = $pending.Pop()
    if (-not (Assert-OrdinaryPath $dir)) { throw "Directory changed: $dir" }
    $directories.Push($dir)
    foreach ($entry in [IO.DirectoryInfo]::new($dir).EnumerateFileSystemInfos()) {
        if ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw "Refusing reparse point: $($entry.FullName)"
        }
        if ($entry.Attributes -band [IO.FileAttributes]::Directory) {
            $pending.Push($entry.FullName)
        } else {
            $files.Add($entry.FullName)
        }
    }
}

foreach ($file in $files) {
    if (Assert-OrdinaryPath $file) { [IO.File]::Delete($file) }
}
foreach ($dir in $directories) {
    # A newly added child makes this fail safely, without recursive deletion.
    if (Assert-OrdinaryPath $dir) { [IO.Directory]::Delete($dir, $false) }
}
Write-Output "Cleared $($files.Count) files: $scratch"
