param(
    [Parameter(Mandatory)][string]$Original,
    [Parameter(Mandatory)][string]$Unit
)
$ErrorActionPreference = 'Stop'
$originalHash = (Get-FileHash -LiteralPath $Original).Hash.ToLowerInvariant()
if ($originalHash -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') {
    throw 'Unexpected original SHA-256'
}
Add-Type -AssemblyName System.Reflection.Metadata
$stream = [IO.File]::OpenRead((Resolve-Path -LiteralPath $Original).Path)
$pe = [System.Reflection.PortableExecutable.PEReader]::new($stream)
try {
    $metadata = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
    $tokens = [System.Reflection.Metadata.Ecma335.MetadataTokens]
    function Read-Rva([int]$Rva, [int]$Length) {
        ,([byte[]]$pe.GetSectionData($Rva).GetContent(0, $Length))
    }
    function Read-Method([int]$Rid) {
        $definition = $metadata.GetMethodDefinition($tokens::MethodDefinitionHandle($Rid))
        $body = [System.Reflection.Metadata.PEReaderExtensions]::GetMethodBody($pe, $definition.RelativeVirtualAddress)
        [pscustomobject]@{
            rva = '0x{0:x}' -f $definition.RelativeVirtualAddress
            bytes = [byte[]]$body.GetILBytes()
            exception_regions = $body.ExceptionRegions
        }
    }
    function Read-MethodHex([int]$Rid) { [Convert]::ToHexString((Read-Method $Rid).bytes) }

    $hostIL = Read-MethodHex 0x30
    $releaseIL = Read-MethodHex 0x31
    $caller = Read-Method 0x32
    $callerIL = [Convert]::ToHexString($caller.bytes)
    if ($hostIL.Substring(6, 54) -ne '7F56000004282F0000060D7F55000004282F00000609283900000A' -or
        $hostIL.Substring(0x36 * 2, 0x1e * 2) -ne '064C1F686A584C0C06020829440000110B06254C1F106A584C2943000011' -or
        $releaseIL -ne '02254C1F106A584C2943000011262A' -or
        $callerIL.Substring(6, 14) -ne '12012830000006' -or
        $callerIL.Substring(0x25 * 2, 14) -ne '072831000006DC') {
        throw 'Unexpected managed operand, source, or slot'
    }
    $slotSignatures = foreach ($rid in 0x44, 0x43) {
        $signature = $metadata.GetStandaloneSignature($tokens::StandaloneSignatureHandle($rid))
        [Convert]::ToHexString($metadata.GetBlobBytes($signature.Signature))
    }
    $runtimeMember = $metadata.GetMemberReference($tokens::MemberReferenceHandle(0x39))
    $runtimeParameters = [Runtime.InteropServices.RuntimeEnvironment].GetMethod('GetRuntimeInterfaceAsIntPtr').GetParameters().Name
    if ($metadata.GetString($runtimeMember.Name) -ne 'GetRuntimeInterfaceAsIntPtr' -or ($runtimeParameters -join ',') -ne 'clsid,riid') {
        throw 'Unexpected producer'
    }
    $guids = foreach ($rid in 0x55, 0x56) {
        $field = $metadata.GetFieldDefinition($tokens::FieldDefinitionHandle($rid))
        $rva = $field.GetRelativeVirtualAddress()
        [pscustomobject]@{
            token = '0x040000{0:x2}' -f $rid
            rva = '0x{0:x}' -f $rva
            value = [Guid]::new((Read-Rva $rva 16)).ToString()
        }
    }

    $entries = Import-Csv -LiteralPath (Join-Path $Unit 'calls.csv')
    $listing = Get-Content -LiteralPath (Join-Path $Unit 'code/internal-ctor-sites.il') -Encoding utf8
    $candidateNewobj = @($entries | Where-Object listing -Like 'code/internal-ctor-sites.il#*')
    $constructors = @(
        @(0x20,0,0xa2,'WrapSaveMergeNNFiles.WrapCall'),
        @(0x2b,7,0xae,'<CrtImplementationDetails>.ModuleLoadExceptionHandlerException'),
        @(0x2c,1,0xac,'<CrtImplementationDetails>.ModuleLoadException'),
        @(0x2d,2,0xab,'<CrtImplementationDetails>.ModuleLoadException'),
        @(0xb4,10,0xb5,'<CrtImplementationDetails>.ModuleUninitializer')
    )
    $checked = foreach ($site in $constructors) {
        $callerId, $offset, $calleeId, $owner = $site
        $callerToken = 0x06000000 + $callerId
        $calleeToken = 0x06000000 + $calleeId
        $callerBody = Read-Method $callerId
        $target = $metadata.GetMethodDefinition($tokens::MethodDefinitionHandle($calleeId))
        $declaring = $metadata.GetTypeDefinition($target.GetDeclaringType())
        $declaringName = $metadata.GetString($declaring.Name)
        $declaringNamespace = $metadata.GetString($declaring.Namespace)
        $qualified = if ($declaringNamespace) { "$declaringNamespace.$declaringName" } else { $declaringName }
        $rows = @($candidateNewobj | Where-Object { $_.caller -eq ('0x{0:x8}' -f $callerToken) })
        if ($rows.Count -ne 1 -or $rows[0].listing -notmatch '#L(\d+)-L\1$') { throw 'Missing newobj evidence' }
        $line = [int]$Matches[1]
        if ($callerBody.bytes[$offset] -ne 0x73 -or [BitConverter]::ToInt32($callerBody.bytes, $offset + 1) -ne $calleeToken -or
            $qualified -ne $owner -or $metadata.GetString($target.Name) -ne '.ctor' -or
            $rows[0].class -ne 'boundary' -or $rows[0].callee -notlike ('*0x{0:x8}*{1}::.ctor*' -f $calleeToken,$owner) -or
            $listing[$line - 1] -notmatch ('IL_{0:X4}:\s+newobj\s+0x{1:X8}\b' -f $offset,$calleeToken)) {
            throw 'Original or candidate constructor mismatch'
        }
        [pscustomobject]@{
            caller = '0x{0:x8}' -f $callerToken
            il_offset = '0x{0:x}' -f $offset
            original_rva = $callerBody.rva
            target = '0x{0:x8}' -f $calleeToken
            owner = $qualified
            listing_line = $line
        }
    }

    $span = Read-Rva 0x217f 26
    $lea = Read-Rva 0x29d0 8
    $guardField = 0x29d0 + 7 + [BitConverter]::ToInt32($lea, 3)
    $section = $pe.PEHeaders.SectionHeaders.Where({$guardField -ge $_.VirtualAddress -and $guardField -lt $_.VirtualAddress + $_.VirtualSize}, 'First')[0]
    $sectionCheck = Read-Rva 0x28f3 14
    $dispatch = Read-Rva 0x21a4 13
    $dispatchSlot = Read-Rva 0x61b8 8
    if ([Convert]::ToHexString($span) -ne 'E84C080000488BD8488338007424488BC8E8DF06000084C07418' -or
        [Convert]::ToHexString($dispatch) -ne '488B034C8B0D0A40000041FFD1' -or
        [Convert]::ToHexString($sectionCheck) -ne '837A24007D0432C0EB0AB001EB06' -or
        [Convert]::ToHexString((Read-Rva 0x48b0 2)) -ne 'FFE0' -or
        [BitConverter]::ToUInt64($dispatchSlot, 0) -ne 0x1800048b0 -or $guardField -ne 0x19b78 -or
        $section.Name -ne '.data' -or [uint32]$section.SectionCharacteristics -ne 0xc0000040u -or
        $guardField -lt $section.VirtualAddress + $section.SizeOfRawData) {
        throw 'Native original facts differ'
    }

    $releaseRow = $entries | Where-Object listing -EQ 'code/methods.il#L1195-L1195'
    $nativeRow = $entries | Where-Object listing -EQ 'code/native.asm#L258-L258'
    $receipts = Get-Content -Raw -LiteralPath (Join-Path $Unit 'code/s29-fingerprints.json') | ConvertFrom-Json -AsHashtable
    $mismatches = foreach ($item in $receipts.GetEnumerator()) {
        $file = Join-Path $Unit $item.Key
        $observed = if (Test-Path -LiteralPath $file -PathType Leaf) { (Get-FileHash -LiteralPath $file).Hash.ToLowerInvariant() } else { $null }
        if ($observed -ne $item.Value) {
            [pscustomobject]@{ path = $item.Key; declared = $item.Value; observed = $observed }
        }
    }
    $classes = $entries | Group-Object class -AsHashTable
    $unresolved = $classes['unresolved']
    $managedAnnex = Import-Csv -LiteralPath (Join-Path $Unit 'code/s25-unresolved-managed.csv')
    $nativeAnnex = Import-Csv -LiteralPath (Join-Path $Unit 'code/s25-unresolved-native.csv')
    $listedButBound = $managedAnnex | Where-Object { $_.listing -notin $unresolved.listing }
    $metrics = Get-Content -Raw -LiteralPath (Join-Path $Unit 'metrics.json') | ConvertFrom-Json

    [pscustomobject]@{
        original_sha256 = $originalHash
        host = [pscustomobject]@{
            il = $hostIL
            signature_blobs = $slotSignatures
            clsid = $guids[0]
            riid = $guids[1]
        }
        original_release = [pscustomobject]@{
            il = $releaseIL
            caller_method_0x06000032_il = $callerIL
            caller_finally_offsets = @($caller.exception_regions | Select-Object Kind,TryOffset,TryLength,HandlerOffset,HandlerLength)
            slot = '0x10'
            signature_token = '0x11000043'
            receiver = 'argument zero; local MethodDef 0x06000032 passes loc1 populated through 0x06000030'
            candidate = $releaseRow
        }
        constructors = $checked
        original_callback = [pscustomobject]@{
            bytes_217f = [Convert]::ToHexString($span)
            bytes_21a4 = [Convert]::ToHexString($dispatch)
            bytes_28f3 = [Convert]::ToHexString($sectionCheck)
            callback_slot = '0x{0:x}' -f $guardField
            writable_section = $section.Name
            flags = '0x{0:x8}' -f [uint32]$section.SectionCharacteristics
            section_raw_end = '0x{0:x}' -f ($section.VirtualAddress + $section.SizeOfRawData)
            section_virtual_end = '0x{0:x}' -f ($section.VirtualAddress + $section.VirtualSize)
            guards = @('0x2187/0x218b null', '0x2190 call 0x2874 tests nonwritable section, 0x2197 skips')
            transfer = '0x21a4 loads RAX from fixed slot once; 0x21ae calls R9 at 0x48b0, which jumps to RAX'
            candidate = $nativeRow
            candidate_asserts_second_vtable_read = $nativeRow.callee -match 'vtable slot 0'
        }
        candidate_calls = $entries.Count
        candidate_boundary = $classes['boundary'].Count
        candidate_external = $classes['external'].Count
        candidate_managed_unresolved = @($unresolved | Where-Object kind -EQ method).Count
        candidate_native_unresolved = @($unresolved | Where-Object kind -EQ native).Count
        old_managed_annex = $managedAnnex.Count
        old_native_annex = $nativeAnnex.Count
        old_managed_annex_already_bound_sites = @($listedButBound.listing)
        candidate_s29_ctor_rows_added = $metrics.s29_ctor_rows_added
        fingerprint_count = $receipts.Count
        fingerprint_mismatches = @($mismatches)
    } | ConvertTo-Json -Depth 7
} finally {
    $pe.Dispose()
    $stream.Dispose()
}
