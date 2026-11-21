// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// Source files combined from dotnet/runtime at 5535e31a712343a63f5d7d796cd874e563e5ac14.
#define NET
#define NETCOREAPP
#define NETCOREAPP3_0_OR_GREATER
#define NETCOREAPP3_1_OR_GREATER
#nullable enable annotations

using Microsoft.Extensions.DependencyInjection.Extensions;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Options;
using Microsoft.Extensions.Primitives;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: InternalsVisibleTo("Microsoft.Extensions.Options.Tests, PublicKey=0024000004800000940000000602000000240000525341310004000001000100f33a29044fa9d740c9b3213a93e57c84b472c84e0b8a0e1ae48e67a9f8f6de9d5f7f3d52ac23e48ac51801f1dc950abe901da34d2a9e3baadb141a17c77ef3c565dd5ee5054b91cf63bb3c6ab83f72ab3aafe93d0fc3c2348b764fafb0b1c0733de51459aeab46580384bf9d74c4e28164b7cde247f891ba07891c9d872ad2bb")]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.Options")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Provides a strongly typed way of specifying and accessing settings using dependency injection.")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.Options")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    public class ConfigureNamedOptions<TOptions> : IConfigureNamedOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, Action<TOptions>? action)
        {
            Name = name;
            Action = action;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions>? Action { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep">Dependency type.</typeparam>
    public class ConfigureNamedOptions<TOptions, TDep> : IConfigureNamedOptions<TOptions>
        where TOptions : class
        where TDep : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, TDep dependency, Action<TOptions, TDep>? action)
        {
            Name = name;
            Action = action;
            Dependency = dependency;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep>? Action { get; }

        /// <summary>
        /// The dependency.
        /// </summary>
        public TDep Dependency { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    public class ConfigureNamedOptions<TOptions, TDep1, TDep2> : IConfigureNamedOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, TDep1 dependency, TDep2 dependency2, Action<TOptions, TDep1, TDep2>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency;
            Dependency2 = dependency2;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    public class ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3> : IConfigureNamedOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, TDep1 dependency, TDep2 dependency2, TDep3 dependency3, Action<TOptions, TDep1, TDep2, TDep3>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    public class ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3, TDep4> : IConfigureNamedOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
        where TDep4 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency1">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="dependency4">A fourth dependency.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, Action<TOptions, TDep1, TDep2, TDep3, TDep4>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3, TDep4>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IConfigureNamedOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    /// <typeparam name="TDep5">Fifth dependency type.</typeparam>
    public class ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5> : IConfigureNamedOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
        where TDep4 : class
        where TDep5 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency1">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="dependency4">A fourth dependency.</param>
        /// <param name="dependency5">A fifth dependency.</param>
        /// <param name="action">The action to register.</param>
        public ConfigureNamedOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, TDep5 dependency5, Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
            Dependency5 = dependency5;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// The fifth dependency.
        /// </summary>
        public TDep5 Dependency5 { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4, Dependency5);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public void Configure(TOptions options) => Configure(Options.DefaultName, options);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    public class ConfigureOptions<TOptions> : IConfigureOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="action">The action to register.</param>
        public ConfigureOptions(Action<TOptions>? action)
        {
            Action = action;
        }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions>? Action { get; }

        /// <summary>
        /// Invokes the registered configure <see cref="Action"/>.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        public virtual void Configure(TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            Action?.Invoke(options);
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Represents something that configures the <typeparamref name="TOptions"/> type.
    /// </summary>
    /// <typeparam name="TOptions">The options type being configured.</typeparam>
    public interface IConfigureNamedOptions<in TOptions> : IConfigureOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configure.</param>
        void Configure(string? name, TOptions options);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Represents something that configures the <typeparamref name="TOptions"/> type.
    /// Note: These are run before all <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">The options type being configured.</typeparam>
    public interface IConfigureOptions<in TOptions> where TOptions : class
    {
        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance.
        /// </summary>
        /// <param name="options">The options instance to configure.</param>
        void Configure(TOptions options);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to retrieve configured <typeparamref name="TOptions"/> instances.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public interface IOptions<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] out TOptions>
        where TOptions : class
    {
        /// <summary>
        /// The default configured <typeparamref name="TOptions"/> instance
        /// </summary>
        TOptions Value { get; }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to fetch <see cref="IChangeToken"/> used for tracking options changes.
    /// </summary>
    /// <typeparam name="TOptions">The options type being changed.</typeparam>
    public interface IOptionsChangeTokenSource<out TOptions>
    {
        /// <summary>
        /// Returns a <see cref="IChangeToken"/> which can be used to register a change notification callback.
        /// </summary>
        /// <returns>Change token.</returns>
        IChangeToken GetChangeToken();

        /// <summary>
        /// The name of the option instance being changed.
        /// </summary>
        string? Name { get; }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to create <typeparamref name="TOptions"/> instances.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public interface IOptionsFactory<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions>
        where TOptions : class
    {
        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance to create.</param>
        /// <returns>The created <typeparamref name="TOptions"/> instance with thw given <paramref name="name"/>.</returns>
        TOptions Create(string name);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used for notifications when <typeparamref name="TOptions"/> instances change.
    /// </summary>
    /// <typeparam name="TOptions">The options type.</typeparam>
    public interface IOptionsMonitor<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] out TOptions>
    {
        /// <summary>
        /// Returns the current <typeparamref name="TOptions"/> instance with the <see cref="Options.DefaultName"/>.
        /// </summary>
        TOptions CurrentValue { get; }

        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance, if a <see langword="null"/> <see cref="Options.DefaultName"/> is used.</param>
        /// <returns>The <typeparamref name="TOptions"/> instance that matches the given <paramref name="name"/>.</returns>
        TOptions Get(string? name);

        /// <summary>
        /// Registers a listener to be called whenever a named <typeparamref name="TOptions"/> changes.
        /// </summary>
        /// <param name="listener">The action to be invoked when <typeparamref name="TOptions"/> has changed.</param>
        /// <returns>An <see cref="IDisposable"/> which should be disposed to stop listening for changes.</returns>
        IDisposable? OnChange(Action<TOptions, string?> listener);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used by <see cref="IOptionsMonitor{TOptions}"/> to cache <typeparamref name="TOptions"/> instances.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public interface IOptionsMonitorCache<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions>
        where TOptions : class
    {
        /// <summary>
        /// Gets a named options instance, or adds a new instance created with <paramref name="createOptions"/>.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="createOptions">The func used to create the new instance.</param>
        /// <returns>The options instance.</returns>
        TOptions GetOrAdd(string? name, Func<TOptions> createOptions);

        /// <summary>
        /// Tries to adds a new option to the cache, will return false if the name already exists.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>Whether anything was added.</returns>
        bool TryAdd(string? name, TOptions options);

        /// <summary>
        /// Try to remove an options instance.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <returns>Whether anything was removed.</returns>
        bool TryRemove(string? name);

        /// <summary>
        /// Clears all options instances from the cache.
        /// </summary>
        void Clear();
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to access the value of <typeparamref name="TOptions"/> for the lifetime of a request.
    /// </summary>
    /// <typeparam name="TOptions">Options type.</typeparam>
    public interface IOptionsSnapshot<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] out TOptions> :
        IOptions<TOptions>
        where TOptions : class
    {
        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance, if <see langword="null"/> <see cref="Options.DefaultName"/> is used.</param>
        /// <returns>The <typeparamref name="TOptions"/> instance that matches the given <paramref name="name"/>.</returns>
        TOptions Get(string? name);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Represents something that configures the <typeparamref name="TOptions"/> type.
    /// Note: These are run after all <see cref="IConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    public interface IPostConfigureOptions<in TOptions> where TOptions : class
    {
        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        void PostConfigure(string? name, TOptions options);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Interface used by hosts to validate options during startup.
    /// Options are enabled to be validated during startup by calling <see cref="DependencyInjection.OptionsBuilderExtensions.ValidateOnStart{TOptions}(OptionsBuilder{TOptions})"/>.
    /// </summary>
    public interface IStartupValidator
    {
        /// <summary>
        /// Calls the <see cref="IValidateOptions{TOptions}"/> validators.
        /// </summary>
        /// <exception cref="OptionsValidationException">One or more <see cref="IValidateOptions{TOptions}"/> return failed <see cref="ValidateOptionsResult"/> when validating.</exception>
        void Validate();
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Interface used to validate options.
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    public interface IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Validates a specific named options instance (or all when name is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        ValidateOptionsResult Validate(string? name, TOptions options);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Helper class.
    /// </summary>
    public static class Options
    {
        // By default, we're going to keep public, parameterless constructor on any Options class.
        internal const DynamicallyAccessedMemberTypes DynamicallyAccessedMembers = DynamicallyAccessedMemberTypes.PublicParameterlessConstructor;

        /// <summary>
        /// The default name used for options instances: "".
        /// </summary>
        public static readonly string DefaultName = string.Empty;

        /// <summary>
        /// Creates a wrapper around an instance of <typeparamref name="TOptions"/> to return itself as an <see cref="IOptions{TOptions}"/>.
        /// </summary>
        /// <typeparam name="TOptions">Options type.</typeparam>
        /// <param name="options">Options object.</param>
        /// <returns>Wrapped options object.</returns>
        public static IOptions<TOptions> Create<[DynamicallyAccessedMembers(DynamicallyAccessedMembers)] TOptions>(TOptions options)
            where TOptions : class
        {
            return new OptionsWrapper<TOptions>(options);
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to configure <typeparamref name="TOptions"/> instances.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public class OptionsBuilder<TOptions> where TOptions : class
    {
        private const string DefaultValidationFailureMessage = "A validation error has occurred.";

        /// <summary>
        /// The default name of the <typeparamref name="TOptions"/> instance.
        /// </summary>
        public string Name { get; }

        /// <summary>
        /// The <see cref="IServiceCollection"/> for the options being configured.
        /// </summary>
        public IServiceCollection Services { get; }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> for the options being configured.</param>
        /// <param name="name">The default name of the <typeparamref name="TOptions"/> instance, if null <see cref="Options.DefaultName"/> is used.</param>
        public OptionsBuilder(IServiceCollection services, string? name)
        {
            ThrowHelper.ThrowIfNull(services);

            Services = services;
            Name = name ?? Options.DefaultName;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure(Action<TOptions> configureOptions)
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddSingleton<IConfigureOptions<TOptions>>(new ConfigureNamedOptions<TOptions>(Name, configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep">A dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure<TDep>(Action<TOptions, TDep> configureOptions)
            where TDep : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IConfigureOptions<TOptions>>(sp =>
                new ConfigureNamedOptions<TOptions, TDep>(Name, sp.GetRequiredService<TDep>(), configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure<TDep1, TDep2>(Action<TOptions, TDep1, TDep2> configureOptions)
            where TDep1 : class
            where TDep2 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IConfigureOptions<TOptions>>(sp =>
                new ConfigureNamedOptions<TOptions, TDep1, TDep2>(Name, sp.GetRequiredService<TDep1>(), sp.GetRequiredService<TDep2>(), configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure<TDep1, TDep2, TDep3>(Action<TOptions, TDep1, TDep2, TDep3> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IConfigureOptions<TOptions>>(
                sp => new ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure<TDep1, TDep2, TDep3, TDep4>(Action<TOptions, TDep1, TDep2, TDep3, TDep4> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
            where TDep4 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IConfigureOptions<TOptions>>(
                sp => new ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3, TDep4>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the action.</typeparam>
        /// <typeparam name="TDep5">The fifth dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Configure<TDep1, TDep2, TDep3, TDep4, TDep5>(Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
            where TDep4 : class
            where TDep5 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IConfigureOptions<TOptions>>(
                sp => new ConfigureNamedOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    sp.GetRequiredService<TDep5>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure(Action<TOptions> configureOptions)
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddSingleton<IPostConfigureOptions<TOptions>>(new PostConfigureOptions<TOptions>(Name, configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to post configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep">The dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure<TDep>(Action<TOptions, TDep> configureOptions)
            where TDep : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IPostConfigureOptions<TOptions>>(sp =>
                new PostConfigureOptions<TOptions, TDep>(Name, sp.GetRequiredService<TDep>(), configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to post configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure<TDep1, TDep2>(Action<TOptions, TDep1, TDep2> configureOptions)
            where TDep1 : class
            where TDep2 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IPostConfigureOptions<TOptions>>(sp =>
                new PostConfigureOptions<TOptions, TDep1, TDep2>(Name, sp.GetRequiredService<TDep1>(), sp.GetRequiredService<TDep2>(), configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to post configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure<TDep1, TDep2, TDep3>(Action<TOptions, TDep1, TDep2, TDep3> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IPostConfigureOptions<TOptions>>(
                sp => new PostConfigureOptions<TOptions, TDep1, TDep2, TDep3>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to post configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure<TDep1, TDep2, TDep3, TDep4>(Action<TOptions, TDep1, TDep2, TDep3, TDep4> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
            where TDep4 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IPostConfigureOptions<TOptions>>(
                sp => new PostConfigureOptions<TOptions, TDep1, TDep2, TDep3, TDep4>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Registers an action used to post configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure(Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the action.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the action.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the action.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the action.</typeparam>
        /// <typeparam name="TDep5">The fifth dependency used by the action.</typeparam>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> PostConfigure<TDep1, TDep2, TDep3, TDep4, TDep5>(Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5> configureOptions)
            where TDep1 : class
            where TDep2 : class
            where TDep3 : class
            where TDep4 : class
            where TDep5 : class
        {
            ThrowHelper.ThrowIfNull(configureOptions);

            Services.AddTransient<IPostConfigureOptions<TOptions>>(
                sp => new PostConfigureOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>(
                    Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    sp.GetRequiredService<TDep5>(),
                    configureOptions));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate(Func<TOptions, bool> validation)
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate(Func<TOptions, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddSingleton<IValidateOptions<TOptions>>(new ValidateOptions<TOptions>(Name, validation, failureMessage));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <typeparam name="TDep">The dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep>(Func<TOptions, TDep, bool> validation) where TDep : notnull
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <typeparam name="TDep">The dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep>(Func<TOptions, TDep, bool> validation, string failureMessage) where TDep : notnull
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddTransient<IValidateOptions<TOptions>>(sp =>
                new ValidateOptions<TOptions, TDep>(Name, sp.GetRequiredService<TDep>(), validation, failureMessage));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2>(Func<TOptions, TDep1, TDep2, bool> validation)
            where TDep1 : notnull
            where TDep2 : notnull
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2>(Func<TOptions, TDep1, TDep2, bool> validation, string failureMessage)
            where TDep1 : notnull
            where TDep2 : notnull
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddTransient<IValidateOptions<TOptions>>(sp =>
                new ValidateOptions<TOptions, TDep1, TDep2>(Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    validation,
                    failureMessage));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3>(Func<TOptions, TDep1, TDep2, TDep3, bool> validation)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3>(Func<TOptions, TDep1, TDep2, TDep3, bool> validation, string failureMessage)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddTransient<IValidateOptions<TOptions>>(sp =>
                new ValidateOptions<TOptions, TDep1, TDep2, TDep3>(Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    validation,
                    failureMessage));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3, TDep4>(Func<TOptions, TDep1, TDep2, TDep3, TDep4, bool> validation)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
            where TDep4 : notnull
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3, TDep4>(Func<TOptions, TDep1, TDep2, TDep3, TDep4, bool> validation, string failureMessage)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
            where TDep4 : notnull
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddTransient<IValidateOptions<TOptions>>(sp =>
                new ValidateOptions<TOptions, TDep1, TDep2, TDep3, TDep4>(Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    validation,
                    failureMessage));
            return this;
        }

        /// <summary>
        /// Register a validation action for an options type using a default failure message.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep5">The fifth dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3, TDep4, TDep5>(Func<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5, bool> validation)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
            where TDep4 : notnull
            where TDep5 : notnull
            => Validate(validation: validation, failureMessage: DefaultValidationFailureMessage);

        /// <summary>
        /// Register a validation action for an options type.
        /// </summary>
        /// <typeparam name="TDep1">The first dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep2">The second dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep3">The third dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep4">The fourth dependency used by the validation function.</typeparam>
        /// <typeparam name="TDep5">The fifth dependency used by the validation function.</typeparam>
        /// <param name="validation">The validation function.</param>
        /// <param name="failureMessage">The failure message to use when validation fails.</param>
        /// <returns>The current <see cref="OptionsBuilder{TOptions}"/>.</returns>
        public virtual OptionsBuilder<TOptions> Validate<TDep1, TDep2, TDep3, TDep4, TDep5>(Func<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5, bool> validation, string failureMessage)
            where TDep1 : notnull
            where TDep2 : notnull
            where TDep3 : notnull
            where TDep4 : notnull
            where TDep5 : notnull
        {
            ThrowHelper.ThrowIfNull(validation);

            Services.AddTransient<IValidateOptions<TOptions>>(sp =>
                new ValidateOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>(Name,
                    sp.GetRequiredService<TDep1>(),
                    sp.GetRequiredService<TDep2>(),
                    sp.GetRequiredService<TDep3>(),
                    sp.GetRequiredService<TDep4>(),
                    sp.GetRequiredService<TDep5>(),
                    validation,
                    failureMessage));
            return this;
        }
    }
}

namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for adding configuration related options services to the DI container via <see cref="OptionsBuilder{TOptions}"/>.
    /// </summary>
    [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2091:UnrecognizedReflectionPattern",
        Justification = "Workaround for https://github.com/mono/linker/issues/1416. Outer method has been annotated with DynamicallyAccessedMembers.")]
    public static class OptionsBuilderExtensions
    {
        /// <summary>
        /// Enforces options validation check on start rather than in runtime.
        /// </summary>
        /// <typeparam name="TOptions">The type of options.</typeparam>
        /// <param name="optionsBuilder">The <see cref="OptionsBuilder{TOptions}"/> to configure options instance.</param>
        /// <returns>The <see cref="OptionsBuilder{TOptions}"/> so that additional calls can be chained.</returns>
        public static OptionsBuilder<TOptions> ValidateOnStart<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicParameterlessConstructor)] TOptions>(this OptionsBuilder<TOptions> optionsBuilder)
            where TOptions : class
        {
            ThrowHelper.ThrowIfNull(optionsBuilder);

            optionsBuilder.Services.AddTransient<IStartupValidator, StartupValidator>();
            optionsBuilder.Services.AddOptions<StartupValidatorOptions>()
                .Configure<IOptionsMonitor<TOptions>>((vo, options) =>
                {
                    // This adds an action that resolves the options value to force evaluation
                    // We don't care about the result as duplicates are not important
                    vo._validators[(typeof(TOptions), optionsBuilder.Name)] = () => options.Get(optionsBuilder.Name);
                });

            return optionsBuilder;
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Used to cache <typeparamref name="TOptions"/> instances.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public class OptionsCache<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptionsMonitorCache<TOptions>
        where TOptions : class
    {
        private readonly ConcurrentDictionary<string, Lazy<TOptions>> _cache = new ConcurrentDictionary<string, Lazy<TOptions>>(concurrencyLevel: 1, capacity: 31, StringComparer.Ordinal); // 31 == default capacity

        /// <summary>
        /// Clears all options instances from the cache.
        /// </summary>
        public void Clear() => _cache.Clear();

        /// <summary>
        /// Gets a named options instance, or adds a new instance created with <paramref name="createOptions"/>.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="createOptions">The func used to create the new instance.</param>
        /// <returns>The options instance.</returns>
        public virtual TOptions GetOrAdd(string? name, Func<TOptions> createOptions)
        {
            ThrowHelper.ThrowIfNull(createOptions);

            name ??= Options.DefaultName;
            Lazy<TOptions> value;

#if NET || NETSTANDARD2_1
            value = _cache.GetOrAdd(name, static (name, createOptions) => new Lazy<TOptions>(createOptions), createOptions);
#else
            if (!_cache.TryGetValue(name, out value))
            {
                value = _cache.GetOrAdd(name, new Lazy<TOptions>(createOptions));
            }
#endif

            return value.Value;
        }

        internal TOptions GetOrAdd<TArg>(string? name, Func<string, TArg, TOptions> createOptions, TArg factoryArgument)
        {
            // For compatibility, fall back to public GetOrAdd() if we're in a derived class.
            // For simplicity, we do the same for older frameworks that don't support the factoryArgument overload of GetOrAdd().
#if NET || NETSTANDARD2_1
            if (GetType() != typeof(OptionsCache<TOptions>))
#endif
            {
                // copying captured variables to locals avoids allocating a closure if we don't enter the if
                string? localName = name;
                Func<string, TArg, TOptions> localCreateOptions = createOptions;
                TArg localFactoryArgument = factoryArgument;
                return GetOrAdd(name, () => localCreateOptions(localName ?? Options.DefaultName, localFactoryArgument));
            }

#if NET || NETSTANDARD2_1
            return _cache.GetOrAdd(
                name ?? Options.DefaultName,
                static (name, arg) => new Lazy<TOptions>(() => arg.createOptions(name, arg.factoryArgument)), (createOptions, factoryArgument)).Value;
#endif
        }

        /// <summary>
        /// Gets a named options instance, if available.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>true if the options were retrieved; otherwise, false.</returns>
        internal bool TryGetValue(string? name, [MaybeNullWhen(false)] out TOptions options)
        {
            if (_cache.TryGetValue(name ?? Options.DefaultName, out Lazy<TOptions>? lazy))
            {
                options = lazy.Value;
                return true;
            }

            options = default;
            return false;
        }

        /// <summary>
        /// Tries to adds a new option to the cache, will return false if the name already exists.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>Whether anything was added.</returns>
        public virtual bool TryAdd(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            return _cache.TryAdd(name ?? Options.DefaultName, new Lazy<TOptions>(
#if !(NET || NETSTANDARD2_1)
                () =>
#endif
                options));
        }

        /// <summary>
        /// Try to remove an options instance.
        /// </summary>
        /// <param name="name">The name of the options instance.</param>
        /// <returns>Whether anything was removed.</returns>
        public virtual bool TryRemove(string? name) =>
            _cache.TryRemove(name ?? Options.DefaultName, out _);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IOptionsFactory{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">The type of options being requested.</typeparam>
    public class OptionsFactory<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptionsFactory<TOptions>
        where TOptions : class
    {
        private readonly IConfigureOptions<TOptions>[] _setups;
        private readonly IPostConfigureOptions<TOptions>[] _postConfigures;
        private readonly IValidateOptions<TOptions>[] _validations;

        /// <summary>
        /// Initializes a new instance with the specified options configurations.
        /// </summary>
        /// <param name="setups">The configuration actions to run.</param>
        /// <param name="postConfigures">The initialization actions to run.</param>
        public OptionsFactory(IEnumerable<IConfigureOptions<TOptions>> setups, IEnumerable<IPostConfigureOptions<TOptions>> postConfigures) : this(setups, postConfigures, validations: Array.Empty<IValidateOptions<TOptions>>())
        { }

        /// <summary>
        /// Initializes a new instance with the specified options configurations.
        /// </summary>
        /// <param name="setups">The configuration actions to run.</param>
        /// <param name="postConfigures">The initialization actions to run.</param>
        /// <param name="validations">The validations to run.</param>
        public OptionsFactory(IEnumerable<IConfigureOptions<TOptions>> setups, IEnumerable<IPostConfigureOptions<TOptions>> postConfigures, IEnumerable<IValidateOptions<TOptions>> validations)
        {
            // The default DI container uses arrays under the covers. Take advantage of this knowledge
            // by checking for an array and enumerate over that, so we don't need to allocate an enumerator.
            // When it isn't already an array, convert it to one, but don't use System.Linq to avoid pulling Linq in to
            // small trimmed applications.

            _setups = setups as IConfigureOptions<TOptions>[] ?? new List<IConfigureOptions<TOptions>>(setups).ToArray();
            _postConfigures = postConfigures as IPostConfigureOptions<TOptions>[] ?? new List<IPostConfigureOptions<TOptions>>(postConfigures).ToArray();
            _validations = validations as IValidateOptions<TOptions>[] ?? new List<IValidateOptions<TOptions>>(validations).ToArray();
        }

        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance to create.</param>
        /// <returns>The created <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.</returns>
        /// <exception cref="OptionsValidationException">One or more <see cref="IValidateOptions{TOptions}"/> return failed <see cref="ValidateOptionsResult"/> when validating the <typeparamref name="TOptions"/> instance been created.</exception>
        /// <exception cref="MissingMethodException">The <typeparamref name="TOptions"/> does not have a public parameterless constructor or <typeparamref name="TOptions"/> is <see langword="abstract"/>.</exception>
        public TOptions Create(string name)
        {
            TOptions options = CreateInstance(name);
            foreach (IConfigureOptions<TOptions> setup in _setups)
            {
                if (setup is IConfigureNamedOptions<TOptions> namedSetup)
                {
                    namedSetup.Configure(name, options);
                }
                else if (name == Options.DefaultName)
                {
                    setup.Configure(options);
                }
            }
            foreach (IPostConfigureOptions<TOptions> post in _postConfigures)
            {
                post.PostConfigure(name, options);
            }

            if (_validations.Length > 0)
            {
                var failures = new List<string>();
                foreach (IValidateOptions<TOptions> validate in _validations)
                {
                    ValidateOptionsResult result = validate.Validate(name, options);
                    if (result is not null && result.Failed)
                    {
                        failures.AddRange(result.Failures);
                    }
                }
                if (failures.Count > 0)
                {
                    throw new OptionsValidationException(name, typeof(TOptions), failures);
                }
            }

            return options;
        }

        /// <summary>
        /// Creates a new instance of options type.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance to create.</param>
        /// <returns>The created <typeparamref name="TOptions"/> instance.</returns>
        /// <exception cref="MissingMethodException">The <typeparamref name="TOptions"/> does not have a public parameterless constructor or <typeparamref name="TOptions"/> is <see langword="abstract"/>.</exception>
        protected virtual TOptions CreateInstance(string name)
        {
            return Activator.CreateInstance<TOptions>();
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IOptions{TOptions}"/> and <see cref="IOptionsSnapshot{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type.</typeparam>
    public class OptionsManager<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptions<TOptions>,
        IOptionsSnapshot<TOptions>
        where TOptions : class
    {
        private readonly IOptionsFactory<TOptions> _factory;
        private readonly OptionsCache<TOptions> _cache = new OptionsCache<TOptions>(); // Note: this is a private cache

        /// <summary>
        /// Initializes a new instance with the specified options configurations.
        /// </summary>
        /// <param name="factory">The factory to use to create options.</param>
        public OptionsManager(IOptionsFactory<TOptions> factory)
        {
            _factory = factory;
        }

        /// <summary>
        /// The default configured <typeparamref name="TOptions"/> instance, equivalent to Get(Options.DefaultName).
        /// </summary>
        public TOptions Value => Get(Options.DefaultName);

        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance, if <see langword="null"/> <see cref="Options.DefaultName"/> is used.</param>
        /// <returns>The <typeparamref name="TOptions"/> instance that matches the given <paramref name="name"/>.</returns>
        /// <exception cref="OptionsValidationException">One or more <see cref="IValidateOptions{TOptions}"/> return failed <see cref="ValidateOptionsResult"/> when validating the <typeparamref name="TOptions"/> instance been created.</exception>
        /// <exception cref="MissingMethodException">The <typeparamref name="TOptions"/> does not have a public parameterless constructor or <typeparamref name="TOptions"/> is <see langword="abstract"/>.</exception>
        public virtual TOptions Get(string? name)
        {
            name ??= Options.DefaultName;

            if (!_cache.TryGetValue(name, out TOptions? options))
            {
                // Store the options in our instance cache. Avoid closure on fast path by storing state into scoped locals.
                IOptionsFactory<TOptions> localFactory = _factory;
                string localName = name;
                options = _cache.GetOrAdd(name, () => localFactory.Create(localName));
            }

            return options;
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IOptionsMonitor{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type.</typeparam>
    public class OptionsMonitor<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptionsMonitor<TOptions>,
        IDisposable
        where TOptions : class
    {
        private readonly IOptionsMonitorCache<TOptions> _cache;
        private readonly IOptionsFactory<TOptions> _factory;
        private readonly List<IDisposable> _registrations = new List<IDisposable>();
        internal event Action<TOptions, string>? _onChange;

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="factory">The factory to use to create options.</param>
        /// <param name="sources">The sources used to listen for changes to the options instance.</param>
        /// <param name="cache">The cache used to store options.</param>
        public OptionsMonitor(IOptionsFactory<TOptions> factory, IEnumerable<IOptionsChangeTokenSource<TOptions>> sources, IOptionsMonitorCache<TOptions> cache)
        {
            _factory = factory;
            _cache = cache;

            void RegisterSource(IOptionsChangeTokenSource<TOptions> source)
            {
                IDisposable registration = ChangeToken.OnChange(
                          source.GetChangeToken,
                          InvokeChanged,
                          source.Name);

                _registrations.Add(registration);
            }

            // The default DI container uses arrays under the covers. Take advantage of this knowledge
            // by checking for an array and enumerate over that, so we don't need to allocate an enumerator.
            if (sources is IOptionsChangeTokenSource<TOptions>[] sourcesArray)
            {
                foreach (IOptionsChangeTokenSource<TOptions> source in sourcesArray)
                {
                    RegisterSource(source);
                }
            }
            else
            {
                foreach (IOptionsChangeTokenSource<TOptions> source in sources)
                {
                    RegisterSource(source);
                }
            }
        }

        private void InvokeChanged(string? name)
        {
            name ??= Options.DefaultName;
            _cache.TryRemove(name);
            TOptions options = Get(name);
            _onChange?.Invoke(options, name);
        }

        /// <summary>
        /// The present value of the options, equivalent to <c>Get(Options.DefaultName)</c>.
        /// </summary>
        /// <exception cref="OptionsValidationException">One or more <see cref="IValidateOptions{TOptions}"/> return failed <see cref="ValidateOptionsResult"/> when validating the <typeparamref name="TOptions"/> instance been created.</exception>
        /// <exception cref="MissingMethodException">The <typeparamref name="TOptions"/> does not have a public parameterless constructor or <typeparamref name="TOptions"/> is <see langword="abstract"/>.</exception>
        public TOptions CurrentValue
        {
            get => Get(Options.DefaultName);
        }

        /// <summary>
        /// Returns a configured <typeparamref name="TOptions"/> instance with the given <paramref name="name"/>.
        /// </summary>
        /// <param name="name">The name of the <typeparamref name="TOptions"/> instance, if <see langword="null"/> <see cref="Options.DefaultName"/> is used.</param>
        /// <returns>The <typeparamref name="TOptions"/> instance that matches the given <paramref name="name"/>.</returns>
        /// <exception cref="OptionsValidationException">One or more <see cref="IValidateOptions{TOptions}"/> return failed <see cref="ValidateOptionsResult"/> when validating the <typeparamref name="TOptions"/> instance been created.</exception>
        /// <exception cref="MissingMethodException">The <typeparamref name="TOptions"/> does not have a public parameterless constructor or <typeparamref name="TOptions"/> is <see langword="abstract"/>.</exception>
        public virtual TOptions Get(string? name)
        {
            if (_cache is not OptionsCache<TOptions> optionsCache)
            {
                // copying captured variables to locals avoids allocating a closure if we don't enter the if
                string localName = name ?? Options.DefaultName;
                IOptionsFactory<TOptions> localFactory = _factory;
                return _cache.GetOrAdd(localName, () => localFactory.Create(localName));
            }

            // non-allocating fast path
            return optionsCache.GetOrAdd(name, static (name, factory) => factory.Create(name), _factory);

        }

        /// <summary>
        /// Registers a listener to be called whenever <typeparamref name="TOptions"/> changes.
        /// </summary>
        /// <param name="listener">The action to be invoked when <typeparamref name="TOptions"/> has changed.</param>
        /// <returns>An <see cref="IDisposable"/> which should be disposed to stop listening for changes.</returns>
        public IDisposable OnChange(Action<TOptions, string> listener)
        {
            var disposable = new ChangeTrackerDisposable(this, listener);
            _onChange += disposable.OnChange;
            return disposable;
        }

        /// <summary>
        /// Removes all change registration subscriptions.
        /// </summary>
        public void Dispose()
        {
            // Remove all subscriptions to the change tokens
            foreach (IDisposable registration in _registrations)
            {
                registration.Dispose();
            }

            _registrations.Clear();
        }

        internal sealed class ChangeTrackerDisposable : IDisposable
        {
            private readonly Action<TOptions, string> _listener;
            private readonly OptionsMonitor<TOptions> _monitor;

            public ChangeTrackerDisposable(OptionsMonitor<TOptions> monitor, Action<TOptions, string> listener)
            {
                _listener = listener;
                _monitor = monitor;
            }

            public void OnChange(TOptions options, string name) => _listener.Invoke(options, name);

            public void Dispose() => _monitor._onChange -= OnChange;
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Extension methods for <see cref="IOptionsMonitor{TOptions}"/>.
    /// </summary>
    public static class OptionsMonitorExtensions
    {
        /// <summary>
        /// Registers a listener to be called whenever <typeparamref name="TOptions"/> changes.
        /// </summary>
        /// <typeparam name="TOptions">The type of options instance being monitored.</typeparam>
        /// <param name="monitor">The IOptionsMonitor.</param>
        /// <param name="listener">The action to be invoked when <typeparamref name="TOptions"/> has changed.</param>
        /// <returns>An <see cref="IDisposable"/> which should be disposed to stop listening for changes.</returns>
        public static IDisposable? OnChange<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions>(
            this IOptionsMonitor<TOptions> monitor,
            Action<TOptions> listener)
                => monitor.OnChange((o, _) => listener(o));
    }
}

namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for adding options services to the DI container.
    /// </summary>
    public static class OptionsServiceCollectionExtensions
    {
        /// <summary>
        /// Adds services required for using options.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection AddOptions(this IServiceCollection services)
        {
            ThrowHelper.ThrowIfNull(services);

            services.TryAdd(ServiceDescriptor.Singleton(typeof(IOptions<>), typeof(UnnamedOptionsManager<>)));
            services.TryAdd(ServiceDescriptor.Scoped(typeof(IOptionsSnapshot<>), typeof(OptionsManager<>)));
            services.TryAdd(ServiceDescriptor.Singleton(typeof(IOptionsMonitor<>), typeof(OptionsMonitor<>)));
            services.TryAdd(ServiceDescriptor.Transient(typeof(IOptionsFactory<>), typeof(OptionsFactory<>)));
            services.TryAdd(ServiceDescriptor.Singleton(typeof(IOptionsMonitorCache<>), typeof(OptionsCache<>)));
            return services;
        }

        /// <summary>
        /// Adds services required for using options and enforces options validation check on start rather than in runtime.
        /// </summary>
        /// <remarks>
        /// The <seealso cref="OptionsBuilderExtensions.ValidateOnStart{TOptions}(OptionsBuilder{TOptions})"/> extension is called by this method.
        /// </remarks>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="name">The name of the options instance.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static OptionsBuilder<TOptions> AddOptionsWithValidateOnStart<
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.All)] TOptions>(
            this IServiceCollection services,
            string? name = null)
            where TOptions : class
        {
            return new OptionsBuilder<TOptions>(services, name ?? Options.Options.DefaultName).ValidateOnStart();
        }

        /// <summary>
        /// Adds services required for using options and enforces options validation check on start rather than in runtime.
        /// </summary>
        /// <remarks>
        /// The <seealso cref="OptionsBuilderExtensions.ValidateOnStart{TOptions}(OptionsBuilder{TOptions})"/> extension is called by this method.
        /// </remarks>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <typeparam name="TValidateOptions">The <see cref="IValidateOptions{TOptions}"/> validator type.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="name">The name of the options instance.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static OptionsBuilder<TOptions> AddOptionsWithValidateOnStart<
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.All)] TOptions,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TValidateOptions>(
            this IServiceCollection services,
            string? name = null)
            where TOptions : class
            where TValidateOptions : class, IValidateOptions<TOptions>
        {
            services.AddOptions().TryAddEnumerable(ServiceDescriptor.Singleton<IValidateOptions<TOptions>, TValidateOptions>());
            return new OptionsBuilder<TOptions>(services, name ?? Options.Options.DefaultName).ValidateOnStart();
        }
        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure{TOptions}(IServiceCollection, Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection Configure<TOptions>(this IServiceCollection services, Action<TOptions> configureOptions) where TOptions : class
            => services.Configure(Options.Options.DefaultName, configureOptions);

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run before all <seealso cref="PostConfigure{TOptions}(IServiceCollection, Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection Configure<TOptions>(this IServiceCollection services, string? name, Action<TOptions> configureOptions)
            where TOptions : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(configureOptions);

            services.AddOptions();
            services.AddSingleton<IConfigureOptions<TOptions>>(new ConfigureNamedOptions<TOptions>(name, configureOptions));
            return services;
        }

        /// <summary>
        /// Registers an action used to configure all instances of a particular type of options.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection ConfigureAll<TOptions>(this IServiceCollection services, Action<TOptions> configureOptions) where TOptions : class
            => services.Configure(name: null, configureOptions: configureOptions);

        /// <summary>
        /// Registers an action used to initialize a particular type of options.
        /// Note: These are run after all <seealso cref="Configure{TOptions}(IServiceCollection, Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection PostConfigure<TOptions>(this IServiceCollection services, Action<TOptions> configureOptions) where TOptions : class
            => services.PostConfigure(Options.Options.DefaultName, configureOptions);

        /// <summary>
        /// Registers an action used to configure a particular type of options.
        /// Note: These are run after all <seealso cref="Configure{TOptions}(IServiceCollection, Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configure.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="name">The name of the options instance.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection PostConfigure<TOptions>(this IServiceCollection services, string? name, Action<TOptions> configureOptions)
            where TOptions : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(configureOptions);

            services.AddOptions();
            services.AddSingleton<IPostConfigureOptions<TOptions>>(new PostConfigureOptions<TOptions>(name, configureOptions));
            return services;
        }

        /// <summary>
        /// Registers an action used to post configure all instances of a particular type of options.
        /// Note: These are run after all <seealso cref="Configure{TOptions}(IServiceCollection, Action{TOptions})"/>.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureOptions">The action used to configure the options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection PostConfigureAll<TOptions>(this IServiceCollection services, Action<TOptions> configureOptions) where TOptions : class
            => services.PostConfigure(name: null, configureOptions: configureOptions);

        /// <summary>
        /// Registers a type that will have all of its <see cref="IConfigureOptions{TOptions}"/>,
        /// <see cref="IPostConfigureOptions{TOptions}"/>, and <see cref="IValidateOptions{TOptions}"/>
        /// registered.
        /// </summary>
        /// <typeparam name="TConfigureOptions">The type that will configure options.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection ConfigureOptions<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TConfigureOptions>(
            this IServiceCollection services)
            where TConfigureOptions : class
                => services.ConfigureOptions(typeof(TConfigureOptions));

        private static IEnumerable<Type> FindConfigurationServices(Type type)
        {
            foreach (Type t in GetInterfacesOnType(type))
            {
                if (t.IsGenericType)
                {
                    Type gtd = t.GetGenericTypeDefinition();
                    if (gtd == typeof(IConfigureOptions<>) ||
                        gtd == typeof(IPostConfigureOptions<>) ||
                        gtd == typeof(IValidateOptions<>))
                    {
                        yield return t;
                    }
                }
            }

            // Extracted the suppression to a local function as trimmer currently doesn't handle suppressions
            // on iterator methods correctly.
            [UnconditionalSuppressMessage("ReflectionAnalysis", "IL2070:UnrecognizedReflectionPattern",
                Justification="This method only looks for interfaces referenced in its code. " +
                    "The trimmer will keep the interface and thus all of its implementations in that case. " +
                    "The call to GetInterfaces may return less results in trimmed apps, but it will " +
                    "include the interfaces this method looks for if they should be there.")]
            static Type[] GetInterfacesOnType(Type t)
                => t.GetInterfaces();
        }

        private static void ThrowNoConfigServices(Type type) =>
            throw new InvalidOperationException(
                type.IsGenericType && type.GetGenericTypeDefinition() == typeof(Action<>) ?
                    SR.Error_NoConfigurationServicesAndAction :
                    SR.Error_NoConfigurationServices);

        /// <summary>
        /// Registers a type that will have all of its <see cref="IConfigureOptions{TOptions}"/>,
        /// <see cref="IPostConfigureOptions{TOptions}"/>, and <see cref="IValidateOptions{TOptions}"/>
        /// registered.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureType">The type that will configure options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection ConfigureOptions(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type configureType)
        {
            services.AddOptions();

            bool added = false;
            foreach (Type serviceType in FindConfigurationServices(configureType))
            {
                services.AddTransient(serviceType, configureType);
                added = true;
            }

            if (!added)
            {
                ThrowNoConfigServices(configureType);
            }

            return services;
        }

        /// <summary>
        /// Registers an object that will have all of its <see cref="IConfigureOptions{TOptions}"/>,
        /// <see cref="IPostConfigureOptions{TOptions}"/>, and <see cref="IValidateOptions{TOptions}"/>
        /// registered.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="configureInstance">The instance that will configure options.</param>
        /// <returns>The <see cref="IServiceCollection"/> so that additional calls can be chained.</returns>
        public static IServiceCollection ConfigureOptions(this IServiceCollection services, object configureInstance)
        {
            services.AddOptions();
            Type configureType = configureInstance.GetType();

            bool added = false;
            foreach (Type serviceType in FindConfigurationServices(configureType))
            {
                services.AddSingleton(serviceType, configureInstance);
                added = true;
            }

            if (!added)
            {
                ThrowNoConfigServices(configureType);
            }

            return services;
        }

        /// <summary>
        /// Gets an options builder that forwards Configure calls for the same <typeparamref name="TOptions"/> to the underlying service collection.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <returns>The <see cref="OptionsBuilder{TOptions}"/> so that configure calls can be chained in it.</returns>
        public static OptionsBuilder<TOptions> AddOptions<TOptions>(this IServiceCollection services) where TOptions : class
            => services.AddOptions<TOptions>(Options.Options.DefaultName);

        /// <summary>
        /// Gets an options builder that forwards Configure calls for the same named <typeparamref name="TOptions"/> to the underlying service collection.
        /// </summary>
        /// <typeparam name="TOptions">The options type to be configured.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the services to.</param>
        /// <param name="name">The name of the options instance.</param>
        /// <returns>The <see cref="OptionsBuilder{TOptions}"/> so that configure calls can be chained in it.</returns>
        public static OptionsBuilder<TOptions> AddOptions<TOptions>(this IServiceCollection services, string? name)
            where TOptions : class
        {
            ThrowHelper.ThrowIfNull(services);

            services.AddOptions();
            return new OptionsBuilder<TOptions>(services, name);
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Thrown when options validation fails.
    /// </summary>
    public class OptionsValidationException : Exception
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="optionsName">The name of the options instance that failed.</param>
        /// <param name="optionsType">The options type that failed.</param>
        /// <param name="failureMessages">The validation failure messages.</param>
        public OptionsValidationException(string optionsName, Type optionsType, IEnumerable<string>? failureMessages)
        {
            ThrowHelper.ThrowIfNull(optionsName);
            ThrowHelper.ThrowIfNull(optionsType);

            Failures = failureMessages ?? new List<string>();
            OptionsType = optionsType;
            OptionsName = optionsName;
        }

        /// <summary>
        /// The name of the options instance that failed.
        /// </summary>
        public string OptionsName { get; }

        /// <summary>
        /// The type of the options that failed.
        /// </summary>
        public Type OptionsType { get; }

        /// <summary>
        /// The validation failures.
        /// </summary>
        public IEnumerable<string> Failures { get; }

        /// <summary>
        /// The message is a semicolon separated list of the <see cref="Failures"/>.
        /// </summary>
        public override string Message => string.Join("; ", Failures);
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Triggers the automatic generation of the implementation of <see cref="Microsoft.Extensions.Options.IValidateOptions{T}" /> at compile time.
    /// </summary>
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct)]
    public sealed class OptionsValidatorAttribute : Attribute
    {
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// <see cref="IOptions{TOptions}"/> wrapper that returns the options instance.
    /// </summary>
    /// <typeparam name="TOptions">Options type.</typeparam>
    public class OptionsWrapper<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptions<TOptions>
        where TOptions : class
    {
        /// <summary>
        /// Initializes the wrapper with the options instance to return.
        /// </summary>
        /// <param name="options">The options instance to return.</param>
        public OptionsWrapper(TOptions options)
        {
            Value = options;
        }

        /// <summary>
        /// The options instance.
        /// </summary>
        public TOptions Value { get; }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    public class PostConfigureOptions<TOptions> : IPostConfigureOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Creates a new instance of <see cref="PostConfigureOptions{TOptions}"/>.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, Action<TOptions>? action)
        {
            Name = name;
            Action = action;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The initialization action.
        /// </summary>
        public Action<TOptions>? Action { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the action to invoke.</param>
        /// <param name="options">The options to use in initialization.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to initialize all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options);
            }
        }
    }

    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep">Dependency type.</typeparam>
    public class PostConfigureOptions<TOptions, TDep> : IPostConfigureOptions<TOptions>
        where TOptions : class
        where TDep : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, TDep dependency, Action<TOptions, TDep>? action)
        {
            Name = name;
            Action = action;
            Dependency = dependency;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep>? Action { get; }

        /// <summary>
        /// The dependency.
        /// </summary>
        public TDep Dependency { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance using the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configured.</param>
        public void PostConfigure(TOptions options) => PostConfigure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    public class PostConfigureOptions<TOptions, TDep1, TDep2> : IPostConfigureOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, TDep1 dependency, TDep2 dependency2, Action<TOptions, TDep1, TDep2>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency;
            Dependency2 = dependency2;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance using the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configured.</param>
        public void PostConfigure(TOptions options) => PostConfigure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    public class PostConfigureOptions<TOptions, TDep1, TDep2, TDep3> : IPostConfigureOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, TDep1 dependency, TDep2 dependency2, TDep3 dependency3, Action<TOptions, TDep1, TDep2, TDep3>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance using the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configured.</param>
        public void PostConfigure(TOptions options) => PostConfigure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    public class PostConfigureOptions<TOptions, TDep1, TDep2, TDep3, TDep4> : IPostConfigureOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
        where TDep4 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency1">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="dependency4">A fourth dependency.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, Action<TOptions, TDep1, TDep2, TDep3, TDep4>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3, TDep4>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance using the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configured.</param>
        public void PostConfigure(TOptions options) => PostConfigure(Options.DefaultName, options);
    }

    /// <summary>
    /// Implementation of <see cref="IPostConfigureOptions{TOptions}"/>.
    /// </summary>
    /// <typeparam name="TOptions">Options type being configured.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    /// <typeparam name="TDep5">Fifth dependency type.</typeparam>
    public class PostConfigureOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5> : IPostConfigureOptions<TOptions>
        where TOptions : class
        where TDep1 : class
        where TDep2 : class
        where TDep3 : class
        where TDep4 : class
        where TDep5 : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">The name of the options.</param>
        /// <param name="dependency1">A dependency.</param>
        /// <param name="dependency2">A second dependency.</param>
        /// <param name="dependency3">A third dependency.</param>
        /// <param name="dependency4">A fourth dependency.</param>
        /// <param name="dependency5">A fifth dependency.</param>
        /// <param name="action">The action to register.</param>
        public PostConfigureOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, TDep5 dependency5, Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>? action)
        {
            Name = name;
            Action = action;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
            Dependency5 = dependency5;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The configuration action.
        /// </summary>
        public Action<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5>? Action { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// The fifth dependency.
        /// </summary>
        public TDep5 Dependency5 { get; }

        /// <summary>
        /// Invokes the registered initialization <see cref="Action"/> if the <paramref name="name"/> matches.
        /// </summary>
        /// <param name="name">The name of the options instance being configured.</param>
        /// <param name="options">The options instance to configured.</param>
        public virtual void PostConfigure(string? name, TOptions options)
        {
            ThrowHelper.ThrowIfNull(options);

            // Null name is used to configure all named options.
            if (Name == null || name == Name)
            {
                Action?.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4, Dependency5);
            }
        }

        /// <summary>
        /// Invoked to configure a <typeparamref name="TOptions"/> instance using the <see cref="Options.DefaultName"/>.
        /// </summary>
        /// <param name="options">The options instance to configured.</param>
        public void PostConfigure(TOptions options) => PostConfigure(Options.DefaultName, options);
    }

}

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

namespace Microsoft.Extensions.Options
{
    internal sealed class StartupValidatorOptions
    {
        // Maps each pair of a) options type and b) options name to a method that forces its evaluation, e.g. IOptionsMonitor<TOptions>.Get(name)
        public Dictionary<(Type, string), Action> _validators { get; } = new Dictionary<(Type, string), Action>();
    }
}

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

namespace Microsoft.Extensions.Options
{
    internal sealed class UnnamedOptionsManager<[DynamicallyAccessedMembers(Options.DynamicallyAccessedMembers)] TOptions> :
        IOptions<TOptions>
        where TOptions : class
    {
        private readonly IOptionsFactory<TOptions> _factory;
        private volatile object? _syncObj;
        private volatile TOptions? _value;

        public UnnamedOptionsManager(IOptionsFactory<TOptions> factory) => _factory = factory;

        public TOptions Value
        {
            get
            {
                if (_value is TOptions value)
                {
                    return value;
                }

                lock (_syncObj ?? Interlocked.CompareExchange(ref _syncObj, new object(), null) ?? _syncObj)
                {
                    return _value ??= _factory.Create(Options.DefaultName);
                }
            }
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Marks a field or property to be enumerated, and each enumerated object to be validated.
    /// </summary>
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
    public sealed class ValidateEnumeratedItemsAttribute : Attribute
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ValidateEnumeratedItemsAttribute"/> class.
        /// </summary>
        /// <remarks>
        /// Using this constructor for a field/property tells the code generator to
        /// generate validation for the individual members of the enumerable's type.
        /// </remarks>
        public ValidateEnumeratedItemsAttribute()
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ValidateEnumeratedItemsAttribute"/> class.
        /// </summary>
        /// <param name="validator">A type that implements <see cref="IValidateOptions{T}" /> for the enumerable's type.</param>
        /// <remarks>
        /// Using this constructor for a field/property tells the code generator to use the given type to validate
        /// the object held by the enumerable.
        /// </remarks>
        public ValidateEnumeratedItemsAttribute(Type validator)
        {
            Validator = validator;
        }

        /// <summary>
        /// Gets the type to use to validate the enumerable's objects.
        /// </summary>
        public Type? Validator { get; }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Marks a field or property to be validated transitively.
    /// </summary>
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
    public sealed class ValidateObjectMembersAttribute : Attribute
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ValidateObjectMembersAttribute"/> class.
        /// </summary>
        /// <remarks>
        /// Using this constructor for a field/property tells the code generator to
        /// generate validation for the individual members of the field/property's type.
        /// </remarks>
        public ValidateObjectMembersAttribute()
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ValidateObjectMembersAttribute"/> class.
        /// </summary>
        /// <param name="validator">A type that implements <see cref="IValidateOptions{T}" /> for the field/property's type.</param>
        /// <remarks>
        /// Using this constructor for a field/property tells the code generator to use the given type to validate
        /// the object held by the field/property.
        /// </remarks>
        public ValidateObjectMembersAttribute(Type validator)
        {
            Validator = validator;
        }

        /// <summary>
        /// Gets the type to use to validate a field or property.
        /// </summary>
        public Type? Validator { get; }
    }
}

namespace Microsoft.Extensions.Options
{
    internal sealed class StartupValidator : IStartupValidator
    {
        private readonly StartupValidatorOptions _validatorOptions;

        public StartupValidator(IOptions<StartupValidatorOptions> validators)
        {
            _validatorOptions = validators.Value;
        }

        public void Validate()
        {
            List<Exception>? exceptions = null;

            foreach (Action validator in _validatorOptions._validators.Values)
            {
                try
                {
                    // Execute the validation method and catch the validation error
                    validator();
                }
                catch (OptionsValidationException ex)
                {
                    exceptions ??= new();
                    exceptions.Add(ex);
                }
            }

            if (exceptions != null)
            {
                if (exceptions.Count == 1)
                {
                    // Rethrow if it's a single error
                    ExceptionDispatchInfo.Capture(exceptions[0]).Throw();
                }

                if (exceptions.Count > 1)
                {
                    // Aggregate if we have many errors
                    throw new AggregateException(exceptions);
                }
            }
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    public class ValidateOptions<TOptions> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, Func<TOptions, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }

    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    /// <typeparam name="TDep">Dependency type.</typeparam>
    public class ValidateOptions<TOptions, TDep> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="dependency">The dependency.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, TDep dependency, Func<TOptions, TDep, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
            Dependency = dependency;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, TDep, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// The dependency.
        /// </summary>
        public TDep Dependency { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options, Dependency))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }

    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    public class ValidateOptions<TOptions, TDep1, TDep2> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="dependency1">The first dependency.</param>
        /// <param name="dependency2">The second dependency.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, TDep1 dependency1, TDep2 dependency2, Func<TOptions, TDep1, TDep2, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, TDep1, TDep2, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options, Dependency1, Dependency2))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }

    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    public class ValidateOptions<TOptions, TDep1, TDep2, TDep3> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="dependency1">The first dependency.</param>
        /// <param name="dependency2">The second dependency.</param>
        /// <param name="dependency3">The third dependency.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, Func<TOptions, TDep1, TDep2, TDep3, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, TDep1, TDep2, TDep3, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options, Dependency1, Dependency2, Dependency3))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }

    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    public class ValidateOptions<TOptions, TDep1, TDep2, TDep3, TDep4> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="dependency1">The first dependency.</param>
        /// <param name="dependency2">The second dependency.</param>
        /// <param name="dependency3">The third dependency.</param>
        /// <param name="dependency4">The fourth dependency.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, Func<TOptions, TDep1, TDep2, TDep3, TDep4, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, TDep1, TDep2, TDep3, TDep4, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }

    /// <summary>
    /// Implementation of <see cref="IValidateOptions{TOptions}"/>
    /// </summary>
    /// <typeparam name="TOptions">The options type to validate.</typeparam>
    /// <typeparam name="TDep1">First dependency type.</typeparam>
    /// <typeparam name="TDep2">Second dependency type.</typeparam>
    /// <typeparam name="TDep3">Third dependency type.</typeparam>
    /// <typeparam name="TDep4">Fourth dependency type.</typeparam>
    /// <typeparam name="TDep5">Fifth dependency type.</typeparam>
    public class ValidateOptions<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5> : IValidateOptions<TOptions> where TOptions : class
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="name">Options name.</param>
        /// <param name="dependency1">The first dependency.</param>
        /// <param name="dependency2">The second dependency.</param>
        /// <param name="dependency3">The third dependency.</param>
        /// <param name="dependency4">The fourth dependency.</param>
        /// <param name="dependency5">The fifth dependency.</param>
        /// <param name="validation">Validation function.</param>
        /// <param name="failureMessage">Validation failure message.</param>
        public ValidateOptions(string? name, TDep1 dependency1, TDep2 dependency2, TDep3 dependency3, TDep4 dependency4, TDep5 dependency5, Func<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5, bool> validation, string failureMessage)
        {
            ThrowHelper.ThrowIfNull(validation);

            Name = name;
            Validation = validation;
            FailureMessage = failureMessage;
            Dependency1 = dependency1;
            Dependency2 = dependency2;
            Dependency3 = dependency3;
            Dependency4 = dependency4;
            Dependency5 = dependency5;
        }

        /// <summary>
        /// The options name.
        /// </summary>
        public string? Name { get; }

        /// <summary>
        /// The validation function.
        /// </summary>
        public Func<TOptions, TDep1, TDep2, TDep3, TDep4, TDep5, bool> Validation { get; }

        /// <summary>
        /// The error to return when validation fails.
        /// </summary>
        public string FailureMessage { get; }

        /// <summary>
        /// The first dependency.
        /// </summary>
        public TDep1 Dependency1 { get; }

        /// <summary>
        /// The second dependency.
        /// </summary>
        public TDep2 Dependency2 { get; }

        /// <summary>
        /// The third dependency.
        /// </summary>
        public TDep3 Dependency3 { get; }

        /// <summary>
        /// The fourth dependency.
        /// </summary>
        public TDep4 Dependency4 { get; }

        /// <summary>
        /// The fifth dependency.
        /// </summary>
        public TDep5 Dependency5 { get; }

        /// <summary>
        /// Validates a specific named options instance (or all when <paramref name="name"/> is null).
        /// </summary>
        /// <param name="name">The name of the options instance being validated.</param>
        /// <param name="options">The options instance.</param>
        /// <returns>The <see cref="ValidateOptionsResult"/> result.</returns>
        public ValidateOptionsResult Validate(string? name, TOptions options)
        {
            // null name is used to configure all named options
            if (Name == null || name == Name)
            {
                if (Validation.Invoke(options, Dependency1, Dependency2, Dependency3, Dependency4, Dependency5))
                {
                    return ValidateOptionsResult.Success;
                }
                return ValidateOptionsResult.Fail(FailureMessage);
            }

            // ignored if not validating this instance
            return ValidateOptionsResult.Skip;
        }
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Represents the result of an options validation.
    /// </summary>
    public class ValidateOptionsResult
    {
        /// <summary>
        /// Result when validation was skipped due to name not matching.
        /// </summary>
        public static readonly ValidateOptionsResult Skip = new ValidateOptionsResult() { Skipped = true };

        /// <summary>
        /// Validation was successful.
        /// </summary>
        public static readonly ValidateOptionsResult Success = new ValidateOptionsResult() { Succeeded = true };

        /// <summary>
        /// True if validation was successful.
        /// </summary>
        public bool Succeeded { get; protected set; }

        /// <summary>
        /// True if validation was not run.
        /// </summary>
        public bool Skipped { get; protected set; }

        /// <summary>
        /// True if validation failed.
        /// </summary>
        [MemberNotNullWhen(true, nameof(Failures))]
        [MemberNotNullWhen(true, nameof(FailureMessage))]
        public bool Failed { get; protected set; }

        /// <summary>
        /// Used to describe why validation failed.
        /// </summary>
        public string? FailureMessage { get; protected set; }

        /// <summary>
        /// Full list of failures (can be multiple).
        /// </summary>
        public IEnumerable<string>? Failures { get; protected set; }

        /// <summary>
        /// Returns a failure result.
        /// </summary>
        /// <param name="failureMessage">The reason for the failure.</param>
        /// <returns>The failure result.</returns>
        public static ValidateOptionsResult Fail(string failureMessage)
            => new ValidateOptionsResult { Failed = true, FailureMessage = failureMessage, Failures = new string[] { failureMessage } };

        /// <summary>
        /// Returns a failure result.
        /// </summary>
        /// <param name="failures">The reasons for the failure.</param>
        /// <returns>The failure result.</returns>
        public static ValidateOptionsResult Fail(IEnumerable<string> failures)
            => new ValidateOptionsResult { Failed = true, FailureMessage = string.Join("; ", failures), Failures = failures };
    }
}

namespace Microsoft.Extensions.Options
{
    /// <summary>
    /// Builds <see cref="ValidateOptionsResult"/> with support for multiple error messages.
    /// </summary>
    [DebuggerDisplay("{ErrorsCount} errors")]
    public class ValidateOptionsResultBuilder
    {
        private const string MemberSeparatorString = ", ";

        private List<string>? _errors;

        /// <summary>
        /// Creates new instance of the <see cref="ValidateOptionsResultBuilder"/> class.
        /// </summary>
        public ValidateOptionsResultBuilder() { }

        /// <summary>
        /// Adds a new validation error to the builder.
        /// </summary>
        /// <param name="error">Content of error message.</param>
        /// <param name="propertyName">The property in the option object which contains an error.</param>
        public void AddError(string error, string? propertyName = null)
        {
            ThrowHelper.ThrowIfNull(error);
            Errors.Add(propertyName is null ? error : $"Property {propertyName}: {error}");
        }

        /// <summary>
        /// Adds any validation error carried by the <see cref="ValidationResult"/> instance to this instance.
        /// </summary>
        /// <param name="result">The instance to append the error from.</param>
        public void AddResult(ValidationResult? result)
        {
            if (result?.ErrorMessage is not null)
            {
                string joinedMembers = string.Join(MemberSeparatorString, result.MemberNames);
                Errors.Add(joinedMembers.Length != 0
                    ? $"{joinedMembers}: {result.ErrorMessage}"
                    : result.ErrorMessage);
            }
        }

        /// <summary>
        /// Adds any validation error carried by the enumeration of <see cref="ValidationResult"/> instances to this instance.
        /// </summary>
        /// <param name="results">The enumeration to consume the errors from.</param>
        public void AddResults(IEnumerable<ValidationResult?>? results)
        {
            if (results != null)
            {
                foreach (ValidationResult? result in results)
                {
                    AddResult(result);
                }
            }
        }

        /// <summary>
        /// Adds any validation errors carried by the <see cref="ValidateOptionsResult"/> instance to this instance.
        /// </summary>
        /// <param name="result">The instance to consume the errors from.</param>
        public void AddResult(ValidateOptionsResult result)
        {
            ThrowHelper.ThrowIfNull(result);

            if (result.Failed)
            {
                if (result.Failures is null)
                {
                    Errors.Add(result.FailureMessage);
                }
                else
                {
                    // We are adding each failure separately to have the right failures count in _errors list.
                    // Otherwise we could add result.FailureMessage as one failure containing all result failures.
                    foreach (var failure in result.Failures)
                    {
                        if (failure is not null)
                        {
                            Errors.Add(failure);
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Builds <see cref="ValidateOptionsResult"/> based on provided data.
        /// </summary>
        /// <returns>New instance of <see cref="ValidateOptionsResult"/>.</returns>
        public ValidateOptionsResult Build()
        {
            if (_errors?.Count > 0)
            {
                return ValidateOptionsResult.Fail(_errors);
            }

            return ValidateOptionsResult.Success;
        }

        /// <summary>
        /// Reset the builder to the empty state
        /// </summary>
        public void Clear() => _errors?.Clear();

        private int ErrorsCount => _errors is null ? 0 : _errors.Count;

        private List<string> Errors => _errors ??= new();
    }
}

#nullable disable

namespace FxResources.Microsoft.Extensions.Options
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
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.Options.SR));

        internal static string Error_CannotActivateAbstractOrInterface => GetResourceString("Error_CannotActivateAbstractOrInterface");

        internal static string Error_FailedBinding => GetResourceString("Error_FailedBinding");

        internal static string Error_FailedToActivate => GetResourceString("Error_FailedToActivate");

        internal static string Error_MissingParameterlessConstructor => GetResourceString("Error_MissingParameterlessConstructor");

        internal static string Error_NoConfigurationServices => GetResourceString("Error_NoConfigurationServices");

        internal static string Error_NoConfigurationServicesAndAction => GetResourceString("Error_NoConfigurationServicesAndAction");
    }
}
