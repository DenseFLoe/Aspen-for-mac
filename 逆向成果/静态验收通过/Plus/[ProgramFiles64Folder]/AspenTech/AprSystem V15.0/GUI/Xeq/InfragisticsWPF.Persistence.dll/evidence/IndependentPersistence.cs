using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Resources;
using System.Security.Cryptography;
using System.Text;

public static class IndependentPersistence
{
    static string Hash(byte[] b) => Convert.ToHexString(SHA256.HashData(b)).ToLowerInvariant();
    static string Token(int token) => token.ToString("x8");
    static string Token(EntityHandle handle) => Token(MetadataTokens.GetToken(handle));
    static byte[] At(PEReader pe, int rva, int length) => pe.GetSectionData(rva).GetContent(0, length).ToArray();
    static int FileOffset(PEReader pe, int rva)
    {
        var s = pe.PEHeaders.SectionHeaders.Single(section => rva >= section.VirtualAddress &&
            (long)rva - section.VirtualAddress < section.SizeOfRawData);
        return checked(s.PointerToRawData + rva - s.VirtualAddress);
    }
    static string Label(MetadataReader md, EntityHandle handle)
    {
        switch (handle.Kind)
        {
            case HandleKind.TypeDefinition:
                var td = md.GetTypeDefinition((TypeDefinitionHandle)handle);
                return (td.GetDeclaringType().IsNil ? md.GetString(td.Namespace) : Label(md, td.GetDeclaringType())) +
                    "." + md.GetString(td.Name);
            case HandleKind.TypeReference:
                var tr = md.GetTypeReference((TypeReferenceHandle)handle);
                return (tr.ResolutionScope.Kind == HandleKind.TypeReference ? Label(md, tr.ResolutionScope) : md.GetString(tr.Namespace)) +
                    "." + md.GetString(tr.Name);
            case HandleKind.MethodDefinition:
                var d = md.GetMethodDefinition((MethodDefinitionHandle)handle);
                return Label(md, d.GetDeclaringType()) + "::" + md.GetString(d.Name);
            case HandleKind.MemberReference:
                var m = md.GetMemberReference((MemberReferenceHandle)handle);
                return Label(md, m.Parent) + "::" + md.GetString(m.Name);
            case HandleKind.MethodSpecification:
                var ms = md.GetMethodSpecification((MethodSpecificationHandle)handle);
                return Label(md, ms.Method) + "<" + Convert.ToHexString(md.GetBlobBytes(ms.Signature)) + ">";
            case HandleKind.TypeSpecification:
                return "TypeSpec:" + Convert.ToHexString(md.GetBlobBytes(md.GetTypeSpecification((TypeSpecificationHandle)handle).Signature));
            default:
                return handle.Kind + ":" + Token(handle);
        }
    }
    static readonly Dictionary<int, OpCode> Opcodes = typeof(OpCodes).GetFields(BindingFlags.Public | BindingFlags.Static)
        .Where(f => f.FieldType == typeof(OpCode)).Select(f => (OpCode)f.GetValue(null))
        .ToDictionary(o => (int)(ushort)o.Value);
    static (object[] Calls, object Flip) Decode(MetadataReader md, byte[] il, int fileOffset)
    {
        var calls = new List<object>();
        object flip = null;
        for (int cursor = 0; cursor < il.Length;)
        {
            int start = cursor;
            int id = il[cursor++];
            if (id == 0xfe) id = 0xfe00 + il[cursor++];
            var op = Opcodes[id];
            int n;
            switch (op.OperandType)
            {
                case OperandType.InlineNone: n = 0; break;
                case OperandType.ShortInlineBrTarget:
                case OperandType.ShortInlineI:
                case OperandType.ShortInlineVar: n = 1; break;
                case OperandType.InlineVar: n = 2; break;
                case OperandType.InlineI8:
                case OperandType.InlineR: n = 8; break;
                case OperandType.InlineSwitch: n = checked(4 + 4 * BitConverter.ToInt32(il, cursor)); break;
                default: n = 4; break;
            }
            if (n < 0 || cursor + n > il.Length) throw new BadImageFormatException("Invalid operand extent");
            if (op.OperandType == OperandType.InlineMethod)
            {
                int token = BitConverter.ToInt32(il, cursor);
                var h = MetadataTokens.EntityHandle(token);
                if (h.IsNil) throw new BadImageFormatException("Missing operand token");
                calls.Add(new { il_offset = start, opcode = op.Name, token = Token(token), target = Label(md, h) });
            }
            if ((id == 0x16 || id == 0x17) && cursor < il.Length && il[cursor] == 0x2a && flip == null)
                flip = new { il_offset = start, file_offset = fileOffset + start, initial = id, modified = id == 0x16 ? 0x17 : 0x16 };
            cursor += n;
        }
        return (calls.ToArray(), flip);
    }
    static object[] WinResources(PEReader pe, DirectoryEntry dir)
    {
        if (dir.Size == 0) return Array.Empty<object>();
        var section = At(pe, dir.RelativeVirtualAddress, dir.Size);
        var entries = new List<object>();
        var visited = new HashSet<uint>();
        void Walk(uint offset, string current, int depth)
        {
            if (!visited.Add(offset) || depth > 2) throw new BadImageFormatException("Resource directory cycle or depth");
            int at = checked((int)offset);
            int count = BitConverter.ToUInt16(section, at + 12) + BitConverter.ToUInt16(section, at + 14);
            for (int i = 0; i < count; i++)
            {
                int pos = at + 16 + 8 * i;
                uint id = BitConverter.ToUInt32(section, pos);
                uint next = BitConverter.ToUInt32(section, pos + 4);
                string name;
                if ((id & 0x80000000u) != 0)
                {
                    int off = (int)(id & 0x7fffffffu);
                    name = "name:" + Encoding.Unicode.GetString(section, off + 2, 2 * BitConverter.ToUInt16(section, off));
                }
                else name = id.ToString();
                string path = current + "/" + name;
                if ((next & 0x80000000u) != 0) Walk(next & 0x7fffffffu, path, depth + 1);
                else
                {
                    if (depth != 2) throw new BadImageFormatException("Incomplete resource path");
                    int off = checked((int)next);
                    int rva = BitConverter.ToInt32(section, off);
                    int length = BitConverter.ToInt32(section, off + 4);
                    var payload = At(pe, rva, length);
                    entries.Add(new { path, length, code_page = BitConverter.ToUInt32(section, off + 8),
                        reserved = BitConverter.ToUInt32(section, off + 12), sha256 = Hash(payload) });
                }
            }
        }
        Walk(0, "", 0);
        return entries.ToArray();
    }
    static string TextAt(PEReader pe, int rva)
    {
        var data = pe.GetSectionData(rva).GetContent().ToArray();
        return Encoding.ASCII.GetString(data, 0, Array.IndexOf(data, (byte)0));
    }
    static object[] Imports(PEReader pe, PEHeader hdr)
    {
        var result = new List<object>();
        if (hdr.ImportTableDirectory.Size == 0) return result.ToArray();
        var b = At(pe, hdr.ImportTableDirectory.RelativeVirtualAddress, hdr.ImportTableDirectory.Size);
        for (int i = 0; i + 20 <= b.Length; i += 20)
        {
            int ilt = BitConverter.ToInt32(b, i);
            int name = BitConverter.ToInt32(b, i + 12);
            int iat = BitConverter.ToInt32(b, i + 16);
            if (ilt == 0 && name == 0 && iat == 0) return result.ToArray();
            var table = pe.GetSectionData(ilt == 0 ? iat : ilt).GetContent().ToArray();
            var symbols = new List<string>();
            bool plus = hdr.Magic == PEMagic.PE32Plus;
            int width = plus ? 8 : 4;
            ulong byOrdinal = plus ? 0x8000000000000000UL : 0x80000000UL;
            for (int j = 0; j + width <= table.Length; j += width)
            {
                ulong v = plus ? BitConverter.ToUInt64(table, j) : BitConverter.ToUInt32(table, j);
                if (v == 0) break;
                symbols.Add((v & byOrdinal) != 0 ? "#" + (v & 0xffffUL) : TextAt(pe, checked((int)v + 2)));
            }
            result.Add(new { module = TextAt(pe, name), symbols });
        }
        throw new BadImageFormatException("Unterminated imports");
    }
    public static object Inspect(string path)
    {
        var file = File.ReadAllBytes(path);
        using var pe = new PEReader(new MemoryStream(file, false));
        var md = pe.GetMetadataReader(MetadataReaderOptions.None);
        var hdr = pe.PEHeaders.PEHeader;
        var cor = pe.PEHeaders.CorHeader;
        byte[] meta = pe.GetMetadata().GetContent().ToArray();
        var mod = md.GetModuleDefinition();
        if (md.GetTableRowCount(TableIndex.Module) != 1 || mod.Mvid.IsNil || mod.Mvid == mod.GenerationId || mod.Mvid == mod.BaseGenerationId)
            throw new BadImageFormatException("MVID slot not isolated");
        Array.Clear(meta, md.GetHeapMetadataOffset(HeapIndex.Guid) + (MetadataTokens.GetHeapOffset(mod.Mvid) - 1) * 16, 16);
        var methods = new List<object>();
        var events = new List<object>();
        int ehCount = 0, bodyCount = 0, abstractCount = 0, pinvokeCount = 0, callCount = 0;
        object control = null;
        foreach (var h in md.MethodDefinitions)
        {
            int row = MetadataTokens.GetRowNumber(h);
            Array.Clear(meta, md.GetTableMetadataOffset(TableIndex.MethodDef) + (row - 1) * md.GetTableRowSize(TableIndex.MethodDef), 4);
            var m = md.GetMethodDefinition(h);
            bool isAbstract = m.Attributes.HasFlag(MethodAttributes.Abstract);
            bool pinvoke = m.Attributes.HasFlag(MethodAttributes.PinvokeImpl);
            if (isAbstract) abstractCount++;
            if (pinvoke) pinvokeCount++;
            var parameters = m.GetParameters().Select(p =>
            {
                var v = md.GetParameter(p);
                return new { row = MetadataTokens.GetRowNumber(p), name = md.GetString(v.Name), attrs = (int)v.Attributes, position = v.SequenceNumber };
            }).ToArray();
            object body = null;
            int rva = m.RelativeVirtualAddress;
            if (rva != 0)
            {
                bodyCount++;
                var b = pe.GetMethodBody(rva);
                var il = b.GetILBytes();
                var full = At(pe, rva, b.Size);
                int header = (full[0] & 3) == 2 ? 1 : (full[1] >> 4) * 4;
                var decoded = Decode(md, il, FileOffset(pe, rva) + header);
                if (control == null && decoded.Flip != null && md.MethodDefinitions.Count(q => md.GetMethodDefinition(q).RelativeVirtualAddress == rva) == 1)
                    control = new { method = Label(md, h), token = Token(h), change = decoded.Flip };
                var regions = b.ExceptionRegions.Select(e => new { kind = e.Kind.ToString(), e.TryOffset, e.TryLength, e.HandlerOffset,
                    e.HandlerLength, catch_token = Token(e.CatchType), e.FilterOffset }).ToArray();
                ehCount += regions.Length;
                callCount += decoded.Calls.Length;
                body = new { sha256 = Hash(full), il_sha256 = Hash(il), il_bytes = il.Length, b.Size, b.MaxStack, b.LocalVariablesInitialized,
                    local_signature = b.LocalSignature.IsNil ? null : Convert.ToHexString(md.GetBlobBytes(md.GetStandaloneSignature(b.LocalSignature).Signature)),
                    regions, calls = decoded.Calls };
            }
            methods.Add(new { token = Token(h), name = Label(md, h), attrs = (int)m.Attributes, impl = (int)m.ImplAttributes,
                sig = Convert.ToHexString(md.GetBlobBytes(m.Signature)), parameters, body });
        }
        foreach (var t in md.TypeDefinitions)
        {
            foreach (var h in md.GetTypeDefinition(t).GetEvents())
            {
                var e = md.GetEventDefinition(h);
                var accessors = e.GetAccessors();
                events.Add(new { name = md.GetString(e.Name), type = Label(md, e.Type), owner = Label(md, t),
                    add = Label(md, accessors.Adder), remove = Label(md, accessors.Remover) });
            }
        }
        var managed = new List<object>();
        foreach (var h in md.ManifestResources)
        {
            var m = md.GetManifestResource(h);
            if (!m.Implementation.IsNil) throw new BadImageFormatException("External resource");
            var resourceStart = checked(cor.ResourcesDirectory.RelativeVirtualAddress + (int)m.Offset);
            int size = BitConverter.ToInt32(At(pe, resourceStart, 4));
            var payload = At(pe, resourceStart + 4, size);
            var values = new List<object>();
            using var rr = new ResourceReader(new MemoryStream(payload, false));
            var it = rr.GetEnumerator();
            while (it.MoveNext())
            {
                string key = (string)it.Key;
                rr.GetResourceData(key, out var type, out var raw);
                string value = null;
                if (type == "ResourceTypeCode.String")
                {
                    using var br = new BinaryReader(new MemoryStream(raw, false), Encoding.UTF8);
                    value = br.ReadString();
                }
                values.Add(new { key, type, value });
            }
            managed.Add(new { name = md.GetString(m.Name), attrs = (int)m.Attributes, size, sha256 = Hash(payload), values });
        }
        var native = WinResources(pe, hdr.ResourceTableDirectory);
        var refs = md.AssemblyReferences.Select(h => {
            var a = md.GetAssemblyReference(h);
            return new { name = md.GetString(a.Name), version = a.Version.ToString(), public_key_or_token = Convert.ToHexString(md.GetBlobBytes(a.PublicKeyOrToken)) };
        }).ToArray();
        var publicKey = md.GetBlobBytes(md.GetAssemblyDefinition().PublicKey);
        var vars = new { method_defs = md.MethodDefinitions.Count, bodyCount, abstractCount, ehCount, callCount,
            pinvoke_count = pinvokeCount, impl_map = md.GetTableRowCount(TableIndex.ImplMap), types = md.TypeDefinitions.Count,
            parameters = md.GetTableRowCount(TableIndex.Param), fields = md.FieldDefinitions.Count, properties = md.PropertyDefinitions.Count,
            field_rva = md.GetTableRowCount(TableIndex.FieldRva) };
        var context = new { clr_flags = (int)cor.Flags, clr_entry = cor.EntryPointTokenOrRelativeVirtualAddress, native_header = cor.ManagedNativeHeaderDirectory.Size,
            machine = pe.PEHeaders.CoffHeader.Machine.ToString(), pe_magic = hdr.Magic.ToString(), subsystem = hdr.Subsystem.ToString(),
            entry_stub = Convert.ToHexString(At(pe, hdr.AddressOfEntryPoint, 6)), imports = Imports(pe, hdr), public_key_sha256 = Hash(publicKey) };
        var signatures = new { signed_directory_bytes = cor.StrongNameSignatureDirectory.Size,
            nonzero_strong_name = At(pe, cor.StrongNameSignatureDirectory.RelativeVirtualAddress, cor.StrongNameSignatureDirectory.Size).Any(b => b != 0),
            authenticode_directory_bytes = hdr.CertificateTableDirectory.Size, mvid = md.GetGuid(mod.Mvid).ToString() };
        return new {
            file_sha256 = Hash(file), size = file.Length, normalized_metadata = Hash(meta), vars, methods, refs, events, managed, native, context, signatures,
            type_defs = md.TypeDefinitions.Select(h => Label(md, h)).ToArray(),
            windows_refs = md.TypeReferences.Select(h => Label(md, h)).Where(n => n.StartsWith("System.Windows.", StringComparison.Ordinal)).ToArray(), control
        };
    }
}
