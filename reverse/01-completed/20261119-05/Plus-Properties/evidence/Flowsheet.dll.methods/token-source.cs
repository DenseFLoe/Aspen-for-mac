// 0x06000001 CreateInstance
using System;
using System.Globalization;
using System.Reflection;

protected override object CreateInstance(Type type, CultureInfo culture)
{
	return Activator.CreateInstance(type, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.CreateInstance, null, null, culture);
}

// 0x06000002 GetPropertyValue
using System.Globalization;
using System.Reflection;

protected override object GetPropertyValue(PropertyInfo propertyInfo, object target, CultureInfo culture)
{
	return propertyInfo.GetValue(target, BindingFlags.Default, null, null, culture);
}

// 0x06000003 SetPropertyValue
using System.Globalization;
using System.Reflection;

protected override void SetPropertyValue(PropertyInfo propertyInfo, object target, object value, CultureInfo culture)
{
	propertyInfo.SetValue(target, value, BindingFlags.Default, null, null, culture);
}

// 0x06000004 CreateDelegate
using System;
using System.Reflection;

protected override Delegate CreateDelegate(Type delegateType, object target, string handler)
{
	return (Delegate)target.GetType().InvokeMember("_CreateDelegate", BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.InvokeMethod, null, target, new object[2] { delegateType, handler }, null);
}

// 0x06000005 AddEventHandler
using System;
using System.Reflection;

protected override void AddEventHandler(EventInfo eventInfo, object target, Delegate handler)
{
	eventInfo.AddEventHandler(target, handler);
}

// 0x06000006 .ctor
public GeneratedInternalTypeHelper()
{
}

// 0x06000007 get_spec
{
	return GetValue(spec_Property);
}

// 0x06000008 get_NOTPFSLOCK
{
	return GetValue(NOTPFSLOCK_Property);
}

// 0x06000009 get_tab0_var
{
	return GetValue(tab0_var_Property);
}

// 0x0600000a OnUpdateData
protected override void OnUpdateData()
{
	base.OnUpdateData();
	if (base.IsInitialUpdate)
	{
		ResolveUpdateParameter("NotNeedName", "NotNull");
		ResolveUpdateParameter("NotNeedType", "NotNull");
	}
}

// 0x0600000b .ctor
public MMFlowsh_Input_ViewModel()
{
}

// 0x0600000c .cctor
using AspenTech.AspenCxs.CxsViewModel;

static MMFlowsh_Input_ViewModel()
{
	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMFlowsh_Input_ViewModel), new CxvVariableProperty
	{
		DataPath = "@main.CC Nodes.MAIN"
	});
	NOTPFSLOCK_Property = CxvPropertyDeclaration.Register("NOTPFSLOCK", typeof(MMFlowsh_Input_ViewModel), new CxvVariableProperty
	{
		DataPath = "@main.CC Nodes.NOTPFSLOCK"
	});
	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFlowsh_Input_ViewModel), new CxvTabItemProperty
	{
		CompleteDataPaths = { "@spec" },
		AccessibleDataPaths = { "@NOTPFSLOCK" }
	});
}

// 0x0600000d .ctor
public MMFlowsh_Input()
{
	base.ViewModelType = typeof(MMFlowsh_Input_ViewModel);
	InitializeComponent();
}

// 0x0600000e InitializeComponent
using System;
using System.CodeDom.Compiler;
using System.Diagnostics;
using System.Windows;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
public void InitializeComponent()
{
	if (!_contentLoaded)
	{
		_contentLoaded = true;
		Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_input.xaml", UriKind.Relative);
		Application.LoadComponent(this, resourceLocator);
	}
}

// 0x0600000f System.Windows.Markup.IComponentConnector.Connect
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows.Markup;
using AspenTech.AspenPlus.MMControls;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
[EditorBrowsable(EditorBrowsableState.Never)]
void IComponentConnector.Connect(int connectionId, object target)
{
	switch (connectionId)
	{
	case 1:
		MMSSTab1 = (MMTabStrip)target;
		break;
	case 2:
		tab0 = (MMTabItem)target;
		break;
	case 3:
		tabInfo = (MMTabItem)target;
		break;
	default:
		_contentLoaded = true;
		break;
	}
}

// 0x06000010 get_grdFlowsheet_GridData
{
	return GetValue(grdFlowsheet_GridData_Property);
}

// 0x06000011 OnUpdateData
protected override void OnUpdateData()
{
	base.OnUpdateData();
	if (base.IsInitialUpdate)
	{
		UpdateInnerItems();
	}
}

// 0x06000012 OnSubPropertyDataChanged
using AspenTech.AspenCxs.CxsViewModel;

protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
{
	base.OnSubPropertyDataChanged(pd, subPropertyName);
	if (pd == grdFlowsheet_GridData_Property && subPropertyName == "Count")
	{
		UpdateInnerItems();
	}
}

// 0x06000013 UpdateInnerItems
using AspenTech.AspenCxs.CxsViewModel.ViewData;

private void UpdateInnerItems()
{
	if (!(grdFlowsheet_GridData is CxvVectorPropertyData cxvVectorPropertyData))
	{
		return;
	}
	if (cxvVectorPropertyData.Count > 0)
	{
		(cxvVectorPropertyData[cxvVectorPropertyData.Count - 1] as grdFlowsheet_GridData_ItemTemplate).IsProxy = true;
	}
	foreach (grdFlowsheet_GridData_ItemTemplate item in cxvVectorPropertyData)
	{
		item.UpdateInnerItems();
	}
}

// 0x06000014 get_Reorder_Command
using AspenTech.AspenPlus.MMControls;
using Microsoft.Practices.Composite.Presentation.Commands;

{
	if (_Reorder_Command == null)
	{
		_Reorder_Command = new DelegateCommand<MMScrollAreaReorderParameter>(Reorder_CommandExecute);
	}
	return _Reorder_Command;
}

// 0x06000015 Reorder_CommandExecute
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.MMControls;
using Infragistics.Windows.DataPresenter;

private void Reorder_CommandExecute(MMScrollAreaReorderParameter parameter)
{
	parameter.Handled = false;
	if (parameter.ScrollArea.DataGrid.SelectedItems.Cells.Count == 0)
	{
		return;
	}
	Cell cell = parameter.ScrollArea.DataGrid.SelectedItems.Cells[0];
	if (cell.Field.Owner != cell.Record.DataPresenter.DefaultFieldLayout)
	{
		parameter.Handled = true;
		MMScrollAreaReorder mMScrollAreaReorder = new MMScrollAreaReorder
		{
			AllowUseValueInReorder = true
		};
		mMScrollAreaReorder.ViewModel = (grdFlowsheet_GridData as CxvVectorPropertyData)[cell.Record.UltimateParentRecord.Index] as MMViewModel;
		switch (cell.Field.Index)
		{
		case 0:
		case 1:
			mMScrollAreaReorder.DataProperty = "Inlets";
			break;
		case 2:
		case 3:
			mMScrollAreaReorder.DataProperty = "Outlets";
			break;
		}
		mMScrollAreaReorder.ShowDialog();
	}
}

// 0x06000016 ValidateBlockId
using System.Collections.ObjectModel;
using System.Windows;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenPlus.Localization.Properties;

private static bool ValidateBlockId(object id, ICxvViewDataContainer vm)
{
	if (id == null)
	{
		return true;
	}
	Collection<string> collection = CxsConverter.ValueToStringCollection(vm.ResolvedCxsProvider.BatchGet("Top.appModelV8.Streams", "child_ids", null));
	if (collection == null)
	{
		return true;
	}
	if (collection.Contains(id.ToString().ToUpper()))
	{
		vm.ShowMessageBox(new ShowMessageBoxEventArgs
		{
			Message = Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message1,
			Title = Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddBlock,
			MsgBoxButton = MessageBoxButton.OK,
			MsgBoxImage = MessageBoxImage.Exclamation
		});
		return false;
	}
	return true;
}

// 0x06000017 ValidateStreamId
using System.Collections.ObjectModel;
using System.Windows;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenPlus.Localization.Properties;

private static bool ValidateStreamId(object id, ICxvViewDataContainer vm)
{
	if (id == null)
	{
		return true;
	}
	Collection<string> collection = CxsConverter.ValueToStringCollection(vm.ResolvedCxsProvider.BatchGet("Top.appModelV8.Blocks", "child_ids", null));
	if (collection == null)
	{
		return true;
	}
	if (collection.Contains(id.ToString().ToUpper()))
	{
		vm.ShowMessageBox(new ShowMessageBoxEventArgs
		{
			Message = Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message2,
			Title = Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddStream,
			MsgBoxButton = MessageBoxButton.OK,
			MsgBoxImage = MessageBoxImage.Exclamation
		});
		return false;
	}
	return true;
}

// 0x06000018 ValidatePort
using AspenTech.AspenCxs.CxsViewModel;

private static bool ValidatePort(object id, ICxvViewDataContainer vm)
{
	if (id == null)
	{
		return true;
	}
	if (id is string text && !text.EndsWith("$(IN)"))
	{
		return !text.EndsWith("$(OUT)");
	}
	return false;
}

// 0x06000019 .ctor
public MMFlowsh_Input_Flowsh_ViewModel()
{
}

// 0x0600001a .cctor
using AspenTech.AspenCxs.CxsViewModel;

static MMFlowsh_Input_Flowsh_ViewModel()
{
	grdFlowsheet_GridData_Property = CxvPropertyDeclaration.Register("grdFlowsheet_GridData", typeof(MMFlowsh_Input_Flowsh_ViewModel), new CxvVectorProperty
	{
		ItemType = typeof(grdFlowsheet_GridData_ItemTemplate),
		IndexBasis = new CxvChildCountIndexBasis
		{
			DataPath = "@main.Input.BLKTYPE",
			UseChildId = true,
			Name = "y"
		},
		AllowCollectionChange = false
	});
}

// 0x0600001b .ctor
public MMFlowsh_Input_Flowsh()
{
	base.ViewModelType = typeof(MMFlowsh_Input_Flowsh_ViewModel);
	InitializeComponent();
	grdFlowsheet.Loaded += grdFlowsheet_Loaded;
}

// 0x0600001c grdFlowsheet_Loaded
using System.Windows;

private void grdFlowsheet_Loaded(object sender, RoutedEventArgs e)
{
	if (grdFlowsheet.DataGrid != null)
	{
		grdFlowsheet.DataGrid.CustomFilterSelectionControlOpening += DataGrid_CustomFilterSelectionControlOpening;
		grdFlowsheet.DataGrid.EditModeEnded += DataGrid_EditModeEnded;
		grdFlowsheet.DataGrid.AddHandler(UIElement.MouseLeftButtonUpEvent, new RoutedEventHandler(DataGrid_MouseLeftButtonUp), handledEventsToo: true);
	}
}

// 0x0600001d DataGrid_MouseLeftButtonUp
using System.Windows;
using Infragistics.Windows;
using Infragistics.Windows.Controls;
using Infragistics.Windows.DataPresenter;

private void DataGrid_MouseLeftButtonUp(object sender, RoutedEventArgs e)
{
	_recordToBeExpandedIndex = null;
	if (e.OriginalSource is ExpansionIndicator || Utilities.GetAncestorFromType(e.OriginalSource as DependencyObject, typeof(ExpansionIndicator), allowSubclassOfType: true) != null)
	{
		Cell activeCell = grdFlowsheet.DataGrid.ActiveCell;
		if (activeCell != null && activeCell.IsInEditMode)
		{
			_recordToBeExpandedIndex = activeCell.Record.Index;
			activeCell.EndEditMode();
		}
	}
}

// 0x0600001e DataGrid_EditModeEnded
using Infragistics.Windows.DataPresenter.Events;

private void DataGrid_EditModeEnded(object sender, EditModeEndedEventArgs e)
{
	if (_recordToBeExpandedIndex.HasValue && grdFlowsheet.DataGrid.Records.Count > _recordToBeExpandedIndex.Value)
	{
		grdFlowsheet.DataGrid.Records[_recordToBeExpandedIndex.Value].IsExpanded = true;
		_recordToBeExpandedIndex = null;
	}
}

// 0x0600001f DataGrid_CustomFilterSelectionControlOpening
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using Infragistics.Windows.DataPresenter.Events;

private void DataGrid_CustomFilterSelectionControlOpening(object sender, CustomFilterSelectionControlOpeningEventArgs e)
{
	if (e.RecordFilter.Field.Label is LabelHeader labelHeader)
	{
		string fieldDescription = string.Format(ApwnResources.ForField, labelHeader.LabelText);
		e.Control.FieldDescription = fieldDescription;
	}
}

// 0x06000020 btnExpandAll_Click
using System.Windows;

private void btnExpandAll_Click(object sender, RoutedEventArgs e)
{
	grdFlowsheet.DataGrid.Records.ExpandAll(recursive: false);
}

// 0x06000021 btnCollapseAll_Click
using System.Windows;

private void btnCollapseAll_Click(object sender, RoutedEventArgs e)
{
	grdFlowsheet.DataGrid.Records.CollapseAll(recursive: false);
}

// 0x06000022 OnClosing
using System.Windows;

public override bool OnClosing()
{
	if (grdFlowsheet.DataGrid != null)
	{
		grdFlowsheet.DataGrid.CustomFilterSelectionControlOpening -= DataGrid_CustomFilterSelectionControlOpening;
		grdFlowsheet.DataGrid.EditModeEnded -= DataGrid_EditModeEnded;
		grdFlowsheet.DataGrid.RemoveHandler(UIElement.MouseLeftButtonUpEvent, new RoutedEventHandler(DataGrid_MouseLeftButtonUp));
	}
	return base.OnClosing();
}

// 0x06000023 InitializeComponent
using System;
using System.CodeDom.Compiler;
using System.Diagnostics;
using System.Windows;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
public void InitializeComponent()
{
	if (!_contentLoaded)
	{
		_contentLoaded = true;
		Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_input_flowsh.xaml", UriKind.Relative);
		Application.LoadComponent(this, resourceLocator);
	}
}

// 0x06000024 System.Windows.Markup.IComponentConnector.Connect
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows.Controls;
using System.Windows.Markup;
using AspenTech.AspenPlus.MMControls;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
[EditorBrowsable(EditorBrowsableState.Never)]
void IComponentConnector.Connect(int connectionId, object target)
{
	switch (connectionId)
	{
	case 1:
		grdFlowsheet = (MMScrollArea)target;
		break;
	case 2:
		btnExpandAll = (Button)target;
		btnExpandAll.Click += btnExpandAll_Click;
		break;
	case 3:
		btnCollapseAll = (Button)target;
		btnCollapseAll.Click += btnCollapseAll_Click;
		break;
	default:
		_contentLoaded = true;
		break;
	}
}

// 0x06000025 get_grdChild_GridData
{
	return GetValue(grdChild_GridData_Property);
}

// 0x06000026 get_cmdAdd_Command
using Microsoft.Practices.Composite.Presentation.Commands;

{
	if (_cmdAdd_Command == null)
	{
		_cmdAdd_Command = new DelegateCommand<object>(cmdAdd_CommandExecute);
	}
	return _cmdAdd_Command;
}

// 0x06000027 get_cmdEdit_Command
using AspenTech.Visualisation.Controls.Support.Commands;

{
	if (_cmdEdit_Command == null)
	{
		_cmdEdit_Command = new RelayActionCommand<object>(cmdEdit_CommandExecute, CommandCanExecute);
	}
	return _cmdEdit_Command;
}

// 0x06000028 get_cmdDelete_Command
using Microsoft.Practices.Composite.Presentation.Commands;

{
	if (_cmdDelete_Command == null)
	{
		_cmdDelete_Command = new DelegateCommand<object>(cmdDelete_CommandExecute);
	}
	return _cmdDelete_Command;
}

// 0x06000029 get_cmdRename_Command
using AspenTech.Visualisation.Controls.Support.Commands;

{
	if (_cmdRename_Command == null)
	{
		_cmdRename_Command = new RelayActionCommand<object>(cmdRename_CommandExecute, CommandCanExecute);
	}
	return _cmdRename_Command;
}

// 0x0600002a get_cmdCurrent_Command
using AspenTech.Visualisation.Controls.Support.Commands;

{
	if (_cmdCurrent_Command == null)
	{
		_cmdCurrent_Command = new RelayActionCommand<object>(cmdCurrent_CommandExecute, CommandCanExecute);
	}
	return _cmdCurrent_Command;
}

// 0x0600002b get_grid_RowDoubleClickCommand
using AspenTech.AspenCxs.CxsViewModel;

{
	if (_grid_RowDoubleClickCommand == null)
	{
		_grid_RowDoubleClickCommand = new CxvDelegateCommand<object>(grid_RowDoubleClickCommandExecute);
	}
	return _grid_RowDoubleClickCommand;
}

// 0x0600002c cmdAdd_CommandExecute
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.MMControls.CompositeEvents;

private void cmdAdd_CommandExecute(object parameter)
{
	new ShowAddChildDialogEventArgs().ParentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
	string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
	string newChildId = null;
	bool? flag = ShowAddChildDialog(parentPath, out newChildId);
	if (flag.HasValue && flag.Value)
	{
		string path = ".!" + newChildId;
		GoToNode(path);
	}
}

// 0x0600002d cmdEdit_CommandExecute
using System.Collections.Generic;

private void cmdEdit_CommandExecute(object parameter)
{
	using IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
	if (enumerator.MoveNext())
	{
		string current = enumerator.Current;
		string path = ".!" + current;
		GoToNodeEx(path);
	}
}

// 0x0600002e GoToNodeEx
using System.Text;
using System.Text.RegularExpressions;

private void GoToNodeEx(string path)
{
	string text = ExpandDataPath("@main");
	if (text.Contains("Blocks"))
	{
		Regex regex = new Regex("Blocks\\.\\w+\\.");
		StringBuilder stringBuilder = new StringBuilder();
		MatchCollection matchCollection = regex.Matches(text);
		if (matchCollection.Count > 0)
		{
			foreach (Match item in matchCollection)
			{
				stringBuilder.Append(item.Value);
			}
		}
		GoToNode("Simulation!" + stringBuilder.ToString() + "Flowsheet.Section." + path.Substring(2));
	}
	else
	{
		GoToNode(path);
	}
}

// 0x0600002f cmdDelete_CommandExecute
using System.Collections.ObjectModel;
using AspenTech.AspenCxs;

private void cmdDelete_CommandExecute(object parameter)
{
	Collection<string> collection = new Collection<string>();
	string text = parameter as string;
	if (!string.IsNullOrEmpty(text))
	{
		collection.Add(text);
	}
	else
	{
		foreach (string selectedId in GetSelectedIds())
		{
			collection.Add(selectedId);
		}
	}
	string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
	DeleteChildren(parentPath, collection);
}

// 0x06000030 cmdRename_CommandExecute
using AspenTech.AspenCxs;

private void cmdRename_CommandExecute(object parameter)
{
	string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
	string text = "";
	foreach (string selectedId in GetSelectedIds())
	{
		text = selectedId;
		ShowRenameChildDialog(parentPath, ref text);
	}
}

// 0x06000031 cmdCurrent_CommandExecute
using AspenTech.AspenCxs;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;

private void cmdCurrent_CommandExecute(object parameter)
{
	this.ChangeSection(ExpandDataPath("@main"), CxsConverter.ValueToString(ResolveViewPropertyPath("grdChild_GridData[" + SelectedRowIndexes[0] + "].txtName_var1.Value", null)));
}

// 0x06000032 CommandCanExecute
private bool CommandCanExecute(object parameter)
{
	if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1)
	{
		return true;
	}
	return false;
}

// 0x06000033 DeleteCommandCanExecute
private bool DeleteCommandCanExecute(object parameter)
{
	if (SelectedRowIndexes != null && SelectedRowIndexes.Count > 0)
	{
		return true;
	}
	return false;
}

// 0x06000034 grid_RowDoubleClickCommandExecute
using System.Collections.Generic;

private void grid_RowDoubleClickCommandExecute(object parameter)
{
	IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
	if (enumerator.MoveNext())
	{
		string path = ".!" + enumerator.Current;
		GoToNode(path);
	}
}

// 0x06000035 get_cmdExport_Command
using AspenTech.Visualisation.Controls.Support.Commands;

{
	if (_cmdExport_Command == null)
	{
		_cmdExport_Command = new RelayActionCommand<object>(cmdExport_CommandExecute, CommandCanExecute);
	}
	return _cmdExport_Command;
}

// 0x06000036 cmdExport_CommandExecute
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.Happ;

private void cmdExport_CommandExecute(object parameter)
{
	foreach (string selectedId in GetSelectedIds())
	{
		string text = ExpandDataPath("@main." + selectedId);
		CxvActionResult cxvActionResult = InvokeAction("Top.appModelV8.Custom Actions", "HappNode", false, text);
		if (cxvActionResult.Succeeded && cxvActionResult.Result is IHNode iHNode)
		{
			iHNode.Export();
		}
	}
}

// 0x06000037 get_SelectedRowIndexes
{
	return _SelectedRowIndexes;
}

// 0x06000038 set_SelectedRowIndexes
{
	if (_SelectedRowIndexes != null)
	{
		_SelectedRowIndexes.CollectionChanged -= _SelectedRowIndexes_CollectionChanged;
	}
	_SelectedRowIndexes = value;
	if (_SelectedRowIndexes != null)
	{
		_SelectedRowIndexes.CollectionChanged += _SelectedRowIndexes_CollectionChanged;
	}
}

// 0x06000039 _SelectedRowIndexes_CollectionChanged
using System.Collections.Specialized;

private void _SelectedRowIndexes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
{
}

// 0x0600003a GetSelectedIds
using System.Collections.Generic;
using System.Runtime.CompilerServices;

[IteratorStateMachine(typeof(<GetSelectedIds>d__40))]
private IEnumerable<string> GetSelectedIds()
{
	return new <GetSelectedIds>d__40(-2)
	{
		<>4__this = this
	};
}

// 0x0600003b SetSelectedRowFromScript
using System.Collections.ObjectModel;

public void SetSelectedRowFromScript(int row)
{
	if (SelectedRowIndexes == null)
	{
		SelectedRowIndexes = new ObservableCollection<int>();
	}
	SelectedRowIndexes.Clear();
	SelectedRowIndexes.Add(row);
}

// 0x0600003c .ctor
public MMFlowsh_ObjMan_ViewModel()
{
}

// 0x0600003d .cctor
using AspenTech.AspenCxs.CxsViewModel;

static MMFlowsh_ObjMan_ViewModel()
{
	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMFlowsh_ObjMan_ViewModel), new CxvVectorProperty
	{
		ItemType = typeof(grdChild_GridData_ItemTemplate),
		IndexBasis = new CxvChildCountIndexBasis
		{
			DataPath = "@main",
			UseChildId = true,
			Name = "y",
			ProxyRow = false
		}
	});
}

// 0x0600003e .ctor
public MMFlowsh_ObjMan()
{
	base.ViewModelType = typeof(MMFlowsh_ObjMan_ViewModel);
	InitializeComponent();
}

// 0x0600003f InitializeComponent
using System;
using System.CodeDom.Compiler;
using System.Diagnostics;
using System.Windows;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
public void InitializeComponent()
{
	if (!_contentLoaded)
	{
		_contentLoaded = true;
		Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_objman.xaml", UriKind.Relative);
		Application.LoadComponent(this, resourceLocator);
	}
}

// 0x06000040 System.Windows.Markup.IComponentConnector.Connect
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows.Markup;
using AspenTech.AspenPlus.MMControls;

[DebuggerNonUserCode]
[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
[EditorBrowsable(EditorBrowsableState.Never)]
void IComponentConnector.Connect(int connectionId, object target)
{
	switch (connectionId)
	{
	case 1:
		cmdAdd = (MMFlatButton)target;
		break;
	case 2:
		cmdExport = (MMFlatButton)target;
		break;
	case 3:
		cmdEdit = (MMFlatButton)target;
		break;
	case 4:
		cmdCurrent = (MMFlatButton)target;
		break;
	case 5:
		grdChild = (MMScrollAreaMS)target;
		break;
	default:
		_contentLoaded = true;
		break;
	}
}

// 0x06000041 _VtblGap1_51
void _VtblGap1_51();

// 0x06000042 Export
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
[DispId(1610743859)]
void Export([In][MarshalAs(UnmanagedType.BStr)] string filename = "");

// 0x06000043 get_cboBlkType_var1
{
	return GetValue(cboBlkType_var1_Property);
}

// 0x06000044 get_MMTextBox1_var1
{
	return GetValue(MMTextBox1_var1_Property);
}

// 0x06000045 get_IsProxy
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	return <IsProxy>k__BackingField;
}

// 0x06000046 set_IsProxy
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	<IsProxy>k__BackingField = value;
}

// 0x06000047 get_Inner
{
	return GetValue(Inner_Property);
}

// 0x06000048 get_Inlets
{
	return GetValue(Inlets_Property);
}

// 0x06000049 get_Outlets
{
	return GetValue(Outlets_Property);
}

// 0x0600004a OnSubPropertyDataChanged
using AspenTech.AspenCxs.CxsViewModel;

protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
{
	if ((pd == Inlets_Property && subPropertyName == "Count") || (pd == Outlets_Property && subPropertyName == "Count"))
	{
		UpdateInnerItems();
	}
	base.OnSubPropertyDataChanged(pd, subPropertyName);
}

// 0x0600004b UpdateInnerItems
using AspenTech.AspenCxs.CxsViewModel.ViewData;

internal void UpdateInnerItems()
{
	if (IsProxy.HasValue && IsProxy.Value)
	{
		ResolveUpdateParameter("NumRows", 0, localOnly: true);
		return;
	}
	CxvVectorPropertyData cxvVectorPropertyData = Inlets as CxvVectorPropertyData;
	CxvVectorPropertyData cxvVectorPropertyData2 = Outlets as CxvVectorPropertyData;
	int num = 0;
	if (cxvVectorPropertyData != null)
	{
		num = cxvVectorPropertyData.Count;
	}
	if (cxvVectorPropertyData2 != null && cxvVectorPropertyData2.Count > num)
	{
		num = cxvVectorPropertyData2.Count;
	}
	ResolveUpdateParameter("NumRows", 0, localOnly: true);
	ResolveUpdateParameter("NumRows", num, localOnly: true);
	CxvVectorPropertyData cxvVectorPropertyData3 = Inner as CxvVectorPropertyData;
	for (int i = 0; i < num; i++)
	{
		if (!(cxvVectorPropertyData3[i] is grdFlowsheet_GridData_InnerTemplate grdFlowsheet_GridData_InnerTemplate))
		{
			continue;
		}
		if (i < cxvVectorPropertyData.Count)
		{
			if (cxvVectorPropertyData[i] is grdFlowsheet_GridData_InletsTemplate grdFlowsheet_GridData_InletsTemplate)
			{
				grdFlowsheet_GridData_InnerTemplate.grdInlet_StrmNode = grdFlowsheet_GridData_InletsTemplate.grdInlet_StrmNode;
				grdFlowsheet_GridData_InnerTemplate.grdInlet_PortNode = grdFlowsheet_GridData_InletsTemplate.grdInlet_PortNode;
			}
		}
		else
		{
			grdFlowsheet_GridData_InnerTemplate.grdInlet_StrmNode = null;
			grdFlowsheet_GridData_InnerTemplate.grdInlet_PortNode = null;
		}
		if (i < cxvVectorPropertyData2.Count)
		{
			if (cxvVectorPropertyData2[i] is grdFlowsheet_GridData_OutletsTemplate grdFlowsheet_GridData_OutletsTemplate)
			{
				grdFlowsheet_GridData_InnerTemplate.grdOutlet_StrmNode = grdFlowsheet_GridData_OutletsTemplate.grdOutlet_StrmNode;
				grdFlowsheet_GridData_InnerTemplate.grdOutlet_PortNode = grdFlowsheet_GridData_OutletsTemplate.grdOutlet_PortNode;
			}
		}
		else
		{
			grdFlowsheet_GridData_InnerTemplate.grdOutlet_StrmNode = null;
			grdFlowsheet_GridData_InnerTemplate.grdOutlet_PortNode = null;
		}
	}
}

// 0x0600004c .ctor
public grdFlowsheet_GridData_ItemTemplate()
{
}

// 0x0600004d .cctor
using AspenTech.AspenCxs.CxsViewModel;

static grdFlowsheet_GridData_ItemTemplate()
{
	cboBlkType_var1_Property = CxvPropertyDeclaration.Register("cboBlkType_var1", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.String,
		DataPath = "@main.Input.MDLTYPE.@y",
		IsEnabledCondition = new CxvLogicalTest
		{
			SubConditions = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.SPECBLKID.@y"
				},
				new CxvLogicalTest
				{
					DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
				}
			},
			Operator = CxvLogicalOperator.And
		}
	});
	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.Id,
		DataPath = "@main.Input.BLKTYPE.@y",
		DisplayedCase = CxsDisplayedCase.Uppercase,
		ValueValidator = ValidateBlockId,
		IsEnabledCondition = new CxvLogicalTest
		{
			DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
		}
	});
	Inner_Property = CxvPropertyDeclaration.Register("Inner", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
	{
		ItemType = typeof(grdFlowsheet_GridData_InnerTemplate),
		IndexBasis = new CxvParameterIndexBasis
		{
			Parameter = "NumRows"
		}
	});
	Inlets_Property = CxvPropertyDeclaration.Register("Inlets", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
	{
		ItemType = typeof(grdFlowsheet_GridData_InletsTemplate),
		IndexBasis = new CxvChildCountIndexBasis
		{
			DataPath = "@main.Input.INSTRM.@y",
			UseChildId = false,
			Name = "x"
		}
	});
	Outlets_Property = CxvPropertyDeclaration.Register("Outlets", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
	{
		ItemType = typeof(grdFlowsheet_GridData_OutletsTemplate),
		IndexBasis = new CxvChildCountIndexBasis
		{
			DataPath = "@main.Input.OUTSTRM.@y",
			UseChildId = false,
			Name = "x"
		}
	});
}

// 0x0600004e .ctor
public grdFlowsheet_GridData_InnerTemplate()
{
	count++;
	mycount = count;
}

// 0x0600004f get_Test
using AspenTech.AspenCxs.CxsViewModel.ViewData;

{
	return new CxvManualVariableData
	{
		Value = mycount.ToString()
	};
}

// 0x06000050 get_grdInlet_StrmNode
{
	return _GrdInlet_StrmNode;
}

// 0x06000051 set_grdInlet_StrmNode
{
	_GrdInlet_StrmNode = value;
}

// 0x06000052 get_grdInlet_PortNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	return <grdInlet_PortNode>k__BackingField;
}

// 0x06000053 set_grdInlet_PortNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	<grdInlet_PortNode>k__BackingField = value;
}

// 0x06000054 get_grdOutlet_StrmNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	return <grdOutlet_StrmNode>k__BackingField;
}

// 0x06000055 set_grdOutlet_StrmNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	<grdOutlet_StrmNode>k__BackingField = value;
}

// 0x06000056 get_grdOutlet_PortNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	return <grdOutlet_PortNode>k__BackingField;
}

// 0x06000057 set_grdOutlet_PortNode
using System.Runtime.CompilerServices;

[CompilerGenerated]
{
	<grdOutlet_PortNode>k__BackingField = value;
}

// 0x06000058 OnSubPropertyDataChanged
using System;
using System.Windows.Threading;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.MMControls;

protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
{
	if (pd.Name == "grdInlet_StrmNode" && subPropertyName == "Value" && ((base.Parent as MMViewModel)?.Parent as MMViewModel)?.View is MMTabPage mMTabPage)
	{
		mMTabPage.Dispatcher.BeginInvoke(DispatcherPriority.Input, new Action(<OnSubPropertyDataChanged>b__0_0));
	}
	base.OnSubPropertyDataChanged(pd, subPropertyName);
}

// 0x06000059 get_grdInlet_PortNode
{
	return GetValue(grdInlet_PortNode_Property);
}

// 0x0600005a get_grdInlet_StrmNode
{
	return GetValue(grdInlet_StrmNode_Property);
}

// 0x0600005b .ctor
public grdFlowsheet_GridData_InletsTemplate()
{
}

// 0x0600005c .cctor
using AspenTech.AspenCxs.CxsViewModel;

static grdFlowsheet_GridData_InletsTemplate()
{
	grdInlet_PortNode_Property = CxvPropertyDeclaration.Register("grdInlet_PortNode", typeof(grdFlowsheet_GridData_InletsTemplate), new CxvVariableProperty
	{
		DataPath = "@main.Input.INPORT.@y.@x",
		IsEnabledCondition = new CxvLogicalTest
		{
			SubConditions = 
			{
				new CxvLogicalTest
				{
					DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
				},
				new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.CONNVALID.@y"
				}
			},
			Operator = CxvLogicalOperator.And
		},
		IsVisibleCondition = new CxvLogicalTest
		{
			DataPath = "@main.CC Nodes.CONNVALID.@y"
		},
		ValueValidator = ValidatePort
	});
	grdInlet_StrmNode_Property = CxvPropertyDeclaration.Register("grdInlet_StrmNode", typeof(grdFlowsheet_GridData_InletsTemplate), new CxvVariableProperty
	{
		DataPath = "@main.Input.INSTRM.@y.@x",
		IsEnabledCondition = new CxvLogicalTest
		{
			SubConditions = 
			{
				new CxvLogicalTest
				{
					DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
				},
				new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.CONNVALID.@y"
				}
			},
			Operator = CxvLogicalOperator.And
		},
		IsVisibleCondition = new CxvLogicalTest
		{
			DataPath = "@main.CC Nodes.CONNVALID.@y"
		},
		AllowNew = false,
		AllowEmptyOptions = true,
		ValueValidator = ValidateStreamId
	});
}

// 0x0600005d <OnSubPropertyDataChanged>b__0_0
using System.Runtime.CompilerServices;
using AspenTech.AspenCxs;

[CompilerGenerated]
private void <OnSubPropertyDataChanged>b__0_0()
{
	string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.INSTRM.@y.@x", "value"));
	if (!string.IsNullOrEmpty(text))
	{
		string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.INPORT.@y.@x", "value"));
		if (string.IsNullOrEmpty(text2) || text2.EndsWith("$(IN)"))
		{
			ExpandDataPathAndSet("@main.Input.INPORT.@y.@x", "value", text + "(IN)");
		}
	}
}

// 0x0600005e OnSubPropertyDataChanged
using System;
using System.Windows.Threading;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.MMControls;

protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
{
	if (pd.Name == "grdOutlet_StrmNode" && subPropertyName == "Value" && ((base.Parent as MMViewModel)?.Parent as MMViewModel)?.View is MMTabPage mMTabPage)
	{
		mMTabPage.Dispatcher.BeginInvoke(DispatcherPriority.Input, new Action(<OnSubPropertyDataChanged>b__0_0));
	}
	base.OnSubPropertyDataChanged(pd, subPropertyName);
}

// 0x0600005f get_grdOutlet_StrmNode
{
	return GetValue(grdOutlet_StrmNode_Property);
}

// 0x06000060 get_grdOutlet_PortNode
{
	return GetValue(grdOutlet_PortNode_Property);
}

// 0x06000061 .ctor
public grdFlowsheet_GridData_OutletsTemplate()
{
}

// 0x06000062 .cctor
using AspenTech.AspenCxs.CxsViewModel;

static grdFlowsheet_GridData_OutletsTemplate()
{
	grdOutlet_StrmNode_Property = CxvPropertyDeclaration.Register("grdOutlet_StrmNode", typeof(grdFlowsheet_GridData_OutletsTemplate), new CxvVariableProperty
	{
		DataPath = "@main.Input.OUTSTRM.@y.@x",
		IsEnabledCondition = new CxvLogicalTest
		{
			SubConditions = 
			{
				new CxvLogicalTest
				{
					DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
				},
				new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.CONNVALID.@y"
				}
			},
			Operator = CxvLogicalOperator.And
		},
		IsVisibleCondition = new CxvLogicalTest
		{
			DataPath = "@main.CC Nodes.CONNVALID.@y"
		},
		AllowNew = false,
		AllowEmptyOptions = true,
		ValueValidator = ValidateStreamId
	});
	grdOutlet_PortNode_Property = CxvPropertyDeclaration.Register("grdOutlet_PortNode", typeof(grdFlowsheet_GridData_OutletsTemplate), new CxvVariableProperty
	{
		DataPath = "@main.Input.OUTPORT.@y.@x",
		IsEnabledCondition = new CxvLogicalTest
		{
			SubConditions = 
			{
				new CxvLogicalTest
				{
					DataPath = "Top.appModelV8.Settings.EnableFlowsheetSectionForm"
				},
				new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.CONNVALID.@y"
				}
			},
			Operator = CxvLogicalOperator.And
		},
		IsVisibleCondition = new CxvLogicalTest
		{
			DataPath = "@main.CC Nodes.CONNVALID.@y"
		},
		ValueValidator = ValidatePort
	});
}

// 0x06000063 <OnSubPropertyDataChanged>b__0_0
using System.Runtime.CompilerServices;
using AspenTech.AspenCxs;

[CompilerGenerated]
private void <OnSubPropertyDataChanged>b__0_0()
{
	string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.OUTSTRM.@y.@x", "value"));
	if (!string.IsNullOrEmpty(text))
	{
		string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.OUTPORT.@y.@x", "value"));
		if (string.IsNullOrEmpty(text2) || text2.EndsWith("$(OUT)"))
		{
			ExpandDataPathAndSet("@main.Input.OUTPORT.@y.@x", "value", text + "(OUT)");
		}
	}
}

// 0x06000064 get_cboSClass_VarCol1
{
	return GetValue(cboSClass_VarCol1_Property);
}

// 0x06000065 get_txtName_var1
{
	return GetValue(txtName_var1_Property);
}

// 0x06000066 GetId
using AspenTech.AspenCxs;

public string GetId()
{
	return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
}

// 0x06000067 get_RecType
{
	if (string.IsNullOrEmpty(_recType))
	{
		switch (ExpandDataPath("@main").Replace("Top.appModelV8.", string.Empty))
		{
		case "Reactions.Reactions":
			_recType = "reactions";
			break;
		case "Properties.Analysis":
			_recType = "analysis";
			break;
		case "Convergence.Convergence":
			_recType = "convergence";
			break;
		case "Model Analysis Tools.Data-Fit.Data-Set":
			_recType = "data_set";
			break;
		case "Properties.Data":
			_recType = "data";
			break;
		}
	}
	return _recType;
}

// 0x06000068 GetLocalizedCol1
using System.Text.RegularExpressions;
using AspenTech.AspenPlus.Localization;

private string GetLocalizedCol1(string key, string defaultOptionValue)
{
	string text = string.Empty;
	if (!string.IsNullOrEmpty(key))
	{
		string name = Regex.Replace(key, "[^a-zA-Z0-9]", "_").ToLower();
		text = ApwnRecTypeResource.ResourceManager.GetObject(name, ApwnRecTypeResource.Culture) as string;
	}
	if (!string.IsNullOrEmpty(text))
	{
		return text;
	}
	return defaultOptionValue;
}

// 0x06000069 get_txtType_VarCol1
using AspenTech.AspenCxs.CxsViewModel.ViewData;

{
	CxvVariableData cxvVariableData = GetValue(txtType_VarCol1_Property) as CxvVariableData;
	if (cxvVariableData != null && cxvVariableData.Value != null && !string.IsNullOrEmpty(cxvVariableData.Value.ToString()))
	{
		string localizedCol = GetLocalizedCol1("rectype_" + RecType + "_" + cxvVariableData.Value.ToString(), cxvVariableData.Value.ToString());
		return new CxvManualVariableData
		{
			Value = localizedCol,
			IsReadOnly = true,
			IsCalculated = false
		};
	}
	return cxvVariableData;
}

// 0x0600006a get_cboStatus_Status
{
	return GetValue(cboStatus_Status_Property);
}

// 0x0600006b get_txtDescription_var1
{
	return GetValue(txtDescription_var1_Property);
}

// 0x0600006c .ctor
public grdChild_GridData_ItemTemplate()
{
	_recType = string.Empty;
	base..ctor();
}

// 0x0600006d .cctor
using AspenTech.AspenCxs.CxsViewModel;

static grdChild_GridData_ItemTemplate()
{
	cboSClass_VarCol1_Property = CxvPropertyDeclaration.Register("cboSClass_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.String,
		DataPath = "@main.@y.Input.SCLASS"
	});
	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
	{
		ExposeAs = CxvVariableTypeCode.Id,
		DataPath = "@main.@y",
		DisplayedCase = CxsDisplayedCase.Uppercase
	});
	txtType_VarCol1_Property = CxvPropertyDeclaration.Register("txtType_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.String,
		DataPath = "@main.@y",
		DataAttribute = "type",
		IsReadOnly = true,
		IsCalculated = false
	});
	cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.String,
		DataPath = "@main.@y",
		DataAttribute = "status",
		IsReadOnly = true
	});
	txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
	{
		DataPath = "@main.@y.Input.DESCRIPTION"
	});
}

// 0x0600006e .ctor
using System;
using System.Diagnostics;

[DebuggerHidden]
public <GetSelectedIds>d__40(int <>1__state)
{
	this.<>1__state = <>1__state;
	<>l__initialThreadId = Environment.CurrentManagedThreadId;
}

// 0x0600006f System.IDisposable.Dispose
using System;
using System.Diagnostics;

[DebuggerHidden]
void IDisposable.Dispose()
{
}

// 0x06000070 MoveNext
using System.Collections;

private bool MoveNext()
{
	int num = <>1__state;
	MMFlowsh_ObjMan_ViewModel mMFlowsh_ObjMan_ViewModel = <>4__this;
	switch (num)
	{
	default:
		return false;
	case 0:
		<>1__state = -1;
		<gridData>5__2 = mMFlowsh_ObjMan_ViewModel.grdChild_GridData as IList;
		<i>5__3 = mMFlowsh_ObjMan_ViewModel.SelectedRowIndexes.Count - 1;
		break;
	case 1:
		<>1__state = -1;
		<i>5__3--;
		break;
	}
	if (<i>5__3 >= 0)
	{
		grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = <gridData>5__2[mMFlowsh_ObjMan_ViewModel.SelectedRowIndexes[<i>5__3]] as grdChild_GridData_ItemTemplate;
		<>2__current = grdChild_GridData_ItemTemplate.GetId();
		<>1__state = 1;
		return true;
	}
	return false;
}

// 0x06000071 System.Collections.Generic.IEnumerator<System.String>.get_Current
using System.Diagnostics;

[DebuggerHidden]
{
	return <>2__current;
}

// 0x06000072 System.Collections.IEnumerator.Reset
using System;
using System.Collections;
using System.Diagnostics;

[DebuggerHidden]
void IEnumerator.Reset()
{
	throw new NotSupportedException();
}

// 0x06000073 System.Collections.IEnumerator.get_Current
using System.Diagnostics;

[DebuggerHidden]
{
	return <>2__current;
}

// 0x06000074 System.Collections.Generic.IEnumerable<System.String>.GetEnumerator
using System;
using System.Collections.Generic;
using System.Diagnostics;

[DebuggerHidden]
IEnumerator<string> IEnumerable<string>.GetEnumerator()
{
	<GetSelectedIds>d__40 result;
	if (<>1__state == -2 && <>l__initialThreadId == Environment.CurrentManagedThreadId)
	{
		<>1__state = 0;
		result = this;
	}
	else
	{
		result = new <GetSelectedIds>d__40(0)
		{
			<>4__this = <>4__this
		};
	}
	return result;
}

// 0x06000075 System.Collections.IEnumerable.GetEnumerator
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;

[DebuggerHidden]
IEnumerator IEnumerable.GetEnumerator()
{
	return ((IEnumerable<string>)this).GetEnumerator();
}

