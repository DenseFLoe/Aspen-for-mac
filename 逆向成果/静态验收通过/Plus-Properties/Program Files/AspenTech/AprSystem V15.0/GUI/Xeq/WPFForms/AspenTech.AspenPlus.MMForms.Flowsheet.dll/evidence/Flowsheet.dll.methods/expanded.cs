using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Threading;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.Visualisation.Controls.Support.Commands;
using Infragistics.Windows;
using Infragistics.Windows.Controls;
using Infragistics.Windows.DataPresenter;
using Infragistics.Windows.DataPresenter.Events;
using Microsoft.Practices.Composite.Presentation.Commands;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Flowsheet")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Flowsheet")]
[assembly: AssemblyCopyright("Copyright © AspenTech 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/flowsheet", "AspenTech.AspenPlus.MMForms.Flowsheet")]
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
namespace AspenTech.AspenPlus.MMForms.Flowsheet
{
	public class MMFlowsh_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMFlowsh_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration NOTPFSLOCK_Property = CxvPropertyDeclaration.Register("NOTPFSLOCK", typeof(MMFlowsh_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NOTPFSLOCK"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFlowsh_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" },
			AccessibleDataPaths = { "@NOTPFSLOCK" }
		});

		public object spec => GetValue(spec_Property);

		public object NOTPFSLOCK => GetValue(NOTPFSLOCK_Property);

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
	[ProgId("MMFlowshForm.MMFlowsh_Input")]
	public class MMFlowsh_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMFlowsh_Input()
		{
			base.ViewModelType = typeof(MMFlowsh_Input_ViewModel);
			InitializeComponent();
		}

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
	public class MMFlowsh_Input_Flowsh_ViewModel : MMTabPageViewModel
	{
		public class grdFlowsheet_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboBlkType_var1_Property = CxvPropertyDeclaration.Register("cboBlkType_var1", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVariableProperty
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

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVariableProperty
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

			[CompilerGenerated]
			private bool? <IsProxy>k__BackingField;

			public static readonly CxvPropertyDeclaration Inner_Property = CxvPropertyDeclaration.Register("Inner", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdFlowsheet_GridData_InnerTemplate),
				IndexBasis = new CxvParameterIndexBasis
				{
					Parameter = "NumRows"
				}
			});

			public static readonly CxvPropertyDeclaration Inlets_Property = CxvPropertyDeclaration.Register("Inlets", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdFlowsheet_GridData_InletsTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Input.INSTRM.@y",
					UseChildId = false,
					Name = "x"
				}
			});

			public static readonly CxvPropertyDeclaration Outlets_Property = CxvPropertyDeclaration.Register("Outlets", typeof(grdFlowsheet_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdFlowsheet_GridData_OutletsTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Input.OUTSTRM.@y",
					UseChildId = false,
					Name = "x"
				}
			});

			public object cboBlkType_var1 => GetValue(cboBlkType_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public bool? IsProxy
			{
				[CompilerGenerated]
				get
				{
					return <IsProxy>k__BackingField;
				}
				[CompilerGenerated]
				set
				{
					<IsProxy>k__BackingField = value;
				}
			}

			public object Inner => GetValue(Inner_Property);

			public object Inlets => GetValue(Inlets_Property);

			public object Outlets => GetValue(Outlets_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if ((pd == Inlets_Property && subPropertyName == "Count") || (pd == Outlets_Property && subPropertyName == "Count"))
				{
					UpdateInnerItems();
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}

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
		}

		public class grdFlowsheet_GridData_InnerTemplate : MMViewModel
		{
			private static int count;

			private int mycount;

			private object _GrdInlet_StrmNode;

			[CompilerGenerated]
			private object <grdInlet_PortNode>k__BackingField;

			[CompilerGenerated]
			private object <grdOutlet_StrmNode>k__BackingField;

			[CompilerGenerated]
			private object <grdOutlet_PortNode>k__BackingField;

			public CxvManualVariableData Test => new CxvManualVariableData
			{
				Value = mycount.ToString()
			};

			public object grdInlet_StrmNode
			{
				get
				{
					return _GrdInlet_StrmNode;
				}
				set
				{
					_GrdInlet_StrmNode = value;
				}
			}

			public object grdInlet_PortNode
			{
				[CompilerGenerated]
				get
				{
					return <grdInlet_PortNode>k__BackingField;
				}
				[CompilerGenerated]
				set
				{
					<grdInlet_PortNode>k__BackingField = value;
				}
			}

			public object grdOutlet_StrmNode
			{
				[CompilerGenerated]
				get
				{
					return <grdOutlet_StrmNode>k__BackingField;
				}
				[CompilerGenerated]
				set
				{
					<grdOutlet_StrmNode>k__BackingField = value;
				}
			}

			public object grdOutlet_PortNode
			{
				[CompilerGenerated]
				get
				{
					return <grdOutlet_PortNode>k__BackingField;
				}
				[CompilerGenerated]
				set
				{
					<grdOutlet_PortNode>k__BackingField = value;
				}
			}

			public grdFlowsheet_GridData_InnerTemplate()
			{
				count++;
				mycount = count;
			}
		}

		public class grdFlowsheet_GridData_InletsTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration grdInlet_PortNode_Property = CxvPropertyDeclaration.Register("grdInlet_PortNode", typeof(grdFlowsheet_GridData_InletsTemplate), new CxvVariableProperty
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

			public static readonly CxvPropertyDeclaration grdInlet_StrmNode_Property = CxvPropertyDeclaration.Register("grdInlet_StrmNode", typeof(grdFlowsheet_GridData_InletsTemplate), new CxvVariableProperty
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

			public object grdInlet_PortNode => GetValue(grdInlet_PortNode_Property);

			public object grdInlet_StrmNode => GetValue(grdInlet_StrmNode_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "grdInlet_StrmNode" && subPropertyName == "Value" && ((base.Parent as MMViewModel)?.Parent as MMViewModel)?.View is MMTabPage mMTabPage)
				{
					mMTabPage.Dispatcher.BeginInvoke(DispatcherPriority.Input, new Action(<OnSubPropertyDataChanged>b__0_0));
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}

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
		}

		public class grdFlowsheet_GridData_OutletsTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration grdOutlet_StrmNode_Property = CxvPropertyDeclaration.Register("grdOutlet_StrmNode", typeof(grdFlowsheet_GridData_OutletsTemplate), new CxvVariableProperty
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

			public static readonly CxvPropertyDeclaration grdOutlet_PortNode_Property = CxvPropertyDeclaration.Register("grdOutlet_PortNode", typeof(grdFlowsheet_GridData_OutletsTemplate), new CxvVariableProperty
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

			public object grdOutlet_StrmNode => GetValue(grdOutlet_StrmNode_Property);

			public object grdOutlet_PortNode => GetValue(grdOutlet_PortNode_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd.Name == "grdOutlet_StrmNode" && subPropertyName == "Value" && ((base.Parent as MMViewModel)?.Parent as MMViewModel)?.View is MMTabPage mMTabPage)
				{
					mMTabPage.Dispatcher.BeginInvoke(DispatcherPriority.Input, new Action(<OnSubPropertyDataChanged>b__0_0));
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}

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
		}

		public static readonly CxvPropertyDeclaration grdFlowsheet_GridData_Property = CxvPropertyDeclaration.Register("grdFlowsheet_GridData", typeof(MMFlowsh_Input_Flowsh_ViewModel), new CxvVectorProperty
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

		private DelegateCommand<MMScrollAreaReorderParameter> _Reorder_Command;

		public object grdFlowsheet_GridData => GetValue(grdFlowsheet_GridData_Property);

		public DelegateCommand<MMScrollAreaReorderParameter> Reorder_Command
		{
			get
			{
				if (_Reorder_Command == null)
				{
					_Reorder_Command = new DelegateCommand<MMScrollAreaReorderParameter>(Reorder_CommandExecute);
				}
				return _Reorder_Command;
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				UpdateInnerItems();
			}
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd == grdFlowsheet_GridData_Property && subPropertyName == "Count")
			{
				UpdateInnerItems();
			}
		}

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
					Message = AspenTech.AspenPlus.Localization.Properties.Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message1,
					Title = AspenTech.AspenPlus.Localization.Properties.Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddBlock,
					MsgBoxButton = MessageBoxButton.OK,
					MsgBoxImage = MessageBoxImage.Exclamation
				});
				return false;
			}
			return true;
		}

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
					Message = AspenTech.AspenPlus.Localization.Properties.Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message2,
					Title = AspenTech.AspenPlus.Localization.Properties.Resources.MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddStream,
					MsgBoxButton = MessageBoxButton.OK,
					MsgBoxImage = MessageBoxImage.Exclamation
				});
				return false;
			}
			return true;
		}

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
	}
	[ProgId("MMFlowshForm.MMFlowsh_Input_Flowsh")]
	public class MMFlowsh_Input_Flowsh : MMTabPage, IComponentConnector
	{
		private int? _recordToBeExpandedIndex;

		internal MMScrollArea grdFlowsheet;

		internal Button btnExpandAll;

		internal Button btnCollapseAll;

		private bool _contentLoaded;

		public MMFlowsh_Input_Flowsh()
		{
			base.ViewModelType = typeof(MMFlowsh_Input_Flowsh_ViewModel);
			InitializeComponent();
			grdFlowsheet.Loaded += grdFlowsheet_Loaded;
		}

		private void grdFlowsheet_Loaded(object sender, RoutedEventArgs e)
		{
			if (grdFlowsheet.DataGrid != null)
			{
				grdFlowsheet.DataGrid.CustomFilterSelectionControlOpening += DataGrid_CustomFilterSelectionControlOpening;
				grdFlowsheet.DataGrid.EditModeEnded += DataGrid_EditModeEnded;
				grdFlowsheet.DataGrid.AddHandler(UIElement.MouseLeftButtonUpEvent, new RoutedEventHandler(DataGrid_MouseLeftButtonUp), handledEventsToo: true);
			}
		}

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

		private void DataGrid_EditModeEnded(object sender, EditModeEndedEventArgs e)
		{
			if (_recordToBeExpandedIndex.HasValue && grdFlowsheet.DataGrid.Records.Count > _recordToBeExpandedIndex.Value)
			{
				grdFlowsheet.DataGrid.Records[_recordToBeExpandedIndex.Value].IsExpanded = true;
				_recordToBeExpandedIndex = null;
			}
		}

		private void DataGrid_CustomFilterSelectionControlOpening(object sender, CustomFilterSelectionControlOpeningEventArgs e)
		{
			if (e.RecordFilter.Field.Label is LabelHeader labelHeader)
			{
				string fieldDescription = string.Format(ApwnResources.ForField, labelHeader.LabelText);
				e.Control.FieldDescription = fieldDescription;
			}
		}

		private void btnExpandAll_Click(object sender, RoutedEventArgs e)
		{
			grdFlowsheet.DataGrid.Records.ExpandAll(recursive: false);
		}

		private void btnCollapseAll_Click(object sender, RoutedEventArgs e)
		{
			grdFlowsheet.DataGrid.Records.CollapseAll(recursive: false);
		}

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
	}
	public class MMFlowsh_ObjMan_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboSClass_VarCol1_Property = CxvPropertyDeclaration.Register("cboSClass_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y.Input.SCLASS"
			});

			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			private string _recType = string.Empty;

			public static readonly CxvPropertyDeclaration txtType_VarCol1_Property = CxvPropertyDeclaration.Register("txtType_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "type",
				IsReadOnly = true,
				IsCalculated = false
			});

			public static readonly CxvPropertyDeclaration cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "status",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtDescription_var1_Property = CxvPropertyDeclaration.Register("txtDescription_var1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.@y.Input.DESCRIPTION"
			});

			public object cboSClass_VarCol1 => GetValue(cboSClass_VarCol1_Property);

			public object txtName_var1 => GetValue(txtName_var1_Property);

			private string RecType
			{
				get
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
			}

			public object txtType_VarCol1
			{
				get
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
			}

			public object cboStatus_Status => GetValue(cboStatus_Status_Property);

			public object txtDescription_var1 => GetValue(txtDescription_var1_Property);

			public string GetId()
			{
				return CxsConverter.ValueToString(ResolveViewPropertyPath("txtName_var1.Value", null));
			}

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
		}

		[CompilerGenerated]
		private sealed class <GetSelectedIds>d__40 : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int <>1__state;

			private string <>2__current;

			private int <>l__initialThreadId;

			public MMFlowsh_ObjMan_ViewModel <>4__this;

			private IList <gridData>5__2;

			private int <i>5__3;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return <>2__current;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return <>2__current;
				}
			}

			[DebuggerHidden]
			public <GetSelectedIds>d__40(int <>1__state)
			{
				this.<>1__state = <>1__state;
				<>l__initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
			}

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

			bool IEnumerator.MoveNext()
			{
				//ILSpy generated this explicit interface implementation from .override directive in MoveNext
				return this.MoveNext();
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

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

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMFlowsh_ObjMan_ViewModel), new CxvVectorProperty
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

		private DelegateCommand<object> _cmdAdd_Command;

		private ICommand _cmdEdit_Command;

		private DelegateCommand<object> _cmdDelete_Command;

		private ICommand _cmdRename_Command;

		private ICommand _cmdCurrent_Command;

		private ICommand _grid_RowDoubleClickCommand;

		private ICommand _cmdExport_Command;

		private ObservableCollection<int> _SelectedRowIndexes;

		public object grdChild_GridData => GetValue(grdChild_GridData_Property);

		public DelegateCommand<object> cmdAdd_Command
		{
			get
			{
				if (_cmdAdd_Command == null)
				{
					_cmdAdd_Command = new DelegateCommand<object>(cmdAdd_CommandExecute);
				}
				return _cmdAdd_Command;
			}
		}

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new RelayActionCommand<object>(cmdEdit_CommandExecute, CommandCanExecute);
				}
				return _cmdEdit_Command;
			}
		}

		public DelegateCommand<object> cmdDelete_Command
		{
			get
			{
				if (_cmdDelete_Command == null)
				{
					_cmdDelete_Command = new DelegateCommand<object>(cmdDelete_CommandExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public ICommand cmdRename_Command
		{
			get
			{
				if (_cmdRename_Command == null)
				{
					_cmdRename_Command = new RelayActionCommand<object>(cmdRename_CommandExecute, CommandCanExecute);
				}
				return _cmdRename_Command;
			}
		}

		public ICommand cmdCurrent_Command
		{
			get
			{
				if (_cmdCurrent_Command == null)
				{
					_cmdCurrent_Command = new RelayActionCommand<object>(cmdCurrent_CommandExecute, CommandCanExecute);
				}
				return _cmdCurrent_Command;
			}
		}

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
					_cmdExport_Command = new RelayActionCommand<object>(cmdExport_CommandExecute, CommandCanExecute);
				}
				return _cmdExport_Command;
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

		private void cmdCurrent_CommandExecute(object parameter)
		{
			this.ChangeSection(ExpandDataPath("@main"), CxsConverter.ValueToString(ResolveViewPropertyPath("grdChild_GridData[" + SelectedRowIndexes[0] + "].txtName_var1.Value", null)));
		}

		private bool CommandCanExecute(object parameter)
		{
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1)
			{
				return true;
			}
			return false;
		}

		private bool DeleteCommandCanExecute(object parameter)
		{
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count > 0)
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

		private void _SelectedRowIndexes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
		}

		[IteratorStateMachine(typeof(<GetSelectedIds>d__40))]
		private IEnumerable<string> GetSelectedIds()
		{
			return new <GetSelectedIds>d__40(-2)
			{
				<>4__this = this
			};
		}

		public void SetSelectedRowFromScript(int row)
		{
			if (SelectedRowIndexes == null)
			{
				SelectedRowIndexes = new ObservableCollection<int>();
			}
			SelectedRowIndexes.Clear();
			SelectedRowIndexes.Add(row);
		}
	}
	[ProgId("MMFlowshForm.MMFlowsh_ObjMan")]
	public class MMFlowsh_ObjMan : MMTabPage, IComponentConnector
	{
		internal MMFlatButton cmdAdd;

		internal MMFlatButton cmdExport;

		internal MMFlatButton cmdEdit;

		internal MMFlatButton cmdCurrent;

		internal MMScrollAreaMS grdChild;

		private bool _contentLoaded;

		public MMFlowsh_ObjMan()
		{
			base.ViewModelType = typeof(MMFlowsh_ObjMan_ViewModel);
			InitializeComponent();
		}

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
	}
}
namespace AspenTech.AspenPlus.Happ
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
}
