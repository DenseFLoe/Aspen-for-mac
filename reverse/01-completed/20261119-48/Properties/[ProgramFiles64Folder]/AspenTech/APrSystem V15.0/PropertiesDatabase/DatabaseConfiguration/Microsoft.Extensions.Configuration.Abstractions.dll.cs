// Derived from .NET Foundation and Contributors code licensed under MIT.
// See LICENSE.TXT and THIRD-PARTY-NOTICES.TXT.
#nullable enable annotations

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using ResourcesMarker = FxResources.Microsoft.Extensions.Configuration.Abstractions.SR;
using Microsoft.Extensions.Primitives;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyDefaultAlias("Microsoft.Extensions.Configuration.Abstractions")]
[assembly: NeutralResourcesLanguage("en-US")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata("IsTrimmable", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyCopyright("© Microsoft Corporation. All rights reserved.")]
[assembly: AssemblyDescription("Provides abstractions of key-value pair based configuration. Interfaces defined in this package are implemented by classes in Microsoft.Extensions.Configuration and other configuration packages.")]
[assembly: AssemblyFileVersion("8.0.23.53103")]
[assembly: AssemblyInformationalVersion("8.0.0+5535e31a712343a63f5d7d796cd874e563e5ac14")]
[assembly: AssemblyProduct("Microsoft® .NET")]
[assembly: AssemblyTitle("Microsoft.Extensions.Configuration.Abstractions")]
[assembly: AssemblyMetadata("RepositoryUrl", "https://github.com/dotnet/runtime")]
[assembly: AssemblyVersion("8.0.0.0")]
// Original module metadata: RefSafetyRules(11). Roslyn emits this attribute.
// Original module metadata: NullablePublicOnly(false). Roslyn controls this attribute.
namespace FxResources.Microsoft.Extensions.Configuration.Abstractions
{
	internal static class SR
	{
	}
}
namespace System
{
	internal static class ThrowHelper
	{
		internal static void ThrowIfNull([NotNull] object argument, [CallerArgumentExpression("argument")] string paramName = null)
		{
			if (argument == null)
			{
				Throw(paramName);
			}
		}

		[DoesNotReturn]
		private static void Throw(string paramName)
		{
			throw new ArgumentNullException(paramName);
		}

		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		[return: NotNull]
		public static string IfNullOrWhitespace([NotNull] string argument, [CallerArgumentExpression("argument")] string paramName = "")
		{
			if (string.IsNullOrWhiteSpace(argument))
			{
				if (argument == null)
				{
					throw new ArgumentNullException(paramName);
				}
				throw new ArgumentException(paramName, "Argument is whitespace");
			}
			return argument;
		}
	}
	internal static class SR
	{
		private static readonly bool s_usingResourceKeys = AppContext.TryGetSwitch("System.Resources.UseSystemResourceKeys", out var isEnabled) && isEnabled;

		private static ResourceManager s_resourceManager;

		internal static ResourceManager ResourceManager => s_resourceManager ?? (s_resourceManager = new ResourceManager(typeof(ResourcesMarker)));

		internal static string InvalidSectionName => GetResourceString("InvalidSectionName");

		internal static bool UsingResourceKeys()
		{
			return s_usingResourceKeys;
		}

		private static string GetResourceString(string resourceKey)
		{
			if (UsingResourceKeys())
			{
				return resourceKey;
			}
			string result = null;
			try
			{
				result = ResourceManager.GetString(resourceKey);
			}
			catch (MissingManifestResourceException)
			{
			}
			return result;
		}

		private static string GetResourceString(string resourceKey, string defaultString)
		{
			string resourceString = GetResourceString(resourceKey);
			if (!(resourceKey == resourceString) && resourceString != null)
			{
				return resourceString;
			}
			return defaultString;
		}

		internal static string Format(string resourceFormat, object p1)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1);
			}
			return string.Format(resourceFormat, p1);
		}

		internal static string Format(string resourceFormat, object p1, object p2)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1, p2);
			}
			return string.Format(resourceFormat, p1, p2);
		}

		internal static string Format(string resourceFormat, object p1, object p2, object p3)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1, p2, p3);
			}
			return string.Format(resourceFormat, p1, p2, p3);
		}

		internal static string Format(string resourceFormat, params object[] args)
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

		internal static string Format(IFormatProvider provider, string resourceFormat, object p1)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1);
			}
			return string.Format(provider, resourceFormat, p1);
		}

		internal static string Format(IFormatProvider provider, string resourceFormat, object p1, object p2)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1, p2);
			}
			return string.Format(provider, resourceFormat, p1, p2);
		}

		internal static string Format(IFormatProvider provider, string resourceFormat, object p1, object p2, object p3)
		{
			if (UsingResourceKeys())
			{
				return string.Join(", ", resourceFormat, p1, p2, p3);
			}
			return string.Format(provider, resourceFormat, p1, p2, p3);
		}

		internal static string Format(IFormatProvider provider, string resourceFormat, params object[] args)
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
namespace Microsoft.Extensions.Configuration
{
	public readonly struct ConfigurationDebugViewContext
	{
		public string Path { get; }

		public string Key { get; }

		public string? Value { get; }

		public IConfigurationProvider ConfigurationProvider { get; }

		public ConfigurationDebugViewContext(string path, string key, string? value, IConfigurationProvider configurationProvider)
		{
			Path = path;
			Key = key;
			Value = value;
			ConfigurationProvider = configurationProvider;
		}
	}
	public static class ConfigurationExtensions
	{
		public static IConfigurationBuilder Add<TSource>(this IConfigurationBuilder builder, Action<TSource>? configureSource) where TSource : IConfigurationSource, new()
		{
			TSource val = new TSource();
			configureSource?.Invoke(val);
			return builder.Add(val);
		}

		public static string? GetConnectionString(this IConfiguration configuration, string name)
		{
			return configuration?.GetSection("ConnectionStrings")[name];
		}

		public static IEnumerable<KeyValuePair<string, string?>> AsEnumerable(this IConfiguration configuration)
		{
			return configuration.AsEnumerable(makePathsRelative: false);
		}

		public static IEnumerable<KeyValuePair<string, string?>> AsEnumerable(this IConfiguration configuration, bool makePathsRelative)
		{
			Stack<IConfiguration> stack = new Stack<IConfiguration>();
			stack.Push(configuration);
			int prefixLength = ((makePathsRelative && configuration is IConfigurationSection configurationSection) ? (configurationSection.Path.Length + 1) : 0);
			while (stack.Count > 0)
			{
				IConfiguration config = stack.Pop();
				if (config is IConfigurationSection configurationSection2 && (!makePathsRelative || config != configuration))
				{
					yield return new KeyValuePair<string, string?>(configurationSection2.Path.Substring(prefixLength), configurationSection2.Value);
				}
				foreach (IConfigurationSection child in config.GetChildren())
				{
					stack.Push(child);
				}
			}
		}

		public static bool Exists([NotNullWhen(true)] this IConfigurationSection? section)
		{
			if (section == null)
			{
				return false;
			}
			if (section.Value == null)
			{
				return section.GetChildren().Any();
			}
			return true;
		}

		public static IConfigurationSection GetRequiredSection(this IConfiguration configuration, string key)
		{
			System.ThrowHelper.ThrowIfNull(configuration, "configuration");
			IConfigurationSection section = configuration.GetSection(key);
			if (section.Exists())
			{
				return section;
			}
			throw new InvalidOperationException(System.SR.Format(System.SR.InvalidSectionName, key));
		}
	}
	[AttributeUsage(AttributeTargets.Property)]
	public sealed class ConfigurationKeyNameAttribute : Attribute
	{
		public string Name { get; }

		public ConfigurationKeyNameAttribute(string name)
		{
			Name = name;
		}
	}
	public static class ConfigurationPath
	{
		public static readonly string KeyDelimiter = ":";

		public static string Combine(params string[] pathSegments)
		{
			System.ThrowHelper.ThrowIfNull(pathSegments, "pathSegments");
			return string.Join(KeyDelimiter, pathSegments);
		}

		public static string Combine(IEnumerable<string> pathSegments)
		{
			System.ThrowHelper.ThrowIfNull(pathSegments, "pathSegments");
			return string.Join(KeyDelimiter, pathSegments);
		}

		[return: NotNullIfNotNull("path")]
		public static string? GetSectionKey(string? path)
		{
			if (string.IsNullOrEmpty(path))
			{
				return path;
			}
			int num = path.LastIndexOf(':');
			if (num >= 0)
			{
				return path.Substring(num + 1);
			}
			return path;
		}

		public static string? GetParentPath(string? path)
		{
			if (string.IsNullOrEmpty(path))
			{
				return null;
			}
			int num = path.LastIndexOf(':');
			if (num >= 0)
			{
				return path.Substring(0, num);
			}
			return null;
		}
	}
	public static class ConfigurationRootExtensions
	{
		public static string GetDebugView(this IConfigurationRoot root)
		{
			return root.GetDebugView(null);
		}

		public static string GetDebugView(this IConfigurationRoot root, Func<ConfigurationDebugViewContext, string>? processValue)
		{
			StringBuilder stringBuilder = new StringBuilder();
			RecurseChildren(stringBuilder, root.GetChildren(), "");
			return stringBuilder.ToString();
			void RecurseChildren(StringBuilder stringBuilder2, IEnumerable<IConfigurationSection> children, string indent)
			{
				foreach (IConfigurationSection child in children)
				{
					(string, IConfigurationProvider) valueAndProvider = GetValueAndProvider(root, child.Path);
					if (valueAndProvider.Item2 != null)
					{
						string text;
						if (processValue == null)
						{
							(text, _) = valueAndProvider;
						}
						else
						{
							text = processValue(new ConfigurationDebugViewContext(child.Path, child.Key, valueAndProvider.Item1, valueAndProvider.Item2));
						}
						string value = text;
						stringBuilder2.Append(indent).Append(child.Key).Append('=')
							.Append(value)
							.Append(" (")
							.Append(valueAndProvider.Item2)
							.AppendLine(")");
					}
					else
					{
						stringBuilder2.Append(indent).Append(child.Key).AppendLine(":");
					}
					RecurseChildren(stringBuilder2, child.GetChildren(), indent + "  ");
				}
			}
		}

		private static (string Value, IConfigurationProvider Provider) GetValueAndProvider(IConfigurationRoot root, string key)
		{
			foreach (IConfigurationProvider item in root.Providers.Reverse())
			{
				if (item.TryGet(key, out string value))
				{
					return (Value: value, Provider: item);
				}
			}
			return (Value: null, Provider: null);
		}
	}
	public interface IConfiguration
	{
		string? this[string key] { get; set; }

		IConfigurationSection GetSection(string key);

		IEnumerable<IConfigurationSection> GetChildren();

		IChangeToken GetReloadToken();
	}
	public interface IConfigurationBuilder
	{
		IDictionary<string, object> Properties { get; }

		IList<IConfigurationSource> Sources { get; }

		IConfigurationBuilder Add(IConfigurationSource source);

		IConfigurationRoot Build();
	}
	public interface IConfigurationManager : IConfiguration, IConfigurationBuilder
	{
	}
	public interface IConfigurationProvider
	{
		bool TryGet(string key, out string? value);

		void Set(string key, string? value);

		IChangeToken GetReloadToken();

		void Load();

		IEnumerable<string> GetChildKeys(IEnumerable<string> earlierKeys, string? parentPath);
	}
	public interface IConfigurationRoot : IConfiguration
	{
		IEnumerable<IConfigurationProvider> Providers { get; }

		void Reload();
	}
	public interface IConfigurationSection : IConfiguration
	{
		string Key { get; }

		string Path { get; }

		string? Value { get; set; }
	}
	public interface IConfigurationSource
	{
		IConfigurationProvider Build(IConfigurationBuilder builder);
	}
}
