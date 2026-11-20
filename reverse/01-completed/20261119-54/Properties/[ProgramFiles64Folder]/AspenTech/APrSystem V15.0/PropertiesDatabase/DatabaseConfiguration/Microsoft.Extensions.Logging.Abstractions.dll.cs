// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// Source files combined from dotnet/runtime at 5535e31a712343a63f5d7d796cd874e563e5ac14.
#define NET
#define NETCOREAPP
#define NETCOREAPP3_0_OR_GREATER
#define NETCOREAPP3_1_OR_GREATER
#define NET5_0_OR_GREATER
#define NET6_0_OR_GREATER
#define NET7_0_OR_GREATER
#define NET8_0_OR_GREATER
#nullable enable annotations

using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Internal;
using Microsoft.Extensions.Logging.Abstractions;
using System.Buffers;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Permissions;
using System.Security;
using System.Text;
using System.Threading;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: InternalsVisibleTo("Microsoft.Extensions.Logging.Tests, PublicKey=0024000004800000940000000602000000240000525341310004000001000100f33a29044fa9d740c9b3213a93e57c84b472c84e0b8a0e1ae48e67a9f8f6de9d5f7f3d52ac23e48ac51801f1dc950abe901da34d2a9e3baadb141a17c77ef3c565dd5ee5054b91cf63bb3c6ab83f72ab3aafe93d0fc3c2348b764fafb0b1c0733de51459aeab46580384bf9d74c4e28164b7cde247f891ba07891c9d872ad2bb")]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.Logging.Abstractions")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Logging abstractions for Microsoft.Extensions.Logging.\r\n\r\nCommonly Used Types:\r\nMicrosoft.Extensions.Logging.ILogger\r\nMicrosoft.Extensions.Logging.ILoggerFactory\r\nMicrosoft.Extensions.Logging.ILogger<TCategoryName>\r\nMicrosoft.Extensions.Logging.LogLevel\r\nMicrosoft.Extensions.Logging.Logger<T>\r\nMicrosoft.Extensions.Logging.LoggerMessage\r\nMicrosoft.Extensions.Logging.Abstractions.NullLogger")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.Logging.Abstractions")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]

// src/libraries/Common/src/Extensions/Logging/DebuggerDisplayFormatting.cs
namespace Microsoft.Extensions.Logging
{
    internal static class DebuggerDisplayFormatting
    {
        internal static string DebuggerToString(string name, ILogger logger)
        {
            LogLevel? minimumLevel = CalculateEnabledLogLevel(logger);

            var debugText = $@"Name = ""{name}""";
            if (minimumLevel != null)
            {
                debugText += $", MinLevel = {minimumLevel}";
            }
            else
            {
                // Display "Enabled = false". This makes it clear that the entire ILogger
                // is disabled and nothing is written.
                //
                // If "MinLevel = None" was displayed then someone could think that the
                // min level is disabled and everything is written.
                debugText += $", Enabled = false";
            }

            return debugText;
        }

        internal static LogLevel? CalculateEnabledLogLevel(ILogger logger)
        {
            ReadOnlySpan<LogLevel> logLevels = stackalloc LogLevel[]
            {
                LogLevel.Critical,
                LogLevel.Error,
                LogLevel.Warning,
                LogLevel.Information,
                LogLevel.Debug,
                LogLevel.Trace,
            };

            LogLevel? minimumLevel = null;

            // Check log level from highest to lowest. Report the lowest log level.
            foreach (LogLevel logLevel in logLevels)
            {
                if (!logger.IsEnabled(logLevel))
                {
                    break;
                }

                minimumLevel = logLevel;
            }

            return minimumLevel;
        }
    }
}

// src/libraries/Common/src/Extensions/Logging/NullExternalScopeProvider.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Scope provider that does nothing.
    /// </summary>
    internal sealed class NullExternalScopeProvider : IExternalScopeProvider
    {
        private NullExternalScopeProvider()
        {
        }

        /// <summary>
        /// Returns a cached instance of <see cref="NullExternalScopeProvider"/>.
        /// </summary>
        public static IExternalScopeProvider Instance { get; } = new NullExternalScopeProvider();

        /// <inheritdoc />
        void IExternalScopeProvider.ForEachScope<TState>(Action<object?, TState> callback, TState state)
        {
        }

        /// <inheritdoc />
        IDisposable IExternalScopeProvider.Push(object? state)
        {
            return NullScope.Instance;
        }
    }
}

// src/libraries/Common/src/Extensions/Logging/NullScope.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// An empty scope without any logic
    /// </summary>
    internal sealed class NullScope : IDisposable
    {
        public static NullScope Instance { get; } = new NullScope();

        private NullScope()
        {
        }

        /// <inheritdoc />
        public void Dispose()
        {
        }
    }
}

// src/libraries/Common/src/Extensions/TypeNameHelper/TypeNameHelper.cs
namespace Microsoft.Extensions.Internal
{
    internal static class TypeNameHelper
    {
        private const char DefaultNestedTypeDelimiter = '+';

        private static readonly Dictionary<Type, string> _builtInTypeNames = new Dictionary<Type, string>
        {
            { typeof(void), "void" },
            { typeof(bool), "bool" },
            { typeof(byte), "byte" },
            { typeof(char), "char" },
            { typeof(decimal), "decimal" },
            { typeof(double), "double" },
            { typeof(float), "float" },
            { typeof(int), "int" },
            { typeof(long), "long" },
            { typeof(object), "object" },
            { typeof(sbyte), "sbyte" },
            { typeof(short), "short" },
            { typeof(string), "string" },
            { typeof(uint), "uint" },
            { typeof(ulong), "ulong" },
            { typeof(ushort), "ushort" }
        };

        [return: NotNullIfNotNull(nameof(item))]
        public static string? GetTypeDisplayName(object? item, bool fullName = true)
        {
            return item == null ? null : GetTypeDisplayName(item.GetType(), fullName);
        }

        /// <summary>
        /// Pretty print a type name.
        /// </summary>
        /// <param name="type">The <see cref="Type"/>.</param>
        /// <param name="fullName"><c>true</c> to print a fully qualified name.</param>
        /// <param name="includeGenericParameterNames"><c>true</c> to include generic parameter names.</param>
        /// <param name="includeGenericParameters"><c>true</c> to include generic parameters.</param>
        /// <param name="nestedTypeDelimiter">Character to use as a delimiter in nested type names</param>
        /// <returns>The pretty printed type name.</returns>
        public static string GetTypeDisplayName(Type type, bool fullName = true, bool includeGenericParameterNames = false, bool includeGenericParameters = true, char nestedTypeDelimiter = DefaultNestedTypeDelimiter)
        {
            StringBuilder? builder = null;
            string? name = ProcessType(ref builder, type, new DisplayNameOptions(fullName, includeGenericParameterNames, includeGenericParameters, nestedTypeDelimiter));
            return name ?? builder?.ToString() ?? string.Empty;
        }

        private static string? ProcessType(ref StringBuilder? builder, Type type, in DisplayNameOptions options)
        {
            if (type.IsGenericType)
            {
                Type[] genericArguments = type.GetGenericArguments();
                builder ??= new StringBuilder();
                ProcessGenericType(builder, type, genericArguments, genericArguments.Length, options);
            }
            else if (type.IsArray)
            {
                builder ??= new StringBuilder();
                ProcessArrayType(builder, type, options);
            }
            else if (_builtInTypeNames.TryGetValue(type, out string? builtInName))
            {
                if (builder is null) return builtInName;

                builder.Append(builtInName);
            }
            else if (type.IsGenericParameter)
            {
                if (options.IncludeGenericParameterNames)
                {
                    if (builder is null) return type.Name;

                    builder.Append(type.Name);
                }
            }
            else
            {
                string name = options.FullName ? type.FullName! : type.Name;

                if (builder is null)
                {
                    if (options.NestedTypeDelimiter != DefaultNestedTypeDelimiter)
                    {
                        return name.Replace(DefaultNestedTypeDelimiter, options.NestedTypeDelimiter);
                    }

                    return name;
                }

                builder.Append(name);
                if (options.NestedTypeDelimiter != DefaultNestedTypeDelimiter)
                {
                    builder.Replace(DefaultNestedTypeDelimiter, options.NestedTypeDelimiter, builder.Length - name.Length, name.Length);
                }
            }

            return null;
        }

        private static void ProcessArrayType(StringBuilder builder, Type type, in DisplayNameOptions options)
        {
            Type innerType = type;
            while (innerType.IsArray)
            {
                innerType = innerType.GetElementType()!;
            }

            ProcessType(ref builder!, innerType, options);

            while (type.IsArray)
            {
                builder.Append('[');
                builder.Append(',', type.GetArrayRank() - 1);
                builder.Append(']');
                type = type.GetElementType()!;
            }
        }

        private static void ProcessGenericType(StringBuilder builder, Type type, Type[] genericArguments, int length, in DisplayNameOptions options)
        {
            int offset = 0;
            if (type.IsNested)
            {
                offset = type.DeclaringType!.GetGenericArguments().Length;
            }

            if (options.FullName)
            {
                if (type.IsNested)
                {
                    ProcessGenericType(builder, type.DeclaringType!, genericArguments, offset, options);
                    builder.Append(options.NestedTypeDelimiter);
                }
                else if (!string.IsNullOrEmpty(type.Namespace))
                {
                    builder.Append(type.Namespace);
                    builder.Append('.');
                }
            }

            int genericPartIndex = type.Name.IndexOf('`');
            if (genericPartIndex <= 0)
            {
                builder.Append(type.Name);
                return;
            }

            builder.Append(type.Name, 0, genericPartIndex);

            if (options.IncludeGenericParameters)
            {
                builder.Append('<');
                for (int i = offset; i < length; i++)
                {
                    ProcessType(ref builder!, genericArguments[i], options);
                    if (i + 1 == length)
                    {
                        continue;
                    }

                    builder.Append(',');
                    if (options.IncludeGenericParameterNames || !genericArguments[i + 1].IsGenericParameter)
                    {
                        builder.Append(' ');
                    }
                }
                builder.Append('>');
            }
        }

        private readonly struct DisplayNameOptions
        {
            public DisplayNameOptions(bool fullName, bool includeGenericParameterNames, bool includeGenericParameters, char nestedTypeDelimiter)
            {
                FullName = fullName;
                IncludeGenericParameters = includeGenericParameters;
                IncludeGenericParameterNames = includeGenericParameterNames;
                NestedTypeDelimiter = nestedTypeDelimiter;
            }

            public bool FullName { get; }

            public bool IncludeGenericParameters { get; }

            public bool IncludeGenericParameterNames { get; }

            public char NestedTypeDelimiter { get; }
        }
    }
}

// src/libraries/Common/src/System/SR.cs
namespace System
{
    internal static partial class SR
    {
        private static readonly bool s_usingResourceKeys = AppContext.TryGetSwitch("System.Resources.UseSystemResourceKeys", out bool usingResourceKeys) ? usingResourceKeys : false;

        // This method is used to decide if we need to append the exception message parameters to the message when calling SR.Format.
        // by default it returns the value of System.Resources.UseSystemResourceKeys AppContext switch or false if not specified.
        // Native code generators can replace the value this returns based on user input at the time of native code generation.
        // The trimming tools are also capable of replacing the value of this method when the application is being trimmed.
        internal static bool UsingResourceKeys() => s_usingResourceKeys;

        // We can optimize out the resource string blob if we can see all accesses to it happening
        // through the generated SR.XXX properties.
        // If a call to GetResourceString is left, the optimization gets defeated and we need to keep
        // the whole resource blob. It's important to keep this private. CoreCLR's CoreLib gets a free
        // pass because the VM needs to be able to call into this, but that's a known set of constants.
#if CORECLR || LEGACY_GETRESOURCESTRING_USER
        internal
#else
        private
#endif
        static string GetResourceString(string resourceKey)
        {
            if (UsingResourceKeys())
            {
                return resourceKey;
            }

            string? resourceString = null;
            try
            {
                resourceString =
#if SYSTEM_PRIVATE_CORELIB || NATIVEAOT
                    InternalGetResourceString(resourceKey);
#else
                    ResourceManager.GetString(resourceKey);
#endif
            }
            catch (MissingManifestResourceException) { }

            return resourceString!; // only null if missing resources
        }

#if LEGACY_GETRESOURCESTRING_USER
        internal
#else
        private
#endif
        static string GetResourceString(string resourceKey, string defaultString)
        {
            string resourceString = GetResourceString(resourceKey);

            return resourceKey == resourceString || resourceString == null ? defaultString : resourceString;
        }

        internal static string Format(string resourceFormat, object? p1)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1);
            }

            return string.Format(resourceFormat, p1);
        }

        internal static string Format(string resourceFormat, object? p1, object? p2)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2);
            }

            return string.Format(resourceFormat, p1, p2);
        }

        internal static string Format(string resourceFormat, object? p1, object? p2, object? p3)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2, p3);
            }

            return string.Format(resourceFormat, p1, p2, p3);
        }

        internal static string Format(string resourceFormat, params object?[]? args)
        {
            if (args != null)
            {
                if (UsingResourceKeys())
                {
                    return resourceFormat + ", " + string.Join(", ", args);
                }

                return string.Format(resourceFormat, args);
            }

            return resourceFormat;
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1);
            }

            return string.Format(provider, resourceFormat, p1);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1, object? p2)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2);
            }

            return string.Format(provider, resourceFormat, p1, p2);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, object? p1, object? p2, object? p3)
        {
            if (UsingResourceKeys())
            {
                return string.Join(", ", resourceFormat, p1, p2, p3);
            }

            return string.Format(provider, resourceFormat, p1, p2, p3);
        }

        internal static string Format(IFormatProvider? provider, string resourceFormat, params object?[]? args)
        {
            if (args != null)
            {
                if (UsingResourceKeys())
                {
                    return resourceFormat + ", " + string.Join(", ", args);
                }

                return string.Format(provider, resourceFormat, args);
            }

            return resourceFormat;
        }
    }
}

// src/libraries/Common/src/System/Text/ValueStringBuilder.cs
#nullable enable
namespace System.Text
{
    internal ref partial struct ValueStringBuilder
    {
        private char[]? _arrayToReturnToPool;
        private Span<char> _chars;
        private int _pos;

        public ValueStringBuilder(Span<char> initialBuffer)
        {
            _arrayToReturnToPool = null;
            _chars = initialBuffer;
            _pos = 0;
        }

        public ValueStringBuilder(int initialCapacity)
        {
            _arrayToReturnToPool = ArrayPool<char>.Shared.Rent(initialCapacity);
            _chars = _arrayToReturnToPool;
            _pos = 0;
        }

        public int Length
        {
            get => _pos;
            set
            {
                Debug.Assert(value >= 0);
                Debug.Assert(value <= _chars.Length);
                _pos = value;
            }
        }

        public int Capacity => _chars.Length;

        public void EnsureCapacity(int capacity)
        {
            // This is not expected to be called this with negative capacity
            Debug.Assert(capacity >= 0);

            // If the caller has a bug and calls this with negative capacity, make sure to call Grow to throw an exception.
            if ((uint)capacity > (uint)_chars.Length)
                Grow(capacity - _pos);
        }

        /// <summary>
        /// Get a pinnable reference to the builder.
        /// Does not ensure there is a null char after <see cref="Length"/>
        /// This overload is pattern matched in the C# 7.3+ compiler so you can omit
        /// the explicit method call, and write eg "fixed (char* c = builder)"
        /// </summary>
        public ref char GetPinnableReference()
        {
            return ref MemoryMarshal.GetReference(_chars);
        }

        /// <summary>
        /// Get a pinnable reference to the builder.
        /// </summary>
        /// <param name="terminate">Ensures that the builder has a null char after <see cref="Length"/></param>
        public ref char GetPinnableReference(bool terminate)
        {
            if (terminate)
            {
                EnsureCapacity(Length + 1);
                _chars[Length] = '\0';
            }
            return ref MemoryMarshal.GetReference(_chars);
        }

        public ref char this[int index]
        {
            get
            {
                Debug.Assert(index < _pos);
                return ref _chars[index];
            }
        }

        public override string ToString()
        {
            string s = _chars.Slice(0, _pos).ToString();
            Dispose();
            return s;
        }

        /// <summary>Returns the underlying storage of the builder.</summary>
        public Span<char> RawChars => _chars;

        /// <summary>
        /// Returns a span around the contents of the builder.
        /// </summary>
        /// <param name="terminate">Ensures that the builder has a null char after <see cref="Length"/></param>
        public ReadOnlySpan<char> AsSpan(bool terminate)
        {
            if (terminate)
            {
                EnsureCapacity(Length + 1);
                _chars[Length] = '\0';
            }
            return _chars.Slice(0, _pos);
        }

        public ReadOnlySpan<char> AsSpan() => _chars.Slice(0, _pos);
        public ReadOnlySpan<char> AsSpan(int start) => _chars.Slice(start, _pos - start);
        public ReadOnlySpan<char> AsSpan(int start, int length) => _chars.Slice(start, length);

        public bool TryCopyTo(Span<char> destination, out int charsWritten)
        {
            if (_chars.Slice(0, _pos).TryCopyTo(destination))
            {
                charsWritten = _pos;
                Dispose();
                return true;
            }
            else
            {
                charsWritten = 0;
                Dispose();
                return false;
            }
        }

        public void Insert(int index, char value, int count)
        {
            if (_pos > _chars.Length - count)
            {
                Grow(count);
            }

            int remaining = _pos - index;
            _chars.Slice(index, remaining).CopyTo(_chars.Slice(index + count));
            _chars.Slice(index, count).Fill(value);
            _pos += count;
        }

        public void Insert(int index, string? s)
        {
            if (s == null)
            {
                return;
            }

            int count = s.Length;

            if (_pos > (_chars.Length - count))
            {
                Grow(count);
            }

            int remaining = _pos - index;
            _chars.Slice(index, remaining).CopyTo(_chars.Slice(index + count));
            s
#if !NETCOREAPP
                .AsSpan()
#endif
                .CopyTo(_chars.Slice(index));
            _pos += count;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public void Append(char c)
        {
            int pos = _pos;
            Span<char> chars = _chars;
            if ((uint)pos < (uint)chars.Length)
            {
                chars[pos] = c;
                _pos = pos + 1;
            }
            else
            {
                GrowAndAppend(c);
            }
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public void Append(string? s)
        {
            if (s == null)
            {
                return;
            }

            int pos = _pos;
            if (s.Length == 1 && (uint)pos < (uint)_chars.Length) // very common case, e.g. appending strings from NumberFormatInfo like separators, percent symbols, etc.
            {
                _chars[pos] = s[0];
                _pos = pos + 1;
            }
            else
            {
                AppendSlow(s);
            }
        }

        private void AppendSlow(string s)
        {
            int pos = _pos;
            if (pos > _chars.Length - s.Length)
            {
                Grow(s.Length);
            }

            s
#if !NETCOREAPP
                .AsSpan()
#endif
                .CopyTo(_chars.Slice(pos));
            _pos += s.Length;
        }

        public void Append(char c, int count)
        {
            if (_pos > _chars.Length - count)
            {
                Grow(count);
            }

            Span<char> dst = _chars.Slice(_pos, count);
            for (int i = 0; i < dst.Length; i++)
            {
                dst[i] = c;
            }
            _pos += count;
        }

        public unsafe void Append(char* value, int length)
        {
            int pos = _pos;
            if (pos > _chars.Length - length)
            {
                Grow(length);
            }

            Span<char> dst = _chars.Slice(_pos, length);
            for (int i = 0; i < dst.Length; i++)
            {
                dst[i] = *value++;
            }
            _pos += length;
        }

        public void Append(ReadOnlySpan<char> value)
        {
            int pos = _pos;
            if (pos > _chars.Length - value.Length)
            {
                Grow(value.Length);
            }

            value.CopyTo(_chars.Slice(_pos));
            _pos += value.Length;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Span<char> AppendSpan(int length)
        {
            int origPos = _pos;
            if (origPos > _chars.Length - length)
            {
                Grow(length);
            }

            _pos = origPos + length;
            return _chars.Slice(origPos, length);
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        private void GrowAndAppend(char c)
        {
            Grow(1);
            Append(c);
        }

        /// <summary>
        /// Resize the internal buffer either by doubling current buffer size or
        /// by adding <paramref name="additionalCapacityBeyondPos"/> to
        /// <see cref="_pos"/> whichever is greater.
        /// </summary>
        /// <param name="additionalCapacityBeyondPos">
        /// Number of chars requested beyond current position.
        /// </param>
        [MethodImpl(MethodImplOptions.NoInlining)]
        private void Grow(int additionalCapacityBeyondPos)
        {
            Debug.Assert(additionalCapacityBeyondPos > 0);
            Debug.Assert(_pos > _chars.Length - additionalCapacityBeyondPos, "Grow called incorrectly, no resize is needed.");

            const uint ArrayMaxLength = 0x7FFFFFC7; // same as Array.MaxLength

            // Increase to at least the required size (_pos + additionalCapacityBeyondPos), but try
            // to double the size if possible, bounding the doubling to not go beyond the max array length.
            int newCapacity = (int)Math.Max(
                (uint)(_pos + additionalCapacityBeyondPos),
                Math.Min((uint)_chars.Length * 2, ArrayMaxLength));

            // Make sure to let Rent throw an exception if the caller has a bug and the desired capacity is negative.
            // This could also go negative if the actual required length wraps around.
            char[] poolArray = ArrayPool<char>.Shared.Rent(newCapacity);

            _chars.Slice(0, _pos).CopyTo(poolArray);

            char[]? toReturn = _arrayToReturnToPool;
            _chars = _arrayToReturnToPool = poolArray;
            if (toReturn != null)
            {
                ArrayPool<char>.Shared.Return(toReturn);
            }
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public void Dispose()
        {
            char[]? toReturn = _arrayToReturnToPool;
            this = default; // for safety, to avoid using pooled array if this instance is erroneously appended to again
            if (toReturn != null)
            {
                ArrayPool<char>.Shared.Return(toReturn);
            }
        }
    }
}
#nullable disable warnings

// src/libraries/Common/src/System/ThrowHelper.cs
#pragma warning disable CS0436 // Type conflicts with imported type
namespace System
{
    internal static partial class ThrowHelper
    {
        /// <summary>Throws an <see cref="ArgumentNullException"/> if <paramref name="argument"/> is null.</summary>
        /// <param name="argument">The reference type argument to validate as non-null.</param>
        /// <param name="paramName">The name of the parameter with which <paramref name="argument"/> corresponds.</param>
        internal static void ThrowIfNull(
#if NETCOREAPP3_0_OR_GREATER
            [NotNull]
#endif
            object? argument,
            [CallerArgumentExpression(nameof(argument))] string? paramName = null)
        {
            if (argument is null)
            {
                Throw(paramName);
            }
        }

#if NETCOREAPP3_0_OR_GREATER
        [DoesNotReturn]
#endif
        private static void Throw(string? paramName) => throw new ArgumentNullException(paramName);

        /// <summary>
        /// Throws either an <see cref="System.ArgumentNullException"/> or an <see cref="System.ArgumentException"/>
        /// if the specified string is <see langword="null"/> or whitespace respectively.
        /// </summary>
        /// <param name="argument">String to be checked for <see langword="null"/> or whitespace.</param>
        /// <param name="paramName">The name of the parameter being checked.</param>
        /// <returns>The original value of <paramref name="argument"/>.</returns>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
#if NETCOREAPP3_0_OR_GREATER
        [return: NotNull]
#endif
        public static string IfNullOrWhitespace(
#if NETCOREAPP3_0_OR_GREATER
            [NotNull]
#endif
            string? argument,
            [CallerArgumentExpression(nameof(argument))] string paramName = "")
        {
#if !NETCOREAPP3_1_OR_GREATER
            if (argument == null)
            {
                throw new ArgumentNullException(paramName);
            }
#endif

            if (string.IsNullOrWhiteSpace(argument))
            {
                if (argument == null)
                {
                    throw new ArgumentNullException(paramName);
                }
                else
                {
                    throw new ArgumentException(paramName, "Argument is whitespace");
                }
            }

            return argument;
        }
    }
}

#if !NETCOREAPP3_0_OR_GREATER
namespace System.Runtime.CompilerServices
{
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = false)]
    internal sealed class CallerArgumentExpressionAttribute : Attribute
    {
        public CallerArgumentExpressionAttribute(string parameterName)
        {
            ParameterName = parameterName;
        }

        public string ParameterName { get; }
    }
}
#endif
#pragma warning restore CS0436

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/EventId.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Identifies a logging event. The primary identifier is the "Id" property, with the "Name" property providing a short description of this type of event.
    /// </summary>
    public readonly struct EventId : IEquatable<EventId>
    {
        /// <summary>
        /// Implicitly creates an EventId from the given <see cref="int"/>.
        /// </summary>
        /// <param name="i">The <see cref="int"/> to convert to an EventId.</param>
        public static implicit operator EventId(int i)
        {
            return new EventId(i);
        }

        /// <summary>
        /// Checks if two specified <see cref="EventId"/> instances have the same value. They are equal if they have the same Id.
        /// </summary>
        /// <param name="left">The first <see cref="EventId"/>.</param>
        /// <param name="right">The second <see cref="EventId"/>.</param>
        /// <returns><see langword="true" /> if the objects are equal.</returns>
        public static bool operator ==(EventId left, EventId right)
        {
            return left.Equals(right);
        }

        /// <summary>
        /// Checks if two specified <see cref="EventId"/> instances have different values.
        /// </summary>
        /// <param name="left">The first <see cref="EventId"/>.</param>
        /// <param name="right">The second <see cref="EventId"/>.</param>
        /// <returns><see langword="true" /> if the objects are not equal.</returns>
        public static bool operator !=(EventId left, EventId right)
        {
            return !left.Equals(right);
        }

        /// <summary>
        /// Initializes an instance of the <see cref="EventId"/> struct.
        /// </summary>
        /// <param name="id">The numeric identifier for this event.</param>
        /// <param name="name">The name of this event.</param>
        public EventId(int id, string? name = null)
        {
            Id = id;
            Name = name;
        }

        /// <summary>
        /// Gets the numeric identifier for this event.
        /// </summary>
        public int Id { get; }

        /// <summary>
        /// Gets the name of this event.
        /// </summary>
        public string? Name { get; }

        /// <inheritdoc />
        public override string ToString()
        {
            return Name ?? Id.ToString();
        }

        /// <summary>
        /// Indicates whether the current object is equal to another object of the same type. Two events are equal if they have the same id.
        /// </summary>
        /// <param name="other">An object to compare with this object.</param>
        /// <returns><see langword="true" /> if the current object is equal to the other parameter; otherwise, <see langword="false" />.</returns>
        public bool Equals(EventId other)
        {
            return Id == other.Id;
        }

        /// <inheritdoc />
        public override bool Equals([NotNullWhen(true)] object? obj)
        {
            if (obj is null)
            {
                return false;
            }

            return obj is EventId eventId && Equals(eventId);
        }

        /// <inheritdoc />
        public override int GetHashCode()
        {
            return Id;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/FormattedLogValues.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// LogValues to enable formatting options supported by <see cref="string.Format(IFormatProvider, string, object?)"/>.
    /// This also enables using {NamedformatItem} in the format string.
    /// </summary>
    internal readonly struct FormattedLogValues : IReadOnlyList<KeyValuePair<string, object?>>
    {
        internal const int MaxCachedFormatters = 1024;
        private const string NullFormat = "[null]";

        private static int s_count;
        private static readonly ConcurrentDictionary<string, LogValuesFormatter> s_formatters = new ConcurrentDictionary<string, LogValuesFormatter>();

        private readonly LogValuesFormatter? _formatter;
        private readonly object?[]? _values;
        private readonly string _originalMessage;

        // for testing purposes
        internal LogValuesFormatter? Formatter => _formatter;

        public FormattedLogValues(string? format, params object?[]? values)
        {
            if (values != null && values.Length != 0 && format != null)
            {
                if (s_count >= MaxCachedFormatters)
                {
                    if (!s_formatters.TryGetValue(format, out _formatter))
                    {
                        _formatter = new LogValuesFormatter(format);
                    }
                }
                else
                {
                    _formatter = s_formatters.GetOrAdd(format, f =>
                    {
                        Interlocked.Increment(ref s_count);
                        return new LogValuesFormatter(f);
                    });
                }
            }
            else
            {
                _formatter = null;
            }

            _originalMessage = format ?? NullFormat;
            _values = values;
        }

        public KeyValuePair<string, object?> this[int index]
        {
            get
            {
                if (index < 0 || index >= Count)
                {
                    throw new IndexOutOfRangeException(nameof(index));
                }

                if (index == Count - 1)
                {
                    return new KeyValuePair<string, object?> ("{OriginalFormat}", _originalMessage);
                }

                return _formatter!.GetValue(_values!, index);
            }
        }

        public int Count
        {
            get
            {
                if (_formatter == null)
                {
                    return 1;
                }

                return _formatter.ValueNames.Count + 1;
            }
        }

        public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
        {
            for (int i = 0; i < Count; ++i)
            {
                yield return this[i];
            }
        }

        public override string ToString()
        {
            if (_formatter == null)
            {
                return _originalMessage;
            }

            return _formatter.Format(_values);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/IExternalScopeProvider.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Represents a storage of common scope data.
    /// </summary>
    public interface IExternalScopeProvider
    {
        /// <summary>
        /// Executes callback for each currently active scope objects in order of creation.
        /// All callbacks are guaranteed to be called inline from this method.
        /// </summary>
        /// <param name="callback">The callback to be executed for every scope object</param>
        /// <param name="state">The state object to be passed into the callback</param>
        /// <typeparam name="TState">The type of state to accept.</typeparam>
        void ForEachScope<TState>(Action<object?, TState> callback, TState state);

        /// <summary>
        /// Adds scope object to the list
        /// </summary>
        /// <param name="state">The scope object</param>
        /// <returns>The <see cref="IDisposable"/> token that removes scope on dispose.</returns>
        IDisposable Push(object? state);
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ILogger.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Represents a type used to perform logging.
    /// </summary>
    /// <remarks>Aggregates most logging patterns to a single method.</remarks>
    public interface ILogger
    {
        /// <summary>
        /// Writes a log entry.
        /// </summary>
        /// <param name="logLevel">Entry will be written on this level.</param>
        /// <param name="eventId">Id of the event.</param>
        /// <param name="state">The entry to be written. Can be also an object.</param>
        /// <param name="exception">The exception related to this entry.</param>
        /// <param name="formatter">Function to create a <see cref="string"/> message of the <paramref name="state"/> and <paramref name="exception"/>.</param>
        /// <typeparam name="TState">The type of the object to be written.</typeparam>
        void Log<TState>(LogLevel logLevel, EventId eventId, TState state, Exception? exception, Func<TState, Exception?, string> formatter);

        /// <summary>
        /// Checks if the given <paramref name="logLevel"/> is enabled.
        /// </summary>
        /// <param name="logLevel">Level to be checked.</param>
        /// <returns><c>true</c> if enabled.</returns>
        bool IsEnabled(LogLevel logLevel);

        /// <summary>
        /// Begins a logical operation scope.
        /// </summary>
        /// <param name="state">The identifier for the scope.</param>
        /// <typeparam name="TState">The type of the state to begin scope for.</typeparam>
        /// <returns>An <see cref="IDisposable"/> that ends the logical operation scope on dispose.</returns>
        IDisposable? BeginScope<TState>(TState state) where TState : notnull;
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ILoggerFactory.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Represents a type used to configure the logging system and create instances of <see cref="ILogger"/> from
    /// the registered <see cref="ILoggerProvider"/>s.
    /// </summary>
    public interface ILoggerFactory : IDisposable
    {
        /// <summary>
        /// Creates a new <see cref="ILogger"/> instance.
        /// </summary>
        /// <param name="categoryName">The category name for messages produced by the logger.</param>
        /// <returns>The <see cref="ILogger"/>.</returns>
        ILogger CreateLogger(string categoryName);

        /// <summary>
        /// Adds an <see cref="ILoggerProvider"/> to the logging system.
        /// </summary>
        /// <param name="provider">The <see cref="ILoggerProvider"/>.</param>
        void AddProvider(ILoggerProvider provider);
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ILoggerProvider.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Represents a type that can create instances of <see cref="ILogger"/>.
    /// </summary>
    public interface ILoggerProvider : IDisposable
    {
        /// <summary>
        /// Creates a new <see cref="ILogger"/> instance.
        /// </summary>
        /// <param name="categoryName">The category name for messages produced by the logger.</param>
        /// <returns>The instance of <see cref="ILogger"/> that was created.</returns>
        ILogger CreateLogger(string categoryName);
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ILoggerT.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// A generic interface for logging where the category name is derived from the specified
    /// <typeparamref name="TCategoryName"/> type name.
    /// Generally used to enable activation of a named <see cref="ILogger"/> from dependency injection.
    /// </summary>
    /// <typeparam name="TCategoryName">The type whose name is used for the logger category name.</typeparam>
    public interface ILogger<out TCategoryName> : ILogger
    {

    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ILoggingBuilder.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// An interface for configuring logging providers.
    /// </summary>
    public interface ILoggingBuilder
    {
        /// <summary>
        /// Gets the <see cref="IServiceCollection"/> where Logging services are configured.
        /// </summary>
        IServiceCollection Services { get; }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/ISupportExternalScope.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Represents a <see cref="ILoggerProvider"/> that is able to consume external scope information.
    /// </summary>
    public interface ISupportExternalScope
    {
        /// <summary>
        /// Sets external scope information source for logger provider.
        /// </summary>
        /// <param name="scopeProvider">The provider of scope data.</param>
        void SetScopeProvider(IExternalScopeProvider scopeProvider);
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LogDefineOptions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Options for <see cref="LoggerMessage.Define(LogLevel, EventId, string)"/> and its overloads
    /// </summary>
    public class LogDefineOptions
    {
        /// <summary>
        /// Gets or sets the flag to skip IsEnabled check for the logging method.
        /// </summary>
        public bool SkipEnabledCheck { get; set; }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LogEntry.cs
namespace Microsoft.Extensions.Logging.Abstractions
{
    /// <summary>
    /// Holds the information for a single log entry.
    /// </summary>
    public readonly struct LogEntry<TState>
    {
        /// <summary>
        /// Initializes an instance of the LogEntry struct.
        /// </summary>
        /// <param name="logLevel">The log level.</param>
        /// <param name="category">The category name for the log.</param>
        /// <param name="eventId">The log event Id.</param>
        /// <param name="state">The state for which log is being written.</param>
        /// <param name="exception">The log exception.</param>
        /// <param name="formatter">The formatter.</param>
        public LogEntry(LogLevel logLevel, string category, EventId eventId, TState state, Exception? exception, Func<TState, Exception?, string> formatter)
        {
            LogLevel = logLevel;
            Category = category;
            EventId = eventId;
            State = state;
            Exception = exception;
            Formatter = formatter;
        }

        /// <summary>
        /// Gets the LogLevel
        /// </summary>
        public LogLevel LogLevel { get; }

        /// <summary>
        /// Gets the log category
        /// </summary>
        public string Category { get; }

        /// <summary>
        /// Gets the log EventId
        /// </summary>
        public EventId EventId { get; }

        /// <summary>
        /// Gets the TState
        /// </summary>
        public TState State { get; }

        /// <summary>
        /// Gets the log exception
        /// </summary>
        public Exception? Exception { get; }

        /// <summary>
        /// Gets the formatter
        /// </summary>
        public Func<TState, Exception?, string> Formatter { get; }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerExtensions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// ILogger extension methods for common scenarios.
    /// </summary>
    public static class LoggerExtensions
    {
        private static readonly Func<FormattedLogValues, Exception?, string> _messageFormatter = MessageFormatter;

        //------------------------------------------DEBUG------------------------------------------//

        /// <summary>
        /// Formats and writes a debug log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogDebug(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogDebug(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Debug, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a debug log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogDebug(0, "Processing request from {Address}", address)</example>
        public static void LogDebug(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Debug, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes a debug log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogDebug(exception, "Error while processing request from {Address}", address)</example>
        public static void LogDebug(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Debug, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a debug log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogDebug("Processing request from {Address}", address)</example>
        public static void LogDebug(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Debug, message, args);
        }

        //------------------------------------------TRACE------------------------------------------//

        /// <summary>
        /// Formats and writes a trace log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogTrace(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogTrace(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Trace, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a trace log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogTrace(0, "Processing request from {Address}", address)</example>
        public static void LogTrace(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Trace, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes a trace log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogTrace(exception, "Error while processing request from {Address}", address)</example>
        public static void LogTrace(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Trace, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a trace log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogTrace("Processing request from {Address}", address)</example>
        public static void LogTrace(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Trace, message, args);
        }

        //------------------------------------------INFORMATION------------------------------------------//

        /// <summary>
        /// Formats and writes an informational log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogInformation(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogInformation(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Information, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes an informational log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogInformation(0, "Processing request from {Address}", address)</example>
        public static void LogInformation(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Information, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes an informational log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogInformation(exception, "Error while processing request from {Address}", address)</example>
        public static void LogInformation(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Information, exception, message, args);
        }

        /// <summary>
        /// Formats and writes an informational log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogInformation("Processing request from {Address}", address)</example>
        public static void LogInformation(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Information, message, args);
        }

        //------------------------------------------WARNING------------------------------------------//

        /// <summary>
        /// Formats and writes a warning log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogWarning(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogWarning(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Warning, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a warning log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogWarning(0, "Processing request from {Address}", address)</example>
        public static void LogWarning(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Warning, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes a warning log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogWarning(exception, "Error while processing request from {Address}", address)</example>
        public static void LogWarning(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Warning, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a warning log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogWarning("Processing request from {Address}", address)</example>
        public static void LogWarning(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Warning, message, args);
        }

        //------------------------------------------ERROR------------------------------------------//

        /// <summary>
        /// Formats and writes an error log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogError(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogError(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Error, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes an error log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogError(0, "Processing request from {Address}", address)</example>
        public static void LogError(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Error, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes an error log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogError(exception, "Error while processing request from {Address}", address)</example>
        public static void LogError(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Error, exception, message, args);
        }

        /// <summary>
        /// Formats and writes an error log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogError("Processing request from {Address}", address)</example>
        public static void LogError(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Error, message, args);
        }

        //------------------------------------------CRITICAL------------------------------------------//

        /// <summary>
        /// Formats and writes a critical log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogCritical(0, exception, "Error while processing request from {Address}", address)</example>
        public static void LogCritical(this ILogger logger, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Critical, eventId, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a critical log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogCritical(0, "Processing request from {Address}", address)</example>
        public static void LogCritical(this ILogger logger, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Critical, eventId, message, args);
        }

        /// <summary>
        /// Formats and writes a critical log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogCritical(exception, "Error while processing request from {Address}", address)</example>
        public static void LogCritical(this ILogger logger, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Critical, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a critical log message.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="message">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <example>logger.LogCritical("Processing request from {Address}", address)</example>
        public static void LogCritical(this ILogger logger, string? message, params object?[] args)
        {
            logger.Log(LogLevel.Critical, message, args);
        }

        /// <summary>
        /// Formats and writes a log message at the specified log level.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="logLevel">Entry will be written on this level.</param>
        /// <param name="message">Format string of the log message.</param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        public static void Log(this ILogger logger, LogLevel logLevel, string? message, params object?[] args)
        {
            logger.Log(logLevel, 0, null, message, args);
        }

        /// <summary>
        /// Formats and writes a log message at the specified log level.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="logLevel">Entry will be written on this level.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="message">Format string of the log message.</param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        public static void Log(this ILogger logger, LogLevel logLevel, EventId eventId, string? message, params object?[] args)
        {
            logger.Log(logLevel, eventId, null, message, args);
        }

        /// <summary>
        /// Formats and writes a log message at the specified log level.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="logLevel">Entry will be written on this level.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message.</param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        public static void Log(this ILogger logger, LogLevel logLevel, Exception? exception, string? message, params object?[] args)
        {
            logger.Log(logLevel, 0, exception, message, args);
        }

        /// <summary>
        /// Formats and writes a log message at the specified log level.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to write to.</param>
        /// <param name="logLevel">Entry will be written on this level.</param>
        /// <param name="eventId">The event id associated with the log.</param>
        /// <param name="exception">The exception to log.</param>
        /// <param name="message">Format string of the log message.</param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        public static void Log(this ILogger logger, LogLevel logLevel, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            ThrowHelper.ThrowIfNull(logger);

            logger.Log(logLevel, eventId, new FormattedLogValues(message, args), exception, _messageFormatter);
        }

        //------------------------------------------Scope------------------------------------------//

        /// <summary>
        /// Formats the message and creates a scope.
        /// </summary>
        /// <param name="logger">The <see cref="ILogger"/> to create the scope in.</param>
        /// <param name="messageFormat">Format string of the log message in message template format. Example: <c>"User {User} logged in from {Address}"</c></param>
        /// <param name="args">An object array that contains zero or more objects to format.</param>
        /// <returns>A disposable scope object. Can be null.</returns>
        /// <example>
        /// using(logger.BeginScope("Processing request from {Address}", address))
        /// {
        /// }
        /// </example>
        public static IDisposable? BeginScope(
            this ILogger logger,
            string messageFormat,
            params object?[] args)
        {
            ThrowHelper.ThrowIfNull(logger);

            return logger.BeginScope(new FormattedLogValues(messageFormat, args));
        }

        //------------------------------------------HELPERS------------------------------------------//

        private static string MessageFormatter(FormattedLogValues state, Exception? error)
        {
            return state.ToString();
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerExternalScopeProvider.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Default implementation of <see cref="IExternalScopeProvider"/>
    /// </summary>
    public class LoggerExternalScopeProvider : IExternalScopeProvider
    {
        private readonly AsyncLocal<Scope?> _currentScope = new AsyncLocal<Scope?>();

        /// <summary>
        /// Creates a new <see cref="LoggerExternalScopeProvider"/>.
        /// </summary>
        public LoggerExternalScopeProvider()
        { }

        /// <inheritdoc />
        public void ForEachScope<TState>(Action<object?, TState> callback, TState state)
        {
            void Report(Scope? current)
            {
                if (current == null)
                {
                    return;
                }
                Report(current.Parent);
                callback(current.State, state);
            }
            Report(_currentScope.Value);
        }

        /// <inheritdoc />
        public IDisposable Push(object? state)
        {
            Scope? parent = _currentScope.Value;
            var newScope = new Scope(this, state, parent);
            _currentScope.Value = newScope;

            return newScope;
        }

        private sealed class Scope : IDisposable
        {
            private readonly LoggerExternalScopeProvider _provider;
            private bool _isDisposed;

            internal Scope(LoggerExternalScopeProvider provider, object? state, Scope? parent)
            {
                _provider = provider;
                State = state;
                Parent = parent;
            }

            public Scope? Parent { get; }

            public object? State { get; }

            public override string? ToString()
            {
                return State?.ToString();
            }

            public void Dispose()
            {
                if (!_isDisposed)
                {
                    _provider._currentScope.Value = Parent;
                    _isDisposed = true;
                }
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerFactoryExtensions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// ILoggerFactory extension methods for common scenarios.
    /// </summary>
    public static class LoggerFactoryExtensions
    {
        /// <summary>
        /// Creates a new <see cref="ILogger"/> instance using the full name of the given type.
        /// </summary>
        /// <param name="factory">The factory.</param>
        /// <typeparam name="T">The type.</typeparam>
        /// <returns>The <see cref="ILogger"/> that was created.</returns>
        public static ILogger<T> CreateLogger<T>(this ILoggerFactory factory)
        {
            ThrowHelper.ThrowIfNull(factory);

            return new Logger<T>(factory);
        }
        /// <summary>
        /// Creates a new <see cref="ILogger"/> instance using the full name of the given <paramref name="type"/>.
        /// </summary>
        /// <param name="factory">The factory.</param>
        /// <param name="type">The type.</param>
        /// <returns>The <see cref="ILogger"/> that was created.</returns>
        public static ILogger CreateLogger(this ILoggerFactory factory, Type type)
        {
            ThrowHelper.ThrowIfNull(factory);
            ThrowHelper.ThrowIfNull(type);

            return factory.CreateLogger(TypeNameHelper.GetTypeDisplayName(type, includeGenericParameters: false, nestedTypeDelimiter: '.'));
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerMessage.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Creates delegates which can be later cached to log messages in a performant way.
    /// </summary>
    public static class LoggerMessage
    {
        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, IDisposable?> DefineScope(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 0);

            var logValues = new LogValues(formatter);

            return logger => logger.BeginScope(logValues);
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, IDisposable?> DefineScope<T1>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 1);

            return (logger, arg1) => logger.BeginScope(new LogValues<T1>(formatter, arg1));
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, T2, IDisposable?> DefineScope<T1, T2>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 2);

            return (logger, arg1, arg2) => logger.BeginScope(new LogValues<T1, T2>(formatter, arg1, arg2));
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, T2, T3, IDisposable?> DefineScope<T1, T2, T3>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 3);

            return (logger, arg1, arg2, arg3) => logger.BeginScope(new LogValues<T1, T2, T3>(formatter, arg1, arg2, arg3));
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, T2, T3, T4, IDisposable?> DefineScope<T1, T2, T3, T4>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 4);

            return (logger, arg1, arg2, arg3, arg4) => logger.BeginScope(new LogValues<T1, T2, T3, T4>(formatter, arg1, arg2, arg3, arg4));
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, T2, T3, T4, T5, IDisposable?> DefineScope<T1, T2, T3, T4, T5>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 5);

            return (logger, arg1, arg2, arg3, arg4, arg5) => logger.BeginScope(new LogValues<T1, T2, T3, T4, T5>(formatter, arg1, arg2, arg3, arg4, arg5));
        }

        /// <summary>
        /// Creates a delegate which can be invoked to create a log scope.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T6">The type of the sixth parameter passed to the named format string.</typeparam>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log scope.</returns>
        public static Func<ILogger, T1, T2, T3, T4, T5, T6, IDisposable?> DefineScope<T1, T2, T3, T4, T5, T6>(string formatString)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 6);

            return (logger, arg1, arg2, arg3, arg4, arg5, arg6) => logger.BeginScope(new LogValues<T1, T2, T3, T4, T5, T6>(formatter, arg1, arg2, arg3, arg4, arg5, arg6));
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, Exception?> Define(LogLevel logLevel, EventId eventId, string formatString)
            => Define(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, Exception?> Define(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 0);

            void Log(ILogger logger, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues(formatter), exception, LogValues.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, Exception?> Define<T1>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, Exception?> Define<T1>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 1);

            void Log(ILogger logger, T1 arg1, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1>(formatter, arg1), exception, LogValues<T1>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, Exception?> Define<T1, T2>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1, T2>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, Exception?> Define<T1, T2>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 2);

            void Log(ILogger logger, T1 arg1, T2 arg2, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1, T2>(formatter, arg1, arg2), exception, LogValues<T1, T2>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, arg2, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, arg2, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, Exception?> Define<T1, T2, T3>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1, T2, T3>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, Exception?> Define<T1, T2, T3>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 3);

            void Log(ILogger logger, T1 arg1, T2 arg2, T3 arg3, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1, T2, T3>(formatter, arg1, arg2, arg3), exception, LogValues<T1, T2, T3>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, arg2, arg3, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, arg2, arg3, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, Exception?> Define<T1, T2, T3, T4>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1, T2, T3, T4>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, Exception?> Define<T1, T2, T3, T4>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 4);

            void Log(ILogger logger, T1 arg1, T2 arg2, T3 arg3, T4 arg4, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1, T2, T3, T4>(formatter, arg1, arg2, arg3, arg4), exception, LogValues<T1, T2, T3, T4>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, arg2, arg3, arg4, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, arg2, arg3, arg4, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, T5, Exception?> Define<T1, T2, T3, T4, T5>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1, T2, T3, T4, T5>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, T5, Exception?> Define<T1, T2, T3, T4, T5>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 5);

            void Log(ILogger logger, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1, T2, T3, T4, T5>(formatter, arg1, arg2, arg3, arg4, arg5), exception, LogValues<T1, T2, T3, T4, T5>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, arg2, arg3, arg4, arg5, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, arg2, arg3, arg4, arg5, exception);
                }
            };
        }

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T6">The type of the sixth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, T5, T6, Exception?> Define<T1, T2, T3, T4, T5, T6>(LogLevel logLevel, EventId eventId, string formatString)
            => Define<T1, T2, T3, T4, T5, T6>(logLevel, eventId, formatString, options: null);

        /// <summary>
        /// Creates a delegate which can be invoked for logging a message.
        /// </summary>
        /// <typeparam name="T1">The type of the first parameter passed to the named format string.</typeparam>
        /// <typeparam name="T2">The type of the second parameter passed to the named format string.</typeparam>
        /// <typeparam name="T3">The type of the third parameter passed to the named format string.</typeparam>
        /// <typeparam name="T4">The type of the fourth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T5">The type of the fifth parameter passed to the named format string.</typeparam>
        /// <typeparam name="T6">The type of the sixth parameter passed to the named format string.</typeparam>
        /// <param name="logLevel">The <see cref="LogLevel"/></param>
        /// <param name="eventId">The event id</param>
        /// <param name="formatString">The named format string</param>
        /// <param name="options">The <see cref="LogDefineOptions"/></param>
        /// <returns>A delegate which when invoked creates a log message.</returns>
        public static Action<ILogger, T1, T2, T3, T4, T5, T6, Exception?> Define<T1, T2, T3, T4, T5, T6>(LogLevel logLevel, EventId eventId, string formatString, LogDefineOptions? options)
        {
            LogValuesFormatter formatter = CreateLogValuesFormatter(formatString, expectedNamedParameterCount: 6);

            void Log(ILogger logger, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, Exception? exception)
            {
                logger.Log(logLevel, eventId, new LogValues<T1, T2, T3, T4, T5, T6>(formatter, arg1, arg2, arg3, arg4, arg5, arg6), exception, LogValues<T1, T2, T3, T4, T5, T6>.Callback);
            }

            if (options != null && options.SkipEnabledCheck)
            {
                return Log;
            }

            return (logger, arg1, arg2, arg3, arg4, arg5, arg6, exception) =>
            {
                if (logger.IsEnabled(logLevel))
                {
                    Log(logger, arg1, arg2, arg3, arg4, arg5, arg6, exception);
                }
            };
        }

        private static LogValuesFormatter CreateLogValuesFormatter(string formatString, int expectedNamedParameterCount)
        {
            var logValuesFormatter = new LogValuesFormatter(formatString);

            int actualCount = logValuesFormatter.ValueNames.Count;
            if (actualCount != expectedNamedParameterCount)
            {
                throw new ArgumentException(
                    SR.Format(SR.UnexpectedNumberOfNamedParameters, formatString, expectedNamedParameterCount, actualCount));
            }

            return logValuesFormatter;
        }

        private readonly struct LogValues : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;

            public LogValues(LogValuesFormatter formatter)
            {
                _formatter = formatter;
            }

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    if (index == 0)
                    {
                        return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                    }
                    throw new IndexOutOfRangeException(nameof(index));
                }
            }

            public int Count => 1;

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                yield return this[0];
            }

            public override string ToString() => _formatter.Format();

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;

            public LogValues(LogValuesFormatter formatter, T0 value0)
            {
                _formatter = formatter;
                _value0 = value0;
            }

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public int Count => 2;

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }


            public override string ToString() => _formatter.Format(_value0);

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0, T1> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0, T1>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;
            private readonly T1 _value1;

            public LogValues(LogValuesFormatter formatter, T0 value0, T1 value1)
            {
                _formatter = formatter;
                _value0 = value0;
                _value1 = value1;
            }

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[1], _value1);
                        case 2:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public int Count => 3;

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }

            public override string ToString() => _formatter.Format(_value0, _value1);

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0, T1, T2> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0, T1, T2>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;
            private readonly T1 _value1;
            private readonly T2 _value2;

            public int Count => 4;

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[1], _value1);
                        case 2:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[2], _value2);
                        case 3:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public LogValues(LogValuesFormatter formatter, T0 value0, T1 value1, T2 value2)
            {
                _formatter = formatter;
                _value0 = value0;
                _value1 = value1;
                _value2 = value2;
            }

            public override string ToString() => _formatter.Format(_value0, _value1, _value2);

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0, T1, T2, T3> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0, T1, T2, T3>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;
            private readonly T1 _value1;
            private readonly T2 _value2;
            private readonly T3 _value3;

            public int Count => 5;

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[1], _value1);
                        case 2:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[2], _value2);
                        case 3:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[3], _value3);
                        case 4:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public LogValues(LogValuesFormatter formatter, T0 value0, T1 value1, T2 value2, T3 value3)
            {
                _formatter = formatter;
                _value0 = value0;
                _value1 = value1;
                _value2 = value2;
                _value3 = value3;
            }

            private object?[] ToArray() => new object?[] { _value0, _value1, _value2, _value3 };

            public override string ToString() => _formatter.FormatWithOverwrite(ToArray());

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0, T1, T2, T3, T4> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0, T1, T2, T3, T4>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;
            private readonly T1 _value1;
            private readonly T2 _value2;
            private readonly T3 _value3;
            private readonly T4 _value4;

            public int Count => 6;

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[1], _value1);
                        case 2:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[2], _value2);
                        case 3:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[3], _value3);
                        case 4:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[4], _value4);
                        case 5:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public LogValues(LogValuesFormatter formatter, T0 value0, T1 value1, T2 value2, T3 value3, T4 value4)
            {
                _formatter = formatter;
                _value0 = value0;
                _value1 = value1;
                _value2 = value2;
                _value3 = value3;
                _value4 = value4;
            }

            private object?[] ToArray() => new object?[] { _value0, _value1, _value2, _value3, _value4 };

            public override string ToString() => _formatter.FormatWithOverwrite(ToArray());

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }

        private readonly struct LogValues<T0, T1, T2, T3, T4, T5> : IReadOnlyList<KeyValuePair<string, object?>>
        {
            public static readonly Func<LogValues<T0, T1, T2, T3, T4, T5>, Exception?, string> Callback = (state, exception) => state.ToString();

            private readonly LogValuesFormatter _formatter;
            private readonly T0 _value0;
            private readonly T1 _value1;
            private readonly T2 _value2;
            private readonly T3 _value3;
            private readonly T4 _value4;
            private readonly T5 _value5;

            public int Count => 7;

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    switch (index)
                    {
                        case 0:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[0], _value0);
                        case 1:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[1], _value1);
                        case 2:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[2], _value2);
                        case 3:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[3], _value3);
                        case 4:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[4], _value4);
                        case 5:
                            return new KeyValuePair<string, object?>(_formatter.ValueNames[5], _value5);
                        case 6:
                            return new KeyValuePair<string, object?>("{OriginalFormat}", _formatter.OriginalFormat);
                        default:
                            throw new IndexOutOfRangeException(nameof(index));
                    }
                }
            }

            public LogValues(LogValuesFormatter formatter, T0 value0, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5)
            {
                _formatter = formatter;
                _value0 = value0;
                _value1 = value1;
                _value2 = value2;
                _value3 = value3;
                _value4 = value4;
                _value5 = value5;
            }

            private object?[] ToArray() => new object?[] { _value0, _value1, _value2, _value3, _value4, _value5 };

            public override string ToString() => _formatter.FormatWithOverwrite(ToArray());

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator()
            {
                for (int i = 0; i < Count; ++i)
                {
                    yield return this[i];
                }
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                return GetEnumerator();
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerMessageAttribute.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Provides information to guide the production of a strongly-typed logging method.
    /// </summary>
    /// <remarks>
    /// <para>The method this attribute is applied to:</para>
    /// <para>   - Must be a partial method.</para>
    /// <para>   - Must return <c>void</c>.</para>
    /// <para>   - Must not be generic.</para>
    /// <para>   - Must have an <see cref="ILogger"/> as one of its parameters.</para>
    /// <para>   - Must have a <see cref="Microsoft.Extensions.Logging.LogLevel"/> as one of its parameters.</para>
    /// <para>   - None of the parameters can be generic.</para>
    /// </remarks>
    /// <example>
    /// <format type="text/markdown"><![CDATA[
    /// ```csharp
    /// static partial class Log
    /// {
    ///     [LoggerMessage(EventId = 0, Message = "Could not open socket for {hostName}")]
    ///     static partial void CouldNotOpenSocket(ILogger logger, LogLevel level, string hostName);
    /// }
    /// ```
    /// ]]></format>
    /// </example>
    [AttributeUsage(AttributeTargets.Method)]
    public sealed class LoggerMessageAttribute : Attribute
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="LoggerMessageAttribute"/> class
        /// which is used to guide the production of a strongly-typed logging method.
        /// </summary>
        public LoggerMessageAttribute() { }

        /// <summary>
        /// Initializes a new instance of the <see cref="LoggerMessageAttribute"/> class
        /// which is used to guide the production of a strongly-typed logging method.
        /// </summary>
        /// <param name="eventId">The log event Id.</param>
        /// <param name="level">The log level.</param>
        /// <param name="message">Format string of the log message.</param>
        public LoggerMessageAttribute(int eventId, LogLevel level, string message)
        {
            EventId = eventId;
            Level = level;
            Message = message;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="LoggerMessageAttribute"/> class
        /// which is used to guide the production of a strongly-typed logging method.
        /// </summary>
        /// <param name="level">The log level.</param>
        /// <param name="message">Format string of the log message.</param>
        public LoggerMessageAttribute(LogLevel level, string message)
        {
            Level = level;
            Message = message;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="LoggerMessageAttribute"/> class
        /// which is used to guide the production of a strongly-typed logging method.
        /// </summary>
        /// <param name="level">The log level.</param>
        public LoggerMessageAttribute(LogLevel level)
        {
            Level = level;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="LoggerMessageAttribute"/> class
        /// which is used to guide the production of a strongly-typed logging method.
        /// </summary>
        /// <param name="message">Format string of the log message.</param>
        public LoggerMessageAttribute(string message)
        {
            Message = message;
        }

        /// <summary>
        /// Gets the logging event id for the logging method.
        /// </summary>
        public int EventId { get; set; } = -1;

        /// <summary>
        /// Gets or sets the logging event name for the logging method.
        /// </summary>
        /// <remarks>
        /// This will equal the method name if not specified.
        /// </remarks>
        public string? EventName { get; set; }

        /// <summary>
        /// Gets the logging level for the logging method.
        /// </summary>
        public LogLevel Level { get; set; } = LogLevel.None;

        /// <summary>
        /// Gets the message text for the logging method.
        /// </summary>
        public string Message { get; set; } = "";

        /// <summary>
        /// Gets the flag to skip IsEnabled check for the logging method.
        /// </summary>
        public bool SkipEnabledCheck { get; set; }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LoggerT.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Delegates to a new <see cref="ILogger"/> instance using the full name of the given type, created by the
    /// provided <see cref="ILoggerFactory"/>.
    /// </summary>
    /// <typeparam name="T">The type.</typeparam>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    public class Logger<T> : ILogger<T>
    {
        [DebuggerBrowsable(DebuggerBrowsableState.RootHidden)]
        private readonly ILogger _logger;

        /// <summary>
        /// Creates a new <see cref="Logger{T}"/>.
        /// </summary>
        /// <param name="factory">The factory.</param>
        public Logger(ILoggerFactory factory)
        {
            ThrowHelper.ThrowIfNull(factory);

            _logger = factory.CreateLogger(GetCategoryName());
        }

        /// <inheritdoc />
        IDisposable? ILogger.BeginScope<TState>(TState state)
        {
            return _logger.BeginScope(state);
        }

        /// <inheritdoc />
        bool ILogger.IsEnabled(LogLevel logLevel)
        {
            return _logger.IsEnabled(logLevel);
        }

        /// <inheritdoc />
        void ILogger.Log<TState>(LogLevel logLevel, EventId eventId, TState state, Exception? exception, Func<TState, Exception?, string> formatter)
        {
            _logger.Log(logLevel, eventId, state, exception, formatter);
        }

        private static string GetCategoryName() => TypeNameHelper.GetTypeDisplayName(typeof(T), includeGenericParameters: false, nestedTypeDelimiter: '.');

        internal string DebuggerToString()
        {
            return DebuggerDisplayFormatting.DebuggerToString(GetCategoryName(), this);
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LogLevel.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Defines logging severity levels.
    /// </summary>
    public enum LogLevel
    {
        /// <summary>
        /// Logs that contain the most detailed messages. These messages may contain sensitive application data.
        /// These messages are disabled by default and should never be enabled in a production environment.
        /// </summary>
        Trace = 0,

        /// <summary>
        /// Logs that are used for interactive investigation during development.  These logs should primarily contain
        /// information useful for debugging and have no long-term value.
        /// </summary>
        Debug = 1,

        /// <summary>
        /// Logs that track the general flow of the application. These logs should have long-term value.
        /// </summary>
        Information = 2,

        /// <summary>
        /// Logs that highlight an abnormal or unexpected event in the application flow, but do not otherwise cause the
        /// application execution to stop.
        /// </summary>
        Warning = 3,

        /// <summary>
        /// Logs that highlight when the current flow of execution is stopped due to a failure. These should indicate a
        /// failure in the current activity, not an application-wide failure.
        /// </summary>
        Error = 4,

        /// <summary>
        /// Logs that describe an unrecoverable application or system crash, or a catastrophic failure that requires
        /// immediate attention.
        /// </summary>
        Critical = 5,

        /// <summary>
        /// Not used for writing log messages. Specifies that a logging category should not write any messages.
        /// </summary>
        None = 6,
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/LogValuesFormatter.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Formatter to convert the named format items like {NamedformatItem} to <see cref="string.Format(IFormatProvider, string, object)"/> format.
    /// </summary>
    internal sealed class LogValuesFormatter
    {
        private const string NullValue = "(null)";
        private static readonly char[] FormatDelimiters = { ',', ':' };
        private readonly List<string> _valueNames = new List<string>();
#if NET8_0_OR_GREATER
        private readonly CompositeFormat _format;
#else
        private readonly string _format;
#endif

        // NOTE: If this assembly ever builds for netcoreapp, the below code should change to:
        // - Be annotated as [SkipLocalsInit] to avoid zero'ing the stackalloc'd char span
        // - Format _valueNames.Count directly into a span

        public LogValuesFormatter(string format)
        {
            ThrowHelper.ThrowIfNull(format);

            OriginalFormat = format;

            var vsb = new ValueStringBuilder(stackalloc char[256]);
            int scanIndex = 0;
            int endIndex = format.Length;

            while (scanIndex < endIndex)
            {
                int openBraceIndex = FindBraceIndex(format, '{', scanIndex, endIndex);
                if (scanIndex == 0 && openBraceIndex == endIndex)
                {
                    // No holes found.
                    _format =
#if NET8_0_OR_GREATER
                        CompositeFormat.Parse(format);
#else
                        format;
#endif
                    return;
                }

                int closeBraceIndex = FindBraceIndex(format, '}', openBraceIndex, endIndex);

                if (closeBraceIndex == endIndex)
                {
                    vsb.Append(format.AsSpan(scanIndex, endIndex - scanIndex));
                    scanIndex = endIndex;
                }
                else
                {
                    // Format item syntax : { index[,alignment][ :formatString] }.
                    int formatDelimiterIndex = FindIndexOfAny(format, FormatDelimiters, openBraceIndex, closeBraceIndex);

                    vsb.Append(format.AsSpan(scanIndex, openBraceIndex - scanIndex + 1));
                    vsb.Append(_valueNames.Count.ToString());
                    _valueNames.Add(format.Substring(openBraceIndex + 1, formatDelimiterIndex - openBraceIndex - 1));
                    vsb.Append(format.AsSpan(formatDelimiterIndex, closeBraceIndex - formatDelimiterIndex + 1));

                    scanIndex = closeBraceIndex + 1;
                }
            }

            _format =
#if NET8_0_OR_GREATER
                CompositeFormat.Parse(vsb.ToString());
#else
                vsb.ToString();
#endif
        }

        public string OriginalFormat { get; private set; }
        public List<string> ValueNames => _valueNames;

        private static int FindBraceIndex(string format, char brace, int startIndex, int endIndex)
        {
            // Example: {{prefix{{{Argument}}}suffix}}.
            int braceIndex = endIndex;
            int scanIndex = startIndex;
            int braceOccurrenceCount = 0;

            while (scanIndex < endIndex)
            {
                if (braceOccurrenceCount > 0 && format[scanIndex] != brace)
                {
                    if (braceOccurrenceCount % 2 == 0)
                    {
                        // Even number of '{' or '}' found. Proceed search with next occurrence of '{' or '}'.
                        braceOccurrenceCount = 0;
                        braceIndex = endIndex;
                    }
                    else
                    {
                        // An unescaped '{' or '}' found.
                        break;
                    }
                }
                else if (format[scanIndex] == brace)
                {
                    if (brace == '}')
                    {
                        if (braceOccurrenceCount == 0)
                        {
                            // For '}' pick the first occurrence.
                            braceIndex = scanIndex;
                        }
                    }
                    else
                    {
                        // For '{' pick the last occurrence.
                        braceIndex = scanIndex;
                    }

                    braceOccurrenceCount++;
                }

                scanIndex++;
            }

            return braceIndex;
        }

        private static int FindIndexOfAny(string format, char[] chars, int startIndex, int endIndex)
        {
            int findIndex = format.IndexOfAny(chars, startIndex, endIndex - startIndex);
            return findIndex == -1 ? endIndex : findIndex;
        }

        public string Format(object?[]? values)
        {
            object?[]? formattedValues = values;

            if (values != null)
            {
                for (int i = 0; i < values.Length; i++)
                {
                    object formattedValue = FormatArgument(values[i]);
                    // If the formatted value is changed, we allocate and copy items to a new array to avoid mutating the array passed in to this method
                    if (!ReferenceEquals(formattedValue, values[i]))
                    {
                        formattedValues = new object[values.Length];
                        Array.Copy(values, formattedValues, i);
                        formattedValues[i++] = formattedValue;
                        for (; i < values.Length; i++)
                        {
                            formattedValues[i] = FormatArgument(values[i]);
                        }
                        break;
                    }
                }
            }

            return string.Format(CultureInfo.InvariantCulture, _format, formattedValues ?? Array.Empty<object>());
        }

        // NOTE: This method mutates the items in the array if needed to avoid extra allocations, and should only be used when caller expects this to happen
        internal string FormatWithOverwrite(object?[]? values)
        {
            if (values != null)
            {
                for (int i = 0; i < values.Length; i++)
                {
                    values[i] = FormatArgument(values[i]);
                }
            }

            return string.Format(CultureInfo.InvariantCulture, _format, values ?? Array.Empty<object>());
        }

        internal string Format()
        {
#if NET8_0_OR_GREATER
            return _format.Format;
#else
            return _format;
#endif
        }

#if NET8_0_OR_GREATER
        internal string Format<TArg0>(TArg0 arg0)
        {
            object? arg0String = null;
            return
                !TryFormatArgumentIfNullOrEnumerable(arg0, ref arg0String) ?
                string.Format(CultureInfo.InvariantCulture, _format, arg0) :
                string.Format(CultureInfo.InvariantCulture, _format, arg0String);
        }

        internal string Format<TArg0, TArg1>(TArg0 arg0, TArg1 arg1)
        {
            object? arg0String = null, arg1String = null;
            return
                !TryFormatArgumentIfNullOrEnumerable(arg0, ref arg0String) &&
                !TryFormatArgumentIfNullOrEnumerable(arg1, ref arg1String) ?
                string.Format(CultureInfo.InvariantCulture, _format, arg0, arg1) :
                string.Format(CultureInfo.InvariantCulture, _format, arg0String ?? arg0, arg1String ?? arg1);
        }

        internal string Format<TArg0, TArg1, TArg2>(TArg0 arg0, TArg1 arg1, TArg2 arg2)
        {
            object? arg0String = null, arg1String = null, arg2String = null;
            return
                !TryFormatArgumentIfNullOrEnumerable(arg0, ref arg0String) &&
                !TryFormatArgumentIfNullOrEnumerable(arg1, ref arg1String) &&
                !TryFormatArgumentIfNullOrEnumerable(arg2, ref arg2String) ?
                string.Format(CultureInfo.InvariantCulture, _format, arg0, arg1, arg2) :
                string.Format(CultureInfo.InvariantCulture, _format, arg0String ?? arg0, arg1String ?? arg1, arg2String ?? arg2);
        }
#else
        internal string Format(object? arg0) =>
            string.Format(CultureInfo.InvariantCulture, _format, FormatArgument(arg0));

        internal string Format(object? arg0, object? arg1) =>
            string.Format(CultureInfo.InvariantCulture, _format, FormatArgument(arg0), FormatArgument(arg1));

        internal string Format(object? arg0, object? arg1, object? arg2) =>
            string.Format(CultureInfo.InvariantCulture, _format, FormatArgument(arg0), FormatArgument(arg1), FormatArgument(arg2));
#endif

        public KeyValuePair<string, object?> GetValue(object?[] values, int index)
        {
            if (index < 0 || index > _valueNames.Count)
            {
                throw new IndexOutOfRangeException(nameof(index));
            }

            if (_valueNames.Count > index)
            {
                return new KeyValuePair<string, object?>(_valueNames[index], values[index]);
            }

            return new KeyValuePair<string, object?>("{OriginalFormat}", OriginalFormat);
        }

        public IEnumerable<KeyValuePair<string, object?>> GetValues(object[] values)
        {
            var valueArray = new KeyValuePair<string, object?>[values.Length + 1];
            for (int index = 0; index != _valueNames.Count; ++index)
            {
                valueArray[index] = new KeyValuePair<string, object?>(_valueNames[index], values[index]);
            }

            valueArray[valueArray.Length - 1] = new KeyValuePair<string, object?>("{OriginalFormat}", OriginalFormat);
            return valueArray;
        }

        private static object FormatArgument(object? value)
        {
            object? stringValue = null;
            return TryFormatArgumentIfNullOrEnumerable(value, ref stringValue) ? stringValue : value!;
        }

        private static bool TryFormatArgumentIfNullOrEnumerable<T>(T? value, [NotNullWhen(true)] ref object? stringValue)
        {
            if (value == null)
            {
                stringValue = NullValue;
                return true;
            }

            // if the value implements IEnumerable but isn't itself a string, build a comma separated string.
            if (value is not string && value is IEnumerable enumerable)
            {
                var vsb = new ValueStringBuilder(stackalloc char[256]);
                bool first = true;
                foreach (object? e in enumerable)
                {
                    if (!first)
                    {
                        vsb.Append(", ");
                    }

                    vsb.Append(e != null ? e.ToString() : NullValue);
                    first = false;
                }
                stringValue = vsb.ToString();
                return true;
            }

            return false;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/NullLogger.cs
namespace Microsoft.Extensions.Logging.Abstractions
{
    /// <summary>
    /// Minimalistic logger that does nothing.
    /// </summary>
    public class NullLogger : ILogger
    {
        /// <summary>
        /// Returns the shared instance of <see cref="NullLogger"/>.
        /// </summary>
        public static NullLogger Instance { get; } = new NullLogger();

        /// <summary>
        /// Initializes a new instance of the <see cref="NullLogger"/> class.
        /// </summary>
        private NullLogger()
        {
        }

        /// <inheritdoc />
        public IDisposable BeginScope<TState>(TState state) where TState : notnull
        {
            return NullScope.Instance;
        }

        /// <inheritdoc />
        public bool IsEnabled(LogLevel logLevel)
        {
            return false;
        }

        /// <inheritdoc />
        public void Log<TState>(LogLevel logLevel, EventId eventId, TState state, Exception? exception, Func<TState, Exception?, string> formatter)
        {
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/NullLoggerFactory.cs
namespace Microsoft.Extensions.Logging.Abstractions
{
    /// <summary>
    /// An <see cref="ILoggerFactory"/> used to create instance of
    /// <see cref="NullLogger"/> that logs nothing.
    /// </summary>
    public class NullLoggerFactory : ILoggerFactory
    {
        /// <summary>
        /// Creates a new <see cref="NullLoggerFactory"/> instance.
        /// </summary>
        public NullLoggerFactory() { }

        /// <summary>
        /// Returns the shared instance of <see cref="NullLoggerFactory"/>.
        /// </summary>
        public static readonly NullLoggerFactory Instance = new NullLoggerFactory();

        /// <inheritdoc />
        /// <remarks>
        /// This returns a <see cref="NullLogger"/> instance which logs nothing.
        /// </remarks>
        public ILogger CreateLogger(string name)
        {
            return NullLogger.Instance;
        }

        /// <inheritdoc />
        /// <remarks>
        /// This method ignores the parameter and does nothing.
        /// </remarks>
        public void AddProvider(ILoggerProvider provider)
        {
        }

        /// <inheritdoc />
        public void Dispose()
        {
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/NullLoggerProvider.cs
namespace Microsoft.Extensions.Logging.Abstractions
{
    /// <summary>
    /// Provider for the <see cref="NullLogger"/>.
    /// </summary>
    public class NullLoggerProvider : ILoggerProvider
    {
        /// <summary>
        /// Returns an instance of <see cref="NullLoggerProvider"/>.
        /// </summary>
        public static NullLoggerProvider Instance { get; } = new NullLoggerProvider();

        private NullLoggerProvider()
        {
        }

        /// <inheritdoc />
        public ILogger CreateLogger(string categoryName)
        {
            return NullLogger.Instance;
        }

        /// <inheritdoc />
        public void Dispose()
        {
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging.Abstractions/src/NullLoggerT.cs
namespace Microsoft.Extensions.Logging.Abstractions
{
    /// <summary>
    /// Minimalistic logger that does nothing.
    /// </summary>
    public class NullLogger<T> : ILogger<T>
    {
        /// <summary>
        /// Returns an instance of <see cref="NullLogger{T}"/>.
        /// </summary>
        /// <returns>An instance of <see cref="NullLogger{T}"/>.</returns>
        public static readonly NullLogger<T> Instance = new NullLogger<T>();

        /// <inheritdoc />
        public IDisposable BeginScope<TState>(TState state) where TState : notnull
        {
            return NullScope.Instance;
        }

        /// <inheritdoc />
        /// <remarks>
        /// This method ignores the parameters and does nothing.
        /// </remarks>
        public void Log<TState>(
            LogLevel logLevel,
            EventId eventId,
            TState state,
            Exception? exception,
            Func<TState, Exception?, string> formatter)
        {
        }

        /// <inheritdoc />
        public bool IsEnabled(LogLevel logLevel)
        {
            return false;
        }
    }
}

#nullable disable

namespace FxResources.Microsoft.Extensions.Logging.Abstractions
{
    internal static class SR
    {
    }
}

namespace System
{
    internal static partial class SR
    {
        private static ResourceManager s_resourceManager;

        internal static ResourceManager ResourceManager =>
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.Logging.Abstractions.SR));

        internal static string UnexpectedNumberOfNamedParameters => GetResourceString("UnexpectedNumberOfNamedParameters");
    }
}
