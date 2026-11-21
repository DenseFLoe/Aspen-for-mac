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
using System.Drawing.Text;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.Aosapfs;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.HybridModelUtilities;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.Properties;
using AspenTech.AspenPlus.ModelLibrary.Controls;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Visualisation.CommonShell;
using AxIconEditorAxLib;
using Infragistics.Windows.DockManager;
using Infragistics.Windows.Ribbon;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.ModelLibrary")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.ModelLibrary")]
[assembly: AssemblyCopyright("Copyright 漏 Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace XamlGeneratedNamespace
{
	[DebuggerNonUserCode]
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	[EditorBrowsable(EditorBrowsableState.Never)]
	public sealed class GeneratedInternalTypeHelper : InternalTypeHelper
	{
		protected override object CreateInstance(Type type, CultureInfo culture)
		{
			return Activator.CreateInstance(type, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.CreateInstance, null, null, culture);
		}

		protected override object GetPropertyValue(PropertyInfo propertyInfo, object target, CultureInfo culture)
		{
			return propertyInfo.GetValue(target, BindingFlags.Default, null, null, culture);
		}

		protected override void SetPropertyValue(PropertyInfo propertyInfo, object target, object value, CultureInfo culture)
		{
			propertyInfo.SetValue(target, value, BindingFlags.Default, null, null, culture);
		}

		protected override Delegate CreateDelegate(Type delegateType, object target, string handler)
		{
			return (Delegate)target.GetType().InvokeMember("_CreateDelegate", BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.InvokeMethod, null, target, new object[2] { delegateType, handler }, null);
		}

		protected override void AddEventHandler(EventInfo eventInfo, object target, Delegate handler)
		{
			eventInfo.AddEventHandler(target, handler);
		}
	}
}
namespace AspenTech.AspenPlus.ModelLibrary
{
	public class HybridModelManagerDialog : Window, IComponentConnector, IStyleConnector
	{
		private const int GWL_STYLE = -16;

		private const int WS_MINIMIZEBOX = 131072;

		private IntPtr _windowHandle;

		private string m_designPath = "C:\\ProgramData\\AspenTech\\HybridModels";

		private string m_installationPath;

		private bool bfTime;

		private string m_downloadsPath = "";

		private string m_deleteFolder = "DeletedHybridModels";

		private string m_deletedFolderPath = "";

		private ModelLibraryManager hlm = new ModelLibraryManager();

		private IEventAggregator m_eventAggregator;

		internal System.Windows.Controls.Label AvailableHModels;

		internal System.Windows.Controls.Button buttonUpdateModel;

		internal System.Windows.Controls.Button buttonRemoveModel;

		internal System.Windows.Controls.DataGrid dataModelList;

		private bool _contentLoaded;

		[DllImport("mmg.dll", CharSet = CharSet.Auto, SetLastError = true)]
		public static extern IntPtr GetHybridUsedModelList();

		[DllImport("user32.dll")]
		private static extern int GetWindowLong(IntPtr hWnd, int nIndex);

		[DllImport("user32.dll")]
		private static extern int SetWindowLong(IntPtr hWnd, int nIndex, int dwNewLong);

		private void MainWindow_SourceInitialized(object sender, EventArgs e)
		{
			_windowHandle = new WindowInteropHelper(this).Handle;
			DisableMinimizeButton();
		}

		protected void DisableMinimizeButton()
		{
			if (_windowHandle == IntPtr.Zero)
			{
				throw new InvalidOperationException("The window has not yet been completely initialized");
			}
			SetWindowLong(_windowHandle, -16, GetWindowLong(_windowHandle, -16) & -131073);
		}

		public HybridModelManagerDialog(IEventAggregator eventAggregator)
		{
			m_eventAggregator = eventAggregator;
			m_eventAggregator.GetEvent<FlowsheetCancelInsertModeEvent>().Publish(new EventArgs());
			string environmentVariable = Environment.GetEnvironmentVariable("USERPROFILE");
			m_downloadsPath = environmentVariable + "\\Downloads";
			m_downloadsPath = System.IO.Path.GetFullPath(m_downloadsPath);
			m_deletedFolderPath = environmentVariable + "\\" + m_deleteFolder;
			if (!Directory.Exists(m_deletedFolderPath))
			{
				Directory.CreateDirectory(m_deletedFolderPath);
			}
			InitializeComponent();
			base.SourceInitialized += MainWindow_SourceInitialized;
			m_installationPath = hlm.installationPath;
			buttonRemoveModel.IsEnabled = false;
			dataModelList.ItemsSource = GetModelList();
		}

		public List<Data> GetModelList()
		{
			List<Data> list = new List<Data>();
			string pathToLibrary = null;
			string text = "";
			string description = "";
			bool flag = false;
			bool flag2 = false;
			hlm.GetAllModels();
			string[] hybridModelManagerDialogLine = hlm.GetHybridModelManagerDialogLine(pathToLibrary);
			string text2 = "";
			string text3 = "";
			string version = "";
			string type = "";
			string s = "";
			string[] array = hybridModelManagerDialogLine;
			for (int i = 0; i < array.Length; i++)
			{
				string[] array2 = array[i].Split(',');
				int num = array2.Count();
				for (int j = 0; j < num; j++)
				{
					text2 = array2[0];
					text3 = array2[1];
					version = array2[2];
					int num2 = Convert.ToInt32(array2[3]);
					type = array2[4];
					if (num2 > 0)
					{
						type = "Block";
					}
					s = array2[5];
					description = array2[6];
				}
				DateTime timeStamp = DateTime.Parse(s);
				if (!bfTime)
				{
					int num3 = text3.LastIndexOf('\\');
					text3.Substring(num3 + 1);
					text = timeStamp.ToString();
					if (text.Contains("1/1/0001") || text.Contains("0001/") || text.Contains("0001/1") || text.Contains("0001/1/1"))
					{
						timeStamp = File.GetLastWriteTime(text3);
					}
				}
				else
				{
					timeStamp = File.GetLastWriteTime(text3);
				}
				IList<string> blockList = new List<string>();
				int blocksUsingModelM = CMEHelper.GetBlocksUsingModelM(text2, out blockList);
				flag = blocksUsingModelM > 0;
				flag2 = blocksUsingModelM <= 0;
				list.Add(new Data
				{
					Model = text2,
					Type = type,
					Version = version,
					TimeStamp = timeStamp,
					Description = description,
					ValUse = flag,
					ValEnable = flag2
				});
			}
			return list;
		}

		private void ButtonUpdateModel_Click(object sender, RoutedEventArgs e)
		{
			Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
			string filter = "Hybrid Models Files (*.athm, *.xlp)|*.athm; *.xlp";
			openFileDialog.Filter = filter;
			openFileDialog.InitialDirectory = m_downloadsPath;
			if (openFileDialog.ShowDialog() == true)
			{
				CheckBox_Unchecked(sender, e);
				InstallModel(openFileDialog.FileName);
			}
		}

		private void InstallModel(string sFullFileName)
		{
			base.Cursor = System.Windows.Input.Cursors.Wait;
			string text = "";
			string text2 = "";
			string text3 = "";
			int num = sFullFileName.LastIndexOf('\\');
			text = sFullFileName.Substring(0, num + 1);
			text2 = sFullFileName.Replace(text, "");
			int length = text2.LastIndexOf('.');
			text3 = text2.Substring(0, length);
			int count = dataModelList.Items.Count;
			if (text3.Length > 39)
			{
				string text4 = string.Format(ModelLibraryResources.HybridModelManager3, text3) + "\n";
				string hybridModelManager = ModelLibraryResources.HybridModelManager2;
				string text5 = text4 + hybridModelManager + "\n";
				string hybridModelManager2 = ModelLibraryResources.HybridModelManager1;
				string messageBoxText = text5 + hybridModelManager2;
				string hybridModelManager3 = ModelLibraryResources.HybridModelManager4;
				System.Windows.MessageBox.Show(messageBoxText, hybridModelManager3, MessageBoxButton.OK, MessageBoxImage.Asterisk);
				base.Cursor = System.Windows.Input.Cursors.Arrow;
				return;
			}
			bool flag = true;
			bool flag2 = false;
			string text6 = "";
			string text7 = "";
			foreach (Data item in (IEnumerable)dataModelList.Items)
			{
				if (item.Model == text3)
				{
					flag = false;
					text6 = item.Version;
					break;
				}
			}
			if (flag)
			{
				text7 = m_installationPath + "\\" + text2;
				try
				{
					if (File.Exists(sFullFileName))
					{
						RemoveAttributeReadOnly(text7);
						File.Copy(sFullFileName, text7, overwrite: true);
					}
				}
				catch (Exception ex)
				{
					string text8 = ModelLibraryResources.HybridModelManager5 + " " + ex.Message + "\n";
					string text9 = string.Format(ModelLibraryResources.HybridModelManager6, m_installationPath);
					string messageBoxText2 = text8 + text9;
					string hybridModelManager4 = ModelLibraryResources.HybridModelManager7;
					System.Windows.MessageBox.Show(messageBoxText2, hybridModelManager4, MessageBoxButton.OK, MessageBoxImage.Exclamation);
					base.Cursor = System.Windows.Input.Cursors.Arrow;
					return;
				}
			}
			else
			{
				List<string> sInUseList = new List<string>();
				GetInUseList(ref sInUseList);
				int count2 = sInUseList.Count;
				bool flag3 = false;
				if (count2 > 0)
				{
					foreach (string item2 in sInUseList)
					{
						if (item2 == text3)
						{
							flag3 = true;
							break;
						}
					}
				}
				if (flag3)
				{
					string text10 = string.Format(ModelLibraryResources.HybridModelManager8, text3) + "\n";
					string hybridModelManager5 = ModelLibraryResources.HybridModelManager9;
					string text11 = text10 + hybridModelManager5 + "\n\n";
					string hybridModelManager6 = ModelLibraryResources.HybridModelManager10;
					string text12 = text11 + hybridModelManager6 + "\n";
					string hybridModelManager7 = ModelLibraryResources.HybridModelManager11;
					string messageBoxText3 = text12 + hybridModelManager7;
					string hybridModelManager8 = ModelLibraryResources.HybridModelManager12;
					System.Windows.MessageBox.Show(messageBoxText3, hybridModelManager8, MessageBoxButton.OK, MessageBoxImage.Asterisk);
					base.Cursor = System.Windows.Input.Cursors.Arrow;
					return;
				}
				string text13 = "";
				text13 = hlm.GetModelVersionFromModelBuilder(text3, text);
				if (text13 == text6)
				{
					string messageBoxText4 = string.Format(ModelLibraryResources.HybridModelManager13, text3, text6);
					string hybridModelManager9 = ModelLibraryResources.HybridModelManager12;
					System.Windows.MessageBox.Show(messageBoxText4, hybridModelManager9, MessageBoxButton.OK, MessageBoxImage.Asterisk);
					base.Cursor = System.Windows.Input.Cursors.Arrow;
					return;
				}
				string text14 = string.Format(ModelLibraryResources.HybridModelManager14, text3, text6) + "\n";
				string text15 = string.Format(ModelLibraryResources.HybridModelManager15, text13);
				string messageBoxText5 = text14 + text15;
				string hybridModelManager10 = ModelLibraryResources.HybridModelManager12;
				if (System.Windows.MessageBox.Show(messageBoxText5, hybridModelManager10, MessageBoxButton.YesNo, MessageBoxImage.Question).ToString().Contains("Yes"))
				{
					string pathToLibrary = null;
					string modelFilePath = hlm.GetModelFilePath(text3, pathToLibrary);
					text6 = text6.Replace('.', '-');
					int num2 = modelFilePath.LastIndexOf(".athm", StringComparison.OrdinalIgnoreCase);
					int num3 = modelFilePath.LastIndexOf(".xlp", StringComparison.OrdinalIgnoreCase);
					string text16 = "";
					if (num2 > 0)
					{
						text16 = text3 + "_" + text6 + ".athm";
					}
					if (num3 > 0)
					{
						text16 = text3 + "_" + text6 + ".xlp";
					}
					text7 = m_deletedFolderPath + "\\" + text16;
					try
					{
						if (File.Exists(modelFilePath))
						{
							RemoveAttributeReadOnly(text7);
							File.Copy(modelFilePath, text7, overwrite: true);
						}
					}
					catch (Exception ex2)
					{
						System.Windows.MessageBox.Show(ex2.Message, "Exception - InstallModel - File.Copy", MessageBoxButton.OK, MessageBoxImage.Exclamation);
					}
					try
					{
						if (File.Exists(sFullFileName))
						{
							RemoveAttributeReadOnly(modelFilePath);
							File.Copy(sFullFileName, modelFilePath, overwrite: true);
						}
					}
					catch (Exception ex3)
					{
						System.Windows.MessageBox.Show(ex3.Message, "Exception - InstallModel - File.Copy", MessageBoxButton.OK, MessageBoxImage.Exclamation);
					}
					flag2 = true;
				}
			}
			string modelTypeName = string.Empty;
			string pathToLibrary2 = null;
			int num4 = 0;
			if (flag || flag2)
			{
				dataModelList.ItemsSource = GetModelList();
				num4 = ((hlm.GetTypeOfModel(ref modelTypeName, text3, pathToLibrary2) == 0) ? 1 : 0);
				int count3 = dataModelList.Items.Count;
				if (count == count3 && flag)
				{
					try
					{
						if (File.Exists(text7))
						{
							RemoveAttributeReadOnly(text7);
							File.Delete(text7);
						}
					}
					catch (Exception ex4)
					{
						System.Windows.MessageBox.Show(ex4.Message, "Exception - InstallModel - File.Delete", MessageBoxButton.OK, MessageBoxImage.Exclamation);
					}
					string hybridModelManager11 = ModelLibraryResources.HybridModelManager28;
					string messageBoxText6 = string.Concat(str1: ModelLibraryResources.HybridModelManager29, str0: string.Format(hybridModelManager11, text3) + "\n");
					string hybridModelManager12 = ModelLibraryResources.HybridModelManager17;
					System.Windows.MessageBox.Show(messageBoxText6, hybridModelManager12, MessageBoxButton.OK, MessageBoxImage.Asterisk);
					base.Cursor = System.Windows.Input.Cursors.Arrow;
					return;
				}
				if (flag)
				{
					RefreshHybridModelPalette(text3, num4, 1);
				}
				if (flag2)
				{
					RefreshHybridModelPalette(string.Empty, num4, 0);
				}
				if (flag)
				{
					string messageBoxText7 = string.Format(ModelLibraryResources.HybridModelManager16, text3);
					string hybridModelManager13 = ModelLibraryResources.HybridModelManager17;
					System.Windows.MessageBox.Show(messageBoxText7, hybridModelManager13, MessageBoxButton.OK, MessageBoxImage.Asterisk);
				}
				if (flag2)
				{
					string text17 = string.Format(ModelLibraryResources.HybridModelManager18, text3) + "\n";
					string hybridModelManager14 = ModelLibraryResources.HybridModelManager19;
					string messageBoxText8 = string.Concat(text17 + hybridModelManager14 + "\n", m_deletedFolderPath);
					string hybridModelManager15 = ModelLibraryResources.HybridModelManager12;
					System.Windows.MessageBox.Show(messageBoxText8, hybridModelManager15, MessageBoxButton.OK, MessageBoxImage.Asterisk);
				}
			}
			base.Cursor = System.Windows.Input.Cursors.Arrow;
		}

		private void ButtonRemoveModel_Click(object sender, RoutedEventArgs e)
		{
			base.Cursor = System.Windows.Input.Cursors.Wait;
			List<Data> selectedItems = new List<Data>();
			foreach (Data item in (IEnumerable)dataModelList.Items)
			{
				if (item.Val)
				{
					selectedItems.Add(item);
				}
			}
			if (selectedItems.Count > 0)
			{
				string messageBoxText = ((selectedItems.Count <= 1) ? string.Format(ModelLibraryResources.HybridModelManager21, selectedItems[0].Model, selectedItems[0].Version) : string.Format(ModelLibraryResources.HybridModelManager20, selectedItems.Count));
				string hybridModelManager = ModelLibraryResources.HybridModelManager22;
				if (System.Windows.MessageBox.Show(messageBoxText, hybridModelManager, MessageBoxButton.YesNo, MessageBoxImage.Question).ToString().Contains("Yes"))
				{
					DeleteLibModel(ref selectedItems);
				}
			}
			dataModelList.ItemsSource = GetModelList();
			CheckBox_Unchecked(sender, e);
			base.Cursor = System.Windows.Input.Cursors.Arrow;
		}

		private void DeleteLibModel(ref List<Data> selectedItems)
		{
			string pathToLibrary = null;
			string value = "";
			string text = "";
			int count = selectedItems.Count;
			List<string> sInUseList = new List<string>();
			GetInUseList(ref sInUseList);
			_ = sInUseList.Count;
			List<string> list = new List<string>();
			List<string> list2 = new List<string>();
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			foreach (Data selectedItem in selectedItems)
			{
				text = selectedItem.Model;
				if (sInUseList.Contains(text))
				{
					list2.Add(text);
				}
				else
				{
					list.Add(text);
				}
			}
			int count2 = list.Count;
			_ = list2.Count;
			string text2 = "";
			if (count2 == 0)
			{
				text2 = ModelLibraryResources.HybridModelManager23 + "\n\n";
				string hybridModelManager = ModelLibraryResources.HybridModelManager24;
				text2 = text2 + hybridModelManager + "\n";
				string hybridModelManager2 = ModelLibraryResources.HybridModelManager25;
				text2 += hybridModelManager2;
				string hybridModelManager3 = ModelLibraryResources.HybridModelManager22;
				System.Windows.MessageBox.Show(text2, hybridModelManager3, MessageBoxButton.OK, MessageBoxImage.Asterisk);
			}
			else
			{
				if (count2 == count)
				{
					string hybridModelManager4 = ModelLibraryResources.HybridModelManager26;
					text2 = text2 + hybridModelManager4 + "\n";
					text2 += m_deletedFolderPath;
					string hybridModelManager5 = ModelLibraryResources.HybridModelManager22;
					System.Windows.MessageBox.Show(text2, hybridModelManager5, MessageBoxButton.OK, MessageBoxImage.Asterisk);
				}
				else if (count2 != count && count2 > 0)
				{
					text2 = ModelLibraryResources.HybridModelManager27 + "\n\n";
					foreach (string item in list)
					{
						text2 = text2 + "     " + item + "\n";
					}
					string hybridModelManager6 = ModelLibraryResources.HybridModelManager26;
					text2 = text2 + "\n" + hybridModelManager6 + "\n";
					text2 += m_deletedFolderPath;
					string hybridModelManager7 = ModelLibraryResources.HybridModelManager24;
					text2 = text2 + hybridModelManager7 + "\n";
					string hybridModelManager8 = ModelLibraryResources.HybridModelManager25;
					text2 += hybridModelManager8;
					string hybridModelManager9 = ModelLibraryResources.HybridModelManager22;
					System.Windows.MessageBox.Show(text2, hybridModelManager9, MessageBoxButton.OK, MessageBoxImage.Asterisk);
				}
				string text3 = "";
				string text4 = "";
				List<string> list3 = new List<string>();
				new List<string>();
				string text5 = "";
				foreach (string item2 in list)
				{
					foreach (Data item3 in (IEnumerable)dataModelList.Items)
					{
						if (!(item3.Model == item2))
						{
							continue;
						}
						value = hlm.GetModelFilePath(item2, pathToLibrary);
						int num = value.LastIndexOf(".athm", StringComparison.OrdinalIgnoreCase);
						int num2 = value.LastIndexOf(".xlp", StringComparison.OrdinalIgnoreCase);
						text5 = item3.Version.Replace('.', '-');
						if (num > 0)
						{
							text3 = item2 + "_" + text5 + ".athm";
						}
						if (num2 > 0)
						{
							text3 = item2 + "_" + text5 + ".xlp";
						}
						text4 = m_deletedFolderPath + "\\" + text3;
						try
						{
							if (File.Exists(value))
							{
								RemoveAttributeReadOnly(text4);
								File.Copy(value, text4, overwrite: true);
							}
						}
						catch (Exception ex)
						{
							System.Windows.MessageBox.Show(ex.Message, "Exception - DeleteLibModel - File.Copy", MessageBoxButton.OK, MessageBoxImage.Exclamation);
						}
						list3.Add(item2);
						dictionary[item2] = value;
						break;
					}
				}
				string text6 = "";
				string text7 = "";
				foreach (string item4 in list3)
				{
					string modelTypeName = string.Empty;
					int typeOfModel = hlm.GetTypeOfModel(ref modelTypeName, item4, pathToLibrary);
					if (!dictionary.TryGetValue(item4, out value))
					{
						value = hlm.GetModelFilePath(item4, pathToLibrary);
					}
					try
					{
						if (File.Exists(value))
						{
							RemoveAttributeReadOnly(value);
							File.Delete(value);
						}
					}
					catch (Exception ex2)
					{
						System.Windows.MessageBox.Show(ex2.Message, "Exception - DeleteLibModel - File.Delete", MessageBoxButton.OK, MessageBoxImage.Exclamation);
					}
					int num3 = ((typeOfModel == 0) ? 1 : 0);
					text7 = "<" + item4 + "?" + num3 + ">";
					text6 += text7;
				}
				if (!string.IsNullOrEmpty(text6))
				{
					RefreshHybridModelPalette(text6, 0, 2);
				}
			}
			if (count2 > 0)
			{
				RefreshHybridModelPalette(string.Empty, 0, 2);
			}
		}

		private bool RemoveAttributeReadOnly(string sModelPath)
		{
			bool result = false;
			if (File.Exists(sModelPath))
			{
				FileAttributes attributes = File.GetAttributes(sModelPath);
				if ((attributes & FileAttributes.ReadOnly) == FileAttributes.ReadOnly)
				{
					attributes &= ~FileAttributes.ReadOnly;
					File.SetAttributes(sModelPath, attributes);
					result = true;
				}
			}
			return result;
		}

		private int GetInUseList(ref List<string> sInUseList)
		{
			string[] source = CMEHelper.GetUsedHybridModelList().Split(',');
			sInUseList.Clear();
			sInUseList = source.ToList();
			return sInUseList.Count;
		}

		private void RefreshHybridModelPalette(string sModelName, int bSensor, int action)
		{
			if (!string.IsNullOrEmpty(sModelName))
			{
				CMEHelper.RefreshHybridModelLibrary(sModelName, bSensor, action);
			}
			if (action == 1 || (action == 2 && string.IsNullOrEmpty(sModelName)))
			{
				m_eventAggregator.GetEvent<RefreshModelPaletteEvent>().Publish(new EventArgs());
				m_eventAggregator.GetEvent<UpdateDisplayEvent>().Publish(new UpdateDisplayEventArgs());
			}
			hlm.GetAllModels();
		}

		private void CheckBox_Checked(object sender, RoutedEventArgs e)
		{
			buttonRemoveModel.IsEnabled = true;
		}

		private void CheckBox_Unchecked(object sender, RoutedEventArgs e)
		{
			foreach (Data item in (IEnumerable)dataModelList.Items)
			{
				if (item != null && item.Val)
				{
					return;
				}
			}
			buttonRemoveModel.IsEnabled = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/hybridmodelmanagerdialog.xaml", UriKind.Relative);
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
				AvailableHModels = (System.Windows.Controls.Label)target;
				break;
			case 2:
				buttonUpdateModel = (System.Windows.Controls.Button)target;
				buttonUpdateModel.Click += ButtonUpdateModel_Click;
				break;
			case 3:
				buttonRemoveModel = (System.Windows.Controls.Button)target;
				buttonRemoveModel.Click += ButtonRemoveModel_Click;
				break;
			case 4:
				dataModelList = (System.Windows.Controls.DataGrid)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 5)
			{
				((System.Windows.Controls.CheckBox)target).Checked += CheckBox_Checked;
				((System.Windows.Controls.CheckBox)target).Unchecked += CheckBox_Unchecked;
			}
		}
	}
	public class Data
	{
		private string _type;

		public bool Val { get; set; }

		public string Model { get; set; }

		public bool ValUse { get; set; }

		public string Type
		{
			get
			{
				return _type;
			}
			set
			{
				_type = value;
				if (_type == "Block")
				{
					LocalizedType = ModelLibraryResources.HybridModelManagerBlockType;
				}
				else if (_type == "Sensor")
				{
					LocalizedType = ModelLibraryResources.HybridModelManagerSensorType;
				}
			}
		}

		public string Version { get; set; }

		public DateTime TimeStamp { get; set; }

		public string Description { get; set; }

		public bool ValEnable { get; set; }

		public string LocalizedType { get; private set; }
	}
	public class ModelLibraryIconEditorScreen : ApwnDocumentControl, IComponentConnector
	{
		private int _loadedTimes;

		private IAEditCategories _targetEditCategories;

		private IAModelType _targetModelType;

		private IAModelIcon _targetModelIcon;

		private const double DefaultScaleLevel = 0.01814721;

		private const double MinimumScaleLevel = 0.002;

		private const double MaximumScaleLevel = 0.5;

		private ModelLibraryIconEditorScreenContextualRibbon mIconEditorRibbon;

		private string m_strUndoItems = string.Empty;

		private string m_strRedoItems = string.Empty;

		private ICommand _zoomInCommand;

		private ICommand _zoomOutCommand;

		private Dictionary<KeyGesture, RoutedEventHandler> m_dicGests = new Dictionary<KeyGesture, RoutedEventHandler>();

		internal Grid grdIconScreen;

		internal AxIconEditorAx iconEditor;

		private bool _contentLoaded;

		public IAEditCategories TargetEditCategories
		{
			get
			{
				if (_targetEditCategories == null && base.ScreenSubject is ModelLibraryIconEditorScreenSubject modelLibraryIconEditorScreenSubject && !string.IsNullOrEmpty(modelLibraryIconEditorScreenSubject.ModelLibraryDisplayName))
				{
					_targetEditCategories = ModelLibraryHelper.GetIAEditCategories(modelLibraryIconEditorScreenSubject.ModelLibraryDisplayName);
				}
				return _targetEditCategories;
			}
		}

		public IAModelType TargetModelType
		{
			get
			{
				if (_targetModelType == null && TargetEditCategories != null)
				{
					ModelLibraryIconEditorScreenSubject modelLibraryIconEditorScreenSubject = base.ScreenSubject as ModelLibraryIconEditorScreenSubject;
					if (!string.IsNullOrEmpty(modelLibraryIconEditorScreenSubject.ModelTypeName))
					{
						_targetModelType = ModelLibraryLoader.GetUnmanagedModelType(TargetEditCategories, modelLibraryIconEditorScreenSubject.ModelTypeName);
					}
				}
				return _targetModelType;
			}
		}

		public IAModelIcon TargetModelIcon
		{
			get
			{
				if (_targetModelIcon == null && TargetModelType != null)
				{
					ModelLibraryIconEditorScreenSubject modelLibraryIconEditorScreenSubject = base.ScreenSubject as ModelLibraryIconEditorScreenSubject;
					if (!string.IsNullOrEmpty(modelLibraryIconEditorScreenSubject.IconName))
					{
						_targetModelIcon = ModelLibraryLoader.GetUnmanagedModelIcon(TargetModelType, modelLibraryIconEditorScreenSubject.IconName);
					}
				}
				return _targetModelIcon;
			}
		}

		public bool CanUndo => true;

		public bool CanRedo => true;

		public new ICommand ZoomInCommand
		{
			get
			{
				if (_zoomInCommand == null)
				{
					_zoomInCommand = new DelegateCommand<object>(ExecuteZoomInCommand, CanExecuteZoomInCommand);
				}
				return _zoomInCommand;
			}
		}

		public new ICommand ZoomOutCommand
		{
			get
			{
				if (_zoomOutCommand == null)
				{
					_zoomOutCommand = new DelegateCommand<object>(ExecuteZoomOutCommand, CanExecuteZoomOutCommand);
				}
				return _zoomOutCommand;
			}
		}

		public ModelLibraryIconEditorScreen()
		{
			InitializeComponent();
			base.ZoomMinimum = 0.03629442;
			base.ZoomMaximum = 9.073605;
			base.ZoomToFitCommand = (ICommand)new ApwnCommand(ExecuteZoomToFitCommand);
		}

		public override void OnOpening(ScreenOpeningEventArgs args)
		{
			base.OnOpening(args);
		}

		protected override void OnInitialized(EventArgs e)
		{
			mIconEditorRibbon = new ModelLibraryIconEditorScreenContextualRibbon(this);
			base.ContextualRibbons.Add(mIconEditorRibbon);
			base.Loaded += ModelLibraryIconEditorScreen_Loaded;
			base.OnInitialized(e);
		}

		private void ModelLibraryIconEditorScreen_Loaded(object sender, RoutedEventArgs e)
		{
			if (_loadedTimes == 0)
			{
				ModelLibraryIconEditorScreenSubject modelLibraryIconEditorScreenSubject = base.ScreenSubject as ModelLibraryIconEditorScreenSubject;
				if (!string.IsNullOrEmpty(modelLibraryIconEditorScreenSubject.IconName))
				{
					base.Header = string.Format(ModelLibraryResources.IconEditorScreenTitle, modelLibraryIconEditorScreenSubject.IconName);
				}
				try
				{
					iconEditor.ResetActiveCtr();
					if (TargetModelIcon == null)
					{
						(base.UnityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as CommonShellWindow).CloseScreen(this);
						return;
					}
					iconEditor.SetModelIcon(TargetModelIcon);
				}
				catch (Exception ex)
				{
					MMMessageBox.Show(ex.Message);
					return;
				}
				_loadedTimes++;
				mIconEditorRibbon.nIconFontCombo.ItemsSource = mIconEditorRibbon.IconFontNameList;
				mIconEditorRibbon.nIconSizeCombo.ItemsSource = mIconEditorRibbon.IconFontSizeList;
				iconEditor.HasSelectedObject();
				mIconEditorRibbon.GetTextAttributeSetRibbon();
				mIconEditorRibbon.bIsCreated = true;
				InitIconEvents();
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibraryUndoRedoExecuteEvent>().Subscribe(OnModelLibraryUndoRedoExecuteEvent);
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<RetrieveUndoRedoDataEvent>().Subscribe(OnRetrieveUndoRedoDataEvent);
			}
			else
			{
				iconEditor.ResetActiveCtr();
				iconEditor.HasSelectedObject();
				mIconEditorRibbon.GetTextAttributeSetRibbon();
			}
			GetUndoRedoList();
			SetContextMenuShortcutFunction();
		}

		protected override void OnGotFocus(RoutedEventArgs e)
		{
			base.OnGotFocus(e);
		}

		public void OnChangeSaved()
		{
			if (base.UnityContainer != null)
			{
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Publish(new UserModelLibraryUpdatedEventArgs(TargetEditCategories, UserModelLibraryUpdatedMode.EditCurrentIcon));
			}
		}

		protected override void OnClosing(CancelEventArgs args)
		{
			iconEditor.ResetActiveCtr();
			iconEditor.CheckSaveIcon();
			base.OnClosing(args);
		}

		protected override void OnClosed(EventArgs args)
		{
			iconEditor.Dispose();
			base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibraryUndoRedoExecuteEvent>().Unsubscribe(OnModelLibraryUndoRedoExecuteEvent);
			base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<RetrieveUndoRedoDataEvent>().Unsubscribe(OnRetrieveUndoRedoDataEvent);
			base.OnClosed(args);
		}

		private void InitIconEvents()
		{
			iconEditor.HistoryModified += icon_OnHistoryModified;
			iconEditor.ZoomChanged += iconEditor_ZoomChanged;
		}

		public void icon_OnHistoryModified(object sender, _DIconEditorAxEvents_HistoryModifiedEvent e)
		{
			GetUndoRedoList();
		}

		public void FireModelLibraryUndoRedoEvent()
		{
			base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibraryUndoRedoEvent>().Publish(new ModelLibraryUndoRedoEventArgs(m_strUndoItems, m_strRedoItems, "ModelLibraryIconEditor"));
		}

		private void GetUndoRedoList()
		{
			if (iconEditor != null)
			{
				string empty = string.Empty;
				string empty2 = string.Empty;
				empty = iconEditor.GetUndoList();
				empty2 = iconEditor.GetRedoList();
				m_strUndoItems = empty;
				m_strRedoItems = empty2;
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibraryUndoRedoEvent>().Publish(new ModelLibraryUndoRedoEventArgs(empty, empty2, "ModelLibraryIconEditor"));
			}
		}

		private void OnModelLibraryUndoRedoExecuteEvent(ModelLibraryUndoRedoExecuteEventArgs e)
		{
			if (!(e.ActiveScreen is ModelLibraryIconEditorScreen modelLibraryIconEditorScreen) || modelLibraryIconEditorScreen != this || (iconEditor != null && iconEditor.FocusInTextEdit() == 1))
			{
				return;
			}
			string stepType = e.StepType;
			if (!(stepType == "OneStep"))
			{
				if (stepType == "Steps")
				{
					if (e.ActionType == "Undo")
					{
						iconEditor.SetStepsUndo(e.CurIndex);
					}
					else
					{
						iconEditor.SetStepsRedo(e.CurIndex);
					}
					GetUndoRedoList();
				}
			}
			else
			{
				if (e.ActionType == "Undo")
				{
					iconEditor.SetOneStepUndo();
				}
				else
				{
					iconEditor.SetOneStepRedo();
				}
				GetUndoRedoList();
			}
		}

		private void OnRetrieveUndoRedoDataEvent(RetrieveUndoRedoDataEventArgs e)
		{
			if (e.ActiveScreen is ModelLibraryIconEditorScreen modelLibraryIconEditorScreen && this == modelLibraryIconEditorScreen)
			{
				GetUndoRedoList();
			}
		}

		private void ExecuteZoomInCommand(object parameter)
		{
			int command = 56008;
			iconEditor.InvokeMenuItem(command);
		}

		private bool CanExecuteZoomInCommand(object arg)
		{
			return true;
		}

		private void ExecuteZoomOutCommand(object parameter)
		{
			int command = 56009;
			iconEditor.InvokeMenuItem(command);
		}

		private bool CanExecuteZoomOutCommand(object arg)
		{
			return true;
		}

		private void ExecuteZoomToFitCommand()
		{
			int command = 56010;
			iconEditor.InvokeMenuItem(command);
		}

		protected override void OnZoomChanged(double oldValue, double newValue)
		{
			if (oldValue > 0.0 && newValue > 0.0)
			{
				double num = 0.01814721 / newValue;
				iconEditor.ZoomToScale((float)num);
			}
			base.OnZoomChanged(oldValue, newValue);
		}

		private void iconEditor_ZoomChanged(object sender, _DIconEditorAxEvents_ZoomChangedEvent e)
		{
			base.Zoom = 0.01814721 / (double)e.newScale;
		}

		private void SetContextMenuShortcutFunction()
		{
			m_dicGests.Clear();
			m_dicGests.Add(new KeyGesture(Key.Up, ModifierKeys.Control), OnShortCutZoomIn);
			m_dicGests.Add(new KeyGesture(Key.Down, ModifierKeys.Control), OnShortCutZoomOut);
			m_dicGests.Add(new KeyGesture(Key.C, ModifierKeys.Control), ContextMenuCopy);
			m_dicGests.Add(new KeyGesture(Key.V, ModifierKeys.Control), ContextMenuPaste);
			m_dicGests.Add(new KeyGesture(Key.X, ModifierKeys.Control), ContextMenuCut);
			m_dicGests.Add(new KeyGesture(Key.P, ModifierKeys.Control), ContextMenuPrint);
			m_dicGests.Add(new KeyGesture(Key.Delete, ModifierKeys.None), ContextMenuDelete);
		}

		private void OnShortCutZoomIn(object sender, RoutedEventArgs e)
		{
			ExecuteZoomInCommand(null);
		}

		private void OnShortCutZoomOut(object sender, RoutedEventArgs e)
		{
			ExecuteZoomOutCommand(null);
		}

		private void ContextMenuCopy(object sender, RoutedEventArgs e)
		{
			int command = 57634;
			iconEditor.InvokeMenuItem(command);
		}

		private void ContextMenuPaste(object sender, RoutedEventArgs e)
		{
			int command = 57637;
			iconEditor.InvokeMenuItem(command);
		}

		private void ContextMenuCut(object sender, RoutedEventArgs e)
		{
			int command = 57635;
			iconEditor.InvokeMenuItem(command);
		}

		private void ContextMenuPrint(object sender, RoutedEventArgs e)
		{
			int command = 57607;
			iconEditor.InvokeMenuItem(command);
		}

		private void ContextMenuDelete(object sender, RoutedEventArgs e)
		{
			int command = 57632;
			iconEditor.InvokeMenuItem(command);
		}

		protected override void OnKeyDown(System.Windows.Input.KeyEventArgs e)
		{
			if (iconEditor != null && iconEditor.FocusInTextEdit() != 1)
			{
				foreach (KeyGesture key in m_dicGests.Keys)
				{
					if (key.Matches(null, e))
					{
						m_dicGests[key](this, e);
						e.Handled = true;
					}
				}
			}
			base.OnKeyDown(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibraryiconeditorscreen.xaml", UriKind.Relative);
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
				grdIconScreen = (Grid)target;
				break;
			case 2:
				iconEditor = (AxIconEditorAx)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ModelLibraryIconEditorScreenContextualRibbon : XamRibbon, IComponentConnector, IStyleConnector
	{
		protected int iMinFontSizeR6 = 6;

		protected int iMaxFontSizeR30 = 30;

		public int iDefFontSize = 10;

		public string sDefFontName = "Tahoma";

		private string msRFontName = "";

		private int miRibFontSize;

		private int miRibFontStyle;

		private int miRibOrientation;

		private int miRibFontColor;

		private ModelLibraryIconEditorScreen _iconEditorScreen;

		private ICommand _saveCurrentIconCommand;

		private ICommand _generateScriptCommand;

		private ICommand _runScriptCommand;

		private ICommand _importDXFCommand;

		public List<SolidColorBrush> colorPickerListR = new List<SolidColorBrush>();

		public static readonly DependencyProperty TextColorItemsProperty = DependencyProperty.Register("TextColorItems", typeof(ObservableCollection<UIElement>), typeof(ModelLibraryIconEditorScreenContextualRibbon));

		internal ButtonTool SaveIconBtn;

		internal ButtonTool nText;

		internal ButtonTool nLine;

		internal ButtonTool nRectangle;

		internal ButtonTool nPolygon;

		internal ButtonTool nPolyline;

		internal ButtonTool nEllipse;

		internal ButtonTool nSemi_Ellipse;

		internal ButtonTool nArrow;

		internal ButtonTool nDoubleArrow;

		internal MenuTool nFillI;

		internal ToolMenuItem TMIFillColorPicker;

		internal ToolMenuItem nFillNoFill;

		internal ToolMenuItem nTMIFillNoFill;

		internal MenuTool MTLine;

		internal ToolMenuItem TMIColorPicker;

		internal MenuTool MTType;

		internal ComboEditorTool nIconFontCombo;

		internal ButtonGroup buttonGroupFonts;

		internal ToggleButtonTool BoldR;

		internal ToggleButtonTool ItalicR;

		internal ToggleButtonTool UnderScoreR;

		internal ButtonTool bEnargeFontR;

		internal ButtonTool bShrinkFontR;

		internal ComboEditorTool nIconSizeCombo;

		internal LabelTool lblTextColorR;

		internal MenuTool nFontColor;

		internal ToolMenuItem TMITextColorPicker1;

		internal ButtonTool RotateBtn;

		internal ButtonTool FlipLRBtn;

		internal ButtonTool FlipUDBtn;

		internal ToggleButtonTool GridBtn;

		internal ToggleButtonTool SnapBtn;

		internal ComboEditorTool GridCombo;

		private bool _contentLoaded;

		public bool bIsCreated { get; set; }

		public List<string> IconFontNameList { get; private set; }

		public List<string> IconFontSizeList { get; private set; }

		public ICommand SaveCurrentIconCommand
		{
			get
			{
				if (_saveCurrentIconCommand == null)
				{
					_saveCurrentIconCommand = new DelegateCommand<object>(SaveCurrentIcon_Executed, SaveCurrentIcon_CanExecute);
				}
				return _saveCurrentIconCommand;
			}
		}

		public ICommand GenerateScriptCommand
		{
			get
			{
				if (_generateScriptCommand == null)
				{
					_generateScriptCommand = new DelegateCommand<object>(GenerateScript_Executed, GenerateScript_CanExecute);
				}
				return _generateScriptCommand;
			}
		}

		public ICommand RunScriptCommand
		{
			get
			{
				if (_runScriptCommand == null)
				{
					_runScriptCommand = new DelegateCommand<object>(RunScript_Executed, RunScript_CanExecte);
				}
				return _runScriptCommand;
			}
		}

		public ICommand ImportDXFCommand
		{
			get
			{
				if (_importDXFCommand == null)
				{
					_importDXFCommand = new DelegateCommand<object>(ImportDXF_Executed, ImportDXF_CanExecte);
				}
				return _importDXFCommand;
			}
		}

		public ObservableCollection<UIElement> TextColorItems
		{
			get
			{
				return (ObservableCollection<UIElement>)((DependencyObject)(object)this).GetValue(TextColorItemsProperty);
			}
			set
			{
				((DependencyObject)(object)this).SetValue(TextColorItemsProperty, (object)value);
			}
		}

		private void CreateFontNameList()
		{
			if (IconFontNameList == null)
			{
				IconFontNameList = new List<string>();
			}
			IconFontNameList.Clear();
			System.Drawing.FontFamily[] families = new InstalledFontCollection().Families;
			foreach (System.Drawing.FontFamily fontFamily in families)
			{
				IconFontNameList.Add(fontFamily.Name);
			}
		}

		private void CreateFontizeList()
		{
			if (IconFontSizeList == null)
			{
				IconFontSizeList = new List<string>();
			}
			IconFontSizeList.Clear();
			for (int i = iMinFontSizeR6; i <= iMaxFontSizeR30; i++)
			{
				IconFontSizeList.Add(i.ToString());
			}
		}

		public void InitIconIvents()
		{
			_iconEditorScreen.iconEditor.Selected += icon_OnSelectedObj;
			_iconEditorScreen.iconEditor.HistoryModified += icon_OnHistoryModified;
			_iconEditorScreen.iconEditor.IconModified += icon_OnIconModified;
		}

		public void icon_OnSelectedObj(object sender, _DIconEditorAxEvents_SelectedEvent e)
		{
			GetTextAttributeSetRibbon();
		}

		public void icon_OnHistoryModified(object sender, _DIconEditorAxEvents_HistoryModifiedEvent e)
		{
		}

		public void icon_OnIconModified(object sender, _DIconEditorAxEvents_IconModifiedEvent e)
		{
			if (e.objectId == 1)
			{
				SaveIconBtn.IsEnabled = true;
			}
			else
			{
				SaveIconBtn.IsEnabled = false;
			}
		}

		public ModelLibraryIconEditorScreenContextualRibbon(ModelLibraryIconEditorScreen iconEditorScreen)
		{
			InitializeComponent();
			((FrameworkElement)(object)this).Loaded += ModelLibraryIconEditorScreenContextualRibbon_Loaded;
			_iconEditorScreen = iconEditorScreen;
			CreateFontNameList();
			CreateFontizeList();
			InitIconIvents();
			SetTextColorPicker();
			CreateColorPickerListR();
			bIsCreated = false;
		}

		private void ModelLibraryIconEditorScreenContextualRibbon_Loaded(object sender, RoutedEventArgs e)
		{
		}

		private void SaveCurrentIcon_Executed(object parameter)
		{
			if (_iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.SaveCurrentIcon();
				_iconEditorScreen.OnChangeSaved();
			}
		}

		private bool SaveCurrentIcon_CanExecute(object parameter)
		{
			return true;
		}

		private void GenerateScript_Executed(object parameter)
		{
			if (_iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.GenerateScript();
			}
		}

		private bool GenerateScript_CanExecute(object parameter)
		{
			return true;
		}

		private void RunScript_Executed(object parameter)
		{
			if (_iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.RunScript();
			}
		}

		private bool RunScript_CanExecte(object parameter)
		{
			return false;
		}

		private void ImportDXF_Executed(object parameter)
		{
			if (_iconEditorScreen != null)
			{
				System.Windows.Forms.OpenFileDialog openFileDialog = new System.Windows.Forms.OpenFileDialog();
				openFileDialog.RestoreDirectory = true;
				openFileDialog.Filter = ApwnResources.FileType_Aspen_Plus_Document + " (*.apw)|*.txt|" + ApwnResources.FileType_All_Files + " (*.*)|*.*";
				openFileDialog.DefaultExt = "dxf";
				openFileDialog.CheckFileExists = true;
				if (openFileDialog.ShowDialog() == DialogResult.OK)
				{
					_iconEditorScreen.iconEditor.ImportDXF(openFileDialog.FileName);
				}
			}
		}

		private bool ImportDXF_CanExecte(object parameter)
		{
			return false;
		}

		private void nText_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(0);
			}
		}

		private void nLine_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(1);
			}
		}

		private void nRectangle_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(2);
			}
		}

		private void nPolygon_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(3);
			}
		}

		private void nPolyline_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(4);
			}
		}

		private void nEllipse_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(5);
			}
		}

		private void nSemi_Ellipse_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(6);
			}
		}

		private void nArrow_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(7);
			}
		}

		private void nDoubleArrow_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.DrawObject(8);
			}
		}

		private int MapFromIconToColorPicker(int iIconIndex)
		{
			int result = iIconIndex;
			if (iIconIndex == 15)
			{
				result = -1;
			}
			if (iIconIndex == 16)
			{
				result = 15;
			}
			return result;
		}

		private int MapFromColorPickerToIcon(int iPickerIndex)
		{
			int result = iPickerIndex;
			if (iPickerIndex == 15)
			{
				result = 16;
			}
			return result;
		}

		private void CreateColorPickerListR()
		{
			SolidColorBrush item = new SolidColorBrush(Colors.Black);
			colorPickerListR.Add(item);
			SolidColorBrush item2 = new SolidColorBrush(Colors.Navy);
			colorPickerListR.Add(item2);
			SolidColorBrush item3 = new SolidColorBrush(Colors.Green);
			colorPickerListR.Add(item3);
			SolidColorBrush item4 = new SolidColorBrush(Colors.Teal);
			colorPickerListR.Add(item4);
			SolidColorBrush item5 = new SolidColorBrush(Colors.Maroon);
			colorPickerListR.Add(item5);
			SolidColorBrush item6 = new SolidColorBrush(Colors.Purple);
			colorPickerListR.Add(item6);
			SolidColorBrush item7 = new SolidColorBrush(Colors.Olive);
			colorPickerListR.Add(item7);
			SolidColorBrush item8 = new SolidColorBrush(Colors.Silver);
			colorPickerListR.Add(item8);
			SolidColorBrush item9 = new SolidColorBrush(Colors.Gray);
			colorPickerListR.Add(item9);
			SolidColorBrush item10 = new SolidColorBrush(System.Windows.Media.Color.FromRgb(0, 128, byte.MaxValue));
			colorPickerListR.Add(item10);
			SolidColorBrush item11 = new SolidColorBrush(Colors.Lime);
			colorPickerListR.Add(item11);
			SolidColorBrush item12 = new SolidColorBrush(Colors.Cyan);
			colorPickerListR.Add(item12);
			SolidColorBrush item13 = new SolidColorBrush(Colors.Red);
			colorPickerListR.Add(item13);
			SolidColorBrush item14 = new SolidColorBrush(Colors.Magenta);
			colorPickerListR.Add(item14);
			SolidColorBrush item15 = new SolidColorBrush(Colors.Yellow);
			colorPickerListR.Add(item15);
			SolidColorBrush item16 = new SolidColorBrush(System.Windows.Media.Color.FromRgb(224, 224, 224));
			colorPickerListR.Add(item16);
		}

		public void GetTextAttributeSetRibbon()
		{
			int isize = 0;
			int istyle = 0;
			int icolor = 0;
			int iorientation = 0;
			string sfontname = "";
			_iconEditorScreen.iconEditor.GetTextAttribute(ref sfontname, ref isize, ref istyle, ref iorientation, ref icolor);
			msRFontName = sfontname;
			miRibFontSize = isize;
			miRibFontStyle = istyle;
			miRibOrientation = iorientation;
			miRibFontColor = icolor;
			short num = (short)(istyle & 2);
			short num2 = (short)(istyle & 1);
			short num3 = (short)(istyle & 4);
			if (num != 0)
			{
				BoldR.IsChecked = true;
			}
			else
			{
				BoldR.IsChecked = false;
			}
			if (num2 != 0)
			{
				ItalicR.IsChecked = true;
			}
			else
			{
				ItalicR.IsChecked = false;
			}
			if (num3 != 0)
			{
				UnderScoreR.IsChecked = true;
			}
			else
			{
				UnderScoreR.IsChecked = false;
			}
			bool flag = false;
			if (isize < iMinFontSizeR6)
			{
				isize = iMinFontSizeR6;
				flag = true;
			}
			if (isize > iMaxFontSizeR30)
			{
				isize = iMaxFontSizeR30;
				flag = true;
			}
			if (flag)
			{
				miRibFontSize = isize;
				_iconEditorScreen.iconEditor.SetTextAttribute(sfontname, miRibFontSize, istyle, iorientation, icolor, 1);
			}
			SetEnargeShrinkFontbtns();
			nIconSizeCombo.Value = isize.ToString();
			if (IconFontNameList.IndexOf(sfontname) >= 0)
			{
				nIconFontCombo.Value = sfontname;
			}
			else
			{
				string value = (msRFontName = sDefFontName);
				nIconFontCombo.Value = value;
				_iconEditorScreen.iconEditor.SetTextAttribute(msRFontName, miRibFontSize, istyle, iorientation, icolor, 0);
			}
			InitializedTextColor();
			InitializedLineColor();
			InitializedFillColor();
			short rotateEnabled = _iconEditorScreen.iconEditor.GetRotateEnabled();
			if (_iconEditorScreen.iconEditor.HasSelectedObject() == 0 || rotateEnabled == 0)
			{
				RotateBtn.IsEnabled = false;
				FlipLRBtn.IsEnabled = false;
				FlipUDBtn.IsEnabled = false;
			}
			else
			{
				RotateBtn.IsEnabled = true;
				FlipLRBtn.IsEnabled = true;
				FlipUDBtn.IsEnabled = true;
			}
			if (_iconEditorScreen.iconEditor.GetSnap() == 1)
			{
				SnapBtn.IsChecked = true;
			}
			else
			{
				SnapBtn.IsChecked = false;
			}
			if (_iconEditorScreen.iconEditor.GetGrid() == 1)
			{
				GridBtn.IsChecked = true;
			}
			else
			{
				GridBtn.IsChecked = false;
			}
			GridCombo.Value = _iconEditorScreen.iconEditor.GetGridSizeIndex();
			if (_iconEditorScreen.iconEditor.GetIconModified() == 1)
			{
				SaveIconBtn.IsEnabled = true;
			}
			else
			{
				SaveIconBtn.IsEnabled = false;
			}
		}

		private void SetChageForFontNotcolor(int ifSel)
		{
			int num = 0;
			int num2 = 0;
			string text = "";
			text = nIconFontCombo.DisplayText;
			num = Convert.ToInt32(nIconSizeCombo.DisplayText);
			if (BoldR.IsChecked == true)
			{
				num2 |= 2;
			}
			if (ItalicR.IsChecked == true)
			{
				num2 |= 1;
			}
			if (UnderScoreR.IsChecked == true)
			{
				num2 |= 4;
			}
			msRFontName = text;
			miRibFontSize = num;
			miRibFontStyle = num2;
			_iconEditorScreen.iconEditor.SetTextAttribute(msRFontName, miRibFontSize, miRibFontStyle, miRibOrientation, miRibFontColor, ifSel);
		}

		private void nIconFontCombo_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				SetChageForFontNotcolor(0);
			}
		}

		private void nIconSizeCombo_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (bIsCreated)
			{
				if (_iconEditorScreen != null)
				{
					SetChageForFontNotcolor(1);
				}
				SetEnargeShrinkFontbtns();
			}
		}

		private void BoldR_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				SetChageForFontNotcolor(0);
			}
		}

		private void ItalicR_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				SetChageForFontNotcolor(0);
			}
		}

		private void UnderScoreR_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				SetChageForFontNotcolor(0);
			}
		}

		private void SetEnargeShrinkFontbtns()
		{
			bEnargeFontR.IsEnabled = true;
			bShrinkFontR.IsEnabled = true;
			if (miRibFontSize == iMaxFontSizeR30)
			{
				bEnargeFontR.IsEnabled = false;
			}
			if (miRibFontSize == iMinFontSizeR6)
			{
				bShrinkFontR.IsEnabled = false;
			}
		}

		private void bEnargeFontR_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				int num = Convert.ToInt32(nIconSizeCombo.DisplayText);
				num++;
				if (num <= iMaxFontSizeR30)
				{
					nIconSizeCombo.Value = num.ToString();
					miRibFontSize = num;
					SetChageForFontNotcolor(1);
				}
				SetEnargeShrinkFontbtns();
			}
		}

		private void bShrinkFontR_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				int num = Convert.ToInt32(nIconSizeCombo.DisplayText);
				num--;
				if (num >= iMinFontSizeR6)
				{
					nIconSizeCombo.Value = num.ToString();
					miRibFontSize = num;
					SetChageForFontNotcolor(1);
				}
				SetEnargeShrinkFontbtns();
			}
		}

		public void SetTextColorPicker()
		{
			TextColorItems = new ObservableCollection<UIElement>();
			ComboBoxItem comboBoxItem = new ComboBoxItem();
			comboBoxItem.Content = new TextColorPicker
			{
				Name = "UserControlTextColor"
			};
			TextColorItems.Add(comboBoxItem);
			new ToolMenuItem();
		}

		private void InitializedTextColor()
		{
			ToolMenuItem toolMenuItem = nFontColor.Items[0] as ToolMenuItem;
			toolMenuItem.ApplyTemplate();
			TextColorPicker textColorPicker = toolMenuItem.Template.FindName("FillColorPicker1", toolMenuItem) as TextColorPicker;
			textColorPicker.ColorSelect = MapFromIconToColorPicker(miRibFontColor);
			textColorPicker.InvalidateVisual();
			lblTextColorR.Background = colorPickerListR[textColorPicker.ColorSelect];
		}

		private void nFontColor_Opened(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				InitializedTextColor();
			}
		}

		private void TMITextColorPicker1_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				ToolMenuItem toolMenuItem = sender as ToolMenuItem;
				if (toolMenuItem.Name == "TMITextColorPicker1")
				{
					TextColorPicker textColorPicker = toolMenuItem.Template.FindName("FillColorPicker1", toolMenuItem) as TextColorPicker;
					miRibFontColor = MapFromColorPickerToIcon(textColorPicker.ColorSelect);
					lblTextColorR.Background = colorPickerListR[textColorPicker.ColorSelect];
					SetChageForFontNotcolor(2);
				}
			}
		}

		private void InitializedLineColor()
		{
			ToolMenuItem toolMenuItem = MTLine.Items[0] as ToolMenuItem;
			toolMenuItem.ApplyTemplate();
			TextColorPicker obj = toolMenuItem.Template.FindName("LineColorPicker1", toolMenuItem) as TextColorPicker;
			int objectLineColorIndex = _iconEditorScreen.iconEditor.GetObjectLineColorIndex();
			obj.ColorSelect = MapFromIconToColorPicker(objectLineColorIndex);
			obj.InvalidateVisual();
		}

		private void MTLine_Opened(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				InitializedLineColor();
			}
		}

		private void TMIColorPicker_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				ToolMenuItem toolMenuItem = sender as ToolMenuItem;
				if (toolMenuItem.Name == "TMIColorPicker")
				{
					TextColorPicker textColorPicker = toolMenuItem.Template.FindName("LineColorPicker1", toolMenuItem) as TextColorPicker;
					short objectLineColorIndex = (short)MapFromColorPickerToIcon(textColorPicker.ColorSelect);
					_iconEditorScreen.iconEditor.SetObjectLineColorIndex(objectLineColorIndex);
				}
			}
		}

		private void MTType_Opened(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				MenuTool menuTool = sender as MenuTool;
				for (int i = 0; i < 6; i++)
				{
					(menuTool.Items[i] as ToolMenuItem).Background = System.Windows.Media.Brushes.Transparent;
				}
				int objectLineTypeIndex = _iconEditorScreen.iconEditor.GetObjectLineTypeIndex();
				objectLineTypeIndex--;
				if (objectLineTypeIndex >= 0)
				{
					(menuTool.Items[objectLineTypeIndex] as ToolMenuItem).Background = System.Windows.Media.Brushes.White;
				}
			}
		}

		private void LineTypeToolMenuItem_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null && e.MouseDevice.LeftButton == MouseButtonState.Pressed)
			{
				ToolMenuItem obj = e.Source as ToolMenuItem;
				int result = 0;
				int.TryParse(obj.Tag.ToString(), out result);
				result++;
				if (result >= 1)
				{
					_iconEditorScreen.iconEditor.SetObjectLineTypeIndex((short)result);
				}
			}
		}

		private void InitializedFillColor()
		{
			ToolMenuItem toolMenuItem = nFillI.Items[0] as ToolMenuItem;
			toolMenuItem.ApplyTemplate();
			TextColorPicker obj = toolMenuItem.Template.FindName("FillColorPicker", toolMenuItem) as TextColorPicker;
			int objectFillColorIndex = _iconEditorScreen.iconEditor.GetObjectFillColorIndex();
			obj.ColorSelect = MapFromIconToColorPicker(objectFillColorIndex);
			obj.InvalidateVisual();
			short fillMode = _iconEditorScreen.iconEditor.GetFillMode();
			ToolMenuItem toolMenuItem2 = nFillI.Items[2] as ToolMenuItem;
			toolMenuItem2.ApplyTemplate();
			if (toolMenuItem2.Template.FindName("BorderNoFill", toolMenuItem2) is Border border)
			{
				CheckBoxTool checkBoxTool = border.Child as CheckBoxTool;
				checkBoxTool.IsEnabled = true;
				switch (fillMode)
				{
				case 255:
					checkBoxTool.IsEnabled = false;
					checkBoxTool.IsChecked = true;
					break;
				case 0:
					checkBoxTool.IsChecked = true;
					break;
				default:
					checkBoxTool.IsChecked = false;
					break;
				}
			}
		}

		private void nFillI_Opened(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				InitializedFillColor();
			}
		}

		private void TMIFillColorPicker_Click(object sender, RoutedEventArgs e)
		{
			if (!bIsCreated || _iconEditorScreen == null)
			{
				return;
			}
			ToolMenuItem toolMenuItem = sender as ToolMenuItem;
			if (toolMenuItem.Name == "TMIFillColorPicker")
			{
				TextColorPicker textColorPicker = toolMenuItem.Template.FindName("FillColorPicker", toolMenuItem) as TextColorPicker;
				int num = MapFromColorPickerToIcon(textColorPicker.ColorSelect);
				if (_iconEditorScreen.iconEditor.GetFillMode() == 0)
				{
					short fillMode = 1;
					_iconEditorScreen.iconEditor.SetFillMode(fillMode);
				}
				_iconEditorScreen.iconEditor.SetObjectFillColorIndex((short)num);
			}
		}

		private void nTMIFillNoFill_Click(object sender, RoutedEventArgs e)
		{
			if (!bIsCreated || _iconEditorScreen == null)
			{
				return;
			}
			ToolMenuItem toolMenuItem = nFillI.Items[0] as ToolMenuItem;
			toolMenuItem.ApplyTemplate();
			TextColorPicker textColorPicker = toolMenuItem.Template.FindName("FillColorPicker", toolMenuItem) as TextColorPicker;
			int num = MapFromColorPickerToIcon(textColorPicker.ColorSelect);
			ToolMenuItem toolMenuItem2 = nFillI.Items[2] as ToolMenuItem;
			toolMenuItem2.ApplyTemplate();
			if (!(toolMenuItem2.Template.FindName("BorderNoFill", toolMenuItem2) is Border border))
			{
				return;
			}
			CheckBoxTool checkBoxTool = border.Child as CheckBoxTool;
			if (checkBoxTool.IsEnabled)
			{
				short fillMode;
				switch (_iconEditorScreen.iconEditor.GetFillMode())
				{
				case 255:
					checkBoxTool.IsEnabled = false;
					checkBoxTool.IsChecked = true;
					return;
				case 0:
					fillMode = 1;
					checkBoxTool.IsChecked = false;
					break;
				default:
					fillMode = 0;
					checkBoxTool.IsChecked = true;
					break;
				}
				_iconEditorScreen.iconEditor.SetFillMode(fillMode);
				_iconEditorScreen.iconEditor.SetObjectFillColorIndex((short)num);
			}
		}

		private void RotateBtn_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.SetClickRotate(0);
			}
		}

		private void FlipLRBtn_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.SetClickRotate(1);
			}
		}

		private void FlipUDBtn_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				_iconEditorScreen.iconEditor.SetClickRotate(2);
			}
		}

		private void SnapBtn_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				if (_iconEditorScreen.iconEditor.GetSnap() == 1)
				{
					SnapBtn.IsChecked = false;
					_iconEditorScreen.iconEditor.SetSnap(0);
				}
				else
				{
					SnapBtn.IsChecked = true;
					_iconEditorScreen.iconEditor.SetSnap(1);
				}
			}
		}

		private void GridBtn_Click(object sender, RoutedEventArgs e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				if (_iconEditorScreen.iconEditor.GetGrid() == 1)
				{
					GridBtn.IsChecked = false;
					_iconEditorScreen.iconEditor.SetGrid(0);
				}
				else
				{
					GridBtn.IsChecked = true;
					_iconEditorScreen.iconEditor.SetGrid(1);
				}
			}
		}

		private void GridCombo_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (bIsCreated && _iconEditorScreen != null)
			{
				short gridSizeIndex = Convert.ToInt16(GridCombo.Value.ToString());
				_iconEditorScreen.iconEditor.SetGridSizeIndex(gridSizeIndex);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibraryiconeditorscreencontextualribbon.xaml", UriKind.Relative);
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
				SaveIconBtn = (ButtonTool)target;
				break;
			case 2:
				nText = (ButtonTool)target;
				nText.Click += nText_Click;
				break;
			case 3:
				nLine = (ButtonTool)target;
				nLine.Click += nLine_Click;
				break;
			case 4:
				nRectangle = (ButtonTool)target;
				nRectangle.Click += nRectangle_Click;
				break;
			case 5:
				nPolygon = (ButtonTool)target;
				nPolygon.Click += nPolygon_Click;
				break;
			case 6:
				nPolyline = (ButtonTool)target;
				nPolyline.Click += nPolyline_Click;
				break;
			case 7:
				nEllipse = (ButtonTool)target;
				nEllipse.Click += nEllipse_Click;
				break;
			case 8:
				nSemi_Ellipse = (ButtonTool)target;
				nSemi_Ellipse.Click += nSemi_Ellipse_Click;
				break;
			case 9:
				nArrow = (ButtonTool)target;
				nArrow.Click += nArrow_Click;
				break;
			case 10:
				nDoubleArrow = (ButtonTool)target;
				nDoubleArrow.Click += nDoubleArrow_Click;
				break;
			case 11:
				nFillI = (MenuTool)target;
				nFillI.Opened += nFillI_Opened;
				break;
			case 12:
				TMIFillColorPicker = (ToolMenuItem)target;
				TMIFillColorPicker.Click += TMIFillColorPicker_Click;
				break;
			case 13:
				nFillNoFill = (ToolMenuItem)target;
				break;
			case 14:
				nTMIFillNoFill = (ToolMenuItem)target;
				nTMIFillNoFill.Click += nTMIFillNoFill_Click;
				break;
			case 16:
				MTLine = (MenuTool)target;
				MTLine.Opened += MTLine_Opened;
				break;
			case 17:
				TMIColorPicker = (ToolMenuItem)target;
				TMIColorPicker.Click += TMIColorPicker_Click;
				break;
			case 18:
				MTType = (MenuTool)target;
				MTType.Opened += MTType_Opened;
				break;
			case 19:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 20:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 21:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 22:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 23:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 24:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 25:
				((ToolMenuItem)target).PreviewMouseDown += LineTypeToolMenuItem_PreviewMouseDown;
				break;
			case 26:
				nIconFontCombo = (ComboEditorTool)target;
				nIconFontCombo.SelectedItemChanged += nIconFontCombo_SelectedItemChanged;
				break;
			case 27:
				buttonGroupFonts = (ButtonGroup)target;
				break;
			case 28:
				BoldR = (ToggleButtonTool)target;
				BoldR.Click += BoldR_Click;
				break;
			case 29:
				ItalicR = (ToggleButtonTool)target;
				ItalicR.Click += ItalicR_Click;
				break;
			case 30:
				UnderScoreR = (ToggleButtonTool)target;
				UnderScoreR.Click += UnderScoreR_Click;
				break;
			case 31:
				bEnargeFontR = (ButtonTool)target;
				bEnargeFontR.Click += bEnargeFontR_Click;
				break;
			case 32:
				bShrinkFontR = (ButtonTool)target;
				bShrinkFontR.Click += bShrinkFontR_Click;
				break;
			case 33:
				nIconSizeCombo = (ComboEditorTool)target;
				nIconSizeCombo.SelectedItemChanged += nIconSizeCombo_SelectedItemChanged;
				break;
			case 34:
				lblTextColorR = (LabelTool)target;
				break;
			case 35:
				nFontColor = (MenuTool)target;
				nFontColor.Opened += nFontColor_Opened;
				break;
			case 36:
				TMITextColorPicker1 = (ToolMenuItem)target;
				TMITextColorPicker1.Click += TMITextColorPicker1_Click;
				break;
			case 37:
				RotateBtn = (ButtonTool)target;
				RotateBtn.Click += RotateBtn_Click;
				break;
			case 38:
				FlipLRBtn = (ButtonTool)target;
				FlipLRBtn.Click += FlipLRBtn_Click;
				break;
			case 39:
				FlipUDBtn = (ButtonTool)target;
				FlipUDBtn.Click += FlipUDBtn_Click;
				break;
			case 40:
				GridBtn = (ToggleButtonTool)target;
				GridBtn.Click += GridBtn_Click;
				break;
			case 41:
				SnapBtn = (ToggleButtonTool)target;
				SnapBtn.Click += SnapBtn_Click;
				break;
			case 42:
				GridCombo = (ComboEditorTool)target;
				GridCombo.SelectedItemChanged += GridCombo_SelectedItemChanged;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 15)
			{
				((CheckBoxTool)target).Click += nTMIFillNoFill_Click;
			}
		}
	}
	public class ModelLibraryIconEditorScreenSubject : ScreenSubject
	{
		public string ModelLibraryDisplayName { get; set; }

		public string ModelTypeName { get; set; }

		public string IconName { get; set; }
	}
	public class ModelTypeUserConfigurationScreen : ApwnDocumentControl, INotifyPropertyChanged, IComponentConnector
	{
		private IAEditCategories _targetEditCategories;

		private IAModelType _targetModelType;

		private int _ConfigDataVersion;

		private string _ConfigDatafuncName = "";

		private const int UVTCOL_NAME = 0;

		private const int UVTCOL_TYPE = 1;

		private const int UVTCOL_DIM = 2;

		private const int UVTCOL_LEVEL = 3;

		private const int UVTCOL_IO = 4;

		private bool _bDataLoaded;

		private ObservableCollection<UserConfigItemData> _listAllDatas = new ObservableCollection<UserConfigItemData>();

		private int nLastSelectedRowIndex = -1;

		internal ModelTypeUserConfigurationScreen root;

		internal System.Windows.Controls.DataGrid ConfigGrid;

		internal System.Windows.Controls.Button btnImport;

		internal System.Windows.Controls.Button btnExport;

		internal System.Windows.Controls.Button btnApply;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public IAEditCategories TargetEditCategories
		{
			get
			{
				if (_targetEditCategories == null && base.ScreenSubject is ModelTypeUserConfigurationScreenSubject modelTypeUserConfigurationScreenSubject && !string.IsNullOrEmpty(modelTypeUserConfigurationScreenSubject.ModelLibraryDisplayName))
				{
					_targetEditCategories = ModelLibraryHelper.GetIAEditCategories(modelTypeUserConfigurationScreenSubject.ModelLibraryDisplayName);
				}
				return _targetEditCategories;
			}
		}

		public IAModelType TargetModelType
		{
			get
			{
				if (_targetModelType == null && TargetEditCategories != null)
				{
					ModelTypeUserConfigurationScreenSubject modelTypeUserConfigurationScreenSubject = base.ScreenSubject as ModelTypeUserConfigurationScreenSubject;
					if (!string.IsNullOrEmpty(modelTypeUserConfigurationScreenSubject.ModelTypeName))
					{
						_targetModelType = ModelLibraryLoader.GetUnmanagedModelType(TargetEditCategories, modelTypeUserConfigurationScreenSubject.ModelTypeName);
					}
				}
				return _targetModelType;
			}
		}

		public int ConfigDataVersion
		{
			get
			{
				return _ConfigDataVersion;
			}
			set
			{
				_ConfigDataVersion = value;
			}
		}

		public string ConfigDatafuncName
		{
			get
			{
				return _ConfigDatafuncName;
			}
			set
			{
				_ConfigDatafuncName = value;
			}
		}

		public ObservableCollection<UserConfigItemData> ListAllDatas
		{
			get
			{
				return _listAllDatas;
			}
			set
			{
				if (value != _listAllDatas)
				{
					_listAllDatas = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("ListAllDatas"));
					}
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ModelTypeUserConfigurationScreen()
		{
			InitializeComponent();
		}

		private void OnChangeApplied()
		{
			if (base.UnityContainer != null)
			{
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Publish(new UserModelLibraryUpdatedEventArgs(TargetEditCategories, UserModelLibraryUpdatedMode.EditUserConfiguration));
			}
		}

		private void btnImport_Click(object sender, RoutedEventArgs e)
		{
			System.Windows.Forms.OpenFileDialog openFileDialog = new System.Windows.Forms.OpenFileDialog();
			openFileDialog.RestoreDirectory = true;
			openFileDialog.Title = ModelLibraryResources.UserConfigImportCaption;
			openFileDialog.Filter = ModelLibraryResources.UserConfigFileFilter + " (*.f,*.for,*.f90)|*.f;*.for;*.f90|" + ApwnResources.FileType_All_Files + " (*.*)|*.*";
			openFileDialog.FilterIndex = 1;
			openFileDialog.Multiselect = false;
			if (openFileDialog.ShowDialog() != DialogResult.OK)
			{
				return;
			}
			int num = -1;
			int num2 = -1;
			int i = 0;
			string[] array;
			for (array = File.ReadAllLines(openFileDialog.FileName); i < array.Length; i++)
			{
				num = array[i].IndexOf("FUNCTION");
				if (num > -1)
				{
					num += 8;
					num2 = array[i].IndexOf("(NVARS");
					if (ConfigDatafuncName == "")
					{
						ConfigDatafuncName = array[i].Substring(num, num2 - num).Trim();
					}
					break;
				}
			}
			if (i == array.Length)
			{
				return;
			}
			int result = 0;
			for (i++; i < array.Length; i++)
			{
				num = array[i].IndexOf("IPARAM_NVARS=");
				if (num > -1)
				{
					num += 13;
					num2 = array[i].IndexOf(")");
					int.TryParse(array[i].Substring(num, num2 - num).Trim(), out result);
					break;
				}
			}
			if (result == 0 || i == array.Length)
			{
				return;
			}
			ObservableCollection<UserConfigItemData> observableCollection = new ObservableCollection<UserConfigItemData>();
			for (i++; i < array.Length; i++)
			{
				num = array[i].IndexOf("1  4H");
				if (num > -1)
				{
					break;
				}
			}
			if (i == array.Length)
			{
				return;
			}
			int num3 = 0;
			while (num3 < result)
			{
				string text = null;
				string text2 = null;
				string text3 = null;
				string text4 = null;
				string text5 = null;
				num = (num2 = 0);
				for (int j = 0; j < 4; j++)
				{
					num = array[i].IndexOf("4H", num);
					text += array[i].Substring(num + 2, 4);
					num += 7;
				}
				text = text.Trim();
				string text6 = array[i].Substring(num);
				text6 = text6.Remove(text6.Length - 1);
				char[] separator = new char[2] { ',', '\0' };
				string[] array2 = text6.Split(separator, 4);
				text2 = array2[0].Trim();
				text3 = array2[1].Trim();
				text4 = array2[2].Trim();
				text5 = array2[3].Trim();
				observableCollection.Add(new UserConfigItemData("Red", text, text2, text3, text4, text5));
				num3++;
				i++;
			}
			if (i == array.Length)
			{
				return;
			}
			for (; i < array.Length; i++)
			{
				num = array[i].IndexOf("IVRSN/");
				if (num > -1)
				{
					num += 6;
					num2 = array[i].IndexOf("/", num);
					int result2 = 0;
					if (int.TryParse(array[i].Substring(num, num2 - num).Trim(), out result2))
					{
						ConfigDataVersion = result2;
					}
					break;
				}
			}
			CheckAndTransDatasToShow(observableCollection);
		}

		private void btnExport_Click(object sender, RoutedEventArgs e)
		{
			ObservableCollection<UserConfigItemData> lstAllDatasTmp = null;
			int nRow = -1;
			string text = CheckAndTransDatasToSave(out lstAllDatasTmp, out nRow);
			if (text != null)
			{
				string caption = ModelLibraryResources.UserConfigErrorMsgDataCaption + nRow;
				MMMessageBox.Show(text, caption, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				ConfigGrid.SelectedIndex = nRow - 1;
				return;
			}
			System.Windows.Forms.SaveFileDialog saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			saveFileDialog.Title = ModelLibraryResources.UserConfigExportCaption;
			saveFileDialog.Filter = ModelLibraryResources.UserConfigFileFilter + " (*.f,*.for,*.f90)|*.f;*.for;*.f90|" + ApwnResources.FileType_All_Files + " (*.*)|*.*";
			saveFileDialog.FilterIndex = 1;
			saveFileDialog.RestoreDirectory = true;
			saveFileDialog.AddExtension = false;
			string text2 = null;
			while (true)
			{
				if (saveFileDialog.ShowDialog() != DialogResult.OK)
				{
					return;
				}
				text2 = saveFileDialog.FileName;
				text2 = System.IO.Path.GetFileNameWithoutExtension(text2);
				if (text2.Length <= 8)
				{
					break;
				}
				MMMessageBox.Show(ModelLibraryResources.UserConfigErrorMsgFileLength, ModelLibraryResources.UserConfigErrorMsgCaption, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				saveFileDialog.FileName = text2;
			}
			ConfigDatafuncName = text2;
			Stream stream = null;
			if ((stream = saveFileDialog.OpenFile()) == null)
			{
				return;
			}
			string text3 = null;
			nRow = lstAllDatasTmp.Count;
			byte[] array = new byte[1024];
			text3 = $"      INTEGER FUNCTION {text2}(NVARS,ICOL,IROW)\n      PARAMETER (IPARAM_NVARS={nRow.ToString()})\n";
			text3 += "      INTEGER IVARIABLES(8,IPARAM_NVARS), IVRSN\n";
			text3 += "      DATA IVARIABLES/\n";
			array = Encoding.UTF8.GetBytes(text3);
			stream.Write(array, 0, array.Length);
			for (int i = 0; i < nRow; i++)
			{
				text3 = "     1  ";
				int j = 0;
				UserConfigItemData userConfigItemData = lstAllDatasTmp[i];
				int length = userConfigItemData.Name.Length;
				for (; j < 16; j++)
				{
					if (j == 0 || j == 4 || j == 8 || j == 12)
					{
						if (j == 4 || j == 8 || j == 12)
						{
							text3 += ",  ";
						}
						text3 += "4H";
					}
					text3 = ((j >= length) ? (text3 + " ") : (text3 + $"{userConfigItemData.Name[j]}"));
				}
				text3 += $",  {userConfigItemData.Type},  {userConfigItemData.Dimension},  {userConfigItemData.Depth},  {userConfigItemData.IO}";
				text3 = ((i == nRow - 1) ? (text3 + "/\n\n") : (text3 + ",\n"));
				array = Encoding.UTF8.GetBytes(text3);
				stream.Write(array, 0, array.Length);
			}
			text3 = $"      DATA IVRSN/{ConfigDataVersion}/\n      NVARS = IPARAM_NVARS\n      IF(IROW .EQ. 0) THEN\n          {text2}=IVRSN\n";
			array = Encoding.UTF8.GetBytes(text3);
			stream.Write(array, 0, array.Length);
			text3 = $"      ELSE IF(IROW .LE. NVARS) THEN\n          {text2}=IVARIABLES(ICOL,IROW)\n      ENDIF\n      RETURN\n      END\n";
			array = Encoding.UTF8.GetBytes(text3);
			stream.Write(array, 0, array.Length);
			stream.Close();
		}

		private string CheckAndTransDatasToSave(out ObservableCollection<UserConfigItemData> lstAllDatasTmp, out int nRow)
		{
			string text = null;
			nRow = -1;
			lstAllDatasTmp = new ObservableCollection<UserConfigItemData>();
			Dictionary<int, string> scalarVariables = GetScalarVariables(ListAllDatas);
			for (int i = 0; i < ListAllDatas.Count; i++)
			{
				UserConfigItemData userConfigItemData = ListAllDatas[i];
				string name = userConfigItemData.Name;
				string type = userConfigItemData.Type;
				string dimension = userConfigItemData.Dimension;
				string depth = userConfigItemData.Depth;
				string iO = userConfigItemData.IO;
				text = CheckVarialeName(name, i);
				if (text != null)
				{
					nRow = i + 1;
					break;
				}
				text = CheckDepthLevel(depth, i);
				if (text != null)
				{
					nRow = i + 1;
					break;
				}
				type = ShowStringToStore(type, 1, scalarVariables);
				dimension = ShowStringToStore(dimension, 2, scalarVariables);
				iO = ShowStringToStore(iO, 4, scalarVariables);
				lstAllDatasTmp.Add(new UserConfigItemData("", name, type, dimension, depth, iO));
			}
			return text;
		}

		private void CheckAndTransDatasToShow(ObservableCollection<UserConfigItemData> lstAllDatasTmp)
		{
			if (lstAllDatasTmp == null)
			{
				return;
			}
			IList<string> list = CreateDimensionsList(lstAllDatasTmp);
			Dictionary<int, string> scalarVariables = GetScalarVariables(lstAllDatasTmp);
			int num = -1;
			ListAllDatas.Clear();
			for (int i = 0; i < lstAllDatasTmp.Count; i++)
			{
				UserConfigItemData userConfigItemData = lstAllDatasTmp[i];
				bool flag = IsScalarVariable(userConfigItemData);
				if (flag)
				{
					num++;
				}
				string text = userConfigItemData.Name;
				string type = userConfigItemData.Type;
				string dimension = userConfigItemData.Dimension;
				string depth = userConfigItemData.Depth;
				string iO = userConfigItemData.IO;
				string stUri = "Green";
				if (CheckVarialeName(text, i) != null)
				{
					text = null;
					stUri = "Red";
				}
				if (CheckDepthLevel(depth, i) != null)
				{
					stUri = "Red";
				}
				type = StoreValueToShow(type, 1, scalarVariables);
				dimension = StoreValueToShow(dimension, 2, scalarVariables);
				iO = StoreValueToShow(iO, 4, scalarVariables);
				UserConfigItemData userConfigItemData2 = new UserConfigItemData(stUri, text, type, dimension, depth, iO);
				for (int j = 0; j < list.Count; j++)
				{
					if (j < 10 || !flag || j != 10 + num)
					{
						userConfigItemData2.DimensionList.Add(list[j]);
					}
				}
				userConfigItemData2.ValueChangedAction = displayRow_ValueChanged;
				ListAllDatas.Add(userConfigItemData2);
			}
		}

		private void displayRow_ValueChanged(UserConfigItemData data, string propertyName, string oldValue, string newValue)
		{
			if (propertyName == "Name" && IsScalarVariable(data))
			{
				UpdateDimensionList(oldValue, newValue);
			}
			else if (propertyName == "Type" && data.Dimension == ModelLibraryResources.UserConfigDimScalar)
			{
				if (oldValue == ModelLibraryResources.UserConfigTypeInt)
				{
					UpdateDimensionList();
				}
				else if (newValue == ModelLibraryResources.UserConfigTypeInt)
				{
					UpdateDimensionList();
				}
			}
			else if (propertyName == "Dimension" && data.Type == ModelLibraryResources.UserConfigTypeInt)
			{
				if (oldValue == ModelLibraryResources.UserConfigDimScalar)
				{
					UpdateDimensionList();
				}
				else if (newValue == ModelLibraryResources.UserConfigDimScalar)
				{
					UpdateDimensionList();
				}
			}
		}

		private void UpdateDimensionList(string oldName = null, string newName = null)
		{
			Dictionary<int, string> scalarVariables = GetScalarVariables(ListAllDatas);
			for (int i = 0; i < ListAllDatas.Count; i++)
			{
				UserConfigItemData userConfigItemData = ListAllDatas[i];
				string dimension = userConfigItemData.Dimension;
				while (userConfigItemData.DimensionList.Count > 10)
				{
					userConfigItemData.DimensionList.RemoveAt(10);
				}
				foreach (KeyValuePair<int, string> item in scalarVariables)
				{
					if (item.Key != i)
					{
						userConfigItemData.DimensionList.Add(item.Value);
					}
				}
				if (userConfigItemData.DimensionList.Contains(dimension))
				{
					userConfigItemData.Dimension = dimension;
				}
				else if (oldName != null && newName != null && dimension == oldName)
				{
					userConfigItemData.Dimension = newName;
				}
				else
				{
					userConfigItemData.Dimension = userConfigItemData.DimensionList.FirstOrDefault();
				}
			}
		}

		private IList<string> CreateDimensionsList(IEnumerable<UserConfigItemData> lstAllDatasTmp)
		{
			List<string> list = new List<string>();
			list.Add(ModelLibraryResources.UserConfigDimScalar);
			list.Add(ModelLibraryResources.UserConfigDimComponets);
			list.Add(ModelLibraryResources.UserConfigDimInlet);
			list.Add(ModelLibraryResources.UserConfigDimMaterialInlet);
			list.Add(ModelLibraryResources.UserConfigDimHeatInlet);
			list.Add(ModelLibraryResources.UserConfigDimWorkInlet);
			list.Add(ModelLibraryResources.UserConfigDimOutlet);
			list.Add(ModelLibraryResources.UserConfigDimMaterialOutlet);
			list.Add(ModelLibraryResources.UserConfigDimHeatOutlet);
			list.Add(ModelLibraryResources.UserConfigDimWorkOutlet);
			list.AddRange(GetScalarVariables(lstAllDatasTmp).Values);
			return list;
		}

		private Dictionary<int, string> GetScalarVariables(IEnumerable<UserConfigItemData> lstAllDatasTmp)
		{
			Dictionary<int, string> dictionary = new Dictionary<int, string>();
			int num = 0;
			foreach (UserConfigItemData item in lstAllDatasTmp)
			{
				if (IsScalarVariable(item))
				{
					dictionary.Add(num, item.Name);
				}
				num++;
			}
			return dictionary;
		}

		private bool IsScalarVariable(UserConfigItemData data)
		{
			if (data.Type == "0" || data.Type == ModelLibraryResources.UserConfigTypeInt)
			{
				if (!(data.Dimension == "-1"))
				{
					return data.Dimension == ModelLibraryResources.UserConfigDimScalar;
				}
				return true;
			}
			return false;
		}

		private void btnApply_Click(object sender, RoutedEventArgs e)
		{
			ObservableCollection<UserConfigItemData> lstAllDatasTmp = null;
			int nRow = -1;
			string text = CheckAndTransDatasToSave(out lstAllDatasTmp, out nRow);
			if (text != null)
			{
				string caption = ModelLibraryResources.UserConfigErrorMsgDataCaption + nRow;
				MMMessageBox.Show(text, caption, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				ConfigGrid.SelectedIndex = nRow - 1;
			}
			else if (lstAllDatasTmp.Count <= 0)
			{
				string userConfigErrorMsgCaption = ModelLibraryResources.UserConfigErrorMsgCaption;
				MMMessageBox.Show(ModelLibraryResources.UserConfigErrorMsgEmptyData, userConfigErrorMsgCaption, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
			}
			else if (ModelLibraryEditorScreen.EnsureEditCategoriesWritable(TargetEditCategories))
			{
				ConfigDataVersion = (int)(DateTime.Now - new DateTime(1970, 1, 1, 0, 0, 0)).TotalSeconds;
				ModelLibraryHelper.SaveUserConfiguration(TargetModelType, lstAllDatasTmp, ConfigDatafuncName, ConfigDataVersion);
				OnChangeApplied();
				ModelLibraryHelper.SaveUserModelLibraryChanges(TargetEditCategories);
			}
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			dynamic activeWindow = base.UnityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow;
			activeWindow.CloseScreen(this);
		}

		private void ScreenContentControl_Loaded(object sender, RoutedEventArgs e)
		{
			if (!_bDataLoaded)
			{
				_bDataLoaded = true;
				_ = TargetEditCategories;
				IAModelType targetModelType = TargetModelType;
				string modelTypeName = ModelLibraryHelper.GetModelTypeName(targetModelType);
				modelTypeName += " - ";
				modelTypeName += base.Header;
				base.Header = modelTypeName;
				string stfuncName = null;
				int nVersion = 0;
				ObservableCollection<UserConfigItemData> observableCollection = null;
				observableCollection = ModelLibraryHelper.ReadUserConfiguration(targetModelType, out stfuncName, out nVersion);
				if (nVersion != 0)
				{
					ConfigDataVersion = nVersion;
				}
				if (stfuncName != null)
				{
					ConfigDatafuncName = stfuncName;
				}
				CheckAndTransDatasToShow(observableCollection);
				ListAllDatas.CollectionChanged += ListAllDatas_CollectionChanged;
			}
		}

		private void ListAllDatas_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (e.Action == NotifyCollectionChangedAction.Add && e.NewItems != null)
			{
				IList<string> list = CreateDimensionsList(ListAllDatas);
				foreach (UserConfigItemData newItem in e.NewItems)
				{
					foreach (string item in list)
					{
						newItem.DimensionList.Add(item);
					}
					newItem.ValueChangedAction = displayRow_ValueChanged;
				}
			}
			UpdateDimensionList();
		}

		private void InsertRow_Click(object sender, RoutedEventArgs e)
		{
			int selectedIndex = ConfigGrid.SelectedIndex;
			if (selectedIndex != -1)
			{
				UserConfigItemData item = new UserConfigItemData("Red", "", ModelLibraryResources.UserConfigTypeReal, ModelLibraryResources.UserConfigDimScalar, "0", ModelLibraryResources.UserConfigIoInput);
				ListAllDatas.Insert(selectedIndex, item);
			}
		}

		private void DeleteRow_Click(object sender, RoutedEventArgs e)
		{
			int selectedIndex = ConfigGrid.SelectedIndex;
			if (ListAllDatas != null && selectedIndex > -1 && selectedIndex < ListAllDatas.Count)
			{
				ListAllDatas.RemoveAt(selectedIndex);
			}
		}

		private string CheckDepthLevel(string stValue, int nIndex)
		{
			string result = null;
			int result2 = -1;
			int.TryParse(stValue, out result2);
			if (stValue.Length > 1 || !char.IsDigit(stValue[0]) || result2 < 0 || result2 > 8)
			{
				result = ModelLibraryResources.UserConfigErrorMsg1;
			}
			else if (nIndex == 0)
			{
				if (result2 != 0)
				{
					result = ModelLibraryResources.UserConfigErrorMsg2;
				}
			}
			else if (result2 > 0)
			{
				bool flag = false;
				for (int i = 0; i < nIndex; i++)
				{
					UserConfigItemData userConfigItemData = ListAllDatas[i];
					int result3 = -1;
					int.TryParse(userConfigItemData.Depth, out result3);
					if (result3 == result2 - 1 && userConfigItemData.Type == ModelLibraryResources.UserConfigTypeStr)
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					result = ModelLibraryResources.UserConfigErrorMsg3;
				}
			}
			return result;
		}

		private string CheckVarialeName(string stValue, int nIndex)
		{
			string text = null;
			if (stValue == null)
			{
				return ModelLibraryResources.UserConfigErrorMsg4;
			}
			stValue = stValue.Trim();
			if (stValue.Length == 0)
			{
				text = ModelLibraryResources.UserConfigErrorMsg4;
			}
			else if (!char.IsLetter(stValue[0]))
			{
				text = ModelLibraryResources.UserConfigErrorMsg5;
			}
			else
			{
				for (int i = 1; i < stValue.Length; i++)
				{
					char c = stValue[i];
					if (!char.IsLetterOrDigit(c) && c != '_')
					{
						text = ModelLibraryResources.UserConfigErrorMsg6;
						break;
					}
				}
				if (text == null)
				{
					if (stValue.Length > 16)
					{
						text = ModelLibraryResources.UserConfigErrorMsg7;
					}
					else
					{
						for (int j = 0; j < nIndex; j++)
						{
							if (j != nIndex && ListAllDatas[j].Name == stValue)
							{
								text = ModelLibraryResources.UserConfigErrorMsg8;
								break;
							}
						}
					}
				}
			}
			return text;
		}

		private string StoreValueToShow(string stValue, int DataTransType, Dictionary<int, string> scalarVariables)
		{
			string result = null;
			int result2 = 1000;
			int.TryParse(stValue, out result2);
			switch (DataTransType)
			{
			case 1:
				result = result2 switch
				{
					0 => ModelLibraryResources.UserConfigTypeInt, 
					2 => ModelLibraryResources.UserConfigTypeCh, 
					3 => ModelLibraryResources.UserConfigTypeStr, 
					_ => ModelLibraryResources.UserConfigTypeReal, 
				};
				break;
			case 2:
				result = GetDimensionTextFromValue(result2, scalarVariables);
				break;
			case 4:
				result = result2 switch
				{
					2 => ModelLibraryResources.UserConfigIoOutput, 
					3 => ModelLibraryResources.UserConfigIoBoth, 
					_ => ModelLibraryResources.UserConfigIoInput, 
				};
				break;
			}
			return result;
		}

		private string GetDimensionTextFromValue(int value, Dictionary<int, string> scalarVariables)
		{
			if (value == -2)
			{
				return ModelLibraryResources.UserConfigDimComponets;
			}
			if (value == -13)
			{
				return ModelLibraryResources.UserConfigDimInlet;
			}
			if (value == -14)
			{
				return ModelLibraryResources.UserConfigDimMaterialInlet;
			}
			if (value == -15)
			{
				return ModelLibraryResources.UserConfigDimHeatInlet;
			}
			if (value == -16)
			{
				return ModelLibraryResources.UserConfigDimWorkInlet;
			}
			if (value == -23)
			{
				return ModelLibraryResources.UserConfigDimOutlet;
			}
			if (value == -24)
			{
				return ModelLibraryResources.UserConfigDimMaterialOutlet;
			}
			if (value == -25)
			{
				return ModelLibraryResources.UserConfigDimHeatOutlet;
			}
			if (value == -26)
			{
				return ModelLibraryResources.UserConfigDimWorkOutlet;
			}
			if (value >= 0 && scalarVariables.ContainsKey(value))
			{
				return scalarVariables[value];
			}
			return ModelLibraryResources.UserConfigDimScalar;
		}

		private string ShowStringToStore(string strValue, int DataTransType, Dictionary<int, string> scalarVariables)
		{
			string result = null;
			switch (DataTransType)
			{
			case 1:
				if (strValue == ModelLibraryResources.UserConfigTypeInt)
				{
					result = "0";
				}
				else if (strValue == ModelLibraryResources.UserConfigTypeReal)
				{
					result = "1";
				}
				else if (strValue == ModelLibraryResources.UserConfigTypeCh)
				{
					result = "2";
				}
				else if (strValue == ModelLibraryResources.UserConfigTypeStr)
				{
					result = "3";
				}
				break;
			case 2:
				result = GetDimensionValueFromText(strValue, scalarVariables);
				break;
			case 4:
				if (strValue == ModelLibraryResources.UserConfigIoInput)
				{
					result = "1";
				}
				else if (strValue == ModelLibraryResources.UserConfigIoOutput)
				{
					result = "2";
				}
				else if (strValue == ModelLibraryResources.UserConfigIoBoth)
				{
					result = "3";
				}
				break;
			}
			return result;
		}

		private string GetDimensionValueFromText(string value, Dictionary<int, string> scalarVariables)
		{
			if (value == ModelLibraryResources.UserConfigDimScalar)
			{
				return "-1";
			}
			if (value == ModelLibraryResources.UserConfigDimComponets)
			{
				return "-2";
			}
			if (value == ModelLibraryResources.UserConfigDimInlet)
			{
				return "-13";
			}
			if (value == ModelLibraryResources.UserConfigDimMaterialInlet)
			{
				return "-14";
			}
			if (value == ModelLibraryResources.UserConfigDimHeatInlet)
			{
				return "-15";
			}
			if (value == ModelLibraryResources.UserConfigDimWorkInlet)
			{
				return "-16";
			}
			if (value == ModelLibraryResources.UserConfigDimOutlet)
			{
				return "-23";
			}
			if (value == ModelLibraryResources.UserConfigDimMaterialOutlet)
			{
				return "-24";
			}
			if (value == ModelLibraryResources.UserConfigDimHeatOutlet)
			{
				return "-25";
			}
			if (value == ModelLibraryResources.UserConfigDimWorkOutlet)
			{
				return "-26";
			}
			foreach (KeyValuePair<int, string> scalarVariable in scalarVariables)
			{
				if (scalarVariable.Value == value)
				{
					return scalarVariable.Key.ToString();
				}
			}
			return "-1";
		}

		private void ConfigGrid_SelectedCellsChanged(object sender, SelectedCellsChangedEventArgs e)
		{
			if (nLastSelectedRowIndex != -1 && nLastSelectedRowIndex == ListAllDatas.Count - 1)
			{
				UserConfigItemData userConfigItemData = ListAllDatas[ListAllDatas.Count - 1];
				if (userConfigItemData.Type == null)
				{
					userConfigItemData.Type = ModelLibraryResources.UserConfigTypeReal;
				}
				if (userConfigItemData.Dimension == null)
				{
					userConfigItemData.Dimension = ModelLibraryResources.UserConfigDimScalar;
				}
				if (userConfigItemData.Depth == null)
				{
					userConfigItemData.Depth = "0";
				}
				if (userConfigItemData.IO == null)
				{
					userConfigItemData.IO = ModelLibraryResources.UserConfigIoInput;
				}
				userConfigItemData.ComStatus = "Red";
			}
			nLastSelectedRowIndex = ConfigGrid.SelectedIndex;
			for (int i = 0; i < ListAllDatas.Count; i++)
			{
				UserConfigItemData userConfigItemData2 = ListAllDatas[i];
				string name = userConfigItemData2.Name;
				string depth = userConfigItemData2.Depth;
				if (CheckVarialeName(name, i) != null)
				{
					ListAllDatas[i].ComStatus = "Red";
					break;
				}
				if (CheckDepthLevel(depth, i) != null)
				{
					ListAllDatas[i].ComStatus = "Red";
					break;
				}
				ListAllDatas[i].ComStatus = "Green";
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypeuserconfigurationscreen.xaml", UriKind.Relative);
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
				root = (ModelTypeUserConfigurationScreen)target;
				root.Loaded += ScreenContentControl_Loaded;
				break;
			case 2:
				((System.Windows.Controls.MenuItem)target).Click += InsertRow_Click;
				break;
			case 3:
				((System.Windows.Controls.MenuItem)target).Click += DeleteRow_Click;
				break;
			case 4:
				ConfigGrid = (System.Windows.Controls.DataGrid)target;
				ConfigGrid.SelectedCellsChanged += ConfigGrid_SelectedCellsChanged;
				break;
			case 5:
				btnImport = (System.Windows.Controls.Button)target;
				btnImport.Click += btnImport_Click;
				break;
			case 6:
				btnExport = (System.Windows.Controls.Button)target;
				btnExport.Click += btnExport_Click;
				break;
			case 7:
				btnApply = (System.Windows.Controls.Button)target;
				btnApply.Click += btnApply_Click;
				break;
			case 8:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MyColorConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				return null;
			}
			System.Windows.Media.Color color = default(System.Windows.Media.Color);
			string text = value as string;
			if (text.ToUpper() == "RED")
			{
				color.A = byte.MaxValue;
				color.R = byte.MaxValue;
				color.G = 0;
				color.B = 0;
			}
			else if (text.ToUpper() == "GREEN")
			{
				color.A = byte.MaxValue;
				color.R = 0;
				color.G = byte.MaxValue;
				color.B = 0;
			}
			else
			{
				color.A = byte.MaxValue;
				color.R = 0;
				color.G = 0;
				color.B = byte.MaxValue;
			}
			return new SolidColorBrush(color);
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return value;
		}
	}
	public class ModelTypeUserConfigurationScreenSubject : ScreenSubject
	{
		public string ModelLibraryDisplayName { get; set; }

		public string ModelTypeName { get; set; }
	}
	public class ModelTypeWizard : Window, IComponentConnector
	{
		private const int MultiBlockFlag = 256;

		private const int MultiBlockWithoutHierarchyFlag = 512;

		private const string User2BaseName = "USER2";

		private const string User3BaseName = "USER3";

		private const string HierarchyBaseModelTypeName = "HIERARCHY";

		internal WizardControl theWizard;

		internal ModelTypeWizardItemWelcome WelcomePage;

		internal ModelTypeWizardItemSelectLibrary SelectLibraryPage;

		internal ModelTypeWizardItemSelectCategory SelectCategoryPage;

		internal ModelTypeWizardItemSelectModelType SelectModelTypePage;

		internal ModelTypeWizardItemModelTypeOptions ModelTypeOptionsPage;

		internal ModelTypeWizardItemSingleBlock SingleBlockPage;

		internal ModelTypeWizardItemSelectAdditionalRecords SelectAdditionalRecordsPage;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public ModelTypeWizardMode Mode { get; private set; }

		public IUnityContainer UnityContainer { get; private set; }

		public IAModelType UnmanagedModelType { get; private set; }

		public IAModel UnmanagedDocumentRootModel { get; private set; }

		public IAModel UnmanagedScreenRootModel { get; private set; }

		public IAModel UnmanagedSingleModel { get; private set; }

		public IEnumAModel UnmanagedAModels { get; private set; }

		public object UnmanagedRecord { get; private set; }

		public UserModelLibrary TargetLibrary { get; private set; }

		public bool IsAppendOnly { get; private set; }

		public UserModelLibrary ResolvedTargetLibrary
		{
			get
			{
				if (TargetLibrary != null)
				{
					return TargetLibrary;
				}
				if (SelectLibraryPage.SelectedLibrary != null)
				{
					return SelectLibraryPage.SelectedLibrary;
				}
				return null;
			}
		}

		public IAModelType ResolvedTargetModelTypeForAppend
		{
			get
			{
				if (!string.IsNullOrEmpty(SelectModelTypePage.SelectedModelType) && ResolvedTargetLibrary != null)
				{
					return ModelLibraryLoader.GetUnmanagedModelType(ResolvedTargetLibrary.UnamangedIAEditCategories, SelectModelTypePage.SelectedModelType);
				}
				return null;
			}
		}

		public bool IsMultiBlock
		{
			get
			{
				if (Mode != ModelTypeWizardMode.MultipleModels)
				{
					return Mode == ModelTypeWizardMode.Problem;
				}
				return true;
			}
		}

		public bool ResolvedIsMultiBlock
		{
			get
			{
				if (SingleBlockPage.SingleBlockOrMultiRecord.HasValue)
				{
					return SingleBlockPage.SingleBlockOrMultiRecord.Value > 0;
				}
				return IsMultiBlock;
			}
		}

		public bool IsSourceUser2
		{
			get
			{
				switch (Mode)
				{
				case ModelTypeWizardMode.ModelType:
				{
					string userModelTypeBaseName2 = ModelLibraryHelper.GetUserModelTypeBaseName(UnmanagedModelType);
					if (!string.Equals(userModelTypeBaseName2, "USER2", StringComparison.CurrentCultureIgnoreCase))
					{
						return string.Equals(userModelTypeBaseName2, "USER3", StringComparison.CurrentCultureIgnoreCase);
					}
					return true;
				}
				case ModelTypeWizardMode.SingleModel:
				case ModelTypeWizardMode.Records:
				{
					IAModelType ppModelType = null;
					UnmanagedSingleModel.GetModelType(ref ppModelType);
					string userModelTypeBaseName = ModelLibraryHelper.GetUserModelTypeBaseName(ppModelType);
					if (!string.Equals(userModelTypeBaseName, "USER2", StringComparison.CurrentCultureIgnoreCase))
					{
						return string.Equals(userModelTypeBaseName, "USER3", StringComparison.CurrentCultureIgnoreCase);
					}
					return true;
				}
				default:
					return false;
				}
			}
		}

		public int ModelTypeIconCopyFlag
		{
			get
			{
				if (ModelTypeOptionsPage.IsToCopyCurrentIcon)
				{
					return 1;
				}
				if (ModelTypeOptionsPage.IsToCopyDefaultIcon)
				{
					return 2;
				}
				if (ModelTypeOptionsPage.IsToCopyAllIcon)
				{
					return 4;
				}
				return 0;
			}
		}

		public bool IsToUseInputRecords
		{
			get
			{
				if (SelectAdditionalRecordsPage.HasSelectionChange.HasValue && SelectAdditionalRecordsPage.HasSelectionChange.Value)
				{
					return false;
				}
				return true;
			}
		}

		private ModelTypeWizard()
		{
			InitializeComponent();
		}

		public ModelTypeWizard(IAModelType unmanagedModelType, IUnityContainer unityContainer, UserModelLibrary targetLibrary = null)
			: this()
		{
			if (unmanagedModelType == null)
			{
				throw new ArgumentNullException("unmanagedModelType");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			TargetLibrary = targetLibrary;
			UnmanagedModelType = unmanagedModelType;
			UnityContainer = unityContainer;
			Mode = ModelTypeWizardMode.ModelType;
		}

		public ModelTypeWizard(IAModel unmanagedDocumentRootModel, IUnityContainer unityContainer)
			: this()
		{
			if (unmanagedDocumentRootModel == null)
			{
				throw new ArgumentNullException("unmanagedDocumentRootModel");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			UnmanagedDocumentRootModel = unmanagedDocumentRootModel;
			UnityContainer = unityContainer;
			Mode = ModelTypeWizardMode.Problem;
		}

		public ModelTypeWizard(IAModel unmanagedDocumentRootModel, IAModel unmanagedScreenRootModel, IAModel unmanagedSingleModel, IEnumAModel unmanagedAModels, IUnityContainer unityContainer)
			: this()
		{
			if (unmanagedDocumentRootModel == null)
			{
				throw new ArgumentNullException("unmanagedDocumentRootModel");
			}
			if (unmanagedScreenRootModel == null)
			{
				throw new ArgumentNullException("unmanagedScreenRootModel");
			}
			if (unmanagedSingleModel == null)
			{
				throw new ArgumentNullException("unmanagedSingleModel");
			}
			if (unmanagedAModels == null)
			{
				throw new ArgumentNullException("unmanagedAModels");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			UnmanagedDocumentRootModel = unmanagedDocumentRootModel;
			UnmanagedScreenRootModel = unmanagedScreenRootModel;
			UnmanagedSingleModel = unmanagedSingleModel;
			UnmanagedAModels = unmanagedAModels;
			UnityContainer = unityContainer;
			Mode = ModelTypeWizardMode.SingleModel;
		}

		public ModelTypeWizard(IAModel unmanagedDocumentRootModel, IAModel unmanagedScreenRootModel, IEnumAModel unmanagedAModels, IUnityContainer unityContainer)
			: this()
		{
			if (unmanagedDocumentRootModel == null)
			{
				throw new ArgumentNullException("unmanagedDocumentRootModel");
			}
			if (unmanagedScreenRootModel == null)
			{
				throw new ArgumentNullException("unmanagedScreenRootModel");
			}
			if (unmanagedAModels == null)
			{
				throw new ArgumentNullException("unmanagedAModels");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			UnmanagedDocumentRootModel = unmanagedDocumentRootModel;
			UnmanagedScreenRootModel = unmanagedScreenRootModel;
			UnmanagedAModels = unmanagedAModels;
			UnityContainer = unityContainer;
			Mode = ModelTypeWizardMode.MultipleModels;
		}

		public ModelTypeWizard(IAModel unmanagedDocumentRootModel, object unmanagedRecord, IUnityContainer unityContainer)
			: this()
		{
			if (unmanagedDocumentRootModel == null)
			{
				throw new ArgumentNullException("unmanagedDocumentRootModel");
			}
			if (unmanagedRecord == null)
			{
				throw new ArgumentNullException("unmanagedRecord");
			}
			UnmanagedDocumentRootModel = unmanagedDocumentRootModel;
			UnmanagedRecord = unmanagedRecord;
			UnityContainer = unityContainer;
			Mode = ModelTypeWizardMode.Records;
			IsAppendOnly = true;
		}

		public void MarkInputRecords()
		{
			switch (Mode)
			{
			case ModelTypeWizardMode.SingleModel:
				ModelLibraryHelper.MarkIAModelOrRecord(UnmanagedSingleModel, marked: true);
				break;
			case ModelTypeWizardMode.MultipleModels:
			{
				uint pnumFetched = 0u;
				IAModel ppModel = null;
				UnmanagedAModels.Reset();
				UnmanagedAModels.Next(1u, ref ppModel, ref pnumFetched);
				while (pnumFetched != 0 && ppModel != null)
				{
					ModelLibraryHelper.MarkIAModelOrRecord(ppModel, marked: true);
					try
					{
						ppModel = null;
						pnumFetched = 0u;
						UnmanagedAModels.Next(1u, ref ppModel, ref pnumFetched);
					}
					catch
					{
						break;
					}
				}
				break;
			}
			case ModelTypeWizardMode.Records:
				ModelLibraryHelper.MarkIAModelOrRecord(UnmanagedRecord, marked: true);
				break;
			case ModelTypeWizardMode.Problem:
				break;
			}
		}

		protected override void OnClosed(EventArgs e)
		{
			ModelLibraryHelper.ClearAllMarks();
			new RecordTreeHelper().CleanUnmanagedTree();
			base.OnClosed(e);
		}

		private int CreateMultiBlockFlag()
		{
			int num = ModelTypeIconCopyFlag | 0x100;
			if (SingleBlockPage.SingleBlockOrMultiRecord.HasValue && SingleBlockPage.SingleBlockOrMultiRecord.Value == 2)
			{
				num |= 0x200;
			}
			return num;
		}

		private IAModelType CreateHierachyModelType(bool useInputRecords)
		{
			if (IsToUseInputRecords)
			{
				MarkInputRecords();
			}
			int copyFlag = CreateMultiBlockFlag();
			return ModelLibraryHelper.CreateModelType(ResolvedTargetLibrary.UnamangedIAEditCategories, SelectCategoryPage.SelectedCategory.Header.ToString(), ModelTypeOptionsPage.ModelTypeName, copyFlag, "HIERARCHY");
		}

		private bool CopyTemplateMB(IAModel rootModel, bool useInputRecordsForTemplateCopy, IAModelType newModelType, bool append)
		{
			if (useInputRecordsForTemplateCopy)
			{
				return ModelLibraryHelper.CopyTemplateMB(rootModel, newModelType, UnmanagedAModels, append);
			}
			return ModelLibraryHelper.CopyTemplateMB(rootModel, newModelType, null, append);
		}

		private bool UpdateTemplateForAppend(IAModel rootModel, bool clearMarksFirst, bool markInputRecords, bool useInputRecordsForTemplateCopy)
		{
			if (clearMarksFirst)
			{
				ModelLibraryHelper.ClearAllMarks();
			}
			if (markInputRecords)
			{
				MarkInputRecords();
			}
			return CopyTemplateMB(rootModel, useInputRecordsForTemplateCopy, ResolvedTargetModelTypeForAppend, append: true);
		}

		private void theWizard_Finished(object sender, RoutedEventArgs e)
		{
			if (ResolvedTargetLibrary != null && ResolvedTargetLibrary.UnamangedIAEditCategories != null)
			{
				bool flag = false;
				ModelLibraryEditorScreen.EnsureEditCategoriesWritable(ResolvedTargetLibrary.UnamangedIAEditCategories);
				flag = ((!WelcomePage.IsAddChecked) ? DoAppend() : DoAdd());
				if (flag)
				{
					flag = ModelLibraryHelper.SaveUserModelLibraryChanges(ResolvedTargetLibrary.UnamangedIAEditCategories);
				}
				if (flag)
				{
					ModelLibraryHelper.RefreshApwnLibraries();
					UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelTypeWizardFinishedEvent>().Publish(new ModelTypeWizardFinishedEventArgs(ResolvedTargetLibrary.UnamangedIAEditCategories));
					base.DialogResult = true;
				}
			}
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			if (ResolvedTargetLibrary != null && ResolvedTargetLibrary.UnamangedIAEditCategories != null)
			{
				ModelLibraryHelper.RevertUserModelLibraryChanges(ResolvedTargetLibrary.UnamangedIAEditCategories);
			}
			Close();
		}

		private bool DoAdd()
		{
			if (Mode != ModelTypeWizardMode.Records)
			{
				ModelLibraryEditorScreen.ClearUncategorizedModelTypes(ResolvedTargetLibrary.UnamangedIAEditCategories);
			}
			return Mode switch
			{
				ModelTypeWizardMode.ModelType => AddModelType(), 
				ModelTypeWizardMode.SingleModel => AddSingleModel(), 
				ModelTypeWizardMode.MultipleModels => AddMultipleModels(), 
				ModelTypeWizardMode.Problem => AddProblem(), 
				ModelTypeWizardMode.Records => true, 
				_ => false, 
			};
		}

		private bool AddModelType()
		{
			int multiBlockTypeFlag = ModelLibraryHelper.GetMultiBlockTypeFlag(UnmanagedModelType);
			int num = ModelTypeIconCopyFlag;
			switch (multiBlockTypeFlag)
			{
			case 1:
				num |= 0x100;
				break;
			case 2:
				num |= 0x300;
				break;
			}
			if (!ModelLibraryEditorScreen.EnsureEditCategoriesWritable(ResolvedTargetLibrary.UnamangedIAEditCategories))
			{
				return false;
			}
			IAModelType iAModelType = ModelLibraryHelper.CreateModelType(ResolvedTargetLibrary.UnamangedIAEditCategories, SelectCategoryPage.SelectedCategory.Header.ToString(), ModelTypeOptionsPage.ModelTypeName, num, UnmanagedModelType);
			if (iAModelType == null)
			{
				return false;
			}
			if (ModelTypeOptionsPage.IsToCopyTemplate && !ModelLibraryHelper.CopyTemplate(UnmanagedModelType, iAModelType))
			{
				return false;
			}
			if (ModelTypeOptionsPage.IsToCopyUserConfiguration && !ModelLibraryHelper.CopyUserConfiguration(UnmanagedModelType, iAModelType))
			{
				return false;
			}
			return true;
		}

		private bool AddSingleModel()
		{
			if (ResolvedIsMultiBlock)
			{
				return AddMultipleModels();
			}
			IAModelType iAModelType = ModelLibraryHelper.CreateModelType(ResolvedTargetLibrary.UnamangedIAEditCategories, SelectCategoryPage.SelectedCategory.Header.ToString(), ModelTypeOptionsPage.ModelTypeName, ModelTypeIconCopyFlag, UnmanagedSingleModel);
			if (iAModelType == null)
			{
				return false;
			}
			if (ModelTypeOptionsPage.IsToCopyTemplate)
			{
				if (!ModelLibraryHelper.CopyTemplate(UnmanagedSingleModel, iAModelType))
				{
					return false;
				}
			}
			else if (!ModelLibraryHelper.UpdateTemplateEnablibilty(iAModelType, enabled: false))
			{
				return false;
			}
			if (ModelTypeOptionsPage.IsToCopyUserConfiguration && !ModelLibraryHelper.CopyUserConfiguration(UnmanagedSingleModel, iAModelType))
			{
				return false;
			}
			return true;
		}

		private bool AddMultipleModels()
		{
			IAModelType iAModelType = CreateHierachyModelType(IsToUseInputRecords);
			if (iAModelType != null)
			{
				return CopyTemplateMB(UnmanagedScreenRootModel, IsToUseInputRecords, iAModelType, append: false);
			}
			return false;
		}

		private bool AddProblem()
		{
			IAModelType iAModelType = CreateHierachyModelType(IsToUseInputRecords);
			if (iAModelType == null)
			{
				return false;
			}
			ModelLibraryHelper.ClearAllMarks();
			return CopyTemplateMB(UnmanagedDocumentRootModel, useInputRecordsForTemplateCopy: false, iAModelType, append: false);
		}

		private bool DoAppend()
		{
			return Mode switch
			{
				ModelTypeWizardMode.ModelType => true, 
				ModelTypeWizardMode.SingleModel => AppendSingleModel(), 
				ModelTypeWizardMode.MultipleModels => AppendMultipleModels(), 
				ModelTypeWizardMode.Problem => AppendProblem(), 
				ModelTypeWizardMode.Records => AppendRecords(), 
				_ => false, 
			};
		}

		private bool AppendSingleModel()
		{
			return UpdateTemplateForAppend(UnmanagedScreenRootModel, clearMarksFirst: false, IsToUseInputRecords, IsToUseInputRecords);
		}

		private bool AppendMultipleModels()
		{
			return UpdateTemplateForAppend(UnmanagedScreenRootModel, clearMarksFirst: false, IsToUseInputRecords, IsToUseInputRecords);
		}

		private bool AppendProblem()
		{
			return UpdateTemplateForAppend(UnmanagedDocumentRootModel, clearMarksFirst: true, markInputRecords: false, useInputRecordsForTemplateCopy: false);
		}

		private bool AppendRecords()
		{
			return UpdateTemplateForAppend(UnmanagedDocumentRootModel, clearMarksFirst: false, IsToUseInputRecords, useInputRecordsForTemplateCopy: false);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizard.xaml", UriKind.Relative);
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
				theWizard = (WizardControl)target;
				theWizard.Finished += theWizard_Finished;
				break;
			case 2:
				WelcomePage = (ModelTypeWizardItemWelcome)target;
				break;
			case 3:
				SelectLibraryPage = (ModelTypeWizardItemSelectLibrary)target;
				break;
			case 4:
				SelectCategoryPage = (ModelTypeWizardItemSelectCategory)target;
				break;
			case 5:
				SelectModelTypePage = (ModelTypeWizardItemSelectModelType)target;
				break;
			case 6:
				ModelTypeOptionsPage = (ModelTypeWizardItemModelTypeOptions)target;
				break;
			case 7:
				SingleBlockPage = (ModelTypeWizardItemSingleBlock)target;
				break;
			case 8:
				SelectAdditionalRecordsPage = (ModelTypeWizardItemSelectAdditionalRecords)target;
				break;
			case 9:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class EnterDescriptionWindow : Window, IComponentConnector
	{
		public static readonly DependencyProperty ModelTypeNameProperty = DependencyProperty.Register("ModelTypeName", typeof(string), typeof(EnterDescriptionWindow));

		public static readonly DependencyProperty DescriptionProperty = DependencyProperty.Register("Description", typeof(string), typeof(EnterDescriptionWindow), new FrameworkPropertyMetadata(OnDescriptionPropertyChanged));

		internal System.Windows.Controls.TextBox textBoxDescription;

		internal System.Windows.Controls.Button buttonOK;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public string ModelTypeName
		{
			get
			{
				return (string)GetValue(ModelTypeNameProperty);
			}
			set
			{
				SetValue(ModelTypeNameProperty, value);
			}
		}

		public string Description
		{
			get
			{
				return (string)GetValue(DescriptionProperty);
			}
			set
			{
				SetValue(DescriptionProperty, value);
			}
		}

		public EnterDescriptionWindow()
		{
			InitializeComponent();
			base.Loaded += EnterDescriptionWindow_Loaded;
		}

		private void EnterDescriptionWindow_Loaded(object sender, RoutedEventArgs e)
		{
			textBoxDescription.Focus();
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private static void OnDescriptionPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/enterdescriptionwindow.xaml", UriKind.Relative);
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
				textBoxDescription = (System.Windows.Controls.TextBox)target;
				break;
			case 2:
				buttonOK = (System.Windows.Controls.Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 3:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class EnterNewNameWindow : Window, IComponentConnector
	{
		private long? _maxLength;

		internal System.Windows.Controls.Label theLabel;

		internal System.Windows.Controls.TextBox textBoxNewName;

		internal System.Windows.Controls.Button buttonOK;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public long MaxLength
		{
			get
			{
				if (_maxLength.HasValue)
				{
					return _maxLength.Value;
				}
				return 2147483647L;
			}
		}

		public string NewName => textBoxNewName.Text.Trim();

		public EnterNewNameWindow(string labelName, string defaultName, long? maxLength = null)
		{
			InitializeComponent();
			theLabel.Content = labelName;
			textBoxNewName.Text = defaultName;
			base.Loaded += EnterNewNameWindow_Loaded;
			_maxLength = maxLength;
		}

		private void EnterNewNameWindow_Loaded(object sender, RoutedEventArgs e)
		{
			textBoxNewName.SelectAll();
			textBoxNewName.Focus();
		}

		private void textBoxNewName_TextChanged(object sender, TextChangedEventArgs e)
		{
			buttonOK.IsEnabled = ((!_maxLength.HasValue) ? (!string.IsNullOrWhiteSpace(textBoxNewName.Text)) : (!string.IsNullOrWhiteSpace(textBoxNewName.Text) && textBoxNewName.Text.Trim().Length <= _maxLength.Value));
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/enternewnamewindow.xaml", UriKind.Relative);
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
				theLabel = (System.Windows.Controls.Label)target;
				break;
			case 2:
				textBoxNewName = (System.Windows.Controls.TextBox)target;
				textBoxNewName.TextChanged += textBoxNewName_TextChanged;
				break;
			case 3:
				buttonOK = (System.Windows.Controls.Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 4:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public static class ModelLibraryCommands
	{
		public static RoutedUICommand MoveUpCommand = new RoutedUICommand(ModelLibraryResources.MoveUp, "MoveUp", typeof(ModelLibraryCommands));

		public static RoutedUICommand MoveDownCommand = new RoutedUICommand(ModelLibraryResources.MoveDown, "MoveDown", typeof(ModelLibraryCommands));

		public static RoutedUICommand CreateNewCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCreateNewCategory, "CreateNewCategory", typeof(ModelLibraryCommands));

		public static RoutedUICommand DeleteCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentCategory, "DeleteCurrentCategory", typeof(ModelLibraryCommands));

		public static RoutedUICommand RenameCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandRenameCurrentCategory, "RenameCurrentCategory", typeof(ModelLibraryCommands));

		public static RoutedUICommand ReorderCategories = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderCategories, "ReorderCategories", typeof(ModelLibraryCommands));

		public static RoutedUICommand ReorderModelsInCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderModelsInCurrentCategory, "ReorderModelsInCurrentCategory", typeof(ModelLibraryCommands));

		public static RoutedUICommand DeleteCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentModel, "DeleteCurrentModel", typeof(ModelLibraryCommands));

		public static RoutedUICommand RenameCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandRenameCurrentModel, "RenameCurrentModel", typeof(ModelLibraryCommands));

		public static RoutedUICommand MoveCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandMoveCurrentModel, "MoveCurrentModel", typeof(ModelLibraryCommands));

		public static RoutedUICommand CopyCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCopyCurrentModel, "CopyCurrentModel", typeof(ModelLibraryCommands));

		public static RoutedUICommand EditDescriptionForCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditDescriptionForCurrentModel, "EditDescriptionForCurrentModel", typeof(ModelLibraryCommands));

		public static RoutedUICommand EditUserConfiguration = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditUserConfiguration, "EditUserConfiguration", typeof(ModelLibraryCommands));

		public static RoutedUICommand ClearUserConfiguration = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandClearUserConfiguration, "ClearUserConfiguration", typeof(ModelLibraryCommands));

		public static RoutedUICommand EditCurrentIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditCurrentIcon, "EditCurrentIcon", typeof(ModelLibraryCommands));

		public static RoutedUICommand CreateNewIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCreateNewIcon, "CreateNewIcon", typeof(ModelLibraryCommands));

		public static RoutedUICommand DeleteCurrentIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentIcon, "DeleteCurrentIcon", typeof(ModelLibraryCommands));

		public static RoutedUICommand ReorderIconsInCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderIconsInCurrentModel, "ReorderIconsInCurrentModel", typeof(ModelLibraryCommands));
	}
	public class ModelTypeWizardItem : WizardControlItem
	{
		public ModelTypeWizard ParentModelTypeWizard
		{
			get
			{
				if (base.ParentWizard != null)
				{
					return Window.GetWindow(base.ParentWizard) as ModelTypeWizard;
				}
				return null;
			}
		}

		public IUnityContainer UnityContainer
		{
			get
			{
				if (ParentModelTypeWizard != null)
				{
					return ParentModelTypeWizard.UnityContainer;
				}
				return null;
			}
		}
	}
	public class ModelTypeWizardItemModelTypeOptions : ModelTypeWizardItem, IComponentConnector
	{
		private readonly List<string> _existingModelTypeNames = new List<string>();

		private const string DefaultComplicatedModelTypeName = "Subplant";

		public static readonly DependencyProperty ModelTypeNameProperty = DependencyProperty.Register("ModelTypeName", typeof(string), typeof(ModelTypeWizardItemModelTypeOptions), new FrameworkPropertyMetadata(OnModelTypeNamePropertyChanged));

		public static readonly DependencyProperty IsToCopyDefaultIconProperty = DependencyProperty.Register("IsToCopyDefaultIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyDefaultIconEnabledProperty = DependencyProperty.Register("IsToCopyDefaultIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyCurrentIconProperty = DependencyProperty.Register("IsToCopyCurrentIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyCurrentIconEnabledProperty = DependencyProperty.Register("IsToCopyCurrentIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyAllIconProperty = DependencyProperty.Register("IsToCopyAllIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyAllIconEnabledProperty = DependencyProperty.Register("IsToCopyAllIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyTemplateProperty = DependencyProperty.Register("IsToCopyTemplate", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyTemplateEnabledProperty = DependencyProperty.Register("IsToCopyTemplateEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyUserConfigurationProperty = DependencyProperty.Register("IsToCopyUserConfiguration", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		public static readonly DependencyProperty IsToCopyUserConfigurationEnabledProperty = DependencyProperty.Register("IsToCopyUserConfigurationEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));

		internal System.Windows.Controls.TextBox textBoxModelTypeName;

		internal TextBlock checkModelTypeNameLabel;

		private bool _contentLoaded;

		public string ModelTypeName
		{
			get
			{
				return (string)GetValue(ModelTypeNameProperty);
			}
			set
			{
				SetValue(ModelTypeNameProperty, value);
			}
		}

		public bool IsToCopyDefaultIcon
		{
			get
			{
				return (bool)GetValue(IsToCopyDefaultIconProperty);
			}
			set
			{
				SetValue(IsToCopyDefaultIconProperty, value);
			}
		}

		public bool IsToCopyDefaultIconEnabled
		{
			get
			{
				return (bool)GetValue(IsToCopyDefaultIconEnabledProperty);
			}
			set
			{
				SetValue(IsToCopyDefaultIconEnabledProperty, value);
			}
		}

		public bool IsToCopyCurrentIcon
		{
			get
			{
				return (bool)GetValue(IsToCopyCurrentIconProperty);
			}
			set
			{
				SetValue(IsToCopyCurrentIconProperty, value);
			}
		}

		public bool IsToCopyCurrentIconEnabled
		{
			get
			{
				return (bool)GetValue(IsToCopyCurrentIconEnabledProperty);
			}
			set
			{
				SetValue(IsToCopyCurrentIconEnabledProperty, value);
			}
		}

		public bool IsToCopyAllIcon
		{
			get
			{
				return (bool)GetValue(IsToCopyAllIconProperty);
			}
			set
			{
				SetValue(IsToCopyAllIconProperty, value);
			}
		}

		public bool IsToCopyAllIconEnabled
		{
			get
			{
				return (bool)GetValue(IsToCopyAllIconEnabledProperty);
			}
			set
			{
				SetValue(IsToCopyAllIconEnabledProperty, value);
			}
		}

		public bool IsToCopyTemplate
		{
			get
			{
				return (bool)GetValue(IsToCopyTemplateProperty);
			}
			set
			{
				SetValue(IsToCopyTemplateProperty, value);
			}
		}

		public bool IsToCopyTemplateEnabled
		{
			get
			{
				return (bool)GetValue(IsToCopyTemplateEnabledProperty);
			}
			set
			{
				SetValue(IsToCopyTemplateEnabledProperty, value);
			}
		}

		public bool IsToCopyUserConfiguration
		{
			get
			{
				return (bool)GetValue(IsToCopyUserConfigurationProperty);
			}
			set
			{
				SetValue(IsToCopyUserConfigurationProperty, value);
			}
		}

		public bool IsToCopyUserConfigurationEnabled
		{
			get
			{
				return (bool)GetValue(IsToCopyUserConfigurationEnabledProperty);
			}
			set
			{
				SetValue(IsToCopyUserConfigurationEnabledProperty, value);
			}
		}

		public ModelTypeWizardItemModelTypeOptions()
		{
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			IEnumerable<string> collection = from category in ModelLibraryLoader.GetManagedCategories(base.ParentModelTypeWizard.ResolvedTargetLibrary.UnamangedIAEditCategories)
				from model in category.Models
				select model.Header.ToString().ToLower(CultureInfo.CurrentCulture);
			_existingModelTypeNames.Clear();
			_existingModelTypeNames.AddRange(collection);
			if (string.IsNullOrEmpty(ModelTypeName))
			{
				ModelTypeName = CreateDefaultModelTypeName();
			}
			if (base.ParentModelTypeWizard.ResolvedIsMultiBlock && base.ParentModelTypeWizard.Mode != ModelTypeWizardMode.ModelType && base.ParentModelTypeWizard.Mode != ModelTypeWizardMode.Problem)
			{
				base.ForwardItem = base.ParentModelTypeWizard.SelectAdditionalRecordsPage;
			}
			else
			{
				base.ForwardItem = null;
			}
			UpdateNextAndFinishEnabled();
			if (base.ParentModelTypeWizard.IsSourceUser2 && !base.ParentModelTypeWizard.ResolvedIsMultiBlock)
			{
				IsToCopyTemplateEnabled = true;
				IsToCopyUserConfigurationEnabled = true;
				IsToCopyTemplate = true;
				IsToCopyUserConfiguration = true;
			}
			else
			{
				IsToCopyTemplateEnabled = false;
				IsToCopyUserConfigurationEnabled = false;
				IsToCopyTemplate = true;
				IsToCopyUserConfiguration = false;
			}
			bool isToCopyDefaultIcon = (IsToCopyDefaultIconEnabled = true);
			IsToCopyDefaultIcon = isToCopyDefaultIcon;
			isToCopyDefaultIcon = (IsToCopyAllIconEnabled = !base.ParentModelTypeWizard.ResolvedIsMultiBlock || base.ParentModelTypeWizard.Mode == ModelTypeWizardMode.ModelType);
			IsToCopyCurrentIconEnabled = isToCopyDefaultIcon;
			base.OnEnter(previousItem, positiveDirection);
		}

		private string CreateDefaultModelTypeName()
		{
			string text = null;
			switch (base.ParentModelTypeWizard.Mode)
			{
			case ModelTypeWizardMode.ModelType:
				text = ModelLibraryLoader.GetUnmanagedModelTypeName(base.ParentModelTypeWizard.UnmanagedModelType);
				break;
			case ModelTypeWizardMode.MultipleModels:
			case ModelTypeWizardMode.Problem:
				text = "Subplant";
				break;
			case ModelTypeWizardMode.SingleModel:
			case ModelTypeWizardMode.Records:
				text = ModelLibraryLoader.GetUnmanagedModelName(base.ParentModelTypeWizard.UnmanagedSingleModel);
				break;
			}
			string text2 = text;
			int num = 1;
			while (_existingModelTypeNames.Contains(text2.ToLower(CultureInfo.CurrentCulture)))
			{
				text2 = $"{text} ({num})";
				num++;
			}
			return text2;
		}

		private void UpdateNextAndFinishEnabled()
		{
			if (!ValidateModelTypeName())
			{
				bool canForward = (base.CanFinish = false);
				base.CanForward = canForward;
			}
			else if (base.ForwardItem != null)
			{
				base.CanForward = true;
				base.CanFinish = true;
			}
			else
			{
				base.CanForward = false;
				base.CanFinish = true;
			}
		}

		private bool ValidateModelTypeName()
		{
			checkModelTypeNameLabel.Visibility = Visibility.Hidden;
			if (string.IsNullOrWhiteSpace(ModelTypeName))
			{
				return false;
			}
			if (Validation.GetHasError(textBoxModelTypeName))
			{
				return false;
			}
			if (_existingModelTypeNames.Contains(ModelTypeName.ToLower(CultureInfo.CurrentCulture)))
			{
				checkModelTypeNameLabel.Visibility = Visibility.Visible;
				return false;
			}
			return true;
		}

		private void textBoxModelTypeName_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
		{
			if (e.Key == Key.Decimal || e.Key == Key.OemPeriod)
			{
				e.Handled = true;
			}
		}

		private static void OnModelTypeNamePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelTypeWizardItemModelTypeOptions).UpdateNextAndFinishEnabled();
		}

		private void textBoxModelTypeName_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			UpdateNextAndFinishEnabled();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemmodeltypeoptions.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				textBoxModelTypeName = (System.Windows.Controls.TextBox)target;
				textBoxModelTypeName.KeyDown += textBoxModelTypeName_KeyDown;
				textBoxModelTypeName.PreviewTextInput += textBoxModelTypeName_PreviewTextInput;
				break;
			case 2:
				checkModelTypeNameLabel = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ModelTypeValicationRule : ValidationRule
	{
		public override ValidationResult Validate(object value, CultureInfo cultureInfo)
		{
			if (string.IsNullOrEmpty(value as string))
			{
				return new ValidationResult(isValid: false, ModelLibraryResources.ModelTypeEmptyError);
			}
			return new ValidationResult(isValid: true, null);
		}
	}
	public class ModelTypeWizardItemSelectAdditionalRecords : ModelTypeWizardItem, IComponentConnector
	{
		[CompilerGenerated]
		private sealed class RootRecordEnumerator : IEnumerable<RecordNode>, IEnumerable, IEnumerator<RecordNode>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private RecordNode currentItem;

			private int initialThreadId;

			public ModelTypeWizardItemSelectAdditionalRecords owner;

			private IEnumerator<ModelTypeWizardRecordNode> outerEnumerator;

			private IEnumerator<RecordNode> innerEnumerator;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public RootRecordEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = iteratorState;
				if ((uint)(num - -4) > 1u && num != 1)
				{
					return;
				}
				try
				{
					if (num != -4 && num != 1)
					{
						return;
					}
					try
					{
					}
					finally
					{
						DisposeInnerEnumerator();
					}
				}
				finally
				{
					DisposeOuterEnumerator();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ModelTypeWizardItemSelectAdditionalRecords modelTypeWizardItemSelectAdditionalRecords = owner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true;
							return false;
						}
						iteratorState = -4;
						goto IL_0099;
					}
					iteratorState = -1;
					if (modelTypeWizardItemSelectAdditionalRecords.RootNodes != null)
					{
						outerEnumerator = modelTypeWizardItemSelectAdditionalRecords.RootNodes.GetEnumerator();
						iteratorState = -3;
						goto IL_00b3;
					}
					goto IL_00cd;
					IL_0099:
					if (innerEnumerator.MoveNext())
					{
						RecordNode current = innerEnumerator.Current;
						currentItem = current;
						iteratorState = 1;
						completedNormally = true;
						return true;
					}
					DisposeInnerEnumerator();
					innerEnumerator = null;
					goto IL_00b3;
					IL_00b3:
					if (outerEnumerator.MoveNext())
					{
						ModelTypeWizardRecordNode current2 = outerEnumerator.Current;
						innerEnumerator = modelTypeWizardItemSelectAdditionalRecords.GetMarkedRecordNodes(current2).GetEnumerator();
						iteratorState = -4;
						goto IL_0099;
					}
					DisposeOuterEnumerator();
					outerEnumerator = null;
					goto IL_00cd;
					IL_00cd:
					completedNormally = true;
					return false;
				}
				finally
				{
					// Dispose on exceptional exit, matching the original IL fault handler.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeOuterEnumerator()
			{
				iteratorState = -1;
				if (outerEnumerator != null)
				{
					outerEnumerator.Dispose();
				}
			}

			private void DisposeInnerEnumerator()
			{
				iteratorState = -3;
				if (innerEnumerator != null)
				{
					innerEnumerator.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<RecordNode> IEnumerable<RecordNode>.GetEnumerator()
			{
				RootRecordEnumerator result;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					result = this;
				}
				else
				{
					result = new RootRecordEnumerator(0)
					{
						owner = owner
					};
				}
				return result;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<RecordNode>)this).GetEnumerator();
			}
		}

		[CompilerGenerated]
		private sealed class ChildRecordEnumerator : IEnumerable<RecordNode>, IEnumerable, IEnumerator<RecordNode>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private RecordNode currentItem;

			private int initialThreadId;

			private ModelTypeWizardRecordNode wizardNode;

			public ModelTypeWizardRecordNode initialWizardNode;

			public ModelTypeWizardItemSelectAdditionalRecords owner;

			private IEnumerator<ModelTypeWizardRecordNode> outerEnumerator;

			private IEnumerator<RecordNode> innerEnumerator;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public ChildRecordEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = iteratorState;
				if ((uint)(num - -4) > 1u && num != 2)
				{
					return;
				}
				try
				{
					if (num != -4 && num != 2)
					{
						return;
					}
					try
					{
					}
					finally
					{
						DisposeInnerEnumerator();
					}
				}
				finally
				{
					DisposeOuterEnumerator();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ModelTypeWizardItemSelectAdditionalRecords modelTypeWizardItemSelectAdditionalRecords = owner;
					switch (num)
					{
					default:
						completedNormally = true;
						return false;
					case 0:
						iteratorState = -1;
						if (wizardNode.IsLeafNode)
						{
							if (wizardNode.IsChecked.HasValue && wizardNode.IsChecked.Value)
							{
								currentItem = wizardNode.Reference;
								iteratorState = 1;
								completedNormally = true;
								return true;
							}
							break;
						}
						outerEnumerator = wizardNode.Children.GetEnumerator();
						iteratorState = -3;
						goto IL_0122;
					case 1:
						iteratorState = -1;
						break;
					case 2:
						{
							iteratorState = -4;
							goto IL_0108;
						}
						IL_0122:
						if (outerEnumerator.MoveNext())
						{
							ModelTypeWizardRecordNode current = outerEnumerator.Current;
							innerEnumerator = modelTypeWizardItemSelectAdditionalRecords.GetMarkedRecordNodes(current).GetEnumerator();
							iteratorState = -4;
							goto IL_0108;
						}
						DisposeOuterEnumerator();
						outerEnumerator = null;
						break;
						IL_0108:
						if (innerEnumerator.MoveNext())
						{
							RecordNode current2 = innerEnumerator.Current;
							currentItem = current2;
							iteratorState = 2;
							completedNormally = true;
							return true;
						}
						DisposeInnerEnumerator();
						innerEnumerator = null;
						goto IL_0122;
					}
					completedNormally = true;
					return false;
				}
				finally
				{
					// Dispose on exceptional exit, matching the original IL fault handler.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeOuterEnumerator()
			{
				iteratorState = -1;
				if (outerEnumerator != null)
				{
					outerEnumerator.Dispose();
				}
			}

			private void DisposeInnerEnumerator()
			{
				iteratorState = -3;
				if (innerEnumerator != null)
				{
					innerEnumerator.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<RecordNode> IEnumerable<RecordNode>.GetEnumerator()
			{
				ChildRecordEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new ChildRecordEnumerator(0)
					{
						owner = owner
					};
				}
				enumerator.wizardNode = initialWizardNode;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<RecordNode>)this).GetEnumerator();
			}
		}

		public static readonly DependencyProperty RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<ModelTypeWizardRecordNode>), typeof(ModelTypeWizardItemSelectAdditionalRecords));

		internal System.Windows.Controls.CheckBox checkHideDisabled;

		internal System.Windows.Controls.TreeView theTreeView;

		private bool _contentLoaded;

		public bool? HasSelectionChange { get; set; }

		public IEnumerable<ModelTypeWizardRecordNode> RootNodes
		{
			get
			{
				return (IEnumerable<ModelTypeWizardRecordNode>)GetValue(RootNodesProperty);
			}
			set
			{
				SetValue(RootNodesProperty, value);
			}
		}

		public ModelTypeWizardItemSelectAdditionalRecords()
		{
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			base.ParentModelTypeWizard.MarkInputRecords();
			HasSelectionChange = true;
			RefreshRootNodes();
			base.CanFinish = true;
			base.OnEnter(previousItem, positiveDirection);
		}

		protected override bool OnFinished()
		{
			if (HasSelectionChange == true)
			{
				IEnumerable<RecordNode> markedRecordNodes = GetMarkedRecordNodes();
				RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
				ModelLibraryHelper.ClearAllMarks();
				foreach (RecordNode item in markedRecordNodes)
				{
					recordTreeHelper.MarkRecord(item);
				}
			}
			return base.OnFinished();
		}

		private void RefreshRootNodes()
		{
			if (RootNodes != null)
			{
				return;
			}
			List<ModelTypeWizardRecordNode> list = new List<ModelTypeWizardRecordNode>();
			foreach (RecordNode item in PrepareRecordNodes())
			{
				ModelTypeWizardRecordNode modelTypeWizardRecordNode = new ModelTypeWizardRecordNode(item);
				if (string.IsNullOrEmpty(modelTypeWizardRecordNode.Name))
				{
					string displayName = (modelTypeWizardRecordNode.Name = ModelLibraryResources.WizardItemSelectAdditionalRecordsRootNodeLabel);
					modelTypeWizardRecordNode.DisplayName = displayName;
				}
				list.Add(modelTypeWizardRecordNode);
			}
			RootNodes = list;
		}

		private IList<RecordNode> PrepareRecordNodes()
		{
			RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
			if (base.ParentModelTypeWizard.UnmanagedScreenRootModel != null)
			{
				recordTreeHelper.InitializeMMRecTree(base.ParentModelTypeWizard.UnmanagedScreenRootModel);
			}
			else
			{
				recordTreeHelper.InitializeMMRecTree(base.ParentModelTypeWizard.UnmanagedDocumentRootModel);
			}
			return recordTreeHelper.BuildRecordTreeNodes();
		}

		[IteratorStateMachine(typeof(RootRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes()
		{
			return new RootRecordEnumerator(-2)
			{
				owner = this
			};
		}

		[IteratorStateMachine(typeof(ChildRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes(ModelTypeWizardRecordNode wizardNode)
		{
			return new ChildRecordEnumerator(-2)
			{
				owner = this,
				initialWizardNode = wizardNode
			};
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemselectadditionalrecords.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				checkHideDisabled = (System.Windows.Controls.CheckBox)target;
				break;
			case 2:
				theTreeView = (System.Windows.Controls.TreeView)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class RecordNodeIsEnabledToVisibilityConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values != DependencyProperty.UnsetValue && values.Length == 2)
			{
				bool? flag = values[0] as bool?;
				bool? flag2 = values[1] as bool?;
				if (flag.HasValue && flag2.HasValue && !flag.Value && flag2.Value)
				{
					return Visibility.Collapsed;
				}
			}
			return Visibility.Visible;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class ModelTypeWizardItemSelectCategory : ModelTypeWizardItem, IComponentConnector
	{
		public static readonly DependencyProperty IntroductionTextProperty = DependencyProperty.Register("IntroductionText", typeof(string), typeof(ModelTypeWizardItemSelectCategory));

		public static readonly DependencyProperty SelectedCategoryProperty = DependencyProperty.Register("SelectedCategory", typeof(Category), typeof(ModelTypeWizardItemSelectCategory), new FrameworkPropertyMetadata(OnSelectedCategoryPropertyChanged));

		internal System.Windows.Controls.ListBox theListBox;

		internal System.Windows.Controls.Button buttonCreateNewCategory;

		private bool _contentLoaded;

		public string IntroductionText
		{
			get
			{
				return (string)GetValue(IntroductionTextProperty);
			}
			set
			{
				SetValue(IntroductionTextProperty, value);
			}
		}

		public Category SelectedCategory
		{
			get
			{
				return (Category)GetValue(SelectedCategoryProperty);
			}
			set
			{
				SetValue(SelectedCategoryProperty, value);
			}
		}

		public ObservableCollection<Category> AvailableCategories { get; private set; }

		public ModelTypeWizardItemSelectCategory()
		{
			AvailableCategories = new ObservableCollection<Category>();
			InitializeComponent();
		}

		private void buttonCreateNewCategory_Click(object sender, RoutedEventArgs e)
		{
			ModelTypeWizard parentModelTypeWizard = base.ParentModelTypeWizard;
			IAEditCategories unamangedIAEditCategories = base.ParentModelTypeWizard.ResolvedTargetLibrary.UnamangedIAEditCategories;
			if (!string.IsNullOrEmpty(ModelLibraryEditorScreen.CreateNewCategoryInEditCategories(unamangedIAEditCategories, parentModelTypeWizard)))
			{
				ModelLibraryHelper.SaveUserModelLibraryChanges(unamangedIAEditCategories);
				UpdateAvailableCategories();
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Publish(new UserModelLibraryUpdatedEventArgs(unamangedIAEditCategories, UserModelLibraryUpdatedMode.CreateNewCategory));
			}
		}

		private void UpdateAvailableCategories()
		{
			string oldHeader = ((SelectedCategory == null) ? null : (SelectedCategory.Header as string));
			AvailableCategories.Clear();
			foreach (Category managedCategory in ModelLibraryLoader.GetManagedCategories(base.ParentModelTypeWizard.ResolvedTargetLibrary.UnamangedIAEditCategories, includeUncategorized: false, includeEmptyCategories: true))
			{
				AvailableCategories.Add(managedCategory);
			}
			SelectedCategory = AvailableCategories.FirstOrDefault((Category x) => string.Equals(x.Header as string, oldHeader, StringComparison.CurrentCultureIgnoreCase));
			if (SelectedCategory == null)
			{
				SelectedCategory = AvailableCategories.FirstOrDefault();
			}
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			IntroductionText = string.Format(ModelLibraryResources.WizardItemSelectCategoryLabel, base.ParentModelTypeWizard.ResolvedTargetLibrary.DisplayName);
			if (base.ParentModelTypeWizard.Mode == ModelTypeWizardMode.ModelType)
			{
				base.ForwardItem = base.ParentModelTypeWizard.ModelTypeOptionsPage;
			}
			else
			{
				base.ForwardItem = base.ParentModelTypeWizard.SingleBlockPage;
			}
			UpdateAvailableCategories();
			base.OnEnter(previousItem, positiveDirection);
		}

		private static void OnSelectedCategoryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelTypeWizardItemSelectCategory).CanForward = e.NewValue != null;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemselectcategory.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				theListBox = (System.Windows.Controls.ListBox)target;
				break;
			case 2:
				buttonCreateNewCategory = (System.Windows.Controls.Button)target;
				buttonCreateNewCategory.Click += buttonCreateNewCategory_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ModelTypeWizardItemSelectLibrary : ModelTypeWizardItem, IComponentConnector
	{
		public static readonly DependencyProperty SelectedLibraryProperty = DependencyProperty.Register("SelectedLibrary", typeof(UserModelLibrary), typeof(ModelTypeWizardItemSelectLibrary), new FrameworkPropertyMetadata(OnSelectedLibraryPropertyChanged));

		internal System.Windows.Controls.ListBox theListBox;

		private bool _contentLoaded;

		public UserModelLibrary SelectedLibrary
		{
			get
			{
				return (UserModelLibrary)GetValue(SelectedLibraryProperty);
			}
			set
			{
				SetValue(SelectedLibraryProperty, value);
			}
		}

		public ObservableCollection<UserModelLibrary> UserModelLibraries { get; private set; }

		public ModelTypeWizardItemSelectLibrary()
		{
			UserModelLibraries = new ObservableCollection<UserModelLibrary>();
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			ModelTypeWizard parentModelTypeWizard = base.ParentModelTypeWizard;
			if (base.ParentModelTypeWizard.WelcomePage.IsAddChecked)
			{
				base.ForwardItem = parentModelTypeWizard.SelectCategoryPage;
			}
			else
			{
				base.ForwardItem = parentModelTypeWizard.SelectModelTypePage;
			}
			UpdateAvailableLibraries();
			base.OnEnter(previousItem, positiveDirection);
		}

		private void UpdateAvailableLibraries()
		{
			string oldSelectedLibraryName = ((SelectedLibrary == null) ? null : SelectedLibrary.DisplayName);
			UserModelLibraries.Clear();
			IEnumerable<UserModelLibrary> enumerable = ModelLibraryLoader.GetAllEditableLibraries();
			if (base.ParentModelTypeWizard.WelcomePage.IsAppendChecked)
			{
				enumerable = enumerable.Where((UserModelLibrary x) => ModelLibraryHelper.ContainsMultiBlockType(x.UnamangedIAEditCategories));
			}
			foreach (UserModelLibrary item in enumerable)
			{
				UserModelLibraries.Add(item);
			}
			SelectedLibrary = UserModelLibraries.FirstOrDefault((UserModelLibrary x) => string.Equals(oldSelectedLibraryName, x.DisplayName, StringComparison.CurrentCultureIgnoreCase));
			if (SelectedLibrary == null)
			{
				SelectedLibrary = UserModelLibraries.FirstOrDefault();
			}
		}

		private static void OnSelectedLibraryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelTypeWizardItemSelectLibrary).CanForward = e.NewValue != null;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemselectlibrary.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				theListBox = (System.Windows.Controls.ListBox)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class ModelTypeWizardItemSelectModelType : ModelTypeWizardItem, IComponentConnector
	{
		public static readonly DependencyProperty SelectedModelTypeProperty = DependencyProperty.Register("SelectedModelType", typeof(string), typeof(ModelTypeWizardItemSelectModelType), new FrameworkPropertyMetadata(OnSelectedModelTypePropertyChanged));

		internal System.Windows.Controls.ListBox theListBox;

		private bool _contentLoaded;

		public string SelectedModelType
		{
			get
			{
				return (string)GetValue(SelectedModelTypeProperty);
			}
			set
			{
				SetValue(SelectedModelTypeProperty, value);
			}
		}

		public ObservableCollection<string> AvailableModelTypes { get; private set; }

		public ModelTypeWizardItemSelectModelType()
		{
			AvailableModelTypes = new ObservableCollection<string>();
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			base.ForwardItem = base.ParentModelTypeWizard.SelectAdditionalRecordsPage;
			UpdateAvailableModelTypes();
			base.OnEnter(previousItem, positiveDirection);
		}

		private void UpdateAvailableModelTypes()
		{
			string oldType = SelectedModelType;
			AvailableModelTypes.Clear();
			foreach (string multiBlockTypesInCategory in ModelLibraryHelper.GetMultiBlockTypesInCategories(base.ParentModelTypeWizard.ResolvedTargetLibrary.UnamangedIAEditCategories))
			{
				AvailableModelTypes.Add(multiBlockTypesInCategory);
			}
			SelectedModelType = AvailableModelTypes.FirstOrDefault((string x) => string.Equals(oldType, x, StringComparison.CurrentCultureIgnoreCase));
			if (SelectedModelType == null)
			{
				SelectedModelType = AvailableModelTypes.FirstOrDefault();
			}
		}

		private static void OnSelectedModelTypePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			ModelTypeWizardItemSelectModelType obj = d as ModelTypeWizardItemSelectModelType;
			bool canForward = (obj.CanFinish = !string.IsNullOrEmpty(obj.SelectedModelType));
			obj.CanForward = canForward;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemselectmodeltype.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				theListBox = (System.Windows.Controls.ListBox)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class ModelTypeWizardItemSingleBlock : ModelTypeWizardItem, IComponentConnector
	{
		public static readonly DependencyProperty IsSingleBlockProperty = DependencyProperty.Register("IsSingleBlock", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));

		public static readonly DependencyProperty IsMultiRecordProperty = DependencyProperty.Register("IsMultiRecord", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));

		public static readonly DependencyProperty IsToCreateWithoutHierarchyProperty = DependencyProperty.Register("IsToCreateWithoutHierarchy", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));

		internal System.Windows.Controls.RadioButton radioButtonMultiRecord;

		private bool _contentLoaded;

		public bool IsSingleBlock
		{
			get
			{
				return (bool)GetValue(IsSingleBlockProperty);
			}
			set
			{
				SetValue(IsSingleBlockProperty, value);
			}
		}

		public bool IsMultiRecord
		{
			get
			{
				return (bool)GetValue(IsMultiRecordProperty);
			}
			set
			{
				SetValue(IsMultiRecordProperty, value);
			}
		}

		public bool IsToCreateWithoutHierarchy
		{
			get
			{
				return (bool)GetValue(IsToCreateWithoutHierarchyProperty);
			}
			set
			{
				SetValue(IsToCreateWithoutHierarchyProperty, value);
			}
		}

		public int? SingleBlockOrMultiRecord { get; private set; }

		public ModelTypeWizardItemSingleBlock()
		{
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			base.CanForward = true;
			base.ForwardItem = base.ParentModelTypeWizard.ModelTypeOptionsPage;
			if (SingleBlockOrMultiRecord.HasValue)
			{
				IsSingleBlock = SingleBlockOrMultiRecord.Value == 0;
				IsMultiRecord = SingleBlockOrMultiRecord.Value > 0;
			}
			else
			{
				IsSingleBlock = !base.ParentModelTypeWizard.IsMultiBlock;
				IsMultiRecord = base.ParentModelTypeWizard.IsMultiBlock;
			}
			base.OnEnter(previousItem, positiveDirection);
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			if (IsSingleBlock)
			{
				SingleBlockOrMultiRecord = 0;
			}
			else if (IsToCreateWithoutHierarchy)
			{
				SingleBlockOrMultiRecord = 2;
			}
			else
			{
				SingleBlockOrMultiRecord = 1;
			}
			return base.OnForward(targetItem);
		}

		protected override bool OnBackward(WizardControlItem targetItem)
		{
			SingleBlockOrMultiRecord = null;
			return base.OnBackward(targetItem);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemsingleblock.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				radioButtonMultiRecord = (System.Windows.Controls.RadioButton)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class ModelTypeWizardItemWelcome : ModelTypeWizardItem, IComponentConnector
	{
		public static readonly DependencyProperty IsAddCheckedProperty = DependencyProperty.Register("IsAddChecked", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));

		public static readonly DependencyProperty IsAppendCheckedProperty = DependencyProperty.Register("IsAppendChecked", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(false));

		public static readonly DependencyProperty CanAddProperty = DependencyProperty.Register("CanAdd", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));

		public static readonly DependencyProperty CanAppendProperty = DependencyProperty.Register("CanAppend", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));

		internal System.Windows.Controls.RadioButton radionButtonAdd;

		internal System.Windows.Controls.RadioButton radionButtonAppend;

		private bool _contentLoaded;

		public bool IsAddChecked
		{
			get
			{
				return (bool)GetValue(IsAddCheckedProperty);
			}
			set
			{
				SetValue(IsAddCheckedProperty, value);
			}
		}

		public bool IsAppendChecked
		{
			get
			{
				return (bool)GetValue(IsAppendCheckedProperty);
			}
			set
			{
				SetValue(IsAppendCheckedProperty, value);
			}
		}

		public bool CanAdd
		{
			get
			{
				return (bool)GetValue(CanAddProperty);
			}
			set
			{
				SetValue(CanAddProperty, value);
			}
		}

		public bool CanAppend
		{
			get
			{
				return (bool)GetValue(CanAppendProperty);
			}
			set
			{
				SetValue(CanAppendProperty, value);
			}
		}

		public ModelTypeWizardItemWelcome()
		{
			InitializeComponent();
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			ModelTypeWizard parentModelTypeWizard = base.ParentModelTypeWizard;
			if (parentModelTypeWizard.TargetLibrary == null)
			{
				base.ForwardItem = parentModelTypeWizard.SelectLibraryPage;
			}
			else
			{
				base.ForwardItem = parentModelTypeWizard.SelectCategoryPage;
			}
			base.CanForward = true;
			foreach (IAEditCategories item in from x in ModelLibraryLoader.GetAllEditableLibraries()
				select x.UnamangedIAEditCategories)
			{
				ModelLibraryHelper.EnsureUserModelLibraryWritable(item);
			}
			if (parentModelTypeWizard.Mode == ModelTypeWizardMode.ModelType)
			{
				CanAppend = false;
			}
			else if (parentModelTypeWizard.TargetLibrary == null)
			{
				CanAppend = ModelLibraryHelper.CanAppendModelToApwnLibraries();
			}
			else
			{
				CanAppend = ModelLibraryHelper.CanAppendModelToUserModelLibrary(parentModelTypeWizard.TargetLibrary.UnamangedIAEditCategories);
			}
			if (parentModelTypeWizard.IsAppendOnly)
			{
				CanAdd = false;
			}
			else if (parentModelTypeWizard.TargetLibrary == null)
			{
				CanAdd = ModelLibraryHelper.CanAddModelToApwnLibraries();
			}
			else
			{
				CanAdd = ModelLibraryHelper.CanAddModelToUserModelLibrary(parentModelTypeWizard.TargetLibrary.UnamangedIAEditCategories);
			}
			if (!CanAdd && CanAppend)
			{
				IsAddChecked = false;
				IsAppendChecked = true;
			}
			base.OnEnter(previousItem, positiveDirection);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modeltypewizarditemwelcome.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		internal Delegate _CreateDelegate(Type delegateType, string handler)
		{
			return Delegate.CreateDelegate(delegateType, this, handler);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				radionButtonAdd = (System.Windows.Controls.RadioButton)target;
				break;
			case 2:
				radionButtonAppend = (System.Windows.Controls.RadioButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public enum ModelTypeWizardMode
	{
		ModelType,
		SingleModel,
		MultipleModels,
		Problem,
		Records
	}
	public class ModelTypeWizardRecordNode : NotifyPropertyChangedBase
	{
		private string _name;

		private string _displayname;

		private bool? _isChecked = false;

		private bool _isExpanded;

		private bool _preventUpdateParent;

		public string Name
		{
			get
			{
				if (string.IsNullOrEmpty(_name) && Reference != null)
				{
					return Reference.Name;
				}
				return _name;
			}
			set
			{
				_name = value;
			}
		}

		public string DisplayName
		{
			get
			{
				if (string.IsNullOrEmpty(_displayname) && Reference != null)
				{
					return Reference.DisplayName;
				}
				return _displayname;
			}
			set
			{
				_displayname = value;
			}
		}

		public bool? IsChecked
		{
			get
			{
				return _isChecked;
			}
			set
			{
				if (_isChecked != value)
				{
					_isChecked = value;
					OnIsCheckedChanged();
					OnPropertyChanged("IsChecked");
				}
			}
		}

		public bool IsEnabled { get; private set; }

		public bool IsExpanded
		{
			get
			{
				return _isExpanded;
			}
			set
			{
				if (_isExpanded != value)
				{
					_isExpanded = value;
					OnPropertyChanged("IsExpanded");
				}
			}
		}

		public RecordNode Reference { get; private set; }

		public ModelTypeWizardRecordNode Parent { get; private set; }

		public IList<ModelTypeWizardRecordNode> Children { get; private set; }

		public bool IsLeafNode => Children.Count == 0;

		public bool IsInitialized { get; private set; }

		public ModelTypeWizardRecordNode(RecordNode reference, ModelTypeWizardRecordNode parent = null)
		{
			if (reference == null)
			{
				throw new ArgumentNullException("reference");
			}
			Name = reference.Name;
			Reference = reference;
			Parent = parent;
			RefreshChildren();
			InitializeCheckedAndExpanded();
			if (!IsLeafNode)
			{
				OnChildIsCheckedChanged();
			}
			if (IsLeafNode)
			{
				IsEnabled = Reference.IsEnabled;
			}
			else
			{
				IsEnabled = Children.Count((ModelTypeWizardRecordNode x) => x.IsEnabled) > 0;
			}
			IsInitialized = true;
		}

		private void RefreshChildren()
		{
			if (Reference == null || Children != null)
			{
				return;
			}
			Children = new List<ModelTypeWizardRecordNode>();
			foreach (RecordNode child in Reference.Children)
			{
				Children.Add(new ModelTypeWizardRecordNode(child, this));
			}
		}

		private void InitializeCheckedAndExpanded()
		{
			if (Reference.IsChecked)
			{
				IsChecked = Reference.IsChecked;
				for (ModelTypeWizardRecordNode modelTypeWizardRecordNode = this; modelTypeWizardRecordNode != null; modelTypeWizardRecordNode = modelTypeWizardRecordNode.Parent)
				{
					modelTypeWizardRecordNode.IsExpanded = true;
				}
			}
		}

		protected void OnIsCheckedChanged()
		{
			if (!IsInitialized)
			{
				return;
			}
			if (IsChecked.HasValue)
			{
				foreach (ModelTypeWizardRecordNode child in Children)
				{
					if (child.IsEnabled)
					{
						child._preventUpdateParent = true;
						child.IsChecked = IsChecked.Value;
						child._preventUpdateParent = false;
					}
				}
			}
			if (Parent != null && !_preventUpdateParent)
			{
				Parent.OnChildIsCheckedChanged();
			}
		}

		protected virtual void OnChildIsCheckedChanged()
		{
			if (Children.Count((ModelTypeWizardRecordNode x) => x.IsChecked.HasValue && x.IsChecked.Value) == Children.Count)
			{
				IsChecked = true;
			}
			else if (Children.Count((ModelTypeWizardRecordNode x) => x.IsChecked.HasValue && !x.IsChecked.Value) == Children.Count)
			{
				IsChecked = false;
			}
			else
			{
				IsChecked = null;
			}
			if (IsInitialized && !_preventUpdateParent && Parent != null)
			{
				Parent.OnChildIsCheckedChanged();
			}
		}
	}
	public class MoveModeToOtherCategoryWindow : Window, IComponentConnector
	{
		public static readonly DependencyProperty SelectedCategoryProperty = DependencyProperty.Register("SelectedCategory", typeof(Category), typeof(MoveModeToOtherCategoryWindow), new FrameworkPropertyMetadata(OnSelectedCategoryPropertyChanged));

		internal System.Windows.Controls.GroupBox theGroupBox;

		internal System.Windows.Controls.ListBox theListBox;

		internal System.Windows.Controls.Button buttonOK;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public Category SelectedCategory
		{
			get
			{
				return (Category)GetValue(SelectedCategoryProperty);
			}
			set
			{
				SetValue(SelectedCategoryProperty, value);
			}
		}

		public ObservableCollection<Category> AvailableCategories { get; private set; }

		public MoveModeToOtherCategoryWindow(IEnumerable<Category> availableCategories)
		{
			if (availableCategories == null)
			{
				throw new ArgumentNullException("availableCategories");
			}
			AvailableCategories = new ObservableCollection<Category>(availableCategories);
			InitializeComponent();
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private static void OnSelectedCategoryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as MoveModeToOtherCategoryWindow).buttonOK.IsEnabled = e.NewValue != null;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/movemodetoothercategorywindow.xaml", UriKind.Relative);
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
				theGroupBox = (System.Windows.Controls.GroupBox)target;
				break;
			case 2:
				theListBox = (System.Windows.Controls.ListBox)target;
				break;
			case 3:
				buttonOK = (System.Windows.Controls.Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 4:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SimpleCategoryInfo : NotifyPropertyChangedBase
	{
		private bool _isInUse;

		private string _header;

		public bool IsInUse
		{
			get
			{
				return _isInUse;
			}
			set
			{
				if (_isInUse != value)
				{
					_isInUse = value;
					OnPropertyChanged("IsInUse");
				}
			}
		}

		public string Header
		{
			get
			{
				return _header;
			}
			set
			{
				if (_header != value)
				{
					_header = value;
					OnPropertyChanged("Header");
				}
			}
		}
	}
	public class ModelCategoriesManagerWindow : ApwnPanelControl, IComponentConnector, IStyleConnector
	{
		internal System.Windows.Controls.DataGrid theDataGrid;

		internal System.Windows.Controls.Button buttonUp;

		internal System.Windows.Controls.Button buttonDown;

		private bool _contentLoaded;

		private System.Windows.Size InitialSize => new System.Windows.Size(base.MinWidth, base.MinHeight);

		public IUnityContainer Container { get; private set; }

		public ObservableCollection<SimpleCategoryInfo> CategoryInfos { get; private set; }

		static ModelCategoriesManagerWindow()
		{
			CommandManager.RegisterClassCommandBinding(typeof(ModelCategoriesManagerWindow), new CommandBinding(ModelLibraryCommands.MoveUpCommand, MoveUpCommand_Executed, MoveUpCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(ModelCategoriesManagerWindow), new CommandBinding(ModelLibraryCommands.MoveDownCommand, MoveDownCommand_Executed, MoveDownCommand_CanExecute));
		}

		public ModelCategoriesManagerWindow(IUnityContainer container)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			Container = container;
			CategoryInfos = new ObservableCollection<SimpleCategoryInfo>();
			InitializeComponent();
		}

		public override void OnOpening(ScreenOpeningEventArgs args)
		{
			args.InitialWindowSize = InitialSize;
			base.OnOpening(args);
		}

		protected override void OnInitialized(EventArgs e)
		{
			Refresh();
			base.OnInitialized(e);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SelectedModelLibrariesChangedEvent>().Subscribe(OnSelectedModelLibrariesChanged);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Subscribe(OnUserModelLibraryUpdated);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelTypeWizardFinishedEvent>().Subscribe(OnModelTypeWizardFinished);
		}

		private void Refresh()
		{
			CategoryInfos.Clear();
			foreach (ModelCategoryData modelCategoriesDatum in ModelLibraryHelper.GetModelCategoriesData())
			{
				CategoryInfos.Add(new SimpleCategoryInfo
				{
					Header = modelCategoriesDatum.CategoryName,
					IsInUse = modelCategoriesDatum.IsInUse
				});
			}
		}

		private void MakeChanges()
		{
			ModelLibraryHelper.UpdateCategorySelection(CategoryInfos.Select((SimpleCategoryInfo x) => new ModelCategoryData
			{
				CategoryName = x.Header,
				IsInUse = x.IsInUse
			}));
			ModelLibraryHelper.SaveApwnLibraries();
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SelectedEditCategoriesChangedEvent>().Publish(new SelectedEditCategoriesChangedEventArgs());
		}

		private void OnSelectedModelLibrariesChanged(SelectedModelLibrariesChangedEventArgs args)
		{
			Refresh();
		}

		private void OnUserModelLibraryUpdated(UserModelLibraryUpdatedEventArgs args)
		{
			UserModelLibraryUpdatedMode action = args.Action;
			if ((uint)(action - 1) <= 2u)
			{
				Refresh();
			}
		}

		private void OnModelTypeWizardFinished(ModelTypeWizardFinishedEventArgs e)
		{
			Refresh();
		}

		private void checkBoxIsInUse_Click(object sender, RoutedEventArgs e)
		{
			if (base.IsLoaded)
			{
				System.Windows.Controls.CheckBox checkBox = sender as System.Windows.Controls.CheckBox;
				if (checkBox.Tag is SimpleCategoryInfo simpleCategoryInfo && simpleCategoryInfo.IsInUse != checkBox.IsChecked.Value)
				{
					simpleCategoryInfo.IsInUse = checkBox.IsChecked.Value;
					MakeChanges();
				}
			}
		}

		private static void MoveUpCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ModelCategoriesManagerWindow obj = sender as ModelCategoriesManagerWindow;
			int selectedIndex = obj.theDataGrid.SelectedIndex;
			obj.CategoryInfos.Move(selectedIndex, selectedIndex - 1);
			obj.MakeChanges();
		}

		private static void MoveUpCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			ModelCategoriesManagerWindow modelCategoriesManagerWindow = sender as ModelCategoriesManagerWindow;
			e.CanExecute = modelCategoriesManagerWindow.theDataGrid.SelectedIndex > 0;
		}

		private static void MoveDownCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ModelCategoriesManagerWindow obj = sender as ModelCategoriesManagerWindow;
			int selectedIndex = obj.theDataGrid.SelectedIndex;
			obj.CategoryInfos.Move(selectedIndex, selectedIndex + 1);
			obj.MakeChanges();
		}

		private static void MoveDownCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			ModelCategoriesManagerWindow modelCategoriesManagerWindow = sender as ModelCategoriesManagerWindow;
			e.CanExecute = modelCategoriesManagerWindow.theDataGrid.SelectedIndex >= 0 && modelCategoriesManagerWindow.theDataGrid.SelectedIndex < modelCategoriesManagerWindow.theDataGrid.Items.Count - 1;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modelcategoriesmanagerwindow.xaml", UriKind.Relative);
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
				theDataGrid = (System.Windows.Controls.DataGrid)target;
				break;
			case 3:
				buttonUp = (System.Windows.Controls.Button)target;
				break;
			case 4:
				buttonDown = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				((System.Windows.Controls.CheckBox)target).Click += checkBoxIsInUse_Click;
			}
		}
	}
	public class ModelLibrariesManagerWindow : ApwnPanelControl, IComponentConnector, IStyleConnector
	{
		private static readonly Dictionary<string, string> _editorPaneNames = new Dictionary<string, string>();

		internal System.Windows.Controls.DataGrid theDataGrid;

		internal System.Windows.Controls.Button buttonNew;

		internal System.Windows.Controls.Button buttonImport;

		private bool _contentLoaded;

		private System.Windows.Size InitialSize => new System.Windows.Size(base.MinWidth, 300.0);

		public IUnityContainer Container { get; private set; }

		public ObservableCollection<UserModelLibrary> UserModelLibraries { get; private set; }

		public ModelLibrariesManagerWindow(IUnityContainer container)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			Container = container;
			UserModelLibraries = new ObservableCollection<UserModelLibrary>();
			InitializeComponent();
		}

		protected override void OnInitialized(EventArgs e)
		{
			Refresh();
			base.OnInitialized(e);
		}

		public override void OnOpening(ScreenOpeningEventArgs args)
		{
			args.InitialWindowSize = InitialSize;
			base.OnOpening(args);
		}

		private void Refresh()
		{
			UserModelLibraries.Clear();
			foreach (UserModelLibrary allUserModelLibrary in ModelLibraryLoader.GetAllUserModelLibraries())
			{
				UserModelLibraries.Add(allUserModelLibrary);
			}
		}

		private void MakeChanges()
		{
			if (ModelLibraryHelper.UpdateLibrarySelection(from x in UserModelLibraries
				where x.IsInUse
				select x.DisplayName))
			{
				ModelLibraryHelper.SaveApwnLibraries();
				Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SelectedModelLibrariesChangedEvent>().Publish(new SelectedModelLibrariesChangedEventArgs());
			}
			else
			{
				MMMessageBox.Show(ModelLibraryResources.ManagerWindowMakeChangeErrorMessage, ModelLibraryResources.ModelLibraryMakingChangeErrorTitle);
			}
		}

		private string HandleEditorPaneName(string displayName)
		{
			if (!_editorPaneNames.ContainsKey(displayName))
			{
				string value = "ModelLibraryEditor_PaneName_" + _editorPaneNames.Count;
				_editorPaneNames.Add(displayName, value);
			}
			return _editorPaneNames[displayName];
		}

		private void checkBoxIsInUse_Click(object sender, RoutedEventArgs e)
		{
			if (base.IsLoaded)
			{
				System.Windows.Controls.CheckBox checkBox = sender as System.Windows.Controls.CheckBox;
				if (checkBox.Tag is UserModelLibrary userModelLibrary && userModelLibrary.IsInUse != checkBox.IsChecked.Value)
				{
					userModelLibrary.IsInUse = checkBox.IsChecked.Value;
					MakeChanges();
				}
			}
		}

		private void buttonViewDetail_Click(object sender, RoutedEventArgs e)
		{
			if ((sender as System.Windows.Controls.Button).Tag is UserModelLibrary { DisplayName: var displayName } userModelLibrary)
			{
				Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
				{
					PaneName = HandleEditorPaneName(displayName),
					ScreenFactoryKey = "ModelLibraryEditorScreenFactoryKey",
					InitialLocation = ScreenLocation.DockableFloating,
					ScreenSubject = new ModelLibraryEditorScreenSubject
					{
						ModelLibraryDisplayName = displayName,
						ModelLibraryLocation = userModelLibrary.Location,
						ModelLibraryIsBuiltIn = userModelLibrary.IsBuiltIn,
						ModelLibraryIsInUse = userModelLibrary.IsInUse
					}
				});
			}
		}

		private void buttonNew_Click(object sender, RoutedEventArgs e)
		{
			if (base.UnityContainer.Resolve<IModelLibraryPresenter>(Array.Empty<ResolverOverride>()).ShowAddNewLibraryWindow())
			{
				Refresh();
			}
		}

		private void buttonImport_Click(object sender, RoutedEventArgs e)
		{
			Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog
			{
				RestoreDirectory = true,
				Filter = ModelLibraryResources.ModelLibraryFileFilter + " (*.apm)|*.apm|" + ApwnResources.FileType_All_Files + " (*.*)|*.*",
				Title = ModelLibraryResources.ModelLibraryImportWindowTitle
			};
			bool? flag = openFileDialog.ShowDialog(Window.GetWindow(this));
			if (!flag.HasValue || !flag.Value)
			{
				return;
			}
			string displayName = null;
			string fileName = openFileDialog.FileName;
			int modelLibraryDisplayName = ModelLibraryHelper.GetModelLibraryDisplayName(fileName, out displayName);
			if (modelLibraryDisplayName > 0)
			{
				if (ModelLibraryHelper.IsDisplayNameReserved(displayName))
				{
					System.Windows.MessageBox.Show(string.Format(ModelLibraryResources.ReserveModelLibraryName, MMVersionHelper.MVGetI18nProductNameM(), displayName), ModelLibraryResources.ModelLibraryImportingErrorTitle);
					return;
				}
				if (UserModelLibraries.FirstOrDefault((UserModelLibrary x) => string.Equals(displayName, x.DisplayName, StringComparison.CurrentCultureIgnoreCase)) == null)
				{
					ModelLibraryHelper.RegisterModelLibrary(displayName, fileName);
					Refresh();
					theDataGrid.SelectedItem = UserModelLibraries.FirstOrDefault((UserModelLibrary x) => string.Equals(displayName, x.DisplayName, StringComparison.CurrentCultureIgnoreCase));
					return;
				}
				string modelLibraryFilePath = ModelLibraryHelper.GetModelLibraryFilePath(displayName);
				if (!string.IsNullOrEmpty(modelLibraryFilePath) && !string.Equals(fileName, modelLibraryFilePath, StringComparison.OrdinalIgnoreCase))
				{
					string messageBoxText = string.Format(ModelLibraryResources.ManagerWindowBrowseButtonFileExisting, displayName);
					if (MMMessageBox.Show(Window.GetWindow(this), messageBoxText, ModelLibraryResources.ManagerWindowTitle, MMMessageBoxButton.YesNo) == MMMessageBoxResult.No)
					{
						return;
					}
					ModelLibraryHelper.UnregisterModelLibrary(displayName);
					ModelLibraryHelper.RegisterModelLibrary(displayName, fileName);
				}
				Refresh();
				theDataGrid.SelectedItem = UserModelLibraries.FirstOrDefault((UserModelLibrary x) => string.Equals(displayName, x.DisplayName, StringComparison.CurrentCultureIgnoreCase));
			}
			else if (modelLibraryDisplayName == -1)
			{
				MMMessageBox.Show(ModelLibraryResources.ManagerWindowBrowseButtonFileLocked, ModelLibraryResources.ModelLibraryImportingErrorTitle);
			}
			else
			{
				MMMessageBox.Show(ModelLibraryResources.ManagerWindowBrowseButtonFileInvalid, ModelLibraryResources.ModelLibraryImportingErrorTitle);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibrariesmanagerwindow.xaml", UriKind.Relative);
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
				theDataGrid = (System.Windows.Controls.DataGrid)target;
				break;
			case 4:
				buttonNew = (System.Windows.Controls.Button)target;
				buttonNew.Click += buttonNew_Click;
				break;
			case 5:
				buttonImport = (System.Windows.Controls.Button)target;
				buttonImport.Click += buttonImport_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 2:
				((System.Windows.Controls.CheckBox)target).Click += checkBoxIsInUse_Click;
				break;
			case 3:
				((System.Windows.Controls.Button)target).Click += buttonViewDetail_Click;
				break;
			}
		}
	}
	public class ModelLibraryCreateNewWindow : Window, IComponentConnector
	{
		internal System.Windows.Controls.TextBox theLibraryName;

		internal System.Windows.Controls.TextBox theFilePath;

		internal System.Windows.Controls.Button buttonBrowse;

		internal System.Windows.Controls.Button buttonOK;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public string DisplayName => theLibraryName.Text.Trim();

		public string FilePath
		{
			get
			{
				string text = theFilePath.Text.Trim();
				if (string.IsNullOrWhiteSpace(text))
				{
					return text;
				}
				if (text.Contains(System.IO.Path.DirectorySeparatorChar) && text.Contains(":"))
				{
					return text;
				}
				return $"{Directory.GetCurrentDirectory()}{System.IO.Path.DirectorySeparatorChar}{text}";
			}
		}

		public string DefaultBrowserDirectory { get; set; }

		public ModelLibraryCreateNewWindow()
		{
			InitializeComponent();
			base.Loaded += ModelLibraryCreateNewWindow_Loaded;
		}

		private void ModelLibraryCreateNewWindow_Loaded(object sender, RoutedEventArgs e)
		{
			theLibraryName.Focus();
		}

		private void theLibraryName_TextChanged(object sender, TextChangedEventArgs e)
		{
			buttonOK.IsEnabled = !string.IsNullOrWhiteSpace(DisplayName) && !string.IsNullOrWhiteSpace(FilePath);
		}

		private void theFilePath_TextChanged(object sender, TextChangedEventArgs e)
		{
			buttonOK.IsEnabled = !string.IsNullOrWhiteSpace(DisplayName) && !string.IsNullOrWhiteSpace(FilePath);
		}

		private void buttonBrowse_Click(object sender, RoutedEventArgs e)
		{
			System.Windows.Forms.SaveFileDialog saveFileDialog = new System.Windows.Forms.SaveFileDialog
			{
				Filter = ModelLibraryResources.ModelLibraryFileFilter + " (*.apm)|*.apm|" + ApwnResources.FileType_All_Files + " (*.*)|*.*",
				CheckFileExists = false,
				CheckPathExists = true,
				FileName = theLibraryName.Text,
				Title = ModelLibraryResources.BrowseWindowTitle,
				InitialDirectory = (Directory.Exists(theFilePath.Text) ? theFilePath.Text : DefaultBrowserDirectory),
				RestoreDirectory = true
			};
			if (saveFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
			{
				theFilePath.Text = saveFileDialog.FileName;
			}
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			if (string.IsNullOrWhiteSpace(DisplayName) || string.IsNullOrWhiteSpace(FilePath))
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowInputIncompleted);
				return;
			}
			if (ModelLibraryHelper.IsDisplayNameReserved(DisplayName))
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowNameReserved);
				return;
			}
			if (ModelLibraryHelper.IsDisplayNameUsed(DisplayName))
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowNameUsed);
				return;
			}
			if (FilePath.ToCharArray().Intersect(System.IO.Path.GetInvalidPathChars()).Count() > 0)
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowFilePathInvalid);
				return;
			}
			string fileName = System.IO.Path.GetFileName(FilePath);
			if (string.IsNullOrWhiteSpace(fileName) || fileName.ToCharArray().Intersect(System.IO.Path.GetInvalidFileNameChars()).Count() > 0)
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowFilePathInvalid);
				return;
			}
			string directoryName = System.IO.Path.GetDirectoryName(FilePath);
			if (string.IsNullOrWhiteSpace(directoryName) || directoryName.ToCharArray().Intersect(System.IO.Path.GetInvalidPathChars()).Count() > 0)
			{
				MMMessageBox.Show(ModelLibraryResources.CreateNewWindowFilePathInvalid);
				return;
			}
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibrarycreatenewwindow.xaml", UriKind.Relative);
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
				theLibraryName = (System.Windows.Controls.TextBox)target;
				theLibraryName.TextChanged += theLibraryName_TextChanged;
				break;
			case 2:
				theFilePath = (System.Windows.Controls.TextBox)target;
				theFilePath.TextChanged += theFilePath_TextChanged;
				break;
			case 3:
				buttonBrowse = (System.Windows.Controls.Button)target;
				buttonBrowse.Click += buttonBrowse_Click;
				break;
			case 4:
				buttonOK = (System.Windows.Controls.Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 5:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ModelLibraryEditorScreen : ApwnPanelControl, IComponentConnector
	{
		private static readonly Dictionary<string, string> _iconEditorPaneNames = new Dictionary<string, string>();

		private static readonly Dictionary<string, string> _configurationEditorPaneNames = new Dictionary<string, string>();

		public const string DragDropDataFormat = "Model Library Editor Type Format";

		private const string StreamCategoryName = "streams";

		private static string[] EditableUserNames = new string[2] { "USER2", "USER3" };

		private const int DragValidLength = 10;

		private readonly Dictionary<IAModelIcon, UIElement> _defaultDrawings = new Dictionary<IAModelIcon, UIElement>();

		private readonly Dictionary<IAModelIcon, UIElement> _checkedDrawings = new Dictionary<IAModelIcon, UIElement>();

		private static readonly System.Windows.Size DefaultSize = new System.Windows.Size(800.0, 160.0);

		private int _loadedTimes;

		private System.Windows.Point _mouseDownPosition;

		private Model _mouseDownModel;

		private IAEditCategories _currentEditCategories;

		internal CommandBinding CreateNewCategory;

		internal CommandBinding DeleteCurrentCategory;

		internal CommandBinding RenameCurrentCategory;

		internal CommandBinding ReorderCategories;

		internal CommandBinding ReorderModelsInCurrentCategory;

		internal CommandBinding DeleteCurrentModel;

		internal CommandBinding RenameCurrentModel;

		internal CommandBinding MoveCurrentModel;

		internal CommandBinding CopyCurrentModel;

		internal CommandBinding EditDescriptionForCurrentModel;

		internal CommandBinding EditUserConfiguration;

		internal CommandBinding ClearUserConfiguration;

		internal CommandBinding EditCurrentIcon;

		internal CommandBinding CreateNewIcon;

		internal CommandBinding DeleteCurrentIcon;

		internal CommandBinding ReorderIconsInCurrentModel;

		internal BlockTableControl theBlockTableControl;

		internal System.Windows.Controls.Button btnSave;

		private bool _contentLoaded;

		public IUnityContainer Container { get; private set; }

		public ModelLibraryEditorScreenSubject LibraryInfo => base.ScreenSubject as ModelLibraryEditorScreenSubject;

		public bool IsEditable
		{
			get
			{
				if (!LibraryInfo.ModelLibraryIsBuiltIn)
				{
					return _currentEditCategories != null;
				}
				return false;
			}
		}

		public ModelLibraryEditorScreen(IUnityContainer container)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			Container = container;
			InitializeComponent();
			theBlockTableControl.AddHandler(DropdownButton.PopupOpenedEvent, new RoutedEventHandler(DropdownButton_PopupOpened));
			theBlockTableControl.SelectedIconChanged += theBlockTableControl_SelectedIconChanged;
			theBlockTableControl.CurrentCategoryChanged += theBlockTableControl_CurrentCategoryChanged;
			theBlockTableControl.PreviewMouseLeftButtonDown += theBlockTableControl_PreviewMouseLeftButtonDown;
			theBlockTableControl.PreviewMouseMove += theBlockTableControl_PreviewMouseMove;
			theBlockTableControl.PreviewMouseLeftButtonUp += theBlockTableControl_PreviewMouseLeftButtonUp;
			theBlockTableControl.ContextMenuOpening += theBlockTableControl_ContextMenuOpening;
			theBlockTableControl.DragEnter += theBlockTableControl_DragEnter;
			theBlockTableControl.Drop += theBlockTableControl_Drop;
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelTypeWizardFinishedEvent>().Subscribe(OnModelTypeWizardFinished);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Subscribe(OnUserModelLibraryUpdated);
			base.Loaded += ModelLibraryEditorScreen_Loaded;
		}

		public override void OnOpening(ScreenOpeningEventArgs args)
		{
			args.InitialWindowSize = DefaultSize;
			base.OnOpening(args);
		}

		protected override void OnClosing(CancelEventArgs args)
		{
			if (IsEditable)
			{
				SaveUserModelLibraryChange();
			}
			base.OnClosing(args);
		}

		public static string CreateNewCategoryInEditCategories(IAEditCategories editCategories, Window dialogOwner)
		{
			if (editCategories == null)
			{
				throw new ArgumentNullException("editCategories");
			}
			EnterNewNameWindow enterNewNameWindow = new EnterNewNameWindow(ModelLibraryResources.EnterNewCategoryNameWindowNameLabel, null, 63L)
			{
				Owner = dialogOwner
			};
			bool? flag = enterNewNameWindow.ShowDialog();
			if (flag.HasValue && flag.Value)
			{
				string categoryName = enterNewNameWindow.NewName;
				if (string.Equals(categoryName, "streams", StringComparison.CurrentCultureIgnoreCase))
				{
					MMMessageBox.Show(ModelLibraryResources.EnterNewCategoryNameWindowNoStreamsCategoryName, ModelLibraryResources.EnterNewCategoryNameWindowInvalidCategoryNameTitle);
					return null;
				}
				if (ModelLibraryLoader.GetManagedCategories(editCategories, includeUncategorized: false, includeEmptyCategories: true).FirstOrDefault((Category x) => string.Equals(categoryName, x.Header.ToString(), StringComparison.CurrentCultureIgnoreCase)) != null)
				{
					MMMessageBox.Show(string.Format(ModelLibraryResources.EnterNewCategoryNameWindowNewCategoryNameExists, categoryName), ModelLibraryResources.EnterNewCategoryNameWindowInvalidCategoryNameTitle);
					return null;
				}
				if (EnsureEditCategoriesWritable(editCategories) && ModelLibraryHelper.AddNewCategory(editCategories, categoryName))
				{
					return categoryName;
				}
			}
			return null;
		}

		public static void ClearUncategorizedModelTypes(IAEditCategories iaEditCategories)
		{
			if (iaEditCategories == null)
			{
				throw new ArgumentNullException("iaEditCategories");
			}
			IACategory iACategory = ModelLibraryHelper.FindCategory(iaEditCategories, ModelLibraryResources.EditorScreenUncategorizedTab);
			if (iACategory == null)
			{
				return;
			}
			foreach (string item in (from x in ModelLibraryLoader.GetManagedModels(iACategory)
				select x.Header as string).ToList())
			{
				ModelLibraryHelper.RemoveModelType(iaEditCategories, item);
			}
		}

		private void Refresh(bool clearDrawingCache = false)
		{
			if (clearDrawingCache)
			{
				_defaultDrawings.Clear();
				_checkedDrawings.Clear();
			}
			Category currentCategory = theBlockTableControl.CurrentCategory;
			AspenTech.AspenPlus.ModelLibrary.Controls.Icon selectedIcon = theBlockTableControl.SelectedIcon;
			CategoryCollection categoryCollection = new CategoryCollection();
			_currentEditCategories = ModelLibraryHelper.GetIAEditCategories(LibraryInfo.ModelLibraryDisplayName);
			if (_currentEditCategories != null)
			{
				foreach (Category managedCategory in ModelLibraryLoader.GetManagedCategories(_currentEditCategories, includeUncategorized: false, includeEmptyCategories: true))
				{
					categoryCollection.Add(managedCategory);
				}
			}
			if (_currentEditCategories != null)
			{
				ClearUncategorizedModelTypes(_currentEditCategories);
			}
			theBlockTableControl.Categories = categoryCollection;
			UpdateBlockTableControlSelection(selectedIcon);
			UpdateBlockTableControlCurrentCategory(currentCategory);
		}

		private void UpdateBlockTableControlSelection(AspenTech.AspenPlus.ModelLibrary.Controls.Icon oldSelectedIcon)
		{
			if (oldSelectedIcon == null)
			{
				return;
			}
			foreach (Category category in theBlockTableControl.Categories)
			{
				foreach (Model model in category.Models)
				{
					foreach (AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon in model.Icons)
					{
						if (icon.Data == oldSelectedIcon.Data)
						{
							theBlockTableControl.SelectedIcon = icon;
							return;
						}
					}
				}
			}
		}

		private void UpdateBlockTableControlCurrentCategory(Category oldCurrentCategory)
		{
			if (oldCurrentCategory != null)
			{
				foreach (Category category in theBlockTableControl.Categories)
				{
					if (oldCurrentCategory.Data == category.Data)
					{
						theBlockTableControl.CurrentCategory = category;
						return;
					}
				}
			}
			theBlockTableControl.CurrentCategory = theBlockTableControl.Categories.FirstOrDefault();
		}

		private void LoadIconsForCategory(Category category)
		{
			if (category == null)
			{
				return;
			}
			foreach (Model model in category.Models)
			{
				if (model.SelectedIcon != null && model.SelectedIcon.DrawingElement == null)
				{
					IAModelIcon modelIcon = model.SelectedIcon.Data as IAModelIcon;
					model.SelectedIcon.DrawingElement = GetDefaultDrawing(modelIcon);
				}
			}
		}

		private UIElement GetDefaultDrawing(IAModelIcon modelIcon)
		{
			if (modelIcon != null)
			{
				if (!_defaultDrawings.ContainsKey(modelIcon))
				{
					_defaultDrawings.Add(modelIcon, ModelLibraryLoader.CreateDrawingElement(modelIcon, theBlockTableControl.DefaultButtonBackground as SolidColorBrush));
				}
				return _defaultDrawings[modelIcon];
			}
			return null;
		}

		private UIElement GetCheckedDrawing(IAModelIcon modelIcon)
		{
			if (modelIcon != null)
			{
				if (!_checkedDrawings.ContainsKey(modelIcon))
				{
					_checkedDrawings.Add(modelIcon, ModelLibraryLoader.CreateDrawingElement(modelIcon, theBlockTableControl.CheckedButtonBackground as SolidColorBrush));
				}
				return _checkedDrawings[modelIcon];
			}
			return null;
		}

		private IEnumerable CreateCategoryMenuItems()
		{
			return new object[6]
			{
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.CreateNewCategory,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.DeleteCurrentCategory,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.RenameCurrentCategory,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.ReorderCategories,
					CommandTarget = this
				},
				new Separator(),
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.ReorderModelsInCurrentCategory,
					CommandTarget = this
				}
			};
		}

		private IEnumerable CreateModelMenuItems()
		{
			return new object[14]
			{
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.DeleteCurrentModel,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.RenameCurrentModel,
					CommandTarget = this
				},
				new Separator(),
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.MoveCurrentModel,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.CopyCurrentModel,
					CommandTarget = this
				},
				new Separator(),
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.EditCurrentIcon,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.CreateNewIcon,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.DeleteCurrentIcon,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.ReorderIconsInCurrentModel,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.EditDescriptionForCurrentModel,
					CommandTarget = this
				},
				new Separator(),
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.EditUserConfiguration,
					CommandTarget = this
				},
				new System.Windows.Controls.MenuItem
				{
					Command = ModelLibraryCommands.ClearUserConfiguration,
					CommandTarget = this
				}
			};
		}

		private bool IsDraggedEventArgsAllowed(System.Windows.DragEventArgs e)
		{
			if (e.Data.GetDataPresent("Model Library Editor Type Format") && e.Data.GetData("Model Library Editor Type Format") is Model model && !theBlockTableControl.Categories.Contains(model.Parent))
			{
				return true;
			}
			return false;
		}

		private bool EnsureUserModelLibraryWritable()
		{
			return EnsureEditCategoriesWritable(_currentEditCategories);
		}

		public static bool EnsureEditCategoriesWritable(IAEditCategories editCategories)
		{
			if (!ModelLibraryHelper.EnsureUserModelLibraryWritable(editCategories))
			{
				MMMessageBox.Show(ModelLibraryResources.EditorScreenFailedMakeWritable, ModelLibraryResources.EditorScreenFailedMakeWritableTitle);
				return false;
			}
			return true;
		}

		private void BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode actionMode)
		{
			if (LibraryInfo.ModelLibraryIsInUse)
			{
				ModelLibraryHelper.RefreshApwnLibraries();
				base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UserModelLibraryUpdatedEvent>().Publish(new UserModelLibraryUpdatedEventArgs(_currentEditCategories, actionMode));
			}
		}

		private void SaveUserModelLibraryChange()
		{
			if (_currentEditCategories != null)
			{
				ModelLibraryHelper.SaveUserModelLibraryChanges(_currentEditCategories);
			}
		}

		private UserModelLibrary CloneUserModelLibrary()
		{
			return new UserModelLibrary
			{
				DisplayName = LibraryInfo.ModelLibraryDisplayName,
				IsBuiltIn = LibraryInfo.ModelLibraryIsBuiltIn,
				IsInUse = LibraryInfo.ModelLibraryIsInUse,
				Location = LibraryInfo.ModelLibraryLocation
			};
		}

		private void OpenModelTypeWizard(Model sourceModel, IAEditCategories targetEditCategories)
		{
			ModelTypeWizard modelTypeWizard = new ModelTypeWizard(sourceModel.Data as IAModelType, base.UnityContainer, CloneUserModelLibrary())
			{
				Owner = Window.GetWindow(this)
			};
			if (modelTypeWizard.SelectCategoryPage != null)
			{
				modelTypeWizard.SelectCategoryPage.SelectedCategory = theBlockTableControl.CurrentCategory;
			}
			modelTypeWizard.ShowDialog();
		}

		private void OpenIconEditorScreen(string sourceModel, string sourceIcon)
		{
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
			{
				PaneName = HandleIconEditorPaneName(sourceModel, sourceIcon),
				ScreenFactoryKey = "ModelLibraryIconEditorScreenFactoryKey",
				ScreenSubject = new ModelLibraryIconEditorScreenSubject
				{
					ModelLibraryDisplayName = LibraryInfo.ModelLibraryDisplayName,
					ModelTypeName = sourceModel,
					IconName = sourceIcon
				},
				InitialLocation = ScreenLocation.TabbedDocument
			});
		}

		private string HandleIconEditorPaneName(string modelTypeName, string iconName)
		{
			string key = LibraryInfo.ModelLibraryDisplayName + "_" + modelTypeName + "_" + iconName;
			if (!_iconEditorPaneNames.ContainsKey(key))
			{
				string value = "IconEditor_PaneName_" + _iconEditorPaneNames.Count;
				_iconEditorPaneNames.Add(key, value);
			}
			return _iconEditorPaneNames[key];
		}

		private string HandleConfigurationEditorPaneName(string modelTypeName)
		{
			string key = LibraryInfo.ModelLibraryDisplayName + "_" + modelTypeName;
			if (!_configurationEditorPaneNames.ContainsKey(key))
			{
				string value = "UserConfigurationEditor_PaneName_" + _configurationEditorPaneNames.Count;
				_configurationEditorPaneNames.Add(key, value);
			}
			return _configurationEditorPaneNames[key];
		}

		private void DropdownButton_PopupOpened(object sender, RoutedEventArgs e)
		{
			if (!(e.OriginalSource is DropdownButton dropdownButton))
			{
				return;
			}
			foreach (object item in (IEnumerable)dropdownButton.Items)
			{
				if (item is AspenTech.AspenPlus.ModelLibrary.Controls.Icon { DrawingElement: null } icon)
				{
					IAModelIcon modelIcon = icon.Data as IAModelIcon;
					icon.DrawingElement = GetDefaultDrawing(modelIcon);
				}
			}
		}

		private void theBlockTableControl_SelectedIconChanged(object sender, RoutedPropertyChangedEventArgs<AspenTech.AspenPlus.ModelLibrary.Controls.Icon> e)
		{
			if (e.OldValue != null)
			{
				e.OldValue.DrawingElement = GetDefaultDrawing(e.OldValue.Data as IAModelIcon);
			}
			if (e.NewValue != null)
			{
				e.NewValue.DrawingElement = GetCheckedDrawing(e.NewValue.Data as IAModelIcon);
				ModelLibraryLoader.SetCurrentIcon(theBlockTableControl.CurrentCategory, e.NewValue);
			}
		}

		private void theBlockTableControl_CurrentCategoryChanged(object sender, RoutedPropertyChangedEventArgs<Category> e)
		{
			if (e.NewValue != null)
			{
				LoadIconsForCategory(e.NewValue);
			}
		}

		private void theBlockTableControl_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			DropdownButton mouseDropdownButton = e.GetMouseDropdownButton(theBlockTableControl);
			if (mouseDropdownButton != null && mouseDropdownButton.Tag is Model mouseDownModel)
			{
				_mouseDownModel = mouseDownModel;
				_mouseDownPosition = e.GetPosition(theBlockTableControl);
			}
		}

		private void theBlockTableControl_PreviewMouseMove(object sender, System.Windows.Input.MouseEventArgs e)
		{
			if (e.LeftButton == MouseButtonState.Pressed && _mouseDownModel != null && !string.Equals(_mouseDownModel.Parent.Header.ToString(), "streams", StringComparison.CurrentCultureIgnoreCase) && (e.GetPosition(theBlockTableControl) - _mouseDownPosition).Length >= 10.0)
			{
				System.Windows.DataObject dataObject = new System.Windows.DataObject();
				dataObject.SetData("Model Library Editor Type Format", _mouseDownModel);
				DragDrop.DoDragDrop(theBlockTableControl, dataObject, System.Windows.DragDropEffects.Copy | System.Windows.DragDropEffects.Move);
				_mouseDownModel = null;
			}
		}

		private void theBlockTableControl_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			if (_mouseDownModel != null)
			{
				_mouseDownModel = null;
			}
		}

		private void theBlockTableControl_ContextMenuOpening(object sender, ContextMenuEventArgs e)
		{
			if (!IsEditable)
			{
				return;
			}
			DropdownButton ancestor = Extensions.GetAncestor<DropdownButton>(e.OriginalSource as DependencyObject, theBlockTableControl);
			if (ancestor != null)
			{
				theBlockTableControl.SelectedIcon = ancestor.SelectedItem as AspenTech.AspenPlus.ModelLibrary.Controls.Icon;
				System.Windows.Controls.ContextMenu contextMenu = new System.Windows.Controls.ContextMenu();
				foreach (object item in CreateModelMenuItems())
				{
					contextMenu.Items.Add(item);
				}
				contextMenu.PlacementTarget = ancestor;
				contextMenu.IsOpen = true;
				return;
			}
			System.Windows.Controls.ContextMenu contextMenu2 = new System.Windows.Controls.ContextMenu();
			foreach (object item2 in CreateCategoryMenuItems())
			{
				contextMenu2.Items.Add(item2);
			}
			contextMenu2.PlacementTarget = this;
			contextMenu2.IsOpen = true;
		}

		private void theBlockTableControl_DragEnter(object sender, System.Windows.DragEventArgs e)
		{
			if (!IsDraggedEventArgsAllowed(e))
			{
				e.Effects = System.Windows.DragDropEffects.None;
			}
		}

		private void theBlockTableControl_Drop(object sender, System.Windows.DragEventArgs e)
		{
			if (IsDraggedEventArgsAllowed(e) && e.Data.GetData("Model Library Editor Type Format") is Model model && !string.Equals(model.Parent.Header.ToString(), "streams", StringComparison.CurrentCultureIgnoreCase))
			{
				OpenModelTypeWizard(model, _currentEditCategories);
			}
		}

		private void OnModelTypeWizardFinished(ModelTypeWizardFinishedEventArgs e)
		{
			if (e.AffectedEditCategories == _currentEditCategories)
			{
				Refresh();
			}
		}

		private void OnUserModelLibraryUpdated(UserModelLibraryUpdatedEventArgs e)
		{
			if (e.AffectedEditCategories == _currentEditCategories)
			{
				Refresh(e.Action == UserModelLibraryUpdatedMode.EditCurrentIcon);
			}
		}

		private void ModelLibraryEditorScreen_Loaded(object sender, RoutedEventArgs e)
		{
			_loadedTimes++;
			if (_loadedTimes != 1 || LibraryInfo == null)
			{
				return;
			}
			if (LibraryInfo.ModelLibraryIsBuiltIn)
			{
				base.Header = ModelLibraryResources.LibraryViewerWindowTitle;
			}
			else
			{
				base.Header = ModelLibraryResources.LibraryEditorWindowTitle;
			}
			if (!string.IsNullOrEmpty(LibraryInfo.ModelLibraryDisplayName))
			{
				Refresh();
				base.Header = LibraryInfo.ModelLibraryDisplayName + " - " + base.Header;
				if (IsEditable)
				{
					theBlockTableControl.AllowDrop = true;
				}
			}
			if (LibraryInfo.ModelLibraryIsBuiltIn)
			{
				btnSave.Visibility = Visibility.Collapsed;
			}
		}

		private void CreateNewCategory_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			string newCategoryName = CreateNewCategoryInEditCategories(_currentEditCategories, Window.GetWindow(this));
			if (!string.IsNullOrEmpty(newCategoryName))
			{
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.CreateNewCategory);
				Category category = theBlockTableControl.Categories.FirstOrDefault((Category x) => string.Equals(newCategoryName, x.Header.ToString(), StringComparison.CurrentCultureIgnoreCase));
				if (category != null)
				{
					theBlockTableControl.CurrentCategory = category;
				}
				SaveUserModelLibraryChange();
			}
		}

		private void CreateNewCategory_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = true;
		}

		private void DeleteCurrentCategory_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			Category currentCategory = theBlockTableControl.CurrentCategory;
			if (MMMessageBox.Show(string.Format(ModelLibraryResources.EditorScreenCheckDeleteCategory, currentCategory.Header.ToString()), ModelLibraryResources.EditorScreenCheckDeleteCategoryTitle, MMMessageBoxButton.YesNo) != MMMessageBoxResult.Yes || !EnsureUserModelLibraryWritable())
			{
				return;
			}
			IACategory pCategory = currentCategory.Data as IACategory;
			foreach (string item in currentCategory.Models.Select((Model x) => x.Header as string).ToList())
			{
				ModelLibraryHelper.RemoveModelType(_currentEditCategories, item);
			}
			_currentEditCategories.RemoveCategory(pCategory);
			SaveUserModelLibraryChange();
			BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.DeleteCurrentCategory);
		}

		private void DeleteCurrentCategory_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.CurrentCategory != null && theBlockTableControl.CurrentCategory.Data != null && !object.Equals(theBlockTableControl.CurrentCategory.Header, ModelLibraryResources.EditorScreenUncategorizedTab);
		}

		private void RenameCurrentCategory_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			Category currentCategory = theBlockTableControl.CurrentCategory;
			string text = currentCategory.Header.ToString();
			EnterNewNameWindow enterNewNameWindow = new EnterNewNameWindow(ModelLibraryResources.EnterNewCategoryNameWindowNameLabel, text, 63L)
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = enterNewNameWindow.ShowDialog();
			if (!flag.HasValue || !flag.Value)
			{
				return;
			}
			string categoryName = enterNewNameWindow.NewName;
			if (string.Equals(categoryName, "streams", StringComparison.CurrentCultureIgnoreCase))
			{
				MMMessageBox.Show(ModelLibraryResources.EnterNewCategoryNameWindowNoStreamsCategoryName, ModelLibraryResources.EnterNewCategoryNameWindowInvalidCategoryNameTitle);
			}
			else if (!string.Equals(categoryName, text, StringComparison.CurrentCultureIgnoreCase))
			{
				if (theBlockTableControl.Categories.FirstOrDefault((Category x) => string.Equals(categoryName, x.Header.ToString(), StringComparison.CurrentCultureIgnoreCase)) != null)
				{
					MMMessageBox.Show(string.Format(ModelLibraryResources.EnterNewCategoryNameWindowNewCategoryNameExists, categoryName), ModelLibraryResources.EnterNewCategoryNameWindowInvalidCategoryNameTitle);
				}
				else if (EnsureUserModelLibraryWritable() && ModelLibraryHelper.RenameCategory(currentCategory.Data as IACategory, categoryName))
				{
					SaveUserModelLibraryChange();
					BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.RenameCurrentCategory);
				}
			}
		}

		private void RenameCurrentCategory_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.CurrentCategory != null && theBlockTableControl.CurrentCategory.Data != null && !object.Equals(theBlockTableControl.CurrentCategory.Header, ModelLibraryResources.EditorScreenUncategorizedTab);
		}

		private void ReorderCategories_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ReorderWindow reorderWindow = new ReorderWindow(from category in theBlockTableControl.Categories
				where category.Data != null
				select category.Header.ToString(), ModelLibraryResources.ReorderWindowTitleOfCategories, ModelLibraryResources.ReorderWindowGroupHeaderOfCategories)
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = reorderWindow.ShowDialog();
			if (flag.HasValue && flag.Value && EnsureUserModelLibraryWritable() && ModelLibraryHelper.ReorderOrderedCollection(_currentEditCategories, reorderWindow.Items))
			{
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.ReorderCategories);
			}
		}

		private void ReorderCategories_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.Categories.Count > 2;
		}

		private void ReorderModelsInCurrentCategory_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ReorderWindow reorderWindow = new ReorderWindow(from model in theBlockTableControl.CurrentCategory.Models
				where model.Data != null
				select model.Header.ToString(), ModelLibraryResources.ReorderWindowTitleOfModels, ModelLibraryResources.ReorderWindowGroupHeaderOfBlocks)
			{
				Owner = Window.GetWindow(this)
			};
			MMHelp.SetHelpFile(reorderWindow, "userguide1.chm");
			MMHelp.SetHelpId(reorderWindow, 1555);
			bool? flag = reorderWindow.ShowDialog();
			if (flag.HasValue && flag.Value && EnsureUserModelLibraryWritable() && ModelLibraryHelper.ReorderOrderedCollection(theBlockTableControl.CurrentCategory.Data, reorderWindow.Items))
			{
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.ReorderModelsInCurrentCategory);
			}
		}

		private void ReorderModelsInCurrentCategory_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.CurrentCategory != null && theBlockTableControl.CurrentCategory.Data != null && !object.Equals(theBlockTableControl.CurrentCategory.Header, ModelLibraryResources.EditorScreenUncategorizedTab) && theBlockTableControl.CurrentCategory.Models.Count > 1;
		}

		private void DeleteCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (MMMessageBox.Show(ModelLibraryResources.EditorScreenCheckDeleteModel, ModelLibraryResources.EditorScreenCheckDeleteModelTitle, MMMessageBoxButton.YesNo) == MMMessageBoxResult.Yes && EnsureUserModelLibraryWritable())
			{
				Model parent = theBlockTableControl.SelectedIcon.Parent;
				if (ModelLibraryHelper.RemoveModelType(_currentEditCategories, parent.Header.ToString()))
				{
					BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.DeleteCurrentModel);
					SaveUserModelLibraryChange();
				}
			}
		}

		private void DeleteCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void RenameCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			Model parent = theBlockTableControl.SelectedIcon.Parent;
			string text = parent.Header.ToString();
			EnterNewNameWindow enterNewNameWindow = new EnterNewNameWindow(ModelLibraryResources.EnterNewModelNameWindowNameLabel, text, 63L)
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = enterNewNameWindow.ShowDialog();
			if (!flag.HasValue || !flag.Value)
			{
				return;
			}
			string newName = enterNewNameWindow.NewName;
			if (!string.Equals(newName, text, StringComparison.CurrentCultureIgnoreCase))
			{
				if ((from category in theBlockTableControl.Categories
					from model in category.Models
					where string.Equals(newName, model.Header.ToString(), StringComparison.CurrentCultureIgnoreCase)
					select model).Count() > 0)
				{
					MMMessageBox.Show(string.Format(ModelLibraryResources.EditorScreenCheckRenameModelNewNameExists, newName), ModelLibraryResources.EditorScreenCheckRenameModelInvalidNameTitle);
				}
				else if (System.Windows.MessageBox.Show(ModelLibraryResources.EditorScreenCheckRenameModel, ModelLibraryResources.EditorScreenCheckRenameModelTitle, MessageBoxButton.YesNo) == MessageBoxResult.Yes && EnsureUserModelLibraryWritable() && ModelLibraryHelper.RenameModelType(parent.Data as IAModelType, newName))
				{
					SaveUserModelLibraryChange();
					BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.RenameCurrentModel);
				}
			}
		}

		private void RenameCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void MoveCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			MoveModeToOtherCategoryWindow moveModeToOtherCategoryWindow = new MoveModeToOtherCategoryWindow(theBlockTableControl.Categories.Where((Category category2) => category2 != theBlockTableControl.CurrentCategory))
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = moveModeToOtherCategoryWindow.ShowDialog();
			if (!flag.HasValue || !flag.Value || !EnsureUserModelLibraryWritable())
			{
				return;
			}
			IAModelType pModelType = theBlockTableControl.SelectedIcon.Parent.Data as IAModelType;
			{
				IACategory iaCategory = ModelLibraryHelper.FindCategory(_currentEditCategories, moveModeToOtherCategoryWindow.SelectedCategory.Header.ToString());
				if (iaCategory != null)
				{
					iaCategory.AddModelType(pModelType);
					Category category = theBlockTableControl.Categories.FirstOrDefault((Category x) => x.Data == iaCategory);
					if (category != null)
					{
						theBlockTableControl.CurrentCategory = category;
					}
					BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.MoveCurrentModel);
				}
			}
		}

		private void MoveCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void CopyCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (EnsureUserModelLibraryWritable())
			{
				OpenModelTypeWizard(theBlockTableControl.SelectedIcon.Parent, null);
			}
		}

		private void CopyCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void EditDescriptionForCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			Model parent = theBlockTableControl.SelectedIcon.Parent;
			EnterDescriptionWindow enterDescriptionWindow = new EnterDescriptionWindow
			{
				Owner = Window.GetWindow(this),
				ModelTypeName = parent.Header.ToString(),
				Description = parent.Description
			};
			if (enterDescriptionWindow.ShowDialog() == true && !string.Equals(parent.Description, enterDescriptionWindow.Description) && EnsureUserModelLibraryWritable() && ModelLibraryHelper.UpdateModelTypeDescription(parent.Data as IAModelType, enterDescriptionWindow.Description))
			{
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.EditDescriptionForCurrentModel);
			}
		}

		private void EditDescriptionForCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void EditUserConfiguration_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			string modelTypeName = theBlockTableControl.SelectedIcon.Parent.Header.ToString();
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
			{
				PaneName = HandleConfigurationEditorPaneName(modelTypeName),
				ScreenFactoryKey = "ModelTypeUserConfigurationScreenFactoryKey",
				ScreenSubject = new ModelTypeUserConfigurationScreenSubject
				{
					ModelLibraryDisplayName = LibraryInfo.ModelLibraryDisplayName,
					ModelTypeName = modelTypeName
				},
				InitialLocation = ScreenLocation.DockableFloating,
				InitialSize = new System.Windows.Size(800.0, 400.0)
			});
		}

		private void EditUserConfiguration_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			if (theBlockTableControl.SelectedIcon != null && theBlockTableControl.SelectedIcon.Parent.Data is IAModelType managedModelType)
			{
				string userModelTypeBaseName = ModelLibraryHelper.GetUserModelTypeBaseName(managedModelType);
				e.CanExecute = EditableUserNames.Contains(userModelTypeBaseName);
			}
		}

		private void ClearUserConfiguration_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (MMMessageBox.Show(ModelLibraryResources.EditorScreenCheckClearConfiguration, ModelLibraryResources.EditorScreenCheckClearConfigurationTitle, MMMessageBoxButton.YesNo) == MMMessageBoxResult.Yes && EnsureUserModelLibraryWritable() && ModelLibraryHelper.ClearModelTypeConfiguration(theBlockTableControl.SelectedIcon.Parent.Data as IAModelType))
			{
				SaveUserModelLibraryChange();
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.ClearUserConfiguration);
			}
		}

		private void ClearUserConfiguration_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			if (theBlockTableControl.SelectedIcon != null && theBlockTableControl.SelectedIcon.Parent.Data is IAModelType managedModelType)
			{
				e.CanExecute = ModelLibraryHelper.CanClearModelTypeConfiguration(managedModelType);
			}
		}

		private void EditCurrentIcon_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (EnsureUserModelLibraryWritable())
			{
				AspenTech.AspenPlus.ModelLibrary.Controls.Icon selectedIcon = theBlockTableControl.SelectedIcon;
				OpenIconEditorScreen(selectedIcon.Parent.Header.ToString(), selectedIcon.Header.ToString());
			}
		}

		private void EditCurrentIcon_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void CreateNewIcon_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			EnterNewNameWindow enterNewNameWindow = new EnterNewNameWindow(ModelLibraryResources.EnterNewIconNameWindowNameLabel, null, 31L)
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = enterNewNameWindow.ShowDialog();
			if (!flag.HasValue || !flag.Value || !EnsureUserModelLibraryWritable())
			{
				return;
			}
			if (ModelLibraryLoader.IsIconExisted(theBlockTableControl.Categories, enterNewNameWindow.NewName))
			{
				MMMessageBox.Show(string.Format(ModelLibraryResources.EnterNewIconNameWindowNewCategoryNameExists, enterNewNameWindow.NewName), ModelLibraryResources.EnterNewIconNameWindowInvalidCategoryNameTitle);
				return;
			}
			Model parent = theBlockTableControl.SelectedIcon.Parent;
			if (ModelLibraryHelper.AppendNewIcon(parent.Data as IAModelType, enterNewNameWindow.NewName) != null)
			{
				OpenIconEditorScreen(parent.Header.ToString(), enterNewNameWindow.NewName);
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.CreateNewIcon);
			}
		}

		private void CreateNewIcon_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null;
		}

		private void DeleteCurrentIcon_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (MMMessageBox.Show(string.Format(ModelLibraryResources.EditorScreenCheckDeleteIcon, theBlockTableControl.SelectedIcon.Header.ToString()), ModelLibraryResources.EditorScreenCheckDeleteIconTitle, MMMessageBoxButton.YesNo) == MMMessageBoxResult.Yes && EnsureUserModelLibraryWritable())
			{
				IAModelType obj = theBlockTableControl.SelectedIcon.Parent.Data as IAModelType;
				IAModelIcon pModelIcon = theBlockTableControl.SelectedIcon.Data as IAModelIcon;
				((IAEditModelIcons)obj).RemoveIcon(pModelIcon);
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.DeleteCurrentIcon);
			}
		}

		private void DeleteCurrentIcon_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null && theBlockTableControl.SelectedIcon.Parent.Icons.Count > 1;
		}

		private void ReorderIconsInCurrentModel_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ReorderWindow reorderWindow = new ReorderWindow(theBlockTableControl.SelectedIcon.Parent.Icons.Select((AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon) => icon.Header.ToString()), ModelLibraryResources.ReorderWindowTitleOfIcons, ModelLibraryResources.ReorderWindowGroupHeaderOfIcons)
			{
				Owner = Window.GetWindow(this)
			};
			bool? flag = reorderWindow.ShowDialog();
			if (flag.HasValue && flag.Value && EnsureUserModelLibraryWritable() && ModelLibraryHelper.ReorderOrderedCollection(theBlockTableControl.SelectedIcon.Parent.Data, reorderWindow.Items))
			{
				BroadcastUserModelLibraryUpdated(UserModelLibraryUpdatedMode.ReorderIconsInCurrentModel);
			}
		}

		private void ReorderIconsInCurrentModel_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = theBlockTableControl.SelectedIcon != null && theBlockTableControl.SelectedIcon.Parent.Icons.Count > 1;
		}

		private void btnSave_Click(object sender, RoutedEventArgs e)
		{
			SaveUserModelLibraryChange();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibraryeditorscreen.xaml", UriKind.Relative);
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
				CreateNewCategory = (CommandBinding)target;
				CreateNewCategory.Executed += CreateNewCategory_Executed;
				CreateNewCategory.CanExecute += CreateNewCategory_CanExecute;
				break;
			case 2:
				DeleteCurrentCategory = (CommandBinding)target;
				DeleteCurrentCategory.Executed += DeleteCurrentCategory_Executed;
				DeleteCurrentCategory.CanExecute += DeleteCurrentCategory_CanExecute;
				break;
			case 3:
				RenameCurrentCategory = (CommandBinding)target;
				RenameCurrentCategory.Executed += RenameCurrentCategory_Executed;
				RenameCurrentCategory.CanExecute += RenameCurrentCategory_CanExecute;
				break;
			case 4:
				ReorderCategories = (CommandBinding)target;
				ReorderCategories.Executed += ReorderCategories_Executed;
				ReorderCategories.CanExecute += ReorderCategories_CanExecute;
				break;
			case 5:
				ReorderModelsInCurrentCategory = (CommandBinding)target;
				ReorderModelsInCurrentCategory.Executed += ReorderModelsInCurrentCategory_Executed;
				ReorderModelsInCurrentCategory.CanExecute += ReorderModelsInCurrentCategory_CanExecute;
				break;
			case 6:
				DeleteCurrentModel = (CommandBinding)target;
				DeleteCurrentModel.Executed += DeleteCurrentModel_Executed;
				DeleteCurrentModel.CanExecute += DeleteCurrentModel_CanExecute;
				break;
			case 7:
				RenameCurrentModel = (CommandBinding)target;
				RenameCurrentModel.Executed += RenameCurrentModel_Executed;
				RenameCurrentModel.CanExecute += RenameCurrentModel_CanExecute;
				break;
			case 8:
				MoveCurrentModel = (CommandBinding)target;
				MoveCurrentModel.Executed += MoveCurrentModel_Executed;
				MoveCurrentModel.CanExecute += MoveCurrentModel_CanExecute;
				break;
			case 9:
				CopyCurrentModel = (CommandBinding)target;
				CopyCurrentModel.Executed += CopyCurrentModel_Executed;
				CopyCurrentModel.CanExecute += CopyCurrentModel_CanExecute;
				break;
			case 10:
				EditDescriptionForCurrentModel = (CommandBinding)target;
				EditDescriptionForCurrentModel.Executed += EditDescriptionForCurrentModel_Executed;
				EditDescriptionForCurrentModel.CanExecute += EditDescriptionForCurrentModel_CanExecute;
				break;
			case 11:
				EditUserConfiguration = (CommandBinding)target;
				EditUserConfiguration.Executed += EditUserConfiguration_Executed;
				EditUserConfiguration.CanExecute += EditUserConfiguration_CanExecute;
				break;
			case 12:
				ClearUserConfiguration = (CommandBinding)target;
				ClearUserConfiguration.Executed += ClearUserConfiguration_Executed;
				ClearUserConfiguration.CanExecute += ClearUserConfiguration_CanExecute;
				break;
			case 13:
				EditCurrentIcon = (CommandBinding)target;
				EditCurrentIcon.Executed += EditCurrentIcon_Executed;
				EditCurrentIcon.CanExecute += EditCurrentIcon_CanExecute;
				break;
			case 14:
				CreateNewIcon = (CommandBinding)target;
				CreateNewIcon.Executed += CreateNewIcon_Executed;
				CreateNewIcon.CanExecute += CreateNewIcon_CanExecute;
				break;
			case 15:
				DeleteCurrentIcon = (CommandBinding)target;
				DeleteCurrentIcon.Executed += DeleteCurrentIcon_Executed;
				DeleteCurrentIcon.CanExecute += DeleteCurrentIcon_CanExecute;
				break;
			case 16:
				ReorderIconsInCurrentModel = (CommandBinding)target;
				ReorderIconsInCurrentModel.Executed += ReorderIconsInCurrentModel_Executed;
				ReorderIconsInCurrentModel.CanExecute += ReorderIconsInCurrentModel_CanExecute;
				break;
			case 17:
				theBlockTableControl = (BlockTableControl)target;
				break;
			case 18:
				btnSave = (System.Windows.Controls.Button)target;
				btnSave.Click += btnSave_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ModelLibraryEditorScreenSubject : ScreenSubject
	{
		public string ModelLibraryDisplayName { get; set; }

		public string ModelLibraryLocation { get; set; }

		public bool ModelLibraryIsInUse { get; set; }

		public bool ModelLibraryIsBuiltIn { get; set; }
	}
	public static class ModelLibraryLoader
	{
		[CompilerGenerated]
		private sealed class IconSelection
		{
			public IAModelIcon currentIcon;

			internal bool MatchesIcon(AspenTech.AspenPlus.ModelLibrary.Controls.Icon x)
			{
				return x.Data == currentIcon;
			}
		}

		[CompilerGenerated]
		private sealed class IconEnumerator : IEnumerable<AspenTech.AspenPlus.ModelLibrary.Controls.Icon>, IEnumerable, IEnumerator<AspenTech.AspenPlus.ModelLibrary.Controls.Icon>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private AspenTech.AspenPlus.ModelLibrary.Controls.Icon currentItem;

			private int initialThreadId;

			private IAModelType iaModelType;

			public IAModelType initialIaModelType;

			private IEnumerator<IAModelIcon> outerEnumerator;

			AspenTech.AspenPlus.ModelLibrary.Controls.Icon IEnumerator<AspenTech.AspenPlus.ModelLibrary.Controls.Icon>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public IconEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = iteratorState;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeOuterEnumerator();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					switch (iteratorState)
					{
					default:
						completedNormally = true;
						return false;
					case 0:
					{
						iteratorState = -1;
						IList<IAModelIcon> list = ModelLibraryHelper.EnumerateIAModelIcons(iaModelType);
						outerEnumerator = list.GetEnumerator();
						iteratorState = -3;
						break;
					}
					case 1:
						iteratorState = -3;
						break;
					}
					if (outerEnumerator.MoveNext())
					{
						IAModelIcon current = outerEnumerator.Current;
						byte[] array = new byte[64];
						current.GetName(ref array[0], array.Length);
						AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon = new AspenTech.AspenPlus.ModelLibrary.Controls.Icon
						{
							Header = GetStringFromBytes(array),
							Data = current
						};
						currentItem = icon;
						iteratorState = 1;
						completedNormally = true;
						return true;
					}
					DisposeOuterEnumerator();
					outerEnumerator = null;
					completedNormally = true;
					return false;
				}
				finally
				{
					// Dispose on exceptional exit, matching the original IL fault handler.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeOuterEnumerator()
			{
				iteratorState = -1;
				if (outerEnumerator != null)
				{
					outerEnumerator.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<AspenTech.AspenPlus.ModelLibrary.Controls.Icon> IEnumerable<AspenTech.AspenPlus.ModelLibrary.Controls.Icon>.GetEnumerator()
			{
				IconEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new IconEnumerator(0);
				}
				enumerator.iaModelType = initialIaModelType;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<AspenTech.AspenPlus.ModelLibrary.Controls.Icon>)this).GetEnumerator();
			}
		}

		[CompilerGenerated]
		private sealed class CategoryEnumerator : IEnumerable<Category>, IEnumerable, IEnumerator<Category>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private Category currentItem;

			private int initialThreadId;

			private IAEditCategories editCategories;

			public IAEditCategories initialEditCategories;

			private bool includeEmptyCategories;

			public bool initialIncludeEmptyCategories;

			private bool includeUncategorized;

			public bool initialIncludeUncategorized;

			private IEnumACategory categoryEnumeratorState;

			private uint fetchedCountState;

			private IACategory iaCategoryState;

			Category IEnumerator<Category>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public CategoryEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
			}

			bool IEnumerator.MoveNext()
			{
				IACategory iACategory;
				Category category2;
				switch (iteratorState)
				{
				default:
					return false;
				case 0:
					iteratorState = -1;
					categoryEnumeratorState = null;
					editCategories.EnumCategories(ref categoryEnumeratorState);
					fetchedCountState = 0u;
					iaCategoryState = null;
					categoryEnumeratorState.Reset();
					categoryEnumeratorState.Next(1u, ref iaCategoryState, ref fetchedCountState);
					goto IL_0144;
				case 1:
					iteratorState = -1;
					goto IL_012c;
				case 2:
					{
						iteratorState = -1;
						break;
					}
					IL_0144:
					if (fetchedCountState != 0)
					{
						byte[] array = new byte[64];
						iaCategoryState.GetName(ref array[0], array.Length);
						Category category = new Category
						{
							Header = GetStringFromBytes(array),
							Name = ModelLibraryHelper.GetCategoryNameByDisplayName(GetStringFromBytes(array)),
							Data = iaCategoryState
						};
						foreach (Model managedModel in GetManagedModels(iaCategoryState))
						{
							category.Models.Add(managedModel);
						}
						iaCategoryState = null;
						if (includeEmptyCategories || category.Models.Count > 0)
						{
							currentItem = category;
							iteratorState = 1;
							return true;
						}
						goto IL_012c;
					}
					if (!includeUncategorized)
					{
						break;
					}
					iACategory = ModelLibraryHelper.FindCategory(editCategories, ModelLibraryResources.EditorScreenUncategorizedTab);
					if (iACategory == null)
					{
						break;
					}
					category2 = new Category
					{
						Header = ModelLibraryResources.EditorScreenUncategorizedTab,
						Data = iACategory
					};
					foreach (Model managedModel2 in GetManagedModels(iACategory))
					{
						category2.Models.Add(managedModel2);
					}
					currentItem = category2;
					iteratorState = 2;
					return true;
					IL_012c:
					categoryEnumeratorState.Next(1u, ref iaCategoryState, ref fetchedCountState);
					goto IL_0144;
				}
				return false;
			}


			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<Category> IEnumerable<Category>.GetEnumerator()
			{
				CategoryEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new CategoryEnumerator(0);
				}
				enumerator.editCategories = initialEditCategories;
				enumerator.includeUncategorized = initialIncludeUncategorized;
				enumerator.includeEmptyCategories = initialIncludeEmptyCategories;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<Category>)this).GetEnumerator();
			}
		}

		[CompilerGenerated]
		private sealed class ModelEnumerator : IEnumerable<Model>, IEnumerable, IEnumerator<Model>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private Model currentItem;

			private int initialThreadId;

			private IACategory iaCategory;

			public IACategory initialIaCategory;

			private IEnumAModelType modelTypeEnumeratorState;

			private string strCategoryNameState;

			private uint fetchedCountState;

			private IAModelType iaModelTypeState;

			private string strManipulatorsState;

			Model IEnumerator<Model>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public ModelEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
			}

			bool IEnumerator.MoveNext()
			{
				int num = iteratorState;
				if (num != 0)
				{
					if (num != 1)
					{
						return false;
					}
					iteratorState = -1;
					goto IL_0208;
				}
				iteratorState = -1;
				modelTypeEnumeratorState = null;
				iaCategory.EnumModelType(ref modelTypeEnumeratorState);
				byte[] array = new byte[80];
				iaCategory.GetName(ref array[0], 80);
				strCategoryNameState = GetStringFromBytes(array);
				fetchedCountState = 0u;
				iaModelTypeState = null;
				modelTypeEnumeratorState.Reset();
				SORRes sORRes = new SORRes();
				strManipulatorsState = sORRes.GetString(1903u);
				modelTypeEnumeratorState.Next(1u, ref iaModelTypeState, ref fetchedCountState);
				goto IL_0220;
				IL_0208:
				modelTypeEnumeratorState.Next(1u, ref iaModelTypeState, ref fetchedCountState);
				goto IL_0220;
				IL_0220:
				if (fetchedCountState != 0)
				{
					if (!(strCategoryNameState == strManipulatorsState) || !(GetUnmanagedModelTypeName(iaModelTypeState) == "PSValve"))
					{
						ProcessTypeRestriction unmanagedModelTypeProcessType = GetUnmanagedModelTypeProcessType(iaModelTypeState);
						if ((BatchProcessMode || unmanagedModelTypeProcessType != ProcessTypeRestriction.ProcessTypeBatch) && (!BatchProcessMode || unmanagedModelTypeProcessType != ProcessTypeRestriction.ProcessTypeContinuous))
						{
							Model model = new Model
							{
								Header = GetUnmanagedModelTypeName(iaModelTypeState),
								Data = iaModelTypeState,
								Description = ModelLibraryHelper.GetModelTypeDescription(iaModelTypeState)
							};
							foreach (AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon in GetIcons(iaModelTypeState))
							{
								model.Icons.Add(icon);
							}
							if (model.Icons.Count > 0)
							{
								IconSelection iconSelection = new IconSelection
								{
									currentIcon = null
								};
								try
								{
									iconSelection.currentIcon = ModelLibraryHelper.GetCurrentIAModelIcon(iaModelTypeState);
								}
								catch (Exception)
								{
								}
								if (iconSelection.currentIcon == null)
								{
									model.SelectedIcon = model.Icons.FirstOrDefault();
								}
								else
								{
									model.SelectedIcon = model.Icons.FirstOrDefault(iconSelection.MatchesIcon);
								}
								iaModelTypeState = null;
								currentItem = model;
								iteratorState = 1;
								return true;
							}
						}
					}
					goto IL_0208;
				}
				return false;
			}


			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<Model> IEnumerable<Model>.GetEnumerator()
			{
				ModelEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new ModelEnumerator(0);
				}
				enumerator.iaCategory = initialIaCategory;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<Model>)this).GetEnumerator();
			}
		}

		private const int WDT_INPROC_CALL = 1215587415;

		private const string StreamCategoryName = "streams";

		private const string ACM_Models = "acm models";

		private static string s_strLocalizedStreamCategoryName = string.Empty;

		private static readonly System.Windows.Size DefaultIconSize = new System.Windows.Size(70.0, 70.0);

		public static bool BatchProcessMode { get; set; }

		public static string LocalizedStreamCategoryName
		{
			get
			{
				if (string.IsNullOrEmpty(s_strLocalizedStreamCategoryName))
				{
					s_strLocalizedStreamCategoryName = ModelLibraryHelper.GetLocalizedStreamCategoryName();
				}
				return s_strLocalizedStreamCategoryName;
			}
		}

		[DllImport("mmstruct.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Auto, ExactSpelling = true)]
		private static extern void MMStructGetModelTypeList([MarshalAs(UnmanagedType.Interface)] out IAEditCategories ppEditCategories);

		public static Library LoadModelLibrary()
		{
			IAEditCategories ppEditCategories = null;
			MMStructGetModelTypeList(out ppEditCategories);
			Library library = new Library();
			foreach (Category managedCategory in GetManagedCategories(ppEditCategories))
			{
				string text = (managedCategory.Name as string).ToLower();
				if (string.Equals(text, "streams", StringComparison.CurrentCultureIgnoreCase) || string.Equals(text, LocalizedStreamCategoryName, StringComparison.CurrentCultureIgnoreCase))
				{
					LocalizeLabelsForStreams(managedCategory);
					managedCategory.IsStreamCategory = true;
					library.StreamCategory = managedCategory;
				}
				else if (!(text == "acm models") || !BatchProcessMode)
				{
					library.BlockCategories.Add(managedCategory);
				}
			}
			library.StreamCategory.SelectedModel = library.StreamCategory.Models.FirstOrDefault();
			library.CurrentBlockCategory = library.BlockCategories.FirstOrDefault();
			return library;
		}

		private static void LocalizeLabelsForStreams(Category streamCategory)
		{
			foreach (Model model in streamCategory.Models)
			{
				if (string.Equals(model.Header as string, "material", StringComparison.InvariantCultureIgnoreCase))
				{
					model.Header = AspenTech.AspenPlus.MMControls.Properties.Resources.rectype_streams_material;
				}
				else if (string.Equals(model.Header as string, "work", StringComparison.InvariantCultureIgnoreCase))
				{
					model.Header = AspenTech.AspenPlus.MMControls.Properties.Resources.rectype_streams_work;
				}
				else if (string.Equals(model.Header as string, "heat", StringComparison.InvariantCultureIgnoreCase))
				{
					model.Header = AspenTech.AspenPlus.MMControls.Properties.Resources.rectype_streams_heat;
				}
				else if (string.Equals(model.Header as string, "power", StringComparison.InvariantCultureIgnoreCase))
				{
					model.Header = AspenTech.AspenPlus.MMControls.Properties.Resources.rectype_streams_power;
				}
			}
		}

		public static void SaveModelLibrary()
		{
			ModelLibraryHelper.GetModelLibrariesInUse();
			new List<UserModelLibrary>();
			foreach (ModelLibraryData userModelLibrary in ModelLibraryHelper.GetUserModelLibraries())
			{
				if (!userModelLibrary.IsBuiltIn)
				{
					IAEditCategories iAEditCategories = ModelLibraryHelper.GetIAEditCategories(userModelLibrary.DisplayName);
					if (iAEditCategories != null)
					{
						ModelLibraryHelper.EnsureUserModelLibraryWritable(iAEditCategories);
						ModelLibraryHelper.SaveUserModelLibraryChanges(iAEditCategories);
					}
				}
			}
		}

		public static UIElement CreateDrawingElement(IAModelIcon iaIcon, SolidColorBrush background, double? width = null, double? height = null)
		{
			double width2 = (width.HasValue ? width.Value : DefaultIconSize.Width);
			double height2 = (height.HasValue ? height.Value : DefaultIconSize.Height);
			BitmapSource originalImageSource = ModelLibraryHelper.CreateImageSourceForIcon(iaIcon, width2, height2, background);
			return new System.Windows.Controls.Image
			{
				Source = GetConvertedImageSource(originalImageSource),
				Stretch = Stretch.None,
				Width = width2,
				Height = height2
			};
		}

		public static IEnumerable<UserModelLibrary> GetAllUserModelLibraries()
		{
			IList<string> modelLibrariesInUse = ModelLibraryHelper.GetModelLibrariesInUse();
			List<UserModelLibrary> list = new List<UserModelLibrary>();
			foreach (ModelLibraryData userModelLibrary in ModelLibraryHelper.GetUserModelLibraries())
			{
				UserModelLibrary item = new UserModelLibrary
				{
					DisplayName = userModelLibrary.DisplayName,
					IsBuiltIn = userModelLibrary.IsBuiltIn,
					IsInUse = modelLibrariesInUse.Contains(userModelLibrary.DisplayName),
					Location = userModelLibrary.Location
				};
				list.Add(item);
			}
			return list;
		}

		public static IEnumerable<UserModelLibrary> GetAllEditableLibraries()
		{
			return from x in GetAllUserModelLibraries()
				where !x.IsBuiltIn && x.IsInUse
				select x;
		}

		[IteratorStateMachine(typeof(CategoryEnumerator))]
		public static IEnumerable<Category> GetManagedCategories(IAEditCategories editCategories, bool includeUncategorized = false, bool includeEmptyCategories = false)
		{
			return new CategoryEnumerator(-2)
			{
				initialEditCategories = editCategories,
				initialIncludeUncategorized = includeUncategorized,
				initialIncludeEmptyCategories = includeEmptyCategories
			};
		}

		public static bool SetCurrentIcon(Category category, AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon)
		{
			if (category != null)
			{
				foreach (Model model in category.Models)
				{
					if (model.Icons.Contains(icon))
					{
						return ModelLibraryHelper.SetCurrentIAModelIcon(model.Data as IAModelType, icon.Data as IAModelIcon);
					}
				}
			}
			return false;
		}

		public static bool IsIconExisted(CategoryCollection categories, string iconName)
		{
			foreach (Category category in categories)
			{
				if (iconName.Equals(category.Header.ToString(), StringComparison.InvariantCultureIgnoreCase))
				{
					return true;
				}
				foreach (Model model in category.Models)
				{
					if (iconName.Equals(model.Header.ToString(), StringComparison.InvariantCultureIgnoreCase))
					{
						return true;
					}
					foreach (AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon in model.Icons)
					{
						if (iconName.Equals(icon.Header.ToString(), StringComparison.InvariantCultureIgnoreCase))
						{
							return true;
						}
					}
				}
			}
			return false;
		}

		[IteratorStateMachine(typeof(ModelEnumerator))]
		public static IEnumerable<Model> GetManagedModels(IACategory iaCategory)
		{
			return new ModelEnumerator(-2)
			{
				initialIaCategory = iaCategory
			};
		}

		public static string GetUnmanagedModelTypeName(IAModelType iaModelType)
		{
			byte[] array = new byte[64];
			iaModelType.GetName(ref array[0], array.Length);
			string text = GetStringFromBytes(array);
			if (text.Length > 24)
			{
				text = text.Substring(0, 21) + "...";
			}
			return text;
		}

		public static ProcessTypeRestriction GetUnmanagedModelTypeProcessType(IAModelType iaModelType)
		{
			ProcessTypeRestriction pProcType = ProcessTypeRestriction.ProcessTypeAny;
			iaModelType.GetProcessType(ref pProcType);
			return pProcType;
		}

		public static string GetUnmanagedModelName(IAModel iaModel)
		{
			byte[] array = new byte[64];
			iaModel.GetName(ref array[0], array.Length);
			return GetStringFromBytes(array);
		}

		public static IAModelType GetUnmanagedModelType(IAEditCategories iaEditCategories, string modelTypeName)
		{
			if (iaEditCategories != null && !string.IsNullOrEmpty(modelTypeName))
			{
				foreach (Category managedCategory in GetManagedCategories(iaEditCategories, includeUncategorized: true))
				{
					foreach (Model model in managedCategory.Models)
					{
						if (string.Equals(model.Header.ToString(), modelTypeName, StringComparison.CurrentCultureIgnoreCase))
						{
							return model.Data as IAModelType;
						}
					}
				}
			}
			return null;
		}

		public static IAModelIcon GetUnmanagedModelIcon(IAModelType iaModelType, string iconName)
		{
			if (iaModelType != null && !string.IsNullOrEmpty(iconName))
			{
				foreach (AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon in GetIcons(iaModelType))
				{
					if (string.Equals(icon.Header.ToString(), iconName, StringComparison.CurrentCultureIgnoreCase))
					{
						return icon.Data as IAModelIcon;
					}
				}
			}
			return null;
		}

		[IteratorStateMachine(typeof(IconEnumerator))]
		private static IEnumerable<AspenTech.AspenPlus.ModelLibrary.Controls.Icon> GetIcons(IAModelType iaModelType)
		{
			return new IconEnumerator(-2)
			{
				initialIaModelType = iaModelType
			};
		}

		private static string GetStringFromBytes(byte[] bytes)
		{
			return Encoding.Default.GetString(bytes).TrimEnd(default(char));
		}

		private static ImageSource GetConvertedImageSource(BitmapSource originalImageSource)
		{
			FormatConvertedBitmap formatConvertedBitmap = new FormatConvertedBitmap();
			formatConvertedBitmap.BeginInit();
			formatConvertedBitmap.Source = originalImageSource;
			formatConvertedBitmap.DestinationFormat = PixelFormats.Rgb128Float;
			formatConvertedBitmap.EndInit();
			return formatConvertedBitmap;
		}
	}
	public class ModelLibraryModule : IModule
	{
		public const string ModelLibraryScreenFactoryKey = "ModelLibraryScreenFactoryKey";

		public const string ModelLibrariesManagerWindowKey = "ModelLibrariesManagerWindowKey";

		public const string ModelCategoriesManagerWindowKey = "ModelCategoriesManagerWindowKey";

		public const string ModelLibraryEditorScreenFactoryKey = "ModelLibraryEditorScreenFactoryKey";

		public const string ModelLibraryIconEditorScreenFactoryKey = "ModelLibraryIconEditorScreenFactoryKey";

		public const string ModelTypeUserConfigurationScreenFactoryKey = "ModelTypeUserConfigurationScreenFactoryKey";

		public IUnityContainer Container { get; private set; }

		public IScreenFactoryCatalog ScreenFactoryCatalog { get; private set; }

		public ModelLibraryModule(IUnityContainer container, IScreenFactoryCatalog screenFactoryCatalog)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			if (screenFactoryCatalog == null)
			{
				throw new ArgumentNullException("screenFactoryCatalog");
			}
			Container = container;
			ScreenFactoryCatalog = screenFactoryCatalog;
		}

		public void Initialize()
		{
			Container.RegisterType<IModelLibraryPresenter, ModelLibraryPresenter>(new ContainerControlledLifetimeManager(), Array.Empty<InjectionMember>());
			ScreenFactoryCatalog.RegisterScreenFactory("ModelLibraryScreenFactoryKey", typeof(ModelLibraryScreen));
			ScreenFactoryCatalog.RegisterScreenFactory("ModelLibrariesManagerWindowKey", typeof(ModelLibrariesManagerWindow));
			ScreenFactoryCatalog.RegisterScreenFactory("ModelCategoriesManagerWindowKey", typeof(ModelCategoriesManagerWindow));
			ScreenFactoryCatalog.RegisterScreenFactory("ModelLibraryEditorScreenFactoryKey", typeof(ModelLibraryEditorScreen));
			ScreenFactoryCatalog.RegisterScreenFactory("ModelLibraryIconEditorScreenFactoryKey", typeof(ModelLibraryIconEditorScreen));
			ScreenFactoryCatalog.RegisterScreenFactory("ModelTypeUserConfigurationScreenFactoryKey", typeof(ModelTypeUserConfigurationScreen));
		}
	}
	public class ModelLibraryPresenter : IModelLibraryPresenter
	{
		public bool BatchProcessMode
		{
			get
			{
				return ModelLibraryLoader.BatchProcessMode;
			}
			set
			{
				ModelLibraryLoader.BatchProcessMode = value;
			}
		}

		public IUnityContainer Container { get; private set; }

		ApwnPanelControl IModelLibraryPresenter.ActivePalette
		{
			get
			{
				if (Container != null)
				{
					IShellApplication shellApplication = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && shellApplication.ActiveWindow is CommonShellWindow commonShellWindow)
					{
						return commonShellWindow.FindNamedPaneScreen("ModelLibraryScreenFactoryKey") as ApwnPanelControl;
					}
				}
				return null;
			}
		}

		bool IModelLibraryPresenter.HasEditableModelLibrary => ModelLibraryLoader.GetAllEditableLibraries().FirstOrDefault() != null;

		bool IModelLibraryPresenter.CanEditCurrentIcon => false;

		public ModelLibraryPresenter(IUnityContainer container)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			Container = container;
		}

		void IModelLibraryPresenter.ShowModelLibraryPalette()
		{
			ModelLibraryLoader.BatchProcessMode = BatchProcessMode;
			if (Container != null)
			{
				Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
				{
					PaneName = "ModelLibraryScreenFactoryKey",
					ScreenFactoryKey = "ModelLibraryScreenFactoryKey",
					InitialLocation = ScreenLocation.DockedBottom
				});
			}
		}

		void IModelLibraryPresenter.CloseModelLibraryPalette()
		{
			if (Container != null)
			{
				IShellApplication shellApplication = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null && shellApplication.ActiveWindow is CommonShellWindow commonShellWindow && commonShellWindow.FindNamedPaneScreen("ModelLibraryScreenFactoryKey") is ApwnPanelControl screen)
				{
					commonShellWindow.CloseScreen(screen);
				}
			}
		}

		void IModelLibraryPresenter.ShowModelLibraryManagerWindow()
		{
			if (Container != null)
			{
				Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
				{
					PaneName = "ModelLibrariesManagerWindowKey",
					ScreenFactoryKey = "ModelLibrariesManagerWindowKey",
					InitialLocation = ScreenLocation.DockableFloating,
					InitialSize = new System.Windows.Size(620.0, 200.0)
				});
			}
		}

		void IModelLibraryPresenter.ShowManageHybridLibraries()
		{
			if (Container != null)
			{
				HybridModelManagerDialog hybridModelManagerDialog = new HybridModelManagerDialog(Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()));
				if (hybridModelManagerDialog == null)
				{
					throw new ArgumentNullException("dialog");
				}
				IShellApplication shellApplication = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null && shellApplication.ActiveWindow is CommonShellWindow owner)
				{
					hybridModelManagerDialog.Owner = owner;
					hybridModelManagerDialog.ShowDialog();
				}
			}
		}

		void IModelLibraryPresenter.ShowPaletteCategoriesWindow()
		{
			if (Container != null)
			{
				Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ShowScreenEvent>().Publish(new ShowScreenEventArgs
				{
					PaneName = "ModelCategoriesManagerWindowKey",
					ScreenFactoryKey = "ModelCategoriesManagerWindowKey",
					InitialLocation = ScreenLocation.DockableFloating
				});
			}
		}

		void IModelLibraryPresenter.ShowManageACMLibraries()
		{
			if (Container != null)
			{
				try
				{
					object value = Registry.ClassesRoot.OpenSubKey("AspenTech.Modeler.LibraryManager\\exe").GetValue("");
					Process process = new Process();
					process.StartInfo.FileName = value.ToString();
					process.Start();
				}
				catch
				{
					string arg = "AspenCustomModelManager.exe";
					System.Windows.MessageBox.Show(string.Format(ApwnResources.AspenCustomModelManager, arg), "Aspen Plus", MessageBoxButton.OK, MessageBoxImage.Exclamation);
				}
			}
		}

		bool IModelLibraryPresenter.ShowAddNewLibraryWindow()
		{
			IShellApplication shellApplication = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
			if (shellApplication != null && shellApplication.ActiveWindow is CommonShellWindow owner)
			{
				ModelLibraryCreateNewWindow modelLibraryCreateNewWindow = new ModelLibraryCreateNewWindow
				{
					Owner = owner,
					DefaultBrowserDirectory = GetDefaultBrowserDirectory()
				};
				bool? flag = modelLibraryCreateNewWindow.ShowDialog();
				if (flag.HasValue && flag.Value)
				{
					string text = modelLibraryCreateNewWindow.FilePath;
					if (string.IsNullOrEmpty(System.IO.Path.GetExtension(text)))
					{
						text += ".apm";
					}
					try
					{
						if (ModelLibraryHelper.CreateNewUserModelLibrary(modelLibraryCreateNewWindow.DisplayName, text))
						{
							return true;
						}
						MMMessageBox.Show(ModelLibraryResources.ManagerWindowSystemErrorCreate, ModelLibraryResources.ModelLibraryCreatingErrorTitle);
					}
					catch (Exception ex)
					{
						System.Windows.MessageBox.Show(ModelLibraryResources.ManagerWindowSystemErrorCreate + "\n" + ex.Message, ModelLibraryResources.ModelLibraryCreatingErrorTitle);
					}
				}
			}
			return false;
		}

		private string GetDefaultBrowserDirectory()
		{
			string result = "";
			try
			{
				result = (string)Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).BatchGet("Top.appModelV8.Settings.startupdir", "value");
			}
			catch
			{
			}
			return result;
		}

		void IModelLibraryPresenter.AddSelected(IAModel documentRootModel, IAModel screenRootModel, IAModel currentModel, IEnumAModel selectedModels)
		{
			if (currentModel == null)
			{
				ModelTypeWizard modelTypeWizard = new ModelTypeWizard(documentRootModel, screenRootModel, selectedModels, Container);
				modelTypeWizard.Owner = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as Window;
				modelTypeWizard.ShowDialog();
			}
			else
			{
				ModelTypeWizard modelTypeWizard2 = new ModelTypeWizard(documentRootModel, screenRootModel, currentModel, selectedModels, Container);
				modelTypeWizard2.Owner = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as Window;
				modelTypeWizard2.ShowDialog();
			}
		}

		void IModelLibraryPresenter.AddCase(IAModel rootModel)
		{
			ModelTypeWizard modelTypeWizard = new ModelTypeWizard(rootModel, Container);
			modelTypeWizard.Owner = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as Window;
			modelTypeWizard.ShowDialog();
		}

		bool IModelLibraryPresenter.CanAppendToTemplate(IAModel documentRootModel, IHNode sourceNode)
		{
			if (documentRootModel != null && sourceNode != null)
			{
				foreach (IAEditCategories item in from x in ModelLibraryLoader.GetAllEditableLibraries()
					select x.UnamangedIAEditCategories)
				{
					ModelLibraryHelper.EnsureUserModelLibraryWritable(item);
				}
				if (ModelLibraryHelper.CanAppendModelToApwnLibraries())
				{
					dynamic val = sourceNode.get_AttributeValue((short)66, Type.Missing);
					if (val == null || val == 0)
					{
						return false;
					}
					return true;
				}
			}
			return false;
		}

		void IModelLibraryPresenter.AppendToTemplate(IAModel documentRootModel, IHNode sourceNode)
		{
			ModelTypeWizard modelTypeWizard = new ModelTypeWizard(documentRootModel, sourceNode, Container);
			modelTypeWizard.Owner = Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as Window;
			modelTypeWizard.ShowDialog();
		}

		void IModelLibraryPresenter.EditCurrentIcon()
		{
		}
	}
	public class ModelLibraryScreen : ApwnPanelControl, IComponentConnector
	{
		private const string CF_AOSA_MODEL_TYPE = "AOSA Model Type Format";

		private const int DragValidLength = 10;

		private readonly Dictionary<IAModelIcon, UIElement> _defaultDrawings = new Dictionary<IAModelIcon, UIElement>();

		private readonly Dictionary<IAModelIcon, UIElement> _checkedDrawings = new Dictionary<IAModelIcon, UIElement>();

		private System.Windows.Point _mouseDownPosition;

		private Model _mouseDownModel;

		private IAModelType _selectedModelType;

		internal ModelLibraryControl theLibraryControl;

		private bool _contentLoaded;

		public IUnityContainer Container { get; private set; }

		public new IEventAggregator EventAggregator { get; private set; }

		public IAModelType SelectedModelType
		{
			get
			{
				return _selectedModelType;
			}
			set
			{
				if (_selectedModelType != value)
				{
					_selectedModelType = value;
					if (EventAggregator != null)
					{
						EventAggregator.GetEvent<SelecetedModelTypeChangedEvent>().Publish(new SelecetedModelTypeChangedEventArgs(_selectedModelType));
					}
				}
			}
		}

		public ModelLibraryScreen(IUnityContainer container, IEventAggregator eventAggregator)
		{
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			if (eventAggregator == null)
			{
				throw new ArgumentNullException("eventAggregator");
			}
			Container = container;
			EventAggregator = eventAggregator;
			InitializeComponent();
		}

		protected override void OnInitialized(EventArgs e)
		{
			EventAggregator.GetEvent<ProcessTypeChangedEvent>().Subscribe(new Action<EventArgs>(OnProcessTypeChangedEvent));
			Refresh();
			theLibraryControl.AddHandler(DropdownButton.PopupOpenedEvent, new RoutedEventHandler(DropdownButton_PopupOpened));
			theLibraryControl.AddHandler(BlockTableControl.CurrentCategoryChangedEvent, new RoutedPropertyChangedEventHandler<Category>(BlockTableControl_CurrentCategoryChanged));
			theLibraryControl.SelectionChanged += theLibraryControl_SelectionChanged;
			theLibraryControl.PreviewMouseLeftButtonDown += theLibraryControl_PreviewMouseLeftButtonDown;
			theLibraryControl.PreviewMouseMove += theLibraryControl_PreviewMouseMove;
			theLibraryControl.PreviewMouseLeftButtonUp += theLibraryControl_PreviewMouseLeftButtonUp;
			EventAggregator.GetEvent<SelectedModelLibrariesChangedEvent>().Subscribe(OnSelectedModelLibrariesChanged);
			EventAggregator.GetEvent<SelectedEditCategoriesChangedEvent>().Subscribe(OnSelectedEditCategoriesChanged);
			EventAggregator.GetEvent<UserModelLibraryUpdatedEvent>().Subscribe(OnUserModelLibraryUpdated);
			EventAggregator.GetEvent<ModelTypeWizardFinishedEvent>().Subscribe(OnModelTypeWizardFinished);
			EventAggregator.GetEvent<FlowsheetCancelInsertModeEvent>().Subscribe(OnFlowsheetCancelInsertMode);
			EventAggregator.GetEvent<UpdateModelPaletteEvent>().Subscribe(OnUpdateModelPaletteEvent);
			EventAggregator.GetEvent<RefreshModelPaletteEvent>().Subscribe(OnRefreshModelPaletteEvent);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibrarySaveEvent>().Subscribe(OnModelLibrarySave);
			base.OnInitialized(e);
		}

		protected override void OnClosed(EventArgs args)
		{
			EventAggregator.GetEvent<SelectedModelLibrariesChangedEvent>().Unsubscribe(OnSelectedModelLibrariesChanged);
			EventAggregator.GetEvent<SelectedEditCategoriesChangedEvent>().Unsubscribe(OnSelectedEditCategoriesChanged);
			EventAggregator.GetEvent<UserModelLibraryUpdatedEvent>().Unsubscribe(OnUserModelLibraryUpdated);
			EventAggregator.GetEvent<ModelTypeWizardFinishedEvent>().Unsubscribe(OnModelTypeWizardFinished);
			EventAggregator.GetEvent<FlowsheetCancelInsertModeEvent>().Unsubscribe(OnFlowsheetCancelInsertMode);
			EventAggregator.GetEvent<UpdateModelPaletteEvent>().Unsubscribe(OnUpdateModelPaletteEvent);
			EventAggregator.GetEvent<RefreshModelPaletteEvent>().Unsubscribe(OnRefreshModelPaletteEvent);
			Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ModelLibrarySaveEvent>().Unsubscribe(OnModelLibrarySave);
			base.OnClosed(args);
		}

		private void OnModelLibrarySave(ModelLibrarySaveEventArgs e)
		{
			ModelLibraryLoader.SaveModelLibrary();
		}

		private void Refresh(bool clearDrawingCache = false)
		{
			string currentCategoryName = null;
			if (theLibraryControl != null && theLibraryControl.CurrentBlockCategory != null && theLibraryControl.CurrentBlockCategory.Header != null)
			{
				currentCategoryName = theLibraryControl.CurrentBlockCategory.Header.ToString();
			}
			if (clearDrawingCache)
			{
				_defaultDrawings.Clear();
				_checkedDrawings.Clear();
			}
			Library library = ModelLibraryLoader.LoadModelLibrary();
			theLibraryControl.ModelLibrary = library;
			InitializeStreamModelIcons();
			UpdateLayout();
			UpdateUIStatus();
			if (!string.IsNullOrWhiteSpace(currentCategoryName) && library.BlockCategories.Count > 0)
			{
				Category category = library.BlockCategories.FirstOrDefault((Category x) => object.Equals(x.Header, currentCategoryName));
				if (category != null && category.Models.Count >= 0)
				{
					theLibraryControl.CurrentBlockCategory = category;
				}
				else
				{
					theLibraryControl.CurrentBlockCategory = library.BlockCategories[0];
				}
			}
		}

		private void InitializeStreamModelIcons()
		{
			if (theLibraryControl.ModelLibrary == null || theLibraryControl.ModelLibrary.StreamCategory == null)
			{
				return;
			}
			foreach (Model model in theLibraryControl.ModelLibrary.StreamCategory.Models)
			{
				foreach (AspenTech.AspenPlus.ModelLibrary.Controls.Icon icon in model.Icons)
				{
					icon.DrawingElement = GetDefaultDrawing(icon.Data as IAModelIcon);
				}
			}
		}

		private void UpdateUIStatus()
		{
			if (SelectedModelType == null)
			{
				theLibraryControl.IsOptionIconChecked = true;
				return;
			}
			foreach (Model model in theLibraryControl.ModelLibrary.StreamCategory.Models)
			{
				if (model.Data == SelectedModelType)
				{
					theLibraryControl.SelectedStreamModel = model;
					theLibraryControl.ModelLibrary.StreamCategory.SelectedModel = model;
					return;
				}
			}
			foreach (Category blockCategory in theLibraryControl.ModelLibrary.BlockCategories)
			{
				foreach (Model model2 in blockCategory.Models)
				{
					if (model2.Data == SelectedModelType)
					{
						model2.IsChecked = true;
						theLibraryControl.SelectedBlockIcon = model2.SelectedIcon;
						theLibraryControl.CurrentBlockCategory = blockCategory;
						return;
					}
				}
			}
		}

		private void DropdownButton_PopupOpened(object sender, RoutedEventArgs e)
		{
			if (!(e.OriginalSource is DropdownButton dropdownButton))
			{
				return;
			}
			foreach (object item in (IEnumerable)dropdownButton.Items)
			{
				if (item is AspenTech.AspenPlus.ModelLibrary.Controls.Icon { DrawingElement: null } icon)
				{
					IAModelIcon modelIcon = icon.Data as IAModelIcon;
					icon.DrawingElement = GetDefaultDrawing(modelIcon);
				}
			}
		}

		private void BlockTableControl_CurrentCategoryChanged(object sender, RoutedPropertyChangedEventArgs<Category> e)
		{
			if (e.NewValue == null)
			{
				return;
			}
			foreach (Model model in e.NewValue.Models)
			{
				if (model.SelectedIcon != null && model.SelectedIcon.DrawingElement == null)
				{
					IAModelIcon modelIcon = model.SelectedIcon.Data as IAModelIcon;
					model.SelectedIcon.DrawingElement = GetDefaultDrawing(modelIcon);
				}
			}
		}

		private void theLibraryControl_SelectionChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (theLibraryControl.SelectedStreamModel != null)
			{
				SelectedModelType = theLibraryControl.SelectedStreamModel.Data as IAModelType;
			}
			else if (theLibraryControl.SelectedBlockIcon != null)
			{
				IAModelIcon currentIcon = theLibraryControl.SelectedBlockIcon.Data as IAModelIcon;
				IAModelType iAModelType = theLibraryControl.SelectedBlockIcon.Parent.Data as IAModelType;
				(iAModelType as IAEditModelIcons).SetCurrentIcon(currentIcon);
				SelectedModelType = iAModelType;
			}
			else
			{
				SelectedModelType = null;
			}
			AspenTech.AspenPlus.ModelLibrary.Controls.Icon selectionAsIcon = GetSelectionAsIcon(e.OldValue);
			if (selectionAsIcon != null)
			{
				selectionAsIcon.DrawingElement = GetDefaultDrawing(selectionAsIcon.Data as IAModelIcon);
			}
			AspenTech.AspenPlus.ModelLibrary.Controls.Icon selectionAsIcon2 = GetSelectionAsIcon(e.NewValue);
			if (selectionAsIcon2 != null)
			{
				selectionAsIcon2.DrawingElement = GetCheckedDrawing(selectionAsIcon2.Data as IAModelIcon);
			}
		}

		private void theLibraryControl_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			DropdownButton mouseDropdownButton = e.GetMouseDropdownButton(theLibraryControl);
			if (mouseDropdownButton != null)
			{
				Model model = mouseDropdownButton.Tag as Model;
				if (model == null && mouseDropdownButton.SelectedItem is Model model2)
				{
					model = model2;
				}
				if (model != null)
				{
					_mouseDownModel = model;
					_mouseDownPosition = e.GetPosition(theLibraryControl);
				}
			}
		}

		private void theLibraryControl_PreviewMouseMove(object sender, System.Windows.Input.MouseEventArgs e)
		{
			if (e.LeftButton == MouseButtonState.Pressed && _mouseDownModel != null && _mouseDownModel.Data == _selectedModelType && (e.GetPosition(theLibraryControl) - _mouseDownPosition).Length >= 10.0)
			{
				System.Windows.DataObject dataObject = new System.Windows.DataObject();
				dataObject.SetData("AOSA Model Type Format", _selectedModelType);
				dataObject.SetData("Model Library Editor Type Format", _mouseDownModel);
				DragDrop.DoDragDrop(this, dataObject, System.Windows.DragDropEffects.Copy | System.Windows.DragDropEffects.Move);
				SelectedModelType = null;
				_mouseDownModel = null;
			}
		}

		private void theLibraryControl_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			if (_mouseDownModel != null)
			{
				_mouseDownModel = null;
			}
		}

		private void OnSelectedModelLibrariesChanged(SelectedModelLibrariesChangedEventArgs args)
		{
			Refresh();
		}

		private void OnSelectedEditCategoriesChanged(SelectedEditCategoriesChangedEventArgs args)
		{
			Refresh();
		}

		private void OnUserModelLibraryUpdated(UserModelLibraryUpdatedEventArgs args)
		{
			switch (args.Action)
			{
			case UserModelLibraryUpdatedMode.DeleteCurrentCategory:
			case UserModelLibraryUpdatedMode.RenameCurrentCategory:
			case UserModelLibraryUpdatedMode.ReorderCategories:
			case UserModelLibraryUpdatedMode.ReorderModelsInCurrentCategory:
			case UserModelLibraryUpdatedMode.DeleteCurrentModel:
			case UserModelLibraryUpdatedMode.RenameCurrentModel:
			case UserModelLibraryUpdatedMode.MoveCurrentModel:
			case UserModelLibraryUpdatedMode.CopyCurrentModel:
			case UserModelLibraryUpdatedMode.CreateNewIcon:
			case UserModelLibraryUpdatedMode.DeleteCurrentIcon:
			case UserModelLibraryUpdatedMode.ReorderIconsInCurrentModel:
			case UserModelLibraryUpdatedMode.EditDescriptionForCurrentModel:
				Refresh();
				break;
			case UserModelLibraryUpdatedMode.EditCurrentIcon:
				Refresh(clearDrawingCache: true);
				break;
			case UserModelLibraryUpdatedMode.EditUserConfiguration:
			case UserModelLibraryUpdatedMode.ClearUserConfiguration:
				break;
			}
		}

		private void OnModelTypeWizardFinished(ModelTypeWizardFinishedEventArgs e)
		{
			Refresh();
		}

		private void OnFlowsheetCancelInsertMode(EventArgs e)
		{
			theLibraryControl.IsOptionIconChecked = true;
		}

		private void OnUpdateModelPaletteEvent(EventArgs e)
		{
			ModelLibraryHelper.DestroyAndRebuildLibraries();
			Refresh(clearDrawingCache: true);
		}

		private void OnRefreshModelPaletteEvent(EventArgs e)
		{
			Refresh(clearDrawingCache: true);
		}

		private void OnProcessTypeChangedEvent(EventArgs e)
		{
			Refresh();
		}

		private AspenTech.AspenPlus.ModelLibrary.Controls.Icon GetSelectionAsIcon(object selection)
		{
			if (selection is AspenTech.AspenPlus.ModelLibrary.Controls.Icon result)
			{
				return result;
			}
			if (selection is Model model)
			{
				return model.Icons[0];
			}
			return null;
		}

		private UIElement GetDefaultDrawing(IAModelIcon modelIcon)
		{
			if (modelIcon != null)
			{
				if (!_defaultDrawings.ContainsKey(modelIcon))
				{
					_defaultDrawings.Add(modelIcon, ModelLibraryLoader.CreateDrawingElement(modelIcon, theLibraryControl.DefaultButtonBackground as SolidColorBrush));
				}
				return _defaultDrawings[modelIcon];
			}
			return null;
		}

		private UIElement GetCheckedDrawing(IAModelIcon modelIcon)
		{
			if (modelIcon != null)
			{
				if (!_checkedDrawings.ContainsKey(modelIcon))
				{
					_checkedDrawings.Add(modelIcon, ModelLibraryLoader.CreateDrawingElement(modelIcon, theLibraryControl.CheckedButtonBackground as SolidColorBrush));
				}
				return _checkedDrawings[modelIcon];
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/modellibraryscreen.xaml", UriKind.Relative);
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
				theLibraryControl = (ModelLibraryControl)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class ScreenDockConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 3)
			{
				PaneLocation? paneLocation = values[0] as PaneLocation?;
				double? num = values[1] as double?;
				double? num2 = values[2] as double?;
				if (num.HasValue && num2.HasValue)
				{
					if (num.Value >= num2.Value)
					{
						if (paneLocation == PaneLocation.DockedTop)
						{
							return Dock.Bottom;
						}
						return Dock.Top;
					}
					if (paneLocation == PaneLocation.DockedLeft)
					{
						return Dock.Left;
					}
					return Dock.Right;
				}
			}
			return Dock.Bottom;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class ReorderWindow : Window, IComponentConnector
	{
		internal System.Windows.Controls.GroupBox theGroupBox;

		internal System.Windows.Controls.ListBox theListBox;

		internal System.Windows.Controls.Button buttonUp;

		internal System.Windows.Controls.Button buttonDown;

		internal System.Windows.Controls.Button buttonOK;

		internal System.Windows.Controls.Button buttonCancel;

		private bool _contentLoaded;

		public ObservableCollection<string> Items { get; private set; }

		static ReorderWindow()
		{
			CommandManager.RegisterClassCommandBinding(typeof(ReorderWindow), new CommandBinding(ModelLibraryCommands.MoveUpCommand, MoveUpCommand_Executed, MoveUpCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(ReorderWindow), new CommandBinding(ModelLibraryCommands.MoveDownCommand, MoveDownCommand_Executed, MoveDownCommand_CanExecute));
		}

		public ReorderWindow(IEnumerable<string> items, string title, string groupHeader)
		{
			Items = new ObservableCollection<string>(items);
			InitializeComponent();
			base.Title = title;
			theGroupBox.Header = groupHeader;
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private static void MoveUpCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ReorderWindow obj = sender as ReorderWindow;
			int selectedIndex = obj.theListBox.SelectedIndex;
			obj.Items.Move(selectedIndex, selectedIndex - 1);
		}

		private static void MoveUpCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			ReorderWindow reorderWindow = sender as ReorderWindow;
			e.CanExecute = reorderWindow.theListBox.SelectedIndex > 0;
		}

		private static void MoveDownCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			ReorderWindow obj = sender as ReorderWindow;
			int selectedIndex = obj.theListBox.SelectedIndex;
			obj.Items.Move(selectedIndex, selectedIndex + 1);
		}

		private static void MoveDownCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			ReorderWindow reorderWindow = sender as ReorderWindow;
			e.CanExecute = reorderWindow.theListBox.SelectedIndex >= 0 && reorderWindow.theListBox.SelectedIndex < reorderWindow.theListBox.Items.Count - 1;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/reorderwindow.xaml", UriKind.Relative);
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
				theGroupBox = (System.Windows.Controls.GroupBox)target;
				break;
			case 2:
				theListBox = (System.Windows.Controls.ListBox)target;
				break;
			case 3:
				buttonUp = (System.Windows.Controls.Button)target;
				break;
			case 4:
				buttonDown = (System.Windows.Controls.Button)target;
				break;
			case 5:
				buttonOK = (System.Windows.Controls.Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 6:
				buttonCancel = (System.Windows.Controls.Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class TextColorPicker : System.Windows.Controls.UserControl, INotifyPropertyChanged, IComponentConnector
	{
		private int m_iCurrentColor;

		private int m_iColorSelect;

		internal System.Windows.Shapes.Rectangle TextColor0a;

		internal System.Windows.Shapes.Rectangle TextColor1a;

		internal System.Windows.Shapes.Rectangle TextColor2a;

		internal System.Windows.Shapes.Rectangle TextColor3a;

		internal System.Windows.Shapes.Rectangle TextColor4a;

		internal System.Windows.Shapes.Rectangle TextColor5a;

		internal System.Windows.Shapes.Rectangle TextColor6a;

		internal System.Windows.Shapes.Rectangle TextColor7a;

		internal System.Windows.Shapes.Rectangle TextColor8a;

		internal System.Windows.Shapes.Rectangle TextColor9a;

		internal System.Windows.Shapes.Rectangle TextColor10a;

		internal System.Windows.Shapes.Rectangle TextColor11a;

		internal System.Windows.Shapes.Rectangle TextColor12a;

		internal System.Windows.Shapes.Rectangle TextColor13a;

		internal System.Windows.Shapes.Rectangle TextColor14a;

		internal System.Windows.Shapes.Rectangle TextColor15a;

		internal System.Windows.Shapes.Rectangle TextColor0;

		internal System.Windows.Shapes.Rectangle TextColor1;

		internal System.Windows.Shapes.Rectangle TextColor2;

		internal System.Windows.Shapes.Rectangle TextColor3;

		internal System.Windows.Shapes.Rectangle TextColor4;

		internal System.Windows.Shapes.Rectangle TextColor5;

		internal System.Windows.Shapes.Rectangle TextColor6;

		internal System.Windows.Shapes.Rectangle TextColor7;

		internal System.Windows.Shapes.Rectangle TextColor8;

		internal System.Windows.Shapes.Rectangle TextColor9;

		internal System.Windows.Shapes.Rectangle TextColor10;

		internal System.Windows.Shapes.Rectangle TextColor11;

		internal System.Windows.Shapes.Rectangle TextColor12;

		internal System.Windows.Shapes.Rectangle TextColor13;

		internal System.Windows.Shapes.Rectangle TextColor14;

		internal System.Windows.Shapes.Rectangle TextColor15;

		private bool _contentLoaded;

		public int CurrentColor
		{
			get
			{
				return m_iCurrentColor;
			}
			set
			{
				m_iCurrentColor = value;
			}
		}

		public int ColorSelect
		{
			get
			{
				return m_iColorSelect;
			}
			set
			{
				m_iColorSelect = value;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public TextColorPicker()
		{
			InitializeComponent();
			PropertyChanged += Color_PropertyChanged;
			base.Loaded += UserControl1_Loaded;
			base.Unloaded += UserControl1_Unloaded;
		}

		protected void Notify(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}

		private void UserControl1_Loaded(object sender, RoutedEventArgs e)
		{
			System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)FindName("TextColor" + m_iCurrentColor);
			UnHighlightRectangle(rect);
			Color_OnSelectedChanged(m_iColorSelect);
		}

		private void UserControl1_Unloaded(object sender, RoutedEventArgs e)
		{
		}

		private void Color_PropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			string propertyName = e.PropertyName;
			if (!(propertyName == "CurrentColor") && propertyName == "ColorSelect")
			{
				Color_OnSelectedChanged(m_iColorSelect);
			}
		}

		private void Color_OnSelectedChanged(int iSelectedIndex)
		{
			m_iCurrentColor = iSelectedIndex;
			string name = "TextColor" + m_iCurrentColor;
			System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)FindName(name);
			UnHighlightRectangle(rect);
			name = "TextColor" + iSelectedIndex;
			System.Windows.Shapes.Rectangle rect2 = (System.Windows.Shapes.Rectangle)FindName(name);
			HighlightRectangle(rect2);
		}

		private void Color_MouseEnter(object sender, System.Windows.Input.MouseEventArgs e)
		{
			HighlightRectangle((System.Windows.Shapes.Rectangle)e.Source);
		}

		private void Color_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
		{
			int result = 0;
			int.TryParse((e.Source as System.Windows.Shapes.Rectangle).Tag.ToString(), out result);
			if (result != m_iColorSelect)
			{
				UnHighlightRectangle((System.Windows.Shapes.Rectangle)e.Source);
			}
		}

		private void Color_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			System.Windows.Shapes.Rectangle obj = e.Source as System.Windows.Shapes.Rectangle;
			int result = 0;
			int.TryParse(obj.Tag.ToString(), out result);
			if (result != m_iColorSelect)
			{
				System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)FindName("TextColor" + m_iColorSelect);
				UnHighlightRectangle(rect);
				System.Windows.Shapes.Rectangle rect2 = (System.Windows.Shapes.Rectangle)FindName("TextColor" + result);
				HighlightRectangle(rect2);
				m_iColorSelect = result;
				m_iCurrentColor = result;
			}
		}

		private void HighlightRectangle(System.Windows.Shapes.Rectangle rect)
		{
			if (rect != null)
			{
				string name = rect.Name;
				name += "a";
				System.Windows.Shapes.Rectangle obj = (System.Windows.Shapes.Rectangle)FindName(name);
				rect.Stroke = System.Windows.Media.Brushes.White;
				obj.Stroke = System.Windows.Media.Brushes.Red;
			}
		}

		private void UnHighlightRectangle(System.Windows.Shapes.Rectangle rect)
		{
			if (rect != null)
			{
				string name = rect.Name;
				name += "a";
				System.Windows.Shapes.Rectangle obj = (System.Windows.Shapes.Rectangle)FindName(name);
				rect.Stroke = System.Windows.Media.Brushes.Black;
				obj.Stroke = System.Windows.Media.Brushes.White;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.ModelLibrary;component/textcolorpicker.xaml", UriKind.Relative);
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
				TextColor0a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 2:
				TextColor1a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 3:
				TextColor2a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 4:
				TextColor3a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 5:
				TextColor4a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 6:
				TextColor5a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 7:
				TextColor6a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 8:
				TextColor7a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 9:
				TextColor8a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 10:
				TextColor9a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 11:
				TextColor10a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 12:
				TextColor11a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 13:
				TextColor12a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 14:
				TextColor13a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 15:
				TextColor14a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 16:
				TextColor15a = (System.Windows.Shapes.Rectangle)target;
				break;
			case 17:
				TextColor0 = (System.Windows.Shapes.Rectangle)target;
				TextColor0.MouseEnter += Color_MouseEnter;
				TextColor0.MouseLeave += Color_MouseLeave;
				TextColor0.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 18:
				TextColor1 = (System.Windows.Shapes.Rectangle)target;
				TextColor1.MouseEnter += Color_MouseEnter;
				TextColor1.MouseLeave += Color_MouseLeave;
				TextColor1.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 19:
				TextColor2 = (System.Windows.Shapes.Rectangle)target;
				TextColor2.MouseEnter += Color_MouseEnter;
				TextColor2.MouseLeave += Color_MouseLeave;
				TextColor2.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 20:
				TextColor3 = (System.Windows.Shapes.Rectangle)target;
				TextColor3.MouseEnter += Color_MouseEnter;
				TextColor3.MouseLeave += Color_MouseLeave;
				TextColor3.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 21:
				TextColor4 = (System.Windows.Shapes.Rectangle)target;
				TextColor4.MouseEnter += Color_MouseEnter;
				TextColor4.MouseLeave += Color_MouseLeave;
				TextColor4.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 22:
				TextColor5 = (System.Windows.Shapes.Rectangle)target;
				TextColor5.MouseEnter += Color_MouseEnter;
				TextColor5.MouseLeave += Color_MouseLeave;
				TextColor5.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 23:
				TextColor6 = (System.Windows.Shapes.Rectangle)target;
				TextColor6.MouseEnter += Color_MouseEnter;
				TextColor6.MouseLeave += Color_MouseLeave;
				TextColor6.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 24:
				TextColor7 = (System.Windows.Shapes.Rectangle)target;
				TextColor7.MouseEnter += Color_MouseEnter;
				TextColor7.MouseLeave += Color_MouseLeave;
				TextColor7.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 25:
				TextColor8 = (System.Windows.Shapes.Rectangle)target;
				TextColor8.MouseEnter += Color_MouseEnter;
				TextColor8.MouseLeave += Color_MouseLeave;
				TextColor8.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 26:
				TextColor9 = (System.Windows.Shapes.Rectangle)target;
				TextColor9.MouseEnter += Color_MouseEnter;
				TextColor9.MouseLeave += Color_MouseLeave;
				TextColor9.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 27:
				TextColor10 = (System.Windows.Shapes.Rectangle)target;
				TextColor10.MouseEnter += Color_MouseEnter;
				TextColor10.MouseLeave += Color_MouseLeave;
				TextColor10.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 28:
				TextColor11 = (System.Windows.Shapes.Rectangle)target;
				TextColor11.MouseEnter += Color_MouseEnter;
				TextColor11.MouseLeave += Color_MouseLeave;
				TextColor11.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 29:
				TextColor12 = (System.Windows.Shapes.Rectangle)target;
				TextColor12.MouseEnter += Color_MouseEnter;
				TextColor12.MouseLeave += Color_MouseLeave;
				TextColor12.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 30:
				TextColor13 = (System.Windows.Shapes.Rectangle)target;
				TextColor13.MouseEnter += Color_MouseEnter;
				TextColor13.MouseLeave += Color_MouseLeave;
				TextColor13.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 31:
				TextColor14 = (System.Windows.Shapes.Rectangle)target;
				TextColor14.MouseEnter += Color_MouseEnter;
				TextColor14.MouseLeave += Color_MouseLeave;
				TextColor14.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			case 32:
				TextColor15 = (System.Windows.Shapes.Rectangle)target;
				TextColor15.MouseEnter += Color_MouseEnter;
				TextColor15.MouseLeave += Color_MouseLeave;
				TextColor15.MouseLeftButtonDown += Color_MouseLeftButtonDown;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UserModelLibrary : NotifyPropertyChangedBase
	{
		private string _displayName;

		private bool _isInUse;

		private bool _isBuiltIn;

		private string _location;

		public string DisplayName
		{
			get
			{
				return _displayName;
			}
			set
			{
				if (_displayName != value)
				{
					_displayName = value;
					OnPropertyChanged("DisplayName");
				}
			}
		}

		public bool IsInUse
		{
			get
			{
				return _isInUse;
			}
			set
			{
				if (_isInUse != value)
				{
					_isInUse = value;
					OnPropertyChanged("IsInUse");
				}
			}
		}

		public bool IsBuiltIn
		{
			get
			{
				return _isBuiltIn;
			}
			set
			{
				if (_isBuiltIn != value)
				{
					_isBuiltIn = value;
					OnPropertyChanged("IsBuiltIn");
					OnPropertyChanged("DetailButtonText");
					OnPropertyChanged("LocationButtonText");
				}
			}
		}

		public string Location
		{
			get
			{
				return _location;
			}
			set
			{
				if (_location != value)
				{
					_location = value;
					OnPropertyChanged("Location");
					OnPropertyChanged("LocationButtonText");
				}
			}
		}

		public string DetailButtonText
		{
			get
			{
				if (IsBuiltIn)
				{
					return ModelLibraryResources.ManagerWindowGridViewButton;
				}
				return ModelLibraryResources.ManagerWindowGridEditButton;
			}
		}

		public string LocationButtonText
		{
			get
			{
				if (IsBuiltIn)
				{
					return ModelLibraryResources.ManagerWindowGridLocationBuiltIn;
				}
				return Location;
			}
		}

		public IAEditCategories UnamangedIAEditCategories
		{
			get
			{
				if (!string.IsNullOrEmpty(DisplayName))
				{
					return ModelLibraryHelper.GetIAEditCategories(DisplayName);
				}
				return null;
			}
		}
	}
}
namespace AspenTech.AspenPlus.ModelLibrary.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
// The original COM types below are embedded from Interop.Aosapfs and Interop.Happ.
// Compile with both original primary interop assemblies and EmbedInteropTypes enabled.
// namespace AspenTech.AspenPlus.Aosapfs
// {
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("A89BB1D0-1057-11D2-80E4-0000C09EFCF3")]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[TypeIdentifier]
// 	public interface IACategory
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetName(ref byte pName, int nSize);
//
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void AddModelType([MarshalAs(UnmanagedType.Interface)] IAModelType pModelType);
//
// 		void _VtblGap2_2();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void EnumModelType([MarshalAs(UnmanagedType.Interface)] ref IEnumAModelType ppEnum);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[Guid("A89BB1D2-1057-11D2-80E4-0000C09EFCF3")]
// 	[TypeIdentifier]
// 	public interface IAEditCategories
// 	{
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void RemoveCategory([MarshalAs(UnmanagedType.Interface)] IACategory pCategory);
//
// 		void _VtblGap2_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void EnumCategories([MarshalAs(UnmanagedType.Interface)] ref IEnumACategory ppEnum);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[Guid("B19E42B3-7889-11D0-A91B-0000C0A118DB")]
// 	[TypeIdentifier]
// 	public interface IAEditModelIcons
// 	{
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void SetCurrentIcon([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);
//
// 		void _VtblGap2_2();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void RemoveIcon([MarshalAs(UnmanagedType.Interface)] IAModelIcon pModelIcon);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("B19E42BF-7889-11D0-A91B-0000C0A118DB")]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[TypeIdentifier]
// 	public interface IAModel
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetName(ref byte pName, int size);
//
// 		void _VtblGap1_3();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetModelType([MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[Guid("B19E42B7-7889-11D0-A91B-0000C0A118DB")]
// 	[TypeIdentifier]
// 	public interface IAModelIcon
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetName(ref byte pName, int size);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[Guid("B19E42B2-7889-11D0-A91B-0000C0A118DB")]
// 	[TypeIdentifier]
// 	public interface IAModelType
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetName(ref byte pName, int nSize);
//
// 		void _VtblGap1_6();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void GetProcessType(ref ProcessTypeRestriction pProcType);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[Guid("A89BB1D1-1057-11D2-80E4-0000C09EFCF3")]
// 	[TypeIdentifier]
// 	public interface IEnumACategory
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IACategory ppCategory, ref uint pnumFetched);
//
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Reset();
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("B19E42C0-7889-11D0-A91B-0000C0A118DB")]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[TypeIdentifier]
// 	public interface IEnumAModel
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModel ppModel, ref uint pnumFetched);
//
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Reset();
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("B19E42B1-7889-11D0-A91B-0000C0A118DB")]
// 	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
// 	[TypeIdentifier]
// 	public interface IEnumAModelType
// 	{
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Next(uint nCount, [MarshalAs(UnmanagedType.Interface)] ref IAModelType ppModelType, ref uint pnumFetched);
//
// 		void _VtblGap1_1();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		void Reset();
// 	}
// 	[CompilerGenerated]
// 	[TypeIdentifier("8080E641-57DE-497B-B834-ABCCB50A4CA2", "AspenTech.AspenPlus.Aosapfs.ProcessTypeRestriction")]
// 	public enum ProcessTypeRestriction
// 	{
// 		ProcessTypeNone = -1,
// 		ProcessTypeAny,
// 		ProcessTypeBatch,
// 		ProcessTypeContinuous
// 	}
// }
// namespace AspenTech.AspenPlus.Happ
// {
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("8E567522-F9BA-11CF-90B2-0000C0A810C4")]
// 	[TypeIdentifier]
// 	public interface IHNode
// 	{
// 		void _VtblGap1_12();
//
// 		[DispId(1610743820)]
// 		object AttributeValue[[In] short attrnumber, [In, Optional, MarshalAs(UnmanagedType.Struct)] object force]
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743820)]
// 			[return: MarshalAs(UnmanagedType.Struct)]
// 			get;
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743820)]
// 			[param: In]
// 			[param: MarshalAs(UnmanagedType.Struct)]
// 			set;
// 		}
// 	}
// }

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000001 <>f__AnonymousType0`2.get_category
// {
// 	return <category>i__Field;
// }

// 0x06000002 <>f__AnonymousType0`2.get_model
// {
// 	return <model>i__Field;
// }

// 0x06000003 <>f__AnonymousType0`2..ctor
// using System.Diagnostics;
//
// [DebuggerHidden]
// public <>f__AnonymousType0(<category>j__TPar category, <model>j__TPar model)
// {
// 	<category>i__Field = category;
// 	<model>i__Field = model;
// }

// 0x06000004 <>f__AnonymousType0`2.Equals
// using System.Collections.Generic;
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override bool Equals(object value)
// {
// 	global::<>f__AnonymousType0<<category>j__TPar, <model>j__TPar> anon = value as global::<>f__AnonymousType0<<category>j__TPar, <model>j__TPar>;
// 	if (this != anon)
// 	{
// 		if (anon != null && EqualityComparer<<category>j__TPar>.Default.Equals(<category>i__Field, anon.<category>i__Field))
// 		{
// 			return EqualityComparer<<model>j__TPar>.Default.Equals(<model>i__Field, anon.<model>i__Field);
// 		}
// 		return false;
// 	}
// 	return true;
// }

// 0x06000005 <>f__AnonymousType0`2.GetHashCode
// using System.Collections.Generic;
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override int GetHashCode()
// {
// 	return (-597602263 * -1521134295 + EqualityComparer<<category>j__TPar>.Default.GetHashCode(<category>i__Field)) * -1521134295 + EqualityComparer<<model>j__TPar>.Default.GetHashCode(<model>i__Field);
// }

// 0x06000006 <>f__AnonymousType0`2.ToString
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override string ToString()
// {
// 	object[] array = new object[2];
// 	<category>j__TPar val = <category>i__Field;
// 	array[0] = ((val != null) ? val.ToString() : null);
// 	<model>j__TPar val2 = <model>i__Field;
// 	array[1] = ((val2 != null) ? val2.ToString() : null);
// 	return string.Format(null, "{{ category = {0}, model = {1} }}", array);
// }

// 0x0600000c XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x06000032 AspenTech.AspenPlus.ModelLibrary.Data..ctor
// public Data()
// {
// }

// 0x060000a2 AspenTech.AspenPlus.ModelLibrary.ModelLibraryIconEditorScreenContextualRibbon..cctor
// using System.Collections.ObjectModel;
// using System.Windows;
//
// static ModelLibraryIconEditorScreenContextualRibbon()
// {
// 	TextColorItemsProperty = DependencyProperty.Register("TextColorItems", typeof(ObservableCollection<UIElement>), typeof(ModelLibraryIconEditorScreenContextualRibbon));
// }

// 0x060000a9 AspenTech.AspenPlus.ModelLibrary.ModelLibraryIconEditorScreenSubject..ctor
// public ModelLibraryIconEditorScreenSubject()
// {
// }

// 0x060000c1 AspenTech.AspenPlus.ModelLibrary.ModelTypeUserConfigurationScreen.add_PropertyChanged
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

// 0x060000c2 AspenTech.AspenPlus.ModelLibrary.ModelTypeUserConfigurationScreen.remove_PropertyChanged
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

// 0x060000d0 AspenTech.AspenPlus.ModelLibrary.MyColorConverter..ctor
// public MyColorConverter()
// {
// }

// 0x060000d5 AspenTech.AspenPlus.ModelLibrary.ModelTypeUserConfigurationScreenSubject..ctor
// public ModelTypeUserConfigurationScreenSubject()
// {
// }

// 0x06000116 AspenTech.AspenPlus.ModelLibrary.EnterDescriptionWindow..cctor
// using System.Windows;
//
// static EnterDescriptionWindow()
// {
// 	ModelTypeNameProperty = DependencyProperty.Register("ModelTypeName", typeof(string), typeof(EnterDescriptionWindow));
// 	DescriptionProperty = DependencyProperty.Register("Description", typeof(string), typeof(EnterDescriptionWindow), new FrameworkPropertyMetadata(OnDescriptionPropertyChanged));
// }

// 0x06000120 AspenTech.AspenPlus.ModelLibrary.ModelLibraryCommands..cctor
// using System.Windows.Input;
// using AspenTech.AspenPlus.Localization;
//
// static ModelLibraryCommands()
// {
// 	MoveUpCommand = new RoutedUICommand(ModelLibraryResources.MoveUp, "MoveUp", typeof(ModelLibraryCommands));
// 	MoveDownCommand = new RoutedUICommand(ModelLibraryResources.MoveDown, "MoveDown", typeof(ModelLibraryCommands));
// 	CreateNewCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCreateNewCategory, "CreateNewCategory", typeof(ModelLibraryCommands));
// 	DeleteCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentCategory, "DeleteCurrentCategory", typeof(ModelLibraryCommands));
// 	RenameCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandRenameCurrentCategory, "RenameCurrentCategory", typeof(ModelLibraryCommands));
// 	ReorderCategories = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderCategories, "ReorderCategories", typeof(ModelLibraryCommands));
// 	ReorderModelsInCurrentCategory = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderModelsInCurrentCategory, "ReorderModelsInCurrentCategory", typeof(ModelLibraryCommands));
// 	DeleteCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentModel, "DeleteCurrentModel", typeof(ModelLibraryCommands));
// 	RenameCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandRenameCurrentModel, "RenameCurrentModel", typeof(ModelLibraryCommands));
// 	MoveCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandMoveCurrentModel, "MoveCurrentModel", typeof(ModelLibraryCommands));
// 	CopyCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCopyCurrentModel, "CopyCurrentModel", typeof(ModelLibraryCommands));
// 	EditDescriptionForCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditDescriptionForCurrentModel, "EditDescriptionForCurrentModel", typeof(ModelLibraryCommands));
// 	EditUserConfiguration = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditUserConfiguration, "EditUserConfiguration", typeof(ModelLibraryCommands));
// 	ClearUserConfiguration = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandClearUserConfiguration, "ClearUserConfiguration", typeof(ModelLibraryCommands));
// 	EditCurrentIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandEditCurrentIcon, "EditCurrentIcon", typeof(ModelLibraryCommands));
// 	CreateNewIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandCreateNewIcon, "CreateNewIcon", typeof(ModelLibraryCommands));
// 	DeleteCurrentIcon = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandDeleteCurrentIcon, "DeleteCurrentIcon", typeof(ModelLibraryCommands));
// 	ReorderIconsInCurrentModel = new RoutedUICommand(ModelLibraryResources.EditorScreenCommandReorderIconsInCurrentModel, "ReorderIconsInCurrentModel", typeof(ModelLibraryCommands));
// }

// 0x06000123 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItem..ctor
// public ModelTypeWizardItem()
// {
// }

// 0x06000145 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemModelTypeOptions..cctor
// using System.Windows;
//
// static ModelTypeWizardItemModelTypeOptions()
// {
// 	ModelTypeNameProperty = DependencyProperty.Register("ModelTypeName", typeof(string), typeof(ModelTypeWizardItemModelTypeOptions), new FrameworkPropertyMetadata(OnModelTypeNamePropertyChanged));
// 	IsToCopyDefaultIconProperty = DependencyProperty.Register("IsToCopyDefaultIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyDefaultIconEnabledProperty = DependencyProperty.Register("IsToCopyDefaultIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyCurrentIconProperty = DependencyProperty.Register("IsToCopyCurrentIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyCurrentIconEnabledProperty = DependencyProperty.Register("IsToCopyCurrentIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyAllIconProperty = DependencyProperty.Register("IsToCopyAllIcon", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyAllIconEnabledProperty = DependencyProperty.Register("IsToCopyAllIconEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyTemplateProperty = DependencyProperty.Register("IsToCopyTemplate", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyTemplateEnabledProperty = DependencyProperty.Register("IsToCopyTemplateEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyUserConfigurationProperty = DependencyProperty.Register("IsToCopyUserConfiguration", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// 	IsToCopyUserConfigurationEnabledProperty = DependencyProperty.Register("IsToCopyUserConfigurationEnabled", typeof(bool), typeof(ModelTypeWizardItemModelTypeOptions));
// }

// 0x06000147 AspenTech.AspenPlus.ModelLibrary.ModelTypeValicationRule..ctor
// public ModelTypeValicationRule()
// {
// }

// 0x06000156 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectAdditionalRecords..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static ModelTypeWizardItemSelectAdditionalRecords()
// {
// 	RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<ModelTypeWizardRecordNode>), typeof(ModelTypeWizardItemSelectAdditionalRecords));
// }

// 0x06000159 AspenTech.AspenPlus.ModelLibrary.RecordNodeIsEnabledToVisibilityConverter..ctor
// public RecordNodeIsEnabledToVisibilityConverter()
// {
// }

// 0x06000168 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectCategory..cctor
// using System.Windows;
// using AspenTech.AspenPlus.ModelLibrary.Controls;
//
// static ModelTypeWizardItemSelectCategory()
// {
// 	IntroductionTextProperty = DependencyProperty.Register("IntroductionText", typeof(string), typeof(ModelTypeWizardItemSelectCategory));
// 	SelectedCategoryProperty = DependencyProperty.Register("SelectedCategory", typeof(Category), typeof(ModelTypeWizardItemSelectCategory), new FrameworkPropertyMetadata(OnSelectedCategoryPropertyChanged));
// }

// 0x06000174 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectLibrary..cctor
// using System.Windows;
//
// static ModelTypeWizardItemSelectLibrary()
// {
// 	SelectedLibraryProperty = DependencyProperty.Register("SelectedLibrary", typeof(UserModelLibrary), typeof(ModelTypeWizardItemSelectLibrary), new FrameworkPropertyMetadata(OnSelectedLibraryPropertyChanged));
// }

// 0x06000180 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectModelType..cctor
// using System.Windows;
//
// static ModelTypeWizardItemSelectModelType()
// {
// 	SelectedModelTypeProperty = DependencyProperty.Register("SelectedModelType", typeof(string), typeof(ModelTypeWizardItemSelectModelType), new FrameworkPropertyMetadata(OnSelectedModelTypePropertyChanged));
// }

// 0x06000190 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSingleBlock..cctor
// using System.Windows;
//
// static ModelTypeWizardItemSingleBlock()
// {
// 	IsSingleBlockProperty = DependencyProperty.Register("IsSingleBlock", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));
// 	IsMultiRecordProperty = DependencyProperty.Register("IsMultiRecord", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));
// 	IsToCreateWithoutHierarchyProperty = DependencyProperty.Register("IsToCreateWithoutHierarchy", typeof(bool), typeof(ModelTypeWizardItemSingleBlock));
// }

// 0x0600019e AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemWelcome..cctor
// using System.Windows;
//
// static ModelTypeWizardItemWelcome()
// {
// 	IsAddCheckedProperty = DependencyProperty.Register("IsAddChecked", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));
// 	IsAppendCheckedProperty = DependencyProperty.Register("IsAppendChecked", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(false));
// 	CanAddProperty = DependencyProperty.Register("CanAdd", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));
// 	CanAppendProperty = DependencyProperty.Register("CanAppend", typeof(bool), typeof(ModelTypeWizardItemWelcome), new UIPropertyMetadata(true));
// }

// 0x060001c1 AspenTech.AspenPlus.ModelLibrary.MoveModeToOtherCategoryWindow..cctor
// using System.Windows;
// using AspenTech.AspenPlus.ModelLibrary.Controls;
//
// static MoveModeToOtherCategoryWindow()
// {
// 	SelectedCategoryProperty = DependencyProperty.Register("SelectedCategory", typeof(Category), typeof(MoveModeToOtherCategoryWindow), new FrameworkPropertyMetadata(OnSelectedCategoryPropertyChanged));
// }

// 0x060001c6 AspenTech.AspenPlus.ModelLibrary.SimpleCategoryInfo..ctor
// public SimpleCategoryInfo()
// {
// }

// 0x060001ef AspenTech.AspenPlus.ModelLibrary.ModelLibrariesManagerWindow..cctor
// using System.Collections.Generic;
//
// static ModelLibrariesManagerWindow()
// {
// 	_editorPaneNames = new Dictionary<string, string>();
// }

// 0x06000247 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static ModelLibraryEditorScreen()
// {
// 	_iconEditorPaneNames = new Dictionary<string, string>();
// 	_configurationEditorPaneNames = new Dictionary<string, string>();
// 	EditableUserNames = new string[2] { "USER2", "USER3" };
// 	DefaultSize = new Size(800.0, 160.0);
// }

// 0x06000251 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreenSubject..ctor
// public ModelLibraryEditorScreenSubject()
// {
// }

// 0x06000268 AspenTech.AspenPlus.ModelLibrary.ModelLibraryLoader..cctor
// using System.Windows;
//
// static ModelLibraryLoader()
// {
// 	s_strLocalizedStreamCategoryName = string.Empty;
// 	DefaultIconSize = new Size(70.0, 70.0);
// }

// 0x060002a6 AspenTech.AspenPlus.ModelLibrary.ScreenDockConverter..ctor
// public ScreenDockConverter()
// {
// }

// 0x060002b4 AspenTech.AspenPlus.ModelLibrary.TextColorPicker.add_PropertyChanged
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

// 0x060002b5 AspenTech.AspenPlus.ModelLibrary.TextColorPicker.remove_PropertyChanged
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

// 0x060002d1 AspenTech.AspenPlus.ModelLibrary.UserModelLibrary..ctor
// public UserModelLibrary()
// {
// }

// 0x060002d3 AspenTech.AspenPlus.ModelLibrary.Properties.Settings..ctor
// public Settings()
// {
// }

// 0x060002d4 AspenTech.AspenPlus.ModelLibrary.Properties.Settings..cctor
// using System.Configuration;
//
// static Settings()
// {
// 	defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());
// }

// 0x060002f5 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemModelTypeOptions+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060002f6 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemModelTypeOptions+<>c..ctor
// public <>c()
// {
// }

// 0x0600030d AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectCategory+<>c__DisplayClass14_0..ctor
// public <>c__DisplayClass14_0()
// {
// }

// 0x0600030f AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectLibrary+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000310 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectLibrary+<>c..ctor
// public <>c()
// {
// }

// 0x06000312 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectLibrary+<>c__DisplayClass10_0..ctor
// public <>c__DisplayClass10_0()
// {
// }

// 0x06000314 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemSelectModelType+<>c__DisplayClass10_0..ctor
// public <>c__DisplayClass10_0()
// {
// }

// 0x06000316 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemWelcome+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000317 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardItemWelcome+<>c..ctor
// public <>c()
// {
// }

// 0x06000319 AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardRecordNode+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031a AspenTech.AspenPlus.ModelLibrary.ModelTypeWizardRecordNode+<>c..ctor
// public <>c()
// {
// }

// 0x0600031e AspenTech.AspenPlus.ModelLibrary.ModelCategoriesManagerWindow+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031f AspenTech.AspenPlus.ModelLibrary.ModelCategoriesManagerWindow+<>c..ctor
// public <>c()
// {
// }

// 0x06000321 AspenTech.AspenPlus.ModelLibrary.ModelLibrariesManagerWindow+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000322 AspenTech.AspenPlus.ModelLibrary.ModelLibrariesManagerWindow+<>c..ctor
// public <>c()
// {
// }

// 0x06000325 AspenTech.AspenPlus.ModelLibrary.ModelLibrariesManagerWindow+<>c__DisplayClass20_0..ctor
// public <>c__DisplayClass20_0()
// {
// }

// 0x06000329 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600032a AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c..ctor
// public <>c()
// {
// }

// 0x06000332 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c.<RenameCurrentModel_Executed>b__68_1
// using AspenTech.AspenPlus.ModelLibrary.Controls;
//
// internal global::<>f__AnonymousType0<Category, Model> <RenameCurrentModel_Executed>b__68_1(Category category, Model model)
// {
// 	return new global::<>f__AnonymousType0<Category, Model>(category, model);
// }

// 0x06000335 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c__DisplayClass24_0..ctor
// public <>c__DisplayClass24_0()
// {
// }

// 0x06000337 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c__DisplayClass56_0..ctor
// public <>c__DisplayClass56_0()
// {
// }

// 0x06000339 AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c__DisplayClass60_0..ctor
// public <>c__DisplayClass60_0()
// {
// }

// 0x0600033b AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c__DisplayClass68_0..ctor
// public <>c__DisplayClass68_0()
// {
// }

// 0x0600033d AspenTech.AspenPlus.ModelLibrary.ModelLibraryEditorScreen+<>c__DisplayClass70_0..ctor
// public <>c__DisplayClass70_0()
// {
// }

// 0x0600033f AspenTech.AspenPlus.ModelLibrary.ModelLibraryLoader+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000340 AspenTech.AspenPlus.ModelLibrary.ModelLibraryLoader+<>c..ctor
// public <>c()
// {
// }

// 0x06000342 AspenTech.AspenPlus.ModelLibrary.ModelLibraryLoader+<>c__DisplayClass21_0..ctor
// public <>c__DisplayClass21_0()
// {
// }

// 0x0600035d AspenTech.AspenPlus.ModelLibrary.ModelLibraryPresenter+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600035e AspenTech.AspenPlus.ModelLibrary.ModelLibraryPresenter+<>c..ctor
// public <>c()
// {
// }

// 0x06000360 AspenTech.AspenPlus.ModelLibrary.ModelLibraryScreen+<>c__DisplayClass22_0..ctor
// public <>c__DisplayClass22_0()
// {
// }
