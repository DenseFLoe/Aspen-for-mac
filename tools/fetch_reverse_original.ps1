[CmdletBinding()]
param(
    [Parameter(Mandatory)][ValidatePattern('^[0-9a-f]{40}$')][string]$Commit,
    [Parameter(Mandatory)][string]$RepositoryPath,
    [Parameter(Mandatory)][ValidatePattern('^[0-9a-f]{64}$')][string]$Sha256,
    [Parameter(Mandatory)][string]$InputDirectory,
    [switch]$LargeFile
)

$ErrorActionPreference = 'Stop'
$segments = $RepositoryPath.Split('/')
if ($segments[0] -cne '原版文件' -or $segments.Count -lt 3 -or
    ($segments | Where-Object { $_ -in @('', '.', '..') -or $_ -match '[:\\]' })) {
    throw 'RepositoryPath must name a file inside 原版文件.'
}

$encodedPath = ($segments | ForEach-Object { [Uri]::EscapeDataString($_) }) -join '/'
$baseUri = if ($LargeFile) {
    'https://media.githubusercontent.com/media/DenseFLoe/Aspen-for-mac'
} else {
    'https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac'
}
$downloadUri = "$baseUri/$Commit/$encodedPath"
$inputFolder = New-Item -ItemType Directory -Path $InputDirectory -Force
$file = Join-Path $inputFolder.FullName $segments[-1]

if (Test-Path -LiteralPath $file -PathType Leaf) {
    if ((Get-FileHash -LiteralPath $file -Algorithm SHA256).Hash -ine $Sha256) {
        throw "Existing file does not match the expected SHA-256: $file"
    }
    Get-Item -LiteralPath $file
    return
}

$temporaryFile = Join-Path $inputFolder.FullName ('.download-' + [Guid]::NewGuid().ToString('N'))
try {
    & curl.exe --fail --silent --show-error --location --retry 2 --connect-timeout 20 --output $temporaryFile $downloadUri
    if ($LASTEXITCODE -ne 0) { throw "Could not download repository path: $RepositoryPath" }
    if ((Get-FileHash -LiteralPath $temporaryFile -Algorithm SHA256).Hash -ine $Sha256) {
        throw "Downloaded content does not match the expected SHA-256: $RepositoryPath"
    }
    Move-Item -LiteralPath $temporaryFile -Destination $file
    Get-Item -LiteralPath $file
} finally {
    if (Test-Path -LiteralPath $temporaryFile -PathType Leaf) {
        Remove-Item -LiteralPath $temporaryFile
    }
}

