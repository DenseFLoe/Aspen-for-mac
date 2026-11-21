using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
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
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.WpfControls.Engineering;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Streams")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Streams")]
[assembly: AssemblyCopyright("Copyright © AspenTech 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/streams", "AspenTech.AspenPlus.MMForms.Streams.Heat")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/streams", "AspenTech.AspenPlus.MMForms.Streams.Material")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/streams", "AspenTech.AspenPlus.MMForms.Streams.Work")]
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
namespace AspenTech.AspenPlus.MMForms.Streams.Work
{
	public class MMWork_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration power_Property = CxvPropertyDeclaration.Register("power", typeof(MMWork_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MN1"
		});

		public static readonly CxvPropertyDeclaration ENTOPT_Property = CxvPropertyDeclaration.Register("ENTOPT", typeof(MMWork_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMWork_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@power" },
			EnteredDataPaths = { "@ENTOPT" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMWork_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTOPT" }
		});

		public object power => GetValue(power_Property);

		public object ENTOPT => GetValue(ENTOPT_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMWork.MMWork_Input")]
	public class MMWork_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMWork_Input()
		{
			base.ViewModelType = typeof(MMWork_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/work/mmwork_input.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMWork_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText1_1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_1_var1", typeof(MMWork_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SPEED"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_0_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_0_var1", typeof(MMWork_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.POWER"
		});

		public object MMLBUText1_1_var1 => GetValue(MMLBUText1_1_var1_Property);

		public object MMLBUText1_0_var1 => GetValue(MMLBUText1_0_var1_Property);
	}
	[ProgId("MMWork.MMWork_Input_Specif")]
	public class MMWork_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_0_label;

		internal MMVariableEdit MMLBUText1_0;

		internal MMLabel MMLBUText1_1_label;

		internal MMVariableEdit MMLBUText1_1;

		private bool _contentLoaded;

		public MMWork_Input_Specif()
		{
			base.ViewModelType = typeof(MMWork_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/work/mmwork_input_specif.xaml", UriKind.Relative);
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
				MMLBUText1_0_label = (MMLabel)target;
				break;
			case 3:
				MMLBUText1_0 = (MMVariableEdit)target;
				break;
			case 4:
				MMLBUText1_1_label = (MMLabel)target;
				break;
			case 5:
				MMLBUText1_1 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMWork_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMWork_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMWork_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@work1" }
		});

		public object work1 => GetValue(work1_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMWork.MMWork_Result")]
	public class MMWork_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMWork_Result()
		{
			base.ViewModelType = typeof(MMWork_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/work/mmwork_result.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMWork_Result_Work_ViewModel : MMTabPageViewModel
	{
		public class grdWork_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col",
				ExposeAs = CxvVariableTypeCode.Integer
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#3.@col",
				ExposeAs = CxvVariableTypeCode.Real
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object txtTableVar_var2
			{
				get
				{
					string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#3.@col", "value"));
					return new CxvManualVariableData
					{
						IsReadOnly = true,
						IsCalculated = true,
						Value = value,
						ValueType = typeof(double),
						CxsItemMoniker = CxvObservableObject.CxsPathToMoniker(ExpandDataPath("@main.Stream Results.Table.#3.@col"))
					};
				}
			}

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Streams.");
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
				else if (pd == txtTableVar_var1_Property && subPropertyName == "Value")
				{
					OnPropertyChanged("txtTableVar_var2");
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdWork_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col"
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
					int num = text.LastIndexOf("Streams.");
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

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMWork_Result_Work_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
					DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMWork_Result_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = true,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMWork_Result_Work_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData2_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = true,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration label1_Property = CxvPropertyDeclaration.Register("label1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#3",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label2_Property = CxvPropertyDeclaration.Register("label2", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#4",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label3_Property = CxvPropertyDeclaration.Register("label3", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#5",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label4_Property = CxvPropertyDeclaration.Register("label4", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#6",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label5_Property = CxvPropertyDeclaration.Register("label5", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#7",
			ExposeAs = CxvVariableTypeCode.Id
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object grdWork_GridData => GetValue(grdWork_GridData_Property);

		public object grdWork_GridData2 => GetValue(grdWork_GridData2_Property);

		public object label1 => GetValue(label1_Property);

		public object label2 => GetValue(label2_Property);

		public object label3 => GetValue(label3_Property);

		public object label4 => GetValue(label4_Property);

		public object label5 => GetValue(label5_Property);

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
				if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#5", "id"))))
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
	[ProgId("MMWork.MMWork_Result_Work")]
	public class MMWork_Result_Work : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdWork;

		internal MMScrollAreaHorizontal grdWork2;

		private bool _contentLoaded;

		public MMWork_Result_Work()
		{
			base.ViewModelType = typeof(MMWork_Result_Work_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/work/mmwork_result_work.xaml", UriKind.Relative);
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
namespace AspenTech.AspenPlus.MMForms.Streams.Power
{
	public class MMPower_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPower_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.SPEC" },
			EnteredDataPaths = { "@main.CC Nodes.ENTSPC" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPower_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@main.CC Nodes.ENTOPT" }
		});

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMPower.MMPower_Input")]
	public class MMPower_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPower_Input()
		{
			base.ViewModelType = typeof(MMPower_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/power/mmpower_input.xaml", UriKind.Relative);
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPower_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration Specif_MultiMap_Property = CxvPropertyDeclaration.Register("Specif_MultiMap", typeof(MMPower_Input_Specif_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "Specif_var1",
					DataPath = "@main.Input.SPECIF"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					DisplayResourceKey = ApwnResources.MMPower_Power,
					Value = "Specif_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Specif_var1",
							Value = "POWER"
						}
					}
				},
				new CxvMultiMapOption
				{
					DisplayResourceKey = ApwnResources.MMPower_Input_Amperage,
					Value = "Specif_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "Specif_var1",
							Value = "AMPERAGE"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.AMPPOW"
			}
		});

		public static readonly CxvPropertyDeclaration Power_var1_Property = CxvPropertyDeclaration.Register("Power_var1", typeof(MMPower_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.POWER"
		});

		public static readonly CxvPropertyDeclaration Amperage_var1_Property = CxvPropertyDeclaration.Register("Amperage_var1", typeof(MMPower_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AMPERAGE",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.ENAMP"
			}
		});

		public object Specif_MultiMap => GetValue(Specif_MultiMap_Property);

		public object Power_var1 => GetValue(Power_var1_Property);

		public object Amperage_var1 => GetValue(Amperage_var1_Property);
	}
	[ProgId("MMPower.MMPower_Input_Specif")]
	public class MMPower_Input_Specif : MMTabPage, IComponentConnector
	{
		private bool _contentLoaded;

		public MMPower_Input_Specif()
		{
			base.ViewModelType = typeof(MMPower_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/power/mmpower_input_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
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
	public class MMPower_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration work1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMPower_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPower_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@power1" }
		});

		public object power1 => GetValue(work1_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMPower.MMPower_Result")]
	public class MMPower_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMPower_Result()
		{
			base.ViewModelType = typeof(MMPower_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/power/mmpower_result.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPower_Result_Power_ViewModel : MMTabPageViewModel
	{
		public class grdWork_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#3.@col",
				ExposeAs = CxvVariableTypeCode.Real
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col"
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object txtTableVar_var2
			{
				get
				{
					string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#3.@col", "value"));
					return new CxvManualVariableData
					{
						IsReadOnly = true,
						IsCalculated = true,
						Value = value,
						ValueType = typeof(double),
						CxsItemMoniker = CxvObservableObject.CxsPathToMoniker(ExpandDataPath("@main.Stream Results.Table.#3.@col"))
					};
				}
			}

			public object cboSubstream_var1 => GetValue(cboSubstream_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstream_var1_Property && subPropertyName == "Value" && cboSubstream_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Streams.");
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
				else if (pd == txtTableVar_var1_Property && subPropertyName == "Value")
				{
					OnPropertyChanged("txtTableVar_var2");
				}
				base.OnSubPropertyDataChanged(pd, subPropertyName);
			}
		}

		public class grdWork_GridData2_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col"
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
					int num = text.LastIndexOf("Streams.");
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

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMPower_Result_Power_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					PromptResourceKey = "MMPower_Result_Power_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
					DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					PromptResourceKey = "MMPower_Result_Power_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMPower_Result_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = true,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMPower_Result_Power_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdWork_GridData2_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = true,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration label1_Property = CxvPropertyDeclaration.Register("label1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#3",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label2_Property = CxvPropertyDeclaration.Register("label2", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#4",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label3_Property = CxvPropertyDeclaration.Register("label3", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#5",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label4_Property = CxvPropertyDeclaration.Register("label4", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#6",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration label5_Property = CxvPropertyDeclaration.Register("label5", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table.#7",
			ExposeAs = CxvVariableTypeCode.Id
		});

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object txtTablelab_var1 => GetValue(txtTablelab_var1_Property);

		public object grdWork_GridData => GetValue(grdWork_GridData_Property);

		public object grdWork_GridData2 => GetValue(grdWork_GridData2_Property);

		public object label1 => GetValue(label1_Property);

		public object label2 => GetValue(label2_Property);

		public object label3 => GetValue(label3_Property);

		public object label4 => GetValue(label4_Property);

		public object label5 => GetValue(label5_Property);

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
				if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#5", "id"))))
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
	[ProgId("MMPower.MMPower_Result_Power")]
	public class MMPower_Result_Power : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdWork;

		private bool _contentLoaded;

		public MMPower_Result_Power()
		{
			base.ViewModelType = typeof(MMPower_Result_Power_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/power/mmpower_result_power.xaml", UriKind.Relative);
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Streams.Material
{
	public class MMMaterial_Input_Info_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration streamName_var_Property = CxvPropertyDeclaration.Register("streamName_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main",
			ExposeAs = CxvVariableTypeCode.Id,
			IsReadOnly = true,
			IsCalculated = false,
			VariablePrompt = "The name of the stream",
			VariablePromptResourceKey = "MMMaterial_Input_Info_Name"
		});

		private string _recType = string.Empty;

		public static readonly CxvPropertyDeclaration streamType_var_Property = CxvPropertyDeclaration.Register("streamType_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main",
			DataAttribute = "type",
			ExposeAs = CxvVariableTypeCode.String,
			IsReadOnly = false
		});

		public static readonly CxvPropertyDeclaration fromValue_var_Property = CxvPropertyDeclaration.Register("fromValue_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Ports.SOURCE.#0",
			ExposeAs = CxvVariableTypeCode.Id,
			IsReadOnly = true,
			IsCalculated = false,
			VariablePrompt = "The source of the stream",
			VariablePromptResourceKey = "MMMaterial_Input_Info_From"
		});

		public static readonly CxvPropertyDeclaration toValue_var_Property = CxvPropertyDeclaration.Register("toValue_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Ports.DEST.#0",
			ExposeAs = CxvVariableTypeCode.Id,
			IsReadOnly = true,
			IsCalculated = false,
			VariablePrompt = "The destination of the stream",
			VariablePromptResourceKey = "MMMaterial_Input_Info_To"
		});

		private object _description_var;

		public static readonly CxvPropertyDeclaration descriptionInput_var_Property = CxvPropertyDeclaration.Register("descriptionInput_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DESCRIPTION",
			IsReadOnly = false,
			IsCalculated = false,
			IsEntered = true
		});

		public static readonly CxvPropertyDeclaration reportOptions_varProperty = CxvPropertyDeclaration.Register("reportOptions_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.@parent.@parent.Setup.ReportOptions.Stream-Names.Input.TEXT.@id",
			IsReadOnly = false,
			IsCalculated = false,
			IsEntered = true
		});

		public static readonly CxvPropertyDeclaration comments_var_Property = CxvPropertyDeclaration.Register("comments_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvDescriptionProperty
		{
			DataPath = "@main.Comments"
		});

		public object streamName_var => GetValue(streamName_var_Property);

		private string RecType
		{
			get
			{
				if (string.IsNullOrEmpty(_recType) && ExpandDataPath("@main").Replace("Top.appModelV8.", string.Empty).StartsWith("Streams"))
				{
					_recType = "streams";
				}
				return _recType;
			}
		}

		public object streamType_var
		{
			get
			{
				CxvVariableData cxvVariableData = GetValue(streamType_var_Property) as CxvVariableData;
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

		public object fromValue_var => GetValue(fromValue_var_Property);

		public object toValue_var => GetValue(toValue_var_Property);

		public object description_var
		{
			get
			{
				return _description_var;
			}
			private set
			{
				_description_var = value;
				OnPropertyChanged("description_var");
			}
		}

		public object descriptionInput_var => GetValue(descriptionInput_var_Property);

		public object reportOptions_var => GetValue(reportOptions_varProperty);

		public object comments_var => GetValue(comments_var_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				description_var = descriptionInput_var;
			}
			base.OnUpdateData();
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
	public class MMMaterial_AddOpt_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lbtuTempTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTempTol_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.EO_TEMP_TOL"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRAC_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VFRAC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRACX_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VFRAC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SFRAC_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SFRC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.COMP_TOL"
		});

		public static readonly CxvPropertyDeclaration MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox11_var1",
					DataPath = "@main.Input.ALWAYS_INST"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox11_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox11_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox11_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox11_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox9_var1",
					DataPath = "@main.Input.PASS_THROUGH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_1",
					Value = "MMComboBox9_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_1",
					Value = "MMComboBox9_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NEG_COMP_CHK"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NEG_FLOW_CHK"
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox4_var1",
					DataPath = "@main.Input.EO_FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard",
					Value = "MMComboBox4_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "STANDARD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EO-PML",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML",
					Value = "MMComboBox4_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "EOPML"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RT-Opt 10.0",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0",
					Value = "MMComboBox4_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "MOLEFRAC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RT-Opt 3.0",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_3_0",
					Value = "MMComboBox4_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "MOLEFLOW"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main.Input.DERIV_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Analytical",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Analytical",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "ANALYTICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Numerical",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Numerical",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "NUMERICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Update (Analytical)",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
					Value = "MMComboBox1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "UPDATE-ANALY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Update (Numerical)",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
					Value = "MMComboBox1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "UPDATE-NUMER"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_var1",
					DataPath = "@main.Input.SOLVE_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with information messages",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_inform",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-PERT-IN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with warning messages",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warnin",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-PERT-WA"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure stop with error messages",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-NOPERT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Closed; use Perturbation layer around closed model",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_",
					Value = "MMComboBox2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "PERTURBATION"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Neither; ignore block during EO solution",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
					Value = "MMComboBox2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "DO-NOT-CREAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox17_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox17_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox17_var1",
					DataPath = "@main.Input.AUTO_PHASE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_2",
					Value = "MMComboBox17_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox17_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_2",
					Value = "MMComboBox17_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox17_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_PHASE_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox10_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox10_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox10_var1",
					DataPath = "@main.Input.FLASH_FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "PML",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_PML",
					Value = "MMComboBox10_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox10_var1",
							Value = "PML"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Smoothing",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Smoothing",
					Value = "MMComboBox10_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox10_var1",
							Value = "SMOOTHING"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox12_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox12_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox12_var1",
					DataPath = "@main.Input.L2_COMP_MODE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Auto",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Auto",
					Value = "MMComboBox12_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox12_var1",
							Value = "AUTO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "None",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_None",
					Value = "MMComboBox12_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox12_var1",
							Value = "NONE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "CompID",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_CompID",
					Value = "MMComboBox12_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox12_var1",
							Value = "COMPID"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.L2CP1"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_L2_COMP",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.L2CP1"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox8_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox8_var1",
					DataPath = "@main.Input.CHECK_FREE_W"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_3",
					Value = "MMComboBox8_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox8_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_3",
					Value = "MMComboBox8_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox8_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_HEAVY_KEY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_LIGHT_KEY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_DEP_COMPS"
		});

		public static readonly CxvPropertyDeclaration MMComboBox7_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox7_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox7_var1",
					DataPath = "@main.Input.SPARSITY"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Temperature & pressure",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature___pressure",
					Value = "MMComboBox7_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox7_var1",
							Value = "COMP-INDEP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Temperature, pressure & composition",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition",
					Value = "MMComboBox7_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox7_var1",
							Value = "FULL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Temperature, pressure & composition for water",
					DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition_for_water",
					Value = "MMComboBox7_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox7_var1",
							Value = "WATER-SOLU"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SPAR"
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

		public object lbtuTempTol_var1 => GetValue(lbtuTempTol_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMLBUText5_var1 => GetValue(MMLBUText5_var1_Property);

		public object MMLBUText6_var1 => GetValue(MMLBUText6_var1_Property);

		public object MMComboBox11_MultiMap => GetValue(MMComboBox11_MultiMap_Property);

		public object MMComboBox9_MultiMap => GetValue(MMComboBox9_MultiMap_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMComboBox4_MultiMap => GetValue(MMComboBox4_MultiMap_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object MMComboBox17_MultiMap => GetValue(MMComboBox17_MultiMap_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox10_MultiMap => GetValue(MMComboBox10_MultiMap_Property);

		public object MMComboBox12_MultiMap => GetValue(MMComboBox12_MultiMap_Property);

		public object MMComboBox13_var1 => GetValue(MMComboBox13_var1_Property);

		public object MMComboBox8_MultiMap => GetValue(MMComboBox8_MultiMap_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMComboBox5_var1 => GetValue(MMComboBox5_var1_Property);

		public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

		public object MMComboBox7_MultiMap => GetValue(MMComboBox7_MultiMap_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}
	}
	[ProgId("MMMaterial.MMMaterial_AddOpt")]
	public class MMMaterial_AddOpt : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox9_label;

		internal MMComboEdit MMComboBox9;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMComboBox11_label;

		internal MMComboEdit MMComboBox11;

		internal MMGroupBox MMFrame3;

		internal MMLabel MMComboBox7_label;

		internal MMComboEdit MMComboBox7;

		internal MMLabel MMComboBox3_label;

		internal MMComboEdit MMComboBox3;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMComboBox8_label;

		internal MMComboEdit MMComboBox8;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox17_label;

		internal MMComboEdit MMComboBox17;

		internal MMLabel MMLBUText10_label;

		internal MMVariableEdit MMLBUText10;

		internal MMLabel MMComboBox10_label;

		internal MMComboEdit MMComboBox10;

		internal MMLabel MMComboBox12_label;

		internal MMComboEdit MMComboBox12;

		internal MMLabel MMComboBox13_label;

		internal MMComboEdit MMComboBox13;

		internal MMGroupBox MMFrame4;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		internal MMLabel lbtuTempTol_label;

		internal MMVariableEdit lbtuTempTol;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMaterial_AddOpt()
		{
			base.ViewModelType = typeof(MMMaterial_AddOpt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_addopt.xaml", UriKind.Relative);
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
				MMComboBox2_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox9_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox9 = (MMComboEdit)target;
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
				MMComboBox11_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox11 = (MMComboEdit)target;
				break;
			case 16:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 17:
				MMComboBox7_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox7 = (MMComboEdit)target;
				break;
			case 19:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 20:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 21:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 22:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 23:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 24:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 25:
				MMComboBox8_label = (MMLabel)target;
				break;
			case 26:
				MMComboBox8 = (MMComboEdit)target;
				break;
			case 27:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 28:
				MMComboBox17_label = (MMLabel)target;
				break;
			case 29:
				MMComboBox17 = (MMComboEdit)target;
				break;
			case 30:
				MMLBUText10_label = (MMLabel)target;
				break;
			case 31:
				MMLBUText10 = (MMVariableEdit)target;
				break;
			case 32:
				MMComboBox10_label = (MMLabel)target;
				break;
			case 33:
				MMComboBox10 = (MMComboEdit)target;
				break;
			case 34:
				MMComboBox12_label = (MMLabel)target;
				break;
			case 35:
				MMComboBox12 = (MMComboEdit)target;
				break;
			case 36:
				MMComboBox13_label = (MMLabel)target;
				break;
			case 37:
				MMComboBox13 = (MMComboEdit)target;
				break;
			case 38:
				MMFrame4 = (MMGroupBox)target;
				break;
			case 39:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 40:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 41:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 42:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 43:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 44:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 45:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 46:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			case 47:
				lbtuTempTol_label = (MMLabel)target;
				break;
			case 48:
				lbtuTempTol = (MMVariableEdit)target;
				break;
			case 49:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Eoopti_Model_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdAddOpt_Command;

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
		{
			DisabledPrompt = WpfFormsResources.MMMaterial_Eoopti_Model_Prompt1
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox6_var1",
					DataPath = "@main.Input.AUTO_COMPS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Always",
					DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
					PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always_Prompt",
					Value = "MMComboBox6_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox6_var1",
							Value = "ALWAYS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No model comps",
					DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
					PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps_Prompt",
					Value = "MMComboBox6_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox6_var1",
							Value = "IF-NO-COMPS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Never",
					DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
					PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never_Prompt",
					Value = "MMComboBox6_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox6_var1",
							Value = "NEVER"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_COMPS_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_COMPS"
		});

		public ICommand cmdAddOpt_Command
		{
			get
			{
				if (_cmdAddOpt_Command == null)
				{
					_cmdAddOpt_Command = new CxvDelegateCommand<object>(cmdAddOpt_CommandExecute);
				}
				return _cmdAddOpt_Command;
			}
		}

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMComboBox6_MultiMap => GetValue(MMComboBox6_MultiMap_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		private void cmdAddOpt_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMaterial.MMMaterial_AddOpt",
				LegacyFlags = 0,
				HelpId = 177,
				HelpFile = "Common.hlp",
				ShowPrompts = true,
				CompleteDataPaths = new string[1] { "@main.CC Nodes.L2CP2" },
				ShortName = WpfFormsResources.MMMaterial_Eoopti_Model_Display1
			});
		}
	}
	[ProgId("MMMaterial.MMMaterial_Eoopti_Model")]
	public class MMMaterial_Eoopti_Model : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMLBUText10_label;

		internal MMVariableEdit MMLBUText10;

		internal MMCmdButton cmdAddOpt;

		private bool _contentLoaded;

		public MMMaterial_Eoopti_Model()
		{
			base.ViewModelType = typeof(MMMaterial_Eoopti_Model_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_eoopti_model.xaml", UriKind.Relative);
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
				MMComboBox1_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 6:
				MMLBUText10_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText10 = (MMVariableEdit)target;
				break;
			case 8:
				cmdAddOpt = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SUBSTRID_Property = CxvPropertyDeclaration.Register("SUBSTRID", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration SPECS_Property = CxvPropertyDeclaration.Register("SPECS", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPECS"
		});

		public static readonly CxvPropertyDeclaration FLASHOPT_Property = CxvPropertyDeclaration.Register("FLASHOPT", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FLSOPT"
		});

		public static readonly CxvPropertyDeclaration SUBATTRID_Property = CxvPropertyDeclaration.Register("SUBATTRID", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBATTRID"
		});

		public static readonly CxvPropertyDeclaration SUBCATID1_Property = CxvPropertyDeclaration.Register("SUBCATID1", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID1"
		});

		public static readonly CxvPropertyDeclaration SUBCATID2_Property = CxvPropertyDeclaration.Register("SUBCATID2", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID2"
		});

		public static readonly CxvPropertyDeclaration SUBCATID3_Property = CxvPropertyDeclaration.Register("SUBCATID3", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID3"
		});

		public static readonly CxvPropertyDeclaration PSDCOMP_Property = CxvPropertyDeclaration.Register("PSDCOMP", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.PSD"
		});

		public static readonly CxvPropertyDeclaration ATTRCOMP_Property = CxvPropertyDeclaration.Register("ATTRCOMP", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ATTR"
		});

		public static readonly CxvPropertyDeclaration PSDACC_Property = CxvPropertyDeclaration.Register("PSDACC", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.PSD1"
		});

		public static readonly CxvPropertyDeclaration ATTRACC_Property = CxvPropertyDeclaration.Register("ATTRACC", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CMP1"
		});

		public static readonly CxvPropertyDeclaration flshe_Property = CxvPropertyDeclaration.Register("flshe", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FLSHE"
		});

		public static readonly CxvPropertyDeclaration ENTEOMOD_Property = CxvPropertyDeclaration.Register("ENTEOMOD", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTEOMOD"
		});

		public static readonly CxvPropertyDeclaration L2CP2_Property = CxvPropertyDeclaration.Register("L2CP2", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.L2CP2"
		});

		public static readonly CxvPropertyDeclaration ENTCOST_Property = CxvPropertyDeclaration.Register("ENTCOST", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCOST"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SPECS" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@FLASHOPT" },
			EnteredDataPaths = { "@flshe" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PSDCOMP" },
			AccessibleDataPaths = { "@PSDACC" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@ATTRCOMP" },
			AccessibleDataPaths = { "@ATTRACC" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@L2CP2" },
			EnteredDataPaths = { "@ENTEOMOD" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTCOST" }
		});

		public static readonly CxvPropertyDeclaration mixed_phase_var_Property = CxvPropertyDeclaration.Register("mixed_phase_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.SPECS", "@main.CC Nodes.SPEC4.MIXED", "@main.CC Nodes.ATTR.MIXED", "@main.CC Nodes.MIXPSD" }
		});

		public static readonly CxvPropertyDeclaration conv_solids_var_Property = CxvPropertyDeclaration.Register("conv_solids_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.SP3C2", "@main.CC Nodes.CNVSPECS", "@main.CC Nodes.CNVATTR", "@main.CC Nodes.CNVPSD" },
			AccessibleDataPaths = { "@main.CC Nodes.CSTAB" }
		});

		public static readonly CxvPropertyDeclaration nonconv_solids_var_Property = CxvPropertyDeclaration.Register("nonconv_solids_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.SP3C2", "@main.CC Nodes.NCSPECS", "@main.CC Nodes.NCVATTR", "@main.CC Nodes.NCPSD" },
			AccessibleDataPaths = { "@main.CC Nodes.NCTAB" }
		});

		private bool _locked;

		private bool _lockTried;

		public object SUBSTRID => GetValue(SUBSTRID_Property);

		public object SPECS => GetValue(SPECS_Property);

		public object FLASHOPT => GetValue(FLASHOPT_Property);

		public object SUBATTRID => GetValue(SUBATTRID_Property);

		public object SUBCATID1 => GetValue(SUBCATID1_Property);

		public object SUBCATID2 => GetValue(SUBCATID2_Property);

		public object SUBCATID3 => GetValue(SUBCATID3_Property);

		public object PSDCOMP => GetValue(PSDCOMP_Property);

		public object ATTRCOMP => GetValue(ATTRCOMP_Property);

		public object PSDACC => GetValue(PSDACC_Property);

		public object ATTRACC => GetValue(ATTRACC_Property);

		public object flshe => GetValue(flshe_Property);

		public object ENTEOMOD => GetValue(ENTEOMOD_Property);

		public object L2CP2 => GetValue(L2CP2_Property);

		public object ENTCOST => GetValue(ENTCOST_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object mixed_phase_var => GetValue(mixed_phase_var_Property);

		public object conv_solids_var => GetValue(conv_solids_var_Property);

		public object nonconv_solids_var => GetValue(nonconv_solids_var_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && !_lockTried)
			{
				_lockTried = true;
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					try
					{
						base.ResolvedCxsProvider.InvokeAction(text, "Lock", true);
						_locked = true;
					}
					catch (CxsException)
					{
					}
				}
			}
			base.OnUpdateData();
		}

		public override bool OnViewClosing()
		{
			if (_locked)
			{
				string text = ExpandDataPath("@main");
				if (!string.IsNullOrEmpty(text))
				{
					try
					{
						base.ResolvedCxsProvider.InvokeAction(text, "Unlock", true);
						_locked = false;
					}
					catch (CxsException)
					{
					}
				}
			}
			return base.OnViewClosing();
		}
	}
	[ProgId("MMMaterial.MMMaterial_Input")]
	public class MMMaterial_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tab1;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab8;

		private bool _contentLoaded;

		public MMMaterial_Input()
		{
			base.ViewModelType = typeof(MMMaterial_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input.xaml", UriKind.Relative);
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
				tab6 = (MMTabItem)target;
				break;
			case 3:
				tab7 = (MMTabItem)target;
				break;
			case 4:
				tab1 = (MMTabItem)target;
				break;
			case 5:
				tab4 = (MMTabItem)target;
				break;
			case 6:
				tab5 = (MMTabItem)target;
				break;
			case 7:
				tab8 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Compat_ViewModel : MMTabPageViewModel
	{
		public class grdCompAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ELEM.@SUBCATID1.@SUBCATID2.@SUBCATID3.@ROWNUM"
			});

			public static readonly CxvPropertyDeclaration txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LAB.@SUBCATID1.@SUBCATID2.@SUBCATID3.@ROWNUM"
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtElement_var1 => GetValue(txtElement_var1_Property);
		}

		public static readonly CxvPropertyDeclaration mnbSubstream_var2_Property = CxvPropertyDeclaration.Register("mnbSubstream_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID1"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_var1_Property = CxvPropertyDeclaration.Register("mnbSubstream_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL",
			SelectedItemBinding = "mnbSubstream_var2.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
			CompletePaths = { "ATTR" },
			EnteredPaths = { "ENTSUBSTR" }
		});

		public static readonly CxvPropertyDeclaration txtATotal_var1_Property = CxvPropertyDeclaration.Register("txtATotal_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.ATTOTAL.@SUBCATID1.@SUBCATID2.@SUBCATID3"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID3"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_component_Property = CxvPropertyDeclaration.Register("mnbAttribute_component", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ATTR.@SUBCATID1.@SUBCATID2"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_entcomp_Property = CxvPropertyDeclaration.Register("mnbAttribute_entcomp", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCOMP.@SUBCATID1.@SUBCATID2"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@SUBCATID1.@SUBCATID2",
			SelectedItemBinding = "mnbAttribute_var2.Value",
			CreateNewPrompt = "Attribute ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Attribute_ID_",
			CompletePaths = { "@main.CC Nodes.ATTR.@SUBCATID1.@SUBCATID2" },
			EnteredPaths = { "@main.CC Nodes.ENTCOMP.@SUBCATID1.@SUBCATID2" }
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID2"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_substream_Property = CxvPropertyDeclaration.Register("mnbComponent_substream", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ATTR.@SUBCATID1"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_entsubstr_Property = CxvPropertyDeclaration.Register("mnbComponent_entsubstr", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSUBSTR.@SUBCATID1"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@SUBCATID1",
			SelectedItemBinding = "mnbComponent_var2.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
			CompletePaths = { "@main.CC Nodes.ATTR.@SUBCATID1" },
			EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@SUBCATID1" }
		});

		public static readonly CxvPropertyDeclaration grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.ELEM.@SUBCATID1.@SUBCATID2.@SUBCATID3",
				UseChildId = true,
				Name = "ROWNUM",
				ProxyRow = false
			}
		});

		public object mnbSubstream_var2 => GetValue(mnbSubstream_var2_Property);

		public object mnbSubstream_var1 => GetValue(mnbSubstream_var1_Property);

		public object txtATotal_var1 => GetValue(txtATotal_var1_Property);

		public object mnbAttribute_var2 => GetValue(mnbAttribute_var2_Property);

		public object mnbAttribute_component => GetValue(mnbAttribute_component_Property);

		public object mnbAttribute_entcomp => GetValue(mnbAttribute_entcomp_Property);

		public object mnbAttribute_var1 => GetValue(mnbAttribute_var1_Property);

		public object mnbComponent_var2 => GetValue(mnbComponent_var2_Property);

		public object mnbComponent_substream => GetValue(mnbComponent_substream_Property);

		public object mnbComponent_entsubstr => GetValue(mnbComponent_entsubstr_Property);

		public object mnbComponent_var1 => GetValue(mnbComponent_var1_Property);

		public object grdCompAttr_GridData => GetValue(grdCompAttr_GridData_Property);
	}
	[ProgId("MMMaterial.MMMaterial_Input_Compat")]
	public class MMMaterial_Input_Compat : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbSubstream_label;

		internal MMAdvancedComboEdit mnbSubstream;

		internal MMGroupBox fraCompAtt;

		internal MMLabel mnbComponent_label;

		internal MMLabel mnbAttribute_label;

		internal MMAdvancedComboEdit mnbComponent;

		internal MMAdvancedComboEdit mnbAttribute;

		internal MMScrollArea grdCompAttr;

		internal MMLabel lblATotal;

		internal MMValueEdit txtATotal;

		private bool _contentLoaded;

		public MMMaterial_Input_Compat()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Compat_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_compat.xaml", UriKind.Relative);
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
				mnbSubstream_label = (MMLabel)target;
				break;
			case 2:
				mnbSubstream = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraCompAtt = (MMGroupBox)target;
				break;
			case 4:
				mnbComponent_label = (MMLabel)target;
				break;
			case 5:
				mnbAttribute_label = (MMLabel)target;
				break;
			case 6:
				mnbComponent = (MMAdvancedComboEdit)target;
				break;
			case 7:
				mnbAttribute = (MMAdvancedComboEdit)target;
				break;
			case 8:
				grdCompAttr = (MMScrollArea)target;
				break;
			case 9:
				lblATotal = (MMLabel)target;
				break;
			case 10:
				txtATotal = (MMValueEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_ConvSol_ViewModel : MMTabPageViewModel
	{
		public class grdComposition_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FLOW.@CONVSUBID.@COMPCONV",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FLOW.@CONVSUBID.@COMPCONV",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtXomponent_var1 => GetValue(txtXomponent_var1_Property);
		}

		public class grdCompAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ELEM.@CONVSUBID.@SUBCATID4.@SUBCATID5.@ROWNUM2",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LAB.@CONVSUBID.@SUBCATID4.@SUBCATID5.@ROWNUM2",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtElement_var1 => GetValue(txtElement_var1_Property);
		}

		public class grdSubstrAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.SUBSATT.@CONVSUBID.@POINT",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.PSD3.@CONVSUBID"
				}
			});

			public static readonly CxvPropertyDeclaration txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.CUM_SUBSATT.@CONVSUBID.@POINT",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.PSD3.@CONVSUBID"
				},
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UPPER.@CONVSUBID.@POINT",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LOWER.@CONVSUBID.@POINT",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INTERVAL.@CONVSUBID.@POINT",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "CONVSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtFraction_var1 => GetValue(txtFraction_var1_Property);

			public object txtCumFraction_var1 => GetValue(txtCumFraction_var1_Property);

			public object txtUpperlimit_var1 => GetValue(txtUpperlimit_var1_Property);

			public object txtLowerLimit_var1 => GetValue(txtLowerLimit_var1_Property);

			public object txtInterval_var1 => GetValue(txtInterval_var1_Property);
		}

		public static readonly CxvPropertyDeclaration mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
		{
			Parameter = "CONVSUBID"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NPHASE",
			SelectedItemBinding = "mnbSubstream_target.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
			CompletePaths = { "@main.CC Nodes.CNVSPEC2", "@main.CC Nodes.CNVSPEC3", "@main.CC Nodes.CNVPSD", "@main.CC Nodes.CNVATTR", "@main.CC Nodes.PSPEC2" },
			Filter = new CxvSubstreamFilter
			{
				SubstreamType = CxvSubstreamFilter.eSubstreamType.Conventional
			}
		});

		public static readonly CxvPropertyDeclaration tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTFLOW.@CONVSUBID",
			BasisPath = "@main.Input.FLOWBASE.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTAL.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdComposition_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FLOW.@CONVSUBID",
				UseChildId = true,
				Name = "COMPCONV"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW.@CONVSUBID",
			BasisPath = "@main.Input.BASIS.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID" },
			AccessibleDataPaths = { "@main.CC Nodes.CMP1.@CONVSUBID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_ConvSol_Prompt1
		});

		public static readonly CxvPropertyDeclaration expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.CNVPSD.@CONVSUBID" },
			AccessibleDataPaths = { "@main.CC Nodes.PSD1.@CONVSUBID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_ConvSol_Prompt2
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID5"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@CONVSUBID.@SUBCATID4",
			SelectedItemBinding = "mnbAttribute_var2.Value",
			CreateNewPrompt = "Attribute ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
			CompletePaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID.@SUBCATID4" },
			EnteredPaths = { "@main.CC Nodes.ENTCOMP.@CONVSUBID.@SUBCATID4" },
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID4"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@CONVSUBID",
			SelectedItemBinding = "mnbComponent_var2.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
			CompletePaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID" },
			EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@CONVSUBID" },
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.ELEM.@CONVSUBID.@SUBCATID4.@SUBCATID5",
				UseChildId = true,
				Name = "ROWNUM2",
				ProxyRow = false
			}
		});

		public static readonly CxvPropertyDeclaration txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIMUNITS.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PSDID.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.PSDID.@CONVSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CONVSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.INTERVAL.@CONVSUBID",
				UseChildId = true,
				Name = "POINT"
			}
		});

		private ICommand _cmdCreateWtFrac_Command;

		public static CxvPropertyDeclaration cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.PSD9.@CONVSUBID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.CNVPSD1.@CONVSUBID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		public static readonly CxvPropertyDeclaration ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrSelMethod_var1",
					DataPath = "@main.Input.WTFRAC_OPT.@CONVSUBID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "User specified values",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "USER"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "A distribution function",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "FUNCTION"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CNVPSD1.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD2.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "TypeCBox_var1",
					DataPath = "@main.Input.TYPE.@CONVSUBID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "GGS",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_GGS",
					Value = "Type_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "GGS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RRSB",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_RRSB",
					Value = "Type_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "RRSB"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Normal",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Normal",
					Value = "Type_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "NORMAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Log Normal",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Log_Normal",
					Value = "Type_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "LOG-NORMAL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GGS_N.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DIAM.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.RRSB_N.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D63.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.STDDEV.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D50.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GMDEV.@CONVSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@CONVSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UOM.@CONVSUBID.@SUBCATID4.@SUBCATID5"
		});

		private bool _needUpdateCombos = true;

		private bool _needUpdateSubstream = true;

		private CxvPropertyWatch varOptDependencies;

		private EventHandler _varOptDependencies_PropertyDependencyChangedHandler;

		private bool _ExpandPSD;

		private bool _ExpandCompAttr;

		public object mnbSubstream_target => GetValue(mnbSubstream_target_Property);

		public object mnbSubstream_display => GetValue(mnbSubstream_display_Property);

		public object tempVEdit_var => GetValue(tempVEdit_var_Property);

		public object presVEdit_var => GetValue(presVEdit_var_Property);

		public object lbtuTotalFlow_var1 => GetValue(lbtuTotalFlow_var1_Property);

		public object txtTotal_var1 => GetValue(txtTotal_var1_Property);

		public object grdComposition_GridData => GetValue(grdComposition_GridData_Property);

		public object lbtuComposition_var1 => GetValue(lbtuComposition_var1_Property);

		public object expandar_comattr => GetValue(expandar_comattr_Property);

		public object expandar_psd => GetValue(expandar_psd_Property);

		public object mnbAttribute_var2 => GetValue(mnbAttribute_var2_Property);

		public object mnbAttribute_var1 => GetValue(mnbAttribute_var1_Property);

		public object mnbComponent_var2 => GetValue(mnbComponent_var2_Property);

		public object mnbComponent_var1 => GetValue(mnbComponent_var1_Property);

		public object grdCompAttr_GridData => GetValue(grdCompAttr_GridData_Property);

		public object txtPSDUnits_var1 => GetValue(txtPSDUnits_var1_Property);

		public object txtPSDID_var1 => GetValue(txtPSDID_var1_Property);

		public object psdCBox_var1 => GetValue(psdCBox_var1_Property);

		public object grdSubstrAttr_GridData => GetValue(grdSubstrAttr_GridData_Property);

		public ICommand cmdCreateWtFrac_Command
		{
			get
			{
				if (_cmdCreateWtFrac_Command == null)
				{
					_cmdCreateWtFrac_Command = new CxvDelegateCommand<object>(cmdCreateWtFrac_CommandExecute, this, cmdCreateWtFracCanExecuteProperty.Name + ".Value");
				}
				return _cmdCreateWtFrac_Command;
			}
		}

		public CxvLogicalPropertyData cmdCreateWtFracCanExecute => GetValue(cmdCreateWtFracCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEdit_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEdit_CommandCanExecute => GetValue(cmdEdit_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public object ogrSelMethod_MultiMap => GetValue(ogrSelMethod_MultiMap_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object Type_MultiMap => GetValue(Type_MultiMap_Property);

		public object GGSLbl_state => GetValue(GGSLbl_state_Property);

		public object txtGGSN_var1 => GetValue(txtGGSN_var1_Property);

		public object txtDiam_var1 => GetValue(txtDiam_var1_Property);

		public object RRSBLbl_state => GetValue(RRSBLbl_state_Property);

		public object txtRRSBN_var1 => GetValue(txtRRSBN_var1_Property);

		public object txtD63_var1 => GetValue(txtD63_var1_Property);

		public object StddevLbl_state => GetValue(StddevLbl_state_Property);

		public object txtStddev_var1 => GetValue(txtStddev_var1_Property);

		public object D50Lbl_state => GetValue(D50Lbl_state_Property);

		public object txtD50_var1 => GetValue(txtD50_var1_Property);

		public object GmdevLbl_state => GetValue(GmdevLbl_state_Property);

		public object txtGmdev_var1 => GetValue(txtGmdev_var1_Property);

		public object CompAttrUnits => GetValue(CompAttrUnits_Property);

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

		public bool ExpandPSD
		{
			get
			{
				return _ExpandPSD;
			}
			set
			{
				_ExpandPSD = value;
				OnPropertyChanged("ExpandPSD");
			}
		}

		public bool ExpandCompAttr
		{
			get
			{
				return _ExpandCompAttr;
			}
			set
			{
				_ExpandCompAttr = value;
				OnPropertyChanged("ExpandCompAttr");
			}
		}

		private void cmdCreateWtFrac_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
			if (text2 != "")
			{
				text = text2 + "." + text;
			}
			string text3 = CxsConverter.ValueToString(this.ResolveViewPropertyPath("mnbSubstream_target.Value"));
			this.SMcreatwtfrac(text, text3, "STREAM");
			base.ResolvedCxsProvider.UpdateDataCache();
			string text4 = ExpandDataPath("@main");
			text4 = text4 + ".Input.SUBSATT." + text3;
			string sTitle = text + " Inlet PSD Curve";
			DisplayPlotWizardEventArgs args = new DisplayPlotWizardEventArgs(null, "PSD", sTitle, text4, "WpfPLDISCURVES.RibbonPlotWizardMgr", null, null, true);
			DisplayPlotWizard(args);
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("psdCBox_var1.Value"));
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMMaterial.MMMaterial_Input_Stratt";
			e.LegacyFlags = 0;
			e.ShowPrompts = true;
			e.ShortName = ApwnResources.MMMaterial_Input_Stratt_Title;
			e.CompleteDataPaths = new string[1] { "@main0.CC Nodes.MN1" };
			DisplayFormEventArgs e2 = e;
			e2.Parameters.Add("main0", "Top.appModelV8.Setup.Stream-Class.Subs-Attr." + text);
			DisplayForm(e2);
		}

		private bool IsSubstreamComplete(string id)
		{
			ResolveUpdateParameter("CONVSUBID", id);
			string[] array = new string[5] { "@main.CC Nodes.CNVSPEC2", "@main.CC Nodes.CNVSPEC3", "@main.CC Nodes.CNVPSD", "@main.CC Nodes.CNVATTR", "@main.CC Nodes.PSPEC2" };
			for (int i = 0; i < array.Length; i++)
			{
				string dataPath = array[i] + "." + id;
				if (CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "value", null, varOptDependencies)) == "0")
				{
					return false;
				}
			}
			return true;
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
			CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.PSDID.@CONVSUBID", "value", null, varOptDependencies));
			if (_needUpdateSubstream)
			{
				ResolveParameter("CONVSUBID");
				if (CxsConverter.ValueToString(ResolveParameter("CONVSUBID")) != "")
				{
					CxvDataFilter cxvDataFilter = new CxvSubstreamFilter
					{
						SubstreamType = CxvSubstreamFilter.eSubstreamType.Conventional
					};
					cxvDataFilter.SetContainer(this);
					string dataPath = "@main.Input.NPHASE";
					string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet(dataPath, "child_ids"));
					string text = "";
					string text2 = "";
					string text3 = "";
					bool flag = false;
					if (array != null)
					{
						for (int i = 1; i < array.Length; i++)
						{
							if (cxvDataFilter.Allow(array[i]))
							{
								if (text == "")
								{
									text = array[i];
								}
								ResolveUpdateParameter("CONVSUBID", array[i]);
								if (!IsSubstreamComplete(array[i]))
								{
									flag = true;
									break;
								}
								if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.PSDID.@CONVSUBID", "value", null, varOptDependencies)) != "" && text2 == "")
								{
									text2 = array[i];
								}
								else if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.TEMP.@CONVSUBID", "value", null, varOptDependencies)) != "")
								{
									text3 = array[i];
								}
							}
						}
						if (!flag)
						{
							if (text2 != "")
							{
								ResolveUpdateParameter("CONVSUBID", text2);
							}
							else if (text3 != "")
							{
								ResolveUpdateParameter("CONVSUBID", text3);
							}
							else
							{
								ResolveUpdateParameter("CONVSUBID", text);
							}
						}
						_needUpdateSubstream = false;
						_needUpdateCombos = false;
					}
				}
			}
			bool? flag2 = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.CNVPSD1.@CONVSUBID", "value"));
			if (flag2.HasValue && flag2.Value)
			{
				_ExpandPSD = true;
			}
			bool? flag3 = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.CMP1.@CONVSUBID", "value"));
			if (flag3.HasValue && flag3.Value)
			{
				_ExpandCompAttr = true;
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
	public class MMMaterial_Input_ConvSol : MMTabPage, IComponentConnector
	{
		internal MMExpander spec;

		internal MMGroupBox stateVarGrp;

		internal MMLabel substrLbl;

		internal MMAdvancedComboEdit substrCBox;

		internal MMLabel tempLbl;

		internal MMVariableEdit tempVEdit;

		internal MMLabel presLbl;

		internal MMVariableEdit presVEdit;

		internal MMLabel basisLbl;

		internal MMVariableEdit basisCBox;

		internal MMLabel flrateLbl;

		internal MMVariableEdit flrateCBox;

		internal MMGroupBox compGrp;

		internal Grid compGrid;

		internal MMVariableEdit lbtuComposition;

		internal MMScrollArea compScr;

		internal MMLabel totalLbl;

		internal MMValueEdit totalTxt;

		internal Grid Grid;

		internal MMExpander attrExp;

		internal MMLabel comIDLbl;

		internal MMAdvancedComboEdit comIDCBox;

		internal MMLabel attrIDLbl;

		internal MMAdvancedComboEdit attrIDCBox;

		internal MMScrollAreaMS comAttrScr;

		internal MMExpander PSDExp;

		internal MMLabel PSDLbl;

		internal MMComboEdit psdCBox;

		internal MMLabel unitsLbl;

		internal MMValueEdit unitsTxtbox;

		internal MMCmdButton cmdEdit;

		internal MMGroupBox MMFrame1;

		internal MMOptionGroup ogrSelMethod;

		internal MMOptionButton ogrSelMethod_opt0;

		internal MMOptionButton ogrSelMethod_opt1;

		internal MMGroupBox MMFrame2;

		internal MMLabel TypeLbl;

		internal MMComboEdit TypeCBox;

		internal MMLabel GGSNLbl;

		internal MMValueEdit GGSNTxtbox;

		internal MMLabel DiamLbl;

		internal MMVariableEdit DiamTxtbox;

		internal MMLabel RRSBNLbl;

		internal MMValueEdit RRSBNTxtbox;

		internal MMLabel D63Lbl;

		internal MMVariableEdit D63Txtbox;

		internal MMLabel StddevLbl;

		internal MMVariableEdit StddevTxtbox;

		internal MMLabel D50Lbl;

		internal MMVariableEdit D50Txtbox;

		internal MMLabel GmdevLbl;

		internal MMValueEdit GmdevTxtbox;

		internal MMCmdButton cmdCreateWtFrac;

		internal MMScrollArea PSDScr;

		private bool _contentLoaded;

		public MMMaterial_Input_ConvSol()
		{
			base.ViewModelType = typeof(MMMaterial_Input_ConvSol_ViewModel);
			InitializeComponent();
			PSDScr.SizeChanged += PSDScr_SizeChanged;
		}

		private void PSDScr_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			UpdateChildInnerBorder();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_convsol.xaml", UriKind.Relative);
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
				spec = (MMExpander)target;
				break;
			case 2:
				stateVarGrp = (MMGroupBox)target;
				break;
			case 3:
				substrLbl = (MMLabel)target;
				break;
			case 4:
				substrCBox = (MMAdvancedComboEdit)target;
				break;
			case 5:
				tempLbl = (MMLabel)target;
				break;
			case 6:
				tempVEdit = (MMVariableEdit)target;
				break;
			case 7:
				presLbl = (MMLabel)target;
				break;
			case 8:
				presVEdit = (MMVariableEdit)target;
				break;
			case 9:
				basisLbl = (MMLabel)target;
				break;
			case 10:
				basisCBox = (MMVariableEdit)target;
				break;
			case 11:
				flrateLbl = (MMLabel)target;
				break;
			case 12:
				flrateCBox = (MMVariableEdit)target;
				break;
			case 13:
				compGrp = (MMGroupBox)target;
				break;
			case 14:
				compGrid = (Grid)target;
				break;
			case 15:
				lbtuComposition = (MMVariableEdit)target;
				break;
			case 16:
				compScr = (MMScrollArea)target;
				break;
			case 17:
				totalLbl = (MMLabel)target;
				break;
			case 18:
				totalTxt = (MMValueEdit)target;
				break;
			case 19:
				Grid = (Grid)target;
				break;
			case 20:
				attrExp = (MMExpander)target;
				break;
			case 21:
				comIDLbl = (MMLabel)target;
				break;
			case 22:
				comIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 23:
				attrIDLbl = (MMLabel)target;
				break;
			case 24:
				attrIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 25:
				comAttrScr = (MMScrollAreaMS)target;
				break;
			case 26:
				PSDExp = (MMExpander)target;
				break;
			case 27:
				PSDLbl = (MMLabel)target;
				break;
			case 28:
				psdCBox = (MMComboEdit)target;
				break;
			case 29:
				unitsLbl = (MMLabel)target;
				break;
			case 30:
				unitsTxtbox = (MMValueEdit)target;
				break;
			case 31:
				cmdEdit = (MMCmdButton)target;
				break;
			case 32:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 33:
				ogrSelMethod = (MMOptionGroup)target;
				break;
			case 34:
				ogrSelMethod_opt0 = (MMOptionButton)target;
				break;
			case 35:
				ogrSelMethod_opt1 = (MMOptionButton)target;
				break;
			case 36:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 37:
				TypeLbl = (MMLabel)target;
				break;
			case 38:
				TypeCBox = (MMComboEdit)target;
				break;
			case 39:
				GGSNLbl = (MMLabel)target;
				break;
			case 40:
				GGSNTxtbox = (MMValueEdit)target;
				break;
			case 41:
				DiamLbl = (MMLabel)target;
				break;
			case 42:
				DiamTxtbox = (MMVariableEdit)target;
				break;
			case 43:
				RRSBNLbl = (MMLabel)target;
				break;
			case 44:
				RRSBNTxtbox = (MMValueEdit)target;
				break;
			case 45:
				D63Lbl = (MMLabel)target;
				break;
			case 46:
				D63Txtbox = (MMVariableEdit)target;
				break;
			case 47:
				StddevLbl = (MMLabel)target;
				break;
			case 48:
				StddevTxtbox = (MMVariableEdit)target;
				break;
			case 49:
				D50Lbl = (MMLabel)target;
				break;
			case 50:
				D50Txtbox = (MMVariableEdit)target;
				break;
			case 51:
				GmdevLbl = (MMLabel)target;
				break;
			case 52:
				GmdevTxtbox = (MMValueEdit)target;
				break;
			case 53:
				cmdCreateWtFrac = (MMCmdButton)target;
				break;
			case 54:
				PSDScr = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Costing_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_Input_Costing_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRICE"
		});

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);
	}
	[ProgId("MMMaterial.MMMaterial_Input_Costing")]
	public class MMMaterial_Input_Costing : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		private bool _contentLoaded;

		public MMMaterial_Input_Costing()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Costing_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_costing.xaml", UriKind.Relative);
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
				MMLBUText1_label = (MMLabel)target;
				break;
			case 3:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Flasho_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuTolerance_var1_Property = CxvPropertyDeclaration.Register("lbtuTolerance_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL.MIXED",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.NOFL.MIXED"
			}
		});

		public static readonly CxvPropertyDeclaration chkStreamProps_var1_Property = CxvPropertyDeclaration.Register("chkStreamProps_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.FL_OPTION.MIXED",
			FalseValue = "NOFLASH",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration cboValidPhases_MultiMap_Property = CxvPropertyDeclaration.Register("cboValidPhases_MultiMap", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboValidPhases_var1",
					DataPath = "@main.Input.NPHASE.MIXED"
				},
				new CxvMultiMapVariable
				{
					Name = "cboValidPhases_var2",
					DataPath = "@main.Input.PHASE.MIXED"
				},
				new CxvMultiMapVariable
				{
					Name = "cboValidPhases_var3",
					DataPath = "@main.Input.FREE_WATER.MIXED"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboValidPhases_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboValidPhases_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboValidPhases_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboValidPhases_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_consider",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboValidPhases_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__a",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "3"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Freewater",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Freewater",
					Value = "cboValidPhases_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Freewater",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Freewater",
					Value = "cboValidPhases_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Dirtywater",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Dirtywater",
					Value = "cboValidPhases_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Dirtywater",
					DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Dirtywater",
					Value = "cboValidPhases_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_wate",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var2",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var3",
							Value = "DIRTY"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.NOFL.MIXED"
			}
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT.MIXED",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.NOFL.MIXED"
			}
		});

		public object lbtuTolerance_var1 => GetValue(lbtuTolerance_var1_Property);

		public object chkStreamProps_var1 => GetValue(chkStreamProps_var1_Property);

		public object cboValidPhases_MultiMap => GetValue(cboValidPhases_MultiMap_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);
	}
	[ProgId("MMMaterial.MMMaterial_Input_Flasho")]
	public class MMMaterial_Input_Flasho : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraFlashCalcs;

		internal MMCheckBox chkStreamProps;

		internal MMLabel cboValidPhases_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		private bool _contentLoaded;

		public MMMaterial_Input_Flasho()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Flasho_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_flasho.xaml", UriKind.Relative);
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
				fraFlashCalcs = (MMGroupBox)target;
				break;
			case 2:
				chkStreamProps = (MMCheckBox)target;
				break;
			case 3:
				cboValidPhases_label = (MMLabel)target;
				break;
			case 4:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 5:
				spnMaxit_label = (MMLabel)target;
				break;
			case 6:
				spnMaxit = (MMSpinBox)target;
				break;
			case 7:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 8:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ProgId("MMMaterial.MMMaterial_Input_Info")]
	public class MMMaterial_Input_Info : MMTabPage, IComponentConnector
	{
		internal MMValueEdit streamName;

		internal MMLabel streamType;

		internal MMValueEdit fromValue;

		internal MMValueEdit toValue;

		internal MMValueEdit descriptionValue;

		internal MMDescription commentsDescription;

		private bool _contentLoaded;

		public MMMaterial_Input_Info()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Info_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_info.xaml", UriKind.Relative);
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
				streamName = (MMValueEdit)target;
				break;
			case 2:
				streamType = (MMLabel)target;
				break;
			case 3:
				fromValue = (MMValueEdit)target;
				break;
			case 4:
				toValue = (MMValueEdit)target;
				break;
			case 5:
				descriptionValue = (MMValueEdit)target;
				break;
			case 6:
				commentsDescription = (MMDescription)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	internal class MMMaterial_Input_MixedPha_ViewModel : MMTabPageViewModel
	{
		public class grdComposition_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FLOW.@SubID.@COMPMIXED"
			});

			public static readonly CxvPropertyDeclaration txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FLOW.@SubID.@COMPMIXED"
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtXomponent_var1 => GetValue(txtXomponent_var1_Property);
		}

		public class grdCompAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ELEM.@SubID.@SUBCATID2.@SUBCATID3.@ROWNUM"
			});

			public static readonly CxvPropertyDeclaration txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LAB.@SubID.@SUBCATID2.@SUBCATID3.@ROWNUM"
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtElement_var1 => GetValue(txtElement_var1_Property);
		}

		public class grdSubstrAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC Nodes.PSD3.@SubID",
								Value = 1,
								Operator = CxvLogicalOperator.Equal
							}
						},
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.SUBSATT.@SubID.@POINT"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC Nodes.PSD3.@SubID",
								Value = 0,
								Operator = CxvLogicalOperator.Equal
							}
						},
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.SUBSATT.@SubID.@POINT",
							IsReadOnly = true
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.CUM_SUBSATT.@SubID.@POINT",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UPPER.@SubID.@POINT"
			});

			public static readonly CxvPropertyDeclaration txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LOWER.@SubID.@POINT"
			});

			public static readonly CxvPropertyDeclaration txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INTERVAL.@SubID.@POINT"
			});

			public object txtFraction_var1 => GetValue(txtFraction_var1_Property);

			public object txtCumFraction_var1 => GetValue(txtCumFraction_var1_Property);

			public object txtUpperlimit_var1 => GetValue(txtUpperlimit_var1_Property);

			public object txtLowerLimit_var1 => GetValue(txtLowerLimit_var1_Property);

			public object txtInterval_var1 => GetValue(txtInterval_var1_Property);
		}

		public static readonly CxvPropertyDeclaration mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NPHASE",
			SelectedItemBinding = "mnbSubstream_target.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
			CompletePaths = { "@main.CC Nodes.SPEC2", "@main.CC Nodes.ATTR" },
			Filter = new CxvSubstreamFilter
			{
				SubstreamType = CxvSubstreamFilter.eSubstreamType.Mixed
			}
		});

		public static readonly CxvPropertyDeclaration cboSpecOpt_var1_Property = CxvPropertyDeclaration.Register("cboSpecOpt_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
		{
			Parameter = "SpecOpt1"
		});

		public static readonly CxvPropertyDeclaration cboSpecOpt_var2_Property = CxvPropertyDeclaration.Register("cboSpecOpt_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
		{
			Parameter = "SpecOpt2"
		});

		public static readonly CxvPropertyDeclaration cboSpecOpt_AdvCollection1_Property = CxvPropertyDeclaration.Register("cboSpecOpt_AdvCollection1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "Temperature",
					EnabledPropertyPath = "Opt2NotTemp.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display1"
				},
				new CxvAdvCollectionItem
				{
					Display = "Pressure",
					EnabledPropertyPath = "Opt2NotPress.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display_Pressure"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vapor Fraction",
					EnabledPropertyPath = "Opt2NotVap.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display_VaporFraction"
				}
			},
			SelectedItemBinding = "cboSpecOpt_var1.Value"
		});

		public static readonly CxvPropertyDeclaration cboSpecOpt_AdvCollection2_Property = CxvPropertyDeclaration.Register("cboSpecOpt_AdvCollection2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
		{
			UseItemsCollection = true,
			Items = 
			{
				new CxvAdvCollectionItem
				{
					Display = "Temperature",
					EnabledPropertyPath = "Opt1NotTemp.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display1"
				},
				new CxvAdvCollectionItem
				{
					Display = "Pressure",
					EnabledPropertyPath = "Opt1NotPress.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display2"
				},
				new CxvAdvCollectionItem
				{
					Display = "Vapor Fraction",
					EnabledPropertyPath = "Opt1NotVap.Value",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_Display3"
				}
			},
			SelectedItemBinding = "cboSpecOpt_var2.Value"
		});

		public static CxvPropertyDeclaration Opt1NotTemp_Property = CxvPropertyDeclaration.Register("Opt1NotTemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var1.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Temperature"
		});

		public static CxvPropertyDeclaration Opt1NotPress_Property = CxvPropertyDeclaration.Register("Opt1NotPress", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var1.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Pressure"
		});

		public static CxvPropertyDeclaration Opt1NotVap_Property = CxvPropertyDeclaration.Register("Opt1NotVap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var1.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Vapor Fraction"
		});

		public static CxvPropertyDeclaration Opt2NotTemp_Property = CxvPropertyDeclaration.Register("Opt2NotTemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var2.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Temperature"
		});

		public static CxvPropertyDeclaration Opt2NotPress_Property = CxvPropertyDeclaration.Register("Opt2NotPress", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var2.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Pressure"
		});

		public static CxvPropertyDeclaration Opt2NotVap_Property = CxvPropertyDeclaration.Register("Opt2NotVap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "cboSpecOpt_var2.Value",
			Operator = CxvLogicalOperator.NotEqual,
			Value = "Vapor Fraction"
		});

		public static readonly CxvPropertyDeclaration cboSpecOpt_MultiMap_Property = CxvPropertyDeclaration.Register("cboSpecOpt_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboSpecOpt_MIXED_SPEC",
					DataPath = "@main.Input.MIXED_SPEC.@SubID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Temperature & pressure",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Temperature_pressure",
					Value = "cboSpecOpt_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSpecOpt_MIXED_SPEC",
							Value = "TP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Temperature & vapor fraction",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Temperature_vaporfraction",
					Value = "cboSpecOpt_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSpecOpt_MIXED_SPEC",
							Value = "TV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Pressure & vapor fraction",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Pressure_vaporfraction",
					Value = "cboSpecOpt_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSpecOpt_MIXED_SPEC",
							Value = "PV"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration SubID_var_Property = CxvPropertyDeclaration.Register("SubID_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.#0",
			ExposeAs = CxvVariableTypeCode.Id
		});

		public static readonly CxvPropertyDeclaration tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.TEMP.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PRES.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration vaporVEdit_var_Property = CxvPropertyDeclaration.Register("vaporVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRAC.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.FRAC.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTFLOW.@SubID",
			BasisPath = "@main.Input.FLOWBASE.@SubID"
		});

		public static readonly CxvPropertyDeclaration cboSolvent_var1_Property = CxvPropertyDeclaration.Register("cboSolvent_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.SOLVENT.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SOLV.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration expandar_reftemp_Property = CxvPropertyDeclaration.Register("expandar_reftemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
		{
			EnteredDataPaths = { "@main.CC Nodes.ENTREF.@SubID" },
			AccessibleDataPaths = { "@main.CC Nodes.REFT1.@SubID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt1
		});

		public static readonly CxvPropertyDeclaration lbtuVolRef_var1_Property = CxvPropertyDeclaration.Register("lbtuVolRef_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VOL_TREF.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.REFT1.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuConcRef_var1_Property = CxvPropertyDeclaration.Register("lbtuConcRef_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.CONC_TREF.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.REFT2.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTAL.@SubID"
		});

		public static readonly CxvPropertyDeclaration lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW.@SubID",
			BasisPath = "@main.Input.BASIS.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Input.FLOW.@SubID",
				DataAttribute = "has_children",
				Operator = CxvLogicalOperator.Equal,
				Value = 1
			}
		});

		public static readonly CxvPropertyDeclaration grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdComposition_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FLOW.@SUBSTRID",
				UseChildId = true,
				Name = "COMPMIXED"
			}
		});

		public static readonly CxvPropertyDeclaration expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.ATTR.@SubID" },
			AccessibleDataPaths = { "@main.CC Nodes.CMP1.@SUBSTRID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt2
		});

		public static readonly CxvPropertyDeclaration expanderAttr_state_Property = CxvPropertyDeclaration.Register("expanderAttr_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.ATTR1"
			}
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID3"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@SubID.@SUBCATID2",
			SelectedItemBinding = "mnbAttribute_var2.Value",
			CreateNewPrompt = "Attribute ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
			CompletePaths = { "@main.CC Nodes.ATTR.@SubID.@SUBCATID2" },
			EnteredPaths = { "@main.CC Nodes.ENTCOMP.@SubID.@SUBCATID2" }
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID2"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@SubID",
			SelectedItemBinding = "mnbComponent_var2.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
			CompletePaths = { "@main.CC Nodes.ATTR.@SubID" },
			EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@SubID" }
		});

		public static readonly CxvPropertyDeclaration grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.ELEM.@SubID.@SUBCATID2.@SUBCATID3",
				UseChildId = true,
				Name = "ROWNUM",
				ProxyRow = false
			}
		});

		private Visibility _mmAdvCombo1_Visibility;

		private CxvPropertyWatch varOptDependencies;

		private EventHandler _varOptDependencies_PropertyDependencyChangedHandler;

		private bool _needUpdateVar = true;

		private bool _needUpdateCombos = true;

		private bool _ExpandPSD;

		private bool _ExpandCompAttr;

		private Collection<string> _oldids;

		public static readonly CxvPropertyDeclaration expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.MIXPSD" },
			AccessibleDataPaths = { "@main.CC Nodes.PSD12" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt3
		});

		public static readonly CxvPropertyDeclaration txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIMUNITS.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "#0",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PSDID.@SubID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.INTERVAL.@SubID",
				UseChildId = true,
				Name = "POINT"
			}
		});

		private ICommand _cmdCreateWtFrac_Command;

		public static CxvPropertyDeclaration cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.PSD9.@SubID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.MIXPSD1.@SubID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		public static readonly CxvPropertyDeclaration psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.PSDID.@SubID"
		});

		public static readonly CxvPropertyDeclaration ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrSelMethod_var1",
					DataPath = "@main.Input.WTFRAC_OPT.@SubID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "User specified values",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "USER"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "A distribution function",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "FUNCTION"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.MIXPSD1.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD2.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "TypeCBox_var1",
					DataPath = "@main.Input.TYPE.@SubID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "GGS",
					DisplayResourceKey = "",
					Value = "Type_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "GGS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RRSB",
					DisplayResourceKey = "",
					Value = "Type_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "RRSB"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Normal",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel_Normal",
					Value = "Type_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "NORMAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Log Normal",
					DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel_LogNormal",
					Value = "Type_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "LOG-NORMAL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GGS_N.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DIAM.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.RRSB_N.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D63.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.STDDEV.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D50.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GMDEV.@SubID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@SubID"
			}
		});

		public static readonly CxvPropertyDeclaration CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UOM.@SubID.@SUBCATID2.@SUBCATID3"
		});

		public object mnbSubstream_target => GetValue(mnbSubstream_target_Property);

		public object mnbSubstream_display => GetValue(mnbSubstream_display_Property);

		public object cboSpecOpt_var1 => GetValue(cboSpecOpt_var1_Property);

		public object cboSpecOpt_var2 => GetValue(cboSpecOpt_var2_Property);

		public object cboSpecOpt_AdvCollection1 => GetValue(cboSpecOpt_AdvCollection1_Property);

		public object cboSpecOpt_AdvCollection2 => GetValue(cboSpecOpt_AdvCollection2_Property);

		public object Opt1NotTemp => GetValue(Opt1NotTemp_Property);

		public object Opt1NotPress => GetValue(Opt1NotPress_Property);

		public object Opt1NotVap => GetValue(Opt1NotVap_Property);

		public object Opt2NotTemp => GetValue(Opt2NotTemp_Property);

		public object Opt2NotPress => GetValue(Opt2NotPress_Property);

		public object Opt2NotVap => GetValue(Opt2NotVap_Property);

		public object cboSpecOpt_MultiMap => GetValue(cboSpecOpt_MultiMap_Property);

		public object SubID_var => GetValue(SubID_var_Property);

		public object tempVEdit_var => GetValue(tempVEdit_var_Property);

		public object presVEdit_var => GetValue(presVEdit_var_Property);

		public object vaporVEdit_var => GetValue(vaporVEdit_var_Property);

		public object lbtuTotalFlow_var1 => GetValue(lbtuTotalFlow_var1_Property);

		public object cboSolvent_var1 => GetValue(cboSolvent_var1_Property);

		public object expandar_reftemp => GetValue(expandar_reftemp_Property);

		public object lbtuVolRef_var1 => GetValue(lbtuVolRef_var1_Property);

		public object lbtuConcRef_var1 => GetValue(lbtuConcRef_var1_Property);

		public object txtTotal_var1 => GetValue(txtTotal_var1_Property);

		public object lbtuComposition_var1 => GetValue(lbtuComposition_var1_Property);

		public object grdComposition_GridData => GetValue(grdComposition_GridData_Property);

		public object expandar_comattr => GetValue(expandar_comattr_Property);

		public object expanderAttr_state => GetValue(expanderAttr_state_Property);

		public object mnbAttribute_var2 => GetValue(mnbAttribute_var2_Property);

		public object mnbAttribute_var1 => GetValue(mnbAttribute_var1_Property);

		public object mnbComponent_var2 => GetValue(mnbComponent_var2_Property);

		public object mnbComponent_var1 => GetValue(mnbComponent_var1_Property);

		public object grdCompAttr_GridData => GetValue(grdCompAttr_GridData_Property);

		public Visibility MMAdvCombo1_Visibility
		{
			get
			{
				return _mmAdvCombo1_Visibility;
			}
			set
			{
				_mmAdvCombo1_Visibility = value;
				OnPropertyChanged("MMAdvCombo1_Visibility");
			}
		}

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
							UpdateMixedSpec();
						}
					};
				}
				return _varOptDependencies_PropertyDependencyChangedHandler;
			}
		}

		public bool ExpandPSD
		{
			get
			{
				return _ExpandPSD;
			}
			set
			{
				_ExpandPSD = value;
				OnPropertyChanged("ExpandPSD");
			}
		}

		public bool ExpandCompAttr
		{
			get
			{
				return _ExpandCompAttr;
			}
			set
			{
				_ExpandCompAttr = value;
				OnPropertyChanged("ExpandCompAttr");
			}
		}

		public object expandar_psd => GetValue(expandar_psd_Property);

		public object txtPSDUnits_var1 => GetValue(txtPSDUnits_var1_Property);

		public object txtPSDID_var1 => GetValue(txtPSDID_var1_Property);

		public object grdSubstrAttr_GridData => GetValue(grdSubstrAttr_GridData_Property);

		public ICommand cmdCreateWtFrac_Command
		{
			get
			{
				if (_cmdCreateWtFrac_Command == null)
				{
					_cmdCreateWtFrac_Command = new CxvDelegateCommand<object>(cmdCreateWtFrac_CommandExecute, this, cmdCreateWtFracCanExecuteProperty.Name + ".Value");
				}
				return _cmdCreateWtFrac_Command;
			}
		}

		public CxvLogicalPropertyData cmdCreateWtFracCanExecute => GetValue(cmdCreateWtFracCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEdit_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEdit_CommandCanExecute => GetValue(cmdEdit_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public object psdCBox_var1 => GetValue(psdCBox_var1_Property);

		public object ogrSelMethod_MultiMap => GetValue(ogrSelMethod_MultiMap_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object Type_MultiMap => GetValue(Type_MultiMap_Property);

		public object GGSLbl_state => GetValue(GGSLbl_state_Property);

		public object txtGGSN_var1 => GetValue(txtGGSN_var1_Property);

		public object txtDiam_var1 => GetValue(txtDiam_var1_Property);

		public object RRSBLbl_state => GetValue(RRSBLbl_state_Property);

		public object txtRRSBN_var1 => GetValue(txtRRSBN_var1_Property);

		public object txtD63_var1 => GetValue(txtD63_var1_Property);

		public object StddevLbl_state => GetValue(StddevLbl_state_Property);

		public object txtStddev_var1 => GetValue(txtStddev_var1_Property);

		public object D50Lbl_state => GetValue(D50Lbl_state_Property);

		public object txtD50_var1 => GetValue(txtD50_var1_Property);

		public object GmdevLbl_state => GetValue(GmdevLbl_state_Property);

		public object txtGmdev_var1 => GetValue(txtGmdev_var1_Property);

		public object CompAttrUnits => GetValue(CompAttrUnits_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string value = CxsConverter.ValueToString(ResolveViewPropertyPath("SubID_var.Value", null));
				ResolveUpdateParameter("SubID", value);
				UpdateMixedSpec();
				MMAdvCombo1_Visibility = Visibility.Collapsed;
			}
			base.OnUpdateData();
		}

		private void UpdateMixedSpec()
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
			_needUpdateVar = false;
			switch (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.MIXED_SPEC.@SubID", "value", null, varOptDependencies)))
			{
			case "TP":
				ResolveUpdateViewPropertyPath("cboSpecOpt_var1.Value", "Temperature");
				ResolveUpdateViewPropertyPath("cboSpecOpt_var2.Value", "Pressure");
				break;
			case "TV":
				ResolveUpdateViewPropertyPath("cboSpecOpt_var1.Value", "Temperature");
				ResolveUpdateViewPropertyPath("cboSpecOpt_var2.Value", "Vapor Fraction");
				break;
			case "PV":
				ResolveUpdateViewPropertyPath("cboSpecOpt_var1.Value", "Pressure");
				ResolveUpdateViewPropertyPath("cboSpecOpt_var2.Value", "Vapor Fraction");
				break;
			}
			_needUpdateVar = true;
			bool? flag = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.PSD12", "value"));
			if (flag.HasValue && flag.Value)
			{
				_ExpandPSD = true;
			}
			bool? flag2 = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.CMP1.#1", "value"));
			if (flag2.HasValue && flag2.Value)
			{
				_ExpandCompAttr = true;
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

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if ((pd.Name == "cboSpecOpt_var1" || pd.Name == "cboSpecOpt_var2") && subPropertyName == "Value" && _needUpdateVar)
			{
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData = cboSpecOpt_AdvCollection1 as CxvAdvCollectionPropertyData;
				CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData2 = cboSpecOpt_AdvCollection2 as CxvAdvCollectionPropertyData;
				string text = null;
				if (cxvAdvCollectionPropertyData.SelectedItem == "Temperature" || cxvAdvCollectionPropertyData.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display1)
				{
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Pressure" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display2)
					{
						text = "TP";
					}
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Vapor Fraction" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display3)
					{
						text = "TV";
					}
				}
				else if (cxvAdvCollectionPropertyData.SelectedItem == "Pressure" || cxvAdvCollectionPropertyData.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display2)
				{
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Temperature" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display1)
					{
						text = "TP";
					}
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Vapor Fraction" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display3)
					{
						text = "PV";
					}
				}
				else if (cxvAdvCollectionPropertyData.SelectedItem == "Vapor Fraction" || cxvAdvCollectionPropertyData.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display3)
				{
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Temperature" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display1)
					{
						text = "TV";
					}
					if (cxvAdvCollectionPropertyData2.SelectedItem == "Pressure" || cxvAdvCollectionPropertyData2.SelectedItem == Resources.MMMaterial_Input_MixedPha_Display2)
					{
						text = "PV";
					}
				}
				string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.MIXED_SPEC.@SubID", "value"));
				if (!string.IsNullOrEmpty(text) && text2 != text)
				{
					_needUpdateCombos = false;
					bool num = ExpandDataPathAndSet("@main.Input.MIXED_SPEC.@SubID", "value", text);
					base.ResolvedCxsProvider.UpdateDataCache();
					_needUpdateCombos = true;
					if (!num)
					{
						(base.View as MMTabPage).Dispatcher.BeginInvoke(DispatcherPriority.Input, (Action)delegate
						{
							UpdateMixedSpec();
						});
					}
				}
			}
			if (pd == mnbAttribute_var1_Property && subPropertyName == "Items")
			{
				Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.NEL.@SubID.@SUBCATID2", "child_ids"));
				if (collection != null && !IsSameCollection(collection, _oldids))
				{
					foreach (string item in collection)
					{
						if (CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.ATTR.@SubID.@SUBCATID2." + item, "value")) != true)
						{
							ResolveUpdateParameter("SUBCATID3", item);
							break;
						}
					}
				}
				_oldids = collection;
			}
			else if (pd == SubID_var_Property && subPropertyName == "Value")
			{
				string value = CxsConverter.ValueToString(ResolveViewPropertyPath("SubID_var.Value", null));
				ResolveUpdateParameter("SubID", value, localOnly: true);
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		private static bool IsSameCollection(Collection<string> c1, Collection<string> c2)
		{
			if (c1 == null && c2 == null)
			{
				return true;
			}
			if ((c1 == null && c2 != null) || (c1 != null && c2 == null))
			{
				return false;
			}
			if (c1.Count != c2.Count)
			{
				return false;
			}
			for (int i = 0; i < c1.Count; i++)
			{
				if (c1[i] != c2[i])
				{
					return false;
				}
			}
			return true;
		}

		private void cmdCreateWtFrac_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
			if (text2 != "")
			{
				text = text2 + "." + text;
			}
			string text3 = CxsConverter.ValueToString(this.ResolveViewPropertyPath("mnbSubstream_target.Value"));
			this.SMcreatwtfrac(text, text3, "STREAM");
			base.ResolvedCxsProvider.UpdateDataCache();
			string text4 = ExpandDataPath("@main");
			text4 = text4 + ".Input.SUBSATT." + text3;
			string sTitle = text + " Inlet PSD Curve";
			DisplayPlotWizardEventArgs args = new DisplayPlotWizardEventArgs(null, "PSD", sTitle, text4, "WpfPLDISCURVES.RibbonPlotWizardMgr", null, null, true);
			DisplayPlotWizard(args);
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("psdCBox_var1.Value"));
			if (text.Length > 0)
			{
				DisplayFormEventArgs e = new DisplayFormEventArgs();
				e.FormProgId = "MMMaterial.MMMaterial_Input_Stratt";
				e.LegacyFlags = 0;
				e.ShowPrompts = true;
				e.ShortName = ApwnResources.MMMaterial_Input_Stratt_Title;
				e.CompleteDataPaths = new string[1] { "@main0.CC Nodes.MN1" };
				DisplayFormEventArgs e2 = e;
				e2.Parameters.Add("main0", "Top.appModelV8.Setup.Stream-Class.Subs-Attr." + text);
				DisplayForm(e2);
			}
		}
	}
	public class MMMaterial_Input_MixedPha : MMTabPage, IComponentConnector
	{
		internal MMExpander spec;

		internal Grid grdLeft;

		internal MMAdvancedComboEdit substrCBox;

		internal MMLabel SpecOptLbl;

		internal MMComboEdit cboSpecOpt1;

		internal MMComboEdit cboSpecOpt2;

		internal MMGroupBox stateVarGrp;

		internal Grid statevarGrid;

		internal MMLabel tempLbl;

		internal MMVariableEdit tempVEdit;

		internal MMLabel presLbl;

		internal MMVariableEdit presVEdit;

		internal MMLabel vaporLbl;

		internal MMVariableEdit vaporVEdit;

		internal MMLabel tlflowLbl;

		internal MMVariableEdit tlflowCBox;

		internal MMLabel flrateLbl;

		internal MMVariableEdit flrateVEdit;

		internal MMLabel solventLbl;

		internal MMComboEdit solCBox;

		internal MMGroupBox refTemp;

		internal MMLabel flRtmpLbl11;

		internal MMVariableEdit flRtmpVEdit1;

		internal MMLabel coRtmpLbl11;

		internal MMVariableEdit coRtmpVEdit1;

		internal MMGroupBox compGrp;

		internal Grid compGrid;

		internal MMVariableEdit lbtuComposition;

		internal MMScrollAreaMS compScr;

		internal MMLabel totalLbl;

		internal MMValueEdit totalTxt;

		internal Grid Grid;

		internal MMExpander attrExp;

		internal MMLabel comIDLbl;

		internal MMAdvancedComboEdit comIDCBox;

		internal MMLabel attrIDLbl;

		internal MMAdvancedComboEdit attrIDCBox;

		internal MMScrollAreaMS comAttrScr;

		internal MMExpander PSDExp;

		internal MMLabel PSDLbl;

		internal MMComboEdit psdCBox;

		internal MMLabel unitsLbl;

		internal MMValueEdit unitsTxtbox;

		internal MMCmdButton cmdEdit;

		internal MMGroupBox MMFrame1;

		internal MMOptionGroup ogrSelMethod;

		internal MMOptionButton ogrSelMethod_opt0;

		internal MMOptionButton ogrSelMethod_opt1;

		internal MMGroupBox MMFrame2;

		internal MMLabel TypeLbl;

		internal MMComboEdit TypeCBox;

		internal MMLabel GGSNLbl;

		internal MMValueEdit GGSNTxtbox;

		internal MMLabel DiamLbl;

		internal MMVariableEdit DiamTxtbox;

		internal MMLabel RRSBNLbl;

		internal MMValueEdit RRSBNTxtbox;

		internal MMLabel D63Lbl;

		internal MMVariableEdit D63Txtbox;

		internal MMLabel StddevLbl;

		internal MMVariableEdit StddevTxtbox;

		internal MMLabel D50Lbl;

		internal MMVariableEdit D50Txtbox;

		internal MMLabel GmdevLbl;

		internal MMValueEdit GmdevTxtbox;

		internal MMCmdButton cmdCreateWtFrac;

		internal MMScrollAreaMS PSDScr;

		private bool _contentLoaded;

		public MMMaterial_Input_MixedPha()
		{
			base.ViewModelType = typeof(MMMaterial_Input_MixedPha_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_mixedpha.xaml", UriKind.Relative);
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
				spec = (MMExpander)target;
				break;
			case 2:
				grdLeft = (Grid)target;
				break;
			case 3:
				substrCBox = (MMAdvancedComboEdit)target;
				break;
			case 4:
				SpecOptLbl = (MMLabel)target;
				break;
			case 5:
				cboSpecOpt1 = (MMComboEdit)target;
				break;
			case 6:
				cboSpecOpt2 = (MMComboEdit)target;
				break;
			case 7:
				stateVarGrp = (MMGroupBox)target;
				break;
			case 8:
				statevarGrid = (Grid)target;
				break;
			case 9:
				tempLbl = (MMLabel)target;
				break;
			case 10:
				tempVEdit = (MMVariableEdit)target;
				break;
			case 11:
				presLbl = (MMLabel)target;
				break;
			case 12:
				presVEdit = (MMVariableEdit)target;
				break;
			case 13:
				vaporLbl = (MMLabel)target;
				break;
			case 14:
				vaporVEdit = (MMVariableEdit)target;
				break;
			case 15:
				tlflowLbl = (MMLabel)target;
				break;
			case 16:
				tlflowCBox = (MMVariableEdit)target;
				break;
			case 17:
				flrateLbl = (MMLabel)target;
				break;
			case 18:
				flrateVEdit = (MMVariableEdit)target;
				break;
			case 19:
				solventLbl = (MMLabel)target;
				break;
			case 20:
				solCBox = (MMComboEdit)target;
				break;
			case 21:
				refTemp = (MMGroupBox)target;
				break;
			case 22:
				flRtmpLbl11 = (MMLabel)target;
				break;
			case 23:
				flRtmpVEdit1 = (MMVariableEdit)target;
				break;
			case 24:
				coRtmpLbl11 = (MMLabel)target;
				break;
			case 25:
				coRtmpVEdit1 = (MMVariableEdit)target;
				break;
			case 26:
				compGrp = (MMGroupBox)target;
				break;
			case 27:
				compGrid = (Grid)target;
				break;
			case 28:
				lbtuComposition = (MMVariableEdit)target;
				break;
			case 29:
				compScr = (MMScrollAreaMS)target;
				break;
			case 30:
				totalLbl = (MMLabel)target;
				break;
			case 31:
				totalTxt = (MMValueEdit)target;
				break;
			case 32:
				Grid = (Grid)target;
				break;
			case 33:
				attrExp = (MMExpander)target;
				break;
			case 34:
				comIDLbl = (MMLabel)target;
				break;
			case 35:
				comIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 36:
				attrIDLbl = (MMLabel)target;
				break;
			case 37:
				attrIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 38:
				comAttrScr = (MMScrollAreaMS)target;
				break;
			case 39:
				PSDExp = (MMExpander)target;
				break;
			case 40:
				PSDLbl = (MMLabel)target;
				break;
			case 41:
				psdCBox = (MMComboEdit)target;
				break;
			case 42:
				unitsLbl = (MMLabel)target;
				break;
			case 43:
				unitsTxtbox = (MMValueEdit)target;
				break;
			case 44:
				cmdEdit = (MMCmdButton)target;
				break;
			case 45:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 46:
				ogrSelMethod = (MMOptionGroup)target;
				break;
			case 47:
				ogrSelMethod_opt0 = (MMOptionButton)target;
				break;
			case 48:
				ogrSelMethod_opt1 = (MMOptionButton)target;
				break;
			case 49:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 50:
				TypeLbl = (MMLabel)target;
				break;
			case 51:
				TypeCBox = (MMComboEdit)target;
				break;
			case 52:
				GGSNLbl = (MMLabel)target;
				break;
			case 53:
				GGSNTxtbox = (MMValueEdit)target;
				break;
			case 54:
				DiamLbl = (MMLabel)target;
				break;
			case 55:
				DiamTxtbox = (MMVariableEdit)target;
				break;
			case 56:
				RRSBNLbl = (MMLabel)target;
				break;
			case 57:
				RRSBNTxtbox = (MMValueEdit)target;
				break;
			case 58:
				D63Lbl = (MMLabel)target;
				break;
			case 59:
				D63Txtbox = (MMVariableEdit)target;
				break;
			case 60:
				StddevLbl = (MMLabel)target;
				break;
			case 61:
				StddevTxtbox = (MMVariableEdit)target;
				break;
			case 62:
				D50Lbl = (MMLabel)target;
				break;
			case 63:
				D50Txtbox = (MMVariableEdit)target;
				break;
			case 64:
				GmdevLbl = (MMLabel)target;
				break;
			case 65:
				GmdevTxtbox = (MMValueEdit)target;
				break;
			case 66:
				cmdCreateWtFrac = (MMCmdButton)target;
				break;
			case 67:
				PSDScr = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	internal class MMMaterial_Input_NCSolid_ViewModel : MMTabPageViewModel
	{
		public class grdComposition_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FLOW.@NCSUBID.@COMPCONV",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FLOW.@NCSUBID.@COMPCONV",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtXomponent_var1 => GetValue(txtXomponent_var1_Property);
		}

		public class grdCompAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ELEM.@NCSUBID.@SUBCATID6.@SUBCATID7.@ROWNUM3",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LAB.@NCSUBID.@SUBCATID6.@SUBCATID7.@ROWNUM3",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtElement_var1 => GetValue(txtElement_var1_Property);
		}

		public class grdSubstrAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.SUBSATT.@NCSUBID.@POINT2",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.PSD3.@NCSUBID"
				}
			});

			public static readonly CxvPropertyDeclaration txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.CUM_SUBSATT.@NCSUBID.@POINT2",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.PSD3.@NCSUBID"
				}
			});

			public static readonly CxvPropertyDeclaration txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UPPER.@NCSUBID.@POINT2",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LOWER.@NCSUBID.@POINT2",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INTERVAL.@NCSUBID.@POINT2",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "NCSUBID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtFraction_var1 => GetValue(txtFraction_var1_Property);

			public object txtCumFraction_var1 => GetValue(txtCumFraction_var1_Property);

			public object txtUpperlimit_var1 => GetValue(txtUpperlimit_var1_Property);

			public object txtLowerLimit_var1 => GetValue(txtLowerLimit_var1_Property);

			public object txtInterval_var1 => GetValue(txtInterval_var1_Property);
		}

		public static readonly CxvPropertyDeclaration mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
		{
			Parameter = "NCSUBID"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NPHASE",
			SelectedItemBinding = "mnbSubstream_target.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
			CompletePaths = { "@main.CC Nodes.NCSPEC2", "@main.CC Nodes.NCSPEC3", "@main.CC Nodes.NCPSD", "@main.CC Nodes.NCVATTR", "@main.CC Nodes.PSPEC3" },
			Filter = new CxvSubstreamFilter
			{
				SubstreamType = CxvSubstreamFilter.eSubstreamType.NonConventional
			}
		});

		public static readonly CxvPropertyDeclaration tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTFLOW.@NCSUBID",
			BasisPath = "@main.Input.FLOWBASE.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTAL.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdComposition_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FLOW.@NCSUBID",
				UseChildId = true,
				Name = "COMPCONV"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW.@NCSUBID",
			BasisPath = "@main.Input.BASIS.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.NCVATTR.@NCSUBID" },
			AccessibleDataPaths = { "@main.CC Nodes.CMP1.@NCSUBID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_NCSolid_Prompt1
		});

		public static readonly CxvPropertyDeclaration expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvExpanderProperty
		{
			CompleteDataPaths = { "@main.CC Nodes.NCPSD.@NCSUBID" },
			AccessibleDataPaths = { "@main.CC Nodes.PSD1.@NCSUBID" },
			DisabledPrompt = WpfFormsResources.MMMaterial_Input_NCSolid_Prompt2
		});

		public static readonly CxvPropertyDeclaration expanderAttr_state_Property = CxvPropertyDeclaration.Register("expanderAttr_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.NCVATTR"
			}
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID7"
		});

		public static readonly CxvPropertyDeclaration mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@NCSUBID.@SUBCATID6",
			SelectedItemBinding = "mnbAttribute_var2.Value",
			CreateNewPrompt = "Attribute ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
			CompletePaths = { "@main.CC Nodes.NCVATTR.@NCSUBID.@SUBCATID6" },
			EnteredPaths = { "@main.CC Nodes.ENTCOMP.@NCSUBID.@SUBCATID6" },
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBCATID6"
		});

		public static readonly CxvPropertyDeclaration mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NEL.@NCSUBID",
			SelectedItemBinding = "mnbComponent_var2.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
			CompletePaths = { "@main.CC Nodes.NCVATTR.@NCSUBID" },
			EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@NCSUBID" },
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.ELEM.@NCSUBID.@SUBCATID6.@SUBCATID7",
				UseChildId = true,
				Name = "ROWNUM3",
				ProxyRow = false
			}
		});

		public static readonly CxvPropertyDeclaration txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIMUNITS.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PSDID.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.INTERVAL.@NCSUBID",
				UseChildId = true,
				Name = "POINT2"
			}
		});

		private ICommand _cmdCreateWtFrac_Command;

		public static CxvPropertyDeclaration cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.PSD9.@NCSUBID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.CC Nodes.NCPSD1.@NCSUBID",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		public static readonly CxvPropertyDeclaration psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.PSDID.@NCSUBID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "NCSUBID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrSelMethod_var1",
					DataPath = "@main.Input.WTFRAC_OPT.@NCSUBID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "User specified values",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "USER"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "A distribution function",
					DisplayResourceKey = "",
					Value = "ogrSelMethod_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrSelMethod_var1",
							Value = "FUNCTION"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.NCPSD1.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD2.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "TypeCBox_var1",
					DataPath = "@main.Input.TYPE.@NCSUBID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "GGS",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_GGS",
					Value = "Type_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "GGS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RRSB",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_RRSB",
					Value = "Type_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "RRSB"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Normal",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Normal",
					Value = "Type_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "NORMAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Log Normal",
					DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Log_Normal",
					Value = "Type_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "TypeCBox_var1",
							Value = "LOG-NORMAL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GGS_N.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DIAM.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.RRSB_N.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D63.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.STDDEV.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD6.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.D50.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD8.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GMDEV.@NCSUBID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PSD7.@NCSUBID"
			}
		});

		public static readonly CxvPropertyDeclaration CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UOM.@NCSUBID.@SUBCATID6.@SUBCATID7"
		});

		private bool _needUpdateCombos = true;

		private bool _needUpdateSubstream = true;

		private CxvPropertyWatch varOptDependencies;

		private EventHandler _varOptDependencies_PropertyDependencyChangedHandler;

		private bool _ExpandPSD;

		private bool _ExpandCompAttr;

		public object mnbSubstream_target => GetValue(mnbSubstream_target_Property);

		public object mnbSubstream_display => GetValue(mnbSubstream_display_Property);

		public object tempVEdit_var => GetValue(tempVEdit_var_Property);

		public object presVEdit_var => GetValue(presVEdit_var_Property);

		public object lbtuTotalFlow_var1 => GetValue(lbtuTotalFlow_var1_Property);

		public object txtTotal_var1 => GetValue(txtTotal_var1_Property);

		public object grdComposition_GridData => GetValue(grdComposition_GridData_Property);

		public object lbtuComposition_var1 => GetValue(lbtuComposition_var1_Property);

		public object expandar_comattr => GetValue(expandar_comattr_Property);

		public object expandar_psd => GetValue(expandar_psd_Property);

		public object expanderAttr_state => GetValue(expanderAttr_state_Property);

		public object mnbAttribute_var2 => GetValue(mnbAttribute_var2_Property);

		public object mnbAttribute_var1 => GetValue(mnbAttribute_var1_Property);

		public object mnbComponent_var2 => GetValue(mnbComponent_var2_Property);

		public object mnbComponent_var1 => GetValue(mnbComponent_var1_Property);

		public object grdCompAttr_GridData => GetValue(grdCompAttr_GridData_Property);

		public object txtPSDUnits_var1 => GetValue(txtPSDUnits_var1_Property);

		public object txtPSDID_var1 => GetValue(txtPSDID_var1_Property);

		public object grdSubstrAttr_GridData => GetValue(grdSubstrAttr_GridData_Property);

		public ICommand cmdCreateWtFrac_Command
		{
			get
			{
				if (_cmdCreateWtFrac_Command == null)
				{
					_cmdCreateWtFrac_Command = new CxvDelegateCommand<object>(cmdCreateWtFrac_CommandExecute, this, cmdCreateWtFracCanExecuteProperty.Name + ".Value");
				}
				return _cmdCreateWtFrac_Command;
			}
		}

		public CxvLogicalPropertyData cmdCreateWtFracCanExecute => GetValue(cmdCreateWtFracCanExecuteProperty) as CxvLogicalPropertyData;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute, this, cmdEdit_CommandCanExecuteProperty.Name + ".Value");
				}
				return _cmdEdit_Command;
			}
		}

		public CxvLogicalPropertyData cmdEdit_CommandCanExecute => GetValue(cmdEdit_CommandCanExecuteProperty) as CxvLogicalPropertyData;

		public object psdCBox_var1 => GetValue(psdCBox_var1_Property);

		public object ogrSelMethod_MultiMap => GetValue(ogrSelMethod_MultiMap_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object Type_MultiMap => GetValue(Type_MultiMap_Property);

		public object GGSLbl_state => GetValue(GGSLbl_state_Property);

		public object txtGGSN_var1 => GetValue(txtGGSN_var1_Property);

		public object txtDiam_var1 => GetValue(txtDiam_var1_Property);

		public object RRSBLbl_state => GetValue(RRSBLbl_state_Property);

		public object txtRRSBN_var1 => GetValue(txtRRSBN_var1_Property);

		public object txtD63_var1 => GetValue(txtD63_var1_Property);

		public object StddevLbl_state => GetValue(StddevLbl_state_Property);

		public object txtStddev_var1 => GetValue(txtStddev_var1_Property);

		public object D50Lbl_state => GetValue(D50Lbl_state_Property);

		public object txtD50_var1 => GetValue(txtD50_var1_Property);

		public object GmdevLbl_state => GetValue(GmdevLbl_state_Property);

		public object txtGmdev_var1 => GetValue(txtGmdev_var1_Property);

		public object CompAttrUnits => GetValue(CompAttrUnits_Property);

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

		public bool ExpandPSD
		{
			get
			{
				return _ExpandPSD;
			}
			set
			{
				_ExpandPSD = value;
				OnPropertyChanged("ExpandPSD");
			}
		}

		public bool ExpandCompAttr
		{
			get
			{
				return _ExpandCompAttr;
			}
			set
			{
				_ExpandCompAttr = value;
				OnPropertyChanged("ExpandCompAttr");
			}
		}

		private void cmdCreateWtFrac_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
			if (text2 != "")
			{
				text = text2 + "." + text;
			}
			string text3 = CxsConverter.ValueToString(this.ResolveViewPropertyPath("mnbSubstream_target.Value"));
			this.SMcreatwtfrac(text, text3, "STREAM");
			base.ResolvedCxsProvider.UpdateDataCache();
			string text4 = ExpandDataPath("@main");
			text4 = text4 + ".Input.SUBSATT." + text3;
			string sTitle = text + " Inlet PSD Curve";
			DisplayPlotWizardEventArgs args = new DisplayPlotWizardEventArgs(null, "PSD", sTitle, text4, "WpfPLDISCURVES.RibbonPlotWizardMgr", null, null, true);
			DisplayPlotWizard(args);
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("psdCBox_var1.Value"));
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMMaterial.MMMaterial_Input_Stratt";
			e.LegacyFlags = 0;
			e.ShowPrompts = true;
			e.ShortName = ApwnResources.MMMaterial_Input_Stratt_Title;
			e.CompleteDataPaths = new string[1] { "@main0.CC Nodes.MN1" };
			DisplayFormEventArgs e2 = e;
			e2.Parameters.Add("main0", "Top.appModelV8.Setup.Stream-Class.Subs-Attr." + text);
			DisplayForm(e2);
		}

		private bool IsSubstreamComplete(string id)
		{
			ResolveUpdateParameter("NCSUBID", id);
			string[] array = new string[5] { "@main.CC Nodes.NCSPEC2", "@main.CC Nodes.NCSPEC3", "@main.CC Nodes.NCPSD", "@main.CC Nodes.NCVATTR", "@main.CC Nodes.PSPEC3" };
			for (int i = 0; i < array.Length; i++)
			{
				string dataPath = array[i] + "." + id;
				if (CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "value", null, varOptDependencies)) == "0")
				{
					return false;
				}
			}
			return true;
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
			CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.PSDID.@NCSUBID", "value", null, varOptDependencies));
			if (_needUpdateSubstream)
			{
				ResolveParameter("NCSUBID");
				if (CxsConverter.ValueToString(ResolveParameter("NCSUBID")) != "")
				{
					CxvDataFilter cxvDataFilter = new CxvSubstreamFilter
					{
						SubstreamType = CxvSubstreamFilter.eSubstreamType.NonConventional
					};
					cxvDataFilter.SetContainer(this);
					string dataPath = "@main.Input.NPHASE";
					string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet(dataPath, "child_ids"));
					string text = "";
					string text2 = "";
					string text3 = "";
					bool flag = false;
					if (array != null)
					{
						for (int i = 1; i < array.Length; i++)
						{
							if (cxvDataFilter.Allow(array[i]))
							{
								if (text == "")
								{
									text = array[i];
								}
								ResolveUpdateParameter("NCSUBID", array[i]);
								if (!IsSubstreamComplete(array[i]))
								{
									flag = true;
									break;
								}
								if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.PSDID.@NCSUBID", "value", null, varOptDependencies)) != "" && text2 == "")
								{
									text2 = array[i];
								}
								else if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.TEMP.@NCSUBID", "value", null, varOptDependencies)) != "")
								{
									text3 = array[i];
								}
							}
						}
						if (!flag)
						{
							if (text2 != "")
							{
								ResolveUpdateParameter("NCSUBID", text2);
							}
							else if (text3 != "")
							{
								ResolveUpdateParameter("NCSUBID", text3);
							}
							else
							{
								ResolveUpdateParameter("NCSUBID", text);
							}
						}
						_needUpdateSubstream = false;
						_needUpdateCombos = false;
					}
				}
			}
			bool? flag2 = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.NCPSD1.@NCSUBID", "value"));
			if (flag2.HasValue && flag2.Value)
			{
				_ExpandPSD = true;
			}
			bool? flag3 = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.CC Nodes.CMP1.@NCSUBID", "value"));
			if (flag3.HasValue && flag3.Value)
			{
				_ExpandCompAttr = true;
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
	public class MMMaterial_Input_NCSolid : MMTabPage, IComponentConnector
	{
		internal MMExpander spec;

		internal MMGroupBox stateVarGrp;

		internal MMLabel substrLbl;

		internal MMAdvancedComboEdit substrCBox;

		internal MMLabel tempLbl;

		internal MMVariableEdit tempVEdit;

		internal MMLabel presLbl;

		internal MMVariableEdit presVEdit;

		internal MMLabel basisLbl;

		internal MMVariableEdit basisCBox;

		internal MMLabel flrateLbl;

		internal MMVariableEdit flrateCBox;

		internal MMGroupBox compGrp;

		internal Grid compGrid;

		internal MMVariableEdit lbtuComposition;

		internal MMScrollArea compScr;

		internal MMLabel totalLbl;

		internal MMValueEdit totalTxt;

		internal MMExpander attrExp;

		internal MMLabel comIDLbl;

		internal MMAdvancedComboEdit comIDCBox;

		internal MMLabel attrIDLbl;

		internal MMAdvancedComboEdit attrIDCBox;

		internal MMScrollAreaMS comAttrScr;

		internal MMExpander PSDExp;

		internal MMLabel PSDLbl;

		internal MMComboEdit psdCBox;

		internal MMLabel unitsLbl;

		internal MMValueEdit unitsTxtbox;

		internal MMCmdButton cmdEdit;

		internal MMGroupBox MMFrame1;

		internal MMOptionGroup ogrSelMethod;

		internal MMOptionButton ogrSelMethod_opt0;

		internal MMOptionButton ogrSelMethod_opt1;

		internal MMGroupBox MMFrame2;

		internal MMLabel TypeLbl;

		internal MMComboEdit TypeCBox;

		internal MMLabel GGSNLbl;

		internal MMValueEdit GGSNTxtbox;

		internal MMLabel DiamLbl;

		internal MMVariableEdit DiamTxtbox;

		internal MMLabel RRSBNLbl;

		internal MMValueEdit RRSBNTxtbox;

		internal MMLabel D63Lbl;

		internal MMVariableEdit D63Txtbox;

		internal MMLabel StddevLbl;

		internal MMVariableEdit StddevTxtbox;

		internal MMLabel D50Lbl;

		internal MMVariableEdit D50Txtbox;

		internal MMLabel GmdevLbl;

		internal MMValueEdit GmdevTxtbox;

		internal MMCmdButton cmdCreateWtFrac;

		internal MMScrollArea PSDScr;

		private bool _contentLoaded;

		public MMMaterial_Input_NCSolid()
		{
			base.ViewModelType = typeof(MMMaterial_Input_NCSolid_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_ncsolid.xaml", UriKind.Relative);
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
				spec = (MMExpander)target;
				break;
			case 2:
				stateVarGrp = (MMGroupBox)target;
				break;
			case 3:
				substrLbl = (MMLabel)target;
				break;
			case 4:
				substrCBox = (MMAdvancedComboEdit)target;
				break;
			case 5:
				tempLbl = (MMLabel)target;
				break;
			case 6:
				tempVEdit = (MMVariableEdit)target;
				break;
			case 7:
				presLbl = (MMLabel)target;
				break;
			case 8:
				presVEdit = (MMVariableEdit)target;
				break;
			case 9:
				basisLbl = (MMLabel)target;
				break;
			case 10:
				basisCBox = (MMVariableEdit)target;
				break;
			case 11:
				flrateLbl = (MMLabel)target;
				break;
			case 12:
				flrateCBox = (MMVariableEdit)target;
				break;
			case 13:
				compGrp = (MMGroupBox)target;
				break;
			case 14:
				compGrid = (Grid)target;
				break;
			case 15:
				lbtuComposition = (MMVariableEdit)target;
				break;
			case 16:
				compScr = (MMScrollArea)target;
				break;
			case 17:
				totalLbl = (MMLabel)target;
				break;
			case 18:
				totalTxt = (MMValueEdit)target;
				break;
			case 19:
				attrExp = (MMExpander)target;
				break;
			case 20:
				comIDLbl = (MMLabel)target;
				break;
			case 21:
				comIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 22:
				attrIDLbl = (MMLabel)target;
				break;
			case 23:
				attrIDCBox = (MMAdvancedComboEdit)target;
				break;
			case 24:
				comAttrScr = (MMScrollAreaMS)target;
				break;
			case 25:
				PSDExp = (MMExpander)target;
				break;
			case 26:
				PSDLbl = (MMLabel)target;
				break;
			case 27:
				psdCBox = (MMComboEdit)target;
				break;
			case 28:
				unitsLbl = (MMLabel)target;
				break;
			case 29:
				unitsTxtbox = (MMValueEdit)target;
				break;
			case 30:
				cmdEdit = (MMCmdButton)target;
				break;
			case 31:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 32:
				ogrSelMethod = (MMOptionGroup)target;
				break;
			case 33:
				ogrSelMethod_opt0 = (MMOptionButton)target;
				break;
			case 34:
				ogrSelMethod_opt1 = (MMOptionButton)target;
				break;
			case 35:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 36:
				TypeLbl = (MMLabel)target;
				break;
			case 37:
				TypeCBox = (MMComboEdit)target;
				break;
			case 38:
				GGSNLbl = (MMLabel)target;
				break;
			case 39:
				GGSNTxtbox = (MMValueEdit)target;
				break;
			case 40:
				DiamLbl = (MMLabel)target;
				break;
			case 41:
				DiamTxtbox = (MMVariableEdit)target;
				break;
			case 42:
				RRSBNLbl = (MMLabel)target;
				break;
			case 43:
				RRSBNTxtbox = (MMValueEdit)target;
				break;
			case 44:
				D63Lbl = (MMLabel)target;
				break;
			case 45:
				D63Txtbox = (MMVariableEdit)target;
				break;
			case 46:
				StddevLbl = (MMLabel)target;
				break;
			case 47:
				StddevTxtbox = (MMVariableEdit)target;
				break;
			case 48:
				D50Lbl = (MMLabel)target;
				break;
			case 49:
				D50Txtbox = (MMVariableEdit)target;
				break;
			case 50:
				GmdevLbl = (MMLabel)target;
				break;
			case 51:
				GmdevTxtbox = (MMValueEdit)target;
				break;
			case 52:
				cmdCreateWtFrac = (MMCmdButton)target;
				break;
			case 53:
				PSDScr = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdComposition_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FLOW.@SUBSTRID.@COMP",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "SUBSTRID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public static readonly CxvPropertyDeclaration txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FLOW.@SUBSTRID.@COMP",
				IsEnabledCondition = new CxvLogicalTest
				{
					Parameter = "SUBSTRID",
					Operator = CxvLogicalOperator.IdExists
				}
			});

			public object txtValue_var1 => GetValue(txtValue_var1_Property);

			public object txtXomponent_var1 => GetValue(txtXomponent_var1_Property);
		}

		private ICommand _cmdRefTemp_Command;

		public static readonly CxvPropertyDeclaration cmdRefTemp_var1_Property = CxvPropertyDeclaration.Register("cmdRefTemp_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.REFT1.@SUBSTRID"
			}
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_spec3_Property = CxvPropertyDeclaration.Register("mnbSubstream_spec3", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC3"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NPHASE",
			SelectedItemBinding = "mnbSubstream_target.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
			CompletePaths = { "SPEC1", "SPEC2", "@main.CC Nodes.SPEC3" }
		});

		public static readonly CxvPropertyDeclaration spcSpec1_Property = CxvPropertyDeclaration.Register("spcSpec1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvSpecProperty
		{
			Options = 
			{
				new CxvSpecOption
				{
					Display = "Temperature",
					DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Temperature",
					DataPath = "@main.Input.TEMP.@SUBSTRID"
				},
				new CxvSpecOption
				{
					Display = "Pressure",
					DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Pressure",
					DataPath = "@main.Input.PRES.@SUBSTRID"
				},
				new CxvSpecOption
				{
					Display = "Vapor fraction",
					DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Vapor_fraction",
					DataPath = "@main.Input.VFRAC.@SUBSTRID"
				}
			},
			Count = 2,
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration spcSpec1_var1_Property = CxvPropertyDeclaration.Register("spcSpec1_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration spcSpec1_var2_Property = CxvPropertyDeclaration.Register("spcSpec1_var2", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration spcSpec1_var3_Property = CxvPropertyDeclaration.Register("spcSpec1_var3", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRAC.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTFLOW.@SUBSTRID",
			BasisPath = "@main.Input.FLOWBASE.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration cboSolvent_var1_Property = CxvPropertyDeclaration.Register("cboSolvent_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.SOLVENT.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOTAL.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdComposition_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FLOW.@SUBSTRID",
				UseChildId = true,
				Name = "COMP"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW.@SUBSTRID",
			BasisPath = "@main.Input.BASIS.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBSTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public ICommand cmdRefTemp_Command
		{
			get
			{
				if (_cmdRefTemp_Command == null)
				{
					_cmdRefTemp_Command = new CxvDelegateCommand<object>(cmdRefTemp_CommandExecute);
				}
				return _cmdRefTemp_Command;
			}
		}

		public object cmdRefTemp_var1 => GetValue(cmdRefTemp_var1_Property);

		public object mnbSubstream_target => GetValue(mnbSubstream_target_Property);

		public object mnbSubstream_spec3 => GetValue(mnbSubstream_spec3_Property);

		public object mnbSubstream_display => GetValue(mnbSubstream_display_Property);

		public object spcSpec1 => GetValue(spcSpec1_Property);

		public object spcSpec1_var1 => GetValue(spcSpec1_var1_Property);

		public object spcSpec1_var2 => GetValue(spcSpec1_var2_Property);

		public object spcSpec1_var3 => GetValue(spcSpec1_var3_Property);

		public object lbtuTotalFlow_var1 => GetValue(lbtuTotalFlow_var1_Property);

		public object cboSolvent_var1 => GetValue(cboSolvent_var1_Property);

		public object txtTotal_var1 => GetValue(txtTotal_var1_Property);

		public object grdComposition_GridData => GetValue(grdComposition_GridData_Property);

		public object lbtuComposition_var1 => GetValue(lbtuComposition_var1_Property);

		private void cmdRefTemp_CommandExecute(object parameter)
		{
			DisplayFormEventArgs e = new DisplayFormEventArgs
			{
				FormProgId = "MMMaterial.MMMaterial_Reftemp",
				LegacyFlags = 0,
				HelpId = 0,
				ShowPrompts = true,
				ShortName = WpfFormsResources.MMMaterial_Input_Specif_Display1
			};
			e.Parameters.Add("SUBSTRID", ResolveParameter("SUBSTRID", null));
			DisplayForm(e);
		}
	}
	[ProgId("MMMaterial.MMMaterial_Input_Specif")]
	public class MMMaterial_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbSubstream_label;

		internal MMAdvancedComboEdit mnbSubstream;

		internal MMCmdButton cmdRefTemp;

		internal MMGroupBox fraVariables;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMComboEdit spcSpec2_combo;

		internal MMVariableEdit spcSpec2;

		internal MMLabel lbtuTotalFlow_label;

		internal MMBasisEdit lbtuTotalFlow_Basis;

		internal MMVariableEdit lbtuTotalFlow;

		internal MMLabel cboSolvent_label;

		internal MMComboEdit cboSolvent;

		internal MMGroupBox fraComposition;

		internal MMVariableEdit lbtuComposition;

		internal MMScrollArea grdComposition;

		internal MMLabel lblTotal;

		internal MMValueEdit txtTotal;

		private bool _contentLoaded;

		public MMMaterial_Input_Specif()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_specif.xaml", UriKind.Relative);
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
				mnbSubstream_label = (MMLabel)target;
				break;
			case 2:
				mnbSubstream = (MMAdvancedComboEdit)target;
				break;
			case 3:
				cmdRefTemp = (MMCmdButton)target;
				break;
			case 4:
				fraVariables = (MMGroupBox)target;
				break;
			case 5:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 6:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 7:
				spcSpec2_combo = (MMComboEdit)target;
				break;
			case 8:
				spcSpec2 = (MMVariableEdit)target;
				break;
			case 9:
				lbtuTotalFlow_label = (MMLabel)target;
				break;
			case 10:
				lbtuTotalFlow_Basis = (MMBasisEdit)target;
				break;
			case 11:
				lbtuTotalFlow = (MMVariableEdit)target;
				break;
			case 12:
				cboSolvent_label = (MMLabel)target;
				break;
			case 13:
				cboSolvent = (MMComboEdit)target;
				break;
			case 14:
				fraComposition = (MMGroupBox)target;
				break;
			case 15:
				lbtuComposition = (MMVariableEdit)target;
				break;
			case 16:
				grdComposition = (MMScrollArea)target;
				break;
			case 17:
				lblTotal = (MMLabel)target;
				break;
			case 18:
				txtTotal = (MMValueEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Stratt_ViewModel : MMTabPageViewModel
	{
		public class grdAttribute_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main0.Input.INTERVAL.@y"
			});

			public static readonly CxvPropertyDeclaration MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main0.Input.PARTICLESIZ2.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main0.CC Nodes.USER"
				}
			});

			public static readonly CxvPropertyDeclaration lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main0.Input.PARTICLESIZE.@y",
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main0.CC Nodes.USER"
				}
			});

			public object txtInt_var1 => GetValue(txtInt_var1_Property);

			public object MMLBUText1_upper => GetValue(MMLBUText1_upper_Property);

			public object lbtuLower_Lower => GetValue(lbtuLower_Lower_Property);
		}

		public static readonly CxvPropertyDeclaration NUMROW_Property = CxvPropertyDeclaration.Register("NUMROW", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVALS",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.EXINT"
			}
		});

		public static readonly CxvPropertyDeclaration txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVAL.@y"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZ2.@y",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZE.@y",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
			}
		});

		private string _psdname;

		public static readonly CxvPropertyDeclaration txtIntervals_var1_Property = CxvPropertyDeclaration.Register("txtIntervals_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.INTERVALS"
		});

		public static readonly CxvPropertyDeclaration lbtuSizeUnits_var1_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.PARTICLESIZE",
			ExtraDataPaths = { "@main0.Input.PARTICLESIZ2", "@main0.Input.LOWER", "@main0.Input.UPPER" },
			VariablePrompt = "Size units",
			VariablePromptResourceKey = "MMSetup_Stratt_Subatt_ViewModel__unit_prompt"
		});

		public static readonly CxvPropertyDeclaration lbtuSizeUnits_var2_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var2", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.PARTICLESIZE"
		});

		public static CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main0.Input.TYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Equidistant",
					DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Equidistant",
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

		public static readonly CxvPropertyDeclaration geoDiscretization_var1_Property = CxvPropertyDeclaration.Register("geoDiscretization_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.Q",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.ISGEO"
			}
		});

		public static readonly CxvPropertyDeclaration spnIntervals_var1_Property = CxvPropertyDeclaration.Register("spnIntervals_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.INTERVALS",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.EXINT1"
			}
		});

		public static readonly CxvPropertyDeclaration txtUpper_var_Property = CxvPropertyDeclaration.Register("txtUpper_var", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.UPPER",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.LIMIT"
			}
		});

		public static readonly CxvPropertyDeclaration txtLower_var_Property = CxvPropertyDeclaration.Register("txtLower_var", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main0.Input.LOWER",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.LIMIT"
			}
		});

		private ICommand _cmdCreateMesh_Command;

		public static readonly CxvPropertyDeclaration cmdCreateMesh_var1_Property = CxvPropertyDeclaration.Register("cmdCreateMesh_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.CMESH"
			}
		});

		public static readonly CxvPropertyDeclaration PSDnext_Enable_Property = CxvPropertyDeclaration.Register("PSDnext_Enable", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Equal,
			DataPath = "@main0.CC Nodes.MN1",
			Value = 0
		});

		private ICommand _cmdUpdatePSD_Command;

		public static readonly CxvPropertyDeclaration cmdUpdatePSD_var1_Property = CxvPropertyDeclaration.Register("cmdUpdatePSD_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main0.CC Nodes.MN1"
			}
		});

		private ICommand _cmdCancel_Command;

		public static readonly CxvPropertyDeclaration grdAttribute_GridData_Property = CxvPropertyDeclaration.Register("grdAttribute_GridData", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAttribute_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main0.Input.INTERVAL",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			},
			AllowCollectionChange = false
		});

		private string _unitChangeornot;

		private string _type;

		private int? _intervals;

		private int? _lower;

		private int? _upper;

		private double[] _lowers;

		private double[] _uppers;

		public object NUMROW => GetValue(NUMROW_Property);

		public object txtInt_var1 => GetValue(txtInt_var1_Property);

		public object MMLBUText1_upper => GetValue(MMLBUText1_upper_Property);

		public object lbtuLower_Lower => GetValue(lbtuLower_Lower_Property);

		public string psdname
		{
			get
			{
				_psdname = CxsConverter.ValueToString(ExpandDataPathAndGet("@main0", "display_name"));
				return _psdname;
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

		public object PSDnext_Enable => GetValue(PSDnext_Enable_Property);

		public ICommand cmdUpdatePSD_Command
		{
			get
			{
				if (_cmdUpdatePSD_Command == null)
				{
					_cmdUpdatePSD_Command = new CxvDelegateCommand<object>(cmdUpdatePSD_CommandExecute);
				}
				return _cmdUpdatePSD_Command;
			}
		}

		public object cmdUpdatePSD_var1 => GetValue(cmdUpdatePSD_var1_Property);

		public ICommand cmdCancel_Command
		{
			get
			{
				if (_cmdCancel_Command == null)
				{
					_cmdCancel_Command = new CxvDelegateCommand<object>(cmdCancel_CommandExecute);
				}
				return _cmdCancel_Command;
			}
		}

		public object grdAttribute_GridData => GetValue(grdAttribute_GridData_Property);

		private void cmdCreateMesh_CommandExecute(object parameter)
		{
			base.ResolvedCxsProvider.BatchSet(ExpandDataPath("@main0") + ".Input.GMESH", "value", null, "YES");
			base.ResolvedCxsProvider.UpdateDataCache();
			base.ResolvedCxsProvider.BatchSet(ExpandDataPath("@main0") + ".Input.GMESH", "value", null, "NO");
		}

		private void cmdUpdatePSD_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
			if (text2 != "")
			{
				text = text2 + "." + text;
			}
			CloseForm();
			UpdateAll();
		}

		private void cmdCancel_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
			if (text2 != "")
			{
				text = text2 + "." + text;
			}
			this.SMupdatepsd(text, _psdname, "STREAM", 2);
			ExpandDataPathAndSet("@main0.Input.TYPE", "value", _type);
			ExpandDataPathAndSet("@main0.Input.PARTICLESIZE", "uom", _unitChangeornot);
			ExpandDataPathAndSet("@main0.Input.PARTICLESIZ2", "uom", _unitChangeornot);
			ExpandDataPathAndSet("@main0.Input.LOWER", "uom", _unitChangeornot);
			ExpandDataPathAndSet("@main0.Input.UPPER", "uom", _unitChangeornot);
			ExpandDataPathAndSet("@main0.Input.LOWER", "value", _lower);
			ExpandDataPathAndSet("@main0.Input.UPPER", "value", _upper);
			ExpandDataPathAndSet("@main0.Input.INTERVALS", "value", _intervals);
			if (_intervals.HasValue)
			{
				int value = _intervals.Value;
				string text3 = ExpandDataPath("@main0.Input.PARTICLESIZE.#");
				string text4 = ExpandDataPath("@main0.Input.PARTICLESIZ2.#");
				CxsBatchRequestData cxsBatchRequestData = new CxsBatchRequestData();
				CxsBatchRequestData cxsBatchRequestData2 = new CxsBatchRequestData();
				for (int i = 0; i < value; i++)
				{
					cxsBatchRequestData.AddRequest(new CxsBatchRequest(text3 + i, "value", null, _lowers[i]));
					cxsBatchRequestData2.AddRequest(new CxsBatchRequest(text4 + i, "value", null, _uppers[i]));
				}
				base.ResolvedCxsProvider.BatchSetNoRefresh(cxsBatchRequestData);
				base.ResolvedCxsProvider.BatchSetNoRefresh(cxsBatchRequestData2);
			}
			CloseForm();
			UpdateAll();
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "display_name"));
				string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "container"));
				if (text2 != "")
				{
					text = text2 + "." + text;
				}
				string psdid = CxsConverter.ValueToString(ExpandDataPathAndGet("@main0", "display_name"));
				this.SMupdatepsd(text, psdid, "STREAM", 0);
				_unitChangeornot = CxsConverter.ValueToString(ExpandDataPathAndGet("@main0.Input.PARTICLESIZE", "uom"));
				_intervals = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main0.Input.INTERVALS", "value"));
				_type = CxsConverter.ValueToString(ExpandDataPathAndGet("@main0.Input.TYPE", "value"));
				_lower = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main0.Input.LOWER", "value"));
				_upper = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main0.Input.UPPER", "value"));
				try
				{
					if (_intervals.HasValue)
					{
						int value = _intervals.Value;
						_lowers = new double[value];
						_uppers = new double[value];
						for (int i = 0; i < value; i++)
						{
							_lowers[i] = CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main0.Input.PARTICLESIZE.#" + i, "value")).Value;
							_uppers[i] = CxsConverter.ValueToDouble(ExpandDataPathAndGet("@main0.Input.PARTICLESIZ2.#" + i, "value")).Value;
						}
					}
				}
				catch
				{
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMMaterial.MMMaterial_Input_Stratt")]
	public class MMMaterial_Input_Stratt : MMTabPage, IComponentConnector
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

		internal MMCmdButton cmdUpdate;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMaterial_Input_Stratt()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Stratt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_stratt.xaml", UriKind.Relative);
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
			case 17:
				cmdUpdate = (MMCmdButton)target;
				break;
			case 18:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Input_Substr_ViewModel : MMTabPageViewModel
	{
		public class grdSubstrAttr_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.SUBSATT.@SUBATTRID.@POINT"
			});

			public static readonly CxvPropertyDeclaration txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UPPER.@SUBATTRID.@POINT"
			});

			public static readonly CxvPropertyDeclaration txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LOWER.@SUBATTRID.@POINT"
			});

			public static readonly CxvPropertyDeclaration txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INTERVAL.@SUBATTRID.@POINT"
			});

			public object txtFraction_var1 => GetValue(txtFraction_var1_Property);

			public object txtUpperlimit_var1 => GetValue(txtUpperlimit_var1_Property);

			public object txtLowerLimit_var1 => GetValue(txtLowerLimit_var1_Property);

			public object txtInterval_var1 => GetValue(txtInterval_var1_Property);
		}

		public static readonly CxvPropertyDeclaration mnbSubstream_var2_Property = CxvPropertyDeclaration.Register("mnbSubstream_var2", typeof(MMMaterial_Input_Substr_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBATTRID"
		});

		public static readonly CxvPropertyDeclaration mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_Substr_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.INTERVAL",
			SelectedItemBinding = "mnbSubstream_var2.Value",
			CreateNewPrompt = "Substream name:",
			CreateNewPromptResourceKey = "MMMaterial_Input_Substr_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
			CompletePaths = { "PSD" }
		});

		public static readonly CxvPropertyDeclaration fraSubstrAttr_state_Property = CxvPropertyDeclaration.Register("fraSubstrAttr_state", typeof(MMMaterial_Input_Substr_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "SUBATTRID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtUnits_var1_Property = CxvPropertyDeclaration.Register("txtUnits_var1", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIMUNITS.@SUBATTRID"
		});

		public static readonly CxvPropertyDeclaration txtAttrID_var1_Property = CxvPropertyDeclaration.Register("txtAttrID_var1", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PSDID.@SUBATTRID"
		});

		public static readonly CxvPropertyDeclaration grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.INTERVAL.@SUBATTRID",
				UseChildId = true,
				Name = "POINT"
			}
		});

		public object mnbSubstream_var2 => GetValue(mnbSubstream_var2_Property);

		public object mnbSubstream_display => GetValue(mnbSubstream_display_Property);

		public object fraSubstrAttr_state => GetValue(fraSubstrAttr_state_Property);

		public object txtUnits_var1 => GetValue(txtUnits_var1_Property);

		public object txtAttrID_var1 => GetValue(txtAttrID_var1_Property);

		public object grdSubstrAttr_GridData => GetValue(grdSubstrAttr_GridData_Property);
	}
	[ProgId("MMMaterial.MMMaterial_Input_Substr")]
	public class MMMaterial_Input_Substr : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbSubstream_label;

		internal MMAdvancedComboEdit mnbSubstream;

		internal MMGroupBox fraSubstrAttr;

		internal MMLabel MMLabel1;

		internal MMValueEdit txtAttrID;

		internal MMLabel MMLabel2;

		internal MMValueEdit txtUnits;

		internal MMScrollArea grdSubstrAttr;

		private bool _contentLoaded;

		public MMMaterial_Input_Substr()
		{
			base.ViewModelType = typeof(MMMaterial_Input_Substr_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_input_substr.xaml", UriKind.Relative);
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
				mnbSubstream_label = (MMLabel)target;
				break;
			case 2:
				mnbSubstream = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraSubstrAttr = (MMGroupBox)target;
				break;
			case 4:
				MMLabel1 = (MMLabel)target;
				break;
			case 5:
				txtAttrID = (MMValueEdit)target;
				break;
			case 6:
				MMLabel2 = (MMLabel)target;
				break;
			case 7:
				txtUnits = (MMValueEdit)target;
				break;
			case 8:
				grdSubstrAttr = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMaterial_Reftemp_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMaterial_Reftemp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VOL_TREF.@SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_Reftemp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.CONC_TREF.@SUBSTRID",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.REFT2.@SUBSTRID"
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

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}
	}
	[ProgId("MMMaterial.MMMaterial_Reftemp")]
	public class MMMaterial_Reftemp : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMaterial_Reftemp()
		{
			base.ViewModelType = typeof(MMMaterial_Reftemp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_reftemp.xaml", UriKind.Relative);
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
				MMLBUText1_label = (MMLabel)target;
				break;
			case 3:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 4:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 5:
				MMLBUText2 = (MMVariableEdit)target;
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
	public class MMMaterial_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.AROMCRV"
		});

		public static readonly CxvPropertyDeclaration petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.BAS-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.CARBCRV"
		});

		public static readonly CxvPropertyDeclaration petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FLASHCRV"
		});

		public static readonly CxvPropertyDeclaration petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.FREEZCRV"
		});

		public static readonly CxvPropertyDeclaration petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.HYDROCRV"
		});

		public static readonly CxvPropertyDeclaration petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.IRONCRV"
		});

		public static readonly CxvPropertyDeclaration petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KNOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.KVISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.LUM-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MERCCRV"
		});

		public static readonly CxvPropertyDeclaration petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.METALCRV"
		});

		public static readonly CxvPropertyDeclaration petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MOCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NAPHCRV"
		});

		public static readonly CxvPropertyDeclaration petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.NICKCRV"
		});

		public static readonly CxvPropertyDeclaration petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OLEFCRV"
		});

		public static readonly CxvPropertyDeclaration petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.OXYGCRV"
		});

		public static readonly CxvPropertyDeclaration petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.PARACRV"
		});

		public static readonly CxvPropertyDeclaration petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POURCRV"
		});

		public static readonly CxvPropertyDeclaration petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.REFICRV"
		});

		public static readonly CxvPropertyDeclaration petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ROCNCRV"
		});

		public static readonly CxvPropertyDeclaration petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.RVPCRV"
		});

		public static readonly CxvPropertyDeclaration petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SMOKCRV"
		});

		public static readonly CxvPropertyDeclaration petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.SULFCRV"
		});

		public static readonly CxvPropertyDeclaration petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TOT-NCRV"
		});

		public static readonly CxvPropertyDeclaration petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VANACRV"
		});

		public static readonly CxvPropertyDeclaration petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VISCCRV"
		});

		public static readonly CxvPropertyDeclaration petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VLOCKCRV"
		});

		public static readonly CxvPropertyDeclaration petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.WARMICRV"
		});

		public static readonly CxvPropertyDeclaration volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRV"
		});

		public static readonly CxvPropertyDeclaration volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRV"
		});

		public static readonly CxvPropertyDeclaration volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CRV"
		});

		public static readonly CxvPropertyDeclaration volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCRV"
		});

		public static readonly CxvPropertyDeclaration volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRV"
		});

		public static readonly CxvPropertyDeclaration volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRV"
		});

		public static readonly CxvPropertyDeclaration volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRV"
		});

		public static readonly CxvPropertyDeclaration volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRK"
		});

		public static readonly CxvPropertyDeclaration weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86CRVWT"
		});

		public static readonly CxvPropertyDeclaration weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D1160CWT"
		});

		public static readonly CxvPropertyDeclaration weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.VACCURWT"
		});

		public static readonly CxvPropertyDeclaration weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.APICRVWT"
		});

		public static readonly CxvPropertyDeclaration weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.GRVCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MWCRVWT"
		});

		public static readonly CxvPropertyDeclaration weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D86WTCRK"
		});

		public static readonly CxvPropertyDeclaration weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.D2887CRV"
		});

		public static readonly CxvPropertyDeclaration poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.POLCSDY"
		});

		public static readonly CxvPropertyDeclaration weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.TBPCRVWT"
		});

		public static readonly CxvPropertyDeclaration petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.ANILCRV"
		});

		public static readonly CxvPropertyDeclaration petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.UOPKCRV"
		});

		public static readonly CxvPropertyDeclaration str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_petrocurveview"
		});

		public static readonly CxvPropertyDeclaration str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_weightcurveview"
		});

		public static readonly CxvPropertyDeclaration str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_volumecurveview"
		});

		public static readonly CxvPropertyDeclaration str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "str_polycurveview"
		});

		public static readonly CxvPropertyDeclaration main_result_Property = CxvPropertyDeclaration.Register("main_result", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "main_result"
		});

		public static readonly CxvPropertyDeclaration solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@OutputNode.MAXIMUM"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@mat1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = 
			{
				"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
				"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
				"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
				"@petro31"
			}
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@poly" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@solid" }
		});

		public static readonly CxvPropertyDeclaration APUnitsNode_Property = CxvPropertyDeclaration.Register("APUnitsNode", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Units"
		});

		public static readonly CxvPropertyDeclaration OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main_result.Results Summary.Stream-Sum.Dist-Curve.Output"
		});

		private bool _isMaterialFormAccessible;

		private bool? _canEnableUIThreadInEngSim;

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

		public object str_weightcurveview => GetValue(str_weightcurveview_Property);

		public object str_volumecurveview => GetValue(str_volumecurveview_Property);

		public object str_polycurveview => GetValue(str_polycurveview_Property);

		public object main_result => GetValue(main_result_Property);

		public object solid => GetValue(solid_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object APUnitsNode => GetValue(APUnitsNode_Property);

		public object OutputNode => GetValue(OutputNode_Property);

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

		public bool HasMaterialResultsToDisplay => CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.Stream Results.Table", "value")) ?? false;

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

		public MMMaterial_Result_ViewModel()
		{
			SimulatorStatusHelperForControls.Default.IsRunningChanged += Simulator_IsRunningChanged;
		}

		private void Simulator_IsRunningChanged(object sender, EventArgs e)
		{
			RefreshMaterialFormStatus();
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
						ResolveUpdateParameter("main_result", "@main.@parent");
					}
					else if (text == "Top.appModelV8.Results Summary")
					{
						ResolveUpdateParameter("main_result", "Top.appModelV8");
					}
					else if (text.Contains(".Blocks.") || text.Contains(".Streams."))
					{
						ResolveUpdateParameter("main_result", "@main.@parent.@parent");
					}
					else
					{
						ResolveUpdateParameter("main_result", "Top.appModelV8");
					}
				}
				else
				{
					ResolveUpdateParameter("main_result", "Top.appModelV8");
				}
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnViewClosed()
		{
			SimulatorStatusHelperForControls.Default.IsRunningChanged -= Simulator_IsRunningChanged;
			base.OnViewClosed();
		}

		protected override void OnViewUpdateDisplayEvent()
		{
			OnPropertyChanged("IsBatchFormAccessible");
			base.OnViewUpdateDisplayEvent();
		}

		protected void RefreshMaterialFormStatus()
		{
			RefreshMaterialFormStatus("@main.Stream Results.Table");
		}

		protected void RefreshMaterialFormStatus(string checkedTablePath)
		{
			if (base.ResolvedCxsProvider.Case != null && base.ResolvedCxsProvider.Case.Solver != null && base.ResolvedCxsProvider.Case.Solver.RunState == CxsSolverRunState.Running && CanEnableUIThreadInEngSim == true)
			{
				IsMaterialFormAccessible = true;
			}
			else
			{
				IsMaterialFormAccessible = HasMaterialResultsToDisplay;
			}
		}
	}
	[ProgId("MMMaterial.MMMaterial_Result")]
	public class MMMaterial_Result : MMTabTemplate, IStreamResultsTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tabBatch;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public bool HasMaterialResultsToDisplay
		{
			get
			{
				if (base.ViewModel is MMMaterial_Result_ViewModel mMMaterial_Result_ViewModel)
				{
					return mMMaterial_Result_ViewModel.HasMaterialResultsToDisplay;
				}
				return false;
			}
		}

		public MMMaterial_Result()
		{
			base.ViewModelType = typeof(MMMaterial_Result_ViewModel);
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
					ContentType = typeof(MMMaterial_Result_Materi)
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_result.xaml", UriKind.Relative);
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
			case 8:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
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
			}
		}

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
	}
	public class MMMaterial_Result_Materi_ViewModel : StreamSummaryViewModel
	{
		public class grdStreams_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Stream Results.Table.@row"
			});

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

			public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);

			public object inner => GetValue(inner_Property);
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

		public class grdStreams_HeaderTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(grdStreams_HeaderTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@x"
			});

			public object var1 => GetValue(var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == var1_Property && subPropertyName == "Value" && var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Streams.");
					if (num != -1)
					{
						string descriptionPath = text.Substring(0, num) + "Streams.[Value]";
						CxvCustomTooltipProperty obj = (var1 as CxvCustomTooltipData).Property as CxvCustomTooltipProperty;
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

		public static CxvPropertyDeclaration cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMMaterial_Result_Materi_ViewModel), new CxvLogicalProperty
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

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMMaterial_Result_Materi_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
					DisplayResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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

		public static readonly CxvPropertyDeclaration cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Stream Results.TFF File",
			Sorted = true
		});

		private bool _hasSetToDefault;

		public static readonly CxvPropertyDeclaration grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreams_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table",
				UseChildId = false,
				Name = "row"
			}
		});

		public static readonly CxvPropertyDeclaration grdStreams_GridHeader_Property = CxvPropertyDeclaration.Register("grdStreams_GridHeader", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdStreams_HeaderTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = false,
				Name = "x"
			}
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

		public object grdStreams_GridHeader => GetValue(grdStreams_GridHeader_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd.Name == "cboDisplay_MultiMap" && subPropertyName == "Value" && !base.IsInitialUpdate && cboDisplay_MultiMap is CxvMultiMapPropertyData cxvMultiMapPropertyData && cxvMultiMapPropertyData.Value as string == "cboDisplay_MultiMapOption_2")
			{
				ExpandDataPathAndSet("@main.Stream Results.Display", "value", "DEFAULT");
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate && !_hasSetToDefault)
			{
				_hasSetToDefault = true;
				ExpandDataPathAndSet("@main.Stream Results.Display", "value", "DEFAULT");
			}
			RefreshMaterialFormStatus();
			base.OnUpdateData();
		}

		public override void OnSimulationRunStarted()
		{
			RefreshMaterialFormStatus();
			base.OnSimulationRunStarted();
		}

		protected void RefreshMaterialFormStatus()
		{
			bool isMaterialFormAccessible = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.Stream Results.Table", "value")) ?? false;
			if (base.IsSimulating)
			{
				string dataPath = "@main.@parent.@parent.EO Configuration.Solve-Options.Input.PROCESS";
				if (CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "value", null)) == "BATCH" && base.CanEnableUIThreadInEngSim == true)
				{
					base.IsMaterialFormAccessible = true;
				}
				else
				{
					base.IsMaterialFormAccessible = isMaterialFormAccessible;
				}
			}
			else
			{
				base.IsMaterialFormAccessible = isMaterialFormAccessible;
			}
		}

		private void cbtStreamTable_CommandExecute(object parameter)
		{
			string path = CxsConverter.ValueToString(ExpandDataPath("@main.Stream Results"));
			Birdcage(hiearchical: true, path);
		}
	}
	[ProgId("MMMaterial.MMMaterial_Result_Materi")]
	public class MMMaterial_Result_Materi : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMLabel cboFormat_label;

		internal MMComboEdit cboFormat;

		internal MMCmdButton cbtStreamTable;

		internal MMScrollAreaMS grdStreams;

		private bool _contentLoaded;

		public override bool CanPrint => true;

		public MMMaterial_Result_Materi()
		{
			base.ViewModelType = typeof(MMMaterial_Result_Materi_ViewModel);
			InitializeComponent();
		}

		public override IEnumerable<FrameworkElement> GeneratePrintPages(Size availablePrintSize)
		{
			string arg = string.Empty;
			if (base.ViewModel != null)
			{
				arg = base.ViewModel.ExpandDataPathAndGet("@main", "id") as string;
			}
			string title = $"Stream {arg} (Material) - Results";
			return this.GenerateGenericPrintPages(grdStreams, availablePrintSize, 0, 1, title, ignoreLastColumn: true);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/material/mmmaterial_result_materi.xaml", UriKind.Relative);
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
}
namespace AspenTech.AspenPlus.MMForms.Streams.Heat
{
	public class MMHeat_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration NPOINT_Property = CxvPropertyDeclaration.Register("NPOINT", typeof(MMHeat_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "NPOINT"
		});

		public static readonly CxvPropertyDeclaration SPECCOMP_Property = CxvPropertyDeclaration.Register("SPECCOMP", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MN1"
		});

		public static readonly CxvPropertyDeclaration LOADL_Property = CxvPropertyDeclaration.Register("LOADL", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.LOADL"
		});

		public static readonly CxvPropertyDeclaration ENTNPOINT_Property = CxvPropertyDeclaration.Register("ENTNPOINT", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTNPOINT"
		});

		public static readonly CxvPropertyDeclaration ENTVEC_Property = CxvPropertyDeclaration.Register("ENTVEC", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTVEC"
		});

		public static readonly CxvPropertyDeclaration LOAD_Property = CxvPropertyDeclaration.Register("LOAD", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.LOAD"
		});

		public static readonly CxvPropertyDeclaration ENTOPT_Property = CxvPropertyDeclaration.Register("ENTOPT", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SPECCOMP" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@LOAD" },
			AccessibleDataPaths = { "@LOADL" },
			EnteredDataPaths = { "@ENTNPOINT", "@ENTVEC" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTOPT" }
		});

		public object NPOINT => GetValue(NPOINT_Property);

		public object SPECCOMP => GetValue(SPECCOMP_Property);

		public object LOADL => GetValue(LOADL_Property);

		public object ENTNPOINT => GetValue(ENTNPOINT_Property);

		public object ENTVEC => GetValue(ENTVEC_Property);

		public object LOAD => GetValue(LOAD_Property);

		public object ENTOPT => GetValue(ENTOPT_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMHeat.MMHeat_Input")]
	public class MMHeat_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab8;

		private bool _contentLoaded;

		public MMHeat_Input()
		{
			base.ViewModelType = typeof(MMHeat_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_input.xaml", UriKind.Relative);
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
				tab8 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMHeat_Input_Eoopti_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_var1",
					DataPath = "@main.Input.SOLVE_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with information messages",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_info",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-PERT-IN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with warning messages",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warn",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-PERT-WA"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure stop with error messages",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "OPEN-NOPERT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Closed; use Perturbation layer around closed model",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_close",
					Value = "MMComboBox2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "PERTURBATION"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Neither; ignore block during EO solution",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
					Value = "MMComboBox2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "DO-NOT-CREAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main.Input.DERIV_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Analytical",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Analytical",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "ANALYTICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Numerical",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Numerical",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "NUMERICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Update (Analytical)",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
					Value = "MMComboBox1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "UPDATE-ANALY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Update (Numerical)",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
					Value = "MMComboBox1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "UPDATE-NUMER"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox9_var1",
					DataPath = "@main.Input.PASS_THROUGH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox9_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox9_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox11_var1",
					DataPath = "@main.Input.ALWAYS_INST"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Yes_1",
					Value = "MMComboBox11_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox11_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_No_1",
					Value = "MMComboBox11_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox11_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object MMComboBox9_MultiMap => GetValue(MMComboBox9_MultiMap_Property);

		public object MMComboBox11_MultiMap => GetValue(MMComboBox11_MultiMap_Property);
	}
	[ProgId("MMHeat.MMHeat_Input_Eoopti")]
	public class MMHeat_Input_Eoopti : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraEOOption;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox9_label;

		internal MMComboEdit MMComboBox9;

		internal MMLabel MMComboBox11_label;

		internal MMComboEdit MMComboBox11;

		private bool _contentLoaded;

		public MMHeat_Input_Eoopti()
		{
			base.ViewModelType = typeof(MMHeat_Input_Eoopti_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_input_eoopti.xaml", UriKind.Relative);
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
				fraEOOption = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox9_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox9 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox11_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox11 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMHeat_Input_Load_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.TVEC.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.TVEC.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.QVEC.@y"
			});

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TVEC"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.QVEC"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMHeat_Input_Load_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.TVEC",
				UseChildId = true,
				Name = "y"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.POINTS"
			}
		});

		public static readonly CxvPropertyDeclaration spnNPoints_NPOINT_Property = CxvPropertyDeclaration.Register("spnNPoints_NPOINT", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NPOINT"
		});

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);

		public object spnNPoints_NPOINT => GetValue(spnNPoints_NPOINT_Property);
	}
	[ProgId("MMHeat.MMHeat_Input_Load")]
	public class MMHeat_Input_Load : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel spnNPoints_label;

		internal MMSpinBox spnNPoints;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMHeat_Input_Load()
		{
			base.ViewModelType = typeof(MMHeat_Input_Load_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_input_load.xaml", UriKind.Relative);
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
				spnNPoints_label = (MMLabel)target;
				break;
			case 3:
				spnNPoints = (MMSpinBox)target;
				break;
			case 4:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMHeat_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuHeat_var1_Property = CxvPropertyDeclaration.Register("lbtuHeat_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DUTY"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEND"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMHeat_Input_Specif_ViewModel), new CxvMultiMapProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "enabletype",
				Operator = CxvLogicalOperator.Equal,
				Value = "1"
			},
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_var1",
					DataPath = "@main.Input.H_SCLASS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Heat",
					DisplayResourceKey = "MMHeat_Input_Specif_ViewModel__CxvMultiMapOption_Display_Heat",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "HEAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Load",
					DisplayResourceKey = "MMHeat_Input_Specif_ViewModel__CxvMultiMapOption_Display_Load",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_var1",
							Value = "LOAD"
						}
					}
				}
			}
		});

		public object lbtuHeat_var1 => GetValue(lbtuHeat_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("enabletype", "0");
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMHeat.MMHeat_Input_Specif")]
	public class MMHeat_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraHeat;

		internal MMLabel MMComboBox1_label;

		internal MMTextEdit MMComboBox1;

		internal MMLabel lbtuHeat_label;

		internal MMVariableEdit lbtuHeat;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		private bool _contentLoaded;

		public MMHeat_Input_Specif()
		{
			base.ViewModelType = typeof(MMHeat_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_input_specif.xaml", UriKind.Relative);
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
				fraHeat = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox1 = (MMTextEdit)target;
				break;
			case 4:
				lbtuHeat_label = (MMLabel)target;
				break;
			case 5:
				lbtuHeat = (MMVariableEdit)target;
				break;
			case 6:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 8:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 9:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMHeat_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMHeat_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Stream Results.Table"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHeat_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@heat1" }
		});

		public object heat1 => GetValue(heat1_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMHeat.MMHeat_Result")]
	public class MMHeat_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem info;

		private bool _contentLoaded;

		public MMHeat_Result()
		{
			base.ViewModelType = typeof(MMHeat_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_result.xaml", UriKind.Relative);
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
				info = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMHeat_Result_Heat_ViewModel : MMTabPageViewModel
	{
		public class grdHeat_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col",
				IsReadOnly = false
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
					int num = text.LastIndexOf("Streams.");
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
				DataPath = "@main.Stream Results.Table.#3.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#5.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#4.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#6.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#7.@col"
			});

			public static readonly CxvPropertyDeclaration MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Stream Results.Table.#8.@col"
			});

			public static readonly CxvPropertyDeclaration cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Stream Results.Table.#0.@col",
				IsReadOnly = false
			});

			public object txtTableVar_var1 => GetValue(txtTableVar_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox4_var1 => GetValue(MMTextBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox5_var1 => GetValue(MMTextBox5_var1_Property);

			public object MMTextBox6_var1 => GetValue(MMTextBox6_var1_Property);

			public object cboSubstr_var1 => GetValue(cboSubstr_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				if (pd == cboSubstr_var1_Property && subPropertyName == "Value" && cboSubstr_var1 != null)
				{
					string text = ExpandDataPath("@main");
					int num = text.LastIndexOf("Streams.");
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

		public static readonly CxvPropertyDeclaration txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#3"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#5"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.Id,
			DataPath = "@main.Stream Results.Table.#4"
		});

		public static readonly CxvPropertyDeclaration cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMHeat_Result_Heat_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
					Value = "cboDisplay_MultiMapOption_1",
					Prompt = "Display all streams",
					PromptResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
					DisplayResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
					Value = "cboDisplay_MultiMapOption_2",
					Prompt = "Enter desired streams",
					PromptResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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

		private ICxsDataWatch _watch;

		private Visibility _RegularVisibility = Visibility.Collapsed;

		private Visibility _BatchVisibility = Visibility.Collapsed;

		public static readonly CxvPropertyDeclaration grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMHeat_Result_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = false,
				Name = "col"
			}
		});

		public static readonly CxvPropertyDeclaration grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMHeat_Result_Heat_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdHeat_GridData2_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Stream Results.Table.#0",
				UseChildId = false,
				Name = "col"
			}
		});

		public object txtTableLab_var1 => GetValue(txtTableLab_var1_Property);

		public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

		public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

		public object cboDisplay_MultiMap => GetValue(cboDisplay_MultiMap_Property);

		public string label1 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#3", "id"));

		public string label2 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#4", "id"));

		public string label3 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#5", "id"));

		public string label4 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#6", "id"));

		public string label5 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#7", "id"));

		public string label6 => CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#8", "id"));

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

		public object grdHeat_GridData => GetValue(grdHeat_GridData_Property);

		public object grdHeat_GridData2 => GetValue(grdHeat_GridData2_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Stream Results.Table.#6", "id"))))
				{
					RegularVisibility = Visibility.Visible;
					BatchVisibility = Visibility.Collapsed;
				}
				else
				{
					RegularVisibility = Visibility.Collapsed;
					BatchVisibility = Visibility.Visible;
				}
				string text = ExpandDataPath("@main.Stream Results.Table.#3");
				string text2 = ExpandDataPath("@main.Stream Results.Table.#4");
				string text3 = ExpandDataPath("@main.Stream Results.Table.#5");
				string text4 = ExpandDataPath("@main.Stream Results.Table.#6");
				string text5 = ExpandDataPath("@main.Stream Results.Table.#7");
				string text6 = ExpandDataPath("@main.Stream Results.Table.#8");
				_watch = CreateCxsWatch();
				if (!string.IsNullOrEmpty(text))
				{
					_watch.AddWatch(text, "id");
				}
				if (!string.IsNullOrEmpty(text2))
				{
					_watch.AddWatch(text2, "id");
				}
				if (!string.IsNullOrEmpty(text3))
				{
					_watch.AddWatch(text3, "id");
				}
				if (!string.IsNullOrEmpty(text4))
				{
					_watch.AddWatch(text4, "id");
				}
				if (!string.IsNullOrEmpty(text5))
				{
					_watch.AddWatch(text5, "id");
				}
				if (!string.IsNullOrEmpty(text6))
				{
					_watch.AddWatch(text6, "id");
				}
				_watch.ValuesChanged += _watch_ValuesChanged;
			}
		}

		private void _watch_ValuesChanged(object sender, EventArgs e)
		{
			OnPropertyChanged("label1");
			OnPropertyChanged("label2");
			OnPropertyChanged("label3");
			OnPropertyChanged("label4");
			OnPropertyChanged("label5");
			OnPropertyChanged("label6");
		}

		public override void Unload()
		{
			base.Unload();
			_watch.ValuesChanged -= _watch_ValuesChanged;
			_watch.Unload();
			_watch = null;
		}
	}
	[ProgId("MMHeat.MMHeat_Result_Heat")]
	public class MMHeat_Result_Heat : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDisplay_label;

		internal MMComboEdit cboDisplay;

		internal MMScrollAreaHorizontal grdHeat;

		internal MMScrollAreaHorizontal grdHeat2;

		private bool _contentLoaded;

		public MMHeat_Result_Heat()
		{
			base.ViewModelType = typeof(MMHeat_Result_Heat_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/heat/mmheat_result_heat.xaml", UriKind.Relative);
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
}
namespace AspenTech.AspenPlus.MMForms.Streams.Control
{
	public class MMControl_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SPEC_Property = CxvPropertyDeclaration.Register("SPEC", typeof(MMControl_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMControl_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SPEC" }
		});

		public object SPEC => GetValue(SPEC_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMControl.MMControl_Input")]
	public class MMControl_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab8;

		private bool _contentLoaded;

		public MMControl_Input()
		{
			base.ViewModelType = typeof(MMControl_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/control/mmcontrol_input.xaml", UriKind.Relative);
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
				tab8 = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMControl_Input_Spec_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration PVBlock_Property = CxvPropertyDeclaration.Register("PVBlock", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FVN_BLOCK"
		});

		public static readonly CxvPropertyDeclaration PVStream_Property = CxvPropertyDeclaration.Register("PVStream", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FVN_STREAM"
		});

		public static readonly CxvPropertyDeclaration PVVariable_Property = CxvPropertyDeclaration.Register("PVVariable", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FVN_VARIABLE"
		});

		public static readonly CxvPropertyDeclaration OPBlock_Property = CxvPropertyDeclaration.Register("OPBlock", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VARYBLOCK"
		});

		public static readonly CxvPropertyDeclaration OPStream_Property = CxvPropertyDeclaration.Register("OPStream", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VARYSTREAM"
		});

		public static readonly CxvPropertyDeclaration OPVariable_Property = CxvPropertyDeclaration.Register("OPVariable", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VARYVARIABLE"
		});

		public static readonly CxvPropertyDeclaration lbtuSetPoint_Property = CxvPropertyDeclaration.Register("lbtuSetPoint", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SETPOINT"
		});

		public object PVBlock => GetValue(PVBlock_Property);

		public object PVStream => GetValue(PVStream_Property);

		public object PVVariable => GetValue(PVVariable_Property);

		public object OPBlock => GetValue(OPBlock_Property);

		public object OPStream => GetValue(OPStream_Property);

		public object OPVariable => GetValue(OPVariable_Property);

		public object lbtuSetPoint => GetValue(lbtuSetPoint_Property);
	}
	[ProgId("MMControl.MMControl_Input_Spec")]
	public class MMControl_Input_Spec : MMTabPage, IComponentConnector
	{
		internal MMLabel In_label;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox3_label;

		internal MMComboEdit MMComboBox3;

		internal MMLabel Out_label;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel lbtuSetPoint_label;

		internal MMVariableEdit lbtuSetPoint;

		private bool _contentLoaded;

		public MMControl_Input_Spec()
		{
			base.ViewModelType = typeof(MMControl_Input_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Streams;component/control/mmcontrol_input_spec.xaml", UriKind.Relative);
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
				In_label = (MMLabel)target;
				break;
			case 2:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 8:
				Out_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 11:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 12:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 13:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 15:
				lbtuSetPoint_label = (MMLabel)target;
				break;
			case 16:
				lbtuSetPoint = (MMVariableEdit)target;
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

// 0x0600000b AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Input_ViewModel..ctor
// public MMWork_Input_ViewModel()
// {
// }

// 0x0600000c AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMWork_Input_ViewModel()
// {
// 	power_Property = CxvPropertyDeclaration.Register("power", typeof(MMWork_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MN1"
// 	});
// 	ENTOPT_Property = CxvPropertyDeclaration.Register("ENTOPT", typeof(MMWork_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTOPT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMWork_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@power" },
// 		EnteredDataPaths = { "@ENTOPT" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMWork_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ENTOPT" }
// 	});
// }

// 0x06000012 AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Input_Specif_ViewModel..ctor
// public MMWork_Input_Specif_ViewModel()
// {
// }

// 0x06000013 AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMWork_Input_Specif_ViewModel()
// {
// 	MMLBUText1_1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_1_var1", typeof(MMWork_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SPEED"
// 	});
// 	MMLBUText1_0_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_0_var1", typeof(MMWork_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.POWER"
// 	});
// }

// 0x06000019 AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_ViewModel..ctor
// public MMWork_Result_ViewModel()
// {
// }

// 0x0600001a AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMWork_Result_ViewModel()
// {
// 	work1_Property = CxvPropertyDeclaration.Register("work1", typeof(MMWork_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMWork_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@work1" }
// 	});
// }

// 0x0600002d AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel..ctor
// using System.Windows;
//
// public MMWork_Result_Work_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x0600002e AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMWork_Result_Work_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMWork_Result_Work_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
// 				DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#3"
// 	});
// 	grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMWork_Result_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMWork_Result_Work_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData2_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	label1_Property = CxvPropertyDeclaration.Register("label1", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label2_Property = CxvPropertyDeclaration.Register("label2", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label3_Property = CxvPropertyDeclaration.Register("label3", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label4_Property = CxvPropertyDeclaration.Register("label4", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#6",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label5_Property = CxvPropertyDeclaration.Register("label5", typeof(MMWork_Result_Work_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#7",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x06000034 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Input_ViewModel..ctor
// public MMPower_Input_ViewModel()
// {
// }

// 0x06000035 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPower_Input_ViewModel()
// {
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPower_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.SPEC" },
// 		EnteredDataPaths = { "@main.CC Nodes.ENTSPC" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPower_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@main.CC Nodes.ENTOPT" }
// 	});
// }

// 0x0600003c AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Input_Specif_ViewModel..ctor
// public MMPower_Input_Specif_ViewModel()
// {
// }

// 0x0600003d AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMPower_Input_Specif_ViewModel()
// {
// 	Specif_MultiMap_Property = CxvPropertyDeclaration.Register("Specif_MultiMap", typeof(MMPower_Input_Specif_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "Specif_var1",
// 				DataPath = "@main.Input.SPECIF"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				DisplayResourceKey = ApwnResources.MMPower_Power,
// 				Value = "Specif_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Specif_var1",
// 						Value = "POWER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				DisplayResourceKey = ApwnResources.MMPower_Input_Amperage,
// 				Value = "Specif_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Specif_var1",
// 						Value = "AMPERAGE"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.AMPPOW"
// 		}
// 	});
// 	Power_var1_Property = CxvPropertyDeclaration.Register("Power_var1", typeof(MMPower_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.POWER"
// 	});
// 	Amperage_var1_Property = CxvPropertyDeclaration.Register("Amperage_var1", typeof(MMPower_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AMPERAGE",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.ENAMP"
// 		}
// 	});
// }

// 0x06000043 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_ViewModel..ctor
// public MMPower_Result_ViewModel()
// {
// }

// 0x06000044 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPower_Result_ViewModel()
// {
// 	work1_Property = CxvPropertyDeclaration.Register("power1", typeof(MMPower_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPower_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@power1" }
// 	});
// }

// 0x06000057 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel..ctor
// using System.Windows;
//
// public MMPower_Result_Power_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000058 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPower_Result_Power_ViewModel()
// {
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMPower_Result_Power_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				PromptResourceKey = "MMPower_Result_Power_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
// 				DisplayResourceKey = "MMWork_Result_Work_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				PromptResourceKey = "MMPower_Result_Power_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#4"
// 	});
// 	txtTablelab_var1_Property = CxvPropertyDeclaration.Register("txtTablelab_var1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#3"
// 	});
// 	grdWork_GridData_Property = CxvPropertyDeclaration.Register("grdWork_GridData", typeof(MMPower_Result_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	grdWork_GridData2_Property = CxvPropertyDeclaration.Register("grdWork_GridData2", typeof(MMPower_Result_Power_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdWork_GridData2_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = true,
// 			Name = "col"
// 		}
// 	});
// 	label1_Property = CxvPropertyDeclaration.Register("label1", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label2_Property = CxvPropertyDeclaration.Register("label2", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label3_Property = CxvPropertyDeclaration.Register("label3", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label4_Property = CxvPropertyDeclaration.Register("label4", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#6",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	label5_Property = CxvPropertyDeclaration.Register("label5", typeof(MMPower_Result_Power_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#7",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x06000068 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Info_ViewModel..ctor
// public MMMaterial_Input_Info_ViewModel()
// {
// 	_recType = string.Empty;
// 	base..ctor();
// }

// 0x06000069 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Info_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Info_ViewModel()
// {
// 	streamName_var_Property = CxvPropertyDeclaration.Register("streamName_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main",
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		IsReadOnly = true,
// 		IsCalculated = false,
// 		VariablePrompt = "The name of the stream",
// 		VariablePromptResourceKey = "MMMaterial_Input_Info_Name"
// 	});
// 	streamType_var_Property = CxvPropertyDeclaration.Register("streamType_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main",
// 		DataAttribute = "type",
// 		ExposeAs = CxvVariableTypeCode.String,
// 		IsReadOnly = false
// 	});
// 	fromValue_var_Property = CxvPropertyDeclaration.Register("fromValue_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Ports.SOURCE.#0",
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		IsReadOnly = true,
// 		IsCalculated = false,
// 		VariablePrompt = "The source of the stream",
// 		VariablePromptResourceKey = "MMMaterial_Input_Info_From"
// 	});
// 	toValue_var_Property = CxvPropertyDeclaration.Register("toValue_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Ports.DEST.#0",
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		IsReadOnly = true,
// 		IsCalculated = false,
// 		VariablePrompt = "The destination of the stream",
// 		VariablePromptResourceKey = "MMMaterial_Input_Info_To"
// 	});
// 	descriptionInput_var_Property = CxvPropertyDeclaration.Register("descriptionInput_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DESCRIPTION",
// 		IsReadOnly = false,
// 		IsCalculated = false,
// 		IsEntered = true
// 	});
// 	reportOptions_varProperty = CxvPropertyDeclaration.Register("reportOptions_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Setup.ReportOptions.Stream-Names.Input.TEXT.@id",
// 		IsReadOnly = false,
// 		IsCalculated = false,
// 		IsEntered = true
// 	});
// 	comments_var_Property = CxvPropertyDeclaration.Register("comments_var", typeof(MMMaterial_Input_Info_ViewModel), new CxvDescriptionProperty
// 	{
// 		DataPath = "@main.Comments"
// 	});
// }

// 0x06000082 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_AddOpt_ViewModel..ctor
// public MMMaterial_AddOpt_ViewModel()
// {
// }

// 0x06000083 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_AddOpt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_AddOpt_ViewModel()
// {
// 	lbtuTempTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTempTol_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.EO_TEMP_TOL"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRAC_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VFRAC"
// 		}
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRACX_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VFRAC"
// 		}
// 	});
// 	MMLBUText5_var1_Property = CxvPropertyDeclaration.Register("MMLBUText5_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SFRAC_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SFRC"
// 		}
// 	});
// 	MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.COMP_TOL"
// 	});
// 	MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox11_var1",
// 				DataPath = "@main.Input.ALWAYS_INST"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox11_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox11_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox11_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox11_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox9_var1",
// 				DataPath = "@main.Input.PASS_THROUGH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_1",
// 				Value = "MMComboBox9_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_1",
// 				Value = "MMComboBox9_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NEG_COMP_CHK"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NEG_FLOW_CHK"
// 	});
// 	MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox4_var1",
// 				DataPath = "@main.Input.EO_FORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard",
// 				Value = "MMComboBox4_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "STANDARD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO-PML",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML",
// 				Value = "MMComboBox4_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "EOPML"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RT-Opt 10.0",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0",
// 				Value = "MMComboBox4_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "MOLEFRAC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RT-Opt 3.0",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_3_0",
// 				Value = "MMComboBox4_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "MOLEFLOW"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Input.DERIV_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Analytical",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Analytical",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "ANALYTICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Numerical",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Numerical",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "NUMERICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Update (Analytical)",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "UPDATE-ANALY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Update (Numerical)",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "UPDATE-NUMER"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Input.SOLVE_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with information messages",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_inform",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-PERT-IN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with warning messages",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warnin",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-PERT-WA"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure stop with error messages",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-NOPERT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Closed; use Perturbation layer around closed model",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_",
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "PERTURBATION"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Neither; ignore block during EO solution",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
// 				Value = "MMComboBox2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "DO-NOT-CREAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox17_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox17_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox17_var1",
// 				DataPath = "@main.Input.AUTO_PHASE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_2",
// 				Value = "MMComboBox17_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox17_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_2",
// 				Value = "MMComboBox17_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox17_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_PHASE_T"
// 	});
// 	MMComboBox10_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox10_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox10_var1",
// 				DataPath = "@main.Input.FLASH_FORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "PML",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_PML",
// 				Value = "MMComboBox10_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox10_var1",
// 						Value = "PML"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Smoothing",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Smoothing",
// 				Value = "MMComboBox10_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox10_var1",
// 						Value = "SMOOTHING"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox12_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox12_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox12_var1",
// 				DataPath = "@main.Input.L2_COMP_MODE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Auto",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Auto",
// 				Value = "MMComboBox12_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox12_var1",
// 						Value = "AUTO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "None",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_None",
// 				Value = "MMComboBox12_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox12_var1",
// 						Value = "NONE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "CompID",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_CompID",
// 				Value = "MMComboBox12_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox12_var1",
// 						Value = "COMPID"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.L2CP1"
// 		}
// 	});
// 	MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_L2_COMP",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.L2CP1"
// 		}
// 	});
// 	MMComboBox8_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox8_var1",
// 				DataPath = "@main.Input.CHECK_FREE_W"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_3",
// 				Value = "MMComboBox8_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox8_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_No_3",
// 				Value = "MMComboBox8_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox8_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_HEAVY_KEY"
// 	});
// 	MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_LIGHT_KEY"
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMMaterial_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_DEP_COMPS"
// 	});
// 	MMComboBox7_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox7_MultiMap", typeof(MMMaterial_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox7_var1",
// 				DataPath = "@main.Input.SPARSITY"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature & pressure",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature___pressure",
// 				Value = "MMComboBox7_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox7_var1",
// 						Value = "COMP-INDEP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature, pressure & composition",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition",
// 				Value = "MMComboBox7_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox7_var1",
// 						Value = "FULL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature, pressure & composition for water",
// 				DisplayResourceKey = "MMMaterial_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition_for_water",
// 				Value = "MMComboBox7_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox7_var1",
// 						Value = "WATER-SOLU"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SPAR"
// 		}
// 	});
// }

// 0x0600008d AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Eoopti_Model_ViewModel..ctor
// public MMMaterial_Eoopti_Model_ViewModel()
// {
// }

// 0x0600008e AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Eoopti_Model_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMaterial_Eoopti_Model_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
// 	{
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Eoopti_Model_Prompt1
// 	});
// 	MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox6_var1",
// 				DataPath = "@main.Input.AUTO_COMPS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Always",
// 				DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
// 				PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always_Prompt",
// 				Value = "MMComboBox6_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox6_var1",
// 						Value = "ALWAYS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No model comps",
// 				DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
// 				PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps_Prompt",
// 				Value = "MMComboBox6_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox6_var1",
// 						Value = "IF-NO-COMPS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Never",
// 				DisplayResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
// 				PromptResourceKey = "MMMaterial_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never_Prompt",
// 				Value = "MMComboBox6_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox6_var1",
// 						Value = "NEVER"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_COMPS_T"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMMaterial_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_COMPS"
// 	});
// }

// 0x060000ac AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ViewModel..ctor
// public MMMaterial_Input_ViewModel()
// {
// }

// 0x060000ad AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_ViewModel()
// {
// 	SUBSTRID_Property = CxvPropertyDeclaration.Register("SUBSTRID", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBSTRID"
// 	});
// 	SPECS_Property = CxvPropertyDeclaration.Register("SPECS", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPECS"
// 	});
// 	FLASHOPT_Property = CxvPropertyDeclaration.Register("FLASHOPT", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FLSOPT"
// 	});
// 	SUBATTRID_Property = CxvPropertyDeclaration.Register("SUBATTRID", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBATTRID"
// 	});
// 	SUBCATID1_Property = CxvPropertyDeclaration.Register("SUBCATID1", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID1"
// 	});
// 	SUBCATID2_Property = CxvPropertyDeclaration.Register("SUBCATID2", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID2"
// 	});
// 	SUBCATID3_Property = CxvPropertyDeclaration.Register("SUBCATID3", typeof(MMMaterial_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID3"
// 	});
// 	PSDCOMP_Property = CxvPropertyDeclaration.Register("PSDCOMP", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.PSD"
// 	});
// 	ATTRCOMP_Property = CxvPropertyDeclaration.Register("ATTRCOMP", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ATTR"
// 	});
// 	PSDACC_Property = CxvPropertyDeclaration.Register("PSDACC", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.PSD1"
// 	});
// 	ATTRACC_Property = CxvPropertyDeclaration.Register("ATTRACC", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CMP1"
// 	});
// 	flshe_Property = CxvPropertyDeclaration.Register("flshe", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FLSHE"
// 	});
// 	ENTEOMOD_Property = CxvPropertyDeclaration.Register("ENTEOMOD", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTEOMOD"
// 	});
// 	L2CP2_Property = CxvPropertyDeclaration.Register("L2CP2", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.L2CP2"
// 	});
// 	ENTCOST_Property = CxvPropertyDeclaration.Register("ENTCOST", typeof(MMMaterial_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTCOST"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@SPECS" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@FLASHOPT" },
// 		EnteredDataPaths = { "@flshe" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PSDCOMP" },
// 		AccessibleDataPaths = { "@PSDACC" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@ATTRCOMP" },
// 		AccessibleDataPaths = { "@ATTRACC" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@L2CP2" },
// 		EnteredDataPaths = { "@ENTEOMOD" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ENTCOST" }
// 	});
// 	mixed_phase_var_Property = CxvPropertyDeclaration.Register("mixed_phase_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.SPECS", "@main.CC Nodes.SPEC4.MIXED", "@main.CC Nodes.ATTR.MIXED", "@main.CC Nodes.MIXPSD" }
// 	});
// 	conv_solids_var_Property = CxvPropertyDeclaration.Register("conv_solids_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.SP3C2", "@main.CC Nodes.CNVSPECS", "@main.CC Nodes.CNVATTR", "@main.CC Nodes.CNVPSD" },
// 		AccessibleDataPaths = { "@main.CC Nodes.CSTAB" }
// 	});
// 	nonconv_solids_var_Property = CxvPropertyDeclaration.Register("nonconv_solids_var", typeof(MMMaterial_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.SP3C2", "@main.CC Nodes.NCSPECS", "@main.CC Nodes.NCVATTR", "@main.CC Nodes.NCPSD" },
// 		AccessibleDataPaths = { "@main.CC Nodes.NCTAB" }
// 	});
// }

// 0x060000bd AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Compat_ViewModel..ctor
// public MMMaterial_Input_Compat_ViewModel()
// {
// }

// 0x060000be AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Compat_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Compat_ViewModel()
// {
// 	mnbSubstream_var2_Property = CxvPropertyDeclaration.Register("mnbSubstream_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID1"
// 	});
// 	mnbSubstream_var1_Property = CxvPropertyDeclaration.Register("mnbSubstream_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL",
// 		SelectedItemBinding = "mnbSubstream_var2.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
// 		CompletePaths = { "ATTR" },
// 		EnteredPaths = { "ENTSUBSTR" }
// 	});
// 	txtATotal_var1_Property = CxvPropertyDeclaration.Register("txtATotal_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ATTOTAL.@SUBCATID1.@SUBCATID2.@SUBCATID3"
// 	});
// 	mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID3"
// 	});
// 	mnbAttribute_component_Property = CxvPropertyDeclaration.Register("mnbAttribute_component", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ATTR.@SUBCATID1.@SUBCATID2"
// 	});
// 	mnbAttribute_entcomp_Property = CxvPropertyDeclaration.Register("mnbAttribute_entcomp", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTCOMP.@SUBCATID1.@SUBCATID2"
// 	});
// 	mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@SUBCATID1.@SUBCATID2",
// 		SelectedItemBinding = "mnbAttribute_var2.Value",
// 		CreateNewPrompt = "Attribute ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Attribute_ID_",
// 		CompletePaths = { "@main.CC Nodes.ATTR.@SUBCATID1.@SUBCATID2" },
// 		EnteredPaths = { "@main.CC Nodes.ENTCOMP.@SUBCATID1.@SUBCATID2" }
// 	});
// 	mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_Compat_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID2"
// 	});
// 	mnbComponent_substream_Property = CxvPropertyDeclaration.Register("mnbComponent_substream", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ATTR.@SUBCATID1"
// 	});
// 	mnbComponent_entsubstr_Property = CxvPropertyDeclaration.Register("mnbComponent_entsubstr", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTSUBSTR.@SUBCATID1"
// 	});
// 	mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_Compat_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@SUBCATID1",
// 		SelectedItemBinding = "mnbComponent_var2.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_Compat_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
// 		CompletePaths = { "@main.CC Nodes.ATTR.@SUBCATID1" },
// 		EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@SUBCATID1" }
// 	});
// 	grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_Compat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.ELEM.@SUBCATID1.@SUBCATID2.@SUBCATID3",
// 			UseChildId = true,
// 			Name = "ROWNUM",
// 			ProxyRow = false
// 		}
// 	});
// }

// 0x060000f4 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel..ctor
// public MMMaterial_Input_ConvSol_ViewModel()
// {
// 	_needUpdateCombos = true;
// 	_needUpdateSubstream = true;
// 	base..ctor();
// }

// 0x060000f5 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMaterial_Input_ConvSol_ViewModel()
// {
// 	mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "CONVSUBID"
// 	});
// 	mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NPHASE",
// 		SelectedItemBinding = "mnbSubstream_target.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
// 		CompletePaths = { "@main.CC Nodes.CNVSPEC2", "@main.CC Nodes.CNVSPEC3", "@main.CC Nodes.CNVPSD", "@main.CC Nodes.CNVATTR", "@main.CC Nodes.PSPEC2" },
// 		Filter = new CxvSubstreamFilter
// 		{
// 			SubstreamType = CxvSubstreamFilter.eSubstreamType.Conventional
// 		}
// 	});
// 	tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTFLOW.@CONVSUBID",
// 		BasisPath = "@main.Input.FLOWBASE.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTAL.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdComposition_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FLOW.@CONVSUBID",
// 			UseChildId = true,
// 			Name = "COMPCONV"
// 		}
// 	});
// 	lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@CONVSUBID",
// 		BasisPath = "@main.Input.BASIS.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.CMP1.@CONVSUBID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_ConvSol_Prompt1
// 	});
// 	expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.CNVPSD.@CONVSUBID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.PSD1.@CONVSUBID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_ConvSol_Prompt2
// 	});
// 	mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID5"
// 	});
// 	mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@CONVSUBID.@SUBCATID4",
// 		SelectedItemBinding = "mnbAttribute_var2.Value",
// 		CreateNewPrompt = "Attribute ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
// 		CompletePaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID.@SUBCATID4" },
// 		EnteredPaths = { "@main.CC Nodes.ENTCOMP.@CONVSUBID.@SUBCATID4" },
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID4"
// 	});
// 	mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@CONVSUBID",
// 		SelectedItemBinding = "mnbComponent_var2.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
// 		CompletePaths = { "@main.CC Nodes.CNVATTR1.@CONVSUBID" },
// 		EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@CONVSUBID" },
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.ELEM.@CONVSUBID.@SUBCATID4.@SUBCATID5",
// 			UseChildId = true,
// 			Name = "ROWNUM2",
// 			ProxyRow = false
// 		}
// 	});
// 	txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIMUNITS.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PSDID.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.PSDID.@CONVSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.INTERVAL.@CONVSUBID",
// 			UseChildId = true,
// 			Name = "POINT"
// 		}
// 	});
// 	cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.PSD9.@CONVSUBID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.CNVPSD1.@CONVSUBID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrSelMethod_var1",
// 				DataPath = "@main.Input.WTFRAC_OPT.@CONVSUBID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "User specified values",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "USER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "A distribution function",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "FUNCTION"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CNVPSD1.@CONVSUBID"
// 		}
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD2.@CONVSUBID"
// 		}
// 	});
// 	Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "TypeCBox_var1",
// 				DataPath = "@main.Input.TYPE.@CONVSUBID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "GGS",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_GGS",
// 				Value = "Type_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "GGS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RRSB",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_RRSB",
// 				Value = "Type_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "RRSB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Normal",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Normal",
// 				Value = "Type_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "NORMAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Log Normal",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Log_Normal",
// 				Value = "Type_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "LOG-NORMAL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
// 		}
// 	});
// 	txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GGS_N.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
// 		}
// 	});
// 	txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DIAM.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@CONVSUBID"
// 		}
// 	});
// 	RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
// 		}
// 	});
// 	txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.RRSB_N.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
// 		}
// 	});
// 	txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D63.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@CONVSUBID"
// 		}
// 	});
// 	StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@CONVSUBID"
// 		}
// 	});
// 	txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.STDDEV.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@CONVSUBID"
// 		}
// 	});
// 	D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@CONVSUBID"
// 		}
// 	});
// 	txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D50.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@CONVSUBID"
// 		}
// 	});
// 	GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@CONVSUBID"
// 		}
// 	});
// 	txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GMDEV.@CONVSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@CONVSUBID"
// 		}
// 	});
// 	CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_ConvSol_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UOM.@CONVSUBID.@SUBCATID4.@SUBCATID5"
// 	});
// }

// 0x060000fc AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Costing_ViewModel..ctor
// public MMMaterial_Input_Costing_ViewModel()
// {
// }

// 0x060000fd AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Costing_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Costing_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_Input_Costing_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRICE"
// 	});
// }

// 0x06000105 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Flasho_ViewModel..ctor
// public MMMaterial_Input_Flasho_ViewModel()
// {
// }

// 0x06000106 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Flasho_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Flasho_ViewModel()
// {
// 	lbtuTolerance_var1_Property = CxvPropertyDeclaration.Register("lbtuTolerance_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL.MIXED",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.NOFL.MIXED"
// 		}
// 	});
// 	chkStreamProps_var1_Property = CxvPropertyDeclaration.Register("chkStreamProps_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.FL_OPTION.MIXED",
// 		FalseValue = "NOFLASH",
// 		DefaultValue = true
// 	});
// 	cboValidPhases_MultiMap_Property = CxvPropertyDeclaration.Register("cboValidPhases_MultiMap", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboValidPhases_var1",
// 				DataPath = "@main.Input.NPHASE.MIXED"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboValidPhases_var2",
// 				DataPath = "@main.Input.PHASE.MIXED"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboValidPhases_var3",
// 				DataPath = "@main.Input.FREE_WATER.MIXED"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboValidPhases_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboValidPhases_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboValidPhases_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboValidPhases_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_consider",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboValidPhases_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__a",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "3"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Freewater",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Freewater",
// 				Value = "cboValidPhases_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Freewater",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Freewater",
// 				Value = "cboValidPhases_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Dirtywater",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Dirtywater",
// 				Value = "cboValidPhases_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Dirtywater",
// 				DisplayResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Dirtywater",
// 				Value = "cboValidPhases_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMaterial_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_wate",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var1",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var2",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboValidPhases_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.NOFL.MIXED"
// 		}
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMMaterial_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT.MIXED",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.NOFL.MIXED"
// 		}
// 	});
// }

// 0x06000154 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel..ctor
// public MMMaterial_Input_MixedPha_ViewModel()
// {
// 	_needUpdateVar = true;
// 	_needUpdateCombos = true;
// 	base..ctor();
// }

// 0x06000155 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMaterial_Input_MixedPha_ViewModel()
// {
// 	mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBSTRID"
// 	});
// 	mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NPHASE",
// 		SelectedItemBinding = "mnbSubstream_target.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
// 		CompletePaths = { "@main.CC Nodes.SPEC2", "@main.CC Nodes.ATTR" },
// 		Filter = new CxvSubstreamFilter
// 		{
// 			SubstreamType = CxvSubstreamFilter.eSubstreamType.Mixed
// 		}
// 	});
// 	cboSpecOpt_var1_Property = CxvPropertyDeclaration.Register("cboSpecOpt_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SpecOpt1"
// 	});
// 	cboSpecOpt_var2_Property = CxvPropertyDeclaration.Register("cboSpecOpt_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SpecOpt2"
// 	});
// 	cboSpecOpt_AdvCollection1_Property = CxvPropertyDeclaration.Register("cboSpecOpt_AdvCollection1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Temperature",
// 				EnabledPropertyPath = "Opt2NotTemp.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display1"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Pressure",
// 				EnabledPropertyPath = "Opt2NotPress.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display_Pressure"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vapor Fraction",
// 				EnabledPropertyPath = "Opt2NotVap.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display_VaporFraction"
// 			}
// 		},
// 		SelectedItemBinding = "cboSpecOpt_var1.Value"
// 	});
// 	cboSpecOpt_AdvCollection2_Property = CxvPropertyDeclaration.Register("cboSpecOpt_AdvCollection2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		UseItemsCollection = true,
// 		Items = 
// 		{
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Temperature",
// 				EnabledPropertyPath = "Opt1NotTemp.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display1"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Pressure",
// 				EnabledPropertyPath = "Opt1NotPress.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display2"
// 			},
// 			new CxvAdvCollectionItem
// 			{
// 				Display = "Vapor Fraction",
// 				EnabledPropertyPath = "Opt1NotVap.Value",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_Display3"
// 			}
// 		},
// 		SelectedItemBinding = "cboSpecOpt_var2.Value"
// 	});
// 	Opt1NotTemp_Property = CxvPropertyDeclaration.Register("Opt1NotTemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var1.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Temperature"
// 	});
// 	Opt1NotPress_Property = CxvPropertyDeclaration.Register("Opt1NotPress", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var1.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Pressure"
// 	});
// 	Opt1NotVap_Property = CxvPropertyDeclaration.Register("Opt1NotVap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var1.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Vapor Fraction"
// 	});
// 	Opt2NotTemp_Property = CxvPropertyDeclaration.Register("Opt2NotTemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var2.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Temperature"
// 	});
// 	Opt2NotPress_Property = CxvPropertyDeclaration.Register("Opt2NotPress", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var2.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Pressure"
// 	});
// 	Opt2NotVap_Property = CxvPropertyDeclaration.Register("Opt2NotVap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "cboSpecOpt_var2.Value",
// 		Operator = CxvLogicalOperator.NotEqual,
// 		Value = "Vapor Fraction"
// 	});
// 	cboSpecOpt_MultiMap_Property = CxvPropertyDeclaration.Register("cboSpecOpt_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboSpecOpt_MIXED_SPEC",
// 				DataPath = "@main.Input.MIXED_SPEC.@SubID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature & pressure",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Temperature_pressure",
// 				Value = "cboSpecOpt_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSpecOpt_MIXED_SPEC",
// 						Value = "TP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature & vapor fraction",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Temperature_vaporfraction",
// 				Value = "cboSpecOpt_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSpecOpt_MIXED_SPEC",
// 						Value = "TV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Pressure & vapor fraction",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Pressure_vaporfraction",
// 				Value = "cboSpecOpt_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSpecOpt_MIXED_SPEC",
// 						Value = "PV"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	SubID_var_Property = CxvPropertyDeclaration.Register("SubID_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.#0",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// 	tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.TEMP.@SubID"
// 		}
// 	});
// 	presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PRES.@SubID"
// 		}
// 	});
// 	vaporVEdit_var_Property = CxvPropertyDeclaration.Register("vaporVEdit_var", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRAC.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FRAC.@SubID"
// 		}
// 	});
// 	lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTFLOW.@SubID",
// 		BasisPath = "@main.Input.FLOWBASE.@SubID"
// 	});
// 	cboSolvent_var1_Property = CxvPropertyDeclaration.Register("cboSolvent_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.SOLVENT.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SOLV.@SubID"
// 		}
// 	});
// 	expandar_reftemp_Property = CxvPropertyDeclaration.Register("expandar_reftemp", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
// 	{
// 		EnteredDataPaths = { "@main.CC Nodes.ENTREF.@SubID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.REFT1.@SubID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt1
// 	});
// 	lbtuVolRef_var1_Property = CxvPropertyDeclaration.Register("lbtuVolRef_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VOL_TREF.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.REFT1.@SubID"
// 		}
// 	});
// 	lbtuConcRef_var1_Property = CxvPropertyDeclaration.Register("lbtuConcRef_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CONC_TREF.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.REFT2.@SubID"
// 		}
// 	});
// 	txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTAL.@SubID"
// 	});
// 	lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@SubID",
// 		BasisPath = "@main.Input.BASIS.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Input.FLOW.@SubID",
// 			DataAttribute = "has_children",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = 1
// 		}
// 	});
// 	grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdComposition_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FLOW.@SUBSTRID",
// 			UseChildId = true,
// 			Name = "COMPMIXED"
// 		}
// 	});
// 	expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.ATTR.@SubID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.CMP1.@SUBSTRID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt2
// 	});
// 	expanderAttr_state_Property = CxvPropertyDeclaration.Register("expanderAttr_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.ATTR1"
// 		}
// 	});
// 	mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID3"
// 	});
// 	mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@SubID.@SUBCATID2",
// 		SelectedItemBinding = "mnbAttribute_var2.Value",
// 		CreateNewPrompt = "Attribute ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
// 		CompletePaths = { "@main.CC Nodes.ATTR.@SubID.@SUBCATID2" },
// 		EnteredPaths = { "@main.CC Nodes.ENTCOMP.@SubID.@SUBCATID2" }
// 	});
// 	mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID2"
// 	});
// 	mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@SubID",
// 		SelectedItemBinding = "mnbComponent_var2.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
// 		CompletePaths = { "@main.CC Nodes.ATTR.@SubID" },
// 		EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@SubID" }
// 	});
// 	grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.ELEM.@SubID.@SUBCATID2.@SUBCATID3",
// 			UseChildId = true,
// 			Name = "ROWNUM",
// 			ProxyRow = false
// 		}
// 	});
// 	expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.MIXPSD" },
// 		AccessibleDataPaths = { "@main.CC Nodes.PSD12" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_MixedPha_Prompt3
// 	});
// 	txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIMUNITS.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "#0",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PSDID.@SubID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.INTERVAL.@SubID",
// 			UseChildId = true,
// 			Name = "POINT"
// 		}
// 	});
// 	cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.PSD9.@SubID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.MIXPSD1.@SubID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.PSDID.@SubID"
// 	});
// 	ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrSelMethod_var1",
// 				DataPath = "@main.Input.WTFRAC_OPT.@SubID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "User specified values",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "USER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "A distribution function",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "FUNCTION"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.MIXPSD1.@SubID"
// 		}
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD2.@SubID"
// 		}
// 	});
// 	Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "TypeCBox_var1",
// 				DataPath = "@main.Input.TYPE.@SubID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "GGS",
// 				DisplayResourceKey = "",
// 				Value = "Type_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "GGS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RRSB",
// 				DisplayResourceKey = "",
// 				Value = "Type_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "RRSB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Normal",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel_Normal",
// 				Value = "Type_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "NORMAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Log Normal",
// 				DisplayResourceKey = "MMMaterial_Input_MixedPha_ViewModel_LogNormal",
// 				Value = "Type_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "LOG-NORMAL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@SubID"
// 		}
// 	});
// 	txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GGS_N.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@SubID"
// 		}
// 	});
// 	txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DIAM.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@SubID"
// 		}
// 	});
// 	RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@SubID"
// 		}
// 	});
// 	txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.RRSB_N.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@SubID"
// 		}
// 	});
// 	txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D63.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@SubID"
// 		}
// 	});
// 	StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@SubID"
// 		}
// 	});
// 	txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.STDDEV.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@SubID"
// 		}
// 	});
// 	D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@SubID"
// 		}
// 	});
// 	txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D50.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@SubID"
// 		}
// 	});
// 	GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@SubID"
// 		}
// 	});
// 	txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GMDEV.@SubID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@SubID"
// 		}
// 	});
// 	CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_MixedPha_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UOM.@SubID.@SUBCATID2.@SUBCATID3"
// 	});
// }

// 0x0600018e AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel..ctor
// public MMMaterial_Input_NCSolid_ViewModel()
// {
// 	_needUpdateCombos = true;
// 	_needUpdateSubstream = true;
// 	base..ctor();
// }

// 0x0600018f AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMaterial_Input_NCSolid_ViewModel()
// {
// 	mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "NCSUBID"
// 	});
// 	mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NPHASE",
// 		SelectedItemBinding = "mnbSubstream_target.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Substream_name",
// 		CompletePaths = { "@main.CC Nodes.NCSPEC2", "@main.CC Nodes.NCSPEC3", "@main.CC Nodes.NCPSD", "@main.CC Nodes.NCVATTR", "@main.CC Nodes.PSPEC3" },
// 		Filter = new CxvSubstreamFilter
// 		{
// 			SubstreamType = CxvSubstreamFilter.eSubstreamType.NonConventional
// 		}
// 	});
// 	tempVEdit_var_Property = CxvPropertyDeclaration.Register("tempVEdit_var", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	presVEdit_var_Property = CxvPropertyDeclaration.Register("presVEdit_var", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTFLOW.@NCSUBID",
// 		BasisPath = "@main.Input.FLOWBASE.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTAL.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdComposition_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FLOW.@NCSUBID",
// 			UseChildId = true,
// 			Name = "COMPCONV"
// 		}
// 	});
// 	lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@NCSUBID",
// 		BasisPath = "@main.Input.BASIS.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	expandar_comattr_Property = CxvPropertyDeclaration.Register("expandar_comattr", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.NCVATTR.@NCSUBID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.CMP1.@NCSUBID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_NCSolid_Prompt1
// 	});
// 	expandar_psd_Property = CxvPropertyDeclaration.Register("expandar_psd", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvExpanderProperty
// 	{
// 		CompleteDataPaths = { "@main.CC Nodes.NCPSD.@NCSUBID" },
// 		AccessibleDataPaths = { "@main.CC Nodes.PSD1.@NCSUBID" },
// 		DisabledPrompt = WpfFormsResources.MMMaterial_Input_NCSolid_Prompt2
// 	});
// 	expanderAttr_state_Property = CxvPropertyDeclaration.Register("expanderAttr_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.NCVATTR"
// 		}
// 	});
// 	mnbAttribute_var2_Property = CxvPropertyDeclaration.Register("mnbAttribute_var2", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID7"
// 	});
// 	mnbAttribute_var1_Property = CxvPropertyDeclaration.Register("mnbAttribute_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@NCSUBID.@SUBCATID6",
// 		SelectedItemBinding = "mnbAttribute_var2.Value",
// 		CreateNewPrompt = "Attribute ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Attribute_ID",
// 		CompletePaths = { "@main.CC Nodes.NCVATTR.@NCSUBID.@SUBCATID6" },
// 		EnteredPaths = { "@main.CC Nodes.ENTCOMP.@NCSUBID.@SUBCATID6" },
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	mnbComponent_var2_Property = CxvPropertyDeclaration.Register("mnbComponent_var2", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBCATID6"
// 	});
// 	mnbComponent_var1_Property = CxvPropertyDeclaration.Register("mnbComponent_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NEL.@NCSUBID",
// 		SelectedItemBinding = "mnbComponent_var2.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_MixedPha_ViewModel__Component_ID",
// 		CompletePaths = { "@main.CC Nodes.NCVATTR.@NCSUBID" },
// 		EnteredPaths = { "@main.CC Nodes.ENTSUBSTR.@NCSUBID" },
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdCompAttr_GridData_Property = CxvPropertyDeclaration.Register("grdCompAttr_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdCompAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.ELEM.@NCSUBID.@SUBCATID6.@SUBCATID7",
// 			UseChildId = true,
// 			Name = "ROWNUM3",
// 			ProxyRow = false
// 		}
// 	});
// 	txtPSDUnits_var1_Property = CxvPropertyDeclaration.Register("txtPSDUnits_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIMUNITS.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtPSDID_var1_Property = CxvPropertyDeclaration.Register("txtPSDID_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PSDID.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.INTERVAL.@NCSUBID",
// 			UseChildId = true,
// 			Name = "POINT2"
// 		}
// 	});
// 	cmdCreateWtFracCanExecuteProperty = CxvPropertyDeclaration.Register("cmdCreateWtFracCanExecute", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.PSD9.@NCSUBID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	cmdEdit_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEdit_CommandCanExecute", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.CC Nodes.NCPSD1.@NCSUBID",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// 	psdCBox_var1_Property = CxvPropertyDeclaration.Register("psdCBox_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.PSDID.@NCSUBID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	ogrSelMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ogrSelMethod_MultiMap", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrSelMethod_var1",
// 				DataPath = "@main.Input.WTFRAC_OPT.@NCSUBID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "User specified values",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "USER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "A distribution function",
// 				DisplayResourceKey = "",
// 				Value = "ogrSelMethod_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrSelMethod_var1",
// 						Value = "FUNCTION"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.NCPSD1.@NCSUBID"
// 		}
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD2.@NCSUBID"
// 		}
// 	});
// 	Type_MultiMap_Property = CxvPropertyDeclaration.Register("Type_MultiMap", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "TypeCBox_var1",
// 				DataPath = "@main.Input.TYPE.@NCSUBID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "GGS",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_GGS",
// 				Value = "Type_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "GGS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RRSB",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_RRSB",
// 				Value = "Type_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "RRSB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Normal",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Normal",
// 				Value = "Type_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "NORMAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Log Normal",
// 				DisplayResourceKey = "MMMaterial_Input_NCSolid_ViewModel__CxvMultiMapOption_Display_Log_Normal",
// 				Value = "Type_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "TypeCBox_var1",
// 						Value = "LOG-NORMAL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	GGSLbl_state_Property = CxvPropertyDeclaration.Register("GGSLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
// 		}
// 	});
// 	txtGGSN_var1_Property = CxvPropertyDeclaration.Register("txtGGSN_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GGS_N.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
// 		}
// 	});
// 	txtDiam_var1_Property = CxvPropertyDeclaration.Register("txtDiam_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DIAM.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD4.@NCSUBID"
// 		}
// 	});
// 	RRSBLbl_state_Property = CxvPropertyDeclaration.Register("RRSBLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
// 		}
// 	});
// 	txtRRSBN_var1_Property = CxvPropertyDeclaration.Register("txtRRSBN_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.RRSB_N.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
// 		}
// 	});
// 	txtD63_var1_Property = CxvPropertyDeclaration.Register("txtD63_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D63.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD5.@NCSUBID"
// 		}
// 	});
// 	StddevLbl_state_Property = CxvPropertyDeclaration.Register("StddevLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@NCSUBID"
// 		}
// 	});
// 	txtStddev_var1_Property = CxvPropertyDeclaration.Register("txtStddev_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.STDDEV.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD6.@NCSUBID"
// 		}
// 	});
// 	D50Lbl_state_Property = CxvPropertyDeclaration.Register("D50Lbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@NCSUBID"
// 		}
// 	});
// 	txtD50_var1_Property = CxvPropertyDeclaration.Register("txtD50_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.D50.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD8.@NCSUBID"
// 		}
// 	});
// 	GmdevLbl_state_Property = CxvPropertyDeclaration.Register("GmdevLbl_state", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@NCSUBID"
// 		}
// 	});
// 	txtGmdev_var1_Property = CxvPropertyDeclaration.Register("txtGmdev_var1", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GMDEV.@NCSUBID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD7.@NCSUBID"
// 		}
// 	});
// 	CompAttrUnits_Property = CxvPropertyDeclaration.Register("CompAttrUnits", typeof(MMMaterial_Input_NCSolid_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UOM.@NCSUBID.@SUBCATID6.@SUBCATID7"
// 	});
// }

// 0x060001a3 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Specif_ViewModel..ctor
// public MMMaterial_Input_Specif_ViewModel()
// {
// }

// 0x060001a4 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Specif_ViewModel()
// {
// 	cmdRefTemp_var1_Property = CxvPropertyDeclaration.Register("cmdRefTemp_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.REFT1.@SUBSTRID"
// 		}
// 	});
// 	mnbSubstream_target_Property = CxvPropertyDeclaration.Register("mnbSubstream_target", typeof(MMMaterial_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBSTRID"
// 	});
// 	mnbSubstream_spec3_Property = CxvPropertyDeclaration.Register("mnbSubstream_spec3", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC3"
// 	});
// 	mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NPHASE",
// 		SelectedItemBinding = "mnbSubstream_target.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
// 		CompletePaths = { "SPEC1", "SPEC2", "@main.CC Nodes.SPEC3" }
// 	});
// 	spcSpec1_Property = CxvPropertyDeclaration.Register("spcSpec1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Temperature",
// 				DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Temperature",
// 				DataPath = "@main.Input.TEMP.@SUBSTRID"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Pressure",
// 				DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Pressure",
// 				DataPath = "@main.Input.PRES.@SUBSTRID"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Vapor fraction",
// 				DisplayResourceKey = "MMMaterial_Input_Specif_ViewModel__CxvSpecOption_Display_Vapor_fraction",
// 				DataPath = "@main.Input.VFRAC.@SUBSTRID"
// 			}
// 		},
// 		Count = 2,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	spcSpec1_var1_Property = CxvPropertyDeclaration.Register("spcSpec1_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	spcSpec1_var2_Property = CxvPropertyDeclaration.Register("spcSpec1_var2", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	spcSpec1_var3_Property = CxvPropertyDeclaration.Register("spcSpec1_var3", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRAC.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuTotalFlow_var1_Property = CxvPropertyDeclaration.Register("lbtuTotalFlow_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTFLOW.@SUBSTRID",
// 		BasisPath = "@main.Input.FLOWBASE.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	cboSolvent_var1_Property = CxvPropertyDeclaration.Register("cboSolvent_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.SOLVENT.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOTAL.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	grdComposition_GridData_Property = CxvPropertyDeclaration.Register("grdComposition_GridData", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdComposition_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FLOW.@SUBSTRID",
// 			UseChildId = true,
// 			Name = "COMP"
// 		}
// 	});
// 	lbtuComposition_var1_Property = CxvPropertyDeclaration.Register("lbtuComposition_var1", typeof(MMMaterial_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@SUBSTRID",
// 		BasisPath = "@main.Input.BASIS.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060001c0 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Stratt_ViewModel..ctor
// public MMMaterial_Input_Stratt_ViewModel()
// {
// }

// 0x060001c1 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Stratt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Stratt_ViewModel()
// {
// 	NUMROW_Property = CxvPropertyDeclaration.Register("NUMROW", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVALS",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.EXINT"
// 		}
// 	});
// 	txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.INTERVAL.@y"
// 	});
// 	MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZ2.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
// 		}
// 	});
// 	lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream-Class.Subs-Attr.@id.Input.PARTICLESIZE.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Stream-Class.Subs-Attr.@id.CC Nodes.USER"
// 		}
// 	});
// 	txtIntervals_var1_Property = CxvPropertyDeclaration.Register("txtIntervals_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.INTERVALS"
// 	});
// 	lbtuSizeUnits_var1_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.PARTICLESIZE",
// 		ExtraDataPaths = { "@main0.Input.PARTICLESIZ2", "@main0.Input.LOWER", "@main0.Input.UPPER" },
// 		VariablePrompt = "Size units",
// 		VariablePromptResourceKey = "MMSetup_Stratt_Subatt_ViewModel__unit_prompt"
// 	});
// 	lbtuSizeUnits_var2_Property = CxvPropertyDeclaration.Register("lbtuSizeUnits_var2", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.PARTICLESIZE"
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main0.Input.TYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Equidistant",
// 				DisplayResourceKey = "MMSetup_Stratt_Subatt_ViewModel__CxvMultiMapOption_Diaplay_Equidistant",
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
// 	geoDiscretization_var1_Property = CxvPropertyDeclaration.Register("geoDiscretization_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.Q",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.ISGEO"
// 		}
// 	});
// 	spnIntervals_var1_Property = CxvPropertyDeclaration.Register("spnIntervals_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.INTERVALS",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.EXINT1"
// 		}
// 	});
// 	txtUpper_var_Property = CxvPropertyDeclaration.Register("txtUpper_var", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.UPPER",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.LIMIT"
// 		}
// 	});
// 	txtLower_var_Property = CxvPropertyDeclaration.Register("txtLower_var", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.LOWER",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.LIMIT"
// 		}
// 	});
// 	cmdCreateMesh_var1_Property = CxvPropertyDeclaration.Register("cmdCreateMesh_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.CMESH"
// 		}
// 	});
// 	PSDnext_Enable_Property = CxvPropertyDeclaration.Register("PSDnext_Enable", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Equal,
// 		DataPath = "@main0.CC Nodes.MN1",
// 		Value = 0
// 	});
// 	cmdUpdatePSD_var1_Property = CxvPropertyDeclaration.Register("cmdUpdatePSD_var1", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.MN1"
// 		}
// 	});
// 	grdAttribute_GridData_Property = CxvPropertyDeclaration.Register("grdAttribute_GridData", typeof(MMMaterial_Input_Stratt_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAttribute_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main0.Input.INTERVAL",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060001cb AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Substr_ViewModel..ctor
// public MMMaterial_Input_Substr_ViewModel()
// {
// }

// 0x060001cc AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Substr_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Input_Substr_ViewModel()
// {
// 	mnbSubstream_var2_Property = CxvPropertyDeclaration.Register("mnbSubstream_var2", typeof(MMMaterial_Input_Substr_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "SUBATTRID"
// 	});
// 	mnbSubstream_display_Property = CxvPropertyDeclaration.Register("mnbSubstream_display", typeof(MMMaterial_Input_Substr_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL",
// 		SelectedItemBinding = "mnbSubstream_var2.Value",
// 		CreateNewPrompt = "Substream name:",
// 		CreateNewPromptResourceKey = "MMMaterial_Input_Substr_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_name_",
// 		CompletePaths = { "PSD" }
// 	});
// 	fraSubstrAttr_state_Property = CxvPropertyDeclaration.Register("fraSubstrAttr_state", typeof(MMMaterial_Input_Substr_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBATTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtUnits_var1_Property = CxvPropertyDeclaration.Register("txtUnits_var1", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIMUNITS.@SUBATTRID"
// 	});
// 	txtAttrID_var1_Property = CxvPropertyDeclaration.Register("txtAttrID_var1", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PSDID.@SUBATTRID"
// 	});
// 	grdSubstrAttr_GridData_Property = CxvPropertyDeclaration.Register("grdSubstrAttr_GridData", typeof(MMMaterial_Input_Substr_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSubstrAttr_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.INTERVAL.@SUBATTRID",
// 			UseChildId = true,
// 			Name = "POINT"
// 		}
// 	});
// }

// 0x060001d4 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Reftemp_ViewModel..ctor
// public MMMaterial_Reftemp_ViewModel()
// {
// }

// 0x060001d5 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Reftemp_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Reftemp_ViewModel()
// {
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMaterial_Reftemp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VOL_TREF.@SUBSTRID"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMaterial_Reftemp_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CONC_TREF.@SUBSTRID",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.REFT2.@SUBSTRID"
// 		}
// 	});
// }

// 0x06000225 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Result_ViewModel()
// {
// 	mat1_Property = CxvPropertyDeclaration.Register("mat1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	petro2_Property = CxvPropertyDeclaration.Register("petro2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.AROMCRV"
// 	});
// 	petro3_Property = CxvPropertyDeclaration.Register("petro3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.BAS-NCRV"
// 	});
// 	petro4_Property = CxvPropertyDeclaration.Register("petro4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.CARBCRV"
// 	});
// 	petro5_Property = CxvPropertyDeclaration.Register("petro5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FLASHCRV"
// 	});
// 	petro6_Property = CxvPropertyDeclaration.Register("petro6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.FREEZCRV"
// 	});
// 	petro7_Property = CxvPropertyDeclaration.Register("petro7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.HYDROCRV"
// 	});
// 	petro8_Property = CxvPropertyDeclaration.Register("petro8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.IRONCRV"
// 	});
// 	petro9_Property = CxvPropertyDeclaration.Register("petro9", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KNOCKCRV"
// 	});
// 	petro10_Property = CxvPropertyDeclaration.Register("petro10", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.KVISCCRV"
// 	});
// 	petro11_Property = CxvPropertyDeclaration.Register("petro11", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.LUM-NCRV"
// 	});
// 	petro12_Property = CxvPropertyDeclaration.Register("petro12", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MERCCRV"
// 	});
// 	petro13_Property = CxvPropertyDeclaration.Register("petro13", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.METALCRV"
// 	});
// 	petro14_Property = CxvPropertyDeclaration.Register("petro14", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MOCNCRV"
// 	});
// 	petro15_Property = CxvPropertyDeclaration.Register("petro15", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NAPHCRV"
// 	});
// 	petro16_Property = CxvPropertyDeclaration.Register("petro16", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.NICKCRV"
// 	});
// 	petro17_Property = CxvPropertyDeclaration.Register("petro17", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OLEFCRV"
// 	});
// 	petro18_Property = CxvPropertyDeclaration.Register("petro18", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.OXYGCRV"
// 	});
// 	petro19_Property = CxvPropertyDeclaration.Register("petro19", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.PARACRV"
// 	});
// 	petro20_Property = CxvPropertyDeclaration.Register("petro20", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POURCRV"
// 	});
// 	petro21_Property = CxvPropertyDeclaration.Register("petro21", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.REFICRV"
// 	});
// 	petro22_Property = CxvPropertyDeclaration.Register("petro22", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ROCNCRV"
// 	});
// 	petro23_Property = CxvPropertyDeclaration.Register("petro23", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.RVPCRV"
// 	});
// 	petro24_Property = CxvPropertyDeclaration.Register("petro24", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SMOKCRV"
// 	});
// 	petro25_Property = CxvPropertyDeclaration.Register("petro25", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.SULFCRV"
// 	});
// 	petro26_Property = CxvPropertyDeclaration.Register("petro26", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TOT-NCRV"
// 	});
// 	petro27_Property = CxvPropertyDeclaration.Register("petro27", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VANACRV"
// 	});
// 	petro28_Property = CxvPropertyDeclaration.Register("petro28", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VISCCRV"
// 	});
// 	petro29_Property = CxvPropertyDeclaration.Register("petro29", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VLOCKCRV"
// 	});
// 	petro30_Property = CxvPropertyDeclaration.Register("petro30", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.WARMICRV"
// 	});
// 	volume1_Property = CxvPropertyDeclaration.Register("volume1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRV"
// 	});
// 	volume2_Property = CxvPropertyDeclaration.Register("volume2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRV"
// 	});
// 	volume3_Property = CxvPropertyDeclaration.Register("volume3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CRV"
// 	});
// 	volume4_Property = CxvPropertyDeclaration.Register("volume4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCRV"
// 	});
// 	volume5_Property = CxvPropertyDeclaration.Register("volume5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRV"
// 	});
// 	volume6_Property = CxvPropertyDeclaration.Register("volume6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRV"
// 	});
// 	volume7_Property = CxvPropertyDeclaration.Register("volume7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRV"
// 	});
// 	volume8_Property = CxvPropertyDeclaration.Register("volume8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRK"
// 	});
// 	weight1_Property = CxvPropertyDeclaration.Register("weight1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86CRVWT"
// 	});
// 	weight2_Property = CxvPropertyDeclaration.Register("weight2", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D1160CWT"
// 	});
// 	weight3_Property = CxvPropertyDeclaration.Register("weight3", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.VACCURWT"
// 	});
// 	weight4_Property = CxvPropertyDeclaration.Register("weight4", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.APICRVWT"
// 	});
// 	weight5_Property = CxvPropertyDeclaration.Register("weight5", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.GRVCRVWT"
// 	});
// 	weight6_Property = CxvPropertyDeclaration.Register("weight6", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MWCRVWT"
// 	});
// 	weight7_Property = CxvPropertyDeclaration.Register("weight7", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D86WTCRK"
// 	});
// 	weight8_Property = CxvPropertyDeclaration.Register("weight8", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.D2887CRV"
// 	});
// 	poly_Property = CxvPropertyDeclaration.Register("poly", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.POLCSDY"
// 	});
// 	weight9_Property = CxvPropertyDeclaration.Register("weight9", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.TBPCRVWT"
// 	});
// 	petro1_Property = CxvPropertyDeclaration.Register("petro1", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.ANILCRV"
// 	});
// 	petro31_Property = CxvPropertyDeclaration.Register("petro31", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.UOPKCRV"
// 	});
// 	str_petrocurveview_Property = CxvPropertyDeclaration.Register("str_petrocurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_petrocurveview"
// 	});
// 	str_weightcurveview_Property = CxvPropertyDeclaration.Register("str_weightcurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_weightcurveview"
// 	});
// 	str_volumecurveview_Property = CxvPropertyDeclaration.Register("str_volumecurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_volumecurveview"
// 	});
// 	str_polycurveview_Property = CxvPropertyDeclaration.Register("str_polycurveview", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "str_polycurveview"
// 	});
// 	main_result_Property = CxvPropertyDeclaration.Register("main_result", typeof(MMMaterial_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "main_result"
// 	});
// 	solid_Property = CxvPropertyDeclaration.Register("solid", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@OutputNode.MAXIMUM"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@mat1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@volume1", "@volume2", "@volume3", "@volume4", "@volume5", "@volume6", "@volume7", "@volume8" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@weight1", "@weight2", "@weight3", "@weight4", "@weight5", "@weight6", "@weight7", "@weight8", "@weight9" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = 
// 		{
// 			"@petro1", "@petro10", "@petro11", "@petro12", "@petro13", "@petro14", "@petro15", "@petro16", "@petro17", "@petro18",
// 			"@petro19", "@petro2", "@petro20", "@petro21", "@petro22", "@petro23", "@petro24", "@petro25", "@petro26", "@petro27",
// 			"@petro28", "@petro29", "@petro3", "@petro30", "@petro4", "@petro5", "@petro6", "@petro7", "@petro8", "@petro9",
// 			"@petro31"
// 		}
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@poly" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMaterial_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@solid" }
// 	});
// 	APUnitsNode_Property = CxvPropertyDeclaration.Register("APUnitsNode", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Units"
// 	});
// 	OutputNode_Property = CxvPropertyDeclaration.Register("OutputNode", typeof(MMMaterial_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main_result.Results Summary.Stream-Sum.Dist-Curve.Output"
// 	});
// }

// 0x06000237 AspenTech.AspenPlus.MMForms.Streams.Material.StreamSummaryViewModel..ctor
// public StreamSummaryViewModel()
// {
// }

// 0x06000245 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel..ctor
// public MMMaterial_Result_Materi_ViewModel()
// {
// }

// 0x06000246 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMaterial_Result_Materi_ViewModel()
// {
// 	cbtStreamTable_CommandCanExecuteProperty = CxvPropertyDeclaration.Register("cbtStreamTable_CommandCanExecute", typeof(MMMaterial_Result_Materi_ViewModel), new CxvLogicalProperty
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
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMMaterial_Result_Materi_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
// 				DisplayResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMMaterial_Result_Materi_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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
// 	cboFormat_var1_Property = CxvPropertyDeclaration.Register("cboFormat_var1", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Stream Results.TFF File",
// 		Sorted = true
// 	});
// 	grdStreams_GridData_Property = CxvPropertyDeclaration.Register("grdStreams_GridData", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table",
// 			UseChildId = false,
// 			Name = "row"
// 		}
// 	});
// 	grdStreams_GridHeader_Property = CxvPropertyDeclaration.Register("grdStreams_GridHeader", typeof(MMMaterial_Result_Materi_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdStreams_HeaderTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = false,
// 			Name = "x"
// 		}
// 	});
// }

// 0x06000256 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_ViewModel..ctor
// public MMHeat_Input_ViewModel()
// {
// }

// 0x06000257 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Input_ViewModel()
// {
// 	NPOINT_Property = CxvPropertyDeclaration.Register("NPOINT", typeof(MMHeat_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "NPOINT"
// 	});
// 	SPECCOMP_Property = CxvPropertyDeclaration.Register("SPECCOMP", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MN1"
// 	});
// 	LOADL_Property = CxvPropertyDeclaration.Register("LOADL", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.LOADL"
// 	});
// 	ENTNPOINT_Property = CxvPropertyDeclaration.Register("ENTNPOINT", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTNPOINT"
// 	});
// 	ENTVEC_Property = CxvPropertyDeclaration.Register("ENTVEC", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTVEC"
// 	});
// 	LOAD_Property = CxvPropertyDeclaration.Register("LOAD", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.LOAD"
// 	});
// 	ENTOPT_Property = CxvPropertyDeclaration.Register("ENTOPT", typeof(MMHeat_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTOPT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@SPECCOMP" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@LOAD" },
// 		AccessibleDataPaths = { "@LOADL" },
// 		EnteredDataPaths = { "@ENTNPOINT", "@ENTVEC" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMHeat_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ENTOPT" }
// 	});
// }

// 0x0600025f AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Eoopti_ViewModel..ctor
// public MMHeat_Input_Eoopti_ViewModel()
// {
// }

// 0x06000260 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Eoopti_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Input_Eoopti_ViewModel()
// {
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Input.SOLVE_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with information messages",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_info",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-PERT-IN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with warning messages",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warn",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-PERT-WA"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure stop with error messages",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "OPEN-NOPERT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Closed; use Perturbation layer around closed model",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_close",
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "PERTURBATION"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Neither; ignore block during EO solution",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
// 				Value = "MMComboBox2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "DO-NOT-CREAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Input.DERIV_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Analytical",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Analytical",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "ANALYTICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Numerical",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Numerical",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "NUMERICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Update (Analytical)",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "UPDATE-ANALY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Update (Numerical)",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "UPDATE-NUMER"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox9_var1",
// 				DataPath = "@main.Input.PASS_THROUGH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox9_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox9_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMHeat_Input_Eoopti_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox11_var1",
// 				DataPath = "@main.Input.ALWAYS_INST"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_Yes_1",
// 				Value = "MMComboBox11_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox11_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMHeat_Input_Eoopti_ViewModel__CxvMultiMapOption_Display_No_1",
// 				Value = "MMComboBox11_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox11_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000268 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Load_ViewModel..ctor
// public MMHeat_Input_Load_ViewModel()
// {
// }

// 0x06000269 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Load_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Input_Load_ViewModel()
// {
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TVEC"
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.QVEC"
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMHeat_Input_Load_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.TVEC",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.POINTS"
// 		}
// 	});
// 	spnNPoints_NPOINT_Property = CxvPropertyDeclaration.Register("spnNPoints_NPOINT", typeof(MMHeat_Input_Load_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NPOINT"
// 	});
// }

// 0x06000272 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Specif_ViewModel..ctor
// public MMHeat_Input_Specif_ViewModel()
// {
// }

// 0x06000273 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Input_Specif_ViewModel()
// {
// 	lbtuHeat_var1_Property = CxvPropertyDeclaration.Register("lbtuHeat_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DUTY"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEND"
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMHeat_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP"
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMHeat_Input_Specif_ViewModel), new CxvMultiMapProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "enabletype",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = "1"
// 		},
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Input.H_SCLASS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Heat",
// 				DisplayResourceKey = "MMHeat_Input_Specif_ViewModel__CxvMultiMapOption_Display_Heat",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "HEAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Load",
// 				DisplayResourceKey = "MMHeat_Input_Specif_ViewModel__CxvMultiMapOption_Display_Load",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "LOAD"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000279 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_ViewModel..ctor
// public MMHeat_Result_ViewModel()
// {
// }

// 0x0600027a AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Result_ViewModel()
// {
// 	heat1_Property = CxvPropertyDeclaration.Register("heat1", typeof(MMHeat_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHeat_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@heat1" }
// 	});
// }

// 0x06000291 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel..ctor
// using System.Windows;
//
// public MMHeat_Result_Heat_ViewModel()
// {
// 	_RegularVisibility = Visibility.Collapsed;
// 	_BatchVisibility = Visibility.Collapsed;
// 	base..ctor();
// }

// 0x06000292 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHeat_Result_Heat_ViewModel()
// {
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#3"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#5"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMHeat_Result_Heat_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.#4"
// 	});
// 	cboDisplay_MultiMap_Property = CxvPropertyDeclaration.Register("cboDisplay_MultiMap", typeof(MMHeat_Result_Heat_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Display_All_streams",
// 				Value = "cboDisplay_MultiMapOption_1",
// 				Prompt = "Display all streams",
// 				PromptResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Prompt_Display_all_streams",
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
// 				DisplayResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Display_Streams",
// 				Value = "cboDisplay_MultiMapOption_2",
// 				Prompt = "Enter desired streams",
// 				PromptResourceKey = "MMHeat_Result_Heat_ViewModel__CxvMultiMapOption_Prompt_Enter_desired_streams",
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
// 	grdHeat_GridData_Property = CxvPropertyDeclaration.Register("grdHeat_GridData", typeof(MMHeat_Result_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// 	grdHeat_GridData2_Property = CxvPropertyDeclaration.Register("grdHeat_GridData2", typeof(MMHeat_Result_Heat_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdHeat_GridData2_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Stream Results.Table.#0",
// 			UseChildId = false,
// 			Name = "col"
// 		}
// 	});
// }

// 0x06000298 AspenTech.AspenPlus.MMForms.Streams.Control.MMControl_Input_ViewModel..ctor
// public MMControl_Input_ViewModel()
// {
// }

// 0x06000299 AspenTech.AspenPlus.MMForms.Streams.Control.MMControl_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMControl_Input_ViewModel()
// {
// 	SPEC_Property = CxvPropertyDeclaration.Register("SPEC", typeof(MMControl_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMControl_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@SPEC" }
// 	});
// }

// 0x060002a4 AspenTech.AspenPlus.MMForms.Streams.Control.MMControl_Input_Spec_ViewModel..ctor
// public MMControl_Input_Spec_ViewModel()
// {
// }

// 0x060002a5 AspenTech.AspenPlus.MMForms.Streams.Control.MMControl_Input_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMControl_Input_Spec_ViewModel()
// {
// 	PVBlock_Property = CxvPropertyDeclaration.Register("PVBlock", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FVN_BLOCK"
// 	});
// 	PVStream_Property = CxvPropertyDeclaration.Register("PVStream", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FVN_STREAM"
// 	});
// 	PVVariable_Property = CxvPropertyDeclaration.Register("PVVariable", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FVN_VARIABLE"
// 	});
// 	OPBlock_Property = CxvPropertyDeclaration.Register("OPBlock", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VARYBLOCK"
// 	});
// 	OPStream_Property = CxvPropertyDeclaration.Register("OPStream", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VARYSTREAM"
// 	});
// 	OPVariable_Property = CxvPropertyDeclaration.Register("OPVariable", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VARYVARIABLE"
// 	});
// 	lbtuSetPoint_Property = CxvPropertyDeclaration.Register("lbtuSetPoint", typeof(MMControl_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SETPOINT"
// 	});
// }

// 0x060002ae AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel+grdWork_GridData_ItemTemplate..ctor
// public grdWork_GridData_ItemTemplate()
// {
// }

// 0x060002af AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel+grdWork_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col",
// 		ExposeAs = CxvVariableTypeCode.Integer
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col",
// 		ExposeAs = CxvVariableTypeCode.Real
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col"
// 	});
// }

// 0x060002b7 AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel+grdWork_GridData2_ItemTemplate..ctor
// public grdWork_GridData2_ItemTemplate()
// {
// }

// 0x060002b8 AspenTech.AspenPlus.MMForms.Streams.Work.MMWork_Result_Work_ViewModel+grdWork_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col"
// 	});
// }

// 0x060002be AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel+grdWork_GridData_ItemTemplate..ctor
// public grdWork_GridData_ItemTemplate()
// {
// }

// 0x060002bf AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel+grdWork_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col",
// 		ExposeAs = CxvVariableTypeCode.Real
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col"
// 	});
// }

// 0x060002c7 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel+grdWork_GridData2_ItemTemplate..ctor
// public grdWork_GridData2_ItemTemplate()
// {
// }

// 0x060002c8 AspenTech.AspenPlus.MMForms.Streams.Power.MMPower_Result_Power_ViewModel+grdWork_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdWork_GridData2_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col"
// 	});
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#7.@col"
// 	});
// 	cboSubstream_var1_Property = CxvPropertyDeclaration.Register("cboSubstream_var1", typeof(grdWork_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col"
// 	});
// }

// 0x060002cb AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Compat_ViewModel+grdCompAttr_GridData_ItemTemplate..ctor
// public grdCompAttr_GridData_ItemTemplate()
// {
// }

// 0x060002cc AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Compat_ViewModel+grdCompAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdCompAttr_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ELEM.@SUBCATID1.@SUBCATID2.@SUBCATID3.@ROWNUM"
// 	});
// 	txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LAB.@SUBCATID1.@SUBCATID2.@SUBCATID3.@ROWNUM"
// 	});
// }

// 0x060002cf AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdComposition_GridData_ItemTemplate..ctor
// public grdComposition_GridData_ItemTemplate()
// {
// }

// 0x060002d0 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdComposition_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdComposition_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@CONVSUBID.@COMPCONV",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FLOW.@CONVSUBID.@COMPCONV",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002d3 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdCompAttr_GridData_ItemTemplate..ctor
// public grdCompAttr_GridData_ItemTemplate()
// {
// }

// 0x060002d4 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdCompAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdCompAttr_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ELEM.@CONVSUBID.@SUBCATID4.@SUBCATID5.@ROWNUM2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LAB.@CONVSUBID.@SUBCATID4.@SUBCATID5.@ROWNUM2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002da AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdSubstrAttr_GridData_ItemTemplate..ctor
// public grdSubstrAttr_GridData_ItemTemplate()
// {
// }

// 0x060002db AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_ConvSol_ViewModel+grdSubstrAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSubstrAttr_GridData_ItemTemplate()
// {
// 	txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SUBSATT.@CONVSUBID.@POINT",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD3.@CONVSUBID"
// 		}
// 	});
// 	txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CUM_SUBSATT.@CONVSUBID.@POINT",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD3.@CONVSUBID"
// 		},
// 		IsReadOnly = true
// 	});
// 	txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@CONVSUBID.@POINT",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LOWER.@CONVSUBID.@POINT",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL.@CONVSUBID.@POINT",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CONVSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002de AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdComposition_GridData_ItemTemplate..ctor
// public grdComposition_GridData_ItemTemplate()
// {
// }

// 0x060002df AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdComposition_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdComposition_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@SubID.@COMPMIXED"
// 	});
// 	txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FLOW.@SubID.@COMPMIXED"
// 	});
// }

// 0x060002e2 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdCompAttr_GridData_ItemTemplate..ctor
// public grdCompAttr_GridData_ItemTemplate()
// {
// }

// 0x060002e3 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdCompAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdCompAttr_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ELEM.@SubID.@SUBCATID2.@SUBCATID3.@ROWNUM"
// 	});
// 	txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LAB.@SubID.@SUBCATID2.@SUBCATID3.@ROWNUM"
// 	});
// }

// 0x060002e9 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdSubstrAttr_GridData_ItemTemplate..ctor
// public grdSubstrAttr_GridData_ItemTemplate()
// {
// }

// 0x060002ea AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_MixedPha_ViewModel+grdSubstrAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSubstrAttr_GridData_ItemTemplate()
// {
// 	txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC Nodes.PSD3.@SubID",
// 						Value = 1,
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.SUBSATT.@SubID.@POINT"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC Nodes.PSD3.@SubID",
// 						Value = 0,
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.SUBSATT.@SubID.@POINT",
// 					IsReadOnly = true
// 				}
// 			}
// 		}
// 	});
// 	txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CUM_SUBSATT.@SubID.@POINT",
// 		IsReadOnly = true
// 	});
// 	txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@SubID.@POINT"
// 	});
// 	txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LOWER.@SubID.@POINT"
// 	});
// 	txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL.@SubID.@POINT"
// 	});
// }

// 0x060002ed AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdComposition_GridData_ItemTemplate..ctor
// public grdComposition_GridData_ItemTemplate()
// {
// }

// 0x060002ee AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdComposition_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdComposition_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@NCSUBID.@COMPCONV",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FLOW.@NCSUBID.@COMPCONV",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002f1 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdCompAttr_GridData_ItemTemplate..ctor
// public grdCompAttr_GridData_ItemTemplate()
// {
// }

// 0x060002f2 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdCompAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdCompAttr_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ELEM.@NCSUBID.@SUBCATID6.@SUBCATID7.@ROWNUM3",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtElement_var1_Property = CxvPropertyDeclaration.Register("txtElement_var1", typeof(grdCompAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LAB.@NCSUBID.@SUBCATID6.@SUBCATID7.@ROWNUM3",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002f8 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdSubstrAttr_GridData_ItemTemplate..ctor
// public grdSubstrAttr_GridData_ItemTemplate()
// {
// }

// 0x060002f9 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_NCSolid_ViewModel+grdSubstrAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSubstrAttr_GridData_ItemTemplate()
// {
// 	txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SUBSATT.@NCSUBID.@POINT2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD3.@NCSUBID"
// 		}
// 	});
// 	txtCumFraction_var1_Property = CxvPropertyDeclaration.Register("txtCumFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CUM_SUBSATT.@NCSUBID.@POINT2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PSD3.@NCSUBID"
// 		}
// 	});
// 	txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@NCSUBID.@POINT2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LOWER.@NCSUBID.@POINT2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL.@NCSUBID.@POINT2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "NCSUBID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x060002fc AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Specif_ViewModel+grdComposition_GridData_ItemTemplate..ctor
// public grdComposition_GridData_ItemTemplate()
// {
// }

// 0x060002fd AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Specif_ViewModel+grdComposition_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdComposition_GridData_ItemTemplate()
// {
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@SUBSTRID.@COMP",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	txtXomponent_var1_Property = CxvPropertyDeclaration.Register("txtXomponent_var1", typeof(grdComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FLOW.@SUBSTRID.@COMP",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "SUBSTRID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// }

// 0x06000301 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Stratt_ViewModel+grdAttribute_GridData_ItemTemplate..ctor
// public grdAttribute_GridData_ItemTemplate()
// {
// }

// 0x06000302 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Stratt_ViewModel+grdAttribute_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAttribute_GridData_ItemTemplate()
// {
// 	txtInt_var1_Property = CxvPropertyDeclaration.Register("txtInt_var1", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.INTERVAL.@y"
// 	});
// 	MMLBUText1_upper_Property = CxvPropertyDeclaration.Register("MMLBUText1_upper", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.PARTICLESIZ2.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.USER"
// 		}
// 	});
// 	lbtuLower_Lower_Property = CxvPropertyDeclaration.Register("lbtuLower_Lower", typeof(grdAttribute_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main0.Input.PARTICLESIZE.@y",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main0.CC Nodes.USER"
// 		}
// 	});
// }

// 0x06000307 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Substr_ViewModel+grdSubstrAttr_GridData_ItemTemplate..ctor
// public grdSubstrAttr_GridData_ItemTemplate()
// {
// }

// 0x06000308 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Input_Substr_ViewModel+grdSubstrAttr_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSubstrAttr_GridData_ItemTemplate()
// {
// 	txtFraction_var1_Property = CxvPropertyDeclaration.Register("txtFraction_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SUBSATT.@SUBATTRID.@POINT"
// 	});
// 	txtUpperlimit_var1_Property = CxvPropertyDeclaration.Register("txtUpperlimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@SUBATTRID.@POINT"
// 	});
// 	txtLowerLimit_var1_Property = CxvPropertyDeclaration.Register("txtLowerLimit_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LOWER.@SUBATTRID.@POINT"
// 	});
// 	txtInterval_var1_Property = CxvPropertyDeclaration.Register("txtInterval_var1", typeof(grdSubstrAttr_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INTERVAL.@SUBATTRID.@POINT"
// 	});
// }

// 0x0600030b AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_GridData_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate()
// {
// }

// 0x0600030c AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_GridData_ItemTemplate()
// {
// 	txtTableLab_var1_Property = CxvPropertyDeclaration.Register("txtTableLab_var1", typeof(grdStreams_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Stream Results.Table.@row"
// 	});
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
// }

// 0x0600030f AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdStreams_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000310 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_GridData_ItemTemplate_inner_ItemTemplate..cctor
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

// 0x06000313 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_HeaderTemplate..ctor
// public grdStreams_HeaderTemplate()
// {
// }

// 0x06000314 AspenTech.AspenPlus.MMForms.Streams.Material.MMMaterial_Result_Materi_ViewModel+grdStreams_HeaderTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdStreams_HeaderTemplate()
// {
// 	var1_Property = CxvPropertyDeclaration.Register("var1", typeof(grdStreams_HeaderTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@x"
// 	});
// }

// 0x06000318 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Load_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000319 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Input_Load_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.TVEC.@y"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TVEC.@y"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.QVEC.@y"
// 	});
// }

// 0x0600031f AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel+grdHeat_GridData_ItemTemplate..ctor
// public grdHeat_GridData_ItemTemplate()
// {
// }

// 0x06000320 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel+grdHeat_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col",
// 		IsReadOnly = false
// 	});
// }

// 0x06000329 AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..ctor
// public grdHeat_GridData2_ItemTemplate()
// {
// }

// 0x0600032a AspenTech.AspenPlus.MMForms.Streams.Heat.MMHeat_Result_Heat_ViewModel+grdHeat_GridData2_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdHeat_GridData2_ItemTemplate()
// {
// 	txtTableVar_var1_Property = CxvPropertyDeclaration.Register("txtTableVar_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#3.@col"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#5.@col"
// 	});
// 	MMTextBox4_var1_Property = CxvPropertyDeclaration.Register("MMTextBox4_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#4.@col"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#6.@col"
// 	});
// 	MMTextBox5_var1_Property = CxvPropertyDeclaration.Register("MMTextBox5_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#7.@col"
// 	});
// 	MMTextBox6_var1_Property = CxvPropertyDeclaration.Register("MMTextBox6_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Stream Results.Table.#8.@col"
// 	});
// 	cboSubstr_var1_Property = CxvPropertyDeclaration.Register("cboSubstr_var1", typeof(grdHeat_GridData2_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Stream Results.Table.#0.@col",
// 		IsReadOnly = false
// 	});
// }
