// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[assembly: NeutralResourcesLanguage("en-US")]
[assembly: AssemblyTitle("System.Security.Cryptography.ProtectedData")]
[assembly: AssemblyDescription("System.Security.Cryptography.ProtectedData")]
[assembly: AssemblyDefaultAlias("System.Security.Cryptography.ProtectedData")]
[assembly: AssemblyCompany("Microsoft Corporation")]
[assembly: AssemblyProduct("Microsoft® .NET Framework")]
[assembly: AssemblyCopyright("© Microsoft Corporation.  All rights reserved.")]
[assembly: AssemblyFileVersion("4.6.26515.06")]
[assembly: AssemblyInformationalVersion("4.6.26515.06 @BuiltBy: dlab-DDVSOWINAGE059 @Branch: release/2.1 @SrcCode: https://github.com/dotnet/corefx/tree/30ab651fcb4354552bd4891619a0bdd81e0ebdbf")]
[assembly: CLSCompliant(true)]
[assembly: AssemblyMetadata(".NETFrameworkAssembly", "")]
[assembly: AssemblyMetadata("Serviceable", "True")]
[assembly: AssemblyMetadata("PreferInbox", "True")]
[assembly: AssemblyMetadata("NotSupported", "True")]
[assembly: DefaultDllImportSearchPaths(DllImportSearchPath.System32 | DllImportSearchPath.AssemblyDirectory)]
[assembly: AssemblyVersion("4.0.3.0")]
namespace FxResources.System.Security.Cryptography.ProtectedData
{
	internal static class SR
	{
	}
}
namespace System
{
	internal static class SR
	{
		private static ResourceManager s_resourceManager;

		private static ResourceManager ResourceManager => s_resourceManager ?? (s_resourceManager = new ResourceManager(ResourceType));

		internal static Type ResourceType { get; } = typeof(FxResources.System.Security.Cryptography.ProtectedData.SR);

		internal static string Cryptography_DpApi_ProfileMayNotBeLoaded => GetResourceString("Cryptography_DpApi_ProfileMayNotBeLoaded", null);

		internal static string PlatformNotSupported_CryptographyProtectedData => GetResourceString("PlatformNotSupported_CryptographyProtectedData", null);

		[MethodImpl(MethodImplOptions.NoInlining)]
		private static bool UsingResourceKeys()
		{
			return false;
		}

		internal static string GetResourceString(string resourceKey, string defaultString)
		{
			string text = null;
			try
			{
				text = ResourceManager.GetString(resourceKey);
			}
			catch (MissingManifestResourceException)
			{
			}
			if (defaultString != null && resourceKey.Equals(text, StringComparison.Ordinal))
			{
				return defaultString;
			}
			return text;
		}

		internal static string Format(string resourceFormat, params object[] args)
		{
			if (args != null)
			{
				if (UsingResourceKeys())
				{
					return resourceFormat + string.Join(", ", args);
				}
				return string.Format(resourceFormat, args);
			}
			return resourceFormat;
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
	}
}
namespace System.Runtime.CompilerServices
{
	[AttributeUsage(AttributeTargets.All)]
	internal class __BlockReflectionAttribute : Attribute
	{
	}
}
namespace System.Security.Cryptography
{
	public enum DataProtectionScope
	{
		CurrentUser,
		LocalMachine
	}
	public static class ProtectedData
	{
		public static byte[] Protect(byte[] userData, byte[] optionalEntropy, DataProtectionScope scope)
		{
			throw new PlatformNotSupportedException(System.SR.PlatformNotSupported_CryptographyProtectedData);
		}

		public static byte[] Unprotect(byte[] encryptedData, byte[] optionalEntropy, DataProtectionScope scope)
		{
			throw new PlatformNotSupportedException(System.SR.PlatformNotSupported_CryptographyProtectedData);
		}
	}
}
