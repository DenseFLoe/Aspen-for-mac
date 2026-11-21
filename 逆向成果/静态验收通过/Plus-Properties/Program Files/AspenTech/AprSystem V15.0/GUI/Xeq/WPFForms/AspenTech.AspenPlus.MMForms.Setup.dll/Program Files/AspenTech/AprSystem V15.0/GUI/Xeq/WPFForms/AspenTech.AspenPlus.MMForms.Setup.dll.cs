using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
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
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Shapes;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.Dialogs;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.Engineering.GridControls;
using AspenTech.Visualisation.Controls.Support.Commands;
using AspenTech.WpfControls.Engineering;
using Infragistics.Controls.Editors;
using Infragistics.Windows;
using Infragistics.Windows.Editors;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Composite.Presentation.Events;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Setup")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Setup")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/setup", "AspenTech.AspenPlus.MMForms.Setup")]
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
namespace AspenTech.AspenPlus.MMForms.Setup
{
	public class MMSetup_EmissionOptions_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMSetup.MMSetup_EmissionOptions")]
	public class MMSetup_EmissionOptions : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabEmissionOptions;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMSetup_EmissionOptions()
		{
			base.ViewModelType = typeof(MMSetup_EmissionOptions_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_emissionoptions.xaml", UriKind.Relative);
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
				tabEmissionOptions = (MMTabStrip)target;
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
	[ProgId("MMSetup.MMSetup_EmissionOptions_EmiOpt")]
	public class MMSetup_EmissionOptions_EmiOpt : MMTabPage, IComponentConnector
	{
		internal MMCheckBox MMCheckBox1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		private bool _contentLoaded;

		public MMSetup_EmissionOptions_EmiOpt()
		{
			base.ViewModelType = typeof(MMSetup_EmissionOptions_EmiOpt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_emissionoptions_emiopt.xaml", UriKind.Relative);
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
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 2:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 4:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 5:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_EmissionOptions_EmiOpt_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_EmissionOptions_EmiOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.CARBON_FEE",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Sim-Options.CC Nodes.MASSCK_INP"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMSetup_EmissionOptions_EmiOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_var1",
					DataPath = "@main.Sim-Options.Input.GHG_STANDARD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "IPCC SAR (1995)",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_SAR__1995_",
					Prompt = PromptResources.FILEPNUM_77_Prompt_96,
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "IPCC-1995"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "IPCC AR4 (2007)",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR4__2007_",
					Prompt = PromptResources.FILEPNUM_77_Prompt_97,
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "IPCC-2007"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "USEPA (2009)",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_USEPA__2009_",
					Prompt = PromptResources.FILEPNUM_77_Prompt_98,
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "USEPA-2009"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "IPCC AR5 (2014)",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR5__2016_",
					Prompt = PromptResources.FILEPNUM_77_Prompt_113,
					Value = "MMComboBox2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "IPCC-2016"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "IPCC AR6 (2021)",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR6__2021_",
					Prompt = PromptResources.FILEPNUM_77_Prompt_114,
					Value = "MMComboBox2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "IPCC-2021"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "None",
					DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_None",
					Prompt = PromptResources.FILEPNUM_77_Prompt_99,
					Value = "MMComboBox2_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "NONE"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Sim-Options.CC Nodes.MASSCK_INP"
			}
		});

		public static readonly CxvPropertyDeclaration MMchkbGreenhEmissions_var1_Property = CxvPropertyDeclaration.Register("MMchkbGreenhEmissions_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.EMISSION_CAL",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object MMchkbGreenhEmissions_var1 => GetValue(MMchkbGreenhEmissions_var1_Property);
	}
	public class MMSetup_StreamGroup_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_StreamGroup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_StreamGroup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public object spec => GetValue(spec_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_StreamGroup")]
	public class MMSetup_StreamGroup : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_StreamGroup()
		{
			base.ViewModelType = typeof(MMSetup_StreamGroup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_streamgroup.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_StreamGroup_ObjManager_ViewModel : MMViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y",
				SubObjectTypePath = "[]",
				IsEnabledCondition = new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanRename",
					Value = true
				}
			});

			public static readonly CxvPropertyDeclaration txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.DESCRIPTION"
			});

			public static readonly CxvPropertyDeclaration format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(grdChild_GridData_ItemTemplate), new CxvLineFormatProperty
			{
				DataPath = "@main.@y.Input.LINESTYLE"
			});

			public static readonly CxvPropertyDeclaration Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdChild_GridData_ItemTemplate), new CxvBooleanProperty
			{
				DataPath = "@main.@y.Input.ACTIVE"
			});

			public static readonly CxvPropertyDeclaration Priority_var_Property = CxvPropertyDeclaration.Register("Priority_var", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.PRIORITY",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration Template_var_Property = CxvPropertyDeclaration.Register("Template_var", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.SGTEMPLATE",
				IsReadOnly = true
			});

			private readonly ObservableCollection<string> _allTemplateNames = new ObservableCollection<string>();

			private string _selectedTemplate;

			public static CxvPropertyDeclaration cmdDelete_var1_Property = CxvPropertyDeclaration.Register("cmdDelete_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCmdButtonProperty
			{
				IsVisibleCondition = new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanDelete",
					Value = true
				}
			});

			public object txtName_var1 => GetValue(txtName_var1_Property);

			public object txtDescription_var1 => GetValue(txtDescription_var1_Property);

			public object format_var => GetValue(format_var_Property);

			public object Active_var => GetValue(Active_var_Property);

			public object Priority_var => GetValue(Priority_var_Property);

			public object Template_var => GetValue(Template_var_Property);

			public ObservableCollection<string> AllTemplateNames
			{
				get
				{
					_allTemplateNames.Clear();
					foreach (string streamSummaryTemplateName in GetStreamSummaryTemplateNames())
					{
						_allTemplateNames.Add(streamSummaryTemplateName);
					}
					_allTemplateNames.Add(ApwDlgRes.StreamGroupsDlg_Default);
					return _allTemplateNames;
				}
			}

			public string SelectedTemplate
			{
				get
				{
					return _selectedTemplate;
				}
				set
				{
					_selectedTemplate = value;
					OnPropertyChanged("SelectedTemplate");
					SaveSelectedTemplate();
				}
			}

			public bool CanRename
			{
				get
				{
					if (IsBuiltinGroup(CxsConverter.ValueToString(ResolveParameter("y"))))
					{
						return false;
					}
					string path = ExpandDataPath("@main");
					try
					{
						if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "RenameChild")).CanInvoke)
						{
							return true;
						}
						if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath("@main.@y"), "can_enter_id", null)) ?? false))
						{
							return false;
						}
					}
					catch (Exception)
					{
						return false;
					}
					return true;
				}
			}

			public object cmdDelete_var1 => GetValue(cmdDelete_var1_Property);

			public bool CanDelete
			{
				get
				{
					if (IsBuiltinGroup(CxsConverter.ValueToString(ResolveParameter("y"))))
					{
						return false;
					}
					string path = ExpandDataPath("@main");
					try
					{
						if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "DeleteChild")).CanInvoke)
						{
							return true;
						}
						if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath("@main.@y"), "can_delete", null)) ?? false))
						{
							return false;
						}
					}
					catch (Exception)
					{
						return false;
					}
					return true;
				}
			}

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
			}

			public string GetDescription()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtDescription_var1.Value", null));
			}

			public string GetFormat()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("format_var.Value", null));
			}

			private void UpdateSelectedTemplate()
			{
				string text = CxsConverter.ValueToString((Template_var as CxvVariableData).Value);
				if (string.IsNullOrEmpty(text))
				{
					SelectedTemplate = ApwDlgRes.StreamGroupsDlg_Default;
				}
				if (!string.IsNullOrEmpty(text))
				{
					SelectedTemplate = text;
				}
			}

			private void SaveSelectedTemplate()
			{
				string text = "";
				if (!SelectedTemplate.Equals(ApwDlgRes.StreamGroupsDlg_Default, StringComparison.InvariantCultureIgnoreCase))
				{
					text = SelectedTemplate;
				}
				if (!CxsConverter.ValueToString(ExpandDataPathAndGet("@main.@y.Input.SGTEMPLATE", "value")).Equals(text, StringComparison.InvariantCultureIgnoreCase))
				{
					ExpandDataPathAndSet("@main.@y.Input.SGTEMPLATE", "value", text);
					string groupName = CxsConverter.ValueToString(ResolveParameter("y"));
					string text2 = text;
					if (text2 == string.Empty)
					{
						text2 = null;
					}
					((CompositePresentationEvent<StreamGroupTemplateChangedEventArgs>)(object)base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<StreamGroupTemplateChangedEvent>()).Publish(new StreamGroupTemplateChangedEventArgs(groupName, text2));
				}
			}

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "Template_var" && subPropertyName == "Value")
				{
					UpdateSelectedTemplate();
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		[CompilerGenerated]
		private sealed class SelectedIdsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string currentId;

			private int initialThreadId;

			public MMSetup_StreamGroup_ObjManager_ViewModel owner;

			private IList gridData;

			private IEnumerator<int> rowIndexes;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			[DebuggerHidden]
			public SelectedIdsEnumerator(int state)
			{
				this.state = state;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = state;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeRowIndexes();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{  bool completedNormally = false;
				try
				{
					int num = state;
					MMSetup_StreamGroup_ObjManager_ViewModel mMSetup_StreamGroup_ObjManager_ViewModel = owner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true; return false;
						}
						state = -3;
					}
					else
					{
						state = -1;
						gridData = mMSetup_StreamGroup_ObjManager_ViewModel.grdChild_GridData as IList;
						if (gridData == null || mMSetup_StreamGroup_ObjManager_ViewModel.SelectedRowIndexes == null)
						{
							goto IL_00d3;
						}
						rowIndexes = mMSetup_StreamGroup_ObjManager_ViewModel.SelectedRowIndexes.GetEnumerator();
						state = -3;
					}
					while (rowIndexes.MoveNext())
					{
						int current = rowIndexes.Current;
						if (current >= 0 && current < gridData.Count)
						{
							grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = gridData[current] as grdChild_GridData_ItemTemplate;
							currentId = grdChild_GridData_ItemTemplate.GetId();
							state = 1;
							completedNormally = true; return true;
						}
					}
					DisposeRowIndexes();
					rowIndexes = null;
					goto IL_00d3;
					IL_00d3:
					completedNormally = true; return false;
				}
				finally
				{
					// Original fault handler runs only when MoveNext leaves by exception.
					if (!completedNormally) ((IDisposable)this).Dispose();

				}
			}







			private void DisposeRowIndexes()
			{
				state = -1;
				if (rowIndexes != null)
				{
					rowIndexes.Dispose();
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
				SelectedIdsEnumerator result;
				if (state == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					state = 0;
					result = this;
				}
				else
				{
					result = new SelectedIdsEnumerator(0)
					{
						owner = owner
					};
				}
				return result;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private ICommand _grid_RowDoubleClickCommand;

		private ICommand _cmdAdd_Command;

		public static CxvPropertyDeclaration cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "InsertChild"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdCopy_Command;

		public static CxvPropertyDeclaration cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "CopyChildren"
				},
				new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanDuplicate",
					Value = true
				}
			}
		});

		private ICommand _cmdPaste_Command;

		public static CxvPropertyDeclaration cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Equal,
			PropertyPath = "CanPaste",
			Value = true
		});

		private ICommand _cmdDelete_Command;

		private ICommand _cmdExport_Command;

		public static CxvPropertyDeclaration cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdDuplicate_Command;

		public static CxvPropertyDeclaration cmdDuplicateCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDuplicateCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main",
					DataAttribute = "child_count",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.Equal,
					Value = 1
				},
				new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanDuplicate",
					Value = true
				}
			},
			Operator = CxvLogicalOperator.And
		});

		private ICommand _cmdManageRules_Command;

		private Collection<string> _existingGroupIds;

		private static readonly string[] BuiltInGroups = new string[7] { "All", "Feeds", "Initial", "Products", "Tears", "Boundary", "Charge" };

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main",
				UseChildId = true,
				ProxyRow = false,
				Name = "y"
			}
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

		public ICommand grid_RowDoubleClickCommand
		{
			get
			{
				if (_grid_RowDoubleClickCommand == null)
				{
					_grid_RowDoubleClickCommand = new CxvDelegateCommand<object>(grid_RowDoubleClickCommandExecute);
				}
				return _grid_RowDoubleClickCommand;
			}
		}

		public ICommand cmdAdd_Command
		{
			get
			{
				if (_cmdAdd_Command == null)
				{
					_cmdAdd_Command = new CxvDelegateCommand<object>(cmdAdd_CommandExecute, this, cmdAddCanExecuteProperty.Name + ".Value");
				}
				return _cmdAdd_Command;
			}
		}

		public CxvLogicalPropertyData cmdAddCanExecute => GetValue(cmdAddCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEditCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEditCanExecute => GetValue(cmdEditCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdCopy_Command
		{
			get
			{
				if (_cmdCopy_Command == null)
				{
					_cmdCopy_Command = new CxvDelegateCommand<object>(cmdCopy_CommandExecute, this, cmdCopyCanExecuteProperty.Name + ".Value");
				}
				return _cmdCopy_Command;
			}
		}

		public CxvLogicalPropertyData cmdCopyCanExecute => GetValue(cmdCopyCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdPaste_Command
		{
			get
			{
				if (_cmdPaste_Command == null)
				{
					_cmdPaste_Command = new CxvDelegateCommand<object>(cmdPaste_CommandExecute, this, cmdPaste_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdPaste_Command;
			}
		}

		public bool CanPaste
		{
			get
			{
				if (!ClipboardWrapper.ContainsData("Aspen Plus Selection"))
				{
					return false;
				}
				if (ClipboardWrapper.ContainsData("Aspen Plus Selection Type"))
				{
					IDataObject dataObject = ClipboardWrapper.GetDataObject();
					if (dataObject != null && dataObject.GetData("Aspen Plus Selection Type", autoConvert: false) is MemoryStream stream)
					{
						string text = new StreamReader(stream).ReadToEnd();
						string path = ExpandDataPath("@main");
						try
						{
							return CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "CanPaste:" + text)).CanInvoke;
						}
						catch (Exception)
						{
						}
					}
				}
				return true;
			}
		}

		public CxvLogicalPropertyData cmdPaste_CommandCanExecute => GetValue(cmdPaste_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new RelayActionCommand<object>(cmdDelete_Command_Execute, cmdDelete_CommandCanExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public ICommand cmdExport_Command
		{
			get
			{
				if (_cmdExport_Command == null)
				{
					_cmdExport_Command = new CxvDelegateCommand<object>(cmdExport_CommandExecute, this, cmdExportCanExecuteProperty.Name + ".Value");
				}
				return _cmdExport_Command;
			}
		}

		public CxvLogicalPropertyData cmdExportCanExecute => GetValue(cmdExportCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDuplicate_Command
		{
			get
			{
				if (_cmdDuplicate_Command == null)
				{
					_cmdDuplicate_Command = new CxvDelegateCommand<object>(cmdDuplicate_CommandExecute, this, cmdDuplicateCanExecuteProperty.Name + ".Value");
				}
				return _cmdDuplicate_Command;
			}
		}

		public CxvLogicalPropertyData cmdDuplicateCanExecute => GetValue(cmdDuplicateCanExecuteProperty) as CxvLogicalPropertyData;

		public bool CanDuplicate
		{
			get
			{
				IEnumerable<string> selectedIds = GetSelectedIds();
				if (selectedIds != null)
				{
					foreach (string item in selectedIds)
					{
						if (IsBuiltinGroup(item))
						{
							return false;
						}
					}
					return true;
				}
				return false;
			}
		}

		public ICommand cmdManageRules_Command
		{
			get
			{
				if (_cmdManageRules_Command == null)
				{
					_cmdManageRules_Command = new DelegateCommand<object>(cmdManageRules_CommandExecuted);
				}
				return _cmdManageRules_Command;
			}
		}

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		public int AllSelectedRecordsCount
		{
			get
			{
				return _allSelectedRecordsCount;
			}
			set
			{
				if (value != _allSelectedRecordsCount)
				{
					_allSelectedRecordsCount = value;
					OnAllSelectedRecordsCountChanged();
				}
				OnPropertyChanged("CanDuplicate");
			}
		}

		public ObservableCollection<int> SelectedRowIndexes
		{
			get
			{
				return _SelectedRowIndexes;
			}
			set
			{
				_SelectedRowIndexes = value;
			}
		}

		public event EventHandler CanPasteChanged;

		public event EventHandler AllSelectedRecordsCountChanged;

		public static bool IsBuiltinGroup(string name)
		{
			if (name.Equals("All") || name.Equals("Feeds") || name.Equals("Initial") || name.Equals("Products") || name.Equals("Tears") || name.Equals("Boundary") || name.Equals("Charge"))
			{
				return true;
			}
			return false;
		}

		private void grid_RowDoubleClickCommandExecute(object parameter)
		{
			IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string path = ".!" + enumerator.Current;
				GoToNode(path);
			}
		}

		private void cmdAdd_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			string newChildId = null;
			bool? flag = ShowAddChildDialog(parentPath, out newChildId);
			if (flag.HasValue && flag.Value)
			{
				AddChildren(ExpandDataPath("@main"), new Collection<string> { newChildId });
			}
		}

		private void SetDefaultPriorityForNewGroup(string id)
		{
			base.ResolvedCxsProvider.UpdateDataCache();
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main", "child_count"));
			string dataPath = $"@main.{id}.Input.PRIORITY";
			ExpandDataPathAndSet(dataPath, "value", num);
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount == 1)
			{
				IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
				if (enumerator.MoveNext())
				{
					string path = ".!" + enumerator.Current;
					GoToNode(path);
				}
			}
		}

		private void cmdCopy_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			CopyChildren(parentPath, collection);
			OnCanPasteChanged();
		}

		private void OnCanPasteChanged()
		{
			if (this.CanPasteChanged != null)
			{
				this.CanPasteChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("CanPaste");
		}

		private void cmdPaste_CommandExecute(object parameter)
		{
			Collection<string> second = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DoPaste(parentPath);
			base.ResolvedCxsProvider.UpdateDataCache();
			IEnumerable<string> enumerable = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids")).Except(second);
			if (enumerable == null)
			{
				return;
			}
			foreach (string item in enumerable)
			{
				SetDefaultPriorityForNewGroup(item);
			}
		}

		private bool CanDelete(string id)
		{
			if (IsBuiltinGroup(id))
			{
				return false;
			}
			string path = ExpandDataPath("@main");
			try
			{
				if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "DeleteChild")).CanInvoke)
				{
					return true;
				}
				if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath("@main.@y"), "can_delete", null)) ?? false))
				{
					return false;
				}
			}
			catch (Exception)
			{
				return false;
			}
			return true;
		}

		private bool cmdDelete_CommandCanExecute(object arg)
		{
			List<string> list = new List<string>();
			list = ((arg == null) ? GetSelectedIds().ToList() : new List<string> { arg as string });
			return !list.Any((string id) => !CanDelete(id));
		}

		private void cmdDelete_Command_Execute(object args)
		{
			int num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main", "child_count")) ?? 0;
			ExpandDataPath("@main");
			int num2 = 0;
			if (args != null)
			{
				string arg = args as string;
				string text = $"@main.{arg}.Input";
				int? num3 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(text + ".PRIORITY", "value"));
				if (num3.HasValue && num3.HasValue)
				{
					num2 = num3.Value;
				}
				DeleteChildren(ExpandDataPath("@main"), new Collection<string> { args as string });
			}
			else
			{
				IEnumerable<string> selectedIds = GetSelectedIds();
				int num4 = 100000;
				foreach (string item in selectedIds)
				{
					string dataPath = $"@main.{item}.Input.PRIORITY";
					int? num5 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(dataPath, "value"));
					if (num5.HasValue && num5.HasValue && num5.Value < num4)
					{
						num4 = num5.Value;
					}
				}
				num2 = num4;
				DeleteChildren(ExpandDataPath("@main"), selectedIds);
			}
			base.ResolvedCxsProvider.UpdateDataCache();
			int num6 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main", "child_count")) ?? 0;
			int num7 = num - num6;
			if (num7 <= 0 || num6 <= 7 || !(grdChild_GridData is IList))
			{
				return;
			}
			Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
			int num8 = num2;
			foreach (string item2 in collection)
			{
				string dataPath2 = $"@main.{item2}.Input.PRIORITY";
				int? num9 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(dataPath2, "value"));
				if (num9.HasValue && num9.HasValue && num9.Value > num8)
				{
					ExpandDataPathAndSet(dataPath2, "value", num9 - num7);
				}
			}
		}

		private void cmdExport_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
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

		private void cmdDuplicate_CommandExecute(object parameter)
		{
			if (!(grdChild_GridData is IList list))
			{
				return;
			}
			grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = list[SelectedRowIndexes[0]] as grdChild_GridData_ItemTemplate;
			_ = SelectedRowIndexes[0];
			if (grdChild_GridData_ItemTemplate == null)
			{
				return;
			}
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main", "child_count"));
			if (num.HasValue)
			{
				_ = num.Value;
			}
			string id = grdChild_GridData_ItemTemplate.GetId();
			string description = grdChild_GridData_ItemTemplate.GetDescription();
			string format = grdChild_GridData_ItemTemplate.GetFormat();
			string text = $"@main.{id}.Input";
			string value = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".SGTEMPLATE", "value"));
			string value2 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".CONDITION", "value"));
			string value3 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".CONTAIN_TEXT", "value"));
			string value4 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".OPERATOR", "value"));
			string value5 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".PROP_SET", "value"));
			string value6 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".SCOPE", "value"));
			string value7 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".SECTION", "value"));
			string value8 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".SELECTION", "value"));
			string value9 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".VALUE1", "value"));
			string value10 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + ".VALUE2", "value"));
			Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
			string text2 = null;
			int num2 = 0;
			do
			{
				text2 = CreateNewVariableName(grdChild_GridData_ItemTemplate.GetId(), $"DP{++num2}");
			}
			while (collection.Contains(text2));
			AddChildren(ExpandDataPath("@main"), new Collection<string> { text2 });
			string text3 = $"@main.{text2}.Input";
			if (!string.IsNullOrEmpty(value))
			{
				ExpandDataPathAndSet(text3 + ".SGTEMPLATE", "value", value);
			}
			if (!string.IsNullOrEmpty(description))
			{
				ExpandDataPathAndSet(text3 + ".DESCRIPTION", "value", description);
			}
			if (!string.IsNullOrEmpty(format))
			{
				ExpandDataPathAndSet(text3 + ".LINESTYLE", "value", format);
			}
			Collection<string> collection2 = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet($"@main.{id}.Input.STREAM_LIST", "child_ids"));
			if (collection2 != null)
			{
				int num3 = 0;
				foreach (string item in collection2)
				{
					object value11 = ExpandDataPathAndGet($"@main.{id}.Input.STREAM_LIST.{item}", "value");
					AddChild($"@main.{text2}.Input.STREAM_LIST", num3);
					ExpandDataPathAndSet($"@main.{text2}.Input.STREAM_LIST.#{num3}", "value", value11);
					num3++;
				}
			}
			if (!string.IsNullOrEmpty(value2))
			{
				ExpandDataPathAndSet(text3 + ".CONDITION", "value", value2);
			}
			if (!string.IsNullOrEmpty(value3))
			{
				ExpandDataPathAndSet(text3 + ".CONTAIN_TEXT", "value", value3);
			}
			if (!string.IsNullOrEmpty(value4))
			{
				ExpandDataPathAndSet(text3 + ".OPERATOR", "value", value4);
			}
			if (!string.IsNullOrEmpty(value5))
			{
				ExpandDataPathAndSet(text3 + ".PROP_SET", "value", value5);
			}
			if (!string.IsNullOrEmpty(value6))
			{
				ExpandDataPathAndSet(text3 + ".SCOPE", "value", value6);
			}
			if (!string.IsNullOrEmpty(value7))
			{
				ExpandDataPathAndSet(text3 + ".SECTION", "value", value7);
			}
			if (!string.IsNullOrEmpty(value8))
			{
				ExpandDataPathAndSet(text3 + ".SELECTION", "value", value8);
			}
			if (!string.IsNullOrEmpty(value9))
			{
				ExpandDataPathAndSet(text3 + ".VALUE1", "value", value9);
			}
			if (!string.IsNullOrEmpty(value10))
			{
				ExpandDataPathAndSet(text3 + ".VALUE2", "value", value10);
			}
			SetDefaultPriorityForNewGroup(text2);
		}

		private string CreateNewVariableName(string name, string suffix)
		{
			if (name.Length < 8 - suffix.Length)
			{
				return name + suffix;
			}
			return name.Substring(0, 8 - suffix.Length) + suffix;
		}

		private void cmdManageRules_CommandExecuted(object obj)
		{
			StreamGroupPriorityDlg streamGroupPriorityDlg = new StreamGroupPriorityDlg(base.UnityContainer, this);
			if (base.View is MMTabPage dependencyObject)
			{
				streamGroupPriorityDlg.Owner = Window.GetWindow(dependencyObject);
			}
			streamGroupPriorityDlg.ShowDialog();
			UpdateDisplay();
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				_existingGroupIds = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
				int num = BuiltInGroups.Length;
				List<int> list = new List<int>();
				string[] builtInGroups = BuiltInGroups;
				foreach (string text in builtInGroups)
				{
					int item = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main." + text + ".Input.PRIORITY", "value")) ?? 0;
					list.Add(item);
				}
				foreach (string existingGroupId in _existingGroupIds)
				{
					if (BuiltInGroups.Contains(existingGroupId, StringComparer.InvariantCultureIgnoreCase))
					{
						continue;
					}
					string dataPath = $"@main.{existingGroupId}.Input.PRIORITY";
					int item2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(dataPath, "value")) ?? 0;
					if (list.Contains(item2))
					{
						do
						{
							num++;
						}
						while (list.Contains(num));
						ExpandDataPathAndSet(dataPath, "value", num);
					}
				}
			}
			else
			{
				Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
				if (!collection.SequenceEqual(_existingGroupIds))
				{
					if (collection.Count > _existingGroupIds.Count)
					{
						string[] array = collection.Except(_existingGroupIds).ToArray();
						if (array != null)
						{
							for (int j = 0; j < array.Length; j++)
							{
								string arg = array[j];
								string dataPath2 = $"@main.{arg}.Input.PRIORITY";
								ExpandDataPathAndSet(dataPath2, "value", _existingGroupIds.Count + j + 1);
							}
						}
					}
					_existingGroupIds = collection;
				}
			}
			base.OnUpdateData();
		}

		private void OnAllSelectedRecordsCountChanged()
		{
			if (this.AllSelectedRecordsCountChanged != null)
			{
				this.AllSelectedRecordsCountChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("AllSelectedRecordsCount");
		}

		[IteratorStateMachine(typeof(SelectedIdsEnumerator))]
		private IEnumerable<string> GetSelectedIds()
		{
			return new SelectedIdsEnumerator(-2)
			{
				owner = this
			};
		}
	}
	[ProgId("MMSetup.MMSetup_StreamGroup_ObjManager")]
	public class MMSetup_StreamGroup_ObjManager : MMTabPage, IComponentConnector
	{
		internal MMFlatButton cmdNew;

		internal MMFlatButton cmdEdit;

		internal MMFlatButton cmdCopy;

		internal MMFlatButton cmdPaste;

		internal MMFlatButton cmdDuplicate;

		internal MMFlatButton cmdExport;

		internal MMFlatButton cmdManageRules;

		internal MMScrollAreaMS grdChild;

		private bool _contentLoaded;

		public MMSetup_StreamGroup_ObjManager()
		{
			base.ViewModelType = typeof(MMSetup_StreamGroup_ObjManager_ViewModel);
			InitializeComponent();
			grdChild.DisplayTextConverter = ConvertDisplayText;
		}

		private (bool Handled, string DisplayText) ConvertDisplayText(IDataCell cell, string sourceText)
		{
			if (cell.Column.Index == 0 && !string.IsNullOrEmpty(sourceText))
			{
				(bool, string) streamGroupResourceText = GetStreamGroupResourceText(sourceText);
				if (streamGroupResourceText.Item1)
				{
					return (Handled: true, DisplayText: streamGroupResourceText.Item2);
				}
			}
			return (Handled: false, DisplayText: sourceText);
		}

		public static (bool Changed, string DisplayText) GetStreamGroupResourceText(string groupName)
		{
			if (!string.IsNullOrEmpty(groupName))
			{
				switch (groupName.ToLowerInvariant())
				{
				case "all":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_All);
				case "feeds":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Feeds);
				case "initial":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Initialized);
				case "products":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Products);
				case "tears":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Tears);
				case "boundary":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Boundary);
				case "charge":
					return (Changed: true, DisplayText: GridFormsResources.StreamReport_StreamGroup_BuiltIn_Charge);
				}
			}
			return (Changed: false, DisplayText: groupName);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_streamgroup_objmanager.xaml", UriKind.Relative);
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
				cmdNew = (MMFlatButton)target;
				break;
			case 2:
				cmdEdit = (MMFlatButton)target;
				break;
			case 3:
				cmdCopy = (MMFlatButton)target;
				break;
			case 4:
				cmdPaste = (MMFlatButton)target;
				break;
			case 5:
				cmdDuplicate = (MMFlatButton)target;
				break;
			case 6:
				cmdExport = (MMFlatButton)target;
				break;
			case 7:
				cmdManageRules = (MMFlatButton)target;
				break;
			case 8:
				grdChild = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_StreamGroup_Selection_ViewModel : MMTabPageViewModel
	{
		private class BuiltinGroupResourceConverter : IValueConverter
		{
			public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
			{
				if (value is string groupName)
				{
					(bool, string) streamGroupResourceText = MMSetup_StreamGroup_ObjManager.GetStreamGroupResourceText(groupName);
					if (streamGroupResourceText.Item1)
					{
						return streamGroupResourceText.Item2;
					}
				}
				return value;
			}

			public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
			{
				throw new NotImplementedException();
			}
		}

		private static string _plantItemContent = ApwDlgRes.StreamGroupDlg_Plant;

		private static string _allSectionItemContent = ApwDlgRes.StreamGroupDlg_AllSection;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.STREAM_LIST"
		});

		public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main",
			IsReadOnly = true,
			Converter = typeof(BuiltinGroupResourceConverter)
		});

		public static readonly CxvPropertyDeclaration SummaryTemplate_var1_Property = CxvPropertyDeclaration.Register("SummaryTemplate_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SGTEMPLATE"
		});

		private bool _isTemplateDropDownOpen;

		public static readonly CxvPropertyDeclaration txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DESCRIPTION"
		});

		public static readonly CxvPropertyDeclaration SelectedGroupVisible_Property = CxvPropertyDeclaration.Register("SelectedGroupVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.SELECTION",
			Value = "SELECTED",
			Operator = CxvLogicalOperator.Equal
		});

		public static readonly CxvPropertyDeclaration ConditionalGroupVisible_Property = CxvPropertyDeclaration.Register("ConditionalGroupVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.SELECTION",
			Value = "CONDITIONAL",
			Operator = CxvLogicalOperator.Equal
		});

		public static readonly CxvPropertyDeclaration BuiltInListVisible_Property = CxvPropertyDeclaration.Register("BuiltInListVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.SELECTION",
			DataAttribute = "can_enter",
			Value = 0,
			Operator = CxvLogicalOperator.Equal
		});

		public static readonly CxvPropertyDeclaration SelectionVar_MultiMap_Property = CxvPropertyDeclaration.Register("SelectionVar_MultiMap", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.Input.SELECTION",
				DataAttribute = "can_enter"
			},
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "SelectionVar",
					DataPath = "@main.Input.SELECTION"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Selected streams",
					Value = "SelectionVar_MultiMapOption_1",
					Prompt = PromptResources.FILEPNUM_92_Prompt_4,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "SelectionVar",
							Value = "SELECTED"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Conditional streams",
					Value = "SelectionVar_MultiMapOption_2",
					Prompt = PromptResources.FILEPNUM_92_Prompt_16,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "SelectionVar",
							Value = "CONDITIONAL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration Sections_var_Property = CxvPropertyDeclaration.Register("Sections_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SECTION",
			AllowNew = false
		});

		public static readonly CxvPropertyDeclaration Scope_var_Property = CxvPropertyDeclaration.Register("Scope_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SCOPE",
			AllowNew = false
		});

		public static readonly CxvPropertyDeclaration Condition_var_Property = CxvPropertyDeclaration.Register("Condition_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "Condition_var",
					DataPath = "@main.Input.CONDITION"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "NAME",
					DisplayResourceKey = "setup_stream_groups_sg_1_condition_name",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Condition_var",
							Value = "NAME"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PROPERTY",
					DisplayResourceKey = "setup_stream_groups_sg_1_condition_property",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Condition_var",
							Value = "PROPERTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration PropSet_var_Property = CxvPropertyDeclaration.Register("PropSet_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_SET",
			AllowNew = false,
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "Condition_var.Value",
				Value = "PROPERTY",
				Operator = CxvLogicalOperator.Equal
			}
		});

		public static readonly CxvPropertyDeclaration ContainText_var_Property = CxvPropertyDeclaration.Register("ContainText_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.CONTAIN_TEXT",
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "Condition_var.Value",
				Value = "NAME",
				Operator = CxvLogicalOperator.Equal
			}
		});

		public static readonly CxvPropertyDeclaration Operator_MultiMap_Property = CxvPropertyDeclaration.Register("Operator_MultiMap", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "Operator_var1",
					DataPath = "@main.Input.OPERATOR"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Greater than",
					DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Greater_than",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Operator_var1",
							Value = "Greater than"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = ">=",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Operator_var1",
							Value = ">="
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Less than",
					DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Less_than",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Operator_var1",
							Value = "Less than"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "<=",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Operator_var1",
							Value = "<="
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Between",
					DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Between",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Operator_var1",
							Value = "BETWEEN"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "Condition_var.Value",
				Value = "PROPERTY",
				Operator = CxvLogicalOperator.Equal
			}
		});

		private string _valueLabel = ApwDlgRes.StreamGroupsDlg_Value2;

		public static readonly CxvPropertyDeclaration Value1_var_Property = CxvPropertyDeclaration.Register("Value1_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VALUE1",
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "Condition_var.Value",
				Value = "PROPERTY",
				Operator = CxvLogicalOperator.Equal
			}
		});

		public static readonly CxvPropertyDeclaration Value2_var_Property = CxvPropertyDeclaration.Register("Value2_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VALUE2",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.COND3"
			}
		});

		public static readonly CxvPropertyDeclaration ValueUnit_var_Property = CxvPropertyDeclaration.Register("ValueUnit_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvParameterProperty
		{
			Parameter = "p_ValueUnits",
			IsReadOnly = true
		});

		private Collection<string> _containsOptions = new Collection<string> { ApwDlgRes.StreamGroupsDlg_ConditionComboItem_Contains };

		public static readonly CxvPropertyDeclaration Contains_var_Property = CxvPropertyDeclaration.Register("Contains_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				PropertyPath = "Condition_var.Value",
				Value = "NAME",
				Operator = CxvLogicalOperator.Equal
			}
		});

		private readonly ObservableCollection<string> _conditionalStreamsList = new ObservableCollection<string>();

		private readonly ObservableCollection<string> _allTemplateNames = new ObservableCollection<string>();

		private string _selectedTemplate;

		private CxvPropertyWatch _templateWatch;

		private CxvPropertyWatch _globalUnitSetWatch;

		public static readonly CxvPropertyDeclaration format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLineFormatProperty
		{
			DataPath = "@main.Input.LINESTYLE"
		});

		private int _colorIndex;

		private double _lineWeight = 1.0;

		private int _lineStyle;

		private Color _lineColor = Colors.Black;

		private static Color[] _definedColors = new Color[16]
		{
			Colors.Black,
			Colors.Navy,
			Colors.Green,
			Colors.Teal,
			Colors.Brown,
			Colors.Purple,
			Colors.DarkOliveGreen,
			Colors.Gray,
			Colors.DarkGray,
			Colors.Blue,
			Colors.LightGreen,
			Colors.SkyBlue,
			Colors.Red,
			Colors.Fuchsia,
			Colors.Yellow,
			Colors.LightGray
		};

		private CxvPropertyWatch _formatWatch;

		private IEnumerable<string> _availableStreams;

		private CxvPropertyWatch _streamsWatch;

		private IEnumerable<string> _allMaterialStreams;

		private IEnumerable<string> _hierarchyBlocks;

		private string _selectedHierarchy = _plantItemContent;

		private List<string> _allSectionNames = new List<string>();

		private IEnumerable<string> _sectionNames;

		private string _selectedSection;

		private CxvPropertyWatch _sectionsWatch;

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		public object txtName_var1 => GetValue(txtName_var1_Property);

		public object SummaryTemplate_var1 => GetValue(SummaryTemplate_var1_Property);

		public bool IsTemplateDropDownOpen
		{
			get
			{
				return _isTemplateDropDownOpen;
			}
			set
			{
				_isTemplateDropDownOpen = value;
				OnPropertyChanged("IsTemplateDropDownOpen");
				if (_isTemplateDropDownOpen)
				{
					UpdateSelectedTemplate();
				}
			}
		}

		public object txtDescription_var1 => GetValue(txtDescription_var1_Property);

		public object SelectedGroupVisible => GetValue(SelectedGroupVisible_Property);

		public object ConditionalGroupVisible => GetValue(ConditionalGroupVisible_Property);

		public object BuiltInListVisible => GetValue(BuiltInListVisible_Property);

		public object SelectionVar_MultiMap => GetValue(SelectionVar_MultiMap_Property);

		public object Sections_var => GetValue(Sections_var_Property);

		public object Scope_var => GetValue(Scope_var_Property);

		public object Condition_var => GetValue(Condition_var_Property);

		public object PropSet_var => GetValue(PropSet_var_Property);

		public object ContainText_var => GetValue(ContainText_var_Property);

		public object Operator_MultiMap => GetValue(Operator_MultiMap_Property);

		public string ValueLabel
		{
			get
			{
				return _valueLabel;
			}
			set
			{
				_valueLabel = value;
				OnPropertyChanged("ValueLabel");
			}
		}

		public object Value1_var => GetValue(Value1_var_Property);

		public object Value2_var => GetValue(Value2_var_Property);

		public object ValueUnit_var => GetValue(ValueUnit_var_Property);

		public Collection<string> ContainsOptions => _containsOptions;

		public object Contains_var => GetValue(Contains_var_Property);

		public ObservableCollection<string> ConditionalStreamsList => _conditionalStreamsList;

		public ObservableCollection<string> AllTemplateNames => _allTemplateNames;

		public string SelectedTemplate
		{
			get
			{
				return _selectedTemplate;
			}
			set
			{
				_selectedTemplate = value;
				OnPropertyChanged("SelectedTemplate");
				SaveSelectedTemplate();
			}
		}

		public object format_var => GetValue(format_var_Property);

		public int ColorIndex
		{
			get
			{
				return _colorIndex;
			}
			set
			{
				if (_colorIndex != value)
				{
					_colorIndex = value;
					OnPropertyChanged("ColorIndex");
					SaveFormat();
				}
			}
		}

		public double LineWeight
		{
			get
			{
				return _lineWeight;
			}
			set
			{
				if (_lineWeight != value)
				{
					_lineWeight = value;
					OnPropertyChanged("LineWeight");
					SaveFormat();
				}
			}
		}

		public int LineStyle
		{
			get
			{
				return _lineStyle;
			}
			set
			{
				if (_lineStyle != value)
				{
					_lineStyle = value;
					OnPropertyChanged("LineStyle");
					SaveFormat();
				}
			}
		}

		public Color LineColor
		{
			get
			{
				return _lineColor;
			}
			set
			{
				if (_lineColor != value)
				{
					_lineColor = value;
					OnPropertyChanged("LineColor");
					SaveFormat();
				}
			}
		}

		public IEnumerable<string> AvailableStreams
		{
			get
			{
				return _availableStreams;
			}
			set
			{
				_availableStreams = value;
				OnPropertyChanged("AvailableStreams");
			}
		}

		public IEnumerable<string> HierarchyBlocks
		{
			get
			{
				return _hierarchyBlocks;
			}
			set
			{
				_hierarchyBlocks = value;
				OnPropertyChanged("HierarchyBlocks");
			}
		}

		public string SelectedHierarchy
		{
			get
			{
				return _selectedHierarchy;
			}
			set
			{
				if (_selectedHierarchy != value)
				{
					_selectedHierarchy = value;
					OnPropertyChanged("SelectedHierarchy");
					if (!string.IsNullOrEmpty(_selectedHierarchy))
					{
						UpdateSectionList();
					}
					UpdateAvailableStreams();
				}
			}
		}

		public IEnumerable<string> SectionNames
		{
			get
			{
				return _sectionNames;
			}
			set
			{
				_sectionNames = value;
				OnPropertyChanged("SectionNames");
			}
		}

		public string SelectedSection
		{
			get
			{
				return _selectedSection;
			}
			set
			{
				if (_selectedSection != value)
				{
					_selectedSection = value;
					OnPropertyChanged("SelectedSection");
					if (!string.IsNullOrEmpty(_selectedSection))
					{
						UpdateAvailableStreams();
					}
				}
			}
		}

		private void UpdateSelectedTemplate()
		{
			_allTemplateNames.Clear();
			foreach (string streamSummaryTemplateName in GetStreamSummaryTemplateNames())
			{
				_allTemplateNames.Add(streamSummaryTemplateName);
			}
			_allTemplateNames.Add(ApwDlgRes.StreamGroupsDlg_Default);
			if (_templateWatch != null)
			{
				_templateWatch.PropertyDependencyChanged -= _templateWatch_PropertyDependencyChanged;
				_templateWatch.Clear();
			}
			else
			{
				_templateWatch = new CxvPropertyWatch();
			}
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.SGTEMPLATE", "value", null, _templateWatch));
			if (_allTemplateNames.Contains(text))
			{
				SelectedTemplate = text;
			}
			else
			{
				SelectedTemplate = ApwDlgRes.StreamGroupsDlg_Default;
			}
			if (!_templateWatch.IsEmpty)
			{
				_templateWatch.PropertyDependencyChanged += _templateWatch_PropertyDependencyChanged;
			}
			else
			{
				_templateWatch = null;
			}
		}

		private void _templateWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateSelectedTemplate();
		}

		private void SaveSelectedTemplate()
		{
			string text = "";
			if (!SelectedTemplate.Equals(ApwDlgRes.StreamGroupsDlg_Default, StringComparison.InvariantCultureIgnoreCase))
			{
				text = SelectedTemplate;
			}
			if (!CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.SGTEMPLATE", "value")).Equals(text, StringComparison.InvariantCultureIgnoreCase))
			{
				ExpandDataPathAndSet("@main.Input.SGTEMPLATE", "value", text);
				string groupName = CxsConverter.ValueToString(this.ResolveViewPropertyPath("txtName_var1.Value"));
				string text2 = text;
				if (text2 == string.Empty)
				{
					text2 = null;
				}
				((CompositePresentationEvent<StreamGroupTemplateChangedEventArgs>)(object)base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<StreamGroupTemplateChangedEvent>()).Publish(new StreamGroupTemplateChangedEventArgs(groupName, text2));
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				UpdateAllMaterialStreams();
				UpdateAllSectionNames();
				UpdateAvailableStreams();
				UpdateFormat();
				UpdateSelectedTemplate();
				_globalUnitSetWatch = new CxvPropertyWatch();
				ExpandDataPathAndGet("Top.appModelV8.Setup.Global.Input.INSET", "value", null, _globalUnitSetWatch);
				_globalUnitSetWatch.PropertyDependencyChanged += _globalUnitSetWatch_ValuesChanged;
			}
			else
			{
				UpdateAllMaterialStreams();
				UpdateAvailableStreams();
				UpdateConditionalStreamsList();
			}
			UpdateSIUnitForSelectedProperty();
			base.OnUpdateData();
		}

		private void _globalUnitSetWatch_ValuesChanged(object sender, EventArgs e)
		{
			UpdateConditionalStreamsList();
		}

		protected override void OnViewChanged()
		{
			if (base.ResolvedCxsProvider != null)
			{
				base.ResolvedCxsProvider.Case.Message += Case_Message;
			}
			base.OnViewChanged();
		}

		private void Case_Message(object sender, CxsMessageEventArgs e)
		{
			foreach (CxsMessage message in e.Messages)
			{
				if (message.MessageType == CxsMessageType.RunCompleted)
				{
					(base.View as MMTabPage).Dispatcher.BeginInvoke((Action)delegate
					{
						UpdateConditionalStreamsList();
					});
				}
			}
		}

		public override void Unload()
		{
			if (base.ResolvedCxsProvider != null)
			{
				base.ResolvedCxsProvider.Case.Message -= Case_Message;
			}
			if (_globalUnitSetWatch != null)
			{
				_globalUnitSetWatch.PropertyDependencyChanged -= _globalUnitSetWatch_ValuesChanged;
				_globalUnitSetWatch = null;
			}
			base.Unload();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if ((pd.Name == "Condition_var" && subPropertyName == "Value") || (pd.Name == "Operator_MultiMap" && subPropertyName == "SelectedItem"))
			{
				string obj = (Condition_var as CxvMultiMapPropertyData).Value as string;
				string text = (Operator_MultiMap as CxvMultiMapPropertyData).Value as string;
				if (obj == "PROPERTY" && text == "Between")
				{
					ValueLabel = ApwDlgRes.StreamGroupsDlg_Value1;
				}
				else
				{
					ValueLabel = ApwDlgRes.StreamGroupsDlg_Value;
				}
			}
			if (((pd.Name == "SelectionVar_MultiMap" || pd.Name == "Operator_MultiMap") && subPropertyName == "SelectedItem") || (subPropertyName == "Value" && (pd.Name == "Condition_var" || pd.Name == "ContainText_var" || pd.Name == "PropSet_var" || pd.Name == "Operator_var" || pd.Name == "Value1_var" || pd.Name == "Value2_var")))
			{
				UpdateConditionalStreamsList();
			}
			else if (pd.Name == "MMListPicker1_var1" && subPropertyName == "Value")
			{
				UpdateAvailableStreams();
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		private void UpdateConditionalStreamsList()
		{
			ConditionalStreamsList.Clear();
			string groupName = CxsConverter.ValueToString(ResolveParameter("id"));
			IEnumerable<string> selectedStreamsInStreamGroup = GetSelectedStreamsInStreamGroup(groupName);
			if (selectedStreamsInStreamGroup == null)
			{
				return;
			}
			foreach (string item in selectedStreamsInStreamGroup)
			{
				ConditionalStreamsList.Add(item);
			}
		}

		private void UpdateFormat()
		{
			if (_formatWatch != null)
			{
				_formatWatch.PropertyDependencyChanged -= _formatWatch_PropertyDependencyChanged;
				_formatWatch.Clear();
			}
			else
			{
				_formatWatch = new CxvPropertyWatch();
			}
			if (string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveViewPropertyPath("format_var.Value", _formatWatch))))
			{
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("Top.appModelV8.Settings.material_color", "value"));
				if (num.HasValue)
				{
					_colorIndex = num.Value;
				}
				int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("Top.appModelV8.Settings.material_width", "value"));
				if (num2.HasValue)
				{
					_lineWeight = num2.Value;
				}
				int? num3 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("Top.appModelV8.Settings.material_style", "value"));
				if (num3.HasValue)
				{
					_lineStyle = num3.Value;
				}
				if (_colorIndex >= 0 && _colorIndex < _definedColors.Length)
				{
					LineColor = _definedColors[_colorIndex];
				}
			}
			else
			{
				int? num4 = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.ColorIndex"));
				if (num4.HasValue)
				{
					_colorIndex = num4.Value;
				}
				int? num5 = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.LineWeight"));
				if (num5.HasValue)
				{
					_lineWeight = num5.Value;
				}
				int? num6 = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.LineStyle"));
				if (num6.HasValue)
				{
					_lineStyle = num6.Value;
				}
				LineColor = (Color)this.ResolveViewPropertyPath("format_var.LineColor");
			}
			OnPropertyChanged("ColorIndex");
			OnPropertyChanged("LineWeight");
			OnPropertyChanged("LineStyle");
			if (!_formatWatch.IsEmpty)
			{
				_formatWatch.PropertyDependencyChanged += _formatWatch_PropertyDependencyChanged;
			}
			else
			{
				_formatWatch = null;
			}
		}

		private void _formatWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateFormat();
		}

		public void SaveFormat()
		{
			string text = $"{ColorIndex};{(int)LineWeight};{LineStyle}";
			if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.LINESTYLE", "value")) != text)
			{
				ExpandDataPathAndSet("@main.Input.LINESTYLE", "value", text);
				bool? flag = CxsConverter.ValueToBoolean(ResolveViewPropertyPath("BuiltInListVisible.Value", null));
				bool? flag2 = CxsConverter.ValueToBoolean(ResolveViewPropertyPath("ConditionalGroupVisible.Value", null));
				bool? flag3 = CxsConverter.ValueToBoolean(ResolveViewPropertyPath("SelectedGroupVisible.Value", null));
				if (flag == true || flag2 == true)
				{
					RefreshStreamGroupsInPfs(allFlowsheets: true, ConditionalStreamsList);
				}
				else if (flag3 == true)
				{
					RefreshStreamGroupsInPfs(allFlowsheets: true, AvailableStreams);
				}
			}
		}

		private void UpdateAvailableStreams()
		{
			if (_allMaterialStreams == null)
			{
				UpdateAllMaterialStreams();
				if (_allMaterialStreams == null)
				{
					AvailableStreams = null;
					return;
				}
			}
			List<string> list = new List<string>();
			if (SelectedHierarchy.Equals(_plantItemContent, StringComparison.InvariantCultureIgnoreCase))
			{
				list.AddRange(_allMaterialStreams);
			}
			else
			{
				list.AddRange(_allMaterialStreams.Where((string p) => p.StartsWith(SelectedHierarchy + ".")));
			}
			IEnumerable<string> second = list;
			if (!SelectedSection.Equals(_allSectionItemContent))
			{
				StringBuilder stringBuilder = new StringBuilder("Top.appModelV8.");
				StringBuilder stringBuilder2 = new StringBuilder();
				string[] array = SelectedSection.Split('.');
				if (array.Length == 1)
				{
					stringBuilder.AppendFormat("Flowsheet.Section.{0}", array[0]);
				}
				else
				{
					int num = 0;
					for (num = 0; num < array.Length - 1; num++)
					{
						stringBuilder.AppendFormat("Blocks.{0}.Data.", array[num]);
						stringBuilder2.AppendFormat("{0}.", array[num]);
					}
					stringBuilder.AppendFormat("Flowsheet.Section.{0}", array[num]);
				}
				List<string> list2 = new List<string>();
				string text = stringBuilder.ToString() + ".Input.INSTRM";
				Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet(text, "child_ids"));
				if (collection != null)
				{
					foreach (string item in collection)
					{
						Collection<string> collection2 = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet(text + "." + item, "child_ids"));
						if (collection2 == null)
						{
							continue;
						}
						foreach (string item2 in collection2)
						{
							string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet(text + "." + item + "." + item2, "value"));
							if (!string.IsNullOrEmpty(stringBuilder2.ToString()))
							{
								text2 = stringBuilder2.ToString() + text2;
							}
							list2.Add(text2);
						}
					}
				}
				List<string> list3 = new List<string>();
				string text3 = stringBuilder.ToString() + ".Input.OUTSTRM";
				collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet(text3, "child_ids"));
				if (collection != null)
				{
					foreach (string item3 in collection)
					{
						Collection<string> collection3 = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet(text3 + "." + item3, "child_ids"));
						if (collection3 == null)
						{
							continue;
						}
						foreach (string item4 in collection3)
						{
							string text4 = CxsConverter.ValueToString(ExpandDataPathAndGet(text3 + "." + item3 + "." + item4, "value"));
							if (!string.IsNullOrEmpty(stringBuilder2.ToString()))
							{
								text4 = stringBuilder2.ToString() + text4;
							}
							list3.Add(text4);
						}
					}
				}
				second = list2.Union(list3).Intersect(list);
			}
			AvailableStreams = _allMaterialStreams.Intersect(second);
		}

		private void UpdateAllMaterialStreams()
		{
			_allMaterialStreams = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.STREAM_LIST", "option_list"));
			Collection<string> collection = new Collection<string> { _plantItemContent };
			if (_allMaterialStreams != null)
			{
				foreach (string allMaterialStream in _allMaterialStreams)
				{
					if (!allMaterialStream.Contains("."))
					{
						continue;
					}
					string[] array = allMaterialStream.Split('.');
					for (int i = 0; i < array.Length - 1; i++)
					{
						StringBuilder stringBuilder = new StringBuilder();
						for (int j = 0; j <= i; j++)
						{
							stringBuilder.AppendFormat("{0}.", array[j]);
						}
						stringBuilder.Remove(stringBuilder.Length - 1, 1);
						string item = stringBuilder.ToString();
						if (!collection.Contains(item))
						{
							collection.Add(item);
						}
					}
				}
			}
			HierarchyBlocks = collection;
		}

		private void _streamsWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateAllMaterialStreams();
			UpdateAvailableStreams();
			UpdateConditionalStreamsList();
		}

		private void UpdateSectionList()
		{
			List<string> list = new List<string>();
			if (SelectedHierarchy == _plantItemContent)
			{
				list.AddRange(_allSectionNames);
			}
			else
			{
				list.AddRange(_allSectionNames.Where((string p) => p.StartsWith(SelectedHierarchy)));
			}
			list.Add(_allSectionItemContent);
			list.Reverse();
			SectionNames = list;
			if (string.IsNullOrEmpty(SelectedSection) || !SectionNames.Contains(SelectedSection))
			{
				SelectedSection = _allSectionItemContent;
			}
		}

		private void UpdateAllSectionNames()
		{
			if (_sectionsWatch != null)
			{
				_sectionsWatch.PropertyDependencyChanged -= _sectionsWatch_PropertyDependencyChanged;
				_sectionsWatch.Clear();
			}
			else
			{
				_sectionsWatch = new CxvPropertyWatch();
			}
			ExpandDataPathAndGet("@main.Input.SECTION", "option_list", null, _sectionsWatch);
			if (HierarchyBlocks != null)
			{
				foreach (string hierarchyBlock in HierarchyBlocks)
				{
					if (!hierarchyBlock.Equals(_plantItemContent, StringComparison.InvariantCultureIgnoreCase))
					{
						StringBuilder stringBuilder = new StringBuilder("Top.appModelV8.");
						StringBuilder stringBuilder2 = new StringBuilder();
						string[] array = hierarchyBlock.Split('.');
						for (int i = 0; i < array.Length; i++)
						{
							stringBuilder.AppendFormat("Blocks.{0}.Data.", array[i]);
							stringBuilder2.AppendFormat("{0}.", array[i]);
						}
						stringBuilder.AppendFormat("Flowsheet.Section");
						ExpandDataPathAndGet(stringBuilder.ToString(), "child_ids", null, _sectionsWatch);
					}
				}
			}
			_allSectionNames.Clear();
			_allSectionNames.AddRange(GetAllSectionNames());
			UpdateSectionList();
			if (!_sectionsWatch.IsEmpty)
			{
				_sectionsWatch.PropertyDependencyChanged += _sectionsWatch_PropertyDependencyChanged;
			}
			else
			{
				_sectionsWatch = null;
			}
		}

		private void _sectionsWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateAllSectionNames();
		}

		private void UpdateSIUnitForSelectedProperty()
		{
			string arg = CxsConverter.ValueToString(ResolveViewPropertyPath("PropSet_var.Value", null));
			string propEngineName = CxsConverter.ValueToString(ExpandDataPathAndGet($"Top.appModelV8.Properties.Prop-Sets.{arg}.Input.UNITS.#0", "id"));
			string sIUnitsForProperty = GetSIUnitsForProperty(propEngineName);
			ResolveUpdateParameter("p_ValueUnits", sIUnitsForProperty, localOnly: true);
		}
	}
	public class MMSetup_Simopt_ModOpt_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration expandar_compr_Property = CxvPropertyDeclaration.Register("expandar_compr", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTCOMPR" }
		});

		public static readonly CxvPropertyDeclaration expandar_mcompr_Property = CxvPropertyDeclaration.Register("expandar_mcompr", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTMCOMP" }
		});

		public static readonly CxvPropertyDeclaration expandar_rgibbs_Property = CxvPropertyDeclaration.Register("expandar_rgibbs", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTRGIBB" }
		});

		public static readonly CxvPropertyDeclaration expandar_radfrac_Property = CxvPropertyDeclaration.Register("expandar_radfrac", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTRADFR" }
		});

		public static readonly CxvPropertyDeclaration expandar_heatx_Property = CxvPropertyDeclaration.Register("expandar_heatx", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTHEATX" }
		});

		public static readonly CxvPropertyDeclaration expandar_heater_Property = CxvPropertyDeclaration.Register("expandar_heater", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTHEATER" }
		});

		public static readonly CxvPropertyDeclaration expandar_Mheatx_Property = CxvPropertyDeclaration.Register("expandar_Mheatx", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTMHEATX" }
		});

		public static readonly CxvPropertyDeclaration cmbComprNPh_var1_Property = CxvPropertyDeclaration.Register("cmbComprNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Model-Option.Input.COMPR_NPHASE",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration spnComprMaxit_var1_Property = CxvPropertyDeclaration.Register("spnComprMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.SB_MAXIT"
		});

		public static readonly CxvPropertyDeclaration lbtuComprTol_var1_Property = CxvPropertyDeclaration.Register("lbtuComprTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.SB_TOL"
		});

		public static readonly CxvPropertyDeclaration cmbMComprNPh_var1_Property = CxvPropertyDeclaration.Register("cmbMComprNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Model-Option.Input.MCOMPR_NPHAS",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration cmbCoolNPh_var1_Property = CxvPropertyDeclaration.Register("cmbCoolNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Model-Option.Input.COOLER_NPHAS",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration spnMComprMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMComprMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.MC_SB_MAXIT"
		});

		public static readonly CxvPropertyDeclaration lbtuMComprTol_var1_Property = CxvPropertyDeclaration.Register("lbtuMComprTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.MC_SB_TOL"
		});

		public static readonly CxvPropertyDeclaration spnRGibbsNPh_var1_Property = CxvPropertyDeclaration.Register("spnRGibbsNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.RGIBBS_NPHAS"
		});

		public static readonly CxvPropertyDeclaration spnRGibbsMaxit_var1_Property = CxvPropertyDeclaration.Register("spnRGibbsMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.RGIBBS_MAXIT"
		});

		public static readonly CxvPropertyDeclaration lbtuRGibbsTol_var1_Property = CxvPropertyDeclaration.Register("lbtuRGibbsTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.RGIBBS_TOL"
		});

		public static readonly CxvPropertyDeclaration spnRadfMaxol_var1_Property = CxvPropertyDeclaration.Register("spnRadfMaxol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.MAXOL"
		});

		public static readonly CxvPropertyDeclaration cmbRadfAlgor_var1_Multimap_Property = CxvPropertyDeclaration.Register("cmbRadfAlgor_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ComboBox4_var1",
					DataPath = "@main.Model-Option.Input.ALGORITHM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard",
					Prompt = ApwnComboPromptResource.setup_model_option_algorithm_standard_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox4_var1",
							Value = "STANDARD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Sum-Rates",
					Prompt = ApwnComboPromptResource.setup_model_option_algorithm_sum_rates_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox4_var1",
							Value = "SUM-RATES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Nonideal",
					Prompt = ApwnComboPromptResource.setup_model_option_algorithm_nonideal_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox4_var1",
							Value = "NONIDEAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Newton",
					Prompt = ApwnComboPromptResource.setup_model_option_algorithm_newton_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox4_var1",
							Value = "NEWTON"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cmbDamping_var1_Property = CxvPropertyDeclaration.Register("cmbDamping_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Model-Option.Input.DAMPING",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration lbtuRadfTol_var1_Property = CxvPropertyDeclaration.Register("lbtuRadfTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.TOLOL"
		});

		public static readonly CxvPropertyDeclaration lbtuRadffmin_var1_Property = CxvPropertyDeclaration.Register("lbtuRadffmin_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.FMINFAC"
		});

		public static readonly CxvPropertyDeclaration lbtuRadfdtmax_var1_Property = CxvPropertyDeclaration.Register("lbtuRadfdtmax_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.DTMAX"
		});

		public static readonly CxvPropertyDeclaration ChkHydrPlots_var_Property = CxvPropertyDeclaration.Register("ChkHydrPlots_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.HYDR_PLOTS",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ChkTQCalc_var_Property = CxvPropertyDeclaration.Register("ChkTQCalc_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.CURVE",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ChkHPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkHPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.HDPPARMOP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ChkCPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkCPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.CDPPARMOP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ChkPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.DPPARMOPT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration lbtuPDCorr_var1_Property = CxvPropertyDeclaration.Register("lbtuPDCorr_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.Input.DPPARM"
		});

		public static readonly CxvPropertyDeclaration ChkMHPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkMHPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.MH_DPPARMOPT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ChkReaction_var_Property = CxvPropertyDeclaration.Register("ChkReaction_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Model-Option.Input.RPT_KINETICS",
			TrueValue = "KINETICS",
			FalseValue = "NOKINETICS",
			DefaultValue = true
		});

		public object expandar_compr => GetValue(expandar_compr_Property);

		public object expandar_mcompr => GetValue(expandar_mcompr_Property);

		public object expandar_rgibbs => GetValue(expandar_rgibbs_Property);

		public object expandar_radfrac => GetValue(expandar_radfrac_Property);

		public object expandar_heatx => GetValue(expandar_heatx_Property);

		public object expandar_heater => GetValue(expandar_heater_Property);

		public object expandar_Mheatx => GetValue(expandar_Mheatx_Property);

		public object cmbComprNPh_var1 => GetValue(cmbComprNPh_var1_Property);

		public object spnComprMaxit_var1 => GetValue(spnComprMaxit_var1_Property);

		public object lbtuComprTol_var1 => GetValue(lbtuComprTol_var1_Property);

		public object cmbMComprNPh_var1 => GetValue(cmbMComprNPh_var1_Property);

		public object cmbCoolNPh_var1 => GetValue(cmbCoolNPh_var1_Property);

		public object spnMComprMaxit_var1 => GetValue(spnMComprMaxit_var1_Property);

		public object lbtuMComprTol_var1 => GetValue(lbtuMComprTol_var1_Property);

		public object spnRGibbsNPh_var1 => GetValue(spnRGibbsNPh_var1_Property);

		public object spnRGibbsMaxit_var1 => GetValue(spnRGibbsMaxit_var1_Property);

		public object lbtuRGibbsTol_var1 => GetValue(lbtuRGibbsTol_var1_Property);

		public object spnRadfMaxol_var1 => GetValue(spnRadfMaxol_var1_Property);

		public object cmbRadfAlgor_var1 => GetValue(cmbRadfAlgor_var1_Multimap_Property);

		public object cmbDamping_var1 => GetValue(cmbDamping_var1_Property);

		public object lbtuRadfTol_var1 => GetValue(lbtuRadfTol_var1_Property);

		public object lbtuRadffmin_var1 => GetValue(lbtuRadffmin_var1_Property);

		public object lbtuRadfdtmax_var1 => GetValue(lbtuRadfdtmax_var1_Property);

		public object ChkHydrPlots_var => GetValue(ChkHydrPlots_var_Property);

		public object ChkTQCalc_var => GetValue(ChkTQCalc_var_Property);

		public object ChkHPDCorr_var => GetValue(ChkHPDCorr_var_Property);

		public object ChkCPDCorr_var => GetValue(ChkCPDCorr_var_Property);

		public object ChkPDCorr_var => GetValue(ChkPDCorr_var_Property);

		public object lbtuPDCorr_var1 => GetValue(lbtuPDCorr_var1_Property);

		public object ChkMHPDCorr_var => GetValue(ChkMHPDCorr_var_Property);

		public object ChkReaction_var => GetValue(ChkReaction_var_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_ModOpt")]
	public class MMSetup_Simopt_ModOpt : MMTabPage, IComponentConnector
	{
		internal MMExpander Compr;

		internal MMLabel cmbComprNPh_label;

		internal MMComboEdit cmbComprNPh;

		internal MMLabel spnComprMaxit_label;

		internal MMSpinBox spnComprMaxit;

		internal MMLabel lbtuComprTol_label;

		internal MMVariableEdit lbtuComprTol;

		internal MMExpander MCompr;

		internal MMLabel cmbMComprNPh_label;

		internal MMComboEdit cmbMComprNPh;

		internal MMLabel cmbCoolNPh_label;

		internal MMComboEdit cmbCoolNPh;

		internal MMLabel spnMComprMaxit_label;

		internal MMSpinBox spnMComprMaxit;

		internal MMLabel lbtuMComprTol_label;

		internal MMVariableEdit lbtuMComprTol;

		internal MMExpander RGibbs;

		internal MMLabel spnRGibbsNPh_label;

		internal MMSpinBox spnRGibbsNPh;

		internal MMLabel spnRGibbsMaxit_label;

		internal MMSpinBox spnRGibbsMaxit;

		internal MMLabel lbtuRGibbsTol_label;

		internal MMVariableEdit lbtuRGibbsTol;

		internal MMExpander Radfrac;

		internal MMLabel spnRadfMaxol_label;

		internal MMSpinBox spnRadfMaxol;

		internal MMLabel cmbRadfAlgor_label;

		internal MMComboEdit cmbRadfAlgor;

		internal MMLabel cmbRadfDamp_label;

		internal MMComboEdit cmbRadfDamp;

		internal MMLabel lbtuRadfTol_label;

		internal MMVariableEdit lbtuRadfTol;

		internal MMLabel lbtuRadffmin_label;

		internal MMVariableEdit lbtuRadffmin;

		internal MMLabel lbtuRadfdtmax_label;

		internal MMVariableEdit lbtuRadfdtmax;

		internal MMCheckBox ChkHydrPlots;

		internal MMExpander Heatx;

		internal MMCheckBox ChkTQCalc;

		internal MMCheckBox ChkHPDCorr;

		internal MMCheckBox ChkCPDCorr;

		internal MMExpander Heater;

		internal MMCheckBox ChkPDCorr;

		internal MMExpander MHeatx;

		internal MMCheckBox ChkMHPDCorr;

		internal MMExpander reactionExpander;

		internal MMCheckBox ChkReaction;

		private bool _contentLoaded;

		public MMSetup_Simopt_ModOpt()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_ModOpt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_modopt.xaml", UriKind.Relative);
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
				Compr = (MMExpander)target;
				break;
			case 2:
				cmbComprNPh_label = (MMLabel)target;
				break;
			case 3:
				cmbComprNPh = (MMComboEdit)target;
				break;
			case 4:
				spnComprMaxit_label = (MMLabel)target;
				break;
			case 5:
				spnComprMaxit = (MMSpinBox)target;
				break;
			case 6:
				lbtuComprTol_label = (MMLabel)target;
				break;
			case 7:
				lbtuComprTol = (MMVariableEdit)target;
				break;
			case 8:
				MCompr = (MMExpander)target;
				break;
			case 9:
				cmbMComprNPh_label = (MMLabel)target;
				break;
			case 10:
				cmbMComprNPh = (MMComboEdit)target;
				break;
			case 11:
				cmbCoolNPh_label = (MMLabel)target;
				break;
			case 12:
				cmbCoolNPh = (MMComboEdit)target;
				break;
			case 13:
				spnMComprMaxit_label = (MMLabel)target;
				break;
			case 14:
				spnMComprMaxit = (MMSpinBox)target;
				break;
			case 15:
				lbtuMComprTol_label = (MMLabel)target;
				break;
			case 16:
				lbtuMComprTol = (MMVariableEdit)target;
				break;
			case 17:
				RGibbs = (MMExpander)target;
				break;
			case 18:
				spnRGibbsNPh_label = (MMLabel)target;
				break;
			case 19:
				spnRGibbsNPh = (MMSpinBox)target;
				break;
			case 20:
				spnRGibbsMaxit_label = (MMLabel)target;
				break;
			case 21:
				spnRGibbsMaxit = (MMSpinBox)target;
				break;
			case 22:
				lbtuRGibbsTol_label = (MMLabel)target;
				break;
			case 23:
				lbtuRGibbsTol = (MMVariableEdit)target;
				break;
			case 24:
				Radfrac = (MMExpander)target;
				break;
			case 25:
				spnRadfMaxol_label = (MMLabel)target;
				break;
			case 26:
				spnRadfMaxol = (MMSpinBox)target;
				break;
			case 27:
				cmbRadfAlgor_label = (MMLabel)target;
				break;
			case 28:
				cmbRadfAlgor = (MMComboEdit)target;
				break;
			case 29:
				cmbRadfDamp_label = (MMLabel)target;
				break;
			case 30:
				cmbRadfDamp = (MMComboEdit)target;
				break;
			case 31:
				lbtuRadfTol_label = (MMLabel)target;
				break;
			case 32:
				lbtuRadfTol = (MMVariableEdit)target;
				break;
			case 33:
				lbtuRadffmin_label = (MMLabel)target;
				break;
			case 34:
				lbtuRadffmin = (MMVariableEdit)target;
				break;
			case 35:
				lbtuRadfdtmax_label = (MMLabel)target;
				break;
			case 36:
				lbtuRadfdtmax = (MMVariableEdit)target;
				break;
			case 37:
				ChkHydrPlots = (MMCheckBox)target;
				break;
			case 38:
				Heatx = (MMExpander)target;
				break;
			case 39:
				ChkTQCalc = (MMCheckBox)target;
				break;
			case 40:
				ChkHPDCorr = (MMCheckBox)target;
				break;
			case 41:
				ChkCPDCorr = (MMCheckBox)target;
				break;
			case 42:
				Heater = (MMExpander)target;
				break;
			case 43:
				ChkPDCorr = (MMCheckBox)target;
				break;
			case 44:
				MHeatx = (MMExpander)target;
				break;
			case 45:
				ChkMHPDCorr = (MMCheckBox)target;
				break;
			case 46:
				reactionExpander = (MMExpander)target;
				break;
			case 47:
				ChkReaction = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Stratt_Characterization_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboType_var2_Property = CxvPropertyDeclaration.Register("cboType_var2", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvParameterProperty
		{
			Parameter = "id"
		});

		public static readonly CxvPropertyDeclaration cboType_var1_Property = CxvPropertyDeclaration.Register("cboType_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Substreams.Input.TYPE",
			SelectedItemBinding = "cboType_var2.Value",
			CreateNewInputMask = 3
		});

		public static readonly CxvPropertyDeclaration chkPSDSpec_var1_Property = CxvPropertyDeclaration.Register("chkPSDSpec_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Substreams.Input.SELECT_PSD.@id",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration ComboBoxSclass_var1_Property = CxvPropertyDeclaration.Register("ComboBoxSclass_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.@parent.@parent.Global.Input.SCLASS"
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.@parent.@parent.@parent.Components.Moisture-Comps.Input.COMP",
			AllowSort = false
		});

		public object cboType_var2 => GetValue(cboType_var2_Property);

		public object cboType_var1 => GetValue(cboType_var1_Property);

		public object chkPSDSpec_var1 => GetValue(chkPSDSpec_var1_Property);

		public object ComboBoxSclass_var1 => GetValue(ComboBoxSclass_var1_Property);

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);
	}
	[ProgId("MMSetup_Stratt_Characterization")]
	public class MMSetup_Stratt_Characterization : MMTabPage, IComponentConnector
	{
		internal MMLabel ComboBoxSclass_label;

		internal MMComboEdit ComboBoxSclass;

		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMSetup_Stratt_Characterization()
		{
			base.ViewModelType = typeof(MMSetup_Stratt_Characterization_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_stratt_characterization.xaml", UriKind.Relative);
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
				ComboBoxSclass_label = (MMLabel)target;
				break;
			case 2:
				ComboBoxSclass = (MMComboEdit)target;
				break;
			case 3:
				MMListPicker1 = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Stratt_List1D_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y",
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration txtType_var1_Property = CxvPropertyDeclaration.Register("txtType_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y.Input.TYPE",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration txtIncrements_var1_Property = CxvPropertyDeclaration.Register("txtIncrements_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y.Input.INTERVALS",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration txtStart_var1_Property = CxvPropertyDeclaration.Register("txtStart_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.LOWER",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration txtEnd_var1_Property = CxvPropertyDeclaration.Register("txtEnd_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.UPPER",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration txtUnits_var1_Property = CxvPropertyDeclaration.Register("txtUnits_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.PARTICLESIZE",
				ExtraDataPaths = { "@main.@y.Input.PARTICLESIZ2" },
				IsReadOnly = true,
				IsCalculated = false
			});

			public static CxvPropertyDeclaration cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "status",
				IsReadOnly = true,
				IsCalculated = false
			});

			public object txtName_var1 => GetValue(txtName_var1_Property);

			public object txtType_var1
			{
				get
				{
					CxvVariableData cxvVariableData = GetValue(txtType_var1_Property) as CxvVariableData;
					if (cxvVariableData != null && cxvVariableData.Value != null && !string.IsNullOrEmpty(cxvVariableData.Value.ToString()))
					{
						string localizedColType = GetLocalizedColType("psdtype_" + cxvVariableData.Value.ToString(), cxvVariableData.Value.ToString());
						return new CxvManualVariableData
						{
							Value = localizedColType,
							IsReadOnly = true,
							IsCalculated = false
						};
					}
					return cxvVariableData;
				}
			}

			public object txtIncrements_var1 => GetValue(txtIncrements_var1_Property);

			public object txtStart_var1 => GetValue(txtStart_var1_Property);

			public object txtEnd_var1 => GetValue(txtEnd_var1_Property);

			public object txtUnits_var1 => GetValue(txtUnits_var1_Property);

			public object cboStatus_Status => GetValue(cboStatus_Status_Property);

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
			}

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "txtType_var1" && subPropertyName == "Value")
				{
					OnPropertyChanged("txtType_var1");
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}

			private string GetLocalizedColType(string key, string defaultOptionValue)
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
		}

		[CompilerGenerated]
		private sealed class SelectedIdsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string currentId;

			private int initialThreadId;

			public MMSetup_Stratt_List1D_ViewModel owner;

			private IList gridData;

			private IEnumerator<int> rowIndexes;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			[DebuggerHidden]
			public SelectedIdsEnumerator(int state)
			{
				this.state = state;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = state;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeRowIndexes();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{  bool completedNormally = false;
				try
				{
					int num = state;
					MMSetup_Stratt_List1D_ViewModel mMSetup_Stratt_List1D_ViewModel = owner;
					switch (num)
					{
					default:
						completedNormally = true; return false;
					case 0:
						state = -1;
						gridData = mMSetup_Stratt_List1D_ViewModel.grdChild_GridData as IList;
						rowIndexes = mMSetup_Stratt_List1D_ViewModel.SelectedRowIndexes.GetEnumerator();
						state = -3;
						break;
					case 1:
						state = -3;
						break;
					}
					if (rowIndexes.MoveNext())
					{
						int current = rowIndexes.Current;
						grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = gridData[current] as grdChild_GridData_ItemTemplate;
						currentId = grdChild_GridData_ItemTemplate.GetId();
						state = 1;
						completedNormally = true; return true;
					}
					DisposeRowIndexes();
					rowIndexes = null;
					completedNormally = true; return false;
				}
				finally
				{
					// Original fault handler runs only when MoveNext leaves by exception.
					if (!completedNormally) ((IDisposable)this).Dispose();

				}
			}







			private void DisposeRowIndexes()
			{
				state = -1;
				if (rowIndexes != null)
				{
					rowIndexes.Dispose();
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
				SelectedIdsEnumerator result;
				if (state == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					state = 0;
					result = this;
				}
				else
				{
					result = new SelectedIdsEnumerator(0)
					{
						owner = owner
					};
				}
				return result;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private ICommand _grid_RowDoubleClickCommand;

		private ICommand _cmdExport_Command;

		public static CxvPropertyDeclaration cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdAdd_Command;

		public static CxvPropertyDeclaration cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "InsertChild"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdDelete_Command;

		public static CxvPropertyDeclaration cmdDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDeleteCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "DeleteChild"
				}
			}
		});

		private DelegateCommand<object> _cmdCopy_Command;

		private ICommand _cmdRename_Command;

		public static CxvPropertyDeclaration cmdRenameCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRenameCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Value = 1
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "RenameChild"
				}
			}
		});

		private ICommand _cmdHide_Command;

		public static CxvPropertyDeclaration cmdHideCanExecuteProperty = CxvPropertyDeclaration.Register("cmdHideCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "HideChild"
				}
			}
		});

		private ICommand _cmdReveal_Command;

		public static CxvPropertyDeclaration cmdRevealCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRevealCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "RevealChild"
		});

		private ICommand _cmdPaste_Command;

		public static CxvPropertyDeclaration cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Equal,
			PropertyPath = "CanPaste",
			Value = true
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main",
				UseChildId = true,
				ProxyRow = false,
				Name = "y"
			},
			AllowCollectionChange = false
		});

		public ICommand grid_RowDoubleClickCommand
		{
			get
			{
				if (_grid_RowDoubleClickCommand == null)
				{
					_grid_RowDoubleClickCommand = new CxvDelegateCommand<object>(grid_RowDoubleClickCommandExecute);
				}
				return _grid_RowDoubleClickCommand;
			}
		}

		public ICommand cmdExport_Command
		{
			get
			{
				if (_cmdExport_Command == null)
				{
					_cmdExport_Command = new CxvDelegateCommand<object>(cmdExport_CommandExecute, this, cmdExportCanExecuteProperty.Name + ".Value");
				}
				return _cmdExport_Command;
			}
		}

		public CxvLogicalPropertyData cmdExportCanExecute => GetValue(cmdExportCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdAdd_Command
		{
			get
			{
				if (_cmdAdd_Command == null)
				{
					_cmdAdd_Command = new CxvDelegateCommand<object>(cmdAdd_CommandExecute, this, cmdAddCanExecuteProperty.Name + ".Value");
				}
				return _cmdAdd_Command;
			}
		}

		public CxvLogicalPropertyData cmdAddCanExecute => GetValue(cmdAddCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEditCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEditCanExecute => GetValue(cmdEditCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new CxvDelegateCommand<object>(cmdDelete_CommandExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public CxvLogicalPropertyData cmdDeleteCanExecute => GetValue(cmdDeleteCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdCopy_Command
		{
			get
			{
				if (_cmdCopy_Command == null)
				{
					_cmdCopy_Command = new DelegateCommand<object>(cmdCopy_CommandExecute, cmdCopy_CanExecute);
				}
				return _cmdCopy_Command;
			}
		}

		public ICommand cmdRename_Command
		{
			get
			{
				if (_cmdRename_Command == null)
				{
					_cmdRename_Command = new CxvDelegateCommand<object>(cmdRename_CommandExecute, this, cmdRenameCanExecuteProperty.Name + ".Value");
				}
				return _cmdRename_Command;
			}
		}

		public CxvLogicalPropertyData cmdRenameCanExecute => GetValue(cmdRenameCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdHide_Command
		{
			get
			{
				if (_cmdHide_Command == null)
				{
					_cmdHide_Command = new CxvDelegateCommand<object>(cmdHide_CommandExecute, this, cmdHideCanExecuteProperty.Name + ".Value");
				}
				return _cmdHide_Command;
			}
		}

		public CxvLogicalPropertyData cmdHideCanExecute => GetValue(cmdHideCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdReveal_Command
		{
			get
			{
				if (_cmdReveal_Command == null)
				{
					_cmdReveal_Command = new CxvDelegateCommand<object>(cmdReveal_CommandExecute, this, cmdRevealCanExecuteProperty.Name + ".Value");
				}
				return _cmdReveal_Command;
			}
		}

		public CxvLogicalPropertyData cmdRevealCanExecute => GetValue(cmdRevealCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdPaste_Command
		{
			get
			{
				if (_cmdPaste_Command == null)
				{
					_cmdPaste_Command = new CxvDelegateCommand<object>(cmdPaste_CommandExecute, this, cmdPaste_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdPaste_Command;
			}
		}

		public bool CanPaste
		{
			get
			{
				if (!ClipboardWrapper.ContainsData("Aspen Plus Selection"))
				{
					return false;
				}
				if (ClipboardWrapper.ContainsData("Aspen Plus Selection Type"))
				{
					IDataObject dataObject = ClipboardWrapper.GetDataObject();
					if (dataObject != null && dataObject.GetData("Aspen Plus Selection Type", autoConvert: false) is MemoryStream stream)
					{
						string text = new StreamReader(stream).ReadToEnd();
						string path = ExpandDataPath("@main");
						try
						{
							return CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "CanPaste:" + text)).CanInvoke;
						}
						catch (Exception)
						{
						}
					}
				}
				return true;
			}
		}

		public CxvLogicalPropertyData cmdPaste_CommandCanExecute => GetValue(cmdPaste_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public int AllSelectedRecordsCount
		{
			get
			{
				return _allSelectedRecordsCount;
			}
			set
			{
				if (value != _allSelectedRecordsCount)
				{
					_allSelectedRecordsCount = value;
					OnAllSelectedRecordsCountChanged();
				}
			}
		}

		public ObservableCollection<int> SelectedRowIndexes
		{
			get
			{
				return _SelectedRowIndexes;
			}
			set
			{
				_SelectedRowIndexes = value;
			}
		}

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		public event EventHandler CanPasteChanged;

		public event EventHandler AllSelectedRecordsCountChanged;

		private void cmdExport_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
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

		private void cmdAdd_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			string newChildId = null;
			bool? flag = ShowAddChildDialog(parentPath, out newChildId);
			if (flag.HasValue && flag.Value)
			{
				string path = ".!" + newChildId;
				GoToNodeEx(path);
			}
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
			using IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				string path = ".!" + current;
				GoToNodeEx(path);
			}
		}

		private void cmdDelete_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			if (parameter != null)
			{
				collection.Add(parameter.ToString());
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

		private bool cmdCopy_CanExecute(object parameter)
		{
			return false;
		}

		private void cmdCopy_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			CopyChildren(parentPath, collection);
			OnCanPasteChanged();
		}

		private void cmdRename_CommandExecute(object parameter)
		{
			int allSelectedRecordsCount = AllSelectedRecordsCount;
			if (allSelectedRecordsCount != 0 && allSelectedRecordsCount <= 1)
			{
				string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
				string childId = GetSelectedIds().First();
				ShowRenameChildDialog(parentPath, ref childId);
			}
		}

		private void cmdHide_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			HideNodeChildren(parentPath, collection);
		}

		private void cmdReveal_CommandExecute(object parameter)
		{
			string path = CxsConverter.ValueToString(ResolveParameter("main", null));
			ShowRevealNodeDialog(path);
		}

		private void OnCanPasteChanged()
		{
			if (this.CanPasteChanged != null)
			{
				this.CanPasteChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("CanPaste");
		}

		private void cmdPaste_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DoPaste(parentPath);
		}

		private void grid_RowDoubleClickCommandExecute(object parameter)
		{
			IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string path = ".!" + enumerator.Current;
				GoToNodeEx(path);
			}
		}

		private void OnAllSelectedRecordsCountChanged()
		{
			if (this.AllSelectedRecordsCountChanged != null)
			{
				this.AllSelectedRecordsCountChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("AllSelectedRecordsCount");
		}

		[IteratorStateMachine(typeof(SelectedIdsEnumerator))]
		private IEnumerable<string> GetSelectedIds()
		{
			return new SelectedIdsEnumerator(-2)
			{
				owner = this
			};
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
		}

		private void GoToNodeEx(string path)
		{
			string text = ExpandDataPath("@main");
			if (text.EndsWith("Design-Spec"))
			{
				GoToNode("Simulation!Flowsheeting Options.Design Spec." + path.Substring(2));
			}
			else if (text.EndsWith("Model Analysis Tools.Sensitivity"))
			{
				GoToNode("Simulation!Model Analysis Tools.Sensitivity." + path.Substring(2));
			}
			else if (text.EndsWith("Data-Set"))
			{
				GoToNode("Simulation!Model Analysis Tools.Data Fit.Data Set." + path.Substring(2));
			}
			else if (text.EndsWith("Generation"))
			{
				GoToNode("Properties!Components.Petro Characterization.Generation." + path.Substring(2));
			}
			else
			{
				GoToNode(path);
			}
		}

		public void SetSelectedRowFromScript(int row)
		{
			if (SelectedRowIndexes == null)
			{
				SelectedRowIndexes = new ObservableCollection<int>();
			}
			SelectedRowIndexes.Clear();
			SelectedRowIndexes.Add(row);
			AllSelectedRecordsCount = 1;
		}
	}
	[ProgId("MMSetup.MMSetup_Stratt_List1D")]
	public class MMSetup_Stratt_List1D : MMTabPage, IComponentConnector
	{
		internal MMFlatButton cmdAdd;

		internal MMFlatButton cmdCopy;

		internal MMFlatButton cmdPaste;

		internal MMFlatButton cmdExport;

		internal MMFlatButton cmdEdit;

		internal MMScrollArea grdChild;

		private bool _contentLoaded;

		public MMSetup_Stratt_List1D()
		{
			base.ViewModelType = typeof(MMSetup_Stratt_List1D_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_stratt_list1d.xaml", UriKind.Relative);
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
				cmdAdd = (MMFlatButton)target;
				break;
			case 2:
				cmdCopy = (MMFlatButton)target;
				break;
			case 3:
				cmdPaste = (MMFlatButton)target;
				break;
			case 4:
				cmdExport = (MMFlatButton)target;
				break;
			case 5:
				cmdEdit = (MMFlatButton)target;
				break;
			case 6:
				grdChild = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Attr_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration ccmain_Property = CxvPropertyDeclaration.Register("ccmain", typeof(MMSetup_Attr_ViewModel), new CxvParameterProperty
		{
			Parameter = "ccmain"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Attr_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PSD" },
			EnteredDataPaths = { "@ATTRE" }
		});

		public static readonly CxvPropertyDeclaration PSD_Property = CxvPropertyDeclaration.Register("PSD", typeof(MMSetup_Attr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MN1"
		});

		public static readonly CxvPropertyDeclaration ATTRE_Property = CxvPropertyDeclaration.Register("ATTRE", typeof(MMSetup_Attr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ATTRE"
		});

		public object ccmain => GetValue(ccmain_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object PSD => GetValue(PSD_Property);

		public object ATTRE => GetValue(ATTRE_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_Attr")]
	public class MMSetup_Attr : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_Attr()
		{
			base.ViewModelType = typeof(MMSetup_Attr_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_attr.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_CostOp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Currency.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Currency.CC Nodes.ENTN"
		});

		public static readonly CxvPropertyDeclaration entcostop_Property = CxvPropertyDeclaration.Register("entcostop", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTCOSTOP"
		});

		public static readonly CxvPropertyDeclaration costop_Property = CxvPropertyDeclaration.Register("costop", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.COSTOP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_CostOp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@costop" },
			EnteredDataPaths = { "@entcostop" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_CostOp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" },
			EnteredDataPaths = { "@entn" }
		});

		public object spec => GetValue(spec_Property);

		public object entn => GetValue(entn_Property);

		public object entcostop => GetValue(entcostop_Property);

		public object costop => GetValue(costop_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
				ResolveUpdateParameter("extraComments_path", "Currency.Comments");
				ResolveUpdateParameter("extraDescription_path", "Currency.Input.DESCRIPTION");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_CostOp")]
	public class MMSetup_CostOp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_CostOp()
		{
			base.ViewModelType = typeof(MMSetup_CostOp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_costop.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_CostOp_CostOpt_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdTempBrowse_Command;

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PLANT_LIFE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STARTUP"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.START_DAY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.START_MONTH",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.START_YEAR",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration txtArch_var1_Property = CxvPropertyDeclaration.Register("txtArch_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.TEMPLATE"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.SCENARIO"
		});

		public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.DESCRIPTION",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		private string REG_APSEN_ICARUS_PRODUCTS = System.IO.Path.Combine("SOFTWARE", "AspenTech", "Aspen Icarus Products");

		private string ASPEN_ICARUS_IPE = "IPE";

		public ICommand cmdTempBrowse_Command
		{
			get
			{
				if (_cmdTempBrowse_Command == null)
				{
					_cmdTempBrowse_Command = new CxvDelegateCommand<object>(cmdTempBrowse_CommandExecute);
				}
				return _cmdTempBrowse_Command;
			}
		}

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

		public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

		public object txtArch_var1 => GetValue(txtArch_var1_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

		private void cmdTempBrowse_CommandExecute(object parameter)
		{
			string value = BrowseEconTemplate();
			if (!string.IsNullOrEmpty(value))
			{
				ExpandDataPathAndSet("@main.Sim-Options.Input.TEMPLATE", "value", value);
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				FinishInit();
			}
			base.OnUpdateData();
		}

		private string GetEconTemplate()
		{
			return CxsConverter.ValueToString(ExpandDataPathAndGet("Top.appModelV8.Settings.econtemplate", "value"));
		}

		private string GetIcarusCurrentVersion()
		{
			int num = -1;
			string rEG_APSEN_ICARUS_PRODUCTS = REG_APSEN_ICARUS_PRODUCTS;
			RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(rEG_APSEN_ICARUS_PRODUCTS, writable: false);
			if (registryKey != null)
			{
				string[] subKeyNames = registryKey.GetSubKeyNames();
				if (subKeyNames != null)
				{
					double num2 = 0.0;
					for (int i = 0; i < subKeyNames.Length; i++)
					{
						try
						{
							double num3 = Convert.ToDouble(subKeyNames[i], CultureInfo.InvariantCulture);
							if (num3 > num2)
							{
								num2 = num3;
								num = i;
							}
						}
						catch (Exception)
						{
						}
					}
				}
				registryKey.Close();
				if (num != -1)
				{
					return subKeyNames[num];
				}
			}
			return null;
		}

		private string BrowseEconTemplate()
		{
			string text = null;
			string icarusCurrentVersion = GetIcarusCurrentVersion();
			if (icarusCurrentVersion != null)
			{
				string name = System.IO.Path.Combine(REG_APSEN_ICARUS_PRODUCTS, icarusCurrentVersion, ASPEN_ICARUS_IPE + " " + icarusCurrentVersion, "InstallDir");
				RegistryKey registryKey = Registry.LocalMachine.OpenSubKey(name, writable: false);
				if (registryKey != null)
				{
					text = (string)registryKey.GetValue("UserTemplatesDir");
					registryKey.Close();
				}
			}
			if (text == null)
			{
				ShowMMMessageBox(new ShowMMMessageBoxEventArgs
				{
					Message = ApwnResources.BadEcon,
					Title = ApwnResources.AspenPlus,
					MsgBoxButton = 0,
					MsgBoxImage = 0,
					DialogResult = 1
				});
				return "";
			}
			string filter = "Templates (*.izt)|*.izt";
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.RestoreDirectory = true;
			openFileDialog.Title = WpfFormsResources.MMSetup_CostOp_CostOpt_Display1;
			openFileDialog.Filter = filter;
			openFileDialog.RestoreDirectory = true;
			if (!string.IsNullOrEmpty(text))
			{
				openFileDialog.InitialDirectory = text;
			}
			if (openFileDialog.ShowDialog().Value)
			{
				return openFileDialog.FileName;
			}
			return null;
		}

		private void FinishInit()
		{
			if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Sim-Options.Input.SCENARIO", "value"))))
			{
				ExpandDataPathAndSet("@main.Sim-Options.Input.SCENARIO", "value", "Scenario1");
			}
			if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Sim-Options.Input.TEMPLATE", "value"))))
			{
				string econTemplate = GetEconTemplate();
				if (!string.IsNullOrEmpty(econTemplate))
				{
					ExpandDataPathAndSet("@main.Sim-Options.Input.TEMPLATE", "value", econTemplate);
				}
			}
		}
	}
	[ProgId("MMSetup.MMSetup_CostOp_CostOpt")]
	public class MMSetup_CostOp_CostOpt : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmProOption;

		internal MMLabel MMLabel2;

		internal MMTextEdit txtArch;

		internal MMCmdButton cmdTempBrowse;

		internal MMLabel MMLabel1;

		internal MMTextEdit MMTextBox1;

		internal MMLabel MMLabel3;

		internal MMTextEdit MMTextBox2;

		internal MMGroupBox frmInvOption;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLabel4;

		internal MMComboEdit MMComboBox1;

		internal MMComboEdit MMComboBox2;

		internal MMComboEdit MMComboBox3;

		private bool _contentLoaded;

		public MMSetup_CostOp_CostOpt()
		{
			base.ViewModelType = typeof(MMSetup_CostOp_CostOpt_ViewModel);
			InitializeComponent();
		}

		public void DisplayCostingPrompt(object sender, RoutedEventArgs e)
		{
			MMTextEdit mMTextEdit = sender as MMTextEdit;
			UIElement uIElement = sender as UIElement;
			if ((string.IsNullOrEmpty(mMTextEdit.Text) || mMTextEdit.Text == " ") && !uIElement.IsKeyboardFocusWithin)
			{
				string mMSetup_CostOp_Curren_MMFPrompt = ApwnResources.MMSetup_CostOp_Curren_MMFPrompt1;
				string aspenPlus = ApwnResources.AspenPlus;
				MessageBoxButton button = MessageBoxButton.OK;
				MessageBoxImage icon = MessageBoxImage.Exclamation;
				MessageBox.Show(mMSetup_CostOp_Curren_MMFPrompt, aspenPlus, button, icon);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_costop_costopt.xaml", UriKind.Relative);
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
				frmProOption = (MMGroupBox)target;
				break;
			case 2:
				MMLabel2 = (MMLabel)target;
				break;
			case 3:
				txtArch = (MMTextEdit)target;
				txtArch.LostFocus += DisplayCostingPrompt;
				break;
			case 4:
				cmdTempBrowse = (MMCmdButton)target;
				break;
			case 5:
				MMLabel1 = (MMLabel)target;
				break;
			case 6:
				MMTextBox1 = (MMTextEdit)target;
				break;
			case 7:
				MMLabel3 = (MMLabel)target;
				break;
			case 8:
				MMTextBox2 = (MMTextEdit)target;
				break;
			case 9:
				frmInvOption = (MMGroupBox)target;
				break;
			case 10:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 11:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 12:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 13:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 14:
				MMLabel4 = (MMLabel)target;
				break;
			case 15:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 16:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox3 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_CostOp_Curren_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Currency.Input.FACTOR.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Currency.Input.FACTOR.@y"
			});

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSetup_CostOp_Curren_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Currency.Input.FACTOR",
				UseChildId = false,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMSetup.MMSetup_CostOp_Curren")]
	public class MMSetup_CostOp_Curren : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMSetup_CostOp_Curren()
		{
			base.ViewModelType = typeof(MMSetup_CostOp_Curren_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_costop_curren.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 2:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_CusUom_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_CusUom_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Custom-Uom.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_CusUom_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Custom-Uom.CC Nodes.ENTN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_CusUom_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" },
			EnteredDataPaths = { "@entn" }
		});

		public object spec => GetValue(spec_Property);

		public object entn => GetValue(entn_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
				ResolveUpdateParameter("extraComments_path", "Custom-Uom.Comments");
				ResolveUpdateParameter("extraDescription_path", "Custom-Uom.Input.DESCRIPTION");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_CusUom")]
	public class MMSetup_CusUom : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_CusUom()
		{
			base.ViewModelType = typeof(MMSetup_CusUom_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_cusuom.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_CusUom_Setup_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Custom-Uom.Input.BASE_UNIT.@y",
				Sorted = true,
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.Custom-Uom.CC Nodes.UNIT1.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Custom-Uom.Input.PHYS_QTY.@y",
				DisplayedCase = CxsDisplayedCase.Lowercase,
				Sorted = true
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Custom-Uom.Input.CUSTOM_UNIT.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.Custom-Uom.CC Nodes.UNIT1.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Custom-Uom.Input.OFFSET.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.Custom-Uom.CC Nodes.UNIT2.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Custom-Uom.Input.MULTIPLIER.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.Custom-Uom.CC Nodes.UNIT2.@y"
				}
			});

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSetup_CusUom_Setup_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Custom-Uom.Input.PHYS_QTY",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			try
			{
				if (base.UnityContainer != null)
				{
					((CompositePresentationEvent<CustomUnitsChangedEventArgs>)(object)base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CustomUnitsChangedEvent>()).Publish(new CustomUnitsChangedEventArgs());
				}
			}
			catch (Exception)
			{
			}
		}
	}
	[ProgId("MMSetup.MMSetup_CusUom_Setup")]
	public class MMSetup_CusUom_Setup : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMLabel MMLabel3;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMSetup_CusUom_Setup()
		{
			base.ViewModelType = typeof(MMSetup_CusUom_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_cusuom_setup.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 2:
				MMLabel3 = (MMLabel)target;
				break;
			case 3:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sreportno_Property = CxvPropertyDeclaration.Register("sreportno", typeof(MMSetup_Report_ViewModel), new CxvParameterProperty
		{
			Parameter = "sreportno"
		});

		public static readonly CxvPropertyDeclaration entglob_Property = CxvPropertyDeclaration.Register("entglob", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Report.CC Nodes.ENTGLOB"
		});

		public static readonly CxvPropertyDeclaration entflows_Property = CxvPropertyDeclaration.Register("entflows", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.CC Nodes.ENTFLOWS"
		});

		public static readonly CxvPropertyDeclaration entblock_Property = CxvPropertyDeclaration.Register("entblock", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.CC Nodes.ENTBLOCK"
		});

		public static readonly CxvPropertyDeclaration entstrm_Property = CxvPropertyDeclaration.Register("entstrm", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.ENTSTRM"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entada_Property = CxvPropertyDeclaration.Register("entada", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.ADA-Report.CC Nodes.ENTADA"
		});

		public static readonly CxvPropertyDeclaration flow_Property = CxvPropertyDeclaration.Register("flow", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.FLOW"
		});

		public static readonly CxvPropertyDeclaration prop_Property = CxvPropertyDeclaration.Register("prop", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.PROP"
		});

		public static readonly CxvPropertyDeclaration ada_Property = CxvPropertyDeclaration.Register("ada", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ADA"
		});

		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Batch-Operation.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration block_Property = CxvPropertyDeclaration.Register("block", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.CC Nodes.BLOCK"
		});

		public static readonly CxvPropertyDeclaration spec2_Property = CxvPropertyDeclaration.Register("spec2", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Stream-Names.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration entstrname_Property = CxvPropertyDeclaration.Register("entstrname", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Stream-Names.CC Nodes.ENTSTREAM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entglob" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@flow" },
			EnteredDataPaths = { "@entflows" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@block" },
			AccessibleDataPaths = { "@flow" },
			EnteredDataPaths = { "@entblock" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec", "@spec2" },
			AccessibleDataPaths = { "@flow" },
			EnteredDataPaths = { "@entstrm", "@entstrname" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@prop" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ada" },
			EnteredDataPaths = { "@entada" }
		});

		public object sreportno => GetValue(sreportno_Property);

		public object entglob => GetValue(entglob_Property);

		public object entflows => GetValue(entflows_Property);

		public object entblock => GetValue(entblock_Property);

		public object entstrm => GetValue(entstrm_Property);

		public object entprop => GetValue(entprop_Property);

		public object entada => GetValue(entada_Property);

		public object flow => GetValue(flow_Property);

		public object prop => GetValue(prop_Property);

		public object ada => GetValue(ada_Property);

		public object spec => GetValue(spec_Property);

		public object block => GetValue(block_Property);

		public object spec2 => GetValue(spec2_Property);

		public object entstrname => GetValue(entstrname_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);
	}
	[ProgId("MMSetup.MMSetup_Report")]
	public class MMSetup_Report : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMSetup_Report()
		{
			base.ViewModelType = typeof(MMSetup_Report_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report.xaml", UriKind.Relative);
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
	public class MMSetup_Report_ADA_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_ADA_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.ADA"
			}
		});

		public static readonly CxvPropertyDeclaration chkComps_var1_Property = CxvPropertyDeclaration.Register("chkComps_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.ADA-Report.Input.COMPS",
			TrueValue = "COMPS",
			FalseValue = "NOCOMPS",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkCurves_var1_Property = CxvPropertyDeclaration.Register("chkCurves_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.ADA-Report.Input.CURVES",
			TrueValue = "CURVES",
			FalseValue = "NOCURVES",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkParams_var1_Property = CxvPropertyDeclaration.Register("chkParams_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.ADA-Report.Input.PARAMS",
			TrueValue = "PARAMS",
			FalseValue = "NOPARAMS",
			DefaultValue = false
		});

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object chkComps_var1 => GetValue(chkComps_var1_Property);

		public object chkCurves_var1 => GetValue(chkCurves_var1_Property);

		public object chkParams_var1 => GetValue(chkParams_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Report_ADA")]
	public class MMSetup_Report_ADA : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkComps;

		internal MMCheckBox chkCurves;

		internal MMCheckBox chkParams;

		private bool _contentLoaded;

		public MMSetup_Report_ADA()
		{
			base.ViewModelType = typeof(MMSetup_Report_ADA_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_ada.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				chkComps = (MMCheckBox)target;
				break;
			case 3:
				chkCurves = (MMCheckBox)target;
				break;
			case 4:
				chkParams = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Attrib_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration chkStruct_struct_Property = CxvPropertyDeclaration.Register("chkStruct_struct", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.STRUCTURE",
			TrueValue = "STRUCTURE",
			FalseValue = "NOSTRUCTURE",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkAttrDesc_attrdesc_Property = CxvPropertyDeclaration.Register("chkAttrDesc_attrdesc", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.ATTR_DESC",
			TrueValue = "ATTR-DESC",
			FalseValue = "NOATTR-DESC",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkCompAttr_compattr_Property = CxvPropertyDeclaration.Register("chkCompAttr_compattr", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.COMP_ATTR",
			TrueValue = "COMP-ATTR",
			FalseValue = "NOCOMP-ATTR",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSubsAttr_subsattr_Property = CxvPropertyDeclaration.Register("chkSubsAttr_subsattr", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUBS_ATTR",
			TrueValue = "SUBS-ATTR",
			FalseValue = "NOSUBS-ATTR",
			DefaultValue = true
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object chkStruct_struct => GetValue(chkStruct_struct_Property);

		public object chkAttrDesc_attrdesc => GetValue(chkAttrDesc_attrdesc_Property);

		public object chkCompAttr_compattr => GetValue(chkCompAttr_compattr_Property);

		public object chkSubsAttr_subsattr => GetValue(chkSubsAttr_subsattr_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_Attrib")]
	public class MMSetup_Report_Attrib : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkCompAttr;

		internal MMCheckBox chkSubsAttr;

		internal MMCheckBox chkAttrDesc;

		internal MMCheckBox chkStruct;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_Attrib()
		{
			base.ViewModelType = typeof(MMSetup_Report_Attrib_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_attrib.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				chkCompAttr = (MMCheckBox)target;
				break;
			case 3:
				chkSubsAttr = (MMCheckBox)target;
				break;
			case 4:
				chkAttrDesc = (MMCheckBox)target;
				break;
			case 5:
				chkStruct = (MMCheckBox)target;
				break;
			case 6:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_BatchO_ViewModel : MMTabPageViewModel
	{
		public class SABatchO_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration spnNtrain_var1_Property = CxvPropertyDeclaration.Register("spnNtrain_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.NTRAIN.@y"
			});

			public static readonly CxvPropertyDeclaration txtOptime_var1_Property = CxvPropertyDeclaration.Register("txtOptime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.OP_TIME.@y"
			});

			public static readonly CxvPropertyDeclaration txtDownTime_var1_Property = CxvPropertyDeclaration.Register("txtDownTime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.DOWN_TIME.@y"
			});

			public static readonly CxvPropertyDeclaration txtCycleTime_var1_Property = CxvPropertyDeclaration.Register("txtCycleTime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME.@y"
			});

			public static readonly CxvPropertyDeclaration cboStream_var1_Property = CxvPropertyDeclaration.Register("cboStream_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME.@y"
			});

			public static readonly CxvPropertyDeclaration lblNtrain_var1_Property = CxvPropertyDeclaration.Register("lblNtrain_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.NTRAIN"
			});

			public object spnNtrain_var1 => GetValue(spnNtrain_var1_Property);

			public object txtOptime_var1 => GetValue(txtOptime_var1_Property);

			public object txtDownTime_var1 => GetValue(txtDownTime_var1_Property);

			public object txtCycleTime_var1 => GetValue(txtCycleTime_var1_Property);

			public object cboStream_var1 => GetValue(cboStream_var1_Property);

			public object lblNtrain_var1 => GetValue(lblNtrain_var1_Property);
		}

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lbtuOptime_var1_Property = CxvPropertyDeclaration.Register("lbtuOptime_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Batch-Operation.Input.OP_TIME"
		});

		public static readonly CxvPropertyDeclaration lbtuDown_var1_Property = CxvPropertyDeclaration.Register("lbtuDown_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Batch-Operation.Input.DOWN_TIME"
		});

		public static readonly CxvPropertyDeclaration lbtuCycle_var1_Property = CxvPropertyDeclaration.Register("lbtuCycle_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME"
		});

		public static readonly CxvPropertyDeclaration SABatchO_GridData_Property = CxvPropertyDeclaration.Register("SABatchO_GridData", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(SABatchO_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME",
				UseChildId = true,
				Name = "y"
			}
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object lbtuOptime_var1 => GetValue(lbtuOptime_var1_Property);

		public object lbtuDown_var1 => GetValue(lbtuDown_var1_Property);

		public object lbtuCycle_var1 => GetValue(lbtuCycle_var1_Property);

		public object SABatchO_GridData => GetValue(SABatchO_GridData_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_BatchO")]
	public class MMSetup_Report_BatchO : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea SABatchO;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_BatchO()
		{
			base.ViewModelType = typeof(MMSetup_Report_BatchO_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_batcho.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				SABatchO = (MMScrollArea)target;
				break;
			case 3:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_BlkExc_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lstpkInclBl_var1_Property = CxvPropertyDeclaration.Register("lstpkInclBl_var1", typeof(MMSetup_Report_BlkExc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Block-Report.Input.EXCL_BLOCKS"
		});

		public static readonly CxvPropertyDeclaration lstpkInclBl_state_Property = CxvPropertyDeclaration.Register("lstpkInclBl_state", typeof(MMSetup_Report_BlkExc_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
			}
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object lstpkInclBl_var1 => GetValue(lstpkInclBl_var1_Property);

		public object lstpkInclBl_state => GetValue(lstpkInclBl_state_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_BlkExc")]
	public class MMSetup_Report_BlkExc : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpkInclBl;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_BlkExc()
		{
			base.ViewModelType = typeof(MMSetup_Report_BlkExc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_blkexc.xaml", UriKind.Relative);
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
				lstpkInclBl = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_BlkInc_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lstpkInclBl_var1_Property = CxvPropertyDeclaration.Register("lstpkInclBl_var1", typeof(MMSetup_Report_BlkInc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Block-Report.Input.INCL_BLOCKS"
		});

		public static readonly CxvPropertyDeclaration lstpkInclBl_state_Property = CxvPropertyDeclaration.Register("lstpkInclBl_state", typeof(MMSetup_Report_BlkInc_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
			}
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object lstpkInclBl_var1 => GetValue(lstpkInclBl_var1_Property);

		public object lstpkInclBl_state => GetValue(lstpkInclBl_state_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_BlkInc")]
	public class MMSetup_Report_BlkInc : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpkInclBl;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_BlkInc()
		{
			base.ViewModelType = typeof(MMSetup_Report_BlkInc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_blkinc.xaml", UriKind.Relative);
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
				lstpkInclBl = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Block_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdIncludeBlock_Command;

		private ICommand _cmdExcludeBlock_Command;

		public static readonly CxvPropertyDeclaration chkCompbal_var1_Property = CxvPropertyDeclaration.Register("chkCompbal_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.COMPBAL",
			TrueValue = "COMPBAL",
			FalseValue = "NOCOMPBAL",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkInput_var1_Property = CxvPropertyDeclaration.Register("chkInput_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.INPUT",
			TrueValue = "INPUT",
			FalseValue = "NOINPUT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkTotbal_var1_Property = CxvPropertyDeclaration.Register("chkTotbal_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.TOTBAL",
			TrueValue = "TOTBAL",
			FalseValue = "NOTOTBAL",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkResults_var1_Property = CxvPropertyDeclaration.Register("chkResults_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.RESULTS",
			TrueValue = "RESULTS",
			FalseValue = "NORESULTS",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.NEWPAGE",
			TrueValue = "NEWPAGE",
			FalseValue = "NONEWPAGE",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkSort_var1_Property = CxvPropertyDeclaration.Register("chkSort_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Block-Report.Input.SORT",
			TrueValue = "SORT",
			FalseValue = "NOSORT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSetup_Report_Block_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
			}
		});

		public static readonly CxvPropertyDeclaration cmdExcludeBlock_var1_Property = CxvPropertyDeclaration.Register("cmdExcludeBlock_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Block-Report.CC Nodes.EXCLD"
			}
		});

		public static readonly CxvPropertyDeclaration cmdIncludeBlock_var1_Property = CxvPropertyDeclaration.Register("cmdIncludeBlock_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Block-Report.CC Nodes.INCLD"
			}
		});

		public ICommand cmdIncludeBlock_Command
		{
			get
			{
				if (_cmdIncludeBlock_Command == null)
				{
					_cmdIncludeBlock_Command = new CxvDelegateCommand<object>(cmdIncludeBlock_CommandExecute);
				}
				return _cmdIncludeBlock_Command;
			}
		}

		public ICommand cmdExcludeBlock_Command
		{
			get
			{
				if (_cmdExcludeBlock_Command == null)
				{
					_cmdExcludeBlock_Command = new CxvDelegateCommand<object>(cmdExcludeBlock_CommandExecute);
				}
				return _cmdExcludeBlock_Command;
			}
		}

		public object chkCompbal_var1 => GetValue(chkCompbal_var1_Property);

		public object chkInput_var1 => GetValue(chkInput_var1_Property);

		public object chkTotbal_var1 => GetValue(chkTotbal_var1_Property);

		public object chkResults_var1 => GetValue(chkResults_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object chkSort_var1 => GetValue(chkSort_var1_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object cmdExcludeBlock_var1 => GetValue(cmdExcludeBlock_var1_Property);

		public object cmdIncludeBlock_var1 => GetValue(cmdIncludeBlock_var1_Property);

		private void cmdIncludeBlock_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_BlkInc",
				LegacyFlags = 0,
				HelpId = 17,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Block_Display1,
				ResizeMode = ResizeMode.CanResize
			};
			DisplayForm(args);
		}

		private void cmdExcludeBlock_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_BlkExc",
				LegacyFlags = 0,
				HelpId = 18,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Block_Display2,
				ResizeMode = ResizeMode.CanResize
			};
			DisplayForm(args);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				ExpandDataPathAndGet("Top.appModelv8.Setup.ReportOptions.Report.Input.REPORT", "value");
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_Block")]
	public class MMSetup_Report_Block : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMCheckBox chkTotbal;

		internal MMCheckBox chkCompbal;

		internal MMCheckBox chkInput;

		internal MMCheckBox chkResults;

		internal MMCheckBox MMCheckBox2;

		internal MMCheckBox chkSort;

		internal MMCmdButton cmdIncludeBlock;

		internal MMCmdButton cmdExcludeBlock;

		private bool _contentLoaded;

		public MMSetup_Report_Block()
		{
			base.ViewModelType = typeof(MMSetup_Report_Block_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_block.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 2:
				chkTotbal = (MMCheckBox)target;
				break;
			case 3:
				chkCompbal = (MMCheckBox)target;
				break;
			case 4:
				chkInput = (MMCheckBox)target;
				break;
			case 5:
				chkResults = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 7:
				chkSort = (MMCheckBox)target;
				break;
			case 8:
				cmdIncludeBlock = (MMCmdButton)target;
				break;
			case 9:
				cmdExcludeBlock = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Default_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration chkReport_var1_Property = CxvPropertyDeclaration.Register("chkReport_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.REPORT",
			TrueValue = "REPORT",
			FalseValue = "NOREPORT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMFrame3_state_Property = CxvPropertyDeclaration.Register("MMFrame3_state", typeof(MMSetup_Report_Default_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
			}
		});

		public static readonly CxvPropertyDeclaration spnLine_var1_Property = CxvPropertyDeclaration.Register("spnLine_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.LINES"
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Default_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
			}
		});

		public static readonly CxvPropertyDeclaration chkSens_var1_Property = CxvPropertyDeclaration.Register("chkSens_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.SENSITIVITY",
			TrueValue = "SENSITIVITY",
			FalseValue = "NOSENSITIVIT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkProp_var1_Property = CxvPropertyDeclaration.Register("chkProp_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.PROPERTIES",
			TrueValue = "PROPERTIES",
			FalseValue = "NOPROPERTIES",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkBlocks_var1_Property = CxvPropertyDeclaration.Register("chkBlocks_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.BLOCKS",
			TrueValue = "BLOCKS",
			FalseValue = "NOBLOCKS",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSensit_var1_Property = CxvPropertyDeclaration.Register("chkSensit_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.STREAMS",
			TrueValue = "STREAMS",
			FalseValue = "NOSTREAMS",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkFlowsheet_var1_Property = CxvPropertyDeclaration.Register("chkFlowsheet_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.FLOWSHEET",
			TrueValue = "FLOWSHEET",
			FalseValue = "NOFLOWSHEET",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkAda_var1_Property = CxvPropertyDeclaration.Register("chkAda_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.ADA",
			TrueValue = "ADA",
			FalseValue = "NOADA",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkInsert_var1_Property = CxvPropertyDeclaration.Register("chkInsert_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.INSERT",
			TrueValue = "INSERT",
			FalseValue = "NOINSERT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkInput_var1_Property = CxvPropertyDeclaration.Register("chkInput_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.INPUT",
			TrueValue = "INPUT",
			FalseValue = "NOINPUT",
			DefaultValue = false
		});

		public object chkReport_var1 => GetValue(chkReport_var1_Property);

		public object MMFrame3_state => GetValue(MMFrame3_state_Property);

		public object spnLine_var1 => GetValue(spnLine_var1_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object chkSens_var1 => GetValue(chkSens_var1_Property);

		public object chkProp_var1 => GetValue(chkProp_var1_Property);

		public object chkBlocks_var1 => GetValue(chkBlocks_var1_Property);

		public object chkSensit_var1 => GetValue(chkSensit_var1_Property);

		public object chkFlowsheet_var1 => GetValue(chkFlowsheet_var1_Property);

		public object chkAda_var1 => GetValue(chkAda_var1_Property);

		public object chkInsert_var1 => GetValue(chkInsert_var1_Property);

		public object chkInput_var1 => GetValue(chkInput_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Report_Default")]
	public class MMSetup_Report_Default : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMCheckBox chkReport;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkInput;

		internal MMCheckBox chkProp;

		internal MMCheckBox chkFlowsheet;

		internal MMCheckBox chkSens;

		internal MMCheckBox chkBlocks;

		internal MMCheckBox chkAda;

		internal MMCheckBox chkSensit;

		internal MMCheckBox chkInsert;

		internal MMGroupBox MMFrame3;

		internal MMLabel lbtuLines_label;

		internal MMSpinBox spnLine;

		private bool _contentLoaded;

		public MMSetup_Report_Default()
		{
			base.ViewModelType = typeof(MMSetup_Report_Default_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_default.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 2:
				chkReport = (MMCheckBox)target;
				break;
			case 3:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 4:
				chkInput = (MMCheckBox)target;
				break;
			case 5:
				chkProp = (MMCheckBox)target;
				break;
			case 6:
				chkFlowsheet = (MMCheckBox)target;
				break;
			case 7:
				chkSens = (MMCheckBox)target;
				break;
			case 8:
				chkBlocks = (MMCheckBox)target;
				break;
			case 9:
				chkAda = (MMCheckBox)target;
				break;
			case 10:
				chkSensit = (MMCheckBox)target;
				break;
			case 11:
				chkInsert = (MMCheckBox)target;
				break;
			case 12:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 13:
				lbtuLines_label = (MMLabel)target;
				break;
			case 14:
				spnLine = (MMSpinBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_ExclSt_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_ExclSt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.EXCL_STREAMS"
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_ExclSt")]
	public class MMSetup_Report_ExclSt : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_ExclSt()
		{
			base.ViewModelType = typeof(MMSetup_Report_ExclSt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_exclst.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_FlowSh_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration chkConstraint_var1_Property = CxvPropertyDeclaration.Register("chkConstraint_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.CONSTRAINT",
			TrueValue = "CONSTRAINT",
			FalseValue = "NOCONSTRAINT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkTransfer_var1_Property = CxvPropertyDeclaration.Register("chkTransfer_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.TRANSFER",
			TrueValue = "TRANSFER",
			FalseValue = "NOTRANSFER",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkDesign_var1_Property = CxvPropertyDeclaration.Register("chkDesign_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.DESIGN_SPEC",
			TrueValue = "DESIGN-SPEC",
			FalseValue = "NODESIGN-SPE",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkOptimi_var1_Property = CxvPropertyDeclaration.Register("chkOptimi_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.OPTIMIZATION",
			TrueValue = "OPTIMIZATION",
			FalseValue = "NOOPTIMIZATI",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkFortran_var1_Property = CxvPropertyDeclaration.Register("chkFortran_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.FORTRAN",
			TrueValue = "FORTRAN",
			FalseValue = "NOFORTRAN",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkDescrip_var1_Property = CxvPropertyDeclaration.Register("chkDescrip_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.DESCRIPTION",
			TrueValue = "DESCRIPTION",
			FalseValue = "NODESCRIPTIO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkCompbal_var1_Property = CxvPropertyDeclaration.Register("chkCompbal_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.COMPBAL",
			TrueValue = "COMPBAL",
			FalseValue = "NOCOMPBAL",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkTotbal_var1_Property = CxvPropertyDeclaration.Register("chkTotbal_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.TOTBAL",
			TrueValue = "TOTBAL",
			FalseValue = "NOTOTBAL",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSeq_var1_Property = CxvPropertyDeclaration.Register("chkSeq_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.SEQUENCE",
			TrueValue = "SEQUENCE",
			FalseValue = "NOSEQUENCE",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkConverge_var1_Property = CxvPropertyDeclaration.Register("chkConverge_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Flowsheet-Report.Input.CONVERGENCE",
			TrueValue = "CONVERGENCE",
			FalseValue = "NOCONVERGENC",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.FLOWS"
			}
		});

		public object chkConstraint_var1 => GetValue(chkConstraint_var1_Property);

		public object chkTransfer_var1 => GetValue(chkTransfer_var1_Property);

		public object chkDesign_var1 => GetValue(chkDesign_var1_Property);

		public object chkOptimi_var1 => GetValue(chkOptimi_var1_Property);

		public object chkFortran_var1 => GetValue(chkFortran_var1_Property);

		public object chkDescrip_var1 => GetValue(chkDescrip_var1_Property);

		public object chkCompbal_var1 => GetValue(chkCompbal_var1_Property);

		public object chkTotbal_var1 => GetValue(chkTotbal_var1_Property);

		public object chkSeq_var1 => GetValue(chkSeq_var1_Property);

		public object chkConverge_var1 => GetValue(chkConverge_var1_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);
	}
	[ProgId("MMSetup.MMSetup_Report_FlowSh")]
	public class MMSetup_Report_FlowSh : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkTotbal;

		internal MMCheckBox chkCompbal;

		internal MMCheckBox chkDescrip;

		internal MMCheckBox chkConverge;

		internal MMCheckBox chkSeq;

		internal MMCheckBox chkDesign;

		internal MMCheckBox chkFortran;

		internal MMCheckBox chkConstraint;

		internal MMCheckBox chkOptimi;

		internal MMCheckBox chkTransfer;

		private bool _contentLoaded;

		public MMSetup_Report_FlowSh()
		{
			base.ViewModelType = typeof(MMSetup_Report_FlowSh_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_flowsh.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				chkTotbal = (MMCheckBox)target;
				break;
			case 3:
				chkCompbal = (MMCheckBox)target;
				break;
			case 4:
				chkDescrip = (MMCheckBox)target;
				break;
			case 5:
				chkConverge = (MMCheckBox)target;
				break;
			case 6:
				chkSeq = (MMCheckBox)target;
				break;
			case 7:
				chkDesign = (MMCheckBox)target;
				break;
			case 8:
				chkFortran = (MMCheckBox)target;
				break;
			case 9:
				chkConstraint = (MMCheckBox)target;
				break;
			case 10:
				chkOptimi = (MMCheckBox)target;
				break;
			case 11:
				chkTransfer = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_InclSt_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_InclSt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.INCL_STREAMS"
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_InclSt")]
	public class MMSetup_Report_InclSt : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_InclSt()
		{
			base.ViewModelType = typeof(MMSetup_Report_InclSt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_inclst.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Proper_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSetup_Report_Proper_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
			}
		});

		public static readonly CxvPropertyDeclaration chkNeu_var1_Property = CxvPropertyDeclaration.Register("chkNeu_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.NEUTRAL",
			TrueValue = "NEUTRAL",
			FalseValue = "NONEUTRAL",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkDfms_var1_Property = CxvPropertyDeclaration.Register("chkDfms_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.DFMS",
			TrueValue = "DFMS",
			FalseValue = "NODFMS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkProject_var1_Property = CxvPropertyDeclaration.Register("chkProject_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PROJECT",
			TrueValue = "PROJECT",
			FalseValue = "NOPROJECT",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkPropData_var1_Property = CxvPropertyDeclaration.Register("chkPropData_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PROP_DATA",
			TrueValue = "PROP-DATA",
			FalseValue = "NOPROP-DATA",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Proper_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
			}
		});

		public static readonly CxvPropertyDeclaration chkPces_var1_Property = CxvPropertyDeclaration.Register("chkPces_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PCES",
			TrueValue = "PCES",
			FalseValue = "NOPCES",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkParplus_var1_Property = CxvPropertyDeclaration.Register("chkParplus_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PARPLUS",
			TrueValue = "PARAM-PLUS",
			FalseValue = "NOPARAM-PLUS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkParams_var1_Property = CxvPropertyDeclaration.Register("chkParams_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PARAMS",
			TrueValue = "PARAMS",
			FalseValue = "NOPARAMS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkComps_var1_Property = CxvPropertyDeclaration.Register("chkComps_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.COMPS",
			TrueValue = "COMPS",
			FalseValue = "NOCOMPS",
			DefaultValue = true
		});

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object chkNeu_var1 => GetValue(chkNeu_var1_Property);

		public object chkDfms_var1 => GetValue(chkDfms_var1_Property);

		public object chkProject_var1 => GetValue(chkProject_var1_Property);

		public object chkPropData_var1 => GetValue(chkPropData_var1_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object chkPces_var1 => GetValue(chkPces_var1_Property);

		public object chkParplus_var1 => GetValue(chkParplus_var1_Property);

		public object chkParams_var1 => GetValue(chkParams_var1_Property);

		public object chkComps_var1 => GetValue(chkComps_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Report_Proper")]
	public class MMSetup_Report_Proper : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkComps;

		internal MMCheckBox chkParams;

		internal MMCheckBox chkPces;

		internal MMCheckBox chkParplus;

		internal MMGroupBox MMFrame2;

		internal MMCheckBox chkDfms;

		internal MMCheckBox chkProject;

		internal MMCheckBox chkPropData;

		internal MMCheckBox chkNeu;

		private bool _contentLoaded;

		public MMSetup_Report_Proper()
		{
			base.ViewModelType = typeof(MMSetup_Report_Proper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_proper.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				chkComps = (MMCheckBox)target;
				break;
			case 3:
				chkParams = (MMCheckBox)target;
				break;
			case 4:
				chkPces = (MMCheckBox)target;
				break;
			case 5:
				chkParplus = (MMCheckBox)target;
				break;
			case 6:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 7:
				chkDfms = (MMCheckBox)target;
				break;
			case 8:
				chkProject = (MMCheckBox)target;
				break;
			case 9:
				chkPropData = (MMCheckBox)target;
				break;
			case 10:
				chkNeu = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_SAttri_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration chkSSubsAttr_subsattr_Property = CxvPropertyDeclaration.Register("chkSSubsAttr_subsattr", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_SUBS_ATTR.@sreportno",
			TrueValue = "SUBS-ATTR",
			FalseValue = "NOSUBS-ATTR",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSCompAttr_compattr_Property = CxvPropertyDeclaration.Register("chkSCompAttr_compattr", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_COMP_ATTR.@sreportno",
			TrueValue = "COMP-ATTR",
			FalseValue = "NOCOMP-ATTR",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSAttrDesc_attrdesc_Property = CxvPropertyDeclaration.Register("chkSAttrDesc_attrdesc", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_ATTR_DESC.@sreportno",
			TrueValue = "ATTR-DESC",
			FalseValue = "NOATTR-DESC",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSStruct_struct_Property = CxvPropertyDeclaration.Register("chkSStruct_struct", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_STRUCTURE.@sreportno",
			TrueValue = "STRUCTURE",
			FalseValue = "NOSTRUCTURE",
			DefaultValue = false
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object chkSSubsAttr_subsattr => GetValue(chkSSubsAttr_subsattr_Property);

		public object chkSCompAttr_compattr => GetValue(chkSCompAttr_compattr_Property);

		public object chkSAttrDesc_attrdesc => GetValue(chkSAttrDesc_attrdesc_Property);

		public object chkSStruct_struct => GetValue(chkSStruct_struct_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_SAttri")]
	public class MMSetup_Report_SAttri : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkSCompAttr;

		internal MMCheckBox chkSSubsAttr;

		internal MMCheckBox chkSAttrDesc;

		internal MMCheckBox chkSStruct;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_SAttri()
		{
			base.ViewModelType = typeof(MMSetup_Report_SAttri_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_sattri.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				chkSCompAttr = (MMCheckBox)target;
				break;
			case 3:
				chkSSubsAttr = (MMCheckBox)target;
				break;
			case 4:
				chkSAttrDesc = (MMCheckBox)target;
				break;
			case 5:
				chkSStruct = (MMCheckBox)target;
				break;
			case 6:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Stream_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdStream_Command;

		private ICommand _cmdExclStreams_Command;

		private ICommand _cmdPropSets_Command;

		private ICommand _cmdAttribute_Command;

		private ICommand _cmdStrName_Command;

		private ICommand _cmdBatch_Command;

		public static CxvPropertyDeclaration cmdBatch_CanExecuteProperty = CxvPropertyDeclaration.Register("cmdBatch_CanExecute", typeof(MMSetup_Report_Stream_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.ReportOptions.Batch-Operation",
			Operator = CxvLogicalOperator.IsNotNull
		});

		private ICommand _cmdSuppl_Command;

		public static readonly CxvPropertyDeclaration frmStreamFormat_state_Property = CxvPropertyDeclaration.Register("frmStreamFormat_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration chkSort_sort_Property = CxvPropertyDeclaration.Register("chkSort_sort", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SORT",
			TrueValue = "SORT",
			FalseValue = "NOSORT",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration opgWide_MultiMap_Property = CxvPropertyDeclaration.Register("opgWide_MultiMap", typeof(MMSetup_Report_Stream_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "opgWide_wide",
					DataPath = "@main.ReportOptions.Stream-Report.Input.WIDE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard (80 characters)",
					DisplayResourceKey = "MMSetup_Report_Stream_ViewModel__CxvMultiMapOption_Display_Standard__80_column_",
					Value = "opgWide_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "opgWide_wide",
							Value = "NARROW"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Wide (132 characters)",
					DisplayResourceKey = "MMSetup_Report_Stream_ViewModel__CxvMultiMapOption_Display_Wide__132_column_",
					Value = "opgWide_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "opgWide_wide",
							Value = "WIDE"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Main.Input.TFFFILE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmdExclStreams_var1_Property = CxvPropertyDeclaration.Register("cmdExclStreams_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.EXCLD"
			}
		});

		public static readonly CxvPropertyDeclaration cmdStream_var1_Property = CxvPropertyDeclaration.Register("cmdStream_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.INCLD"
			}
		});

		public static readonly CxvPropertyDeclaration cmdPropSets_var1_Property = CxvPropertyDeclaration.Register("cmdPropSets_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration cmdAttribute_var1_Property = CxvPropertyDeclaration.Register("cmdAttribute_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration chkZero_zero_Property = CxvPropertyDeclaration.Register("chkZero_zero", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.ZEROFLOW",
			TrueValue = "ZEROFLOW",
			FalseValue = "NOZEROFLOW",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration fraFracBasis_state_Property = CxvPropertyDeclaration.Register("fraFracBasis_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration chkFracStd_stdvolfrac_Property = CxvPropertyDeclaration.Register("chkFracStd_stdvolfrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.STDVOLFRAC",
			TrueValue = "STDVOLFRAC",
			FalseValue = "NOVOLFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkFracMass_massfrac_Property = CxvPropertyDeclaration.Register("chkFracMass_massfrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.MASSFRAC",
			TrueValue = "MASSFRAC",
			FalseValue = "NOMASSFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkFracMole_molefrac_Property = CxvPropertyDeclaration.Register("chkFracMole_molefrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.MOLEFRAC",
			TrueValue = "MOLEFRAC",
			FalseValue = "NOMOLEFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration fraFlowBasis_state_Property = CxvPropertyDeclaration.Register("fraFlowBasis_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration chkFlowStd_stdvolflow_Property = CxvPropertyDeclaration.Register("chkFlowStd_stdvolflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.STDVOLFLOW",
			TrueValue = "STDVOLFLOW",
			FalseValue = "NOVOLFLOW",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkFlowMass_massflow_Property = CxvPropertyDeclaration.Register("chkFlowMass_massflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.MASSFLOW",
			TrueValue = "MASSFLOW",
			FalseValue = "NOMASSFLOW",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkFlowMole_moleflow_Property = CxvPropertyDeclaration.Register("chkFlowMole_moleflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.MOLEFLOW",
			TrueValue = "MOLEFLOW",
			FalseValue = "NOMOLEFLOW",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkNames_var1_Property = CxvPropertyDeclaration.Register("chkNames_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.NAMES",
			TrueValue = "NAMES",
			FalseValue = "NONAMES",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration chkReport_var1_Property = CxvPropertyDeclaration.Register("chkReport_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.REPORT",
			TrueValue = "REPORT",
			FalseValue = "NOREPORT",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration cmdSuppl_var1_Property = CxvPropertyDeclaration.Register("cmdSuppl_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
			}
		});

		public static readonly CxvPropertyDeclaration fraItems_state_Property = CxvPropertyDeclaration.Register("fraItems_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
			}
		});

		public ICommand cmdStream_Command
		{
			get
			{
				if (_cmdStream_Command == null)
				{
					_cmdStream_Command = new CxvDelegateCommand<object>(cmdStream_CommandExecute);
				}
				return _cmdStream_Command;
			}
		}

		public ICommand cmdExclStreams_Command
		{
			get
			{
				if (_cmdExclStreams_Command == null)
				{
					_cmdExclStreams_Command = new CxvDelegateCommand<object>(cmdExclStreams_CommandExecute);
				}
				return _cmdExclStreams_Command;
			}
		}

		public ICommand cmdPropSets_Command
		{
			get
			{
				if (_cmdPropSets_Command == null)
				{
					_cmdPropSets_Command = new CxvDelegateCommand<object>(cmdPropSets_CommandExecute);
				}
				return _cmdPropSets_Command;
			}
		}

		public ICommand cmdAttribute_Command
		{
			get
			{
				if (_cmdAttribute_Command == null)
				{
					_cmdAttribute_Command = new CxvDelegateCommand<object>(cmdAttribute_CommandExecute);
				}
				return _cmdAttribute_Command;
			}
		}

		public ICommand cmdStrName_Command
		{
			get
			{
				if (_cmdStrName_Command == null)
				{
					_cmdStrName_Command = new CxvDelegateCommand<object>(cmdStrName_CommandExecute);
				}
				return _cmdStrName_Command;
			}
		}

		public ICommand cmdBatch_Command
		{
			get
			{
				if (_cmdBatch_Command == null)
				{
					_cmdBatch_Command = new CxvDelegateCommand<object>(cmdBatch_CommandExecute, this, cmdBatch_CanExecuteProperty.Name + ".Value");
				}
				return _cmdBatch_Command;
			}
		}

		public CxvLogicalPropertyData cmdBatch_CanExecute => GetValue(cmdBatch_CanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdSuppl_Command
		{
			get
			{
				if (_cmdSuppl_Command == null)
				{
					_cmdSuppl_Command = new CxvDelegateCommand<object>(cmdSuppl_CommandExecute);
				}
				return _cmdSuppl_Command;
			}
		}

		public object frmStreamFormat_state => GetValue(frmStreamFormat_state_Property);

		public object chkSort_sort => GetValue(chkSort_sort_Property);

		public object opgWide_MultiMap => GetValue(opgWide_MultiMap_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cmdExclStreams_var1 => GetValue(cmdExclStreams_var1_Property);

		public object cmdStream_var1 => GetValue(cmdStream_var1_Property);

		public object cmdPropSets_var1 => GetValue(cmdPropSets_var1_Property);

		public object cmdAttribute_var1 => GetValue(cmdAttribute_var1_Property);

		public object chkZero_zero => GetValue(chkZero_zero_Property);

		public object fraFracBasis_state => GetValue(fraFracBasis_state_Property);

		public object chkFracStd_stdvolfrac => GetValue(chkFracStd_stdvolfrac_Property);

		public object chkFracMass_massfrac => GetValue(chkFracMass_massfrac_Property);

		public object chkFracMole_molefrac => GetValue(chkFracMole_molefrac_Property);

		public object fraFlowBasis_state => GetValue(fraFlowBasis_state_Property);

		public object chkFlowStd_stdvolflow => GetValue(chkFlowStd_stdvolflow_Property);

		public object chkFlowMass_massflow => GetValue(chkFlowMass_massflow_Property);

		public object chkFlowMole_moleflow => GetValue(chkFlowMole_moleflow_Property);

		public object chkNames_var1 => GetValue(chkNames_var1_Property);

		public object chkReport_var1 => GetValue(chkReport_var1_Property);

		public object cmdSuppl_var1 => GetValue(cmdSuppl_var1_Property);

		public object fraItems_state => GetValue(fraItems_state_Property);

		private void cmdStream_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_InclSt",
				LegacyFlags = 0,
				HelpId = 287,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Stream_Display1,
				ResizeMode = ResizeMode.CanResize
			};
			DisplayForm(args);
		}

		private void cmdExclStreams_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_ExclSt",
				LegacyFlags = 0,
				HelpId = 312,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Stream_Display2,
				ResizeMode = ResizeMode.CanResize
			};
			DisplayForm(args);
		}

		private void cmdPropSets_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_StrPro",
				LegacyFlags = 0,
				HelpId = 288,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Stream_Display3,
				PreferredHeight = 300,
				ResizeMode = ResizeMode.CanResize
			};
			DisplayForm(args);
		}

		private void cmdAttribute_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_Attrib",
				LegacyFlags = 0,
				HelpId = 289,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Stream_Display4
			};
			DisplayForm(args);
		}

		private void cmdStrName_CommandExecute(object parameter)
		{
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMSetup.MMSetup_Report_StrName";
			e.LegacyFlags = 0;
			e.HelpId = 320;
			e.HelpFile = "setup.hlp";
			e.ShortName = WpfFormsResources.MMSetup_Report_Stream_Display5;
			e.ShowPrompts = true;
			e.CompleteDataPaths = new string[1] { "@main.ReportOptions.Stream-Names.CC Nodes.SPEC" };
			DisplayFormEventArgs args = e;
			DisplayForm(args);
		}

		private void cmdBatch_CommandExecute(object parameter)
		{
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMSetup.MMSetup_Report_BatchO";
			e.LegacyFlags = 0;
			e.HelpId = 286;
			e.HelpFile = "setup.hlp";
			e.ShowPrompts = true;
			e.ShortName = WpfFormsResources.MMSetup_Report_Stream_Display6;
			e.CompleteDataPaths = new string[1] { "@main.ReportOptions.Batch-Operation.CC Nodes.SPEC" };
			e.PreferredWidth = 550;
			e.ResizeMode = ResizeMode.CanResizeWithGrip;
			DisplayFormEventArgs args = e;
			DisplayForm(args);
		}

		private void cmdSuppl_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_Supple",
				LegacyFlags = 0,
				HelpId = 285,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Stream_Display7
			};
			DisplayForm(args);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				ExpandDataPathAndGet("Top.appModelv8.Setup.ReportOptions.Report.Input.REPORT", "value");
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_Stream")]
	public class MMSetup_Report_Stream : MMTabPage, IComponentConnector
	{
		internal MMCheckBox chkReport;

		internal MMCheckBox chkNames;

		internal MMGroupBox fraItems;

		internal MMGroupBox fraFlowBasis;

		internal MMCheckBox chkFlowMole;

		internal MMCheckBox chkFlowMass;

		internal MMCheckBox chkFlowStd;

		internal MMGroupBox fraFracBasis;

		internal MMCheckBox chkFracMole;

		internal MMCheckBox chkFracMass;

		internal MMCheckBox chkFracStd;

		internal MMCheckBox chkZero;

		internal MMGroupBox frmStreamFormat;

		internal MMOptionGroup opgWide;

		internal MMOptionButton opgWide_opt0;

		internal MMOptionButton opgWide_opt1;

		internal MMCheckBox chkSort;

		internal MMCmdButton cmdStream;

		internal MMCmdButton cmdExclStreams;

		internal MMCmdButton cmdPropSets;

		internal MMCmdButton cmdAttribute;

		internal MMCmdButton cmdStrName;

		internal MMCmdButton cmdBatch;

		internal MMCmdButton cmdSuppl;

		private bool _contentLoaded;

		public MMSetup_Report_Stream()
		{
			base.ViewModelType = typeof(MMSetup_Report_Stream_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_stream.xaml", UriKind.Relative);
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
				chkReport = (MMCheckBox)target;
				break;
			case 2:
				chkNames = (MMCheckBox)target;
				break;
			case 3:
				fraItems = (MMGroupBox)target;
				break;
			case 4:
				fraFlowBasis = (MMGroupBox)target;
				break;
			case 5:
				chkFlowMole = (MMCheckBox)target;
				break;
			case 6:
				chkFlowMass = (MMCheckBox)target;
				break;
			case 7:
				chkFlowStd = (MMCheckBox)target;
				break;
			case 8:
				fraFracBasis = (MMGroupBox)target;
				break;
			case 9:
				chkFracMole = (MMCheckBox)target;
				break;
			case 10:
				chkFracMass = (MMCheckBox)target;
				break;
			case 11:
				chkFracStd = (MMCheckBox)target;
				break;
			case 12:
				chkZero = (MMCheckBox)target;
				break;
			case 13:
				frmStreamFormat = (MMGroupBox)target;
				break;
			case 14:
				opgWide = (MMOptionGroup)target;
				break;
			case 15:
				opgWide_opt0 = (MMOptionButton)target;
				break;
			case 16:
				opgWide_opt1 = (MMOptionButton)target;
				break;
			case 17:
				chkSort = (MMCheckBox)target;
				break;
			case 18:
				cmdStream = (MMCmdButton)target;
				break;
			case 19:
				cmdExclStreams = (MMCmdButton)target;
				break;
			case 20:
				cmdPropSets = (MMCmdButton)target;
				break;
			case 21:
				cmdAttribute = (MMCmdButton)target;
				break;
			case 22:
				cmdStrName = (MMCmdButton)target;
				break;
			case 23:
				cmdBatch = (MMCmdButton)target;
				break;
			case 24:
				cmdSuppl = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_StrName_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT.@y"
			});

			public static readonly CxvPropertyDeclaration txtDesc_var1_Property = CxvPropertyDeclaration.Register("txtDesc_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT.@y"
			});

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object txtDesc_var1 => GetValue(txtDesc_var1_Property);
		}

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Report_StrName_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT",
				UseChildId = true,
				Name = "y"
			}
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_StrName")]
	public class MMSetup_Report_StrName : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea grdChild;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_StrName()
		{
			base.ViewModelType = typeof(MMSetup_Report_StrName_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_strname.xaml", UriKind.Relative);
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 2:
				grdChild = (MMScrollArea)target;
				break;
			case 3:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_StrPro_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_StrPro_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.PROPERTIES",
			AllowSort = false
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_StrPro")]
	public class MMSetup_Report_StrPro : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_StrPro()
		{
			base.ViewModelType = typeof(MMSetup_Report_StrPro_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_strpro.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_SupExc_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_SupExc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_EXCL_ST.@sreportno"
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_SupExc")]
	public class MMSetup_Report_SupExc : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_SupExc()
		{
			base.ViewModelType = typeof(MMSetup_Report_SupExc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_supexc.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_SupInc_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_SupInc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_INCL_ST.@sreportno"
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_SupInc")]
	public class MMSetup_Report_SupInc : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_SupInc()
		{
			base.ViewModelType = typeof(MMSetup_Report_SupInc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_supinc.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_Supple_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdStream_Command;

		private ICommand _cmdExcludeStream_Command;

		private ICommand _cmdPropSets_Command;

		private ICommand _cmdAttribute_Command;

		private ICommand _cmdSubr_Command;

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "sreportno",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration cmdExcludeStream_var1_Property = CxvPropertyDeclaration.Register("cmdExcludeStream_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SEXCLD.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration cmdStream_var1_Property = CxvPropertyDeclaration.Register("cmdStream_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SINCLD.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration chkSReport_var1_Property = CxvPropertyDeclaration.Register("chkSReport_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_REPORT.@sreportno",
			TrueValue = "REPORT",
			FalseValue = "NOREPORT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration fraItems_state_Property = CxvPropertyDeclaration.Register("fraItems_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "sreportno",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration cmdAttribute_var1_Property = CxvPropertyDeclaration.Register("cmdAttribute_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration cmdPropSets_var1_Property = CxvPropertyDeclaration.Register("cmdPropSets_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration opgSWide_MultiMap_Property = CxvPropertyDeclaration.Register("opgSWide_MultiMap", typeof(MMSetup_Report_Supple_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "opgSWide_wide",
					DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_WIDE.@sreportno"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard (80 characters)",
					DisplayResourceKey = "MMSetup_Report_Supple_ViewModel__CxvMultiMapOption_Display_Standard__80_column_",
					Value = "opgSWide_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "opgSWide_wide",
							Value = "NARROW"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Wide (132 characters)",
					DisplayResourceKey = "MMSetup_Report_Supple_ViewModel__CxvMultiMapOption_Display_Wide__132_column_",
					Value = "opgSWide_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "opgSWide_wide",
							Value = "WIDE"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration chkSSort_sort_Property = CxvPropertyDeclaration.Register("chkSSort_sort", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_SORT.@sreportno",
			TrueValue = "SORT",
			FalseValue = "NOSORT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration fraFlowBasis_state_Property = CxvPropertyDeclaration.Register("fraFlowBasis_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration chkSFlowMole_moleflow_Property = CxvPropertyDeclaration.Register("chkSFlowMole_moleflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MOLEFLOW.@sreportno",
			TrueValue = "MOLEFLOW",
			FalseValue = "NOMOLEFLOW",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkSFlowMass_massflow_Property = CxvPropertyDeclaration.Register("chkSFlowMass_massflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MASSFLOW.@sreportno",
			TrueValue = "MASSFLOW",
			FalseValue = "NOMASSFLOW",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkSFlowStd_stdvolflow_Property = CxvPropertyDeclaration.Register("chkSFlowStd_stdvolflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_STDVOLFLOW.@sreportno",
			TrueValue = "STDVOLFLOW",
			FalseValue = "NOVOLFLOW",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration fraFracBasis_state_Property = CxvPropertyDeclaration.Register("fraFracBasis_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration chkSFracMole_molefrac_Property = CxvPropertyDeclaration.Register("chkSFracMole_molefrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MOLEFRAC.@sreportno",
			TrueValue = "MOLEFRAC",
			FalseValue = "NOMOLEFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkSFracMass_massfrac_Property = CxvPropertyDeclaration.Register("chkSFracMass_massfrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MASSFRAC.@sreportno",
			TrueValue = "MASSFRAC",
			FalseValue = "NOMASSFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkSFracStd_stdvolfrac_Property = CxvPropertyDeclaration.Register("chkSFracStd_stdvolfrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.S_STDVOLFRAC.@sreportno",
			TrueValue = "STDVOLFRAC",
			FalseValue = "NOVOLFRAC",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkSZero_zero_Property = CxvPropertyDeclaration.Register("chkSZero_zero", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_ZEROFLOW.@sreportno",
			TrueValue = "ZEROFLOW",
			FalseValue = "NOZEROFLOW",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
			}
		});

		public static readonly CxvPropertyDeclaration mnbReportNo_var2_Property = CxvPropertyDeclaration.Register("mnbReportNo_var2", typeof(MMSetup_Report_Supple_ViewModel), new CxvParameterProperty
		{
			Parameter = "sreportno"
		});

		public static readonly CxvPropertyDeclaration mnbReportNo_var1_Property = CxvPropertyDeclaration.Register("mnbReportNo_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_REPORT",
			SelectedItemBinding = "mnbReportNo_var2.Value",
			CreateNewPrompt = "Supplementary report number:",
			CreateNewPromptResourceKey = "MMSetup_Report_Supple_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Supplementary_report_numbe",
			CreateNewInputMask = 0,
			CreateNewMaxLength = 3
		});

		public ICommand cmdStream_Command
		{
			get
			{
				if (_cmdStream_Command == null)
				{
					_cmdStream_Command = new CxvDelegateCommand<object>(cmdStream_CommandExecute);
				}
				return _cmdStream_Command;
			}
		}

		public ICommand cmdExcludeStream_Command
		{
			get
			{
				if (_cmdExcludeStream_Command == null)
				{
					_cmdExcludeStream_Command = new CxvDelegateCommand<object>(cmdExcludeStream_CommandExecute);
				}
				return _cmdExcludeStream_Command;
			}
		}

		public ICommand cmdPropSets_Command
		{
			get
			{
				if (_cmdPropSets_Command == null)
				{
					_cmdPropSets_Command = new CxvDelegateCommand<object>(cmdPropSets_CommandExecute);
				}
				return _cmdPropSets_Command;
			}
		}

		public ICommand cmdAttribute_Command
		{
			get
			{
				if (_cmdAttribute_Command == null)
				{
					_cmdAttribute_Command = new CxvDelegateCommand<object>(cmdAttribute_CommandExecute);
				}
				return _cmdAttribute_Command;
			}
		}

		public ICommand cmdSubr_Command
		{
			get
			{
				if (_cmdSubr_Command == null)
				{
					_cmdSubr_Command = new CxvDelegateCommand<object>(cmdSubr_CommandExecute);
				}
				return _cmdSubr_Command;
			}
		}

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object cmdExcludeStream_var1 => GetValue(cmdExcludeStream_var1_Property);

		public object cmdStream_var1 => GetValue(cmdStream_var1_Property);

		public object chkSReport_var1 => GetValue(chkSReport_var1_Property);

		public object fraItems_state => GetValue(fraItems_state_Property);

		public object cmdAttribute_var1 => GetValue(cmdAttribute_var1_Property);

		public object cmdPropSets_var1 => GetValue(cmdPropSets_var1_Property);

		public object opgSWide_MultiMap => GetValue(opgSWide_MultiMap_Property);

		public object chkSSort_sort => GetValue(chkSSort_sort_Property);

		public object fraFlowBasis_state => GetValue(fraFlowBasis_state_Property);

		public object chkSFlowMole_moleflow => GetValue(chkSFlowMole_moleflow_Property);

		public object chkSFlowMass_massflow => GetValue(chkSFlowMass_massflow_Property);

		public object chkSFlowStd_stdvolflow => GetValue(chkSFlowStd_stdvolflow_Property);

		public object fraFracBasis_state => GetValue(fraFracBasis_state_Property);

		public object chkSFracMole_molefrac => GetValue(chkSFracMole_molefrac_Property);

		public object chkSFracMass_massfrac => GetValue(chkSFracMass_massfrac_Property);

		public object chkSFracStd_stdvolfrac => GetValue(chkSFracStd_stdvolfrac_Property);

		public object chkSZero_zero => GetValue(chkSZero_zero_Property);

		public object mnbReportNo_var2 => GetValue(mnbReportNo_var2_Property);

		public object mnbReportNo_var1 => GetValue(mnbReportNo_var1_Property);

		private void cmdStream_CommandExecute(object parameter)
		{
			CxvParameterPropertyData cxvParameterPropertyData = mnbReportNo_var2 as CxvParameterPropertyData;
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_SupInc",
				LegacyFlags = 0,
				HelpId = 305,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Supple_Display1,
				ResizeMode = ResizeMode.CanResize
			};
			if (cxvParameterPropertyData != null)
			{
				e.Parameters.Add("sreportno", cxvParameterPropertyData.Value);
			}
			DisplayForm(e);
		}

		private void cmdExcludeStream_CommandExecute(object parameter)
		{
			CxvParameterPropertyData cxvParameterPropertyData = mnbReportNo_var2 as CxvParameterPropertyData;
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_SupExc",
				LegacyFlags = 0,
				HelpId = 313,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Supple_Display2,
				ResizeMode = ResizeMode.CanResize
			};
			if (cxvParameterPropertyData != null)
			{
				e.Parameters.Add("sreportno", cxvParameterPropertyData.Value);
			}
			DisplayForm(e);
		}

		private void cmdPropSets_CommandExecute(object parameter)
		{
			CxvParameterPropertyData cxvParameterPropertyData = mnbReportNo_var2 as CxvParameterPropertyData;
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_SupPro",
				LegacyFlags = 0,
				HelpId = 306,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Supple_Display3,
				PreferredHeight = 300,
				ResizeMode = ResizeMode.CanResize
			};
			if (cxvParameterPropertyData != null)
			{
				e.Parameters.Add("sreportno", cxvParameterPropertyData.Value);
			}
			DisplayForm(e);
		}

		private void cmdAttribute_CommandExecute(object parameter)
		{
			CxvParameterPropertyData cxvParameterPropertyData = mnbReportNo_var2 as CxvParameterPropertyData;
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_SAttri",
				LegacyFlags = 0,
				HelpId = 307,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Supple_Display4
			};
			if (cxvParameterPropertyData != null)
			{
				e.Parameters.Add("sreportno", cxvParameterPropertyData.Value);
			}
			DisplayForm(e);
		}

		private void cmdSubr_CommandExecute(object parameter)
		{
			CxvParameterPropertyData cxvParameterPropertyData = mnbReportNo_var2 as CxvParameterPropertyData;
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Report_SupSub",
				LegacyFlags = 0,
				HelpId = 308,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Report_Supple_Display5
			};
			if (cxvParameterPropertyData != null)
			{
				e.Parameters.Add("sreportno", cxvParameterPropertyData.Value);
			}
			DisplayForm(e);
		}

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_Supple")]
	public class MMSetup_Report_Supple : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbReportNo_label;

		internal MMAdvancedComboEdit mnbReportNo;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkSReport;

		internal MMCmdButton cmdStream;

		internal MMCmdButton cmdExcludeStream;

		internal MMGroupBox fraItems;

		internal MMGroupBox fraFlowBasis;

		internal MMCheckBox chkSFlowMole;

		internal MMCheckBox chkSFlowMass;

		internal MMCheckBox chkSFlowStd;

		internal MMGroupBox fraFracBasis;

		internal MMCheckBox chkSFracMole;

		internal MMCheckBox chkSFracMass;

		internal MMCheckBox chkSFracStd;

		internal MMOptionGroup opgSWide;

		internal MMOptionButton opgSWide_opt0;

		internal MMOptionButton opgSWide_opt1;

		internal MMCheckBox chkSSort;

		internal MMCheckBox chkSZero;

		internal MMCmdButton cmdPropSets;

		internal MMCmdButton cmdAttribute;

		internal MMCmdButton cmdSubr;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_Supple()
		{
			base.ViewModelType = typeof(MMSetup_Report_Supple_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_supple.xaml", UriKind.Relative);
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
				mnbReportNo_label = (MMLabel)target;
				break;
			case 2:
				mnbReportNo = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 4:
				chkSReport = (MMCheckBox)target;
				break;
			case 5:
				cmdStream = (MMCmdButton)target;
				break;
			case 6:
				cmdExcludeStream = (MMCmdButton)target;
				break;
			case 7:
				fraItems = (MMGroupBox)target;
				break;
			case 8:
				fraFlowBasis = (MMGroupBox)target;
				break;
			case 9:
				chkSFlowMole = (MMCheckBox)target;
				break;
			case 10:
				chkSFlowMass = (MMCheckBox)target;
				break;
			case 11:
				chkSFlowStd = (MMCheckBox)target;
				break;
			case 12:
				fraFracBasis = (MMGroupBox)target;
				break;
			case 13:
				chkSFracMole = (MMCheckBox)target;
				break;
			case 14:
				chkSFracMass = (MMCheckBox)target;
				break;
			case 15:
				chkSFracStd = (MMCheckBox)target;
				break;
			case 16:
				opgSWide = (MMOptionGroup)target;
				break;
			case 17:
				opgSWide_opt0 = (MMOptionButton)target;
				break;
			case 18:
				opgSWide_opt1 = (MMOptionButton)target;
				break;
			case 19:
				chkSSort = (MMCheckBox)target;
				break;
			case 20:
				chkSZero = (MMCheckBox)target;
				break;
			case 21:
				cmdPropSets = (MMCmdButton)target;
				break;
			case 22:
				cmdAttribute = (MMCmdButton)target;
				break;
			case 23:
				cmdSubr = (MMCmdButton)target;
				break;
			case 24:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_SupPro_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lstpSupPropSet_var1_Property = CxvPropertyDeclaration.Register("lstpSupPropSet_var1", typeof(MMSetup_Report_SupPro_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_PROPS.@sreportno",
			AllowSort = false
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object lstpSupPropSet_var1 => GetValue(lstpSupPropSet_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_SupPro")]
	public class MMSetup_Report_SupPro : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpSupPropSet;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_SupPro()
		{
			base.ViewModelType = typeof(MMSetup_Report_SupPro_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_suppro.xaml", UriKind.Relative);
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
				lstpSupPropSet = (MMListPicker)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Report_SupSub_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMSetup_Report_SupSub_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.HEADING.@sreportno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Report_SupSub_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Stream-Report.Input.SUBROUTINE.@sreportno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Report_SupSub")]
	public class MMSetup_Report_SupSub : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMTextEdit MMTextBox1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Report_SupSub()
		{
			base.ViewModelType = typeof(MMSetup_Report_SupSub_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_report_supsub.xaml", UriKind.Relative);
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
				MMLBUText1_label = (MMLabel)target;
				break;
			case 2:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 3:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 4:
				MMTextBox1 = (MMTextEdit)target;
				break;
			case 5:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accoun_Property = CxvPropertyDeclaration.Register("accoun", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.CC Nodes.MAIN1"
		});

		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.GLMAIN"
		});

		public static readonly CxvPropertyDeclaration entglb_Property = CxvPropertyDeclaration.Register("entglb", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Global.CC Nodes.ENTGLOBAL"
		});

		public static readonly CxvPropertyDeclaration entacc_Property = CxvPropertyDeclaration.Register("entacc", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.CC Nodes.ENTACCOUN"
		});

		public static readonly CxvPropertyDeclaration entstr_Property = CxvPropertyDeclaration.Register("entstr", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ENTSTREAM"
		});

		public static readonly CxvPropertyDeclaration entdg_Property = CxvPropertyDeclaration.Register("entdg", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration entdes_Property = CxvPropertyDeclaration.Register("entdes", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Description.CC Nodes.ENTDESC"
		});

		public static readonly CxvPropertyDeclaration enetit_Property = CxvPropertyDeclaration.Register("enetit", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ENTTITLE"
		});

		public static readonly CxvPropertyDeclaration entphs_Property = CxvPropertyDeclaration.Register("entphs", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTPHASE"
		});

		public static readonly CxvPropertyDeclaration visited_Property = CxvPropertyDeclaration.Register("visited", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.VISITED"
		});

		public static readonly CxvPropertyDeclaration entmeth_Property = CxvPropertyDeclaration.Register("entmeth", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTSMETH"
		});

		public static readonly CxvPropertyDeclaration GLOBL_Property = CxvPropertyDeclaration.Register("GLOBL", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.GLOBL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global", "@GLOBL" },
			EnteredDataPaths = { "@enetit", "@entglb", "@entmeth", "@entphs" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdes" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@accoun" },
			EnteredDataPaths = { "@entacc" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdg" }
		});

		public object accoun => GetValue(accoun_Property);

		public object global => GetValue(global_Property);

		public object entglb => GetValue(entglb_Property);

		public object entacc => GetValue(entacc_Property);

		public object entstr => GetValue(entstr_Property);

		public object entdg => GetValue(entdg_Property);

		public object entdes => GetValue(entdes_Property);

		public object enetit => GetValue(enetit_Property);

		public object entphs => GetValue(entphs_Property);

		public object visited => GetValue(visited_Property);

		public object entmeth => GetValue(entmeth_Property);

		public object GLOBL => GetValue(GLOBL_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
				ResolveUpdateParameter("extraComments_path", "Main.Comments");
				ResolveUpdateParameter("extraDescription_path", "Main.Input.DESCRIPTION");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_Setup")]
	public class MMSetup_Setup : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabSetup;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_Setup()
		{
			base.ViewModelType = typeof(MMSetup_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup.xaml", UriKind.Relative);
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
				tabSetup = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Accoun_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuProjId_var1_Property = CxvPropertyDeclaration.Register("lbtuProjId_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.Input.PROJECT_ID",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuProjName_var1_Property = CxvPropertyDeclaration.Register("lbtuProjName_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.Input.PROJECT_NAME",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuAccount_var1_Property = CxvPropertyDeclaration.Register("lbtuAccount_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.Input.ACCOUNT",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuUsName_var1_Property = CxvPropertyDeclaration.Register("lbtuUsName_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.Input.USER_NAME",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration fraHeader_var1_Property = CxvPropertyDeclaration.Register("fraHeader_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvParameterProperty
		{
			Parameter = "HeaderLabel"
		});

		public object lbtuProjId_var1 => GetValue(lbtuProjId_var1_Property);

		public object lbtuProjName_var1 => GetValue(lbtuProjName_var1_Property);

		public object lbtuAccount_var1 => GetValue(lbtuAccount_var1_Property);

		public object lbtuUsName_var1 => GetValue(lbtuUsName_var1_Property);

		public object fraHeader_var1 => GetValue(fraHeader_var1_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("HeaderLabel", WpfFormsResources.MMSetup_Setup_Accoun_Dispaly1);
				}
				else
				{
					ResolveUpdateParameter("HeaderLabel", WpfFormsResources.MMSetup_Setup_Accoun_Dispaly2);
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Setup_Accoun")]
	public class MMSetup_Setup_Accoun : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuUsName_label;

		internal MMVariableEdit lbtuUsName;

		internal MMLabel lbtuAccount_label;

		internal MMVariableEdit lbtuAccount;

		internal MMLabel lbtuProjId_label;

		internal MMVariableEdit lbtuProjId;

		internal MMLabel lbtuProjName_label;

		internal MMVariableEdit lbtuProjName;

		private bool _contentLoaded;

		public MMSetup_Setup_Accoun()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Accoun_ViewModel);
			InitializeComponent();
			lbtuUsName.LostFocus += lbtuUsName_LostFocus;
		}

		private void lbtuUsName_LostFocus(object sender, RoutedEventArgs e)
		{
			if (lbtuUsName.Value != null && string.IsNullOrWhiteSpace(lbtuUsName.Value.ToString()))
			{
				lbtuUsName.Value = null;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_accoun.xaml", UriKind.Relative);
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
				lbtuUsName_label = (MMLabel)target;
				break;
			case 2:
				lbtuUsName = (MMVariableEdit)target;
				break;
			case 3:
				lbtuAccount_label = (MMLabel)target;
				break;
			case 4:
				lbtuAccount = (MMVariableEdit)target;
				break;
			case 5:
				lbtuProjId_label = (MMLabel)target;
				break;
			case 6:
				lbtuProjId = (MMVariableEdit)target;
				break;
			case 7:
				lbtuProjName_label = (MMLabel)target;
				break;
			case 8:
				lbtuProjName = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Descri_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMDescription1_var1_Property = CxvPropertyDeclaration.Register("MMDescription1_var1", typeof(MMSetup_Setup_Descri_ViewModel), new CxvDescriptionProperty
		{
			DataPath = "@main.Description.Input.DESCRIP"
		});

		public object MMDescription1_var1 => GetValue(MMDescription1_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Setup_Descri")]
	public class MMSetup_Setup_Descri : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDesc;

		internal MMDescription MMDescription1;

		private bool _contentLoaded;

		public MMSetup_Setup_Descri()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Descri_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_descri.xaml", UriKind.Relative);
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
				fraDesc = (MMGroupBox)target;
				break;
			case 2:
				MMDescription1 = (MMDescription)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Diagno_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdDialogOptions_Command;

		private ICommand _cmdHistoryOptions_Command;

		public static readonly CxvPropertyDeclaration dsldConverg_var1_Property = CxvPropertyDeclaration.Register("dsldConverg_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_CONV_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldConverg_var2_Property = CxvPropertyDeclaration.Register("dsldConverg_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.CONV_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldStream_var1_Property = CxvPropertyDeclaration.Register("dsldStream_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_STRM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldStream_var2_Property = CxvPropertyDeclaration.Register("dsldStream_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.STREAM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldPhysical_var1_Property = CxvPropertyDeclaration.Register("dsldPhysical_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldPhysical_var2_Property = CxvPropertyDeclaration.Register("dsldPhysical_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldSimulation_var1_Property = CxvPropertyDeclaration.Register("dsldSimulation_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldSimulation_var2_Property = CxvPropertyDeclaration.Register("dsldSimulation_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldInputTrans_var1_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_SYS_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldInputTrans_var2_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SYS_LEVEL"
		});

		public ICommand cmdDialogOptions_Command
		{
			get
			{
				if (_cmdDialogOptions_Command == null)
				{
					_cmdDialogOptions_Command = new CxvDelegateCommand<object>(cmdDialogOptions_CommandExecute);
				}
				return _cmdDialogOptions_Command;
			}
		}

		public ICommand cmdHistoryOptions_Command
		{
			get
			{
				if (_cmdHistoryOptions_Command == null)
				{
					_cmdHistoryOptions_Command = new CxvDelegateCommand<object>(cmdHistoryOptions_CommandExecute);
				}
				return _cmdHistoryOptions_Command;
			}
		}

		public object dsldConverg_var1 => GetValue(dsldConverg_var1_Property);

		public object dsldConverg_var2 => GetValue(dsldConverg_var2_Property);

		public object dsldStream_var1 => GetValue(dsldStream_var1_Property);

		public object dsldStream_var2 => GetValue(dsldStream_var2_Property);

		public object dsldPhysical_var1 => GetValue(dsldPhysical_var1_Property);

		public object dsldPhysical_var2 => GetValue(dsldPhysical_var2_Property);

		public object dsldSimulation_var1 => GetValue(dsldSimulation_var1_Property);

		public object dsldSimulation_var2 => GetValue(dsldSimulation_var2_Property);

		public object dsldInputTrans_var1 => GetValue(dsldInputTrans_var1_Property);

		public object dsldInputTrans_var2 => GetValue(dsldInputTrans_var2_Property);

		private void cmdDialogOptions_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Setup_Dialog",
				LegacyFlags = 0,
				HelpId = 290,
				HelpFile = "setup.hlp",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Setup_Diagno_Display1
			});
		}

		private void cmdHistoryOptions_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Setup_Histor",
				LegacyFlags = 0,
				HelpId = 5048,
				HelpFile = "setup.chm",
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMSetup_Setup_Diagno_Display2
			});
		}
	}
	[ProgId("MMSetup.MMSetup_Setup_Diagno")]
	public class MMSetup_Setup_Diagno : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lbltermerrors;

		internal MMLabel lblUp0;

		internal MMLabel lblUp4;

		internal MMLabel lblUp10;

		internal MMLabel lblFulldiagnostics;

		internal MMLabel lblDiagInputTrans;

		internal MMDoubleSlider dsldInputTrans;

		internal MMLabel lblControlPanel;

		internal MMLabel lblDiagSimulation;

		internal MMDoubleSlider dsldSimulation;

		internal MMDoubleSlider dsldSpecimen;

		internal MMLabel lblDiagPhysical;

		internal MMDoubleSlider dsldPhysical;

		internal MMLabel lblHistotyFile;

		internal MMLabel lblDiagStream;

		internal MMDoubleSlider dsldStream;

		internal MMCmdButton cmdDialogOptions;

		internal MMLabel lblDiagConverg;

		internal MMDoubleSlider dsldConverg;

		internal MMCmdButton cmdHistoryOptions;

		internal MMLabel lblDown0;

		internal MMLabel lblDown4;

		internal MMLabel lblDown10;

		private bool _contentLoaded;

		public MMSetup_Setup_Diagno()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Diagno_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_diagno.xaml", UriKind.Relative);
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
				fraDiag = (MMGroupBox)target;
				break;
			case 2:
				lbltermerrors = (MMLabel)target;
				break;
			case 3:
				lblUp0 = (MMLabel)target;
				break;
			case 4:
				lblUp4 = (MMLabel)target;
				break;
			case 5:
				lblUp10 = (MMLabel)target;
				break;
			case 6:
				lblFulldiagnostics = (MMLabel)target;
				break;
			case 7:
				lblDiagInputTrans = (MMLabel)target;
				break;
			case 8:
				dsldInputTrans = (MMDoubleSlider)target;
				break;
			case 9:
				lblControlPanel = (MMLabel)target;
				break;
			case 10:
				lblDiagSimulation = (MMLabel)target;
				break;
			case 11:
				dsldSimulation = (MMDoubleSlider)target;
				break;
			case 12:
				dsldSpecimen = (MMDoubleSlider)target;
				break;
			case 13:
				lblDiagPhysical = (MMLabel)target;
				break;
			case 14:
				dsldPhysical = (MMDoubleSlider)target;
				break;
			case 15:
				lblHistotyFile = (MMLabel)target;
				break;
			case 16:
				lblDiagStream = (MMLabel)target;
				break;
			case 17:
				dsldStream = (MMDoubleSlider)target;
				break;
			case 18:
				cmdDialogOptions = (MMCmdButton)target;
				break;
			case 19:
				lblDiagConverg = (MMLabel)target;
				break;
			case 20:
				dsldConverg = (MMDoubleSlider)target;
				break;
			case 21:
				cmdHistoryOptions = (MMCmdButton)target;
				break;
			case 22:
				lblDown0 = (MMLabel)target;
				break;
			case 23:
				lblDown4 = (MMLabel)target;
				break;
			case 24:
				lblDown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Dialog_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration dsldFortran_var1_Property = CxvPropertyDeclaration.Register("dsldFortran_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.TVAR_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldFortran_var2_Property = CxvPropertyDeclaration.Register("dsldFortran_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.VAR_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldCost_var1_Property = CxvPropertyDeclaration.Register("dsldCost_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_COST_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldCost_var2_Property = CxvPropertyDeclaration.Register("dsldCost_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.COST_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldEcono_var1_Property = CxvPropertyDeclaration.Register("dsldEcono_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_ECON_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldEcono_var2_Property = CxvPropertyDeclaration.Register("dsldEcono_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.ECON_LEVEL"
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object dsldFortran_var1 => GetValue(dsldFortran_var1_Property);

		public object dsldFortran_var2 => GetValue(dsldFortran_var2_Property);

		public object dsldCost_var1 => GetValue(dsldCost_var1_Property);

		public object dsldCost_var2 => GetValue(dsldCost_var2_Property);

		public object dsldEcono_var1 => GetValue(dsldEcono_var1_Property);

		public object dsldEcono_var2 => GetValue(dsldEcono_var2_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Setup_Dialog")]
	public class MMSetup_Setup_Dialog : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lbltermerrors;

		internal MMLabel lblFulldiagnostics;

		internal MMLabel lblUp0;

		internal MMLabel lblUp4;

		internal MMLabel lblUp10;

		internal MMLabel lblDiagFortran;

		internal MMDoubleSlider dsldFortran;

		internal MMLabel lblDiagCost;

		internal MMDoubleSlider dsldCost;

		internal MMLabel lblDiagEconomic;

		internal MMDoubleSlider dsldEcono;

		internal MMLabel lblDown0;

		internal MMLabel lblDown4;

		internal MMLabel lblDown10;

		internal MMLabel lblControlPanel;

		internal MMDoubleSlider dsldSpecimen;

		internal MMLabel lblHistotyFile;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Setup_Dialog()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Dialog_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_dialog.xaml", UriKind.Relative);
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
				fraDiag = (MMGroupBox)target;
				break;
			case 2:
				lbltermerrors = (MMLabel)target;
				break;
			case 3:
				lblFulldiagnostics = (MMLabel)target;
				break;
			case 4:
				lblUp0 = (MMLabel)target;
				break;
			case 5:
				lblUp4 = (MMLabel)target;
				break;
			case 6:
				lblUp10 = (MMLabel)target;
				break;
			case 7:
				lblDiagFortran = (MMLabel)target;
				break;
			case 8:
				dsldFortran = (MMDoubleSlider)target;
				break;
			case 9:
				lblDiagCost = (MMLabel)target;
				break;
			case 10:
				dsldCost = (MMDoubleSlider)target;
				break;
			case 11:
				lblDiagEconomic = (MMLabel)target;
				break;
			case 12:
				dsldEcono = (MMDoubleSlider)target;
				break;
			case 13:
				lblDown0 = (MMLabel)target;
				break;
			case 14:
				lblDown4 = (MMLabel)target;
				break;
			case 15:
				lblDown10 = (MMLabel)target;
				break;
			case 16:
				lblControlPanel = (MMLabel)target;
				break;
			case 17:
				dsldSpecimen = (MMDoubleSlider)target;
				break;
			case 18:
				lblHistotyFile = (MMLabel)target;
				break;
			case 19:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Global_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUOpyr_var1_Property = CxvPropertyDeclaration.Register("MMLBUOpyr_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.OPER_YEAR"
		});

		public static readonly CxvPropertyDeclaration MMLBUOpyr_var2_Property = CxvPropertyDeclaration.Register("MMLBUOpyr_var2", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.OPER_YEAR"
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_var1",
					DataPath = "@main.Main.Input.FREE_WATER"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Dirty water",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Dirty_water",
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration LbtuTamb_tambeqp_Property = CxvPropertyDeclaration.Register("LbtuTamb_tambeqp", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.TAMBEQP",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Main.CC Nodes.ENTAMB"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Global.Input.SCLASS"
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox4_var1",
					DataPath = "@main.Global.Input.BASIS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Mass",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Mass",
					Value = "MMComboBox4_MultiMapOption_1",
					Prompt = "Mass flow.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Mass_flow_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "MASS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Mole",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Mole",
					Value = "MMComboBox4_MultiMapOption_2",
					Prompt = "Mole flow.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Mole_flow_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "MOLE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "StdVol",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_StdVol",
					Value = "MMComboBox4_MultiMapOption_3",
					Prompt = "Standard volume flow.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Standard_volume_flow_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "STDVOL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.ATM_PRES"
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var2_Property = CxvPropertyDeclaration.Register("lbtuTemp_var2", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.ATM_PRES"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main.Main.Input.RUN_CLASS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Assay Data Analysis",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Assay_Data_Analysis",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "ADA"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Data Regression",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Data_Regression",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "DRS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Flowsheet",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Flowsheet",
					Value = "MMComboBox1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "FLOWSHEET"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Properties Plus",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Properties_Plus",
					Value = "MMComboBox1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "PROP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Property Analysis",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Property_Analysis",
					Value = "MMComboBox1_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "TGS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Property Estimation",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Property_Estimation",
					Value = "MMComboBox1_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "PCES"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboInpMode_var1_Property = CxvPropertyDeclaration.Register("cboInpMode_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Main.Input.INPUT_MODE",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuTitle_var1_Property = CxvPropertyDeclaration.Register("lbtuTitle_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.TITLE"
		});

		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
		{
			Prompt = "Valid phases to be considered in calculations. If left blank, the default is block-dependent. See Valid Phases in individual blocks for details.",
			PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapProperty_Prompt_Valid_phases_to_be_considered_in_calculations_",
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Sim-Options.Input.NPHASE"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Sim-Options.Input.PHASE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var2",
							Value = "V"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var2",
							Value = "L"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var1",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var1",
							Value = "3"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var2"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboInputData_var1_Property = CxvPropertyDeclaration.Register("cboInputData_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Global.Input.INSET",
			AllowNew = false
		});

		private bool _rentry;

		public object MMLBUOpyr_var1 => GetValue(MMLBUOpyr_var1_Property);

		public object MMLBUOpyr_var2 => GetValue(MMLBUOpyr_var2_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object LbtuTamb_tambeqp => GetValue(LbtuTamb_tambeqp_Property);

		public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

		public object MMComboBox4_MultiMap => GetValue(MMComboBox4_MultiMap_Property);

		public object lbtuTemp_var1 => GetValue(lbtuTemp_var1_Property);

		public object lbtuTemp_var2 => GetValue(lbtuTemp_var2_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object cboInpMode_var1 => GetValue(cboInpMode_var1_Property);

		public object lbtuTitle_var1 => GetValue(lbtuTitle_var1_Property);

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object cboInputData_var1 => GetValue(cboInputData_var1_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Metadata.Name == "MMComboBox4_MultiMap" && subPropertyName == "Value" && CxsConverter.ValueToString(this.ResolveViewPropertyPath("MMComboBox1_MultiMap.Value")) == "MMComboBox1_MultiMapOption_3")
			{
				string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Global.Input.BASIS", "value"));
				try
				{
					switch (text)
					{
					case "MOLE":
						if (string.Compare(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.ReportOptions.Stream-Report.Input.MOLEFLOW", "value")), "MOLEFLOW", StringComparison.Ordinal) != 0)
						{
							ExpandDataPathAndSet("@main.ReportOptions.Stream-Report.Input.MOLEFLOW", "value", "MOLEFLOW");
						}
						break;
					case "MASS":
						if (string.Compare(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.ReportOptions.Stream-Report.Input.MASSFLOW", "value")), "MASSFLOW", StringComparison.Ordinal) != 0)
						{
							ExpandDataPathAndSet("@main.ReportOptions.Stream-Report.Input.MASSFLOW", "value", "MASSFLOW");
						}
						break;
					case "STDVOL":
						if (string.Compare(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.ReportOptions.Stream-Report.Input.STDVOLFLOW", "value")), "STDVOLFLOW", StringComparison.Ordinal) != 0)
						{
							ExpandDataPathAndSet("@main.ReportOptions.Stream-Report.Input.STDVOLFLOW", "value", "STDVOLFLOW");
						}
						break;
					}
				}
				catch (Exception)
				{
				}
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		protected override void OnUpdateData()
		{
			if (_rentry)
			{
				return;
			}
			_rentry = true;
			if (base.IsInitialUpdate)
			{
				string path = ExpandDataPath("@main") + ".Main.Input.VISITED";
				if ((CxsConverter.ValueToInt32(base.ResolvedCxsProvider.BatchGet(path, "value", null)) ?? 0) == 0)
				{
					base.ResolvedCxsProvider.BatchSet(path, "value", null, 1);
				}
			}
			base.OnUpdateData();
			_rentry = false;
		}
	}
	[ProgId("MMSetup.MMSetup_Setup_Global")]
	public class MMSetup_Setup_Global : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuTitle_label;

		internal MMVariableEdit lbtuTitle;

		internal MMLabel cboInputData_label;

		internal MMComboEdit cboInputData;

		internal MMGroupBox fraGlobalSett;

		internal MMLabel cboInpMode_label;

		internal MMComboEdit cboInpMode;

		internal MMLabel MMComboBox3_label;

		internal MMComboEdit MMComboBox3;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMLabel lbtuTemp_label;

		internal MMVariableEdit lbtuTemp;

		internal MMLabel LbtuTamb_label;

		internal MMVariableEdit LbtuTamb;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMLBUOpyr_label;

		internal MMVariableEdit MMLBUOpyr;

		private bool _contentLoaded;

		public MMSetup_Setup_Global()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Global_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_global.xaml", UriKind.Relative);
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
				lbtuTitle_label = (MMLabel)target;
				break;
			case 2:
				lbtuTitle = (MMVariableEdit)target;
				break;
			case 3:
				cboInputData_label = (MMLabel)target;
				break;
			case 4:
				cboInputData = (MMComboEdit)target;
				break;
			case 5:
				fraGlobalSett = (MMGroupBox)target;
				break;
			case 6:
				cboInpMode_label = (MMLabel)target;
				break;
			case 7:
				cboInpMode = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 12:
				lbtuTemp_label = (MMLabel)target;
				break;
			case 13:
				lbtuTemp = (MMVariableEdit)target;
				break;
			case 14:
				LbtuTamb_label = (MMLabel)target;
				break;
			case 15:
				LbtuTamb = (MMVariableEdit)target;
				break;
			case 16:
				cboPhase_label = (MMLabel)target;
				break;
			case 17:
				cboPhase = (MMComboEdit)target;
				break;
			case 18:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 19:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 20:
				MMLBUOpyr_label = (MMLabel)target;
				break;
			case 21:
				MMLBUOpyr = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Setup_Histor_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration chkEchoInsert_var1_Property = CxvPropertyDeclaration.Register("chkEchoInsert_var1", typeof(MMSetup_Setup_Histor_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Diagnostics.Input.INSERT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Setup_Histor_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Diagnostics.Input.SORTED",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object chkEchoInsert_var1 => GetValue(chkEchoInsert_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Setup_Histor")]
	public class MMSetup_Setup_Histor : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPrintHistory;

		internal MMCheckBox chkEchoInsert;

		internal MMCheckBox MMCheckBox1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Setup_Histor()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Histor_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_setup_histor.xaml", UriKind.Relative);
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
				fraPrintHistory = (MMGroupBox)target;
				break;
			case 2:
				chkEchoInsert = (MMCheckBox)target;
				break;
			case 3:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 4:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration calc_Property = CxvPropertyDeclaration.Register("calc", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entclc_Property = CxvPropertyDeclaration.Register("entclc", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration entsys_Property = CxvPropertyDeclaration.Register("entsys", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sys-Options.CC Nodes.ENTSYSTEM"
		});

		public static readonly CxvPropertyDeclaration entlim_Property = CxvPropertyDeclaration.Register("entlim", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.CC Nodes.ENTLIMIT"
		});

		public static readonly CxvPropertyDeclaration entmx_Property = CxvPropertyDeclaration.Register("entmx", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.CC Nodes.ENTMAX"
		});

		public static readonly CxvPropertyDeclaration entrea_Property = CxvPropertyDeclaration.Register("entrea", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTREAC"
		});

		public static readonly CxvPropertyDeclaration entsmlim_Property = CxvPropertyDeclaration.Register("entsmlim", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTSMLIM"
		});

		public static readonly CxvPropertyDeclaration entresl_Property = CxvPropertyDeclaration.Register("entresl", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTRESL"
		});

		public static readonly CxvPropertyDeclaration entmodop_Property = CxvPropertyDeclaration.Register("entmodop", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Model-Option.CC Nodes.ENTMODOP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entclc" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@calc" },
			EnteredDataPaths = { "@entfls" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entmodop" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entresl" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsys" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entlim", "@entmx", "@entsmlim" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entrea" }
		});

		public object calc => GetValue(calc_Property);

		public object entclc => GetValue(entclc_Property);

		public object entfls => GetValue(entfls_Property);

		public object entsys => GetValue(entsys_Property);

		public object entlim => GetValue(entlim_Property);

		public object entmx => GetValue(entmx_Property);

		public object entrea => GetValue(entrea_Property);

		public object entsmlim => GetValue(entsmlim_Property);

		public object entresl => GetValue(entresl_Property);

		public object entmodop => GetValue(entmodop_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt")]
	public class MMSetup_Simopt : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabSetup;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab6;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMSetup_Simopt()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt.xaml", UriKind.Relative);
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
				tabSetup = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab1 = (MMTabItem)target;
				break;
			case 4:
				tab6 = (MMTabItem)target;
				break;
			case 5:
				tab2 = (MMTabItem)target;
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Calcul_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText2_var2_Property = CxvPropertyDeclaration.Register("MMLBUText2_var2", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.REF_TEMP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var3_Property = CxvPropertyDeclaration.Register("MMLBUText3_var3", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.REF_PRES"
		});

		public static readonly CxvPropertyDeclaration lbtuInitgparam_var1_Property = CxvPropertyDeclaration.Register("lbtuInitgparam_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.INIT_GPARAM"
		});

		public static readonly CxvPropertyDeclaration MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.DUMPXML",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.ADSCNVG",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Multimap_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ComboBox1_var1",
					DataPath = "@main.Sim-Options.Input.PACKING_DB"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Latest",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_latest_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "LATEST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "V2006",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v2006_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "V2006"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "V2006.5",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v2006_5_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "V2006.5"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "V7",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v7_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "V7"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "V7.2",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v7_2_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "V7.2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "V9.0",
					Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v9_0_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ComboBox1_var1",
							Value = "V9.0"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration chkDBChk_var1_Property = CxvPropertyDeclaration.Register("chkDBChk_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.OLD_DATABANK",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.PROP_DERIV",
			TrueValue = "ANALYTICAL",
			FalseValue = "NUMERICAL",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.DN_REQUIRED",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.DX_REQUIRED",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.SOLID_DERIV",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox5_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox5_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.ENG_ELECPAR",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration lbtuXwH2ophase_var1_Property = CxvPropertyDeclaration.Register("lbtuXwH2ophase_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.XW_H2OPHASE"
		});

		public static readonly CxvPropertyDeclaration chkBypass_var1_Property = CxvPropertyDeclaration.Register("chkBypass_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.BYPASS_PROP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkRestart_var1_Property = CxvPropertyDeclaration.Register("chkRestart_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.RESTART",
			TrueValue = "NO",
			FalseValue = "YES",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkMwCalc_var1_Property = CxvPropertyDeclaration.Register("chkMwCalc_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.MW_CALC",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkEnryBal_var1_Property = CxvPropertyDeclaration.Register("chkEnryBal_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.ENERGY_BAL",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public object MMLBUText2_var2 => GetValue(MMLBUText2_var2_Property);

		public object MMLBUText3_var3 => GetValue(MMLBUText3_var3_Property);

		public object lbtuInitgparam_var1 => GetValue(lbtuInitgparam_var1_Property);

		public object MMCheckBox6_var1 => GetValue(MMCheckBox6_var1_Property);

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Multimap_Property);

		public object chkDBChk_var1 => GetValue(chkDBChk_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox3_var1 => GetValue(MMCheckBox3_var1_Property);

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object MMCheckBox5_var1 => GetValue(MMCheckBox5_var1_Property);

		public object lbtuXwH2ophase_var1 => GetValue(lbtuXwH2ophase_var1_Property);

		public object chkBypass_var1 => GetValue(chkBypass_var1_Property);

		public object chkRestart_var1 => GetValue(chkRestart_var1_Property);

		public object chkMwCalc_var1 => GetValue(chkMwCalc_var1_Property);

		public object chkEnryBal_var1 => GetValue(chkEnryBal_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_Calcul")]
	public class MMSetup_Simopt_Calcul : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraCalc;

		internal MMCheckBox chkEnryBal;

		internal MMCheckBox chkDBChk;

		internal MMCheckBox chkMwCalc;

		internal MMCheckBox chkRestart;

		internal MMCheckBox chkBypass;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox2;

		internal MMCheckBox MMCheckBox3;

		internal MMCheckBox MMCheckBox4;

		internal MMCheckBox MMCheckBox5;

		internal MMCheckBox MMCheckBox6;

		internal MMTextBlock lbtuXwH2ophase_label;

		internal MMVariableEdit lbtuXwH2ophase;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel lbtuInitgparam_label;

		internal MMVariableEdit lbtuInitgparam;

		private bool _contentLoaded;

		public MMSetup_Simopt_Calcul()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_Calcul_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_calcul.xaml", UriKind.Relative);
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
				fraCalc = (MMGroupBox)target;
				break;
			case 2:
				chkEnryBal = (MMCheckBox)target;
				break;
			case 3:
				chkDBChk = (MMCheckBox)target;
				break;
			case 4:
				chkMwCalc = (MMCheckBox)target;
				break;
			case 5:
				chkRestart = (MMCheckBox)target;
				break;
			case 6:
				chkBypass = (MMCheckBox)target;
				break;
			case 7:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 8:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 9:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 10:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			case 11:
				MMCheckBox5 = (MMCheckBox)target;
				break;
			case 12:
				MMCheckBox6 = (MMCheckBox)target;
				break;
			case 13:
				lbtuXwH2ophase_label = (MMTextBlock)target;
				break;
			case 14:
				lbtuXwH2ophase = (MMVariableEdit)target;
				break;
			case 15:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 17:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 18:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 19:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 20:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 21:
				lbtuInitgparam_label = (MMLabel)target;
				break;
			case 22:
				lbtuInitgparam = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Flashc_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.FLASH_PSEUDO",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration cboFlashMethod_MultiMap_Property = CxvPropertyDeclaration.Register("cboFlashMethod_MultiMap", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboFlashMethod_var1",
					DataPath = "@main.Sim-Options.Input.FLASH_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Inside-Out",
					DisplayResourceKey = "MMSetup_Simopt_Flashc_ViewModel__CxvMultiMapOption_Display_Inside_Out",
					Value = "cboFlashMethod_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboFlashMethod_var1",
							Value = "INSIDE-OUT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Gibbs",
					DisplayResourceKey = "MMSetup_Simopt_Flashc_ViewModel__CxvMultiMapOption_Display_Gibbs",
					Value = "cboFlashMethod_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboFlashMethod_var1",
							Value = "GIBBS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_User",
					Value = "cboFlashMethod_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboFlashMethod_var1",
							Value = "USER"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.NEW_SPLIT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.FLASH3_OPT",
			TrueValue = "4PHASE",
			FalseValue = "3PHASE",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.HF_FL3_DAMP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.MAXSOL_CHECK",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.REFP_FLASH",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.TOL"
		});

		public static readonly CxvPropertyDeclaration lbtuTolFac_var1_Property = CxvPropertyDeclaration.Register("lbtuTolFac_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.FLASH_TOLFAC"
		});

		public static readonly CxvPropertyDeclaration lbtuMinTol_var1_Property = CxvPropertyDeclaration.Register("lbtuMinTol_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.FLASH_MINTOL"
		});

		public static readonly CxvPropertyDeclaration lbtuMaxitx_var1_Property = CxvPropertyDeclaration.Register("lbtuMaxitx_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.FLASH_MAXITX"
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.MAXIT"
		});

		public static readonly CxvPropertyDeclaration lbtuRootExtr_var1_Property = CxvPropertyDeclaration.Register("lbtuRootExtr_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.ROOT_EXTR"
		});

		public static readonly CxvPropertyDeclaration lbtuLowPres_var1_Property = CxvPropertyDeclaration.Register("lbtuLowPres_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PLOWER"
		});

		public static readonly CxvPropertyDeclaration lbtuUpPres_var1_Property = CxvPropertyDeclaration.Register("lbtuUpPres_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PUPPER"
		});

		public static readonly CxvPropertyDeclaration lbtuLowTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuLowTemp_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.TLOWER"
		});

		public static readonly CxvPropertyDeclaration lbtuUpTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuUpTemp_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.TUPPER"
		});

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cboFlashMethod_MultiMap => GetValue(cboFlashMethod_MultiMap_Property);

		public object MMCheckBox3_var1 => GetValue(MMCheckBox3_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object lbtuTol_var1 => GetValue(lbtuTol_var1_Property);

		public object lbtuTolFac_var1 => GetValue(lbtuTolFac_var1_Property);

		public object lbtuMinTol_var1 => GetValue(lbtuMinTol_var1_Property);

		public object lbtuMaxitx_var1 => GetValue(lbtuMaxitx_var1_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);

		public object lbtuRootExtr_var1 => GetValue(lbtuRootExtr_var1_Property);

		public object lbtuLowPres_var1 => GetValue(lbtuLowPres_var1_Property);

		public object lbtuUpPres_var1 => GetValue(lbtuUpPres_var1_Property);

		public object lbtuLowTemp_var1 => GetValue(lbtuLowTemp_var1_Property);

		public object lbtuUpTemp_var1 => GetValue(lbtuUpTemp_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_Flashc")]
	public class MMSetup_Simopt_Flashc : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraTemp;

		internal MMLabel lbtuLowTemp_label;

		internal MMVariableEdit lbtuLowTemp;

		internal MMLabel lbtuUpTemp_label;

		internal MMVariableEdit lbtuUpTemp;

		internal MMGroupBox fraPress;

		internal MMLabel lbtuLowPres_label;

		internal MMVariableEdit lbtuLowPres;

		internal MMLabel lbtuUpPres_label;

		internal MMVariableEdit lbtuUpPres;

		internal MMGroupBox fraFlashConv;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTol_label;

		internal MMVariableEdit lbtuTol;

		internal MMLabel lbtuTolFac_label;

		internal MMVariableEdit lbtuTolFac;

		internal MMLabel lbtuMinTol_label;

		internal MMVariableEdit lbtuMinTol;

		internal MMLabel lbtuMaxitx_label;

		internal MMVariableEdit lbtuMaxitx;

		internal MMLabel lbtuRootExtr_label;

		internal MMLabel cboFlashMethod_label;

		internal MMVariableEdit lbtuRootExtr;

		internal MMComboEdit cboFlashMethod;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMCheckBox MMCheckBox7;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox2;

		internal MMCheckBox MMCheckBox3;

		internal MMCheckBox MMCheckBox4;

		private bool _contentLoaded;

		public MMSetup_Simopt_Flashc()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_Flashc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_flashc.xaml", UriKind.Relative);
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
				fraTemp = (MMGroupBox)target;
				break;
			case 2:
				lbtuLowTemp_label = (MMLabel)target;
				break;
			case 3:
				lbtuLowTemp = (MMVariableEdit)target;
				break;
			case 4:
				lbtuUpTemp_label = (MMLabel)target;
				break;
			case 5:
				lbtuUpTemp = (MMVariableEdit)target;
				break;
			case 6:
				fraPress = (MMGroupBox)target;
				break;
			case 7:
				lbtuLowPres_label = (MMLabel)target;
				break;
			case 8:
				lbtuLowPres = (MMVariableEdit)target;
				break;
			case 9:
				lbtuUpPres_label = (MMLabel)target;
				break;
			case 10:
				lbtuUpPres = (MMVariableEdit)target;
				break;
			case 11:
				fraFlashConv = (MMGroupBox)target;
				break;
			case 12:
				spnMaxit_label = (MMLabel)target;
				break;
			case 13:
				spnMaxit = (MMSpinBox)target;
				break;
			case 14:
				lbtuTol_label = (MMLabel)target;
				break;
			case 15:
				lbtuTol = (MMVariableEdit)target;
				break;
			case 16:
				lbtuTolFac_label = (MMLabel)target;
				break;
			case 17:
				lbtuTolFac = (MMVariableEdit)target;
				break;
			case 18:
				lbtuMinTol_label = (MMLabel)target;
				break;
			case 19:
				lbtuMinTol = (MMVariableEdit)target;
				break;
			case 20:
				lbtuMaxitx_label = (MMLabel)target;
				break;
			case 21:
				lbtuMaxitx = (MMVariableEdit)target;
				break;
			case 22:
				lbtuRootExtr_label = (MMLabel)target;
				break;
			case 23:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 24:
				lbtuRootExtr = (MMVariableEdit)target;
				break;
			case 25:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 26:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 27:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 28:
				MMCheckBox7 = (MMCheckBox)target;
				break;
			case 29:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 30:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 31:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 32:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Limits_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PACK_FRAC"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PACK_FLOW"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox4_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox4_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.PROP_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox2_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox2_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SYS_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox3_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox3_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SIM_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox1_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox1_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_FORT_ERR"
		});

		public static readonly CxvPropertyDeclaration lbtuMaxTime_var1_Property = CxvPropertyDeclaration.Register("lbtuMaxTime_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_TIME"
		});

		public static readonly CxvPropertyDeclaration spnSevErr_var1_Property = CxvPropertyDeclaration.Register("spnSevErr_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_ERRORS"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox6_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox6_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_FILESIZE"
		});

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMSpinBox4_var1 => GetValue(MMSpinBox4_var1_Property);

		public object MMSpinBox2_var1 => GetValue(MMSpinBox2_var1_Property);

		public object MMSpinBox3_var1 => GetValue(MMSpinBox3_var1_Property);

		public object MMSpinBox1_var1 => GetValue(MMSpinBox1_var1_Property);

		public object lbtuMaxTime_var1 => GetValue(lbtuMaxTime_var1_Property);

		public object spnSevErr_var1 => GetValue(spnSevErr_var1_Property);

		public object MMSpinBox6_var1 => GetValue(MMSpinBox6_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_Limits")]
	public class MMSetup_Simopt_Limits : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraTimeError;

		internal MMLabel lbtuMaxTime_label;

		internal MMVariableEdit lbtuMaxTime;

		internal MMLabel spnSevErr_label;

		internal MMSpinBox spnSevErr;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMSpinBox6_label;

		internal MMSpinBox MMSpinBox6;

		internal MMGroupBox fraHisFile;

		internal MMLabel MMSpinBox2_label;

		internal MMSpinBox MMSpinBox2;

		internal MMLabel MMSpinBox3_label;

		internal MMSpinBox MMSpinBox3;

		internal MMLabel MMSpinBox4_label;

		internal MMSpinBox MMSpinBox4;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		private bool _contentLoaded;

		public MMSetup_Simopt_Limits()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_Limits_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_limits.xaml", UriKind.Relative);
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
				fraTimeError = (MMGroupBox)target;
				break;
			case 2:
				lbtuMaxTime_label = (MMLabel)target;
				break;
			case 3:
				lbtuMaxTime = (MMVariableEdit)target;
				break;
			case 4:
				spnSevErr_label = (MMLabel)target;
				break;
			case 5:
				spnSevErr = (MMSpinBox)target;
				break;
			case 6:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 7:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 8:
				MMSpinBox6_label = (MMLabel)target;
				break;
			case 9:
				MMSpinBox6 = (MMSpinBox)target;
				break;
			case 10:
				fraHisFile = (MMGroupBox)target;
				break;
			case 11:
				MMSpinBox2_label = (MMLabel)target;
				break;
			case 12:
				MMSpinBox2 = (MMSpinBox)target;
				break;
			case 13:
				MMSpinBox3_label = (MMLabel)target;
				break;
			case 14:
				MMSpinBox3 = (MMSpinBox)target;
				break;
			case 15:
				MMSpinBox4_label = (MMLabel)target;
				break;
			case 16:
				MMSpinBox4 = (MMSpinBox)target;
				break;
			case 17:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 18:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 19:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 20:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 21:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Reactions_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.ELEC_CHK_TOL"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_gamusbasis",
					DataPath = "@main.Sim-Options.Input.GAMUS_BASIS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Aqueous",
					DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Aqueous",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_gamusbasis",
							Value = "AQUEOUS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Mixed-Solvent",
					DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Mixed_Solvent",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_gamusbasis",
							Value = "MIXED-SOLVENT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration ogrStioMbChe_MultiMap_Property = CxvPropertyDeclaration.Register("ogrStioMbChe_MultiMap", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrStioMbChe_var1",
					DataPath = "@main.Sim-Options.Input.STOIC_MB_CHE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Issue error when mass imbalance occurs",
					DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Issue_error_when_mass_imbalance_occurs",
					Value = "ogrStioMbChe_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrStioMbChe_var1",
							Value = "ERROR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Issue warning when mass imbalance occurs",
					DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Issue_warning_when_mass_imbalance_occu",
					Value = "ogrStioMbChe_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrStioMbChe_var1",
							Value = "WARNING"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuStoicTol_var1_Property = CxvPropertyDeclaration.Register("lbtuStoicTol_var1", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STOIC_MB_TOL"
		});

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object ogrStioMbChe_MultiMap => GetValue(ogrStioMbChe_MultiMap_Property);

		public object lbtuStoicTol_var1 => GetValue(lbtuStoicTol_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_Reactions")]
	public class MMSetup_Simopt_Reactions : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraStio;

		internal MMLabel lbtuStoicTol_label;

		internal MMVariableEdit lbtuStoicTol;

		internal MMLabel lblStoicUnits;

		internal MMOptionGroup ogrStioMbChe;

		internal MMOptionButton ogrStioMbChe_opt0;

		internal MMOptionButton ogrStioMbChe_opt1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMComboEdit MMComboBox1;

		private bool _contentLoaded;

		public MMSetup_Simopt_Reactions()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_Reactions_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_reactions.xaml", UriKind.Relative);
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
				fraStio = (MMGroupBox)target;
				break;
			case 2:
				lbtuStoicTol_label = (MMLabel)target;
				break;
			case 3:
				lbtuStoicTol = (MMVariableEdit)target;
				break;
			case 4:
				lblStoicUnits = (MMLabel)target;
				break;
			case 5:
				ogrStioMbChe = (MMOptionGroup)target;
				break;
			case 6:
				ogrStioMbChe_opt0 = (MMOptionButton)target;
				break;
			case 7:
				ogrStioMbChe_opt1 = (MMOptionButton)target;
				break;
			case 8:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 9:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 11:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 12:
				MMComboBox1 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.MASS_BAL_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Sim-Options.CC Nodes.MASSCK"
			}
		});

		public static readonly CxvPropertyDeclaration MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.MASS_BAL_CHE",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.VLLE_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.VLE_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PEQ_CHK_FRAC"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PEQ_CHK_TOL"
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.PEQ_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.SLE_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.SVE_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.SOLTHRESHOLD"
		});

		public static readonly CxvPropertyDeclaration chkPhaseStab_var1_Property = CxvPropertyDeclaration.Register("chkPhaseStab_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.FL_STAB_CHK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration StabChkThr_var1_Property = CxvPropertyDeclaration.Register("StabChkThr_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_CHK_THR"
		});

		public static readonly CxvPropertyDeclaration StabMinFrc_var1_Property = CxvPropertyDeclaration.Register("StabMinFrc_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_MIN_FRC"
		});

		public static readonly CxvPropertyDeclaration StabMaxFrc_var1_Property = CxvPropertyDeclaration.Register("StabMaxFrc_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_MAX_FRC"
		});

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMCheckBox6_var1 => GetValue(MMCheckBox6_var1_Property);

		public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

		public object MMComboBox5_var1 => GetValue(MMComboBox5_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

		public object MMComboBox4_var1 => GetValue(MMComboBox4_var1_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object chkPhaseStab_var1 => GetValue(chkPhaseStab_var1_Property);

		public object StabChkThr_var1 => GetValue(StabChkThr_var1_Property);

		public object StabMinFrc_var1 => GetValue(StabMinFrc_var1_Property);

		public object StabMaxFrc_var1 => GetValue(StabMaxFrc_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_Result")]
	public class MMSetup_Simopt_Result : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMCheckBox MMCheckBox6;

		internal MMTextBlock MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMComboBox3_label;

		internal MMComboEdit MMComboBox3;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMTextBlock MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMTextBlock MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMTextBlock MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMGroupBox MMFrame3;

		internal MMLabel chkPhaseStab_label;

		internal MMComboEdit chkPhaseStab;

		internal MMTextBlock StabChkThr_label;

		internal MMVariableEdit StabChkThr;

		internal MMTextBlock StabMinFrc_label;

		internal MMVariableEdit StabMinFrc;

		internal MMTextBlock StabMaxFrc_label;

		internal MMVariableEdit StabMaxFrc;

		private bool _contentLoaded;

		public MMSetup_Simopt_Result()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_result.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 2:
				MMCheckBox6 = (MMCheckBox)target;
				break;
			case 3:
				MMLBUText3_label = (MMTextBlock)target;
				break;
			case 4:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 5:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 6:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 14:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 16:
				MMLBUText1_label = (MMTextBlock)target;
				break;
			case 17:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 18:
				MMLBUText2_label = (MMTextBlock)target;
				break;
			case 19:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 20:
				MMLBUText4_label = (MMTextBlock)target;
				break;
			case 21:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 22:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 23:
				chkPhaseStab_label = (MMLabel)target;
				break;
			case 24:
				chkPhaseStab = (MMComboEdit)target;
				break;
			case 25:
				StabChkThr_label = (MMTextBlock)target;
				break;
			case 26:
				StabChkThr = (MMVariableEdit)target;
				break;
			case 27:
				StabMinFrc_label = (MMTextBlock)target;
				break;
			case 28:
				StabMinFrc = (MMVariableEdit)target;
				break;
			case 29:
				StabMaxFrc_label = (MMTextBlock)target;
				break;
			case 30:
				StabMaxFrc = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_System_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sys-Options.Input.TRACE",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkBlkChk_var1_Property = CxvPropertyDeclaration.Register("chkBlkChk_var1", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sys-Options.Input.BLOCK_CHECK",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration ChkStrmProp_Property = CxvPropertyDeclaration.Register("ChkStrmProp", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sys-Options.Input.STRPP_CHECK",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration ogrInterpret_MultiMap_Property = CxvPropertyDeclaration.Register("ogrInterpret_MultiMap", typeof(MMSetup_Simopt_System_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrInterpret_var1",
					DataPath = "@main.Sys-Options.Input.INTERPRET"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Interpret all inline Fortran statements at execution time",
					DisplayResourceKey = "MMSetup_Simopt_System_ViewModel__CxvMultiMapOption_Display_Interpret_all_inline_Fortran_statements_a",
					Value = "ogrInterpret_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrInterpret_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Write inline Fortran to a subroutine to be compiled and dynamically linked",
					DisplayResourceKey = "MMSetup_Simopt_System_ViewModel__CxvMultiMapOption_Display_Write_inline_Fortran_to_a_subroutine_to_b",
					Value = "ogrInterpret_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrInterpret_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);

		public object chkBlkChk_var1 => GetValue(chkBlkChk_var1_Property);

		public object ChkStrmProp => GetValue(ChkStrmProp_Property);

		public object ogrInterpret_MultiMap => GetValue(ogrInterpret_MultiMap_Property);
	}
	[ProgId("MMSetup.MMSetup_Simopt_System")]
	public class MMSetup_Simopt_System : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraSysOptions;

		internal MMOptionGroup ogrInterpret;

		internal MMOptionButton ogrInterpret_opt0;

		internal MMOptionButton ogrInterpret_opt1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBox7;

		internal MMGroupBox MMFrame2;

		internal MMCheckBox chkBlkChk;

		internal MMCheckBox ChkStrmProp;

		private bool _contentLoaded;

		public MMSetup_Simopt_System()
		{
			base.ViewModelType = typeof(MMSetup_Simopt_System_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_simopt_system.xaml", UriKind.Relative);
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
				fraSysOptions = (MMGroupBox)target;
				break;
			case 2:
				ogrInterpret = (MMOptionGroup)target;
				break;
			case 3:
				ogrInterpret_opt0 = (MMOptionButton)target;
				break;
			case 4:
				ogrInterpret_opt1 = (MMOptionButton)target;
				break;
			case 5:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 6:
				MMCheckBox7 = (MMCheckBox)target;
				break;
			case 7:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 8:
				chkBlkChk = (MMCheckBox)target;
				break;
			case 9:
				ChkStrmProp = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_SPInput_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_SPInput_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_SPInput_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_SPInput_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" },
			EnteredDataPaths = { "@entn" }
		});

		public object spec => GetValue(spec_Property);

		public object entn => GetValue(entn_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_SPInput")]
	public class MMSetup_SPInput : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_SPInput()
		{
			base.ViewModelType = typeof(MMSetup_SPInput_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_spinput.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_SPInput_Input_ViewModel : MMTabPageViewModel
	{
		public class grdStreamPrice_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.DESTBLK.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.SOURCEBLK.@y",
				IsReadOnly = true
			});

			public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);
		}

		private ICommand _cmdAddFeedStream_Command;

		private ICommand _cmdAddProdStream_Command;

		public static readonly CxvPropertyDeclaration grdStreamPrice_GridData_Property = CxvPropertyDeclaration.Register("grdStreamPrice_GridData", typeof(MMSetup_SPInput_Input_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreamPrice_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PRICE",
				UseChildId = true,
				Name = "y"
			}
		});

		public ICommand cmdAddFeedStream_Command
		{
			get
			{
				if (_cmdAddFeedStream_Command == null)
				{
					_cmdAddFeedStream_Command = new CxvDelegateCommand<object>(cmdAddFeedStream_CommandExecute);
				}
				return _cmdAddFeedStream_Command;
			}
		}

		public ICommand cmdAddProdStream_Command
		{
			get
			{
				if (_cmdAddProdStream_Command == null)
				{
					_cmdAddProdStream_Command = new CxvDelegateCommand<object>(cmdAddProdStream_CommandExecute);
				}
				return _cmdAddProdStream_Command;
			}
		}

		public object grdStreamPrice_GridData => GetValue(grdStreamPrice_GridData_Property);

		private void cmdAddFeedStream_CommandExecute(object parameter)
		{
			if (this.GxAddStream("FEED", 0) == 1)
			{
				ShowMessageBoxEventArgs e = new ShowMessageBoxEventArgs
				{
					Message = WpfFormsResources.MMSetup_SPInput_Input_Display2,
					MsgBoxButton = MessageBoxButton.YesNo,
					MsgBoxImage = MessageBoxImage.Question,
					Title = WpfFormsResources.MMSetup_SPInput_Input_Display1
				};
				ShowMessageBox(e);
				if (e.DialogResult == MessageBoxResult.Yes)
				{
					ExpandDataPathAndSet("@main.Input.HIER_STREAM", "value", "YES");
				}
				else
				{
					ExpandDataPathAndSet("@main.Input.HIER_STREAM", "value", "NO");
				}
			}
			this.GxAddStream("FEED", 1);
			UpdateAll();
		}

		private void cmdAddProdStream_CommandExecute(object parameter)
		{
			if (this.GxAddStream("PRODUCT", 0) == 1)
			{
				ShowMessageBoxEventArgs e = new ShowMessageBoxEventArgs
				{
					Message = WpfFormsResources.MMSetup_SPInput_Input_Display2,
					MsgBoxButton = MessageBoxButton.YesNo,
					MsgBoxImage = MessageBoxImage.Question,
					Title = WpfFormsResources.MMSetup_SPInput_Input_Display1
				};
				ShowMessageBox(e);
				if (e.DialogResult == MessageBoxResult.Yes)
				{
					ExpandDataPathAndSet("@main.Input.HIER_STREAM", "value", "YES");
				}
				else
				{
					ExpandDataPathAndSet("@main.Input.HIER_STREAM", "value", "NO");
				}
			}
			this.GxAddStream("PRODUCT", 1);
			UpdateAll();
		}
	}
	[ProgId("MMSetup.MMSetup_SPInput_Input")]
	public class MMSetup_SPInput_Input : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmStrPrice;

		internal MMScrollArea grdStreamPrice;

		internal MMCmdButton cmdAddFeedStream;

		internal MMCmdButton cmdAddProdStream;

		private bool _contentLoaded;

		public MMSetup_SPInput_Input()
		{
			base.ViewModelType = typeof(MMSetup_SPInput_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_spinput_input.xaml", UriKind.Relative);
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
				frmStrPrice = (MMGroupBox)target;
				break;
			case 2:
				grdStreamPrice = (MMScrollArea)target;
				break;
			case 3:
				cmdAddFeedStream = (MMCmdButton)target;
				break;
			case 4:
				cmdAddProdStream = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_SPResult_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cost_Property = CxvPropertyDeclaration.Register("cost", typeof(MMSetup_SPResult_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.COST"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_SPResult_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@cost" }
		});

		public object cost => GetValue(cost_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMSetup.MMSetup_SPResult")]
	public class MMSetup_SPResult : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMSetup_SPResult()
		{
			base.ViewModelType = typeof(MMSetup_SPResult_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_spresult.xaml", UriKind.Relative);
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_SPResult_Result_ViewModel : MMTabPageViewModel
	{
		public class grdStreamPrice_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MOLE_PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MASS_PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.VOL_PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.STDVOL_PRICE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COST.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Output.COST.@y"
			});

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MOLE_PRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MASS_PRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.VOL_PRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.STDVOL_PRICE"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.COST"
		});

		public static readonly CxvPropertyDeclaration grdStreamPrice_GridData_Property = CxvPropertyDeclaration.Register("grdStreamPrice_GridData", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreamPrice_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.COST",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMLBUText5_var1 => GetValue(MMLBUText5_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object grdStreamPrice_GridData => GetValue(grdStreamPrice_GridData_Property);
	}
	[ProgId("MMSetup.MMSetup_SPResult_Result")]
	public class MMSetup_SPResult_Result : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdStreamPrice;

		private bool _contentLoaded;

		public MMSetup_SPResult_Result()
		{
			base.ViewModelType = typeof(MMSetup_SPResult_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_spresult_result.xaml", UriKind.Relative);
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
				grdStreamPrice = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMSetup_Stratt_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration subsmain_Property = CxvPropertyDeclaration.Register("subsmain", typeof(MMSetup_Stratt_ViewModel), new CxvParameterProperty
		{
			Parameter = "subsmain"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PSD" },
			AccessibleDataPaths = { "@RUNFLOWSH" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@DEFSUB" },
			AccessibleDataPaths = { "@RUNFLOWSH" },
			EnteredDataPaths = { "@SUBSE" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@SUBSE", "@entsele" }
		});

		public static readonly CxvPropertyDeclaration PSD_Property = CxvPropertyDeclaration.Register("PSD", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Subs-Attr.@id.CC Nodes.MN1"
		});

		public static readonly CxvPropertyDeclaration attre_Property = CxvPropertyDeclaration.Register("attre", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Subs-Attr.@id.CC Nodes.ATTRE"
		});

		public static readonly CxvPropertyDeclaration RUNFLOWSH_Property = CxvPropertyDeclaration.Register("RUNFLOWSH", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Main.CC Nodes.RUNFLOWSH"
		});

		public static readonly CxvPropertyDeclaration DEFSUB_Property = CxvPropertyDeclaration.Register("DEFSUB", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Substreams.CC Nodes.MN2"
		});

		public static readonly CxvPropertyDeclaration SUBSE_Property = CxvPropertyDeclaration.Register("SUBSE", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Stream-Class.Substreams.CC Nodes.SUBSE"
		});

		public static readonly CxvPropertyDeclaration entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.@parent.Components.Moisture-Comps.CC Nodes.ENTSELE"
		});

		public object subsmain => GetValue(subsmain_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object PSD => GetValue(PSD_Property);

		public object attre => GetValue(attre_Property);

		public object RUNFLOWSH => GetValue(RUNFLOWSH_Property);

		public object DEFSUB => GetValue(DEFSUB_Property);

		public object SUBSE => GetValue(SUBSE_Property);

		public object entsele => GetValue(entsele_Property);
	}
	[ProgId("MMSetup.MMSetup_Stratt")]
	public class MMSetup_Stratt : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab2;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		private bool _contentLoaded;

		public MMSetup_Stratt()
		{
			base.ViewModelType = typeof(MMSetup_Stratt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_stratt.xaml", UriKind.Relative);
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
				tabInput = (MMTabStrip)target;
				break;
			case 2:
				tab2 = (MMTabItem)target;
				break;
			case 3:
				tab0 = (MMTabItem)target;
				break;
			case 4:
				tab1 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Stratt_Subatt_ViewModel : MMTabPageViewModel
	{
		public class grdAttribute_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INTERVAL.@y"
			});

			public static readonly CxvPropertyDeclaration MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PARTICLESIZ2.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.USER"
				}
			});

			public static readonly CxvPropertyDeclaration lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PARTICLESIZE.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.USER"
				}
			});

			public object txtInt_var1 => GetValue(txtInt_var1_Property);

			public object MMLBUText1_upper => GetValue(MMLBUText1_upper_Property);

			public object lbtuLower_Lower => GetValue(lbtuLower_Lower_Property);
		}

		public static readonly CxvPropertyDeclaration NUMROW_Property = CxvPropertyDeclaration.Register("NUMROW", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVALS",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.EXINT"
			}
		});

		public static readonly CxvPropertyDeclaration txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVAL.@y"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZ2.@y",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZE.@y",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
			}
		});

		private string _psdname;

		private EventHandler _nameWatch_PropertyDependencyChangedHandler;

		private CxvPropertyWatch _nameWatch;

		public static readonly CxvPropertyDeclaration txtIntervals_var1_Property = CxvPropertyDeclaration.Register("txtIntervals_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.INTERVALS"
		});

		public static readonly CxvPropertyDeclaration lbtuSizeUnits_var1_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PARTICLESIZE",
			ExtraDataPaths = { "@main.Input.PARTICLESIZ2", "@main.Input.LOWER", "@main.Input.UPPER" },
			VariablePrompt = "Size units",
			VariablePromptResourceKey = "MMSetup_Stratt_Subatt_ViewModel__unit_prompt"
		});

		public static readonly CxvPropertyDeclaration lbtuSizeUnits_var2_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var2", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PARTICLESIZ2"
		});

		public static CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main.Input.TYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Equidistant",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Equidistant",
					Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_equidistant_prompt,
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "EQUIDISTANT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Geometric",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Geometric",
					Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_geometric_prompt,
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "GEOMETRIC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Logarithmic",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Logarithmic",
					Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_logarithmic_prompt,
					Value = "MMComboBox1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "LOGARITHMIC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_User",
					Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_user_prompt,
					Value = "MMComboBox1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "USER"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration geoDiscretization_var1_Property = CxvPropertyDeclaration.Register("geoDiscretization_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.Q",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.ISGEO"
			}
		});

		public static readonly CxvPropertyDeclaration spnIntervals_var1_Property = CxvPropertyDeclaration.Register("spnIntervals_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.INTERVALS",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EXINT1"
			}
		});

		public static readonly CxvPropertyDeclaration txtUpper_var_Property = CxvPropertyDeclaration.Register("txtUpper_var", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UPPER",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.LIMIT"
			}
		});

		public static readonly CxvPropertyDeclaration txtLower_var_Property = CxvPropertyDeclaration.Register("txtLower_var", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LOWER",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.LIMIT"
			}
		});

		private ICommand _cmdCreateMesh_Command;

		public static readonly CxvPropertyDeclaration cmdCreateMesh_var1_Property = CxvPropertyDeclaration.Register("cmdCreateMesh_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CMESH"
			}
		});

		public static readonly CxvPropertyDeclaration grdAttribute_GridData_Property = CxvPropertyDeclaration.Register("grdAttribute_GridData", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAttribute_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.INTERVAL",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			},
			AllowCollectionChange = false
		});

		public object NUMROW => GetValue(NUMROW_Property);

		public object txtInt_var1 => GetValue(txtInt_var1_Property);

		public object MMLBUText1_upper => GetValue(MMLBUText1_upper_Property);

		public object lbtuLower_Lower => GetValue(lbtuLower_Lower_Property);

		public string psdname
		{
			get
			{
				if (_nameWatch != null)
				{
					_nameWatch.PropertyDependencyChanged -= varDefnDependencies_PropertyDependencyChangedHandler;
				}
				if (_nameWatch != null)
				{
					_nameWatch.Clear();
				}
				else
				{
					_nameWatch = new CxvPropertyWatch();
				}
				_psdname = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name", null, _nameWatch));
				if (!_nameWatch.IsEmpty)
				{
					_nameWatch.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					_nameWatch = null;
				}
				return _psdname;
			}
		}

		private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_nameWatch_PropertyDependencyChangedHandler == null)
				{
					_nameWatch_PropertyDependencyChangedHandler = delegate
					{
						OnPropertyChanged("psdname");
					};
				}
				return _nameWatch_PropertyDependencyChangedHandler;
			}
		}

		public object txtIntervals_var1 => GetValue(txtIntervals_var1_Property);

		public object lbtuSizeUnits_var1 => GetValue(lbtuSizeUnits_var1_Property);

		public object lbtuSizeUnits_var2 => GetValue(lbtuSizeUnits_var2_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object geoDiscretization_var1 => GetValue(geoDiscretization_var1_Property);

		public object spnIntervals_var1 => GetValue(spnIntervals_var1_Property);

		public object txtUpper_var => GetValue(txtUpper_var_Property);

		public object txtLower_var => GetValue(txtLower_var_Property);

		public ICommand cmdCreateMesh_Command
		{
			get
			{
				if (_cmdCreateMesh_Command == null)
				{
					_cmdCreateMesh_Command = new CxvDelegateCommand<object>(cmdCreateMesh_CommandExecute);
				}
				return _cmdCreateMesh_Command;
			}
		}

		public object cmdCreateMesh_var1 => GetValue(cmdCreateMesh_var1_Property);

		public object grdAttribute_GridData => GetValue(grdAttribute_GridData_Property);

		private void cmdCreateMesh_CommandExecute(object parameter)
		{
			base.ResolvedCxsProvider.BatchSet(ExpandDataPath("@main") + ".Input.GMESH", "value", null, "YES");
			base.ResolvedCxsProvider.BatchSet(ExpandDataPath("@main") + ".Input.GMESH", "value", null, "NO");
		}
	}
	[ProgId("MMSetup.MMSetup_Stratt_Subatt")]
	public class MMSetup_Stratt_Subatt : MMTabPage, IComponentConnector
	{
		internal MMComboEdit distrId;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel geoDiscretization_label;

		internal MMSpinBox geoDiscretization;

		internal MMLabel spnIntervals_label;

		internal MMSpinBox spnIntervals;

		internal MMLabel txtLower_label;

		internal MMValueEdit txtLower;

		internal MMLabel txtUpper_label;

		internal MMValueEdit txtUpper;

		internal MMLabel MMComboBox2_label;

		internal MMVariableEdit lbtuSizeUnits;

		internal MMCmdButton cmdCreateMesh;

		internal MMGroupBox fraAttribute;

		internal MMScrollArea grdAttribute;

		private bool _contentLoaded;

		public MMSetup_Stratt_Subatt()
		{
			base.ViewModelType = typeof(MMSetup_Stratt_Subatt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_stratt_subatt.xaml", UriKind.Relative);
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
				distrId = (MMComboEdit)target;
				break;
			case 2:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 4:
				geoDiscretization_label = (MMLabel)target;
				break;
			case 5:
				geoDiscretization = (MMSpinBox)target;
				break;
			case 6:
				spnIntervals_label = (MMLabel)target;
				break;
			case 7:
				spnIntervals = (MMSpinBox)target;
				break;
			case 8:
				txtLower_label = (MMLabel)target;
				break;
			case 9:
				txtLower = (MMValueEdit)target;
				break;
			case 10:
				txtUpper_label = (MMLabel)target;
				break;
			case 11:
				txtUpper = (MMValueEdit)target;
				break;
			case 12:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 13:
				lbtuSizeUnits = (MMVariableEdit)target;
				break;
			case 14:
				cmdCreateMesh = (MMCmdButton)target;
				break;
			case 15:
				fraAttribute = (MMGroupBox)target;
				break;
			case 16:
				grdAttribute = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SCLASS_Property = CxvPropertyDeclaration.Register("SCLASS", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "SCLASS"
		});

		public static readonly CxvPropertyDeclaration DEFSUB_Property = CxvPropertyDeclaration.Register("DEFSUB", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Substreams.CC Nodes.MN2"
		});

		public static readonly CxvPropertyDeclaration STRCLA_Property = CxvPropertyDeclaration.Register("STRCLA", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN3"
		});

		public static readonly CxvPropertyDeclaration subse_Property = CxvPropertyDeclaration.Register("subse", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Substreams.CC Nodes.SUBSE"
		});

		public static readonly CxvPropertyDeclaration strcle_Property = CxvPropertyDeclaration.Register("strcle", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.STRCLE"
		});

		public static readonly CxvPropertyDeclaration runflowsh_Property = CxvPropertyDeclaration.Register("runflowsh", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.RUNFLOWSH"
		});

		public static readonly CxvPropertyDeclaration defstrmain_Property = CxvPropertyDeclaration.Register("defstrmain", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "defstrmain"
		});

		public static readonly CxvPropertyDeclaration _class_Property = CxvPropertyDeclaration.Register("_class", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "_class"
		});

		public static readonly CxvPropertyDeclaration main2_Property = CxvPropertyDeclaration.Register("main2", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "main2"
		});

		public static readonly CxvPropertyDeclaration defs_Property = CxvPropertyDeclaration.Register("defs", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.DEFS"
		});

		public static readonly CxvPropertyDeclaration entopt_Property = CxvPropertyDeclaration.Register("entopt", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.ENTOPT"
		});

		public static readonly CxvPropertyDeclaration ENTSECT_Property = CxvPropertyDeclaration.Register("ENTSECT", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ENTSECT"
		});

		public static readonly CxvPropertyDeclaration mn3_Property = CxvPropertyDeclaration.Register("mn3", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN3"
		});

		public static readonly CxvPropertyDeclaration DEF2_Property = CxvPropertyDeclaration.Register("DEF2", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.DEF2"
		});

		public static readonly CxvPropertyDeclaration ENTLOAD_Property = CxvPropertyDeclaration.Register("ENTLOAD", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.ENTLOAD"
		});

		public static readonly CxvPropertyDeclaration hclass_Property = CxvPropertyDeclaration.Register("hclass", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "hclass"
		});

		public static readonly CxvPropertyDeclaration load_Property = CxvPropertyDeclaration.Register("load", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "load"
		});

		public static readonly CxvPropertyDeclaration MN1_Property = CxvPropertyDeclaration.Register("MN1", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@load.CC Nodes.MN1"
		});

		public static readonly CxvPropertyDeclaration ENTNPOINT_Property = CxvPropertyDeclaration.Register("ENTNPOINT", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Stream-Attributes.LOAD.CC Nodes.ENTNPOINT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTSECT" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@defs" },
			EnteredDataPaths = { "@entopt" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@mn3" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@MN1" },
			EnteredDataPaths = { "@ENTLOAD", "@ENTNPOINT" }
		});

		public object SCLASS => GetValue(SCLASS_Property);

		public object DEFSUB => GetValue(DEFSUB_Property);

		public object STRCLA => GetValue(STRCLA_Property);

		public object subse => GetValue(subse_Property);

		public object strcle => GetValue(strcle_Property);

		public object runflowsh => GetValue(runflowsh_Property);

		public object defstrmain => GetValue(defstrmain_Property);

		public object _class => GetValue(_class_Property);

		public object main2 => GetValue(main2_Property);

		public object defs => GetValue(defs_Property);

		public object entopt => GetValue(entopt_Property);

		public object ENTSECT => GetValue(ENTSECT_Property);

		public object mn3 => GetValue(mn3_Property);

		public object DEF2 => GetValue(DEF2_Property);

		public object ENTLOAD => GetValue(ENTLOAD_Property);

		public object hclass => GetValue(hclass_Property);

		public object load => GetValue(load_Property);

		public object MN1 => GetValue(MN1_Property);

		public object ENTNPOINT => GetValue(ENTNPOINT_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
				ResolveUpdateParameter("extraComments_path", "Stream-Class.Stream-Class.Comments");
				ResolveUpdateParameter("extraDescription_path", "Stream-Class.Stream-Class.Input.DESCRIPTION");
				ResolveUpdateParameter("defstrmain", "@main.@parent.Flowsheet.Def-Streams");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla")]
	public class MMSetup_Strcla : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_Strcla()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla.xaml", UriKind.Relative);
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
				tabInput = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_Defstr_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration mnbStreamCl_var2_Property = CxvPropertyDeclaration.Register("mnbStreamCl_var2", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvParameterProperty
		{
			Parameter = "_class"
		});

		public static readonly CxvPropertyDeclaration mnbStreamCl_DEF1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_DEF1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.DEF1"
		});

		public static readonly CxvPropertyDeclaration mnbStreamCl_ENTOPT1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_ENTOPT1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@defstrmain.CC Nodes.ENTOPT1"
		});

		public static readonly CxvPropertyDeclaration lstStreams_state_Property = CxvPropertyDeclaration.Register("lstStreams_state", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "_class",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lstStreams_var1_Property = CxvPropertyDeclaration.Register("lstStreams_var1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@defstrmain.Input.SLIST.@_class",
			AllowSort = false
		});

		public static readonly CxvPropertyDeclaration mnbStreamCl_var1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_var1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@defstrmain.Input.SCLASS",
			SelectedItemBinding = "mnbStreamCl_var2.Value",
			CreateNewPrompt = "Stream class:",
			CreateNewPromptResourceKey = "MMSetup_Strcla_Defstr_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_class_",
			CompletePaths = { "@defstrmain.CC Nodes.DEF1" },
			EnteredPaths = { "@defstrmain.CC Nodes.ENTOPT1" },
			DisplayValues = true
		});

		public object mnbStreamCl_var2 => GetValue(mnbStreamCl_var2_Property);

		public object mnbStreamCl_DEF1 => GetValue(mnbStreamCl_DEF1_Property);

		public object mnbStreamCl_ENTOPT1 => GetValue(mnbStreamCl_ENTOPT1_Property);

		public object lstStreams_state => GetValue(lstStreams_state_Property);

		public object lstStreams_var1 => GetValue(lstStreams_var1_Property);

		public object mnbStreamCl_var1 => GetValue(mnbStreamCl_var1_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveParameter("defstrmain"))))
			{
				ResolveUpdateParameter("defstrmain", "@main.@parent.Flowsheet.Def-Streams");
			}
			base.OnUpdateData();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Metadata.Name == "mnbStreamCl_var1")
			{
				_ = subPropertyName == "SelectedItem";
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla_Defstr")]
	public class MMSetup_Strcla_Defstr : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbStreamCl_label;

		internal MMAdvancedComboEdit mnbStreamCl;

		internal MMListPicker lstStreams;

		private bool _contentLoaded;

		public MMSetup_Strcla_Defstr()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_Defstr_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla_defstr.xaml", UriKind.Relative);
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
				mnbStreamCl_label = (MMLabel)target;
				break;
			case 2:
				mnbStreamCl = (MMAdvancedComboEdit)target;
				break;
			case 3:
				lstStreams = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_Defsub_ViewModel : MMTabPageViewModel
	{
		public class grdDefSubstream_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboAttribute_var1_Property = CxvPropertyDeclaration.Register("cboAttribute_var1", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@subsmain.Stream-Class.Substreams.Input.ATTRIBUTES.@y"
			});

			public static readonly CxvPropertyDeclaration cboType_var1_Property = CxvPropertyDeclaration.Register("cboType_var1", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE.@y"
			});

			public static readonly CxvPropertyDeclaration txtSubstream_sid_Property = CxvPropertyDeclaration.Register("txtSubstream_sid", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object cboAttribute_var1 => GetValue(cboAttribute_var1_Property);

			public object cboType_var1 => GetValue(cboType_var1_Property);

			public object txtSubstream_sid => GetValue(txtSubstream_sid_Property);
		}

		public static readonly CxvPropertyDeclaration fraDefSubstream_subsmain_Property = CxvPropertyDeclaration.Register("fraDefSubstream_subsmain", typeof(MMSetup_Strcla_Defsub_ViewModel), new CxvVariableProperty
		{
			DataPath = "subsmain"
		});

		public static readonly CxvPropertyDeclaration grdDefSubstream_GridData_Property = CxvPropertyDeclaration.Register("grdDefSubstream_GridData", typeof(MMSetup_Strcla_Defsub_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdDefSubstream_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE",
				UseChildId = true,
				Name = "y"
			}
		});

		public object fraDefSubstream_subsmain => GetValue(fraDefSubstream_subsmain_Property);

		public object grdDefSubstream_GridData => GetValue(grdDefSubstream_GridData_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveParameter("subsmain"))))
			{
				ResolveUpdateParameter("subsmain", "@main.@parent.@parent");
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla_Defsub")]
	public class MMSetup_Strcla_Defsub : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDefSubstream;

		internal MMScrollArea grdDefSubstream;

		private bool _contentLoaded;

		public MMSetup_Strcla_Defsub()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_Defsub_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla_defsub.xaml", UriKind.Relative);
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
				fraDefSubstream = (MMGroupBox)target;
				break;
			case 2:
				grdDefSubstream = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_Flowsh_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_SCLASS_Property = CxvPropertyDeclaration.Register("MMComboBox1_SCLASS", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main2.@y.Input.SCLASS"
			});

			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main2.@y"
			});

			public object MMComboBox1_SCLASS => GetValue(MMComboBox1_SCLASS_Property);

			public object txtName_var1 => GetValue(txtName_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraSection_flsmain_Property = CxvPropertyDeclaration.Register("fraSection_flsmain", typeof(MMSetup_Strcla_Flowsh_ViewModel), new CxvVariableProperty
		{
			DataPath = "flsmain"
		});

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Strcla_Flowsh_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main2",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			}
		});

		public object fraSection_flsmain => GetValue(fraSection_flsmain_Property);

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveParameter("main2"))))
			{
				ResolveUpdateParameter("main2", "@main.@parent.Flowsheet.Section");
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla_Flowsh")]
	public class MMSetup_Strcla_Flowsh : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraSection;

		internal MMScrollArea grdChild;

		private bool _contentLoaded;

		public MMSetup_Strcla_Flowsh()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_Flowsh_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla_flowsh.xaml", UriKind.Relative);
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
				fraSection = (MMGroupBox)target;
				break;
			case 2:
				grdChild = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_Load_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spnMaxLoadPoints_NPOINT_Property = CxvPropertyDeclaration.Register("spnMaxLoadPoints_NPOINT", typeof(MMSetup_Strcla_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.AppModelV8.Setup.Stream-Class.Stream-Attributes.LOAD.Input.NPOINT"
		});

		private CxvPropertyWatch varDefnDependencies;

		private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

		public object spnMaxLoadPoints_NPOINT => GetValue(spnMaxLoadPoints_NPOINT_Property);

		public object lstStreams_var1
		{
			get
			{
				if (varDefnDependencies != null)
				{
					varDefnDependencies.Clear();
				}
				else
				{
					varDefnDependencies = new CxvPropertyWatch();
				}
				ExpandDataPathAndGet("@main.@parent.Flowsheet.Def-Streams.Input.H_SLIST.@hclass", "option_list", null, varDefnDependencies);
				if (!varDefnDependencies.IsEmpty)
				{
					varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					varDefnDependencies = null;
				}
				return new CxvListVariableData(this, new CxvVariableProperty
				{
					ExposeAs = CxvVariableTypeCode.List,
					DataPath = "@main.@parent.Flowsheet.Def-Streams.Input.H_SLIST.@hclass",
					AllowSort = false
				});
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
						OnPropertyChanged("lstStreams_var1");
					};
				}
				return _varDefnDependencies_PropertyDependencyChangedHandler;
			}
		}

		protected override void OnUpdateData()
		{
			if (string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveParameter("heat"))))
			{
				ResolveUpdateParameter("heat", "Top.AppModelV8.Setup.Stream-Class.Stream-Attributes.LOAD");
			}
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.@parent.Flowsheet.Def-Streams.Input.H_SCLASS", "child_count"));
			if (!num.HasValue || !num.HasValue || num.Value == 0)
			{
				AddChild("@main.@parent.Flowsheet.Def-Streams.Input.H_SCLASS", 0);
			}
			try
			{
				if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.@parent.Flowsheet.Def-Streams.Input.H_SCLASS.#0", "value")) != "LOAD")
				{
					GetSimulationStatusFlags(out var flagCPT, out var flagPGC, out var flagNEC);
					CxsBatchRequestData cxsBatchRequestData = new CxsBatchRequestData();
					cxsBatchRequestData.AddRequest(ExpandDataPath("@main.@parent.Flowsheet.Def-Streams.Input.H_SCLASS.#0"), "value", null, "LOAD");
					base.ResolvedCxsProvider.BatchSetNoRefresh(cxsBatchRequestData);
					SetSimulationStatusFlags(flagCPT, flagPGC, flagNEC);
				}
			}
			catch (Exception)
			{
			}
			ResolveUpdateParameter("hclass", "#0");
			base.OnUpdateData();
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla_Load")]
	public class MMSetup_Strcla_Load : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstStreams;

		internal MMGroupBox frmLoadStreamAttributes;

		internal MMLabel spnMaxLoadPoints_label;

		internal MMSpinBox spnMaxLoadPoints;

		private bool _contentLoaded;

		public MMSetup_Strcla_Load()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_Load_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla_load.xaml", UriKind.Relative);
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
				lstStreams = (MMListPicker)target;
				break;
			case 2:
				frmLoadStreamAttributes = (MMGroupBox)target;
				break;
			case 3:
				spnMaxLoadPoints_label = (MMLabel)target;
				break;
			case 4:
				spnMaxLoadPoints = (MMSpinBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Strcla_Strcla_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration mnbStreamClass_var2_Property = CxvPropertyDeclaration.Register("mnbStreamClass_var2", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvParameterProperty
		{
			Parameter = "SCLASS"
		});

		public static readonly CxvPropertyDeclaration mnbStreamClass_mn4_Property = CxvPropertyDeclaration.Register("mnbStreamClass_mn4", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN4"
		});

		public static readonly CxvPropertyDeclaration mnbStreamClass_var1_Property = CxvPropertyDeclaration.Register("mnbStreamClass_var1", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Stream-Class.Stream-Class.Input.SUBSTREAMS",
			SelectedItemBinding = "mnbStreamClass_var2.Value",
			CreateNewPrompt = "Stream class:",
			CreateNewPromptResourceKey = "MMSetup_Strcla_Strcla_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_class_",
			CreateNewInputMask = 2,
			CompletePaths = { "@main.Stream-Class.Stream-Class.CC Nodes.MN4" }
		});

		public static readonly CxvPropertyDeclaration lstpSubstreams_state_Property = CxvPropertyDeclaration.Register("lstpSubstreams_state", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SCLASS",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lstpSubstreams_var1_Property = CxvPropertyDeclaration.Register("lstpSubstreams_var1", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Stream-Class.Stream-Class.Input.SUBSTREAMS.@SCLASS"
		});

		private bool _needUpdateCombos = true;

		private CxvPropertyWatch varOptDependencies;

		private EventHandler _varOptDependencies_PropertyDependencyChangedHandler;

		public object mnbStreamClass_var2 => GetValue(mnbStreamClass_var2_Property);

		public object mnbStreamClass_mn4 => GetValue(mnbStreamClass_mn4_Property);

		public object mnbStreamClass_var1 => GetValue(mnbStreamClass_var1_Property);

		public object lstpSubstreams_state => GetValue(lstpSubstreams_state_Property);

		public object lstpSubstreams_var1 => GetValue(lstpSubstreams_var1_Property);

		private EventHandler varOptDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_varOptDependencies_PropertyDependencyChangedHandler == null)
				{
					_varOptDependencies_PropertyDependencyChangedHandler = delegate
					{
						if (_needUpdateCombos)
						{
							UpdateComboboxes();
						}
					};
				}
				return _varOptDependencies_PropertyDependencyChangedHandler;
			}
		}

		private void UpdateComboboxes()
		{
			if (varOptDependencies != null)
			{
				varOptDependencies.PropertyDependencyChanged -= varOptDependencies_PropertyDependencyChangedHandler;
			}
			if (varOptDependencies != null)
			{
				varOptDependencies.Clear();
			}
			else
			{
				varOptDependencies = new CxvPropertyWatch();
			}
			string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.@parent.Flowsheet.Section.#0.Input.SCLASS", "value", null, varOptDependencies));
			if (!string.IsNullOrEmpty(value))
			{
				ResolveUpdateParameter("SCLASS", value);
			}
			if (!varOptDependencies.IsEmpty)
			{
				varOptDependencies.PropertyDependencyChanged += varOptDependencies_PropertyDependencyChangedHandler;
			}
			else
			{
				varOptDependencies = null;
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				UpdateComboboxes();
			}
		}
	}
	[ProgId("MMSetup.MMSetup_Strcla_Strcla")]
	public class MMSetup_Strcla_Strcla : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbStreamClass_label;

		internal MMAdvancedComboEdit mnbStreamClass;

		internal MMListPicker lstpSubstreams;

		private bool _contentLoaded;

		public MMSetup_Strcla_Strcla()
		{
			base.ViewModelType = typeof(MMSetup_Strcla_Strcla_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_strcla_strcla.xaml", UriKind.Relative);
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
				mnbStreamClass_label = (MMLabel)target;
				break;
			case 2:
				mnbStreamClass = (MMAdvancedComboEdit)target;
				break;
			case 3:
				lstpSubstreams = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ProgId("MMSetup.MMSetup_StreamGroup_Selection")]
	public class MMSetup_StreamGroup_Selection : MMTabPage, IComponentConnector
	{
		internal MMValueEdit txtName;

		internal XamComboEditor cboSummaryTemplate;

		internal MMValueEdit txtDescription;

		internal MMOptionGroup ogrSelection;

		internal MMOptionButton ogrSelection_opt1;

		internal MMOptionButton ogrSelection_opt2;

		internal MMComboEdit cboHierarchy;

		internal MMComboEdit cboSection;

		internal MMListPicker MMListPicker1;

		internal MMComboEdit cboCondition;

		internal MMComboEdit cboContains;

		internal MMComboEdit cboPropertySet;

		internal MMValueEdit txtContainText;

		internal MMComboEdit cboOperator;

		internal MMValueEdit txtValue1;

		internal MMValueEdit txtValue1Units;

		internal MMValueEdit txtValue2;

		internal MMValueEdit txtValue2Units;

		internal ListBox lstConditionalStreams;

		internal ListBox lstBuiltInStreams;

		internal ColorPicker colorPicker1;

		internal LineWeightPicker lieghtWeightPicker1;

		internal LineStylePicker lineStylePicker1;

		private bool _contentLoaded;

		public MMSetup_StreamGroup_Selection()
		{
			base.ViewModelType = typeof(MMSetup_StreamGroup_Selection_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_streamgroup_selection.xaml", UriKind.Relative);
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
				txtName = (MMValueEdit)target;
				break;
			case 2:
				cboSummaryTemplate = (XamComboEditor)target;
				break;
			case 3:
				txtDescription = (MMValueEdit)target;
				break;
			case 4:
				ogrSelection = (MMOptionGroup)target;
				break;
			case 5:
				ogrSelection_opt1 = (MMOptionButton)target;
				break;
			case 6:
				ogrSelection_opt2 = (MMOptionButton)target;
				break;
			case 7:
				cboHierarchy = (MMComboEdit)target;
				break;
			case 8:
				cboSection = (MMComboEdit)target;
				break;
			case 9:
				MMListPicker1 = (MMListPicker)target;
				break;
			case 10:
				cboCondition = (MMComboEdit)target;
				break;
			case 11:
				cboContains = (MMComboEdit)target;
				break;
			case 12:
				cboPropertySet = (MMComboEdit)target;
				break;
			case 13:
				txtContainText = (MMValueEdit)target;
				break;
			case 14:
				cboOperator = (MMComboEdit)target;
				break;
			case 15:
				txtValue1 = (MMValueEdit)target;
				break;
			case 16:
				txtValue1Units = (MMValueEdit)target;
				break;
			case 17:
				txtValue2 = (MMValueEdit)target;
				break;
			case 18:
				txtValue2Units = (MMValueEdit)target;
				break;
			case 19:
				lstConditionalStreams = (ListBox)target;
				break;
			case 20:
				lstBuiltInStreams = (ListBox)target;
				break;
			case 21:
				colorPicker1 = (ColorPicker)target;
				break;
			case 22:
				lieghtWeightPicker1 = (LineWeightPicker)target;
				break;
			case 23:
				lineStylePicker1 = (LineStylePicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_UnitObj_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static CxvPropertyDeclaration cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "status",
				IsReadOnly = true,
				IsCalculated = false
			});

			public object txtName_var1 => GetValue(txtName_var1_Property);

			public object cboStatus_Status => GetValue(cboStatus_Status_Property);

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
			}
		}

		[CompilerGenerated]
		private sealed class SelectedIdsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string currentId;

			private int initialThreadId;

			public MMSetup_UnitObj_ViewModel owner;

			private IList gridData;

			private IEnumerator<int> rowIndexes;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			[DebuggerHidden]
			public SelectedIdsEnumerator(int state)
			{
				this.state = state;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = state;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeRowIndexes();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{  bool completedNormally = false;
				try
				{
					int num = state;
					MMSetup_UnitObj_ViewModel mMSetup_UnitObj_ViewModel = owner;
					switch (num)
					{
					default:
						completedNormally = true; return false;
					case 0:
						state = -1;
						gridData = mMSetup_UnitObj_ViewModel.grdChild_GridData as IList;
						if (gridData == null)
						{
							completedNormally = true; return false;
						}
						rowIndexes = mMSetup_UnitObj_ViewModel.SelectedRowIndexes.GetEnumerator();
						state = -3;
						break;
					case 1:
						state = -3;
						break;
					}
					if (rowIndexes.MoveNext())
					{
						int current = rowIndexes.Current;
						grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = gridData[current] as grdChild_GridData_ItemTemplate;
						currentId = grdChild_GridData_ItemTemplate.GetId();
						state = 1;
						completedNormally = true; return true;
					}
					DisposeRowIndexes();
					rowIndexes = null;
					completedNormally = true; return false;
				}
				finally
				{
					// Original fault handler runs only when MoveNext leaves by exception.
					if (!completedNormally) ((IDisposable)this).Dispose();

				}
			}







			private void DisposeRowIndexes()
			{
				state = -1;
				if (rowIndexes != null)
				{
					rowIndexes.Dispose();
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
				SelectedIdsEnumerator result;
				if (state == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					state = 0;
					result = this;
				}
				else
				{
					result = new SelectedIdsEnumerator(0)
					{
						owner = owner
					};
				}
				return result;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private ICommand _grid_RowDoubleClickCommand;

		private ICommand _cmdAdd_Command;

		public static CxvPropertyDeclaration cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "InsertChild"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private DelegateCommand<object> _cmdDelete_Command;

		private ICommand _cmdCopy_Command;

		public static CxvPropertyDeclaration cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "CopyChildren"
				}
			}
		});

		private DelegateCommand<object> _cmdRename_Command;

		private ICommand _cmdHide_Command;

		public static CxvPropertyDeclaration cmdHideCanExecuteProperty = CxvPropertyDeclaration.Register("cmdHideCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "HideChild"
				}
			}
		});

		private ICommand _cmdReveal_Command;

		public static CxvPropertyDeclaration cmdRevealCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRevealCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "RevealChild"
		});

		private ICommand _cmdPaste_Command;

		public static CxvPropertyDeclaration cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Equal,
			PropertyPath = "CanPaste",
			Value = true
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_UnitObj_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main",
				UseChildId = true,
				ProxyRow = false,
				Name = "y"
			}
		});

		public ICommand grid_RowDoubleClickCommand
		{
			get
			{
				if (_grid_RowDoubleClickCommand == null)
				{
					_grid_RowDoubleClickCommand = new CxvDelegateCommand<object>(grid_RowDoubleClickCommandExecute);
				}
				return _grid_RowDoubleClickCommand;
			}
		}

		public ICommand cmdAdd_Command
		{
			get
			{
				if (_cmdAdd_Command == null)
				{
					_cmdAdd_Command = new CxvDelegateCommand<object>(cmdAdd_CommandExecute, this, cmdAddCanExecuteProperty.Name + ".Value");
				}
				return _cmdAdd_Command;
			}
		}

		public CxvLogicalPropertyData cmdAddCanExecute => GetValue(cmdAddCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEditCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEditCanExecute => GetValue(cmdEditCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new DelegateCommand<object>(cmdDelete_CommandExecute, cmdDelete_CanExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public ICommand cmdCopy_Command
		{
			get
			{
				if (_cmdCopy_Command == null)
				{
					_cmdCopy_Command = new CxvDelegateCommand<object>(cmdCopy_CommandExecute, this, cmdCopyCanExecuteProperty.Name + ".Value");
				}
				return _cmdCopy_Command;
			}
		}

		public CxvLogicalPropertyData cmdCopyCanExecute => GetValue(cmdCopyCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdRename_Command
		{
			get
			{
				if (_cmdRename_Command == null)
				{
					_cmdRename_Command = new DelegateCommand<object>(cmdRename_CommandExecute, cmdRename_CanExecute);
				}
				return _cmdRename_Command;
			}
		}

		public ICommand cmdHide_Command
		{
			get
			{
				if (_cmdHide_Command == null)
				{
					_cmdHide_Command = new CxvDelegateCommand<object>(cmdHide_CommandExecute, this, cmdHideCanExecuteProperty.Name + ".Value");
				}
				return _cmdHide_Command;
			}
		}

		public CxvLogicalPropertyData cmdHideCanExecute => GetValue(cmdHideCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdReveal_Command
		{
			get
			{
				if (_cmdReveal_Command == null)
				{
					_cmdReveal_Command = new CxvDelegateCommand<object>(cmdReveal_CommandExecute, this, cmdRevealCanExecuteProperty.Name + ".Value");
				}
				return _cmdReveal_Command;
			}
		}

		public CxvLogicalPropertyData cmdRevealCanExecute => GetValue(cmdRevealCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdPaste_Command
		{
			get
			{
				if (_cmdPaste_Command == null)
				{
					_cmdPaste_Command = new CxvDelegateCommand<object>(cmdPaste_CommandExecute, this, cmdPaste_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdPaste_Command;
			}
		}

		public bool CanPaste
		{
			get
			{
				if (!ClipboardWrapper.ContainsData("Aspen Plus Selection"))
				{
					return false;
				}
				if (ClipboardWrapper.ContainsData("Aspen Plus Selection Type"))
				{
					IDataObject dataObject = ClipboardWrapper.GetDataObject();
					if (dataObject != null && dataObject.GetData("Aspen Plus Selection Type", autoConvert: false) is MemoryStream stream)
					{
						string text = new StreamReader(stream).ReadToEnd();
						string path = ExpandDataPath("@main");
						try
						{
							return CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "CanPaste:" + text)).CanInvoke;
						}
						catch (Exception)
						{
						}
					}
				}
				return true;
			}
		}

		public CxvLogicalPropertyData cmdPaste_CommandCanExecute => GetValue(cmdPaste_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public int AllSelectedRecordsCount
		{
			get
			{
				return _allSelectedRecordsCount;
			}
			set
			{
				if (value != _allSelectedRecordsCount)
				{
					_allSelectedRecordsCount = value;
					OnAllSelectedRecordsCountChanged();
				}
			}
		}

		public ObservableCollection<int> SelectedRowIndexes
		{
			get
			{
				return _SelectedRowIndexes;
			}
			set
			{
				if (_SelectedRowIndexes != value)
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
			}
		}

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		public event EventHandler CanPasteChanged;

		public event EventHandler AllSelectedRecordsCountChanged;

		private void cmdAdd_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			string newChildId = null;
			bool? flag = ShowAddChildDialog(parentPath, out newChildId);
			if (flag.HasValue && flag.Value)
			{
				string path = ".!" + newChildId;
				GoToNode(path);
			}
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
			using IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string current = enumerator.Current;
				string path = ".!" + current;
				GoToNode(path);
			}
		}

		private bool cmdDelete_CanExecute(object parameter)
		{
			if (_SelectedRowIndexes == null || _SelectedRowIndexes.Count == 0)
			{
				return false;
			}
			bool result = true;
			using IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			while (enumerator.MoveNext())
			{
				switch (enumerator.Current)
				{
				case "ENG":
				case "MET":
				case "SI":
					result = false;
					break;
				}
			}
			return result;
		}

		private void cmdDelete_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DeleteChildren(parentPath, collection);
		}

		private void cmdCopy_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			CopyChildren(parentPath, collection);
			OnCanPasteChanged();
		}

		private bool cmdRename_CanExecute(object parameter)
		{
			if (_SelectedRowIndexes == null || _SelectedRowIndexes.Count != 1)
			{
				return false;
			}
			bool result = true;
			using IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			while (enumerator.MoveNext())
			{
				switch (enumerator.Current)
				{
				case "ENG":
				case "MET":
				case "SI":
					result = false;
					break;
				}
			}
			return result;
		}

		private void cmdRename_CommandExecute(object parameter)
		{
			int allSelectedRecordsCount = AllSelectedRecordsCount;
			if (allSelectedRecordsCount != 0 && allSelectedRecordsCount <= 1)
			{
				string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
				string childId = GetSelectedIds().First();
				ShowRenameChildDialog(parentPath, ref childId);
			}
		}

		private void cmdHide_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			HideNodeChildren(parentPath, collection);
		}

		private void cmdReveal_CommandExecute(object parameter)
		{
			string path = CxsConverter.ValueToString(ResolveParameter("main", null));
			ShowRevealNodeDialog(path);
		}

		private void OnCanPasteChanged()
		{
			if (this.CanPasteChanged != null)
			{
				this.CanPasteChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("CanPaste");
		}

		private void cmdPaste_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DoPaste(parentPath);
		}

		private void grid_RowDoubleClickCommandExecute(object parameter)
		{
			IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string path = ".!" + enumerator.Current;
				GoToNode(path);
			}
		}

		private void OnAllSelectedRecordsCountChanged()
		{
			if (this.AllSelectedRecordsCountChanged != null)
			{
				this.AllSelectedRecordsCountChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("AllSelectedRecordsCount");
		}

		private void _SelectedRowIndexes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (_cmdDelete_Command != null)
			{
				_cmdDelete_Command.RaiseCanExecuteChanged();
			}
			if (_cmdRename_Command != null)
			{
				_cmdRename_Command.RaiseCanExecuteChanged();
			}
		}

		[IteratorStateMachine(typeof(SelectedIdsEnumerator))]
		private IEnumerable<string> GetSelectedIds()
		{
			return new SelectedIdsEnumerator(-2)
			{
				owner = this
			};
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			_ = base.IsInitialUpdate;
		}
	}
	[ProgId("MMSetup.MMSetup_UnitObj")]
	public class MMSetup_UnitObj : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdChild;

		internal MMCmdButton cmdAdd;

		internal MMCmdButton cmdEdit;

		internal MMCmdButton cmdDelete;

		internal MMCmdButton cmdCopy;

		internal MMCmdButton cmdRename;

		internal MMCmdButton cmdHide;

		internal MMCmdButton cmdReveal;

		internal MMCmdButton cmdPaste;

		private bool _contentLoaded;

		public MMSetup_UnitObj()
		{
			base.ViewModelType = typeof(MMSetup_UnitObj_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_unitobj.xaml", UriKind.Relative);
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
				grdChild = (MMScrollArea)target;
				break;
			case 2:
				cmdAdd = (MMCmdButton)target;
				break;
			case 3:
				cmdEdit = (MMCmdButton)target;
				break;
			case 4:
				cmdDelete = (MMCmdButton)target;
				break;
			case 5:
				cmdCopy = (MMCmdButton)target;
				break;
			case 6:
				cmdRename = (MMCmdButton)target;
				break;
			case 7:
				cmdHide = (MMCmdButton)target;
				break;
			case 8:
				cmdReveal = (MMCmdButton)target;
				break;
			case 9:
				cmdPaste = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMSetup_Units_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Units_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@var1" }
		});

		public object var1 => GetValue(var1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_Units")]
	public class MMSetup_Units : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_Units()
		{
			base.ViewModelType = typeof(MMSetup_Units_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units.xaml", UriKind.Relative);
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
			case 8:
				tab6 = (MMTabItem)target;
				break;
			case 9:
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Concen_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox78_var1_Property = CxvPropertyDeclaration.Register("MMComboBox78_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.COMPOSITION",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_1_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox24_var1_Property = CxvPropertyDeclaration.Register("MMComboBox24_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLES",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox43_var1_Property = CxvPropertyDeclaration.Register("MMComboBox43_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENERGY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox42_var1_Property = CxvPropertyDeclaration.Register("MMComboBox42_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FORCE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox41_var1_Property = CxvPropertyDeclaration.Register("MMComboBox41_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.POWER",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox40_var1_Property = CxvPropertyDeclaration.Register("MMComboBox40_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.WORK",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox11_var1_Property = CxvPropertyDeclaration.Register("MMComboBox11_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.CURRENT",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox12_var1_Property = CxvPropertyDeclaration.Register("MMComboBox12_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLTAGE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.RESISTANCE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox14_var1_Property = CxvPropertyDeclaration.Register("MMComboBox14_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ELEC-POWER",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox52_var1_Property = CxvPropertyDeclaration.Register("MMComboBox52_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.TIME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox51_var1_Property = CxvPropertyDeclaration.Register("MMComboBox51_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-TIME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox50_var1_Property = CxvPropertyDeclaration.Register("MMComboBox50_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.LN-INV-TIME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox77_var1_Property = CxvPropertyDeclaration.Register("MMComboBox77_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.CONTENTS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox76_var1_Property = CxvPropertyDeclaration.Register("MMComboBox76_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-CONC",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_14_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_14_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-CONC",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_13_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.NUM-CONC",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox75_var1_Property = CxvPropertyDeclaration.Register("MMComboBox75_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.NUM-CON-RATE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox74_var1_Property = CxvPropertyDeclaration.Register("MMComboBox74_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.POP-DENSITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox79_var1_Property = CxvPropertyDeclaration.Register("MMComboBox79_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-CONTENT",
			Sorted = true
		});

		public object MMComboBox78_var1 => GetValue(MMComboBox78_var1_Property);

		public object MMComboBox18_1_var1 => GetValue(MMComboBox18_1_var1_Property);

		public object MMComboBox24_var1 => GetValue(MMComboBox24_var1_Property);

		public object MMComboBox43_var1 => GetValue(MMComboBox43_var1_Property);

		public object MMComboBox42_var1 => GetValue(MMComboBox42_var1_Property);

		public object MMComboBox41_var1 => GetValue(MMComboBox41_var1_Property);

		public object MMComboBox40_var1 => GetValue(MMComboBox40_var1_Property);

		public object MMComboBox11_var1 => GetValue(MMComboBox11_var1_Property);

		public object MMComboBox12_var1 => GetValue(MMComboBox12_var1_Property);

		public object MMComboBox13_var1 => GetValue(MMComboBox13_var1_Property);

		public object MMComboBox14_var1 => GetValue(MMComboBox14_var1_Property);

		public object MMComboBox52_var1 => GetValue(MMComboBox52_var1_Property);

		public object MMComboBox51_var1 => GetValue(MMComboBox51_var1_Property);

		public object MMComboBox50_var1 => GetValue(MMComboBox50_var1_Property);

		public object MMComboBox77_var1 => GetValue(MMComboBox77_var1_Property);

		public object MMComboBox76_var1 => GetValue(MMComboBox76_var1_Property);

		public object MMComboBox18_14_var1 => GetValue(MMComboBox18_14_var1_Property);

		public object MMComboBox18_13_var1 => GetValue(MMComboBox18_13_var1_Property);

		public object MMComboBox75_var1 => GetValue(MMComboBox75_var1_Property);

		public object MMComboBox74_var1 => GetValue(MMComboBox74_var1_Property);

		public object MMComboBox79_var1 => GetValue(MMComboBox79_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Units_Concen")]
	public class MMSetup_Units_Concen : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame11;

		internal MMLabel MMComboBox43_label;

		internal MMComboEdit MMComboBox43;

		internal MMLabel MMComboBox42_label;

		internal MMComboEdit MMComboBox42;

		internal MMLabel MMComboBox41_label;

		internal MMComboEdit MMComboBox41;

		internal MMLabel MMComboBox40_label;

		internal MMComboEdit MMComboBox40;

		internal MMLabel MMComboBox11_label;

		internal MMComboEdit MMComboBox11;

		internal MMLabel MMComboBox12_label;

		internal MMComboEdit MMComboBox12;

		internal MMLabel MMComboBox13_label;

		internal MMComboEdit MMComboBox13;

		internal MMLabel MMComboBox14_label;

		internal MMComboEdit MMComboBox14;

		internal MMGroupBox MMFrame17;

		internal MMLabel MMComboBox77_label;

		internal MMComboEdit MMComboBox77;

		internal MMLabel MMComboBox76_label;

		internal MMComboEdit MMComboBox76;

		internal MMLabel MMComboBox18_14_label;

		internal MMComboEdit MMComboBox18_14;

		internal MMLabel MMComboBox18_13_label;

		internal MMComboEdit MMComboBox18_13;

		internal MMLabel MMComboBox75_label;

		internal MMComboEdit MMComboBox75;

		internal MMLabel MMComboBox74_label;

		internal MMComboEdit MMComboBox74;

		internal MMLabel MMComboBox79_label;

		internal MMComboEdit MMComboBox79;

		internal MMGroupBox MMFrame13;

		internal MMLabel MMComboBox52_label;

		internal MMComboEdit MMComboBox52;

		internal MMLabel MMComboBox51_label;

		internal MMComboEdit MMComboBox51;

		internal MMLabel MMComboBox50_label;

		internal MMComboEdit MMComboBox50;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox78_label;

		internal MMComboEdit MMComboBox78;

		internal MMLabel MMComboBox18_1_label;

		internal MMComboEdit MMComboBox18_1;

		internal MMLabel MMComboBox24_label;

		internal MMComboEdit MMComboBox24;

		private bool _contentLoaded;

		public MMSetup_Units_Concen()
		{
			base.ViewModelType = typeof(MMSetup_Units_Concen_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_concen.xaml", UriKind.Relative);
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
				MMFrame11 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox43_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox43 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox42_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox42 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox41_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox41 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox40_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox40 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox11_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox11 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox12_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox12 = (MMComboEdit)target;
				break;
			case 14:
				MMComboBox13_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox13 = (MMComboEdit)target;
				break;
			case 16:
				MMComboBox14_label = (MMLabel)target;
				break;
			case 17:
				MMComboBox14 = (MMComboEdit)target;
				break;
			case 18:
				MMFrame17 = (MMGroupBox)target;
				break;
			case 19:
				MMComboBox77_label = (MMLabel)target;
				break;
			case 20:
				MMComboBox77 = (MMComboEdit)target;
				break;
			case 21:
				MMComboBox76_label = (MMLabel)target;
				break;
			case 22:
				MMComboBox76 = (MMComboEdit)target;
				break;
			case 23:
				MMComboBox18_14_label = (MMLabel)target;
				break;
			case 24:
				MMComboBox18_14 = (MMComboEdit)target;
				break;
			case 25:
				MMComboBox18_13_label = (MMLabel)target;
				break;
			case 26:
				MMComboBox18_13 = (MMComboEdit)target;
				break;
			case 27:
				MMComboBox75_label = (MMLabel)target;
				break;
			case 28:
				MMComboBox75 = (MMComboEdit)target;
				break;
			case 29:
				MMComboBox74_label = (MMLabel)target;
				break;
			case 30:
				MMComboBox74 = (MMComboEdit)target;
				break;
			case 31:
				MMComboBox79_label = (MMLabel)target;
				break;
			case 32:
				MMComboBox79 = (MMComboEdit)target;
				break;
			case 33:
				MMFrame13 = (MMGroupBox)target;
				break;
			case 34:
				MMComboBox52_label = (MMLabel)target;
				break;
			case 35:
				MMComboBox52 = (MMComboEdit)target;
				break;
			case 36:
				MMComboBox51_label = (MMLabel)target;
				break;
			case 37:
				MMComboBox51 = (MMComboEdit)target;
				break;
			case 38:
				MMComboBox50_label = (MMLabel)target;
				break;
			case 39:
				MMComboBox50 = (MMComboEdit)target;
				break;
			case 40:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 41:
				MMComboBox78_label = (MMLabel)target;
				break;
			case 42:
				MMComboBox78 = (MMComboEdit)target;
				break;
			case 43:
				MMComboBox18_1_label = (MMLabel)target;
				break;
			case 44:
				MMComboBox18_1 = (MMComboEdit)target;
				break;
			case 45:
				MMComboBox24_label = (MMLabel)target;
				break;
			case 46:
				MMComboBox24 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Curren_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cmbCostRate_var1_Property = CxvPropertyDeclaration.Register("cmbCostRate_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.COST-RATE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbMolePrice_var1_Property = CxvPropertyDeclaration.Register("cmbMolePrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbVolPrice_var1_Property = CxvPropertyDeclaration.Register("cmbVolPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbMassPrice_var1_Property = CxvPropertyDeclaration.Register("cmbMassPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.UNIT-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbItemPrice_9_var1_Property = CxvPropertyDeclaration.Register("cmbItemPrice_9_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ITEM-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbFiscal_10_var1_Property = CxvPropertyDeclaration.Register("cmbFiscal_10_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FISCAL",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbEngerPrice_var1_Property = CxvPropertyDeclaration.Register("cmbEngerPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENERGY-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbElecPrice_var1_Property = CxvPropertyDeclaration.Register("cmbElecPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ELEC-PRICE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration cmbAreaPrice_var1_Property = CxvPropertyDeclaration.Register("cmbAreaPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.AREA-PRICE",
			Sorted = true
		});

		private bool _isCurrencyEnabled;

		private string _display;

		private CxvPropertyWatch _watch;

		private EventHandler _watch_PropertyChangedHandler;

		public object cmbCostRate_var1 => GetValue(cmbCostRate_var1_Property);

		public object cmbMolePrice_var1 => GetValue(cmbMolePrice_var1_Property);

		public object cmbVolPrice_var1 => GetValue(cmbVolPrice_var1_Property);

		public object cmbMassPrice_var1 => GetValue(cmbMassPrice_var1_Property);

		public object cmbItemPrice_9_var1 => GetValue(cmbItemPrice_9_var1_Property);

		public object cmbFiscal_10_var1 => GetValue(cmbFiscal_10_var1_Property);

		public object cmbEngerPrice_var1 => GetValue(cmbEngerPrice_var1_Property);

		public object cmbElecPrice_var1 => GetValue(cmbElecPrice_var1_Property);

		public object cmbAreaPrice_var1 => GetValue(cmbAreaPrice_var1_Property);

		public bool IsCurrencyEnabled
		{
			get
			{
				return _isCurrencyEnabled;
			}
			set
			{
				_isCurrencyEnabled = value;
				OnPropertyChanged("IsCurrencyEnabled");
			}
		}

		public string Display
		{
			get
			{
				if (_display == null)
				{
					object obj = ExpandDataPathAndGet("@main.Input.CURRENCY", "value");
					if (obj == null || obj == DBNull.Value)
					{
						_display = "$";
					}
					else
					{
						_display = CxsConverter.ValueToString(obj);
					}
				}
				return _display;
			}
			set
			{
				if (!string.IsNullOrEmpty(value) && _display != value)
				{
					ExpandDataPathAndSet("@main.Input.CURRENCY", "value", value);
					CurrencyChanged(value);
					_display = value;
					OnPropertyChanged("Display");
				}
			}
		}

		public IEnumerable DisplayOptions
		{
			get
			{
				List<string> list = new List<string>();
				list.Add("$");
				string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("Top.appModelV8.Setup.Currency.Input.FACTOR", "child_ids"));
				if (array != null && array.Length != 0)
				{
					list.AddRange(array);
				}
				return list;
			}
		}

		private EventHandler watch_PropertyChangedHandler
		{
			get
			{
				if (_watch_PropertyChangedHandler == null)
				{
					_watch_PropertyChangedHandler = delegate
					{
						CheckCurrencyEnabled();
					};
				}
				return _watch_PropertyChangedHandler;
			}
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				CheckCurrencyEnabled();
			}
			base.OnUpdateData();
		}

		private void CheckCurrencyEnabled()
		{
			if (_watch != null)
			{
				_watch.PropertyDependencyChanged -= watch_PropertyChangedHandler;
				_watch.Clear();
			}
			else
			{
				_watch = new CxvPropertyWatch();
			}
			bool? flag = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.Unit-Types.FISCAL", "can_enter", null, _watch));
			if (flag.HasValue)
			{
				IsCurrencyEnabled = flag.Value;
			}
			if (!_watch.IsEmpty)
			{
				_watch.PropertyDependencyChanged += watch_PropertyChangedHandler;
			}
			else
			{
				_watch = null;
			}
		}

		private void CurrencyChanged(string curCurrency)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.AREA-PRICE", "value"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.ELEC-PRICE", "value"));
			string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.ENERGY-PRICE", "value"));
			string text4 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.FISCAL", "value"));
			string text5 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.ITEM-PRICE", "value"));
			string text6 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.UNIT-PRICE", "value"));
			string text7 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.MOLE-PRICE", "value"));
			string text8 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.VOLUME-PRICE", "value"));
			string text9 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Unit-Types.COST-RATE", "value"));
			text = text.Replace(_display, curCurrency);
			text2 = text2.Replace(_display, curCurrency);
			text3 = text3.Replace(_display, curCurrency);
			text4 = text4.Replace(_display, curCurrency);
			text5 = text5.Replace(_display, curCurrency);
			text6 = text6.Replace(_display, curCurrency);
			text7 = text7.Replace(_display, curCurrency);
			text8 = text8.Replace(_display, curCurrency);
			text9 = text9.Replace(_display, curCurrency);
			ExpandDataPathAndSet("@main.Unit-Types.AREA-PRICE", "value", text);
			ExpandDataPathAndSet("@main.Unit-Types.ELEC-PRICE", "value", text2);
			ExpandDataPathAndSet("@main.Unit-Types.ENERGY-PRICE", "value", text3);
			ExpandDataPathAndSet("@main.Unit-Types.FISCAL", "value", text4);
			ExpandDataPathAndSet("@main.Unit-Types.ITEM-PRICE", "value", text5);
			ExpandDataPathAndSet("@main.Unit-Types.UNIT-PRICE", "value", text6);
			ExpandDataPathAndSet("@main.Unit-Types.MOLE-PRICE", "value", text7);
			ExpandDataPathAndSet("@main.Unit-Types.VOLUME-PRICE", "value", text8);
			ExpandDataPathAndSet("@main.Unit-Types.COST-RATE", "value", text9);
		}
	}
	[ProgId("MMSetup.MMSetup_Units_Curren")]
	public class MMSetup_Units_Curren : MMTabPage, IComponentConnector
	{
		internal MMLabel labCurrency;

		internal MMComboEdit cmbCurrecy;

		internal MMGroupBox MMFrame15;

		internal MMLabel cmbAreaPrice_label;

		internal MMComboEdit cmbAreaPrice;

		internal MMLabel cmbElecPrice_label;

		internal MMComboEdit cmbElecPrice;

		internal MMLabel cmbEngerPrice_label;

		internal MMComboEdit cmbEngerPrice;

		internal MMLabel cmbFiscal_10_label;

		internal MMComboEdit cmbFiscal_10;

		internal MMLabel cmbItemPrice_9_label;

		internal MMComboEdit cmbItemPrice_9;

		internal MMLabel cmbMassPrice_label;

		internal MMComboEdit cmbMassPrice;

		internal MMLabel cmbMolePrice_label;

		internal MMComboEdit cmbMolePrice;

		internal MMLabel cmbVolPrice_label;

		internal MMComboEdit cmbVolPrice;

		internal MMLabel cmbCostRate_label;

		internal MMComboEdit cmbCostRate;

		private bool _contentLoaded;

		public MMSetup_Units_Curren()
		{
			base.ViewModelType = typeof(MMSetup_Units_Curren_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_curren.xaml", UriKind.Relative);
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
				labCurrency = (MMLabel)target;
				break;
			case 2:
				cmbCurrecy = (MMComboEdit)target;
				break;
			case 3:
				MMFrame15 = (MMGroupBox)target;
				break;
			case 4:
				cmbAreaPrice_label = (MMLabel)target;
				break;
			case 5:
				cmbAreaPrice = (MMComboEdit)target;
				break;
			case 6:
				cmbElecPrice_label = (MMLabel)target;
				break;
			case 7:
				cmbElecPrice = (MMComboEdit)target;
				break;
			case 8:
				cmbEngerPrice_label = (MMLabel)target;
				break;
			case 9:
				cmbEngerPrice = (MMComboEdit)target;
				break;
			case 10:
				cmbFiscal_10_label = (MMLabel)target;
				break;
			case 11:
				cmbFiscal_10 = (MMComboEdit)target;
				break;
			case 12:
				cmbItemPrice_9_label = (MMLabel)target;
				break;
			case 13:
				cmbItemPrice_9 = (MMComboEdit)target;
				break;
			case 14:
				cmbMassPrice_label = (MMLabel)target;
				break;
			case 15:
				cmbMassPrice = (MMComboEdit)target;
				break;
			case 16:
				cmbMolePrice_label = (MMLabel)target;
				break;
			case 17:
				cmbMolePrice = (MMComboEdit)target;
				break;
			case 18:
				cmbVolPrice_label = (MMLabel)target;
				break;
			case 19:
				cmbVolPrice = (MMComboEdit)target;
				break;
			case 20:
				cmbCostRate_label = (MMLabel)target;
				break;
			case 21:
				cmbCostRate = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Energy_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox48_var1_Property = CxvPropertyDeclaration.Register("MMComboBox48_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-HEAT-CA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox49_var1_Property = CxvPropertyDeclaration.Register("MMComboBox49_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-HEAT-CA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_5_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOL-HEAT-CAP",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox36_var1_Property = CxvPropertyDeclaration.Register("MMComboBox36_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOL-ENTHALPY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox33_var1_Property = CxvPropertyDeclaration.Register("MMComboBox33_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-ENTHALP",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox34_var1_Property = CxvPropertyDeclaration.Register("MMComboBox34_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-ENTHALP",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox35_var1_Property = CxvPropertyDeclaration.Register("MMComboBox35_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENTHALPY-FLO",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_3_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENTHALPY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox37_var1_Property = CxvPropertyDeclaration.Register("MMComboBox37_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-ENTROPY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox38_var1_Property = CxvPropertyDeclaration.Register("MMComboBox38_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-ENTROPY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox39_var1_Property = CxvPropertyDeclaration.Register("MMComboBox39_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENTROPY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox46_var1_Property = CxvPropertyDeclaration.Register("MMComboBox46_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.UA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox45_var1_Property = CxvPropertyDeclaration.Register("MMComboBox45_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-HT-C",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox44_var1_Property = CxvPropertyDeclaration.Register("MMComboBox44_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.HEAT-TRANS-C",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_6_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.HEAT-FLUX",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox47_var1_Property = CxvPropertyDeclaration.Register("MMComboBox47_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.HEAT",
			Sorted = true
		});

		public object MMComboBox48_var1 => GetValue(MMComboBox48_var1_Property);

		public object MMComboBox49_var1 => GetValue(MMComboBox49_var1_Property);

		public object MMComboBox18_5_var1 => GetValue(MMComboBox18_5_var1_Property);

		public object MMComboBox36_var1 => GetValue(MMComboBox36_var1_Property);

		public object MMComboBox33_var1 => GetValue(MMComboBox33_var1_Property);

		public object MMComboBox34_var1 => GetValue(MMComboBox34_var1_Property);

		public object MMComboBox35_var1 => GetValue(MMComboBox35_var1_Property);

		public object MMComboBox18_3_var1 => GetValue(MMComboBox18_3_var1_Property);

		public object MMComboBox37_var1 => GetValue(MMComboBox37_var1_Property);

		public object MMComboBox38_var1 => GetValue(MMComboBox38_var1_Property);

		public object MMComboBox39_var1 => GetValue(MMComboBox39_var1_Property);

		public object MMComboBox46_var1 => GetValue(MMComboBox46_var1_Property);

		public object MMComboBox45_var1 => GetValue(MMComboBox45_var1_Property);

		public object MMComboBox44_var1 => GetValue(MMComboBox44_var1_Property);

		public object MMComboBox18_6_var1 => GetValue(MMComboBox18_6_var1_Property);

		public object MMComboBox47_var1 => GetValue(MMComboBox47_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Units_Energy")]
	public class MMSetup_Units_Energy : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame9;

		internal MMLabel MMComboBox18_3_label;

		internal MMComboEdit MMComboBox18_3;

		internal MMLabel MMComboBox35_label;

		internal MMComboEdit MMComboBox35;

		internal MMLabel MMComboBox34_label;

		internal MMComboEdit MMComboBox34;

		internal MMLabel MMComboBox33_label;

		internal MMComboEdit MMComboBox33;

		internal MMLabel MMComboBox36_label;

		internal MMComboEdit MMComboBox36;

		internal MMGroupBox MMFrame12;

		internal MMLabel MMComboBox47_label;

		internal MMComboEdit MMComboBox47;

		internal MMLabel MMComboBox18_6_label;

		internal MMComboEdit MMComboBox18_6;

		internal MMLabel MMComboBox44_label;

		internal MMComboEdit MMComboBox44;

		internal MMLabel MMComboBox45_label;

		internal MMComboEdit MMComboBox45;

		internal MMLabel MMComboBox46_label;

		internal MMComboEdit MMComboBox46;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox48_label;

		internal MMComboEdit MMComboBox48;

		internal MMLabel MMComboBox49_label;

		internal MMComboEdit MMComboBox49;

		internal MMLabel MMComboBox18_5_label;

		internal MMComboEdit MMComboBox18_5;

		internal MMGroupBox MMFrame10;

		internal MMLabel MMComboBox39_label;

		internal MMComboEdit MMComboBox39;

		internal MMLabel MMComboBox38_label;

		internal MMComboEdit MMComboBox38;

		internal MMLabel MMComboBox37_label;

		internal MMComboEdit MMComboBox37;

		private bool _contentLoaded;

		public MMSetup_Units_Energy()
		{
			base.ViewModelType = typeof(MMSetup_Units_Energy_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_energy.xaml", UriKind.Relative);
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
				MMFrame9 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox18_3_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox18_3 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox35_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox35 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox34_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox34 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox33_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox33 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox36_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox36 = (MMComboEdit)target;
				break;
			case 12:
				MMFrame12 = (MMGroupBox)target;
				break;
			case 13:
				MMComboBox47_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox47 = (MMComboEdit)target;
				break;
			case 15:
				MMComboBox18_6_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox18_6 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox44_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox44 = (MMComboEdit)target;
				break;
			case 19:
				MMComboBox45_label = (MMLabel)target;
				break;
			case 20:
				MMComboBox45 = (MMComboEdit)target;
				break;
			case 21:
				MMComboBox46_label = (MMLabel)target;
				break;
			case 22:
				MMComboBox46 = (MMComboEdit)target;
				break;
			case 23:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 24:
				MMComboBox48_label = (MMLabel)target;
				break;
			case 25:
				MMComboBox48 = (MMComboEdit)target;
				break;
			case 26:
				MMComboBox49_label = (MMLabel)target;
				break;
			case 27:
				MMComboBox49 = (MMComboEdit)target;
				break;
			case 28:
				MMComboBox18_5_label = (MMLabel)target;
				break;
			case 29:
				MMComboBox18_5 = (MMComboEdit)target;
				break;
			case 30:
				MMFrame10 = (MMGroupBox)target;
				break;
			case 31:
				MMComboBox39_label = (MMLabel)target;
				break;
			case 32:
				MMComboBox39 = (MMComboEdit)target;
				break;
			case 33:
				MMComboBox38_label = (MMLabel)target;
				break;
			case 34:
				MMComboBox38 = (MMComboEdit)target;
				break;
			case 35:
				MMComboBox37_label = (MMLabel)target;
				break;
			case 36:
				MMComboBox37 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Miscel_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-EMISSIO",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox59_var1_Property = CxvPropertyDeclaration.Register("MMComboBox59_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.WATER-RATE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox88_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox88_1_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOM-INERTIA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox84_var1_Property = CxvPropertyDeclaration.Register("MMComboBox84_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SOUND-LEVEL",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_15_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.CHROM-VEL",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox82_var1_Property = CxvPropertyDeclaration.Register("MMComboBox82_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SOLVENT-PERM",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox81_var1_Property = CxvPropertyDeclaration.Register("MMComboBox81_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SOLUTE-PERM",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox73_var1_Property = CxvPropertyDeclaration.Register("MMComboBox73_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SPEC-FLT-RES",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox87_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox87_0_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.BOND-WORK-IN",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox86_var1_Property = CxvPropertyDeclaration.Register("MMComboBox86_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FILTER-RESIS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox15_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox16_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FREQUENCY",
			Sorted = true
		});

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object MMComboBox59_var1 => GetValue(MMComboBox59_var1_Property);

		public object MMComboBox88_1_var1 => GetValue(MMComboBox88_1_var1_Property);

		public object MMComboBox84_var1 => GetValue(MMComboBox84_var1_Property);

		public object MMComboBox18_15_var1 => GetValue(MMComboBox18_15_var1_Property);

		public object MMComboBox82_var1 => GetValue(MMComboBox82_var1_Property);

		public object MMComboBox81_var1 => GetValue(MMComboBox81_var1_Property);

		public object MMComboBox73_var1 => GetValue(MMComboBox73_var1_Property);

		public object MMComboBox87_0_var1 => GetValue(MMComboBox87_0_var1_Property);

		public object MMComboBox86_var1 => GetValue(MMComboBox86_var1_Property);

		public object MMComboBox15_var1 => GetValue(MMComboBox15_var1_Property);

		public object MMComboBox16_var1 => GetValue(MMComboBox16_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Units_Miscel")]
	public class MMSetup_Units_Miscel : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame19;

		internal MMLabel MMComboBox18_15_label;

		internal MMComboEdit MMComboBox18_15;

		internal MMLabel MMComboBox87_0_label;

		internal MMComboEdit MMComboBox87_0;

		internal MMLabel MMComboBox86_label;

		internal MMComboEdit MMComboBox86;

		internal MMLabel MMComboBox88_1_label;

		internal MMComboEdit MMComboBox88_1;

		internal MMLabel MMComboBox81_label;

		internal MMComboEdit MMComboBox81;

		internal MMLabel MMComboBox82_label;

		internal MMComboEdit MMComboBox82;

		internal MMLabel MMComboBox84_label;

		internal MMComboEdit MMComboBox84;

		internal MMLabel MMComboBox73_label;

		internal MMComboEdit MMComboBox73;

		internal MMLabel MMComboBox59_label;

		internal MMComboEdit MMComboBox59;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox15_label;

		internal MMComboEdit MMComboBox15;

		internal MMLabel MMComboBox16_label;

		internal MMComboEdit MMComboBox16;

		private bool _contentLoaded;

		public MMSetup_Units_Miscel()
		{
			base.ViewModelType = typeof(MMSetup_Units_Miscel_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_miscel.xaml", UriKind.Relative);
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
				MMFrame19 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox18_15_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox18_15 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox87_0_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox87_0 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox86_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox86 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox88_1_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox88_1 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox81_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox81 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox82_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox82 = (MMComboEdit)target;
				break;
			case 14:
				MMComboBox84_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox84 = (MMComboEdit)target;
				break;
			case 16:
				MMComboBox73_label = (MMLabel)target;
				break;
			case 17:
				MMComboBox73 = (MMComboEdit)target;
				break;
			case 18:
				MMComboBox59_label = (MMLabel)target;
				break;
			case 19:
				MMComboBox59 = (MMComboEdit)target;
				break;
			case 20:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 21:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 22:
				MMComboBox15_label = (MMLabel)target;
				break;
			case 23:
				MMComboBox15 = (MMComboEdit)target;
				break;
			case 24:
				MMComboBox16_label = (MMLabel)target;
				break;
			case 25:
				MMComboBox16 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Search_ViewModel : MMTabPageViewModel
	{
		public class scrSearch_GridData_ItemTemplate : MMViewModel
		{
			private int? _index;

			public static readonly CxvPropertyDeclaration MMLBUText1_unitlabel_Property = CxvPropertyDeclaration.Register("MMLBUText1_unitlabel", typeof(scrSearch_GridData_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "itemlabel",
				IsCalculated = false,
				IsReadOnly = true,
				IsLocal = true
			});

			public static readonly CxvPropertyDeclaration MMLBUText1_unitname_Property = CxvPropertyDeclaration.Register("MMLBUText1_unitname", typeof(scrSearch_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Unit-Types.@itemtype"
			});

			public object MMLBUText1_unitlabel => GetValue(MMLBUText1_unitlabel_Property);

			public object MMLBUText1_unitname => GetValue(MMLBUText1_unitname_Property);

			internal void EnsureData()
			{
				if (!_index.HasValue)
				{
					_index = ResolveParameter("y") as int?;
					if (_index.HasValue)
					{
						ResolveUpdateParameter("itemlabel", VarLabel[_index.Value], localOnly: true);
						ResolveUpdateParameter("itemtype", varnames[_index.Value], localOnly: true);
					}
				}
			}

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("MMLBUText1_unitlabel.Value", null));
			}
		}

		private ICommand _cmdHelp_Command;

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration unitname_Property = CxvPropertyDeclaration.Register("unitname", typeof(MMSetup_Units_Search_ViewModel), new CxvParameterProperty
		{
			Parameter = "unitname"
		});

		public static readonly CxvPropertyDeclaration txtUnitName_unitlabel_Property = CxvPropertyDeclaration.Register("txtUnitName_unitlabel", typeof(MMSetup_Units_Search_ViewModel), new CxvVariableProperty
		{
			DataPath = "unitlabel"
		});

		public static readonly CxvPropertyDeclaration MMComboBox46_var1_Property = CxvPropertyDeclaration.Register("MMComboBox46_var1", typeof(MMSetup_Units_Search_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.@unitname",
			Sorted = true
		});

		private const int varCount = 120;

		private static List<string> VarLabel = new List<string>
		{
			WpfFormsResources.MMSetup_Units_Search_acceleration,
			WpfFormsResources.MMSetup_Units_Search_Angle,
			WpfFormsResources.MMSetup_Units_Search_Area,
			WpfFormsResources.MMSetup_Units_Search_Area_price,
			WpfFormsResources.MMSetup_Units_Search_Area_usage,
			WpfFormsResources.MMSetup_Units_Search_Bond_work_index,
			WpfFormsResources.MMSetup_Units_Search_Chromatic_velocity,
			WpfFormsResources.MMSetup_Units_Search_Composition,
			WpfFormsResources.MMSetup_Units_Search_Cost_rate,
			WpfFormsResources.MMSetup_Units_Search_Content,
			WpfFormsResources.MMSetup_Units_Search_Current,
			WpfFormsResources.MMSetup_Units_Search_Delta_T,
			WpfFormsResources.MMSetup_Units_Search_Density,
			WpfFormsResources.MMSetup_Units_Search_Diffusivity,
			WpfFormsResources.MMSetup_Units_Search_Dimensionless,
			WpfFormsResources.MMSetup_Units_Search_Dipole_moment,
			WpfFormsResources.MMSetup_Units_Search_Electric_conductivity,
			WpfFormsResources.MMSetup_Units_Search_Electric_power,
			WpfFormsResources.MMSetup_Units_Search_Electric_price,
			WpfFormsResources.MMSetup_Units_Search_Energy,
			WpfFormsResources.MMSetup_Units_Search_Energy_price,
			WpfFormsResources.MMSetup_Units_Search_Energy_rate_per_volume,
			WpfFormsResources.MMSetup_Units_Search_Enthalpy,
			WpfFormsResources.MMSetup_Units_Search_Enthalpy_cycle,
			WpfFormsResources.MMSetup_Units_Search_Enthalpy_flow,
			WpfFormsResources.MMSetup_Units_Search_Enthalpy_opr,
			WpfFormsResources.MMSetup_Units_Search_Entropy,
			WpfFormsResources.MMSetup_Units_Search_F_factor,
			WpfFormsResources.MMSetup_Units_Search_Filter_resistance,
			WpfFormsResources.MMSetup_Units_Search_Fiscal,
			WpfFormsResources.MMSetup_Units_Search_Flow,
			WpfFormsResources.MMSetup_Units_Search_Flux,
			WpfFormsResources.MMSetup_Units_Search_Flux_heat_area,
			WpfFormsResources.MMSetup_Units_Search_Flux_mole,
			WpfFormsResources.MMSetup_Units_Search_Force,
			WpfFormsResources.MMSetup_Units_Search_Frequency,
			WpfFormsResources.MMSetup_Units_Search_Head,
			WpfFormsResources.MMSetup_Units_Search_Heat,
			WpfFormsResources.MMSetup_Units_Search_Heat_flux,
			WpfFormsResources.MMSetup_Units_Search_Heat_transfer_coef,
			WpfFormsResources.MMSetup_Units_Search_Inverse_THC,
			WpfFormsResources.MMSetup_Units_Search_Inverse_area,
			WpfFormsResources.MMSetup_Units_Search_Inverse_length,
			WpfFormsResources.MMSetup_Units_Search_Inverse_pressure,
			WpfFormsResources.MMSetup_Units_Search_Inverse_temperature,
			WpfFormsResources.MMSetup_Units_Search_Inverse_time,
			WpfFormsResources.MMSetup_Units_Search_inverse_vel,
			WpfFormsResources.MMSetup_Units_Search_Item_price,
			WpfFormsResources.MMSetup_Units_Search_Length,
			WpfFormsResources.MMSetup_Units_Search_Ln_inv_time,
			WpfFormsResources.MMSetup_Units_Search_Mass,
			WpfFormsResources.MMSetup_Units_Search_Mass_conc,
			WpfFormsResources.MMSetup_Units_Search_Mass_content,
			WpfFormsResources.MMSetup_Units_Search_Mass_cycle,
			WpfFormsResources.MMSetup_Units_Search_Mass_density,
			WpfFormsResources.MMSetup_Units_Search_Mass_enthalpy,
			WpfFormsResources.MMSetup_Units_Search_Mass_entropy,
			WpfFormsResources.MMSetup_Units_Search_Mass_flow,
			WpfFormsResources.MMSetup_Units_Search_Mass_flux,
			WpfFormsResources.MMSetup_Units_Search_MassFrac,
			WpfFormsResources.MMSetup_Units_Search_Mass_heat_capacity,
			WpfFormsResources.MMSetup_Units_Search_MassLength,
			WpfFormsResources.MMSetup_Units_Search_Mass_oper,
			WpfFormsResources.MMSetup_Units_Search_Mass_transfer_coef,
			WpfFormsResources.MMSetup_Units_Search_Mole_conc,
			WpfFormsResources.MMSetup_Units_Search_Mole_cycle,
			WpfFormsResources.MMSetup_Units_Search_Mole_density,
			WpfFormsResources.MMSetup_Units_Search_Mole_enthalpy,
			WpfFormsResources.MMSetup_Units_Search_Mole_entropy,
			WpfFormsResources.MMSetup_Units_Search_Mole_flow,
			WpfFormsResources.MMSetup_Units_Search_MoleFrac,
			WpfFormsResources.MMSetup_Units_Search_Mole_heat_capacity,
			WpfFormsResources.MMSetup_Units_Search_Mole_oper,
			WpfFormsResources.MMSetup_Units_Search_Mole_reaction_rate_vol,
			WpfFormsResources.MMSetup_Units_Search_Mole_reaction_rate_wt,
			WpfFormsResources.MMSetup_Units_Search_Mole_volume,
			WpfFormsResources.MMSetup_Units_Search_Mole_flowLength,
			WpfFormsResources.MMSetup_Units_Search_Moles,
			WpfFormsResources.MMSetup_Units_Search_MoleWeight,
			WpfFormsResources.MMSetup_Units_Search_Moment_of_inertia,
			WpfFormsResources.MMSetup_Units_Search_Number_conc_rate,
			WpfFormsResources.MMSetup_Units_Search_Number_concentration,
			WpfFormsResources.MMSetup_Units_Search_Pack_factor,
			WpfFormsResources.MMSetup_Units_Search_Pdrop_per_ht,
			WpfFormsResources.MMSetup_Units_Search_Population_density,
			WpfFormsResources.MMSetup_Units_Search_Power,
			WpfFormsResources.MMSetup_Units_Search_PowerVolume,
			WpfFormsResources.MMSetup_Units_Search_Pdrop,
			WpfFormsResources.MMSetup_Units_Search_Pressure,
			WpfFormsResources.MMSetup_Units_Search_RhoV2,
			WpfFormsResources.MMSetup_Units_Search_Solubility_parameter,
			WpfFormsResources.MMSetup_Units_Search_Solute_permeability,
			WpfFormsResources.MMSetup_Units_Search_Solvent_permeability,
			WpfFormsResources.MMSetup_Units_Search_Sound_level,
			WpfFormsResources.MMSetup_Units_Search_Sp_filter_resistance,
			WpfFormsResources.MMSetup_Units_Search_Specific_area,
			WpfFormsResources.MMSetup_Units_Search_Surface_tension,
			WpfFormsResources.MMSetup_Units_Search_TemperatureVolume,
			WpfFormsResources.MMSetup_Units_Search_Temperature,
			WpfFormsResources.MMSetup_Units_Search_Thermal_conductivity,
			WpfFormsResources.MMSetup_Units_Search_Time,
			WpfFormsResources.MMSetup_Units_Search_UA,
			WpfFormsResources.MMSetup_Units_Search_Unit_price,
			WpfFormsResources.MMSetup_Units_Search_Velocity,
			WpfFormsResources.MMSetup_Units_Search_VflowLength,
			WpfFormsResources.MMSetup_Units_Search_VflowRPM,
			WpfFormsResources.MMSetup_Units_Search_Viscosity,
			WpfFormsResources.MMSetup_Units_Search_Voltage,
			WpfFormsResources.MMSetup_Units_Search_Volume,
			WpfFormsResources.MMSetup_Units_Search_Volume_cycle,
			WpfFormsResources.MMSetup_Units_Search_Volume_enthalpy,
			WpfFormsResources.MMSetup_Units_Search_Volume_flow,
			WpfFormsResources.MMSetup_Units_Search_Volume_heat_capacity,
			WpfFormsResources.MMSetup_Units_Search_Volume_oper,
			WpfFormsResources.MMSetup_Units_Search_Volume_price,
			WpfFormsResources.MMSetup_Units_Search_Volume_usage,
			WpfFormsResources.MMSetup_Units_Search_VolumeEnergy,
			WpfFormsResources.MMSetup_Units_Search_VolumeMass,
			WpfFormsResources.MMSetup_Units_Search_Water_rate,
			WpfFormsResources.MMSetup_Units_Search_Work
		};

		private static List<string> varnames = new List<string>
		{
			"ACCELERATION", "ANGLE", "AREA", "AREA-PRICE", "AREA-USAGE", "BOND-WORK-IN", "CHROM-VEL", "COMPOSITION", "COST-RATE", "CONTENTS",
			"CURRENT", "DELTA-T", "DENSITY", "DIFFUSIVITY", "DIMENSIONLES", "DIPOLEMOMENT", "SIEMENS-M", "ELEC-POWER", "ELEC-PRICE", "ENERGY",
			"ENERGY-PRICE", "HEAT-RATE-V", "ENTHALPY", "ENTHALPY-CYC", "ENTHALPY-FLO", "ENTHALPY-OPR", "ENTROPY", "F-FACTOR", "FILTER-RESIS", "FISCAL",
			"FLOW", "FLUX", "FLUX-HEAT-AR", "FLUX-MOLE", "FORCE", "FREQUENCY", "HEAD", "HEAT", "HEAT-FLUX", "HEAT-TRANS-C",
			"INVERSE-HT-C", "INVERSE-AREA", "INVERSE-LENG", "INVERSE-PRES", "INVERSE-TEMP", "INVERSE-TIME", "INVERSE-VEL", "ITEM-PRICE", "LENGTH", "LN-INV-TIME",
			"MASS", "MASS-CONC", "MASS-CONTENT", "MASS-CYCL", "MASS-DENSITY", "MASS-ENTHALP", "MASS-ENTROPY", "MASS-FLOW", "MASS-FLUX", "MASSFRAC",
			"MASS-HEAT-CA", "MASS-PER-LEN", "MASS-OPER", "MASS-TRANS-C", "MOLE-CONC", "MOLE-CYCL", "MOLE-DENSITY", "MOLE-ENTHALP", "MOLE-ENTROPY", "MOLE-FLOW",
			"MOLEFRAC", "MOLE-HEAT-CA", "MOLE-OPER", "MOLE-RXN-RAT", "MOL-RXN-RATW", "MOLE-VOLUME", "MOL-FLOW-LEN", "MOLES", "MOLE-WEIGHT", "MOM-INERTIA",
			"NUM-CON-RATE", "NUM-CONC", "PACK-FACTOR", "PDROP-PER-HT", "POP-DENSITY", "POWER", "POWER-VOLUME", "PDROP", "PRESSURE", "RHO-VSQRD",
			"SOLUPARAM", "SOLUTE-PERM", "SOLVENT-PERM", "SOUND-LEVEL", "SPEC-FLT-RES", "SPECIFICAREA", "SURFACE-TENS", "TEMP-VOLUME", "TEMPERATURE", "THERMAL-COND",
			"TIME", "UA", "UNIT-PRICE", "VELOCITY", "VFLOW-LENGTH", "VFLOW-RPM", "VISCOSITY", "VOLTAGE", "VOLUME", "VOLUME-CYCL",
			"VOL-ENTHALPY", "VOLUME-FLOW", "VOL-HEAT-CAP", "VOLUME-OPER", "VOLUME-PRICE", "VOLUME-USAGE", "ENERGY-VOL", "MASS-VOLUME", "WATER-RATE", "WORK"
		};

		public static readonly CxvPropertyDeclaration scrSearch_GridData_Property = CxvPropertyDeclaration.Register("scrSearch_GridData", typeof(MMSetup_Units_Search_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(scrSearch_GridData_ItemTemplate),
			IndexBasis = new CxvFixedCountIndexBasis
			{
				FixedCount = 120,
				Name = "y"
			}
		});

		public ICommand cmdHelp_Command
		{
			get
			{
				if (_cmdHelp_Command == null)
				{
					_cmdHelp_Command = new CxvDelegateCommand<object>(cmdHelp_CommandExecute);
				}
				return _cmdHelp_Command;
			}
		}

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object unitname => GetValue(unitname_Property);

		public object txtUnitName_unitlabel => GetValue(txtUnitName_unitlabel_Property);

		public object MMComboBox46_var1 => GetValue(MMComboBox46_var1_Property);

		public object scrSearch_GridData => GetValue(scrSearch_GridData_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (!base.IsInitialUpdate || !(scrSearch_GridData is CxvVectorPropertyData cxvVectorPropertyData))
			{
				return;
			}
			foreach (scrSearch_GridData_ItemTemplate item in cxvVectorPropertyData)
			{
				item.EnsureData();
			}
		}

		private void cmdHelp_CommandExecute(object parameter)
		{
		}

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMSetup.MMSetup_Units_Search")]
	public class MMSetup_Units_Search : MMTabPage, IComponentConnector
	{
		internal MMScrollArea scrSearch;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSetup_Units_Search()
		{
			base.ViewModelType = typeof(MMSetup_Units_Search_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_search.xaml", UriKind.Relative);
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
				scrSearch = (MMScrollArea)target;
				break;
			case 2:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Sizing_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox18_16_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_16_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.PACK-FACTOR",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox83_var1_Property = CxvPropertyDeclaration.Register("MMComboBox83_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.F-FACTOR",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox27_var1_Property = CxvPropertyDeclaration.Register("MMComboBox27_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.TEMP-VOLUME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox26_var1_Property = CxvPropertyDeclaration.Register("MMComboBox26_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.POWER-VOLUME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox25_var1_Property = CxvPropertyDeclaration.Register("MMComboBox25_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.AREA-USAGE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox24_11_var1_Property = CxvPropertyDeclaration.Register("MMComboBox24_11_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME-USAGE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox23_var1_Property = CxvPropertyDeclaration.Register("MMComboBox23_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOL-FLOW-LEN",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_12_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_12_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.AREA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox19_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-AREA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox20_var1_Property = CxvPropertyDeclaration.Register("MMComboBox20_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-LENG",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox21_var1_Property = CxvPropertyDeclaration.Register("MMComboBox21_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.LENGTH",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox22_var1_Property = CxvPropertyDeclaration.Register("MMComboBox22_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SPECIFICAREA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox28_var1_Property = CxvPropertyDeclaration.Register("MMComboBox28_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SHORT-LENGTH",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox29_var1_Property = CxvPropertyDeclaration.Register("MMComboBox29_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.WEIR-LOAD",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox30_var1_Property = CxvPropertyDeclaration.Register("MMComboBox30_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DOWNCOMER-LD",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox31_var1_Property = CxvPropertyDeclaration.Register("MMComboBox31_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASSFL-AREA",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox132_var1_Property = CxvPropertyDeclaration.Register("MMComboBox132_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VELOCIT-FLUX",
			Sorted = true
		});

		public object MMComboBox18_16_var1 => GetValue(MMComboBox18_16_var1_Property);

		public object MMComboBox83_var1 => GetValue(MMComboBox83_var1_Property);

		public object MMComboBox27_var1 => GetValue(MMComboBox27_var1_Property);

		public object MMComboBox26_var1 => GetValue(MMComboBox26_var1_Property);

		public object MMComboBox25_var1 => GetValue(MMComboBox25_var1_Property);

		public object MMComboBox24_11_var1 => GetValue(MMComboBox24_11_var1_Property);

		public object MMComboBox23_var1 => GetValue(MMComboBox23_var1_Property);

		public object MMComboBox18_12_var1 => GetValue(MMComboBox18_12_var1_Property);

		public object MMComboBox19_var1 => GetValue(MMComboBox19_var1_Property);

		public object MMComboBox20_var1 => GetValue(MMComboBox20_var1_Property);

		public object MMComboBox21_var1 => GetValue(MMComboBox21_var1_Property);

		public object MMComboBox22_var1 => GetValue(MMComboBox22_var1_Property);

		public object MMComboBox28_var1 => GetValue(MMComboBox28_var1_Property);

		public object MMComboBox29_var1 => GetValue(MMComboBox29_var1_Property);

		public object MMComboBox30_var1 => GetValue(MMComboBox30_var1_Property);

		public object MMComboBox31_var1 => GetValue(MMComboBox31_var1_Property);

		public object MMComboBox132_var1 => GetValue(MMComboBox132_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Units_Sizing")]
	public class MMSetup_Units_Sizing : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame16;

		internal MMLabel MMComboBox18_12_label;

		internal MMComboEdit MMComboBox18_12;

		internal MMLabel MMComboBox19_label;

		internal MMComboEdit MMComboBox19;

		internal MMLabel MMComboBox20_label;

		internal MMComboEdit MMComboBox20;

		internal MMLabel MMComboBox21_label;

		internal MMComboEdit MMComboBox21;

		internal MMLabel MMComboBox22_label;

		internal MMComboEdit MMComboBox22;

		internal MMLabel MMComboBox28_label;

		internal MMComboEdit MMComboBox28;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox23_label;

		internal MMComboEdit MMComboBox23;

		internal MMLabel MMComboBox24_11_label;

		internal MMComboEdit MMComboBox24_11;

		internal MMLabel MMComboBox25_label;

		internal MMComboEdit MMComboBox25;

		internal MMLabel MMComboBox26_label;

		internal MMComboEdit MMComboBox26;

		internal MMLabel MMComboBox27_label;

		internal MMComboEdit MMComboBox27;

		internal MMLabel MMComboBox13_2_label;

		internal MMComboEdit MMComboBox132;

		internal MMLabel MMComboBox29_label;

		internal MMComboEdit MMComboBox29;

		internal MMLabel MMComboBox30_label;

		internal MMComboEdit MMComboBox30;

		internal MMLabel MMComboBox31_label;

		internal MMComboEdit MMComboBox31;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox83_label;

		internal MMComboEdit MMComboBox83;

		internal MMLabel MMComboBox18_16_label;

		internal MMComboEdit MMComboBox18_16;

		private bool _contentLoaded;

		public MMSetup_Units_Sizing()
		{
			base.ViewModelType = typeof(MMSetup_Units_Sizing_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_sizing.xaml", UriKind.Relative);
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
				MMFrame16 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox18_12_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox18_12 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox19_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox19 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox20_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox20 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox21_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox21 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox22_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox22 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox28_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox28 = (MMComboEdit)target;
				break;
			case 14:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 15:
				MMComboBox23_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox23 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox24_11_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox24_11 = (MMComboEdit)target;
				break;
			case 19:
				MMComboBox25_label = (MMLabel)target;
				break;
			case 20:
				MMComboBox25 = (MMComboEdit)target;
				break;
			case 21:
				MMComboBox26_label = (MMLabel)target;
				break;
			case 22:
				MMComboBox26 = (MMComboEdit)target;
				break;
			case 23:
				MMComboBox27_label = (MMLabel)target;
				break;
			case 24:
				MMComboBox27 = (MMComboEdit)target;
				break;
			case 25:
				MMComboBox13_2_label = (MMLabel)target;
				break;
			case 26:
				MMComboBox132 = (MMComboEdit)target;
				break;
			case 27:
				MMComboBox29_label = (MMLabel)target;
				break;
			case 28:
				MMComboBox29 = (MMComboEdit)target;
				break;
			case 29:
				MMComboBox30_label = (MMLabel)target;
				break;
			case 30:
				MMComboBox30 = (MMComboEdit)target;
				break;
			case 31:
				MMComboBox31_label = (MMLabel)target;
				break;
			case 32:
				MMComboBox31 = (MMComboEdit)target;
				break;
			case 33:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 34:
				MMComboBox83_label = (MMLabel)target;
				break;
			case 35:
				MMComboBox83 = (MMComboEdit)target;
				break;
			case 36:
				MMComboBox18_16_label = (MMLabel)target;
				break;
			case 37:
				MMComboBox18_16 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Temper_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdSearch_Command;

		public static readonly CxvPropertyDeclaration MMComboBox25_var1_Property = CxvPropertyDeclaration.Register("MMComboBox25_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-TEMP",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox26_var1_Property = CxvPropertyDeclaration.Register("MMComboBox26_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DELTA-T",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox27_var1_Property = CxvPropertyDeclaration.Register("MMComboBox27_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.TEMPERATURE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox22_var1_Property = CxvPropertyDeclaration.Register("MMComboBox22_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-FLUX",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox23_var1_Property = CxvPropertyDeclaration.Register("MMComboBox23_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FLUX",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_2_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FLOW",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox19_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME-FLOW",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox20_var1_Property = CxvPropertyDeclaration.Register("MMComboBox20_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-FLOW",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox21_var1_Property = CxvPropertyDeclaration.Register("MMComboBox21_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-FLOW",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox31_var1_Property = CxvPropertyDeclaration.Register("MMComboBox31_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-PRES",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox32_var1_Property = CxvPropertyDeclaration.Register("MMComboBox32_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.HEAD",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox30_var1_Property = CxvPropertyDeclaration.Register("MMComboBox30_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.PDROP-PER-HT",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox29_var1_Property = CxvPropertyDeclaration.Register("MMComboBox29_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.PDROP",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox28_var1_Property = CxvPropertyDeclaration.Register("MMComboBox28_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.PRESSURE",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox33_var1_Property = CxvPropertyDeclaration.Register("MMComboBox33_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME-GFLOW",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.BASESET",
			AllowNew = false
		});

		public ICommand cmdSearch_Command
		{
			get
			{
				if (_cmdSearch_Command == null)
				{
					_cmdSearch_Command = new CxvDelegateCommand<object>(cmdSearch_CommandExecute);
				}
				return _cmdSearch_Command;
			}
		}

		public object MMComboBox25_var1 => GetValue(MMComboBox25_var1_Property);

		public object MMComboBox26_var1 => GetValue(MMComboBox26_var1_Property);

		public object MMComboBox27_var1 => GetValue(MMComboBox27_var1_Property);

		public object MMComboBox22_var1 => GetValue(MMComboBox22_var1_Property);

		public object MMComboBox23_var1 => GetValue(MMComboBox23_var1_Property);

		public object MMComboBox18_2_var1 => GetValue(MMComboBox18_2_var1_Property);

		public object MMComboBox19_var1 => GetValue(MMComboBox19_var1_Property);

		public object MMComboBox20_var1 => GetValue(MMComboBox20_var1_Property);

		public object MMComboBox21_var1 => GetValue(MMComboBox21_var1_Property);

		public object MMComboBox31_var1 => GetValue(MMComboBox31_var1_Property);

		public object MMComboBox32_var1 => GetValue(MMComboBox32_var1_Property);

		public object MMComboBox30_var1 => GetValue(MMComboBox30_var1_Property);

		public object MMComboBox29_var1 => GetValue(MMComboBox29_var1_Property);

		public object MMComboBox28_var1 => GetValue(MMComboBox28_var1_Property);

		public object MMComboBox33_var1 => GetValue(MMComboBox33_var1_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		private void cmdSearch_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMSetup.MMSetup_Units_Search",
				LegacyFlags = 0,
				HelpId = 291,
				HelpFile = "setup.hlp",
				ShortName = WpfFormsResources.MMSetup_Units_Temper_Display1,
				ShowPrompts = true
			});
		}
	}
	[ProgId("MMSetup.MMSetup_Units_Temper")]
	public class MMSetup_Units_Temper : MMTabPage, IComponentConnector
	{
		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMCmdButton cmdSearch;

		internal MMGroupBox MMFrame6;

		internal MMLabel MMComboBox21_label;

		internal MMComboEdit MMComboBox21;

		internal MMLabel MMComboBox20_label;

		internal MMComboEdit MMComboBox20;

		internal MMLabel MMComboBox19_label;

		internal MMComboEdit MMComboBox19;

		internal MMLabel MMComboBox18_2_label;

		internal MMComboEdit MMComboBox18_2;

		internal MMLabel MMComboBox23_label;

		internal MMComboEdit MMComboBox23;

		internal MMLabel MMComboBox22_label;

		internal MMComboEdit MMComboBox22;

		internal MMLabel MMComboBox33_label;

		internal MMComboEdit MMComboBox33;

		internal MMGroupBox MMFrame7;

		internal MMLabel MMComboBox27_label;

		internal MMComboEdit MMComboBox27;

		internal MMLabel MMComboBox26_label;

		internal MMComboEdit MMComboBox26;

		internal MMLabel MMComboBox25_label;

		internal MMComboEdit MMComboBox25;

		internal MMGroupBox MMFrame8;

		internal MMLabel MMComboBox28_label;

		internal MMComboEdit MMComboBox28;

		internal MMLabel MMComboBox29_label;

		internal MMComboEdit MMComboBox29;

		internal MMLabel MMComboBox30_label;

		internal MMComboEdit MMComboBox30;

		internal MMLabel MMComboBox32_label;

		internal MMComboEdit MMComboBox32;

		internal MMLabel MMComboBox31_label;

		internal MMComboEdit MMComboBox31;

		private bool _contentLoaded;

		public MMSetup_Units_Temper()
		{
			base.ViewModelType = typeof(MMSetup_Units_Temper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_temper.xaml", UriKind.Relative);
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
				MMComboBox1_label = (MMLabel)target;
				break;
			case 2:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 3:
				cmdSearch = (MMCmdButton)target;
				break;
			case 4:
				MMFrame6 = (MMGroupBox)target;
				break;
			case 5:
				MMComboBox21_label = (MMLabel)target;
				break;
			case 6:
				MMComboBox21 = (MMComboEdit)target;
				break;
			case 7:
				MMComboBox20_label = (MMLabel)target;
				break;
			case 8:
				MMComboBox20 = (MMComboEdit)target;
				break;
			case 9:
				MMComboBox19_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox19 = (MMComboEdit)target;
				break;
			case 11:
				MMComboBox18_2_label = (MMLabel)target;
				break;
			case 12:
				MMComboBox18_2 = (MMComboEdit)target;
				break;
			case 13:
				MMComboBox23_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox23 = (MMComboEdit)target;
				break;
			case 15:
				MMComboBox22_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox22 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox33_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox33 = (MMComboEdit)target;
				break;
			case 19:
				MMFrame7 = (MMGroupBox)target;
				break;
			case 20:
				MMComboBox27_label = (MMLabel)target;
				break;
			case 21:
				MMComboBox27 = (MMComboEdit)target;
				break;
			case 22:
				MMComboBox26_label = (MMLabel)target;
				break;
			case 23:
				MMComboBox26 = (MMComboEdit)target;
				break;
			case 24:
				MMComboBox25_label = (MMLabel)target;
				break;
			case 25:
				MMComboBox25 = (MMComboEdit)target;
				break;
			case 26:
				MMFrame8 = (MMGroupBox)target;
				break;
			case 27:
				MMComboBox28_label = (MMLabel)target;
				break;
			case 28:
				MMComboBox28 = (MMComboEdit)target;
				break;
			case 29:
				MMComboBox29_label = (MMLabel)target;
				break;
			case 30:
				MMComboBox29 = (MMComboEdit)target;
				break;
			case 31:
				MMComboBox30_label = (MMLabel)target;
				break;
			case 32:
				MMComboBox30 = (MMComboEdit)target;
				break;
			case 33:
				MMComboBox32_label = (MMLabel)target;
				break;
			case 34:
				MMComboBox32 = (MMComboEdit)target;
				break;
			case 35:
				MMComboBox31_label = (MMLabel)target;
				break;
			case 36:
				MMComboBox31 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Units_Volume_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox53_var1_Property = CxvPropertyDeclaration.Register("MMComboBox53_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SOLUPARAM",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox54_var1_Property = CxvPropertyDeclaration.Register("MMComboBox54_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DIPOLEMOMENT",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox58_var1_Property = CxvPropertyDeclaration.Register("MMComboBox58_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DIFFUSIVITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox57_var1_Property = CxvPropertyDeclaration.Register("MMComboBox57_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-TRANS-C",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox56_var1_Property = CxvPropertyDeclaration.Register("MMComboBox56_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SURFACE-TENS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_8_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_8_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.THERMAL-COND",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_7_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_7_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VISCOSITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox55_var1_Property = CxvPropertyDeclaration.Register("MMComboBox55_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VELOCITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox16_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_1_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-VOLUME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox17_var1_Property = CxvPropertyDeclaration.Register("MMComboBox17_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox16_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_0_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-VOLUME",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox15_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VFLOW-LENGTH",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_0_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DENSITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-DENSITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-DENSITY",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox7_var1_Property = CxvPropertyDeclaration.Register("MMComboBox7_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.RHO-VSQRD",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration CurrentDensity_var1_Property = CxvPropertyDeclaration.Register("CurrentDensity_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.CURRENT-DENS",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox59_var1_Property = CxvPropertyDeclaration.Register("MMComboBox59_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.INVERSE-VEL",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration MMComboBox60_var1_Property = CxvPropertyDeclaration.Register("MMComboBox60_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ACCELERATION",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration ElectConduct_var1_Property = CxvPropertyDeclaration.Register("ElectConduct_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SIEMENS-M",
			Sorted = true
		});

		public object MMComboBox53_var1 => GetValue(MMComboBox53_var1_Property);

		public object MMComboBox54_var1 => GetValue(MMComboBox54_var1_Property);

		public object MMComboBox58_var1 => GetValue(MMComboBox58_var1_Property);

		public object MMComboBox57_var1 => GetValue(MMComboBox57_var1_Property);

		public object MMComboBox56_var1 => GetValue(MMComboBox56_var1_Property);

		public object MMComboBox18_8_var1 => GetValue(MMComboBox18_8_var1_Property);

		public object MMComboBox18_7_var1 => GetValue(MMComboBox18_7_var1_Property);

		public object MMComboBox55_var1 => GetValue(MMComboBox55_var1_Property);

		public object MMComboBox16_1_var1 => GetValue(MMComboBox16_1_var1_Property);

		public object MMComboBox17_var1 => GetValue(MMComboBox17_var1_Property);

		public object MMComboBox16_0_var1 => GetValue(MMComboBox16_0_var1_Property);

		public object MMComboBox15_var1 => GetValue(MMComboBox15_var1_Property);

		public object MMComboBox18_0_var1 => GetValue(MMComboBox18_0_var1_Property);

		public object MMComboBox5_var1 => GetValue(MMComboBox5_var1_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMComboBox7_var1 => GetValue(MMComboBox7_var1_Property);

		public object CurrentDensity_var1 => GetValue(CurrentDensity_var1_Property);

		public object MMComboBox59_var1 => GetValue(MMComboBox59_var1_Property);

		public object MMComboBox60_var1 => GetValue(MMComboBox60_var1_Property);

		public object ElectConduct_var1 => GetValue(ElectConduct_var1_Property);
	}
	[ProgId("MMSetup.MMSetup_Units_Volume")]
	public class MMSetup_Units_Volume : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame5;

		internal MMLabel MMComboBox17_label;

		internal MMComboEdit MMComboBox17;

		internal MMLabel MMComboBox16_0_label;

		internal MMComboEdit MMComboBox16_0;

		internal MMLabel MMComboBox16_1_label;

		internal MMComboEdit MMComboBox16_1;

		internal MMLabel MMComboBox15_label;

		internal MMComboEdit MMComboBox15;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox18_0_label;

		internal MMComboEdit MMComboBox18_0;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMComboBox7_label;

		internal MMComboEdit MMComboBox7;

		internal MMLabel CurrentDensity_label;

		internal MMComboEdit CurrentDensity;

		internal MMGroupBox MMFrame14;

		internal MMLabel MMComboBox58_label;

		internal MMComboEdit MMComboBox58;

		internal MMLabel MMComboBox57_label;

		internal MMComboEdit MMComboBox57;

		internal MMLabel MMComboBox56_label;

		internal MMComboEdit MMComboBox56;

		internal MMLabel MMComboBox18_8_label;

		internal MMComboEdit MMComboBox18_8;

		internal MMLabel MMComboBox18_7_label;

		internal MMComboEdit MMComboBox18_7;

		internal MMLabel MMComboBox55_label;

		internal MMComboEdit MMComboBox55;

		internal MMLabel MMComboBox59_label;

		internal MMComboEdit MMComboBox59;

		internal MMLabel MMComboBox60_label;

		internal MMComboEdit MMComboBox60;

		internal MMLabel ElectConduct_label;

		internal MMComboEdit ElectConduct;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox54_label;

		internal MMComboEdit MMComboBox54;

		internal MMLabel MMComboBox53_label;

		internal MMComboEdit MMComboBox53;

		private bool _contentLoaded;

		public MMSetup_Units_Volume()
		{
			base.ViewModelType = typeof(MMSetup_Units_Volume_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_units_volume.xaml", UriKind.Relative);
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
				MMFrame5 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox17_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox17 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox16_0_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox16_0 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox16_1_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox16_1 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox15_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox15 = (MMComboEdit)target;
				break;
			case 10:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 11:
				MMComboBox18_0_label = (MMLabel)target;
				break;
			case 12:
				MMComboBox18_0 = (MMComboEdit)target;
				break;
			case 13:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 15:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox7_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox7 = (MMComboEdit)target;
				break;
			case 19:
				CurrentDensity_label = (MMLabel)target;
				break;
			case 20:
				CurrentDensity = (MMComboEdit)target;
				break;
			case 21:
				MMFrame14 = (MMGroupBox)target;
				break;
			case 22:
				MMComboBox58_label = (MMLabel)target;
				break;
			case 23:
				MMComboBox58 = (MMComboEdit)target;
				break;
			case 24:
				MMComboBox57_label = (MMLabel)target;
				break;
			case 25:
				MMComboBox57 = (MMComboEdit)target;
				break;
			case 26:
				MMComboBox56_label = (MMLabel)target;
				break;
			case 27:
				MMComboBox56 = (MMComboEdit)target;
				break;
			case 28:
				MMComboBox18_8_label = (MMLabel)target;
				break;
			case 29:
				MMComboBox18_8 = (MMComboEdit)target;
				break;
			case 30:
				MMComboBox18_7_label = (MMLabel)target;
				break;
			case 31:
				MMComboBox18_7 = (MMComboEdit)target;
				break;
			case 32:
				MMComboBox55_label = (MMLabel)target;
				break;
			case 33:
				MMComboBox55 = (MMComboEdit)target;
				break;
			case 34:
				MMComboBox59_label = (MMLabel)target;
				break;
			case 35:
				MMComboBox59 = (MMComboEdit)target;
				break;
			case 36:
				MMComboBox60_label = (MMLabel)target;
				break;
			case 37:
				MMComboBox60 = (MMComboEdit)target;
				break;
			case 38:
				ElectConduct_label = (MMLabel)target;
				break;
			case 39:
				ElectConduct = (MMComboEdit)target;
				break;
			case 40:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 41:
				MMComboBox54_label = (MMLabel)target;
				break;
			case 42:
				MMComboBox54 = (MMComboEdit)target;
				break;
			case 43:
				MMComboBox53_label = (MMLabel)target;
				break;
			case 44:
				MMComboBox53 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_VarGroup_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec1_Property = CxvPropertyDeclaration.Register("spec1", typeof(MMSetup_VarGroup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC1"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_VarGroup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec1" }
		});

		public object spec1 => GetValue(spec1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMSetup.MMSetup_VarGroup")]
	public class MMSetup_VarGroup : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSetup_VarGroup()
		{
			base.ViewModelType = typeof(MMSetup_VarGroup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_vargroup.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_VarGroup_Define_ViewModel : MMTabPageViewModel
	{
		public class grdDefine_GridData_ItemTemplate : MMViewModel
		{
			private readonly CxvPropertyWatch watch = new CxvPropertyWatch();

			public static readonly CxvPropertyDeclaration txtVarName_var1_Property = CxvPropertyDeclaration.Register("txtVarName_var1", typeof(grdDefine_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FVN_VARTYPE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase,
				Sorted = true
			});

			public static readonly CxvPropertyDeclaration txtDescription_Property = CxvPropertyDeclaration.Register("txtDescription", typeof(grdDefine_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FVN_DESCRIPT.@y"
			});

			public static readonly CxvPropertyDeclaration format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(grdDefine_GridData_ItemTemplate), new CxvLineFormatProperty
			{
				DataPath = "@main.Input.FVN_LINESTYL.@y",
				DefaultLineWeight = 3.0
			});

			public static readonly CxvPropertyDeclaration Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdDefine_GridData_ItemTemplate), new CxvBooleanProperty
			{
				DataPath = "@main.Input.FVN_ACTIVE.@y"
			});

			public object txtVarDefn_VarDefn => new CxvManualVariableData
			{
				IsReadOnly = true,
				Value = VarDefn
			};

			public string VarDefn
			{
				get
				{
					string result = "";
					string text = "";
					string text2 = CxsConverter.ValueToString(ResolveParameter("y"));
					watch.PropertyDependencyChanged -= watch_PropertyDependencyChanged;
					watch.Clear();
					string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + text2, "value", null, watch));
					if (text3 == null)
					{
						return result;
					}
					foreach (VarType varType in VarTypes)
					{
						if (text3 == varType.UCase)
						{
							text = varType.MCase;
							break;
						}
					}
					foreach (PromptType prompt in Prompts)
					{
						string text4 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + prompt.Variable + "." + text2, "value", null, watch));
						string text5 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + prompt.Variable + "." + text2, "can_enter", null, watch));
						if (text5 == null)
						{
							text5 = "0";
						}
						if (!string.IsNullOrEmpty(text4) && (!prompt.HideWhenLocked || text5 == "1"))
						{
							if (prompt.ConvertToMixedCase)
							{
								text4 = StrConvMixCase(text4);
							}
							text = text + " " + prompt.Label + text4;
						}
					}
					result = text;
					if (!watch.IsEmpty)
					{
						watch.PropertyDependencyChanged += watch_PropertyDependencyChanged;
					}
					return result;
				}
			}

			public object txtVarName_var1 => GetValue(txtVarName_var1_Property);

			public object txtDescription => GetValue(txtDescription_Property);

			public object format_var => GetValue(format_var_Property);

			public object Active_var => GetValue(Active_var_Property);

			private void watch_PropertyDependencyChanged(object sender, EventArgs e)
			{
				OnPropertyChanged("txtVarDefn_VarDefn");
			}

			public string GetFormat()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("format_var.Value", null));
			}

			public void RefreshVarDefn()
			{
				OnPropertyChanged("txtVarDefn_VarDefn");
			}
		}

		public struct PromptType
		{
			public string Text;

			public string Label;

			public string Variable;

			public bool HideWhenLocked;

			public bool ConvertToMixedCase;
		}

		public struct VarType
		{
			public string UCase;

			public string MCase;

			public int[] PromptIndex;
		}

		public static readonly CxvPropertyDeclaration Disable_Plotvg_Property = CxvPropertyDeclaration.Register("Disable_Plotvg", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "p_IsSystemGenerate",
				Operator = CxvLogicalOperator.NotEqual,
				Value = "1"
			}
		});

		private ICommand _cmdNew_Command;

		private RelayActionCommand<object> _cmdDelete_Command;

		private RelayActionCommand<object> _cmdCopy_Command;

		private RelayActionCommand<object> _cmdPaste_Command;

		private bool _isPastingObjectRows;

		private RelayActionCommand<object> _cmdReorder_0_Command;

		private RelayActionCommand<object> _cmdReorder_1_Command;

		private RelayActionCommand<object> _cmdViewvariable_Command;

		public static readonly CxvPropertyDeclaration grdDefine_GridData_Property = CxvPropertyDeclaration.Register("grdDefine_GridData", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdDefine_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FVN_VARTYPE",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			}
		});

		public static readonly CxvPropertyDeclaration expandar_define_Property = CxvPropertyDeclaration.Register("expandar_define", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvExpanderProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				Parameter = "p_IsSystemGenerate",
				Operator = CxvLogicalOperator.NotEqual,
				Value = "1"
			}
		});

		private bool _ExpandDefine;

		private ICommand _cmdFind_Command;

		public static readonly CxvPropertyDeclaration mnuVarname_ListVar_Property = CxvPropertyDeclaration.Register("mnuVarname_ListVar", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FVN_VARIABLE",
			SelectedItemBinding = "mnuVarname_StoVar2.Value",
			CreateNewInputMask = 3,
			CompletePaths = { "@main.CC Nodes.SPEC" }
		});

		public static readonly CxvPropertyDeclaration mnuVarname_StoVar2_Property = CxvPropertyDeclaration.Register("mnuVarname_StoVar2", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvParameterProperty
		{
			Parameter = "xVarName"
		});

		public static readonly CxvPropertyDeclaration optCategory_MultiMap_Property = CxvPropertyDeclaration.Register("optCategory_MultiMap", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "optCategory_var1",
					DataPath = "@main.Input.OPT_CATEG.@xInt"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "All",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_All",
					Value = "ALL",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "ALL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Blocks",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Blocks",
					Value = "BLOCK",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "BLOCK"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Streams",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "STREAM",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "STREAM"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Model Utility",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Model_Utility",
					Value = "MODUT",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "MODUT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Property Parameters",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Physical_Property_Parameters",
					Value = "PROP",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "PROP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Reactions",
					DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Reactions",
					Value = "REACT",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "REACT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Sensors",
					DisplayResourceKey = "MMSensitivi_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Sensor",
					Value = "SENSOR",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optCategory_var1",
							Value = "SENSOR"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboVarTypevw_var1_Property = CxvPropertyDeclaration.Register("cboVarTypevw_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.FVN_VARTYPE.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_0_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_0_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow0.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_0_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_0_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvPropertySelector
		{
			Choices = 
			{
				new CxvPropertyChoice
				{
					Conditions = 
					{
						new CxvLogicalTest
						{
							Parameter = "RowsvwD_0_IsMixedCase",
							Value = "1"
						}
					},
					Operator = CxvLogicalOperator.And,
					Property = new CxvVariableProperty
					{
						DataPath = "@main.Input.@vwrow0.@xInt",
						ExposeAs = CxvVariableTypeCode.String,
						DisplayedCase = CxsDisplayedCase.Lowercase,
						Sorted = true
					}
				},
				new CxvPropertyChoice
				{
					Conditions = 
					{
						new CxvLogicalTest
						{
							Parameter = "RowsvwD_0_IsMixedCase",
							Value = "0"
						}
					},
					Operator = CxvLogicalOperator.And,
					Property = new CxvVariableProperty
					{
						DataPath = "@main.Input.@vwrow0.@xInt",
						ExposeAs = CxvVariableTypeCode.String,
						Sorted = true
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_1_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow1.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_1_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvPropertySelector
		{
			Choices = 
			{
				new CxvPropertyChoice
				{
					Conditions = 
					{
						new CxvLogicalTest
						{
							Parameter = "RowsvwD_1_IsMixedCase",
							Value = "1"
						}
					},
					Operator = CxvLogicalOperator.And,
					Property = new CxvVariableProperty
					{
						DataPath = "@main.Input.@vwrow1.@xInt",
						ExposeAs = CxvVariableTypeCode.String,
						DisplayedCase = CxsDisplayedCase.Lowercase,
						Sorted = true
					}
				},
				new CxvPropertyChoice
				{
					Conditions = 
					{
						new CxvLogicalTest
						{
							Parameter = "RowsvwD_1_IsMixedCase",
							Value = "0"
						}
					},
					Operator = CxvLogicalOperator.And,
					Property = new CxvVariableProperty
					{
						DataPath = "@main.Input.@vwrow1.@xInt",
						ExposeAs = CxvVariableTypeCode.String,
						Sorted = true
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_2_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_2_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow2.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_2_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_2_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow2.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_3_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_3_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow3.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_3_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_3_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow3.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_4_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_4_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow4.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_4_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_4_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow4.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_5_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_5_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow5.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_5_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_5_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow5.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_6_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_6_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow6.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_6_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_6_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow6.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_7_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_7_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow7.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_7_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_7_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow7.@xInt",
			Sorted = true
		});

		public static readonly CxvPropertyDeclaration txtBlockVar_var1_Property = CxvPropertyDeclaration.Register("txtBlockVar_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow1.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase,
			IsVisibleCondition = new CxvLogicalTest
			{
				Parameter = "p_BlockVarVisible",
				Value = "1"
			}
		});

		public static readonly CxvPropertyDeclaration txtHybridVar_var1_Property = CxvPropertyDeclaration.Register("txtHybridVar_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow1.@xInt",
			DisplayedCase = CxsDisplayedCase.Uppercase,
			IsVisibleCondition = new CxvLogicalTest
			{
				Parameter = "p_HybridVarVisible",
				Value = "1"
			}
		});

		private ObservableCollection<string> _cboVarTypevw_var2;

		private string _cboVarTypevw_SelectedValue;

		private string[] _label_captions = new string[8];

		private Visibility[] _label_Visibilities = new Visibility[8];

		private Visibility[] _combo_Visibilities = new Visibility[8];

		private bool[] _combo_AllowClear = new bool[8] { true, true, true, true, true, true, true, true };

		private Visibility[] _textEdit_Visibilities = new Visibility[8];

		private Visibility[] _cmdFind_Visibilities = new Visibility[8];

		private int[] _comboWidth = new int[8] { 182, 182, 182, 182, 182, 182, 182, 182 };

		public static readonly CxvPropertyDeclaration format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvLineFormatProperty
		{
			DataPath = "@main.Input.FVN_LINESTYL.@xInt"
		});

		private int _colorIndex;

		public const double DEFAULT_LINE_WEIGHT = 3.0;

		private double _lineWeight = 3.0;

		private int _lineStyle;

		private Color _lineColor = Colors.Black;

		private static Color[] _definedColors = new Color[16]
		{
			Colors.Black,
			Colors.Navy,
			Colors.Green,
			Colors.Teal,
			Colors.Brown,
			Colors.Purple,
			Colors.DarkOliveGreen,
			Colors.Gray,
			Colors.DarkGray,
			Colors.Blue,
			Colors.LightGreen,
			Colors.SkyBlue,
			Colors.Red,
			Colors.Fuchsia,
			Colors.Yellow,
			Colors.LightGray
		};

		private CxvPropertyWatch _formatWatch;

		private CxvPropertyWatch _watcher = new CxvPropertyWatch();

		private const int HAP_DISABLED = 4096;

		private const int HAP_ENABLED = 8192;

		private bool _isBlockActive = true;

		private readonly CxvPropertyWatch statusWatch = new CxvPropertyWatch();

		private ObservableCollection<int> _selectedRowIndexes;

		public static List<VarType> VarTypes;

		public static List<PromptType> Prompts;

		private ICommand _cmdFindVariables_Command;

		public object Disable_Plotvg => GetValue(Disable_Plotvg_Property);

		public ICommand cmdNew_Command
		{
			get
			{
				if (_cmdNew_Command == null)
				{
					_cmdNew_Command = new CxvDelegateCommand<object>(cmdNew_CommandExecute);
				}
				return _cmdNew_Command;
			}
		}

		public RelayActionCommand<object> cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new RelayActionCommand<object>(cmdDelete_CommandExecute, (object parameter) => SelectedRowIndexes != null && SelectedRowIndexes.Count > 0);
				}
				return _cmdDelete_Command;
			}
		}

		public bool OnlyProxyRowSelected
		{
			get
			{
				if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1)
				{
					int? num = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("grdDefine_GridData.Count"));
					if (num.HasValue && SelectedRowIndexes[0] == num - 1)
					{
						return true;
					}
				}
				return false;
			}
		}

		public RelayActionCommand<object> cmdCopy_Command
		{
			get
			{
				if (_cmdCopy_Command == null)
				{
					_cmdCopy_Command = new RelayActionCommand<object>(cmdCopy_CommandExecute, (object parameter) => SelectedRowIndexes != null && SelectedRowIndexes.Count > 0);
				}
				return _cmdCopy_Command;
			}
		}

		public RelayActionCommand<object> cmdPaste_Command
		{
			get
			{
				if (_cmdPaste_Command == null)
				{
					_cmdPaste_Command = new RelayActionCommand<object>(cmdPaste_CommandExecute, cmdPaste_CommandCanExecute);
				}
				return _cmdPaste_Command;
			}
		}

		public RelayActionCommand<object> cmdReorder_0_Command
		{
			get
			{
				if (_cmdReorder_0_Command == null)
				{
					_cmdReorder_0_Command = new RelayActionCommand<object>(cmdReorder_0_CommandExecute, cmdUp_CommandCanExecute);
				}
				return _cmdReorder_0_Command;
			}
		}

		public RelayActionCommand<object> cmdReorder_1_Command
		{
			get
			{
				if (_cmdReorder_1_Command == null)
				{
					_cmdReorder_1_Command = new RelayActionCommand<object>(cmdReorder_1_CommandExecute, cmdDown_CommandCanExecute);
				}
				return _cmdReorder_1_Command;
			}
		}

		public RelayActionCommand<object> cmdViewvariable_Command
		{
			get
			{
				if (_cmdViewvariable_Command == null)
				{
					_cmdViewvariable_Command = new RelayActionCommand<object>(cmdViewvariable_CommandExecute, cmdViewvariable_CommandCanExecute);
				}
				return _cmdViewvariable_Command;
			}
		}

		public object grdDefine_GridData => GetValue(grdDefine_GridData_Property);

		public object expandar_define => GetValue(expandar_define_Property);

		public bool ExpandDefine
		{
			get
			{
				return _ExpandDefine;
			}
			set
			{
				_ExpandDefine = value;
				OnPropertyChanged("ExpandDefine");
			}
		}

		public ICommand cmdFind_Command
		{
			get
			{
				if (_cmdFind_Command == null)
				{
					_cmdFind_Command = new CxvDelegateCommand<object>(cmdFind_CommandExecute);
				}
				return _cmdFind_Command;
			}
		}

		public object mnuVarname_ListVar => GetValue(mnuVarname_ListVar_Property);

		public object mnuVarname_StoVar2 => GetValue(mnuVarname_StoVar2_Property);

		public object optCategory_MultiMap => GetValue(optCategory_MultiMap_Property);

		public object cboVarTypevw_var1 => GetValue(cboVarTypevw_var1_Property);

		public object txtRowsvw_0_var1 => GetValue(txtRowsvw_0_var1_Property);

		public object cboRowsvw_0_var1 => GetValue(cboRowsvw_0_var1_Property);

		public object txtRowsvw_1_var1 => GetValue(txtRowsvw_1_var1_Property);

		public object cboRowsvw_1_var1 => GetValue(cboRowsvw_1_var1_Property);

		public object txtRowsvw_2_var1 => GetValue(txtRowsvw_2_var1_Property);

		public object cboRowsvw_2_var1 => GetValue(cboRowsvw_2_var1_Property);

		public object txtRowsvw_3_var1 => GetValue(txtRowsvw_3_var1_Property);

		public object cboRowsvw_3_var1 => GetValue(cboRowsvw_3_var1_Property);

		public object txtRowsvw_4_var1 => GetValue(txtRowsvw_4_var1_Property);

		public object cboRowsvw_4_var1 => GetValue(cboRowsvw_4_var1_Property);

		public object txtRowsvw_5_var1 => GetValue(txtRowsvw_5_var1_Property);

		public object cboRowsvw_5_var1 => GetValue(cboRowsvw_5_var1_Property);

		public object txtRowsvw_6_var1 => GetValue(txtRowsvw_6_var1_Property);

		public object cboRowsvw_6_var1 => GetValue(cboRowsvw_6_var1_Property);

		public object txtRowsvw_7_var1 => GetValue(txtRowsvw_7_var1_Property);

		public object cboRowsvw_7_var1 => GetValue(cboRowsvw_7_var1_Property);

		public object txtBlockVar_var1 => GetValue(txtBlockVar_var1_Property);

		public object txtHybridVar_var1 => GetValue(txtHybridVar_var1_Property);

		public ObservableCollection<string> cboVarTypevw_var2
		{
			get
			{
				return _cboVarTypevw_var2;
			}
			set
			{
				_cboVarTypevw_var2 = value;
				if (_cboVarTypevw_var2 != null)
				{
					_cboVarTypevw_var2.CollectionChanged -= _cboVarTypevw_var2_CollectionChanged;
					_cboVarTypevw_var2.CollectionChanged += _cboVarTypevw_var2_CollectionChanged;
				}
				OnPropertyChanged("cboVarTypevw_var2");
			}
		}

		public string cboVarTypevw_SelectedValue
		{
			get
			{
				string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE.@xInt", "value"));
				if (string.IsNullOrEmpty(value))
				{
					if (base.ResolvedCxsProvider != null)
					{
						base.ResolvedCxsProvider.UpdateDataCache();
					}
					value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE.@xInt", "value"));
				}
				_cboVarTypevw_SelectedValue = value;
				if (_cboVarTypevw_SelectedValue != null)
				{
					foreach (VarType item in VAVarTypeInit(CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "option_list"))))
					{
						if (item.UCase == _cboVarTypevw_SelectedValue)
						{
							_cboVarTypevw_SelectedValue = item.MCase;
							break;
						}
					}
				}
				return _cboVarTypevw_SelectedValue;
			}
			set
			{
				string text = _cboVarTypevw_SelectedValue;
				_cboVarTypevw_SelectedValue = value;
				OnPropertyChanged("cboVarTypevw_SelectedValue");
				if (!(_cboVarTypevw_SelectedValue != text))
				{
					return;
				}
				foreach (VarType item in VAVarTypeInit(CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "option_list"))))
				{
					if (item.MCase == _cboVarTypevw_SelectedValue)
					{
						_cboVarTypevw_SelectedValue = item.UCase;
						break;
					}
				}
				ExpandDataPathAndSet("@main.Input.FVN_VARTYPE.@xInt", "value", _cboVarTypevw_SelectedValue);
				Display2();
			}
		}

		public string cboRowsvw_0_value
		{
			get
			{
				string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.@vwrow0.@xInt", "value"));
				if (text == null)
				{
					return "";
				}
				return text;
			}
			set
			{
				ExpandDataPathAndSet("@main.Input.@vwrow0.@xInt", "value", value);
				Display2();
			}
		}

		public string[] Label_Captions => _label_captions;

		public Visibility[] Label_Visibilities => _label_Visibilities;

		public Visibility[] Combo_Visibilities => _combo_Visibilities;

		public bool[] Combo_AllowClear => _combo_AllowClear;

		public Visibility[] TextEdit_Visibilities => _textEdit_Visibilities;

		public Visibility[] cmdFind_Visibilities => _cmdFind_Visibilities;

		public int[] ComboWidth => _comboWidth;

		public object format_var => GetValue(format_var_Property);

		public int ColorIndex
		{
			get
			{
				return _colorIndex;
			}
			set
			{
				if (_colorIndex != value)
				{
					_colorIndex = value;
					OnPropertyChanged("ColorIndex");
					SaveFormat();
				}
			}
		}

		public double LineWeight
		{
			get
			{
				return _lineWeight;
			}
			set
			{
				if (_lineWeight != value)
				{
					_lineWeight = value;
					OnPropertyChanged("LineWeight");
					SaveFormat();
				}
			}
		}

		public int LineStyle
		{
			get
			{
				return _lineStyle;
			}
			set
			{
				if (_lineStyle != value)
				{
					_lineStyle = value;
					OnPropertyChanged("LineStyle");
					SaveFormat();
				}
			}
		}

		public Color LineColor
		{
			get
			{
				return _lineColor;
			}
			set
			{
				if (_lineColor != value)
				{
					_lineColor = value;
					OnPropertyChanged("LineColor");
					SaveFormat();
				}
			}
		}

		public bool IsBlockActive
		{
			get
			{
				statusWatch.PropertyDependencyChanged -= statusWatch_PropertyDependencyChanged;
				statusWatch.Clear();
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main", "status_code", null, statusWatch));
				if (num.HasValue && (num.Value & 0x2000) != 0)
				{
					_isBlockActive = true;
				}
				else if (num.HasValue && (num.Value & 0x1000) != 0)
				{
					_isBlockActive = false;
				}
				if (!statusWatch.IsEmpty)
				{
					statusWatch.PropertyDependencyChanged += statusWatch_PropertyDependencyChanged;
				}
				return _isBlockActive;
			}
			set
			{
				ActivateOrDeactivateBlockNode(ExpandDataPath("@main"), value);
				_isBlockActive = value;
				OnPropertyChanged("IsBlockActive");
			}
		}

		public ObservableCollection<int> SelectedRowIndexes
		{
			get
			{
				return _selectedRowIndexes;
			}
			set
			{
				if (value != _selectedRowIndexes)
				{
					if (_selectedRowIndexes != null)
					{
						_selectedRowIndexes.CollectionChanged -= _selectedRowIndexes_CollectionChanged;
					}
					_selectedRowIndexes = value;
					if (_selectedRowIndexes != null)
					{
						_selectedRowIndexes.CollectionChanged += _selectedRowIndexes_CollectionChanged;
					}
					OnPropertyChanged("SelectedRowIndexes");
					UpdateEditDetail();
				}
			}
		}

		public ICommand cmdFindVariables_Command
		{
			get
			{
				if (_cmdFindVariables_Command == null)
				{
					_cmdFindVariables_Command = new CxvDelegateCommand<object>(findVariables_CommandExecute);
				}
				return _cmdFindVariables_Command;
			}
		}

		private void cmdNew_CommandExecute(object parameter)
		{
			new GetUserInputEventArgs().DialogResult = null;
			OneIdDialog.maskType mask = (OneIdDialog.maskType)Enum.ToObject(typeof(OneIdDialog.maskType), OneIdDialog.maskType.IS_FORTRAN_VARIABLE);
			OneIdDialog oneIdDialog = new OneIdDialog(base.UnityContainer, AspenTech.AspenPlus.Localization.Properties.Resources.MMDesignSpe_Input_Define_ViewModel__OneIdDialog_Prompt, "", null, mask);
			oneIdDialog.Owner = Window.GetWindow(base.View as DependencyObject);
			oneIdDialog.Title = AspenTech.AspenPlus.Localization.Properties.Resources.MMDesignSpe_Input_Define_ViewModel__OneIdDialog_Title;
			MMHelp.SetHelpFile(oneIdDialog, "apwn.chm");
			MMHelp.SetHelpId(oneIdDialog, 20325);
			oneIdDialog.ShowDialog();
			if (oneIdDialog.DialogResult != false)
			{
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.FVN_VARIABLE", "child_count"));
				if (!num.HasValue)
				{
					num = 0;
				}
				int num2 = Convert.ToInt32(num);
				AddChild("@main.Input.FVN_VARIABLE", num2);
				ExpandDataPathAndSet("@main.Input.FVN_VARIABLE.#" + num2, "id", oneIdDialog.NewID);
				base.ResolvedCxsProvider.UpdateDataCache();
				if (!CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARIABLE.#" + num2, "id")).Equals(oneIdDialog.NewID, StringComparison.InvariantCultureIgnoreCase))
				{
					DeleteChild("@main.Input.FVN_VARIABLE", num2);
					num2--;
				}
				SelectedRowIndexes = new ObservableCollection<int> { num2 };
				UpdateEditDetail();
			}
		}

		private void cmdDelete_CommandExecute(object parameter)
		{
			if (SelectedRowIndexes == null || SelectedRowIndexes.Count == 0)
			{
				ShowMessageBoxEventArgs args = new ShowMessageBoxEventArgs
				{
					Message = AspenTech.AspenPlus.Localization.Properties.Resources.MMDesignSpe_Input_Define_ViewModel__MSGBox_Message2,
					Title = AspenTech.AspenPlus.Localization.Properties.Resources.MMDesignSpe_Input_Define_ViewModel__MSGBox_Title_DeleteVariable,
					MsgBoxButton = MessageBoxButton.OK
				};
				ShowMessageBox(args);
				return;
			}
			IList dataList = grdDefine_GridData as IList;
			IOrderedEnumerable<int> rows = SelectedRowIndexes.OrderBy((int index) => index);
			IEnumerable<string> ids = from index in SelectedRowIndexes
				let itemTemplate = dataList[index] as grdDefine_GridData_ItemTemplate
				orderby index
				select itemTemplate.ResolveViewPropertyPath("txtVarName_var1.Value") as string;
			DeleteChildren("@main.Input.FVN_VARTYPE", rows, ids);
			RefreshButtonStatus();
		}

		private void cmdCopy_CommandExecute(object parameter)
		{
			string mainPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			this.CopyObjectRows(mainPath, "VARGROUP.DEFINE", SelectedRowIndexes);
		}

		private void cmdPaste_CommandExecute(object parameter)
		{
			ExecutePaste();
		}

		public bool ExecutePaste()
		{
			bool result = false;
			if (_isPastingObjectRows)
			{
				string[] oldIds = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids"));
				string mainPath = CxsConverter.ValueToString(ResolveParameter("main", null));
				result = ((SelectedRowIndexes == null || SelectedRowIndexes.Count != 1) ? (this.PasteObjectRows(mainPath, "VARGROUP.DEFINE") != 0) : (this.PasteObjectRows(mainPath, "VARGROUP.DEFINE", SelectedRowIndexes[0]) != 0));
				UpdateSelectedRow(oldIds);
			}
			else
			{
				string asiFormatTextFromClipboard = ClipboardHelper.GetAsiFormatTextFromClipboard();
				if (!string.IsNullOrEmpty(asiFormatTextFromClipboard) && base.ResolvedCxsProvider != null && base.ResolvedCxsProvider.Case != null)
				{
					IList<string> paths = ClipboardHelper.ParseCxsPathFromAsiFormat(asiFormatTextFromClipboard, base.ResolvedCxsProvider.Case.CaseFullFilePath);
					result = PasteVariable(paths);
				}
			}
			return result;
		}

		private void UpdateSelectedRow(IEnumerable<string> oldIds)
		{
			string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids"));
			if (array == null)
			{
				return;
			}
			string text = ((oldIds == null) ? array.FirstOrDefault() : array.Except(oldIds).FirstOrDefault());
			if (string.IsNullOrEmpty(text))
			{
				return;
			}
			ResolveUpdateParameter("xVarName", text);
			if (!(grdDefine_GridData is CxvVectorPropertyData cxvVectorPropertyData))
			{
				return;
			}
			for (int i = 0; i < cxvVectorPropertyData.Count; i++)
			{
				if (cxvVectorPropertyData[i] is grdDefine_GridData_ItemTemplate grdDefine_GridData_ItemTemplate && string.Equals(grdDefine_GridData_ItemTemplate.ExpandDataPathAndGet("@main.Input.FVN_VARTYPE.@y", "id") as string, text))
				{
					SelectedRowIndexes = new ObservableCollection<int>(new int[1] { i });
					break;
				}
			}
		}

		private bool cmdPaste_CommandCanExecute(object parameter)
		{
			if (this.CanPasteObjectRows("FVN"))
			{
				_isPastingObjectRows = true;
				return true;
			}
			if (CanPasteVariable())
			{
				_isPastingObjectRows = false;
				return true;
			}
			return false;
		}

		private bool cmdUp_CommandCanExecute(object parameter)
		{
			bool result = false;
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count > 0 && grdDefine_GridData is CxvVectorPropertyData && SelectedRowIndexes.Count == 1 && SelectedRowIndexes[0] != 0)
			{
				result = true;
			}
			return result;
		}

		private void cmdReorder_0_CommandExecute(object parameter)
		{
			if (SelectedRowIndexes == null || SelectedRowIndexes.Count != 1)
			{
				return;
			}
			int num = SelectedRowIndexes[0];
			if (!(grdDefine_GridData is IList list) || num == 0 || !(list[num] is grdDefine_GridData_ItemTemplate container))
			{
				return;
			}
			string text = container.ResolveViewPropertyPath("txtVarName_var1.Value") as string;
			if (!(list[num - 1] is grdDefine_GridData_ItemTemplate container2))
			{
				return;
			}
			string text2 = container2.ResolveViewPropertyPath("txtVarName_var1.Value") as string;
			if (string.IsNullOrEmpty(text2))
			{
				text2 = "#" + (num - 1);
			}
			int num2 = 0;
			int index = 0;
			int index2 = 0;
			int value = 0;
			List<int> list2 = new List<int>();
			foreach (string item in CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids")))
			{
				if (item == text)
				{
					index = num2;
					value = num2;
				}
				if (item == text2)
				{
					index2 = num2;
				}
				list2.Add(num2);
				num2++;
			}
			list2[index] = list2[index2];
			list2[index2] = value;
			ReorderChildren("@main.Input.FVN_VARTYPE", list2);
			int num3 = 0;
			if (num > 1)
			{
				num3 = num - 1;
			}
			SelectedRowIndexes = new ObservableCollection<int>(new int[1] { num3 });
			if (_cmdReorder_0_Command != null)
			{
				_cmdReorder_0_Command.RaiseCanExecuteChanged();
			}
			if (_cmdReorder_1_Command != null)
			{
				_cmdReorder_1_Command.RaiseCanExecuteChanged();
			}
		}

		private bool cmdDown_CommandCanExecute(object parameter)
		{
			bool result = false;
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count > 0 && grdDefine_GridData is CxvVectorPropertyData cxvVectorPropertyData && SelectedRowIndexes.Count == 1 && SelectedRowIndexes[0] != cxvVectorPropertyData.Count - 1)
			{
				result = true;
			}
			return result;
		}

		private void cmdReorder_1_CommandExecute(object parameter)
		{
			if (SelectedRowIndexes == null || SelectedRowIndexes.Count != 1)
			{
				return;
			}
			int num = SelectedRowIndexes[0];
			if (!(grdDefine_GridData is IList list) || num == list.Count - 1 || !(list[num] is grdDefine_GridData_ItemTemplate container))
			{
				return;
			}
			string text = container.ResolveViewPropertyPath("txtVarName_var1.Value") as string;
			if (!(list[num + 1] is grdDefine_GridData_ItemTemplate container2))
			{
				return;
			}
			string text2 = container2.ResolveViewPropertyPath("txtVarName_var1.Value") as string;
			if (string.IsNullOrEmpty(text2))
			{
				text2 = "#" + (num + 1);
			}
			int num2 = 0;
			int index = 0;
			int index2 = 0;
			int value = 0;
			List<int> list2 = new List<int>();
			foreach (string item in CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids")))
			{
				if (item == text)
				{
					index = num2;
					value = num2;
				}
				if (item == text2)
				{
					index2 = num2;
				}
				list2.Add(num2);
				num2++;
			}
			list2[index] = list2[index2];
			list2[index2] = value;
			ReorderChildren("@main.Input.FVN_VARTYPE", list2);
			int num3 = list.Count - 1;
			if (num < num3)
			{
				num3 = num + 1;
			}
			SelectedRowIndexes = new ObservableCollection<int>(new int[1] { num3 });
			if (_cmdReorder_0_Command != null)
			{
				_cmdReorder_0_Command.RaiseCanExecuteChanged();
			}
			if (_cmdReorder_1_Command != null)
			{
				_cmdReorder_1_Command.RaiseCanExecuteChanged();
			}
		}

		private void cmdViewvariable_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMDesignSpec.MMDesignSpe_ViewDefinevariables_List",
				LegacyFlags = 0,
				HelpId = 4,
				HelpFile = "hlpflwop.chm",
				ShowPrompts = true,
				ResizeMode = ResizeMode.CanResizeWithGrip,
				ShortName = AspenTech.AspenPlus.Localization.Properties.Resources.ShortName_ViewDefinevariables_Format
			});
		}

		private bool cmdViewvariable_CommandCanExecute(object parameter)
		{
			return CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids")) != null;
		}

		private void cmdFind_CommandExecute(object parameter)
		{
			CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = mnuVarname_ListVar as CxvAdvCollectionPropertyData;
			string selectedItem = cxvAdvCollectionPropertyData.SelectedItem;
			int num = -1;
			for (int i = 0; i < cxvAdvCollectionPropertyData.Items.Count; i++)
			{
				if (cxvAdvCollectionPropertyData.Items[i].Display == selectedItem)
				{
					num = i;
					break;
				}
			}
			this.GxSearchVariable(ExpandDataPath("@main"), num + 1, selectedItem, "", "DEFINE");
			Display2();
			UpdateAll();
			UpdateDisplay();
		}

		private void _cboVarTypevw_var2_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			Display2();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "optCategory_MultiMap" && subPropertyName == "Value")
			{
				if (optCategory_MultiMap is CxvMultiMapPropertyData { Value: not null } cxvMultiMapPropertyData)
				{
					string optVal = cxvMultiMapPropertyData.Value.ToString();
					UpdateVarTypeOptions(optVal);
					Display2();
				}
			}
			else if (pd.Name == "mnuVarname_ListVar" && subPropertyName == "SelectedItem")
			{
				DoVarnameChange();
			}
			else if (subPropertyName == "Value")
			{
				Display2();
			}
		}

		private void UpdateVarTypeOptions(string optVal)
		{
			ObjType objType = optVal switch
			{
				"ALL" => ObjType.otAll, 
				"BLOCK" => ObjType.otBlock, 
				"STREAM" => ObjType.otStream, 
				"MODUT" => ObjType.otUtility, 
				"PROP" => ObjType.otProperty, 
				"REACT" => ObjType.otReactions, 
				"SENSOR" => ObjType.otSensor, 
				"COST" => ObjType.otCosting, 
				_ => ObjType.otAll, 
			};
			List<VarType> list = VAVarTypeInit(CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "option_list")));
			if (list == null)
			{
				return;
			}
			if (objType == ObjType.otAll)
			{
				if (cboVarTypevw_var2 == null)
				{
					cboVarTypevw_var2 = new ObservableCollection<string>();
				}
				cboVarTypevw_var2.Clear();
				{
					foreach (VarType item in list)
					{
						cboVarTypevw_var2.Add(item.MCase);
					}
					return;
				}
			}
			List<VarType> list2 = VAGetVarIndex(list, objType);
			if (cboVarTypevw_var2 == null)
			{
				cboVarTypevw_var2 = new ObservableCollection<string>();
			}
			cboVarTypevw_var2.Clear();
			foreach (VarType item2 in list2)
			{
				cboVarTypevw_var2.Add(item2.MCase);
			}
			if (!(mnuVarname_ListVar is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData))
			{
				return;
			}
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + cxvAdvCollectionPropertyData.SelectedItem, "value"));
			if (text == null)
			{
				return;
			}
			if (VAVarFindUCaseIndex(list, text) == -1)
			{
				if (objType == ObjType.otSensor)
				{
					SetSensorVarType();
				}
				return;
			}
			foreach (VarType item3 in list2)
			{
				if (text == item3.UCase)
				{
					return;
				}
			}
			ClearVarType();
		}

		private void DoVarnameChange()
		{
			if (mnuVarname_ListVar is CxvAdvCollectionPropertyData { SelectedItem: var selectedItem })
			{
				string optVal = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.OPT_CATEG." + selectedItem, "value"));
				UpdateVarTypeOptions(optVal);
				ResolveUpdateParameter("xInt", selectedItem);
				OnPropertyChanged("cboVarTypevw_SelectedValue");
			}
		}

		private void ClearVarType()
		{
			ExpandDataPathAndSet("@main.Input.FVN_VARTYPE.@xInt", "value", "");
			OnPropertyChanged("cboVarTypevw_SelectedValue");
		}

		private void SetSensorVarType()
		{
			ExpandDataPathAndSet("@main.Input.FVN_VARTYPE.@xInt", "value", "SENSOR-VAR");
			OnPropertyChanged("cboVarTypevw_SelectedValue");
		}

		private void Display2()
		{
			List<PromptType> list = VAPromptInit();
			byte b = 0;
			for (int i = 0; i < cmdFind_Visibilities.Length; i++)
			{
				cmdFind_Visibilities[i] = Visibility.Collapsed;
			}
			ResolveUpdateParameter("p_BlockVarVisible", "0", localOnly: true);
			ResolveUpdateParameter("p_HybridVarVisible", "0", localOnly: true);
			for (int j = 0; j < list.Count; j++)
			{
				PromptType promptType = list[j];
				string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + promptType.Variable + ".@xInt", "can_enter"));
				if (text == null)
				{
					continue;
				}
				string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + promptType.Variable + ".@xInt", "value"));
				if (text2 == null)
				{
					continue;
				}
				bool flag = !(text == "1");
				if (flag && (!(promptType.Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units) || !(text2 != "")))
				{
					continue;
				}
				_label_Visibilities[b] = Visibility.Visible;
				_label_captions[b] = list[j].Text;
				object obj = ExpandDataPathAndGet("@main.Input." + promptType.Variable + ".@xInt", "option_list");
				if (obj == null || obj.GetType() == typeof(DBNull) || list[j].Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence)
				{
					_combo_Visibilities[b] = Visibility.Collapsed;
					_textEdit_Visibilities[b] = Visibility.Visible;
				}
				else
				{
					_combo_Visibilities[b] = Visibility.Visible;
					_textEdit_Visibilities[b] = Visibility.Collapsed;
				}
				if (promptType.Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable && _combo_Visibilities[b] == Visibility.Visible)
				{
					cmdFind_Visibilities[b] = Visibility.Visible;
					ComboWidth[b] = 154;
				}
				else if (list[j].Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable && (cboVarTypevw_SelectedValue == "Block-Var" || cboVarTypevw_SelectedValue == "Sensor-Var"))
				{
					_combo_Visibilities[b] = Visibility.Collapsed;
					_textEdit_Visibilities[b] = Visibility.Collapsed;
					string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_BLOCK.@xInt", "value"));
					if (!string.IsNullOrEmpty(text3))
					{
						text3 = GetFullBlockName("@main", text3);
						if (GetModelCategoryByBlockName(text3) == 14 || cboVarTypevw_SelectedValue == "Sensor-Var")
						{
							ResolveUpdateParameter("p_HybridVarVisible", "1");
						}
						else
						{
							ResolveUpdateParameter("p_BlockVarVisible", "1");
						}
					}
				}
				else
				{
					ComboWidth[b] = 182;
				}
				if (promptType.Variable == "FVN_UOM")
				{
					Combo_AllowClear[b] = false;
				}
				else
				{
					Combo_AllowClear[b] = true;
				}
				if (base.View is MMSetup_VarGroup_Define mMSetup_VarGroup_Define)
				{
					MMTextEdit mMTextEdit = mMSetup_VarGroup_Define.FindName("txtRowsvw_" + b) as MMTextEdit;
					MMComboEdit mMComboEdit = mMSetup_VarGroup_Define.FindName("cboRowsvw_" + b) as MMComboEdit;
					MMValueEdit mMValueEdit = mMSetup_VarGroup_Define.FindName("txtRowsvw_" + b) as MMValueEdit;
					if (flag || list[j].Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence)
					{
						if (mMTextEdit != null)
						{
							mMTextEdit.IsMMEnabled = false;
						}
						if (mMComboEdit != null)
						{
							mMComboEdit.IsMMEnabled = false;
						}
						if (mMValueEdit != null)
						{
							mMValueEdit.IsMMEnabled = false;
						}
					}
					else
					{
						if (mMTextEdit != null)
						{
							mMTextEdit.IsMMEnabled = true;
						}
						if (mMComboEdit != null)
						{
							mMComboEdit.IsMMEnabled = true;
						}
						if (mMValueEdit != null)
						{
							mMValueEdit.IsMMEnabled = true;
						}
					}
					if (mMComboEdit != null)
					{
						if (list[j].Text == AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units && !mMComboEdit.IsMMEnabled)
						{
							mMComboEdit.DisplayAsTextBox = true;
						}
						else
						{
							mMComboEdit.DisplayAsTextBox = false;
						}
					}
				}
				if (list[j].ConvertToMixedCase)
				{
					ResolveUpdateParameter("RowsvwD_" + b + "_IsMixedCase", "1");
				}
				else
				{
					ResolveUpdateParameter("RowsvwD_" + b + "_IsMixedCase", "0");
				}
				ResolveUpdateParameter("vwrow" + b, promptType.Variable);
				b++;
				if (b > 7)
				{
					break;
				}
			}
			for (int k = b; k <= 7; k++)
			{
				_label_Visibilities[k] = Visibility.Collapsed;
				_combo_Visibilities[k] = Visibility.Collapsed;
				_textEdit_Visibilities[k] = Visibility.Collapsed;
			}
			OnPropertyChanged("Label_Captions");
			OnPropertyChanged("Label_Visibilities");
			OnPropertyChanged("Combo_Visibilities");
			OnPropertyChanged("TextEdit_Visibilities");
			OnPropertyChanged("cmdFind_Visibilities");
			OnPropertyChanged("ComboWidth");
			OnPropertyChanged("Combo_AllowClear");
		}

		public static List<VarType> VAGetVarIndex(List<VarType> VarTypes, ObjType oType)
		{
			List<VarType> list = new List<VarType>();
			switch (oType)
			{
			case ObjType.otAll:
				list = VarTypes;
				break;
			case ObjType.otBlock:
				foreach (VarType VarType in VarTypes)
				{
					if (VarType.UCase == "BLOCK-VAR" || VarType.UCase == "BLOCK-VEC" || VarType.UCase == "MEAS-VAR" || VarType.UCase == "CONT-VAR" || VarType.UCase == "CONFIG-VAR")
					{
						list.Add(VarType);
					}
				}
				break;
			case ObjType.otStream:
				foreach (VarType VarType2 in VarTypes)
				{
					if (VarType2.UCase == "STREAM-VAR" || VarType2.UCase == "MOLE-FLOW" || VarType2.UCase == "MOLE-FRAC" || VarType2.UCase == "MASS-FLOW" || VarType2.UCase == "MASS-FRAC" || VarType2.UCase == "STDVOL-FLOW" || VarType2.UCase == "STDVOL-FRAC" || VarType2.UCase == "STREAM-VEC" || VarType2.UCase == "STREAM-PROP" || VarType2.UCase == "SUBSTRM-VEC" || VarType2.UCase == "COMPATTR-VAR" || VarType2.UCase == "COMPATTR-VEC" || VarType2.UCase == "SUBSATTR-VAR" || VarType2.UCase == "SUBSATTR-VEC" || VarType2.UCase == "HEAT-DUTY" || VarType2.UCase == "WORK-POWER" || VarType2.UCase == "HEAT-TEMP" || VarType2.UCase == "HEAT-TEND" || VarType2.UCase == "QVEC" || VarType2.UCase == "TVEC" || VarType2.UCase == "STREAM-COST" || VarType2.UCase == "POWER-POWER")
					{
						list.Add(VarType2);
					}
				}
				break;
			case ObjType.otUtility:
				foreach (VarType VarType3 in VarTypes)
				{
					if (VarType3.UCase == "PARAMETER" || VarType3.UCase == "LOCAL-PARAM" || VarType3.UCase == "BALANCE-VAR" || VarType3.UCase == "PRESR-VAR" || VarType3.UCase == "UTILITY")
					{
						list.Add(VarType3);
					}
				}
				break;
			case ObjType.otProperty:
				foreach (VarType VarType4 in VarTypes)
				{
					if (VarType4.UCase == "UNARY-PARAM" || VarType4.UCase == "UNARY-COR-EL" || VarType4.UCase == "UN-COR-VEC" || VarType4.UCase == "BI-PARAM" || VarType4.UCase == "BI-COR-EL" || VarType4.UCase == "BI-COR-VEC" || VarType4.UCase == "NC-PARAM" || VarType4.UCase == "NC-COR-EL" || VarType4.UCase == "NC-COR-VEC" || VarType4.UCase == "GROUP-PARAM" || VarType4.UCase == "GROUP-BI-PAR" || VarType4.UCase == "GR-BI-COR-EL")
					{
						list.Add(VarType4);
					}
				}
				break;
			case ObjType.otReactions:
				foreach (VarType VarType5 in VarTypes)
				{
					if (VarType5.UCase == "CHEM-VAR" || VarType5.UCase == "REACT-VAR")
					{
						list.Add(VarType5);
					}
				}
				break;
			case ObjType.otSensor:
				foreach (VarType VarType6 in VarTypes)
				{
					if (VarType6.UCase == "SENSOR-VAR")
					{
						list.Add(VarType6);
					}
				}
				break;
			case ObjType.otCosting:
				foreach (VarType VarType7 in VarTypes)
				{
					if (VarType7.UCase == "BYPROD-VAR" || VarType7.UCase == "CAPITAL-VAR" || VarType7.UCase == "CBLOCK-VAR" || VarType7.UCase == "LABOR-VAR" || VarType7.UCase == "OPER-COST-VA" || VarType7.UCase == "PRODUCT-VAR" || VarType7.UCase == "PROFIT-VAR" || VarType7.UCase == "RAW-MAT-VAR" || VarType7.UCase == "STARTUP-VAR" || VarType7.UCase == "UNIT-VAR" || VarType7.UCase == "UTILITY-VAR" || VarType7.UCase == "WASTE-VAR" || VarType7.UCase == "WORK-CAP-VAR")
					{
						list.Add(VarType7);
					}
				}
				break;
			case ObjType.otOther:
				foreach (VarType VarType8 in VarTypes)
				{
					if (VarType8.UCase == "MEAS-VAR" || VarType8.UCase == "CONT-VAR")
					{
						list.Add(VarType8);
					}
				}
				break;
			}
			return list;
		}

		public static string VAVarFindMCase(List<VarType> VarTypes, string UCase)
		{
			string result = null;
			foreach (VarType VarType in VarTypes)
			{
				if (UCase == VarType.UCase)
				{
					result = VarType.MCase;
					break;
				}
			}
			return result;
		}

		public static int VAVarFindUCaseIndex(List<VarType> VarTypes, string UCase)
		{
			int result = -1;
			int num = 0;
			foreach (VarType VarType in VarTypes)
			{
				if (UCase == VarType.UCase)
				{
					result = num;
					break;
				}
				num++;
			}
			return result;
		}

		private void UpdateFormat()
		{
			if (_formatWatch != null)
			{
				_formatWatch.PropertyDependencyChanged -= _formatWatch_PropertyDependencyChanged;
				_formatWatch.Clear();
			}
			else
			{
				_formatWatch = new CxvPropertyWatch();
			}
			if (string.IsNullOrEmpty(CxsConverter.ValueToString(ResolveViewPropertyPath("format_var.Value", _formatWatch))))
			{
				_colorIndex = 0;
				_lineWeight = 3.0;
				LineStyle = 0;
				LineColor = _definedColors[_colorIndex];
			}
			else
			{
				int? num = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.ColorIndex"));
				if (num.HasValue)
				{
					_colorIndex = num.Value;
				}
				int? num2 = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.LineWeight"));
				if (num2.HasValue)
				{
					_lineWeight = num2.Value;
				}
				int? num3 = CxsConverter.ValueToInt32(this.ResolveViewPropertyPath("format_var.LineStyle"));
				if (num3.HasValue)
				{
					_lineStyle = num3.Value;
				}
				_lineColor = (Color)this.ResolveViewPropertyPath("format_var.LineColor");
			}
			OnPropertyChanged("ColorIndex");
			OnPropertyChanged("LineWeight");
			OnPropertyChanged("LineStyle");
			OnPropertyChanged("LineColor");
			if (!_formatWatch.IsEmpty)
			{
				_formatWatch.PropertyDependencyChanged += _formatWatch_PropertyDependencyChanged;
			}
			else
			{
				_formatWatch = null;
			}
		}

		private void _formatWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateFormat();
		}

		public void SaveFormat()
		{
			string text = $"{LineColor};{(int)LineWeight};{LineStyle}";
			if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_LINESTYL.@xInt", "value")) != text)
			{
				ExpandDataPathAndSet("@main.Input.FVN_LINESTYL.@xInt", "value", text);
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				InitializeVaVar(this);
				DoVarnameChange();
				UpdateFormat();
				if (CxsConverter.ValueToString(ResolveParameter("main", null)).Contains("Variable-Groups.$PLOTVG"))
				{
					ResolveUpdateParameter("p_IsSystemGenerate", "1");
					_ExpandDefine = false;
				}
				else
				{
					ResolveUpdateParameter("p_IsSystemGenerate", "0");
					_ExpandDefine = true;
				}
			}
		}

		public static void InitializeVaVar(CxvViewModel vm)
		{
			if (vm != null)
			{
				VAPromptInit();
				VAVarTypeInit(CxsConverter.ValueToStringCollection(vm.ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "option_list")));
			}
		}

		public MMSetup_VarGroup_Define_ViewModel()
		{
			_watcher.PropertyDependencyChanged += _watcher_PropertyDependencyChanged;
		}

		private void _watcher_PropertyDependencyChanged(object sender, EventArgs e)
		{
			RefreshButtonStatus();
		}

		private int GetRowCount()
		{
			return CxsConverter.ValueToInt32(ResolveViewPropertyPath("grdDefine_GridData.Count", _watcher)).GetValueOrDefault();
		}

		private void statusWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			OnPropertyChanged("IsBlockActive");
		}

		private void _selectedRowIndexes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			RefreshButtonStatus();
			UpdateEditDetail();
		}

		private void UpdateEditDetail()
		{
			if (base.View == null || SelectedRowIndexes == null || SelectedRowIndexes.Count != 1)
			{
				return;
			}
			int index = SelectedRowIndexes[0];
			if ((grdDefine_GridData as IList)[index] is grdDefine_GridData_ItemTemplate grdDefine_GridData_ItemTemplate)
			{
				string value = grdDefine_GridData_ItemTemplate.ExpandDataPathAndGet("@main.Input.FVN_VARTYPE.@y", "id") as string;
				if (!string.IsNullOrEmpty(value))
				{
					ResolveUpdateParameter("xVarName", value);
				}
			}
		}

		public static List<PromptType> VAPromptInit()
		{
			if (Prompts == null)
			{
				Prompts = new List<PromptType>();
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Block,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Block1,
					Variable = "FVN_BLOCK"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Stream,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Stream1,
					Variable = "FVN_STREAM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Substream,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Substream1,
					Variable = "FVN_SUBS"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Component,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Component1,
					Variable = "FVN_COMPONEN"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ParaNo,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ParaNo1,
					Variable = "FVN_PARAMNO"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Attribute,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Attribute1,
					Variable = "FVN_ATTRIB"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable1,
					Variable = "FVN_VARIABLE"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence1,
					Variable = "FVN_SENTENCE"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID1,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID11,
					Variable = "FVN_ID1"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID2,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID21,
					Variable = "FVN_ID2"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID3,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID31,
					Variable = "FVN_ID3"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Element,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Element1,
					Variable = "FVN_ELEM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PropSet,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PropSet1,
					Variable = "FVN_PROPSET"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PhysicalType,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PhysicalType1,
					Variable = "FVN_PHYS_QTY",
					HideWhenLocked = true,
					ConvertToMixedCase = true
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units1,
					Variable = "FVN_UOM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__InitialValue,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__InitialValue1,
					Variable = "FVN_INIT_VAL"
				});
			}
			return Prompts;
		}

		public static List<VarType> VAVarTypeInit(Collection<string> oplist)
		{
			if (VarTypes == null)
			{
				VarTypes = new List<VarType>();
				VarTypes.Add(new VarType
				{
					MCase = "Balance-Var",
					UCase = "BALANCE-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Cor-El",
					UCase = "BI-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Cor-Vec",
					UCase = "BI-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Param",
					UCase = "BI-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Block-Var",
					UCase = "BLOCK-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Block-Vec",
					UCase = "BLOCK-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Byprod-Var",
					UCase = "BYPROD-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Capital-Var",
					UCase = "CAPITAL-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Cblock-Var",
					UCase = "CBLOCK-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Chem-Var",
					UCase = "CHEM-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Compattr-Var",
					UCase = "COMPATTR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Compattr-Vec",
					UCase = "COMPATTR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Config-Var",
					UCase = "CONFIG-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Cont-Var",
					UCase = "CONT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Costing-Utility-Var",
					UCase = "UTILITY-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Param",
					UCase = "GROUP-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Bi-Param",
					UCase = "GROUP-BI-PAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Bi-Cor-El",
					UCase = "GR-BI-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-Duty",
					UCase = "HEAT-DUTY"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-Temp",
					UCase = "HEAT-TEMP"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-T-End",
					UCase = "HEAT-TEND"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Labor-Var",
					UCase = "LABOR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Local-Param",
					UCase = "LOCAL-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mass-Flow",
					UCase = "MASS-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mass-Frac",
					UCase = "MASS-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Meas-Var",
					UCase = "MEAS-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mole-Flow",
					UCase = "MOLE-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mole-Frac",
					UCase = "MOLE-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Cor-El",
					UCase = "NC-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Cor-Vec",
					UCase = "NC-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Param",
					UCase = "NC-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Oper-Cost-Var",
					UCase = "OPER-COST-VA"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Parameter",
					UCase = "PARAMETER"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Power-Power",
					UCase = "POWER-POWER"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Presr-Var",
					UCase = "PRESR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Product-Var",
					UCase = "PRODUCT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Profit-Var",
					UCase = "PROFIT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "PSD-Var",
					UCase = "SUBSATTR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "PSD-Vec",
					UCase = "SUBSATTR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Q-Vec",
					UCase = "QVEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Raw-Mat-Var",
					UCase = "RAW-MAT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "React-Var",
					UCase = "REACT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Sensor-Var",
					UCase = "SENSOR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Startup-Var",
					UCase = "STARTUP-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "StdVol-Flow",
					UCase = "STDVOL-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "StdVol-Frac",
					UCase = "STDVOL-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Cost",
					UCase = "STREAM-COST"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Prop",
					UCase = "STREAM-PROP"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Var",
					UCase = "STREAM-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Vec",
					UCase = "STREAM-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Substrm-Vec",
					UCase = "SUBSTRM-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "T-Vec",
					UCase = "TVEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unary-Cor-El",
					UCase = "UNARY-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unary-Param",
					UCase = "UNARY-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unit-Var",
					UCase = "UNIT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Utility-Var",
					UCase = "UTILITY"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Un-Cor-Vec",
					UCase = "UN-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Waste-Var",
					UCase = "WASTE-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Work-Cap-Var",
					UCase = "WORK-CAP-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Work-Power",
					UCase = "WORK-POWER"
				});
				List<VarType> list = new List<VarType>();
				if (oplist != null && oplist.Count > 0)
				{
					string[] array = new string[oplist.Count];
					bool[] array2 = new bool[oplist.Count];
					for (int i = 0; i < oplist.Count; i++)
					{
						array[i] = oplist[i];
						array2[i] = false;
					}
					foreach (VarType varType in VarTypes)
					{
						for (int j = 0; j < array.Length; j++)
						{
							if (array[j] == varType.UCase)
							{
								list.Add(varType);
								array2[j] = true;
								break;
							}
						}
					}
					for (int k = 0; k < array2.Length; k++)
					{
						if (!array2[k])
						{
							list.Add(new VarType
							{
								UCase = array[k],
								MCase = StrConvMixCase(array[k])
							});
						}
					}
					VarTypes = list;
				}
			}
			return VarTypes;
		}

		public static string StrConvMixCase(string InpVal)
		{
			string text = "";
			try
			{
				int result = 0;
				if (int.TryParse(InpVal, out result))
				{
					text = InpVal;
					return text;
				}
				string[] array = InpVal.Split('-');
				for (int i = 0; i < array.Length; i++)
				{
					if (array[i].Length > 1)
					{
						array[i] = array[i].Substring(0, 1).ToUpper() + array[i].Substring(1).ToLower();
					}
					else if (array[i].Length > 0)
					{
						array[i] = array[i].ToUpper();
					}
				}
				for (int j = 0; j < array.Length - 1; j++)
				{
					text = text + array[j] + "-";
				}
				text += array[array.Length - 1];
			}
			catch
			{
			}
			return text;
		}

		private void RefreshButtonStatus()
		{
			cmdDelete_Command.RaiseCanExecuteChanged();
			cmdCopy_Command.RaiseCanExecuteChanged();
			cmdReorder_0_Command.RaiseCanExecuteChanged();
			cmdReorder_1_Command.RaiseCanExecuteChanged();
		}

		public override bool PasteVariable(IEnumerable<string> paths)
		{
			if (!(CxsConverter.ValueToBoolean(ResolveParameter("p_IsSystemGenerate")) ?? false) && paths != null && paths.Count() > 0)
			{
				bool ShowedMessage = false;
				string[] oldIds = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_ids"));
				foreach (string path in paths)
				{
					if (!string.IsNullOrEmpty(path))
					{
						SmgeExtensions.SMVariableAccessingParse(this, path, VarAcessType.Define, ref ShowedMessage);
					}
				}
				UpdateSelectedRow(oldIds);
				OnPropertyChanged("cboVarTypevw_SelectedValue");
				return true;
			}
			return base.PasteVariable(paths);
		}

		private void findVariables_CommandExecute(object parameter)
		{
			FindVariables(ExpandDataPath("@main.Input.SHOWDLG"));
			UpdateDisplay();
		}
	}
	public enum ObjType
	{
		otAll,
		otBlock,
		otStream,
		otUtility,
		otProperty,
		otReactions,
		otSensor,
		otCosting,
		otOther
	}
	public class VRowMaskConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value as Type == typeof(double))
			{
				return AesMaskOption.Double;
			}
			return AesMaskOption.None;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	[ProgId("MMSetup.MMSetup_VarGroup_Define")]
	public class MMSetup_VarGroup_Define : MMTabPagePastable, IComponentConnector
	{
		internal MMCheckBox MMCheckBox1;

		internal MMExpander DefineAll;

		internal MMFlatButton cmdNew;

		internal MMFlatButton cmdDelete;

		internal MMFlatButton cmdCopy;

		internal MMFlatButton cmdPaste;

		internal MMFlatButton cmdMoveUp;

		internal MMFlatButton cmdMoveDown;

		internal MMScrollAreaMS grdDefine;

		internal MMExpander Define;

		internal MMLabel lblVarname;

		internal MMAdvancedComboEdit mnuVarname;

		internal MMOptionGroup optCategory;

		internal MMOptionButton ALL;

		internal MMOptionButton BLOCK;

		internal MMOptionButton STREAM;

		internal MMOptionButton MODUT;

		internal MMOptionButton PROP;

		internal MMOptionButton REACT;

		internal MMOptionButton SENSOR;

		internal MMGroupBox frmReference;

		internal MMLabel lblVaryTypevw;

		internal MMComboEdit cboVarTypevw;

		internal MMLabel lblrowsvw_0;

		internal MMTextEdit txtRowsvw_0;

		internal MMComboEdit cboRowsvw_0;

		internal MMFindButton cmdFind0;

		internal MMLabel lblrowsvw_1;

		internal MMTextEdit txtRowsvw_1;

		internal MMComboEdit cboRowsvw_1;

		internal MMFindButton cmdFind1;

		internal MMEOBrowseEditor txtBlockVar;

		internal MMLabel lblrowsvw_2;

		internal MMValueEdit txtRowsvw_2;

		internal MMComboEdit cboRowsvw_2;

		internal MMFindButton cmdFind2;

		internal MMLabel lblrowsvw_3;

		internal MMTextEdit txtRowsvw_3;

		internal MMComboEdit cboRowsvw_3;

		internal MMFindButton cmdFind3;

		internal MMLabel lblrowsvw_4;

		internal MMTextEdit txtRowsvw_4;

		internal MMComboEdit cboRowsvw_4;

		internal MMFindButton cmdFind4;

		internal MMLabel lblrowsvw_5;

		internal MMTextEdit txtRowsvw_5;

		internal MMComboEdit cboRowsvw_5;

		internal MMFindButton cmdFind5;

		internal MMLabel lblrowsvw_6;

		internal MMTextEdit txtRowsvw_6;

		internal MMComboEdit cboRowsvw_6;

		internal MMFindButton cmdFind6;

		internal MMLabel lblrowsvw_7;

		internal MMTextEdit txtRowsvw_7;

		internal MMComboEdit cboRowsvw_7;

		internal MMFindButton cmdFind7;

		internal XamColorPicker LineColorPicker;

		internal LineWeightPicker lieghtWeightPicker1;

		internal LineStylePicker lineStylePicker1;

		private bool _contentLoaded;

		public MMSetup_VarGroup_Define()
		{
			base.ViewModelType = typeof(MMSetup_VarGroup_Define_ViewModel);
			InitializeComponent();
		}

		protected override bool IsAllowedPasteTarget(DragEventArgs e)
		{
			bool flag = base.IsAllowedPasteTarget(e);
			if (!flag)
			{
				flag = Utilities.GetAncestorFromType(e.OriginalSource as DependencyObject, typeof(MMScrollAreaMS), allowSubclassOfType: false) is MMScrollAreaMS mMScrollAreaMS && string.Equals(mMScrollAreaMS.Name, "grdDefine");
			}
			return flag;
		}

		public override bool OnRibbonCopy()
		{
			if (base.ViewModel != null)
			{
				(base.ViewModel as MMSetup_VarGroup_Define_ViewModel).cmdCopy_Command.Execute(null);
				return true;
			}
			return base.OnRibbonCopy();
		}

		public override bool OnRibbonCanPaste()
		{
			if (base.ViewModel != null)
			{
				return (base.ViewModel as MMSetup_VarGroup_Define_ViewModel).cmdPaste_Command.CanExecute(null);
			}
			return base.OnRibbonCanPaste();
		}

		public override bool OnRibbonPaste()
		{
			if (base.ViewModel != null)
			{
				return (base.ViewModel as MMSetup_VarGroup_Define_ViewModel).ExecutePaste();
			}
			return base.OnRibbonPaste();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_vargroup_define.xaml", UriKind.Relative);
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
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 2:
				DefineAll = (MMExpander)target;
				break;
			case 3:
				cmdNew = (MMFlatButton)target;
				break;
			case 4:
				cmdDelete = (MMFlatButton)target;
				break;
			case 5:
				cmdCopy = (MMFlatButton)target;
				break;
			case 6:
				cmdPaste = (MMFlatButton)target;
				break;
			case 7:
				cmdMoveUp = (MMFlatButton)target;
				break;
			case 8:
				cmdMoveDown = (MMFlatButton)target;
				break;
			case 9:
				grdDefine = (MMScrollAreaMS)target;
				break;
			case 10:
				Define = (MMExpander)target;
				break;
			case 11:
				lblVarname = (MMLabel)target;
				break;
			case 12:
				mnuVarname = (MMAdvancedComboEdit)target;
				break;
			case 13:
				optCategory = (MMOptionGroup)target;
				break;
			case 14:
				ALL = (MMOptionButton)target;
				break;
			case 15:
				BLOCK = (MMOptionButton)target;
				break;
			case 16:
				STREAM = (MMOptionButton)target;
				break;
			case 17:
				MODUT = (MMOptionButton)target;
				break;
			case 18:
				PROP = (MMOptionButton)target;
				break;
			case 19:
				REACT = (MMOptionButton)target;
				break;
			case 20:
				SENSOR = (MMOptionButton)target;
				break;
			case 21:
				frmReference = (MMGroupBox)target;
				break;
			case 22:
				lblVaryTypevw = (MMLabel)target;
				break;
			case 23:
				cboVarTypevw = (MMComboEdit)target;
				break;
			case 24:
				lblrowsvw_0 = (MMLabel)target;
				break;
			case 25:
				txtRowsvw_0 = (MMTextEdit)target;
				break;
			case 26:
				cboRowsvw_0 = (MMComboEdit)target;
				break;
			case 27:
				cmdFind0 = (MMFindButton)target;
				break;
			case 28:
				lblrowsvw_1 = (MMLabel)target;
				break;
			case 29:
				txtRowsvw_1 = (MMTextEdit)target;
				break;
			case 30:
				cboRowsvw_1 = (MMComboEdit)target;
				break;
			case 31:
				cmdFind1 = (MMFindButton)target;
				break;
			case 32:
				txtBlockVar = (MMEOBrowseEditor)target;
				break;
			case 33:
				lblrowsvw_2 = (MMLabel)target;
				break;
			case 34:
				txtRowsvw_2 = (MMValueEdit)target;
				break;
			case 35:
				cboRowsvw_2 = (MMComboEdit)target;
				break;
			case 36:
				cmdFind2 = (MMFindButton)target;
				break;
			case 37:
				lblrowsvw_3 = (MMLabel)target;
				break;
			case 38:
				txtRowsvw_3 = (MMTextEdit)target;
				break;
			case 39:
				cboRowsvw_3 = (MMComboEdit)target;
				break;
			case 40:
				cmdFind3 = (MMFindButton)target;
				break;
			case 41:
				lblrowsvw_4 = (MMLabel)target;
				break;
			case 42:
				txtRowsvw_4 = (MMTextEdit)target;
				break;
			case 43:
				cboRowsvw_4 = (MMComboEdit)target;
				break;
			case 44:
				cmdFind4 = (MMFindButton)target;
				break;
			case 45:
				lblrowsvw_5 = (MMLabel)target;
				break;
			case 46:
				txtRowsvw_5 = (MMTextEdit)target;
				break;
			case 47:
				cboRowsvw_5 = (MMComboEdit)target;
				break;
			case 48:
				cmdFind5 = (MMFindButton)target;
				break;
			case 49:
				lblrowsvw_6 = (MMLabel)target;
				break;
			case 50:
				txtRowsvw_6 = (MMTextEdit)target;
				break;
			case 51:
				cboRowsvw_6 = (MMComboEdit)target;
				break;
			case 52:
				cmdFind6 = (MMFindButton)target;
				break;
			case 53:
				lblrowsvw_7 = (MMLabel)target;
				break;
			case 54:
				txtRowsvw_7 = (MMTextEdit)target;
				break;
			case 55:
				cboRowsvw_7 = (MMComboEdit)target;
				break;
			case 56:
				cmdFind7 = (MMFindButton)target;
				break;
			case 57:
				LineColorPicker = (XamColorPicker)target;
				break;
			case 58:
				lieghtWeightPicker1 = (LineWeightPicker)target;
				break;
			case 59:
				lineStylePicker1 = (LineStylePicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_VarGroup_ObjManager_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y",
				SubObjectTypePath = "[]",
				IsEnabledCondition = new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanRename",
					Value = true
				}
			});

			public static readonly CxvPropertyDeclaration txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.DESCRIPTION"
			});

			private const int HAP_DISABLED = 4096;

			private const int HAP_ENABLED = 8192;

			private bool _isBlockActive = true;

			public static CxvPropertyDeclaration Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdChild_GridData_ItemTemplate), new CxvParameterProperty
			{
				PropertyPath = "IsBlockActive",
				IsReadOnlyParamter = "p_IsSystemGenerated"
			});

			public static CxvPropertyDeclaration cmdDelete_var1_Property = CxvPropertyDeclaration.Register("cmdDelete_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCmdButtonProperty
			{
				IsVisibleCondition = new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanDelete",
					Value = true
				}
			});

			public object txtName_var1 => GetValue(txtName_var1_Property);

			public object txtDescription_var1 => GetValue(txtDescription_var1_Property);

			public bool IsBlockActive
			{
				get
				{
					_isBlockActive = GetIsBlockActive(GetId());
					return _isBlockActive;
				}
				set
				{
					ActivateOrDeactivateBlockNode(ExpandDataPath("@main.@y"), value);
					_isBlockActive = value;
					OnPropertyChanged("IsBlockActive");
				}
			}

			public object Active_var => GetValue(Active_var_Property);

			public bool CanRename
			{
				get
				{
					string path = ExpandDataPath("@main");
					try
					{
						if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "RenameChild")).CanInvoke)
						{
							return true;
						}
						if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath("@main.@y"), "can_enter_id", null)) ?? false))
						{
							return false;
						}
					}
					catch (Exception)
					{
						return false;
					}
					return true;
				}
			}

			public object cmdDelete_var1 => GetValue(cmdDelete_var1_Property);

			public bool CanDelete
			{
				get
				{
					string path = ExpandDataPath("@main");
					try
					{
						if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "DeleteChild")).CanInvoke)
						{
							return true;
						}
						if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath("@main.@y"), "can_delete", null)) ?? false))
						{
							return false;
						}
					}
					catch (Exception)
					{
						return false;
					}
					return true;
				}
			}

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
			}

			public string GetDescription()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtDescription_var1.Value", null));
			}

			private bool GetIsBlockActive(string id)
			{
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main." + id, "status_code"));
				if (num.HasValue && (num.Value & 0x2000) != 0)
				{
					return true;
				}
				return false;
			}

			protected override void OnUpdateData()
			{
				string text = CxsConverter.ValueToString(ResolveParameter("y"));
				if (!string.IsNullOrEmpty(text))
				{
					if ((CxsConverter.ValueToBoolean(this.ResolveViewPropertyPath("Active_var.Value")) ?? false) != IsBlockActive)
					{
						ResolveUpdateViewPropertyPath("Active_var.Value", IsBlockActive);
						OnPropertyChanged("Active_var");
					}
					if (text.Equals("$PLOTVG"))
					{
						ResolveUpdateParameter("p_IsSystemGenerated", "1", localOnly: true);
					}
					else
					{
						ResolveUpdateParameter("p_IsSystemGenerated", "0", localOnly: true);
					}
				}
				base.OnUpdateData();
			}
		}

		[CompilerGenerated]
		private sealed class SelectedIdsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string currentId;

			private int initialThreadId;

			public MMSetup_VarGroup_ObjManager_ViewModel owner;

			private IList gridData;

			private IEnumerator<int> rowIndexes;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentId;
				}
			}

			[DebuggerHidden]
			public SelectedIdsEnumerator(int state)
			{
				this.state = state;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = state;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeRowIndexes();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{  bool completedNormally = false;
				try
				{
					int num = state;
					MMSetup_VarGroup_ObjManager_ViewModel mMSetup_VarGroup_ObjManager_ViewModel = owner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true; return false;
						}
						state = -3;
					}
					else
					{
						state = -1;
						gridData = mMSetup_VarGroup_ObjManager_ViewModel.grdChild_GridData as IList;
						if (gridData == null || mMSetup_VarGroup_ObjManager_ViewModel.SelectedRowIndexes == null)
						{
							goto IL_00d3;
						}
						rowIndexes = mMSetup_VarGroup_ObjManager_ViewModel.SelectedRowIndexes.GetEnumerator();
						state = -3;
					}
					while (rowIndexes.MoveNext())
					{
						int current = rowIndexes.Current;
						if (current >= 0 && current < gridData.Count)
						{
							grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = gridData[current] as grdChild_GridData_ItemTemplate;
							currentId = grdChild_GridData_ItemTemplate.GetId();
							state = 1;
							completedNormally = true; return true;
						}
					}
					DisposeRowIndexes();
					rowIndexes = null;
					goto IL_00d3;
					IL_00d3:
					completedNormally = true; return false;
				}
				finally
				{
					// Original fault handler runs only when MoveNext leaves by exception.
					if (!completedNormally) ((IDisposable)this).Dispose();

				}
			}







			private void DisposeRowIndexes()
			{
				state = -1;
				if (rowIndexes != null)
				{
					rowIndexes.Dispose();
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
				SelectedIdsEnumerator result;
				if (state == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					state = 0;
					result = this;
				}
				else
				{
					result = new SelectedIdsEnumerator(0)
					{
						owner = owner
					};
				}
				return result;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private ICommand _grid_RowDoubleClickCommand;

		private ICommand _cmdAdd_Command;

		public static CxvPropertyDeclaration cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "InsertChild"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdCopy_Command;

		public static CxvPropertyDeclaration cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					PropertyPath = "AllSelectedRecordsCount",
					Operator = CxvLogicalOperator.GreaterThan,
					Value = 0
				},
				new CxvLogicalTest
				{
					DataPath = "@main",
					Operator = CxvLogicalOperator.CanInvokeAction,
					Value = "CopyChildren"
				},
				new CxvLogicalTest
				{
					Operator = CxvLogicalOperator.Equal,
					PropertyPath = "CanDuplicate",
					Value = true
				}
			}
		});

		private ICommand _cmdPaste_Command;

		public static CxvPropertyDeclaration cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Equal,
			PropertyPath = "CanPaste",
			Value = true
		});

		private ICommand _cmdDelete_Command;

		private ICommand _cmdExport_Command;

		public static CxvPropertyDeclaration cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdDuplicate_Command;

		private Collection<string> _existingGroupIds;

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main",
				UseChildId = true,
				ProxyRow = false,
				Name = "y"
			}
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

		public ICommand grid_RowDoubleClickCommand
		{
			get
			{
				if (_grid_RowDoubleClickCommand == null)
				{
					_grid_RowDoubleClickCommand = new CxvDelegateCommand<object>(grid_RowDoubleClickCommandExecute);
				}
				return _grid_RowDoubleClickCommand;
			}
		}

		public ICommand cmdAdd_Command
		{
			get
			{
				if (_cmdAdd_Command == null)
				{
					_cmdAdd_Command = new CxvDelegateCommand<object>(cmdAdd_CommandExecute, this, cmdAddCanExecuteProperty.Name + ".Value");
				}
				return _cmdAdd_Command;
			}
		}

		public CxvLogicalPropertyData cmdAddCanExecute => GetValue(cmdAddCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEditCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEditCanExecute => GetValue(cmdEditCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdCopy_Command
		{
			get
			{
				if (_cmdCopy_Command == null)
				{
					_cmdCopy_Command = new CxvDelegateCommand<object>(cmdCopy_CommandExecute, this, cmdCopyCanExecuteProperty.Name + ".Value");
				}
				return _cmdCopy_Command;
			}
		}

		public CxvLogicalPropertyData cmdCopyCanExecute => GetValue(cmdCopyCanExecuteProperty) as CxvLogicalPropertyData;

		public bool CanDuplicate
		{
			get
			{
				if (GetSelectedIds() != null)
				{
					return true;
				}
				return false;
			}
		}

		public ICommand cmdPaste_Command
		{
			get
			{
				if (_cmdPaste_Command == null)
				{
					_cmdPaste_Command = new CxvDelegateCommand<object>(cmdPaste_CommandExecute, this, cmdPaste_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdPaste_Command;
			}
		}

		public bool CanPaste
		{
			get
			{
				if (!ClipboardWrapper.ContainsData("Aspen Plus Selection"))
				{
					return false;
				}
				if (ClipboardWrapper.ContainsData("Aspen Plus Selection Type"))
				{
					IDataObject dataObject = ClipboardWrapper.GetDataObject();
					if (dataObject != null && dataObject.GetData("Aspen Plus Selection Type", autoConvert: false) is MemoryStream stream)
					{
						string text = new StreamReader(stream).ReadToEnd();
						string path = ExpandDataPath("@main");
						try
						{
							return CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(path, "action_status", "CanPaste:" + text)).CanInvoke;
						}
						catch (Exception)
						{
						}
					}
				}
				return true;
			}
		}

		public CxvLogicalPropertyData cmdPaste_CommandCanExecute => GetValue(cmdPaste_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new RelayActionCommand<object>(cmdDelete_Command_Execute, cmdDelete_Command_CanExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public ICommand cmdExport_Command
		{
			get
			{
				if (_cmdExport_Command == null)
				{
					_cmdExport_Command = new CxvDelegateCommand<object>(cmdExport_CommandExecute, this, cmdExportCanExecuteProperty.Name + ".Value");
				}
				return _cmdExport_Command;
			}
		}

		public CxvLogicalPropertyData cmdExportCanExecute => GetValue(cmdExportCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdDuplicate_Command
		{
			get
			{
				if (_cmdDuplicate_Command == null)
				{
					_cmdDuplicate_Command = new RelayActionCommand<object>(cmdDuplicate_CommandExecute, cmdDuplicateCanExecute);
				}
				return _cmdDuplicate_Command;
			}
		}

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		public int AllSelectedRecordsCount
		{
			get
			{
				return _allSelectedRecordsCount;
			}
			set
			{
				if (value != _allSelectedRecordsCount)
				{
					_allSelectedRecordsCount = value;
					OnAllSelectedRecordsCountChanged();
				}
				OnPropertyChanged("CanDuplicate");
			}
		}

		public ObservableCollection<int> SelectedRowIndexes
		{
			get
			{
				return _SelectedRowIndexes;
			}
			set
			{
				_SelectedRowIndexes = value;
				if (cmdDelete_Command != null)
				{
					(cmdDelete_Command as DelegateCommand<object>).RaiseCanExecuteChanged();
				}
			}
		}

		public event EventHandler CanPasteChanged;

		public event EventHandler AllSelectedRecordsCountChanged;

		private void grid_RowDoubleClickCommandExecute(object parameter)
		{
			IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
			if (enumerator.MoveNext())
			{
				string path = ".!" + enumerator.Current;
				GoToNode(path);
			}
		}

		private void cmdAdd_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			string newChildId = null;
			bool? flag = ShowAddChildDialog(parentPath, out newChildId);
			if (flag.HasValue && flag.Value)
			{
				AddChildren(ExpandDataPath("@main"), new Collection<string> { newChildId });
			}
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount == 1)
			{
				IEnumerator<string> enumerator = GetSelectedIds().GetEnumerator();
				if (enumerator.MoveNext())
				{
					string path = ".!" + enumerator.Current;
					GoToNode(path);
				}
			}
		}

		private void cmdCopy_CommandExecute(object parameter)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			CopyChildren(parentPath, collection);
			OnCanPasteChanged();
		}

		private void OnCanPasteChanged()
		{
			if (this.CanPasteChanged != null)
			{
				this.CanPasteChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("CanPaste");
		}

		private void cmdPaste_CommandExecute(object parameter)
		{
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DoPaste(parentPath);
			base.ResolvedCxsProvider.UpdateDataCache();
		}

		private void cmdDelete_Command_Execute(object args)
		{
			Collection<string> collection = new Collection<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				collection.Add(selectedId);
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			DeleteChildren(parentPath, collection);
		}

		private bool cmdDelete_Command_CanExecute(object args)
		{
			IEnumerable<string> enumerable = null;
			enumerable = ((args == null) ? GetSelectedIds() : new List<string> { args as string });
			if (enumerable != null && enumerable.Count() > 0)
			{
				string text = ExpandDataPath("@main");
				try
				{
					if (CxsConverter.ValueToActionStatusDetails(base.ResolvedCxsProvider.BatchGet(text, "action_status", "DeleteChild")).CanInvoke)
					{
						return true;
					}
					foreach (string item in enumerable)
					{
						if (!(CxsConverter.ValueToBoolean(base.ResolvedCxsProvider.BatchGet(ExpandDataPath(text + "." + item), "can_delete", null)) ?? false))
						{
							return false;
						}
					}
					return true;
				}
				catch (Exception)
				{
					return false;
				}
			}
			return true;
		}

		private void cmdExport_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
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

		public bool cmdDuplicateCanExecute(object args)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return false;
			}
			if (GetSelectedIds().ElementAt(0).Equals("$PLOTVG", StringComparison.InvariantCultureIgnoreCase))
			{
				return false;
			}
			return true;
		}

		private void cmdDuplicate_CommandExecute(object parameter)
		{
			if (!(grdChild_GridData is IList list))
			{
				return;
			}
			grdChild_GridData_ItemTemplate grdChild_GridData_ItemTemplate = list[0] as grdChild_GridData_ItemTemplate;
			ObservableCollection<int> selection = new ObservableCollection<int>(new int[1]);
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1 && list.Count > SelectedRowIndexes[0])
			{
				grdChild_GridData_ItemTemplate = list[SelectedRowIndexes[0]] as grdChild_GridData_ItemTemplate;
				selection = SelectedRowIndexes;
			}
			if (grdChild_GridData_ItemTemplate != null)
			{
				string mainPath = CxsConverter.ValueToString(ResolveParameter("main", null));
				this.CopyObjectRows(mainPath, "VARGROUP", selection);
				Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
				string text = null;
				int num = 0;
				do
				{
					text = CreateNewVariableName(grdChild_GridData_ItemTemplate.GetId(), $"DP{++num}");
				}
				while (collection.Contains(text));
				AddChildren(ExpandDataPath("@main"), new Collection<string> { text });
				string text2 = $"@main.{text}.Input";
				string description = grdChild_GridData_ItemTemplate.GetDescription();
				ExpandDataPathAndSet(text2 + ".DESCRIPTION", "value", description);
				this.PasteObjectRows(mainPath, "VARGROUP");
				base.ResolvedCxsProvider.UpdateDataCache();
			}
		}

		private string CreateNewVariableName(string name, string suffix)
		{
			if (name.Length < 8 - suffix.Length)
			{
				return name + suffix;
			}
			return name.Substring(0, 8 - suffix.Length) + suffix;
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				_existingGroupIds = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main", "child_ids"));
			}
			base.OnUpdateData();
		}

		private void OnAllSelectedRecordsCountChanged()
		{
			if (this.AllSelectedRecordsCountChanged != null)
			{
				this.AllSelectedRecordsCountChanged(this, EventArgs.Empty);
			}
			OnPropertyChanged("AllSelectedRecordsCount");
		}

		[IteratorStateMachine(typeof(SelectedIdsEnumerator))]
		private IEnumerable<string> GetSelectedIds()
		{
			return new SelectedIdsEnumerator(-2)
			{
				owner = this
			};
		}
	}
	[ProgId("MMSetup.MMSetup_VarGroup_ObjManager")]
	public class MMSetup_VarGroup_ObjManager : MMTabPage, IComponentConnector
	{
		internal MMFlatButton cmdNew;

		internal MMFlatButton cmdEdit;

		internal MMFlatButton cmdCopy;

		internal MMFlatButton cmdPaste;

		internal MMFlatButton cmdDuplicate;

		internal MMFlatButton cmdExport;

		internal MMScrollAreaMS grdChild;

		private bool _contentLoaded;

		public MMSetup_VarGroup_ObjManager()
		{
			base.ViewModelType = typeof(MMSetup_VarGroup_ObjManager_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_vargroup_objmanager.xaml", UriKind.Relative);
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
				cmdNew = (MMFlatButton)target;
				break;
			case 2:
				cmdEdit = (MMFlatButton)target;
				break;
			case 3:
				cmdCopy = (MMFlatButton)target;
				break;
			case 4:
				cmdPaste = (MMFlatButton)target;
				break;
			case 5:
				cmdDuplicate = (MMFlatButton)target;
				break;
			case 6:
				cmdExport = (MMFlatButton)target;
				break;
			case 7:
				grdChild = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_ViewDefinevariables_List_ViewModel : MMTabPageViewModel
	{
		public class grdViewvariable_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtVarName_var1_Property = CxvPropertyDeclaration.Register("txtVarName_var1", typeof(grdViewvariable_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FVN_VARTYPE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase,
				IsReadOnly = true
			});

			public object txtVarName_var1 => GetValue(txtVarName_var1_Property);

			public object txtVarDefn_VarDefn => new CxvManualVariableData
			{
				IsReadOnly = true,
				Value = VarDefn
			};

			public string VarDefn
			{
				get
				{
					string result = "";
					string text = "";
					string text2 = CxsConverter.ValueToString(ResolveParameter("y"));
					string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + text2, "value"));
					if (text3 == null)
					{
						return result;
					}
					foreach (VarType varType in VarTypes)
					{
						if (text3 == varType.UCase)
						{
							text = varType.MCase;
							break;
						}
					}
					foreach (PromptType prompt in Prompts)
					{
						string text4 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + prompt.Variable + "." + text2, "value"));
						string text5 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + prompt.Variable + "." + text2, "can_enter"));
						if (text5 == null)
						{
							text5 = "0";
						}
						if (!string.IsNullOrEmpty(text4) && (!prompt.HideWhenLocked || text5 == "1"))
						{
							if (prompt.ConvertToMixedCase)
							{
								text4 = StrConvMixCase(text4);
							}
							text = text + " " + prompt.Label + text4;
						}
					}
					return text;
				}
			}
		}

		public struct PromptType
		{
			public string Text;

			public string Label;

			public string Variable;

			public bool HideWhenLocked;

			public bool ConvertToMixedCase;
		}

		public struct VarType
		{
			public string UCase;

			public string MCase;

			public int[] PromptIndex;
		}

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration grdViewvariable_GridData_Property = CxvPropertyDeclaration.Register("grdViewvariable_GridData", typeof(MMSetup_ViewDefinevariables_List_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdViewvariable_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FVN_VARTYPE",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			},
			AllowCollectionChange = false
		});

		public static List<VarType> VarTypes;

		public static List<PromptType> Prompts;

		public ICommand cmdClose_Command
		{
			get
			{
				if (_cmdClose_Command == null)
				{
					_cmdClose_Command = new CxvDelegateCommand<object>(cmdClose_CommandExecute);
				}
				return _cmdClose_Command;
			}
		}

		public object grdViewvariable_GridData => GetValue(grdViewvariable_GridData_Property);

		public static string StrConvMixCase(string InpVal)
		{
			string text = "";
			try
			{
				int result = 0;
				if (int.TryParse(InpVal, out result))
				{
					text = InpVal;
					return text;
				}
				string[] array = InpVal.Split('-');
				for (int i = 0; i < array.Length; i++)
				{
					if (array[i].Length > 1)
					{
						array[i] = array[i].Substring(0, 1).ToUpper() + array[i].Substring(1).ToLower();
					}
					else if (array[i].Length > 0)
					{
						array[i] = array[i].ToUpper();
					}
				}
				for (int j = 0; j < array.Length - 1; j++)
				{
					text = text + array[j] + "-";
				}
				text += array[array.Length - 1];
			}
			catch
			{
			}
			return text;
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				VarTypes = VAVarTypeInit(CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "option_list")));
				Prompts = VAPromptInit();
			}
		}

		public static List<PromptType> VAPromptInit()
		{
			if (Prompts == null)
			{
				Prompts = new List<PromptType>();
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Block,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Block1,
					Variable = "FVN_BLOCK"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Stream,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Stream1,
					Variable = "FVN_STREAM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Substream,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Substream1,
					Variable = "FVN_SUBS"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Component,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Component1,
					Variable = "FVN_COMPONEN"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ParaNo,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ParaNo1,
					Variable = "FVN_PARAMNO"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Attribute,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Attribute1,
					Variable = "FVN_ATTRIB"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Variable1,
					Variable = "FVN_VARIABLE"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Sentence1,
					Variable = "FVN_SENTENCE"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID1,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID11,
					Variable = "FVN_ID1"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID2,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID21,
					Variable = "FVN_ID2"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID3,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__ID31,
					Variable = "FVN_ID3"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Element,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Element1,
					Variable = "FVN_ELEM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PropSet,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PropSet1,
					Variable = "FVN_PROPSET"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PhysicalType,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__PhysicalType1,
					Variable = "FVN_PHYS_QTY",
					HideWhenLocked = true,
					ConvertToMixedCase = true
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__Units1,
					Variable = "FVN_UOM"
				});
				Prompts.Add(new PromptType
				{
					Text = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__InitialValue,
					Label = AspenTech.AspenPlus.Localization.Properties.Resources.MMCalcul_Input_Define_ViewModel__InitialValue1,
					Variable = "FVN_INIT_VAL"
				});
			}
			return Prompts;
		}

		public static List<VarType> VAVarTypeInit(Collection<string> oplist)
		{
			if (VarTypes == null)
			{
				VarTypes = new List<VarType>();
				VarTypes.Add(new VarType
				{
					MCase = "Balance-Var",
					UCase = "BALANCE-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Cor-El",
					UCase = "BI-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Cor-Vec",
					UCase = "BI-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Bi-Param",
					UCase = "BI-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Block-Var",
					UCase = "BLOCK-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Block-Vec",
					UCase = "BLOCK-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Byprod-Var",
					UCase = "BYPROD-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Capital-Var",
					UCase = "CAPITAL-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Cblock-Var",
					UCase = "CBLOCK-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Chem-Var",
					UCase = "CHEM-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Compattr-Var",
					UCase = "COMPATTR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Compattr-Vec",
					UCase = "COMPATTR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Config-Var",
					UCase = "CONFIG-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Cont-Var",
					UCase = "CONT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Costing-Utility-Var",
					UCase = "UTILITY-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Param",
					UCase = "GROUP-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Bi-Param",
					UCase = "GROUP-BI-PAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Group-Bi-Cor-El",
					UCase = "GR-BI-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-Duty",
					UCase = "HEAT-DUTY"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-Temp",
					UCase = "HEAT-TEMP"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Heat-T-End",
					UCase = "HEAT-TEND"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Labor-Var",
					UCase = "LABOR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Local-Param",
					UCase = "LOCAL-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mass-Flow",
					UCase = "MASS-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mass-Frac",
					UCase = "MASS-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Meas-Var",
					UCase = "MEAS-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mole-Flow",
					UCase = "MOLE-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Mole-Frac",
					UCase = "MOLE-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Cor-El",
					UCase = "NC-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Cor-Vec",
					UCase = "NC-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "NC-Param",
					UCase = "NC-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Oper-Cost-Var",
					UCase = "OPER-COST-VA"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Parameter",
					UCase = "PARAMETER"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Power-Power",
					UCase = "POWER-POWER"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Presr-Var",
					UCase = "PRESR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Product-Var",
					UCase = "PRODUCT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Profit-Var",
					UCase = "PROFIT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "PSD-Var",
					UCase = "SUBSATTR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "PSD-Vec",
					UCase = "SUBSATTR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Q-Vec",
					UCase = "QVEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Raw-Mat-Var",
					UCase = "RAW-MAT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "React-Var",
					UCase = "REACT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Sensor-Var",
					UCase = "SENSOR-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Startup-Var",
					UCase = "STARTUP-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "StdVol-Flow",
					UCase = "STDVOL-FLOW"
				});
				VarTypes.Add(new VarType
				{
					MCase = "StdVol-Frac",
					UCase = "STDVOL-FRAC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Cost",
					UCase = "STREAM-COST"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Prop",
					UCase = "STREAM-PROP"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Var",
					UCase = "STREAM-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Stream-Vec",
					UCase = "STREAM-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Substrm-Vec",
					UCase = "SUBSTRM-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "T-Vec",
					UCase = "TVEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unary-Cor-El",
					UCase = "UNARY-COR-EL"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unary-Param",
					UCase = "UNARY-PARAM"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Unit-Var",
					UCase = "UNIT-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Utility-Var",
					UCase = "UTILITY"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Un-Cor-Vec",
					UCase = "UN-COR-VEC"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Waste-Var",
					UCase = "WASTE-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Work-Cap-Var",
					UCase = "WORK-CAP-VAR"
				});
				VarTypes.Add(new VarType
				{
					MCase = "Work-Power",
					UCase = "WORK-POWER"
				});
				List<VarType> list = new List<VarType>();
				if (oplist != null && oplist.Count > 0)
				{
					string[] array = new string[oplist.Count];
					bool[] array2 = new bool[oplist.Count];
					for (int i = 0; i < oplist.Count; i++)
					{
						array[i] = oplist[i];
						array2[i] = false;
					}
					foreach (VarType varType in VarTypes)
					{
						for (int j = 0; j < array.Length; j++)
						{
							if (array[j] == varType.UCase)
							{
								list.Add(varType);
								array2[j] = true;
								break;
							}
						}
					}
					for (int k = 0; k < array2.Length; k++)
					{
						if (!array2[k])
						{
							list.Add(new VarType
							{
								UCase = array[k],
								MCase = StrConvMixCase(array[k])
							});
						}
					}
					VarTypes = list;
				}
			}
			return VarTypes;
		}

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
			UpdateAll();
		}
	}
	[ProgId("MMSetup.MMSetup_ViewDefinevariables_List")]
	public class MMSetup_ViewDefinevariables_List : MMTabPage, IComponentConnector
	{
		internal MMCmdButton cmdClose;

		internal MMScrollArea grdViewvariable;

		private bool _contentLoaded;

		public MMSetup_ViewDefinevariables_List()
		{
			base.ViewModelType = typeof(MMSetup_ViewDefinevariables_List_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/mmsetup_viewdefinevariables_list.xaml", UriKind.Relative);
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
				cmdClose = (MMCmdButton)target;
				break;
			case 2:
				grdViewvariable = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class StreamGroupPriorityDlg : Window, IComponentConnector
	{
		private IUnityContainer _unityContainer;

		private MMViewModel _MMViewModel;

		private CxsCase _case;

		private const string MAINPATH = "Top.appModelV8.Setup.Stream-Groups";

		private static readonly List<DataColumn> _columns = new List<DataColumn>
		{
			new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Priority)
			{
				Width = 80.0
			},
			new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Name)
			{
				Width = 100.0
			},
			new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Format)
			{
				Width = 200.0,
				IsReadOnly = true
			}
		};

		private static Color[] _definedColors = new Color[16]
		{
			Colors.Black,
			Colors.Navy,
			Colors.Green,
			Colors.Teal,
			Colors.Brown,
			Colors.Purple,
			Colors.DarkOliveGreen,
			Colors.Gray,
			Colors.DarkGray,
			Colors.Blue,
			Colors.LightGreen,
			Colors.SkyBlue,
			Colors.Red,
			Colors.Fuchsia,
			Colors.Yellow,
			Colors.LightGray
		};

		private List<StreamGroupItem> _sortedStreamGroups;

		private ICommand _moveUpCommand;

		private ICommand _moveDownCommand;

		internal GridControl gridGroups;

		internal Button btnOK;

		internal Button btnCancel;

		private bool _contentLoaded;

		public ICommand MoveUpCommand
		{
			get
			{
				if (_moveUpCommand == null)
				{
					_moveUpCommand = new RelayActionCommand<object>(MoveUpCommandExecuted, MoveUpCommandCanExecute);
				}
				return _moveUpCommand;
			}
		}

		public ICommand MoveDownCommand
		{
			get
			{
				if (_moveDownCommand == null)
				{
					_moveDownCommand = new RelayActionCommand<object>(MoveDownCommandExecuted, MoveDownCommandCanExecute);
				}
				return _moveDownCommand;
			}
		}

		public StreamGroupPriorityDlg(IUnityContainer container, MMViewModel vm)
		{
			InitializeComponent();
			if (container == null)
			{
				throw new ArgumentNullException("container");
			}
			_unityContainer = container;
			_MMViewModel = vm;
			_case = _unityContainer.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
			base.DataContext = this;
			base.Loaded += StreamGroupPriorityDlg_Loaded;
		}

		private void StreamGroupPriorityDlg_Loaded(object sender, RoutedEventArgs e)
		{
			InitializeStreamGroupsDataSource();
			gridGroups.DataSource = new DataTable(_columns);
			RefreshStreamGroupGrid();
		}

		private void InitializeStreamGroupsDataSource()
		{
			Collection<string> collection = CxsConverter.ValueToStringCollection(_case.BatchGet("Top.appModelV8.Setup.Stream-Groups", "child_ids"));
			List<StreamGroupItem> list = new List<StreamGroupItem>();
			foreach (string item in collection)
			{
				int? priority = CxsConverter.ValueToInt32(_case.BatchGet(string.Format("{0}.{1}.Input.PRIORITY", "Top.appModelV8.Setup.Stream-Groups", item), "value"));
				string format = CxsConverter.ValueToString(_case.BatchGet(string.Format("{0}.{1}.Input.LINESTYLE", "Top.appModelV8.Setup.Stream-Groups", item), "value"));
				list.Add(new StreamGroupItem
				{
					Name = item,
					Priority = priority,
					Format = format
				});
			}
			_sortedStreamGroups = new List<StreamGroupItem>(list.OrderBy((StreamGroupItem p) => p.Priority));
		}

		private void RefreshStreamGroupGrid()
		{
			if (_sortedStreamGroups == null)
			{
				InitializeStreamGroupsDataSource();
			}
			List<DataRow> list = new List<DataRow>();
			foreach (StreamGroupItem sortedStreamGroup in _sortedStreamGroups)
			{
				DataRow dataRow = new DataRow(gridGroups.DataSource.Columns);
				dataRow.Tag = sortedStreamGroup;
				dataRow[0] = new DataCellInteger(sortedStreamGroup.Priority)
				{
					IsReadOnly = true
				};
				dataRow[1] = new DataCellText(sortedStreamGroup.Name)
				{
					IsReadOnly = true
				};
				Color color = Colors.Black;
				int lineStyle = 0;
				double num = 1.0;
				if (!string.IsNullOrEmpty(sortedStreamGroup.Format))
				{
					string[] array = sortedStreamGroup.Format.Split(';');
					if (array.Length >= 3)
					{
						int num2 = 0;
						int? num3 = CxsConverter.ValueToInt32(array[0]);
						if (num3.HasValue)
						{
							num2 = num3.Value;
						}
						if (num2 < 0 || num2 > _definedColors.Length - 1)
						{
							num2 = 0;
						}
						color = _definedColors[num2];
						double? num4 = CxsConverter.ValueToDouble(array[1]);
						if (num4.HasValue)
						{
							num = num4.Value;
						}
						int? num5 = CxsConverter.ValueToInt32(array[2]);
						if (num5.HasValue)
						{
							lineStyle = num5.Value;
						}
					}
				}
				DataTemplate dataTemplate = new DataTemplate();
				FrameworkElementFactory frameworkElementFactory = new FrameworkElementFactory(typeof(Line));
				frameworkElementFactory.SetValue(Line.X1Property, 5.0);
				frameworkElementFactory.SetValue(Line.X2Property, 95.0);
				frameworkElementFactory.SetValue(Line.Y1Property, 0.0);
				frameworkElementFactory.SetValue(Line.Y2Property, 0.0);
				frameworkElementFactory.SetValue(Shape.StretchProperty, Stretch.Fill);
				frameworkElementFactory.SetValue(Shape.StrokeProperty, new SolidColorBrush(color));
				frameworkElementFactory.SetValue(Shape.StrokeDashArrayProperty, LineStyleToStrokeDashArray(lineStyle));
				frameworkElementFactory.SetValue(Shape.StrokeThicknessProperty, num);
				frameworkElementFactory.SetValue(FrameworkElement.HorizontalAlignmentProperty, HorizontalAlignment.Stretch);
				frameworkElementFactory.SetValue(FrameworkElement.VerticalAlignmentProperty, VerticalAlignment.Center);
				frameworkElementFactory.SetValue(FrameworkElement.MarginProperty, new Thickness(5.0));
				dataTemplate.VisualTree = frameworkElementFactory;
				dataRow[2] = new DataCellText
				{
					Template = dataTemplate
				};
				list.Add(dataRow);
			}
			gridGroups.DataSource.UpdateRows(list);
		}

		private DoubleCollection LineStyleToStrokeDashArray(int lineStyle)
		{
			return lineStyle switch
			{
				0 => null, 
				1 => new DoubleCollection { 3.0, 1.0 }, 
				2 => new DoubleCollection { 1.0, 1.0 }, 
				3 => new DoubleCollection { 4.0, 1.0, 1.0, 1.0 }, 
				4 => new DoubleCollection { 4.0, 1.0, 1.0, 1.0, 1.0, 1.0 }, 
				_ => null, 
			};
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			foreach (StreamGroupItem sortedStreamGroup in _sortedStreamGroups)
			{
				_case.BatchSet(string.Format("{0}.{1}.Input.PRIORITY", "Top.appModelV8.Setup.Stream-Groups", sortedStreamGroup.Name), "value", sortedStreamGroup.Priority.HasValue ? sortedStreamGroup.Priority.Value : (-1));
			}
			if (_MMViewModel != null)
			{
				_MMViewModel.NotifyStreamGroupsPriorityReorderChanged();
			}
			base.DialogResult = true;
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void gridGroups_SelectionChanged(object sender, RoutedEventArgs e)
		{
		}

		private bool MoveUpCommandCanExecute(object arg)
		{
			if (gridGroups.SelectedRows.Any())
			{
				StreamGroupItem item = gridGroups.SelectedRows.First().Tag as StreamGroupItem;
				if (_sortedStreamGroups.IndexOf(item) > 0)
				{
					return true;
				}
			}
			return false;
		}

		private void MoveUpCommandExecuted(object obj)
		{
			StreamGroupItem streamGroupItem = gridGroups.SelectedRows.First().Tag as StreamGroupItem;
			int num = _sortedStreamGroups.IndexOf(streamGroupItem);
			StreamGroupItem streamGroupItem2 = _sortedStreamGroups[num - 1];
			string name = streamGroupItem2.Name;
			string format = streamGroupItem2.Format;
			streamGroupItem2.Name = streamGroupItem.Name;
			streamGroupItem2.Format = streamGroupItem.Format;
			streamGroupItem.Name = name;
			streamGroupItem.Format = format;
			RefreshStreamGroupGrid();
			DataRow row = gridGroups.DataSource.Rows.ElementAt(num - 1);
			gridGroups.DeselectAll();
			gridGroups.SelectRow(row);
			gridGroups.CurrentCell = new DataCellInfo(row, gridGroups.DataSource.Columns.First());
		}

		private bool MoveDownCommandCanExecute(object arg)
		{
			if (gridGroups.SelectedRows.Any())
			{
				StreamGroupItem item = gridGroups.SelectedRows.First().Tag as StreamGroupItem;
				int num = _sortedStreamGroups.IndexOf(item);
				if (num >= 0 && num < _sortedStreamGroups.Count - 1)
				{
					return true;
				}
			}
			return false;
		}

		private void MoveDownCommandExecuted(object obj)
		{
			StreamGroupItem streamGroupItem = gridGroups.SelectedRows.First().Tag as StreamGroupItem;
			int num = _sortedStreamGroups.IndexOf(streamGroupItem);
			StreamGroupItem streamGroupItem2 = _sortedStreamGroups[num + 1];
			string name = streamGroupItem2.Name;
			string format = streamGroupItem2.Format;
			streamGroupItem2.Name = streamGroupItem.Name;
			streamGroupItem2.Format = streamGroupItem.Format;
			streamGroupItem.Name = name;
			streamGroupItem.Format = format;
			RefreshStreamGroupGrid();
			DataRow row = gridGroups.DataSource.Rows.ElementAt(num + 1);
			gridGroups.DeselectAll();
			gridGroups.SelectRow(row);
			gridGroups.CurrentCell = new DataCellInfo(row, gridGroups.DataSource.Columns.First());
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Setup;component/streamgroupprioritydlg.xaml", UriKind.Relative);
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
				gridGroups = (GridControl)target;
				gridGroups.SelectionChanged += gridGroups_SelectionChanged;
				break;
			case 2:
				btnOK = (Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 3:
				btnCancel = (Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	internal class StreamGroupItem
	{
		public string Name { get; set; }

		public int? Priority { get; set; }

		public string Format { get; set; }
	}
}
/* Compile with /link:Interop.Happ.dll. The compiler embeds this original COM interface and its 51-slot vtable gap.	namespace AspenTech.AspenPlus.Happ
{
	[ComImport]
	[CompilerGenerated]
	[Guid("8E567522-F9BA-11CF-90B2-0000C0A810C4")]
	[TypeIdentifier]
	public interface IHNode
	{
		void _VtblGap1_51();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1610743859)]
		void Export([In][MarshalAs(UnmanagedType.BStr)] string filename = "");
	}
} */

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000001 <>f__AnonymousType0`2.get_index
// {
// 	return <index>i__Field;
// }

// 0x06000002 <>f__AnonymousType0`2.get_itemTemplate
// {
// 	return <itemTemplate>i__Field;
// }

// 0x06000003 <>f__AnonymousType0`2..ctor
// using System.Diagnostics;
//
// [DebuggerHidden]
// public <>f__AnonymousType0(<index>j__TPar index, <itemTemplate>j__TPar itemTemplate)
// {
// 	<index>i__Field = index;
// 	<itemTemplate>i__Field = itemTemplate;
// }

// 0x06000004 <>f__AnonymousType0`2.Equals
// using System.Collections.Generic;
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override bool Equals(object value)
// {
// 	global::<>f__AnonymousType0<<index>j__TPar, <itemTemplate>j__TPar> anon = value as global::<>f__AnonymousType0<<index>j__TPar, <itemTemplate>j__TPar>;
// 	if (this != anon)
// 	{
// 		if (anon != null && EqualityComparer<<index>j__TPar>.Default.Equals(<index>i__Field, anon.<index>i__Field))
// 		{
// 			return EqualityComparer<<itemTemplate>j__TPar>.Default.Equals(<itemTemplate>i__Field, anon.<itemTemplate>i__Field);
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
// 	return (-1968418159 * -1521134295 + EqualityComparer<<index>j__TPar>.Default.GetHashCode(<index>i__Field)) * -1521134295 + EqualityComparer<<itemTemplate>j__TPar>.Default.GetHashCode(<itemTemplate>i__Field);
// }

// 0x06000006 <>f__AnonymousType0`2.ToString
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override string ToString()
// {
// 	object[] array = new object[2];
// 	<index>j__TPar val = <index>i__Field;
// 	array[0] = ((val != null) ? val.ToString() : null);
// 	<itemTemplate>j__TPar val2 = <itemTemplate>i__Field;
// 	array[1] = ((val2 != null) ? val2.ToString() : null);
// 	return string.Format(null, "{{ index = {0}, itemTemplate = {1} }}", array);
// }

// 0x0600000c XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x0600000d AspenTech.AspenPlus.MMForms.Setup.MMSetup_EmissionOptions_ViewModel..ctor
// public MMSetup_EmissionOptions_ViewModel()
// {
// }

// 0x06000017 AspenTech.AspenPlus.MMForms.Setup.MMSetup_EmissionOptions_EmiOpt_ViewModel..ctor
// public MMSetup_EmissionOptions_EmiOpt_ViewModel()
// {
// }

// 0x06000018 AspenTech.AspenPlus.MMForms.Setup.MMSetup_EmissionOptions_EmiOpt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_EmissionOptions_EmiOpt_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_EmissionOptions_EmiOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.CARBON_FEE",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Sim-Options.CC Nodes.MASSCK_INP"
// 		}
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMSetup_EmissionOptions_EmiOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Sim-Options.Input.GHG_STANDARD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "IPCC SAR (1995)",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_SAR__1995_",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_96,
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "IPCC-1995"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "IPCC AR4 (2007)",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR4__2007_",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_97,
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "IPCC-2007"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "USEPA (2009)",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_USEPA__2009_",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_98,
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "USEPA-2009"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "IPCC AR5 (2014)",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR5__2016_",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_113,
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "IPCC-2016"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "IPCC AR6 (2021)",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_IPCC_AR6__2021_",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_114,
// 				Value = "MMComboBox2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "IPCC-2021"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "None",
// 				DisplayResourceKey = "MMSetup_Simopt_Calcul_ViewModel__CxvMultiMapOption_Display_None",
// 				Prompt = PromptResources.FILEPNUM_77_Prompt_99,
// 				Value = "MMComboBox2_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "NONE"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Sim-Options.CC Nodes.MASSCK_INP"
// 		}
// 	});
// 	MMchkbGreenhEmissions_var1_Property = CxvPropertyDeclaration.Register("MMchkbGreenhEmissions_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.EMISSION_CAL",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// }

// 0x0600001c AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ViewModel..ctor
// public MMSetup_StreamGroup_ViewModel()
// {
// }

// 0x0600001d AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_StreamGroup_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_StreamGroup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_StreamGroup_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" }
// 	});
// }

// 0x06000030 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel.add_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000031 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel.remove_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000047 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel.add_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000048 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel.remove_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x0600004d AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel..ctor
// public MMSetup_StreamGroup_ObjManager_ViewModel()
// {
// }

// 0x0600004e AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_StreamGroup_ObjManager_ViewModel()
// {
// 	cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "InsertChild"
// 	});
// 	cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "CopyChildren"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Operator = CxvLogicalOperator.Equal,
// 				PropertyPath = "CanDuplicate",
// 				Value = true
// 			}
// 		}
// 	});
// 	cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Equal,
// 		PropertyPath = "CanPaste",
// 		Value = true
// 	});
// 	cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdDuplicateCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDuplicateCanExecute", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				DataAttribute = "child_count",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.Equal,
// 				Value = 1
// 			},
// 			new CxvLogicalTest
// 			{
// 				Operator = CxvLogicalOperator.Equal,
// 				PropertyPath = "CanDuplicate",
// 				Value = true
// 			}
// 		},
// 		Operator = CxvLogicalOperator.And
// 	});
// 	BuiltInGroups = new string[7] { "All", "Feeds", "Initial", "Products", "Tears", "Boundary", "Charge" };
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_StreamGroup_ObjManager_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main",
// 			UseChildId = true,
// 			ProxyRow = false,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000097 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_Selection_ViewModel..ctor
// using System.Collections.Generic;
// using System.Collections.ObjectModel;
// using System.Windows.Media;
// using AspenTech.AspenPlus.Localization;
//
// public MMSetup_StreamGroup_Selection_ViewModel()
// {
// 	_valueLabel = ApwDlgRes.StreamGroupsDlg_Value2;
// 	_containsOptions = new Collection<string> { ApwDlgRes.StreamGroupsDlg_ConditionComboItem_Contains };
// 	_conditionalStreamsList = new ObservableCollection<string>();
// 	_allTemplateNames = new ObservableCollection<string>();
// 	_lineWeight = 1.0;
// 	_lineColor = Colors.Black;
// 	_selectedHierarchy = _plantItemContent;
// 	_allSectionNames = new List<string>();
// 	base..ctor();
// }

// 0x06000098 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_Selection_ViewModel..cctor
// using System.Windows.Media;
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_StreamGroup_Selection_ViewModel()
// {
// 	_plantItemContent = ApwDlgRes.StreamGroupDlg_Plant;
// 	_allSectionItemContent = ApwDlgRes.StreamGroupDlg_AllSection;
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.STREAM_LIST"
// 	});
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main",
// 		IsReadOnly = true,
// 		Converter = typeof(BuiltinGroupResourceConverter)
// 	});
// 	SummaryTemplate_var1_Property = CxvPropertyDeclaration.Register("SummaryTemplate_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SGTEMPLATE"
// 	});
// 	txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DESCRIPTION"
// 	});
// 	SelectedGroupVisible_Property = CxvPropertyDeclaration.Register("SelectedGroupVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.SELECTION",
// 		Value = "SELECTED",
// 		Operator = CxvLogicalOperator.Equal
// 	});
// 	ConditionalGroupVisible_Property = CxvPropertyDeclaration.Register("ConditionalGroupVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.SELECTION",
// 		Value = "CONDITIONAL",
// 		Operator = CxvLogicalOperator.Equal
// 	});
// 	BuiltInListVisible_Property = CxvPropertyDeclaration.Register("BuiltInListVisible", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.SELECTION",
// 		DataAttribute = "can_enter",
// 		Value = 0,
// 		Operator = CxvLogicalOperator.Equal
// 	});
// 	SelectionVar_MultiMap_Property = CxvPropertyDeclaration.Register("SelectionVar_MultiMap", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Input.SELECTION",
// 			DataAttribute = "can_enter"
// 		},
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "SelectionVar",
// 				DataPath = "@main.Input.SELECTION"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Selected streams",
// 				Value = "SelectionVar_MultiMapOption_1",
// 				Prompt = PromptResources.FILEPNUM_92_Prompt_4,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "SelectionVar",
// 						Value = "SELECTED"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Conditional streams",
// 				Value = "SelectionVar_MultiMapOption_2",
// 				Prompt = PromptResources.FILEPNUM_92_Prompt_16,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "SelectionVar",
// 						Value = "CONDITIONAL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	Sections_var_Property = CxvPropertyDeclaration.Register("Sections_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SECTION",
// 		AllowNew = false
// 	});
// 	Scope_var_Property = CxvPropertyDeclaration.Register("Scope_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SCOPE",
// 		AllowNew = false
// 	});
// 	Condition_var_Property = CxvPropertyDeclaration.Register("Condition_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "Condition_var",
// 				DataPath = "@main.Input.CONDITION"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "NAME",
// 				DisplayResourceKey = "setup_stream_groups_sg_1_condition_name",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Condition_var",
// 						Value = "NAME"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PROPERTY",
// 				DisplayResourceKey = "setup_stream_groups_sg_1_condition_property",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Condition_var",
// 						Value = "PROPERTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	PropSet_var_Property = CxvPropertyDeclaration.Register("PropSet_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PROP_SET",
// 		AllowNew = false,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "Condition_var.Value",
// 			Value = "PROPERTY",
// 			Operator = CxvLogicalOperator.Equal
// 		}
// 	});
// 	ContainText_var_Property = CxvPropertyDeclaration.Register("ContainText_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CONTAIN_TEXT",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "Condition_var.Value",
// 			Value = "NAME",
// 			Operator = CxvLogicalOperator.Equal
// 		}
// 	});
// 	Operator_MultiMap_Property = CxvPropertyDeclaration.Register("Operator_MultiMap", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "Operator_var1",
// 				DataPath = "@main.Input.OPERATOR"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Greater than",
// 				DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Greater_than",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Operator_var1",
// 						Value = "Greater than"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = ">=",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Operator_var1",
// 						Value = ">="
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Less than",
// 				DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Less_than",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Operator_var1",
// 						Value = "Less than"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "<=",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Operator_var1",
// 						Value = "<="
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Between",
// 				DisplayResourceKey = "MMSetup_StreamGroup_Selection_Operator_Between",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Operator_var1",
// 						Value = "BETWEEN"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "Condition_var.Value",
// 			Value = "PROPERTY",
// 			Operator = CxvLogicalOperator.Equal
// 		}
// 	});
// 	Value1_var_Property = CxvPropertyDeclaration.Register("Value1_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUE1",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "Condition_var.Value",
// 			Value = "PROPERTY",
// 			Operator = CxvLogicalOperator.Equal
// 		}
// 	});
// 	Value2_var_Property = CxvPropertyDeclaration.Register("Value2_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUE2",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.COND3"
// 		}
// 	});
// 	ValueUnit_var_Property = CxvPropertyDeclaration.Register("ValueUnit_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "p_ValueUnits",
// 		IsReadOnly = true
// 	});
// 	Contains_var_Property = CxvPropertyDeclaration.Register("Contains_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			PropertyPath = "Condition_var.Value",
// 			Value = "NAME",
// 			Operator = CxvLogicalOperator.Equal
// 		}
// 	});
// 	format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(MMSetup_StreamGroup_Selection_ViewModel), new CxvLineFormatProperty
// 	{
// 		DataPath = "@main.Input.LINESTYLE"
// 	});
// 	_definedColors = new Color[16]
// 	{
// 		Colors.Black,
// 		Colors.Navy,
// 		Colors.Green,
// 		Colors.Teal,
// 		Colors.Brown,
// 		Colors.Purple,
// 		Colors.DarkOliveGreen,
// 		Colors.Gray,
// 		Colors.DarkGray,
// 		Colors.Blue,
// 		Colors.LightGreen,
// 		Colors.SkyBlue,
// 		Colors.Red,
// 		Colors.Fuchsia,
// 		Colors.Yellow,
// 		Colors.LightGray
// 	};
// }

// 0x060000bb AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_ModOpt_ViewModel..ctor
// public MMSetup_Simopt_ModOpt_ViewModel()
// {
// }

// 0x060000bc AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_ModOpt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_Simopt_ModOpt_ViewModel()
// {
// 	expandar_compr_Property = CxvPropertyDeclaration.Register("expandar_compr", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTCOMPR" }
// 	});
// 	expandar_mcompr_Property = CxvPropertyDeclaration.Register("expandar_mcompr", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTMCOMP" }
// 	});
// 	expandar_rgibbs_Property = CxvPropertyDeclaration.Register("expandar_rgibbs", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTRGIBB" }
// 	});
// 	expandar_radfrac_Property = CxvPropertyDeclaration.Register("expandar_radfrac", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTRADFR" }
// 	});
// 	expandar_heatx_Property = CxvPropertyDeclaration.Register("expandar_heatx", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTHEATX" }
// 	});
// 	expandar_heater_Property = CxvPropertyDeclaration.Register("expandar_heater", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTHEATER" }
// 	});
// 	expandar_Mheatx_Property = CxvPropertyDeclaration.Register("expandar_Mheatx", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.Model-Option.CC Nodes.ENTMHEATX" }
// 	});
// 	cmbComprNPh_var1_Property = CxvPropertyDeclaration.Register("cmbComprNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Model-Option.Input.COMPR_NPHASE",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	spnComprMaxit_var1_Property = CxvPropertyDeclaration.Register("spnComprMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.SB_MAXIT"
// 	});
// 	lbtuComprTol_var1_Property = CxvPropertyDeclaration.Register("lbtuComprTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.SB_TOL"
// 	});
// 	cmbMComprNPh_var1_Property = CxvPropertyDeclaration.Register("cmbMComprNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Model-Option.Input.MCOMPR_NPHAS",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	cmbCoolNPh_var1_Property = CxvPropertyDeclaration.Register("cmbCoolNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Model-Option.Input.COOLER_NPHAS",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	spnMComprMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMComprMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.MC_SB_MAXIT"
// 	});
// 	lbtuMComprTol_var1_Property = CxvPropertyDeclaration.Register("lbtuMComprTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.MC_SB_TOL"
// 	});
// 	spnRGibbsNPh_var1_Property = CxvPropertyDeclaration.Register("spnRGibbsNPh_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.RGIBBS_NPHAS"
// 	});
// 	spnRGibbsMaxit_var1_Property = CxvPropertyDeclaration.Register("spnRGibbsMaxit_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.RGIBBS_MAXIT"
// 	});
// 	lbtuRGibbsTol_var1_Property = CxvPropertyDeclaration.Register("lbtuRGibbsTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.RGIBBS_TOL"
// 	});
// 	spnRadfMaxol_var1_Property = CxvPropertyDeclaration.Register("spnRadfMaxol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.MAXOL"
// 	});
// 	cmbRadfAlgor_var1_Multimap_Property = CxvPropertyDeclaration.Register("cmbRadfAlgor_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ComboBox4_var1",
// 				DataPath = "@main.Model-Option.Input.ALGORITHM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard",
// 				Prompt = ApwnComboPromptResource.setup_model_option_algorithm_standard_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox4_var1",
// 						Value = "STANDARD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Sum-Rates",
// 				Prompt = ApwnComboPromptResource.setup_model_option_algorithm_sum_rates_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox4_var1",
// 						Value = "SUM-RATES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Nonideal",
// 				Prompt = ApwnComboPromptResource.setup_model_option_algorithm_nonideal_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox4_var1",
// 						Value = "NONIDEAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Newton",
// 				Prompt = ApwnComboPromptResource.setup_model_option_algorithm_newton_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox4_var1",
// 						Value = "NEWTON"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cmbDamping_var1_Property = CxvPropertyDeclaration.Register("cmbDamping_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Model-Option.Input.DAMPING",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	lbtuRadfTol_var1_Property = CxvPropertyDeclaration.Register("lbtuRadfTol_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.TOLOL"
// 	});
// 	lbtuRadffmin_var1_Property = CxvPropertyDeclaration.Register("lbtuRadffmin_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.FMINFAC"
// 	});
// 	lbtuRadfdtmax_var1_Property = CxvPropertyDeclaration.Register("lbtuRadfdtmax_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.DTMAX"
// 	});
// 	ChkHydrPlots_var_Property = CxvPropertyDeclaration.Register("ChkHydrPlots_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.HYDR_PLOTS",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ChkTQCalc_var_Property = CxvPropertyDeclaration.Register("ChkTQCalc_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.CURVE",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ChkHPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkHPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.HDPPARMOP",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ChkCPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkCPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.CDPPARMOP",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ChkPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.DPPARMOPT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	lbtuPDCorr_var1_Property = CxvPropertyDeclaration.Register("lbtuPDCorr_var1", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.DPPARM"
// 	});
// 	ChkMHPDCorr_var_Property = CxvPropertyDeclaration.Register("ChkMHPDCorr_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.MH_DPPARMOPT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ChkReaction_var_Property = CxvPropertyDeclaration.Register("ChkReaction_var", typeof(MMSetup_Simopt_ModOpt_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Model-Option.Input.RPT_KINETICS",
// 		TrueValue = "KINETICS",
// 		FalseValue = "NOKINETICS",
// 		DefaultValue = true
// 	});
// }

// 0x060000c5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Characterization_ViewModel..ctor
// public MMSetup_Stratt_Characterization_ViewModel()
// {
// }

// 0x060000c6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Characterization_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Stratt_Characterization_ViewModel()
// {
// 	cboType_var2_Property = CxvPropertyDeclaration.Register("cboType_var2", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "id"
// 	});
// 	cboType_var1_Property = CxvPropertyDeclaration.Register("cboType_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Substreams.Input.TYPE",
// 		SelectedItemBinding = "cboType_var2.Value",
// 		CreateNewInputMask = 3
// 	});
// 	chkPSDSpec_var1_Property = CxvPropertyDeclaration.Register("chkPSDSpec_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Substreams.Input.SELECT_PSD.@id",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	ComboBoxSclass_var1_Property = CxvPropertyDeclaration.Register("ComboBoxSclass_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@parent.@parent.Global.Input.SCLASS"
// 	});
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Stratt_Characterization_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.@parent.@parent.@parent.Components.Moisture-Comps.Input.COMP",
// 		AllowSort = false
// 	});
// }

// 0x060000e5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel.add_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060000e6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel.remove_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060000ed AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel.add_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060000ee AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel.remove_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060000f7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel..ctor
// public MMSetup_Stratt_List1D_ViewModel()
// {
// }

// 0x060000f8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Stratt_List1D_ViewModel()
// {
// 	cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "InsertChild"
// 	});
// 	cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDeleteCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "DeleteChild"
// 			}
// 		}
// 	});
// 	cmdRenameCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRenameCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Value = 1
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "RenameChild"
// 			}
// 		}
// 	});
// 	cmdHideCanExecuteProperty = CxvPropertyDeclaration.Register("cmdHideCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "HideChild"
// 			}
// 		}
// 	});
// 	cmdRevealCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRevealCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "RevealChild"
// 	});
// 	cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Equal,
// 		PropertyPath = "CanPaste",
// 		Value = true
// 	});
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Stratt_List1D_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main",
// 			UseChildId = true,
// 			ProxyRow = false,
// 			Name = "y"
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x06000101 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Attr_ViewModel..ctor
// public MMSetup_Attr_ViewModel()
// {
// }

// 0x06000102 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Attr_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Attr_ViewModel()
// {
// 	ccmain_Property = CxvPropertyDeclaration.Register("ccmain", typeof(MMSetup_Attr_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ccmain"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Attr_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PSD" },
// 		EnteredDataPaths = { "@ATTRE" }
// 	});
// 	PSD_Property = CxvPropertyDeclaration.Register("PSD", typeof(MMSetup_Attr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MN1"
// 	});
// 	ATTRE_Property = CxvPropertyDeclaration.Register("ATTRE", typeof(MMSetup_Attr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ATTRE"
// 	});
// }

// 0x0600010d AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_ViewModel..ctor
// public MMSetup_CostOp_ViewModel()
// {
// }

// 0x0600010e AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_CostOp_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Currency.CC Nodes.SPEC"
// 	});
// 	entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Currency.CC Nodes.ENTN"
// 	});
// 	entcostop_Property = CxvPropertyDeclaration.Register("entcostop", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTCOSTOP"
// 	});
// 	costop_Property = CxvPropertyDeclaration.Register("costop", typeof(MMSetup_CostOp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.COSTOP"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_CostOp_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@costop" },
// 		EnteredDataPaths = { "@entcostop" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_CostOp_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" },
// 		EnteredDataPaths = { "@entn" }
// 	});
// }

// 0x06000121 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_CostOpt_ViewModel..ctor
// using System.IO;
//
// public MMSetup_CostOp_CostOpt_ViewModel()
// {
// 	REG_APSEN_ICARUS_PRODUCTS = Path.Combine("SOFTWARE", "AspenTech", "Aspen Icarus Products");
// 	ASPEN_ICARUS_IPE = "IPE";
// 	base..ctor();
// }

// 0x06000122 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_CostOpt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_CostOp_CostOpt_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PLANT_LIFE"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.STARTUP"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.START_DAY"
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.START_MONTH",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.START_YEAR",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	txtArch_var1_Property = CxvPropertyDeclaration.Register("txtArch_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.TEMPLATE"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.SCENARIO"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMSetup_CostOp_CostOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.DESCRIPTION",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x06000128 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_Curren_ViewModel..ctor
// public MMSetup_CostOp_Curren_ViewModel()
// {
// }

// 0x06000129 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_Curren_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_CostOp_Curren_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSetup_CostOp_Curren_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Currency.Input.FACTOR",
// 			UseChildId = false,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000131 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_ViewModel..ctor
// public MMSetup_CusUom_ViewModel()
// {
// }

// 0x06000132 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_CusUom_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_CusUom_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Custom-Uom.CC Nodes.SPEC"
// 	});
// 	entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_CusUom_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Custom-Uom.CC Nodes.ENTN"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_CusUom_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" },
// 		EnteredDataPaths = { "@entn" }
// 	});
// }

// 0x06000138 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_Setup_ViewModel..ctor
// public MMSetup_CusUom_Setup_ViewModel()
// {
// }

// 0x06000139 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_Setup_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_CusUom_Setup_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSetup_CusUom_Setup_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Custom-Uom.Input.PHYS_QTY",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000151 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ViewModel..ctor
// public MMSetup_Report_ViewModel()
// {
// }

// 0x06000152 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_ViewModel()
// {
// 	sreportno_Property = CxvPropertyDeclaration.Register("sreportno", typeof(MMSetup_Report_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "sreportno"
// 	});
// 	entglob_Property = CxvPropertyDeclaration.Register("entglob", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.CC Nodes.ENTGLOB"
// 	});
// 	entflows_Property = CxvPropertyDeclaration.Register("entflows", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.CC Nodes.ENTFLOWS"
// 	});
// 	entblock_Property = CxvPropertyDeclaration.Register("entblock", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.CC Nodes.ENTBLOCK"
// 	});
// 	entstrm_Property = CxvPropertyDeclaration.Register("entstrm", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.ENTSTRM"
// 	});
// 	entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.CC Nodes.ENTPROP"
// 	});
// 	entada_Property = CxvPropertyDeclaration.Register("entada", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.ADA-Report.CC Nodes.ENTADA"
// 	});
// 	flow_Property = CxvPropertyDeclaration.Register("flow", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.FLOW"
// 	});
// 	prop_Property = CxvPropertyDeclaration.Register("prop", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.PROP"
// 	});
// 	ada_Property = CxvPropertyDeclaration.Register("ada", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.ADA"
// 	});
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.CC Nodes.SPEC"
// 	});
// 	block_Property = CxvPropertyDeclaration.Register("block", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.CC Nodes.BLOCK"
// 	});
// 	spec2_Property = CxvPropertyDeclaration.Register("spec2", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Names.CC Nodes.SPEC"
// 	});
// 	entstrname_Property = CxvPropertyDeclaration.Register("entstrname", typeof(MMSetup_Report_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Names.CC Nodes.ENTSTREAM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entglob" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@flow" },
// 		EnteredDataPaths = { "@entflows" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@block" },
// 		AccessibleDataPaths = { "@flow" },
// 		EnteredDataPaths = { "@entblock" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec", "@spec2" },
// 		AccessibleDataPaths = { "@flow" },
// 		EnteredDataPaths = { "@entstrm", "@entstrname" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@prop" },
// 		EnteredDataPaths = { "@entprop" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSetup_Report_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ada" },
// 		EnteredDataPaths = { "@entada" }
// 	});
// }

// 0x0600015a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ADA_ViewModel..ctor
// public MMSetup_Report_ADA_ViewModel()
// {
// }

// 0x0600015b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ADA_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_ADA_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_ADA_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.ADA"
// 		}
// 	});
// 	chkComps_var1_Property = CxvPropertyDeclaration.Register("chkComps_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.ADA-Report.Input.COMPS",
// 		TrueValue = "COMPS",
// 		FalseValue = "NOCOMPS",
// 		DefaultValue = true
// 	});
// 	chkCurves_var1_Property = CxvPropertyDeclaration.Register("chkCurves_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.ADA-Report.Input.CURVES",
// 		TrueValue = "CURVES",
// 		FalseValue = "NOCURVES",
// 		DefaultValue = true
// 	});
// 	chkParams_var1_Property = CxvPropertyDeclaration.Register("chkParams_var1", typeof(MMSetup_Report_ADA_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.ADA-Report.Input.PARAMS",
// 		TrueValue = "PARAMS",
// 		FalseValue = "NOPARAMS",
// 		DefaultValue = false
// 	});
// }

// 0x06000165 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Attrib_ViewModel..ctor
// public MMSetup_Report_Attrib_ViewModel()
// {
// }

// 0x06000166 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Attrib_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Attrib_ViewModel()
// {
// 	chkStruct_struct_Property = CxvPropertyDeclaration.Register("chkStruct_struct", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.STRUCTURE",
// 		TrueValue = "STRUCTURE",
// 		FalseValue = "NOSTRUCTURE",
// 		DefaultValue = false
// 	});
// 	chkAttrDesc_attrdesc_Property = CxvPropertyDeclaration.Register("chkAttrDesc_attrdesc", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.ATTR_DESC",
// 		TrueValue = "ATTR-DESC",
// 		FalseValue = "NOATTR-DESC",
// 		DefaultValue = true
// 	});
// 	chkCompAttr_compattr_Property = CxvPropertyDeclaration.Register("chkCompAttr_compattr", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.COMP_ATTR",
// 		TrueValue = "COMP-ATTR",
// 		FalseValue = "NOCOMP-ATTR",
// 		DefaultValue = true
// 	});
// 	chkSubsAttr_subsattr_Property = CxvPropertyDeclaration.Register("chkSubsAttr_subsattr", typeof(MMSetup_Report_Attrib_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUBS_ATTR",
// 		TrueValue = "SUBS-ATTR",
// 		FalseValue = "NOSUBS-ATTR",
// 		DefaultValue = true
// 	});
// }

// 0x06000170 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BatchO_ViewModel..ctor
// public MMSetup_Report_BatchO_ViewModel()
// {
// }

// 0x06000171 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BatchO_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_BatchO_ViewModel()
// {
// 	lbtuOptime_var1_Property = CxvPropertyDeclaration.Register("lbtuOptime_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.OP_TIME"
// 	});
// 	lbtuDown_var1_Property = CxvPropertyDeclaration.Register("lbtuDown_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.DOWN_TIME"
// 	});
// 	lbtuCycle_var1_Property = CxvPropertyDeclaration.Register("lbtuCycle_var1", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME"
// 	});
// 	SABatchO_GridData_Property = CxvPropertyDeclaration.Register("SABatchO_GridData", typeof(MMSetup_Report_BatchO_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(SABatchO_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000179 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BlkExc_ViewModel..ctor
// public MMSetup_Report_BlkExc_ViewModel()
// {
// }

// 0x0600017a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BlkExc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_BlkExc_ViewModel()
// {
// 	lstpkInclBl_var1_Property = CxvPropertyDeclaration.Register("lstpkInclBl_var1", typeof(MMSetup_Report_BlkExc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Block-Report.Input.EXCL_BLOCKS"
// 	});
// 	lstpkInclBl_state_Property = CxvPropertyDeclaration.Register("lstpkInclBl_state", typeof(MMSetup_Report_BlkExc_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
// 		}
// 	});
// }

// 0x06000182 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BlkInc_ViewModel..ctor
// public MMSetup_Report_BlkInc_ViewModel()
// {
// }

// 0x06000183 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BlkInc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_BlkInc_ViewModel()
// {
// 	lstpkInclBl_var1_Property = CxvPropertyDeclaration.Register("lstpkInclBl_var1", typeof(MMSetup_Report_BlkInc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Block-Report.Input.INCL_BLOCKS"
// 	});
// 	lstpkInclBl_state_Property = CxvPropertyDeclaration.Register("lstpkInclBl_state", typeof(MMSetup_Report_BlkInc_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
// 		}
// 	});
// }

// 0x06000195 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Block_ViewModel..ctor
// public MMSetup_Report_Block_ViewModel()
// {
// }

// 0x06000196 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Block_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Block_ViewModel()
// {
// 	chkCompbal_var1_Property = CxvPropertyDeclaration.Register("chkCompbal_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.COMPBAL",
// 		TrueValue = "COMPBAL",
// 		FalseValue = "NOCOMPBAL",
// 		DefaultValue = false
// 	});
// 	chkInput_var1_Property = CxvPropertyDeclaration.Register("chkInput_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.INPUT",
// 		TrueValue = "INPUT",
// 		FalseValue = "NOINPUT",
// 		DefaultValue = true
// 	});
// 	chkTotbal_var1_Property = CxvPropertyDeclaration.Register("chkTotbal_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.TOTBAL",
// 		TrueValue = "TOTBAL",
// 		FalseValue = "NOTOTBAL",
// 		DefaultValue = true
// 	});
// 	chkResults_var1_Property = CxvPropertyDeclaration.Register("chkResults_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.RESULTS",
// 		TrueValue = "RESULTS",
// 		FalseValue = "NORESULTS",
// 		DefaultValue = true
// 	});
// 	MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.NEWPAGE",
// 		TrueValue = "NEWPAGE",
// 		FalseValue = "NONEWPAGE",
// 		DefaultValue = false
// 	});
// 	chkSort_var1_Property = CxvPropertyDeclaration.Register("chkSort_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Block-Report.Input.SORT",
// 		TrueValue = "SORT",
// 		FalseValue = "NOSORT",
// 		DefaultValue = true
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSetup_Report_Block_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.BLOCK"
// 		}
// 	});
// 	cmdExcludeBlock_var1_Property = CxvPropertyDeclaration.Register("cmdExcludeBlock_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Block-Report.CC Nodes.EXCLD"
// 		}
// 	});
// 	cmdIncludeBlock_var1_Property = CxvPropertyDeclaration.Register("cmdIncludeBlock_var1", typeof(MMSetup_Report_Block_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Block-Report.CC Nodes.INCLD"
// 		}
// 	});
// }

// 0x060001a6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Default_ViewModel..ctor
// public MMSetup_Report_Default_ViewModel()
// {
// }

// 0x060001a7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Default_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Default_ViewModel()
// {
// 	chkReport_var1_Property = CxvPropertyDeclaration.Register("chkReport_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.REPORT",
// 		TrueValue = "REPORT",
// 		FalseValue = "NOREPORT",
// 		DefaultValue = true
// 	});
// 	MMFrame3_state_Property = CxvPropertyDeclaration.Register("MMFrame3_state", typeof(MMSetup_Report_Default_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
// 		}
// 	});
// 	spnLine_var1_Property = CxvPropertyDeclaration.Register("spnLine_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.LINES"
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Default_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
// 		}
// 	});
// 	chkSens_var1_Property = CxvPropertyDeclaration.Register("chkSens_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.SENSITIVITY",
// 		TrueValue = "SENSITIVITY",
// 		FalseValue = "NOSENSITIVIT",
// 		DefaultValue = true
// 	});
// 	chkProp_var1_Property = CxvPropertyDeclaration.Register("chkProp_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.PROPERTIES",
// 		TrueValue = "PROPERTIES",
// 		FalseValue = "NOPROPERTIES",
// 		DefaultValue = true
// 	});
// 	chkBlocks_var1_Property = CxvPropertyDeclaration.Register("chkBlocks_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.BLOCKS",
// 		TrueValue = "BLOCKS",
// 		FalseValue = "NOBLOCKS",
// 		DefaultValue = true
// 	});
// 	chkSensit_var1_Property = CxvPropertyDeclaration.Register("chkSensit_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.STREAMS",
// 		TrueValue = "STREAMS",
// 		FalseValue = "NOSTREAMS",
// 		DefaultValue = true
// 	});
// 	chkFlowsheet_var1_Property = CxvPropertyDeclaration.Register("chkFlowsheet_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.FLOWSHEET",
// 		TrueValue = "FLOWSHEET",
// 		FalseValue = "NOFLOWSHEET",
// 		DefaultValue = true
// 	});
// 	chkAda_var1_Property = CxvPropertyDeclaration.Register("chkAda_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.ADA",
// 		TrueValue = "ADA",
// 		FalseValue = "NOADA",
// 		DefaultValue = true
// 	});
// 	chkInsert_var1_Property = CxvPropertyDeclaration.Register("chkInsert_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.INSERT",
// 		TrueValue = "INSERT",
// 		FalseValue = "NOINSERT",
// 		DefaultValue = true
// 	});
// 	chkInput_var1_Property = CxvPropertyDeclaration.Register("chkInput_var1", typeof(MMSetup_Report_Default_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Report.Input.INPUT",
// 		TrueValue = "INPUT",
// 		FalseValue = "NOINPUT",
// 		DefaultValue = false
// 	});
// }

// 0x060001ae AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ExclSt_ViewModel..ctor
// public MMSetup_Report_ExclSt_ViewModel()
// {
// }

// 0x060001af AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_ExclSt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_ExclSt_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_ExclSt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.EXCL_STREAMS"
// 	});
// }

// 0x060001be AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_FlowSh_ViewModel..ctor
// public MMSetup_Report_FlowSh_ViewModel()
// {
// }

// 0x060001bf AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_FlowSh_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_FlowSh_ViewModel()
// {
// 	chkConstraint_var1_Property = CxvPropertyDeclaration.Register("chkConstraint_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.CONSTRAINT",
// 		TrueValue = "CONSTRAINT",
// 		FalseValue = "NOCONSTRAINT",
// 		DefaultValue = true
// 	});
// 	chkTransfer_var1_Property = CxvPropertyDeclaration.Register("chkTransfer_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.TRANSFER",
// 		TrueValue = "TRANSFER",
// 		FalseValue = "NOTRANSFER",
// 		DefaultValue = true
// 	});
// 	chkDesign_var1_Property = CxvPropertyDeclaration.Register("chkDesign_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.DESIGN_SPEC",
// 		TrueValue = "DESIGN-SPEC",
// 		FalseValue = "NODESIGN-SPE",
// 		DefaultValue = true
// 	});
// 	chkOptimi_var1_Property = CxvPropertyDeclaration.Register("chkOptimi_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.OPTIMIZATION",
// 		TrueValue = "OPTIMIZATION",
// 		FalseValue = "NOOPTIMIZATI",
// 		DefaultValue = true
// 	});
// 	chkFortran_var1_Property = CxvPropertyDeclaration.Register("chkFortran_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.FORTRAN",
// 		TrueValue = "FORTRAN",
// 		FalseValue = "NOFORTRAN",
// 		DefaultValue = true
// 	});
// 	chkDescrip_var1_Property = CxvPropertyDeclaration.Register("chkDescrip_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.DESCRIPTION",
// 		TrueValue = "DESCRIPTION",
// 		FalseValue = "NODESCRIPTIO",
// 		DefaultValue = true
// 	});
// 	chkCompbal_var1_Property = CxvPropertyDeclaration.Register("chkCompbal_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.COMPBAL",
// 		TrueValue = "COMPBAL",
// 		FalseValue = "NOCOMPBAL",
// 		DefaultValue = true
// 	});
// 	chkTotbal_var1_Property = CxvPropertyDeclaration.Register("chkTotbal_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.TOTBAL",
// 		TrueValue = "TOTBAL",
// 		FalseValue = "NOTOTBAL",
// 		DefaultValue = true
// 	});
// 	chkSeq_var1_Property = CxvPropertyDeclaration.Register("chkSeq_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.SEQUENCE",
// 		TrueValue = "SEQUENCE",
// 		FalseValue = "NOSEQUENCE",
// 		DefaultValue = true
// 	});
// 	chkConverge_var1_Property = CxvPropertyDeclaration.Register("chkConverge_var1", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Flowsheet-Report.Input.CONVERGENCE",
// 		TrueValue = "CONVERGENCE",
// 		FalseValue = "NOCONVERGENC",
// 		DefaultValue = true
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_FlowSh_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.FLOWS"
// 		}
// 	});
// }

// 0x060001c6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_InclSt_ViewModel..ctor
// public MMSetup_Report_InclSt_ViewModel()
// {
// }

// 0x060001c7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_InclSt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_InclSt_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_InclSt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.INCL_STREAMS"
// 	});
// }

// 0x060001d5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Proper_ViewModel..ctor
// public MMSetup_Report_Proper_ViewModel()
// {
// }

// 0x060001d6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Proper_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Proper_ViewModel()
// {
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSetup_Report_Proper_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
// 		}
// 	});
// 	chkNeu_var1_Property = CxvPropertyDeclaration.Register("chkNeu_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.NEUTRAL",
// 		TrueValue = "NEUTRAL",
// 		FalseValue = "NONEUTRAL",
// 		DefaultValue = false
// 	});
// 	chkDfms_var1_Property = CxvPropertyDeclaration.Register("chkDfms_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.DFMS",
// 		TrueValue = "DFMS",
// 		FalseValue = "NODFMS",
// 		DefaultValue = false
// 	});
// 	chkProject_var1_Property = CxvPropertyDeclaration.Register("chkProject_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.PROJECT",
// 		TrueValue = "PROJECT",
// 		FalseValue = "NOPROJECT",
// 		DefaultValue = false
// 	});
// 	chkPropData_var1_Property = CxvPropertyDeclaration.Register("chkPropData_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.PROP_DATA",
// 		TrueValue = "PROP-DATA",
// 		FalseValue = "NOPROP-DATA",
// 		DefaultValue = false
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Proper_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
// 		}
// 	});
// 	chkPces_var1_Property = CxvPropertyDeclaration.Register("chkPces_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.PCES",
// 		TrueValue = "PCES",
// 		FalseValue = "NOPCES",
// 		DefaultValue = false
// 	});
// 	chkParplus_var1_Property = CxvPropertyDeclaration.Register("chkParplus_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.PARPLUS",
// 		TrueValue = "PARAM-PLUS",
// 		FalseValue = "NOPARAM-PLUS",
// 		DefaultValue = false
// 	});
// 	chkParams_var1_Property = CxvPropertyDeclaration.Register("chkParams_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.PARAMS",
// 		TrueValue = "PARAMS",
// 		FalseValue = "NOPARAMS",
// 		DefaultValue = false
// 	});
// 	chkComps_var1_Property = CxvPropertyDeclaration.Register("chkComps_var1", typeof(MMSetup_Report_Proper_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Property-Report.Input.COMPS",
// 		TrueValue = "COMPS",
// 		FalseValue = "NOCOMPS",
// 		DefaultValue = true
// 	});
// }

// 0x060001e0 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SAttri_ViewModel..ctor
// public MMSetup_Report_SAttri_ViewModel()
// {
// }

// 0x060001e1 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SAttri_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_SAttri_ViewModel()
// {
// 	chkSSubsAttr_subsattr_Property = CxvPropertyDeclaration.Register("chkSSubsAttr_subsattr", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_SUBS_ATTR.@sreportno",
// 		TrueValue = "SUBS-ATTR",
// 		FalseValue = "NOSUBS-ATTR",
// 		DefaultValue = true
// 	});
// 	chkSCompAttr_compattr_Property = CxvPropertyDeclaration.Register("chkSCompAttr_compattr", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_COMP_ATTR.@sreportno",
// 		TrueValue = "COMP-ATTR",
// 		FalseValue = "NOCOMP-ATTR",
// 		DefaultValue = true
// 	});
// 	chkSAttrDesc_attrdesc_Property = CxvPropertyDeclaration.Register("chkSAttrDesc_attrdesc", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_ATTR_DESC.@sreportno",
// 		TrueValue = "ATTR-DESC",
// 		FalseValue = "NOATTR-DESC",
// 		DefaultValue = true
// 	});
// 	chkSStruct_struct_Property = CxvPropertyDeclaration.Register("chkSStruct_struct", typeof(MMSetup_Report_SAttri_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_STRUCTURE.@sreportno",
// 		TrueValue = "STRUCTURE",
// 		FalseValue = "NOSTRUCTURE",
// 		DefaultValue = false
// 	});
// }

// 0x0600020a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Stream_ViewModel..ctor
// public MMSetup_Report_Stream_ViewModel()
// {
// }

// 0x0600020b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Stream_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Stream_ViewModel()
// {
// 	cmdBatch_CanExecuteProperty = CxvPropertyDeclaration.Register("cmdBatch_CanExecute", typeof(MMSetup_Report_Stream_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation",
// 		Operator = CxvLogicalOperator.IsNotNull
// 	});
// 	frmStreamFormat_state_Property = CxvPropertyDeclaration.Register("frmStreamFormat_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	chkSort_sort_Property = CxvPropertyDeclaration.Register("chkSort_sort", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SORT",
// 		TrueValue = "SORT",
// 		FalseValue = "NOSORT",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	opgWide_MultiMap_Property = CxvPropertyDeclaration.Register("opgWide_MultiMap", typeof(MMSetup_Report_Stream_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "opgWide_wide",
// 				DataPath = "@main.ReportOptions.Stream-Report.Input.WIDE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard (80 characters)",
// 				DisplayResourceKey = "MMSetup_Report_Stream_ViewModel__CxvMultiMapOption_Display_Standard__80_column_",
// 				Value = "opgWide_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "opgWide_wide",
// 						Value = "NARROW"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Wide (132 characters)",
// 				DisplayResourceKey = "MMSetup_Report_Stream_ViewModel__CxvMultiMapOption_Display_Wide__132_column_",
// 				Value = "opgWide_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "opgWide_wide",
// 						Value = "WIDE"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Main.Input.TFFFILE",
// 		Sorted = true
// 	});
// 	cmdExclStreams_var1_Property = CxvPropertyDeclaration.Register("cmdExclStreams_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.EXCLD"
// 		}
// 	});
// 	cmdStream_var1_Property = CxvPropertyDeclaration.Register("cmdStream_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.INCLD"
// 		}
// 	});
// 	cmdPropSets_var1_Property = CxvPropertyDeclaration.Register("cmdPropSets_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	cmdAttribute_var1_Property = CxvPropertyDeclaration.Register("cmdAttribute_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	chkZero_zero_Property = CxvPropertyDeclaration.Register("chkZero_zero", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.ZEROFLOW",
// 		TrueValue = "ZEROFLOW",
// 		FalseValue = "NOZEROFLOW",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	fraFracBasis_state_Property = CxvPropertyDeclaration.Register("fraFracBasis_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	chkFracStd_stdvolfrac_Property = CxvPropertyDeclaration.Register("chkFracStd_stdvolfrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.STDVOLFRAC",
// 		TrueValue = "STDVOLFRAC",
// 		FalseValue = "NOVOLFRAC",
// 		DefaultValue = false
// 	});
// 	chkFracMass_massfrac_Property = CxvPropertyDeclaration.Register("chkFracMass_massfrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.MASSFRAC",
// 		TrueValue = "MASSFRAC",
// 		FalseValue = "NOMASSFRAC",
// 		DefaultValue = false
// 	});
// 	chkFracMole_molefrac_Property = CxvPropertyDeclaration.Register("chkFracMole_molefrac", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.MOLEFRAC",
// 		TrueValue = "MOLEFRAC",
// 		FalseValue = "NOMOLEFRAC",
// 		DefaultValue = false
// 	});
// 	fraFlowBasis_state_Property = CxvPropertyDeclaration.Register("fraFlowBasis_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	chkFlowStd_stdvolflow_Property = CxvPropertyDeclaration.Register("chkFlowStd_stdvolflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.STDVOLFLOW",
// 		TrueValue = "STDVOLFLOW",
// 		FalseValue = "NOVOLFLOW",
// 		DefaultValue = false
// 	});
// 	chkFlowMass_massflow_Property = CxvPropertyDeclaration.Register("chkFlowMass_massflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.MASSFLOW",
// 		TrueValue = "MASSFLOW",
// 		FalseValue = "NOMASSFLOW",
// 		DefaultValue = false
// 	});
// 	chkFlowMole_moleflow_Property = CxvPropertyDeclaration.Register("chkFlowMole_moleflow", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.MOLEFLOW",
// 		TrueValue = "MOLEFLOW",
// 		FalseValue = "NOMOLEFLOW",
// 		DefaultValue = true
// 	});
// 	chkNames_var1_Property = CxvPropertyDeclaration.Register("chkNames_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.NAMES",
// 		TrueValue = "NAMES",
// 		FalseValue = "NONAMES",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.STRM"
// 		}
// 	});
// 	chkReport_var1_Property = CxvPropertyDeclaration.Register("chkReport_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.REPORT",
// 		TrueValue = "REPORT",
// 		FalseValue = "NOREPORT",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
// 		}
// 	});
// 	cmdSuppl_var1_Property = CxvPropertyDeclaration.Register("cmdSuppl_var1", typeof(MMSetup_Report_Stream_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
// 		}
// 	});
// 	fraItems_state_Property = CxvPropertyDeclaration.Register("fraItems_state", typeof(MMSetup_Report_Stream_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "Top.appModelv8.Setup.ReportOptions.Report.CC Nodes.STRM"
// 		}
// 	});
// }

// 0x06000212 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrName_ViewModel..ctor
// public MMSetup_Report_StrName_ViewModel()
// {
// }

// 0x06000213 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrName_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_StrName_ViewModel()
// {
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Report_StrName_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x0600021a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrPro_ViewModel..ctor
// public MMSetup_Report_StrPro_ViewModel()
// {
// }

// 0x0600021b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrPro_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_StrPro_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_StrPro_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.PROPERTIES",
// 		AllowSort = false
// 	});
// }

// 0x06000222 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupExc_ViewModel..ctor
// public MMSetup_Report_SupExc_ViewModel()
// {
// }

// 0x06000223 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupExc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_SupExc_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_SupExc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_EXCL_ST.@sreportno"
// 	});
// }

// 0x0600022a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupInc_ViewModel..ctor
// public MMSetup_Report_SupInc_ViewModel()
// {
// }

// 0x0600022b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupInc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_SupInc_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMSetup_Report_SupInc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_INCL_ST.@sreportno"
// 	});
// }

// 0x0600024f AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Supple_ViewModel..ctor
// public MMSetup_Report_Supple_ViewModel()
// {
// }

// 0x06000250 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_Supple_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_Supple_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "sreportno",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	cmdExcludeStream_var1_Property = CxvPropertyDeclaration.Register("cmdExcludeStream_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SEXCLD.@sreportno"
// 		}
// 	});
// 	cmdStream_var1_Property = CxvPropertyDeclaration.Register("cmdStream_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SINCLD.@sreportno"
// 		}
// 	});
// 	chkSReport_var1_Property = CxvPropertyDeclaration.Register("chkSReport_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_REPORT.@sreportno",
// 		TrueValue = "REPORT",
// 		FalseValue = "NOREPORT",
// 		DefaultValue = true
// 	});
// 	fraItems_state_Property = CxvPropertyDeclaration.Register("fraItems_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "sreportno",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	cmdAttribute_var1_Property = CxvPropertyDeclaration.Register("cmdAttribute_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	cmdPropSets_var1_Property = CxvPropertyDeclaration.Register("cmdPropSets_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	opgSWide_MultiMap_Property = CxvPropertyDeclaration.Register("opgSWide_MultiMap", typeof(MMSetup_Report_Supple_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "opgSWide_wide",
// 				DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_WIDE.@sreportno"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard (80 characters)",
// 				DisplayResourceKey = "MMSetup_Report_Supple_ViewModel__CxvMultiMapOption_Display_Standard__80_column_",
// 				Value = "opgSWide_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "opgSWide_wide",
// 						Value = "NARROW"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Wide (132 characters)",
// 				DisplayResourceKey = "MMSetup_Report_Supple_ViewModel__CxvMultiMapOption_Display_Wide__132_column_",
// 				Value = "opgSWide_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "opgSWide_wide",
// 						Value = "WIDE"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	chkSSort_sort_Property = CxvPropertyDeclaration.Register("chkSSort_sort", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_SORT.@sreportno",
// 		TrueValue = "SORT",
// 		FalseValue = "NOSORT",
// 		DefaultValue = true
// 	});
// 	fraFlowBasis_state_Property = CxvPropertyDeclaration.Register("fraFlowBasis_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	chkSFlowMole_moleflow_Property = CxvPropertyDeclaration.Register("chkSFlowMole_moleflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MOLEFLOW.@sreportno",
// 		TrueValue = "MOLEFLOW",
// 		FalseValue = "NOMOLEFLOW",
// 		DefaultValue = true
// 	});
// 	chkSFlowMass_massflow_Property = CxvPropertyDeclaration.Register("chkSFlowMass_massflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MASSFLOW.@sreportno",
// 		TrueValue = "MASSFLOW",
// 		FalseValue = "NOMASSFLOW",
// 		DefaultValue = false
// 	});
// 	chkSFlowStd_stdvolflow_Property = CxvPropertyDeclaration.Register("chkSFlowStd_stdvolflow", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_STDVOLFLOW.@sreportno",
// 		TrueValue = "STDVOLFLOW",
// 		FalseValue = "NOVOLFLOW",
// 		DefaultValue = false
// 	});
// 	fraFracBasis_state_Property = CxvPropertyDeclaration.Register("fraFracBasis_state", typeof(MMSetup_Report_Supple_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	chkSFracMole_molefrac_Property = CxvPropertyDeclaration.Register("chkSFracMole_molefrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MOLEFRAC.@sreportno",
// 		TrueValue = "MOLEFRAC",
// 		FalseValue = "NOMOLEFRAC",
// 		DefaultValue = false
// 	});
// 	chkSFracMass_massfrac_Property = CxvPropertyDeclaration.Register("chkSFracMass_massfrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_MASSFRAC.@sreportno",
// 		TrueValue = "MASSFRAC",
// 		FalseValue = "NOMASSFRAC",
// 		DefaultValue = false
// 	});
// 	chkSFracStd_stdvolfrac_Property = CxvPropertyDeclaration.Register("chkSFracStd_stdvolfrac", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.S_STDVOLFRAC.@sreportno",
// 		TrueValue = "STDVOLFRAC",
// 		FalseValue = "NOVOLFRAC",
// 		DefaultValue = false
// 	});
// 	chkSZero_zero_Property = CxvPropertyDeclaration.Register("chkSZero_zero", typeof(MMSetup_Report_Supple_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUP_ZEROFLOW.@sreportno",
// 		TrueValue = "ZEROFLOW",
// 		FalseValue = "NOZEROFLOW",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.ReportOptions.Stream-Report.CC Nodes.SUPP.@sreportno"
// 		}
// 	});
// 	mnbReportNo_var2_Property = CxvPropertyDeclaration.Register("mnbReportNo_var2", typeof(MMSetup_Report_Supple_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "sreportno"
// 	});
// 	mnbReportNo_var1_Property = CxvPropertyDeclaration.Register("mnbReportNo_var1", typeof(MMSetup_Report_Supple_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_REPORT",
// 		SelectedItemBinding = "mnbReportNo_var2.Value",
// 		CreateNewPrompt = "Supplementary report number:",
// 		CreateNewPromptResourceKey = "MMSetup_Report_Supple_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Supplementary_report_numbe",
// 		CreateNewInputMask = 0,
// 		CreateNewMaxLength = 3
// 	});
// }

// 0x06000257 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupPro_ViewModel..ctor
// public MMSetup_Report_SupPro_ViewModel()
// {
// }

// 0x06000258 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupPro_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_SupPro_ViewModel()
// {
// 	lstpSupPropSet_var1_Property = CxvPropertyDeclaration.Register("lstpSupPropSet_var1", typeof(MMSetup_Report_SupPro_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUPP_PROPS.@sreportno",
// 		AllowSort = false
// 	});
// }

// 0x06000260 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupSub_ViewModel..ctor
// public MMSetup_Report_SupSub_ViewModel()
// {
// }

// 0x06000261 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_SupSub_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Report_SupSub_ViewModel()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMSetup_Report_SupSub_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.HEADING.@sreportno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Report_SupSub_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Report.Input.SUBROUTINE.@sreportno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x06000276 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_ViewModel..ctor
// public MMSetup_Setup_ViewModel()
// {
// }

// 0x06000277 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_ViewModel()
// {
// 	accoun_Property = CxvPropertyDeclaration.Register("accoun", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.CC Nodes.MAIN1"
// 	});
// 	global_Property = CxvPropertyDeclaration.Register("global", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.GLMAIN"
// 	});
// 	entglb_Property = CxvPropertyDeclaration.Register("entglb", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Global.CC Nodes.ENTGLOBAL"
// 	});
// 	entacc_Property = CxvPropertyDeclaration.Register("entacc", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.CC Nodes.ENTACCOUN"
// 	});
// 	entstr_Property = CxvPropertyDeclaration.Register("entstr", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.ENTSTREAM"
// 	});
// 	entdg_Property = CxvPropertyDeclaration.Register("entdg", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.CC Nodes.ENTDIAG"
// 	});
// 	entdes_Property = CxvPropertyDeclaration.Register("entdes", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Description.CC Nodes.ENTDESC"
// 	});
// 	enetit_Property = CxvPropertyDeclaration.Register("enetit", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.ENTTITLE"
// 	});
// 	entphs_Property = CxvPropertyDeclaration.Register("entphs", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTPHASE"
// 	});
// 	visited_Property = CxvPropertyDeclaration.Register("visited", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.Input.VISITED"
// 	});
// 	entmeth_Property = CxvPropertyDeclaration.Register("entmeth", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTSMETH"
// 	});
// 	GLOBL_Property = CxvPropertyDeclaration.Register("GLOBL", typeof(MMSetup_Setup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.GLOBL"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@global", "@GLOBL" },
// 		EnteredDataPaths = { "@enetit", "@entglb", "@entmeth", "@entphs" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entdes" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@accoun" },
// 		EnteredDataPaths = { "@entacc" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Setup_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entdg" }
// 	});
// }

// 0x06000281 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Accoun_ViewModel..ctor
// public MMSetup_Setup_Accoun_ViewModel()
// {
// }

// 0x06000282 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Accoun_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Accoun_ViewModel()
// {
// 	lbtuProjId_var1_Property = CxvPropertyDeclaration.Register("lbtuProjId_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.Input.PROJECT_ID",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuProjName_var1_Property = CxvPropertyDeclaration.Register("lbtuProjName_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.Input.PROJECT_NAME",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuAccount_var1_Property = CxvPropertyDeclaration.Register("lbtuAccount_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.Input.ACCOUNT",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuUsName_var1_Property = CxvPropertyDeclaration.Register("lbtuUsName_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Account-Info.Input.USER_NAME",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	fraHeader_var1_Property = CxvPropertyDeclaration.Register("fraHeader_var1", typeof(MMSetup_Setup_Accoun_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "HeaderLabel"
// 	});
// }

// 0x06000288 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Descri_ViewModel..ctor
// public MMSetup_Setup_Descri_ViewModel()
// {
// }

// 0x06000289 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Descri_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Descri_ViewModel()
// {
// 	MMDescription1_var1_Property = CxvPropertyDeclaration.Register("MMDescription1_var1", typeof(MMSetup_Setup_Descri_ViewModel), new CxvDescriptionProperty
// 	{
// 		DataPath = "@main.Description.Input.DESCRIP"
// 	});
// }

// 0x0600029b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Diagno_ViewModel..ctor
// public MMSetup_Setup_Diagno_ViewModel()
// {
// }

// 0x0600029c AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Diagno_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Diagno_ViewModel()
// {
// 	dsldConverg_var1_Property = CxvPropertyDeclaration.Register("dsldConverg_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_CONV_LEVEL"
// 	});
// 	dsldConverg_var2_Property = CxvPropertyDeclaration.Register("dsldConverg_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.CONV_LEVEL"
// 	});
// 	dsldStream_var1_Property = CxvPropertyDeclaration.Register("dsldStream_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_STRM_LEVEL"
// 	});
// 	dsldStream_var2_Property = CxvPropertyDeclaration.Register("dsldStream_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.STREAM_LEVEL"
// 	});
// 	dsldPhysical_var1_Property = CxvPropertyDeclaration.Register("dsldPhysical_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_PROP_LEVEL"
// 	});
// 	dsldPhysical_var2_Property = CxvPropertyDeclaration.Register("dsldPhysical_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.PROP_LEVEL"
// 	});
// 	dsldSimulation_var1_Property = CxvPropertyDeclaration.Register("dsldSimulation_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_SIM_LEVEL"
// 	});
// 	dsldSimulation_var2_Property = CxvPropertyDeclaration.Register("dsldSimulation_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.SIM_LEVEL"
// 	});
// 	dsldInputTrans_var1_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var1", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_SYS_LEVEL"
// 	});
// 	dsldInputTrans_var2_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var2", typeof(MMSetup_Setup_Diagno_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.SYS_LEVEL"
// 	});
// }

// 0x060002a8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Dialog_ViewModel..ctor
// public MMSetup_Setup_Dialog_ViewModel()
// {
// }

// 0x060002a9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Dialog_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Dialog_ViewModel()
// {
// 	dsldFortran_var1_Property = CxvPropertyDeclaration.Register("dsldFortran_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.TVAR_LEVEL"
// 	});
// 	dsldFortran_var2_Property = CxvPropertyDeclaration.Register("dsldFortran_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.VAR_LEVEL"
// 	});
// 	dsldCost_var1_Property = CxvPropertyDeclaration.Register("dsldCost_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_COST_LEVEL"
// 	});
// 	dsldCost_var2_Property = CxvPropertyDeclaration.Register("dsldCost_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.COST_LEVEL"
// 	});
// 	dsldEcono_var1_Property = CxvPropertyDeclaration.Register("dsldEcono_var1", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.T_ECON_LEVEL"
// 	});
// 	dsldEcono_var2_Property = CxvPropertyDeclaration.Register("dsldEcono_var2", typeof(MMSetup_Setup_Dialog_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.ECON_LEVEL"
// 	});
// }

// 0x060002bc AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Global_ViewModel..ctor
// public MMSetup_Setup_Global_ViewModel()
// {
// }

// 0x060002bd AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Global_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Global_ViewModel()
// {
// 	MMLBUOpyr_var1_Property = CxvPropertyDeclaration.Register("MMLBUOpyr_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.Input.OPER_YEAR"
// 	});
// 	MMLBUOpyr_var2_Property = CxvPropertyDeclaration.Register("MMLBUOpyr_var2", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.OPER_YEAR"
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Main.Input.FREE_WATER"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Dirty water",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Dirty_water",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	LbtuTamb_tambeqp_Property = CxvPropertyDeclaration.Register("LbtuTamb_tambeqp", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.Input.TAMBEQP",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Main.CC Nodes.ENTAMB"
// 		}
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Global.Input.SCLASS"
// 	});
// 	MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox4_var1",
// 				DataPath = "@main.Global.Input.BASIS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mass",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Mass",
// 				Value = "MMComboBox4_MultiMapOption_1",
// 				Prompt = "Mass flow.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Mass_flow_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "MASS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mole",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Mole",
// 				Value = "MMComboBox4_MultiMapOption_2",
// 				Prompt = "Mole flow.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Mole_flow_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "MOLE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "StdVol",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_StdVol",
// 				Value = "MMComboBox4_MultiMapOption_3",
// 				Prompt = "Standard volume flow.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Standard_volume_flow_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "STDVOL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.Input.ATM_PRES"
// 	});
// 	lbtuTemp_var2_Property = CxvPropertyDeclaration.Register("lbtuTemp_var2", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ATM_PRES"
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Main.Input.RUN_CLASS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Assay Data Analysis",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Assay_Data_Analysis",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "ADA"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Data Regression",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Data_Regression",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "DRS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Flowsheet",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Flowsheet",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "FLOWSHEET"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Properties Plus",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Properties_Plus",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "PROP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Property Analysis",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Property_Analysis",
// 				Value = "MMComboBox1_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "TGS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Property Estimation",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Property_Estimation",
// 				Value = "MMComboBox1_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "PCES"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboInpMode_var1_Property = CxvPropertyDeclaration.Register("cboInpMode_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Main.Input.INPUT_MODE",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	lbtuTitle_var1_Property = CxvPropertyDeclaration.Register("lbtuTitle_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.Input.TITLE"
// 	});
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSetup_Setup_Global_ViewModel), new CxvMultiMapProperty
// 	{
// 		Prompt = "Valid phases to be considered in calculations. If left blank, the default is block-dependent. See Valid Phases in individual blocks for details.",
// 		PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapProperty_Prompt_Valid_phases_to_be_considered_in_calculations_",
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Sim-Options.Input.NPHASE"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Sim-Options.Input.PHASE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var2",
// 						Value = "V"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var2",
// 						Value = "L"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var1",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSetup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var1",
// 						Value = "3"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var2"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboInputData_var1_Property = CxvPropertyDeclaration.Register("cboInputData_var1", typeof(MMSetup_Setup_Global_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Global.Input.INSET",
// 		AllowNew = false
// 	});
// }

// 0x060002c5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Histor_ViewModel..ctor
// public MMSetup_Setup_Histor_ViewModel()
// {
// }

// 0x060002c6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Setup_Histor_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Setup_Histor_ViewModel()
// {
// 	chkEchoInsert_var1_Property = CxvPropertyDeclaration.Register("chkEchoInsert_var1", typeof(MMSetup_Setup_Histor_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.INSERT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Setup_Histor_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.SORTED",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// }

// 0x060002db AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_ViewModel..ctor
// public MMSetup_Simopt_ViewModel()
// {
// }

// 0x060002dc AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_ViewModel()
// {
// 	calc_Property = CxvPropertyDeclaration.Register("calc", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.MAIN"
// 	});
// 	entclc_Property = CxvPropertyDeclaration.Register("entclc", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTCALC"
// 	});
// 	entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTFLASH"
// 	});
// 	entsys_Property = CxvPropertyDeclaration.Register("entsys", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sys-Options.CC Nodes.ENTSYSTEM"
// 	});
// 	entlim_Property = CxvPropertyDeclaration.Register("entlim", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Control.CC Nodes.ENTLIMIT"
// 	});
// 	entmx_Property = CxvPropertyDeclaration.Register("entmx", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.CC Nodes.ENTMAX"
// 	});
// 	entrea_Property = CxvPropertyDeclaration.Register("entrea", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTREAC"
// 	});
// 	entsmlim_Property = CxvPropertyDeclaration.Register("entsmlim", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTSMLIM"
// 	});
// 	entresl_Property = CxvPropertyDeclaration.Register("entresl", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.CC Nodes.ENTRESL"
// 	});
// 	entmodop_Property = CxvPropertyDeclaration.Register("entmodop", typeof(MMSetup_Simopt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Model-Option.CC Nodes.ENTMODOP"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entclc" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@calc" },
// 		EnteredDataPaths = { "@entfls" }
// 	});
// 	tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entmodop" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entresl" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entsys" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entlim", "@entmx", "@entsmlim" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSetup_Simopt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entrea" }
// 	});
// }

// 0x060002f1 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Calcul_ViewModel..ctor
// public MMSetup_Simopt_Calcul_ViewModel()
// {
// }

// 0x060002f2 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Calcul_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_Simopt_Calcul_ViewModel()
// {
// 	MMLBUText2_var2_Property = CxvPropertyDeclaration.Register("MMLBUText2_var2", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.REF_TEMP"
// 	});
// 	MMLBUText3_var3_Property = CxvPropertyDeclaration.Register("MMLBUText3_var3", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.REF_PRES"
// 	});
// 	lbtuInitgparam_var1_Property = CxvPropertyDeclaration.Register("lbtuInitgparam_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.INIT_GPARAM"
// 	});
// 	MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.DUMPXML",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ADSCNVG",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMComboBox1_var1_Multimap_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ComboBox1_var1",
// 				DataPath = "@main.Sim-Options.Input.PACKING_DB"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Latest",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_latest_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "LATEST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "V2006",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v2006_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "V2006"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "V2006.5",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v2006_5_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "V2006.5"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "V7",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v7_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "V7"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "V7.2",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v7_2_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "V7.2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "V9.0",
// 				Prompt = ApwnComboPromptResource.setup_sim_options_packing_db_v9_0_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ComboBox1_var1",
// 						Value = "V9.0"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	chkDBChk_var1_Property = CxvPropertyDeclaration.Register("chkDBChk_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.OLD_DATABANK",
// 		TrueValue = "YES",
// 		FalseValue = "NO"
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PROP_DERIV",
// 		TrueValue = "ANALYTICAL",
// 		FalseValue = "NUMERICAL",
// 		DefaultValue = true
// 	});
// 	MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.DN_REQUIRED",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.DX_REQUIRED",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.SOLID_DERIV",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox5_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox5_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ENG_ELECPAR",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	lbtuXwH2ophase_var1_Property = CxvPropertyDeclaration.Register("lbtuXwH2ophase_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.XW_H2OPHASE"
// 	});
// 	chkBypass_var1_Property = CxvPropertyDeclaration.Register("chkBypass_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.BYPASS_PROP",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	chkRestart_var1_Property = CxvPropertyDeclaration.Register("chkRestart_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.RESTART",
// 		TrueValue = "NO",
// 		FalseValue = "YES",
// 		DefaultValue = true
// 	});
// 	chkMwCalc_var1_Property = CxvPropertyDeclaration.Register("chkMwCalc_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.MW_CALC",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	chkEnryBal_var1_Property = CxvPropertyDeclaration.Register("chkEnryBal_var1", typeof(MMSetup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ENERGY_BAL",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// }

// 0x06000307 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Flashc_ViewModel..ctor
// public MMSetup_Simopt_Flashc_ViewModel()
// {
// }

// 0x06000308 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Flashc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_Flashc_ViewModel()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.FLASH_PSEUDO",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	cboFlashMethod_MultiMap_Property = CxvPropertyDeclaration.Register("cboFlashMethod_MultiMap", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboFlashMethod_var1",
// 				DataPath = "@main.Sim-Options.Input.FLASH_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Inside-Out",
// 				DisplayResourceKey = "MMSetup_Simopt_Flashc_ViewModel__CxvMultiMapOption_Display_Inside_Out",
// 				Value = "cboFlashMethod_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboFlashMethod_var1",
// 						Value = "INSIDE-OUT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Gibbs",
// 				DisplayResourceKey = "MMSetup_Simopt_Flashc_ViewModel__CxvMultiMapOption_Display_Gibbs",
// 				Value = "cboFlashMethod_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboFlashMethod_var1",
// 						Value = "GIBBS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_User",
// 				Value = "cboFlashMethod_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboFlashMethod_var1",
// 						Value = "USER"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.NEW_SPLIT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.FLASH3_OPT",
// 		TrueValue = "4PHASE",
// 		FalseValue = "3PHASE",
// 		DefaultValue = false
// 	});
// 	MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.HF_FL3_DAMP",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.MAXSOL_CHECK",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.REFP_FLASH",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.TOL"
// 	});
// 	lbtuTolFac_var1_Property = CxvPropertyDeclaration.Register("lbtuTolFac_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.FLASH_TOLFAC"
// 	});
// 	lbtuMinTol_var1_Property = CxvPropertyDeclaration.Register("lbtuMinTol_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.FLASH_MINTOL"
// 	});
// 	lbtuMaxitx_var1_Property = CxvPropertyDeclaration.Register("lbtuMaxitx_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.FLASH_MAXITX"
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.MAXIT"
// 	});
// 	lbtuRootExtr_var1_Property = CxvPropertyDeclaration.Register("lbtuRootExtr_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ROOT_EXTR"
// 	});
// 	lbtuLowPres_var1_Property = CxvPropertyDeclaration.Register("lbtuLowPres_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PLOWER"
// 	});
// 	lbtuUpPres_var1_Property = CxvPropertyDeclaration.Register("lbtuUpPres_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PUPPER"
// 	});
// 	lbtuLowTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuLowTemp_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.TLOWER"
// 	});
// 	lbtuUpTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuUpTemp_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.TUPPER"
// 	});
// }

// 0x06000315 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Limits_ViewModel..ctor
// public MMSetup_Simopt_Limits_ViewModel()
// {
// }

// 0x06000316 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Limits_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_Limits_ViewModel()
// {
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PACK_FRAC"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PACK_FLOW"
// 	});
// 	MMSpinBox4_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox4_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.PROP_LIMIT"
// 	});
// 	MMSpinBox2_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox2_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.SYS_LIMIT"
// 	});
// 	MMSpinBox3_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox3_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Diagnostics.Input.SIM_LIMIT"
// 	});
// 	MMSpinBox1_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox1_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Control.Input.MAX_FORT_ERR"
// 	});
// 	lbtuMaxTime_var1_Property = CxvPropertyDeclaration.Register("lbtuMaxTime_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Control.Input.MAX_TIME"
// 	});
// 	spnSevErr_var1_Property = CxvPropertyDeclaration.Register("spnSevErr_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Control.Input.MAX_ERRORS"
// 	});
// 	MMSpinBox6_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox6_var1", typeof(MMSetup_Simopt_Limits_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Run-Control.Input.MAX_FILESIZE"
// 	});
// }

// 0x0600031e AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Reactions_ViewModel..ctor
// public MMSetup_Simopt_Reactions_ViewModel()
// {
// }

// 0x0600031f AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Reactions_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_Reactions_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.ELEC_CHK_TOL"
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_gamusbasis",
// 				DataPath = "@main.Sim-Options.Input.GAMUS_BASIS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aqueous",
// 				DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Aqueous",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_gamusbasis",
// 						Value = "AQUEOUS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mixed-Solvent",
// 				DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Mixed_Solvent",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_gamusbasis",
// 						Value = "MIXED-SOLVENT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	ogrStioMbChe_MultiMap_Property = CxvPropertyDeclaration.Register("ogrStioMbChe_MultiMap", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrStioMbChe_var1",
// 				DataPath = "@main.Sim-Options.Input.STOIC_MB_CHE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Issue error when mass imbalance occurs",
// 				DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Issue_error_when_mass_imbalance_occurs",
// 				Value = "ogrStioMbChe_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrStioMbChe_var1",
// 						Value = "ERROR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Issue warning when mass imbalance occurs",
// 				DisplayResourceKey = "MMSetup_Simopt_Reactions_ViewModel__CxvMultiMapOption_Display_Issue_warning_when_mass_imbalance_occu",
// 				Value = "ogrStioMbChe_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrStioMbChe_var1",
// 						Value = "WARNING"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuStoicTol_var1_Property = CxvPropertyDeclaration.Register("lbtuStoicTol_var1", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.STOIC_MB_TOL"
// 	});
// }

// 0x06000331 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Result_ViewModel..ctor
// public MMSetup_Simopt_Result_ViewModel()
// {
// }

// 0x06000332 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_Result_ViewModel()
// {
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.MASS_BAL_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Sim-Options.CC Nodes.MASSCK"
// 		}
// 	});
// 	MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.MASS_BAL_CHE",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.VLLE_CHECK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.VLE_CHECK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PEQ_CHK_FRAC"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.PEQ_CHK_TOL"
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.PEQ_CHECK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.SLE_CHECK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.SVE_CHECK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.SOLTHRESHOLD"
// 	});
// 	chkPhaseStab_var1_Property = CxvPropertyDeclaration.Register("chkPhaseStab_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Sim-Options.Input.FL_STAB_CHK",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	StabChkThr_var1_Property = CxvPropertyDeclaration.Register("StabChkThr_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.STAB_CHK_THR"
// 	});
// 	StabMinFrc_var1_Property = CxvPropertyDeclaration.Register("StabMinFrc_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.STAB_MIN_FRC"
// 	});
// 	StabMaxFrc_var1_Property = CxvPropertyDeclaration.Register("StabMaxFrc_var1", typeof(MMSetup_Simopt_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Sim-Options.Input.STAB_MAX_FRC"
// 	});
// }

// 0x0600033a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_System_ViewModel..ctor
// public MMSetup_Simopt_System_ViewModel()
// {
// }

// 0x0600033b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Simopt_System_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Simopt_System_ViewModel()
// {
// 	MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sys-Options.Input.TRACE",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	chkBlkChk_var1_Property = CxvPropertyDeclaration.Register("chkBlkChk_var1", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sys-Options.Input.BLOCK_CHECK",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	ChkStrmProp_Property = CxvPropertyDeclaration.Register("ChkStrmProp", typeof(MMSetup_Simopt_System_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Sys-Options.Input.STRPP_CHECK",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	ogrInterpret_MultiMap_Property = CxvPropertyDeclaration.Register("ogrInterpret_MultiMap", typeof(MMSetup_Simopt_System_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrInterpret_var1",
// 				DataPath = "@main.Sys-Options.Input.INTERPRET"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Interpret all inline Fortran statements at execution time",
// 				DisplayResourceKey = "MMSetup_Simopt_System_ViewModel__CxvMultiMapOption_Display_Interpret_all_inline_Fortran_statements_a",
// 				Value = "ogrInterpret_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrInterpret_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Write inline Fortran to a subroutine to be compiled and dynamically linked",
// 				DisplayResourceKey = "MMSetup_Simopt_System_ViewModel__CxvMultiMapOption_Display_Write_inline_Fortran_to_a_subroutine_to_b",
// 				Value = "ogrInterpret_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrInterpret_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000343 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_ViewModel..ctor
// public MMSetup_SPInput_ViewModel()
// {
// }

// 0x06000344 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_SPInput_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSetup_SPInput_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC"
// 	});
// 	entn_Property = CxvPropertyDeclaration.Register("entn", typeof(MMSetup_SPInput_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTN"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_SPInput_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" },
// 		EnteredDataPaths = { "@entn" }
// 	});
// }

// 0x0600034d AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_Input_ViewModel..ctor
// public MMSetup_SPInput_Input_ViewModel()
// {
// }

// 0x0600034e AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_SPInput_Input_ViewModel()
// {
// 	grdStreamPrice_GridData_Property = CxvPropertyDeclaration.Register("grdStreamPrice_GridData", typeof(MMSetup_SPInput_Input_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreamPrice_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PRICE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000354 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_ViewModel..ctor
// public MMSetup_SPResult_ViewModel()
// {
// }

// 0x06000355 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_SPResult_ViewModel()
// {
// 	cost_Property = CxvPropertyDeclaration.Register("cost", typeof(MMSetup_SPResult_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COST"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_SPResult_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@cost" }
// 	});
// }

// 0x0600035f AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_Result_ViewModel..ctor
// public MMSetup_SPResult_Result_ViewModel()
// {
// }

// 0x06000360 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_SPResult_Result_ViewModel()
// {
// 	MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MOLE_PRICE"
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MASS_PRICE"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.VOL_PRICE"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.STDVOL_PRICE"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COST"
// 	});
// 	grdStreamPrice_GridData_Property = CxvPropertyDeclaration.Register("grdStreamPrice_GridData", typeof(MMSetup_SPResult_Result_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreamPrice_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COST",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x0600036e AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_ViewModel..ctor
// public MMSetup_Stratt_ViewModel()
// {
// }

// 0x0600036f AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Stratt_ViewModel()
// {
// 	subsmain_Property = CxvPropertyDeclaration.Register("subsmain", typeof(MMSetup_Stratt_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "subsmain"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PSD" },
// 		AccessibleDataPaths = { "@RUNFLOWSH" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@DEFSUB" },
// 		AccessibleDataPaths = { "@RUNFLOWSH" },
// 		EnteredDataPaths = { "@SUBSE" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Stratt_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@SUBSE", "@entsele" }
// 	});
// 	PSD_Property = CxvPropertyDeclaration.Register("PSD", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Subs-Attr.@id.CC Nodes.MN1"
// 	});
// 	attre_Property = CxvPropertyDeclaration.Register("attre", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Subs-Attr.@id.CC Nodes.ATTRE"
// 	});
// 	RUNFLOWSH_Property = CxvPropertyDeclaration.Register("RUNFLOWSH", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Main.CC Nodes.RUNFLOWSH"
// 	});
// 	DEFSUB_Property = CxvPropertyDeclaration.Register("DEFSUB", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Substreams.CC Nodes.MN2"
// 	});
// 	SUBSE_Property = CxvPropertyDeclaration.Register("SUBSE", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Stream-Class.Substreams.CC Nodes.SUBSE"
// 	});
// 	entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MMSetup_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.@parent.Components.Moisture-Comps.CC Nodes.ENTSELE"
// 	});
// }

// 0x06000385 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Subatt_ViewModel..ctor
// public MMSetup_Stratt_Subatt_ViewModel()
// {
// }

// 0x06000386 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Subatt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_Stratt_Subatt_ViewModel()
// {
// 	NUMROW_Property = CxvPropertyDeclaration.Register("NUMROW", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVALS",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.EXINT"
// 		}
// 	});
// 	txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVAL.@y"
// 	});
// 	MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZ2.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
// 		}
// 	});
// 	lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZE.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
// 		}
// 	});
// 	txtIntervals_var1_Property = CxvPropertyDeclaration.Register("txtIntervals_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVALS"
// 	});
// 	lbtuSizeUnits_var1_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PARTICLESIZE",
// 		ExtraDataPaths = { "@main.Input.PARTICLESIZ2", "@main.Input.LOWER", "@main.Input.UPPER" },
// 		VariablePrompt = "Size units",
// 		VariablePromptResourceKey = "MMSetup_Stratt_Subatt_ViewModel__unit_prompt"
// 	});
// 	lbtuSizeUnits_var2_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var2", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PARTICLESIZ2"
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Input.TYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Equidistant",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Equidistant",
// 				Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_equidistant_prompt,
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "EQUIDISTANT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Geometric",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Geometric",
// 				Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_geometric_prompt,
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "GEOMETRIC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Logarithmic",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Logarithmic",
// 				Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_logarithmic_prompt,
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "LOGARITHMIC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_User",
// 				Prompt = ApwnComboPromptResource.stream_class_subs_attr_psd_type_user_prompt,
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "USER"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	geoDiscretization_var1_Property = CxvPropertyDeclaration.Register("geoDiscretization_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.Q",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.ISGEO"
// 		}
// 	});
// 	spnIntervals_var1_Property = CxvPropertyDeclaration.Register("spnIntervals_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVALS",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EXINT1"
// 		}
// 	});
// 	txtUpper_var_Property = CxvPropertyDeclaration.Register("txtUpper_var", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.LIMIT"
// 		}
// 	});
// 	txtLower_var_Property = CxvPropertyDeclaration.Register("txtLower_var", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LOWER",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.LIMIT"
// 		}
// 	});
// 	cmdCreateMesh_var1_Property = CxvPropertyDeclaration.Register("cmdCreateMesh_var1", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CMESH"
// 		}
// 	});
// 	grdAttribute_GridData_Property = CxvPropertyDeclaration.Register("grdAttribute_GridData", typeof(MMSetup_Stratt_Subatt_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAttribute_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.INTERVAL",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060003a3 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_ViewModel..ctor
// public MMSetup_Strcla_ViewModel()
// {
// }

// 0x060003a4 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_ViewModel()
// {
// 	SCLASS_Property = CxvPropertyDeclaration.Register("SCLASS", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SCLASS"
// 	});
// 	DEFSUB_Property = CxvPropertyDeclaration.Register("DEFSUB", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Substreams.CC Nodes.MN2"
// 	});
// 	STRCLA_Property = CxvPropertyDeclaration.Register("STRCLA", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN3"
// 	});
// 	subse_Property = CxvPropertyDeclaration.Register("subse", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Substreams.CC Nodes.SUBSE"
// 	});
// 	strcle_Property = CxvPropertyDeclaration.Register("strcle", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.STRCLE"
// 	});
// 	runflowsh_Property = CxvPropertyDeclaration.Register("runflowsh", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.RUNFLOWSH"
// 	});
// 	defstrmain_Property = CxvPropertyDeclaration.Register("defstrmain", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "defstrmain"
// 	});
// 	_class_Property = CxvPropertyDeclaration.Register("_class", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "_class"
// 	});
// 	main2_Property = CxvPropertyDeclaration.Register("main2", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main2"
// 	});
// 	defs_Property = CxvPropertyDeclaration.Register("defs", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.DEFS"
// 	});
// 	entopt_Property = CxvPropertyDeclaration.Register("entopt", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.ENTOPT"
// 	});
// 	ENTSECT_Property = CxvPropertyDeclaration.Register("ENTSECT", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Main.CC Nodes.ENTSECT"
// 	});
// 	mn3_Property = CxvPropertyDeclaration.Register("mn3", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN3"
// 	});
// 	DEF2_Property = CxvPropertyDeclaration.Register("DEF2", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.DEF2"
// 	});
// 	ENTLOAD_Property = CxvPropertyDeclaration.Register("ENTLOAD", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.ENTLOAD"
// 	});
// 	hclass_Property = CxvPropertyDeclaration.Register("hclass", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "hclass"
// 	});
// 	load_Property = CxvPropertyDeclaration.Register("load", typeof(MMSetup_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "load"
// 	});
// 	MN1_Property = CxvPropertyDeclaration.Register("MN1", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@load.CC Nodes.MN1"
// 	});
// 	ENTNPOINT_Property = CxvPropertyDeclaration.Register("ENTNPOINT", typeof(MMSetup_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Attributes.LOAD.CC Nodes.ENTNPOINT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ENTSECT" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@defs" },
// 		EnteredDataPaths = { "@entopt" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@mn3" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSetup_Strcla_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@MN1" },
// 		EnteredDataPaths = { "@ENTLOAD", "@ENTNPOINT" }
// 	});
// }

// 0x060003b0 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defstr_ViewModel..ctor
// public MMSetup_Strcla_Defstr_ViewModel()
// {
// }

// 0x060003b1 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defstr_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_Defstr_ViewModel()
// {
// 	mnbStreamCl_var2_Property = CxvPropertyDeclaration.Register("mnbStreamCl_var2", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "_class"
// 	});
// 	mnbStreamCl_DEF1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_DEF1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.DEF1"
// 	});
// 	mnbStreamCl_ENTOPT1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_ENTOPT1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@defstrmain.CC Nodes.ENTOPT1"
// 	});
// 	lstStreams_state_Property = CxvPropertyDeclaration.Register("lstStreams_state", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "_class",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lstStreams_var1_Property = CxvPropertyDeclaration.Register("lstStreams_var1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@defstrmain.Input.SLIST.@_class",
// 		AllowSort = false
// 	});
// 	mnbStreamCl_var1_Property = CxvPropertyDeclaration.Register("mnbStreamCl_var1", typeof(MMSetup_Strcla_Defstr_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@defstrmain.Input.SCLASS",
// 		SelectedItemBinding = "mnbStreamCl_var2.Value",
// 		CreateNewPrompt = "Stream class:",
// 		CreateNewPromptResourceKey = "MMSetup_Strcla_Defstr_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_class_",
// 		CompletePaths = { "@defstrmain.CC Nodes.DEF1" },
// 		EnteredPaths = { "@defstrmain.CC Nodes.ENTOPT1" },
// 		DisplayValues = true
// 	});
// }

// 0x060003b8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defsub_ViewModel..ctor
// public MMSetup_Strcla_Defsub_ViewModel()
// {
// }

// 0x060003b9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defsub_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_Defsub_ViewModel()
// {
// 	fraDefSubstream_subsmain_Property = CxvPropertyDeclaration.Register("fraDefSubstream_subsmain", typeof(MMSetup_Strcla_Defsub_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "subsmain"
// 	});
// 	grdDefSubstream_GridData_Property = CxvPropertyDeclaration.Register("grdDefSubstream_GridData", typeof(MMSetup_Strcla_Defsub_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdDefSubstream_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060003c0 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Flowsh_ViewModel..ctor
// public MMSetup_Strcla_Flowsh_ViewModel()
// {
// }

// 0x060003c1 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Flowsh_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_Flowsh_ViewModel()
// {
// 	fraSection_flsmain_Property = CxvPropertyDeclaration.Register("fraSection_flsmain", typeof(MMSetup_Strcla_Flowsh_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "flsmain"
// 	});
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_Strcla_Flowsh_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main2",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		}
// 	});
// }

// 0x060003c9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Load_ViewModel..ctor
// public MMSetup_Strcla_Load_ViewModel()
// {
// }

// 0x060003ca AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Load_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_Load_ViewModel()
// {
// 	spnMaxLoadPoints_NPOINT_Property = CxvPropertyDeclaration.Register("spnMaxLoadPoints_NPOINT", typeof(MMSetup_Strcla_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.AppModelV8.Setup.Stream-Class.Stream-Attributes.LOAD.Input.NPOINT"
// 	});
// }

// 0x060003d7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Strcla_ViewModel..ctor
// public MMSetup_Strcla_Strcla_ViewModel()
// {
// 	_needUpdateCombos = true;
// 	base..ctor();
// }

// 0x060003d8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Strcla_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Strcla_Strcla_ViewModel()
// {
// 	mnbStreamClass_var2_Property = CxvPropertyDeclaration.Register("mnbStreamClass_var2", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SCLASS"
// 	});
// 	mnbStreamClass_mn4_Property = CxvPropertyDeclaration.Register("mnbStreamClass_mn4", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Class.CC Nodes.MN4"
// 	});
// 	mnbStreamClass_var1_Property = CxvPropertyDeclaration.Register("mnbStreamClass_var1", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Stream-Class.Stream-Class.Input.SUBSTREAMS",
// 		SelectedItemBinding = "mnbStreamClass_var2.Value",
// 		CreateNewPrompt = "Stream class:",
// 		CreateNewPromptResourceKey = "MMSetup_Strcla_Strcla_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_class_",
// 		CreateNewInputMask = 2,
// 		CompletePaths = { "@main.Stream-Class.Stream-Class.CC Nodes.MN4" }
// 	});
// 	lstpSubstreams_state_Property = CxvPropertyDeclaration.Register("lstpSubstreams_state", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SCLASS",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lstpSubstreams_var1_Property = CxvPropertyDeclaration.Register("lstpSubstreams_var1", typeof(MMSetup_Strcla_Strcla_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Stream-Class.Stream-Class.Input.SUBSTREAMS.@SCLASS"
// 	});
// }

// 0x060003f8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel.add_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060003f9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel.remove_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000400 AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel.add_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000401 AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel.remove_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000409 AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel..ctor
// public MMSetup_UnitObj_ViewModel()
// {
// }

// 0x0600040a AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_UnitObj_ViewModel()
// {
// 	cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "InsertChild"
// 	});
// 	cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "CopyChildren"
// 			}
// 		}
// 	});
// 	cmdHideCanExecuteProperty = CxvPropertyDeclaration.Register("cmdHideCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "HideChild"
// 			}
// 		}
// 	});
// 	cmdRevealCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRevealCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "RevealChild"
// 	});
// 	cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_UnitObj_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Equal,
// 		PropertyPath = "CanPaste",
// 		Value = true
// 	});
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_UnitObj_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main",
// 			UseChildId = true,
// 			ProxyRow = false,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000411 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_ViewModel..ctor
// public MMSetup_Units_ViewModel()
// {
// }

// 0x06000412 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_ViewModel()
// {
// 	var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMSetup_Units_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_Units_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@var1" }
// 	});
// }

// 0x0600042b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Concen_ViewModel..ctor
// public MMSetup_Units_Concen_ViewModel()
// {
// }

// 0x0600042c AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Concen_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Concen_ViewModel()
// {
// 	MMComboBox78_var1_Property = CxvPropertyDeclaration.Register("MMComboBox78_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.COMPOSITION",
// 		Sorted = true
// 	});
// 	MMComboBox18_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_1_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS",
// 		Sorted = true
// 	});
// 	MMComboBox24_var1_Property = CxvPropertyDeclaration.Register("MMComboBox24_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLES",
// 		Sorted = true
// 	});
// 	MMComboBox43_var1_Property = CxvPropertyDeclaration.Register("MMComboBox43_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ENERGY",
// 		Sorted = true
// 	});
// 	MMComboBox42_var1_Property = CxvPropertyDeclaration.Register("MMComboBox42_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FORCE",
// 		Sorted = true
// 	});
// 	MMComboBox41_var1_Property = CxvPropertyDeclaration.Register("MMComboBox41_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.POWER",
// 		Sorted = true
// 	});
// 	MMComboBox40_var1_Property = CxvPropertyDeclaration.Register("MMComboBox40_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.WORK",
// 		Sorted = true
// 	});
// 	MMComboBox11_var1_Property = CxvPropertyDeclaration.Register("MMComboBox11_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.CURRENT",
// 		Sorted = true
// 	});
// 	MMComboBox12_var1_Property = CxvPropertyDeclaration.Register("MMComboBox12_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLTAGE",
// 		Sorted = true
// 	});
// 	MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.RESISTANCE",
// 		Sorted = true
// 	});
// 	MMComboBox14_var1_Property = CxvPropertyDeclaration.Register("MMComboBox14_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ELEC-POWER",
// 		Sorted = true
// 	});
// 	MMComboBox52_var1_Property = CxvPropertyDeclaration.Register("MMComboBox52_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.TIME",
// 		Sorted = true
// 	});
// 	MMComboBox51_var1_Property = CxvPropertyDeclaration.Register("MMComboBox51_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-TIME",
// 		Sorted = true
// 	});
// 	MMComboBox50_var1_Property = CxvPropertyDeclaration.Register("MMComboBox50_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.LN-INV-TIME",
// 		Sorted = true
// 	});
// 	MMComboBox77_var1_Property = CxvPropertyDeclaration.Register("MMComboBox77_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.CONTENTS",
// 		Sorted = true
// 	});
// 	MMComboBox76_var1_Property = CxvPropertyDeclaration.Register("MMComboBox76_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-CONC",
// 		Sorted = true
// 	});
// 	MMComboBox18_14_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_14_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-CONC",
// 		Sorted = true
// 	});
// 	MMComboBox18_13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_13_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.NUM-CONC",
// 		Sorted = true
// 	});
// 	MMComboBox75_var1_Property = CxvPropertyDeclaration.Register("MMComboBox75_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.NUM-CON-RATE",
// 		Sorted = true
// 	});
// 	MMComboBox74_var1_Property = CxvPropertyDeclaration.Register("MMComboBox74_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.POP-DENSITY",
// 		Sorted = true
// 	});
// 	MMComboBox79_var1_Property = CxvPropertyDeclaration.Register("MMComboBox79_var1", typeof(MMSetup_Units_Concen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-CONTENT",
// 		Sorted = true
// 	});
// }

// 0x06000442 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Curren_ViewModel..ctor
// public MMSetup_Units_Curren_ViewModel()
// {
// }

// 0x06000443 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Curren_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Curren_ViewModel()
// {
// 	cmbCostRate_var1_Property = CxvPropertyDeclaration.Register("cmbCostRate_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.COST-RATE",
// 		Sorted = true
// 	});
// 	cmbMolePrice_var1_Property = CxvPropertyDeclaration.Register("cmbMolePrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-PRICE",
// 		Sorted = true
// 	});
// 	cmbVolPrice_var1_Property = CxvPropertyDeclaration.Register("cmbVolPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLUME-PRICE",
// 		Sorted = true
// 	});
// 	cmbMassPrice_var1_Property = CxvPropertyDeclaration.Register("cmbMassPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.UNIT-PRICE",
// 		Sorted = true
// 	});
// 	cmbItemPrice_9_var1_Property = CxvPropertyDeclaration.Register("cmbItemPrice_9_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ITEM-PRICE",
// 		Sorted = true
// 	});
// 	cmbFiscal_10_var1_Property = CxvPropertyDeclaration.Register("cmbFiscal_10_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FISCAL",
// 		Sorted = true
// 	});
// 	cmbEngerPrice_var1_Property = CxvPropertyDeclaration.Register("cmbEngerPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ENERGY-PRICE",
// 		Sorted = true
// 	});
// 	cmbElecPrice_var1_Property = CxvPropertyDeclaration.Register("cmbElecPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ELEC-PRICE",
// 		Sorted = true
// 	});
// 	cmbAreaPrice_var1_Property = CxvPropertyDeclaration.Register("cmbAreaPrice_var1", typeof(MMSetup_Units_Curren_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.AREA-PRICE",
// 		Sorted = true
// 	});
// }

// 0x06000458 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Energy_ViewModel..ctor
// public MMSetup_Units_Energy_ViewModel()
// {
// }

// 0x06000459 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Energy_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Energy_ViewModel()
// {
// 	MMComboBox48_var1_Property = CxvPropertyDeclaration.Register("MMComboBox48_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-HEAT-CA",
// 		Sorted = true
// 	});
// 	MMComboBox49_var1_Property = CxvPropertyDeclaration.Register("MMComboBox49_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-HEAT-CA",
// 		Sorted = true
// 	});
// 	MMComboBox18_5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_5_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOL-HEAT-CAP",
// 		Sorted = true
// 	});
// 	MMComboBox36_var1_Property = CxvPropertyDeclaration.Register("MMComboBox36_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOL-ENTHALPY",
// 		Sorted = true
// 	});
// 	MMComboBox33_var1_Property = CxvPropertyDeclaration.Register("MMComboBox33_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-ENTHALP",
// 		Sorted = true
// 	});
// 	MMComboBox34_var1_Property = CxvPropertyDeclaration.Register("MMComboBox34_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-ENTHALP",
// 		Sorted = true
// 	});
// 	MMComboBox35_var1_Property = CxvPropertyDeclaration.Register("MMComboBox35_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ENTHALPY-FLO",
// 		Sorted = true
// 	});
// 	MMComboBox18_3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_3_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ENTHALPY",
// 		Sorted = true
// 	});
// 	MMComboBox37_var1_Property = CxvPropertyDeclaration.Register("MMComboBox37_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-ENTROPY",
// 		Sorted = true
// 	});
// 	MMComboBox38_var1_Property = CxvPropertyDeclaration.Register("MMComboBox38_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-ENTROPY",
// 		Sorted = true
// 	});
// 	MMComboBox39_var1_Property = CxvPropertyDeclaration.Register("MMComboBox39_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ENTROPY",
// 		Sorted = true
// 	});
// 	MMComboBox46_var1_Property = CxvPropertyDeclaration.Register("MMComboBox46_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.UA",
// 		Sorted = true
// 	});
// 	MMComboBox45_var1_Property = CxvPropertyDeclaration.Register("MMComboBox45_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-HT-C",
// 		Sorted = true
// 	});
// 	MMComboBox44_var1_Property = CxvPropertyDeclaration.Register("MMComboBox44_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.HEAT-TRANS-C",
// 		Sorted = true
// 	});
// 	MMComboBox18_6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_6_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.HEAT-FLUX",
// 		Sorted = true
// 	});
// 	MMComboBox47_var1_Property = CxvPropertyDeclaration.Register("MMComboBox47_var1", typeof(MMSetup_Units_Energy_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.HEAT",
// 		Sorted = true
// 	});
// }

// 0x06000469 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Miscel_ViewModel..ctor
// public MMSetup_Units_Miscel_ViewModel()
// {
// }

// 0x0600046a AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Miscel_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Miscel_ViewModel()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-EMISSIO",
// 		Sorted = true
// 	});
// 	MMComboBox59_var1_Property = CxvPropertyDeclaration.Register("MMComboBox59_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.WATER-RATE",
// 		Sorted = true
// 	});
// 	MMComboBox88_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox88_1_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOM-INERTIA",
// 		Sorted = true
// 	});
// 	MMComboBox84_var1_Property = CxvPropertyDeclaration.Register("MMComboBox84_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SOUND-LEVEL",
// 		Sorted = true
// 	});
// 	MMComboBox18_15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_15_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.CHROM-VEL",
// 		Sorted = true
// 	});
// 	MMComboBox82_var1_Property = CxvPropertyDeclaration.Register("MMComboBox82_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SOLVENT-PERM",
// 		Sorted = true
// 	});
// 	MMComboBox81_var1_Property = CxvPropertyDeclaration.Register("MMComboBox81_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SOLUTE-PERM",
// 		Sorted = true
// 	});
// 	MMComboBox73_var1_Property = CxvPropertyDeclaration.Register("MMComboBox73_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SPEC-FLT-RES",
// 		Sorted = true
// 	});
// 	MMComboBox87_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox87_0_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.BOND-WORK-IN",
// 		Sorted = true
// 	});
// 	MMComboBox86_var1_Property = CxvPropertyDeclaration.Register("MMComboBox86_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FILTER-RESIS",
// 		Sorted = true
// 	});
// 	MMComboBox15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox15_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FS",
// 		Sorted = true
// 	});
// 	MMComboBox16_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_var1", typeof(MMSetup_Units_Miscel_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FREQUENCY",
// 		Sorted = true
// 	});
// }

// 0x06000477 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Search_ViewModel..ctor
// public MMSetup_Units_Search_ViewModel()
// {
// }

// 0x06000478 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Search_ViewModel..cctor
// using System.Collections.Generic;
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMSetup_Units_Search_ViewModel()
// {
// 	unitname_Property = CxvPropertyDeclaration.Register("unitname", typeof(MMSetup_Units_Search_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "unitname"
// 	});
// 	txtUnitName_unitlabel_Property = CxvPropertyDeclaration.Register("txtUnitName_unitlabel", typeof(MMSetup_Units_Search_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "unitlabel"
// 	});
// 	MMComboBox46_var1_Property = CxvPropertyDeclaration.Register("MMComboBox46_var1", typeof(MMSetup_Units_Search_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.@unitname",
// 		Sorted = true
// 	});
// 	VarLabel = new List<string>
// 	{
// 		WpfFormsResources.MMSetup_Units_Search_acceleration,
// 		WpfFormsResources.MMSetup_Units_Search_Angle,
// 		WpfFormsResources.MMSetup_Units_Search_Area,
// 		WpfFormsResources.MMSetup_Units_Search_Area_price,
// 		WpfFormsResources.MMSetup_Units_Search_Area_usage,
// 		WpfFormsResources.MMSetup_Units_Search_Bond_work_index,
// 		WpfFormsResources.MMSetup_Units_Search_Chromatic_velocity,
// 		WpfFormsResources.MMSetup_Units_Search_Composition,
// 		WpfFormsResources.MMSetup_Units_Search_Cost_rate,
// 		WpfFormsResources.MMSetup_Units_Search_Content,
// 		WpfFormsResources.MMSetup_Units_Search_Current,
// 		WpfFormsResources.MMSetup_Units_Search_Delta_T,
// 		WpfFormsResources.MMSetup_Units_Search_Density,
// 		WpfFormsResources.MMSetup_Units_Search_Diffusivity,
// 		WpfFormsResources.MMSetup_Units_Search_Dimensionless,
// 		WpfFormsResources.MMSetup_Units_Search_Dipole_moment,
// 		WpfFormsResources.MMSetup_Units_Search_Electric_conductivity,
// 		WpfFormsResources.MMSetup_Units_Search_Electric_power,
// 		WpfFormsResources.MMSetup_Units_Search_Electric_price,
// 		WpfFormsResources.MMSetup_Units_Search_Energy,
// 		WpfFormsResources.MMSetup_Units_Search_Energy_price,
// 		WpfFormsResources.MMSetup_Units_Search_Energy_rate_per_volume,
// 		WpfFormsResources.MMSetup_Units_Search_Enthalpy,
// 		WpfFormsResources.MMSetup_Units_Search_Enthalpy_cycle,
// 		WpfFormsResources.MMSetup_Units_Search_Enthalpy_flow,
// 		WpfFormsResources.MMSetup_Units_Search_Enthalpy_opr,
// 		WpfFormsResources.MMSetup_Units_Search_Entropy,
// 		WpfFormsResources.MMSetup_Units_Search_F_factor,
// 		WpfFormsResources.MMSetup_Units_Search_Filter_resistance,
// 		WpfFormsResources.MMSetup_Units_Search_Fiscal,
// 		WpfFormsResources.MMSetup_Units_Search_Flow,
// 		WpfFormsResources.MMSetup_Units_Search_Flux,
// 		WpfFormsResources.MMSetup_Units_Search_Flux_heat_area,
// 		WpfFormsResources.MMSetup_Units_Search_Flux_mole,
// 		WpfFormsResources.MMSetup_Units_Search_Force,
// 		WpfFormsResources.MMSetup_Units_Search_Frequency,
// 		WpfFormsResources.MMSetup_Units_Search_Head,
// 		WpfFormsResources.MMSetup_Units_Search_Heat,
// 		WpfFormsResources.MMSetup_Units_Search_Heat_flux,
// 		WpfFormsResources.MMSetup_Units_Search_Heat_transfer_coef,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_THC,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_area,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_length,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_pressure,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_temperature,
// 		WpfFormsResources.MMSetup_Units_Search_Inverse_time,
// 		WpfFormsResources.MMSetup_Units_Search_inverse_vel,
// 		WpfFormsResources.MMSetup_Units_Search_Item_price,
// 		WpfFormsResources.MMSetup_Units_Search_Length,
// 		WpfFormsResources.MMSetup_Units_Search_Ln_inv_time,
// 		WpfFormsResources.MMSetup_Units_Search_Mass,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_conc,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_content,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_cycle,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_density,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_enthalpy,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_entropy,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_flow,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_flux,
// 		WpfFormsResources.MMSetup_Units_Search_MassFrac,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_heat_capacity,
// 		WpfFormsResources.MMSetup_Units_Search_MassLength,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_oper,
// 		WpfFormsResources.MMSetup_Units_Search_Mass_transfer_coef,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_conc,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_cycle,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_density,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_enthalpy,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_entropy,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_flow,
// 		WpfFormsResources.MMSetup_Units_Search_MoleFrac,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_heat_capacity,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_oper,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_reaction_rate_vol,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_reaction_rate_wt,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_volume,
// 		WpfFormsResources.MMSetup_Units_Search_Mole_flowLength,
// 		WpfFormsResources.MMSetup_Units_Search_Moles,
// 		WpfFormsResources.MMSetup_Units_Search_MoleWeight,
// 		WpfFormsResources.MMSetup_Units_Search_Moment_of_inertia,
// 		WpfFormsResources.MMSetup_Units_Search_Number_conc_rate,
// 		WpfFormsResources.MMSetup_Units_Search_Number_concentration,
// 		WpfFormsResources.MMSetup_Units_Search_Pack_factor,
// 		WpfFormsResources.MMSetup_Units_Search_Pdrop_per_ht,
// 		WpfFormsResources.MMSetup_Units_Search_Population_density,
// 		WpfFormsResources.MMSetup_Units_Search_Power,
// 		WpfFormsResources.MMSetup_Units_Search_PowerVolume,
// 		WpfFormsResources.MMSetup_Units_Search_Pdrop,
// 		WpfFormsResources.MMSetup_Units_Search_Pressure,
// 		WpfFormsResources.MMSetup_Units_Search_RhoV2,
// 		WpfFormsResources.MMSetup_Units_Search_Solubility_parameter,
// 		WpfFormsResources.MMSetup_Units_Search_Solute_permeability,
// 		WpfFormsResources.MMSetup_Units_Search_Solvent_permeability,
// 		WpfFormsResources.MMSetup_Units_Search_Sound_level,
// 		WpfFormsResources.MMSetup_Units_Search_Sp_filter_resistance,
// 		WpfFormsResources.MMSetup_Units_Search_Specific_area,
// 		WpfFormsResources.MMSetup_Units_Search_Surface_tension,
// 		WpfFormsResources.MMSetup_Units_Search_TemperatureVolume,
// 		WpfFormsResources.MMSetup_Units_Search_Temperature,
// 		WpfFormsResources.MMSetup_Units_Search_Thermal_conductivity,
// 		WpfFormsResources.MMSetup_Units_Search_Time,
// 		WpfFormsResources.MMSetup_Units_Search_UA,
// 		WpfFormsResources.MMSetup_Units_Search_Unit_price,
// 		WpfFormsResources.MMSetup_Units_Search_Velocity,
// 		WpfFormsResources.MMSetup_Units_Search_VflowLength,
// 		WpfFormsResources.MMSetup_Units_Search_VflowRPM,
// 		WpfFormsResources.MMSetup_Units_Search_Viscosity,
// 		WpfFormsResources.MMSetup_Units_Search_Voltage,
// 		WpfFormsResources.MMSetup_Units_Search_Volume,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_cycle,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_enthalpy,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_flow,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_heat_capacity,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_oper,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_price,
// 		WpfFormsResources.MMSetup_Units_Search_Volume_usage,
// 		WpfFormsResources.MMSetup_Units_Search_VolumeEnergy,
// 		WpfFormsResources.MMSetup_Units_Search_VolumeMass,
// 		WpfFormsResources.MMSetup_Units_Search_Water_rate,
// 		WpfFormsResources.MMSetup_Units_Search_Work
// 	};
// 	varnames = new List<string>
// 	{
// 		"ACCELERATION", "ANGLE", "AREA", "AREA-PRICE", "AREA-USAGE", "BOND-WORK-IN", "CHROM-VEL", "COMPOSITION", "COST-RATE", "CONTENTS",
// 		"CURRENT", "DELTA-T", "DENSITY", "DIFFUSIVITY", "DIMENSIONLES", "DIPOLEMOMENT", "SIEMENS-M", "ELEC-POWER", "ELEC-PRICE", "ENERGY",
// 		"ENERGY-PRICE", "HEAT-RATE-V", "ENTHALPY", "ENTHALPY-CYC", "ENTHALPY-FLO", "ENTHALPY-OPR", "ENTROPY", "F-FACTOR", "FILTER-RESIS", "FISCAL",
// 		"FLOW", "FLUX", "FLUX-HEAT-AR", "FLUX-MOLE", "FORCE", "FREQUENCY", "HEAD", "HEAT", "HEAT-FLUX", "HEAT-TRANS-C",
// 		"INVERSE-HT-C", "INVERSE-AREA", "INVERSE-LENG", "INVERSE-PRES", "INVERSE-TEMP", "INVERSE-TIME", "INVERSE-VEL", "ITEM-PRICE", "LENGTH", "LN-INV-TIME",
// 		"MASS", "MASS-CONC", "MASS-CONTENT", "MASS-CYCL", "MASS-DENSITY", "MASS-ENTHALP", "MASS-ENTROPY", "MASS-FLOW", "MASS-FLUX", "MASSFRAC",
// 		"MASS-HEAT-CA", "MASS-PER-LEN", "MASS-OPER", "MASS-TRANS-C", "MOLE-CONC", "MOLE-CYCL", "MOLE-DENSITY", "MOLE-ENTHALP", "MOLE-ENTROPY", "MOLE-FLOW",
// 		"MOLEFRAC", "MOLE-HEAT-CA", "MOLE-OPER", "MOLE-RXN-RAT", "MOL-RXN-RATW", "MOLE-VOLUME", "MOL-FLOW-LEN", "MOLES", "MOLE-WEIGHT", "MOM-INERTIA",
// 		"NUM-CON-RATE", "NUM-CONC", "PACK-FACTOR", "PDROP-PER-HT", "POP-DENSITY", "POWER", "POWER-VOLUME", "PDROP", "PRESSURE", "RHO-VSQRD",
// 		"SOLUPARAM", "SOLUTE-PERM", "SOLVENT-PERM", "SOUND-LEVEL", "SPEC-FLT-RES", "SPECIFICAREA", "SURFACE-TENS", "TEMP-VOLUME", "TEMPERATURE", "THERMAL-COND",
// 		"TIME", "UA", "UNIT-PRICE", "VELOCITY", "VFLOW-LENGTH", "VFLOW-RPM", "VISCOSITY", "VOLTAGE", "VOLUME", "VOLUME-CYCL",
// 		"VOL-ENTHALPY", "VOLUME-FLOW", "VOL-HEAT-CAP", "VOLUME-OPER", "VOLUME-PRICE", "VOLUME-USAGE", "ENERGY-VOL", "MASS-VOLUME", "WATER-RATE", "WORK"
// 	};
// 	scrSearch_GridData_Property = CxvPropertyDeclaration.Register("scrSearch_GridData", typeof(MMSetup_Units_Search_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(scrSearch_GridData_ItemTemplate),
// 		IndexBasis = new CxvFixedCountIndexBasis
// 		{
// 			FixedCount = 120,
// 			Name = "y"
// 		}
// 	});
// }

// 0x0600048d AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Sizing_ViewModel..ctor
// public MMSetup_Units_Sizing_ViewModel()
// {
// }

// 0x0600048e AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Sizing_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Sizing_ViewModel()
// {
// 	MMComboBox18_16_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_16_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.PACK-FACTOR",
// 		Sorted = true
// 	});
// 	MMComboBox83_var1_Property = CxvPropertyDeclaration.Register("MMComboBox83_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.F-FACTOR",
// 		Sorted = true
// 	});
// 	MMComboBox27_var1_Property = CxvPropertyDeclaration.Register("MMComboBox27_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.TEMP-VOLUME",
// 		Sorted = true
// 	});
// 	MMComboBox26_var1_Property = CxvPropertyDeclaration.Register("MMComboBox26_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.POWER-VOLUME",
// 		Sorted = true
// 	});
// 	MMComboBox25_var1_Property = CxvPropertyDeclaration.Register("MMComboBox25_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.AREA-USAGE",
// 		Sorted = true
// 	});
// 	MMComboBox24_11_var1_Property = CxvPropertyDeclaration.Register("MMComboBox24_11_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLUME-USAGE",
// 		Sorted = true
// 	});
// 	MMComboBox23_var1_Property = CxvPropertyDeclaration.Register("MMComboBox23_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOL-FLOW-LEN",
// 		Sorted = true
// 	});
// 	MMComboBox18_12_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_12_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.AREA",
// 		Sorted = true
// 	});
// 	MMComboBox19_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-AREA",
// 		Sorted = true
// 	});
// 	MMComboBox20_var1_Property = CxvPropertyDeclaration.Register("MMComboBox20_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-LENG",
// 		Sorted = true
// 	});
// 	MMComboBox21_var1_Property = CxvPropertyDeclaration.Register("MMComboBox21_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.LENGTH",
// 		Sorted = true
// 	});
// 	MMComboBox22_var1_Property = CxvPropertyDeclaration.Register("MMComboBox22_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SPECIFICAREA",
// 		Sorted = true
// 	});
// 	MMComboBox28_var1_Property = CxvPropertyDeclaration.Register("MMComboBox28_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SHORT-LENGTH",
// 		Sorted = true
// 	});
// 	MMComboBox29_var1_Property = CxvPropertyDeclaration.Register("MMComboBox29_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.WEIR-LOAD",
// 		Sorted = true
// 	});
// 	MMComboBox30_var1_Property = CxvPropertyDeclaration.Register("MMComboBox30_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.DOWNCOMER-LD",
// 		Sorted = true
// 	});
// 	MMComboBox31_var1_Property = CxvPropertyDeclaration.Register("MMComboBox31_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASSFL-AREA",
// 		Sorted = true
// 	});
// 	MMComboBox132_var1_Property = CxvPropertyDeclaration.Register("MMComboBox132_var1", typeof(MMSetup_Units_Sizing_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VELOCIT-FLUX",
// 		Sorted = true
// 	});
// }

// 0x060004a4 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Temper_ViewModel..ctor
// public MMSetup_Units_Temper_ViewModel()
// {
// }

// 0x060004a5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Temper_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Temper_ViewModel()
// {
// 	MMComboBox25_var1_Property = CxvPropertyDeclaration.Register("MMComboBox25_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-TEMP",
// 		Sorted = true
// 	});
// 	MMComboBox26_var1_Property = CxvPropertyDeclaration.Register("MMComboBox26_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.DELTA-T",
// 		Sorted = true
// 	});
// 	MMComboBox27_var1_Property = CxvPropertyDeclaration.Register("MMComboBox27_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.TEMPERATURE",
// 		Sorted = true
// 	});
// 	MMComboBox22_var1_Property = CxvPropertyDeclaration.Register("MMComboBox22_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-FLUX",
// 		Sorted = true
// 	});
// 	MMComboBox23_var1_Property = CxvPropertyDeclaration.Register("MMComboBox23_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FLUX",
// 		Sorted = true
// 	});
// 	MMComboBox18_2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_2_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.FLOW",
// 		Sorted = true
// 	});
// 	MMComboBox19_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLUME-FLOW",
// 		Sorted = true
// 	});
// 	MMComboBox20_var1_Property = CxvPropertyDeclaration.Register("MMComboBox20_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-FLOW",
// 		Sorted = true
// 	});
// 	MMComboBox21_var1_Property = CxvPropertyDeclaration.Register("MMComboBox21_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-FLOW",
// 		Sorted = true
// 	});
// 	MMComboBox31_var1_Property = CxvPropertyDeclaration.Register("MMComboBox31_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-PRES",
// 		Sorted = true
// 	});
// 	MMComboBox32_var1_Property = CxvPropertyDeclaration.Register("MMComboBox32_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.HEAD",
// 		Sorted = true
// 	});
// 	MMComboBox30_var1_Property = CxvPropertyDeclaration.Register("MMComboBox30_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.PDROP-PER-HT",
// 		Sorted = true
// 	});
// 	MMComboBox29_var1_Property = CxvPropertyDeclaration.Register("MMComboBox29_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.PDROP",
// 		Sorted = true
// 	});
// 	MMComboBox28_var1_Property = CxvPropertyDeclaration.Register("MMComboBox28_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.PRESSURE",
// 		Sorted = true
// 	});
// 	MMComboBox33_var1_Property = CxvPropertyDeclaration.Register("MMComboBox33_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLUME-GFLOW",
// 		Sorted = true
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Units_Temper_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.BASESET",
// 		AllowNew = false
// 	});
// }

// 0x060004bd AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Volume_ViewModel..ctor
// public MMSetup_Units_Volume_ViewModel()
// {
// }

// 0x060004be AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Volume_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_Units_Volume_ViewModel()
// {
// 	MMComboBox53_var1_Property = CxvPropertyDeclaration.Register("MMComboBox53_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SOLUPARAM",
// 		Sorted = true
// 	});
// 	MMComboBox54_var1_Property = CxvPropertyDeclaration.Register("MMComboBox54_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.DIPOLEMOMENT",
// 		Sorted = true
// 	});
// 	MMComboBox58_var1_Property = CxvPropertyDeclaration.Register("MMComboBox58_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.DIFFUSIVITY",
// 		Sorted = true
// 	});
// 	MMComboBox57_var1_Property = CxvPropertyDeclaration.Register("MMComboBox57_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-TRANS-C",
// 		Sorted = true
// 	});
// 	MMComboBox56_var1_Property = CxvPropertyDeclaration.Register("MMComboBox56_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SURFACE-TENS",
// 		Sorted = true
// 	});
// 	MMComboBox18_8_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_8_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.THERMAL-COND",
// 		Sorted = true
// 	});
// 	MMComboBox18_7_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_7_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VISCOSITY",
// 		Sorted = true
// 	});
// 	MMComboBox55_var1_Property = CxvPropertyDeclaration.Register("MMComboBox55_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VELOCITY",
// 		Sorted = true
// 	});
// 	MMComboBox16_1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_1_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-VOLUME",
// 		Sorted = true
// 	});
// 	MMComboBox17_var1_Property = CxvPropertyDeclaration.Register("MMComboBox17_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VOLUME",
// 		Sorted = true
// 	});
// 	MMComboBox16_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_0_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-VOLUME",
// 		Sorted = true
// 	});
// 	MMComboBox15_var1_Property = CxvPropertyDeclaration.Register("MMComboBox15_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.VFLOW-LENGTH",
// 		Sorted = true
// 	});
// 	MMComboBox18_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_0_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.DENSITY",
// 		Sorted = true
// 	});
// 	MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MASS-DENSITY",
// 		Sorted = true
// 	});
// 	MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.MOLE-DENSITY",
// 		Sorted = true
// 	});
// 	MMComboBox7_var1_Property = CxvPropertyDeclaration.Register("MMComboBox7_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.RHO-VSQRD",
// 		Sorted = true
// 	});
// 	CurrentDensity_var1_Property = CxvPropertyDeclaration.Register("CurrentDensity_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.CURRENT-DENS",
// 		Sorted = true
// 	});
// 	MMComboBox59_var1_Property = CxvPropertyDeclaration.Register("MMComboBox59_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.INVERSE-VEL",
// 		Sorted = true
// 	});
// 	MMComboBox60_var1_Property = CxvPropertyDeclaration.Register("MMComboBox60_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.ACCELERATION",
// 		Sorted = true
// 	});
// 	ElectConduct_var1_Property = CxvPropertyDeclaration.Register("ElectConduct_var1", typeof(MMSetup_Units_Volume_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Unit-Types.SIEMENS-M",
// 		Sorted = true
// 	});
// }

// 0x060004c5 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ViewModel..ctor
// public MMSetup_VarGroup_ViewModel()
// {
// }

// 0x060004c6 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_VarGroup_ViewModel()
// {
// 	spec1_Property = CxvPropertyDeclaration.Register("spec1", typeof(MMSetup_VarGroup_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC1"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSetup_VarGroup_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec1" }
// 	});
// }

// 0x06000532 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel..cctor
// using System.Windows.Media;
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_VarGroup_Define_ViewModel()
// {
// 	Disable_Plotvg_Property = CxvPropertyDeclaration.Register("Disable_Plotvg", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "p_IsSystemGenerate",
// 			Operator = CxvLogicalOperator.NotEqual,
// 			Value = "1"
// 		}
// 	});
// 	grdDefine_GridData_Property = CxvPropertyDeclaration.Register("grdDefine_GridData", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdDefine_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FVN_VARTYPE",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		}
// 	});
// 	expandar_define_Property = CxvPropertyDeclaration.Register("expandar_define", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvExpanderProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Parameter = "p_IsSystemGenerate",
// 			Operator = CxvLogicalOperator.NotEqual,
// 			Value = "1"
// 		}
// 	});
// 	mnuVarname_ListVar_Property = CxvPropertyDeclaration.Register("mnuVarname_ListVar", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FVN_VARIABLE",
// 		SelectedItemBinding = "mnuVarname_StoVar2.Value",
// 		CreateNewInputMask = 3,
// 		CompletePaths = { "@main.CC Nodes.SPEC" }
// 	});
// 	mnuVarname_StoVar2_Property = CxvPropertyDeclaration.Register("mnuVarname_StoVar2", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "xVarName"
// 	});
// 	optCategory_MultiMap_Property = CxvPropertyDeclaration.Register("optCategory_MultiMap", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "optCategory_var1",
// 				DataPath = "@main.Input.OPT_CATEG.@xInt"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "All",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_All",
// 				Value = "ALL",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "ALL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Blocks",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Blocks",
// 				Value = "BLOCK",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "BLOCK"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Streams",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "STREAM",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "STREAM"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Model Utility",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Model_Utility",
// 				Value = "MODUT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "MODUT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Property Parameters",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Physical_Property_Parameters",
// 				Value = "PROP",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "PROP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Reactions",
// 				DisplayResourceKey = "MMDesignSpe_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Reactions",
// 				Value = "REACT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "REACT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Sensors",
// 				DisplayResourceKey = "MMSensitivi_Input_VarWiz_ViewModel__CxvMultiMapOption_Display_Sensor",
// 				Value = "SENSOR",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optCategory_var1",
// 						Value = "SENSOR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboVarTypevw_var1_Property = CxvPropertyDeclaration.Register("cboVarTypevw_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.FVN_VARTYPE.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_0_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_0_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow0.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_0_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_0_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						Parameter = "RowsvwD_0_IsMixedCase",
// 						Value = "1"
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.@vwrow0.@xInt",
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DisplayedCase = CxsDisplayedCase.Lowercase,
// 					Sorted = true
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						Parameter = "RowsvwD_0_IsMixedCase",
// 						Value = "0"
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.@vwrow0.@xInt",
// 					ExposeAs = CxvVariableTypeCode.String,
// 					Sorted = true
// 				}
// 			}
// 		}
// 	});
// 	txtRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_1_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow1.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_1_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						Parameter = "RowsvwD_1_IsMixedCase",
// 						Value = "1"
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.@vwrow1.@xInt",
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DisplayedCase = CxsDisplayedCase.Lowercase,
// 					Sorted = true
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						Parameter = "RowsvwD_1_IsMixedCase",
// 						Value = "0"
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.@vwrow1.@xInt",
// 					ExposeAs = CxvVariableTypeCode.String,
// 					Sorted = true
// 				}
// 			}
// 		}
// 	});
// 	txtRowsvw_2_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_2_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow2.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_2_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_2_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow2.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_3_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_3_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow3.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_3_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_3_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow3.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_4_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_4_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow4.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_4_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_4_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow4.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_5_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_5_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow5.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_5_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_5_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow5.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_6_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_6_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow6.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_6_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_6_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow6.@xInt",
// 		Sorted = true
// 	});
// 	txtRowsvw_7_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_7_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow7.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_7_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_7_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow7.@xInt",
// 		Sorted = true
// 	});
// 	txtBlockVar_var1_Property = CxvPropertyDeclaration.Register("txtBlockVar_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow1.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Parameter = "p_BlockVarVisible",
// 			Value = "1"
// 		}
// 	});
// 	txtHybridVar_var1_Property = CxvPropertyDeclaration.Register("txtHybridVar_var1", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow1.@xInt",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Parameter = "p_HybridVarVisible",
// 			Value = "1"
// 		}
// 	});
// 	format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(MMSetup_VarGroup_Define_ViewModel), new CxvLineFormatProperty
// 	{
// 		DataPath = "@main.Input.FVN_LINESTYL.@xInt"
// 	});
// 	_definedColors = new Color[16]
// 	{
// 		Colors.Black,
// 		Colors.Navy,
// 		Colors.Green,
// 		Colors.Teal,
// 		Colors.Brown,
// 		Colors.Purple,
// 		Colors.DarkOliveGreen,
// 		Colors.Gray,
// 		Colors.DarkGray,
// 		Colors.Blue,
// 		Colors.LightGreen,
// 		Colors.SkyBlue,
// 		Colors.Red,
// 		Colors.Fuchsia,
// 		Colors.Yellow,
// 		Colors.LightGray
// 	};
// }

// 0x06000537 AspenTech.AspenPlus.MMForms.Setup.VRowMaskConverter..ctor
// public VRowMaskConverter()
// {
// }

// 0x0600054d AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel.add_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x0600054e AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel.remove_CanPasteChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.CanPasteChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.CanPasteChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000560 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel.add_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000561 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel.remove_AllSelectedRecordsCountChanged
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler eventHandler = this.AllSelectedRecordsCountChanged;
// 	EventHandler eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.AllSelectedRecordsCountChanged, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000566 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel..ctor
// public MMSetup_VarGroup_ObjManager_ViewModel()
// {
// }

// 0x06000567 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_VarGroup_ObjManager_ViewModel()
// {
// 	cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "InsertChild"
// 	});
// 	cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdCopyCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCopyCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				PropertyPath = "AllSelectedRecordsCount",
// 				Operator = CxvLogicalOperator.GreaterThan,
// 				Value = 0
// 			},
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main",
// 				Operator = CxvLogicalOperator.CanInvokeAction,
// 				Value = "CopyChildren"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Operator = CxvLogicalOperator.Equal,
// 				PropertyPath = "CanDuplicate",
// 				Value = true
// 			}
// 		}
// 	});
// 	cmdPaste_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdPaste_CommandCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Equal,
// 		PropertyPath = "CanPaste",
// 		Value = true
// 	});
// 	cmdExportCanExecuteProperty = CxvPropertyDeclaration.Register("cmdExportCanExecute", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMSetup_VarGroup_ObjManager_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main",
// 			UseChildId = true,
// 			ProxyRow = false,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000572 AspenTech.AspenPlus.MMForms.Setup.MMSetup_ViewDefinevariables_List_ViewModel..ctor
// public MMSetup_ViewDefinevariables_List_ViewModel()
// {
// }

// 0x06000573 AspenTech.AspenPlus.MMForms.Setup.MMSetup_ViewDefinevariables_List_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSetup_ViewDefinevariables_List_ViewModel()
// {
// 	grdViewvariable_GridData_Property = CxvPropertyDeclaration.Register("grdViewvariable_GridData", typeof(MMSetup_ViewDefinevariables_List_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdViewvariable_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FVN_VARTYPE",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x06000587 AspenTech.AspenPlus.MMForms.Setup.StreamGroupPriorityDlg..cctor
// using System.Collections.Generic;
// using System.Windows.Media;
// using AspenTech.AspenPlus.Localization;
// using AspenTech.Engineering.GridControls;
//
// static StreamGroupPriorityDlg()
// {
// 	_columns = new List<DataColumn>
// 	{
// 		new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Priority)
// 		{
// 			Width = 80.0
// 		},
// 		new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Name)
// 		{
// 			Width = 100.0
// 		},
// 		new DataColumn(ApwnResources.MMSetup_StreamGroups_StreamGroupPriorityDlg_Format)
// 		{
// 			Width = 200.0,
// 			IsReadOnly = true
// 		}
// 	};
// 	_definedColors = new Color[16]
// 	{
// 		Colors.Black,
// 		Colors.Navy,
// 		Colors.Green,
// 		Colors.Teal,
// 		Colors.Brown,
// 		Colors.Purple,
// 		Colors.DarkOliveGreen,
// 		Colors.Gray,
// 		Colors.DarkGray,
// 		Colors.Blue,
// 		Colors.LightGreen,
// 		Colors.SkyBlue,
// 		Colors.Red,
// 		Colors.Fuchsia,
// 		Colors.Yellow,
// 		Colors.LightGray
// 	};
// }

// 0x0600058e AspenTech.AspenPlus.MMForms.Setup.StreamGroupItem..ctor
// public StreamGroupItem()
// {
// }

// 0x060005a3 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel+grdChild_GridData_ItemTemplate..ctor
// using System.Collections.ObjectModel;
//
// public grdChild_GridData_ItemTemplate()
// {
// 	_allTemplateNames = new ObservableCollection<string>();
// 	base..ctor();
// }

// 0x060005a4 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_ObjManager_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.@y",
// 		SubObjectTypePath = "[]",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Operator = CxvLogicalOperator.Equal,
// 			PropertyPath = "CanRename",
// 			Value = true
// 		}
// 	});
// 	txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.DESCRIPTION"
// 	});
// 	format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(grdChild_GridData_ItemTemplate), new CxvLineFormatProperty
// 	{
// 		DataPath = "@main.@y.Input.LINESTYLE"
// 	});
// 	Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdChild_GridData_ItemTemplate), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.@y.Input.ACTIVE"
// 	});
// 	Priority_var_Property = CxvPropertyDeclaration.Register("Priority_var", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.PRIORITY",
// 		IsReadOnly = true
// 	});
// 	Template_var_Property = CxvPropertyDeclaration.Register("Template_var", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.SGTEMPLATE",
// 		IsReadOnly = true
// 	});
// 	cmdDelete_var1_Property = CxvPropertyDeclaration.Register("cmdDelete_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCmdButtonProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Operator = CxvLogicalOperator.Equal,
// 			PropertyPath = "CanDelete",
// 			Value = true
// 		}
// 	});
// }

// 0x060005b0 AspenTech.AspenPlus.MMForms.Setup.MMSetup_StreamGroup_Selection_ViewModel+BuiltinGroupResourceConverter..ctor
// public BuiltinGroupResourceConverter()
// {
// }

// 0x060005bb AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// }

// 0x060005bc AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_List1D_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.@y",
// 		IsCalculated = false
// 	});
// 	txtType_var1_Property = CxvPropertyDeclaration.Register("txtType_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y.Input.TYPE",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	txtIncrements_var1_Property = CxvPropertyDeclaration.Register("txtIncrements_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y.Input.INTERVALS",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	txtStart_var1_Property = CxvPropertyDeclaration.Register("txtStart_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.LOWER",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	txtEnd_var1_Property = CxvPropertyDeclaration.Register("txtEnd_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.UPPER",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	txtUnits_var1_Property = CxvPropertyDeclaration.Register("txtUnits_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.PARTICLESIZE",
// 		ExtraDataPaths = { "@main.@y.Input.PARTICLESIZ2" },
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y",
// 		DataAttribute = "status",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// }

// 0x060005c8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_Curren_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060005c9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CostOp_Curren_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Currency.Input.FACTOR.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Currency.Input.FACTOR.@y"
// 	});
// }

// 0x060005cf AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_Setup_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060005d0 AspenTech.AspenPlus.MMForms.Setup.MMSetup_CusUom_Setup_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Custom-Uom.Input.BASE_UNIT.@y",
// 		Sorted = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Custom-Uom.CC Nodes.UNIT1.@y"
// 		}
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Custom-Uom.Input.PHYS_QTY.@y",
// 		DisplayedCase = CxsDisplayedCase.Lowercase,
// 		Sorted = true
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Custom-Uom.Input.CUSTOM_UNIT.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Custom-Uom.CC Nodes.UNIT1.@y"
// 		}
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Custom-Uom.Input.OFFSET.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Custom-Uom.CC Nodes.UNIT2.@y"
// 		}
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Custom-Uom.Input.MULTIPLIER.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Custom-Uom.CC Nodes.UNIT2.@y"
// 		}
// 	});
// }

// 0x060005d7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BatchO_ViewModel+SABatchO_GridData_ItemTemplate..ctor
// public SABatchO_GridData_ItemTemplate()
// {
// }

// 0x060005d8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_BatchO_ViewModel+SABatchO_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static SABatchO_GridData_ItemTemplate()
// {
// 	spnNtrain_var1_Property = CxvPropertyDeclaration.Register("spnNtrain_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.NTRAIN.@y"
// 	});
// 	txtOptime_var1_Property = CxvPropertyDeclaration.Register("txtOptime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.OP_TIME.@y"
// 	});
// 	txtDownTime_var1_Property = CxvPropertyDeclaration.Register("txtDownTime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.DOWN_TIME.@y"
// 	});
// 	txtCycleTime_var1_Property = CxvPropertyDeclaration.Register("txtCycleTime_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME.@y"
// 	});
// 	cboStream_var1_Property = CxvPropertyDeclaration.Register("cboStream_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.CYCLE_TIME.@y"
// 	});
// 	lblNtrain_var1_Property = CxvPropertyDeclaration.Register("lblNtrain_var1", typeof(SABatchO_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Batch-Operation.Input.NTRAIN"
// 	});
// }

// 0x060005db AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrName_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// }

// 0x060005dc AspenTech.AspenPlus.MMForms.Setup.MMSetup_Report_StrName_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT.@y"
// 	});
// 	txtDesc_var1_Property = CxvPropertyDeclaration.Register("txtDesc_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.ReportOptions.Stream-Names.Input.TEXT.@y"
// 	});
// }

// 0x060005e1 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_Input_ViewModel+grdStreamPrice_GridData_ItemTemplate..ctor
// public grdStreamPrice_GridData_ItemTemplate()
// {
// }

// 0x060005e2 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPInput_Input_ViewModel+grdStreamPrice_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreamPrice_GridData_ItemTemplate()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRICE.@y"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.PRICE.@y"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DESTBLK.@y",
// 		IsReadOnly = true
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SOURCEBLK.@y",
// 		IsReadOnly = true
// 	});
// }

// 0x060005e9 AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_Result_ViewModel+grdStreamPrice_GridData_ItemTemplate..ctor
// public grdStreamPrice_GridData_ItemTemplate()
// {
// }

// 0x060005ea AspenTech.AspenPlus.MMForms.Setup.MMSetup_SPResult_Result_ViewModel+grdStreamPrice_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreamPrice_GridData_ItemTemplate()
// {
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MOLE_PRICE.@y"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MASS_PRICE.@y"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.VOL_PRICE.@y"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.STDVOL_PRICE.@y"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COST.@y"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(grdStreamPrice_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Output.COST.@y"
// 	});
// }

// 0x060005ee AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Subatt_ViewModel+grdAttribute_GridData_ItemTemplate..ctor
// public grdAttribute_GridData_ItemTemplate()
// {
// }

// 0x060005ef AspenTech.AspenPlus.MMForms.Setup.MMSetup_Stratt_Subatt_ViewModel+grdAttribute_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAttribute_GridData_ItemTemplate()
// {
// 	txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL.@y"
// 	});
// 	MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PARTICLESIZ2.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.USER"
// 		}
// 	});
// 	lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PARTICLESIZE.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.USER"
// 		}
// 	});
// }

// 0x060005f3 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defsub_ViewModel+grdDefSubstream_GridData_ItemTemplate..ctor
// public grdDefSubstream_GridData_ItemTemplate()
// {
// }

// 0x060005f4 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Defsub_ViewModel+grdDefSubstream_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdDefSubstream_GridData_ItemTemplate()
// {
// 	cboAttribute_var1_Property = CxvPropertyDeclaration.Register("cboAttribute_var1", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@subsmain.Stream-Class.Substreams.Input.ATTRIBUTES.@y"
// 	});
// 	cboType_var1_Property = CxvPropertyDeclaration.Register("cboType_var1", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE.@y"
// 	});
// 	txtSubstream_sid_Property = CxvPropertyDeclaration.Register("txtSubstream_sid", typeof(grdDefSubstream_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@subsmain.Stream-Class.Substreams.Input.TYPE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x060005f7 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Flowsh_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// }

// 0x060005f8 AspenTech.AspenPlus.MMForms.Setup.MMSetup_Strcla_Flowsh_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	MMComboBox1_SCLASS_Property = CxvPropertyDeclaration.Register("MMComboBox1_SCLASS", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main2.@y.Input.SCLASS"
// 	});
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main2.@y"
// 	});
// }

// 0x060005fc AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// }

// 0x060005fd AspenTech.AspenPlus.MMForms.Setup.MMSetup_UnitObj_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.@y",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// 	cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y",
// 		DataAttribute = "status",
// 		IsReadOnly = true,
// 		IsCalculated = false
// 	});
// }

// 0x0600060b AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Search_ViewModel+scrSearch_GridData_ItemTemplate..ctor
// public scrSearch_GridData_ItemTemplate()
// {
// }

// 0x0600060c AspenTech.AspenPlus.MMForms.Setup.MMSetup_Units_Search_ViewModel+scrSearch_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static scrSearch_GridData_ItemTemplate()
// {
// 	MMLBUText1_unitlabel_Property = CxvPropertyDeclaration.Register("MMLBUText1_unitlabel", typeof(scrSearch_GridData_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "itemlabel",
// 		IsCalculated = false,
// 		IsReadOnly = true,
// 		IsLocal = true
// 	});
// 	MMLBUText1_unitname_Property = CxvPropertyDeclaration.Register("MMLBUText1_unitname", typeof(scrSearch_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Unit-Types.@itemtype"
// 	});
// }

// 0x06000616 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel+grdDefine_GridData_ItemTemplate..ctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// public grdDefine_GridData_ItemTemplate()
// {
// 	watch = new CxvPropertyWatch();
// 	base..ctor();
// }

// 0x06000617 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel+grdDefine_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdDefine_GridData_ItemTemplate()
// {
// 	txtVarName_var1_Property = CxvPropertyDeclaration.Register("txtVarName_var1", typeof(grdDefine_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FVN_VARTYPE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		Sorted = true
// 	});
// 	txtDescription_Property = CxvPropertyDeclaration.Register("txtDescription", typeof(grdDefine_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FVN_DESCRIPT.@y"
// 	});
// 	format_var_Property = CxvPropertyDeclaration.Register("format_var", typeof(grdDefine_GridData_ItemTemplate), new CxvLineFormatProperty
// 	{
// 		DataPath = "@main.Input.FVN_LINESTYL.@y",
// 		DefaultLineWeight = 3.0
// 	});
// 	Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdDefine_GridData_ItemTemplate), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.FVN_ACTIVE.@y"
// 	});
// }

// 0x06000618 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000619 AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x0600061d AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_Define_ViewModel+<>c__DisplayClass12_0..ctor
// public <>c__DisplayClass12_0()
// {
// }

// 0x0600062b AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// 	_isBlockActive = true;
// 	base..ctor();
// }

// 0x0600062c AspenTech.AspenPlus.MMForms.Setup.MMSetup_VarGroup_ObjManager_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.@y",
// 		SubObjectTypePath = "[]",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Operator = CxvLogicalOperator.Equal,
// 			PropertyPath = "CanRename",
// 			Value = true
// 		}
// 	});
// 	txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@y.Input.DESCRIPTION"
// 	});
// 	Active_var_Property = CxvPropertyDeclaration.Register("Active_var", typeof(grdChild_GridData_ItemTemplate), new CxvParameterProperty
// 	{
// 		PropertyPath = "IsBlockActive",
// 		IsReadOnlyParamter = "p_IsSystemGenerated"
// 	});
// 	cmdDelete_var1_Property = CxvPropertyDeclaration.Register("cmdDelete_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCmdButtonProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			Operator = CxvLogicalOperator.Equal,
// 			PropertyPath = "CanDelete",
// 			Value = true
// 		}
// 	});
// }

// 0x06000639 AspenTech.AspenPlus.MMForms.Setup.MMSetup_ViewDefinevariables_List_ViewModel+grdViewvariable_GridData_ItemTemplate..ctor
// public grdViewvariable_GridData_ItemTemplate()
// {
// }

// 0x0600063a AspenTech.AspenPlus.MMForms.Setup.MMSetup_ViewDefinevariables_List_ViewModel+grdViewvariable_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdViewvariable_GridData_ItemTemplate()
// {
// 	txtVarName_var1_Property = CxvPropertyDeclaration.Register("txtVarName_var1", typeof(grdViewvariable_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FVN_VARTYPE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsReadOnly = true
// 	});
// }

// 0x0600063b AspenTech.AspenPlus.MMForms.Setup.StreamGroupPriorityDlg+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600063c AspenTech.AspenPlus.MMForms.Setup.StreamGroupPriorityDlg+<>c..ctor
// public <>c()
// {
// }
