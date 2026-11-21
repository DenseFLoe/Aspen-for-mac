using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Input;
using System.Windows.Markup;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Apr_Setup")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Apr_Setup")]
[assembly: AssemblyCopyright("Copyright © Microsoft 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/apropsetup", "AspenTech.AspenPlus.MMForms.APropSetup")]
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
namespace AspenTech.AspenPlus.MMForms.APropSetup
{
	public class MMAPr_Setup_Report_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sreportno_Property = CxvPropertyDeclaration.Register("sreportno", typeof(MMAPr_Setup_Report_ViewModel), new CxvParameterProperty
		{
			Parameter = "sreportno"
		});

		public static readonly CxvPropertyDeclaration entglob_Property = CxvPropertyDeclaration.Register("entglob", typeof(MMAPr_Setup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Report.CC Nodes.ENTGLOB"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMAPr_Setup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entada_Property = CxvPropertyDeclaration.Register("entada", typeof(MMAPr_Setup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.ADA-Report.CC Nodes.ENTADA"
		});

		public static readonly CxvPropertyDeclaration prop_Property = CxvPropertyDeclaration.Register("prop", typeof(MMAPr_Setup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.PROP"
		});

		public static readonly CxvPropertyDeclaration ada_Property = CxvPropertyDeclaration.Register("ada", typeof(MMAPr_Setup_Report_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ADA"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Setup_Report_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entglob" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Setup_Report_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@prop" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Setup_Report_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ada" },
			EnteredDataPaths = { "@entada" }
		});

		public object sreportno => GetValue(sreportno_Property);

		public object entglob => GetValue(entglob_Property);

		public object entprop => GetValue(entprop_Property);

		public object entada => GetValue(entada_Property);

		public object prop => GetValue(prop_Property);

		public object ada => GetValue(ada_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Report")]
	public class MMAPr_Setup_Report : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		private bool _contentLoaded;

		public MMAPr_Setup_Report()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Report_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_report.xaml", UriKind.Relative);
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Report_Default_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration chkReport_var1_Property = CxvPropertyDeclaration.Register("chkReport_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.REPORT",
			TrueValue = "REPORT",
			FalseValue = "NOREPORT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMFrame3_state_Property = CxvPropertyDeclaration.Register("MMFrame3_state", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
			}
		});

		public static readonly CxvPropertyDeclaration spnLine_var1_Property = CxvPropertyDeclaration.Register("spnLine_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.LINES"
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.GLOB"
			}
		});

		public static readonly CxvPropertyDeclaration chkProp_var1_Property = CxvPropertyDeclaration.Register("chkProp_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.PROPERTIES",
			TrueValue = "PROPERTIES",
			FalseValue = "NOPROPERTIES",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkAda_var1_Property = CxvPropertyDeclaration.Register("chkAda_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.ADA",
			TrueValue = "ADA",
			FalseValue = "NOADA",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkInsert_var1_Property = CxvPropertyDeclaration.Register("chkInsert_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Report.Input.INSERT",
			TrueValue = "INSERT",
			FalseValue = "NOINSERT",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkInput_var1_Property = CxvPropertyDeclaration.Register("chkInput_var1", typeof(MMAPr_Setup_Report_Default_ViewModel), new CxvBooleanProperty
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

		public object chkProp_var1 => GetValue(chkProp_var1_Property);

		public object chkAda_var1 => GetValue(chkAda_var1_Property);

		public object chkInsert_var1 => GetValue(chkInsert_var1_Property);

		public object chkInput_var1 => GetValue(chkInput_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Report_Default")]
	public class MMAPr_Setup_Report_Default : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMCheckBox chkReport;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox chkInput;

		internal MMCheckBox chkProp;

		internal MMCheckBox chkAda;

		internal MMCheckBox chkInsert;

		internal MMGroupBox MMFrame3;

		internal MMLabel lbtuLines_label;

		internal MMSpinBox spnLine;

		private bool _contentLoaded;

		public MMAPr_Setup_Report_Default()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Report_Default_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_report_default.xaml", UriKind.Relative);
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
				chkAda = (MMCheckBox)target;
				break;
			case 7:
				chkInsert = (MMCheckBox)target;
				break;
			case 8:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 9:
				lbtuLines_label = (MMLabel)target;
				break;
			case 10:
				spnLine = (MMSpinBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Report_Proper_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
			}
		});

		public static readonly CxvPropertyDeclaration chkNeu_var1_Property = CxvPropertyDeclaration.Register("chkNeu_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.NEUTRAL",
			TrueValue = "NEUTRAL",
			FalseValue = "NONEUTRAL",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkDfms_var1_Property = CxvPropertyDeclaration.Register("chkDfms_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.DFMS",
			TrueValue = "DFMS",
			FalseValue = "NODFMS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkProject_var1_Property = CxvPropertyDeclaration.Register("chkProject_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PROJECT",
			TrueValue = "PROJECT",
			FalseValue = "NOPROJECT",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkPropData_var1_Property = CxvPropertyDeclaration.Register("chkPropData_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PROP_DATA",
			TrueValue = "PROP-DATA",
			FalseValue = "NOPROP-DATA",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.ReportOptions.Report.CC Nodes.PROP"
			}
		});

		public static readonly CxvPropertyDeclaration chkPces_var1_Property = CxvPropertyDeclaration.Register("chkPces_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PCES",
			TrueValue = "PCES",
			FalseValue = "NOPCES",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkParplus_var1_Property = CxvPropertyDeclaration.Register("chkParplus_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PARPLUS",
			TrueValue = "PARAM-PLUS",
			FalseValue = "NOPARAM-PLUS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkParams_var1_Property = CxvPropertyDeclaration.Register("chkParams_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.PARAMS",
			TrueValue = "PARAMS",
			FalseValue = "NOPARAMS",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration chkComps_var1_Property = CxvPropertyDeclaration.Register("chkComps_var1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.ReportOptions.Property-Report.Input.COMPS",
			TrueValue = "COMPS",
			FalseValue = "NOCOMPS",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration Simulation1_Property = CxvPropertyDeclaration.Register("Simulation1", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel1"
		});

		public static readonly CxvPropertyDeclaration Simulation2_Property = CxvPropertyDeclaration.Register("Simulation2", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel2"
		});

		public static readonly CxvPropertyDeclaration Simulation3_Property = CxvPropertyDeclaration.Register("Simulation3", typeof(MMAPr_Setup_Report_Proper_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel3"
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

		public object Simulation1 => GetValue(Simulation1_Property);

		public object Simulation2 => GetValue(Simulation2_Property);

		public object Simulation3 => GetValue(Simulation3_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("SimulationLabel1", Resources.MMAPr_Setup_Report_Proper_SimulationLabel1_AProp);
					ResolveUpdateParameter("SimulationLabel2", Resources.MMAPr_Setup_Report_Proper_SimulationLabel2_AProp);
					ResolveUpdateParameter("SimulationLabel3", Resources.MMAPr_Setup_Report_Proper_SimulationLabel3_AProp);
				}
				else
				{
					ResolveUpdateParameter("SimulationLabel1", Resources.MMAPr_Setup_Report_Proper_SimulationLabel1_APlus);
					ResolveUpdateParameter("SimulationLabel2", Resources.MMAPr_Setup_Report_Proper_SimulationLabel2_APlus);
					ResolveUpdateParameter("SimulationLabel3", Resources.MMAPr_Setup_Report_Proper_SimulationLabel3_APlus);
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Report_Proper")]
	public class MMAPr_Setup_Report_Proper : MMTabPage, IComponentConnector
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

		public MMAPr_Setup_Report_Proper()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Report_Proper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_report_proper.xaml", UriKind.Relative);
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
	public class MMAPr_Setup_Setup_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accoun_Property = CxvPropertyDeclaration.Register("accoun", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.CC Nodes.MAIN1"
		});

		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.GLMAIN"
		});

		public static readonly CxvPropertyDeclaration entglb_Property = CxvPropertyDeclaration.Register("entglb", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Global.CC Nodes.ENTGLOBAL"
		});

		public static readonly CxvPropertyDeclaration entacc_Property = CxvPropertyDeclaration.Register("entacc", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Account-Info.CC Nodes.ENTACCOUN"
		});

		public static readonly CxvPropertyDeclaration entstr_Property = CxvPropertyDeclaration.Register("entstr", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ENTSTREAM"
		});

		public static readonly CxvPropertyDeclaration entdg_Property = CxvPropertyDeclaration.Register("entdg", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration entdes_Property = CxvPropertyDeclaration.Register("entdes", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Description.CC Nodes.ENTDESC"
		});

		public static readonly CxvPropertyDeclaration enetit_Property = CxvPropertyDeclaration.Register("enetit", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.CC Nodes.ENTTITLE"
		});

		public static readonly CxvPropertyDeclaration entphs_Property = CxvPropertyDeclaration.Register("entphs", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTPHASE"
		});

		public static readonly CxvPropertyDeclaration visited_Property = CxvPropertyDeclaration.Register("visited", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.VISITED"
		});

		public static readonly CxvPropertyDeclaration GLOBL_Property = CxvPropertyDeclaration.Register("GLOBL", typeof(MMAPr_Setup_Setup_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.GLOBL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Setup_Setup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global", "@GLOBL" },
			EnteredDataPaths = { "@enetit", "@entglb", "@entphs" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Setup_Setup_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdes" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Setup_Setup_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@accoun" },
			EnteredDataPaths = { "@entacc" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAPr_Setup_Setup_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdg" }
		});

		private bool _rentry;

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

		public object GLOBL => GetValue(GLOBL_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		protected override void OnUpdateData()
		{
			if (!_rentry)
			{
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
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
				ResolveUpdateParameter("extraComments_path", "Main.Comments");
				ResolveUpdateParameter("extraDescription_path", "Main.Input.DESCRIPTION");
			}
		}
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Setup")]
	public class MMAPr_Setup_Setup : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabSetup;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMAPr_Setup_Setup()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_setup.xaml", UriKind.Relative);
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
	public class MMAPr_Setup_Setup_Diagno_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdHistoryOptions_Command;

		public static readonly CxvPropertyDeclaration dsldPhysical_var1_Property = CxvPropertyDeclaration.Register("dsldPhysical_var1", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldPhysical_var2_Property = CxvPropertyDeclaration.Register("dsldPhysical_var2", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldSimulation_var1_Property = CxvPropertyDeclaration.Register("dsldSimulation_var1", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldSimulation_var2_Property = CxvPropertyDeclaration.Register("dsldSimulation_var2", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldInputTrans_var1_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var1", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.T_SYS_LEVEL"
		});

		public static readonly CxvPropertyDeclaration dsldInputTrans_var2_Property = CxvPropertyDeclaration.Register("dsldInputTrans_var2", typeof(MMAPr_Setup_Setup_Diagno_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SYS_LEVEL"
		});

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

		public object dsldPhysical_var1 => GetValue(dsldPhysical_var1_Property);

		public object dsldPhysical_var2 => GetValue(dsldPhysical_var2_Property);

		public object dsldSimulation_var1 => GetValue(dsldSimulation_var1_Property);

		public object dsldSimulation_var2 => GetValue(dsldSimulation_var2_Property);

		public object dsldInputTrans_var1 => GetValue(dsldInputTrans_var1_Property);

		public object dsldInputTrans_var2 => GetValue(dsldInputTrans_var2_Property);

		private void cmdHistoryOptions_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMAPr_Setup.MMAPr_Setup_Setup_Histor",
				LegacyFlags = 0,
				HelpId = 48,
				HelpFile = "APR-Setup.CHM",
				ShowPrompts = true,
				ShortName = Resources.MMAPr_Setup_Setup_Diagno_HistoryOptions
			});
		}
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Setup_Diagno")]
	public class MMAPr_Setup_Setup_Diagno : MMTabPage, IComponentConnector
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

		internal MMCmdButton cmdHistoryOptions;

		internal MMLabel lblDown0;

		internal MMLabel lblDown4;

		internal MMLabel lblDown10;

		private bool _contentLoaded;

		public MMAPr_Setup_Setup_Diagno()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Setup_Diagno_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_setup_diagno.xaml", UriKind.Relative);
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
				cmdHistoryOptions = (MMCmdButton)target;
				break;
			case 17:
				lblDown0 = (MMLabel)target;
				break;
			case 18:
				lblDown4 = (MMLabel)target;
				break;
			case 19:
				lblDown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Setup_Global_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMAPr_Setup_Setup_Global_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox2_MultiMapOption_1",
					Prompt = "Perform calculations to handle free water as a 2nd liquid phase in water-hydrocarbon or other water organic systems.",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox2_MultiMapOption_2",
					Prompt = "Perform calculations to handle free water as a 2nd liquid phase in water-hydrocarbon or other water organic systems.",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Dirty_water",
					Value = "MMComboBox2_MultiMapOption_3",
					Prompt = "Perform calculations to handle free water as a 2nd liquid phase in water-hydrocarbon or other water organic systems.",
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

		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMAPr_Setup_Setup_Global_ViewModel), new CxvMultiMapProperty
		{
			Prompt = "Valid phases to be considered in calculations. If left blank, the default is Vapor-Liquid.",
			PromptResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapProperty_Prompt_Valid_phases_to_be_considered_in_calculations_",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_conside",
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
					DisplayResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMAPr_Setup_Setup_Global_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__",
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

		public static readonly CxvPropertyDeclaration cboInputData_var1_Property = CxvPropertyDeclaration.Register("cboInputData_var1", typeof(MMAPr_Setup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Global.Input.INSET",
			AllowNew = false
		});

		public static readonly CxvPropertyDeclaration lbtuTitle_var1_Property = CxvPropertyDeclaration.Register("lbtuTitle_var1", typeof(MMAPr_Setup_Setup_Global_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Main.Input.TITLE"
		});

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object cboInputData_var1 => GetValue(cboInputData_var1_Property);

		public object lbtuTitle_var1 => GetValue(lbtuTitle_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Setup_Global")]
	public class MMAPr_Setup_Setup_Global : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuTitle_label;

		internal MMVariableEdit lbtuTitle;

		internal MMLabel cboInputData_label;

		internal MMComboEdit cboInputData;

		internal MMGroupBox fraGlobalSett;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		private bool _contentLoaded;

		public MMAPr_Setup_Setup_Global()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Setup_Global_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_setup_global.xaml", UriKind.Relative);
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
				cboPhase_label = (MMLabel)target;
				break;
			case 7:
				cboPhase = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox2 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Setup_Histor_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration chkEchoInsert_var1_Property = CxvPropertyDeclaration.Register("chkEchoInsert_var1", typeof(MMAPr_Setup_Setup_Histor_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Diagnostics.Input.INSERT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMAPr_Setup_Setup_Histor_ViewModel), new CxvBooleanProperty
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
	[ProgId("MMAPr_Setup.MMAPr_Setup_Setup_Histor")]
	public class MMAPr_Setup_Setup_Histor : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPrintHistory;

		internal MMCheckBox chkEchoInsert;

		internal MMCheckBox MMCheckBox1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAPr_Setup_Setup_Histor()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Setup_Histor_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_setup_histor.xaml", UriKind.Relative);
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
	public class MMAPr_Setup_Simopt_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration calc_Property = CxvPropertyDeclaration.Register("calc", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entclc_Property = CxvPropertyDeclaration.Register("entclc", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration entfls2_Property = CxvPropertyDeclaration.Register("entfls2", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTFLASH2"
		});

		public static readonly CxvPropertyDeclaration entsys_Property = CxvPropertyDeclaration.Register("entsys", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sys-Options.CC Nodes.ENTSYSTEM"
		});

		public static readonly CxvPropertyDeclaration entlim_Property = CxvPropertyDeclaration.Register("entlim", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.CC Nodes.ENTLIMIT"
		});

		public static readonly CxvPropertyDeclaration entmx_Property = CxvPropertyDeclaration.Register("entmx", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.CC Nodes.ENTMAX"
		});

		public static readonly CxvPropertyDeclaration entrea_Property = CxvPropertyDeclaration.Register("entrea", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.CC Nodes.ENTREAC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entclc" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@calc" },
			EnteredDataPaths = { "@entfls" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entfls2" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsys" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entlim", "@entmx" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAPr_Setup_Simopt_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entrea" }
		});

		public object calc => GetValue(calc_Property);

		public object entclc => GetValue(entclc_Property);

		public object entfls => GetValue(entfls_Property);

		public object entfls2 => GetValue(entfls2_Property);

		public object entsys => GetValue(entsys_Property);

		public object entlim => GetValue(entlim_Property);

		public object entmx => GetValue(entmx_Property);

		public object entrea => GetValue(entrea_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Simopt")]
	public class MMAPr_Setup_Simopt : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabSetup;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab6;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		private bool _contentLoaded;

		public MMAPr_Setup_Simopt()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Simopt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_simopt.xaml", UriKind.Relative);
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Simopt_Calcul_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText2_var2_Property = CxvPropertyDeclaration.Register("MMLBUText2_var2", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.REF_TEMP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var3_Property = CxvPropertyDeclaration.Register("MMLBUText3_var3", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.REF_PRES"
		});

		public static readonly CxvPropertyDeclaration chkDBChk_var1_Property = CxvPropertyDeclaration.Register("chkDBChk_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.OLD_DATABANK",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.PROP_DERIV",
			TrueValue = "ANALYTICAL",
			FalseValue = "NUMERICAL",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.DN_REQUIRED",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.DX_REQUIRED",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.SOLID_DERIV",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox5_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox5_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.ENG_ELECPAR",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration lbtuXwH2ophase_var1_Property = CxvPropertyDeclaration.Register("lbtuXwH2ophase_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.XW_H2OPHASE"
		});

		public static readonly CxvPropertyDeclaration chkBypass_var1_Property = CxvPropertyDeclaration.Register("chkBypass_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.BYPASS_PROP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration chkMwCalc_var1_Property = CxvPropertyDeclaration.Register("chkMwCalc_var1", typeof(MMAPr_Setup_Simopt_Calcul_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sim-Options.Input.MW_CALC",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public object MMLBUText2_var2 => GetValue(MMLBUText2_var2_Property);

		public object MMLBUText3_var3 => GetValue(MMLBUText3_var3_Property);

		public object chkDBChk_var1 => GetValue(chkDBChk_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox3_var1 => GetValue(MMCheckBox3_var1_Property);

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object MMCheckBox5_var1 => GetValue(MMCheckBox5_var1_Property);

		public object lbtuXwH2ophase_var1 => GetValue(lbtuXwH2ophase_var1_Property);

		public object chkBypass_var1 => GetValue(chkBypass_var1_Property);

		public object chkMwCalc_var1 => GetValue(chkMwCalc_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Simopt_Calcul")]
	public class MMAPr_Setup_Simopt_Calcul : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraCalc;

		internal MMCheckBox chkMwCalc;

		internal MMCheckBox chkBypass;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox2;

		internal MMCheckBox MMCheckBox3;

		internal MMCheckBox MMCheckBox4;

		internal MMCheckBox MMCheckBox5;

		internal MMTextBlock lbtuXwH2ophase_label;

		internal MMVariableEdit lbtuXwH2ophase;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		private bool _contentLoaded;

		public MMAPr_Setup_Simopt_Calcul()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Simopt_Calcul_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_simopt_calcul.xaml", UriKind.Relative);
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
				chkMwCalc = (MMCheckBox)target;
				break;
			case 3:
				chkBypass = (MMCheckBox)target;
				break;
			case 4:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 7:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			case 8:
				MMCheckBox5 = (MMCheckBox)target;
				break;
			case 9:
				lbtuXwH2ophase_label = (MMTextBlock)target;
				break;
			case 10:
				lbtuXwH2ophase = (MMVariableEdit)target;
				break;
			case 11:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 12:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 13:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 14:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Simopt_Limits_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMSpinBox4_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox4_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.PROP_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox2_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox2_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SYS_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox3_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox3_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Diagnostics.Input.SIM_LIMIT"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox1_var1_Property = CxvPropertyDeclaration.Register("MMSpinBox1_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_FORT_ERR"
		});

		public static readonly CxvPropertyDeclaration lbtuMaxTime_var1_Property = CxvPropertyDeclaration.Register("lbtuMaxTime_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_TIME"
		});

		public static readonly CxvPropertyDeclaration spnSevErr_var1_Property = CxvPropertyDeclaration.Register("spnSevErr_var1", typeof(MMAPr_Setup_Simopt_Limits_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Run-Control.Input.MAX_ERRORS"
		});

		public object MMSpinBox4_var1 => GetValue(MMSpinBox4_var1_Property);

		public object MMSpinBox2_var1 => GetValue(MMSpinBox2_var1_Property);

		public object MMSpinBox3_var1 => GetValue(MMSpinBox3_var1_Property);

		public object MMSpinBox1_var1 => GetValue(MMSpinBox1_var1_Property);

		public object lbtuMaxTime_var1 => GetValue(lbtuMaxTime_var1_Property);

		public object spnSevErr_var1 => GetValue(spnSevErr_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Simopt_Limits")]
	public class MMAPr_Setup_Simopt_Limits : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraTimeError;

		internal MMLabel lbtuMaxTime_label;

		internal MMVariableEdit lbtuMaxTime;

		internal MMLabel spnSevErr_label;

		internal MMSpinBox spnSevErr;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox fraHisFile;

		internal MMLabel MMSpinBox2_label;

		internal MMSpinBox MMSpinBox2;

		internal MMLabel MMSpinBox3_label;

		internal MMSpinBox MMSpinBox3;

		internal MMLabel MMSpinBox4_label;

		internal MMSpinBox MMSpinBox4;

		private bool _contentLoaded;

		public MMAPr_Setup_Simopt_Limits()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Simopt_Limits_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_simopt_limits.xaml", UriKind.Relative);
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
				fraHisFile = (MMGroupBox)target;
				break;
			case 9:
				MMSpinBox2_label = (MMLabel)target;
				break;
			case 10:
				MMSpinBox2 = (MMSpinBox)target;
				break;
			case 11:
				MMSpinBox3_label = (MMLabel)target;
				break;
			case 12:
				MMSpinBox3 = (MMSpinBox)target;
				break;
			case 13:
				MMSpinBox4_label = (MMLabel)target;
				break;
			case 14:
				MMSpinBox4 = (MMSpinBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Simopt_System_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMAPr_Setup_Simopt_System_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Sys-Options.Input.TRACE",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Simopt_System")]
	public class MMAPr_Setup_Simopt_System : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBox7;

		private bool _contentLoaded;

		public MMAPr_Setup_Simopt_System()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Simopt_System_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_simopt_system.xaml", UriKind.Relative);
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
				MMCheckBox7 = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Units_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMAPr_Setup_Units_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Setup_Units_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@var1" }
		});

		public object var1 => GetValue(var1_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Units")]
	public class MMAPr_Setup_Units : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		private bool _contentLoaded;

		public MMAPr_Setup_Units()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Units_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_units.xaml", UriKind.Relative);
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Units_Energy_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox48_var1_Property = CxvPropertyDeclaration.Register("MMComboBox48_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-HEAT-CA"
		});

		public static readonly CxvPropertyDeclaration MMComboBox49_var1_Property = CxvPropertyDeclaration.Register("MMComboBox49_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-HEAT-CA"
		});

		public static readonly CxvPropertyDeclaration MMComboBox37_var1_Property = CxvPropertyDeclaration.Register("MMComboBox37_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-ENTROPY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox38_var1_Property = CxvPropertyDeclaration.Register("MMComboBox38_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-ENTROPY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox39_var1_Property = CxvPropertyDeclaration.Register("MMComboBox39_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENTROPY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox54_var1_Property = CxvPropertyDeclaration.Register("MMComboBox54_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DIPOLEMOMENT"
		});

		public static readonly CxvPropertyDeclaration MMComboBox53_var1_Property = CxvPropertyDeclaration.Register("MMComboBox53_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SOLUPARAM"
		});

		public static readonly CxvPropertyDeclaration MMComboBox33_var1_Property = CxvPropertyDeclaration.Register("MMComboBox33_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-ENTHALP"
		});

		public static readonly CxvPropertyDeclaration MMComboBox34_var1_Property = CxvPropertyDeclaration.Register("MMComboBox34_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-ENTHALP"
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_3_var1", typeof(MMAPr_Setup_Units_Energy_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.ENTHALPY"
		});

		public object MMComboBox48_var1 => GetValue(MMComboBox48_var1_Property);

		public object MMComboBox49_var1 => GetValue(MMComboBox49_var1_Property);

		public object MMComboBox37_var1 => GetValue(MMComboBox37_var1_Property);

		public object MMComboBox38_var1 => GetValue(MMComboBox38_var1_Property);

		public object MMComboBox39_var1 => GetValue(MMComboBox39_var1_Property);

		public object MMComboBox54_var1 => GetValue(MMComboBox54_var1_Property);

		public object MMComboBox53_var1 => GetValue(MMComboBox53_var1_Property);

		public object MMComboBox33_var1 => GetValue(MMComboBox33_var1_Property);

		public object MMComboBox34_var1 => GetValue(MMComboBox34_var1_Property);

		public object MMComboBox18_3_var1 => GetValue(MMComboBox18_3_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Units_Energy")]
	public class MMAPr_Setup_Units_Energy : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame9;

		internal MMLabel MMComboBox18_3_label;

		internal MMComboEdit MMComboBox18_3;

		internal MMLabel MMComboBox34_label;

		internal MMComboEdit MMComboBox34;

		internal MMLabel MMComboBox33_label;

		internal MMComboEdit MMComboBox33;

		internal MMGroupBox MMFrame10;

		internal MMLabel MMComboBox39_label;

		internal MMComboEdit MMComboBox39;

		internal MMLabel MMComboBox38_label;

		internal MMComboEdit MMComboBox38;

		internal MMLabel MMComboBox37_label;

		internal MMComboEdit MMComboBox37;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox48_label;

		internal MMComboEdit MMComboBox48;

		internal MMLabel MMComboBox49_label;

		internal MMComboEdit MMComboBox49;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox54_label;

		internal MMComboEdit MMComboBox54;

		internal MMLabel MMComboBox53_label;

		internal MMComboEdit MMComboBox53;

		private bool _contentLoaded;

		public MMAPr_Setup_Units_Energy()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Units_Energy_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_units_energy.xaml", UriKind.Relative);
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
				MMComboBox34_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox34 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox33_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox33 = (MMComboEdit)target;
				break;
			case 8:
				MMFrame10 = (MMGroupBox)target;
				break;
			case 9:
				MMComboBox39_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox39 = (MMComboEdit)target;
				break;
			case 11:
				MMComboBox38_label = (MMLabel)target;
				break;
			case 12:
				MMComboBox38 = (MMComboEdit)target;
				break;
			case 13:
				MMComboBox37_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox37 = (MMComboEdit)target;
				break;
			case 15:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 16:
				MMComboBox48_label = (MMLabel)target;
				break;
			case 17:
				MMComboBox48 = (MMComboEdit)target;
				break;
			case 18:
				MMComboBox49_label = (MMLabel)target;
				break;
			case 19:
				MMComboBox49 = (MMComboEdit)target;
				break;
			case 20:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 21:
				MMComboBox54_label = (MMLabel)target;
				break;
			case 22:
				MMComboBox54 = (MMComboEdit)target;
				break;
			case 23:
				MMComboBox53_label = (MMLabel)target;
				break;
			case 24:
				MMComboBox53 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Units_Temper_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.BASESET"
		});

		public static readonly CxvPropertyDeclaration MMComboBox27_var1_Property = CxvPropertyDeclaration.Register("MMComboBox27_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.TEMPERATURE"
		});

		public static readonly CxvPropertyDeclaration MMComboBox28_var1_Property = CxvPropertyDeclaration.Register("MMComboBox28_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.PRESSURE"
		});

		public static readonly CxvPropertyDeclaration MMComboBox16_var1_Property = CxvPropertyDeclaration.Register("MMComboBox16_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-VOLUME"
		});

		public static readonly CxvPropertyDeclaration MMComboBox17_var1_Property = CxvPropertyDeclaration.Register("MMComboBox17_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME"
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-DENSITY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-DENSITY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_0_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DENSITY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_2_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.FLOW"
		});

		public static readonly CxvPropertyDeclaration MMComboBox19_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VOLUME-FLOW"
		});

		public static readonly CxvPropertyDeclaration MMComboBox20_var1_Property = CxvPropertyDeclaration.Register("MMComboBox20_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MOLE-FLOW"
		});

		public static readonly CxvPropertyDeclaration MMComboBox21_var1_Property = CxvPropertyDeclaration.Register("MMComboBox21_var1", typeof(MMAPr_Setup_Units_Temper_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-FLOW"
		});

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object MMComboBox27_var1 => GetValue(MMComboBox27_var1_Property);

		public object MMComboBox28_var1 => GetValue(MMComboBox28_var1_Property);

		public object MMComboBox16_var1 => GetValue(MMComboBox16_var1_Property);

		public object MMComboBox17_var1 => GetValue(MMComboBox17_var1_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMComboBox5_var1 => GetValue(MMComboBox5_var1_Property);

		public object MMComboBox18_0_var1 => GetValue(MMComboBox18_0_var1_Property);

		public object MMComboBox18_2_var1 => GetValue(MMComboBox18_2_var1_Property);

		public object MMComboBox19_var1 => GetValue(MMComboBox19_var1_Property);

		public object MMComboBox20_var1 => GetValue(MMComboBox20_var1_Property);

		public object MMComboBox21_var1 => GetValue(MMComboBox21_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Units_Temper")]
	public class MMAPr_Setup_Units_Temper : MMTabPage, IComponentConnector
	{
		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox18_0_label;

		internal MMComboEdit MMComboBox18_0;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMGroupBox MMFrame6;

		internal MMLabel MMComboBox21_label;

		internal MMComboEdit MMComboBox21;

		internal MMLabel MMComboBox20_label;

		internal MMComboEdit MMComboBox20;

		internal MMLabel MMComboBox19_label;

		internal MMComboEdit MMComboBox19;

		internal MMLabel MMComboBox18_2_label;

		internal MMComboEdit MMComboBox18_2;

		internal MMGroupBox MMFrame7;

		internal MMLabel MMComboBox27_label;

		internal MMComboEdit MMComboBox27;

		internal MMGroupBox MMFrame8;

		internal MMLabel MMComboBox28_label;

		internal MMComboEdit MMComboBox28;

		internal MMGroupBox MMFrame5;

		internal MMLabel MMComboBox17_label;

		internal MMComboEdit MMComboBox17;

		internal MMLabel MMComboBox16_label;

		internal MMComboEdit MMComboBox16;

		private bool _contentLoaded;

		public MMAPr_Setup_Units_Temper()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Units_Temper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_units_temper.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 4:
				MMComboBox18_0_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox18_0 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 10:
				MMFrame6 = (MMGroupBox)target;
				break;
			case 11:
				MMComboBox21_label = (MMLabel)target;
				break;
			case 12:
				MMComboBox21 = (MMComboEdit)target;
				break;
			case 13:
				MMComboBox20_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox20 = (MMComboEdit)target;
				break;
			case 15:
				MMComboBox19_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox19 = (MMComboEdit)target;
				break;
			case 17:
				MMComboBox18_2_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox18_2 = (MMComboEdit)target;
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
				MMFrame8 = (MMGroupBox)target;
				break;
			case 23:
				MMComboBox28_label = (MMLabel)target;
				break;
			case 24:
				MMComboBox28 = (MMComboEdit)target;
				break;
			case 25:
				MMFrame5 = (MMGroupBox)target;
				break;
			case 26:
				MMComboBox17_label = (MMLabel)target;
				break;
			case 27:
				MMComboBox17 = (MMComboEdit)target;
				break;
			case 28:
				MMComboBox16_label = (MMLabel)target;
				break;
			case 29:
				MMComboBox16 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAPr_Setup_Units_Volume_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox19_0_var1_Property = CxvPropertyDeclaration.Register("MMComboBox19_0_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VELOCITY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox58_var1_Property = CxvPropertyDeclaration.Register("MMComboBox58_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.DIFFUSIVITY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox57_var1_Property = CxvPropertyDeclaration.Register("MMComboBox57_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.MASS-TRANS-C"
		});

		public static readonly CxvPropertyDeclaration MMComboBox56_var1_Property = CxvPropertyDeclaration.Register("MMComboBox56_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.SURFACE-TENS"
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_8_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_8_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.THERMAL-COND"
		});

		public static readonly CxvPropertyDeclaration MMComboBox18_7_var1_Property = CxvPropertyDeclaration.Register("MMComboBox18_7_var1", typeof(MMAPr_Setup_Units_Volume_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Unit-Types.VISCOSITY"
		});

		public object MMComboBox19_0_var1 => GetValue(MMComboBox19_0_var1_Property);

		public object MMComboBox58_var1 => GetValue(MMComboBox58_var1_Property);

		public object MMComboBox57_var1 => GetValue(MMComboBox57_var1_Property);

		public object MMComboBox56_var1 => GetValue(MMComboBox56_var1_Property);

		public object MMComboBox18_8_var1 => GetValue(MMComboBox18_8_var1_Property);

		public object MMComboBox18_7_var1 => GetValue(MMComboBox18_7_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMAPr_Setup_Units_Volume")]
	public class MMAPr_Setup_Units_Volume : MMTabPage, IComponentConnector
	{
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

		internal MMLabel MMComboBox19_0_label;

		internal MMComboEdit MMComboBox19_0;

		private bool _contentLoaded;

		public MMAPr_Setup_Units_Volume()
		{
			base.ViewModelType = typeof(MMAPr_Setup_Units_Volume_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmapr_setup_units_volume.xaml", UriKind.Relative);
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
				MMFrame14 = (MMGroupBox)target;
				break;
			case 2:
				MMComboBox58_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox58 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox57_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox57 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox56_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox56 = (MMComboEdit)target;
				break;
			case 8:
				MMComboBox18_8_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox18_8 = (MMComboEdit)target;
				break;
			case 10:
				MMComboBox18_7_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox18_7 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox19_0_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox19_0 = (MMComboEdit)target;
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
	[ProgId("MMAPr_Setup.MMSetup_Report_ADA")]
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_report_ada.xaml", UriKind.Relative);
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
					ResolveUpdateParameter("HeaderLabel", Resources.MMSetup_Setup_Accoun_HeaderLabel_AProp);
				}
				else
				{
					ResolveUpdateParameter("HeaderLabel", Resources.MMSetup_Setup_Accoun_HeaderLabel_APlus);
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMAPr_Setup.MMSetup_Setup_Accoun")]
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_setup_accoun.xaml", UriKind.Relative);
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
	[ProgId("MMAPr_Setup.MMSetup_Setup_Descri")]
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_setup_descri.xaml", UriKind.Relative);
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
	public class MMSetup_Setup_Proper_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdOK_Command;

		private ICommand _cmdCancel_Command;

		public static readonly CxvPropertyDeclaration txtNewId_propset_Property = CxvPropertyDeclaration.Register("txtNewId_propset", typeof(MMSetup_Setup_Proper_ViewModel), new CxvParameterProperty
		{
			Parameter = "propset"
		});

		public ICommand cmdOK_Command
		{
			get
			{
				if (_cmdOK_Command == null)
				{
					_cmdOK_Command = new CxvDelegateCommand<object>(cmdOK_CommandExecute);
				}
				return _cmdOK_Command;
			}
		}

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

		public object txtNewId_propset => GetValue(txtNewId_propset_Property);

		private void cmdOK_CommandExecute(object parameter)
		{
		}

		private void cmdCancel_CommandExecute(object parameter)
		{
		}
	}
	[ProgId("MMAPr_Setup.MMSetup_Setup_Proper")]
	public class MMSetup_Setup_Proper : MMTabPage, IComponentConnector
	{
		internal MMLabel lblNewId;

		internal MMValueEdit txtNewId;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMSetup_Setup_Proper()
		{
			base.ViewModelType = typeof(MMSetup_Setup_Proper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_setup_proper.xaml", UriKind.Relative);
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
				lblNewId = (MMLabel)target;
				break;
			case 2:
				txtNewId = (MMValueEdit)target;
				break;
			case 3:
				cmdOK = (MMCmdButton)target;
				break;
			case 4:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Flashc_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrRootErrorLevel",
					DataPath = "@main.Sim-Options.Input.FLASH_PSEUDO"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Warning",
					DisplayResourceKey = "RootErrorLevelOption_Warning",
					Value = "ogrRootErrorLevel_Warning",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrRootErrorLevel",
							Value = "WARNING"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Error",
					DisplayResourceKey = "RootErrorLevelOption_Error",
					Value = "ogrRootErrorLevel_Error",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrRootErrorLevel",
							Value = "ERROR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Information",
					DisplayResourceKey = "RootErrorLevelOption_Information",
					Value = "ogrRootErrorLevel_Information",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrRootErrorLevel",
							Value = "INFORMATION"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "None",
					DisplayResourceKey = "RootErrorLevelOption_None",
					Value = "ogrRootErrorLevel_None",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrRootErrorLevel",
							Value = "NONE"
						}
					}
				}
			}
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

		public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.PEQ_CHECK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PEQ_CHK_TOL"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.PEQ_CHK_FRAC"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.SOLTHRESHOLD"
		});

		public static readonly CxvPropertyDeclaration chkPhaseStab_var1_Property = CxvPropertyDeclaration.Register("chkPhaseStab_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Sim-Options.Input.FL_STAB_CHK",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration StabChkThr_var1_Property = CxvPropertyDeclaration.Register("StabChkThr_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_CHK_THR"
		});

		public static readonly CxvPropertyDeclaration StabMinFrc_var1_Property = CxvPropertyDeclaration.Register("StabMinFrc_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_MIN_FRC"
		});

		public static readonly CxvPropertyDeclaration StabMaxFrc_var1_Property = CxvPropertyDeclaration.Register("StabMaxFrc_var1", typeof(MMSetup_Simopt_Flashc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.STAB_MAX_FRC"
		});

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cboFlashMethod_MultiMap => GetValue(cboFlashMethod_MultiMap_Property);

		public object MMCheckBox3_var1 => GetValue(MMCheckBox3_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object lbtuTol_var1 => GetValue(lbtuTol_var1_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);

		public object lbtuRootExtr_var1 => GetValue(lbtuRootExtr_var1_Property);

		public object lbtuLowPres_var1 => GetValue(lbtuLowPres_var1_Property);

		public object lbtuUpPres_var1 => GetValue(lbtuUpPres_var1_Property);

		public object lbtuLowTemp_var1 => GetValue(lbtuLowTemp_var1_Property);

		public object lbtuUpTemp_var1 => GetValue(lbtuUpTemp_var1_Property);

		public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object chkPhaseStab_var1 => GetValue(chkPhaseStab_var1_Property);

		public object StabChkThr_var1 => GetValue(StabChkThr_var1_Property);

		public object StabMinFrc_var1 => GetValue(StabMinFrc_var1_Property);

		public object StabMaxFrc_var1 => GetValue(StabMaxFrc_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMSetup_Simopt_Flashc")]
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_simopt_flashc.xaml", UriKind.Relative);
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
				lbtuRootExtr_label = (MMLabel)target;
				break;
			case 17:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 18:
				lbtuRootExtr = (MMVariableEdit)target;
				break;
			case 19:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 20:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 21:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 22:
				MMCheckBox7 = (MMCheckBox)target;
				break;
			case 23:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 24:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 25:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 26:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSetup_Simopt_Reactions_ViewModel : MMTabPageViewModel
	{
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

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSetup_Simopt_Reactions_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Sim-Options.Input.ELEC_CHK_TOL"
		});

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object ogrStioMbChe_MultiMap => GetValue(ogrStioMbChe_MultiMap_Property);

		public object lbtuStoicTol_var1 => GetValue(lbtuStoicTol_var1_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);
	}
	[ProgId("MMAPr_Setup.MMSetup_Simopt_Reactions")]
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_simopt_reactions.xaml", UriKind.Relative);
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
	[ProgId("MMAPr_Setup.MMSetup_Simopt_Result")]
	public class MMSetup_Simopt_Result : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.APropSetup;component/mmsetup_simopt_result.xaml", UriKind.Relative);
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
				MMLBUText1_label = (MMTextBlock)target;
				break;
			case 5:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 6:
				MMLBUText2_label = (MMTextBlock)target;
				break;
			case 7:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 8:
				MMLBUText4_label = (MMTextBlock)target;
				break;
			case 9:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 10:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 11:
				chkPhaseStab_label = (MMLabel)target;
				break;
			case 12:
				chkPhaseStab = (MMComboEdit)target;
				break;
			case 13:
				StabChkThr_label = (MMTextBlock)target;
				break;
			case 14:
				StabChkThr = (MMVariableEdit)target;
				break;
			case 15:
				StabMinFrc_label = (MMTextBlock)target;
				break;
			case 16:
				StabMinFrc = (MMVariableEdit)target;
				break;
			case 17:
				StabMaxFrc_label = (MMTextBlock)target;
				break;
			case 18:
				StabMaxFrc = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
