using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Configuration;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security;
using System.Threading;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Threading;
using AspenTech.AspenPlus;
using AspenTech.AspenPlus.AspenSplashInterop;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.UnmanagedWrapper;
using IWshRuntimeLibrary;
using Microsoft.Practices.Composite.Logging;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("Aspen Plus V15")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("Aspen Plus V15")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenPlus
{
	public class App : System.Windows.Application
	{
		private const int copyrightDate = 2025;

		private AspenSplashScreen _splash;

		private bool _IsShowSplash = true;

		private static string commonXeqDirectory;

		private static string _mmFavoritesDirectory;

		private const string InternalVersionString = "41.0";

		private bool showCrashMessage = true;

		private static List<string> _supportedLanguages = new List<string> { "ENG", "FRA", "ITA", "DEU", "SPA", "JPN", "CHS", "KOR", "RUS", "PTB" };

		private static List<string> _alreadyTried = new List<string>();

		private static string _HydraulicsPath = null;

		private static string _SafetyAnalysisPath = null;

		private readonly List<string> _reflectionOnlyTried = new List<string>();

		private bool _contentLoaded;

		public static string CommonXeq
		{
			get
			{
				if (commonXeqDirectory == null)
				{
					try
					{
						commonXeqDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Aprsystem\\41.0\\mm", "mmcommonxeq", "").ToString();
					}
					catch
					{
					}
				}
				return commonXeqDirectory;
			}
		}

		public static string MMFavorites
		{
			get
			{
				if (_mmFavoritesDirectory == null)
				{
					try
					{
						_mmFavoritesDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Aspen Plus\\41.0\\mm", "mmfavorites", "").ToString();
					}
					catch
					{
					}
				}
				return _mmFavoritesDirectory;
			}
		}

		public App()
		{
			AppDomain currentDomain = AppDomain.CurrentDomain;
			currentDomain.AssemblyResolve += currentDomain_AssemblyResolve;
			currentDomain.ReflectionOnlyAssemblyResolve += currentDomain_ReflectionOnlyAssemblyResolve;
			try
			{
				Assembly.LoadFrom(CommonXeq + "\\AspenTech.AspenPlus.Infrastructure.dll");
				Assembly.LoadFrom(CommonXeq + "\\AspenTech.AspenPlus.UnmanagedWrapper.dll");
			}
			catch (FileNotFoundException)
			{
			}
			DoInitialization();
		}

		private void DoInitialization()
		{
			ApplyAspenLanguageSelection();
			string[] commandLineArgs = Environment.GetCommandLineArgs();
			foreach (string strA in commandLineArgs)
			{
				if (string.Compare(strA, "-Automation", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "/Automation", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-nologo", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "/nologo", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-input", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "/input", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-Turbo", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "/Turbo", ignoreCase: true, CultureInfo.InvariantCulture) == 0)
				{
					_IsShowSplash = false;
					break;
				}
			}
			if (_IsShowSplash)
			{
				ThreadPool.QueueUserWorkItem(delegate
				{
					_splash = new AspenSplashScreen();
					_splash.ShowSplashScreen(SystemEnvironment.ApplicationName, SystemEnvironment.ApplicationName, SystemEnvironment.ExternalVersionString, 2011, 2025, SystemEnvironment.CheckLicString);
				});
			}
			CreateFavoriteLink();
		}

		private void CloseSplash()
		{
			if (_splash != null)
			{
				_splash.DismissScreen();
				_splash = null;
			}
		}

		private void SplashStatus(string messaage)
		{
			if (_splash != null)
			{
				_splash.SplashStatus(messaage);
			}
		}

		private void CreateFavoriteLink()
		{
			SystemEnvironment.LogDebug("CreateFavoriteLink: Creating.....");
			string text = "Aspen Plus " + SystemEnvironment.ExternalVersionString;
			string text2 = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Links", text + " Favorites.lnk");
			string message = "CreateFavoriteLink ShortcutAdress: " + text2;
			try
			{
				SystemEnvironment.LogDebug(message);
				if (!File.Exists(text2))
				{
					WshShell wshShell = (WshShell)Activator.CreateInstance(Marshal.GetTypeFromCLSID(new Guid("72C24DD5-D70A-438B-8A42-98424B88AFB8")));
					SystemEnvironment.LogDebug("CreateFavoriteLink: calling shell.CreateShortcut(shortcutAddress)");
					IWshShortcut obj = (IWshShortcut)(dynamic)wshShell.CreateShortcut(text2);
					SystemEnvironment.LogDebug("CreateFavoriteLink: shell.CreateShortcut(shortcutAddress) calling successful");
					obj.Description = text + " Favorites";
					obj.TargetPath = MMFavorites;
					obj.Save();
					SystemEnvironment.LogDebug("CreateFavoriteLink:  shortcut.Save() successful");
				}
			}
			catch (Exception)
			{
				SystemEnvironment.LogDebug("CreateFavoriteLink:  Failed");
			}
			SystemEnvironment.LogDebug("CreateFavoriteLink: Exiting successfully...");
		}

		private void App_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
		{
			if (e.Exception == null)
			{
				return;
			}
			if (IgnoreException(e.Exception))
			{
				string message = string.Format(AspenResources.UnhandledEx + "{1}" + AspenResources.ExMessage + " {0}{1}" + AspenResources.ExSource + " {2}{1}" + AspenResources.StackTrace + " {3}", e.Exception.Message, Environment.NewLine, e.Exception.Source, e.Exception.StackTrace);
				SystemEnvironment.Logger.Log(message, Category.Exception, Priority.Low);
				e.Handled = true;
			}
			else
			{
				if (!string.IsNullOrEmpty(e.Exception.Source) && (string.Compare(e.Exception.Source.Substring(0, 5), "WpfPL", ignoreCase: true) == 0 || (!string.IsNullOrEmpty(e.Exception.StackTrace) && (e.Exception.StackTrace.IndexOf(".UpdateWizardData()") != -1 || e.Exception.StackTrace.IndexOf("at WpfPL") != -1))))
				{
					return;
				}
				string message2 = string.Format(AspenResources.UnhandledEx + "{1}" + AspenResources.ExMessage + " {0}{1}" + AspenResources.ExSource + " {2}{1}" + AspenResources.StackTrace + " {3}", e.Exception.Message, Environment.NewLine, e.Exception.Source, e.Exception.StackTrace);
				SystemEnvironment.Logger.Log(message2, Category.Exception, Priority.High);
				if (showCrashMessage)
				{
					showCrashMessage = false;
					if (SystemEnvironment.Logger is SystemEnvironment.DebugLogger { FilePath: not null } debugLogger && base.MainWindow != null)
					{
						MMMessageBox.Show(Window.GetWindow(base.MainWindow), string.Format(ApwnResources.UnhandledException, ApwnResources.AspenPlus, debugLogger.FilePath), ApwnResources.AspenPlus, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
					}
				}
				bool flag = false;
				try
				{
					flag = HelperFuncs.CrashReport();
				}
				catch (Exception)
				{
				}
				if (!flag)
				{
					e.Handled = true;
					Shutdown();
				}
			}
		}

		private bool IgnoreException(Exception ex)
		{
			if (ex.StackTrace.Contains("AspenTech.Exchange.SecureServices"))
			{
				return true;
			}
			if (ex.StackTrace.Contains("System.Windows.Media.Visual.PointToScreen"))
			{
				return true;
			}
			if (ex.StackTrace.Contains("System.Windows.Controls.PopupControlService.RaiseToolTipClosingEvent"))
			{
				return true;
			}
			return false;
		}

		protected override void OnStartup(StartupEventArgs e)
		{
			SystemEnvironment.LogDebug("App.OnStartup started");
			AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
			base.DispatcherUnhandledException += App_DispatcherUnhandledException;
			System.Windows.Forms.Application.ThreadException += Application_WinFormThreadException;
			SystemEnvironment.LogDebug("MMVersionHelper.MVSetProductCodeM started");
			MMVersionHelper.MVSetProductCodeM(1);
			SystemEnvironment.LogDebug("MMVersionHelper.MVSetProductCodeM ended");
			ApplicationHelper.Run(this, CloseSplash, SplashStatus);
			if (!ApplicationHelper.IsGenerateInput)
			{
				base.OnStartup(e);
			}
			else
			{
				Shutdown();
			}
		}

		protected override void OnExit(ExitEventArgs e)
		{
			try
			{
				ApplicationHelper.OnExit(e);
			}
			catch
			{
			}
			base.OnExit(e);
		}

		private void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
		{
			Exception ex = e.ExceptionObject as Exception;
			if (ex != null)
			{
				string message = $"AppDomain.UnhandledException: {ex.Message}\n{ex.StackTrace}";
				SystemEnvironment.Logger.Log(message, Category.Exception, Priority.High);
			}
			else if (e.ExceptionObject != null)
			{
				SystemEnvironment.Logger.Log("AppDomain.UnhandledException: " + ex.ToString(), Category.Exception, Priority.High);
			}
			else
			{
				SystemEnvironment.Logger.Log("AppDomain.UnhandledException.", Category.Exception, Priority.High);
			}
		}

		public void Application_WinFormThreadException(object sender, ThreadExceptionEventArgs e)
		{
			FailureFromFocusedChild(e.Exception);
		}

		private bool FailureFromFocusedChild(Exception ex)
		{
			string stackTrace = ex.StackTrace;
			if (ex is ArgumentException && ex.Source == "System.Windows.Forms")
			{
				return stackTrace.Contains("System.Windows.Forms.Integration.WindowsFormsHost.RestoreFocusedChild");
			}
			return false;
		}

		private static void ApplyAspenLanguageSelection()
		{
			string keyName = "HKEY_CURRENT_USER\\Software\\AspenTech\\Engineering\\Language";
			string text = Registry.GetValue(keyName, null, string.Empty) as string;
			if (string.IsNullOrEmpty(text))
			{
				string text2 = Thread.CurrentThread.CurrentUICulture.ThreeLetterWindowsLanguageName;
				if (!_supportedLanguages.Contains(text2))
				{
					text2 = "ENG";
				}
				Registry.SetValue(keyName, null, text2);
				text = text2;
			}
			string empty = string.Empty;
			empty = text.ToUpperInvariant() switch
			{
				"ENG" => "en-US", 
				"FRA" => "fr-FR", 
				"ITA" => "it-IT", 
				"DEU" => "de-DE", 
				"SPA" => "es-ES", 
				"JPN" => "ja-JP", 
				"CHS" => "zh-HANS", 
				"KOR" => "ko-KR", 
				"RUS" => "ru-RU", 
				"PTB" => "pt-BR", 
				_ => "en-US", 
			};
			if (!string.IsNullOrEmpty(empty))
			{
				CultureInfo cultureInfo = null;
				try
				{
					cultureInfo = new CultureInfo(CultureInfo.CreateSpecificCulture(empty).Name, useUserOverride: true);
				}
				catch (CultureNotFoundException)
				{
				}
				if (cultureInfo != null)
				{
					Thread.CurrentThread.CurrentUICulture = cultureInfo;
					return;
				}
				CultureInfo currentUICulture = new CultureInfo("en-US");
				Thread.CurrentThread.CurrentUICulture = currentUICulture;
			}
		}

		private static Assembly currentDomain_AssemblyResolve(object sender, ResolveEventArgs args)
		{
			if (_alreadyTried.Contains(args.Name))
			{
				return null;
			}
			Assembly assembly = AppDomain.CurrentDomain.GetAssemblies().FirstOrDefault((Assembly x) => x.FullName == args.Name);
			if (assembly != null)
			{
				return assembly;
			}
			string text = (args.Name.Contains(',') ? args.Name.Substring(0, args.Name.IndexOf(',')) : args.Name);
			if (!string.IsNullOrEmpty(text))
			{
				string text2 = CommonXeq + "\\" + text + ".dll";
				if (File.Exists(text2))
				{
					try
					{
						return Assembly.LoadFrom(text2);
					}
					catch (FileNotFoundException)
					{
					}
					catch (BadImageFormatException)
					{
					}
				}
				else if (text.EndsWith(".resources", StringComparison.InvariantCultureIgnoreCase))
				{
					string rootAssemblyName = text.Substring(0, text.Length - 10);
					Assembly assembly2 = AppDomain.CurrentDomain.GetAssemblies().FirstOrDefault((Assembly assembly4) => assembly4.FullName.StartsWith(rootAssemblyName));
					if (assembly2 != null)
					{
						string text3 = CultureInfo.CurrentCulture.Name;
						if (args.Name.Contains("Culture="))
						{
							string text4 = args.Name.Substring(args.Name.IndexOf("Culture="));
							if (text4.Contains(','))
							{
								text3 = text4.Substring(8, text4.IndexOf(',') - 8);
							}
						}
						string text5 = Path.GetDirectoryName(assembly2.Location) + "\\" + text3 + "\\" + text + ".dll";
						if (File.Exists(text5))
						{
							try
							{
								return Assembly.LoadFrom(text5);
							}
							catch (FileNotFoundException)
							{
							}
						}
					}
				}
				else
				{
					Assembly assembly3 = _ResolveSafetyAssembly(text, args.Name);
					if (assembly3 != null)
					{
						return assembly3;
					}
				}
			}
			_alreadyTried.Add(args.Name);
			return null;
		}

		private static Assembly _ResolveSafetyAssembly(string failedName, string fullName)
		{
			if (failedName.StartsWith("AspenTech.EquipmentAnalysis") || failedName.StartsWith("PSVSizingEngine"))
			{
				if (string.IsNullOrEmpty(_SafetyAnalysisPath))
				{
					using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\Setup");
					string text = (string)registryKey?.GetValue("ASPENROOT64");
					if (!string.IsNullOrEmpty(text))
					{
						string text2 = Path.Combine(text, "Aspen Safety Analysis " + SystemEnvironment.PathVersionString);
						if (!string.IsNullOrEmpty(text2) && Directory.Exists(text2))
						{
							_SafetyAnalysisPath = text2;
						}
					}
				}
				if (!string.IsNullOrEmpty(_SafetyAnalysisPath))
				{
					string text3 = Path.Combine(_SafetyAnalysisPath, failedName) + ".dll";
					if (File.Exists(text3))
					{
						if (1 == 0)
						{
							throw new SecurityException();
						}
						try
						{
							return Assembly.LoadFrom(text3);
						}
						catch (Exception)
						{
							SystemEnvironment.Logger.Log("Aspen Safety Analysis assembly failed to load: " + fullName, Category.Info, Priority.High);
						}
					}
				}
			}
			if (string.IsNullOrEmpty(_HydraulicsPath))
			{
				using RegistryKey registryKey2 = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\Aspen Hydraulics\\" + SystemEnvironment.InternalVersionString);
				if (registryKey2 != null)
				{
					_HydraulicsPath = (string)registryKey2.GetValue("");
				}
			}
			if (!string.IsNullOrEmpty(_HydraulicsPath))
			{
				string text4 = Path.Combine(_HydraulicsPath, failedName) + ".dll";
				if (File.Exists(text4))
				{
					if (1 == 0)
					{
						throw new SecurityException();
					}
					try
					{
						return Assembly.LoadFrom(text4);
					}
					catch (Exception)
					{
						SystemEnvironment.Logger.Log("Aspen Hydraulics assembly failed to load: " + fullName, Category.Info, Priority.High);
					}
				}
			}
			return null;
		}

		private Assembly currentDomain_ReflectionOnlyAssemblyResolve(object sender, ResolveEventArgs args)
		{
			if (_reflectionOnlyTried.Contains(args.Name))
			{
				return null;
			}
			_reflectionOnlyTried.Add(args.Name);
			Assembly assembly = AppDomain.CurrentDomain.ReflectionOnlyGetAssemblies().FirstOrDefault((Assembly x) => x.FullName == args.Name);
			if (assembly != null)
			{
				return assembly;
			}
			if (args.Name.StartsWith("System."))
			{
				try
				{
					if (Assembly.Load(args.Name) != null)
					{
						return Assembly.ReflectionOnlyLoad(args.Name);
					}
				}
				catch (Exception)
				{
				}
			}
			string text = (args.Name.Contains(',') ? args.Name.Substring(0, args.Name.IndexOf(',')) : args.Name);
			if (!string.IsNullOrEmpty(text))
			{
				string text2 = CommonXeq + "\\" + text + ".dll";
				if (File.Exists(text2))
				{
					try
					{
						return Assembly.ReflectionOnlyLoadFrom(text2);
					}
					catch (FileNotFoundException)
					{
					}
				}
			}
			return null;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenPlus;component/app.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[STAThread]
		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public static void Main()
		{
			App app = new App();
			app.InitializeComponent();
			app.Run();
		}
	}
}
namespace AspenPlus.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
namespace AspenTech.AspenPlus
{
	public class AspenSplashScreen : IDisposable
	{
		private ISplashWindow _splash;

		public void ShowSplashScreen(string title, string subtitle, string externalVersion, short copyrightFrom, short copyrightTo, string licenseChecks)
		{
			try
			{
				Type typeFromCLSID = Type.GetTypeFromCLSID(new Guid("5ec5eb43-13e3-11d3-840d-000000000000"));
				if (!(typeFromCLSID == null))
				{
					_splash = Activator.CreateInstance(typeFromCLSID) as ISplashWindow;
					if (_splash != null)
					{
						_splash.SetStatusText(AspenResources.Initializing);
						_splash.SetSplashTimeout(-1);
						_splash.ShowSplash2(title, subtitle, externalVersion, copyrightFrom, copyrightTo, "");
					}
					if (!string.IsNullOrEmpty(licenseChecks) && Activator.CreateInstance(typeFromCLSID) is ISplashWindow splashWindow)
					{
						splashWindow.CheckLicenseExpiration(licenseChecks);
					}
				}
			}
			catch (Exception)
			{
			}
		}

		public void DismissScreen()
		{
			if (_splash != null)
			{
				try
				{
					Marshal.ReleaseComObject(_splash);
				}
				catch (Exception)
				{
				}
				_splash = null;
			}
		}

		public void SplashStatus(string message)
		{
			if (_splash != null)
			{
				try
				{
					_splash.SetStatusText(message);
				}
				catch (Exception)
				{
				}
			}
		}

		public void Dispose()
		{
			Dispose(disposing: true);
			GC.SuppressFinalize(this);
		}

		private void Dispose(bool disposing)
		{
			if (disposing)
			{
				DismissScreen();
			}
		}
	}
}
namespace AspenTech.AspenPlus.AspenSplashInterop
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("5ec5eb42-13e3-11d3-840d-000000000000")]
	internal interface ISplashWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void ShowSplash([In][MarshalAs(UnmanagedType.BStr)] string title, [In][MarshalAs(UnmanagedType.BStr)] string subtitle, [In][MarshalAs(UnmanagedType.I2)] short majorVersion, [In][MarshalAs(UnmanagedType.I2)] short minorVersion, [In][MarshalAs(UnmanagedType.I2)] short copyrightFrom, [In][MarshalAs(UnmanagedType.I2)] short copyrightTo, [In][MarshalAs(UnmanagedType.BStr)] string license);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetStatusText([In][MarshalAs(UnmanagedType.BStr)] string status);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetLicenseeText([In][MarshalAs(UnmanagedType.BStr)] string licensee);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void AddToRecentAppList([In][MarshalAs(UnmanagedType.BStr)] string appPath, [In][MarshalAs(UnmanagedType.BStr)] string appTitle);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void AddToRecentDocList([In][MarshalAs(UnmanagedType.BStr)] string documentPath, [In][MarshalAs(UnmanagedType.BStr)] string appOpenWith);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void TestUserRegistration();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void HideSplash();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetSplashTimeout([In][MarshalAs(UnmanagedType.I2)] short nTimeout);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void CheckLicenseExpiration([In][MarshalAs(UnmanagedType.BStr)] string license);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void ShowSplash2([In][MarshalAs(UnmanagedType.BStr)] string title, [In][MarshalAs(UnmanagedType.BStr)] string subtitle, [In][MarshalAs(UnmanagedType.BStr)] string version, [In][MarshalAs(UnmanagedType.I2)] short copyrightFrom, [In][MarshalAs(UnmanagedType.I2)] short copyrightTo, [In][MarshalAs(UnmanagedType.BStr)] string license);
	}
}
namespace IWshRuntimeLibrary
{
	[ComImport]
	[CompilerGenerated]
	[Guid("F935DC21-1CF0-11D0-ADB9-00C04FD58A0B")]
	[TypeIdentifier]
	public interface IWshShell
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("24BE5A30-EDFE-11D2-B933-00104B365C9F")]
	[TypeIdentifier]
	public interface IWshShell2 : IWshShell
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("41904400-BE18-11D3-A28B-00104BD35090")]
	[TypeIdentifier]
	public interface IWshShell3 : IWshShell2
	{
		void _VtblGap1_4();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1002)]
		[return: MarshalAs(UnmanagedType.IDispatch)]
		object CreateShortcut([In][MarshalAs(UnmanagedType.BStr)] string PathLink);
	}
	[ComImport]
	[CompilerGenerated]
	[DefaultMember("FullName")]
	[Guid("F935DC23-1CF0-11D0-ADB9-00C04FD58A0B")]
	[TypeIdentifier]
	public interface IWshShortcut
	{
		[DispId(0)]
		string FullName
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(0)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}

		void _VtblGap1_2();

		[DispId(1001)]
		string Description
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1001)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1001)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		void _VtblGap2_5();

		[DispId(1005)]
		string TargetPath
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1005)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1005)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		void _VtblGap3_5();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(2001)]
		void Save();
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("41904400-BE18-11D3-A28B-00104BD35090")]
	[CoClass(typeof(object))]
	[TypeIdentifier]
	public interface WshShell : IWshShell3
	{
	}
}
