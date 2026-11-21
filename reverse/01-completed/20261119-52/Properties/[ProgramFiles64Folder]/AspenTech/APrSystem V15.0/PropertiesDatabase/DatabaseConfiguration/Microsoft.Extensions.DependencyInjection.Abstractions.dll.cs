// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// Source files combined from dotnet/runtime at 5535e31a712343a63f5d7d796cd874e563e5ac14.
#define NET
#define NETCOREAPP
#define NETCOREAPP3_0_OR_GREATER
#define NETCOREAPP3_1_OR_GREATER
#define NET8_0_OR_GREATER
#nullable enable annotations

using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Internal;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics;
using System.Linq.Expressions;
using System.Reflection.Metadata;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Threading.Tasks;
using System;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: MetadataUpdateHandler(typeof(ActivatorUtilities.ActivatorUtilitiesUpdateHandler))]
[assembly: InternalsVisibleTo("Microsoft.Extensions.DependencyInjection.Tests, PublicKey=0024000004800000940000000602000000240000525341310004000001000100f33a29044fa9d740c9b3213a93e57c84b472c84e0b8a0e1ae48e67a9f8f6de9d5f7f3d52ac23e48ac51801f1dc950abe901da34d2a9e3baadb141a17c77ef3c565dd5ee5054b91cf63bb3c6ab83f72ab3aafe93d0fc3c2348b764fafb0b1c0733de51459aeab46580384bf9d74c4e28164b7cde247f891ba07891c9d872ad2bb")]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.DependencyInjection.Abstractions")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Abstractions for dependency injection.\r\n\r\nCommonly Used Types:\r\nMicrosoft.Extensions.DependencyInjection.IServiceCollection")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.DependencyInjection.Abstractions")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]

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

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ActivatorUtilities.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Helper code for the various activator services.
    /// </summary>
    public static class ActivatorUtilities
    {
#if NETCOREAPP
        // Support caching of constructor metadata for the common case of types in non-collectible assemblies.
        private static readonly ConcurrentDictionary<Type, ConstructorInfoEx[]> s_constructorInfos = new();

        // Support caching of constructor metadata for types in collectible assemblies.
        private static readonly Lazy<ConditionalWeakTable<Type, ConstructorInfoEx[]>> s_collectibleConstructorInfos = new();
#endif

#if NET8_0_OR_GREATER
        // Maximum number of fixed arguments for ConstructorInvoker.Invoke(arg1, etc).
        private const int FixedArgumentThreshold = 4;
#endif

        private static readonly MethodInfo GetServiceInfo =
            GetMethodInfo<Func<IServiceProvider, Type, Type, bool, object?, object?>>((sp, t, r, c, k) => GetService(sp, t, r, c, k));

        /// <summary>
        /// Instantiate a type with constructor arguments provided directly and/or from an <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="provider">The service provider used to resolve dependencies</param>
        /// <param name="instanceType">The type to activate</param>
        /// <param name="parameters">Constructor arguments not provided by the <paramref name="provider"/>.</param>
        /// <returns>An activated object of type instanceType</returns>
        public static object CreateInstance(
            IServiceProvider provider,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            params object[] parameters)
        {
            if (provider == null)
            {
                throw new ArgumentNullException(nameof(provider));
            }

            if (instanceType.IsAbstract)
            {
                throw new InvalidOperationException(SR.CannotCreateAbstractClasses);
            }

            ConstructorInfoEx[]? constructors;
#if NETCOREAPP
            if (!s_constructorInfos.TryGetValue(instanceType, out constructors))
            {
                constructors = GetOrAddConstructors(instanceType);
            }
#else
            constructors = CreateConstructorInfoExs(instanceType);
#endif

            ConstructorInfoEx? constructor;
            IServiceProviderIsService? serviceProviderIsService = provider.GetService<IServiceProviderIsService>();
            // if container supports using IServiceProviderIsService, we try to find the longest ctor that
            // (a) matches all parameters given to CreateInstance
            // (b) matches the rest of ctor arguments as either a parameter with a default value or as a service registered
            // if no such match is found we fallback to the same logic used by CreateFactory which would only allow creating an
            // instance if all parameters given to CreateInstance only match with a single ctor
            if (serviceProviderIsService != null)
            {
                int bestLength = -1;
                bool seenPreferred = false;

                ConstructorMatcher bestMatcher = default;
                bool multipleBestLengthFound = false;

                for (int i = 0; i < constructors.Length; i++)
                {
                    constructor = constructors[i];
                    ConstructorMatcher matcher = new(constructor);
                    bool isPreferred = constructor.IsPreferred;
                    int length = matcher.Match(parameters, serviceProviderIsService);

                    if (isPreferred)
                    {
                        if (seenPreferred)
                        {
                            ThrowMultipleCtorsMarkedWithAttributeException();
                        }

                        if (length == -1)
                        {
                            ThrowMarkedCtorDoesNotTakeAllProvidedArguments();
                        }
                    }

                    if (isPreferred || bestLength < length)
                    {
                        bestLength = length;
                        bestMatcher = matcher;
                        multipleBestLengthFound = false;
                    }
                    else if (bestLength == length)
                    {
                        multipleBestLengthFound = true;
                    }

                    seenPreferred |= isPreferred;
                }

                if (bestLength != -1)
                {
                    if (multipleBestLengthFound)
                    {
                        throw new InvalidOperationException(SR.Format(SR.MultipleCtorsFoundWithBestLength, instanceType, bestLength));
                    }

                    return bestMatcher.CreateInstance(provider);
                }
            }

            Type?[] argumentTypes;
            if (parameters.Length == 0)
            {
                argumentTypes = Type.EmptyTypes;
            }
            else
            {
                argumentTypes = new Type[parameters.Length];
                for (int i = 0; i < argumentTypes.Length; i++)
                {
                    argumentTypes[i] = parameters[i]?.GetType();
                }
            }

            FindApplicableConstructor(instanceType, argumentTypes, out ConstructorInfo constructorInfo, out int?[] parameterMap);

            // Find the ConstructorInfoEx from the given constructorInfo.
            constructor = null;
            foreach (ConstructorInfoEx ctor in constructors)
            {
                if (ReferenceEquals(ctor.Info, constructorInfo))
                {
                    constructor = ctor;
                    break;
                }
            }

            Debug.Assert(constructor != null);

            var constructorMatcher = new ConstructorMatcher(constructor);
            constructorMatcher.MapParameters(parameterMap, parameters);
            return constructorMatcher.CreateInstance(provider);
        }

#if NETCOREAPP
        private static ConstructorInfoEx[] GetOrAddConstructors(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type type)
        {
            // Not found. Do the slower work of checking for the value in the correct cache.
            // Null and non-collectible load contexts use the default cache.
            if (!type.Assembly.IsCollectible)
            {
                return s_constructorInfos.GetOrAdd(type, CreateConstructorInfoExs(type));
            }

            // Collectible load contexts should use the ConditionalWeakTable so they can be unloaded.
            if (s_collectibleConstructorInfos.Value.TryGetValue(type, out ConstructorInfoEx[]? value))
            {
                return value;
            }

            value = CreateConstructorInfoExs(type);

            // ConditionalWeakTable doesn't support GetOrAdd() so use AddOrUpdate(). This means threads
            // can have different instances for the same type, but that is OK since they are equivalent.
            s_collectibleConstructorInfos.Value.AddOrUpdate(type, value);
            return value;
        }
#endif // NETCOREAPP

        private static ConstructorInfoEx[] CreateConstructorInfoExs(
                [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type type)
        {
            ConstructorInfo[] constructors = type.GetConstructors();
            ConstructorInfoEx[]? value = new ConstructorInfoEx[constructors.Length];
            for (int i = 0; i < constructors.Length; i++)
            {
                value[i] = new ConstructorInfoEx(constructors[i]);
            }

            return value;
        }

        /// <summary>
        /// Create a delegate that will instantiate a type with constructor arguments provided directly
        /// and/or from an <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="instanceType">The type to activate</param>
        /// <param name="argumentTypes">
        /// The types of objects, in order, that will be passed to the returned function as its second parameter
        /// </param>
        /// <returns>
        /// A factory that will instantiate instanceType using an <see cref="IServiceProvider"/>
        /// and an argument array containing objects matching the types defined in argumentTypes
        /// </returns>
        public static ObjectFactory CreateFactory(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            Type[] argumentTypes)
        {
#if NETSTANDARD2_1_OR_GREATER || NETCOREAPP
            if (!RuntimeFeature.IsDynamicCodeCompiled)
            {
                // Create a reflection-based factory when dynamic code is not compiled\jitted as would be the case with
                // NativeAOT, iOS or WASM.
                // For NativeAOT and iOS, using the reflection-based factory is faster than reflection-fallback interpreted
                // expressions and also doesn't pull in the large System.Linq.Expressions dependency.
                // For WASM, although it has the ability to use expressions (with dynamic code) and interpet the dynamic code
                // efficiently, the size savings of not using System.Linq.Expressions is more important than CPU perf.
                return CreateFactoryReflection(instanceType, argumentTypes);
            }
#endif
            CreateFactoryInternal(instanceType, argumentTypes, out ParameterExpression provider, out ParameterExpression argumentArray, out Expression factoryExpressionBody);

            var factoryLambda = Expression.Lambda<Func<IServiceProvider, object?[]?, object>>(
                factoryExpressionBody, provider, argumentArray);

            Func<IServiceProvider, object?[]?, object>? result = factoryLambda.Compile();
            return result.Invoke;
        }

        /// <summary>
        /// Create a delegate that will instantiate a type with constructor arguments provided directly
        /// and/or from an <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type to activate</typeparam>
        /// <param name="argumentTypes">
        /// The types of objects, in order, that will be passed to the returned function as its second parameter
        /// </param>
        /// <returns>
        /// A factory that will instantiate type T using an <see cref="IServiceProvider"/>
        /// and an argument array containing objects matching the types defined in argumentTypes
        /// </returns>
        public static ObjectFactory<T>
            CreateFactory<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] T>(
                Type[] argumentTypes)
        {
#if NETSTANDARD2_1_OR_GREATER || NETCOREAPP
            if (!RuntimeFeature.IsDynamicCodeCompiled)
            {
                // See the comment above in the non-generic CreateFactory() for why we use 'IsDynamicCodeCompiled' here.
                var factory = CreateFactoryReflection(typeof(T), argumentTypes);
                return (serviceProvider, arguments) => (T)factory(serviceProvider, arguments);
            }
#endif
            CreateFactoryInternal(typeof(T), argumentTypes, out ParameterExpression provider, out ParameterExpression argumentArray, out Expression factoryExpressionBody);

            var factoryLambda = Expression.Lambda<Func<IServiceProvider, object?[]?, T>>(
                factoryExpressionBody, provider, argumentArray);

            Func<IServiceProvider, object?[]?, T>? result = factoryLambda.Compile();
            return result.Invoke;
        }

        private static void CreateFactoryInternal([DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType, Type[] argumentTypes, out ParameterExpression provider, out ParameterExpression argumentArray, out Expression factoryExpressionBody)
        {
            FindApplicableConstructor(instanceType, argumentTypes, out ConstructorInfo constructor, out int?[] parameterMap);

            provider = Expression.Parameter(typeof(IServiceProvider), "provider");
            argumentArray = Expression.Parameter(typeof(object[]), "argumentArray");
            factoryExpressionBody = BuildFactoryExpression(constructor, parameterMap, provider, argumentArray);
        }

        /// <summary>
        /// Instantiate a type with constructor arguments provided directly and/or from an <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type to activate</typeparam>
        /// <param name="provider">The service provider used to resolve dependencies</param>
        /// <param name="parameters">Constructor arguments not provided by the <paramref name="provider"/>.</param>
        /// <returns>An activated object of type T</returns>
        public static T CreateInstance<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] T>(IServiceProvider provider, params object[] parameters)
        {
            return (T)CreateInstance(provider, typeof(T), parameters);
        }

        /// <summary>
        /// Retrieve an instance of the given type from the service provider. If one is not found then instantiate it directly.
        /// </summary>
        /// <typeparam name="T">The type of the service</typeparam>
        /// <param name="provider">The service provider used to resolve dependencies</param>
        /// <returns>The resolved service or created instance</returns>
        public static T GetServiceOrCreateInstance<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] T>(IServiceProvider provider)
        {
            return (T)GetServiceOrCreateInstance(provider, typeof(T));
        }

        /// <summary>
        /// Retrieve an instance of the given type from the service provider. If one is not found then instantiate it directly.
        /// </summary>
        /// <param name="provider">The service provider</param>
        /// <param name="type">The type of the service</param>
        /// <returns>The resolved service or created instance</returns>
        public static object GetServiceOrCreateInstance(
            IServiceProvider provider,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type type)
        {
            return provider.GetService(type) ?? CreateInstance(provider, type);
        }

        private static MethodInfo GetMethodInfo<T>(Expression<T> expr)
        {
            var mc = (MethodCallExpression)expr.Body;
            return mc.Method;
        }

        private static object? GetService(IServiceProvider sp, Type type, Type requiredBy, bool hasDefaultValue, object? key)
        {
            object? service = key == null ? sp.GetService(type) : GetKeyedService(sp, type, key);
            if (service is null && !hasDefaultValue)
            {
                ThrowHelperUnableToResolveService(type, requiredBy);
            }
            return service;
        }

        [DoesNotReturn]
        private static void ThrowHelperUnableToResolveService(Type type, Type requiredBy)
        {
            throw new InvalidOperationException(SR.Format(SR.UnableToResolveService, type, requiredBy));
        }

        private static BlockExpression BuildFactoryExpression(
            ConstructorInfo constructor,
            int?[] parameterMap,
            Expression serviceProvider,
            Expression factoryArgumentArray)
        {
            ParameterInfo[]? constructorParameters = constructor.GetParameters();
            var constructorArguments = new Expression[constructorParameters.Length];

            for (int i = 0; i < constructorParameters.Length; i++)
            {
                ParameterInfo? constructorParameter = constructorParameters[i];
                Type? parameterType = constructorParameter.ParameterType;
                bool hasDefaultValue = ParameterDefaultValue.TryGetDefaultValue(constructorParameter, out object? defaultValue);

                if (parameterMap[i] != null)
                {
                    constructorArguments[i] = Expression.ArrayAccess(factoryArgumentArray, Expression.Constant(parameterMap[i]));
                }
                else
                {
                    var keyAttribute = (FromKeyedServicesAttribute?) Attribute.GetCustomAttribute(constructorParameter, typeof(FromKeyedServicesAttribute), inherit: false);
                    var parameterTypeExpression = new Expression[] { serviceProvider,
                        Expression.Constant(parameterType, typeof(Type)),
                        Expression.Constant(constructor.DeclaringType, typeof(Type)),
                        Expression.Constant(hasDefaultValue),
                        Expression.Constant(keyAttribute?.Key) };
                    constructorArguments[i] = Expression.Call(GetServiceInfo, parameterTypeExpression);
                }

                // Support optional constructor arguments by passing in the default value
                // when the argument would otherwise be null.
                if (hasDefaultValue)
                {
                    ConstantExpression? defaultValueExpression = Expression.Constant(defaultValue);
                    constructorArguments[i] = Expression.Coalesce(constructorArguments[i], defaultValueExpression);
                }

                constructorArguments[i] = Expression.Convert(constructorArguments[i], parameterType);
            }

            return Expression.Block(Expression.IfThen(Expression.Equal(serviceProvider, Expression.Constant(null)), Expression.Throw(Expression.Constant(new ArgumentNullException(nameof(serviceProvider))))),
                Expression.New(constructor, constructorArguments));
        }

#if NETSTANDARD2_1_OR_GREATER || NETCOREAPP
        [DoesNotReturn]
        private static void ThrowHelperArgumentNullExceptionServiceProvider()
        {
            throw new ArgumentNullException("serviceProvider");
        }

        private static ObjectFactory CreateFactoryReflection(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            Type?[] argumentTypes)
        {
            FindApplicableConstructor(instanceType, argumentTypes, out ConstructorInfo constructor, out int?[] parameterMap);
            Type declaringType = constructor.DeclaringType!;

#if NET8_0_OR_GREATER
            ConstructorInvoker invoker = ConstructorInvoker.Create(constructor);

            ParameterInfo[] constructorParameters = constructor.GetParameters();
            if (constructorParameters.Length == 0)
            {
                return (IServiceProvider serviceProvider, object?[]? arguments) =>
                    invoker.Invoke();
            }

            // Gather some metrics to determine what fast path to take, if any.
            bool useFixedValues = constructorParameters.Length <= FixedArgumentThreshold;
            bool hasAnyDefaultValues = false;
            int matchedArgCount = 0;
            int matchedArgCountWithMap = 0;
            for (int i = 0; i < constructorParameters.Length; i++)
            {
                hasAnyDefaultValues |= constructorParameters[i].HasDefaultValue;

                if (parameterMap[i] is not null)
                {
                    matchedArgCount++;
                    if (parameterMap[i] == i)
                    {
                        matchedArgCountWithMap++;
                    }
                }
            }

            // No fast path; contains default values or arg mapping.
            if (hasAnyDefaultValues || matchedArgCount != matchedArgCountWithMap)
            {
                return InvokeCanonical();
            }

            if (matchedArgCount == 0)
            {
                // All injected; use a fast path.
                FactoryParameterContext[] parameters = GetFactoryParameterContext();
                return useFixedValues ?
                    (serviceProvider, arguments) => ReflectionFactoryServiceOnlyFixed(invoker, parameters, declaringType, serviceProvider) :
                    (serviceProvider, arguments) => ReflectionFactoryServiceOnlySpan(invoker, parameters, declaringType, serviceProvider);
            }

            if (matchedArgCount == constructorParameters.Length)
            {
                // All direct with no mappings; use a fast path.
                return (serviceProvider, arguments) => ReflectionFactoryDirect(invoker, serviceProvider, arguments);
            }

            return InvokeCanonical();

            ObjectFactory InvokeCanonical()
            {
                FactoryParameterContext[] parameters = GetFactoryParameterContext();
                return useFixedValues ?
                    (serviceProvider, arguments) => ReflectionFactoryCanonicalFixed(invoker, parameters, declaringType, serviceProvider, arguments) :
                    (serviceProvider, arguments) => ReflectionFactoryCanonicalSpan(invoker, parameters, declaringType, serviceProvider, arguments);
            }
#else
            ParameterInfo[] constructorParameters = constructor.GetParameters();
            if (constructorParameters.Length == 0)
            {
                return (IServiceProvider serviceProvider, object?[]? arguments) =>
                    constructor.Invoke(BindingFlags.DoNotWrapExceptions, binder: null, parameters: null, culture: null);
            }

            FactoryParameterContext[] parameters = GetFactoryParameterContext();
            return (serviceProvider, arguments) => ReflectionFactoryCanonical(constructor, parameters, declaringType, serviceProvider, arguments);
#endif // NET8_0_OR_GREATER

            FactoryParameterContext[] GetFactoryParameterContext()
            {
                FactoryParameterContext[] parameters = new FactoryParameterContext[constructorParameters.Length];
                for (int i = 0; i < constructorParameters.Length; i++)
                {
                    ParameterInfo constructorParameter = constructorParameters[i];
                    FromKeyedServicesAttribute? attr = (FromKeyedServicesAttribute?)
                        Attribute.GetCustomAttribute(constructorParameter, typeof(FromKeyedServicesAttribute), inherit: false);
                    bool hasDefaultValue = ParameterDefaultValue.TryGetDefaultValue(constructorParameter, out object? defaultValue);
                    parameters[i] = new FactoryParameterContext(
                        constructorParameter.ParameterType,
                        hasDefaultValue,
                        defaultValue,
                        parameterMap[i] ?? -1,
                        attr?.Key);
                }

                return parameters;
            }
        }
#endif // NETSTANDARD2_1_OR_GREATER || NETCOREAPP

        private readonly struct FactoryParameterContext
        {
            public FactoryParameterContext(Type parameterType, bool hasDefaultValue, object? defaultValue, int argumentIndex, object? serviceKey)
            {
                ParameterType = parameterType;
                HasDefaultValue = hasDefaultValue;
                DefaultValue = defaultValue;
                ArgumentIndex = argumentIndex;
                ServiceKey = serviceKey;
            }

            public Type ParameterType { get; }
            public bool HasDefaultValue { get; }
            public object? DefaultValue { get; }
            public int ArgumentIndex { get; }
            public object? ServiceKey { get; }
        }

        private static void FindApplicableConstructor(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            Type?[] argumentTypes,
            out ConstructorInfo matchingConstructor,
            out int?[] matchingParameterMap)
        {
            ConstructorInfo? constructorInfo;
            int?[]? parameterMap;

            if (!TryFindPreferredConstructor(instanceType, argumentTypes, out constructorInfo, out parameterMap) &&
                !TryFindMatchingConstructor(instanceType, argumentTypes, out constructorInfo, out parameterMap))
            {
                throw new InvalidOperationException(SR.Format(SR.CtorNotLocated, instanceType));
            }

            matchingConstructor = constructorInfo;
            matchingParameterMap = parameterMap;
        }

        // Tries to find constructor based on provided argument types
        private static bool TryFindMatchingConstructor(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            Type?[] argumentTypes,
            [NotNullWhen(true)] out ConstructorInfo? matchingConstructor,
            [NotNullWhen(true)] out int?[]? parameterMap)
        {
            matchingConstructor = null;
            parameterMap = null;

            foreach (ConstructorInfo? constructor in instanceType.GetConstructors())
            {
                if (TryCreateParameterMap(constructor.GetParameters(), argumentTypes, out int?[] tempParameterMap))
                {
                    if (matchingConstructor != null)
                    {
                        throw new InvalidOperationException(SR.Format(SR.MultipleCtorsFound, instanceType));
                    }

                    matchingConstructor = constructor;
                    parameterMap = tempParameterMap;
                }
            }

            if (matchingConstructor != null)
            {
                Debug.Assert(parameterMap != null);
                return true;
            }

            return false;
        }

        // Tries to find constructor marked with ActivatorUtilitiesConstructorAttribute
        private static bool TryFindPreferredConstructor(
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type instanceType,
            Type?[] argumentTypes,
            [NotNullWhen(true)] out ConstructorInfo? matchingConstructor,
            [NotNullWhen(true)] out int?[]? parameterMap)
        {
            bool seenPreferred = false;
            matchingConstructor = null;
            parameterMap = null;

            foreach (ConstructorInfo? constructor in instanceType.GetConstructors())
            {
                if (constructor.IsDefined(typeof(ActivatorUtilitiesConstructorAttribute), false))
                {
                    if (seenPreferred)
                    {
                        ThrowMultipleCtorsMarkedWithAttributeException();
                    }

                    if (!TryCreateParameterMap(constructor.GetParameters(), argumentTypes, out int?[] tempParameterMap))
                    {
                        ThrowMarkedCtorDoesNotTakeAllProvidedArguments();
                    }

                    matchingConstructor = constructor;
                    parameterMap = tempParameterMap;
                    seenPreferred = true;
                }
            }

            if (matchingConstructor != null)
            {
                Debug.Assert(parameterMap != null);
                return true;
            }

            return false;
        }

        // Creates an injective parameterMap from givenParameterTypes to assignable constructorParameters.
        // Returns true if each given parameter type is assignable to a unique; otherwise, false.
        private static bool TryCreateParameterMap(ParameterInfo[] constructorParameters, Type?[] argumentTypes, out int?[] parameterMap)
        {
            parameterMap = new int?[constructorParameters.Length];

            for (int i = 0; i < argumentTypes.Length; i++)
            {
                bool foundMatch = false;
                Type? givenParameter = argumentTypes[i];

                for (int j = 0; j < constructorParameters.Length; j++)
                {
                    if (parameterMap[j] != null)
                    {
                        // This ctor parameter has already been matched
                        continue;
                    }

                    if (constructorParameters[j].ParameterType.IsAssignableFrom(givenParameter))
                    {
                        foundMatch = true;
                        parameterMap[j] = i;
                        break;
                    }
                }

                if (!foundMatch)
                {
                    return false;
                }
            }

            return true;
        }

        private sealed class ConstructorInfoEx
        {
            public readonly ConstructorInfo Info;
            public readonly ParameterInfo[] Parameters;
            public readonly bool IsPreferred;
            private readonly object?[]? _parameterKeys;

            public ConstructorInfoEx(ConstructorInfo constructor)
            {
                Info = constructor;
                Parameters = constructor.GetParameters();
                IsPreferred = constructor.IsDefined(typeof(ActivatorUtilitiesConstructorAttribute), inherit: false);

                for (int i = 0; i < Parameters.Length; i++)
                {
                    FromKeyedServicesAttribute? attr = (FromKeyedServicesAttribute?)
                        Attribute.GetCustomAttribute(Parameters[i], typeof(FromKeyedServicesAttribute), inherit: false);

                    if (attr is not null)
                    {
                        _parameterKeys ??= new object?[Parameters.Length];
                        _parameterKeys[i] = attr.Key;
                    }
                }
            }

            public bool IsService(IServiceProviderIsService serviceProviderIsService, int parameterIndex)
            {
                ParameterInfo parameterInfo = Parameters[parameterIndex];

                // Handle keyed service
                object? key = _parameterKeys?[parameterIndex];
                if (key is not null)
                {
                    if (serviceProviderIsService is IServiceProviderIsKeyedService serviceProviderIsKeyedService)
                    {
                        return serviceProviderIsKeyedService.IsKeyedService(parameterInfo.ParameterType, key);
                    }

                    throw new InvalidOperationException(SR.KeyedServicesNotSupported);
                }

                // Use non-keyed service
                return serviceProviderIsService.IsService(parameterInfo.ParameterType);
            }

            public object? GetService(IServiceProvider serviceProvider, int parameterIndex)
            {
                ParameterInfo parameterInfo = Parameters[parameterIndex];

                // Handle keyed service
                object? key = _parameterKeys?[parameterIndex];
                if (key is not null)
                {
                    if (serviceProvider is IKeyedServiceProvider keyedServiceProvider)
                    {
                        return keyedServiceProvider.GetKeyedService(parameterInfo.ParameterType, key);
                    }

                    throw new InvalidOperationException(SR.KeyedServicesNotSupported);
                }

                // Use non-keyed service
                return serviceProvider.GetService(parameterInfo.ParameterType);
            }
        }

        private readonly struct ConstructorMatcher
        {
            private readonly ConstructorInfoEx _constructor;
            private readonly object?[] _parameterValues;

            public ConstructorMatcher(ConstructorInfoEx constructor)
            {
                _constructor = constructor;
                _parameterValues = new object[constructor.Parameters.Length];
            }

            public int Match(object[] givenParameters, IServiceProviderIsService serviceProviderIsService)
            {
                for (int givenIndex = 0; givenIndex < givenParameters.Length; givenIndex++)
                {
                    Type? givenType = givenParameters[givenIndex]?.GetType();
                    bool givenMatched = false;

                    for (int applyIndex = 0; applyIndex < _constructor.Parameters.Length; applyIndex++)
                    {
                        if (_parameterValues[applyIndex] == null &&
                            _constructor.Parameters[applyIndex].ParameterType.IsAssignableFrom(givenType))
                        {
                            givenMatched = true;
                            _parameterValues[applyIndex] = givenParameters[givenIndex];
                            break;
                        }
                    }

                    if (!givenMatched)
                    {
                        return -1;
                    }
                }

                // confirms the rest of ctor arguments match either as a parameter with a default value or as a service registered
                for (int i = 0; i < _constructor.Parameters.Length; i++)
                {
                    if (_parameterValues[i] == null &&
                        !_constructor.IsService(serviceProviderIsService, i))
                    {
                        if (ParameterDefaultValue.TryGetDefaultValue(_constructor.Parameters[i], out object? defaultValue))
                        {
                            _parameterValues[i] = defaultValue;
                        }
                        else
                        {
                            return -1;
                        }
                    }
                }

                return _constructor.Parameters.Length;
            }

            public object CreateInstance(IServiceProvider provider)
            {
                for (int index = 0; index < _constructor.Parameters.Length; index++)
                {
                    if (_parameterValues[index] == null)
                    {
                        object? value = _constructor.GetService(provider, index);
                        if (value == null)
                        {
                            if (!ParameterDefaultValue.TryGetDefaultValue(_constructor.Parameters[index], out object? defaultValue))
                            {
                                throw new InvalidOperationException(SR.Format(SR.UnableToResolveService, _constructor.Parameters[index].ParameterType, _constructor.Info.DeclaringType));
                            }
                            else
                            {
                                _parameterValues[index] = defaultValue;
                            }
                        }
                        else
                        {
                            _parameterValues[index] = value;
                        }
                    }
                }

#if NETFRAMEWORK || NETSTANDARD2_0
                try
                {
                    return _constructor.Info.Invoke(_parameterValues);
                }
                catch (TargetInvocationException ex) when (ex.InnerException != null)
                {
                    ExceptionDispatchInfo.Capture(ex.InnerException).Throw();
                    // The above line will always throw, but the compiler requires we throw explicitly.
                    throw;
                }
#else
                return _constructor.Info.Invoke(BindingFlags.DoNotWrapExceptions, binder: null, parameters: _parameterValues, culture: null);
#endif
            }

            public void MapParameters(int?[] parameterMap, object[] givenParameters)
            {
                for (int i = 0; i < _constructor.Parameters.Length; i++)
                {
                    if (parameterMap[i] != null)
                    {
                        _parameterValues[i] = givenParameters[(int)parameterMap[i]!];
                    }
                }
            }
        }

        private static void ThrowMultipleCtorsMarkedWithAttributeException()
        {
            throw new InvalidOperationException(SR.Format(SR.MultipleCtorsMarkedWithAttribute, nameof(ActivatorUtilitiesConstructorAttribute)));
        }

        private static void ThrowMarkedCtorDoesNotTakeAllProvidedArguments()
        {
            throw new InvalidOperationException(SR.Format(SR.MarkedCtorMissingArgumentTypes, nameof(ActivatorUtilitiesConstructorAttribute)));
        }

#if NET8_0_OR_GREATER // Use the faster ConstructorInvoker which also has alloc-free APIs when <= 4 parameters.
        private static object ReflectionFactoryServiceOnlyFixed(
            ConstructorInvoker invoker,
            FactoryParameterContext[] parameters,
            Type declaringType,
            IServiceProvider serviceProvider)
        {
            Debug.Assert(parameters.Length >= 1 && parameters.Length <= FixedArgumentThreshold);
            Debug.Assert(FixedArgumentThreshold == 4);

            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            switch (parameters.Length)
            {
                case 1:
                    return invoker.Invoke(
                        GetService(serviceProvider, parameters[0].ParameterType, declaringType, false, parameters[0].ServiceKey));

                case 2:
                    return invoker.Invoke(
                        GetService(serviceProvider, parameters[0].ParameterType, declaringType, false, parameters[0].ServiceKey),
                        GetService(serviceProvider, parameters[1].ParameterType, declaringType, false, parameters[1].ServiceKey));

                case 3:
                    return invoker.Invoke(
                        GetService(serviceProvider, parameters[0].ParameterType, declaringType, false, parameters[0].ServiceKey),
                        GetService(serviceProvider, parameters[1].ParameterType, declaringType, false, parameters[1].ServiceKey),
                        GetService(serviceProvider, parameters[2].ParameterType, declaringType, false, parameters[2].ServiceKey));

                case 4:
                    return invoker.Invoke(
                        GetService(serviceProvider, parameters[0].ParameterType, declaringType, false, parameters[0].ServiceKey),
                        GetService(serviceProvider, parameters[1].ParameterType, declaringType, false, parameters[1].ServiceKey),
                        GetService(serviceProvider, parameters[2].ParameterType, declaringType, false, parameters[2].ServiceKey),
                        GetService(serviceProvider, parameters[3].ParameterType, declaringType, false, parameters[3].ServiceKey));
            }

            return null!;
        }

        private static object ReflectionFactoryServiceOnlySpan(
            ConstructorInvoker invoker,
            FactoryParameterContext[] parameters,
            Type declaringType,
            IServiceProvider serviceProvider)
        {
            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            object?[] arguments = new object?[parameters.Length];
            for (int i = 0; i < parameters.Length; i++)
            {
                arguments[i] = GetService(serviceProvider, parameters[i].ParameterType, declaringType, false, parameters[i].ServiceKey);
            }

            return invoker.Invoke(arguments.AsSpan());
        }

        private static object ReflectionFactoryCanonicalFixed(
            ConstructorInvoker invoker,
            FactoryParameterContext[] parameters,
            Type declaringType,
            IServiceProvider serviceProvider,
            object?[]? arguments)
        {
            Debug.Assert(parameters.Length >= 1 && parameters.Length <= FixedArgumentThreshold);
            Debug.Assert(FixedArgumentThreshold == 4);

            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            ref FactoryParameterContext parameter1 = ref parameters[0];

            switch (parameters.Length)
            {
                case 1:
                    return invoker.Invoke(
                         ((parameter1.ArgumentIndex != -1)
                            // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                            ? arguments![parameter1.ArgumentIndex]
                            : GetService(
                                serviceProvider,
                                parameter1.ParameterType,
                                declaringType,
                                parameter1.HasDefaultValue,
                                parameter1.ServiceKey)) ?? parameter1.DefaultValue);
                case 2:
                    {
                        ref FactoryParameterContext parameter2 = ref parameters[1];

                        return invoker.Invoke(
                             ((parameter1.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter1.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter1.ParameterType,
                                    declaringType,
                                    parameter1.HasDefaultValue,
                                    parameter1.ServiceKey)) ?? parameter1.DefaultValue,
                             ((parameter2.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter2.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter2.ParameterType,
                                    declaringType,
                                    parameter2.HasDefaultValue,
                                    parameter2.ServiceKey)) ?? parameter2.DefaultValue);
                    }
                case 3:
                    {
                        ref FactoryParameterContext parameter2 = ref parameters[1];
                        ref FactoryParameterContext parameter3 = ref parameters[2];

                        return invoker.Invoke(
                             ((parameter1.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter1.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter1.ParameterType,
                                    declaringType,
                                    parameter1.HasDefaultValue,
                                    parameter1.ServiceKey)) ?? parameter1.DefaultValue,
                             ((parameter2.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter2.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter2.ParameterType,
                                    declaringType,
                                    parameter2.HasDefaultValue,
                                    parameter2.ServiceKey)) ?? parameter2.DefaultValue,
                             ((parameter3.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter3.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter3.ParameterType,
                                    declaringType,
                                    parameter3.HasDefaultValue,
                                    parameter3.ServiceKey)) ?? parameter3.DefaultValue);
                    }
                case 4:
                    {
                        ref FactoryParameterContext parameter2 = ref parameters[1];
                        ref FactoryParameterContext parameter3 = ref parameters[2];
                        ref FactoryParameterContext parameter4 = ref parameters[3];

                        return invoker.Invoke(
                             ((parameter1.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter1.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter1.ParameterType,
                                    declaringType,
                                    parameter1.HasDefaultValue,
                                    parameter1.ServiceKey)) ?? parameter1.DefaultValue,
                             ((parameter2.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter2.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter2.ParameterType,
                                    declaringType,
                                    parameter2.HasDefaultValue,
                                    parameter2.ServiceKey)) ?? parameter2.DefaultValue,
                             ((parameter3.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter3.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter3.ParameterType,
                                    declaringType,
                                    parameter3.HasDefaultValue,
                                    parameter3.ServiceKey)) ?? parameter3.DefaultValue,
                             ((parameter4.ArgumentIndex != -1)
                                // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                                ? arguments![parameter4.ArgumentIndex]
                                : GetService(
                                    serviceProvider,
                                    parameter4.ParameterType,
                                    declaringType,
                                    parameter4.HasDefaultValue,
                                    parameter4.ServiceKey)) ?? parameter4.DefaultValue);
                    }

            }

            return null!;
        }

        private static object ReflectionFactoryCanonicalSpan(
            ConstructorInvoker invoker,
            FactoryParameterContext[] parameters,
            Type declaringType,
            IServiceProvider serviceProvider,
            object?[]? arguments)
        {
            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            object?[] constructorArguments = new object?[parameters.Length];
            for (int i = 0; i < parameters.Length; i++)
            {
                ref FactoryParameterContext parameter = ref parameters[i];
                constructorArguments[i] = ((parameter.ArgumentIndex != -1)
                    // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                    ? arguments![parameter.ArgumentIndex]
                    : GetService(
                        serviceProvider,
                        parameter.ParameterType,
                        declaringType,
                        parameter.HasDefaultValue,
                        parameter.ServiceKey)) ?? parameter.DefaultValue;
            }

            return invoker.Invoke(constructorArguments.AsSpan());
        }

        private static object ReflectionFactoryDirect(
            ConstructorInvoker invoker,
            IServiceProvider serviceProvider,
            object?[]? arguments)
        {
            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            if (arguments is null)
                ThrowHelperNullReferenceException(); //AsSpan() will not throw NullReferenceException.

            return invoker.Invoke(arguments.AsSpan());
        }

        /// <summary>
        /// For consistency with the expression-based factory, throw NullReferenceException.
        /// </summary>
        [DoesNotReturn]
        private static void ThrowHelperNullReferenceException()
        {
            throw new NullReferenceException();
        }
#elif NETSTANDARD2_1_OR_GREATER || NETCOREAPP
        private static object ReflectionFactoryCanonical(
            ConstructorInfo constructor,
            FactoryParameterContext[] parameters,
            Type declaringType,
            IServiceProvider serviceProvider,
            object?[]? arguments)
        {
            if (serviceProvider is null)
                ThrowHelperArgumentNullExceptionServiceProvider();

            object?[] constructorArguments = new object?[parameters.Length];
            for (int i = 0; i < parameters.Length; i++)
            {
                ref FactoryParameterContext parameter = ref parameters[i];
                constructorArguments[i] = ((parameter.ArgumentIndex != -1)
                    // Throws a NullReferenceException if arguments is null. Consistent with expression-based factory.
                    ? arguments![parameter.ArgumentIndex]
                    : GetService(
                        serviceProvider,
                        parameter.ParameterType,
                        declaringType,
                        parameter.HasDefaultValue,
                        parameter.ServiceKey)) ?? parameter.DefaultValue;
            }

            return constructor.Invoke(BindingFlags.DoNotWrapExceptions, binder: null, constructorArguments, culture: null);
        }
#endif // NET8_0_OR_GREATER

#if NETCOREAPP
        internal static class ActivatorUtilitiesUpdateHandler
        {
            public static void ClearCache(Type[]? _)
            {
                // Ignore the Type[] argument; just clear the caches.
                s_constructorInfos.Clear();
                if (s_collectibleConstructorInfos.IsValueCreated)
                {
                    s_collectibleConstructorInfos.Value.Clear();
                }
            }
        }
#endif

        private static object? GetKeyedService(IServiceProvider provider, Type type, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(provider);

            if (provider is IKeyedServiceProvider keyedServiceProvider)
            {
                return keyedServiceProvider.GetKeyedService(type, serviceKey);
            }

            throw new InvalidOperationException(SR.KeyedServicesNotSupported);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ActivatorUtilitiesConstructorAttribute.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Marks the constructor to be used when activating type using <see cref="ActivatorUtilities"/>.
    /// </summary>
    [AttributeUsage(AttributeTargets.All)]
    public class ActivatorUtilitiesConstructorAttribute : Attribute
    {
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/AsyncServiceScope.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// An <see cref="IServiceScope" /> implementation that implements <see cref="IAsyncDisposable" />.
    /// </summary>
    [DebuggerDisplay("{ServiceProvider,nq}")]
    public readonly struct AsyncServiceScope : IServiceScope, IAsyncDisposable
    {
        private readonly IServiceScope _serviceScope;

        /// <summary>
        /// Initializes a new instance of the <see cref="AsyncServiceScope"/> struct.
        /// Wraps an instance of <see cref="IServiceScope" />.
        /// </summary>
        /// <param name="serviceScope">The <see cref="IServiceScope"/> instance to wrap.</param>
        public AsyncServiceScope(IServiceScope serviceScope)
        {
            ThrowHelper.ThrowIfNull(serviceScope);

            _serviceScope = serviceScope;
        }

        /// <inheritdoc />
        public IServiceProvider ServiceProvider => _serviceScope.ServiceProvider;

        /// <inheritdoc />
        public void Dispose()
        {
            _serviceScope.Dispose();
        }

        /// <inheritdoc />
        public ValueTask DisposeAsync()
        {
            if (_serviceScope is IAsyncDisposable ad)
            {
                return ad.DisposeAsync();
            }
            _serviceScope.Dispose();

            // ValueTask.CompletedTask is only available in net5.0 and later.
            return default;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/Extensions/ServiceCollectionDescriptorExtensions.cs
namespace Microsoft.Extensions.DependencyInjection.Extensions
{
    /// <summary>
    /// Extension methods for adding and removing services to an <see cref="IServiceCollection" />.
    /// </summary>
    public static partial class ServiceCollectionDescriptorExtensions
    {
        /// <summary>
        /// Adds the specified <paramref name="descriptor"/> to the <paramref name="collection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptor">The <see cref="ServiceDescriptor"/> to add.</param>
        /// <returns>A reference to the current instance of <see cref="IServiceCollection"/>.</returns>
        public static IServiceCollection Add(
            this IServiceCollection collection,
            ServiceDescriptor descriptor)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(descriptor);

            collection.Add(descriptor);
            return collection;
        }

        /// <summary>
        /// Adds a sequence of <see cref="ServiceDescriptor"/> to the <paramref name="collection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptors">The <see cref="ServiceDescriptor"/>s to add.</param>
        /// <returns>A reference to the current instance of <see cref="IServiceCollection"/>.</returns>
        public static IServiceCollection Add(
            this IServiceCollection collection,
            IEnumerable<ServiceDescriptor> descriptors)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(descriptors);

            foreach (ServiceDescriptor? descriptor in descriptors)
            {
                collection.Add(descriptor);
            }

            return collection;
        }

        /// <summary>
        /// Adds the specified <paramref name="descriptor"/> to the <paramref name="collection"/> if the
        /// service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptor">The <see cref="ServiceDescriptor"/> to add.</param>
        public static void TryAdd(
            this IServiceCollection collection,
            ServiceDescriptor descriptor)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(descriptor);

            int count = collection.Count;
            for (int i = 0; i < count; i++)
            {
                if (collection[i].ServiceType == descriptor.ServiceType
                    && collection[i].ServiceKey == descriptor.ServiceKey)
                {
                    // Already added
                    return;
                }
            }

            collection.Add(descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="descriptors"/> to the <paramref name="collection"/> if the
        /// service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptors">The <see cref="ServiceDescriptor"/>s to add.</param>
        public static void TryAdd(
            this IServiceCollection collection,
            IEnumerable<ServiceDescriptor> descriptors)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(descriptors);

            foreach (ServiceDescriptor? d in descriptors)
            {
                collection.TryAdd(d);
            }
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        public static void TryAddTransient(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.Transient(service, service);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddTransient(
            this IServiceCollection collection,
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.Transient(service, implementationType);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddTransient(
            this IServiceCollection collection,
            Type service,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.Transient(service, implementationFactory);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddTransient<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddTransient(collection, typeof(TService), typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddTransient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddTransient(collection, typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddTransient<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.Transient(implementationFactory));
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        public static void TryAddScoped(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.Scoped(service, service);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddScoped(
            this IServiceCollection collection,
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.Scoped(service, implementationType);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddScoped(
            this IServiceCollection collection,
            Type service,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.Scoped(service, implementationFactory);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddScoped<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddScoped(collection, typeof(TService), typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddScoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddScoped(collection, typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddScoped<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.Scoped(implementationFactory));
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        public static void TryAddSingleton(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.Singleton(service, service);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddSingleton(
            this IServiceCollection collection,
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.Singleton(service, implementationType);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddSingleton(
            this IServiceCollection collection,
            Type service,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.Singleton(service, implementationFactory);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddSingleton<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddSingleton(collection, typeof(TService), typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        public static void TryAddSingleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddSingleton(collection, typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// with an instance specified in <paramref name="instance"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="instance">The instance of the service to add.</param>
        public static void TryAddSingleton<TService>(this IServiceCollection collection, TService instance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(instance);

            var descriptor = ServiceDescriptor.Singleton(serviceType: typeof(TService), implementationInstance: instance);
            TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddSingleton<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.Singleton(implementationFactory));
        }

        /// <summary>
        /// Adds a <see cref="ServiceDescriptor"/> if an existing descriptor with the same
        /// <see cref="ServiceDescriptor.ServiceType"/> and an implementation that does not already exist
        /// in <paramref name="services."/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptor">The <see cref="ServiceDescriptor"/>.</param>
        /// <remarks>
        /// Use <see cref="TryAddEnumerable(IServiceCollection, ServiceDescriptor)"/> when registering a service implementation of a
        /// service type that
        /// supports multiple registrations of the same service type. Using
        /// <see cref="Add(IServiceCollection, ServiceDescriptor)"/> is not idempotent and can add
        /// duplicate
        /// <see cref="ServiceDescriptor"/> instances if called twice. Using
        /// <see cref="TryAddEnumerable(IServiceCollection, ServiceDescriptor)"/> will prevent registration
        /// of multiple implementation types.
        /// </remarks>
        public static void TryAddEnumerable(
            this IServiceCollection services,
            ServiceDescriptor descriptor)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(descriptor);

            Type? implementationType = descriptor.GetImplementationType();

            if (implementationType == typeof(object) ||
                implementationType == descriptor.ServiceType)
            {
                throw new ArgumentException(
                    SR.Format(SR.TryAddIndistinguishableTypeToEnumerable,
                        implementationType,
                        descriptor.ServiceType),
                    nameof(descriptor));
            }

            int count = services.Count;
            for (int i = 0; i < count; i++)
            {
                ServiceDescriptor service = services[i];
                if (service.ServiceType == descriptor.ServiceType &&
                    service.GetImplementationType() == implementationType &&
                    service.ServiceKey == descriptor.ServiceKey)
                {
                    // Already added
                    return;
                }
            }

            services.Add(descriptor);
        }

        /// <summary>
        /// Adds the specified <see cref="ServiceDescriptor"/>s if an existing descriptor with the same
        /// <see cref="ServiceDescriptor.ServiceType"/> and an implementation that does not already exist
        /// in <paramref name="services."/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptors">The <see cref="ServiceDescriptor"/>s.</param>
        /// <remarks>
        /// Use <see cref="TryAddEnumerable(IServiceCollection, ServiceDescriptor)"/> when registering a service
        /// implementation of a service type that
        /// supports multiple registrations of the same service type. Using
        /// <see cref="Add(IServiceCollection, ServiceDescriptor)"/> is not idempotent and can add
        /// duplicate
        /// <see cref="ServiceDescriptor"/> instances if called twice. Using
        /// <see cref="TryAddEnumerable(IServiceCollection, ServiceDescriptor)"/> will prevent registration
        /// of multiple implementation types.
        /// </remarks>
        public static void TryAddEnumerable(
            this IServiceCollection services,
            IEnumerable<ServiceDescriptor> descriptors)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(descriptors);

            foreach (ServiceDescriptor? d in descriptors)
            {
                services.TryAddEnumerable(d);
            }
        }

        /// <summary>
        /// Removes the first service in <see cref="IServiceCollection"/> with the same service type
        /// as <paramref name="descriptor"/> and adds <paramref name="descriptor"/> to the collection.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="descriptor">The <see cref="ServiceDescriptor"/> to replace with.</param>
        /// <returns>The <see cref="IServiceCollection"/> for chaining.</returns>
        public static IServiceCollection Replace(
            this IServiceCollection collection,
            ServiceDescriptor descriptor)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(descriptor);

            // Remove existing
            int count = collection.Count;
            for (int i = 0; i < count; i++)
            {
                if (collection[i].ServiceType == descriptor.ServiceType && collection[i].ServiceKey == descriptor.ServiceKey)
                {
                    collection.RemoveAt(i);
                    break;
                }
            }

            collection.Add(descriptor);
            return collection;
        }

        /// <summary>
        /// Removes all services of type <typeparamref name="T"/> in <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <returns>The <see cref="IServiceCollection"/> for chaining.</returns>
        public static IServiceCollection RemoveAll<T>(this IServiceCollection collection)
        {
            return RemoveAll(collection, typeof(T));
        }

        /// <summary>
        /// Removes all services of type <paramref name="serviceType"/> in <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceType">The service type to remove.</param>
        /// <returns>The <see cref="IServiceCollection"/> for chaining.</returns>
        public static IServiceCollection RemoveAll(this IServiceCollection collection, Type serviceType)
        {
            ThrowHelper.ThrowIfNull(serviceType);

            for (int i = collection.Count - 1; i >= 0; i--)
            {
                ServiceDescriptor? descriptor = collection[i];
                if (descriptor.ServiceType == serviceType && descriptor.ServiceKey == null)
                {
                    collection.RemoveAt(i);
                }
            }

            return collection;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/Extensions/ServiceCollectionDescriptorExtensions.Keyed.cs
namespace Microsoft.Extensions.DependencyInjection.Extensions
{
    public static partial class ServiceCollectionDescriptorExtensions
    {
        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedTransient(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.KeyedTransient(service, serviceKey, service);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddKeyedTransient(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.KeyedTransient(service, serviceKey, implementationType);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddKeyedTransient(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.KeyedTransient(service, serviceKey, implementationFactory);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedTransient<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection, object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedTransient(collection, typeof(TService), serviceKey, typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedTransient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection, object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedTransient(collection, typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Transient"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddKeyedTransient<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.KeyedTransient(serviceKey, implementationFactory));
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedScoped(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.KeyedScoped(service, serviceKey, service);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddKeyedScoped(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.KeyedScoped(service, serviceKey, implementationType);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddKeyedScoped(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.KeyedScoped(service, serviceKey, implementationFactory);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedScoped<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection, object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedScoped(collection, typeof(TService), serviceKey, typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedScoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection, object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedScoped(collection, typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Scoped"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedScoped<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.KeyedScoped(serviceKey, implementationFactory));
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedSingleton(
            this IServiceCollection collection,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type service,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);

            var descriptor = ServiceDescriptor.KeyedSingleton(service, serviceKey, service);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// with the <paramref name="implementationType"/> implementation
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        public static void TryAddKeyedSingleton(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            var descriptor = ServiceDescriptor.KeyedSingleton(service, serviceKey, implementationType);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <paramref name="service"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="service">The type of the service to register.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddKeyedSingleton(
            this IServiceCollection collection,
            Type service,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            var descriptor = ServiceDescriptor.KeyedSingleton(service, serviceKey, implementationFactory);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedSingleton<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection collection, object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedSingleton(collection, typeof(TService), serviceKey, typeof(TService));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// implementation type specified in <typeparamref name="TImplementation"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        public static void TryAddKeyedSingleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection collection, object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(collection);

            TryAddKeyedSingleton(collection, typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// with an instance specified in <paramref name="instance"/>
        /// to the <paramref name="collection"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="instance">The instance of the service to add.</param>
        public static void TryAddKeyedSingleton<TService>(this IServiceCollection collection, object? serviceKey, TService instance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(collection);
            ThrowHelper.ThrowIfNull(instance);

            var descriptor = ServiceDescriptor.KeyedSingleton(serviceType: typeof(TService), serviceKey, implementationInstance: instance);
            ServiceCollectionDescriptorExtensions.TryAdd(collection, descriptor);
        }

        /// <summary>
        /// Adds the specified <typeparamref name="TService"/> as a <see cref="ServiceLifetime.Singleton"/> service
        /// using the factory specified in <paramref name="implementationFactory"/>
        /// to the <paramref name="services"/> if the service type hasn't already been registered.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        public static void TryAddKeyedSingleton<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            services.TryAdd(ServiceDescriptor.KeyedSingleton(serviceKey, implementationFactory));
        }

        /// <summary>
        /// Removes all services of type <typeparamref name="T"/> in <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <returns>The <see cref="IServiceCollection"/> for chaining.</returns>
        public static IServiceCollection RemoveAllKeyed<T>(this IServiceCollection collection, object? serviceKey)
        {
            return RemoveAllKeyed(collection, typeof(T), serviceKey);
        }

        /// <summary>
        /// Removes all services of type <paramref name="serviceType"/> in <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="collection">The <see cref="IServiceCollection"/>.</param>
        /// <param name="serviceType">The service type to remove.</param>
        /// <param name="serviceKey">The service key.</param>
        /// <returns>The <see cref="IServiceCollection"/> for chaining.</returns>
        public static IServiceCollection RemoveAllKeyed(this IServiceCollection collection, Type serviceType, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(serviceType);

            for (int i = collection.Count - 1; i >= 0; i--)
            {
                ServiceDescriptor? descriptor = collection[i];
                if (descriptor.ServiceType == serviceType && descriptor.ServiceKey == serviceKey)
                {
                    collection.RemoveAt(i);
                }
            }

            return collection;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/FromKeyedServicesAttribute.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Indicates that the parameter should be bound using the keyed service registered with the specified key.
    /// </summary>
    [AttributeUsage(AttributeTargets.Parameter)]
    public class FromKeyedServicesAttribute : Attribute
    {
        /// <summary>
        /// Creates a new <see cref="FromKeyedServicesAttribute"/> instance.
        /// </summary>
        /// <param name="key">The key of the keyed service to bind to.</param>
        public FromKeyedServicesAttribute(object key) => Key = key;

        /// <summary>
        /// The key of the keyed service to bind to.
        /// </summary>
        public object Key { get; }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IKeyedServiceProvider.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// IKeyedServiceProvider is a service provider that can be used to retrieve services using a key in addition
    /// to a type.
    /// </summary>
    public interface IKeyedServiceProvider : IServiceProvider
    {
        /// <summary>
        /// Gets the service object of the specified type.
        /// </summary>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns> A service object of type serviceType. -or- null if there is no service object of type serviceType.</returns>
        object? GetKeyedService(Type serviceType, object? serviceKey);

        /// <summary>
        /// Gets service of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/> implementing
        /// this interface.
        /// </summary>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A service object of type <paramref name="serviceType"/>.
        /// Throws an exception if the <see cref="IServiceProvider"/> cannot create the object.</returns>
        object GetRequiredKeyedService(Type serviceType, object? serviceKey);
    }

    /// <summary>
    /// Statics for use with <see cref="IKeyedServiceProvider"/>.
    /// </summary>
    public static class KeyedService
    {
        /// <summary>
        /// Represents a key that matches any key.
        /// </summary>
        public static object AnyKey { get; } = new AnyKeyObj();

        private sealed class AnyKeyObj
        {
            public override string? ToString() => "*";
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceCollection.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Specifies the contract for a collection of service descriptors.
    /// </summary>
    public interface IServiceCollection : IList<ServiceDescriptor>
    {
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceProviderFactory.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Provides an extension point for creating a container specific builder and an <see cref="IServiceProvider"/>.
    /// </summary>
    public interface IServiceProviderFactory<TContainerBuilder> where TContainerBuilder : notnull
    {
        /// <summary>
        /// Creates a container builder from an <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The collection of services</param>
        /// <returns>A container builder that can be used to create an <see cref="IServiceProvider"/>.</returns>
        TContainerBuilder CreateBuilder(IServiceCollection services);

        /// <summary>
        /// Creates an <see cref="IServiceProvider"/> from the container builder.
        /// </summary>
        /// <param name="containerBuilder">The container builder</param>
        /// <returns>An <see cref="IServiceProvider"/></returns>
        IServiceProvider CreateServiceProvider(TContainerBuilder containerBuilder);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceProviderIsKeyedService.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Optional service used to determine if the specified type with the specified service key is available
    /// from the <see cref="IServiceProvider"/>.
    /// </summary>
    public interface IServiceProviderIsKeyedService : IServiceProviderIsService
    {
        /// <summary>
        /// Determines if the specified service type with the specified service key is available from the
        /// <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="serviceType">An object that specifies the type of service object to test.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>true if the specified service is a available, false if it is not.</returns>
        bool IsKeyedService(Type serviceType, object? serviceKey);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceProviderIsService.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Optional service used to determine if the specified type is available from the <see cref="IServiceProvider"/>.
    /// </summary>
    public interface IServiceProviderIsService
    {
        /// <summary>
        /// Determines if the specified service type is available from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="serviceType">An object that specifies the type of service object to test.</param>
        /// <returns>true if the specified service is a available, false if it is not.</returns>
        bool IsService(Type serviceType);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceScope.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// The <see cref="System.IDisposable.Dispose"/> method ends the scope lifetime. Once Dispose
    /// is called, any scoped services that have been resolved from
    /// <see cref="Microsoft.Extensions.DependencyInjection.IServiceScope.ServiceProvider"/> will be
    /// disposed.
    /// </summary>
    public interface IServiceScope : IDisposable
    {
        /// <summary>
        /// The <see cref="System.IServiceProvider"/> used to resolve dependencies from the scope.
        /// </summary>
        IServiceProvider ServiceProvider { get; }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/IServiceScopeFactory.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// A factory for creating instances of <see cref="IServiceScope"/>, which is used to create
    /// services within a scope.
    /// </summary>
    public interface IServiceScopeFactory
    {
        /// <summary>
        /// Create an <see cref="Microsoft.Extensions.DependencyInjection.IServiceScope"/> which
        /// contains an <see cref="System.IServiceProvider"/> used to resolve dependencies from a
        /// newly created scope.
        /// </summary>
        /// <returns>
        /// An <see cref="Microsoft.Extensions.DependencyInjection.IServiceScope"/> controlling the
        /// lifetime of the scope. Once this is disposed, any scoped services that have been resolved
        /// from the <see cref="Microsoft.Extensions.DependencyInjection.IServiceScope.ServiceProvider"/>
        /// will also be disposed.
        /// </returns>
        IServiceScope CreateScope();
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ISupportRequiredService.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Optional contract used by <see cref="ServiceProviderServiceExtensions.GetRequiredService{T}(IServiceProvider)"/>
    /// to resolve services if supported by <see cref="IServiceProvider"/>.
    /// </summary>
    public interface ISupportRequiredService
    {
        /// <summary>
        /// Gets service of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/> implementing
        /// this interface.
        /// </summary>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <returns>A service object of type <paramref name="serviceType"/>.
        /// Throws an exception if the <see cref="IServiceProvider"/> cannot create the object.</returns>
        object GetRequiredService(Type serviceType);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ObjectFactory.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// The result of <see cref="ActivatorUtilities.CreateFactory(Type, Type[])"/>.
    /// </summary>
    /// <param name="serviceProvider">The <see cref="IServiceProvider"/> to get service arguments from.</param>
    /// <param name="arguments">Additional constructor arguments.</param>
    /// <returns>The instantiated type.</returns>
    public delegate object ObjectFactory(IServiceProvider serviceProvider, object?[]? arguments);
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ObjectFactoryT.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// The result of <see cref="ActivatorUtilities.CreateFactory{T}"/>. A delegate to specify a factory method to call to instantiate an instance of type `T`
    /// </summary>
    /// <typeparam name="T">The type of the instance being returned</typeparam>
    /// <param name="serviceProvider">The <see cref="IServiceProvider"/> to get service arguments from.</param>
    /// <param name="arguments">Additional constructor arguments.</param>
    /// <returns>An instance of T</returns>
    public delegate T ObjectFactory<T>(IServiceProvider serviceProvider, object?[]? arguments);
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceCollection.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Default implementation of <see cref="IServiceCollection"/>.
    /// </summary>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    [DebuggerTypeProxy(typeof(ServiceCollectionDebugView))]
    public class ServiceCollection : IServiceCollection
    {
        private readonly List<ServiceDescriptor> _descriptors = new List<ServiceDescriptor>();
        private bool _isReadOnly;

        /// <inheritdoc />
        public int Count => _descriptors.Count;

        /// <inheritdoc />
        public bool IsReadOnly => _isReadOnly;

        /// <inheritdoc />
        public ServiceDescriptor this[int index]
        {
            get
            {
                return _descriptors[index];
            }
            set
            {
                CheckReadOnly();
                _descriptors[index] = value;
            }
        }

        /// <inheritdoc />
        public void Clear()
        {
            CheckReadOnly();
            _descriptors.Clear();
        }

        /// <inheritdoc />
        public bool Contains(ServiceDescriptor item)
        {
            return _descriptors.Contains(item);
        }

        /// <inheritdoc />
        public void CopyTo(ServiceDescriptor[] array, int arrayIndex)
        {
            _descriptors.CopyTo(array, arrayIndex);
        }

        /// <inheritdoc />
        public bool Remove(ServiceDescriptor item)
        {
            CheckReadOnly();
            return _descriptors.Remove(item);
        }

        /// <inheritdoc />
        public IEnumerator<ServiceDescriptor> GetEnumerator()
        {
            return _descriptors.GetEnumerator();
        }

        void ICollection<ServiceDescriptor>.Add(ServiceDescriptor item)
        {
            CheckReadOnly();
            _descriptors.Add(item);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        /// <inheritdoc />
        public int IndexOf(ServiceDescriptor item)
        {
            return _descriptors.IndexOf(item);
        }

        /// <inheritdoc />
        public void Insert(int index, ServiceDescriptor item)
        {
            CheckReadOnly();
            _descriptors.Insert(index, item);
        }

        /// <inheritdoc />
        public void RemoveAt(int index)
        {
            CheckReadOnly();
            _descriptors.RemoveAt(index);
        }

        /// <summary>
        /// Makes this collection read-only.
        /// </summary>
        /// <remarks>
        /// After the collection is marked as read-only, any further attempt to modify it throws an <see cref="InvalidOperationException" />.
        /// </remarks>
        public void MakeReadOnly()
        {
            _isReadOnly = true;
        }

        private void CheckReadOnly()
        {
            if (_isReadOnly)
            {
                ThrowReadOnlyException();
            }
        }

        private static void ThrowReadOnlyException() =>
            throw new InvalidOperationException(SR.ServiceCollectionReadOnly);

        private string DebuggerToString()
        {
            string debugText = $"Count = {_descriptors.Count}";
            if (_isReadOnly)
            {
                debugText += $", IsReadOnly = true";
            }
            return debugText;
        }

        private sealed class ServiceCollectionDebugView
        {
            private readonly ServiceCollection _services;

            public ServiceCollectionDebugView(ServiceCollection services)
            {
                _services = services;
            }

            [DebuggerBrowsable(DebuggerBrowsableState.RootHidden)]
            public ServiceDescriptor[] Items
            {
                get
                {
                    ServiceDescriptor[] items = new ServiceDescriptor[_services.Count];
                    _services.CopyTo(items, 0);
                    return items;
                }
            }
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceCollectionServiceExtensions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for adding services to an <see cref="IServiceCollection" />.
    /// </summary>
    public static partial class ServiceCollectionServiceExtensions
    {
        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient(
            this IServiceCollection services,
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return Add(services, serviceType, implementationType, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient(
            this IServiceCollection services,
            Type serviceType,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Add(services, serviceType, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection services)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddTransient(typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddTransient(serviceType, serviceType);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection services)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddTransient(typeof(TService));
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddTransient(typeof(TService), implementationFactory);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddTransient<TService, TImplementation>(
            this IServiceCollection services,
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddTransient(typeof(TService), implementationFactory);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped(
            this IServiceCollection services,
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return Add(services, serviceType, implementationType, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped(
            this IServiceCollection services,
            Type serviceType,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Add(services, serviceType, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection services)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddScoped(typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddScoped(serviceType, serviceType);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection services)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddScoped(typeof(TService));
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddScoped(typeof(TService), implementationFactory);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddScoped<TService, TImplementation>(
            this IServiceCollection services,
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddScoped(typeof(TService), implementationFactory);
        }


        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton(
            this IServiceCollection services,
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return Add(services, serviceType, implementationType, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton(
            this IServiceCollection services,
            Type serviceType,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Add(services, serviceType, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(this IServiceCollection services)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddSingleton(typeof(TService), typeof(TImplementation));
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddSingleton(serviceType, serviceType);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(this IServiceCollection services)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddSingleton(typeof(TService));
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton<TService>(
            this IServiceCollection services,
            Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddSingleton(typeof(TService), implementationFactory);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton<TService, TImplementation>(
            this IServiceCollection services,
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddSingleton(typeof(TService), implementationFactory);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with an
        /// instance specified in <paramref name="implementationInstance"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="implementationInstance">The instance of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton(
            this IServiceCollection services,
            Type serviceType,
            object implementationInstance)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationInstance);

            var serviceDescriptor = new ServiceDescriptor(serviceType, implementationInstance);
            services.Add(serviceDescriptor);
            return services;
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService" /> with an
        /// instance specified in <paramref name="implementationInstance"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="implementationInstance">The instance of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddSingleton<TService>(
            this IServiceCollection services,
            TService implementationInstance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationInstance);

            return services.AddSingleton(typeof(TService), implementationInstance);
        }

        private static IServiceCollection Add(
            IServiceCollection collection,
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
        {
            var descriptor = new ServiceDescriptor(serviceType, implementationType, lifetime);
            collection.Add(descriptor);
            return collection;
        }

        private static IServiceCollection Add(
            IServiceCollection collection,
            Type serviceType,
            Func<IServiceProvider, object> implementationFactory,
            ServiceLifetime lifetime)
        {
            var descriptor = new ServiceDescriptor(serviceType, implementationFactory, lifetime);
            collection.Add(descriptor);
            return collection;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceCollectionServiceExtensions.Keyed.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for adding services to an <see cref="IServiceCollection" />.
    /// </summary>
    public static partial class ServiceCollectionServiceExtensions
    {
        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return AddKeyed(services, serviceType, serviceKey, implementationType, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return AddKeyed(services, serviceType, serviceKey, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedTransient(typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds a transient service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddKeyedTransient(serviceType, serviceKey, serviceType);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedTransient(typeof(TService), serviceKey);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedTransient(typeof(TService), serviceKey, implementationFactory);
        }

        /// <summary>
        /// Adds a transient service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Transient"/>
        public static IServiceCollection AddKeyedTransient<TService, TImplementation>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedTransient(typeof(TService), serviceKey, implementationFactory);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return AddKeyed(services, serviceType, serviceKey, implementationType, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return AddKeyed(services, serviceType, serviceKey, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedScoped(typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddKeyedScoped(serviceType, serviceKey, serviceType);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedScoped(typeof(TService), serviceKey);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedScoped(typeof(TService), serviceKey, implementationFactory);
        }

        /// <summary>
        /// Adds a scoped service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Scoped"/>
        public static IServiceCollection AddKeyedScoped<TService, TImplementation>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedScoped(typeof(TService), serviceKey, implementationFactory);
        }


        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with an
        /// implementation of the type specified in <paramref name="implementationType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The implementation type of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            return AddKeyed(services, serviceType, serviceKey, implementationType, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return AddKeyed(services, serviceType, serviceKey, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedSingleton(typeof(TService), serviceKey, typeof(TImplementation));
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register and the implementation to use.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton(
            this IServiceCollection services,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type serviceType,
            object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);

            return services.AddKeyedSingleton(serviceType, serviceKey, serviceType);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton<[DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TService>(
            this IServiceCollection services,
            object? serviceKey)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);

            return services.AddKeyedSingleton(typeof(TService), serviceKey, typeof(TService));
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with a
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton<TService>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedSingleton(typeof(TService), serviceKey, implementationFactory);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService"/> with an
        /// implementation type specified in <typeparamref name="TImplementation" /> using the
        /// factory specified in <paramref name="implementationFactory"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <typeparam name="TService">The type of the service to add.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation to use.</typeparam>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">The factory that creates the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton<TService, TImplementation>(
            this IServiceCollection services,
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return services.AddKeyedSingleton(typeof(TService), serviceKey, implementationFactory);
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <paramref name="serviceType"/> with an
        /// instance specified in <paramref name="implementationInstance"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceType">The type of the service to register.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationInstance">The instance of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton(
            this IServiceCollection services,
            Type serviceType,
            object? serviceKey,
            object implementationInstance)
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationInstance);

            var serviceDescriptor = new ServiceDescriptor(serviceType, serviceKey, implementationInstance);
            services.Add(serviceDescriptor);
            return services;
        }

        /// <summary>
        /// Adds a singleton service of the type specified in <typeparamref name="TService" /> with an
        /// instance specified in <paramref name="implementationInstance"/> to the
        /// specified <see cref="IServiceCollection"/>.
        /// </summary>
        /// <param name="services">The <see cref="IServiceCollection"/> to add the service to.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationInstance">The instance of the service.</param>
        /// <returns>A reference to this instance after the operation has completed.</returns>
        /// <seealso cref="ServiceLifetime.Singleton"/>
        public static IServiceCollection AddKeyedSingleton<TService>(
            this IServiceCollection services,
            object? serviceKey,
            TService implementationInstance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(services);
            ThrowHelper.ThrowIfNull(implementationInstance);

            return services.AddKeyedSingleton(typeof(TService), serviceKey, implementationInstance);
        }

        private static IServiceCollection AddKeyed(
            IServiceCollection collection,
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
        {
            var descriptor = new ServiceDescriptor(serviceType, serviceKey, implementationType, lifetime);
            collection.Add(descriptor);
            return collection;
        }

        private static IServiceCollection AddKeyed(
            IServiceCollection collection,
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory,
            ServiceLifetime lifetime)
        {
            var descriptor = new ServiceDescriptor(serviceType, serviceKey, implementationFactory, lifetime);
            collection.Add(descriptor);
            return collection;
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceDescriptor.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Describes a service with its service type, implementation, and lifetime.
    /// </summary>
    [DebuggerDisplay("{DebuggerToString(),nq}")]
    public class ServiceDescriptor
    {
        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="implementationType"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="implementationType">The <see cref="Type"/> implementing the service.</param>
        /// <param name="lifetime">The <see cref="ServiceLifetime"/> of the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
            : this(serviceType, null, implementationType, lifetime)
        {
        }

        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="implementationType"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The <see cref="Type"/> implementing the service.</param>
        /// <param name="lifetime">The <see cref="ServiceLifetime"/> of the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
            : this(serviceType, serviceKey, lifetime)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationType);

            _implementationType = implementationType;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="instance"/>
        /// as a <see cref="ServiceLifetime.Singleton"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="instance">The instance implementing the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            object instance)
            : this(serviceType, null, instance)
        {
        }

        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="instance"/>
        /// as a <see cref="ServiceLifetime.Singleton"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="instance">The instance implementing the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            object? serviceKey,
            object instance)
            : this(serviceType, serviceKey, ServiceLifetime.Singleton)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(instance);

            _implementationInstance = instance;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="factory"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="factory">A factory used for creating service instances.</param>
        /// <param name="lifetime">The <see cref="ServiceLifetime"/> of the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            Func<IServiceProvider, object> factory,
            ServiceLifetime lifetime)
            : this(serviceType, serviceKey: null, lifetime)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(factory);

            _implementationFactory = factory;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="ServiceDescriptor"/> with the specified <paramref name="factory"/>.
        /// </summary>
        /// <param name="serviceType">The <see cref="Type"/> of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="factory">A factory used for creating service instances.</param>
        /// <param name="lifetime">The <see cref="ServiceLifetime"/> of the service.</param>
        public ServiceDescriptor(
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> factory,
            ServiceLifetime lifetime)
            : this(serviceType, serviceKey, lifetime)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(factory);

            if (serviceKey is null)
            {
                // If the key is null, use the same factory signature as non-keyed descriptor
                Func<IServiceProvider, object> nullKeyedFactory = sp => factory(sp, null);
                _implementationFactory = nullKeyedFactory;
            }
            else
            {
                _implementationFactory = factory;
            }
        }

        private ServiceDescriptor(Type serviceType, object? serviceKey, ServiceLifetime lifetime)
        {
            Lifetime = lifetime;
            ServiceType = serviceType;
            ServiceKey = serviceKey;
        }

        /// <summary>
        /// Gets the <see cref="ServiceLifetime"/> of the service.
        /// </summary>
        public ServiceLifetime Lifetime { get; }

        /// <summary>
        /// Get the key of the service, if applicable.
        /// </summary>
        public object? ServiceKey { get; }

        /// <summary>
        /// Gets the <see cref="Type"/> of the service.
        /// </summary>
        public Type ServiceType { get; }

        [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)]
        private Type? _implementationType;

        /// <summary>
        /// Gets the <see cref="Type"/> that implements the service.
        /// </summary>
        [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)]
        public Type? ImplementationType
        {
            get
            {
                if (IsKeyedService)
                {
                    ThrowKeyedDescriptor();
                }
                return _implementationType;
            }
        }

        /// <summary>
        /// Gets the <see cref="Type"/> that implements the service.
        /// </summary>
        [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)]
        public Type? KeyedImplementationType
        {
            get
            {
                if (!IsKeyedService)
                {
                    ThrowNonKeyedDescriptor();
                }
                return _implementationType;
            }
        }

        private object? _implementationInstance;

        /// <summary>
        /// Gets the instance that implements the service.
        /// </summary>
        public object? ImplementationInstance
        {
            get
            {
                if (IsKeyedService)
                {
                    ThrowKeyedDescriptor();
                }
                return _implementationInstance;
            }
        }

        /// <summary>
        /// Gets the instance that implements the service.
        /// </summary>
        public object? KeyedImplementationInstance
        {
            get
            {
                if (!IsKeyedService)
                {
                    ThrowNonKeyedDescriptor();
                }
                return _implementationInstance;
            }
        }

        private object? _implementationFactory;

        /// <summary>
        /// Gets the factory used for creating service instances.
        /// </summary>
        public Func<IServiceProvider, object>? ImplementationFactory
        {
            get
            {
                if (IsKeyedService)
                {
                    ThrowKeyedDescriptor();
                }
                return (Func<IServiceProvider, object>?) _implementationFactory;
            }
        }

        /// <summary>
        /// Gets the factory used for creating Keyed service instances.
        /// </summary>
        public Func<IServiceProvider, object?, object>? KeyedImplementationFactory
        {
            get
            {
                if (!IsKeyedService)
                {
                    ThrowNonKeyedDescriptor();
                }
                return (Func<IServiceProvider, object?, object>?) _implementationFactory;
            }
        }

        /// <summary>
        /// Indicates whether the service is a keyed service.
        /// </summary>
        public bool IsKeyedService => ServiceKey != null;

        /// <inheritdoc />
        public override string ToString()
        {
            string? lifetime = $"{nameof(ServiceType)}: {ServiceType} {nameof(Lifetime)}: {Lifetime} ";

            if (IsKeyedService)
            {
                lifetime += $"{nameof(ServiceKey)}: {ServiceKey} ";

                if (KeyedImplementationType != null)
                {
                    return lifetime + $"{nameof(KeyedImplementationType)}: {KeyedImplementationType}";
                }

                if (KeyedImplementationFactory != null)
                {
                    return lifetime + $"{nameof(KeyedImplementationFactory)}: {KeyedImplementationFactory.Method}";
                }

                return lifetime + $"{nameof(KeyedImplementationInstance)}: {KeyedImplementationInstance}";
            }
            else
            {
                if (ImplementationType != null)
                {
                    return lifetime + $"{nameof(ImplementationType)}: {ImplementationType}";
                }

                if (ImplementationFactory != null)
                {
                    return lifetime + $"{nameof(ImplementationFactory)}: {ImplementationFactory.Method}";
                }

                return lifetime + $"{nameof(ImplementationInstance)}: {ImplementationInstance}";
            }
        }

        internal Type GetImplementationType()
        {
            if (ServiceKey == null)
            {
                if (ImplementationType != null)
                {
                    return ImplementationType;
                }
                else if (ImplementationInstance != null)
                {
                    return ImplementationInstance.GetType();
                }
                else if (ImplementationFactory != null)
                {
                    Type[]? typeArguments = ImplementationFactory.GetType().GenericTypeArguments;

                    Debug.Assert(typeArguments.Length == 2);

                    return typeArguments[1];
                }
            }
            else
            {
                if (KeyedImplementationType != null)
                {
                    return KeyedImplementationType;
                }
                else if (KeyedImplementationInstance != null)
                {
                    return KeyedImplementationInstance.GetType();
                }
                else if (KeyedImplementationFactory != null)
                {
                    Type[]? typeArguments = KeyedImplementationFactory.GetType().GenericTypeArguments;

                    Debug.Assert(typeArguments.Length == 3);

                    return typeArguments[2];
                }
            }

            Debug.Assert(false, "ImplementationType, ImplementationInstance, ImplementationFactory or KeyedImplementationFactory must be non null");
            return null;
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Transient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>()
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(null, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedTransient<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(serviceKey, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Transient(
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            return Describe(service, implementationType, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedTransient(
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            return DescribeKeyed(service, serviceKey, implementationType, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Transient<TService, TImplementation>(
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedTransient<TService, TImplementation>(
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Transient<TService>(Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedTransient<TService>(object? serviceKey, Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Transient(Type service, Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(service, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Transient"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedTransient(Type service, object? serviceKey, Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(service, serviceKey, implementationFactory, ServiceLifetime.Transient);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Scoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>()
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(null, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedScoped<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(serviceKey, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Scoped(
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            return Describe(service, implementationType, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedScoped(
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            return DescribeKeyed(service, serviceKey, implementationType, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Scoped<TService, TImplementation>(
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedScoped<TService, TImplementation>(
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Scoped<TService>(Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedScoped<TService>(object? serviceKey, Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Scoped(Type service, Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(service, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Scoped"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedScoped(Type service, object? serviceKey, Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(service, serviceKey, implementationFactory, ServiceLifetime.Scoped);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>()
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(null, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(
            object? serviceKey)
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed<TService, TImplementation>(serviceKey, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton(
            Type service,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            return Describe(service, implementationType, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="service"/> and <paramref name="implementationType"/>
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="service">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton(
            Type service,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType)
        {
            ThrowHelper.ThrowIfNull(service);
            ThrowHelper.ThrowIfNull(implementationType);

            return DescribeKeyed(service, serviceKey, implementationType, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton<TService, TImplementation>(
            Func<IServiceProvider, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <typeparamref name="TImplementation"/>,
        /// <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <typeparam name="TImplementation">The type of the implementation.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton<TService, TImplementation>(
            object? serviceKey,
            Func<IServiceProvider, object?, TImplementation> implementationFactory)
            where TService : class
            where TImplementation : class, TService
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton<TService>(Func<IServiceProvider, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(typeof(TService), implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton<TService>(
            object? serviceKey,
            Func<IServiceProvider, object?, TService> implementationFactory)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(typeof(TService), serviceKey, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton(
            Type serviceType,
            Func<IServiceProvider, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return Describe(serviceType, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationFactory"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton(
            Type serviceType,
            object? serviceKey,
            Func<IServiceProvider, object?, object> implementationFactory)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationFactory);

            return DescribeKeyed(serviceType, serviceKey, implementationFactory, ServiceLifetime.Singleton);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationInstance"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="implementationInstance">The instance of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton<TService>(TService implementationInstance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationInstance);

            return Singleton(serviceType: typeof(TService), implementationInstance: implementationInstance);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <typeparamref name="TService"/>, <paramref name="implementationInstance"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <typeparam name="TService">The type of the service.</typeparam>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationInstance">The instance of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton<TService>(
            object? serviceKey,
            TService implementationInstance)
            where TService : class
        {
            ThrowHelper.ThrowIfNull(implementationInstance);

            return KeyedSingleton(typeof(TService), serviceKey, implementationInstance);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationInstance"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="implementationInstance">The instance of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Singleton(
            Type serviceType,
            object implementationInstance)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationInstance);

            return new ServiceDescriptor(serviceType, implementationInstance);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationInstance"/>,
        /// and the <see cref="ServiceLifetime.Singleton"/> lifetime.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationInstance">The instance of the implementation.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor KeyedSingleton(
            Type serviceType,
            object? serviceKey,
            object implementationInstance)
        {
            ThrowHelper.ThrowIfNull(serviceType);
            ThrowHelper.ThrowIfNull(implementationInstance);

            return new ServiceDescriptor(serviceType, serviceKey, implementationInstance);
        }

        private static ServiceDescriptor DescribeKeyed<TService, [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] TImplementation>(
            object? serviceKey,
            ServiceLifetime lifetime)
            where TService : class
            where TImplementation : class, TService
        {
            return DescribeKeyed(
                typeof(TService),
                serviceKey,
                typeof(TImplementation),
                lifetime: lifetime);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationType"/>,
        /// and <paramref name="lifetime"/>.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <param name="lifetime">The lifetime of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Describe(
            Type serviceType,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
        {
            return new ServiceDescriptor(serviceType, implementationType, lifetime);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationType"/>,
        /// and <paramref name="lifetime"/>.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationType">The type of the implementation.</param>
        /// <param name="lifetime">The lifetime of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor DescribeKeyed(
            Type serviceType,
            object? serviceKey,
            [DynamicallyAccessedMembers(DynamicallyAccessedMemberTypes.PublicConstructors)] Type implementationType,
            ServiceLifetime lifetime)
        {
            return new ServiceDescriptor(serviceType, serviceKey, implementationType, lifetime);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationFactory"/>,
        /// and <paramref name="lifetime"/>.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <param name="lifetime">The lifetime of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor Describe(Type serviceType, Func<IServiceProvider, object> implementationFactory, ServiceLifetime lifetime)
        {
            return new ServiceDescriptor(serviceType, implementationFactory, lifetime);
        }

        /// <summary>
        /// Creates an instance of <see cref="ServiceDescriptor"/> with the specified
        /// <paramref name="serviceType"/>, <paramref name="implementationFactory"/>,
        /// and <paramref name="lifetime"/>.
        /// </summary>
        /// <param name="serviceType">The type of the service.</param>
        /// <param name="serviceKey">The <see cref="ServiceDescriptor.ServiceKey"/> of the service.</param>
        /// <param name="implementationFactory">A factory to create new instances of the service implementation.</param>
        /// <param name="lifetime">The lifetime of the service.</param>
        /// <returns>A new instance of <see cref="ServiceDescriptor"/>.</returns>
        public static ServiceDescriptor DescribeKeyed(Type serviceType, object? serviceKey, Func<IServiceProvider, object?, object> implementationFactory, ServiceLifetime lifetime)
        {
            return new ServiceDescriptor(serviceType, serviceKey, implementationFactory, lifetime);
        }

        private string DebuggerToString()
        {
            string debugText = $@"Lifetime = {Lifetime}, ServiceType = ""{ServiceType.FullName}""";

            // Either implementation type, factory or instance is set.
            if (IsKeyedService)
            {
                debugText += $@", ServiceKey = ""{ServiceKey}""";
                if (KeyedImplementationType != null)
                {
                    debugText += $@", KeyedImplementationType = ""{KeyedImplementationType.FullName}""";
                }
                else if (KeyedImplementationFactory != null)
                {
                    debugText += $@", KeyedImplementationFactory = {KeyedImplementationFactory.Method}";
                }
                else
                {
                    debugText += $@", KeyedImplementationInstance = {KeyedImplementationInstance}";
                }
            }
            else
            {
                if (ImplementationType != null)
                {
                    debugText += $@", ImplementationType = ""{ImplementationType.FullName}""";
                }
                else if (ImplementationFactory != null)
                {
                    debugText += $@", ImplementationFactory = {ImplementationFactory.Method}";
                }
                else
                {
                    debugText += $@", ImplementationInstance = {ImplementationInstance}";
                }
            }

            return debugText;
        }

        private static void ThrowKeyedDescriptor() => throw new InvalidOperationException(SR.KeyedDescriptorMisuse);

        private static void ThrowNonKeyedDescriptor() => throw new InvalidOperationException(SR.NonKeyedDescriptorMisuse);
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceKeyAttribute.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// ServiceKeyAttribute can be specified on a parameter to inject the key that was used for
    /// registration/resolution.
    /// </summary>
    [AttributeUsage(AttributeTargets.Parameter)]
    public class ServiceKeyAttribute : Attribute
    {
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceLifetime.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Specifies the lifetime of a service in an <see cref="IServiceCollection"/>.
    /// </summary>
    public enum ServiceLifetime
    {
        /// <summary>
        /// Specifies that a single instance of the service will be created.
        /// </summary>
        Singleton,
        /// <summary>
        /// Specifies that a new instance of the service will be created for each scope.
        /// </summary>
        /// <remarks>
        /// In ASP.NET Core applications a scope is created around each server request.
        /// </remarks>
        Scoped,
        /// <summary>
        /// Specifies that a new instance of the service will be created every time it is requested.
        /// </summary>
        Transient
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceProviderKeyedServiceExtensions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for getting services from an <see cref="IServiceProvider" />.
    /// </summary>
    public static class ServiceProviderKeyedServiceExtensions
    {
        /// <summary>
        /// Get service of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns>A service object of type <typeparamref name="T"/> or null if there is no such service.</returns>
        public static T? GetKeyedService<T>(this IServiceProvider provider, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(provider);

            if (provider is IKeyedServiceProvider keyedServiceProvider)
            {
                return (T?)keyedServiceProvider.GetKeyedService(typeof(T), serviceKey);
            }

            throw new InvalidOperationException(SR.KeyedServicesNotSupported);
        }

        /// <summary>
        /// Get service of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns>A service object of type <paramref name="serviceType"/>.</returns>
        /// <exception cref="System.InvalidOperationException">There is no service of type <paramref name="serviceType"/>.</exception>
        public static object GetRequiredKeyedService(this IServiceProvider provider, Type serviceType, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(provider);
            ThrowHelper.ThrowIfNull(serviceType);

            if (provider is IKeyedServiceProvider requiredServiceSupportingProvider)
            {
                return requiredServiceSupportingProvider.GetRequiredKeyedService(serviceType, serviceKey);
            }

            throw new InvalidOperationException(SR.KeyedServicesNotSupported);
        }

        /// <summary>
        /// Get service of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns>A service object of type <typeparamref name="T"/>.</returns>
        /// <exception cref="System.InvalidOperationException">There is no service of type <typeparamref name="T"/>.</exception>
        public static T GetRequiredKeyedService<T>(this IServiceProvider provider, object? serviceKey) where T : notnull
        {
            ThrowHelper.ThrowIfNull(provider);

            return (T)provider.GetRequiredKeyedService(typeof(T), serviceKey);
        }

        /// <summary>
        /// Get an enumeration of services of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the services from.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns>An enumeration of services of type <typeparamref name="T"/>.</returns>
        public static IEnumerable<T> GetKeyedServices<T>(this IServiceProvider provider, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(provider);

            return provider.GetRequiredKeyedService<IEnumerable<T>>(serviceKey);
        }

        /// <summary>
        /// Get an enumeration of services of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the services from.</param>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <param name="serviceKey">An object that specifies the key of service object to get.</param>
        /// <returns>An enumeration of services of type <paramref name="serviceType"/>.</returns>
        [RequiresDynamicCode("The native code for an IEnumerable<serviceType> might not be available at runtime.")]
        public static IEnumerable<object?> GetKeyedServices(this IServiceProvider provider, Type serviceType, object? serviceKey)
        {
            ThrowHelper.ThrowIfNull(provider);
            ThrowHelper.ThrowIfNull(serviceType);

            Type? genericEnumerable = typeof(IEnumerable<>).MakeGenericType(serviceType);
            return (IEnumerable<object>)provider.GetRequiredKeyedService(genericEnumerable, serviceKey);
        }
    }
}

// src/libraries/Microsoft.Extensions.DependencyInjection.Abstractions/src/ServiceProviderServiceExtensions.cs
namespace Microsoft.Extensions.DependencyInjection
{
    /// <summary>
    /// Extension methods for getting services from an <see cref="IServiceProvider" />.
    /// </summary>
    public static class ServiceProviderServiceExtensions
    {
        /// <summary>
        /// Get service of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <returns>A service object of type <typeparamref name="T"/> or null if there is no such service.</returns>
        public static T? GetService<T>(this IServiceProvider provider)
        {
            ThrowHelper.ThrowIfNull(provider);

            return (T?)provider.GetService(typeof(T));
        }

        /// <summary>
        /// Get service of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <returns>A service object of type <paramref name="serviceType"/>.</returns>
        /// <exception cref="System.InvalidOperationException">There is no service of type <paramref name="serviceType"/>.</exception>
        public static object GetRequiredService(this IServiceProvider provider, Type serviceType)
        {
            ThrowHelper.ThrowIfNull(provider);
            ThrowHelper.ThrowIfNull(serviceType);

            if (provider is ISupportRequiredService requiredServiceSupportingProvider)
            {
                return requiredServiceSupportingProvider.GetRequiredService(serviceType);
            }

            object? service = provider.GetService(serviceType);
            if (service == null)
            {
                throw new InvalidOperationException(SR.Format(SR.NoServiceRegistered, serviceType));
            }

            return service;
        }

        /// <summary>
        /// Get service of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the service object from.</param>
        /// <returns>A service object of type <typeparamref name="T"/>.</returns>
        /// <exception cref="System.InvalidOperationException">There is no service of type <typeparamref name="T"/>.</exception>
        public static T GetRequiredService<T>(this IServiceProvider provider) where T : notnull
        {
            ThrowHelper.ThrowIfNull(provider);

            return (T)provider.GetRequiredService(typeof(T));
        }

        /// <summary>
        /// Get an enumeration of services of type <typeparamref name="T"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <typeparam name="T">The type of service object to get.</typeparam>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the services from.</param>
        /// <returns>An enumeration of services of type <typeparamref name="T"/>.</returns>
        public static IEnumerable<T> GetServices<T>(this IServiceProvider provider)
        {
            ThrowHelper.ThrowIfNull(provider);

            return provider.GetRequiredService<IEnumerable<T>>();
        }

        /// <summary>
        /// Get an enumeration of services of type <paramref name="serviceType"/> from the <see cref="IServiceProvider"/>.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to retrieve the services from.</param>
        /// <param name="serviceType">An object that specifies the type of service object to get.</param>
        /// <returns>An enumeration of services of type <paramref name="serviceType"/>.</returns>
        [RequiresDynamicCode("The native code for an IEnumerable<serviceType> might not be available at runtime.")]
        public static IEnumerable<object?> GetServices(this IServiceProvider provider, Type serviceType)
        {
            ThrowHelper.ThrowIfNull(provider);
            ThrowHelper.ThrowIfNull(serviceType);

            Type? genericEnumerable = typeof(IEnumerable<>).MakeGenericType(serviceType);
            return (IEnumerable<object>)provider.GetRequiredService(genericEnumerable);
        }

        /// <summary>
        /// Creates a new <see cref="IServiceScope"/> that can be used to resolve scoped services.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to create the scope from.</param>
        /// <returns>A <see cref="IServiceScope"/> that can be used to resolve scoped services.</returns>
        public static IServiceScope CreateScope(this IServiceProvider provider)
        {
            return provider.GetRequiredService<IServiceScopeFactory>().CreateScope();
        }

        /// <summary>
        /// Creates a new <see cref="AsyncServiceScope"/> that can be used to resolve scoped services.
        /// </summary>
        /// <param name="provider">The <see cref="IServiceProvider"/> to create the scope from.</param>
        /// <returns>An <see cref="AsyncServiceScope"/> that can be used to resolve scoped services.</returns>
        public static AsyncServiceScope CreateAsyncScope(this IServiceProvider provider)
        {
            return new AsyncServiceScope(provider.CreateScope());
        }

        /// <summary>
        /// Creates a new <see cref="AsyncServiceScope"/> that can be used to resolve scoped services.
        /// </summary>
        /// <param name="serviceScopeFactory">The <see cref="IServiceScopeFactory"/> to create the scope from.</param>
        /// <returns>An <see cref="AsyncServiceScope"/> that can be used to resolve scoped services.</returns>
        public static AsyncServiceScope CreateAsyncScope(this IServiceScopeFactory serviceScopeFactory)
        {
            return new AsyncServiceScope(serviceScopeFactory.CreateScope());
        }
    }
}

#nullable disable

namespace FxResources.Microsoft.Extensions.DependencyInjection.Abstractions
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
            s_resourceManager ??= new ResourceManager(typeof(FxResources.Microsoft.Extensions.DependencyInjection.Abstractions.SR));

        internal static string AmbiguousConstructorMatch => GetResourceString("AmbiguousConstructorMatch");

        internal static string CannotResolveService => GetResourceString("CannotResolveService");

        internal static string NoConstructorMatch => GetResourceString("NoConstructorMatch");

        internal static string NoServiceRegistered => GetResourceString("NoServiceRegistered");

        internal static string ServiceCollectionReadOnly => GetResourceString("ServiceCollectionReadOnly");

        internal static string TryAddIndistinguishableTypeToEnumerable => GetResourceString("TryAddIndistinguishableTypeToEnumerable");

        internal static string MultipleCtorsMarkedWithAttribute => GetResourceString("MultipleCtorsMarkedWithAttribute");

        internal static string MarkedCtorMissingArgumentTypes => GetResourceString("MarkedCtorMissingArgumentTypes");

        internal static string CannotCreateAbstractClasses => GetResourceString("CannotCreateAbstractClasses");

        internal static string MultipleCtorsFoundWithBestLength => GetResourceString("MultipleCtorsFoundWithBestLength");

        internal static string UnableToResolveService => GetResourceString("UnableToResolveService");

        internal static string CtorNotLocated => GetResourceString("CtorNotLocated");

        internal static string MultipleCtorsFound => GetResourceString("MultipleCtorsFound");

        internal static string KeyedServicesNotSupported => GetResourceString("KeyedServicesNotSupported");

        internal static string KeyedDescriptorMisuse => GetResourceString("KeyedDescriptorMisuse");

        internal static string NonKeyedDescriptorMisuse => GetResourceString("NonKeyedDescriptorMisuse");
    }
}
