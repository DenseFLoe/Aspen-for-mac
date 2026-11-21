using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Threading;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.Engineering.GridControls;
using AspenTech.Engineering.GridControls.EventArgs;
using Infragistics.Windows.DataPresenter;
using Infragistics.Windows.DataPresenter.Events;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Results_Summary")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Results_Summary")]
[assembly: AssemblyCopyright("Copyright © AspenTech 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Run_Status")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/results_summary", "AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum")]
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
namespace AspenTech.AspenPlus.MMForms.Results_Summary
{
	public class CustomIndexBasis : CxvChildCountIndexBasis
	{
		private string paramSelectedStreams;

		private string paramAvailableStreams;

		public CustomIndexBasis(string paramSelectedStreams, string paramAvailableStreams)
		{
			this.paramAvailableStreams = paramAvailableStreams;
			this.paramSelectedStreams = paramSelectedStreams;
		}

		public override CxvIndexBasisBaseData CreateData(ICxvViewDataContainer dataContainer, CxvPropertyWatch dependencies)
		{
			return new CustomIndexBasisData(this, dataContainer, paramSelectedStreams, paramAvailableStreams);
		}
	}
	public class CustomIndexBasisData : CxvChildCountIndexBasisData
	{
		private string paramSelectedStreams;

		private string paramAvailableStreams;

		private ObservableCollection<string> selectedStreams;

		private ObservableCollection<string> availableStreams;

		public bool SuspendUpdate { get; set; }

		public override int Count
		{
			get
			{
				if (base.DataContainer == null)
				{
					return 0;
				}
				if (availableStreams == null || availableStreams.Count <= 0 || selectedStreams == null)
				{
					return 0;
				}
				return selectedStreams.Count + 1;
			}
		}

		public override bool AllowRemove => true;

		public CustomIndexBasisData(CxvChildCountIndexBasis basis, ICxvViewDataContainer dataContainer, string paramSelectedStreams, string paramAvailableStreams)
			: base(basis, dataContainer)
		{
			this.paramAvailableStreams = paramAvailableStreams;
			this.paramSelectedStreams = paramSelectedStreams;
			SuspendUpdate = false;
			selectedStreams = (ObservableCollection<string>)dataContainer.ResolveParameter(paramSelectedStreams);
			if (selectedStreams != null)
			{
				selectedStreams.CollectionChanged += selectedStreams_CollectionChanged;
			}
			availableStreams = (ObservableCollection<string>)base.DataContainer.ResolveParameter(paramAvailableStreams);
		}

		public void Update()
		{
			OnCountChanged();
		}

		private void selectedStreams_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (!SuspendUpdate)
			{
				OnCountChanged();
			}
		}

		public override object GetIndexSubstitution(int index, CxvPropertyWatch dependencies)
		{
			if (selectedStreams == null)
			{
				return null;
			}
			if (index < selectedStreams.Count)
			{
				return selectedStreams[index];
			}
			return "#" + (base.Count + 1).ToString(CultureInfo.InvariantCulture);
		}

		protected override void RefreshChildIds()
		{
			base.RefreshChildIds();
			selectedStreams = (ObservableCollection<string>)base.DataContainer.ResolveParameter(paramSelectedStreams);
		}

		public override void Unload()
		{
			base.Unload();
			selectedStreams.CollectionChanged -= selectedStreams_CollectionChanged;
			selectedStreams = null;
		}

		public override void RemoveAt(int index)
		{
			if (selectedStreams != null && index < selectedStreams.Count)
			{
				string item = selectedStreams[index];
				selectedStreams.Remove(item);
			}
		}
	}
	public interface IItemTemplate
	{
		object inner { get; }
	}
	public interface IFormViewModel
	{
		object stream_AdvCollection { get; }
	}
	public class CustomStreamSelectedObject<GridData_ItemTemplate, FormViewModel> : INotifyPropertyChanged where GridData_ItemTemplate : MMViewModel, IItemTemplate where FormViewModel : MMTabPageViewModel, IFormViewModel
	{
		private string paramSelectedStreams;

		private string paramAvailableStreams;

		private string paramStreamVisible;

		private ICxvViewDataContainer _dataContainer;

		private string _id;

		private Dictionary<string, string> _ComboPropmptsDictionary = new Dictionary<string, string>();

		private ICxsDataWatch _tooltipWatch;

		private EventHandler _tooltipWatch_ValuesChangedHandler;

		private ObservableCollection<string> _valueOptions;

		public bool? IsReadOnly
		{
			get
			{
				if ((_valueOptions == null || _valueOptions.Count == 0) && string.IsNullOrEmpty(_id))
				{
					return true;
				}
				return false;
			}
		}

		public bool? IsCalculated => true;

		public bool? IsEntered => false;

		public bool? IsEnabled => true;

		public Type ValueType => typeof(string);

		public object Value
		{
			get
			{
				return _id;
			}
			set
			{
				if (!(_id != (string)value))
				{
					return;
				}
				string oldValue = _id;
				_id = (string)value;
				int num = -1;
				ObservableCollection<string> observableCollection = (ObservableCollection<string>)_dataContainer.ResolveParameter(paramSelectedStreams);
				if (!string.IsNullOrEmpty(oldValue) && observableCollection.Contains(oldValue))
				{
					if (observableCollection.Where((string x) => x == oldValue).Count() == 1)
					{
						num = observableCollection.IndexOf(oldValue);
					}
					else
					{
						num = observableCollection.IndexOf(oldValue);
						MMViewModel mMViewModel = _dataContainer as MMViewModel;
						if (mMViewModel.Parent is GridData_ItemTemplate val && val.inner is CxvVectorPropertyData cxvVectorPropertyData && cxvVectorPropertyData[num] != mMViewModel)
						{
							for (int num2 = num + 1; num2 < cxvVectorPropertyData.Count; num2++)
							{
								if (cxvVectorPropertyData[num2] == mMViewModel)
								{
									num = num2;
									break;
								}
							}
						}
					}
				}
				if (value == null)
				{
					if (num != -1)
					{
						observableCollection.RemoveAt(num);
					}
				}
				else if (num == -1)
				{
					observableCollection.Add(_id);
				}
				else
				{
					observableCollection[num] = _id;
				}
				if (!(((bool?)_dataContainer.ResolveParameter(paramStreamVisible)) ?? true))
				{
					return;
				}
				_dataContainer.ResolveUpdateParameter(paramStreamVisible, false);
				for (MMViewModel mMViewModel2 = _dataContainer as MMViewModel; mMViewModel2 != null; mMViewModel2 = mMViewModel2.Parent as MMViewModel)
				{
					if (mMViewModel2 is FormViewModel val2)
					{
						(val2.stream_AdvCollection as CxvAdvCollectionPropertyData).SelectedItem = "Streams";
						break;
					}
				}
			}
		}

		public Dictionary<string, string> OptionPrompts => _ComboPropmptsDictionary;

		public string VariablePrompt
		{
			get
			{
				if (string.IsNullOrEmpty(_id))
				{
					return null;
				}
				return GetVariablePrompt(_id);
			}
		}

		public IEnumerable ValueOptions => _valueOptions;

		public event PropertyChangedEventHandler PropertyChanged;

		public CustomStreamSelectedObject(ICxvViewDataContainer dataContainer, string paramSelectedStreams, string paramAvailableStreams, string paramStreamVisible)
		{
			this.paramSelectedStreams = paramSelectedStreams;
			this.paramAvailableStreams = paramAvailableStreams;
			this.paramStreamVisible = paramStreamVisible;
			_dataContainer = dataContainer;
			_id = (string)_dataContainer.ResolveParameter("x");
			if (!string.IsNullOrEmpty(_id) && _id.StartsWith("#"))
			{
				_id = "";
			}
			_valueOptions = (ObservableCollection<string>)_dataContainer.ResolveParameter(paramAvailableStreams);
			if (_ComboPropmptsDictionary.Count != 0)
			{
				return;
			}
			foreach (string valueOption in _valueOptions)
			{
				_ComboPropmptsDictionary[valueOption] = GetVariablePrompt(valueOption);
			}
		}

		protected void OnPropertyChanged(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}

		private void UpdateTooltipWatch(ICxsDataWatch tooltipWatch)
		{
			if (tooltipWatch == _tooltipWatch)
			{
				return;
			}
			if (_tooltipWatch != null && _tooltipWatch_ValuesChangedHandler != null)
			{
				_tooltipWatch.ValuesChanged -= _tooltipWatch_ValuesChangedHandler;
				_tooltipWatch.Unload();
				_tooltipWatch = null;
			}
			if (tooltipWatch == null || tooltipWatch.IsEmpty)
			{
				return;
			}
			if (_tooltipWatch_ValuesChangedHandler == null)
			{
				_tooltipWatch_ValuesChangedHandler = delegate
				{
					OnPropertyChanged("VariablePrompt");
				};
			}
			_tooltipWatch = tooltipWatch;
			_tooltipWatch.ValuesChanged += _tooltipWatch_ValuesChangedHandler;
		}

		private string GetVariablePrompt(string id)
		{
			string text = CxvCustomTooltipHelper.ResolveDataPath(_dataContainer.ExpandDataPath("@main2").Replace("Results Summary", "Streams.[Value]"), id);
			string text2 = text.Replace("Top.appModelV8.", string.Empty).Replace("Blocks.", "Block ").Replace("Streams.", "Stream ")
				.Replace(".Data.", " (Hierarchy) ")
				.Replace(".", " ");
			ICxsDataWatch cxsDataWatch = _dataContainer.ResolvedCxsProvider.CreateWatch();
			cxsDataWatch.AddWatch(CxvCustomTooltipHelper.ResolveDescriptionPath(text), "value");
			cxsDataWatch.AddWatch(text, "type");
			cxsDataWatch.AddWatch(text, "status");
			UpdateTooltipWatch(cxsDataWatch);
			object[] values = cxsDataWatch.Values;
			string text3 = CxsConverter.ValueToString(values[0]);
			string text4 = CxsConverter.ValueToString(values[1]);
			string text5 = CxsConverter.ValueToString(values[2]);
			return text2 + (string.IsNullOrEmpty(text4) ? string.Empty : (" (" + text4 + ")")) + (string.IsNullOrEmpty(text3) ? string.Empty : ("\n" + text3)) + (string.IsNullOrEmpty(text5) ? string.Empty : ("\n" + text5));
		}
	}
	public class StreamHelper<GridData_ItemTemplate> where GridData_ItemTemplate : MMViewModel, IItemTemplate
	{
		private string _paramStreamVisible;

		private MMTabPageViewModel _vm;

		private ObservableCollection<string> _selectedStreams;

		private ObservableCollection<string> _availableStreams;

		private object _grdResults_GridData;

		private ICxsDataWatch _connectionWatch;

		private CxvAdvCollectionPropertyData _stream;

		public StreamHelper(string paramStreamVisible, MMTabPageViewModel vm, ObservableCollection<string> _selectedStreams, ObservableCollection<string> _availableStreams, object grdResults_GridData, CxvAdvCollectionPropertyData stream)
		{
			_paramStreamVisible = paramStreamVisible;
			_vm = vm;
			this._selectedStreams = _selectedStreams;
			this._availableStreams = _availableStreams;
			_grdResults_GridData = grdResults_GridData;
			_stream = stream;
		}

		internal void InitAvailableStreams(Collection<string> streams)
		{
			_availableStreams.Clear();
			if (streams == null)
			{
				return;
			}
			foreach (string stream in streams)
			{
				_availableStreams.Add(stream);
			}
		}

		internal void InSetVariable(Collection<string> streams)
		{
			int num = 0;
			while (num < _selectedStreams.Count)
			{
				if (_availableStreams.Contains(_selectedStreams[num]))
				{
					num++;
				}
				else
				{
					_selectedStreams.RemoveAt(num);
				}
			}
			if (((bool?)_vm.ResolveParameter(_paramStreamVisible)) ?? true)
			{
				CxvVectorPropertyData cxvVectorPropertyData = _grdResults_GridData as CxvVectorPropertyData;
				CustomIndexBasisData customIndexBasisData = null;
				for (int i = 0; i < cxvVectorPropertyData.Count; i++)
				{
					if ((cxvVectorPropertyData[i] as GridData_ItemTemplate).inner is CxvVectorPropertyData { IndexBasis: CustomIndexBasisData indexBasis })
					{
						indexBasis.SuspendUpdate = true;
					}
				}
				_selectedStreams.Clear();
				foreach (string availableStream in _availableStreams)
				{
					_selectedStreams.Add(availableStream);
				}
				for (int j = 0; j < cxvVectorPropertyData.Count; j++)
				{
					if ((cxvVectorPropertyData[j] as GridData_ItemTemplate).inner is CxvVectorPropertyData { IndexBasis: CustomIndexBasisData indexBasis2 })
					{
						indexBasis2.SuspendUpdate = false;
						indexBasis2.Update();
					}
				}
			}
			else if (_availableStreams.Count == 0)
			{
				_selectedStreams.Clear();
			}
		}

		internal void SetInitialDisplay()
		{
			string text = _vm.ExpandDataPath("@main");
			_stream.RefreshItems();
			string text2 = CxsPath.LeafId(text);
			if (text2 == "Results Summary")
			{
				_vm.ResolveUpdateParameter("main2", text);
				_vm.ResolveUpdateParameter(_paramStreamVisible, true);
				return;
			}
			if (CxsPath.LeafId(CxsPath.ParentPath(text)) == "Streams")
			{
				_selectedStreams.Add(text2);
			}
			else
			{
				_connectionWatch = _vm.ResolvedCxsProvider.CreateWatch();
				_connectionWatch.AddWatch(text + ".Connections", "child_ids", null);
				object[] values = _connectionWatch.Values;
				if (values != null && values[0] != null)
				{
					Collection<string> collection = CxsConverter.ValueToStringCollection(values[0]);
					if (collection != null)
					{
						foreach (string item in collection)
						{
							_selectedStreams.Add(item);
						}
					}
				}
				_connectionWatch.ValuesChanged += _connectionWatch_ValuesChanged;
			}
			_vm.ResolveUpdateParameter("main2", CxsPath.ParentPath(CxsPath.ParentPath(text)) + ".Results Summary");
			_vm.ResolveUpdateParameter(_paramStreamVisible, false);
			_stream.SelectedItem = _stream.Items[1].Display;
		}

		private void _connectionWatch_ValuesChanged(object sender, EventArgs e)
		{
		}

		internal void Unload()
		{
			if (_connectionWatch != null)
			{
				_connectionWatch.Unload();
				_connectionWatch = null;
			}
		}

		internal void OnStreamChanged(MMScrollArea sa)
		{
			sa.SuspendInitFields = true;
			string selectedItem = _stream.SelectedItem;
			if (selectedItem == null)
			{
				return;
			}
			CxvVectorPropertyData cxvVectorPropertyData = _grdResults_GridData as CxvVectorPropertyData;
			bool flag = ((bool?)_vm.ResolveParameter(_paramStreamVisible)) ?? true;
			if (selectedItem == "All streams")
			{
				_vm.ResolveUpdateParameter(_paramStreamVisible, true);
				if (!flag && _selectedStreams != null)
				{
					CustomIndexBasisData customIndexBasisData = null;
					for (int i = 0; i < cxvVectorPropertyData.Count; i++)
					{
						if ((cxvVectorPropertyData[i] as GridData_ItemTemplate).inner is CxvVectorPropertyData { IndexBasis: CustomIndexBasisData indexBasis })
						{
							indexBasis.SuspendUpdate = true;
						}
					}
					_selectedStreams.Clear();
					foreach (string availableStream in _availableStreams)
					{
						_selectedStreams.Add(availableStream);
					}
					for (int j = 0; j < cxvVectorPropertyData.Count; j++)
					{
						if ((cxvVectorPropertyData[j] as GridData_ItemTemplate).inner is CxvVectorPropertyData { IndexBasis: CustomIndexBasisData indexBasis2 })
						{
							indexBasis2.SuspendUpdate = false;
							indexBasis2.Update();
						}
					}
				}
			}
			else if (selectedItem == "Streams")
			{
				_vm.ResolveUpdateParameter(_paramStreamVisible, false);
				if (flag && _selectedStreams != null)
				{
					_selectedStreams.Clear();
				}
			}
			sa.SuspendInitFields = false;
			sa.ReInitFields();
		}
	}
	public class StreamSummaryViewModel : MMTabPageViewModel
	{
		private Dispatcher _uiDispatcher;

		private bool _isMaterialFormAccessible;

		private bool? _canEnableUIThreadInEngSim;

		public Dispatcher UIDispatcher
		{
			get
			{
				if (_uiDispatcher == null && base.View is MMTabTemplate mMTabTemplate)
				{
					_uiDispatcher = mMTabTemplate.Dispatcher;
				}
				return _uiDispatcher;
			}
		}

		public bool IsSimulating { get; private set; }

		public bool IsMaterialFormAccessible
		{
			get
			{
				return _isMaterialFormAccessible;
			}
			set
			{
				_isMaterialFormAccessible = value;
				OnPropertyChanged("IsMaterialFormAccessible");
				OnPropertyChanged("IsBatchFormAccessible");
			}
		}

		public virtual bool HasMaterialResultsToDisplay => CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.Stream Results.Table", "value")) ?? false;

		public bool? CanEnableUIThreadInEngSim
		{
			get
			{
				if (!_canEnableUIThreadInEngSim.HasValue)
				{
					CxvActionResult cxvActionResult = InvokeAction("Top.appModelV8.Custom Actions", "CanEnableUIThreadInEngSim", false);
					_canEnableUIThreadInEngSim = CxsConverter.ValueToBoolean(cxvActionResult.Result);
				}
				return _canEnableUIThreadInEngSim;
			}
		}

		public bool IsBatchFormAccessible
		{
			get
			{
				if (base.AdbTopProvider != null)
				{
					string adsFlowsheetPathForStreamSummaryForms = GetAdsFlowsheetPathForStreamSummaryForms();
					if (!string.IsNullOrEmpty(adsFlowsheetPathForStreamSummaryForms))
					{
						return base.AdbTopProvider.IsBatchFlowsheet(adsFlowsheetPathForStreamSummaryForms);
					}
				}
				return false;
			}
		}

		public bool HaveBatchForm
		{
			get
			{
				if (base.AdbTopProvider != null)
				{
					string adsFlowsheetPathForStreamSummaryForms = GetAdsFlowsheetPathForStreamSummaryForms();
					if (!string.IsNullOrEmpty(adsFlowsheetPathForStreamSummaryForms))
					{
						if (!base.AdbTopProvider.IsBatchFlowsheet(adsFlowsheetPathForStreamSummaryForms))
						{
							return base.AdbTopProvider.HaveBatchFlowsheetInBlocks();
						}
						return true;
					}
				}
				return false;
			}
		}

		public string BatchTabHelpFile
		{
			get
			{
				string text = ExpandDataPath("@main");
				if (!text.Contains(".Results Summary.") && !text.EndsWith(".Results Summary", StringComparison.InvariantCultureIgnoreCase) && !text.Contains(".Streams."))
				{
					string dataPath = text;
					if (text.EndsWith("Stream Results", StringComparison.InvariantCultureIgnoreCase))
					{
						dataPath = text.Substring(0, text.Length - ".Stream Results".Length);
					}
					if (string.Equals(CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "type")), "BatchOp", StringComparison.InvariantCultureIgnoreCase))
					{
						return "Common.chm";
					}
				}
				return "Results.chm";
			}
		}

		public int BatchTabHelpId
		{
			get
			{
				string text = ExpandDataPath("@main");
				if (!text.Contains(".Results Summary.") && !text.EndsWith(".Results Summary", StringComparison.InvariantCultureIgnoreCase) && !text.Contains(".Streams."))
				{
					string dataPath = text;
					if (text.EndsWith("Stream Results", StringComparison.InvariantCultureIgnoreCase))
					{
						dataPath = text.Substring(0, text.Length - ".Stream Results".Length);
					}
					if (string.Equals(CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "type")), "BatchOp", StringComparison.InvariantCultureIgnoreCase))
					{
						return 1000;
					}
				}
				return 1001;
			}
		}

		protected override void OnViewChanged()
		{
			base.ResolvedCxsProvider.Case.Message += Case_Message;
			base.OnViewChanged();
		}

		public override void OnViewClosed()
		{
			if (base.ResolvedCxsProvider != null && base.ResolvedCxsProvider.Case != null)
			{
				base.ResolvedCxsProvider.Case.Message -= Case_Message;
			}
			base.OnViewClosed();
		}

		private void Case_Message(object sender, CxsMessageEventArgs e)
		{
			foreach (CxsMessage message in e.Messages)
			{
				if (message.MessageType == CxsMessageType.RunStarted)
				{
					if (UIDispatcher == null || Dispatcher.CurrentDispatcher == UIDispatcher)
					{
						IsSimulating = true;
						OnSimulationRunStarted();
						continue;
					}
					UIDispatcher.BeginInvoke((Action)delegate
					{
						IsSimulating = true;
						OnSimulationRunStarted();
					});
				}
				else
				{
					if (message.MessageType != CxsMessageType.RunPaused && message.MessageType != CxsMessageType.RunFailed && message.MessageType != CxsMessageType.RunCompleted)
					{
						continue;
					}
					if (UIDispatcher == null || Dispatcher.CurrentDispatcher == UIDispatcher)
					{
						IsSimulating = false;
						OnSimulationRunFinished();
						continue;
					}
					UIDispatcher.BeginInvoke((Action)delegate
					{
						IsSimulating = false;
						OnSimulationRunFinished();
					});
				}
			}
		}

		public virtual void OnSimulationRunStarted()
		{
		}

		public virtual void OnSimulationRunFinished()
		{
		}

		protected void RefreshMaterialFormStatus()
		{
			if (base.ResolvedCxsProvider.Case != null)
			{
				if (base.ResolvedCxsProvider.Case.Solver != null && base.ResolvedCxsProvider.Case.Solver.RunState == CxsSolverRunState.Running && CanEnableUIThreadInEngSim == true)
				{
					IsMaterialFormAccessible = true;
				}
				else
				{
					IsMaterialFormAccessible = HasMaterialResultsToDisplay;
				}
			}
			else
			{
				IsMaterialFormAccessible = false;
			}
		}

		protected override void OnViewUpdateDisplayEvent()
		{
			OnPropertyChanged("IsBatchFormAccessible");
			base.OnViewUpdateDisplayEvent();
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum
{
	public class MMUtil_Summary_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.UTIL_TYPE"
		});

		public static readonly CxvPropertyDeclaration var2_Property = CxvPropertyDeclaration.Register("var2", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NET_DUTY"
		});

		public static readonly CxvPropertyDeclaration var3_Property = CxvPropertyDeclaration.Register("var3", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
		});

		public static readonly CxvPropertyDeclaration hier_id_Property = CxvPropertyDeclaration.Register("hier_id", typeof(MMUtil_Summary_ViewModel), new CxvParameterProperty
		{
			Parameter = "hier_id"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMUtil_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@var2", "@var3" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMUtil_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@var1" }
		});

		public object var1 => GetValue(var1_Property);

		public object var2 => GetValue(var2_Property);

		public object var3 => GetValue(var3_Property);

		public object hier_id => GetValue(hier_id_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMUtil_Sum.MMUtil_Summary")]
	public class MMUtil_Summary : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		private bool _contentLoaded;

		public MMUtil_Summary()
		{
			base.ViewModelType = typeof(MMUtil_Summary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/utility-sum/mmutil_summary.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMTabStrip1 = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab1 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMUtil_Summary_Overview_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_HEAT_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_HEAT_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMTextBox9_var1_Property = CxvPropertyDeclaration.Register("MMTextBox9_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_COOL_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMTextBox10_var1_Property = CxvPropertyDeclaration.Register("MMTextBox10_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NET_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_HEAT_COST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_COOL_COST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NET_COST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.FEEDSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.PRODSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_COOL_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NET_DUTY"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_HEAT_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOT_COOL_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NET_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText12_var1_Property = CxvPropertyDeclaration.Register("MMLBUText12_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.FEEDSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText11_var1_Property = CxvPropertyDeclaration.Register("MMLBUText11_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.PRODSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText13_var1_Property = CxvPropertyDeclaration.Register("MMLBUText13_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ELECPOWER"
		});

		public static readonly CxvPropertyDeclaration MMTextBox13_var1_Property = CxvPropertyDeclaration.Register("MMTextBox13_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ELECPOWER"
		});

		public static readonly CxvPropertyDeclaration MMLBUText14_var1_Property = CxvPropertyDeclaration.Register("MMLBUText14_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ELECCOST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox14_var1_Property = CxvPropertyDeclaration.Register("MMTextBox14_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ELECCOST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText15_var1_Property = CxvPropertyDeclaration.Register("MMLBUText15_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOTUTCOST"
		});

		public static readonly CxvPropertyDeclaration MMTextBox15_var1_Property = CxvPropertyDeclaration.Register("MMTextBox15_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TOTUTCOST"
		});

		public object MMLBUText9_var1 => GetValue(MMLBUText9_var1_Property);

		public object MMTextBox8_var1 => GetValue(MMTextBox8_var1_Property);

		public object MMTextBox9_var1 => GetValue(MMTextBox9_var1_Property);

		public object MMTextBox10_var1 => GetValue(MMTextBox10_var1_Property);

		public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

		public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

		public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

		public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

		public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

		public object MMTextBox7_var1 => GetValue(MMTextBox7_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText5_var1 => GetValue(MMLBUText5_var1_Property);

		public object MMLBUText6_var1 => GetValue(MMLBUText6_var1_Property);

		public object MMLBUText12_var1 => GetValue(MMLBUText12_var1_Property);

		public object MMLBUText11_var1 => GetValue(MMLBUText11_var1_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMLBUText13_var1 => GetValue(MMLBUText13_var1_Property);

		public object MMTextBox13_var1 => GetValue(MMTextBox13_var1_Property);

		public object MMLBUText14_var1 => GetValue(MMLBUText14_var1_Property);

		public object MMTextBox14_var1 => GetValue(MMTextBox14_var1_Property);

		public object MMLBUText15_var1 => GetValue(MMLBUText15_var1_Property);

		public object MMTextBox15_var1 => GetValue(MMTextBox15_var1_Property);
	}
	[ProgId("MMUtil_Sum.MMUtil_Summary_Overview")]
	public class MMUtil_Summary_Overview : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaManualLayout MMScrollArea2;

		private bool _contentLoaded;

		public MMUtil_Summary_Overview()
		{
			base.ViewModelType = typeof(MMUtil_Summary_Overview_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/utility-sum/mmutil_summary_overview.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				MMScrollArea2 = (MMScrollAreaManualLayout)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMUtil_Summary_Sum_ViewModel : MMTabPageViewModel
	{
		public class grdUtlSum_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox22_var1_Property = CxvPropertyDeclaration.Register("MMTextBox22_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.BLKCO2RATE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox21_var1_Property = CxvPropertyDeclaration.Register("MMTextBox21_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMFACTOR.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox20_var1_Property = CxvPropertyDeclaration.Register("MMTextBox20_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMEFFICIENCY.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox17_var1_Property = CxvPropertyDeclaration.Register("MMTextBox17_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.ENTH_OUT.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox16_var1_Property = CxvPropertyDeclaration.Register("MMTextBox16_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.ENTH_IN.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox15_var1_Property = CxvPropertyDeclaration.Register("MMTextBox15_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Utility-Sum.Output.UTIL_TYPE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox14_var1_Property = CxvPropertyDeclaration.Register("MMTextBox14_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.UTIL_TYPE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.VFRAC.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox13_var1_Property = CxvPropertyDeclaration.Register("MMTextBox13_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.OUT_TEMP.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox12_var1_Property = CxvPropertyDeclaration.Register("MMTextBox12_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.IN_TEMP.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox11_var1_Property = CxvPropertyDeclaration.Register("MMTextBox11_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.TRATE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox10_var1_Property = CxvPropertyDeclaration.Register("MMTextBox10_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.DUTY.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox9_var1_Property = CxvPropertyDeclaration.Register("MMTextBox9_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.HCOOL.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.OUT_PRES.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.IN_PRES.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.IN_VF.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.ENERGY_PRICE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.ELEC_PRICE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.PPRICE.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.TCOST.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox19_var1_Property = CxvPropertyDeclaration.Register("MMTextBox19_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMFUELTYPE.@x",
				ExposeAs = CxvVariableTypeCode.String
			});

			public static readonly CxvPropertyDeclaration MMTextBox18_var1_Property = CxvPropertyDeclaration.Register("MMTextBox18_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMDATASOURCE.@x",
				ExposeAs = CxvVariableTypeCode.String
			});

			public static readonly CxvPropertyDeclaration CO2EmissionScope_var1_Property = CxvPropertyDeclaration.Register("CO2EmissionScope_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMSCOPE.@x",
				ExposeAs = CxvVariableTypeCode.String
			});

			public static readonly CxvPropertyDeclaration CO2AdjustmentFactor_var1_Property = CxvPropertyDeclaration.Register("CO2AdjustmentFactor_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.EMADJFACTOR.@x"
			});

			public object MMTextBox22_var1 => GetValue(MMTextBox22_var1_Property);

			public object MMTextBox21_var1 => GetValue(MMTextBox21_var1_Property);

			public object MMTextBox20_var1 => GetValue(MMTextBox20_var1_Property);

			public object MMTextBox17_var1 => GetValue(MMTextBox17_var1_Property);

			public object MMTextBox16_var1 => GetValue(MMTextBox16_var1_Property);

			public object MMTextBox15_var1 => GetValue(MMTextBox15_var1_Property);

			public object MMTextBox14_var1 => GetValue(MMTextBox14_var1_Property);

			public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

			public object MMTextBox13_var1 => GetValue(MMTextBox13_var1_Property);

			public object MMTextBox12_var1 => GetValue(MMTextBox12_var1_Property);

			public object MMTextBox11_var1 => GetValue(MMTextBox11_var1_Property);

			public object MMTextBox10_var1 => GetValue(MMTextBox10_var1_Property);

			public object MMTextBox9_var1 => GetValue(MMTextBox9_var1_Property);

			public object MMTextBox8_var1 => GetValue(MMTextBox8_var1_Property);

			public object MMTextBox7_var1 => GetValue(MMTextBox7_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMTextBox19_var1 => GetValue(MMTextBox19_var1_Property);

			public object MMTextBox18_var1 => GetValue(MMTextBox18_var1_Property);

			public object CO2EmissionScope_var1 => GetValue(CO2EmissionScope_var1_Property);

			public object CO2AdjustmentFactor_var1 => GetValue(CO2AdjustmentFactor_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText15_var1_Property = CxvPropertyDeclaration.Register("MMLBUText15_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.BLKCO2RATE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText14_var1_Property = CxvPropertyDeclaration.Register("MMLBUText14_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.EMFACTOR"
		});

		public static readonly CxvPropertyDeclaration MMLBUText13_var1_Property = CxvPropertyDeclaration.Register("MMLBUText13_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ENTH_IN"
		});

		public static readonly CxvPropertyDeclaration MMLBUText12_var1_Property = CxvPropertyDeclaration.Register("MMLBUText12_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ENTH_OUT"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.PPRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText11_var1_Property = CxvPropertyDeclaration.Register("MMLBUText11_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.OUT_PRES"
		});

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.IN_PRES"
		});

		public static readonly CxvPropertyDeclaration MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.OUT_TEMP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.IN_TEMP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TRATE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.DUTY"
		});

		public static readonly CxvPropertyDeclaration MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.HCOOL"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.TCOST"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ENERGY_PRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.ELEC_PRICE"
		});

		public static readonly CxvPropertyDeclaration grdUtlSum_GridData_Property = CxvPropertyDeclaration.Register("grdUtlSum_GridData", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdUtlSum_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Utility-Sum.Output.UTIL_TYPE",
				UseChildId = true,
				Name = "x"
			}
		});

		public object MMLBUText15_var1 => GetValue(MMLBUText15_var1_Property);

		public object MMLBUText14_var1 => GetValue(MMLBUText14_var1_Property);

		public object MMLBUText13_var1 => GetValue(MMLBUText13_var1_Property);

		public object MMLBUText12_var1 => GetValue(MMLBUText12_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText11_var1 => GetValue(MMLBUText11_var1_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMLBUText9_var1 => GetValue(MMLBUText9_var1_Property);

		public object MMLBUText8_var1 => GetValue(MMLBUText8_var1_Property);

		public object MMLBUText7_var1 => GetValue(MMLBUText7_var1_Property);

		public object MMLBUText6_var1 => GetValue(MMLBUText6_var1_Property);

		public object MMLBUText5_var1 => GetValue(MMLBUText5_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object grdUtlSum_GridData => GetValue(grdUtlSum_GridData_Property);
	}
	[ProgId("MMUtil_Sum.MMUtil_Summary_Sum")]
	public class MMUtil_Summary_Sum : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaHorizontal grdUtlSum;

		private bool _contentLoaded;

		public MMUtil_Summary_Sum()
		{
			base.ViewModelType = typeof(MMUtil_Summary_Sum_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/utility-sum/mmutil_summary_sum.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				grdUtlSum = (MMScrollAreaHorizontal)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum
{
	public class MMStreamSum_Summar_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Sum.Stream-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRVWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "stream"
		});

		public static readonly CxvPropertyDeclaration load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP"
		});

		public static readonly CxvPropertyDeclaration load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.duty"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@load1", "@load2" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro31", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8",
				"@petro9"
			}
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration main_summar_Property = CxvPropertyDeclaration.Register("main_summar", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summar"
		});

		public static readonly CxvPropertyDeclaration tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@main_summar.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM" }
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Sum.Load-Sum.Output"
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summar.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object power1 => GetValue(power1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object stream => GetValue(stream_Property);

		public object load1 => GetValue(load1_Property);

		public object load2 => GetValue(load2_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab9_var => GetValue(tab9_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object main_summar => GetValue(main_summar_Property);

		public object tab8_var => GetValue(tab8_var_Property);

		public object loadsum => GetValue(loadsum_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		public override bool HasMaterialResultsToDisplay
		{
			get
			{
				string text = ExpandDataPath("@main");
				string hierPath = (text.EndsWith(".Results Summary") ? text.Substring(0, text.Length - ".Results Summary".Length) : text);
				return HasMaterialResultsInHierarchy(hierPath);
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summar", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summar", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summar", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summar", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summar", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}

		private bool HasMaterialResultsInHierarchy(string hierPath)
		{
			string[] array = CxsConverter.ValueToStringArray(base.ResolvedCxsProvider.Case.BatchGet(hierPath + ".Streams", "child_ids"));
			if (array != null && array.Length != 0)
			{
				string[] array2 = array;
				foreach (string text in array2)
				{
					if (!(CxsConverter.ValueToString(base.ResolvedCxsProvider.Case.BatchGet(hierPath + ".Streams." + text, "type")) == "POWER"))
					{
						string path = hierPath + ".Streams." + text + ".Stream Results.Table";
						if (CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.Case.BatchGet(path, "value")) == true)
						{
							return true;
						}
					}
				}
				return false;
			}
			string[] array3 = CxsConverter.ValueToStringArray(base.ResolvedCxsProvider.Case.BatchGet(hierPath + ".Blocks", "child_ids"));
			if (array3 != null)
			{
				string[] array2 = array3;
				foreach (string text2 in array2)
				{
					string text3 = hierPath + ".Blocks." + text2;
					string text4 = text3 + ".Data";
					if (CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.Case.BatchGet(text4, "has_children")) == true)
					{
						if (HasMaterialResultsInHierarchy(text4))
						{
							return true;
						}
					}
					else if (CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.Case.BatchGet(text3 + ".Stream Results.Table", "value")) == true)
					{
						return true;
					}
				}
			}
			return false;
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar")]
	public class MMStreamSum_Summar : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab9;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tab8;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMStreamSum_Summar()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMStreamSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab9 = (MMTabItem)target;
				break;
			case 6:
				tab4 = (MMTabItem)target;
				break;
			case 7:
				tab5 = (MMTabItem)target;
				break;
			case 8:
				tab6 = (MMTabItem)target;
				break;
			case 9:
				tab7 = (MMTabItem)target;
				break;
			case 10:
				tab8 = (MMTabItem)target;
				break;
			case 11:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMStreamSum_Summar_Heat_ViewModel : MMTabPageViewModel
	{
		public class grdHeat_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@houtp.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@houtp.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@houtp.#4.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@houtp.#3.@col"
			});

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object cboSubstr_var1 => GetValue(cboSubstr_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstr_var1_Property && subPropertyName == "Value" && cboSubstr_var1 != null)
				{
					CxvCustomTooltipProperty obj = (cboSubstr_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdHeat_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat-Sum.Table.#8.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Heat-Sum.Table.#3.@col"
			});

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

			public object MMTextBox7_var1 => GetValue(MMTextBox7_var1_Property);

			public object cboSubstr_var1 => GetValue(cboSubstr_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstr_var1_Property && subPropertyName == "Value" && cboSubstr_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstr_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration houtp_Property = CxvPropertyDeclaration.Register("houtp", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@houtp.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@houtp.#4"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@houtp.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat-Sum.Table.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox6Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat-Sum.Table.#7"
		});

		public static readonly CxvPropertyDeclaration MMTextBox7Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat-Sum.Table.#8"
		});

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Heat-Sum.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "All hierarchy streams",
					DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
					Value = "cboDisplay_MultiMapOption_3",
					Prompt = "Display all hierarchy streams",
					PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLHIERSTREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@houtp",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData2_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Heat-Sum.Table.#0",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object houtp => GetValue(houtp_Property);

		public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object MMTextBox6Lab_var1 => GetValue(MMTextBox6Lab_var1_Property);

		public object MMTextBox7Lab_var1 => GetValue(MMTextBox7Lab_var1_Property);

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object grdHeat_GridData => GetValue(grdHeat_GridData_Property);

		public object grdHeat_GridData2 => GetValue(grdHeat_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main.Heat-Sum.Table");
				if (text != null)
				{
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
					if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Heat-Sum.Table.#6", "id"))))
					{
						RegularVisibility = Visibility.Visible;
						BatchVisibility = Visibility.Collapsed;
					}
					else
					{
						RegularVisibility = Visibility.Collapsed;
						BatchVisibility = Visibility.Visible;
					}
				}
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == grdHeat_GridData && subPropertyName == "Count" && !base.IsUnloaded && grdHeat_GridData is CxvVectorPropertyData { Count: >0 })
			{
				base.ResolvedCxsProvider.UpdateDataCache();
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Heat")]
	public class MMStreamSum_Summar_Heat : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal LocalMMScrollArea grdHeat;

		internal MMScrollAreaHorizontal grdHeat2;

		private bool _contentLoaded;

		public MMStreamSum_Summar_Heat()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Heat_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_heat.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdHeat = (LocalMMScrollArea)target;
				break;
			case 4:
				grdHeat2 = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class LocalMMScrollArea : MMScrollAreaHorizontal
	{
		private Point _currentCell;

		protected override void DataGrid_CellActivated(object sender, CellActivatedEventArgs e)
		{
			_currentCell.X = e.Cell.Record.Index;
			_currentCell.Y = e.Cell.Field.Index;
			base.DataGrid_CellActivated(sender, e);
		}

		protected override void RestoreActivePositionAfterReset(bool shouldStartEditMode)
		{
			base.Dispatcher.BeginInvoke(DispatcherPriority.Input, (Action)delegate
			{
				try
				{
					base.DataGrid.ActiveCell = (base.DataGrid.Records[(int)_currentCell.X] as DataRecord).Cells[(int)_currentCell.Y];
					base.DataGrid.ActiveCell.IsActive = true;
				}
				catch
				{
				}
			});
		}
	}
	public class MMStreamSum_Summar_Load_ViewModel : MMTabPageViewModel
	{
		public class grdLoad_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream-Sum.Load-Sum.Output.DUTY.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream.@row"
			});

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvAdvCollectionTooltipProperty
		{
			DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP",
			CreateNewPrompt = "Stream name:",
			CreateNewPromptResourceKey = "MMStreamSum_Summar_Load_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_name_"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Sum.Load-Sum.Output.DUTY.@stream"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream"
		});

		public static readonly CxvPropertyDeclaration grdLoad_GridData_Property = CxvPropertyDeclaration.Register("grdLoad_GridData", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLoad_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream",
				UseChildId = true,
				Name = "row"
			}
		});

		public object MMAdvCombo1_var1 => GetValue(MMAdvCombo1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object grdLoad_GridData => GetValue(grdLoad_GridData_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == MMAdvCombo1_var1_Property && subPropertyName == "Items" && MMAdvCombo1_var1 != null)
			{
				((MMAdvCombo1_var1 as CxvAdvCollectionTooltipData).Property as CxvAdvCollectionTooltipProperty).LongNamePath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
			}
			else if (pd == MMAdvCombo1_var1_Property && subPropertyName == "SelectedItem" && MMAdvCombo1_var1 != null)
			{
				CxvAdvCollectionTooltipData cxvAdvCollectionTooltipData = MMAdvCombo1_var1 as CxvAdvCollectionTooltipData;
				ResolveUpdateParameter("stream", "\"" + cxvAdvCollectionTooltipData.SelectedItem + "\"");
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Load")]
	public class MMStreamSum_Summar_Load : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMScrollAreaMS grdLoad;

		private bool _contentLoaded;

		public MMStreamSum_Summar_Load()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Load_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_load.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMAdvCombo1_label = (MMLabel)target;
				break;
			case 2:
				MMAdvCombo1 = (MMComboEdit)target;
				break;
			case 3:
				grdLoad = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMStreamSum_Summar_Materi_ViewModel : MMTabPageViewModel
	{
		public class grdStreams_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdStreams_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@outp.#0",
					UseChildId = true,
					Name = "col"
				}
			});

			public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@outp.@row",
				IsCalculated = true
			});

			public object inner => GetValue(inner_Property);

			public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);
		}

		public class grdStreams_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "col"
			});

			public static readonly CxvPropertyDeclaration txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@outp.@row.@col"
			});

			public object cboStreams_var1 => GetValue(cboStreams_var1_Property);

			public object txtTable_var1 => GetValue(txtTable_var1_Property);
		}

		public class GridData_Column_ViewModel : MMViewModel
		{
			public static CxvPropertyDeclaration Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
			{
				DataPath = "@outp.#0.@z",
				ExposeAs = CxvVariableTypeCode.IdWithOptions
			});

			public object Uom => GetValue(Uom_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == Uom_Property && subPropertyName == "Value" && Uom != null)
				{
					CxvCustomTooltipProperty obj = (Uom as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		private ICommand _cbtStreamTable_Command;

		public static CxvPropertyDeclaration cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvLogicalProperty
		{
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Stream-Sum.Stream-Sum.Table.#0",
					DataAttribute = "child_count",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 1
				}
			}
		});

		public static readonly CxvPropertyDeclaration outp_Property = CxvPropertyDeclaration.Register("outp", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Sum.Stream-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Stream-Sum.Stream-Sum.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Hierarchy streams",
					DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Hierarchy_streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Display this and child hierarchy streams",
					PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_this_and_child_hierarchy_strea",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLHIERSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_3",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Stream-Sum.Stream-Sum.TFF File",
			Sorted = true
		});

		public static CxvPropertyDeclaration GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVectorProperty
		{
			IndexBasis = new CxvChildCountIndexBasis
			{
				Name = "z",
				DataPath = "@outp.#0",
				UseChildId = false
			},
			ItemType = typeof(GridData_Column_ViewModel)
		});

		public static readonly CxvPropertyDeclaration grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreams_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@outp",
				UseChildId = false,
				Name = "row"
			}
		});

		private ICommand _copyAll_Command;

		public ICommand cbtStreamTable_Command
		{
			get
			{
				if (_cbtStreamTable_Command == null)
				{
					_cbtStreamTable_Command = new CxvDelegateCommand<object>(cbtStreamTable_CommandExecute, this, cbtStreamTable_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cbtStreamTable_Command;
			}
		}

		public CxvLogicalPropertyData cbtStreamTable_CommandCanExecute => GetValue(cbtStreamTable_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public object outp => GetValue(outp_Property);

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object cboFormat_var1 => GetValue(cboFormat_var1_Property);

		public object GridData_Column => GetValue(GridData_Column_Property);

		public object grdStreams_GridData => GetValue(grdStreams_GridData_Property);

		public ICommand CopyAll_Command
		{
			get
			{
				if (_copyAll_Command == null)
				{
					_copyAll_Command = new DelegateCommand<object>(copyAll_CommandExecute);
				}
				return _copyAll_Command;
			}
		}

		private void cbtStreamTable_CommandExecute(object parameter)
		{
			string path = CxsConverter.ValueToString(ExpandDataPath("@main.Stream-Sum.Stream-Sum"));
			Birdcage(hiearchical: true, path);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main.Stream-Sum.Stream-Sum.Table");
				if (text != null)
				{
					try
					{
						InvokeAction(text, "Query", false);
					}
					catch (Exception)
					{
					}
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
				}
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == GridData_Column_Property && subPropertyName == "Count" && !base.IsUnloaded && GridData_Column is CxvVectorPropertyData { Count: >0 })
			{
				base.ResolvedCxsProvider.UpdateDataCache();
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		private void copyAll_CommandExecute(object parameter)
		{
			string text = ResolveParameter("outp") as string;
			if (!string.IsNullOrEmpty(text))
			{
				base.ResolvedCxsProvider.InvokeAction(text, "ToClipboard", false);
			}
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Materi")]
	public class MMStreamSum_Summar_Materi : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMLabel cboFormat_label;

		internal MMComboEdit cboFormat;

		internal MMCmdButton cbtStreamTable;

		internal MMCmdButton cbtCopyAll;

		internal MMScrollAreaMS grdStreams;

		private bool _contentLoaded;

		public override bool CanPrint => true;

		public MMStreamSum_Summar_Materi()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Materi_ViewModel);
			InitializeComponent();
			grdStreams.DataCopying += grdStreams_DataCopying;
			grdStreams.PreparingCellValuesForCopy += grdStreams_PreparingCellValuesForCopy;
		}

		private void grdStreams_PreparingCellValuesForCopy(object sender, PreparingCellValuesEventArgs e)
		{
			if (base.ViewModel == null)
			{
				return;
			}
			foreach (DataCellInfo cell in e.Cells)
			{
				ProcessTraceCell(cell, base.ViewModel, e);
			}
		}

		private void ProcessTraceCell(DataCellInfo cell, CxvViewModel vm, PreparingCellValuesEventArgs e)
		{
			if (cell.Data == null || cell.Data.ValueType != typeof(string))
			{
				return;
			}
			string propPath = GetPropPath(cell);
			object obj = base.ViewModel.ResolveViewPropertyPath(propPath + ".AlternatePath");
			if (obj != null && !string.IsNullOrEmpty(obj.ToString()))
			{
				object obj2 = base.ViewModel.ResolvedCxsProvider.BatchGet(obj.ToString(), "value", null);
				if (obj2 != null && (obj2.GetType() == typeof(double) || obj2.GetType() == typeof(int)))
				{
					e.Values[cell] = obj2;
				}
			}
		}

		private string GetPropPath(DataCellInfo cell)
		{
			StringBuilder stringBuilder = new StringBuilder();
			int num = cell.Row.DataTable.Rows.IndexOf(cell.Row);
			stringBuilder.Append(grdStreams.DataProperty).Append("[").Append(num.ToString(CultureInfo.InvariantCulture))
				.Append("]");
			MMScrollAreaMSDataColumn mMScrollAreaMSDataColumn = cell.Column as MMScrollAreaMSDataColumn;
			if (mMScrollAreaMSDataColumn.Field == null)
			{
				return null;
			}
			if (!string.IsNullOrEmpty(mMScrollAreaMSDataColumn.Field.PropertyPath))
			{
				stringBuilder.Append(".").Append(mMScrollAreaMSDataColumn.Field.PropertyPath);
			}
			return stringBuilder.ToString();
		}

		private void grdStreams_DataCopying(object sender, MMScrollAreaDataCopyEventArgs e)
		{
			if (e.IsAllSelected)
			{
				(base.ViewModel as MMStreamSum_Summar_Materi_ViewModel).CopyAll_Command.Execute(null);
				e.Handled = true;
			}
		}

		public override IEnumerable<FrameworkElement> GeneratePrintPages(Size availablePrintSize)
		{
			return this.GenerateGenericPrintPages(grdStreams, availablePrintSize, 2, 1, "Results Summary Streams Material", ignoreLastColumn: true);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_materi.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				cboFormat_label = (MMLabel)target;
				break;
			case 4:
				cboFormat = (MMComboEdit)target;
				break;
			case 5:
				cbtStreamTable = (MMCmdButton)target;
				break;
			case 6:
				cbtCopyAll = (MMCmdButton)target;
				break;
			case 7:
				grdStreams = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMStreamSum_Summar_Power_ViewModel : MMTabPageViewModel
	{
		public class grdPower_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#3.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@poutp.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdPower_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@poutp.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@poutp.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Power-Sum.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "All hierarchy streams",
					DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
					Value = "cboDisplay_MultiMapOption_3",
					Prompt = "Display all hierarchy streams",
					PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLHIERSTREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration poutp_Property = CxvPropertyDeclaration.Register("poutp", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@poutp.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@poutp.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@poutp.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@poutp.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@poutp.#7"
		});

		public static readonly CxvPropertyDeclaration grdPower_GridData_Property = CxvPropertyDeclaration.Register("grdPower_GridData", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPower_GridData_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@poutp",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdPower_GridData2_Property = CxvPropertyDeclaration.Register("grdPower_GridData2", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPower_GridData2_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@poutp",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object poutp => GetValue(poutp_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object MMTextBox3Lab_var1 => GetValue(MMTextBox3Lab_var1_Property);

		public object MMTextBox4Lab_var1 => GetValue(MMTextBox4Lab_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object grdPower_GridData => GetValue(grdPower_GridData_Property);

		public object grdPower_GridData2 => GetValue(grdPower_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && ExpandDataPath("@main.Power-Sum.Table") != null)
			{
				if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Power-Sum.Table.#5", "id"))))
				{
					RegularVisibility = Visibility.Visible;
					BatchVisibility = Visibility.Collapsed;
				}
				else
				{
					RegularVisibility = Visibility.Collapsed;
					BatchVisibility = Visibility.Visible;
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Power")]
	public class MMStreamSum_Summar_Power : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdPower;

		private bool _contentLoaded;

		public MMStreamSum_Summar_Power()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Power_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_power.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdPower = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMStreamSum_Summar_Solids_ViewModel : MMTabPageViewModel
	{
		public class grdPSD_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtUpperLimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperLimit_var1", typeof(grdPSD_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPSD_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new MyCxvChildCountIndexBasis
				{
					DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
					UseChildId = true,
					Name = "col"
				}
			});

			public object txtUpperLimit_var1 => GetValue(txtUpperLimit_var1_Property);

			public object inner => GetValue(inner_Property);

			protected override void OnUpdateData()
			{
				OnPropertyChanged("inner");
				base.OnUpdateData();
			}

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "txtUpperLimit_var1")
				{
					_ = subPropertyName == "Value";
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdPSD_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "col"
			});

			public static readonly CxvPropertyDeclaration txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream.@col.@row"
			});

			public object cboStreams_var1 => GetValue(cboStreams_var1_Property);

			public object txtTable_var1 => GetValue(txtTable_var1_Property);
		}

		public class GridData_Column_ViewModel : MMViewModel
		{
			public static CxvPropertyDeclaration Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream.@z",
				ExposeAs = CxvVariableTypeCode.Id
			});

			public object Uom => GetValue(Uom_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == Uom_Property && subPropertyName == "Value" && Uom != null)
				{
					CxvCustomTooltipProperty obj = (Uom as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					string text = ExpandDataPath("@main");
					string descriptionPath = null;
					if (text.Contains("Results Summary"))
					{
						descriptionPath = text.Replace("Results Summary", "Streams.[Value]");
					}
					else
					{
						int num = text.LastIndexOf("Blocks.");
						if (num != -1)
						{
							descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						}
					}
					obj.DescriptionPath = descriptionPath;
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdPSDA_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration StreamID_var1_Property = CxvPropertyDeclaration.Register("StreamID_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream.@row",
				ExposeAs = CxvVariableTypeCode.Id
			});

			public static readonly CxvPropertyDeclaration D10_var1_Property = CxvPropertyDeclaration.Register("D10_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D20_var1_Property = CxvPropertyDeclaration.Register("D20_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D20.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D25_var1_Property = CxvPropertyDeclaration.Register("D25_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D50_var1_Property = CxvPropertyDeclaration.Register("D50_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D50.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D63_var1_Property = CxvPropertyDeclaration.Register("D63_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D63.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D75_var1_Property = CxvPropertyDeclaration.Register("D75_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D75.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D80_var1_Property = CxvPropertyDeclaration.Register("D80_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D80.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D90_var1_Property = CxvPropertyDeclaration.Register("D90_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D90.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D95_var1_Property = CxvPropertyDeclaration.Register("D95_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D95.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D100_var1_Property = CxvPropertyDeclaration.Register("D100_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D100.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D25D75_var1_Property = CxvPropertyDeclaration.Register("D25D75_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25D75.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration SMD_var1_Property = CxvPropertyDeclaration.Register("SMD_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SMD.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration SV_var1_Property = CxvPropertyDeclaration.Register("SV_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SV.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration D43_var1_Property = CxvPropertyDeclaration.Register("D43_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D43.@stream.@row"
			});

			public object StreamID_var1 => GetValue(StreamID_var1_Property);

			public object D10_var1 => GetValue(D10_var1_Property);

			public object D20_var1 => GetValue(D20_var1_Property);

			public object D25_var1 => GetValue(D25_var1_Property);

			public object D50_var1 => GetValue(D50_var1_Property);

			public object D63_var1 => GetValue(D63_var1_Property);

			public object D75_var1 => GetValue(D75_var1_Property);

			public object D80_var1 => GetValue(D80_var1_Property);

			public object D90_var1 => GetValue(D90_var1_Property);

			public object D95_var1 => GetValue(D95_var1_Property);

			public object D100_var1 => GetValue(D100_var1_Property);

			public object D25D75_var1 => GetValue(D25D75_var1_Property);

			public object SMD_var1 => GetValue(SMD_var1_Property);

			public object SV_var1 => GetValue(SV_var1_Property);

			public object D43_var1 => GetValue(D43_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "StreamID_var1" && subPropertyName == "Value" && StreamID_var1 != null)
				{
					CxvCustomTooltipProperty obj = (StreamID_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					string text = ExpandDataPath("@main");
					string descriptionPath = null;
					if (text.Contains("Results Summary"))
					{
						descriptionPath = text.Replace("Results Summary", "Streams.[Value]");
					}
					else
					{
						int num = text.LastIndexOf("Blocks.");
						if (num != -1)
						{
							descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						}
					}
					obj.DescriptionPath = descriptionPath;
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdMC_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtMC_var1_Property = CxvPropertyDeclaration.Register("txtMC_var1", typeof(grdMC_GridData_ItemTemplate), new CxvVariableProperty());

			public static readonly CxvPropertyDeclaration cboUnits2_var1_Property = CxvPropertyDeclaration.Register("cboUnits2_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty());

			public static readonly CxvPropertyDeclaration inner2_Property = CxvPropertyDeclaration.Register("inner2", typeof(grdMC_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream",
					UseChildId = true,
					Name = "col"
				}
			});

			public object txtMC_var1 => GetValue(txtMC_var1_Property);

			public object cboUnits2_var1 => GetValue(cboUnits2_var1_Property);

			public object inner2 => GetValue(inner2_Property);
		}

		public class grdMC_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "col"
			});

			public static readonly CxvPropertyDeclaration txtTable2_var1_Property = CxvPropertyDeclaration.Register("txtTable2_var1", typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream.@col.@row"
			});

			public object cboStreams_var1 => GetValue(cboStreams_var1_Property);

			public object txtTable2_var1 => GetValue(txtTable2_var1_Property);
		}

		public class GridData_Column2_ViewModel : MMViewModel
		{
			public static CxvPropertyDeclaration Uom2_Property = CxvPropertyDeclaration.Register("Uom2", typeof(GridData_Column2_ViewModel), new CxvCustomTooltipProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream.@z",
				ExposeAs = CxvVariableTypeCode.Id
			});

			public object Uom2 => GetValue(Uom2_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == Uom2_Property && subPropertyName == "Value" && Uom2 != null)
				{
					CxvCustomTooltipProperty obj = (Uom2 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					string text = ExpandDataPath("@main");
					string descriptionPath = null;
					if (text.Contains("Results Summary"))
					{
						descriptionPath = text.Replace("Results Summary", "Streams.[Value]");
					}
					else
					{
						int num = text.LastIndexOf("Blocks.");
						if (num != -1)
						{
							descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						}
					}
					obj.DescriptionPath = descriptionPath;
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdPSD_2_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtUpperLimit_2_var1_Property = CxvPropertyDeclaration.Register("txtUpperLimit_2_var1", typeof(grdPSD_2_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream.@row2"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPSD_2_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new MyCxvChildCountIndexBasis
				{
					DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
					UseChildId = true,
					Name = "col2"
				}
			});

			public object txtUpperLimit_2_var1 => GetValue(txtUpperLimit_2_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "col2"
			});

			public static readonly CxvPropertyDeclaration txtTable_2_var1_Property = CxvPropertyDeclaration.Register("txtTable_2_var1", typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream.@col2.@row2"
			});

			public object cboStreams_var1 => GetValue(cboStreams_var1_Property);

			public object txtTable_2_var1 => GetValue(txtTable_2_var1_Property);
		}

		public class GridData_Column_2_ViewModel : MMViewModel
		{
			public static CxvPropertyDeclaration Uom_2_Property = CxvPropertyDeclaration.Register("Uom_2", typeof(GridData_Column_2_ViewModel), new CxvCustomTooltipProperty
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream.@z",
				ExposeAs = CxvVariableTypeCode.Id
			});

			public object Uom_2 => GetValue(Uom_2_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == Uom_2_Property && subPropertyName == "Value" && Uom_2 != null)
				{
					CxvCustomTooltipProperty obj = (Uom_2 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					string text = ExpandDataPath("@main");
					string descriptionPath = null;
					if (text.Contains("Results Summary"))
					{
						descriptionPath = text.Replace("Results Summary", "Streams.[Value]");
					}
					else
					{
						int num = text.LastIndexOf("Blocks.");
						if (num != -1)
						{
							descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						}
					}
					obj.DescriptionPath = descriptionPath;
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class MyCxvChildCountIndexBasis : CxvChildCountIndexBasis
		{
			public override CxvIndexBasisBaseData CreateData(ICxvViewDataContainer dataContainer, CxvPropertyWatch dependencies)
			{
				return new MyCxvChildCountIndexBasisData(this, dataContainer);
			}
		}

		public class MyCxvChildCountIndexBasisData : CxvChildCountIndexBasisData
		{
			internal static IEnumerable<string> _selectedStreamIds;

			public MyCxvChildCountIndexBasisData(MyCxvChildCountIndexBasis indexBasis, ICxvViewDataContainer dataContainer)
				: base(indexBasis, dataContainer)
			{
			}

			protected override void SetChildIds(string childIds, CxvPropertyWatch dependencies)
			{
				string text = string.Empty;
				ICxvViewDataContainer dataContainer = base.DataContainer;
				if (dataContainer == null || dataContainer.ResolvedCxsProvider == null || string.IsNullOrEmpty(childIds))
				{
					return;
				}
				string text2 = dataContainer.ExpandDataPath("@main");
				if (string.IsNullOrEmpty(text2))
				{
					return;
				}
				if (text2.EndsWith("Results Summary"))
				{
					string[] array = CxsConverter.ValueToStringArray(dataContainer.ResolvedCxsProvider.BatchGet(base.DataContainer.ExpandDataPath("@main.Stream-Sum.Stream-Sum.Table.#0", dependencies), "child_ids", null));
					ICxsDataWatch cxsDataWatch = dataContainer.CreateCxsWatch();
					if (cxsDataWatch != null)
					{
						cxsDataWatch.AddWatch(base.DataContainer.ExpandDataPath("@main.Stream-Sum.Stream-Sum.Table.#0"), "child_ids");
						dependencies.AddWatch(cxsDataWatch);
					}
					IEnumerable<string> enumerable = _selectedStreamIds;
					if (enumerable == null && array != null)
					{
						enumerable = array.Where((string p) => !p.StartsWith("#", StringComparison.InvariantCulture));
					}
					if (enumerable != null)
					{
						string[] array2 = childIds.Split('\n');
						if (array2 == null || array2.Count() == 0 || enumerable == null || enumerable.Count() == 0)
						{
							base.SetChildIds(childIds, dependencies);
							return;
						}
						foreach (string item in enumerable)
						{
							if (array2.Contains(item))
							{
								text = text + item + "\n";
							}
						}
						if (string.IsNullOrEmpty(text))
						{
							base.SetChildIds(null, dependencies);
						}
						else if (text.Length > 1)
						{
							text = text.Substring(0, text.Length - 1);
							base.SetChildIds(text, dependencies);
						}
						else
						{
							base.SetChildIds(childIds, dependencies);
						}
					}
					else
					{
						base.SetChildIds(childIds, dependencies);
					}
				}
				else if (text2.Contains(".Blocks.") || text2.Contains(".Streams."))
				{
					string[] array3 = CxsConverter.ValueToStringArray(dataContainer.ResolvedCxsProvider.BatchGet(base.DataContainer.ExpandDataPath("@main.Stream Results.Table.#0", dependencies), "child_ids", null));
					ICxsDataWatch cxsDataWatch2 = dataContainer.CreateCxsWatch();
					if (cxsDataWatch2 != null)
					{
						cxsDataWatch2.AddWatch(base.DataContainer.ExpandDataPath("@main.Stream Results.Table.#0"), "child_ids");
						dependencies.AddWatch(cxsDataWatch2);
					}
					IEnumerable<string> enumerable2 = _selectedStreamIds;
					if (enumerable2 == null && array3 != null)
					{
						enumerable2 = array3.Where((string p) => !p.StartsWith("#", StringComparison.InvariantCulture));
					}
					if (enumerable2 != null)
					{
						string[] array4 = childIds.Split('\n');
						if (array4 == null || array4.Count() == 0)
						{
							base.SetChildIds(childIds, dependencies);
							return;
						}
						foreach (string item2 in enumerable2)
						{
							if (array4.Contains(item2))
							{
								text = text + item2 + "\n";
							}
						}
						if (string.IsNullOrEmpty(text))
						{
							base.SetChildIds(null, dependencies);
						}
						else if (text.Length > 1)
						{
							text = text.Substring(0, text.Length - 1);
							base.SetChildIds(text, dependencies);
						}
						else
						{
							base.SetChildIds(childIds, dependencies);
						}
					}
					else
					{
						base.SetChildIds(childIds, dependencies);
					}
				}
				else
				{
					base.SetChildIds(childIds, dependencies);
				}
			}

			internal void ResetChildIds(IEnumerable<string> streams)
			{
				_selectedStreamIds = streams;
				RefreshChildIds();
				OnCountChanged();
			}
		}

		public static readonly CxvPropertyDeclaration main_solid_Property = CxvPropertyDeclaration.Register("main_solid", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_solid"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var2_Property = CxvPropertyDeclaration.Register("MMComboBox1_var2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
		{
			Parameter = "stream"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM",
			SelectedItemBinding = "MMComboBox1_var2.Value"
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_var2_Property = CxvPropertyDeclaration.Register("MMComboBox2_var2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
		{
			Parameter = "sub"
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvPropertySelector
		{
			Choices = 
			{
				new CxvPropertyChoice
				{
					Property = new CxvAdvCollectionProperty
					{
						UseItemsCollection = true,
						Items = 
						{
							new CxvAdvCollectionItem
							{
								Display = "PSD Averages",
								DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_MMComboBox2_var1_CxvAdvCollectionItem2"
							},
							new CxvAdvCollectionItem
							{
								Display = "PSD(Particle size distribution)",
								DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_MMComboBox2_var1_CxvAdvCollectionItem1"
							}
						},
						SelectedItemBinding = "MMComboBox2_var2.Value"
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration ogrOption1_MultiMap_Property = CxvPropertyDeclaration.Register("ogrOption1_MultiMap", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrOption1_var1",
					Parameter = "opt1"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Fractions",
					DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption1_MultiMapOption_1",
					Value = "ogrOption1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrOption1_var1",
							Value = "SUBS-ATTR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cumulate fractions",
					DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption1_MultiMapOption_2",
					Value = "ogrOption1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrOption1_var1",
							Value = "TOTAL"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				Parameter = "sub",
				Value = "PSD(Particle size distribution)"
			}
		});

		public static readonly CxvPropertyDeclaration ogrOption2_MultiMap_Property = CxvPropertyDeclaration.Register("ogrOption2_MultiMap", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrOption2_var1",
					Parameter = "opt2"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Wet basis",
					DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption2_MultiMapOption_1",
					Value = "ogrOption2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrOption2_var1",
							Value = "WET"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Dry basis",
					DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption2_MultiMapOption_2",
					Value = "ogrOption2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrOption2_var1",
							Value = "DRY"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				Parameter = "sub",
				Value = "Moisture Content"
			}
		});

		public static readonly CxvPropertyDeclaration grdPSD_GridData_Property = CxvPropertyDeclaration.Register("grdPSD_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPSD_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream",
				UseChildId = true,
				Name = "row"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "PSD_1_Visible.Value"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				PropertyPath = "PSD_1_Enable.Value"
			}
		});

		public static readonly CxvPropertyDeclaration txtUnit_var1_Property = CxvPropertyDeclaration.Register("txtUnit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static CxvPropertyDeclaration GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			IndexBasis = new MyCxvChildCountIndexBasis
			{
				Name = "z",
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
				UseChildId = true
			},
			ItemType = typeof(GridData_Column_ViewModel)
		});

		public static readonly CxvPropertyDeclaration grdPSDA_GridData_Property = CxvPropertyDeclaration.Register("grdPSDA_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPSDA_GridData_ItemTemplate),
			IndexBasis = new MyCxvChildCountIndexBasis
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream",
				UseChildId = true,
				Name = "row"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "PSDA_Visible.Value"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				PropertyPath = "PSDA_Enable.Value"
			}
		});

		public static readonly CxvPropertyDeclaration grdMC_GridData_Property = CxvPropertyDeclaration.Register("grdMC_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdMC_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				UseChildId = true,
				Name = "row"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "MC_Visible.Value"
			}
		});

		public static CxvPropertyDeclaration GridData_Column2_Property = CxvPropertyDeclaration.Register("GridData_Column2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			IndexBasis = new MyCxvChildCountIndexBasis
			{
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
				UseChildId = true,
				Name = "col"
			},
			ItemType = typeof(GridData_Column2_ViewModel)
		});

		public static readonly CxvPropertyDeclaration D10Unit_var1_Property = CxvPropertyDeclaration.Register("D10Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10"
		});

		public static readonly CxvPropertyDeclaration D20Unit_var1_Property = CxvPropertyDeclaration.Register("D20Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D20"
		});

		public static readonly CxvPropertyDeclaration D25Unit_var1_Property = CxvPropertyDeclaration.Register("D25Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25"
		});

		public static readonly CxvPropertyDeclaration D50Unit_var1_Property = CxvPropertyDeclaration.Register("D50Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D50"
		});

		public static readonly CxvPropertyDeclaration D63Unit_var1_Property = CxvPropertyDeclaration.Register("D63Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D63"
		});

		public static readonly CxvPropertyDeclaration D75Unit_var1_Property = CxvPropertyDeclaration.Register("D75Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D75"
		});

		public static readonly CxvPropertyDeclaration D80Unit_var1_Property = CxvPropertyDeclaration.Register("D80Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D80"
		});

		public static readonly CxvPropertyDeclaration D90Unit_var1_Property = CxvPropertyDeclaration.Register("D90Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D90"
		});

		public static readonly CxvPropertyDeclaration D95Unit_var1_Property = CxvPropertyDeclaration.Register("D95Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D95"
		});

		public static readonly CxvPropertyDeclaration D100Unit_var1_Property = CxvPropertyDeclaration.Register("D100Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D100"
		});

		public static readonly CxvPropertyDeclaration SMDUnit_var1_Property = CxvPropertyDeclaration.Register("SMDUnit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SMD"
		});

		public static readonly CxvPropertyDeclaration SVUnit_var1_Property = CxvPropertyDeclaration.Register("SVUnit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SV"
		});

		public static readonly CxvPropertyDeclaration D43Unit_var1_Property = CxvPropertyDeclaration.Register("D43Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D43"
		});

		private static CxvPropertyDeclaration PSD_1_Visible_Property = CxvPropertyDeclaration.Register("PSD_1_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "PSD(Particle size distribution)"
				}
			}
		});

		private static CxvPropertyDeclaration PSD_1_Enable_Property = CxvPropertyDeclaration.Register("PSD_1_Enable", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "PSD(Particle size distribution)"
				},
				new CxvLogicalTest
				{
					DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
					DataAttribute = "child_count",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = "0"
				}
			}
		});

		private static CxvPropertyDeclaration PSD_2_Visible_Property = CxvPropertyDeclaration.Register("PSD_2_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "PSD(Particle size distribution)"
				},
				new CxvLogicalTest
				{
					Parameter = "opt1",
					Value = "TOTAL"
				}
			}
		});

		private static CxvPropertyDeclaration PSDA_Visible_Property = CxvPropertyDeclaration.Register("PSDA_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "PSD Averages"
				}
			}
		});

		private static CxvPropertyDeclaration PSDA_Enable_Property = CxvPropertyDeclaration.Register("PSDA_Enable", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "PSD Averages"
				},
				new CxvLogicalTest
				{
					DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
					DataAttribute = "child_count",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = "0"
				}
			}
		});

		private static CxvPropertyDeclaration MC_Visible_Property = CxvPropertyDeclaration.Register("MC_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "sub",
					Value = "Moisture Content"
				}
			}
		});

		public static readonly CxvPropertyDeclaration txtUnit_2_var1_Property = CxvPropertyDeclaration.Register("txtUnit_2_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static CxvPropertyDeclaration GridData_Column_2_Property = CxvPropertyDeclaration.Register("GridData_Column_2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
		{
			IndexBasis = new MyCxvChildCountIndexBasis
			{
				Name = "z",
				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
				UseChildId = true
			},
			ItemType = typeof(GridData_Column_2_ViewModel)
		});

		public object main_solid => GetValue(main_solid_Property);

		public object MMComboBox1_var2 => GetValue(MMComboBox1_var2_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object MMComboBox2_var2 => GetValue(MMComboBox2_var2_Property);

		public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

		public object ogrOption1_MultiMap => GetValue(ogrOption1_MultiMap_Property);

		public object ogrOption2_MultiMap => GetValue(ogrOption2_MultiMap_Property);

		public object grdPSD_GridData => GetValue(grdPSD_GridData_Property);

		public object txtUnit_var1 => GetValue(txtUnit_var1_Property);

		public object GridData_Column => GetValue(GridData_Column_Property);

		public object grdPSDA_GridData => GetValue(grdPSDA_GridData_Property);

		public object grdMC_GridData => GetValue(grdMC_GridData_Property);

		public object GridData_Column2 => GetValue(GridData_Column2_Property);

		public object D10Unit_var1 => GetValue(D10Unit_var1_Property);

		public object D20Unit_var1 => GetValue(D20Unit_var1_Property);

		public object D25Unit_var1 => GetValue(D25Unit_var1_Property);

		public object D50Unit_var1 => GetValue(D50Unit_var1_Property);

		public object D63Unit_var1 => GetValue(D63Unit_var1_Property);

		public object D75Unit_var1 => GetValue(D75Unit_var1_Property);

		public object D80Unit_var1 => GetValue(D80Unit_var1_Property);

		public object D90Unit_var1 => GetValue(D90Unit_var1_Property);

		public object D95Unit_var1 => GetValue(D95Unit_var1_Property);

		public object D100Unit_var1 => GetValue(D100Unit_var1_Property);

		public object SMDUnit_var1 => GetValue(SMDUnit_var1_Property);

		public object SVUnit_var1 => GetValue(SVUnit_var1_Property);

		public object D43Unit_var1 => GetValue(D43Unit_var1_Property);

		public string L0 => ApwnResources.MMStreamSum_Summar_Solids_PSDProperty + "\t";

		public string L1 => "D10\t" + ResolveUnitForGlobalUnitSet(D10Unit_var1);

		public string L2 => "D20\t" + ResolveUnitForGlobalUnitSet(D20Unit_var1);

		public string L3 => "D25\t" + ResolveUnitForGlobalUnitSet(D25Unit_var1);

		public string L4 => "D50\t" + ResolveUnitForGlobalUnitSet(D50Unit_var1);

		public string L5 => "D63\t" + ResolveUnitForGlobalUnitSet(D63Unit_var1);

		public string L6 => "D75\t" + ResolveUnitForGlobalUnitSet(D75Unit_var1);

		public string L7 => "D80\t" + ResolveUnitForGlobalUnitSet(D80Unit_var1);

		public string L8 => "D90\t" + ResolveUnitForGlobalUnitSet(D90Unit_var1);

		public string L9 => "D25:D75\t";

		public string L10 => "SMD\t" + ResolveUnitForGlobalUnitSet(SMDUnit_var1);

		public string L11 => "VSSA\t" + ResolveUnitForGlobalUnitSet(SVUnit_var1);

		public string L12 => "D[4,3]\t" + ResolveUnitForGlobalUnitSet(D43Unit_var1);

		public string L13 => "D95\t" + ResolveUnitForGlobalUnitSet(D95Unit_var1);

		public string L14 => "D100\t" + ResolveUnitForGlobalUnitSet(D100Unit_var1);

		public object PSD_1_Visible => GetValue(PSD_1_Visible_Property);

		public object PSD_1_Enable => GetValue(PSD_1_Enable_Property);

		public object PSD_2_Visible => GetValue(PSD_2_Visible_Property);

		public object PSDA_Visible => GetValue(PSDA_Visible_Property);

		public object PSDA_Enable => GetValue(PSDA_Enable_Property);

		public object MC_Visible => GetValue(MC_Visible_Property);

		public object txtUnit_2_var1 => GetValue(txtUnit_2_var1_Property);

		public object GridData_Column_2 => GetValue(GridData_Column_2_Property);

		protected override void OnViewChanged()
		{
			IEventAggregator eventAggregator = base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			eventAggregator.GetEvent<MaterialFormColumnsChangedEvent>().Subscribe(OnMaterialFormColumnsChanged);
			MaterialFormColumnsQueryEventArgs e = new MaterialFormColumnsQueryEventArgs();
			eventAggregator.GetEvent<MaterialFormColumnsQueryEvent>().Publish(e);
			UpdateDisplayedStreams(e.DisplayedStreamIds);
			base.OnViewChanged();
		}

		private void OnMaterialFormColumnsChanged(MaterialFormColumnsChangedEventArgs args)
		{
			UpdateDisplayedStreams(args.DisplayedStreamIds);
		}

		private void UpdateDisplayedStreams(IEnumerable<string> ids)
		{
			List<string> streamIds = new List<string>();
			if (ids != null)
			{
				foreach (string id in ids)
				{
					int num = id.LastIndexOf(".");
					if (num >= 0)
					{
						string item = id.Substring(num + 1);
						if (!streamIds.Contains(item))
						{
							streamIds.Add(item);
						}
					}
					else if (!streamIds.Contains(id))
					{
						streamIds.Add(id);
					}
				}
			}
			if (!(base.View is MMTabPage mMTabPage))
			{
				return;
			}
			mMTabPage.Dispatcher.BeginInvoke((Action)delegate
			{
				if (streamIds != null)
				{
					if (grdPSDA_GridData is CxvVectorPropertyData { IndexBasis: MyCxvChildCountIndexBasisData indexBasis })
					{
						indexBasis.ResetChildIds(streamIds);
					}
					if (grdPSD_GridData is CxvVectorPropertyData cxvVectorPropertyData2)
					{
						foreach (object item2 in cxvVectorPropertyData2)
						{
							if (item2 is grdPSD_GridData_ItemTemplate { inner: CxvVectorPropertyData { IndexBasis: MyCxvChildCountIndexBasisData indexBasis2 } })
							{
								indexBasis2.ResetChildIds(streamIds);
							}
						}
					}
					if (GridData_Column is CxvVectorPropertyData { IndexBasis: MyCxvChildCountIndexBasisData indexBasis3 })
					{
						indexBasis3.ResetChildIds(streamIds);
					}
					OnPropertyChanged("grdPSD_GridData");
					OnPropertyChanged("GridData_Column");
				}
			});
		}

		public override void OnViewClosed()
		{
			base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<MaterialFormColumnsChangedEvent>().Unsubscribe(OnMaterialFormColumnsChanged);
			base.OnViewClosed();
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if ((ogrOption1_MultiMap as CxvMultiMapPropertyData).SelectedItem == null)
				{
					ResolveUpdateViewPropertyPath("ogrOption1_MultiMap.SelectedItem", AspenTech.AspenPlus.Localization.Properties.Resources.MMStreamSum_Summar_Solids_ViewModel_ogrOption1_MultiMapOption_2);
				}
				if ((ogrOption2_MultiMap as CxvMultiMapPropertyData).SelectedItem == null)
				{
					ResolveUpdateViewPropertyPath("ogrOption2_MultiMap.SelectedItem", AspenTech.AspenPlus.Localization.Properties.Resources.MMStreamSum_Summar_Solids_ViewModel_ogrOption2_MultiMapOption_1);
				}
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_solid", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_solid", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_solid", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_solid", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_solid", "Top.appModelV8");
				}
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (subPropertyName == "Units")
			{
				if (pd == D10Unit_var1_Property)
				{
					OnPropertyChanged("L1");
				}
				else if (pd == D20Unit_var1_Property)
				{
					OnPropertyChanged("L2");
				}
				else if (pd == D25Unit_var1_Property)
				{
					OnPropertyChanged("L3");
				}
				else if (pd == D50Unit_var1_Property)
				{
					OnPropertyChanged("L4");
				}
				else if (pd == D63Unit_var1_Property)
				{
					OnPropertyChanged("L5");
				}
				else if (pd == D75Unit_var1_Property)
				{
					OnPropertyChanged("L6");
				}
				else if (pd == D80Unit_var1_Property)
				{
					OnPropertyChanged("L7");
				}
				else if (pd == D90Unit_var1_Property)
				{
					OnPropertyChanged("L8");
				}
				else if (pd == SMDUnit_var1_Property)
				{
					OnPropertyChanged("L10");
				}
				else if (pd == SVUnit_var1_Property)
				{
					OnPropertyChanged("L11");
				}
				else if (pd == D43Unit_var1_Property)
				{
					OnPropertyChanged("L12");
				}
				else if (pd == D95Unit_var1_Property)
				{
					OnPropertyChanged("L13");
				}
				else if (pd == D100Unit_var1_Property)
				{
					OnPropertyChanged("L14");
				}
			}
			if (pd == MMComboBox2_var2_Property && subPropertyName == "Value")
			{
				RefreshPlotWizardRibbon();
				IEventAggregator eventAggregator = base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				MaterialFormColumnsQueryEventArgs e = new MaterialFormColumnsQueryEventArgs();
				eventAggregator.GetEvent<MaterialFormColumnsQueryEvent>().Publish(e);
				UpdateDisplayedStreams(e.DisplayedStreamIds);
			}
			else if (pd == MMComboBox1_var2_Property && subPropertyName == "Value")
			{
				IEventAggregator eventAggregator2 = base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				MaterialFormColumnsQueryEventArgs e2 = new MaterialFormColumnsQueryEventArgs();
				eventAggregator2.GetEvent<MaterialFormColumnsQueryEvent>().Publish(e2);
				UpdateDisplayedStreams(e2.DisplayedStreamIds);
			}
		}

		private string ResolveUnitForGlobalUnitSet(object property)
		{
			if (property is CxvVariableData cxvVariableData)
			{
				if (cxvVariableData.UnitRow != 0)
				{
					return base.UnityContainer.TryResolve<IAdbUnitsProvider>().GetDefaultDisplayUnits(cxvVariableData.UnitRow);
				}
				return cxvVariableData.Units;
			}
			return null;
		}

		public override object GetValue(CxvPropertyDeclaration property)
		{
			if (property == null)
			{
				return null;
			}
			if (base.IsUnloaded)
			{
				return null;
			}
			if (property.Name == "GridData_Column_2" || property.Name == "GridData_Column")
			{
				CxvPropertyWatch dependencies = new CxvPropertyWatch();
				return property.Metadata.GetPropertyValue(this, dependencies);
			}
			return base.GetValue(property);
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Solids")]
	public class MMStreamSum_Summar_Solids : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuSubstr_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel lbtuView_label;

		internal MMComboEdit MMComboBox2;

		internal MMOptionGroup ogrOption1;

		internal MMOptionButton ogrOption1_opt0;

		internal MMOptionButton ogrOption1_opt1;

		internal MMOptionGroup ogrOption2;

		internal MMOptionButton ogrOption2_opt0;

		internal MMOptionButton ogrOption2_opt1;

		internal MMOptionGroup ogrOption3;

		internal MMOptionButton ogrOption3_opt3;

		internal MMOptionButton ogrOption3_opt4;

		internal MMScrollAreaMS grdPSD;

		internal MMScrollAreaMS grdPSDA;

		internal MMScrollAreaMS grdMC;

		private bool _contentLoaded;

		public MMStreamSum_Summar_Solids()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Solids_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_solids.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				lbtuSubstr_label = (MMLabel)target;
				break;
			case 2:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 3:
				lbtuView_label = (MMLabel)target;
				break;
			case 4:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 5:
				ogrOption1 = (MMOptionGroup)target;
				break;
			case 6:
				ogrOption1_opt0 = (MMOptionButton)target;
				break;
			case 7:
				ogrOption1_opt1 = (MMOptionButton)target;
				break;
			case 8:
				ogrOption2 = (MMOptionGroup)target;
				break;
			case 9:
				ogrOption2_opt0 = (MMOptionButton)target;
				break;
			case 10:
				ogrOption2_opt1 = (MMOptionButton)target;
				break;
			case 11:
				ogrOption3 = (MMOptionGroup)target;
				break;
			case 12:
				ogrOption3_opt3 = (MMOptionButton)target;
				break;
			case 13:
				ogrOption3_opt4 = (MMOptionButton)target;
				break;
			case 14:
				grdPSD = (MMScrollAreaMS)target;
				break;
			case 15:
				grdPSDA = (MMScrollAreaMS)target;
				break;
			case 16:
				grdMC = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMStreamSum_Summar_Work_ViewModel : MMTabPageViewModel
	{
		public class grdWork_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#3.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@woutp.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdWork_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@woutp.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@woutp.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
					obj.DescriptionPath = ExpandDataPath("@main").Replace("Results Summary", "Streams.[Value]");
					obj.SubObjectTypePath = obj.DescriptionPath;
					obj.StatusPath = obj.SubObjectTypePath;
					obj.ObjectType = obj.SubObjectTypePath;
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Work-Sum.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "All hierarchy streams",
					DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
					Value = "cboDisplay_MultiMapOption_3",
					Prompt = "Display all hierarchy streams",
					PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLHIERSTREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration woutp_Property = CxvPropertyDeclaration.Register("woutp", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work-Sum.Table"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@woutp.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@woutp.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@woutp.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@woutp.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@woutp.#7"
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@woutp",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData2_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@woutp",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object woutp => GetValue(woutp_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object MMTextBox3Lab_var1 => GetValue(MMTextBox3Lab_var1_Property);

		public object MMTextBox4Lab_var1 => GetValue(MMTextBox4Lab_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object grdWork_GridData => GetValue(grdWork_GridData_Property);

		public object grdWork_GridData2 => GetValue(grdWork_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && ExpandDataPath("@main.Work-Sum.Table") != null)
			{
				if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Work-Sum.Table.#5", "id"))))
				{
					RegularVisibility = Visibility.Visible;
					BatchVisibility = Visibility.Collapsed;
				}
				else
				{
					RegularVisibility = Visibility.Collapsed;
					BatchVisibility = Visibility.Visible;
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMStreamSum.MMStreamSum_Summar_Work")]
	public class MMStreamSum_Summar_Work : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdWork;

		internal MMScrollAreaHorizontal grdWork2;

		private bool _contentLoaded;

		public MMStreamSum_Summar_Work()
		{
			base.ViewModelType = typeof(MMStreamSum_Summar_Work_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/stream-sum/mmstreamsum_summar_work.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdWork = (MMScrollAreaHorizontal)target;
				break;
			case 4:
				grdWork2 = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Run_Status
{
	public class MMRun_Status_ViewModel : MMTabPageViewModel
	{
		public string HelpFile
		{
			get
			{
				if (GetProductCode() != 2)
				{
					return "results.chm";
				}
				return "apr-results.chm";
			}
		}

		public MMRun_Status_ViewModel()
		{
			ResolveUpdateParameter("extra_message_path", "Run-Status");
		}
	}
	[ProgId("MMRun_Stat.MMRun_Status")]
	public class MMRun_Status : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus1;

		private bool _contentLoaded;

		public MMRun_Status()
		{
			base.ViewModelType = typeof(MMRun_Status_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/run-status/mmrun_status.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMTabStrip1 = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tabStatus1 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMRun_Status_Summar_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuDescr_var1_Property = CxvPropertyDeclaration.Register("lbtuDescr_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.DESCRIPTION",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuVer_var1_Property = CxvPropertyDeclaration.Register("lbtuVer_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.VERNO",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuSiteid_var1_Property = CxvPropertyDeclaration.Register("lbtuSiteid_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.SITEID"
		});

		public static readonly CxvPropertyDeclaration lbtuNodename_var1_Property = CxvPropertyDeclaration.Register("lbtuNodename_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.NODENAME",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuMachine_var1_Property = CxvPropertyDeclaration.Register("lbtuMachine_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.MACHINE",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuUser_var1_Property = CxvPropertyDeclaration.Register("lbtuUser_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.USER",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuDate_var1_Property = CxvPropertyDeclaration.Register("lbtuDate_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Status.Output.ITDATE"
		});

		public static readonly CxvPropertyDeclaration cboUosStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboUosStat_MultiMap", typeof(MMRun_Status_Summar_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboUosStat_var1",
					DataPath = "@main.Run-Status.Output.UOSSTAT2"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Simulation was completed normally",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Simulation_was_completed_normally",
					Value = "cboUosStat_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Simulation was not completed normally, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Simulation_was_not_completed_normally__use_",
					Value = "cboUosStat_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "3"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Data regression was completed normally",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Data_regression_was_completed_normally",
					Value = "cboUosStat_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "4"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Data regression was completed with errors, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Data_regression_was_completed_with_errors__",
					Value = "cboUosStat_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "5"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Assay data analysis was completed normally",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Assay_data_analysis_was_completed_normally",
					Value = "cboUosStat_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "6"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Assay data analysis was completed with errors, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Assay_data_analysis_was_completed_with_erro",
					Value = "cboUosStat_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "7"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Calculations were completed normally",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_normally",
					Value = "cboUosStat_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "8"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Calculations were completed with errors, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_with_errors__us",
					Value = "cboUosStat_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "9"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Calculations were completed with warnings, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_with_warnings__",
					Value = "cboUosStat_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboUosStat_var1",
							Value = "10"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboTotStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboTotStat_MultiMap", typeof(MMRun_Status_Summar_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboTotStat_var1",
					DataPath = "@main.Run-Status.Output.ITSTAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "There are warnings during input translation, use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_There_are_warnings_during_input_translation",
					Value = "cboTotStat_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTotStat_var1",
							Value = "4"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Use_status_button_for_details",
					Value = "cboTotStat_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTotStat_var1",
							Value = "1"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Use status button for details",
					DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Use_status_button_for_details_1",
					Value = "cboTotStat_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTotStat_var1",
							Value = "16"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = " ",
					Value = "cboTotStat_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTotStat_var1",
							Value = "0"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuVer_var2_Property = CxvPropertyDeclaration.Register("lbtuVer_var2", typeof(MMRun_Status_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "ParamVersionLabel"
		});

		public object lbtuDescr_var1 => GetValue(lbtuDescr_var1_Property);

		public object lbtuVer_var1 => GetValue(lbtuVer_var1_Property);

		public object lbtuSiteid_var1 => GetValue(lbtuSiteid_var1_Property);

		public object lbtuNodename_var1 => GetValue(lbtuNodename_var1_Property);

		public object lbtuMachine_var1 => GetValue(lbtuMachine_var1_Property);

		public object lbtuUser_var1 => GetValue(lbtuUser_var1_Property);

		public object lbtuDate_var1 => GetValue(lbtuDate_var1_Property);

		public object cboUosStat_MultiMap => GetValue(cboUosStat_MultiMap_Property);

		public object cboTotStat_MultiMap => GetValue(cboTotStat_MultiMap_Property);

		public object lbtuVer_var2 => GetValue(lbtuVer_var2_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("ParamVersionLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMRun_Status_Summar_ViewModel__ParamVersionLabel_Aspen_Properties_Version);
				}
				else
				{
					ResolveUpdateParameter("ParamVersionLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMRun_Status_Summar_ViewModel__ParamVersionLabel_Aspen_Plus_Version);
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMRun_Stat.MMRun_Status_Summar")]
	public class MMRun_Status_Summar : MMTabPage, IComponentConnector
	{
		internal MMTextEdit cboUosStat;

		internal MMTextEdit cboTotStat;

		internal MMLabel lbtuVer_label;

		internal MMVariableEdit lbtuVer;

		internal MMLabel lbtuDescr_label;

		internal MMVariableEdit lbtuDescr;

		internal MMLabel lbtuDate_label;

		internal MMVariableEdit lbtuDate;

		internal MMLabel lbtuUser_label;

		internal MMVariableEdit lbtuUser;

		internal MMLabel lbtuSiteid_label;

		internal MMVariableEdit lbtuSiteid;

		internal MMLabel lbtuMachine_label;

		internal MMVariableEdit lbtuMachine;

		internal MMLabel lbtuNodename_label;

		internal MMVariableEdit lbtuNodename;

		private bool _contentLoaded;

		public MMRun_Status_Summar()
		{
			base.ViewModelType = typeof(MMRun_Status_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/run-status/mmrun_status_summar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboUosStat = (MMTextEdit)target;
				break;
			case 2:
				cboTotStat = (MMTextEdit)target;
				break;
			case 3:
				lbtuVer_label = (MMLabel)target;
				break;
			case 4:
				lbtuVer = (MMVariableEdit)target;
				break;
			case 5:
				lbtuDescr_label = (MMLabel)target;
				break;
			case 6:
				lbtuDescr = (MMVariableEdit)target;
				break;
			case 7:
				lbtuDate_label = (MMLabel)target;
				break;
			case 8:
				lbtuDate = (MMVariableEdit)target;
				break;
			case 9:
				lbtuUser_label = (MMLabel)target;
				break;
			case 10:
				lbtuUser = (MMVariableEdit)target;
				break;
			case 11:
				lbtuSiteid_label = (MMLabel)target;
				break;
			case 12:
				lbtuSiteid = (MMVariableEdit)target;
				break;
			case 13:
				lbtuMachine_label = (MMLabel)target;
				break;
			case 14:
				lbtuMachine = (MMVariableEdit)target;
				break;
			case 15:
				lbtuNodename_label = (MMLabel)target;
				break;
			case 16:
				lbtuNodename = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve
{
	public class MMPolycur_Result_Csd_ViewModel : MMTabPageViewModel, IFormViewModel
	{
		public class grdResults_GridData_ItemTemplate : MMViewModel, IItemTemplate
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_DP_Property = CxvPropertyDeclaration.Register("MMTextBox1_DP", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@DPid.@y"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CustomIndexBasis("selectedStreams4", "availableStreams4")
				{
					DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4",
					UseChildId = true,
					Name = "x",
					ProxyRow = false,
					IsNotJagged = true,
					MinimumRows = 1
				}
			});

			public object MMTextBox1_DP => GetValue(MMTextBox1_DP_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdResults_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4.@x.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4.@x"
			});

			public object MMTextBox2_StreamValues => GetValue(MMTextBox2_StreamValues_Property);

			public object id => new CustomStreamSelectedObject<grdResults_GridData_ItemTemplate, MMPolycur_Result_Csd_ViewModel>(this, "selectedStreams4", "availableStreams4", "StreamVisible4");

			public object MMTextBox2_StreamUOM => GetValue(MMTextBox2_StreamUOM_Property);
		}

		public static readonly CxvPropertyDeclaration fraPoly_ColCount_Property = CxvPropertyDeclaration.Register("fraPoly_ColCount", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount"
		});

		public static readonly CxvPropertyDeclaration fraPoly_viewid_Property = CxvPropertyDeclaration.Register("fraPoly_viewid", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
		{
			Parameter = "viewid4"
		});

		public static readonly CxvPropertyDeclaration fraPoly_DPid_Property = CxvPropertyDeclaration.Register("fraPoly_DPid", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
		{
			Parameter = "DPid"
		});

		public static readonly CxvPropertyDeclaration grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMPolycur_Result_Csd_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdResults_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@DPid",
				UseChildId = true,
				Name = "y"
			}
		});

		private const string paramStreamVisible = "StreamVisible4";

		private ObservableCollection<string> _selectedStreams = new ObservableCollection<string>();

		private ObservableCollection<string> _availableStreams = new ObservableCollection<string>();

		private StreamHelper<grdResults_GridData_ItemTemplate> helper;

		public static readonly CxvPropertyDeclaration mnuCurveView_PetroView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PetroView", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview4"
		});

		public static readonly CxvPropertyDeclaration mnuCurveView_PCurView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PCurView", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
		{
			Parameter = "PCurView"
		});

		public static readonly CxvPropertyDeclaration stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMPolycur_Result_Csd_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "All streams",
					DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_Diaplay_All_Streams"
				},
				new CxvAdvCollectionItem
				{
					Display = "Streams",
					DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_Diaplay_Streams"
				}
			}
		});

		public static readonly CxvPropertyDeclaration mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMPolycur_Result_Csd_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "Chain size",
					DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionItem_Display_Chain_size"
				}
			},
			SelectedItemBinding = "mnuCurveView_PCurView.Value",
			CreateNewPrompt = "View:",
			CreateNewPromptResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_View_",
			CreateNewInputMask = 2,
			IsCalculated = true
		});

		public object fraPoly_ColCount => GetValue(fraPoly_ColCount_Property);

		public object fraPoly_viewid => GetValue(fraPoly_viewid_Property);

		public object fraPoly_DPid => GetValue(fraPoly_DPid_Property);

		public object grdResults_GridData => GetValue(grdResults_GridData_Property);

		public object mnuCurveView_PetroView => GetValue(mnuCurveView_PetroView_Property);

		public object mnuCurveView_PCurView => GetValue(mnuCurveView_PCurView_Property);

		public object stream_AdvCollection => GetValue(stream_AdvCollection_Property);

		public object mnuCurveView_AdvCollection => GetValue(mnuCurveView_AdvCollection_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				helper = new StreamHelper<grdResults_GridData_ItemTemplate>("StreamVisible4", this, _selectedStreams, _availableStreams, grdResults_GridData, stream_AdvCollection as CxvAdvCollectionPropertyData);
				helper.SetInitialDisplay();
				SetComboEnabledArray();
				string text = FindFirstComboItem();
				ResolveUpdateParameter("str_polycurveview4", text);
				SetVariable(text, "PCurView");
				ResolveUpdateParameter("selectedStreams4", _selectedStreams);
				ResolveUpdateParameter("availableStreams4", _availableStreams);
			}
			base.OnUpdateData();
		}

		public override void Unload()
		{
			helper.Unload();
			base.Unload();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Name == "stream_AdvCollection" && subPropertyName == "SelectedItem")
			{
				if (base.View is MMPolycur_Result_Csd mMPolycur_Result_Csd)
				{
					helper.OnStreamChanged(mMPolycur_Result_Csd.grdResults);
				}
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "Items")
			{
				SetComboEnabledArray();
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "SelectedItem")
			{
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = mnuCurveView_AdvCollection as CxvAdvCollectionPropertyData;
				SetVariable(cxvAdvCollectionPropertyData.SelectedItem, "PetroView");
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		private void SetComboEnabledArray()
		{
			string text = ExpandDataPath("@main2");
			if (string.IsNullOrEmpty(text) || text.IndexOf(".Results Summary") < 0)
			{
				return;
			}
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (!(mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData))
			{
				return;
			}
			string text3 = "";
			for (int i = 0; i < cxvAdvCollectionPropertyData.Items.Count; i++)
			{
				cxvAdvCollectionPropertyData.Items[i].Entered = false;
				if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionItem_Display_Chain_size)
				{
					text3 = "POLCSDY";
				}
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "child_count"));
				if (num.HasValue && num.Value > 0)
				{
					cxvAdvCollectionPropertyData.Items[i].Entered = true;
				}
			}
		}

		private string FindFirstComboItem()
		{
			string result = null;
			string text = ExpandDataPath("@main2");
			if (!string.IsNullOrEmpty(text))
			{
				string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
				if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
				{
					string text3 = "";
					foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
					{
						if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionItem_Display_Chain_size)
						{
							text3 = "POLCSDY";
						}
						int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "child_count"));
						if (num.HasValue && num.Value > 0)
						{
							result = item.Id;
							break;
						}
					}
				}
			}
			return result;
		}

		private void SetVariable(string newValue, string varname)
		{
			if (varname == "PCurView")
			{
				ResolveUpdateParameter("str_petrocurveview4", newValue);
				ResolveUpdateParameter("DPid", "POLCSDX");
				ResolveUpdateParameter("viewid4", "POLCSDY");
				Collection<string> streams = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid4", "child_ids", null));
				helper.InitAvailableStreams(streams);
				helper.InSetVariable(streams);
			}
		}
	}
	[ProgId("MMPolycur.MMPolycur_Result_Csd")]
	public class MMPolycur_Result_Csd : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuCurveView_label;

		internal MMComboEdit mnuCurveView;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMPolycur_Result_Csd()
		{
			base.ViewModelType = typeof(MMPolycur_Result_Csd_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/poly-curve/mmpolycur_result_csd.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				mnuCurveView_label = (MMLabel)target;
				break;
			case 2:
				mnuCurveView = (MMComboEdit)target;
				break;
			case 3:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve
{
	public class MMDistcu_Result_Petro_ViewModel : MMTabPageViewModel, IFormViewModel
	{
		public class grdResults_GridData_ItemTemplate : MMViewModel, IItemTemplate
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid.@y"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CustomIndexBasis("selectedStreams", "availableStreams")
				{
					DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid",
					UseChildId = false,
					Name = "x",
					ProxyRow = false,
					MinimumRows = 1
				},
				AllowCollectionChange = false
			});

			public object MMTextBox1_TBPT => GetValue(MMTextBox1_TBPT_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdResults_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid.@x.@y",
				IsCalculated = true
			});

			public object id => new CustomStreamSelectedObject<grdResults_GridData_ItemTemplate, MMDistcu_Result_Petro_ViewModel>(this, "selectedStreams", "availableStreams", "StreamVisible");

			public object MMTextBox2_StreamUOM => GetValue(MMTextBox2_StreamUOM_Property);

			public object MMTextBox2_StreamValues => GetValue(MMTextBox2_StreamValues_Property);
		}

		public static readonly CxvPropertyDeclaration fraPetro_ColCount_Property = CxvPropertyDeclaration.Register("fraPetro_ColCount", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount"
		});

		public static readonly CxvPropertyDeclaration fraPetro_viewid_Property = CxvPropertyDeclaration.Register("fraPetro_viewid", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "viewid"
		});

		public static readonly CxvPropertyDeclaration fraPetro_TBPTid_Property = CxvPropertyDeclaration.Register("fraPetro_TBPTid", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "TBPTid"
		});

		private const string paramSelectedStream = "selectedStreams";

		private const string paramAvailableStream = "availableStreams";

		private const string paramStreamVisible = "StreamVisible";

		private StreamHelper<grdResults_GridData_ItemTemplate> helper;

		private ObservableCollection<string> _selectedStreams = new ObservableCollection<string>();

		private ObservableCollection<string> _availableStreams = new ObservableCollection<string>();

		public static readonly CxvPropertyDeclaration mnuCurveView_PetroView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PetroView", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Petro_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdResults_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid",
				UseChildId = false,
				Name = "y",
				IsNotJagged = true,
				ProxyRow = false
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "PetroGridEnabled",
				Operator = CxvLogicalOperator.Equal,
				Value = true
			}
		});

		public static readonly CxvPropertyDeclaration mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Petro_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "Aniline point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Aniline_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Aromatic content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Aromatic_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Asphaltene content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Asphaltene_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Basic nitrogen content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Basic_nitrogen_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Bromine number",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Bromine_number"
				},
				new CxvAdvCollectionItem
				{
					Display = "Carbon residue",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Carbon_residue"
				},
				new CxvAdvCollectionItem
				{
					Display = "Cetane number",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Cetane_number"
				},
				new CxvAdvCollectionItem
				{
					Display = "Cloud point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Cloud_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Conradson carbon content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Conradson_carbon_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Hydrogen content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Hydrogen_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Flash point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Flash_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Freeze point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Freeze_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Iron content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Iron_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Antiknock index",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Antiknock_index"
				},
				new CxvAdvCollectionItem
				{
					Display = "Kinematic viscosity",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
				},
				new CxvAdvCollectionItem
				{
					Display = "Luminometer number",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Luminometer_number"
				},
				new CxvAdvCollectionItem
				{
					Display = "Mercaptan content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Mercaptan_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Metal content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Metal_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Motor octane number",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Motor_octane_number"
				},
				new CxvAdvCollectionItem
				{
					Display = "Naphthene content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Naphthene_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Nickel content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Nickel_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Olefin content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Olefin_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Oxygen content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Oxygen_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Paraffin content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Paraffin_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Pour point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Pour_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Refractive index",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Refractive_index"
				},
				new CxvAdvCollectionItem
				{
					Display = "Research octane number",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Research_octane_number"
				},
				new CxvAdvCollectionItem
				{
					Display = "Reid vapor pressure",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Reid_vapor_pressure"
				},
				new CxvAdvCollectionItem
				{
					Display = "Smoke point",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Smoke_point"
				},
				new CxvAdvCollectionItem
				{
					Display = "Sulfur content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Sulfur_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Total nitrogen content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Total_nitrogen_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vanadium content",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Vanadium_content"
				},
				new CxvAdvCollectionItem
				{
					Display = "Viscosity",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Viscosity"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vapor knock index",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Vapor_knock_index"
				},
				new CxvAdvCollectionItem
				{
					Display = "Warm-up index",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Warm_up_index"
				},
				new CxvAdvCollectionItem
				{
					Display = "Watson UOP K curve",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Watson_UOP_K_curve"
				}
			},
			SelectedItemBinding = "mnuCurveView_PetroView.Value",
			CreateNewPrompt = "Curve view:",
			CreateNewPromptResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_",
			CreateNewInputMask = 2
		});

		public static readonly CxvPropertyDeclaration stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Petro_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "All streams",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_All_Streams"
				},
				new CxvAdvCollectionItem
				{
					Display = "Streams",
					DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Streams"
				}
			}
		});

		public static readonly CxvPropertyDeclaration StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "StreamVisible"
		});

		public object fraPetro_ColCount => GetValue(fraPetro_ColCount_Property);

		public object fraPetro_viewid => GetValue(fraPetro_viewid_Property);

		public object fraPetro_TBPTid => GetValue(fraPetro_TBPTid_Property);

		public object mnuCurveView_PetroView => GetValue(mnuCurveView_PetroView_Property);

		public object grdResults_GridData => GetValue(grdResults_GridData_Property);

		public object mnuCurveView_AdvCollection => GetValue(mnuCurveView_AdvCollection_Property);

		public object stream_AdvCollection => GetValue(stream_AdvCollection_Property);

		public object StreamVisible => GetValue(StreamVisible_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "stream_AdvCollection" && subPropertyName == "SelectedItem")
			{
				if (base.View is MMDistcu_Result_Petro mMDistcu_Result_Petro)
				{
					helper.OnStreamChanged(mMDistcu_Result_Petro.grdResults);
				}
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "Items")
			{
				SetComboEnabledArray();
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "SelectedItem")
			{
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = mnuCurveView_AdvCollection as CxvAdvCollectionPropertyData;
				SetVariable(cxvAdvCollectionPropertyData.SelectedItem, "PetroView");
				SetGridAvailability(cxvAdvCollectionPropertyData.SelectedItem);
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				helper = new StreamHelper<grdResults_GridData_ItemTemplate>("StreamVisible", this, _selectedStreams, _availableStreams, grdResults_GridData, stream_AdvCollection as CxvAdvCollectionPropertyData);
				helper.SetInitialDisplay();
				ResolveUpdateParameter("selectedStreams", _selectedStreams);
				ResolveUpdateParameter("availableStreams", _availableStreams);
				SetComboEnabledArray();
				string text = FindFirstComboItem();
				ResolveUpdateParameter("str_petrocurveview", text);
				SetVariable(text, "PetroView");
				SetGridAvailability(text);
			}
		}

		public override void Unload()
		{
			base.Unload();
		}

		private void SetComboEnabledArray()
		{
			string text = ExpandDataPath("@main2");
			if (text.IndexOf(".Results Summary") < 0)
			{
				return;
			}
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (!(mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData))
			{
				return;
			}
			string text3 = "";
			foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
			{
				item.Entered = false;
				if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text)
				{
					text3 = "ANILCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_1)
				{
					text3 = "AROMCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_32)
				{
					text3 = "ASPHACRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_2)
				{
					text3 = "BAS-NCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_33)
				{
					text3 = "BROMICRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_3)
				{
					text3 = "CARBCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_34)
				{
					text3 = "CETANCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_31)
				{
					text3 = "CLOUDCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_35)
				{
					text3 = "COCARCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_5)
				{
					text3 = "FLASHCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_6)
				{
					text3 = (text3 = "FREEZCRV");
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_4)
				{
					text3 = "HYDROCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_7)
				{
					text3 = "IRONCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_8)
				{
					text3 = "KNOCKCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_9)
				{
					text3 = "KVISCCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_10)
				{
					text3 = "LUM-NCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_11)
				{
					text3 = "MERCCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_12)
				{
					text3 = "METALCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_13)
				{
					text3 = "MOCNCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_14)
				{
					text3 = "NAPHCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_15)
				{
					text3 = "NICKCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_16)
				{
					text3 = "OLEFCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_17)
				{
					text3 = "OXYGCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_18)
				{
					text3 = "PARACRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_19)
				{
					text3 = "POURCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_20)
				{
					text3 = "REFICRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_21)
				{
					text3 = "ROCNCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_22)
				{
					text3 = "RVPCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_23)
				{
					text3 = "SMOKCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_24)
				{
					text3 = "SULFCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_25)
				{
					text3 = "TOT-NCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_26)
				{
					text3 = "VANACRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_27)
				{
					text3 = "VISCCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_28)
				{
					text3 = "VLOCKCRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_29)
				{
					text3 = "WARMICRV";
				}
				else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_30)
				{
					text3 = "UOPKCRV";
				}
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "has_children"));
				if (num.HasValue && num > 0)
				{
					item.Entered = true;
				}
			}
		}

		private string FindFirstComboItem()
		{
			string result = null;
			string text = ExpandDataPath("@main2");
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
			{
				string text3 = "";
				foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
				{
					if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text)
					{
						text3 = "ANILCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_1)
					{
						text3 = "AROMCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_32)
					{
						text3 = "ASPHACRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_2)
					{
						text3 = "BAS-NCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_33)
					{
						text3 = "BROMICRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_3)
					{
						text3 = "CARBCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_34)
					{
						text3 = "CETANCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_31)
					{
						text3 = "CLOUDCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_35)
					{
						text3 = "COCARCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_5)
					{
						text3 = "FLASHCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_6)
					{
						text3 = "FREEZCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_4)
					{
						text3 = "HYDROCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_7)
					{
						text3 = "IRONCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_8)
					{
						text3 = "KNOCKCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_9)
					{
						text3 = "KVISCCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_10)
					{
						text3 = "LUM-NCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_11)
					{
						text3 = "MERCCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_12)
					{
						text3 = "METALCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_13)
					{
						text3 = "MOCNCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_14)
					{
						text3 = "NAPHCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_15)
					{
						text3 = "NICKCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_16)
					{
						text3 = "OLEFCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_17)
					{
						text3 = "OXYGCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_18)
					{
						text3 = "PARACRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_19)
					{
						text3 = "POURCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_20)
					{
						text3 = "REFICRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_21)
					{
						text3 = "ROCNCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_22)
					{
						text3 = "RVPCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_23)
					{
						text3 = "SMOKCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_24)
					{
						text3 = "SULFCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_25)
					{
						text3 = "TOT-NCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_26)
					{
						text3 = "VANACRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_27)
					{
						text3 = "VISCCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_28)
					{
						text3 = "VLOCKCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_29)
					{
						text3 = "WARMICRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_30)
					{
						text3 = "UOPKCRV";
					}
					int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "child_count"));
					if (num.HasValue && num > 0)
					{
						result = item.Id;
						break;
					}
				}
			}
			return result;
		}

		private void SetVariable(string newValue, string varname)
		{
			switch (varname)
			{
			default:
				_ = varname == "TestUserDefined";
				break;
			case "PetroView":
			{
				ResolveUpdateParameter("str_petrocurveview", newValue);
				string value = "";
				string value2 = "";
				if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text)
				{
					value = "ANILCRV";
					value2 = "ANILTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_1)
				{
					value = "AROMCRV";
					value2 = "AROMTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_32)
				{
					value = "ASPHACRV";
					value2 = "ASPHABPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_2)
				{
					value = "BAS-NCRV";
					value2 = "BA-NTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_33)
				{
					value = "BROMICRV";
					value2 = "BROMIBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_3)
				{
					value = "CARBCRV";
					value2 = "CARBTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_34)
				{
					value = "CETANCRV";
					value2 = "CETANBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_31)
				{
					value = "CLOUDCRV";
					value2 = "CLOUDBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_35)
				{
					value = "COCARCRV";
					value2 = "COCARBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_5)
				{
					value = "FLASHCRV";
					value2 = "FLASHTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_6)
				{
					value = "FREEZCRV";
					value2 = "FREEZTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_4)
				{
					value = "HYDROCRV";
					value2 = "HYDROTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_7)
				{
					value = "IRONCRV";
					value2 = "IRONTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_8)
				{
					value = "KNOCKCRV";
					value2 = "KNOCKTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_9)
				{
					value = "KVISCCRV";
					value2 = "KVISTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_10)
				{
					value = "LUM-NCRV";
					value2 = "LUMITBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_11)
				{
					value = "MERCCRV";
					value2 = "MERCTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_12)
				{
					value = "METALCRV";
					value2 = "METALTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_13)
				{
					value = "MOCNCRV";
					value2 = "MOCNTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_14)
				{
					value = "NAPHCRV";
					value2 = "NAPHTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_15)
				{
					value = "NICKCRV";
					value2 = "NICKTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_16)
				{
					value = "OLEFCRV";
					value2 = "OLEFTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_17)
				{
					value = "OXYGCRV";
					value2 = "OXYGTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_18)
				{
					value = "PARACRV";
					value2 = "PARATBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_19)
				{
					value = "POURCRV";
					value2 = "POURTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_20)
				{
					value = "REFICRV";
					value2 = "REFITBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_21)
				{
					value = "ROCNCRV";
					value2 = "ROCNTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_22)
				{
					value = "RVPCRV";
					value2 = "RVPTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_23)
				{
					value = "SMOKCRV";
					value2 = "SMOKTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_24)
				{
					value = "SULFCRV";
					value2 = "SULFTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_25)
				{
					value = "TOT-NCRV";
					value2 = "TOT-NTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_26)
				{
					value = "VANACRV";
					value2 = "VANATBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_27)
				{
					value = "VISCCRV";
					value2 = "VISCTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_28)
				{
					value = "VLOCKCRV";
					value2 = "VLOCKTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_29)
				{
					value = "WARMICRV";
					value2 = "WARMTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Text_30)
				{
					value = "UOPKCRV";
					value2 = "UOPKTBPT";
				}
				if (_selectedStreams == null || _selectedStreams.Count == 0)
				{
					helper.SetInitialDisplay();
				}
				ResolveUpdateParameter("viewid", value);
				Collection<string> streams = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid", "child_ids", null));
				helper.InitAvailableStreams(streams);
				ResolveUpdateParameter("TBPTid", value2);
				helper.InSetVariable(streams);
				break;
			}
			case "target":
				break;
			}
		}

		private void SetGridAvailability(string selectedItem)
		{
			if (!(mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData))
			{
				return;
			}
			foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
			{
				if (item.Display == selectedItem)
				{
					ResolveUpdateParameter("PetroGridEnabled", item.Entered.Value);
					break;
				}
			}
		}
	}
	[ProgId("MMDistcu.MMDistcu_Result_Petro")]
	public class MMDistcu_Result_Petro : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuCurveView_label;

		internal MMAdvancedComboEdit mnuCurveView;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMDistcu_Result_Petro()
		{
			base.ViewModelType = typeof(MMDistcu_Result_Petro_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/dist-curve/mmdistcu_result_petro.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				mnuCurveView_label = (MMLabel)target;
				break;
			case 2:
				mnuCurveView = (MMAdvancedComboEdit)target;
				break;
			case 3:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMDistcu_Result_Volume_ViewModel : MMTabPageViewModel, IFormViewModel
	{
		public class grdResults_GridData_ItemTemplate : MMViewModel, IItemTemplate
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Output.@viewid2.@x.@y"
			});

			public static readonly CxvPropertyDeclaration MMLBUText1_Units_Property = CxvPropertyDeclaration.Register("MMLBUText1_Units", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Output.@viewid2.@x"
			});

			public static readonly CxvPropertyDeclaration mnuDisplayView_DisplayView_Property = CxvPropertyDeclaration.Register("mnuDisplayView_DisplayView", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "DisplayView"
			});

			public static readonly CxvPropertyDeclaration mnuDisplayView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuDisplayView_AdvCollection", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
			{
				UseItemsCollection = true,
				Items = 
				{
					new CxvAdvCollectionItem
					{
						Display = "All streams",
						DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_All_streams"
					},
					new CxvAdvCollectionItem
					{
						Display = "Streams",
						DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Streams"
					}
				},
				SelectedItemBinding = "mnuDisplayView_DisplayView.Value"
			});

			public static readonly CxvPropertyDeclaration MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "target"
			});

			public static readonly CxvPropertyDeclaration MMAdvCombo1_selector_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_selector", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2",
				SelectedItemBinding = "MMAdvCombo1_target.Value"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CustomIndexBasis("selectedStreams2", "availableStreams2")
				{
					DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2",
					UseChildId = true,
					Name = "x",
					ProxyRow = false,
					IsNotJagged = true,
					MinimumRows = 1
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid2.@y",
				IsCalculated = true,
				IsReadOnly = true
			});

			public object MMTextBox2_StreamValues => GetValue(MMTextBox2_StreamValues_Property);

			public object MMLBUText1_Units => GetValue(MMLBUText1_Units_Property);

			public object mnuDisplayView_DisplayView => GetValue(mnuDisplayView_DisplayView_Property);

			public object mnuDisplayView_AdvCollection => GetValue(mnuDisplayView_AdvCollection_Property);

			public object MMAdvCombo1_target => GetValue(MMAdvCombo1_target_Property);

			public object MMAdvCombo1_selector => GetValue(MMAdvCombo1_selector_Property);

			public object inner => GetValue(inner_Property);

			public object MMTextBox1_TBPT => GetValue(MMTextBox1_TBPT_Property);
		}

		public class grdResults_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x"
			});

			private CxvPropertyWatch varDefnDependencies;

			private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

			public object id => new CustomStreamSelectedObject<grdResults_GridData_ItemTemplate, MMDistcu_Result_Volume_ViewModel>(this, "selectedStreams2", "availableStreams2", "StreamVisible2");

			public object MMTextBox2_StreamUOM => GetValue(MMTextBox2_StreamUOM_Property);

			public object MMTextBox2_StreamValues => new CxvManualVariableData
			{
				Value = ParamValueValue,
				IsCalculated = true,
				IsReadOnly = true,
				Path = ParamValuePath,
				ValueType = typeof(double)
			};

			public object ParamValueValue
			{
				get
				{
					if (varDefnDependencies != null)
					{
						varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
					}
					if (varDefnDependencies != null)
					{
						varDefnDependencies.Clear();
					}
					else
					{
						varDefnDependencies = new CxvPropertyWatch();
					}
					string text = CxsConverter.ValueToString(ResolveParameter("viewid2"));
					CxsConverter.ValueToString(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x", "uom", null, varDefnDependencies));
					if (!varDefnDependencies.IsEmpty)
					{
						varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
					}
					else
					{
						varDefnDependencies = null;
					}
					if (text != "D1160CRV")
					{
						return CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x.@y", "value"));
					}
					string valuePath = ((base.Parent as grdResults_GridData_ItemTemplate).Parent as MMDistcu_Result_Volume_ViewModel).ValuePath;
					return CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x." + valuePath + ".@y", "value"));
				}
			}

			public string ParamValuePath
			{
				get
				{
					if (CxsConverter.ValueToString(ResolveParameter("viewid2")) != "D1160CRV")
					{
						return ExpandDataPath("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x.@y");
					}
					string valuePath = ((base.Parent as grdResults_GridData_ItemTemplate).Parent as MMDistcu_Result_Volume_ViewModel).ValuePath;
					return ExpandDataPath("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x." + valuePath + ".@y");
				}
			}

			private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
			{
				get
				{
					if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
					{
						_varDefnDependencies_PropertyDependencyChangedHandler = delegate
						{
							OnPropertyChanged("MMTextBox2_StreamValues");
						};
					}
					return _varDefnDependencies_PropertyDependencyChangedHandler;
				}
			}
		}

		public static readonly CxvPropertyDeclaration fraVolume_PresUnits_Property = CxvPropertyDeclaration.Register("fraVolume_PresUnits", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "PresUnits"
		});

		public static readonly CxvPropertyDeclaration fraVolume_ColCount_Property = CxvPropertyDeclaration.Register("fraVolume_ColCount", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount"
		});

		public static readonly CxvPropertyDeclaration fraVolume_viewid_Property = CxvPropertyDeclaration.Register("fraVolume_viewid", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "viewid2"
		});

		public static readonly CxvPropertyDeclaration fraVolume_TBPTid_Property = CxvPropertyDeclaration.Register("fraVolume_TBPTid", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "TBPTid2"
		});

		public static readonly CxvPropertyDeclaration fraVolume_Pressure_Property = CxvPropertyDeclaration.Register("fraVolume_Pressure", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "Pressure"
		});

		public static readonly CxvPropertyDeclaration fraVolume_displayview_Property = CxvPropertyDeclaration.Register("fraVolume_displayview", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "displayview"
		});

		public static readonly CxvPropertyDeclaration NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount.Output.@viewid2.0"
		});

		public static readonly CxvPropertyDeclaration grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Volume_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdResults_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid2",
				UseChildId = true,
				Name = "y"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "VolGridEnabled",
				Operator = CxvLogicalOperator.Equal,
				Value = true
			}
		});

		private const string paramSelectedStream = "selectedStreams2";

		private const string paramAvailableStream = "availableStreams2";

		private const string paramStreamVisible = "StreamVisible2";

		private StreamHelper<grdResults_GridData_ItemTemplate> helper;

		private ObservableCollection<string> _selectedStreams = new ObservableCollection<string>();

		private ObservableCollection<string> _availableStreams = new ObservableCollection<string>();

		public static readonly CxvPropertyDeclaration mnuCurveView_VolumeView_Property = CxvPropertyDeclaration.Register("mnuCurveView_VolumeView", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview2"
		});

		public static readonly CxvPropertyDeclaration mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Volume_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "TBP curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_TBP_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D86 curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D1160 curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vacuum at 10 mmHg curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "API curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_API_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Specific gravity curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Molecular weight curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D86CRK curve",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve"
				}
			},
			SelectedItemBinding = "mnuCurveView_VolumeView.Value",
			CreateNewPrompt = "Curve view:",
			CreateNewPromptResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_",
			CreateNewInputMask = 2
		});

		private Dictionary<string, string> _dictPaths = new Dictionary<string, string>();

		public string ValuePath;

		private CxvManualVariableData _HeaderVolume;

		public static readonly CxvPropertyDeclaration stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Volume_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "All streams",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_All_streams"
				},
				new CxvAdvCollectionItem
				{
					Display = "Streams",
					DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Streams"
				}
			}
		});

		public static readonly CxvPropertyDeclaration StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
		{
			Parameter = "StreamVisible2"
		});

		private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

		private CxvPropertyWatch varDefnDependencies;

		public object fraVolume_PresUnits => GetValue(fraVolume_PresUnits_Property);

		public object fraVolume_ColCount => GetValue(fraVolume_ColCount_Property);

		public object fraVolume_viewid => GetValue(fraVolume_viewid_Property);

		public object fraVolume_TBPTid => GetValue(fraVolume_TBPTid_Property);

		public object fraVolume_Pressure => GetValue(fraVolume_Pressure_Property);

		public object fraVolume_displayview => GetValue(fraVolume_displayview_Property);

		public object NumCol => GetValue(NumCol_Property);

		public object grdResults_GridData => GetValue(grdResults_GridData_Property);

		public object mnuCurveView_VolumeView => GetValue(mnuCurveView_VolumeView_Property);

		public object mnuCurveView_AdvCollection => GetValue(mnuCurveView_AdvCollection_Property);

		public object mnuPressure_AdvCollection
		{
			get
			{
				if (CxsConverter.ValueToString(ResolveParameter("viewid2")) == "D1160CRV")
				{
					_dictPaths.Clear();
					List<string> list = new List<string>();
					string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.#0", "child_ids"));
					if (array != null)
					{
						string[] array2 = array;
						foreach (string text in array2)
						{
							string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2.#0.\"" + text + "\".#0", "id"));
							list.Add(text + " " + text2);
							_dictPaths.Add(text + " " + text2, "\"" + text + "\"." + text2);
						}
					}
					CxvManualVariableData cxvManualVariableData = new CxvManualVariableData
					{
						ValueOptions = list,
						Value = list[0],
						IsEnabled = true,
						IsReadOnly = false
					};
					cxvManualVariableData.PropertyChanged += pressureData_PropertyChanged;
					pressureData_PropertyChanged(cxvManualVariableData, null);
					return cxvManualVariableData;
				}
				return new CxvManualVariableData
				{
					IsEnabled = false
				};
			}
		}

		public CxvManualVariableData HeaderVolume
		{
			get
			{
				if (_HeaderVolume == null)
				{
					_HeaderVolume = new CxvManualVariableData
					{
						Value = "Volume %"
					};
				}
				return _HeaderVolume;
			}
		}

		public object stream_AdvCollection => GetValue(stream_AdvCollection_Property);

		public object StreamVisible => GetValue(StreamVisible_Property);

		private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
				{
					_varDefnDependencies_PropertyDependencyChangedHandler = delegate
					{
						if (_selectedStreams == null || _selectedStreams.Count == 0)
						{
							helper.SetInitialDisplay();
						}
						ResolveUpdateParameter("selectedStreams2", _selectedStreams);
						ResolveUpdateParameter("availableStreams2", _availableStreams);
						SetComboEnabledArray();
						string text = FindFirstComboItem();
						ResolveUpdateParameter("str_petrocurveview2", text);
						SetVariable(text, "VolumnView");
						SetGridAvailability(text);
					};
				}
				return _varDefnDependencies_PropertyDependencyChangedHandler;
			}
		}

		private void pressureData_PropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			if (sender is CxvManualVariableData { Value: not null } cxvManualVariableData)
			{
				ValuePath = _dictPaths[cxvManualVariableData.Value.ToString()];
			}
		}

		private void SetComboEnabledArray()
		{
			if (varDefnDependencies != null)
			{
				varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
			}
			if (varDefnDependencies != null)
			{
				varDefnDependencies.Clear();
			}
			else
			{
				varDefnDependencies = new CxvPropertyWatch();
			}
			string text = ExpandDataPath("@main2");
			int num = text.IndexOf(".Results Summary");
			if (num < 0)
			{
				return;
			}
			string text2 = text.Substring(0, num);
			if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
			{
				string text3 = "";
				for (int i = 0; i < cxvAdvCollectionPropertyData.Items.Count; i++)
				{
					cxvAdvCollectionPropertyData.Items[i].Entered = false;
					if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
					{
						text3 = "TBPCRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_1)
					{
						text3 = "D86CRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_2)
					{
						text3 = "D1160CRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_3)
					{
						text3 = "VACCRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_4)
					{
						text3 = "APICRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_5)
					{
						text3 = "GRVCRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_6)
					{
						text3 = "MWCRV";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_7)
					{
						text3 = "D86CRVCK";
					}
					int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "has_children", null, varDefnDependencies));
					if (num2.HasValue && num2 > 0)
					{
						cxvAdvCollectionPropertyData.Items[i].Entered = true;
					}
				}
			}
			if (!varDefnDependencies.IsEmpty)
			{
				varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
			}
			else
			{
				varDefnDependencies = null;
			}
		}

		private string FindFirstComboItem()
		{
			string result = null;
			string text = ExpandDataPath("@main2");
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
			{
				string text3 = "";
				foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
				{
					if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
					{
						text3 = "TBPCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_1)
					{
						text3 = "D86CRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_2)
					{
						text3 = "D1160CRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_3)
					{
						text3 = "VACCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_4)
					{
						text3 = "APICRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_5)
					{
						text3 = "GRVCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_6)
					{
						text3 = "MWCRV";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_7)
					{
						text3 = "D86CRVCK";
					}
					int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "child_count"));
					if (num.HasValue && num > 0)
					{
						result = item.Id;
						break;
					}
				}
			}
			return result;
		}

		private void SetVariable(string newValue, string varname)
		{
			if (varname == "VolumnView")
			{
				ResolveUpdateParameter("str_petrocurveview2", newValue);
				string value = "";
				string value2 = "";
				if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
				{
					value = "TBPCRV";
					value2 = "TBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_1)
				{
					value = "D86CRV";
					value2 = "D86TBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_2)
				{
					value = "D1160CRV";
					value2 = "D1160TBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_3)
				{
					value = "VACCRV";
					value2 = "VACTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_4)
				{
					value = "APICRV";
					value2 = "APITBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_5)
				{
					value = "GRVCRV";
					value2 = "GRVTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_6)
				{
					value = "MWCRV";
					value2 = "MWTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Text_7)
				{
					value = "D86CRVCK";
					value2 = "D86CRKX";
				}
				if (_selectedStreams == null || _selectedStreams.Count == 0)
				{
					helper.SetInitialDisplay();
				}
				ResolveUpdateParameter("viewid2", value);
				Collection<string> streams = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid2", "child_ids", null));
				helper.InitAvailableStreams(streams);
				ResolveUpdateParameter("TBPTid2", value2);
				helper.InSetVariable(streams);
			}
		}

		private void SetGridAvailability(string selectedItem)
		{
			if (!(mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData))
			{
				return;
			}
			foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
			{
				if (item.Display == selectedItem)
				{
					ResolveUpdateParameter("VolGridEnabled", item.Entered.Value);
					break;
				}
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				helper = new StreamHelper<grdResults_GridData_ItemTemplate>("StreamVisible2", this, _selectedStreams, _availableStreams, grdResults_GridData, stream_AdvCollection as CxvAdvCollectionPropertyData);
				helper.SetInitialDisplay();
				ResolveUpdateParameter("selectedStreams2", _selectedStreams);
				ResolveUpdateParameter("availableStreams2", _availableStreams);
				SetComboEnabledArray();
				string text = FindFirstComboItem();
				ResolveUpdateParameter("str_petrocurveview2", text);
				SetVariable(text, "VolumnView");
				SetGridAvailability(text);
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Name == "stream_AdvCollection" && subPropertyName == "SelectedItem")
			{
				if (base.View is MMDistcu_Result_Volume mMDistcu_Result_Volume)
				{
					helper.OnStreamChanged(mMDistcu_Result_Volume.grdResults);
				}
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "Items")
			{
				SetComboEnabledArray();
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "SelectedItem")
			{
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = mnuCurveView_AdvCollection as CxvAdvCollectionPropertyData;
				SetVariable(cxvAdvCollectionPropertyData.SelectedItem, "VolumnView");
				SetGridAvailability(cxvAdvCollectionPropertyData.SelectedItem);
				OnPropertyChanged("mnuPressure_AdvCollection");
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		public override void Unload()
		{
			helper.Unload();
			if (varDefnDependencies != null)
			{
				varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
				varDefnDependencies.Clear();
				varDefnDependencies = null;
			}
			base.Unload();
		}
	}
	[ProgId("MMDistcu.MMDistcu_Result_Volume")]
	public class MMDistcu_Result_Volume : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuCurveView_label;

		internal MMAdvancedComboEdit mnuCurveView;

		internal MMLabel mnuPressure_label;

		internal MMComboEdit mnuPressure;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMDistcu_Result_Volume()
		{
			base.ViewModelType = typeof(MMDistcu_Result_Volume_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/dist-curve/mmdistcu_result_volume.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				mnuCurveView_label = (MMLabel)target;
				break;
			case 2:
				mnuCurveView = (MMAdvancedComboEdit)target;
				break;
			case 3:
				mnuPressure_label = (MMLabel)target;
				break;
			case 4:
				mnuPressure = (MMComboEdit)target;
				break;
			case 5:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMDistcu_Result_Weight_ViewModel : MMTabPageViewModel, IFormViewModel
	{
		public class grdResults_GridData_ItemTemplate : MMViewModel, IItemTemplate
		{
			public static readonly CxvPropertyDeclaration mnuDisplayView_DisplayView_Property = CxvPropertyDeclaration.Register("mnuDisplayView_DisplayView", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "DisplayView"
			});

			public static readonly CxvPropertyDeclaration mnuDisplayView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuDisplayView_AdvCollection", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
			{
				UseItemsCollection = true,
				Items = 
				{
					new CxvAdvCollectionItem
					{
						Display = "All streams",
						DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_All_streams"
					},
					new CxvAdvCollectionItem
					{
						Display = "Streams",
						DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Streams"
					}
				},
				SelectedItemBinding = "mnuDisplayView_DisplayView.Value"
			});

			public static readonly CxvPropertyDeclaration MMLBUText1_Units_Property = CxvPropertyDeclaration.Register("MMLBUText1_Units", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Output.@viewid3.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Output.@viewid3.@x.@y"
			});

			public static readonly CxvPropertyDeclaration MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "target"
			});

			public static readonly CxvPropertyDeclaration MMAdvCombo1_selector_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_selector", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3",
				SelectedItemBinding = "MMAdvCombo1_target.Value"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CustomIndexBasis("selectedStreams3", "availableStreams3")
				{
					DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3",
					UseChildId = false,
					Name = "x",
					ProxyRow = false,
					IsNotJagged = true,
					MinimumRows = 1
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid3.@y",
				IsCalculated = true,
				IsReadOnly = true
			});

			public object mnuDisplayView_DisplayView => GetValue(mnuDisplayView_DisplayView_Property);

			public object mnuDisplayView_AdvCollection => GetValue(mnuDisplayView_AdvCollection_Property);

			public object MMLBUText1_Units => GetValue(MMLBUText1_Units_Property);

			public object MMTextBox2_StreamValues => GetValue(MMTextBox2_StreamValues_Property);

			public object MMAdvCombo1_target => GetValue(MMAdvCombo1_target_Property);

			public object MMAdvCombo1_selector => GetValue(MMAdvCombo1_selector_Property);

			public object inner => GetValue(inner_Property);

			public object MMTextBox1_TBPT => GetValue(MMTextBox1_TBPT_Property);
		}

		public class grdResults_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x"
			});

			private CxvPropertyWatch varDefnDependencies;

			private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

			public object id => new CustomStreamSelectedObject<grdResults_GridData_ItemTemplate, MMDistcu_Result_Weight_ViewModel>(this, "selectedStreams3", "availableStreams3", "StreamVisible3");

			public object MMTextBox2_StreamUOM => GetValue(MMTextBox2_StreamUOM_Property);

			public object MMTextBox2_StreamValues => new CxvManualVariableData
			{
				Value = ParamValueValue,
				IsCalculated = true,
				IsReadOnly = true,
				Path = ParamValuePath
			};

			public double? ParamValueValue
			{
				get
				{
					if (varDefnDependencies != null)
					{
						varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
					}
					if (varDefnDependencies != null)
					{
						varDefnDependencies.Clear();
					}
					else
					{
						varDefnDependencies = new CxvPropertyWatch();
					}
					string text = CxsConverter.ValueToString(ResolveParameter("viewid3"));
					string units = CxsConverter.ValueToString(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x", "uom", null, varDefnDependencies));
					if (!varDefnDependencies.IsEmpty)
					{
						varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
					}
					else
					{
						varDefnDependencies = null;
					}
					if (text != "D1160CWT")
					{
						return CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x.@y", "value", units));
					}
					string valuePath = ((base.Parent as grdResults_GridData_ItemTemplate).Parent as MMDistcu_Result_Weight_ViewModel).ValuePath;
					return CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x." + valuePath + ".@y", "value", units));
				}
			}

			public string ParamValuePath
			{
				get
				{
					if (CxsConverter.ValueToString(ResolveParameter("viewid3")) != "D1160CWT")
					{
						return ExpandDataPath("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x.@y");
					}
					string valuePath = ((base.Parent as grdResults_GridData_ItemTemplate).Parent as MMDistcu_Result_Weight_ViewModel).ValuePath;
					return ExpandDataPath("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x." + valuePath + ".@y");
				}
			}

			private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
			{
				get
				{
					if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
					{
						_varDefnDependencies_PropertyDependencyChangedHandler = delegate
						{
							OnPropertyChanged("MMTextBox2_StreamValues");
						};
					}
					return _varDefnDependencies_PropertyDependencyChangedHandler;
				}
			}
		}

		public static readonly CxvPropertyDeclaration fraWeight_PresUnits_Property = CxvPropertyDeclaration.Register("fraWeight_PresUnits", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "PresUnits"
		});

		public static readonly CxvPropertyDeclaration fraWeight_ColCount_Property = CxvPropertyDeclaration.Register("fraWeight_ColCount", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount"
		});

		public static readonly CxvPropertyDeclaration fraWeight_Pressure_Property = CxvPropertyDeclaration.Register("fraWeight_Pressure", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "Pressure"
		});

		public static readonly CxvPropertyDeclaration fraWeight_TBPTid_Property = CxvPropertyDeclaration.Register("fraWeight_TBPTid", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "TBPTid3"
		});

		public static readonly CxvPropertyDeclaration fraWeight_viewid_Property = CxvPropertyDeclaration.Register("fraWeight_viewid", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "viewid3"
		});

		public static readonly CxvPropertyDeclaration NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "ColCount.Output.@viewid3.0"
		});

		public static readonly CxvPropertyDeclaration grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Weight_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdResults_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid3",
				UseChildId = true,
				Name = "y"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "WtGridEnabled",
				Operator = CxvLogicalOperator.Equal,
				Value = true
			}
		});

		private const string paramSelectedStream = "selectedStreams3";

		private const string paramAvailableStream = "availableStreams3";

		private const string paramStreamVisible = "StreamVisible3";

		private StreamHelper<grdResults_GridData_ItemTemplate> helper;

		private ObservableCollection<string> _selectedStreams = new ObservableCollection<string>();

		private ObservableCollection<string> _availableStreams = new ObservableCollection<string>();

		public static readonly CxvPropertyDeclaration mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Weight_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "TBP curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_TBP_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D86 curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D1160 curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vacuum at 10 mmHg curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "API curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_API_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Specific gravity curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "Molecular weight curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D86CRK curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve"
				},
				new CxvAdvCollectionItem
				{
					Display = "ASTM D2887 curve",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D2887_curve"
				}
			},
			SelectedItemBinding = "mnuCurveView_WeightView.Value",
			CreateNewPrompt = "Curve view:",
			CreateNewPromptResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_"
		});

		public static readonly CxvPropertyDeclaration mnuCurveView_WeightView_Property = CxvPropertyDeclaration.Register("mnuCurveView_WeightView", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview3"
		});

		public static readonly CxvPropertyDeclaration stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Weight_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			IsCalculated = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "All streams",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_All_streams"
				},
				new CxvAdvCollectionItem
				{
					Display = "Streams",
					DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Streams"
				}
			}
		});

		public static readonly CxvPropertyDeclaration StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
		{
			Parameter = "StreamVisible3"
		});

		private Dictionary<string, string> _dictPaths = new Dictionary<string, string>();

		public string ValuePath;

		private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

		private CxvPropertyWatch varDefnDependencies;

		public object fraWeight_PresUnits => GetValue(fraWeight_PresUnits_Property);

		public object fraWeight_ColCount => GetValue(fraWeight_ColCount_Property);

		public object fraWeight_Pressure => GetValue(fraWeight_Pressure_Property);

		public object fraWeight_TBPTid => GetValue(fraWeight_TBPTid_Property);

		public object fraWeight_viewid => GetValue(fraWeight_viewid_Property);

		public object NumCol => GetValue(NumCol_Property);

		public object grdResults_GridData => GetValue(grdResults_GridData_Property);

		public object mnuCurveView_AdvCollection => GetValue(mnuCurveView_AdvCollection_Property);

		public object mnuCurveView_WeightView => GetValue(mnuCurveView_WeightView_Property);

		public object stream_AdvCollection => GetValue(stream_AdvCollection_Property);

		public object StreamVisible => GetValue(StreamVisible_Property);

		public object mnuPressure_AdvCollection
		{
			get
			{
				if (CxsConverter.ValueToString(ResolveParameter("viewid3")) == "D1160CWT")
				{
					_dictPaths.Clear();
					List<string> list = new List<string>();
					string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.#0", "child_ids"));
					if (array != null)
					{
						string[] array2 = array;
						foreach (string text in array2)
						{
							string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3.#0.\"" + text + "\".#0", "id"));
							list.Add(text + " " + text2);
							_dictPaths.Add(text + " " + text2, "\"" + text + "\"." + text2);
						}
					}
					CxvManualVariableData cxvManualVariableData = new CxvManualVariableData
					{
						ValueOptions = list,
						Value = list[0],
						IsEnabled = true,
						IsReadOnly = false,
						IsCalculated = true
					};
					cxvManualVariableData.PropertyChanged += pressureData_PropertyChanged;
					pressureData_PropertyChanged(cxvManualVariableData, null);
					return cxvManualVariableData;
				}
				return new CxvManualVariableData
				{
					IsEnabled = false
				};
			}
		}

		private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
				{
					_varDefnDependencies_PropertyDependencyChangedHandler = delegate
					{
						if (_selectedStreams == null || _selectedStreams.Count == 0)
						{
							helper.SetInitialDisplay();
						}
						ResolveUpdateParameter("selectedStreams3", _selectedStreams);
						ResolveUpdateParameter("availableStreams3", _availableStreams);
						SetComboEnabledArray();
						string text = FindFirstComboItem();
						ResolveUpdateParameter("str_petrocurveview3", text);
						SetVariable(text, "WeightView");
						SetGridAvailability(text);
					};
				}
				return _varDefnDependencies_PropertyDependencyChangedHandler;
			}
		}

		private void pressureData_PropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			if (sender is CxvManualVariableData { Value: not null } cxvManualVariableData)
			{
				ValuePath = _dictPaths[cxvManualVariableData.Value.ToString()];
			}
		}

		private void SetComboEnabledArray()
		{
			if (varDefnDependencies != null)
			{
				varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
			}
			if (varDefnDependencies != null)
			{
				varDefnDependencies.Clear();
			}
			else
			{
				varDefnDependencies = new CxvPropertyWatch();
			}
			string text = ExpandDataPath("@main2");
			if (text.IndexOf(".Results Summary") < 0)
			{
				return;
			}
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
			{
				string text3 = "";
				for (int i = 0; i < cxvAdvCollectionPropertyData.Items.Count; i++)
				{
					cxvAdvCollectionPropertyData.Items[i].Entered = false;
					if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
					{
						text3 = "TBPCRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve)
					{
						text3 = "D86CRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve)
					{
						text3 = "D1160CWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve)
					{
						text3 = "VACCRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_API_curve)
					{
						text3 = "APICRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve)
					{
						text3 = "GRVCRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve)
					{
						text3 = "MWCRVWT";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve)
					{
						text3 = "D86WTCKC";
					}
					else if (cxvAdvCollectionPropertyData.Items[i].Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D2887_curve)
					{
						text3 = "D2887CRV";
					}
					int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "has_children", null, varDefnDependencies));
					if (num.HasValue && num > 0)
					{
						cxvAdvCollectionPropertyData.Items[i].Entered = true;
					}
				}
			}
			if (!varDefnDependencies.IsEmpty)
			{
				varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
			}
			else
			{
				varDefnDependencies = null;
			}
		}

		private string FindFirstComboItem()
		{
			string result = null;
			string text = ExpandDataPath("@main2");
			string text2 = text.Substring(0, text.IndexOf(".Results Summary"));
			if (mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData { Items: not null } cxvAdvCollectionPropertyData)
			{
				string text3 = "";
				foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
				{
					if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
					{
						text3 = "TBPCRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve)
					{
						text3 = "D86CRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve)
					{
						text3 = "D1160CWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve)
					{
						text3 = "VACCRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_API_curve)
					{
						text3 = "APICRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve)
					{
						text3 = "GRVCRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve)
					{
						text3 = "MWCRVWT";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve)
					{
						text3 = "D86WTCKC";
					}
					else if (item.Id == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D2887_curve)
					{
						text3 = "D2887CRV";
					}
					int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text2 + ".Results Summary.Stream-Sum.Dist-Curve.Output." + text3, "child_count"));
					if (num.HasValue && num > 0)
					{
						result = item.Id;
						break;
					}
				}
			}
			return result;
		}

		private void SetVariable(string newValue, string varname)
		{
			if (varname == "WeightView")
			{
				ResolveUpdateParameter("str_petrocurveview3", newValue);
				string value = "";
				string value2 = "";
				if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_TBP_curve)
				{
					value = "TBPCRVWT";
					value2 = "TBPWTX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve)
				{
					value = "D86CRVWT";
					value2 = "D86WTX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve)
				{
					value = "D1160CWT";
					value2 = "D1160WTX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve)
				{
					value = "VACCRVWT";
					value2 = "VACWTX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_API_curve)
				{
					value = "APICRVWT";
					value2 = "APIWTX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve)
				{
					value = "GRVCRVWT";
					value2 = "GRVWTTBP";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve)
				{
					value = "MWCRVWT";
					value2 = "MWWTTBPT";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve)
				{
					value = "D86WTCKC";
					value2 = "D86WTCKX";
				}
				else if (newValue == AspenTech.AspenPlus.Localization.Properties.Resources.MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D2887_curve)
				{
					value = "D2887CRV";
					value2 = "D2887TBP";
				}
				if (_selectedStreams == null || _selectedStreams.Count == 0)
				{
					helper.SetInitialDisplay();
				}
				ResolveUpdateParameter("viewid3", value);
				Collection<string> streams = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main2.Stream-Sum.Dist-Curve.Output.@viewid3", "child_ids", null));
				helper.InitAvailableStreams(streams);
				ResolveUpdateParameter("TBPTid3", value2);
				helper.InSetVariable(streams);
			}
		}

		private void SetGridAvailability(string selectedItem)
		{
			if (!(mnuCurveView_AdvCollection is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData))
			{
				return;
			}
			foreach (CxvAdvCollectionPropertyDataItem item in cxvAdvCollectionPropertyData.Items)
			{
				if (item.Display == selectedItem)
				{
					ResolveUpdateParameter("WtGridEnabled", item.Entered.Value);
					break;
				}
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				helper = new StreamHelper<grdResults_GridData_ItemTemplate>("StreamVisible3", this, _selectedStreams, _availableStreams, grdResults_GridData, stream_AdvCollection as CxvAdvCollectionPropertyData);
				helper.SetInitialDisplay();
				ResolveUpdateParameter("selectedStreams3", _selectedStreams);
				ResolveUpdateParameter("availableStreams3", _availableStreams);
				SetComboEnabledArray();
				string text = FindFirstComboItem();
				ResolveUpdateParameter("str_petrocurveview3", text);
				SetVariable(text, "WeightView");
				SetGridAvailability(text);
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "stream_AdvCollection" && subPropertyName == "SelectedItem")
			{
				if (base.View is MMDistcu_Result_Weight mMDistcu_Result_Weight)
				{
					helper.OnStreamChanged(mMDistcu_Result_Weight.grdResults);
				}
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "Items")
			{
				SetComboEnabledArray();
			}
			else if (pd.Name == "mnuCurveView_AdvCollection" && subPropertyName == "SelectedItem")
			{
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = mnuCurveView_AdvCollection as CxvAdvCollectionPropertyData;
				SetVariable(cxvAdvCollectionPropertyData.SelectedItem, "WeightView");
				SetGridAvailability(cxvAdvCollectionPropertyData.SelectedItem);
				OnPropertyChanged("mnuPressure_AdvCollection");
			}
		}

		public override void Unload()
		{
			if (varDefnDependencies != null)
			{
				varDefnDependencies.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
				varDefnDependencies.Clear();
				varDefnDependencies = null;
			}
			base.Unload();
		}
	}
	[ProgId("MMDistcu.MMDistcu_Result_Weight")]
	public class MMDistcu_Result_Weight : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuCurveView_label;

		internal MMAdvancedComboEdit mnuCurveView;

		internal MMLabel mnuPressure_label;

		internal MMComboEdit mnuPressure;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMDistcu_Result_Weight()
		{
			base.ViewModelType = typeof(MMDistcu_Result_Weight_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/dist-curve/mmdistcu_result_weight.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				mnuCurveView_label = (MMLabel)target;
				break;
			case 2:
				mnuCurveView = (MMAdvancedComboEdit)target;
				break;
			case 3:
				mnuPressure_label = (MMLabel)target;
				break;
			case 4:
				mnuPressure = (MMComboEdit)target;
				break;
			case 5:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum
{
	public class MMConv_Summary_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec1_Property = CxvPropertyDeclaration.Register("spec1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.DES_SPEC"
		});

		public static readonly CxvPropertyDeclaration tear1_Property = CxvPropertyDeclaration.Register("tear1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.STREAMID"
		});

		public static readonly CxvPropertyDeclaration tvar1_Property = CxvPropertyDeclaration.Register("tvar1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.DEFVID"
		});

		public static readonly CxvPropertyDeclaration eoconv1_Property = CxvPropertyDeclaration.Register("eoconv1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@spec1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@tear1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@eoconv1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@tvar1" }
		});

		public object spec1 => GetValue(spec1_Property);

		public object tear1 => GetValue(tear1_Property);

		public object tvar1 => GetValue(tvar1_Property);

		public object eoconv1 => GetValue(eoconv1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);
	}
	[ProgId("MMConv_Sum.MMConv_Summary")]
	public class MMConv_Summary : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabSummary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab3;

		internal MMTabItem tab2;

		private bool _contentLoaded;

		public MMConv_Summary()
		{
			base.ViewModelType = typeof(MMConv_Summary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/conv-sum/mmconv_summary.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				tabSummary = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab1 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab2 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMConv_Summary_EOConv_ViewModel : MMTabPageViewModel
	{
		public class grdTear_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox1_var1",
						DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.EOSTAT.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Has not run",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Has_not_run",
						Value = "MMComboBox1_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "0"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Converged",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Converged",
						Value = "MMComboBox1_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "1"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Switch to EO failed",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Switch_to_EO_failed",
						Value = "MMComboBox1_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "2"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Line seach failed",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Line_seach_failed",
						Value = "MMComboBox1_MultiMapOption_4",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "3"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "QP failed",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_QP_failed",
						Value = "MMComboBox1_MultiMapOption_5",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "4"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Not_converged",
						Value = "MMComboBox1_MultiMapOption_6",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "5"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtTear_var1_Property = CxvPropertyDeclaration.Register("txtTear_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID.@y"
			});

			public static readonly CxvPropertyDeclaration cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "cboStat_var1",
						DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMSTAT.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Has not run",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Has_not_run_1",
						Value = "cboStat_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "0"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "No tear stream",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_No_tear_stream",
						Value = "cboStat_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "1"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Converged",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Converged_1",
						Value = "cboStat_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "2"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged",
						DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Not_converged_1",
						Value = "cboStat_MultiMapOption_4",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "3"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtMaxErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMMAXERR.@y"
			});

			public static readonly CxvPropertyDeclaration txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMTOL.@y"
			});

			public static readonly CxvPropertyDeclaration txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.CVBLKID.@y"
			});

			public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

			public object txtTear_var1 => GetValue(txtTear_var1_Property);

			public object cboStat_MultiMap => GetValue(cboStat_MultiMap_Property);

			public object txtMaxErr_var1 => GetValue(txtMaxErr_var1_Property);

			public object txtTol_var1 => GetValue(txtTol_var1_Property);

			public object txtConv_var1 => GetValue(txtConv_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdTear_GridData_Property = CxvPropertyDeclaration.Register("grdTear_GridData", typeof(MMConv_Summary_EOConv_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdTear_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdTear_GridData => GetValue(grdTear_GridData_Property);
	}
	[ProgId("MMConv_Sum.MMConv_Summary_EOConv")]
	public class MMConv_Summary_EOConv : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdTear;

		private bool _contentLoaded;

		public MMConv_Summary_EOConv()
		{
			base.ViewModelType = typeof(MMConv_Summary_EOConv_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/conv-sum/mmconv_summary_eoconv.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				grdTear = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMConv_Summary_Spec_ViewModel : MMTabPageViewModel
	{
		public class grdDesignSpec_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.CONVBLK.@y"
			});

			public static readonly CxvPropertyDeclaration txtVal_var1_Property = CxvPropertyDeclaration.Register("txtVal_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.VAR_VAL.@y"
			});

			public static readonly CxvPropertyDeclaration txtErrTol_var1_Property = CxvPropertyDeclaration.Register("txtErrTol_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR_TOL.@y"
			});

			public static readonly CxvPropertyDeclaration txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.TOLERANCE.@y"
			});

			public static readonly CxvPropertyDeclaration txtErr_var1_Property = CxvPropertyDeclaration.Register("txtErr_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR.@y"
			});

			public static readonly CxvPropertyDeclaration cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "cboStat_var1",
						DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.CVSTAT.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Converged",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged",
						Value = "cboStat_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "#"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged",
						Value = "cboStat_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "*"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged, LB",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged__LB",
						Value = "cboStat_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "* LB"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged, UB",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged__UB",
						Value = "cboStat_MultiMapOption_4",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "* UB"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Converged, LB",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged__LB",
						Value = "cboStat_MultiMapOption_5",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "# LB"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Converged, UB",
						DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged__UB",
						Value = "cboStat_MultiMapOption_6",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "# UB"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtSpec_var1_Property = CxvPropertyDeclaration.Register("txtSpec_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.DES_SPEC.@y"
			});

			public object txtConv_var1 => GetValue(txtConv_var1_Property);

			public object txtVal_var1 => GetValue(txtVal_var1_Property);

			public object txtErrTol_var1 => GetValue(txtErrTol_var1_Property);

			public object txtTol_var1 => GetValue(txtTol_var1_Property);

			public object txtErr_var1 => GetValue(txtErr_var1_Property);

			public object cboStat_MultiMap => GetValue(cboStat_MultiMap_Property);

			public object txtSpec_var1 => GetValue(txtSpec_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdDesignSpec_GridData_Property = CxvPropertyDeclaration.Register("grdDesignSpec_GridData", typeof(MMConv_Summary_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdDesignSpec_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdDesignSpec_GridData => GetValue(grdDesignSpec_GridData_Property);
	}
	[ProgId("MMConv_Sum.MMConv_Summary_Spec")]
	public class MMConv_Summary_Spec : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdDesignSpec;

		private bool _contentLoaded;

		public MMConv_Summary_Spec()
		{
			base.ViewModelType = typeof(MMConv_Summary_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/conv-sum/mmconv_summary_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				grdDesignSpec = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMConv_Summary_Tear_ViewModel : MMTabPageViewModel
	{
		public class grdTear_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTear_var1_Property = CxvPropertyDeclaration.Register("txtTear_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.STREAMID.@y"
			});

			public static readonly CxvPropertyDeclaration cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "cboStat_var1",
						DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.CVSTAT.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Converged",
						DisplayResourceKey = "MMConv_Summary_Tear_ViewModel__CxvMultiMapOption_Display_Converged",
						Value = "cboStat_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "#"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged",
						DisplayResourceKey = "MMConv_Summary_Tear_ViewModel__CxvMultiMapOption_Display_Not_converged",
						Value = "cboStat_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "*"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtMaxErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR2.@y"
			});

			public static readonly CxvPropertyDeclaration txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.TOLERANCE.@y"
			});

			public static readonly CxvPropertyDeclaration txtMaxErrTol_var1_Property = CxvPropertyDeclaration.Register("txtMaxErrTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR_TOL.@y"
			});

			public static readonly CxvPropertyDeclaration txtMaxAbsErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxAbsErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR.@y"
			});

			public static readonly CxvPropertyDeclaration txtVar_var1_Property = CxvPropertyDeclaration.Register("txtVar_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.VARID.@y"
			});

			public static readonly CxvPropertyDeclaration txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.CONVBLK.@y"
			});

			public object txtTear_var1 => GetValue(txtTear_var1_Property);

			public object cboStat_MultiMap => GetValue(cboStat_MultiMap_Property);

			public object txtMaxErr_var1 => GetValue(txtMaxErr_var1_Property);

			public object txtTol_var1 => GetValue(txtTol_var1_Property);

			public object txtMaxErrTol_var1 => GetValue(txtMaxErrTol_var1_Property);

			public object txtMaxAbsErr_var1 => GetValue(txtMaxAbsErr_var1_Property);

			public object txtVar_var1 => GetValue(txtVar_var1_Property);

			public object txtConv_var1 => GetValue(txtConv_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdTear_GridData_Property = CxvPropertyDeclaration.Register("grdTear_GridData", typeof(MMConv_Summary_Tear_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdTear_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdTear_GridData => GetValue(grdTear_GridData_Property);
	}
	[ProgId("MMConv_Sum.MMConv_Summary_Tear")]
	public class MMConv_Summary_Tear : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdTear;

		private bool _contentLoaded;

		public MMConv_Summary_Tear()
		{
			base.ViewModelType = typeof(MMConv_Summary_Tear_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/conv-sum/mmconv_summary_tear.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				grdTear = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMConv_Summary_Tvar_ViewModel : MMTabPageViewModel
	{
		public class grdTvar_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtDefvar_var1_Property = CxvPropertyDeclaration.Register("txtDefvar_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.DEFVID.@y"
			});

			public static readonly CxvPropertyDeclaration cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTvar_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "cboStat_var1",
						DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.CVSTAT.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Converged",
						DisplayResourceKey = "MMConv_Summary_Tvar_ViewModel__CxvMultiMapOption_Display_Converged",
						Value = "cboStat_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "#"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Not converged",
						DisplayResourceKey = "MMConv_Summary_Tvar_ViewModel__CxvMultiMapOption_Display_Not_converged",
						Value = "cboStat_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "cboStat_var1",
								Value = "*"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtErr_var1_Property = CxvPropertyDeclaration.Register("txtErr_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR2.@y"
			});

			public static readonly CxvPropertyDeclaration txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.TOLERANCE.@y"
			});

			public static readonly CxvPropertyDeclaration txtErrTol_var1_Property = CxvPropertyDeclaration.Register("txtErrTol_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR_TOL.@y"
			});

			public static readonly CxvPropertyDeclaration txtAbsErr_var1_Property = CxvPropertyDeclaration.Register("txtAbsErr_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR.@y"
			});

			public static readonly CxvPropertyDeclaration txtDes_var1_Property = CxvPropertyDeclaration.Register("txtDes_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.VARDES.@y"
			});

			public static readonly CxvPropertyDeclaration txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.CONVBLK.@y"
			});

			public static readonly CxvPropertyDeclaration txtCal_var1_Property = CxvPropertyDeclaration.Register("txtCal_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.FBLKID.@y"
			});

			public object txtDefvar_var1 => GetValue(txtDefvar_var1_Property);

			public object cboStat_MultiMap => GetValue(cboStat_MultiMap_Property);

			public object txtErr_var1 => GetValue(txtErr_var1_Property);

			public object txtTol_var1 => GetValue(txtTol_var1_Property);

			public object txtErrTol_var1 => GetValue(txtErrTol_var1_Property);

			public object txtAbsErr_var1 => GetValue(txtAbsErr_var1_Property);

			public object txtDes_var1 => GetValue(txtDes_var1_Property);

			public object txtConv_var1 => GetValue(txtConv_var1_Property);

			public object txtCal_var1 => GetValue(txtCal_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdTvar_GridData_Property = CxvPropertyDeclaration.Register("grdTvar_GridData", typeof(MMConv_Summary_Tvar_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdTvar_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdTvar_GridData => GetValue(grdTvar_GridData_Property);
	}
	[ProgId("MMConv_Sum.MMConv_Summary_Tvar")]
	public class MMConv_Summary_Tvar : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdTvar;

		private bool _contentLoaded;

		public MMConv_Summary_Tvar()
		{
			base.ViewModelType = typeof(MMConv_Summary_Tvar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/conv-sum/mmconv_summary_tvar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				grdTvar = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum
{
	public class MMCO2Emis_Summary_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration hier_id_Property = CxvPropertyDeclaration.Register("hier_id", typeof(MMCO2Emis_Summary_ViewModel), new CxvParameterProperty
		{
			Parameter = "hier_id"
		});

		public object hier_id => GetValue(hier_id_Property);
	}
	[ProgId("MMCO2Emis_Sum.MMCO2Emis_Summary")]
	public class MMCO2Emis_Summary : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMCO2Emis_Summary()
		{
			base.ViewModelType = typeof(MMCO2Emis_Summary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/co2emis-sum/mmco2emis_summary.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMTabStrip1 = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMCO2Emis_Summary_Summary_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea2_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.PSTRMCO2E.@hier_id.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id.@x"
			});

			public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.FSTRMCO2E.@hier_id.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id.@x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id.@x"
			});

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.HCO2TAX.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvParameterProperty
		{
			Parameter = "hier_id"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_var2_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var2", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Utility-Sum.Output.HNETSTRCO2E",
			CreateNewPrompt = "Hierarchy:",
			CreateNewPromptResourceKey = "MMCO2Emis_Summary_Summary_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Hierarchy_"
		});

		public static readonly CxvPropertyDeclaration MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.PSTRMCO2E.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea2_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea2_GridData", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea2_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id",
				UseChildId = true,
				Name = "x"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.HTOTCO2E.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.HUTILCO2E.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.HNETSTRCO2E.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.FSTRMCO2E.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id",
				UseChildId = true,
				Name = "x"
			}
		});

		public object MMLBUText8_var1 => GetValue(MMLBUText8_var1_Property);

		public object MMAdvCombo1_var1 => GetValue(MMAdvCombo1_var1_Property);

		public object MMAdvCombo1_var2 => GetValue(MMAdvCombo1_var2_Property);

		public object MMLBUText7_var1 => GetValue(MMLBUText7_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMScrollArea2_GridData => GetValue(MMScrollArea2_GridData_Property);

		public object MMLBUText5_var1 => GetValue(MMLBUText5_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText6_var1 => GetValue(MMLBUText6_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Name == "MMAdvCombo1_var2" && subPropertyName == "SelectedItem")
			{
				string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("MMAdvCombo1_var2.SelectedItem"));
				text = "\"" + text + "\"";
				ResolveUpdateParameter("hier_id", text);
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMCO2Emis_Sum.MMCO2Emis_Summary_Summary")]
	public class MMCO2Emis_Summary_Summary : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMLBUText8_label;

		internal MMVariableEdit MMLBUText8;

		internal MMScrollArea MMScrollArea1;

		internal MMScrollArea MMScrollArea2;

		private bool _contentLoaded;

		public MMCO2Emis_Summary_Summary()
		{
			base.ViewModelType = typeof(MMCO2Emis_Summary_Summary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/co2emis-sum/mmco2emis_summary_summary.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMAdvCombo1_label = (MMLabel)target;
				break;
			case 2:
				MMAdvCombo1 = (MMComboEdit)target;
				break;
			case 3:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 4:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 5:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 6:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 7:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 8:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 9:
				MMLBUText8_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText8 = (MMVariableEdit)target;
				break;
			case 11:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 12:
				MMScrollArea2 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum
{
	public class MMBlkStrSum_Summar_Heat_ViewModel : MMTabPageViewModel
	{
		public class grdHeat_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Heat Results.Table.#3.@col"
			});

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object cboSubstr_var1 => GetValue(cboSubstr_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstr_var1_Property && subPropertyName == "Value" && cboSubstr_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstr_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdHeat_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Heat Results.Table.#8.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Heat Results.Table.#3.@col"
			});

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

			public object MMTextBox7_var1 => GetValue(MMTextBox7_var1_Property);

			public object cboSubstr_var1 => GetValue(cboSubstr_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstr_var1_Property && subPropertyName == "Value" && cboSubstr_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstr_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox6Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#7"
		});

		public static readonly CxvPropertyDeclaration MMTextBox7Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Heat Results.Table.#8"
		});

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Heat Results.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Heat Results.Table.#0",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData2_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Heat Results.Table.#0",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object MMTextBox6Lab_var1 => GetValue(MMTextBox6Lab_var1_Property);

		public object MMTextBox7Lab_var1 => GetValue(MMTextBox7Lab_var1_Property);

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object grdHeat_GridData => GetValue(grdHeat_GridData_Property);

		public object grdHeat_GridData2 => GetValue(grdHeat_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main.Heat Results.Table");
				if (text != null)
				{
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
					if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Heat Results.Table.#6", "id"))))
					{
						RegularVisibility = Visibility.Visible;
						BatchVisibility = Visibility.Collapsed;
					}
					else
					{
						RegularVisibility = Visibility.Collapsed;
						BatchVisibility = Visibility.Visible;
					}
				}
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == grdHeat_GridData && subPropertyName == "Count" && !base.IsUnloaded && grdHeat_GridData is CxvVectorPropertyData { Count: >0 })
			{
				base.ResolvedCxsProvider.UpdateDataCache();
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_Summar_Heat")]
	public class MMBlkStrSum_Summar_Heat : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdHeat;

		internal MMScrollAreaHorizontal grdHeat2;

		private bool _contentLoaded;

		public MMBlkStrSum_Summar_Heat()
		{
			base.ViewModelType = typeof(MMBlkStrSum_Summar_Heat_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summar_heat.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdHeat = (MMScrollAreaHorizontal)target;
				break;
			case 4:
				grdHeat2 = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_Summar_Load_ViewModel : MMTabPageViewModel
	{
		public class grdLoad_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@loadsum.DUTY.@stream.@row"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@loadsum.TEMP.@stream.@row"
			});

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraStream_stream_Property = CxvPropertyDeclaration.Register("fraStream_stream", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvParameterProperty
		{
			Parameter = "stream"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvAdvCollectionTooltipProperty
		{
			DataPath = "@loadsum.TEMP",
			CreateNewPrompt = "Stream name:",
			CreateNewPromptResourceKey = "MMBlkStrSum_Summar_Load_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_name_"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.DUTY.@stream"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP.@stream"
		});

		public static readonly CxvPropertyDeclaration grdLoad_GridData_Property = CxvPropertyDeclaration.Register("grdLoad_GridData", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLoad_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@loadsum.TEMP.@stream",
				UseChildId = true,
				Name = "row"
			}
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
		});

		public static readonly CxvPropertyDeclaration fraStream_loadsum_Property = CxvPropertyDeclaration.Register("fraStream_loadsum", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum"
		});

		public object fraStream_stream => GetValue(fraStream_stream_Property);

		public object MMAdvCombo1_var1 => GetValue(MMAdvCombo1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object grdLoad_GridData => GetValue(grdLoad_GridData_Property);

		public object loadsum => GetValue(loadsum_Property);

		public object fraStream_loadsum => GetValue(fraStream_loadsum_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == MMAdvCombo1_var1_Property && subPropertyName == "Items" && MMAdvCombo1_var1 != null)
			{
				string text = ExpandDataPath("@main");
				int num = text.LastIndexOf("Blocks.");
				if (num != -1)
				{
					string longNamePath = text.Substring(0, num) + "Streams.[Value]";
					((MMAdvCombo1_var1 as CxvAdvCollectionTooltipData).Property as CxvAdvCollectionTooltipProperty).LongNamePath = longNamePath;
				}
			}
			else if (pd == MMAdvCombo1_var1_Property && subPropertyName == "SelectedItem" && MMAdvCombo1_var1 != null)
			{
				CxvAdvCollectionTooltipData cxvAdvCollectionTooltipData = MMAdvCombo1_var1 as CxvAdvCollectionTooltipData;
				ResolveUpdateParameter("stream", "\"" + cxvAdvCollectionTooltipData.SelectedItem + "\"");
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_Summar_Load")]
	public class MMBlkStrSum_Summar_Load : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMScrollArea grdLoad;

		private bool _contentLoaded;

		public MMBlkStrSum_Summar_Load()
		{
			base.ViewModelType = typeof(MMBlkStrSum_Summar_Load_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summar_load.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMAdvCombo1_label = (MMLabel)target;
				break;
			case 2:
				MMAdvCombo1 = (MMComboEdit)target;
				break;
			case 3:
				grdLoad = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_Summar_Materi_ViewModel : MMTabPageViewModel
	{
		public class grdStreams_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdStreams_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Stream Results.Table.#0",
					UseChildId = true,
					Name = "col"
				}
			});

			public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Stream Results.Table.@row",
				IsCalculated = true
			});

			public object inner => GetValue(inner_Property);

			public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);
		}

		public class grdStreams_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "col"
			});

			public static readonly CxvPropertyDeclaration txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.@row.@col"
			});

			public object cboStreams_var1 => GetValue(cboStreams_var1_Property);

			public object txtTable_var1 => GetValue(txtTable_var1_Property);
		}

		public class GridData_Column_ViewModel : MMViewModel
		{
			public static CxvPropertyDeclaration Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
			{
				DataPath = "@main.Stream Results.Table.#0.@z",
				ExposeAs = CxvVariableTypeCode.IdWithOptions
			});

			public object Uom => GetValue(Uom_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == Uom_Property && subPropertyName == "Value" && Uom != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (Uom as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		private ICommand _cbtStreamTable_Command;

		public static CxvPropertyDeclaration cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvLogicalProperty
		{
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Stream Results.Table.#0",
					DataAttribute = "child_count",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 1
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Stream Results.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Hierarchy streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Hierarchy_streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Display this and child hierarchy streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_this_and_child_hierarchy_strea",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLHIERSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_3",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "<Default>",
					DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display__Default_",
					Value = "cboDisplay_MultiMapOption_4",
					Prompt = "Display default streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_default_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "DEFAULT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Stream Results.TFF File",
			Sorted = true
		});

		private bool _hasSetToDefault;

		public static readonly CxvPropertyDeclaration grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreams_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table",
				UseChildId = false,
				Name = "row"
			}
		});

		public static CxvPropertyDeclaration GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVectorProperty
		{
			IndexBasis = new CxvChildCountIndexBasis
			{
				Name = "z",
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = false
			},
			ItemType = typeof(GridData_Column_ViewModel)
		});

		public ICommand cbtStreamTable_Command
		{
			get
			{
				if (_cbtStreamTable_Command == null)
				{
					_cbtStreamTable_Command = new CxvDelegateCommand<object>(cbtStreamTable_CommandExecute, this, cbtStreamTable_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cbtStreamTable_Command;
			}
		}

		public CxvLogicalPropertyData cbtStreamTable_CommandCanExecute => GetValue(cbtStreamTable_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object cboFormat_var1 => GetValue(cboFormat_var1_Property);

		public object grdStreams_GridData => GetValue(grdStreams_GridData_Property);

		public object GridData_Column => GetValue(GridData_Column_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Name == "cboDisplay_MultiMap" && subPropertyName == "Value")
			{
				string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("cboDisplay_MultiMap.Value"));
				if (text == "cboDisplay_MultiMapOption_4")
				{
					ResolveUpdateViewPropertyPath("cboDisplay_MultiMap.Value", "cboDisplay_MultiMapOption_3");
				}
				else if (text == "cboDisplay_MultiMapOption_3" && cboDisplay_MultiMap is CxvMultiMapPropertyData { Value: not null })
				{
					base.ResolvedCxsProvider.UpdateDataCache();
				}
			}
			else if (pd == GridData_Column_Property && subPropertyName == "Count" && !base.IsUnloaded && GridData_Column is CxvVectorPropertyData { Count: >0 })
			{
				base.ResolvedCxsProvider.UpdateDataCache();
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && !_hasSetToDefault)
			{
				_hasSetToDefault = true;
				string text = ExpandDataPath("@main.Stream Results.Table");
				string path = ExpandDataPath("@main.Output.preload");
				if (text != null)
				{
					try
					{
						InvokeAction(path, "Query", false);
					}
					catch (Exception)
					{
					}
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
				}
			}
			base.OnUpdateData();
		}

		private void cbtStreamTable_CommandExecute(object parameter)
		{
			string path = CxsConverter.ValueToString(ExpandDataPath("@main.Stream Results"));
			Birdcage(hiearchical: true, path);
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_Summar_Materi")]
	public class MMBlkStrSum_Summar_Materi : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMLabel cboFormat_label;

		internal MMComboEdit cboFormat;

		internal MMCmdButton cbtStreamTable;

		internal MMScrollAreaMS grdStreams;

		private bool _contentLoaded;

		public override bool CanPrint => true;

		public MMBlkStrSum_Summar_Materi()
		{
			base.ViewModelType = typeof(MMBlkStrSum_Summar_Materi_ViewModel);
			InitializeComponent();
		}

		public override IEnumerable<FrameworkElement> GeneratePrintPages(Size availablePrintSize)
		{
			string arg = string.Empty;
			if (base.ViewModel != null)
			{
				arg = base.ViewModel.ExpandDataPathAndGet("@main", "id") as string;
			}
			string title = $"Block {arg} Stream Results Material";
			return this.GenerateGenericPrintPages(grdStreams, availablePrintSize, 0, 1, title, ignoreLastColumn: true);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summar_materi.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				cboFormat_label = (MMLabel)target;
				break;
			case 4:
				cboFormat = (MMComboEdit)target;
				break;
			case 5:
				cbtStreamTable = (MMCmdButton)target;
				break;
			case 6:
				grdStreams = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_Summar_Power_ViewModel : MMTabPageViewModel
	{
		public class grdPower_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Power Results.Table.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdPower_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Power Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Power Results.Table.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Power Results.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Power Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Power Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Power Results.Table.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Power Results.Table.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Power Results.Table.#7"
		});

		public static readonly CxvPropertyDeclaration grdPower_GridData_Property = CxvPropertyDeclaration.Register("grdPower_GridData", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPower_GridData_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@main.Power Results.Table",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdPower_GridData2_Property = CxvPropertyDeclaration.Register("grdPower_GridData2", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPower_GridData2_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@main.Power Results.Table",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		private bool _hasSetToDefault;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object MMTextBox3Lab_var1 => GetValue(MMTextBox3Lab_var1_Property);

		public object MMTextBox4Lab_var1 => GetValue(MMTextBox4Lab_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object grdPower_GridData => GetValue(grdPower_GridData_Property);

		public object grdPower_GridData2 => GetValue(grdPower_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && !_hasSetToDefault)
			{
				_hasSetToDefault = true;
				ExpandDataPathAndSet("@main.Work Results.Display", "value", "DEFAULT");
				string text = ExpandDataPath("@main.Power Results.Table");
				string path = ExpandDataPath("@main.Output.preload");
				if (text != null)
				{
					try
					{
						InvokeAction(path, "Query", false);
					}
					catch (Exception)
					{
					}
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
					if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Power Results.Table.#5", "id"))))
					{
						RegularVisibility = Visibility.Visible;
						BatchVisibility = Visibility.Collapsed;
					}
					else
					{
						RegularVisibility = Visibility.Collapsed;
						BatchVisibility = Visibility.Visible;
					}
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_Summar_Power")]
	public class MMBlkStrSum_Summar_Power : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdPower;

		private bool _contentLoaded;

		public MMBlkStrSum_Summar_Power()
		{
			base.ViewModelType = typeof(MMBlkStrSum_Summar_Power_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summar_power.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdPower = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_Summar_Work_ViewModel : MMTabPageViewModel
	{
		public class grdWork_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Work Results.Table.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdWork_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Work Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Work Results.Table.#3.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Blocks.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (cboSubstream_var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
						obj.DescriptionPath = descriptionPath;
						obj.SubObjectTypePath = obj.DescriptionPath;
						obj.StatusPath = obj.SubObjectTypePath;
						obj.ObjectType = obj.SubObjectTypePath;
					}
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDisplay_var1",
					DataPath = "@main.Work Results.Display"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "ALLSTREAMS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDisplay_var1",
							Value = "STREAMS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Work Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Work Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Work Results.Table.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Work Results.Table.#6"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Work Results.Table.#7"
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@main.Work Results.Table",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData2_ItemTemplate),
			IndexBasis = new CxvSecondLevelChildCountIndexBasis
			{
				DataPath = "@main.Work Results.Table",
				UseChildId = false,
				Name = "col"
			}
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		private bool _hasSetToDefault;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object MMTextBox3Lab_var1 => GetValue(MMTextBox3Lab_var1_Property);

		public object MMTextBox4Lab_var1 => GetValue(MMTextBox4Lab_var1_Property);

		public object MMTextBox5Lab_var1 => GetValue(MMTextBox5Lab_var1_Property);

		public object grdWork_GridData => GetValue(grdWork_GridData_Property);

		public object grdWork_GridData2 => GetValue(grdWork_GridData2_Property);

		public Visibility RegularVisibility
		{
			get
			{
				return _RegularVisibility;
			}
			set
			{
				_RegularVisibility = value;
				OnPropertyChanged("RegularVisibility");
			}
		}

		public Visibility BatchVisibility
		{
			get
			{
				return _BatchVisibility;
			}
			set
			{
				_BatchVisibility = value;
				OnPropertyChanged("BatchVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && !_hasSetToDefault)
			{
				_hasSetToDefault = true;
				ExpandDataPathAndSet("@main.Work Results.Display", "value", "DEFAULT");
				string text = ExpandDataPath("@main.Work Results.Table");
				string path = ExpandDataPath("@main.Output.preload");
				if (text != null)
				{
					try
					{
						InvokeAction(path, "Query", false);
					}
					catch (Exception)
					{
					}
					try
					{
						InvokeAction(text, "Preload", false);
					}
					catch (Exception)
					{
					}
					if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Work Results.Table.#5", "id"))))
					{
						RegularVisibility = Visibility.Visible;
						BatchVisibility = Visibility.Collapsed;
					}
					else
					{
						RegularVisibility = Visibility.Collapsed;
						BatchVisibility = Visibility.Visible;
					}
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_Summar_Work")]
	public class MMBlkStrSum_Summar_Work : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdWork;

		internal MMScrollAreaHorizontal grdWork2;

		private bool _contentLoaded;

		public MMBlkStrSum_Summar_Work()
		{
			base.ViewModelType = typeof(MMBlkStrSum_Summar_Work_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summar_work.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				cboDisplay_label = (MMLabel)target;
				break;
			case 2:
				cboDisplay = (MMComboEdit)target;
				break;
			case 3:
				grdWork = (MMScrollAreaHorizontal)target;
				break;
			case 4:
				grdWork2 = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummH_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
		{
			Parameter = "stream"
		});

		public static readonly CxvPropertyDeclaration load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP"
		});

		public static readonly CxvPropertyDeclaration load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.DUTY"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@load1", "@load2" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro31", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8",
				"@petro9"
			}
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
		});

		public object heat1 => GetValue(heat1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object stream => GetValue(stream_Property);

		public object load1 => GetValue(load1_Property);

		public object load2 => GetValue(load2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		public object loadsum => GetValue(loadsum_Property);
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummH")]
	public class MMBlkStrSum_SummH : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMBlkStrSum_SummH()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummH_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summh.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab1 = (MMTabItem)target;
				break;
			case 4:
				tab2 = (MMTabItem)target;
				break;
			case 5:
				tab3 = (MMTabItem)target;
				break;
			case 6:
				tab4 = (MMTabItem)target;
				break;
			case 7:
				tab5 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummM_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summM_Property = CxvPropertyDeclaration.Register("main_summM", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summM"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summM.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summM => GetValue(main_summM_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summM", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summM", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summM", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summM", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summM", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummM")]
	public class MMBlkStrSum_SummM : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummM()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummM_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summm.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMH_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP"
		});

		public static readonly CxvPropertyDeclaration load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.DUTY"
		});

		public static readonly CxvPropertyDeclaration stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "stream"
		});

		public static readonly CxvPropertyDeclaration main_summMH_Property = CxvPropertyDeclaration.Register("main_summMH", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMH"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMH.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@load1", "@load2" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMH.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object load1 => GetValue(load1_Property);

		public object load2 => GetValue(load2_Property);

		public object stream => GetValue(stream_Property);

		public object main_summMH => GetValue(main_summMH_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		public object loadsum => GetValue(loadsum_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			object obj = ExpandDataPathAndGet("@main", "type");
			if (obj != null && "Analyzer" == obj.ToString() && base.View is MMBlkStrSum_SummMH mMBlkStrSum_SummMH)
			{
				MMTabItem mMTabItem = mMBlkStrSum_SummMH.FindName("tab1") as MMTabItem;
				MMTabItem mMTabItem2 = mMBlkStrSum_SummMH.FindName("tab2") as MMTabItem;
				if (mMTabItem != null)
				{
					mMTabItem.Visibility = Visibility.Collapsed;
				}
				if (mMTabItem2 != null)
				{
					mMTabItem2.Visibility = Visibility.Collapsed;
				}
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMH", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMH", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMH", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMH", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMH", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMH")]
	public class MMBlkStrSum_SummMH : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMH()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMH_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmh.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tab7 = (MMTabItem)target;
				break;
			case 9:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMHLW_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMHW_Property = CxvPropertyDeclaration.Register("main_summMHW", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMHW"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMHW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
		});

		public static readonly CxvPropertyDeclaration load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP"
		});

		public static readonly CxvPropertyDeclaration load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.DUTY"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@load1", "@load2" }
		});

		public static readonly CxvPropertyDeclaration tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@main.Power Results.Table" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMHW => GetValue(main_summMHW_Property);

		public object solid => GetValue(solid_Property);

		public object loadsum => GetValue(loadsum_Property);

		public object load1 => GetValue(load1_Property);

		public object load2 => GetValue(load2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object tab8_var => GetValue(tab8_var_Property);

		public object tab9_var => GetValue(tab9_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMHW", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMHW", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMHLW")]
	public class MMBlkStrSum_SummMHLW : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab8;

		internal MMTabItem tab2;

		internal MMTabItem tab9;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMHLW()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMHLW_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmhlw.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab8 = (MMTabItem)target;
				break;
			case 4:
				tab2 = (MMTabItem)target;
				break;
			case 5:
				tab9 = (MMTabItem)target;
				break;
			case 6:
				tab3 = (MMTabItem)target;
				break;
			case 7:
				tab4 = (MMTabItem)target;
				break;
			case 8:
				tab5 = (MMTabItem)target;
				break;
			case 9:
				tab6 = (MMTabItem)target;
				break;
			case 10:
				tab7 = (MMTabItem)target;
				break;
			case 11:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMHLWP_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMHWP"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
		});

		public static readonly CxvPropertyDeclaration load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.TEMP"
		});

		public static readonly CxvPropertyDeclaration load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@loadsum.DUTY"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@load1", "@load2" }
		});

		public static readonly CxvPropertyDeclaration tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object power1 => GetValue(power1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMHWP => GetValue(main_summMHWP_Property);

		public object solid => GetValue(solid_Property);

		public object loadsum => GetValue(loadsum_Property);

		public object load1 => GetValue(load1_Property);

		public object load2 => GetValue(load2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object tab8_var => GetValue(tab8_var_Property);

		public object tab9_var => GetValue(tab9_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMHLWP")]
	public class MMBlkStrSum_SummMHLWP : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab8;

		internal MMTabItem tab2;

		internal MMTabItem tab9;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMHLWP()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMHLWP_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmhlwp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab8 = (MMTabItem)target;
				break;
			case 4:
				tab2 = (MMTabItem)target;
				break;
			case 5:
				tab9 = (MMTabItem)target;
				break;
			case 6:
				tab3 = (MMTabItem)target;
				break;
			case 7:
				tab4 = (MMTabItem)target;
				break;
			case 8:
				tab5 = (MMTabItem)target;
				break;
			case 9:
				tab6 = (MMTabItem)target;
				break;
			case 10:
				tab7 = (MMTabItem)target;
				break;
			case 11:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMHP_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMHWP"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object power1 => GetValue(power1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMHWP => GetValue(main_summMHWP_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab8_var => GetValue(tab8_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMHP")]
	public class MMBlkStrSum_SummMHP : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab9;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMHP()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMHP_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmhp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab9 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tab7 = (MMTabItem)target;
				break;
			case 9:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMHW_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMHW_Property = CxvPropertyDeclaration.Register("main_summMHW", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMHW"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMHW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMHW => GetValue(main_summMHW_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMHW", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMHW", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMHW", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMHW")]
	public class MMBlkStrSum_SummMHW : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMHW()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMHW_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmhw.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tab7 = (MMTabItem)target;
				break;
			case 9:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMHWP_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Heat Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMHWP"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object heat1 => GetValue(heat1_Property);

		public object work1 => GetValue(work1_Property);

		public object power1 => GetValue(power1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMHWP => GetValue(main_summMHWP_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab8_var => GetValue(tab8_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMHWP", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMHWP", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMHWP")]
	public class MMBlkStrSum_SummMHWP : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab9;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMHWP()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMHWP_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmhwp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab9 = (MMTabItem)target;
				break;
			case 5:
				tab3 = (MMTabItem)target;
				break;
			case 6:
				tab4 = (MMTabItem)target;
				break;
			case 7:
				tab5 = (MMTabItem)target;
				break;
			case 8:
				tab6 = (MMTabItem)target;
				break;
			case 9:
				tab7 = (MMTabItem)target;
				break;
			case 10:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMP_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Power Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMP_Property = CxvPropertyDeclaration.Register("main_summMP", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMP"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object power1 => GetValue(power1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMP => GetValue(main_summMP_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMP", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMP", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMP", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMP", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMP", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMP")]
	public class MMBlkStrSum_SummMP : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMP()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMP_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlkStrSum_SummMW_ViewModel : StreamSummaryViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Work Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCURWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_summMW_Property = CxvPropertyDeclaration.Register("main_summMW", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_summMW"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_summMW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		public object mat1 => GetValue(mat1_Property);

		public object work1 => GetValue(work1_Property);

		public object petro2 => GetValue(petro2_Property);

		public object petro3 => GetValue(petro3_Property);

		public object petro4 => GetValue(petro4_Property);

		public object petro5 => GetValue(petro5_Property);

		public object petro6 => GetValue(petro6_Property);

		public object petro7 => GetValue(petro7_Property);

		public object petro8 => GetValue(petro8_Property);

		public object petro9 => GetValue(petro9_Property);

		public object petro10 => GetValue(petro10_Property);

		public object petro11 => GetValue(petro11_Property);

		public object petro12 => GetValue(petro12_Property);

		public object petro13 => GetValue(petro13_Property);

		public object petro14 => GetValue(petro14_Property);

		public object petro15 => GetValue(petro15_Property);

		public object petro16 => GetValue(petro16_Property);

		public object petro17 => GetValue(petro17_Property);

		public object petro18 => GetValue(petro18_Property);

		public object petro19 => GetValue(petro19_Property);

		public object petro20 => GetValue(petro20_Property);

		public object petro21 => GetValue(petro21_Property);

		public object petro22 => GetValue(petro22_Property);

		public object petro23 => GetValue(petro23_Property);

		public object petro24 => GetValue(petro24_Property);

		public object petro25 => GetValue(petro25_Property);

		public object petro26 => GetValue(petro26_Property);

		public object petro27 => GetValue(petro27_Property);

		public object petro28 => GetValue(petro28_Property);

		public object petro29 => GetValue(petro29_Property);

		public object petro30 => GetValue(petro30_Property);

		public object volume1 => GetValue(volume1_Property);

		public object volume2 => GetValue(volume2_Property);

		public object volume3 => GetValue(volume3_Property);

		public object volume4 => GetValue(volume4_Property);

		public object volume5 => GetValue(volume5_Property);

		public object volume6 => GetValue(volume6_Property);

		public object volume7 => GetValue(volume7_Property);

		public object volume8 => GetValue(volume8_Property);

		public object weight1 => GetValue(weight1_Property);

		public object weight2 => GetValue(weight2_Property);

		public object weight3 => GetValue(weight3_Property);

		public object weight4 => GetValue(weight4_Property);

		public object weight5 => GetValue(weight5_Property);

		public object weight6 => GetValue(weight6_Property);

		public object weight7 => GetValue(weight7_Property);

		public object weight8 => GetValue(weight8_Property);

		public object poly => GetValue(poly_Property);

		public object weight9 => GetValue(weight9_Property);

		public object petro1 => GetValue(petro1_Property);

		public object petro31 => GetValue(petro31_Property);

		public object str_petrocurveview => GetValue(str_petrocurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_summMW => GetValue(main_summMW_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object OutputNode => GetValue(OutputNode_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					if (text.EndsWith("Data.Results Summary"))
					{
						ResolveUpdateParameter("main_summMW", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_summMW", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_summMW", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_summMW", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_summMW", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}
	}
	[ProgId("MMBlkStrSum.MMBlkStrSum_SummMW")]
	public class MMBlkStrSum_SummMW : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tabBatch;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is StreamSummaryViewModel streamSummaryViewModel)
				{
					return streamSummaryViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMBlkStrSum_SummMW()
		{
			base.ViewModelType = typeof(MMBlkStrSum_SummMW_ViewModel);
			InitializeComponent();
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			UpdateTabs(newContainer);
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		private void UpdateTabs(IUnityContainer container)
		{
			if (container != null && MMControlHelper.IsRegistryOpen(container, "KeepOldStreamSummaryForm"))
			{
				MMTabItem item = new MMTabItem
				{
					VariablePath = "tab0_var",
					Header = "Material(old)",
					ContentType = typeof(MMBlkStrSum_Summar_Materi)
				};
				MMSSTab1.Items.Add(item);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Results_Summary;component/blkstream-sum/mmblkstrsum_summmw.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
				MMSSTab1 = (MMTabStrip)target;
				break;
			case 2:
				tab1 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tabBatch = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
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

// 0x0600001e AspenTech.AspenPlus.MMForms.Results_Summary.CustomStreamSelectedObject`2.add_PropertyChanged
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

// 0x0600001f AspenTech.AspenPlus.MMForms.Results_Summary.CustomStreamSelectedObject`2.remove_PropertyChanged
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

// 0x06000040 AspenTech.AspenPlus.MMForms.Results_Summary.StreamSummaryViewModel..ctor
// public StreamSummaryViewModel()
// {
// }

// 0x06000049 AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_ViewModel..ctor
// public MMUtil_Summary_ViewModel()
// {
// }

// 0x0600004a AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMUtil_Summary_ViewModel()
// {
// 	var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.UTIL_TYPE"
// 	});
// 	var2_Property = CxvPropertyDeclaration.Register("var2", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NET_DUTY"
// 	});
// 	var3_Property = CxvPropertyDeclaration.Register("var3", typeof(MMUtil_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
// 	});
// 	hier_id_Property = CxvPropertyDeclaration.Register("hier_id", typeof(MMUtil_Summary_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "hier_id"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMUtil_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@var2", "@var3" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMUtil_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@var1" }
// 	});
// }

// 0x06000066 AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Overview_ViewModel..ctor
// public MMUtil_Summary_Overview_ViewModel()
// {
// }

// 0x06000067 AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Overview_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMUtil_Summary_Overview_ViewModel()
// {
// 	MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_HEAT_DUTY"
// 	});
// 	MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_HEAT_DUTY"
// 	});
// 	MMTextBox9_var1_Property = CxvPropertyDeclaration.Register("MMTextBox9_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_COOL_DUTY"
// 	});
// 	MMTextBox10_var1_Property = CxvPropertyDeclaration.Register("MMTextBox10_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NET_DUTY"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_HEAT_COST"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_COOL_COST"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NET_COST"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FEEDSTR_COST"
// 	});
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PRODSTR_COST"
// 	});
// 	MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_COOL_DUTY"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NET_DUTY"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_HEAT_COST"
// 	});
// 	MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOT_COOL_COST"
// 	});
// 	MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NET_COST"
// 	});
// 	MMLBUText12_var1_Property = CxvPropertyDeclaration.Register("MMLBUText12_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FEEDSTR_COST"
// 	});
// 	MMLBUText11_var1_Property = CxvPropertyDeclaration.Register("MMLBUText11_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PRODSTR_COST"
// 	});
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.NETSTR_COST"
// 	});
// 	MMLBUText13_var1_Property = CxvPropertyDeclaration.Register("MMLBUText13_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELECPOWER"
// 	});
// 	MMTextBox13_var1_Property = CxvPropertyDeclaration.Register("MMTextBox13_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELECPOWER"
// 	});
// 	MMLBUText14_var1_Property = CxvPropertyDeclaration.Register("MMLBUText14_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELECCOST"
// 	});
// 	MMTextBox14_var1_Property = CxvPropertyDeclaration.Register("MMTextBox14_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELECCOST"
// 	});
// 	MMLBUText15_var1_Property = CxvPropertyDeclaration.Register("MMLBUText15_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOTUTCOST"
// 	});
// 	MMTextBox15_var1_Property = CxvPropertyDeclaration.Register("MMTextBox15_var1", typeof(MMUtil_Summary_Overview_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TOTUTCOST"
// 	});
// }

// 0x0600007b AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Sum_ViewModel..ctor
// public MMUtil_Summary_Sum_ViewModel()
// {
// }

// 0x0600007c AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Sum_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMUtil_Summary_Sum_ViewModel()
// {
// 	MMLBUText15_var1_Property = CxvPropertyDeclaration.Register("MMLBUText15_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.BLKCO2RATE"
// 	});
// 	MMLBUText14_var1_Property = CxvPropertyDeclaration.Register("MMLBUText14_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMFACTOR"
// 	});
// 	MMLBUText13_var1_Property = CxvPropertyDeclaration.Register("MMLBUText13_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENTH_IN"
// 	});
// 	MMLBUText12_var1_Property = CxvPropertyDeclaration.Register("MMLBUText12_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENTH_OUT"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PPRICE"
// 	});
// 	MMLBUText11_var1_Property = CxvPropertyDeclaration.Register("MMLBUText11_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.OUT_PRES"
// 	});
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.IN_PRES"
// 	});
// 	MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.OUT_TEMP"
// 	});
// 	MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.IN_TEMP"
// 	});
// 	MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TRATE"
// 	});
// 	MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.DUTY"
// 	});
// 	MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HCOOL"
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TCOST"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENERGY_PRICE"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELEC_PRICE"
// 	});
// 	grdUtlSum_GridData_Property = CxvPropertyDeclaration.Register("grdUtlSum_GridData", typeof(MMUtil_Summary_Sum_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdUtlSum_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Utility-Sum.Output.UTIL_TYPE",
// 			UseChildId = true,
// 			Name = "x"
// 		}
// 	});
// }

// 0x060000ce AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_ViewModel..ctor
// public MMStreamSum_Summar_ViewModel()
// {
// }

// 0x060000cf AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Stream-Sum.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work-Sum.Table"
// 	});
// 	power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power-Sum.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRVWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stream"
// 	});
// 	load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP"
// 	});
// 	load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.duty"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@load1", "@load2" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro31", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8",
// 			"@petro9"
// 		}
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	main_summar_Property = CxvPropertyDeclaration.Register("main_summar", typeof(MMStreamSum_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summar"
// 	});
// 	tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMStreamSum_Summar_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@main_summar.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM" }
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output"
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMStreamSum_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summar.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x060000e6 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel..ctor
// using System.Windows;
//
// public MMStreamSum_Summar_Heat_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x060000e7 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Heat_ViewModel()
// {
// 	houtp_Property = CxvPropertyDeclaration.Register("houtp", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table"
// 	});
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@houtp.#3"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@houtp.#4"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@houtp.#5"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat-Sum.Table.#6"
// 	});
// 	MMTextBox6Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat-Sum.Table.#7"
// 	});
// 	MMTextBox7Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7Lab_var1", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat-Sum.Table.#8"
// 	});
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Heat-Sum.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "All hierarchy streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
// 				Value = "cboDisplay_MultiMapOption_3",
// 				Prompt = "Display all hierarchy streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLHIERSTREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@houtp",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMStreamSum_Summar_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData2_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Heat-Sum.Table.#0",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x060000ee AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.LocalMMScrollArea..ctor
// public LocalMMScrollArea()
// {
// }

// 0x060000f5 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Load_ViewModel..ctor
// public MMStreamSum_Summar_Load_ViewModel()
// {
// }

// 0x060000f6 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Load_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Load_ViewModel()
// {
// 	MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvAdvCollectionTooltipProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP",
// 		CreateNewPrompt = "Stream name:",
// 		CreateNewPromptResourceKey = "MMStreamSum_Summar_Load_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_name_"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output.DUTY.@stream"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream"
// 	});
// 	grdLoad_GridData_Property = CxvPropertyDeclaration.Register("grdLoad_GridData", typeof(MMStreamSum_Summar_Load_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLoad_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream",
// 			UseChildId = true,
// 			Name = "row"
// 		}
// 	});
// }

// 0x06000106 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel..ctor
// public MMStreamSum_Summar_Materi_ViewModel()
// {
// }

// 0x06000107 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Materi_ViewModel()
// {
// 	cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvLogicalProperty
// 	{
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main.Stream-Sum.Stream-Sum.Table.#0",
// 				DataAttribute = "child_count",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 1
// 			}
// 		}
// 	});
// 	outp_Property = CxvPropertyDeclaration.Register("outp", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Stream-Sum.Table"
// 	});
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Stream-Sum.Stream-Sum.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Hierarchy streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Hierarchy_streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Display this and child hierarchy streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_this_and_child_hierarchy_strea",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLHIERSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_3",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Stream-Sum.Stream-Sum.TFF File",
// 		Sorted = true
// 	});
// 	GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			Name = "z",
// 			DataPath = "@outp.#0",
// 			UseChildId = false
// 		},
// 		ItemType = typeof(GridData_Column_ViewModel)
// 	});
// 	grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMStreamSum_Summar_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@outp",
// 			UseChildId = false,
// 			Name = "row"
// 		}
// 	});
// }

// 0x0600011f AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel..ctor
// using System.Windows;
//
// public MMStreamSum_Summar_Power_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000120 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Power_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Power-Sum.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "All hierarchy streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
// 				Value = "cboDisplay_MultiMapOption_3",
// 				Prompt = "Display all hierarchy streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLHIERSTREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	poutp_Property = CxvPropertyDeclaration.Register("poutp", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power-Sum.Table"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@poutp.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@poutp.#3"
// 	});
// 	MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@poutp.#5"
// 	});
// 	MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@poutp.#6"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@poutp.#7"
// 	});
// 	grdPower_GridData_Property = CxvPropertyDeclaration.Register("grdPower_GridData", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPower_GridData_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@poutp",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdPower_GridData2_Property = CxvPropertyDeclaration.Register("grdPower_GridData2", typeof(MMStreamSum_Summar_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPower_GridData2_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@poutp",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x0600015d AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel..ctor
// public MMStreamSum_Summar_Solids_ViewModel()
// {
// }

// 0x0600015e AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Solids_ViewModel()
// {
// 	main_solid_Property = CxvPropertyDeclaration.Register("main_solid", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_solid"
// 	});
// 	MMComboBox1_var2_Property = CxvPropertyDeclaration.Register("MMComboBox1_var2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stream"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM",
// 		SelectedItemBinding = "MMComboBox1_var2.Value"
// 	});
// 	MMComboBox2_var2_Property = CxvPropertyDeclaration.Register("MMComboBox2_var2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "sub"
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Property = new CxvAdvCollectionProperty
// 				{
// 					UseItemsCollection = true,
// 					Items = 
// 					{
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "PSD Averages",
// 							DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_MMComboBox2_var1_CxvAdvCollectionItem2"
// 						},
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "PSD(Particle size distribution)",
// 							DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_MMComboBox2_var1_CxvAdvCollectionItem1"
// 						}
// 					},
// 					SelectedItemBinding = "MMComboBox2_var2.Value"
// 				}
// 			}
// 		}
// 	});
// 	ogrOption1_MultiMap_Property = CxvPropertyDeclaration.Register("ogrOption1_MultiMap", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrOption1_var1",
// 				Parameter = "opt1"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Fractions",
// 				DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption1_MultiMapOption_1",
// 				Value = "ogrOption1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrOption1_var1",
// 						Value = "SUBS-ATTR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cumulate fractions",
// 				DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption1_MultiMapOption_2",
// 				Value = "ogrOption1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrOption1_var1",
// 						Value = "TOTAL"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Parameter = "sub",
// 			Value = "PSD(Particle size distribution)"
// 		}
// 	});
// 	ogrOption2_MultiMap_Property = CxvPropertyDeclaration.Register("ogrOption2_MultiMap", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrOption2_var1",
// 				Parameter = "opt2"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Wet basis",
// 				DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption2_MultiMapOption_1",
// 				Value = "ogrOption2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrOption2_var1",
// 						Value = "WET"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Dry basis",
// 				DisplayResourceKey = "MMStreamSum_Summar_Solids_ViewModel_ogrOption2_MultiMapOption_2",
// 				Value = "ogrOption2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrOption2_var1",
// 						Value = "DRY"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Parameter = "sub",
// 			Value = "Moisture Content"
// 		}
// 	});
// 	grdPSD_GridData_Property = CxvPropertyDeclaration.Register("grdPSD_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPSD_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream",
// 			UseChildId = true,
// 			Name = "row"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "PSD_1_Visible.Value"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "PSD_1_Enable.Value"
// 		}
// 	});
// 	txtUnit_var1_Property = CxvPropertyDeclaration.Register("txtUnit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			Name = "z",
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
// 			UseChildId = true
// 		},
// 		ItemType = typeof(GridData_Column_ViewModel)
// 	});
// 	grdPSDA_GridData_Property = CxvPropertyDeclaration.Register("grdPSDA_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPSDA_GridData_ItemTemplate),
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream",
// 			UseChildId = true,
// 			Name = "row"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "PSDA_Visible.Value"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "PSDA_Enable.Value"
// 		}
// 	});
// 	grdMC_GridData_Property = CxvPropertyDeclaration.Register("grdMC_GridData", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMC_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			UseChildId = true,
// 			Name = "row"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "MC_Visible.Value"
// 		}
// 	});
// 	GridData_Column2_Property = CxvPropertyDeclaration.Register("GridData_Column2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
// 			UseChildId = true,
// 			Name = "col"
// 		},
// 		ItemType = typeof(GridData_Column2_ViewModel)
// 	});
// 	D10Unit_var1_Property = CxvPropertyDeclaration.Register("D10Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10"
// 	});
// 	D20Unit_var1_Property = CxvPropertyDeclaration.Register("D20Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D20"
// 	});
// 	D25Unit_var1_Property = CxvPropertyDeclaration.Register("D25Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25"
// 	});
// 	D50Unit_var1_Property = CxvPropertyDeclaration.Register("D50Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D50"
// 	});
// 	D63Unit_var1_Property = CxvPropertyDeclaration.Register("D63Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D63"
// 	});
// 	D75Unit_var1_Property = CxvPropertyDeclaration.Register("D75Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D75"
// 	});
// 	D80Unit_var1_Property = CxvPropertyDeclaration.Register("D80Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D80"
// 	});
// 	D90Unit_var1_Property = CxvPropertyDeclaration.Register("D90Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D90"
// 	});
// 	D95Unit_var1_Property = CxvPropertyDeclaration.Register("D95Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D95"
// 	});
// 	D100Unit_var1_Property = CxvPropertyDeclaration.Register("D100Unit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D100"
// 	});
// 	SMDUnit_var1_Property = CxvPropertyDeclaration.Register("SMDUnit_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SMD"
// 	});
// 	SVUnit_var1_Property = CxvPropertyDeclaration.Register("SVUnit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SV"
// 	});
// 	D43Unit_var1_Property = CxvPropertyDeclaration.Register("D43Unit_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D43"
// 	});
// 	PSD_1_Visible_Property = CxvPropertyDeclaration.Register("PSD_1_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "PSD(Particle size distribution)"
// 			}
// 		}
// 	});
// 	PSD_1_Enable_Property = CxvPropertyDeclaration.Register("PSD_1_Enable", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "PSD(Particle size distribution)"
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
// 				DataAttribute = "child_count",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = "0"
// 			}
// 		}
// 	});
// 	PSD_2_Visible_Property = CxvPropertyDeclaration.Register("PSD_2_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "PSD(Particle size distribution)"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "opt1",
// 				Value = "TOTAL"
// 			}
// 		}
// 	});
// 	PSDA_Visible_Property = CxvPropertyDeclaration.Register("PSDA_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "PSD Averages"
// 			}
// 		}
// 	});
// 	PSDA_Enable_Property = CxvPropertyDeclaration.Register("PSDA_Enable", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "PSD Averages"
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
// 				DataAttribute = "child_count",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = "0"
// 			}
// 		}
// 	});
// 	MC_Visible_Property = CxvPropertyDeclaration.Register("MC_Visible", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "sub",
// 				Value = "Moisture Content"
// 			}
// 		}
// 	});
// 	txtUnit_2_var1_Property = CxvPropertyDeclaration.Register("txtUnit_2_var1", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	GridData_Column_2_Property = CxvPropertyDeclaration.Register("GridData_Column_2", typeof(MMStreamSum_Summar_Solids_ViewModel), new CxvVectorProperty
// 	{
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			Name = "z",
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
// 			UseChildId = true
// 		},
// 		ItemType = typeof(GridData_Column_2_ViewModel)
// 	});
// }

// 0x06000170 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel..ctor
// using System.Windows;
//
// public MMStreamSum_Summar_Work_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000171 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMStreamSum_Summar_Work_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Work-Sum.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "All hierarchy streams",
// 				DisplayResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_hierarchystreams",
// 				Value = "cboDisplay_MultiMapOption_3",
// 				Prompt = "Display all hierarchy streams",
// 				PromptResourceKey = "MMStreamSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_hierarchystreams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLHIERSTREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	woutp_Property = CxvPropertyDeclaration.Register("woutp", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work-Sum.Table"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@woutp.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@woutp.#3"
// 	});
// 	MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@woutp.#5"
// 	});
// 	MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@woutp.#6"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@woutp.#7"
// 	});
// 	grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@woutp",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMStreamSum_Summar_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData2_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@woutp",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x06000185 AspenTech.AspenPlus.MMForms.Results_Summary.Run_Status.MMRun_Status_Summar_ViewModel..ctor
// public MMRun_Status_Summar_ViewModel()
// {
// }

// 0x06000186 AspenTech.AspenPlus.MMForms.Results_Summary.Run_Status.MMRun_Status_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMRun_Status_Summar_ViewModel()
// {
// 	lbtuDescr_var1_Property = CxvPropertyDeclaration.Register("lbtuDescr_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.DESCRIPTION",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuVer_var1_Property = CxvPropertyDeclaration.Register("lbtuVer_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.VERNO",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuSiteid_var1_Property = CxvPropertyDeclaration.Register("lbtuSiteid_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.SITEID"
// 	});
// 	lbtuNodename_var1_Property = CxvPropertyDeclaration.Register("lbtuNodename_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.NODENAME",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuMachine_var1_Property = CxvPropertyDeclaration.Register("lbtuMachine_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.MACHINE",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuUser_var1_Property = CxvPropertyDeclaration.Register("lbtuUser_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.USER",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuDate_var1_Property = CxvPropertyDeclaration.Register("lbtuDate_var1", typeof(MMRun_Status_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Status.Output.ITDATE"
// 	});
// 	cboUosStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboUosStat_MultiMap", typeof(MMRun_Status_Summar_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboUosStat_var1",
// 				DataPath = "@main.Run-Status.Output.UOSSTAT2"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Simulation was completed normally",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Simulation_was_completed_normally",
// 				Value = "cboUosStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Simulation was not completed normally, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Simulation_was_not_completed_normally__use_",
// 				Value = "cboUosStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "3"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Data regression was completed normally",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Data_regression_was_completed_normally",
// 				Value = "cboUosStat_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "4"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Data regression was completed with errors, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Data_regression_was_completed_with_errors__",
// 				Value = "cboUosStat_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "5"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Assay data analysis was completed normally",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Assay_data_analysis_was_completed_normally",
// 				Value = "cboUosStat_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "6"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Assay data analysis was completed with errors, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Assay_data_analysis_was_completed_with_erro",
// 				Value = "cboUosStat_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "7"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Calculations were completed normally",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_normally",
// 				Value = "cboUosStat_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "8"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Calculations were completed with errors, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_with_errors__us",
// 				Value = "cboUosStat_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "9"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Calculations were completed with warnings, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Calculations_were_completed_with_warnings__",
// 				Value = "cboUosStat_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboUosStat_var1",
// 						Value = "10"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboTotStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboTotStat_MultiMap", typeof(MMRun_Status_Summar_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboTotStat_var1",
// 				DataPath = "@main.Run-Status.Output.ITSTAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "There are warnings during input translation, use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_There_are_warnings_during_input_translation",
// 				Value = "cboTotStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTotStat_var1",
// 						Value = "4"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Use_status_button_for_details",
// 				Value = "cboTotStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTotStat_var1",
// 						Value = "1"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Use status button for details",
// 				DisplayResourceKey = "MMRun_Status_Summar_ViewModel__CxvMultiMapOption_Display_Use_status_button_for_details_1",
// 				Value = "cboTotStat_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTotStat_var1",
// 						Value = "16"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = " ",
// 				Value = "cboTotStat_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTotStat_var1",
// 						Value = "0"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuVer_var2_Property = CxvPropertyDeclaration.Register("lbtuVer_var2", typeof(MMRun_Status_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ParamVersionLabel"
// 	});
// }

// 0x06000198 AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel..ctor
// using System.Collections.ObjectModel;
//
// public MMPolycur_Result_Csd_ViewModel()
// {
// 	_selectedStreams = new ObservableCollection<string>();
// 	_availableStreams = new ObservableCollection<string>();
// 	base..ctor();
// }

// 0x06000199 AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolycur_Result_Csd_ViewModel()
// {
// 	fraPoly_ColCount_Property = CxvPropertyDeclaration.Register("fraPoly_ColCount", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount"
// 	});
// 	fraPoly_viewid_Property = CxvPropertyDeclaration.Register("fraPoly_viewid", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "viewid4"
// 	});
// 	fraPoly_DPid_Property = CxvPropertyDeclaration.Register("fraPoly_DPid", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "DPid"
// 	});
// 	grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMPolycur_Result_Csd_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@DPid",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	mnuCurveView_PetroView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PetroView", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview4"
// 	});
// 	mnuCurveView_PCurView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PCurView", typeof(MMPolycur_Result_Csd_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "PCurView"
// 	});
// 	stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMPolycur_Result_Csd_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_Diaplay_All_Streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_Diaplay_Streams"
// 			}
// 		}
// 	});
// 	mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMPolycur_Result_Csd_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Chain size",
// 				DisplayResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionItem_Display_Chain_size"
// 			}
// 		},
// 		SelectedItemBinding = "mnuCurveView_PCurView.Value",
// 		CreateNewPrompt = "View:",
// 		CreateNewPromptResourceKey = "MMPolycur_Result_Csd_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_View_",
// 		CreateNewInputMask = 2,
// 		IsCalculated = true
// 	});
// }

// 0x060001ac AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel..ctor
// using System.Collections.ObjectModel;
//
// public MMDistcu_Result_Petro_ViewModel()
// {
// 	_selectedStreams = new ObservableCollection<string>();
// 	_availableStreams = new ObservableCollection<string>();
// 	base..ctor();
// }

// 0x060001ad AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMDistcu_Result_Petro_ViewModel()
// {
// 	fraPetro_ColCount_Property = CxvPropertyDeclaration.Register("fraPetro_ColCount", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount"
// 	});
// 	fraPetro_viewid_Property = CxvPropertyDeclaration.Register("fraPetro_viewid", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "viewid"
// 	});
// 	fraPetro_TBPTid_Property = CxvPropertyDeclaration.Register("fraPetro_TBPTid", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "TBPTid"
// 	});
// 	mnuCurveView_PetroView_Property = CxvPropertyDeclaration.Register("mnuCurveView_PetroView", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Petro_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid",
// 			UseChildId = false,
// 			Name = "y",
// 			IsNotJagged = true,
// 			ProxyRow = false
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "PetroGridEnabled",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = true
// 		}
// 	});
// 	mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Petro_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Aniline point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Aniline_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Aromatic content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Aromatic_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Asphaltene content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Asphaltene_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Basic nitrogen content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Basic_nitrogen_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Bromine number",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Bromine_number"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Carbon residue",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Carbon_residue"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Cetane number",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Cetane_number"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Cloud point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Cloud_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Conradson carbon content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Conradson_carbon_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Hydrogen content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Hydrogen_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Flash point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Flash_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Freeze point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Freeze_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Iron content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Iron_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Antiknock index",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Antiknock_index"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Kinematic viscosity",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Luminometer number",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Luminometer_number"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Mercaptan content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Mercaptan_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Metal content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Metal_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Motor octane number",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Motor_octane_number"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Naphthene content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Naphthene_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Nickel content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Nickel_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Olefin content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Olefin_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Oxygen content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Oxygen_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Paraffin content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Paraffin_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Pour point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Pour_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Refractive index",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Refractive_index"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Research octane number",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Research_octane_number"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Reid vapor pressure",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Reid_vapor_pressure"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Smoke point",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Smoke_point"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Sulfur content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Sulfur_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Total nitrogen content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Total_nitrogen_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vanadium content",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Vanadium_content"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Viscosity",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Viscosity"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vapor knock index",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Vapor_knock_index"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Warm-up index",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Warm_up_index"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Watson UOP K curve",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Watson_UOP_K_curve"
// 			}
// 		},
// 		SelectedItemBinding = "mnuCurveView_PetroView.Value",
// 		CreateNewPrompt = "Curve view:",
// 		CreateNewPromptResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_",
// 		CreateNewInputMask = 2
// 	});
// 	stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Petro_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_All_Streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDistcu_Result_Petro_ViewModel__CxvAdvCollectionItem_Display_Streams"
// 			}
// 		}
// 	});
// 	StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "StreamVisible"
// 	});
// }

// 0x060001c8 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel..ctor
// using System.Collections.Generic;
// using System.Collections.ObjectModel;
//
// public MMDistcu_Result_Volume_ViewModel()
// {
// 	_selectedStreams = new ObservableCollection<string>();
// 	_availableStreams = new ObservableCollection<string>();
// 	_dictPaths = new Dictionary<string, string>();
// 	base..ctor();
// }

// 0x060001c9 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMDistcu_Result_Volume_ViewModel()
// {
// 	fraVolume_PresUnits_Property = CxvPropertyDeclaration.Register("fraVolume_PresUnits", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "PresUnits"
// 	});
// 	fraVolume_ColCount_Property = CxvPropertyDeclaration.Register("fraVolume_ColCount", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount"
// 	});
// 	fraVolume_viewid_Property = CxvPropertyDeclaration.Register("fraVolume_viewid", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "viewid2"
// 	});
// 	fraVolume_TBPTid_Property = CxvPropertyDeclaration.Register("fraVolume_TBPTid", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "TBPTid2"
// 	});
// 	fraVolume_Pressure_Property = CxvPropertyDeclaration.Register("fraVolume_Pressure", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Pressure"
// 	});
// 	fraVolume_displayview_Property = CxvPropertyDeclaration.Register("fraVolume_displayview", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "displayview"
// 	});
// 	NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount.Output.@viewid2.0"
// 	});
// 	grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Volume_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid2",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "VolGridEnabled",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = true
// 		}
// 	});
// 	mnuCurveView_VolumeView_Property = CxvPropertyDeclaration.Register("mnuCurveView_VolumeView", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview2"
// 	});
// 	mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Volume_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "TBP curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_TBP_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D86 curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D1160 curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vacuum at 10 mmHg curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "API curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_API_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Specific gravity curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Molecular weight curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D86CRK curve",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve"
// 			}
// 		},
// 		SelectedItemBinding = "mnuCurveView_VolumeView.Value",
// 		CreateNewPrompt = "Curve view:",
// 		CreateNewPromptResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_",
// 		CreateNewInputMask = 2
// 	});
// 	stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Volume_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_All_streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Streams"
// 			}
// 		}
// 	});
// 	StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Volume_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "StreamVisible2"
// 	});
// }

// 0x060001e3 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel..ctor
// using System.Collections.Generic;
// using System.Collections.ObjectModel;
//
// public MMDistcu_Result_Weight_ViewModel()
// {
// 	_selectedStreams = new ObservableCollection<string>();
// 	_availableStreams = new ObservableCollection<string>();
// 	_dictPaths = new Dictionary<string, string>();
// 	base..ctor();
// }

// 0x060001e4 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMDistcu_Result_Weight_ViewModel()
// {
// 	fraWeight_PresUnits_Property = CxvPropertyDeclaration.Register("fraWeight_PresUnits", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "PresUnits"
// 	});
// 	fraWeight_ColCount_Property = CxvPropertyDeclaration.Register("fraWeight_ColCount", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount"
// 	});
// 	fraWeight_Pressure_Property = CxvPropertyDeclaration.Register("fraWeight_Pressure", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Pressure"
// 	});
// 	fraWeight_TBPTid_Property = CxvPropertyDeclaration.Register("fraWeight_TBPTid", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "TBPTid3"
// 	});
// 	fraWeight_viewid_Property = CxvPropertyDeclaration.Register("fraWeight_viewid", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "viewid3"
// 	});
// 	NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ColCount.Output.@viewid3.0"
// 	});
// 	grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMDistcu_Result_Weight_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid3",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "WtGridEnabled",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = true
// 		}
// 	});
// 	mnuCurveView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuCurveView_AdvCollection", typeof(MMDistcu_Result_Weight_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "TBP curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_TBP_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D86 curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D1160 curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D1160_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vacuum at 10 mmHg curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Vacuum_at_10_mmHg_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "API curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_API_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Specific gravity curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Specific_gravity_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Molecular weight curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Molecular_weight_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D86CRK curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D86CRK_curve"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "ASTM D2887 curve",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_ASTM_D2887_curve"
// 			}
// 		},
// 		SelectedItemBinding = "mnuCurveView_WeightView.Value",
// 		CreateNewPrompt = "Curve view:",
// 		CreateNewPromptResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Curve_view_"
// 	});
// 	mnuCurveView_WeightView_Property = CxvPropertyDeclaration.Register("mnuCurveView_WeightView", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview3"
// 	});
// 	stream_AdvCollection_Property = CxvPropertyDeclaration.Register("stream_AdvCollection", typeof(MMDistcu_Result_Weight_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		IsCalculated = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_All_streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Streams"
// 			}
// 		}
// 	});
// 	StreamVisible_Property = CxvPropertyDeclaration.Register("StreamVisible", typeof(MMDistcu_Result_Weight_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "StreamVisible3"
// 	});
// }

// 0x060001f1 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_ViewModel..ctor
// public MMConv_Summary_ViewModel()
// {
// }

// 0x060001f2 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMConv_Summary_ViewModel()
// {
// 	spec1_Property = CxvPropertyDeclaration.Register("spec1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.DES_SPEC"
// 	});
// 	tear1_Property = CxvPropertyDeclaration.Register("tear1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.STREAMID"
// 	});
// 	tvar1_Property = CxvPropertyDeclaration.Register("tvar1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.DEFVID"
// 	});
// 	eoconv1_Property = CxvPropertyDeclaration.Register("eoconv1", typeof(MMConv_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@spec1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@tear1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@eoconv1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMConv_Summary_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@tvar1" }
// 	});
// }

// 0x060001f7 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_EOConv_ViewModel..ctor
// public MMConv_Summary_EOConv_ViewModel()
// {
// }

// 0x060001f8 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_EOConv_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMConv_Summary_EOConv_ViewModel()
// {
// 	grdTear_GridData_Property = CxvPropertyDeclaration.Register("grdTear_GridData", typeof(MMConv_Summary_EOConv_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdTear_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060001fd AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Spec_ViewModel..ctor
// public MMConv_Summary_Spec_ViewModel()
// {
// }

// 0x060001fe AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMConv_Summary_Spec_ViewModel()
// {
// 	grdDesignSpec_GridData_Property = CxvPropertyDeclaration.Register("grdDesignSpec_GridData", typeof(MMConv_Summary_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdDesignSpec_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000203 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tear_ViewModel..ctor
// public MMConv_Summary_Tear_ViewModel()
// {
// }

// 0x06000204 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tear_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMConv_Summary_Tear_ViewModel()
// {
// 	grdTear_GridData_Property = CxvPropertyDeclaration.Register("grdTear_GridData", typeof(MMConv_Summary_Tear_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdTear_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000209 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tvar_ViewModel..ctor
// public MMConv_Summary_Tvar_ViewModel()
// {
// }

// 0x0600020a AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tvar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMConv_Summary_Tvar_ViewModel()
// {
// 	grdTvar_GridData_Property = CxvPropertyDeclaration.Register("grdTvar_GridData", typeof(MMConv_Summary_Tvar_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdTvar_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x0600020f AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_ViewModel..ctor
// public MMCO2Emis_Summary_ViewModel()
// {
// }

// 0x06000210 AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCO2Emis_Summary_ViewModel()
// {
// 	hier_id_Property = CxvPropertyDeclaration.Register("hier_id", typeof(MMCO2Emis_Summary_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "hier_id"
// 	});
// }

// 0x06000221 AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel..ctor
// public MMCO2Emis_Summary_Summary_ViewModel()
// {
// }

// 0x06000222 AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCO2Emis_Summary_Summary_ViewModel()
// {
// 	MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HCO2TAX.@hier_id"
// 	});
// 	MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "hier_id"
// 	});
// 	MMAdvCombo1_var2_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var2", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HNETSTRCO2E",
// 		CreateNewPrompt = "Hierarchy:",
// 		CreateNewPromptResourceKey = "MMCO2Emis_Summary_Summary_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Hierarchy_"
// 	});
// 	MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PSTRMCO2E.@hier_id"
// 	});
// 	MMScrollArea2_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea2_GridData", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea2_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id",
// 			UseChildId = true,
// 			Name = "x"
// 		}
// 	});
// 	MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HTOTCO2E.@hier_id"
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HUTILCO2E.@hier_id"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HNETSTRCO2E.@hier_id"
// 	});
// 	MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FSTRMCO2E.@hier_id"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id"
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCO2Emis_Summary_Summary_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id",
// 			UseChildId = true,
// 			Name = "x"
// 		}
// 	});
// }

// 0x06000235 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel..ctor
// using System.Windows;
//
// public MMBlkStrSum_Summar_Heat_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000236 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_Summar_Heat_ViewModel()
// {
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#3"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#4"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#5"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#6"
// 	});
// 	MMTextBox6Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#7"
// 	});
// 	MMTextBox7Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7Lab_var1", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Heat Results.Table.#8"
// 	});
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Heat Results.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Heat Results.Table.#0",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMBlkStrSum_Summar_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData2_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Heat Results.Table.#0",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x06000242 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Load_ViewModel..ctor
// public MMBlkStrSum_Summar_Load_ViewModel()
// {
// }

// 0x06000243 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Load_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_Summar_Load_ViewModel()
// {
// 	fraStream_stream_Property = CxvPropertyDeclaration.Register("fraStream_stream", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stream"
// 	});
// 	MMAdvCombo1_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvAdvCollectionTooltipProperty
// 	{
// 		DataPath = "@loadsum.TEMP",
// 		CreateNewPrompt = "Stream name:",
// 		CreateNewPromptResourceKey = "MMBlkStrSum_Summar_Load_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_name_"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY.@stream"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP.@stream"
// 	});
// 	grdLoad_GridData_Property = CxvPropertyDeclaration.Register("grdLoad_GridData", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLoad_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@loadsum.TEMP.@stream",
// 			UseChildId = true,
// 			Name = "row"
// 		}
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
// 	});
// 	fraStream_loadsum_Property = CxvPropertyDeclaration.Register("fraStream_loadsum", typeof(MMBlkStrSum_Summar_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum"
// 	});
// }

// 0x06000250 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel..ctor
// public MMBlkStrSum_Summar_Materi_ViewModel()
// {
// }

// 0x06000251 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_Summar_Materi_ViewModel()
// {
// 	cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvLogicalProperty
// 	{
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main.Stream Results.Table.#0",
// 				DataAttribute = "child_count",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 1
// 			}
// 		}
// 	});
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Stream Results.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Hierarchy streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Hierarchy_streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Display this and child hierarchy streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_this_and_child_hierarchy_strea",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLHIERSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_3",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "<Default>",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Display__Default_",
// 				Value = "cboDisplay_MultiMapOption_4",
// 				Prompt = "Display default streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_default_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "DEFAULT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Stream Results.TFF File",
// 		Sorted = true
// 	});
// 	grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table",
// 			UseChildId = false,
// 			Name = "row"
// 		}
// 	});
// 	GridData_Column_Property = CxvPropertyDeclaration.Register("GridData_Column", typeof(MMBlkStrSum_Summar_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			Name = "z",
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = false
// 		},
// 		ItemType = typeof(GridData_Column_ViewModel)
// 	});
// }

// 0x06000264 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel..ctor
// using System.Windows;
//
// public MMBlkStrSum_Summar_Power_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000265 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_Summar_Power_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Power Results.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Power Results.Table.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Power Results.Table.#3"
// 	});
// 	MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Power Results.Table.#5"
// 	});
// 	MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Power Results.Table.#6"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Power Results.Table.#7"
// 	});
// 	grdPower_GridData_Property = CxvPropertyDeclaration.Register("grdPower_GridData", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPower_GridData_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@main.Power Results.Table",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdPower_GridData2_Property = CxvPropertyDeclaration.Register("grdPower_GridData2", typeof(MMBlkStrSum_Summar_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPower_GridData2_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@main.Power Results.Table",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x06000276 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel..ctor
// using System.Windows;
//
// public MMBlkStrSum_Summar_Work_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000277 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_Summar_Work_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDisplay_var1",
// 				DataPath = "@main.Work Results.Display"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "ALLSTREAMS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMBlkStrSum_Summar_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDisplay_var1",
// 						Value = "STREAMS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Work Results.Table.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Work Results.Table.#3"
// 	});
// 	MMTextBox3Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Work Results.Table.#5"
// 	});
// 	MMTextBox4Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Work Results.Table.#6"
// 	});
// 	MMTextBox5Lab_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5Lab_var1", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Work Results.Table.#7"
// 	});
// 	grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@main.Work Results.Table",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMBlkStrSum_Summar_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData2_ItemTemplate),
// 		IndexBasis = new CxvSecondLevelChildCountIndexBasis
// 		{
// 			DataPath = "@main.Work Results.Table",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x060002bc AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummH_ViewModel..ctor
// public MMBlkStrSum_SummH_ViewModel()
// {
// }

// 0x060002bd AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummH_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummH_ViewModel()
// {
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMBlkStrSum_SummH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stream"
// 	});
// 	load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP"
// 	});
// 	load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@load1", "@load2" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro31", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8",
// 			"@petro9"
// 		}
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
// 	});
// }

// 0x06000302 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummM_ViewModel..ctor
// public MMBlkStrSum_SummM_ViewModel()
// {
// }

// 0x06000303 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummM_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummM_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summM_Property = CxvPropertyDeclaration.Register("main_summM", typeof(MMBlkStrSum_SummM_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summM"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summM.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummM_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummM_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000353 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMH_ViewModel..ctor
// public MMBlkStrSum_SummMH_ViewModel()
// {
// }

// 0x06000354 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMH_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMH_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP"
// 	});
// 	load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY"
// 	});
// 	stream_Property = CxvPropertyDeclaration.Register("stream", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stream"
// 	});
// 	main_summMH_Property = CxvPropertyDeclaration.Register("main_summMH", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMH"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMH.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@load1", "@load2" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMH.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMH_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
// 	});
// }

// 0x060003a5 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHLW_ViewModel..ctor
// public MMBlkStrSum_SummMHLW_ViewModel()
// {
// }

// 0x060003a6 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHLW_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMHLW_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMHW_Property = CxvPropertyDeclaration.Register("main_summMHW", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMHW"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMHW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
// 	});
// 	load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP"
// 	});
// 	load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@load1", "@load2" }
// 	});
// 	tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@main.Power Results.Table" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHLW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x060003f8 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHLWP_ViewModel..ctor
// public MMBlkStrSum_SummMHLWP_ViewModel()
// {
// }

// 0x060003f9 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHLWP_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMHLWP_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMHWP"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	loadsum_Property = CxvPropertyDeclaration.Register("loadsum", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Load-Sum.Output"
// 	});
// 	load1_Property = CxvPropertyDeclaration.Register("load1", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP"
// 	});
// 	load2_Property = CxvPropertyDeclaration.Register("load2", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@load1", "@load2" }
// 	});
// 	tab9_var_Property = CxvPropertyDeclaration.Register("tab9_var", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHLWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000447 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHP_ViewModel..ctor
// public MMBlkStrSum_SummMHP_ViewModel()
// {
// }

// 0x06000448 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHP_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMHP_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMHWP"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000494 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHW_ViewModel..ctor
// public MMBlkStrSum_SummMHW_ViewModel()
// {
// }

// 0x06000495 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHW_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMHW_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMHW_Property = CxvPropertyDeclaration.Register("main_summMHW", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMHW"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMHW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x060004e3 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHWP_ViewModel..ctor
// public MMBlkStrSum_SummMHWP_ViewModel()
// {
// }

// 0x060004e4 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMHWP_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMHWP_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMHWP_Property = CxvPropertyDeclaration.Register("main_summMHWP", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMHWP"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMHWP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab8_var_Property = CxvPropertyDeclaration.Register("tab8_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMHWP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x0600052e AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMP_ViewModel..ctor
// public MMBlkStrSum_SummMP_ViewModel()
// {
// }

// 0x0600052f AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMP_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMP_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	power1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMP_Property = CxvPropertyDeclaration.Register("main_summMP", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMP"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMP.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMP_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000579 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMW_ViewModel..ctor
// public MMBlkStrSum_SummMW_ViewModel()
// {
// }

// 0x0600057a AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_SummMW_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlkStrSum_SummMW_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCURWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_summMW_Property = CxvPropertyDeclaration.Register("main_summMW", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_summMW"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_summMW.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMBlkStrSum_SummMW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000581 AspenTech.AspenPlus.MMForms.Results_Summary.CustomStreamSelectedObject`2+<>c__DisplayClass18_0..ctor
// public <>c__DisplayClass18_0()
// {
// }

// 0x0600059b AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Sum_ViewModel+grdUtlSum_GridData_ItemTemplate..ctor
// public grdUtlSum_GridData_ItemTemplate()
// {
// }

// 0x0600059c AspenTech.AspenPlus.MMForms.Results_Summary.Utility_Sum.MMUtil_Summary_Sum_ViewModel+grdUtlSum_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdUtlSum_GridData_ItemTemplate()
// {
// 	MMTextBox22_var1_Property = CxvPropertyDeclaration.Register("MMTextBox22_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.BLKCO2RATE.@x"
// 	});
// 	MMTextBox21_var1_Property = CxvPropertyDeclaration.Register("MMTextBox21_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMFACTOR.@x"
// 	});
// 	MMTextBox20_var1_Property = CxvPropertyDeclaration.Register("MMTextBox20_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMEFFICIENCY.@x"
// 	});
// 	MMTextBox17_var1_Property = CxvPropertyDeclaration.Register("MMTextBox17_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENTH_OUT.@x"
// 	});
// 	MMTextBox16_var1_Property = CxvPropertyDeclaration.Register("MMTextBox16_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENTH_IN.@x"
// 	});
// 	MMTextBox15_var1_Property = CxvPropertyDeclaration.Register("MMTextBox15_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Utility-Sum.Output.UTIL_TYPE.@x"
// 	});
// 	MMTextBox14_var1_Property = CxvPropertyDeclaration.Register("MMTextBox14_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.UTIL_TYPE.@x"
// 	});
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.VFRAC.@x"
// 	});
// 	MMTextBox13_var1_Property = CxvPropertyDeclaration.Register("MMTextBox13_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.OUT_TEMP.@x"
// 	});
// 	MMTextBox12_var1_Property = CxvPropertyDeclaration.Register("MMTextBox12_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.IN_TEMP.@x"
// 	});
// 	MMTextBox11_var1_Property = CxvPropertyDeclaration.Register("MMTextBox11_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TRATE.@x"
// 	});
// 	MMTextBox10_var1_Property = CxvPropertyDeclaration.Register("MMTextBox10_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.DUTY.@x"
// 	});
// 	MMTextBox9_var1_Property = CxvPropertyDeclaration.Register("MMTextBox9_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.HCOOL.@x"
// 	});
// 	MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.OUT_PRES.@x"
// 	});
// 	MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.IN_PRES.@x"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.IN_VF.@x"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ENERGY_PRICE.@x"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.ELEC_PRICE.@x"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PPRICE.@x"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.TCOST.@x"
// 	});
// 	MMTextBox19_var1_Property = CxvPropertyDeclaration.Register("MMTextBox19_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMFUELTYPE.@x",
// 		ExposeAs = CxvVariableTypeCode.String
// 	});
// 	MMTextBox18_var1_Property = CxvPropertyDeclaration.Register("MMTextBox18_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMDATASOURCE.@x",
// 		ExposeAs = CxvVariableTypeCode.String
// 	});
// 	CO2EmissionScope_var1_Property = CxvPropertyDeclaration.Register("CO2EmissionScope_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMSCOPE.@x",
// 		ExposeAs = CxvVariableTypeCode.String
// 	});
// 	CO2AdjustmentFactor_var1_Property = CxvPropertyDeclaration.Register("CO2AdjustmentFactor_var1", typeof(grdUtlSum_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.EMADJFACTOR.@x"
// 	});
// }

// 0x060005a2 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel+grdHeat_GridData_ItemTemplate..ctor
// public grdHeat_GridData_ItemTemplate()
// {
// }

// 0x060005a3 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel+grdHeat_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@houtp.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@houtp.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@houtp.#4.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@houtp.#3.@col"
// 	});
// }

// 0x060005ac AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..ctor
// public grdHeat_GridData2_ItemTemplate()
// {
// }

// 0x060005ad AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData2_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#4.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#5.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#6.@col"
// 	});
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#7.@col"
// 	});
// 	MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat-Sum.Table.#8.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Heat-Sum.Table.#3.@col"
// 	});
// }

// 0x060005b0 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Load_ViewModel+grdLoad_GridData_ItemTemplate..ctor
// public grdLoad_GridData_ItemTemplate()
// {
// }

// 0x060005b1 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Load_ViewModel+grdLoad_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLoad_GridData_ItemTemplate()
// {
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output.DUTY.@stream.@row"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Sum.Load-Sum.Output.TEMP.@stream.@row"
// 	});
// }

// 0x060005b4 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate()
// {
// }

// 0x060005b5 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdStreams_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@outp.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@outp.@row",
// 		IsCalculated = true
// 	});
// }

// 0x060005b8 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060005b9 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "col"
// 	});
// 	txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@outp.@row.@col"
// 	});
// }

// 0x060005bc AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+GridData_Column_ViewModel..ctor
// public GridData_Column_ViewModel()
// {
// }

// 0x060005bd AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Materi_ViewModel+GridData_Column_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static GridData_Column_ViewModel()
// {
// 	Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@outp.#0.@z",
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions
// 	});
// }

// 0x060005c2 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel+grdPower_GridData_ItemTemplate..ctor
// public grdPower_GridData_ItemTemplate()
// {
// }

// 0x060005c3 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel+grdPower_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPower_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#3.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@poutp.#3.@col"
// 	});
// }

// 0x060005cb AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel+grdPower_GridData2_ItemTemplate..ctor
// public grdPower_GridData2_ItemTemplate()
// {
// }

// 0x060005cc AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Power_ViewModel+grdPower_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPower_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@poutp.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@poutp.#3.@col"
// 	});
// }

// 0x060005d1 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_GridData_ItemTemplate..ctor
// public grdPSD_GridData_ItemTemplate()
// {
// }

// 0x060005d2 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPSD_GridData_ItemTemplate()
// {
// 	txtUpperLimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperLimit_var1", typeof(grdPSD_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream.@row"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPSD_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// }

// 0x060005d5 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdPSD_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060005d6 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPSD_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "col"
// 	});
// 	txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdPSD_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream.@col.@row"
// 	});
// }

// 0x060005d9 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column_ViewModel..ctor
// public GridData_Column_ViewModel()
// {
// }

// 0x060005da AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static GridData_Column_ViewModel()
// {
// 	Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt1.@stream.@z",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x060005eb AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSDA_GridData_ItemTemplate..ctor
// public grdPSDA_GridData_ItemTemplate()
// {
// }

// 0x060005ec AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSDA_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPSDA_GridData_ItemTemplate()
// {
// 	StreamID_var1_Property = CxvPropertyDeclaration.Register("StreamID_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream.@row",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	D10_var1_Property = CxvPropertyDeclaration.Register("D10_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D10.@stream.@row"
// 	});
// 	D20_var1_Property = CxvPropertyDeclaration.Register("D20_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D20.@stream.@row"
// 	});
// 	D25_var1_Property = CxvPropertyDeclaration.Register("D25_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25.@stream.@row"
// 	});
// 	D50_var1_Property = CxvPropertyDeclaration.Register("D50_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D50.@stream.@row"
// 	});
// 	D63_var1_Property = CxvPropertyDeclaration.Register("D63_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D63.@stream.@row"
// 	});
// 	D75_var1_Property = CxvPropertyDeclaration.Register("D75_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D75.@stream.@row"
// 	});
// 	D80_var1_Property = CxvPropertyDeclaration.Register("D80_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D80.@stream.@row"
// 	});
// 	D90_var1_Property = CxvPropertyDeclaration.Register("D90_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D90.@stream.@row"
// 	});
// 	D95_var1_Property = CxvPropertyDeclaration.Register("D95_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D95.@stream.@row"
// 	});
// 	D100_var1_Property = CxvPropertyDeclaration.Register("D100_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D100.@stream.@row"
// 	});
// 	D25D75_var1_Property = CxvPropertyDeclaration.Register("D25D75_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D25D75.@stream.@row"
// 	});
// 	SMD_var1_Property = CxvPropertyDeclaration.Register("SMD_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SMD.@stream.@row"
// 	});
// 	SV_var1_Property = CxvPropertyDeclaration.Register("SV_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.SV.@stream.@row"
// 	});
// 	D43_var1_Property = CxvPropertyDeclaration.Register("D43_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.D43.@stream.@row"
// 	});
// }

// 0x060005f0 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdMC_GridData_ItemTemplate..ctor
// public grdMC_GridData_ItemTemplate()
// {
// }

// 0x060005f1 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdMC_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMC_GridData_ItemTemplate()
// {
// 	txtMC_var1_Property = CxvPropertyDeclaration.Register("txtMC_var1", typeof(grdMC_GridData_ItemTemplate), new CxvVariableProperty());
// 	cboUnits2_var1_Property = CxvPropertyDeclaration.Register("cboUnits2_var1", typeof(grdPSDA_GridData_ItemTemplate), new CxvVariableProperty());
// 	inner2_Property = CxvPropertyDeclaration.Register("inner2", typeof(grdMC_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// }

// 0x060005f4 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdMC_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdMC_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060005f5 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdMC_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMC_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "col"
// 	});
// 	txtTable2_var1_Property = CxvPropertyDeclaration.Register("txtTable2_var1", typeof(grdMC_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream.@col.@row"
// 	});
// }

// 0x060005f8 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column2_ViewModel..ctor
// public GridData_Column2_ViewModel()
// {
// }

// 0x060005f9 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column2_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static GridData_Column2_ViewModel()
// {
// 	Uom2_Property = CxvPropertyDeclaration.Register("Uom2", typeof(GridData_Column2_ViewModel), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.@opt2.@stream.@z",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x060005fc AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_2_GridData_ItemTemplate..ctor
// public grdPSD_2_GridData_ItemTemplate()
// {
// }

// 0x060005fd AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_2_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPSD_2_GridData_ItemTemplate()
// {
// 	txtUpperLimit_2_var1_Property = CxvPropertyDeclaration.Register("txtUpperLimit_2_var1", typeof(grdPSD_2_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.MAXIMUM.@stream.@row2"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPSD_2_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new MyCxvChildCountIndexBasis
// 		{
// 			DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream",
// 			UseChildId = true,
// 			Name = "col2"
// 		}
// 	});
// }

// 0x06000600 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000601 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "col2"
// 	});
// 	txtTable_2_var1_Property = CxvPropertyDeclaration.Register("txtTable_2_var1", typeof(grdPSD_2_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream.@col2.@row2"
// 	});
// }

// 0x06000604 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column_2_ViewModel..ctor
// public GridData_Column_2_ViewModel()
// {
// }

// 0x06000605 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+GridData_Column_2_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static GridData_Column_2_ViewModel()
// {
// 	Uom_2_Property = CxvPropertyDeclaration.Register("Uom_2", typeof(GridData_Column_2_ViewModel), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@main_solid.Results Summary.Stream-Sum.Dist-Curve.Output.TOTAL.@stream.@z",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x06000607 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+MyCxvChildCountIndexBasis..ctor
// public MyCxvChildCountIndexBasis()
// {
// }

// 0x0600060b AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+<>c__DisplayClass2_0..ctor
// public <>c__DisplayClass2_0()
// {
// }

// 0x06000611 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel+grdWork_GridData_ItemTemplate..ctor
// public grdWork_GridData_ItemTemplate()
// {
// }

// 0x06000612 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel+grdWork_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#3.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@woutp.#3.@col"
// 	});
// }

// 0x0600061a AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel+grdWork_GridData2_ItemTemplate..ctor
// public grdWork_GridData2_ItemTemplate()
// {
// }

// 0x0600061b AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Work_ViewModel+grdWork_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@woutp.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@woutp.#3.@col"
// 	});
// }

// 0x0600061e AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel+grdResults_GridData_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate()
// {
// }

// 0x0600061f AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel+grdResults_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate()
// {
// 	MMTextBox1_DP_Property = CxvPropertyDeclaration.Register("MMTextBox1_DP", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@DPid.@y"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CustomIndexBasis("selectedStreams4", "availableStreams4")
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4",
// 			UseChildId = true,
// 			Name = "x",
// 			ProxyRow = false,
// 			IsNotJagged = true,
// 			MinimumRows = 1
// 		}
// 	});
// }

// 0x06000623 AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000624 AspenTech.AspenPlus.MMForms.Results_Summary.Poly_Curve.MMPolycur_Result_Csd_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4.@x.@y"
// 	});
// 	MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid4.@x"
// 	});
// }

// 0x06000627 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel+grdResults_GridData_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate()
// {
// }

// 0x06000628 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel+grdResults_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate()
// {
// 	MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid.@y"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CustomIndexBasis("selectedStreams", "availableStreams")
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid",
// 			UseChildId = false,
// 			Name = "x",
// 			ProxyRow = false,
// 			MinimumRows = 1
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x0600062c AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x0600062d AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Petro_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid.@x"
// 	});
// 	MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid.@x.@y",
// 		IsCalculated = true
// 	});
// }

// 0x06000636 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel+grdResults_GridData_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate()
// {
// }

// 0x06000637 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel+grdResults_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate()
// {
// 	MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Output.@viewid2.@x.@y"
// 	});
// 	MMLBUText1_Units_Property = CxvPropertyDeclaration.Register("MMLBUText1_Units", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Output.@viewid2.@x"
// 	});
// 	mnuDisplayView_DisplayView_Property = CxvPropertyDeclaration.Register("mnuDisplayView_DisplayView", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "DisplayView"
// 	});
// 	mnuDisplayView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuDisplayView_AdvCollection", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_All_streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDistcu_Result_Volume_ViewModel__CxvAdvCollectionItem_Display_Streams"
// 			}
// 		},
// 		SelectedItemBinding = "mnuDisplayView_DisplayView.Value"
// 	});
// 	MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "target"
// 	});
// 	MMAdvCombo1_selector_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_selector", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2",
// 		SelectedItemBinding = "MMAdvCombo1_target.Value"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CustomIndexBasis("selectedStreams2", "availableStreams2")
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2",
// 			UseChildId = true,
// 			Name = "x",
// 			ProxyRow = false,
// 			IsNotJagged = true,
// 			MinimumRows = 1
// 		}
// 	});
// 	MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid2.@y",
// 		IsCalculated = true,
// 		IsReadOnly = true
// 	});
// }

// 0x0600063e AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x0600063f AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Volume_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid2.@x"
// 	});
// }

// 0x06000649 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel+grdResults_GridData_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate()
// {
// }

// 0x0600064a AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel+grdResults_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate()
// {
// 	mnuDisplayView_DisplayView_Property = CxvPropertyDeclaration.Register("mnuDisplayView_DisplayView", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "DisplayView"
// 	});
// 	mnuDisplayView_AdvCollection_Property = CxvPropertyDeclaration.Register("mnuDisplayView_AdvCollection", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "All streams",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_All_streams"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDistcu_Result_Weight_ViewModel__CxvAdvCollectionItem_Display_Streams"
// 			}
// 		},
// 		SelectedItemBinding = "mnuDisplayView_DisplayView.Value"
// 	});
// 	MMLBUText1_Units_Property = CxvPropertyDeclaration.Register("MMLBUText1_Units", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Output.@viewid3.@x"
// 	});
// 	MMTextBox2_StreamValues_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamValues", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Output.@viewid3.@x.@y"
// 	});
// 	MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "target"
// 	});
// 	MMAdvCombo1_selector_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_selector", typeof(grdResults_GridData_ItemTemplate), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3",
// 		SelectedItemBinding = "MMAdvCombo1_target.Value"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdResults_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CustomIndexBasis("selectedStreams3", "availableStreams3")
// 		{
// 			DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3",
// 			UseChildId = false,
// 			Name = "x",
// 			ProxyRow = false,
// 			IsNotJagged = true,
// 			MinimumRows = 1
// 		}
// 	});
// 	MMTextBox1_TBPT_Property = CxvPropertyDeclaration.Register("MMTextBox1_TBPT", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@TBPTid3.@y",
// 		IsCalculated = true,
// 		IsReadOnly = true
// 	});
// }

// 0x06000651 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000652 AspenTech.AspenPlus.MMForms.Results_Summary.Dist_Curve.MMDistcu_Result_Weight_ViewModel+grdResults_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox2_StreamUOM_Property = CxvPropertyDeclaration.Register("MMTextBox2_StreamUOM", typeof(grdResults_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main2.Stream-Sum.Dist-Curve.Output.@viewid3.@x"
// 	});
// }

// 0x0600065a AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_EOConv_ViewModel+grdTear_GridData_ItemTemplate..ctor
// public grdTear_GridData_ItemTemplate()
// {
// }

// 0x0600065b AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_EOConv_ViewModel+grdTear_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdTear_GridData_ItemTemplate()
// {
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.EOSTAT.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Has not run",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Has_not_run",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "0"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Converged",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "1"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Switch to EO failed",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Switch_to_EO_failed",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Line seach failed",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Line_seach_failed",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "3"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "QP failed",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_QP_failed",
// 				Value = "MMComboBox1_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "4"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Not_converged",
// 				Value = "MMComboBox1_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "5"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtTear_var1_Property = CxvPropertyDeclaration.Register("txtTear_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.HBLKID.@y"
// 	});
// 	cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboStat_var1",
// 				DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMSTAT.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Has not run",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Has_not_run_1",
// 				Value = "cboStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "0"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No tear stream",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_No_tear_stream",
// 				Value = "cboStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "1"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Converged_1",
// 				Value = "cboStat_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged",
// 				DisplayResourceKey = "MMConv_Summary_EOConv_ViewModel__CxvMultiMapOption_Display_Not_converged_1",
// 				Value = "cboStat_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "3"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtMaxErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMMAXERR.@y"
// 	});
// 	txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.SMTOL.@y"
// 	});
// 	txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.EOCV-SUMMARY.Output.CVBLKID.@y"
// 	});
// }

// 0x06000663 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Spec_ViewModel+grdDesignSpec_GridData_ItemTemplate..ctor
// public grdDesignSpec_GridData_ItemTemplate()
// {
// }

// 0x06000664 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Spec_ViewModel+grdDesignSpec_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdDesignSpec_GridData_ItemTemplate()
// {
// 	txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.CONVBLK.@y"
// 	});
// 	txtVal_var1_Property = CxvPropertyDeclaration.Register("txtVal_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.VAR_VAL.@y"
// 	});
// 	txtErrTol_var1_Property = CxvPropertyDeclaration.Register("txtErrTol_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR_TOL.@y"
// 	});
// 	txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.TOLERANCE.@y"
// 	});
// 	txtErr_var1_Property = CxvPropertyDeclaration.Register("txtErr_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.ERR.@y"
// 	});
// 	cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboStat_var1",
// 				DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.CVSTAT.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged",
// 				Value = "cboStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "#"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged",
// 				Value = "cboStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "*"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged, LB",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged__LB",
// 				Value = "cboStat_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "* LB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged, UB",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Not_converged__UB",
// 				Value = "cboStat_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "* UB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged, LB",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged__LB",
// 				Value = "cboStat_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "# LB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged, UB",
// 				DisplayResourceKey = "MMConv_Summary_Spec_ViewModel__CxvMultiMapOption_Display_Converged__UB",
// 				Value = "cboStat_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "# UB"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtSpec_var1_Property = CxvPropertyDeclaration.Register("txtSpec_var1", typeof(grdDesignSpec_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.SPEC-SUMMARY.Output.DES_SPEC.@y"
// 	});
// }

// 0x0600066d AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tear_ViewModel+grdTear_GridData_ItemTemplate..ctor
// public grdTear_GridData_ItemTemplate()
// {
// }

// 0x0600066e AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tear_ViewModel+grdTear_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdTear_GridData_ItemTemplate()
// {
// 	txtTear_var1_Property = CxvPropertyDeclaration.Register("txtTear_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.STREAMID.@y"
// 	});
// 	cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTear_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboStat_var1",
// 				DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.CVSTAT.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged",
// 				DisplayResourceKey = "MMConv_Summary_Tear_ViewModel__CxvMultiMapOption_Display_Converged",
// 				Value = "cboStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "#"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged",
// 				DisplayResourceKey = "MMConv_Summary_Tear_ViewModel__CxvMultiMapOption_Display_Not_converged",
// 				Value = "cboStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "*"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtMaxErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR2.@y"
// 	});
// 	txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.TOLERANCE.@y"
// 	});
// 	txtMaxErrTol_var1_Property = CxvPropertyDeclaration.Register("txtMaxErrTol_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR_TOL.@y"
// 	});
// 	txtMaxAbsErr_var1_Property = CxvPropertyDeclaration.Register("txtMaxAbsErr_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.ERR.@y"
// 	});
// 	txtVar_var1_Property = CxvPropertyDeclaration.Register("txtVar_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.VARID.@y"
// 	});
// 	txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTear_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TEAR-SUMMARY.Output.CONVBLK.@y"
// 	});
// }

// 0x06000678 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tvar_ViewModel+grdTvar_GridData_ItemTemplate..ctor
// public grdTvar_GridData_ItemTemplate()
// {
// }

// 0x06000679 AspenTech.AspenPlus.MMForms.Results_Summary.Conv_Sum.MMConv_Summary_Tvar_ViewModel+grdTvar_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdTvar_GridData_ItemTemplate()
// {
// 	txtDefvar_var1_Property = CxvPropertyDeclaration.Register("txtDefvar_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.DEFVID.@y"
// 	});
// 	cboStat_MultiMap_Property = CxvPropertyDeclaration.Register("cboStat_MultiMap", typeof(grdTvar_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboStat_var1",
// 				DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.CVSTAT.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Converged",
// 				DisplayResourceKey = "MMConv_Summary_Tvar_ViewModel__CxvMultiMapOption_Display_Converged",
// 				Value = "cboStat_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "#"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Not converged",
// 				DisplayResourceKey = "MMConv_Summary_Tvar_ViewModel__CxvMultiMapOption_Display_Not_converged",
// 				Value = "cboStat_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboStat_var1",
// 						Value = "*"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtErr_var1_Property = CxvPropertyDeclaration.Register("txtErr_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR2.@y"
// 	});
// 	txtTol_var1_Property = CxvPropertyDeclaration.Register("txtTol_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.TOLERANCE.@y"
// 	});
// 	txtErrTol_var1_Property = CxvPropertyDeclaration.Register("txtErrTol_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR_TOL.@y"
// 	});
// 	txtAbsErr_var1_Property = CxvPropertyDeclaration.Register("txtAbsErr_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.ERR.@y"
// 	});
// 	txtDes_var1_Property = CxvPropertyDeclaration.Register("txtDes_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.VARDES.@y"
// 	});
// 	txtConv_var1_Property = CxvPropertyDeclaration.Register("txtConv_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.CONVBLK.@y"
// 	});
// 	txtCal_var1_Property = CxvPropertyDeclaration.Register("txtCal_var1", typeof(grdTvar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Conv-Sum.TVAR-SUMMARY.Output.FBLKID.@y"
// 	});
// }

// 0x0600067d AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel+MMScrollArea2_GridData_ItemTemplate..ctor
// public MMScrollArea2_GridData_ItemTemplate()
// {
// }

// 0x0600067e AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel+MMScrollArea2_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea2_GridData_ItemTemplate()
// {
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PSTRMCO2E.@hier_id.@x"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id.@x"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea2_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Utility-Sum.Output.PSTRMASSFLOW.@hier_id.@x"
// 	});
// }

// 0x06000682 AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000683 AspenTech.AspenPlus.MMForms.Results_Summary.CO2Emis_Sum.MMCO2Emis_Summary_Summary_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FSTRMCO2E.@hier_id.@x"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id.@x"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Utility-Sum.Output.FSTRMASSFLOW.@hier_id.@x"
// 	});
// }

// 0x06000689 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel+grdHeat_GridData_ItemTemplate..ctor
// public grdHeat_GridData_ItemTemplate()
// {
// }

// 0x0600068a AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel+grdHeat_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#4.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#5.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Heat Results.Table.#3.@col"
// 	});
// }

// 0x06000693 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..ctor
// public grdHeat_GridData2_ItemTemplate()
// {
// }

// 0x06000694 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData2_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#4.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#5.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#6.@col"
// 	});
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#7.@col"
// 	});
// 	MMTextBox7_var1_Property = CxvPropertyDeclaration.Register("MMTextBox7_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Heat Results.Table.#8.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Heat Results.Table.#3.@col"
// 	});
// }

// 0x06000697 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Load_ViewModel+grdLoad_GridData_ItemTemplate..ctor
// public grdLoad_GridData_ItemTemplate()
// {
// }

// 0x06000698 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Load_ViewModel+grdLoad_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLoad_GridData_ItemTemplate()
// {
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.DUTY.@stream.@row"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdLoad_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@loadsum.TEMP.@stream.@row"
// 	});
// }

// 0x0600069b AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate()
// {
// }

// 0x0600069c AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdStreams_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.@row",
// 		IsCalculated = true
// 	});
// }

// 0x0600069f AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060006a0 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	cboStreams_var1_Property = CxvPropertyDeclaration.Register("cboStreams_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "col"
// 	});
// 	txtTable_var1_Property = CxvPropertyDeclaration.Register("txtTable_var1", typeof(grdStreams_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.@row.@col"
// 	});
// }

// 0x060006a3 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+GridData_Column_ViewModel..ctor
// public GridData_Column_ViewModel()
// {
// }

// 0x060006a4 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Materi_ViewModel+GridData_Column_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static GridData_Column_ViewModel()
// {
// 	Uom_Property = CxvPropertyDeclaration.Register("Uom", typeof(GridData_Column_ViewModel), new CxvCustomTooltipProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#0.@z",
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions
// 	});
// }

// 0x060006a9 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel+grdPower_GridData_ItemTemplate..ctor
// public grdPower_GridData_ItemTemplate()
// {
// }

// 0x060006aa AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel+grdPower_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPower_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#3.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Power Results.Table.#3.@col"
// 	});
// }

// 0x060006b2 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel+grdPower_GridData2_ItemTemplate..ctor
// public grdPower_GridData2_ItemTemplate()
// {
// }

// 0x060006b3 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Power_ViewModel+grdPower_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPower_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Power Results.Table.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdPower_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Power Results.Table.#3.@col"
// 	});
// }

// 0x060006b8 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel+grdWork_GridData_ItemTemplate..ctor
// public grdWork_GridData_ItemTemplate()
// {
// }

// 0x060006b9 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel+grdWork_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#3.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Work Results.Table.#3.@col"
// 	});
// }

// 0x060006c1 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel+grdWork_GridData2_ItemTemplate..ctor
// public grdWork_GridData2_ItemTemplate()
// {
// }

// 0x060006c2 AspenTech.AspenPlus.MMForms.Results_Summary.BlkStream_Sum.MMBlkStrSum_Summar_Work_ViewModel+grdWork_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Work Results.Table.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Work Results.Table.#3.@col"
// 	});
// }

// 0x060006c3 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+MyCxvChildCountIndexBasisData+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060006c4 AspenTech.AspenPlus.MMForms.Results_Summary.Stream_Sum.MMStreamSum_Summar_Solids_ViewModel+MyCxvChildCountIndexBasisData+<>c..ctor
// public <>c()
// {
// }
