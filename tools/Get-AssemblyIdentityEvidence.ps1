param(
    [Parameter(Mandatory=$true)][string]$RequestPath,
    [Parameter(Mandatory=$true)][string]$OutputPath
)
$ErrorActionPreference = 'Stop'
if (Test-Path -LiteralPath $OutputPath) { throw 'Output must be new.' }
$request = Get-Content -LiteralPath $RequestPath -Raw -Encoding UTF8 | ConvertFrom-Json
$results = @(
    foreach ($path in $request) {
        try {
            # Reads manifest metadata without loading or executing the assembly.
            $identity = [Reflection.AssemblyName]::GetAssemblyName($path)
            $token = ($identity.GetPublicKeyToken() | ForEach-Object { $_.ToString('x2') }) -join ''
            $culture = $identity.CultureName
            if (-not $culture) { $culture = 'neutral' }
            $algorithm = [Security.Cryptography.SHA256]::Create()
            $inputStream = [IO.File]::OpenRead($path)
            try {
                $digest = ([BitConverter]::ToString($algorithm.ComputeHash($inputStream))).Replace('-', '').ToLowerInvariant()
            } finally {
                $inputStream.Dispose()
                $algorithm.Dispose()
            }
            [pscustomobject]@{
                path = $path
                name = $identity.Name
                version = $identity.Version.ToString()
                culture = $culture
                publickeytoken = $token
                processorarchitecture = $identity.ProcessorArchitecture.ToString()
                full_name = $identity.FullName
                sha256 = $digest
                error = ''
            }
        } catch {
            [pscustomobject]@{ path = $path; error = $_.Exception.Message }
        }
    }
)
$json = ConvertTo-Json -InputObject $results -Depth 6
$absolute = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputPath)
$stream = [IO.File]::Open($absolute, [IO.FileMode]::CreateNew, [IO.FileAccess]::Write)
try {
    $bytes = [Text.UTF8Encoding]::new($false).GetBytes($json + "`n")
    $stream.Write($bytes, 0, $bytes.Length)
} finally { $stream.Dispose() }
