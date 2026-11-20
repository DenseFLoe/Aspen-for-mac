using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.Scripting;
using AspenTech.AspenPlus.MMDialogs.Modules.Dialogs;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Visualisation.CommonShell;
using AspenTech.WpfControls.Engineering;
using AxAdvancedFileDialogLib;
using Infragistics.Windows;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Logging;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMDialogs")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMDialogs")]
[assembly: AssemblyCopyright("Copyright 漏 Aspen Technology, Inc. 2010 - 2024, All rights reserved")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("ca9e3a80-c6bc-42d5-9590-8da558585b39")]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
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
namespace AspenTech.AspenPlus.MMDialogs
{
	public class ACMModelConflictsDlg : MMDialog, IComponentConnector
	{
		public class ACMModelConflict
		{
			public string Model { get; set; }

			public string Installed { get; set; }

			public string Case { get; set; }

			public bool Action { get; set; }
		}

		public List<ACMModelConflict> ACMModelConflictList;

		public string sModelInstallFlags = string.Empty;

		public List<ACMModelConflict> ACMModelConflictListE;

		public string sModelInstallFlagsE = string.Empty;

		internal ACMModelConflictsDlg dlg;

		internal Grid grid1;

		internal System.Windows.Controls.Label DeployN;

		internal System.Windows.Controls.Label EditN;

		internal System.Windows.Controls.Button Ok;

		internal System.Windows.Controls.Button Cancel;

		internal System.Windows.Controls.DataGrid dgConflictList;

		internal System.Windows.Controls.DataGrid dgConflictListE;

		private bool _contentLoaded;

		public string HelpFile
		{
			get
			{
				if (!SystemEnvironment.IsAspenProperties)
				{
					return "userguide3.chm";
				}
				return "plotwiz.chm";
			}
		}

		public int HelpId
		{
			get
			{
				if (!SystemEnvironment.IsAspenProperties)
				{
					return 72;
				}
				return 6;
			}
		}

		public void LoadModelConflictList(string sModelInfoList, string sModelInfoListE)
		{
			if ((sModelInfoList == null || sModelInfoList.Length <= 0) && (sModelInfoListE == null || sModelInfoListE.Length <= 0))
			{
				return;
			}
			if (sModelInfoList != null && sModelInfoList.Length > 0)
			{
				string[] array = sModelInfoList.Split('|');
				ACMModelConflictList = new List<ACMModelConflict>();
				for (int i = 0; i < array.Length; i++)
				{
					string[] array2 = array[i].Split(',');
					if (array2.Length >= 6)
					{
						ACMModelConflict aCMModelConflict = new ACMModelConflict();
						aCMModelConflict.Model = array2[0];
						aCMModelConflict.Installed = array2[1];
						if (!string.IsNullOrEmpty(array2[2]))
						{
							aCMModelConflict.Installed += " - ";
							aCMModelConflict.Installed += ConvertTimestamp(array2[2]);
						}
						aCMModelConflict.Case = array2[3];
						if (!string.IsNullOrEmpty(array2[4]))
						{
							aCMModelConflict.Case += " - ";
							aCMModelConflict.Case += ConvertTimestamp(array2[4]);
						}
						aCMModelConflict.Action = array2[5] == "Yes";
						ACMModelConflictList.Add(aCMModelConflict);
					}
				}
			}
			if (sModelInfoListE == null || sModelInfoListE.Length <= 0)
			{
				return;
			}
			string[] array3 = sModelInfoListE.Split('|');
			ACMModelConflictListE = new List<ACMModelConflict>();
			for (int j = 0; j < array3.Length; j++)
			{
				string[] array4 = array3[j].Split(',');
				if (array4.Length >= 6)
				{
					ACMModelConflict aCMModelConflict2 = new ACMModelConflict();
					aCMModelConflict2.Model = array4[0];
					aCMModelConflict2.Installed = array4[1];
					if (!string.IsNullOrEmpty(array4[2]))
					{
						aCMModelConflict2.Installed += " - ";
						aCMModelConflict2.Installed += ConvertTimestamp(array4[2]);
					}
					aCMModelConflict2.Case = array4[3];
					if (!string.IsNullOrEmpty(array4[4]))
					{
						aCMModelConflict2.Case += " - ";
						aCMModelConflict2.Case += ConvertTimestamp(array4[4]);
					}
					aCMModelConflict2.Action = array4[5] == "Yes";
					ACMModelConflictListE.Add(aCMModelConflict2);
				}
			}
		}

		private string ConvertTimestamp(string sTimeStamp)
		{
			string result = sTimeStamp;
			string[] array = sTimeStamp.Split('.');
			if (array.Length == 6)
			{
				try
				{
					result = new DateTime(Convert.ToInt32(array[0]), Convert.ToInt32(array[1]), Convert.ToInt32(array[2]), Convert.ToInt32(array[3]), Convert.ToInt32(array[4]), Convert.ToInt32(array[5])).ToString();
				}
				catch
				{
				}
			}
			return result;
		}

		public ACMModelConflictsDlg(string sModelInfoList, string sModelInfoListE)
		{
			LoadModelConflictList(sModelInfoList, sModelInfoListE);
			InitializeComponent();
			Mouse.OverrideCursor = System.Windows.Input.Cursors.Wait;
			dgConflictList.ItemsSource = ACMModelConflictList;
			dgConflictListE.ItemsSource = ACMModelConflictListE;
			if (sModelInfoList == null || sModelInfoList.Length <= 0)
			{
				CollapsedDeployed();
			}
			if (sModelInfoListE == null || sModelInfoListE.Length <= 0)
			{
				CollapsedEdited();
			}
			base.Loaded += ACMConflictsDlg_Loaded;
			base.Closing += ACMConflictsDlg_Closing;
		}

		private void ACMConflictsDlg_Loaded(object sender, RoutedEventArgs e)
		{
		}

		private void ACMConflictsDlg_Closing(object sender, CancelEventArgs e)
		{
		}

		private void Ok_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			if (ACMModelConflictList != null && ACMModelConflictList.Count >= 0)
			{
				for (int i = 0; i < ACMModelConflictList.Count; i++)
				{
					if (!string.IsNullOrEmpty(sModelInstallFlags))
					{
						sModelInstallFlags += ",";
					}
					sModelInstallFlags += (ACMModelConflictList[i].Action ? "1" : "0");
				}
			}
			if (ACMModelConflictListE != null && ACMModelConflictListE.Count >= 0)
			{
				for (int j = 0; j < ACMModelConflictListE.Count; j++)
				{
					if (!string.IsNullOrEmpty(sModelInstallFlagsE))
					{
						sModelInstallFlagsE += ",";
					}
					sModelInstallFlagsE += (ACMModelConflictListE[j].Action ? "1" : "0");
				}
			}
			Close();
		}

		private void CollapsedDeployed()
		{
			DeployN.Visibility = Visibility.Collapsed;
			dgConflictList.Visibility = Visibility.Collapsed;
		}

		private void CollapsedEdited()
		{
			EditN.Visibility = Visibility.Collapsed;
			dgConflictListE.Visibility = Visibility.Collapsed;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/acmmodelconflictsdlg.xaml", UriKind.Relative);
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
				dlg = (ACMModelConflictsDlg)target;
				break;
			case 2:
				grid1 = (Grid)target;
				break;
			case 3:
				DeployN = (System.Windows.Controls.Label)target;
				break;
			case 4:
				EditN = (System.Windows.Controls.Label)target;
				break;
			case 5:
				Ok = (System.Windows.Controls.Button)target;
				Ok.Click += Ok_Click;
				break;
			case 6:
				Cancel = (System.Windows.Controls.Button)target;
				break;
			case 7:
				dgConflictList = (System.Windows.Controls.DataGrid)target;
				break;
			case 8:
				dgConflictListE = (System.Windows.Controls.DataGrid)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ApwzFormat : Window, IComponentConnector
	{
		public enum FormateType
		{
			None,
			Apwz,
			Bkp
		}

		private FormateType _formateType = FormateType.Apwz;

		private const int GWL_STYLE = -16;

		private const int WS_SYSMENU = 524288;

		internal TextBlock apwzTxtForPlus;

		internal TextBlock apwzTxtForProperty;

		internal TextBlock bkpTxtForPlus;

		internal TextBlock bkpTxtForProperty;

		internal System.Windows.Controls.Button btnOk;

		internal System.Windows.Controls.Button btnNo;

		private bool _contentLoaded;

		public bool NoMore { get; set; }

		public bool CopyDoc { get; set; }

		public ApwzFormat(FormateType formateType)
		{
			InitializeComponent();
			base.DataContext = this;
			NoMore = false;
			CopyDoc = false;
			_formateType = formateType;
			if (SystemEnvironment.IsAspenProperties)
			{
				base.Title = ApwnResources.AspenPlusProperties;
			}
			apwzTxtForPlus.Visibility = ((SystemEnvironment.IsAspenProperties || _formateType != FormateType.Apwz) ? Visibility.Collapsed : Visibility.Visible);
			apwzTxtForProperty.Visibility = ((!SystemEnvironment.IsAspenProperties || _formateType != FormateType.Apwz) ? Visibility.Collapsed : Visibility.Visible);
			bkpTxtForPlus.Visibility = ((SystemEnvironment.IsAspenProperties || _formateType != FormateType.Bkp) ? Visibility.Collapsed : Visibility.Visible);
			bkpTxtForProperty.Visibility = ((!SystemEnvironment.IsAspenProperties || _formateType != FormateType.Bkp) ? Visibility.Collapsed : Visibility.Visible);
		}

		private void btnOk_Click(object sender, RoutedEventArgs e)
		{
			CopyDoc = true;
			Close();
		}

		private void btnNo_Click(object sender, RoutedEventArgs e)
		{
			CopyDoc = false;
			Close();
		}

		[DllImport("user32.dll", SetLastError = true)]
		private static extern IntPtr GetWindowLongPtr(IntPtr hwnd, int nIndex);

		[DllImport("user32.dll")]
		private static extern IntPtr SetWindowLongPtr(IntPtr hwnd, int index, IntPtr value);

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			IntPtr handle = new WindowInteropHelper(this).Handle;
			if (handle != IntPtr.Zero)
			{
				long num = GetWindowLongPtr(handle, -16).ToInt64();
				SetWindowLongPtr(handle, -16, new IntPtr(num & -524289));
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/apwzformat.xaml", UriKind.Relative);
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
				apwzTxtForPlus = (TextBlock)target;
				break;
			case 2:
				apwzTxtForProperty = (TextBlock)target;
				break;
			case 3:
				bkpTxtForPlus = (TextBlock)target;
				break;
			case 4:
				bkpTxtForProperty = (TextBlock)target;
				break;
			case 5:
				btnOk = (System.Windows.Controls.Button)target;
				btnOk.Click += btnOk_Click;
				break;
			case 6:
				btnNo = (System.Windows.Controls.Button)target;
				btnNo.Click += btnNo_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class AssayLibrary : Window, IComponentConnector
	{
		private int m_iRbtnSeleced;

		internal System.Windows.Controls.RadioButton RbtnApal;

		internal System.Windows.Controls.RadioButton RbtnPmal;

		internal System.Windows.Controls.Button BtnOK;

		internal System.Windows.Controls.Button BtnCancel;

		private bool _contentLoaded;

		public int RbtnSeleced
		{
			get
			{
				return m_iRbtnSeleced;
			}
			set
			{
				m_iRbtnSeleced = value;
			}
		}

		public AssayLibrary()
		{
			InitializeComponent();
			RbtnApal.IsChecked = true;
		}

		protected void Rbtn_OnChecked(object sender, RoutedEventArgs args)
		{
			System.Windows.Controls.RadioButton radioButton = sender as System.Windows.Controls.RadioButton;
			if (radioButton.IsChecked == true)
			{
				if (radioButton.Name == "RbtnApal")
				{
					m_iRbtnSeleced = 0;
				}
				else
				{
					m_iRbtnSeleced = 1;
				}
			}
		}

		private void BtnOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
		}

		private void BtnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/assaylibrary.xaml", UriKind.Relative);
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
				RbtnApal = (System.Windows.Controls.RadioButton)target;
				RbtnApal.Checked += Rbtn_OnChecked;
				break;
			case 2:
				RbtnPmal = (System.Windows.Controls.RadioButton)target;
				RbtnPmal.Checked += Rbtn_OnChecked;
				break;
			case 3:
				BtnOK = (System.Windows.Controls.Button)target;
				BtnOK.Click += BtnOK_Click;
				break;
			case 4:
				BtnCancel = (System.Windows.Controls.Button)target;
				BtnCancel.Click += BtnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class AssayLibraryWait : Window, IComponentConnector
	{
		[StructLayout(LayoutKind.Sequential)]
		public class SECURITY_ATTRIBUTES
		{
			public int nLength;

			public string lpSecurityDescriptor;

			public bool bInheritHandle;
		}

		public struct STARTUPINFO
		{
			public int cb;

			public string lpReserved;

			public string lpDesktop;

			public int lpTitle;

			public int dwX;

			public int dwY;

			public int dwXSize;

			public int dwYSize;

			public int dwXCountChars;

			public int dwYCountChars;

			public int dwFillAttribute;

			public int dwFlags;

			public int dwShowWindow;

			public int cbReserved2;

			public byte lpReserved2;

			public IntPtr hStdInput;

			public IntPtr hStdOutput;

			public IntPtr hStdError;
		}

		public struct PROCESS_INFORMATION
		{
			public IntPtr hProcess;

			public IntPtr hThread;

			public int dwProcessId;

			public int dwThreadId;
		}

		private System.Windows.Forms.Timer m_tmProbe = new System.Windows.Forms.Timer();

		private const int WAIT_OBJECT_0 = 0;

		private const long WAIT_TIMEOUT = 258L;

		private bool m_bProcessExit;

		private PROCESS_INFORMATION m_structPI;

		private const int GWL_STYLE = -16;

		private const int WS_SYSMENU = 524288;

		private uint m_iStatus;

		private bool _contentLoaded;

		public bool ProcessExit
		{
			get
			{
				return m_bProcessExit;
			}
			private set
			{
				m_bProcessExit = value;
			}
		}

		public uint StatusProcess
		{
			get
			{
				return m_iStatus;
			}
			private set
			{
				m_iStatus = value;
			}
		}

		[DllImport("user32.dll")]
		private static extern IntPtr GetWindowLongPtr(IntPtr hwnd, int nIndex);

		[DllImport("user32.dll")]
		private static extern IntPtr SetWindowLongPtr(IntPtr hwnd, int index, IntPtr value);

		[DllImport("Kernel32.dll", CharSet = CharSet.Unicode)]
		public static extern bool CreateProcess(StringBuilder lpApplicationName, StringBuilder lpCommandLine, SECURITY_ATTRIBUTES lpProcessAttributes, SECURITY_ATTRIBUTES lpThreadAttributes, bool bInheritHandles, int dwCreationFlags, StringBuilder lpEnvironment, StringBuilder lpCurrentDirectory, ref STARTUPINFO lpStartupInfo, ref PROCESS_INFORMATION lpProcessInformation);

		[DllImport("Kernel32.dll")]
		public static extern uint WaitForSingleObject(IntPtr hHandle, uint dwMilliseconds);

		[DllImport("Kernel32.dll")]
		public static extern bool CloseHandle(IntPtr hObject);

		public AssayLibraryWait()
		{
			InitializeComponent();
			m_tmProbe.Interval = 3000;
			m_tmProbe.Tick += Timer_OnTick;
			base.Loaded += AssayLibraryWait_Loaded;
		}

		private void AssayLibraryWait_Loaded(object sender, RoutedEventArgs e)
		{
			IntPtr handle = new WindowInteropHelper(this).Handle;
			if (handle != IntPtr.Zero)
			{
				long num = GetWindowLongPtr(handle, -16).ToInt64();
				SetWindowLongPtr(handle, -16, new IntPtr(num & -524289));
			}
			base.Cursor = System.Windows.Input.Cursors.Wait;
			CaptureMouse();
		}

		public void CreateTargetProcess(string strExecute)
		{
			m_structPI = default(PROCESS_INFORMATION);
			STARTUPINFO lpStartupInfo = default(STARTUPINFO);
			if (CreateProcess(null, new StringBuilder(strExecute), null, null, bInheritHandles: false, 0, null, null, ref lpStartupInfo, ref m_structPI))
			{
				m_tmProbe.Start();
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			base.OnClosing(e);
		}

		protected void Timer_OnTick(object sender, EventArgs e)
		{
			uint num = 0u;
			if ((ulong)(m_iStatus = WaitForSingleObject(m_structPI.hProcess, 0u)) != 258)
			{
				m_tmProbe.Stop();
				m_tmProbe.Dispose();
				CloseHandle(m_structPI.hThread);
				CloseHandle(m_structPI.hProcess);
				m_bProcessExit = true;
				ReleaseMouseCapture();
				Close();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/assaylibrarywait.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	internal class ColumnHXIntegrationDlgViewModel : INotifyPropertyChanged
	{
		private bool initialized = true;

		private MMDialog m_parent;

		public bool m_bReOpen;

		public IntPtr m_pNode;

		private string m_hxColdStreamOut = "";

		private string m_hierName;

		private bool m_bDelete;

		private bool m_bFlow;

		private bool m_bTemp;

		private bool m_bDelt;

		private bool m_bVfrac;

		private bool m_bQn;

		private int m_nstage;

		private string m_columnid = string.Empty;

		private string m_strRebUtil = string.Empty;

		private string m_strRebOption = string.Empty;

		private string _reboilerType = string.Empty;

		private string _reboilerID = string.Empty;

		private string _blockID;

		private string _selectedBlockID;

		private string _blockType;

		private string _selectedBlockType;

		private string _blockMode;

		private string _circulationType;

		private List<string> _blockComboListID;

		private List<string> _blockComboListType;

		private List<string> _blockComboListMode;

		private List<string> _circulationComboListType;

		private string _flashBlockID;

		private string _selectedFlashBlockID;

		private List<string> _flashBlockComboListID;

		private string _1stblockID;

		private string _2ndblockID;

		private string _dampingfactor = Convert.ToString(0.5.ToString(CultureInfo.CurrentCulture.NumberFormat));

		private bool _isMoveToChecked;

		private string _moveToBlock;

		private string _selectedMoveToBlock;

		private List<string> _moveToComboListBlock;

		private bool _isLinkToChecked = true;

		private string _hxInputFile = string.Empty;

		private bool _isEableInputFile;

		private bool[] _bEable = new bool[14];

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnBrowse;

		private DelegateCommand<object> _commandOnCancel;

		public bool Initialized
		{
			get
			{
				return initialized;
			}
			protected set
			{
				initialized = value;
			}
		}

		public bool IsEableSTREAMID
		{
			get
			{
				return _bEable[1];
			}
			set
			{
				if (_bEable[1] != value)
				{
					_bEable[1] = value;
					OnPropertyChanged("IsEableSTREAMID");
				}
			}
		}

		public bool IsEableHEATXID
		{
			get
			{
				return _bEable[2];
			}
			set
			{
				if (_bEable[2] != value)
				{
					_bEable[2] = value;
					OnPropertyChanged("IsEableHEATXID");
				}
			}
		}

		public bool IsEableHXFLOWTYPE
		{
			get
			{
				return _bEable[5];
			}
			set
			{
				if (_bEable[5] != value)
				{
					_bEable[5] = value;
					OnPropertyChanged("IsEableHXFLOWTYPE");
				}
			}
		}

		public bool IsEableFLASHID
		{
			get
			{
				return _bEable[8];
			}
			set
			{
				if (_bEable[8] != value)
				{
					_bEable[8] = value;
					OnPropertyChanged("IsEableFLASHID");
				}
			}
		}

		public bool IsEableCALCULATOR1ID
		{
			get
			{
				return _bEable[9];
			}
			set
			{
				if (_bEable[9] != value)
				{
					_bEable[9] = value;
					OnPropertyChanged("IsEableCALCULATOR1ID");
				}
			}
		}

		public bool IsEableCALCULATOR2ID
		{
			get
			{
				return _bEable[10];
			}
			set
			{
				if (_bEable[10] != value)
				{
					_bEable[10] = value;
					OnPropertyChanged("IsEableCALCULATOR2ID");
				}
			}
		}

		public bool IsEableDAMPINGFACTOR
		{
			get
			{
				return _bEable[11];
			}
			set
			{
				if (_bEable[11] != value)
				{
					_bEable[11] = value;
					OnPropertyChanged("IsEableDAMPINGFACTOR");
				}
			}
		}

		public bool IsEableMoveTo
		{
			get
			{
				return _bEable[12];
			}
			set
			{
				if (_bEable[12] != value)
				{
					_bEable[12] = value;
					OnPropertyChanged("IsEableMoveTo");
				}
			}
		}

		public bool IsEableHIERID
		{
			get
			{
				return _bEable[13];
			}
			set
			{
				if (_bEable[13] != value)
				{
					_bEable[13] = value;
					OnPropertyChanged("IsEableHIERID");
				}
			}
		}

		public string HelpFile => "radfrac.chm";

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public ICommand CommandOnBrowse
		{
			get
			{
				if (_commandOnBrowse == null)
				{
					_commandOnBrowse = new DelegateCommand<object>(ExecuteCommandOnBrowse);
				}
				return _commandOnBrowse;
			}
		}

		public ICommand CommandOnCancel
		{
			get
			{
				if (_commandOnCancel == null)
				{
					_commandOnCancel = new DelegateCommand<object>(ExecuteCommandOnCancel);
				}
				return _commandOnCancel;
			}
		}

		public string ReboilerType
		{
			get
			{
				return _reboilerType;
			}
			set
			{
				if (_reboilerType != value)
				{
					_reboilerType = value;
					OnPropertyChanged("ReboilerType");
				}
			}
		}

		public string ReboilerID
		{
			get
			{
				return _reboilerID;
			}
			set
			{
				if (_reboilerID != value)
				{
					_reboilerID = value;
					OnPropertyChanged("ReboilerID");
				}
			}
		}

		public string BlockID
		{
			get
			{
				return _blockID;
			}
			set
			{
				if (_blockID != value)
				{
					_blockID = value;
					OnPropertyChanged("BlockID");
				}
			}
		}

		public string SelectedBlockID
		{
			get
			{
				return _selectedBlockID;
			}
			set
			{
				if (_selectedBlockID != value)
				{
					_selectedBlockID = value;
					OnPropertyChanged("SelectedBlockID");
					BlockID = value;
					InitHeatx();
					InitDialogDisplay();
				}
			}
		}

		public string BlockType
		{
			get
			{
				return _blockType;
			}
			set
			{
				if (_blockType != value)
				{
					_blockType = value;
					OnPropertyChanged("BlockType");
				}
			}
		}

		public string SelectedBlockType
		{
			get
			{
				return _selectedBlockType;
			}
			set
			{
				if (_selectedBlockType != value)
				{
					_selectedBlockType = value;
					OnPropertyChanged("SelectedBlockType");
					BlockType = value;
					InitDialogDisplay();
				}
			}
		}

		public string BlockMode
		{
			get
			{
				return _blockMode;
			}
			set
			{
				if (_blockMode != value)
				{
					_blockMode = value;
					OnPropertyChanged("BlockMode");
					InitDialogDisplay();
				}
			}
		}

		public string CirculationType
		{
			get
			{
				return _circulationType;
			}
			set
			{
				if (_circulationType != value)
				{
					_circulationType = value;
					OnPropertyChanged("CirculationType");
				}
			}
		}

		public List<string> BlockComboListID
		{
			get
			{
				return _blockComboListID;
			}
			set
			{
				if (_blockComboListID != value)
				{
					_blockComboListID = value;
					OnPropertyChanged("BlockComboListID");
				}
			}
		}

		public List<string> BlockComboListType
		{
			get
			{
				return _blockComboListType;
			}
			set
			{
				if (_blockComboListType != value)
				{
					_blockComboListType = value;
					OnPropertyChanged("BlockComboListType");
				}
			}
		}

		public List<string> BlockComboListMode
		{
			get
			{
				return _blockComboListMode;
			}
			set
			{
				if (_blockComboListMode != value)
				{
					_blockComboListMode = value;
					OnPropertyChanged("BlockComboListMode");
				}
			}
		}

		public List<string> CirculationComboListType
		{
			get
			{
				return _circulationComboListType;
			}
			set
			{
				if (_circulationComboListType != value)
				{
					_circulationComboListType = value;
					OnPropertyChanged("CirculationComboListType");
				}
			}
		}

		public string FlashBlockID
		{
			get
			{
				return _flashBlockID;
			}
			set
			{
				if (_flashBlockID != value)
				{
					_flashBlockID = value;
					OnPropertyChanged("FlashBlockID");
				}
			}
		}

		public string SelectedFlashBlockID
		{
			get
			{
				return _selectedFlashBlockID;
			}
			set
			{
				if (_selectedFlashBlockID != value)
				{
					_selectedFlashBlockID = value;
					OnPropertyChanged("SelectedFlashBlockID");
					FlashBlockID = value;
				}
			}
		}

		public List<string> FlashBlockComboListID
		{
			get
			{
				return _flashBlockComboListID;
			}
			set
			{
				if (_flashBlockComboListID != value)
				{
					_flashBlockComboListID = value;
					OnPropertyChanged("FlashBlockComboListID");
				}
			}
		}

		public string FirstblockID
		{
			get
			{
				return _1stblockID;
			}
			set
			{
				if (_1stblockID != value)
				{
					_1stblockID = value;
					OnPropertyChanged("FirstblockID");
				}
			}
		}

		public string SecondblockID
		{
			get
			{
				return _2ndblockID;
			}
			set
			{
				if (value == "0")
				{
					value = string.Empty;
				}
				if (_2ndblockID != value)
				{
					_2ndblockID = value;
					OnPropertyChanged("SecondblockID");
				}
			}
		}

		public string Dampingfactor
		{
			get
			{
				return _dampingfactor;
			}
			set
			{
				if (_dampingfactor != value)
				{
					_dampingfactor = value;
					OnPropertyChanged("Dampingfactor");
				}
			}
		}

		public bool IsMoveToChecked
		{
			get
			{
				return _isMoveToChecked;
			}
			set
			{
				if (_isMoveToChecked != value)
				{
					_isMoveToChecked = value;
					OnPropertyChanged("IsMoveToChecked");
					IsEableHIERID = value;
				}
			}
		}

		public string MoveToBlock
		{
			get
			{
				return _moveToBlock;
			}
			set
			{
				if (_moveToBlock != value)
				{
					_moveToBlock = value;
					OnPropertyChanged("MoveToBlock");
				}
			}
		}

		public string SelectedMoveToBlock
		{
			get
			{
				return _selectedMoveToBlock;
			}
			set
			{
				if (_selectedMoveToBlock != value)
				{
					_selectedMoveToBlock = value;
					OnPropertyChanged("SelectedMoveToBlock");
					MoveToBlock = value;
				}
			}
		}

		public List<string> MoveToComboListBlock
		{
			get
			{
				return _moveToComboListBlock;
			}
			set
			{
				if (_moveToComboListBlock != value)
				{
					_moveToComboListBlock = value;
					OnPropertyChanged("MoveToComboListBlock");
				}
			}
		}

		public bool IsLinkToChecked
		{
			get
			{
				return _isLinkToChecked;
			}
			set
			{
				if (_isLinkToChecked != value)
				{
					_isLinkToChecked = value;
					OnPropertyChanged("IsLinkToChecked");
				}
			}
		}

		public string HxInputFile
		{
			get
			{
				return _hxInputFile;
			}
			set
			{
				if (value == "0")
				{
					value = string.Empty;
				}
				if (_hxInputFile != value)
				{
					_hxInputFile = value;
					OnPropertyChanged("HxInputFile");
				}
			}
		}

		public bool IsEableInputFile
		{
			get
			{
				return _isEableInputFile;
			}
			set
			{
				if (_isEableInputFile != value)
				{
					_isEableInputFile = value;
					OnPropertyChanged("IsEableInputFile");
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ColumnHXIntegrationDlgViewModel()
		{
		}

		public ColumnHXIntegrationDlgViewModel(MMDialog Owner, IntPtr pNode, string szModelName, string szBlockName)
		{
			m_pNode = pNode;
			m_columnid = szBlockName;
			m_parent = Owner;
			Initialize();
		}

		private void CheckDistillationSpecs()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add(m_columnid + "\\Input");
			list.Add("NSTAGE");
			if (ColumnHXHelper.GetVarValue(m_pNode, list, out var objRet))
			{
				m_nstage = Convert.ToInt32(objRet);
			}
			list.RemoveAt(list.Count - 1);
			list.Add("REBOILER");
			if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
			{
				ReboilerType = Convert.ToString(objRet);
			}
			if (ReboilerType != "NONE")
			{
				list.RemoveAt(list.Count - 1);
				list.Add("REB_UTIL");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					m_strRebUtil = Convert.ToString(objRet);
				}
			}
			if (ReboilerType == "KETTLE")
			{
				ReboilerType = AspenTech.AspenPlus.Localization.Properties.Resources.MMRadfrac_Setup_Config_ViewModel__CxvMultiMapOption_Display_Kettle;
			}
			else if (ReboilerType == "THERMOSYPHON" || ReboilerType == "THERMOSIPHON")
			{
				ReboilerType = AspenTech.AspenPlus.Localization.Properties.Resources.MMRadfrac_Setup_Config_ViewModel__CxvMultiMapOption_Display_Thermosiphon;
			}
			else
			{
				ReboilerType = AspenTech.AspenPlus.Localization.Properties.Resources.MMRadfrac_Setup_Config_ViewModel__CxvMultiMapOption_Display_None_1;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("OPT_TH_REB");
			if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
			{
				m_strRebOption = Convert.ToString(objRet);
			}
			if (ReboilerType == WpfMMDialogResources.ColumnHXComStr1 || ReboilerType == WpfMMDialogResources.ColumnHXComStr3)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("TH_FLOW");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet) && m_strRebOption.Contains("FLOW"))
				{
					list.RemoveAt(list.Count - 1);
					list.Add("VARTYPE");
					if (!ColumnHXHelper.GetVaryType(m_pNode, list, "RFLOW") && BlockType == WpfMMDialogResources.ColumnHeatxType1 && CirculationType == WpfMMDialogResources.ColumnHeatxCir1)
					{
						m_bFlow = true;
					}
				}
				if (m_strRebOption.Contains("OUTLET"))
				{
					list.RemoveAt(list.Count - 1);
					list.Add("TH_TEMP");
					if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
					{
						list.RemoveAt(list.Count - 1);
						list.Add("VARTYPE");
						if (!ColumnHXHelper.GetVaryType(m_pNode, list, "TREB"))
						{
							m_bTemp = true;
						}
					}
					list.RemoveAt(list.Count - 1);
					list.Add("TH_DELT");
					if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
					{
						list.RemoveAt(list.Count - 1);
						list.Add("VARTYPE");
						if (!ColumnHXHelper.GetVaryType(m_pNode, list, "DTREB"))
						{
							m_bDelt = true;
						}
					}
					list.RemoveAt(list.Count - 1);
					list.Add("TH_VFRAC");
					if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
					{
						list.RemoveAt(list.Count - 1);
						list.Add("VARTYPE");
						if (!ColumnHXHelper.GetVaryType(m_pNode, list, "VREB"))
						{
							m_bVfrac = true;
						}
					}
				}
			}
			list.RemoveAt(list.Count - 1);
			list.Add("QN");
			if (!ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
			{
				return;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("VARTYPE");
			if (!ColumnHXHelper.GetVaryType(m_pNode, list, "QN"))
			{
				if (ReboilerType.ToUpper() != WpfMMDialogResources.ColumnHXComStr3.ToUpper())
				{
					m_bQn = true;
				}
				else if (m_strRebOption != "FLOW+OUTLET")
				{
					m_bQn = true;
				}
			}
		}

		private void Initialize()
		{
			if (!ColumnHXHelper.IsBlockExist(m_pNode, "Input"))
			{
				return;
			}
			List<string> list = new List<string>();
			list.Add("Input");
			list.Add("REBWIZ");
			ColumnHXHelper.GetVarValue(m_pNode, list, out var objRet);
			if (Convert.ToString(objRet) == "YES")
			{
				m_bReOpen = true;
			}
			if (m_bReOpen)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("PSTRID");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					ReboilerID = Convert.ToString(objRet);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("HXID");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					BlockID = Convert.ToString(objRet);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("FLASHID");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					FlashBlockID = Convert.ToString(objRet);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("CALC1ID");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					FirstblockID = Convert.ToString(objRet);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("CALC2ID");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					SecondblockID = Convert.ToString(objRet);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("DAMPF");
				if (ColumnHXHelper.GetVarValue(m_pNode, list, out objRet))
				{
					Dampingfactor = Convert.ToString(objRet);
				}
				if (string.IsNullOrEmpty(ReboilerID) && string.IsNullOrEmpty(BlockID) && string.IsNullOrEmpty(FlashBlockID) && string.IsNullOrEmpty(FirstblockID) && string.IsNullOrEmpty(SecondblockID))
				{
					List<string> list2 = new List<string>();
					list2.Add("Input");
					list2.Add("REBWIZ");
					ColumnHXHelper.SetBlockVariable(m_pNode, list2, "NO", 0);
					m_bReOpen = false;
				}
				else if (string.IsNullOrEmpty(ReboilerID) || string.IsNullOrEmpty(BlockID) || string.IsNullOrEmpty(FlashBlockID) || string.IsNullOrEmpty(FirstblockID))
				{
					m_bDelete = true;
					string text = WpfMMDialogResources.ColumnHXTipErrMsgBase + "\n";
					if (!string.IsNullOrEmpty(ReboilerID))
					{
						text = text + "\n" + WpfMMDialogResources.ColumnHXTipErrMsgReboilerStream.PadRight(24) + ReboilerID;
					}
					if (!string.IsNullOrEmpty(BlockID))
					{
						text = text + "\n" + WpfMMDialogResources.ColumnHXTipErrMsgHeatX.PadRight(30) + BlockID;
					}
					if (!string.IsNullOrEmpty(FlashBlockID))
					{
						text = text + "\n" + WpfMMDialogResources.ColumnHXTipErrMsgFlashBlock.PadRight(30) + FlashBlockID;
					}
					if (!string.IsNullOrEmpty(FirstblockID))
					{
						text = text + "\n" + WpfMMDialogResources.ColumnHXTipErrMsgCalculator.PadRight(29) + FirstblockID;
					}
					MMMessageBox.Show(text, MMVersionHelper.MVGetI18nProductNameM());
					initialized = false;
					return;
				}
			}
			else
			{
				List<string> list3 = new List<string>();
				list3.Add("..\\..\\");
				list3.Add("Streams");
				ColumnHXHelper.GetDefaultName(m_pNode, list3, out var objRet2);
				ReboilerID = objRet2;
				list3.RemoveAt(list.Count - 1);
				list3.Add("Flowsheeting Options\\Calculator");
				ColumnHXHelper.GetDefaultName(m_pNode, list3, out objRet2);
				FirstblockID = objRet2;
				int num = _1stblockID.LastIndexOf('-');
				string text2 = _1stblockID.Substring(0, num + 1);
				string value = _1stblockID.Substring(num + 1, _1stblockID.Length - num - 1);
				SecondblockID = text2 + (Convert.ToDouble(value) + 1.0);
			}
			if (!m_bDelete)
			{
				if (BlockComboListType == null)
				{
					BlockComboListType = new List<string>();
					BlockComboListType.Add(WpfMMDialogResources.ColumnHeatxType1);
					BlockComboListType.Add(WpfMMDialogResources.ColumnHeatxType2);
					BlockType = WpfMMDialogResources.ColumnHeatxType1;
				}
				if (BlockComboListMode == null)
				{
					BlockComboListMode = new List<string>();
					BlockComboListMode.Add(WpfMMDialogResources.ColumnHeatxMode1);
					BlockComboListMode.Add(WpfMMDialogResources.ColumnHeatxMode2);
					BlockComboListMode.Add(WpfMMDialogResources.ColumnHeatxMode3);
					BlockMode = WpfMMDialogResources.ColumnHeatxMode1;
				}
				if (CirculationComboListType == null)
				{
					CirculationComboListType = new List<string>();
					CirculationComboListType.Add(WpfMMDialogResources.ColumnHeatxCir1);
					CirculationComboListType.Add(WpfMMDialogResources.ColumnHeatxCir2);
					CirculationType = WpfMMDialogResources.ColumnHeatxCir2;
				}
				if (_blockComboListID == null)
				{
					_blockComboListID = new List<string>();
				}
				if (_flashBlockComboListID == null)
				{
					_flashBlockComboListID = new List<string>();
				}
				if (_moveToComboListBlock == null)
				{
					_moveToComboListBlock = new List<string>();
				}
				m_hierName = ColumnHXHelper.GetHierName(m_pNode);
				ColumnHXHelper.FindeComboxItems(m_pNode, "..\\..\\", "\\Blocks", m_hierName, out _blockComboListID, out _flashBlockComboListID, out _moveToComboListBlock);
				if (m_bReOpen)
				{
					InitHeatx();
				}
				CheckDistillationSpecs();
				InitDialogDisplay();
			}
		}

		private void InitDialogDisplay()
		{
			IsEableSTREAMID = !m_bReOpen || string.IsNullOrEmpty(ReboilerID);
			IsEableHEATXID = !m_bReOpen || string.IsNullOrEmpty(BlockID);
			IsEableHXFLOWTYPE = BlockMode == WpfMMDialogResources.ColumnHeatxMode3 && BlockType == WpfMMDialogResources.ColumnHeatxType1 && (ReboilerType == WpfMMDialogResources.ColumnHXComStr1 || ReboilerType == WpfMMDialogResources.ColumnHXComStr3);
			IsEableInputFile = BlockType == WpfMMDialogResources.ColumnHeatxType1;
			IsEableFLASHID = !m_bReOpen || string.IsNullOrEmpty(FlashBlockID);
			IsEableCALCULATOR1ID = !m_bReOpen || string.IsNullOrEmpty(FirstblockID);
			IsEableCALCULATOR2ID = BlockMode == WpfMMDialogResources.ColumnHeatxMode3 && (!m_bReOpen || string.IsNullOrEmpty(SecondblockID));
			IsEableDAMPINGFACTOR = BlockMode == WpfMMDialogResources.ColumnHeatxMode3;
			IsEableMoveTo = !m_bReOpen;
			IsEableHIERID = !m_bReOpen && IsMoveToChecked;
		}

		private void InitHeatx()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add(BlockID);
			list.Add("Input\\EXCH_TYPE");
			ColumnHXHelper.GetVarValue(m_pNode, list, out var objRet);
			string text = Convert.ToString(objRet);
			string text2 = ((!(text != ReboilerType) && !(text != WpfMMDialogResources.ColumnHXComStr3.ToUpper())) ? WpfMMDialogResources.ColumnHXTipErrMsg0 : "");
			list.RemoveAt(list.Count - 1);
			list.Add("Input\\MODE");
			ColumnHXHelper.GetVarValue(m_pNode, list, out objRet);
			text = Convert.ToString(objRet);
			if (text.ToUpper() == WpfMMDialogResources.ColumnHeatxType2.ToUpper())
			{
				BlockType = WpfMMDialogResources.ColumnHeatxType2;
			}
			else if (text.ToUpper() == "TASCPLUS-RIG")
			{
				BlockType = WpfMMDialogResources.ColumnHeatxType1;
			}
			else
			{
				text2 += WpfMMDialogResources.ColumnHXTipErrMsg1;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("Input\\PROGRAM_MODE");
			ColumnHXHelper.GetVarValue(m_pNode, list, out objRet);
			text = Convert.ToString(objRet);
			if (text.ToUpper() == WpfMMDialogResources.ColumnHeatxMode1.ToUpper())
			{
				BlockMode = WpfMMDialogResources.ColumnHeatxMode1;
			}
			else if (text.ToUpper() == WpfMMDialogResources.ColumnHeatxMode2.ToUpper())
			{
				BlockMode = WpfMMDialogResources.ColumnHeatxMode2;
			}
			else if (text.ToUpper() == WpfMMDialogResources.ColumnHeatxMode3.ToUpper())
			{
				BlockMode = WpfMMDialogResources.ColumnHeatxMode3;
			}
			else
			{
				text2 += WpfMMDialogResources.ColumnHXTipErrMsg2;
			}
			if (!string.IsNullOrEmpty(text2))
			{
				text2 += WpfMMDialogResources.ColumnHXTipErrMsg3;
				MMMessageBox.Show(text2, MMVersionHelper.MVGetI18nProductNameM());
				BlockID = null;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("Input\\INPUT_FILE");
			ColumnHXHelper.GetVarValue(m_pNode, list, out objRet);
			HxInputFile = Convert.ToString(objRet);
			if (ReboilerType == WpfMMDialogResources.ColumnHXComStr3 && m_strRebOption.Contains("FLOW"))
			{
				list.RemoveAt(list.Count - 1);
				list.Add("Input\\CIRC_TYPE");
				ColumnHXHelper.GetVarValue(m_pNode, list, out objRet);
				text = Convert.ToString(objRet);
				if (text == "FIND-FLOW")
				{
					CirculationType = WpfMMDialogResources.ColumnHeatxCir1;
				}
				else
				{
					CirculationType = WpfMMDialogResources.ColumnHeatxCir2;
				}
			}
		}

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		private void ExecuteCommandOnOK(object arg)
		{
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (!m_bReOpen)
			{
				if (string.IsNullOrEmpty(ReboilerID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg13, caption);
					return;
				}
				if (!CheckUniqueStreamName())
				{
					return;
				}
				if (string.IsNullOrEmpty(FirstblockID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg14, caption);
					return;
				}
				if (!CheckUniqueClaculatorName(FirstblockID))
				{
					return;
				}
				if (string.IsNullOrEmpty(BlockID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg15, caption);
					return;
				}
				if (!string.IsNullOrEmpty(MoveToBlock) && string.Compare(BlockID, MoveToBlock, ignoreCase: true) == 0)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg10, caption);
					return;
				}
				BlockID = BlockID.ToUpper();
				if (!CheckUniqueBlockName(BlockID))
				{
					return;
				}
				if (string.IsNullOrEmpty(FlashBlockID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg16, caption);
					return;
				}
				if (!string.IsNullOrEmpty(MoveToBlock) && string.Compare(FlashBlockID, MoveToBlock) == 0)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg12, caption);
					return;
				}
				FlashBlockID = FlashBlockID.ToUpper();
				if (string.Compare(BlockID, FlashBlockID) == 0)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg9, caption);
					return;
				}
				if (!CheckUniqueBlockName(FlashBlockID))
				{
					return;
				}
				if (IsMoveToChecked)
				{
					if (string.IsNullOrEmpty(MoveToBlock))
					{
						MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg17, caption);
						return;
					}
					MoveToBlock = MoveToBlock.ToUpper();
					if (!CheckUniqueBlockName(MoveToBlock))
					{
						return;
					}
					IntPtr intPtr = ColumnHXHelper.MoveColumnToHier(m_pNode, m_columnid, BlockID, FlashBlockID, out _moveToBlock, m_hierName);
					if (intPtr == IntPtr.Zero || !ColumnHXHelper.IsBlockExist(intPtr, "..\\..\\"))
					{
						return;
					}
					m_pNode = intPtr;
					m_hierName = MoveToBlock + ".";
				}
			}
			if (!string.IsNullOrEmpty(HxInputFile) && (HxInputFile.IndexOfAny(Path.GetInvalidPathChars()) > -1 || HxInputFile.IndexOf("\\") == 0 || (HxInputFile.LastIndexOf("\\") > 0 && HxInputFile.Substring(HxInputFile.LastIndexOf("\\") + 1).IndexOfAny(Path.GetInvalidFileNameChars()) > -1) || (HxInputFile.LastIndexOf("\\") < 0 && HxInputFile.IndexOfAny(Path.GetInvalidFileNameChars()) > -1)))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg25, caption);
				return;
			}
			if (BlockMode == WpfMMDialogResources.ColumnHeatxMode3)
			{
				if (string.IsNullOrEmpty(SecondblockID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg14, caption);
					return;
				}
				SecondblockID = SecondblockID.ToUpper();
				if (!CheckUniqueClaculatorName(SecondblockID))
				{
					return;
				}
				CheckDistillationSpecs();
				if (!m_bQn && !m_bFlow && !m_bTemp && !m_bDelt && !m_bVfrac)
				{
					if (ReboilerType == WpfMMDialogResources.ColumnHXComStr2)
					{
						MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg18, caption);
					}
					else
					{
						MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg19, caption);
					}
					return;
				}
			}
			if (SetDistillationColumn())
			{
				int settingValue = ColumnHXHelper.GetSettingValue();
				ColumnHXHelper.SetSettingValue(1);
				if (!SetHeatxBlock())
				{
					ColumnHXHelper.SetSettingValue(settingValue);
					return;
				}
				if (!SetFlashBlock())
				{
					ColumnHXHelper.SetSettingValue(settingValue);
					return;
				}
				if (!SetPushCalculatorBlock())
				{
					ColumnHXHelper.SetSettingValue(settingValue);
					return;
				}
				SetPullCalculatorBlock();
				SetWizardInfo();
				ColumnHXHelper.SetSettingValue(settingValue);
				m_parent.DialogResult = true;
			}
		}

		private void SetWizardInfo()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks\\" + m_columnid + "\\Input");
			list.Add("REB_TH_OPT");
			ColumnHXHelper.SetBlockVariable(m_pNode, list, m_strRebOption, 0);
			if (IsLinkToChecked)
			{
				if (!m_bReOpen)
				{
					list.RemoveAt(list.Count - 1);
					list.Add("REBWIZ");
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("PSTRID");
					ColumnHXHelper.SetBlockVariable(m_pNode, list, ReboilerID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("HXID");
					ColumnHXHelper.SetBlockVariable(m_pNode, list, BlockID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FLASHID");
					ColumnHXHelper.SetBlockVariable(m_pNode, list, FlashBlockID, 0);
				}
				list.RemoveAt(list.Count - 1);
				list.Add("CALC1ID");
				ColumnHXHelper.SetBlockVariable(m_pNode, list, FirstblockID, 0);
				list.RemoveAt(list.Count - 1);
				list.Add("CALC2ID");
				ColumnHXHelper.SetBlockVariable(m_pNode, list, SecondblockID, 0);
				list.RemoveAt(list.Count - 1);
				list.Add("DAMPF");
				ColumnHXHelper.SetBlockVariable(m_pNode, list, Dampingfactor, 0);
			}
			else
			{
				list.RemoveAt(list.Count - 1);
				list.Add("REBWIZ");
				ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0);
			}
			if (m_bReOpen)
			{
				list.Clear();
				list.Add("..\\..\\");
				list.Add("\\Blocks\\" + m_columnid + "\\CC Nodes");
				string[] array = new string[6] { "REBWIZARD1", "REBWIZARD2", "REBWIZARD3", "REBWIZARD4", "REBWIZARD5", "REBWIZARD6" };
				foreach (string text in array)
				{
					list.Add("\\" + text);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, 1, 1);
				}
			}
		}

		private void SetPullCalculatorBlock()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Flowsheeting Options\\Calculator");
			if (m_bReOpen)
			{
				ColumnHXHelper.DeleteBlock(m_pNode, list, SecondblockID);
			}
			if (BlockMode != WpfMMDialogResources.ColumnHeatxMode3)
			{
				return;
			}
			ColumnHXHelper.CreateCalculatorBlock(m_pNode, SecondblockID);
			list.Add(SecondblockID + "\\Input");
			list.Add("REBWIZ");
			ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0);
			int num = 0;
			int num2 = 0;
			while (m_bQn || m_bTemp || m_bDelt || m_bVfrac || (m_bFlow && string.IsNullOrEmpty(CirculationType) && string.IsNullOrEmpty(BlockType)))
			{
				string text = "";
				string text2 = "";
				if (m_bQn || ReboilerType == WpfMMDialogResources.ColumnHXComStr2)
				{
					text = "DUTY";
					text2 = "QCALC";
				}
				else if (m_bTemp)
				{
					text = "TEMP";
					text2 = "TCALC";
				}
				else if (m_bDelt)
				{
					text = "DTEMP";
					text2 = "DTCALC";
				}
				else if (m_bVfrac)
				{
					text = "VFRAC";
					text2 = "VCALC";
				}
				else if (m_bFlow)
				{
					text = "FLOW";
					text2 = "FCALC";
				}
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARIABLE");
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text, num, bInsert: true);
				num++;
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text2, num, bInsert: true);
				num++;
				list.RemoveAt(list.Count - 1);
				list.Add("WRITE_VAR");
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text, num2, bInsert: false);
				list.RemoveAt(list.Count - 1);
				list.Add("SCALE");
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text, num2, bInsert: true);
				list.RemoveAt(list.Count - 1);
				list.Add("READ_VAR");
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text2, num2, bInsert: false);
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARTYPE\\" + text);
				ColumnHXHelper.SetBlockVariable(m_pNode, list, "BLOCK-VAR", 0);
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARTYPE\\" + text2);
				ColumnHXHelper.SetBlockVariable(m_pNode, list, "BLOCK-VAR", 0);
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_BLOCK\\" + text);
				ColumnHXHelper.SetBlockVariable(m_pNode, list, m_columnid, 0);
				string text3 = "";
				if (m_bQn || ReboilerType == WpfMMDialogResources.ColumnHXComStr2)
				{
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "QN", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_BLOCK\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, BlockID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "QCALC", 0);
					m_bQn = false;
				}
				else if (m_bTemp)
				{
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-TEMP", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_BLOCK\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, FlashBlockID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TCALC", 0);
					m_bTemp = false;
				}
				else if (m_bDelt)
				{
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-DELT", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_BLOCK\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, FlashBlockID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TCALC", 0);
					text3 = "STEMP";
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE");
					ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text3, num, bInsert: true);
					num++;
					list.RemoveAt(list.Count - 1);
					list.Add("READ_VAR");
					ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text3, num2 + 1, bInsert: false);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARTYPE\\" + text3);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "STREAM-VAR", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_STREAM\\" + text3);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, ReboilerID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text3);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TEMP", 0);
					m_bDelt = false;
				}
				else if (m_bVfrac)
				{
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-VFRAC", 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_BLOCK\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, FlashBlockID, 0);
					list.RemoveAt(list.Count - 1);
					list.Add("FVN_VARIABLE\\" + text2);
					ColumnHXHelper.SetBlockVariable(m_pNode, list, "VCALC", 0);
					m_bVfrac = false;
				}
				else if (m_bFlow)
				{
					list.Clear();
					list.Add("..\\..\\");
					list.Add("Blocks\\" + m_columnid + "\\Input");
					list.Add("TH_BASIS");
					ColumnHXHelper.GetVarValue(m_pNode, list, out var objRet);
					string text4 = Convert.ToString(objRet);
					list.Clear();
					list.Add("..\\..\\");
					list.Add("\\Flowsheeting Options\\Calculator");
					list.Add(SecondblockID + "\\Input");
					if (!string.IsNullOrEmpty(text4))
					{
						list.Add("FVN_VARTYPE\\" + text2);
						ColumnHXHelper.SetBlockVariable(m_pNode, list, BlockID, 0);
						if (text4.ToUpper() == "MASS")
						{
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-MASS-FLOW", 0);
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text2);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "CSMFCALC", 0);
						}
						if (text4.ToUpper() == "MOLE")
						{
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-MOLE-FLOW", 0);
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text2);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "CSMOLFCALC", 0);
						}
						if (text4.ToUpper() == "STDVOL")
						{
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-VOL-FLOW", 0);
							list.RemoveAt(list.Count - 1);
							list.Add("FVN_VARIABLE\\" + text2);
							ColumnHXHelper.SetBlockVariable(m_pNode, list, "CSVOLFCALC", 0);
						}
					}
					m_bFlow = false;
				}
				string strVar;
				if (num2 == 0)
				{
					strVar = "F      REAL*8 Dampf";
					list.RemoveAt(list.Count - 1);
					list.Add("FORTRAN_DEC");
					ColumnHXHelper.InsertAndSetVariable(m_pNode, list, strVar, num2, bInsert: false);
					string text5 = ColumnHXHelper.DoublewithSignToString(Convert.ToDouble(Dampingfactor), 2);
					strVar = "F      Dampf = " + text5;
					list.RemoveAt(list.Count - 1);
					list.Add("FORTRAN_EXEC");
					ColumnHXHelper.InsertAndSetVariable(m_pNode, list, strVar, num2, bInsert: false);
				}
				string text6 = ((!string.IsNullOrEmpty(text3)) ? (text + " = " + text + " + Dampf*(" + text2 + " - " + text3 + " - " + text + ")") : (text + " = " + text + " + Dampf*(" + text2 + " - " + text + ")"));
				strVar = "F      " + text6;
				ColumnHXHelper.InsertAndSetVariable(m_pNode, list, strVar, ++num2, bInsert: false);
			}
			list.RemoveAt(list.Count - 1);
			list.Add("REBWIZ");
			if (IsLinkToChecked)
			{
				ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0);
			}
			else
			{
				ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0);
			}
			list.Clear();
			list.Add("..\\..\\");
			list.Add("\\Convergence\\Conv-Options\\Input");
			list.Add("TEAR_VAR");
			ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0);
		}

		private bool SetPushCalculatorBlock()
		{
			bool flag = true;
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Flowsheeting Options\\Calculator");
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (m_bReOpen)
			{
				ColumnHXHelper.DeleteBlock(m_pNode, list, FirstblockID);
			}
			if (!ColumnHXHelper.CreateCalculatorBlock(m_pNode, FirstblockID))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg21, caption);
				return false;
			}
			list.Add(FirstblockID + "\\Input");
			list.Add("REBWIZ");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			string text;
			string text2;
			if (BlockMode != WpfMMDialogResources.ColumnHeatxMode3)
			{
				text = "QCALC";
				text2 = "DUTY";
			}
			else
			{
				text = "PCALC";
				text2 = "PRES";
			}
			list.RemoveAt(list.Count - 1);
			list.Add("FVN_VARIABLE");
			if (!ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text, 0, bInsert: true))
			{
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("READ_VAR");
			if (!ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text, 0, bInsert: false))
			{
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("FVN_VARTYPE\\" + text);
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "BLOCK-VAR", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("FVN_BLOCK\\" + text);
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, m_columnid, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			if (BlockMode != WpfMMDialogResources.ColumnHeatxMode3)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARIABLE\\" + text);
				flag = ColumnHXHelper.SetBlockVariable(m_pNode, list, "REB-DUTY", 0);
			}
			else
			{
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARIABLE\\" + text);
				flag = ColumnHXHelper.SetBlockVariable(m_pNode, list, "TH-REB-PRES", 0);
			}
			if (!flag)
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("FVN_VARIABLE");
			if (!ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text2, 1, bInsert: true))
			{
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("WRITE_VAR");
			if (!ColumnHXHelper.InsertAndSetVariable(m_pNode, list, text2, 0, bInsert: false))
			{
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("FVN_VARTYPE\\" + text2);
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "BLOCK-VAR", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			if (BlockMode != WpfMMDialogResources.ColumnHeatxMode3)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_BLOCK\\" + text2);
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, BlockID, 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARIABLE\\" + text2);
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "DUTY", 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
			}
			else
			{
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_BLOCK\\" + text2);
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, FlashBlockID, 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
				list.RemoveAt(list.Count - 1);
				list.Add("FVN_VARIABLE\\" + text2);
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "PRES", 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
			}
			string strVar = "F      " + text2 + " = " + text;
			list.RemoveAt(list.Count - 1);
			list.Add("FORTRAN_EXEC");
			if (!ColumnHXHelper.InsertAndSetVariable(m_pNode, list, strVar, 0, bInsert: false))
			{
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("REBWIZ");
			if (!((!IsLinkToChecked) ? ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0) : ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0)))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			return true;
		}

		private bool SetFlashBlock()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (!m_bReOpen)
			{
				List<string> list2 = new List<string>();
				list2.Add("..\\..\\");
				list2.Add("Streams");
				if (!ColumnHXHelper.InitDiffBlock(m_pNode, list, FlashBlockID, m_hxColdStreamOut, "Flash2", 1))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg21, caption);
					return false;
				}
				ColumnHXHelper.GetDefaultName(m_pNode, list2, out var objRet);
				if (!string.IsNullOrEmpty(m_hierName))
				{
					objRet = m_hierName + objRet;
				}
				ColumnHXHelper.SetGRcrehystm(objRet, FlashBlockID, 1, 1);
				ColumnHXHelper.GetDefaultName(m_pNode, list2, out var objRet2);
				if (!string.IsNullOrEmpty(m_hierName))
				{
					objRet2 = m_hierName + objRet2;
				}
				ColumnHXHelper.SetGRcrehystm(objRet2, FlashBlockID, 1, 2);
			}
			list.Clear();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add(FlashBlockID + "\\Input");
			list.Add("REBWIZ");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("DUTY");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, 0.0, 2))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("PRES");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, 0.0, 2))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("SPEC_OPT");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "PD", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg22, caption);
				return false;
			}
			if (IsLinkToChecked)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("REBWIZ");
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
			}
			return true;
		}

		private bool SetHeatxBlock()
		{
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (!m_bReOpen)
			{
				string text = ReboilerID;
				if (!string.IsNullOrEmpty(m_hierName))
				{
					text = m_hierName + text;
				}
				if (!ColumnHXHelper.InitDiffBlock(m_pNode, list, BlockID, text, "Heatx", 2))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg21 + "Heatx", caption);
					return false;
				}
				List<string> list2 = new List<string>();
				list2.Add("..\\..\\");
				list2.Add("Streams");
				ColumnHXHelper.GetDefaultName(m_pNode, list2, out m_hxColdStreamOut);
				if (!string.IsNullOrEmpty(m_hierName))
				{
					m_hxColdStreamOut = m_hierName + m_hxColdStreamOut;
				}
				ColumnHXHelper.SetGRcrehystm(m_hxColdStreamOut, BlockID, 1, 2);
			}
			list.Add(BlockID + "\\Input");
			list.Add("REBWIZ");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			if (BlockType == WpfMMDialogResources.ColumnHeatxType2 && !string.IsNullOrEmpty(m_strRebUtil))
			{
				list.RemoveAt(list.Count - 1);
				list.Add("COLD_UTIL");
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "", 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
				list.RemoveAt(list.Count - 1);
				list.Add("HOT_UTIL");
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, m_strRebUtil, 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
			}
			else
			{
				string szName = BlockID;
				if (!string.IsNullOrEmpty(m_hierName))
				{
					szName = m_hierName + BlockID;
				}
				if (ColumnHXHelper.GetGRgetbcn(szName, 0) < 2)
				{
					list.Clear();
					list.Add("..\\..\\");
					list.Add("Streams");
					ColumnHXHelper.GetDefaultName(m_pNode, list, out var objRet);
					if (!string.IsNullOrEmpty(m_hierName))
					{
						objRet = m_hierName + objRet;
					}
					ColumnHXHelper.SetGRcrehystm(objRet, BlockID, 0, 1);
				}
				if (ColumnHXHelper.GetGRgetbcn(szName, 1) < 2)
				{
					list.Clear();
					list.Add("..\\..\\");
					list.Add("Streams");
					ColumnHXHelper.GetDefaultName(m_pNode, list, out var objRet2);
					if (!string.IsNullOrEmpty(m_hierName))
					{
						objRet2 = m_hierName + objRet2;
					}
					ColumnHXHelper.SetGRcrehystm(objRet2, BlockID, 1, 1);
				}
			}
			string objValue = ((BlockMode == WpfMMDialogResources.ColumnHeatxMode1) ? "DESIGN" : ((!(BlockMode == WpfMMDialogResources.ColumnHeatxMode2)) ? "SIMULATION" : "RATING"));
			list.Clear();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add(BlockID + "\\Input");
			list.Add("PROGRAM_MODE");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, objValue, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("INPUT_FILE");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, HxInputFile, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("MODE");
			if (!ColumnHXHelper.SetBlockVariable(objValue: (!(BlockType == WpfMMDialogResources.ColumnHeatxType1)) ? "SHORTCUT" : "TASCPLUS-RIG", ptrP: m_pNode, StrListBlocks: list, nType: 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("SPEC");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "DUTY", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.Clear();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add("\\Input\\QN");
			double dDuty = 1.0;
			ColumnHXHelper.GetDutyAndUnit(m_pNode, list, out dDuty, out var strUnit);
			list.RemoveAt(list.Count - 1);
			list.Add(BlockID + "\\Input");
			list.Add("VALUE");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, dDuty, 2))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count - 1);
			list.Add("SPECUN");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, strUnit, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			string objValue2 = ((!(ReboilerType == WpfMMDialogResources.ColumnHXComStr2)) ? "THERMOSIPHON" : "KETTLE");
			list.RemoveAt(list.Count - 1);
			list.Add("EXCH_TYPE");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, objValue2, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			string objValue3 = ((!(CirculationType == WpfMMDialogResources.ColumnHeatxCir2)) ? "FIND-FLOW" : "FIXED-FLOW");
			list.RemoveAt(list.Count - 1);
			list.Add("CIRC_TYPE");
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, objValue3, 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			if (IsLinkToChecked)
			{
				list.RemoveAt(list.Count - 1);
				list.Add("REBWIZ");
				if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
					return false;
				}
			}
			return true;
		}

		private bool SetDistillationColumn()
		{
			if (!m_bReOpen)
			{
				string text = ReboilerID;
				if (!string.IsNullOrEmpty(m_hierName))
				{
					text = m_hierName + text;
				}
				ColumnHXHelper.SetGRcrehystm(text, m_columnid, 1, 8);
			}
			bool flag = true;
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			list.Add(m_columnid + "\\Input");
			list.Add("OPT_PSEUDO\\" + ReboilerID);
			flag = ColumnHXHelper.SetBlockVariable(m_pNode, list, "REBOILER", 0);
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (!flag)
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count() - 1);
			list.Add("PSEUDO_PHAS1\\" + ReboilerID);
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "R", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.RemoveAt(list.Count() - 1);
			list.Add("P_STATE\\" + ReboilerID);
			if (!ColumnHXHelper.SetBlockVariable(m_pNode, list, "INLET", 0))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			list.Clear();
			list.Add("..\\..\\");
			list.Add("\\Streams\\" + ReboilerID + "\\Input");
			list.Add("REBWIZ");
			if (!((!IsLinkToChecked) ? ColumnHXHelper.SetBlockVariable(m_pNode, list, "NO", 0) : ColumnHXHelper.SetBlockVariable(m_pNode, list, "YES", 0)))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg20, caption);
				return false;
			}
			return true;
		}

		private void ExecuteCommandOnBrowse(object arg)
		{
			System.Windows.Forms.OpenFileDialog openFileDialog = new System.Windows.Forms.OpenFileDialog();
			openFileDialog.RestoreDirectory = true;
			openFileDialog.Filter = "Tasc+ Input Files (*.edr)|*.edr||";
			if (openFileDialog.ShowDialog() == DialogResult.OK)
			{
				HxInputFile = openFileDialog.FileName;
			}
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			m_parent.DialogResult = false;
		}

		public bool CheckUniqueStreamName()
		{
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, ReboilerID))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg4, caption);
				return false;
			}
			list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Streams");
			if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, ReboilerID))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg4, caption);
				return false;
			}
			if (IsMoveToChecked && !string.IsNullOrEmpty(MoveToBlock))
			{
				string moveToBlock = MoveToBlock;
				if (moveToBlock.Contains("."))
				{
					moveToBlock.Replace(".", "\\Data\\Blocks\\");
				}
				list.RemoveAt(list.Count - 1);
				list.Add("\\Blocks\\" + moveToBlock + "\\Data\\Streams");
				if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, ReboilerID))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg5 + moveToBlock + WpfMMDialogResources.ColumnHXTipErrMsg6, caption);
					return false;
				}
			}
			return true;
		}

		public bool CheckUniqueClaculatorName(string strName)
		{
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (!string.IsNullOrEmpty(FirstblockID) && !string.IsNullOrEmpty(SecondblockID) && FirstblockID == SecondblockID)
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg7, caption);
				return false;
			}
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Flowsheeting Options\\Calculator");
			if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, strName) && !m_bReOpen)
			{
				MMMessageBox.Show(strName + WpfMMDialogResources.ColumnHXTipErrMsg8, caption);
				return false;
			}
			if (IsMoveToChecked && !string.IsNullOrEmpty(MoveToBlock))
			{
				string moveToBlock = MoveToBlock;
				if (moveToBlock.Contains("."))
				{
					moveToBlock.Replace(".", "\\Data\\Blocks\\");
				}
				list.RemoveAt(list.Count - 1);
				list.Add("\\Blocks\\" + moveToBlock + "\\Data\\Flowsheeting Options\\Calculator");
				if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, strName) && !m_bReOpen)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg5 + moveToBlock + WpfMMDialogResources.ColumnHXTipErrMsg6, caption);
					return false;
				}
			}
			return true;
		}

		public bool CheckUniqueBlockName(string csBlockid)
		{
			string caption = MMVersionHelper.MVGetI18nProductNameM();
			if (csBlockid.StartsWith(",") || csBlockid.StartsWith("$") || csBlockid.StartsWith(":") || csBlockid.StartsWith("+") || csBlockid.StartsWith("-") || csBlockid.Contains("."))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg11, caption);
				if (csBlockid == BlockID)
				{
					BlockID = "";
				}
				else if (csBlockid == FlashBlockID)
				{
					FlashBlockID = "";
				}
				else if (csBlockid == MoveToBlock)
				{
					MoveToBlock = "";
				}
				return false;
			}
			List<string> list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Streams");
			if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, csBlockid))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg8, caption);
				return false;
			}
			list = new List<string>();
			list.Add("..\\..\\");
			list.Add("\\Blocks");
			if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, csBlockid) && (!(csBlockid == BlockID) || !BlockComboListID.Contains(csBlockid)) && (!(csBlockid == FlashBlockID) || !FlashBlockComboListID.Contains(csBlockid)) && (!(csBlockid == MoveToBlock) || !MoveToComboListBlock.Contains(csBlockid)))
			{
				MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg8, caption);
				return false;
			}
			if (IsMoveToChecked && !string.IsNullOrEmpty(MoveToBlock))
			{
				string moveToBlock = MoveToBlock;
				if (moveToBlock.Contains("."))
				{
					moveToBlock.Replace(".", "\\Data\\Blocks\\");
				}
				list.RemoveAt(list.Count - 1);
				list.Add("\\Blocks\\" + moveToBlock + "\\Data\\Blocks");
				if (ColumnHXHelper.CheckBlockVarValue(m_pNode, list, csBlockid) && (!(csBlockid == BlockID) || !BlockComboListID.Contains(csBlockid)) && (!(csBlockid == FlashBlockID) || !FlashBlockComboListID.Contains(csBlockid)) && (!(csBlockid == MoveToBlock) || !MoveToComboListBlock.Contains(csBlockid)))
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg5 + moveToBlock + WpfMMDialogResources.ColumnHXTipErrMsg6, caption);
					return false;
				}
			}
			return true;
		}
	}
	public class ControlVariableListDialog : MMDialog, IComponentConnector
	{
		public class ControlVariable
		{
			public string Name { get; set; }

			public string Description { get; set; }
		}

		public List<ControlVariable> ControlVariableList;

		public string sControlVariableName = string.Empty;

		public int nVariableSelectedIndex = -1;

		internal ControlVariableListDialog dlg;

		internal Grid grid1;

		internal System.Windows.Controls.Button CVListOk;

		internal System.Windows.Controls.Button Cancel;

		internal System.Windows.Controls.DataGrid dgVariableList;

		private bool _contentLoaded;

		public void LoadControlVariableList(string sCtrlVarList)
		{
			if (sCtrlVarList == null || sCtrlVarList.Length <= 0)
			{
				return;
			}
			string[] array = sCtrlVarList.Split('|');
			ControlVariableList = new List<ControlVariable>();
			for (int i = 0; i < array.Length; i++)
			{
				string[] array2 = array[i].Split(',');
				ControlVariable controlVariable = new ControlVariable();
				controlVariable.Name = array2[0];
				if (array2.Length > 1)
				{
					controlVariable.Description = array2[1];
				}
				ControlVariableList.Add(controlVariable);
			}
		}

		public ControlVariableListDialog(string sVarInfoList)
		{
			LoadControlVariableList(sVarInfoList);
			InitializeComponent();
			dgVariableList.ItemsSource = ControlVariableList;
			dgVariableList.SelectionChanged += ControlVariable_Selected;
			CVListOk.IsEnabled = nVariableSelectedIndex >= 0;
		}

		private void ControlVariable_Selected(object sender, SelectionChangedEventArgs e)
		{
			nVariableSelectedIndex = dgVariableList.SelectedIndex;
			if (nVariableSelectedIndex >= 0 && nVariableSelectedIndex < ControlVariableList.Count)
			{
				sControlVariableName = ControlVariableList[nVariableSelectedIndex].Name;
			}
			CVListOk.IsEnabled = nVariableSelectedIndex >= 0;
		}

		private void Ok_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/controlvariablelistdialog.xaml", UriKind.Relative);
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
				dlg = (ControlVariableListDialog)target;
				break;
			case 2:
				grid1 = (Grid)target;
				break;
			case 3:
				CVListOk = (System.Windows.Controls.Button)target;
				CVListOk.Click += Ok_Click;
				break;
			case 4:
				Cancel = (System.Windows.Controls.Button)target;
				break;
			case 5:
				dgVariableList = (System.Windows.Controls.DataGrid)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class RecTypeI18nHelper
	{
		private static readonly Dictionary<string, string> RecordTypeDictionary = new Dictionary<string, string>
		{
			{ "material", "rectype_streams_material" },
			{ "heat", "rectype_streams_heat" },
			{ "work", "rectype_streams_work" },
			{ "generic", "rectype_analysis_generic" },
			{ "ptenvelope", "rectype_analysis_ptenvelope" },
			{ "residue", "rectype_analysis_residue" },
			{ "terdiagram", "rectype_analysis_terdiagram" },
			{ "assay", "rectype_assay_blend_assay" },
			{ "blend", "rectype_assay_blend_blend" },
			{ "broyden", "rectype_convergence_broyden" },
			{ "complex", "rectype_convergence_complex" },
			{ "direct", "rectype_convergence_direct" },
			{ "newton", "rectype_convergence_newton" },
			{ "secant", "rectype_convergence_secant" },
			{ "sqp", "rectype_convergence_sqp" },
			{ "wegstein", "rectype_convergence_wegstein" },
			{ "mixture", "rectype_data_mixture" },
			{ "pure-comp", "rectype_data_pure_comp" },
			{ "point-data", "rectype_data_set_point_data" },
			{ "profile-data", "rectype_data_set_profile_data" },
			{ "custom", "rectype_objective_custom" },
			{ "linear", "rectype_objective_linear" },
			{ "sumofsquares", "rectype_objective_sumofsquares" },
			{ "emulsion", "rectype_reactions_emulsion" },
			{ "free-rad", "rectype_reactions_free_rad" },
			{ "general", "rectype_reactions_general" },
			{ "ionic", "rectype_reactions_ionic" },
			{ "lhhw", "rectype_reactions_lhhw" },
			{ "powerlaw", "rectype_reactions_powerlaw" },
			{ "reac-dist", "rectype_reactions_reac_dist" },
			{ "segment-bas", "rectype_reactions_segment_bas" },
			{ "step-growth", "rectype_reactions_step_growth" },
			{ "user", "rectype_reactions_user" },
			{ "useracm", "rectype_reactions_useracm" },
			{ "ziegler-nat", "rectype_reactions_ziegler_nat" },
			{ "constraint", "rectype_model_analysis_constraint" },
			{ "optimization", "rectype_model_analysis_optimization" },
			{ "regression", "rectype_model_analysis_regression" },
			{ "nc-params", "rectype__nc_params" },
			{ "pair", "rectype__pair" },
			{ "scalar", "rectype__scalar" },
			{ "t-dependent", "rectype__t_dependent" },
			{ "unifac-group", "rectype__unifac_group" }
		};

		public static string GetTranslatedRecType(string recType)
		{
			if (RecordTypeDictionary.Keys.Contains(recType.ToLower()))
			{
				return ApwnRecTypeResource.ResourceManager.GetString(RecordTypeDictionary[recType.ToLower()], Thread.CurrentThread.CurrentUICulture);
			}
			return recType;
		}

		public static string GetRecTypeFromDisplayName(string displayName)
		{
			string result = string.Empty;
			int num = displayName.IndexOf('(');
			int num2 = displayName.IndexOf(')');
			if (num != 0 && num2 != 0 && num2 > num)
			{
				result = displayName.Substring(num + 1, num2 - num - 1);
			}
			return result;
		}
	}
	public class CopyMarkDlgViewModel : INotifyPropertyChanged
	{
		private string _name;

		private string _displayname;

		private bool? _isChecked = false;

		private bool _isExpanded;

		private bool _preventUpdateParent;

		public static bool m_bCheckAll;

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
					string recTypeFromDisplayName = RecTypeI18nHelper.GetRecTypeFromDisplayName(Reference.DisplayName);
					if (!string.IsNullOrEmpty(recTypeFromDisplayName))
					{
						string oldValue = $"({recTypeFromDisplayName})";
						string newValue = $"({RecTypeI18nHelper.GetTranslatedRecType(recTypeFromDisplayName)})";
						return Reference.DisplayName.Replace(oldValue, newValue);
					}
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
				bool? isChecked = _isChecked;
				return IsEnabled & isChecked;
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

		public CopyMarkDlgViewModel Parent { get; private set; }

		public IList<CopyMarkDlgViewModel> Children { get; private set; }

		public bool IsLeafNode => Children.Count == 0;

		public bool IsInitialized { get; private set; }

		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}

		public CopyMarkDlgViewModel(RecordNode reference, CopyMarkDlgViewModel parent = null)
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
				IsEnabled = Children.Count((CopyMarkDlgViewModel x) => x.IsEnabled) > 0;
			}
			if (m_bCheckAll)
			{
				IsExpanded = IsEnabled;
			}
			IsInitialized = true;
		}

		private void RefreshChildren()
		{
			if (Reference == null || Children != null)
			{
				return;
			}
			Children = new List<CopyMarkDlgViewModel>();
			foreach (RecordNode child in Reference.Children)
			{
				Children.Add(new CopyMarkDlgViewModel(child, this));
			}
		}

		private void InitializeCheckedAndExpanded()
		{
			if (Reference.IsChecked)
			{
				IsChecked = Reference.IsChecked;
				for (CopyMarkDlgViewModel copyMarkDlgViewModel = this; copyMarkDlgViewModel != null; copyMarkDlgViewModel = copyMarkDlgViewModel.Parent)
				{
					copyMarkDlgViewModel.IsExpanded = true;
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
				foreach (CopyMarkDlgViewModel child in Children)
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
			if (Children.Count((CopyMarkDlgViewModel x) => x.IsChecked.HasValue && x.IsChecked.Value) == Children.Count)
			{
				IsChecked = true;
			}
			else if (Children.Count((CopyMarkDlgViewModel x) => x.IsChecked.HasValue && !x.IsChecked.Value) == Children.Count)
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
	public class CopyMarkDlg : Window, IComponentConnector
	{
		[CompilerGenerated]
		private sealed class RootRecordEnumerator : IEnumerable<RecordNode>, IEnumerable, IEnumerator<RecordNode>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private RecordNode currentRecord;

			private int initialThreadId;

			public CopyMarkDlg dialog;

			private IEnumerator<CopyMarkDlgViewModel> viewModels;

			private IEnumerator<RecordNode> records;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
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
						DisposeRecords();
					}
				}
				finally
				{
					DisposeViewModels();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					CopyMarkDlg copyMarkDlg = dialog;
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
					if (copyMarkDlg.RootNodes != null)
					{
						viewModels = copyMarkDlg.RootNodes.GetEnumerator();
						iteratorState = -3;
						goto IL_00b3;
					}
					goto IL_00cd;
					IL_0099:
					if (records.MoveNext())
					{
						RecordNode current = records.Current;
						currentRecord = current;
						iteratorState = 1;
						completedNormally = true;
						return true;
					}
					DisposeRecords();
					records = null;
					goto IL_00b3;
					IL_00b3:
					if (viewModels.MoveNext())
					{
						CopyMarkDlgViewModel current2 = viewModels.Current;
						records = copyMarkDlg.GetMarkedRecordNodes(current2).GetEnumerator();
						iteratorState = -4;
						goto IL_0099;
					}
					DisposeViewModels();
					viewModels = null;
					goto IL_00cd;
					IL_00cd:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeViewModels()
			{
				iteratorState = -1;
				if (viewModels != null)
				{
					viewModels.Dispose();
				}
			}

			private void DisposeRecords()
			{
				iteratorState = -3;
				if (records != null)
				{
					records.Dispose();
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
						dialog = dialog
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

			private RecordNode currentRecord;

			private int initialThreadId;

			private CopyMarkDlgViewModel wizardNode;

			public CopyMarkDlgViewModel initialWizardNode;

			public CopyMarkDlg dialog;

			private IEnumerator<CopyMarkDlgViewModel> viewModels;

			private IEnumerator<RecordNode> records;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
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
						DisposeRecords();
					}
				}
				finally
				{
					DisposeViewModels();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					CopyMarkDlg copyMarkDlg = dialog;
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
								currentRecord = wizardNode.Reference;
								iteratorState = 1;
								completedNormally = true;
								return true;
							}
							break;
						}
						viewModels = wizardNode.Children.GetEnumerator();
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
						if (viewModels.MoveNext())
						{
							CopyMarkDlgViewModel current = viewModels.Current;
							records = copyMarkDlg.GetMarkedRecordNodes(current).GetEnumerator();
							iteratorState = -4;
							goto IL_0108;
						}
						DisposeViewModels();
						viewModels = null;
						break;
						IL_0108:
						if (records.MoveNext())
						{
							RecordNode current2 = records.Current;
							currentRecord = current2;
							iteratorState = 2;
							completedNormally = true;
							return true;
						}
						DisposeRecords();
						records = null;
						goto IL_0122;
					}
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeViewModels()
			{
				iteratorState = -1;
				if (viewModels != null)
				{
					viewModels.Dispose();
				}
			}

			private void DisposeRecords()
			{
				iteratorState = -3;
				if (records != null)
				{
					records.Dispose();
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
						dialog = dialog
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

		public static readonly DependencyProperty RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<CopyMarkDlgViewModel>), typeof(CopyMarkDlg));

		private string _strHelpID;

		private string _windTitle;

		private IntPtr m_ptrModel = IntPtr.Zero;

		private int m_nType;

		private bool m_bCheckAll;

		private bool bHasLoad;

		internal System.Windows.Controls.TreeView theTreeView;

		internal System.Windows.Controls.CheckBox checkHideDisabled;

		private bool _contentLoaded;

		public string HelpFile => "gendbhlp.chm";

		public string HelpId => _strHelpID;

		public string WindowTitle => _windTitle;

		public IEnumerable<CopyMarkDlgViewModel> RootNodes
		{
			get
			{
				return (IEnumerable<CopyMarkDlgViewModel>)GetValue(RootNodesProperty);
			}
			set
			{
				SetValue(RootNodesProperty, value);
			}
		}

		public CopyMarkDlg(string strTitle, IntPtr ptr, int nType = 0, bool bCheckAll = false)
		{
			InitializeComponent();
			m_bCheckAll = bCheckAll;
			base.Loaded += CopyMarkDlg_Loaded;
			if (strTitle == WpfMMDialogResources.CopyMarkTitle1)
			{
				_strHelpID = "2";
			}
			if (strTitle == WpfMMDialogResources.CopyMarkTitle2)
			{
				_strHelpID = "100";
			}
			m_nType = nType;
			m_ptrModel = ptr;
			_windTitle = strTitle;
			CopyMarkDlgViewModel.m_bCheckAll = m_bCheckAll;
		}

		private void CopyMarkDlg_Loaded(object sender, RoutedEventArgs e)
		{
			if (!bHasLoad)
			{
				base.DataContext = this;
				RefreshRootNodes();
				bHasLoad = true;
			}
		}

		private void RefreshRootNodes()
		{
			if (RootNodes != null)
			{
				return;
			}
			List<CopyMarkDlgViewModel> list = new List<CopyMarkDlgViewModel>();
			foreach (RecordNode item in PrepareRecordNodes())
			{
				CopyMarkDlgViewModel copyMarkDlgViewModel = new CopyMarkDlgViewModel(item);
				if (string.IsNullOrEmpty(copyMarkDlgViewModel.Name))
				{
					string displayName = (copyMarkDlgViewModel.Name = WpfMMDialogResources.Plant);
					copyMarkDlgViewModel.DisplayName = displayName;
				}
				if (m_bCheckAll)
				{
					copyMarkDlgViewModel.IsChecked = copyMarkDlgViewModel.IsEnabled;
					copyMarkDlgViewModel.IsExpanded = copyMarkDlgViewModel.IsEnabled;
				}
				list.Add(copyMarkDlgViewModel);
			}
			RootNodes = list;
		}

		private IList<RecordNode> PrepareRecordNodes()
		{
			RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
			if (recordTreeHelper.InitializeMMRecTree(m_ptrModel, m_nType))
			{
				return recordTreeHelper.BuildRecordTreeNodes();
			}
			return null;
		}

		[IteratorStateMachine(typeof(RootRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes()
		{
			return new RootRecordEnumerator(-2)
			{
				dialog = this
			};
		}

		[IteratorStateMachine(typeof(ChildRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes(CopyMarkDlgViewModel wizardNode)
		{
			return new ChildRecordEnumerator(-2)
			{
				dialog = this,
				initialWizardNode = wizardNode
			};
		}

		private void button1_Click(object sender, RoutedEventArgs e)
		{
			IEnumerable<RecordNode> markedRecordNodes = GetMarkedRecordNodes();
			RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
			recordTreeHelper.HYDelAllItems();
			foreach (RecordNode item in markedRecordNodes)
			{
				recordTreeHelper.MarkRecord(item);
			}
			base.DialogResult = true;
		}

		private void button2_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/copymarkdlg.xaml", UriKind.Relative);
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
				theTreeView = (System.Windows.Controls.TreeView)target;
				break;
			case 2:
				checkHideDisabled = (System.Windows.Controls.CheckBox)target;
				break;
			case 3:
				((System.Windows.Controls.Button)target).Click += button1_Click;
				break;
			case 4:
				((System.Windows.Controls.Button)target).Click += button2_Click;
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
	public class ColumnHXIntegrationDlg : MMDialog, IComponentConnector
	{
		private string productName = MMVersionHelper.MVGetI18nProductNameM();

		internal System.Windows.Controls.TextBox textBox1;

		internal System.Windows.Controls.TextBox textBox2;

		internal System.Windows.Controls.GroupBox groupBox1;

		internal System.Windows.Controls.ComboBox CmbBlockID;

		internal System.Windows.Controls.ComboBox CmbFlashBlockID;

		internal System.Windows.Controls.ComboBox CmbMoveToHierarchy;

		private bool _contentLoaded;

		public new bool Initialized => ((ColumnHXIntegrationDlgViewModel)base.DataContext).Initialized;

		public ColumnHXIntegrationDlg()
		{
			InitializeComponent();
			base.Loaded += ColumnHXIntegrationDlg_Loaded;
		}

		public ColumnHXIntegrationDlg(IntPtr ptrIaModel, string szModelName, string szBlockName)
		{
			InitializeComponent();
			base.DataContext = new ColumnHXIntegrationDlgViewModel(this, ptrIaModel, szModelName, szBlockName);
			base.Loaded += ColumnHXIntegrationDlg_Loaded2;
		}

		private void ColumnHXIntegrationDlg_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = new ColumnHXIntegrationDlgViewModel();
			SetComboBoxTextToUpperCase(CmbBlockID);
			SetComboBoxTextToUpperCase(CmbFlashBlockID);
			SetComboBoxTextToUpperCase(CmbMoveToHierarchy);
		}

		private void ColumnHXIntegrationDlg_Loaded2(object sender, RoutedEventArgs e)
		{
			SetComboBoxTextToUpperCase(CmbBlockID);
			SetComboBoxTextToUpperCase(CmbFlashBlockID);
			SetComboBoxTextToUpperCase(CmbMoveToHierarchy);
		}

		private void textBox2_LostFocus(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel columnHXIntegrationDlgViewModel = base.DataContext as ColumnHXIntegrationDlgViewModel;
			if (!columnHXIntegrationDlgViewModel.m_bReOpen)
			{
				columnHXIntegrationDlgViewModel.CheckUniqueStreamName();
			}
		}

		private void TextBox_LostFocus(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel obj = base.DataContext as ColumnHXIntegrationDlgViewModel;
			obj.CheckUniqueClaculatorName(obj.FirstblockID);
		}

		private void TextBox_LostFocus_1(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel obj = base.DataContext as ColumnHXIntegrationDlgViewModel;
			obj.CheckUniqueClaculatorName(obj.SecondblockID);
		}

		private void ComboBox_LostFocus(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel columnHXIntegrationDlgViewModel = base.DataContext as ColumnHXIntegrationDlgViewModel;
			if (!columnHXIntegrationDlgViewModel.m_bReOpen && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.BlockID))
			{
				if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.BlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.FlashBlockID) && columnHXIntegrationDlgViewModel.BlockID == columnHXIntegrationDlgViewModel.FlashBlockID)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg9, productName);
				}
				else if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.BlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.MoveToBlock) && columnHXIntegrationDlgViewModel.BlockID == columnHXIntegrationDlgViewModel.MoveToBlock)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg10, productName);
				}
				else
				{
					columnHXIntegrationDlgViewModel.CheckUniqueBlockName(columnHXIntegrationDlgViewModel.BlockID);
				}
			}
		}

		private void ComboBox_LostFocus_1(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel columnHXIntegrationDlgViewModel = base.DataContext as ColumnHXIntegrationDlgViewModel;
			if (!columnHXIntegrationDlgViewModel.m_bReOpen && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.FlashBlockID))
			{
				if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.BlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.FlashBlockID) && columnHXIntegrationDlgViewModel.BlockID == columnHXIntegrationDlgViewModel.FlashBlockID)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg9, productName);
				}
				else if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.FlashBlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.MoveToBlock) && columnHXIntegrationDlgViewModel.FlashBlockID == columnHXIntegrationDlgViewModel.MoveToBlock)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg12, productName);
				}
			}
		}

		private void ComboBox_LostFocus_2(object sender, RoutedEventArgs e)
		{
			ColumnHXIntegrationDlgViewModel columnHXIntegrationDlgViewModel = base.DataContext as ColumnHXIntegrationDlgViewModel;
			if (!columnHXIntegrationDlgViewModel.m_bReOpen && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.MoveToBlock))
			{
				if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.BlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.MoveToBlock) && columnHXIntegrationDlgViewModel.BlockID == columnHXIntegrationDlgViewModel.MoveToBlock)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg10, productName);
				}
				else if (!string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.FlashBlockID) && !string.IsNullOrEmpty(columnHXIntegrationDlgViewModel.MoveToBlock) && columnHXIntegrationDlgViewModel.FlashBlockID == columnHXIntegrationDlgViewModel.MoveToBlock)
				{
					MMMessageBox.Show(WpfMMDialogResources.ColumnHXTipErrMsg12, productName);
				}
			}
		}

		private void SetComboBoxTextToUpperCase(System.Windows.Controls.ComboBox cmbCtrl)
		{
			if (Utilities.GetDescendantFromName(cmbCtrl, "PART_EditableTextBox") is System.Windows.Controls.TextBox textBox)
			{
				textBox.CharacterCasing = System.Windows.Controls.CharacterCasing.Upper;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/columnhxintegrationdlg.xaml", UriKind.Relative);
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
				textBox1 = (System.Windows.Controls.TextBox)target;
				break;
			case 2:
				textBox2 = (System.Windows.Controls.TextBox)target;
				textBox2.LostFocus += textBox2_LostFocus;
				break;
			case 3:
				groupBox1 = (System.Windows.Controls.GroupBox)target;
				break;
			case 4:
				CmbBlockID = (System.Windows.Controls.ComboBox)target;
				CmbBlockID.LostFocus += ComboBox_LostFocus;
				break;
			case 5:
				CmbFlashBlockID = (System.Windows.Controls.ComboBox)target;
				CmbFlashBlockID.LostFocus += ComboBox_LostFocus_1;
				break;
			case 6:
				((System.Windows.Controls.TextBox)target).LostFocus += TextBox_LostFocus;
				break;
			case 7:
				((System.Windows.Controls.TextBox)target).LostFocus += TextBox_LostFocus_1;
				break;
			case 8:
				CmbMoveToHierarchy = (System.Windows.Controls.ComboBox)target;
				CmbMoveToHierarchy.LostFocus += ComboBox_LostFocus_2;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ConvertDlg : Window, IComponentConnector
	{
		internal StackPanel stackPanel1;

		internal TextBlock DescriptionTextBlock;

		internal Grid grid1;

		internal System.Windows.Controls.Button OkButton;

		internal System.Windows.Controls.Button CancelButton;

		private bool _contentLoaded;

		public ConvertToM CppCode { get; set; }

		public string LabelText => string.Format(WpfMMDialogResources.ConvertTo_PromptLabel, CppCode.LabelText);

		public ConvertDlg(object comPtr)
		{
			base.DataContext = this;
			CppCode = new ConvertToM(Marshal.GetIUnknownForObject(comPtr));
			InitializeComponent();
			base.Closed += delegate(object sender, EventArgs a)
			{
				((ConvertDlg)sender).CppCode.Cleanup();
			};
		}

		private void OkButton_Click(object sender, RoutedEventArgs e)
		{
			CppCode.OnOk();
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/convertdlg.xaml", UriKind.Relative);
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
				stackPanel1 = (StackPanel)target;
				break;
			case 2:
				DescriptionTextBlock = (TextBlock)target;
				break;
			case 3:
				grid1 = (Grid)target;
				break;
			case 4:
				OkButton = (System.Windows.Controls.Button)target;
				OkButton.Click += OkButton_Click;
				break;
			case 5:
				CancelButton = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class CostBlkUnitDlg : Window, IComponentConnector
	{
		internal System.Windows.Controls.ComboBox comboBox1;

		internal System.Windows.Controls.Label label3;

		internal System.Windows.Controls.Label label4;

		internal System.Windows.Controls.Button button1;

		internal System.Windows.Controls.Button button2;

		private bool _contentLoaded;

		public CostBlkUnitDlg()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/costblkunitdlg.xaml", UriKind.Relative);
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
				comboBox1 = (System.Windows.Controls.ComboBox)target;
				break;
			case 2:
				label3 = (System.Windows.Controls.Label)target;
				break;
			case 3:
				label4 = (System.Windows.Controls.Label)target;
				break;
			case 4:
				button1 = (System.Windows.Controls.Button)target;
				break;
			case 5:
				button2 = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class DefineID : Window, IComponentConnector
	{
		private bool _contentLoaded;

		public DefineID()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/defineid.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	[ComVisible(true)]
	[Guid("4E77497A-8275-4D31-8261-DA794E458DC9")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IDialogDriver
	{
		int ShowDefineIDPrefixDialog(string ID, out string newID);

		int ShowDefineIDSuffixDialog(string ID, out string newID);

		int ShowEditLabelDialog(string label, out string newLabel);

		int ShowEditIDDialog(string ID, out string newID);

		int ShowDialog(string dialogName);

		int ShowConvertToDialog(object comPtr);

		int ShowFileDialog(string dialogName, string fileName);

		int ShowFileDialog(string dialogName, string fileName, string dialogTitle);

		int ShowMoveErrorDlg(string fileName, bool bCanCancel);

		int ShowFindVariableDlg(long _main, int lRow, string szSearchText, string SenName);

		int ShowMoveToDlg(string name, long ptrIaModel, bool bCanExplode, long ptrAdvanced, int eProcType, [MarshalAs(UnmanagedType.AnsiBStr)] out string strselHier, out int iselHier);

		int ShowColumnHXIntegrationDlg(long main, string szModelName, string szBlockName);

		int ShowSuperNextDlg(string dialogName, string titlein, string textin);

		bool GetApwzFormat(out bool bNoMore);

		bool GetBkpFormat(out bool bNoMore);

		int ShowHierImportDlg(ref short shortClear, ref short shortGlobalReplace);

		int ShowProgressDlg();

		void ProgressDlgClose();

		void ProgressDlgInitialize(int nMin = 0, int nMax = 0, int nStep = 1);

		void ProgressDlgStepIt();

		int ProgressDlgGetWasCancelled();

		int ShowExportHierarchyTree(string strTitle, long _pNode, int nType, bool bCheckAll, out string strFileName);

		int ResolveStrmEONameDlg(string dialogName);

		int ShowCopyMarkDlg(string strTitle, long _ptr, int nType, bool bCheckAll);

		int ShowCopyMarkDlg2(string strTitle, long _ptr, int nType, bool bCheckAll);

		int ShowParaValDlg(long _ptr);

		int DontAskMB(string message, string setting, int flags);

		int ShowEOExportWzd(Window own, string caption, string obj, int local, int import, int hier);

		int ShowOpenFileDialog(string strInitialDirectory, string strFilter, string strDefFileName, bool bShowHierarchy, out string strFilePath);

		int ShowSaveFileDialog(string strInitialDirectory, string strFilter, string strDefFileName, bool bShowHierarchy, out string strFilePath);

		int ShowConfirmImportCustomGlobalDataPropSetDialog();

		int ShowResultsInconsistentDlg();

		int ShowTPSARUpgradeDialog(ref int checkbox);

		int ShowACMModelConflictsDialog(string modelConflictInfo, out string sModelInstallFlags, string modelConflictInfoE, out string sModelInstallFlagsE);

		int ShowControlVariablesListDialog(string sVarDescList, out string sControlVarName);

		int ShowMMMessageBox(string strMsg, int iButton, int iIcon);
	}
	[ComVisible(true)]
	[Guid("CF82C4ED-F1AD-4ADB-AA7E-480C2009A5B9")]
	[ProgId("AspenTech.AspenPlus.WpfMMDialog.DialogDriver.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class DialogDriver : IDialogDriver
	{
		private ProgressDlg m_WinProgress;

		private const int IDCANCEL = 2;

		public static string InternalVersionString => SystemEnvironment.InternalVersionString;

		public static string ExternalVersionString => SystemEnvironment.ExternalVersionString;

		public int ShowDefineIDPrefixDialog(string ID, out string newID)
		{
			newID = ID;
			IDBoxDlg iDBoxDlg = new IDBoxDlg("Prefix", "Please add the Prefix", IDBoxDlg.IDType.Prefix, 11);
			iDBoxDlg.ID = ID;
			bool? flag = iDBoxDlg.ShowDialog();
			if (flag == true)
			{
				newID = iDBoxDlg.ID;
			}
			return (flag == true) ? 1 : 0;
		}

		public int ShowDefineIDSuffixDialog(string ID, out string newID)
		{
			newID = ID;
			IDBoxDlg iDBoxDlg = new IDBoxDlg("Suffix", "Please add the Suffix", IDBoxDlg.IDType.Suffix, 11);
			iDBoxDlg.ID = ID;
			bool? flag = iDBoxDlg.ShowDialog();
			if (flag == true)
			{
				newID = iDBoxDlg.ID;
			}
			return (flag == true) ? 1 : 0;
		}

		public int ShowEditLabelDialog(string label, out string newLabel)
		{
			newLabel = label;
			EditLabel editLabel = new EditLabel();
			editLabel.LabelText = label;
			editLabel.LabelMaxLength = 31;
			bool? flag = editLabel.ShowDialog();
			if (flag == true)
			{
				newLabel = editLabel.LabelText;
			}
			return (flag == true) ? 1 : 0;
		}

		public int ShowEditIDDialog(string ID, out string newID)
		{
			newID = ID;
			EditIDdlg editIDdlg = new EditIDdlg();
			editIDdlg.ID = ID;
			editIDdlg.IDMaxLength = 11;
			bool? flag = editIDdlg.ShowDialog();
			if (flag == true)
			{
				newID = editIDdlg.ID;
			}
			return (flag == true) ? 1 : 0;
		}

		public int ShowDialog(string dialogName)
		{
			bool? flag = null;
			Window window = null;
			switch (dialogName)
			{
			case "ColumnHXIntegration":
				window = new ColumnHXIntegrationDlg();
				break;
			case "CopyMark":
				window = new ColumnHXIntegrationDlg();
				break;
			case "CostBlkUnit":
				window = new CostBlkUnitDlg();
				break;
			case "DefineID":
				window = new DefineID();
				break;
			case "DontAskMB":
				window = new DontAskMB("The first example, which is Extensible Application Markup Language (XAML), defines a TextBox and places it in a StackPanel element. Three Button controls represent the three enumeration values of the Visibility property: Visible, Hidden, and Collapsed. When a user clicks any of these buttons, the click triggers an event in the code-behind file that is associated with the Button. The Visibility state of the TextBox is changed to match the value associated with the Button.", "setting", 65793);
				break;
			case "EditID":
				window = new EditIDdlg();
				break;
			case "EditLabel":
				window = new EditLabel();
				break;
			case "HierImport":
				window = new HierImportDlg();
				break;
			case "IDBox":
				window = new IDBoxDlg("Test Title", "Please enter test id(8):", IDBoxDlg.IDType.ID, 8);
				break;
			case "MarkBox":
				window = new MarkBoxDlg();
				break;
			case "MoveTo":
				window = new MoveToDlg();
				break;
			case "Progress":
				window = new ProgressDlg();
				break;
			case "ResolveConflicts":
				window = new ResolveConflictsDlg();
				break;
			case "Reveal":
				window = new RevealDlg();
				break;
			case "Type2Dlg":
				window = new Type2Dlg();
				break;
			case "UnknownFormat":
				if (!HelperFuncs.GetDialogsSuppressed())
				{
					MMMessageBox.Show(ApwnResources.UnknownFormatDoc, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				}
				break;
			default:
				window = null;
				break;
			case "EditPaste":
				break;
			}
			if (window != null)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null)
					{
						window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						window.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
				}
				flag = window.ShowDialog();
			}
			if (flag == true)
			{
				return 1;
			}
			return 0;
		}

		public int ShowConvertToDialog(object comPtr)
		{
			ConvertDlg convertDlg = new ConvertDlg(comPtr);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					convertDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					convertDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			convertDlg.ShowDialog();
			return (convertDlg.DialogResult == true) ? 1 : 0;
		}

		public int ShowFindVariableDlg(long _main, int lRow, string szSearchText, string SenName)
		{
			FindVariableDlg findVariableDlg = new FindVariableDlg(new IntPtr(_main), lRow, szSearchText, SenName);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					findVariableDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					findVariableDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			findVariableDlg.ShowDialog();
			return (findVariableDlg.DialogResult == true) ? 1 : 0;
		}

		public int ShowFileDialog(string dialogName, string fileName)
		{
			return ShowFileDialog(dialogName, fileName, "");
		}

		public int ShowFileDialog(string dialogName, string fileName, string dialogTitle)
		{
			ShowFileDlgViewModel showFileDlgViewModel = null;
			switch (dialogName)
			{
			case "ShowFileDlg":
				showFileDlgViewModel = new ShowFileDlgViewModel();
				break;
			case "ShowFlowsheetIncompleteDlg":
				showFileDlgViewModel = new ShowFlowsheetIncompleteDlgViewModel();
				break;
			case "ShowTFFProcessingError":
				showFileDlgViewModel = new ShowTFFProcessingErrorViewModel();
				break;
			case "ShowReadBackupFileError":
				showFileDlgViewModel = new ShowReadBackupFileErrorViewModel();
				break;
			case "ShowInputSummaryError":
				showFileDlgViewModel = new ShowInputSummaryErrorViewModel();
				break;
			case "SpeedupExportDialog":
				showFileDlgViewModel = new SpeedupExportDialogViewModel();
				showFileDlgViewModel.Title = dialogTitle;
				break;
			case "ShowEOErrorDlg":
				showFileDlgViewModel = new ShowEOErrorDlgViewModel();
				break;
			case "ShowMoveErrorDlg":
				showFileDlgViewModel = new ShowMoveErrorDlgViewModel();
				break;
			case "ShowProcessTypeErrorDlg":
				showFileDlgViewModel = new ShowFileDlgViewModel();
				showFileDlgViewModel.Title = dialogTitle;
				break;
			}
			if (showFileDlgViewModel == null || !showFileDlgViewModel.Initialize(fileName))
			{
				return 0;
			}
			ShowFileDlg showFileDlg = new ShowFileDlg();
			showFileDlg.DataContext = showFileDlgViewModel;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					showFileDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					showFileDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			showFileDlg.Show();
			return 1;
		}

		public int ShowMoveErrorDlg(string fileName, bool bCanCancel)
		{
			ShowMoveErrorDlgViewModel showMoveErrorDlgViewModel = new ShowMoveErrorDlgViewModel();
			if (!showMoveErrorDlgViewModel.Initialize(fileName, bCanCancel))
			{
				return 0;
			}
			ShowFileDlg showFileDlg = new ShowFileDlg();
			showFileDlg.DataContext = showMoveErrorDlgViewModel;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					showFileDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					showFileDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			showFileDlg.ShowDialog();
			return (showFileDlg.DialogResult == true) ? 1 : 0;
		}

		public int ShowMoveToDlg(string name, long _ptrIaModel, bool bCanExplode, long _ptrAdvanced, int eProcType, [MarshalAs(UnmanagedType.AnsiBStr)] out string strselHier, out int iselHier)
		{
			IntPtr ptrIaModel = new IntPtr(_ptrIaModel);
			IntPtr ptrAdvanced = new IntPtr(_ptrAdvanced);
			MoveToDlg moveToDlg = new MoveToDlg(name, ptrIaModel, bCanExplode, ptrAdvanced, eProcType);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					moveToDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					moveToDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			moveToDlg.ShowDialog();
			strselHier = moveToDlg.StrNodeValue;
			iselHier = moveToDlg.NRadioSelected;
			RecordMoveToHierarchyEventArgs e = new RecordMoveToHierarchyEventArgs();
			if (iselHier == 2)
			{
				e.MoveToHierarchy = "MOVETOPARENT";
			}
			else
			{
				e.MoveToHierarchy = moveToDlg.StrNodeValue;
			}
			if (iselHier == 1 || iselHier == 2)
			{
				e.HierarchyIsRelative = true;
			}
			container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<RecordMoveToHierarchyEvent>().Publish(e);
			return (moveToDlg.DialogResult == true) ? 1 : 0;
		}

		public int ShowColumnHXIntegrationDlg(long _main, string szModelName, string szBlockName)
		{
			ColumnHXIntegrationDlg columnHXIntegrationDlg = new ColumnHXIntegrationDlg(new IntPtr(_main), szModelName, szBlockName);
			if (columnHXIntegrationDlg.Initialized)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null)
					{
						columnHXIntegrationDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						columnHXIntegrationDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
				}
				columnHXIntegrationDlg.ShowDialog();
				return (columnHXIntegrationDlg.DialogResult == true) ? 1 : 0;
			}
			return 0;
		}

		public int ShowSuperNextDlg(string dialogName, string titlein, string textin)
		{
			int num = 0;
			string text = titlein;
			string text2 = textin;
			Collection<string> collection = new Collection<string>();
			int[] array = new int[5] { 1, 4, 3, 6, 5 };
			int[] array2 = new int[4] { 1, 4, 3, 6 };
			int[] array3 = new int[3] { 1, 4, 3 };
			int[] array4 = new int[4] { 8, 2, 4, 3 };
			int[] array5 = new int[5] { 8, 2, 4, 3, 7 };
			int[] array6 = new int[2] { 1, 7 };
			int[] array7 = new int[3] { 8, 3, 7 };
			int[] array8 = new int[3] { 1, 4, 3 };
			int[] array9 = new int[5] { 1, 2, 4, 3, 7 };
			int[] array10 = new int[1] { 7 };
			int[] array11 = new int[2] { 3, 7 };
			CxsCase cxsCase = DialogsModule.Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			bool flag = true;
			string text3 = null;
			int minWidth = 0;
			if (cxsCase != null)
			{
				flag = cxsCase.Solver.CanRun;
				text3 = CxsConverter.ValueToString(cxsCase.BatchGet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value"));
			}
			switch (dialogName)
			{
			case "REG_incomp":
				if (text == null)
				{
					text = WpfMMDialogResources.tiDataFitIncomplete;
					minWidth = 450;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtDataHas;
				}
				collection.Add(WpfMMDialogResources.opEnterMoreExp);
				collection.Add(WpfMMDialogResources.opSpecDR);
				break;
			case "MAIN_pcomp":
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtNextStep;
				}
				switch (text3)
				{
				case "DRS":
					if (text == null)
					{
						text = WpfMMDialogResources.tiReqdrsIC;
						minWidth = 400;
					}
					if (flag)
					{
						collection.Add(WpfMMDialogResources.opRunPropDRS);
					}
					collection.Add(WpfMMDialogResources.opEnterAddRaw);
					collection.Add(WpfMMDialogResources.opSwitchToAnalysis);
					break;
				case "PROP":
				case "TGS":
					if (text == null)
					{
						text = WpfMMDialogResources.tiReqPropIC;
					}
					if (flag)
					{
						collection.Add(WpfMMDialogResources.opRunProp);
					}
					else
					{
						text2 = WpfMMDialogResources.txtGoNext;
						collection.Add(WpfMMDialogResources.opGoToNext);
					}
					collection.Add(WpfMMDialogResources.opMOdReq);
					collection.Add(WpfMMDialogResources.opEnterProp);
					collection.Add(WpfMMDialogResources.opEnterRaw);
					if (!SystemEnvironment.IsAspenProperties)
					{
						collection.Add(WpfMMDialogResources.opGoToSim);
					}
					break;
				case "FLOWSHEET":
					if (flag)
					{
						if (text == null)
						{
							text = WpfMMDialogResources.tiReqPropIC;
						}
						collection.Add(WpfMMDialogResources.opRunAnalysis);
						collection.Add(WpfMMDialogResources.opMOdReq);
					}
					else
					{
						num = 1;
					}
					break;
				}
				break;
			case "MAIN_pcomp_ndb":
				if (text == null)
				{
					text = WpfMMDialogResources.tiNonDBCom;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtYourSim;
				}
				collection.Add(WpfMMDialogResources.opGoToNext);
				collection.Add(WpfMMDialogResources.opEnterProp);
				collection.Add(WpfMMDialogResources.opEnterRaw);
				collection.Add(WpfMMDialogResources.opEnterMolStr);
				collection.Add(WpfMMDialogResources.opTurnOnPEST);
				break;
			case "PCES_pcomp":
				if (text == null)
				{
					text = WpfMMDialogResources.tiReqPCESIC;
					minWidth = 450;
				}
				if (flag)
				{
					if (text2 == null)
					{
						text2 = WpfMMDialogResources.txtGoNext;
					}
					collection.Add(WpfMMDialogResources.opRunPropEst);
				}
				else if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtNextStep;
				}
				collection.Add(WpfMMDialogResources.opSwitchToAnalysis);
				break;
			case "PCES_pcomp_ndb":
				if (text == null)
				{
					text = WpfMMDialogResources.tiNonDBCom;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtYourSim;
				}
				collection.Add(WpfMMDialogResources.opGoToNext);
				collection.Add(WpfMMDialogResources.opEnterAddProp);
				collection.Add(WpfMMDialogResources.opEnterAddRaw);
				collection.Add(WpfMMDialogResources.opEntMolStrEs);
				break;
			case "ADA_pcomp":
				if (text == null)
				{
					text = WpfMMDialogResources.tiReqPropIC;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtGoNextRS;
				}
				collection.Add(WpfMMDialogResources.opGoToNext);
				collection.Add(WpfMMDialogResources.opEnterProp);
				collection.Add(WpfMMDialogResources.opEnterRaw);
				break;
			case "adapcs_opt":
				if (text == null)
				{
					text = WpfMMDialogResources.tiReqPropADA;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtGoNextRS;
				}
				collection.Add(WpfMMDialogResources.opGoToNext);
				collection.Add(WpfMMDialogResources.opModifyADA);
				collection.Add(WpfMMDialogResources.opModifyPetro);
				collection.Add(WpfMMDialogResources.opSpecifyADA);
				collection.Add(WpfMMDialogResources.opSpecifyOptions);
				collection.Add(WpfMMDialogResources.opEnterPseudo);
				break;
			case "DATA_FIT_REG_incomp":
				if (text == null)
				{
					text = WpfMMDialogResources.tiDataFitIncomplete;
					minWidth = 450;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtDataHas;
				}
				collection.Add(WpfMMDialogResources.opEnterMoreExp);
				collection.Add(WpfMMDialogResources.opSpecifyDataFit);
				break;
			case "prop_comp_para":
				if (text == null)
				{
					text = WpfMMDialogResources.tiAddProp;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtReqPr;
				}
				collection.Add(WpfMMDialogResources.opPurCp);
				collection.Add(WpfMMDialogResources.opBin);
				collection.Add(WpfMMDialogResources.opEpp);
				collection.Add(WpfMMDialogResources.opEtp);
				break;
			case "next_sm_complete":
				if (text == null)
				{
					text = WpfMMDialogResources.tiSimCom;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtSimNorRp;
				}
				collection.Add(WpfMMDialogResources.opdisRS);
				collection.Add(WpfMMDialogResources.opEnterEq);
				collection.Add(WpfMMDialogResources.opSyncEO);
				break;
			case "next_eo_sync":
				if (text == null)
				{
					text = WpfMMDialogResources.tiSimCom;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtYourSimNor;
				}
				collection.Add(WpfMMDialogResources.opDisEQV);
				collection.Add(WpfMMDialogResources.opdisRS);
				collection.Add(WpfMMDialogResources.opEnterEq);
				collection.Add(WpfMMDialogResources.opSolEq);
				break;
			case "next_eo_sync_err":
				if (text == null)
				{
					text = WpfMMDialogResources.tiSimErr;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtSimNor;
				}
				collection.Add(WpfMMDialogResources.opviewser);
				collection.Add(WpfMMDialogResources.opDisEQV);
				collection.Add(WpfMMDialogResources.opdisRS);
				collection.Add(WpfMMDialogResources.opEnterEq);
				collection.Add(WpfMMDialogResources.opSolEq);
				break;
			case "next_eo_config":
				if (text == null)
				{
					text = WpfMMDialogResources.tiReqEO;
					minWidth = 450;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.txtGoNextEO;
				}
				collection.Add(WpfMMDialogResources.opGoToNext);
				collection.Add(WpfMMDialogResources.opDefM);
				collection.Add(WpfMMDialogResources.opDefSC);
				collection.Add(WpfMMDialogResources.opDefObj);
				collection.Add(WpfMMDialogResources.opDefSG);
				collection.Add(WpfMMDialogResources.opdefUC);
				collection.Add(WpfMMDialogResources.opdefHier);
				break;
			case "next_prop_complete":
				if (text == null)
				{
					text = WpfMMDialogResources.tiReqPropIC;
				}
				if (text2 == null)
				{
					text2 = WpfMMDialogResources.tiNextStep;
				}
				collection.Add(WpfMMDialogResources.opRunProp);
				if (!SystemEnvironment.IsAspenProperties)
				{
					collection.Add(WpfMMDialogResources.opSwitchToSim);
				}
				minWidth = 280;
				break;
			}
			if (text != null)
			{
				bool flag2 = false;
				int result = 0;
				int result2 = 0;
				string name = "SOFTWARE\\AspenTech\\Aspen Plus\\" + InternalVersionString + "\\mmgini";
				RegistryKey registryKey = Registry.CurrentUser.OpenSubKey(name, writable: true);
				if (registryKey != null)
				{
					if (registryKey.GetValue("netdrivecasesavetoremote") == null)
					{
						registryKey.SetValue("netdrivecasesavetoremote", result);
					}
					if (registryKey.GetValue("ndcasesavedontshowmsgagain") == null)
					{
						registryKey.SetValue("ndcasesavedontshowmsgagain", result2);
					}
					string s = registryKey.GetValue("netdrivecasesavetoremote").ToString();
					string s2 = registryKey.GetValue("ndcasesavedontshowmsgagain").ToString();
					int.TryParse(s, out result);
					int.TryParse(s2, out result2);
					flag2 = result == 1;
					registryKey.Close();
				}
				if (result2 == 0)
				{
					SuperNextDlg superNextDlg = new SuperNextDlg(text, text2, collection, minWidth);
					IUnityContainer container = DialogsModule.Container;
					if (container != null)
					{
						IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
						if (shellApplication != null)
						{
							superNextDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
							superNextDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						}
					}
					if (text.Equals(WpfMMDialogResources.tiSimCom) || text.Equals(WpfMMDialogResources.tiSimErr) || text.Equals(ApwnResources.SimWarns))
					{
						MMHelp.SetHelpFile(superNextDlg, "userguide1.chm");
						MMHelp.SetHelpId(superNextDlg, 398);
					}
					else if (text.Equals(ApwnResources.ReqPROPSIComp))
					{
						MMHelp.SetHelpFile(superNextDlg, "userguide1.chm");
						MMHelp.SetHelpId(superNextDlg, 442);
					}
					if (!superNextDlg.DontShowMessageAgain)
					{
						bool? flag3 = superNextDlg.ShowDialog();
						superNextDlg.Cursor = System.Windows.Input.Cursors.Arrow;
						flag2 = flag3.HasValue && flag3.Value;
					}
					registryKey = Registry.CurrentUser.OpenSubKey(name, writable: true);
					if (registryKey != null)
					{
						registryKey.SetValue("netdrivecasesavetoremote", flag2 ? 1 : 0);
						registryKey.SetValue("ndcasesavedontshowmsgagain", superNextDlg.DontShowMessageAgain ? 1 : 0);
						registryKey.Close();
					}
					if (flag2)
					{
						num = superNextDlg.ButtonIndex + 1;
						switch (dialogName)
						{
						case "MAIN_pcomp":
							switch (text3)
							{
							case "DRS":
								num = ((!flag) ? array11[num - 1] : array7[num - 1]);
								break;
							case "PROP":
							case "TGS":
								num = ((!flag) ? array9[num - 1] : array5[num - 1]);
								break;
							case "FLOWSHEET":
								num = ((!flag) ? array8[num - 1] : array4[num - 1]);
								break;
							}
							break;
						case "MAIN_pcomp_ndb":
							num = array[num - 1];
							break;
						case "PCES_pcomp":
							num = ((!flag) ? array10[num - 1] : array6[num - 1]);
							break;
						case "PCES_pcomp_ndb":
							num = array2[num - 1];
							break;
						case "ADA_pcomp":
							num = array3[num - 1];
							break;
						}
					}
				}
			}
			return num;
		}

		private bool GetApwzFormatImpl(ApwzFormat.FormateType ft, out bool bNoMore)
		{
			if (ScriptingSupport.Enabled)
			{
				bNoMore = true;
				return false;
			}
			if (!HelperFuncs.GetVisibleSuppress())
			{
				bNoMore = false;
				return false;
			}
			ApwzFormat apwzFormat = new ApwzFormat(ft);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					apwzFormat.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					apwzFormat.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = null;
			apwzFormat.ShowDialog();
			if (overrideCursor != null)
			{
				Mouse.OverrideCursor = overrideCursor;
			}
			bNoMore = apwzFormat.NoMore;
			return apwzFormat.CopyDoc;
		}

		public bool GetApwzFormat(out bool bNoMore)
		{
			return GetApwzFormatImpl(ApwzFormat.FormateType.Apwz, out bNoMore);
		}

		public bool GetBkpFormat(out bool bNoMore)
		{
			return GetApwzFormatImpl(ApwzFormat.FormateType.Bkp, out bNoMore);
		}

		public int ShowHierImportDlg(ref short shortClear, ref short shortGlobalReplace)
		{
			HierImportDlg hierImportDlg = new HierImportDlg();
			hierImportDlg.Title = FlowsheetResources.PFS_HIERARCHY_IMPORT_OPTION;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					hierImportDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					hierImportDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			hierImportDlg.ShowDialog();
			if (hierImportDlg.DialogResult == true)
			{
				if (hierImportDlg.BoolClear)
				{
					shortClear = 1;
				}
				else
				{
					shortClear = 0;
				}
				if (hierImportDlg.BoolGlobalReplace)
				{
					shortGlobalReplace = 1;
				}
				else
				{
					shortGlobalReplace = 0;
				}
			}
			return (hierImportDlg.DialogResult == true) ? 1 : 0;
		}

		public int ShowProgressDlg()
		{
			m_WinProgress = new ProgressDlg();
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					m_WinProgress.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					m_WinProgress.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			m_WinProgress.Show();
			return 0;
		}

		public void ProgressDlgInitialize(int nMin, int nMax, int nStep)
		{
			if (m_WinProgress != null)
			{
				m_WinProgress.InitializeBar(nMin, nMax, nStep);
			}
		}

		public void ProgressDlgStepIt()
		{
			if (m_WinProgress != null)
			{
				m_WinProgress.StepIt();
			}
		}

		public void ProgressDlgClose()
		{
			if (m_WinProgress != null)
			{
				m_WinProgress.Close();
			}
		}

		public int ProgressDlgGetWasCancelled()
		{
			if (m_WinProgress != null)
			{
				return m_WinProgress.IsCancelled;
			}
			return 0;
		}

		public int ShowExportHierarchyTree(string strTitle, long _pNode, int nType, bool bCheckAll, out string strFileName)
		{
			IntPtr ptr = new IntPtr(_pNode);
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			strFileName = "";
			string text = "";
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					while (true)
					{
						ExportHierarchy exportHierarchy = new ExportHierarchy();
						exportHierarchy.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						exportHierarchy.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						exportHierarchy.TxtFileLocation.Text = text;
						exportHierarchy.ShowDialog();
						if (exportHierarchy.DialogResult != true)
						{
							break;
						}
						strFileName = exportHierarchy.FileName;
						text = exportHierarchy.FileName;
						ExportHierarchyTree exportHierarchyTree = new ExportHierarchyTree(strTitle, ptr, nType, bCheckAll);
						if (exportHierarchyTree == null)
						{
							break;
						}
						exportHierarchyTree.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						exportHierarchyTree.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						exportHierarchyTree.ShowDialog();
						if (exportHierarchyTree.Result != 1)
						{
							result = ((exportHierarchyTree.DialogResult == true) ? 1 : 0);
							break;
						}
					}
				}
			}
			return result;
		}

		public int ResolveStrmEONameDlg(string dialogName)
		{
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					ResolveStreamEOName resolveStreamEOName = null;
					if (dialogName == "Rename")
					{
						resolveStreamEOName = new ResolveStreamEOName(bRename: true);
					}
					else if (dialogName == "Remove")
					{
						resolveStreamEOName = new ResolveStreamEOName();
					}
					if (resolveStreamEOName != null)
					{
						resolveStreamEOName.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						resolveStreamEOName.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						resolveStreamEOName.ShowDialog();
						result = ((resolveStreamEOName.DialogResult == true) ? 1 : 0);
					}
				}
			}
			return result;
		}

		public int ShowCopyMarkDlg(string strTitle, long _ptr, int nType, bool bCheckAll)
		{
			IntPtr ptr = new IntPtr(_ptr);
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					CopyMarkDlg copyMarkDlg = new CopyMarkDlg(strTitle, ptr, nType, bCheckAll);
					if (copyMarkDlg != null)
					{
						copyMarkDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						copyMarkDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						copyMarkDlg.ShowDialog();
						result = ((copyMarkDlg.DialogResult == true) ? 1 : 0);
					}
				}
			}
			return result;
		}

		public int ShowCopyMarkDlg2(string strTitle, long _ptr, int nType, bool bCheckAll)
		{
			IntPtr ptr = new IntPtr(_ptr);
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					CopyMarkDlg copyMarkDlg = new CopyMarkDlg(strTitle, ptr, nType, bCheckAll);
					if (copyMarkDlg != null)
					{
						copyMarkDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						copyMarkDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						copyMarkDlg.ShowDialog();
						result = ((copyMarkDlg.DialogResult == true) ? 1 : 2);
					}
				}
			}
			return result;
		}

		public int ShowParaValDlg(long _ptr)
		{
			IntPtr ptrParas = new IntPtr(_ptr);
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					ParamVal paramVal = new ParamVal(ptrParas);
					if (paramVal != null)
					{
						paramVal.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						paramVal.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						paramVal.ShowDialog();
						result = ((paramVal.DialogResult == true) ? 1 : 0);
					}
				}
			}
			return result;
		}

		public int DontAskMB(string message, string setting, int flags)
		{
			DontAskMB dontAskMB = new DontAskMB(message, setting, flags);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					dontAskMB.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					dontAskMB.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				}
			}
			dontAskMB.ShowDontAskMBDialog();
			return dontAskMB.ReturnCode;
		}

		public int ShowEOExportWzd(Window own, string caption, string obj, int local, int import, int hier)
		{
			int result = 0;
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					Window window = new EOExportWzd(caption, obj, local, import, hier);
					if (window != null)
					{
						window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						window.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
						window.ShowDialog();
						result = ((window.DialogResult == true) ? 1 : 0);
					}
				}
			}
			return result;
		}

		public int ShowOpenFileDialog(string strInitialDirectory, string strFilter, string strDefFileName, bool bShowHierarchy, out string strFilePath)
		{
			strFilePath = string.Empty;
			AxAdvancedFileDialog axAdvancedFileDialog = new AxAdvancedFileDialog();
			axAdvancedFileDialog.CreateControl();
			axAdvancedFileDialog.SetInitialDir(strInitialDirectory);
			axAdvancedFileDialog.SetFilter(strFilter);
			if (!string.IsNullOrEmpty(strDefFileName))
			{
				axAdvancedFileDialog.SetFileName(strDefFileName);
			}
			axAdvancedFileDialog.SetProductType(MMVersionHelper.MVGetProductCodeM());
			axAdvancedFileDialog.SetFavoritesPath(MMPFSHelper.GetFavoritesPath());
			bool result = axAdvancedFileDialog.ShowOpenFileDialog(bShowHierarchy ? 1 : 0) != 0;
			strFilePath = axAdvancedFileDialog.GetPathName();
			axAdvancedFileDialog.Dispose();
			return result ? 1 : 0;
		}

		public int ShowSaveFileDialog(string strInitialDirectory, string strFilter, string strDefFileName, bool bShowHierarchy, out string strFilePath)
		{
			strFilePath = string.Empty;
			AxAdvancedFileDialog axAdvancedFileDialog = new AxAdvancedFileDialog();
			axAdvancedFileDialog.CreateControl();
			axAdvancedFileDialog.SetInitialDir(strInitialDirectory);
			axAdvancedFileDialog.SetFilter(strFilter);
			if (!string.IsNullOrEmpty(strDefFileName))
			{
				axAdvancedFileDialog.SetFileName(strDefFileName);
			}
			axAdvancedFileDialog.SetProductType(MMVersionHelper.MVGetProductCodeM());
			axAdvancedFileDialog.SetFavoritesPath(MMPFSHelper.GetFavoritesPath());
			bool result = axAdvancedFileDialog.ShowSaveFileDialog(bShowHierarchy ? 1 : 0) != 0;
			strFilePath = axAdvancedFileDialog.GetPathName();
			axAdvancedFileDialog.Dispose();
			return result ? 1 : 0;
		}

		public int ShowConfirmImportCustomGlobalDataPropSetDialog()
		{
			if (MMMessageBox.Show("Do you want to import custom global data prop set?", ApwnResources.AspenPlus, MMMessageBoxButton.YesNo, MMMessageBoxImage.Question) == MMMessageBoxResult.Yes)
			{
				return 1;
			}
			return 0;
		}

		public int ShowTPSARUpgradeDialog(ref int checkbox)
		{
			checkbox = 0;
			TPSARUpgradeDlg tPSARUpgradeDlg = new TPSARUpgradeDlg();
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					tPSARUpgradeDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					tPSARUpgradeDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				}
			}
			tPSARUpgradeDlg.ShowDialog();
			checkbox = tPSARUpgradeDlg.DoNotAskAgain;
			return tPSARUpgradeDlg.ReturnCode;
		}

		public int ShowACMModelConflictsDialog(string modelConflictInfo, out string sModelInstallFlags, string modelConflictInfoE, out string sModelInstallFlagsE)
		{
			ACMModelConflictsDlg aCMModelConflictsDlg = new ACMModelConflictsDlg(modelConflictInfo, modelConflictInfoE);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					aCMModelConflictsDlg.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					aCMModelConflictsDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				}
			}
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = System.Windows.Input.Cursors.Arrow;
			bool? flag = aCMModelConflictsDlg.ShowDialog();
			Mouse.OverrideCursor = overrideCursor;
			sModelInstallFlags = aCMModelConflictsDlg.sModelInstallFlags;
			sModelInstallFlagsE = aCMModelConflictsDlg.sModelInstallFlagsE;
			return (flag == true) ? 1 : 0;
		}

		public int ShowControlVariablesListDialog(string sVarDescList, out string sControlVarName)
		{
			ControlVariableListDialog controlVariableListDialog = new ControlVariableListDialog(sVarDescList);
			IUnityContainer container = DialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					controlVariableListDialog.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					controlVariableListDialog.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				}
			}
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = System.Windows.Input.Cursors.Arrow;
			bool? flag = controlVariableListDialog.ShowDialog();
			Mouse.OverrideCursor = overrideCursor;
			sControlVarName = controlVariableListDialog.sControlVariableName;
			return (flag == true) ? 1 : 0;
		}

		public int ShowMMMessageBox(string strMsg, int iButton, int iIcon)
		{
			MMMessageBoxButton button = MMMessageBoxButton.OK;
			switch (iButton)
			{
			case 0:
				button = MMMessageBoxButton.OK;
				break;
			case 1:
				button = MMMessageBoxButton.OKCancel;
				break;
			case 2:
				button = MMMessageBoxButton.YesAllNo;
				break;
			case 3:
				button = MMMessageBoxButton.YesAllNoAll;
				break;
			case 4:
				button = MMMessageBoxButton.YesNo;
				break;
			case 5:
				button = MMMessageBoxButton.YesNoAll;
				break;
			case 6:
				button = MMMessageBoxButton.YesNoCancel;
				break;
			case 7:
				button = MMMessageBoxButton.AbortRetryIgnore;
				break;
			case 8:
				button = MMMessageBoxButton.RetryCancel;
				break;
			}
			MMMessageBoxImage icon = MMMessageBoxImage.None;
			switch (iIcon)
			{
			case 0:
				icon = MMMessageBoxImage.None;
				break;
			case 1:
				icon = MMMessageBoxImage.Error;
				break;
			case 2:
				icon = MMMessageBoxImage.Error;
				break;
			case 3:
				icon = MMMessageBoxImage.Error;
				break;
			case 4:
				icon = MMMessageBoxImage.Question;
				break;
			case 5:
				icon = MMMessageBoxImage.Exclamation;
				break;
			case 6:
				icon = MMMessageBoxImage.Exclamation;
				break;
			case 7:
				icon = MMMessageBoxImage.Information;
				break;
			case 8:
				icon = MMMessageBoxImage.Information;
				break;
			}
			return (int)MMMessageBox.Show(strMsg, MMVersionHelper.MVGetI18nProductNameM(), button, icon);
		}

		public int ShowResultsInconsistentDlg()
		{
			return ResultsInconsistentDlg.ShowDlg();
		}
	}
	public class DistillationSynthesis : Window, IComponentConnector
	{
		private string m_strType = string.Empty;

		private int m_iDistillationUserChoose = -1;

		private int m_iDistillationContinue;

		private bool m_bFeatureLicense;

		private bool? m_bDontShowDistillationDialog = false;

		internal System.Windows.Controls.Button BtnLm;

		internal System.Windows.Controls.Button BtnFa;

		internal System.Windows.Controls.Button BtnUds;

		internal System.Windows.Controls.Button BtnCta;

		internal System.Windows.Controls.CheckBox ChkDns;

		private bool _contentLoaded;

		public bool? DontShowDistillationDialog
		{
			get
			{
				return m_bDontShowDistillationDialog;
			}
			set
			{
				m_bDontShowDistillationDialog = value;
			}
		}

		public int DistillationUserChoose
		{
			get
			{
				return m_iDistillationUserChoose;
			}
			set
			{
				m_iDistillationUserChoose = value;
			}
		}

		public int DistillationContinue
		{
			get
			{
				return m_iDistillationContinue;
			}
			set
			{
				m_iDistillationContinue = value;
			}
		}

		public string HelpFile => "userguide2.chm";

		[DllImport("User32")]
		private static extern IntPtr GetWindowLongPtr(IntPtr hWnd, int index);

		[DllImport("User32")]
		private static extern IntPtr SetWindowLongPtr(IntPtr hWnd, int index, IntPtr newStyle);

		public DistillationSynthesis()
		{
			InitializeComponent();
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			IntPtr handle = new WindowInteropHelper(this).Handle;
			long value = GetWindowLongPtr(handle, -16).ToInt64() & -65537 & -131073 & -524289;
			SetWindowLongPtr(handle, -16, new IntPtr(value));
		}

		public DistillationSynthesis(string strType, bool bFeatureLicense)
		{
			InitializeComponent();
			m_strType = strType;
			m_bFeatureLicense = bFeatureLicense;
			base.Loaded += DistillationSynthesis_Loaded;
		}

		private void DistillationSynthesis_Loaded(object sender, RoutedEventArgs e)
		{
			BtnCta.Content = BtnCta.Content.ToString() + " " + m_strType;
			if (!m_bFeatureLicense)
			{
				BtnFa.IsEnabled = false;
				BtnUds.IsEnabled = false;
			}
		}

		private void BtnFa_Click(object sender, RoutedEventArgs e)
		{
			m_iDistillationUserChoose = 1;
			base.DialogResult = true;
			Close();
		}

		private void BtnUds_Click(object sender, RoutedEventArgs e)
		{
			m_iDistillationUserChoose = 2;
			base.DialogResult = true;
			Close();
		}

		private void BtnCta_Click(object sender, RoutedEventArgs e)
		{
			m_iDistillationUserChoose = 3;
			base.DialogResult = true;
			DistillationContinue = 1;
			Close();
		}

		private void ChkDns_Checked(object sender, RoutedEventArgs e)
		{
			System.Windows.Controls.CheckBox checkBox = sender as System.Windows.Controls.CheckBox;
			m_bDontShowDistillationDialog = checkBox.IsChecked;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/distillationsynthesis.xaml", UriKind.Relative);
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
				BtnLm = (System.Windows.Controls.Button)target;
				break;
			case 2:
				BtnFa = (System.Windows.Controls.Button)target;
				BtnFa.Click += BtnFa_Click;
				break;
			case 3:
				BtnUds = (System.Windows.Controls.Button)target;
				BtnUds.Click += BtnUds_Click;
				break;
			case 4:
				BtnCta = (System.Windows.Controls.Button)target;
				BtnCta.Click += BtnCta_Click;
				break;
			case 5:
				ChkDns = (System.Windows.Controls.CheckBox)target;
				ChkDns.Checked += ChkDns_Checked;
				ChkDns.Unchecked += ChkDns_Checked;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class DistillationSynthesisContinue : Window, IComponentConnector
	{
		internal System.Windows.Controls.Label LblRa;

		internal System.Windows.Controls.Button BtnOK;

		internal System.Windows.Controls.Button BtnCancel;

		private bool _contentLoaded;

		public DistillationSynthesisContinue()
		{
			InitializeComponent();
		}

		private void BtnOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void BtnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/distillationsynthesiscontinue.xaml", UriKind.Relative);
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
				LblRa = (System.Windows.Controls.Label)target;
				break;
			case 2:
				BtnOK = (System.Windows.Controls.Button)target;
				BtnOK.Click += BtnOK_Click;
				break;
			case 3:
				BtnCancel = (System.Windows.Controls.Button)target;
				BtnCancel.Click += BtnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class DontAskMB : MMDialog, INotifyPropertyChanged, IComponentConnector
	{
		private bool m_DontAskAgain;

		private string m_Setting;

		private int m_GroupIndex;

		private const int IDOK = 1;

		private const int IDCANCEL = 2;

		private const int IDABORT = 3;

		private const int IDRETRY = 4;

		private const int IDIGNORE = 5;

		private const int IDYES = 6;

		private const int IDNO = 7;

		private const int IDCLOSE = 8;

		private const int IDHELP = 9;

		private static readonly int[,] ButtonGroups = new int[6, 4]
		{
			{ 1, 0, 0, 9 },
			{ 1, 2, 0, 9 },
			{ 3, 4, 5, 9 },
			{ 6, 7, 2, 9 },
			{ 6, 7, 0, 9 },
			{ 4, 2, 0, 9 }
		};

		private static readonly int[] ButtonNumberOfGroup = new int[6] { 1, 2, 3, 3, 2, 2 };

		private static readonly string[] szRetStrings = new string[9]
		{
			WpfMMDialogResources.Unknown,
			WpfMMDialogResources.Ok,
			WpfMMDialogResources.Help,
			WpfMMDialogResources.Cancel,
			WpfMMDialogResources.Abort,
			WpfMMDialogResources.Retry,
			WpfMMDialogResources.Ignore,
			WpfMMDialogResources.Yes,
			WpfMMDialogResources.No
		};

		private static readonly string[] szRetStrings2 = new string[9]
		{
			WpfMMDialogResources.Unknown,
			WpfMMDialogResources._Ok,
			WpfMMDialogResources._Help,
			WpfMMDialogResources._Cancel,
			WpfMMDialogResources._Abort,
			WpfMMDialogResources._Retry,
			WpfMMDialogResources._Ignore,
			WpfMMDialogResources._Yes,
			WpfMMDialogResources._No
		};

		internal System.Windows.Controls.Label label1;

		internal System.Windows.Controls.Button Button1;

		internal System.Windows.Controls.Button Button2;

		internal System.Windows.Controls.Button Button3;

		private bool _contentLoaded;

		public string Message { get; set; }

		public bool DontAskAgain
		{
			get
			{
				return m_DontAskAgain;
			}
			set
			{
				m_DontAskAgain = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("DontAskAgain"));
				}
			}
		}

		public int ButtonNumber => ButtonNumberOfGroup[m_GroupIndex];

		public Visibility Button2Enabled
		{
			get
			{
				if (ButtonNumber < 2)
				{
					return Visibility.Collapsed;
				}
				return Visibility.Visible;
			}
		}

		public Visibility Button3Enabled
		{
			get
			{
				if (ButtonNumber != 3)
				{
					return Visibility.Collapsed;
				}
				return Visibility.Visible;
			}
		}

		public string Button1Text => LookupReturn(ButtonGroups[m_GroupIndex, 0], hasAmpersand: true);

		public string Button2Text => LookupReturn(ButtonGroups[m_GroupIndex, 1], hasAmpersand: true);

		public string Button3Text => LookupReturn(ButtonGroups[m_GroupIndex, 2], hasAmpersand: true);

		public int DefaultButton { get; set; }

		public bool Button1IsDefault => DefaultButton == 0;

		public bool Button2IsDefault => DefaultButton == 0;

		public bool Button3IsDefault => DefaultButton == 0;

		public int ReturnCode { get; private set; }

		public event PropertyChangedEventHandler PropertyChanged;

		public DontAskMB(string message, string setting, int flags)
		{
			DontAskAgain = false;
			Message = message;
			m_Setting = setting;
			m_GroupIndex = GetButtonGroup(flags);
			DefaultButton = GetDefaultButton(flags);
			base.DataContext = this;
			InitializeComponent();
			if (SystemEnvironment.IsAspenProperties)
			{
				base.Title = "Aspen Properties";
			}
		}

		public bool? ShowDontAskMBDialog()
		{
			int? settingValue = AspenTech.AspenPlus.UnmanagedWrapper.DontAskAgain.GetSettingValue(m_Setting, 0);
			if (!settingValue.HasValue)
			{
				ReturnCode = 2;
				return false;
			}
			if (settingValue.Value > 0)
			{
				ReturnCode = settingValue.Value;
				return true;
			}
			return ShowDialog();
		}

		private static int GetButtonGroup(int flags)
		{
			return flags & 0xF;
		}

		private static int GetDefaultButton(int flags)
		{
			return (flags & 0x300) >> 8;
		}

		private static string LookupReturn(int val, bool hasAmpersand)
		{
			int num = 0;
			switch (val)
			{
			case 1:
				num = 1;
				break;
			case 9:
				num = 2;
				break;
			case 2:
				num = 3;
				break;
			case 3:
				num = 4;
				break;
			case 4:
				num = 5;
				break;
			case 5:
				num = 6;
				break;
			case 6:
				num = 7;
				break;
			case 7:
				num = 8;
				break;
			}
			if (!hasAmpersand)
			{
				return szRetStrings[num];
			}
			return szRetStrings2[num];
		}

		private static int MessageBoxDefault(int flags, int nAutoDefault)
		{
			long num = ((nAutoDefault != -1) ? GetDefaultButton(nAutoDefault) : GetDefaultButton(flags));
			long num2 = GetButtonGroup(flags);
			return ButtonGroups[(int)checked((nint)num2), (int)checked((nint)num)];
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			System.Windows.Controls.Button obj = (System.Windows.Controls.Button)sender;
			int num = 0;
			switch (obj.Name)
			{
			case "Button1":
				num = ButtonGroups[m_GroupIndex, 0];
				break;
			case "Button2":
				num = ButtonGroups[m_GroupIndex, 1];
				break;
			case "Button3":
				num = ButtonGroups[m_GroupIndex, 2];
				break;
			}
			if (DontAskAgain && num != 2)
			{
				AspenTech.AspenPlus.UnmanagedWrapper.DontAskAgain.SetSettingValue(m_Setting, num, 1, 0, IntPtr.Zero);
			}
			ReturnCode = num;
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/dontaskmb.xaml", UriKind.Relative);
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
				label1 = (System.Windows.Controls.Label)target;
				break;
			case 2:
				Button1 = (System.Windows.Controls.Button)target;
				Button1.Click += Button_Click;
				break;
			case 3:
				Button2 = (System.Windows.Controls.Button)target;
				Button2.Click += Button_Click;
				break;
			case 4:
				Button3 = (System.Windows.Controls.Button)target;
				Button3.Click += Button_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	internal class EditIDdlg : Window, INotifyPropertyChanged, IComponentConnector
	{
		internal EditIDdlg root;

		internal System.Windows.Controls.TextBox IDEditBox;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public int IDMaxLength
		{
			get
			{
				return IDEditBox.MaxLength;
			}
			set
			{
				int num = value;
				if (num < 0)
				{
					num = 0;
				}
				IDEditBox.MaxLength = num;
			}
		}

		public string ID
		{
			get
			{
				return IDEditBox.Text;
			}
			set
			{
				IDEditBox.Text = value;
			}
		}

		public bool IsOKEnable => IDEditBox.Text.Length > 0;

		public event PropertyChangedEventHandler PropertyChanged;

		public EditIDdlg()
		{
			InitializeComponent();
		}

		private void IDEditBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("IsOKEnable"));
			}
		}

		private void DlgBox_Loaded(object sender, RoutedEventArgs e)
		{
			IDEditBox.Focus();
			if (IDEditBox.Text.Length > 0)
			{
				IDEditBox.SelectAll();
			}
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			if (IDHelper.ValidateID(ID, 0, bMHeatx: false, out var errorDescription))
			{
				base.DialogResult = true;
				Close();
			}
			else if (errorDescription != null)
			{
				MMMessageBox.Show(this, errorDescription, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Error);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/editiddlg.xaml", UriKind.Relative);
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
				root = (EditIDdlg)target;
				root.Loaded += DlgBox_Loaded;
				break;
			case 2:
				IDEditBox = (System.Windows.Controls.TextBox)target;
				IDEditBox.TextChanged += IDEditBox_TextChanged;
				break;
			case 3:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 4:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	internal class EditLabel : Window, INotifyPropertyChanged, IComponentConnector
	{
		internal EditLabel root;

		internal System.Windows.Controls.TextBox labelEditBox;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public int LabelMaxLength
		{
			get
			{
				return labelEditBox.MaxLength;
			}
			set
			{
				int num = value;
				if (num < 0)
				{
					num = 0;
				}
				labelEditBox.MaxLength = num;
			}
		}

		public string LabelText
		{
			get
			{
				return labelEditBox.Text;
			}
			set
			{
				labelEditBox.Text = value;
			}
		}

		public bool IsOKEnable => labelEditBox.Text.Length > 0;

		public event PropertyChangedEventHandler PropertyChanged;

		public EditLabel()
		{
			InitializeComponent();
		}

		private void labelEditBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("IsOKEnable"));
			}
		}

		private void DlgBox_Loaded(object sender, RoutedEventArgs e)
		{
			labelEditBox.Focus();
			if (labelEditBox.Text.Length > 0)
			{
				labelEditBox.SelectAll();
			}
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/editlabel.xaml", UriKind.Relative);
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
				root = (EditLabel)target;
				root.Loaded += DlgBox_Loaded;
				break;
			case 2:
				labelEditBox = (System.Windows.Controls.TextBox)target;
				labelEditBox.TextChanged += labelEditBox_TextChanged;
				break;
			case 3:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 4:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ExportHierarchy : Window, IComponentConnector
	{
		private string m_strFileName = "";

		private string m_strFileExtension = "";

		private string m_strFileFullPath = "";

		private int m_iResult;

		internal System.Windows.Controls.TextBox TxtFileLocation;

		internal System.Windows.Controls.Button BtnBrowser;

		internal System.Windows.Controls.Button BtnNext;

		internal System.Windows.Controls.Button Cancel;

		private bool _contentLoaded;

		public int Result
		{
			get
			{
				return m_iResult;
			}
			private set
			{
				m_iResult = value;
			}
		}

		public string FileName
		{
			get
			{
				return m_strFileFullPath;
			}
			private set
			{
				m_strFileFullPath = value;
			}
		}

		public ExportHierarchy()
		{
			m_strFileExtension = "";
			m_strFileName = "";
			InitializeComponent();
			base.Loaded += ExportHierarchy_Loaded;
		}

		private void ExportHierarchy_Loaded(object sender, RoutedEventArgs e)
		{
			if (string.IsNullOrEmpty(TxtFileLocation.Text) || string.IsNullOrEmpty(TxtFileLocation.Text.Trim()))
			{
				BtnNext.IsEnabled = false;
			}
		}

		private void BtnNext_Click(object sender, RoutedEventArgs e)
		{
			Directory.Exists(TxtFileLocation.Text.Trim());
			m_strFileFullPath = TxtFileLocation.Text.Trim();
			Result = 2;
			base.DialogResult = true;
			Close();
		}

		private void Cancel_Click(object sender, RoutedEventArgs e)
		{
			Result = 3;
			base.DialogResult = false;
			Close();
		}

		private void BtnBrowser_Click(object sender, RoutedEventArgs e)
		{
			System.Windows.Forms.SaveFileDialog saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			saveFileDialog.AddExtension = true;
			saveFileDialog.Filter = "Aspen Plus Backup Files (*.bkp)|";
			saveFileDialog.Title = WpfMMDialogResources.Export;
			saveFileDialog.InitialDirectory = Directory.GetCurrentDirectory();
			saveFileDialog.CheckPathExists = true;
			saveFileDialog.RestoreDirectory = true;
			if (saveFileDialog.ShowDialog() != System.Windows.Forms.DialogResult.OK)
			{
				return;
			}
			string text = saveFileDialog.FileName.ToUpper();
			if (!string.IsNullOrEmpty(text))
			{
				if (text.LastIndexOf(".BKP") != -1)
				{
					TxtFileLocation.Text = saveFileDialog.FileName;
				}
				else
				{
					TxtFileLocation.Text = saveFileDialog.FileName + ".bkp";
				}
				m_strFileExtension = ".bkp";
			}
		}

		private void TxtFileLocation_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (TxtFileLocation.Text.Trim() != "")
			{
				BtnNext.IsEnabled = true;
			}
			else
			{
				BtnNext.IsEnabled = false;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/exporthierarchy.xaml", UriKind.Relative);
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
				TxtFileLocation = (System.Windows.Controls.TextBox)target;
				TxtFileLocation.TextChanged += TxtFileLocation_TextChanged;
				break;
			case 2:
				BtnBrowser = (System.Windows.Controls.Button)target;
				BtnBrowser.Click += BtnBrowser_Click;
				break;
			case 3:
				BtnNext = (System.Windows.Controls.Button)target;
				BtnNext.Click += BtnNext_Click;
				break;
			case 4:
				Cancel = (System.Windows.Controls.Button)target;
				Cancel.Click += Cancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ExportHierarchyTreeViewModel : INotifyPropertyChanged
	{
		private string _name;

		private bool? _isChecked = true;

		private bool _isExpanded = true;

		private bool _preventUpdateParent;

		private string _displayname;

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

		public bool IsThreeState => !IsLeafNode;

		public bool? IsChecked
		{
			get
			{
				bool? isChecked = _isChecked;
				return IsEnabled & isChecked;
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

		public ExportHierarchyTreeViewModel Parent { get; private set; }

		public IList<ExportHierarchyTreeViewModel> Children { get; private set; }

		public bool IsLeafNode => Children.Count == 0;

		public bool IsInitialized { get; private set; }

		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		public ExportHierarchyTreeViewModel(RecordNode reference, ExportHierarchyTreeViewModel parent = null)
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
				IsEnabled = Children.Count((ExportHierarchyTreeViewModel x) => x.IsEnabled) > 0;
			}
			IsExpanded = IsEnabled;
			IsInitialized = true;
		}

		private void RefreshChildren()
		{
			if (Reference == null || Children != null)
			{
				return;
			}
			Children = new List<ExportHierarchyTreeViewModel>();
			foreach (RecordNode child in Reference.Children)
			{
				Children.Add(new ExportHierarchyTreeViewModel(child, this));
			}
		}

		private void InitializeCheckedAndExpanded()
		{
			if (Reference.IsChecked)
			{
				IsChecked = Reference.IsChecked;
				for (ExportHierarchyTreeViewModel exportHierarchyTreeViewModel = this; exportHierarchyTreeViewModel != null; exportHierarchyTreeViewModel = exportHierarchyTreeViewModel.Parent)
				{
					exportHierarchyTreeViewModel.IsExpanded = true;
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
				foreach (ExportHierarchyTreeViewModel child in Children)
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
			if (Children.Count((ExportHierarchyTreeViewModel x) => x.IsChecked.HasValue && x.IsChecked.Value) == Children.Count)
			{
				IsChecked = true;
			}
			else if (Children.Count((ExportHierarchyTreeViewModel x) => x.IsChecked.HasValue && !x.IsChecked.Value) == Children.Count)
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
	public class ExportHierarchyTree : Window, IComponentConnector
	{
		[CompilerGenerated]
		private sealed class RootRecordEnumerator : IEnumerable<RecordNode>, IEnumerable, IEnumerator<RecordNode>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private RecordNode currentRecord;

			private int initialThreadId;

			public ExportHierarchyTree dialog;

			private IEnumerator<ExportHierarchyTreeViewModel> viewModels;

			private IEnumerator<RecordNode> records;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
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
						DisposeRecords();
					}
				}
				finally
				{
					DisposeViewModels();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ExportHierarchyTree exportHierarchyTree = dialog;
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
					if (exportHierarchyTree.RootNodes != null)
					{
						viewModels = exportHierarchyTree.RootNodes.GetEnumerator();
						iteratorState = -3;
						goto IL_00b3;
					}
					goto IL_00cd;
					IL_0099:
					if (records.MoveNext())
					{
						RecordNode current = records.Current;
						currentRecord = current;
						iteratorState = 1;
						completedNormally = true;
						return true;
					}
					DisposeRecords();
					records = null;
					goto IL_00b3;
					IL_00b3:
					if (viewModels.MoveNext())
					{
						ExportHierarchyTreeViewModel current2 = viewModels.Current;
						records = exportHierarchyTree.GetMarkedRecordNodes(current2).GetEnumerator();
						iteratorState = -4;
						goto IL_0099;
					}
					DisposeViewModels();
					viewModels = null;
					goto IL_00cd;
					IL_00cd:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeViewModels()
			{
				iteratorState = -1;
				if (viewModels != null)
				{
					viewModels.Dispose();
				}
			}

			private void DisposeRecords()
			{
				iteratorState = -3;
				if (records != null)
				{
					records.Dispose();
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
						dialog = dialog
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

			private RecordNode currentRecord;

			private int initialThreadId;

			private ExportHierarchyTreeViewModel wizardNode;

			public ExportHierarchyTreeViewModel initialWizardNode;

			public ExportHierarchyTree dialog;

			private IEnumerator<ExportHierarchyTreeViewModel> viewModels;

			private IEnumerator<RecordNode> records;

			RecordNode IEnumerator<RecordNode>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentRecord;
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
						DisposeRecords();
					}
				}
				finally
				{
					DisposeViewModels();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ExportHierarchyTree exportHierarchyTree = dialog;
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
								currentRecord = wizardNode.Reference;
								iteratorState = 1;
								completedNormally = true;
								return true;
							}
							break;
						}
						viewModels = wizardNode.Children.GetEnumerator();
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
						if (viewModels.MoveNext())
						{
							ExportHierarchyTreeViewModel current = viewModels.Current;
							records = exportHierarchyTree.GetMarkedRecordNodes(current).GetEnumerator();
							iteratorState = -4;
							goto IL_0108;
						}
						DisposeViewModels();
						viewModels = null;
						break;
						IL_0108:
						if (records.MoveNext())
						{
							RecordNode current2 = records.Current;
							currentRecord = current2;
							iteratorState = 2;
							completedNormally = true;
							return true;
						}
						DisposeRecords();
						records = null;
						goto IL_0122;
					}
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeViewModels()
			{
				iteratorState = -1;
				if (viewModels != null)
				{
					viewModels.Dispose();
				}
			}

			private void DisposeRecords()
			{
				iteratorState = -3;
				if (records != null)
				{
					records.Dispose();
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
						dialog = dialog
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

		private int m_iResult;

		public static readonly DependencyProperty RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<ExportHierarchyTreeViewModel>), typeof(ExportHierarchyTree));

		private string _strHelpID;

		private string _windTitle;

		private IntPtr m_ptrModel = IntPtr.Zero;

		private int m_nType;

		private bool bHasLoad;

		internal System.Windows.Controls.Label LblTesting;

		internal System.Windows.Controls.TreeView theTreeView;

		internal System.Windows.Controls.CheckBox checkHideDisabled;

		internal System.Windows.Controls.Button BtnBack;

		private bool _contentLoaded;

		public int Result
		{
			get
			{
				return m_iResult;
			}
			private set
			{
				m_iResult = value;
			}
		}

		public string HelpFile => "userguide1.chm";

		public string HelpId => _strHelpID;

		public string WindowTitle => _windTitle;

		public IEnumerable<ExportHierarchyTreeViewModel> RootNodes
		{
			get
			{
				return (IEnumerable<ExportHierarchyTreeViewModel>)GetValue(RootNodesProperty);
			}
			set
			{
				SetValue(RootNodesProperty, value);
			}
		}

		public ExportHierarchyTree(string strTitle, IntPtr ptr, int nType = 0, bool bCheckAll = false)
		{
			InitializeComponent();
			base.Loaded += ExportHierarchyTree_Loaded;
			m_nType = nType;
			m_ptrModel = ptr;
			_windTitle = FlowsheetResources.PFS_SELECT_ADDITIONAL_RECORDS_TO_EXPORT;
			_strHelpID = "1328";
		}

		private void ExportHierarchyTree_Loaded(object sender, RoutedEventArgs e)
		{
			if (!bHasLoad)
			{
				base.DataContext = this;
				RefreshRootNodes();
				bHasLoad = true;
			}
		}

		private void RefreshRootNodes()
		{
			if (RootNodes != null)
			{
				return;
			}
			List<ExportHierarchyTreeViewModel> list = new List<ExportHierarchyTreeViewModel>();
			foreach (RecordNode item in PrepareRecordNodes())
			{
				ExportHierarchyTreeViewModel exportHierarchyTreeViewModel = new ExportHierarchyTreeViewModel(item);
				if (string.IsNullOrEmpty(exportHierarchyTreeViewModel.Name))
				{
					string displayName = (exportHierarchyTreeViewModel.Name = WpfMMDialogResources.ExportHierarchyTreeRoot);
					exportHierarchyTreeViewModel.DisplayName = displayName;
				}
				list.Add(exportHierarchyTreeViewModel);
			}
			RootNodes = list;
		}

		private IList<RecordNode> PrepareRecordNodes()
		{
			RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
			if (recordTreeHelper.InitializeMMRecTree(m_ptrModel, m_nType))
			{
				return recordTreeHelper.BuildRecordTreeNodes();
			}
			return null;
		}

		[IteratorStateMachine(typeof(RootRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes()
		{
			return new RootRecordEnumerator(-2)
			{
				dialog = this
			};
		}

		[IteratorStateMachine(typeof(ChildRecordEnumerator))]
		private IEnumerable<RecordNode> GetMarkedRecordNodes(ExportHierarchyTreeViewModel wizardNode)
		{
			return new ChildRecordEnumerator(-2)
			{
				dialog = this,
				initialWizardNode = wizardNode
			};
		}

		private void BtnFinish_Click(object sender, RoutedEventArgs e)
		{
			IEnumerable<RecordNode> markedRecordNodes = GetMarkedRecordNodes();
			RecordTreeHelper recordTreeHelper = new RecordTreeHelper();
			int num = 0;
			recordTreeHelper.HYDelAllItems();
			foreach (RecordNode item in markedRecordNodes)
			{
				num++;
				recordTreeHelper.MarkRecord(item);
			}
			Result = 2;
			base.DialogResult = true;
		}

		private void BtnCancel_Click(object sender, RoutedEventArgs e)
		{
			Result = 3;
			base.DialogResult = false;
		}

		private void BtnBack_Click(object sender, RoutedEventArgs e)
		{
			m_iResult = 1;
			base.DialogResult = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/exporthierarchytree.xaml", UriKind.Relative);
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
				LblTesting = (System.Windows.Controls.Label)target;
				break;
			case 2:
				theTreeView = (System.Windows.Controls.TreeView)target;
				break;
			case 3:
				checkHideDisabled = (System.Windows.Controls.CheckBox)target;
				break;
			case 4:
				BtnBack = (System.Windows.Controls.Button)target;
				BtnBack.Click += BtnBack_Click;
				break;
			case 5:
				((System.Windows.Controls.Button)target).Click += BtnFinish_Click;
				break;
			case 6:
				((System.Windows.Controls.Button)target).Click += BtnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class FileInputBox : System.Windows.Controls.UserControl, IComponentConnector
	{
		public static readonly DependencyProperty FilterProperty = DependencyProperty.Register("Filter", typeof(string), typeof(FileInputBox), new PropertyMetadata(null));

		public static readonly DependencyProperty FileOpenDlgType = DependencyProperty.Register("DlgType", typeof(int), typeof(FileInputBox), new PropertyMetadata(null));

		internal System.Windows.Controls.TextBox theTextBox;

		internal System.Windows.Controls.Button theButton;

		private bool _contentLoaded;

		public string FileName
		{
			get
			{
				return theTextBox.Text;
			}
			set
			{
				theTextBox.Text = value;
			}
		}

		public string Filter
		{
			get
			{
				return (string)GetValue(FilterProperty);
			}
			set
			{
				SetValue(FilterProperty, value);
			}
		}

		public int DlgType
		{
			get
			{
				return (int)GetValue(FileOpenDlgType);
			}
			set
			{
				SetValue(FileOpenDlgType, value);
			}
		}

		public event EventHandler<EventArgs> FileNameChanged;

		public FileInputBox()
		{
			InitializeComponent();
			theTextBox.TextChanged += OnTextChanged;
		}

		private void theButton_Click(object sender, RoutedEventArgs e)
		{
			Microsoft.Win32.FileDialog fileDialog = null;
			if (DlgType == 1)
			{
				fileDialog = new Microsoft.Win32.OpenFileDialog();
				fileDialog.RestoreDirectory = true;
			}
			if (DlgType == 0)
			{
				fileDialog = new Microsoft.Win32.SaveFileDialog();
				fileDialog.RestoreDirectory = true;
				(fileDialog as Microsoft.Win32.SaveFileDialog).OverwritePrompt = false;
			}
			if (fileDialog != null)
			{
				fileDialog.Filter = Filter;
				if (fileDialog.ShowDialog() == true)
				{
					FileName = fileDialog.FileName;
				}
			}
		}

		private void OnTextChanged(object sender, TextChangedEventArgs e)
		{
			e.Handled = true;
			if (this.FileNameChanged != null)
			{
				this.FileNameChanged(this, EventArgs.Empty);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/fileinputboxex.xaml", UriKind.Relative);
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
				theTextBox = (System.Windows.Controls.TextBox)target;
				break;
			case 2:
				theButton = (System.Windows.Controls.Button)target;
				theButton.Click += theButton_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class FindVariableDlg : Window, INotifyPropertyChanged, IComponentConnector, IStyleConnector
	{
		private IntPtr _IHNode;

		private string _SenName;

		private int _nlRow;

		private string _strSearchVariable;

		private ObservableCollection<PropertyItem> _allFoundVariable;

		private PropertyItem _selectedItem;

		private DelegateCommand<object> _commandOnOK;

		private GridViewColumnHeader _lastHeaderClicked;

		private ListSortDirection _lastDirection;

		internal FindVariableDlg DlgSearchVar;

		internal System.Windows.Controls.TextBox txtSearchCriteria;

		internal System.Windows.Controls.Button btnSearch;

		internal System.Windows.Controls.ListView lv;

		private bool _contentLoaded;

		public string HelpFile => "hlpflwop.chm";

		public string SearchVaribale
		{
			get
			{
				return _strSearchVariable;
			}
			set
			{
				if (_strSearchVariable != value)
				{
					_strSearchVariable = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SearchVaribale"));
					}
				}
			}
		}

		public ObservableCollection<PropertyItem> AllFoundVariable
		{
			get
			{
				return _allFoundVariable;
			}
			set
			{
				if (_allFoundVariable != value)
				{
					_allFoundVariable = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("AllFoundVariable"));
					}
				}
			}
		}

		public PropertyItem SelectedItem
		{
			get
			{
				return _selectedItem;
			}
			set
			{
				if (_selectedItem != value)
				{
					_selectedItem = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedItem"));
						(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
					}
				}
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK, CanExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public FindVariableDlg(IntPtr main, int lRow, string szSearchText, string SenName)
		{
			InitializeComponent();
			_IHNode = main;
			_nlRow = lRow;
			_SenName = SenName;
			SearchVaribale = szSearchText;
			txtSearchCriteria.Focus();
		}

		private void BtnSearch_Click(object sender, RoutedEventArgs e)
		{
			AllFoundVariable = SmgeHelper.SMFetchFindVariables(SearchVaribale, _IHNode, _nlRow, _SenName);
			if (AllFoundVariable.Count == 0)
			{
				MMMessageBox.Show(WpfMMDialogResources.FindVarTip, WpfMMDialogResources.FindVarCap, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				AllFoundVariable = null;
			}
		}

		private void ExecuteCommandOnOK(object arg)
		{
			if (SelectedItem != null)
			{
				SmgeHelper.SMSetServiceVariables(_IHNode, _nlRow, SelectedItem.Name, _SenName);
			}
			Close();
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			if (SelectedItem != null && SelectedItem.Name != null)
			{
				return true;
			}
			return false;
		}

		private void ListView_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			if (MyVisualHelper.TryFindFromPoint<GridViewColumnHeader>(lv, e.GetPosition(lv)) == null && AllFoundVariable != null && AllFoundVariable.Count != 0)
			{
				if (SelectedItem != null)
				{
					SmgeHelper.SMSetServiceVariables(_IHNode, _nlRow, SelectedItem.Name, _SenName);
				}
				Close();
			}
		}

		private void GridViewColumnHeaderClickedHandler(object sender, RoutedEventArgs e)
		{
			if (AllFoundVariable != null && AllFoundVariable.Count != 0 && e.OriginalSource is GridViewColumnHeader { Role: not GridViewColumnHeaderRole.Padding } gridViewColumnHeader)
			{
				ListSortDirection listSortDirection = ((gridViewColumnHeader == _lastHeaderClicked && _lastDirection == ListSortDirection.Ascending) ? ListSortDirection.Descending : ListSortDirection.Ascending);
				string sortBy = gridViewColumnHeader.Column.Header as string;
				Sort(sortBy, listSortDirection, sender as System.Windows.Controls.ListView);
				if (listSortDirection == ListSortDirection.Ascending)
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowUp"] as DataTemplate;
				}
				else
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowDown"] as DataTemplate;
				}
				if (_lastHeaderClicked != null && _lastHeaderClicked != gridViewColumnHeader)
				{
					_lastHeaderClicked.Column.HeaderTemplate = null;
				}
				_lastHeaderClicked = gridViewColumnHeader;
				_lastDirection = listSortDirection;
			}
		}

		private void Sort(string sortBy, ListSortDirection direction, System.Windows.Controls.ListView lstView)
		{
			ICollectionView defaultView = CollectionViewSource.GetDefaultView(lstView.ItemsSource);
			sortBy = ((!(sortBy == WpfMMDialogResources.FindVarDes)) ? "Name" : "Alias");
			defaultView.SortDescriptions.Clear();
			SortDescription item = new SortDescription(sortBy, direction);
			defaultView.SortDescriptions.Add(item);
			defaultView.Refresh();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/findvariabledlg.xaml", UriKind.Relative);
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
				DlgSearchVar = (FindVariableDlg)target;
				break;
			case 2:
				txtSearchCriteria = (System.Windows.Controls.TextBox)target;
				break;
			case 3:
				btnSearch = (System.Windows.Controls.Button)target;
				btnSearch.Click += BtnSearch_Click;
				break;
			case 4:
				lv = (System.Windows.Controls.ListView)target;
				lv.AddHandler(System.Windows.Controls.Primitives.ButtonBase.ClickEvent, new RoutedEventHandler(GridViewColumnHeaderClickedHandler));
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
				EventSetter eventSetter = new EventSetter();
				eventSetter.Event = System.Windows.Controls.Control.MouseDoubleClickEvent;
				eventSetter.Handler = new MouseButtonEventHandler(ListView_MouseDoubleClick);
				((Style)target).Setters.Add(eventSetter);
			}
		}
	}
	public static class MyVisualHelper
	{
		public static T TryFindParent<T>(this DependencyObject child) where T : DependencyObject
		{
			DependencyObject parentObject = child.GetParentObject();
			if (parentObject == null)
			{
				return null;
			}
			if (parentObject is T result)
			{
				return result;
			}
			return parentObject.TryFindParent<T>();
		}

		public static DependencyObject GetParentObject(this DependencyObject child)
		{
			if (child == null)
			{
				return null;
			}
			if (child is ContentElement contentElement)
			{
				DependencyObject parent = ContentOperations.GetParent(contentElement);
				if (parent != null)
				{
					return parent;
				}
				if (!(contentElement is FrameworkContentElement frameworkContentElement))
				{
					return null;
				}
				return frameworkContentElement.Parent;
			}
			if (child is FrameworkElement { Parent: { } parent2 })
			{
				return parent2;
			}
			return VisualTreeHelper.GetParent(child);
		}

		public static T TryFindFromPoint<T>(UIElement reference, Point point) where T : DependencyObject
		{
			if (!(reference.InputHitTest(point) is DependencyObject dependencyObject))
			{
				return null;
			}
			if (dependencyObject is T)
			{
				return (T)dependencyObject;
			}
			return dependencyObject.TryFindParent<T>();
		}
	}
	[ValueConversion(typeof(int), typeof(string))]
	internal class FileTypeConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if ((int)value == 0)
			{
				return ApwnResources.FileType_Aspen_Plus_X_Vector_File + " (*.x)|*.x";
			}
			return ApwnResources.FileType_Aspen_Plus_Variables_File + " (*.var)|*.var";
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class EOExportFile : WizardPage, IComponentConnector
	{
		private bool _contentLoaded;

		public EOExportFileM CppCode { get; set; }

		public EOExportFile(EOExportFileM page)
		{
			InitializeComponent();
			base.CanNext = false;
			base.CanFinish = false;
			base.CanPrev = false;
			CppCode = page;
			base.DataContext = this;
		}

		public void FileNameChanged(object sender, EventArgs e)
		{
			FileInputBox fileInputBox = sender as FileInputBox;
			if (!string.IsNullOrEmpty(fileInputBox.FileName))
			{
				CppCode.m_strFilename = fileInputBox.FileName;
			}
			bool canNext = (base.CanFinish = !string.IsNullOrEmpty(CppCode.m_strFilename));
			base.CanNext = canNext;
			WizardContainer container = base.Container;
			canNext = (base.Container.CanNext = !string.IsNullOrEmpty(CppCode.m_strFilename));
			container.CanFinish = canNext;
		}

		private void AddFileExtension()
		{
			if (CppCode.m_nXFile == 0 && !CppCode.m_strFilename.EndsWith(".x", StringComparison.InvariantCultureIgnoreCase))
			{
				CppCode.m_strFilename += ".x";
			}
			else if (CppCode.m_nXFile == 1 && !CppCode.m_strFilename.EndsWith(".var", StringComparison.InvariantCultureIgnoreCase))
			{
				CppCode.m_strFilename += ".var";
			}
		}

		private bool IsFilePathValid()
		{
			if (!Path.IsPathRooted(CppCode.m_strFilename))
			{
				MMMessageBox.Show(WpfMMDialogResources.InvalidFilePath, WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return false;
			}
			string[] array = CppCode.m_strFilename.Split('\\');
			for (int i = 1; i < array.Count(); i++)
			{
				char[] invalidFileNameChars = Path.GetInvalidFileNameChars();
				foreach (char c in invalidFileNameChars)
				{
					if (array[i].Contains(c))
					{
						MMMessageBox.Show($"{WpfMMDialogResources.InvalidChar} '{c}' !", WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
						return false;
					}
				}
			}
			if (!Directory.Exists(Path.GetDirectoryName(CppCode.m_strFilename)))
			{
				MMMessageBox.Show(WpfMMDialogResources.InvalidDir, WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return false;
			}
			return true;
		}

		public override bool DoNext()
		{
			if (!IsFilePathValid())
			{
				return false;
			}
			AddFileExtension();
			if (CppCode.GetEOWzd().m_nImport == 1 && !CppCode.GetEOWzd().UpdateQuery())
			{
				MMMessageBox.Show($"{WpfMMDialogResources.EoVariableMsg1} {CppCode.GetEOWzd().m_strQueryFile}!", WpfMMDialogResources.DlgTitle);
				WizardContainer container = base.Container;
				bool flag = (base.Container.CanNext = false);
				bool flag3 = (container.CanFinish = flag);
				bool canNext = (base.CanFinish = flag3);
				base.CanNext = canNext;
				return false;
			}
			if (CppCode.GetEOWzd().m_nImport == 0 && CppCode.GetEOWzd().UpdateQuery() && MMMessageBox.Show($"{CppCode.GetEOWzd().m_strQueryFile} {WpfMMDialogResources.EoVariableMsg2}", WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Exclamation) == MMMessageBoxResult.Cancel)
			{
				return false;
			}
			return true;
		}

		public override bool DoFinish()
		{
			if (!IsFilePathValid())
			{
				return false;
			}
			AddFileExtension();
			if (CppCode.GetEOWzd().m_nImport == 0 && CppCode.GetEOWzd().UpdateQuery() && MMMessageBox.Show($"{CppCode.GetEOWzd().m_strQueryFile} {WpfMMDialogResources.EoVariableMsg2}", WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Exclamation) == MMMessageBoxResult.Cancel)
			{
				return false;
			}
			return CppCode.OnFinish();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/eoexportfile.xaml", UriKind.Relative);
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
			_contentLoaded = true;
		}
	}
	public class EOExportMask : WizardPage, IComponentConnector
	{
		internal new System.Windows.Controls.CheckBox Name;

		internal System.Windows.Controls.CheckBox Units;

		internal System.Windows.Controls.CheckBox Value;

		internal System.Windows.Controls.CheckBox PhysicalType;

		internal System.Windows.Controls.CheckBox LowerBound;

		internal System.Windows.Controls.CheckBox SpecType;

		internal System.Windows.Controls.CheckBox UpperBound;

		internal System.Windows.Controls.CheckBox SimpleSpec;

		internal System.Windows.Controls.CheckBox Resolved_LB;

		internal System.Windows.Controls.CheckBox StepBound;

		internal System.Windows.Controls.CheckBox Resolved_UB;

		internal System.Windows.Controls.CheckBox StepBoundWeight;

		internal System.Windows.Controls.CheckBox InitialValue;

		internal System.Windows.Controls.CheckBox ActiveBound;

		internal System.Windows.Controls.CheckBox Change;

		internal System.Windows.Controls.CheckBox ShadowPrice;

		internal System.Windows.Controls.CheckBox Scale;

		private bool _contentLoaded;

		public EOExportMaskM CppCode { get; set; }

		public EOExportMask(EOExportMaskM page)
		{
			InitializeComponent();
			base.CanNext = false;
			base.CanFinish = true;
			base.CanPrev = true;
			CppCode = page;
			base.DataContext = this;
		}

		private void CheckBox_Click(object sender, RoutedEventArgs e)
		{
			if ((base.Container as EOExportWzd).CppCode.m_nImport != 0 && CppCode.m_maskCode && MMMessageBox.Show(WpfMMDialogResources.ImportQuestion, WpfMMDialogResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Question) == MMMessageBoxResult.Cancel)
			{
				CppCode.m_maskCode = false;
			}
		}

		public override void OnShowing()
		{
			EOExportWzdM cppCode = (base.Container as EOExportWzd).CppCode;
			if (cppCode.m_nImport != 0)
			{
				PhysicalType.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_PHYSICAL_TYPE) != 0;
				CppCode.m_maskPType = false;
				LowerBound.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_LOWER) != 0;
				CppCode.m_maskLower = false;
				Value.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_VALUE) != 0;
				CppCode.m_maskValue = Value.IsEnabled;
				UpperBound.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_UPPER) != 0;
				CppCode.m_maskUpper = false;
				Scale.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_SCALE) != 0;
				CppCode.m_maskScale = false;
				Units.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_UOM) != 0;
				CppCode.m_maskUOM = false;
				SpecType.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_CODE) != 0;
				CppCode.m_maskCode = false;
				StepBound.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_STEP) != 0;
				CppCode.m_maskStep = false;
				StepBoundWeight.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_SBWEIGHT) != 0;
				CppCode.m_maskSBWeight = false;
				ShadowPrice.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_SHADOW) != 0;
				CppCode.m_maskShadow = false;
				ActiveBound.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_ACTIVE_BOUND) != 0;
				CppCode.m_maskAB = false;
				InitialValue.IsEnabled = (cppCode.m_lQueriedAttributes & VMask.VMASK_INIT) != 0;
				CppCode.m_maskInit = false;
				Change.IsEnabled = false;
				CppCode.m_maskChange = false;
				SimpleSpec.IsEnabled = false;
				CppCode.m_maskSSpec = false;
				Resolved_LB.IsEnabled = false;
				CppCode.m_maskRLower = false;
				Resolved_UB.IsEnabled = false;
				CppCode.m_maskRUpper = false;
			}
			else if (cppCode.pageFile.m_nXFile == 0)
			{
				ActiveBound.IsEnabled = true;
				SpecType.IsEnabled = true;
				LowerBound.IsEnabled = true;
				PhysicalType.IsEnabled = false;
				StepBoundWeight.IsEnabled = true;
				Scale.IsEnabled = true;
				ShadowPrice.IsEnabled = true;
				StepBound.IsEnabled = true;
				Units.IsEnabled = true;
				UpperBound.IsEnabled = true;
				Value.IsEnabled = true;
				Change.IsEnabled = false;
				InitialValue.IsEnabled = false;
				Resolved_LB.IsEnabled = false;
				Resolved_UB.IsEnabled = false;
				SimpleSpec.IsEnabled = false;
			}
			else
			{
				ActiveBound.IsEnabled = false;
				SpecType.IsEnabled = true;
				LowerBound.IsEnabled = true;
				PhysicalType.IsEnabled = false;
				StepBoundWeight.IsEnabled = true;
				Scale.IsEnabled = true;
				ShadowPrice.IsEnabled = false;
				StepBound.IsEnabled = true;
				Units.IsEnabled = true;
				UpperBound.IsEnabled = true;
				Value.IsEnabled = true;
				Change.IsEnabled = true;
				InitialValue.IsEnabled = true;
				Resolved_LB.IsEnabled = true;
				Resolved_UB.IsEnabled = true;
				SimpleSpec.IsEnabled = true;
			}
		}

		public override bool DoFinish()
		{
			return CppCode.OnFinish();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/eoexportmask.xaml", UriKind.Relative);
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
				Name = (System.Windows.Controls.CheckBox)target;
				break;
			case 2:
				Units = (System.Windows.Controls.CheckBox)target;
				break;
			case 3:
				Value = (System.Windows.Controls.CheckBox)target;
				break;
			case 4:
				PhysicalType = (System.Windows.Controls.CheckBox)target;
				break;
			case 5:
				LowerBound = (System.Windows.Controls.CheckBox)target;
				break;
			case 6:
				SpecType = (System.Windows.Controls.CheckBox)target;
				SpecType.Click += CheckBox_Click;
				break;
			case 7:
				UpperBound = (System.Windows.Controls.CheckBox)target;
				break;
			case 8:
				SimpleSpec = (System.Windows.Controls.CheckBox)target;
				break;
			case 9:
				Resolved_LB = (System.Windows.Controls.CheckBox)target;
				break;
			case 10:
				StepBound = (System.Windows.Controls.CheckBox)target;
				break;
			case 11:
				Resolved_UB = (System.Windows.Controls.CheckBox)target;
				break;
			case 12:
				StepBoundWeight = (System.Windows.Controls.CheckBox)target;
				break;
			case 13:
				InitialValue = (System.Windows.Controls.CheckBox)target;
				break;
			case 14:
				ActiveBound = (System.Windows.Controls.CheckBox)target;
				break;
			case 15:
				Change = (System.Windows.Controls.CheckBox)target;
				break;
			case 16:
				ShadowPrice = (System.Windows.Controls.CheckBox)target;
				break;
			case 17:
				Scale = (System.Windows.Controls.CheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class EOExportWzd : WizardContainer
	{
		public EOExportWzdM CppCode { get; set; }

		public EOExportFile pageFile { get; set; }

		public EOExportMask pageMask { get; set; }

		public ImportFromPage pageFrom { get; set; }

		public EOExportWzd(string caption, string obj, int local, int import, int hier)
		{
			CppCode = new EOExportWzdM(caption, obj, local, import, hier);
			pageFile = new EOExportFile(CppCode.pageFile);
			AddPage(pageFile);
			if (import != 0)
			{
				pageFrom = new ImportFromPage(CppCode.pageFrom);
				AddPage(pageFrom);
			}
			pageMask = new EOExportMask(CppCode.pageMask);
			AddPage(pageMask);
			if (import != 0)
			{
				pageFile.Title = WpfMMDialogResources.PageFile_ImportTitle;
				pageFrom.Title = WpfMMDialogResources.PageFrom_ImportTitle;
				pageMask.Title = WpfMMDialogResources.PageMask_ImportTitle;
			}
			else
			{
				pageFile.Title = WpfMMDialogResources.PageFile_ExportTitle;
				pageMask.Title = WpfMMDialogResources.PageMask_ExportTitle;
			}
		}
	}
	public class MoveToItemImageConvert : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append("pack://application:,,,/");
			stringBuilder.Append(typeof(EOExportWzd).Assembly.FullName);
			stringBuilder.Append(";component/Images/");
			stringBuilder.Append(value as string);
			return new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class ImportFromPage : WizardPage, IComponentConnector
	{
		internal System.Windows.Controls.CheckBox cbRestore;

		private bool _contentLoaded;

		public ImportFromPageM CppCode { get; set; }

		public ImportFromPage(ImportFromPageM page)
		{
			InitializeComponent();
			base.CanNext = true;
			base.CanFinish = true;
			base.CanPrev = true;
			CppCode = page;
			base.DataContext = this;
		}

		private void TreeViewSelectedItemChanged(object sender, RoutedEventArgs e)
		{
			if (!((sender as System.Windows.Controls.TreeView).SelectedItem is TreeItem treeItem) || treeItem.Name == CppCode.GetEOWzd().pageFile.m_strFilename)
			{
				bool canFinish = (base.CanNext = true);
				base.CanFinish = canFinish;
				CppCode.m_strSelected = "root";
				WizardContainer container = base.Container;
				canFinish = (base.Container.CanNext = true);
				container.CanFinish = canFinish;
				return;
			}
			int count = treeItem.Children.Count;
			if ((count > 0 && CppCode.m_nHier == 1) || (count == 0 && CppCode.m_nHier == 0))
			{
				bool canFinish = (base.CanNext = true);
				base.CanFinish = canFinish;
				WizardContainer container2 = base.Container;
				canFinish = (base.Container.CanNext = true);
				container2.CanFinish = canFinish;
				CppCode.m_strSelected = treeItem.Tag.Remove(treeItem.Tag.LastIndexOf('.'), 5);
			}
			else
			{
				bool canFinish = (base.CanNext = false);
				base.CanFinish = canFinish;
				WizardContainer container3 = base.Container;
				canFinish = (base.Container.CanNext = false);
				container3.CanFinish = canFinish;
			}
		}

		public override void OnShowing()
		{
			if ((base.Container as EOExportWzd).CppCode.m_nHier != 0)
			{
				CppCode.m_strPrompt = WpfMMDialogResources.EoVariableMsg3;
				CppCode.m_nHier = 1;
			}
			else
			{
				CppCode.m_strPrompt = WpfMMDialogResources.EoVariableMsg4;
				CppCode.m_nHier = 0;
			}
			CppCode.OnShow();
		}

		public override bool DoFinish()
		{
			if (cbRestore.IsChecked == true)
			{
				CppCode.m_Restore = true;
			}
			else
			{
				CppCode.m_Restore = false;
			}
			return CppCode.OnFinish();
		}

		public override bool DoNext()
		{
			if (cbRestore.IsChecked == true)
			{
				CppCode.m_Restore = true;
			}
			else
			{
				CppCode.m_Restore = false;
			}
			return true;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/importfrompage.xaml", UriKind.Relative);
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
				((System.Windows.Controls.TreeView)target).SelectedItemChanged += TreeViewSelectedItemChanged;
				break;
			case 2:
				cbRestore = (System.Windows.Controls.CheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ComVisible(true)]
	[Guid("C52B3E82-9EE5-432E-92A2-F3F0319DBA2F")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IMMLogger
	{
		void Log(string message, int category, int priority);
	}
	[ComVisible(true)]
	[Guid("6FB72A3B-15A3-4E1C-AC13-EB5F21E000FD")]
	[ProgId("AspenTech.AspenPlus.MMLogger.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class MMLogger : IMMLogger
	{
		[DispId(1)]
		public void Log(string message, int category, int priority)
		{
			Category category2 = Category.Debug;
			Priority priority2 = Priority.None;
			if (Enum.IsDefined(typeof(Category), category))
			{
				category2 = (Category)category;
			}
			if (Enum.IsDefined(typeof(Priority), priority))
			{
				priority2 = (Priority)priority;
			}
			SystemEnvironment.Logger.Log(message, category2, priority2);
		}
	}
	public class ResultsInconsistentDlg : MMDialog, IComponentConnector
	{
		private const int GWL_STYLE = -16;

		private const int WS_SYSMENU = 524288;

		private int _result = -1;

		internal Grid buttonsPanel;

		internal System.Windows.Controls.Button btnRun;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		[DllImport("user32.dll", SetLastError = true)]
		private static extern IntPtr GetWindowLongPtr(IntPtr hwnd, int nIndex);

		[DllImport("user32.dll")]
		private static extern IntPtr SetWindowLongPtr(IntPtr hwnd, int index, IntPtr value);

		public ResultsInconsistentDlg()
		{
			InitializeComponent();
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			IntPtr handle = new WindowInteropHelper(this).Handle;
			if (handle != IntPtr.Zero)
			{
				long num = GetWindowLongPtr(handle, -16).ToInt64();
				SetWindowLongPtr(handle, -16, new IntPtr(num & -524289));
			}
		}

		public static int ShowDlg()
		{
			ResultsInconsistentDlg msg = null;
			DispatcherOperation dispatcherOperation = System.Windows.Application.Current.Dispatcher.BeginInvoke((Func<int>)delegate
			{
				msg = new ResultsInconsistentDlg();
				msg.Title = MMVersionHelper.MVGetI18nProductNameM();
				msg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
				Mouse.OverrideCursor = null;
				msg.ShowDialog();
				Mouse.OverrideCursor = overrideCursor;
				return msg._result;
			});
			dispatcherOperation.Wait();
			if (dispatcherOperation.Status == DispatcherOperationStatus.Completed)
			{
				return (dispatcherOperation.Result as int?) ?? (-1);
			}
			return -1;
		}

		private void btnRun_Click(object sender, RoutedEventArgs e)
		{
			_result = 1;
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			_result = 0;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/resultsinconsistentdlg.xaml", UriKind.Relative);
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
				buttonsPanel = (Grid)target;
				break;
			case 2:
				btnRun = (System.Windows.Controls.Button)target;
				btnRun.Click += btnRun_Click;
				break;
			case 3:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class TPSARUpgradeDlg : Window, IComponentConnector
	{
		internal System.Windows.Controls.CheckBox chkDoNotAsk;

		internal System.Windows.Controls.Button btnMoreInfo;

		internal System.Windows.Controls.Button btnUpgrade;

		internal System.Windows.Controls.Button btnNotUpgrade;

		private bool _contentLoaded;

		[DefaultValue(0)]
		public int ReturnCode { get; private set; }

		[DefaultValue(0)]
		public int DoNotAskAgain { get; private set; }

		public TPSARUpgradeDlg()
		{
			InitializeComponent();
			base.Closed += TPSARUpgradeDlg_Closed;
		}

		private void TPSARUpgradeDlg_Closed(object sender, EventArgs e)
		{
			if (chkDoNotAsk.IsChecked ?? false)
			{
				DoNotAskAgain = 1;
			}
			else
			{
				DoNotAskAgain = 0;
			}
		}

		private void btnUpgrade_Click(object sender, RoutedEventArgs e)
		{
			ReturnCode = 1;
			Close();
		}

		private void btnNotUpgrade_Click(object sender, RoutedEventArgs e)
		{
			ReturnCode = 0;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/tpsarupgradedlg.xaml", UriKind.Relative);
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
				chkDoNotAsk = (System.Windows.Controls.CheckBox)target;
				break;
			case 2:
				btnMoreInfo = (System.Windows.Controls.Button)target;
				break;
			case 3:
				btnUpgrade = (System.Windows.Controls.Button)target;
				btnUpgrade.Click += btnUpgrade_Click;
				break;
			case 4:
				btnNotUpgrade = (System.Windows.Controls.Button)target;
				btnNotUpgrade.Click += btnNotUpgrade_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class WizardContainer : Window, IComponentConnector
	{
		public static readonly DependencyProperty CanPrevProperty = DependencyProperty.Register("CanPrev", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));

		public static readonly DependencyProperty CanNextProperty = DependencyProperty.Register("CanNext", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));

		public static readonly DependencyProperty CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));

		public static readonly DependencyProperty ContainerParentProperty = DependencyProperty.Register("ContainerParent", typeof(UIElement), typeof(WizardContainer), new PropertyMetadata(null));

		private int currentPage;

		private ObservableCollection<WizardPage> PageCollection = new ObservableCollection<WizardPage>();

		private WizardPage _current;

		internal WizardContainer ctrlWizard;

		internal ContentControl WizardContent;

		internal System.Windows.Controls.Button btnPrev;

		internal System.Windows.Controls.Button btnNext;

		internal System.Windows.Controls.Button btnFinish;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public bool CanPrev
		{
			get
			{
				return (bool)GetValue(CanPrevProperty);
			}
			set
			{
				SetValue(CanPrevProperty, value);
			}
		}

		public bool CanNext
		{
			get
			{
				return (bool)GetValue(CanNextProperty);
			}
			set
			{
				SetValue(CanNextProperty, value);
			}
		}

		public bool CanFinish
		{
			get
			{
				return (bool)GetValue(CanFinishProperty);
			}
			set
			{
				SetValue(CanFinishProperty, value);
			}
		}

		public UIElement ContainerParent
		{
			get
			{
				return (UIElement)GetValue(ContainerParentProperty);
			}
			set
			{
				SetValue(ContainerParentProperty, value);
			}
		}

		public WizardPage current
		{
			get
			{
				return _current;
			}
			set
			{
				if (_current != value)
				{
					_current = value;
				}
			}
		}

		public void AddPage(WizardPage page)
		{
			if (current == null)
			{
				current = page;
				CanNext = current.CanNext;
				CanFinish = current.CanFinish;
			}
			page.ContainerParent = ContainerParent;
			page.Container = this;
			PageCollection.Add(page);
		}

		public WizardPage GetPage(int nIndex)
		{
			if (PageCollection != null && PageCollection.Count > 0 && PageCollection.Count > nIndex)
			{
				return PageCollection[nIndex];
			}
			return null;
		}

		public WizardContainer()
		{
			InitializeComponent();
			base.DataContext = this;
			base.Loaded += delegate
			{
				WizardContent.Content = GetPage(0);
			};
		}

		private void UpDateStatus(int nIndex)
		{
			if (nIndex >= 0 && nIndex < PageCollection.Count)
			{
				ContentControl wizardContent = WizardContent;
				WizardPage content = (current = GetPage(nIndex));
				wizardContent.Content = content;
				current.OnShowing();
				base.Title = current.Title;
				CanPrev = current.CanPrev;
				CanNext = current.CanNext;
				CanFinish = current.CanFinish;
			}
		}

		private void btnPrev_Click(object sender, RoutedEventArgs e)
		{
			UpDateStatus(--currentPage);
		}

		private void btnNext_Click(object sender, RoutedEventArgs e)
		{
			if (current.DoNext())
			{
				UpDateStatus(++currentPage);
			}
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		private void btnFinish_Click(object sender, RoutedEventArgs e)
		{
			current.DoFinish();
			base.DialogResult = true;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/wizardcontainer.xaml", UriKind.Relative);
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
				ctrlWizard = (WizardContainer)target;
				break;
			case 2:
				WizardContent = (ContentControl)target;
				break;
			case 3:
				btnPrev = (System.Windows.Controls.Button)target;
				btnPrev.Click += btnPrev_Click;
				break;
			case 4:
				btnNext = (System.Windows.Controls.Button)target;
				btnNext.Click += btnNext_Click;
				break;
			case 5:
				btnFinish = (System.Windows.Controls.Button)target;
				btnFinish.Click += btnFinish_Click;
				break;
			case 6:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class WizardPage : System.Windows.Controls.UserControl
	{
		public static readonly DependencyProperty CanNextProperty = DependencyProperty.Register("CanNext", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));

		public static readonly DependencyProperty CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));

		public static readonly DependencyProperty CanPrevProperty = DependencyProperty.Register("CanPrev", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));

		public static readonly DependencyProperty ContainerParentProperty = DependencyProperty.Register("ContainerParent", typeof(UIElement), typeof(WizardPage), new PropertyMetadata(null));

		public static readonly DependencyProperty ContainerProperty = DependencyProperty.Register("Container", typeof(WizardContainer), typeof(WizardPage), new PropertyMetadata(null));

		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(WizardPage), new PropertyMetadata(null));

		public bool CanNext
		{
			get
			{
				return (bool)GetValue(CanNextProperty);
			}
			set
			{
				SetValue(CanNextProperty, value);
			}
		}

		public bool CanFinish
		{
			get
			{
				return (bool)GetValue(CanFinishProperty);
			}
			set
			{
				SetValue(CanFinishProperty, value);
			}
		}

		public bool CanPrev
		{
			get
			{
				return (bool)GetValue(CanPrevProperty);
			}
			set
			{
				SetValue(CanPrevProperty, value);
			}
		}

		public UIElement ContainerParent
		{
			get
			{
				return (UIElement)GetValue(ContainerParentProperty);
			}
			set
			{
				SetValue(ContainerParentProperty, value);
			}
		}

		public WizardContainer Container
		{
			get
			{
				return (WizardContainer)GetValue(ContainerProperty);
			}
			set
			{
				SetValue(ContainerProperty, value);
			}
		}

		public string Title
		{
			get
			{
				return (string)GetValue(TitleProperty);
			}
			set
			{
				SetValue(TitleProperty, value);
			}
		}

		public virtual void OnShowing()
		{
		}

		public virtual bool DoNext()
		{
			return false;
		}

		public virtual bool DoFinish()
		{
			return false;
		}
	}
	public class HierImportDlg : MMDialog, IComponentConnector
	{
		private bool m_bClear;

		private bool m_bGlobalReplace;

		internal System.Windows.Controls.Button BtnContinue;

		internal System.Windows.Controls.Button BtnAbort;

		internal System.Windows.Controls.Button BtnHelp;

		private bool _contentLoaded;

		public string HelpFile => "userguide1.chm";

		public bool BoolClear
		{
			get
			{
				return m_bClear;
			}
			set
			{
				m_bClear = value;
			}
		}

		public bool BoolGlobalReplace
		{
			get
			{
				return m_bGlobalReplace;
			}
			set
			{
				m_bGlobalReplace = value;
			}
		}

		public HierImportDlg()
		{
			InitializeComponent();
		}

		protected void OnButtonClickBtnContinue(object sender, RoutedEventArgs args)
		{
			base.DialogResult = true;
			Close();
		}

		protected void OnButtonClickBtnAbort(object sender, RoutedEventArgs args)
		{
			base.DialogResult = false;
			Close();
		}

		protected void OnButtonClickBtnHelp(object sender, RoutedEventArgs args)
		{
		}

		protected void ChkClear_OnChecked(object sender, RoutedEventArgs args)
		{
			if ((sender as System.Windows.Controls.CheckBox).IsChecked == true)
			{
				m_bClear = true;
			}
			else
			{
				m_bClear = false;
			}
		}

		protected void ChkGlobalReplace_OnChecked(object sender, RoutedEventArgs args)
		{
			if ((sender as System.Windows.Controls.CheckBox).IsChecked == true)
			{
				m_bGlobalReplace = true;
			}
			else
			{
				m_bGlobalReplace = false;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/hierimportdlg.xaml", UriKind.Relative);
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
				((System.Windows.Controls.CheckBox)target).Checked += ChkClear_OnChecked;
				((System.Windows.Controls.CheckBox)target).Unchecked += ChkClear_OnChecked;
				break;
			case 2:
				((System.Windows.Controls.CheckBox)target).Checked += ChkGlobalReplace_OnChecked;
				((System.Windows.Controls.CheckBox)target).Unchecked += ChkGlobalReplace_OnChecked;
				break;
			case 3:
				BtnContinue = (System.Windows.Controls.Button)target;
				BtnContinue.Click += OnButtonClickBtnContinue;
				break;
			case 4:
				BtnAbort = (System.Windows.Controls.Button)target;
				BtnAbort.Click += OnButtonClickBtnAbort;
				break;
			case 5:
				BtnHelp = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class IDBoxDlg : MMDialog, INotifyPropertyChanged, IComponentConnector
	{
		public enum IDType
		{
			UnDefine = -1,
			ID,
			Prefix,
			Suffix
		}

		private IDType _idtype;

		private bool _bMHeatX;

		internal IDBoxDlg root;

		internal System.Windows.Controls.Label promptLabel;

		internal System.Windows.Controls.TextBox editBox;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public string Prompt
		{
			get
			{
				return promptLabel.Content.ToString();
			}
			set
			{
				promptLabel.Content = value;
			}
		}

		public int MaxLength
		{
			get
			{
				return editBox.MaxLength;
			}
			set
			{
				int num = value;
				if (num < 0)
				{
					num = 0;
				}
				editBox.MaxLength = num;
			}
		}

		public string ID
		{
			get
			{
				return editBox.Text;
			}
			set
			{
				editBox.Text = value;
			}
		}

		public bool IsOKEnable => editBox.Text.Length > 0;

		public event PropertyChangedEventHandler PropertyChanged;

		public IDBoxDlg(string title, string prompt, IDType type, int maxLength = 0)
		{
			InitializeComponent();
			Prompt = prompt;
			base.Title = title;
			MaxLength = maxLength;
			_idtype = type;
		}

		public IDBoxDlg(string title, string prompt, IDType type, bool bMHeatX, int maxLength = 0)
		{
			InitializeComponent();
			Prompt = prompt;
			base.Title = title;
			MaxLength = maxLength;
			_idtype = type;
			_bMHeatX = bMHeatX;
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			string errorDescription;
			if (_idtype == IDType.UnDefine)
			{
				base.DialogResult = true;
				Close();
			}
			else if (IDHelper.ValidateID(ID, (int)_idtype, _bMHeatX, out errorDescription))
			{
				base.DialogResult = true;
				Close();
			}
			else if (errorDescription != null)
			{
				MMMessageBox.Show(this, errorDescription, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Error);
			}
		}

		private void editBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("IsOKEnable"));
			}
		}

		private void DlgBox_Loaded(object sender, RoutedEventArgs e)
		{
			editBox.Focus();
		}

		private void editBox_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			int length = editBox.Text.Length;
			_ = editBox.Text;
			if (string.IsNullOrEmpty(e.Text))
			{
				e.Handled = true;
				return;
			}
			char c = e.Text[0];
			if (length == 0 && !char.IsLetterOrDigit(c) && c != '\r' && c != '\b')
			{
				e.Handled = true;
			}
			else if (length > 0 && !char.IsLetterOrDigit(c) && c != '$' && c != ',' && c != ':' && c != '+' && c != '-' && c != ';' && c != '/' && c != '=' && c != '*' && c != '.' && c != '&' && c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}' && c != '<' && c != '>' && c != '\r' && c != '\b')
			{
				e.Handled = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/idboxdlg.xaml", UriKind.Relative);
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
				root = (IDBoxDlg)target;
				break;
			case 2:
				promptLabel = (System.Windows.Controls.Label)target;
				break;
			case 3:
				editBox = (System.Windows.Controls.TextBox)target;
				editBox.TextChanged += editBox_TextChanged;
				editBox.PreviewTextInput += editBox_PreviewTextInput;
				break;
			case 4:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 5:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class IDBoxDlg2 : Window, INotifyPropertyChanged, IComponentConnector
	{
		private string _strNewName = "";

		internal System.Windows.Controls.Button BtnOk;

		internal System.Windows.Controls.Button BtnCancel;

		private bool _contentLoaded;

		public string NewName
		{
			get
			{
				return _strNewName;
			}
			set
			{
				if (_strNewName != value)
				{
					_strNewName = value;
					OnPropertyChanged("NewName");
				}
			}
		}

		public string HelpFile => "apeoref.chm";

		public event PropertyChangedEventHandler PropertyChanged;

		public IDBoxDlg2(string curname)
		{
			InitializeComponent();
			base.Loaded += IDBoxDlg2_Loaded;
			NewName = curname;
		}

		private void IDBoxDlg2_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
		}

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		private void BtnOk_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
		}

		private void BtnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/idboxdlg2.xaml", UriKind.Relative);
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
				BtnOk = (System.Windows.Controls.Button)target;
				BtnOk.Click += BtnOk_Click;
				break;
			case 2:
				BtnCancel = (System.Windows.Controls.Button)target;
				BtnCancel.Click += BtnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MarkBoxDlg : MMDialog, IComponentConnector
	{
		internal System.Windows.Controls.ListView lvMarklist;

		internal System.Windows.Controls.Button btnDependencies;

		internal System.Windows.Controls.Button btnReferences;

		internal System.Windows.Controls.Button btnUndo;

		internal System.Windows.Controls.Button btnRemove;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public MarkBoxDlg()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/markboxdlg.xaml", UriKind.Relative);
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
				lvMarklist = (System.Windows.Controls.ListView)target;
				break;
			case 2:
				btnDependencies = (System.Windows.Controls.Button)target;
				break;
			case 3:
				btnReferences = (System.Windows.Controls.Button)target;
				break;
			case 4:
				btnUndo = (System.Windows.Controls.Button)target;
				break;
			case 5:
				btnRemove = (System.Windows.Controls.Button)target;
				break;
			case 6:
				btnOK = (System.Windows.Controls.Button)target;
				break;
			case 7:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ComVisible(true)]
	[Guid("7213EE9F-9189-447E-9391-2EE1D5685827")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IMessageBox
	{
		int Show(string contents, string caption, int helpid, int buttons);

		int Show(string contents, string caption, int helpid, int buttons, int image);

		int Show(string contents, string caption, int helpid, int buttons, int image, int defaultResults);

		int ShowOpenMessageBox(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, int nCancelButton);

		int ShowOpenMessageBoxWithCheckBox(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, ref int checkbox, int nCancelButton);

		int ShowAlsoSaveAsDialog(out int showCheckbox);

		int ShowSaveApwzDialog(out int showCheckbox);
	}
	[ComVisible(true)]
	[Guid("81ECE899-F346-4D06-8656-C3AB26266A5C")]
	[ProgId("AspenTech.AspenPlus.WpfMMDialog.MessageBox.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class MessageBox : IMessageBox
	{
		public int Show(string contents, string caption, int helpid, int buttons)
		{
			return (int)MMMessageBox.Show(contents, caption, (MMMessageBoxButton)buttons);
		}

		public int Show(string contents, string caption, int helpid, int buttons, int image)
		{
			return (int)MMMessageBox.Show(contents, caption, (MMMessageBoxButton)buttons, (MMMessageBoxImage)image);
		}

		public int Show(string contents, string caption, int helpid, int buttons, int image, int defaultResults)
		{
			return (int)MMMessageBox.Show(contents, caption, (MMMessageBoxButton)buttons, (MMMessageBoxImage)image, showHelpButton: false, defaultResults);
		}

		public int ShowOpenMessageBox(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, int nCancelButton)
		{
			int checkbox = 0;
			return OpenMessageBox.Show(szCaption, szMsg, szBtn1, szBtn2, szBtn3, szBtn4, szHelp, nDefButton, ref checkbox, nCancelButton);
		}

		public int ShowOpenMessageBoxWithCheckBox(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, ref int checkbox, int nCancelButton)
		{
			return OpenMessageBox.Show(szCaption, szMsg, szBtn1, szBtn2, szBtn3, szBtn4, szHelp, nDefButton, ref checkbox, nCancelButton);
		}

		public int ShowAlsoSaveAsDialog(out int showCheckbox)
		{
			showCheckbox = 1;
			return OpenMessageBox.Show(MMVersionHelper.MVGetI18nProductNameM(), WpfMMDialogResources.AlsoSaveAsDialogText, WpfMMDialogResources._Yes, WpfMMDialogResources._No, WpfMMDialogResources._Cancel, "", "", 1, ref showCheckbox) switch
			{
				1 => 6, 
				2 => 7, 
				_ => 2, 
			};
		}

		public int ShowSaveApwzDialog(out int showCheckbox)
		{
			showCheckbox = 1;
			return OpenMessageBox.Show(MMVersionHelper.MVGetI18nProductNameM(), WpfMMDialogResources.SaveApwzDialogText, WpfMMDialogResources._Yes, WpfMMDialogResources._No, WpfMMDialogResources._Cancel, "", "", 1, ref showCheckbox) switch
			{
				1 => 6, 
				2 => 7, 
				_ => 2, 
			};
		}
	}
	[ComVisible(true)]
	[Guid("6367840E-0FAE-464E-9870-DD829BCC6C63")]
	public interface IMessageBoxEx
	{
		int Show(long hwnd, string text, string caption, int nType);

		int ShowEx(long hwnd, string text, string caption, int nType, int nImage);
	}
	[ComVisible(true)]
	[Guid("F1B7A80D-7EAA-45BD-96D8-61693BBBAD94")]
	[ProgId("AspenTech.AspenPlus.WpfMMDialog.MessageBoxEx.410")]
	public class MessageBoxEx : MMDialog, IMessageBoxEx
	{
		private Window _onwerWnd;

		private string _text;

		private string _caption;

		private int _type;

		private int _image;

		public int Show(long _hwnd, string text, string caption, int nType)
		{
			IntPtr intPtr = new IntPtr(_hwnd);
			if (intPtr != IntPtr.Zero)
			{
				new WindowInteropHelper(_onwerWnd).Owner = intPtr;
			}
			_text = text;
			_caption = caption;
			_type = nType;
			base.DefaultMessage = text;
			return (int)MMMessageBox.Show(_onwerWnd, base.DefaultMessage, _caption, (MMMessageBoxButton)_type, MMMessageBoxImage.None, showHelpButton: true);
		}

		public int ShowEx(long _hwnd, string text, string caption, int nType, int nImage)
		{
			IntPtr intPtr = new IntPtr(_hwnd);
			if (intPtr != IntPtr.Zero)
			{
				new WindowInteropHelper(_onwerWnd).Owner = intPtr;
			}
			_text = text;
			_caption = caption;
			_type = nType;
			_image = nImage;
			base.DefaultMessage = text;
			return (int)MMMessageBox.Show(_onwerWnd, base.DefaultMessage, _caption, (MMMessageBoxButton)_type, (MMMessageBoxImage)_image);
		}
	}
	public class MMDialog : Window
	{
		public int AutoDefault { get; set; }

		public string DefaultMessage { get; set; }

		public string ButtonText { get; set; }

		protected virtual void InitSuppressed()
		{
		}

		public MMDialog()
		{
			AutoDefault = 0;
			DefaultMessage = "Suppressed Dialog";
			ButtonText = "";
		}

		public virtual int ShowMMDialog()
		{
			if (MmgSor.MMGetSuppressM() == 0)
			{
				bool? flag = ShowDialog();
				if (!flag.HasValue || !flag.Value)
				{
					return 0;
				}
				return 1;
			}
			InitSuppressed();
			return AutoDefault;
		}
	}
	public static class MmgDll
	{
		public struct symbol
		{
			public int val;

			public int ext;
		}

		public struct paste_item
		{
			public int type;

			public int size;

			public IntPtr next;

			public int selected;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 112)]
			public string path_name;

			public int level;

			public int canparam;

			public int couldparam;

			public int paramno;

			public int paramloc;

			public int deleted;

			public int comp;

			public byte paramsel;

			public byte paramshow;

			public byte depid;

			public byte reveal;

			public int XLHandle;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
			public string usename;

			public symbol symbol;

			public int action;

			public int hierinvalid;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 74)]
			public string hiername;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
			public string iconname;

			public IntPtr child;

			public IntPtr parent;
		}

		public struct conbuf
		{
			public IntPtr next;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 140)]
			public string buf1;

			public int newidlen;

			public int selected;

			public int mergeok;

			[MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
			public string newusename;

			public IntPtr item;

			public IntPtr olditem;

			public int defaction;
		}

		[DllImport("..\\..\\AprSystem\\xeqd\\mmg.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int HYinmove();

		[DllImport("..\\..\\AprSystem\\xeqd\\mmg.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
		public static extern int ICgetcon(ref IntPtr conflict_buf_ptr, ref IntPtr next_buf_ptr);
	}
	public class MoveToDlg : Window, INotifyPropertyChanged, IComponentConnector
	{
		private IntPtr _ptrIaModel = IntPtr.Zero;

		private IntPtr _ptrAdvanced = IntPtr.Zero;

		private ObservableCollection<HierarchyTreeViewItemViewModel> m_TreeViewRootNodes = new ObservableCollection<HierarchyTreeViewItemViewModel>();

		private string _strRootHier;

		private string _strNodeValue = "";

		private int _nRadioSelected = 1;

		private bool _bCanEnableRadio2 = true;

		private Visibility _visibilityRadio3;

		private Visibility _visibilityCheckBox;

		private bool _isCheckBoxChecked;

		internal System.Windows.Controls.Button button1;

		internal System.Windows.Controls.Button button2;

		internal System.Windows.Controls.RadioButton Rd1;

		internal System.Windows.Controls.TextBox text1;

		internal System.Windows.Controls.RadioButton Rd2;

		internal System.Windows.Controls.ComboBox Combox1;

		internal System.Windows.Controls.TreeView tree1;

		internal System.Windows.Controls.RadioButton Rd3;

		internal System.Windows.Controls.CheckBox check1;

		private bool _contentLoaded;

		public ObservableCollection<HierarchyTreeViewItemViewModel> RootNodes
		{
			get
			{
				return m_TreeViewRootNodes;
			}
			set
			{
				m_TreeViewRootNodes = value;
			}
		}

		public string StrNodeValue
		{
			get
			{
				return _strNodeValue;
			}
			set
			{
				if (_strNodeValue != value)
				{
					_strNodeValue = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("StrNodeValue"));
					}
				}
			}
		}

		public int NRadioSelected
		{
			get
			{
				return _nRadioSelected;
			}
			set
			{
				if (_nRadioSelected != value)
				{
					_nRadioSelected = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("NRadioSelected"));
						this.PropertyChanged(this, new PropertyChangedEventArgs("IsCheckBoxEnable"));
					}
				}
			}
		}

		public bool BCanEnableRadio2
		{
			get
			{
				return _bCanEnableRadio2;
			}
			set
			{
				if (_bCanEnableRadio2 != value)
				{
					_bCanEnableRadio2 = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("BCanEnableRadio2"));
					}
				}
			}
		}

		public Visibility VisibilityRadio3
		{
			get
			{
				return _visibilityRadio3;
			}
			set
			{
				if (_visibilityRadio3 != value)
				{
					_visibilityRadio3 = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("VisibilityRadio3"));
					}
				}
			}
		}

		public bool IsCheckBoxEnable
		{
			get
			{
				if (NRadioSelected == 2)
				{
					return false;
				}
				return true;
			}
		}

		public Visibility VisibilityCheckBox
		{
			get
			{
				return _visibilityCheckBox;
			}
			set
			{
				if (_visibilityCheckBox != value)
				{
					_visibilityCheckBox = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("VisibilityCheckBox"));
					}
				}
			}
		}

		public bool IsCheckBoxChecked
		{
			get
			{
				return _isCheckBoxChecked;
			}
			set
			{
				if (_isCheckBoxChecked != value)
				{
					_isCheckBoxChecked = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("IsCheckBoxChecked"));
					}
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public MoveToDlg()
		{
			InitializeComponent();
			base.Loaded += MoveToDlg_Loaded;
		}

		private void MoveToDlg_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
		}

		public MoveToDlg(string name, IntPtr ptrIaModel, bool bCanExplode, IntPtr ptrAdvanced, int eProcType)
		{
			_strRootHier = name;
			if (_strRootHier == null || _strRootHier == "")
			{
				_strRootHier = "Plant";
			}
			StrNodeValue = MMPFSHelper.GetMoveToNodeValue(ptrIaModel);
			bool bCheck = false;
			if (MMPFSHelper.GetMoveToCheckBoxStatus(ptrAdvanced, out bCheck))
			{
				VisibilityCheckBox = Visibility.Visible;
				IsCheckBoxChecked = bCheck;
			}
			else
			{
				VisibilityCheckBox = Visibility.Collapsed;
			}
			if (bCanExplode)
			{
				VisibilityRadio3 = Visibility.Visible;
			}
			else
			{
				VisibilityRadio3 = Visibility.Collapsed;
			}
			List<string> list = MMPFSHelper.InitMoveToComboxItems(ptrIaModel, _strRootHier, eProcType);
			list.Remove("");
			GenerateTreeviewData(list);
			if (list == null || list.Count == 0)
			{
				BCanEnableRadio2 = false;
			}
			_ptrIaModel = ptrIaModel;
			_ptrAdvanced = ptrAdvanced;
			base.Loaded += MoveToDlg_Loaded;
			InitializeComponent();
		}

		private void BtnOK_Click(object sender, RoutedEventArgs e)
		{
			if (NRadioSelected == 0)
			{
				if (tree1.SelectedValue is HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel)
				{
					_strNodeValue = hierarchyTreeViewItemViewModel.HierarchyID;
				}
				if (_strNodeValue == "Plant")
				{
					_strNodeValue = "";
				}
				MMPFSHelper.ChangeIntPtrContentValue(_ptrAdvanced, IsCheckBoxChecked);
				base.DialogResult = true;
			}
			else if (NRadioSelected == 1)
			{
				if (StrNodeValue == null || StrNodeValue == "")
				{
					MMMessageBox.Show(WpfMMDialogResources.StrMoveToTip, WpfMMDialogResources.StrMoveToCap, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					return;
				}
				if (MMPFSHelper.IsHierarchyExist(_ptrIaModel, StrNodeValue))
				{
					MMMessageBox.Show(WpfMMDialogResources.StrMoveToWarn, WpfMMDialogResources.StrMoveToCap, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					return;
				}
				MMPFSHelper.ChangeIntPtrContentValue(_ptrAdvanced, IsCheckBoxChecked);
				base.DialogResult = true;
			}
			else if (NRadioSelected == 2)
			{
				base.DialogResult = true;
			}
			else
			{
				base.DialogResult = false;
			}
		}

		private void TextBox_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
		{
			if ((e.Key < Key.A || e.Key > Key.Z) && (e.Key < Key.NumPad0 || e.Key > Key.NumPad9) && (e.Key < Key.D0 || e.Key > Key.D9) && e.Key != Key.Add && e.Key != Key.Subtract && e.Key != Key.OemPlus && (e.Key != Key.OemMinus || e.IsToggled) && e.Key != Key.OemComma && e.Key != Key.Oem4 && e.Key != Key.Oem1)
			{
				e.Handled = true;
			}
			else if ((sender as System.Windows.Controls.TextBox).Text.Length == 8)
			{
				e.Handled = true;
			}
		}

		private void OnComboBoxLoaded(object sender, RoutedEventArgs e)
		{
			(sender as System.Windows.Controls.ComboBox).IsDropDownOpen = true;
			(sender as System.Windows.Controls.ComboBox).IsDropDownOpen = false;
		}

		public void GenerateTreeviewData(List<string> lstHierarchies)
		{
			HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel = null;
			foreach (string lstHierarchy in lstHierarchies)
			{
				string[] array = lstHierarchy.Split('.');
				hierarchyTreeViewItemViewModel = GenerateRootNodes(array[0]);
				GenerateIterationNodes(hierarchyTreeViewItemViewModel, array);
			}
			if (RootNodes.Count > 0)
			{
				RootNodes[0].IsSelected = true;
			}
		}

		public HierarchyTreeViewItemViewModel GenerateRootNodes(string strName)
		{
			bool flag = false;
			HierarchyTreeViewItemViewModel result = null;
			foreach (HierarchyTreeViewItemViewModel rootNode in RootNodes)
			{
				if (rootNode.Name.CompareTo(strName) == 0)
				{
					flag = true;
					result = rootNode;
					break;
				}
			}
			if (!flag)
			{
				HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel = new HierarchyTreeViewItemViewModel(strName);
				m_TreeViewRootNodes.Add(hierarchyTreeViewItemViewModel);
				result = hierarchyTreeViewItemViewModel;
			}
			return result;
		}

		public void GenerateIterationNodes(HierarchyTreeViewItemViewModel tvmParent, string[] arrStrHierarchies)
		{
			if (tvmParent == null || arrStrHierarchies == null)
			{
				return;
			}
			HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel = tvmParent;
			int num = 0;
			int i = 1;
			num = arrStrHierarchies.Count();
			while (i < num)
			{
				HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel2 = FindNodeInChildren(hierarchyTreeViewItemViewModel, arrStrHierarchies[i]);
				if (hierarchyTreeViewItemViewModel2 == null)
				{
					for (; i < num; i++)
					{
						HierarchyTreeViewItemViewModel hierarchyTreeViewItemViewModel3 = new HierarchyTreeViewItemViewModel(arrStrHierarchies[i], hierarchyTreeViewItemViewModel);
						hierarchyTreeViewItemViewModel.Children.Add(hierarchyTreeViewItemViewModel3);
						hierarchyTreeViewItemViewModel = hierarchyTreeViewItemViewModel3;
					}
					break;
				}
				i++;
				hierarchyTreeViewItemViewModel = hierarchyTreeViewItemViewModel2;
			}
		}

		private HierarchyTreeViewItemViewModel FindNodeInChildren(HierarchyTreeViewItemViewModel tvmParent, string strName)
		{
			HierarchyTreeViewItemViewModel result = null;
			foreach (HierarchyTreeViewItemViewModel child in tvmParent.Children)
			{
				if (child.Name.CompareTo(strName) == 0)
				{
					result = child;
					break;
				}
			}
			return result;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/movetodlg.xaml", UriKind.Relative);
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
				button1 = (System.Windows.Controls.Button)target;
				button1.Click += BtnOK_Click;
				break;
			case 2:
				button2 = (System.Windows.Controls.Button)target;
				break;
			case 3:
				Rd1 = (System.Windows.Controls.RadioButton)target;
				break;
			case 4:
				text1 = (System.Windows.Controls.TextBox)target;
				text1.KeyDown += TextBox_KeyDown;
				break;
			case 5:
				Rd2 = (System.Windows.Controls.RadioButton)target;
				break;
			case 6:
				Combox1 = (System.Windows.Controls.ComboBox)target;
				Combox1.Loaded += OnComboBoxLoaded;
				break;
			case 7:
				tree1 = (System.Windows.Controls.TreeView)target;
				break;
			case 8:
				Rd3 = (System.Windows.Controls.RadioButton)target;
				break;
			case 9:
				check1 = (System.Windows.Controls.CheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ValueConversion(typeof(int), typeof(bool))]
	public class RadioBoolToIntConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return (int)value == int.Parse(parameter.ToString());
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return parameter;
		}
	}
	public class NameDialog : Window, IComponentConnector
	{
		private bool _contentLoaded;

		public NameDialog()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/namedialog.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	public class OpenMessageBox : MMDialog, INotifyPropertyChanged, IComponentConnector
	{
		private const int GWL_STYLE = -16;

		private const int WS_SYSMENU = 524288;

		private List<System.Windows.Controls.Button> btns = new List<System.Windows.Controls.Button>();

		private string[] _captions = new string[4] { "", "", "", "" };

		private int m_nDefButton;

		private int m_nCancelButton;

		private string m_csHelp = "";

		private int m_checkbox;

		private int _result = -1;

		public static SynchronizationContext _syncContext;

		internal TextBlock txtMessage;

		internal System.Windows.Controls.CheckBox chkDontshow;

		internal Grid buttonsPanel;

		internal System.Windows.Controls.Button btn0;

		internal System.Windows.Controls.Button btn1;

		internal System.Windows.Controls.Button btn2;

		internal System.Windows.Controls.Button btn3;

		private bool _contentLoaded;

		public string[] Captions
		{
			get
			{
				return _captions;
			}
			set
			{
				_captions = value;
				OnPropertyChanged("Captions");
				for (int i = 0; i < Captions.Length; i++)
				{
					if (string.IsNullOrEmpty(Captions[i]))
					{
						btns[i].Visibility = Visibility.Collapsed;
						continue;
					}
					btns[i].Content = Captions[i];
					btns[i].Visibility = Visibility.Visible;
				}
				OnPropertyChanged("ButtonsVisibility");
			}
		}

		public bool IsChecked
		{
			get
			{
				return m_checkbox == 1;
			}
			set
			{
				m_checkbox = (value ? 1 : 0);
				OnPropertyChanged("IsChecked");
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public OpenMessageBox()
		{
			InitializeComponent();
			base.Loaded += OpenMessageBox_Loaded;
			btns.Clear();
			btns.Add(btn0);
			btns.Add(btn1);
			btns.Add(btn2);
			btns.Add(btn3);
		}

		private void OpenMessageBox_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}

		private string ConvertButtonCaption(string text)
		{
			if (!string.IsNullOrEmpty(text))
			{
				text = BtnI18n(text);
				text = text.Replace('&', '_');
			}
			return text;
		}

		public void Init(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, int checkbox, int nCancelButton = -1, Window parentWnd = null)
		{
			string text = MMVersionHelper.MVGetI18nProductNameM();
			base.Title = (string.IsNullOrEmpty(szCaption) ? text : szCaption);
			if (parentWnd == null)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && shellApplication.ActiveWindow != null)
					{
						base.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
					else
					{
						base.Topmost = true;
					}
				}
			}
			else
			{
				base.Owner = parentWnd;
			}
			txtMessage.Text = szMsg;
			m_nDefButton = nDefButton;
			if (nCancelButton == -1)
			{
				m_nCancelButton = nDefButton;
			}
			else
			{
				m_nCancelButton = nCancelButton;
			}
			m_csHelp = szHelp;
			szBtn1 = ConvertButtonCaption(szBtn1);
			szBtn2 = ConvertButtonCaption(szBtn2);
			szBtn3 = ConvertButtonCaption(szBtn3);
			szBtn4 = ConvertButtonCaption(szBtn4);
			if (!string.IsNullOrEmpty(szBtn4))
			{
				Captions = new string[4] { szBtn1, szBtn2, szBtn3, szBtn4 };
			}
			else if (m_csHelp != null && m_csHelp.IndexOf('#') != -1)
			{
				Captions = new string[4]
				{
					szBtn1,
					szBtn2,
					szBtn3,
					WpfMMDialogResources._Help
				};
			}
			else
			{
				Captions = new string[4] { szBtn1, szBtn2, szBtn3, "" };
			}
			if (m_csHelp != null && m_csHelp.IndexOf('#') != -1)
			{
				int num = m_csHelp.IndexOf('#');
				if (int.TryParse(m_csHelp.Substring(num + 1), out var result))
				{
					MMHelp.SetHelpFile(this, m_csHelp.Substring(0, num));
					MMHelp.SetHelpId(this, result);
				}
			}
			m_checkbox = checkbox;
			chkDontshow.Visibility = ((m_checkbox == 0) ? Visibility.Collapsed : Visibility.Visible);
			switch (m_nDefButton)
			{
			case 0:
			case 1:
				btn0.IsDefault = true;
				break;
			case 2:
				btn1.IsDefault = true;
				break;
			case 3:
				btn2.IsDefault = true;
				break;
			case 4:
				btn3.IsDefault = true;
				break;
			}
			IsChecked = false;
		}

		private static string BtnI18n(string szBtn)
		{
			if (string.IsNullOrEmpty(szBtn))
			{
				return szBtn;
			}
			string result = szBtn;
			string text = szBtn;
			text = text.Trim().Replace("&", "");
			if (string.Compare(text, "Cancel", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Cancel;
			}
			else if (string.Compare(text, "OK", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Ok;
			}
			else if (string.Compare(text, "Abort", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Abort;
			}
			else if (string.Compare(text, "Help", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Help;
			}
			else if (string.Compare(text, "Ignore", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Ignore;
			}
			else if (string.Compare(text, "Yes", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Yes;
			}
			else if (string.Compare(text, "No", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._No;
			}
			else if (string.Compare(text, "Delete", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Delete;
			}
			else if (string.Compare(text, "Rename", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Rename;
			}
			else if (string.Compare(text, "Yes to all", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._YesAll;
			}
			else if (string.Compare(text, "No to all", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._NoAll;
			}
			else if (string.Compare(text, "Keep", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Keep;
			}
			else if (string.Compare(text, "Replace", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Replace;
			}
			else if (string.Compare(text, "Add", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._Add;
			}
			else if (string.Compare(text, "PURE", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._PURE;
			}
			else if (string.Compare(text, "MIXTURE", ignoreCase: true) == 0)
			{
				result = WpfMMDialogResources._MIXTURE;
			}
			return result;
		}

		public static int Show(string szCaption, string szMsg, string szBtn1, string szBtn2, string szBtn3, string szBtn4, string szHelp, int nDefButton, ref int checkbox, int nCancelButton = -1, Window parentWnd = null)
		{
			int nCheck = checkbox;
			OpenMessageBox msg = null;
			DispatcherOperation dispatcherOperation = System.Windows.Application.Current.Dispatcher.BeginInvoke((Func<int>)delegate
			{
				msg = new OpenMessageBox();
				msg.Init(szCaption, szMsg, szBtn1, szBtn2, szBtn3, szBtn4, szHelp, nDefButton, nCheck, nCancelButton, parentWnd);
				System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
				Mouse.OverrideCursor = null;
				msg.ShowDialog();
				Mouse.OverrideCursor = overrideCursor;
				return msg._result;
			});
			dispatcherOperation.Wait();
			if (msg != null)
			{
				checkbox = msg.m_checkbox;
			}
			if (dispatcherOperation.Status == DispatcherOperationStatus.Completed)
			{
				return (dispatcherOperation.Result as int?) ?? (-1);
			}
			return -1;
		}

		private void btn0_Click(object sender, RoutedEventArgs e)
		{
			if (IsHelpStr(Captions[0]))
			{
				ShowHelp();
				return;
			}
			_result = 1;
			Close();
		}

		private void btn1_Click(object sender, RoutedEventArgs e)
		{
			if (IsHelpStr(Captions[1]))
			{
				ShowHelp();
				return;
			}
			_result = 2;
			Close();
		}

		private void btn2_Click(object sender, RoutedEventArgs e)
		{
			if (IsHelpStr(Captions[2]))
			{
				ShowHelp();
				return;
			}
			_result = 3;
			Close();
		}

		private void btn3_Click(object sender, RoutedEventArgs e)
		{
			if (IsHelpStr(Captions[3]))
			{
				ShowHelp();
				return;
			}
			_result = 4;
			Close();
		}

		private bool IsHelpStr(string csBtn)
		{
			int num = 0;
			int num2 = 0;
			StringBuilder stringBuilder = new StringBuilder(20);
			while (num2 < csBtn.Length && num < 20)
			{
				if (num2 == 0 && csBtn[num2] == '_')
				{
					num2++;
				}
				else if (csBtn[num2] != '&' && csBtn[num2] != ' ')
				{
					stringBuilder.Append(csBtn[num2++]);
					num++;
				}
				else
				{
					num2++;
				}
			}
			if (stringBuilder.ToString().Equals(WpfMMDialogResources.Help, StringComparison.InvariantCultureIgnoreCase))
			{
				return true;
			}
			return false;
		}

		private bool ShowHelp()
		{
			ApplicationCommands.Help.Execute(null, this);
			return false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/openmessagebox.xaml", UriKind.Relative);
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
				txtMessage = (TextBlock)target;
				break;
			case 2:
				chkDontshow = (System.Windows.Controls.CheckBox)target;
				break;
			case 3:
				buttonsPanel = (Grid)target;
				break;
			case 4:
				btn0 = (System.Windows.Controls.Button)target;
				btn0.Click += btn0_Click;
				break;
			case 5:
				btn1 = (System.Windows.Controls.Button)target;
				btn1.Click += btn1_Click;
				break;
			case 6:
				btn2 = (System.Windows.Controls.Button)target;
				btn2.Click += btn2_Click;
				break;
			case 7:
				btn3 = (System.Windows.Controls.Button)target;
				btn3.Click += btn3_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ParamVal : MMDialog, INotifyPropertyChanged, IComponentConnector
	{
		private IntPtr m_ptrInit;

		private bool _canEdit;

		private ObservableCollection<StreamEoItem> _allParamVal = new ObservableCollection<StreamEoItem>();

		internal System.Windows.Controls.DataGrid NameGrid;

		private bool _contentLoaded;

		public string HelpFile => "gendbhlp.chm";

		public bool CanEdit
		{
			get
			{
				return _canEdit;
			}
			set
			{
				if (_canEdit != value)
				{
					_canEdit = value;
					OnPropertyChanged("CanEdit");
				}
			}
		}

		public ObservableCollection<StreamEoItem> AllParamVals
		{
			get
			{
				return _allParamVal;
			}
			set
			{
				if (_allParamVal != value)
				{
					_allParamVal = value;
					OnPropertyChanged("AllParamVals");
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ParamVal()
		{
			InitializeComponent();
			base.Loaded += ParamVal_Loaded;
		}

		public ParamVal(IntPtr ptrParas)
		{
			InitializeComponent();
			m_ptrInit = ptrParas;
			while (ptrParas != IntPtr.Zero)
			{
				int strLen = 0;
				ptrParas = IDHelper.GetParaVals(ptrParas, out var strPara, out strLen, out var strVal);
				StreamEoItem item = new StreamEoItem
				{
					OldName = strPara,
					NewName = strLen.ToString(),
					Status = strVal
				};
				AllParamVals.Add(item);
			}
			CanEdit = false;
			base.Loaded += ParamVal_Loaded;
		}

		private void ParamVal_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
		}

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		private void NameGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (NameGrid.SelectedItems != null)
			{
				if (NameGrid.SelectedItems.Count == 1)
				{
					CanEdit = true;
				}
				else
				{
					CanEdit = false;
				}
			}
		}

		private void Button_Click_edit(object sender, RoutedEventArgs e)
		{
			IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfMMDialogResources.ParaValueTitle, WpfMMDialogResources.ParaValueLabel, IDBoxDlg.IDType.UnDefine, 11);
			iDBoxDlg.Owner = this;
			iDBoxDlg.ShowDialog();
			if (iDBoxDlg.DialogResult == true && NameGrid.SelectedItems != null && ContainsNon_Chinese_Characteres(iDBoxDlg.ID))
			{
				(NameGrid.SelectedItems[0] as StreamEoItem).Status = iDBoxDlg.ID;
			}
		}

		private void Button_Click_OK(object sender, RoutedEventArgs e)
		{
			foreach (StreamEoItem allParamVal in AllParamVals)
			{
				if (string.IsNullOrEmpty(allParamVal.Status))
				{
					MMMessageBox.Show(WpfMMDialogResources.ParaValMsg, MMVersionHelper.MVGetI18nProductNameM());
					return;
				}
			}
			IntPtr intPtr = m_ptrInit;
			foreach (StreamEoItem allParamVal2 in AllParamVals)
			{
				if (intPtr != IntPtr.Zero)
				{
					intPtr = IDHelper.SetParaVal(intPtr, allParamVal2.Status);
				}
			}
			base.DialogResult = true;
		}

		private void Button_Click_Cancel(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		private void NameGrid_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfMMDialogResources.ParaValueTitle, WpfMMDialogResources.ParaValueLabel, IDBoxDlg.IDType.UnDefine, 12);
			iDBoxDlg.Owner = this;
			iDBoxDlg.ShowDialog();
			if (iDBoxDlg.DialogResult == true && NameGrid.SelectedItems != null && ContainsNon_Chinese_Characteres(iDBoxDlg.ID))
			{
				(NameGrid.SelectedItems[0] as StreamEoItem).Status = iDBoxDlg.ID;
			}
		}

		private bool ContainsNon_Chinese_Characteres(string input)
		{
			return new Regex("^[^\\p{IsCJKUnifiedIdeographs}]*$").IsMatch(input);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/paramval.xaml", UriKind.Relative);
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
				NameGrid = (System.Windows.Controls.DataGrid)target;
				NameGrid.SelectionChanged += NameGrid_SelectionChanged;
				NameGrid.MouseDoubleClick += NameGrid_MouseDoubleClick;
				break;
			case 2:
				((System.Windows.Controls.Button)target).Click += Button_Click_edit;
				break;
			case 3:
				((System.Windows.Controls.Button)target).Click += Button_Click_OK;
				break;
			case 4:
				((System.Windows.Controls.Button)target).Click += Button_Click_Cancel;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ProgressDlg : Window, IComponentConnector
	{
		private delegate void UpdateProgressBarDelegate(DependencyProperty dp, object value);

		private double m_dStepValue = 1.0;

		private short m_shortCancelled;

		internal System.Windows.Controls.ProgressBar progressBar1;

		internal System.Windows.Controls.Button button1;

		private bool _contentLoaded;

		public double StepValue => m_dStepValue;

		public short IsCancelled
		{
			get
			{
				return m_shortCancelled;
			}
			set
			{
				m_shortCancelled = value;
			}
		}

		public ProgressDlg()
		{
			InitializeComponent();
		}

		public void InitializeBar(int nMinimum = 0, int nMaximum = 0, int nStep = 1)
		{
			progressBar1.Minimum = nMinimum;
			progressBar1.Maximum = nMaximum;
			progressBar1.Value = 0.0;
			m_dStepValue = nStep;
		}

		public void StepIt()
		{
			double num = 0.0;
			num = progressBar1.Value;
			num += m_dStepValue;
			UpdateProgressBarDelegate method = progressBar1.SetValue;
			base.Dispatcher.Invoke(method, DispatcherPriority.Background, RangeBase.ValueProperty, num);
		}

		protected void Button1_OnClick(object sender, RoutedEventArgs args)
		{
			m_shortCancelled = 1;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/progressdlg.xaml", UriKind.Relative);
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
				progressBar1 = (System.Windows.Controls.ProgressBar)target;
				break;
			case 2:
				button1 = (System.Windows.Controls.Button)target;
				button1.Click += Button1_OnClick;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ResolveConflictsDlg : MMDialog, IComponentConnector
	{
		private const int SC_CLOSE = 61536;

		private const int MF_GRAYED = 1;

		private const int MF_DISABLED = 2;

		private const int MF_BYCOMMAND = 0;

		private GridViewColumnHeader _lastHeaderClicked;

		private ListSortDirection _lastDirection;

		internal ResolveConflictsDlg dlg;

		internal Grid grid1;

		internal System.Windows.Controls.Button Replace;

		internal System.Windows.Controls.Button Merge;

		internal System.Windows.Controls.Button EditID;

		internal System.Windows.Controls.Button AddPrefix;

		internal System.Windows.Controls.Button AddSuffix;

		internal System.Windows.Controls.Button Ignore;

		internal System.Windows.Controls.Button Undo;

		internal System.Windows.Controls.Button Ok;

		internal System.Windows.Controls.Button Cancel;

		internal System.Windows.Controls.Button Help;

		internal System.Windows.Controls.ListView ConflictIDList;

		private bool _contentLoaded;

		public string HelpFile
		{
			get
			{
				if (!SystemEnvironment.IsAspenProperties)
				{
					return "userguide3.chm";
				}
				return "plotwiz.chm";
			}
		}

		public int HelpId
		{
			get
			{
				if (!SystemEnvironment.IsAspenProperties)
				{
					return 72;
				}
				return 6;
			}
		}

		public ResolveConflictsM CppCode { get; set; }

		public bool CanCancel { get; set; }

		[DllImport("user32.dll")]
		public static extern int GetSystemMenu(int hWnd, int bRevert);

		[DllImport("user32.dll")]
		public static extern bool EnableMenuItem(int hMenu, int uIDEnableItem, int uEnable);

		public ResolveConflictsDlg()
		{
			base.DataContext = this;
			CppCode = new ResolveConflictsM();
			InitializeComponent();
			ConflictIDList.ItemsSource = CppCode.Items;
			base.AutoDefault = 0;
			base.ButtonText = WpfMMDialogResources.ConflictDialog_Cancel;
			base.DefaultMessage = WpfMMDialogResources.ConflictDialog_DefaultMessage;
			base.Loaded += ResolveConflictsDlg_Loaded;
			base.Closing += ResolveConflictsDlg_Closing;
			base.Closed += delegate(object sender, EventArgs a)
			{
				((ResolveConflictsDlg)sender).CppCode.Cleanup();
			};
		}

		private void ResolveConflictsDlg_Loaded(object sender, RoutedEventArgs e)
		{
			if (!CppCode.CancelEnabled)
			{
				Ok.Content = WpfMMDialogResources.Close;
				IntPtr handle = new WindowInteropHelper(this).Handle;
				if (handle != IntPtr.Zero)
				{
					EnableMenuItem(GetSystemMenu(handle.ToInt32(), 0), 61536, 1);
				}
			}
		}

		private void ResolveConflictsDlg_Closing(object sender, CancelEventArgs e)
		{
			if (!Cancel.IsEnabled && Keyboard.IsKeyDown(Key.F4) && Keyboard.Modifiers == ModifierKeys.Alt)
			{
				e.Cancel = true;
			}
		}

		private void Replace_Click(object sender, RoutedEventArgs e)
		{
			CppCode.SetSelectedItems(1, null);
		}

		private void Ignore_Click(object sender, RoutedEventArgs e)
		{
			CppCode.SetSelectedItems(2, null);
		}

		private void Merge_Click(object sender, RoutedEventArgs e)
		{
			CppCode.SetSelectedItems(3, null);
		}

		private void EditID_Click(object sender, RoutedEventArgs e)
		{
			string[] array = (ConflictIDList.SelectedItem as ResolveConflictsM.ConflictItem).Name.Split(' ').Reverse().ToArray();
			bool bMHeatX = false;
			if (array[1].Contains("MHeatX"))
			{
				bMHeatX = true;
			}
			IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfMMDialogResources.ConflictDialog_ObjectName, WpfMMDialogResources.ConflictDialog_PleaseEnterID, IDBoxDlg.IDType.ID, bMHeatX, 16);
			iDBoxDlg.Owner = this;
			if (array != null && array.Length > 1)
			{
				int i;
				for (i = 0; array[i] == string.Empty || array[i].StartsWith("("); i++)
				{
				}
				iDBoxDlg.ID = array[i];
				iDBoxDlg.ShowDialog();
				if (iDBoxDlg.DialogResult == true)
				{
					CppCode.SetSelectedItems(10, iDBoxDlg.ID.ToUpper());
				}
			}
		}

		private void AddPrefix_Click(object sender, RoutedEventArgs e)
		{
			IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfMMDialogResources.ConflictDialog_Prefix, WpfMMDialogResources.ConflictDialog_EnterPrefix, IDBoxDlg.IDType.Prefix, CppCode.MaxLength());
			iDBoxDlg.ShowDialog();
			if (iDBoxDlg.DialogResult == true)
			{
				CppCode.SetSelectedItems(20, iDBoxDlg.ID.ToUpper());
			}
		}

		private void AddSuffix_Click(object sender, RoutedEventArgs e)
		{
			IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfMMDialogResources.ConflictDialog_Suffix, WpfMMDialogResources.ConflictDialog_EnterSuffix, IDBoxDlg.IDType.Suffix, CppCode.MaxLength());
			iDBoxDlg.ShowDialog();
			if (iDBoxDlg.DialogResult == true)
			{
				CppCode.SetSelectedItems(30, iDBoxDlg.ID.ToUpper());
			}
		}

		private void Undo_Click(object sender, RoutedEventArgs e)
		{
			CppCode.Undo();
		}

		private void Ok_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void ListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			List<ResolveConflictsM.ConflictItem> list = new List<ResolveConflictsM.ConflictItem>();
			foreach (ResolveConflictsM.ConflictItem selectedItem in ConflictIDList.SelectedItems)
			{
				list.Add(selectedItem);
			}
			CppCode.SelectedItems = list;
			CppCode.OnSelectedItemsChange();
		}

		private void ListView_ColumnHeaderClicked(object sender, RoutedEventArgs e)
		{
			if (e.OriginalSource is GridViewColumnHeader { Role: not GridViewColumnHeaderRole.Padding } gridViewColumnHeader)
			{
				ListSortDirection listSortDirection = ((gridViewColumnHeader == _lastHeaderClicked && _lastDirection == ListSortDirection.Ascending) ? ListSortDirection.Descending : ListSortDirection.Ascending);
				string sortBy = gridViewColumnHeader.Column.Header as string;
				Sort(sortBy, listSortDirection);
				if (listSortDirection == ListSortDirection.Ascending)
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowUp"] as DataTemplate;
				}
				else
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowDown"] as DataTemplate;
				}
				if (_lastHeaderClicked != null && _lastHeaderClicked != gridViewColumnHeader)
				{
					_lastHeaderClicked.Column.HeaderTemplate = null;
				}
				_lastHeaderClicked = gridViewColumnHeader;
				_lastDirection = listSortDirection;
			}
		}

		private void Sort(string sortBy, ListSortDirection direction)
		{
			if (sortBy == "Object")
			{
				sortBy = "Name";
			}
			ICollectionView defaultView = CollectionViewSource.GetDefaultView(ConflictIDList.ItemsSource);
			defaultView.SortDescriptions.Clear();
			SortDescription item = new SortDescription(sortBy, direction);
			defaultView.SortDescriptions.Add(item);
			defaultView.Refresh();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/resolveconflictsdlg.xaml", UriKind.Relative);
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
				dlg = (ResolveConflictsDlg)target;
				break;
			case 2:
				grid1 = (Grid)target;
				break;
			case 3:
				Replace = (System.Windows.Controls.Button)target;
				Replace.Click += Replace_Click;
				break;
			case 4:
				Merge = (System.Windows.Controls.Button)target;
				Merge.Click += Merge_Click;
				break;
			case 5:
				EditID = (System.Windows.Controls.Button)target;
				EditID.Click += EditID_Click;
				break;
			case 6:
				AddPrefix = (System.Windows.Controls.Button)target;
				AddPrefix.Click += AddPrefix_Click;
				break;
			case 7:
				AddSuffix = (System.Windows.Controls.Button)target;
				AddSuffix.Click += AddSuffix_Click;
				break;
			case 8:
				Ignore = (System.Windows.Controls.Button)target;
				Ignore.Click += Ignore_Click;
				break;
			case 9:
				Undo = (System.Windows.Controls.Button)target;
				Undo.Click += Undo_Click;
				break;
			case 10:
				Ok = (System.Windows.Controls.Button)target;
				Ok.Click += Ok_Click;
				break;
			case 11:
				Cancel = (System.Windows.Controls.Button)target;
				break;
			case 12:
				Help = (System.Windows.Controls.Button)target;
				break;
			case 13:
				ConflictIDList = (System.Windows.Controls.ListView)target;
				ConflictIDList.SelectionChanged += ListView_SelectionChanged;
				ConflictIDList.AddHandler(System.Windows.Controls.Primitives.ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class NameI18nConvertor : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				return null;
			}
			string text = value.ToString();
			string empty = string.Empty;
			empty = ((!text.Contains('(')) ? text : text.Substring(0, text.IndexOf('(') - 1));
			CultureInfo cultureInfo = new CultureInfo("en-US");
			string text2 = string.Empty;
			string text3 = string.Empty;
			string[] array = empty.Trim().Split(' ');
			for (int i = 0; i < array.Length - 1; i++)
			{
				if (!string.IsNullOrEmpty(array[i]))
				{
					text3 = ((!(array[i] == "EO") && !array[i].Contains("EO-Sensitivity")) ? (text3 + cultureInfo.TextInfo.ToTitleCase(array[i].ToLower())) : (text3 + array[i]));
					string translatedNodeDisplayText = NodePathI18nHelper.GetTranslatedNodeDisplayText(text3);
					if (!string.IsNullOrEmpty(translatedNodeDisplayText))
					{
						text2 = text2 + " " + translatedNodeDisplayText;
						text3 = string.Empty;
					}
				}
			}
			text2 = (string.IsNullOrEmpty(text2) ? empty : (text2 + " " + array[array.Length - 1]));
			if (text.Contains('('))
			{
				text = text2 + text.Substring(text.IndexOf('('));
				string recTypeFromDisplayName = RecTypeI18nHelper.GetRecTypeFromDisplayName(text);
				if (!string.IsNullOrEmpty(recTypeFromDisplayName))
				{
					string oldValue = $"({recTypeFromDisplayName})";
					string newValue = $"({RecTypeI18nHelper.GetTranslatedRecType(recTypeFromDisplayName)})";
					text = text.Replace(oldValue, newValue);
				}
			}
			else
			{
				text = text2;
			}
			return text;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class NodePathI18nHelper
	{
		public static string GetTranslatedNodeDisplayText(string textString)
		{
			string name = $"Browser{textString}";
			string text = ApwnResources.ResourceManager.GetString(name, Thread.CurrentThread.CurrentUICulture);
			return string.IsNullOrEmpty(text) ? textString : text;
		}
	}
	public class ResolveStreamEOName : Window, INotifyPropertyChanged, IComponentConnector
	{
		private const int MF_BYPOSITION = 1024;

		private string _helpId;

		private Visibility _editVisble;

		private string _strTitle;

		private string _strBtnLabel;

		private ObservableCollection<StreamEoItem> _allEoStreamName = new ObservableCollection<StreamEoItem>();

		private DelegateCommand<object> _commandOnReplace;

		private DelegateCommand<object> _commandOnIgnore;

		private DelegateCommand<object> _commandOnEdit;

		private DelegateCommand<object> _commandOnOK;

		internal System.Windows.Controls.DataGrid NameGrid;

		private bool _contentLoaded;

		public string HelpFile => "apeoref.chm";

		public string HelpID
		{
			get
			{
				return _helpId;
			}
			set
			{
				if (_helpId != value)
				{
					_helpId = value;
					OnPropertyChanged("HelpID");
				}
			}
		}

		public Visibility EditVisble
		{
			get
			{
				return _editVisble;
			}
			set
			{
				if (_editVisble != value)
				{
					_editVisble = value;
					OnPropertyChanged("EditVisble");
				}
			}
		}

		public string WindowTitle
		{
			get
			{
				return _strTitle;
			}
			set
			{
				if (_strTitle != value)
				{
					_strTitle = value;
					OnPropertyChanged("WindowTitle");
				}
			}
		}

		public string BtnLabel
		{
			get
			{
				return _strBtnLabel;
			}
			set
			{
				if (_strBtnLabel != value)
				{
					_strBtnLabel = value;
					OnPropertyChanged("BtnLabel");
				}
			}
		}

		public ObservableCollection<StreamEoItem> AllEoStreamName
		{
			get
			{
				return _allEoStreamName;
			}
			set
			{
				if (_allEoStreamName != value)
				{
					_allEoStreamName = value;
					OnPropertyChanged("AllEoStreamName");
				}
			}
		}

		public ICommand CommandOnReplace
		{
			get
			{
				if (_commandOnReplace == null)
				{
					_commandOnReplace = new DelegateCommand<object>(ExecuteCommandOnReplace, CanExecuteCommandReplace);
				}
				return _commandOnReplace;
			}
		}

		public ICommand CommandOnIgnore
		{
			get
			{
				if (_commandOnIgnore == null)
				{
					_commandOnIgnore = new DelegateCommand<object>(ExecuteCommandOnIgnore, CanExecuteCommandIgnore);
				}
				return _commandOnIgnore;
			}
		}

		public ICommand CommandOnEdit
		{
			get
			{
				if (_commandOnEdit == null)
				{
					_commandOnEdit = new DelegateCommand<object>(ExecuteCommandOnEdit, CanExecuteCommandEdit);
				}
				return _commandOnEdit;
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ResolveStreamEOName(bool bRename = false)
		{
			InitializeComponent();
			if (bRename)
			{
				HelpID = "77";
				BtnLabel = WpfMMDialogResources.Replace;
				EditVisble = Visibility.Visible;
				WindowTitle = WpfMMDialogResources.ResolveEoNames;
			}
			else
			{
				HelpID = "209";
				BtnLabel = WpfMMDialogResources.Remove;
				EditVisble = Visibility.Collapsed;
				WindowTitle = WpfMMDialogResources.RemoveEoNames;
				NameGrid.Columns[1].Visibility = Visibility.Collapsed;
			}
			int accept = -1;
			string strOldName = "";
			string strNewName = "";
			IntPtr ptr = IntPtr.Zero;
			int num = 1;
			while (num > 0)
			{
				num = IDHelper.GetEOName(ref ptr, ref strOldName, ref strNewName, ref accept);
				if (!string.IsNullOrEmpty(strOldName))
				{
					StreamEoItem item = ((accept != 1) ? new StreamEoItem
					{
						OldName = strOldName,
						NewName = strNewName,
						Status = WpfMMDialogResources.Ignore
					} : new StreamEoItem
					{
						OldName = strOldName,
						NewName = strNewName,
						Status = BtnLabel
					});
					AllEoStreamName.Add(item);
				}
				if (accept == -1)
				{
					break;
				}
			}
			base.Loaded += ResolveStreamEOName_Loaded;
		}

		private void ResolveStreamEOName_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
			IntPtr systemMenu = GetSystemMenu(new WindowInteropHelper(this).Handle, bRevert: false);
			int menuItemCount = GetMenuItemCount(systemMenu);
			RemoveMenu(systemMenu, menuItemCount - 1, 1024);
		}

		[DllImport("User32")]
		private static extern int RemoveMenu(IntPtr hMenu, int nPosition, int wFlags);

		[DllImport("User32")]
		private static extern IntPtr GetSystemMenu(IntPtr hWnd, bool bRevert);

		[DllImport("User32")]
		private static extern int GetMenuItemCount(IntPtr hWnd);

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		private bool CanExecuteCommandReplace(object arg)
		{
			if (NameGrid.SelectedItems != null && NameGrid.SelectedItems.Count > 0)
			{
				if (NameGrid.SelectedItems.Count == 1 && (NameGrid.SelectedItems[0] as StreamEoItem).Status == BtnLabel)
				{
					return false;
				}
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnReplace(object arg)
		{
			SetSelectedItemStatus(BtnLabel);
		}

		private void SetSelectedItemStatus(string status)
		{
			foreach (object selectedItem in NameGrid.SelectedItems)
			{
				(selectedItem as StreamEoItem).Status = status;
			}
			(CommandOnReplace as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnIgnore as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private void ExecuteCommandOnIgnore(object arg)
		{
			SetSelectedItemStatus(WpfMMDialogResources.Ignore);
		}

		private bool CanExecuteCommandIgnore(object arg)
		{
			if (NameGrid.SelectedItems != null && NameGrid.SelectedItems.Count > 0)
			{
				if (NameGrid.SelectedItems.Count == 1 && (NameGrid.SelectedItems[0] as StreamEoItem).Status == WpfMMDialogResources.Ignore)
				{
					return false;
				}
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnEdit(object arg)
		{
			StreamEoItem streamEoItem = NameGrid.SelectedItems[0] as StreamEoItem;
			IDBoxDlg2 iDBoxDlg = new IDBoxDlg2(streamEoItem.NewName);
			iDBoxDlg.Owner = this;
			iDBoxDlg.ShowDialog();
			if (iDBoxDlg.DialogResult == true)
			{
				streamEoItem.NewName = iDBoxDlg.NewName;
			}
		}

		private bool CanExecuteCommandEdit(object arg)
		{
			if (NameGrid.SelectedItems != null && NameGrid.SelectedItems.Count == 1)
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			IntPtr ptr = IntPtr.Zero;
			int num = 1;
			while (num > 0)
			{
				int accept = -1;
				string strOldName = "";
				string strNewName = "";
				num = IDHelper.GetEOName(ref ptr, ref strOldName, ref strNewName, ref accept);
				if (accept == -1)
				{
					break;
				}
				if (string.IsNullOrEmpty(strOldName))
				{
					continue;
				}
				foreach (StreamEoItem item in AllEoStreamName)
				{
					if (item.OldName == strOldName)
					{
						IDHelper.SetEOName(accept: (AllEoStreamName[0].Status == BtnLabel) ? 1 : 0, ptr: ptr, strNewName: item.NewName);
						break;
					}
				}
			}
			base.DialogResult = true;
		}

		private void NameGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			(CommandOnReplace as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnIgnore as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnEdit as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/resolvestreameoname.xaml", UriKind.Relative);
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
				NameGrid = (System.Windows.Controls.DataGrid)target;
				NameGrid.SelectionChanged += NameGrid_SelectionChanged;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class StreamEoItem : INotifyPropertyChanged
	{
		private string _oldName;

		private string _newName;

		private string _status;

		public string OldName
		{
			get
			{
				return _oldName;
			}
			set
			{
				if (_oldName != value)
				{
					_oldName = value;
					OnPropertyChanged("OldName");
				}
			}
		}

		public string NewName
		{
			get
			{
				return _newName;
			}
			set
			{
				if (_newName != value)
				{
					_newName = value;
					OnPropertyChanged("NewName");
				}
			}
		}

		public string Status
		{
			get
			{
				return _status;
			}
			set
			{
				if (_status != value)
				{
					_status = value;
					OnPropertyChanged("Status");
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	public class RevealDlg : Window, IComponentConnector
	{
		internal Grid grid1;

		internal System.Windows.Controls.Button Replace;

		internal System.Windows.Controls.Button Merge;

		internal System.Windows.Controls.Button EditID;

		internal System.Windows.Controls.Button AddPrefix;

		internal System.Windows.Controls.Button AddSuffix;

		internal System.Windows.Controls.Button Ignore;

		internal System.Windows.Controls.ListView ConflictIDList;

		private bool _contentLoaded;

		public RevealDlg()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/revealdlg.xaml", UriKind.Relative);
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
				grid1 = (Grid)target;
				break;
			case 2:
				Replace = (System.Windows.Controls.Button)target;
				break;
			case 3:
				Merge = (System.Windows.Controls.Button)target;
				break;
			case 4:
				EditID = (System.Windows.Controls.Button)target;
				break;
			case 5:
				AddPrefix = (System.Windows.Controls.Button)target;
				break;
			case 6:
				AddSuffix = (System.Windows.Controls.Button)target;
				break;
			case 7:
				Ignore = (System.Windows.Controls.Button)target;
				break;
			case 8:
				ConflictIDList = (System.Windows.Controls.ListView)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ShowFileDlgViewModel : INotifyPropertyChanged
	{
		private string _title;

		private string _fileContent;

		private Visibility _canCancel = Visibility.Collapsed;

		private string _strHelpID;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public string Title
		{
			get
			{
				return _title;
			}
			set
			{
				_title = value;
				OnPropertyChanged("Title");
			}
		}

		public string FileContent
		{
			get
			{
				return _fileContent;
			}
			set
			{
				_fileContent = value;
				OnPropertyChanged("FileContent");
			}
		}

		public Visibility CanCancel
		{
			get
			{
				return _canCancel;
			}
			set
			{
				_canCancel = value;
				OnPropertyChanged("CanCancel");
			}
		}

		public string HelpId
		{
			get
			{
				return _strHelpID;
			}
			set
			{
				_strHelpID = value;
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public ICommand CommandOnCancel
		{
			get
			{
				if (_commandOnCancel == null)
				{
					_commandOnCancel = new DelegateCommand<object>(ExecuteCommandOnCancel);
				}
				return _commandOnCancel;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public virtual bool Initialize(string fileName)
		{
			if (string.IsNullOrEmpty(fileName) || !File.Exists(fileName))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(FileContent))
			{
				return false;
			}
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			DialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			DialogsModule.Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			DialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}
	}
	public class ShowFlowsheetIncompleteDlgViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			string text = "";
			if (string.IsNullOrEmpty(fileName))
			{
				MmgSor.GetEditorTempFileNameM(out var szFilename);
				text = szFilename;
			}
			else
			{
				text = fileName;
			}
			if (MmgSor.CCgrahlpM(text) <= 0)
			{
				return false;
			}
			if (string.IsNullOrEmpty(text) || !File.Exists(text))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(text, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			File.Delete(text);
			if (string.IsNullOrEmpty(base.FileContent))
			{
				return false;
			}
			base.Title = WpfMMDialogResources.ShowFileDlgTitleIncomplete;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class ShowTFFProcessingErrorViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			if (string.IsNullOrEmpty(fileName))
			{
				return false;
			}
			if (string.IsNullOrEmpty(fileName) || !File.Exists(fileName))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(base.FileContent))
			{
				return false;
			}
			base.Title = WpfMMDialogResources.ShowFileDlogTilteTFFProcessingError;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class ShowReadBackupFileErrorViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			if (string.IsNullOrEmpty(fileName))
			{
				return false;
			}
			if (string.IsNullOrEmpty(fileName) || !File.Exists(fileName))
			{
				return false;
			}
			string text = null;
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				text = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(text))
			{
				return false;
			}
			if (MmgSor.GRinqMoveToHierM() != 0)
			{
				base.FileContent = WpfMMDialogResources.ErrorMoveObjectIntoHierarchy + Environment.NewLine;
				base.Title = WpfMMDialogResources.ErrorMoveHierarchyTitle;
			}
			else
			{
				base.FileContent = WpfMMDialogResources.ErrorReadBackFileContent + Environment.NewLine;
				base.Title = WpfMMDialogResources.ErrorReadBackFileContentTitle;
			}
			base.FileContent += text;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && (shellApplication.MainWindows.Count == 0 || !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible))
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class ShowInputSummaryErrorViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			if (string.IsNullOrEmpty(fileName))
			{
				return false;
			}
			if (string.IsNullOrEmpty(fileName) || !File.Exists(fileName))
			{
				return false;
			}
			string text = null;
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				text = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(text))
			{
				return false;
			}
			base.FileContent = WpfMMDialogResources.ErrorBeforCalculations;
			text.Replace(';', ' ');
			base.FileContent += text;
			base.FileContent += WpfMMDialogResources.ErrorLocateSource;
			base.Title = WpfMMDialogResources.ErrorLocateSourceTitle;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class SpeedupExportDialogViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			if (string.IsNullOrEmpty(fileName))
			{
				return false;
			}
			if (string.IsNullOrEmpty(fileName) || !File.Exists(fileName))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(base.FileContent))
			{
				return false;
			}
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class ShowEOErrorDlgViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			string text = "";
			if (string.IsNullOrEmpty(fileName))
			{
				string szFilename = "";
				MmgSor.GetEditorTempFileNameM(out szFilename);
				text = szFilename;
			}
			else
			{
				text = fileName;
			}
			if (MmgSor.MDerrmsgM(text) <= 0)
			{
				return false;
			}
			if (string.IsNullOrEmpty(text) || !File.Exists(text))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(text, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			File.Delete(text);
			if (string.IsNullOrEmpty(base.FileContent))
			{
				return false;
			}
			base.Title = WpfMMDialogResources.EOSynchronizationFailuresTitle;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}

		public bool Initiliaze(string fileName, string object_id)
		{
			if (!File.Exists(fileName))
			{
				return false;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			if (string.IsNullOrEmpty(object_id))
			{
				base.Title = WpfMMDialogResources.EOSynchronizationErrorAndWarningTitle;
			}
			else
			{
				base.Title = string.Format(WpfMMDialogResources.EOSynchErrorAndWarningWithIdTitle, object_id);
			}
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	public class ShowMoveErrorDlgViewModel : ShowFileDlgViewModel
	{
		public override bool Initialize(string fileName)
		{
			return Initialize(fileName, bCanCancel: false);
		}

		public bool Initialize(string fileName, bool bCanCancel)
		{
			if (!File.Exists(fileName))
			{
				return false;
			}
			if (bCanCancel)
			{
				base.CanCancel = Visibility.Visible;
			}
			try
			{
				using StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
				base.FileContent = streamReader.ReadToEnd();
			}
			catch (IOException ex)
			{
				MMMessageBox.Show(ex.Message);
				return false;
			}
			base.Title = WpfMMDialogResources.MoveConflictResolutionFailures;
			if (MmgSor.MMGetSuppressM() != 0)
			{
				IUnityContainer container = DialogsModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null && !Window.GetWindow(shellApplication.MainWindows[0] as DependencyObject).IsVisible)
					{
						return false;
					}
				}
			}
			base.HelpId = "21004";
			return true;
		}
	}
	public class ShowFileDlg : Window, IComponentConnector
	{
		internal System.Windows.Controls.TextBox txtFileContent;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		internal System.Windows.Controls.Button btnHelp;

		private bool _contentLoaded;

		public ShowFileDlg()
		{
			InitializeComponent();
		}

		private void OnClickOK(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void OnClickCancel(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/showfiledlg.xaml", UriKind.Relative);
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
				txtFileContent = (System.Windows.Controls.TextBox)target;
				break;
			case 2:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += OnClickOK;
				break;
			case 3:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += OnClickCancel;
				break;
			case 4:
				btnHelp = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SuperNextDlg : Window, IComponentConnector
	{
		private Collection<System.Windows.Controls.RadioButton> buttons;

		private int buttonIndex = -1;

		private int nbutton;

		public static DependencyProperty DontShowMessageAgainProperty = DependencyProperty.Register("DontShowMessageAgain", typeof(bool), typeof(SuperNextDlg), new FrameworkPropertyMetadata(false, null));

		internal SuperNextDlg WinSuperNext;

		internal System.Windows.Controls.Label label1;

		internal AesGroupBox AesGroupBox;

		internal StackPanel stackRadios;

		internal System.Windows.Controls.RadioButton Rd0;

		internal System.Windows.Controls.RadioButton Rd1;

		internal System.Windows.Controls.RadioButton Rd2;

		internal System.Windows.Controls.RadioButton Rd3;

		internal System.Windows.Controls.RadioButton Rd4;

		internal System.Windows.Controls.RadioButton Rd5;

		internal System.Windows.Controls.RadioButton Rd6;

		internal System.Windows.Controls.Button OK;

		internal System.Windows.Controls.Button Cancel;

		internal System.Windows.Controls.CheckBox ChkBox_DontShow;

		internal System.Windows.Controls.Label LblTitle;

		private bool _contentLoaded;

		public int ButtonIndex
		{
			get
			{
				return buttonIndex;
			}
			set
			{
				buttonIndex = value;
			}
		}

		public bool DontShowMessageAgain
		{
			get
			{
				return (bool)GetValue(DontShowMessageAgainProperty);
			}
			set
			{
				SetValue(DontShowMessageAgainProperty, value);
			}
		}

		public SuperNextDlg(string title, string text, Collection<string> options, int minWidth)
		{
			InitializeComponent();
			base.Title = title;
			label1.Content = text;
			if (minWidth > 0)
			{
				base.MinWidth = minWidth;
			}
			nbutton = options.Count;
			buttons = new Collection<System.Windows.Controls.RadioButton>();
			buttons.Add(Rd0);
			buttons.Add(Rd1);
			buttons.Add(Rd2);
			buttons.Add(Rd3);
			buttons.Add(Rd4);
			buttons.Add(Rd5);
			buttons.Add(Rd6);
			for (int i = 0; i < nbutton; i++)
			{
				buttons[i].Content = options[i];
			}
			for (int j = nbutton; j < 7; j++)
			{
				buttons[j].Visibility = Visibility.Collapsed;
				buttons[j].IsEnabled = false;
			}
			buttons[0].IsChecked = true;
			base.Loaded += SuperNextDlg_Loaded;
		}

		private void SuperNextDlg_Loaded(object sender, RoutedEventArgs e)
		{
			SetWindowAppropriateWidth();
		}

		private void SetWindowAppropriateWidth()
		{
			if (base.Title == WpfMMDialogResources.tiReqdrsIC || base.Title == WpfMMDialogResources.tiReqPCESIC)
			{
				base.MinWidth = LblTitle.ActualWidth + 126.0;
			}
			else
			{
				base.MinWidth = LblTitle.ActualWidth + 96.0;
			}
			buttons[0].Focus();
		}

		private void BtnOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			ButtonIndex = -1;
			for (int i = 0; i < nbutton; i++)
			{
				if (buttons[i].IsChecked.Value)
				{
					ButtonIndex = i;
					break;
				}
			}
		}

		private void ChkBoxDontShow_CheckedChanged(object sender, RoutedEventArgs e)
		{
			Handle(sender as System.Windows.Controls.CheckBox);
		}

		private void ChkBoxDontShow_UnCheckedChanged(object sender, RoutedEventArgs e)
		{
			Handle(sender as System.Windows.Controls.CheckBox);
		}

		private void Handle(System.Windows.Controls.CheckBox checkBox)
		{
			bool value = checkBox.IsChecked.Value;
			DontShowMessageAgain = value;
		}

		private void Cancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
		}

		private void Rd_GotFocus(object sender, RoutedEventArgs e)
		{
			(sender as System.Windows.Controls.RadioButton).IsChecked = true;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/supernextdlg.xaml", UriKind.Relative);
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
				WinSuperNext = (SuperNextDlg)target;
				break;
			case 2:
				label1 = (System.Windows.Controls.Label)target;
				break;
			case 3:
				AesGroupBox = (AesGroupBox)target;
				break;
			case 4:
				stackRadios = (StackPanel)target;
				break;
			case 5:
				Rd0 = (System.Windows.Controls.RadioButton)target;
				Rd0.GotFocus += Rd_GotFocus;
				break;
			case 6:
				Rd1 = (System.Windows.Controls.RadioButton)target;
				Rd1.GotFocus += Rd_GotFocus;
				break;
			case 7:
				Rd2 = (System.Windows.Controls.RadioButton)target;
				Rd2.GotFocus += Rd_GotFocus;
				break;
			case 8:
				Rd3 = (System.Windows.Controls.RadioButton)target;
				Rd3.GotFocus += Rd_GotFocus;
				break;
			case 9:
				Rd4 = (System.Windows.Controls.RadioButton)target;
				Rd4.GotFocus += Rd_GotFocus;
				break;
			case 10:
				Rd5 = (System.Windows.Controls.RadioButton)target;
				Rd5.GotFocus += Rd_GotFocus;
				break;
			case 11:
				Rd6 = (System.Windows.Controls.RadioButton)target;
				Rd6.GotFocus += Rd_GotFocus;
				break;
			case 12:
				OK = (System.Windows.Controls.Button)target;
				OK.Click += BtnOK_Click;
				break;
			case 13:
				Cancel = (System.Windows.Controls.Button)target;
				Cancel.Click += Cancel_Click;
				break;
			case 14:
				ChkBox_DontShow = (System.Windows.Controls.CheckBox)target;
				ChkBox_DontShow.Checked += ChkBoxDontShow_CheckedChanged;
				ChkBox_DontShow.Unchecked += ChkBoxDontShow_UnCheckedChanged;
				break;
			case 15:
				LblTitle = (System.Windows.Controls.Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class HierarchyTreeViewItemViewModel : INotifyPropertyChanged
	{
		private string m_strName;

		private string m_strHierarchyID;

		private bool m_bIsExpanded;

		private bool m_bIsSelected;

		private ObservableCollection<HierarchyTreeViewItemViewModel> m_Children = new ObservableCollection<HierarchyTreeViewItemViewModel>();

		public string Name
		{
			get
			{
				return m_strName;
			}
			set
			{
				m_strName = value;
			}
		}

		public string HierarchyID => m_strHierarchyID;

		public bool IsExpanded
		{
			get
			{
				return m_bIsExpanded;
			}
			set
			{
				if (value != m_bIsExpanded)
				{
					m_bIsExpanded = value;
					OnPropertyChanged("IsExpanded");
					if (m_bIsExpanded && Parent != null)
					{
						Parent.IsExpanded = true;
					}
				}
			}
		}

		public bool IsSelected
		{
			get
			{
				return m_bIsSelected;
			}
			set
			{
				if (value != m_bIsSelected)
				{
					m_bIsSelected = value;
					OnPropertyChanged("IsSelected");
				}
			}
		}

		public HierarchyTreeViewItemViewModel Parent { get; set; }

		public ObservableCollection<HierarchyTreeViewItemViewModel> Children
		{
			get
			{
				return m_Children;
			}
			set
			{
				m_Children = value;
			}
		}

		public bool IsLeafNode => Children.Count == 0;

		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string strPropertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(strPropertyName));
			}
		}

		public HierarchyTreeViewItemViewModel(string strName, HierarchyTreeViewItemViewModel tvmParent = null)
		{
			m_strName = strName;
			Parent = tvmParent;
			m_strHierarchyID = strName;
			if (Parent != null)
			{
				m_strHierarchyID = Parent.HierarchyID + "." + m_strName;
			}
		}
	}
	public class Type2Dlg : Window, IComponentConnector
	{
		private List<string> typeList = new List<string>();

		private List<string> localizedTypelist = new List<string>();

		internal System.Windows.Controls.ComboBox cboType2;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public Type2Dlg()
		{
			InitializeComponent();
			string ptype;
			for (int i = 0; MmgSor.EVlsttp2M(i, out ptype) != 0; i++)
			{
				typeList.Add(ptype);
			}
			typeList.Sort();
			foreach (string type in typeList)
			{
				string localizedType = GetLocalizedType("type_" + type, type);
				localizedTypelist.Add(localizedType);
			}
			foreach (string item in localizedTypelist)
			{
				cboType2.Items.Add(item);
			}
			btnOK.IsEnabled = false;
		}

		private string GetLocalizedType(string key, string defaultValue)
		{
			string text = string.Empty;
			if (!string.IsNullOrEmpty(key))
			{
				string name = Regex.Replace(key, "[^a-zA-Z0-9]", "_").ToLower();
				text = ApwnRecTypeResource.ResourceManager.GetString(name, ApwnRecTypeResource.Culture);
			}
			if (!string.IsNullOrEmpty(text))
			{
				return text;
			}
			return defaultValue;
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			bool value = false;
			if (cboType2.SelectedItem != null)
			{
				string text = cboType2.SelectedItem.ToString();
				if (!string.IsNullOrEmpty(text))
				{
					int num = localizedTypelist.IndexOf(text);
					if (num != -1)
					{
						MmgSor.EVclstp2M(typeList[num]);
					}
					else
					{
						MmgSor.EVclstp2M(text);
					}
					value = true;
				}
			}
			base.DialogResult = value;
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void cboType2_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (cboType2.SelectedIndex >= 0)
			{
				btnOK.IsEnabled = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMDialogs;component/type2dlg.xaml", UriKind.Relative);
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
				cboType2 = (System.Windows.Controls.ComboBox)target;
				cboType2.SelectionChanged += cboType2_SelectionChanged;
				break;
			case 2:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 3:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMDialogs.Modules.Dialogs
{
	[Module(ModuleName = "AspenTech.AspenPlus.MMDialogs.Modules.Dialog.DialogsModule")]
	public class DialogsModule : IModule
	{
		public const string ModuleName = "AspenTech.AspenPlus.MMDialogs.Modules.Dialog.DialogsModule";

		internal static IUnityContainer Container { get; private set; }

		public DialogsModule(IUnityContainer container)
		{
			Container = container;
		}

		public void Initialize()
		{
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000006 XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x0600003e AspenTech.AspenPlus.MMDialogs.ColumnHXIntegrationDlgViewModel.add_PropertyChanged
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

// 0x0600003f AspenTech.AspenPlus.MMDialogs.ColumnHXIntegrationDlgViewModel.remove_PropertyChanged
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

// 0x060000a0 AspenTech.AspenPlus.MMDialogs.RecTypeI18nHelper..ctor
// public RecTypeI18nHelper()
// {
// }

// 0x060000a1 AspenTech.AspenPlus.MMDialogs.RecTypeI18nHelper..cctor
// using System.Collections.Generic;
//
// static RecTypeI18nHelper()
// {
// 	RecordTypeDictionary = new Dictionary<string, string>
// 	{
// 		{ "material", "rectype_streams_material" },
// 		{ "heat", "rectype_streams_heat" },
// 		{ "work", "rectype_streams_work" },
// 		{ "generic", "rectype_analysis_generic" },
// 		{ "ptenvelope", "rectype_analysis_ptenvelope" },
// 		{ "residue", "rectype_analysis_residue" },
// 		{ "terdiagram", "rectype_analysis_terdiagram" },
// 		{ "assay", "rectype_assay_blend_assay" },
// 		{ "blend", "rectype_assay_blend_blend" },
// 		{ "broyden", "rectype_convergence_broyden" },
// 		{ "complex", "rectype_convergence_complex" },
// 		{ "direct", "rectype_convergence_direct" },
// 		{ "newton", "rectype_convergence_newton" },
// 		{ "secant", "rectype_convergence_secant" },
// 		{ "sqp", "rectype_convergence_sqp" },
// 		{ "wegstein", "rectype_convergence_wegstein" },
// 		{ "mixture", "rectype_data_mixture" },
// 		{ "pure-comp", "rectype_data_pure_comp" },
// 		{ "point-data", "rectype_data_set_point_data" },
// 		{ "profile-data", "rectype_data_set_profile_data" },
// 		{ "custom", "rectype_objective_custom" },
// 		{ "linear", "rectype_objective_linear" },
// 		{ "sumofsquares", "rectype_objective_sumofsquares" },
// 		{ "emulsion", "rectype_reactions_emulsion" },
// 		{ "free-rad", "rectype_reactions_free_rad" },
// 		{ "general", "rectype_reactions_general" },
// 		{ "ionic", "rectype_reactions_ionic" },
// 		{ "lhhw", "rectype_reactions_lhhw" },
// 		{ "powerlaw", "rectype_reactions_powerlaw" },
// 		{ "reac-dist", "rectype_reactions_reac_dist" },
// 		{ "segment-bas", "rectype_reactions_segment_bas" },
// 		{ "step-growth", "rectype_reactions_step_growth" },
// 		{ "user", "rectype_reactions_user" },
// 		{ "useracm", "rectype_reactions_useracm" },
// 		{ "ziegler-nat", "rectype_reactions_ziegler_nat" },
// 		{ "constraint", "rectype_model_analysis_constraint" },
// 		{ "optimization", "rectype_model_analysis_optimization" },
// 		{ "regression", "rectype_model_analysis_regression" },
// 		{ "nc-params", "rectype__nc_params" },
// 		{ "pair", "rectype__pair" },
// 		{ "scalar", "rectype__scalar" },
// 		{ "t-dependent", "rectype__t_dependent" },
// 		{ "unifac-group", "rectype__unifac_group" }
// 	};
// }

// 0x060000a2 AspenTech.AspenPlus.MMDialogs.CopyMarkDlgViewModel.add_PropertyChanged
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

// 0x060000a3 AspenTech.AspenPlus.MMDialogs.CopyMarkDlgViewModel.remove_PropertyChanged
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

// 0x060000cc AspenTech.AspenPlus.MMDialogs.CopyMarkDlg..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static CopyMarkDlg()
// {
// 	RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<CopyMarkDlgViewModel>), typeof(CopyMarkDlg));
// }

// 0x060000cf AspenTech.AspenPlus.MMDialogs.RecordNodeIsEnabledToVisibilityConverter..ctor
// public RecordNodeIsEnabledToVisibilityConverter()
// {
// }

// 0x06000137 AspenTech.AspenPlus.MMDialogs.DialogDriver..ctor
// public DialogDriver()
// {
// }

// 0x06000161 AspenTech.AspenPlus.MMDialogs.DontAskMB.add_PropertyChanged
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

// 0x06000162 AspenTech.AspenPlus.MMDialogs.DontAskMB.remove_PropertyChanged
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

// 0x0600016d AspenTech.AspenPlus.MMDialogs.DontAskMB..cctor
// using AspenTech.AspenPlus.Localization;
//
// static DontAskMB()
// {
// 	ButtonGroups = new int[6, 4]
// 	{
// 		{ 1, 0, 0, 9 },
// 		{ 1, 2, 0, 9 },
// 		{ 3, 4, 5, 9 },
// 		{ 6, 7, 2, 9 },
// 		{ 6, 7, 0, 9 },
// 		{ 4, 2, 0, 9 }
// 	};
// 	ButtonNumberOfGroup = new int[6] { 1, 2, 3, 3, 2, 2 };
// 	szRetStrings = new string[9]
// 	{
// 		WpfMMDialogResources.Unknown,
// 		WpfMMDialogResources.Ok,
// 		WpfMMDialogResources.Help,
// 		WpfMMDialogResources.Cancel,
// 		WpfMMDialogResources.Abort,
// 		WpfMMDialogResources.Retry,
// 		WpfMMDialogResources.Ignore,
// 		WpfMMDialogResources.Yes,
// 		WpfMMDialogResources.No
// 	};
// 	szRetStrings2 = new string[9]
// 	{
// 		WpfMMDialogResources.Unknown,
// 		WpfMMDialogResources._Ok,
// 		WpfMMDialogResources._Help,
// 		WpfMMDialogResources._Cancel,
// 		WpfMMDialogResources._Abort,
// 		WpfMMDialogResources._Retry,
// 		WpfMMDialogResources._Ignore,
// 		WpfMMDialogResources._Yes,
// 		WpfMMDialogResources._No
// 	};
// }

// 0x06000174 AspenTech.AspenPlus.MMDialogs.EditIDdlg.add_PropertyChanged
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

// 0x06000175 AspenTech.AspenPlus.MMDialogs.EditIDdlg.remove_PropertyChanged
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

// 0x06000181 AspenTech.AspenPlus.MMDialogs.EditLabel.add_PropertyChanged
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

// 0x06000182 AspenTech.AspenPlus.MMDialogs.EditLabel.remove_PropertyChanged
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

// 0x06000194 AspenTech.AspenPlus.MMDialogs.ExportHierarchyTreeViewModel.add_PropertyChanged
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

// 0x06000195 AspenTech.AspenPlus.MMDialogs.ExportHierarchyTreeViewModel.remove_PropertyChanged
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

// 0x060001c2 AspenTech.AspenPlus.MMDialogs.ExportHierarchyTree..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static ExportHierarchyTree()
// {
// 	RootNodesProperty = DependencyProperty.Register("RootNodes", typeof(IEnumerable<ExportHierarchyTreeViewModel>), typeof(ExportHierarchyTree));
// }

// 0x060001cc AspenTech.AspenPlus.MMDialogs.FileInputBox.add_FileNameChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<EventArgs> eventHandler = this.FileNameChanged;
// 	EventHandler<EventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<EventArgs> value2 = (EventHandler<EventArgs>)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.FileNameChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060001cd AspenTech.AspenPlus.MMDialogs.FileInputBox.remove_FileNameChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<EventArgs> eventHandler = this.FileNameChanged;
// 	EventHandler<EventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<EventArgs> value2 = (EventHandler<EventArgs>)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.FileNameChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060001d0 AspenTech.AspenPlus.MMDialogs.FileInputBox..cctor
// using System.Windows;
//
// static FileInputBox()
// {
// 	FilterProperty = DependencyProperty.Register("Filter", typeof(string), typeof(FileInputBox), new PropertyMetadata(null));
// 	FileOpenDlgType = DependencyProperty.Register("DlgType", typeof(int), typeof(FileInputBox), new PropertyMetadata(null));
// }

// 0x060001d3 AspenTech.AspenPlus.MMDialogs.FindVariableDlg.add_PropertyChanged
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

// 0x060001d4 AspenTech.AspenPlus.MMDialogs.FindVariableDlg.remove_PropertyChanged
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

// 0x060001ea AspenTech.AspenPlus.MMDialogs.FileTypeConverter..ctor
// public FileTypeConverter()
// {
// }

// 0x06000209 AspenTech.AspenPlus.MMDialogs.MoveToItemImageConvert..ctor
// public MoveToItemImageConvert()
// {
// }

// 0x06000215 AspenTech.AspenPlus.MMDialogs.MMLogger..ctor
// public MMLogger()
// {
// }

// 0x0600023e AspenTech.AspenPlus.MMDialogs.WizardContainer..cctor
// using System.Windows;
//
// static WizardContainer()
// {
// 	CanPrevProperty = DependencyProperty.Register("CanPrev", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	CanNextProperty = DependencyProperty.Register("CanNext", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	ContainerParentProperty = DependencyProperty.Register("ContainerParent", typeof(UIElement), typeof(WizardContainer), new PropertyMetadata(null));
// }

// 0x0600024d AspenTech.AspenPlus.MMDialogs.WizardPage..ctor
// public WizardPage()
// {
// }

// 0x06000250 AspenTech.AspenPlus.MMDialogs.WizardPage..cctor
// using System.Windows;
//
// static WizardPage()
// {
// 	CanNextProperty = DependencyProperty.Register("CanNext", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));
// 	CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));
// 	CanPrevProperty = DependencyProperty.Register("CanPrev", typeof(bool), typeof(WizardPage), new PropertyMetadata(true));
// 	ContainerParentProperty = DependencyProperty.Register("ContainerParent", typeof(UIElement), typeof(WizardPage), new PropertyMetadata(null));
// 	ContainerProperty = DependencyProperty.Register("Container", typeof(WizardContainer), typeof(WizardPage), new PropertyMetadata(null));
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(WizardPage), new PropertyMetadata(null));
// }

// 0x06000268 AspenTech.AspenPlus.MMDialogs.IDBoxDlg.add_PropertyChanged
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

// 0x06000269 AspenTech.AspenPlus.MMDialogs.IDBoxDlg.remove_PropertyChanged
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

// 0x06000276 AspenTech.AspenPlus.MMDialogs.IDBoxDlg2.add_PropertyChanged
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

// 0x06000277 AspenTech.AspenPlus.MMDialogs.IDBoxDlg2.remove_PropertyChanged
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

// 0x0600028f AspenTech.AspenPlus.MMDialogs.MessageBox..ctor
// public MessageBox()
// {
// }

// 0x06000294 AspenTech.AspenPlus.MMDialogs.MessageBoxEx..ctor
// public MessageBoxEx()
// {
// }

// 0x060002a5 AspenTech.AspenPlus.MMDialogs.MoveToDlg.add_PropertyChanged
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

// 0x060002a6 AspenTech.AspenPlus.MMDialogs.MoveToDlg.remove_PropertyChanged
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

// 0x060002bf AspenTech.AspenPlus.MMDialogs.RadioBoolToIntConverter..ctor
// public RadioBoolToIntConverter()
// {
// }

// 0x060002c6 AspenTech.AspenPlus.MMDialogs.OpenMessageBox.add_PropertyChanged
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

// 0x060002c7 AspenTech.AspenPlus.MMDialogs.OpenMessageBox.remove_PropertyChanged
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

// 0x060002dd AspenTech.AspenPlus.MMDialogs.ParamVal.add_PropertyChanged
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

// 0x060002de AspenTech.AspenPlus.MMDialogs.ParamVal.remove_PropertyChanged
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

// 0x06000312 AspenTech.AspenPlus.MMDialogs.NameI18nConvertor..ctor
// public NameI18nConvertor()
// {
// }

// 0x06000314 AspenTech.AspenPlus.MMDialogs.NodePathI18nHelper..ctor
// public NodePathI18nHelper()
// {
// }

// 0x0600031a AspenTech.AspenPlus.MMDialogs.ResolveStreamEOName.add_PropertyChanged
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

// 0x0600031b AspenTech.AspenPlus.MMDialogs.ResolveStreamEOName.remove_PropertyChanged
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

// 0x0600033d AspenTech.AspenPlus.MMDialogs.StreamEoItem.add_PropertyChanged
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

// 0x0600033e AspenTech.AspenPlus.MMDialogs.StreamEoItem.remove_PropertyChanged
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

// 0x06000340 AspenTech.AspenPlus.MMDialogs.StreamEoItem..ctor
// public StreamEoItem()
// {
// }

// 0x06000344 AspenTech.AspenPlus.MMDialogs.ShowFileDlgViewModel..ctor
// using System.Windows;
//
// public ShowFileDlgViewModel()
// {
// 	_canCancel = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000352 AspenTech.AspenPlus.MMDialogs.ShowFileDlgViewModel.add_PropertyChanged
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

// 0x06000353 AspenTech.AspenPlus.MMDialogs.ShowFileDlgViewModel.remove_PropertyChanged
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

// 0x06000356 AspenTech.AspenPlus.MMDialogs.ShowFlowsheetIncompleteDlgViewModel..ctor
// public ShowFlowsheetIncompleteDlgViewModel()
// {
// }

// 0x06000358 AspenTech.AspenPlus.MMDialogs.ShowTFFProcessingErrorViewModel..ctor
// public ShowTFFProcessingErrorViewModel()
// {
// }

// 0x0600035a AspenTech.AspenPlus.MMDialogs.ShowReadBackupFileErrorViewModel..ctor
// public ShowReadBackupFileErrorViewModel()
// {
// }

// 0x0600035c AspenTech.AspenPlus.MMDialogs.ShowInputSummaryErrorViewModel..ctor
// public ShowInputSummaryErrorViewModel()
// {
// }

// 0x0600035e AspenTech.AspenPlus.MMDialogs.SpeedupExportDialogViewModel..ctor
// public SpeedupExportDialogViewModel()
// {
// }

// 0x06000361 AspenTech.AspenPlus.MMDialogs.ShowEOErrorDlgViewModel..ctor
// public ShowEOErrorDlgViewModel()
// {
// }

// 0x06000364 AspenTech.AspenPlus.MMDialogs.ShowMoveErrorDlgViewModel..ctor
// public ShowMoveErrorDlgViewModel()
// {
// }

// 0x06000379 AspenTech.AspenPlus.MMDialogs.SuperNextDlg..cctor
// using System.Windows;
//
// static SuperNextDlg()
// {
// 	DontShowMessageAgainProperty = DependencyProperty.Register("DontShowMessageAgain", typeof(bool), typeof(SuperNextDlg), new FrameworkPropertyMetadata(false, null));
// }

// 0x0600037a AspenTech.AspenPlus.MMDialogs.HierarchyTreeViewItemViewModel.add_PropertyChanged
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

// 0x0600037b AspenTech.AspenPlus.MMDialogs.HierarchyTreeViewItemViewModel.remove_PropertyChanged
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

// 0x0600039d AspenTech.AspenPlus.MMDialogs.ACMModelConflictsDlg+ACMModelConflict..ctor
// public ACMModelConflict()
// {
// }

// 0x0600039e AspenTech.AspenPlus.MMDialogs.AssayLibraryWait+SECURITY_ATTRIBUTES..ctor
// public SECURITY_ATTRIBUTES()
// {
// }

// 0x060003a3 AspenTech.AspenPlus.MMDialogs.ControlVariableListDialog+ControlVariable..ctor
// public ControlVariable()
// {
// }

// 0x060003a4 AspenTech.AspenPlus.MMDialogs.CopyMarkDlgViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003a5 AspenTech.AspenPlus.MMDialogs.CopyMarkDlgViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x060003bd AspenTech.AspenPlus.MMDialogs.ConvertDlg+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003be AspenTech.AspenPlus.MMDialogs.ConvertDlg+<>c..ctor
// public <>c()
// {
// }

// 0x060003c0 AspenTech.AspenPlus.MMDialogs.ExportHierarchyTreeViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003c1 AspenTech.AspenPlus.MMDialogs.ExportHierarchyTreeViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x060003d9 AspenTech.AspenPlus.MMDialogs.ResultsInconsistentDlg+<>c__DisplayClass7_0..ctor
// public <>c__DisplayClass7_0()
// {
// }

// 0x060003db AspenTech.AspenPlus.MMDialogs.OpenMessageBox+<>c__DisplayClass23_0..ctor
// public <>c__DisplayClass23_0()
// {
// }

// 0x060003e1 AspenTech.AspenPlus.MMDialogs.ResolveConflictsDlg+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003e2 AspenTech.AspenPlus.MMDialogs.ResolveConflictsDlg+<>c..ctor
// public <>c()
// {
// }
