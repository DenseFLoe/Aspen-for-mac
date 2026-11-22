using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using System.Text;

// All reads use ECMA-335 metadata and PE mappings. Never load the input assembly.
public static class ManagedEvidence
{
    static readonly Dictionary<ushort, OpCode> Ops = typeof(OpCodes).GetFields()
        .Where(f => f.FieldType == typeof(OpCode))
        .Select(f => (OpCode)f.GetValue(null))
        .ToDictionary(op => unchecked((ushort)op.Value));

    static string Hash(byte[] bytes) => Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant();
    static string Pack(string tag, params string[] values) =>
        tag + "(" + string.Concat(values.Select(s => s.Length + ":" + s)) + ")";

    sealed class SignatureNames : ISignatureTypeProvider<string, int>
    {
        readonly MetadataReader r;
        public SignatureNames(MetadataReader reader) { r = reader; }
        public string Def(TypeDefinitionHandle h, int depth = 0)
        {
            if (depth > 128) throw new BadImageFormatException("cyclic/deep TypeDef");
            var t = r.GetTypeDefinition(h);
            var parent = t.GetDeclaringType();
            return Pack("type", parent.IsNil ? "" : Def(parent, depth + 1), r.GetString(t.Namespace), r.GetString(t.Name));
        }
        string Ref(TypeReferenceHandle h, int depth)
        {
            if (depth > 128) throw new BadImageFormatException("cyclic/deep TypeRef");
            var t = r.GetTypeReference(h);
            var scope = t.ResolutionScope;
            string name = "";
            if (!scope.IsNil)
            {
                switch (scope.Kind)
                {
                    case HandleKind.TypeReference: name = Ref((TypeReferenceHandle)scope, depth + 1); break;
                    case HandleKind.ModuleReference: name = Pack("module", r.GetString(r.GetModuleReference((ModuleReferenceHandle)scope).Name)); break;
                    case HandleKind.ModuleDefinition: name = "self"; break;
                    case HandleKind.AssemblyReference:
                        var a = r.GetAssemblyReference((AssemblyReferenceHandle)scope);
                        name = Pack("assembly", r.GetString(a.Name), a.Version.ToString(), r.GetString(a.Culture),
                                    ((int)a.Flags).ToString(), Convert.ToHexString(r.GetBlobBytes(a.PublicKeyOrToken)));
                        break;
                    default: throw new BadImageFormatException("invalid type reference scope");
                }
            }
            return Pack("ref", name, r.GetString(t.Namespace), r.GetString(t.Name));
        }
        public string Signature(MethodSignature<string> s) => Pack("sig", s.Header.RawValue.ToString(), s.GenericParameterCount.ToString(),
            s.RequiredParameterCount.ToString(), s.ReturnType, Pack("args", s.ParameterTypes.ToArray()));
        public string GetTypeFromDefinition(MetadataReader r, TypeDefinitionHandle h, byte k) => Pack(k.ToString(), Def(h));
        public string GetTypeFromReference(MetadataReader r, TypeReferenceHandle h, byte k) => Pack(k.ToString(), Ref(h, 0));
        public string GetTypeFromSpecification(MetadataReader r, int context, TypeSpecificationHandle h, byte k) {
            if (context > 64) throw new BadImageFormatException("cyclic/deep TypeSpec");
            return Pack(k.ToString(), r.GetTypeSpecification(h).DecodeSignature(this, context + 1));
        }
        public string GetArrayType(string t, ArrayShape s) => Pack("array", t, s.Rank.ToString(), string.Join(",",s.Sizes),string.Join(",",s.LowerBounds));
        public string GetByReferenceType(string t) => Pack("byref", t);
        public string GetFunctionPointerType(MethodSignature<string> t) => Pack("fn", Signature(t));
        public string GetGenericInstantiation(string t, ImmutableArray<string> args) => Pack("inst", t, Pack("args",args.ToArray()));
        public string GetGenericMethodParameter(int c, int i) => "!!"+i;
        public string GetGenericTypeParameter(int c, int i) => "!"+i;
        public string GetModifiedType(string m, string t, bool required) => Pack(required ? "modreq" : "modopt", m, t);
        public string GetPinnedType(string t) => Pack("pinned", t);
        public string GetPointerType(string t) => Pack("ptr", t);
        public string GetPrimitiveType(PrimitiveTypeCode t) => t.ToString();
        public string GetSZArrayType(string t) => Pack("szarray",t);
    }

    static string MetadataDigest(PEReader pe, MetadataReader r)
    {
        byte[] bytes = pe.GetMetadata().GetContent().ToArray();
        // RVA is a physical locator. Every MethodDef body is checked separately.
        int start = r.GetTableMetadataOffset(TableIndex.MethodDef);
        int stride = r.GetTableRowSize(TableIndex.MethodDef);
        for (int i = 0; i < r.MethodDefinitions.Count; i++) Array.Clear(bytes, checked(start+i*stride), 4);
        // A fresh assembly build may generate a new module version ID. Only erase
        // its actual, uniquely owned #GUID slot. Leave every other heap bit intact.
        var mod = r.GetModuleDefinition();
        bool hasDebugTables = Enumerable.Range(48, 8).Any(i => r.GetTableRowCount((TableIndex)i) != 0);
        if (!hasDebugTables && r.GetTableRowCount(TableIndex.Module) == 1 && !mod.Mvid.IsNil &&
            mod.Mvid != mod.GenerationId && mod.Mvid != mod.BaseGenerationId)
        {
            int index = MetadataTokens.GetHeapOffset(mod.Mvid);
            int offset = checked(r.GetHeapMetadataOffset(HeapIndex.Guid) + 16*(index-1));
            Array.Clear(bytes,offset,16);
        }
        return Hash(bytes);
    }

    static void Require(bool ok, string message) { if (!ok) throw new BadImageFormatException(message); }
    static void ValidateToken(MetadataReader r, int token, OperandType kind)
    {
        if (kind == OperandType.InlineString)
        {
            Require((uint)token >> 24 == 0x70 && (token & 0xffffff) != 0, "invalid #US token");
            r.GetUserString(MetadataTokens.UserStringHandle(token & 0xffffff));
            return;
        }
        var h = MetadataTokens.EntityHandle(token);
        int row = token & 0xffffff;
        Require(row > 0 && row <= r.GetTableRowCount((TableIndex)((uint)token >> 24)), "out-of-range metadata token");
        bool meth = h.Kind == HandleKind.MethodDefinition || h.Kind == HandleKind.MethodSpecification;
        bool field = h.Kind == HandleKind.FieldDefinition;
        if (h.Kind == HandleKind.MemberReference)
        {
            var mk = r.GetMemberReference((MemberReferenceHandle)h).GetKind();
            meth = mk == MemberReferenceKind.Method; field = mk == MemberReferenceKind.Field;
        }
        bool type = h.Kind == HandleKind.TypeDefinition || h.Kind == HandleKind.TypeReference || h.Kind == HandleKind.TypeSpecification;
        bool sig = h.Kind == HandleKind.StandaloneSignature;
        Require((kind == OperandType.InlineMethod && meth) || (kind == OperandType.InlineField && field) ||
                (kind == OperandType.InlineType && type) || (kind == OperandType.InlineTok && (meth || field || type)) ||
                (kind == OperandType.InlineSig && sig && r.GetStandaloneSignature((StandaloneSignatureHandle)h).GetKind() == StandaloneSignatureKind.Method),
                "operand token of wrong kind");
    }

    static void Body(MetadataReader r, MethodBodyBlock body, Dictionary<string,object> row)
    {
        byte[] il = body.GetILBytes();
        Require(il != null && il.Length > 0, "empty CIL body");
        var starts = new HashSet<int>(); var targets = new List<int>();
        int p=0, prefixCount=0; bool previousPrefix=false;
        while (p < il.Length)
        {
            // Branch and EH targets can only point to the first prefix of a prefixed instruction.
            if (!previousPrefix) starts.Add(p);
            ushort op = il[p++];
            if (op == 0xfe) { Require(p < il.Length,"truncated long opcode"); op = (ushort)(0xfe00 | il[p++]); }
            Require(Ops.TryGetValue(op, out var code) && code.OpCodeType != OpCodeType.Nternal, "invalid/reserved IL opcode");
            previousPrefix = code.OpCodeType == OpCodeType.Prefix;
            if (previousPrefix) prefixCount++;
            int size=0;
            switch (code.OperandType)
            {
                case OperandType.InlineNone: break;
                case OperandType.ShortInlineVar: case OperandType.ShortInlineI: size=1; break;
                case OperandType.InlineVar: size=2; break;
                case OperandType.InlineI: case OperandType.ShortInlineR: size=4; break;
                case OperandType.InlineI8: case OperandType.InlineR: size=8; break;
                case OperandType.InlineMethod: case OperandType.InlineField: case OperandType.InlineType:
                case OperandType.InlineSig: case OperandType.InlineTok: case OperandType.InlineString:
                    Require(p <= il.Length-4, "truncated metadata token");
                    ValidateToken(r, BitConverter.ToInt32(il,p), code.OperandType); size=4; break;
                case OperandType.ShortInlineBrTarget:
                    Require(p < il.Length, "truncated short branch");
                    targets.Add(checked(p+1+unchecked((sbyte)il[p]))); size=1; break;
                case OperandType.InlineBrTarget:
                    Require(p <= il.Length-4, "truncated branch");
                    targets.Add(checked(p+4+BitConverter.ToInt32(il,p))); size=4; break;
                case OperandType.InlineSwitch:
                    Require(p <= il.Length-4, "truncated switch count");
                    int n=BitConverter.ToInt32(il,p);
                    Require(n>=0 && n <= (il.Length-p-4)/4, "invalid switch count");
                    size=4+4*n;
                    for(int i=0;i<n;i++) targets.Add(checked(p+size+BitConverter.ToInt32(il,p+4+4*i)));
                    break;
                default: throw new BadImageFormatException("unsupported IL operand");
            }
            Require(p <= il.Length-size, "truncated operand");
            p += size;
        }
        Require(!previousPrefix && targets.All(starts.Contains),"invalid prefix or branch target");
        string locals = "";
        if (!body.LocalSignature.IsNil)
        {
            var sig = r.GetStandaloneSignature(body.LocalSignature);
            Require(sig.GetKind() == StandaloneSignatureKind.LocalVariables,"invalid local signature");
            locals = Convert.ToHexString(r.GetBlobBytes(sig.Signature));
        }
        var eh = new List<string>();
        foreach(var region in body.ExceptionRegions)
        {
            int te=checked(region.TryOffset+region.TryLength), he=checked(region.HandlerOffset+region.HandlerLength);
            Require(region.TryLength>0 && region.HandlerLength>0 && starts.Contains(region.TryOffset) && starts.Contains(region.HandlerOffset)
                && (te==il.Length || starts.Contains(te)) && (he==il.Length || starts.Contains(he)), "invalid EH boundary");
            int token=0,filter=-1;
            switch(region.Kind)
            {
                case ExceptionRegionKind.Catch: token=MetadataTokens.GetToken(region.CatchType); ValidateToken(r,token,OperandType.InlineType); break;
                case ExceptionRegionKind.Filter: filter=region.FilterOffset; Require(starts.Contains(filter) && filter<region.HandlerOffset, "invalid filter"); break;
                case ExceptionRegionKind.Finally: case ExceptionRegionKind.Fault: break;
                default: throw new BadImageFormatException("unsupported EH clause");
            }
            eh.Add(string.Join(",",(int)region.Kind,region.TryOffset,region.TryLength,region.HandlerOffset,region.HandlerLength,token,filter));
        }
        row["il_sha256"]=Hash(il);
        row["il_bytes"]=il.Length;
        row["instructions"]=starts.Count+prefixCount;
        row["branch_targets"]=targets.Count;
        row["eh_sha256"]=Hash(Encoding.UTF8.GetBytes(string.Join("|",eh)));
        row["eh_count"]=eh.Count;
        row["locals_signature"]=locals;
        row["init_locals"]=body.LocalVariablesInitialized;
        row["max_stack"]=body.MaxStack;
    }

    static byte[] FileBytes(PEReader pe, Stream stream, int rva, int size)
    {
        Require(rva>0 && size>=0,"invalid managed data range");
        var s=pe.PEHeaders.SectionHeaders.Single(section => rva>=section.VirtualAddress &&
                  (long)rva+size<=(long)section.VirtualAddress+section.SizeOfRawData &&
                  (section.VirtualSize==0 || (long)rva+size<=(long)section.VirtualAddress+section.VirtualSize));
        stream.Position=checked((long)s.PointerToRawData+rva-s.VirtualAddress);
        byte[] outBytes=new byte[size];
        stream.ReadExactly(outBytes);
        return outBytes;
    }

    static int FieldSize(MetadataReader r, FieldDefinition field)
    {
        var b=r.GetBlobReader(field.Signature);
        if(b.ReadSignatureHeader().Kind!=SignatureKind.Field) return 0;
        byte et=b.ReadByte();
        int size=0;
        switch(et)
        {
            case 0x02: case 0x04: case 0x05: size=1; break;
            case 0x03: case 0x06: case 0x07: size=2; break;
            case 0x08: case 0x09: case 0x0c: size=4; break;
            case 0x0a: case 0x0b: case 0x0d: size=8; break;
            case 0x11:
                var h=b.ReadTypeHandle();
                if(h.Kind!=HandleKind.TypeDefinition) return 0;
                var t=r.GetTypeDefinition((TypeDefinitionHandle)h);
                if(t.BaseType.Kind!=HandleKind.TypeReference || (t.Attributes&TypeAttributes.LayoutMask)==TypeAttributes.AutoLayout)
                    return 0;
                var parent=r.GetTypeReference((TypeReferenceHandle)t.BaseType);
                if(r.GetString(parent.Namespace)!="System" || r.GetString(parent.Name)!="ValueType" ||
                     t.GetFields().Any(f => (r.GetFieldDefinition(f).Attributes & FieldAttributes.Static)==0)) return 0;
                size=t.GetLayout().Size;
                break;
        }
        return b.RemainingBytes==0 ? size : 0;
    }

    static object[] FieldData(PEReader pe, Stream stream, MetadataReader r)
    {
        var fields=new List<object>();
        foreach (var handle in r.FieldDefinitions)
        {
            var f=r.GetFieldDefinition(handle);
            if ((f.Attributes & FieldAttributes.HasFieldRVA)==0) continue;
            int size=FieldSize(r,f);
            string digest = size > 0 ? Hash(FileBytes(pe,stream,f.GetRelativeVirtualAddress(),size)) : "";
            fields.Add(new { token=MetadataTokens.GetToken(handle), size, digest });
        }
        Require(fields.Count==r.GetTableRowCount(TableIndex.FieldRva),"FieldRVA row/flag mismatch");
        return fields.ToArray();
    }

    static object ResourceData(PEReader pe, Stream stream, MetadataReader r, DirectoryEntry dir)
    {
        Require(dir.Size>=0 && ((dir.Size==0)==(dir.RelativeVirtualAddress==0)), "invalid resource directory");
        byte[] bytes=dir.Size==0 ? Array.Empty<byte>() : FileBytes(pe,stream,dir.RelativeVirtualAddress,dir.Size);
        int external=0;
        foreach(var h in r.ManifestResources)
        {
            var m=r.GetManifestResource(h);
            if(!m.Implementation.IsNil) { external++; continue; }
            Require(m.Offset>=0 && m.Offset<=bytes.Length-4,"bad embedded resource offset");
            int offset=checked((int)m.Offset);
            int len=BitConverter.ToInt32(bytes,offset);
            Require(len>=0 && len<=bytes.Length-offset-4,"bad embedded resource length");
        }
        return new { size=bytes.Length, digest=Hash(bytes), external };
    }

    public static object Inspect(string path)
    {
        using var fs = File.OpenRead(path);
        string hash = Convert.ToHexString(SHA256.HashData(fs)).ToLowerInvariant();
        fs.Position=0;
        using var pe = new PEReader(fs);
        Require(pe.HasMetadata && pe.PEHeaders.CorHeader != null, "missing CLR metadata");
        var r=pe.GetMetadataReader(MetadataReaderOptions.None);
        var names=new SignatureNames(r);
        var rows=new List<Dictionary<string,object>>();
        foreach (var h in r.MethodDefinitions)
        {
            var row = new Dictionary<string,object>{{"token",MetadataTokens.GetToken(h).ToString("x8")}};
            rows.Add(row);
            try
            {
                var m=r.GetMethodDefinition(h); var owner=m.GetDeclaringType();
                Require(!owner.IsNil,"MethodDef missing owner");
                var decl=names.Def(owner);
                row["name"]=r.GetString(m.Name);
                row["owner"]=decl;
                row["family"]=Pack("method", decl,(string)row["name"]);
                row["signature"]=names.Signature(m.DecodeSignature(names,0));
                row["key"]=Pack("method", decl,(string)row["name"],(string)row["signature"]);
                row["attrs"]=(int)m.Attributes; row["impl"]=(int)m.ImplAttributes;
                int rva=m.RelativeVirtualAddress;
                var code=m.ImplAttributes & MethodImplAttributes.CodeTypeMask;
                bool abs=(m.Attributes & MethodAttributes.Abstract)!=0, pin=(m.Attributes & MethodAttributes.PinvokeImpl)!=0;
                bool internalCall=(m.ImplAttributes & MethodImplAttributes.InternalCall)!=0;
                bool forward=(m.ImplAttributes & MethodImplAttributes.ForwardRef)!=0;
                if (pin)
                {
                    var import=m.GetImport();
                    Require(!import.Module.IsNil && !import.Name.IsNil,"missing ImplMap");
                    r.GetString(r.GetModuleReference(import.Module).Name); r.GetString(import.Name);
                }
                if (rva==0 && (abs || pin || internalCall || code==MethodImplAttributes.Runtime) && !forward)
                    row["kind"]=abs ? "abstract" : pin ? "pinvoke" : internalCall ? "internalcall":"runtime";
                else if (rva==0 || abs || pin || internalCall || forward || code!=MethodImplAttributes.IL ||
                        (m.ImplAttributes & MethodImplAttributes.Unmanaged)!=0)
                    row["kind"]="unsupported_body";
                else { Body(r,pe.GetMethodBody(rva),row); row["kind"]="cil"; }
            }
            catch(Exception e) { row["kind"]="invalid"; row["reason"]=e.GetType().Name + ": " + e.Message; }
        }
        var ch=pe.PEHeaders.CorHeader;
        return new {
            sha256=hash, metadata=MetadataDigest(pe,r), methods=rows, types=r.TypeDefinitions.Count,
            cli_flags=(int)ch.Flags, machine=(int)pe.PEHeaders.CoffHeader.Machine, pe_magic=(int)pe.PEHeaders.PEHeader.Magic,
            managed_entry=ch.EntryPointTokenOrRelativeVirtualAddress, native_header=ch.ManagedNativeHeaderDirectory.Size,
            vtable_fixups=ch.VtableFixupsDirectory.Size, code_manager=ch.CodeManagerTableDirectory.Size,
            export_jumps=ch.ExportAddressTableJumpsDirectory.Size,
            managed_resources=r.ManifestResources.Count, field_rvas=r.GetTableRowCount(TableIndex.FieldRva),
            external_modules=r.AssemblyFiles.Count(h=>r.GetAssemblyFile(h).ContainsMetadata),
            field_data=FieldData(pe,fs,r), resource_data=ResourceData(pe,fs,r,ch.ResourcesDirectory)
        };
    }
}

