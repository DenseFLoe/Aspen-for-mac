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

using Microsoft.Extensions.DependencyInjection.Extensions;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Threading;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.Logging")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Logging infrastructure default implementation for Microsoft.Extensions.Logging.")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.Logging")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]
[assembly: TypeForwardedTo(typeof(ILoggingBuilder))]

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

// src/libraries/Common/src/Extensions/ProviderAliasUtilities/ProviderAliasUtilities.cs
namespace Microsoft.Extensions.Logging
{
    internal static class ProviderAliasUtilities
    {
        private const string AliasAttributeTypeFullName = "Microsoft.Extensions.Logging.ProviderAliasAttribute";

        internal static string? GetAlias(Type providerType)
        {
            IList<CustomAttributeData> attributes = CustomAttributeData.GetCustomAttributes(providerType);

            for (int i = 0; i < attributes.Count; i++)
            {
                CustomAttributeData attributeData = attributes[i];
                if (attributeData.AttributeType.FullName == AliasAttributeTypeFullName &&
                    attributeData.ConstructorArguments.Count > 0)
                {
                    CustomAttributeTypedArgument arg = attributeData.ConstructorArguments[0];

                    Debug.Assert(arg.ArgumentType == typeof(string));

                    return arg.Value?.ToString();
                }
            }

            return null;
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

// src/libraries/Microsoft.Extensions.Logging/src/ActivityTrackingOptions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Flags to indicate which trace context parts should be included with the logging scopes.
    /// </summary>
    [Flags]
    public enum ActivityTrackingOptions
    {
        /// <summary>
        /// None of the trace context part will be included in the logging.
        /// </summary>
        None        = 0x0000,

        /// <summary>
        /// Span Id will be included in the logging.
        /// </summary>
        SpanId      = 0x0001,

        /// <summary>
        /// Trace Id will be included in the logging.
        /// </summary>
        TraceId     = 0x0002,

        /// <summary>
        /// Parent Id will be included in the logging.
        /// </summary>
        ParentId    = 0x0004,

        /// <summary>
        /// Trace State will be included in the logging.
        /// </summary>
        TraceState  = 0x0008,

        /// <summary>
        /// Trace flags will be included in the logging.
        /// </summary>
        TraceFlags  = 0x0010,

        /// <summary>
        /// Tags will be included in the logging.
        /// </summary>
        Tags        = 0x0020,

        /// <summary>
        /// Items of baggage will be included in the logging.
        /// </summary>
        Baggage     = 0x0040
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/DefaultLoggerLevelConfigureOptions.cs
namespace Microsoft.Extensions.Logging
{
    internal sealed class DefaultLoggerLevelConfigureOptions : ConfigureOptions<LoggerFilterOptions>
    {
        public DefaultLoggerLevelConfigureOptions(LogLevel level) : base(options => options.MinLevel = level)
        {
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/FilterLoggingBuilderExtensions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Extension methods for setting up logging services in an <see cref="IServiceCollection" />.
    /// </summary>
    public static class FilterLoggingBuilderExtensions
    {
        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="filter">The filter to be added.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter(this ILoggingBuilder builder, Func<string?, string?, LogLevel, bool> filter) =>
            builder.ConfigureFilter(options => options.AddFilter(filter));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="categoryLevelFilter">The filter to be added.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter(this ILoggingBuilder builder, Func<string?, LogLevel, bool> categoryLevelFilter) =>
            builder.ConfigureFilter(options => options.AddFilter(categoryLevelFilter));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="categoryLevelFilter">The filter to be added.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter<T>(this ILoggingBuilder builder, Func<string?, LogLevel, bool> categoryLevelFilter) where T : ILoggerProvider =>
            builder.ConfigureFilter(options => options.AddFilter<T>(categoryLevelFilter));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="levelFilter">The filter to be added.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter(this ILoggingBuilder builder, Func<LogLevel, bool> levelFilter) =>
            builder.ConfigureFilter(options => options.AddFilter(levelFilter));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="levelFilter">The filter to be added.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter<T>(this ILoggingBuilder builder, Func<LogLevel, bool> levelFilter) where T : ILoggerProvider =>
            builder.ConfigureFilter(options => options.AddFilter<T>(levelFilter));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="level">The level to filter.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter(this ILoggingBuilder builder, string? category, LogLevel level) =>
            builder.ConfigureFilter(options => options.AddFilter(category, level));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="level">The level to filter.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter<T>(this ILoggingBuilder builder, string? category, LogLevel level) where T : ILoggerProvider =>
            builder.ConfigureFilter(options => options.AddFilter<T>(category, level));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter(this ILoggingBuilder builder, string? category, Func<LogLevel, bool> levelFilter) =>
            builder.ConfigureFilter(options => options.AddFilter(category, levelFilter));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddFilter<T>(this ILoggingBuilder builder, string? category, Func<LogLevel, bool> levelFilter) where T : ILoggerProvider =>
            builder.ConfigureFilter(options => options.AddFilter<T>(category, levelFilter));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="filter">The filter function to apply.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter(this LoggerFilterOptions builder, Func<string?, string?, LogLevel, bool> filter) =>
            AddRule(builder, filter: filter);

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="categoryLevelFilter">The filter function to apply.</param>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter(this LoggerFilterOptions builder, Func<string?, LogLevel, bool> categoryLevelFilter) =>
            AddRule(builder, filter: (type, name, level) => categoryLevelFilter(name, level));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="categoryLevelFilter">The filter function to apply.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter<T>(this LoggerFilterOptions builder, Func<string?, LogLevel, bool> categoryLevelFilter) where T : ILoggerProvider =>
            AddRule(builder, type: typeof(T).FullName, filter: (type, name, level) => categoryLevelFilter(name, level));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter(this LoggerFilterOptions builder, Func<LogLevel, bool> levelFilter) =>
            AddRule(builder, filter: (type, name, level) => levelFilter(level));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter<T>(this LoggerFilterOptions builder, Func<LogLevel, bool> levelFilter) where T : ILoggerProvider =>
            AddRule(builder, type: typeof(T).FullName, filter: (type, name, level) => levelFilter(level));

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="level">The level to filter.</param>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter(this LoggerFilterOptions builder, string? category, LogLevel level) =>
            AddRule(builder, category: category, level: level);

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="level">The level to filter.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter<T>(this LoggerFilterOptions builder, string? category, LogLevel level) where T : ILoggerProvider =>
            AddRule(builder, type: typeof(T).FullName, category: category, level: level);

        /// <summary>
        /// Adds a log filter to the factory.
        /// </summary>
        /// <param name="builder">The <see cref="LoggerFilterOptions"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <returns>The <see cref="LoggerFilterOptions"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter(this LoggerFilterOptions builder, string? category, Func<LogLevel, bool> levelFilter) =>
            AddRule(builder, category: category, filter: (type, name, level) => levelFilter(level));

        /// <summary>
        /// Adds a log filter for the given <see cref="ILoggerProvider"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the filter to.</param>
        /// <param name="category">The category to filter.</param>
        /// <param name="levelFilter">The filter function to apply.</param>
        /// <typeparam name="T">The <see cref="ILoggerProvider"/> which this filter will be added for.</typeparam>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static LoggerFilterOptions AddFilter<T>(this LoggerFilterOptions builder, string? category, Func<LogLevel, bool> levelFilter) where T : ILoggerProvider =>
            AddRule(builder, type: typeof(T).FullName, category: category, filter: (type, name, level) => levelFilter(level));

        private static ILoggingBuilder ConfigureFilter(this ILoggingBuilder builder, Action<LoggerFilterOptions> configureOptions)
        {
            builder.Services.Configure(configureOptions);
            return builder;
        }

        private static LoggerFilterOptions AddRule(LoggerFilterOptions options,
            string? type = null,
            string? category = null,
            LogLevel? level = null,
            Func<string?, string?, LogLevel, bool>? filter = null)
        {
            options.Rules.Add(new LoggerFilterRule(type, category, level, filter));
            return options;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/Logger.cs
namespace Microsoft.Extensions.Logging
{
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    [DebuggerTypeProxy(typeof(LoggerDebugView))]
    internal sealed class Logger : ILogger
    {
        private readonly string _categoryName;

        public Logger(string categoryName, LoggerInformation[] loggers)
        {
            _categoryName = categoryName;
            Loggers = loggers;
        }

        public LoggerInformation[] Loggers { get; set; }
        public MessageLogger[]? MessageLoggers { get; set; }
        public ScopeLogger[]? ScopeLoggers { get; set; }

        public void Log<TState>(LogLevel logLevel, EventId eventId, TState state, Exception? exception, Func<TState, Exception?, string> formatter)
        {
            MessageLogger[]? loggers = MessageLoggers;
            if (loggers == null)
            {
                return;
            }

            List<Exception>? exceptions = null;
            for (int i = 0; i < loggers.Length; i++)
            {
                ref readonly MessageLogger loggerInfo = ref loggers[i];
                if (!loggerInfo.IsEnabled(logLevel))
                {
                    continue;
                }

                LoggerLog(logLevel, eventId, loggerInfo.Logger, exception, formatter, ref exceptions, state);
            }

            if (exceptions != null && exceptions.Count > 0)
            {
                ThrowLoggingError(exceptions);
            }

            static void LoggerLog(LogLevel logLevel, EventId eventId, ILogger logger, Exception? exception, Func<TState, Exception?, string> formatter, ref List<Exception>? exceptions, in TState state)
            {
                try
                {
                    logger.Log(logLevel, eventId, state, exception, formatter);
                }
                catch (Exception ex)
                {
                    exceptions ??= new List<Exception>();
                    exceptions.Add(ex);
                }
            }
        }

        public bool IsEnabled(LogLevel logLevel)
        {
            MessageLogger[]? loggers = MessageLoggers;
            if (loggers == null)
            {
                return false;
            }

            List<Exception>? exceptions = null;
            int i = 0;
            for (; i < loggers.Length; i++)
            {
                ref readonly MessageLogger loggerInfo = ref loggers[i];
                if (!loggerInfo.IsEnabled(logLevel))
                {
                    continue;
                }

                if (LoggerIsEnabled(logLevel, loggerInfo.Logger, ref exceptions))
                {
                    break;
                }
            }

            if (exceptions != null && exceptions.Count > 0)
            {
                ThrowLoggingError(exceptions);
            }

            return i < loggers.Length ? true : false;

            static bool LoggerIsEnabled(LogLevel logLevel, ILogger logger, ref List<Exception>? exceptions)
            {
                try
                {
                    if (logger.IsEnabled(logLevel))
                    {
                        return true;
                    }
                }
                catch (Exception ex)
                {
                    exceptions ??= new List<Exception>();
                    exceptions.Add(ex);
                }

                return false;
            }
        }

        public IDisposable? BeginScope<TState>(TState state) where TState : notnull
        {
            ScopeLogger[]? loggers = ScopeLoggers;

            if (loggers == null)
            {
                return NullScope.Instance;
            }

            if (loggers.Length == 1)
            {
                return loggers[0].CreateScope(state);
            }

            var scope = new Scope(loggers.Length);
            List<Exception>? exceptions = null;
            for (int i = 0; i < loggers.Length; i++)
            {
                ref readonly ScopeLogger scopeLogger = ref loggers[i];

                try
                {
                    scope.SetDisposable(i, scopeLogger.CreateScope(state));
                }
                catch (Exception ex)
                {
                    exceptions ??= new List<Exception>();
                    exceptions.Add(ex);
                }
            }

            if (exceptions != null && exceptions.Count > 0)
            {
                ThrowLoggingError(exceptions);
            }

            return scope;
        }

        private static void ThrowLoggingError(List<Exception> exceptions)
        {
            throw new AggregateException(
                message: "An error occurred while writing to logger(s).", innerExceptions: exceptions);
        }

        internal string DebuggerToString()
        {
            return DebuggerDisplayFormatting.DebuggerToString(_categoryName, this);
        }

        private sealed class LoggerDebugView(Logger logger)
        {
            public string Name => logger._categoryName;

            // The list of providers includes the full list of configured providers from the logger factory.
            // It then mentions the min level and enable status of each provider for this logger.
            public List<LoggerProviderDebugView> Providers
            {
                get
                {
                    List<LoggerProviderDebugView> providers = new List<LoggerProviderDebugView>();
                    for (int i = 0; i < logger.Loggers.Length; i++)
                    {
                        LoggerInformation loggerInfo = logger.Loggers[i];
                        string providerName = ProviderAliasUtilities.GetAlias(loggerInfo.ProviderType) ?? loggerInfo.ProviderType.Name;
                        MessageLogger? messageLogger = logger.MessageLoggers?.FirstOrDefault(messageLogger => messageLogger.Logger == loggerInfo.Logger);

                        providers.Add(new LoggerProviderDebugView(providerName, messageLogger));
                    }

                    return providers;
                }
            }

            public List<object?>? Scopes
            {
                get
                {
                    var scopeProvider = logger.ScopeLoggers?.FirstOrDefault().ExternalScopeProvider;
                    if (scopeProvider == null)
                    {
                        return null;
                    }

                    List<object?> scopes = new List<object?>();
                    scopeProvider.ForEachScope((scope, scopes) => scopes!.Add(scope), scopes);
                    return scopes;
                }
            }
            public LogLevel? MinLevel => DebuggerDisplayFormatting.CalculateEnabledLogLevel(logger);
            public bool Enabled => DebuggerDisplayFormatting.CalculateEnabledLogLevel(logger) != null;
        }

        [DebuggerDisplay("{DebuggerToString(),nq}")]
        private sealed class LoggerProviderDebugView(string providerName, MessageLogger? messageLogger)
        {
            public string Name => providerName;
            public LogLevel LogLevel => CalculateEnabledLogLevel(messageLogger) ?? LogLevel.None;

            private static LogLevel? CalculateEnabledLogLevel(MessageLogger? logger)
            {
                if (logger == null)
                {
                    return null;
                }

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
                    if (!logger.Value.IsEnabled(logLevel))
                    {
                        break;
                    }

                    minimumLevel = logLevel;
                }

                return minimumLevel;
            }

            private string DebuggerToString()
            {
                return $@"Name = ""{providerName}"", LogLevel = {LogLevel}";
            }
        }

        private sealed class Scope : IDisposable
        {
            private bool _isDisposed;

            private IDisposable? _disposable0;
            private IDisposable? _disposable1;
            private readonly IDisposable?[]? _disposable;

            public Scope(int count)
            {
                if (count > 2)
                {
                    _disposable = new IDisposable[count - 2];
                }
            }

            public void SetDisposable(int index, IDisposable? disposable)
            {
                switch (index)
                {
                    case 0:
                        _disposable0 = disposable;
                        break;
                    case 1:
                        _disposable1 = disposable;
                        break;
                    default:
                        _disposable![index - 2] = disposable;
                        break;
                }
            }

            public void Dispose()
            {
                if (!_isDisposed)
                {
                    _disposable0?.Dispose();
                    _disposable1?.Dispose();

                    if (_disposable != null)
                    {
                        int count = _disposable.Length;
                        for (int index = 0; index != count; ++index)
                        {
                            _disposable[index]?.Dispose();
                        }
                    }

                    _isDisposed = true;
                }
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerFactory.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Produces instances of <see cref="ILogger"/> classes based on the given providers.
    /// </summary>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    [DebuggerTypeProxy(typeof(LoggerFactoryDebugView))]
    public class LoggerFactory : ILoggerFactory
    {
        private readonly ConcurrentDictionary<string, Logger> _loggers = new ConcurrentDictionary<string, Logger>(StringComparer.Ordinal);
        private readonly List<ProviderRegistration> _providerRegistrations = new List<ProviderRegistration>();
        private readonly object _sync = new object();
        private volatile bool _disposed;
        private readonly IDisposable? _changeTokenRegistration;
        private LoggerFilterOptions _filterOptions;
        private IExternalScopeProvider? _scopeProvider;
        private readonly LoggerFactoryOptions _factoryOptions;

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        public LoggerFactory() : this(Array.Empty<ILoggerProvider>())
        {
        }

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        /// <param name="providers">The providers to use in producing <see cref="ILogger"/> instances.</param>
        public LoggerFactory(IEnumerable<ILoggerProvider> providers) : this(providers, new StaticFilterOptionsMonitor(new LoggerFilterOptions()))
        {
        }

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        /// <param name="providers">The providers to use in producing <see cref="ILogger"/> instances.</param>
        /// <param name="filterOptions">The filter options to use.</param>
        public LoggerFactory(IEnumerable<ILoggerProvider> providers, LoggerFilterOptions filterOptions) : this(providers, new StaticFilterOptionsMonitor(filterOptions))
        {
        }

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        /// <param name="providers">The providers to use in producing <see cref="ILogger"/> instances.</param>
        /// <param name="filterOption">The filter option to use.</param>
        public LoggerFactory(IEnumerable<ILoggerProvider> providers, IOptionsMonitor<LoggerFilterOptions> filterOption) : this(providers, filterOption, null)
        {
        }

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        /// <param name="providers">The providers to use in producing <see cref="ILogger"/> instances.</param>
        /// <param name="filterOption">The filter option to use.</param>
        /// <param name="options">The <see cref="LoggerFactoryOptions"/>.</param>
        public LoggerFactory(IEnumerable<ILoggerProvider> providers, IOptionsMonitor<LoggerFilterOptions> filterOption, IOptions<LoggerFactoryOptions>? options) : this(providers, filterOption, options, null)
        {
        }

        /// <summary>
        /// Creates a new <see cref="LoggerFactory"/> instance.
        /// </summary>
        /// <param name="providers">The providers to use in producing <see cref="ILogger"/> instances.</param>
        /// <param name="filterOption">The filter option to use.</param>
        /// <param name="options">The <see cref="LoggerFactoryOptions"/>.</param>
        /// <param name="scopeProvider">The <see cref="IExternalScopeProvider"/>.</param>
        public LoggerFactory(IEnumerable<ILoggerProvider> providers, IOptionsMonitor<LoggerFilterOptions> filterOption, IOptions<LoggerFactoryOptions>? options = null, IExternalScopeProvider? scopeProvider = null)
        {
            _scopeProvider = scopeProvider;

            _factoryOptions = options == null || options.Value == null ? new LoggerFactoryOptions() : options.Value;

            const ActivityTrackingOptions ActivityTrackingOptionsMask = ~(ActivityTrackingOptions.SpanId | ActivityTrackingOptions.TraceId | ActivityTrackingOptions.ParentId |
                                                                          ActivityTrackingOptions.TraceFlags | ActivityTrackingOptions.TraceState | ActivityTrackingOptions.Tags
                                                                          | ActivityTrackingOptions.Baggage);


            if ((_factoryOptions.ActivityTrackingOptions & ActivityTrackingOptionsMask) != 0)
            {
                throw new ArgumentException(SR.Format(SR.InvalidActivityTrackingOptions, _factoryOptions.ActivityTrackingOptions), nameof(options));
            }

            foreach (ILoggerProvider provider in providers)
            {
                AddProviderRegistration(provider, dispose: false);
            }

            _changeTokenRegistration = filterOption.OnChange(RefreshFilters);
            RefreshFilters(filterOption.CurrentValue);
        }

        /// <summary>
        /// Creates new instance of <see cref="ILoggerFactory"/> configured using provided <paramref name="configure"/> delegate.
        /// </summary>
        /// <param name="configure">A delegate to configure the <see cref="ILoggingBuilder"/>.</param>
        /// <returns>The <see cref="ILoggerFactory"/> that was created.</returns>
        public static ILoggerFactory Create(Action<ILoggingBuilder> configure)
        {
            var serviceCollection = new ServiceCollection();
            serviceCollection.AddLogging(configure);
            ServiceProvider serviceProvider = serviceCollection.BuildServiceProvider();
            ILoggerFactory loggerFactory = serviceProvider.GetRequiredService<ILoggerFactory>();
            return new DisposingLoggerFactory(loggerFactory, serviceProvider);
        }

        [MemberNotNull(nameof(_filterOptions))]
        private void RefreshFilters(LoggerFilterOptions filterOptions)
        {
            lock (_sync)
            {
                _filterOptions = filterOptions;
                foreach (KeyValuePair<string, Logger> registeredLogger in _loggers)
                {
                    Logger logger = registeredLogger.Value;
                    (logger.MessageLoggers, logger.ScopeLoggers) = ApplyFilters(logger.Loggers);
                }
            }
        }

        /// <summary>
        /// Creates an <see cref="ILogger"/> with the given <paramref name="categoryName"/>.
        /// </summary>
        /// <param name="categoryName">The category name for messages produced by the logger.</param>
        /// <returns>The <see cref="ILogger"/> that was created.</returns>
        public ILogger CreateLogger(string categoryName)
        {
            if (CheckDisposed())
            {
                throw new ObjectDisposedException(nameof(LoggerFactory));
            }

            if (!_loggers.TryGetValue(categoryName, out Logger? logger))
            {
                lock (_sync)
                {
                    if (!_loggers.TryGetValue(categoryName, out logger))
                    {
                        logger = new Logger(categoryName, CreateLoggers(categoryName));

                        (logger.MessageLoggers, logger.ScopeLoggers) = ApplyFilters(logger.Loggers);

                        _loggers[categoryName] = logger;
                    }
                }
            }

            return logger;
        }

        /// <summary>
        /// Adds the given provider to those used in creating <see cref="ILogger"/> instances.
        /// </summary>
        /// <param name="provider">The <see cref="ILoggerProvider"/> to add.</param>
        public void AddProvider(ILoggerProvider provider)
        {
            if (CheckDisposed())
            {
                throw new ObjectDisposedException(nameof(LoggerFactory));
            }

            ThrowHelper.ThrowIfNull(provider);

            lock (_sync)
            {
                AddProviderRegistration(provider, dispose: true);

                foreach (KeyValuePair<string, Logger> existingLogger in _loggers)
                {
                    Logger logger = existingLogger.Value;
                    LoggerInformation[] loggerInformation = logger.Loggers;

                    int newLoggerIndex = loggerInformation.Length;
                    Array.Resize(ref loggerInformation, loggerInformation.Length + 1);
                    loggerInformation[newLoggerIndex] = new LoggerInformation(provider, existingLogger.Key);

                    logger.Loggers = loggerInformation;
                    (logger.MessageLoggers, logger.ScopeLoggers) = ApplyFilters(logger.Loggers);
                }
            }
        }

        private void AddProviderRegistration(ILoggerProvider provider, bool dispose)
        {
            _providerRegistrations.Add(new ProviderRegistration
            {
                Provider = provider,
                ShouldDispose = dispose
            });

            if (provider is ISupportExternalScope supportsExternalScope)
            {
                _scopeProvider ??= new LoggerFactoryScopeProvider(_factoryOptions.ActivityTrackingOptions);

                supportsExternalScope.SetScopeProvider(_scopeProvider);
            }
        }

        private LoggerInformation[] CreateLoggers(string categoryName)
        {
            var loggers = new LoggerInformation[_providerRegistrations.Count];
            for (int i = 0; i < _providerRegistrations.Count; i++)
            {
                loggers[i] = new LoggerInformation(_providerRegistrations[i].Provider, categoryName);
            }
            return loggers;
        }

        private (MessageLogger[] MessageLoggers, ScopeLogger[]? ScopeLoggers) ApplyFilters(LoggerInformation[] loggers)
        {
            var messageLoggers = new List<MessageLogger>();
            List<ScopeLogger>? scopeLoggers = _filterOptions.CaptureScopes ? new List<ScopeLogger>() : null;

            foreach (LoggerInformation loggerInformation in loggers)
            {
                LoggerRuleSelector.Select(_filterOptions,
                    loggerInformation.ProviderType,
                    loggerInformation.Category,
                    out LogLevel? minLevel,
                    out Func<string?, string?, LogLevel, bool>? filter);

                if (minLevel is not null and > LogLevel.Critical)
                {
                    continue;
                }

                messageLoggers.Add(new MessageLogger(loggerInformation.Logger, loggerInformation.Category, loggerInformation.ProviderType.FullName, minLevel, filter));

                if (!loggerInformation.ExternalScope)
                {
                    scopeLoggers?.Add(new ScopeLogger(logger: loggerInformation.Logger, externalScopeProvider: null));
                }
            }

            if (_scopeProvider != null)
            {
                scopeLoggers?.Add(new ScopeLogger(logger: null, externalScopeProvider: _scopeProvider));
            }

            return (messageLoggers.ToArray(), scopeLoggers?.ToArray());
        }

        /// <summary>
        /// Check if the factory has been disposed.
        /// </summary>
        /// <returns>True when <see cref="Dispose()"/> as been called</returns>
        protected virtual bool CheckDisposed() => _disposed;

        /// <inheritdoc/>
        public void Dispose()
        {
            if (!_disposed)
            {
                _disposed = true;

                _changeTokenRegistration?.Dispose();

                foreach (ProviderRegistration registration in _providerRegistrations)
                {
                    try
                    {
                        if (registration.ShouldDispose)
                        {
                            registration.Provider.Dispose();
                        }
                    }
                    catch
                    {
                        // Swallow exceptions on dispose
                    }
                }
            }
        }

        private struct ProviderRegistration
        {
            public ILoggerProvider Provider;
            public bool ShouldDispose;
        }

        private sealed class DisposingLoggerFactory : ILoggerFactory
        {
            private readonly ILoggerFactory _loggerFactory;

            private readonly ServiceProvider _serviceProvider;

            public DisposingLoggerFactory(ILoggerFactory loggerFactory, ServiceProvider serviceProvider)
            {
                _loggerFactory = loggerFactory;
                _serviceProvider = serviceProvider;
            }

            public void Dispose()
            {
                _serviceProvider.Dispose();
            }

            public ILogger CreateLogger(string categoryName)
            {
                return _loggerFactory.CreateLogger(categoryName);
            }

            public void AddProvider(ILoggerProvider provider)
            {
                _loggerFactory.AddProvider(provider);
            }
        }

        private string DebuggerToString()
        {
            return $"Providers = {_providerRegistrations.Count}, {_filterOptions.DebuggerToString()}";
        }

        private sealed class LoggerFactoryDebugView(LoggerFactory loggerFactory)
        {
            public List<ILoggerProvider> Providers => loggerFactory._providerRegistrations.Select(r => r.Provider).ToList();
            public bool Disposed => loggerFactory._disposed;
            public LoggerFilterOptions FilterOptions => loggerFactory._filterOptions;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerFactoryOptions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// The options for a LoggerFactory.
    /// </summary>
    [DebuggerDisplay("ActivityTrackingOptions = {ActivityTrackingOptions}")]
    public class LoggerFactoryOptions
    {
        /// <summary>
        /// Creates a new <see cref="LoggerFactoryOptions"/> instance.
        /// </summary>
        public LoggerFactoryOptions() { }

        /// <summary>
        /// Gets or sets <see cref="LoggerFactoryOptions"/> value to indicate which parts of the tracing context information should be included with the logging scopes.
        /// </summary>
        public ActivityTrackingOptions ActivityTrackingOptions { get; set; }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerFactoryScopeProvider.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Default implementation of <see cref="IExternalScopeProvider"/>
    /// </summary>
    internal sealed class LoggerFactoryScopeProvider : IExternalScopeProvider
    {
        private readonly AsyncLocal<Scope?> _currentScope = new AsyncLocal<Scope?>();
        private readonly ActivityTrackingOptions _activityTrackingOption;

        public LoggerFactoryScopeProvider(ActivityTrackingOptions activityTrackingOption) => _activityTrackingOption = activityTrackingOption;

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

            if (_activityTrackingOption != ActivityTrackingOptions.None)
            {
                Activity? activity = Activity.Current;
                if (activity != null)
                {
                    const string propertyKey = "__ActivityLogScope__";

                    ActivityLogScope? activityLogScope = activity.GetCustomProperty(propertyKey) as ActivityLogScope;
                    if (activityLogScope == null)
                    {
                        activityLogScope = new ActivityLogScope(activity, _activityTrackingOption);
                        activity.SetCustomProperty(propertyKey, activityLogScope);
                    }

                    callback(activityLogScope, state);

                    // Tags and baggage are opt-in and thus we assume that most of the time it will not be used.
                    if ((_activityTrackingOption & ActivityTrackingOptions.Tags) != 0
                        && activity.TagObjects.GetEnumerator().MoveNext())
                    {
                        // As TagObjects is a IEnumerable<KeyValuePair<string, object?>> this can be used directly as a scope.
                        // We do this to safe the allocation of a wrapper object.
                        callback(activity.TagObjects, state);
                    }

                    if ((_activityTrackingOption & ActivityTrackingOptions.Baggage) != 0)
                    {
                        // Only access activity.Baggage as every call leads to an allocation
                        IEnumerable<KeyValuePair<string, string?>> baggage = activity.Baggage;
                        if (baggage.GetEnumerator().MoveNext())
                        {
                            // For the baggage a wrapper object is necessary because we need to be able to overwrite ToString().
                            // In contrast to the TagsObject, Baggage doesn't have one underlining type where we can do this overwrite.
                            ActivityBaggageLogScopeWrapper scope = GetOrCreateActivityBaggageLogScopeWrapper(activity, baggage);
                            callback(scope, state);
                        }
                    }
                }
            }

            Report(_currentScope.Value);
        }

        private static ActivityBaggageLogScopeWrapper GetOrCreateActivityBaggageLogScopeWrapper(Activity activity, IEnumerable<KeyValuePair<string, string?>> items)
        {
            const string additionalItemsBaggagePropertyKey = "__ActivityBaggageItemsLogScope__";
            var activityBaggageLogScopeWrapper = activity.GetCustomProperty(additionalItemsBaggagePropertyKey) as ActivityBaggageLogScopeWrapper;
            if (activityBaggageLogScopeWrapper == null)
            {
                activityBaggageLogScopeWrapper = new ActivityBaggageLogScopeWrapper(items);
                activity.SetCustomProperty(additionalItemsBaggagePropertyKey, activityBaggageLogScopeWrapper);
            }

            return activityBaggageLogScopeWrapper;
        }

        public IDisposable Push(object? state)
        {
            Scope? parent = _currentScope.Value;
            var newScope = new Scope(this, state, parent);
            _currentScope.Value = newScope;

            return newScope;
        }

        private sealed class Scope : IDisposable
        {
            private readonly LoggerFactoryScopeProvider _provider;
            private bool _isDisposed;

            internal Scope(LoggerFactoryScopeProvider provider, object? state, Scope? parent)
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

        private sealed class ActivityLogScope : IReadOnlyList<KeyValuePair<string, object?>>
        {
            private string? _cachedToString;
            private const int MaxItems = 5;
            private readonly KeyValuePair<string, object?>[] _items = new KeyValuePair<string, object?>[MaxItems];

            public ActivityLogScope(Activity activity, ActivityTrackingOptions activityTrackingOption)
            {
                Debug.Assert(activity != null);
                Debug.Assert(activityTrackingOption != ActivityTrackingOptions.None);

                int count = 0;
                if ((activityTrackingOption & ActivityTrackingOptions.SpanId) != 0)
                {
                    _items[count++] = new KeyValuePair<string, object?>("SpanId", activity.GetSpanId());
                }

                if ((activityTrackingOption & ActivityTrackingOptions.TraceId) != 0)
                {
                    _items[count++] = new KeyValuePair<string, object?>("TraceId", activity.GetTraceId());
                }

                if ((activityTrackingOption & ActivityTrackingOptions.ParentId) != 0)
                {
                    _items[count++] = new KeyValuePair<string, object?>("ParentId", activity.GetParentId());
                }

                if ((activityTrackingOption & ActivityTrackingOptions.TraceState) != 0)
                {
                    _items[count++] = new KeyValuePair<string, object?>("TraceState", activity.TraceStateString);
                }

                if ((activityTrackingOption & ActivityTrackingOptions.TraceFlags) != 0)
                {
                    _items[count++] = new KeyValuePair<string, object?>("TraceFlags", activity.ActivityTraceFlags);
                }

                Count = count;
            }

            public int Count { get; }

            public KeyValuePair<string, object?> this[int index]
            {
                get
                {
                    if (index >= Count)
                    {
                        throw new ArgumentOutOfRangeException(nameof(index));
                    }

                    return _items[index];
                }
            }

            public override string ToString()
            {
                if (_cachedToString == null)
                {
                    StringBuilder sb = new StringBuilder();

                    sb.Append(_items[0].Key);
                    sb.Append(':');
                    sb.Append(_items[0].Value);

                    for (int i = 1; i < Count; i++)
                    {
                        sb.Append(", ");
                        sb.Append(_items[i].Key);
                        sb.Append(':');
                        sb.Append(_items[i].Value);
                    }
                    _cachedToString = sb.ToString();
                }

                return _cachedToString;
            }

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

        private sealed class ActivityBaggageLogScopeWrapper : IEnumerable<KeyValuePair<string, object?>>
        {
            private readonly IEnumerable<KeyValuePair<string, string?>> _items;

            private StringBuilder? _stringBuilder;

            public ActivityBaggageLogScopeWrapper(IEnumerable<KeyValuePair<string, string?>> items)
            {
                _items = items;
            }

            public IEnumerator<KeyValuePair<string, object?>> GetEnumerator() => new BaggageEnumerator(_items.GetEnumerator());

            IEnumerator IEnumerable.GetEnumerator() => new BaggageEnumerator(_items.GetEnumerator());

            public override string ToString()
            {
                lock (this)
                {
                    IEnumerator<KeyValuePair<string, string?>> enumerator = _items.GetEnumerator();
                    if (!enumerator.MoveNext())
                    {
                        return string.Empty;
                    }

                    _stringBuilder ??= new StringBuilder();
                    _stringBuilder.Append(enumerator.Current.Key);
                    _stringBuilder.Append(':');
                    _stringBuilder.Append(enumerator.Current.Value);

                    while (enumerator.MoveNext())
                    {
                        _stringBuilder.Append(", ");
                        _stringBuilder.Append(enumerator.Current.Key);
                        _stringBuilder.Append(':');
                        _stringBuilder.Append(enumerator.Current.Value);
                    }

                    string result = _stringBuilder.ToString();
                    _stringBuilder.Clear();
                    return result;
                }
            }

            private struct BaggageEnumerator : IEnumerator<KeyValuePair<string, object?>>
            {
                private readonly IEnumerator<KeyValuePair<string, string?>> _enumerator;

                public BaggageEnumerator(IEnumerator<KeyValuePair<string, string?>> enumerator)
                {
                    _enumerator = enumerator;
                }

                public KeyValuePair<string, object?> Current => new KeyValuePair<string, object?>(_enumerator.Current.Key, _enumerator.Current.Value);

                object? IEnumerator.Current => Current;

                public void Dispose() => _enumerator.Dispose();

                public bool MoveNext() => _enumerator.MoveNext();

                public void Reset() => _enumerator.Reset();
            }
        }
    }

    internal static class ActivityExtensions
    {
        public static string GetSpanId(this Activity activity)
        {
            return activity.IdFormat switch
            {
                ActivityIdFormat.Hierarchical => activity.Id,
                ActivityIdFormat.W3C => activity.SpanId.ToHexString(),
                _ => null,
            } ?? string.Empty;
        }

        public static string GetTraceId(this Activity activity)
        {
            return activity.IdFormat switch
            {
                ActivityIdFormat.Hierarchical => activity.RootId,
                ActivityIdFormat.W3C => activity.TraceId.ToHexString(),
                _ => null,
            } ?? string.Empty;
        }

        public static string GetParentId(this Activity activity)
        {
            return activity.IdFormat switch
            {
                ActivityIdFormat.Hierarchical => activity.ParentId,
                ActivityIdFormat.W3C => activity.ParentSpanId.ToHexString(),
                _ => null,
            } ?? string.Empty;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerFilterOptions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// The options for a LoggerFilter.
    /// </summary>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    public class LoggerFilterOptions
    {
        /// <summary>
        /// Creates a new <see cref="LoggerFilterOptions"/> instance.
        /// </summary>
        public LoggerFilterOptions() { }

        /// <summary>
        /// Gets or sets value indicating whether logging scopes are being captured. Defaults to <c>true</c>
        /// </summary>
        public bool CaptureScopes { get; set; } = true;

        /// <summary>
        /// Gets or sets the minimum level of log messages if none of the rules match.
        /// </summary>
        public LogLevel MinLevel { get; set; }

        /// <summary>
        /// Gets the collection of <see cref="LoggerFilterRule"/> used for filtering log messages.
        /// </summary>
        public IList<LoggerFilterRule> Rules => RulesInternal;

        // Concrete representation of the rule list
        internal List<LoggerFilterRule> RulesInternal { get; } = new List<LoggerFilterRule>();

        internal string DebuggerToString()
        {
            string debugText;
            if (MinLevel != LogLevel.None)
            {
                debugText = $"MinLevel = {MinLevel}";
            }
            else
            {
                // Display "Enabled = false". This makes it clear that the entire ILogger
                // is disabled and nothing is written.
                //
                // If "MinLevel = None" was displayed then someone could think that the
                // min level is disabled and everything is written.
                debugText = $"Enabled = false";
            }

            if (Rules.Count > 0)
            {
                debugText += $", Rules = {Rules.Count}";
            }

            return debugText;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerFilterRule.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Defines a rule used to filter log messages
    /// </summary>
    public class LoggerFilterRule
    {
        /// <summary>
        /// Creates a new <see cref="LoggerFilterRule"/> instance.
        /// </summary>
        /// <param name="providerName">The provider name to use in this filter rule.</param>
        /// <param name="categoryName">The category name to use in this filter rule.</param>
        /// <param name="logLevel">The <see cref="LogLevel"/> to use in this filter rule.</param>
        /// <param name="filter">The filter to apply.</param>
        public LoggerFilterRule(string? providerName, string? categoryName, LogLevel? logLevel, Func<string?, string?, LogLevel, bool>? filter)
        {
            ProviderName = providerName;
            CategoryName = categoryName;
            LogLevel = logLevel;
            Filter = filter;
        }

        /// <summary>
        /// Gets the logger provider type or alias this rule applies to.
        /// </summary>
        public string? ProviderName { get; }

        /// <summary>
        /// Gets the logger category this rule applies to.
        /// </summary>
        public string? CategoryName { get; }

        /// <summary>
        /// Gets the minimum <see cref="LogLevel"/> of messages.
        /// </summary>
        public LogLevel? LogLevel { get; }

        /// <summary>
        /// Gets the filter delegate that would be applied to messages that passed the <see cref="LogLevel"/>.
        /// </summary>
        public Func<string?, string?, LogLevel, bool>? Filter { get; }

        /// <inheritdoc/>
        public override string ToString()
        {
            return $"{nameof(ProviderName)}: '{ProviderName}', {nameof(CategoryName)}: '{CategoryName}', {nameof(LogLevel)}: '{LogLevel}', {nameof(Filter)}: '{Filter}'";
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerInformation.cs
namespace Microsoft.Extensions.Logging
{
    internal readonly struct MessageLogger
    {
        public MessageLogger(ILogger logger, string category, string? providerTypeFullName, LogLevel? minLevel, Func<string?, string?, LogLevel, bool>? filter)
        {
            Logger = logger;
            Category = category;
            ProviderTypeFullName = providerTypeFullName;
            MinLevel = minLevel;
            Filter = filter;
        }

        public ILogger Logger { get; }

        public string Category { get; }

        private string? ProviderTypeFullName { get; }

        public LogLevel? MinLevel { get; }

        public Func<string?, string?, LogLevel, bool>? Filter { get; }

        public bool IsEnabled(LogLevel level)
        {
            if (MinLevel != null && level < MinLevel)
            {
                return false;
            }

            if (Filter != null)
            {
                return Filter(ProviderTypeFullName, Category, level);
            }

            return true;
        }
    }

    internal readonly struct ScopeLogger
    {
        public ScopeLogger(ILogger? logger, IExternalScopeProvider? externalScopeProvider)
        {
            Debug.Assert(logger != null || externalScopeProvider != null, "Logger can't be null when there isn't an ExternalScopeProvider");

            Logger = logger;
            ExternalScopeProvider = externalScopeProvider;
        }

        public ILogger? Logger { get; }

        public IExternalScopeProvider? ExternalScopeProvider { get; }

        public IDisposable? CreateScope<TState>(TState state) where TState : notnull
        {
            if (ExternalScopeProvider != null)
            {
                return ExternalScopeProvider.Push(state);
            }

            Debug.Assert(Logger != null);
            return Logger.BeginScope<TState>(state);
        }
    }

    internal readonly struct LoggerInformation
    {
        public LoggerInformation(ILoggerProvider provider, string category) : this()
        {
            ProviderType = provider.GetType();
            Logger = provider.CreateLogger(category);
            Category = category;
            ExternalScope = provider is ISupportExternalScope;
        }

        public ILogger Logger { get; }

        public string Category { get; }

        public Type ProviderType { get; }

        public bool ExternalScope { get; }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggerRuleSelector.cs
namespace Microsoft.Extensions.Logging
{
    internal static class LoggerRuleSelector
    {
        public static void Select(LoggerFilterOptions options, Type providerType, string category, out LogLevel? minLevel, out Func<string?, string?, LogLevel, bool>? filter)
        {
            filter = null;
            minLevel = options.MinLevel;

            // Filter rule selection:
            // 1. Select rules for current logger type, if there is none, select ones without logger type specified
            // 2. Select rules with longest matching categories
            // 3. If there nothing matched by category take all rules without category
            // 3. If there is only one rule use it's level and filter
            // 4. If there are multiple rules use last
            // 5. If there are no applicable rules use global minimal level

            string? providerAlias = ProviderAliasUtilities.GetAlias(providerType);
            LoggerFilterRule? current = null;
            foreach (LoggerFilterRule rule in options.RulesInternal)
            {
                if (IsBetter(rule, current, providerType.FullName, category)
                    || (!string.IsNullOrEmpty(providerAlias) && IsBetter(rule, current, providerAlias, category)))
                {
                    current = rule;
                }
            }

            if (current != null)
            {
                filter = current.Filter;
                minLevel = current.LogLevel;
            }
        }

        private static bool IsBetter(LoggerFilterRule rule, LoggerFilterRule? current, string? logger, string category)
        {
            // Skip rules with inapplicable type or category
            if (rule.ProviderName != null && rule.ProviderName != logger)
            {
                return false;
            }

            string? categoryName = rule.CategoryName;
            if (categoryName != null)
            {
                const char WildcardChar = '*';

                int wildcardIndex = categoryName.IndexOf(WildcardChar);
                if (wildcardIndex != -1 &&
                    categoryName.IndexOf(WildcardChar, wildcardIndex + 1) != -1)
                {
                    throw new InvalidOperationException(SR.MoreThanOneWildcard);
                }

                ReadOnlySpan<char> prefix, suffix;
                if (wildcardIndex == -1)
                {
                    prefix = categoryName.AsSpan();
                    suffix = default;
                }
                else
                {
                    prefix = categoryName.AsSpan(0, wildcardIndex);
                    suffix = categoryName.AsSpan(wildcardIndex + 1);
                }

                if (!category.AsSpan().StartsWith(prefix, StringComparison.OrdinalIgnoreCase) ||
                    !category.AsSpan().EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
                {
                    return false;
                }
            }

            if (current?.ProviderName != null)
            {
                if (rule.ProviderName == null)
                {
                    return false;
                }
            }
            else
            {
                // We want to skip category check when going from no provider to having provider
                if (rule.ProviderName != null)
                {
                    return true;
                }
            }

            if (current?.CategoryName != null)
            {
                if (rule.CategoryName == null)
                {
                    return false;
                }

                if (current.CategoryName.Length > rule.CategoryName.Length)
                {
                    return false;
                }
            }

            return true;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggingBuilder.cs
namespace Microsoft.Extensions.Logging
{
    internal sealed class LoggingBuilder : ILoggingBuilder
    {
        public LoggingBuilder(IServiceCollection services)
        {
            Services = services;
        }

        public IServiceCollection Services { get; }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggingBuilderExtensions.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Extension methods for setting up logging services in an <see cref="ILoggingBuilder" />.
    /// </summary>
    public static class LoggingBuilderExtensions
    {
        /// <summary>
        /// Sets a minimum <see cref="LogLevel"/> requirement for log messages to be logged.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to set the minimum level on.</param>
        /// <param name="level">The <see cref="LogLevel"/> to set as the minimum.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder SetMinimumLevel(this ILoggingBuilder builder, LogLevel level)
        {
            builder.Services.Add(ServiceDescriptor.Singleton<IConfigureOptions<LoggerFilterOptions>>(
                new DefaultLoggerLevelConfigureOptions(level)));
            return builder;
        }

        /// <summary>
        /// Adds the given <see cref="ILoggerProvider"/> to the <see cref="ILoggingBuilder"/>
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to add the <paramref name="provider"/> to.</param>
        /// <param name="provider">The <see cref="ILoggerProvider"/> to add to the <paramref name="builder"/>.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder AddProvider(this ILoggingBuilder builder, ILoggerProvider provider)
        {
            builder.Services.AddSingleton(provider);
            return builder;
        }

        /// <summary>
        /// Removes all <see cref="ILoggerProvider"/>s from <paramref name="builder"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to remove <see cref="ILoggerProvider"/>s from.</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder ClearProviders(this ILoggingBuilder builder)
        {
            builder.Services.RemoveAll<ILoggerProvider>();
            return builder;
        }

        /// <summary>
        /// Configure the <paramref name="builder"/> with the <see cref="LoggerFactoryOptions"/>.
        /// </summary>
        /// <param name="builder">The <see cref="ILoggingBuilder"/> to be configured with <see cref="LoggerFactoryOptions"/></param>
        /// <param name="action">The action used to configure the logger factory</param>
        /// <returns>The <see cref="ILoggingBuilder"/> so that additional calls can be chained.</returns>
        public static ILoggingBuilder Configure(this ILoggingBuilder builder, Action<LoggerFactoryOptions> action)
        {
            builder.Services.Configure(action);
            return builder;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/LoggingServiceCollectionExtensions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for setting up logging services in an <see cref="IServiceCollection" />.
    /// </summary>
    public static class LoggingServiceCollectionExtensions
    {
        /// <summary>
        /// Adds logging services to the specified <see cref="IServiceCollection" />.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection" /> to add services to.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection AddLogging(this IServiceCollection services)
        {
            return AddLogging(services, builder => { });
        }

        /// <summary>
        /// Adds logging services to the specified <see cref="IServiceCollection" />.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection" /> to add services to.</param>
        /// <param name="configure">The <see cref="ILoggingBuilder"/> configuration delegate.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection AddLogging(this IServiceCollection services, Action<ILoggingBuilder> configure)
        {
            ThrowHelper.ThrowIfNull(services);

            services.AddOptions();

            services.TryAdd(ServiceDescriptor.Singleton<ILoggerFactory, LoggerFactory>());
            services.TryAdd(ServiceDescriptor.Singleton(typeof(ILogger<>), typeof(Logger<>)));

            services.TryAddEnumerable(ServiceDescriptor.Singleton<IConfigureOptions<LoggerFilterOptions>>(
                new DefaultLoggerLevelConfigureOptions(LogLevel.Information)));

            configure(new LoggingBuilder(services));
            return services;
        }
    }
}

// src/libraries/Microsoft.Extensions.Logging/src/ProviderAliasAttribute.cs
namespace Microsoft.Extensions.Logging
{
    /// <summary>
    /// Defines alias for <see cref="ILoggerProvider"/> implementation to be used in filtering rules.
    /// </summary>
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false, Inherited = false)]
    public class ProviderAliasAttribute : Attribute
    {
        /// <summary>
        /// Creates a new <see cref="ProviderAliasAttribute"/> instance.
        /// </summary>
        /// <param name="alias">The alias to set.</param>
        public ProviderAliasAttribute(string alias)
        {
            Alias = alias;
        }

        /// <summary>
        /// The alias of the provider.
        /// </summary>
        public string Alias { get; }

    }
}

// src/libraries/Microsoft.Extensions.Logging/src/StaticFilterOptionsMonitor.cs
namespace Microsoft.Extensions.Logging
{
    internal sealed class StaticFilterOptionsMonitor : IOptionsMonitor<LoggerFilterOptions>
    {
        public StaticFilterOptionsMonitor(LoggerFilterOptions currentValue)
        {
            CurrentValue = currentValue ?? throw new ArgumentNullException(nameof(currentValue));
        }

        public IDisposable? OnChange(Action<LoggerFilterOptions, string> listener) => null;

        public LoggerFilterOptions Get(string? name) => CurrentValue;

        public LoggerFilterOptions CurrentValue { get; }
    }
}

#nullable disable

namespace FxResources.Microsoft.Extensions.Logging
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
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.Logging.SR));

        internal static string InvalidActivityTrackingOptions => GetResourceString("InvalidActivityTrackingOptions");
        internal static string MoreThanOneWildcard => GetResourceString("MoreThanOneWildcard");
    }
}
