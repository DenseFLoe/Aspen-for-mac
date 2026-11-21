using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
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
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xml.Serialization;
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Infrastructure.MvvmCore;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.Scripting;
using AspenTech.AspenPlus.Simulation;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Visualisation.CommonShell;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.WpfSimdll")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("Aspen Plus")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, INC. 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("9684c51b-5346-4cc8-872f-27cfe2711914")]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
public class SimConnectDlgViewModel : INotifyPropertyChanged
{
	private ObservableCollection<ServerTypeItem> _serverTypeList = new ObservableCollection<ServerTypeItem>();

	private int _selectedServerTypeIndex;

	private string _nodeName;

	private string _userName;

	private string _password;

	private string _workingDir;

	private bool _isControlEnabled = true;

	private Visibility _saveDefaultVisibility;

	private bool _isSaveDefault;

	private string _cancelButtonText;

	private bool _bCancelToExit;

	private string _regServerType;

	private string _regNodeName;

	private string _regUserName;

	private string _regWorkDir;

	private int _localHostIndex;

	private int _regCsest = -1;

	private string _restoreServerData = "";

	private string _curNodeName;

	private string _curUserName;

	private string _curPassword;

	private string _curWorkingDir;

	private int _curCsect;

	private ICommand _OKCommand;

	private ICommand _cancelCommand;

	public string HelpFile
	{
		get
		{
			if (MMVersionHelper.MVIsAspenplus())
			{
				return "userguide1.chm";
			}
			return "apr-ug1.chm";
		}
	}

	public ObservableCollection<ServerTypeItem> ServerTypeList => _serverTypeList;

	public int SelectedServerTypeIndex
	{
		get
		{
			return _selectedServerTypeIndex;
		}
		set
		{
			_selectedServerTypeIndex = value;
			OnPropertyChanged("SelectedServerTypeIndex");
			OnServerSelChange();
		}
	}

	public string NodeName
	{
		get
		{
			return _nodeName;
		}
		set
		{
			_nodeName = value;
			OnPropertyChanged("NodeName");
		}
	}

	public string UserName
	{
		get
		{
			return _userName;
		}
		set
		{
			_userName = value;
			OnPropertyChanged("UserName");
		}
	}

	public string Password
	{
		get
		{
			return _password;
		}
		set
		{
			_password = value;
			OnPropertyChanged("Password");
		}
	}

	public string WorkingDir
	{
		get
		{
			return _workingDir;
		}
		set
		{
			_workingDir = value;
			OnPropertyChanged("WorkingDir");
		}
	}

	public bool IsControlEnabled
	{
		get
		{
			return _isControlEnabled;
		}
		set
		{
			_isControlEnabled = value;
			OnPropertyChanged("IsControlEnabled");
		}
	}

	public Visibility SaveDefaultVisibility
	{
		get
		{
			return _saveDefaultVisibility;
		}
		set
		{
			_saveDefaultVisibility = value;
			OnPropertyChanged("SaveDefaultVisibility");
		}
	}

	public bool IsSaveDefault
	{
		get
		{
			return _isSaveDefault;
		}
		set
		{
			_isSaveDefault = value;
			OnPropertyChanged("IsSaveDefault");
		}
	}

	public string CancelButtonText
	{
		get
		{
			return _cancelButtonText;
		}
		set
		{
			_cancelButtonText = value;
			OnPropertyChanged("CancelButtonText");
		}
	}

	public ICommand OKCommand
	{
		get
		{
			if (_OKCommand == null)
			{
				_OKCommand = new DelegateCommand<object>(OKCommand_Execute, OKCommand_CanExecuted);
			}
			return _OKCommand;
		}
	}

	public ICommand CancelCommand
	{
		get
		{
			if (_cancelCommand == null)
			{
				_cancelCommand = new DelegateCommand<object>(CancelCommand_Execute, CancelCommand_CanExecuted);
			}
			return _cancelCommand;
		}
	}

	public event PropertyChangedEventHandler PropertyChanged;

	public virtual void OnPropertyChanged(string propertyName)
	{
		PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
		if (propertyChangedEventHandler != null)
		{
			PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
			propertyChangedEventHandler(this, e);
		}
	}

	[DllImport("sbsim.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Auto, ExactSpelling = true)]
	public static extern int SBgetcsect(int num, ref string name, ref string desc, ref int isdefault, ref int local);

	public SimConnectDlgViewModel()
	{
		GetRegistryValue();
		if (!_bCancelToExit)
		{
			GetCurrentValue();
		}
		int num = -1;
		string name = string.Empty;
		string desc = string.Empty;
		int isdefault = 0;
		int local = 0;
		int num2 = 0;
		while ((num = SimHelper.SBgetcsectM(num, out name, out desc, out isdefault, out local)) != -1)
		{
			ServerTypeItem item = new ServerTypeItem
			{
				Name = name,
				Description = desc
			};
			ServerTypeList.Add(item);
			if (isdefault != 0)
			{
				_curCsect = num2;
			}
			if (local != 0)
			{
				_localHostIndex = num2;
			}
			if (!string.IsNullOrEmpty(_regServerType) && desc != _regServerType)
			{
				_regCsest = num2;
			}
		}
		if (ServerTypeList.Count > 0)
		{
			if (!RestoreConnectionData())
			{
				if (_regCsest == -1)
				{
					SelectedServerTypeIndex = _curCsect;
				}
				else
				{
					SelectedServerTypeIndex = _regCsest;
				}
			}
		}
		else
		{
			IsControlEnabled = false;
		}
		if (_bCancelToExit)
		{
			CancelButtonText = WpfSimdllResources.Exit;
		}
		else
		{
			CancelButtonText = WpfSimdllResources.Cancel;
		}
	}

	private void GetRegistryValue()
	{
		_regServerType = SimHelper.GetSettingStringValue("servertype", 0);
		_regNodeName = SimHelper.GetSettingStringValue("servername", 0);
		_regUserName = SimHelper.GetSettingStringValue("username", 0);
		_regWorkDir = SimHelper.GetSettingStringValue("workingdir", 0);
	}

	private bool RestoreConnectionData()
	{
		if (string.IsNullOrEmpty(_restoreServerData))
		{
			return false;
		}
		int count = ServerTypeList.Count;
		for (int i = 0; i < count; i++)
		{
			if (_restoreServerData == ServerTypeList[i].Name)
			{
				SelectedServerTypeIndex = i;
				SetCurrentValue();
				if (i == _localHostIndex)
				{
					IsControlEnabled = false;
				}
				else
				{
					IsControlEnabled = true;
				}
				return true;
			}
		}
		return false;
	}

	private void SetCurrentValue()
	{
		NodeName = _curNodeName;
		UserName = _curUserName;
		Password = _curPassword;
		WorkingDir = _curWorkingDir;
	}

	private void GetCurrentValue()
	{
		_curNodeName = SimHelper.SBgethvrM("NODENAME");
		if (!string.IsNullOrEmpty(_curNodeName))
		{
			_curUserName = SimHelper.SBgethvrM("LOGONNAME");
			if (!string.IsNullOrEmpty(_curUserName))
			{
				_curPassword = SimHelper.SBgethvrM("PASSWORD");
				_curWorkingDir = SimHelper.SBgetinterdirM();
			}
		}
	}

	private void OnServerSelChange()
	{
		SaveDefaultVisibility = Visibility.Visible;
		if (SelectedServerTypeIndex == _regCsest)
		{
			SetRegistryValue();
			SaveDefaultVisibility = Visibility.Collapsed;
		}
		else if (SelectedServerTypeIndex == _curCsect)
		{
			SetCurrentValue();
		}
		else
		{
			ResetAllValue();
		}
		if (SelectedServerTypeIndex == _localHostIndex)
		{
			IsControlEnabled = false;
		}
		else
		{
			IsControlEnabled = true;
		}
	}

	private void SetRegistryValue()
	{
		NodeName = _regNodeName;
		UserName = _regUserName;
		if (_regCsest == _curCsect && _regNodeName == _curNodeName && _regUserName == _curUserName)
		{
			Password = _curPassword;
		}
		else
		{
			Password = "";
		}
		WorkingDir = _regWorkDir;
	}

	private void ResetAllValue()
	{
		NodeName = "";
		UserName = "";
		Password = "";
		WorkingDir = "";
	}

	private bool OKCommand_CanExecuted(object args)
	{
		return true;
	}

	private void OKCommand_Execute(object args)
	{
		Window window = args as Window;
		window.Cursor = System.Windows.Input.Cursors.Wait;
		if (SimHelper.SimStartRunM(SelectedServerTypeIndex, NodeName, UserName, Password, WorkingDir) == 0)
		{
			if (SaveDefaultVisibility == Visibility.Visible && IsSaveDefault)
			{
				SaveSettingValues(1);
			}
			else
			{
				SaveSettingValues(0);
			}
			window.DialogResult = true;
			window.Close();
		}
		window.Cursor = System.Windows.Input.Cursors.Arrow;
	}

	private void SaveSettingValues(int saveinregistry)
	{
		DontAskAgain.SetSettingStringValue("servertype", ServerTypeList[SelectedServerTypeIndex].Description, saveinregistry, 0, IntPtr.Zero);
		DontAskAgain.SetSettingStringValue("servername", NodeName, saveinregistry, 0, IntPtr.Zero);
		DontAskAgain.SetSettingStringValue("username", UserName, saveinregistry, 0, IntPtr.Zero);
		DontAskAgain.SetSettingStringValue("workingdir", WorkingDir, saveinregistry, 0, IntPtr.Zero);
	}

	private bool CancelCommand_CanExecuted(object args)
	{
		return true;
	}

	private void CancelCommand_Execute(object args)
	{
		if (args is Window window)
		{
			window.Close();
		}
	}
}
public class ServerTypeItem
{
	public string Name { get; set; }

	public string Description { get; set; }
}
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
namespace AspenTech.AspenPlus.Simulation
{
	public static class SimulationStatus
	{
		public static readonly SimulationStatusEnum REFRESH = new SimulationStatusEnum("IDS_SIMMSG_REFRESH", 471u);

		public static readonly SimulationStatusEnum REQUIRED_INPUT_INCOMPLETE = new SimulationStatusEnum("IDS_STATUS_RequiredInputIncomplete", 1909u);

		public static readonly SimulationStatusEnum REQUIRED_PROPERTIES_INPUT_COMPLETE = new SimulationStatusEnum("IDS_STATUS_RequiredPropertiesInputComplete", 1921u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE = new SimulationStatusEnum("IDS_STATUS_ResultsAvailable", 1912u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE_WITH_WARNINGS = new SimulationStatusEnum("IDS_STATUS_ResultsAvailableWithWarnings", 1913u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE_WITH_ERRORS = new SimulationStatusEnum("IDS_STATUS_ResultsAvailableWithErrors", 1914u);

		public static readonly SimulationStatusEnum INPUT_CHANGED = new SimulationStatusEnum("IDS_STATUS_InputChanged", 1911u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE_WITH_ERRORS_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS4", 1449u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE_WITH_WARNINGS_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS5", 1450u);

		public static readonly SimulationStatusEnum RESULTS_AVAILABLE_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS6", 1451u);
	}
	public class SimulationStatusEnum
	{
		private SORRes _resourcesManager = new SORRes();

		private string _localized;

		public uint Id { get; private set; }

		public string Name { get; private set; }

		public string Localized
		{
			get
			{
				string obj = _localized ?? _resourcesManager.GetString(Id);
				string result = obj;
				_localized = obj;
				return result;
			}
		}

		internal SimulationStatusEnum(string name, uint id)
		{
			Name = name;
			Id = id;
		}

		public override bool Equals(object obj)
		{
			if (obj is SimulationStatusEnum simulationStatusEnum)
			{
				if (string.Equals(Localized, simulationStatusEnum.Localized, StringComparison.InvariantCultureIgnoreCase))
				{
					return object.Equals(Id, simulationStatusEnum.Id);
				}
				return false;
			}
			if (obj is string b)
			{
				return string.Equals(Localized, b, StringComparison.InvariantCultureIgnoreCase);
			}
			if (obj is int num)
			{
				return object.Equals(Id, num);
			}
			return false;
		}

		public override string ToString()
		{
			return Localized;
		}

		public override int GetHashCode()
		{
			return (int)Id;
		}
	}
	public class SimulationStatusView
	{
		public string StatusText { get; set; } = string.Empty;

		public Brush Background { get; set; } = Brushes.Transparent;

		internal SimulationStatusView()
		{
		}
	}
	public static class SimulationStatusViewBuilder
	{
		private class Status
		{
			public readonly int StatusCode;

			public readonly string KeyWord;

			public readonly string Message;

			public readonly Brush ColorBrush;

			public Status(int pStatusCode, string pKeyWord, string pMessage, Brush pColorBrush)
			{
				KeyWord = pKeyWord;
				StatusCode = pStatusCode;
				Message = pMessage;
				ColorBrush = pColorBrush;
			}
		}

		private static readonly List<Status> StatusList = new List<Status>
		{
			new Status(0, "Warnings", "Simulation Completed with Warnings", new SolidColorBrush(Color.FromRgb(byte.MaxValue, byte.MaxValue, 0))),
			new Status(1, "Failed", "Simulation Failed", new SolidColorBrush(Color.FromRgb(byte.MaxValue, 80, 84))),
			new Status(2, "Available", "Results Available", Brushes.Transparent),
			new Status(3, "Changed", "Required Input Changed", new SolidColorBrush(Colors.Yellow)),
			new Status(4, "Incomplete", "Required Input Incomplete", new SolidColorBrush(Color.FromRgb(byte.MaxValue, 43, 43))),
			new Status(5, "completed", "Run Completed", Brushes.Transparent)
		};

		public static SimulationStatusView Build(string message)
		{
			SimulationStatusView simulationStatusView = new SimulationStatusView();
			foreach (Status status in StatusList)
			{
				if (message.Contains(status.KeyWord))
				{
					simulationStatusView.StatusText = status.Message;
					simulationStatusView.Background = status.ColorBrush;
					break;
				}
			}
			return simulationStatusView;
		}

		public static Brush GetBrush(int status_code)
		{
			Brush transparent = Brushes.Transparent;
			Status status = StatusList.FirstOrDefault((Status status2) => status2.StatusCode == status_code);
			if (status == null)
			{
				return transparent;
			}
			return status.ColorBrush;
		}
	}
}
namespace AspenTech.AspenPlus.WpfSimdll
{
	internal class CheckBoxThreeStateCvt : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is ApwnSimBlockItems { Items: not null } apwnSimBlockItems && apwnSimBlockItems.Items.Count > 0)
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
	public class ControlPaneFindNodeDlg : Window, INotifyPropertyChanged, IComponentConnector
	{
		private IEnumerable<string> BaseNodeData;

		private ObservableCollection<string> _nodes;

		private string _searchText;

		private string _selectedName = string.Empty;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		internal System.Windows.Controls.TreeView tree1;

		private bool _contentLoaded;

		public ObservableCollection<string> Nodes
		{
			get
			{
				return _nodes;
			}
			private set
			{
				if (_nodes != value)
				{
					_nodes = value;
					OnPropertyChanged("Nodes");
				}
			}
		}

		public string SearchText
		{
			get
			{
				return _searchText;
			}
			set
			{
				if (_searchText != value)
				{
					_searchText = value;
					OnSearchTextChanged(value);
					OnPropertyChanged("SearchText");
				}
			}
		}

		public string SelectedName
		{
			get
			{
				return _selectedName;
			}
			set
			{
				_selectedName = value;
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

		public ControlPaneFindNodeDlg(IEnumerable<string> vNodes)
		{
			InitializeComponent();
			base.DataContext = this;
			BaseNodeData = vNodes;
			if (BaseNodeData == null)
			{
				BaseNodeData = new List<string>();
			}
			Initial(vNodes);
		}

		private void Initial(IEnumerable<string> vNodes)
		{
			_nodes = new ObservableCollection<string>();
			foreach (string vNode in vNodes)
			{
				_nodes.Add(vNode);
			}
		}

		private void OnSearchTextChanged(string searchText)
		{
			List<string> list = new List<string>();
			list = ((!string.IsNullOrEmpty(searchText)) ? BaseNodeData.Where((string p) => p.Contains(searchText)).ToList() : BaseNodeData.ToList());
			Nodes = new ObservableCollection<string>();
			foreach (string item in list)
			{
				Nodes.Add(item);
			}
		}

		private void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		private void ExecuteCommandOnOK(object arg)
		{
			SelectedName = tree1.SelectedItem.ToString();
			Close();
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			if (tree1.SelectedItem != null)
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			Close();
		}

		private void Tree1_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/controlpanefindnodedlg.xaml", UriKind.Relative);
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
				tree1 = (System.Windows.Controls.TreeView)target;
				tree1.SelectedItemChanged += Tree1_SelectedItemChanged;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public static class PasswordBoxHelper
	{
		public static readonly DependencyProperty PasswordProperty = DependencyProperty.RegisterAttached("Password", typeof(string), typeof(PasswordBoxHelper), new FrameworkPropertyMetadata("", OnPasswordPropertyChanged));

		public static readonly DependencyProperty IsUpdatingProperty = DependencyProperty.RegisterAttached("IsUpdating", typeof(bool), typeof(PasswordBoxHelper));

		public static readonly DependencyProperty AttachedProperty = DependencyProperty.RegisterAttached("Attached", typeof(bool), typeof(PasswordBoxHelper), new PropertyMetadata(false, OnAttachedPropertyChanged));

		public static void SetPassword(DependencyObject ele, string value)
		{
			ele.SetValue(PasswordProperty, value);
		}

		public static string GetPassword(DependencyObject ele)
		{
			return (string)ele.GetValue(PasswordProperty);
		}

		private static void OnPasswordPropertyChanged(DependencyObject sender, DependencyPropertyChangedEventArgs e)
		{
			PasswordBox passwordBox = sender as PasswordBox;
			passwordBox.PasswordChanged -= OnPasswordChanged;
			if (!GetIsUpdating(passwordBox))
			{
				passwordBox.Password = e.NewValue as string;
			}
			passwordBox.PasswordChanged += OnPasswordChanged;
		}

		private static void OnPasswordChanged(object sender, RoutedEventArgs e)
		{
			PasswordBox passwordBox = sender as PasswordBox;
			SetIsUpdating(passwordBox, value: true);
			SetPassword(passwordBox, passwordBox.Password);
			SetIsUpdating(passwordBox, value: false);
		}

		public static void SetIsUpdating(DependencyObject ele, bool value)
		{
			ele.SetValue(IsUpdatingProperty, value);
		}

		public static bool GetIsUpdating(DependencyObject ele)
		{
			return (bool)ele.GetValue(IsUpdatingProperty);
		}

		public static void SetAttached(DependencyObject ele, bool value)
		{
			ele.SetValue(AttachedProperty, value);
		}

		public static bool GetAttached(DependencyObject ele)
		{
			return (bool)ele.GetValue(AttachedProperty);
		}

		private static void OnAttachedPropertyChanged(DependencyObject sender, DependencyPropertyChangedEventArgs e)
		{
			if (sender is PasswordBox passwordBox)
			{
				if ((bool)e.OldValue)
				{
					passwordBox.PasswordChanged -= OnPasswordChanged;
				}
				if ((bool)e.NewValue)
				{
					passwordBox.PasswordChanged += OnPasswordChanged;
				}
			}
		}
	}
	[ProgId("WpfSimdll.RunSettingsDlgAP")]
	public class RunSettingsDlgAP : Window, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(ApwnRunSettingsDlgViewModel), typeof(RunSettingsDlgAP), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal System.Windows.Controls.TabControl tc_RunSettings;

		internal TabItem tb_EngineFiles;

		internal System.Windows.Controls.GroupBox gb_UserLibraries;

		internal System.Windows.Controls.Label lb_Insert;

		internal System.Windows.Controls.TextBox txt_Insert;

		internal System.Windows.Controls.Button btn_Insert;

		internal System.Windows.Controls.GroupBox gb_Miscellaneous_Files;

		internal System.Windows.Controls.Label lb_LinkerOptions;

		internal System.Windows.Controls.TextBox txt_LinkerOptions;

		internal System.Windows.Controls.Button btn_Linker;

		internal System.Windows.Controls.Label lb_RunDefinitions;

		internal System.Windows.Controls.TextBox txt_RunDefinition;

		internal TabItem tb_Options;

		internal System.Windows.Controls.GroupBox gb_InputOptions;

		internal System.Windows.Controls.CheckBox chk_AllowRun;

		internal System.Windows.Controls.CheckBox chk_EditKeyword;

		internal System.Windows.Controls.Button btn_OK;

		internal System.Windows.Controls.Button btn_Cancel;

		internal System.Windows.Controls.Button btn_Apply;

		internal System.Windows.Controls.Button btn_Help;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public ApwnRunSettingsDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as ApwnRunSettingsDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer UnityContainer { get; set; }

		public string InitialTab { get; set; }

		public RunSettingsDlgAP()
		{
			InitializeComponent();
			base.ResizeMode = ResizeMode.NoResize;
			base.Loaded += RunSettingsDlgAP_Loaded;
		}

		private void RunSettingsDlgAP_Loaded(object sender, RoutedEventArgs e)
		{
			if (!string.IsNullOrEmpty(InitialTab) && InitialTab == "Run Settings")
			{
				tb_Options.IsSelected = true;
			}
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is RunSettingsDlgAP runSettingsDlgAP)
			{
				runSettingsDlgAP.DataContext = args.NewValue;
				if (args.NewValue != null)
				{
					((ApwnRunSettingsDlgViewModel)args.NewValue).View = runSettingsDlgAP;
				}
			}
		}

		private void OnLoaded(object sender, RoutedEventArgs e)
		{
		}

		private void tc_RunSettings_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			MMHelp.SetHelpId(this, 1145);
		}

		private string GetFileFromLinker(string caption)
		{
			string text;
			if (!string.IsNullOrEmpty(ViewModel.RemoteDirectory))
			{
				text = ViewModel.RemoteDirectory;
			}
			else
			{
				try
				{
					text = Directory.GetCurrentDirectory();
				}
				catch (Exception)
				{
					text = "";
				}
			}
			if (!Directory.Exists(text))
			{
				text = "C:\\";
			}
			Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
			openFileDialog.InitialDirectory = text;
			if (caption == WpfSimdllResources.LabelLinkeroptions)
			{
				openFileDialog.Filter = "(*.txt; *.dlopt; *.opt)|*.txt;*.dlopt;*.opt";
			}
			else if (caption == WpfSimdllResources.LabelInsert)
			{
				openFileDialog.Filter = "(*.*; *.ilb)|*.*;*.ilb";
			}
			if (openFileDialog.ShowDialog() == true)
			{
				return text = openFileDialog.FileName;
			}
			return "";
		}

		private void btn_Insert_Click(object sender, RoutedEventArgs e)
		{
			string fileFromLinker = GetFileFromLinker(WpfSimdllResources.LabelInsert);
			if (!string.IsNullOrEmpty(fileFromLinker))
			{
				txt_Insert.Text = fileFromLinker;
			}
		}

		private void btn_Linker_Click(object sender, RoutedEventArgs e)
		{
			string fileFromLinker = GetFileFromLinker(WpfSimdllResources.LabelLinkeroptions);
			if (!string.IsNullOrEmpty(fileFromLinker))
			{
				txt_LinkerOptions.Text = fileFromLinker;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/runsettingsdlgap.xaml", UriKind.Relative);
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
				tc_RunSettings = (System.Windows.Controls.TabControl)target;
				tc_RunSettings.SelectionChanged += tc_RunSettings_SelectionChanged;
				break;
			case 2:
				tb_EngineFiles = (TabItem)target;
				break;
			case 3:
				gb_UserLibraries = (System.Windows.Controls.GroupBox)target;
				break;
			case 4:
				lb_Insert = (System.Windows.Controls.Label)target;
				break;
			case 5:
				txt_Insert = (System.Windows.Controls.TextBox)target;
				break;
			case 6:
				btn_Insert = (System.Windows.Controls.Button)target;
				btn_Insert.Click += btn_Insert_Click;
				break;
			case 7:
				gb_Miscellaneous_Files = (System.Windows.Controls.GroupBox)target;
				break;
			case 8:
				lb_LinkerOptions = (System.Windows.Controls.Label)target;
				break;
			case 9:
				txt_LinkerOptions = (System.Windows.Controls.TextBox)target;
				break;
			case 10:
				btn_Linker = (System.Windows.Controls.Button)target;
				btn_Linker.Click += btn_Linker_Click;
				break;
			case 11:
				lb_RunDefinitions = (System.Windows.Controls.Label)target;
				break;
			case 12:
				txt_RunDefinition = (System.Windows.Controls.TextBox)target;
				break;
			case 13:
				tb_Options = (TabItem)target;
				break;
			case 14:
				gb_InputOptions = (System.Windows.Controls.GroupBox)target;
				break;
			case 15:
				chk_AllowRun = (System.Windows.Controls.CheckBox)target;
				break;
			case 16:
				chk_EditKeyword = (System.Windows.Controls.CheckBox)target;
				break;
			case 17:
				btn_OK = (System.Windows.Controls.Button)target;
				break;
			case 18:
				btn_Cancel = (System.Windows.Controls.Button)target;
				break;
			case 19:
				btn_Apply = (System.Windows.Controls.Button)target;
				break;
			case 20:
				btn_Help = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ShowBlockTempDlgViewModel : INotifyPropertyChanged
	{
		private string _selectedClass;

		private ApwnSimBlockItems _reportItems;

		private string _caption;

		private string _selctedBlocks;

		private ApwnSimBlockItems _selectedItem;

		private readonly List<SimBlockTypeClass> _itemSets;

		private readonly Window _dlg;

		private DelegateCommand<object> _commandOnbtnOK;

		private DelegateCommand<object> _commandOnbtnCancel;

		private DelegateCommand<object> _commandOnbtnApply;

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
				}
			}
		}

		public int SelectType { get; protected set; }

		public Visibility VisibleBlocks
		{
			get
			{
				if (_reportItems == null || _reportItems.Items == null || _reportItems.Items.Count == 0)
				{
					return Visibility.Collapsed;
				}
				return Visibility.Visible;
			}
		}

		public ApwnSimBlockItems ReportItems
		{
			get
			{
				return _reportItems;
			}
			private set
			{
				if (_reportItems != value)
				{
					_reportItems = value;
					_reportItems.Parent = null;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("ReportItems"));
					}
				}
			}
		}

		public string SelectedCaption
		{
			get
			{
				return _caption;
			}
			protected set
			{
				_caption = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedCaption"));
				}
			}
		}

		public string SelectedBlocks
		{
			get
			{
				return _selctedBlocks;
			}
			set
			{
				if (_selctedBlocks != value)
				{
					_selctedBlocks = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedBlocks"));
					}
				}
				(CommandOnbtnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
				(CommandOnbtnApply as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ApwnSimBlockItems SelectedItem
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
					}
				}
				string strBlocks = SelectedBlocks;
				UpdateSeletedBlocks(SelectedItem, ref strBlocks);
				SelectedBlocks = strBlocks;
			}
		}

		public CxsCase currentCase { get; set; }

		public string HelpFile => "userguide1.chm";

		public ICommand CommandOnbtnOK => _commandOnbtnOK ?? (_commandOnbtnOK = new DelegateCommand<object>(ExecuteCommandOnbtnOK, CanExecuteCommandOnbtnOK));

		public ICommand CommandOnbtnCancel => _commandOnbtnCancel ?? (_commandOnbtnCancel = new DelegateCommand<object>(ExecuteCommandOnbtnCancel));

		public ICommand CommandOnbtnApply => _commandOnbtnApply ?? (_commandOnbtnApply = new DelegateCommand<object>(ExecuteCommandOnbtnApply, CanExecuteCommandOnbtnOK));

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnSelectedClassChanged()
		{
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectType = @class.returntype;
					SelectedCaption = @class.caption;
					SelectedBlocks = "";
					break;
				}
			}
			ReportItems = new ApwnSimBlockItems
			{
				Items = new ObservableCollection<ApwnSimBlockItems>()
			};
			ApwnSimBlockItems apwnSimBlockItems = ApwnSimBlockItems.CreateSelectAllSimBlockItems();
			foreach (SimBlockTypeClass itemSet in _itemSets)
			{
				if (itemSet.name == _selectedClass)
				{
					apwnSimBlockItems.Items = new ObservableCollection<ApwnSimBlockItems>(itemSet.Items);
					break;
				}
			}
			if (apwnSimBlockItems.Items != null && apwnSimBlockItems.Items.Count != 0)
			{
				foreach (ApwnSimBlockItems item in apwnSimBlockItems.Items)
				{
					item.DisplayName = item.Name;
				}
				ReportItems.Items.Add(apwnSimBlockItems);
			}
			ReportItems.Checked = false;
			(CommandOnbtnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnbtnApply as DelegateCommand<object>).RaiseCanExecuteChanged();
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("VisibleBlocks"));
			}
		}

		private void DealNodeString(ref string strBlocks, string strTag, bool bAdd)
		{
			char[] trimChars = new char[1] { ' ' };
			string[] array = strBlocks.TrimEnd(trimChars).Split(' ');
			for (int i = 0; i < array.Count(); i++)
			{
				if (array[i] == strTag)
				{
					if (bAdd)
					{
						return;
					}
					array[i] = "";
					break;
				}
			}
			if (bAdd)
			{
				strBlocks += strTag;
				strBlocks += " ";
				return;
			}
			strBlocks = "";
			for (int j = 0; j < array.Count(); j++)
			{
				if (!string.IsNullOrEmpty(array[j]))
				{
					strBlocks += array[j];
					strBlocks += " ";
				}
			}
		}

		private void UpdateSeletedBlocks(ApwnSimBlockItems curBlock, ref string strBlocks)
		{
			if (curBlock == null)
			{
				strBlocks = "";
				return;
			}
			if (curBlock.Type == "-1")
			{
				foreach (ApwnSimBlockItems item in curBlock.Items)
				{
					if (item.Type == "-1")
					{
						UpdateSeletedBlocks(item, ref strBlocks);
					}
					else
					{
						DealNodeString(ref strBlocks, item.Tag, item.Checked == true);
					}
				}
				return;
			}
			DealNodeString(ref strBlocks, curBlock.Tag, curBlock.Checked == true);
		}

		public ShowBlockTempDlgViewModel(Window dlg, IUnityContainer container)
		{
			_dlg = dlg;
			currentCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			Classes = new List<MoveToType>
			{
				new MoveToType
				{
					name = "Simulation",
					DisplayName = WpfSimdllResources.All,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SimulationIDs,
					GRlstmovID = 0,
					extraItem = null,
					showtype = 0,
					returntype = 13
				},
				new MoveToType
				{
					name = "Balance",
					DisplayName = WpfSimdllResources.Balance,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BalanceIDs,
					GRlstmovID = 11,
					extraItem = null,
					showtype = 11,
					returntype = 10
				},
				new MoveToType
				{
					name = "Block",
					DisplayName = WpfSimdllResources.Block,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BlockIDs,
					GRlstmovID = 1,
					extraItem = null,
					showtype = 1,
					returntype = 1
				},
				new MoveToType
				{
					name = "Calculator",
					DisplayName = WpfSimdllResources.Calculator,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_CalculatorIDs,
					GRlstmovID = 4,
					extraItem = null,
					showtype = 8,
					returntype = 7
				},
				new MoveToType
				{
					name = "Connecting Streams",
					DisplayName = WpfSimdllResources.ConnectingStreams,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BlockIDs,
					GRlstmovID = 1,
					extraItem = null,
					showtype = 1,
					returntype = 18
				},
				new MoveToType
				{
					name = "Controller",
					DisplayName = WpfSimdllResources.Controller,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_ControllerIDs,
					GRlstmovID = 17,
					extraItem = null,
					showtype = 17,
					returntype = 23
				},
				new MoveToType
				{
					name = "Convergence",
					DisplayName = WpfSimdllResources.Convergence,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_ConvergenceIDs,
					GRlstmovID = 2,
					extraItem = null,
					showtype = 2,
					returntype = 2
				},
				new MoveToType
				{
					name = "Flowsheet Balance",
					DisplayName = WpfSimdllResources.FlowsheetBalance,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SimulationIDs,
					GRlstmovID = 0,
					extraItem = null,
					showtype = 0,
					returntype = 15
				},
				new MoveToType
				{
					name = "Measurement",
					DisplayName = WpfSimdllResources.Measurement,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_MeasurementIDs,
					GRlstmovID = 14,
					extraItem = null,
					showtype = 14,
					returntype = 21
				},
				new MoveToType
				{
					name = "Measurement Report",
					DisplayName = WpfSimdllResources.MeasurementReport,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SimulationIDs,
					GRlstmovID = 0,
					extraItem = null,
					showtype = 0,
					returntype = 22
				},
				new MoveToType
				{
					name = "Pressure Relief",
					DisplayName = WpfSimdllResources.PressureRelief,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_PressureIDs,
					GRlstmovID = 9,
					extraItem = null,
					showtype = 12,
					returntype = 11
				},
				new MoveToType
				{
					name = "Regression",
					DisplayName = WpfSimdllResources.Regression,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_RegressionIDs,
					GRlstmovID = 10,
					extraItem = null,
					showtype = 13,
					returntype = 12
				},
				new MoveToType
				{
					name = "Sensitivity",
					DisplayName = WpfSimdllResources.Sensitivity,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SensitivityIDs,
					GRlstmovID = 3,
					extraItem = null,
					showtype = 5,
					returntype = 5
				},
				new MoveToType
				{
					name = "Sensor",
					DisplayName = WpfSimdllResources.Sensor,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SensorIDs,
					GRlstmovID = 18,
					extraItem = null,
					showtype = 18,
					returntype = 24
				},
				new MoveToType
				{
					name = "Streams",
					DisplayName = WpfSimdllResources.Streams,
					caption = WpfSimdllResources.WpfSimdll_StreamsIDs,
					GRlstmovID = 12,
					extraItem = "All",
					showtype = 10,
					returntype = 9
				},
				new MoveToType
				{
					name = "Transfer",
					DisplayName = WpfSimdllResources.Transfer,
					caption = WpfSimdllResources.WpfSimdll_ReinitDlg_TransferIDs,
					GRlstmovID = 5,
					extraItem = null,
					showtype = 7,
					returntype = 6
				},
				new MoveToType
				{
					name = "Utilities",
					DisplayName = WpfSimdllResources.Utilities,
					caption = WpfSimdllResources.WpfSimdll_UtilitiesIDs,
					GRlstmovID = 8,
					extraItem = null,
					showtype = 9,
					returntype = 8
				}
			};
			object obj = currentCase.BatchGet("Top.Solver.ReportPointList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			_itemSets.RemoveAll((SimBlockTypeClass item) => item.Items.Count == 0);
			foreach (SimBlockTypeClass itemSet in _itemSets)
			{
				ObservableCollection<ApwnSimBlockItems> blockItems = new ObservableCollection<ApwnSimBlockItems>(itemSet.Items);
				PruneIt(ref blockItems);
				itemSet.Items = new List<ApwnSimBlockItems>(blockItems);
			}
			_itemSets.RemoveAll((SimBlockTypeClass item) => item.Items.Count == 0);
			SelectedClass = Classes[0].name;
		}

		public void PruneIt(ref ObservableCollection<ApwnSimBlockItems> blockItems)
		{
			List<ApwnSimBlockItems> list = blockItems.Where((ApwnSimBlockItems i) => i.Items.Count == 0 && i.Image == "folder.ico").ToList();
			if (list.Count == 0)
			{
				return;
			}
			foreach (ApwnSimBlockItems item in list)
			{
				blockItems.Remove(item);
			}
			foreach (ApwnSimBlockItems blockItem in blockItems)
			{
				ObservableCollection<ApwnSimBlockItems> blockItems2 = blockItem.Items;
				PruneIt(ref blockItems2);
			}
		}

		private void ExecuteCommandOnbtnOK(object arg)
		{
			_dlg.DialogResult = true;
			char[] trimChars = new char[1] { ' ' };
			string text = SelectedBlocks.TrimEnd(trimChars);
			currentCase.Solver.InvokeAction("DisplayReport", text, SelectType);
		}

		private bool CanExecuteCommandOnbtnOK(object arg)
		{
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name && @class.GRlstmovID <= 0)
				{
					return true;
				}
			}
			if (ReportItems != null && ReportItems.Items.Count > 0 && !string.IsNullOrEmpty(SelectedBlocks))
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnbtnCancel(object arg)
		{
			_dlg.DialogResult = false;
		}

		private void ExecuteCommandOnbtnApply(object arg)
		{
			char[] trimChars = new char[1] { ' ' };
			string text = SelectedBlocks.TrimEnd(trimChars);
			currentCase.Solver.InvokeAction("DisplayReport", text, SelectType);
		}
	}
	public class ShowBlockTempDlg : Window, IComponentConnector, IStyleConnector
	{
		private IUnityContainer Container;

		private ShowBlockTempDlgViewModel ViewModel;

		internal System.Windows.Controls.TreeView treeView;

		private bool _contentLoaded;

		public ShowBlockTempDlg(IUnityContainer container)
		{
			InitializeComponent();
			Container = container;
			base.Loaded += ShowBlockTempDlg_Loaded;
		}

		private void ShowBlockTempDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new ShowBlockTempDlgViewModel(this, Container);
			base.DataContext = ViewModel;
		}

		private void CheckBox_Click(object sender, RoutedEventArgs e)
		{
			if (ViewModel != null)
			{
				ApwnSimBlockItems apwnSimBlockItems = (sender as System.Windows.Controls.CheckBox).DataContext as ApwnSimBlockItems;
				if (apwnSimBlockItems != null && apwnSimBlockItems.Checked != true)
				{
					apwnSimBlockItems.Checked = false;
				}
				ViewModel.SelectedItem = apwnSimBlockItems;
			}
		}

		private void treeView_PreviewKeyDown(object sender, System.Windows.Input.KeyEventArgs e)
		{
			if (e.Key != Key.Space || !(e.OriginalSource is TreeViewItem treeViewItem))
			{
				return;
			}
			ApwnSimBlockItems apwnSimBlockItems = treeViewItem.DataContext as ApwnSimBlockItems;
			if (apwnSimBlockItems != null)
			{
				if (apwnSimBlockItems.Checked.HasValue)
				{
					apwnSimBlockItems.Checked = !apwnSimBlockItems.Checked.Value;
				}
				else
				{
					apwnSimBlockItems.Checked = true;
				}
			}
			ViewModel.SelectedItem = apwnSimBlockItems;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/showblocktempdlg.xaml", UriKind.Relative);
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
				treeView = (System.Windows.Controls.TreeView)target;
				treeView.PreviewKeyDown += treeView_PreviewKeyDown;
			}
			else
			{
				_contentLoaded = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				((System.Windows.Controls.CheckBox)target).Click += CheckBox_Click;
			}
		}
	}
	public class DRSRegressionRunDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public DRSRegressionRunDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "MoveTo", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class DRSRegressionRunDlg : Window, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(DRSRegressionRunDlgViewModel), typeof(DRSRegressionRunDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		private ObservableCollection<string> lstAvali = new ObservableCollection<string>();

		private ObservableCollection<string> lstSelected = new ObservableCollection<string>();

		internal DRSRegressionRunDlg drsRegressionRunDlg;

		internal System.Windows.Controls.ListBox lstAvailableComp;

		internal System.Windows.Controls.Button btnMove;

		internal System.Windows.Controls.Button btnMoveAll;

		internal System.Windows.Controls.Button btnRemove;

		internal System.Windows.Controls.Button btnClearAll;

		internal System.Windows.Controls.ListBox lstSelectedComp;

		internal System.Windows.Controls.Button btnUp;

		internal System.Windows.Controls.Button btnDown;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public DRSRegressionRunDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as DRSRegressionRunDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public ObservableCollection<string> AvaliItems
		{
			get
			{
				return lstAvali;
			}
			set
			{
				lstAvali = value;
			}
		}

		public ObservableCollection<string> SelectedItems
		{
			get
			{
				return lstSelected;
			}
			set
			{
				lstSelected = value;
			}
		}

		public DRSRegressionRunDlg()
		{
			InitializeComponent();
			DrsRegressionRun drsRegressionRun = new DrsRegressionRun();
			string selList = drsRegressionRun.GetSelList();
			if (!string.IsNullOrEmpty(selList))
			{
				string[] array = selList.Split('|');
				foreach (string item in array)
				{
					lstSelected.Add(item);
				}
			}
			selList = drsRegressionRun.GetAvaliList();
			if (!string.IsNullOrEmpty(selList))
			{
				string[] array = selList.Split('|');
				foreach (string text in array)
				{
					if (!IsInSelectedItems(text))
					{
						lstAvali.Add(text);
					}
				}
			}
			btnRemove.IsEnabled = (btnMove.IsEnabled = false);
			btnUp.IsEnabled = (btnDown.IsEnabled = false);
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as DRSRegressionRunDlg).DataContext = args.NewValue;
		}

		private void btnMove_Click(object sender, RoutedEventArgs e)
		{
			if (lstAvailableComp.SelectedItems.Count < 1)
			{
				return;
			}
			List<string> list = new List<string>();
			foreach (string selectedItem in lstAvailableComp.SelectedItems)
			{
				list.Add(selectedItem);
				SelectedItems.Add(selectedItem);
				lstSelectedComp.SelectedItem = selectedItem;
			}
			int num = 0;
			foreach (string item in list)
			{
				num = AvaliItems.IndexOf(item);
				AvaliItems.Remove(item);
			}
			int count = AvaliItems.Count;
			if (num < count)
			{
				lstAvailableComp.SelectedIndex = num;
			}
			else
			{
				lstAvailableComp.SelectedIndex = count - 1;
			}
		}

		private void btnMoveAll_Click(object sender, RoutedEventArgs e)
		{
			List<string> list = new List<string>();
			foreach (string avaliItem in AvaliItems)
			{
				list.Add(avaliItem);
				SelectedItems.Add(avaliItem);
			}
			foreach (string item in list)
			{
				AvaliItems.Remove(item);
			}
			btnMove.IsEnabled = false;
		}

		private void btnRemove_Click(object sender, RoutedEventArgs e)
		{
			if (lstSelectedComp.SelectedItems.Count < 1)
			{
				return;
			}
			List<string> list = new List<string>();
			foreach (string selectedItem in lstSelectedComp.SelectedItems)
			{
				list.Add(selectedItem);
				AvaliItems.Add(selectedItem);
				lstAvailableComp.SelectedItem = selectedItem;
			}
			int num = 0;
			foreach (string item in list)
			{
				num = SelectedItems.IndexOf(item);
				SelectedItems.Remove(item);
			}
			int count = SelectedItems.Count;
			if (num < count)
			{
				lstSelectedComp.SelectedIndex = num;
			}
			else
			{
				lstSelectedComp.SelectedIndex = count - 1;
			}
		}

		private void btnClearAll_Click(object sender, RoutedEventArgs e)
		{
			List<string> list = new List<string>();
			foreach (string selectedItem in SelectedItems)
			{
				list.Add(selectedItem);
				AvaliItems.Add(selectedItem);
			}
			foreach (string item in list)
			{
				SelectedItems.Remove(item);
			}
			btnRemove.IsEnabled = false;
			System.Windows.Controls.Button button = btnUp;
			bool isEnabled = (btnDown.IsEnabled = false);
			button.IsEnabled = isEnabled;
		}

		private bool IsInSelectedItems(string sItem)
		{
			foreach (string item in lstSelected)
			{
				if (item == sItem)
				{
					return true;
				}
			}
			return false;
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			int count = lstSelectedComp.Items.Count;
			if (count == 0)
			{
				MMMessageBox.Show(WpfSimdllResources.Regression_limit, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return;
			}
			DrsRegressionRun drsRegressionRun = new DrsRegressionRun();
			drsRegressionRun.SetRunCase(null, 1);
			for (int i = 0; i < count; i++)
			{
				drsRegressionRun.SetRunCase(lstSelectedComp.Items[i].ToString(), 1);
			}
			base.DialogResult = true;
			Close();
		}

		private void lstAvailableComp_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (lstAvailableComp.SelectedIndex >= 0)
			{
				btnMove.IsEnabled = true;
			}
			else
			{
				btnMove.IsEnabled = false;
			}
		}

		private void lstSelectedComp_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (lstSelectedComp.SelectedIndex == -1)
			{
				System.Windows.Controls.Button button = btnRemove;
				System.Windows.Controls.Button button2 = btnUp;
				bool flag = (btnDown.IsEnabled = false);
				bool isEnabled = (button2.IsEnabled = flag);
				button.IsEnabled = isEnabled;
				return;
			}
			btnRemove.IsEnabled = true;
			if (lstSelectedComp.SelectedIndex == 0)
			{
				btnUp.IsEnabled = false;
			}
			else
			{
				btnUp.IsEnabled = true;
			}
			if (lstSelectedComp.SelectedIndex == lstSelectedComp.Items.Count - 1)
			{
				btnDown.IsEnabled = false;
			}
			else
			{
				btnDown.IsEnabled = true;
			}
		}

		private void btnUp_Click(object sender, RoutedEventArgs e)
		{
			int selectedIndex = lstSelectedComp.SelectedIndex;
			if (selectedIndex > 0)
			{
				string item = SelectedItems[selectedIndex];
				SelectedItems.RemoveAt(selectedIndex);
				SelectedItems.Insert(selectedIndex - 1, item);
				lstSelectedComp.SelectedIndex = selectedIndex - 1;
			}
		}

		private void btnDown_Click(object sender, RoutedEventArgs e)
		{
			int selectedIndex = lstSelectedComp.SelectedIndex;
			if (selectedIndex < lstSelectedComp.Items.Count - 1)
			{
				string item = SelectedItems[selectedIndex];
				SelectedItems.RemoveAt(selectedIndex);
				SelectedItems.Insert(selectedIndex + 1, item);
				lstSelectedComp.SelectedIndex = selectedIndex + 1;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/drsregressionrundlg.xaml", UriKind.Relative);
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
				drsRegressionRunDlg = (DRSRegressionRunDlg)target;
				break;
			case 2:
				lstAvailableComp = (System.Windows.Controls.ListBox)target;
				lstAvailableComp.SelectionChanged += lstAvailableComp_SelectionChanged;
				lstAvailableComp.MouseDoubleClick += btnMove_Click;
				break;
			case 3:
				btnMove = (System.Windows.Controls.Button)target;
				btnMove.Click += btnMove_Click;
				break;
			case 4:
				btnMoveAll = (System.Windows.Controls.Button)target;
				btnMoveAll.Click += btnMoveAll_Click;
				break;
			case 5:
				btnRemove = (System.Windows.Controls.Button)target;
				btnRemove.Click += btnRemove_Click;
				break;
			case 6:
				btnClearAll = (System.Windows.Controls.Button)target;
				btnClearAll.Click += btnClearAll_Click;
				break;
			case 7:
				lstSelectedComp = (System.Windows.Controls.ListBox)target;
				lstSelectedComp.SelectionChanged += lstSelectedComp_SelectionChanged;
				lstSelectedComp.MouseDoubleClick += btnRemove_Click;
				break;
			case 8:
				btnUp = (System.Windows.Controls.Button)target;
				btnUp.Click += btnUp_Click;
				break;
			case 9:
				btnDown = (System.Windows.Controls.Button)target;
				btnDown.Click += btnDown_Click;
				break;
			case 10:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 11:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MoveAllConvert : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return (int)value > 0;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new Exception(ApwnResources.ErrorCanNotConvertMoveAll);
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
				MMMessageBox.Show(WpfSimdllResources.InvalidFilePath, WpfSimdllResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
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
						MMMessageBox.Show($"{WpfSimdllResources.InvalidChar} '{c}' !", WpfSimdllResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
						return false;
					}
				}
			}
			if (!Directory.Exists(Path.GetDirectoryName(CppCode.m_strFilename)))
			{
				MMMessageBox.Show(WpfSimdllResources.InvalidDir, WpfSimdllResources.DlgTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
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
				MMMessageBox.Show($"{WpfSimdllResources.EoVariableMsg1} {CppCode.GetEOWzd().m_strQueryFile}!", WpfSimdllResources.DlgTitle);
				WizardContainer container = base.Container;
				bool flag = (base.Container.CanNext = false);
				bool flag3 = (container.CanFinish = flag);
				bool canNext = (base.CanFinish = flag3);
				base.CanNext = canNext;
				return false;
			}
			if (CppCode.GetEOWzd().m_nImport == 0 && CppCode.GetEOWzd().UpdateQuery() && MMMessageBox.Show($"{CppCode.GetEOWzd().m_strQueryFile} {WpfSimdllResources.EoVariableMsg2}", WpfSimdllResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Exclamation) == MMMessageBoxResult.Cancel)
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
			if (CppCode.GetEOWzd().m_nImport == 0 && CppCode.GetEOWzd().UpdateQuery() && MMMessageBox.Show($"{CppCode.GetEOWzd().m_strQueryFile} {WpfSimdllResources.EoVariableMsg2}", WpfSimdllResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Exclamation) == MMMessageBoxResult.Cancel)
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/eoexportfile.xaml", UriKind.Relative);
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
			if ((base.Container as EOExportWzd).CppCode.m_nImport != 0 && CppCode.m_maskCode && MMMessageBox.Show(WpfSimdllResources.ImportQuestion, WpfSimdllResources.DlgTitle, MMMessageBoxButton.OKCancel, MMMessageBoxImage.Question) == MMMessageBoxResult.Cancel)
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/eoexportmask.xaml", UriKind.Relative);
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
				pageFile.Title = WpfSimdllResources.PageFile_ImportTitle;
				pageFrom.Title = WpfSimdllResources.PageFrom_ImportTitle;
				pageMask.Title = WpfSimdllResources.PageMask_ImportTitle;
			}
			else
			{
				pageFile.Title = WpfSimdllResources.PageFile_ExportTitle;
				pageMask.Title = WpfSimdllResources.PageMask_ExportTitle;
			}
		}
	}
	public class EOReinitDlgViewModel : ObservableObject
	{
		public static string gScope;

		private int _Choice;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

		public int Choice
		{
			get
			{
				return _Choice;
			}
			set
			{
				if (value != _Choice)
				{
					_Choice = value;
					PropertyHasChange();
				}
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

		public EOReinitDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
			Choice = ControlPanel.EOReinitChoice();
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "EOInitialize", Choice, gScope);
			if (Choice == 4)
			{
				UnityContainer.Parent?.Parent?.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<EOVariableImportedEvent>().Publish(new EOVariableImportedEventArgs());
			}
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class EOReinitDlg : System.Windows.Controls.UserControl, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(EOReinitDlgViewModel), typeof(EOReinitDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal EOReinitDlg eOReinitDlg;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		internal System.Windows.Controls.Button btnHelp;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public EOReinitDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as EOReinitDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public EOReinitDlg()
		{
			InitializeComponent();
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as EOReinitDlg).DataContext = args.NewValue;
		}

		private void eOReinitDlg_PreviewMouseRightButtonDown(object sender, MouseButtonEventArgs e)
		{
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/eoreinitdlg.xaml", UriKind.Relative);
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
				eOReinitDlg = (EOReinitDlg)target;
				eOReinitDlg.PreviewMouseRightButtonDown += eOReinitDlg_PreviewMouseRightButtonDown;
				break;
			case 2:
				btnOK = (System.Windows.Controls.Button)target;
				break;
			case 3:
				btnCancel = (System.Windows.Controls.Button)target;
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
	public class EOReinitConvert : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || parameter == null)
			{
				return false;
			}
			if ((int)value == int.Parse((string)parameter))
			{
				return true;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || parameter == null)
			{
				return null;
			}
			if ((bool)value)
			{
				return int.Parse((string)parameter);
			}
			return null;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/fileinputbox.xaml", UriKind.Relative);
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
				string text = treeItem.Tag.Remove(treeItem.Tag.LastIndexOf('.'), 5);
				if (text.Contains("."))
				{
					string[] array = text.Split('.');
					text = string.Empty;
					for (int num = array.Length - 1; num >= 0; num--)
					{
						text = text + array[num] + ".";
					}
					text = text.TrimEnd('.');
				}
				CppCode.m_strSelected = text;
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
				CppCode.m_strPrompt = WpfSimdllResources.EoVariableMsg3;
				CppCode.m_nHier = 1;
			}
			else
			{
				CppCode.m_strPrompt = WpfSimdllResources.EoVariableMsg4;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/importfrompage.xaml", UriKind.Relative);
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
	public class MoveToType
	{
		public string name { get; set; }

		public string DisplayName { get; set; }

		public string caption { get; set; }

		public int GRlstmovID { get; set; }

		public string extraItem { get; set; }

		public int showtype { get; set; }

		public int returntype { get; set; }
	}
	[XmlType(TypeName = "Class")]
	public class SimBlockTypeClass
	{
		public string name { get; set; }

		public List<ApwnSimBlockItems> Items { get; set; }
	}
	[XmlType(TypeName = "Item")]
	public class ApwnSimBlockItems : INotifyPropertyChanged
	{
		private string _name;

		private string _displayname = string.Empty;

		private ObservableCollection<ApwnSimBlockItems> _Items;

		private bool _expand;

		private bool bUpdated;

		private bool? _isChecked;

		public static readonly string SelectAllName = WpfSimdllResources.Select_All;

		public static readonly string SelectAllDisplayName = WpfSimdllResources.Select_All;

		public string Name
		{
			get
			{
				return _name;
			}
			set
			{
				_name = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("Name"));
				}
			}
		}

		public string DisplayName
		{
			get
			{
				if (string.IsNullOrEmpty(_displayname))
				{
					return _name;
				}
				if (string.Compare(_displayname, "All", ignoreCase: true) == 0)
				{
					return WpfSimdllResources.WpfSimdll_ALL;
				}
				return _displayname;
			}
			set
			{
				_displayname = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("DisplayName"));
				}
			}
		}

		public string Image { get; set; }

		public ObservableCollection<ApwnSimBlockItems> Items
		{
			get
			{
				return _Items;
			}
			set
			{
				if (_Items == value)
				{
					return;
				}
				if (_Items != null)
				{
					foreach (ApwnSimBlockItems item in _Items)
					{
						item.Parent = null;
					}
				}
				_Items = value;
				if (_Items != null)
				{
					foreach (ApwnSimBlockItems item2 in _Items)
					{
						item2.Parent = this;
					}
				}
				_Items.CollectionChanged += delegate(object o, NotifyCollectionChangedEventArgs e)
				{
					if (e.NewItems != null)
					{
						if (e.Action == NotifyCollectionChangedAction.Add)
						{
							foreach (ApwnSimBlockItems newItem in e.NewItems)
							{
								newItem.Parent = this;
							}
							return;
						}
						if (e.Action == NotifyCollectionChangedAction.Remove)
						{
							foreach (ApwnSimBlockItems newItem2 in e.NewItems)
							{
								newItem2.Parent = null;
							}
						}
					}
				};
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("Items"));
				}
			}
		}

		public ApwnSimBlockItems Parent { get; set; }

		public string Type { get; set; }

		public string Tag { get; set; }

		public bool IsExpanded
		{
			get
			{
				return _expand;
			}
			set
			{
				_expand = value;
				if (Image != "FormNode.png")
				{
					if (value && Items != null && Items.Count > 0)
					{
						Image = "unFolder.ico";
					}
					else
					{
						Image = "folder.ico";
					}
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("Image"));
					}
				}
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("IsExpanded"));
				}
			}
		}

		public bool? Checked
		{
			get
			{
				return _isChecked;
			}
			set
			{
				if (_isChecked == value)
				{
					return;
				}
				_isChecked = value;
				bUpdated = true;
				if (_isChecked.HasValue && IsChildrenNeedUpdate())
				{
					IsExpanded = _isChecked.Value;
					foreach (ApwnSimBlockItems item in Items)
					{
						item.Checked = value;
						item.IsExpanded = _isChecked.Value;
					}
				}
				if (Parent != null && !Parent.bUpdated && Name != SelectAllName)
				{
					UpdateParentStatus();
				}
				bUpdated = false;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("Checked"));
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private bool IsChildrenNeedUpdate()
		{
			foreach (ApwnSimBlockItems item in Items)
			{
				if (item.bUpdated)
				{
					return false;
				}
			}
			return true;
		}

		private void UpdateParentStatus()
		{
			ApwnSimBlockItems parent = Parent;
			if (IsAllUnchecked(parent.Items))
			{
				parent.Checked = false;
			}
			else if (IsAllChecked(parent.Items))
			{
				parent.Checked = true;
			}
			else
			{
				parent.Checked = null;
			}
		}

		private bool IsAllChecked(IList<ApwnSimBlockItems> source)
		{
			foreach (ApwnSimBlockItems item in source)
			{
				if (!item.Checked.HasValue || (item.Checked.HasValue && !item.Checked.Value))
				{
					return false;
				}
			}
			return true;
		}

		private bool IsAllUnchecked(IList<ApwnSimBlockItems> source)
		{
			foreach (ApwnSimBlockItems item in source)
			{
				if (!item.Checked.HasValue || (item.Checked.HasValue && item.Checked.Value))
				{
					return false;
				}
			}
			return true;
		}

		public static ApwnSimBlockItems CreateSelectAllSimBlockItems()
		{
			return new ApwnSimBlockItems
			{
				Name = SelectAllName,
				DisplayName = SelectAllDisplayName,
				Type = "-1",
				Tag = ""
			};
		}
	}
	public class MoveToDlgViewModel : INotifyPropertyChanged
	{
		private string _selectedClassCaption;

		private bool _bOKSpecialActived;

		private string _selectedClass;

		private List<ApwnSimBlockItems> _moveToItems;

		private ApwnSimBlockItems _selectedItem;

		private List<SimBlockTypeClass> _itemSets;

		private Window _dlg;

		private DelegateCommand<object> _commandOnOK;

		public string HelpFile => "gendbhlp.chm";

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClassCaption
		{
			get
			{
				return _selectedClassCaption;
			}
			set
			{
				if (_selectedClassCaption != value)
				{
					_selectedClassCaption = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedClassCaption"));
					}
				}
			}
		}

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
					(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
				}
			}
		}

		public List<ApwnSimBlockItems> MoveToItems
		{
			get
			{
				return _moveToItems;
			}
			private set
			{
				if (_moveToItems != value)
				{
					_moveToItems = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("MoveToItems"));
					}
				}
			}
		}

		public ApwnSimBlockItems SelectedItem
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

		private IUnityContainer UnityContainer { get; set; }

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

		private void OnSelectedClassChanged()
		{
			int num = 0;
			_bOKSpecialActived = false;
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectedClassCaption = @class.caption;
					if (@class.GRlstmovID <= 0)
					{
						_bOKSpecialActived = true;
					}
					break;
				}
				num++;
			}
			if (num < Classes.Count)
			{
				MoveToItems = _itemSets[num].Items;
				if (MoveToItems.Count > 0)
				{
					SelectedItem = MoveToItems[0];
				}
				else
				{
					SelectedItem = null;
				}
			}
		}

		public MoveToDlgViewModel(IUnityContainer container, Window dlg)
		{
			_dlg = dlg;
			UnityContainer = container;
			Classes = new List<MoveToType>();
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Block,
				caption = WpfSimdllResources.Block,
				GRlstmovID = 1,
				extraItem = null,
				showtype = 1,
				returntype = 1
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Convergence,
				caption = WpfSimdllResources.Convergence,
				GRlstmovID = 2,
				extraItem = null,
				showtype = 2,
				returntype = 2
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Sensitivity,
				caption = WpfSimdllResources.Sensitivity,
				GRlstmovID = 3,
				extraItem = null,
				showtype = 5,
				returntype = 3
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Transfer,
				caption = WpfSimdllResources.Transfer,
				GRlstmovID = 5,
				extraItem = null,
				showtype = 7,
				returntype = 5
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Calculator,
				caption = WpfSimdllResources.Calculator,
				GRlstmovID = 4,
				extraItem = null,
				showtype = 8,
				returntype = 4
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Utilities,
				caption = WpfSimdllResources.Utilities,
				GRlstmovID = 8,
				extraItem = null,
				showtype = 9,
				returntype = 8
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Balance,
				caption = WpfSimdllResources.Balance,
				GRlstmovID = 11,
				extraItem = null,
				showtype = 11,
				returntype = 11
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.PressureRelief,
				caption = WpfSimdllResources.PressureRelief,
				GRlstmovID = 9,
				extraItem = null,
				showtype = 12,
				returntype = 9
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Regression,
				caption = WpfSimdllResources.Regression,
				GRlstmovID = 10,
				extraItem = null,
				showtype = 13,
				returntype = 10
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.StartofSequence,
				caption = WpfSimdllResources.StartofSequence,
				GRlstmovID = 0,
				extraItem = null,
				showtype = 6,
				returntype = 12
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Measurement,
				caption = WpfSimdllResources.Measurement,
				GRlstmovID = 14,
				extraItem = null,
				showtype = 14,
				returntype = 21
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.EOConvergence,
				caption = WpfSimdllResources.EOConvergence,
				GRlstmovID = 15,
				extraItem = null,
				showtype = 15,
				returntype = 15
			});
			object obj = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).BatchGet("Top.Solver.MoveToList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			SelectedClass = Classes[0].name;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			if (!_bOKSpecialActived)
			{
				cxsCase.InvokeAction("Top.Solver", "MoveTo", SelectedItem.Tag);
				_dlg.DialogResult = true;
			}
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			if (_bOKSpecialActived)
			{
				return true;
			}
			if (SelectedItem != null && !(SelectedItem.Type == "-1"))
			{
				return true;
			}
			return false;
		}
	}
	public class MoveToTypeConvert : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is IList<MoveToType> list)
			{
				List<string> list2 = new List<string>();
				{
					foreach (MoveToType item in list)
					{
						list2.Add(item.name);
					}
					return list2;
				}
			}
			return null;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class MoveToItemImageConvert : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			StringBuilder stringBuilder = new StringBuilder();
			stringBuilder.Append("pack://application:,,,/");
			stringBuilder.Append(typeof(MoveToDlg).Assembly.FullName);
			stringBuilder.Append(";component/Image/");
			stringBuilder.Append(value as string);
			return new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class MoveToDlg : Window, IComponentConnector
	{
		private MoveToDlgViewModel ViewModel;

		private IUnityContainer UnityContainer;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		internal System.Windows.Controls.Button btnHelp;

		internal System.Windows.Controls.ComboBox cbeClass;

		private bool _contentLoaded;

		public MoveToDlg(IUnityContainer container)
		{
			InitializeComponent();
			UnityContainer = container;
			base.Loaded += MoveToDlg_Loaded;
		}

		private void MoveToDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new MoveToDlgViewModel(UnityContainer, this);
			base.DataContext = ViewModel;
		}

		private void TreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			System.Windows.Controls.TreeView treeView = sender as System.Windows.Controls.TreeView;
			if (ViewModel != null)
			{
				ViewModel.SelectedItem = treeView.SelectedItem as ApwnSimBlockItems;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/movetodlg.xaml", UriKind.Relative);
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
				btnOK = (System.Windows.Controls.Button)target;
				break;
			case 2:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			case 3:
				btnHelp = (System.Windows.Controls.Button)target;
				break;
			case 4:
				cbeClass = (System.Windows.Controls.ComboBox)target;
				break;
			case 5:
				((System.Windows.Controls.TreeView)target).SelectedItemChanged += TreeView_SelectedItemChanged;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PDBActivateDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public PDBActivateDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "MoveTo", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class PDBActivateDlg : System.Windows.Controls.UserControl, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public MoveToDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as MoveToDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public PDBActivateDlg()
		{
			InitializeComponent();
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as MoveToDlg).DataContext = args.NewValue;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/pdbactivatedlg.xaml", UriKind.Relative);
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
				btnOK = (System.Windows.Controls.Button)target;
				break;
			case 2:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PDBGetDlgViewModel : INotifyPropertyChanged
	{
		private Window _dlg;

		private List<SimBlockTypeClass> _itemSets;

		private string _selectedClass;

		private List<ApwnSimBlockItems> _PDBGetItems;

		private string _caption;

		private string _selctedBlocks;

		private ApwnSimBlockItems _selectedItem;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public CxsCase currentCase { get; set; }

		private IUnityContainer UnityContainer { get; set; }

		public string HelpFile => "userguide1.chm";

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
				}
			}
		}

		public List<ApwnSimBlockItems> PDBGetItems
		{
			get
			{
				return _PDBGetItems;
			}
			private set
			{
				if (_PDBGetItems != value)
				{
					_PDBGetItems = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("PDBGetItems"));
					}
				}
			}
		}

		public string SelectedCaption
		{
			get
			{
				return _caption;
			}
			protected set
			{
				_caption = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedCaption"));
				}
			}
		}

		public string SelectedBlocks
		{
			get
			{
				return _selctedBlocks;
			}
			set
			{
				if (_selctedBlocks != value)
				{
					_selctedBlocks = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedBlocks"));
					}
				}
				(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ApwnSimBlockItems SelectedItem
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
					}
				}
				string strBlocks = SelectedBlocks;
				UpdateSeletedBlocks(SelectedItem, ref strBlocks);
				SelectedBlocks = strBlocks;
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

		public PDBGetDlgViewModel(IUnityContainer container, Window dlg)
		{
			_dlg = dlg;
			UnityContainer = container;
			currentCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			Classes = new List<MoveToType>();
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Simulation,
				caption = "Available Items",
				GRlstmovID = 0,
				extraItem = null,
				showtype = 0,
				returntype = 3
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Block,
				caption = "Block IDs",
				GRlstmovID = 1,
				extraItem = "All",
				showtype = 1,
				returntype = 1
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Streams,
				caption = "Streams IDs",
				GRlstmovID = 12,
				extraItem = "All",
				showtype = 10,
				returntype = 2
			});
			object obj = currentCase.BatchGet("Top.Solver.PDBGetList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			SelectedClass = Classes[0].name;
		}

		private void OnSelectedClassChanged()
		{
			int num = 0;
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectedCaption = @class.caption;
					SelectedBlocks = "";
					break;
				}
				num++;
			}
			if (num < Classes.Count)
			{
				PDBGetItems = _itemSets[num].Items;
				foreach (ApwnSimBlockItems pDBGetItem in PDBGetItems)
				{
					pDBGetItem.Checked = false;
				}
			}
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private void DealNodeString(ref string strBlocks, string strTag, bool bAdd)
		{
			char[] trimChars = new char[1] { ' ' };
			string[] array = strBlocks.TrimEnd(trimChars).Split(' ');
			for (int i = 0; i < array.Count(); i++)
			{
				if (array[i] == strTag)
				{
					if (bAdd)
					{
						return;
					}
					array[i] = "";
					break;
				}
			}
			if (bAdd)
			{
				strBlocks += strTag;
				strBlocks += " ";
				return;
			}
			strBlocks = "";
			for (int j = 0; j < array.Count(); j++)
			{
				if (!string.IsNullOrEmpty(array[j]))
				{
					strBlocks += array[j];
					strBlocks += " ";
				}
			}
		}

		private void UpdateSeletedBlocks(ApwnSimBlockItems curBlock, ref string strBlocks)
		{
			if (curBlock == null)
			{
				strBlocks = "";
				return;
			}
			if (curBlock.Type == "-1")
			{
				foreach (ApwnSimBlockItems item in curBlock.Items)
				{
					if (item.Type == "-1")
					{
						UpdateSeletedBlocks(item, ref strBlocks);
					}
					else
					{
						DealNodeString(ref strBlocks, item.Tag.ToString(), item.Checked.HasValue && item.Checked.Value);
					}
				}
				return;
			}
			DealNodeString(ref strBlocks, curBlock.Tag.ToString(), curBlock.Checked.HasValue && curBlock.Checked.Value);
		}

		private void ExecuteCommandOnOK(object arg)
		{
			_dlg.DialogResult = true;
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name && @class.GRlstmovID <= 0)
				{
					return true;
				}
			}
			if (PDBGetItems != null && PDBGetItems.Count > 0 && !string.IsNullOrEmpty(SelectedBlocks))
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			_dlg.DialogResult = false;
		}
	}
	public class PDBGetDlg : Window, IComponentConnector, IStyleConnector
	{
		private IUnityContainer Container;

		private PDBGetDlgViewModel ViewModel;

		private bool _contentLoaded;

		public PDBGetDlg(IUnityContainer container)
		{
			InitializeComponent();
			Container = container;
			base.Loaded += PDBGetDlg_Loaded;
		}

		private void PDBGetDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new PDBGetDlgViewModel(Container, this);
			base.DataContext = ViewModel;
		}

		private void CheckBox_Click(object sender, RoutedEventArgs e)
		{
			if (ViewModel != null)
			{
				ViewModel.SelectedItem = (sender as System.Windows.Controls.CheckBox).DataContext as ApwnSimBlockItems;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/pdbgetdlg.xaml", UriKind.Relative);
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

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((System.Windows.Controls.CheckBox)target).Click += CheckBox_Click;
			}
		}
	}
	public class PDBPutDlgViewModel : INotifyPropertyChanged
	{
		private Window _dlg;

		private List<SimBlockTypeClass> _itemSets;

		private string _selectedClass;

		private List<ApwnSimBlockItems> _pDBPutItems;

		private string _caption;

		private string _selctedBlocks;

		private ApwnSimBlockItems _selectedItem;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public CxsCase currentCase { get; set; }

		private IUnityContainer UnityContainer { get; set; }

		public string HelpFile => "userguide1.chm";

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
				}
			}
		}

		public List<ApwnSimBlockItems> PDBPutItems
		{
			get
			{
				return _pDBPutItems;
			}
			private set
			{
				if (_pDBPutItems != value)
				{
					_pDBPutItems = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("PDBPutItems"));
					}
				}
			}
		}

		public string SelectedCaption
		{
			get
			{
				return _caption;
			}
			protected set
			{
				_caption = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedCaption"));
				}
			}
		}

		public string SelectedBlocks
		{
			get
			{
				return _selctedBlocks;
			}
			set
			{
				if (_selctedBlocks != value)
				{
					_selctedBlocks = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedBlocks"));
					}
				}
				(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ApwnSimBlockItems SelectedItem
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
					}
				}
				string strBlocks = SelectedBlocks;
				UpdateSeletedBlocks(SelectedItem, ref strBlocks);
				SelectedBlocks = strBlocks;
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

		public PDBPutDlgViewModel(IUnityContainer container, Window dlg)
		{
			_dlg = dlg;
			UnityContainer = container;
			currentCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			Classes = new List<MoveToType>();
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Simulation,
				caption = WpfSimdllResources.Simulation,
				GRlstmovID = 0,
				extraItem = null,
				showtype = 0,
				returntype = 3
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Block,
				caption = WpfSimdllResources.Block,
				GRlstmovID = 1,
				extraItem = "All",
				showtype = 1,
				returntype = 1
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Streams,
				caption = WpfSimdllResources.Streams,
				GRlstmovID = 12,
				extraItem = "All",
				showtype = 10,
				returntype = 2
			});
			object obj = currentCase.BatchGet("Top.Solver.PDBPutList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			SelectedClass = Classes[0].name;
		}

		private void OnSelectedClassChanged()
		{
			int num = 0;
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectedCaption = @class.caption;
					SelectedBlocks = "";
					break;
				}
				num++;
			}
			if (num < Classes.Count)
			{
				PDBPutItems = _itemSets[num].Items;
				foreach (ApwnSimBlockItems pDBPutItem in PDBPutItems)
				{
					pDBPutItem.Checked = false;
				}
			}
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private void DealNodeString(ref string strBlocks, string strTag, bool bAdd)
		{
			char[] trimChars = new char[1] { ' ' };
			string[] array = strBlocks.TrimEnd(trimChars).Split(' ');
			for (int i = 0; i < array.Count(); i++)
			{
				if (array[i] == strTag)
				{
					if (bAdd)
					{
						return;
					}
					array[i] = "";
					break;
				}
			}
			if (bAdd)
			{
				strBlocks += strTag;
				strBlocks += " ";
				return;
			}
			strBlocks = "";
			for (int j = 0; j < array.Count(); j++)
			{
				if (!string.IsNullOrEmpty(array[j]))
				{
					strBlocks += array[j];
					strBlocks += " ";
				}
			}
		}

		private void UpdateSeletedBlocks(ApwnSimBlockItems curBlock, ref string strBlocks)
		{
			if (curBlock == null)
			{
				strBlocks = "";
				return;
			}
			if (curBlock.Type == "-1")
			{
				foreach (ApwnSimBlockItems item in curBlock.Items)
				{
					if (item.Type == "-1")
					{
						UpdateSeletedBlocks(item, ref strBlocks);
					}
					else
					{
						DealNodeString(ref strBlocks, item.Tag, item.Checked.HasValue && item.Checked.Value);
					}
				}
				return;
			}
			DealNodeString(ref strBlocks, curBlock.Tag, curBlock.Checked.HasValue && curBlock.Checked.Value);
		}

		private void ExecuteCommandOnOK(object arg)
		{
			_dlg.DialogResult = true;
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name && @class.GRlstmovID <= 0)
				{
					return true;
				}
			}
			if (PDBPutItems != null && PDBPutItems.Count > 0 && !string.IsNullOrEmpty(SelectedBlocks))
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			_dlg.DialogResult = false;
		}
	}
	public class PDBPutDlg : Window, IComponentConnector, IStyleConnector
	{
		private IUnityContainer Container;

		private PDBPutDlgViewModel ViewModel;

		private bool _contentLoaded;

		public PDBPutDlg(IUnityContainer container)
		{
			InitializeComponent();
			Container = container;
			base.Loaded += PDBPutDlg_Loaded;
		}

		private void PDBPutDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new PDBPutDlgViewModel(Container, this);
			base.DataContext = ViewModel;
		}

		private void CheckBox_Click(object sender, RoutedEventArgs e)
		{
			if (ViewModel != null)
			{
				ViewModel.SelectedItem = (sender as System.Windows.Controls.CheckBox).DataContext as ApwnSimBlockItems;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/pdbputdlg.xaml", UriKind.Relative);
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

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((System.Windows.Controls.CheckBox)target).Click += CheckBox_Click;
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
	public class ReExecuteBlockDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public ReExecuteBlockDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "MoveTo", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class ReExecuteBlockDlg : Window, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		public static DependencyProperty BlockProperty = DependencyProperty.Register("Block", typeof(string), typeof(ReExecuteBlockDlg));

		internal ReExecuteBlockDlg reExecuteBlockDlg;

		internal System.Windows.Controls.RadioButton btnReexecute;

		internal System.Windows.Controls.RadioButton btnContinue;

		internal System.Windows.Controls.Button btnOk;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public MoveToDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as MoveToDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public int Choice { get; protected set; }

		public string BlockName { get; set; }

		public string Block
		{
			get
			{
				return (string)GetValue(BlockProperty);
			}
			set
			{
				SetValue(BlockProperty, value);
			}
		}

		public ReExecuteBlockDlg()
		{
			InitializeComponent();
			base.Loaded += ReExecuteBlockDlg_Loaded;
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as MoveToDlg).DataContext = args.NewValue;
		}

		public void ReExecuteBlockDlg_Loaded(object sender, RoutedEventArgs e)
		{
			Block = WpfSimdllResources.WpfSimdll_ReExecuteBlockDlg_ExecutionBlock;
			Block += BlockName;
			btnReexecute.IsChecked = true;
		}

		private void btnOk_Click(object sender, RoutedEventArgs e)
		{
			Choice = (btnReexecute.IsChecked.Value ? 1 : 2);
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/reexecuteblockdlg.xaml", UriKind.Relative);
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
				reExecuteBlockDlg = (ReExecuteBlockDlg)target;
				break;
			case 2:
				btnReexecute = (System.Windows.Controls.RadioButton)target;
				break;
			case 3:
				btnContinue = (System.Windows.Controls.RadioButton)target;
				break;
			case 4:
				btnOk = (System.Windows.Controls.Button)target;
				btnOk.Click += btnOk_Click;
				break;
			case 5:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ReexecuteFortranDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public ReexecuteFortranDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "MoveTo", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class ReexecuteFortranDlg : Window, IComponentConnector
	{
		private int SelectedItem = -1;

		private List<string> reexectype = new List<string>();

		public static DependencyProperty BlocksProperty = DependencyProperty.Register("Blocks", typeof(DataTable), typeof(ReexecuteFortranDlg));

		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal ReexecuteFortranDlg reexecuteFortranDlg;

		internal System.Windows.Controls.ListView lvwItems;

		internal System.Windows.Controls.Button btnMoveTo;

		internal System.Windows.Controls.Button btnContinue;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public DataTable Blocks
		{
			get
			{
				return (DataTable)GetValue(BlocksProperty);
			}
			set
			{
				SetValue(BlocksProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public MoveToDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as MoveToDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public int Choice { get; protected set; }

		public string ItemSelected { get; protected set; }

		public ReexecuteFortranDlg()
		{
			reexectype.Add("");
			reexectype.Add("BLOCK");
			reexectype.Add("CONVERGENCE");
			reexectype.Add("COST");
			reexectype.Add("ECONOMIC");
			reexectype.Add("SENSITIVITY");
			reexectype.Add("");
			reexectype.Add("TRANSFER");
			reexectype.Add("CALCULATOR");
			reexectype.Add("UTILITY");
			reexectype.Add("CASE-STUDY");
			reexectype.Add("BALANCE");
			reexectype.Add("EQUIPMENT");
			reexectype.Add("PRES-RELIEF");
			reexectype.Add("REGRESSION");
			Blocks = new DataTable();
			InitializeComponent();
			Blocks.Columns.Add("FortranType", typeof(string));
			Blocks.Columns.Add("FortranID", typeof(string));
			Blocks.Columns.Add("BlockType", typeof(string));
			Blocks.Columns.Add("BlockID", typeof(string));
			Blocks.Columns.Add("Display1", typeof(string));
			Blocks.Columns.Add("Display2", typeof(string));
			base.Loaded += ReexecuteFortranDlg_Loaded;
		}

		private void ReexecuteFortranDlg_Loaded(object sender, RoutedEventArgs e)
		{
			lvwItems.SelectedIndex = 0;
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as MoveToDlg).DataContext = args.NewValue;
		}

		private void btnMoveTo_Click(object sender, RoutedEventArgs e)
		{
			DataRowView dataRowView = lvwItems.SelectedItem as DataRowView;
			string text = dataRowView["FortranType"].ToString().Trim();
			int num = 0;
			foreach (string item in reexectype)
			{
				if (text == item)
				{
					Choice = num;
					ItemSelected = dataRowView["FortranID"].ToString();
					break;
				}
				num++;
			}
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void btnContinue_Click(object sender, RoutedEventArgs e)
		{
			Choice = -1;
			Close();
		}

		public bool ReadEngineFile(string filename)
		{
			bool result = false;
			FileStream fileStream = new FileStream(filename, FileMode.Open, FileAccess.Read, FileShare.Read);
			StreamReader streamReader = new StreamReader(fileStream);
			if (fileStream.Length != 0L)
			{
				result = true;
				int num = 0;
				while (true)
				{
					string Third;
					string Forth;
					string Second = (Third = (Forth = ""));
					string text = streamReader.ReadLine();
					if (string.IsNullOrEmpty(text))
					{
						break;
					}
					int index = ParseFormatLine(text, ref Second, ref Third, ref Forth);
					DataRow dataRow = Blocks.NewRow();
					dataRow["FortranType"] = reexectype[index];
					int length = Second.Length;
					if (length > num)
					{
						num = length;
					}
					dataRow["FortranID"] = Second;
					int num2 = int.Parse(Third);
					if (num2 == 21)
					{
						dataRow["BlockType"] = "STREAM";
					}
					else if (num2 > reexectype.Count - 1)
					{
						dataRow["BlockType"] = "BLOCK";
					}
					else
					{
						dataRow["BlockType"] = reexectype[num2];
					}
					Forth = (string)(dataRow["BlockID"] = Forth.Trim());
					dataRow["Display1"] = string.Format("{0} {1}", dataRow["FortranType"].ToString(), dataRow["FortranID"].ToString());
					dataRow["Display2"] = string.Format("{0} {1}", dataRow["BlockType"].ToString(), dataRow["BlockID"].ToString());
					Blocks.Rows.Add(dataRow);
					length = Forth.Length;
					if (length > num)
					{
						num = length;
					}
				}
			}
			streamReader.Close();
			fileStream.Close();
			return result;
		}

		private int ParseFormatLine(string line, ref string Second, ref string Third, ref string Forth)
		{
			string[] array = line.Split(' ');
			Second = array[1];
			Third = array[2];
			Forth = array[3];
			return int.Parse(array[0]);
		}

		private void lvwItems_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (!(lvwItems.SelectedItem is DataRowView))
			{
				SelectedItem = -1;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/reexecutefortrandlg.xaml", UriKind.Relative);
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
				reexecuteFortranDlg = (ReexecuteFortranDlg)target;
				break;
			case 2:
				lvwItems = (System.Windows.Controls.ListView)target;
				lvwItems.SelectionChanged += lvwItems_SelectionChanged;
				break;
			case 3:
				btnMoveTo = (System.Windows.Controls.Button)target;
				btnMoveTo.Click += btnMoveTo_Click;
				break;
			case 4:
				btnContinue = (System.Windows.Controls.Button)target;
				btnContinue.Click += btnContinue_Click;
				break;
			case 5:
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
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

		public static T GetChildObject<T>(DependencyObject obj, string name) where T : FrameworkElement
		{
			DependencyObject dependencyObject = null;
			T val = null;
			for (int i = 0; i < VisualTreeHelper.GetChildrenCount(obj); i++)
			{
				dependencyObject = VisualTreeHelper.GetChild(obj, i);
				if (dependencyObject is T && ((T)dependencyObject).Name == name)
				{
					return (T)dependencyObject;
				}
				val = GetChildObject<T>(dependencyObject, name);
				if (val != null)
				{
					return val;
				}
			}
			return null;
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
	public class ReinitDlgViewModel : INotifyPropertyChanged
	{
		private Window _dlg;

		private List<SimBlockTypeClass> _itemSets;

		private string _selectedClass;

		private ApwnSimBlockItems _reinitItems;

		private string _caption;

		private string _selctedBlocks;

		private ApwnSimBlockItems _selectedItem;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public CxsCase currentCase { get; set; }

		private IUnityContainer UnityContainer { get; set; }

		public string HelpFile => "userguide1.chm";

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
				}
			}
		}

		public ObservableCollection<ApwnSimBlockItems> AvailableItems { get; set; }

		public Visibility VisibleBlocks
		{
			get
			{
				if (_reinitItems == null || _reinitItems.Items == null || _reinitItems.Items.Count == 0)
				{
					return Visibility.Collapsed;
				}
				return Visibility.Visible;
			}
		}

		public ApwnSimBlockItems ReinitItems
		{
			get
			{
				return _reinitItems;
			}
			private set
			{
				if (_reinitItems != value)
				{
					_reinitItems = value;
					_reinitItems.Parent = null;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("ReinitItems"));
					}
				}
			}
		}

		public string SelectedCaption
		{
			get
			{
				return _caption;
			}
			set
			{
				_caption = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedCaption"));
				}
			}
		}

		public string SelectedBlocks
		{
			get
			{
				return _selctedBlocks;
			}
			set
			{
				if (_selctedBlocks != value)
				{
					_selctedBlocks = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedBlocks"));
					}
				}
				(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ApwnSimBlockItems SelectedItem
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
					}
				}
				string strBlocks = SelectedBlocks;
				UpdateSeletedBlocks(SelectedItem, ref strBlocks);
				SelectedBlocks = strBlocks;
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

		public ReinitDlgViewModel(IUnityContainer container, Window dlg)
		{
			_dlg = dlg;
			UnityContainer = container;
			currentCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			bool flag = (int)currentCase.BatchGet("Top.Solver.IsCurSeqBlkBatch", "value") == 1;
			Classes = new List<MoveToType>();
			if (flag)
			{
				Classes.Add(new MoveToType
				{
					name = WpfSimdllResources.Batch_Restart,
					caption = WpfSimdllResources.Batch_Restart,
					GRlstmovID = -2,
					extraItem = null,
					showtype = 0,
					returntype = 5
				});
			}
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Simulation,
				caption = WpfSimdllResources.Simulation,
				GRlstmovID = -2,
				extraItem = null,
				showtype = 0,
				returntype = 4
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Block,
				caption = WpfSimdllResources.Block,
				GRlstmovID = 1,
				extraItem = "All",
				showtype = 1,
				returntype = 1
			});
			object obj = currentCase.BatchGet("Top.Solver.ReinitList", "value");
			if (((string)obj).IndexOf("Convergence") != -1)
			{
				Classes.Add(new MoveToType
				{
					name = WpfSimdllResources.Convergence,
					caption = WpfSimdllResources.Convergence,
					GRlstmovID = 2,
					extraItem = "All",
					showtype = 2,
					returntype = 2
				});
			}
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Streams,
				caption = WpfSimdllResources.Streams,
				GRlstmovID = 12,
				extraItem = "All",
				showtype = 10,
				returntype = 3
			});
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			if (_itemSets != null && _itemSets.Count == 1)
			{
				Classes.Clear();
				if (flag)
				{
					Classes.Add(new MoveToType
					{
						name = WpfSimdllResources.Batch_Restart,
						caption = WpfSimdllResources.Batch_Restart,
						GRlstmovID = -2,
						extraItem = null,
						showtype = 0,
						returntype = 5
					});
				}
				Classes.Add(new MoveToType
				{
					name = WpfSimdllResources.Simulation,
					caption = WpfSimdllResources.Simulation,
					GRlstmovID = -2,
					extraItem = null,
					showtype = 0,
					returntype = 4
				});
			}
			SelectedClass = Classes[0].name;
		}

		private void OnSelectedClassChanged()
		{
			int num = 0;
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectedCaption = @class.caption;
					SelectedBlocks = "";
					break;
				}
				if (!(@class.name == WpfSimdllResources.Batch_Restart))
				{
					num++;
				}
			}
			ReinitItems = new ApwnSimBlockItems();
			ReinitItems.Items = new ObservableCollection<ApwnSimBlockItems>();
			ApwnSimBlockItems apwnSimBlockItems = ApwnSimBlockItems.CreateSelectAllSimBlockItems();
			if (num < Classes.Count)
			{
				apwnSimBlockItems.Items = new ObservableCollection<ApwnSimBlockItems>(_itemSets[num].Items);
				AvailableItems = apwnSimBlockItems.Items;
			}
			if (apwnSimBlockItems.Items != null && apwnSimBlockItems.Items.Count != 0)
			{
				ReinitItems.Items.Add(apwnSimBlockItems);
			}
			ReinitItems.Checked = false;
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("VisibleBlocks"));
			}
		}

		private void DealNodeString(ref string strBlocks, string strTag, bool bAdd)
		{
			char[] trimChars = new char[1] { ' ' };
			string[] array = strBlocks.TrimEnd(trimChars).Split(' ');
			for (int i = 0; i < array.Count(); i++)
			{
				if (array[i] == strTag)
				{
					if (bAdd)
					{
						return;
					}
					array[i] = "";
					break;
				}
			}
			if (bAdd)
			{
				strBlocks += strTag;
				strBlocks += " ";
				return;
			}
			strBlocks = "";
			for (int j = 0; j < array.Count(); j++)
			{
				if (!string.IsNullOrEmpty(array[j]))
				{
					strBlocks += array[j];
					strBlocks += " ";
				}
			}
		}

		private void UpdateSeletedBlocks(ApwnSimBlockItems curBlock, ref string strBlocks)
		{
			if (curBlock == null)
			{
				strBlocks = "";
				return;
			}
			if (curBlock.Type == "-1")
			{
				foreach (ApwnSimBlockItems item in curBlock.Items)
				{
					if (item.Type == "-1")
					{
						UpdateSeletedBlocks(item, ref strBlocks);
					}
					else
					{
						DealNodeString(ref strBlocks, item.Tag, item.Checked.HasValue && item.Checked.Value);
					}
				}
				return;
			}
			DealNodeString(ref strBlocks, curBlock.Tag, curBlock.Checked.HasValue && curBlock.Checked.Value);
		}

		private void ExecuteCommandOnOK(object arg)
		{
			object[] array = null;
			string text = null;
			if (SelectedClass == WpfSimdllResources.Simulation)
			{
				text = "Simulation";
			}
			else if (SelectedClass == WpfSimdllResources.Block)
			{
				text = "Block";
			}
			else if (SelectedClass == WpfSimdllResources.Convergence)
			{
				text = "Convergence";
			}
			else if (SelectedClass == WpfSimdllResources.Streams)
			{
				text = "Streams";
			}
			if (!string.IsNullOrEmpty(SelectedBlocks))
			{
				char[] trimChars = new char[1] { ' ' };
				string[] array2 = SelectedBlocks.TrimEnd(trimChars).Split(' ');
				array = new object[array2.Count() + 1];
				array[0] = text;
				for (int i = 0; i < array2.Count(); i++)
				{
					array[i + 1] = array2[i];
				}
			}
			bool flag = true;
			if ((!ScriptingSupport.Enabled || !ScriptingSupport.ScriptRunning) && SelectedClass == WpfSimdllResources.Simulation && MMMessageBox.Show(Reinit.GetPrompt(), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OKCancel, MMMessageBoxImage.Question) == MMMessageBoxResult.Cancel)
			{
				flag = false;
			}
			if (!flag)
			{
				return;
			}
			if (array != null)
			{
				currentCase.InvokeAction("Top.Solver", "Initialize", array);
				if (UnityContainer != null && array[0].ToString().ToUpper() == WpfSimdllResources.Block.ToUpper())
				{
					List<string> list = new List<string>();
					for (int j = 1; j < array.Count(); j++)
					{
						string path = "Top.appModelV8.Blocks." + array[j];
						object obj = currentCase.BatchGet(path, "type");
						if (obj != null && !(obj.ToString().ToUpper() != "RADFRAC"))
						{
							list.Add(array[j].ToString());
						}
					}
					ReInitEventArgs payload = new ReInitEventArgs(list);
					UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ReInitEvent>().Publish(payload);
				}
			}
			else if (SelectedClass == WpfSimdllResources.Batch_Restart)
			{
				array = new object[1] { "Batch" };
				currentCase.InvokeAction("Top.Solver", "Initialize", array);
			}
			else
			{
				currentCase.InvokeAction("Top.Solver", "Initialize");
				ReInitEventArgs payload2 = new ReInitEventArgs(null);
				UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<ReInitEvent>().Publish(payload2);
			}
			_dlg.DialogResult = true;
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name && @class.GRlstmovID <= 0)
				{
					return true;
				}
			}
			if (ReinitItems != null && _reinitItems.Items != null && ReinitItems.Items.Count > 0 && !string.IsNullOrEmpty(SelectedBlocks))
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			_dlg.DialogResult = false;
		}
	}
	public class ReinitDlg : Window, IComponentConnector, IStyleConnector
	{
		private IUnityContainer Container;

		private ReinitDlgViewModel ViewModel;

		private bool _contentLoaded;

		public ReinitDlg(IUnityContainer container)
		{
			InitializeComponent();
			Container = container;
			base.Loaded += ReinitDlg_Loaded;
		}

		private void ReinitDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new ReinitDlgViewModel(Container, this);
			base.DataContext = ViewModel;
			if (!ScriptingSupport.Enabled || !ScriptingSupport.ScriptRunning)
			{
				return;
			}
			if (!ScriptingSupport.DialogArgs[0].Name.ToUpper().Equals("SIMULATION"))
			{
				switch (ScriptingSupport.DialogArgs[0].Name)
				{
				case "block":
					ViewModel.SelectedClass = "Block";
					break;
				case "convergence":
					ViewModel.SelectedClass = "Convergence";
					break;
				case "streams":
					ViewModel.SelectedClass = "Streams";
					break;
				}
				if (ScriptingSupport.DialogArgs[0].Value.ToString().ToUpper().Equals("ALL"))
				{
					StringBuilder stringBuilder = new StringBuilder();
					foreach (ApwnSimBlockItems availableItem in ViewModel.AvailableItems)
					{
						stringBuilder.Append(availableItem.Name);
						stringBuilder.Append(' ');
					}
					ViewModel.SelectedBlocks = stringBuilder.ToString().Trim();
				}
				else
				{
					ViewModel.SelectedBlocks = ScriptingSupport.DialogArgs[0].Value.ToString();
				}
			}
			ViewModel.CommandOnOK.Execute(null);
			Close();
		}

		private void CheckBox_Click(object sender, RoutedEventArgs e)
		{
			if (ViewModel != null)
			{
				ApwnSimBlockItems apwnSimBlockItems = (sender as System.Windows.Controls.CheckBox).DataContext as ApwnSimBlockItems;
				if (apwnSimBlockItems != null && apwnSimBlockItems.Checked != true)
				{
					apwnSimBlockItems.Checked = false;
				}
				ViewModel.SelectedItem = apwnSimBlockItems;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/reinitdlg.xaml", UriKind.Relative);
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

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((System.Windows.Controls.CheckBox)target).Click += CheckBox_Click;
			}
		}
	}
	public class SimConnectDlg : Window, IComponentConnector
	{
		internal SimConnectDlg dlgSimConnect;

		internal System.Windows.Controls.ComboBox cboServerType;

		internal System.Windows.Controls.TextBox txtNodeName;

		internal System.Windows.Controls.TextBox txtUserName;

		internal PasswordBox txtPassword;

		internal System.Windows.Controls.TextBox txtWorkingDir;

		internal System.Windows.Controls.RadioButton rdSaveDefault;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		internal System.Windows.Controls.Button btnHelp;

		private bool _contentLoaded;

		public SimConnectDlg()
		{
			InitializeComponent();
			base.Loaded += SimConnectDlg_Loaded;
		}

		private void SimConnectDlg_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = new SimConnectDlgViewModel();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/simconnectdlg.xaml", UriKind.Relative);
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
				dlgSimConnect = (SimConnectDlg)target;
				break;
			case 2:
				cboServerType = (System.Windows.Controls.ComboBox)target;
				break;
			case 3:
				txtNodeName = (System.Windows.Controls.TextBox)target;
				break;
			case 4:
				txtUserName = (System.Windows.Controls.TextBox)target;
				break;
			case 5:
				txtPassword = (PasswordBox)target;
				break;
			case 6:
				txtWorkingDir = (System.Windows.Controls.TextBox)target;
				break;
			case 7:
				rdSaveDefault = (System.Windows.Controls.RadioButton)target;
				break;
			case 8:
				btnOK = (System.Windows.Controls.Button)target;
				break;
			case 9:
				btnCancel = (System.Windows.Controls.Button)target;
				break;
			case 10:
				btnHelp = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[XmlType(TypeName = "Class")]
	public class StopSetList
	{
		public string Action { get; set; }

		public string Type { get; set; }

		public string Block { get; set; }
	}
	public class StopPointDlgViewModel : INotifyPropertyChanged
	{
		private List<SimBlockTypeClass> _itemSets;

		private string _selectedClass;

		private string _caption;

		private List<ApwnSimBlockItems> _stopPointItems;

		private ApwnSimBlockItems _selectedItem;

		private IList _selectedAcceptedProps;

		private Window _dlg;

		private int _nCurrentShowType;

		private ObservableCollection<StopSetList> _allOldStopPoints;

		private ObservableCollection<StopSetList> _allRemovedStopPoints;

		private ObservableCollection<StopSetList> _allStopPoints;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private DelegateCommand<object> _commandOnStopBefore;

		private DelegateCommand<object> _commandOnStopAfter;

		private DelegateCommand<object> _commandOnRemove;

		private DelegateCommand<object> _commandOnClear;

		public string HelpFile => "userguide1.chm";

		private IUnityContainer UnityContainer { get; set; }

		public List<MoveToType> Classes { get; private set; }

		public string SelectedClass
		{
			get
			{
				return _selectedClass;
			}
			set
			{
				if (_selectedClass != value)
				{
					_selectedClass = value;
					OnSelectedClassChanged();
				}
			}
		}

		public string SelectedCaption
		{
			get
			{
				return _caption;
			}
			protected set
			{
				_caption = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedCaption"));
				}
			}
		}

		public List<ApwnSimBlockItems> StopPointItems
		{
			get
			{
				return _stopPointItems;
			}
			private set
			{
				if (_stopPointItems != value)
				{
					_stopPointItems = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("StopPointItems"));
					}
				}
			}
		}

		public ApwnSimBlockItems SelectedItem
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
						(CommandOnStopBefore as DelegateCommand<object>).RaiseCanExecuteChanged();
						(CommandOnStopAfter as DelegateCommand<object>).RaiseCanExecuteChanged();
					}
				}
			}
		}

		public IList SelectedAcceptedProps
		{
			get
			{
				return _selectedAcceptedProps;
			}
			set
			{
				_selectedAcceptedProps = value;
				if (this.PropertyChanged != null)
				{
					this.PropertyChanged(this, new PropertyChangedEventArgs("SelectedAcceptedProps"));
					(CommandOnRemove as DelegateCommand<object>).RaiseCanExecuteChanged();
				}
			}
		}

		public ObservableCollection<StopSetList> AllStopPoints
		{
			get
			{
				return _allStopPoints;
			}
			set
			{
				if (_allStopPoints != value)
				{
					_allStopPoints = value;
					if (this.PropertyChanged != null)
					{
						this.PropertyChanged(this, new PropertyChangedEventArgs("AllStopPoints"));
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

		public ICommand CommandOnStopBefore
		{
			get
			{
				if (_commandOnStopBefore == null)
				{
					_commandOnStopBefore = new DelegateCommand<object>(ExecuteCommandOnStopBefore, CanExecuteCommandOnStopBefore);
				}
				return _commandOnStopBefore;
			}
		}

		public ICommand CommandOnStopAfter
		{
			get
			{
				if (_commandOnStopAfter == null)
				{
					_commandOnStopAfter = new DelegateCommand<object>(ExecuteCommandOnStopAfter, CanExecuteCommandOnStopAfter);
				}
				return _commandOnStopAfter;
			}
		}

		public ICommand CommandOnRemove
		{
			get
			{
				if (_commandOnRemove == null)
				{
					_commandOnRemove = new DelegateCommand<object>(ExecuteCommandOnRemove, CanExecuteCommandOnRemove);
				}
				return _commandOnRemove;
			}
		}

		public ICommand CommandOnClear
		{
			get
			{
				if (_commandOnClear == null)
				{
					_commandOnClear = new DelegateCommand<object>(ExecuteCommandOnClear, CanExecuteCommandOnClear);
				}
				return _commandOnClear;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnSelectedClassChanged()
		{
			int num = 0;
			foreach (MoveToType @class in Classes)
			{
				if (_selectedClass == @class.name)
				{
					SelectedCaption = @class.caption;
					break;
				}
				num++;
			}
			if (num < Classes.Count)
			{
				StopPointItems = _itemSets[num].Items;
				_nCurrentShowType = Classes[num].showtype;
				if (StopPointItems.Count > 0)
				{
					SelectedItem = StopPointItems[0];
				}
				else
				{
					SelectedItem = null;
				}
			}
		}

		public StopPointDlgViewModel(IUnityContainer container, Window dlg)
		{
			_dlg = dlg;
			Classes = new List<MoveToType>();
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Block,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BlockIDs,
				GRlstmovID = 1,
				extraItem = null,
				showtype = 1,
				returntype = 1
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Convergence,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_ConvergenceIDs,
				GRlstmovID = 2,
				extraItem = null,
				showtype = 2,
				returntype = 2
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Sensitivity,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_SensitivityIDs,
				GRlstmovID = 3,
				extraItem = null,
				showtype = 5,
				returntype = 5
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Transfer,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_TransferIDs,
				GRlstmovID = 5,
				extraItem = null,
				showtype = 7,
				returntype = 6
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Calculator,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_CalculatorIDs,
				GRlstmovID = 4,
				extraItem = null,
				showtype = 8,
				returntype = 7
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Utilities,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_UtilityIDs,
				GRlstmovID = 8,
				extraItem = null,
				showtype = 9,
				returntype = 8
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Balance,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BalanceIDs,
				GRlstmovID = 11,
				extraItem = null,
				showtype = 11,
				returntype = 10
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.PressureRelief,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_PressureIDs,
				GRlstmovID = 9,
				extraItem = null,
				showtype = 12,
				returntype = 11
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Regression,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_RegressionIDs,
				GRlstmovID = 10,
				extraItem = null,
				showtype = 13,
				returntype = 12
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.Measurement,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_MeasurementIDs,
				GRlstmovID = 14,
				extraItem = null,
				showtype = 14,
				returntype = 21
			});
			Classes.Add(new MoveToType
			{
				name = WpfSimdllResources.BAConvergence,
				caption = WpfSimdllResources.WpfSimdll_ReinitDlg_BAConvergenceIDs,
				GRlstmovID = 16,
				extraItem = null,
				showtype = 16,
				returntype = 22
			});
			UnityContainer = container;
			object obj = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).BatchGet("Top.Solver.StopPointList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<SimBlockTypeClass>));
				StringReader textReader = new StringReader(obj as string);
				_itemSets = xmlSerializer.Deserialize(textReader) as List<SimBlockTypeClass>;
			}
			SelectedClass = Classes[0].name;
			if (RefreshStopList())
			{
				AllStopPoints = new ObservableCollection<StopSetList>(_allOldStopPoints);
			}
		}

		private bool RefreshStopList()
		{
			object obj = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).BatchGet("Top.Solver.StopExistPointList", "value");
			if (obj != null)
			{
				XmlSerializer xmlSerializer = new XmlSerializer(typeof(ObservableCollection<StopSetList>));
				StringReader textReader = new StringReader(obj as string);
				_allOldStopPoints = xmlSerializer.Deserialize(textReader) as ObservableCollection<StopSetList>;
				return true;
			}
			return false;
		}

		private bool IsCanPointSetAction(string action)
		{
			if (SelectedItem == null || SelectedItem.Name == null || AllStopPoints == null)
			{
				return false;
			}
			if (SelectedItem.Type == "-1")
			{
				return false;
			}
			foreach (StopSetList allStopPoint in AllStopPoints)
			{
				if (allStopPoint.Block == SelectedItem.Tag && allStopPoint.Action == action && allStopPoint.Type == SelectedClass.ToUpper())
				{
					return false;
				}
			}
			return true;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			foreach (StopSetList allStopPoint in AllStopPoints)
			{
				bool flag = false;
				foreach (StopSetList allOldStopPoint in _allOldStopPoints)
				{
					if (allOldStopPoint.Action == allStopPoint.Action && allOldStopPoint.Block == allStopPoint.Block && allStopPoint.Type == allOldStopPoint.Type)
					{
						flag = true;
						_allOldStopPoints.Remove(allOldStopPoint);
						break;
					}
				}
				if (!flag)
				{
					if (allStopPoint.Action == WpfSimdllResources.ActionStopAfter)
					{
						cxsCase.InvokeAction("Top.Solver", "StopPoint", allStopPoint.Block, _nCurrentShowType, 2);
					}
					if (allStopPoint.Action == WpfSimdllResources.ActionStopBefore)
					{
						cxsCase.InvokeAction("Top.Solver", "StopPoint", allStopPoint.Block, _nCurrentShowType, 1);
					}
				}
			}
			foreach (StopSetList allOldStopPoint2 in _allOldStopPoints)
			{
				if (allOldStopPoint2.Action == WpfSimdllResources.ActionStopAfter)
				{
					cxsCase.InvokeAction("Top.Solver", "RemoveStopPoint", allOldStopPoint2.Block, 2);
				}
				if (allOldStopPoint2.Action == WpfSimdllResources.ActionStopBefore)
				{
					cxsCase.InvokeAction("Top.Solver", "RemoveStopPoint", allOldStopPoint2.Block, 1);
				}
			}
			_dlg.DialogResult = true;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			if (_allRemovedStopPoints != null)
			{
				CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
				foreach (StopSetList allRemovedStopPoint in _allRemovedStopPoints)
				{
					if (allRemovedStopPoint.Action == WpfSimdllResources.ActionStopAfter)
					{
						cxsCase.InvokeAction("Top.Solver", "StopPoint", allRemovedStopPoint.Block, _nCurrentShowType, 2);
					}
					if (allRemovedStopPoint.Action == WpfSimdllResources.ActionStopBefore)
					{
						cxsCase.InvokeAction("Top.Solver", "StopPoint", allRemovedStopPoint.Block, _nCurrentShowType, 1);
					}
				}
			}
			_dlg.DialogResult = false;
		}

		private void ExecuteCommandOnStopBefore(object arg)
		{
			if (AllStopPoints.Count >= 10)
			{
				MMMessageBox.Show(WpfSimdllResources.StopPointLimited, WpfSimdllResources.StopPoint, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				return;
			}
			StopSetList item = new StopSetList
			{
				Action = WpfSimdllResources.ActionStopBefore,
				Block = SelectedItem.Tag,
				Type = SelectedClass.ToUpper()
			};
			AllStopPoints.Add(item);
			(CommandOnClear as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnStopBefore as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecuteCommandOnStopBefore(object arg)
		{
			return IsCanPointSetAction(WpfSimdllResources.ActionStopBefore);
		}

		private void ExecuteCommandOnStopAfter(object arg)
		{
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			if (AllStopPoints.Count >= 10)
			{
				MMMessageBox.Show(WpfSimdllResources.StopPointLimited, WpfSimdllResources.StopPoint, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				return;
			}
			StopSetList item = new StopSetList
			{
				Action = WpfSimdllResources.ActionStopAfter,
				Block = SelectedItem.Tag,
				Type = SelectedClass.ToUpper()
			};
			AllStopPoints.Add(item);
			(CommandOnClear as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnStopAfter as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecuteCommandOnStopAfter(object arg)
		{
			return IsCanPointSetAction(WpfSimdllResources.ActionStopAfter);
		}

		private void ExecuteCommandOnRemove(object arg)
		{
			if (SelectedAcceptedProps != null && SelectedAcceptedProps.Count > 0)
			{
				CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
				_allRemovedStopPoints = new ObservableCollection<StopSetList>();
				while (SelectedAcceptedProps.Count > 0)
				{
					StopSetList stopSetList = SelectedAcceptedProps[0] as StopSetList;
					AllStopPoints.Remove(stopSetList);
					foreach (StopSetList allOldStopPoint in _allOldStopPoints)
					{
						if (allOldStopPoint.Type == stopSetList.Type && allOldStopPoint.Block == stopSetList.Block && allOldStopPoint.Action == allOldStopPoint.Action)
						{
							if (stopSetList.Action == WpfSimdllResources.ActionStopAfter)
							{
								cxsCase.InvokeAction("Top.Solver", "RemoveStopPoint", stopSetList.Block, 2);
							}
							if (stopSetList.Action == WpfSimdllResources.ActionStopBefore)
							{
								cxsCase.InvokeAction("Top.Solver", "RemoveStopPoint", stopSetList.Block, 1);
							}
							_allRemovedStopPoints.Add(stopSetList);
							break;
						}
					}
				}
				RefreshStopList();
			}
			(CommandOnClear as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnRemove as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecuteCommandOnRemove(object arg)
		{
			if (SelectedAcceptedProps != null && SelectedAcceptedProps.Count > 0)
			{
				return true;
			}
			return false;
		}

		private void ExecuteCommandOnClear(object arg)
		{
			AllStopPoints.Clear();
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
			(CommandOnClear as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecuteCommandOnClear(object arg)
		{
			if (AllStopPoints != null && AllStopPoints.Count > 0)
			{
				return true;
			}
			return false;
		}
	}
	public class StopPointDlg : Window, IComponentConnector
	{
		private IUnityContainer UnityContainer;

		private StopPointDlgViewModel ViewModel;

		internal ListBoxEx lvPointList;

		private bool _contentLoaded;

		public StopPointDlg(IUnityContainer container)
		{
			InitializeComponent();
			UnityContainer = container;
			base.Loaded += StopPointDlg_Loaded;
		}

		private void StopPointDlg_Loaded(object sender, RoutedEventArgs e)
		{
			ViewModel = new StopPointDlgViewModel(UnityContainer, this);
			base.DataContext = ViewModel;
		}

		private void TreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			System.Windows.Controls.TreeView treeView = sender as System.Windows.Controls.TreeView;
			if (ViewModel != null)
			{
				ViewModel.SelectedItem = treeView.SelectedItem as ApwnSimBlockItems;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/stoppointdlg.xaml", UriKind.Relative);
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
				((System.Windows.Controls.TreeView)target).SelectedItemChanged += TreeView_SelectedItemChanged;
				break;
			case 2:
				lvPointList = (ListBoxEx)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ListBoxEx : System.Windows.Controls.ListBox
	{
		public static readonly DependencyProperty BindableSelectedItemsProperty = DependencyProperty.Register("BindableSelectedItems", typeof(IList), typeof(ListBoxEx));

		public IList BindableSelectedItems
		{
			get
			{
				return (IList)GetValue(BindableSelectedItemsProperty);
			}
			set
			{
				SetValue(BindableSelectedItemsProperty, value);
			}
		}

		protected override void OnSelectionChanged(SelectionChangedEventArgs e)
		{
			BindableSelectedItems = base.SelectedItems;
			base.OnSelectionChanged(e);
		}
	}
	public class UseFortranDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public UseFortranDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "MoveTo", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class UseFortranDlg : Window, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal System.Windows.Controls.TextBox txtName;

		internal System.Windows.Controls.Button btnOK;

		internal System.Windows.Controls.Button btnCancel;

		private bool _contentLoaded;

		public string name { get; protected set; }

		[Microsoft.Practices.Unity.Dependency]
		public MoveToDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as MoveToDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public UseFortranDlg()
		{
			InitializeComponent();
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as MoveToDlg).DataContext = args.NewValue;
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			name = txtName.Text;
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/usefortrandlg.xaml", UriKind.Relative);
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
				txtName = (System.Windows.Controls.TextBox)target;
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
	public class BatchSubmitDlg : Window, IComponentConnector
	{
		private string m_runid;

		private string m_remoteDirectory;

		private string m_commandQualifiers;

		private bool m_deleteTemporary;

		internal System.Windows.Controls.Button btn_OK;

		internal System.Windows.Controls.Button btn_Cancel;

		internal System.Windows.Controls.Button btn_Help;

		internal System.Windows.Controls.Label lbl_Runid;

		internal System.Windows.Controls.TextBox txt_ChosenJob;

		internal System.Windows.Controls.Button btn_Settings;

		internal System.Windows.Controls.GroupBox gb_Options;

		internal System.Windows.Controls.Label lbl_Directory;

		internal System.Windows.Controls.TextBox txt_Directory;

		internal System.Windows.Controls.Label lbl_Qualifiers;

		internal System.Windows.Controls.TextBox txt_Qualifiers;

		internal System.Windows.Controls.CheckBox chk_DeleteFiles;

		private bool _contentLoaded;

		public string RunID
		{
			get
			{
				return m_runid;
			}
			set
			{
				m_runid = value;
			}
		}

		public string RemoteDirectory
		{
			get
			{
				return m_remoteDirectory;
			}
			set
			{
				m_remoteDirectory = value;
			}
		}

		public string CommandQualifiers
		{
			get
			{
				return m_commandQualifiers;
			}
			set
			{
				m_commandQualifiers = value;
			}
		}

		public bool DeleteTemporary
		{
			get
			{
				return m_deleteTemporary;
			}
			set
			{
				m_deleteTemporary = value;
			}
		}

		public BatchSubmitDlg()
		{
			InitializeComponent();
			base.ResizeMode = ResizeMode.NoResize;
		}

		private void btn_Help_Click(object sender, RoutedEventArgs e)
		{
		}

		private void btn_OK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void btn_Cancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void btn_Settings_Click(object sender, RoutedEventArgs e)
		{
			new RunSettingsDlg().ShowDialog();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/batchsubmitdlg.xaml", UriKind.Relative);
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
				btn_OK = (System.Windows.Controls.Button)target;
				btn_OK.Click += btn_OK_Click;
				break;
			case 2:
				btn_Cancel = (System.Windows.Controls.Button)target;
				btn_Cancel.Click += btn_Cancel_Click;
				break;
			case 3:
				btn_Help = (System.Windows.Controls.Button)target;
				btn_Help.Click += btn_Help_Click;
				break;
			case 4:
				lbl_Runid = (System.Windows.Controls.Label)target;
				break;
			case 5:
				txt_ChosenJob = (System.Windows.Controls.TextBox)target;
				break;
			case 6:
				btn_Settings = (System.Windows.Controls.Button)target;
				btn_Settings.Click += btn_Settings_Click;
				break;
			case 7:
				gb_Options = (System.Windows.Controls.GroupBox)target;
				break;
			case 8:
				lbl_Directory = (System.Windows.Controls.Label)target;
				break;
			case 9:
				txt_Directory = (System.Windows.Controls.TextBox)target;
				break;
			case 10:
				lbl_Qualifiers = (System.Windows.Controls.Label)target;
				break;
			case 11:
				txt_Qualifiers = (System.Windows.Controls.TextBox)target;
				break;
			case 12:
				chk_DeleteFiles = (System.Windows.Controls.CheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ComVisible(true)]
	[Guid("AAEF7397-2FAE-45E3-8A1B-52EDE3A54A10")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IDialogDriver
	{
		void Show(string dialogName);

		bool? ShowDialog(string dialogName);

		int ShowEOExportWzd(Window own, string caption, string obj, int local, int import, int hier);

		Type GetType(string name);

		int SimAskReexecute(string name);

		int SimAskReexecuteFortran(string filename, ref string id);

		int ShowRegression();

		void ShowWaitingForEditorDlg(uint Process, string Message);

		int ShowUserFortran(ref string name, int len);

		void ShowStopPointManagerDlg(Window Own, IUnityContainer container);

		void ShowMoveToPointManagerDlg(Window Own, IUnityContainer container);

		void ShowSimReportsDlg(Window Own, IUnityContainer container);

		bool ShowSimReinitDlg(Window Own, IUnityContainer container);

		void ShowSimPDBPutDlg(Window Own, IUnityContainer container);

		void ShowSimPDBGetDlg(Window Own, IUnityContainer container);

		int ShowSimConnectDlg();
	}
	[ComVisible(true)]
	[Guid("40E1498D-76D4-4706-86B6-8B9AB7441856")]
	[ProgId("AspenTech.AspenPlus.WpfSimdll.DialogDriver.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class DialogDriver : IDialogDriver
	{
		private IList<Type> lstDialogs = new List<Type>();

		public static IUnityContainer Container { get; set; }

		public static SynchronizationContext SyncContext { get; set; }

		public DialogDriver()
		{
			lstDialogs.Add(typeof(DRSRegressionRunDlg));
			lstDialogs.Add(typeof(EOReinitDlg));
			lstDialogs.Add(typeof(PDBActivateDlg));
			lstDialogs.Add(typeof(ReExecuteBlockDlg));
			lstDialogs.Add(typeof(ReexecuteFortranDlg));
			lstDialogs.Add(typeof(UseFortranDlg));
			lstDialogs.Add(typeof(BatchSubmitDlg));
			lstDialogs.Add(typeof(JobStatDlg));
		}

		public void Show(string dialogName)
		{
			Window window = null;
			Type type = GetType(dialogName);
			if (type != null)
			{
				window = (Window)Activator.CreateInstance(type);
			}
			window?.Show();
			window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
		}

		public bool? ShowDialog(string dialogName)
		{
			Window window = null;
			Type type = GetType(dialogName);
			if (type != null)
			{
				window = (Window)Activator.CreateInstance(type);
			}
			if (window != null)
			{
				window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
				return window.ShowDialog();
			}
			return null;
		}

		public int ShowEOExportWzd(Window own, string caption, string obj, int local, int import, int hier)
		{
			Window w = new EOExportWzd(caption, obj, local, import, hier);
			w.Owner = own;
			if (w.Owner == null)
			{
				SyncContext.Send(delegate
				{
					IUnityContainer container = Container;
					if (container != null)
					{
						IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
						if (shellApplication != null)
						{
							w.Owner = shellApplication.MainWindows[0] as Window;
						}
					}
				}, null);
			}
			w.ShowDialog();
			return (w.DialogResult == true) ? 1 : 0;
		}

		public Type GetType(string name)
		{
			foreach (Type lstDialog in lstDialogs)
			{
				string text = lstDialog.ToString().ToUpper();
				int num = text.LastIndexOf('.');
				if (num != -1)
				{
					text = text.Substring(num + 1, text.Length - num - 1);
				}
				if (text == name.ToUpper())
				{
					return lstDialog;
				}
			}
			return null;
		}

		public int SimAskReexecute(string name)
		{
			if (string.IsNullOrEmpty(name))
			{
				return 2;
			}
			int ret = 0;
			SyncContext.Send(delegate
			{
				IUnityContainer container = Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null)
					{
						ReExecuteBlockDlg reExecuteBlockDlg = new ReExecuteBlockDlg();
						reExecuteBlockDlg.BlockName = name;
						reExecuteBlockDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						reExecuteBlockDlg.Owner = shellApplication.MainWindows[0] as Window;
						reExecuteBlockDlg.ShowDialog();
						ret = reExecuteBlockDlg.Choice;
					}
				}
			}, null);
			return ret;
		}

		public int SimAskReexecuteFortran(string filename, ref string id)
		{
			if (string.IsNullOrEmpty(filename))
			{
				return 0;
			}
			int ret = 0;
			string locid = null;
			if (MmgSor.MMGetSuppressM() == 1)
			{
				ret = -1;
				return ret;
			}
			SyncContext.Send(delegate
			{
				IUnityContainer container = Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null)
					{
						ReexecuteFortranDlg reexecuteFortranDlg = new ReexecuteFortranDlg();
						reexecuteFortranDlg.ReadEngineFile(filename);
						reexecuteFortranDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						reexecuteFortranDlg.Owner = shellApplication.MainWindows[0] as Window;
						reexecuteFortranDlg.ShowDialog();
						ret = reexecuteFortranDlg.Choice;
						locid = reexecuteFortranDlg.ItemSelected;
					}
				}
			}, null);
			if (locid != null)
			{
				id = locid;
			}
			return ret;
		}

		public int ShowRegression()
		{
			IUnityContainer container = Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					DRSRegressionRunDlg dRSRegressionRunDlg = new DRSRegressionRunDlg();
					dRSRegressionRunDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					dRSRegressionRunDlg.Owner = shellApplication.MainWindows[0] as Window;
					dRSRegressionRunDlg.ShowDialog();
					if (dRSRegressionRunDlg.DialogResult.Value)
					{
						return 1;
					}
					return 0;
				}
			}
			return 1;
		}

		public void ShowWaitingForEditorDlg(uint Process, string Message)
		{
			IUnityContainer container = Container;
			if (container == null)
			{
				return;
			}
			IShellApplication app = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
			if (app == null)
			{
				return;
			}
			try
			{
				SyncContext.Send(delegate
				{
					WaitingForEditorDlg waitingForEditorDlg = new WaitingForEditorDlg();
					waitingForEditorDlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					waitingForEditorDlg.Owner = app.MainWindows[0] as Window;
					waitingForEditorDlg.SetInfo(Process, Message);
					waitingForEditorDlg.ShowDialog();
				}, null);
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		public int ShowUserFortran(ref string name, int len)
		{
			if (string.IsNullOrEmpty(name))
			{
				return 0;
			}
			int nRet = 0;
			string retName = "";
			IUnityContainer container = Container;
			if (container != null && container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()) != null)
			{
				try
				{
					SyncContext.Send(delegate
					{
						UseFortranDlg useFortranDlg = new UseFortranDlg();
						useFortranDlg.ShowDialog();
						if (!string.IsNullOrEmpty(useFortranDlg.name))
						{
							retName = useFortranDlg.name;
							nRet = 1;
						}
					}, null);
				}
				catch (Exception ex)
				{
					_ = ex.Message;
				}
			}
			name = retName;
			return nRet;
		}

		public void ShowStopPointManagerDlg(Window Own, IUnityContainer container)
		{
			StopPointDlg stopPointDlg = new StopPointDlg(container);
			stopPointDlg.Owner = Own;
			stopPointDlg.ShowDialog();
		}

		public void ShowMoveToPointManagerDlg(Window Own, IUnityContainer container)
		{
			MoveToDlg moveToDlg = new MoveToDlg(container);
			moveToDlg.Owner = Own;
			moveToDlg.ShowDialog();
		}

		public void ShowSimReportsDlg(Window Own, IUnityContainer container)
		{
			ShowBlockTempDlg showBlockTempDlg = new ShowBlockTempDlg(container);
			showBlockTempDlg.Owner = Own;
			showBlockTempDlg.ShowDialog();
		}

		public void ShowSimReportsDlgInPropertiesMode(Window Own, IUnityContainer container)
		{
			container.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).Solver.InvokeAction("DisplayReport", "", 13);
		}

		public bool ShowSimReinitDlg(Window Own, IUnityContainer container)
		{
			if (new ReinitDlg(container)
			{
				Owner = Own
			}.ShowDialog() == true)
			{
				return true;
			}
			return false;
		}

		public void ShowSimPDBPutDlg(Window Own, IUnityContainer container)
		{
			PDBPutDlg pDBPutDlg = new PDBPutDlg(container);
			pDBPutDlg.Owner = Own;
			pDBPutDlg.ShowDialog();
		}

		public void ShowSimPDBGetDlg(Window Own, IUnityContainer container)
		{
			PDBGetDlg pDBGetDlg = new PDBGetDlg(container);
			pDBGetDlg.Owner = Own;
			pDBGetDlg.ShowDialog();
		}

		public int ShowSimConnectDlg()
		{
			Window window = new SimConnectDlg();
			IUnityContainer container = Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					window.Owner = shellApplication.MainWindows[0] as Window;
				}
			}
			bool? flag = window.ShowDialog();
			if (!flag.HasValue || !flag.Value)
			{
				return 0;
			}
			return 1;
		}
	}
	public class JobStatDlg : Window, IComponentConnector
	{
		private string m_jobText;

		internal System.Windows.Controls.Label lbl_SubmittedJobs;

		internal System.Windows.Controls.ListBox lst_Jobs;

		internal System.Windows.Controls.Label lbl_Job;

		internal System.Windows.Controls.TextBox txt_ChosenJob;

		internal System.Windows.Controls.Button btn_OK;

		internal System.Windows.Controls.Button btn_Cancel;

		internal System.Windows.Controls.Button btn_Help;

		private bool _contentLoaded;

		public string JobText
		{
			get
			{
				return m_jobText;
			}
			set
			{
				m_jobText = value;
			}
		}

		public JobStatDlg(ItemCollection items)
		{
			InitializeComponent();
			lst_Jobs.ItemsSource = items;
			base.ResizeMode = ResizeMode.NoResize;
		}

		private void btn_OK_Click(object sender, RoutedEventArgs e)
		{
			JobText = (string)lst_Jobs.SelectedItem;
			base.DialogResult = true;
			Close();
		}

		private void btn_Help_Click(object sender, RoutedEventArgs e)
		{
		}

		private void btn_Cancel_Click(object sender, RoutedEventArgs e)
		{
			JobText = null;
			base.DialogResult = false;
			Close();
		}

		private void lst_Jobs_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			object selectedItem = (sender as System.Windows.Controls.ListBox).SelectedItem;
			JobText = selectedItem.ToString();
			txt_ChosenJob.Text = JobText;
		}

		private void lst_Jobs_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			ListBoxItem listBoxItem = (sender as System.Windows.Controls.ListBox).SelectedItem as ListBoxItem;
			JobText = listBoxItem.Content.ToString();
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/jobstatdlg.xaml", UriKind.Relative);
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
				lbl_SubmittedJobs = (System.Windows.Controls.Label)target;
				break;
			case 2:
				lst_Jobs = (System.Windows.Controls.ListBox)target;
				lst_Jobs.SelectionChanged += lst_Jobs_SelectionChanged;
				lst_Jobs.MouseDoubleClick += lst_Jobs_MouseDoubleClick;
				break;
			case 3:
				lbl_Job = (System.Windows.Controls.Label)target;
				break;
			case 4:
				txt_ChosenJob = (System.Windows.Controls.TextBox)target;
				break;
			case 5:
				btn_OK = (System.Windows.Controls.Button)target;
				btn_OK.Click += btn_OK_Click;
				break;
			case 6:
				btn_Cancel = (System.Windows.Controls.Button)target;
				btn_Cancel.Click += btn_Cancel_Click;
				break;
			case 7:
				btn_Help = (System.Windows.Controls.Button)target;
				btn_Help.Click += btn_Help_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ApwnRunSettingsDlgViewModel : INotifyPropertyChanged
	{
		private string m_INSERT;

		private string m_STREAM;

		private string m_LINKEROPTIONS;

		private string m_RUNDEFINITION;

		private string m_COSTDATABANK;

		private int m_EXPRESSRUN;

		private int m_INTERACTIVELYLOAD;

		private bool m_InteractivelyLoadResultsEnable = true;

		private int m_ANIMATEFLOWSHEET;

		private int m_ALLOWRUN;

		private int m_EDITKEYWORD;

		private int m_save_ANIMATEFLOWSHEET;

		private string m_runid;

		private string m_remoteDirectory;

		private string m_commandQualifiers;

		private bool m_deleteTemporary;

		private DataTable m_dtJobStatus;

		private bool m_isAutoRunMode;

		private bool m_changed;

		private bool m_FromOK;

		public BatchSubmit bs = new BatchSubmit();

		private IApwnApplication _application;

		private bool _isDynamicUpdateChecked;

		public LoadResults _loadResults = new LoadResults();

		private bool Restarted;

		private DelegateCommand<object> _commandLoad;

		private DelegateCommand<object> _commandRestart;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private DelegateCommand<object> _commandOnApply;

		private bool m_bIsBtnEable;

		private DataRow m_lstLoadRow;

		private IUnityContainer UnityContainer { get; set; }

		public Window View { get; set; }

		public bool Changed
		{
			get
			{
				return m_changed;
			}
			set
			{
				m_changed = value;
				OnPropertyChanged("Changed");
			}
		}

		public string INSERT
		{
			get
			{
				return m_INSERT;
			}
			set
			{
				m_INSERT = value;
				Changed = true;
			}
		}

		public string STREAM
		{
			get
			{
				return m_STREAM;
			}
			set
			{
				m_STREAM = value;
				Changed = true;
			}
		}

		public string LINKEROPTIONS
		{
			get
			{
				return m_LINKEROPTIONS;
			}
			set
			{
				m_LINKEROPTIONS = value;
				Changed = true;
			}
		}

		public string RUNDEFINITION
		{
			get
			{
				return m_RUNDEFINITION;
			}
			set
			{
				m_RUNDEFINITION = value;
				Changed = true;
			}
		}

		public string COSTDATABANK
		{
			get
			{
				return m_COSTDATABANK;
			}
			set
			{
				m_COSTDATABANK = value;
				Changed = true;
			}
		}

		public int EXPRESSRUN
		{
			get
			{
				return m_EXPRESSRUN;
			}
			set
			{
				m_EXPRESSRUN = value;
				OnPropertyChanged("AnimateEnabled");
				Changed = true;
			}
		}

		public bool InteractivelyLoadResultsEnable => m_InteractivelyLoadResultsEnable;

		public int INTERACTIVELYLOAD
		{
			get
			{
				return m_INTERACTIVELYLOAD;
			}
			set
			{
				m_INTERACTIVELYLOAD = value;
				Changed = true;
			}
		}

		public int ANIMATEFLOWSHEET
		{
			get
			{
				return m_ANIMATEFLOWSHEET;
			}
			set
			{
				m_ANIMATEFLOWSHEET = value;
				Changed = true;
			}
		}

		public bool AnimateEnabled => m_EXPRESSRUN != 1;

		public bool IsAllowRunEnabled => !IsAutoRunMode;

		public int ALLOWRUN
		{
			get
			{
				return m_ALLOWRUN;
			}
			set
			{
				m_ALLOWRUN = value;
				Changed = true;
			}
		}

		public int EDITKEYWORD
		{
			get
			{
				return m_EDITKEYWORD;
			}
			set
			{
				m_EDITKEYWORD = value;
				Changed = true;
			}
		}

		public string RunID
		{
			get
			{
				return m_runid;
			}
			set
			{
				m_runid = value;
			}
		}

		public string RemoteDirectory
		{
			get
			{
				return m_remoteDirectory;
			}
			set
			{
				m_remoteDirectory = value;
			}
		}

		public string CommandQualifiers
		{
			get
			{
				return m_commandQualifiers;
			}
			set
			{
				m_commandQualifiers = value;
			}
		}

		public bool DeleteTemporary
		{
			get
			{
				return m_deleteTemporary;
			}
			set
			{
				m_deleteTemporary = value;
			}
		}

		public DataTable JobStatus
		{
			get
			{
				if (m_dtJobStatus == null)
				{
					m_dtJobStatus = new DataTable();
					m_dtJobStatus.Columns.Add("Runid", typeof(string));
					m_dtJobStatus.Columns.Add("Status", typeof(string));
					m_dtJobStatus.Columns.Add("Loaded", typeof(string));
				}
				return m_dtJobStatus;
			}
		}

		public bool IsAutoRunMode
		{
			get
			{
				return m_isAutoRunMode;
			}
			set
			{
				if (value != m_isAutoRunMode)
				{
					m_isAutoRunMode = value;
					Changed = true;
					OnPropertyChanged("IsAllowRunEnabled");
				}
			}
		}

		public bool IsAutoRunModeEnabled { get; set; }

		public IApwnApplication Application
		{
			get
			{
				if (_application == null)
				{
					_application = UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
				}
				return _application;
			}
		}

		public bool IsDynamicUpdateChecked
		{
			get
			{
				return _isDynamicUpdateChecked;
			}
			set
			{
				if (value != _isDynamicUpdateChecked)
				{
					_isDynamicUpdateChecked = value;
					Changed = true;
					OnPropertyChanged("IsDynamicUpdateChecked");
				}
			}
		}

		public bool IsDynamicUpdateEnabled
		{
			get
			{
				IApwnApplication apwnApplication = UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
				if (apwnApplication != null)
				{
					IApwnDocument activeDocument = apwnApplication.ActiveDocument;
					if (activeDocument != null)
					{
						return activeDocument.ActiveMode == ProblemModes.Simulation;
					}
					return false;
				}
				return false;
			}
		}

		public string HelpFile => "userguide1.chm";

		public ICommand CommandLoad
		{
			get
			{
				if (_commandLoad == null)
				{
					_commandLoad = new DelegateCommand<object>(ExecuteCommandLoad);
				}
				return _commandLoad;
			}
		}

		public bool IsLoadResultsEnabled
		{
			get
			{
				if (!Restarted)
				{
					return _loadResults.CanLoad();
				}
				return false;
			}
		}

		public ICommand CommandRestart
		{
			get
			{
				if (_commandRestart == null)
				{
					_commandRestart = new DelegateCommand<object>(ExecuteCommandRestart);
				}
				return _commandRestart;
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

		public ICommand CommandOnApply
		{
			get
			{
				if (_commandOnApply == null)
				{
					_commandOnApply = new DelegateCommand<object>(ExecuteCommandOnApply);
				}
				return _commandOnApply;
			}
		}

		public bool IsBtnLoadEable
		{
			get
			{
				return m_bIsBtnEable;
			}
			private set
			{
				if (m_bIsBtnEable != value)
				{
					m_bIsBtnEable = value;
					OnPropertyChanged("IsBtnLoadEable");
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ApwnRunSettingsDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
			CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			Changed = false;
			m_INSERT = (string)cxsCase.BatchGet("Top.Solver.Insert", "value");
			m_STREAM = (string)cxsCase.BatchGet("Top.Solver.Stream_lib", "value");
			m_RUNDEFINITION = (string)cxsCase.BatchGet("Top.Solver.Defaults", "value");
			m_LINKEROPTIONS = (string)cxsCase.BatchGet("Top.Solver.Dlopt", "value");
			if (m_LINKEROPTIONS == "\"\"")
			{
				m_LINKEROPTIONS = null;
			}
			m_COSTDATABANK = (string)cxsCase.BatchGet("Top.Solver.Ucost", "value");
			m_EXPRESSRUN = (int)cxsCase.BatchGet("Top.Solver.ExpressRun", "value");
			if (cxsCase.BatchGet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value").Equals("FLOWSHEET"))
			{
				m_INTERACTIVELYLOAD = (int)cxsCase.BatchGet("Top.Solver.InteractivelyLoad", "value");
			}
			else
			{
				m_InteractivelyLoadResultsEnable = false;
			}
			m_save_ANIMATEFLOWSHEET = (m_ANIMATEFLOWSHEET = (int)cxsCase.BatchGet("Top.Solver.AnimateFlowsheet", "value"));
			m_ALLOWRUN = HelperFuncs.AllowRunWithComplete();
			m_EDITKEYWORD = (int)cxsCase.BatchGet("Top.Solver.EditInput", "value");
			string jobStatus = AspenTech.AspenPlus.UnmanagedWrapper.JobStatus.GetJobStatus();
			if (!string.IsNullOrEmpty(jobStatus))
			{
				string[] array = jobStatus.Split('|');
				for (int i = 0; i < array.Length; i++)
				{
					string[] array2 = array[i].Split('^');
					if (array2.Length == 2)
					{
						DataRow dataRow = JobStatus.NewRow();
						dataRow["Runid"] = array2[0];
						dataRow["Status"] = array2[1];
						dataRow["Loaded"] = WpfSimdllResources.IsLoadNo;
						JobStatus.Rows.Add(dataRow);
					}
				}
			}
			m_runid = bs.GetRunid();
			if (m_runid != null && m_runid.Length > 8)
			{
				m_runid = m_runid.Substring(0, 8);
			}
			m_remoteDirectory = bs.GetLocation();
			m_commandQualifiers = bs.GetCLQ();
			m_deleteTemporary = bs.GetDelTemp();
			IsNormalRunEventArgs e = new IsNormalRunEventArgs(_isNormalRun: false, _isSet: false);
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<IsNormalRunEvent>().Publish(e);
			IsAutoRunMode = !e.IsNormalRun;
			IApwnApplication apwnApplication = container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>());
			if (apwnApplication != null)
			{
				IApwnDocument activeDocument = apwnApplication.ActiveDocument;
				if (activeDocument != null && activeDocument.ActiveMode == ProblemModes.Simulation)
				{
					IsAutoRunModeEnabled = true;
				}
				else
				{
					IsAutoRunModeEnabled = false;
				}
			}
			string text = CxsConverter.ValueToString(cxsCase.BatchGet("Top.appModelV8.Setup.Sim-Options.Input.ADSCNVG", "value"));
			_isDynamicUpdateChecked = text == "YES";
		}

		protected void OnPropertyChanged(string changed)
		{
			this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(changed));
		}

		private void ExecuteCommandLoad(object arg)
		{
			HappFuncs.HappRunM(3);
		}

		private void ExecuteCommandRestart(object arg)
		{
			_loadResults.Restart();
			Restarted = true;
			OnPropertyChanged("IsLoadResultsEnabled");
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			m_FromOK = true;
			ExecuteCommandOnApply(arg);
			View.Close();
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
			View.Close();
		}

		private void ExecuteCommandOnApply(object arg)
		{
			if (!Changed)
			{
				return;
			}
			CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			cxsCase.BatchSet("Top.Solver.Insert", "value", m_INSERT);
			cxsCase.BatchSet("Top.Solver.Stream_lib", "value", m_STREAM);
			cxsCase.BatchSet("Top.Solver.Defaults", "value", m_RUNDEFINITION);
			cxsCase.BatchSet("Top.Solver.Dlopt", "value", (m_LINKEROPTIONS == null) ? string.Empty : m_LINKEROPTIONS);
			cxsCase.BatchSet("Top.Solver.Ucost", "value", m_COSTDATABANK);
			cxsCase.BatchSet("Top.Solver.ExpressRun", "value", m_EXPRESSRUN);
			cxsCase.BatchSet("Top.Solver.InteractivelyLoad", "value", m_INTERACTIVELYLOAD);
			string text = CxsConverter.ValueToString(cxsCase.BatchGet("Top.appModelV8.Setup.Sim-Options.Input.ADSCNVG", "value"));
			if (text == "NO" && _isDynamicUpdateChecked)
			{
				cxsCase.BatchSet("Top.appModelV8.Setup.Sim-Options.Input.ADSCNVG", "value", "YES");
			}
			if (text == "YES" && !_isDynamicUpdateChecked)
			{
				cxsCase.BatchSet("Top.appModelV8.Setup.Sim-Options.Input.ADSCNVG", "value", "NO");
			}
			IsNormalRunEventArgs payload = new IsNormalRunEventArgs(!IsAutoRunMode, _isSet: true);
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<IsNormalRunEvent>().Publish(payload);
			if (!m_FromOK)
			{
				int num = (int)cxsCase.BatchGet("Top.Solver.InteractivelyLoad", "value");
				if (num != m_INTERACTIVELYLOAD)
				{
					INTERACTIVELYLOAD = num;
					OnPropertyChanged("INTERACTIVELYLOAD");
				}
			}
			if (m_save_ANIMATEFLOWSHEET != m_ANIMATEFLOWSHEET)
			{
				cxsCase.BatchSet("Top.Solver.AnimateFlowsheet", "value", m_ANIMATEFLOWSHEET);
			}
			HelperFuncs.SetAllowRunWithComplete(m_ALLOWRUN);
			cxsCase.BatchSet("Top.Solver.EditInput", "value", m_EDITKEYWORD);
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SetDocumentDirtyEvent>().Publish(new SetDocumentDirtyEventArg
			{
				DirtyFlag = false,
				Source = "RunSettingDialog"
			});
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<PFSUpdateAnimateFlagEvent>().Publish(new EventArgs());
			Changed = false;
		}

		public void Submit()
		{
			if (string.IsNullOrWhiteSpace(m_runid))
			{
				MMMessageBox.Show(WpfSimdllResources.BatchRunID_Error, WpfSimdllResources.DlgTitle);
				return;
			}
			if (m_runid.Length > 8)
			{
				MMMessageBox.Show(WpfSimdllResources.BatchRunID_Limit, WpfSimdllResources.DlgTitle);
				return;
			}
			bs.SetRunid(m_runid);
			bs.SetLocation(m_remoteDirectory);
			bs.SetCLQ(m_commandQualifiers);
			bs.SetDleTemp(m_deleteTemporary);
			bs.Done();
			UpdateAllWindow();
		}

		public void UpdateAllWindow()
		{
			IApwnDocument apwnDocument = UnityContainer.Resolve<IApwnDocument>(Array.Empty<ResolverOverride>());
			if (apwnDocument != null)
			{
				string jobStatus = AspenTech.AspenPlus.UnmanagedWrapper.JobStatus.GetJobStatus();
				apwnDocument.UpdateStatus("BatchRun" + jobStatus);
				apwnDocument.UpdateAllForms();
			}
		}

		public void RefreshJobStatus()
		{
			string jobStatus = AspenTech.AspenPlus.UnmanagedWrapper.JobStatus.GetJobStatus();
			if (string.IsNullOrEmpty(jobStatus))
			{
				return;
			}
			string[] array = jobStatus.Split('|');
			for (int i = 0; i < array.Length; i++)
			{
				string[] array2 = array[i].Split('^');
				DataRow[] array3 = JobStatus.Select($"Runid='{array2[0]}'");
				if (array3.Length != 0)
				{
					if (array3[0]["Status"].ToString() != array2[1])
					{
						array3[0]["Status"] = array2[1];
					}
				}
				else if (array2.Length == 2)
				{
					DataRow dataRow = JobStatus.NewRow();
					dataRow["Runid"] = array2[0];
					dataRow["Status"] = array2[1];
					dataRow["Loaded"] = WpfSimdllResources.IsLoadNo;
					JobStatus.Rows.Add(dataRow);
				}
			}
		}

		public void RefreshBtnStatus(string strSel)
		{
			DataRow[] array = JobStatus.Select($"Runid='{strSel}'");
			IsBtnLoadEable = false;
			if (array.Length != 0 && array[0]["Loaded"].ToString() == WpfSimdllResources.IsLoadNo && array[0]["Status"].ToString() == WpfSimdllResources.StatusRunComplete)
			{
				IsBtnLoadEable = true;
			}
		}

		public void ChangeLoadStatus(string strSel)
		{
			DataRow[] array = JobStatus.Select($"Runid='{strSel}'");
			if (array.Length != 0)
			{
				array[0]["Loaded"] = WpfSimdllResources.IsLoadYes;
				m_lstLoadRow = array[0];
				if (UnityContainer.Resolve<IApwnDocument>(Array.Empty<ResolverOverride>()) != null)
				{
					string localized = SimulationStatus.RESULTS_AVAILABLE.Localized;
					UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateStatusTextEvent>().Publish(new UpdateStatusTextEventArgs(localized));
				}
			}
		}
	}
	[ProgId("WpfSimdll.RunSettingsDlg")]
	public class RunSettingsDlg : Window, IComponentConnector
	{
		private DispatcherTimer dispTimer = new DispatcherTimer();

		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(ApwnRunSettingsDlgViewModel), typeof(RunSettingsDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		internal System.Windows.Controls.TabControl tc_RunSettings;

		internal TabItem tb_EngineFiles;

		internal System.Windows.Controls.GroupBox gb_UserLibraries;

		internal System.Windows.Controls.Label lb_Insert;

		internal System.Windows.Controls.TextBox txt_Insert;

		internal System.Windows.Controls.Button btn_Insert;

		internal System.Windows.Controls.Label lb_Stream;

		internal System.Windows.Controls.TextBox txt_Stream;

		internal System.Windows.Controls.Button btn_Stream;

		internal System.Windows.Controls.GroupBox gb_Miscellaneous_Files;

		internal System.Windows.Controls.Label lb_LinkerOptions;

		internal System.Windows.Controls.TextBox txt_LinkerOptions;

		internal System.Windows.Controls.Button btn_Linker;

		internal System.Windows.Controls.Label lb_RunDefinitions;

		internal System.Windows.Controls.TextBox txt_RunDefinition;

		internal TabItem tb_Options;

		internal System.Windows.Controls.GroupBox gb_InteractiveRuns;

		internal System.Windows.Controls.CheckBox chkAutoRun;

		internal System.Windows.Controls.CheckBox chk_ExpressRun;

		internal System.Windows.Controls.CheckBox chk_InteractivelyLoad;

		internal System.Windows.Controls.CheckBox chk_AnimateFlowsheet;

		internal System.Windows.Controls.CheckBox chkDynamicUpdate;

		internal System.Windows.Controls.GroupBox gb_InputOptions;

		internal System.Windows.Controls.CheckBox chk_AllowRun;

		internal System.Windows.Controls.CheckBox chk_EditKeyword;

		internal System.Windows.Controls.GroupBox gb_CurrentSimulation;

		internal System.Windows.Controls.Button btn_Load;

		internal System.Windows.Controls.Label lbl_LoadResults;

		internal System.Windows.Controls.Label lbl_RestartSimulation;

		internal System.Windows.Controls.Button btn_Restart;

		internal TabItem tb_BatchRun;

		internal System.Windows.Controls.Button btnSubmit;

		internal System.Windows.Controls.Button btnBrowse;

		internal System.Windows.Controls.TextBox txtPath;

		internal System.Windows.Controls.CheckBox chk_DeleteFiles;

		internal System.Windows.Controls.Button btnLoad;

		internal System.Windows.Controls.ListView lsbIDs;

		internal System.Windows.Controls.Button btn_OK;

		internal System.Windows.Controls.Button btn_Cancel;

		internal System.Windows.Controls.Button btn_Apply;

		internal System.Windows.Controls.Button btn_Help;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public ApwnRunSettingsDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as ApwnRunSettingsDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer UnityContainer { get; set; }

		public string InitialTab { get; set; }

		public RunSettingsDlg()
		{
			InitializeComponent();
			base.ResizeMode = ResizeMode.NoResize;
			base.Loaded += RunSettingsDlg_Loaded;
			dispTimer.Tick += dispatcherTimer_Tick;
			dispTimer.Interval = new TimeSpan(0, 0, 0, 0, 100);
			dispTimer.Start();
		}

		private void RunSettingsDlg_Loaded(object sender, RoutedEventArgs e)
		{
			IApwnDocument activeDocument = UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument;
			chk_ExpressRun.IsEnabled = activeDocument.ActiveMode != ProblemModes.Properties;
			chk_InteractivelyLoad.IsEnabled = activeDocument.ActiveMode != ProblemModes.Properties;
			if (!string.IsNullOrEmpty(InitialTab))
			{
				if (InitialTab == "Batch Run")
				{
					tb_BatchRun.IsSelected = true;
				}
				else if (InitialTab == "Run Settings")
				{
					tb_Options.IsSelected = true;
				}
			}
		}

		private void dispatcherTimer_Tick(object sender, EventArgs e)
		{
			ViewModel.RefreshJobStatus();
			DataRowView dataRowView = lsbIDs.SelectedItem as DataRowView;
			string strSel = null;
			if (dataRowView != null)
			{
				strSel = dataRowView["Runid"].ToString();
			}
			ViewModel.RefreshBtnStatus(strSel);
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is RunSettingsDlg runSettingsDlg)
			{
				runSettingsDlg.DataContext = args.NewValue;
				if (args.NewValue != null)
				{
					((ApwnRunSettingsDlgViewModel)args.NewValue).View = runSettingsDlg;
				}
			}
		}

		private void OnLoaded(object sender, RoutedEventArgs e)
		{
		}

		private void lsbIDs_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (lsbIDs.SelectedItem is DataRowView dataRowView)
			{
				ViewModel.bs.SetJobBack(dataRowView["Runid"].ToString());
			}
			e.Handled = true;
		}

		private void btnSubmit_Click(object sender, RoutedEventArgs e)
		{
			ViewModel.Submit();
		}

		private void btnBrowse_Click(object sender, RoutedEventArgs e)
		{
			string folderFromBrowse = GetFolderFromBrowse(WpfSimdllResources.TitleBatchSubmit);
			if (!string.IsNullOrEmpty(folderFromBrowse))
			{
				txtPath.Text = folderFromBrowse;
			}
		}

		private void btnLoad_Click(object sender, RoutedEventArgs e)
		{
			if (ViewModel.bs.ReadJobBack() != 2)
			{
				DataRowView dataRowView = lsbIDs.SelectedItem as DataRowView;
				ViewModel.UpdateAllWindow();
				if (dataRowView != null)
				{
					ViewModel.ChangeLoadStatus(dataRowView["Runid"].ToString());
				}
			}
		}

		private void tc_RunSettings_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			TabItem objA = tc_RunSettings.SelectedItem as TabItem;
			MMHelp.SetHelpId(this, object.Equals(objA, tb_BatchRun) ? 1142 : 1145);
		}

		private string GetFolderFromBrowse(string caption)
		{
			string text;
			if (!string.IsNullOrEmpty(ViewModel.RemoteDirectory))
			{
				text = ViewModel.RemoteDirectory;
			}
			else
			{
				CxsCase cxsCase = UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
				try
				{
					text = (string)cxsCase.BatchGet("Top.appModelV8.Settings.startupdir", "value");
				}
				catch (Exception)
				{
					text = "";
				}
			}
			if (!Directory.Exists(text))
			{
				text = "C:\\";
			}
			FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog
			{
				SelectedPath = text,
				Description = WpfSimdllResources.LabelSelectFolder,
				ShowNewFolderButton = true
			};
			if (folderBrowserDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
			{
				ViewModel.RemoteDirectory = folderBrowserDialog.SelectedPath;
				return folderBrowserDialog.SelectedPath;
			}
			return "";
		}

		private string GetFileFromBrowse(string caption)
		{
			string text;
			if (!string.IsNullOrEmpty(ViewModel.RemoteDirectory))
			{
				text = ViewModel.RemoteDirectory;
			}
			else
			{
				try
				{
					text = Directory.GetCurrentDirectory();
				}
				catch (Exception)
				{
					text = "";
				}
			}
			if (!Directory.Exists(text))
			{
				text = "C:\\";
			}
			System.Windows.Forms.OpenFileDialog openFileDialog = new System.Windows.Forms.OpenFileDialog();
			openFileDialog.InitialDirectory = text;
			if (caption == WpfSimdllResources.LabelLinkeroptions)
			{
				openFileDialog.Filter = "(*.txt; *.dlopt; *.opt)|*.txt;*.dlopt;*.opt";
			}
			else if (caption == WpfSimdllResources.LabelInsert)
			{
				openFileDialog.Filter = "(*.*; *.ilb)|*.*;*.ilb";
			}
			else if (caption == WpfSimdllResources.LabelStream)
			{
				openFileDialog.Filter = "(*.*; *.slb)|*.*;*.slb";
			}
			if (openFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
			{
				string fileName = openFileDialog.FileName;
				ViewModel.RemoteDirectory = Path.GetDirectoryName(fileName);
				return fileName;
			}
			return "";
		}

		private void btn_Insert_Click(object sender, RoutedEventArgs e)
		{
			string fileFromBrowse = GetFileFromBrowse(WpfSimdllResources.LabelInsert);
			if (!string.IsNullOrEmpty(fileFromBrowse))
			{
				txt_Insert.Text = fileFromBrowse;
			}
		}

		private void btn_Linker_Click(object sender, RoutedEventArgs e)
		{
			string fileFromBrowse = GetFileFromBrowse(WpfSimdllResources.LabelLinkeroptions);
			if (!string.IsNullOrEmpty(fileFromBrowse))
			{
				txt_LinkerOptions.Text = fileFromBrowse;
			}
		}

		private void btn_Stream_Click(object sender, RoutedEventArgs e)
		{
			string fileFromBrowse = GetFileFromBrowse(WpfSimdllResources.LabelStream);
			if (!string.IsNullOrEmpty(fileFromBrowse))
			{
				txt_Stream.Text = fileFromBrowse;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/runsettingsdlg.xaml", UriKind.Relative);
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
				tc_RunSettings = (System.Windows.Controls.TabControl)target;
				tc_RunSettings.SelectionChanged += tc_RunSettings_SelectionChanged;
				break;
			case 2:
				tb_EngineFiles = (TabItem)target;
				break;
			case 3:
				gb_UserLibraries = (System.Windows.Controls.GroupBox)target;
				break;
			case 4:
				lb_Insert = (System.Windows.Controls.Label)target;
				break;
			case 5:
				txt_Insert = (System.Windows.Controls.TextBox)target;
				break;
			case 6:
				btn_Insert = (System.Windows.Controls.Button)target;
				btn_Insert.Click += btn_Insert_Click;
				break;
			case 7:
				lb_Stream = (System.Windows.Controls.Label)target;
				break;
			case 8:
				txt_Stream = (System.Windows.Controls.TextBox)target;
				break;
			case 9:
				btn_Stream = (System.Windows.Controls.Button)target;
				btn_Stream.Click += btn_Stream_Click;
				break;
			case 10:
				gb_Miscellaneous_Files = (System.Windows.Controls.GroupBox)target;
				break;
			case 11:
				lb_LinkerOptions = (System.Windows.Controls.Label)target;
				break;
			case 12:
				txt_LinkerOptions = (System.Windows.Controls.TextBox)target;
				break;
			case 13:
				btn_Linker = (System.Windows.Controls.Button)target;
				btn_Linker.Click += btn_Linker_Click;
				break;
			case 14:
				lb_RunDefinitions = (System.Windows.Controls.Label)target;
				break;
			case 15:
				txt_RunDefinition = (System.Windows.Controls.TextBox)target;
				break;
			case 16:
				tb_Options = (TabItem)target;
				break;
			case 17:
				gb_InteractiveRuns = (System.Windows.Controls.GroupBox)target;
				break;
			case 18:
				chkAutoRun = (System.Windows.Controls.CheckBox)target;
				break;
			case 19:
				chk_ExpressRun = (System.Windows.Controls.CheckBox)target;
				break;
			case 20:
				chk_InteractivelyLoad = (System.Windows.Controls.CheckBox)target;
				break;
			case 21:
				chk_AnimateFlowsheet = (System.Windows.Controls.CheckBox)target;
				break;
			case 22:
				chkDynamicUpdate = (System.Windows.Controls.CheckBox)target;
				break;
			case 23:
				gb_InputOptions = (System.Windows.Controls.GroupBox)target;
				break;
			case 24:
				chk_AllowRun = (System.Windows.Controls.CheckBox)target;
				break;
			case 25:
				chk_EditKeyword = (System.Windows.Controls.CheckBox)target;
				break;
			case 26:
				gb_CurrentSimulation = (System.Windows.Controls.GroupBox)target;
				break;
			case 27:
				btn_Load = (System.Windows.Controls.Button)target;
				break;
			case 28:
				lbl_LoadResults = (System.Windows.Controls.Label)target;
				break;
			case 29:
				lbl_RestartSimulation = (System.Windows.Controls.Label)target;
				break;
			case 30:
				btn_Restart = (System.Windows.Controls.Button)target;
				break;
			case 31:
				tb_BatchRun = (TabItem)target;
				break;
			case 32:
				btnSubmit = (System.Windows.Controls.Button)target;
				btnSubmit.Click += btnSubmit_Click;
				break;
			case 33:
				btnBrowse = (System.Windows.Controls.Button)target;
				btnBrowse.Click += btnBrowse_Click;
				break;
			case 34:
				txtPath = (System.Windows.Controls.TextBox)target;
				break;
			case 35:
				chk_DeleteFiles = (System.Windows.Controls.CheckBox)target;
				break;
			case 36:
				btnLoad = (System.Windows.Controls.Button)target;
				btnLoad.Click += btnLoad_Click;
				break;
			case 37:
				lsbIDs = (System.Windows.Controls.ListView)target;
				lsbIDs.SelectionChanged += lsbIDs_SelectionChanged;
				break;
			case 38:
				btn_OK = (System.Windows.Controls.Button)target;
				break;
			case 39:
				btn_Cancel = (System.Windows.Controls.Button)target;
				break;
			case 40:
				btn_Apply = (System.Windows.Controls.Button)target;
				break;
			case 41:
				btn_Help = (System.Windows.Controls.Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[Module(ModuleName = "AspenTech.AspenPlus.WpfSimdll.SimdllModule")]
	[ModuleDependency("AspenTech.AspenPlus.MMControls.MMControlsModule")]
	public class SimdllModule : MMFormsModuleBase
	{
		public const string ModuleName = "AspenTech.AspenPlus.WpfSimdll.SimdllModule";

		public SimdllModule(IUnityContainer container)
			: base(container)
		{
			base.FormCatalog.RegisterForm(typeof(RunSettingsDlg));
			base.FormCatalog.RegisterForm(typeof(RunSettingsDlgAP));
		}
	}
	public class WaitingForEditorDlgViewModel : INotifyPropertyChanged
	{
		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

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

		public WaitingForEditorDlgViewModel(IUnityContainer container)
		{
			UnityContainer = container;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = true
			});
			UnityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>()).InvokeAction("Top.Solver", "WaitingForEditor", "B5");
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CloseFormEvent>().Publish(new CloseFormEventArgs
			{
				DialogResult = false
			});
		}
	}
	public class WaitingForEditorDlg : Window, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(WaitingForEditorDlgViewModel), typeof(WaitingForEditorDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		private WaitingForEditor wfe = new WaitingForEditor();

		private uint Process;

		public static DependencyProperty MessageProperty = DependencyProperty.Register("Message", typeof(string), typeof(WaitingForEditorDlg));

		private DispatcherTimer dTimer = new DispatcherTimer();

		internal WaitingForEditorDlg waitingForEditorDlg;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public WaitingForEditorDlgViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as WaitingForEditorDlgViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public string Message
		{
			get
			{
				return (string)GetValue(MessageProperty);
			}
			set
			{
				SetValue(MessageProperty, value);
			}
		}

		public WaitingForEditorDlg()
		{
			InitializeComponent();
			dTimer.Tick += dTimer_Tick;
			dTimer.Interval = new TimeSpan(0, 0, 1);
			dTimer.Start();
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			(d as WaitingForEditorDlg).DataContext = args.NewValue;
		}

		public void SetInfo(uint nProcess, string sMessage)
		{
			Process = nProcess;
			Message = sMessage;
		}

		private void dTimer_Tick(object sender, EventArgs e)
		{
			if (wfe.QueryProcess(Process))
			{
				dTimer.Stop();
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/waitingforeditordlg.xaml", UriKind.Relative);
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
				waitingForEditorDlg = (WaitingForEditorDlg)target;
			}
			else
			{
				_contentLoaded = true;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfSimdll;component/wizardcontainer.xaml", UriKind.Relative);
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
}
namespace AspenTech.AspenPlus.WpfSimdll.Modules
{
	[Module(ModuleName = "AspenTech.AspenPlus.WpfSimdll.Modules.WpfSimdllModule")]
	public class WpfSimdllModule : IModule
	{
		public const string ModuleName = "AspenTech.AspenPlus.WpfSimdll.Modules.WpfSimdllModule";

		internal static IUnityContainer Container { get; private set; }

		public WpfSimdllModule(IUnityContainer container)
		{
			DialogDriver.Container = container;
			DialogDriver.SyncContext = SynchronizationContext.Current;
		}

		public void Initialize()
		{
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000001 SimConnectDlgViewModel.add_PropertyChanged
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

// 0x06000002 SimConnectDlgViewModel.remove_PropertyChanged
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

// 0x0600002c ServerTypeItem..ctor
// public ServerTypeItem()
// {
// }

// 0x06000032 XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x06000033 AspenTech.AspenPlus.Simulation.SimulationStatus..cctor
// static SimulationStatus()
// {
// 	REFRESH = new SimulationStatusEnum("IDS_SIMMSG_REFRESH", 471u);
// 	REQUIRED_INPUT_INCOMPLETE = new SimulationStatusEnum("IDS_STATUS_RequiredInputIncomplete", 1909u);
// 	REQUIRED_PROPERTIES_INPUT_COMPLETE = new SimulationStatusEnum("IDS_STATUS_RequiredPropertiesInputComplete", 1921u);
// 	RESULTS_AVAILABLE = new SimulationStatusEnum("IDS_STATUS_ResultsAvailable", 1912u);
// 	RESULTS_AVAILABLE_WITH_WARNINGS = new SimulationStatusEnum("IDS_STATUS_ResultsAvailableWithWarnings", 1913u);
// 	RESULTS_AVAILABLE_WITH_ERRORS = new SimulationStatusEnum("IDS_STATUS_ResultsAvailableWithErrors", 1914u);
// 	INPUT_CHANGED = new SimulationStatusEnum("IDS_STATUS_InputChanged", 1911u);
// 	RESULTS_AVAILABLE_WITH_ERRORS_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS4", 1449u);
// 	RESULTS_AVAILABLE_WITH_WARNINGS_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS5", 1450u);
// 	RESULTS_AVAILABLE_FIMMTOP = new SimulationStatusEnum("IDS_STR_FIMMTOP_STATUS6", 1451u);
// }

// 0x06000044 AspenTech.AspenPlus.Simulation.SimulationStatusViewBuilder..cctor
// using System.Collections.Generic;
// using System.Windows.Media;
//
// static SimulationStatusViewBuilder()
// {
// 	StatusList = new List<Status>
// 	{
// 		new Status(0, "Warnings", "Simulation Completed with Warnings", new SolidColorBrush(Color.FromRgb(byte.MaxValue, byte.MaxValue, 0))),
// 		new Status(1, "Failed", "Simulation Failed", new SolidColorBrush(Color.FromRgb(byte.MaxValue, 80, 84))),
// 		new Status(2, "Available", "Results Available", Brushes.Transparent),
// 		new Status(3, "Changed", "Required Input Changed", new SolidColorBrush(Colors.Yellow)),
// 		new Status(4, "Incomplete", "Required Input Incomplete", new SolidColorBrush(Color.FromRgb(byte.MaxValue, 43, 43))),
// 		new Status(5, "completed", "Run Completed", Brushes.Transparent)
// 	};
// }

// 0x06000047 AspenTech.AspenPlus.WpfSimdll.CheckBoxThreeStateCvt..ctor
// public CheckBoxThreeStateCvt()
// {
// }

// 0x06000051 AspenTech.AspenPlus.WpfSimdll.ControlPaneFindNodeDlg.add_PropertyChanged
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

// 0x06000052 AspenTech.AspenPlus.WpfSimdll.ControlPaneFindNodeDlg.remove_PropertyChanged
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

// 0x06000065 AspenTech.AspenPlus.WpfSimdll.PasswordBoxHelper..cctor
// using System.Windows;
//
// static PasswordBoxHelper()
// {
// 	PasswordProperty = DependencyProperty.RegisterAttached("Password", typeof(string), typeof(PasswordBoxHelper), new FrameworkPropertyMetadata("", OnPasswordPropertyChanged));
// 	IsUpdatingProperty = DependencyProperty.RegisterAttached("IsUpdating", typeof(bool), typeof(PasswordBoxHelper));
// 	AttachedProperty = DependencyProperty.RegisterAttached("Attached", typeof(bool), typeof(PasswordBoxHelper), new PropertyMetadata(false, OnAttachedPropertyChanged));
// }

// 0x06000076 AspenTech.AspenPlus.WpfSimdll.RunSettingsDlgAP..cctor
// using System.Windows;
//
// static RunSettingsDlgAP()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(ApwnRunSettingsDlgViewModel), typeof(RunSettingsDlgAP), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x06000095 AspenTech.AspenPlus.WpfSimdll.ShowBlockTempDlgViewModel.add_PropertyChanged
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

// 0x06000096 AspenTech.AspenPlus.WpfSimdll.ShowBlockTempDlgViewModel.remove_PropertyChanged
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

// 0x060000a1 AspenTech.AspenPlus.WpfSimdll.DRSRegressionRunDlgViewModel.add_PropertyChanged
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

// 0x060000a2 AspenTech.AspenPlus.WpfSimdll.DRSRegressionRunDlgViewModel.remove_PropertyChanged
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

// 0x060000bc AspenTech.AspenPlus.WpfSimdll.DRSRegressionRunDlg..cctor
// using System.Windows;
//
// static DRSRegressionRunDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(DRSRegressionRunDlgViewModel), typeof(DRSRegressionRunDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x060000bf AspenTech.AspenPlus.WpfSimdll.MoveAllConvert..ctor
// public MoveAllConvert()
// {
// }

// 0x060000c2 AspenTech.AspenPlus.WpfSimdll.FileTypeConverter..ctor
// public FileTypeConverter()
// {
// }

// 0x060000ef AspenTech.AspenPlus.WpfSimdll.EOReinitDlg..cctor
// using System.Windows;
//
// static EOReinitDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(EOReinitDlgViewModel), typeof(EOReinitDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x060000f2 AspenTech.AspenPlus.WpfSimdll.EOReinitConvert..ctor
// public EOReinitConvert()
// {
// }

// 0x060000fc AspenTech.AspenPlus.WpfSimdll.FileInputBox.add_FileNameChanged
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

// 0x060000fd AspenTech.AspenPlus.WpfSimdll.FileInputBox.remove_FileNameChanged
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

// 0x06000100 AspenTech.AspenPlus.WpfSimdll.FileInputBox..cctor
// using System.Windows;
//
// static FileInputBox()
// {
// 	FilterProperty = DependencyProperty.Register("Filter", typeof(string), typeof(FileInputBox), new PropertyMetadata(null));
// 	FileOpenDlgType = DependencyProperty.Register("DlgType", typeof(int), typeof(FileInputBox), new PropertyMetadata(null));
// }

// 0x06000118 AspenTech.AspenPlus.WpfSimdll.MoveToType..ctor
// public MoveToType()
// {
// }

// 0x0600011d AspenTech.AspenPlus.WpfSimdll.SimBlockTypeClass..ctor
// public SimBlockTypeClass()
// {
// }

// 0x06000130 AspenTech.AspenPlus.WpfSimdll.ApwnSimBlockItems.add_PropertyChanged
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

// 0x06000131 AspenTech.AspenPlus.WpfSimdll.ApwnSimBlockItems.remove_PropertyChanged
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

// 0x06000137 AspenTech.AspenPlus.WpfSimdll.ApwnSimBlockItems..ctor
// public ApwnSimBlockItems()
// {
// 	_displayname = string.Empty;
// 	base..ctor();
// }

// 0x06000138 AspenTech.AspenPlus.WpfSimdll.ApwnSimBlockItems..cctor
// using AspenTech.AspenPlus.Localization;
//
// static ApwnSimBlockItems()
// {
// 	SelectAllName = WpfSimdllResources.Select_All;
// 	SelectAllDisplayName = WpfSimdllResources.Select_All;
// }

// 0x06000149 AspenTech.AspenPlus.WpfSimdll.MoveToDlgViewModel.add_PropertyChanged
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

// 0x0600014a AspenTech.AspenPlus.WpfSimdll.MoveToDlgViewModel.remove_PropertyChanged
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

// 0x06000150 AspenTech.AspenPlus.WpfSimdll.MoveToTypeConvert..ctor
// public MoveToTypeConvert()
// {
// }

// 0x06000153 AspenTech.AspenPlus.WpfSimdll.MoveToItemImageConvert..ctor
// public MoveToItemImageConvert()
// {
// }

// 0x0600015c AspenTech.AspenPlus.WpfSimdll.PDBActivateDlgViewModel.add_PropertyChanged
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

// 0x0600015d AspenTech.AspenPlus.WpfSimdll.PDBActivateDlgViewModel.remove_PropertyChanged
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

// 0x06000168 AspenTech.AspenPlus.WpfSimdll.PDBActivateDlg..cctor
// using System.Windows;
//
// static PDBActivateDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x06000170 AspenTech.AspenPlus.WpfSimdll.PDBGetDlgViewModel.add_PropertyChanged
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

// 0x06000171 AspenTech.AspenPlus.WpfSimdll.PDBGetDlgViewModel.remove_PropertyChanged
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

// 0x06000192 AspenTech.AspenPlus.WpfSimdll.PDBPutDlgViewModel.add_PropertyChanged
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

// 0x06000193 AspenTech.AspenPlus.WpfSimdll.PDBPutDlgViewModel.remove_PropertyChanged
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

// 0x060001af AspenTech.AspenPlus.WpfSimdll.RadioBoolToIntConverter..ctor
// public RadioBoolToIntConverter()
// {
// }

// 0x060001b3 AspenTech.AspenPlus.WpfSimdll.ReExecuteBlockDlgViewModel.add_PropertyChanged
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

// 0x060001b4 AspenTech.AspenPlus.WpfSimdll.ReExecuteBlockDlgViewModel.remove_PropertyChanged
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

// 0x060001c8 AspenTech.AspenPlus.WpfSimdll.ReExecuteBlockDlg..cctor
// using System.Windows;
//
// static ReExecuteBlockDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// 	BlockProperty = DependencyProperty.Register("Block", typeof(string), typeof(ReExecuteBlockDlg));
// }

// 0x060001cc AspenTech.AspenPlus.WpfSimdll.ReexecuteFortranDlgViewModel.add_PropertyChanged
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

// 0x060001cd AspenTech.AspenPlus.WpfSimdll.ReexecuteFortranDlgViewModel.remove_PropertyChanged
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

// 0x060001e5 AspenTech.AspenPlus.WpfSimdll.ReexecuteFortranDlg..cctor
// using System.Data;
// using System.Windows;
//
// static ReexecuteFortranDlg()
// {
// 	BlocksProperty = DependencyProperty.Register("Blocks", typeof(DataTable), typeof(ReexecuteFortranDlg));
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x060001f1 AspenTech.AspenPlus.WpfSimdll.ReinitDlgViewModel.add_PropertyChanged
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

// 0x060001f2 AspenTech.AspenPlus.WpfSimdll.ReinitDlgViewModel.remove_PropertyChanged
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

// 0x0600021a AspenTech.AspenPlus.WpfSimdll.StopSetList..ctor
// public StopSetList()
// {
// }

// 0x0600022f AspenTech.AspenPlus.WpfSimdll.StopPointDlgViewModel.add_PropertyChanged
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

// 0x06000230 AspenTech.AspenPlus.WpfSimdll.StopPointDlgViewModel.remove_PropertyChanged
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

// 0x0600024b AspenTech.AspenPlus.WpfSimdll.ListBoxEx..ctor
// public ListBoxEx()
// {
// }

// 0x0600024c AspenTech.AspenPlus.WpfSimdll.ListBoxEx..cctor
// using System.Collections;
// using System.Windows;
//
// static ListBoxEx()
// {
// 	BindableSelectedItemsProperty = DependencyProperty.Register("BindableSelectedItems", typeof(IList), typeof(ListBoxEx));
// }

// 0x06000250 AspenTech.AspenPlus.WpfSimdll.UseFortranDlgViewModel.add_PropertyChanged
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

// 0x06000251 AspenTech.AspenPlus.WpfSimdll.UseFortranDlgViewModel.remove_PropertyChanged
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

// 0x06000260 AspenTech.AspenPlus.WpfSimdll.UseFortranDlg..cctor
// using System.Windows;
//
// static UseFortranDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(MoveToDlgViewModel), typeof(MoveToDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x060002a5 AspenTech.AspenPlus.WpfSimdll.ApwnRunSettingsDlgViewModel.add_PropertyChanged
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

// 0x060002a6 AspenTech.AspenPlus.WpfSimdll.ApwnRunSettingsDlgViewModel.remove_PropertyChanged
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

// 0x060002fc AspenTech.AspenPlus.WpfSimdll.RunSettingsDlg..cctor
// using System.Windows;
//
// static RunSettingsDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(ApwnRunSettingsDlgViewModel), typeof(RunSettingsDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// }

// 0x06000301 AspenTech.AspenPlus.WpfSimdll.WaitingForEditorDlgViewModel.add_PropertyChanged
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

// 0x06000302 AspenTech.AspenPlus.WpfSimdll.WaitingForEditorDlgViewModel.remove_PropertyChanged
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

// 0x06000311 AspenTech.AspenPlus.WpfSimdll.WaitingForEditorDlg..cctor
// using System.Windows;
//
// static WaitingForEditorDlg()
// {
// 	ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(WaitingForEditorDlgViewModel), typeof(WaitingForEditorDlg), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));
// 	MessageProperty = DependencyProperty.Register("Message", typeof(string), typeof(WaitingForEditorDlg));
// }

// 0x06000326 AspenTech.AspenPlus.WpfSimdll.WizardContainer..cctor
// using System.Windows;
//
// static WizardContainer()
// {
// 	CanPrevProperty = DependencyProperty.Register("CanPrev", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	CanNextProperty = DependencyProperty.Register("CanNext", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardContainer), new PropertyMetadata(false));
// 	ContainerParentProperty = DependencyProperty.Register("ContainerParent", typeof(UIElement), typeof(WizardContainer), new PropertyMetadata(null));
// }

// 0x06000335 AspenTech.AspenPlus.WpfSimdll.WizardPage..ctor
// public WizardPage()
// {
// }

// 0x06000338 AspenTech.AspenPlus.WpfSimdll.WizardPage..cctor
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

// 0x0600033e AspenTech.AspenPlus.Simulation.SimulationStatusViewBuilder+<>c__DisplayClass2_0..ctor
// public <>c__DisplayClass2_0()
// {
// }

// 0x06000340 AspenTech.AspenPlus.WpfSimdll.ControlPaneFindNodeDlg+<>c__DisplayClass11_0..ctor
// public <>c__DisplayClass11_0()
// {
// }

// 0x06000342 AspenTech.AspenPlus.WpfSimdll.ShowBlockTempDlgViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000343 AspenTech.AspenPlus.WpfSimdll.ShowBlockTempDlgViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000347 AspenTech.AspenPlus.WpfSimdll.DialogDriver+<>c__DisplayClass12_0..ctor
// public <>c__DisplayClass12_0()
// {
// }

// 0x06000349 AspenTech.AspenPlus.WpfSimdll.DialogDriver+<>c__DisplayClass14_0..ctor
// public <>c__DisplayClass14_0()
// {
// }

// 0x0600034b AspenTech.AspenPlus.WpfSimdll.DialogDriver+<>c__DisplayClass15_0..ctor
// public <>c__DisplayClass15_0()
// {
// }

// 0x0600034d AspenTech.AspenPlus.WpfSimdll.DialogDriver+<>c__DisplayClass17_0..ctor
// public <>c__DisplayClass17_0()
// {
// }

// 0x0600034f AspenTech.AspenPlus.WpfSimdll.DialogDriver+<>c__DisplayClass18_0..ctor
// public <>c__DisplayClass18_0()
// {
// }
