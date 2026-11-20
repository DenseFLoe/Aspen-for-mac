// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// Source files combined from dotnet/runtime at 5535e31a712343a63f5d7d796cd874e563e5ac14.
#define IL_EMIT
#define NET
#define NETCOREAPP
#define NETCOREAPP3_0_OR_GREATER
#define NETCOREAPP3_1_OR_GREATER
#define NET8_0_OR_GREATER
#nullable enable annotations

using Microsoft.Extensions.DependencyInjection.ServiceLookup;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Internal;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics.Tracing;
using System.Diagnostics;
using System.Linq.Expressions;
using System.Linq;
using System.Reflection.Emit;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: InternalsVisibleTo("Microsoft.Extensions.DependencyInjection.Tests, PublicKey=0024000004800000940000000602000000240000525341310004000001000100f33a29044fa9d740c9b3213a93e57c84b472c84e0b8a0e1ae48e67a9f8f6de9d5f7f3d52ac23e48ac51801f1dc950abe901da34d2a9e3baadb141a17c77ef3c565dd5ee5054b91cf63bb3c6ab83f72ab3aafe93d0fc3c2348b764fafb0b1c0733de51459aeab46580384bf9d74c4e28164b7cde247f891ba07891c9d872ad2bb")]
[assembly: InternalsVisibleTo("MicroBenchmarks, PublicKey=00240000048000009400000006020000002400005253413100040000010001004b86c4cb78549b34bab61a3b1800e23bfeb5b3ec390074041536a7e3cbd97f5f04cf0f857155a8928eaa29ebfd11cfbbad3ba70efea7bda3226c6a8d370a4cd303f714486b6ebc225985a638471e6ef571cc92a4613c00b8fa65d61ccee0cbe5f36330c9a01f4183559f1bef24cc2917c6d913e3a541333a1d05d9bed22b38cb")]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.DependencyInjection")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Default implementation of dependency injection for Microsoft.Extensions.DependencyInjection.")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.DependencyInjection")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]
[assembly: TypeForwardedTo(typeof(ServiceCollection))]

// src/libraries/Common/src/Extensions/ParameterDefaultValue/ParameterDefaultValue.netcoreapp.cs
namespace Microsoft.Extensions.Internal
{
    internal static partial class ParameterDefaultValue
    {
        public static bool CheckHasDefaultValue(ParameterInfo parameter, out bool tryToGetDefaultValue)
        {
            tryToGetDefaultValue = true;
            return parameter.HasDefaultValue;
        }
    }
}

// src/libraries/Common/src/Extensions/ParameterDefaultValue/ParameterDefaultValue.cs
namespace Microsoft.Extensions.Internal
{
    internal static partial class ParameterDefaultValue
    {
        public static bool TryGetDefaultValue(ParameterInfo parameter, out object? defaultValue)
        {
            bool hasDefaultValue = CheckHasDefaultValue(parameter, out bool tryToGetDefaultValue);
            defaultValue = null;

            if (hasDefaultValue)
            {
                if (tryToGetDefaultValue)
                {
                    defaultValue = parameter.DefaultValue;
                }

                bool isNullableParameterType = parameter.ParameterType.IsGenericType &&
                    parameter.ParameterType.GetGenericTypeDefinition() == typeof(Nullable<>);

                // Workaround for https://github.com/dotnet/runtime/issues/18599
                if (defaultValue == null && parameter.ParameterType.IsValueType
                    && !isNullableParameterType) // Nullable types should be left null
                {
                    defaultValue = CreateValueType(parameter.ParameterType);
                }

                [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2067:UnrecognizedReflectionPattern",
                    Justification = "CreateValueType is only called on a ValueType. You can always create an instance of a ValueType.")]
                static object? CreateValueType(Type t) =>
#if NETFRAMEWORK || NETSTANDARD2_0
                    FormatterServices.GetUninitializedObject(t);
#else
                    RuntimeHelpers.GetUninitializedObject(t);
#endif

                // Handle nullable enums
                if (defaultValue != null && isNullableParameterType)
                {
                    Type? underlyingType = Nullable.GetUnderlyingType(parameter.ParameterType);
                    if (underlyingType != null && underlyingType.IsEnum)
                    {
                        defaultValue = Enum.ToObject(underlyingType, defaultValue);
                    }
                }
            }

            return hasDefaultValue;
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

// src/libraries/Microsoft.Extensions.DependencyInjection/src/CallSiteJsonFormatter.cs
namespace Microsoft.Extensions.DependencyInjection
{
    internal sealed class CallSiteJsonFormatter: CallSiteVisitor<CallSiteJsonFormatter.CallSiteFormatterContext, object?>
    {
        internal static CallSiteJsonFormatter Instance = new CallSiteJsonFormatter();

        private CallSiteJsonFormatter()
        {
        }

        public string Format(ServiceCallSite callSite)
        {
            var stringBuilder = new StringBuilder();
            var context = new CallSiteFormatterContext(stringBuilder, 0, new HashSet<ServiceCallSite>());

            VisitCallSite(callSite, context);

            return stringBuilder.ToString();
        }

        protected override object? VisitConstructor(ConstructorCallSite constructorCallSite, CallSiteFormatterContext argument)
        {
            argument.WriteProperty("implementationType", constructorCallSite.ImplementationType);

            if (constructorCallSite.ParameterCallSites.Length > 0)
            {
                argument.StartProperty("arguments");

                CallSiteFormatterContext childContext = argument.StartArray();
                foreach (ServiceCallSite parameter in constructorCallSite.ParameterCallSites)
                {
                    childContext.StartArrayItem();
                    VisitCallSite(parameter, childContext);
                }
                argument.EndArray();
            }

            return null;
        }

        protected override object? VisitCallSiteMain(ServiceCallSite callSite, CallSiteFormatterContext argument)
        {
            if (argument.ShouldFormat(callSite))
            {
                CallSiteFormatterContext childContext = argument.StartObject();

                childContext.WriteProperty("serviceType", callSite.ServiceType);
                childContext.WriteProperty("kind", callSite.Kind);
                childContext.WriteProperty("cache", callSite.Cache.Location);

                base.VisitCallSiteMain(callSite, childContext);

                argument.EndObject();
            }
            else
            {
                CallSiteFormatterContext childContext = argument.StartObject();
                childContext.WriteProperty("ref", callSite.ServiceType);
                argument.EndObject();
            }

            return null;
        }

        protected override object? VisitConstant(ConstantCallSite constantCallSite, CallSiteFormatterContext argument)
        {
            argument.WriteProperty("value", constantCallSite.DefaultValue ?? "");

            return null;
        }

        protected override object? VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, CallSiteFormatterContext argument)
        {
            return null;
        }

        protected override object? VisitIEnumerable(IEnumerableCallSite enumerableCallSite, CallSiteFormatterContext argument)
        {
            argument.WriteProperty("itemType", enumerableCallSite.ItemType);
            argument.WriteProperty("size", enumerableCallSite.ServiceCallSites.Length);

            if (enumerableCallSite.ServiceCallSites.Length > 0)
            {
                argument.StartProperty("items");

                CallSiteFormatterContext childContext = argument.StartArray();
                foreach (ServiceCallSite item in enumerableCallSite.ServiceCallSites)
                {
                    childContext.StartArrayItem();
                    VisitCallSite(item, childContext);
                }
                argument.EndArray();
            }
            return null;
        }

        protected override object? VisitFactory(FactoryCallSite factoryCallSite, CallSiteFormatterContext argument)
        {
            argument.WriteProperty("method", factoryCallSite.Factory.Method);

            return null;
        }

        internal struct CallSiteFormatterContext
        {
            private readonly HashSet<ServiceCallSite> _processedCallSites;

            public CallSiteFormatterContext(StringBuilder builder, int offset, HashSet<ServiceCallSite> processedCallSites)
            {
                Builder = builder;
                Offset = offset;
                _processedCallSites = processedCallSites;
                _firstItem = true;
            }

            private bool _firstItem;

            public int Offset { get; }
            public StringBuilder Builder { get; }

            public bool ShouldFormat(ServiceCallSite serviceCallSite)
            {
                return _processedCallSites.Add(serviceCallSite);
            }

            public CallSiteFormatterContext IncrementOffset()
            {
                return new CallSiteFormatterContext(Builder, Offset + 4, _processedCallSites)
                {
                    _firstItem = true
                };
            }

            public CallSiteFormatterContext StartObject()
            {
                Builder.Append('{');
                return IncrementOffset();
            }

            public void EndObject()
            {
                Builder.Append('}');
            }

            public void StartProperty(string name)
            {
                if (!_firstItem)
                {
                    Builder.Append(',');
                }
                else
                {
                    _firstItem = false;
                }

                Builder.Append('"').Append(name).Append("\":");
            }

            public void StartArrayItem()
            {
                if (!_firstItem)
                {
                    Builder.Append(',');
                }
                else
                {
                    _firstItem = false;
                }
            }

            public void WriteProperty(string name, object? value)
            {
                StartProperty(name);
                if (value != null)
                {
                    Builder.Append(" \"").Append(value).Append('"');
                }
                else
                {
                    Builder.Append( "null");
                }
            }

            public CallSiteFormatterContext StartArray()
            {
                Builder.Append('[');
                return IncrementOffset();
            }

            public void EndArray()
            {
                Builder.Append(']');
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/DefaultServiceProviderFactory.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Default implementation of <see cref="IServiceProviderFactory{TContainerBuilder}"/>.
    /// </summary>
    public class DefaultServiceProviderFactory : IServiceProviderFactory<IServiceCollection>
    {
        private readonly ServiceProviderOptions _options;

        /// <summary>
        /// Initializes a new instance of the <see cref="DefaultServiceProviderFactory"/> class
        /// with default options.
        /// </summary>
        public DefaultServiceProviderFactory() : this(ServiceProviderOptions.Default)
        {

        }

        /// <summary>
        /// Initializes a new instance of the <see cref="DefaultServiceProviderFactory"/> class
        /// with the specified <paramref name="options"/>.
        /// </summary>
        /// <param name="options">The options to use for this instance.</param>
        public DefaultServiceProviderFactory(ServiceProviderOptions options)
        {
            _options = options ?? throw new ArgumentNullException(nameof(options));
        }

        /// <inheritdoc />
        public IServiceCollection CreateBuilder(IServiceCollection services)
        {
            return services;
        }

        /// <inheritdoc />
        public IServiceProvider CreateServiceProvider(IServiceCollection containerBuilder)
        {
            return containerBuilder.BuildServiceProvider(_options);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/DependencyInjectionEventSource.cs
namespace Microsoft.Extensions.DependencyInjection
{
    [EventSource(Name = "Microsoft-Extensions-DependencyInjection")]
    internal sealed class DependencyInjectionEventSource : EventSource
    {
        public static readonly DependencyInjectionEventSource Log = new DependencyInjectionEventSource();

        public static class Keywords
        {
            public const EventKeywords ServiceProviderInitialized = (EventKeywords)0x1;
        }

        // Event source doesn't support large payloads so we chunk large payloads like formatted call site tree and descriptors
        private const int MaxChunkSize = 10 * 1024;

        private readonly List<WeakReference<ServiceProvider>> _providers = new();

        private DependencyInjectionEventSource() : base(EventSourceSettings.EtwSelfDescribingEventFormat)
        {
        }

        // NOTE
        // - The 'Start' and 'Stop' suffixes on the following event names have special meaning in EventSource. They
        //   enable creating 'activities'.
        //   For more information, take a look at the following blog post:
        //   https://blogs.msdn.microsoft.com/vancem/2015/09/14/exploring-eventsource-activity-correlation-and-causation-features/
        // - A stop event's event id must be next one after its start event.
        // - Avoid renaming methods or parameters marked with EventAttribute. EventSource uses these to form the event object.

        [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2026:RequiresUnreferencedCode",
            Justification = "Parameters to this method are primitive and are trimmer safe.")]
        [Event(1, Level = EventLevel.Verbose)]
        private void CallSiteBuilt(string serviceType, string callSite, int chunkIndex, int chunkCount, int serviceProviderHashCode)
        {
            WriteEvent(1, serviceType, callSite, chunkIndex, chunkCount, serviceProviderHashCode);
        }

        [Event(2, Level = EventLevel.Verbose)]
        public void ServiceResolved(string serviceType, int serviceProviderHashCode)
        {
            WriteEvent(2, serviceType, serviceProviderHashCode);
        }

        [Event(3, Level = EventLevel.Verbose)]
        public void ExpressionTreeGenerated(string serviceType, int nodeCount, int serviceProviderHashCode)
        {
            WriteEvent(3, serviceType, nodeCount, serviceProviderHashCode);
        }

        [Event(4, Level = EventLevel.Verbose)]
        public void DynamicMethodBuilt(string serviceType, int methodSize, int serviceProviderHashCode)
        {
            WriteEvent(4, serviceType, methodSize, serviceProviderHashCode);
        }

        [Event(5, Level = EventLevel.Verbose)]
        public void ScopeDisposed(int serviceProviderHashCode, int scopedServicesResolved, int disposableServices)
        {
            WriteEvent(5, serviceProviderHashCode, scopedServicesResolved, disposableServices);
        }

        [Event(6, Level = EventLevel.Error)]
        public void ServiceRealizationFailed(string? exceptionMessage, int serviceProviderHashCode)
        {
            WriteEvent(6, exceptionMessage, serviceProviderHashCode);
        }

        [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2026:RequiresUnreferencedCode",
            Justification = "Parameters to this method are primitive and are trimmer safe.")]
        [Event(7, Level = EventLevel.Informational, Keywords = Keywords.ServiceProviderInitialized)]
        private void ServiceProviderBuilt(int serviceProviderHashCode, int singletonServices, int scopedServices, int transientServices, int closedGenericsServices, int openGenericsServices)
        {
            WriteEvent(7, serviceProviderHashCode, singletonServices, scopedServices, transientServices, closedGenericsServices, openGenericsServices);
        }

        [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2026:RequiresUnreferencedCode",
            Justification = "Parameters to this method are primitive and are trimmer safe.")]
        [Event(8, Level = EventLevel.Informational, Keywords = Keywords.ServiceProviderInitialized)]
        private void ServiceProviderDescriptors(int serviceProviderHashCode, string descriptors, int chunkIndex, int chunkCount)
        {
            WriteEvent(8, serviceProviderHashCode, descriptors, chunkIndex, chunkCount);
        }

        [NonEvent]
        public void ServiceResolved(ServiceProvider provider, Type serviceType)
        {
            if (IsEnabled(EventLevel.Verbose, EventKeywords.All))
            {
                ServiceResolved(serviceType.ToString(), provider.GetHashCode());
            }
        }

        [NonEvent]
        public void CallSiteBuilt(ServiceProvider provider, Type serviceType, ServiceCallSite callSite)
        {
            if (IsEnabled(EventLevel.Verbose, EventKeywords.All))
            {
                string format = CallSiteJsonFormatter.Instance.Format(callSite);
                int chunkCount = format.Length / MaxChunkSize + (format.Length % MaxChunkSize > 0 ? 1 : 0);

                int providerHashCode = provider.GetHashCode();
                for (int i = 0; i < chunkCount; i++)
                {
                    CallSiteBuilt(
                        serviceType.ToString(),
                        format.Substring(i * MaxChunkSize, Math.Min(MaxChunkSize, format.Length - i * MaxChunkSize)), i, chunkCount,
                        providerHashCode);
                }
            }
        }

        [NonEvent]
        public void DynamicMethodBuilt(ServiceProvider provider, Type serviceType, int methodSize)
        {
            if (IsEnabled(EventLevel.Verbose, EventKeywords.All))
            {
                DynamicMethodBuilt(serviceType.ToString(), methodSize, provider.GetHashCode());
            }
        }

        [NonEvent]
        public void ServiceRealizationFailed(Exception exception, int serviceProviderHashCode)
        {
            if (IsEnabled(EventLevel.Error, EventKeywords.All))
            {
                ServiceRealizationFailed(exception.ToString(), serviceProviderHashCode);
            }
        }

        [NonEvent]
        public void ServiceProviderBuilt(ServiceProvider provider)
        {
            lock (_providers)
            {
                _providers.Add(new WeakReference<ServiceProvider>(provider));
            }

            WriteServiceProviderBuilt(provider);
        }

        [NonEvent]
        public void ServiceProviderDisposed(ServiceProvider provider)
        {
            lock (_providers)
            {
                for (int i = _providers.Count - 1; i >= 0; i--)
                {
                    // remove the provider, along with any stale references
                    WeakReference<ServiceProvider> reference = _providers[i];
                    if (!reference.TryGetTarget(out ServiceProvider? target) || target == provider)
                    {
                        _providers.RemoveAt(i);
                    }
                }
            }
        }

        [NonEvent]
        private void WriteServiceProviderBuilt(ServiceProvider provider)
        {
            if (IsEnabled(EventLevel.Informational, Keywords.ServiceProviderInitialized))
            {
                int singletonServices = 0;
                int scopedServices = 0;
                int transientServices = 0;
                int closedGenericsServices = 0;
                int openGenericsServices = 0;

                StringBuilder descriptorBuilder = new StringBuilder("{ \"descriptors\":[ ");
                bool firstDescriptor = true;
                foreach (ServiceDescriptor descriptor in provider.CallSiteFactory.Descriptors)
                {
                    if (firstDescriptor)
                    {
                        firstDescriptor = false;
                    }
                    else
                    {
                        descriptorBuilder.Append(", ");
                    }

                    AppendServiceDescriptor(descriptorBuilder, descriptor);

                    switch (descriptor.Lifetime)
                    {
                        case ServiceLifetime.Singleton:
                            singletonServices++;
                            break;
                        case ServiceLifetime.Scoped:
                            scopedServices++;
                            break;
                        case ServiceLifetime.Transient:
                            transientServices++;
                            break;
                    }

                    if (descriptor.ServiceType.IsGenericType)
                    {
                        if (descriptor.ServiceType.IsConstructedGenericType)
                        {
                            closedGenericsServices++;
                        }
                        else
                        {
                            openGenericsServices++;
                        }
                    }
                }
                descriptorBuilder.Append(" ] }");

                int providerHashCode = provider.GetHashCode();
                ServiceProviderBuilt(providerHashCode, singletonServices, scopedServices, transientServices, closedGenericsServices, openGenericsServices);

                string descriptorString = descriptorBuilder.ToString();
                int chunkCount = descriptorString.Length / MaxChunkSize + (descriptorString.Length % MaxChunkSize > 0 ? 1 : 0);

                for (int i = 0; i < chunkCount; i++)
                {
                    ServiceProviderDescriptors(
                        providerHashCode,
                        descriptorString.Substring(i * MaxChunkSize, Math.Min(MaxChunkSize, descriptorString.Length - i * MaxChunkSize)), i, chunkCount);
                }
            }
        }

        [NonEvent]
        private static void AppendServiceDescriptor(StringBuilder builder, ServiceDescriptor descriptor)
        {
            builder.Append("{ \"serviceType\": \"");
            builder.Append(descriptor.ServiceType);
            builder.Append("\", \"lifetime\": \"");
            builder.Append(descriptor.Lifetime);
            builder.Append("\", ");

            if (descriptor.HasImplementationType())
            {
                builder.Append("\"implementationType\": \"");
                builder.Append(descriptor.GetImplementationType());
            }
            else if (!descriptor.IsKeyedService && descriptor.ImplementationFactory != null)
            {
                builder.Append("\"implementationFactory\": \"");
                builder.Append(descriptor.ImplementationFactory.Method);
            }
            else if (descriptor.IsKeyedService && descriptor.KeyedImplementationFactory != null)
            {
                builder.Append("\"implementationFactory\": \"");
                builder.Append(descriptor.KeyedImplementationFactory.Method);
            }
            else if (descriptor.HasImplementationInstance())
            {
                object? instance = descriptor.GetImplementationInstance();
                Debug.Assert(instance != null, "descriptor.ImplementationInstance != null");
                builder.Append("\"implementationInstance\": \"");
                builder.Append(instance.GetType());
                builder.Append(" (instance)");
            }
            else
            {
                builder.Append("\"unknown\": \"");
            }

            builder.Append("\" }");
        }

        protected override void OnEventCommand(EventCommandEventArgs command)
        {
            if (command.Command == EventCommand.Enable)
            {
                // When this EventSource becomes enabled, write out the existing ServiceProvider information
                // because building the ServiceProvider happens early in the process. This way a listener
                // can get this information, even if they attach while the process is running.

                lock (_providers)
                {
                    foreach (WeakReference<ServiceProvider> reference in _providers)
                    {
                        if (reference.TryGetTarget(out ServiceProvider? provider))
                        {
                            WriteServiceProviderBuilt(provider);
                        }
                    }
                }
            }
        }
    }

    internal static class DependencyInjectionEventSourceExtensions
    {
        // This is an extension method because this assembly is trimmed at a "type granular" level in Blazor,
        // and the whole DependencyInjectionEventSource type can't be trimmed. So extracting this to a separate
        // type allows for the System.Linq.Expressions usage to be trimmed by the ILLinker.
        public static void ExpressionTreeGenerated(this DependencyInjectionEventSource source, ServiceProvider provider, Type serviceType, Expression expression)
        {
            if (source.IsEnabled(EventLevel.Verbose, EventKeywords.All))
            {
                var visitor = new NodeCountingVisitor();
                visitor.Visit(expression);
                source.ExpressionTreeGenerated(serviceType.ToString(), visitor.NodeCount, provider.GetHashCode());
            }
        }

        private sealed class NodeCountingVisitor : ExpressionVisitor
        {
            public int NodeCount { get; private set; }

            [return: NotNullIfNotNull(nameof(e))]
            public override Expression? Visit(Expression? e)
            {
                base.Visit(e);
                NodeCount++;
                return e;
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceCollectionContainerBuilderExtensions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for building a <see cref="ServiceProvider"/> from an <see cref="IServiceCollection"/>.
    /// </summary>
    public static class ServiceCollectionContainerBuilderExtensions
    {
        /// <summary>
        /// Creates a <see cref="ServiceProvider"/> containing services from the provided <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> containing service descriptors.</param>
        /// <returns>The <see cref="ServiceProvider"/>.</returns>
        public static ServiceProvider BuildServiceProvider(this IServiceCollection services)
        {
            return BuildServiceProvider(services, ServiceProviderOptions.Default);
        }

        /// <summary>
        /// Creates a <see cref="ServiceProvider"/> containing services from the provided <see cref="IServiceCollection"/>
        /// optionally enabling scope validation.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> containing service descriptors.</param>
        /// <param name="validateScopes">
        /// <c>true</c> to perform check verifying that scoped services never gets resolved from root provider; otherwise <c>false</c>.
        /// </param>
        /// <returns>The <see cref="ServiceProvider"/>.</returns>
        public static ServiceProvider BuildServiceProvider(this IServiceCollection services, bool validateScopes)
        {
            return services.BuildServiceProvider(new ServiceProviderOptions { ValidateScopes = validateScopes });
        }

        /// <summary>
        /// Creates a <see cref="ServiceProvider"/> containing services from the provided <see cref="IServiceCollection"/>
        /// optionally enabling scope validation.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> containing service descriptors.</param>
        /// <param name="options">
        /// Configures various service provider behaviors.
        /// </param>
        /// <returns>The <see cref="ServiceProvider"/>.</returns>
        public static ServiceProvider BuildServiceProvider(this IServiceCollection services, ServiceProviderOptions options)
        {
            if (services is null)
            {
                throw new ArgumentNullException(nameof(services));
            }
            if (options is null)
            {
                throw new ArgumentNullException(nameof(options));
            }

            return new ServiceProvider(services, options);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteChain.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class CallSiteChain
    {
        private readonly Dictionary<ServiceIdentifier, ChainItemInfo> _callSiteChain;

        public CallSiteChain()
        {
            _callSiteChain = new Dictionary<ServiceIdentifier, ChainItemInfo>();
        }

        public void CheckCircularDependency(ServiceIdentifier serviceIdentifier)
        {
            if (_callSiteChain.ContainsKey(serviceIdentifier))
            {
                throw new InvalidOperationException(CreateCircularDependencyExceptionMessage(serviceIdentifier));
            }
        }

        public void Remove(ServiceIdentifier serviceIdentifier)
        {
            _callSiteChain.Remove(serviceIdentifier);
        }

        public void Add(ServiceIdentifier serviceIdentifier, Type? implementationType = null)
        {
            _callSiteChain[serviceIdentifier] = new ChainItemInfo(_callSiteChain.Count, implementationType);
        }

        private string CreateCircularDependencyExceptionMessage(ServiceIdentifier serviceIdentifier)
        {
            var messageBuilder = new StringBuilder();
            messageBuilder.Append(SR.Format(SR.CircularDependencyException, TypeNameHelper.GetTypeDisplayName(serviceIdentifier.ServiceType)));
            messageBuilder.AppendLine();

            AppendResolutionPath(messageBuilder, serviceIdentifier);

            return messageBuilder.ToString();
        }

        private void AppendResolutionPath(StringBuilder builder, ServiceIdentifier currentlyResolving)
        {
            var ordered = new List<KeyValuePair<ServiceIdentifier, ChainItemInfo>>(_callSiteChain);
            ordered.Sort((a, b) => a.Value.Order.CompareTo(b.Value.Order));

            foreach (KeyValuePair<ServiceIdentifier, ChainItemInfo> pair in ordered)
            {
                ServiceIdentifier serviceIdentifier = pair.Key;
                Type? implementationType = pair.Value.ImplementationType;
                if (implementationType == null || serviceIdentifier.ServiceType == implementationType)
                {
                    builder.Append(TypeNameHelper.GetTypeDisplayName(serviceIdentifier.ServiceType));
                }
                else
                {
                    builder.Append(TypeNameHelper.GetTypeDisplayName(serviceIdentifier.ServiceType))
                           .Append('(')
                           .Append(TypeNameHelper.GetTypeDisplayName(implementationType))
                           .Append(')');
                }

                builder.Append(" -> ");
            }

            builder.Append(TypeNameHelper.GetTypeDisplayName(currentlyResolving.ServiceType));
        }

        private readonly struct ChainItemInfo
        {
            public int Order { get; }
            public Type? ImplementationType { get; }

            public ChainItemInfo(int order, Type? implementationType)
            {
                Order = order;
                ImplementationType = implementationType;
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteFactory.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class CallSiteFactory : IServiceProviderIsService, IServiceProviderIsKeyedService
    {
        private const int DefaultSlot = 0;
        private readonly ServiceDescriptor[] _descriptors;
        private readonly ConcurrentDictionary<ServiceCacheKey, ServiceCallSite> _callSiteCache = new ConcurrentDictionary<ServiceCacheKey, ServiceCallSite>();
        private readonly Dictionary<ServiceIdentifier, ServiceDescriptorCacheItem> _descriptorLookup = new Dictionary<ServiceIdentifier, ServiceDescriptorCacheItem>();
        private readonly ConcurrentDictionary<ServiceIdentifier, object> _callSiteLocks = new ConcurrentDictionary<ServiceIdentifier, object>();

        private readonly StackGuard _stackGuard;

        public CallSiteFactory(ICollection<ServiceDescriptor> descriptors)
        {
            _stackGuard = new StackGuard();
            _descriptors = new ServiceDescriptor[descriptors.Count];
            descriptors.CopyTo(_descriptors, 0);

            Populate();
        }

        internal ServiceDescriptor[] Descriptors => _descriptors;

        private void Populate()
        {
            foreach (ServiceDescriptor descriptor in _descriptors)
            {
                Type serviceType = descriptor.ServiceType;
                if (serviceType.IsGenericTypeDefinition)
                {
                    Type? implementationType = descriptor.GetImplementationType();

                    if (implementationType == null || !implementationType.IsGenericTypeDefinition)
                    {
                        throw new ArgumentException(
                            SR.Format(SR.OpenGenericServiceRequiresOpenGenericImplementation, serviceType),
                            "descriptors");
                    }

                    if (implementationType.IsAbstract || implementationType.IsInterface)
                    {
                        throw new ArgumentException(
                            SR.Format(SR.TypeCannotBeActivated, implementationType, serviceType));
                    }

                    Type[] serviceTypeGenericArguments = serviceType.GetGenericArguments();
                    Type[] implementationTypeGenericArguments = implementationType.GetGenericArguments();
                    if (serviceTypeGenericArguments.Length != implementationTypeGenericArguments.Length)
                    {
                        throw new ArgumentException(
                            SR.Format(SR.ArityOfOpenGenericServiceNotEqualArityOfOpenGenericImplementation, serviceType, implementationType), "descriptors");
                    }

                    if (ServiceProvider.VerifyOpenGenericServiceTrimmability)
                    {
                        ValidateTrimmingAnnotations(serviceType, serviceTypeGenericArguments, implementationType, implementationTypeGenericArguments);
                    }
                }
                else if (descriptor.TryGetImplementationType(out Type? implementationType))
                {
                    Debug.Assert(implementationType != null);

                    if (implementationType.IsGenericTypeDefinition ||
                        implementationType.IsAbstract ||
                        implementationType.IsInterface)
                    {
                        throw new ArgumentException(
                            SR.Format(SR.TypeCannotBeActivated, implementationType, serviceType));
                    }
                }

                var cacheKey = ServiceIdentifier.FromDescriptor(descriptor);
                _descriptorLookup.TryGetValue(cacheKey, out ServiceDescriptorCacheItem cacheItem);
                _descriptorLookup[cacheKey] = cacheItem.Add(descriptor);
            }
        }

        /// <summary>
        /// Validates that two generic type definitions have compatible trimming annotations on their generic arguments.
        /// </summary>
        /// <remarks>
        /// When open generic types are used in DI, there is an error when the concrete implementation type
        /// has [DynamicallyAccessedMembers] attributes on a generic argument type, but the interface/service type
        /// doesn't have matching annotations. The problem is that the trimmer doesn't see the members that need to
        /// be preserved on the type being passed to the generic argument. But when the interface/service type also has
        /// the annotations, the trimmer will see which members need to be preserved on the closed generic argument type.
        /// </remarks>
        private static void ValidateTrimmingAnnotations(
            Type serviceType,
            Type[] serviceTypeGenericArguments,
            Type implementationType,
            Type[] implementationTypeGenericArguments)
        {
            Debug.Assert(serviceTypeGenericArguments.Length == implementationTypeGenericArguments.Length);

            for (int i = 0; i < serviceTypeGenericArguments.Length; i++)
            {
                Type serviceGenericType = serviceTypeGenericArguments[i];
                Type implementationGenericType = implementationTypeGenericArguments[i];

                DynamicallyAccessedMemberTypes serviceDynamicallyAccessedMembers = GetDynamicallyAccessedMemberTypes(serviceGenericType);
                DynamicallyAccessedMemberTypes implementationDynamicallyAccessedMembers = GetDynamicallyAccessedMemberTypes(implementationGenericType);

                if (!AreCompatible(serviceDynamicallyAccessedMembers, implementationDynamicallyAccessedMembers))
                {
                    throw new ArgumentException(SR.Format(SR.TrimmingAnnotationsDoNotMatch, implementationType.FullName, serviceType.FullName));
                }

                bool serviceHasNewConstraint = serviceGenericType.GenericParameterAttributes.HasFlag(GenericParameterAttributes.DefaultConstructorConstraint);
                bool implementationHasNewConstraint = implementationGenericType.GenericParameterAttributes.HasFlag(GenericParameterAttributes.DefaultConstructorConstraint);
                if (implementationHasNewConstraint && !serviceHasNewConstraint)
                {
                    throw new ArgumentException(SR.Format(SR.TrimmingAnnotationsDoNotMatch_NewConstraint, implementationType.FullName, serviceType.FullName));
                }
            }
        }

        private static DynamicallyAccessedMemberTypes GetDynamicallyAccessedMemberTypes(Type serviceGenericType)
        {
            foreach (CustomAttributeData attributeData in serviceGenericType.GetCustomAttributesData())
            {
                if (attributeData.AttributeType.FullName == "System.Diagnostics.CodeAnalysis.DynamicallyAccessedMembersAttribute" &&
                    attributeData.ConstructorArguments.Count == 1 &&
                    attributeData.ConstructorArguments[0].ArgumentType.FullName == "System.Diagnostics.CodeAnalysis.DynamicallyAccessedMemberTypes")
                {
                    return (DynamicallyAccessedMemberTypes)(int)attributeData.ConstructorArguments[0].Value!;
                }
            }

            return DynamicallyAccessedMemberTypes.None;
        }

        private static bool AreCompatible(DynamicallyAccessedMemberTypes serviceDynamicallyAccessedMembers, DynamicallyAccessedMemberTypes implementationDynamicallyAccessedMembers)
        {
            // The DynamicallyAccessedMemberTypes don't need to exactly match.
            // The service type needs to preserve a superset of the members required by the implementation type.
            return serviceDynamicallyAccessedMembers.HasFlag(implementationDynamicallyAccessedMembers);
        }

        // For unit testing
        internal int? GetSlot(ServiceDescriptor serviceDescriptor)
        {
            if (_descriptorLookup.TryGetValue(ServiceIdentifier.FromDescriptor(serviceDescriptor), out ServiceDescriptorCacheItem item))
            {
                return item.GetSlot(serviceDescriptor);
            }

            return null;
        }

        internal ServiceCallSite? GetCallSite(ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain) =>
            _callSiteCache.TryGetValue(new ServiceCacheKey(serviceIdentifier, DefaultSlot), out ServiceCallSite? site) ? site :
            CreateCallSite(serviceIdentifier, callSiteChain);

        internal ServiceCallSite? GetCallSite(ServiceDescriptor serviceDescriptor, CallSiteChain callSiteChain)
        {
            var serviceIdentifier = ServiceIdentifier.FromDescriptor(serviceDescriptor);
            if (_descriptorLookup.TryGetValue(serviceIdentifier, out ServiceDescriptorCacheItem descriptor))
            {
                return TryCreateExact(serviceDescriptor, serviceIdentifier, callSiteChain, descriptor.GetSlot(serviceDescriptor));
            }

            Debug.Fail("_descriptorLookup didn't contain requested serviceDescriptor");
            return null;
        }

        private ServiceCallSite? CreateCallSite(ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain)
        {
            if (!_stackGuard.TryEnterOnCurrentStack())
            {
                return _stackGuard.RunOnEmptyStack(CreateCallSite, serviceIdentifier, callSiteChain);
            }

            // We need to lock the resolution process for a single service type at a time:
            // Consider the following:
            // C -> D -> A
            // E -> D -> A
            // Resolving C and E in parallel means that they will be modifying the callsite cache concurrently
            // to add the entry for C and E, but the resolution of D and A is synchronized
            // to make sure C and E both reference the same instance of the callsite.

            // This is to make sure we can safely store singleton values on the callsites themselves

            var callsiteLock = _callSiteLocks.GetOrAdd(serviceIdentifier, static _ => new object());

            lock (callsiteLock)
            {
                callSiteChain.CheckCircularDependency(serviceIdentifier);

                ServiceCallSite? callSite = TryCreateExact(serviceIdentifier, callSiteChain) ??
                                           TryCreateOpenGeneric(serviceIdentifier, callSiteChain) ??
                                           TryCreateEnumerable(serviceIdentifier, callSiteChain);

                return callSite;
            }
        }

        private ServiceCallSite? TryCreateExact(ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain)
        {
            if (_descriptorLookup.TryGetValue(serviceIdentifier, out ServiceDescriptorCacheItem descriptor))
            {
                return TryCreateExact(descriptor.Last, serviceIdentifier, callSiteChain, DefaultSlot);
            }

            if (serviceIdentifier.ServiceKey != null)
            {
                // Check if there is a registration with KeyedService.AnyKey
                var catchAllIdentifier = new ServiceIdentifier(KeyedService.AnyKey, serviceIdentifier.ServiceType);
                if (_descriptorLookup.TryGetValue(catchAllIdentifier, out descriptor))
                {
                    return TryCreateExact(descriptor.Last, serviceIdentifier, callSiteChain, DefaultSlot);
                }
            }

            return null;
        }

        private ServiceCallSite? TryCreateOpenGeneric(ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain)
        {
            if (serviceIdentifier.IsConstructedGenericType)
            {
                var genericIdentifier = serviceIdentifier.GetGenericTypeDefinition();
                if (_descriptorLookup.TryGetValue(genericIdentifier, out ServiceDescriptorCacheItem descriptor))
                {
                    return TryCreateOpenGeneric(descriptor.Last, serviceIdentifier, callSiteChain, DefaultSlot, true);
                }

                if (serviceIdentifier.ServiceKey != null)
                {
                    // Check if there is a registration with KeyedService.AnyKey
                    var catchAllIdentifier = new ServiceIdentifier(KeyedService.AnyKey, genericIdentifier.ServiceType);
                    if (_descriptorLookup.TryGetValue(catchAllIdentifier, out descriptor))
                    {
                        return TryCreateOpenGeneric(descriptor.Last, serviceIdentifier, callSiteChain, DefaultSlot, true);
                    }
                }
            }

            return null;
        }

        private ServiceCallSite? TryCreateEnumerable(ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain)
        {
            ServiceCacheKey callSiteKey = new ServiceCacheKey(serviceIdentifier, DefaultSlot);
            if (_callSiteCache.TryGetValue(callSiteKey, out ServiceCallSite? serviceCallSite))
            {
                return serviceCallSite;
            }

            try
            {
                callSiteChain.Add(serviceIdentifier);

                var serviceType = serviceIdentifier.ServiceType;

                if (!serviceType.IsConstructedGenericType ||
                    serviceType.GetGenericTypeDefinition() != typeof(IEnumerable<>))
                {
                    return null;
                }

                Type itemType = serviceType.GenericTypeArguments[0];
                var cacheKey = new ServiceIdentifier(serviceIdentifier.ServiceKey, itemType);
                if (ServiceProvider.VerifyAotCompatibility && itemType.IsValueType)
                {
                    // NativeAOT apps are not able to make Enumerable of ValueType services
                    // since there is no guarantee the ValueType[] code has been generated.
                    throw new InvalidOperationException(SR.Format(SR.AotCannotCreateEnumerableValueType, itemType));
                }

                CallSiteResultCacheLocation cacheLocation = CallSiteResultCacheLocation.Root;
                ServiceCallSite[] callSites;

                // If item type is not generic we can safely use descriptor cache
                if (!itemType.IsConstructedGenericType &&
                    _descriptorLookup.TryGetValue(cacheKey, out ServiceDescriptorCacheItem descriptors))
                {
                    callSites = new ServiceCallSite[descriptors.Count];
                    for (int i = 0; i < descriptors.Count; i++)
                    {
                        ServiceDescriptor descriptor = descriptors[i];

                        // Last service should get slot 0
                        int slot = descriptors.Count - i - 1;
                        // There may not be any open generics here
                        ServiceCallSite? callSite = TryCreateExact(descriptor, cacheKey, callSiteChain, slot);
                        Debug.Assert(callSite != null);

                        cacheLocation = GetCommonCacheLocation(cacheLocation, callSite.Cache.Location);
                        callSites[i] = callSite;
                    }
                }
                else
                {
                    // We need to construct a list of matching call sites in declaration order, but to ensure
                    // correct caching we must assign slots in reverse declaration order and with slots being
                    // given out first to any exact matches before any open generic matches. Therefore, we
                    // iterate over the descriptors twice in reverse, catching exact matches on the first pass
                    // and open generic matches on the second pass.

                    List<KeyValuePair<int, ServiceCallSite>> callSitesByIndex = new();

                    int slot = 0;
                    for (int i = _descriptors.Length - 1; i >= 0; i--)
                    {
                        if (KeysMatch(_descriptors[i].ServiceKey, cacheKey.ServiceKey))
                        {
                            if (TryCreateExact(_descriptors[i], cacheKey, callSiteChain, slot) is { } callSite)
                            {
                                AddCallSite(callSite, i);
                            }
                        }
                    }
                    for (int i = _descriptors.Length - 1; i >= 0; i--)
                    {
                        if (KeysMatch(_descriptors[i].ServiceKey, cacheKey.ServiceKey))
                        {
                            if (TryCreateOpenGeneric(_descriptors[i], cacheKey, callSiteChain, slot, throwOnConstraintViolation: false) is { } callSite)
                            {
                                AddCallSite(callSite, i);
                            }
                        }
                    }

                    callSitesByIndex.Sort((a, b) => a.Key.CompareTo(b.Key));
                    callSites = new ServiceCallSite[callSitesByIndex.Count];
                    for (var i = 0; i < callSites.Length; ++i)
                    {
                        callSites[i] = callSitesByIndex[i].Value;
                    }

                    void AddCallSite(ServiceCallSite callSite, int index)
                    {
                        slot++;

                        cacheLocation = GetCommonCacheLocation(cacheLocation, callSite.Cache.Location);
                        callSitesByIndex.Add(new(index, callSite));
                    }
                }
                ResultCache resultCache = (cacheLocation == CallSiteResultCacheLocation.Scope || cacheLocation == CallSiteResultCacheLocation.Root)
                    ? new ResultCache(cacheLocation, callSiteKey)
                    : new ResultCache(CallSiteResultCacheLocation.None, callSiteKey);
                return _callSiteCache[callSiteKey] = new IEnumerableCallSite(resultCache, itemType, callSites);
            }
            finally
            {
                callSiteChain.Remove(serviceIdentifier);
            }
        }

        private static CallSiteResultCacheLocation GetCommonCacheLocation(CallSiteResultCacheLocation locationA, CallSiteResultCacheLocation locationB)
        {
            return (CallSiteResultCacheLocation)Math.Max((int)locationA, (int)locationB);
        }

        private ServiceCallSite? TryCreateExact(ServiceDescriptor descriptor, ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain, int slot)
        {
            if (serviceIdentifier.ServiceType == descriptor.ServiceType)
            {
                ServiceCacheKey callSiteKey = new ServiceCacheKey(serviceIdentifier, slot);
                if (_callSiteCache.TryGetValue(callSiteKey, out ServiceCallSite? serviceCallSite))
                {
                    return serviceCallSite;
                }

                ServiceCallSite callSite;
                var lifetime = new ResultCache(descriptor.Lifetime, serviceIdentifier, slot);
                if (descriptor.HasImplementationInstance())
                {
                    callSite = new ConstantCallSite(descriptor.ServiceType, descriptor.GetImplementationInstance());
                }
                else if (!descriptor.IsKeyedService && descriptor.ImplementationFactory != null)
                {
                    callSite = new FactoryCallSite(lifetime, descriptor.ServiceType, descriptor.ImplementationFactory);
                }
                else if (descriptor.IsKeyedService && descriptor.KeyedImplementationFactory != null)
                {
                    callSite = new FactoryCallSite(lifetime, descriptor.ServiceType, serviceIdentifier.ServiceKey!, descriptor.KeyedImplementationFactory);
                }
                else if (descriptor.HasImplementationType())
                {
                    callSite = CreateConstructorCallSite(lifetime, serviceIdentifier, descriptor.GetImplementationType()!, callSiteChain);
                }
                else
                {
                    throw new InvalidOperationException(SR.InvalidServiceDescriptor);
                }
                callSite.Key = descriptor.ServiceKey;

                return _callSiteCache[callSiteKey] = callSite;
            }

            return null;
        }

        [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2055:MakeGenericType",
            Justification = "MakeGenericType here is used to create a closed generic implementation type given the closed service type. " +
            "Trimming annotations on the generic types are verified when 'Microsoft.Extensions.DependencyInjection.VerifyOpenGenericServiceTrimmability' is set, which is set by default when PublishTrimmed=true. " +
            "That check informs developers when these generic types don't have compatible trimming annotations.")]
        [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
            Justification = "When ServiceProvider.VerifyAotCompatibility is true, which it is by default when PublishAot=true, " +
            "this method ensures the generic types being created aren't using ValueTypes.")]
        private ServiceCallSite? TryCreateOpenGeneric(ServiceDescriptor descriptor, ServiceIdentifier serviceIdentifier, CallSiteChain callSiteChain, int slot, bool throwOnConstraintViolation)
        {
            if (serviceIdentifier.IsConstructedGenericType &&
                serviceIdentifier.ServiceType.GetGenericTypeDefinition() == descriptor.ServiceType)
            {
                ServiceCacheKey callSiteKey = new ServiceCacheKey(serviceIdentifier, slot);
                if (_callSiteCache.TryGetValue(callSiteKey, out ServiceCallSite? serviceCallSite))
                {
                    return serviceCallSite;
                }

                Type? implementationType = descriptor.GetImplementationType();
                Debug.Assert(implementationType != null, "descriptor.ImplementationType != null");
                var lifetime = new ResultCache(descriptor.Lifetime, serviceIdentifier, slot);
                Type closedType;
                try
                {
                    Type[] genericTypeArguments = serviceIdentifier.ServiceType.GenericTypeArguments;
                    if (ServiceProvider.VerifyAotCompatibility)
                    {
                        VerifyOpenGenericAotCompatibility(serviceIdentifier.ServiceType, genericTypeArguments);
                    }

                    closedType = implementationType.MakeGenericType(genericTypeArguments);
                }
                catch (ArgumentException)
                {
                    if (throwOnConstraintViolation)
                    {
                        throw;
                    }

                    return null;
                }

                return _callSiteCache[callSiteKey] = CreateConstructorCallSite(lifetime, serviceIdentifier, closedType, callSiteChain);
            }

            return null;
        }

        private ConstructorCallSite CreateConstructorCallSite(
            ResultCache lifetime,
            ServiceIdentifier serviceIdentifier,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            CallSiteChain callSiteChain)
        {
            try
            {
                callSiteChain.Add(serviceIdentifier, implementationType);
                ConstructorInfo[] constructors = implementationType.GetConstructors();

                ServiceCallSite[]? parameterCallSites = null;

                if (constructors.Length == 0)
                {
                    throw new InvalidOperationException(SR.Format(SR.NoConstructorMatch, implementationType));
                }
                else if (constructors.Length == 1)
                {
                    ConstructorInfo constructor = constructors[0];
                    ParameterInfo[] parameters = constructor.GetParameters();
                    if (parameters.Length == 0)
                    {
                        return new ConstructorCallSite(lifetime, serviceIdentifier.ServiceType, constructor);
                    }

                    parameterCallSites = CreateArgumentCallSites(
                        serviceIdentifier,
                        implementationType,
                        callSiteChain,
                        parameters,
                        throwIfCallSiteNotFound: true)!;

                    return new ConstructorCallSite(lifetime, serviceIdentifier.ServiceType, constructor, parameterCallSites);
                }

                Array.Sort(constructors,
                    (a, b) => b.GetParameters().Length.CompareTo(a.GetParameters().Length));

                ConstructorInfo? bestConstructor = null;
                HashSet<Type>? bestConstructorParameterTypes = null;
                for (int i = 0; i < constructors.Length; i++)
                {
                    ParameterInfo[] parameters = constructors[i].GetParameters();

                    ServiceCallSite[]? currentParameterCallSites = CreateArgumentCallSites(
                        serviceIdentifier,
                        implementationType,
                        callSiteChain,
                        parameters,
                        throwIfCallSiteNotFound: false);

                    if (currentParameterCallSites != null)
                    {
                        if (bestConstructor == null)
                        {
                            bestConstructor = constructors[i];
                            parameterCallSites = currentParameterCallSites;
                        }
                        else
                        {
                            // Since we're visiting constructors in decreasing order of number of parameters,
                            // we'll only see ambiguities or supersets once we've seen a 'bestConstructor'.

                            if (bestConstructorParameterTypes == null)
                            {
                                bestConstructorParameterTypes = new HashSet<Type>();
                                foreach (ParameterInfo p in bestConstructor.GetParameters())
                                {
                                    bestConstructorParameterTypes.Add(p.ParameterType);
                                }
                            }

                            foreach (ParameterInfo p in parameters)
                            {
                                if (!bestConstructorParameterTypes.Contains(p.ParameterType))
                                {
                                    // Ambiguous match exception
                                    throw new InvalidOperationException(string.Join(
                                        Environment.NewLine,
                                        SR.Format(SR.AmbiguousConstructorException, implementationType),
                                        bestConstructor,
                                        constructors[i]));
                                }
                            }
                        }
                    }
                }

                if (bestConstructor == null)
                {
                    throw new InvalidOperationException(
                        SR.Format(SR.UnableToActivateTypeException, implementationType));
                }
                else
                {
                    Debug.Assert(parameterCallSites != null);
                    return new ConstructorCallSite(lifetime, serviceIdentifier.ServiceType, bestConstructor, parameterCallSites);
                }
            }
            finally
            {
                callSiteChain.Remove(serviceIdentifier);
            }
        }

        /// <returns>Not <b>null</b> if <b>throwIfCallSiteNotFound</b> is true</returns>
        private ServiceCallSite[]? CreateArgumentCallSites(
            ServiceIdentifier serviceIdentifier,
            Type implementationType,
            CallSiteChain callSiteChain,
            ParameterInfo[] parameters,
            bool throwIfCallSiteNotFound)
        {
            var parameterCallSites = new ServiceCallSite[parameters.Length];

            for (int index = 0; index < parameters.Length; index++)
            {
                ServiceCallSite? callSite = null;
                Type parameterType = parameters[index].ParameterType;
                foreach (var attribute in parameters[index].GetCustomAttributes(true))
                {
                    if (serviceIdentifier.ServiceKey != null && attribute is ServiceKeyAttribute)
                    {
                        // Check if the parameter type matches
                        if (parameterType != serviceIdentifier.ServiceKey.GetType())
                        {
                            throw new InvalidOperationException(SR.InvalidServiceKeyType);
                        }
                        callSite = new ConstantCallSite(parameterType, serviceIdentifier.ServiceKey);
                        break;
                    }
                    if (attribute is FromKeyedServicesAttribute keyed)
                    {
                        var parameterSvcId = new ServiceIdentifier(keyed.Key, parameterType);
                        callSite = GetCallSite(parameterSvcId, callSiteChain);
                        break;
                    }
                }

                callSite ??= GetCallSite(ServiceIdentifier.FromServiceType(parameterType), callSiteChain);

                if (callSite == null && ParameterDefaultValue.TryGetDefaultValue(parameters[index], out object? defaultValue))
                {
                    callSite = new ConstantCallSite(parameterType, defaultValue);
                }

                if (callSite == null)
                {
                    if (throwIfCallSiteNotFound)
                    {
                        throw new InvalidOperationException(SR.Format(SR.CannotResolveService,
                            parameterType,
                            implementationType));
                    }

                    return null;
                }

                parameterCallSites[index] = callSite;
            }

            return parameterCallSites;
        }

        /// <summary>
        /// Verifies none of the generic type arguments are ValueTypes.
        /// </summary>
        /// <remarks>
        /// NativeAOT apps are not guaranteed that the native code for the closed generic of ValueType
        /// has been generated. To catch these problems early, this verification is enabled at development-time
        /// to inform the developer early that this scenario will not work once AOT'd.
        /// </remarks>
        private static void VerifyOpenGenericAotCompatibility(Type serviceType, Type[] genericTypeArguments)
        {
            foreach (Type typeArg in genericTypeArguments)
            {
                if (typeArg.IsValueType)
                {
                    throw new InvalidOperationException(SR.Format(SR.AotCannotCreateGenericValueType, serviceType, typeArg));
                }
            }
        }

        public void Add(ServiceIdentifier serviceIdentifier, ServiceCallSite serviceCallSite)
        {
            _callSiteCache[new ServiceCacheKey(serviceIdentifier, DefaultSlot)] = serviceCallSite;
        }

        public bool IsService(Type serviceType) => IsService(new ServiceIdentifier(null, serviceType));

        public bool IsKeyedService(Type serviceType, object? key) => IsService(new ServiceIdentifier(key, serviceType));

        internal bool IsService(ServiceIdentifier serviceIdentifier)
        {
            var serviceType = serviceIdentifier.ServiceType;

            if (serviceType is null)
            {
                throw new ArgumentNullException(nameof(serviceType));
            }

            // Querying for an open generic should return false (they aren't resolvable)
            if (serviceType.IsGenericTypeDefinition)
            {
                return false;
            }

            if (_descriptorLookup.ContainsKey(serviceIdentifier))
            {
                return true;
            }

            if (serviceIdentifier.ServiceKey != null && _descriptorLookup.ContainsKey(new ServiceIdentifier(KeyedService.AnyKey, serviceType)))
            {
                return true;
            }

            if (serviceType.IsConstructedGenericType && serviceType.GetGenericTypeDefinition() is Type genericDefinition)
            {
                // We special case IEnumerable since it isn't explicitly registered in the container
                // yet we can manifest instances of it when requested.
                return genericDefinition == typeof(IEnumerable<>) || _descriptorLookup.ContainsKey(serviceIdentifier.GetGenericTypeDefinition());
            }

            // These are the built in service types that aren't part of the list of service descriptors
            // If you update these make sure to also update the code in ServiceProvider.ctor
            return serviceType == typeof(IServiceProvider) ||
                   serviceType == typeof(IServiceScopeFactory) ||
                   serviceType == typeof(IServiceProviderIsService) ||
                   serviceType == typeof(IServiceProviderIsKeyedService);
        }

        /// <summary>
        /// Returns true if both keys are null or equals, or if key1 is KeyedService.AnyKey and key2 is not null
        /// </summary>
        private static bool KeysMatch(object? key1, object? key2)
        {
            if (key1 == null && key2 == null)
                return true;

            if (key1 != null && key2 != null)
                return key1.Equals(KeyedService.AnyKey) || key1.Equals(key2);

            return false;
        }

        private struct ServiceDescriptorCacheItem
        {
            [DisallowNull]
            private ServiceDescriptor? _item;

            [DisallowNull]
            private List<ServiceDescriptor>? _items;

            public ServiceDescriptor Last
            {
                get
                {
                    if (_items != null && _items.Count > 0)
                    {
                        return _items[_items.Count - 1];
                    }

                    Debug.Assert(_item != null);
                    return _item;
                }
            }

            public int Count
            {
                get
                {
                    if (_item == null)
                    {
                        Debug.Assert(_items == null);
                        return 0;
                    }

                    return 1 + (_items?.Count ?? 0);
                }
            }

            public ServiceDescriptor this[int index]
            {
                get
                {
                    if (index >= Count)
                    {
                        throw new ArgumentOutOfRangeException(nameof(index));
                    }

                    if (index == 0)
                    {
                        return _item!;
                    }

                    return _items![index - 1];
                }
            }

            public int GetSlot(ServiceDescriptor descriptor)
            {
                if (descriptor == _item)
                {
                    return Count - 1;
                }

                if (_items != null)
                {
                    int index = _items.IndexOf(descriptor);
                    if (index != -1)
                    {
                        return _items.Count - (index + 1);
                    }
                }

                throw new InvalidOperationException(SR.ServiceDescriptorNotExist);
            }

            public ServiceDescriptorCacheItem Add(ServiceDescriptor descriptor)
            {
                var newCacheItem = default(ServiceDescriptorCacheItem);
                if (_item == null)
                {
                    Debug.Assert(_items == null);
                    newCacheItem._item = descriptor;
                }
                else
                {
                    newCacheItem._item = _item;
                    newCacheItem._items = _items ?? new List<ServiceDescriptor>();
                    newCacheItem._items.Add(descriptor);
                }
                return newCacheItem;
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteKind.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal enum CallSiteKind
    {
        Factory,

        Constructor,

        Constant,

        IEnumerable,

        ServiceProvider,
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteResultCacheLocation.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal enum CallSiteResultCacheLocation
    {
        Root,
        Scope,
        Dispose,
        None
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteRuntimeResolver.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class CallSiteRuntimeResolver : CallSiteVisitor<RuntimeResolverContext, object?>
    {
        public static CallSiteRuntimeResolver Instance { get; } = new();

        private CallSiteRuntimeResolver()
        {
        }

        public object? Resolve(ServiceCallSite callSite, ServiceProviderEngineScope scope)
        {
            // Fast path to avoid virtual calls if we already have the cached value in the root scope
            if (scope.IsRootScope && callSite.Value is object cached)
            {
                return cached;
            }

            return VisitCallSite(callSite, new RuntimeResolverContext
            {
                Scope = scope
            });
        }

        protected override object? VisitDisposeCache(ServiceCallSite transientCallSite, RuntimeResolverContext context)
        {
            return context.Scope.CaptureDisposable(VisitCallSiteMain(transientCallSite, context));
        }

        protected override object VisitConstructor(ConstructorCallSite constructorCallSite, RuntimeResolverContext context)
        {
            object?[] parameterValues;
            if (constructorCallSite.ParameterCallSites.Length == 0)
            {
                parameterValues = Array.Empty<object>();
            }
            else
            {
                parameterValues = new object?[constructorCallSite.ParameterCallSites.Length];
                for (int index = 0; index < parameterValues.Length; index++)
                {
                    parameterValues[index] = VisitCallSite(constructorCallSite.ParameterCallSites[index], context);
                }
            }

#if NETFRAMEWORK || NETSTANDARD2_0
            try
            {
                return constructorCallSite.ConstructorInfo.Invoke(parameterValues);
            }
            catch (Exception ex) when (ex.InnerException != null)
            {
                ExceptionDispatchInfo.Capture(ex.InnerException).Throw();
                // The above line will always throw, but the compiler requires we throw explicitly.
                throw;
            }
#else
            return constructorCallSite.ConstructorInfo.Invoke(BindingFlags.DoNotWrapExceptions, binder: null, parameters: parameterValues, culture: null);
#endif
        }

        protected override object? VisitRootCache(ServiceCallSite callSite, RuntimeResolverContext context)
        {
            if (callSite.Value is object value)
            {
                // Value already calculated, return it directly
                return value;
            }

            var lockType = RuntimeResolverLock.Root;
            ServiceProviderEngineScope serviceProviderEngine = context.Scope.RootProvider.Root;

            lock (callSite)
            {
                // Lock the callsite and check if another thread already cached the value
                if (callSite.Value is object callSiteValue)
                {
                    return callSiteValue;
                }

                object? resolved = VisitCallSiteMain(callSite, new RuntimeResolverContext
                {
                    Scope = serviceProviderEngine,
                    AcquiredLocks = context.AcquiredLocks | lockType
                });
                serviceProviderEngine.CaptureDisposable(resolved);
                callSite.Value = resolved;
                return resolved;
            }
        }

        protected override object? VisitScopeCache(ServiceCallSite callSite, RuntimeResolverContext context)
        {
            // Check if we are in the situation where scoped service was promoted to singleton
            // and we need to lock the root
            return context.Scope.IsRootScope ?
                VisitRootCache(callSite, context) :
                VisitCache(callSite, context, context.Scope, RuntimeResolverLock.Scope);
        }

        private object? VisitCache(ServiceCallSite callSite, RuntimeResolverContext context, ServiceProviderEngineScope serviceProviderEngine, RuntimeResolverLock lockType)
        {
            bool lockTaken = false;
            object sync = serviceProviderEngine.Sync;
            Dictionary<ServiceCacheKey, object?> resolvedServices = serviceProviderEngine.ResolvedServices;
            // Taking locks only once allows us to fork resolution process
            // on another thread without causing the deadlock because we
            // always know that we are going to wait the other thread to finish before
            // releasing the lock
            if ((context.AcquiredLocks & lockType) == 0)
            {
                Monitor.Enter(sync, ref lockTaken);
            }

            try
            {
                // Note: This method has already taken lock by the caller for resolution and access synchronization.
                // For scoped: takes a dictionary as both a resolution lock and a dictionary access lock.
                if (resolvedServices.TryGetValue(callSite.Cache.Key, out object? resolved))
                {
                    return resolved;
                }

                resolved = VisitCallSiteMain(callSite, new RuntimeResolverContext
                {
                    Scope = serviceProviderEngine,
                    AcquiredLocks = context.AcquiredLocks | lockType
                });
                serviceProviderEngine.CaptureDisposable(resolved);
                resolvedServices.Add(callSite.Cache.Key, resolved);
                return resolved;
            }
            finally
            {
                if (lockTaken)
                {
                    Monitor.Exit(sync);
                }
            }
        }

        protected override object? VisitConstant(ConstantCallSite constantCallSite, RuntimeResolverContext context)
        {
            return constantCallSite.DefaultValue;
        }

        protected override object VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, RuntimeResolverContext context)
        {
            return context.Scope;
        }

        protected override object VisitIEnumerable(IEnumerableCallSite enumerableCallSite, RuntimeResolverContext context)
        {
            Array array = CreateArray(
                enumerableCallSite.ItemType,
                enumerableCallSite.ServiceCallSites.Length);

            for (int index = 0; index < enumerableCallSite.ServiceCallSites.Length; index++)
            {
                object? value = VisitCallSite(enumerableCallSite.ServiceCallSites[index], context);
                array.SetValue(value, index);
            }
            return array;

            [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
                Justification = "VerifyAotCompatibility ensures elementType is not a ValueType")]
            static Array CreateArray(Type elementType, int length)
            {
                Debug.Assert(!ServiceProvider.VerifyAotCompatibility || !elementType.IsValueType, "VerifyAotCompatibility=true will throw during building the IEnumerableCallSite if elementType is a ValueType.");

                return Array.CreateInstance(elementType, length);
            }
        }

        protected override object VisitFactory(FactoryCallSite factoryCallSite, RuntimeResolverContext context)
        {
            return factoryCallSite.Factory(context.Scope);
        }
    }

    internal struct RuntimeResolverContext
    {
        public ServiceProviderEngineScope Scope { get; set; }

        public RuntimeResolverLock AcquiredLocks { get; set; }
    }

    [Flags]
    internal enum RuntimeResolverLock
    {
        Scope = 1,
        Root = 2
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteValidator.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class CallSiteValidator : CallSiteVisitor<CallSiteValidator.CallSiteValidatorState, Type?>
    {
        // Keys are services being resolved via GetService, values - first scoped service in their call site tree
        private readonly ConcurrentDictionary<ServiceCacheKey, Type> _scopedServices = new ConcurrentDictionary<ServiceCacheKey, Type>();

        public void ValidateCallSite(ServiceCallSite callSite)
        {
            Type? scoped = VisitCallSite(callSite, default);
            if (scoped != null)
            {
                _scopedServices[callSite.Cache.Key] = scoped;
            }
        }

        public void ValidateResolution(ServiceCallSite callSite, IServiceScope scope, IServiceScope rootScope)
        {
            if (ReferenceEquals(scope, rootScope)
                && _scopedServices.TryGetValue(callSite.Cache.Key, out Type? scopedService))
            {
                Type serviceType = callSite.ServiceType;
                if (serviceType == scopedService)
                {
                    throw new InvalidOperationException(
                        SR.Format(SR.DirectScopedResolvedFromRootException, callSite.ServiceType,
                            nameof(ServiceLifetime.Scoped).ToLowerInvariant()));
                }

                throw new InvalidOperationException(
                    SR.Format(SR.ScopedResolvedFromRootException,
                        callSite.ServiceType,
                        scopedService,
                        nameof(ServiceLifetime.Scoped).ToLowerInvariant()));
            }
        }

        protected override Type? VisitConstructor(ConstructorCallSite constructorCallSite, CallSiteValidatorState state)
        {
            Type? result = null;
            foreach (ServiceCallSite parameterCallSite in constructorCallSite.ParameterCallSites)
            {
                Type? scoped =  VisitCallSite(parameterCallSite, state);
                result ??= scoped;
            }
            return result;
        }

        protected override Type? VisitIEnumerable(IEnumerableCallSite enumerableCallSite,
            CallSiteValidatorState state)
        {
            Type? result = null;
            foreach (ServiceCallSite serviceCallSite in enumerableCallSite.ServiceCallSites)
            {
                Type? scoped = VisitCallSite(serviceCallSite, state);
                result ??= scoped;
            }
            return result;
        }

        protected override Type? VisitRootCache(ServiceCallSite singletonCallSite, CallSiteValidatorState state)
        {
            state.Singleton = singletonCallSite;
            return VisitCallSiteMain(singletonCallSite, state);
        }

        protected override Type? VisitScopeCache(ServiceCallSite scopedCallSite, CallSiteValidatorState state)
        {
            // We are fine with having ServiceScopeService requested by singletons
            if (scopedCallSite.ServiceType == typeof(IServiceScopeFactory))
            {
                return null;
            }
            if (state.Singleton != null)
            {
                throw new InvalidOperationException(SR.Format(SR.ScopedInSingletonException,
                    scopedCallSite.ServiceType,
                    state.Singleton.ServiceType,
                    nameof(ServiceLifetime.Scoped).ToLowerInvariant(),
                    nameof(ServiceLifetime.Singleton).ToLowerInvariant()
                    ));
            }

            VisitCallSiteMain(scopedCallSite, state);
            return scopedCallSite.ServiceType;
        }

        protected override Type? VisitConstant(ConstantCallSite constantCallSite, CallSiteValidatorState state) => null;

        protected override Type? VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, CallSiteValidatorState state) => null;

        protected override Type? VisitFactory(FactoryCallSite factoryCallSite, CallSiteValidatorState state) => null;

        internal struct CallSiteValidatorState
        {
            [DisallowNull]
            public ServiceCallSite? Singleton { get; set; }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CallSiteVisitor.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal abstract class CallSiteVisitor<TArgument, TResult>
    {
        private readonly StackGuard _stackGuard;

        protected CallSiteVisitor()
        {
            _stackGuard = new StackGuard();
        }

        protected virtual TResult VisitCallSite(ServiceCallSite callSite, TArgument argument)
        {
            if (!_stackGuard.TryEnterOnCurrentStack())
            {
                return _stackGuard.RunOnEmptyStack(VisitCallSite, callSite, argument);
            }

            switch (callSite.Cache.Location)
            {
                case CallSiteResultCacheLocation.Root:
                    return VisitRootCache(callSite, argument);
                case CallSiteResultCacheLocation.Scope:
                    return VisitScopeCache(callSite, argument);
                case CallSiteResultCacheLocation.Dispose:
                    return VisitDisposeCache(callSite, argument);
                case CallSiteResultCacheLocation.None:
                    return VisitNoCache(callSite, argument);
                default:
                    throw new ArgumentOutOfRangeException();
            }
        }

        protected virtual TResult VisitCallSiteMain(ServiceCallSite callSite, TArgument argument)
        {
            switch (callSite.Kind)
            {
                case CallSiteKind.Factory:
                    return VisitFactory((FactoryCallSite)callSite, argument);
                case  CallSiteKind.IEnumerable:
                    return VisitIEnumerable((IEnumerableCallSite)callSite, argument);
                case CallSiteKind.Constructor:
                    return VisitConstructor((ConstructorCallSite)callSite, argument);
                case CallSiteKind.Constant:
                    return VisitConstant((ConstantCallSite)callSite, argument);
                case CallSiteKind.ServiceProvider:
                    return VisitServiceProvider((ServiceProviderCallSite)callSite, argument);
                default:
                    throw new NotSupportedException(SR.Format(SR.CallSiteTypeNotSupported, callSite.GetType()));
            }
        }

        protected virtual TResult VisitNoCache(ServiceCallSite callSite, TArgument argument)
        {
            return VisitCallSiteMain(callSite, argument);
        }

        protected virtual TResult VisitDisposeCache(ServiceCallSite callSite, TArgument argument)
        {
            return VisitCallSiteMain(callSite, argument);
        }

        protected virtual TResult VisitRootCache(ServiceCallSite callSite, TArgument argument)
        {
            return VisitCallSiteMain(callSite, argument);
        }

        protected virtual TResult VisitScopeCache(ServiceCallSite callSite, TArgument argument)
        {
            return VisitCallSiteMain(callSite, argument);
        }

        protected abstract TResult VisitConstructor(ConstructorCallSite constructorCallSite, TArgument argument);

        protected abstract TResult VisitConstant(ConstantCallSite constantCallSite, TArgument argument);

        protected abstract TResult VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, TArgument argument);

        protected abstract TResult VisitIEnumerable(IEnumerableCallSite enumerableCallSite, TArgument argument);

        protected abstract TResult VisitFactory(FactoryCallSite factoryCallSite, TArgument argument);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/CompiledServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal abstract class CompiledServiceProviderEngine : ServiceProviderEngine
    {
#if IL_EMIT
        public ILEmitResolverBuilder ResolverBuilder { get; }
#else
        public ExpressionResolverBuilder ResolverBuilder { get; }
#endif

        [RequiresDynamicCode("Creates DynamicMethods")]
        public CompiledServiceProviderEngine(ServiceProvider provider)
        {
            ResolverBuilder = new(provider);
        }

        public override Func<ServiceProviderEngineScope, object?> RealizeService(ServiceCallSite callSite) => ResolverBuilder.Build(callSite);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ConstantCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ConstantCallSite : ServiceCallSite
    {
        private readonly Type _serviceType;
        internal object? DefaultValue => Value;

        public ConstantCallSite(Type serviceType, object? defaultValue) : base(ResultCache.None(serviceType))
        {
            _serviceType = serviceType ?? throw new ArgumentNullException(nameof(serviceType));
            if (defaultValue != null && !serviceType.IsInstanceOfType(defaultValue))
            {
                throw new ArgumentException(SR.Format(SR.ConstantCantBeConvertedToServiceType, defaultValue.GetType(), serviceType));
            }

            Value = defaultValue;
        }

        public override Type ServiceType => _serviceType;
        public override Type ImplementationType => DefaultValue?.GetType() ?? _serviceType;
        public override CallSiteKind Kind { get; } = CallSiteKind.Constant;
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ConstructorCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ConstructorCallSite : ServiceCallSite
    {
        internal ConstructorInfo ConstructorInfo { get; }
        internal ServiceCallSite[] ParameterCallSites { get; }

        public ConstructorCallSite(ResultCache cache, Type serviceType, ConstructorInfo constructorInfo) : this(cache, serviceType, constructorInfo, Array.Empty<ServiceCallSite>())
        {
        }

        public ConstructorCallSite(ResultCache cache, Type serviceType, ConstructorInfo constructorInfo, ServiceCallSite[] parameterCallSites) : base(cache)
        {
            if (!serviceType.IsAssignableFrom(constructorInfo.DeclaringType))
            {
                throw new ArgumentException(SR.Format(SR.ImplementationTypeCantBeConvertedToServiceType, constructorInfo.DeclaringType, serviceType));
            }

            ServiceType = serviceType;
            ConstructorInfo = constructorInfo;
            ParameterCallSites = parameterCallSites;
        }

        public override Type ServiceType { get; }

        public override Type? ImplementationType => ConstructorInfo.DeclaringType;
        public override CallSiteKind Kind { get; } = CallSiteKind.Constructor;
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/DynamicServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class DynamicServiceProviderEngine : CompiledServiceProviderEngine
    {
        private readonly ServiceProvider _serviceProvider;

        [RequiresDynamicCode("Creates DynamicMethods")]
        public DynamicServiceProviderEngine(ServiceProvider serviceProvider) : base(serviceProvider)
        {
            _serviceProvider = serviceProvider;
        }

        public override Func<ServiceProviderEngineScope, object?> RealizeService(ServiceCallSite callSite)
        {
            int callCount = 0;
            return scope =>
            {
                // Resolve the result before we increment the call count, this ensures that singletons
                // won't cause any side effects during the compilation of the resolve function.
                var result = CallSiteRuntimeResolver.Instance.Resolve(callSite, scope);

                if (Interlocked.Increment(ref callCount) == 2)
                {
                    // Don't capture the ExecutionContext when forking to build the compiled version of the
                    // resolve function
                    _ = ThreadPool.UnsafeQueueUserWorkItem(_ =>
                    {
                        try
                        {
                            _serviceProvider.ReplaceServiceAccessor(callSite, base.RealizeService(callSite));
                        }
                        catch (Exception ex)
                        {
                            DependencyInjectionEventSource.Log.ServiceRealizationFailed(ex, _serviceProvider.GetHashCode());

                            Debug.Fail($"We should never get exceptions from the background compilation.{Environment.NewLine}{ex}");
                        }
                    },
                    null);
                }

                return result;
            };
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/Expressions/ExpressionResolverBuilder.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ExpressionResolverBuilder : CallSiteVisitor<object?, Expression>
    {
        private static readonly ParameterExpression ScopeParameter = Expression.Parameter(typeof(ServiceProviderEngineScope));

        private static readonly ParameterExpression ResolvedServices = Expression.Variable(typeof(IDictionary<ServiceCacheKey, object>), ScopeParameter.Name + "resolvedServices");
        private static readonly ParameterExpression Sync = Expression.Variable(typeof(object), ScopeParameter.Name + "sync");
        private static readonly BinaryExpression ResolvedServicesVariableAssignment =
            Expression.Assign(ResolvedServices,
                Expression.Property(
                    ScopeParameter,
                    typeof(ServiceProviderEngineScope).GetProperty(nameof(ServiceProviderEngineScope.ResolvedServices), BindingFlags.Instance | BindingFlags.NonPublic)!));

        private static readonly BinaryExpression SyncVariableAssignment =
            Expression.Assign(Sync,
                Expression.Property(
                    ScopeParameter,
                    typeof(ServiceProviderEngineScope).GetProperty(nameof(ServiceProviderEngineScope.Sync), BindingFlags.Instance | BindingFlags.NonPublic)!));

        private static readonly ParameterExpression CaptureDisposableParameter = Expression.Parameter(typeof(object));
        private static readonly LambdaExpression CaptureDisposable = Expression.Lambda(
                    Expression.Call(ScopeParameter, ServiceLookupHelpers.CaptureDisposableMethodInfo, CaptureDisposableParameter),
                    CaptureDisposableParameter);

        private static readonly ConstantExpression CallSiteRuntimeResolverInstanceExpression = Expression.Constant(
            CallSiteRuntimeResolver.Instance,
            typeof(CallSiteRuntimeResolver));

        private readonly ServiceProviderEngineScope _rootScope;

        private readonly ConcurrentDictionary<ServiceCacheKey, Func<ServiceProviderEngineScope, object>> _scopeResolverCache;

        private readonly Func<ServiceCacheKey, ServiceCallSite, Func<ServiceProviderEngineScope, object>> _buildTypeDelegate;

        public ExpressionResolverBuilder(ServiceProvider serviceProvider)
        {
            _rootScope = serviceProvider.Root;
            _scopeResolverCache = new ConcurrentDictionary<ServiceCacheKey, Func<ServiceProviderEngineScope, object>>();
            _buildTypeDelegate = (key, cs) => BuildNoCache(cs);
        }

        public Func<ServiceProviderEngineScope, object> Build(ServiceCallSite callSite)
        {
            // Only scope methods are cached
            if (callSite.Cache.Location == CallSiteResultCacheLocation.Scope)
            {
#if NETFRAMEWORK || NETSTANDARD2_0
                return _scopeResolverCache.GetOrAdd(callSite.Cache.Key, key => _buildTypeDelegate(key, callSite));
#else
                return _scopeResolverCache.GetOrAdd(callSite.Cache.Key, _buildTypeDelegate, callSite);
#endif
            }

            return BuildNoCache(callSite);
        }

        public Func<ServiceProviderEngineScope, object> BuildNoCache(ServiceCallSite callSite)
        {
            Expression<Func<ServiceProviderEngineScope, object>> expression = BuildExpression(callSite);
            DependencyInjectionEventSource.Log.ExpressionTreeGenerated(_rootScope.RootProvider, callSite.ServiceType, expression);
            return expression.Compile();
        }

        private Expression<Func<ServiceProviderEngineScope, object>> BuildExpression(ServiceCallSite callSite)
        {
            if (callSite.Cache.Location == CallSiteResultCacheLocation.Scope)
            {
                return Expression.Lambda<Func<ServiceProviderEngineScope, object>>(
                    Expression.Block(
                        new[] { ResolvedServices, Sync },
                        ResolvedServicesVariableAssignment,
                        SyncVariableAssignment,
                        BuildScopedExpression(callSite)),
                    ScopeParameter);
            }

            return Expression.Lambda<Func<ServiceProviderEngineScope, object>>(
                Convert(VisitCallSite(callSite, null), typeof(object), forceValueTypeConversion: true),
                ScopeParameter);
        }

        protected override Expression VisitRootCache(ServiceCallSite singletonCallSite, object? context)
        {
            return Expression.Constant(CallSiteRuntimeResolver.Instance.Resolve(singletonCallSite, _rootScope));
        }

        protected override Expression VisitConstant(ConstantCallSite constantCallSite, object? context)
        {
            return Expression.Constant(constantCallSite.DefaultValue);
        }

        protected override Expression VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, object? context)
        {
            return ScopeParameter;
        }

        protected override Expression VisitFactory(FactoryCallSite factoryCallSite, object? context)
        {
            return Expression.Invoke(Expression.Constant(factoryCallSite.Factory), ScopeParameter);
        }

        protected override Expression VisitIEnumerable(IEnumerableCallSite callSite, object? context)
        {
            [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
                Justification = "VerifyAotCompatibility ensures elementType is not a ValueType")]
            static MethodInfo GetArrayEmptyMethodInfo(Type elementType)
            {
                Debug.Assert(!ServiceProvider.VerifyAotCompatibility || !elementType.IsValueType, "VerifyAotCompatibility=true will throw during building the IEnumerableCallSite if elementType is a ValueType.");

                return ServiceLookupHelpers.GetArrayEmptyMethodInfo(elementType);
            }

            [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
                Justification = "VerifyAotCompatibility ensures elementType is not a ValueType")]
            static NewArrayExpression NewArrayInit(Type elementType, IEnumerable<Expression> expr)
            {
                Debug.Assert(!ServiceProvider.VerifyAotCompatibility || !elementType.IsValueType, "VerifyAotCompatibility=true will throw during building the IEnumerableCallSite if elementType is a ValueType.");

                return Expression.NewArrayInit(elementType, expr);
            }

            if (callSite.ServiceCallSites.Length == 0)
            {
                return Expression.Constant(
                    GetArrayEmptyMethodInfo(callSite.ItemType)
                    .Invoke(obj: null, parameters: Array.Empty<object>()));
            }

            return NewArrayInit(
                callSite.ItemType,
                callSite.ServiceCallSites.Select(cs =>
                    Convert(
                        VisitCallSite(cs, context),
                        callSite.ItemType)));
        }

        protected override Expression VisitDisposeCache(ServiceCallSite callSite, object? context)
        {
            // Elide calls to GetCaptureDisposable if the implementation type isn't disposable
            return TryCaptureDisposable(
                callSite,
                ScopeParameter,
                VisitCallSiteMain(callSite, context));
        }

        private static Expression TryCaptureDisposable(ServiceCallSite callSite, ParameterExpression scope, Expression service)
        {
            if (!callSite.CaptureDisposable)
            {
                return service;
            }

            return Expression.Invoke(GetCaptureDisposable(scope), service);
        }

        protected override Expression VisitConstructor(ConstructorCallSite callSite, object? context)
        {
            ParameterInfo[] parameters = callSite.ConstructorInfo.GetParameters();
            Expression[] parameterExpressions;
            if (callSite.ParameterCallSites.Length == 0)
            {
                parameterExpressions = Array.Empty<Expression>();
            }
            else
            {
                parameterExpressions = new Expression[callSite.ParameterCallSites.Length];
                for (int i = 0; i < parameterExpressions.Length; i++)
                {
                    parameterExpressions[i] = Convert(VisitCallSite(callSite.ParameterCallSites[i], context), parameters[i].ParameterType);
                }
            }

            Expression expression = Expression.New(callSite.ConstructorInfo, parameterExpressions);
            if (callSite.ImplementationType!.IsValueType)
            {
                expression = Expression.Convert(expression, typeof(object));
            }
            return expression;
        }

        private static Expression Convert(Expression expression, Type type, bool forceValueTypeConversion = false)
        {
            // Don't convert if the expression is already assignable
            if (type.IsAssignableFrom(expression.Type)
                && (!expression.Type.IsValueType || !forceValueTypeConversion))
            {
                return expression;
            }

            return Expression.Convert(expression, type);
        }

        protected override Expression VisitScopeCache(ServiceCallSite callSite, object? context)
        {
            Func<ServiceProviderEngineScope, object> lambda = Build(callSite);
            return Expression.Invoke(Expression.Constant(lambda), ScopeParameter);
        }

        // Move off the main stack
        private ConditionalExpression BuildScopedExpression(ServiceCallSite callSite)
        {
            ConstantExpression callSiteExpression = Expression.Constant(
                callSite,
                typeof(ServiceCallSite));

            // We want to directly use the callsite value if it's set and the scope is the root scope.
            // We've already called into the RuntimeResolver and pre-computed any singletons or root scope
            // Avoid the compilation for singletons (or promoted singletons)
            MethodCallExpression resolveRootScopeExpression = Expression.Call(
                CallSiteRuntimeResolverInstanceExpression,
                ServiceLookupHelpers.ResolveCallSiteAndScopeMethodInfo,
                callSiteExpression,
                ScopeParameter);

            ConstantExpression keyExpression = Expression.Constant(
                callSite.Cache.Key,
                typeof(ServiceCacheKey));

            ParameterExpression resolvedVariable = Expression.Variable(typeof(object), "resolved");

            ParameterExpression resolvedServices = ResolvedServices;

            MethodCallExpression tryGetValueExpression = Expression.Call(
                resolvedServices,
                ServiceLookupHelpers.TryGetValueMethodInfo,
                keyExpression,
                resolvedVariable);

            Expression captureDisposible = TryCaptureDisposable(callSite, ScopeParameter, VisitCallSiteMain(callSite, null));

            BinaryExpression assignExpression = Expression.Assign(
                resolvedVariable,
                captureDisposible);

            MethodCallExpression addValueExpression = Expression.Call(
                resolvedServices,
                ServiceLookupHelpers.AddMethodInfo,
                keyExpression,
                resolvedVariable);

            BlockExpression blockExpression = Expression.Block(
                typeof(object),
                new[]
                {
                    resolvedVariable
                },
                Expression.IfThen(
                    Expression.Not(tryGetValueExpression),
                    Expression.Block(
                        assignExpression,
                        addValueExpression)),
                resolvedVariable);


            // The C# compiler would copy the lock object to guard against mutation.
            // We don't, since we know the lock object is readonly.
            ParameterExpression lockWasTaken = Expression.Variable(typeof(bool), "lockWasTaken");
            ParameterExpression sync = Sync;

            MethodCallExpression monitorEnter = Expression.Call(ServiceLookupHelpers.MonitorEnterMethodInfo, sync, lockWasTaken);
            MethodCallExpression monitorExit = Expression.Call(ServiceLookupHelpers.MonitorExitMethodInfo, sync);

            BlockExpression tryBody = Expression.Block(monitorEnter, blockExpression);
            ConditionalExpression finallyBody = Expression.IfThen(lockWasTaken, monitorExit);

            return Expression.Condition(
                    Expression.Property(
                        ScopeParameter,
                        typeof(ServiceProviderEngineScope)
                            .GetProperty(nameof(ServiceProviderEngineScope.IsRootScope), BindingFlags.Instance | BindingFlags.Public)!),
                    resolveRootScopeExpression,
                    Expression.Block(
                        typeof(object),
                        new[] { lockWasTaken },
                        Expression.TryFinally(tryBody, finallyBody))
                );
        }

        public static Expression GetCaptureDisposable(ParameterExpression scope)
        {
            if (scope != ScopeParameter)
            {
                throw new NotSupportedException(SR.GetCaptureDisposableNotSupported);
            }
            return CaptureDisposable;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/Expressions/ExpressionsServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ExpressionsServiceProviderEngine : ServiceProviderEngine
    {
        private readonly ExpressionResolverBuilder _expressionResolverBuilder;

        public ExpressionsServiceProviderEngine(ServiceProvider serviceProvider)
        {
            _expressionResolverBuilder = new ExpressionResolverBuilder(serviceProvider);
        }

        public override Func<ServiceProviderEngineScope, object> RealizeService(ServiceCallSite callSite)
        {
            return _expressionResolverBuilder.Build(callSite);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/FactoryCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class FactoryCallSite : ServiceCallSite
    {
        public Func<IServiceProvider, object> Factory { get; }

        public FactoryCallSite(ResultCache cache, Type serviceType, Func<IServiceProvider, object> factory) : base(cache)
        {
            Factory = factory;
            ServiceType = serviceType;
        }

        public FactoryCallSite(ResultCache cache, Type serviceType, object serviceKey, Func<IServiceProvider, object, object> factory) : base(cache)
        {
            Factory = sp => factory(sp, serviceKey);
            ServiceType = serviceType;
        }

        public override Type ServiceType { get; }
        public override Type? ImplementationType => null;

        public override CallSiteKind Kind { get; } = CallSiteKind.Factory;
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/IEnumerableCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class IEnumerableCallSite : ServiceCallSite
    {
        internal Type ItemType { get; }
        internal ServiceCallSite[] ServiceCallSites { get; }

        public IEnumerableCallSite(ResultCache cache, Type itemType, ServiceCallSite[] serviceCallSites) : base(cache)
        {
            Debug.Assert(!ServiceProvider.VerifyAotCompatibility || !itemType.IsValueType, "If VerifyAotCompatibility=true, an IEnumerableCallSite should not be created with a ValueType.");

            ItemType = itemType;
            ServiceCallSites = serviceCallSites;
        }

        [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
            Justification = "When ServiceProvider.VerifyAotCompatibility is true, which it is by default when PublishAot=true, " +
            "CallSiteFactory ensures ItemType is not a ValueType.")]
        public override Type ServiceType => typeof(IEnumerable<>).MakeGenericType(ItemType);

        [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
            Justification = "When ServiceProvider.VerifyAotCompatibility is true, which it is by default when PublishAot=true, " +
            "CallSiteFactory ensures ItemType is not a ValueType.")]
        public override Type ImplementationType => ItemType.MakeArrayType();

        public override CallSiteKind Kind { get; } = CallSiteKind.IEnumerable;
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ILEmit/ILEmitResolverBuilder.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    [RequiresDynamicCode("Creates DynamicMethods")]
    internal sealed class ILEmitResolverBuilder : CallSiteVisitor<ILEmitResolverBuilderContext, object?>
    {
        private static readonly MethodInfo ResolvedServicesGetter = typeof(ServiceProviderEngineScope).GetProperty(
            nameof(ServiceProviderEngineScope.ResolvedServices), BindingFlags.Instance | BindingFlags.NonPublic)!.GetMethod!;

        private static readonly MethodInfo ScopeLockGetter = typeof(ServiceProviderEngineScope).GetProperty(
            nameof(ServiceProviderEngineScope.Sync), BindingFlags.Instance | BindingFlags.NonPublic)!.GetMethod!;

        private static readonly MethodInfo ScopeIsRootScope = typeof(ServiceProviderEngineScope).GetProperty(
            nameof(ServiceProviderEngineScope.IsRootScope), BindingFlags.Instance | BindingFlags.Public)!.GetMethod!;

        private static readonly MethodInfo CallSiteRuntimeResolverResolveMethod = typeof(CallSiteRuntimeResolver).GetMethod(
            nameof(CallSiteRuntimeResolver.Resolve), BindingFlags.Public | BindingFlags.Instance)!;

        private static readonly MethodInfo CallSiteRuntimeResolverInstanceField = typeof(CallSiteRuntimeResolver).GetProperty(
            nameof(CallSiteRuntimeResolver.Instance), BindingFlags.Static | BindingFlags.Public | BindingFlags.Instance)!.GetMethod!;

        private static readonly FieldInfo FactoriesField = typeof(ILEmitResolverBuilderRuntimeContext).GetField(nameof(ILEmitResolverBuilderRuntimeContext.Factories))!;
        private static readonly FieldInfo ConstantsField = typeof(ILEmitResolverBuilderRuntimeContext).GetField(nameof(ILEmitResolverBuilderRuntimeContext.Constants))!;
        private static readonly MethodInfo GetTypeFromHandleMethod = typeof(Type).GetMethod(nameof(Type.GetTypeFromHandle))!;

        private static readonly ConstructorInfo CacheKeyCtor = typeof(ServiceCacheKey).GetConstructors()[0];

        private sealed class ILEmitResolverBuilderRuntimeContext
        {
            public object?[]? Constants;
            public Func<IServiceProvider, object>[]? Factories;
        }

        private struct GeneratedMethod
        {
            public Func<ServiceProviderEngineScope, object?> Lambda;

            public ILEmitResolverBuilderRuntimeContext Context;
            public DynamicMethod DynamicMethod;
        }

        private readonly ServiceProviderEngineScope _rootScope;

        private readonly ConcurrentDictionary<ServiceCacheKey, GeneratedMethod> _scopeResolverCache;

        private readonly Func<ServiceCacheKey, ServiceCallSite, GeneratedMethod> _buildTypeDelegate;

        public ILEmitResolverBuilder(ServiceProvider serviceProvider)
        {
            _rootScope = serviceProvider.Root;
            _scopeResolverCache = new ConcurrentDictionary<ServiceCacheKey, GeneratedMethod>();
            _buildTypeDelegate = (key, cs) => BuildTypeNoCache(cs);
        }

        public Func<ServiceProviderEngineScope, object?> Build(ServiceCallSite callSite)
        {
            return BuildType(callSite).Lambda;
        }

        private GeneratedMethod BuildType(ServiceCallSite callSite)
        {
            // Only scope methods are cached
            if (callSite.Cache.Location == CallSiteResultCacheLocation.Scope)
            {
#if NETFRAMEWORK || NETSTANDARD2_0
                return _scopeResolverCache.GetOrAdd(callSite.Cache.Key, key => _buildTypeDelegate(key, callSite));
#else
                return _scopeResolverCache.GetOrAdd(callSite.Cache.Key, _buildTypeDelegate, callSite);
#endif
            }

            return BuildTypeNoCache(callSite);
        }

        private GeneratedMethod BuildTypeNoCache(ServiceCallSite callSite)
        {
            // We need to skip visibility checks because services/constructors might be private
            var dynamicMethod = new DynamicMethod("ResolveService",
                attributes: MethodAttributes.Public | MethodAttributes.Static,
                callingConvention: CallingConventions.Standard,
                returnType: typeof(object),
                parameterTypes: new[] { typeof(ILEmitResolverBuilderRuntimeContext), typeof(ServiceProviderEngineScope) },
                owner: GetType(),
                skipVisibility: true);

            // In traces we've seen methods range from 100B - 4K sized methods since we've
            // stop trying to inline everything into scoped methods. We'll pay for a couple of resizes
            // so there'll be allocations but we could potentially change ILGenerator to use the array pool
            ILGenerator ilGenerator = dynamicMethod.GetILGenerator(512);
            ILEmitResolverBuilderRuntimeContext runtimeContext = GenerateMethodBody(callSite, ilGenerator);

#if SAVE_ASSEMBLIES
            var assemblyName = "Test" + DateTime.Now.Ticks;
            var fileName = assemblyName + ".dll";

            var assembly = AssemblyBuilder.DefineDynamicAssembly(new AssemblyName(assemblyName), AssemblyBuilderAccess.RunAndSave);
            var module = assembly.DefineDynamicModule(assemblyName, fileName);
            var type = module.DefineType(callSite.ServiceType.Name + "Resolver");

            var method = type.DefineMethod(
                "ResolveService", MethodAttributes.Public | MethodAttributes.Static, CallingConventions.Standard, typeof(object),
                new[] { typeof(ILEmitResolverBuilderRuntimeContext), typeof(ServiceProviderEngineScope) });

            GenerateMethodBody(callSite, method.GetILGenerator());
            type.CreateTypeInfo();
            // Assembly.Save is only available in .NET Framework (https://github.com/dotnet/runtime/issues/15704)
            assembly.Save(fileName);
#endif
            DependencyInjectionEventSource.Log.DynamicMethodBuilt(_rootScope.RootProvider, callSite.ServiceType, ilGenerator.ILOffset);

            return new GeneratedMethod()
            {
                Lambda = (Func<ServiceProviderEngineScope, object?>)dynamicMethod.CreateDelegate(typeof(Func<ServiceProviderEngineScope, object?>), runtimeContext),
                Context = runtimeContext,
                DynamicMethod = dynamicMethod
            };
        }


        protected override object? VisitDisposeCache(ServiceCallSite transientCallSite, ILEmitResolverBuilderContext argument)
        {
            if (transientCallSite.CaptureDisposable)
            {
                BeginCaptureDisposable(argument);
                VisitCallSiteMain(transientCallSite, argument);
                EndCaptureDisposable(argument);
            }
            else
            {
                VisitCallSiteMain(transientCallSite, argument);
            }
            return null;
        }

        protected override object? VisitConstructor(ConstructorCallSite constructorCallSite, ILEmitResolverBuilderContext argument)
        {
            // new T([create arguments])
            foreach (ServiceCallSite parameterCallSite in constructorCallSite.ParameterCallSites)
            {
                VisitCallSite(parameterCallSite, argument);
                if (parameterCallSite.ServiceType.IsValueType)
                {
                    argument.Generator.Emit(OpCodes.Unbox_Any, parameterCallSite.ServiceType);
                }
            }

            argument.Generator.Emit(OpCodes.Newobj, constructorCallSite.ConstructorInfo);
            if (constructorCallSite.ImplementationType!.IsValueType)
            {
                argument.Generator.Emit(OpCodes.Box, constructorCallSite.ImplementationType);
            }

            return null;
        }

        protected override object? VisitRootCache(ServiceCallSite callSite, ILEmitResolverBuilderContext argument)
        {
            AddConstant(argument, CallSiteRuntimeResolver.Instance.Resolve(callSite, _rootScope));
            return null;
        }

        protected override object? VisitScopeCache(ServiceCallSite scopedCallSite, ILEmitResolverBuilderContext argument)
        {
            GeneratedMethod generatedMethod = BuildType(scopedCallSite);

            // Type builder doesn't support invoking dynamic methods, replace them with delegate.Invoke calls
#if SAVE_ASSEMBLIES
            AddConstant(argument, generatedMethod.Lambda);
            // ProviderScope
            argument.Generator.Emit(OpCodes.Ldarg_1);
            argument.Generator.Emit(OpCodes.Call, generatedMethod.Lambda.GetType().GetMethod("Invoke"));
#else
            AddConstant(argument, generatedMethod.Context);
            // ProviderScope
            argument.Generator.Emit(OpCodes.Ldarg_1);
            argument.Generator.Emit(OpCodes.Call, generatedMethod.DynamicMethod);
#endif

            return null;
        }

        protected override object? VisitConstant(ConstantCallSite constantCallSite, ILEmitResolverBuilderContext argument)
        {
            AddConstant(argument, constantCallSite.DefaultValue);
            return null;
        }

        protected override object? VisitServiceProvider(ServiceProviderCallSite serviceProviderCallSite, ILEmitResolverBuilderContext argument)
        {
            // [return] ProviderScope
            argument.Generator.Emit(OpCodes.Ldarg_1);
            return null;
        }

        protected override object? VisitIEnumerable(IEnumerableCallSite enumerableCallSite, ILEmitResolverBuilderContext argument)
        {
            if (enumerableCallSite.ServiceCallSites.Length == 0)
            {
                argument.Generator.Emit(OpCodes.Call, ServiceLookupHelpers.GetArrayEmptyMethodInfo(enumerableCallSite.ItemType));
            }
            else
            {
                // var array = new ItemType[];
                // array[0] = [Create argument0];
                // array[1] = [Create argument1];
                // ...
                argument.Generator.Emit(OpCodes.Ldc_I4, enumerableCallSite.ServiceCallSites.Length);
                argument.Generator.Emit(OpCodes.Newarr, enumerableCallSite.ItemType);
                for (int i = 0; i < enumerableCallSite.ServiceCallSites.Length; i++)
                {
                    // duplicate array
                    argument.Generator.Emit(OpCodes.Dup);
                    // push index
                    argument.Generator.Emit(OpCodes.Ldc_I4, i);
                    // create parameter
                    ServiceCallSite parameterCallSite = enumerableCallSite.ServiceCallSites[i];
                    VisitCallSite(parameterCallSite, argument);
                    if (parameterCallSite.ServiceType.IsValueType)
                    {
                        argument.Generator.Emit(OpCodes.Unbox_Any, parameterCallSite.ServiceType);
                    }

                    // store
                    argument.Generator.Emit(OpCodes.Stelem, enumerableCallSite.ItemType);
                }
            }

            return null;
        }

        protected override object? VisitFactory(FactoryCallSite factoryCallSite, ILEmitResolverBuilderContext argument)
        {
            argument.Factories ??= new List<Func<IServiceProvider, object>>();

            // this.Factories[i](ProviderScope)
            argument.Generator.Emit(OpCodes.Ldarg_0);
            argument.Generator.Emit(OpCodes.Ldfld, FactoriesField);

            argument.Generator.Emit(OpCodes.Ldc_I4, argument.Factories.Count);
            argument.Generator.Emit(OpCodes.Ldelem, typeof(Func<IServiceProvider, object>));

            argument.Generator.Emit(OpCodes.Ldarg_1);
            argument.Generator.Emit(OpCodes.Call, ServiceLookupHelpers.InvokeFactoryMethodInfo);

            argument.Factories.Add(factoryCallSite.Factory);
            return null;
        }

        private static void AddConstant(ILEmitResolverBuilderContext argument, object? value)
        {
            argument.Constants ??= new List<object?>();

            // this.Constants[i]
            argument.Generator.Emit(OpCodes.Ldarg_0);
            argument.Generator.Emit(OpCodes.Ldfld, ConstantsField);

            argument.Generator.Emit(OpCodes.Ldc_I4, argument.Constants.Count);
            argument.Generator.Emit(OpCodes.Ldelem, typeof(object));
            argument.Constants.Add(value);
        }

        private static void AddCacheKey(ILEmitResolverBuilderContext argument, ServiceCacheKey key)
        {
            var id = key.ServiceIdentifier;

            // new ServiceCacheKey(key.ServiceKey, key.type, key.slot)
            AddConstant(argument, id.ServiceKey);
            argument.Generator.Emit(OpCodes.Ldtoken, id.ServiceType);
            argument.Generator.Emit(OpCodes.Call, GetTypeFromHandleMethod);
            argument.Generator.Emit(OpCodes.Ldc_I4, key.Slot);
            argument.Generator.Emit(OpCodes.Newobj, CacheKeyCtor);
        }

        private ILEmitResolverBuilderRuntimeContext GenerateMethodBody(ServiceCallSite callSite, ILGenerator generator)
        {
            var context = new ILEmitResolverBuilderContext(generator)
            {
                Constants = null,
                Factories = null
            };

            // if (scope.IsRootScope)
            // {
            //    return CallSiteRuntimeResolver.Instance.Resolve(callSite, scope);
            // }
            // var cacheKey = scopedCallSite.CacheKey;
            // object sync;
            // bool lockTaken;
            // object result;
            // try
            // {
            //    var resolvedServices = scope.ResolvedServices;
            //    sync = scope.Sync;
            //    Monitor.Enter(sync, ref lockTaken);
            //    if (!resolvedServices.TryGetValue(cacheKey, out result)
            //    {
            //       result = [createvalue];
            //       CaptureDisposable(result);
            //       resolvedServices.Add(cacheKey, result);
            //    }
            // }
            // finally
            // {
            //   if (lockTaken)
            //   {
            //      Monitor.Exit(sync);
            //   }
            // }
            // return result;

            if (callSite.Cache.Location == CallSiteResultCacheLocation.Scope)
            {
                LocalBuilder cacheKeyLocal = context.Generator.DeclareLocal(typeof(ServiceCacheKey));
                LocalBuilder resolvedServicesLocal = context.Generator.DeclareLocal(typeof(IDictionary<ServiceCacheKey, object>));
                LocalBuilder syncLocal = context.Generator.DeclareLocal(typeof(object));
                LocalBuilder lockTakenLocal = context.Generator.DeclareLocal(typeof(bool));
                LocalBuilder resultLocal = context.Generator.DeclareLocal(typeof(object));

                Label skipCreationLabel = context.Generator.DefineLabel();
                Label returnLabel = context.Generator.DefineLabel();
                Label defaultLabel = context.Generator.DefineLabel();

                // Check if scope IsRootScope
                context.Generator.Emit(OpCodes.Ldarg_1);
                context.Generator.Emit(OpCodes.Callvirt, ScopeIsRootScope);
                context.Generator.Emit(OpCodes.Brfalse_S, defaultLabel);

                context.Generator.Emit(OpCodes.Call, CallSiteRuntimeResolverInstanceField);
                AddConstant(context, callSite);
                context.Generator.Emit(OpCodes.Ldarg_1);
                context.Generator.Emit(OpCodes.Callvirt, CallSiteRuntimeResolverResolveMethod);
                context.Generator.Emit(OpCodes.Ret);

                // Generate cache key
                context.Generator.MarkLabel(defaultLabel);
                AddCacheKey(context, callSite.Cache.Key);
                // and store to local
                context.Generator.Emit(OpCodes.Stloc, cacheKeyLocal);

                context.Generator.BeginExceptionBlock();

                // scope
                context.Generator.Emit(OpCodes.Ldarg_1);
                // .ResolvedServices
                context.Generator.Emit(OpCodes.Callvirt, ResolvedServicesGetter);
                // Store resolved services
                context.Generator.Emit(OpCodes.Stloc, resolvedServicesLocal);

                // scope
                context.Generator.Emit(OpCodes.Ldarg_1);
                // .Sync
                context.Generator.Emit(OpCodes.Callvirt, ScopeLockGetter);
                // Store syncLocal
                context.Generator.Emit(OpCodes.Stloc, syncLocal);

                // Load syncLocal
                context.Generator.Emit(OpCodes.Ldloc, syncLocal);
                // Load address of lockTaken
                context.Generator.Emit(OpCodes.Ldloca, lockTakenLocal);
                // Monitor.Enter
                context.Generator.Emit(OpCodes.Call, ServiceLookupHelpers.MonitorEnterMethodInfo);

                // Load resolved services
                context.Generator.Emit(OpCodes.Ldloc, resolvedServicesLocal);
                // Load cache key
                context.Generator.Emit(OpCodes.Ldloc, cacheKeyLocal);
                // Load address of result local
                context.Generator.Emit(OpCodes.Ldloca, resultLocal);
                // .TryGetValue
                context.Generator.Emit(OpCodes.Callvirt, ServiceLookupHelpers.TryGetValueMethodInfo);

                // Jump to the end if already in cache
                context.Generator.Emit(OpCodes.Brtrue, skipCreationLabel);

                // Create value
                VisitCallSiteMain(callSite, context);
                context.Generator.Emit(OpCodes.Stloc, resultLocal);

                if (callSite.CaptureDisposable)
                {
                    BeginCaptureDisposable(context);
                    context.Generator.Emit(OpCodes.Ldloc, resultLocal);
                    EndCaptureDisposable(context);
                    // Pop value returned by CaptureDisposable off the stack
                    generator.Emit(OpCodes.Pop);
                }

                // load resolvedServices
                context.Generator.Emit(OpCodes.Ldloc, resolvedServicesLocal);
                // load cache key
                context.Generator.Emit(OpCodes.Ldloc, cacheKeyLocal);
                // load value
                context.Generator.Emit(OpCodes.Ldloc, resultLocal);
                // .Add
                context.Generator.Emit(OpCodes.Callvirt, ServiceLookupHelpers.AddMethodInfo);

                context.Generator.MarkLabel(skipCreationLabel);

                context.Generator.BeginFinallyBlock();

                // load lockTaken
                context.Generator.Emit(OpCodes.Ldloc, lockTakenLocal);
                // return if not
                context.Generator.Emit(OpCodes.Brfalse, returnLabel);
                // Load syncLocal
                context.Generator.Emit(OpCodes.Ldloc, syncLocal);
                // Monitor.Exit
                context.Generator.Emit(OpCodes.Call, ServiceLookupHelpers.MonitorExitMethodInfo);

                context.Generator.MarkLabel(returnLabel);

                context.Generator.EndExceptionBlock();

                // load value
                context.Generator.Emit(OpCodes.Ldloc, resultLocal);
                // return
                context.Generator.Emit(OpCodes.Ret);
            }
            else
            {
                VisitCallSite(callSite, context);
                // return
                context.Generator.Emit(OpCodes.Ret);
            }

            return new ILEmitResolverBuilderRuntimeContext
            {
                Constants = context.Constants?.ToArray(),
                Factories = context.Factories?.ToArray()
            };
        }

        private static void BeginCaptureDisposable(ILEmitResolverBuilderContext argument)
        {
            argument.Generator.Emit(OpCodes.Ldarg_1);
        }

        private static void EndCaptureDisposable(ILEmitResolverBuilderContext argument)
        {
            // When calling CaptureDisposable we expect callee and arguments to be on the stackcontext.Generator.BeginExceptionBlock
            argument.Generator.Emit(OpCodes.Callvirt, ServiceLookupHelpers.CaptureDisposableMethodInfo);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ILEmit/ILEmitResolverBuilderContext.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ILEmitResolverBuilderContext
    {
        public ILEmitResolverBuilderContext(ILGenerator generator) => Generator = generator;
        public ILGenerator Generator { get; }
        public List<object?>? Constants { get; set; }
        public List<Func<IServiceProvider, object>>? Factories { get; set; }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ILEmit/ILEmitServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ILEmitServiceProviderEngine : ServiceProviderEngine
    {
        private readonly ILEmitResolverBuilder _expressionResolverBuilder;

        [RequiresDynamicCode("Creates DynamicMethods")]
        public ILEmitServiceProviderEngine(ServiceProvider serviceProvider)
        {
            _expressionResolverBuilder = new ILEmitResolverBuilder(serviceProvider);
        }

        public override Func<ServiceProviderEngineScope, object?> RealizeService(ServiceCallSite callSite)
        {
            return _expressionResolverBuilder.Build(callSite);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ResultCache.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal struct ResultCache
    {
        public static ResultCache None(Type serviceType)
        {
            var cacheKey = new ServiceCacheKey(ServiceIdentifier.FromServiceType(serviceType), 0);
            return new ResultCache(CallSiteResultCacheLocation.None, cacheKey);
        }

        internal ResultCache(CallSiteResultCacheLocation lifetime, ServiceCacheKey cacheKey)
        {
            Location = lifetime;
            Key = cacheKey;
        }

        public ResultCache(ServiceLifetime lifetime, ServiceIdentifier serviceIdentifier, int slot)
        {
            switch (lifetime)
            {
                case ServiceLifetime.Singleton:
                    Location = CallSiteResultCacheLocation.Root;
                    break;
                case ServiceLifetime.Scoped:
                    Location = CallSiteResultCacheLocation.Scope;
                    break;
                case ServiceLifetime.Transient:
                    Location = CallSiteResultCacheLocation.Dispose;
                    break;
                default:
                    Location = CallSiteResultCacheLocation.None;
                    break;
            }
            Key = new ServiceCacheKey(serviceIdentifier, slot);
        }

        public CallSiteResultCacheLocation Location { get; set; }

        public ServiceCacheKey Key { get; set; }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/RuntimeServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class RuntimeServiceProviderEngine : ServiceProviderEngine
    {
        public static RuntimeServiceProviderEngine Instance { get; } = new RuntimeServiceProviderEngine();

        private RuntimeServiceProviderEngine() { }

        public override Func<ServiceProviderEngineScope, object?> RealizeService(ServiceCallSite callSite)
        {
            return scope =>
            {
                return CallSiteRuntimeResolver.Instance.Resolve(callSite, scope);
            };
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceCacheKey.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal readonly struct ServiceCacheKey : IEquatable<ServiceCacheKey>
    {
        /// <summary>
        /// Type of service being cached
        /// </summary>
        public ServiceIdentifier ServiceIdentifier { get; }

        /// <summary>
        /// Reverse index of the service when resolved in <c>IEnumerable&lt;Type&gt;</c> where default instance gets slot 0.
        /// For example for service collection
        ///  IService Impl1
        ///  IService Impl2
        ///  IService Impl3
        /// We would get the following cache keys:
        ///  Impl1 2
        ///  Impl2 1
        ///  Impl3 0
        /// </summary>
        public int Slot { get; }

        public ServiceCacheKey(object key, Type type, int slot)
        {
            ServiceIdentifier = new ServiceIdentifier(key, type);
            Slot = slot;
        }

        public ServiceCacheKey(ServiceIdentifier type, int slot)
        {
            ServiceIdentifier = type;
            Slot = slot;
        }

        /// <summary>Indicates whether the current instance is equal to another instance of the same type.</summary>
        /// <param name="other">An instance to compare with this instance.</param>
        /// <returns>true if the current instance is equal to the other instance; otherwise, false.</returns>
        public bool Equals(ServiceCacheKey other) =>
            ServiceIdentifier.Equals(other.ServiceIdentifier) && Slot == other.Slot;

        public override bool Equals([NotNullWhen(true)] object? obj) =>
            obj is ServiceCacheKey other && Equals(other);

        public override int GetHashCode()
        {
            unchecked
            {
                return (ServiceIdentifier.GetHashCode() * 397) ^ Slot;
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    /// <summary>
    /// Summary description for ServiceCallSite
    /// </summary>
    internal abstract class ServiceCallSite
    {
        protected ServiceCallSite(ResultCache cache)
        {
            Cache = cache;
        }

        public abstract Type ServiceType { get; }
        public abstract Type? ImplementationType { get; }
        public abstract CallSiteKind Kind { get; }
        public ResultCache Cache { get; }
        public object? Value { get; set; }
        public object? Key { get; set; }

        public bool CaptureDisposable =>
            ImplementationType == null ||
            typeof(IDisposable).IsAssignableFrom(ImplementationType) ||
            typeof(IAsyncDisposable).IsAssignableFrom(ImplementationType);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceDescriptorExtensions.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal static class ServiceDescriptorExtensions
    {
        public static bool HasImplementationInstance(this ServiceDescriptor serviceDescriptor) => GetImplementationInstance(serviceDescriptor) != null;

        public static bool HasImplementationFactory(this ServiceDescriptor serviceDescriptor) => GetImplementationFactory(serviceDescriptor) != null;

        public static bool HasImplementationType(this ServiceDescriptor serviceDescriptor) => GetImplementationType(serviceDescriptor) != null;

        public static object? GetImplementationInstance(this ServiceDescriptor serviceDescriptor)
        {
            return serviceDescriptor.IsKeyedService
                ? serviceDescriptor.KeyedImplementationInstance
                : serviceDescriptor.ImplementationInstance;
        }

        public static object? GetImplementationFactory(this ServiceDescriptor serviceDescriptor)
        {
            return serviceDescriptor.IsKeyedService
                ? serviceDescriptor.KeyedImplementationFactory
                : serviceDescriptor.ImplementationFactory;
        }

        [return: DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)]
        public static Type? GetImplementationType(this ServiceDescriptor serviceDescriptor)
        {
            return serviceDescriptor.IsKeyedService
                ? serviceDescriptor.KeyedImplementationType
                : serviceDescriptor.ImplementationType;
        }

        public static bool TryGetImplementationType(this ServiceDescriptor serviceDescriptor, out Type? type)
        {
            type = GetImplementationType(serviceDescriptor);
            return type != null;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceIdentifier.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal readonly struct ServiceIdentifier : IEquatable<ServiceIdentifier>
    {
        public object? ServiceKey { get; }

        public Type ServiceType { get; }

        public ServiceIdentifier(Type serviceType)
        {
            ServiceType = serviceType;
        }

        public ServiceIdentifier(object? serviceKey, Type serviceType)
        {
            ServiceKey = serviceKey;
            ServiceType = serviceType;
        }

        public static ServiceIdentifier FromDescriptor(ServiceDescriptor serviceDescriptor)
            => new ServiceIdentifier(serviceDescriptor.ServiceKey, serviceDescriptor.ServiceType);

        public static ServiceIdentifier FromServiceType(Type type) => new ServiceIdentifier(null, type);

        public bool Equals(ServiceIdentifier other)
        {
            if (ServiceKey == null && other.ServiceKey == null)
            {
                return ServiceType == other.ServiceType;
            }
            else if (ServiceKey != null && other.ServiceKey != null)
            {
                return ServiceType == other.ServiceType && ServiceKey.Equals(other.ServiceKey);
            }
            return false;
        }

        public override bool Equals([NotNullWhen(true)] object? obj)
        {
            return obj is ServiceIdentifier && Equals((ServiceIdentifier)obj);
        }

        public override int GetHashCode()
        {
            if (ServiceKey == null)
            {
                return ServiceType.GetHashCode();
            }
            unchecked
            {
                return (ServiceType.GetHashCode() * 397) ^ ServiceKey.GetHashCode();
            }
        }

        public bool IsConstructedGenericType => ServiceType.IsConstructedGenericType;

        public ServiceIdentifier GetGenericTypeDefinition() => new ServiceIdentifier(ServiceKey, ServiceType.GetGenericTypeDefinition());

        public override string? ToString()
        {
            if (ServiceKey == null)
            {
                return ServiceType.ToString();
            }

            return $"({ServiceKey}, {ServiceType})";
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceLookupHelpers.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal static class ServiceLookupHelpers
    {
        private const BindingFlags LookupFlags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;
        private static readonly MethodInfo ArrayEmptyMethodInfo = typeof(Array).GetMethod(nameof(Array.Empty))!;

        internal static readonly MethodInfo InvokeFactoryMethodInfo = typeof(Func<IServiceProvider, object>)
            .GetMethod(nameof(Func<IServiceProvider, object>.Invoke), LookupFlags)!;

        internal static readonly MethodInfo CaptureDisposableMethodInfo = typeof(ServiceProviderEngineScope)
            .GetMethod(nameof(ServiceProviderEngineScope.CaptureDisposable), LookupFlags)!;

        internal static readonly MethodInfo TryGetValueMethodInfo = typeof(IDictionary<ServiceCacheKey, object>)
            .GetMethod(nameof(IDictionary<ServiceCacheKey, object>.TryGetValue), LookupFlags)!;

        internal static readonly MethodInfo ResolveCallSiteAndScopeMethodInfo = typeof(CallSiteRuntimeResolver)
            .GetMethod(nameof(CallSiteRuntimeResolver.Resolve), LookupFlags)!;

        internal static readonly MethodInfo AddMethodInfo = typeof(IDictionary<ServiceCacheKey, object>)
            .GetMethod(nameof(IDictionary<ServiceCacheKey, object>.Add), LookupFlags)!;

        internal static readonly MethodInfo MonitorEnterMethodInfo = typeof(Monitor)
            .GetMethod(nameof(Monitor.Enter), BindingFlags.Public | BindingFlags.Static, null, new Type[] { typeof(object), typeof(bool).MakeByRefType() }, null)!;
        internal static readonly MethodInfo MonitorExitMethodInfo = typeof(Monitor)
            .GetMethod(nameof(Monitor.Exit), BindingFlags.Public | BindingFlags.Static, null, new Type[] { typeof(object) }, null)!;

        [RequiresDynamicCode("The code for an array of the specified type might not be available.")]
        [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2060:MakeGenericMethod",
            Justification = "Calling Array.Empty<T>() is safe since the T doesn't have trimming annotations.")]
        internal static MethodInfo GetArrayEmptyMethodInfo(Type itemType) =>
            ArrayEmptyMethodInfo.MakeGenericMethod(itemType);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceProviderCallSite.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class ServiceProviderCallSite : ServiceCallSite
    {
        public ServiceProviderCallSite() : base(ResultCache.None(typeof(IServiceProvider)))
        {
        }

        public override Type ServiceType { get; } = typeof(IServiceProvider);
        public override Type ImplementationType { get; } = typeof(ServiceProvider);
        public override CallSiteKind Kind { get; } = CallSiteKind.ServiceProvider;
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceProviderEngine.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal abstract class ServiceProviderEngine
    {
        public abstract Func<ServiceProviderEngineScope, object?> RealizeService(ServiceCallSite callSite);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ServiceProviderEngineScope.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    [DebuggerTypeProxy(typeof(ServiceProviderEngineScopeDebugView))]
    internal sealed class ServiceProviderEngineScope : IServiceScope, IServiceProvider, IKeyedServiceProvider, IAsyncDisposable, IServiceScopeFactory
    {
        // For testing and debugging only
        internal IList<object> Disposables => _disposables ?? (IList<object>)Array.Empty<object>();

        private bool _disposed;
        private List<object>? _disposables;

        public ServiceProviderEngineScope(ServiceProvider provider, bool isRootScope)
        {
            ResolvedServices = new Dictionary<ServiceCacheKey, object?>();
            RootProvider = provider;
            IsRootScope = isRootScope;
        }

        internal Dictionary<ServiceCacheKey, object?> ResolvedServices { get; }

        internal bool Disposed => _disposed;

        // This lock protects state on the scope, in particular, for the root scope, it protects
        // the list of disposable entries only, since ResolvedServices are cached on CallSites
        // For other scopes, it protects ResolvedServices and the list of disposables
        internal object Sync => ResolvedServices;

        public bool IsRootScope { get; }

        internal ServiceProvider RootProvider { get; }

        public object? GetService(Type serviceType)
        {
            if (_disposed)
            {
                ThrowHelper.ThrowObjectDisposedException();
            }

            return RootProvider.GetService(ServiceIdentifier.FromServiceType(serviceType), this);
        }

        public object? GetKeyedService(Type serviceType, object? serviceKey)
        {
            if (_disposed)
            {
                ThrowHelper.ThrowObjectDisposedException();
            }

            return RootProvider.GetKeyedService(serviceType, serviceKey, this);
        }

        public object GetRequiredKeyedService(Type serviceType, object? serviceKey)
        {
            if (_disposed)
            {
                ThrowHelper.ThrowObjectDisposedException();
            }

            return RootProvider.GetRequiredKeyedService(serviceType, serviceKey, this);
        }

        public IServiceProvider ServiceProvider => this;

        public IServiceScope CreateScope() => RootProvider.CreateScope();

        [return: NotNullIfNotNull(nameof(service))]
        internal object? CaptureDisposable(object? service)
        {
            if (ReferenceEquals(this, service) || !(service is IDisposable || service is IAsyncDisposable))
            {
                return service;
            }

            bool disposed = false;
            lock (Sync)
            {
                if (_disposed)
                {
                    disposed = true;
                }
                else
                {
                    _disposables ??= new List<object>();

                    _disposables.Add(service);
                }
            }

            // Don't run customer code under the lock
            if (disposed)
            {
                if (service is IDisposable disposable)
                {
                    disposable.Dispose();
                }
                else
                {
                    // sync over async, for the rare case that an object only implements IAsyncDisposable and may end up starving the thread pool.
                    object? localService = service; // copy to avoid closure on other paths
                    Task.Run(() => ((IAsyncDisposable)localService).DisposeAsync().AsTask()).GetAwaiter().GetResult();
                }

                ThrowHelper.ThrowObjectDisposedException();
            }

            return service;
        }

        public void Dispose()
        {
            List<object>? toDispose = BeginDispose();

            if (toDispose != null)
            {
                for (int i = toDispose.Count - 1; i >= 0; i--)
                {
                    if (toDispose[i] is IDisposable disposable)
                    {
                        disposable.Dispose();
                    }
                    else
                    {
                        throw new InvalidOperationException(SR.Format(SR.AsyncDisposableServiceDispose, TypeNameHelper.GetTypeDisplayName(toDispose[i])));
                    }
                }
            }
        }

        public ValueTask DisposeAsync()
        {
            List<object>? toDispose = BeginDispose();

            if (toDispose != null)
            {
                try
                {
                    for (int i = toDispose.Count - 1; i >= 0; i--)
                    {
                        object disposable = toDispose[i];
                        if (disposable is IAsyncDisposable asyncDisposable)
                        {
                            ValueTask vt = asyncDisposable.DisposeAsync();
                            if (!vt.IsCompletedSuccessfully)
                            {
                                return Await(i, vt, toDispose);
                            }

                            // If its a IValueTaskSource backed ValueTask,
                            // inform it its result has been read so it can reset
                            vt.GetAwaiter().GetResult();
                        }
                        else
                        {
                            ((IDisposable)disposable).Dispose();
                        }
                    }
                }
                catch (Exception ex)
                {
                    return new ValueTask(Task.FromException(ex));
                }
            }

            return default;

            static async ValueTask Await(int i, ValueTask vt, List<object> toDispose)
            {
                await vt.ConfigureAwait(false);
                // vt is acting on the disposable at index i,
                // decrement it and move to the next iteration
                i--;

                for (; i >= 0; i--)
                {
                    object disposable = toDispose[i];
                    if (disposable is IAsyncDisposable asyncDisposable)
                    {
                        await asyncDisposable.DisposeAsync().ConfigureAwait(false);
                    }
                    else
                    {
                        ((IDisposable)disposable).Dispose();
                    }
                }
            }
        }

        private List<object>? BeginDispose()
        {
            lock (Sync)
            {
                if (_disposed)
                {
                    return null;
                }

                // Track statistics about the scope (number of disposable objects and number of disposed services)
                DependencyInjectionEventSource.Log.ScopeDisposed(RootProvider.GetHashCode(), ResolvedServices.Count, _disposables?.Count ?? 0);

                // We've transitioned to the disposed state, so future calls to
                // CaptureDisposable will immediately dispose the object.
                // No further changes to _state.Disposables, are allowed.
                _disposed = true;

            }

            if (IsRootScope && !RootProvider.IsDisposed())
            {
                // If this ServiceProviderEngineScope instance is a root scope, disposing this instance will need to dispose the RootProvider too.
                // Otherwise the RootProvider will never get disposed and will leak.
                // Note, if the RootProvider get disposed first, it will automatically dispose all attached ServiceProviderEngineScope objects.
                RootProvider.Dispose();
            }

            // ResolvedServices is never cleared for singletons because there might be a compilation running in background
            // trying to get a cached singleton service. If it doesn't find it
            // it will try to create a new one which will result in an ObjectDisposedException.
            return _disposables;
        }

        internal string DebuggerToString()
        {
            string debugText = $"ServiceDescriptors = {RootProvider.CallSiteFactory.Descriptors.Length}";
            if (!IsRootScope)
            {
                debugText += $", IsScope = true";
            }
            if (_disposed)
            {
                debugText += $", Disposed = true";
            }
            return debugText;
        }

        private sealed class ServiceProviderEngineScopeDebugView
        {
            private readonly ServiceProviderEngineScope _serviceProvider;

            public ServiceProviderEngineScopeDebugView(ServiceProviderEngineScope serviceProvider)
            {
                _serviceProvider = serviceProvider;
            }

            public List<ServiceDescriptor> ServiceDescriptors => new List<ServiceDescriptor>(_serviceProvider.RootProvider.CallSiteFactory.Descriptors);
            public List<object> Disposables => new List<object>(_serviceProvider.Disposables);
            public bool Disposed => _serviceProvider._disposed;
            public bool IsScope => !_serviceProvider.IsRootScope;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/StackGuard.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal sealed class StackGuard
    {
        private const int MaxExecutionStackCount = 1024;

        private int _executionStackCount;

        public bool TryEnterOnCurrentStack()
        {
#if NETFRAMEWORK || NETSTANDARD2_0
            try
            {
                RuntimeHelpers.EnsureSufficientExecutionStack();
                return true;
            }
            catch (InsufficientExecutionStackException)
            {
            }
#else
            if (RuntimeHelpers.TryEnsureSufficientExecutionStack())
            {
                return true;
            }
#endif

            if (_executionStackCount < MaxExecutionStackCount)
            {
                return false;
            }

            throw new InsufficientExecutionStackException();
        }

        public TR RunOnEmptyStack<T1, T2, TR>(Func<T1, T2, TR> action, T1 arg1, T2 arg2)
        {
#if NETFRAMEWORK || NETSTANDARD2_0
            return RunOnEmptyStackCore(static s =>
            {
                var t = (Tuple<Func<T1, T2, TR>, T1, T2>)s;
                return t.Item1(t.Item2, t.Item3);
            }, Tuple.Create(action, arg1, arg2));
#else
            // Prefer ValueTuple when available to reduce dependencies on Tuple
            return RunOnEmptyStackCore(static s =>
            {
                var t = ((Func<T1, T2, TR>, T1, T2))s;
                return t.Item1(t.Item2, t.Item3);
            }, (action, arg1, arg2));
#endif
        }

        private R RunOnEmptyStackCore<R>(Func<object, R> action, object state)
        {
            _executionStackCount++;

            try
            {
                // Using default scheduler rather than picking up the current scheduler.
                Task<R> task = Task.Factory.StartNew((Func<object?, R>)action, state, CancellationToken.None, TaskCreationOptions.DenyChildAttach, TaskScheduler.Default);

                // Avoid AsyncWaitHandle lazy allocation of ManualResetEvent in the rare case we finish quickly.
                if (!task.IsCompleted)
                {
                    // Task.Wait has the potential of inlining the task's execution on the current thread; avoid this.
                    ((IAsyncResult)task).AsyncWaitHandle.WaitOne();
                }

                // Using awaiter here to propagate original exception
                return task.GetAwaiter().GetResult();
            }
            finally
            {
                _executionStackCount--;
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceLookup/ThrowHelper.cs
namespace Microsoft.Extensions.DependencyInjection.ServiceLookup
{
    internal static class ThrowHelper
    {
        [DoesNotReturn]
        [MethodImpl(MethodImplOptions.NoInlining)]
        internal static void ThrowObjectDisposedException()
        {
            throw new ObjectDisposedException(nameof(IServiceProvider));
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceProvider.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// The default IServiceProvider.
    /// </summary>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    [DebuggerTypeProxy(typeof(ServiceProviderDebugView))]
    public sealed class ServiceProvider : IServiceProvider, IKeyedServiceProvider, IDisposable, IAsyncDisposable
    {
        private readonly CallSiteValidator? _callSiteValidator;

        private readonly Func<ServiceIdentifier, ServiceAccessor> _createServiceAccessor;

        // Internal for testing
        internal ServiceProviderEngine _engine;

        private bool _disposed;

        private readonly ConcurrentDictionary<ServiceIdentifier, ServiceAccessor> _serviceAccessors;

        internal CallSiteFactory CallSiteFactory { get; }

        internal ServiceProviderEngineScope Root { get; }

        internal static bool VerifyOpenGenericServiceTrimmability { get; } =
            AppContext.TryGetSwitch("Microsoft.Extensions.DependencyInjection.VerifyOpenGenericServiceTrimmability", out bool verifyOpenGenerics) ? verifyOpenGenerics : false;

        internal static bool DisableDynamicEngine { get; } =
            AppContext.TryGetSwitch("Microsoft.Extensions.DependencyInjection.DisableDynamicEngine", out bool disableDynamicEngine) ? disableDynamicEngine : false;

        internal static bool VerifyAotCompatibility =>
#if NETFRAMEWORK || NETSTANDARD2_0
            false;
#else
            !RuntimeFeature.IsDynamicCodeSupported;
#endif

        internal ServiceProvider(ICollection<ServiceDescriptor> serviceDescriptors, ServiceProviderOptions options)
        {
            // note that Root needs to be set before calling GetEngine(), because the engine may need to access Root
            Root = new ServiceProviderEngineScope(this, isRootScope: true);
            _engine = GetEngine();
            _createServiceAccessor = CreateServiceAccessor;
            _serviceAccessors = new ConcurrentDictionary<ServiceIdentifier, ServiceAccessor>();

            CallSiteFactory = new CallSiteFactory(serviceDescriptors);
            // The list of built in services that aren't part of the list of service descriptors
            // keep this in sync with CallSiteFactory.IsService
            CallSiteFactory.Add(ServiceIdentifier.FromServiceType(typeof(IServiceProvider)), new ServiceProviderCallSite());
            CallSiteFactory.Add(ServiceIdentifier.FromServiceType(typeof(IServiceScopeFactory)), new ConstantCallSite(typeof(IServiceScopeFactory), Root));
            CallSiteFactory.Add(ServiceIdentifier.FromServiceType(typeof(IServiceProviderIsService)), new ConstantCallSite(typeof(IServiceProviderIsService), CallSiteFactory));
            CallSiteFactory.Add(ServiceIdentifier.FromServiceType(typeof(IServiceProviderIsKeyedService)), new ConstantCallSite(typeof(IServiceProviderIsKeyedService), CallSiteFactory));

            if (options.ValidateScopes)
            {
                _callSiteValidator = new CallSiteValidator();
            }

            if (options.ValidateOnBuild)
            {
                List<Exception>? exceptions = null;
                foreach (ServiceDescriptor serviceDescriptor in serviceDescriptors)
                {
                    try
                    {
                        ValidateService(serviceDescriptor);
                    }
                    catch (Exception e)
                    {
                        exceptions ??= new List<Exception>();
                        exceptions.Add(e);
                    }
                }

                if (exceptions != null)
                {
                    throw new AggregateException("Some services are not able to be constructed", exceptions.ToArray());
                }
            }

            DependencyInjectionEventSource.Log.ServiceProviderBuilt(this);
        }

        /// <summary>
        /// Gets the service object of the specified type.
        /// </summary>
        /// <param name="serviceType">The type of the service to get.</param>
        /// <returns>The service that was produced.</returns>
        public object? GetService(Type serviceType) => GetService(ServiceIdentifier.FromServiceType(serviceType), Root);

        /// <summary>
        /// Gets the service object of the specified type with the specified key.
        /// </summary>
        /// <param name="serviceType">The type of the service to get.</param>
        /// <param name="serviceKey">The key of the service to get.</param>
        /// <returns>The keyed service.</returns>
        public object? GetKeyedService(Type serviceType, object? serviceKey)
            => GetKeyedService(serviceType, serviceKey, Root);

        internal object? GetKeyedService(Type serviceType, object? serviceKey, ServiceProviderEngineScope serviceProviderEngineScope)
            => GetService(new ServiceIdentifier(serviceKey, serviceType), serviceProviderEngineScope);

        /// <summary>
        /// Gets the service object of the specified type. Will throw if the service not found.
        /// </summary>
        /// <param name="serviceType">The type of the service to get.</param>
        /// <param name="serviceKey">The key of the service to get.</param>
        /// <returns>The keyed service.</returns>
        /// <exception cref="InvalidOperationException"></exception>
        public object GetRequiredKeyedService(Type serviceType, object? serviceKey)
            => GetRequiredKeyedService(serviceType, serviceKey, Root);

        internal object GetRequiredKeyedService(Type serviceType, object? serviceKey, ServiceProviderEngineScope serviceProviderEngineScope)
        {
            object? service = GetKeyedService(serviceType, serviceKey, serviceProviderEngineScope);
            if (service == null)
            {
                throw new InvalidOperationException(SR.Format(SR.NoServiceRegistered, serviceType));
            }
            return service;
        }

        internal bool IsDisposed() => _disposed;

        /// <inheritdoc />
        public void Dispose()
        {
            DisposeCore();
            Root.Dispose();
        }

        /// <inheritdoc/>
        public ValueTask DisposeAsync()
        {
            DisposeCore();
            return Root.DisposeAsync();
        }

        private void DisposeCore()
        {
            _disposed = true;
            DependencyInjectionEventSource.Log.ServiceProviderDisposed(this);
        }

        private void OnCreate(ServiceCallSite callSite)
        {
            _callSiteValidator?.ValidateCallSite(callSite);
        }

        private void OnResolve(ServiceCallSite? callSite, IServiceScope scope)
        {
            if (callSite != null)
            {
                _callSiteValidator?.ValidateResolution(callSite, scope, Root);
            }
        }

        internal object? GetService(ServiceIdentifier serviceIdentifier, ServiceProviderEngineScope serviceProviderEngineScope)
        {
            if (_disposed)
            {
                ThrowHelper.ThrowObjectDisposedException();
            }
            ServiceAccessor serviceAccessor = _serviceAccessors.GetOrAdd(serviceIdentifier, _createServiceAccessor);
            OnResolve(serviceAccessor.CallSite, serviceProviderEngineScope);
            DependencyInjectionEventSource.Log.ServiceResolved(this, serviceIdentifier.ServiceType);
            object? result = serviceAccessor.RealizedService?.Invoke(serviceProviderEngineScope);
            System.Diagnostics.Debug.Assert(result is null || CallSiteFactory.IsService(serviceIdentifier));
            return result;
        }

        private void ValidateService(ServiceDescriptor descriptor)
        {
            if (descriptor.ServiceType.IsGenericType && !descriptor.ServiceType.IsConstructedGenericType)
            {
                return;
            }

            try
            {
                ServiceCallSite? callSite = CallSiteFactory.GetCallSite(descriptor, new CallSiteChain());
                if (callSite != null)
                {
                    OnCreate(callSite);
                }
            }
            catch (Exception e)
            {
                throw new InvalidOperationException($"Error while validating the service descriptor '{descriptor}': {e.Message}", e);
            }
        }

        private ServiceAccessor CreateServiceAccessor(ServiceIdentifier serviceIdentifier)
        {
            ServiceCallSite? callSite = CallSiteFactory.GetCallSite(serviceIdentifier, new CallSiteChain());
            if (callSite != null)
            {
                DependencyInjectionEventSource.Log.CallSiteBuilt(this, serviceIdentifier.ServiceType, callSite);
                OnCreate(callSite);

                // Optimize singleton case
                if (callSite.Cache.Location == CallSiteResultCacheLocation.Root)
                {
                    object? value = CallSiteRuntimeResolver.Instance.Resolve(callSite, Root);
                    return new ServiceAccessor { CallSite = callSite, RealizedService = scope => value };
                }

                Func<ServiceProviderEngineScope, object?> realizedService = _engine.RealizeService(callSite);
                return new ServiceAccessor { CallSite = callSite, RealizedService = realizedService };
            }
            return new ServiceAccessor { CallSite = callSite, RealizedService = _ => null };
        }

        internal void ReplaceServiceAccessor(ServiceCallSite callSite, Func<ServiceProviderEngineScope, object?> accessor)
        {
            _serviceAccessors[new ServiceIdentifier(callSite.Key, callSite.ServiceType)] = new ServiceAccessor
            {
                CallSite = callSite,
                RealizedService = accessor
            };
        }

        internal IServiceScope CreateScope()
        {
            if (_disposed)
            {
                ThrowHelper.ThrowObjectDisposedException();
            }

            return new ServiceProviderEngineScope(this, isRootScope: false);
        }

        private ServiceProviderEngine GetEngine()
        {
            ServiceProviderEngine engine;

#if NETFRAMEWORK || NETSTANDARD2_0
            engine = CreateDynamicEngine();
#else
            if (RuntimeFeature.IsDynamicCodeCompiled && !DisableDynamicEngine)
            {
                engine = CreateDynamicEngine();
            }
            else
            {
                // Don't try to compile Expressions/IL if they are going to get interpreted
                engine = RuntimeServiceProviderEngine.Instance;
            }
#endif
            return engine;

            [UnconditionalSuppressMessage("AotAnalysis", "IL3050:RequiresDynamicCode",
                Justification = "CreateDynamicEngine won't be called when using NativeAOT.")] // see also https://github.com/dotnet/linker/issues/2715
            ServiceProviderEngine CreateDynamicEngine() => new DynamicServiceProviderEngine(this);
        }

        private string DebuggerToString() => Root.DebuggerToString();

        internal sealed class ServiceProviderDebugView
        {
            private readonly ServiceProvider _serviceProvider;

            public ServiceProviderDebugView(ServiceProvider serviceProvider)
            {
                _serviceProvider = serviceProvider;
            }

            public List<ServiceDescriptor> ServiceDescriptors => new List<ServiceDescriptor>(_serviceProvider.Root.RootProvider.CallSiteFactory.Descriptors);
            public List<object> Disposables => new List<object>(_serviceProvider.Root.Disposables);
            public bool Disposed => _serviceProvider.Root.Disposed;
            public bool IsScope => !_serviceProvider.Root.IsRootScope;
        }

        private sealed class ServiceAccessor
        {
            public ServiceCallSite? CallSite { get; set; }
            public Func<ServiceProviderEngineScope, object?>? RealizedService { get; set; }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection/src/ServiceProviderOptions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Options for configuring various behaviors of the default <see cref="IServiceProvider"/> implementation.
    /// </summary>
    public class ServiceProviderOptions
    {
        // Avoid allocating objects in the default case
        internal static readonly ServiceProviderOptions Default = new ServiceProviderOptions();

        /// <summary>
        /// <c>true</c> to perform check verifying that scoped services never gets resolved from root provider; otherwise <c>false</c>. Defaults to <c>false</c>.
        /// </summary>
        public bool ValidateScopes { get; set; }

        /// <summary>
        /// <c>true</c> to perform check verifying that all services can be created during <c>BuildServiceProvider</c> call; otherwise <c>false</c>. Defaults to <c>false</c>.
        /// NOTE: this check doesn't verify open generics services.
        /// </summary>
        public bool ValidateOnBuild { get; set; }
    }
}

#nullable disable

namespace FxResources.Microsoft.Extensions.DependencyInjection
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
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.DependencyInjection.SR));

        internal static string AmbiguousConstructorException => GetResourceString("AmbiguousConstructorException");

        internal static string CannotResolveService => GetResourceString("CannotResolveService");

        internal static string CircularDependencyException => GetResourceString("CircularDependencyException");

        internal static string UnableToActivateTypeException => GetResourceString("UnableToActivateTypeException");

        internal static string OpenGenericServiceRequiresOpenGenericImplementation => GetResourceString("OpenGenericServiceRequiresOpenGenericImplementation");

        internal static string ArityOfOpenGenericServiceNotEqualArityOfOpenGenericImplementation => GetResourceString("ArityOfOpenGenericServiceNotEqualArityOfOpenGenericImplementation");

        internal static string TypeCannotBeActivated => GetResourceString("TypeCannotBeActivated");

        internal static string NoConstructorMatch => GetResourceString("NoConstructorMatch");

        internal static string ScopedInSingletonException => GetResourceString("ScopedInSingletonException");

        internal static string ScopedResolvedFromRootException => GetResourceString("ScopedResolvedFromRootException");

        internal static string DirectScopedResolvedFromRootException => GetResourceString("DirectScopedResolvedFromRootException");

        internal static string ConstantCantBeConvertedToServiceType => GetResourceString("ConstantCantBeConvertedToServiceType");

        internal static string ImplementationTypeCantBeConvertedToServiceType => GetResourceString("ImplementationTypeCantBeConvertedToServiceType");

        internal static string AsyncDisposableServiceDispose => GetResourceString("AsyncDisposableServiceDispose");

        internal static string GetCaptureDisposableNotSupported => GetResourceString("GetCaptureDisposableNotSupported");

        internal static string InvalidServiceDescriptor => GetResourceString("InvalidServiceDescriptor");

        internal static string ServiceDescriptorNotExist => GetResourceString("ServiceDescriptorNotExist");

        internal static string CallSiteTypeNotSupported => GetResourceString("CallSiteTypeNotSupported");

        internal static string TrimmingAnnotationsDoNotMatch => GetResourceString("TrimmingAnnotationsDoNotMatch");

        internal static string TrimmingAnnotationsDoNotMatch_NewConstraint => GetResourceString("TrimmingAnnotationsDoNotMatch_NewConstraint");

        internal static string AotCannotCreateEnumerableValueType => GetResourceString("AotCannotCreateEnumerableValueType");

        internal static string AotCannotCreateGenericValueType => GetResourceString("AotCannotCreateGenericValueType");

        internal static string NoServiceRegistered => GetResourceString("NoServiceRegistered");

        internal static string InvalidServiceKeyType => GetResourceString("InvalidServiceKeyType");
    }
}
