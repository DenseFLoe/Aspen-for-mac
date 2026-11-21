using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xml;
using System.Xml.Linq;
using AspenTech.Adb.Interfaces;
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.Aosapfs;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.WpfPlotWizards;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Engineering.CommonShellExtensions.Compability;
using AspenTech.Modeler.ACMExpUtilities;
using AspenTech.Visualisation.CommonShell;
using AspenTech.Visualisation.Controls.Support.Commands;
using Infragistics.Windows.DockManager;
using Infragistics.Windows.Ribbon;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Logging;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Events;
using Microsoft.Practices.Composite.UnityExtensions;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.Infrastructure")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.Infrastructure")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace ApwnShell.Infrastructure
{
	public static class ScreenFactoryKeys
	{
		public static string ApwnFormContentFactory = "ApwnFormContentFactory";

		public static string BrowserScreenFactory = "BrowserScreenFactory";

		public static string MessageViewFactory = "MessageViewFactory";

		public static string PromptViewFactory = "PromptViewFactory";

		public static string ViewModelDumpFactory = "ViewModelDumpFactory";

		public static string AnalysisScreenFactory = "AnalysisScreenFactory";

		public static string ControlPanelScreenFactory = "ControlPanelScreenFactory";

		public static string FlowsheetScreenFactory = "FlowsheetScreenFactory";

		public static string NewFlowsheetScreenFactory = "NewFlowsheetScreenFactory";

		public static string ApwnPlotScreenFactory = "ApwnPlotScreenFactory";

		public static string Apwn3DPlotScreenFactory = "Apwn3DPlotScreenFactory";

		public static string Apwn3DPlotScreenV2Factory = "Apwn3DPlotScreenV2Factory";

		public static string ApwnPlotWizardScreenFactory = "ApwnPlotWizardScreenFactory";

		public static string TdeEvaluateResultScreenFactory = "TdeEvaluateResultScreenFactory";

		public static string TDEDialogScreenFactory = "TDEDialogScreenFactory";

		public static string AspenMarketPlaceScreenFactory = "AspenMarketPlaceScreenFactory";

		public static string AOLConfigurationScreenFactory = "AOLConfigurationScreenFactory";

		public static string ApwnTimePlotScreenFactory = "ApwnTimePlotScreenFactory";

		public static string SpecChemPlotScreenFactory = "SpecChemPlotScreenFactory";

		public static string UnitProcedureSummaryResultsScreenFactory = "UnitProcedureSummaryResultsScreenFactory";

		public static string ApwnPlotWizardNewPlotControlScreenFactory = "ApwnPlotWizardNewPlotControlScreenFactory";

		public static string ApwnPlotNewPlotControlScreenFactory = "ApwnPlotNewPlotControlScreenFactory";

		public static string CustomModelsEditorScreenFactory = "CustomModelsEditorScreenFactory";

		public static string CustomModelsObjectManagerScreenFactory = "CustomModelsObjectManagerScreenFactory";
	}
}
namespace AspenTech.AspenPlus
{
	public class ACMModelLibraryHelper
	{
		private const string GuidSuffix = "0410";

		private static IModelLibraryManager _oACMLibMgr;

		public static IModelLibraryManager ACMModelLibraryManager
		{
			get
			{
				if (_oACMLibMgr == null)
				{
					_oACMLibMgr = new ModelLibraryManager();
				}
				return _oACMLibMgr;
			}
		}

		public static object ACM_FindModel(string sModel)
		{
			return ACMModelLibraryManager.FindModel(sModel);
		}

		public static object ACM_FindModel(string sModel, string sVersion)
		{
			return ACMModelLibraryManager.FindModel(sModel, sVersion);
		}

		public static object ACM_FindReaction(string sModel)
		{
			return ACMModelLibraryManager.FindReaction(sModel);
		}

		public static void ACM_UnlockModel(string sModel)
		{
			ACMModelLibraryManager.UnlockModel(sModel);
		}

		public static void ACM_ModelSaveTo(object oModel, string sModelFile, bool bOverwrite)
		{
			if (oModel is IACMExpModel iACMExpModel)
			{
				iACMExpModel.SaveTo(sModelFile, bOverwrite);
			}
		}

		public static bool ACM_InstallModel(string sModelFile, bool bOverwrite)
		{
			return ACMModelLibraryManager.InstallNewLibrary(sModelFile, bOverwrite);
		}

		public static bool ACM_UninstallModel(string sModelName, string sVersion)
		{
			return ACMModelLibraryManager.UninstallLibrary(sModelName, sVersion);
		}

		public static object ACM_OpenModelFile(string sModelFile)
		{
			return ACMModelLibraryManager.OpenModelFile(sModelFile);
		}

		public static void ACM_CloseModelFile(object oModel)
		{
			if (oModel is IACMExpModel oModel2)
			{
				ACMModelLibraryManager.CloseModelFile(oModel2);
			}
		}

		public static bool ACM_CloseModel(string sModelName)
		{
			return ACMModelLibraryManager.CloseModel(sModelName);
		}

		public static object ACM_GetModelPropertyObject(object oModel, string sProperty)
		{
			string result = null;
			try
			{
				PropertyInfo property = oModel.GetType().GetProperty(sProperty);
				if (property != null)
				{
					return property.GetValue(oModel, null);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public static string ACM_GetModelProperty(object oModel, string sProperty)
		{
			string result = null;
			try
			{
				if (oModel is IACMExpModel iACMExpModel)
				{
					switch (sProperty)
					{
					case "Compiled":
						return iACMExpModel.Compiled;
					case "Help":
						return iACMExpModel.Help;
					case "Plots":
						return iACMExpModel.Plots;
					case "Timestamp":
						return iACMExpModel.Timestamp;
					case "Description":
						return iACMExpModel.Description;
					case "Version":
						return iACMExpModel.Version;
					case "RevisionGuid":
						return iACMExpModel.RevisionGuid;
					case "Display":
						return iACMExpModel.Display;
					}
				}
				PropertyInfo property = oModel.GetType().GetProperty(sProperty);
				if (property != null)
				{
					object value = property.GetValue(oModel, null);
					if (value != null)
					{
						result = value.ToString();
					}
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public static string ACM_GetModelInfoProperty(object oModelInfo, string sProperty)
		{
			string result = null;
			try
			{
				if (oModelInfo is IACMExpModelInfo iACMExpModelInfo)
				{
					switch (sProperty)
					{
					case "Name":
						return iACMExpModelInfo.Name;
					case "Compiled":
						return iACMExpModelInfo.Compiled;
					case "Timestamp":
						return iACMExpModelInfo.Timestamp;
					case "Description":
						return iACMExpModelInfo.Description;
					case "Version":
						return iACMExpModelInfo.Version;
					case "RevisionGuid":
						return iACMExpModelInfo.RevisionGuid;
					case "Display":
						return iACMExpModelInfo.Display;
					}
				}
				PropertyInfo property = oModelInfo.GetType().GetProperty(sProperty);
				if (property != null)
				{
					object value = property.GetValue(oModelInfo, null);
					if (value != null)
					{
						result = value.ToString();
					}
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public static string ACM_SetModelProperty(object oModel, string sProperty, object value)
		{
			string result = null;
			try
			{
				PropertyInfo property = oModel.GetType().GetProperty(sProperty);
				if (property != null)
				{
					property.SetValue(oModel, value, null);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public static bool ACM_GetModelCustomModelingFile(object oModel, string customModelFile)
		{
			bool result = false;
			try
			{
				if (oModel is IACMExpModel { CustomModeling: var customModeling } && !string.IsNullOrEmpty(customModeling))
				{
					result = true;
					File.Copy(customModeling, customModelFile, overwrite: true);
				}
			}
			catch (Exception)
			{
			}
			return result;
		}

		public static string ACM_GetModelHelp(object oModel, string helpFolder)
		{
			try
			{
				if (oModel is IACMExpModel { Help: var help } && !string.IsNullOrEmpty(helpFolder) && !string.IsNullOrEmpty(help))
				{
					if (!Directory.Exists(helpFolder))
					{
						Directory.CreateDirectory(helpFolder);
					}
					string text = Path.Combine(helpFolder, Path.GetFileName(help));
					File.Copy(help, text, overwrite: true);
					return text;
				}
			}
			catch (Exception)
			{
			}
			return null;
		}

		public static int ACM_GetModelProcedures(object oModel, string procFolder)
		{
			int num = 0;
			try
			{
				if (oModel is IACMExpModel { Procedures: var procedures } && !string.IsNullOrEmpty(procFolder) && procedures != null)
				{
					num = procedures.Length;
					for (int i = 0; i < num; i++)
					{
						File.Copy(procedures[i], Path.Combine(procFolder, Path.GetFileName(procedures[i])), overwrite: true);
					}
				}
			}
			catch (Exception)
			{
			}
			return num;
		}

		public static string[] ACM_GetInstalledModels()
		{
			ACMModelLibraryManager.Refresh();
			return ACMModelLibraryManager.ACMModels;
		}

		public static bool ACM_GetInstalledModelInfo(string modelDisplayName, out string name, out string version, out string description, out string reversionGuid, out object modelObject)
		{
			name = null;
			version = null;
			description = null;
			reversionGuid = null;
			modelObject = null;
			try
			{
				IACMExpModelInfo iACMExpModelInfo = ACMModelLibraryManager.FindModelInfo(modelDisplayName);
				if (iACMExpModelInfo != null)
				{
					name = iACMExpModelInfo.Name;
					version = iACMExpModelInfo.Version;
					description = iACMExpModelInfo.Description;
					reversionGuid = iACMExpModelInfo.RevisionGuid;
					modelObject = iACMExpModelInfo.Model;
					return true;
				}
			}
			catch (Exception)
			{
			}
			return false;
		}

		public static object GetModelFileInfo(string sModelFile)
		{
			return ACMModelLibraryManager.GetModelFileInfo(sModelFile);
		}
	}
}
namespace AspenTech.AspenPlus.Infrastructure
{
	public static class APEDHelpers
	{
		private const string CONFIG_OS_REGKEY = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";

		private static int LocalDB = 0;

		private static string error = string.Empty;

		private static bool bWin10 = false;

		private static bool bLocalDB = false;

		private const string APROPADDIN_REGKEY = "SOFTWARE\\AspenTech\\Aspen Properties\\";

		private const string Product_Version = "V15.0";

		private const string PGDatabaseFilePath = "C:\\ProgramData\\AspenTech\\APED V15.0\\pgDatabases.dat";

		public static int ReadAPEDConfigurationFile(string APED_CONFIG_FILE_REGKEY, out bool bWindows10)
		{
			bWindows10 = false;
			int num = 0;
			string ConfigFilePath = string.Empty;
			LocalDB = GetLocalDB(APED_CONFIG_FILE_REGKEY);
			bLocalDB = UseLocalDB();
			bWindows10 = bWin10;
			if (SystemEnvironment.GetDBProvider.CompareTo("postgres") == 0)
			{
				ConfigFilePath = "C:\\ProgramData\\AspenTech\\APED V15.0\\pgDatabases.dat";
				error = SetLogFilePath(ConfigFilePath, APED_CONFIG_FILE_REGKEY);
				if (SystemEnvironment.IsAspenProperties)
				{
					CopyHelpPathForCurrentUser();
				}
				if (File.Exists(ConfigFilePath))
				{
					if (string.IsNullOrEmpty(ReadPostgreSQLAPEDConfigFile(ConfigFilePath)))
					{
						num = 1;
					}
				}
				else
				{
					num = 1;
				}
			}
			else
			{
				if (!CheckAPEDRegistryKey(out ConfigFilePath, APED_CONFIG_FILE_REGKEY))
				{
					return 3;
				}
				if (SystemEnvironment.IsAspenProperties)
				{
					CopyHelpPathForCurrentUser();
				}
				if (File.Exists(ConfigFilePath))
				{
					if (string.IsNullOrEmpty(ReadAPEDConfigFile(ConfigFilePath)))
					{
						num = 1;
					}
				}
				else if (GetAspenDB(APED_CONFIG_FILE_REGKEY) == 2)
				{
					num = 4;
				}
				else if (bLocalDB)
				{
					if (CheckLocalDBConfigFilePath(ref ConfigFilePath) && string.IsNullOrEmpty(ReadAPEDConfigFile(ConfigFilePath)))
					{
						num = 1;
					}
				}
				else
				{
					num = 5;
				}
			}
			if (num == 0)
			{
				error = SetLogFilePath(ConfigFilePath, APED_CONFIG_FILE_REGKEY);
			}
			return num;
		}

		public static bool CheckPostgreSQLRegistryKey(out string DBProviderPath, string APED_CONFIG_FILE_REGKEY)
		{
			DBProviderPath = string.Empty;
			bool flag = true;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.LocalMachine.OpenSubKey(APED_CONFIG_FILE_REGKEY);
				if (registryKey == null)
				{
					flag = false;
				}
				else
				{
					object value = registryKey.GetValue("dbProvider");
					if (value == null)
					{
						flag = false;
					}
					else if (!Convert.ToString(value).ToLowerInvariant().Contains("postgres"))
					{
						flag = false;
					}
					else
					{
						DBProviderPath = "C:\\ProgramData\\AspenTech\\APED V15.0\\pgDatabases.dat";
					}
				}
			}
			catch (Exception ex)
			{
				error = ex.Message;
				flag = false;
			}
			finally
			{
				registryKey?.Close();
			}
			if (flag)
			{
				error = SetLogFilePath(DBProviderPath, APED_CONFIG_FILE_REGKEY);
			}
			return flag;
		}

		public static bool CheckAPEDRegistryKey(out string ConfigFilePath, string APED_CONFIG_FILE_REGKEY)
		{
			ConfigFilePath = string.Empty;
			bool flag = true;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.LocalMachine.OpenSubKey(APED_CONFIG_FILE_REGKEY);
				if (registryKey == null)
				{
					flag = false;
				}
				else
				{
					object value = registryKey.GetValue("ConfigFilePath");
					if (value == null)
					{
						flag = false;
					}
					else
					{
						ConfigFilePath = Convert.ToString(value);
						if (!ConfigFilePath.ToLowerInvariant().Contains("config.aem"))
						{
							flag = false;
						}
					}
				}
			}
			catch (Exception ex)
			{
				error = ex.Message;
				flag = false;
			}
			finally
			{
				registryKey?.Close();
			}
			if (flag)
			{
				error = SetLogFilePath(ConfigFilePath, APED_CONFIG_FILE_REGKEY);
			}
			return flag;
		}

		public static string ReadPostgreSQLAPEDConfigFile(string ConfigFilePath)
		{
			string text = string.Empty;
			Stream stream = new FileStream(ConfigFilePath, FileMode.Open, FileAccess.Read, FileShare.Read);
			StreamReader streamReader = new StreamReader(stream);
			string text2 = "";
			if (streamReader != null)
			{
				_ = string.Empty;
				while ((text2 = streamReader.ReadLine()) != null)
				{
					string text3 = text2;
					if (!text3.StartsWith("port:"))
					{
						text = text + text3 + ";";
					}
				}
				streamReader.Close();
				stream.Close();
			}
			return text;
		}

		public static string ReadAPEDConfigFile(string ConfigFilePath)
		{
			string text = string.Empty;
			Stream stream = new FileStream(ConfigFilePath, FileMode.Open, FileAccess.Read, FileShare.Read);
			StreamReader streamReader = new StreamReader(stream);
			string text2 = "";
			if (streamReader != null)
			{
				string empty = string.Empty;
				while ((text2 = streamReader.ReadLine()) != null)
				{
					if (text2.StartsWith("<alias id="))
					{
						string text3 = text2;
						int num = text3.IndexOf(">", 0, text3.Length);
						int num2 = text3.IndexOf("<", 1, text3.Length - 1);
						empty = text3.Substring(num + 1, num2 - num - 1);
						if (!string.IsNullOrEmpty(empty))
						{
							text = text + empty + ";";
						}
					}
				}
				streamReader.Close();
				stream.Close();
			}
			return text;
		}

		public static int GetAspenDB(string APED_CONFIG_FILE_REGKEY)
		{
			int num = 1;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.LocalMachine.OpenSubKey(APED_CONFIG_FILE_REGKEY);
				if (registryKey != null)
				{
					object value = registryKey.GetValue("ASPENDB");
					if (value != null && !string.IsNullOrEmpty(value.ToString()))
					{
						num = Convert.ToInt32(value);
						if (num != 2 && num != 3)
						{
							num = 1;
						}
					}
				}
			}
			catch (Exception ex)
			{
				error = ex.Message;
			}
			finally
			{
				registryKey?.Close();
			}
			return num;
		}

		public static bool UseLocalDB()
		{
			bool result = false;
			string oSName = GetOSName();
			if (oSName.Contains("Windows Server") || oSName.Contains("Windows XP") || oSName.Contains("Windows 2000"))
			{
				if (LocalDB == 4 || LocalDB == 9)
				{
					result = true;
				}
				if (oSName.Contains("Windows Server") && !oSName.Contains("Windows Server 2003") && !oSName.Contains("Windows Server 2008") && !oSName.Contains("Windows Server 2012"))
				{
					bWin10 = true;
				}
			}
			else
			{
				if (LocalDB != 1 && LocalDB != 8)
				{
					result = true;
				}
				if (!oSName.Contains("Windows Vista") && !oSName.Contains("Windows 7") && !oSName.Contains("Windows 8"))
				{
					bWin10 = true;
				}
			}
			return result;
		}

		public static bool CheckLocalDBConfigFilePath(ref string ConfigFilePath)
		{
			ConfigFilePath = Path.GetDirectoryName(ConfigFilePath) + "\\" + Environment.UserName + "\\" + Path.GetFileName(ConfigFilePath);
			if (File.Exists(ConfigFilePath))
			{
				return true;
			}
			return false;
		}

		public static string GetOSName()
		{
			object obj = null;
			string result = string.Empty;
			RegistryKey registryKey = null;
			if (Environment.Is64BitOperatingSystem)
			{
				RegistryKey registryKey2 = RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64);
				if (registryKey2 != null)
				{
					registryKey = registryKey2.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion");
					if (registryKey != null)
					{
						obj = registryKey.GetValue("ProductName");
						registryKey.Close();
					}
					registryKey2.Close();
				}
			}
			else
			{
				registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion");
				if (registryKey != null)
				{
					obj = registryKey.GetValue("ProductName");
					registryKey.Close();
				}
			}
			if (obj != null)
			{
				result = obj.ToString();
			}
			return result;
		}

		private static int GetLocalDB(string APED_CONFIG_FILE_REGKEY)
		{
			int num = 0;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.CurrentUser.OpenSubKey(APED_CONFIG_FILE_REGKEY);
				if (registryKey != null)
				{
					object value = registryKey.GetValue("LOCALDB");
					if (value != null && !string.IsNullOrEmpty(value.ToString()))
					{
						num = Convert.ToInt32(value);
					}
				}
			}
			catch (Exception ex)
			{
				error = ex.Message;
			}
			finally
			{
				registryKey?.Close();
			}
			if (string.IsNullOrEmpty(error) && (num == 1 || num == 4))
			{
				System.Windows.Forms.MessageBox.Show("APED initialization starts from here.");
			}
			return num;
		}

		public static string SetLogFilePath(string ConfigFilePath, string APED_CONFIG_FILE_REGKEY)
		{
			string directoryName = Path.GetDirectoryName(ConfigFilePath);
			string empty = string.Empty;
			string[] array = directoryName.Split('\\');
			string text = string.Concat(str2: (!ConfigFilePath.Contains(Environment.UserName)) ? array[array.Length - 1] : array[array.Length - 2], str0: Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), str1: "\\AspenTech\\");
			if (!Directory.Exists(text))
			{
				error = CreateCurrentUserFilePath(text);
			}
			text += "\\apedconnectionerror.log";
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.CurrentUser.OpenSubKey(APED_CONFIG_FILE_REGKEY, writable: true);
				if (registryKey == null)
				{
					registryKey = Registry.CurrentUser.CreateSubKey(APED_CONFIG_FILE_REGKEY);
				}
				registryKey?.SetValue("LogFilePath", text);
			}
			catch (Exception ex)
			{
				error = ex.Message;
			}
			finally
			{
				registryKey?.Close();
			}
			return error;
		}

		public static void CopyHelpPathForCurrentUser()
		{
			if (string.IsNullOrEmpty(CheckHelpPathForCurrentUser()))
			{
				string helpExtractor = string.Empty;
				string helpPath = GetHelpPath(out helpExtractor);
				if (!string.IsNullOrEmpty(helpPath))
				{
					SetHelpPathForCurrentUser(helpPath, helpExtractor);
				}
			}
		}

		public static string CheckHelpPathForCurrentUser()
		{
			string result = string.Empty;
			string name = "SOFTWARE\\AspenTech\\Aspen Properties\\" + SystemEnvironment.InternalVersionString + "\\mm";
			string name2 = "HtmlHelpRoot";
			_ = string.Empty;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.CurrentUser.OpenSubKey(name);
				if (registryKey != null)
				{
					object value = registryKey.GetValue(name2);
					if (value != null)
					{
						result = value.ToString();
					}
				}
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
			return result;
		}

		public static string GetHelpPath(out string helpExtractor)
		{
			string result = string.Empty;
			helpExtractor = string.Empty;
			string name = "SOFTWARE\\AspenTech\\Aspen Properties\\" + SystemEnvironment.InternalVersionString + "\\mm";
			string name2 = "HtmlHelpRoot";
			string name3 = "HtmlHelpExtractor";
			_ = string.Empty;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.LocalMachine.OpenSubKey(name);
				if (registryKey != null)
				{
					object value = registryKey.GetValue(name2);
					if (value != null)
					{
						result = value.ToString();
					}
					value = registryKey.GetValue(name3);
					if (value != null)
					{
						helpExtractor = value.ToString();
					}
				}
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
			return result;
		}

		public static void SetHelpPathForCurrentUser(string helpPath, string helpExtractor)
		{
			string text = "SOFTWARE\\AspenTech\\Aspen Properties\\" + SystemEnvironment.InternalVersionString + "\\mm";
			string name = "HtmlHelpRoot";
			string name2 = "HtmlHelpExtractor";
			_ = string.Empty;
			RegistryKey registryKey = null;
			try
			{
				registryKey = Registry.CurrentUser.OpenSubKey(text, writable: true);
				if (registryKey != null)
				{
					if (registryKey.GetValue(name) == null)
					{
						registryKey.SetValue(name, helpPath);
					}
					if (registryKey.GetValue(name2) == null)
					{
						registryKey.SetValue(name2, helpExtractor);
					}
				}
				else
				{
					registryKey = Registry.CurrentUser.CreateSubKey(text);
					registryKey.SetValue(name, helpPath);
					registryKey.SetValue(name2, helpExtractor);
				}
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		public static string CreateCurrentUserFilePath(string folder)
		{
			string result = string.Empty;
			try
			{
				Directory.CreateDirectory(folder);
			}
			catch (Exception ex)
			{
				result = ex.Message;
			}
			return result;
		}
	}
	public enum FileOptionDashboardState
	{
		Collpased,
		Expanded,
		Off
	}
	public sealed class ApplicationSettings
	{
		public static ApplicationSettings Default { get; private set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public StringCollection MostRecentlyUsedFiles { get; private set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public StringCollection MostRecentlyUsedTemplates { get; private set; }

		[DefaultValue(null)]
		public string BasicShellSettings { get; set; }

		[DefaultValue(null)]
		public System.Windows.Point? SavedWindowPosition { get; set; }

		[DefaultValue(null)]
		public System.Windows.Size? SavedWindowSize { get; set; }

		[DefaultValue(null)]
		public WindowState? SavedWindowState { get; set; }

		[DefaultValue(null)]
		public PrintPageSettings PrintSettings { get; set; }

		[DefaultValue(null)]
		public PrintPageSettings PrintSettingsForPlots { get; set; }

		[DefaultValue(false)]
		public bool ShouldLogFormOpenTimeAtStatusBar { get; set; }

		[DefaultValue(null)]
		public string ACESharePointURI { get; set; }

		[DefaultValue(null)]
		public string RibbonQATCustomization { get; set; }

		[DefaultValue(false)]
		public bool SequenceViewShown { get; set; }

		[DefaultValue(true)]
		public bool EnergyAnalyzerIndependencyInstanceDialog { get; set; }

		[Obsolete("This property is obsoleted. Use InitialDashboardState instead.")]
		[DefaultValue(false)]
		public bool SuppressActivationDashboard { get; set; }

		[DefaultValue(FileOptionDashboardState.Collpased)]
		public FileOptionDashboardState InitialDashboardState { get; set; }

		[DefaultValue(null)]
		public string DefaultStreamSummaryTemplate { get; set; }

		[DefaultValue(false)]
		public bool UsePfsPlotControl { get; set; }

		[DefaultValue(false)]
		public bool UseSmartPfsCtrl { get; set; }

		[DefaultValue(false)]
		public bool HideInContextGuidanceButtons { get; set; }

		static ApplicationSettings()
		{
			ReloadDefault();
		}

		public static void ReloadDefault()
		{
			Default = ReadFromDefaultFile();
		}

		private static ApplicationSettings ReadFromDefaultFile()
		{
			ApplicationSettings applicationSettings = null;
			string settingsFilePath = GetSettingsFilePath();
			if (File.Exists(settingsFilePath))
			{
				string xamlText = File.ReadAllText(settingsFilePath);
				try
				{
					object obj = XamlReader.Parse(xamlText);
					if (obj != null)
					{
						applicationSettings = obj as ApplicationSettings;
					}
				}
				catch
				{
				}
			}
			return applicationSettings ?? new ApplicationSettings();
		}

		private static string GetSettingsFilePath()
		{
			return Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech", SystemEnvironment.ApplicationNameWithPathVersion, "application.settings");
		}

		public ApplicationSettings()
		{
			MostRecentlyUsedFiles = new StringCollection();
			MostRecentlyUsedTemplates = new StringCollection();
		}

		public void Save()
		{
			try
			{
				string settingsFilePath = GetSettingsFilePath();
				DirectoryInfo directoryInfo = new DirectoryInfo(settingsFilePath.Substring(0, settingsFilePath.LastIndexOf(Path.DirectorySeparatorChar)));
				if (!directoryInfo.Exists)
				{
					directoryInfo.Create();
				}
				if (File.Exists(settingsFilePath) && File.GetAttributes(settingsFilePath) != FileAttributes.Normal)
				{
					File.SetAttributes(settingsFilePath, FileAttributes.Normal);
				}
				string contents = XDocument.Parse(XamlWriter.Save(this)).ToString();
				File.WriteAllText(settingsFilePath, contents);
			}
			catch (Exception ex)
			{
				SystemEnvironment.Logger.Log(ex.Message, Category.Exception, Priority.Low);
			}
		}
	}
	public class ApwnCommand : RelayActionCommand
	{
		public ApwnCommand(Action execute)
			: base(execute)
		{
		}

		public ApwnCommand(Action execute, Func<bool> canExecute)
			: base(execute, canExecute)
		{
		}

		public ApwnCommand(Action execute, UIElement commandTarget, KeyGesture keyGesture)
			: base(execute)
		{
			if (commandTarget == null)
			{
				throw new ArgumentNullException("commandTarget");
			}
			if (keyGesture == null)
			{
				throw new ArgumentNullException("keyGesture");
			}
			commandTarget.InputBindings.Add(new KeyBinding(this, keyGesture));
		}

		public ApwnCommand(Action execute, Func<bool> canExecute, UIElement commandTarget, KeyGesture keyGesture)
			: base(execute, canExecute)
		{
			if (commandTarget == null)
			{
				throw new ArgumentNullException("commandTarget");
			}
			if (keyGesture == null)
			{
				throw new ArgumentNullException("keyGesture");
			}
			commandTarget.InputBindings.Add(new KeyBinding(this, keyGesture));
		}
	}
	public class ApwnCommand<T> : RelayActionCommand<T>
	{
		public ApwnCommand(Action<T> execute)
			: base(execute)
		{
		}

		public ApwnCommand(Action<T> execute, Func<T, bool> canExecute)
			: base(execute, canExecute)
		{
		}

		public ApwnCommand(Action<T> execute, UIElement commandTarget, KeyGesture keyGesture)
			: base(execute)
		{
			if (commandTarget == null)
			{
				throw new ArgumentNullException("commandTarget");
			}
			if (keyGesture == null)
			{
				throw new ArgumentNullException("keyGesture");
			}
			commandTarget.InputBindings.Add(new KeyBinding(this, keyGesture));
		}

		public ApwnCommand(Action<T> execute, Func<T, bool> canExecute, UIElement commandTarget, KeyGesture keyGesture)
			: base(execute, canExecute)
		{
			if (commandTarget == null)
			{
				throw new ArgumentNullException("commandTarget");
			}
			if (keyGesture == null)
			{
				throw new ArgumentNullException("keyGesture");
			}
			commandTarget.InputBindings.Add(new KeyBinding(this, keyGesture));
		}
	}
	public class ApwnDocumentControl : ScreenDocumentControl, IPrintSupport
	{
		private DateTime _closingTime;

		private bool _isActive;

		public IApwnDocument ActiveDocument
		{
			get
			{
				if (base.UnityContainer != null)
				{
					IApwnApplication apwnApplication = base.UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
					if (apwnApplication != null)
					{
						return apwnApplication.ActiveDocument;
					}
				}
				return null;
			}
		}

		public bool IsActive
		{
			get
			{
				return _isActive;
			}
			private set
			{
				bool isActive = _isActive;
				if (value != isActive)
				{
					_isActive = value;
					OnIsActiveChanged(isActive, _isActive);
				}
			}
		}

		public virtual bool CanPrintPreview => false;

		public virtual bool CanPrint => false;

		protected virtual void OnIsActiveChanged(bool oldValue, bool newValue)
		{
		}

		public void SetIsActiveStatus(bool isActive)
		{
			IsActive = isActive;
		}

		public ApwnDocumentControl()
		{
			base.AllowDocking = true;
			if (SystemEnvironment.ApplicationSettings.ShouldLogFormOpenTimeAtStatusBar)
			{
				Dispatcher.CurrentDispatcher.BeginInvoke((Action<DateTime>)delegate(DateTime timeBefore)
				{
					double totalMilliseconds = (DateTime.Now - timeBefore).TotalMilliseconds;
					string text = $"{base.Header}'s loading time (ms): {totalMilliseconds}";
					base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateStatusTextEvent>().Publish(new UpdateStatusTextEventArgs(text));
				}, DispatcherPriority.Input, DateTime.Now);
			}
			base.Dispatcher.BeginInvoke(new Action(ResetParentCloseAction), DispatcherPriority.Render);
		}

		private void ResetParentCloseAction()
		{
			if (base.Parent is ContentPane contentPane)
			{
				contentPane.CloseAction = PaneCloseAction.RemovePane;
			}
		}

		protected override void OnClosing(CancelEventArgs args)
		{
			if (SystemEnvironment.ApplicationSettings.ShouldLogFormOpenTimeAtStatusBar)
			{
				_closingTime = DateTime.Now;
			}
			base.OnClosing(args);
		}

		protected override void OnClosed(EventArgs eventArgs)
		{
			base.OnClosed(eventArgs);
			if (SystemEnvironment.ApplicationSettings.ShouldLogFormOpenTimeAtStatusBar)
			{
				double totalMilliseconds = (DateTime.Now - _closingTime).TotalMilliseconds;
				string text = $"{base.Header}'s closing time (ms): {totalMilliseconds}";
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateStatusTextEvent>().Publish(new UpdateStatusTextEventArgs(text));
			}
		}

		public override bool CanReplaceScreen()
		{
			return false;
		}

		public virtual IEnumerable<FrameworkElement> GeneratePrintPages(System.Windows.Size availablePrintSize)
		{
			return null;
		}

		public virtual bool DoCustomPrintPreview()
		{
			return false;
		}

		public virtual bool DoCustomPrint()
		{
			return false;
		}

		public virtual bool DoCustomPrintSetup()
		{
			return false;
		}

		public static bool IsMainNodeExisting(IUnityContainer container, string mainNodePath)
		{
			IApwnApplication apwnApplication = container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
			if (apwnApplication != null && apwnApplication.ActiveDocument != null)
			{
				CxsCase cxsCase = apwnApplication.ActiveDocument.Case;
				if (cxsCase != null)
				{
					try
					{
						object obj = cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "HappNode", mainNodePath);
						if (obj != null && obj != DBNull.Value)
						{
							return true;
						}
					}
					catch (COMException)
					{
						return false;
					}
				}
			}
			return false;
		}
	}
	public class ApwnPanelControl : ScreenPanelControl
	{
		public IApwnDocument ActiveDocument
		{
			get
			{
				if (base.UnityContainer != null)
				{
					IApwnApplication apwnApplication = base.UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
					if (apwnApplication != null)
					{
						return apwnApplication.ActiveDocument;
					}
				}
				return null;
			}
		}

		public ApwnPanelControl()
		{
			base.AllowHiding = false;
		}
	}
	public class AsyncDelegateCommand<T> : ICommand
	{
		protected Func<T, Task> executeAsyncMethod;

		protected Func<T, bool> canExecute;

		public event EventHandler CanExecuteChanged;

		public AsyncDelegateCommand(Func<T, Task> executeMethod)
		{
			executeAsyncMethod = executeMethod;
		}

		public AsyncDelegateCommand(Func<T, Task> executeMethod, Func<T, bool> canExecuteMethod)
		{
			executeAsyncMethod = executeMethod;
			canExecute = canExecuteMethod;
		}

		public bool CanExecute(object parameter)
		{
			if (canExecute != null)
			{
				return canExecute((T)parameter);
			}
			return true;
		}

		public async void Execute(object parameter)
		{
			await executeAsyncMethod((T)parameter);
		}

		public void RaiseCanExecuteChanged()
		{
			if (this.CanExecuteChanged != null)
			{
				this.CanExecuteChanged(this, new EventArgs());
			}
		}
	}
	public class AttachedProperties : DependencyObject
	{
		public static readonly DependencyProperty IsTextBindingTriggerWithPropertyChangeProperty = DependencyProperty.RegisterAttached("IsTextBindingTriggerWithPropertyChange", typeof(bool), typeof(AttachedProperties), new PropertyMetadata(false, IsTextBindingTriggerWithPropertyChanged));

		public static bool GetIsTextBindingTriggerWithPropertyChange(DependencyObject obj)
		{
			return (bool)obj.GetValue(IsTextBindingTriggerWithPropertyChangeProperty);
		}

		public static void SetIsTextBindingTriggerWithPropertyChange(DependencyObject obj, bool value)
		{
			obj.SetValue(IsTextBindingTriggerWithPropertyChangeProperty, value);
		}

		private static void IsTextBindingTriggerWithPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			System.Windows.Controls.TextBox sender = d as System.Windows.Controls.TextBox;
			if (sender != null && (bool)e.NewValue)
			{
				sender.Loaded += delegate
				{
					SetBindingTrigger(sender);
				};
			}
		}

		private static void SetBindingTrigger(System.Windows.Controls.TextBox tb)
		{
			if (tb == null)
			{
				return;
			}
			BindingExpression bindingExpression = tb.GetBindingExpression(System.Windows.Controls.TextBox.TextProperty);
			if (bindingExpression != null && bindingExpression.ParentBinding != null)
			{
				System.Windows.Data.Binding binding = new System.Windows.Data.Binding
				{
					Converter = bindingExpression.ParentBinding.Converter,
					ConverterParameter = bindingExpression.ParentBinding.ConverterParameter,
					Mode = bindingExpression.ParentBinding.Mode,
					NotifyOnSourceUpdated = bindingExpression.ParentBinding.NotifyOnSourceUpdated,
					NotifyOnTargetUpdated = bindingExpression.ParentBinding.NotifyOnTargetUpdated,
					NotifyOnValidationError = bindingExpression.ParentBinding.NotifyOnValidationError,
					Path = bindingExpression.ParentBinding.Path,
					UpdateSourceTrigger = UpdateSourceTrigger.PropertyChanged,
					XPath = bindingExpression.ParentBinding.XPath
				};
				if (bindingExpression.ParentBinding.ElementName != null)
				{
					binding.ElementName = bindingExpression.ParentBinding.ElementName;
				}
				else if (bindingExpression.ParentBinding.Source != null)
				{
					binding.Source = bindingExpression.ParentBinding.Source;
				}
				else if (bindingExpression.DataItem != null)
				{
					binding.Source = bindingExpression.DataItem;
				}
				else
				{
					binding.Source = tb.DataContext;
				}
				tb.SetBinding(System.Windows.Controls.TextBox.TextProperty, binding);
				tb.GetBindingExpression(System.Windows.Controls.TextBox.TextProperty).UpdateTarget();
			}
		}
	}
	public static class AVCAEntryPoint
	{
		public const string MainEntryPointGuid = "D15457BD-ABEB-42DD-8463-C0F6CB677B1D";

		private const string AplusSimulator = "AspenPlus";

		private static bool _mainEntryPointChecked;

		private static Type _mainEntryPointType;

		private static Type MainEntryPointType
		{
			get
			{
				if (!_mainEntryPointChecked)
				{
					try
					{
						_mainEntryPointType = Type.GetTypeFromCLSID(new Guid("D15457BD-ABEB-42DD-8463-C0F6CB677B1D"));
					}
					catch (Exception ex)
					{
						SystemEnvironment.Logger.Log(ex.Message, Category.Exception, Priority.High);
					}
					_mainEntryPointChecked = true;
				}
				return _mainEntryPointType;
			}
		}

		public static bool IsAvcaAvailable => MainEntryPointType != null;

		public static void DoInitialization(IUnityContainer container)
		{
			ExecuteVersionCompareMethod("DoInitialization", "AspenPlus", container);
		}

		public static void Start(CxsCase cxsCase)
		{
			ExecuteVersionCompareMethod("Start", "AspenPlus", cxsCase);
		}

		public static void ShowSingleCompareScreen(CxsCase cxsCase, IUnityContainer container)
		{
			ExecuteVersionCompareMethod("ShowSingleCompareScreen", "AspenPlus", cxsCase, container);
		}

		private static void ExecuteVersionCompareMethod(string methodName, params object[] parameters)
		{
			if (string.IsNullOrWhiteSpace(methodName))
			{
				throw new ArgumentException("Parameter methodName cannot be null or white space.");
			}
			try
			{
				if (!(MainEntryPointType != null))
				{
					return;
				}
				object obj = Activator.CreateInstance(MainEntryPointType);
				if (obj != null)
				{
					MethodInfo method = MainEntryPointType.GetMethod(methodName);
					if (method != null)
					{
						method.Invoke(obj, parameters);
					}
				}
			}
			catch (Exception ex)
			{
				SystemEnvironment.Logger.Log(ex.Message, Category.Exception, Priority.High);
			}
		}
	}
	public class CaseFileSettings
	{
		[DefaultValue(null)]
		public string EOSearchDialogSettings { get; set; }

		[DefaultValue(null)]
		public string EOVariableFormSettings { get; set; }

		[DefaultValue(null)]
		public string StreamSummaryFormSettings { get; set; }

		[DefaultValue(null)]
		public string AOLTempFolderPath { get; set; }

		[DefaultValue(null)]
		public string AOLTempProjectName { get; set; }

		public static CaseFileSettings Default { get; private set; }

		static CaseFileSettings()
		{
			Default = new CaseFileSettings();
		}

		public static void RestoreDefault(string settings)
		{
			if (string.IsNullOrEmpty(settings))
			{
				return;
			}
			try
			{
				if (XamlReader.Parse(settings) is CaseFileSettings caseFileSettings)
				{
					Default = caseFileSettings;
				}
			}
			catch (Exception)
			{
			}
		}

		public static string SaveDefault()
		{
			if (Default != null)
			{
				return XamlWriter.Save(Default);
			}
			return null;
		}
	}
	public static class CustomCusors
	{
		private const string BlackCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.black_cursor.ani";

		private const string BlueCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.blue_cursor.ani";

		private const string MaroonCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.maroon_cursor.ani";

		private const string RedCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.red_cursor.ani";

		private const string WhiteCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.white_cursor.ani";

		private const string RunCursorResource = "AspenTech.AspenPlus.Infrastructure.Cursors.run_icon_cursor.ani";

		private static IDictionary<string, System.Windows.Input.Cursor> _cursors;

		public static System.Windows.Input.Cursor SimulatingCursorBlack => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.black_cursor.ani");

		public static System.Windows.Input.Cursor SimulatingCursorBlue => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.blue_cursor.ani");

		public static System.Windows.Input.Cursor SimulatingCursorMaroon => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.maroon_cursor.ani");

		public static System.Windows.Input.Cursor SimulatingCursorRed => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.red_cursor.ani");

		public static System.Windows.Input.Cursor SimulatingCursorWhite => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.white_cursor.ani");

		public static System.Windows.Input.Cursor SimulatingCursorRunButton => QueryCursor("AspenTech.AspenPlus.Infrastructure.Cursors.run_icon_cursor.ani");

		private static System.Windows.Input.Cursor QueryCursor(string cursorResource)
		{
			if (_cursors == null)
			{
				_cursors = new Dictionary<string, System.Windows.Input.Cursor>();
			}
			if (_cursors.ContainsKey(cursorResource))
			{
				return _cursors[cursorResource];
			}
			using (Stream stream = typeof(CustomCusors).Assembly.GetManifestResourceStream(cursorResource))
			{
				if (stream != null)
				{
					System.Windows.Input.Cursor cursor = new System.Windows.Input.Cursor(stream);
					_cursors[cursorResource] = cursor;
					return cursor;
				}
			}
			return null;
		}
	}
	public class CustomModelsEditorScreenSubject : ScreenSubject
	{
		public ACMModelInfo ModelInfo { get; set; }
	}
	public enum ModelType
	{
		Installed,
		Saved,
		New,
		Template
	}
	public enum ModelStatus
	{
		ReadyToDeploy = 0,
		Incomplete = 2
	}
	public class ACMModelInfo
	{
		private string _displayName;

		private string _modelName;

		private string _atmlzFilePath;

		private string _atmlzRelativePath;

		private string _versionString;

		private DateTime _modifiedTime = DateTime.MinValue;

		private string _revisionGuid;

		private FileStream _fsLock;

		private bool _modelNotEditable;

		public string DisplayName
		{
			get
			{
				if (ExpModelInfoObject != null && _displayName == null)
				{
					_displayName = ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Display");
				}
				return _displayName;
			}
			set
			{
				_displayName = value;
			}
		}

		public string ModelName
		{
			get
			{
				if (ExpModelInfoObject != null && _modelName == null)
				{
					_modelName = ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Name");
				}
				return _modelName;
			}
			set
			{
				_modelName = value;
			}
		}

		public string DeployedFolder
		{
			get
			{
				string text = VersionString;
				if (string.IsNullOrEmpty(text))
				{
					text = SystemEnvironment.InternalVersionString;
				}
				return Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech", "AES", "AM Models", text);
			}
		}

		public string SavedFolder => Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "AspenTech", SystemEnvironment.ApplicationNameWithPathVersion, "AM Models");

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public string AtmlzFilePath
		{
			get
			{
				if (string.IsNullOrEmpty(_atmlzFilePath) && !string.IsNullOrEmpty(_atmlzRelativePath))
				{
					if (ModelType == ModelType.Installed)
					{
						_atmlzFilePath = Path.Combine(DeployedFolder, _atmlzRelativePath);
					}
					else if (ModelType == ModelType.Saved)
					{
						_atmlzFilePath = Path.Combine(SavedFolder, _atmlzRelativePath);
					}
				}
				return _atmlzFilePath;
			}
			set
			{
				_atmlzFilePath = value;
			}
		}

		public string AtmlzRelativePath
		{
			get
			{
				if (string.IsNullOrEmpty(_atmlzRelativePath) && !string.IsNullOrEmpty(AtmlzFilePath))
				{
					if (ModelType == ModelType.Installed)
					{
						string text = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech", "AES", "AM Models", SystemEnvironment.InternalVersionString);
						_atmlzRelativePath = AtmlzFilePath.Substring(text.Length + 1);
					}
					else if (ModelType == ModelType.Saved)
					{
						string text2 = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal), "AspenTech", SystemEnvironment.ApplicationNameWithPathVersion, "AM Models");
						_atmlzRelativePath = AtmlzFilePath.Substring(text2.Length + 1);
					}
					else
					{
						_atmlzRelativePath = AtmlzFilePath;
					}
				}
				return _atmlzRelativePath;
			}
			set
			{
				_atmlzRelativePath = value;
			}
		}

		public string VersionString
		{
			get
			{
				if (ExpModelInfoObject != null && _versionString == null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Version");
				}
				return _versionString;
			}
			set
			{
				_versionString = value;
			}
		}

		public ModelType ModelType { get; set; }

		public ModelStatus Status
		{
			get
			{
				if (ExpModelInfoObject != null && ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Compiled") == "1")
				{
					return ModelStatus.ReadyToDeploy;
				}
				return ModelStatus.Incomplete;
			}
		}

		public DateTime ModifiledTime
		{
			get
			{
				if (ExpModelInfoObject != null && _modifiedTime < new DateTime(1900, 1, 1))
				{
					return ParseTime(ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Timestamp"));
				}
				return _modifiedTime;
			}
			set
			{
				_modifiedTime = value;
			}
		}

		public string RevisionGuid
		{
			get
			{
				if (ExpModelInfoObject != null && _revisionGuid == null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "RevisionGuid");
				}
				return _revisionGuid;
			}
			set
			{
				_revisionGuid = value;
			}
		}

		public string Description
		{
			get
			{
				if (ModelForEdit != null && ModelForEdit.ExpModelInfoObject != null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ModelForEdit.ExpModelInfoObject, "Description");
				}
				if (ExpModelInfoObject != null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Description");
				}
				return null;
			}
			set
			{
				if (ModelForEdit != null && ModelForEdit.ExpModelInfoObject != null)
				{
					object oModel = ACMModelLibraryHelper.ACM_OpenModelFile(ModelForEdit.AtmlzFilePath);
					ACMModelLibraryHelper.ACM_SetModelProperty(oModel, "Description", value);
					ACMModelLibraryHelper.ACM_ModelSaveTo(oModel, ModelForEdit.AtmlzFilePath, bOverwrite: true);
					ACMModelLibraryHelper.ACM_CloseModelFile(oModel);
				}
				else if (ExpModelInfoObject != null)
				{
					object oModel2 = ACMModelLibraryHelper.ACM_OpenModelFile(AtmlzFilePath);
					ACMModelLibraryHelper.ACM_SetModelProperty(oModel2, "Description", value);
					ACMModelLibraryHelper.ACM_ModelSaveTo(oModel2, AtmlzFilePath, bOverwrite: true);
					ACMModelLibraryHelper.ACM_CloseModelFile(oModel2);
				}
			}
		}

		public string Compiled
		{
			get
			{
				if (ModelForEdit != null && ModelForEdit.ExpModelInfoObject != null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ModelForEdit.ExpModelInfoObject, "Compiled");
				}
				if (ExpModelInfoObject != null)
				{
					return ACMModelLibraryHelper.ACM_GetModelInfoProperty(ExpModelInfoObject, "Compiled");
				}
				return null;
			}
			set
			{
				if (ModelForEdit != null && ModelForEdit.ExpModelInfoObject != null)
				{
					object oModel = ACMModelLibraryHelper.ACM_OpenModelFile(ModelForEdit.AtmlzFilePath);
					ACMModelLibraryHelper.ACM_SetModelProperty(oModel, "Compiled", value);
					ACMModelLibraryHelper.ACM_ModelSaveTo(oModel, AtmlzFilePath, bOverwrite: true);
					ACMModelLibraryHelper.ACM_CloseModelFile(oModel);
				}
				else if (ExpModelInfoObject != null)
				{
					object oModel2 = ACMModelLibraryHelper.ACM_OpenModelFile(AtmlzFilePath);
					ACMModelLibraryHelper.ACM_SetModelProperty(oModel2, "Compiled", value);
					ACMModelLibraryHelper.ACM_ModelSaveTo(oModel2, AtmlzFilePath, bOverwrite: true);
					ACMModelLibraryHelper.ACM_CloseModelFile(oModel2);
				}
			}
		}

		public object ExpModelInfoObject { get; private set; }

		public ACMModelInfo ModelForEdit { get; set; }

		public bool Locked
		{
			get
			{
				return _fsLock != null;
			}
			set
			{
				if (value)
				{
					if (_fsLock == null && ExpModelInfoObject != null)
					{
						_fsLock = File.Open(AtmlzFilePath, FileMode.Open, FileAccess.Read, FileShare.Read);
					}
				}
				else if (_fsLock != null)
				{
					_fsLock.Dispose();
					_fsLock = null;
				}
			}
		}

		public bool NotEditable
		{
			get
			{
				return _modelNotEditable;
			}
			set
			{
				_modelNotEditable = value;
			}
		}

		public ACMModelInfo()
		{
		}

		public ACMModelInfo(string atmlzFilePath, ModelType modelType, object modelInfoObject = null)
		{
			AtmlzFilePath = atmlzFilePath;
			ModelType = modelType;
			if (modelInfoObject != null)
			{
				ExpModelInfoObject = modelInfoObject;
			}
			else if (!string.IsNullOrEmpty(atmlzFilePath))
			{
				ExpModelInfoObject = ACMModelLibraryHelper.GetModelFileInfo(atmlzFilePath);
			}
		}

		public static DateTime ParseTime(string tstamp)
		{
			string format = "yyyy.M.d.H.m.s";
			if (tstamp == null || tstamp == "")
			{
				return DateTime.MinValue;
			}
			if (!DateTime.TryParseExact(tstamp, format, null, DateTimeStyles.AssumeLocal, out var result))
			{
				return DateTime.MinValue;
			}
			return result;
		}

		public override bool Equals(object obj)
		{
			if (obj is ACMModelInfo aCMModelInfo)
			{
				if (ModelName == aCMModelInfo.ModelName)
				{
					return VersionString == aCMModelInfo.VersionString;
				}
				return false;
			}
			return false;
		}
	}
	public class ExceptionHelper
	{
		public static void Log(Exception e, IUnityContainer container, string title, string source, bool showDebug = false)
		{
			if (e == null || container == null)
			{
				return;
			}
			try
			{
				ILoggerFacade loggerFacade = container.Resolve<ILoggerFacade>(Array.Empty<ResolverOverride>());
				if (loggerFacade != null)
				{
					string text = string.Format(CultureInfo.InvariantCulture, "Unexpected Exception Caught in {0}:{3}   {1} {2}{3}    Exception Stack {4}", source, e.GetType().ToString(), e.Message, Environment.NewLine, e.StackTrace);
					string text2 = "  ";
					while (e.InnerException != null)
					{
						text += string.Format(CultureInfo.InvariantCulture, "{2}{4}Inner Exception {0} {1}{2}{4}    Inner Exception Stack {3}", e.InnerException.GetType().ToString(), e.InnerException.Message, Environment.NewLine, e.InnerException.StackTrace, text2);
						text2 += "  ";
						e = e.InnerException;
					}
					loggerFacade.Log(text, Category.Exception, Priority.Medium);
				}
			}
			catch (Exception)
			{
			}
		}
	}
	public interface IColumnAnalysisPresenter
	{
		bool TryAttachColumnInternalsContextualRibbon(ScreenContentControl screen);

		void ShowHydraulicPlotsScreen(IUnityContainer container, string columnOptionDataPath, string suggestedScreenTitle, ShowScreenOptions screenOptions);

		void CloseHydraulicPlotsScreen(IUnityContainer container, string columnOptionDataPath);
	}
	public interface IFlowsheetScreenPresenter
	{
		void ShowFlowsheetScreen(string navigationGroupKey, string flowsheetHierarchy = null);
	}
	public interface IFormedScreenInfo
	{
		ShowFormEventArgs FormArgs { get; }
	}
	public static class FormedScreenInfoExtensions
	{
		public static string GetMainNodePath(this IFormedScreenInfo si)
		{
			if (si == null)
			{
				throw new ArgumentNullException("si");
			}
			if (si.FormArgs != null)
			{
				return si.FormArgs.PathKey;
			}
			return null;
		}

		public static string GetFormKey(this IFormedScreenInfo si)
		{
			if (si == null)
			{
				throw new ArgumentNullException("si");
			}
			if (si.FormArgs != null)
			{
				return si.FormArgs.FormKey;
			}
			return null;
		}
	}
	public interface IHybridVariableListPresenter
	{
		bool? ExecuteListVariables(UIElement inputElement);
	}
	public interface IMarketPlaceControl
	{
		void Initialize(Action<string> openFileAction, Action refreshModelPaletteAction, Action<string> importFileAction, Func<string> currentCaseFile, object objContext, object marketplacelauncher);
	}
	public class ApwnException : Exception
	{
		public ApwnException(string message)
			: base(message)
		{
		}

		public ApwnException(string message, Exception innerException)
			: base(message, innerException)
		{
		}
	}
	public class BrowserScreenSubject : ScreenSubject
	{
		public bool IsSuppressed { get; set; }

		public Uri Uri { get; set; }

		public string Title { get; set; }
	}
	public class IsStringValueToCollapsedConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && parameter != null && value.ToString() == parameter.ToString())
			{
				return Visibility.Collapsed;
			}
			return Visibility.Visible;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class IsStringValueToVisibleConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || parameter == null)
			{
				return Visibility.Collapsed;
			}
			string[] array = parameter.ToString().Split(',');
			if (array == null)
			{
				return Visibility.Collapsed;
			}
			if (array.Length == 1 && string.Equals(array[0], "AllDataGroup"))
			{
				return Visibility.Visible;
			}
			string[] array2 = array;
			foreach (string text in array2)
			{
				object value2 = typeof(NavigationGroupKeys).GetField(text.Trim()).GetValue(null);
				if (value2 != null && string.Equals(value.ToString(), value2.ToString(), StringComparison.OrdinalIgnoreCase))
				{
					return Visibility.Visible;
				}
			}
			return Visibility.Collapsed;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class IsNotStringValueToBooleanConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && parameter != null && value.ToString() == parameter.ToString())
			{
				return false;
			}
			return true;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class IsStringValueToBooleanConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && parameter != null && value.ToString() == parameter.ToString())
			{
				return true;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class NotNullToBooleanConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || value == DependencyProperty.UnsetValue)
			{
				return false;
			}
			return true;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class CommaSplittedStringListToBoolConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || value == DependencyProperty.UnsetValue || parameter == null || parameter == DependencyProperty.UnsetValue)
			{
				return false;
			}
			string[] array = parameter.ToString().Split(',');
			if (array == null)
			{
				return false;
			}
			if (array.Length == 1 && string.Equals(array[0], "AllDataGroup"))
			{
				return true;
			}
			string[] array2 = array;
			foreach (string text in array2)
			{
				object value2 = typeof(NavigationGroupKeys).GetField(text.Trim()).GetValue(null);
				if (value2 != null && string.Equals(value.ToString(), value2.ToString(), StringComparison.OrdinalIgnoreCase))
				{
					return true;
				}
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public interface IApplication
	{
		string ApplicationTitle { get; }
	}
	public interface IApwnApplication : IApplication
	{
		IApwnDocument ActiveDocument { get; }

		event EventHandler ActiveDocumentChanged;
	}
	public enum ProblemModes
	{
		Properties,
		Simulation,
		Dyanmics,
		EnergyAnalysis,
		PSVPlus
	}
	public interface IApwnDocument
	{
		IApwnApplication Application { get; }

		CxsCase Case { get; }

		ProblemModes ActiveMode { get; set; }

		int FileVersionNumber { get; }

		bool IsCurrentFlowsheetBatch { get; }

		bool CurrentBatchProcessInteractive { get; }

		string SolutionMode { get; set; }

		bool IsSaving { get; }

		bool ShowHierarchyScreen(string fullPath);

		object GetHierarchyContent();

		object GetActivePFS();

		void OnAutomationOpen(string fileName);

		void OnActivateShell();

		void UpdateAllForms();

		void UpdateStatus(string sStatus);
	}
	public interface IApwnSimulationViewModel
	{
		void Initialize(string strLoad, IApwnDocument document);

		void Load(object view);

		void Unload(object view);

		void Clear();

		string Save();

		string Messages();

		void OnSimStopped();

		void OnStopPending();

		void WriteLine(string text);
	}
	public interface IApwnSimulationCommands
	{
		IApwnDocument Document { get; set; }
	}
	public abstract class SimualationSequenceNode
	{
		public abstract ImageSource Image { get; }

		public abstract string Text { get; }

		public abstract string Tooltip { get; }

		public abstract bool IsSelected { get; set; }

		public abstract bool IsExpanded { get; }
	}
	public interface IAXEmbeddedObject
	{
		bool SupportsZoom { get; }

		bool Loading { get; set; }

		bool IsPFSObject { get; set; }

		bool IsEditMode { get; set; }

		void CopyAXEmbeddedObjectContent();

		bool CanAXEmbeddedObjectCopy();

		void Zoom(double factor);

		void GetContentSize(ref int nWidth, ref int nHeight);

		void CompactView();

		void UpdateAXData();

		void ResetInternalStatus();

		void NotifyUpdatedData();

		bool PreparePrintingData(string strCageKey);

		void DisposePrintingData(string strCageKey);

		void SetupDataGridCage(string strCageKey);

		void Close();
	}
	public interface IDialogManager
	{
		void ShowDialog(DriveDialogEventArgs args);
	}
	public class DriveDialogEventArgs : EventArgs
	{
		private Dictionary<string, object> _formParameters = new Dictionary<string, object>();

		public string DialogName { get; set; }

		public Type DialogType { get; set; }

		public string DialogTitle { get; set; }

		public bool? DialogResult { get; set; }

		public object[] Params { get; set; }

		public IApwnDocument Doc { get; set; }

		public FrameworkElement Owner { get; set; }

		public Dictionary<string, object> FormParameters => _formParameters;

		public int? PreferredWidth { get; set; }

		public int? PreferredHeight { get; set; }

		public ResizeMode ResizeMode { get; set; }
	}
	public class DriveDialogEvent : RoutedCompositePresentationEvent<DriveDialogEventArgs>
	{
		public DriveDialogEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfParentsThenActiveWindow;
		}
	}
	public interface IEOVariableListPresenter
	{
		bool CanExecuteListVariables(UIElement inputElement, bool isUpdateRequired = false);

		bool? ExecuteListVariables(UIElement inputElement);
	}
	public interface IModelLibraryPresenter
	{
		ApwnPanelControl ActivePalette { get; }

		bool HasEditableModelLibrary { get; }

		bool CanEditCurrentIcon { get; }

		bool BatchProcessMode { get; set; }

		void ShowModelLibraryPalette();

		void CloseModelLibraryPalette();

		void ShowModelLibraryManagerWindow();

		void ShowManageHybridLibraries();

		void ShowPaletteCategoriesWindow();

		void ShowManageACMLibraries();

		bool ShowAddNewLibraryWindow();

		void AddSelected(IAModel documentRootModel, IAModel screenRootModel, IAModel currentModel, IEnumAModel selectedModels);

		void AddCase(IAModel rootModel);

		bool CanAppendToTemplate(IAModel documentRootModel, IHNode sourceNode);

		void AppendToTemplate(IAModel documentRootModel, IHNode sourceNode);

		void EditCurrentIcon();
	}
	public interface IMolecularEditorPresenter
	{
		void SimplyOpenMolecularEditor();

		string[] OpenMolecularEditor(string[] molefileContentAsLines, bool forTDE, ref string fragmentName, out int fragmentConsistency, out bool changed);

		string[] CheckMolecularEditor(string[] molefileContentAsLines, out int fragmentConsistency);

		object CreateBitmapForMolefile(string[] molefileContentAsLines);

		object CreateBitmapForMolefileInSpecialSize(string[] molefileContentAsLines, double width, double height);

		void GenerateConnectionTable(string[] molefileContentAsLines, out int[] startAtomIndexes, out int[] endAtomIndexes, out string[] startAtomSymbols, out string[] endAtomSymbols, out int[] bondTypes, out string[] formulaAtomSymbols, out int[] formularAtomCounts);
	}
	[Module(ModuleName = "AspenTech.AspenPlus.Infrastructure.InfrastructureModule")]
	public class InfrastructureModule : IModule
	{
		public const string ModuleName = "AspenTech.AspenPlus.Infrastructure.InfrastructureModule";

		public IUnityContainer Container { get; private set; }

		public InfrastructureModule(IUnityContainer container)
		{
			Container = container;
			SystemEnvironment.unityContainer = container;
		}

		public void Initialize()
		{
		}
	}
	public interface IPathNavigatorScreenSubject
	{
		string NavigatorPath { get; }
	}
	public interface IPlotInfoExportable
	{
		string ExportPlotInfo();
	}
	public interface IPlotWizardTemplate
	{
		void SetCaption(ref string caption);

		void SetMinHeight(ref double minHeight);

		void SetMinWidth(ref double minWidth);

		void SetDefaultHeight(ref double defaultHeight);

		void SetDefaultWidth(ref double defaultWidth);
	}
	public interface IPrintPresenter
	{
		bool CanPrint { get; }

		bool CanPrintPreview { get; }

		bool CanPrintSetup { get; }

		void DoPrint();

		void DoPrintPreview();

		void DoPrintSetup();
	}
	public interface IPrintSupport
	{
		bool CanPrint { get; }

		bool CanPrintPreview { get; }

		IEnumerable<FrameworkElement> GeneratePrintPages(System.Windows.Size availablePrintSize);

		bool DoCustomPrintPreview();

		bool DoCustomPrint();

		bool DoCustomPrintSetup();
	}
	public interface IRibbonEmbeddable
	{
		string TargetRibbonTab { get; }

		IEnumerable<RibbonGroup> RibbonGroups { get; }
	}
	public static class RibbonEmbedHelper
	{
		private static readonly Dictionary<RibbonGroup, IRibbonEmbeddable> GroupToScreenDict = new Dictionary<RibbonGroup, IRibbonEmbeddable>();

		public static void UpdateEmbeddedRibbon(IRibbonEmbeddable oldScreen, IRibbonEmbeddable newScreen, XamRibbon hostRibbon)
		{
			if (hostRibbon == null)
			{
				throw new ArgumentNullException("hostRibbon");
			}
			if (oldScreen != null)
			{
				Dispatcher.CurrentDispatcher.BeginInvoke((Action)delegate
				{
					RemoveEmbeddedRibbon(oldScreen);
				}, DispatcherPriority.Input);
			}
			if (newScreen != null)
			{
				Dispatcher.CurrentDispatcher.BeginInvoke((Action)delegate
				{
					AppendEmbeddedRibbon(newScreen, hostRibbon);
				}, DispatcherPriority.Input);
			}
		}

		public static void UpdateEmbeddedRibbon(IRibbonEmbeddable screen)
		{
			if (screen == null)
			{
				throw new ArgumentNullException("screen");
			}
			if (screen is ApwnDocumentControl { UnityContainer: not null } apwnDocumentControl)
			{
				IShellApplication shellApplication = apwnDocumentControl.UnityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null && shellApplication.ActiveWindow != null && shellApplication.ActiveWindow.ActiveDocumentScreen == apwnDocumentControl)
				{
					XamRibbon ribbon = (shellApplication.ActiveWindow as CommonShellWindow).Ribbon;
					RemoveEmbeddedRibbon(screen);
					AppendEmbeddedRibbon(screen, ribbon);
				}
			}
		}

		public static void ClearEmbededRibbons()
		{
			foreach (RibbonGroup key in GroupToScreenDict.Keys)
			{
				if (key.Parent is RibbonTabItem ribbonTabItem)
				{
					((Collection<RibbonGroup>)(object)ribbonTabItem.RibbonGroups).Remove(key);
				}
			}
			GroupToScreenDict.Clear();
		}

		private static void RemoveEmbeddedRibbon(IRibbonEmbeddable screen)
		{
			if (screen == null)
			{
				throw new ArgumentNullException("screen");
			}
			List<KeyValuePair<RibbonGroup, IRibbonEmbeddable>> list = GroupToScreenDict.Where((KeyValuePair<RibbonGroup, IRibbonEmbeddable> p) => p.Value == screen).ToList();
			foreach (KeyValuePair<RibbonGroup, IRibbonEmbeddable> item in list)
			{
				if (item.Key.Parent is RibbonTabItem ribbonTabItem)
				{
					try
					{
						TryCloseMenuToolIfAny(item.Key);
						((Collection<RibbonGroup>)(object)ribbonTabItem.RibbonGroups).Remove(item.Key);
					}
					catch (NullReferenceException ex)
					{
						SystemEnvironment.Logger.Log(ex.Message + "\r\n" + ex.StackTrace, Category.Exception, Priority.Low);
					}
				}
			}
			foreach (KeyValuePair<RibbonGroup, IRibbonEmbeddable> item2 in list)
			{
				GroupToScreenDict.Remove(item2.Key);
			}
		}

		private static void TryCloseMenuToolIfAny(RibbonGroup ribbonGroup)
		{
			foreach (object item in (IEnumerable)ribbonGroup.Items)
			{
				if (item is MenuTool { IsOpen: not false } menuTool)
				{
					menuTool.IsOpen = false;
				}
			}
		}

		private static bool FindRibbonTabItemByName(RibbonTabItem rtTab, RibbonGroup rgTarget)
		{
			foreach (RibbonGroup item in ((IEnumerable<RibbonGroup>)rtTab.RibbonGroups).ToList())
			{
				if (!string.IsNullOrWhiteSpace(item.Caption) && string.Equals(item.Caption.Trim(), rgTarget.Caption.Trim(), StringComparison.CurrentCultureIgnoreCase))
				{
					return true;
				}
			}
			return false;
		}

		private static void AppendEmbeddedRibbon(IRibbonEmbeddable screen, XamRibbon hostRibbon)
		{
			if (screen == null)
			{
				throw new ArgumentNullException("screen");
			}
			if (hostRibbon == null)
			{
				throw new ArgumentNullException("hostRibbon");
			}
			if (screen.RibbonGroups == null)
			{
				return;
			}
			RibbonTabItem ribbonTabItem = FindRibbonTabItem(screen, hostRibbon);
			if (ribbonTabItem == null)
			{
				return;
			}
			bool flag = false;
			foreach (RibbonGroup item in screen.RibbonGroups.ToList())
			{
				if (!FindRibbonTabItemByName(ribbonTabItem, item) && !((Collection<RibbonGroup>)(object)ribbonTabItem.RibbonGroups).Contains(item))
				{
					if (item.Parent is RibbonTabItem ribbonTabItem2)
					{
						((Collection<RibbonGroup>)(object)ribbonTabItem2.RibbonGroups).Remove(item);
					}
					GroupToScreenDict[item] = screen;
					try
					{
						((Collection<RibbonGroup>)(object)ribbonTabItem.RibbonGroups).Add(item);
					}
					catch (Exception)
					{
						flag = true;
					}
				}
			}
			if (flag && ((TabItem)(object)ribbonTabItem).IsSelected)
			{
				((TabItem)(object)ribbonTabItem).IsSelected = false;
				((UIElement)(object)hostRibbon).UpdateLayout();
				((TabItem)(object)ribbonTabItem).IsSelected = true;
				((UIElement)(object)hostRibbon).UpdateLayout();
			}
		}

		private static RibbonTabItem FindRibbonTabItem(IRibbonEmbeddable screen, XamRibbon hostRibbon)
		{
			string targetRibbonTab = screen.TargetRibbonTab;
			if (!string.IsNullOrWhiteSpace(targetRibbonTab))
			{
				List<RibbonTabItem> list = hostRibbon.Tabs.ToList();
				foreach (ContextualTabGroup item in (Collection<ContextualTabGroup>)(object)hostRibbon.ContextualTabGroups)
				{
					if (item.IsVisible)
					{
						list.AddRange((IEnumerable<RibbonTabItem>)item.Tabs);
					}
				}
				foreach (RibbonTabItem item2 in list)
				{
					if (((UIElement)(object)item2).Visibility != Visibility.Visible)
					{
						continue;
					}
					string name = ((FrameworkElement)(object)item2).Name;
					if (!string.IsNullOrWhiteSpace(name))
					{
						string text = "Properties" + targetRibbonTab.Trim();
						if (string.Equals(name.Trim(), targetRibbonTab.Trim(), StringComparison.CurrentCultureIgnoreCase))
						{
							return item2;
						}
						if (string.Equals(name.Trim(), text.Trim(), StringComparison.CurrentCultureIgnoreCase))
						{
							return item2;
						}
					}
				}
			}
			return null;
		}
	}
	public class ParametricData
	{
		private int m_ncurve;

		private List<double> m_par_value;

		private int m_size;

		private List<long> m_curve_num;

		public ParametricData()
		{
			m_ncurve = 0;
			m_size = 0;
			m_par_value = new List<double>();
			m_curve_num = new List<long>();
		}

		public void AddData(long loc, double par_value)
		{
			int i;
			for (i = 0; i < m_ncurve; i++)
			{
				_ = m_par_value[i];
				if (m_par_value[i] == par_value)
				{
					break;
				}
			}
			if (i == m_ncurve)
			{
				m_ncurve++;
				if (m_par_value.Count <= i)
				{
					m_par_value.Add(par_value);
				}
				else
				{
					m_par_value[i] = par_value;
				}
			}
			if (loc >= m_size)
			{
				while (m_size < loc)
				{
					if (m_curve_num.Count <= m_size)
					{
						m_curve_num.Add(0L);
					}
					else
					{
						m_curve_num[m_size] = 0L;
					}
					m_size++;
				}
				m_size = (int)loc + 1;
			}
			if (m_curve_num.Count <= (int)loc)
			{
				m_curve_num.Add(i);
			}
			else
			{
				m_curve_num[(int)loc] = i;
			}
		}

		public void AddData2(long loc, double par_value)
		{
			bool flag = false;
			int i;
			for (i = 0; i < m_ncurve; i++)
			{
				if (m_par_value.FindIndex((double ditem) => ditem == par_value) != -1)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				m_ncurve++;
				m_par_value.Add(par_value);
			}
			if (loc >= m_size)
			{
				while (m_size < loc)
				{
					m_curve_num.Add(0L);
					m_size++;
				}
				m_size = (int)loc + 1;
			}
			m_curve_num.Add(i);
		}

		public long GetNCurve()
		{
			return m_ncurve;
		}

		public long GetCurve(long loc)
		{
			if (loc < 0 || loc >= m_size || loc > m_curve_num.Count())
			{
				return 0L;
			}
			return m_curve_num[(int)loc];
		}

		public double GetParValue(long ncurve)
		{
			if (ncurve < 0 || ncurve >= m_ncurve || ncurve > m_par_value.Count())
			{
				return double.NaN;
			}
			return m_par_value[(int)ncurve];
		}
	}
	public enum RibbonControlType
	{
		None,
		ComboBox,
		CheckBox,
		TextBox
	}
	public class DialogCls
	{
		private Window _hostWindow;

		private UIElement _uiElement;

		public DialogCls(UIElement uid)
		{
			_uiElement = uid;
			_hostWindow = new Window();
			_hostWindow.Width = 300.0;
			_hostWindow.Height = 150.0;
		}

		private void PopUpWindow()
		{
			Grid grid = new Grid();
			grid.Width = _hostWindow.Width;
			grid.Height = _hostWindow.Height;
			_hostWindow.Content = grid;
			grid.ColumnDefinitions.Add(new ColumnDefinition());
			grid.RowDefinitions.Add(new RowDefinition());
			grid.RowDefinitions.Add(new RowDefinition());
			System.Windows.Controls.Button button = new System.Windows.Controls.Button();
			button.IsEnabled = true;
			button.Width = 100.0;
			button.Height = 20.0;
			button.Content = "OK";
			button.Click += btn_Click;
			grid.Children.Add(button);
			grid.Children.Add(_uiElement);
			Grid.SetRow(_uiElement, 0);
			Grid.SetRow(button, 1);
			_hostWindow.ShowDialog();
		}

		public void ShowWindow()
		{
			PopUpWindow();
		}

		private void btn_Click(object sender, RoutedEventArgs e)
		{
			_hostWindow.Close();
		}
	}
	public class PWRPlotType
	{
		public string PoltHeaderType { get; set; }

		public string TagId { get; set; }

		public string DefTitle { get; set; }

		public string DefXAxisTitle { get; set; }

		public string DefYAxisTitle { get; set; }

		public string IndependentVar { get; set; }

		public string DependentVar { get; set; }

		public int UnitRow { get; set; }

		public string HelpFileName { get; set; }

		public int HelpId { get; set; }

		public string ImageId { get; set; }

		public int Basis { get; set; }
	}
	public class PWRParser
	{
		private static char[] TobeReplaced = new char[7] { '(', ')', '-', ' ', '.', '/', '\\' };

		private static char UnderLine = '_';

		public void ParseHeaderLine(string line, ref PWRPlotType pwrPlotType)
		{
			string[] array = line.Split(new string[1] { ", " }, StringSplitOptions.None);
			if (array.Length != 0)
			{
				string[] array2 = array[0].Split(new string[1] { " " }, StringSplitOptions.None);
				if (array2.Length > 1)
				{
					pwrPlotType.PoltHeaderType = array2[1];
				}
			}
			for (int i = 1; i < array.Length; i++)
			{
				switch (i)
				{
				case 1:
					pwrPlotType.TagId = array[i].Trim();
					break;
				case 2:
					pwrPlotType.ImageId = array[i].Trim();
					break;
				}
			}
		}

		public void ParseProperty(string line, ref PWRPlotType pwrPlotType)
		{
			string[] array = new string[9] { "PlotTitle", "XAxisTitle", "YAxisTitle", "IndepVar", "DepVar", "UnitRow", "HelpFileName", "HelpID", "Basis" };
			string[] array2 = line.Split('=');
			if (array2.Length > 1)
			{
				string text = array2[0];
				string text2 = array2[1];
				text = text.Trim();
				text2 = text2.Trim();
				if (string.Compare(text, array[0], ignoreCase: true) == 0)
				{
					string text3 = PlotPWRResource.ResourceManager.GetString(ConstructKey(pwrPlotType.PoltHeaderType, pwrPlotType.TagId, text));
					pwrPlotType.DefTitle = ((!string.IsNullOrEmpty(text3)) ? text3 : text2);
				}
				else if (string.Compare(text, array[1], ignoreCase: true) == 0)
				{
					string text4 = PlotPWRResource.ResourceManager.GetString(ConstructKey(pwrPlotType.PoltHeaderType, pwrPlotType.TagId, text));
					pwrPlotType.DefXAxisTitle = ((!string.IsNullOrEmpty(text4)) ? text4 : text2);
				}
				else if (string.Compare(text, array[2], ignoreCase: true) == 0)
				{
					string text5 = PlotPWRResource.ResourceManager.GetString(ConstructKey(pwrPlotType.PoltHeaderType, pwrPlotType.TagId, text));
					pwrPlotType.DefYAxisTitle = ((!string.IsNullOrEmpty(text5)) ? text5 : text2);
				}
				else if (string.Compare(text, array[3], ignoreCase: true) == 0)
				{
					pwrPlotType.IndependentVar = text2;
				}
				else if (string.Compare(text, array[4], ignoreCase: true) == 0)
				{
					pwrPlotType.DependentVar = text2;
				}
				else if (string.Compare(text, array[5], ignoreCase: true) == 0)
				{
					pwrPlotType.UnitRow = int.Parse(text2);
				}
				else if (string.Compare(text, array[6], ignoreCase: true) == 0)
				{
					pwrPlotType.HelpFileName = text2;
				}
				else if (string.Compare(text, array[7], ignoreCase: true) == 0)
				{
					pwrPlotType.HelpId = int.Parse(text2);
				}
				else if (string.Compare(text, array[8], ignoreCase: true) == 0)
				{
					pwrPlotType.Basis = int.Parse(text2);
				}
			}
		}

		public string ConstructKey(string plotHeaderType, string id, string input)
		{
			string text = plotHeaderType + UnderLine + id;
			char[] tobeReplaced = TobeReplaced;
			foreach (char oldChar in tobeReplaced)
			{
				text = text.Replace(oldChar, UnderLine);
			}
			return text + UnderLine + input;
		}

		public bool IsBeginPlot(string line)
		{
			return line.StartsWith("BeginPlot", StringComparison.CurrentCultureIgnoreCase);
		}

		public bool IsEndPlot(string line)
		{
			return line.StartsWith("EndPlot", StringComparison.CurrentCultureIgnoreCase);
		}

		public void FillDefaultPlotVal(PWRPlotType pwrPlotType, ref IHNode happContext, ref IHWizardPlot wizardPlot)
		{
			if (pwrPlotType != null && wizardPlot != null)
			{
				IHPlotVal plotVal = wizardPlot.PlotVal;
				if (pwrPlotType.DefTitle != null && pwrPlotType.DefTitle.Length > 0)
				{
					plotVal.set_Title(pwrPlotType.DefTitle);
				}
				plotVal.PlotType = 0;
				if (pwrPlotType.Basis > 0)
				{
					wizardPlot.basis = pwrPlotType.Basis;
				}
				if (happContext != null && pwrPlotType.IndependentVar != null && pwrPlotType.IndependentVar.Length > 0)
				{
					wizardPlot.SetIndependentVariable(happContext, pwrPlotType.IndependentVar);
				}
				if (pwrPlotType.DefXAxisTitle != null && pwrPlotType.DefXAxisTitle.Length > 0)
				{
					plotVal.set_XAxisTitle(pwrPlotType.DefXAxisTitle);
				}
				if (pwrPlotType.DefYAxisTitle != null && pwrPlotType.DefYAxisTitle.Length > 0)
				{
					plotVal.set_YAxisTitle(Type.Missing, pwrPlotType.DefYAxisTitle);
				}
			}
		}

		public bool FindPlotType(string tagID, ref List<PWRPlotType> lspwrTypes, ref PWRPlotType pwrPlotType)
		{
			for (int i = 0; i < lspwrTypes.Count; i++)
			{
				pwrPlotType = lspwrTypes[i];
				if (pwrPlotType.TagId == tagID)
				{
					return true;
				}
			}
			return false;
		}

		public void ParsePwrFile(StreamReader sr, ref List<PWRPlotType> lspwrTypes)
		{
			PWRPlotType pwrPlotType = new PWRPlotType();
			string text;
			while ((text = sr.ReadLine()) != null)
			{
				if (IsBeginPlot(text))
				{
					ParseHeaderLine(text, ref pwrPlotType);
				}
				else if (IsEndPlot(text))
				{
					lspwrTypes.Add(pwrPlotType);
					ParsePwrFile(sr, ref lspwrTypes);
				}
				else if (text.StartsWith("\n"))
				{
					ParsePwrFile(sr, ref lspwrTypes);
				}
				else
				{
					ParseProperty(text, ref pwrPlotType);
				}
			}
		}
	}
	public interface IRibbonPlotWizardType
	{
		string TagID { get; set; }

		string Name { get; set; }

		object WizardPlot { get; set; }

		object CxsNode { get; set; }

		System.Drawing.Image ImageIcon { get; }

		bool HasInputDialog { get; }

		string HelpFile { get; }

		long HelpID { get; }

		List<string> SupportedDataFields { get; }

		List<string> SupportedStyleFields { get; }

		string TooltipContentForRibbonItem { get; }

		string TooltipHeaderForRibbonItem { get; }

		bool CheckDataOnly { get; set; }

		void SetFieldData(string sFieldName, string sValue);

		void GetFieldData(string sFieldName, ref string sCurrentVal);

		List<string> FieldDataOptionList(string sFieldName);

		void SetFieldStyle(string sFieldName, string sValue);

		void GetFieldStyle(string sFieldName, ref string sCurrentVal);

		RibbonControlType GetFieldCtrlType(string sFieldName);

		void Context(object oNode, ref object oPlotWizardComponent, ref int ierror);

		void UpdateWizardData();

		void ShowInputDialog();

		void GetConfigData(ref string sConfigValue);

		void SetConfigData(string sValue);
	}
	public interface IRibbonPlotWizardMgr
	{
		void SetContext(object oNode, ref object oWizard);

		long SupportedPlotTypes(ref List<string> lsPlotTypes);

		long GetPlotType(string sPlotName, ref IRibbonPlotWizardType plwType);

		void ShowInputDialog(string sName);
	}
	public interface IRibbonAdhocPlotMgr
	{
		void DisplayDialog(object mmTabPage, bool bParametric, ref bool bDlgResult, ref string sBatchSepSettings);
	}
	public interface IRibbonAdsAdhocPlotMgr
	{
		void DisplayDialog(object cxsNode, object unityContainer, ref bool bDlgResult, ref object bPlot);
	}
	[AttributeUsage(AttributeTargets.Class)]
	public class RibbonAdhocPlotMgrAttribute : Attribute
	{
		public string Name { get; private set; }

		public Type TargetType { get; private set; }

		public RibbonAdhocPlotMgrAttribute(string name, Type targetType)
		{
			if (string.IsNullOrEmpty(name))
			{
				throw new ArgumentException("Parameter name cannot be null or empty.");
			}
			if (targetType == null)
			{
				throw new ArgumentNullException("targetType");
			}
			Name = name;
			TargetType = targetType;
		}
	}
	[AttributeUsage(AttributeTargets.Class)]
	public class RibbonPlotWizardMgrAttribute : Attribute
	{
		public string Name { get; private set; }

		public Type TargetType { get; private set; }

		public RibbonPlotWizardMgrAttribute(string name, Type targetType)
		{
			if (string.IsNullOrEmpty(name))
			{
				throw new ArgumentException("Parameter name cannot be null or empty.");
			}
			if (targetType == null)
			{
				throw new ArgumentNullException("targetType");
			}
			Name = name;
			TargetType = targetType;
		}
	}
	public interface IRibbonPlotResolver
	{
		IRibbonPlotWizardMgr ResolveRibbonPlotWizardMgr(string key);

		IRibbonAdhocPlotMgr ResolveRibbonAdhocPlotMgr(string key);

		IRibbonAdsAdhocPlotMgr ResolveRibbonAdsAdhocPlotMgr(string key);
	}
	public interface IStartPageControl
	{
		void Initialize(Action<string> openFileAction);
	}
	public class StreamGroupInfo
	{
		public string Name { get; private set; }

		public string Description { get; private set; }

		public string Template { get; private set; }

		public bool IsConditional { get; private set; }

		public bool IsPropertyConditional { get; private set; }

		public string LineStyle { get; private set; }

		public int Priority { get; private set; }

		public bool Active { get; private set; }

		public bool IsBuiltInGroup { get; private set; }

		public StreamGroupInfo(string name, string description, string template, bool isConditional, bool isPropertyConditional, string strLineStyle, bool bIsBuiltInGroup, bool bActive, int iPriority)
		{
			Name = name;
			Description = description;
			Template = template;
			IsConditional = isConditional;
			IsPropertyConditional = isPropertyConditional;
			LineStyle = strLineStyle;
			IsBuiltInGroup = bIsBuiltInGroup;
			Active = bActive;
			Priority = iPriority;
		}
	}
	public interface IStreamGroupPresenter
	{
		IEnumerable<StreamGroupInfo> GetAllUserDefinedGroups();

		IEnumerable<StreamGroupInfo> GetAllGroupsOrderByPriority();

		IEnumerable<StreamGroupInfo> GetAllActiveGroupsOrderByPriority();

		IEnumerable<string> GetSelectedStreams(string userDefinedGroupName);

		bool SaveUserDefinedGroup(string userDefinedGroupName, IEnumerable<string> streams);

		string CreateNewUserDefinedGroup(IEnumerable<string> streams);

		IEnumerable<string> FastQueryAllMaterialStreams();

		IEnumerable<string> QueryAllMaterialStreams();

		IEnumerable<string> GetAllSections();

		string GetStreamGroupTemplate(string groupName);

		string GetPropertySIUnits(string propertyEngineName);

		string GetPropertyPhysicalType(string propertyEngineName);
	}
	public enum FlowsheetContextType
	{
		None,
		StreamSelected,
		UnitOperationSelected,
		HierarchyBlockSelected,
		FlowsheetActivatedWithNoSelection
	}
	public interface IStreamReportPresenter
	{
		string GetDefaultTemplate();

		IEnumerable<string> GetTemplates(bool includeCssTemplates = false);

		IEnumerable<Tuple<string, object>> GetStreamGroups();

		IEnumerable<Tuple<string, object>> GetStreamGroupsForHierarchyInFlowsheet();

		bool CanOpenReport(FlowsheetContextType contextType, object parameter);

		void OpenStreamSummaryReport(FlowsheetContextType contextType, string selectedNodePath, object parameter);

		void SaveReferencedTemplates();
	}
	public interface IUnitProcedureResultSummaryPresenter
	{
		void ShowResultSummaryScreen(string contextFlowsheetPath);
	}
	public class MMMessageBox : Window, IComponentConnector
	{
		private Dictionary<MMMessageBoxButton, string[]> Button_Captions = new Dictionary<MMMessageBoxButton, string[]>();

		private List<System.Windows.Controls.Button> btns = new List<System.Windows.Controls.Button>();

		private readonly int _maxBtnCnt = 6;

		private static readonly Assembly _ass;

		private MMMessageBoxButton _button;

		private MMMessageBoxImage _icon;

		private int _defaultButton = 1;

		private bool _showHelpButton;

		protected MMMessageBoxResult _result;

		internal System.Windows.Controls.Image HeaderImage;

		internal TextBlock TxtBlock;

		internal Grid buttonsPanel;

		internal System.Windows.Controls.Button btn0;

		internal System.Windows.Controls.Button btn1;

		internal System.Windows.Controls.Button btn2;

		internal System.Windows.Controls.Button btn3;

		internal System.Windows.Controls.Button btn4;

		internal System.Windows.Controls.Button btn5;

		private bool _contentLoaded;

		public string HelpFile { get; private set; }

		public int HelpId { get; private set; }

		public string MessageText
		{
			get
			{
				return TxtBlock.Text;
			}
			set
			{
				if (!string.IsNullOrEmpty(value))
				{
					value.Replace("\\n", "\n");
				}
				TxtBlock.Text = value;
			}
		}

		public MMMessageBoxButton Button
		{
			get
			{
				return _button;
			}
			set
			{
				_button = value;
				string[] array = Button_Captions[Button];
				if (array.Length < 1)
				{
					return;
				}
				for (int i = 0; i < btns.Count; i++)
				{
					if (i >= array.Length)
					{
						btns[i].Visibility = Visibility.Collapsed;
						continue;
					}
					btns[i].Visibility = Visibility.Visible;
					btns[i].Content = array[i];
				}
				if (_showHelpButton)
				{
					btns[array.Length].Visibility = Visibility.Visible;
					btns[array.Length].Content = InfrastructureResources._Help;
				}
			}
		}

		public MMMessageBoxImage MessageIcon
		{
			get
			{
				return _icon;
			}
			set
			{
				_icon = value;
				if (_icon == MMMessageBoxImage.None)
				{
					HeaderImage.Visibility = Visibility.Collapsed;
					return;
				}
				HeaderImage.Visibility = Visibility.Visible;
				StringBuilder stringBuilder = new StringBuilder();
				ImageSource imageSource = null;
				stringBuilder.Append("pack://application:,,,/");
				stringBuilder.Append(typeof(MMMessageBox).Assembly.FullName);
				stringBuilder.Append(";component/Images/");
				switch (_icon)
				{
				case MMMessageBoxImage.Error:
					try
					{
						stringBuilder.Append("Stop.png");
						imageSource = new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
					}
					catch (Exception)
					{
					}
					break;
				case MMMessageBoxImage.Exclamation:
					try
					{
						stringBuilder.Append("Exclamation.png");
						imageSource = new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
					}
					catch (Exception)
					{
					}
					break;
				case MMMessageBoxImage.Information:
					try
					{
						stringBuilder.Append("Asterisk.png");
						imageSource = new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
					}
					catch (Exception)
					{
					}
					break;
				case MMMessageBoxImage.Question:
					try
					{
						stringBuilder.Append("Question.png");
						imageSource = new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
					}
					catch (Exception)
					{
					}
					break;
				}
				if (imageSource != null)
				{
					HeaderImage.Source = imageSource;
				}
			}
		}

		protected int DefaultButton
		{
			get
			{
				return _defaultButton;
			}
			set
			{
				if (value > 0 && value <= _maxBtnCnt && btns[value - 1].Content != null && !string.IsNullOrEmpty(btns[value - 1].Content.ToString()))
				{
					btns[value - 1].IsDefault = true;
					btns[value - 1].Focus();
					_defaultButton = value;
				}
				else
				{
					btns[0].IsDefault = true;
					btns[0].Focus();
					_defaultButton = 1;
				}
			}
		}

		protected bool ShowHelpButton
		{
			get
			{
				return _showHelpButton;
			}
			set
			{
				_showHelpButton = value;
				if (_showHelpButton)
				{
					string[] array = Button_Captions[Button];
					if (array.Length >= 1)
					{
						btns[array.Length].Visibility = Visibility.Visible;
						btns[array.Length].Content = InfrastructureResources._Help;
					}
				}
			}
		}

		[DllImport("user32.dll", CharSet = CharSet.Auto, ExactSpelling = true)]
		private static extern IntPtr GetActiveWindow();

		[DllImport("user32.dll", CharSet = CharSet.Auto, ExactSpelling = true)]
		private static extern IntPtr GetForegroundWindow();

		static MMMessageBox()
		{
			try
			{
				_ass = Assembly.LoadFile(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location) + "\\AspenTech.AspenPlus.MMControls.dll");
			}
			catch
			{
			}
		}

		protected MMMessageBox()
		{
			InitializeComponent();
			base.KeyDown += MMMessageBox_KeyDown;
			Button_Captions.Clear();
			btns.Clear();
			Button_Captions.Add(MMMessageBoxButton.OK, new string[1] { InfrastructureResources._Ok });
			Button_Captions.Add(MMMessageBoxButton.OKCancel, new string[2]
			{
				InfrastructureResources._Ok,
				InfrastructureResources._Cancel
			});
			Button_Captions.Add(MMMessageBoxButton.YesNoCancel, new string[3]
			{
				InfrastructureResources._Yes,
				InfrastructureResources._No,
				InfrastructureResources._Cancel
			});
			Button_Captions.Add(MMMessageBoxButton.YesNo, new string[2]
			{
				InfrastructureResources._Yes,
				InfrastructureResources._No
			});
			Button_Captions.Add(MMMessageBoxButton.AbortRetryIgnore, new string[3]
			{
				InfrastructureResources._Abort,
				InfrastructureResources._Retry,
				InfrastructureResources._Ignore
			});
			Button_Captions.Add(MMMessageBoxButton.RetryCancel, new string[2]
			{
				InfrastructureResources._Retry,
				InfrastructureResources._Cancel
			});
			Button_Captions.Add(MMMessageBoxButton.YesAllNoAll, new string[5]
			{
				InfrastructureResources._Yes,
				InfrastructureResources._YesAll,
				InfrastructureResources._No,
				InfrastructureResources._NoAll,
				InfrastructureResources._Cancel
			});
			Button_Captions.Add(MMMessageBoxButton.YesAllNo, new string[4]
			{
				InfrastructureResources._Yes,
				InfrastructureResources._YesAll,
				InfrastructureResources._No,
				InfrastructureResources._Cancel
			});
			Button_Captions.Add(MMMessageBoxButton.YesNoAll, new string[4]
			{
				InfrastructureResources._Yes,
				InfrastructureResources._No,
				InfrastructureResources._NoAll,
				InfrastructureResources._Cancel
			});
			btns.Add(btn0);
			btns.Add(btn1);
			btns.Add(btn2);
			btns.Add(btn3);
			btns.Add(btn4);
			btns.Add(btn5);
		}

		private void btn_Click(object sender, RoutedEventArgs e)
		{
			if (sender is System.Windows.Controls.Button { Content: not null } button)
			{
				if (button.Content.Equals(InfrastructureResources._Ok))
				{
					_result = MMMessageBoxResult.OK;
				}
				else if (button.Content.Equals(InfrastructureResources._Cancel))
				{
					_result = MMMessageBoxResult.Cancel;
				}
				else if (button.Content.Equals(InfrastructureResources._Yes))
				{
					_result = MMMessageBoxResult.Yes;
				}
				else if (button.Content.Equals(InfrastructureResources._No))
				{
					_result = MMMessageBoxResult.No;
				}
				else if (button.Content.Equals(InfrastructureResources._Abort))
				{
					_result = MMMessageBoxResult.Abort;
				}
				else if (button.Content.Equals(InfrastructureResources._Retry))
				{
					_result = MMMessageBoxResult.Retry;
				}
				else if (button.Content.Equals(InfrastructureResources._Ignore))
				{
					_result = MMMessageBoxResult.Ignore;
				}
				else if (button.Content.Equals(InfrastructureResources._YesAll))
				{
					_result = MMMessageBoxResult.YesAll;
				}
				else if (button.Content.Equals(InfrastructureResources._NoAll))
				{
					_result = MMMessageBoxResult.NoAll;
				}
				else if (button.Content.Equals(InfrastructureResources._Help))
				{
					ApplicationCommands.Help.Execute(this, button);
				}
				if (!button.Content.Equals(InfrastructureResources._Help))
				{
					Close();
				}
			}
		}

		private void MMMessageBox_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
		{
			if (e.Key == Key.Escape)
			{
				if (Button == MMMessageBoxButton.OK)
				{
					_result = MMMessageBoxResult.OK;
				}
				else
				{
					_result = MMMessageBoxResult.Cancel;
				}
				Close();
			}
		}

		protected override void OnClosed(EventArgs e)
		{
			if (_result == MMMessageBoxResult.None)
			{
				_result = MMMessageBoxResult.Cancel;
			}
			base.OnClosed(e);
		}

		private static MMMessageBoxResult InitializeMMMessageBox(Window owner, string messageBoxText, string caption, MMMessageBoxButton button, MMMessageBoxImage icon, bool showHelpButton, int defaultButton, string helpFile, int helpId)
		{
			if (!string.IsNullOrEmpty(caption))
			{
				if (caption == "Aspen Plus")
				{
					caption = ApwnResources.AspenPlus;
				}
				else if (caption == "Aspen Properties")
				{
					caption = ApwnResources.AspenPropTitle;
				}
			}
			MMMessageBox mMMessageBox = new MMMessageBox
			{
				MessageText = messageBoxText,
				Title = (string.IsNullOrEmpty(caption) ? "" : caption),
				Button = button,
				MessageIcon = icon,
				DefaultButton = defaultButton,
				ShowHelpButton = showHelpButton,
				HelpFile = helpFile,
				HelpId = helpId,
				WindowStartupLocation = WindowStartupLocation.CenterOwner
			};
			if (owner != null)
			{
				mMMessageBox.Owner = owner;
			}
			else
			{
				WindowInteropHelper windowInteropHelper = new WindowInteropHelper(mMMessageBox);
				windowInteropHelper.Owner = GetActiveWindow();
				if (windowInteropHelper.Owner == IntPtr.Zero)
				{
					windowInteropHelper.Owner = GetForegroundWindow();
				}
			}
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = null;
			mMMessageBox.ShowDialog();
			if (overrideCursor != null)
			{
				Mouse.OverrideCursor = overrideCursor;
			}
			return mMMessageBox?._result ?? MMMessageBoxResult.OK;
		}

		public static MMMessageBoxResult Show(Window owner, string messageBoxText, string caption = "", MMMessageBoxButton button = MMMessageBoxButton.OK, MMMessageBoxImage icon = MMMessageBoxImage.None, bool showHelpButton = false, int defaultButton = 1, string helpFile = "apwn.chm", int helpId = -1)
		{
			MMMessageBoxResult result = MMMessageBoxResult.OK;
			FieldInfo fieldInfo = null;
			FieldInfo fieldInfo2 = null;
			if (_ass != null)
			{
				Type type = _ass.GetType("AspenTech.AspenPlus.MMControls.Scripting.ScriptingSupport");
				fieldInfo2 = type.GetField("ScriptRunning", BindingFlags.Static | BindingFlags.Public);
				fieldInfo = type.GetField("Enabled", BindingFlags.Static | BindingFlags.Public);
			}
			if (fieldInfo != null && fieldInfo2 != null && (bool)fieldInfo.GetValue(null) && (bool)fieldInfo2.GetValue(null))
			{
				switch (button)
				{
				case MMMessageBoxButton.OK:
				case MMMessageBoxButton.OKCancel:
					result = MMMessageBoxResult.OK;
					break;
				case MMMessageBoxButton.YesAllNoAll:
				case MMMessageBoxButton.YesAllNo:
					result = MMMessageBoxResult.YesAll;
					break;
				case MMMessageBoxButton.YesNoCancel:
				case MMMessageBoxButton.YesNo:
				case MMMessageBoxButton.YesNoAll:
					result = MMMessageBoxResult.Yes;
					break;
				}
			}
			else if (System.Windows.Application.Current.Dispatcher != Dispatcher.CurrentDispatcher)
			{
				System.Windows.Application.Current.Dispatcher.Invoke(delegate
				{
					try
					{
						result = InitializeMMMessageBox(owner, messageBoxText, caption, button, icon, showHelpButton, defaultButton, helpFile, helpId);
					}
					catch (Exception)
					{
					}
				});
			}
			else
			{
				try
				{
					result = InitializeMMMessageBox(owner, messageBoxText, caption, button, icon, showHelpButton, defaultButton, helpFile, helpId);
				}
				catch (Exception)
				{
				}
			}
			return result;
		}

		public static MMMessageBoxResult Show(string messageBoxText, string caption = "", MMMessageBoxButton button = MMMessageBoxButton.OK, MMMessageBoxImage icon = MMMessageBoxImage.None, bool showHelpButton = false, int defaultResult = 1, string helpFile = "apwn.chm", int helpId = -1)
		{
			return Show(null, messageBoxText, caption, button, icon, showHelpButton, defaultResult, helpFile, helpId);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.Infrastructure;component/mmmessagebox.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				HeaderImage = (System.Windows.Controls.Image)target;
				break;
			case 2:
				TxtBlock = (TextBlock)target;
				break;
			case 3:
				buttonsPanel = (Grid)target;
				break;
			case 4:
				btn0 = (System.Windows.Controls.Button)target;
				btn0.Click += btn_Click;
				break;
			case 5:
				btn1 = (System.Windows.Controls.Button)target;
				btn1.Click += btn_Click;
				break;
			case 6:
				btn2 = (System.Windows.Controls.Button)target;
				btn2.Click += btn_Click;
				break;
			case 7:
				btn3 = (System.Windows.Controls.Button)target;
				btn3.Click += btn_Click;
				break;
			case 8:
				btn4 = (System.Windows.Controls.Button)target;
				btn4.Click += btn_Click;
				break;
			case 9:
				btn5 = (System.Windows.Controls.Button)target;
				btn5.Click += btn_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public enum MMMessageBoxButton
	{
		OK = 0,
		OKCancel = 1,
		AbortRetryIgnore = 2,
		YesNoCancel = 3,
		YesNo = 4,
		RetryCancel = 5,
		YesAllNoAll = 13,
		YesAllNo = 14,
		YesNoAll = 15
	}
	public enum MMMessageBoxResult
	{
		None = 0,
		OK = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7,
		YesAll = 14,
		NoAll = 15
	}
	public enum MMMessageBoxImage
	{
		None = 0,
		Error = 16,
		Hand = 16,
		Stop = 16,
		Question = 32,
		Exclamation = 48,
		Warning = 48,
		Information = 64,
		Asterisk = 64
	}
	public static class NavigationGroupKeys
	{
		public static readonly string AllDataGroup = "All Data";

		public static readonly string SimulationGroup = "Simulation";

		public static readonly string PropertiesGroup = "Properties";

		public static readonly string EnergyAnalysisGroup = "Energy Analysis";

		public static readonly string PSVPlusGroup = "PSVPlus";

		public static string ConvertToNavigatorGroupKey(ProblemModes mode)
		{
			return mode switch
			{
				ProblemModes.Simulation => SimulationGroup, 
				ProblemModes.Properties => PropertiesGroup, 
				ProblemModes.PSVPlus => PSVPlusGroup, 
				ProblemModes.EnergyAnalysis => EnergyAnalysisGroup, 
				_ => null, 
			};
		}

		public static ProblemModes? ConvertToProblemModes(string navigatorGroupKey)
		{
			if (!string.IsNullOrEmpty(navigatorGroupKey))
			{
				if (string.Equals(navigatorGroupKey, SimulationGroup, StringComparison.InvariantCultureIgnoreCase))
				{
					return ProblemModes.Simulation;
				}
				if (string.Equals(navigatorGroupKey, PropertiesGroup, StringComparison.InvariantCultureIgnoreCase))
				{
					return ProblemModes.Properties;
				}
				if (string.Equals(navigatorGroupKey, PSVPlusGroup, StringComparison.InvariantCultureIgnoreCase))
				{
					return ProblemModes.PSVPlus;
				}
				if (string.Equals(navigatorGroupKey, EnergyAnalysisGroup, StringComparison.InvariantCultureIgnoreCase))
				{
					return ProblemModes.EnergyAnalysis;
				}
			}
			return null;
		}
	}
	public class PlotWizardTemplate : Window, IComponentConnector
	{
		private System.Windows.Input.Cursor _externalCursor;

		public bool _ShowInTaskbar;

		public SizeToContent _SizeToContent = SizeToContent.WidthAndHeight;

		private bool _contentLoaded;

		public PlotWizardTemplate()
		{
			InitializeComponent();
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			if (base.Content is IPlotWizardTemplate plotWizardTemplate)
			{
				string caption = string.Empty;
				double defaultHeight = 0.0;
				double defaultWidth = 0.0;
				double minHeight = 0.0;
				double minWidth = 0.0;
				plotWizardTemplate.SetCaption(ref caption);
				plotWizardTemplate.SetDefaultHeight(ref defaultHeight);
				plotWizardTemplate.SetDefaultWidth(ref defaultWidth);
				plotWizardTemplate.SetMinHeight(ref minHeight);
				plotWizardTemplate.SetMinWidth(ref minWidth);
				base.Title = caption;
				if (defaultHeight > 0.0)
				{
					base.Height = defaultHeight;
				}
				if (defaultWidth > 0.0)
				{
					base.Width = defaultWidth;
				}
				base.MinHeight = minHeight;
				base.MinWidth = minWidth;
				base.SizeToContent = _SizeToContent;
			}
			base.ShowInTaskbar = _ShowInTaskbar;
			base.WindowStartupLocation = WindowStartupLocation.CenterOwner;
			_externalCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = System.Windows.Input.Cursors.Arrow;
		}

		protected override void OnClosed(EventArgs e)
		{
			Mouse.OverrideCursor = _externalCursor;
			base.OnClosed(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.Infrastructure;component/plotwizardtemplate.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((PlotWizardTemplate)target).Loaded += Window_Loaded;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class PrintPageSettings
	{
		private const double MarginScale = 96.0;

		[DefaultValue(null)]
		public string PaperSize { get; set; }

		[DefaultValue(null)]
		public string PaperSource { get; set; }

		[DefaultValue(false)]
		public bool IsLandscape { get; set; }

		[DefaultValue(null)]
		public Thickness? Margin { get; set; }
	}
	public static class RegionNames
	{
		public static string RibbonRegion => "RibbonRegion";

		public static string DockingRegion => "DockingRegion";

		public static string DataBrowserTreeRegion => "DataBrowserTreeRegion";

		public static string FormBrowserRegion => "FormBrowserRegion";
	}
	public sealed class RibbonToolExtensions : DependencyObject
	{
		private class ProxyCommand : ICommand
		{
			private DependencyObject Target { get; set; }

			private ICommand Content { get; set; }

			public event EventHandler CanExecuteChanged;

			public ProxyCommand(DependencyObject target, ICommand content)
			{
				if (target == null)
				{
					throw new ArgumentNullException("target");
				}
				Target = target;
				Content = Content;
			}

			public bool CanExecute(object parameter)
			{
				if (!CanExecuteCommand(Target))
				{
					return false;
				}
				if (Content != null)
				{
					return Content.CanExecute(parameter);
				}
				return false;
			}

			public void Execute(object parameter)
			{
				if (Content != null)
				{
					Content.Execute(parameter);
				}
			}
		}

		public static readonly DependencyProperty CommandProperty = DependencyProperty.RegisterAttached("Command", typeof(ICommand), typeof(RibbonToolExtensions), new PropertyMetadata(OnCommandPropertyChanged));

		public static void SetCommand(DependencyObject target, ICommand command)
		{
			if (target == null)
			{
				throw new ArgumentNullException("target");
			}
			target.SetValue(CommandProperty, command);
		}

		public static ICommand GetCommand(DependencyObject target)
		{
			if (target == null)
			{
				throw new ArgumentNullException("target");
			}
			return target.GetValue(CommandProperty) as ICommand;
		}

		private static void OnCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			PropertyInfo property = d.GetType().GetProperty("Command", BindingFlags.Public);
			if (property != null && property.CanWrite)
			{
				property.SetValue(d, new ProxyCommand(d, e.NewValue as ICommand));
			}
		}

		private static bool CanExecuteCommand(DependencyObject d)
		{
			FrameworkElement frameworkElement = d as FrameworkElement;
			if (frameworkElement != null)
			{
				return false;
			}
			if (!IsRibbonToolOnQat(frameworkElement))
			{
				return true;
			}
			return XamRibbon.GetOriginalTool(frameworkElement)?.IsVisible ?? true;
		}

		private static bool IsRibbonToolOnQat(DependencyObject d)
		{
			try
			{
				return ((dynamic)d).IsOnQat;
			}
			catch (Exception)
			{
				return false;
			}
		}
	}
	public static class ShellHelpers
	{
		public static void BindScreenZoomToScaleTransform(ScreenContentControl screen)
		{
			ScaleTransform scaleTransform = new ScaleTransform();
			System.Windows.Data.Binding binding = new System.Windows.Data.Binding
			{
				Source = screen,
				Mode = BindingMode.TwoWay,
				Path = new PropertyPath(ScreenContentControl.ZoomProperty.Name)
			};
			BindingOperations.SetBinding(scaleTransform, ScaleTransform.ScaleXProperty, binding);
			BindingOperations.SetBinding(scaleTransform, ScaleTransform.ScaleYProperty, binding);
			(screen.Content as FrameworkElement).LayoutTransform = scaleTransform;
		}
	}
	public static class ShellSettingsSerializer
	{
		private class FileRootSettings
		{
			public string CaseFileSettings { get; set; }

			public string CommonShellSettings { get; set; }

			public static FileRootSettings Parse(string settings)
			{
				if (!string.IsNullOrEmpty(settings))
				{
					if (settings.IndexOf("PersistRibbonState") >= 0 && settings.Length > 99999)
					{
						settings = settings.Replace("\r", string.Empty);
						settings = settings.Replace("\n", string.Empty);
						settings = settings.Replace("&gt;", "&gt;\r\n");
						settings = settings.Replace("&amp;gt;", "&amp;gt;\r\n");
						settings = settings.Replace("&amp;amp;gt;", "&amp;amp;gt;\r\n");
					}
					try
					{
						if (settings.StartsWith("<FileRootSettings>"))
						{
							XElement xElement = XElement.Parse(settings);
							if (xElement != null)
							{
								FileRootSettings fileRootSettings = new FileRootSettings();
								XElement xElement2 = xElement.Element("CaseFileSettings");
								if (xElement2 != null)
								{
									fileRootSettings.CaseFileSettings = xElement2.Value;
								}
								XElement xElement3 = xElement.Element("CommonShellSettings");
								if (xElement3 != null)
								{
									fileRootSettings.CommonShellSettings = xElement3.Value;
								}
								return fileRootSettings;
							}
						}
						else if (settings.StartsWith("<CommonShellSettings "))
						{
							return new FileRootSettings
							{
								CommonShellSettings = settings
							};
						}
					}
					catch (Exception)
					{
					}
				}
				return null;
			}

			public string Save()
			{
				XElement xElement = new XElement("FileRootSettings");
				if (!string.IsNullOrEmpty(CaseFileSettings))
				{
					xElement.Add(new XElement("CaseFileSettings", CaseFileSettings));
				}
				if (!string.IsNullOrEmpty(CommonShellSettings))
				{
					xElement.Add(new XElement("CommonShellSettings", CommonShellSettings));
				}
				return xElement.ToString(SaveOptions.DisableFormatting);
			}
		}

		private static string[] plugins = new string[7] { "AOLServiceDLL", "AOLUtils", "AspenOnLine.WindowsClientAppContent", "AspenTech.AspenOnLine.Infrastructure", "AspenTech.AspenOnLine.RemotingHelper", "AspenTech.AspenOnLine.UI.Infrastructure", "AOLLocalization" };

		public static bool LoadDocumentShellSettings(IUnityContainer unityContainer, string file)
		{
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			IShellApplication shellApplication = unityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
			if (shellApplication != null && GetActiveCxsCase(shellApplication) != null && !IgnoreReadShellSettings())
			{
				FileRootSettings fileRootSettings = ReadSettingsFromFile(file);
				if (fileRootSettings != null)
				{
					if (!string.IsNullOrEmpty(fileRootSettings.CaseFileSettings))
					{
						CaseFileSettings.RestoreDefault(fileRootSettings.CaseFileSettings);
					}
					if (!string.IsNullOrEmpty(fileRootSettings.CommonShellSettings))
					{
						int? documentInternalVersion = null;
						if (shellApplication is IApwnApplication && ((IApwnApplication)shellApplication).ActiveDocument != null)
						{
							documentInternalVersion = ((IApwnApplication)shellApplication).ActiveDocument.FileVersionNumber;
						}
						bool result = InternalLoadShellSettings(shellApplication, unityContainer, fileRootSettings.CommonShellSettings, documentInternalVersion);
						CloseInvisibleScreens(shellApplication.ActiveWindow);
						return result;
					}
				}
			}
			return false;
		}

		public static bool SaveDocumentShellSettings(IUnityContainer unityContainer, string file)
		{
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			unityContainer.TryResolve<IStreamReportPresenter>()?.SaveReferencedTemplates();
			IShellApplication shellApplication = unityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
			if (shellApplication != null && GetActiveCxsCase(shellApplication) != null && !IgnoreSaveShellSettings())
			{
				string caseFileSettings = CaseFileSettings.SaveDefault();
				string commonShellSettings = InternalSaveShellSettings(shellApplication);
				SaveSettingsToFile(file, caseFileSettings, commonShellSettings);
				return true;
			}
			return false;
		}

		private static void CloseInvisibleScreens(IShellMainWindow mainWindow)
		{
			if (mainWindow == null)
			{
				throw new ArgumentNullException("mainWindow");
			}
			foreach (ScreenContentControl item in mainWindow.SelectScreens(delegate(ScreenContentControl x)
			{
				if (x.Parent is ContentPane { Visibility: not Visibility.Visible } contentPane)
				{
					contentPane.CloseAction = PaneCloseAction.RemovePane;
					return true;
				}
				return false;
			}).ToList())
			{
				mainWindow.CloseScreen(item);
			}
			try
			{
				if (SystemEnvironment.ExternalVersionString == "V10")
				{
					ScreenContentControl screenContentControl = mainWindow.FindScreen((ScreenContentControl x) => x.ScreenFactoryKey == "PlantCompareScreen");
					if (screenContentControl != null)
					{
						mainWindow.CloseScreen(screenContentControl);
					}
				}
			}
			catch (Exception)
			{
			}
		}

		private static void LoadAOLDlls()
		{
			try
			{
				Assembly[] assemblies = AppDomain.CurrentDomain.GetAssemblies();
				string[] array = plugins;
				foreach (string dll in array)
				{
					if (assemblies.FirstOrDefault((Assembly p) => p.FullName.Contains(dll)) == null)
					{
						Assembly.LoadFrom(Path.Combine(SystemEnvironment.AspenTechSharedPluginsFolder, "AOL", dll + ".dll"));
					}
				}
			}
			catch (Exception ex)
			{
				SystemEnvironment.Logger.Log("Failing loading AOL dlls:" + ex.Message, Category.Exception, Priority.Low);
			}
		}

		private static bool InternalLoadShellSettings(IShellApplication shellApp, IUnityContainer container, string settings, int? documentInternalVersion)
		{
			try
			{
				string finalSettings = settings;
				ISettingsTransformer settingsTransformer = container.TryResolve<ISettingsTransformer>();
				if (settingsTransformer != null)
				{
					int? currentApplicationVersionNumber = GetCurrentApplicationVersionNumber();
					if (documentInternalVersion.HasValue && currentApplicationVersionNumber.HasValue)
					{
						finalSettings = settingsTransformer.Transform(settings, documentInternalVersion.Value, currentApplicationVersionNumber.Value);
					}
				}
				finalSettings = TrimXamlShellSettingsText(finalSettings);
				LoadAOLDlls();
				shellApp.RestoreShellSettings(finalSettings);
				return true;
			}
			catch (Exception ex)
			{
				SystemEnvironment.Logger.Log("Error when loading shell settings:" + ex.Message, Category.Exception, Priority.Low);
				return false;
			}
		}

		private static string TrimXamlShellSettingsText(string finalSettings)
		{
			try
			{
				using StringReader input = new StringReader(finalSettings);
				using XmlTextReader xmlTextReader = new XmlTextReader(input);
				while (xmlTextReader.Read())
				{
				}
				return finalSettings;
			}
			catch (XmlException)
			{
				bool flag = false;
				bool flag2 = false;
				char c = ' ';
				for (int i = 0; i < finalSettings.Length; i++)
				{
					char c2 = finalSettings[i];
					switch (c2)
					{
					case '\'':
						flag = !flag;
						break;
					case '"':
						flag2 = !flag2;
						break;
					case '\n':
					case '\r':
						if (!flag && !flag2 && c != '>')
						{
							finalSettings = finalSettings.Remove(i, 1);
							i--;
						}
						break;
					}
					if (!char.IsWhiteSpace(c2))
					{
						c = c2;
					}
				}
				return finalSettings;
			}
		}

		private static int? GetCurrentApplicationVersionNumber()
		{
			double result = 0.0;
			if (double.TryParse(SystemEnvironment.InternalVersionString, out result))
			{
				return (int)result;
			}
			return null;
		}

		private static string InternalSaveShellSettings(IShellApplication shellApp)
		{
			try
			{
				return shellApp.SaveShellSettings();
			}
			catch (Exception ex)
			{
				SystemEnvironment.Logger.Log("Error when saving shell settings:" + ex.Message, Category.Exception, Priority.Low);
				return null;
			}
		}

		private static CxsCase GetActiveCxsCase(IShellApplication shellApp)
		{
			if (shellApp is IApwnApplication { ActiveDocument: not null } apwnApplication)
			{
				return apwnApplication.ActiveDocument.Case;
			}
			return null;
		}

		private static string GetShellSettingsFile(CxsCase activeCase)
		{
			return activeCase.CaseFullFilePath + ".shell";
		}

		private static FileRootSettings ReadSettingsFromFile(string file)
		{
			if (File.Exists(file))
			{
				string text = null;
				try
				{
					StringBuilder stringBuilder = new StringBuilder();
					string[] array = File.ReadAllLines(file);
					foreach (string value in array)
					{
						stringBuilder.Append(value);
					}
					text = stringBuilder.ToString();
				}
				catch (Exception ex)
				{
					SystemEnvironment.Logger.Log("Error when reading shell settings from file " + file + ":" + ex.Message, Category.Exception, Priority.Low);
				}
				if (!string.IsNullOrEmpty(text))
				{
					int num = text.IndexOf("<FileRootSettings>", StringComparison.InvariantCultureIgnoreCase);
					int num2 = text.IndexOf("</FileRootSettings>", StringComparison.InvariantCultureIgnoreCase);
					if (num >= 0 && num2 > num)
					{
						return FileRootSettings.Parse(text.Substring(num, num2 - num + "</FileRootSettings>".Length));
					}
					int num3 = text.IndexOf("<CommonShellSettings", StringComparison.InvariantCultureIgnoreCase);
					int num4 = text.IndexOf("</CommonShellSettings>", StringComparison.InvariantCultureIgnoreCase);
					if (num3 >= 0 && num4 > num3)
					{
						return FileRootSettings.Parse(text.Substring(num3, num4 - num3 + "</CommonShellSettings>".Length));
					}
				}
			}
			return null;
		}

		private static void SaveSettingsToFile(string file, string caseFileSettings, string commonShellSettings)
		{
			if (File.Exists(file) && File.GetAttributes(file) != FileAttributes.Normal)
			{
				File.SetAttributes(file, FileAttributes.Normal);
			}
			FileRootSettings fileRootSettings = new FileRootSettings
			{
				CaseFileSettings = caseFileSettings,
				CommonShellSettings = commonShellSettings
			};
			if (fileRootSettings != null)
			{
				File.WriteAllText(file, fileRootSettings.Save());
			}
		}

		private static bool IgnoreReadShellSettings()
		{
			return SystemEnvironment.IsMmgIniKeyOpen("ignorereadapwnshellsettings");
		}

		private static bool IgnoreSaveShellSettings()
		{
			return SystemEnvironment.IsMmgIniKeyOpen("ignoresaveapwnshellsettings");
		}
	}
	public static class SimulationEventNotification
	{
		private enum UpdateOption
		{
			None,
			ClearCache,
			ResetPointsAndClearCache
		}

		private class InternalSimulationNotifier
		{
			private bool _updateLocked;

			private bool _reInitialize;

			private readonly List<UpdateOption> _updateQueues = new List<UpdateOption>();

			private const int HINT_KERNEL_UPDATE = 301;

			private const int HINT_THREADMODAL_BEGIN = 235;

			private const int HINT_THREADMODAL_ENDED = 236;

			private const int HINT_ASC_NEWEVENT = 303;

			private const int HINT_UPDATE_RUNSTEP = 212;

			private const int HINT_UPDATE_RENAMEBLOCK = 207;

			private const int HINT_RELEASE_POINTERS = 304;

			private const int HINT_UPDATE_REINIT = 214;

			private const int HINT_UPDATE_FORMS_ONLY = 201;

			private const int HINT_UPDATE_STORE = 204;

			private const int WFRF_BEFOREINIT = 118;

			private const int WFRF_RUNREINIT = 109;

			private const int SIM_EVENT_REFRESH = 1005;

			private const int SIM_EVENT_UPDATE_STATUS = 1004;

			private const int ASCSimEvent_PostBlocksChanged = 0;

			private const int ASCSimEvent_PostVariablesChanged = 1;

			private const int ASCSimEvent_RequestStarted = 2;

			private const int ASCSimEvent_RequestCompleted = 3;

			private const int ASCSimEvent_CommandStarted = 4;

			private const int ASCSimEvent_CommandCompleted = 5;

			private const int ASCSimEvent_PreSolve = 6;

			private const int ASCSimEvent_PostSolve = 7;

			private const int ASCSimEvent_PreSync = 8;

			private const int ASCSimEvent_PostSync = 9;

			private const int ASCSimEvent_PostBlockInclude = 10;

			private const int ASCSimEvent_PostParameterChanged = 11;

			private const int ASCSimEvent_PostPortsChanged = 12;

			private const int ASCSimEvent_PostBlockStructureChanged = 13;

			private const int ASCSimEvent_PostBlockDofChanged = 14;

			private Dispatcher _uiDispatcherInternal;

			private IHapp _happ;

			private CxsCase _activeCase;

			public Dispatcher UIDispatcherInternal
			{
				get
				{
					if (_uiDispatcherInternal == null && UnityContainer != null)
					{
						IShellApplication shellApplication = UnityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
						if (shellApplication != null && shellApplication.ActiveWindow != null)
						{
							_uiDispatcherInternal = (shellApplication.ActiveWindow as Window).Dispatcher;
						}
					}
					return _uiDispatcherInternal;
				}
			}

			public IHapp Happ
			{
				get
				{
					return _happ;
				}
				set
				{
					if (_happ != value)
					{
						IHapp happ = _happ;
						_happ = value;
						OnHappChanged(happ, _happ);
					}
				}
			}

			public CxsCase ActiveCase
			{
				get
				{
					return _activeCase;
				}
				set
				{
					if (_activeCase != value)
					{
						CxsCase activeCase = _activeCase;
						_activeCase = value;
						OnActiveCaseChanged(activeCase, _activeCase);
					}
				}
			}

			public IUnityContainer UnityContainer { get; set; }

			public Action SimulationReinitializedAction { get; set; }

			public Action SimulationRunStartedAction { get; set; }

			public Action SimulationRunPausedAction { get; set; }

			public Action SimulationRunCompletedAction { get; set; }

			public Action SimulationRunFailedAction { get; set; }

			public Action SimulationObjectSolvingAction { get; set; }

			public Action SimulationIntegrationStepAction { get; set; }

			public Action<UpdateOption> UpdateDataRequiredByHappLSAction { get; set; }

			private void OnHappChanged(IHapp oldValue, IHapp newValue)
			{
				if (oldValue != null && oldValue is HappLS target)
				{
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnDataChanged").RemoveEventHandler(target, new IAPHappEvents_OnDataChangedEventHandler(happLs_OnDataChanged));
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnUpdateMessage").RemoveEventHandler(target, new IAPHappEvents_OnUpdateMessageEventHandler(happLs_OnUpdateMessage));
				}
				if (newValue != null && newValue is HappLS target2)
				{
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnDataChanged").AddEventHandler(target2, new IAPHappEvents_OnDataChangedEventHandler(happLs_OnDataChanged));
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnUpdateMessage").AddEventHandler(target2, new IAPHappEvents_OnUpdateMessageEventHandler(happLs_OnUpdateMessage));
				}
			}

			private void OnActiveCaseChanged(CxsCase oldValue, CxsCase newValue)
			{
				if (oldValue != null)
				{
					oldValue.Message -= cxsCase_Message;
				}
				if (newValue != null)
				{
					newValue.Message += cxsCase_Message;
				}
			}

			public void UnsubscribeEvents()
			{
				if (Happ != null && Happ is HappLS target)
				{
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnDataChanged").RemoveEventHandler(target, new IAPHappEvents_OnDataChangedEventHandler(happLs_OnDataChanged));
					new ComAwareEventInfo(typeof(IAPHappEvents_Event), "OnUpdateMessage").RemoveEventHandler(target, new IAPHappEvents_OnUpdateMessageEventHandler(happLs_OnUpdateMessage));
				}
				if (ActiveCase != null)
				{
					ActiveCase.Message -= cxsCase_Message;
				}
			}

			private bool ShouldSuppressEvents()
			{
				if (_app.ActiveDocument == null)
				{
					return true;
				}
				if (_app.ActiveDocument.IsSaving)
				{
					return true;
				}
				return false;
			}

			private void happLs_OnDataChanged(object pObj)
			{
				if (!ShouldSuppressEvents() && pObj is IHNode iHNode && string.Equals(iHNode.get_Name(Type.Missing), "OUTSET", StringComparison.InvariantCultureIgnoreCase))
				{
					UpdateDataRequiredByHappLS(UpdateOption.ClearCache);
				}
			}

			private void happLs_OnUpdateMessage(int msg_code, string msg_hint, object msg_object, int source_handle)
			{
				if (!ShouldSuppressEvents())
				{
					ProcessMessage(msg_code, msg_hint);
				}
			}

			private void cxsCase_Message(object sender, CxsMessageEventArgs e)
			{
				if (ShouldSuppressEvents())
				{
					return;
				}
				foreach (CxsMessage message in e.Messages)
				{
					if (message.MessageType == CxsMessageType.RunStarted)
					{
						TryInvoke(SimulationRunStartedAction);
					}
					else if (message.MessageType == CxsMessageType.RunCompleted)
					{
						TryInvoke(SimulationRunCompletedAction);
					}
					else if (message.MessageType == CxsMessageType.RunFailed)
					{
						TryInvoke(SimulationRunFailedAction);
					}
					else if (message.MessageType == CxsMessageType.RunPaused)
					{
						TryInvoke(SimulationRunPausedAction);
					}
					else if (message.MessageType == CxsMessageType.Custom)
					{
						switch (message.Number)
						{
						case 1005:
							if (message.MessageDataCount > 0)
							{
								int msg_code = Convert.ToInt32(message.MessageData[0]);
								ProcessMessage(msg_code, string.Empty);
							}
							break;
						case 303:
							ProcessMessage(message.Number, message.Text);
							break;
						case 1000:
							TryInvoke(SimulationObjectSolvingAction);
							break;
						case 1373:
							TryInvoke(SimulationIntegrationStepAction);
							break;
						}
					}
					else
					{
						ProcessMessage(message.Number, message.Text);
					}
				}
			}

			private void ProcessMessage(int msg_code, string msg_hint)
			{
				switch (msg_code)
				{
				case 301:
					UpdateDataRequiredByHappLS(UpdateOption.ResetPointsAndClearCache);
					break;
				case 235:
					_updateLocked = true;
					break;
				case 236:
					_updateLocked = false;
					UpdateDataRequiredByHappLS(UpdateOption.ResetPointsAndClearCache);
					break;
				case 118:
					_updateLocked = true;
					break;
				case 109:
					_updateLocked = false;
					UpdateDataRequiredByHappLS(UpdateOption.ClearCache, reinit: true);
					break;
				case 212:
					UpdateDataRequiredByHappLS(UpdateOption.ClearCache);
					break;
				case 207:
					UpdateDataRequiredByHappLS(UpdateOption.ResetPointsAndClearCache);
					break;
				case 304:
					UpdateDataRequiredByHappLS(UpdateOption.ResetPointsAndClearCache);
					break;
				case 201:
					UpdateDataRequiredByHappLS(UpdateOption.None);
					break;
				case 204:
					UpdateDataRequiredByHappLS(UpdateOption.None);
					break;
				case 303:
				{
					int result = -1;
					if (!string.IsNullOrEmpty(msg_hint))
					{
						int num = msg_hint.IndexOf(' ');
						if (num > 0)
						{
							int.TryParse(msg_hint.Substring(0, num), out result);
						}
					}
					switch (result)
					{
					case 0:
					case 7:
					case 9:
						UpdateDataRequiredByHappLS(UpdateOption.ClearCache);
						break;
					case 1:
						UpdateDataRequiredByHappLS(UpdateOption.ClearCache);
						break;
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 8:
						break;
					}
					break;
				}
				}
			}

			private void UpdateDataRequiredByHappLS(UpdateOption option, bool reinit = false)
			{
				if (_updateLocked || (!reinit && _updateQueues.Contains(option)))
				{
					return;
				}
				if (reinit)
				{
					_reInitialize = true;
					_updateQueues.Clear();
				}
				else
				{
					_updateQueues.Add(option);
					_reInitialize = false;
				}
				if (UIDispatcherInternal == null)
				{
					return;
				}
				UIDispatcherInternal.BeginInvoke((Action)delegate
				{
					if (_reInitialize)
					{
						TryInvoke(SimulationReinitializedAction);
						_reInitialize = false;
					}
					else if (_updateQueues.Count > 0)
					{
						if (_updateQueues.Contains(UpdateOption.ResetPointsAndClearCache))
						{
							OnUpdateDataRequiredByHappLSInternal(UpdateOption.ResetPointsAndClearCache);
						}
						else if (_updateQueues.Contains(UpdateOption.ClearCache))
						{
							OnUpdateDataRequiredByHappLSInternal(UpdateOption.ClearCache);
						}
						else
						{
							OnUpdateDataRequiredByHappLSInternal(UpdateOption.None);
						}
						_updateQueues.Clear();
					}
				}, DispatcherPriority.Render);
				_updateQueues.Add(option);
			}

			private void OnUpdateDataRequiredByHappLSInternal(UpdateOption option)
			{
				if (UpdateDataRequiredByHappLSAction != null)
				{
					UpdateDataRequiredByHappLSAction(option);
				}
			}

			private void TryInvoke(Action action)
			{
				action?.Invoke();
			}
		}

		private static IApwnApplication _app;

		private static IUnityContainer _unityContainer;

		private static InternalSimulationNotifier _SimulationNotifier;

		private static Dispatcher _uiDispatcher;

		private static IEventAggregator _eventAggregator;

		public static Dispatcher UIDispatcher
		{
			get
			{
				if (_uiDispatcher == null && _app is IShellApplication { ActiveWindow: not null, ActiveWindow: Window activeWindow })
				{
					_uiDispatcher = activeWindow.Dispatcher;
				}
				return _uiDispatcher;
			}
		}

		public static IEventAggregator EventAggregator
		{
			get
			{
				if (_eventAggregator == null && _unityContainer != null)
				{
					_eventAggregator = _unityContainer.TryResolve<IEventAggregator>();
				}
				return _eventAggregator;
			}
		}

		public static void RegisterApplication(IApwnApplication app, IUnityContainer unityContainer)
		{
			if (app == null)
			{
				throw new ArgumentNullException("app");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			_app = app;
			_unityContainer = unityContainer;
			InternalSimulationNotifier simulationNotifier = _SimulationNotifier;
			if (simulationNotifier != null)
			{
				simulationNotifier.UnsubscribeEvents();
				UpdateSimulationNotifier(simulationNotifier, null, null, null, null, null);
			}
			_SimulationNotifier = new InternalSimulationNotifier
			{
				UnityContainer = unityContainer,
				SimulationReinitializedAction = OnSimulationReinitialized,
				SimulationRunStartedAction = OnSimulationRunStarted,
				SimulationRunPausedAction = OnSimulationRunPaused,
				SimulationRunFailedAction = OnSimulationRunFailed,
				SimulationRunCompletedAction = OnSimulationRunCompleted,
				SimulationObjectSolvingAction = OnSimulationObjectSolving,
				SimulationIntegrationStepAction = OnSimulationIntegrationStep,
				UpdateDataRequiredByHappLSAction = OnUpdateDataRequiredByHappLS
			};
			app.ActiveDocumentChanged += app_ActiveDocumentChanged;
		}

		private static void app_ActiveDocumentChanged(object sender, EventArgs e)
		{
			System.Windows.Application.Current.Dispatcher.BeginInvoke(new Action(UpdateHappForNotifier), DispatcherPriority.Loaded);
		}

		private static void UpdateHappForNotifier()
		{
			if (_app == null || _unityContainer == null || _SimulationNotifier == null || _app.ActiveDocument == null)
			{
				return;
			}
			try
			{
				InternalSimulationNotifier simulationNotifier = _SimulationNotifier;
				simulationNotifier.ActiveCase = _app.ActiveDocument.Case;
				if (_unityContainer.Resolve<object>("RootApplicationObject", Array.Empty<ResolverOverride>()) is IHapp happ)
				{
					simulationNotifier.Happ = happ;
				}
			}
			catch (Exception ex)
			{
				SystemEnvironment.LogDebug(ex.Message);
			}
		}

		private static void OnSimulationReinitialized()
		{
			PublishRoutedEvent<SimulationReinitializedEvent, SimulationReinitializedEventArgs>();
		}

		private static void OnSimulationRunStarted()
		{
			PublishRoutedEvent<SimulationRunStartedEvent, SimulationRunStartedEventArgs>();
		}

		private static void OnSimulationRunPaused()
		{
			PublishRoutedEvent<SimulationRunPausedEvent, SimulationRunPausedEventArgs>();
		}

		private static void OnSimulationRunCompleted()
		{
			PublishRoutedEvent<SimulationRunCompletedEvent, SimulationRunCompletedEventArgs>();
		}

		private static void OnSimulationRunFailed()
		{
			PublishRoutedEvent<SimulationRunFailedEvent, SimulationRunFailedEventArgs>();
		}

		private static void OnUpdateDataRequiredByHappLS(UpdateOption option)
		{
			PublishRoutedEvent<SimulationStatusChangedEvent, SimulationStatusChangedEventArgs>();
		}

		private static void OnSimulationObjectSolving()
		{
			PublishRoutedEvent<SimulationObjectSolvingEvent, SimulationObjectSolvingEventArgs>();
		}

		private static void OnSimulationIntegrationStep()
		{
			PublishRoutedEvent<SimulationIntegrationStepEvent, SimulationIntegrationStepEventArgs>();
		}

		private static void PublishRoutedEvent<E, T>() where E : SimulationEventBase<T> where T : new()
		{
			if (EventAggregator == null)
			{
				return;
			}
			if (UIDispatcher == null || UIDispatcher == Dispatcher.CurrentDispatcher)
			{
				EventAggregator.GetEvent<E>().Publish(new T());
				return;
			}
			UIDispatcher.BeginInvoke((Action)delegate
			{
				try
				{
					EventAggregator.GetEvent<E>().Publish(new T());
				}
				catch (Exception ex)
				{
					SystemEnvironment.Logger.Log(ex.ToString(), Category.Exception, Priority.Medium);
				}
			});
		}

		private static void UpdateSimulationNotifier(InternalSimulationNotifier notifier, IUnityContainer uc, IHapp happ, CxsCase activeCase, Action reinitializeAction, Action<UpdateOption> updateDataAction)
		{
			notifier.UnityContainer = uc;
			notifier.SimulationReinitializedAction = reinitializeAction;
			notifier.UpdateDataRequiredByHappLSAction = updateDataAction;
			notifier.Happ = happ;
			notifier.ActiveCase = activeCase;
		}
	}
	public class SingleAutomationScript
	{
		private string _scriptPath = string.Empty;

		private static SingleAutomationScript _instance;

		private bool? _logScriptState;

		public static SingleAutomationScript Instance
		{
			get
			{
				if (_instance == null)
				{
					_instance = new SingleAutomationScript();
				}
				return _instance;
			}
		}

		public bool? LogScriptState
		{
			get
			{
				if (!_logScriptState.HasValue)
				{
					string environmentVariable = Environment.GetEnvironmentVariable("APLUSAUTOMATIONSCRIPT");
					if (string.IsNullOrEmpty(environmentVariable))
					{
						_logScriptState = false;
					}
					else if (environmentVariable == "1")
					{
						_logScriptState = true;
					}
					else
					{
						_logScriptState = false;
					}
				}
				return _logScriptState;
			}
		}

		private SingleAutomationScript()
		{
		}

		public void LogAction(string nodePath, string actionName, IEnumerable<string> arguments)
		{
			try
			{
				if (LogScriptState == true && !string.IsNullOrEmpty(_scriptPath))
				{
					string text = "null";
					if (arguments.Any())
					{
						text = "@\"[" + string.Join(",", arguments) + "]\"";
					}
					string contents = "            ATP.Action(\"" + nodePath + "\", \"" + actionName + "\", " + text + ");\r\n";
					File.AppendAllText(_scriptPath, contents);
				}
			}
			catch (Exception ex)
			{
				File.AppendAllText(_scriptPath, ex.Message);
			}
		}

		public void LogBatchSet(IEnumerable<string> paths, IEnumerable<string> attributes, IEnumerable<string> units, IEnumerable<string> values)
		{
			try
			{
				if (LogScriptState != true || string.IsNullOrEmpty(_scriptPath))
				{
					return;
				}
				new XmlDocument().CreateElement("BatchSet");
				for (int i = 0; i < paths.Count(); i++)
				{
					string text = values.ElementAt(i);
					if (!double.TryParse(values.ElementAt(i), NumberStyles.Any, CultureInfo.InvariantCulture, out var _))
					{
						text = "\"" + text + "\"";
					}
					string contents = "            ATP.Set(\"" + paths.ElementAt(i) + "\", \"" + attributes.ElementAt(i) + "\", \"" + units.ElementAt(i) + "\", " + text + ");\r\n";
					File.AppendAllText(_scriptPath, contents);
				}
			}
			catch (Exception ex)
			{
				File.AppendAllText(_scriptPath, ex.Message);
			}
		}

		public void SetScriptPath(string newPath)
		{
			_scriptPath = newPath;
		}

		public string CreateScriptFile(string documentPath)
		{
			try
			{
				string environmentVariable = Environment.GetEnvironmentVariable("APLUSAUTOMATIONSCRIPT");
				if (string.IsNullOrEmpty(environmentVariable) || environmentVariable != "1")
				{
					return string.Empty;
				}
				if (!string.IsNullOrEmpty(_scriptPath))
				{
					CloseScript();
				}
				string directoryName = Path.GetDirectoryName(documentPath);
				if (!Directory.Exists(directoryName))
				{
					Directory.CreateDirectory(directoryName);
				}
				string text = $"{Path.GetFileNameWithoutExtension(documentPath)}_{DateTime.Now:yyyyMMddhhmm}_atp.cs";
				string text2 = Path.Combine(directoryName, text);
				File.Create(text2).Close();
				_scriptPath = text2;
				InitScriptContent(text);
				return _scriptPath;
			}
			catch
			{
				return string.Empty;
			}
		}

		private void InitScriptContent(string fileName)
		{
			string text = fileName.Replace("_atp.cs", "");
			string contents = "namespace AutomationTestTool\r\n{\r\n    public static class " + text + "\r\n    {\r\n        public static void RunScript(string document)\r\n        {\r\n            ATP.Load(document);\r\n";
			File.AppendAllText(_scriptPath, contents);
		}

		public void CloseScript()
		{
			if (!string.IsNullOrEmpty(_scriptPath))
			{
				string contents = "        }\r\n    }\r\n}\r\n";
				File.AppendAllText(_scriptPath, contents);
				_scriptPath = string.Empty;
			}
		}
	}
	public class StringScreenSubject : ScreenSubject
	{
		public string subject { get; set; }

		public string fatherNodePath { get; set; }
	}
	public static class SystemEnvironment
	{
		public class DebugLogger : ILoggerFacade
		{
			private string _filePath;

			private string _startTime;

			private List<Category> _logCategories;

			private List<Priority> _logPriorities;

			public string FilePath => _filePath;

			public DebugLogger()
			{
				_startTime = DateTime.Now.ToString("yyyyMMdd.hhmmss.fff");
			}

			private void Setup()
			{
				if (_filePath != null)
				{
					return;
				}
				string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech", ApplicationNameWithPathVersion);
				if (!Directory.Exists(path))
				{
					try
					{
						Directory.CreateDirectory(path);
					}
					catch (IOException)
					{
						return;
					}
				}
				string path2 = ApplicationName + " Logger." + _startTime + ".log";
				_filePath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech", ApplicationNameWithPathVersion, path2);
				if (_logCategories != null)
				{
					return;
				}
				_logCategories = new List<Category>();
				_logCategories.Add(Category.Exception);
				_logPriorities = new List<Priority>();
				_logPriorities.Add(Priority.None);
				_logPriorities.Add(Priority.High);
				string[] commandLineArgs = Environment.GetCommandLineArgs();
				foreach (string strA in commandLineArgs)
				{
					if (string.Compare(strA, "/full_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-full_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0)
					{
						_logCategories.Add(Category.Debug);
						_logCategories.Add(Category.Info);
						_logCategories.Add(Category.Warn);
						_logPriorities.Add(Priority.Low);
						_logPriorities.Add(Priority.Medium);
					}
					if (string.Compare(strA, "/medium_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-medium_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0)
					{
						_logCategories.Add(Category.Debug);
						_logCategories.Add(Category.Info);
						_logCategories.Add(Category.Warn);
						_logPriorities.Add(Priority.Medium);
					}
					if (string.Compare(strA, "/simple_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0 || string.Compare(strA, "-simple_log", ignoreCase: true, CultureInfo.InvariantCulture) == 0)
					{
						_logCategories.Add(Category.Debug);
						_logCategories.Add(Category.Info);
						_logCategories.Add(Category.Warn);
					}
				}
			}

			[Conditional("DEBUG")]
			private void LogAllIfDebug()
			{
				_logCategories = new List<Category>();
				_logCategories.Add(Category.Exception);
				_logCategories.Add(Category.Debug);
				_logCategories.Add(Category.Info);
				_logCategories.Add(Category.Warn);
				_logPriorities = new List<Priority>();
				_logPriorities.Add(Priority.None);
				_logPriorities.Add(Priority.Low);
				_logPriorities.Add(Priority.Medium);
				_logPriorities.Add(Priority.High);
			}

			public void Log(string message, Category category, Priority priority)
			{
				Setup();
				if (!string.IsNullOrWhiteSpace(message) && _logCategories.Contains(category) && _logPriorities.Contains(priority) && _filePath != null)
				{
					try
					{
						string contents = string.Format("[{0}] [{1}]:{2}{3}", DateTime.Now.ToString("hh:mm:ss:ffff"), category.ToString(), message, Environment.NewLine);
						File.AppendAllText(_filePath, contents);
					}
					catch
					{
					}
				}
			}
		}

		public const string AppSessionFlag = "/sessioned";

		private const string ASPEN_PRODUCT_KEY = "SOFTWARE\\AspenTech\\Setup\\Products";

		private const string ASPEN_PRODUCT_WOW_KEY = "SOFTWARE\\Wow6432Node\\AspenTech\\Setup\\Products";

		public const string CompanyName = "AspenTech";

		public const string AspenUpdateCenterUrl = "AspenUpdateCenterUrl";

		public const string AspenRssFeedUrl = "AspenRssFeedUrl";

		public const string AspenHomeUrl = "AspenHomeUrl";

		public const string AspenUpdateLinkedInPageUrl = "AspenUpdateLinkedInPageUrl";

		public const string AspenNoHelpUrl = "AspenNoHelpUrl";

		public const string AspenDechemaUrl = "AspenDechemaUrl";

		public const string AspenDipprURL = "AspenDipprURL";

		public const string AspenProcessiumURL = "AspenProcessiumURL";

		public const string AspenChemEssenURL = "AspenChemEssenURL";

		private static string _executablePath = null;

		private static readonly ILoggerFacade _logger = new DebugLogger();

		private static string _internalVersionString = null;

		private static string _externalVersionString = null;

		private static string _pathVersionString = null;

		private static string _latestEconomicsCompleteInternalVersion = null;

		private static string _latestComProgIDSuffix = null;

		private static string _edrVersion = null;

		private static string _edrLocation = null;

		private static string _aspenTechSharedFolder;

		private static string commonXeqDirectory = null;

		private static string AMSystemHelpDirectory = null;

		private static string _entryDir;

		private static string MMTOPDirectory = null;

		private static int dynamicsInstalled = -1;

		private static string _configurationFile = null;

		private static readonly Dictionary<string, string> _configurationInfo = new Dictionary<string, string>();

		private static bool? _isOpenFromExistingSession;

		private static bool? _isLaunchedByCreateNew;

		private static bool? _isLaunchedByOpenFile;

		private static bool? _isLaunchedByAutomation;

		public static IUnityContainer unityContainer;

		public static Dictionary<string, string> ChmHelpToURLMap = new Dictionary<string, string>();

		public static Dictionary<string, string> ChmUserGuide1ToURLMap = new Dictionary<string, string>();

		public static string ExecutablePath
		{
			get
			{
				if (_executablePath == null)
				{
					StringBuilder stringBuilder = new StringBuilder(257);
					GetModuleFileName(IntPtr.Zero, stringBuilder, 256);
					_executablePath = stringBuilder.ToString();
				}
				return _executablePath;
			}
		}

		public static ILoggerFacade Logger => _logger;

		public static string ApplicationName
		{
			get
			{
				if (!IsAspenProperties)
				{
					return "Aspen Plus";
				}
				return "Aspen Properties";
			}
		}

		public static string ApplicationNameWithVersion => ApplicationName + " " + ExternalVersionString;

		public static string ApplicationNameWithPathVersion => ApplicationName + " " + PathVersionString;

		public static string CheckLicString
		{
			get
			{
				if (!IsAspenProperties)
				{
					return "AEA_AspenPlus";
				}
				return "AEA_AspenProperties";
			}
		}

		public static string InternalVersionString => _internalVersionString ?? (_internalVersionString = MMVersionHelper.MVGetVersionStringM());

		public static string ExternalVersionString
		{
			get
			{
				if (_externalVersionString == null)
				{
					_externalVersionString = MMVersionHelper.MVGetAESSuiteVersionM().Split('.')[0];
				}
				return _externalVersionString;
			}
		}

		public static string PathVersionString => _pathVersionString ?? (_pathVersionString = MMVersionHelper.MVGetAESSuiteVersionM());

		public static string CompatibleEconomicVersionString => _latestEconomicsCompleteInternalVersion ?? (_latestEconomicsCompleteInternalVersion = MMVersionHelper.MVGetEconomicsCompleteInternalVersionM());

		public static string ComProgIDSuffixString => _latestComProgIDSuffix ?? (_latestComProgIDSuffix = MMVersionHelper.MVGetComProgIDSuffixM());

		public static string CompatibleExchangerPath
		{
			get
			{
				_ = CompatibleExchangerVersionString;
				return _edrLocation;
			}
		}

		public static string CompatibleExchangerVersionString
		{
			get
			{
				if (_edrVersion == null)
				{
					_edrVersion = InternalVersionString;
					try
					{
						using RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\ASPEN PLUS\\" + InternalVersionString + "\\Compatibility\\Aspen Exchanger Design and Rating");
						if (registryKey != null)
						{
							for (int i = 0; i <= 5; i++)
							{
								object obj = null;
								obj = ((i != 0) ? registryKey.GetValue(i.ToString()) : registryKey.GetValue("CurVer"));
								if (obj == null)
								{
									continue;
								}
								string text = obj.ToString();
								using RegistryKey registryKey2 = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\B-JAC\\" + text + "\\BJACWIN");
								if (registryKey2 != null)
								{
									string text2 = registryKey2.GetValue("BJAC_TOP") as string;
									if (!string.IsNullOrEmpty(text2) && Directory.Exists(text2))
									{
										_edrLocation = text2;
										_edrVersion = text;
										registryKey2.Close();
										break;
									}
									registryKey2.Close();
								}
							}
							registryKey.Close();
						}
					}
					catch (Exception)
					{
					}
				}
				return _edrVersion;
			}
		}

		public static string AspenTechSharedFolder
		{
			get
			{
				if (_aspenTechSharedFolder == null)
				{
					try
					{
						if (IntPtr.Size == 8)
						{
							_aspenTechSharedFolder = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Setup", "ASPENCOMMON64", "").ToString();
						}
						else
						{
							_aspenTechSharedFolder = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Setup", "ASPENCOMMONDir", "").ToString();
						}
					}
					catch (Exception)
					{
					}
				}
				return _aspenTechSharedFolder;
			}
		}

		public static string AspenTechSharedPluginsFolder => Path.Combine(AspenTechSharedFolder, "plugins", PathVersionString);

		public static string CommonXeq
		{
			get
			{
				if (commonXeqDirectory == null)
				{
					try
					{
						commonXeqDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Aprsystem\\" + InternalVersionString + "\\mm", "mmcommonxeq", "").ToString();
					}
					catch (Exception)
					{
					}
				}
				return commonXeqDirectory;
			}
		}

		public static string AMSystemHelp
		{
			get
			{
				if (AMSystemHelpDirectory == null)
				{
					try
					{
						AMSystemHelpDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\AMSystem\\" + InternalVersionString + "\\Dir", "Help", "").ToString();
					}
					catch (Exception)
					{
					}
				}
				return AMSystemHelpDirectory;
			}
		}

		public static string EntryDir
		{
			get
			{
				if (string.IsNullOrEmpty(_entryDir))
				{
					string location = Assembly.GetEntryAssembly().Location;
					_entryDir = location.Substring(0, location.LastIndexOf(Path.DirectorySeparatorChar));
				}
				return _entryDir;
			}
		}

		public static string MMTOPDir
		{
			get
			{
				if (MMTOPDirectory == null)
				{
					try
					{
						if (IsAspenProperties)
						{
							MMTOPDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\ASPEN PROPERTIES\\" + InternalVersionString + "\\mm", "mmtop", "").ToString();
						}
						else
						{
							MMTOPDirectory = Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\ASPEN PLUS\\" + InternalVersionString + "\\mm", "mmtop", "").ToString();
						}
					}
					catch (Exception)
					{
					}
				}
				return MMTOPDirectory;
			}
		}

		public static int DynamicsInstalled
		{
			get
			{
				if (dynamicsInstalled == -1)
				{
					dynamicsInstalled = 0;
					try
					{
						RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\ASPEN PLUS\\" + InternalVersionString + "\\Compatibility\\Aspen Dynamics");
						if (registryKey != null)
						{
							string text = null;
							for (int i = 1; i <= 5; i++)
							{
								object value = registryKey.GetValue(i.ToString());
								if (value != null)
								{
									text = value.ToString();
									RegistryKey registryKey2 = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\Aspen Dynamics\\" + text + "\\Dir");
									if (registryKey2 != null)
									{
										dynamicsInstalled = 1;
										registryKey2.Close();
										break;
									}
								}
							}
							registryKey.Close();
						}
					}
					catch (Exception)
					{
						dynamicsInstalled = 0;
					}
				}
				return dynamicsInstalled;
			}
		}

		public static bool IsAspenProperties { get; private set; }

		public static bool IsSwitchingEnvironment { get; private set; }

		public static ApplicationSettings ApplicationSettings => ApplicationSettings.Default;

		public static StringCollection MostRecentlyUsedFiles => ApplicationSettings.Default.MostRecentlyUsedFiles;

		public static StringCollection MostRecentlyUsedTemplates => ApplicationSettings.Default.MostRecentlyUsedTemplates;

		public static string ConfigurationFile
		{
			get
			{
				if (_configurationFile == null)
				{
					try
					{
						_configurationFile = Path.Combine(Registry.GetValue("HKEY_LOCAL_MACHINE\\SOFTWARE\\AspenTech\\Aprsystem\\" + InternalVersionString + "\\mm", "mmcommontop", "").ToString(), "Config.json");
					}
					catch (Exception)
					{
					}
				}
				return _configurationFile;
			}
		}

		public static Dictionary<string, string> ConfigurationInfo => _configurationInfo;

		public static bool IsOpenFromExistingSession
		{
			get
			{
				if (!_isOpenFromExistingSession.HasValue)
				{
					string[] commandLineArgs = Environment.GetCommandLineArgs();
					_isOpenFromExistingSession = commandLineArgs.FirstOrDefault((string x) => string.Equals(x, "/sessioned", StringComparison.InvariantCultureIgnoreCase)) != null;
				}
				return _isOpenFromExistingSession.Value;
			}
		}

		public static bool IsLaunchedByCreateNew
		{
			get
			{
				if (!_isLaunchedByCreateNew.HasValue)
				{
					string[] commandLineArgs = Environment.GetCommandLineArgs();
					_isLaunchedByCreateNew = commandLineArgs.FirstOrDefault((string x) => string.Equals(x, "/new", StringComparison.InvariantCultureIgnoreCase)) != null;
				}
				return _isLaunchedByCreateNew.Value;
			}
		}

		public static bool IsLaunchedByOpenFile
		{
			get
			{
				if (!_isLaunchedByOpenFile.HasValue)
				{
					string[] commandLineArgs = Environment.GetCommandLineArgs();
					_isLaunchedByOpenFile = commandLineArgs.Skip(1).FirstOrDefault((string x) => x.Length > 0 && x[0] != '/' && x[0] != '-') != null;
				}
				return _isLaunchedByOpenFile.Value;
			}
		}

		public static bool IsLaunchedByAutomation
		{
			get
			{
				if (!_isLaunchedByAutomation.HasValue)
				{
					string[] commandLineArgs = Environment.GetCommandLineArgs();
					_isLaunchedByAutomation = commandLineArgs.FirstOrDefault((string x) => string.Equals(x, "/Automation", StringComparison.InvariantCultureIgnoreCase)) != null || commandLineArgs.FirstOrDefault((string x) => string.Equals(x, "-Automation", StringComparison.InvariantCultureIgnoreCase)) != null;
				}
				return _isLaunchedByAutomation.Value;
			}
		}

		public static bool IsIcarusInstalled
		{
			get
			{
				string text = "AspenIcarus" + CompatibleEconomicVersionString.Replace(".", "");
				RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\AspenTech\\Setup\\Products\\" + text, writable: false);
				if (registryKey != null)
				{
					registryKey.Close();
					return true;
				}
				registryKey = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Wow6432Node\\AspenTech\\Setup\\Products\\" + text, writable: false);
				if (registryKey != null)
				{
					registryKey.Close();
					return true;
				}
				return false;
			}
		}

		public static string GetDBProvider
		{
			get
			{
				string name = "SOFTWARE\\AspenTech\\APED\\" + InternalVersionString;
				string result = "mssql";
				RegistryKey registryKey = Registry.CurrentUser.OpenSubKey(name);
				if (registryKey != null)
				{
					object value = registryKey.GetValue("dbProvider");
					registryKey.Close();
					if (value == null)
					{
						RegistryKey registryKey2 = Registry.LocalMachine.OpenSubKey(name);
						if (registryKey2 != null)
						{
							value = registryKey2.GetValue("dbProvider");
							registryKey2.Close();
							if (value != null)
							{
								result = Convert.ToString(value);
							}
						}
					}
					else
					{
						result = Convert.ToString(value);
					}
				}
				else
				{
					RegistryKey registryKey3 = Registry.LocalMachine.OpenSubKey(name);
					if (registryKey3 != null)
					{
						object value2 = registryKey3.GetValue("dbProvider");
						registryKey3.Close();
						if (value2 != null)
						{
							result = Convert.ToString(value2);
						}
					}
				}
				return result;
			}
		}

		[DllImport("kernel32.dll", SetLastError = true)]
		public static extern uint GetModuleFileName([In] IntPtr hModule, [Out] StringBuilder lpFilename, [In][MarshalAs(UnmanagedType.U4)] int nSize);

		public static void LogDebug(string message)
		{
			Logger.Log(message, Category.Debug, Priority.Low);
		}

		public static void SetAspenPropertiesFlag()
		{
			IsAspenProperties = true;
		}

		public static void SetIsSwitchingEnvironmentFlag(bool value)
		{
			IsSwitchingEnvironment = value;
		}

		public static string FindFileInContextFolder(string fileName)
		{
			if (!string.IsNullOrWhiteSpace(fileName))
			{
				string text = Path.Combine(CommonXeq, fileName);
				if (File.Exists(text))
				{
					return text;
				}
				text = Path.Combine(EntryDir, fileName);
				if (File.Exists(text))
				{
					return text;
				}
			}
			return null;
		}

		public static bool IsMmgIniKeyOpen(string registryKey)
		{
			string text = "Software\\AspenTech\\";
			text = (IsAspenProperties ? (text + "Aspen Properties\\") : (text + "Aspen Plus\\"));
			text += InternalVersionString;
			text += "\\mmgini";
			RegistryKey registryKey2 = Registry.CurrentUser.OpenSubKey(text, writable: false);
			if (registryKey2 != null)
			{
				try
				{
					int? num = registryKey2.GetValue(registryKey) as int?;
					registryKey2.Close();
					if (num.HasValue)
					{
						return num.Value == 1;
					}
				}
				catch
				{
					registryKey2.Close();
				}
			}
			string fullName = Directory.GetParent(ExecutablePath).FullName;
			string text2 = null;
			text2 = ((!IsAspenProperties) ? Path.Combine(fullName, "mmg.ini") : Path.Combine(fullName, "propmmg.ini"));
			string[] array = File.ReadAllLines(text2);
			foreach (string text3 in array)
			{
				if (text3.IndexOf(registryKey) == -1)
				{
					continue;
				}
				string[] array2 = text3.Split(' ');
				if (array2.Count() > 1 && int.TryParse(array2[1], out var result))
				{
					switch (result)
					{
					case 0:
						return false;
					case 1:
						return true;
					}
				}
				break;
			}
			return false;
		}

		public static void ShowHtmlHelp(string sHelpFile, int iHelpCode)
		{
			if (unityContainer != null)
			{
				unityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowHtmlHelpEvent>().Publish(new ShowHtmlHelpEventArgs(sHelpFile, iHelpCode));
			}
		}

		public static IAdbTop GetActiveDocAdbTop()
		{
			return MmgSor.GetActiveDocAdbTop();
		}
	}
	public enum ViewsFilterOption
	{
		AllViews,
		InputViews,
		OutputViews
	}
}
namespace AspenTech.AspenPlus.Infrastructure.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "15.3.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
namespace AspenTech.AspenPlus.Infrastructure.MvvmCore
{
	public class ObservableObject : INotifyPropertyChanged
	{
		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void PropertyHasChange()
		{
			StackFrame stackFrame = new StackFrame(1, fNeedFileInfo: false);
			new StackTrace(stackFrame);
			string property = stackFrame.GetMethod().Name.Substring(4);
			OnPropertyChanged(property);
		}

		private void OnPropertyChanged(string property)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(property);
				propertyChangedEventHandler(this, e);
			}
		}
	}
}
namespace AspenTech.AspenPlus.Infrastructure.Events
{
	public class ShowACMModelHelpEventArg : EventArgs
	{
		public string ModelType { get; set; }
	}
	public class ShowACMModelHelpEvent : RoutedCompositePresentationEvent<ShowACMModelHelpEventArg>
	{
	}
	public class UpdateACMModelDOFEventArg : EventArgs
	{
		public string ModelId { get; set; }
	}
	public class UpdateACMModelDOFEvent : RoutedCompositePresentationEvent<UpdateACMModelDOFEventArg>
	{
	}
	public class ApwnDocumentOpenedEvent : RoutedCompositePresentationEvent<EventArgs>
	{
		public ApwnDocumentOpenedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
	public class ProcessTypeChangedEventArgs : EventArgs
	{
		public bool BatchProcessMode { get; set; }
	}
	public class ProcessTypeChangedEvent : RoutedCompositePresentationEvent<ProcessTypeChangedEventArgs>
	{
	}
	public class CloseCustomModelEditorEvent : RoutedCompositePresentationEvent<CloseCustomModelEditorEventArgs>
	{
	}
	public class CloseCustomModelEditorEventArgs : EventArgs
	{
		public bool SaveModel { get; private set; }

		public CloseCustomModelEditorEventArgs(bool saveModel)
		{
			SaveModel = saveModel;
		}
	}
	public class SaveCustomModelEditorEvent : RoutedCompositePresentationEvent<SaveCustomModelEditorEventArgs>
	{
	}
	public class SaveCustomModelEditorEventArgs : EventArgs
	{
		public string ModelName { get; private set; }

		public SaveCustomModelEditorEventArgs(string modelName = null)
		{
			ModelName = modelName;
		}
	}
	public class ColumnInternalsInvokedEventArgs : EventArgs
	{
	}
	public class ColumnInternalsInvoked : RoutedCompositePresentationEvent<ColumnInternalsInvokedEventArgs>
	{
	}
	public class ContextMenuFindObjectEventArgs
	{
		public string TargetNodePath { get; set; }
	}
	public class ContextMenuFindObjectEvent : RoutedCompositePresentationEvent<ContextMenuFindObjectEventArgs>
	{
	}
	public class ContextMenuFindObjectCanExecuteEventArgs
	{
		public string TargetNodePath { get; set; }

		public bool CanExecute { get; set; }
	}
	public class ContextMenuFindObjectCanExecuteEvent : RoutedCompositePresentationEvent<ContextMenuFindObjectCanExecuteEventArgs>
	{
	}
	public class FODSelectObjectInFlowsheetEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string ObjectName { get; set; }

		public int ObjectClass { get; set; }
	}
	public class FODSelectObjectInFlowsheetEvent : RoutedCompositePresentationEvent<FODSelectObjectInFlowsheetEventArgs>
	{
	}
	public class FODFindObjectInFlowsheetEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string ObjectName { get; set; }

		public int ObjectClass { get; set; }
	}
	public class FODFindObjectInFlowsheetEvent : RoutedCompositePresentationEvent<FODFindObjectInFlowsheetEventArgs>
	{
	}
	public class FODOpenFormInPSVEventArgs : EventArgs
	{
		public int CommandID { get; set; }

		public string NavigationPath { get; set; }

		public string ModelType { get; set; }

		public string ObjectName { get; set; }
	}
	public class FODOpenFormInPSVEvent : RoutedCompositePresentationEvent<FODOpenFormInPSVEventArgs>
	{
	}
	public class RenameFlowsheetSectionEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }
	}
	public class RenameFlowsheetSectionEvent : RoutedCompositePresentationEvent<RenameFlowsheetSectionEventArgs>
	{
	}
	public class AddFlowsheetSectionEventArgs : EventArgs
	{
		public string FlowsheetSectionPath { get; set; }
	}
	public class AddFlowsheetSectionEvent : RoutedCompositePresentationEvent<AddFlowsheetSectionEventArgs>
	{
	}
	public class FlowsheetSectionChangedEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }
	}
	public class FlowsheetSectionChangedEvent : RoutedCompositePresentationEvent<FlowsheetSectionChangedEventArgs>
	{
	}
	public class GlobalUnitSetChangedEventArgs
	{
		public string OldUnitSet { get; private set; }

		public string NewUnitSet { get; private set; }

		public GlobalUnitSetChangedEventArgs(string oldUnitSet, string newUnitSet)
		{
			OldUnitSet = oldUnitSet;
			NewUnitSet = newUnitSet;
		}
	}
	public class GlobalUnitSetChangedEvent : RoutedCompositePresentationEvent<GlobalUnitSetChangedEventArgs>
	{
		public GlobalUnitSetChangedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
	public class SetDataGridCageEventArgs : EventArgs
	{
		public string CageKey { get; set; }

		public int Rows { get; set; }

		public int Columns { get; set; }

		public int HeaderHeight { get; set; }

		public int[] RowsHeightArray { get; set; }

		public int[] ColumnsWidthArray { get; set; }

		public string[] ColumnsLabelArray { get; set; }

		public string[,] Contents { get; set; }

		public short[,] Align { get; set; }

		public short[,] Style { get; set; }

		public bool Successful { get; set; }
	}
	public class SetDataGridCageEvent : RoutedCompositePresentationEvent<SetDataGridCageEventArgs>
	{
	}
	public class DisposeDataGridCageEventArgs : EventArgs
	{
		public string CageKey { get; set; }

		public DisposeDataGridCageEventArgs(string strCageKey)
		{
			CageKey = strCageKey;
		}
	}
	public class DisposeDataGridCageEvent : RoutedCompositePresentationEvent<DisposeDataGridCageEventArgs>
	{
	}
	public class SetupDataGridCageEventArgs : EventArgs
	{
		public string CageKey { get; set; }

		public SetupDataGridCageEventArgs(string strCageKey)
		{
			CageKey = strCageKey;
		}
	}
	public class SetupDataGridCageEvent : RoutedCompositePresentationEvent<SetupDataGridCageEventArgs>
	{
	}
	public class QueryFlowsheetModeEventArgs
	{
		public string FlowsheetMode { get; set; }
	}
	public class QueryFlowsheetModeEvent : RoutedCompositePresentationEvent<QueryFlowsheetModeEventArgs>
	{
	}
	public class DocumentClosedEventArgs
	{
	}
	public class DocumentClosedEvent : RoutedCompositePresentationEvent<DocumentClosedEventArgs>
	{
	}
	public class FileDropEventArg : EventArgs
	{
		public string[] DropFiles { get; set; }
	}
	public class FileDropEvent : CompositePresentationEvent<FileDropEventArg>
	{
	}
	public class IsNormalRunEventArgs : EventArgs
	{
		public bool IsNormalRun { get; set; }

		public bool IsSet { get; set; }

		public IsNormalRunEventArgs(bool _isNormalRun, bool _isSet)
		{
			IsNormalRun = _isNormalRun;
			IsSet = _isSet;
		}
	}
	public class IsNormalRunEvent : RoutedCompositePresentationEvent<IsNormalRunEventArgs>
	{
	}
	public class ModelLibrarySaveEventArgs
	{
	}
	public class ModelLibrarySaveEvent : RoutedCompositePresentationEvent<ModelLibrarySaveEventArgs>
	{
	}
	public class RecordMoveToHierarchyEventArgs
	{
		public string MoveToHierarchy { get; set; }

		[DefaultValue(false)]
		public bool HierarchyIsRelative { get; set; }

		[DefaultValue(false)]
		public bool ScenarioNameConflict { get; set; }

		public RecordMoveToHierarchyEventArgs()
		{
		}

		public RecordMoveToHierarchyEventArgs(string strMoveToHierarchy, bool bHierarchyIsRelative)
		{
			MoveToHierarchy = strMoveToHierarchy;
			HierarchyIsRelative = bHierarchyIsRelative;
		}
	}
	public class RecordMoveToHierarchyEvent : RoutedCompositePresentationEvent<RecordMoveToHierarchyEventArgs>
	{
	}
	public class MoveHierarchyToHierarchyEventArgs
	{
		public List<string> MovedHierarchies { get; set; }

		public string TargetHierarchy { get; set; }

		public bool ExtractContentAndDeleteHierarchy { get; set; }

		public MoveHierarchyToHierarchyEventArgs()
		{
		}

		public MoveHierarchyToHierarchyEventArgs(List<string> lstMovedHierarchies, string strTargetHierarchy, bool bExtractContentAndDeleteHierarchy)
		{
			MovedHierarchies = lstMovedHierarchies;
			TargetHierarchy = strTargetHierarchy;
			ExtractContentAndDeleteHierarchy = bExtractContentAndDeleteHierarchy;
		}
	}
	public class MoveHierarchyToHierarchyEvent : RoutedCompositePresentationEvent<MoveHierarchyToHierarchyEventArgs>
	{
	}
	public class MoveSelectionEventArgs
	{
		public IDictionary<string, bool> MovedBlocks { get; }

		public IEnumerable<string> MovedStreams { get; }

		public string TargetHierarchy { get; }

		public int MoveSelectionType { get; }

		public MoveSelectionEventArgs(IDictionary<string, bool> movedBlocks, IEnumerable<string> movedStreams, string targetHierarchy, int iMoveSelectionType)
		{
			MovedBlocks = movedBlocks ?? throw new ArgumentNullException("movedBlocks");
			MovedStreams = movedStreams ?? throw new ArgumentNullException("movedStreams");
			TargetHierarchy = targetHierarchy ?? throw new ArgumentNullException("targetHierarchy");
			MoveSelectionType = iMoveSelectionType;
		}
	}
	public class MoveSelectionEvent : RoutedCompositePresentationEvent<MoveSelectionEventArgs>
	{
	}
	public class RecordUpdatedCustomTableEventArgs
	{
		public string CustomTablePath { get; set; }

		public RecordUpdatedCustomTableEventArgs(string strCustomTablePath)
		{
			CustomTablePath = strCustomTablePath;
		}
	}
	public class RecordUpdatedCustomTableEvent : RoutedCompositePresentationEvent<RecordUpdatedCustomTableEventArgs>
	{
	}
	public class PFSContextMenuItemBlockTypeRetrieveEventArgs : EventArgs
	{
		public int NodeType { get; set; }

		public string NodePath { get; set; }

		public string BlockType { get; set; }

		public string NavigatorPath { get; set; }
	}
	public class PFSContextMenuItemBlockTypeRetrieveEvent : RoutedCompositePresentationEvent<PFSContextMenuItemBlockTypeRetrieveEventArgs>
	{
		public PFSContextMenuItemBlockTypeRetrieveEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class PFSContextMenuItemIconRetrieveEventArgs : EventArgs
	{
		public string ItemType { get; set; }

		public object StatusImage { get; set; }

		public PFSContextMenuItemIconRetrieveEventArgs(string strItemType)
		{
			ItemType = strItemType;
		}
	}
	public class PFSContextMenuItemIconRetrieveEvent : RoutedCompositePresentationEvent<PFSContextMenuItemIconRetrieveEventArgs>
	{
		public PFSContextMenuItemIconRetrieveEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class PFSUpdateAnimateFlagEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class ReInitEventArgs : EventArgs
	{
		public List<string> RadfracBlkList { get; set; }

		public ReInitEventArgs(List<string> RadfracBlockIds)
		{
			RadfracBlkList = RadfracBlockIds;
		}
	}
	public class ReInitEvent : RoutedCompositePresentationEvent<ReInitEventArgs>
	{
	}
	public class RibbonTabsRequestingEventArgs
	{
		public IEnumerable<RibbonTabItem> ContextualRibbonTabs { get; set; }

		public object Tag { get; set; }
	}
	public class RibbonTabsRequestingEvent : RoutedCompositePresentationEvent<RibbonTabsRequestingEventArgs>
	{
	}
	public class RMBObjectSelectedEventArgs : EventArgs
	{
		public int ObjectType { get; set; }

		public string ObjectPath { get; set; }

		public string ObjectModelTypeName { get; set; }

		public RMBObjectSelectedEventArgs(int iObjectType, string strObjectPath, string strObjectModelTypeName)
		{
			ObjectType = iObjectType;
			ObjectPath = strObjectPath;
			ObjectModelTypeName = strObjectModelTypeName;
		}
	}
	public class RMBObjectSelectedEvent : RoutedCompositePresentationEvent<RMBObjectSelectedEventArgs>
	{
	}
	public enum CostAction
	{
		NONE,
		MAP,
		UNMAP
	}
	public class ShowPartialFlowsheetCostBlocksEventArgs
	{
		public CostAction EEAction { get; set; }

		public string[] ArrayofBlockIds { get; set; }

		public bool SkipCalculation { get; set; }

		public ShowPartialFlowsheetCostBlocksEventArgs(string[] arrayofBlockIds)
		{
			ArrayofBlockIds = arrayofBlockIds;
			SkipCalculation = false;
			EEAction = CostAction.NONE;
		}

		public ShowPartialFlowsheetCostBlocksEventArgs(string[] arrayofBlockIds, bool bSkipCalc)
		{
			ArrayofBlockIds = arrayofBlockIds;
			SkipCalculation = bSkipCalc;
			EEAction = CostAction.NONE;
		}

		public ShowPartialFlowsheetCostBlocksEventArgs(string[] arrayofBlockIds, bool bSkipCalc, CostAction enumAction)
		{
			ArrayofBlockIds = arrayofBlockIds;
			SkipCalculation = bSkipCalc;
			EEAction = enumAction;
		}
	}
	public class ShowPartialFlowsheetCostBlocksEvent : RoutedCompositePresentationEvent<ShowPartialFlowsheetCostBlocksEventArgs>
	{
		public ShowPartialFlowsheetCostBlocksEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class IsIPEInstalledRetrieveEventArgs : EventArgs
	{
		public bool IsIPEInstalled { get; set; }
	}
	public class IsIPEInstalledRetrieveEvent : RoutedCompositePresentationEvent<IsIPEInstalledRetrieveEventArgs>
	{
		public IsIPEInstalledRetrieveEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class ShowABEventArgs : EventArgs
	{
	}
	public class ShowABEvent : RoutedCompositePresentationEvent<ShowABEventArgs>
	{
		public ShowABEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class ShowHtmlHelpEventArgs : EventArgs
	{
		[DefaultValue(null)]
		public string HelpFile { get; set; }

		[DefaultValue(null)]
		public int? HelpCode { get; set; }

		public ShowHtmlHelpEventArgs(string sHelpfile, int? iHelpcode)
		{
			HelpFile = sHelpfile;
			HelpCode = iHelpcode;
		}
	}
	public class ShowHtmlHelpEvent : RoutedCompositePresentationEvent<ShowHtmlHelpEventArgs>
	{
	}
	public abstract class SimulationEventBase<T> : RoutedCompositePresentationEvent<T>
	{
		protected SimulationEventBase()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
	public class SimulationReinitializedEventArgs
	{
	}
	public class SimulationReinitializedEvent : SimulationEventBase<SimulationReinitializedEventArgs>
	{
	}
	public class SimulationRunStartedEventArgs
	{
	}
	public class SimulationRunStartedEvent : SimulationEventBase<SimulationRunStartedEventArgs>
	{
	}
	public class SimulationRunPausedEventArgs
	{
	}
	public class SimulationRunPausedEvent : SimulationEventBase<SimulationRunPausedEventArgs>
	{
	}
	public class SimulationRunCompletedEventArgs
	{
	}
	public class SimulationRunCompletedEvent : SimulationEventBase<SimulationRunCompletedEventArgs>
	{
	}
	public class SimulationRunFailedEventArgs
	{
	}
	public class SimulationRunFailedEvent : SimulationEventBase<SimulationRunFailedEventArgs>
	{
	}
	public class SimulationStatusChangedEventArgs
	{
	}
	public class SimulationStatusChangedEvent : SimulationEventBase<SimulationStatusChangedEventArgs>
	{
	}
	public class SimulationObjectSolvingEventArgs
	{
	}
	public class SimulationObjectSolvingEvent : SimulationEventBase<SimulationObjectSolvingEventArgs>
	{
	}
	public class SimulationIntegrationStepEventArgs
	{
	}
	public class SimulationIntegrationStepEvent : SimulationEventBase<SimulationIntegrationStepEventArgs>
	{
	}
	public class StreamGroupChangedEventArgs : EventArgs
	{
		public string GroupName { get; set; }
	}
	public class StreamGroupChangedEvent : RoutedCompositePresentationEvent<StreamGroupChangedEventArgs>
	{
	}
	public class RefreshPFSStreamEventArgs : EventArgs
	{
		public IEnumerable<string> StreamNames { get; set; }
	}
	public class RefreshPFSStreamEvent : RoutedCompositePresentationEvent<RefreshPFSStreamEventArgs>
	{
	}
	public class AddStreamsToStreamGroupEventArgs : EventArgs
	{
		public string GroupName { get; set; }

		public IEnumerable<string> StreamNames { get; set; }
	}
	public class AddStreamsToStreamGroupEvent : RoutedCompositePresentationEvent<AddStreamsToStreamGroupEventArgs>
	{
	}
	public class RemoveStreamsFromStreamGroupEventArgs : EventArgs
	{
		public string GroupName { get; set; }

		public IEnumerable<string> StreamNames { get; set; }
	}
	public class RemoveStreamsFromStreamGroupEvent : RoutedCompositePresentationEvent<RemoveStreamsFromStreamGroupEventArgs>
	{
	}
	public class UpdateStreamSummaryFormRibbonStatusEventArgs : EventArgs
	{
	}
	public class UpdateStreamSummaryFormRibbonStatusEvent : RoutedCompositePresentationEvent<UpdateStreamSummaryFormRibbonStatusEventArgs>
	{
	}
	public class SynchronizePSVConnectivityEventArgs : EventArgs
	{
		public string StreamFullPath { get; set; }

		public string PSVName { get; set; }

		public SynchronizePSVConnectivityEventArgs(string strStreamFullPath, string strPSVName)
		{
			StreamFullPath = strStreamFullPath;
			PSVName = strPSVName;
		}
	}
	public class SynchronizePSVConnectivityEvent : RoutedCompositePresentationEvent<SynchronizePSVConnectivityEventArgs>
	{
		public SynchronizePSVConnectivityEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class PSVDeleteFromTreeViewEventArgs : EventArgs
	{
		public string StreamFullPath { get; set; }

		public string PSVName { get; set; }

		public PSVDeleteFromTreeViewEventArgs(string strStreamFullPath, string strPSVName)
		{
			StreamFullPath = strStreamFullPath;
			PSVName = strPSVName;
		}
	}
	public class PSVDeleteFromTreeViewEvent : RoutedCompositePresentationEvent<PSVDeleteFromTreeViewEventArgs>
	{
		public PSVDeleteFromTreeViewEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class PSVRenameFromTreeViewEventArgs : EventArgs
	{
		public string StreamFullPath { get; set; }

		public string PSVOldName { get; set; }

		public string PSVNewName { get; set; }

		public PSVRenameFromTreeViewEventArgs(string strStreamFullPath, string strPSVOldName, string strPSVNewName)
		{
			StreamFullPath = strStreamFullPath;
			PSVOldName = strPSVOldName;
			PSVNewName = strPSVNewName;
		}
	}
	public class PSVRenameFromTreeViewEvent : RoutedCompositePresentationEvent<PSVRenameFromTreeViewEventArgs>
	{
		public PSVRenameFromTreeViewEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class ActiveModeChangedEventArg : EventArgs
	{
		public ProblemModes NewMode { get; set; }
	}
	public class ActiveModeChangedEvent : CompositePresentationEvent<ActiveModeChangedEventArg>
	{
	}
	[Serializable]
	public class CancelOpenDocumentEventArgs : EventArgs
	{
		public string Source { get; set; }
	}
	public class CancelOpenDocumentEvent : RoutedCompositePresentationEvent<CancelOpenDocumentEventArgs>
	{
	}
	public class CustomFormRenameEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string CustomFormOldPath { get; set; }

		public string CustomFormNewPath { get; set; }

		public CustomFormRenameEventArgs(string strFlowsheetSubject, string strCustomFormOldPath, string strCustomFormNewPath)
		{
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormOldPath = strCustomFormOldPath;
			CustomFormNewPath = strCustomFormNewPath;
		}
	}
	public class CustomFormRenameEvent : RoutedCompositePresentationEvent<CustomFormRenameEventArgs>
	{
	}
	public class CustomFormDeleteEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string CustomFormPath { get; set; }

		public CustomFormDeleteEventArgs(string strFlowsheetSubject, string strCustomFormPath)
		{
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormPath = strCustomFormPath;
		}
	}
	public class CustomFormDeleteEvent : RoutedCompositePresentationEvent<CustomFormDeleteEventArgs>
	{
	}
	public class CustomFormLayoutChangedEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string CustomFormPath { get; set; }

		public CustomFormLayoutChangedEventArgs(string strFlowsheetSubject, string strCustomFormPath)
		{
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormPath = strCustomFormPath;
		}
	}
	public class CustomFormLayoutChangedEvent : RoutedCompositePresentationEvent<CustomFormLayoutChangedEventArgs>
	{
	}
	public class CustomFormUpdateDataEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public string CustomFormPath { get; set; }

		public CustomFormUpdateDataEventArgs(string strFlowsheetSubject, string strCustomFormPath)
		{
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormPath = strCustomFormPath;
		}
	}
	public class CustomFormUpdateDataEvent : RoutedCompositePresentationEvent<CustomFormUpdateDataEventArgs>
	{
	}
	public class CustomFormFirstColumnUpdateDataEventArgs : EventArgs
	{
		public object CustomFormInstance { get; set; }

		public string FlowsheetSubject { get; set; }

		public string CustomFormPath { get; set; }

		public string TabName { get; set; }

		public int RowIndex { get; set; }

		public string NewValue { get; set; }

		public CustomFormFirstColumnUpdateDataEventArgs(object objCustomFormInstance, string strFlowsheetSubject, string strCustomFormPath, string strTabName, int iRowIndex, string strNewValue)
		{
			CustomFormInstance = objCustomFormInstance;
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormPath = strCustomFormPath;
			TabName = strTabName;
			RowIndex = iRowIndex;
			NewValue = strNewValue;
		}
	}
	public class CustomFormFirstColumnUpdateDataEvent : RoutedCompositePresentationEvent<CustomFormFirstColumnUpdateDataEventArgs>
	{
	}
	public class CustomFormPathColumnUpdateDataEventArgs : EventArgs
	{
		public object CustomFormInstance { get; set; }

		public string FlowsheetSubject { get; set; }

		public string CustomFormPath { get; set; }

		public string TabName { get; set; }

		public int RowIndex { get; set; }

		public string NewValue { get; set; }

		public CustomFormPathColumnUpdateDataEventArgs(object objCustomFormInstance, string strFlowsheetSubject, string strCustomFormPath, string strTabName, int iRowIndex, string strNewValue)
		{
			CustomFormInstance = objCustomFormInstance;
			FlowsheetSubject = strFlowsheetSubject;
			CustomFormPath = strCustomFormPath;
			TabName = strTabName;
			RowIndex = iRowIndex;
			NewValue = strNewValue;
		}
	}
	public class CustomFormPathColumnUpdateDataEvent : RoutedCompositePresentationEvent<CustomFormPathColumnUpdateDataEventArgs>
	{
	}
	public class QueryCustomTableFormPartEventArgs : EventArgs
	{
		public string MainNodePath { get; set; }

		public bool FormIsOpen { get; set; }

		public QueryCustomTableFormPartEventArgs(string strMainNodePath)
		{
			MainNodePath = strMainNodePath;
			FormIsOpen = false;
		}
	}
	public class QueryCustomTableFormPartEvent : RoutedCompositePresentationEvent<QueryCustomTableFormPartEventArgs>
	{
	}
	public class PFSEmbeddedCustomTableStoreValueEventArgs : EventArgs
	{
	}
	public class PFSEmbeddedCustomTableStoreValueEvent : RoutedCompositePresentationEvent<PFSEmbeddedCustomTableStoreValueEventArgs>
	{
	}
	public enum EmbeddedActiveObjectType
	{
		Default,
		CustomForm,
		StreamSummaryForm,
		TopLevelStreamSummaryForm
	}
	public class CustomFormPlaceOnFlowsheetEventArgs : EventArgs
	{
		public object CustomForm { get; set; }

		public object CustomFormImage { get; set; }

		public string MainNodePath { get; set; }

		public bool ShowAsIcon { get; set; }

		public CustomFormPlaceOnFlowsheetEventArgs(object objCustomForm, object objCustomFormImage, string strMainNodePath, bool bShowAsIcon)
		{
			CustomForm = objCustomForm;
			CustomFormImage = objCustomFormImage;
			MainNodePath = strMainNodePath;
			ShowAsIcon = bShowAsIcon;
		}
	}
	public class CustomFormPlaceOnFlowsheetEvent : RoutedCompositePresentationEvent<CustomFormPlaceOnFlowsheetEventArgs>
	{
	}
	public class StreamSummaryFormPlaceOnFlowsheetEventArgs : EventArgs
	{
		public object StreamSummaryForm { get; set; }

		public object StreamSummaryFormImage { get; set; }

		public string MainNodePath { get; set; }

		public bool ShowAsIcon { get; set; }

		public StreamSummaryFormPlaceOnFlowsheetEventArgs(object objStreamSummaryForm, object objImage, string strMainNodePath, bool bShowAsIcon)
		{
			StreamSummaryForm = objStreamSummaryForm;
			StreamSummaryFormImage = objImage;
			MainNodePath = strMainNodePath;
			ShowAsIcon = bShowAsIcon;
		}
	}
	public class StreamSummaryFormPlaceOnFlowsheetEvent : RoutedCompositePresentationEvent<StreamSummaryFormPlaceOnFlowsheetEventArgs>
	{
	}
	public class StreamSummaryFormLayoutChangedEventArgs : EventArgs
	{
		public string MainNodePath { get; set; }

		public StreamSummaryFormLayoutChangedEventArgs(string strMainNodePath)
		{
			MainNodePath = strMainNodePath;
		}
	}
	public class StreamSummaryFormLayoutChangedEvent : RoutedCompositePresentationEvent<StreamSummaryFormLayoutChangedEventArgs>
	{
	}
	public class EmbeddedWPFFormDataChangedEventArgs : EventArgs
	{
		public string MainNodePath { get; set; }

		public EmbeddedActiveObjectType otype { get; set; }

		public EmbeddedWPFFormDataChangedEventArgs(string strMainNodePath, EmbeddedActiveObjectType iotype)
		{
			MainNodePath = strMainNodePath;
			otype = iotype;
		}
	}
	public class EmbeddedWPFFormDataChangedEvent : RoutedCompositePresentationEvent<EmbeddedWPFFormDataChangedEventArgs>
	{
	}
	public class EconomicAutoEvaluateChangedEvent : RoutedCompositePresentationEvent<EventArgs>
	{
		public EconomicAutoEvaluateChangedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.ParentsThenChildren;
		}
	}
	public class EnergyAnalysisAutoCompleteEvent : RoutedCompositePresentationEvent<EventArgs>
	{
		public EnergyAnalysisAutoCompleteEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.ParentsThenChildren;
		}
	}
	public class EvaluateScopeEventArgs : EventArgs
	{
		public IEnumerable<string> SelectedEquipments { get; set; }

		public IEnumerable<string> AllEquipments { get; set; }

		public IEnumerable<string> AllEquipmentsOnCurrentTab { get; set; }
	}
	public class EvaluateScopeEvent : RoutedCompositePresentationEvent<EvaluateScopeEventArgs>
	{
		public EvaluateScopeEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.ParentsThenChildren;
		}
	}
	public class FlowsheetCustomPropSetChangedEventArgs : EventArgs
	{
	}
	public class FlowsheetCustomPropSetChangedEvent : RoutedCompositePresentationEvent<FlowsheetCustomPropSetChangedEventArgs>
	{
	}
	public class SizeScopeEventArgs : EventArgs
	{
		public IEnumerable<string> SelectedEquipments { get; set; }

		public IEnumerable<string> AllEquipments { get; set; }

		public IEnumerable<string> AllEquipmentsOnCurrentTab { get; set; }
	}
	public class SizeScopeEvent : RoutedCompositePresentationEvent<SizeScopeEventArgs>
	{
		public SizeScopeEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.ParentsThenChildren;
		}
	}
	public class TDEConsistencyCheckEventArgs : EventArgs
	{
		public bool RunConsistencyCompleted { get; set; }

		public TDEConsistencyCheckEventArgs(bool bRunConsistencyCompleted)
		{
			RunConsistencyCompleted = bRunConsistencyCompleted;
		}
	}
	public class TDEConsistencyCheckEvent : RoutedCompositePresentationEvent<TDEConsistencyCheckEventArgs>
	{
	}
	public class FlowsheetScreenCloseEventArgs : EventArgs
	{
		public string FlowsheetSubject { get; set; }

		public FlowsheetScreenCloseEventArgs(string strFlowsheetSubject)
		{
			FlowsheetSubject = strFlowsheetSubject;
		}
	}
	public class FlowsheetScreenCloseEvent : RoutedCompositePresentationEvent<FlowsheetScreenCloseEventArgs>
	{
	}
	public class HierarchyBlockRenameEventArgs : EventArgs
	{
		public string OldFlowsheetSubject { get; set; }

		public string NewFlowsheetSubject { get; set; }

		public HierarchyBlockRenameEventArgs(string strOldFlowsheetSubject, string strNewFlowsheetSubject)
		{
			OldFlowsheetSubject = strOldFlowsheetSubject;
			NewFlowsheetSubject = strNewFlowsheetSubject;
		}
	}
	public class HierarchyBlockRenameEvent : RoutedCompositePresentationEvent<HierarchyBlockRenameEventArgs>
	{
	}
	public class EOVariableImportedEventArgs
	{
	}
	public class EOVariableImportedEvent : RoutedCompositePresentationEvent<EOVariableImportedEventArgs>
	{
	}
	public class NavigateTreeNodeActivateOrDeactivateEventArgs : EventArgs
	{
		public string NodeFlowsheetSubject { get; set; }

		public NavigateTreeNodeActivateOrDeactivateEventArgs(string strNodeFlowsheetSubject)
		{
			NodeFlowsheetSubject = strNodeFlowsheetSubject;
		}
	}
	public class NavigateTreeNodeActivateOrDeactivateEvent : RoutedCompositePresentationEvent<NavigateTreeNodeActivateOrDeactivateEventArgs>
	{
	}
	public class FlowsheetOptionChangedEventArgs
	{
	}
	public class FlowsheetOptionChangedEvent : RoutedCompositePresentationEvent<FlowsheetOptionChangedEventArgs>
	{
	}
	public class StartupDialogParametersChangedEvent : RoutedCompositePresentationEvent<EventArgs>
	{
		public StartupDialogParametersChangedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfParentsThenActiveWindow;
		}
	}
	public class StreamTablePrintEventArgs
	{
	}
	public class StreamTablePrintEvent : RoutedCompositePresentationEvent<StreamTablePrintEventArgs>
	{
	}
	public class PFSContextMenuClosedEventArgs
	{
	}
	public class PFSContextMenuClosedEvent : RoutedCompositePresentationEvent<PFSContextMenuClosedEventArgs>
	{
	}
	public class PFSContextMenuClosedPositionEventArgs
	{
		public int X { get; set; }

		public int Y { get; set; }

		public string MouseButtonType { get; set; }

		public PFSContextMenuClosedPositionEventArgs(int nX, int nY, string strMouseButtonType)
		{
			X = nX;
			Y = nY;
			MouseButtonType = strMouseButtonType;
		}
	}
	public class PFSContextMenuClosedPositionEvent : RoutedCompositePresentationEvent<PFSContextMenuClosedPositionEventArgs>
	{
		public PFSContextMenuClosedPositionEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class PFSContextMenuShowEventArgs
	{
		public System.Windows.Controls.ContextMenu PFSContextMenu { get; set; }

		public PFSContextMenuShowEventArgs(System.Windows.Controls.ContextMenu pfsContextMenu)
		{
			PFSContextMenu = pfsContextMenu;
		}
	}
	public class PFSContextMenuShowEvent : RoutedCompositePresentationEvent<PFSContextMenuShowEventArgs>
	{
		public PFSContextMenuShowEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class GridSettingsChangedEventArgs : EventArgs
	{
	}
	public class GridSettingsChangedEvent : RoutedCompositePresentationEvent<GridSettingsChangedEventArgs>
	{
	}
	public class MaterialStreamDefaultLineStyleChangedEventArgs : EventArgs
	{
	}
	public class MaterialStreamDefaultLineStyleChangedEvent : RoutedCompositePresentationEvent<MaterialStreamDefaultLineStyleChangedEventArgs>
	{
	}
	public class RetrieveUndoRedoDataEventArgs : EventArgs
	{
		public object ActiveScreen { get; private set; }

		public RetrieveUndoRedoDataEventArgs(object objActiveScreen)
		{
			ActiveScreen = objActiveScreen;
		}
	}
	public class RetrieveUndoRedoDataEvent : RoutedCompositePresentationEvent<RetrieveUndoRedoDataEventArgs>
	{
	}
	public class DoActiveOrDeactiveModelEventArgs : EventArgs
	{
		public string Path { get; set; }

		public DoActiveOrDeactiveModelEventArgs(string strPath)
		{
			Path = strPath;
		}
	}
	public class DoActiveOrDeactiveModelEvent : RoutedCompositePresentationEvent<DoActiveOrDeactiveModelEventArgs>
	{
	}
	public class FlowsheetControlUndoRedoEventArgs : EventArgs
	{
		public string UndoItems { get; private set; }

		public string RedoItems { get; private set; }

		public string UndoRedoScreenType { get; private set; }

		public FlowsheetControlUndoRedoEventArgs(string strUndoItems, string strRedoItems, string strUndoRedoScreenType)
		{
			UndoItems = strUndoItems;
			RedoItems = strRedoItems;
			UndoRedoScreenType = strUndoRedoScreenType;
		}
	}
	public class FlowsheetControlUndoRedoEvent : RoutedCompositePresentationEvent<FlowsheetControlUndoRedoEventArgs>
	{
	}
	public class FlowsheetControlUndoRedoExecuteEventArgs : EventArgs
	{
		public string StepType { get; private set; }

		public string ActionType { get; private set; }

		public short CurIndex { get; private set; }

		public object ActiveScreen { get; private set; }

		public FlowsheetControlUndoRedoExecuteEventArgs(string strActionType, string strStepType, short iCurIndex, object objActiveScreen)
		{
			ActionType = strActionType;
			StepType = strStepType;
			CurIndex = iCurIndex;
			ActiveScreen = objActiveScreen;
		}
	}
	public class FlowsheetControlUndoRedoExecuteEvent : RoutedCompositePresentationEvent<FlowsheetControlUndoRedoExecuteEventArgs>
	{
	}
	public class ObjectDeleteEventArgs : EventArgs
	{
		public string ObjectType { get; set; }

		public string Name { get; set; }

		public string Path { get; set; }

		public ObjectDeleteEventArgs(string strObjectType, string strName, string strPath)
		{
			ObjectType = strObjectType;
			Name = strName;
			Path = strPath;
		}
	}
	public class ObjectDeleteEvent : RoutedCompositePresentationEvent<ObjectDeleteEventArgs>
	{
	}
	public class ObjectRenameEventArgs : EventArgs
	{
		public string ObjectType { get; set; }

		public string OldName { get; set; }

		public string NewName { get; set; }

		public string Path { get; set; }

		public object Data { get; set; }

		public ObjectRenameEventArgs(string strObjectType, string strOldName, string strNewName, string strPath)
		{
			ObjectType = strObjectType;
			OldName = strOldName;
			NewName = strNewName;
			Path = strPath;
		}
	}
	public class ObjectRenameEvent : RoutedCompositePresentationEvent<ObjectRenameEventArgs>
	{
	}
	public class LockFlowsheetEventArgs : EventArgs
	{
		public bool LockFlowsheetFlag { get; set; }

		public LockFlowsheetEventArgs(bool bLockFlowsheet)
		{
			LockFlowsheetFlag = bLockFlowsheet;
		}
	}
	public class LockFlowsheetEvent : RoutedCompositePresentationEvent<LockFlowsheetEventArgs>
	{
	}
	public class ModelLibraryUndoRedoEventArgs : EventArgs
	{
		public string UndoItems { get; private set; }

		public string RedoItems { get; private set; }

		public string UndoRedoScreenType { get; private set; }

		public ModelLibraryUndoRedoEventArgs(string strUndoItems, string strRedoItems, string strUndoRedoScreenType)
		{
			UndoItems = strUndoItems;
			RedoItems = strRedoItems;
			UndoRedoScreenType = strUndoRedoScreenType;
		}
	}
	public class ModelLibraryUndoRedoEvent : RoutedCompositePresentationEvent<ModelLibraryUndoRedoEventArgs>
	{
	}
	public class ModelLibraryUndoRedoExecuteEventArgs : EventArgs
	{
		public string StepType { get; private set; }

		public string ActionType { get; private set; }

		public short CurIndex { get; private set; }

		public object ActiveScreen { get; private set; }

		public ModelLibraryUndoRedoExecuteEventArgs(string strActionType, string strStepType, short iCurIndex, object objActiveScreen)
		{
			ActionType = strActionType;
			StepType = strStepType;
			CurIndex = iCurIndex;
			ActiveScreen = objActiveScreen;
		}
	}
	public class ModelLibraryUndoRedoExecuteEvent : RoutedCompositePresentationEvent<ModelLibraryUndoRedoExecuteEventArgs>
	{
	}
	public class CostingStatusUpdatedEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class RequestSaveDataShareEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class FlowsheetCancelInsertModeEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class ModelTypeWizardFinishedEventArgs
	{
		public IAEditCategories AffectedEditCategories { get; private set; }

		public ModelTypeWizardFinishedEventArgs(IAEditCategories affectedEditCategories)
		{
			AffectedEditCategories = affectedEditCategories;
		}
	}
	public class ModelTypeWizardFinishedEvent : RoutedCompositePresentationEvent<ModelTypeWizardFinishedEventArgs>
	{
	}
	public class PFSContextMenuItemLoadedEventArgs
	{
		public bool Handled { get; set; }

		public bool CanExecute { get; set; }

		public bool IsChecked { get; set; }

		public int CommandID { get; set; }

		public System.Windows.Controls.MenuItem ContextMenuItem { get; private set; }

		public string Subject { get; set; }

		public Action<PFSContextMenuItemLoadedEventArgs> ExecutedAction { get; set; }

		public PFSContextMenuItemLoadedEventArgs(System.Windows.Controls.MenuItem contextMenuItem)
		{
			if (contextMenuItem == null)
			{
				throw new ArgumentNullException("contextMenuItem");
			}
			ContextMenuItem = contextMenuItem;
		}
	}
	public class PFSContextMenuItemLoadedEvent : RoutedCompositePresentationEvent<PFSContextMenuItemLoadedEventArgs>
	{
		public PFSContextMenuItemLoadedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfChildrenThenParents;
		}
	}
	public class SelecetedModelTypeChangedEventArgs
	{
		public IAModelType SelectedModelType { get; private set; }

		public SelecetedModelTypeChangedEventArgs(IAModelType selectedModelType)
		{
			SelectedModelType = selectedModelType;
		}
	}
	public class SelecetedModelTypeChangedEvent : RoutedCompositePresentationEvent<SelecetedModelTypeChangedEventArgs>
	{
	}
	public class NavigatorPanelTreeSelectedChangedEventArgs : EventArgs
	{
		public string NavigatorPanelTreeNodePath { get; private set; }

		public string NavigatorPanelTreeParentNodePath { get; private set; }

		public string NavigatorPanelTreeNodeKeyReadOnly { get; private set; }

		public int TreeNodeType { get; private set; }

		public string TreeNodeSubject { get; private set; }

		public string TreeNodeName { get; private set; }

		public NavigatorPanelTreeSelectedChangedEventArgs(string strTreeNodeSubject, string strTreeNodeName, int iTreeNodeType)
		{
			TreeNodeSubject = strTreeNodeSubject;
			TreeNodeName = strTreeNodeName;
			TreeNodeType = iTreeNodeType;
		}
	}
	public class NavigatorPanelTreeSelectedChangedEvent : RoutedCompositePresentationEvent<NavigatorPanelTreeSelectedChangedEventArgs>
	{
	}
	public class SelectedEditCategoriesChangedEventArgs
	{
	}
	public class SelectedEditCategoriesChangedEvent : RoutedCompositePresentationEvent<SelectedEditCategoriesChangedEventArgs>
	{
	}
	public class SelectedModelLibrariesChangedEventArgs
	{
	}
	public class SelectedModelLibrariesChangedEvent : RoutedCompositePresentationEvent<SelectedModelLibrariesChangedEventArgs>
	{
	}
	[Serializable]
	public class SetDocumentDirtyEventArg : EventArgs
	{
		public string Source { get; set; }

		public bool DirtyFlag { get; set; }
	}
	public class SetDocumentDirtyEvent : RoutedCompositePresentationEvent<SetDocumentDirtyEventArg>
	{
	}
	[Serializable]
	public class SetDocumentOpenedEventArg : EventArgs
	{
	}
	public class SetDocumentOpenedEvent : RoutedCompositePresentationEvent<SetDocumentOpenedEventArg>
	{
	}
	public class UpdateModelPaletteEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class RefreshModelPaletteEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public class RefreshACMModelManagerEvent : RoutedCompositePresentationEvent<EventArgs>
	{
	}
	public enum UserModelLibraryUpdatedMode
	{
		CreateNewCategory,
		DeleteCurrentCategory,
		RenameCurrentCategory,
		ReorderCategories,
		ReorderModelsInCurrentCategory,
		DeleteCurrentModel,
		RenameCurrentModel,
		MoveCurrentModel,
		CopyCurrentModel,
		EditCurrentIcon,
		CreateNewIcon,
		DeleteCurrentIcon,
		ReorderIconsInCurrentModel,
		EditDescriptionForCurrentModel,
		EditUserConfiguration,
		ClearUserConfiguration
	}
	public class UserModelLibraryUpdatedEventArgs
	{
		public IAEditCategories AffectedEditCategories { get; private set; }

		public UserModelLibraryUpdatedMode Action { get; private set; }

		public UserModelLibraryUpdatedEventArgs(IAEditCategories affectedEditCategories, UserModelLibraryUpdatedMode action)
		{
			if (affectedEditCategories == null)
			{
				throw new ArgumentNullException("affectedEditCategories");
			}
			AffectedEditCategories = affectedEditCategories;
			Action = action;
		}
	}
	public class UserModelLibraryUpdatedEvent : RoutedCompositePresentationEvent<UserModelLibraryUpdatedEventArgs>
	{
	}
	public class ViewFilterChangedEventArgs
	{
		public string NavigatorGroupKey { get; private set; }

		public ViewsFilterOption OldFilter { get; private set; }

		public ViewsFilterOption NewFilter { get; private set; }

		public ViewFilterChangedEventArgs(string navigatorGroupKey, ViewsFilterOption oldFilter, ViewsFilterOption newFilter)
		{
			NavigatorGroupKey = navigatorGroupKey;
			OldFilter = oldFilter;
			NewFilter = newFilter;
		}
	}
	public class ViewFilterChangedEvent : RoutedCompositePresentationEvent<ViewFilterChangedEventArgs>
	{
	}
	public class NavigateToEventArgs : EventArgs
	{
		public string Group { get; set; }

		public string Path { get; set; }

		public bool UseNewTab { get; set; }

		public string TabName { get; set; }

		[DefaultValue(true)]
		public bool IsSucceeded { get; set; }

		public ScreenLocation? InitialLocation { get; set; }
	}
	public class NavigateToEvent : RoutedCompositePresentationEvent<NavigateToEventArgs>
	{
		public NavigateToEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfParentsThenActiveWindow;
		}
	}
	public class NavigateToResultSummaryEquipmentTabEventArgs : EventArgs
	{
		public bool UseNewTab { get; set; }

		public string TabName { get; set; }
	}
	public class NavigateToResultSummaryEquipmentTabEvent : RoutedCompositePresentationEvent<NavigateToResultSummaryEquipmentTabEventArgs>
	{
	}
	public class ObjectChangedEventArgs
	{
		public string Name { get; set; }
	}
	public class ObjectChangedEvent : CompositePresentationEvent<ObjectChangedEventArgs>
	{
	}
	public class ObjectSelectedEventArgs : EventArgs
	{
		public string ModelType { get; set; }

		public string ObjectName { get; set; }

		public int ObjectType { get; set; }

		public string ObjectNavigatorPath { get; set; }
	}
	public class ObjectSelectedEvent : RoutedCompositePresentationEvent<ObjectSelectedEventArgs>
	{
		public ObjectSelectedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.FirstOfParentsThenActiveWindow;
		}
	}
	public class ResultsAvailableEventArgs : EventArgs
	{
		public bool? Available { get; private set; }

		public ResultsAvailableEventArgs(bool available)
		{
			Available = available;
		}
	}
	public class ResultsAvailableEvent : RoutedCompositePresentationEvent<ResultsAvailableEventArgs>
	{
		public ResultsAvailableEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.ParentsThenChildren;
		}
	}
	public class ShowFormEventArgs : EventArgs
	{
		[DefaultValue(null)]
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public Type FormType { get; set; }

		[DefaultValue(null)]
		public string FormProgId { get; set; }

		[DefaultValue(null)]
		public string FormKey { get; set; }

		[DefaultValue(null)]
		public string Header { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IDictionary<string, object> Parameters { get; private set; }

		[DefaultValue(null)]
		public bool? ResultsOnly { get; set; }

		[DefaultValue(null)]
		public bool? CloseContentOnUnload { get; set; }

		[DefaultValue(null)]
		public string PathKey { get; set; }

		public ShowFormEventArgs()
		{
			Parameters = new Dictionary<string, object>();
		}

		public ShowFormEventArgs(IDictionary<string, object> parameters)
		{
			if (parameters != null)
			{
				Parameters = parameters;
			}
			else
			{
				Parameters = new Dictionary<string, object>();
			}
		}
	}
	public class ShowFormEvent : CompositePresentationEvent<ShowFormEventArgs>
	{
	}
}
namespace AspenTech.AspenPlus.Aosapfs
{
	[ComImport]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("A89BB1D2-1057-11D2-80E4-0000C09EFCF3")]
	[TypeIdentifier]
	public interface IAEditCategories
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("B19E42BF-7889-11D0-A91B-0000C0A118DB")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[TypeIdentifier]
	public interface IAModel
	{
	}
	[ComImport]
	[CompilerGenerated]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[Guid("B19E42B2-7889-11D0-A91B-0000C0A118DB")]
	[TypeIdentifier]
	public interface IAModelType
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("B19E42C0-7889-11D0-A91B-0000C0A118DB")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	[TypeIdentifier]
	public interface IEnumAModel
	{
	}
}
namespace AspenTech.AspenPlus.Happ
{
	[ComImport]
	[CompilerGenerated]
	[Guid("11677780-B72B-11D0-A943-0000C0A118DB")]
	[CoClass(typeof(object))]
	[TypeIdentifier]
	public interface CHPlotVal : IHPlotVal
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("8E567521-F9BA-11CF-90B2-0000C0A810C4")]
	[CoClass(typeof(object))]
	[TypeIdentifier]
	public interface HappLS : IHapp, IAPHappEvents_Event
	{
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("503FD632-F63E-11D1-8D3E-0000C033EAF2")]
	[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
	[TypeIdentifier]
	public interface IAPHappEvents
	{
		void _VtblGap1_4();

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(104)]
		void OnDataChanged([In][MarshalAs(UnmanagedType.IDispatch)] object pObj);

		[MethodImpl(MethodImplOptions.PreserveSig | MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(105)]
		void OnUpdateMessage([In] int msg_code, [In][MarshalAs(UnmanagedType.BStr)] string msg_hint, [In][MarshalAs(UnmanagedType.IDispatch)] object msg_object, [In] int source_handle);
	}
	// TypeDef 0x02000148 carries the Import flag with no GuidAttribute in the embedded event interface metadata.
	[CompilerGenerated]
	[ComEventInterface(typeof(IAPHappEvents), typeof(IAPHappEvents))]
	[TypeIdentifier("8E567520-F9BA-11CF-90B2-0000C0A810C4", "AspenTech.AspenPlus.Happ.IAPHappEvents_Event")]
	public interface IAPHappEvents_Event
	{
		void _VtblGap1_8();

		event IAPHappEvents_OnDataChangedEventHandler OnDataChanged;

		event IAPHappEvents_OnUpdateMessageEventHandler OnUpdateMessage;
	}
	[CompilerGenerated]
	[TypeIdentifier("8E567520-F9BA-11CF-90B2-0000C0A810C4", "AspenTech.AspenPlus.Happ.IAPHappEvents_OnDataChangedEventHandler")]
	public delegate void IAPHappEvents_OnDataChangedEventHandler([In][MarshalAs(UnmanagedType.IDispatch)] object pObj);
	[CompilerGenerated]
	[TypeIdentifier("8E567520-F9BA-11CF-90B2-0000C0A810C4", "AspenTech.AspenPlus.Happ.IAPHappEvents_OnUpdateMessageEventHandler")]
	public delegate void IAPHappEvents_OnUpdateMessageEventHandler([In] int msg_code, [In][MarshalAs(UnmanagedType.BStr)] string msg_hint, [In][MarshalAs(UnmanagedType.IDispatch)] object msg_object, [In] int source_handle);
	[ComImport]
	[CompilerGenerated]
	[Guid("8E567522-F9BA-11CF-90B2-0000C0A810C4")]
	[TypeIdentifier]
	public interface IHNode
	{
		void _VtblGap1_2();

		// Indexed COM property 0x17000192 (Name), DispId 1610743810.
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		string get_Name([In, Optional, MarshalAs(UnmanagedType.Struct)] object force);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743810)]
		void set_Name([In, Optional, MarshalAs(UnmanagedType.Struct)] object force, [In, MarshalAs(UnmanagedType.BStr)] string Name);




	}
	[ComImport]
	[CompilerGenerated]
	[Guid("11677780-B72B-11D0-A943-0000C0A118DB")]
	[TypeIdentifier]
	public interface IHPlotVal
	{
		void _VtblGap1_2();

		// COM property 0x17000193 (Title), DispId 1610743810.
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743810)]
		[return: MarshalAs(UnmanagedType.BStr)]
		string get_Title();

		void _VtblGap2_1();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743810)]
		void set_Title([In, MarshalAs(UnmanagedType.BStr)] string Title);





		// COM property 0x17000194 (XAxisTitle), DispId 1610743813.
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743813)]
		[return: MarshalAs(UnmanagedType.BStr)]
		string get_XAxisTitle();

		void _VtblGap3_1();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743813)]
		void set_XAxisTitle([In, MarshalAs(UnmanagedType.BStr)] string xtitle);





		// Indexed COM property 0x17000195 (YAxisTitle), DispId 1610743816.
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743816)]
		[return: MarshalAs(UnmanagedType.BStr)]
		string get_YAxisTitle([In, Optional, MarshalAs(UnmanagedType.Struct)] object nAxis);

		void _VtblGap4_1();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[SpecialName, DispId(1610743816)]
		void set_YAxisTitle([In, Optional, MarshalAs(UnmanagedType.Struct)] object nAxis, [In, MarshalAs(UnmanagedType.BStr)] string ytitle);





		void _VtblGap5_24();

		[DispId(1610743843)]
		int PlotType
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743843)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743843)]
			[param: In]
			set;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("8008C730-1A3E-11D1-8A4D-0000C0237DF9")]
	[TypeIdentifier]
	public interface IHWizardPlot
	{
		[DispId(1610743808)]
		CHPlotVal PlotVal
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743808)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}

		[DispId(1610743809)]
		int basis
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743809)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743809)]
			[param: In]
			set;
		}

		void _VtblGap1_4();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743815)]
		void SetIndependentVariable([In][MarshalAs(UnmanagedType.Interface)] IHNode pContext, [In][MarshalAs(UnmanagedType.BStr)] string indepvar);
	}
	[ComImport]
	[CompilerGenerated]
	[DefaultMember("Name")]
	[Guid("8E567521-F9BA-11CF-90B2-0000C0A810C4")]
	[TypeIdentifier]
	public interface IHapp
	{
		void _VtblGap1_3();

		[DispId(0)]
		string Name
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(0)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000001 ApwnShell.Infrastructure.ScreenFactoryKeys..cctor
// static ScreenFactoryKeys()
// {
// 	ApwnFormContentFactory = "ApwnFormContentFactory";
// 	BrowserScreenFactory = "BrowserScreenFactory";
// 	MessageViewFactory = "MessageViewFactory";
// 	PromptViewFactory = "PromptViewFactory";
// 	ViewModelDumpFactory = "ViewModelDumpFactory";
// 	AnalysisScreenFactory = "AnalysisScreenFactory";
// 	ControlPanelScreenFactory = "ControlPanelScreenFactory";
// 	FlowsheetScreenFactory = "FlowsheetScreenFactory";
// 	NewFlowsheetScreenFactory = "NewFlowsheetScreenFactory";
// 	ApwnPlotScreenFactory = "ApwnPlotScreenFactory";
// 	Apwn3DPlotScreenFactory = "Apwn3DPlotScreenFactory";
// 	Apwn3DPlotScreenV2Factory = "Apwn3DPlotScreenV2Factory";
// 	ApwnPlotWizardScreenFactory = "ApwnPlotWizardScreenFactory";
// 	TdeEvaluateResultScreenFactory = "TdeEvaluateResultScreenFactory";
// 	TDEDialogScreenFactory = "TDEDialogScreenFactory";
// 	AspenMarketPlaceScreenFactory = "AspenMarketPlaceScreenFactory";
// 	AOLConfigurationScreenFactory = "AOLConfigurationScreenFactory";
// 	ApwnTimePlotScreenFactory = "ApwnTimePlotScreenFactory";
// 	SpecChemPlotScreenFactory = "SpecChemPlotScreenFactory";
// 	UnitProcedureSummaryResultsScreenFactory = "UnitProcedureSummaryResultsScreenFactory";
// 	ApwnPlotWizardNewPlotControlScreenFactory = "ApwnPlotWizardNewPlotControlScreenFactory";
// 	ApwnPlotNewPlotControlScreenFactory = "ApwnPlotNewPlotControlScreenFactory";
// 	CustomModelsEditorScreenFactory = "CustomModelsEditorScreenFactory";
// 	CustomModelsObjectManagerScreenFactory = "CustomModelsObjectManagerScreenFactory";
// }

// 0x06000017 AspenTech.AspenPlus.ACMModelLibraryHelper..ctor
// public ACMModelLibraryHelper()
// {
// }

// 0x06000028 AspenTech.AspenPlus.Infrastructure.APEDHelpers..cctor
// static APEDHelpers()
// {
// 	LocalDB = 0;
// 	error = string.Empty;
// 	bWin10 = false;
// 	bLocalDB = false;
// }

// 0x06000076 AspenTech.AspenPlus.Infrastructure.AsyncDelegateCommand`1.add_CanExecuteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanExecuteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanExecuteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000077 AspenTech.AspenPlus.Infrastructure.AsyncDelegateCommand`1.remove_CanExecuteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanExecuteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanExecuteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x0600007e AspenTech.AspenPlus.Infrastructure.AttachedProperties..ctor
// public AttachedProperties()
// {
// }

// 0x0600007f AspenTech.AspenPlus.Infrastructure.AttachedProperties..cctor
// using System.Windows;
//
// static AttachedProperties()
// {
// 	IsTextBindingTriggerWithPropertyChangeProperty = DependencyProperty.RegisterAttached("IsTextBindingTriggerWithPropertyChange", typeof(bool), typeof(AttachedProperties), new PropertyMetadata(false, IsTextBindingTriggerWithPropertyChanged));
// }

// 0x06000095 AspenTech.AspenPlus.Infrastructure.CaseFileSettings..ctor
// public CaseFileSettings()
// {
// }

// 0x0600009f AspenTech.AspenPlus.Infrastructure.CustomModelsEditorScreenSubject..ctor
// public CustomModelsEditorScreenSubject()
// {
// }

// 0x060000c4 AspenTech.AspenPlus.Infrastructure.ExceptionHelper..ctor
// public ExceptionHelper()
// {
// }

// 0x060000d6 AspenTech.AspenPlus.Infrastructure.BrowserScreenSubject..ctor
// public BrowserScreenSubject()
// {
// }

// 0x060000d9 AspenTech.AspenPlus.Infrastructure.IsStringValueToCollapsedConverter..ctor
// public IsStringValueToCollapsedConverter()
// {
// }

// 0x060000dc AspenTech.AspenPlus.Infrastructure.IsStringValueToVisibleConverter..ctor
// public IsStringValueToVisibleConverter()
// {
// }

// 0x060000df AspenTech.AspenPlus.Infrastructure.IsNotStringValueToBooleanConverter..ctor
// public IsNotStringValueToBooleanConverter()
// {
// }

// 0x060000e2 AspenTech.AspenPlus.Infrastructure.IsStringValueToBooleanConverter..ctor
// public IsStringValueToBooleanConverter()
// {
// }

// 0x060000e5 AspenTech.AspenPlus.Infrastructure.NotNullToBooleanConverter..ctor
// public NotNullToBooleanConverter()
// {
// }

// 0x060000e8 AspenTech.AspenPlus.Infrastructure.CommaSplittedStringListToBoolConverter..ctor
// public CommaSplittedStringListToBoolConverter()
// {
// }

// 0x0600010f AspenTech.AspenPlus.Infrastructure.SimualationSequenceNode..ctor
// protected SimualationSequenceNode()
// {
// }

// 0x06000124 AspenTech.AspenPlus.Infrastructure.DriveDialogEventArgs..ctor
// using System.Collections.Generic;
//
// public DriveDialogEventArgs()
// {
// 	_formParameters = new Dictionary<string, object>();
// 	base..ctor();
// }

// 0x06000175 AspenTech.AspenPlus.Infrastructure.RibbonEmbedHelper..cctor
// using System.Collections.Generic;
// using Infragistics.Windows.Ribbon;
//
// static RibbonEmbedHelper()
// {
// 	GroupToScreenDict = new Dictionary<RibbonGroup, IRibbonEmbeddable>();
// }

// 0x06000198 AspenTech.AspenPlus.Infrastructure.PWRPlotType..ctor
// public PWRPlotType()
// {
// }

// 0x060001a1 AspenTech.AspenPlus.Infrastructure.PWRParser..ctor
// public PWRParser()
// {
// }

// 0x060001a2 AspenTech.AspenPlus.Infrastructure.PWRParser..cctor
// static PWRParser()
// {
// 	TobeReplaced = new char[7] { '(', ')', '-', ' ', '.', '/', '\\' };
// 	UnderLine = '_';
// }

// 0x06000217 AspenTech.AspenPlus.Infrastructure.NavigationGroupKeys..cctor
// static NavigationGroupKeys()
// {
// 	AllDataGroup = "All Data";
// 	SimulationGroup = "Simulation";
// 	PropertiesGroup = "Properties";
// 	EnergyAnalysisGroup = "Energy Analysis";
// 	PSVPlusGroup = "PSVPlus";
// }

// 0x06000225 AspenTech.AspenPlus.Infrastructure.PrintPageSettings..ctor
// public PrintPageSettings()
// {
// }

// 0x0600022f AspenTech.AspenPlus.Infrastructure.RibbonToolExtensions..ctor
// public RibbonToolExtensions()
// {
// }

// 0x06000230 AspenTech.AspenPlus.Infrastructure.RibbonToolExtensions..cctor
// using System.Windows;
// using System.Windows.Input;
//
// static RibbonToolExtensions()
// {
// 	CommandProperty = DependencyProperty.RegisterAttached("Command", typeof(ICommand), typeof(RibbonToolExtensions), new PropertyMetadata(OnCommandPropertyChanged));
// }

// 0x06000240 AspenTech.AspenPlus.Infrastructure.ShellSettingsSerializer..cctor
// static ShellSettingsSerializer()
// {
// 	plugins = new string[7] { "AOLServiceDLL", "AOLUtils", "AspenOnLine.WindowsClientAppContent", "AspenTech.AspenOnLine.Infrastructure", "AspenTech.AspenOnLine.RemotingHelper", "AspenTech.AspenOnLine.UI.Infrastructure", "AOLLocalization" };
// }

// 0x0600025d AspenTech.AspenPlus.Infrastructure.StringScreenSubject..ctor
// public StringScreenSubject()
// {
// }

// 0x06000289 AspenTech.AspenPlus.Infrastructure.SystemEnvironment..cctor
// using System.Collections.Generic;
//
// static SystemEnvironment()
// {
// 	_executablePath = null;
// 	_logger = new DebugLogger();
// 	_internalVersionString = null;
// 	_externalVersionString = null;
// 	_pathVersionString = null;
// 	_latestEconomicsCompleteInternalVersion = null;
// 	_latestComProgIDSuffix = null;
// 	_edrVersion = null;
// 	_edrLocation = null;
// 	commonXeqDirectory = null;
// 	AMSystemHelpDirectory = null;
// 	MMTOPDirectory = null;
// 	dynamicsInstalled = -1;
// 	_configurationFile = null;
// 	_configurationInfo = new Dictionary<string, string>();
// 	ChmHelpToURLMap = new Dictionary<string, string>();
// 	ChmUserGuide1ToURLMap = new Dictionary<string, string>();
// }

// 0x0600028b AspenTech.AspenPlus.Infrastructure.Properties.Settings..ctor
// public Settings()
// {
// }

// 0x0600028c AspenTech.AspenPlus.Infrastructure.Properties.Settings..cctor
// using System.Configuration;
//
// static Settings()
// {
// 	defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());
// }

// 0x0600028d AspenTech.AspenPlus.Infrastructure.MvvmCore.ObservableObject.add_PropertyChanged
// using System;
// using System.ComponentModel;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
// 	PropertyChangedEventHandler propertyChangedEventHandler2;
// 	do
// 	{
// 		propertyChangedEventHandler2 = propertyChangedEventHandler;
// 		PropertyChangedEventHandler value2 = (PropertyChangedEventHandler)Delegate.Combine(propertyChangedEventHandler2, value);
// 		propertyChangedEventHandler = Interlocked.CompareExchange(ref this.PropertyChanged, value2, propertyChangedEventHandler2);
// 	}
// 	while ((object)propertyChangedEventHandler != propertyChangedEventHandler2);
// }

// 0x0600028e AspenTech.AspenPlus.Infrastructure.MvvmCore.ObservableObject.remove_PropertyChanged
// using System;
// using System.ComponentModel;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
// 	PropertyChangedEventHandler propertyChangedEventHandler2;
// 	do
// 	{
// 		propertyChangedEventHandler2 = propertyChangedEventHandler;
// 		PropertyChangedEventHandler value2 = (PropertyChangedEventHandler)Delegate.Remove(propertyChangedEventHandler2, value);
// 		propertyChangedEventHandler = Interlocked.CompareExchange(ref this.PropertyChanged, value2, propertyChangedEventHandler2);
// 	}
// 	while ((object)propertyChangedEventHandler != propertyChangedEventHandler2);
// }

// 0x06000291 AspenTech.AspenPlus.Infrastructure.MvvmCore.ObservableObject..ctor
// public ObservableObject()
// {
// }

// 0x06000294 AspenTech.AspenPlus.Infrastructure.Events.ShowACMModelHelpEventArg..ctor
// public ShowACMModelHelpEventArg()
// {
// }

// 0x06000295 AspenTech.AspenPlus.Infrastructure.Events.ShowACMModelHelpEvent..ctor
// public ShowACMModelHelpEvent()
// {
// }

// 0x06000298 AspenTech.AspenPlus.Infrastructure.Events.UpdateACMModelDOFEventArg..ctor
// public UpdateACMModelDOFEventArg()
// {
// }

// 0x06000299 AspenTech.AspenPlus.Infrastructure.Events.UpdateACMModelDOFEvent..ctor
// public UpdateACMModelDOFEvent()
// {
// }

// 0x0600029d AspenTech.AspenPlus.Infrastructure.Events.ProcessTypeChangedEventArgs..ctor
// public ProcessTypeChangedEventArgs()
// {
// }

// 0x0600029e AspenTech.AspenPlus.Infrastructure.Events.ProcessTypeChangedEvent..ctor
// public ProcessTypeChangedEvent()
// {
// }

// 0x0600029f AspenTech.AspenPlus.Infrastructure.Events.CloseCustomModelEditorEvent..ctor
// public CloseCustomModelEditorEvent()
// {
// }

// 0x060002a3 AspenTech.AspenPlus.Infrastructure.Events.SaveCustomModelEditorEvent..ctor
// public SaveCustomModelEditorEvent()
// {
// }

// 0x060002a7 AspenTech.AspenPlus.Infrastructure.Events.ColumnInternalsInvokedEventArgs..ctor
// public ColumnInternalsInvokedEventArgs()
// {
// }

// 0x060002a8 AspenTech.AspenPlus.Infrastructure.Events.ColumnInternalsInvoked..ctor
// public ColumnInternalsInvoked()
// {
// }

// 0x060002ab AspenTech.AspenPlus.Infrastructure.Events.ContextMenuFindObjectEventArgs..ctor
// public ContextMenuFindObjectEventArgs()
// {
// }

// 0x060002ac AspenTech.AspenPlus.Infrastructure.Events.ContextMenuFindObjectEvent..ctor
// public ContextMenuFindObjectEvent()
// {
// }

// 0x060002b1 AspenTech.AspenPlus.Infrastructure.Events.ContextMenuFindObjectCanExecuteEventArgs..ctor
// public ContextMenuFindObjectCanExecuteEventArgs()
// {
// }

// 0x060002b2 AspenTech.AspenPlus.Infrastructure.Events.ContextMenuFindObjectCanExecuteEvent..ctor
// public ContextMenuFindObjectCanExecuteEvent()
// {
// }

// 0x060002b9 AspenTech.AspenPlus.Infrastructure.Events.FODSelectObjectInFlowsheetEventArgs..ctor
// public FODSelectObjectInFlowsheetEventArgs()
// {
// }

// 0x060002ba AspenTech.AspenPlus.Infrastructure.Events.FODSelectObjectInFlowsheetEvent..ctor
// public FODSelectObjectInFlowsheetEvent()
// {
// }

// 0x060002c1 AspenTech.AspenPlus.Infrastructure.Events.FODFindObjectInFlowsheetEventArgs..ctor
// public FODFindObjectInFlowsheetEventArgs()
// {
// }

// 0x060002c2 AspenTech.AspenPlus.Infrastructure.Events.FODFindObjectInFlowsheetEvent..ctor
// public FODFindObjectInFlowsheetEvent()
// {
// }

// 0x060002cb AspenTech.AspenPlus.Infrastructure.Events.FODOpenFormInPSVEventArgs..ctor
// public FODOpenFormInPSVEventArgs()
// {
// }

// 0x060002cc AspenTech.AspenPlus.Infrastructure.Events.FODOpenFormInPSVEvent..ctor
// public FODOpenFormInPSVEvent()
// {
// }

// 0x060002cf AspenTech.AspenPlus.Infrastructure.Events.RenameFlowsheetSectionEventArgs..ctor
// public RenameFlowsheetSectionEventArgs()
// {
// }

// 0x060002d0 AspenTech.AspenPlus.Infrastructure.Events.RenameFlowsheetSectionEvent..ctor
// public RenameFlowsheetSectionEvent()
// {
// }

// 0x060002d3 AspenTech.AspenPlus.Infrastructure.Events.AddFlowsheetSectionEventArgs..ctor
// public AddFlowsheetSectionEventArgs()
// {
// }

// 0x060002d4 AspenTech.AspenPlus.Infrastructure.Events.AddFlowsheetSectionEvent..ctor
// public AddFlowsheetSectionEvent()
// {
// }

// 0x060002d7 AspenTech.AspenPlus.Infrastructure.Events.FlowsheetSectionChangedEventArgs..ctor
// public FlowsheetSectionChangedEventArgs()
// {
// }

// 0x060002d8 AspenTech.AspenPlus.Infrastructure.Events.FlowsheetSectionChangedEvent..ctor
// public FlowsheetSectionChangedEvent()
// {
// }

// 0x060002f5 AspenTech.AspenPlus.Infrastructure.Events.SetDataGridCageEventArgs..ctor
// public SetDataGridCageEventArgs()
// {
// }

// 0x060002f6 AspenTech.AspenPlus.Infrastructure.Events.SetDataGridCageEvent..ctor
// public SetDataGridCageEvent()
// {
// }

// 0x060002fa AspenTech.AspenPlus.Infrastructure.Events.DisposeDataGridCageEvent..ctor
// public DisposeDataGridCageEvent()
// {
// }

// 0x060002fe AspenTech.AspenPlus.Infrastructure.Events.SetupDataGridCageEvent..ctor
// public SetupDataGridCageEvent()
// {
// }

// 0x06000301 AspenTech.AspenPlus.Infrastructure.Events.QueryFlowsheetModeEventArgs..ctor
// public QueryFlowsheetModeEventArgs()
// {
// }

// 0x06000302 AspenTech.AspenPlus.Infrastructure.Events.QueryFlowsheetModeEvent..ctor
// public QueryFlowsheetModeEvent()
// {
// }

// 0x06000303 AspenTech.AspenPlus.Infrastructure.Events.DocumentClosedEventArgs..ctor
// public DocumentClosedEventArgs()
// {
// }

// 0x06000304 AspenTech.AspenPlus.Infrastructure.Events.DocumentClosedEvent..ctor
// public DocumentClosedEvent()
// {
// }

// 0x06000307 AspenTech.AspenPlus.Infrastructure.Events.FileDropEventArg..ctor
// public FileDropEventArg()
// {
// }

// 0x06000308 AspenTech.AspenPlus.Infrastructure.Events.FileDropEvent..ctor
// public FileDropEvent()
// {
// }

// 0x0600030e AspenTech.AspenPlus.Infrastructure.Events.IsNormalRunEvent..ctor
// public IsNormalRunEvent()
// {
// }

// 0x0600030f AspenTech.AspenPlus.Infrastructure.Events.ModelLibrarySaveEventArgs..ctor
// public ModelLibrarySaveEventArgs()
// {
// }

// 0x06000310 AspenTech.AspenPlus.Infrastructure.Events.ModelLibrarySaveEvent..ctor
// public ModelLibrarySaveEvent()
// {
// }

// 0x06000319 AspenTech.AspenPlus.Infrastructure.Events.RecordMoveToHierarchyEvent..ctor
// public RecordMoveToHierarchyEvent()
// {
// }

// 0x06000322 AspenTech.AspenPlus.Infrastructure.Events.MoveHierarchyToHierarchyEvent..ctor
// public MoveHierarchyToHierarchyEvent()
// {
// }

// 0x06000328 AspenTech.AspenPlus.Infrastructure.Events.MoveSelectionEvent..ctor
// public MoveSelectionEvent()
// {
// }

// 0x0600032c AspenTech.AspenPlus.Infrastructure.Events.RecordUpdatedCustomTableEvent..ctor
// public RecordUpdatedCustomTableEvent()
// {
// }

// 0x06000335 AspenTech.AspenPlus.Infrastructure.Events.PFSContextMenuItemBlockTypeRetrieveEventArgs..ctor
// public PFSContextMenuItemBlockTypeRetrieveEventArgs()
// {
// }

// 0x0600033d AspenTech.AspenPlus.Infrastructure.Events.PFSUpdateAnimateFlagEvent..ctor
// public PFSUpdateAnimateFlagEvent()
// {
// }

// 0x06000341 AspenTech.AspenPlus.Infrastructure.Events.ReInitEvent..ctor
// public ReInitEvent()
// {
// }

// 0x06000346 AspenTech.AspenPlus.Infrastructure.Events.RibbonTabsRequestingEventArgs..ctor
// public RibbonTabsRequestingEventArgs()
// {
// }

// 0x06000347 AspenTech.AspenPlus.Infrastructure.Events.RibbonTabsRequestingEvent..ctor
// public RibbonTabsRequestingEvent()
// {
// }

// 0x0600034f AspenTech.AspenPlus.Infrastructure.Events.RMBObjectSelectedEvent..ctor
// public RMBObjectSelectedEvent()
// {
// }

// 0x0600035c AspenTech.AspenPlus.Infrastructure.Events.IsIPEInstalledRetrieveEventArgs..ctor
// public IsIPEInstalledRetrieveEventArgs()
// {
// }

// 0x0600035e AspenTech.AspenPlus.Infrastructure.Events.ShowABEventArgs..ctor
// public ShowABEventArgs()
// {
// }

// 0x06000365 AspenTech.AspenPlus.Infrastructure.Events.ShowHtmlHelpEvent..ctor
// public ShowHtmlHelpEvent()
// {
// }

// 0x06000367 AspenTech.AspenPlus.Infrastructure.Events.SimulationReinitializedEventArgs..ctor
// public SimulationReinitializedEventArgs()
// {
// }

// 0x06000368 AspenTech.AspenPlus.Infrastructure.Events.SimulationReinitializedEvent..ctor
// public SimulationReinitializedEvent()
// {
// }

// 0x06000369 AspenTech.AspenPlus.Infrastructure.Events.SimulationRunStartedEventArgs..ctor
// public SimulationRunStartedEventArgs()
// {
// }

// 0x0600036a AspenTech.AspenPlus.Infrastructure.Events.SimulationRunStartedEvent..ctor
// public SimulationRunStartedEvent()
// {
// }

// 0x0600036b AspenTech.AspenPlus.Infrastructure.Events.SimulationRunPausedEventArgs..ctor
// public SimulationRunPausedEventArgs()
// {
// }

// 0x0600036c AspenTech.AspenPlus.Infrastructure.Events.SimulationRunPausedEvent..ctor
// public SimulationRunPausedEvent()
// {
// }

// 0x0600036d AspenTech.AspenPlus.Infrastructure.Events.SimulationRunCompletedEventArgs..ctor
// public SimulationRunCompletedEventArgs()
// {
// }

// 0x0600036e AspenTech.AspenPlus.Infrastructure.Events.SimulationRunCompletedEvent..ctor
// public SimulationRunCompletedEvent()
// {
// }

// 0x0600036f AspenTech.AspenPlus.Infrastructure.Events.SimulationRunFailedEventArgs..ctor
// public SimulationRunFailedEventArgs()
// {
// }

// 0x06000370 AspenTech.AspenPlus.Infrastructure.Events.SimulationRunFailedEvent..ctor
// public SimulationRunFailedEvent()
// {
// }

// 0x06000371 AspenTech.AspenPlus.Infrastructure.Events.SimulationStatusChangedEventArgs..ctor
// public SimulationStatusChangedEventArgs()
// {
// }

// 0x06000372 AspenTech.AspenPlus.Infrastructure.Events.SimulationStatusChangedEvent..ctor
// public SimulationStatusChangedEvent()
// {
// }

// 0x06000373 AspenTech.AspenPlus.Infrastructure.Events.SimulationObjectSolvingEventArgs..ctor
// public SimulationObjectSolvingEventArgs()
// {
// }

// 0x06000374 AspenTech.AspenPlus.Infrastructure.Events.SimulationObjectSolvingEvent..ctor
// public SimulationObjectSolvingEvent()
// {
// }

// 0x06000375 AspenTech.AspenPlus.Infrastructure.Events.SimulationIntegrationStepEventArgs..ctor
// public SimulationIntegrationStepEventArgs()
// {
// }

// 0x06000376 AspenTech.AspenPlus.Infrastructure.Events.SimulationIntegrationStepEvent..ctor
// public SimulationIntegrationStepEvent()
// {
// }

// 0x06000379 AspenTech.AspenPlus.Infrastructure.Events.StreamGroupChangedEventArgs..ctor
// public StreamGroupChangedEventArgs()
// {
// }

// 0x0600037a AspenTech.AspenPlus.Infrastructure.Events.StreamGroupChangedEvent..ctor
// public StreamGroupChangedEvent()
// {
// }

// 0x0600037d AspenTech.AspenPlus.Infrastructure.Events.RefreshPFSStreamEventArgs..ctor
// public RefreshPFSStreamEventArgs()
// {
// }

// 0x0600037e AspenTech.AspenPlus.Infrastructure.Events.RefreshPFSStreamEvent..ctor
// public RefreshPFSStreamEvent()
// {
// }

// 0x06000383 AspenTech.AspenPlus.Infrastructure.Events.AddStreamsToStreamGroupEventArgs..ctor
// public AddStreamsToStreamGroupEventArgs()
// {
// }

// 0x06000384 AspenTech.AspenPlus.Infrastructure.Events.AddStreamsToStreamGroupEvent..ctor
// public AddStreamsToStreamGroupEvent()
// {
// }

// 0x06000389 AspenTech.AspenPlus.Infrastructure.Events.RemoveStreamsFromStreamGroupEventArgs..ctor
// public RemoveStreamsFromStreamGroupEventArgs()
// {
// }

// 0x0600038a AspenTech.AspenPlus.Infrastructure.Events.RemoveStreamsFromStreamGroupEvent..ctor
// public RemoveStreamsFromStreamGroupEvent()
// {
// }

// 0x0600038b AspenTech.AspenPlus.Infrastructure.Events.UpdateStreamSummaryFormRibbonStatusEventArgs..ctor
// public UpdateStreamSummaryFormRibbonStatusEventArgs()
// {
// }

// 0x0600038c AspenTech.AspenPlus.Infrastructure.Events.UpdateStreamSummaryFormRibbonStatusEvent..ctor
// public UpdateStreamSummaryFormRibbonStatusEvent()
// {
// }

// 0x060003a3 AspenTech.AspenPlus.Infrastructure.Events.ActiveModeChangedEventArg..ctor
// public ActiveModeChangedEventArg()
// {
// }

// 0x060003a4 AspenTech.AspenPlus.Infrastructure.Events.ActiveModeChangedEvent..ctor
// public ActiveModeChangedEvent()
// {
// }

// 0x060003a7 AspenTech.AspenPlus.Infrastructure.Events.CancelOpenDocumentEventArgs..ctor
// public CancelOpenDocumentEventArgs()
// {
// }

// 0x060003a8 AspenTech.AspenPlus.Infrastructure.Events.CancelOpenDocumentEvent..ctor
// public CancelOpenDocumentEvent()
// {
// }

// 0x060003b0 AspenTech.AspenPlus.Infrastructure.Events.CustomFormRenameEvent..ctor
// public CustomFormRenameEvent()
// {
// }

// 0x060003b6 AspenTech.AspenPlus.Infrastructure.Events.CustomFormDeleteEvent..ctor
// public CustomFormDeleteEvent()
// {
// }

// 0x060003bc AspenTech.AspenPlus.Infrastructure.Events.CustomFormLayoutChangedEvent..ctor
// public CustomFormLayoutChangedEvent()
// {
// }

// 0x060003c2 AspenTech.AspenPlus.Infrastructure.Events.CustomFormUpdateDataEvent..ctor
// public CustomFormUpdateDataEvent()
// {
// }

// 0x060003d0 AspenTech.AspenPlus.Infrastructure.Events.CustomFormFirstColumnUpdateDataEvent..ctor
// public CustomFormFirstColumnUpdateDataEvent()
// {
// }

// 0x060003de AspenTech.AspenPlus.Infrastructure.Events.CustomFormPathColumnUpdateDataEvent..ctor
// public CustomFormPathColumnUpdateDataEvent()
// {
// }

// 0x060003e4 AspenTech.AspenPlus.Infrastructure.Events.QueryCustomTableFormPartEvent..ctor
// public QueryCustomTableFormPartEvent()
// {
// }

// 0x060003e5 AspenTech.AspenPlus.Infrastructure.Events.PFSEmbeddedCustomTableStoreValueEventArgs..ctor
// public PFSEmbeddedCustomTableStoreValueEventArgs()
// {
// }

// 0x060003e6 AspenTech.AspenPlus.Infrastructure.Events.PFSEmbeddedCustomTableStoreValueEvent..ctor
// public PFSEmbeddedCustomTableStoreValueEvent()
// {
// }

// 0x060003f0 AspenTech.AspenPlus.Infrastructure.Events.CustomFormPlaceOnFlowsheetEvent..ctor
// public CustomFormPlaceOnFlowsheetEvent()
// {
// }

// 0x060003fa AspenTech.AspenPlus.Infrastructure.Events.StreamSummaryFormPlaceOnFlowsheetEvent..ctor
// public StreamSummaryFormPlaceOnFlowsheetEvent()
// {
// }

// 0x060003fe AspenTech.AspenPlus.Infrastructure.Events.StreamSummaryFormLayoutChangedEvent..ctor
// public StreamSummaryFormLayoutChangedEvent()
// {
// }

// 0x06000404 AspenTech.AspenPlus.Infrastructure.Events.EmbeddedWPFFormDataChangedEvent..ctor
// public EmbeddedWPFFormDataChangedEvent()
// {
// }

// 0x06000407 AspenTech.AspenPlus.Infrastructure.Events.EvaluateScopeEventArgs..ctor
// public EvaluateScopeEventArgs()
// {
// }

// 0x0600040f AspenTech.AspenPlus.Infrastructure.Events.FlowsheetCustomPropSetChangedEventArgs..ctor
// public FlowsheetCustomPropSetChangedEventArgs()
// {
// }

// 0x06000410 AspenTech.AspenPlus.Infrastructure.Events.FlowsheetCustomPropSetChangedEvent..ctor
// public FlowsheetCustomPropSetChangedEvent()
// {
// }

// 0x06000411 AspenTech.AspenPlus.Infrastructure.Events.SizeScopeEventArgs..ctor
// public SizeScopeEventArgs()
// {
// }

// 0x0600041c AspenTech.AspenPlus.Infrastructure.Events.TDEConsistencyCheckEvent..ctor
// public TDEConsistencyCheckEvent()
// {
// }

// 0x06000420 AspenTech.AspenPlus.Infrastructure.Events.FlowsheetScreenCloseEvent..ctor
// public FlowsheetScreenCloseEvent()
// {
// }

// 0x06000426 AspenTech.AspenPlus.Infrastructure.Events.HierarchyBlockRenameEvent..ctor
// public HierarchyBlockRenameEvent()
// {
// }

// 0x06000427 AspenTech.AspenPlus.Infrastructure.Events.EOVariableImportedEventArgs..ctor
// public EOVariableImportedEventArgs()
// {
// }

// 0x06000428 AspenTech.AspenPlus.Infrastructure.Events.EOVariableImportedEvent..ctor
// public EOVariableImportedEvent()
// {
// }

// 0x0600042c AspenTech.AspenPlus.Infrastructure.Events.NavigateTreeNodeActivateOrDeactivateEvent..ctor
// public NavigateTreeNodeActivateOrDeactivateEvent()
// {
// }

// 0x0600042d AspenTech.AspenPlus.Infrastructure.Events.FlowsheetOptionChangedEventArgs..ctor
// public FlowsheetOptionChangedEventArgs()
// {
// }

// 0x0600042e AspenTech.AspenPlus.Infrastructure.Events.FlowsheetOptionChangedEvent..ctor
// public FlowsheetOptionChangedEvent()
// {
// }

// 0x06000430 AspenTech.AspenPlus.Infrastructure.Events.StreamTablePrintEventArgs..ctor
// public StreamTablePrintEventArgs()
// {
// }

// 0x06000431 AspenTech.AspenPlus.Infrastructure.Events.StreamTablePrintEvent..ctor
// public StreamTablePrintEvent()
// {
// }

// 0x06000432 AspenTech.AspenPlus.Infrastructure.Events.PFSContextMenuClosedEventArgs..ctor
// public PFSContextMenuClosedEventArgs()
// {
// }

// 0x06000433 AspenTech.AspenPlus.Infrastructure.Events.PFSContextMenuClosedEvent..ctor
// public PFSContextMenuClosedEvent()
// {
// }

// 0x06000440 AspenTech.AspenPlus.Infrastructure.Events.GridSettingsChangedEventArgs..ctor
// public GridSettingsChangedEventArgs()
// {
// }

// 0x06000441 AspenTech.AspenPlus.Infrastructure.Events.GridSettingsChangedEvent..ctor
// public GridSettingsChangedEvent()
// {
// }

// 0x06000442 AspenTech.AspenPlus.Infrastructure.Events.MaterialStreamDefaultLineStyleChangedEventArgs..ctor
// public MaterialStreamDefaultLineStyleChangedEventArgs()
// {
// }

// 0x06000443 AspenTech.AspenPlus.Infrastructure.Events.MaterialStreamDefaultLineStyleChangedEvent..ctor
// public MaterialStreamDefaultLineStyleChangedEvent()
// {
// }

// 0x06000447 AspenTech.AspenPlus.Infrastructure.Events.RetrieveUndoRedoDataEvent..ctor
// public RetrieveUndoRedoDataEvent()
// {
// }

// 0x0600044b AspenTech.AspenPlus.Infrastructure.Events.DoActiveOrDeactiveModelEvent..ctor
// public DoActiveOrDeactiveModelEvent()
// {
// }

// 0x06000453 AspenTech.AspenPlus.Infrastructure.Events.FlowsheetControlUndoRedoEvent..ctor
// public FlowsheetControlUndoRedoEvent()
// {
// }

// 0x0600045d AspenTech.AspenPlus.Infrastructure.Events.FlowsheetControlUndoRedoExecuteEvent..ctor
// public FlowsheetControlUndoRedoExecuteEvent()
// {
// }

// 0x06000465 AspenTech.AspenPlus.Infrastructure.Events.ObjectDeleteEvent..ctor
// public ObjectDeleteEvent()
// {
// }

// 0x06000471 AspenTech.AspenPlus.Infrastructure.Events.ObjectRenameEvent..ctor
// public ObjectRenameEvent()
// {
// }

// 0x06000475 AspenTech.AspenPlus.Infrastructure.Events.LockFlowsheetEvent..ctor
// public LockFlowsheetEvent()
// {
// }

// 0x0600047d AspenTech.AspenPlus.Infrastructure.Events.ModelLibraryUndoRedoEvent..ctor
// public ModelLibraryUndoRedoEvent()
// {
// }

// 0x06000487 AspenTech.AspenPlus.Infrastructure.Events.ModelLibraryUndoRedoExecuteEvent..ctor
// public ModelLibraryUndoRedoExecuteEvent()
// {
// }

// 0x06000488 AspenTech.AspenPlus.Infrastructure.Events.CostingStatusUpdatedEvent..ctor
// public CostingStatusUpdatedEvent()
// {
// }

// 0x06000489 AspenTech.AspenPlus.Infrastructure.Events.RequestSaveDataShareEvent..ctor
// public RequestSaveDataShareEvent()
// {
// }

// 0x0600048a AspenTech.AspenPlus.Infrastructure.Events.FlowsheetCancelInsertModeEvent..ctor
// public FlowsheetCancelInsertModeEvent()
// {
// }

// 0x0600048e AspenTech.AspenPlus.Infrastructure.Events.ModelTypeWizardFinishedEvent..ctor
// public ModelTypeWizardFinishedEvent()
// {
// }

// 0x060004a2 AspenTech.AspenPlus.Infrastructure.Events.SelecetedModelTypeChangedEvent..ctor
// public SelecetedModelTypeChangedEvent()
// {
// }

// 0x060004b0 AspenTech.AspenPlus.Infrastructure.Events.NavigatorPanelTreeSelectedChangedEvent..ctor
// public NavigatorPanelTreeSelectedChangedEvent()
// {
// }

// 0x060004b1 AspenTech.AspenPlus.Infrastructure.Events.SelectedEditCategoriesChangedEventArgs..ctor
// public SelectedEditCategoriesChangedEventArgs()
// {
// }

// 0x060004b2 AspenTech.AspenPlus.Infrastructure.Events.SelectedEditCategoriesChangedEvent..ctor
// public SelectedEditCategoriesChangedEvent()
// {
// }

// 0x060004b3 AspenTech.AspenPlus.Infrastructure.Events.SelectedModelLibrariesChangedEventArgs..ctor
// public SelectedModelLibrariesChangedEventArgs()
// {
// }

// 0x060004b4 AspenTech.AspenPlus.Infrastructure.Events.SelectedModelLibrariesChangedEvent..ctor
// public SelectedModelLibrariesChangedEvent()
// {
// }

// 0x060004b9 AspenTech.AspenPlus.Infrastructure.Events.SetDocumentDirtyEventArg..ctor
// public SetDocumentDirtyEventArg()
// {
// }

// 0x060004ba AspenTech.AspenPlus.Infrastructure.Events.SetDocumentDirtyEvent..ctor
// public SetDocumentDirtyEvent()
// {
// }

// 0x060004bb AspenTech.AspenPlus.Infrastructure.Events.SetDocumentOpenedEventArg..ctor
// public SetDocumentOpenedEventArg()
// {
// }

// 0x060004bc AspenTech.AspenPlus.Infrastructure.Events.SetDocumentOpenedEvent..ctor
// public SetDocumentOpenedEvent()
// {
// }

// 0x060004bd AspenTech.AspenPlus.Infrastructure.Events.UpdateModelPaletteEvent..ctor
// public UpdateModelPaletteEvent()
// {
// }

// 0x060004be AspenTech.AspenPlus.Infrastructure.Events.RefreshModelPaletteEvent..ctor
// public RefreshModelPaletteEvent()
// {
// }

// 0x060004bf AspenTech.AspenPlus.Infrastructure.Events.RefreshACMModelManagerEvent..ctor
// public RefreshACMModelManagerEvent()
// {
// }

// 0x060004c5 AspenTech.AspenPlus.Infrastructure.Events.UserModelLibraryUpdatedEvent..ctor
// public UserModelLibraryUpdatedEvent()
// {
// }

// 0x060004cd AspenTech.AspenPlus.Infrastructure.Events.ViewFilterChangedEvent..ctor
// public ViewFilterChangedEvent()
// {
// }

// 0x060004da AspenTech.AspenPlus.Infrastructure.Events.NavigateToEventArgs..ctor
// public NavigateToEventArgs()
// {
// }

// 0x060004e0 AspenTech.AspenPlus.Infrastructure.Events.NavigateToResultSummaryEquipmentTabEventArgs..ctor
// public NavigateToResultSummaryEquipmentTabEventArgs()
// {
// }

// 0x060004e1 AspenTech.AspenPlus.Infrastructure.Events.NavigateToResultSummaryEquipmentTabEvent..ctor
// public NavigateToResultSummaryEquipmentTabEvent()
// {
// }

// 0x060004e4 AspenTech.AspenPlus.Infrastructure.Events.ObjectChangedEventArgs..ctor
// public ObjectChangedEventArgs()
// {
// }

// 0x060004e5 AspenTech.AspenPlus.Infrastructure.Events.ObjectChangedEvent..ctor
// public ObjectChangedEvent()
// {
// }

// 0x060004ee AspenTech.AspenPlus.Infrastructure.Events.ObjectSelectedEventArgs..ctor
// public ObjectSelectedEventArgs()
// {
// }

// 0x06000506 AspenTech.AspenPlus.Infrastructure.Events.ShowFormEvent..ctor
// public ShowFormEvent()
// {
// }

// 0x0600052a AspenTech.AspenPlus.Infrastructure.AsyncDelegateCommand`1+<Execute>d__8.MoveNext
// using System;
// using System.Runtime.CompilerServices;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	AsyncDelegateCommand<T> asyncDelegateCommand = <>4__this;
// 	try
// 	{
// 		TaskAwaiter awaiter;
// 		if (num != 0)
// 		{
// 			awaiter = asyncDelegateCommand.executeAsyncMethod((T)parameter).GetAwaiter();
// 			if (!awaiter.IsCompleted)
// 			{
// 				num = (<>1__state = 0);
// 				<>u__1 = awaiter;
// 				<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 				return;
// 			}
// 		}
// 		else
// 		{
// 			awaiter = <>u__1;
// 			<>u__1 = default(TaskAwaiter);
// 			num = (<>1__state = -1);
// 		}
// 		awaiter.GetResult();
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x0600052b AspenTech.AspenPlus.Infrastructure.AsyncDelegateCommand`1+<Execute>d__8.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x0600052c AspenTech.AspenPlus.Infrastructure.AttachedProperties+<>c__DisplayClass3_0..ctor
// public <>c__DisplayClass3_0()
// {
// }

// 0x0600052e AspenTech.AspenPlus.Infrastructure.RibbonEmbedHelper+<>c__DisplayClass1_0..ctor
// public <>c__DisplayClass1_0()
// {
// }

// 0x06000531 AspenTech.AspenPlus.Infrastructure.RibbonEmbedHelper+<>c__DisplayClass4_0..ctor
// public <>c__DisplayClass4_0()
// {
// }

// 0x06000533 AspenTech.AspenPlus.Infrastructure.ParametricData+<>c__DisplayClass6_0..ctor
// public <>c__DisplayClass6_0()
// {
// }

// 0x06000535 AspenTech.AspenPlus.Infrastructure.MMMessageBox+<>c__DisplayClass40_0..ctor
// public <>c__DisplayClass40_0()
// {
// }

// 0x0600053d AspenTech.AspenPlus.Infrastructure.RibbonToolExtensions+ProxyCommand.add_CanExecuteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanExecuteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanExecuteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x0600053e AspenTech.AspenPlus.Infrastructure.RibbonToolExtensions+ProxyCommand.remove_CanExecuteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanExecuteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanExecuteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000546 AspenTech.AspenPlus.Infrastructure.ShellSettingsSerializer+FileRootSettings..ctor
// public FileRootSettings()
// {
// }

// 0x06000547 AspenTech.AspenPlus.Infrastructure.ShellSettingsSerializer+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000548 AspenTech.AspenPlus.Infrastructure.ShellSettingsSerializer+<>c..ctor
// public <>c()
// {
// }

// 0x0600054b AspenTech.AspenPlus.Infrastructure.ShellSettingsSerializer+<>c__DisplayClass4_0..ctor
// public <>c__DisplayClass4_0()
// {
// }

// 0x0600056f AspenTech.AspenPlus.Infrastructure.SimulationEventNotification+InternalSimulationNotifier..ctor
// using System.Collections.Generic;
//
// public InternalSimulationNotifier()
// {
// 	_updateQueues = new List<UpdateOption>();
// 	base..ctor();
// }

// 0x06000571 AspenTech.AspenPlus.Infrastructure.SimulationEventNotification+<>c__20`2..cctor
// static <>c__20()
// {
// 	<>9 = new <>c__20<E, T>();
// }

// 0x06000572 AspenTech.AspenPlus.Infrastructure.SimulationEventNotification+<>c__20`2..ctor
// public <>c__20()
// {
// }

// 0x06000579 AspenTech.AspenPlus.Infrastructure.SystemEnvironment+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600057a AspenTech.AspenPlus.Infrastructure.SystemEnvironment+<>c..ctor
// public <>c()
// {
// }
