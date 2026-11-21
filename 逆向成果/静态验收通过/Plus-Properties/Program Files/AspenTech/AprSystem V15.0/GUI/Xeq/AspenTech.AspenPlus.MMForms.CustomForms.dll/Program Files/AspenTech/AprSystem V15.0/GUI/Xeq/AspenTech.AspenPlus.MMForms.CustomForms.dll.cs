using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Threading;
using System.Xml.Linq;
using System.Xml.XPath;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.ExportToExcel;
using AspenTech.AspenCxs.InfragisticsControls;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMForms.GridForms.StreamReport;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Engineering.GridControls;
using AspenTech.Engineering.GridControls.EventArgs;
using AspenTech.Engineering.GridControls.Internal;
using AspenTech.Engineering.GridControls.Panel;
using AspenTech.Visualisation.CommonImages;
using AspenTech.Visualisation.CommonShell;
using Infragistics.Windows;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Logging;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Composite.UnityExtensions;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.CustomForms")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.CustomForms")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2012 -2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenTech.AspenPlus.MMForms.CustomForms
{
	public class CaseVariablesBrowser : Window, IComponentConnector
	{
		private CxsNodeExplorer _cxsExplorer = new CxsNodeExplorer();

		private CxsCase _case;

		private List<string> _selectedPaths = new List<string>();

		internal System.Windows.Controls.Button btnCancel;

		internal System.Windows.Controls.Button btnOK;

		internal Grid gridBrowser;

		private bool _contentLoaded;

		public CxsCase Case
		{
			get
			{
				return _case;
			}
			set
			{
				_case = value;
			}
		}

		public List<string> SelectedPaths
		{
			get
			{
				return _selectedPaths;
			}
			set
			{
				_selectedPaths = value;
			}
		}

		public bool UserClickedOK { get; set; }

		public CaseVariablesBrowser()
		{
			InitializeComponent();
			base.WindowStartupLocation = WindowStartupLocation.CenterOwner;
			_cxsExplorer.ListViewExpansionDepth = 1;
			_cxsExplorer.ListViewExpansionLimit = 1000;
			_cxsExplorer.ListViewVisible = true;
			_cxsExplorer.MultiSelectRows = true;
			_cxsExplorer.SearchMaximumDepth = 0;
			_cxsExplorer.SearchResultsSplitterDistance = 140;
			_cxsExplorer.SearchViewVisible = false;
			_cxsExplorer.TabIndex = 5;
			_cxsExplorer.TreeViewSplitterDistance = 132;
			_cxsExplorer.TreeViewVisible = true;
			UserClickedOK = false;
			base.Loaded += CaseVariablesBrowser_Loaded;
			base.Closed += CaseVariablesBrowser_Closed;
			base.Closing += CaseVariablesBrowser_Closing;
		}

		private void CaseVariablesBrowser_Closing(object sender, CancelEventArgs e)
		{
			if (_cxsExplorer != null)
			{
				_cxsExplorer.Dispose();
				_cxsExplorer = null;
			}
		}

		private void CaseVariablesBrowser_Closed(object sender, EventArgs e)
		{
		}

		private void CaseVariablesBrowser_Loaded(object sender, RoutedEventArgs e)
		{
			WindowsFormsHost windowsFormsHost = new WindowsFormsHost();
			_cxsExplorer = new CxsNodeExplorer();
			_cxsExplorer.AddRootCase(_case);
			windowsFormsHost.Child = _cxsExplorer;
			gridBrowser.Children.Add(windowsFormsHost);
			MMHelp.SetHelpFile(this, "apwn.chm");
			MMHelp.SetHelpId(this, 21002);
		}

		public void SetCxsCase(CxsCase caseToBrowse)
		{
			Case = caseToBrowse;
		}

		private void UpdateSelectedCxsVarList()
		{
			SelectedPaths.Clear();
			foreach (CxsNode selectedNode in _cxsExplorer.SelectedNodes)
			{
				SelectedPaths.Add(selectedNode.Path);
			}
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			UpdateSelectedCxsVarList();
			UserClickedOK = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.CustomForms;component/casevariablesbrowser.xaml", UriKind.Relative);
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
				btnCancel = (System.Windows.Controls.Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			case 2:
				btnOK = (System.Windows.Controls.Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 3:
				gridBrowser = (Grid)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class CustomFormViewModel : MMTabPageViewModel
	{
		private DelegateCommand<object> m_CmdPlaceFormOnFlowsheet;

		private DelegateCommand<object> m_CmdPlaceAsIconOnFlowsheet;

		private DelegateCommand<object> m_CmdSendToExcel;

		private DelegateCommand<object> m_CmdSendToMultiCase;

		public CustomForm CustomFormEntry { get; set; }

		public DelegateCommand<object> CmdPlaceFormOnFlowsheet
		{
			get
			{
				if (m_CmdPlaceFormOnFlowsheet == null)
				{
					m_CmdPlaceFormOnFlowsheet = new DelegateCommand<object>(CmdPlaceFormOnFlowsheetExecute);
				}
				return m_CmdPlaceFormOnFlowsheet;
			}
		}

		public DelegateCommand<object> CmdPlaceAsIconOnFlowsheet
		{
			get
			{
				if (m_CmdPlaceAsIconOnFlowsheet == null)
				{
					m_CmdPlaceAsIconOnFlowsheet = new DelegateCommand<object>(CmdPlaceAsIconOnFlowsheetExecute);
				}
				return m_CmdPlaceAsIconOnFlowsheet;
			}
		}

		public DelegateCommand<object> CmdSendToExcel
		{
			get
			{
				if (m_CmdSendToExcel == null)
				{
					m_CmdSendToExcel = new DelegateCommand<object>(CmdSendToExcelExecute);
				}
				return m_CmdSendToExcel;
			}
		}

		public DelegateCommand<object> CmdSendToMultiCase
		{
			get
			{
				if (m_CmdSendToMultiCase == null)
				{
					m_CmdSendToMultiCase = new DelegateCommand<object>(CmdSendToMultiCaseExecute);
				}
				return m_CmdSendToMultiCase;
			}
		}

		protected override void OnViewChanged()
		{
			if (base.View is ICustomFormView customFormView)
			{
				string mainPath = ExpandDataPath("@main");
				customFormView.InitializeView(base.UnityContainer, mainPath);
			}
			base.OnViewChanged();
		}

		protected override void OnUpdateData()
		{
			if (base.View is ICustomFormView customFormView)
			{
				customFormView.UpdateView();
			}
			base.OnUpdateData();
		}

		private void CmdPlaceFormOnFlowsheetExecute(object parameter)
		{
			if (CustomFormEntry != null)
			{
				CustomFormEntry.theCustomFormControl.PlaceOnFlowsheet(bPlaceAsIcon: false);
			}
		}

		private void CmdPlaceAsIconOnFlowsheetExecute(object parameter)
		{
			if (CustomFormEntry != null)
			{
				CustomFormEntry.theCustomFormControl.PlaceOnFlowsheet(bPlaceAsIcon: true);
			}
		}

		private void CmdSendToExcelExecute(object parameter)
		{
			if (CustomFormEntry != null)
			{
				CustomFormEntry.theCustomFormControl.SendToExcel();
			}
		}

		private void CmdSendToMultiCaseExecute(object parameter)
		{
			if (CustomFormEntry != null)
			{
				CustomFormEntry.theCustomFormControl.SendToMultiCase();
			}
		}
	}
	[ProgId("MMCustomForms.CustomForm")]
	public class CustomForm : MMTabPage, ICustomFormView, IComponentConnector
	{
		private bool m_bClickOnCommandButton;

		internal MMCmdButton MMBtnPT;

		internal MMCmdButton MMBtnPI;

		internal MMCmdButton MMBtnSendToExcel;

		internal MMCmdButton MMBtnSendToMultiCase;

		internal CustomFormControl theCustomFormControl;

		private bool _contentLoaded;

		protected override bool CanContentZoom => ((IShellZoomable)theCustomFormControl).SupportsZoom;

		public CustomForm()
		{
			base.ViewModelType = typeof(CustomFormViewModel);
			InitializeComponent();
			base.Loaded += CustomForm_Loaded;
		}

		private void CustomForm_Loaded(object sender, RoutedEventArgs e)
		{
			m_bClickOnCommandButton = false;
		}

		public void InitializeView(IUnityContainer unityContainer, string mainPath)
		{
			if (unityContainer != null && !string.IsNullOrEmpty(mainPath))
			{
				theCustomFormControl.Initialize(unityContainer, mainPath);
			}
			(base.ViewModel as CustomFormViewModel).CustomFormEntry = this;
		}

		public void UpdateView()
		{
			theCustomFormControl.InvalidateData();
		}

		public override void OnClosed()
		{
			theCustomFormControl.OnParentClosed();
			base.OnClosed();
		}

		protected override void DoFocusFirstControl()
		{
			_ = m_bClickOnCommandButton;
		}

		protected override void ApplyZoomFactor(double zoomFactor)
		{
			theCustomFormControl.Zoom(zoomFactor);
		}

		protected override void OnPreviewMouseLeftButtonDown(MouseButtonEventArgs e)
		{
			if (e.Source is MMCmdButton)
			{
				m_bClickOnCommandButton = true;
			}
			else
			{
				m_bClickOnCommandButton = false;
			}
			base.OnPreviewMouseLeftButtonDown(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.CustomForms;component/customform.xaml", UriKind.Relative);
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
				MMBtnPT = (MMCmdButton)target;
				break;
			case 2:
				MMBtnPI = (MMCmdButton)target;
				break;
			case 3:
				MMBtnSendToExcel = (MMCmdButton)target;
				break;
			case 4:
				MMBtnSendToMultiCase = (MMCmdButton)target;
				break;
			case 5:
				theCustomFormControl = (CustomFormControl)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class CustomFormControl : System.Windows.Controls.UserControl, IAXEmbeddedObject, IShellZoomable, IComponentConnector
	{
		private bool m_bInitializing;

		private bool _eventsSubscribed;

		private EngineCalculator _calculator;

		private int m_iActiveGridControlIndex;

		public static bool s_bFirstColumnValueChangedByAssignValue;

		internal GridControlPanel thePanel;

		private bool _contentLoaded;

		public IUnityContainer UnityContainer { get; private set; }

		public string MainNodePath { get; private set; }

		public CxsCase CxsCase { get; private set; }

		public CxsNode MainNode { get; private set; }

		public CxsDataProvider DataProvider { get; private set; }

		public bool EmbeddedInPFS { get; set; }

		public EngineCalculator SteamReportEngineCalculator
		{
			get
			{
				if (_calculator == null && UnityContainer != null)
				{
					_calculator = UnityContainer.Resolve<EngineCalculator>(Array.Empty<ResolverOverride>());
				}
				return _calculator;
			}
		}

		public Size GridSize
		{
			get
			{
				if (thePanel.ActiveGridControl != null)
				{
					Size dataGridControlSize = thePanel.ActiveGridControl.DataGridControlSize;
					if (thePanel.GridControls.Count >= 2)
					{
						dataGridControlSize.Height += 4.0;
					}
					return dataGridControlSize;
				}
				return new Size(0.0, 0.0);
			}
		}

		public Size MinimumGridPanelSize
		{
			get
			{
				Size result = new Size(0.0, 0.0);
				result.Width = thePanel.MinWidth;
				result.Height = thePanel.MinHeight;
				return result;
			}
		}

		public int ActiveGridControlIndex
		{
			get
			{
				return m_iActiveGridControlIndex;
			}
			set
			{
				m_iActiveGridControlIndex = value;
			}
		}

		private bool IsTabsInvalid { get; set; }

		bool IAXEmbeddedObject.SupportsZoom => true;

		bool IAXEmbeddedObject.Loading { get; set; }

		bool IAXEmbeddedObject.IsPFSObject { get; set; }

		bool IAXEmbeddedObject.IsEditMode { get; set; }

		bool IShellZoomable.SupportsZoom => true;

		public CustomFormControl()
		{
			InitializeComponent();
		}

		protected override void OnInitialized(EventArgs e)
		{
			thePanel.NameProvider = new DefaultNameProvider(thePanel)
			{
				NewGridNamePattern = CustomFormsResources.NewGridNamePattern,
				DescriptionLabel = CustomFormsResources.InputNameDialog_Label
			};
			thePanel.ChildGridControlGenerator = () => new CustomFormControlPage(this);
			thePanel.GridControlAddedManually += thePanel_GridControlAddedManually;
			thePanel.GridControlRemovingManually += thePanel_GridControlRemovingManually;
			thePanel.GridControlRemovedManually += thePanel_GridControlRemovedManually;
			thePanel.GridControlRenamed += thePanel_GridControlRenamed;
			thePanel.ActiveGridControlChanged += thePanel_ActiveGridControlChanged;
			thePanel.CommandExecuting += thePanel_CommandExecuting;
			base.Loaded += CustomFormControl_Loaded;
			base.OnInitialized(e);
		}

		private void CustomFormControl_Loaded(object sender, RoutedEventArgs e)
		{
			if (IsTabsInvalid)
			{
				InitializeTabs();
				IsTabsInvalid = false;
			}
		}

		public void DisableDataGridControlScrollBar()
		{
			if (EmbeddedInPFS && thePanel.ActiveGridControl != null && thePanel.ActiveGridControl.DataGridControlInstance != null)
			{
				thePanel.ActiveGridControl.DataGridControlInstance.HorizontalScrollBarVisibility = ScrollBarVisibility.Disabled;
				thePanel.ActiveGridControl.DataGridControlInstance.VerticalScrollBarVisibility = ScrollBarVisibility.Disabled;
			}
		}

		public void EnableDataGridControlScrollBar()
		{
			if (EmbeddedInPFS && thePanel.ActiveGridControl != null && thePanel.ActiveGridControl.DataGridControlInstance != null)
			{
				thePanel.ActiveGridControl.DataGridControlInstance.HorizontalScrollBarVisibility = ScrollBarVisibility.Hidden;
				thePanel.ActiveGridControl.DataGridControlInstance.VerticalScrollBarVisibility = ScrollBarVisibility.Hidden;
			}
		}

		private void thePanel_GridControlAddedManually(object sender, GridControlEventArgs e)
		{
			CustomFormControlPage customFormControlPage = e.GridControl as CustomFormControlPage;
			customFormControlPage.InitializeLayout(CreateInitialTabLayout(customFormControlPage.Title));
			PublishCustomFormChangedEvent(CustomFormChangeAction.TabAdded, e.GridControl.Title, null, saveLayoutFirst: true);
		}

		private void thePanel_GridControlRemovingManually(object sender, GridControlRemovingEventArgs e)
		{
			if (MMMessageBox.Show(Window.GetWindow(this), CustomFormsResources.Message_RemoveForm, CustomFormsResources.MessageTitle_RemoveForm, MMMessageBoxButton.YesNo) == MMMessageBoxResult.Yes)
			{
				e.Cancel = false;
			}
			else
			{
				e.Cancel = true;
			}
		}

		private void thePanel_GridControlRemovedManually(object sender, GridControlEventArgs e)
		{
			PublishCustomFormChangedEvent(CustomFormChangeAction.TabRemmoved, e.GridControl.Title, null, saveLayoutFirst: true);
		}

		private void thePanel_GridControlRenamed(object sender, GridControlRenamedEventArgs e)
		{
			PublishCustomFormChangedEvent(CustomFormChangeAction.TabRenamed, e.NewTitle, e.OldTitle, saveLayoutFirst: true);
		}

		private void thePanel_ActiveGridControlChanged(object sender, RoutedPropertyChangedEventArgs<GridControl> e)
		{
			if (e.OldValue is CustomFormControlPage customFormControlPage)
			{
				customFormControlPage.IsActive = false;
			}
			if (e.NewValue is CustomFormControlPage customFormControlPage2)
			{
				customFormControlPage2.IsActive = true;
			}
			if (EmbeddedInPFS && !m_bInitializing)
			{
				Dispatcher.CurrentDispatcher.BeginInvoke(DispatcherPriority.Loaded, (Action)delegate
				{
					string mainNodePath = MainNodePath;
					string strFlowsheetSubject = RetrieveFlowshetSubjectFromPath(mainNodePath);
					UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomFormLayoutChangedEvent>().Publish(new CustomFormLayoutChangedEventArgs(strFlowsheetSubject, mainNodePath));
				});
			}
		}

		private void thePanel_CommandExecuting(object sender, CommandExecutingEventArgs e)
		{
			if (e.Command == GridControlPanel.RemoveCurrentGridCommand)
			{
				e.Cancel = thePanel.GridControls.Count <= 1;
			}
		}

		private string GetSystemDecimalSymbol()
		{
			return 0.1.ToString().Replace("0", string.Empty).Replace("1", string.Empty);
		}

		public void SetActivateGridControlByIndex(int iIndex)
		{
			if (thePanel.GridControls.Count < iIndex)
			{
				return;
			}
			if (thePanel.ActiveGridControl != null)
			{
				if (thePanel.ActiveGridControl != thePanel.GridControls[iIndex])
				{
					CustomFormControlPage customFormControlPage = thePanel.ActiveGridControl as CustomFormControlPage;
					CustomFormControlPage customFormControlPage2 = thePanel.ActiveGridControl as CustomFormControlPage;
					if (customFormControlPage != null)
					{
						customFormControlPage.IsActive = false;
					}
					if (customFormControlPage2 != null)
					{
						customFormControlPage2.IsActive = true;
					}
					thePanel.ActiveGridControl = thePanel.GridControls[iIndex];
				}
			}
			else
			{
				if (thePanel.GridControls[iIndex] is CustomFormControlPage customFormControlPage3)
				{
					customFormControlPage3.IsActive = true;
				}
				thePanel.ActiveGridControl = thePanel.GridControls[iIndex];
			}
		}

		public void Initialize(IUnityContainer unityContainer, string mainNodePath)
		{
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			if (string.IsNullOrEmpty(mainNodePath))
			{
				throw new ArgumentException("Argument mainNodePath cannot be null or empty.");
			}
			m_bInitializing = true;
			UnityContainer = unityContainer;
			MainNodePath = mainNodePath;
			CxsCase = UnityContainer.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument.Case;
			MainNode = CxsCase.ResolveNode(MainNodePath);
			DataProvider = UnityContainer.Resolve<CxsDataProvider>(Array.Empty<ResolverOverride>());
			InitializeTabs();
			SubscribeEvents();
			if (EmbeddedInPFS)
			{
				thePanel.MinWidth = 0.0;
				thePanel.MinHeight = 0.0;
			}
			m_bInitializing = false;
		}

		public void OnParentClosed()
		{
			SaveFormLayout();
			UnsubscribeEvents();
		}

		private void SubscribeEvents()
		{
			if (!_eventsSubscribed)
			{
				IEventAggregator eventAggregator = UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				eventAggregator.GetEvent<UpdateAllEvent>().Subscribe(OnUpdateAll);
				eventAggregator.GetEvent<CustomFormChangedEvent>().Subscribe(OnCustomFormChanged);
				eventAggregator.GetEvent<ObjectRenamedAnywhereEvent>().Subscribe(OnObjectRenamedAnywhereEvent);
				eventAggregator.GetEvent<CustomFormFirstColumnUpdateDataEvent>().Subscribe(OnCustomFormFirstColumnDataChangedEvent);
				eventAggregator.GetEvent<BeforeSavingEvent>().Subscribe(OnBeforeSavingEvent);
				eventAggregator.GetEvent<QueryCustomTableFormPartEvent>().Subscribe(OnQueryCustomTableFormPartEvent);
				eventAggregator.GetEvent<StoreValueEvent>().Subscribe(OnStoreValueEvent);
				eventAggregator.GetEvent<PFSEmbeddedCustomTableStoreValueEvent>().Subscribe(OnPFSEmbeddedCustomTableStoreValueEvent);
				eventAggregator.GetEvent<CustomFormGridControlColumnDisplayIndexChangedEvent>().Subscribe(OnCustomFormGridControlColumnDisplayIndexChangedEvent);
				eventAggregator.GetEvent<SimulationRunStartedEvent>().Subscribe(OnSimulationRunStartedEvent);
				eventAggregator.GetEvent<SimulationRunCompletedEvent>().Subscribe(OnSimulationRunCompletedEvent);
				eventAggregator.GetEvent<SimulationRunFailedEvent>().Subscribe(OnSimulationRunFailedEvent);
				eventAggregator.GetEvent<SimulationReinitializedEvent>().Subscribe(OnSimulationReinitializedEvent);
				eventAggregator.GetEvent<SimulationIntegrationStepEvent>().Subscribe(OnSimulationIntegrationStepEvent);
				eventAggregator.GetEvent<CustomFormVariableRepairedEvent>().Subscribe(OnCustomFormVariableRepairedEvent);
				_eventsSubscribed = true;
			}
		}

		private void UnsubscribeEvents()
		{
			if (UnityContainer != null && _eventsSubscribed)
			{
				IEventAggregator eventAggregator = UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				eventAggregator.GetEvent<UpdateAllEvent>().Unsubscribe(OnUpdateAll);
				eventAggregator.GetEvent<CustomFormChangedEvent>().Unsubscribe(OnCustomFormChanged);
				eventAggregator.GetEvent<ObjectRenamedAnywhereEvent>().Unsubscribe(OnObjectRenamedAnywhereEvent);
				eventAggregator.GetEvent<CustomFormFirstColumnUpdateDataEvent>().Unsubscribe(OnCustomFormFirstColumnDataChangedEvent);
				eventAggregator.GetEvent<BeforeSavingEvent>().Unsubscribe(OnBeforeSavingEvent);
				eventAggregator.GetEvent<QueryCustomTableFormPartEvent>().Unsubscribe(OnQueryCustomTableFormPartEvent);
				eventAggregator.GetEvent<StoreValueEvent>().Unsubscribe(OnStoreValueEvent);
				eventAggregator.GetEvent<PFSEmbeddedCustomTableStoreValueEvent>().Unsubscribe(OnPFSEmbeddedCustomTableStoreValueEvent);
				eventAggregator.GetEvent<CustomFormGridControlColumnDisplayIndexChangedEvent>().Unsubscribe(OnCustomFormGridControlColumnDisplayIndexChangedEvent);
				eventAggregator.GetEvent<SimulationRunStartedEvent>().Unsubscribe(OnSimulationRunStartedEvent);
				eventAggregator.GetEvent<SimulationRunCompletedEvent>().Unsubscribe(OnSimulationRunCompletedEvent);
				eventAggregator.GetEvent<SimulationRunFailedEvent>().Unsubscribe(OnSimulationRunFailedEvent);
				eventAggregator.GetEvent<SimulationReinitializedEvent>().Unsubscribe(OnSimulationReinitializedEvent);
				eventAggregator.GetEvent<SimulationIntegrationStepEvent>().Unsubscribe(OnSimulationIntegrationStepEvent);
				eventAggregator.GetEvent<CustomFormVariableRepairedEvent>().Unsubscribe(OnCustomFormVariableRepairedEvent);
				_eventsSubscribed = false;
			}
		}

		private void InitializeTabs()
		{
			FormLayout formLayout = DataHelper.LoadCustomFormLayout(MainNode);
			if (formLayout == null)
			{
				CustomFormControlPage customFormControlPage = new CustomFormControlPage(this, showRealValuesAsTooltips: true)
				{
					Title = CustomFormsResources.DefaultTabName
				};
				thePanel.GridControls.Add(customFormControlPage);
				customFormControlPage.InitializeLayout(CreateInitialTabLayout(customFormControlPage.Title));
			}
			else
			{
				foreach (TabLayout tab in formLayout.Tabs)
				{
					CustomFormControlPage customFormControlPage2 = new CustomFormControlPage(this, showRealValuesAsTooltips: true)
					{
						Title = tab.Name
					};
					thePanel.GridControls.Add(customFormControlPage2);
					customFormControlPage2.InitializeLayout(tab);
				}
			}
			thePanel.ActiveGridControl = thePanel.GridControls.FirstOrDefault();
			InvalidateData(recalculateStreamReportExtraProperties: true);
		}

		private TabLayout CreateInitialTabLayout(string pageName)
		{
			return new TabLayout
			{
				Name = pageName,
				Columns = 
				{
					new ColumnLayout
					{
						AttributeName = "name"
					},
					new ColumnLayout
					{
						AttributeName = "value"
					},
					new ColumnLayout
					{
						AttributeName = "units"
					}
				}
			};
		}

		private void UpdateData()
		{
			if (EmbeddedInPFS)
			{
				DataProvider.UpdateDataCache();
			}
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				gridControl.InvalidateData();
			}
		}

		public void InvalidateData(bool recalculateStreamReportExtraProperties = false)
		{
			base.Dispatcher.BeginInvokeOnce(UpdateData, DispatcherPriority.Render);
			if (recalculateStreamReportExtraProperties)
			{
				base.Dispatcher.BeginInvokeOnce(SendExtraStreamReportPropertiesToEngine);
			}
		}

		public void SaveFormLayout()
		{
			FormLayout formLayout = new FormLayout();
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				formLayout.Tabs.Add(gridControl.SaveTabLayout());
			}
			if (MainNode != null)
			{
				DataHelper.SaveCustomFormLayout(MainNode, formLayout);
			}
		}

		public void PlaceOnFlowsheet(bool bPlaceAsIcon)
		{
			for (int i = 0; i < thePanel.GridControls.Count; i++)
			{
				if (thePanel.ActiveGridControl == thePanel.GridControls[i])
				{
					ActiveGridControlIndex = i;
					break;
				}
			}
			SaveFormLayout();
			CommonImages commonImages = new CommonImages();
			Image image = new Image();
			image.Source = commonImages.DataSheet_32;
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomFormPlaceOnFlowsheetEvent>().Publish(new CustomFormPlaceOnFlowsheetEventArgs(this, image, MainNodePath, bPlaceAsIcon));
		}

		private void OnStoreValueEvent(StoreValueEventArgs args)
		{
			StoreValue();
		}

		private void OnPFSEmbeddedCustomTableStoreValueEvent(PFSEmbeddedCustomTableStoreValueEventArgs args)
		{
			StoreValue();
		}

		private static string GetHierarchyFullPath(string strHierarchy, bool bAllHierarchy)
		{
			string[] array = strHierarchy.Split('.');
			string text = string.Empty;
			string[] array2 = array;
			foreach (string text2 in array2)
			{
				text = text + "." + text2 + ".Data.Blocks";
			}
			text = text.TrimStart('.');
			if (!bAllHierarchy)
			{
				text = text.TrimEnd(".Data.Blocks".ToArray());
			}
			return text;
		}

		private void OnSimulationRunStartedEvent(SimulationRunStartedEventArgs e)
		{
			InvalidateData();
		}

		private void OnSimulationRunCompletedEvent(SimulationRunCompletedEventArgs e)
		{
			InvalidateData(recalculateStreamReportExtraProperties: true);
		}

		private void OnSimulationRunFailedEvent(SimulationRunFailedEventArgs e)
		{
			InvalidateData(recalculateStreamReportExtraProperties: true);
		}

		private void OnSimulationReinitializedEvent(SimulationReinitializedEventArgs e)
		{
			InvalidateData();
		}

		private void OnSimulationIntegrationStepEvent(SimulationIntegrationStepEventArgs e)
		{
			InvalidateData();
		}

		private void OnCustomFormVariableRepairedEvent(CustomFormVariableRepairedEventArgs e)
		{
			base.Dispatcher.BeginInvoke((Action<CustomFormVariableRepairedEventArgs>)delegate(CustomFormVariableRepairedEventArgs args)
			{
				if (args.ContainsCustomFormNode(MainNodePath))
				{
					ReloadTabs();
				}
			}, DispatcherPriority.Loaded, e);
		}

		private void SendExtraStreamReportPropertiesToEngine()
		{
			List<string> list = new List<string>();
			List<TemplatePropertyItem> list2 = new List<TemplatePropertyItem>();
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				foreach (CustomFormDataRow item in gridControl.DataSource.Rows.ToList())
				{
					StreamReportExtraPropertyInfo streamReportExtraPropertyInfo = item.InitialRowLayout?.SrepInfo;
					if (streamReportExtraPropertyInfo != null)
					{
						if (!list.Contains(streamReportExtraPropertyInfo.Stream))
						{
							list.Add(streamReportExtraPropertyInfo.Stream);
						}
						if (!list2.Contains(streamReportExtraPropertyInfo.Template))
						{
							list2.Add(streamReportExtraPropertyInfo.Template);
						}
					}
				}
			}
			SteamReportEngineCalculator.DoCalculationForRawProperties(list, list2);
		}

		private void ReloadTabs()
		{
			CxsCase?.RefreshAllNodes();
			FormLayout formLayout = DataHelper.LoadCustomFormLayout(MainNode);
			if (formLayout == null)
			{
				return;
			}
			foreach (TabLayout tabLayout in formLayout.Tabs)
			{
				if (thePanel.GridControls.FirstOrDefault((GridControl x) => string.Equals(x.Title, tabLayout.Name, StringComparison.CurrentCultureIgnoreCase)) is CustomFormControlPage customFormControlPage)
				{
					customFormControlPage.ReloadLayoutVariables(tabLayout);
				}
			}
		}

		private void StoreValue()
		{
			if (!EmbeddedInPFS || !(thePanel.ActiveGridControl is CustomFormControlPage customFormControlPage))
			{
				return;
			}
			_ = customFormControlPage.CurrentCell;
			if (customFormControlPage.CurrentCell.Row != null && customFormControlPage.CurrentCell.Column != null && customFormControlPage.CurrentCell.Data != null)
			{
				GridControlCell hostControl = customFormControlPage.CurrentCell.Data.HostControl;
				if (hostControl != null && !hostControl.IsKeyboardFocusWithin && hostControl.IsInEditMode && thePanel.ActiveGridControl != null)
				{
					thePanel.ActiveGridControl.Focus();
				}
			}
		}

		public void OnBeforeSavingEvent(BeforeSavingEventArgs args)
		{
			if (EmbeddedInPFS)
			{
				QueryCustomTableFormPartEventArgs e = new QueryCustomTableFormPartEventArgs(MainNodePath);
				UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<QueryCustomTableFormPartEvent>().Publish(e);
				if (!e.FormIsOpen)
				{
					SaveFormLayout();
				}
			}
			else
			{
				SaveFormLayout();
			}
		}

		public void OnQueryCustomTableFormPartEvent(QueryCustomTableFormPartEventArgs args)
		{
			if (!EmbeddedInPFS && MainNodePath == args.MainNodePath)
			{
				args.FormIsOpen = true;
			}
		}

		private void OnObjectRenamedAnywhereEvent(ObjectRenamedAnywhereEventArgs args)
		{
			if (args.IsCxsPathImpacted(MainNodePath))
			{
				MainNodePath = args.GetNewPathAfterRenamed(MainNodePath);
				MainNode = CxsCase.ResolveNode(MainNodePath);
			}
		}

		private void OnCustomFormFirstColumnDataChangedEvent(CustomFormFirstColumnUpdateDataEventArgs args)
		{
			if (!args.CustomFormPath.Equals(MainNodePath) || args.CustomFormInstance as CustomFormControl == this)
			{
				return;
			}
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				if (gridControl.Title == args.TabName)
				{
					if (gridControl.DataSource is CustomFormDataTable customFormDataTable && customFormDataTable.Rows.Count > args.RowIndex && customFormDataTable.Rows[args.RowIndex][0].Value as string != args.NewValue)
					{
						s_bFirstColumnValueChangedByAssignValue = true;
						customFormDataTable.Rows[args.RowIndex][0].Value = args.NewValue;
						s_bFirstColumnValueChangedByAssignValue = false;
					}
					break;
				}
			}
		}

		private string RetrieveFlowshetSubjectFromPath(string sPath)
		{
			string text = string.Empty;
			_ = string.Empty;
			int num;
			for (num = sPath.IndexOf(".Blocks.", 0); num >= 0; num = sPath.IndexOf(".Blocks.", num))
			{
				num += 8;
				int num2 = sPath.IndexOf('.', num);
				if (text != string.Empty)
				{
					text += ".";
				}
				text += sPath.Substring(num, num2 - num);
				sPath.Substring(0, num2);
			}
			return text;
		}

		public void PublishDataChangedEvent()
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateAllEvent>().Publish(new UpdateAllEventArgs());
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateDisplayEvent>().Publish(new UpdateDisplayEventArgs());
		}

		protected virtual void OnUpdateAll(UpdateAllEventArgs e)
		{
			InvalidateData();
		}

		public void PublishCustomFormChangedEvent(CustomFormChangeAction action, string tabName, string oldTabName, bool saveLayoutFirst)
		{
			if (saveLayoutFirst)
			{
				SaveFormLayout();
			}
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomFormChangedEvent>().Publish(new CustomFormChangedEventArgs(this, MainNodePath, tabName, action)
			{
				OldTabName = oldTabName
			});
			if (action == CustomFormChangeAction.RowsChanged || action == CustomFormChangeAction.ColumnsChanged || action == CustomFormChangeAction.TabRemmoved)
			{
				Dispatcher.CurrentDispatcher.BeginInvoke(DispatcherPriority.Loaded, (Action)delegate
				{
					string mainNodePath = MainNodePath;
					string strCustomFormPath = mainNodePath.Substring(mainNodePath.LastIndexOf(".") + 1);
					string strFlowsheetSubject = RetrieveFlowshetSubjectFromPath(mainNodePath);
					UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomFormLayoutChangedEvent>().Publish(new CustomFormLayoutChangedEventArgs(strFlowsheetSubject, strCustomFormPath));
				});
			}
		}

		protected virtual void OnCustomFormChanged(CustomFormChangedEventArgs e)
		{
			if (e.Source == this || !string.Equals(e.MainNodePath, MainNodePath))
			{
				return;
			}
			switch (e.Action)
			{
			case CustomFormChangeAction.TabAdded:
				thePanel.GridControls.Clear();
				InvalidateTabs();
				break;
			case CustomFormChangeAction.TabRemmoved:
				thePanel.GridControls.Clear();
				InvalidateTabs();
				break;
			case CustomFormChangeAction.TabRenamed:
			{
				GridControl gridControl = thePanel.GridControls.FirstOrDefault((GridControl x) => string.Equals(x.Title, e.OldTabName));
				if (gridControl != null)
				{
					gridControl.Title = e.TabName;
				}
				break;
			}
			case CustomFormChangeAction.RowsChanged:
			case CustomFormChangeAction.ColumnsChanged:
			{
				if (!(thePanel.GridControls.FirstOrDefault((GridControl x) => string.Equals(x.Title, e.TabName)) is CustomFormControlPage customFormControlPage))
				{
					break;
				}
				FormLayout formLayout = DataHelper.LoadCustomFormLayout(MainNode);
				if (formLayout != null)
				{
					TabLayout layout = formLayout.Tabs.FirstOrDefault((TabLayout x) => string.Equals(x.Name, e.TabName));
					customFormControlPage.InitializeLayout(layout);
				}
				break;
			}
			}
		}

		protected override void OnPreviewKeyDown(System.Windows.Input.KeyEventArgs e)
		{
			if (e.Key == Key.Delete)
			{
				CustomFormControlPage customFormControlPage = thePanel.ActiveGridControl as CustomFormControlPage;
				CustomFormDataTable customFormDataTable = customFormControlPage.DataSource as CustomFormDataTable;
				bool flag = false;
				_ = customFormControlPage.CurrentCell;
				if (customFormControlPage.CurrentCell.Row != null && customFormControlPage.CurrentCell.Column != null && customFormControlPage.CurrentCell.Data != null)
				{
					GridControlCell hostControl = customFormControlPage.CurrentCell.Data.HostControl;
					if (hostControl != null && hostControl.IsInEditMode)
					{
						flag = true;
					}
				}
				if (!flag)
				{
					List<DataRow> list = customFormControlPage.SelectedRows.ToList();
					bool flag2 = false;
					bool flag3 = false;
					foreach (DataRow item in list)
					{
						if (!customFormDataTable.Rows.Contains(item))
						{
							continue;
						}
						if (!flag2)
						{
							if (MMMessageBoxResult.Yes != MMMessageBox.Show(System.Windows.Application.Current.MainWindow, ApwnResources.Confirm_To_Delete_The_Selected_Row, ApwnResources.Delete_Row, MMMessageBoxButton.YesNo, MMMessageBoxImage.Information, showHelpButton: false, 2))
							{
								return;
							}
							flag2 = true;
						}
						if (flag2)
						{
							customFormDataTable.Rows.Remove(item);
							flag3 = true;
						}
					}
					if (flag3)
					{
						e.Handled = true;
						PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, customFormControlPage.Title, null, saveLayoutFirst: true);
						customFormControlPage.Focus();
					}
				}
			}
			base.OnPreviewKeyDown(e);
		}

		private void InvalidateTabs()
		{
			if (base.IsLoaded)
			{
				InitializeTabs();
			}
			else if (!IsTabsInvalid)
			{
				IsTabsInvalid = true;
			}
		}

		public void FocusOnActiveGrid()
		{
			if (thePanel.ActiveGridControl != null && !thePanel.ActiveGridControl.IsKeyboardFocusWithin)
			{
				thePanel.ActiveGridControl.Focus();
			}
		}

		public void SetDirtyFlag()
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>())?.GetEvent<SetDocumentDirtyEvent>()?.Publish(new SetDocumentDirtyEventArg
			{
				DirtyFlag = false,
				Source = "CustomTable"
			});
		}

		protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
		{
			FocusOnActiveGrid();
			e.Handled = true;
			base.OnMouseLeftButtonDown(e);
		}

		public virtual void Zoom(double factor)
		{
			thePanel.ZoomFactor = factor;
		}

		public void PublishCustomFormGridControlColumnDisplayIndexChangedEvent(CustomFormGridControlColumnDisplayIndexChangedEventArgs args)
		{
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomFormGridControlColumnDisplayIndexChangedEvent>().Publish(args);
		}

		private void OnCustomFormGridControlColumnDisplayIndexChangedEvent(CustomFormGridControlColumnDisplayIndexChangedEventArgs args)
		{
			if (args == null || args.CustomFormControl == this || !(args.CustomFormControlPage is CustomFormControlPage { DataGridControlInstance: not null } customFormControlPage))
			{
				return;
			}
			CustomFormControlPage customFormControlPage2 = null;
			foreach (GridControl gridControl in thePanel.GridControls)
			{
				if (gridControl.Title == customFormControlPage.Title)
				{
					customFormControlPage2 = gridControl as CustomFormControlPage;
					break;
				}
			}
			if (customFormControlPage2 == null || customFormControlPage2.DataGridControlInstance == null)
			{
				return;
			}
			foreach (DataGridColumn column in customFormControlPage2.DataGridControlInstance.Columns)
			{
				if (column.Header != null && column.Header is DataColumn && (column.Header as DataColumn).Header == args.ColumnHeader)
				{
					CustomFormControlPage.s_bColumnIndexChangingByCode = true;
					column.DisplayIndex = args.ColumnDisplayIndex;
					CustomFormControlPage.s_bColumnIndexChangingByCode = false;
					break;
				}
			}
		}

		public void FindVariables()
		{
			try
			{
				CaseVariablesBrowser caseVariablesBrowser = null;
				caseVariablesBrowser = new CaseVariablesBrowser();
				if (caseVariablesBrowser != null)
				{
					caseVariablesBrowser.SetCxsCase(CxsCase);
					caseVariablesBrowser.Owner = Window.GetWindow(this);
					caseVariablesBrowser.ShowDialog();
					if (caseVariablesBrowser.UserClickedOK && caseVariablesBrowser.SelectedPaths != null && caseVariablesBrowser.SelectedPaths.Count > 0)
					{
						CustomFormControlPage customFormControlPage = thePanel.ActiveGridControl as CustomFormControlPage;
						IList<DataRow> rows = (customFormControlPage.DataSource as CustomFormDataTable).InsertVariablesByPaths(caseVariablesBrowser.SelectedPaths);
						customFormControlPage.ExclusiveSelectRows(rows);
						PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, customFormControlPage.Title, null, saveLayoutFirst: true);
					}
				}
			}
			catch (Exception ex)
			{
				MMMessageBox.Show(ex.Message);
			}
		}

		public void SendToMultiCase()
		{
			SaveFileDialog saveFileDialog = new SaveFileDialog();
			saveFileDialog.Filter = "JSON files (*.json)|*.json";
			saveFileDialog.FilterIndex = 2;
			if (saveFileDialog.ShowDialog() == DialogResult.Cancel)
			{
				return;
			}
			string path = ((Path.GetExtension(saveFileDialog.FileName) == ".json") ? saveFileDialog.FileName : (saveFileDialog.FileName + ".json"));
			List<string> list = new List<string>();
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				if (!(gridControl.DataSource is CustomFormDataTable customFormDataTable))
				{
					continue;
				}
				foreach (DataRow row in customFormDataTable.Rows)
				{
					new Variable();
					int num = 0;
					while (true)
					{
						try
						{
							if (row[num] == null)
							{
								break;
							}
						}
						catch
						{
							break;
						}
						if ((row[num].Column as CustomFormDataColumn).ColumnAttribute == "path")
						{
							string text = row[num].ValueAsString;
							if (text.Contains("#"))
							{
								string text2 = "Top.appModel.";
								IHNode iHNode = null;
								IHapp happ = null;
								if (UnityContainer.Resolve<object>("RootApplicationObject", Array.Empty<ResolverOverride>()) is IHapp happ2)
								{
									try
									{
										iHNode = happ2.Tree;
									}
									catch (Exception)
									{
									}
									IHNode iHNode2 = iHNode.FindNode("Data");
									string[] array = text.Split('.');
									for (int i = 2; i < array.Length; i++)
									{
										if (array[i].Contains("#"))
										{
											array[i] = iHNode2.Elements[int.Parse(array[i].Replace("#", "")), Type.Missing, Type.Missing, Type.Missing, Type.Missing].get_Name(Type.Missing);
											iHNode2 = iHNode2.Elements[array[i], Type.Missing, Type.Missing, Type.Missing, Type.Missing];
											if (iHNode2 != null)
											{
												text2 = ((!text.Contains(".Output.")) ? (text2 + iHNode2.get_Name(Type.Missing) + ".") : (text2 + "Substreams." + iHNode2.get_Name(Type.Missing) + "."));
											}
										}
										else
										{
											iHNode2 = iHNode2.Elements[array[i], Type.Missing, Type.Missing, Type.Missing, Type.Missing];
											if (iHNode2 != null)
											{
												text2 = text2 + iHNode2.get_Name(Type.Missing) + ".";
											}
										}
									}
									text = text2.Remove(text2.Length - 1);
								}
							}
							list.Add("{\"Identifier\": \"" + text + "\"}");
						}
						num++;
					}
				}
			}
			File.WriteAllText(path, "{\"Name\": \"CustomForm\",\"Variables\": [" + string.Join(",", list) + "]}");
		}

		public void SendToExcel()
		{
			ExportTemplate exportTemplate = new ExportTemplate();
			foreach (CustomFormControlPage gridControl in thePanel.GridControls)
			{
				if (!(gridControl.DataSource is CustomFormDataTable customFormDataTable))
				{
					continue;
				}
				List<DataColumn> list = new List<DataColumn>();
				for (int i = 0; i < customFormDataTable.Columns.Count; i++)
				{
					foreach (DataColumn column2 in customFormDataTable.Columns)
					{
						if (column2.DisplayIndex == i)
						{
							list.Add(column2);
							break;
						}
					}
				}
				if (list.Count == 0)
				{
					list = customFormDataTable.Columns.ToList();
				}
				Table table = new Table();
				table.Name = gridControl.Title;
				foreach (CustomFormDataColumn item in list)
				{
					if (item.Visibility == Visibility.Visible)
					{
						Column column = new Column();
						string attribute = string.Empty;
						column.Header = item.Header;
						switch (item.ColumnAttribute)
						{
						case "name":
							attribute = "Name";
							break;
						case "units":
							attribute = "Units";
							break;
						case "value":
							attribute = "Value";
							break;
						case "status":
							attribute = "Status";
							break;
						case "container":
							attribute = "Container";
							break;
						case "container_category":
							attribute = "Container_Category";
							break;
						case "container_type":
							attribute = "Container_Type";
							break;
						case "lower_limit":
							attribute = "Lower";
							break;
						case "upper_limit":
							attribute = "Upper";
							break;
						case "path":
							attribute = "Path";
							break;
						case "variable name":
							attribute = "VariableName";
							break;
						case "object name":
							attribute = "ObjectName";
							break;
						case "object type":
							attribute = "ObjectType";
							break;
						case "object id1":
							attribute = "ID1";
							break;
						case "object id2":
							attribute = "ID2";
							break;
						case "object id3":
							attribute = "ID3";
							break;
						}
						column.Attribute = attribute;
						table.Columns.Add(column);
					}
				}
				foreach (DataRow row in customFormDataTable.Rows)
				{
					Variable variable = new Variable();
					int num = 0;
					while (true)
					{
						try
						{
							if (row[num] == null)
							{
								break;
							}
						}
						catch
						{
							break;
						}
						switch ((row[num].Column as CustomFormDataColumn).ColumnAttribute)
						{
						case "name":
							variable.Attributes.Add("Name", row[num].ValueAsString);
							break;
						case "units":
							variable.Attributes.Add("Units", row[num].ValueAsString);
							break;
						case "value":
						{
							string text = row[num].ValueAsString;
							double result = 0.0;
							if (!string.IsNullOrEmpty(text) && double.TryParse(text, out result))
							{
								text = text.Replace(GetSystemDecimalSymbol(), ".");
							}
							variable.Attributes.Add("Value", text);
							break;
						}
						case "status":
							variable.Attributes.Add("Status", row[num].ValueAsString);
							break;
						case "container":
							variable.Attributes.Add("Container", row[num].ValueAsString);
							break;
						case "container_category":
							variable.Attributes.Add("Container_Category", row[num].ValueAsString);
							break;
						case "container_type":
							variable.Attributes.Add("Container_Type", row[num].ValueAsString);
							break;
						case "lower_limit":
							variable.Attributes.Add("Lower", row[num].ValueAsString);
							break;
						case "upper_limit":
							variable.Attributes.Add("Upper", row[num].ValueAsString);
							break;
						case "path":
							variable.Attributes.Add("Path", row[num].ValueAsString);
							break;
						case "variable name":
							variable.Attributes.Add("VariableName", row[num].ValueAsString);
							break;
						case "object name":
							variable.Attributes.Add("ObjectName", row[num].ValueAsString);
							break;
						case "object type":
							variable.Attributes.Add("ObjectType", row[num].ValueAsString);
							break;
						case "object id1":
							variable.Attributes.Add("ID1", row[num].ValueAsString);
							break;
						case "object id2":
							variable.Attributes.Add("ID2", row[num].ValueAsString);
							break;
						case "object id3":
							variable.Attributes.Add("ID3", row[num].ValueAsString);
							break;
						}
						num++;
					}
					table.Variables.Add(variable);
				}
				exportTemplate.Tables.Add(table);
			}
			if (CxsCase != null)
			{
				exportTemplate.ApplicationName = CxsCase.ApplicationName;
				exportTemplate.Case = CxsCase;
				exportTemplate.CasePath = CxsCase.CaseFullFilePath;
			}
			try
			{
				exportTemplate.Owner = Window.GetWindow(base.Parent);
			}
			catch
			{
				exportTemplate.Owner = null;
			}
			exportTemplate.OpenDialog(CustomFormsResources.ExportCustomTables);
		}

		void IAXEmbeddedObject.CopyAXEmbeddedObjectContent()
		{
			if (!(thePanel.ActiveGridControl is CustomFormControlPage { DataSource: CustomFormDataTable dataSource }) || dataSource.Rows.Count <= 0)
			{
				return;
			}
			List<DataCellInfo> list = new List<DataCellInfo>();
			foreach (DataRow row in dataSource.Rows)
			{
				foreach (DataColumn column in dataSource.Columns)
				{
					list.Add(new DataCellInfo(row, column));
				}
			}
			string data = GridClipboardHelper.GenerateTextToCopy(dataSource, dataSource.Rows, dataSource.Columns, list, includeHeader: true);
			object data2 = CustomFormControlPage.CreateAsiFormatData(dataSource, list, CxsCase);
			System.Windows.DataObject dataObject = new System.Windows.DataObject();
			dataObject.SetData(System.Windows.DataFormats.Text, data);
			dataObject.SetData(System.Windows.DataFormats.GetDataFormat("ASI Format").Name, data2);
			System.Windows.Clipboard.SetDataObject(dataObject, copy: true);
		}

		bool IAXEmbeddedObject.CanAXEmbeddedObjectCopy()
		{
			if (thePanel.ActiveGridControl is CustomFormControlPage { DataSource: not null } customFormControlPage && customFormControlPage.DataSource.Rows.Count > 0)
			{
				return true;
			}
			return false;
		}

		void IAXEmbeddedObject.Zoom(double factor)
		{
			Zoom(factor);
		}

		void IAXEmbeddedObject.GetContentSize(ref int nContentWidth, ref int nContentHeight)
		{
			double val = 1600.0;
			double val2 = 800.0;
			double num = 25.0;
			double num2 = 90.0;
			double num3 = 120.0;
			double num4 = 25.0;
			double num5 = num;
			double num6 = 0.0;
			double num7 = 32.0;
			double num8 = 6.0;
			double num9 = 6.0;
			CustomFormDataTable customFormDataTable = thePanel.ActiveGridControl.DataSource as CustomFormDataTable;
			foreach (DataRow row in customFormDataTable.Rows)
			{
				_ = row;
				num5 += num;
			}
			bool flag = false;
			if (Utilities.GetDescendantFromName(this, "PART_ColumnHeadersPresenter") is DataGridColumnHeadersPresenter parent && Utilities.GetDescendantFromType(parent, typeof(DataGridCellsPanel), allowSubclassOfType: true) is DataGridCellsPanel { Children: not null } dataGridCellsPanel)
			{
				if (dataGridCellsPanel.Children.Count == customFormDataTable.Columns.Count)
				{
					for (int i = 0; i < dataGridCellsPanel.Children.Count; i++)
					{
						UIElement uIElement = dataGridCellsPanel.Children[i];
						if (uIElement is DataGridColumnHeader)
						{
							DataGridColumnHeader dataGridColumnHeader = uIElement as DataGridColumnHeader;
							num6 = ((!double.IsNaN(dataGridColumnHeader.ActualWidth)) ? (num6 + dataGridColumnHeader.ActualWidth) : ((i != 0) ? (num6 + num2) : (num6 + num3)));
						}
					}
					num6 += num4;
					flag = true;
				}
				else if (!double.IsNaN(dataGridCellsPanel.ActualWidth))
				{
					num6 = dataGridCellsPanel.DesiredSize.Width;
					num6 += num4;
					flag = true;
				}
			}
			if (!flag)
			{
				for (int j = 0; j < customFormDataTable.Columns.Count; j++)
				{
					if (customFormDataTable.Columns[j].Visibility == Visibility.Visible)
					{
						num6 = ((j != 0) ? (num6 + num2) : (num6 + num3));
					}
				}
				num6 += num4;
			}
			nContentWidth = (int)Math.Min(num6, val) + (int)num8 + (int)num9;
			nContentHeight = (int)Math.Min(num5, val2) + (int)num7;
		}

		void IAXEmbeddedObject.CompactView()
		{
		}

		void IAXEmbeddedObject.UpdateAXData()
		{
			InvalidateData();
		}

		void IAXEmbeddedObject.ResetInternalStatus()
		{
			if (!EmbeddedInPFS || !(thePanel.ActiveGridControl is CustomFormControlPage customFormControlPage))
			{
				return;
			}
			_ = customFormControlPage.CurrentCell;
			if (customFormControlPage.CurrentCell.Row != null && customFormControlPage.CurrentCell.Column != null && customFormControlPage.CurrentCell.Data != null)
			{
				GridControlCell hostControl = customFormControlPage.CurrentCell.Data.HostControl;
				if (hostControl != null && !hostControl.IsKeyboardFocusWithin && hostControl.IsInEditMode)
				{
					customFormControlPage.Focus();
					hostControl.EndEditModeIfPossible(commitChange: true);
				}
			}
		}

		void IAXEmbeddedObject.NotifyUpdatedData()
		{
		}

		bool IAXEmbeddedObject.PreparePrintingData(string strCageKey)
		{
			if (string.IsNullOrEmpty(strCageKey))
			{
				return false;
			}
			if (UnityContainer == null)
			{
				return false;
			}
			if (thePanel.GridControls == null)
			{
				return false;
			}
			if (!(thePanel.GridControls[0].DataSource is CustomFormDataTable customFormDataTable))
			{
				return false;
			}
			if (!(Utilities.GetDescendantFromName(this, "PART_RowsPresenter") is DataGridRowsPresenter { Children: var children }))
			{
				return false;
			}
			if (children == null || children.Count == 0)
			{
				return false;
			}
			List<int> list = new List<int>();
			List<int> list2 = new List<int>();
			foreach (object item in children)
			{
				UIElement uIElement = item as UIElement;
				if (uIElement.Visibility != Visibility.Visible || uIElement.TranslatePoint(new Point(0.0, 0.0), this).Y >= base.Height || !(item is GridControlDataGridRow))
				{
					continue;
				}
				GridControlDataGridRow gridControlDataGridRow = item as GridControlDataGridRow;
				if (!gridControlDataGridRow.IsVisible)
				{
					continue;
				}
				if (gridControlDataGridRow.DataContext is DataRow)
				{
					list.Add(customFormDataTable.Rows.IndexOf(gridControlDataGridRow.DataContext as DataRow));
				}
				if (list2.Count != 0 || !(Utilities.GetDescendantFromType(gridControlDataGridRow, typeof(DataGridCellsPanel), allowSubclassOfType: true) is DataGridCellsPanel dataGridCellsPanel))
				{
					continue;
				}
				foreach (object child in dataGridCellsPanel.Children)
				{
					if ((child is UIElement uIElement2 && uIElement2.TranslatePoint(new Point(0.0, 0.0), this).X >= base.Width) || !(child is GridControlCell))
					{
						continue;
					}
					GridControlCell gridControlCell = child as GridControlCell;
					if (gridControlCell.IsVisible && gridControlCell.Column is GridControlColumn)
					{
						DataColumn dataColumn = (gridControlCell.Column as GridControlColumn).DataColumn;
						if (dataColumn != null)
						{
							list2.Add(customFormDataTable.Columns.IndexOf(dataColumn));
						}
					}
				}
			}
			list.Sort();
			list2.Sort();
			int num = 0;
			int num2 = 0;
			List<DataRow> list3 = new List<DataRow>();
			List<DataColumn> list4 = new List<DataColumn>();
			foreach (DataRow row in customFormDataTable.Rows)
			{
				if (row.Visibility == Visibility.Visible && list.Contains(customFormDataTable.Rows.IndexOf(row)))
				{
					list3.Add(row);
					num++;
				}
			}
			foreach (DataColumn column in customFormDataTable.Columns)
			{
				if (column.Visibility == Visibility.Visible && list2.Contains(customFormDataTable.Columns.IndexOf(column)))
				{
					list4.Add(column);
					num2++;
				}
			}
			int headerHeight = 25;
			string[] array = new string[num2];
			string[,] array2 = new string[num, num2];
			short[,] array3 = new short[num, num2];
			short[,] array4 = new short[num, num2];
			int[] array5 = new int[num];
			int[] array6 = new int[num2];
			int num3 = 0;
			foreach (DataColumn item2 in list4)
			{
				if (string.IsNullOrEmpty(item2.Header))
				{
					array[num3] = " ";
				}
				else
				{
					array[num3] = item2.Header;
				}
				array6[num3] = ((!item2.Width.HasValue) ? 50 : ((int)item2.Width.Value));
				num3++;
			}
			num3 = 0;
			foreach (DataRow item3 in list3)
			{
				_ = item3;
				array5[num3] = 25;
				num3++;
			}
			for (int i = 0; i < list3.Count; i++)
			{
				for (int j = 0; j < list4.Count; j++)
				{
					string empty = string.Empty;
					IDataCell dataCell = list3[i][j];
					if (dataCell == null)
					{
						empty = " ";
						array3[i, j] = 0;
					}
					else
					{
						empty = (string.IsNullOrEmpty(dataCell.ValueAsString) ? " " : dataCell.ValueAsString);
						switch (dataCell.ContentHorizontalAlignment)
						{
						case System.Windows.HorizontalAlignment.Left:
							array3[i, j] = 0;
							break;
						case System.Windows.HorizontalAlignment.Center:
							array3[i, j] = 1;
							break;
						case System.Windows.HorizontalAlignment.Right:
							array3[i, j] = 2;
							break;
						default:
							array3[i, j] = 0;
							break;
						}
					}
					string text = "";
					if (j == 0)
					{
						if (list3[i].GroupingRowsCount > 0)
						{
							if (list3[i].GroupingState == RowGroupingState.Expanded)
							{
								text = "- ";
							}
							else if (list3[i].GroupingState == RowGroupingState.Collapsed)
							{
								text = "+ ";
							}
							array4[i, j] = 1;
						}
						else
						{
							array4[i, j] = 0;
						}
					}
					else
					{
						array4[i, j] = 0;
					}
					int num4 = (int)(list3[i].GroupingIndent / 10.0 * 1.5);
					string text2 = "";
					if (j == 0)
					{
						while (num4 > 0)
						{
							text2 += " ";
							num4--;
						}
					}
					array2[i, j] = text2 + text + empty;
				}
			}
			SetDataGridCageEventArgs e = new SetDataGridCageEventArgs
			{
				CageKey = strCageKey,
				Rows = num,
				Columns = num2,
				HeaderHeight = headerHeight,
				RowsHeightArray = array5,
				ColumnsWidthArray = array6,
				ColumnsLabelArray = array,
				Contents = array2,
				Align = array3,
				Style = array4,
				Successful = false
			};
			UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SetDataGridCageEvent>().Publish(e);
			return e.Successful;
		}

		void IAXEmbeddedObject.DisposePrintingData(string strCageKey)
		{
			if (!string.IsNullOrEmpty(strCageKey) && UnityContainer != null)
			{
				UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DisposeDataGridCageEvent>().Publish(new DisposeDataGridCageEventArgs(strCageKey));
			}
		}

		void IAXEmbeddedObject.SetupDataGridCage(string strCageKey)
		{
			if (!string.IsNullOrEmpty(strCageKey) && UnityContainer != null)
			{
				UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<SetupDataGridCageEvent>().Publish(new SetupDataGridCageEventArgs(strCageKey));
			}
		}

		void IAXEmbeddedObject.Close()
		{
			OnParentClosed();
		}

		void IShellZoomable.Zoom(double factor)
		{
			Zoom(factor);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.CustomForms;component/customformcontrol.xaml", UriKind.Relative);
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
				thePanel = (GridControlPanel)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class CustomFormControlPage : GridControl
	{
		private const string InternalUsedDraggingFormat = "CustomFormControlPage_InternalUsedDraggingFormat";

		public static readonly DependencyProperty IsActiveProperty;

		public static readonly RoutedUICommand InsertRowCommand;

		public static readonly RoutedUICommand DeleteRowCommand;

		public static readonly RoutedUICommand ClearValueCommand;

		public static readonly RoutedUICommand FindVariablesCommand;

		private bool m_bVariablesReorderFake;

		public static bool s_bColumnIndexChangingByCode;

		private bool _invalidateDataFlag;

		public bool IsActive
		{
			get
			{
				return (bool)GetValue(IsActiveProperty);
			}
			set
			{
				SetValue(IsActiveProperty, value);
			}
		}

		public CustomFormControl ParentFormControl { get; private set; }

		public bool ShowRealValuesAsTooltips { get; }

		static CustomFormControlPage()
		{
			IsActiveProperty = DependencyProperty.Register("IsActive", typeof(bool), typeof(CustomFormControlPage), new FrameworkPropertyMetadata(OnIsActivePropertyChanged));
			InsertRowCommand = new RoutedUICommand(CustomFormsResources.ContextMenuItem_InsertRow, "InsertRow", typeof(CustomFormControlPage));
			DeleteRowCommand = new RoutedUICommand(CustomFormsResources.ContextMenuItem_DeleteRow, "DeleteRow", typeof(CustomFormControlPage));
			ClearValueCommand = new RoutedUICommand(CustomFormsResources.ContextMenuItem_Clear, "ClearValue", typeof(CustomFormControlPage));
			FindVariablesCommand = new RoutedUICommand(CustomFormsResources.ContextMenuItem_FindVariables, "FindVariables", typeof(CustomFormControlPage));
			s_bColumnIndexChangingByCode = false;
			GridControl.AllowRowReorderProperty.OverrideMetadata(typeof(CustomFormControlPage), new FrameworkPropertyMetadata(true));
			CommandManager.RegisterClassCommandBinding(typeof(CustomFormControlPage), new CommandBinding(InsertRowCommand, InsertRowCommand_Executed, InsertRowCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(CustomFormControlPage), new CommandBinding(DeleteRowCommand, DeleteRowCommand_Executed, DeleteRowCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(CustomFormControlPage), new CommandBinding(ClearValueCommand, ClearValueCommand_Executed, ClearValueCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(CustomFormControlPage), new CommandBinding(FindVariablesCommand, FindVariablesCommand_Executed, FindVariablesCommand_CanExecute));
		}

		public CustomFormControlPage(CustomFormControl parentFormControl, bool showRealValuesAsTooltips = false)
		{
			if (parentFormControl == null)
			{
				throw new ArgumentNullException("parentFormControl");
			}
			ParentFormControl = parentFormControl;
			base.AllowRecordFiltering = false;
			ShowRealValuesAsTooltips = showRealValuesAsTooltips;
		}

		public void InitializeLayout(TabLayout layout)
		{
			if (layout == null)
			{
				throw new ArgumentNullException("layout");
			}
			base.Title = layout.Name;
			CustomFormDataTable customFormDataTable = new CustomFormDataTable(this);
			customFormDataTable.LoadLayout(layout);
			base.DataSource = customFormDataTable;
			if (!string.IsNullOrEmpty(layout.GridSettings))
			{
				LoadLayoutSettings(layout.GridSettings);
			}
		}

		public void ReloadLayoutVariables(TabLayout layout)
		{
			if (layout == null)
			{
				throw new ArgumentNullException("layout");
			}
			SaveLayoutSettings();
			CustomFormDataTable customFormDataTable = new CustomFormDataTable(this);
			customFormDataTable.LoadLayout(layout);
			base.DataSource = customFormDataTable;
			if (!string.IsNullOrEmpty(layout.GridSettings))
			{
				LoadLayoutSettings(layout.GridSettings);
			}
		}

		public TabLayout SaveTabLayout()
		{
			TabLayout tabLayout = new TabLayout
			{
				Name = base.Title
			};
			if (base.DataSource is CustomFormDataTable customFormDataTable)
			{
				customFormDataTable.SaveTabLayout(tabLayout);
			}
			tabLayout.GridSettings = SaveLayoutSettings();
			return tabLayout;
		}

		protected override void OnDragLeave(System.Windows.DragEventArgs e)
		{
			UpdateRowIndicatorLine(Visibility.Collapsed);
			base.OnDragLeave(e);
		}

		protected override void OnDragOver(System.Windows.DragEventArgs e)
		{
			if (!e.Data.GetDataPresent("CustomFormControlPage_InternalUsedDraggingFormat") || e.Data.GetData("CustomFormControlPage_InternalUsedDraggingFormat") != this)
			{
				string asiFormatTextFromDataObject = DataHelper.GetAsiFormatTextFromDataObject(e.Data);
				if (!string.IsNullOrEmpty(asiFormatTextFromDataObject))
				{
					IList<ClipboardCellDataTuple> list = DataHelper.ParseDataFromAsiFormat(asiFormatTextFromDataObject, ParentFormControl.CxsCase.CaseFullFilePath);
					if (list != null && list.Count > 0)
					{
						UpdateRowIndicatorLine(Visibility.Visible, (IInputElement x) => e.GetPosition(x));
					}
				}
			}
			base.OnDragOver(e);
			if (GetRowIndexOfRowIndicator() >= 0)
			{
				m_bVariablesReorderFake = true;
			}
		}

		protected override void OnDrop(System.Windows.DragEventArgs e)
		{
			if (!e.Data.GetDataPresent("CustomFormControlPage_InternalUsedDraggingFormat") || e.Data.GetData("CustomFormControlPage_InternalUsedDraggingFormat") != this)
			{
				string asiFormatTextFromDataObject = DataHelper.GetAsiFormatTextFromDataObject(e.Data);
				if (!string.IsNullOrEmpty(asiFormatTextFromDataObject))
				{
					IList<ClipboardCellDataTuple> list = DataHelper.ParseDataFromAsiFormat(asiFormatTextFromDataObject, ParentFormControl.CxsCase.CaseFullFilePath);
					if (list != null && list.Count > 0)
					{
						if (list.Count > 200)
						{
							MMMessageBox.Show(string.Format(CustomFormsResources.PasteTooManyVariables, 200), MMVersionHelper.MVGetProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
							return;
						}
						IList<DataRow> rows = (base.DataSource as CustomFormDataTable).InsertVariables(list, GetRowIndexOfRowIndicator());
						ExclusiveSelectRows(rows);
						UpdateRowIndicatorLine(Visibility.Collapsed);
						ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, base.Title, null, saveLayoutFirst: true);
						return;
					}
				}
			}
			if (e.OriginalSource is GridControlCell)
			{
				base.OnDrop(e);
			}
			if (m_bVariablesReorderFake)
			{
				m_bVariablesReorderFake = false;
				ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, base.Title, null, saveLayoutFirst: true);
			}
		}

		protected override bool CanPasteData()
		{
			bool flag = false;
			string asiFormatTextFromClipboard = DataHelper.GetAsiFormatTextFromClipboard();
			if (!string.IsNullOrEmpty(asiFormatTextFromClipboard))
			{
				IList<ClipboardCellDataTuple> list = DataHelper.ParseDataFromAsiFormat(asiFormatTextFromClipboard, ParentFormControl.CxsCase.CaseFullFilePath);
				if (list != null && list.Count > 0)
				{
					flag = ((CustomFormDataTable)base.DataSource).FixAndFilterExistingDatas(list).Any();
				}
				if (flag)
				{
					return flag;
				}
			}
			return base.CanPasteData();
		}

		protected override void OnDataPasting(GridControlPastingEventArgs e)
		{
			string asiFormatTextFromClipboard = DataHelper.GetAsiFormatTextFromClipboard();
			if (!string.IsNullOrEmpty(asiFormatTextFromClipboard))
			{
				IList<ClipboardCellDataTuple> list = DataHelper.ParseDataFromAsiFormat(asiFormatTextFromClipboard, ParentFormControl.CxsCase.CaseFullFilePath);
				if (list != null && list.Count > 0)
				{
					if (list.Count > 200)
					{
						MMMessageBox.Show(string.Format(CustomFormsResources.PasteTooManyVariables, 200), MMVersionHelper.MVGetProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
						return;
					}
					IList<DataRow> list2 = (base.DataSource as CustomFormDataTable).InsertVariables(list);
					if (list2 != null && list2.Count > 0)
					{
						ExclusiveSelectRows(list2);
						ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, base.Title, null, saveLayoutFirst: true);
						bool handled = (e.Cancel = true);
						e.Handled = handled;
						return;
					}
				}
			}
			base.OnDataPasting(e);
		}

		protected override void OnDataCopying(GridControlCopyEventArgs e)
		{
			e.ClipboardContents.Add("ASI Format", CreateAsiFormatDataForSelection());
			base.OnDataCopying(e);
		}

		protected override void OnDataDragging(System.Windows.IDataObject dataObject)
		{
			dataObject.SetData(System.Windows.DataFormats.GetDataFormat("ASI Format").Name, CreateAsiFormatDataForSelection(plainTextIsOk: true));
			dataObject.SetData("CustomFormControlPage_InternalUsedDraggingFormat", this);
			base.OnDataDragging(dataObject);
		}

		protected override void OnDefaultContextMenuOpening(DefaultContextMenuEventArgs e)
		{
			System.Windows.Controls.MenuItem menuItem = new System.Windows.Controls.MenuItem
			{
				Command = ApplicationCommands.Copy,
				CommandTarget = this,
				Icon = new Image
				{
					Source = ImageSourceHelper.Copy16
				}
			};
			System.Windows.Controls.MenuItem menuItem2 = new System.Windows.Controls.MenuItem
			{
				Command = ApplicationCommands.Paste,
				CommandTarget = this,
				Icon = new Image
				{
					Source = ImageSourceHelper.Paste16
				}
			};
			if (e.IsOpenFromGridCell)
			{
				e.DefaultContextMenu.Items.Clear();
				e.DefaultContextMenu.Items.Add(menuItem);
				e.DefaultContextMenu.Items.Add(menuItem2);
				e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
				{
					Command = ClearValueCommand,
					CommandTarget = this
				});
				e.DefaultContextMenu.Items.Add(new Separator());
				e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
				{
					Command = InsertRowCommand,
					CommandTarget = this
				});
				e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
				{
					Command = DeleteRowCommand,
					CommandTarget = this
				});
			}
			else if (e.IsOpenFromRowHeader)
			{
				e.DefaultContextMenu.Items.Clear();
				e.DefaultContextMenu.Items.Add(menuItem);
				e.DefaultContextMenu.Items.Add(menuItem2);
				e.DefaultContextMenu.Items.Add(new Separator());
				e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
				{
					Command = InsertRowCommand,
					CommandTarget = this
				});
				e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
				{
					Command = DeleteRowCommand,
					CommandTarget = this
				});
			}
			else if (e.IsOpenFromColumnHeader)
			{
				if (e.DefaultContextMenu.Items.Count > 0)
				{
					e.DefaultContextMenu.Items.Insert(0, new Separator());
				}
				e.DefaultContextMenu.Items.Insert(0, menuItem2);
				e.DefaultContextMenu.Items.Insert(0, menuItem);
			}
			else if (e.IsOpenFromHeaderPrefixArea)
			{
				if (e.DefaultContextMenu.Items.Count > 0)
				{
					e.DefaultContextMenu.Items.Insert(0, new Separator());
				}
				e.DefaultContextMenu.Items.Insert(0, menuItem2);
				e.DefaultContextMenu.Items.Insert(0, menuItem);
			}
			else if (e.IsOpenFromBlankArea)
			{
				e.DefaultContextMenu.Items.Clear();
				e.DefaultContextMenu.Items.Add(menuItem);
				e.DefaultContextMenu.Items.Add(menuItem2);
			}
			if (e.DefaultContextMenu.Items.Count > 0)
			{
				e.DefaultContextMenu.Items.Add(new Separator());
			}
			e.DefaultContextMenu.Items.Add(new System.Windows.Controls.MenuItem
			{
				Command = FindVariablesCommand,
				CommandTarget = this
			});
			base.OnDefaultContextMenuOpening(e);
		}

		protected override void OnDataSourceColumnsVisibilityChanged()
		{
			base.OnDataSourceColumnsVisibilityChanged();
			if (ParentFormControl != null)
			{
				ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.ColumnsChanged, base.Title, null, saveLayoutFirst: true);
			}
		}

		protected virtual void OnIsActiveChanged(bool oldValue, bool newValue)
		{
			if (_invalidateDataFlag && newValue)
			{
				InvalidateData();
			}
		}

		public override void OnApplyTemplate()
		{
			base.OnApplyTemplate();
			if (base.DataGrid != null)
			{
				base.DataGrid.ColumnDisplayIndexChanged += DataGrid_ColumnDisplayIndexChanged;
			}
		}

		private void DataGrid_ColumnDisplayIndexChanged(object sender, DataGridColumnEventArgs e)
		{
			if (!s_bColumnIndexChangingByCode && ParentFormControl != null && e.Column != null)
			{
				CustomFormGridControlColumnDisplayIndexChangedEventArgs args = new CustomFormGridControlColumnDisplayIndexChangedEventArgs
				{
					GridTabName = base.Title,
					CustomFormControl = ParentFormControl,
					ColumnHeader = ((e.Column.Header == null) ? string.Empty : ((e.Column.Header is DataColumn) ? (e.Column.Header as DataColumn).Header : string.Empty)),
					ColumnDisplayIndex = e.Column.DisplayIndex,
					CustomFormControlPage = this
				};
				ParentFormControl.PublishCustomFormGridControlColumnDisplayIndexChangedEvent(args);
			}
		}

		public new void InvalidateData()
		{
			if (base.DataSource is CustomFormDataTable customFormDataTable)
			{
				if (IsActive)
				{
					customFormDataTable.UpdateData();
					_invalidateDataFlag = false;
				}
				else
				{
					_invalidateDataFlag = true;
				}
			}
		}

		public void ExclusiveSelectRows(IList<DataRow> rows)
		{
			DeselectAll();
			if (rows == null || rows.Count <= 0)
			{
				return;
			}
			DataColumn dataColumn = ColumnFromDisplayIndex(0);
			if (dataColumn != null)
			{
				base.CurrentCell = new DataCellInfo(rows[0], dataColumn);
			}
			foreach (DataRow row in rows)
			{
				SelectRow(row);
			}
		}

		private object CreateAsiFormatDataForSelection(bool plainTextIsOk = false)
		{
			return CreateAsiFormatData(base.DataSource as CustomFormDataTable, base.TotalOrderedSelectedCells, ParentFormControl.CxsCase, plainTextIsOk);
		}

		public static object CreateAsiFormatData(CustomFormDataTable table, IEnumerable<DataCellInfo> cells, CxsCase cxsCase, bool plainTextIsOk = false)
		{
			if (table == null)
			{
				return null;
			}
			List<string> list = new List<string>();
			Dictionary<string, (string, int, int)> dictionary = new Dictionary<string, (string, int, int)>();
			List<DataRow> list2 = new List<DataRow>();
			foreach (DataCellInfo item in cells.ToList())
			{
				if (list2.Contains(item.Row))
				{
					continue;
				}
				list2.Add(item.Row);
				if (!(item.Row is CustomFormDataRow customFormDataRow))
				{
					continue;
				}
				string cxsPathForCopy = customFormDataRow.GetCxsPathForCopy();
				if (string.IsNullOrEmpty(cxsPathForCopy))
				{
					continue;
				}
				list.Add(cxsPathForCopy);
				IDataCell dataCell = customFormDataRow[0];
				if (dataCell == null)
				{
					continue;
				}
				string text = dataCell.Value as string;
				if (!string.IsNullOrEmpty(text) && !dictionary.Keys.Contains(cxsPathForCopy))
				{
					if (table.Columns == null || table.Columns.Count <= 1)
					{
						dictionary.Add(cxsPathForCopy, (text, list2.Count - 1, 0));
					}
					else if (table.Columns[1].Visibility == Visibility.Visible)
					{
						dictionary.Add(cxsPathForCopy, (text, list2.Count - 1, 2));
					}
					else
					{
						dictionary.Add(cxsPathForCopy, (text, list2.Count - 1, 1));
					}
				}
			}
			string text2 = DataHelper.GenerateAsiFormatText(cxsCase, list, dictionary);
			if (plainTextIsOk)
			{
				return text2;
			}
			return new MemoryStream(Encoding.UTF8.GetBytes(text2));
		}

		private static void OnIsActivePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CustomFormControlPage).OnIsActiveChanged((bool)e.OldValue, (bool)e.NewValue);
		}

		private static void InsertRowCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			CustomFormDataTable customFormDataTable = customFormControlPage.DataSource as CustomFormDataTable;
			int index = 0;
			if (customFormControlPage.CurrentDataRow != null)
			{
				index = customFormDataTable.Rows.IndexOf(customFormControlPage.CurrentDataRow);
			}
			customFormDataTable.Rows.Insert(index, customFormDataTable.CreateRow(new RowLayout()));
			customFormControlPage.ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, customFormControlPage.Title, null, saveLayoutFirst: true);
		}

		private static void InsertRowCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			e.CanExecute = customFormControlPage.DataSource != null;
		}

		private static void DeleteRowCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			CustomFormDataTable customFormDataTable = customFormControlPage.DataSource as CustomFormDataTable;
			List<DataRow> list = customFormControlPage.SelectedRows.ToList();
			bool flag = false;
			foreach (DataRow item in list)
			{
				if (!customFormDataTable.Rows.Contains(item))
				{
					continue;
				}
				if (!flag)
				{
					if (MMMessageBoxResult.Yes != MMMessageBox.Show(System.Windows.Application.Current.MainWindow, ApwnResources.Confirm_To_Delete_The_Selected_Row, ApwnResources.Delete_Row, MMMessageBoxButton.YesNo, MMMessageBoxImage.Information, showHelpButton: false, 2))
					{
						return;
					}
					flag = true;
				}
				if (flag)
				{
					customFormDataTable.Rows.Remove(item);
				}
			}
			customFormControlPage.ParentFormControl.PublishCustomFormChangedEvent(CustomFormChangeAction.RowsChanged, customFormControlPage.Title, null, saveLayoutFirst: true);
			customFormControlPage.Focus();
		}

		private static void DeleteRowCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			e.CanExecute = customFormControlPage.SelectedRows.Count() > 0;
		}

		private static void ClearValueCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			_ = customFormControlPage.CurrentCell;
			customFormControlPage.CurrentCell.Data?.ClearValue();
		}

		private static void ClearValueCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			CustomFormControlPage customFormControlPage = sender as CustomFormControlPage;
			_ = customFormControlPage.CurrentCell;
			IDataCell data = customFormControlPage.CurrentCell.Data;
			if (data != null && ((CustomFormDataColumn)data.Column).ColumnType != CustomFormColumnType.Units)
			{
				e.CanExecute = data.HasValue && !data.IsReadOnly;
			}
		}

		private static void FindVariablesCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			if (sender is CustomFormControlPage customFormControlPage)
			{
				customFormControlPage.ParentFormControl.FindVariables();
			}
		}

		private static void FindVariablesCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = true;
		}
	}
	public class CustomFormDataTable : DataTable
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class RowPathSelectors
		{
			public static readonly RowPathSelectors Instance = new RowPathSelectors();
			public static Func<DataRow, string> ForData;
			public static Func<DataRow, string> ForPaths;

			internal string GetDataPath(DataRow row)
			{
				return ((CustomFormDataRow)row).InitialRowLayout.Path;
			}

			internal string GetExistingPath(DataRow row)
			{
				return ((CustomFormDataRow)row).InitialRowLayout.Path;
			}
		}

		[CompilerGenerated]
		private sealed class FixAndFilterExistingDatasEnumerator : IEnumerable<ClipboardCellDataTuple>, IEnumerable, IEnumerator<ClipboardCellDataTuple>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private ClipboardCellDataTuple iteratorCurrentValue;

			private int iteratorInitialThreadId;

			public CustomFormDataTable iteratorOwner;

			private IEnumerable<ClipboardCellDataTuple> datas;

			public IEnumerable<ClipboardCellDataTuple> initialDatas;

			private List<string> existingPathsListState2;

			private IEnumerator<ClipboardCellDataTuple> iteratorLocal2;

			ClipboardCellDataTuple IEnumerator<ClipboardCellDataTuple>.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			[DebuggerHidden]
			public FixAndFilterExistingDatasEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				iteratorInitialThreadId = Environment.CurrentManagedThreadId;
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
						RunFinally1();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					CustomFormDataTable customFormDataTable = iteratorOwner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true;
							return false;
						}
						iteratorState = -3;
					}
					else
					{
						iteratorState = -1;
						IEnumerable<string> source = customFormDataTable.Rows.Select(RowPathSelectors.ForData ?? (RowPathSelectors.ForData = RowPathSelectors.Instance.GetDataPath));
						existingPathsListState2 = source.ToList();
						if (datas == null)
						{
							goto IL_020d;
						}
						iteratorLocal2 = datas.GetEnumerator();
						iteratorState = -3;
					}
					while (iteratorLocal2.MoveNext())
					{
						ClipboardCellDataTuple current = iteratorLocal2.Current;
						string text = current.Path;
						if (!text.EndsWith("</metadata>", StringComparison.InvariantCultureIgnoreCase))
						{
							if (text.StartsWith("cxs:"))
							{
								text = text.Substring(4);
							}
							if (!text.StartsWith("Top.appModel.EO Flowsheet.") && !text.Contains("Top.appModel.AllRecords.") && !text.Contains("Top.appModel.Sizing and Costing.") && !text.Contains(".Engine.Variables.") && !text.Contains(".Engine.Parameters.") && !text.Contains(".Engine.Ports.") && !text.Contains(".Engine.Equations.") && text.Contains("\""))
							{
								text = text.Replace("\"", string.Empty);
							}
							if (text.EndsWith(".Input.PSDID") || text.EndsWith(".Input.SPEC_OVOPT"))
							{
								CxsNode cxsNodeByPath = customFormDataTable.GetCxsNodeByPath(text);
								if (cxsNodeByPath != null && cxsNodeByPath.ChildNodes != null && cxsNodeByPath.ChildNodes.Count == 1)
								{
									text = cxsNodeByPath.ChildNodes[0].Path;
								}
							}
						}
						if (!existingPathsListState2.Contains(text))
						{
							existingPathsListState2.Add(text);
							iteratorCurrentValue = new ClipboardCellDataTuple(current.Name, text, current.RowIndex, current.ColumnIndex);
							iteratorState = 1;
							completedNormally = true;
							return true;
						}
					}
					RunFinally1();
					iteratorLocal2 = null;
					goto IL_020d;
					IL_020d:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void RunFinally1()
			{
				iteratorState = -1;
				if (iteratorLocal2 != null)
				{
					iteratorLocal2.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<ClipboardCellDataTuple> IEnumerable<ClipboardCellDataTuple>.GetEnumerator()
			{
				FixAndFilterExistingDatasEnumerator enumerator;
				if (iteratorState == -2 && iteratorInitialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new FixAndFilterExistingDatasEnumerator(0)
					{
						iteratorOwner = iteratorOwner
					};
				}
				enumerator.datas = initialDatas;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<ClipboardCellDataTuple>)this).GetEnumerator();
			}
		}

		[CompilerGenerated]
		private sealed class FixAndFilterExistingPathsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private string iteratorCurrentValue;

			private int iteratorInitialThreadId;

			public CustomFormDataTable iteratorOwner;

			private IEnumerable<string> pathsToAdd;

			public IEnumerable<string> initialPathsToAdd;

			private List<string> existingPathsListState2;

			private IEnumerator<string> iteratorLocal2;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			[DebuggerHidden]
			public FixAndFilterExistingPathsEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				iteratorInitialThreadId = Environment.CurrentManagedThreadId;
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
						RunFinally1();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					CustomFormDataTable customFormDataTable = iteratorOwner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true;
							return false;
						}
						iteratorState = -3;
					}
					else
					{
						iteratorState = -1;
						IEnumerable<string> source = customFormDataTable.Rows.Select(RowPathSelectors.ForPaths ?? (RowPathSelectors.ForPaths = RowPathSelectors.Instance.GetExistingPath));
						existingPathsListState2 = source.ToList();
						if (pathsToAdd == null)
						{
							goto IL_01d8;
						}
						iteratorLocal2 = pathsToAdd.GetEnumerator();
						iteratorState = -3;
					}
					while (iteratorLocal2.MoveNext())
					{
						string text = iteratorLocal2.Current;
						if (text.StartsWith("cxs:"))
						{
							text = text.Substring(4);
						}
						if (!text.StartsWith("Top.appModel.EO Flowsheet.") && !text.Contains("Top.appModel.AllRecords.") && !text.Contains("Top.appModel.Sizing and Costing.") && !text.Contains(".Engine.Variables.") && !text.Contains(".Engine.Parameters.") && !text.Contains(".Engine.Ports.") && !text.Contains(".Engine.Equations.") && text.Contains("\""))
						{
							text = text.Replace("\"", string.Empty);
						}
						if (text.EndsWith(".Input.PSDID") || text.EndsWith(".Input.SPEC_OVOPT"))
						{
							CxsNode cxsNodeByPath = customFormDataTable.GetCxsNodeByPath(text);
							if (cxsNodeByPath != null && cxsNodeByPath.ChildNodes != null && cxsNodeByPath.ChildNodes.Count == 1)
							{
								text = cxsNodeByPath.ChildNodes[0].Path;
							}
						}
						if (!existingPathsListState2.Contains(text))
						{
							existingPathsListState2.Add(text);
							iteratorCurrentValue = text;
							iteratorState = 1;
							completedNormally = true;
							return true;
						}
					}
					RunFinally1();
					iteratorLocal2 = null;
					goto IL_01d8;
					IL_01d8:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler disposes the iterator on exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void RunFinally1()
			{
				iteratorState = -1;
				if (iteratorLocal2 != null)
				{
					iteratorLocal2.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<string> IEnumerable<string>.GetEnumerator()
			{
				FixAndFilterExistingPathsEnumerator enumerator;
				if (iteratorState == -2 && iteratorInitialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new FixAndFilterExistingPathsEnumerator(0)
					{
						iteratorOwner = iteratorOwner
					};
				}
				enumerator.pathsToAdd = initialPathsToAdd;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private const double DefaultColumnWidth = 120.0;

		public CustomFormControlPage ParentPage { get; private set; }

		public CustomFormDataTable(CustomFormControlPage parentPage)
		{
			if (parentPage == null)
			{
				throw new ArgumentNullException("parentPage");
			}
			ParentPage = parentPage;
			InitializeColumns();
		}

		private void InitializeColumns()
		{
			List<DataColumn> list = new List<DataColumn>
			{
				CreateDataColumn(CustomFormColumnType.Name, isReadOnly: false, isFrozen: true, canChangeVisibility: false, typeof(string), 120.0),
				CreateDataColumn(CustomFormColumnType.Units, isReadOnly: false, isFrozen: false, canChangeVisibility: true, typeof(string), 80.0),
				CreateDataColumn(CustomFormColumnType.Value, isReadOnly: false, isFrozen: false, canChangeVisibility: false, null, 90.0),
				CreateDataColumn(CustomFormColumnType.Status, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 80.0),
				CreateDataColumn(CustomFormColumnType.Container, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 70.0),
				CreateDataColumn(CustomFormColumnType.ContainerCategory, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 120.0),
				CreateDataColumn(CustomFormColumnType.ContainerType, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 90.0),
				CreateDataColumn(CustomFormColumnType.Lower, isReadOnly: true, isFrozen: false, canChangeVisibility: true, null, 90.0),
				CreateDataColumn(CustomFormColumnType.Upper, isReadOnly: true, isFrozen: false, canChangeVisibility: true, null, 90.0),
				CreateDataColumn(CustomFormColumnType.Path, isReadOnly: false, isFrozen: false, canChangeVisibility: true, typeof(string), 200.0),
				CreateDataColumn(CustomFormColumnType.VariableName, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 90.0),
				CreateDataColumn(CustomFormColumnType.ObjectName, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 80.0),
				CreateDataColumn(CustomFormColumnType.ObjectType, isReadOnly: true, isFrozen: false, canChangeVisibility: true, typeof(string), 80.0),
				CreateDataColumn(CustomFormColumnType.ObjectID1, isReadOnly: true, isFrozen: false, canChangeVisibility: true, null, 70.0),
				CreateDataColumn(CustomFormColumnType.ObjectID2, isReadOnly: true, isFrozen: false, canChangeVisibility: true, null, 70.0),
				CreateDataColumn(CustomFormColumnType.ObjectID3, isReadOnly: true, isFrozen: false, canChangeVisibility: true, null, 70.0)
			};
			base.Columns = new ReadOnlyCollection<DataColumn>(list);
		}

		private DataColumn CreateDataColumn(CustomFormColumnType columnType, bool isReadOnly, bool isFrozen, bool canChangeVisibility, Type defaultDataType = null, double? initialWidth = 120.0)
		{
			return new CustomFormDataColumn(columnType)
			{
				IsReadOnly = isReadOnly,
				IsFrozen = isFrozen,
				CanChangeVisibility = canChangeVisibility,
				DefaultDataType = defaultDataType,
				Width = initialWidth,
				CanSorting = false
			};
		}

		public void LoadLayout(TabLayout layout)
		{
			if (layout == null)
			{
				throw new ArgumentNullException("layout");
			}
			foreach (CustomFormDataColumn column in base.Columns)
			{
				if (layout.Columns.FirstOrDefault((ColumnLayout x) => string.Equals(x.AttributeName, column.ColumnAttribute, StringComparison.OrdinalIgnoreCase)) == null)
				{
					column.Visibility = Visibility.Collapsed;
				}
				else
				{
					column.Visibility = Visibility.Visible;
				}
			}
			base.Rows.Clear();
			for (int num = 0; num < layout.Rows.Count; num++)
			{
				DataRow item = CreateRow(layout.Rows[num]);
				base.Rows.Add(item);
			}
		}

		internal IList<DataRow> InsertVariables(IList<ClipboardCellDataTuple> datas, int? targetRowIndex = null)
		{
			if (datas == null)
			{
				throw new ArgumentNullException("datas");
			}
			if (datas.Count == 0)
			{
				return null;
			}
			int num = 0;
			if (targetRowIndex.HasValue)
			{
				num = ((targetRowIndex.Value >= 0) ? targetRowIndex.Value : base.Rows.Count);
			}
			else if (ParentPage.HasSelection)
			{
				DataCellInfo dataCellInfo = ParentPage.TotalOrderedSelectedCells.LastOrDefault();
				num = base.Rows.IndexOf(dataCellInfo.Row) + 1;
			}
			else
			{
				num = base.Rows.Count;
			}
			List<DataRow> list = new List<DataRow>();
			foreach (ClipboardCellDataTuple item in FixAndFilterExistingDatas(datas))
			{
				DataRow dataRow = null;
				string resolvedCxsPath;
				StreamReportExtraPropertyInfo srepInfo = FindExtraStreamReportProperty(item, out resolvedCxsPath);
				dataRow = (string.IsNullOrWhiteSpace(item.Name) ? CreateRow(new RowLayout
				{
					Path = resolvedCxsPath,
					SrepInfo = srepInfo
				}) : CreateRow(new RowLayout
				{
					Name = item.Name,
					Path = resolvedCxsPath,
					SrepInfo = srepInfo
				}));
				if (base.Rows.Count > num)
				{
					base.Rows.Insert(num, dataRow);
				}
				else
				{
					base.Rows.Add(dataRow);
				}
				list.Add(dataRow);
				num++;
			}
			return list;
		}

		private static StreamReportExtraPropertyInfo FindExtraStreamReportProperty(ClipboardCellDataTuple ccdt, out string resolvedCxsPath)
		{
			if (ccdt != null && StreamReportCxsPathPreprocessor.IsComplexStreamReportCxsPath(ccdt.Path))
			{
				StreamReportComplexCxsPathInfo streamReportComplexCxsPathInfo = StreamReportCxsPathPreprocessor.TryParse(ccdt.Path);
				if (streamReportComplexCxsPathInfo != null)
				{
					resolvedCxsPath = streamReportComplexCxsPathInfo.CxsPath;
					return new StreamReportExtraPropertyInfo
					{
						Stream = streamReportComplexCxsPathInfo.StreamId,
						Template = streamReportComplexCxsPathInfo.Property
					};
				}
			}
			resolvedCxsPath = FixResolveddCxsPath(ccdt?.Path);
			return null;
			static string FixResolveddCxsPath(string internalFinalPath)
			{
				if (!string.IsNullOrEmpty(internalFinalPath) && internalFinalPath.StartsWith("cxs:", StringComparison.InvariantCultureIgnoreCase))
				{
					return internalFinalPath.Substring(4);
				}
				return internalFinalPath;
			}
		}

		public IList<DataRow> InsertVariablesByPaths(IList<string> paths, IDictionary<string, string> dicPathToName = null, int? targetRowIndex = null)
		{
			if (paths == null)
			{
				throw new ArgumentNullException("paths");
			}
			if (paths.Count == 0)
			{
				return null;
			}
			int num = 0;
			if (targetRowIndex.HasValue)
			{
				num = ((targetRowIndex.Value >= 0) ? targetRowIndex.Value : base.Rows.Count);
			}
			else if (ParentPage.HasSelection)
			{
				DataCellInfo dataCellInfo = ParentPage.TotalOrderedSelectedCells.LastOrDefault();
				num = base.Rows.IndexOf(dataCellInfo.Row) + 1;
			}
			else
			{
				num = base.Rows.Count;
			}
			List<string> list = new List<string>();
			List<DataRow> list2 = new List<DataRow>();
			_ = string.Empty;
			int num2 = 0;
			foreach (string item in FixAndFilterExistingPaths(paths))
			{
				DataRow dataRow = null;
				dataRow = ((dicPathToName == null || !dicPathToName.Keys.Contains(paths[num2])) ? CreateRow(new RowLayout
				{
					Path = item
				}) : CreateRow(new RowLayout
				{
					Name = dicPathToName[paths[num2]],
					Path = item
				}));
				if (base.Rows.Count > num)
				{
					base.Rows.Insert(num, dataRow);
				}
				else
				{
					base.Rows.Add(dataRow);
				}
				list2.Add(dataRow);
				num++;
				list.Add(paths[num2].TrimStart("cxs:".ToCharArray()));
				num2++;
			}
			return list2;
		}

		private CxsNode GetCxsNodeByPath(string strPath)
		{
			if (string.IsNullOrEmpty(strPath))
			{
				return null;
			}
			return ParentPage.ParentFormControl.CxsCase.ResolveNode(strPath);
		}

		[IteratorStateMachine(typeof(FixAndFilterExistingDatasEnumerator))]
		internal IEnumerable<ClipboardCellDataTuple> FixAndFilterExistingDatas(IEnumerable<ClipboardCellDataTuple> datas)
		{
			return new FixAndFilterExistingDatasEnumerator(-2)
			{
				iteratorOwner = this,
				initialDatas = datas
			};
		}

		[IteratorStateMachine(typeof(FixAndFilterExistingPathsEnumerator))]
		public IEnumerable<string> FixAndFilterExistingPaths(IEnumerable<string> pathsToAdd)
		{
			return new FixAndFilterExistingPathsEnumerator(-2)
			{
				iteratorOwner = this,
				initialPathsToAdd = pathsToAdd
			};
		}

		public string AdjustRowName(CustomFormDataRow row, CustomFormDataColumn nameColumn, string nameToUse)
		{
			int testingTo = base.Rows.IndexOf(row);
			if (!IsNameOccupied(nameToUse, testingTo))
			{
				return nameToUse;
			}
			for (int i = 1; i < int.MaxValue; i++)
			{
				string text = $"{nameToUse}.{i}";
				if (!IsNameOccupied(text, testingTo))
				{
					return text;
				}
			}
			return nameToUse;
			bool IsNameOccupied(string nameToTry, int num)
			{
				for (int j = 0; j < num; j++)
				{
					IDataCell dataCell = base.Rows[j][nameColumn];
					if (dataCell != null && string.Equals(dataCell.Value as string, nameToTry, StringComparison.CurrentCulture))
					{
						return true;
					}
				}
				return false;
			}
		}

		protected override IDataCell OnCellValueQueried(DataRow row, DataColumn column)
		{
			CustomFormDataRow customFormDataRow = row as CustomFormDataRow;
			CustomFormDataColumn customFormDataColumn = column as CustomFormDataColumn;
			bool flag = !string.IsNullOrEmpty(customFormDataRow.InitialRowLayout.Path);
			IDataCell dataCell = null;
			if (customFormDataRow.IsActive)
			{
				IDataCell dataCell2 = DataHelper.CreateDataCellObject(this, customFormDataRow.CxsNode, customFormDataRow, customFormDataColumn);
				if (dataCell2 != null && (customFormDataColumn.ColumnType == CustomFormColumnType.Value || customFormDataColumn.ColumnType == CustomFormColumnType.Units))
				{
					dataCell2.Foreground = DataHelper.GetForegroundForNode(customFormDataRow.CxsNode);
					dataCell2.FontStyle = DataHelper.GetFontStyleForNode(customFormDataRow.CxsNode);
					dataCell2.FontWeight = DataHelper.GetFontWeightForNode(customFormDataRow.CxsNode);
				}
				return dataCell2;
			}
			if (customFormDataColumn.ColumnType == CustomFormColumnType.Name)
			{
				if (!flag)
				{
					return new DataCellText(customFormDataRow.InitialRowLayout.Name);
				}
				dataCell = new DataCellText(customFormDataRow.InitialRowLayout.Name);
			}
			else if (customFormDataColumn.ColumnType == CustomFormColumnType.Path)
			{
				dataCell = new DataCellText(customFormDataRow.InitialRowLayout.Path);
			}
			else if (flag)
			{
				dataCell = new DataCellText(string.Empty);
			}
			if (dataCell != null)
			{
				if (dataCell.Value as string == customFormDataRow.InitialRowLayout.Path)
				{
					dataCell.Foreground = Brushes.Red;
					dataCell.Background = Brushes.LightGray;
					dataCell.IsReadOnly = false;
				}
				else
				{
					dataCell.Background = Brushes.LightGray;
					dataCell.IsReadOnly = true;
				}
				return dataCell;
			}
			return base.OnCellValueQueried(row, column);
		}

		protected override void OnCellValueChanged(IDataCell cell, object oldValue, object newValue)
		{
			CustomFormControl customFormControl = ParentPage?.ParentFormControl;
			if (customFormControl == null || !(cell.Row is CustomFormDataRow customFormDataRow) || !(cell.Column is CustomFormDataColumn customFormDataColumn))
			{
				return;
			}
			if (customFormDataColumn.ColumnType == CustomFormColumnType.Name)
			{
				customFormDataRow.InitialRowLayout.Name = newValue as string;
				customFormControl.SetDirtyFlag();
				customFormControl.PublishCustomFormRepairedEvent(saveLayout: true);
				return;
			}
			if (customFormDataColumn.ColumnType == CustomFormColumnType.Path)
			{
				customFormDataRow.InitialRowLayout.Path = newValue as string;
				customFormControl.PublishCustomFormRepairedEvent(saveLayout: true);
				return;
			}
			if (customFormDataColumn.ColumnType == CustomFormColumnType.Units)
			{
				if (DataHelper.UpdateAttributeValue(ParentPage.ParentFormControl.UnityContainer, customFormDataRow.CxsNode, CustomFormColumnType.Units, newValue))
				{
					customFormDataRow.InitialRowLayout.Units = newValue as string;
					customFormControl.PublishDataChangedEvent();
				}
				else
				{
					DataHelper.UpdateAttributeValue(ParentPage.ParentFormControl.UnityContainer, customFormDataRow.CxsNode, CustomFormColumnType.Units, oldValue);
				}
				return;
			}
			if (customFormDataRow.CxsNode != null && cell.Column != base.Columns[0] && (customFormDataRow.IsSpecialPathNode || (customFormDataRow.IHNodeEntry != null && customFormDataRow.IHNodeEntry != DBNull.Value)))
			{
				DataHelper.UpdateAttributeValue(ParentPage.ParentFormControl.UnityContainer, customFormDataRow.CxsNode, customFormDataColumn.ColumnType, newValue);
				customFormControl.PublishDataChangedEvent();
			}
			base.OnCellValueChanged(cell, oldValue, newValue);
		}

		public void UpdateData()
		{
			ParentPage?.ParentFormControl?.CxsCase?.RefreshAllNodes();
			foreach (CustomFormDataRow row in base.Rows)
			{
				row.RefreshData();
			}
		}

		public void SaveTabLayout(TabLayout layout)
		{
			if (layout == null)
			{
				throw new ArgumentNullException("layout");
			}
			layout.Columns.Clear();
			foreach (CustomFormDataColumn column in base.Columns)
			{
				if (column.Visibility == Visibility.Visible)
				{
					layout.Columns.Add(new ColumnLayout
					{
						AttributeName = column.ColumnAttribute
					});
				}
			}
			layout.Rows.Clear();
			DataColumn index = base.Columns[0];
			DataColumn index2 = base.Columns[1];
			_ = base.Columns[2];
			foreach (CustomFormDataRow row in base.Rows)
			{
				RowLayout item = new RowLayout
				{
					Name = (row.InitialRowLayout.Name ?? row[index].ValueAsString),
					Units = (row.InitialRowLayout.Units ?? row[index2]?.ValueAsString),
					Path = row.InitialRowLayout.Path,
					SrepInfo = row.InitialRowLayout.SrepInfo
				};
				layout.Rows.Add(item);
			}
		}

		public DataRow CreateRow(RowLayout rowLayout)
		{
			if (rowLayout == null)
			{
				throw new ArgumentNullException("rowLayout");
			}
			return new CustomFormDataRow(this, rowLayout);
		}

		public CxsNode GetCxsNodeAtRow(DataRow row)
		{
			if (row is CustomFormDataRow customFormDataRow)
			{
				return customFormDataRow.CxsNode;
			}
			return null;
		}

		public object ResolveHappNode(string strPath, CxsNode objCxsNode = null)
		{
			if (string.IsNullOrEmpty(strPath))
			{
				return null;
			}
			object obj = null;
			CxsCase cxsCase = ParentPage.ParentFormControl.CxsCase;
			try
			{
				obj = cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "HappNode", CustomFormDataRow.ParseInitialPath(cxsCase, strPath));
				if ((obj == null || obj == DBNull.Value) && !string.IsNullOrEmpty(strPath) && strPath.Contains(".Table."))
				{
					string text = CustomFormDataRow.ParseInitialPath(cxsCase, strPath);
					int num = -1;
					while (!string.IsNullOrEmpty(text) && !text.EndsWith(".Table"))
					{
						num = text.LastIndexOf(".");
						if (num > 0)
						{
							text = text.Substring(0, num);
						}
					}
					obj = cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "HappNode", text);
				}
				if ((obj == null || obj == DBNull.Value) && objCxsNode != null)
				{
					int num2 = strPath.LastIndexOf('#');
					string empty = string.Empty;
					_ = string.Empty;
					int result = -1;
					if (num2 != -1)
					{
						empty = strPath.Substring(0, num2 - 1);
						if (int.TryParse(strPath.Substring(num2 + 1), out result) && result != -1)
						{
							string[] array = CxsConverter.ValueToStringArray(cxsCase.BatchGet(empty, "child_ids", null));
							if (array != null && array.Count() > result)
							{
								string text2 = array[result];
								if (!string.IsNullOrEmpty(text2))
								{
									string text3 = objCxsNode.ParentPath + "." + text2;
									obj = cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "HappNode", text3);
								}
							}
						}
					}
					else
					{
						string parentPath = objCxsNode.ParentPath;
						obj = cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "HappNode", parentPath);
					}
				}
			}
			catch
			{
				return objCxsNode;
			}
			return obj;
		}
	}
	public enum CustomFormColumnType
	{
		Name,
		Units,
		Value,
		Status,
		Container,
		ContainerCategory,
		ContainerType,
		Lower,
		Upper,
		Path,
		VariableName,
		ObjectName,
		ObjectType,
		ObjectID1,
		ObjectID2,
		ObjectID3
	}
	public class CustomFormDataColumn : DataColumn
	{
		public CustomFormColumnType ColumnType { get; }

		public string ColumnAttribute => ColumnType switch
		{
			CustomFormColumnType.Name => "name", 
			CustomFormColumnType.Units => "units", 
			CustomFormColumnType.Value => "value", 
			CustomFormColumnType.Status => "status", 
			CustomFormColumnType.Container => "container", 
			CustomFormColumnType.ContainerCategory => "container_category", 
			CustomFormColumnType.ContainerType => "container_type", 
			CustomFormColumnType.Lower => "lower_limit", 
			CustomFormColumnType.Upper => "upper_limit", 
			CustomFormColumnType.Path => "path", 
			CustomFormColumnType.VariableName => "variable name", 
			CustomFormColumnType.ObjectName => "object name", 
			CustomFormColumnType.ObjectType => "object type", 
			CustomFormColumnType.ObjectID1 => "object id1", 
			CustomFormColumnType.ObjectID2 => "object id2", 
			CustomFormColumnType.ObjectID3 => "object id3", 
			_ => null, 
		};

		public CustomFormDataColumn(CustomFormColumnType columnType)
		{
			ColumnType = columnType;
			base.Header = GetDisplayedText(columnType);
		}

		private static string GetDisplayedText(CustomFormColumnType columnType)
		{
			return columnType switch
			{
				CustomFormColumnType.Name => CustomFormsResources.ColumnText_Name, 
				CustomFormColumnType.Units => CustomFormsResources.ColumnText_Units, 
				CustomFormColumnType.Value => CustomFormsResources.ColumnText_Value, 
				CustomFormColumnType.Status => CustomFormsResources.ColumnText_Status, 
				CustomFormColumnType.Container => CustomFormsResources.ColumnText_Container, 
				CustomFormColumnType.ContainerCategory => CustomFormsResources.ColumnText_ContainerCategory, 
				CustomFormColumnType.ContainerType => CustomFormsResources.ColumnText_ContainerType, 
				CustomFormColumnType.Lower => CustomFormsResources.ColumnText_Lower, 
				CustomFormColumnType.Upper => CustomFormsResources.ColumnText_Upper, 
				CustomFormColumnType.Path => CustomFormsResources.ColumnText_Path, 
				CustomFormColumnType.VariableName => CustomFormsResources.ColumnText_VariableName, 
				CustomFormColumnType.ObjectName => CustomFormsResources.ColumnText_ObjectName, 
				CustomFormColumnType.ObjectType => CustomFormsResources.ColumnText_ObjectType, 
				CustomFormColumnType.ObjectID1 => CustomFormsResources.ColumnText_ObjectID1, 
				CustomFormColumnType.ObjectID2 => CustomFormsResources.ColumnText_ObjectID2, 
				CustomFormColumnType.ObjectID3 => CustomFormsResources.ColumnText_ObjectID3, 
				_ => null, 
			};
		}
	}
	public class CustomFormDataRow : DataRow
	{
		private const string EOFlowsheetSegmentInPath = "!EO Flowsheet!";

		private const string EconomicVariableNode = "Top.appModel.AllRecords.";

		private const string EconomicVariableNode2 = "Top.appModel.Sizing and Costing.";

		private const string ACMVariableNode = ".Engine.Variables.";

		private const string ACMParamtersNode = ".Engine.Parameters.";

		private const string ACMEquationsNode = ".Engine.Equations.";

		private const string CASharedData = ".SharedData.";

		private CxsNode _cxsNode;

		private object m_IHNodeEntry;

		private IEnumerable<string> _unitsList;

		public bool IsEOVariable
		{
			get
			{
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && (InitialRowLayout.Path.StartsWith("!EO Flowsheet!") || InitialRowLayout.Path.StartsWith("Top.appModel.EO Flowsheet.")))
				{
					return true;
				}
				return false;
			}
		}

		public bool IsEconomicVariable
		{
			get
			{
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && (InitialRowLayout.Path.StartsWith("Top.appModel.AllRecords.") || InitialRowLayout.Path.StartsWith("Top.appModel.Sizing and Costing.")))
				{
					return true;
				}
				return false;
			}
		}

		public bool IsSharedData
		{
			get
			{
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && InitialRowLayout.Path.Contains(".SharedData."))
				{
					return true;
				}
				return false;
			}
		}

		public bool IsSpecialPathNode
		{
			get
			{
				if (IsEOVariable || IsEconomicVariable)
				{
					return true;
				}
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && (InitialRowLayout.Path.Contains(".Engine.Variables.") || InitialRowLayout.Path.Contains(".Engine.Parameters.") || InitialRowLayout.Path.Contains(".Engine.Equations.")))
				{
					return true;
				}
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && InitialRowLayout.Path.Contains(".Custom.Reactions."))
				{
					return true;
				}
				if (!string.IsNullOrEmpty(InitialRowLayout.Path) && InitialRowLayout.Path.Contains(".SharedData."))
				{
					return true;
				}
				return false;
			}
		}

		public bool IsActive
		{
			get
			{
				if (CxsNode != null)
				{
					if (!IsSpecialPathNode)
					{
						if (IHNodeEntry != null)
						{
							return IHNodeEntry != DBNull.Value;
						}
						return false;
					}
					return true;
				}
				return false;
			}
		}

		public RowLayout InitialRowLayout { get; private set; }

		public CxsNode CxsNode
		{
			get
			{
				if (_cxsNode == null && !string.IsNullOrEmpty(InitialRowLayout.Path))
				{
					CxsCase cxsCase = (base.DataTable as CustomFormDataTable).ParentPage.ParentFormControl.CxsCase;
					_cxsNode = cxsCase.ResolveNode(ParseInitialPath(cxsCase, InitialRowLayout.Path), new CxsNodeRefreshOptions(new string[1] { "option_list" }, null));
				}
				return _cxsNode;
			}
		}

		public object IHNodeEntry
		{
			get
			{
				if ((m_IHNodeEntry == null || m_IHNodeEntry == DBNull.Value) && !string.IsNullOrEmpty(InitialRowLayout.Path))
				{
					CustomFormDataTable customFormDataTable = base.DataTable as CustomFormDataTable;
					_ = customFormDataTable.ParentPage.ParentFormControl.CxsCase;
					try
					{
						m_IHNodeEntry = customFormDataTable.ResolveHappNode(InitialRowLayout.Path, CxsNode);
					}
					catch
					{
						return CxsNode;
					}
				}
				return m_IHNodeEntry;
			}
		}

		public IEnumerable<string> UnitsList
		{
			get
			{
				if (_unitsList == null)
				{
					_unitsList = GenerateUnitsList();
				}
				return _unitsList;
				IEnumerable<string> GenerateUnitsList()
				{
					CxsNode cxsNode = CxsNode;
					if (cxsNode != null && cxsNode.UnitsList?.Any() == true)
					{
						return CxsNode.UnitsList;
					}
					return CxsConverter.ValueToStringArray((base.DataTable as CustomFormDataTable).ParentPage.ParentFormControl.CxsCase.BatchGet(InitialRowLayout.Path, "uom_options"));
				}
			}
		}

		public CustomFormDataRow(CustomFormDataTable dataTable, RowLayout rowLayout)
			: base(dataTable)
		{
			InitialRowLayout = rowLayout;
		}

		public void RefreshData()
		{
			_cxsNode = null;
			ClearData();
			RaiseIndexerPropertyChanged();
		}

		public string GetCxsPathForCopy()
		{
			string text = InitialRowLayout?.GetCxsPathForCopy();
			if (!string.IsNullOrWhiteSpace(text))
			{
				return ParseInitialPath((base.DataTable as CustomFormDataTable).ParentPage.ParentFormControl.CxsCase, text);
			}
			return text;
		}

		public string GetDisplayedUnit()
		{
			CxsCase cxsCase = (base.DataTable as CustomFormDataTable).ParentPage.ParentFormControl.CxsCase;
			if (DataHelper.IsCalculatorDefineVariableSheetValueVariable(InitialRowLayout.Path))
			{
				string calculatorDefineVariableSheetValueVariableUnit = DataHelper.GetCalculatorDefineVariableSheetValueVariableUnit(cxsCase, InitialRowLayout.Path);
				if (!string.IsNullOrEmpty(calculatorDefineVariableSheetValueVariableUnit))
				{
					return calculatorDefineVariableSheetValueVariableUnit;
				}
			}
			if (string.IsNullOrEmpty(CxsNode?.Units))
			{
				return CxsConverter.ValueToString(cxsCase.BatchGet(InitialRowLayout.Path, "uom", null));
			}
			return null;
		}

		public static string ParseInitialPath(CxsCase cxsCase, string initialPath)
		{
			if (!initialPath.StartsWith("!EO Flowsheet!"))
			{
				return initialPath;
			}
			string[] array = initialPath.Substring("!EO Flowsheet!".Length).Split('.');
			string text = "Top.appModel.EO Flowsheet.appModel";
			for (int i = 0; i < array.Length; i++)
			{
				string text2 = text + ".Blocks." + array[i];
				string text3 = text + ".Variables.\"" + ConcatenateStrings(array, i) + "\"";
				CxsVerificationResult[] array2 = cxsCase.VerifyPaths(new string[2] { text2, text3 });
				if (array2[0] == CxsVerificationResult.Valid)
				{
					text = text2;
				}
				else if (array2[1] == CxsVerificationResult.Valid)
				{
					return text3;
				}
			}
			if (initialPath != "Top.appModel.EO Flowsheet.appModel" && text == "Top.appModel.EO Flowsheet.appModel")
			{
				return initialPath;
			}
			return text;
		}

		private static string ConcatenateStrings(string[] segments, int startIndex)
		{
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = startIndex; i < segments.Length; i++)
			{
				if (i == startIndex)
				{
					stringBuilder.Append(segments[i]);
				}
				else
				{
					stringBuilder.Append('.').Append(segments[i]);
				}
			}
			return stringBuilder.ToString();
		}
	}
	public enum CustomFormChangeAction
	{
		TabAdded,
		TabRemmoved,
		TabRenamed,
		RowsChanged,
		ColumnsChanged
	}
	public class CustomFormChangedEventArgs : EventArgs
	{
		public string MainNodePath { get; private set; }

		public string TabName { get; private set; }

		public CustomFormChangeAction Action { get; private set; }

		public string OldTabName { get; set; }

		public CustomFormControl Source { get; private set; }

		public CustomFormChangedEventArgs(CustomFormControl source, string mainNodePath, string tabName, CustomFormChangeAction action)
		{
			Source = source;
			MainNodePath = mainNodePath;
			TabName = tabName;
			Action = action;
		}
	}
	public class CustomFormChangedEvent : RoutedCompositePresentationEvent<CustomFormChangedEventArgs>
	{
	}
	public class CustomFormGridControlColumnDisplayIndexChangedEventArgs : EventArgs
	{
		public string GridTabName { get; set; }

		public string ColumnHeader { get; set; }

		public int ColumnDisplayIndex { get; set; }

		public object CustomFormControl { get; set; }

		public object CustomFormControlPage { get; set; }
	}
	public class CustomFormGridControlColumnDisplayIndexChangedEvent : RoutedCompositePresentationEvent<CustomFormGridControlColumnDisplayIndexChangedEventArgs>
	{
	}
	public class CustomFormVariableRepairedEventArgs : EventArgs
	{
		public IEnumerable<string> UpdatedCustomFormNodePaths { get; }

		public CustomFormVariableRepairedEventArgs(IEnumerable<string> updatedCustomFormNodePaths)
		{
			UpdatedCustomFormNodePaths = updatedCustomFormNodePaths ?? throw new ArgumentNullException("updatedCustomFormNodePaths");
		}

		public bool ContainsCustomFormNode(string customFormNodePath)
		{
			if (!string.IsNullOrWhiteSpace(customFormNodePath))
			{
				return UpdatedCustomFormNodePaths.Any((string x) => string.Equals(ShortPath(x), ShortPath(customFormNodePath), StringComparison.InvariantCultureIgnoreCase));
			}
			return false;
		}

		private static string ShortPath(string path)
		{
			if (path.StartsWith("Top.AppModel.", StringComparison.InvariantCultureIgnoreCase))
			{
				return path.Substring("Top.AppModel.".Length);
			}
			if (path.StartsWith("Top.AppModelV8.", StringComparison.InvariantCultureIgnoreCase))
			{
				return path.Substring("Top.AppModelV8.".Length);
			}
			return path;
		}
	}
	public class CustomFormVariableRepairedEvent : RoutedCompositePresentationEvent<CustomFormVariableRepairedEventArgs>
	{
		public CustomFormVariableRepairedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
	[Module(ModuleName = "CustomFormsModule")]
	[ModuleDependency("AspenTech.AspenPlus.MMControls.MMControlsModule")]
	public class CustomFormsModule : MMFormsModuleBase
	{
		public static IUnityContainer SharedUnityContainer { get; private set; }

		public CustomFormsModule(IUnityContainer container)
			: base(container)
		{
			SharedUnityContainer = container;
		}
	}
	public class RowLayout
	{
		[DefaultValue(null)]
		public string Name { get; set; }

		[DefaultValue(null)]
		public string Path { get; set; }

		[DefaultValue(null)]
		public string Value { get; set; }

		[DefaultValue(null)]
		public string Units { get; set; }

		[DefaultValue(null)]
		public StreamReportExtraPropertyInfo SrepInfo { get; set; }

		public string GetCxsPathForCopy()
		{
			if (SrepInfo == null)
			{
				return Path;
			}
			return StreamReportClipboardHelper.ComposeSpecialStreamReportCxsPath(Path, SrepInfo.Stream, SrepInfo.Template);
		}

		public string Save(IDictionary<TemplatePropertyItem, int> streamReportPropertiesIndexes)
		{
			if (streamReportPropertiesIndexes == null)
			{
				throw new ArgumentNullException("streamReportPropertiesIndexes");
			}
			XElement xElement = new XElement("RowLayout");
			xElement.SetElementValue("Name", Name);
			xElement.SetElementValue("Path", Path);
			xElement.SetElementValue("Units", Units);
			if (SrepInfo != null)
			{
				XElement xElement2 = new XElement("SrepInfo");
				xElement2.Add(SrepInfo.Save(streamReportPropertiesIndexes));
				xElement.Add(xElement2);
			}
			return xElement.ToString(SaveOptions.DisableFormatting);
		}

		public static RowLayout TryParse(string text, IList<TemplatePropertyItem> streamReportProperties)
		{
			XElement xElement = CreateXElement(text);
			if (xElement != null)
			{
				StreamReportExtraPropertyInfo srepInfo = null;
				XElement xElement2 = xElement.Element("SrepInfo");
				if (xElement2 != null && xElement2.HasElements)
				{
					srepInfo = StreamReportExtraPropertyInfo.TryParse(xElement2.Elements().First(), streamReportProperties);
				}
				return new RowLayout
				{
					Name = (string)xElement.Element("Name"),
					Path = (string)xElement.Element("Path"),
					Units = (string)xElement.Element("Units"),
					SrepInfo = srepInfo
				};
			}
			return null;
		}

		public static XElement CreateXElement(string text)
		{
			if (!string.IsNullOrEmpty(text))
			{
				try
				{
					return XElement.Parse(text);
				}
				catch (Exception ex)
				{
					SystemEnvironment.Logger.Log(ex.Message, Category.Exception, Priority.High);
					return null;
				}
			}
			return null;
		}
	}
	public class ColumnLayout
	{
		public const string Attribute_Container = "container";

		public const string Attribute_ContainerCategory = "container_category";

		public const string Attribute_ContainerType = "container_type";

		public const string Attribute_Name = "name";

		public const string Attribute_Value = "value";

		public const string Attribute_Units = "units";

		public const string Attribute_Lower = "lower_limit";

		public const string Attribute_Upper = "upper_limit";

		public const string Attribute_Uom = "uom";

		public const string Attribute_Path = "path";

		public const string Attribute_Status = "status";

		public const string Attribute_VariableName = "variable name";

		public const string Attribute_ObjectName = "object name";

		public const string Attribute_ObjectType = "object type";

		public const string Attribute_ObjectID1 = "object id1";

		public const string Attribute_ObjectID2 = "object id2";

		public const string Attribute_ObjectID3 = "object id3";

		[DefaultValue(null)]
		public string AttributeName { get; set; }

		public static string GetDisplayedTextOfAttribute(string attribute)
		{
			return attribute switch
			{
				"container" => CustomFormsResources.ColumnText_Container, 
				"container_category" => CustomFormsResources.ColumnText_ContainerCategory, 
				"container_type" => CustomFormsResources.ColumnText_ContainerType, 
				"name" => CustomFormsResources.ColumnText_Name, 
				"value" => CustomFormsResources.ColumnText_Value, 
				"units" => CustomFormsResources.ColumnText_Units, 
				"lower_limit" => CustomFormsResources.ColumnText_Lower, 
				"upper_limit" => CustomFormsResources.ColumnText_Upper, 
				"path" => CustomFormsResources.ColumnText_Path, 
				"status" => CustomFormsResources.ColumnText_Status, 
				"variable name" => CustomFormsResources.ColumnText_VariableName, 
				"object name" => CustomFormsResources.ColumnText_ObjectName, 
				"object type" => CustomFormsResources.ColumnText_ObjectType, 
				"object id1" => CustomFormsResources.ColumnText_ObjectID1, 
				"object id2" => CustomFormsResources.ColumnText_ObjectID2, 
				"object id3" => CustomFormsResources.ColumnText_ObjectID3, 
				_ => attribute, 
			};
		}
	}
	public class TabLayout
	{
		[DefaultValue(null)]
		public string Name { get; set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IList<ColumnLayout> Columns { get; private set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IList<RowLayout> Rows { get; private set; }

		[DefaultValue(null)]
		public string GridSettings { get; set; }

		public TabLayout()
		{
			Columns = new List<ColumnLayout>();
			Rows = new List<RowLayout>();
		}

		public string Save()
		{
			XElement xElement = new XElement("TabLayout");
			xElement.SetElementValue("Name", Name);
			if (Columns.Count > 0)
			{
				StringBuilder stringBuilder = new StringBuilder();
				foreach (ColumnLayout column in Columns)
				{
					if (!string.IsNullOrEmpty(column.AttributeName))
					{
						stringBuilder.Append(column.AttributeName).Append(',');
					}
				}
				xElement.SetElementValue("Columns", stringBuilder.ToString());
			}
			if (Rows.Count > 0)
			{
				List<TemplatePropertyItem> list = new List<TemplatePropertyItem>();
				Dictionary<TemplatePropertyItem, int> dictionary = new Dictionary<TemplatePropertyItem, int>();
				foreach (RowLayout row in Rows)
				{
					TemplatePropertyItem template = row.SrepInfo?.Template;
					if (template != null && !list.Contains(template))
					{
						TemplatePropertyItem templatePropertyItem = list.Find((TemplatePropertyItem x) => x.HasSameOptions(template));
						if (templatePropertyItem == null)
						{
							list.Add(template);
							dictionary.Add(template, list.Count - 1);
						}
						else
						{
							dictionary[template] = list.IndexOf(templatePropertyItem);
						}
					}
				}
				if (list.Count > 0)
				{
					XElement xElement2 = new XElement("StreamReportProperties");
					foreach (TemplatePropertyItem item in list)
					{
						xElement2.Add(item.Save());
					}
					xElement.Add(xElement2);
				}
				XElement xElement3 = new XElement("Rows");
				foreach (RowLayout row2 in Rows)
				{
					xElement3.Add(new XElement("Row", row2.Save(dictionary)));
				}
				xElement.Add(xElement3);
			}
			xElement.SetElementValue("GridSettings", GridSettings);
			return xElement.ToString(SaveOptions.DisableFormatting);
		}

		public static TabLayout TryParse(string text)
		{
			XElement xElement = RowLayout.CreateXElement(text);
			if (xElement != null)
			{
				TabLayout tabLayout = new TabLayout
				{
					Name = (string)xElement.Element("Name"),
					GridSettings = (string)xElement.Element("GridSettings")
				};
				string text2 = (string)xElement.Element("Columns");
				if (!string.IsNullOrEmpty(text2))
				{
					string[] array = text2.Split(',');
					foreach (string text3 in array)
					{
						if (!string.IsNullOrEmpty(text3))
						{
							tabLayout.Columns.Add(new ColumnLayout
							{
								AttributeName = text3
							});
						}
					}
				}
				List<TemplatePropertyItem> list = new List<TemplatePropertyItem>();
				XElement xElement2 = xElement.Element("StreamReportProperties");
				if (xElement2 != null)
				{
					foreach (XElement item in xElement2.Elements())
					{
						TemplatePropertyItem templatePropertyItem = TemplatePropertyItem.Parse(item);
						if (templatePropertyItem != null)
						{
							list.Add(templatePropertyItem);
						}
					}
				}
				XElement xElement3 = xElement.Element("Rows");
				if (xElement3 != null)
				{
					foreach (XElement item2 in xElement3.Elements("Row"))
					{
						RowLayout rowLayout = RowLayout.TryParse((string)item2, list);
						if (rowLayout != null)
						{
							tabLayout.Rows.Add(rowLayout);
						}
					}
				}
				return tabLayout;
			}
			return null;
		}
	}
	public class FormLayout
	{
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IList<TabLayout> Tabs { get; private set; }

		public FormLayout()
		{
			Tabs = new List<TabLayout>();
		}

		public string Save()
		{
			XElement xElement = new XElement("FormLayout");
			foreach (TabLayout tab in Tabs)
			{
				xElement.Add(new XElement("Tab", tab.Save()));
			}
			return xElement.ToString(SaveOptions.DisableFormatting);
		}

		public static FormLayout TryParse(string text)
		{
			if (!string.IsNullOrEmpty(text))
			{
				if (!text.StartsWith("<FormLayout>", StringComparison.CurrentCultureIgnoreCase))
				{
					try
					{
						return XamlReader.Parse(text) as FormLayout;
					}
					catch (Exception ex)
					{
						SystemEnvironment.Logger.Log(ex.Message, Category.Exception, Priority.High);
						return null;
					}
				}
				XElement xElement = RowLayout.CreateXElement(text);
				if (xElement != null)
				{
					FormLayout formLayout = new FormLayout();
					{
						foreach (XElement item in xElement.Elements("Tab"))
						{
							TabLayout tabLayout = TabLayout.TryParse((string)item);
							if (tabLayout != null)
							{
								formLayout.Tabs.Add(tabLayout);
							}
						}
						return formLayout;
					}
				}
			}
			return null;
		}
	}
	public class StreamReportExtraPropertyInfo
	{
		public string Stream { get; set; }

		public TemplatePropertyItem Template { get; set; }

		public XElement Save(IDictionary<TemplatePropertyItem, int> templatesIndexes)
		{
			if (templatesIndexes == null)
			{
				throw new ArgumentNullException("templatesIndexes");
			}
			XElement xElement = new XElement("SREPI");
			if (!string.IsNullOrWhiteSpace(Stream))
			{
				xElement.SetAttributeValue("Stream", Stream);
			}
			if (Template != null)
			{
				xElement.SetAttributeValue("Template", templatesIndexes[Template]);
			}
			return xElement;
		}

		public static StreamReportExtraPropertyInfo TryParse(XElement xml, IList<TemplatePropertyItem> streamReportProperties)
		{
			if (xml == null)
			{
				throw new ArgumentNullException("xml");
			}
			if (streamReportProperties == null)
			{
				throw new ArgumentNullException("streamReportProperties");
			}
			string text = (string)xml.Attribute("Stream");
			if (string.IsNullOrWhiteSpace(text))
			{
				return null;
			}
			int? num = (int?)xml.Attribute("Template");
			if (!num.HasValue || num.Value < 0 || num.Value >= streamReportProperties.Count)
			{
				return null;
			}
			return new StreamReportExtraPropertyInfo
			{
				Stream = text,
				Template = streamReportProperties[num.Value]
			};
		}
	}
	public static class CustomFormVariableRepairer
	{
		[CompilerGenerated]
		private sealed class EnumerateCustomFormsEnumerator : IEnumerable<(CxsNode Node, FormLayout Layout)>, IEnumerable, IEnumerator<(CxsNode Node, FormLayout Layout)>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private (CxsNode Node, FormLayout Layout) iteratorCurrentValue;

			private int iteratorInitialThreadId;

			private CxsNode[] iteratorLocal1;

			private int iteratorLocal2;

			(CxsNode Node, FormLayout Layout) IEnumerator<(CxsNode Node, FormLayout Layout)>.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return iteratorCurrentValue;
				}
			}

			[DebuggerHidden]
			public EnumerateCustomFormsEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				iteratorInitialThreadId = Environment.CurrentManagedThreadId;
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
					goto IL_00a1;
				}
				iteratorState = -1;
				if (CustomFormsModule.SharedUnityContainer != null)
				{
					CxsCase cxsCase = (UnityContainerHelper.TryResolve<IShellApplication>(CustomFormsModule.SharedUnityContainer) as IApwnApplication)?.ActiveDocument?.Case;
					if (cxsCase != null)
					{
						CxsNode[] array = DataHelper.FindAllCustomForms(cxsCase);
						if (array != null)
						{
							iteratorLocal1 = array;
							iteratorLocal2 = 0;
							goto IL_00af;
						}
					}
				}
				goto IL_00c6;
				IL_00a1:
				iteratorLocal2++;
				goto IL_00af;
				IL_00c6:
				return false;
				IL_00af:
				if (iteratorLocal2 < iteratorLocal1.Length)
				{
					CxsNode cxsNode = iteratorLocal1[iteratorLocal2];
					FormLayout formLayout = DataHelper.LoadCustomFormLayout(cxsNode);
					if (formLayout != null)
					{
						iteratorCurrentValue = (Node: cxsNode, Layout: formLayout);
						iteratorState = 1;
						return true;
					}
					goto IL_00a1;
				}
				iteratorLocal1 = null;
				goto IL_00c6;
			}


			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<(CxsNode Node, FormLayout Layout)> IEnumerable<(CxsNode Node, FormLayout Layout)>.GetEnumerator()
			{
				if (iteratorState == -2 && iteratorInitialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					return this;
				}
				return new EnumerateCustomFormsEnumerator(0);
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<(CxsNode, FormLayout)>)this).GetEnumerator();
			}
		}

		private const string TopAppModelDot = "Top.AppModel.";

		private const string TopAppModelV8Dot = "Top.AppModelV8.";

		public static void RepairAllForObjectRenaming(ObjectRenamedAnywhereEventArgs args)
		{
			if (args == null || string.IsNullOrWhiteSpace(args.OldPath) || string.IsNullOrWhiteSpace(args.NewPath))
			{
				return;
			}
			List<string> list = new List<string>();
			foreach (var item in EnumerateCustomForms())
			{
				bool flag = false;
				foreach (TabLayout tab in item.Layout.Tabs)
				{
					foreach (RowLayout row in tab.Rows)
					{
						if (TryRenameVariableInRow(row, args.OldPath, args.NewPath))
						{
							flag = true;
						}
					}
				}
				if (flag)
				{
					DataHelper.SaveCustomFormLayout(item.Node, item.Layout);
					list.Add(item.Node.Path);
				}
			}
			if (list.Count > 0)
			{
				PublishCustomFormRepairedEvent(list);
			}
		}

		public static void RepairAllForObjectDeleting(ObjectDeletedAnywhereEventArgs args)
		{
			if (string.IsNullOrWhiteSpace(args?.DeletedObjectPath))
			{
				return;
			}
			List<string> list = new List<string>();
			foreach (var item in EnumerateCustomForms())
			{
				bool flag = false;
				foreach (TabLayout tab in item.Layout.Tabs)
				{
					List<RowLayout> list2 = tab.Rows.Where((RowLayout x) => IsVariableInRowDeleted(x, args.DeletedObjectPath)).ToList();
					if (list2.Count <= 0)
					{
						continue;
					}
					foreach (RowLayout item2 in list2)
					{
						tab.Rows.Remove(item2);
					}
					flag = true;
				}
				if (flag)
				{
					DataHelper.SaveCustomFormLayout(item.Node, item.Layout);
					list.Add(item.Node.Path);
				}
			}
			if (list.Count > 0)
			{
				PublishCustomFormRepairedEvent(list);
			}
		}

		public static void RepairAllForMovingSelection(MoveSelectionEventArgs args)
		{
			if (args == null)
			{
				return;
			}
			List<string> list = new List<string>(args.MovedStreams);
			list.AddRange(args.MovedBlocks.Keys);
			IDictionary<string, string> dictionary = GenerateMovedPaths(list, args.TargetHierarchy);
			if (dictionary.Count <= 0)
			{
				return;
			}
			List<string> list2 = new List<string>();
			foreach (var item in EnumerateCustomForms())
			{
				bool flag = false;
				foreach (TabLayout tab in item.Layout.Tabs)
				{
					foreach (RowLayout row in tab.Rows)
					{
						if (TryFixVariableInRowForObjectMoving(row, dictionary))
						{
							flag = true;
						}
					}
				}
				if (flag)
				{
					DataHelper.SaveCustomFormLayout(item.Node, item.Layout);
					list2.Add(item.Node.Path);
				}
			}
			if (list2.Count > 0)
			{
				PublishCustomFormRepairedEvent(list2);
			}
		}

		private static IDictionary<string, string> GenerateMovedPaths(IEnumerable<string> movedObjects, string targetHierarchy)
		{
			Dictionary<string, string> dictionary = new Dictionary<string, string>();
			string text = CreateHierarchyPrefix(targetHierarchy);
			foreach (string movedObject in movedObjects)
			{
				string text2 = movedObject;
				if (text2.StartsWith("Data.", StringComparison.InvariantCultureIgnoreCase))
				{
					text2 = text2.Substring(5);
				}
				if (string.IsNullOrEmpty(text))
				{
					dictionary[text2] = string.Empty;
					continue;
				}
				string text3 = TrimToLeafNode(movedObject);
				dictionary[text2] = text + text3;
			}
			return dictionary;
			static string CreateHierarchyPrefix(string hpath)
			{
				if (!string.IsNullOrEmpty(hpath))
				{
					StringBuilder stringBuilder = new StringBuilder();
					string[] array = hpath.Split('.');
					foreach (string value in array)
					{
						if (stringBuilder.Length == 0)
						{
							stringBuilder.Append("Blocks.").Append(value).Append('.');
						}
						else
						{
							stringBuilder.Append("Data.Blocks.").Append(value).Append('.');
						}
					}
					return stringBuilder.ToString();
				}
				return string.Empty;
			}
			static string TrimToLeafNode(string path)
			{
				int num = path.LastIndexOf(".Data.");
				if (num <= 0)
				{
					return path;
				}
				return path.Substring(num + 1);
			}
		}

		private static bool TryRenameVariableInRow(RowLayout row, string oldPathPrefix, string newPathPrefix)
		{
			if (!string.IsNullOrWhiteSpace(row.Path))
			{
				string prefix;
				string text = TrimAppTopModelPrefix(oldPathPrefix, out prefix) + ".";
				string prefix2;
				string text2 = TrimAppTopModelPrefix(row.Path, out prefix2);
				if (text2.StartsWith(text, StringComparison.InvariantCultureIgnoreCase))
				{
					string prefix3;
					string text3 = TrimAppTopModelPrefix(newPathPrefix, out prefix3) + ".";
					row.Path = prefix2 + text3 + text2.Substring(text.Length);
					return true;
				}
			}
			return false;
		}

		private static bool TryFixVariableInRowForObjectMoving(RowLayout row, IDictionary<string, string> movedPaths)
		{
			if (!string.IsNullOrWhiteSpace(row.Path))
			{
				string prefix;
				string trimmedRowPath = TrimAppTopModelPrefix(row.Path, out prefix);
				string text = movedPaths.Keys.FirstOrDefault((string x) => trimmedRowPath.StartsWith(x + ".", StringComparison.CurrentCultureIgnoreCase));
				if (text != null)
				{
					string text2 = movedPaths[text];
					string text3 = trimmedRowPath.Substring(text.Length);
					if (!string.IsNullOrEmpty(text2))
					{
						row.Path = prefix + text2 + text3;
					}
					else
					{
						if (text3.StartsWith(".Data.", StringComparison.CurrentCultureIgnoreCase))
						{
							text3 = text3.Substring(6);
						}
						row.Path = prefix + text3;
					}
					return true;
				}
			}
			return false;
		}

		private static bool IsVariableInRowDeleted(RowLayout row, string path)
		{
			if (!string.IsNullOrWhiteSpace(row.Path))
			{
				string prefix;
				string text = TrimAppTopModelPrefix(path, out prefix);
				if (TrimAppTopModelPrefix(row.Path, out var _).StartsWith(text + ".", StringComparison.InvariantCultureIgnoreCase))
				{
					return true;
				}
			}
			return false;
		}

		[IteratorStateMachine(typeof(EnumerateCustomFormsEnumerator))]
		private static IEnumerable<(CxsNode Node, FormLayout Layout)> EnumerateCustomForms()
		{
			return new EnumerateCustomFormsEnumerator(-2);
		}

		private static string FixHierarchyNameToCheck(string name)
		{
			string text = name.Replace(".Streams.", ".Data.Streams.");
			text = text.Replace(".Blocks.", ".Data.Blocks.");
			return "." + text + ".";
		}

		private static string TrimAppTopModelPrefix(string path, out string prefix)
		{
			prefix = null;
			if (!string.IsNullOrWhiteSpace(path))
			{
				if (path.StartsWith("Top.AppModel.", StringComparison.InvariantCultureIgnoreCase))
				{
					prefix = "Top.AppModel.";
					return path.Substring("Top.AppModel.".Length);
				}
				if (path.StartsWith("Top.AppModelV8.", StringComparison.InvariantCultureIgnoreCase))
				{
					prefix = "Top.AppModelV8.";
					return path.Substring("Top.AppModelV8.".Length);
				}
			}
			return path;
		}

		private static void PublishCustomFormRepairedEvent(IEnumerable<string> paths)
		{
			IUnityContainer sharedUnityContainer = CustomFormsModule.SharedUnityContainer;
			if (sharedUnityContainer != null)
			{
				UnityContainerHelper.TryResolve<IEventAggregator>(sharedUnityContainer)?.GetEvent<CustomFormVariableRepairedEvent>().Publish(new CustomFormVariableRepairedEventArgs(paths));
			}
		}

		public static void PublishCustomFormRepairedEvent(this CustomFormControl cfc, bool saveLayout = false)
		{
			if (cfc != null)
			{
				if (saveLayout)
				{
					cfc.SaveFormLayout();
				}
				PublishCustomFormRepairedEvent(new string[1] { cfc.MainNodePath });
			}
		}
	}
	internal class CustomizeSizeWindow : Window
	{
		protected override Size MeasureOverride(Size availableSize)
		{
			availableSize.Width = 2147483647.0;
			availableSize.Height = 2147483647.0;
			return availableSize;
		}
	}
	public static class DataHelper
	{
		public const int MaxPasteVariableCount = 200;

		public const string AsiFormat = "ASI Format";

		private const int LayoutCharactersPerLine = 76;

		private const string EndSavedLayoutString = "</FormLayout>";

		private const string InputSegmentInPath = ".Input.";

		private const string OutputSegmentInPath = ".Output.";

		private const string EOFlowsheetSegmentInPath = ".EO Flowsheet.";

		private const string SharedDataSegmentInPath = ".SharedData.";

		public static string GetAsiFormatTextFromClipboard()
		{
			if (System.Windows.Clipboard.ContainsData("ASI Format"))
			{
				object obj = null;
				try
				{
					obj = System.Windows.Clipboard.GetData("ASI Format");
				}
				catch (Exception)
				{
				}
				if (obj is string)
				{
					return obj as string;
				}
				if (obj is Stream)
				{
					using (StreamReader streamReader = new StreamReader(obj as Stream))
					{
						return streamReader.ReadToEnd();
					}
				}
			}
			return null;
		}

		public static string GetAsiFormatTextFromDataObject(System.Windows.IDataObject dataObject)
		{
			if (dataObject != null)
			{
				try
				{
					object data = dataObject.GetData("ASI Format");
					if (data is string)
					{
						return data as string;
					}
					if (data is Stream)
					{
						using (StreamReader streamReader = new StreamReader(data as Stream))
						{
							return streamReader.ReadToEnd();
						}
					}
				}
				catch (Exception)
				{
				}
			}
			return null;
		}

		internal static IList<ClipboardCellDataTuple> ParseDataFromAsiFormat(string asiFormatText, string baseCaseFilePath)
		{
			if (!string.IsNullOrEmpty(asiFormatText))
			{
				try
				{
					XDocument xDocument = XDocument.Parse(asiFormatText);
					if (xDocument != null)
					{
						XElement xElement = xDocument.Root.Element("FileMoniker");
						if (xElement != null && string.Equals(xElement.Value, baseCaseFilePath, StringComparison.CurrentCulture))
						{
							List<ClipboardCellDataTuple> list = new List<ClipboardCellDataTuple>();
							IEnumerable<XElement> enumerable = xDocument.Root.XPathSelectElements("Items/Item");
							if (enumerable != null)
							{
								foreach (XElement item in enumerable)
								{
									string name = (string)item.Element("Name");
									string text = (string)item.Element("Path");
									int? rowIndex = (int?)item.Element("Row");
									int? columnIndex = (int?)item.Element("Col");
									if (!string.IsNullOrWhiteSpace(text))
									{
										list.Add(new ClipboardCellDataTuple(name, text, rowIndex, columnIndex));
									}
								}
							}
							return list;
						}
					}
				}
				catch
				{
					return null;
				}
			}
			return null;
		}

		public static string GenerateAsiFormatText(CxsCase cxsCase, IList<string> paths, IDictionary<string, (string name, int rowIndex, int columnIndex)> dicPathToName)
		{
			XElement xElement = new XElement("Selection");
			xElement.SetElementValue("Product", cxsCase.ApplicationName);
			xElement.SetElementValue("Version", SystemEnvironment.ExternalVersionString);
			xElement.SetElementValue("FileMoniker", cxsCase.CaseFullFilePath);
			XElement xElement2 = new XElement("Items");
			foreach (string path in paths)
			{
				string content = string.Empty;
				int num = 0;
				int num2 = 0;
				if (dicPathToName.Keys.Contains(path))
				{
					content = dicPathToName[path].name;
					num = dicPathToName[path].rowIndex;
					num2 = dicPathToName[path].columnIndex;
				}
				xElement2.Add(new XElement("Item", new XElement("Path", "cxs:" + path), new XElement("Name", content), new XElement("Row", num), new XElement("Col", num2)));
			}
			xElement.Add(xElement2);
			return xElement.ToString(SaveOptions.DisableFormatting);
		}

		public static IDataCell CreateDataCellObject(CustomFormDataTable table, CxsNode node, CustomFormDataRow row, CustomFormDataColumn column)
		{
			switch (column.ColumnType)
			{
			case CustomFormColumnType.Name:
			{
				if (!string.IsNullOrEmpty(row.InitialRowLayout.Name))
				{
					return DataRow.CreateDataCell(row.InitialRowLayout.Name);
				}
				string text = table.AdjustRowName(row, column, GetAttributeValue(node, "name") as string);
				row.InitialRowLayout.Name = text;
				return DataRow.CreateDataCell(text);
			}
			case CustomFormColumnType.Value:
			{
				object attributeValue = GetAttributeValue(node, "value");
				Type type = null;
				bool flag = false;
				string nodeType = node.NodeType;
				if (!(nodeType == "Text"))
				{
					if (nodeType == "Real")
					{
						type = typeof(double);
						flag = table.ParentPage.ShowRealValuesAsTooltips;
					}
				}
				else
				{
					type = typeof(string);
				}
				if (node.OptionList != null && node.OptionList.Count > 0)
				{
					return DataRow.CreateDataCell(attributeValue, node.ReadOnly || ReadonlyDue2SpecialPath(node.Path), node.OptionList, CellUIType.ComboBox, null, null, type);
				}
				bool isReadOnly = node.ReadOnly || ReadonlyDue2SpecialPath(node.Path);
				Type valueType = type;
				bool showValueAsTooltipForDoubleTypes = flag;
				return DataRow.CreateDataCell(attributeValue, isReadOnly, null, CellUIType.Unknown, null, null, valueType, null, null, null, null, null, null, showValueAsTooltipForDoubleTypes);
			}
			case CustomFormColumnType.Lower:
			case CustomFormColumnType.Upper:
				return DataRow.CreateDataCell(GetAttributeValue(node, column.ColumnAttribute), isReadOnly: true);
			case CustomFormColumnType.Units:
			{
				if (node.UnitsList == null || node.UnitsList.Count == 0)
				{
					string[] array = CxsConverter.ValueToStringArray(node.Case.BatchGet(node.Path, "uom_options", null));
					if (array != null && array.Length != 0)
					{
						return DataRow.CreateDataCell(GetAttributeValue(node, "units") as string, isReadOnly: false, array);
					}
					return DataRow.CreateDataCell(GetAttributeValue(node, "units") as string, isReadOnly: true);
				}
				string value = node.Units;
				if (string.IsNullOrEmpty(value) || !node.UnitsList.Contains(value))
				{
					value = node.Case.BatchGet(node.Path, "uom", null) as string;
				}
				return DataRow.CreateDataCell(value, isReadOnly: false, node.UnitsList);
			}
			default:
				return DataRow.CreateDataCell(GetAttributeValue(node, column.ColumnAttribute), isReadOnly: true);
			}
		}

		private static object GetAttributeValue(CxsNode node, string attribute)
		{
			switch (attribute)
			{
			case "container":
				return node.Container;
			case "container_category":
				return node.ContainerCategory;
			case "container_type":
				return node.ContainerType;
			case "name":
				if (IsCalculatorDefineVariableSheetValueVariable(node.Path))
				{
					string calculatorDefineVariableSheetValueVariableName = GetCalculatorDefineVariableSheetValueVariableName(node.Case, node.Path);
					if (!string.IsNullOrEmpty(calculatorDefineVariableSheetValueVariableName))
					{
						return calculatorDefineVariableSheetValueVariableName;
					}
				}
				return GetNodeName(node);
			case "value":
			{
				object obj = null;
				if (node.Case != null)
				{
					obj = node.Case.BatchGet(node.Path, "value");
					if (obj != null)
					{
						Type type = obj.GetType();
						if (type != null && type.FullName == "System.DBNull" && obj != null)
						{
							return null;
						}
					}
					else
					{
						obj = node.Value;
					}
				}
				else
				{
					obj = node.Value;
				}
				if (obj != null && node.ValueType == CxsNodeValueType.Real)
				{
					double result = 0.0;
					if (double.TryParse(obj.ToString(), out result))
					{
						obj = result;
					}
				}
				return obj;
			}
			case "units":
				if (IsCalculatorDefineVariableSheetValueVariable(node.Path))
				{
					string calculatorDefineVariableSheetValueVariableUnit = GetCalculatorDefineVariableSheetValueVariableUnit(node.Case, node.Path);
					if (!string.IsNullOrEmpty(calculatorDefineVariableSheetValueVariableUnit))
					{
						return calculatorDefineVariableSheetValueVariableUnit;
					}
				}
				if (string.IsNullOrEmpty(node.Units))
				{
					return node.Case.BatchGet(node.Path, "uom", null);
				}
				return node.Units;
			case "lower_limit":
				return node.LowerLimit;
			case "upper_limit":
				return node.UpperLimit;
			case "path":
				return node.Path;
			case "status":
				if (!string.IsNullOrEmpty(node.Status))
				{
					return node.Status;
				}
				return CxsConverter.ValueToString(node.Case.BatchGet(node.Path, "status"));
			case "variable name":
				return GetNodeVariableName(node);
			case "object name":
				return GetNodeObjectName(node);
			case "object type":
				return GetNodeObjectType(node);
			case "object id1":
				return GetNodeObjectID1(node);
			case "object id2":
				return GetNodeObjectID2(node);
			case "object id3":
				return GetNodeObjectID3(node);
			default:
				return node.GetAttribute(attribute);
			}
		}

		public static bool ReadonlyDue2SpecialPath(string strNodePath)
		{
			if (string.IsNullOrEmpty(strNodePath))
			{
				return false;
			}
			if (strNodePath.EndsWith(".Input.PARTICLESIZE"))
			{
				return true;
			}
			if (strNodePath.Contains(".Stream Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Heat Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Work Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Power Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			return false;
		}

		public static bool IsResultVariable(string strNodePath)
		{
			if (string.IsNullOrEmpty(strNodePath))
			{
				return false;
			}
			if (strNodePath.Contains(".Stream Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Heat Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Work Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			if (strNodePath.Contains(".Power Results.") && strNodePath.Contains(".Table."))
			{
				return true;
			}
			return false;
		}

		public static bool IsCalculatorDefineVariableSheetValueVariable(string strNodePath)
		{
			bool result = false;
			if (string.IsNullOrEmpty(strNodePath))
			{
				return false;
			}
			if (strNodePath.Contains(".Flowsheeting Options.Calculator.") && (strNodePath.Contains(".Output.READ_VAL.") || strNodePath.Contains(".Output.WRITE_VAL.")))
			{
				return true;
			}
			return result;
		}

		public static string GetCalculatorDefineVariableSheetValueVariableName(CxsCase objCxsCase, string strNodePath)
		{
			if (objCxsCase == null)
			{
				return string.Empty;
			}
			if (!IsCalculatorDefineVariableSheetValueVariable(strNodePath))
			{
				return string.Empty;
			}
			string path = strNodePath.Replace(".READ_VAL.", ".VARID.").Replace(".WRITE_VAL.", ".VARID.");
			CxsNode cxsNode = objCxsCase.ResolveNode(path);
			if (cxsNode == null)
			{
				return string.Empty;
			}
			return cxsNode.Value as string;
		}

		public static string GetCalculatorDefineVariableSheetValueVariableUnit(CxsCase objCxsCase, string strNodePath)
		{
			if (objCxsCase == null)
			{
				return string.Empty;
			}
			if (!IsCalculatorDefineVariableSheetValueVariable(strNodePath))
			{
				return string.Empty;
			}
			string path = strNodePath.Replace(".READ_VAL.", ".VAR_UNIT.").Replace(".WRITE_VAL.", ".VAR_UNIT.");
			CxsNode cxsNode = objCxsCase.ResolveNode(path);
			if (cxsNode == null)
			{
				return string.Empty;
			}
			return cxsNode.Value as string;
		}

		private static string GetNodeName(CxsNode node)
		{
			string nodeObjectName = GetNodeObjectName(node);
			string nodeVariableName = GetNodeVariableName(node);
			if (string.IsNullOrEmpty(nodeObjectName) || string.IsNullOrEmpty(nodeVariableName))
			{
				return GetLongNodeName(node);
			}
			return nodeObjectName + "." + nodeVariableName;
		}

		private static string GetNodeVariableName(CxsNode node)
		{
			string path = CheckSharedData(node);
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < 4; i++)
			{
				string objectIdSegment = GetObjectIdSegment(path, i);
				if (string.IsNullOrWhiteSpace(objectIdSegment) || Guid.TryParse(objectIdSegment, out var _))
				{
					break;
				}
				if (stringBuilder.Length > 0)
				{
					stringBuilder.Append("_");
				}
				stringBuilder.Append(objectIdSegment);
			}
			return stringBuilder.ToString();
		}

		private static string GetNodeObjectName(CxsNode node)
		{
			if (node.Path.Contains(".Input.") || node.Path.Contains(".Output."))
			{
				return node.Container;
			}
			if (node.Path.Contains(".SharedData."))
			{
				if (string.IsNullOrEmpty(node.Container))
				{
					if (node.Path.StartsWith("Top.appModel.SharedData.", StringComparison.InvariantCultureIgnoreCase))
					{
						string text = node.Path.Replace("Top.appModel.SharedData.", string.Empty);
						if (text.StartsWith("Flowsheet.", StringComparison.InvariantCultureIgnoreCase))
						{
							text = text.Replace("Flowsheet.", null);
						}
						int num = text.LastIndexOf('.');
						if (num > 0)
						{
							text = text.Substring(0, num);
						}
						return text;
					}
					string path = node.Path;
					int length = path.IndexOf(".SharedData.");
					return path.Substring(0, length).Replace("Top.appModel.", string.Empty).Replace("Data.Blocks.", string.Empty)
						.Replace("Blocks.", string.Empty);
				}
				return node.Container;
			}
			return null;
		}

		private static string GetLongNodeName(CxsNode node)
		{
			string empty = string.Empty;
			if (string.IsNullOrEmpty(node.Path))
			{
				return empty;
			}
			empty = node.Path;
			empty = empty.Replace("Top.appModel.", string.Empty);
			empty = empty.Replace("Top.", string.Empty);
			empty = empty.Replace("Subobjects.", string.Empty);
			empty = empty.Replace("Blocks.", string.Empty);
			return empty.Replace("Sections.", string.Empty);
		}

		private static string GetNodeObjectType(CxsNode node)
		{
			string path = node.Path;
			int num = path.IndexOf(".Input.");
			if (num < 0)
			{
				num = path.IndexOf(".Output.");
			}
			if (num < 0)
			{
				num = path.IndexOf(".SharedData.");
			}
			if (num > 0)
			{
				string[] array = path.Substring(0, num).Split('.');
				if (array.Length > 2)
				{
					return array[array.Length - 2];
				}
			}
			return null;
		}

		public static string CheckSharedData(CxsNode cxsNode)
		{
			if (!string.IsNullOrEmpty(cxsNode.Path) && cxsNode.Path.Contains(".SharedData."))
			{
				object obj = cxsNode.Case.BatchGet(cxsNode.Path, "ads_id_path", null);
				if (obj != null)
				{
					return "SharedData.Output." + obj.ToString();
				}
			}
			return cxsNode.Path;
		}

		private static string GetNodeObjectID1(CxsNode node)
		{
			return GetObjectIdSegment(CheckSharedData(node), 1);
		}

		private static string GetNodeObjectID2(CxsNode node)
		{
			return GetObjectIdSegment(CheckSharedData(node), 2);
		}

		private static string GetNodeObjectID3(CxsNode node)
		{
			return GetObjectIdSegment(CheckSharedData(node), 3);
		}

		private static string GetObjectIdSegment(string path, int offset)
		{
			if (string.IsNullOrEmpty(path))
			{
				return null;
			}
			if (offset < 0)
			{
				return null;
			}
			int num = path.IndexOf(".Input.");
			int length = ".Input.".Length;
			if (num < 0)
			{
				num = path.IndexOf(".Output.");
				length = ".Output.".Length;
			}
			if (num > 0)
			{
				string text = path.Substring(num + length);
				if (!string.IsNullOrEmpty(text))
				{
					string[] array = text.Split('.');
					if (array.Length > offset)
					{
						return array[offset];
					}
				}
			}
			else if (offset == 0 && path.IndexOf(".EO Flowsheet.") > 0)
			{
				int num2 = path.LastIndexOf(".\"");
				if (num2 > 0 && path.Length > num2 + 2)
				{
					string text2 = path.Substring(num2 + 2);
					string text3 = string.Empty;
					if (text2.LastOrDefault() == '"')
					{
						text3 = text2.Substring(0, text2.Length - 1);
					}
					if (string.IsNullOrEmpty(text3))
					{
						return null;
					}
					string text4 = string.Empty;
					num2 = path.LastIndexOf(".Variables");
					if (num2 > 0)
					{
						string text5 = path.Substring(0, num2);
						text5 = text5.Replace("Top.appModel.EO Flowsheet.appModel.", "");
						if (text5.StartsWith("Blocks.") && text5 != "Blocks.")
						{
							text5 = text5.Substring(7);
						}
						text5 = text5.Replace(".Blocks", "");
						if (!string.IsNullOrEmpty(text5))
						{
							text4 = text5;
						}
					}
					if (!string.IsNullOrEmpty(text4))
					{
						text3 = text4 + "." + text3;
					}
					return text3;
				}
			}
			return null;
		}

		public static bool UpdateAttributeValue(IUnityContainer unityContainer, CxsNode node, CustomFormColumnType columnType, object value)
		{
			CxsDataProvider cxsDataProvider = unityContainer.Resolve<CxsDataProvider>(Array.Empty<ResolverOverride>());
			switch (columnType)
			{
			case CustomFormColumnType.Value:
				return cxsDataProvider.BatchSet(node.Path, "value", null, value);
			case CustomFormColumnType.Lower:
				return cxsDataProvider.BatchSet(node.Path, "lower_limit", null, value);
			case CustomFormColumnType.Upper:
				return cxsDataProvider.BatchSet(node.Path, "upper_limit", null, value);
			case CustomFormColumnType.Units:
			{
				if (!node.ReadOnly && !ReadonlyDue2SpecialPath(node.Path))
				{
					return cxsDataProvider.BatchSet(node.Path, "value", value as string, node.Value);
				}
				string path = node.Path;
				return cxsDataProvider.BatchSet(path, "uom", null, value as string);
			}
			default:
				return false;
			}
		}

		public static CxsNode[] FindAllCustomForms(CxsCase CxsCase)
		{
			if (CxsCase == null)
			{
				return null;
			}
			List<CxsNode> list = new List<CxsNode>();
			CxsNode cxsNode = CxsCase.ResolveNode("Top.appModel.Flowsheet.Custom Forms");
			if (cxsNode != null)
			{
				CxsNodeCollection childNodes = cxsNode.ChildNodes;
				if (childNodes != null)
				{
					list.AddRange(childNodes);
				}
			}
			CxsNode cxsNode2 = CxsCase.ResolveNode("Top.appModel.Blocks");
			if (cxsNode2 != null)
			{
				CxsNode[] array = FindCustomFormsInBlock(cxsNode2);
				if (array != null)
				{
					list.AddRange(array);
				}
			}
			return list.ToArray();
		}

		private static CxsNode[] FindCustomFormsInBlock(CxsNode blockNode)
		{
			if (blockNode == null)
			{
				return null;
			}
			List<CxsNode> list = new List<CxsNode>();
			CxsNodeCollection childNodes = blockNode.ChildNodes;
			if (childNodes != null)
			{
				foreach (CxsNode item in childNodes)
				{
					if (string.IsNullOrWhiteSpace(item.NodeType) || !(item.NodeType.ToUpper() == "HIERARCHY"))
					{
						continue;
					}
					CxsNode cxsNode = blockNode.Case.ResolveNode(item.Path + ".Data.Flowsheet.Custom Forms");
					if (cxsNode != null)
					{
						CxsNodeCollection childNodes2 = cxsNode.ChildNodes;
						if (childNodes2 != null)
						{
							list.AddRange(childNodes2);
						}
					}
					CxsNode cxsNode2 = blockNode.Case.ResolveNode(item.Path + ".Data.Blocks");
					if (cxsNode2 != null)
					{
						CxsNode[] array = FindCustomFormsInBlock(cxsNode2);
						if (array != null)
						{
							list.AddRange(array);
						}
					}
				}
			}
			return list.ToArray();
		}

		public static void UpdateCustomFormLayout(CxsNode customFormNode, CxsDataProvider provider)
		{
			if (customFormNode == null || provider == null)
			{
				return;
			}
			CxsCase cxsCase = provider.Case;
			if (cxsCase == null)
			{
				return;
			}
			FormLayout formLayout = LoadCustomFormLayout(customFormNode);
			if (formLayout == null)
			{
				formLayout = new FormLayout();
			}
			else
			{
				foreach (TabLayout tab in formLayout.Tabs)
				{
					if (tab == null)
					{
						continue;
					}
					foreach (RowLayout row in tab.Rows)
					{
						try
						{
							string path = row.Path;
							object obj = cxsCase.BatchGet(path, "value");
							object obj2 = cxsCase.BatchGet(path, "uom");
							row.Value = ((obj != null) ? obj.ToString() : row.Value);
							row.Units = ((obj2 != null) ? obj2.ToString() : row.Units);
						}
						catch (Exception)
						{
						}
					}
				}
			}
			SaveCustomFormLayout(customFormNode, formLayout);
		}

		public static FormLayout LoadCustomFormLayout(CxsNode customFormNode)
		{
			return FormLayout.TryParse(GetCustomFormLayout(customFormNode));
		}

		public static string GetCustomFormLayout(CxsNode customFormNode)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (customFormNode == null)
			{
				return string.Empty;
			}
			CxsNode cxsNode = customFormNode.ResolveNode("Input.VIEWS");
			if (cxsNode == null)
			{
				return string.Empty;
			}
			cxsNode.RefreshChildNodes();
			foreach (CxsNode childNode in cxsNode.ChildNodes)
			{
				string stringValue = childNode.StringValue;
				if (stringValue.StartsWith("{") && stringValue.EndsWith("}"))
				{
					stringBuilder.Append(stringValue.Substring(1, stringValue.Length - 2));
				}
				else
				{
					stringBuilder.Append(stringValue);
				}
			}
			string text = stringBuilder.ToString();
			int num = text.IndexOf("</FormLayout>");
			return (num > 0) ? text.Substring(0, num + "</FormLayout>".Length) : string.Empty;
		}

		public static void SaveCustomFormLayout(CxsNode customFormNode, FormLayout layout)
		{
			string layoutString = layout.Save();
			SaveCustomFormLayout2(customFormNode, layoutString);
		}

		public static void SaveCustomFormLayout2(CxsNode customFormNode, string layoutString)
		{
			if (string.IsNullOrEmpty(layoutString))
			{
				return;
			}
			int length = layoutString.Length;
			List<string> list = new List<string>();
			for (int i = 0; i < length; i += 76)
			{
				string text = layoutString.Substring(i, Math.Min(length - i, 76));
				list.Add("{" + text + "}");
			}
			CxsNode cxsNode = customFormNode.ResolveNode("Input.VIEWS");
			if (cxsNode == null)
			{
				return;
			}
			cxsNode.RefreshChildNodes();
			int value = MmgSor.MMinqcpt();
			int value2 = MmgSor.MMinqpgc();
			int value3 = MmgSor.MMinqnec();
			string parentPath = cxsNode.ParentPath;
			int count = cxsNode.ChildNodes.Count;
			if (count > 0)
			{
				for (int num = count - 1; num >= 0; num--)
				{
					customFormNode.Case.InvokeAction(parentPath + ".VIEWS", "DeleteChild", num);
				}
			}
			cxsNode.RefreshChildNodes();
			for (int j = 0; j < list.Count; j++)
			{
				cxsNode.ChildNodes.AddNew();
				CxsNode cxsNode2 = cxsNode.ResolveNode("#" + j);
				if (cxsNode2 != null)
				{
					cxsNode2.Value = list[j];
				}
			}
			MmgSor.MMsetcpt(value);
			MmgSor.MMsetpgc(value2);
			MmgSor.MMsetnec(value3);
		}

		public static Brush GetForegroundForNode(CxsNode node)
		{
			if (node != null)
			{
				if (node.ReadOnly)
				{
					return Brushes.Black;
				}
				if (IsResultVariable(node.Path))
				{
					return Brushes.Black;
				}
				return Brushes.Blue;
			}
			return null;
		}

		public static FontWeight GetFontWeightForNode(CxsNode node)
		{
			if (node != null)
			{
				if (node.ReadOnly)
				{
					return FontWeights.Normal;
				}
				if (IsResultVariable(node.Path))
				{
					return FontWeights.Normal;
				}
				if (string.Equals(node.Status, "Default", StringComparison.OrdinalIgnoreCase))
				{
					return FontWeights.Normal;
				}
				if (node.Case != null && !string.IsNullOrEmpty(node.Path) && CxsConverter.ValueToBoolean(node.Case.BatchGet(node.Path, "user_entered")) == false)
				{
					return FontWeights.Normal;
				}
				return FontWeights.Bold;
			}
			return FontWeights.Normal;
		}

		public static FontStyle GetFontStyleForNode(CxsNode node)
		{
			if (node != null)
			{
				if (string.Equals(node.Status, "Default", StringComparison.OrdinalIgnoreCase))
				{
					return FontStyles.Italic;
				}
				if (node.Case != null && !string.IsNullOrEmpty(node.Path) && CxsConverter.ValueToBoolean(node.Case.BatchGet(node.Path, "user_entered")) == false)
				{
					return FontStyles.Italic;
				}
				return FontStyles.Normal;
			}
			return FontStyles.Normal;
		}
	}
	internal class ClipboardCellDataTuple
	{
		public string Name { get; }

		public string Path { get; }

		public int? RowIndex { get; }

		public int? ColumnIndex { get; }

		public ClipboardCellDataTuple(string name, string path, int? rowIndex, int? columnIndex)
		{
			Name = name;
			Path = path;
			RowIndex = rowIndex;
			ColumnIndex = columnIndex;
		}
	}
	public interface ICustomFormView
	{
		void InitializeView(IUnityContainer unityContainer, string mainPath);

		void UpdateView();
	}
}
namespace AspenTech.AspenPlus.MMForms.CustomForms.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
// The three COM contracts below are embedded by the C# compiler from its linked Interop.Happ primary interop assembly.
// namespace AspenTech.AspenPlus.Happ
// {
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("8E567522-F9BA-11CF-90B2-0000C0A810C4")]
// 	[TypeIdentifier]
// 	public interface IHNode
// 	{
// 		void _VtblGap1_2();
//
// 		[DispId(1610743810)]
// 		string Name  // COM index parameter: object force.
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743810)]
// 			[return: MarshalAs(UnmanagedType.BStr)]
// 			get;
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743810)]
// 			[param: In]
// 			[param: MarshalAs(UnmanagedType.BStr)]
// 			set;
// 		}
//
// 		void _VtblGap2_14();
//
// 		[DispId(1610743826)]
// 		IHNodeCol Elements
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743826)]
// 			[return: MarshalAs(UnmanagedType.Interface)]
// 			get;
// 		}
//
// 		void _VtblGap3_8();
//
// 		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 		[DispId(1610743835)]
// 		[return: MarshalAs(UnmanagedType.Interface)]
// 		IHNode FindNode([In][MarshalAs(UnmanagedType.BStr)] string path);
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[Guid("89E81F60-019A-11D0-9BE7-0000C05375D5")]
// 	[TypeIdentifier]
// 	public interface IHNodeCol : IEnumerable
// 	{
// 		void _VtblGap1_6();
//
// 		[DispId(0)]
// 		IHNode this[[In][MarshalAs(UnmanagedType.Struct)] object loc_or_name, [Optional][In][MarshalAs(UnmanagedType.Struct)] object loc_or_name2, [Optional][In][MarshalAs(UnmanagedType.Struct)] object loc_or_name3, [Optional][In][MarshalAs(UnmanagedType.Struct)] object loc_or_name4, [Optional][In][MarshalAs(UnmanagedType.Struct)] object loc_or_name5]
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(0)]
// 			[return: MarshalAs(UnmanagedType.Interface)]
// 			get;
// 		}
// 	}
// 	[ComImport]
// 	[CompilerGenerated]
// 	[DefaultMember("Name")]
// 	[Guid("8E567521-F9BA-11CF-90B2-0000C0A810C4")]
// 	[TypeIdentifier]
// 	public interface IHapp
// 	{
// 		void _VtblGap1_3();
//
// 		[DispId(0)]
// 		string Name  // COM index parameter: object force.
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(0)]
// 			[return: MarshalAs(UnmanagedType.BStr)]
// 			get;
// 		}
//
// 		void _VtblGap2_7();
//
// 		[DispId(1610743819)]
// 		IHNode Tree
// 		{
// 			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
// 			[DispId(1610743819)]
// 			[return: MarshalAs(UnmanagedType.Interface)]
// 			get;
// 		}
// 	}
// }

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x0600001d AspenTech.AspenPlus.MMForms.CustomForms.CustomFormViewModel..ctor
// public CustomFormViewModel()
// {
// }

// 0x060000e8 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormChangedEvent..ctor
// public CustomFormChangedEvent()
// {
// }

// 0x060000f3 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormGridControlColumnDisplayIndexChangedEventArgs..ctor
// public CustomFormGridControlColumnDisplayIndexChangedEventArgs()
// {
// }

// 0x060000f4 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormGridControlColumnDisplayIndexChangedEvent..ctor
// public CustomFormGridControlColumnDisplayIndexChangedEvent()
// {
// }

// 0x0600010b AspenTech.AspenPlus.MMForms.CustomForms.RowLayout..ctor
// public RowLayout()
// {
// }

// 0x0600010f AspenTech.AspenPlus.MMForms.CustomForms.ColumnLayout..ctor
// public ColumnLayout()
// {
// }

// 0x06000126 AspenTech.AspenPlus.MMForms.CustomForms.StreamReportExtraPropertyInfo..ctor
// public StreamReportExtraPropertyInfo()
// {
// }

// 0x06000136 AspenTech.AspenPlus.MMForms.CustomForms.CustomizeSizeWindow..ctor
// public CustomizeSizeWindow()
// {
// }

// 0x0600015f AspenTech.AspenPlus.MMForms.CustomForms.Properties.Settings..ctor
// public Settings()
// {
// }

// 0x06000160 AspenTech.AspenPlus.MMForms.CustomForms.Properties.Settings..cctor
// using System.Configuration;
//
// static Settings()
// {
// 	defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());
// }

// 0x0600016e AspenTech.AspenPlus.MMForms.CustomForms.CustomFormControl+<>c__DisplayClass70_0..ctor
// public <>c__DisplayClass70_0()
// {
// }

// 0x06000170 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormControl+<>c__DisplayClass81_0..ctor
// public <>c__DisplayClass81_0()
// {
// }

// 0x06000174 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormControlPage+<>c__DisplayClass23_0..ctor
// public <>c__DisplayClass23_0()
// {
// }

// 0x06000176 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormDataTable+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000177 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormDataTable+<>c..ctor
// public <>c()
// {
// }

// 0x0600017a AspenTech.AspenPlus.MMForms.CustomForms.CustomFormDataTable+<>c__DisplayClass8_0..ctor
// public <>c__DisplayClass8_0()
// {
// }

// 0x0600018e AspenTech.AspenPlus.MMForms.CustomForms.CustomFormVariableRepairedEventArgs+<>c__DisplayClass4_0..ctor
// public <>c__DisplayClass4_0()
// {
// }

// 0x06000190 AspenTech.AspenPlus.MMForms.CustomForms.TabLayout+<>c__DisplayClass17_0..ctor
// public <>c__DisplayClass17_0()
// {
// }

// 0x06000192 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormVariableRepairer+<>c__DisplayClass3_0..ctor
// public <>c__DisplayClass3_0()
// {
// }

// 0x06000194 AspenTech.AspenPlus.MMForms.CustomForms.CustomFormVariableRepairer+<>c__DisplayClass7_0..ctor
// public <>c__DisplayClass7_0()
// {
// }
