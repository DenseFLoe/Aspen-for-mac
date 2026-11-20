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
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xml;
using System.Xml.Linq;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.Localization.WpfPlotWizards;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture;
using AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Converter;
using AspenTech.Engineering.GridControls;
using AspenTech.Engineering.GridControls.EventArgs;
using AspenTech.Engineering.GridControls.Internal;
using AspenTech.Visualisation.CommonImages;
using AspenTech.Visualisation.CommonShell;
using AspenTech.Visualisation.Controls.Support.Commands;
using AspenTech.WpfControls.Engineering;
using AspenTech.WpfControls.Engineering.Properties;
using Infragistics.Windows;
using Infragistics.Windows.Editors;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;

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

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties
{
	public class PairValueToDisplayTextConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				string text = value.ToString().Trim();
				if (!string.IsNullOrEmpty(text))
				{
					int num = text.IndexOf(' ');
					if (num > 0)
					{
						return text.Substring(0, num);
					}
					return text;
				}
			}
			return null;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties
{
	public class DiaplayTextToValueConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				string text = value.ToString().Trim();
				if (!string.IsNullOrEmpty(text))
				{
					int num = text.IndexOf(' ');
					if (num > 0)
					{
						text = text.Substring(0, num);
					}
				}
				string numberDecimalSeparator = CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;
				return text.Replace(".", numberDecimalSeparator);
			}
			return null;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				string text = value.ToString().Trim();
				if (!string.IsNullOrEmpty(text))
				{
					int num = text.IndexOf(' ');
					if (num > 0)
					{
						text = text.Substring(0, num);
					}
				}
				return text;
			}
			return null;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	public class CheckBoxHeaderGroupBox : GroupBox
	{
		public override void OnApplyTemplate()
		{
			base.OnApplyTemplate();
			if (VisualChildrenCount > 0 && GetVisualChild(0) is Grid grid && grid.Children.Count >= 4 && grid.Children[3] is Border border)
			{
				border.IsHitTestVisible = false;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_GopsetNameDB")]
	public class MMProp_Spec_GopsetNameDB : MMTabPage, IComponentConnector
	{
		internal MMLabel txtOpsetName_label;

		internal MMVariableEdit txtOpsetName;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMProp_Spec_GopsetNameDB()
		{
			base.ViewModelType = typeof(MMProp_Spec_GopsetNameDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_gopsetnamedb.xaml", UriKind.Relative);
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
				txtOpsetName_label = (MMLabel)target;
				break;
			case 2:
				txtOpsetName = (MMVariableEdit)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	public class MMProp_Spec_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMProp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMProp_Spec_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration FlowSect_Property = CxvPropertyDeclaration.Register("FlowSect", typeof(MMProp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN2"
		});

		public static readonly CxvPropertyDeclaration entflow_Property = CxvPropertyDeclaration.Register("entflow", typeof(MMProp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLOW"
		});

		public static readonly CxvPropertyDeclaration entref_Property = CxvPropertyDeclaration.Register("entref", typeof(MMProp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTREF"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMProp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMProp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@FlowSect" },
			EnteredDataPaths = { "@entflow" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMProp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entref" }
		});

		private Visibility _commonVisibility;

		public object global => GetValue(global_Property);

		public object choice => GetValue(choice_Property);

		public object FlowSect => GetValue(FlowSect_Property);

		public object entflow => GetValue(entflow_Property);

		public object entref => GetValue(entref_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public Visibility CommonVisibility
		{
			get
			{
				return _commonVisibility;
			}
			set
			{
				_commonVisibility = value;
				OnPropertyChanged("CommonVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
			SetVisibilities();
		}

		private void SetVisibilities()
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value"));
			CommonVisibility = ((text == "ADA" || text == "PCES") ? Visibility.Collapsed : Visibility.Visible);
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_Input")]
	public class MMProp_Spec_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabProp_Spec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMProp_Spec_Input()
		{
			base.ViewModelType = typeof(MMProp_Spec_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_input.xaml", UriKind.Relative);
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
				tabProp_Spec = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_Input_FlowSect")]
	public class MMProp_Spec_Input_FlowSect : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuSectionID_label;

		internal MMAdvancedComboEdit mnuSectionID;

		internal MMLabel MMLabel1;

		internal MMGroupBox fra_Property_Methods_Models;

		internal MMLabel cbo_ProcessType_label;

		internal MMComboEdit cbo_ProcessType;

		internal MMLabel cboBase_Method_label;

		internal MMComboEdit cboBase_Method;

		internal MMLabel cboHenryComps_label;

		internal MMComboEdit cboHenryComps;

		internal MMGroupBox fra_Petroleum_Calc_Opt;

		internal MMLabel cboFreeWaterPhase_label;

		internal MMComboEdit cboFreeWaterPhase;

		internal MMLabel cboSolu_Water_label;

		internal MMComboEdit cboSolu_Water;

		internal MMGroupBox fraElectrolyte_Calc_Opt;

		internal MMLabel cboChemistryID_label;

		internal MMComboEdit cboChemistryID;

		internal MMCheckBox chkUseTrueComponents;

		internal MMComboEdit cboProperty_Method_ID;

		internal MMCmdButton CmdAssistant;

		internal CheckBoxHeaderGroupBox fra_Models;

		internal MMCheckBox chkModifyflow;

		internal MMLabel lblVaporEOS;

		internal MMLabel lblEOS;

		internal MMComboEdit cbo_VaporEOS;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel cbo_LiquidGamma_label;

		internal MMComboEdit cbo_LiquidGamma;

		internal MMLabel spnData_Set_label;

		internal MMSpinBox spnData_Set;

		internal MMLabel cbo_LiquidEnthalpy_label;

		internal MMComboEdit cbo_LiquidEnthalpy;

		internal MMLabel cbo_LiquidDensity_label;

		internal MMComboEdit cbo_LiquidDensity;

		internal MMCheckBox chk_PoyntingCorrection;

		internal MMCheckBox chk_HeatOfMixing;

		internal MMCheckBox chk_LiqRefState;

		private bool _contentLoaded;

		public MMProp_Spec_Input_FlowSect()
		{
			base.ViewModelType = typeof(MMProp_Spec_Input_FlowSect_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_input_flowsect.xaml", UriKind.Relative);
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
				mnuSectionID_label = (MMLabel)target;
				break;
			case 2:
				mnuSectionID = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMLabel1 = (MMLabel)target;
				break;
			case 4:
				fra_Property_Methods_Models = (MMGroupBox)target;
				break;
			case 5:
				cbo_ProcessType_label = (MMLabel)target;
				break;
			case 6:
				cbo_ProcessType = (MMComboEdit)target;
				break;
			case 7:
				cboBase_Method_label = (MMLabel)target;
				break;
			case 8:
				cboBase_Method = (MMComboEdit)target;
				break;
			case 9:
				cboHenryComps_label = (MMLabel)target;
				break;
			case 10:
				cboHenryComps = (MMComboEdit)target;
				break;
			case 11:
				fra_Petroleum_Calc_Opt = (MMGroupBox)target;
				break;
			case 12:
				cboFreeWaterPhase_label = (MMLabel)target;
				break;
			case 13:
				cboFreeWaterPhase = (MMComboEdit)target;
				break;
			case 14:
				cboSolu_Water_label = (MMLabel)target;
				break;
			case 15:
				cboSolu_Water = (MMComboEdit)target;
				break;
			case 16:
				fraElectrolyte_Calc_Opt = (MMGroupBox)target;
				break;
			case 17:
				cboChemistryID_label = (MMLabel)target;
				break;
			case 18:
				cboChemistryID = (MMComboEdit)target;
				break;
			case 19:
				chkUseTrueComponents = (MMCheckBox)target;
				break;
			case 20:
				cboProperty_Method_ID = (MMComboEdit)target;
				break;
			case 21:
				CmdAssistant = (MMCmdButton)target;
				break;
			case 22:
				fra_Models = (CheckBoxHeaderGroupBox)target;
				break;
			case 23:
				chkModifyflow = (MMCheckBox)target;
				break;
			case 24:
				lblVaporEOS = (MMLabel)target;
				break;
			case 25:
				lblEOS = (MMLabel)target;
				break;
			case 26:
				cbo_VaporEOS = (MMComboEdit)target;
				break;
			case 27:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 28:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 29:
				cbo_LiquidGamma_label = (MMLabel)target;
				break;
			case 30:
				cbo_LiquidGamma = (MMComboEdit)target;
				break;
			case 31:
				spnData_Set_label = (MMLabel)target;
				break;
			case 32:
				spnData_Set = (MMSpinBox)target;
				break;
			case 33:
				cbo_LiquidEnthalpy_label = (MMLabel)target;
				break;
			case 34:
				cbo_LiquidEnthalpy = (MMComboEdit)target;
				break;
			case 35:
				cbo_LiquidDensity_label = (MMLabel)target;
				break;
			case 36:
				cbo_LiquidDensity = (MMComboEdit)target;
				break;
			case 37:
				chk_PoyntingCorrection = (MMCheckBox)target;
				break;
			case 38:
				chk_HeatOfMixing = (MMCheckBox)target;
				break;
			case 39:
				chk_LiqRefState = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_Input_Global")]
	public class MMProp_Spec_Input_Global : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInformation;

		internal MMLabel MMLabel2;

		internal MMGroupBox fra_Property_Methods_Models;

		internal MMLabel cboGPProcessType_label;

		internal MMComboEdit cboGPProcessType;

		internal MMLabel MMComboBox4_label;

		internal MMLabel lblBase_Method;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox fraPetroleumCalculationOptions;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMGroupBox fraElectrolyteCalculationOptions;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMCheckBox MMCheckBox1;

		internal MMLabel MMLabel1;

		internal MMComboEdit MMComboBox7;

		internal MMCmdButton CmdAssistant;

		internal CheckBoxHeaderGroupBox fraModels;

		internal MMCheckBox chkModifyglobal;

		internal MMLabel lblVaporEOS;

		internal MMLabel lblEOS;

		internal MMComboEdit cboVaporEOS;

		internal MMLabel spnVaporEOS_label;

		internal MMSpinBox spnVaporEOS;

		internal MMLabel cboLiquidGamma_label;

		internal MMComboEdit cboLiquidGamma;

		internal MMLabel spnDataSetLiqdGamma_label;

		internal MMSpinBox spnDataSetLiqdGamma;

		internal MMLabel cboLiquidEnthalpy_label;

		internal MMComboEdit cboLiquidEnthalpy;

		internal MMLabel cboLiquidDensity_label;

		internal MMComboEdit cboLiquidDensity;

		internal MMCheckBox chkHeatofMixing;

		internal MMCheckBox chkPoyntingCorrection;

		internal MMCheckBox chkLiqRefState;

		private bool _contentLoaded;

		public MMProp_Spec_Input_Global()
		{
			base.ViewModelType = typeof(MMProp_Spec_Input_Global_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_input_global.xaml", UriKind.Relative);
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
				fraInformation = (MMGroupBox)target;
				break;
			case 2:
				MMLabel2 = (MMLabel)target;
				break;
			case 3:
				fra_Property_Methods_Models = (MMGroupBox)target;
				break;
			case 4:
				cboGPProcessType_label = (MMLabel)target;
				break;
			case 5:
				cboGPProcessType = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 7:
				lblBase_Method = (MMLabel)target;
				break;
			case 8:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 9:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 11:
				fraPetroleumCalculationOptions = (MMGroupBox)target;
				break;
			case 12:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 14:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 16:
				fraElectrolyteCalculationOptions = (MMGroupBox)target;
				break;
			case 17:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 18:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 19:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 20:
				MMLabel1 = (MMLabel)target;
				break;
			case 21:
				MMComboBox7 = (MMComboEdit)target;
				break;
			case 22:
				CmdAssistant = (MMCmdButton)target;
				break;
			case 23:
				fraModels = (CheckBoxHeaderGroupBox)target;
				break;
			case 24:
				chkModifyglobal = (MMCheckBox)target;
				break;
			case 25:
				lblVaporEOS = (MMLabel)target;
				break;
			case 26:
				lblEOS = (MMLabel)target;
				break;
			case 27:
				cboVaporEOS = (MMComboEdit)target;
				break;
			case 28:
				spnVaporEOS_label = (MMLabel)target;
				break;
			case 29:
				spnVaporEOS = (MMSpinBox)target;
				break;
			case 30:
				cboLiquidGamma_label = (MMLabel)target;
				break;
			case 31:
				cboLiquidGamma = (MMComboEdit)target;
				break;
			case 32:
				spnDataSetLiqdGamma_label = (MMLabel)target;
				break;
			case 33:
				spnDataSetLiqdGamma = (MMSpinBox)target;
				break;
			case 34:
				cboLiquidEnthalpy_label = (MMLabel)target;
				break;
			case 35:
				cboLiquidEnthalpy = (MMComboEdit)target;
				break;
			case 36:
				cboLiquidDensity_label = (MMLabel)target;
				break;
			case 37:
				cboLiquidDensity = (MMComboEdit)target;
				break;
			case 38:
				chkHeatofMixing = (MMCheckBox)target;
				break;
			case 39:
				chkPoyntingCorrection = (MMCheckBox)target;
				break;
			case 40:
				chkLiqRefState = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	public class MMProp_Spec_Input_Reference_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lstpSelectMethods_copybopset_Property = CxvPropertyDeclaration.Register("lstpSelectMethods_copybopset", typeof(MMProp_Spec_Input_Reference_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.BOPSETNAME",
			AllowSort = false
		});

		public object lstpSelectMethods_copybopset => GetValue(lstpSelectMethods_copybopset_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_Input_Reference")]
	public class MMProp_Spec_Input_Reference : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpSelectMethods;

		private bool _contentLoaded;

		public MMProp_Spec_Input_Reference()
		{
			base.ViewModelType = typeof(MMProp_Spec_Input_Reference_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_input_reference.xaml", UriKind.Relative);
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
				lstpSelectMethods = (MMListPicker)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Specifications
{
	[ProgId("MMProp_Spec.MMProp_Spec_OpsetnameDB")]
	public class MMProp_Spec_OpsetnameDB : MMTabPage, IComponentConnector
	{
		internal MMLabel txtOpsetName_label;

		internal MMVariableEdit txtOpsetName;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMProp_Spec_OpsetnameDB()
		{
			base.ViewModelType = typeof(MMProp_Spec_OpsetnameDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/specifications/mmprop_spec_opsetnamedb.xaml", UriKind.Relative);
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
				txtOpsetName_label = (MMLabel)target;
				break;
			case 2:
				txtOpsetName = (MMVariableEdit)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMRegress_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration SETUPTAB1_Property = CxvPropertyDeclaration.Register("SETUPTAB1", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SETUPTAB1"
		});

		public static readonly CxvPropertyDeclaration SETUPTAB2_Property = CxvPropertyDeclaration.Register("SETUPTAB2", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration PARAMSTAB1_Property = CxvPropertyDeclaration.Register("PARAMSTAB1", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.PARAMSTAB1"
		});

		public static readonly CxvPropertyDeclaration ENTALGO_Property = CxvPropertyDeclaration.Register("ENTALGO", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTALGO"
		});

		public static readonly CxvPropertyDeclaration ENTDIAG_Property = CxvPropertyDeclaration.Register("ENTDIAG", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration ENTREP_Property = CxvPropertyDeclaration.Register("ENTREP", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTREP"
		});

		public static readonly CxvPropertyDeclaration ENTGEN_Property = CxvPropertyDeclaration.Register("ENTGEN", typeof(MMRegress_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTGEN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SETUPTAB1", "@SETUPTAB2" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PARAMSTAB1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTREP" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTALGO" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTDIAG" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMRegress_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTGEN" }
		});

		public object choice => GetValue(choice_Property);

		public object SETUPTAB1 => GetValue(SETUPTAB1_Property);

		public object SETUPTAB2 => GetValue(SETUPTAB2_Property);

		public object PARAMSTAB1 => GetValue(PARAMSTAB1_Property);

		public object ENTALGO => GetValue(ENTALGO_Property);

		public object ENTDIAG => GetValue(ENTDIAG_Property);

		public object ENTREP => GetValue(ENTREP_Property);

		public object ENTGEN => GetValue(ENTGEN_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp")]
	public class MMRegress_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMRegress_Inp()
		{
			base.ViewModelType = typeof(MMRegress_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_Algorithm")]
	public class MMRegress_Inp_Algorithm : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraOptions;

		internal MMLabel cboObjectFunction_label;

		internal MMComboEdit cboObjectFunction;

		internal MMLabel cboAlgorithm_label;

		internal MMComboEdit cboAlgorithm;

		internal MMLabel cboInitMethod_label;

		internal MMComboEdit cboInitMethod;

		internal MMLabel lbtu_label;

		internal MMVariableEdit lbtu;

		internal MMCheckBox chkOneDSearch;

		internal MMCheckBox chkMethod;

		internal MMGroupBox fraMaxIterations;

		internal MMLabel spnInitMaxit_label;

		internal MMSpinBox spnInitMaxit;

		internal MMLabel spnLoopMaxit_label;

		internal MMSpinBox spnLoopMaxit;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMGroupBox fraStepSize;

		internal MMLabel lbtuStepSize_label;

		internal MMVariableEdit lbtuStepSize;

		internal MMLabel lbtuNumericalDerivative_label;

		internal MMVariableEdit lbtuNumericalDerivative;

		internal MMCheckBox chkTestStability;

		private bool _contentLoaded;

		public MMRegress_Inp_Algorithm()
		{
			base.ViewModelType = typeof(MMRegress_Inp_Algorithm_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_algorithm.xaml", UriKind.Relative);
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
				fraOptions = (MMGroupBox)target;
				break;
			case 2:
				cboObjectFunction_label = (MMLabel)target;
				break;
			case 3:
				cboObjectFunction = (MMComboEdit)target;
				break;
			case 4:
				cboAlgorithm_label = (MMLabel)target;
				break;
			case 5:
				cboAlgorithm = (MMComboEdit)target;
				break;
			case 6:
				cboInitMethod_label = (MMLabel)target;
				break;
			case 7:
				cboInitMethod = (MMComboEdit)target;
				break;
			case 8:
				lbtu_label = (MMLabel)target;
				break;
			case 9:
				lbtu = (MMVariableEdit)target;
				break;
			case 10:
				chkOneDSearch = (MMCheckBox)target;
				break;
			case 11:
				chkMethod = (MMCheckBox)target;
				break;
			case 12:
				fraMaxIterations = (MMGroupBox)target;
				break;
			case 13:
				spnInitMaxit_label = (MMLabel)target;
				break;
			case 14:
				spnInitMaxit = (MMSpinBox)target;
				break;
			case 15:
				spnLoopMaxit_label = (MMLabel)target;
				break;
			case 16:
				spnLoopMaxit = (MMSpinBox)target;
				break;
			case 17:
				spnMaxit_label = (MMLabel)target;
				break;
			case 18:
				spnMaxit = (MMSpinBox)target;
				break;
			case 19:
				fraStepSize = (MMGroupBox)target;
				break;
			case 20:
				lbtuStepSize_label = (MMLabel)target;
				break;
			case 21:
				lbtuStepSize = (MMVariableEdit)target;
				break;
			case 22:
				lbtuNumericalDerivative_label = (MMLabel)target;
				break;
			case 23:
				lbtuNumericalDerivative = (MMVariableEdit)target;
				break;
			case 24:
				chkTestStability = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Inp_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMRegress_Inp_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMRegress_Inp_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMRegress_Inp_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMGegress_Inp_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMGegress_Inp_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_Diag")]
	public class MMRegress_Inp_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiagMessageLevel;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel labNbr0;

		internal MMLabel labNbr5;

		internal MMLabel labNbr10;

		internal MMLabel labSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel labProperty;

		internal MMSlider sldProperty;

		internal MMLabel labNbr0_b;

		internal MMLabel labNbr5_b;

		internal MMLabel labNbr10_b;

		private bool _contentLoaded;

		public MMRegress_Inp_Diag()
		{
			base.ViewModelType = typeof(MMRegress_Inp_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_diag.xaml", UriKind.Relative);
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
				fraDiagMessageLevel = (MMGroupBox)target;
				break;
			case 2:
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				labNbr0 = (MMLabel)target;
				break;
			case 5:
				labNbr5 = (MMLabel)target;
				break;
			case 6:
				labNbr10 = (MMLabel)target;
				break;
			case 7:
				labSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				labProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				labNbr0_b = (MMLabel)target;
				break;
			case 12:
				labNbr5_b = (MMLabel)target;
				break;
			case 13:
				labNbr10_b = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_Params")]
	public class MMRegress_Inp_Params : MMTabPagePastable, IComponentConnector
	{
		internal MMGroupBox fraParameters;

		internal MMScrollAreaMS grdParameters;

		internal MMCmdButton cmdCopy;

		internal MMCmdButton cmdPaste;

		internal MMCmdButton MMCmdClear;

		private bool _contentLoaded;

		public MMRegress_Inp_Params()
		{
			base.ViewModelType = typeof(MMRegress_Inp_Params_ViewModel);
			InitializeComponent();
			base.Loaded += MMRegress_Inp_Params_Loaded;
		}

		private void MMRegress_Inp_Params_Loaded(object sender, RoutedEventArgs e)
		{
		}

		private void grdParameters_DataCopying(object sender, MMScrollAreaDataCopyEventArgs e)
		{
			if (base.ViewModel is MMRegress_Inp_Params_ViewModel mMRegress_Inp_Params_ViewModel && mMRegress_Inp_Params_ViewModel.cmdCopy_Command.CanExecute(null))
			{
				mMRegress_Inp_Params_ViewModel.cmdCopy_Command.Execute(null);
				e.Handled = true;
			}
		}

		private void grdParameters_DataPasting(object sender, MMScrollAreaDataPasteEventArgs e)
		{
			if (grdParameters.SelectedRowsCount > 0 && base.ViewModel is MMRegress_Inp_Params_ViewModel mMRegress_Inp_Params_ViewModel && mMRegress_Inp_Params_ViewModel.cmdPaste_Command.CanExecute(null))
			{
				mMRegress_Inp_Params_ViewModel.cmdPaste_Command.Execute(null);
				e.Handled = true;
			}
		}

		private void grdParameters_CanPasteChecking(object sender, MMScrollAreaCanPasteCheckingEventArgs e)
		{
			if (base.ViewModel is MMRegress_Inp_Params_ViewModel mMRegress_Inp_Params_ViewModel && mMRegress_Inp_Params_ViewModel.cmdPaste_Command.CanExecute(null))
			{
				e.CanPaste = true;
				e.Handled = true;
			}
		}

		protected override bool IsAllowedPasteTarget(DragEventArgs e)
		{
			bool flag = base.IsAllowedPasteTarget(e);
			if (!flag)
			{
				flag = Utilities.GetAncestorFromType(e.OriginalSource as DependencyObject, typeof(MMScrollAreaMS), allowSubclassOfType: false) is MMScrollAreaMS mMScrollAreaMS && string.Equals(mMScrollAreaMS.Name, "grdParameters");
			}
			return flag;
		}

		public override bool OnRibbonCopy()
		{
			if (base.ViewModel != null)
			{
				return (base.ViewModel as MMRegress_Inp_Params_ViewModel).ExecuteCopy();
			}
			return base.OnRibbonCopy();
		}

		public override bool OnRibbonCanPaste()
		{
			if (base.ViewModel != null)
			{
				return (base.ViewModel as MMRegress_Inp_Params_ViewModel).cmdPaste_Command.CanExecute(null);
			}
			return base.OnRibbonCanPaste();
		}

		public override bool OnRibbonPaste()
		{
			if (base.ViewModel != null)
			{
				return (base.ViewModel as MMRegress_Inp_Params_ViewModel).ExecutePaste();
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_params.xaml", UriKind.Relative);
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
				fraParameters = (MMGroupBox)target;
				break;
			case 2:
				grdParameters = (MMScrollAreaMS)target;
				break;
			case 3:
				cmdCopy = (MMCmdButton)target;
				break;
			case 4:
				cmdPaste = (MMCmdButton)target;
				break;
			case 5:
				MMCmdClear = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Inp_Report_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMRegress_Inp_Report_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.OPTIONS",
			AllowSort = false
		});

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_Report")]
	public class MMRegress_Inp_Report : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMRegress_Inp_Report()
		{
			base.ViewModelType = typeof(MMRegress_Inp_Report_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_report.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPicker)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_Setup")]
	public class MMRegress_Inp_Setup : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPropertyOptions;

		internal MMLabel cboMethod_label;

		internal MMComboEdit cboMethod;

		internal MMLabel cboHenryComps_label;

		internal MMComboEdit cboHenryComps;

		internal MMLabel cboChemID_label;

		internal MMComboEdit cboChemID;

		internal MMCheckBox chkTrueComponents;

		internal MMGroupBox fraCalculation;

		internal MMOptionGroup ogrCalcType;

		internal MMOptionButton ogrCalcType_opt0;

		internal MMOptionButton ogrCalcType_opt1;

		internal MMGroupBox MMFrame1;

		internal MMTextBlock Label1;

		internal MMCheckBox analysisChk;

		internal MMGroupBox fraStuff;

		private bool _contentLoaded;

		public MMRegress_Inp_Setup()
		{
			base.ViewModelType = typeof(MMRegress_Inp_Setup_ViewModel);
			InitializeComponent();
			base.Loaded += MMRegress_Inp_Setup_Loaded;
		}

		private void MMRegress_Inp_Setup_Loaded(object sender, RoutedEventArgs e)
		{
			MMScrollAreaMS mMScrollAreaMS = new MMScrollAreaMS
			{
				Uid = "MMScrollArea_1",
				DataProperty = "grdStuff_GridData",
				Name = "grdStuff",
				DataContext = base.ViewModel
			};
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaComboValueField
			{
				VariableDataMember = "Value",
				PropertyPath = "cboDSID_var1",
				Width = 156.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel0
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaValueField
			{
				PropertyPath = "txtWeight_var1",
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel1
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaCheckBoxField
			{
				PropertyPath = "chkPerformTest_var1",
				MinWidth = 112.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel2
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaCheckBoxField
			{
				PropertyPath = "chkReject_var1",
				MinWidth = 0.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel3
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaComboValueField
			{
				PropertyPath = "cboTestMethod_MultiMap",
				Width = 110.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel4
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaValueField
			{
				PropertyPath = "txtAreaTolerance_var1",
				Width = 130.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel5
			});
			mMScrollAreaMS.MMFields.Add(new MMScrollAreaValueField
			{
				PropertyPath = "txtPointTolerance_var1",
				Width = 130.0,
				Label = ApwnResources.MMRegress_Inp_Setup_MMFLabel6
			});
			mMScrollAreaMS.Width = 0.0;
			fraStuff.Content = mMScrollAreaMS;
			mMScrollAreaMS.Width = 832.0;
			mMScrollAreaMS.MinWidth = 832.0;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_setup.xaml", UriKind.Relative);
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
				fraPropertyOptions = (MMGroupBox)target;
				break;
			case 2:
				cboMethod_label = (MMLabel)target;
				break;
			case 3:
				cboMethod = (MMComboEdit)target;
				break;
			case 4:
				cboHenryComps_label = (MMLabel)target;
				break;
			case 5:
				cboHenryComps = (MMComboEdit)target;
				break;
			case 6:
				cboChemID_label = (MMLabel)target;
				break;
			case 7:
				cboChemID = (MMComboEdit)target;
				break;
			case 8:
				chkTrueComponents = (MMCheckBox)target;
				break;
			case 9:
				fraCalculation = (MMGroupBox)target;
				break;
			case 10:
				ogrCalcType = (MMOptionGroup)target;
				break;
			case 11:
				ogrCalcType_opt0 = (MMOptionButton)target;
				break;
			case 12:
				ogrCalcType_opt1 = (MMOptionButton)target;
				break;
			case 13:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 14:
				Label1 = (MMTextBlock)target;
				break;
			case 15:
				analysisChk = (MMCheckBox)target;
				break;
			case 16:
				fraStuff = (MMGroupBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Inp_UModel_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration ogrEquationForm_MultiMap_Property = CxvPropertyDeclaration.Register("ogrEquationForm_MultiMap", typeof(MMRegress_Inp_UModel_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrEquationForm_var1",
					DataPath = "@main.Input.FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Normal",
					DisplayResourceKey = "MMRegress_Inp_UModel_ViewModel__CxvMultiMapOption_Display_Normal",
					Value = "ogrEquationForm_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrEquationForm_var1",
							Value = "NORMAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Logarithm",
					DisplayResourceKey = "MMRegress_Inp_UModel_ViewModel__CxvMultiMapOption_Display_Logarithm",
					Value = "ogrEquationForm_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrEquationForm_var1",
							Value = "LOG"
						}
					}
				}
			}
		});

		public object ogrEquationForm_MultiMap => GetValue(ogrEquationForm_MultiMap_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Inp_UModel")]
	public class MMRegress_Inp_UModel : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrEquationForm;

		internal MMOptionButton ogrEquationForm_opt0;

		internal MMOptionButton ogrEquationForm_opt1;

		private bool _contentLoaded;

		public MMRegress_Inp_UModel()
		{
			base.ViewModelType = typeof(MMRegress_Inp_UModel_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_inp_umodel.xaml", UriKind.Relative);
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
				ogrEquationForm = (MMOptionGroup)target;
				break;
			case 2:
				ogrEquationForm_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogrEquationForm_opt1 = (MMOptionButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration DATASETIDX_Property = CxvPropertyDeclaration.Register("DATASETIDX", typeof(MMRegress_Out_ViewModel), new CxvParameterProperty
		{
			Parameter = "DATASETIDX"
		});

		public static readonly CxvPropertyDeclaration EVALTAB1_Property = CxvPropertyDeclaration.Register("EVALTAB1", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EVALTAB1"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMRegress_Out_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration idx_Property = CxvPropertyDeclaration.Register("idx", typeof(MMRegress_Out_ViewModel), new CxvParameterProperty
		{
			Parameter = "idx"
		});

		public static readonly CxvPropertyDeclaration Consistency_Property = CxvPropertyDeclaration.Register("Consistency", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.LINE8"
		});

		public static readonly CxvPropertyDeclaration XProperty_Property = CxvPropertyDeclaration.Register("XProperty", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.PROPNAME2"
		});

		public static readonly CxvPropertyDeclaration Parameters_Property = CxvPropertyDeclaration.Register("Parameters", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.PARANAME"
		});

		public static readonly CxvPropertyDeclaration Residual_Property = CxvPropertyDeclaration.Register("Residual", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@Main.Output.AARD"
		});

		public static readonly CxvPropertyDeclaration Profiles_Property = CxvPropertyDeclaration.Register("Profiles", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TEMP"
		});

		public static readonly CxvPropertyDeclaration Profiles2_Property = CxvPropertyDeclaration.Register("Profiles2", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.LINE9"
		});

		public static readonly CxvPropertyDeclaration Correlation_Property = CxvPropertyDeclaration.Register("Correlation", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.VAL1.#0"
		});

		public static readonly CxvPropertyDeclaration SOS_Property = CxvPropertyDeclaration.Register("SOS", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.ALGOR"
		});

		public static readonly CxvPropertyDeclaration Evaluation_Property = CxvPropertyDeclaration.Register("Evaluation", typeof(MMRegress_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.SIGMAMX2"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Parameters" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Consistency" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Residual" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Profiles" }
		});

		public static readonly CxvPropertyDeclaration tabAnalysisPro_var_Property = CxvPropertyDeclaration.Register("tabAnalysisPro_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Profiles2" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Correlation" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Parameters" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@Evaluation" }
		});

		public static readonly CxvPropertyDeclaration tab7_var_Property = CxvPropertyDeclaration.Register("tab7_var", typeof(MMRegress_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@XProperty" }
		});

		public object DATASETIDX => GetValue(DATASETIDX_Property);

		public object EVALTAB1 => GetValue(EVALTAB1_Property);

		public object choice => GetValue(choice_Property);

		public object idx => GetValue(idx_Property);

		public object Consistency => GetValue(Consistency_Property);

		public object XProperty => GetValue(XProperty_Property);

		public new object Parameters => GetValue(Parameters_Property);

		public object Residual => GetValue(Residual_Property);

		public object Profiles => GetValue(Profiles_Property);

		public object Profiles2 => GetValue(Profiles2_Property);

		public object Correlation => GetValue(Correlation_Property);

		public object SOS => GetValue(SOS_Property);

		public object Evaluation => GetValue(Evaluation_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tabAnalysisPro_var => GetValue(tabAnalysisPro_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object tab7_var => GetValue(tab7_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out")]
	public class MMRegress_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab8;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tab6;

		internal MMTabItem tab7;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMRegress_Out()
		{
			base.ViewModelType = typeof(MMRegress_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
				tab8 = (MMTabItem)target;
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_AnalysisProfile")]
	public class MMRegress_Out_AnalysisProfile : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMGroupBox fraSummary;

		internal MMScrollAreaMS grdProfiles2;

		private bool _contentLoaded;

		public MMRegress_Out_AnalysisProfile()
		{
			base.ViewModelType = typeof(MMRegress_Out_AnalysisProfile_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_analysisprofile.xaml", UriKind.Relative);
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
				fraSummary = (MMGroupBox)target;
				break;
			case 4:
				grdProfiles2 = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Contest")]
	public class MMRegress_Out_Contest : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraConsistencyTests;

		internal MMScrollArea grdConsistencyTests;

		private bool _contentLoaded;

		public MMRegress_Out_Contest()
		{
			base.ViewModelType = typeof(MMRegress_Out_Contest_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_contest.xaml", UriKind.Relative);
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
				fraConsistencyTests = (MMGroupBox)target;
				break;
			case 2:
				grdConsistencyTests = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Corre")]
	public class MMRegress_Out_Corre : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraCorrelation;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMRegress_Out_Corre()
		{
			base.ViewModelType = typeof(MMRegress_Out_Corre_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_corre.xaml", UriKind.Relative);
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
				fraCorrelation = (MMGroupBox)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Eval")]
	public class MMRegress_Out_Eval : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraGeneral;

		internal MMLabel labPropOptionSet;

		internal MMTextEdit txtPropOptSet;

		internal MMLabel labWsos;

		internal MMValueEdit txtWSOS;

		internal MMLabel labMeanSqErr;

		internal MMValueEdit txtMeanSqErr;

		private bool _contentLoaded;

		public MMRegress_Out_Eval()
		{
			base.ViewModelType = typeof(MMRegress_Out_Eval_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_eval.xaml", UriKind.Relative);
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
				fraGeneral = (MMGroupBox)target;
				break;
			case 2:
				labPropOptionSet = (MMLabel)target;
				break;
			case 3:
				txtPropOptSet = (MMTextEdit)target;
				break;
			case 4:
				labWsos = (MMLabel)target;
				break;
			case 5:
				txtWSOS = (MMValueEdit)target;
				break;
			case 6:
				labMeanSqErr = (MMLabel)target;
				break;
			case 7:
				txtMeanSqErr = (MMValueEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Profile")]
	public class MMRegress_Out_Profile : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMGroupBox fraSummary;

		internal MMScrollAreaMS grdProfiles;

		private bool _contentLoaded;

		public MMRegress_Out_Profile()
		{
			base.ViewModelType = typeof(MMRegress_Out_Profile_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_profile.xaml", UriKind.Relative);
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
				fraSummary = (MMGroupBox)target;
				break;
			case 4:
				grdProfiles = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Out_RDev_DB_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMTextBox6_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox6_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AARD.@idx.#0"
		});

		public static readonly CxvPropertyDeclaration MMTextBox5_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox5_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.RMSREL.@idx.#0"
		});

		public static readonly CxvPropertyDeclaration MMTextBox4_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox4_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MAX_DEV.@idx.#0"
		});

		public static readonly CxvPropertyDeclaration MMTextBox3_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox3_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AAD.@idx.#0"
		});

		public static readonly CxvPropertyDeclaration MMTextBox2_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox2_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.RMS_DEV.@idx.#0"
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_VAR1_Property = CxvPropertyDeclaration.Register("MMTextBox1_VAR1", typeof(MMRegress_Out_RDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AVG_DEV.@idx.#0"
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

		public object MMTextBox6_VAR1 => GetValue(MMTextBox6_VAR1_Property);

		public object MMTextBox5_VAR1 => GetValue(MMTextBox5_VAR1_Property);

		public object MMTextBox4_VAR1 => GetValue(MMTextBox4_VAR1_Property);

		public object MMTextBox3_VAR1 => GetValue(MMTextBox3_VAR1_Property);

		public object MMTextBox2_VAR1 => GetValue(MMTextBox2_VAR1_Property);

		public object MMTextBox1_VAR1 => GetValue(MMTextBox1_VAR1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_RDev_DB")]
	public class MMRegress_Out_RDev_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMLabel1;

		internal MMValueEdit MMTextBox1;

		internal MMLabel MMLabel4;

		internal MMValueEdit MMTextBox4;

		internal MMLabel MMLabel2;

		internal MMValueEdit MMTextBox2;

		internal MMLabel MMLabel5;

		internal MMValueEdit MMTextBox5;

		internal MMLabel MMLabel3;

		internal MMValueEdit MMTextBox3;

		internal MMLabel MMLabel6;

		internal MMValueEdit MMTextBox6;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRegress_Out_RDev_DB()
		{
			base.ViewModelType = typeof(MMRegress_Out_RDev_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_rdev_db.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 3:
				MMTextBox1 = (MMValueEdit)target;
				break;
			case 4:
				MMLabel4 = (MMLabel)target;
				break;
			case 5:
				MMTextBox4 = (MMValueEdit)target;
				break;
			case 6:
				MMLabel2 = (MMLabel)target;
				break;
			case 7:
				MMTextBox2 = (MMValueEdit)target;
				break;
			case 8:
				MMLabel5 = (MMLabel)target;
				break;
			case 9:
				MMTextBox5 = (MMValueEdit)target;
				break;
			case 10:
				MMLabel3 = (MMLabel)target;
				break;
			case 11:
				MMTextBox3 = (MMValueEdit)target;
				break;
			case 12:
				MMLabel6 = (MMLabel)target;
				break;
			case 13:
				MMTextBox6 = (MMValueEdit)target;
				break;
			case 14:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class TxtIDDetailInfo
	{
		public string Name { get; set; }

		public int StartNumber { get; set; }

		public int EndNumber { get; set; }
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Residal")]
	public class MMRegress_Out_Residal : MMTabPage, IComponentConnector
	{
		internal MMCmdButton cmdPrev;

		internal MMCmdButton cmdNext;

		internal MMTextEdit txtL1;

		internal MMLabel labUnits;

		internal MMTextEdit txtL6;

		internal MMTextEdit txtL2;

		internal MMTextEdit txtL3;

		internal MMTextEdit txtL4;

		internal MMTextEdit txtL5;

		internal MMGroupBox fraResidual;

		internal MMScrollArea grdResidual;

		internal MMTextBlock MMFrame1;

		internal MMLabel MMLabel1;

		internal MMValueEdit MMTextBox1;

		internal MMLabel MMLabel4;

		internal MMValueEdit MMTextBox4;

		internal MMLabel MMLabel2;

		internal MMValueEdit MMTextBox2;

		internal MMLabel MMLabel5;

		internal MMValueEdit MMTextBox5;

		internal MMLabel MMLabel3;

		internal MMValueEdit MMTextBox3;

		internal MMLabel MMLabel6;

		internal MMValueEdit MMTextBox6;

		private bool _contentLoaded;

		public MMRegress_Out_Residal()
		{
			base.ViewModelType = typeof(MMRegress_Out_Residal_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_residal.xaml", UriKind.Relative);
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
				cmdPrev = (MMCmdButton)target;
				break;
			case 2:
				cmdNext = (MMCmdButton)target;
				break;
			case 3:
				txtL1 = (MMTextEdit)target;
				break;
			case 4:
				labUnits = (MMLabel)target;
				break;
			case 5:
				txtL6 = (MMTextEdit)target;
				break;
			case 6:
				txtL2 = (MMTextEdit)target;
				break;
			case 7:
				txtL3 = (MMTextEdit)target;
				break;
			case 8:
				txtL4 = (MMTextEdit)target;
				break;
			case 9:
				txtL5 = (MMTextEdit)target;
				break;
			case 10:
				fraResidual = (MMGroupBox)target;
				break;
			case 11:
				grdResidual = (MMScrollArea)target;
				break;
			case 12:
				MMFrame1 = (MMTextBlock)target;
				break;
			case 13:
				MMLabel1 = (MMLabel)target;
				break;
			case 14:
				MMTextBox1 = (MMValueEdit)target;
				break;
			case 15:
				MMLabel4 = (MMLabel)target;
				break;
			case 16:
				MMTextBox4 = (MMValueEdit)target;
				break;
			case 17:
				MMLabel2 = (MMLabel)target;
				break;
			case 18:
				MMTextBox2 = (MMValueEdit)target;
				break;
			case 19:
				MMLabel5 = (MMLabel)target;
				break;
			case 20:
				MMTextBox5 = (MMValueEdit)target;
				break;
			case 21:
				MMLabel3 = (MMLabel)target;
				break;
			case 22:
				MMTextBox3 = (MMValueEdit)target;
				break;
			case 23:
				MMLabel6 = (MMLabel)target;
				break;
			case 24:
				MMTextBox6 = (MMValueEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class DataSetDetailInfo
	{
		private IEnumerable<DataSetDetailInfo> _childTypeList;

		public bool IsGroupRow { get; set; }

		public string HeaderName { get; set; }

		public double WSOSValue { get; set; }

		public double IndexData { get; set; }

		public IEnumerable<DataSetDetailInfo> ChildTypeList
		{
			get
			{
				return _childTypeList;
			}
			set
			{
				_childTypeList = value;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Sos")]
	public class MMRegress_Out_Sos : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frGeneral;

		internal MMLabel labObjFunc;

		internal MMTextEdit txtObjFunc;

		internal MMLabel labAlgorithm;

		internal MMTextEdit txtAlgor;

		internal MMLabel labInitMethod;

		internal MMTextEdit txtInitMeth;

		internal MMLabel labWeighSumSq;

		internal MMValueEdit txtSigmamx;

		internal MMLabel labResidRMSErr;

		internal MMValueEdit txtSigma;

		internal GridControl gcResult;

		private bool _contentLoaded;

		public MMRegress_Out_Sos()
		{
			base.ViewModelType = typeof(MMRegress_Out_Sos_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_sos.xaml", UriKind.Relative);
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
				frGeneral = (MMGroupBox)target;
				break;
			case 2:
				labObjFunc = (MMLabel)target;
				break;
			case 3:
				txtObjFunc = (MMTextEdit)target;
				break;
			case 4:
				labAlgorithm = (MMLabel)target;
				break;
			case 5:
				txtAlgor = (MMTextEdit)target;
				break;
			case 6:
				labInitMethod = (MMLabel)target;
				break;
			case 7:
				txtInitMeth = (MMTextEdit)target;
				break;
			case 8:
				labWeighSumSq = (MMLabel)target;
				break;
			case 9:
				txtSigmamx = (MMValueEdit)target;
				break;
			case 10:
				labResidRMSErr = (MMLabel)target;
				break;
			case 11:
				txtSigma = (MMValueEdit)target;
				break;
			case 12:
				gcResult = (GridControl)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Summ")]
	public class MMRegress_Out_Summ : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraRegressedParameters;

		internal MMScrollArea grdSummary;

		internal MMTextEdit txtRstat;

		internal MMLabel labPropMethod;

		internal MMTextEdit txtPropertyMethod;

		private bool _contentLoaded;

		public MMRegress_Out_Summ()
		{
			base.ViewModelType = typeof(MMRegress_Out_Summ_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_summ.xaml", UriKind.Relative);
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
				fraRegressedParameters = (MMGroupBox)target;
				break;
			case 2:
				grdSummary = (MMScrollArea)target;
				break;
			case 3:
				txtRstat = (MMTextEdit)target;
				break;
			case 4:
				labPropMethod = (MMLabel)target;
				break;
			case 5:
				txtPropertyMethod = (MMTextEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegress_Out_XDev_DB_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration txtAvgAbsPct_VAR1_Property = CxvPropertyDeclaration.Register("txtAvgAbsPct_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AARD2.@idx"
		});

		public static readonly CxvPropertyDeclaration txtRmsErrPct_VAR1_Property = CxvPropertyDeclaration.Register("txtRmsErrPct_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.RMSREL2.@idx"
		});

		public static readonly CxvPropertyDeclaration txtMaxDev_VAR1_Property = CxvPropertyDeclaration.Register("txtMaxDev_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MAX_DEV2.@idx"
		});

		public static readonly CxvPropertyDeclaration txtAvgAbs_VAR1_Property = CxvPropertyDeclaration.Register("txtAvgAbs_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AAD2.@idx"
		});

		public static readonly CxvPropertyDeclaration txtRmsErr_VAR1_Property = CxvPropertyDeclaration.Register("txtRmsErr_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.RMS_DEV2.@idx"
		});

		public static readonly CxvPropertyDeclaration txtAvgDev_VAR1_Property = CxvPropertyDeclaration.Register("txtAvgDev_VAR1", typeof(MMRegress_Out_XDev_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.AVG_DEV2.@idx"
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

		public object txtAvgAbsPct_VAR1 => GetValue(txtAvgAbsPct_VAR1_Property);

		public object txtRmsErrPct_VAR1 => GetValue(txtRmsErrPct_VAR1_Property);

		public object txtMaxDev_VAR1 => GetValue(txtMaxDev_VAR1_Property);

		public object txtAvgAbs_VAR1 => GetValue(txtAvgAbs_VAR1_Property);

		public object txtRmsErr_VAR1 => GetValue(txtRmsErr_VAR1_Property);

		public object txtAvgDev_VAR1 => GetValue(txtAvgDev_VAR1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_XDev_DB")]
	public class MMRegress_Out_XDev_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraStats;

		internal MMLabel labAvgDev;

		internal MMValueEdit txtAvgDev;

		internal MMLabel labMaxDev;

		internal MMValueEdit txtMaxDev;

		internal MMLabel labRmsErr;

		internal MMValueEdit txtRmsErr;

		internal MMLabel labRmsErrPct;

		internal MMValueEdit txtRmsErrPct;

		internal MMLabel labAvgAbs;

		internal MMValueEdit txtAvgAbs;

		internal MMLabel labAvgAbsPct;

		internal MMValueEdit txtAvgAbsPct;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRegress_Out_XDev_DB()
		{
			base.ViewModelType = typeof(MMRegress_Out_XDev_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_xdev_db.xaml", UriKind.Relative);
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
				fraStats = (MMGroupBox)target;
				break;
			case 2:
				labAvgDev = (MMLabel)target;
				break;
			case 3:
				txtAvgDev = (MMValueEdit)target;
				break;
			case 4:
				labMaxDev = (MMLabel)target;
				break;
			case 5:
				txtMaxDev = (MMValueEdit)target;
				break;
			case 6:
				labRmsErr = (MMLabel)target;
				break;
			case 7:
				txtRmsErr = (MMValueEdit)target;
				break;
			case 8:
				labRmsErrPct = (MMLabel)target;
				break;
			case 9:
				txtRmsErrPct = (MMValueEdit)target;
				break;
			case 10:
				labAvgAbs = (MMLabel)target;
				break;
			case 11:
				txtAvgAbs = (MMValueEdit)target;
				break;
			case 12:
				labAvgAbsPct = (MMLabel)target;
				break;
			case 13:
				txtAvgAbsPct = (MMValueEdit)target;
				break;
			case 14:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	[ProgId("MMRegress.MMRegress_Out_Xprop")]
	public class MMRegress_Out_Xprop : MMTabPage, IComponentConnector
	{
		internal MMCmdButton cmdPrev;

		internal MMTextEdit MMTextBox1;

		internal MMCmdButton cmdNext;

		internal MMTextEdit txtID;

		internal MMTextEdit txtL1;

		internal MMGroupBox fraProfiles;

		internal MMScrollArea grdResidual;

		internal MMCmdButton CmdDeviations;

		private bool _contentLoaded;

		public MMRegress_Out_Xprop()
		{
			base.ViewModelType = typeof(MMRegress_Out_Xprop_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregress_out_xprop.xaml", UriKind.Relative);
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
				cmdPrev = (MMCmdButton)target;
				break;
			case 2:
				MMTextBox1 = (MMTextEdit)target;
				break;
			case 3:
				cmdNext = (MMCmdButton)target;
				break;
			case 4:
				txtID = (MMTextEdit)target;
				break;
			case 5:
				txtL1 = (MMTextEdit)target;
				break;
			case 6:
				fraProfiles = (MMGroupBox)target;
				break;
			case 7:
				grdResidual = (MMScrollArea)target;
				break;
			case 8:
				CmdDeviations = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Regression
{
	public class MMRegressResourceDictionary : ResourceDictionary, IComponentConnector, IStyleConnector
	{
		private static readonly MMRegressResourceDictionary Default = new MMRegressResourceDictionary();

		private static readonly DataTemplate GroupingReadonlyHyperlinkCellTemplate = Default.FindTemplate("groupingReadonlyHyperlinkCellTemplate");

		private bool _contentLoaded;

		public MMRegressResourceDictionary()
		{
			InitializeComponent();
		}

		private DataTemplate FindTemplate(string key)
		{
			return base[key] as DataTemplate;
		}

		public static DataTemplate ReturnDataTemplate(string key)
		{
			return Default.FindTemplate(key);
		}

		private void PART_GroupBorder_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			IDataCell dataCell = (sender as Border).DataContext as IDataCell;
			if (dataCell.Row.GroupingState == RowGroupingState.Expanded)
			{
				dataCell.Row.GroupingState = RowGroupingState.Collapsed;
			}
			else
			{
				dataCell.Row.GroupingState = RowGroupingState.Expanded;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/regression/mmregressresourcedictionary.xaml", UriKind.Relative);
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

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((Border)target).PreviewMouseLeftButtonDown += PART_GroupBorder_PreviewMouseLeftButtonDown;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Prop_Sets
{
	public class MMPropSets_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration propsets_Property = CxvPropertyDeclaration.Register("propsets", typeof(MMPropSets_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration qual_Property = CxvPropertyDeclaration.Register("qual", typeof(MMPropSets_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.QUAL"
		});

		public static readonly CxvPropertyDeclaration entqual_Property = CxvPropertyDeclaration.Register("entqual", typeof(MMPropSets_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTQUAL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPropSets_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@propsets" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPropSets_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@qual" },
			EnteredDataPaths = { "@entqual" }
		});

		private Visibility _prop_Visibility;

		public object propsets => GetValue(propsets_Property);

		public object qual => GetValue(qual_Property);

		public object entqual => GetValue(entqual_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public Visibility Prop_Visibility
		{
			get
			{
				return _prop_Visibility;
			}
			set
			{
				_prop_Visibility = value;
				OnPropertyChanged("Prop_Visibility");
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
				SetVisibilities();
			}
		}

		private void SetVisibilities()
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.ISPLUS", "value"));
			Prop_Visibility = ((text2 == "YES" && text != "FLOWSHEET") ? Visibility.Collapsed : Visibility.Visible);
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Prop_Sets
{
	[ProgId("MMPropSets.MMPropSets_Input")]
	public class MMPropSets_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPropSets;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPropSets_Input()
		{
			base.ViewModelType = typeof(MMPropSets_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/prop-sets/mmpropsets_input.xaml", UriKind.Relative);
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
				tabPropSets = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Prop_Sets
{
	[ProgId("MMPropSets.MMPropSets_Input_Properties")]
	public class MMPropSets_Input_Properties : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInformation;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel3;

		internal MMLabel cboSubstream_label;

		internal MMComboEdit cboSubstream;

		internal MMCmdButton cmdSearch;

		internal MMGroupBox fraProperties;

		internal MMScrollAreaMS grdSelection;

		private bool _contentLoaded;

		public MMPropSets_Input_Properties()
		{
			base.ViewModelType = typeof(MMPropSets_Input_Properties_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/prop-sets/mmpropsets_input_properties.xaml", UriKind.Relative);
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
				fraInformation = (MMGroupBox)target;
				break;
			case 2:
				MMLabel2 = (MMLabel)target;
				break;
			case 3:
				MMLabel3 = (MMLabel)target;
				break;
			case 4:
				cboSubstream_label = (MMLabel)target;
				break;
			case 5:
				cboSubstream = (MMComboEdit)target;
				break;
			case 6:
				cmdSearch = (MMCmdButton)target;
				break;
			case 7:
				fraProperties = (MMGroupBox)target;
				break;
			case 8:
				grdSelection = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Prop_Sets
{
	[ProgId("MMPropSets.MMPropSets_Input_Qualifiers")]
	public class MMPropSets_Input_Qualifiers : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaHorizontal grdQualifiers;

		internal MMScrollAreaValueField MMScrollAreaTemperatureField;

		internal MMScrollAreaValueField MMScrollAreaPressureField;

		internal MMLabel ltTBL_label;

		internal MMVariableEdit ltTBL;

		internal MMLabel ltTBU_label;

		internal MMVariableEdit ltTBU;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel ltBTBL_label;

		internal MMVariableEdit ltBTBL;

		internal MMLabel ltBTBU_label;

		internal MMVariableEdit ltBTBU;

		internal MMVariableEdit MMLBUText2;

		private bool _contentLoaded;

		public MMPropSets_Input_Qualifiers()
		{
			base.ViewModelType = typeof(MMPropSets_Input_Qualifiers_ViewModel);
			InitializeComponent();
		}

		internal void RefreshMMScrollAreaHorizontalCopyText(QualifiersScrollAreaFieldEnum scrollAreaFieldEnum, string modifyLabel)
		{
			switch (scrollAreaFieldEnum)
			{
			case QualifiersScrollAreaFieldEnum.TemperatureField:
				MMScrollAreaTemperatureField.Label = modifyLabel;
				break;
			case QualifiersScrollAreaFieldEnum.PressureField:
				MMScrollAreaPressureField.Label = modifyLabel;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/prop-sets/mmpropsets_input_qualifiers.xaml", UriKind.Relative);
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
				grdQualifiers = (MMScrollAreaHorizontal)target;
				break;
			case 2:
				MMScrollAreaTemperatureField = (MMScrollAreaValueField)target;
				break;
			case 3:
				MMScrollAreaPressureField = (MMScrollAreaValueField)target;
				break;
			case 4:
				ltTBL_label = (MMLabel)target;
				break;
			case 5:
				ltTBL = (MMVariableEdit)target;
				break;
			case 6:
				ltTBU_label = (MMLabel)target;
				break;
			case 7:
				ltTBU = (MMVariableEdit)target;
				break;
			case 8:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 9:
				ltBTBL_label = (MMLabel)target;
				break;
			case 10:
				ltBTBL = (MMVariableEdit)target;
				break;
			case 11:
				ltBTBU_label = (MMLabel)target;
				break;
			case 12:
				ltBTBU = (MMVariableEdit)target;
				break;
			case 13:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Prop_Sets
{
	internal enum QualifiersScrollAreaFieldEnum
	{
		TemperatureField,
		PressureField
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Ternary
{
	public class MMElecTer_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration param_Property = CxvPropertyDeclaration.Register("param", typeof(MMElecTer_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMElecTer_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@param" }
		});

		public object param => GetValue(param_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Ternary
{
	[ProgId("MMElecTer.MMElecTer_Input")]
	public class MMElecTer_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabElectrolyteTernary;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMElecTer_Input()
		{
			base.ViewModelType = typeof(MMElecTer_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/ternary/mmelecter_input.xaml", UriKind.Relative);
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
				tabElectrolyteTernary = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Ternary
{
	[ProgId("MMElecTer.MMElecTer_Input_Par")]
	public class MMElecTer_Input_Par : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLabel4;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel cboPropertyUnits_label;

		internal MMComboEdit cboPropertyUnits;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMLabel MMLabel1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMElecTer_Input_Par()
		{
			base.ViewModelType = typeof(MMElecTer_Input_Par_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/ternary/mmelecter_input_par.xaml", UriKind.Relative);
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
				MMLabel4 = (MMLabel)target;
				break;
			case 2:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 3:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 4:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 5:
				cboPropertyUnits_label = (MMLabel)target;
				break;
			case 6:
				cboPropertyUnits = (MMComboEdit)target;
				break;
			case 7:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 8:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 9:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 10:
				MMLabel1 = (MMLabel)target;
				break;
			case 11:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_UNIFAC_Groups
{
	[ProgId("MMResultsPureUni.MMResults_PureScaUni")]
	public class MMResults_PureScaUni : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel lblStatus;

		internal MMScrollAreaMS grdPureScaUniStatus;

		internal MMScrollAreaMS grdPureScaUniValue;

		private bool _contentLoaded;

		public MMResults_PureScaUni()
		{
			base.ViewModelType = typeof(MMResults_PureScaUni_ViewModel);
			InitializeComponent();
			grdPureScaUniStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdPureScaUniValue.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/pure%20unifac%20groups/mmresults_purescauni.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				lblStatus = (MMLabel)target;
				break;
			case 4:
				grdPureScaUniStatus = (MMScrollAreaMS)target;
				break;
			case 5:
				grdPureScaUniValue = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_UNIFAC_Groups
{
	public class MMResults_PureUni_ViewModel : MMTabPageViewModel
	{
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_UNIFAC_Groups
{
	[ProgId("MMResultsPureUni.MMResults_PureUni")]
	public class MMResults_PureUni : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResultsPure;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMResults_PureUni()
		{
			base.ViewModelType = typeof(MMResults_PureUni_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/pure%20unifac%20groups/mmresults_pureuni.xaml", UriKind.Relative);
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
				tabResultsPure = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_Components
{
	public class MMResults_Pure_ViewModel : MMTabPageViewModel
	{
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_Components
{
	[ProgId("MMResultsPure.MMResults_Pure")]
	public class MMResults_Pure : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResultsPure;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMResults_Pure()
		{
			base.ViewModelType = typeof(MMResults_Pure_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/pure%20components/mmresults_pure.xaml", UriKind.Relative);
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
				tabResultsPure = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_Components
{
	[ProgId("MMResultsPure.MMResults_PureSca")]
	public class MMResults_PureSca : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMCmdButton cmdCopyParameter;

		internal MMScrollAreaMS grdStatus;

		internal MMScrollAreaMS grdParameters;

		private bool _contentLoaded;

		public MMResults_PureSca()
		{
			base.ViewModelType = typeof(MMResults_PureSca_ViewModel);
			InitializeComponent();
			grdStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdParameters.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		private void MMTabPage_Loaded(object sender, RoutedEventArgs e)
		{
			InitializeGridControl();
		}

		private void InitializeGridControl()
		{
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/pure%20components/mmresults_puresca.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				cmdCopyParameter = (MMCmdButton)target;
				break;
			case 4:
				grdStatus = (MMScrollAreaMS)target;
				break;
			case 5:
				grdParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_Components
{
	public class GridRowItemDataSource
	{
		private string _itemComponent;

		private string _itemTemperatureUnites;

		private string _itemSource;

		private string _itemPropertyUnits;

		private List<double?> _itemElement = new List<double?>();

		public string itemComponent
		{
			get
			{
				return _itemComponent;
			}
			set
			{
				_itemComponent = value;
			}
		}

		public string itemTemperatureUnites
		{
			get
			{
				return _itemTemperatureUnites;
			}
			set
			{
				_itemTemperatureUnites = value;
			}
		}

		public string itemSource
		{
			get
			{
				return _itemSource;
			}
			set
			{
				_itemSource = value;
			}
		}

		public string itemPropertyUnits
		{
			get
			{
				return _itemPropertyUnits;
			}
			set
			{
				_itemPropertyUnits = value;
			}
		}

		public List<double?> itemElement => _itemElement;
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Pure_Components
{
	[ProgId("MMResultsPure.MMResults_PureTDep")]
	public class MMResults_PureTDep : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel advParameter_label;

		internal MMComboEdit advParameter;

		internal MMCmdButton cmdCopyParameter;

		internal MMScrollAreaMS grdStats;

		internal MMScrollAreaMS grdParameters;

		private bool _contentLoaded;

		public MMResults_PureTDep()
		{
			base.ViewModelType = typeof(MMResults_PureTDep_ViewModel);
			InitializeComponent();
			grdStats.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdParameters.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/pure%20components/mmresults_puretdep.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				advParameter_label = (MMLabel)target;
				break;
			case 4:
				advParameter = (MMComboEdit)target;
				break;
			case 5:
				cmdCopyParameter = (MMCmdButton)target;
				break;
			case 6:
				grdStats = (MMScrollAreaMS)target;
				break;
			case 7:
				grdParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.PublicComponent
{
	public class LegendBar : UserControl, IComponentConnector
	{
		private bool _contentLoaded;

		public LegendBar()
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/publiccomponent/legendbar.xaml", UriKind.Relative);
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Electrolyte_Pair
{
	public class MMResults_Pair_ViewModel : MMTabPageViewModel
	{
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Electrolyte_Pair
{
	[ProgId("MMResultsPair.MMResults_Pair")]
	public class MMResults_Pair : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPurecomp;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMResults_Pair()
		{
			base.ViewModelType = typeof(MMResults_Pair_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/electrolyte%20pair/mmresults_pair.xaml", UriKind.Relative);
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
				tabPurecomp = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Electrolyte_Pair
{
	[ProgId("MMResultsPair.MMResults_Pair_Params")]
	public class MMResults_Pair_Params : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		internal MMLabel MMLabel2;

		internal MMTextEdit MMTextBox8;

		internal MMScrollAreaMS grdSelection;

		private bool _contentLoaded;

		public MMResults_Pair_Params()
		{
			base.ViewModelType = typeof(MMResults_Pair_Params_ViewModel);
			InitializeComponent();
			grdSelection.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/electrolyte%20pair/mmresults_pair_params.xaml", UriKind.Relative);
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
				MMLabel2 = (MMLabel)target;
				break;
			case 4:
				MMTextBox8 = (MMTextEdit)target;
				break;
			case 5:
				grdSelection = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Converter
{
	public class ValueToColorConverter : IValueConverter
	{
		private Brush _blueColor;

		private Brush _yellowColor;

		private Brush _pinkColor;

		public ValueToColorConverter()
		{
			InitColors();
		}

		private void InitColors()
		{
			_blueColor = new SolidColorBrush(Color.FromRgb(231, 239, byte.MaxValue));
			_yellowColor = new SolidColorBrush(Color.FromRgb(byte.MaxValue, byte.MaxValue, 231));
			_pinkColor = new SolidColorBrush(Color.FromRgb(254, 245, byte.MaxValue));
		}

		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				string text = value.ToString().Trim();
				if (text.StartsWith("D"))
				{
					return _yellowColor;
				}
				if (text.StartsWith("S"))
				{
					return _blueColor;
				}
				if (text.StartsWith("M"))
				{
					return _pinkColor;
				}
				return new SolidColorBrush(Colors.LightGray);
			}
			return new SolidColorBrush(Colors.LightGray);
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Converter
{
	public class StatusDisplayConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				return (value as string) switch
				{
					"X" => "S", 
					"0" => "M", 
					_ => value, 
				};
			}
			return value;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_UNIFAC_Group
{
	[ProgId("MMResultsBinUni.MMResults_BinScaUni")]
	public class MMResults_BinScaUni : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel advParameters_label;

		internal MMComboEdit advParameters;

		internal MMLabel lblStatus;

		internal MMScrollAreaMS grdBinaryParametersStatus;

		internal MMScrollAreaMS grdBinaryParametersValue;

		private bool _contentLoaded;

		public MMResults_BinScaUni()
		{
			base.ViewModelType = typeof(MMResults_BinScaUni_ViewModel);
			InitializeComponent();
			grdBinaryParametersStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdBinaryParametersValue.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20unifac%20group/mmresults_binscauni.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				advParameters_label = (MMLabel)target;
				break;
			case 4:
				advParameters = (MMComboEdit)target;
				break;
			case 5:
				lblStatus = (MMLabel)target;
				break;
			case 6:
				grdBinaryParametersStatus = (MMScrollAreaMS)target;
				break;
			case 7:
				grdBinaryParametersValue = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_UNIFAC_Group
{
	[ProgId("MMResultsBinUni.MMResults_BinTDepUni")]
	public class MMResults_BinTDepUni : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel advParameter_label;

		internal MMComboEdit advParameter;

		internal MMLabel lblStatus;

		internal MMScrollAreaMS grdStatus;

		internal MMScrollAreaMS grdParameters;

		private bool _contentLoaded;

		public MMResults_BinTDepUni()
		{
			base.ViewModelType = typeof(MMResults_BinTDepUni_ViewModel);
			InitializeComponent();
			grdStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdParameters.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20unifac%20group/mmresults_bintdepuni.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				advParameter_label = (MMLabel)target;
				break;
			case 4:
				advParameter = (MMComboEdit)target;
				break;
			case 5:
				lblStatus = (MMLabel)target;
				break;
			case 6:
				grdStatus = (MMScrollAreaMS)target;
				break;
			case 7:
				grdParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_UNIFAC_Group
{
	public class MMResults_BinUni_ViewModel : MMTabPageViewModel
	{
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_UNIFAC_Group
{
	[ProgId("MMResultsBinUni.MMResults_BinUni")]
	public class MMResults_BinUni : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResultsPure;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMResults_BinUni()
		{
			base.ViewModelType = typeof(MMResults_BinUni_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20unifac%20group/mmresults_binuni.xaml", UriKind.Relative);
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
				tabResultsPure = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_Interaction
{
	public class MMResults_Binary_ViewModel : MMTabPageViewModel
	{
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_Interaction
{
	[ProgId("MMResultsBinary.MMResults_Binary")]
	public class MMResults_Binary : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResultsPure;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMResults_Binary()
		{
			base.ViewModelType = typeof(MMResults_Binary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20interaction/mmresults_binary.xaml", UriKind.Relative);
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
				tabResultsPure = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_Interaction
{
	[ProgId("MMResultsBinary.MMResults_BinarySca")]
	public class MMResults_BinarySca : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel advParameters_label;

		internal MMComboEdit advParameters;

		internal MMScrollAreaMS grdBinaryParametersValue;

		internal MMScrollAreaMS grdBinaryParametersStatus;

		private bool _contentLoaded;

		public MMResults_BinarySca()
		{
			base.ViewModelType = typeof(MMResults_BinarySca_ViewModel);
			InitializeComponent();
			grdBinaryParametersStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdBinaryParametersValue.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20interaction/mmresults_binarysca.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				advParameters_label = (MMLabel)target;
				break;
			case 4:
				advParameters = (MMComboEdit)target;
				break;
			case 5:
				grdBinaryParametersValue = (MMScrollAreaMS)target;
				break;
			case 6:
				grdBinaryParametersStatus = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Results.Binary_Interaction
{
	[ProgId("MMResultsBinary.MMResults_BinaryTDep")]
	public class MMResults_BinaryTDep : MMTabPage, IComponentConnector
	{
		internal MMLabel advView_label;

		internal MMComboEdit advView;

		internal MMLabel advParameter_label;

		internal MMComboEdit advParameter;

		internal MMScrollAreaMS grdStatus;

		internal MMScrollAreaMS grdValues;

		private bool _contentLoaded;

		public MMResults_BinaryTDep()
		{
			base.ViewModelType = typeof(MMResults_BinaryTDep_ViewModel);
			InitializeComponent();
			grdStatus.DataRetriever = new ReadOnlyViewModelDataRetriever();
			grdValues.DataRetriever = new ReadOnlyViewModelDataRetriever();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/results/binary%20interaction/mmresults_binarytdep.xaml", UriKind.Relative);
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
				advView_label = (MMLabel)target;
				break;
			case 2:
				advView = (MMComboEdit)target;
				break;
			case 3:
				advParameter_label = (MMLabel)target;
				break;
			case 4:
				advParameter = (MMComboEdit)target;
				break;
			case 5:
				grdStatus = (MMScrollAreaMS)target;
				break;
			case 6:
				grdValues = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_UNIFAC_Groups
{
	public class MMParam_PureUni_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration data_Property = CxvPropertyDeclaration.Register("data", typeof(MMParam_PureUni_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DATA"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_PureUni_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@data" }
		});

		public object data => GetValue(data_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_UNIFAC_Groups
{
	[ProgId("MMParam_PureUni.MMParam_PureUni_Input")]
	public class MMParam_PureUni_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPureUnifac;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_PureUni_Input()
		{
			base.ViewModelType = typeof(MMParam_PureUni_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20unifac%20groups/mmparam_pureuni_input.xaml", UriKind.Relative);
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
				tabPureUnifac = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_UNIFAC_Groups
{
	[ProgId("MMParam_PureUni.MMParam_PureUni_Input_Par")]
	public class MMParam_PureUni_In_Par : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollAreaMS MMScrollArea1;

		private bool _contentLoaded;

		public MMParam_PureUni_In_Par()
		{
			base.ViewModelType = typeof(MMParam_PureUni_In_Par_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20unifac%20groups/mmparam_pureuni_in_par.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.T_Dependent
{
	public class MMParam_PureCor_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration para_Property = CxvPropertyDeclaration.Register("para", typeof(MMParam_PureCor_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_PureCor_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@para" }
		});

		public object para => GetValue(para_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.T_Dependent
{
	[ProgId("MMParam_PureCor.MMParam_PureCor_In")]
	public class MMParam_PureCor_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tabNew;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_PureCor_In()
		{
			base.ViewModelType = typeof(MMParam_PureCor_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20components/t-dependent/mmparam_purecor_in.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
				break;
			case 2:
				tabNew = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.T_Dependent
{
	[ProgId("MMParam_PureCor.MMParam_PureCor_In_Para")]
	public class MMParam_PureCor_In_Para : MMTabPage, IComponentConnector
	{
		private bool _isInitializing = true;

		internal MMLabel MMLabel1;

		internal MMTextEdit txtRecordType;

		internal MMCmdButton cmdParameterhelp_1;

		internal MMLabel lblDataSet;

		internal MMTextEdit txtDataSet;

		internal MMGroupBox fraVaporPressureCorrelationParameters;

		internal MMScrollAreaMS grdNRTLInteractionParameters;

		private bool _contentLoaded;

		public bool IsInitializing
		{
			get
			{
				return _isInitializing;
			}
			private set
			{
				_isInitializing = value;
			}
		}

		public MMParam_PureCor_In_Para()
		{
			base.ViewModelType = typeof(MMParam_PureCor_In_Para_ViewModel);
			InitializeComponent();
			base.Dispatcher.BeginInvoke(DispatcherPriority.Input, (Action)delegate
			{
				IsInitializing = false;
			});
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20components/t-dependent/mmparam_purecor_in_para.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 2:
				txtRecordType = (MMTextEdit)target;
				break;
			case 3:
				cmdParameterhelp_1 = (MMCmdButton)target;
				break;
			case 4:
				lblDataSet = (MMLabel)target;
				break;
			case 5:
				txtDataSet = (MMTextEdit)target;
				break;
			case 6:
				fraVaporPressureCorrelationParameters = (MMGroupBox)target;
				break;
			case 7:
				grdNRTLInteractionParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.Scalar
{
	public class MMParam_PureSca_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration para_Property = CxvPropertyDeclaration.Register("para", typeof(MMParam_PureSca_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_PureSca_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@para" }
		});

		public object para => GetValue(para_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.Scalar
{
	[ProgId("MMParam_PureSca.MMParam_PureSca_In")]
	public class MMParam_PureSca_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_PureSca_In()
		{
			base.ViewModelType = typeof(MMParam_PureSca_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20components/scalar/mmparam_puresca_in.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.NC_Params
{
	public class MMNCParam_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMNCParam_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration param_Property = CxvPropertyDeclaration.Register("param", typeof(MMNCParam_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMNCParam_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@param" }
		});

		public object choice => GetValue(choice_Property);

		public object param => GetValue(param_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.NC_Params
{
	[ProgId("MMNCParam.MMNCParam_Input")]
	public class MMNCParam_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabNCParameters;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMNCParam_Input()
		{
			base.ViewModelType = typeof(MMNCParam_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20components/nc-params/mmncparam_input.xaml", UriKind.Relative);
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
				tabNCParameters = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Pure_Components.NC_Params
{
	[ProgId("MMNCParam.MMNCParam_Input_Param")]
	public class MMNCParam_Input_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuNCParameter_label;

		internal MMAdvancedComboEdit mnuNCParameter;

		internal MMComboEdit cboPropertyUnits;

		internal MMLabel cboTempUnits_label;

		internal MMComboEdit cboTempUnits;

		internal MMGroupBox fraNonconventionalParameters;

		internal MMScrollArea grdNonConventionalParameters;

		private bool _contentLoaded;

		public MMNCParam_Input_Param()
		{
			base.ViewModelType = typeof(MMNCParam_Input_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/pure%20components/nc-params/mmncparam_input_param.xaml", UriKind.Relative);
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
				mnuNCParameter_label = (MMLabel)target;
				break;
			case 2:
				mnuNCParameter = (MMAdvancedComboEdit)target;
				break;
			case 3:
				cboPropertyUnits = (MMComboEdit)target;
				break;
			case 4:
				cboTempUnits_label = (MMLabel)target;
				break;
			case 5:
				cboTempUnits = (MMComboEdit)target;
				break;
			case 6:
				fraNonconventionalParameters = (MMGroupBox)target;
				break;
			case 7:
				grdNonConventionalParameters = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Electrolyte_Pair
{
	public class MMParam_Pair_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMParam_Pair_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration passed_Property = CxvPropertyDeclaration.Register("passed", typeof(MMParam_Pair_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration para_Property = CxvPropertyDeclaration.Register("para", typeof(MMParam_Pair_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMParam_Pair_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDB"
		});

		public static readonly CxvPropertyDeclaration accessdb_Property = CxvPropertyDeclaration.Register("accessdb", typeof(MMParam_Pair_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCESSDBE"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_Pair_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@para" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMParam_Pair_Input_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accessdb" },
			EnteredDataPaths = { "@entdb" }
		});

		public object choice => GetValue(choice_Property);

		public object passed => GetValue(passed_Property);

		public object para => GetValue(para_Property);

		public object entdb => GetValue(entdb_Property);

		public object accessdb => GetValue(accessdb_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Electrolyte_Pair
{
	[ProgId("MMParam_Pair.MMParam_Pair_Input")]
	public class MMParam_Pair_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPurecomp;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_Pair_Input()
		{
			base.ViewModelType = typeof(MMParam_Pair_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/electrolyte%20pair/mmparam_pair_input.xaml", UriKind.Relative);
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
				tabPurecomp = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Electrolyte_Pair
{
	public class MMParam_Pair_Input_Data_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration mnuBDBank_var2_Property = CxvPropertyDeclaration.Register("mnuBDBank_var2", typeof(MMParam_Pair_Input_Data_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration mnuBDBank_var1_Property = CxvPropertyDeclaration.Register("mnuBDBank_var1", typeof(MMParam_Pair_Input_Data_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.BDBANK",
			SelectedItemBinding = "mnuBDBank_var2.Value"
		});

		public static readonly CxvPropertyDeclaration lstpDatabanks_bdbank_Property = CxvPropertyDeclaration.Register("lstpDatabanks_bdbank", typeof(MMParam_Pair_Input_Data_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.BDBANK.#0"
		});

		public object mnuBDBank_var2 => GetValue(mnuBDBank_var2_Property);

		public object mnuBDBank_var1 => GetValue(mnuBDBank_var1_Property);

		public object lstpDatabanks_bdbank => GetValue(lstpDatabanks_bdbank_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Electrolyte_Pair
{
	[ProgId("MMParam_Pair.MMParam_Pair_Input_Data")]
	public class MMParam_Pair_Input_Data : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpDatabanks;

		internal MMLabel mnuBDBank_label;

		internal MMAdvancedComboEdit mnuBDBank;

		private bool _contentLoaded;

		public MMParam_Pair_Input_Data()
		{
			base.ViewModelType = typeof(MMParam_Pair_Input_Data_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/electrolyte%20pair/mmparam_pair_input_data.xaml", UriKind.Relative);
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
				lstpDatabanks = (MMListPicker)target;
				break;
			case 2:
				mnuBDBank_label = (MMLabel)target;
				break;
			case 3:
				mnuBDBank = (MMAdvancedComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Electrolyte_Pair
{
	[ProgId("MMParam_Pair.MMParam_Pair_Input_Param")]
	public class MMParam_Pair_Input_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLabel1;

		internal MMTextEdit txtRecordType;

		internal MMAdvancedComboEdit mnuElecPairParam;

		internal MMLabel lblDataSet;

		internal MMValueEdit txtDataSet;

		internal MMLabel lblTempUnit;

		internal MMComboEdit cboTempUnits;

		internal MMGroupBox fraParameters;

		internal MMScrollArea grdSelection;

		internal MMScrollAreaHeaderOnlyField header1;

		internal MMScrollAreaComboValueField comboField1;

		internal MMScrollAreaHeaderOnlyField header2;

		internal MMScrollAreaComboValueField comboField3;

		private bool _contentLoaded;

		public MMParam_Pair_Input_Param()
		{
			base.ViewModelType = typeof(MMParam_Pair_Input_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/electrolyte%20pair/mmparam_pair_input_param.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 2:
				txtRecordType = (MMTextEdit)target;
				break;
			case 3:
				mnuElecPairParam = (MMAdvancedComboEdit)target;
				break;
			case 4:
				lblDataSet = (MMLabel)target;
				break;
			case 5:
				txtDataSet = (MMValueEdit)target;
				break;
			case 6:
				lblTempUnit = (MMLabel)target;
				break;
			case 7:
				cboTempUnits = (MMComboEdit)target;
				break;
			case 8:
				fraParameters = (MMGroupBox)target;
				break;
			case 9:
				grdSelection = (MMScrollArea)target;
				break;
			case 10:
				header1 = (MMScrollAreaHeaderOnlyField)target;
				break;
			case 11:
				comboField1 = (MMScrollAreaComboValueField)target;
				break;
			case 12:
				header2 = (MMScrollAreaHeaderOnlyField)target;
				break;
			case 13:
				comboField3 = (MMScrollAreaComboValueField)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.T_Dependent
{
	public class MMBiUNI_Cor_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration accessdb_Property = CxvPropertyDeclaration.Register("accessdb", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCESSDB.@choice"
		});

		public static readonly CxvPropertyDeclaration passed_Property = CxvPropertyDeclaration.Register("passed", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration para_Property = CxvPropertyDeclaration.Register("para", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBiUNI_Cor_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@para" }
		});

		public object choice => GetValue(choice_Property);

		public object accessdb => GetValue(accessdb_Property);

		public object passed => GetValue(passed_Property);

		public object para => GetValue(para_Property);

		public object entdb => GetValue(entdb_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.T_Dependent
{
	[ProgId("MMBiUni_Cor.MMBiUNI_Cor_Inp")]
	public class MMBiUNI_Cor_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMBiUNI_Cor_Inp()
		{
			base.ViewModelType = typeof(MMBiUNI_Cor_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20unifac%20group/t-dependent/mmbiuni_cor_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.T_Dependent
{
	[ProgId("MMBiUni_Cor.MMBiUNI_Cor_Inp_Param")]
	public class MMBiUNI_Cor_Inp_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLabel1;

		internal MMTextEdit txtRecordType;

		internal MMLabel mnuParamBiCorParam_label;

		internal MMAdvancedComboEdit mnuParamBiCorParam;

		internal MMLabel lblDataset;

		internal MMValueEdit txtDataSet;

		internal MMCmdButton cmdDechema;

		internal MMGroupBox fraNRTLInteractionParameters;

		internal MMScrollAreaMS grdNRTLInteractionParameters;

		internal MMCheckBox chkEstMissingParamByUNIFAC;

		private bool _contentLoaded;

		public MMBiUNI_Cor_Inp_Param()
		{
			base.ViewModelType = typeof(MMBiUNI_Cor_Inp_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20unifac%20group/t-dependent/mmbiuni_cor_inp_param.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 2:
				txtRecordType = (MMTextEdit)target;
				break;
			case 3:
				mnuParamBiCorParam_label = (MMLabel)target;
				break;
			case 4:
				mnuParamBiCorParam = (MMAdvancedComboEdit)target;
				break;
			case 5:
				lblDataset = (MMLabel)target;
				break;
			case 6:
				txtDataSet = (MMValueEdit)target;
				break;
			case 7:
				cmdDechema = (MMCmdButton)target;
				break;
			case 8:
				fraNRTLInteractionParameters = (MMGroupBox)target;
				break;
			case 9:
				grdNRTLInteractionParameters = (MMScrollAreaMS)target;
				break;
			case 10:
				chkEstMissingParamByUNIFAC = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.Scalar
{
	public class MMBiUNI_Sca_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration accessdb_Property = CxvPropertyDeclaration.Register("accessdb", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCESSDB"
		});

		public static readonly CxvPropertyDeclaration passed_Property = CxvPropertyDeclaration.Register("passed", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration param_Property = CxvPropertyDeclaration.Register("param", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBiUNI_Sca_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@param" }
		});

		public object choice => GetValue(choice_Property);

		public object accessdb => GetValue(accessdb_Property);

		public object passed => GetValue(passed_Property);

		public object param => GetValue(param_Property);

		public object entdb => GetValue(entdb_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.Scalar
{
	[ProgId("MMBiUni_Sca.MMBiUNI_Sca_Inp")]
	public class MMBiUNI_Sca_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMBiUNI_Sca_Inp()
		{
			base.ViewModelType = typeof(MMBiUNI_Sca_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20unifac%20group/scalar/mmbiuni_sca_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_UNIFAC_Group.Scalar
{
	[ProgId("MMBiUni_Sca.MMBiUNI_Sca_Inp_Param")]
	public class MMBiUNI_Sca_Inp_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLabel1;

		internal MMTextEdit txtRecordType;

		internal MMLabel mnuValue_label;

		internal MMAdvancedComboEdit mnuValue;

		internal MMLabel lblDataSet;

		internal MMValueEdit txtDataset;

		internal MMLabel lblUnits;

		internal MMComboEdit cboPropertyUnits;

		internal MMGroupBox frarackettLiquidMolarVolumeParameters;

		internal MMScrollAreaMS grdBinaryParameters;

		private bool _contentLoaded;

		public MMBiUNI_Sca_Inp_Param()
		{
			base.ViewModelType = typeof(MMBiUNI_Sca_Inp_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20unifac%20group/scalar/mmbiuni_sca_inp_param.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 2:
				txtRecordType = (MMTextEdit)target;
				break;
			case 3:
				mnuValue_label = (MMLabel)target;
				break;
			case 4:
				mnuValue = (MMAdvancedComboEdit)target;
				break;
			case 5:
				lblDataSet = (MMLabel)target;
				break;
			case 6:
				txtDataset = (MMValueEdit)target;
				break;
			case 7:
				lblUnits = (MMLabel)target;
				break;
			case 8:
				cboPropertyUnits = (MMComboEdit)target;
				break;
			case 9:
				frarackettLiquidMolarVolumeParameters = (MMGroupBox)target;
				break;
			case 10:
				grdBinaryParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	public class MMParam_Bi_Cor_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration accessdb_Property = CxvPropertyDeclaration.Register("accessdb", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCESSDB.@choice"
		});

		public static readonly CxvPropertyDeclaration passed_Property = CxvPropertyDeclaration.Register("passed", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration para_Property = CxvPropertyDeclaration.Register("para", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@para" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMParam_Bi_Cor_Inp_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accessdb" },
			EnteredDataPaths = { "@entdb" }
		});

		public object choice => GetValue(choice_Property);

		public object accessdb => GetValue(accessdb_Property);

		public object passed => GetValue(passed_Property);

		public object para => GetValue(para_Property);

		public object entdb => GetValue(entdb_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_Inp")]
	public class MMParam_Bi_Cor_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tabNew;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_Inp()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
				break;
			case 2:
				tabNew = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	public class MMParam_Bi_Cor_Inp_Data_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lstpDatabanks_bdbank_Property = CxvPropertyDeclaration.Register("lstpDatabanks_bdbank", typeof(MMParam_Bi_Cor_Inp_Data_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.BDBANK.@passed"
		});

		public static readonly CxvPropertyDeclaration mnuBDbank_var1_Property = CxvPropertyDeclaration.Register("mnuBDbank_var1", typeof(MMParam_Bi_Cor_Inp_Data_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.BDBANK",
			SelectedItemBinding = "mnuBDbank_var2.Value"
		});

		public static readonly CxvPropertyDeclaration mnuBDbank_var2_Property = CxvPropertyDeclaration.Register("mnuBDbank_var2", typeof(MMParam_Bi_Cor_Inp_Data_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public object lstpDatabanks_bdbank => GetValue(lstpDatabanks_bdbank_Property);

		public object mnuBDbank_var1 => GetValue(mnuBDbank_var1_Property);

		public object mnuBDbank_var2 => GetValue(mnuBDbank_var2_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.BDBANK.#0", "id"));
				if (!string.IsNullOrEmpty(value))
				{
					ResolveUpdateParameter("passed", value);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_Inp_Data")]
	public class MMParam_Bi_Cor_Inp_Data : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpDatabanks;

		internal MMLabel mnuBDbank_label;

		internal MMAdvancedComboEdit mnuBDbank;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_Inp_Data()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_Inp_Data_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_inp_data.xaml", UriKind.Relative);
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
				lstpDatabanks = (MMListPicker)target;
				break;
			case 2:
				mnuBDbank_label = (MMLabel)target;
				break;
			case 3:
				mnuBDbank = (MMAdvancedComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_Inp_Param")]
	public class MMParam_Bi_Cor_Inp_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel lblParameter;

		internal MMTextEdit txtRecordType;

		internal MMCmdButton cmdParameterhelp_1;

		internal MMLabel lblDataset;

		internal MMValueEdit txtDataSet;

		internal MMCmdButton cmdSwap;

		internal MMCmdButton cmdDechema;

		internal MMCheckBox chkEstMissingParamByUNIFAC;

		internal MMCmdButton CmdReginfo;

		internal MMCmdButton cmdSearch;

		internal MMGroupBox fraNRTLInteractionParameters;

		internal MMScrollAreaMS grdNRTLInteractionParameters;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_Inp_Param()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_Inp_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_inp_param.xaml", UriKind.Relative);
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
				lblParameter = (MMLabel)target;
				break;
			case 2:
				txtRecordType = (MMTextEdit)target;
				break;
			case 3:
				cmdParameterhelp_1 = (MMCmdButton)target;
				break;
			case 4:
				lblDataset = (MMLabel)target;
				break;
			case 5:
				txtDataSet = (MMValueEdit)target;
				break;
			case 6:
				cmdSwap = (MMCmdButton)target;
				break;
			case 7:
				cmdDechema = (MMCmdButton)target;
				break;
			case 8:
				chkEstMissingParamByUNIFAC = (MMCheckBox)target;
				break;
			case 9:
				CmdReginfo = (MMCmdButton)target;
				break;
			case 10:
				cmdSearch = (MMCmdButton)target;
				break;
			case 11:
				fraNRTLInteractionParameters = (MMGroupBox)target;
				break;
			case 12:
				grdNRTLInteractionParameters = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	public class LabelToIsUsedConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue && value is string)
			{
				return !string.IsNullOrEmpty(value as string);
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	public class MMParam_Bi_Cor_NRTL_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdOK_Command;

		private ICommand _cmdCancel_Command;

		public static readonly CxvPropertyDeclaration compi_var_Property = CxvPropertyDeclaration.Register("compi_var", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvParameterProperty
		{
			Parameter = "compi"
		});

		public static readonly CxvPropertyDeclaration compj_var_Property = CxvPropertyDeclaration.Register("compj_var", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvParameterProperty
		{
			Parameter = "compj"
		});

		public static readonly CxvPropertyDeclaration frmDechemaDB_paramname_Property = CxvPropertyDeclaration.Register("frmDechemaDB_paramname", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvParameterProperty
		{
			Parameter = "paramname"
		});

		public static readonly CxvPropertyDeclaration lbtuComponentj_componentj_Property = CxvPropertyDeclaration.Register("lbtuComponentj_componentj", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.IdWithOptions,
			DataPath = "@main.Input.VAL1.@choice.@z.#0",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration lbtuComponentI_var1_Property = CxvPropertyDeclaration.Register("lbtuComponentI_var1", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.IdWithOptions,
			DataPath = "@main.Input.VAL1.@choice.@z",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration LBLLE_Visible_Property = CxvPropertyDeclaration.Register("LBLLE_Visible", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Input.OPT_SOURCE.@choice.@z.#0",
					Value = "LLE"
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtu_var1_Property = CxvPropertyDeclaration.Register("lbtu_var1", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VALALPHA.@choice.@z.#0"
		});

		public static readonly CxvPropertyDeclaration lbtuAji_var1_Property = CxvPropertyDeclaration.Register("lbtuAji_var1", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VALJ.@choice.@z.#0"
		});

		public static readonly CxvPropertyDeclaration lbtuaij_var1_Property = CxvPropertyDeclaration.Register("lbtuaij_var1", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VALI.@choice.@z.#0"
		});

		public static readonly CxvPropertyDeclaration MMOptionGroup1_MultiMap_Property = CxvPropertyDeclaration.Register("MMOptionGroup1_MultiMap", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMOptionGroup1_var1",
					DataPath = "@main.Input.OPT_SOURCE.@choice.@z.#0"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "VLE",
					DisplayResourceKey = "MMParam_Bi_Cor_NRTL_ViewModel__CxvMultiMapOption_Display_VLE",
					Value = "MMOptionGroup1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMOptionGroup1_var1",
							Value = "VLE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "LLE",
					DisplayResourceKey = "MMParam_Bi_Cor_NRTL_ViewModel__CxvMultiMapOption_Display_LLE",
					Value = "MMOptionGroup1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMOptionGroup1_var1",
							Value = "LLE"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration LBVLE_Visible_Property = CxvPropertyDeclaration.Register("LBVLE_Visible", typeof(MMParam_Bi_Cor_NRTL_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Input.OPT_SOURCE.@choice.@z.#0",
					Value = "VLE"
				}
			}
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

		public object compi_var => GetValue(compi_var_Property);

		public object compj_var => GetValue(compj_var_Property);

		public object frmDechemaDB_paramname => GetValue(frmDechemaDB_paramname_Property);

		public object lbtuComponentj_componentj => GetValue(lbtuComponentj_componentj_Property);

		public object lbtuComponentI_var1 => GetValue(lbtuComponentI_var1_Property);

		public object LBLLE_Visible => GetValue(LBLLE_Visible_Property);

		public object lbtu_var1 => GetValue(lbtu_var1_Property);

		public object lbtuAji_var1 => GetValue(lbtuAji_var1_Property);

		public object lbtuaij_var1 => GetValue(lbtuaij_var1_Property);

		public object MMOptionGroup1_MultiMap => GetValue(MMOptionGroup1_MultiMap_Property);

		public object LBVLE_Visible => GetValue(LBVLE_Visible_Property);

		private void cmdOK_CommandExecute(object parameter)
		{
			string setting = CxsConverter.ValueToString(ResolveParameter("y"));
			string text = CxsConverter.ValueToString(ResolveParameter("z"));
			int columnNumber = 0;
			if (!string.IsNullOrEmpty(text))
			{
				columnNumber = int.Parse(text.Substring(1));
			}
			if (this.SMDechema(columnNumber, 1, setting) == 0)
			{
				ShowMessageBox(new ShowMessageBoxEventArgs
				{
					Message = AspenTech.AspenPlus.Localization.Properties.Resources.MsgBox_Message41,
					MsgBoxImage = MessageBoxImage.Hand,
					MsgBoxButton = MessageBoxButton.OK,
					Title = AspenTech.AspenPlus.Localization.Properties.Resources.MsgBox_Title_Error
				});
			}
			UpdateAll();
			string text2 = CxsConverter.ValueToString(ResolveParameter("choice"));
			ExpandDataPathAndSet("@main.Input.TUNITLABEL." + text2, "value", "K");
			CloseForm();
		}

		private void cmdCancel_CommandExecute(object parameter)
		{
			CloseForm();
		}

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				CxvVariableData cxvVariableData = lbtuComponentI_var1 as CxvVariableData;
				CxvVariableData cxvVariableData2 = lbtuComponentj_componentj as CxvVariableData;
				ResolveUpdateParameter("compi", cxvVariableData.Value);
				ResolveUpdateParameter("compj", cxvVariableData2.Value);
			}
			base.OnUpdateData();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_NRTL")]
	public class MMParam_Bi_Cor_NRTL : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmDechemaDB;

		internal MMLabel lbtuComponentI_label;

		internal MMVariableEdit lbtuComponentI;

		internal MMLabel lbtuComponentj_label;

		internal MMVariableEdit lbtuComponentj;

		internal MMOptionGroup MMOptionGroup1;

		internal MMOptionButton MMOptionGroup1_opt0;

		internal MMOptionButton MMOptionGroup1_opt1;

		internal MMLabel lbtuaij_label;

		internal MMLabel lbtuAji_label;

		internal MMLabel lbtu_label;

		internal MMVariableEdit lbtuaij;

		internal MMVariableEdit lbtuAji;

		internal MMVariableEdit lbtu;

		internal MMLabel MMLabel1_0;

		internal MMLabel lblUnitsi;

		internal MMLabel MMLabel2_1;

		internal MMLabel lblUnitsj;

		internal MMLabel lblRvalue;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_NRTL()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_NRTL_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_nrtl.xaml", UriKind.Relative);
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
				frmDechemaDB = (MMGroupBox)target;
				break;
			case 2:
				lbtuComponentI_label = (MMLabel)target;
				break;
			case 3:
				lbtuComponentI = (MMVariableEdit)target;
				break;
			case 4:
				lbtuComponentj_label = (MMLabel)target;
				break;
			case 5:
				lbtuComponentj = (MMVariableEdit)target;
				break;
			case 6:
				MMOptionGroup1 = (MMOptionGroup)target;
				break;
			case 7:
				MMOptionGroup1_opt0 = (MMOptionButton)target;
				break;
			case 8:
				MMOptionGroup1_opt1 = (MMOptionButton)target;
				break;
			case 9:
				lbtuaij_label = (MMLabel)target;
				break;
			case 10:
				lbtuAji_label = (MMLabel)target;
				break;
			case 11:
				lbtu_label = (MMLabel)target;
				break;
			case 12:
				lbtuaij = (MMVariableEdit)target;
				break;
			case 13:
				lbtuAji = (MMVariableEdit)target;
				break;
			case 14:
				lbtu = (MMVariableEdit)target;
				break;
			case 15:
				MMLabel1_0 = (MMLabel)target;
				break;
			case 16:
				lblUnitsi = (MMLabel)target;
				break;
			case 17:
				MMLabel2_1 = (MMLabel)target;
				break;
			case 18:
				lblUnitsj = (MMLabel)target;
				break;
			case 19:
				lblRvalue = (MMLabel)target;
				break;
			case 20:
				cmdOK = (MMCmdButton)target;
				break;
			case 21:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_Search")]
	public class MMParam_Bi_Cor_Search : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmSearchDB;

		internal MMLabel cboCID1_label;

		internal MMComboEdit cboCID1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMCmdButton cmdSearch;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_Search()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_Search_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_search.xaml", UriKind.Relative);
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
				frmSearchDB = (MMGroupBox)target;
				break;
			case 2:
				cboCID1_label = (MMLabel)target;
				break;
			case 3:
				cboCID1 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				cmdSearch = (MMCmdButton)target;
				break;
			case 7:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_UNIQ")]
	public class MMParam_Bi_Cor_UNIQ : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmDechemaDB;

		internal MMLabel lbtuComponentI_label;

		internal MMVariableEdit lbtuComponentI;

		internal MMLabel lbtuComponentj_label;

		internal MMVariableEdit lbtuComponentj;

		internal MMOptionGroup MMOptionGroup1;

		internal MMOptionButton MMOptionGroup1_opt0;

		internal MMOptionButton MMOptionGroup1_opt1;

		internal MMLabel lbtuaij_label;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit lbtuaij;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLabel1_1;

		internal MMLabel lblUnitsi;

		internal MMLabel MMLabel2_2;

		internal MMLabel lblUnitsj;

		internal MMLabel lblRvalue;

		internal MMTextBlock MMLabel1_0;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_UNIQ()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_UNIQ_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_uniq.xaml", UriKind.Relative);
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
				frmDechemaDB = (MMGroupBox)target;
				break;
			case 2:
				lbtuComponentI_label = (MMLabel)target;
				break;
			case 3:
				lbtuComponentI = (MMVariableEdit)target;
				break;
			case 4:
				lbtuComponentj_label = (MMLabel)target;
				break;
			case 5:
				lbtuComponentj = (MMVariableEdit)target;
				break;
			case 6:
				MMOptionGroup1 = (MMOptionGroup)target;
				break;
			case 7:
				MMOptionGroup1_opt0 = (MMOptionButton)target;
				break;
			case 8:
				MMOptionGroup1_opt1 = (MMOptionButton)target;
				break;
			case 9:
				lbtuaij_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 11:
				lbtuaij = (MMVariableEdit)target;
				break;
			case 12:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 13:
				MMLabel1_1 = (MMLabel)target;
				break;
			case 14:
				lblUnitsi = (MMLabel)target;
				break;
			case 15:
				MMLabel2_2 = (MMLabel)target;
				break;
			case 16:
				lblUnitsj = (MMLabel)target;
				break;
			case 17:
				lblRvalue = (MMLabel)target;
				break;
			case 18:
				MMLabel1_0 = (MMTextBlock)target;
				break;
			case 19:
				cmdOK = (MMCmdButton)target;
				break;
			case 20:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Cor_WIL")]
	public class MMParam_Bi_Cor_WIL : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmDechemaDB;

		internal MMLabel lbtuComponentI_label;

		internal MMVariableEdit lbtuComponentI;

		internal MMLabel lbtuComponentj_label;

		internal MMVariableEdit lbtuComponentj;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel lblcc_mol;

		internal MMLabel lbtuaij_label;

		internal MMVariableEdit lbtuaij;

		internal MMLabel lblUnitsi;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel lblccmol;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel lblUnitsj;

		internal MMLabel lblRvalue;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMParam_Bi_Cor_WIL()
		{
			base.ViewModelType = typeof(MMParam_Bi_Cor_WIL_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_cor_wil.xaml", UriKind.Relative);
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
				frmDechemaDB = (MMGroupBox)target;
				break;
			case 2:
				lbtuComponentI_label = (MMLabel)target;
				break;
			case 3:
				lbtuComponentI = (MMVariableEdit)target;
				break;
			case 4:
				lbtuComponentj_label = (MMLabel)target;
				break;
			case 5:
				lbtuComponentj = (MMVariableEdit)target;
				break;
			case 6:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 8:
				lblcc_mol = (MMLabel)target;
				break;
			case 9:
				lbtuaij_label = (MMLabel)target;
				break;
			case 10:
				lbtuaij = (MMVariableEdit)target;
				break;
			case 11:
				lblUnitsi = (MMLabel)target;
				break;
			case 12:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 13:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 14:
				lblccmol = (MMLabel)target;
				break;
			case 15:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 16:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 17:
				lblUnitsj = (MMLabel)target;
				break;
			case 18:
				lblRvalue = (MMLabel)target;
				break;
			case 19:
				cmdOK = (MMCmdButton)target;
				break;
			case 20:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Reg_Henry")]
	public class MMParam_Bi_Reg_Henry : MMTabPage, IComponentConnector
	{
		internal MMLabel databank;

		internal MMLabel Label1;

		internal MMLabel parameter;

		internal MMLabel Label2;

		internal MMLabel components;

		internal MMLabel Label3;

		internal MMLabel rangeofdata;

		internal Grid svGrid;

		internal MMLabel state;

		internal MMLabel range;

		internal MMLabel temp;

		internal MMLabel Label4;

		internal MMLabel Pres;

		internal MMLabel Label5;

		internal MMLabel Hconstant;

		internal MMLabel Label7;

		internal MMLabel Liquid;

		internal MMLabel Label6;

		internal MMLabel Label13;

		internal MMLabel resid;

		internal MMLabel Label8;

		internal MMLabel avedev;

		internal MMLabel adstate;

		internal MMLabel point;

		internal MMLabel relative;

		internal MMLabel abso;

		internal MMLabel max;

		internal MMLabel Hcondev;

		internal MMLabel Label9;

		internal MMLabel Label10;

		internal MMLabel Label11;

		internal MMLabel Label12;

		private bool _contentLoaded;

		public MMParam_Bi_Reg_Henry()
		{
			base.ViewModelType = typeof(MMParam_Bi_Reg_Henry_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_reg_henry.xaml", UriKind.Relative);
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
				databank = (MMLabel)target;
				break;
			case 2:
				Label1 = (MMLabel)target;
				break;
			case 3:
				parameter = (MMLabel)target;
				break;
			case 4:
				Label2 = (MMLabel)target;
				break;
			case 5:
				components = (MMLabel)target;
				break;
			case 6:
				Label3 = (MMLabel)target;
				break;
			case 7:
				rangeofdata = (MMLabel)target;
				break;
			case 8:
				svGrid = (Grid)target;
				break;
			case 9:
				state = (MMLabel)target;
				break;
			case 10:
				range = (MMLabel)target;
				break;
			case 11:
				temp = (MMLabel)target;
				break;
			case 12:
				Label4 = (MMLabel)target;
				break;
			case 13:
				Pres = (MMLabel)target;
				break;
			case 14:
				Label5 = (MMLabel)target;
				break;
			case 15:
				Hconstant = (MMLabel)target;
				break;
			case 16:
				Label7 = (MMLabel)target;
				break;
			case 17:
				Liquid = (MMLabel)target;
				break;
			case 18:
				Label6 = (MMLabel)target;
				break;
			case 19:
				Label13 = (MMLabel)target;
				break;
			case 20:
				resid = (MMLabel)target;
				break;
			case 21:
				Label8 = (MMLabel)target;
				break;
			case 22:
				avedev = (MMLabel)target;
				break;
			case 23:
				adstate = (MMLabel)target;
				break;
			case 24:
				point = (MMLabel)target;
				break;
			case 25:
				relative = (MMLabel)target;
				break;
			case 26:
				abso = (MMLabel)target;
				break;
			case 27:
				max = (MMLabel)target;
				break;
			case 28:
				Hcondev = (MMLabel)target;
				break;
			case 29:
				Label9 = (MMLabel)target;
				break;
			case 30:
				Label10 = (MMLabel)target;
				break;
			case 31:
				Label11 = (MMLabel)target;
				break;
			case 32:
				Label12 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Reg_LLE")]
	public class MMParam_Bi_Reg_LLE : MMTabPage, IComponentConnector
	{
		internal MMLabel databank;

		internal MMLabel Label1;

		internal MMLabel parameter;

		internal MMLabel Label2;

		internal MMLabel components;

		internal MMLabel Label3;

		internal MMLabel rangeofdata;

		internal Grid svGrid;

		internal MMLabel state;

		internal MMLabel range;

		internal MMLabel temp;

		internal MMLabel Label4;

		internal MMLabel liquidI;

		internal MMLabel Label17;

		internal MMLabel Label5;

		internal MMLabel LiquidII;

		internal MMLabel Label6;

		internal MMLabel Label7;

		internal MMLabel resid;

		internal MMLabel Label8;

		internal MMLabel avedev;

		internal Grid adGrid;

		internal MMLabel adstate;

		internal MMLabel point;

		internal MMLabel relative;

		internal MMLabel abso;

		internal MMLabel max;

		internal MMLabel LIdev;

		internal MMLabel Label9;

		internal MMLabel Label10;

		internal MMLabel Label11;

		internal MMLabel Label12;

		internal MMLabel LIIdev;

		internal MMLabel Label13;

		internal MMLabel Label14;

		internal MMLabel Label15;

		internal MMLabel Label16;

		private bool _contentLoaded;

		public MMParam_Bi_Reg_LLE()
		{
			base.ViewModelType = typeof(MMParam_Bi_Reg_LLE_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_reg_lle.xaml", UriKind.Relative);
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
				databank = (MMLabel)target;
				break;
			case 2:
				Label1 = (MMLabel)target;
				break;
			case 3:
				parameter = (MMLabel)target;
				break;
			case 4:
				Label2 = (MMLabel)target;
				break;
			case 5:
				components = (MMLabel)target;
				break;
			case 6:
				Label3 = (MMLabel)target;
				break;
			case 7:
				rangeofdata = (MMLabel)target;
				break;
			case 8:
				svGrid = (Grid)target;
				break;
			case 9:
				state = (MMLabel)target;
				break;
			case 10:
				range = (MMLabel)target;
				break;
			case 11:
				temp = (MMLabel)target;
				break;
			case 12:
				Label4 = (MMLabel)target;
				break;
			case 13:
				liquidI = (MMLabel)target;
				break;
			case 14:
				Label17 = (MMLabel)target;
				break;
			case 15:
				Label5 = (MMLabel)target;
				break;
			case 16:
				LiquidII = (MMLabel)target;
				break;
			case 17:
				Label6 = (MMLabel)target;
				break;
			case 18:
				Label7 = (MMLabel)target;
				break;
			case 19:
				resid = (MMLabel)target;
				break;
			case 20:
				Label8 = (MMLabel)target;
				break;
			case 21:
				avedev = (MMLabel)target;
				break;
			case 22:
				adGrid = (Grid)target;
				break;
			case 23:
				adstate = (MMLabel)target;
				break;
			case 24:
				point = (MMLabel)target;
				break;
			case 25:
				relative = (MMLabel)target;
				break;
			case 26:
				abso = (MMLabel)target;
				break;
			case 27:
				max = (MMLabel)target;
				break;
			case 28:
				LIdev = (MMLabel)target;
				break;
			case 29:
				Label9 = (MMLabel)target;
				break;
			case 30:
				Label10 = (MMLabel)target;
				break;
			case 31:
				Label11 = (MMLabel)target;
				break;
			case 32:
				Label12 = (MMLabel)target;
				break;
			case 33:
				LIIdev = (MMLabel)target;
				break;
			case 34:
				Label13 = (MMLabel)target;
				break;
			case 35:
				Label14 = (MMLabel)target;
				break;
			case 36:
				Label15 = (MMLabel)target;
				break;
			case 37:
				Label16 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Reg_NIST")]
	public class MMParam_Bi_Reg_NIST : MMTabPage, IComponentConnector
	{
		internal MMLabel databank;

		internal MMLabel Label1;

		internal MMLabel parameter;

		internal MMLabel Label2;

		internal MMLabel components;

		internal MMLabel Label3;

		internal MMLabel rangeofdata;

		internal Grid svGrid;

		internal MMLabel state;

		internal MMLabel range;

		internal MMLabel temp;

		internal MMLabel Label4;

		internal MMLabel pres;

		internal MMLabel Label5;

		internal MMLabel Lmolf;

		internal MMLabel Label6;

		internal MMLabel Label7;

		internal MMLabel resid;

		internal MMLabel Label8;

		internal MMLabel avedev;

		internal DataGrid adGrid;

		internal MMLabel lbl_citations;

		internal ListBox citationGrid;

		private bool _contentLoaded;

		public MMParam_Bi_Reg_NIST()
		{
			base.ViewModelType = typeof(MMParam_Bi_Reg_NIST_ViewModel);
			InitializeComponent();
		}

		private void citationGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			citationGrid.SelectedIndex = -1;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_reg_nist.xaml", UriKind.Relative);
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
				databank = (MMLabel)target;
				break;
			case 2:
				Label1 = (MMLabel)target;
				break;
			case 3:
				parameter = (MMLabel)target;
				break;
			case 4:
				Label2 = (MMLabel)target;
				break;
			case 5:
				components = (MMLabel)target;
				break;
			case 6:
				Label3 = (MMLabel)target;
				break;
			case 7:
				rangeofdata = (MMLabel)target;
				break;
			case 8:
				svGrid = (Grid)target;
				break;
			case 9:
				state = (MMLabel)target;
				break;
			case 10:
				range = (MMLabel)target;
				break;
			case 11:
				temp = (MMLabel)target;
				break;
			case 12:
				Label4 = (MMLabel)target;
				break;
			case 13:
				pres = (MMLabel)target;
				break;
			case 14:
				Label5 = (MMLabel)target;
				break;
			case 15:
				Lmolf = (MMLabel)target;
				break;
			case 16:
				Label6 = (MMLabel)target;
				break;
			case 17:
				Label7 = (MMLabel)target;
				break;
			case 18:
				resid = (MMLabel)target;
				break;
			case 19:
				Label8 = (MMLabel)target;
				break;
			case 20:
				avedev = (MMLabel)target;
				break;
			case 21:
				adGrid = (DataGrid)target;
				break;
			case 22:
				lbl_citations = (MMLabel)target;
				break;
			case 23:
				citationGrid = (ListBox)target;
				citationGrid.SelectionChanged += citationGrid_SelectionChanged;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.T_Dependent
{
	[ProgId("MMParam_Bi_Cor.MMParam_Bi_Reg_VLE")]
	public class MMParam_Bi_Reg_VLE : MMTabPage, IComponentConnector
	{
		internal MMLabel databank;

		internal MMLabel Label1;

		internal MMLabel parameter;

		internal MMLabel Label2;

		internal MMLabel components;

		internal MMLabel Label3;

		internal MMLabel rangeofdata;

		internal Grid svGrid;

		internal MMLabel state;

		internal MMLabel range;

		internal MMLabel temp;

		internal MMLabel Label4;

		internal MMLabel pres;

		internal MMLabel Label5;

		internal MMLabel Lmolf;

		internal MMLabel Label6;

		internal MMLabel Label7;

		internal MMLabel resid;

		internal MMLabel Label8;

		internal MMLabel avedev;

		internal Grid adGrid;

		internal MMLabel adstate;

		internal MMLabel point;

		internal MMLabel relative;

		internal MMLabel abso;

		internal MMLabel max;

		internal MMLabel adtemp;

		internal MMLabel Label9;

		internal MMLabel Label10;

		internal MMLabel Label11;

		internal MMLabel Label12;

		internal MMLabel adpres;

		internal MMLabel Label13;

		internal MMLabel Label14;

		internal MMLabel Label15;

		internal MMLabel Label16;

		internal MMLabel advap;

		internal MMLabel Label17;

		internal MMLabel Label18;

		internal MMLabel Label19;

		internal MMLabel Label20;

		private bool _contentLoaded;

		public MMParam_Bi_Reg_VLE()
		{
			base.ViewModelType = typeof(MMParam_Bi_Reg_VLE_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/t-dependent/mmparam_bi_reg_vle.xaml", UriKind.Relative);
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
				databank = (MMLabel)target;
				break;
			case 2:
				Label1 = (MMLabel)target;
				break;
			case 3:
				parameter = (MMLabel)target;
				break;
			case 4:
				Label2 = (MMLabel)target;
				break;
			case 5:
				components = (MMLabel)target;
				break;
			case 6:
				Label3 = (MMLabel)target;
				break;
			case 7:
				rangeofdata = (MMLabel)target;
				break;
			case 8:
				svGrid = (Grid)target;
				break;
			case 9:
				state = (MMLabel)target;
				break;
			case 10:
				range = (MMLabel)target;
				break;
			case 11:
				temp = (MMLabel)target;
				break;
			case 12:
				Label4 = (MMLabel)target;
				break;
			case 13:
				pres = (MMLabel)target;
				break;
			case 14:
				Label5 = (MMLabel)target;
				break;
			case 15:
				Lmolf = (MMLabel)target;
				break;
			case 16:
				Label6 = (MMLabel)target;
				break;
			case 17:
				Label7 = (MMLabel)target;
				break;
			case 18:
				resid = (MMLabel)target;
				break;
			case 19:
				Label8 = (MMLabel)target;
				break;
			case 20:
				avedev = (MMLabel)target;
				break;
			case 21:
				adGrid = (Grid)target;
				break;
			case 22:
				adstate = (MMLabel)target;
				break;
			case 23:
				point = (MMLabel)target;
				break;
			case 24:
				relative = (MMLabel)target;
				break;
			case 25:
				abso = (MMLabel)target;
				break;
			case 26:
				max = (MMLabel)target;
				break;
			case 27:
				adtemp = (MMLabel)target;
				break;
			case 28:
				Label9 = (MMLabel)target;
				break;
			case 29:
				Label10 = (MMLabel)target;
				break;
			case 30:
				Label11 = (MMLabel)target;
				break;
			case 31:
				Label12 = (MMLabel)target;
				break;
			case 32:
				adpres = (MMLabel)target;
				break;
			case 33:
				Label13 = (MMLabel)target;
				break;
			case 34:
				Label14 = (MMLabel)target;
				break;
			case 35:
				Label15 = (MMLabel)target;
				break;
			case 36:
				Label16 = (MMLabel)target;
				break;
			case 37:
				advap = (MMLabel)target;
				break;
			case 38:
				Label17 = (MMLabel)target;
				break;
			case 39:
				Label18 = (MMLabel)target;
				break;
			case 40:
				Label19 = (MMLabel)target;
				break;
			case 41:
				Label20 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	public class MMParam_Bi_Sca_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration accessdb_Property = CxvPropertyDeclaration.Register("accessdb", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCESSDBS"
		});

		public static readonly CxvPropertyDeclaration passed_Property = CxvPropertyDeclaration.Register("passed", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration param_Property = CxvPropertyDeclaration.Register("param", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@param" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMParam_Bi_Sca_Inp_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accessdb" },
			EnteredDataPaths = { "@entdb" }
		});

		public object choice => GetValue(choice_Property);

		public object accessdb => GetValue(accessdb_Property);

		public object passed => GetValue(passed_Property);

		public object param => GetValue(param_Property);

		public object entdb => GetValue(entdb_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	[ProgId("MMParam_Bi_Sca.MMParam_Bi_Sca_Inp")]
	public class MMParam_Bi_Sca_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMParam_Bi_Sca_Inp()
		{
			base.ViewModelType = typeof(MMParam_Bi_Sca_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/scalar/mmparam_bi_sca_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	public class MMParam_Bi_Sca_Inp_Data_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration mnuBDBank_var2_Property = CxvPropertyDeclaration.Register("mnuBDBank_var2", typeof(MMParam_Bi_Sca_Inp_Data_ViewModel), new CxvParameterProperty
		{
			Parameter = "passed"
		});

		public static readonly CxvPropertyDeclaration mnuBDBank_var1_Property = CxvPropertyDeclaration.Register("mnuBDBank_var1", typeof(MMParam_Bi_Sca_Inp_Data_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.BDBANK",
			SelectedItemBinding = "mnuBDBank_var2.Value"
		});

		public static readonly CxvPropertyDeclaration lstpDataBanks_bdbank_Property = CxvPropertyDeclaration.Register("lstpDataBanks_bdbank", typeof(MMParam_Bi_Sca_Inp_Data_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.BDBANK.#0"
		});

		public object mnuBDBank_var2 => GetValue(mnuBDBank_var2_Property);

		public object mnuBDBank_var1 => GetValue(mnuBDBank_var1_Property);

		public object lstpDataBanks_bdbank => GetValue(lstpDataBanks_bdbank_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	[ProgId("MMParam_Bi_Sca.MMParam_Bi_Sca_Inp_Data")]
	public class MMParam_Bi_Sca_Inp_Data : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpDataBanks;

		internal MMLabel mnuBDBank_label;

		internal MMAdvancedComboEdit mnuBDBank;

		private bool _contentLoaded;

		public MMParam_Bi_Sca_Inp_Data()
		{
			base.ViewModelType = typeof(MMParam_Bi_Sca_Inp_Data_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/scalar/mmparam_bi_sca_inp_data.xaml", UriKind.Relative);
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
				lstpDataBanks = (MMListPicker)target;
				break;
			case 2:
				mnuBDBank_label = (MMLabel)target;
				break;
			case 3:
				mnuBDBank = (MMAdvancedComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	[ProgId("MMParam_Bi_Sca.MMParam_Bi_Sca_Inp_Param")]
	public class MMParam_Bi_Sca_Inp_Param : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLabel1;

		internal MMAdvancedComboEdit mnuValue;

		internal MMTextEdit txtRecordType;

		internal MMLabel lblDataSet;

		internal MMValueEdit txtDataset;

		internal MMLabel cboPropertyUnits_label;

		internal MMComboEdit cboPropertyUnits;

		internal MMGroupBox frarackettLiquidMolarVolumeParameters;

		internal MMScrollAreaMS grdBinaryParameters;

		internal MMCmdButton cmdSearch;

		private bool _contentLoaded;

		public MMParam_Bi_Sca_Inp_Param()
		{
			base.ViewModelType = typeof(MMParam_Bi_Sca_Inp_Param_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/scalar/mmparam_bi_sca_inp_param.xaml", UriKind.Relative);
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
				MMLabel1 = (MMLabel)target;
				break;
			case 2:
				mnuValue = (MMAdvancedComboEdit)target;
				break;
			case 3:
				txtRecordType = (MMTextEdit)target;
				break;
			case 4:
				lblDataSet = (MMLabel)target;
				break;
			case 5:
				txtDataset = (MMValueEdit)target;
				break;
			case 6:
				cboPropertyUnits_label = (MMLabel)target;
				break;
			case 7:
				cboPropertyUnits = (MMComboEdit)target;
				break;
			case 8:
				frarackettLiquidMolarVolumeParameters = (MMGroupBox)target;
				break;
			case 9:
				grdBinaryParameters = (MMScrollAreaMS)target;
				break;
			case 10:
				cmdSearch = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Parameters.Binary_Interaction.Scalar
{
	[ProgId("MMParam_Bi_Sca.MMParam_Bi_Sca_Search")]
	public class MMParam_Bi_Sca_Search : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmSearchDB;

		internal MMLabel cboCID1_label;

		internal MMComboEdit cboCID1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMCmdButton cmdSearch;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMParam_Bi_Sca_Search()
		{
			base.ViewModelType = typeof(MMParam_Bi_Sca_Search_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/parameters/binary%20interaction/scalar/mmparam_bi_sca_search.xaml", UriKind.Relative);
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
				frmSearchDB = (MMGroupBox)target;
				break;
			case 2:
				cboCID1_label = (MMLabel)target;
				break;
			case 3:
				cboCID1 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				cmdSearch = (MMCmdButton)target;
				break;
			case 7:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_Affected_DB")]
	public class MMRouteModel_Affected_DB : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRouteModel_Affected_DB()
		{
			base.ViewModelType = typeof(MMRouteModel_Affected_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_affected_db.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollArea)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_BuildRoute_DB")]
	public class MMRouteModel_BuildRoute_DB : MMTabPage, IComponentConnector
	{
		internal MMLabel cboMType_label;

		internal MMComboEdit cboMType;

		internal MMLabel cboMethodCode_label;

		internal MMComboEdit cboMethodCode;

		internal MMLabel cboSelectProperty_Name_label;

		internal MMComboEdit cboSelectProperty_Name;

		internal MMLabel cboCopyRouteFrom_label;

		internal MMComboEdit cboCopyRouteFrom;

		internal MMGroupBox fraSpecifyRequiredRoutesAndModels;

		internal MMScrollArea grdRoutes_0;

		internal MMCmdButton cmdViewTree;

		internal MMScrollArea grdModels;

		internal MMCmdButton cmdOptionCodes;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRouteModel_BuildRoute_DB()
		{
			base.ViewModelType = typeof(MMRouteModel_BuildRoute_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_buildroute_db.xaml", UriKind.Relative);
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
				cboMType_label = (MMLabel)target;
				break;
			case 2:
				cboMType = (MMComboEdit)target;
				break;
			case 3:
				cboMethodCode_label = (MMLabel)target;
				break;
			case 4:
				cboMethodCode = (MMComboEdit)target;
				break;
			case 5:
				cboSelectProperty_Name_label = (MMLabel)target;
				break;
			case 6:
				cboSelectProperty_Name = (MMComboEdit)target;
				break;
			case 7:
				cboCopyRouteFrom_label = (MMLabel)target;
				break;
			case 8:
				cboCopyRouteFrom = (MMComboEdit)target;
				break;
			case 9:
				fraSpecifyRequiredRoutesAndModels = (MMGroupBox)target;
				break;
			case 10:
				grdRoutes_0 = (MMScrollArea)target;
				break;
			case 11:
				cmdViewTree = (MMCmdButton)target;
				break;
			case 12:
				grdModels = (MMScrollArea)target;
				break;
			case 13:
				cmdOptionCodes = (MMCmdButton)target;
				break;
			case 14:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	public class MMRouteModel_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration comp_Property = CxvPropertyDeclaration.Register("comp", typeof(MMRouteModel_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMRouteModel_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@comp" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMRouteModel_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@comp" }
		});

		public object comp => GetValue(comp_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_In")]
	public class MMRouteModel_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPropSets;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMRouteModel_In()
		{
			base.ViewModelType = typeof(MMRouteModel_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_in.xaml", UriKind.Relative);
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
				tabPropSets = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_In_Models")]
	public class MMRouteModel_In_Models : MMTabPage, IComponentConnector
	{
		internal MMLabel cboModel_BaseMethod_label;

		internal MMComboEdit cboModel_BaseMethod;

		internal MMGroupBox fraModels;

		internal MMScrollAreaMS grdModels_1;

		internal MMCmdButton cmdAffected;

		internal MMCmdButton cmdOptionCodes;

		private bool _contentLoaded;

		public MMRouteModel_In_Models()
		{
			base.ViewModelType = typeof(MMRouteModel_In_Models_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_in_models.xaml", UriKind.Relative);
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
				cboModel_BaseMethod_label = (MMLabel)target;
				break;
			case 2:
				cboModel_BaseMethod = (MMComboEdit)target;
				break;
			case 3:
				fraModels = (MMGroupBox)target;
				break;
			case 4:
				grdModels_1 = (MMScrollAreaMS)target;
				break;
			case 5:
				cmdAffected = (MMCmdButton)target;
				break;
			case 6:
				cmdOptionCodes = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_In_Routes")]
	public class MMRouteModel_In_Routes : MMTabPage, IComponentConnector
	{
		internal MMLabel cboBasemethod_label;

		internal MMComboEdit cboBasemethod;

		internal MMGroupBox fraRoutes;

		internal MMLabel mnuType_label;

		internal MMComboEdit mnuType;

		internal MMLabel mnuMajorSub_label;

		internal MMComboEdit mnuMajorSub;

		internal MMScrollAreaMS grdSelection;

		internal MMCmdButton cmdBuildRoute;

		internal MMCmdButton cmdEditRoute;

		internal MMCmdButton cmdViewTree;

		private bool _contentLoaded;

		public MMRouteModel_In_Routes()
		{
			base.ViewModelType = typeof(MMRouteModel_In_Routes_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_in_routes.xaml", UriKind.Relative);
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
				cboBasemethod_label = (MMLabel)target;
				break;
			case 2:
				cboBasemethod = (MMComboEdit)target;
				break;
			case 3:
				fraRoutes = (MMGroupBox)target;
				break;
			case 4:
				mnuType_label = (MMLabel)target;
				break;
			case 5:
				mnuType = (MMComboEdit)target;
				break;
			case 6:
				mnuMajorSub_label = (MMLabel)target;
				break;
			case 7:
				mnuMajorSub = (MMComboEdit)target;
				break;
			case 8:
				grdSelection = (MMScrollAreaMS)target;
				break;
			case 9:
				cmdBuildRoute = (MMCmdButton)target;
				break;
			case 10:
				cmdEditRoute = (MMCmdButton)target;
				break;
			case 11:
				cmdViewTree = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_OptCodeDB")]
	public class MMRouteModel_OptCodeDB : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraOptionCodes;

		internal MMScrollAreaMS MMScrollArea1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRouteModel_OptCodeDB()
		{
			base.ViewModelType = typeof(MMRouteModel_OptCodeDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_optcodedb.xaml", UriKind.Relative);
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
				fraOptionCodes = (MMGroupBox)target;
				break;
			case 4:
				MMScrollArea1 = (MMScrollAreaMS)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_RouteName_DB")]
	public class MMRouteModel_RouteName_DB : MMTabPage, IComponentConnector
	{
		internal MMLabel txtRouteName_label;

		internal MMVariableEdit txtRouteName;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMRouteModel_RouteName_DB()
		{
			base.ViewModelType = typeof(MMRouteModel_RouteName_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_routename_db.xaml", UriKind.Relative);
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
				txtRouteName_label = (MMLabel)target;
				break;
			case 2:
				txtRouteName = (MMVariableEdit)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Option_Sets
{
	[ProgId("MMRouteModel.MMRouteModel_ViewTree_DB")]
	public class MMRouteModel_ViewTree_DB : MMTabPage, IComponentConnector
	{
		internal Grid NodeTreeHost;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRouteModel_ViewTree_DB()
		{
			base.ViewModelType = typeof(MMRouteModel_ViewTree_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/option-sets/mmroutemodel_viewtree_db.xaml", UriKind.Relative);
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
				NodeTreeHost = (Grid)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	[ComVisible(true)]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class SimpleApedMoleInfoReceiver
	{
		public string MoleInfoData { get; private set; }

		public void GetMoleInfoFromData(string moleInfoData)
		{
			MoleInfoData = moleInfoData;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	public class MMProp_MoSt_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMProp_MoSt_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration spe_Property = CxvPropertyDeclaration.Register("spe", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPE"
		});

		public static readonly CxvPropertyDeclaration formula_Property = CxvPropertyDeclaration.Register("formula", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FORMULA"
		});

		public static readonly CxvPropertyDeclaration gen_Property = CxvPropertyDeclaration.Register("gen", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GEN"
		});

		public static readonly CxvPropertyDeclaration entgen_Property = CxvPropertyDeclaration.Register("entgen", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTGEN"
		});

		public static readonly CxvPropertyDeclaration entform_Property = CxvPropertyDeclaration.Register("entform", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFORM"
		});

		public static readonly CxvPropertyDeclaration entmeth_Property = CxvPropertyDeclaration.Register("entmeth", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTMETH"
		});

		public static readonly CxvPropertyDeclaration maincc_Property = CxvPropertyDeclaration.Register("maincc", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration nbiocmp_Property = CxvPropertyDeclaration.Register("nbiocmp", typeof(MMProp_MoSt_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NBIOCMP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMProp_MoSt_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@gen" },
			EnteredDataPaths = { "@entgen" },
			AccessibleDataPaths = { "@nbiocmp" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMProp_MoSt_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@maincc", "@spe" },
			EnteredDataPaths = { "@entmeth" },
			AccessibleDataPaths = { "@nbiocmp" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMProp_MoSt_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@formula" },
			EnteredDataPaths = { "@entform" },
			AccessibleDataPaths = { "@nbiocmp" }
		});

		public new static readonly CxvPropertyDeclaration info_var_Property = CxvPropertyDeclaration.Register("info_var", typeof(MMProp_MoSt_Input_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@nbiocmp" }
		});

		public object choice => GetValue(choice_Property);

		public object spe => GetValue(spe_Property);

		public object formula => GetValue(formula_Property);

		public object gen => GetValue(gen_Property);

		public object entgen => GetValue(entgen_Property);

		public object entform => GetValue(entform_Property);

		public object entmeth => GetValue(entmeth_Property);

		public object maincc => GetValue(maincc_Property);

		public object nbiocmp => GetValue(nbiocmp_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public new object info_var => GetValue(info_var_Property);

		protected override void OnUpdateData()
		{
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "id"));
			string dataPath = "Top.appModelV8.Components.Specifications.Input.TYPE." + text;
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet(dataPath, "value"));
			int num = 0;
			if (text2 == "BIO")
			{
				num = 1;
			}
			string dataPath2 = "@main.Input.BIOCOMP";
			int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet(dataPath2, "value"));
			if (num2.HasValue && num2.Value != num)
			{
				ExpandDataPathAndSet(dataPath2, "value", num);
			}
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	[ProgId("MMProp_MoSt.MMProp_MoSt_Input")]
	public class MMProp_MoSt_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMProp_Mo;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMProp_MoSt_Input()
		{
			base.ViewModelType = typeof(MMProp_MoSt_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/molecularstructure/mmprop_most_input.xaml", UriKind.Relative);
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
				MMProp_Mo = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	[ProgId("MMProp_MoSt.MMProp_MoSt_Input_Formula")]
	public class MMProp_MoSt_Input_Formula : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMProp_MoSt_Input_Formula()
		{
			base.ViewModelType = typeof(MMProp_MoSt_Input_Formula_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/molecularstructure/mmprop_most_input_formula.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	[ProgId("MMProp_MoSt.MMProp_MoSt_Input_FuncGrl")]
	public class MMProp_MoSt_Input_FuncGr : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMProp_MoSt_Input_FuncGr()
		{
			base.ViewModelType = typeof(MMProp_MoSt_Input_FuncGr_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/molecularstructure/mmprop_most_input_funcgr.xaml", UriKind.Relative);
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
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 3:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	internal class GroupTypeOption
	{
		private string _localizedValue;

		internal string ResourceKey => "groupfilter_" + Value.Replace("-", "_");

		internal string LocalizedValue
		{
			get
			{
				if (string.IsNullOrEmpty(_localizedValue))
				{
					_localizedValue = ApwnComboResource.ResourceManager.GetString(ResourceKey);
					if (string.IsNullOrEmpty(_localizedValue))
					{
						_localizedValue = Value;
					}
				}
				return _localizedValue;
			}
		}

		internal string Value { get; private set; }

		internal GroupTypeOption(string pDefaultValue)
		{
			Value = pDefaultValue;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	internal class GroupTypeOptionsCollection
	{
		internal IList<GroupTypeOption> Collection { get; set; } = new List<GroupTypeOption>();

		internal bool TryGetValueByLocalizedValue(string pLocalizedValue, out string pValue)
		{
			pValue = null;
			if (Collection != null)
			{
				for (int i = 0; i < Collection.Count; i++)
				{
					if (Collection[i] != null && Collection[i].LocalizedValue == pLocalizedValue)
					{
						pValue = Collection[i].Value;
						return true;
					}
				}
			}
			return false;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	public class FunctionalGroupDataUpdatedEventArgs : EventArgs
	{
		public string MainPath { get; }

		public string Method { get; }

		public FunctionalGroupDataUpdatedEventArgs(string mainPath, string method)
		{
			MainPath = mainPath;
			Method = method;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	public class FunctionalGroupDataUpdatedEvent : RoutedCompositePresentationEvent<FunctionalGroupDataUpdatedEventArgs>
	{
		public FunctionalGroupDataUpdatedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	public class MolecularGroupItemToGroupConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is string text)
			{
				int num = text.IndexOf('\t');
				if (num > 0)
				{
					return text.Substring(0, num);
				}
			}
			return null;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.MolecularStructure
{
	[ProgId("MMProp_MoSt.MMProp_MoSt_Input_General")]
	public class MMProp_MoSt_Input_General : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollAreaMS MMScrollArea1;

		internal MMGroupBox MMFrame2;

		internal MMScrollAreaMS MMScrollArea2;

		private bool _contentLoaded;

		public MMProp_MoSt_Input_General()
		{
			base.ViewModelType = typeof(MMProp_MoSt_Input_General_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/molecularstructure/mmprop_most_input_general.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollAreaMS)target;
				break;
			case 3:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 4:
				MMScrollArea2 = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	public class MMPropEsti_Cmp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMPropEsti_Cmp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Compare.CC Nodes.COMP"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMPropEsti_Cmp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration PURETAB1_Property = CxvPropertyDeclaration.Register("PURETAB1", typeof(MMPropEsti_Cmp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.COMPID3.0"
		});

		public static readonly CxvPropertyDeclaration TDEPTAB1_Property = CxvPropertyDeclaration.Register("TDEPTAB1", typeof(MMPropEsti_Cmp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.TEMP.0"
		});

		public static readonly CxvPropertyDeclaration UNIFTAB1_Property = CxvPropertyDeclaration.Register("UNIFTAB1", typeof(MMPropEsti_Cmp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.PARANAME5.0"
		});

		public static readonly CxvPropertyDeclaration entset_Property = CxvPropertyDeclaration.Register("entset", typeof(MMPropEsti_Cmp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Compare.CC Nodes.ENTSET"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPropEsti_Cmp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@var1" },
			EnteredDataPaths = { "@entset" }
		});

		public object var1 => GetValue(var1_Property);

		public object choice => GetValue(choice_Property);

		public object PURETAB1 => GetValue(PURETAB1_Property);

		public object TDEPTAB1 => GetValue(TDEPTAB1_Property);

		public object UNIFTAB1 => GetValue(UNIFTAB1_Property);

		public object entset => GetValue(entset_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Cmp")]
	public class MMPropEsti_Cmp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMPropEsti_Cmp()
		{
			base.ViewModelType = typeof(MMPropEsti_Cmp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmp.xaml", UriKind.Relative);
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	public class MMPropEsti_CmpRes_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration var1_Property = CxvPropertyDeclaration.Register("var1", typeof(MMPropEsti_CmpRes_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Compare.CC Nodes.COMP"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMPropEsti_CmpRes_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration PURETAB1_Property = CxvPropertyDeclaration.Register("PURETAB1", typeof(MMPropEsti_CmpRes_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.COMPID3"
		});

		public static readonly CxvPropertyDeclaration TDEPTAB1_Property = CxvPropertyDeclaration.Register("TDEPTAB1", typeof(MMPropEsti_CmpRes_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.TEMP"
		});

		public static readonly CxvPropertyDeclaration UNIFTAB1_Property = CxvPropertyDeclaration.Register("UNIFTAB1", typeof(MMPropEsti_CmpRes_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.PARANAME5"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPropEsti_CmpRes_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@PURETAB1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPropEsti_CmpRes_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@TDEPTAB1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPropEsti_CmpRes_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@UNIFTAB1" }
		});

		public object var1 => GetValue(var1_Property);

		public object choice => GetValue(choice_Property);

		public object PURETAB1 => GetValue(PURETAB1_Property);

		public object TDEPTAB1 => GetValue(TDEPTAB1_Property);

		public object UNIFTAB1 => GetValue(UNIFTAB1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_CmpRes")]
	public class MMPropEsti_CmpRes : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		private bool _contentLoaded;

		public MMPropEsti_CmpRes()
		{
			base.ViewModelType = typeof(MMPropEsti_CmpRes_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmpres.xaml", UriKind.Relative);
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Cmp_Pure")]
	public class MMPropEsti_Cmp_Pure : MMTabPage, IComponentConnector
	{
		internal MMLabel mbComponentID_label;

		internal MMComboEdit mbComponentID;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdPure;

		private bool _contentLoaded;

		public MMPropEsti_Cmp_Pure()
		{
			base.ViewModelType = typeof(MMPropEsti_Cmp_Pure_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmp_pure.xaml", UriKind.Relative);
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
				mbComponentID_label = (MMLabel)target;
				break;
			case 2:
				mbComponentID = (MMComboEdit)target;
				break;
			case 3:
				fraMethods = (MMGroupBox)target;
				break;
			case 4:
				grdPure = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Cmp_Setup")]
	public class MMPropEsti_Cmp_Setup : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraVerify;

		internal MMScrollArea grdCompID;

		internal MMScrollArea grdGroupID;

		internal MMGroupBox fraCompare;

		internal MMScrollArea grdCComp;

		internal MMScrollArea grdCGroup;

		private bool _contentLoaded;

		public MMPropEsti_Cmp_Setup()
		{
			base.ViewModelType = typeof(MMPropEsti_Cmp_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmp_setup.xaml", UriKind.Relative);
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
				fraVerify = (MMGroupBox)target;
				break;
			case 2:
				grdCompID = (MMScrollArea)target;
				break;
			case 3:
				grdGroupID = (MMScrollArea)target;
				break;
			case 4:
				fraCompare = (MMGroupBox)target;
				break;
			case 5:
				grdCComp = (MMScrollArea)target;
				break;
			case 6:
				grdCGroup = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Cmp_Tdep")]
	public class MMPropEsti_Cmp_Tdep : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraMethods;

		internal MMCmdButton cmdPrev;

		internal MMLabel MMLabel1;

		internal MMCmdButton cmdNext;

		internal MMTextEdit txtComponent;

		internal MMTextEdit txtProp;

		internal MMTextEdit txtMeth;

		internal MMScrollArea grdCompareT;

		private bool _contentLoaded;

		public MMPropEsti_Cmp_Tdep()
		{
			base.ViewModelType = typeof(MMPropEsti_Cmp_Tdep_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmp_tdep.xaml", UriKind.Relative);
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
				fraMethods = (MMGroupBox)target;
				break;
			case 2:
				cmdPrev = (MMCmdButton)target;
				break;
			case 3:
				MMLabel1 = (MMLabel)target;
				break;
			case 4:
				cmdNext = (MMCmdButton)target;
				break;
			case 5:
				txtComponent = (MMTextEdit)target;
				break;
			case 6:
				txtProp = (MMTextEdit)target;
				break;
			case 7:
				txtMeth = (MMTextEdit)target;
				break;
			case 8:
				grdCompareT = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Cmp_Unif")]
	public class MMPropEsti_Cmp_Unif : MMTabPage, IComponentConnector
	{
		internal MMLabel mbComponentID_label;

		internal MMComboEdit mbComponentID;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdPure;

		private bool _contentLoaded;

		public MMPropEsti_Cmp_Unif()
		{
			base.ViewModelType = typeof(MMPropEsti_Cmp_Unif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_cmp_unif.xaml", UriKind.Relative);
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
				mbComponentID_label = (MMLabel)target;
				break;
			case 2:
				mbComponentID = (MMComboEdit)target;
				break;
			case 3:
				fraMethods = (MMGroupBox)target;
				break;
			case 4:
				grdPure = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	public class MMPropEsti_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMPropEsti_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration choiceN_Property = CxvPropertyDeclaration.Register("choiceN", typeof(MMPropEsti_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choiceN"
		});

		public static readonly CxvPropertyDeclaration SETUPTAB1_Property = CxvPropertyDeclaration.Register("SETUPTAB1", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration TDEPTAB1_Property = CxvPropertyDeclaration.Register("TDEPTAB1", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.UT"
		});

		public static readonly CxvPropertyDeclaration TDEPTAB2_Property = CxvPropertyDeclaration.Register("TDEPTAB2", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.UTC"
		});

		public static readonly CxvPropertyDeclaration BINTAB1_Property = CxvPropertyDeclaration.Register("BINTAB1", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.BI"
		});

		public static readonly CxvPropertyDeclaration BINTAB2_Property = CxvPropertyDeclaration.Register("BINTAB2", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.BIC"
		});

		public static readonly CxvPropertyDeclaration PURETAB1_Property = CxvPropertyDeclaration.Register("PURETAB1", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.UN"
		});

		public static readonly CxvPropertyDeclaration PURETAB2_Property = CxvPropertyDeclaration.Register("PURETAB2", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.UNC"
		});

		public static readonly CxvPropertyDeclaration UNIFTAB1_Property = CxvPropertyDeclaration.Register("UNIFTAB1", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.GR"
		});

		public static readonly CxvPropertyDeclaration UNIFTAB2_Property = CxvPropertyDeclaration.Register("UNIFTAB2", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.GRC"
		});

		public static readonly CxvPropertyDeclaration BinEst_Property = CxvPropertyDeclaration.Register("BinEst", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Input.PROPERTY.@choiceN"
		});

		public static readonly CxvPropertyDeclaration ENTUTAB_Property = CxvPropertyDeclaration.Register("ENTUTAB", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.ENTU"
		});

		public static readonly CxvPropertyDeclaration ENTTTAB_Property = CxvPropertyDeclaration.Register("ENTTTAB", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.ENTT"
		});

		public static readonly CxvPropertyDeclaration ENTBTAB_Property = CxvPropertyDeclaration.Register("ENTBTAB", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.ENTBIN"
		});

		public static readonly CxvPropertyDeclaration ENTGTAB_Property = CxvPropertyDeclaration.Register("ENTGTAB", typeof(MMPropEsti_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.CC Nodes.ENTGRP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPropEsti_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SETUPTAB1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPropEsti_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PURETAB1" },
			AccessibleDataPaths = { "@PURETAB2" },
			EnteredDataPaths = { "@ENTUTAB" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPropEsti_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@TDEPTAB1" },
			AccessibleDataPaths = { "@TDEPTAB2" },
			EnteredDataPaths = { "@ENTTTAB" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPropEsti_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@BINTAB1" },
			AccessibleDataPaths = { "@BINTAB2" },
			EnteredDataPaths = { "@ENTBTAB" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMPropEsti_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@UNIFTAB1" },
			AccessibleDataPaths = { "@UNIFTAB2" },
			EnteredDataPaths = { "@ENTGTAB" }
		});

		public object choice => GetValue(choice_Property);

		public object choiceN => GetValue(choiceN_Property);

		public object SETUPTAB1 => GetValue(SETUPTAB1_Property);

		public object TDEPTAB1 => GetValue(TDEPTAB1_Property);

		public object TDEPTAB2 => GetValue(TDEPTAB2_Property);

		public object BINTAB1 => GetValue(BINTAB1_Property);

		public object BINTAB2 => GetValue(BINTAB2_Property);

		public object PURETAB1 => GetValue(PURETAB1_Property);

		public object PURETAB2 => GetValue(PURETAB2_Property);

		public object UNIFTAB1 => GetValue(UNIFTAB1_Property);

		public object UNIFTAB2 => GetValue(UNIFTAB2_Property);

		public object BinEst => GetValue(BinEst_Property);

		public object ENTUTAB => GetValue(ENTUTAB_Property);

		public object ENTTTAB => GetValue(ENTTTAB_Property);

		public object ENTBTAB => GetValue(ENTBTAB_Property);

		public object ENTGTAB => GetValue(ENTGTAB_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("extraUnits_path", "Estimate.Input.Unit Set");
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp")]
	public class MMPropEsti_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPropEsti_Inp()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp_Bin")]
	public class MMPropEsti_Inp_Bin : MMTabPage, IComponentConnector
	{
		internal MMLabel labParameter;

		internal MMCmdButton cmdPrev;

		internal MMComboEdit cbPropName;

		internal MMCmdButton cmdNext;

		internal MMCmdButton cmdNew;

		internal MMCmdButton cmdDelete;

		internal MMLabel labMethEst;

		internal MMHorizontalListEdit grdMethEst;

		internal MMGroupBox fraMethods;

		internal MMScrollAreaMS grdCompMeth;

		private bool _contentLoaded;

		public MMPropEsti_Inp_Bin()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_Bin_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp_bin.xaml", UriKind.Relative);
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
				labParameter = (MMLabel)target;
				break;
			case 2:
				cmdPrev = (MMCmdButton)target;
				break;
			case 3:
				cbPropName = (MMComboEdit)target;
				break;
			case 4:
				cmdNext = (MMCmdButton)target;
				break;
			case 5:
				cmdNew = (MMCmdButton)target;
				break;
			case 6:
				cmdDelete = (MMCmdButton)target;
				break;
			case 7:
				labMethEst = (MMLabel)target;
				break;
			case 8:
				grdMethEst = (MMHorizontalListEdit)target;
				break;
			case 9:
				fraMethods = (MMGroupBox)target;
				break;
			case 10:
				grdCompMeth = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp_Pure")]
	public class MMPropEsti_Inp_Pure : MMTabPage, IComponentConnector
	{
		internal MMLabel menParameter_label;

		internal MMAdvancedComboEdit menParameter;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdMethod;

		private bool _contentLoaded;

		public MMPropEsti_Inp_Pure()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_Pure_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp_pure.xaml", UriKind.Relative);
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
				menParameter_label = (MMLabel)target;
				break;
			case 2:
				menParameter = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraMethods = (MMGroupBox)target;
				break;
			case 4:
				grdMethod = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp_Setup")]
	public class MMPropEsti_Inp_Setup : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrParams;

		internal MMOptionButton ogrParams_opt0;

		internal MMOptionButton ogrParams_opt1;

		internal MMOptionButton ogrParams_opt2;

		internal MMGroupBox fraParamTypes;

		internal MMCheckBox chkPureScalar;

		internal MMCheckBox chkPureTemp;

		internal MMCheckBox chkBinary;

		internal MMCheckBox chk;

		private bool _contentLoaded;

		public MMPropEsti_Inp_Setup()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp_setup.xaml", UriKind.Relative);
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
				ogrParams = (MMOptionGroup)target;
				break;
			case 2:
				ogrParams_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogrParams_opt1 = (MMOptionButton)target;
				break;
			case 4:
				ogrParams_opt2 = (MMOptionButton)target;
				break;
			case 5:
				fraParamTypes = (MMGroupBox)target;
				break;
			case 6:
				chkPureScalar = (MMCheckBox)target;
				break;
			case 7:
				chkPureTemp = (MMCheckBox)target;
				break;
			case 8:
				chkBinary = (MMCheckBox)target;
				break;
			case 9:
				chk = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp_Tdep")]
	public class MMPropEsti_Inp_Tdep : MMTabPage, IComponentConnector
	{
		internal MMLabel menParameter_label;

		internal MMAdvancedComboEdit menParameter;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdCompon;

		private bool _contentLoaded;

		public MMPropEsti_Inp_Tdep()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_Tdep_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp_tdep.xaml", UriKind.Relative);
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
				menParameter_label = (MMLabel)target;
				break;
			case 2:
				menParameter = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraMethods = (MMGroupBox)target;
				break;
			case 4:
				grdCompon = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Inp_Unif")]
	public class MMPropEsti_Inp_Unif : MMTabPage, IComponentConnector
	{
		internal MMLabel menParameter_label;

		internal MMAdvancedComboEdit menParameter;

		internal MMGroupBox fraParams;

		internal MMScrollArea grdData;

		private bool _contentLoaded;

		public MMPropEsti_Inp_Unif()
		{
			base.ViewModelType = typeof(MMPropEsti_Inp_Unif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_inp_unif.xaml", UriKind.Relative);
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
				menParameter_label = (MMLabel)target;
				break;
			case 2:
				menParameter = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraParams = (MMGroupBox)target;
				break;
			case 4:
				grdData = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	public class MMPropEsti_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMPropEsti_Out_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration choiceN_Property = CxvPropertyDeclaration.Register("choiceN", typeof(MMPropEsti_Out_ViewModel), new CxvParameterProperty
		{
			Parameter = "choiceN"
		});

		public static readonly CxvPropertyDeclaration PURETAB1_Property = CxvPropertyDeclaration.Register("PURETAB1", typeof(MMPropEsti_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.COMPID"
		});

		public static readonly CxvPropertyDeclaration TDEPTAB1_Property = CxvPropertyDeclaration.Register("TDEPTAB1", typeof(MMPropEsti_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.COMPID2"
		});

		public static readonly CxvPropertyDeclaration BINTAB1_Property = CxvPropertyDeclaration.Register("BINTAB1", typeof(MMPropEsti_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.COMP_NAMES"
		});

		public static readonly CxvPropertyDeclaration UNIFTAB1_Property = CxvPropertyDeclaration.Register("UNIFTAB1", typeof(MMPropEsti_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Estimate.Output.PARANAME4"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPropEsti_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@PURETAB1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPropEsti_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@TDEPTAB1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPropEsti_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@BINTAB1" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPropEsti_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@UNIFTAB1" }
		});

		public object choice => GetValue(choice_Property);

		public object choiceN => GetValue(choiceN_Property);

		public object PURETAB1 => GetValue(PURETAB1_Property);

		public object TDEPTAB1 => GetValue(TDEPTAB1_Property);

		public object BINTAB1 => GetValue(BINTAB1_Property);

		public object UNIFTAB1 => GetValue(UNIFTAB1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("extra_message_path", "Estimate");
			}
			base.OnUpdateData();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Out")]
	public class MMPropEsti_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMPropEsti_Out()
		{
			base.ViewModelType = typeof(MMPropEsti_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_out.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Out_Bin")]
	public class MMPropEsti_Out_Bin : MMTabPage, IComponentConnector
	{
		internal MMCmdButton cmdPrev;

		internal MMTextEdit txtID;

		internal MMCmdButton cmdNext;

		internal MMGroupBox fraMethods;

		internal MMScrollArea MMScrollArea1;

		internal MMScrollArea MMScrollArea11;

		private bool _contentLoaded;

		public MMPropEsti_Out_Bin()
		{
			base.ViewModelType = typeof(MMPropEsti_Out_Bin_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_out_bin.xaml", UriKind.Relative);
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
				cmdPrev = (MMCmdButton)target;
				break;
			case 2:
				txtID = (MMTextEdit)target;
				break;
			case 3:
				cmdNext = (MMCmdButton)target;
				break;
			case 4:
				fraMethods = (MMGroupBox)target;
				break;
			case 5:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 6:
				MMScrollArea11 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Out_Pure")]
	public class MMPropEsti_Out_Pure : MMTabPage, IComponentConnector
	{
		internal MMLabel mbComponentID_label;

		internal MMComboEdit mbComponentID;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdPure;

		private bool _contentLoaded;

		public MMPropEsti_Out_Pure()
		{
			base.ViewModelType = typeof(MMPropEsti_Out_Pure_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_out_pure.xaml", UriKind.Relative);
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
				mbComponentID_label = (MMLabel)target;
				break;
			case 2:
				mbComponentID = (MMComboEdit)target;
				break;
			case 3:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 4:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 5:
				fraMethods = (MMGroupBox)target;
				break;
			case 6:
				grdPure = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Out_Tdep")]
	public class MMPropEsti_Out_Tdep : MMTabPage, IComponentConnector
	{
		internal MMLabel mbComponentID_label;

		internal MMComboEdit mbComponentID;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdPure;

		private bool _contentLoaded;

		public MMPropEsti_Out_Tdep()
		{
			base.ViewModelType = typeof(MMPropEsti_Out_Tdep_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_out_tdep.xaml", UriKind.Relative);
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
				mbComponentID_label = (MMLabel)target;
				break;
			case 2:
				mbComponentID = (MMComboEdit)target;
				break;
			case 3:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 4:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 5:
				fraMethods = (MMGroupBox)target;
				break;
			case 6:
				grdPure = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Estimation
{
	[ProgId("MMPropEsti.MMPropEsti_Out_Unif")]
	public class MMPropEsti_Out_Unif : MMTabPage, IComponentConnector
	{
		internal MMLabel mbComponentID_label;

		internal MMComboEdit mbComponentID;

		internal MMGroupBox fraMethods;

		internal MMScrollArea grdPure;

		private bool _contentLoaded;

		public MMPropEsti_Out_Unif()
		{
			base.ViewModelType = typeof(MMPropEsti_Out_Unif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/estimation/mmpropesti_out_unif.xaml", UriKind.Relative);
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
				mbComponentID_label = (MMLabel)target;
				break;
			case 2:
				mbComponentID = (MMComboEdit)target;
				break;
			case 3:
				fraMethods = (MMGroupBox)target;
				break;
			case 4:
				grdPure = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Pure
{
	public class MMData_Pure_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SUBSTRID_Property = CxvPropertyDeclaration.Register("SUBSTRID", typeof(MMData_Pure_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration DATA_ID_Property = CxvPropertyDeclaration.Register("DATA_ID", typeof(MMData_Pure_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC_NODES.MAIN"
		});

		public static readonly CxvPropertyDeclaration VARVALUE_Property = CxvPropertyDeclaration.Register("VARVALUE", typeof(MMData_Pure_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "VARVALUE"
		});

		public static readonly CxvPropertyDeclaration DATATAB_Property = CxvPropertyDeclaration.Register("DATATAB", typeof(MMData_Pure_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DATATAB"
		});

		public static readonly CxvPropertyDeclaration SETUPTAB_Property = CxvPropertyDeclaration.Register("SETUPTAB", typeof(MMData_Pure_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SETUPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMData_Pure_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SETUPTAB" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMData_Pure_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@DATATAB" }
		});

		public object SUBSTRID => GetValue(SUBSTRID_Property);

		public object DATA_ID => GetValue(DATA_ID_Property);

		public object VARVALUE => GetValue(VARVALUE_Property);

		public object DATATAB => GetValue(DATATAB_Property);

		public object SETUPTAB => GetValue(SETUPTAB_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Pure
{
	[ProgId("MMData_Pure.MMData_Pure_Input")]
	public class MMData_Pure_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMData_Pure_Input()
		{
			base.ViewModelType = typeof(MMData_Pure_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/pure/mmdata_pure_input.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Pure
{
	[ProgId("MMData_Pure.MMData_Pure_Input_Data")]
	public class MMData_Pure_Input_Data : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollAreaMS grdData;

		private bool _contentLoaded;

		public MMData_Pure_Input_Data()
		{
			base.ViewModelType = typeof(MMData_Pure_Input_Data_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/pure/mmdata_pure_input_data.xaml", UriKind.Relative);
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
				grdData = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Pure
{
	[ProgId("MMData_Pure.MMData_Pure_Input_Setup")]
	public class MMData_Pure_Input_Setup : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDatatype_label;

		internal MMComboEdit cboDatatype;

		internal MMLabel cboProperty_label;

		internal MMComboEdit cboProperty;

		internal MMLabel cboComponent_label;

		internal MMComboEdit cboComponent;

		internal MMGroupBox frmTemperaturePressure;

		internal MMLabel lbtuTemperature_label;

		internal MMVariableEdit lbtuTemperature;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		private bool _contentLoaded;

		public MMData_Pure_Input_Setup()
		{
			base.ViewModelType = typeof(MMData_Pure_Input_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/pure/mmdata_pure_input_setup.xaml", UriKind.Relative);
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
				cboDatatype_label = (MMLabel)target;
				break;
			case 2:
				cboDatatype = (MMComboEdit)target;
				break;
			case 3:
				cboProperty_label = (MMLabel)target;
				break;
			case 4:
				cboProperty = (MMComboEdit)target;
				break;
			case 5:
				cboComponent_label = (MMLabel)target;
				break;
			case 6:
				cboComponent = (MMComboEdit)target;
				break;
			case 7:
				frmTemperaturePressure = (MMGroupBox)target;
				break;
			case 8:
				lbtuTemperature_label = (MMLabel)target;
				break;
			case 9:
				lbtuTemperature = (MMVariableEdit)target;
				break;
			case 10:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 11:
				lbtuPressure = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	public class MMDataMixt_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMDataMixt_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration dataname_Property = CxvPropertyDeclaration.Register("dataname", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.STATESPEC"
		});

		public static readonly CxvPropertyDeclaration SUBSTRID_Property = CxvPropertyDeclaration.Register("SUBSTRID", typeof(MMDataMixt_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "SUBSTRID"
		});

		public static readonly CxvPropertyDeclaration VARVALUE_Property = CxvPropertyDeclaration.Register("VARVALUE", typeof(MMDataMixt_Inp_ViewModel), new CxvParameterProperty
		{
			Parameter = "VARVALUE"
		});

		public static readonly CxvPropertyDeclaration DATATAB1_Property = CxvPropertyDeclaration.Register("DATATAB1", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DATATAB1"
		});

		public static readonly CxvPropertyDeclaration TWOCOMPS_Property = CxvPropertyDeclaration.Register("TWOCOMPS", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TWOCOMPONS"
		});

		public static readonly CxvPropertyDeclaration STATEOK_Property = CxvPropertyDeclaration.Register("STATEOK", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STATEOK"
		});

		public static readonly CxvPropertyDeclaration DATATAB2_Property = CxvPropertyDeclaration.Register("DATATAB2", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DATATAB2"
		});

		public static readonly CxvPropertyDeclaration CNSTRNT1_Property = CxvPropertyDeclaration.Register("CNSTRNT1", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CNSTTAB1"
		});

		public static readonly CxvPropertyDeclaration SETUPTAB1_Property = CxvPropertyDeclaration.Register("SETUPTAB1", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SETUPTAB1"
		});

		public static readonly CxvPropertyDeclaration entcons_Property = CxvPropertyDeclaration.Register("entcons", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCONS"
		});

		public static readonly CxvPropertyDeclaration METHOD_Property = CxvPropertyDeclaration.Register("METHOD", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.METHOD"
		});

		public static readonly CxvPropertyDeclaration ACCMET_Property = CxvPropertyDeclaration.Register("ACCMET", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCMET"
		});

		public static readonly CxvPropertyDeclaration NOSALTID_Property = CxvPropertyDeclaration.Register("NOSALTID", typeof(MMDataMixt_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NOSALTID"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMDataMixt_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SETUPTAB1", "@STATEOK", "@TWOCOMPS", "@NOSALTID" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMDataMixt_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@DATATAB1", "@DATATAB2" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMDataMixt_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CNSTRNT1", "@NOSALTID" },
			EnteredDataPaths = { "@entcons" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMDataMixt_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@METHOD" },
			AccessibleDataPaths = { "@ACCMET" }
		});

		public object choice => GetValue(choice_Property);

		public object dataname => GetValue(dataname_Property);

		public object SUBSTRID => GetValue(SUBSTRID_Property);

		public object VARVALUE => GetValue(VARVALUE_Property);

		public object DATATAB1 => GetValue(DATATAB1_Property);

		public object TWOCOMPS => GetValue(TWOCOMPS_Property);

		public object STATEOK => GetValue(STATEOK_Property);

		public object DATATAB2 => GetValue(DATATAB2_Property);

		public object CNSTRNT1 => GetValue(CNSTRNT1_Property);

		public object SETUPTAB1 => GetValue(SETUPTAB1_Property);

		public object entcons => GetValue(entcons_Property);

		public object METHOD => GetValue(METHOD_Property);

		public object ACCMET => GetValue(ACCMET_Property);

		public object NOSALTID => GetValue(NOSALTID_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp")]
	public class MMDataMixt_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMDataMixt_Inp()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp.xaml", UriKind.Relative);
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
				tabComponentSpec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp_Cnstrnts")]
	public class MMDataMixt_Inp_Cnstrnts : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPhase;

		internal MMScrollAreaHorizontal grdPhase;

		internal MMGroupBox fraChemical;

		internal MMScrollAreaHorizontal grdChemical;

		internal MMGroupBox fraChemid;

		internal MMLabel MMLable_Chemid;

		internal MMComboEdit MMComboBoxChemid;

		internal MMLabel MMLable_Rxnno;

		internal MMScrollAreaHorizontal grdChemid;

		private bool _contentLoaded;

		public MMDataMixt_Inp_Cnstrnts()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_Cnstrnts_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp_cnstrnts.xaml", UriKind.Relative);
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
				fraPhase = (MMGroupBox)target;
				break;
			case 2:
				grdPhase = (MMScrollAreaHorizontal)target;
				break;
			case 3:
				fraChemical = (MMGroupBox)target;
				break;
			case 4:
				grdChemical = (MMScrollAreaHorizontal)target;
				break;
			case 5:
				fraChemid = (MMGroupBox)target;
				break;
			case 6:
				MMLable_Chemid = (MMLabel)target;
				break;
			case 7:
				MMComboBoxChemid = (MMComboEdit)target;
				break;
			case 8:
				MMLable_Rxnno = (MMLabel)target;
				break;
			case 9:
				grdChemid = (MMScrollAreaHorizontal)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp_Data")]
	public class MMDataMixt_Inp_Data : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMCmdButton cmdRetrieveTDE;

		internal MMCmdButton cmdGenerate;

		internal MMCmdButton cmdClearUp;

		internal MMGroupBox fraData;

		internal MMScrollAreaMS grdData;

		private bool _contentLoaded;

		public MMDataMixt_Inp_Data()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_Data_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp_data.xaml", UriKind.Relative);
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
				cmdRetrieveTDE = (MMCmdButton)target;
				break;
			case 4:
				cmdGenerate = (MMCmdButton)target;
				break;
			case 5:
				cmdClearUp = (MMCmdButton)target;
				break;
			case 6:
				fraData = (MMGroupBox)target;
				break;
			case 7:
				grdData = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp_DGen")]
	public class MMDataMixt_Inp_DGen : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraGen;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel labCompMixture;

		internal MMTextEdit txtCID1;

		internal MMTextEdit txtCID2;

		internal MMLabel cboPropMethod_label;

		internal MMComboEdit cboPropMethod;

		internal MMLabel cboHenry_label;

		internal MMComboEdit cboHenry;

		internal MMLabel cboChemistry_label;

		internal MMComboEdit cboChemistry;

		internal MMCmdButton cmdGenerate;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMDataMixt_Inp_DGen()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_DGen_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp_dgen.xaml", UriKind.Relative);
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
				fraGen = (MMGroupBox)target;
				break;
			case 2:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 3:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 4:
				labCompMixture = (MMLabel)target;
				break;
			case 5:
				txtCID1 = (MMTextEdit)target;
				break;
			case 6:
				txtCID2 = (MMTextEdit)target;
				break;
			case 7:
				cboPropMethod_label = (MMLabel)target;
				break;
			case 8:
				cboPropMethod = (MMComboEdit)target;
				break;
			case 9:
				cboHenry_label = (MMLabel)target;
				break;
			case 10:
				cboHenry = (MMComboEdit)target;
				break;
			case 11:
				cboChemistry_label = (MMLabel)target;
				break;
			case 12:
				cboChemistry = (MMComboEdit)target;
				break;
			case 13:
				cmdGenerate = (MMCmdButton)target;
				break;
			case 14:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	public class MMDataMixt_Inp_Equip_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraMeasMethod_state_Property = CxvPropertyDeclaration.Register("fraMeasMethod_state", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.ACCMET"
			}
		});

		public static readonly CxvPropertyDeclaration cboMeasurementMethod_MultiMap_Property = CxvPropertyDeclaration.Register("cboMeasurementMethod_MultiMap", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboMeasurementMethod_Equipment",
					DataPath = "@main.Input.EQUIPMENT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Ebulliometry method",
					DisplayResourceKey = "MMDataMixt_Inp_Equip_ViewModel__CxvMultiMapOption_Display_Ebulliometry_method",
					Value = "cboMeasurementMethod_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMeasurementMethod_Equipment",
							Value = "EBULLIOMETER"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Static method",
					DisplayResourceKey = "MMDataMixt_Inp_Equip_ViewModel__CxvMultiMapOption_Display_Static_method",
					Value = "cboMeasurementMethod_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMeasurementMethod_Equipment",
							Value = "STATIC-CELL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration fraEquipConst_state_Property = CxvPropertyDeclaration.Register("fraEquipConst_state", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.ACCMET"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuStaticConst_0_var1_Property = CxvPropertyDeclaration.Register("lbtuStaticConst_0_var1", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.RATIO_VOLUME",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RVOLQUA"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuCellVolume_0_var1_Property = CxvPropertyDeclaration.Register("lbtuCellVolume_0_var1", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.CELL_VOLUME",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CELLVOL"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuEbulConst_0_var1_Property = CxvPropertyDeclaration.Register("lbtuEbulConst_0_var1", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.EBUL_CONST",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RVOLQUAL"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuCoefEvap_0_var1_Property = CxvPropertyDeclaration.Register("lbtuCoefEvap_0_var1", typeof(MMDataMixt_Inp_Equip_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.RATIO_VL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RVOLQUAL"
			}
		});

		public object fraMeasMethod_state => GetValue(fraMeasMethod_state_Property);

		public object cboMeasurementMethod_MultiMap => GetValue(cboMeasurementMethod_MultiMap_Property);

		public object fraEquipConst_state => GetValue(fraEquipConst_state_Property);

		public object lbtuStaticConst_0_var1 => GetValue(lbtuStaticConst_0_var1_Property);

		public object lbtuCellVolume_0_var1 => GetValue(lbtuCellVolume_0_var1_Property);

		public object lbtuEbulConst_0_var1 => GetValue(lbtuEbulConst_0_var1_Property);

		public object lbtuCoefEvap_0_var1 => GetValue(lbtuCoefEvap_0_var1_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp_Equip")]
	public class MMDataMixt_Inp_Equip : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraMeasMethod;

		internal MMComboEdit cboMeasurementMethod;

		internal MMGroupBox fraEquipConst;

		internal MMLabel lbtuCoefEvap_0_label;

		internal MMVariableEdit lbtuCoefEvap_0;

		internal MMLabel lbtuEbulConst_0_label;

		internal MMVariableEdit lbtuEbulConst_0;

		internal MMLabel lbtuStaticConst_0_label;

		internal MMVariableEdit lbtuStaticConst_0;

		internal MMLabel lbtuCellVolume_0_label;

		internal MMVariableEdit lbtuCellVolume_0;

		private bool _contentLoaded;

		public MMDataMixt_Inp_Equip()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_Equip_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp_equip.xaml", UriKind.Relative);
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
				fraMeasMethod = (MMGroupBox)target;
				break;
			case 2:
				cboMeasurementMethod = (MMComboEdit)target;
				break;
			case 3:
				fraEquipConst = (MMGroupBox)target;
				break;
			case 4:
				lbtuCoefEvap_0_label = (MMLabel)target;
				break;
			case 5:
				lbtuCoefEvap_0 = (MMVariableEdit)target;
				break;
			case 6:
				lbtuEbulConst_0_label = (MMLabel)target;
				break;
			case 7:
				lbtuEbulConst_0 = (MMVariableEdit)target;
				break;
			case 8:
				lbtuStaticConst_0_label = (MMLabel)target;
				break;
			case 9:
				lbtuStaticConst_0 = (MMVariableEdit)target;
				break;
			case 10:
				lbtuCellVolume_0_label = (MMLabel)target;
				break;
			case 11:
				lbtuCellVolume_0 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Data.Mixture
{
	[ProgId("MMDataMixt.MMDataMixt_Inp_Setup")]
	public class MMDataMixt_Inp_Setup : MMTabPage, IComponentConnector
	{
		internal MMLabel cboEqulibrium_label;

		internal MMComboEdit cboEqulibrium;

		internal MMLabel cboDatatype_label;

		internal MMComboEdit cboDatatype;

		internal MMListPicker lstpMixture;

		internal MMGroupBox MMFrame1;

		internal MMLabel lbutTemperature_label;

		internal MMVariableEdit lbutTemperature;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox fraCompositionBasis;

		internal MMLabel cboCompositionBasis_label;

		internal MMComboEdit cboCompositionBasis;

		internal MMLabel cboCompBasisUnit_label;

		internal MMComboEdit cboCompBasisUnit;

		private bool _contentLoaded;

		public MMDataMixt_Inp_Setup()
		{
			base.ViewModelType = typeof(MMDataMixt_Inp_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/data/mixture/mmdatamixt_inp_setup.xaml", UriKind.Relative);
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
				cboEqulibrium_label = (MMLabel)target;
				break;
			case 2:
				cboEqulibrium = (MMComboEdit)target;
				break;
			case 3:
				cboDatatype_label = (MMLabel)target;
				break;
			case 4:
				cboDatatype = (MMComboEdit)target;
				break;
			case 5:
				lstpMixture = (MMListPicker)target;
				break;
			case 6:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 7:
				lbutTemperature_label = (MMLabel)target;
				break;
			case 8:
				lbutTemperature = (MMVariableEdit)target;
				break;
			case 9:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 10:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 11:
				fraCompositionBasis = (MMGroupBox)target;
				break;
			case 12:
				cboCompositionBasis_label = (MMLabel)target;
				break;
			case 13:
				cboCompositionBasis = (MMComboEdit)target;
				break;
			case 14:
				cboCompBasisUnit_label = (MMLabel)target;
				break;
			case 15:
				cboCompBasisUnit = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.CO_Package
{
	public class MMCOPackage_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMCOPackage_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCOPackage_Input_ViewModel), new CxvTabItemProperty
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.CO_Package
{
	[ProgId("MMCOPackage.MMCOPackage_Input")]
	public class MMCOPackage_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabProp_Spec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMCOPackage_Input()
		{
			base.ViewModelType = typeof(MMCOPackage_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/co%20package/mmcopackage_input.xaml", UriKind.Relative);
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
				tabProp_Spec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.CO_Package
{
	[ProgId("MMCOPackage.MMCOPackage_Input_Comp")]
	public class MMCOPackage_Input_Comp : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComp;

		internal MMScrollArea grdReaction_Names1;

		private bool _contentLoaded;

		public MMCOPackage_Input_Comp()
		{
			base.ViewModelType = typeof(MMCOPackage_Input_Comp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/co%20package/mmcopackage_input_comp.xaml", UriKind.Relative);
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
				fraComp = (MMGroupBox)target;
				break;
			case 2:
				grdReaction_Names1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.CO_Package
{
	[ProgId("MMCOPackage.MMCOPackage_Input_Prop")]
	public class MMCOPackage_Input_Prop : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMGroupBox MMFrame3;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMCheckBox MMCheckBox1;

		internal MMLabel cboHenryComps_label;

		internal MMComboEdit cboHenryComps;

		internal MMGroupBox fraElecCal;

		internal MMLabel cboChemId_label;

		internal MMComboEdit cboChemId;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		internal MMGroupBox fraPetroOptions;

		internal MMLabel cboFreeWatProp_label;

		internal MMComboEdit cboFreeWatProp;

		internal MMLabel cboWaterSol_label;

		internal MMComboEdit cboWaterSol;

		private bool _contentLoaded;

		public MMCOPackage_Input_Prop()
		{
			base.ViewModelType = typeof(MMCOPackage_Input_Prop_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/co%20package/mmcopackage_input_prop.xaml", UriKind.Relative);
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
				MMLBUText3_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 8:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 9:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 10:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 12:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 13:
				cboHenryComps_label = (MMLabel)target;
				break;
			case 14:
				cboHenryComps = (MMComboEdit)target;
				break;
			case 15:
				fraElecCal = (MMGroupBox)target;
				break;
			case 16:
				cboChemId_label = (MMLabel)target;
				break;
			case 17:
				cboChemId = (MMComboEdit)target;
				break;
			case 18:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 19:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			case 20:
				fraPetroOptions = (MMGroupBox)target;
				break;
			case 21:
				cboFreeWatProp_label = (MMLabel)target;
				break;
			case 22:
				cboFreeWatProp = (MMComboEdit)target;
				break;
			case 23:
				cboWaterSol_label = (MMLabel)target;
				break;
			case 24:
				cboWaterSol = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.CO_Package
{
	[ProgId("MMCOPackage.MMCOPackage_List1D")]
	public class MMCOPackage_List1D : MMTabPage, IComponentConnector
	{
		internal MMFlatButton cmdAdd;

		internal MMFlatButton cmdEdit;

		internal MMFlatButton cmdDelete;

		internal MMFlatButton cmdRename;

		internal MMFlatButton cmdImport;

		internal MMScrollArea grdChild;

		private bool _contentLoaded;

		public MMCOPackage_List1D()
		{
			base.ViewModelType = typeof(MMCOPackage_List1D_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/co%20package/mmcopackage_list1d.xaml", UriKind.Relative);
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
				cmdEdit = (MMFlatButton)target;
				break;
			case 3:
				cmdDelete = (MMFlatButton)target;
				break;
			case 4:
				cmdRename = (MMFlatButton)target;
				break;
			case 5:
				cmdImport = (MMFlatButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	public class MMAPr_Pr_Spec_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMAPr_Pr_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAPr_Pr_Spec_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration entref_Property = CxvPropertyDeclaration.Register("entref", typeof(MMAPr_Pr_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTREF"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Pr_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Pr_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entref" }
		});

		public object global => GetValue(global_Property);

		public object choice => GetValue(choice_Property);

		public object entref => GetValue(entref_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	[ProgId("MMAPr_Pr_Spec.MMAPr_Pr_Spec_Input")]
	public class MMAPr_Pr_Spec_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabProp_Spec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMAPr_Pr_Spec_Input()
		{
			base.ViewModelType = typeof(MMAPr_Pr_Spec_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/apr_specifications/mmapr_pr_spec_input.xaml", UriKind.Relative);
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
				tabProp_Spec = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	[ProgId("MMAPr_Pr_Spec.MMAPr_Pr_Spec_In_Global")]
	public class MMAPr_Pr_Spec_In_Global : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fra_Property_Methods_Models;

		internal MMLabel cboGPProcessType_label;

		internal MMComboEdit cboGPProcessType;

		internal MMLabel MMComboBox4_label;

		internal MMLabel lblBase_Method;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox fraPetroleumCalculationOptions;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMGroupBox fraElectrolyteCalculationOptions;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMCheckBox MMCheckBox1;

		internal MMLabel MMLabel1;

		internal MMComboEdit MMComboBox3;

		internal MMCmdButton CmdAssistant;

		internal MMGroupBox fraModels;

		internal MMLabel lblVaporEOS;

		internal MMLabel lblEOS;

		internal MMComboEdit cboVaporEOS;

		internal MMLabel spnVaporEOS_label;

		internal MMSpinBox spnVaporEOS;

		internal MMLabel cboLiquidGamma_label;

		internal MMComboEdit cboLiquidGamma;

		internal MMLabel spnDataSetLiqdGamma_label;

		internal MMSpinBox spnDataSetLiqdGamma;

		internal MMLabel cboLiquidEnthalpy_label;

		internal MMComboEdit cboLiquidEnthalpy;

		internal MMLabel cboLiquidDensity_label;

		internal MMComboEdit cboLiquidDensity;

		internal MMCheckBox chkHeatofMixing;

		internal MMCheckBox chkPoyntingCorrection;

		internal MMCheckBox chkLiqRefState;

		internal MMCheckBox chkModifyglobal;

		private bool _contentLoaded;

		public MMAPr_Pr_Spec_In_Global()
		{
			base.ViewModelType = typeof(MMAPr_Pr_Spec_In_Global_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/apr_specifications/mmapr_pr_spec_in_global.xaml", UriKind.Relative);
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
				fra_Property_Methods_Models = (MMGroupBox)target;
				break;
			case 2:
				cboGPProcessType_label = (MMLabel)target;
				break;
			case 3:
				cboGPProcessType = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 5:
				lblBase_Method = (MMLabel)target;
				break;
			case 6:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 7:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 8:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 9:
				fraPetroleumCalculationOptions = (MMGroupBox)target;
				break;
			case 10:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 11:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 12:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 14:
				fraElectrolyteCalculationOptions = (MMGroupBox)target;
				break;
			case 15:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 16:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 17:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 18:
				MMLabel1 = (MMLabel)target;
				break;
			case 19:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 20:
				CmdAssistant = (MMCmdButton)target;
				break;
			case 21:
				fraModels = (MMGroupBox)target;
				break;
			case 22:
				lblVaporEOS = (MMLabel)target;
				break;
			case 23:
				lblEOS = (MMLabel)target;
				break;
			case 24:
				cboVaporEOS = (MMComboEdit)target;
				break;
			case 25:
				spnVaporEOS_label = (MMLabel)target;
				break;
			case 26:
				spnVaporEOS = (MMSpinBox)target;
				break;
			case 27:
				cboLiquidGamma_label = (MMLabel)target;
				break;
			case 28:
				cboLiquidGamma = (MMComboEdit)target;
				break;
			case 29:
				spnDataSetLiqdGamma_label = (MMLabel)target;
				break;
			case 30:
				spnDataSetLiqdGamma = (MMSpinBox)target;
				break;
			case 31:
				cboLiquidEnthalpy_label = (MMLabel)target;
				break;
			case 32:
				cboLiquidEnthalpy = (MMComboEdit)target;
				break;
			case 33:
				cboLiquidDensity_label = (MMLabel)target;
				break;
			case 34:
				cboLiquidDensity = (MMComboEdit)target;
				break;
			case 35:
				chkHeatofMixing = (MMCheckBox)target;
				break;
			case 36:
				chkPoyntingCorrection = (MMCheckBox)target;
				break;
			case 37:
				chkLiqRefState = (MMCheckBox)target;
				break;
			case 38:
				chkModifyglobal = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	public class MMAPr_Pr_Spec_In_Refer_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lstpSelectMethods_copybopset_Property = CxvPropertyDeclaration.Register("lstpSelectMethods_copybopset", typeof(MMAPr_Pr_Spec_In_Refer_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.BOPSETNAME",
			AllowSort = false
		});

		public object lstpSelectMethods_copybopset => GetValue(lstpSelectMethods_copybopset_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	[ProgId("MMAPr_Pr_Spec.MMAPr_Pr_Spec_In_Refer")]
	public class MMAPr_Pr_Spec_In_Refer : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpSelectMethods;

		private bool _contentLoaded;

		public MMAPr_Pr_Spec_In_Refer()
		{
			base.ViewModelType = typeof(MMAPr_Pr_Spec_In_Refer_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/apr_specifications/mmapr_pr_spec_in_refer.xaml", UriKind.Relative);
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
				lstpSelectMethods = (MMListPicker)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.APr_Specifications
{
	[ProgId("MMAPr_Pr_Spec.MMProp_Spec_GopsetNameDB")]
	public class MMProp_Spec_GopsetNameDB : MMTabPage, IComponentConnector
	{
		internal MMLabel txtOpsetName_label;

		internal MMVariableEdit txtOpsetName;

		internal MMCmdButton cmdOK;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMProp_Spec_GopsetNameDB()
		{
			base.ViewModelType = typeof(MMProp_Spec_GopsetNameDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/apr_specifications/mmprop_spec_gopsetnamedb.xaml", UriKind.Relative);
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
				txtOpsetName_label = (MMLabel)target;
				break;
			case 2:
				txtOpsetName = (MMVariableEdit)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis
{
	internal class MMListPickerForPropSet : MMListPicker
	{
		public override void ExecuteDefineNew()
		{
			if (base.Variable is CxvListVariableData cxvListVariableData)
			{
				IEnumerable<string> second = CloneValues(cxvListVariableData.Value);
				base.ExecuteDefineNew();
				CxsDataProvider cxsDataProvider = null;
				if (cxvListVariableData.DataContainer != null && cxvListVariableData.DataContainer.ResolvedCxsProvider != null)
				{
					cxsDataProvider = cxvListVariableData.DataContainer.ResolvedCxsProvider;
					cxsDataProvider.UpdateDataCache();
				}
				string text = CloneValues(cxvListVariableData.Value).Except(second).FirstOrDefault();
				if (!string.IsNullOrEmpty(text) && cxsDataProvider != null)
				{
					cxvListVariableData.DataContainer.ResolvedCxsProvider.BatchSet($"Top.appModelV8.Properties.Prop-Sets.{text}.Input.SHOWDLG", "value", null, 1);
				}
			}
		}

		private static IEnumerable<string> CloneValues(IEnumerable<string> oldValues)
		{
			List<string> list = new List<string>();
			if (oldValues != null)
			{
				list.AddRange(oldValues);
			}
			return list;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_ProfileTer_DB")]
	public class MMAnalysis_ProfileTer_DB : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogresult;

		internal MMOptionButton ogresult_opt0;

		internal MMOptionButton ogresult_opt1;

		internal MMOptionButton ogresult_opt2;

		internal MMGroupBox MMFrame3;

		internal MMScrollArea MMScrollArea2;

		internal MMGroupBox MMFrame2;

		internal MMScrollArea MMScrollArea1;

		internal MMGroupBox MMFrame1;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_ProfileTer_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_ProfileTer_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_profileter_db.xaml", UriKind.Relative);
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
				ogresult = (MMOptionGroup)target;
				break;
			case 2:
				ogresult_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogresult_opt1 = (MMOptionButton)target;
				break;
			case 4:
				ogresult_opt2 = (MMOptionButton)target;
				break;
			case 5:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 6:
				MMScrollArea2 = (MMScrollArea)target;
				break;
			case 7:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 8:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 9:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 10:
				grdResults = (MMScrollArea)target;
				break;
			case 11:
				cmdPlotwiz = (MMCmdButton)target;
				break;
			case 12:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_TernaryMap_DB")]
	public class MMAnalysis_TernaryMap_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMLabel MMSpintieline_label;

		internal MMSpinBox MMSpintieline;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMGroupBox temperature;

		internal MMVariableEdit MMLBUText1;

		internal MMCmdButton cmdSaveAsForm;

		internal MMCmdButton cmdGo;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_TernaryMap_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_TernaryMap_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ternarymap_db.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				MMSpintieline_label = (MMLabel)target;
				break;
			case 9:
				MMSpintieline = (MMSpinBox)target;
				break;
			case 10:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 11:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 12:
				FraPressure = (MMGroupBox)target;
				break;
			case 13:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 14:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 15:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 16:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 17:
				temperature = (MMGroupBox)target;
				break;
			case 18:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 19:
				cmdSaveAsForm = (MMCmdButton)target;
				break;
			case 20:
				cmdGo = (MMCmdButton)target;
				break;
			case 21:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	public class MMAnalysis_Ter_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration tern_Property = CxvPropertyDeclaration.Register("tern", typeof(MMAnalysis_Ter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TERN"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_Ter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Ter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.TERN"
		});

		public static readonly CxvPropertyDeclaration accrestie_Property = CxvPropertyDeclaration.Register("accrestie", typeof(MMAnalysis_Ter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.TIEN"
		});

		public static readonly CxvPropertyDeclaration accreaze_Property = CxvPropertyDeclaration.Register("accreaze", typeof(MMAnalysis_Ter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.AZET"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@tern" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accrestie" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accreaze" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Ter_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres", "@accrestie", "@accreaze" }
		});

		public object tern => GetValue(tern_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object accrestie => GetValue(accrestie_Property);

		public object accreaze => GetValue(accreaze_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_In")]
	public class MMAnalysis_Ter_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisTernary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Ter_In()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_in.xaml", UriKind.Relative);
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
				tabAnalysisTernary = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	public class MMAnalysis_Ter_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuTolerance_tolerance_Property = CxvPropertyDeclaration.Register("lbtuTolerance_tolerance", typeof(MMAnalysis_Ter_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL"
		});

		public static readonly CxvPropertyDeclaration spnMaximumIterations_maxit_Property = CxvPropertyDeclaration.Register("spnMaximumIterations_maxit", typeof(MMAnalysis_Ter_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_Ter_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_Ter_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Ter_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object lbtuTolerance_tolerance => GetValue(lbtuTolerance_tolerance_Property);

		public object spnMaximumIterations_maxit => GetValue(spnMaximumIterations_maxit_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Ter_In_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Ter_In_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_In_Diag")]
	public class MMAnalysis_Ter_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		internal MMGroupBox fraEnterFlashCalculationConvergenceParameters;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		private bool _contentLoaded;

		public MMAnalysis_Ter_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			case 14:
				fraEnterFlashCalculationConvergenceParameters = (MMGroupBox)target;
				break;
			case 15:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 16:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 17:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 18:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	public class MMAnalysis_Ter_In_Syst_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboComp1Gibbs_comps_Property = CxvPropertyDeclaration.Register("cboComp1Gibbs_comps", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.COMPS"
		});

		public static readonly CxvPropertyDeclaration cboComp2Gibbs_comp2_Property = CxvPropertyDeclaration.Register("cboComp2Gibbs_comp2", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.COMP2"
		});

		public static readonly CxvPropertyDeclaration cboComponent3_comp3_Property = CxvPropertyDeclaration.Register("cboComponent3_comp3", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.COMP3"
		});

		public static readonly CxvPropertyDeclaration lbtuPressure_pres_Property = CxvPropertyDeclaration.Register("lbtuPressure_pres", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES"
		});

		public static readonly CxvPropertyDeclaration cboValidPhases_MultiMap_Property = CxvPropertyDeclaration.Register("cboValidPhases_MultiMap", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboValidPhases_var1",
					DataPath = "@main.Input.PHASE_EQ"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Liquid-Liquid",
					DisplayResourceKey = "MMAnalysis_Ter_In_Syst_ViewModel__CxvMultiMapOption_Display_Liquid_Liquid",
					Prompt = "2 liquid phases are considered in phase equilibrium calculations (no vapor)",
					PromptResourceKey = "ValidPhaseOption_Prompt_LL",
					Value = "cboValidPhases_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "LL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMAnalysis_Ter_In_Syst_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboValidPhases_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboValidPhases_var1",
							Value = "VLL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTemperature_temp_Property = CxvPropertyDeclaration.Register("lbtuTemperature_temp", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP"
		});

		public static readonly CxvPropertyDeclaration MMSpinBox1_ntieline_Property = CxvPropertyDeclaration.Register("MMSpinBox1_ntieline", typeof(MMAnalysis_Ter_In_Syst_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NTIELINE"
		});

		public object cboComp1Gibbs_comps => GetValue(cboComp1Gibbs_comps_Property);

		public object cboComp2Gibbs_comp2 => GetValue(cboComp2Gibbs_comp2_Property);

		public object cboComponent3_comp3 => GetValue(cboComponent3_comp3_Property);

		public object lbtuPressure_pres => GetValue(lbtuPressure_pres_Property);

		public object cboValidPhases_MultiMap => GetValue(cboValidPhases_MultiMap_Property);

		public object lbtuTemperature_temp => GetValue(lbtuTemperature_temp_Property);

		public object MMSpinBox1_ntieline => GetValue(MMSpinBox1_ntieline_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_In_Syst")]
	public class MMAnalysis_Ter_In_Syst : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox FraNumTieline;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox FraTemperature;

		internal MMVariableEdit lbtuTemperature;

		private bool _contentLoaded;

		public MMAnalysis_Ter_In_Syst()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_In_Syst_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_in_syst.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 9:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 10:
				FraPressure = (MMGroupBox)target;
				break;
			case 11:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 12:
				FraNumTieline = (MMGroupBox)target;
				break;
			case 13:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 14:
				FraTemperature = (MMGroupBox)target;
				break;
			case 15:
				lbtuTemperature = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_In_Tern")]
	public class MMAnalysis_Ter_In_Tern : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox FraNumTieline;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox temperature;

		internal MMVariableEdit MMLBUText1;

		internal MMCmdButton cmdRunAnalysis;

		internal MMCmdButton cmdSaveAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Ter_In_Tern()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_In_Tern_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Ter_In_Tern_Loaded;
		}

		private void MMAnalysis_Ter_In_Tern_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_in_tern.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 9:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 10:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 11:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 12:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 13:
				FraPressure = (MMGroupBox)target;
				break;
			case 14:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 15:
				FraNumTieline = (MMGroupBox)target;
				break;
			case 16:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 17:
				temperature = (MMGroupBox)target;
				break;
			case 18:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 19:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			case 20:
				cmdSaveAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	public class MMAnalysis_Ter_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.TERN"
		});

		public static readonly CxvPropertyDeclaration accrestie_Property = CxvPropertyDeclaration.Register("accrestie", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.TIEN"
		});

		public static readonly CxvPropertyDeclaration accreaze_Property = CxvPropertyDeclaration.Register("accreaze", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.AZET"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accrestie" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Ter_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accreaze" }
		});

		public object accres => GetValue(accres_Property);

		public object accrestie => GetValue(accrestie_Property);

		public object accreaze => GetValue(accreaze_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_Out")]
	public class MMAnalysis_Ter_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisTernaryResults;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Ter_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_out.xaml", UriKind.Relative);
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
				tabAnalysisTernaryResults = (MMTabStrip)target;
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_Out_Aze")]
	public class MMAnalysis_Ter_Out_Aze : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResult3;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Ter_Out_Aze()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_Out_Aze_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_out_aze.xaml", UriKind.Relative);
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
				fraResult3 = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_Out_Tern")]
	public class MMAnalysis_Ter_Out_Tern : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Ter_Out_Tern()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_Out_Tern_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_out_tern.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.TernaryMap
{
	[ProgId("MMAnalysis_Ter.MMAnalysis_Ter_Out_Tie")]
	public class MMAnalysis_Ter_Out_Tie : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResult2;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Ter_Out_Tie()
		{
			base.ViewModelType = typeof(MMAnalysis_Ter_Out_Tie_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ternarymap/mmanalysis_ter_out_tie.xaml", UriKind.Relative);
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
				fraResult2 = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Bubble")]
	public class MMAnalysis_Stm_Bubble : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox3;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMLBUTlow_label;

		internal MMVariableEdit MMLBUTlow;

		internal MMLabel MMLBUTupp_label;

		internal MMVariableEdit MMLBUTupp;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox MMFrame3;

		internal MMScrollArea MMScrollArea1;

		internal MMCmdButton CmdRunAnalysis;

		internal MMCmdButton CmdSaveAnalysis;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Bubble()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Bubble_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Stm_Bubble_Loaded;
		}

		private void MMAnalysis_Stm_Bubble_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(CmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_bubble.xaml", UriKind.Relative);
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
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 6:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 7:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 8:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 9:
				MMLBUTlow_label = (MMLabel)target;
				break;
			case 10:
				MMLBUTlow = (MMVariableEdit)target;
				break;
			case 11:
				MMLBUTupp_label = (MMLabel)target;
				break;
			case 12:
				MMLBUTupp = (MMVariableEdit)target;
				break;
			case 13:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 14:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 15:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 16:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 17:
				CmdRunAnalysis = (MMCmdButton)target;
				break;
			case 18:
				CmdSaveAnalysis = (MMCmdButton)target;
				break;
			case 19:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Compfl")]
	public class MMAnalysis_Stm_Compfl : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBoxmole;

		internal MMCheckBox MMCheckBoxmass;

		internal MMCheckBox MMCheckBoxstandard;

		internal MMCmdButton CmdGo;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Compfl()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Compfl_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_compfl.xaml", UriKind.Relative);
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
				MMCheckBoxmole = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBoxmass = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBoxstandard = (MMCheckBox)target;
				break;
			case 7:
				CmdGo = (MMCmdButton)target;
				break;
			case 8:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Compsi")]
	public class MMAnalysis_Stm_Compsi : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBoxmole;

		internal MMCheckBox MMCheckBoxmass;

		internal MMCheckBox MMCheckBoxstandard;

		internal MMCheckBox MMCheckBoxparpres;

		internal MMCmdButton CmdGo;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Compsi()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Compsi_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_compsi.xaml", UriKind.Relative);
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
				MMCheckBoxmole = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBoxmass = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBoxstandard = (MMCheckBox)target;
				break;
			case 7:
				MMCheckBoxparpres = (MMCheckBox)target;
				break;
			case 8:
				CmdGo = (MMCmdButton)target;
				break;
			case 9:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Discur")]
	public class MMAnalysis_Stm_Discur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMCmdButton CmdGo;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Discur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Discur_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_discur.xaml", UriKind.Relative);
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
				CmdGo = (MMCmdButton)target;
				break;
			case 4:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Petrol")]
	public class MMAnalysis_Stm_Petrol : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBoxmole;

		internal MMCheckBox MMCheckBoxmass;

		internal MMCheckBox MMCheckBoxvolume;

		internal MMGroupBox MMFrame2;

		internal MMCheckBox MMCheckBoxthermody;

		internal MMCheckBox MMCheckBoxtrans;

		internal MMCmdButton CmdGo;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Petrol()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Petrol_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_petrol.xaml", UriKind.Relative);
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
				MMCheckBoxmole = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBoxmass = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBoxvolume = (MMCheckBox)target;
				break;
			case 7:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 8:
				MMCheckBoxthermody = (MMCheckBox)target;
				break;
			case 9:
				MMCheckBoxtrans = (MMCheckBox)target;
				break;
			case 10:
				CmdGo = (MMCmdButton)target;
				break;
			case 11:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Point")]
	public class MMAnalysis_Stm_Point : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBoxmole;

		internal MMCheckBox MMCheckBoxmass;

		internal MMCheckBox MMCheckBoxvolume;

		internal MMGroupBox MMFrame2;

		internal MMCheckBox MMCheckBoxthermody;

		internal MMCheckBox MMCheckBoxtrans;

		internal MMCmdButton CmdGo;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Point()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Point_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_point.xaml", UriKind.Relative);
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
				MMCheckBoxmole = (MMCheckBox)target;
				break;
			case 5:
				MMCheckBoxmass = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBoxvolume = (MMCheckBox)target;
				break;
			case 7:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 8:
				MMCheckBoxthermody = (MMCheckBox)target;
				break;
			case 9:
				MMCheckBoxtrans = (MMCheckBox)target;
				break;
			case 10:
				CmdGo = (MMCmdButton)target;
				break;
			case 11:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Pvcur")]
	public class MMAnalysis_Stm_Pvcur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMLBUTlow_label;

		internal MMVariableEdit MMLBUTlow;

		internal MMLabel MMLBUTupp_label;

		internal MMVariableEdit MMLBUTupp;

		internal MMLabel MMSpinpoint_label;

		internal MMSpinBox MMSpinpoint;

		internal MMCmdButton CmdRunAnalysis;

		internal MMCmdButton CmdSaveAnalysis;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Pvcur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Pvcur_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Stm_Pvcur_Loaded;
		}

		private void MMAnalysis_Stm_Pvcur_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(CmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_pvcur.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				MMLBUTlow_label = (MMLabel)target;
				break;
			case 7:
				MMLBUTlow = (MMVariableEdit)target;
				break;
			case 8:
				MMLBUTupp_label = (MMLabel)target;
				break;
			case 9:
				MMLBUTupp = (MMVariableEdit)target;
				break;
			case 10:
				MMSpinpoint_label = (MMLabel)target;
				break;
			case 11:
				MMSpinpoint = (MMSpinBox)target;
				break;
			case 12:
				CmdRunAnalysis = (MMCmdButton)target;
				break;
			case 13:
				CmdSaveAnalysis = (MMCmdButton)target;
				break;
			case 14:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResBubble")]
	public class MMAnalysis_Stm_ResBubble : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResBubble()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResBubble_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_resbubble.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResCompfl")]
	public class MMAnalysis_Stm_ResCompfl : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResCompfl()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResCompfl_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_rescompfl.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResCompsi")]
	public class MMAnalysis_Stm_ResCompsi : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResCompsi()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResCompsi_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_rescompsi.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResDiscur")]
	public class MMAnalysis_Stm_ResDiscur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox frmResult;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResDiscur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResDiscur_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_resdiscur.xaml", UriKind.Relative);
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
				frmResult = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
				break;
			case 5:
				cmdPlotwiz = (MMCmdButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResPetrol")]
	public class MMAnalysis_Stm_ResPetrol : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResPetrol()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResPetrol_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_respetrol.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResPoint")]
	public class MMAnalysis_Stm_ResPoint : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox frmResult;

		internal MMScrollArea grdResults;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResPoint()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResPoint_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_respoint.xaml", UriKind.Relative);
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
				frmResult = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResPvcur")]
	public class MMAnalysis_Stm_ResPvcur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResPvcur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResPvcur_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_respvcur.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_ResTvcur")]
	public class MMAnalysis_Stm_ResTvcur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraResults;

		internal MMScrollArea grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Stm_ResTvcur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_ResTvcur_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_restvcur.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 4:
				grdResults = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Stream
{
	[ProgId("MMAnalysis_Stm.MMAnalysis_Stm_Tvcur")]
	public class MMAnalysis_Stm_Tvcur : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMLBUTlow_label;

		internal MMVariableEdit MMLBUTlow;

		internal MMLabel MMLBUTupp_label;

		internal MMVariableEdit MMLBUTupp;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMCmdButton CmdRunAnalysis;

		internal MMCmdButton CmdSaveAnalysis;

		internal MMCmdButton CmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Stm_Tvcur()
		{
			base.ViewModelType = typeof(MMAnalysis_Stm_Tvcur_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Stm_Tvcur_Loaded;
		}

		private void MMAnalysis_Stm_Tvcur_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(CmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/stream/mmanalysis_stm_tvcur.xaml", UriKind.Relative);
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
				MMFrame2 = (MMGroupBox)target;
				break;
			case 4:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 6:
				MMLBUTlow_label = (MMLabel)target;
				break;
			case 7:
				MMLBUTlow = (MMVariableEdit)target;
				break;
			case 8:
				MMLBUTupp_label = (MMLabel)target;
				break;
			case 9:
				MMLBUTupp = (MMVariableEdit)target;
				break;
			case 10:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 11:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 12:
				CmdRunAnalysis = (MMCmdButton)target;
				break;
			case 13:
				CmdSaveAnalysis = (MMCmdButton)target;
				break;
			case 14:
				CmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	public class MMAnalysis_Solubility_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SPEC_Property = CxvPropertyDeclaration.Register("SPEC", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTTABU"
		});

		public static readonly CxvPropertyDeclaration entcalc_Property = CxvPropertyDeclaration.Register("entcalc", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration bkop_Property = CxvPropertyDeclaration.Register("bkop", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entdig_Property = CxvPropertyDeclaration.Register("entdig", typeof(MMAnalysis_Solubility_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SPEC" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@bkop" },
			EnteredDataPaths = { "@entcalc" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdig" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Solubility_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object SPEC => GetValue(SPEC_Property);

		public object tabu => GetValue(tabu_Property);

		public object entcalc => GetValue(entcalc_Property);

		public object bkop => GetValue(bkop_Property);

		public object accres => GetValue(accres_Property);

		public object entdig => GetValue(entdig_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	[ProgId("MMAnalysis_Solubility.MMAnalysis_Solubility")]
	public class MMAnalysis_Solubility : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab2;

		internal MMTabItem tab1;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Solubility()
		{
			base.ViewModelType = typeof(MMAnalysis_Solubility_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/solubility/mmanalysis_solubility.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab1 = (MMTabItem)target;
				break;
			case 5:
				tab3 = (MMTabItem)target;
				break;
			case 6:
				tab4 = (MMTabItem)target;
				break;
			case 7:
				tabInfo = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	[ProgId("MMAnalysis_Solubility.MMAnalysis_Solubility_CalcOptions")]
	public class MMAnalysis_Solubility_CalcOptions : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraValidPhases;

		internal MMLabel MMLabel_5_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboFlashType_label;

		internal MMComboEdit cboFlashType;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		internal MMLabel cboFlashMethod_label;

		internal MMComboEdit cboFlashMethod;

		internal MMCheckBox chkRestart;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMComboEdit cboChemistryGibbs;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		private bool _contentLoaded;

		public MMAnalysis_Solubility_CalcOptions()
		{
			base.ViewModelType = typeof(MMAnalysis_Solubility_CalcOptions_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/solubility/mmanalysis_solubility_calcoptions.xaml", UriKind.Relative);
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
				fraValidPhases = (MMGroupBox)target;
				break;
			case 2:
				MMLabel_5_label = (MMLabel)target;
				break;
			case 3:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 4:
				cboFlashType_label = (MMLabel)target;
				break;
			case 5:
				cboFlashType = (MMComboEdit)target;
				break;
			case 6:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 7:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 8:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 9:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			case 10:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 11:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 12:
				chkRestart = (MMCheckBox)target;
				break;
			case 13:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 14:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 15:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 16:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 17:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 18:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 19:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 20:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 21:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	[ProgId("MMAnalysis_Solubility.MMAnalysis_Solubility_Results")]
	public class MMAnalysis_Solubility_Results : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Solubility_Results()
		{
			base.ViewModelType = typeof(MMAnalysis_Solubility_Results_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/solubility/mmanalysis_solubility_results.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	[ProgId("MMAnalysis_Solubility.MMAnalysis_Solubility_Solubility")]
	public class MMAnalysis_Solubility_Solubility : MMTabPage, IComponentConnector
	{
		internal MMExpander spec;

		internal MMLabel SoluteComp_label;

		internal MMGroupBox Proper_Rep;

		internal MMListPickerForPropSet MMListPicker;

		internal MMLabel SolventComp_label;

		internal MMGroupBox MMGroupBox_SolventComp;

		internal MMVariableEdit lbtuBasis;

		internal MMScrollArea grdSystem;

		internal MMValueEdit txtTotal;

		internal MMExpander phase;

		internal MMLabel cboValidPhases_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboSoluPhases_label;

		internal MMComboEdit cboSoluPhases;

		internal MMLabel cboPropMethod_label;

		internal MMComboEdit cboPropMethod;

		internal MMLabel cboChemistry_label;

		internal MMComboEdit cboChemistry;

		internal MMExpander spec2;

		internal MMLabel ManipulatedVar_label;

		internal MMOptionGroup Manipulated_Var;

		internal MMComboEdit cboVariable_AdvCollection1_Comb;

		internal MMComboEdit cboVariable_Comp1;

		internal MMOptionButton ogrComp_opt1;

		internal MMOptionButton ogrComp_opt2;

		internal MMOptionButton ogrComp_opt3;

		internal MMGroupBox MMGroupBoxCEquidistant;

		internal MMLabel MMLabelEquSPoint;

		internal MMVariableEdit txtEquStartPoint;

		internal MMComboEdit StartPointUnit;

		internal MMLabel MMLabelCEquEPoint;

		internal MMVariableEdit txtEquEndPoint;

		internal MMComboEdit EndPointUnit;

		internal MMOptionGroup MMOptionGroupComp;

		internal MMOptionButton MMOptionGroup_CPoint;

		internal MMSpinBox MMSpinBoxEquNPoint;

		internal MMOptionButton MMOptionGroup_CIncr;

		internal MMVariableEdit txtIncr;

		internal MMComboEdit IncrUnit;

		internal MMGroupBox MMGroupBox3;

		internal MMLabel MMLabelLogSPoint;

		internal MMVariableEdit txtLogStartPoint;

		internal MMComboEdit LogStartPointUnit;

		internal MMLabel MMLabelLogEPoint;

		internal MMVariableEdit txtLogEndPoint;

		internal MMLabel MMLabelLogNPoint;

		internal MMComboEdit LogEndPointUnit;

		internal MMSpinBox MMSpinBoxLogNPoint;

		internal MMLabel MMLabelFactor;

		internal MMVariableEdit txFactor;

		internal MMLabel Mlist_label;

		internal MMComboEdit ListValueUnit;

		internal MMScrollArea grdList;

		internal MMLabel ParametricVar_label;

		internal MMGroupBox Parametric_Var;

		internal MMComboEdit cboVariable0_Comb;

		internal MMComboEdit cboVariable_Comp0;

		internal MMLabel Enterval_label;

		internal MMComboEdit PListValueUnit;

		internal MMScrollArea grdList1;

		internal MMGroupBox Enter_Var;

		internal MMLabel Fixedstate_label;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMComboEdit spcSpec2_combo;

		internal MMVariableEdit spcSpec2;

		internal MMCmdButton cmdRunAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Solubility_Solubility()
		{
			base.ViewModelType = typeof(MMAnalysis_Solubility_Solubility_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Solubility_Solubility_Loaded;
		}

		private void MMAnalysis_Solubility_Solubility_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/solubility/mmanalysis_solubility_solubility.xaml", UriKind.Relative);
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
				spec = (MMExpander)target;
				break;
			case 2:
				SoluteComp_label = (MMLabel)target;
				break;
			case 3:
				Proper_Rep = (MMGroupBox)target;
				break;
			case 4:
				MMListPicker = (MMListPickerForPropSet)target;
				break;
			case 5:
				SolventComp_label = (MMLabel)target;
				break;
			case 6:
				MMGroupBox_SolventComp = (MMGroupBox)target;
				break;
			case 7:
				lbtuBasis = (MMVariableEdit)target;
				break;
			case 8:
				grdSystem = (MMScrollArea)target;
				break;
			case 9:
				txtTotal = (MMValueEdit)target;
				break;
			case 10:
				phase = (MMExpander)target;
				break;
			case 11:
				cboValidPhases_label = (MMLabel)target;
				break;
			case 12:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 13:
				cboSoluPhases_label = (MMLabel)target;
				break;
			case 14:
				cboSoluPhases = (MMComboEdit)target;
				break;
			case 15:
				cboPropMethod_label = (MMLabel)target;
				break;
			case 16:
				cboPropMethod = (MMComboEdit)target;
				break;
			case 17:
				cboChemistry_label = (MMLabel)target;
				break;
			case 18:
				cboChemistry = (MMComboEdit)target;
				break;
			case 19:
				spec2 = (MMExpander)target;
				break;
			case 20:
				ManipulatedVar_label = (MMLabel)target;
				break;
			case 21:
				Manipulated_Var = (MMOptionGroup)target;
				break;
			case 22:
				cboVariable_AdvCollection1_Comb = (MMComboEdit)target;
				break;
			case 23:
				cboVariable_Comp1 = (MMComboEdit)target;
				break;
			case 24:
				ogrComp_opt1 = (MMOptionButton)target;
				break;
			case 25:
				ogrComp_opt2 = (MMOptionButton)target;
				break;
			case 26:
				ogrComp_opt3 = (MMOptionButton)target;
				break;
			case 27:
				MMGroupBoxCEquidistant = (MMGroupBox)target;
				break;
			case 28:
				MMLabelEquSPoint = (MMLabel)target;
				break;
			case 29:
				txtEquStartPoint = (MMVariableEdit)target;
				break;
			case 30:
				StartPointUnit = (MMComboEdit)target;
				break;
			case 31:
				MMLabelCEquEPoint = (MMLabel)target;
				break;
			case 32:
				txtEquEndPoint = (MMVariableEdit)target;
				break;
			case 33:
				EndPointUnit = (MMComboEdit)target;
				break;
			case 34:
				MMOptionGroupComp = (MMOptionGroup)target;
				break;
			case 35:
				MMOptionGroup_CPoint = (MMOptionButton)target;
				break;
			case 36:
				MMSpinBoxEquNPoint = (MMSpinBox)target;
				break;
			case 37:
				MMOptionGroup_CIncr = (MMOptionButton)target;
				break;
			case 38:
				txtIncr = (MMVariableEdit)target;
				break;
			case 39:
				IncrUnit = (MMComboEdit)target;
				break;
			case 40:
				MMGroupBox3 = (MMGroupBox)target;
				break;
			case 41:
				MMLabelLogSPoint = (MMLabel)target;
				break;
			case 42:
				txtLogStartPoint = (MMVariableEdit)target;
				break;
			case 43:
				LogStartPointUnit = (MMComboEdit)target;
				break;
			case 44:
				MMLabelLogEPoint = (MMLabel)target;
				break;
			case 45:
				txtLogEndPoint = (MMVariableEdit)target;
				break;
			case 46:
				MMLabelLogNPoint = (MMLabel)target;
				break;
			case 47:
				LogEndPointUnit = (MMComboEdit)target;
				break;
			case 48:
				MMSpinBoxLogNPoint = (MMSpinBox)target;
				break;
			case 49:
				MMLabelFactor = (MMLabel)target;
				break;
			case 50:
				txFactor = (MMVariableEdit)target;
				break;
			case 51:
				Mlist_label = (MMLabel)target;
				break;
			case 52:
				ListValueUnit = (MMComboEdit)target;
				break;
			case 53:
				grdList = (MMScrollArea)target;
				break;
			case 54:
				ParametricVar_label = (MMLabel)target;
				break;
			case 55:
				Parametric_Var = (MMGroupBox)target;
				break;
			case 56:
				cboVariable0_Comb = (MMComboEdit)target;
				break;
			case 57:
				cboVariable_Comp0 = (MMComboEdit)target;
				break;
			case 58:
				Enterval_label = (MMLabel)target;
				break;
			case 59:
				PListValueUnit = (MMComboEdit)target;
				break;
			case 60:
				grdList1 = (MMScrollArea)target;
				break;
			case 61:
				Enter_Var = (MMGroupBox)target;
				break;
			case 62:
				Fixedstate_label = (MMLabel)target;
				break;
			case 63:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 64:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 65:
				spcSpec2_combo = (MMComboEdit)target;
				break;
			case 66:
				spcSpec2 = (MMVariableEdit)target;
				break;
			case 67:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	public class MMAnalysis_Solubility_Tabulate_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdTableSpecifications_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMAnalysis_Solubility_Tabulate_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.PROPERTIES"
		});

		public static readonly CxvPropertyDeclaration cmdTableSpecifications_Command_var1_Property = CxvPropertyDeclaration.Register("cmdTableSpecifications_Command_var1", typeof(MMAnalysis_Solubility_Tabulate_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Specifications for tables in report",
			ToolTipTextResourceKey = "MMAnalysis_Pure_In_Prop_ViewModel__CxvCmdButtonProperty_ToolTipText_TableSpec"
		});

		public ICommand cmdTableSpecifications_Command
		{
			get
			{
				if (_cmdTableSpecifications_Command == null)
				{
					_cmdTableSpecifications_Command = new CxvDelegateCommand<object>(cmdTableSpecifications_CommandExecute);
				}
				return _cmdTableSpecifications_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		public object cmdTableSpecifications_Command_var1 => GetValue(cmdTableSpecifications_Command_var1_Property);

		private void cmdTableSpecifications_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMAnalysis_Pure.MMAnalysis_Pure_InTabDB",
				LegacyFlags = 0,
				HelpId = 784,
				HelpFile = "PROPS.HLP",
				ShowPrompts = true,
				ShortName = AspenTech.AspenPlus.Localization.Properties.Resources.ShortName_Specifications_For_Tables_In_Report
			};
			DisplayForm(args);
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Solubility
{
	[ProgId("MMAnalysis_Solubility.MMAnalysis_Solubility_Tabulate")]
	public class MMAnalysis_Solubility_Tabulate : MMTabPage, IComponentConnector
	{
		internal MMListPickerForPropSet MMListPicker1;

		internal MMCmdButton cmdTableSpecifications;

		private bool _contentLoaded;

		public MMAnalysis_Solubility_Tabulate()
		{
			base.ViewModelType = typeof(MMAnalysis_Solubility_Tabulate_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/solubility/mmanalysis_solubility_tabulate.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPickerForPropSet)target;
				break;
			case 2:
				cmdTableSpecifications = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_ProfileRes_DB")]
	public class MMAnalysis_ProfileRes_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollAreaMS grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_ProfileRes_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_ProfileRes_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_profileres_db.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
				break;
			case 3:
				cmdPlotwiz = (MMCmdButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_ResidueCur_DB")]
	public class MMAnalysis_ResidueCur_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMOptionGroup optNumberOfCurves;

		internal MMOptionButton optNumberOfCurves_opt0;

		internal MMOptionButton optNumberOfCurves_opt1;

		internal MMOptionButton optNumberOfCurves_opt2;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMComboEdit cboChemistryGibbs;

		internal MMCmdButton cmdSaveAsForm;

		internal MMCmdButton cmdGo;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_ResidueCur_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_ResidueCur_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_residuecur_db.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				FraPressure = (MMGroupBox)target;
				break;
			case 9:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 10:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 11:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 12:
				optNumberOfCurves = (MMOptionGroup)target;
				break;
			case 13:
				optNumberOfCurves_opt0 = (MMOptionButton)target;
				break;
			case 14:
				optNumberOfCurves_opt1 = (MMOptionButton)target;
				break;
			case 15:
				optNumberOfCurves_opt2 = (MMOptionButton)target;
				break;
			case 16:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 17:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 18:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 19:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 20:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 21:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 22:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 23:
				cmdSaveAsForm = (MMCmdButton)target;
				break;
			case 24:
				cmdGo = (MMCmdButton)target;
				break;
			case 25:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	public class MMAnalysis_Res_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration resd_Property = CxvPropertyDeclaration.Register("resd", typeof(MMAnalysis_Res_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.RESD"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_Res_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Res_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.RESD"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Res_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@resd" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Res_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Res_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Res_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object resd => GetValue(resd_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_In")]
	public class MMAnalysis_Res_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Res_In()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			case 6:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	public class MMAnalysis_Res_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuTolerance_tolerance_Property = CxvPropertyDeclaration.Register("lbtuTolerance_tolerance", typeof(MMAnalysis_Res_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL"
		});

		public static readonly CxvPropertyDeclaration spnMaximumIterations_maxit_Property = CxvPropertyDeclaration.Register("spnMaximumIterations_maxit", typeof(MMAnalysis_Res_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_Res_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_Res_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Res_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object lbtuTolerance_tolerance => GetValue(lbtuTolerance_tolerance_Property);

		public object spnMaximumIterations_maxit => GetValue(spnMaximumIterations_maxit_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Res_In_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Res_In_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_In_Diag")]
	public class MMAnalysis_Res_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		internal MMGroupBox fraEnterFlashCalculationConvergenceParameters;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		private bool _contentLoaded;

		public MMAnalysis_Res_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			case 14:
				fraEnterFlashCalculationConvergenceParameters = (MMGroupBox)target;
				break;
			case 15:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 16:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 17:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 18:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_In_Resi")]
	public class MMAnalysis_Res_In_Resi : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMOptionGroup optNumberOfCurves;

		internal MMOptionButton optNumberOfCurves_opt0;

		internal MMOptionButton optNumberOfCurves_opt1;

		internal MMOptionButton optNumberOfCurves_opt2;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMComboEdit cboChemistryGibbs;

		internal MMCmdButton cmdRunAnalysis;

		internal MMCmdButton cmdSaveAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Res_In_Resi()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_In_Resi_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Res_In_Resi_Loaded;
		}

		private void MMAnalysis_Res_In_Resi_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_in_resi.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				FraPressure = (MMGroupBox)target;
				break;
			case 9:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 10:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 11:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 12:
				optNumberOfCurves = (MMOptionGroup)target;
				break;
			case 13:
				optNumberOfCurves_opt0 = (MMOptionButton)target;
				break;
			case 14:
				optNumberOfCurves_opt1 = (MMOptionButton)target;
				break;
			case 15:
				optNumberOfCurves_opt2 = (MMOptionButton)target;
				break;
			case 16:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 17:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 18:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 19:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 20:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 21:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 22:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 23:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			case 24:
				cmdSaveAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_In_Syst")]
	public class MMAnalysis_Res_In_Syst : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraComponents;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboComponent3_label;

		internal MMComboEdit cboComponent3;

		internal MMOptionGroup optNumberOfCurves;

		internal MMOptionButton optNumberOfCurves_opt0;

		internal MMOptionButton optNumberOfCurves_opt1;

		internal MMOptionButton optNumberOfCurves_opt2;

		internal MMGroupBox FraPressure;

		internal MMVariableEdit lbtuPressure;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		private bool _contentLoaded;

		public MMAnalysis_Res_In_Syst()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_In_Syst_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_in_syst.xaml", UriKind.Relative);
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
				fraComponents = (MMGroupBox)target;
				break;
			case 2:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 3:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 4:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComponent3_label = (MMLabel)target;
				break;
			case 7:
				cboComponent3 = (MMComboEdit)target;
				break;
			case 8:
				optNumberOfCurves = (MMOptionGroup)target;
				break;
			case 9:
				optNumberOfCurves_opt0 = (MMOptionButton)target;
				break;
			case 10:
				optNumberOfCurves_opt1 = (MMOptionButton)target;
				break;
			case 11:
				optNumberOfCurves_opt2 = (MMOptionButton)target;
				break;
			case 12:
				FraPressure = (MMGroupBox)target;
				break;
			case 13:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 14:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 15:
				cboValidPhases = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	public class MMAnalysis_Res_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Res_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.RESD"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Res_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_Out")]
	public class MMAnalysis_Res_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinaryResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Res_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_out.xaml", UriKind.Relative);
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
				tabAnalysisBinaryResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.ResidueCurve
{
	[ProgId("MMAnalysis_Res.MMAnalysis_Res_Out_Resu")]
	public class MMAnalysis_Res_Out_Resu : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResults;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Res_Out_Resu()
		{
			base.ViewModelType = typeof(MMAnalysis_Res_Out_Resu_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/residuecurve/mmanalysis_res_out_resu.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_PAnalysis_DB")]
	public class MMAnalysis_PAnalysis_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraProperty;

		internal MMLabel cboProperty_label;

		internal MMComboEdit cboProperty;

		internal MMLabel cboPureCompProperties_label;

		internal MMComboEdit cboPureCompProperties;

		internal MMLabel cboPropUnits_label;

		internal MMComboEdit cboPropUnits;

		internal MMLabel lblPhase;

		internal MMCheckBox chkVapor;

		internal MMCheckBox chkLiquid;

		internal MMCheckBox chkSolid;

		internal MMOptionGroup ogrTemp;

		internal MMLabel cboTUnit_0_label;

		internal MMComboEdit cboTUnit_0;

		internal MMOptionButton ogrTemp_opt0;

		internal MMHorizontalListEdit grdList;

		internal MMOptionButton ogrTemp_opt1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMListPicker lstComps;

		internal MMGroupBox fraPressure;

		internal MMValueEdit txtPList;

		internal MMComboEdit cboPUnit;

		internal MMLabel cboPropertyMethod_label;

		internal MMComboEdit cboPropertyMethod;

		internal MMCmdButton cmdSaveAsForm;

		internal MMCmdButton cmdGo;

		internal MMCmdButton cmdCancel;

		private bool _contentLoaded;

		public MMAnalysis_PAnalysis_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_PAnalysis_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_panalysis_db.xaml", UriKind.Relative);
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
				fraProperty = (MMGroupBox)target;
				break;
			case 2:
				cboProperty_label = (MMLabel)target;
				break;
			case 3:
				cboProperty = (MMComboEdit)target;
				break;
			case 4:
				cboPureCompProperties_label = (MMLabel)target;
				break;
			case 5:
				cboPureCompProperties = (MMComboEdit)target;
				break;
			case 6:
				cboPropUnits_label = (MMLabel)target;
				break;
			case 7:
				cboPropUnits = (MMComboEdit)target;
				break;
			case 8:
				lblPhase = (MMLabel)target;
				break;
			case 9:
				chkVapor = (MMCheckBox)target;
				break;
			case 10:
				chkLiquid = (MMCheckBox)target;
				break;
			case 11:
				chkSolid = (MMCheckBox)target;
				break;
			case 12:
				ogrTemp = (MMOptionGroup)target;
				break;
			case 13:
				cboTUnit_0_label = (MMLabel)target;
				break;
			case 14:
				cboTUnit_0 = (MMComboEdit)target;
				break;
			case 15:
				ogrTemp_opt0 = (MMOptionButton)target;
				break;
			case 16:
				grdList = (MMHorizontalListEdit)target;
				break;
			case 17:
				ogrTemp_opt1 = (MMOptionButton)target;
				break;
			case 18:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 19:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 20:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 21:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 22:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 23:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 24:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 25:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 26:
				lstComps = (MMListPicker)target;
				break;
			case 27:
				fraPressure = (MMGroupBox)target;
				break;
			case 28:
				txtPList = (MMValueEdit)target;
				break;
			case 29:
				cboPUnit = (MMComboEdit)target;
				break;
			case 30:
				cboPropertyMethod_label = (MMLabel)target;
				break;
			case 31:
				cboPropertyMethod = (MMComboEdit)target;
				break;
			case 32:
				cmdSaveAsForm = (MMCmdButton)target;
				break;
			case 33:
				cmdGo = (MMCmdButton)target;
				break;
			case 34:
				cmdCancel = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_PResults_DB")]
	public class MMAnalysis_PResults_DB : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaMS grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_PResults_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_PResults_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_presults_db.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
				break;
			case 2:
				cmdPlotwiz = (MMCmdButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_PTEn_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_PTEn_In_Diag")]
	public class MMAnalysis_PTEn_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pten_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_Pure_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration tpoints_Property = CxvPropertyDeclaration.Register("tpoints", typeof(MMAnalysis_Pure_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "tpoints"
		});

		public static readonly CxvPropertyDeclaration points_Property = CxvPropertyDeclaration.Register("points", typeof(MMAnalysis_Pure_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "points"
		});

		public static readonly CxvPropertyDeclaration comp_Property = CxvPropertyDeclaration.Register("comp", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.COMP"
		});

		public static readonly CxvPropertyDeclaration temppres_Property = CxvPropertyDeclaration.Register("temppres", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TEMPPRES"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration main1_Property = CxvPropertyDeclaration.Register("main1", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN1"
		});

		public static readonly CxvPropertyDeclaration bkop_Property = CxvPropertyDeclaration.Register("bkop", typeof(MMAnalysis_Pure_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Pure_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@main1", "@bkop" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Pure_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Pure_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Pure_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object tpoints => GetValue(tpoints_Property);

		public object points => GetValue(points_Property);

		public object comp => GetValue(comp_Property);

		public object temppres => GetValue(temppres_Property);

		public object accres => GetValue(accres_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object main1 => GetValue(main1_Property);

		public object bkop => GetValue(bkop_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_In")]
	public class MMAnalysis_Pure_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPurecomp;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Pure_In()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_in.xaml", UriKind.Relative);
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
				tabPurecomp = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			case 6:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_Pure_InTabDB_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMSpinBox1_lines_Property = CxvPropertyDeclaration.Register("MMSpinBox1_lines", typeof(MMAnalysis_Pure_InTabDB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LINES"
		});

		public static readonly CxvPropertyDeclaration lbtuHeading_var1_Property = CxvPropertyDeclaration.Register("lbtuHeading_var1", typeof(MMAnalysis_Pure_InTabDB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.HEADING",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration ogrNumFor_MultiMap_Property = CxvPropertyDeclaration.Register("ogrNumFor_MultiMap", typeof(MMAnalysis_Pure_InTabDB_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrNumFor_display",
					DataPath = "@main.Input.HIGH_PREC"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "5 significant figures",
					DisplayResourceKey = "MMAnalysis_Pure_InTabDB_ViewModel__CxvMultiMapOption_Display_5_significant_figures",
					Value = "ogrNumFor_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrNumFor_display",
							Value = "STD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "7 significant figures",
					DisplayResourceKey = "MMAnalysis_Pure_InTabDB_ViewModel__CxvMultiMapOption_Display_7_significant_figures",
					Value = "ogrNumFor_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrNumFor_display",
							Value = "HIGH"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration ogrTableWidth_MultiMap_Property = CxvPropertyDeclaration.Register("ogrTableWidth_MultiMap", typeof(MMAnalysis_Pure_InTabDB_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrTableWidth_display",
					DataPath = "@main.Input.WIDE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "80 characters",
					DisplayResourceKey = "MMAnalysis_Pure_InTabDB_ViewModel__CxvMultiMapOption_Display_80_columns",
					Value = "ogrTableWidth_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrTableWidth_display",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "132 characters",
					DisplayResourceKey = "MMAnalysis_Pure_InTabDB_ViewModel__CxvMultiMapOption_Display_132_columns",
					Value = "ogrTableWidth_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrTableWidth_display",
							Value = "YES"
						}
					}
				}
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

		public object MMSpinBox1_lines => GetValue(MMSpinBox1_lines_Property);

		public object lbtuHeading_var1 => GetValue(lbtuHeading_var1_Property);

		public object ogrNumFor_MultiMap => GetValue(ogrNumFor_MultiMap_Property);

		public object ogrTableWidth_MultiMap => GetValue(ogrTableWidth_MultiMap_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_InTabDB")]
	public class MMAnalysis_Pure_InTabDB : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuHeading_label;

		internal MMVariableEdit lbtuHeading;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMOptionGroup ogrNumFor;

		internal MMOptionButton ogrNumFor_opt0;

		internal MMOptionButton ogrNumFor_opt1;

		internal MMOptionGroup ogrTableWidth;

		internal MMOptionButton ogrTableWidth_opt0;

		internal MMOptionButton ogrTableWidth_opt1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Pure_InTabDB()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_InTabDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_intabdb.xaml", UriKind.Relative);
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
				lbtuHeading_label = (MMLabel)target;
				break;
			case 2:
				lbtuHeading = (MMVariableEdit)target;
				break;
			case 3:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 4:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 5:
				ogrNumFor = (MMOptionGroup)target;
				break;
			case 6:
				ogrNumFor_opt0 = (MMOptionButton)target;
				break;
			case 7:
				ogrNumFor_opt1 = (MMOptionButton)target;
				break;
			case 8:
				ogrTableWidth = (MMOptionGroup)target;
				break;
			case 9:
				ogrTableWidth_opt0 = (MMOptionButton)target;
				break;
			case 10:
				ogrTableWidth_opt1 = (MMOptionButton)target;
				break;
			case 11:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_Pure_In_Comp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lstComps_var1_Property = CxvPropertyDeclaration.Register("lstComps_var1", typeof(MMAnalysis_Pure_In_Comp_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.COMPS",
			AllowSort = false
		});

		public object lstComps_var1 => GetValue(lstComps_var1_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_In_Comp")]
	public class MMAnalysis_Pure_In_Comp : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstComps;

		private bool _contentLoaded;

		public MMAnalysis_Pure_In_Comp()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_In_Comp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_in_comp.xaml", UriKind.Relative);
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
				lstComps = (MMListPicker)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_Pure_In_Prop_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdTableSpecifications_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMAnalysis_Pure_In_Prop_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.PROPERTIES"
		});

		public static readonly CxvPropertyDeclaration cmdTableSpecifications_Command_var1_Property = CxvPropertyDeclaration.Register("cmdTableSpecifications_Command_var1", typeof(MMAnalysis_Pure_In_Prop_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Specifications for tables in report",
			ToolTipTextResourceKey = "MMAnalysis_Pure_In_Prop_ViewModel__CxvCmdButtonProperty_ToolTipText_TableSpec"
		});

		public ICommand cmdTableSpecifications_Command
		{
			get
			{
				if (_cmdTableSpecifications_Command == null)
				{
					_cmdTableSpecifications_Command = new CxvDelegateCommand<object>(cmdTableSpecifications_CommandExecute);
				}
				return _cmdTableSpecifications_Command;
			}
		}

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		public object cmdTableSpecifications_Command_var1 => GetValue(cmdTableSpecifications_Command_var1_Property);

		private void cmdTableSpecifications_CommandExecute(object parameter)
		{
			DisplayFormEventArgs args = new DisplayFormEventArgs
			{
				FormProgId = "MMAnalysis_Pure.MMAnalysis_Pure_InTabDB",
				LegacyFlags = 0,
				HelpId = 784,
				HelpFile = "PROPS.HLP",
				ShowPrompts = true,
				ShortName = AspenTech.AspenPlus.Localization.Properties.Resources.ShortName_Specifications_For_Tables_In_Report
			};
			DisplayForm(args);
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_In_Prop")]
	public class MMAnalysis_Pure_In_Prop : MMTabPage, IComponentConnector
	{
		internal MMListPickerForPropSet MMListPicker1;

		internal MMCmdButton cmdTableSpecifications;

		private bool _contentLoaded;

		public MMAnalysis_Pure_In_Prop()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_In_Prop_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_in_prop.xaml", UriKind.Relative);
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
				MMListPicker1 = (MMListPickerForPropSet)target;
				break;
			case 2:
				cmdTableSpecifications = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_In_Pure")]
	public class MMAnalysis_Pure_In_Pure : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraProperty;

		internal MMLabel cboProperty_label;

		internal MMComboEdit cboProperty;

		internal MMLabel cboPureCompProperties_label;

		internal MMComboEdit cboPureCompProperties;

		internal MMLabel cboPropUnits_label;

		internal MMComboEdit cboPropUnits;

		internal MMLabel lblPhase;

		internal MMCheckBox chkVapor;

		internal MMCheckBox chkLiquid;

		internal MMCheckBox chkSolid;

		internal MMListPicker lstComps;

		internal MMGroupBox fraPropertyOptions;

		internal MMLabel cboPropMethod_label;

		internal MMComboEdit cboPropertyMethod;

		internal MMLabel cboHenryComp_label;

		internal MMComboEdit cbocboHenryComp;

		internal MMLabel cboChemistry_label;

		internal MMComboEdit cboChemistry;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		internal MMOptionGroup ogrTemp;

		internal MMLabel cboTUnit_0_label;

		internal MMComboEdit cboTUnit_0;

		internal MMOptionButton ogrTemp_opt1;

		internal MMOptionButton ogrTemp_opt2;

		internal MMOptionButton ogrTemp_opt3;

		internal MMGroupBox MMGroupBox2;

		internal MMLabel MMLabelEquSPoint;

		internal MMVariableEdit txtEquStartPoint;

		internal MMLabel MMLabelEquEPoint;

		internal MMVariableEdit txtEquEndPoint;

		internal MMOptionGroup MMOptionGroup2;

		internal MMOptionButton MMOptionGroup4;

		internal MMSpinBox MMSpinBoxEquNPoint;

		internal MMOptionButton MMOptionGroup5;

		internal MMVariableEdit txtIncr;

		internal MMGroupBox MMGroupBox3;

		internal MMLabel MMLabelLogSPoint;

		internal MMVariableEdit txtLogStartPoint;

		internal MMLabel MMLabelLogEPoint;

		internal MMVariableEdit txtLogEndPoint;

		internal MMLabel MMLabelLogNPoint;

		internal MMSpinBox MMSpinBoxLogNPoint;

		internal MMLabel MMLabelFactor;

		internal MMVariableEdit txFactor;

		internal MMLabel list_label;

		internal MMScrollArea grdList;

		internal MMGroupBox fraPressure;

		internal MMValueEdit txtPList;

		internal MMComboEdit cboPUnit;

		internal MMCmdButton cmdRunAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Pure_In_Pure()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_In_Pure_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Pure_In_Pure_Loaded;
		}

		private void MMAnalysis_Pure_In_Pure_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_in_pure.xaml", UriKind.Relative);
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
				fraProperty = (MMGroupBox)target;
				break;
			case 2:
				cboProperty_label = (MMLabel)target;
				break;
			case 3:
				cboProperty = (MMComboEdit)target;
				break;
			case 4:
				cboPureCompProperties_label = (MMLabel)target;
				break;
			case 5:
				cboPureCompProperties = (MMComboEdit)target;
				break;
			case 6:
				cboPropUnits_label = (MMLabel)target;
				break;
			case 7:
				cboPropUnits = (MMComboEdit)target;
				break;
			case 8:
				lblPhase = (MMLabel)target;
				break;
			case 9:
				chkVapor = (MMCheckBox)target;
				break;
			case 10:
				chkLiquid = (MMCheckBox)target;
				break;
			case 11:
				chkSolid = (MMCheckBox)target;
				break;
			case 12:
				lstComps = (MMListPicker)target;
				break;
			case 13:
				fraPropertyOptions = (MMGroupBox)target;
				break;
			case 14:
				cboPropMethod_label = (MMLabel)target;
				break;
			case 15:
				cboPropertyMethod = (MMComboEdit)target;
				break;
			case 16:
				cboHenryComp_label = (MMLabel)target;
				break;
			case 17:
				cbocboHenryComp = (MMComboEdit)target;
				break;
			case 18:
				cboChemistry_label = (MMLabel)target;
				break;
			case 19:
				cboChemistry = (MMComboEdit)target;
				break;
			case 20:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 21:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			case 22:
				ogrTemp = (MMOptionGroup)target;
				break;
			case 23:
				cboTUnit_0_label = (MMLabel)target;
				break;
			case 24:
				cboTUnit_0 = (MMComboEdit)target;
				break;
			case 25:
				ogrTemp_opt1 = (MMOptionButton)target;
				break;
			case 26:
				ogrTemp_opt2 = (MMOptionButton)target;
				break;
			case 27:
				ogrTemp_opt3 = (MMOptionButton)target;
				break;
			case 28:
				MMGroupBox2 = (MMGroupBox)target;
				break;
			case 29:
				MMLabelEquSPoint = (MMLabel)target;
				break;
			case 30:
				txtEquStartPoint = (MMVariableEdit)target;
				break;
			case 31:
				MMLabelEquEPoint = (MMLabel)target;
				break;
			case 32:
				txtEquEndPoint = (MMVariableEdit)target;
				break;
			case 33:
				MMOptionGroup2 = (MMOptionGroup)target;
				break;
			case 34:
				MMOptionGroup4 = (MMOptionButton)target;
				break;
			case 35:
				MMSpinBoxEquNPoint = (MMSpinBox)target;
				break;
			case 36:
				MMOptionGroup5 = (MMOptionButton)target;
				break;
			case 37:
				txtIncr = (MMVariableEdit)target;
				break;
			case 38:
				MMGroupBox3 = (MMGroupBox)target;
				break;
			case 39:
				MMLabelLogSPoint = (MMLabel)target;
				break;
			case 40:
				txtLogStartPoint = (MMVariableEdit)target;
				break;
			case 41:
				MMLabelLogEPoint = (MMLabel)target;
				break;
			case 42:
				txtLogEndPoint = (MMVariableEdit)target;
				break;
			case 43:
				MMLabelLogNPoint = (MMLabel)target;
				break;
			case 44:
				MMSpinBoxLogNPoint = (MMSpinBox)target;
				break;
			case 45:
				MMLabelFactor = (MMLabel)target;
				break;
			case 46:
				txFactor = (MMVariableEdit)target;
				break;
			case 47:
				list_label = (MMLabel)target;
				break;
			case 48:
				grdList = (MMScrollArea)target;
				break;
			case 49:
				fraPressure = (MMGroupBox)target;
				break;
			case 50:
				txtPList = (MMValueEdit)target;
				break;
			case 51:
				cboPUnit = (MMComboEdit)target;
				break;
			case 52:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_In_Vari")]
	public class MMAnalysis_Pure_In_Vari : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrTemp;

		internal MMLabel cboTUnit_0_label;

		internal MMComboEdit cboTUnit_0;

		internal MMOptionButton ogrTemp_opt0;

		internal MMHorizontalListEdit grdList;

		internal MMOptionButton ogrTemp_opt1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMOptionGroup MMOptionGroup1;

		internal MMLabel cboTUnit_1_label;

		internal MMComboEdit cboTUnit_1;

		internal MMOptionButton MMOptionGroup1_opt0;

		internal MMHorizontalListEdit MMScrollArea1;

		internal MMOptionButton MMOptionGroup1_opt1;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMSpinBox2_label;

		internal MMSpinBox MMSpinBox2;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		private bool _contentLoaded;

		public MMAnalysis_Pure_In_Vari()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_In_Vari_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_in_vari.xaml", UriKind.Relative);
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
				ogrTemp = (MMOptionGroup)target;
				break;
			case 2:
				cboTUnit_0_label = (MMLabel)target;
				break;
			case 3:
				cboTUnit_0 = (MMComboEdit)target;
				break;
			case 4:
				ogrTemp_opt0 = (MMOptionButton)target;
				break;
			case 5:
				grdList = (MMHorizontalListEdit)target;
				break;
			case 6:
				ogrTemp_opt1 = (MMOptionButton)target;
				break;
			case 7:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 8:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 9:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 11:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 12:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 13:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 14:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 15:
				MMOptionGroup1 = (MMOptionGroup)target;
				break;
			case 16:
				cboTUnit_1_label = (MMLabel)target;
				break;
			case 17:
				cboTUnit_1 = (MMComboEdit)target;
				break;
			case 18:
				MMOptionGroup1_opt0 = (MMOptionButton)target;
				break;
			case 19:
				MMScrollArea1 = (MMHorizontalListEdit)target;
				break;
			case 20:
				MMOptionGroup1_opt1 = (MMOptionButton)target;
				break;
			case 21:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 22:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 23:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 24:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 25:
				MMSpinBox2_label = (MMLabel)target;
				break;
			case 26:
				MMSpinBox2 = (MMSpinBox)target;
				break;
			case 27:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 28:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class MMAnalysis_Pure_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Pure_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Pure_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_Out")]
	public class MMAnalysis_Pure_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPureResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Pure_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_out.xaml", UriKind.Relative);
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
				tabPureResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class PureAnalysisResultUpdatedEventArgs : EventArgs
	{
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	public class PureAnalysisResultUpdatedEvent : RoutedCompositePresentationEvent<PureAnalysisResultUpdatedEventArgs>
	{
		public PureAnalysisResultUpdatedEvent()
		{
			base.RoutingStrategy = CompositeEventRoutingStrategy.AllTopDown;
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PureComponents
{
	[ProgId("MMAnalysis_Pure.MMAnalysis_Pure_Out_Res")]
	public class MMAnalysis_Pure_Out_Res : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPureComponentProperties;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Pure_Out_Res()
		{
			base.ViewModelType = typeof(MMAnalysis_Pure_Out_Res_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/purecomponents/mmanalysis_pure_out_res.xaml", UriKind.Relative);
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
				fraPureComponentProperties = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	public class MMAnalysis_PTEnAdvan_DB_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMLBUText2_redt_Property = CxvPropertyDeclaration.Register("MMLBUText2_redt", typeof(MMAnalysis_PTEnAdvan_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REDT"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_tinit_Property = CxvPropertyDeclaration.Register("MMLBUText1_tinit", typeof(MMAnalysis_PTEnAdvan_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TINIT"
		});

		public static readonly CxvPropertyDeclaration lbtuPressure_pinit_Property = CxvPropertyDeclaration.Register("lbtuPressure_pinit", typeof(MMAnalysis_PTEnAdvan_DB_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PINIT"
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

		public object MMLBUText2_redt => GetValue(MMLBUText2_redt_Property);

		public object MMLBUText1_tinit => GetValue(MMLBUText1_tinit_Property);

		public object lbtuPressure_pinit => GetValue(lbtuPressure_pinit_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEnAdvan_DB")]
	public class MMAnalysis_PTEnAdvan_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraOptionalInitialPoint;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraOptionalTerminationPoint;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_PTEnAdvan_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEnAdvan_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_ptenadvan_db.xaml", UriKind.Relative);
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
				fraOptionalInitialPoint = (MMGroupBox)target;
				break;
			case 2:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 3:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 4:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 5:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 6:
				fraOptionalTerminationPoint = (MMGroupBox)target;
				break;
			case 7:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 8:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 9:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEnResul_DB")]
	public class MMAnalysis_PTEnResul_DB : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollAreaMS grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_PTEnResul_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEnResul_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_ptenresul_db.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
				break;
			case 3:
				cmdPlotwiz = (MMCmdButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEnvelop_DB")]
	public class MMAnalysis_PTEnvelop_DB : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBox1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox fraVaporFractionBranches;

		internal MMScrollArea MMScrollArea1;

		internal MMCmdButton cmdSaveAsForm;

		internal MMCmdButton cmdGo;

		internal MMCmdButton cmdCancel;

		internal MMCmdButton cmdAdvanced;

		private bool _contentLoaded;

		public MMAnalysis_PTEnvelop_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEnvelop_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_ptenvelop_db.xaml", UriKind.Relative);
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
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 5:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 6:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 7:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 8:
				fraVaporFractionBranches = (MMGroupBox)target;
				break;
			case 9:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 10:
				cmdSaveAsForm = (MMCmdButton)target;
				break;
			case 11:
				cmdGo = (MMCmdButton)target;
				break;
			case 12:
				cmdCancel = (MMCmdButton)target;
				break;
			case 13:
				cmdAdvanced = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	public class MMAnalysis_PTEn_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration sys_Property = CxvPropertyDeclaration.Register("sys", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration enve_Property = CxvPropertyDeclaration.Register("enve", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENVE"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TABU"
		});

		public static readonly CxvPropertyDeclaration proper_Property = CxvPropertyDeclaration.Register("proper", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sys", "@enve" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@proper" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object choice => GetValue(choice_Property);

		public object sys => GetValue(sys_Property);

		public object enve => GetValue(enve_Property);

		public object tabu => GetValue(tabu_Property);

		public object proper => GetValue(proper_Property);

		public object entprop => GetValue(entprop_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_In")]
	public class MMAnalysis_PTEn_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
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
				tabInfo = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	public class MMAnalysis_PTEn_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_In_Diag")]
	public class MMAnalysis_PTEn_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_In_Enve")]
	public class MMAnalysis_PTEn_In_Enve : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraVaporFractionBranches;

		internal MMCheckBox chkDew_BubblePointCurves;

		internal MMLabel lblAdditionalVaporFractions;

		internal MMScrollArea MMScrollArea1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox fraOptionalInitialPoint;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraOptionalTerminationPoint;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Enve()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Enve_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_in_enve.xaml", UriKind.Relative);
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
				fraVaporFractionBranches = (MMGroupBox)target;
				break;
			case 2:
				chkDew_BubblePointCurves = (MMCheckBox)target;
				break;
			case 3:
				lblAdditionalVaporFractions = (MMLabel)target;
				break;
			case 4:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 5:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 6:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 7:
				fraOptionalInitialPoint = (MMGroupBox)target;
				break;
			case 8:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 9:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 10:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 11:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 12:
				fraOptionalTerminationPoint = (MMGroupBox)target;
				break;
			case 13:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 14:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_In_PTEn")]
	public class MMAnalysis_PTEn_In_PTEn : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup optComp;

		internal MMLabel MMLabel_System;

		internal MMOptionButton optComp_opt0;

		internal MMOptionButton optComp_opt1;

		internal MMLabel cboStreamID_label;

		internal MMComboEdit cboStreamID;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollArea grdSystem;

		internal MMLabel lblAdditionalVaporFractions;

		internal MMCheckBox chkDew_BubblePointCurves;

		internal MMScrollArea MMScrollArea1;

		internal MMLabel optionSpec_Label;

		internal MMLabel cboValidPhases_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboMethod_label;

		internal MMComboEdit cboMethod;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel Termination_Label;

		internal MMLabel MMLabel18;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLabel20;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		internal MMLabel MMLBUText7_label;

		internal MMVariableEdit MMLBUText7;

		internal MMCmdButton cmdRunAnalysis;

		internal MMCmdButton cmdSaveAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_PTEn()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_PTEn_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_PTEn_In_PTEn_Loaded;
		}

		private void MMAnalysis_PTEn_In_PTEn_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_in_pten.xaml", UriKind.Relative);
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
				optComp = (MMOptionGroup)target;
				break;
			case 2:
				MMLabel_System = (MMLabel)target;
				break;
			case 3:
				optComp_opt0 = (MMOptionButton)target;
				break;
			case 4:
				optComp_opt1 = (MMOptionButton)target;
				break;
			case 5:
				cboStreamID_label = (MMLabel)target;
				break;
			case 6:
				cboStreamID = (MMComboEdit)target;
				break;
			case 7:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 8:
				grdSystem = (MMScrollArea)target;
				break;
			case 9:
				lblAdditionalVaporFractions = (MMLabel)target;
				break;
			case 10:
				chkDew_BubblePointCurves = (MMCheckBox)target;
				break;
			case 11:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 12:
				optionSpec_Label = (MMLabel)target;
				break;
			case 13:
				cboValidPhases_label = (MMLabel)target;
				break;
			case 14:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 15:
				cboMethod_label = (MMLabel)target;
				break;
			case 16:
				cboMethod = (MMComboEdit)target;
				break;
			case 17:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 18:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 19:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 20:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 21:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 22:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 23:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 24:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 25:
				Termination_Label = (MMLabel)target;
				break;
			case 26:
				MMLabel18 = (MMLabel)target;
				break;
			case 27:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 28:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 29:
				MMLabel20 = (MMLabel)target;
				break;
			case 30:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 31:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 32:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 33:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 34:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 35:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			case 36:
				MMLBUText7_label = (MMLabel)target;
				break;
			case 37:
				MMLBUText7 = (MMVariableEdit)target;
				break;
			case 38:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			case 39:
				cmdSaveAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_In_Syst")]
	public class MMAnalysis_PTEn_In_Syst : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup optComp;

		internal MMOptionButton optComp_opt0;

		internal MMOptionButton optComp_opt1;

		internal MMGroupBox fraStreamID;

		internal MMLabel cboStreamID_label;

		internal MMComboEdit cboStreamID;

		internal MMGroupBox fraSystem;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollArea grdSystem;

		internal MMGroupBox Assumption;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel3;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Syst()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Syst_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_in_syst.xaml", UriKind.Relative);
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
				optComp = (MMOptionGroup)target;
				break;
			case 2:
				optComp_opt0 = (MMOptionButton)target;
				break;
			case 3:
				optComp_opt1 = (MMOptionButton)target;
				break;
			case 4:
				fraStreamID = (MMGroupBox)target;
				break;
			case 5:
				cboStreamID_label = (MMLabel)target;
				break;
			case 6:
				cboStreamID = (MMComboEdit)target;
				break;
			case 7:
				fraSystem = (MMGroupBox)target;
				break;
			case 8:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 9:
				grdSystem = (MMScrollArea)target;
				break;
			case 10:
				Assumption = (MMGroupBox)target;
				break;
			case 11:
				MMLabel2 = (MMLabel)target;
				break;
			case 12:
				MMLabel3 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	public class MMAnalysis_PTEn_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_PTEn_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_PTEn_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_Out")]
	public class MMAnalysis_PTEn_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_out.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.PTEnvelope
{
	[ProgId("MMAnalysis_PTEn.MMAnalysis_PTEn_Out_Res")]
	public class MMAnalysis_PTEn_Out_Res : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuTcrit_label;

		internal MMVariableEdit lbtuTcrit;

		internal MMLabel lbtuTcrit3_label;

		internal MMVariableEdit lbtuTcrit3;

		internal MMLabel lbtuPcrit_label;

		internal MMVariableEdit lbtuPcrit;

		internal MMLabel lbtuPcrit3_label;

		internal MMVariableEdit lbtuPcrit3;

		internal MMLabel lbtuTmax_label;

		internal MMVariableEdit lbtuTmax;

		internal MMLabel lbtuPatTmax_label;

		internal MMVariableEdit lbtuPatTmax;

		internal MMLabel lbtuPmax_label;

		internal MMVariableEdit lbtuPmax;

		internal MMLabel lbtuTatPmax_label;

		internal MMVariableEdit lbtuTatPmax;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_Out_Res()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_Out_Res_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/ptenvelope/mmanalysis_pten_out_res.xaml", UriKind.Relative);
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
				lbtuTcrit_label = (MMLabel)target;
				break;
			case 2:
				lbtuTcrit = (MMVariableEdit)target;
				break;
			case 3:
				lbtuTcrit3_label = (MMLabel)target;
				break;
			case 4:
				lbtuTcrit3 = (MMVariableEdit)target;
				break;
			case 5:
				lbtuPcrit_label = (MMLabel)target;
				break;
			case 6:
				lbtuPcrit = (MMVariableEdit)target;
				break;
			case 7:
				lbtuPcrit3_label = (MMLabel)target;
				break;
			case 8:
				lbtuPcrit3 = (MMVariableEdit)target;
				break;
			case 9:
				lbtuTmax_label = (MMLabel)target;
				break;
			case 10:
				lbtuTmax = (MMVariableEdit)target;
				break;
			case 11:
				lbtuPatTmax_label = (MMLabel)target;
				break;
			case 12:
				lbtuPatTmax = (MMVariableEdit)target;
				break;
			case 13:
				lbtuPmax_label = (MMLabel)target;
				break;
			case 14:
				lbtuPmax = (MMVariableEdit)target;
				break;
			case 15:
				lbtuTatPmax_label = (MMLabel)target;
				break;
			case 16:
				lbtuTatPmax = (MMVariableEdit)target;
				break;
			case 17:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Mixture
{
	public class MMAnalysis_Mix_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration STRM_Property = CxvPropertyDeclaration.Register("STRM", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration COMPVARY_Property = CxvPropertyDeclaration.Register("COMPVARY", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.COMPVARY"
		});

		public static readonly CxvPropertyDeclaration VRY4_Property = CxvPropertyDeclaration.Register("VRY4", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.VRY4"
		});

		public static readonly CxvPropertyDeclaration VRY5_Property = CxvPropertyDeclaration.Register("VRY5", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.VRY5"
		});

		public static readonly CxvPropertyDeclaration CALCOPT_Property = CxvPropertyDeclaration.Register("CALCOPT", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CALCOPT"
		});

		public static readonly CxvPropertyDeclaration entcalc_Property = CxvPropertyDeclaration.Register("entcalc", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration bkop_Property = CxvPropertyDeclaration.Register("bkop", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Mix_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@STRM", "@COMPVARY" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Mix_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@bkop", "@VRY4", "@VRY5", "@CALCOPT" },
			EnteredDataPaths = { "@entcalc" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Mix_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Mix_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Mix_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object STRM => GetValue(STRM_Property);

		public object COMPVARY => GetValue(COMPVARY_Property);

		public object VRY4 => GetValue(VRY4_Property);

		public object VRY5 => GetValue(VRY5_Property);

		public object CALCOPT => GetValue(CALCOPT_Property);

		public object entcalc => GetValue(entcalc_Property);

		public object bkop => GetValue(bkop_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Mixture
{
	[ProgId("MMAnalysis_Mix.MMAnalysis_Mix_In")]
	public class MMAnalysis_Mix_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Mix_In()
		{
			base.ViewModelType = typeof(MMAnalysis_Mix_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/mixture/mmanalysis_mix_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
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
			case 7:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Mixture
{
	[ProgId("MMAnalysis_Mix.MMAnalysis_Mix_In_Stream")]
	public class MMAnalysis_Mix_In_Stream : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMGroupBox_Stream1;

		internal MMLabel cboStreamID_label;

		internal MMComboEdit cboStreamID;

		internal MMGroupBox Proper_Rep_Stream;

		internal MMListPickerForPropSet MMListPickerStream;

		internal MMExpander spec1;

		internal MMGroupBox MMGroupBox_Comp;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollArea grdSystem;

		internal MMValueEdit totalTxt;

		internal MMGroupBox Proper_Rep;

		internal MMListPickerForPropSet MMListPicker1;

		internal MMExpander spec2;

		internal MMOptionGroup Manipulated_Var;

		internal MMComboEdit cboVariable_AdvCollection1_Comb;

		internal MMComboEdit cboVariable_Comp;

		internal MMComboEdit cboVariable_SubS;

		internal MMOptionButton ogrManipVar_opt1;

		internal MMOptionButton ogrManipVar_opt2;

		internal MMOptionButton ogrManipVar_opt3;

		internal MMGroupBox MMGroupBoxEquidistant;

		internal MMLabel MMLabelStartPoint;

		internal MMVariableEdit txtStartPoint;

		internal MMComboEdit StartPointUnit;

		internal MMLabel MMLabelEndPoint;

		internal MMVariableEdit txtEndPoint;

		internal MMComboEdit EndPointUnit;

		internal MMOptionGroup optTpointsIncr;

		internal MMOptionButton MMOptionGroup_Point;

		internal MMSpinBox MMSpinBoxNPoint;

		internal MMOptionButton MMOptionGroup_Incr;

		internal MMVariableEdit txtIncr;

		internal MMComboEdit IncrUnit;

		internal MMGroupBox MMGroupBox3;

		internal MMLabel MMLabelLogSPoint;

		internal MMVariableEdit txtLogStartPoint;

		internal MMLabel MMLabelLogEPoint;

		internal MMComboEdit StartPointLogUnit;

		internal MMVariableEdit txtLogEndPoint;

		internal MMComboEdit EndPointLogUnit;

		internal MMLabel MMLabelLogNPoint;

		internal MMSpinBox MMSpinBoxLogNPoint;

		internal MMLabel MMLabelFactor;

		internal MMVariableEdit txFactor;

		internal MMLabel Mlist_label;

		internal MMComboEdit ListValueUnit;

		internal MMScrollArea grdList;

		internal MMGroupBox Parametric_Var;

		internal MMComboEdit cboVariable_AdvCollection2_Comb;

		internal MMComboEdit cboVariable_Unit2_Comb;

		internal MMLabel Enterval_label;

		internal MMScrollArea grdList1;

		internal MMGroupBox Enter_Var;

		internal MMLabel Fixedstate_label;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMCmdButton cmdRunAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Mix_In_Stream()
		{
			base.ViewModelType = typeof(MMAnalysis_Mix_In_Stream_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Mix_In_Stream_Loaded;
		}

		private void MMAnalysis_Mix_In_Stream_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
			CxvViewModel viewModel = base.ViewModel;
			if (viewModel != null)
			{
				bool? flag = CxsConverter.ValueToBoolean(viewModel.ExpandDataPathAndGet("@main.CC Nodes.ISCOMP", "value"));
				if (flag.HasValue && !flag.Value)
				{
					spec1.Header = ApwnResources.MMAPr_Anal_Gen_In_System_MMExpander_1;
				}
				else
				{
					spec1.Header = ApwnResources.MMAPr_Anal_Gen_In_System_MMExpander_4;
				}
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/mixture/mmanalysis_mix_in_stream.xaml", UriKind.Relative);
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
				MMGroupBox_Stream1 = (MMGroupBox)target;
				break;
			case 2:
				cboStreamID_label = (MMLabel)target;
				break;
			case 3:
				cboStreamID = (MMComboEdit)target;
				break;
			case 4:
				Proper_Rep_Stream = (MMGroupBox)target;
				break;
			case 5:
				MMListPickerStream = (MMListPickerForPropSet)target;
				break;
			case 6:
				spec1 = (MMExpander)target;
				break;
			case 7:
				MMGroupBox_Comp = (MMGroupBox)target;
				break;
			case 8:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 9:
				grdSystem = (MMScrollArea)target;
				break;
			case 10:
				totalTxt = (MMValueEdit)target;
				break;
			case 11:
				Proper_Rep = (MMGroupBox)target;
				break;
			case 12:
				MMListPicker1 = (MMListPickerForPropSet)target;
				break;
			case 13:
				spec2 = (MMExpander)target;
				break;
			case 14:
				Manipulated_Var = (MMOptionGroup)target;
				break;
			case 15:
				cboVariable_AdvCollection1_Comb = (MMComboEdit)target;
				break;
			case 16:
				cboVariable_Comp = (MMComboEdit)target;
				break;
			case 17:
				cboVariable_SubS = (MMComboEdit)target;
				break;
			case 18:
				ogrManipVar_opt1 = (MMOptionButton)target;
				break;
			case 19:
				ogrManipVar_opt2 = (MMOptionButton)target;
				break;
			case 20:
				ogrManipVar_opt3 = (MMOptionButton)target;
				break;
			case 21:
				MMGroupBoxEquidistant = (MMGroupBox)target;
				break;
			case 22:
				MMLabelStartPoint = (MMLabel)target;
				break;
			case 23:
				txtStartPoint = (MMVariableEdit)target;
				break;
			case 24:
				StartPointUnit = (MMComboEdit)target;
				break;
			case 25:
				MMLabelEndPoint = (MMLabel)target;
				break;
			case 26:
				txtEndPoint = (MMVariableEdit)target;
				break;
			case 27:
				EndPointUnit = (MMComboEdit)target;
				break;
			case 28:
				optTpointsIncr = (MMOptionGroup)target;
				break;
			case 29:
				MMOptionGroup_Point = (MMOptionButton)target;
				break;
			case 30:
				MMSpinBoxNPoint = (MMSpinBox)target;
				break;
			case 31:
				MMOptionGroup_Incr = (MMOptionButton)target;
				break;
			case 32:
				txtIncr = (MMVariableEdit)target;
				break;
			case 33:
				IncrUnit = (MMComboEdit)target;
				break;
			case 34:
				MMGroupBox3 = (MMGroupBox)target;
				break;
			case 35:
				MMLabelLogSPoint = (MMLabel)target;
				break;
			case 36:
				txtLogStartPoint = (MMVariableEdit)target;
				break;
			case 37:
				MMLabelLogEPoint = (MMLabel)target;
				break;
			case 38:
				StartPointLogUnit = (MMComboEdit)target;
				break;
			case 39:
				txtLogEndPoint = (MMVariableEdit)target;
				break;
			case 40:
				EndPointLogUnit = (MMComboEdit)target;
				break;
			case 41:
				MMLabelLogNPoint = (MMLabel)target;
				break;
			case 42:
				MMSpinBoxLogNPoint = (MMSpinBox)target;
				break;
			case 43:
				MMLabelFactor = (MMLabel)target;
				break;
			case 44:
				txFactor = (MMVariableEdit)target;
				break;
			case 45:
				Mlist_label = (MMLabel)target;
				break;
			case 46:
				ListValueUnit = (MMComboEdit)target;
				break;
			case 47:
				grdList = (MMScrollArea)target;
				break;
			case 48:
				Parametric_Var = (MMGroupBox)target;
				break;
			case 49:
				cboVariable_AdvCollection2_Comb = (MMComboEdit)target;
				break;
			case 50:
				cboVariable_Unit2_Comb = (MMComboEdit)target;
				break;
			case 51:
				Enterval_label = (MMLabel)target;
				break;
			case 52:
				grdList1 = (MMScrollArea)target;
				break;
			case 53:
				Enter_Var = (MMGroupBox)target;
				break;
			case 54:
				Fixedstate_label = (MMLabel)target;
				break;
			case 55:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 56:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 57:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Mixture
{
	public class MMAnalysis_Mix_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Mix_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Mix_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Mixture
{
	[ProgId("MMAnalysis_Mix.MMAnalysis_Mix_Out")]
	public class MMAnalysis_Mix_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabGeneralResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Mix_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Mix_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/mixture/mmanalysis_mix_out.xaml", UriKind.Relative);
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
				tabGeneralResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_DBVari")]
	public class MMAnalysis_Gen_DBVari : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMOptionGroup OptionVarvalue;

		internal MMOptionButton OptionVarvalue_opt0;

		internal MMOptionButton OptionVarvalue_opt1;

		internal MMScrollAreaMS grdList;

		internal MMGroupBox MMFrame2;

		internal MMOptionGroup optTpointsIncr;

		internal MMOptionButton optTpointsIncr_opt0;

		internal MMSpinBox spnTNPOINT;

		internal MMOptionButton optTpointsIncr_opt1;

		internal MMValueEdit txtTIncr;

		internal MMLabel txtLower_label;

		internal MMVariableEdit txtLower;

		internal MMLabel txtUpper_label;

		internal MMVariableEdit txtUpper;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Gen_DBVari()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_DBVari_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_dbvari.xaml", UriKind.Relative);
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
				OptionVarvalue = (MMOptionGroup)target;
				break;
			case 3:
				OptionVarvalue_opt0 = (MMOptionButton)target;
				break;
			case 4:
				OptionVarvalue_opt1 = (MMOptionButton)target;
				break;
			case 5:
				grdList = (MMScrollAreaMS)target;
				break;
			case 6:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 7:
				optTpointsIncr = (MMOptionGroup)target;
				break;
			case 8:
				optTpointsIncr_opt0 = (MMOptionButton)target;
				break;
			case 9:
				spnTNPOINT = (MMSpinBox)target;
				break;
			case 10:
				optTpointsIncr_opt1 = (MMOptionButton)target;
				break;
			case 11:
				txtTIncr = (MMValueEdit)target;
				break;
			case 12:
				txtLower_label = (MMLabel)target;
				break;
			case 13:
				txtLower = (MMVariableEdit)target;
				break;
			case 14:
				txtUpper_label = (MMLabel)target;
				break;
			case 15:
				txtUpper = (MMVariableEdit)target;
				break;
			case 16:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	public class MMAnalysis_Gen_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAnalysis_Gen_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration sys_Property = CxvPropertyDeclaration.Register("sys", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration nphase_Property = CxvPropertyDeclaration.Register("nphase", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NPHASE"
		});

		public static readonly CxvPropertyDeclaration vary_Property = CxvPropertyDeclaration.Register("vary", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.COMPVARY"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TABU"
		});

		public static readonly CxvPropertyDeclaration proper_Property = CxvPropertyDeclaration.Register("proper", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAnalysis_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration row_Property = CxvPropertyDeclaration.Register("row", typeof(MMAnalysis_Gen_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "row"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sys", "@nphase" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@vary" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@proper", "@nphase" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Gen_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object choice => GetValue(choice_Property);

		public object sys => GetValue(sys_Property);

		public object nphase => GetValue(nphase_Property);

		public object vary => GetValue(vary_Property);

		public object tabu => GetValue(tabu_Property);

		public object proper => GetValue(proper_Property);

		public object accres => GetValue(accres_Property);

		public object entprop => GetValue(entprop_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object row => GetValue(row_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_In")]
	public class MMAnalysis_Gen_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab6;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
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
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tabInfo = (MMTabItem)target;
				break;
			case 9:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	public class MMAnalysis_Gen_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_In_Diag")]
	public class MMAnalysis_Gen_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_In_System")]
	public class MMAnalysis_Gen_In_System : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraGenerate;

		internal MMOptionGroup optNumberOfCurves;

		internal MMOptionButton optNumberOfCurves_opt0;

		internal MMOptionButton optNumberOfCurves_opt1;

		internal MMGroupBox fraValidPhases;

		internal MMLabel MMLabel_5_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		internal MMLabel cboFlashMethod_label;

		internal MMComboEdit cboFlashMethod;

		internal MMCheckBox chkRestart;

		internal MMGroupBox fraSystem;

		internal MMOptionGroup optComp;

		internal MMOptionButton optComp_opt0;

		internal MMOptionButton optComp_opt1;

		internal MMLabel cboStreamID_label;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMComboEdit cboStreamID;

		internal MMLabel cboFlashtype_label;

		internal MMComboEdit cboFlashtype;

		internal MMScrollArea grdSystem;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In_System()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_System_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_in_system.xaml", UriKind.Relative);
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
				fraGenerate = (MMGroupBox)target;
				break;
			case 2:
				optNumberOfCurves = (MMOptionGroup)target;
				break;
			case 3:
				optNumberOfCurves_opt0 = (MMOptionButton)target;
				break;
			case 4:
				optNumberOfCurves_opt1 = (MMOptionButton)target;
				break;
			case 5:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 6:
				MMLabel_5_label = (MMLabel)target;
				break;
			case 7:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 8:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 9:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 10:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 11:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			case 12:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 13:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 14:
				chkRestart = (MMCheckBox)target;
				break;
			case 15:
				fraSystem = (MMGroupBox)target;
				break;
			case 16:
				optComp = (MMOptionGroup)target;
				break;
			case 17:
				optComp_opt0 = (MMOptionButton)target;
				break;
			case 18:
				optComp_opt1 = (MMOptionButton)target;
				break;
			case 19:
				cboStreamID_label = (MMLabel)target;
				break;
			case 20:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 21:
				cboStreamID = (MMComboEdit)target;
				break;
			case 22:
				cboFlashtype_label = (MMLabel)target;
				break;
			case 23:
				cboFlashtype = (MMComboEdit)target;
				break;
			case 24:
				grdSystem = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_In_Vari")]
	public class MMAnalysis_Gen_In_Vari : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraFixedStateVariable;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMComboEdit spcSpec2_combo;

		internal MMVariableEdit spcSpec2;

		internal MMGroupBox fraAdjustedVariables;

		internal MMScrollArea grdVariables;

		internal MMCmdButton cmdRangeList;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In_Vari()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_Vari_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_in_vari.xaml", UriKind.Relative);
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
				fraFixedStateVariable = (MMGroupBox)target;
				break;
			case 2:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 3:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 4:
				spcSpec2_combo = (MMComboEdit)target;
				break;
			case 5:
				spcSpec2 = (MMVariableEdit)target;
				break;
			case 6:
				fraAdjustedVariables = (MMGroupBox)target;
				break;
			case 7:
				grdVariables = (MMScrollArea)target;
				break;
			case 8:
				cmdRangeList = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	public class MMAnalysis_Gen_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Gen_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Gen_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_Out")]
	public class MMAnalysis_Gen_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabGeneralResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Gen_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_out.xaml", UriKind.Relative);
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
				tabGeneralResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.General
{
	[ProgId("MMAnalysis_Gen.MMAnalysis_Gen_Out_Resul")]
	public class MMAnalysis_Gen_Out_Resul : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResults;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Gen_Out_Resul()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_Out_Resul_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/general/mmanalysis_gen_out_resul.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_BiAnalysis_DB")]
	public class MMAnalysis_BiAnalysis_DB : MMTabPage, IComponentConnector
	{
		internal MMLabel cboanaltype_label;

		internal MMComboEdit cboanaltype;

		internal MMGroupBox fraComponentPairGibbs;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMOptionGroup ogrComp;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel cboComponent_label;

		internal MMComboEdit cboComponent;

		internal MMOptionButton ogrComp_opt0;

		internal MMHorizontalListEdit grdList;

		internal MMOptionButton ogrComp_opt1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboGibbsEnergyUnits_label;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMComboEdit cboGibbsEnergyUnits;

		internal MMOptionGroup MMOptionGroup1_0;

		internal MMLabel cboTUnit_0_label;

		internal MMComboEdit cboTUnit_0;

		internal MMOptionButton MMOptionGroup1_0_opt0;

		internal MMHorizontalListEdit MMScrollArea1_0;

		internal MMOptionButton MMOptionGroup1_0_opt1;

		internal MMLabel MMLBUText4_0_label;

		internal MMVariableEdit MMLBUText4_0;

		internal MMLabel MMLBUText5_0_label;

		internal MMVariableEdit MMLBUText5_0;

		internal MMLabel MMSpinBox2_0_label;

		internal MMSpinBox MMSpinBox2_0;

		internal MMLabel MMLBUText6_0_label;

		internal MMVariableEdit MMLBUText6_0;

		internal MMOptionGroup MMOptionGroup1_1;

		internal MMLabel cboTUnit_1_label;

		internal MMComboEdit cboTUnit_1;

		internal MMOptionButton MMOptionGroup1_1_opt0;

		internal MMHorizontalListEdit MMScrollArea1_1;

		internal MMOptionButton MMOptionGroup1_1_opt1;

		internal MMLabel MMLBUText4_1_label;

		internal MMVariableEdit MMLBUText4_1;

		internal MMLabel MMLBUText5_1_label;

		internal MMVariableEdit MMLBUText5_1;

		internal MMLabel MMSpinBox2_1_label;

		internal MMSpinBox MMSpinBox2_1;

		internal MMLabel MMLBUText6_1_label;

		internal MMVariableEdit MMLBUText6_1;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMLabel lblChemistryIDGibbs;

		internal MMComboEdit cboChemistryGibbs;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		internal MMCmdButton cmdSave;

		internal MMCmdButton cmdGo;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_BiAnalysis_DB()
		{
			base.ViewModelType = typeof(MMAnalysis_BiAnalysis_DB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bianalysis_db.xaml", UriKind.Relative);
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
				cboanaltype_label = (MMLabel)target;
				break;
			case 2:
				cboanaltype = (MMComboEdit)target;
				break;
			case 3:
				fraComponentPairGibbs = (MMGroupBox)target;
				break;
			case 4:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 5:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 6:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 7:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 8:
				ogrComp = (MMOptionGroup)target;
				break;
			case 9:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 11:
				cboComponent_label = (MMLabel)target;
				break;
			case 12:
				cboComponent = (MMComboEdit)target;
				break;
			case 13:
				ogrComp_opt0 = (MMOptionButton)target;
				break;
			case 14:
				grdList = (MMHorizontalListEdit)target;
				break;
			case 15:
				ogrComp_opt1 = (MMOptionButton)target;
				break;
			case 16:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 17:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 18:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 19:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 20:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 21:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 22:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 23:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 24:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 25:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 26:
				cboGibbsEnergyUnits_label = (MMLabel)target;
				break;
			case 27:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 28:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 29:
				cboGibbsEnergyUnits = (MMComboEdit)target;
				break;
			case 30:
				MMOptionGroup1_0 = (MMOptionGroup)target;
				break;
			case 31:
				cboTUnit_0_label = (MMLabel)target;
				break;
			case 32:
				cboTUnit_0 = (MMComboEdit)target;
				break;
			case 33:
				MMOptionGroup1_0_opt0 = (MMOptionButton)target;
				break;
			case 34:
				MMScrollArea1_0 = (MMHorizontalListEdit)target;
				break;
			case 35:
				MMOptionGroup1_0_opt1 = (MMOptionButton)target;
				break;
			case 36:
				MMLBUText4_0_label = (MMLabel)target;
				break;
			case 37:
				MMLBUText4_0 = (MMVariableEdit)target;
				break;
			case 38:
				MMLBUText5_0_label = (MMLabel)target;
				break;
			case 39:
				MMLBUText5_0 = (MMVariableEdit)target;
				break;
			case 40:
				MMSpinBox2_0_label = (MMLabel)target;
				break;
			case 41:
				MMSpinBox2_0 = (MMSpinBox)target;
				break;
			case 42:
				MMLBUText6_0_label = (MMLabel)target;
				break;
			case 43:
				MMLBUText6_0 = (MMVariableEdit)target;
				break;
			case 44:
				MMOptionGroup1_1 = (MMOptionGroup)target;
				break;
			case 45:
				cboTUnit_1_label = (MMLabel)target;
				break;
			case 46:
				cboTUnit_1 = (MMComboEdit)target;
				break;
			case 47:
				MMOptionGroup1_1_opt0 = (MMOptionButton)target;
				break;
			case 48:
				MMScrollArea1_1 = (MMHorizontalListEdit)target;
				break;
			case 49:
				MMOptionGroup1_1_opt1 = (MMOptionButton)target;
				break;
			case 50:
				MMLBUText4_1_label = (MMLabel)target;
				break;
			case 51:
				MMLBUText4_1 = (MMVariableEdit)target;
				break;
			case 52:
				MMLBUText5_1_label = (MMLabel)target;
				break;
			case 53:
				MMLBUText5_1 = (MMVariableEdit)target;
				break;
			case 54:
				MMSpinBox2_1_label = (MMLabel)target;
				break;
			case 55:
				MMSpinBox2_1 = (MMSpinBox)target;
				break;
			case 56:
				MMLBUText6_1_label = (MMLabel)target;
				break;
			case 57:
				MMLBUText6_1 = (MMVariableEdit)target;
				break;
			case 58:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 59:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 60:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 61:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 62:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 63:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 64:
				lblChemistryIDGibbs = (MMLabel)target;
				break;
			case 65:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 66:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 67:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			case 68:
				cmdSave = (MMCmdButton)target;
				break;
			case 69:
				cmdGo = (MMCmdButton)target;
				break;
			case 70:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_DB_Results")]
	public class MMAnalysis_Bi_DB_Results : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaMS grdResults;

		internal MMCmdButton cmdPlotwiz;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Bi_DB_Results()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_DB_Results_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_db_results.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
				break;
			case 2:
				cmdPlotwiz = (MMCmdButton)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	public class MMAnalysis_Bi_Inp_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sys_Property = CxvPropertyDeclaration.Register("sys", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SYS"
		});

		public static readonly CxvPropertyDeclaration CALCOPT_Property = CxvPropertyDeclaration.Register("CALCOPT", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CALCOPT"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TABU"
		});

		public static readonly CxvPropertyDeclaration temppres_Property = CxvPropertyDeclaration.Register("temppres", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TEMPPRES"
		});

		public static readonly CxvPropertyDeclaration entcalc_Property = CxvPropertyDeclaration.Register("entcalc", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration bkop_Property = CxvPropertyDeclaration.Register("bkop", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entdig_Property = CxvPropertyDeclaration.Register("entdig", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sys", "@temppres" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@bkop", "@CALCOPT" },
			EnteredDataPaths = { "@entcalc" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdig" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAnalysis_Bi_Inp_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object sys => GetValue(sys_Property);

		public object CALCOPT => GetValue(CALCOPT_Property);

		public object tabu => GetValue(tabu_Property);

		public object temppres => GetValue(temppres_Property);

		public object entcalc => GetValue(entcalc_Property);

		public object bkop => GetValue(bkop_Property);

		public object accres => GetValue(accres_Property);

		public object entdig => GetValue(entdig_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp")]
	public class MMAnalysis_Bi_Inp : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab1;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
				break;
			case 3:
				tab2 = (MMTabItem)target;
				break;
			case 4:
				tab3 = (MMTabItem)target;
				break;
			case 5:
				tab1 = (MMTabItem)target;
				break;
			case 6:
				tab4 = (MMTabItem)target;
				break;
			case 7:
				tabInfo = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp_Binary")]
	public class MMAnalysis_Bi_Inp_Binary : MMTabPage, IComponentConnector
	{
		internal MMLabel cboanaltype_label;

		internal MMComboEdit cboanaltype;

		internal MMLabel cboGibbsEnergyUnits_label;

		internal MMComboEdit cboGibbsEnergyUnits;

		internal MMGroupBox fraComponentPairGibbs;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMLabel cboBasis_label2;

		internal MMComboEdit cboBasis2;

		internal MMGroupBox fraPseudoBinary;

		internal MMCheckBox chkPseudoBinary;

		internal MMLabel cboEntrainer_label;

		internal MMComboEdit cboEntrainer;

		internal MMLabel cboEntrainerFraction_label;

		internal MMScrollArea grdEList;

		internal MMOptionGroup ogrLLETemp;

		internal MMLabel MMLabelL2CompT;

		internal MMComboEdit cboL2CompT;

		internal MMLabel MMLabelLTemp;

		internal MMVariableEdit txtLTemp;

		internal MMComboEdit LLE_TLUnit;

		internal MMLabel MMLabelUTemp;

		internal MMVariableEdit txtUTemp;

		internal MMComboEdit LLE_TUUnit;

		internal MMOptionButton ogrLLETemp_opt1;

		internal MMSpinBox MMSpinBoxLLETemp;

		internal MMOptionButton ogrLLETemp_opt2;

		internal MMVariableEdit txtLLETIncr;

		internal MMOptionGroup ogrLLEPres;

		internal MMLabel MMLabelL2CompP;

		internal MMComboEdit cboL2CompP;

		internal MMLabel MMLabelUPres;

		internal MMVariableEdit txtUPres;

		internal MMComboEdit LLE_PUnit;

		internal MMOptionButton ogrLLEPres_opt1;

		internal MMSpinBox MMSpinBoxLLEPres;

		internal MMOptionButton ogrLLEPres_opt2;

		internal MMVariableEdit txtLLEPIncr;

		internal MMOptionGroup ogrComp;

		internal MMLabel cboBasis_label;

		internal MMComboEdit cboBasis;

		internal MMLabel cboVaryComp_label;

		internal MMComboEdit cboVaryComp;

		internal MMOptionButton ogrComp_opt1;

		internal MMOptionButton ogrComp_opt2;

		internal MMOptionButton ogrComp_opt3;

		internal MMGroupBox MMGroupBoxCEquidistant;

		internal MMLabel MMLabelCEquSPoint;

		internal MMVariableEdit txtCEquStartPoint;

		internal MMLabel MMLabelCEquEPoint;

		internal MMVariableEdit txtCEquEndPoint;

		internal MMOptionGroup MMOptionGroupComp;

		internal MMOptionButton MMOptionGroup_CPoint;

		internal MMSpinBox MMSpinBoxCEquNPoint;

		internal MMOptionButton MMOptionGroup_CIncr;

		internal MMVariableEdit txtCIncr;

		internal MMGroupBox MMGroupBox3;

		internal MMLabel MMLabelLogSPoint;

		internal MMVariableEdit txtLogStartPoint;

		internal MMLabel MMLabelLogEPoint;

		internal MMVariableEdit txtLogEndPoint;

		internal MMLabel MMLabelLogNPoint;

		internal MMSpinBox MMSpinBoxLogNPoint;

		internal MMLabel MMLabelFactor;

		internal MMVariableEdit txFactor;

		internal MMLabel Clist_label;

		internal MMScrollArea grdList;

		internal MMOptionGroup ogrTemp;

		internal MMLabel cboTempUnit_label;

		internal MMComboEdit cboTempUnit;

		internal MMOptionButton ogrTemp_opt1;

		internal MMOptionButton ogrTemp_opt2;

		internal MMGroupBox ogrTempEquidistant;

		internal MMLabel MMLabelTEquSPoint;

		internal MMVariableEdit txtTEquStartPoint;

		internal MMLabel MMLabelTEquEPoint;

		internal MMVariableEdit txtTEquEndPoint;

		internal MMOptionGroup MMOptionGroupTemp;

		internal MMOptionButton MMOptionGroup_Temp1;

		internal MMSpinBox MMSpinBoxEquNPoint;

		internal MMOptionButton MMOptionGroup_Temp2;

		internal MMVariableEdit txtTIncr;

		internal MMLabel Tlist_label;

		internal MMScrollArea grdTList;

		internal MMOptionGroup ogrPres;

		internal MMLabel cboPresUnit_label;

		internal MMComboEdit cboPresUnit;

		internal MMOptionButton ogrPres_opt1;

		internal MMOptionButton ogrPres_opt2;

		internal MMGroupBox ogrPresEquidistant;

		internal MMLabel MMLabelEquSPoint;

		internal MMVariableEdit txtEquStartPoint;

		internal MMLabel MMLabelEquEPoint;

		internal MMVariableEdit txtEquEndPoint;

		internal MMOptionGroup MMOptionGroupPres;

		internal MMOptionButton MMOptionGroupPresOption1;

		internal MMSpinBox MMSpinBoxPEquNPoint;

		internal MMOptionButton MMOptionGroupPresOption2;

		internal MMVariableEdit txtPIncr;

		internal MMLabel Plist_label;

		internal MMScrollArea grdPList;

		internal MMOptionGroup ogrState;

		internal MMLabel txtStatePrese_label;

		internal MMVariableEdit txtStatePres;

		internal MMLabel cboStateTempUnit_label;

		internal MMComboEdit cboStateTempUnit;

		internal MMOptionButton ogrStateTemp_opt1;

		internal MMOptionButton ogrStateTemp_opt2;

		internal MMGroupBox ogrStateTempEquidistant;

		internal MMLabel MMLabelStateSPoint;

		internal MMVariableEdit txtStateStartPoint;

		internal MMLabel MMLabelStateEPoint;

		internal MMVariableEdit txtStateEndPoint;

		internal MMOptionGroup MMOptionGroupState;

		internal MMOptionButton MMOptionButtonSPoint;

		internal MMSpinBox MMSpinBoxStateNPoint;

		internal MMOptionButton MMOptionButtonSIncr;

		internal MMVariableEdit txtStateIncr;

		internal MMLabel Slist_label;

		internal MMScrollArea grdStateList;

		internal MMCmdButton cmdRunAnalysis;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp_Binary()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_Binary_ViewModel);
			InitializeComponent();
			base.Loaded += MMAnalysis_Bi_Inp_Binary_Loaded;
		}

		private void MMAnalysis_Bi_Inp_Binary_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp_binary.xaml", UriKind.Relative);
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
				cboanaltype_label = (MMLabel)target;
				break;
			case 2:
				cboanaltype = (MMComboEdit)target;
				break;
			case 3:
				cboGibbsEnergyUnits_label = (MMLabel)target;
				break;
			case 4:
				cboGibbsEnergyUnits = (MMComboEdit)target;
				break;
			case 5:
				fraComponentPairGibbs = (MMGroupBox)target;
				break;
			case 6:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 7:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 8:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 9:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 10:
				cboBasis_label2 = (MMLabel)target;
				break;
			case 11:
				cboBasis2 = (MMComboEdit)target;
				break;
			case 12:
				fraPseudoBinary = (MMGroupBox)target;
				break;
			case 13:
				chkPseudoBinary = (MMCheckBox)target;
				break;
			case 14:
				cboEntrainer_label = (MMLabel)target;
				break;
			case 15:
				cboEntrainer = (MMComboEdit)target;
				break;
			case 16:
				cboEntrainerFraction_label = (MMLabel)target;
				break;
			case 17:
				grdEList = (MMScrollArea)target;
				break;
			case 18:
				ogrLLETemp = (MMOptionGroup)target;
				break;
			case 19:
				MMLabelL2CompT = (MMLabel)target;
				break;
			case 20:
				cboL2CompT = (MMComboEdit)target;
				break;
			case 21:
				MMLabelLTemp = (MMLabel)target;
				break;
			case 22:
				txtLTemp = (MMVariableEdit)target;
				break;
			case 23:
				LLE_TLUnit = (MMComboEdit)target;
				break;
			case 24:
				MMLabelUTemp = (MMLabel)target;
				break;
			case 25:
				txtUTemp = (MMVariableEdit)target;
				break;
			case 26:
				LLE_TUUnit = (MMComboEdit)target;
				break;
			case 27:
				ogrLLETemp_opt1 = (MMOptionButton)target;
				break;
			case 28:
				MMSpinBoxLLETemp = (MMSpinBox)target;
				break;
			case 29:
				ogrLLETemp_opt2 = (MMOptionButton)target;
				break;
			case 30:
				txtLLETIncr = (MMVariableEdit)target;
				break;
			case 31:
				ogrLLEPres = (MMOptionGroup)target;
				break;
			case 32:
				MMLabelL2CompP = (MMLabel)target;
				break;
			case 33:
				cboL2CompP = (MMComboEdit)target;
				break;
			case 34:
				MMLabelUPres = (MMLabel)target;
				break;
			case 35:
				txtUPres = (MMVariableEdit)target;
				break;
			case 36:
				LLE_PUnit = (MMComboEdit)target;
				break;
			case 37:
				ogrLLEPres_opt1 = (MMOptionButton)target;
				break;
			case 38:
				MMSpinBoxLLEPres = (MMSpinBox)target;
				break;
			case 39:
				ogrLLEPres_opt2 = (MMOptionButton)target;
				break;
			case 40:
				txtLLEPIncr = (MMVariableEdit)target;
				break;
			case 41:
				ogrComp = (MMOptionGroup)target;
				break;
			case 42:
				cboBasis_label = (MMLabel)target;
				break;
			case 43:
				cboBasis = (MMComboEdit)target;
				break;
			case 44:
				cboVaryComp_label = (MMLabel)target;
				break;
			case 45:
				cboVaryComp = (MMComboEdit)target;
				break;
			case 46:
				ogrComp_opt1 = (MMOptionButton)target;
				break;
			case 47:
				ogrComp_opt2 = (MMOptionButton)target;
				break;
			case 48:
				ogrComp_opt3 = (MMOptionButton)target;
				break;
			case 49:
				MMGroupBoxCEquidistant = (MMGroupBox)target;
				break;
			case 50:
				MMLabelCEquSPoint = (MMLabel)target;
				break;
			case 51:
				txtCEquStartPoint = (MMVariableEdit)target;
				break;
			case 52:
				MMLabelCEquEPoint = (MMLabel)target;
				break;
			case 53:
				txtCEquEndPoint = (MMVariableEdit)target;
				break;
			case 54:
				MMOptionGroupComp = (MMOptionGroup)target;
				break;
			case 55:
				MMOptionGroup_CPoint = (MMOptionButton)target;
				break;
			case 56:
				MMSpinBoxCEquNPoint = (MMSpinBox)target;
				break;
			case 57:
				MMOptionGroup_CIncr = (MMOptionButton)target;
				break;
			case 58:
				txtCIncr = (MMVariableEdit)target;
				break;
			case 59:
				MMGroupBox3 = (MMGroupBox)target;
				break;
			case 60:
				MMLabelLogSPoint = (MMLabel)target;
				break;
			case 61:
				txtLogStartPoint = (MMVariableEdit)target;
				break;
			case 62:
				MMLabelLogEPoint = (MMLabel)target;
				break;
			case 63:
				txtLogEndPoint = (MMVariableEdit)target;
				break;
			case 64:
				MMLabelLogNPoint = (MMLabel)target;
				break;
			case 65:
				MMSpinBoxLogNPoint = (MMSpinBox)target;
				break;
			case 66:
				MMLabelFactor = (MMLabel)target;
				break;
			case 67:
				txFactor = (MMVariableEdit)target;
				break;
			case 68:
				Clist_label = (MMLabel)target;
				break;
			case 69:
				grdList = (MMScrollArea)target;
				break;
			case 70:
				ogrTemp = (MMOptionGroup)target;
				break;
			case 71:
				cboTempUnit_label = (MMLabel)target;
				break;
			case 72:
				cboTempUnit = (MMComboEdit)target;
				break;
			case 73:
				ogrTemp_opt1 = (MMOptionButton)target;
				break;
			case 74:
				ogrTemp_opt2 = (MMOptionButton)target;
				break;
			case 75:
				ogrTempEquidistant = (MMGroupBox)target;
				break;
			case 76:
				MMLabelTEquSPoint = (MMLabel)target;
				break;
			case 77:
				txtTEquStartPoint = (MMVariableEdit)target;
				break;
			case 78:
				MMLabelTEquEPoint = (MMLabel)target;
				break;
			case 79:
				txtTEquEndPoint = (MMVariableEdit)target;
				break;
			case 80:
				MMOptionGroupTemp = (MMOptionGroup)target;
				break;
			case 81:
				MMOptionGroup_Temp1 = (MMOptionButton)target;
				break;
			case 82:
				MMSpinBoxEquNPoint = (MMSpinBox)target;
				break;
			case 83:
				MMOptionGroup_Temp2 = (MMOptionButton)target;
				break;
			case 84:
				txtTIncr = (MMVariableEdit)target;
				break;
			case 85:
				Tlist_label = (MMLabel)target;
				break;
			case 86:
				grdTList = (MMScrollArea)target;
				break;
			case 87:
				ogrPres = (MMOptionGroup)target;
				break;
			case 88:
				cboPresUnit_label = (MMLabel)target;
				break;
			case 89:
				cboPresUnit = (MMComboEdit)target;
				break;
			case 90:
				ogrPres_opt1 = (MMOptionButton)target;
				break;
			case 91:
				ogrPres_opt2 = (MMOptionButton)target;
				break;
			case 92:
				ogrPresEquidistant = (MMGroupBox)target;
				break;
			case 93:
				MMLabelEquSPoint = (MMLabel)target;
				break;
			case 94:
				txtEquStartPoint = (MMVariableEdit)target;
				break;
			case 95:
				MMLabelEquEPoint = (MMLabel)target;
				break;
			case 96:
				txtEquEndPoint = (MMVariableEdit)target;
				break;
			case 97:
				MMOptionGroupPres = (MMOptionGroup)target;
				break;
			case 98:
				MMOptionGroupPresOption1 = (MMOptionButton)target;
				break;
			case 99:
				MMSpinBoxPEquNPoint = (MMSpinBox)target;
				break;
			case 100:
				MMOptionGroupPresOption2 = (MMOptionButton)target;
				break;
			case 101:
				txtPIncr = (MMVariableEdit)target;
				break;
			case 102:
				Plist_label = (MMLabel)target;
				break;
			case 103:
				grdPList = (MMScrollArea)target;
				break;
			case 104:
				ogrState = (MMOptionGroup)target;
				break;
			case 105:
				txtStatePrese_label = (MMLabel)target;
				break;
			case 106:
				txtStatePres = (MMVariableEdit)target;
				break;
			case 107:
				cboStateTempUnit_label = (MMLabel)target;
				break;
			case 108:
				cboStateTempUnit = (MMComboEdit)target;
				break;
			case 109:
				ogrStateTemp_opt1 = (MMOptionButton)target;
				break;
			case 110:
				ogrStateTemp_opt2 = (MMOptionButton)target;
				break;
			case 111:
				ogrStateTempEquidistant = (MMGroupBox)target;
				break;
			case 112:
				MMLabelStateSPoint = (MMLabel)target;
				break;
			case 113:
				txtStateStartPoint = (MMVariableEdit)target;
				break;
			case 114:
				MMLabelStateEPoint = (MMLabel)target;
				break;
			case 115:
				txtStateEndPoint = (MMVariableEdit)target;
				break;
			case 116:
				MMOptionGroupState = (MMOptionGroup)target;
				break;
			case 117:
				MMOptionButtonSPoint = (MMOptionButton)target;
				break;
			case 118:
				MMSpinBoxStateNPoint = (MMSpinBox)target;
				break;
			case 119:
				MMOptionButtonSIncr = (MMOptionButton)target;
				break;
			case 120:
				txtStateIncr = (MMVariableEdit)target;
				break;
			case 121:
				Slist_label = (MMLabel)target;
				break;
			case 122:
				grdStateList = (MMScrollArea)target;
				break;
			case 123:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	public class MMAnalysis_Bi_Inp_Methods_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboWaterSol_MultiMap_Property = CxvPropertyDeclaration.Register("cboWaterSol_MultiMap", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboWaterSol_var1",
					DataPath = "@main.Input.SOLU_WATER"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "0 - Saturated steam table",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_0___Saturated_steam_table",
					Value = "cboWaterSol_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "0"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "1 - Saturated primary package",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_1___Saturated_primary_package",
					Value = "cboWaterSol_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "1"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "2 - Unsaturated primary package",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_2___Unsaturated_primary_package",
					Value = "cboWaterSol_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "3 - No correction",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_3___No_correction",
					Value = "cboWaterSol_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "3"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "4 - Water solubility is one",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_4___Water_solubility_is_one",
					Value = "cboWaterSol_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "4"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "5 - Unsaturated steam",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_5___Unsaturated_steam",
					Value = "cboWaterSol_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWaterSol_var1",
							Value = "5"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboFreeWatProp_var1_Property = CxvPropertyDeclaration.Register("cboFreeWatProp_var1", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.FRWATEROPSET"
		});

		public static readonly CxvPropertyDeclaration cboHenryComps_var1_Property = CxvPropertyDeclaration.Register("cboHenryComps_var1", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.HENRY_COMPS",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.HENRYL"
			}
		});

		public static readonly CxvPropertyDeclaration cboPropMethod_var1_Property = CxvPropertyDeclaration.Register("cboPropMethod_var1", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.OPSETNAME"
		});

		public static readonly CxvPropertyDeclaration cboSimulationApproach_MultiMap_Property = CxvPropertyDeclaration.Register("cboSimulationApproach_MultiMap", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboSimulationApproach_var1",
					DataPath = "@main.Input.TRUE_COMPS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "True components",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_True_components",
					Value = "cboSimulationApproach_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSimulationApproach_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Apparent components",
					DisplayResourceKey = "MMAnalysis_Bi_Inp_Methods_ViewModel__CxvMultiMapOption_Display_Apparent_components",
					Value = "cboSimulationApproach_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSimulationApproach_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboChemId_var1_Property = CxvPropertyDeclaration.Register("cboChemId_var1", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.CHEMISTRY"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Bi_Inp_Methods_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel"
		});

		public object cboWaterSol_MultiMap => GetValue(cboWaterSol_MultiMap_Property);

		public object cboFreeWatProp_var1 => GetValue(cboFreeWatProp_var1_Property);

		public object cboHenryComps_var1 => GetValue(cboHenryComps_var1_Property);

		public object cboPropMethod_var1 => GetValue(cboPropMethod_var1_Property);

		public object cboSimulationApproach_MultiMap => GetValue(cboSimulationApproach_MultiMap_Property);

		public object cboChemId_var1 => GetValue(cboChemId_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Bi_Inp_Methods_ViewModel__SimulationLabel_CalculationApproach);
				}
				else
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Bi_Inp_Methods_ViewModel__SimulationLabel_SimulationApproach);
				}
			}
			base.OnUpdateData();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp_Methods")]
	public class MMAnalysis_Bi_Inp_Methods : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraPropOptions;

		internal MMLabel cboPropMethod_label;

		internal MMComboEdit cboPropMethod;

		internal MMLabel cboHenryComps_label;

		internal MMComboEdit cboHenryComps;

		internal MMGroupBox fraElecCal;

		internal MMLabel cboChemId_label;

		internal MMComboEdit cboChemId;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		internal MMGroupBox fraPetroOptions;

		internal MMLabel cboFreeWatProp_label;

		internal MMComboEdit cboFreeWatProp;

		internal MMLabel cboWaterSol_label;

		internal MMComboEdit cboWaterSol;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp_Methods()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_Methods_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp_methods.xaml", UriKind.Relative);
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
				fraPropOptions = (MMGroupBox)target;
				break;
			case 2:
				cboPropMethod_label = (MMLabel)target;
				break;
			case 3:
				cboPropMethod = (MMComboEdit)target;
				break;
			case 4:
				cboHenryComps_label = (MMLabel)target;
				break;
			case 5:
				cboHenryComps = (MMComboEdit)target;
				break;
			case 6:
				fraElecCal = (MMGroupBox)target;
				break;
			case 7:
				cboChemId_label = (MMLabel)target;
				break;
			case 8:
				cboChemId = (MMComboEdit)target;
				break;
			case 9:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 10:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			case 11:
				fraPetroOptions = (MMGroupBox)target;
				break;
			case 12:
				cboFreeWatProp_label = (MMLabel)target;
				break;
			case 13:
				cboFreeWatProp = (MMComboEdit)target;
				break;
			case 14:
				cboWaterSol_label = (MMLabel)target;
				break;
			case 15:
				cboWaterSol = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp_Option")]
	public class MMAnalysis_Bi_Inp_Option : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraValidPhases;

		internal MMLabel MMLabel_5_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel MMLabelL2CompT;

		internal MMComboEdit cboL2CompT;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		internal MMLabel cboFlashMethod_label;

		internal MMComboEdit cboFlashMethod;

		internal MMCheckBox chkRestart;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMComboEdit cboChemistryGibbs;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp_Option()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_Option_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp_option.xaml", UriKind.Relative);
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
				fraValidPhases = (MMGroupBox)target;
				break;
			case 2:
				MMLabel_5_label = (MMLabel)target;
				break;
			case 3:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 4:
				MMLabelL2CompT = (MMLabel)target;
				break;
			case 5:
				cboL2CompT = (MMComboEdit)target;
				break;
			case 6:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 7:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 8:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 9:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			case 10:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 11:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 12:
				chkRestart = (MMCheckBox)target;
				break;
			case 13:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 14:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 15:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 16:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 17:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 18:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 19:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 20:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 21:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp_System")]
	public class MMAnalysis_Bi_Inp_System : MMTabPage, IComponentConnector
	{
		internal MMLabel cboanaltype_label;

		internal MMComboEdit cboanaltype;

		internal MMGroupBox fraValidPhases;

		internal MMComboEdit cboValidPhases;

		internal MMGroupBox fraComponentPairGibbs;

		internal MMLabel cboComp1Gibbs_label;

		internal MMComboEdit cboComp1Gibbs;

		internal MMLabel cboComp2Gibbs_label;

		internal MMComboEdit cboComp2Gibbs;

		internal MMOptionGroup ogrComp;

		internal MMLabel cboBasis_label;

		internal MMComboEdit cboBasis;

		internal MMLabel cboComponent_label;

		internal MMComboEdit cboComponent;

		internal MMOptionButton ogrComp_opt0;

		internal MMHorizontalListEdit grdList;

		internal MMOptionButton ogrComp_opt1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp_System()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_System_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp_system.xaml", UriKind.Relative);
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
				cboanaltype_label = (MMLabel)target;
				break;
			case 2:
				cboanaltype = (MMComboEdit)target;
				break;
			case 3:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 4:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 5:
				fraComponentPairGibbs = (MMGroupBox)target;
				break;
			case 6:
				cboComp1Gibbs_label = (MMLabel)target;
				break;
			case 7:
				cboComp1Gibbs = (MMComboEdit)target;
				break;
			case 8:
				cboComp2Gibbs_label = (MMLabel)target;
				break;
			case 9:
				cboComp2Gibbs = (MMComboEdit)target;
				break;
			case 10:
				ogrComp = (MMOptionGroup)target;
				break;
			case 11:
				cboBasis_label = (MMLabel)target;
				break;
			case 12:
				cboBasis = (MMComboEdit)target;
				break;
			case 13:
				cboComponent_label = (MMLabel)target;
				break;
			case 14:
				cboComponent = (MMComboEdit)target;
				break;
			case 15:
				ogrComp_opt0 = (MMOptionButton)target;
				break;
			case 16:
				grdList = (MMHorizontalListEdit)target;
				break;
			case 17:
				ogrComp_opt1 = (MMOptionButton)target;
				break;
			case 18:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 19:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 20:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 21:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 22:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 23:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 24:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 25:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Inp_Variabl")]
	public class MMAnalysis_Bi_Inp_Variabl : MMTabPage, IComponentConnector
	{
		internal MMLabel cboGibbsEnergyUnits_label;

		internal MMComboEdit cboGibbsEnergyUnits;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMOptionGroup MMOptionGroup1;

		internal MMLabel cboTUnit_1_label;

		internal MMComboEdit cboTUnit_1;

		internal MMOptionButton MMOptionGroup1_opt0;

		internal MMHorizontalListEdit MMScrollArea1;

		internal MMOptionButton MMOptionGroup1_opt1;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMSpinBox2_label;

		internal MMSpinBox MMSpinBox2;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		internal MMOptionGroup ogrTemp;

		internal MMLabel cboTUnit_0_label;

		internal MMComboEdit cboTUnit_0;

		internal MMOptionButton ogrTemp_opt0;

		internal MMHorizontalListEdit grdList;

		internal MMOptionButton ogrTemp_opt1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Inp_Variabl()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Inp_Variabl_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_inp_variabl.xaml", UriKind.Relative);
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
				cboGibbsEnergyUnits_label = (MMLabel)target;
				break;
			case 2:
				cboGibbsEnergyUnits = (MMComboEdit)target;
				break;
			case 3:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 4:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 5:
				MMOptionGroup1 = (MMOptionGroup)target;
				break;
			case 6:
				cboTUnit_1_label = (MMLabel)target;
				break;
			case 7:
				cboTUnit_1 = (MMComboEdit)target;
				break;
			case 8:
				MMOptionGroup1_opt0 = (MMOptionButton)target;
				break;
			case 9:
				MMScrollArea1 = (MMHorizontalListEdit)target;
				break;
			case 10:
				MMOptionGroup1_opt1 = (MMOptionButton)target;
				break;
			case 11:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 12:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 13:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 14:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 15:
				MMSpinBox2_label = (MMLabel)target;
				break;
			case 16:
				MMSpinBox2 = (MMSpinBox)target;
				break;
			case 17:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 18:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			case 19:
				ogrTemp = (MMOptionGroup)target;
				break;
			case 20:
				cboTUnit_0_label = (MMLabel)target;
				break;
			case 21:
				cboTUnit_0 = (MMComboEdit)target;
				break;
			case 22:
				ogrTemp_opt0 = (MMOptionButton)target;
				break;
			case 23:
				grdList = (MMHorizontalListEdit)target;
				break;
			case 24:
				ogrTemp_opt1 = (MMOptionButton)target;
				break;
			case 25:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 26:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 27:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 28:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 29:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 30:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 31:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 32:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	public class MMAnalysis_Bi_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Bi_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Bi_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Out")]
	public class MMAnalysis_Bi_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_out.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Bi_Out_Results")]
	public class MMAnalysis_Bi_Out_Results : MMTabPage, IComponentConnector
	{
		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Bi_Out_Results()
		{
			base.ViewModelType = typeof(MMAnalysis_Bi_Out_Results_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_bi_out_results.xaml", UriKind.Relative);
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
				grdResults = (MMScrollAreaMS)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	public class MMAnalysis_Gen_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel"
		});

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Calculation);
				}
				else
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Simulation);
				}
			}
			base.OnUpdateData();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.Binary
{
	[ProgId("MMAnalysis_Bi.MMAnalysis_Gen_In_Diag")]
	public class MMAnalysis_Gen_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/binary/mmanalysis_gen_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	public class MMAnalysis_PTEn_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_PTEn_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "Simulation"
		});

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Calculation);
				}
				else
				{
					ResolveUpdateParameter("Simulation", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_PTEn_In_Diag_ViewModel__Simulation_Simulation);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAnalysis_PTEn_In_Diag")]
	public class MMAnalysis_PTEn_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmanalysis_pten_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAnalysis_PTEn_In_Enve")]
	public class MMAnalysis_PTEn_In_Enve : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraVaporFractionBranches;

		internal MMCheckBox chkDew_BubblePointCurves;

		internal MMLabel lblAdditionalVaporFractions;

		internal MMScrollArea MMScrollArea1;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMGroupBox fraOptionalInitialPoint;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraOptionalTerminationPoint;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_In_Enve()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_In_Enve_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmanalysis_pten_in_enve.xaml", UriKind.Relative);
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
				fraVaporFractionBranches = (MMGroupBox)target;
				break;
			case 2:
				chkDew_BubblePointCurves = (MMCheckBox)target;
				break;
			case 3:
				lblAdditionalVaporFractions = (MMLabel)target;
				break;
			case 4:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 5:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 6:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 7:
				fraOptionalInitialPoint = (MMGroupBox)target;
				break;
			case 8:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 9:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 10:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 11:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 12:
				fraOptionalTerminationPoint = (MMGroupBox)target;
				break;
			case 13:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 14:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAnalysis_PTEn_Out_Res")]
	public class MMAnalysis_PTEn_Out_Res : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuTcrit_label;

		internal MMVariableEdit lbtuTcrit;

		internal MMLabel lbtuTcrit3_label;

		internal MMVariableEdit lbtuTcrit3;

		internal MMLabel lbtuPcrit_label;

		internal MMVariableEdit lbtuPcrit;

		internal MMLabel lbtuPcrit3_label;

		internal MMVariableEdit lbtuPcrit3;

		internal MMLabel lbtuTmax_label;

		internal MMVariableEdit lbtuTmax;

		internal MMLabel lbtuPatTmax_label;

		internal MMVariableEdit lbtuPatTmax;

		internal MMLabel lbtuPmax_label;

		internal MMVariableEdit lbtuPmax;

		internal MMLabel lbtuTatPmax_label;

		internal MMVariableEdit lbtuTatPmax;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_PTEn_Out_Res()
		{
			base.ViewModelType = typeof(MMAnalysis_PTEn_Out_Res_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmanalysis_pten_out_res.xaml", UriKind.Relative);
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
				lbtuTcrit_label = (MMLabel)target;
				break;
			case 2:
				lbtuTcrit = (MMVariableEdit)target;
				break;
			case 3:
				lbtuTcrit3_label = (MMLabel)target;
				break;
			case 4:
				lbtuTcrit3 = (MMVariableEdit)target;
				break;
			case 5:
				lbtuPcrit_label = (MMLabel)target;
				break;
			case 6:
				lbtuPcrit = (MMVariableEdit)target;
				break;
			case 7:
				lbtuPcrit3_label = (MMLabel)target;
				break;
			case 8:
				lbtuPcrit3 = (MMVariableEdit)target;
				break;
			case 9:
				lbtuTmax_label = (MMLabel)target;
				break;
			case 10:
				lbtuTmax = (MMVariableEdit)target;
				break;
			case 11:
				lbtuPatTmax_label = (MMLabel)target;
				break;
			case 12:
				lbtuPatTmax = (MMVariableEdit)target;
				break;
			case 13:
				lbtuPmax_label = (MMLabel)target;
				break;
			case 14:
				lbtuPmax = (MMVariableEdit)target;
				break;
			case 15:
				lbtuTatPmax_label = (MMLabel)target;
				break;
			case 16:
				lbtuTatPmax = (MMVariableEdit)target;
				break;
			case 17:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	public class MMAPr_Anal_PTEn_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration sys_Property = CxvPropertyDeclaration.Register("sys", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration enve_Property = CxvPropertyDeclaration.Register("enve", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENVE"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TABU"
		});

		public static readonly CxvPropertyDeclaration proper_Property = CxvPropertyDeclaration.Register("proper", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sys", "@enve" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@proper" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAPr_Anal_PTEn_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object choice => GetValue(choice_Property);

		public object sys => GetValue(sys_Property);

		public object enve => GetValue(enve_Property);

		public object tabu => GetValue(tabu_Property);

		public object proper => GetValue(proper_Property);

		public object entprop => GetValue(entprop_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAPr_Anal_PTEn_In")]
	public class MMAPr_Anal_PTEn_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAPr_Anal_PTEn_In()
		{
			base.ViewModelType = typeof(MMAPr_Anal_PTEn_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmapr_anal_pten_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
				break;
			case 2:
				tab0 = (MMTabItem)target;
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
				tabInfo = (MMTabItem)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAPr_Anal_PTEn_In_Syst")]
	public class MMAPr_Anal_PTEn_In_Syst : MMTabPage, IComponentConnector
	{
		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollAreaMS grdSystem;

		internal MMGroupBox fraInformation;

		internal MMLabel MMLabel_Info;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel3;

		internal MMLabel MMLabel5;

		internal MMLabel lblAdditionalVaporFractions;

		internal MMCheckBox chkDew_BubblePointCurves;

		internal MMScrollAreaMS MMScrollArea1;

		internal MMLabel optionSpec_Label;

		internal MMLabel cboValidPhases_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboMethod_label;

		internal MMComboEdit cboMethod;

		internal MMLabel MMSpinBox1_label;

		internal MMSpinBox MMSpinBox1;

		internal MMLabel lbtuPressure_label;

		internal MMVariableEdit lbtuPressure;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel Termination_Label;

		internal MMLabel MMLabel18;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMLabel20;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText5_label;

		internal MMVariableEdit MMLBUText5;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		internal MMLabel MMLBUText7_label;

		internal MMVariableEdit MMLBUText7;

		internal MMCmdButton cmdRunAnalysis;

		internal MMCmdButton cmdSaveAnalysis;

		private bool _contentLoaded;

		public MMAPr_Anal_PTEn_In_Syst()
		{
			base.ViewModelType = typeof(MMAPr_Anal_PTEn_In_Syst_ViewModel);
			InitializeComponent();
			base.Loaded += MMAPr_Anal_PTEn_In_Syst_Loaded;
		}

		private void MMAPr_Anal_PTEn_In_Syst_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmapr_anal_pten_in_syst.xaml", UriKind.Relative);
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
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 2:
				grdSystem = (MMScrollAreaMS)target;
				break;
			case 3:
				fraInformation = (MMGroupBox)target;
				break;
			case 4:
				MMLabel_Info = (MMLabel)target;
				break;
			case 5:
				MMLabel2 = (MMLabel)target;
				break;
			case 6:
				MMLabel3 = (MMLabel)target;
				break;
			case 7:
				MMLabel5 = (MMLabel)target;
				break;
			case 8:
				lblAdditionalVaporFractions = (MMLabel)target;
				break;
			case 9:
				chkDew_BubblePointCurves = (MMCheckBox)target;
				break;
			case 10:
				MMScrollArea1 = (MMScrollAreaMS)target;
				break;
			case 11:
				optionSpec_Label = (MMLabel)target;
				break;
			case 12:
				cboValidPhases_label = (MMLabel)target;
				break;
			case 13:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 14:
				cboMethod_label = (MMLabel)target;
				break;
			case 15:
				cboMethod = (MMComboEdit)target;
				break;
			case 16:
				MMSpinBox1_label = (MMLabel)target;
				break;
			case 17:
				MMSpinBox1 = (MMSpinBox)target;
				break;
			case 18:
				lbtuPressure_label = (MMLabel)target;
				break;
			case 19:
				lbtuPressure = (MMVariableEdit)target;
				break;
			case 20:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 21:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 22:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 23:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 24:
				Termination_Label = (MMLabel)target;
				break;
			case 25:
				MMLabel18 = (MMLabel)target;
				break;
			case 26:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 27:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 28:
				MMLabel20 = (MMLabel)target;
				break;
			case 29:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 30:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 31:
				MMLBUText5_label = (MMLabel)target;
				break;
			case 32:
				MMLBUText5 = (MMVariableEdit)target;
				break;
			case 33:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 34:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			case 35:
				MMLBUText7_label = (MMLabel)target;
				break;
			case 36:
				MMLBUText7 = (MMVariableEdit)target;
				break;
			case 37:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			case 38:
				cmdSaveAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	public class MMAPr_Anal_PTEn_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAPr_Anal_PTEn_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Anal_PTEn_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_PTEnvelope
{
	[ProgId("MMAPr_Anal_PTEn.MMAPr_Anal_PTEn_Out")]
	public class MMAPr_Anal_PTEn_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAPr_Anal_PTEn_Out()
		{
			base.ViewModelType = typeof(MMAPr_Anal_PTEn_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_ptenvelope/mmapr_anal_pten_out.xaml", UriKind.Relative);
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	public class MMAPr_Anal_Mix_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration STRM_Property = CxvPropertyDeclaration.Register("STRM", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration COMPVARY_Property = CxvPropertyDeclaration.Register("COMPVARY", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.COMPVARY"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entcalc_Property = CxvPropertyDeclaration.Register("entcalc", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCALC"
		});

		public static readonly CxvPropertyDeclaration bkop_Property = CxvPropertyDeclaration.Register("bkop", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration CALCOPT_Property = CxvPropertyDeclaration.Register("CALCOPT", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CALCOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@STRM", "@COMPVARY" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@bkop", "@CALCOPT" },
			EnteredDataPaths = { "@entcalc" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAPr_Anal_Mix_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object STRM => GetValue(STRM_Property);

		public object COMPVARY => GetValue(COMPVARY_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object accres => GetValue(accres_Property);

		public object entcalc => GetValue(entcalc_Property);

		public object bkop => GetValue(bkop_Property);

		public object CALCOPT => GetValue(CALCOPT_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	[ProgId("MMAPr_Anal_Mix.MMAPr_Anal_Mix_In")]
	public class MMAPr_Anal_Mix_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisMixture;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAPr_Anal_Mix_In()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Mix_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_mixture/mmapr_anal_mix_in.xaml", UriKind.Relative);
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
				tabAnalysisMixture = (MMTabStrip)target;
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
			case 7:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	[ProgId("MMAPr_Anal_Mix.MMAPr_Anal_Mix_In_CalcOptions")]
	public class MMAPr_Anal_Mix_In_CalcOptions : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraValidPhases;

		internal MMCheckBox chkPerformFlashCalculations;

		internal MMLabel MMLabel_5_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel cboFlashType_label;

		internal MMComboEdit cboFlashType;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		internal MMLabel cboFlashMethod_label;

		internal MMComboEdit cboFlashMethod;

		internal MMCheckBox chkRestart;

		internal MMGroupBox fraPropertyOptionsGibbs;

		internal MMLabel cboMethodsGibbs_label;

		internal MMComboEdit cboMethodsGibbs;

		internal MMLabel cboHenryCompsGibbs_label;

		internal MMComboEdit cboHenryCompsGibbs;

		internal MMLabel cboChemistryGibbs_label;

		internal MMComboEdit cboChemistryGibbs;

		internal MMLabel cboSimulationApproach_label;

		internal MMComboEdit cboSimulationApproach;

		private bool _contentLoaded;

		public MMAPr_Anal_Mix_In_CalcOptions()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Mix_In_CalcOptions_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_mixture/mmapr_anal_mix_in_calcoptions.xaml", UriKind.Relative);
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
				fraValidPhases = (MMGroupBox)target;
				break;
			case 2:
				chkPerformFlashCalculations = (MMCheckBox)target;
				break;
			case 3:
				MMLabel_5_label = (MMLabel)target;
				break;
			case 4:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 5:
				cboFlashType_label = (MMLabel)target;
				break;
			case 6:
				cboFlashType = (MMComboEdit)target;
				break;
			case 7:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 8:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 9:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 10:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			case 11:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 12:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 13:
				chkRestart = (MMCheckBox)target;
				break;
			case 14:
				fraPropertyOptionsGibbs = (MMGroupBox)target;
				break;
			case 15:
				cboMethodsGibbs_label = (MMLabel)target;
				break;
			case 16:
				cboMethodsGibbs = (MMComboEdit)target;
				break;
			case 17:
				cboHenryCompsGibbs_label = (MMLabel)target;
				break;
			case 18:
				cboHenryCompsGibbs = (MMComboEdit)target;
				break;
			case 19:
				cboChemistryGibbs_label = (MMLabel)target;
				break;
			case 20:
				cboChemistryGibbs = (MMComboEdit)target;
				break;
			case 21:
				cboSimulationApproach_label = (MMLabel)target;
				break;
			case 22:
				cboSimulationApproach = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	[ProgId("MMAPr_Anal_Mix.MMAPr_Anal_Mix_In_Mixture")]
	public class MMAPr_Anal_Mix_In_Mixture : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInformation;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel3;

		internal MMLabel MMLabel5;

		internal MMExpander spec;

		internal MMGroupBox MMGroupBox_Comp;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollArea grdSystem;

		internal MMValueEdit totalTxt;

		internal MMGroupBox Proper_Rep;

		internal MMListPickerForPropSet MMListPicker1;

		internal MMExpander spec2;

		internal MMOptionGroup Manipulated_Var;

		internal MMComboEdit cboVariable_AdvCollection1_Comb;

		internal MMComboEdit cboVariable_Comp;

		internal MMOptionButton ogrComp_opt1;

		internal MMOptionButton ogrComp_opt2;

		internal MMOptionButton ogrComp_opt3;

		internal MMGroupBox MMGroupBoxCEquidistant;

		internal MMLabel MMLabelEquSPoint;

		internal MMVariableEdit txtEquStartPoint;

		internal MMComboEdit StartPointUnit;

		internal MMLabel MMLabelCEquEPoint;

		internal MMVariableEdit txtEquEndPoint;

		internal MMComboEdit EndPointUnit;

		internal MMOptionGroup MMOptionGroupComp;

		internal MMOptionButton MMOptionGroup_CPoint;

		internal MMSpinBox MMSpinBoxEquNPoint;

		internal MMOptionButton MMOptionGroup_CIncr;

		internal MMVariableEdit txtIncr;

		internal MMComboEdit IncrUnit;

		internal MMGroupBox MMGroupBox3;

		internal MMLabel MMLabelLogSPoint;

		internal MMVariableEdit txtLogStartPoint;

		internal MMComboEdit LogStartPointUnit;

		internal MMLabel MMLabelLogEPoint;

		internal MMVariableEdit txtLogEndPoint;

		internal MMLabel MMLabelLogNPoint;

		internal MMComboEdit LogEndPointUnit;

		internal MMSpinBox MMSpinBoxLogNPoint;

		internal MMLabel MMLabelFactor;

		internal MMVariableEdit txFactor;

		internal MMLabel Mlist_label;

		internal MMComboEdit ListValueUnit;

		internal MMScrollArea grdList;

		internal MMGroupBox Parametric_Var;

		internal MMComboEdit cboVariable_AdvCollection2_Comb;

		internal MMComboEdit cboVariable_Unit2_Comb;

		internal MMLabel Enterval_label;

		internal MMScrollArea grdList1;

		internal MMGroupBox Enter_Var;

		internal MMLabel Fixedstate_label;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMCmdButton cmdRunAnalysis;

		private bool _contentLoaded;

		public MMAPr_Anal_Mix_In_Mixture()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Mix_In_Mixture_ViewModel);
			InitializeComponent();
			base.Loaded += MMAPr_Anal_Mix_In_Mixture_Loaded;
		}

		private void MMAPr_Anal_Mix_In_Mixture_Loaded(object sender, RoutedEventArgs e)
		{
			if (Utilities.GetDescendantFromName(cmdRunAnalysis, "PART_BUTTON") is Button button)
			{
				button.Background = Brushes.LightGreen;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_mixture/mmapr_anal_mix_in_mixture.xaml", UriKind.Relative);
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
				fraInformation = (MMGroupBox)target;
				break;
			case 2:
				MMLabel2 = (MMLabel)target;
				break;
			case 3:
				MMLabel3 = (MMLabel)target;
				break;
			case 4:
				MMLabel5 = (MMLabel)target;
				break;
			case 5:
				spec = (MMExpander)target;
				break;
			case 6:
				MMGroupBox_Comp = (MMGroupBox)target;
				break;
			case 7:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 8:
				grdSystem = (MMScrollArea)target;
				break;
			case 9:
				totalTxt = (MMValueEdit)target;
				break;
			case 10:
				Proper_Rep = (MMGroupBox)target;
				break;
			case 11:
				MMListPicker1 = (MMListPickerForPropSet)target;
				break;
			case 12:
				spec2 = (MMExpander)target;
				break;
			case 13:
				Manipulated_Var = (MMOptionGroup)target;
				break;
			case 14:
				cboVariable_AdvCollection1_Comb = (MMComboEdit)target;
				break;
			case 15:
				cboVariable_Comp = (MMComboEdit)target;
				break;
			case 16:
				ogrComp_opt1 = (MMOptionButton)target;
				break;
			case 17:
				ogrComp_opt2 = (MMOptionButton)target;
				break;
			case 18:
				ogrComp_opt3 = (MMOptionButton)target;
				break;
			case 19:
				MMGroupBoxCEquidistant = (MMGroupBox)target;
				break;
			case 20:
				MMLabelEquSPoint = (MMLabel)target;
				break;
			case 21:
				txtEquStartPoint = (MMVariableEdit)target;
				break;
			case 22:
				StartPointUnit = (MMComboEdit)target;
				break;
			case 23:
				MMLabelCEquEPoint = (MMLabel)target;
				break;
			case 24:
				txtEquEndPoint = (MMVariableEdit)target;
				break;
			case 25:
				EndPointUnit = (MMComboEdit)target;
				break;
			case 26:
				MMOptionGroupComp = (MMOptionGroup)target;
				break;
			case 27:
				MMOptionGroup_CPoint = (MMOptionButton)target;
				break;
			case 28:
				MMSpinBoxEquNPoint = (MMSpinBox)target;
				break;
			case 29:
				MMOptionGroup_CIncr = (MMOptionButton)target;
				break;
			case 30:
				txtIncr = (MMVariableEdit)target;
				break;
			case 31:
				IncrUnit = (MMComboEdit)target;
				break;
			case 32:
				MMGroupBox3 = (MMGroupBox)target;
				break;
			case 33:
				MMLabelLogSPoint = (MMLabel)target;
				break;
			case 34:
				txtLogStartPoint = (MMVariableEdit)target;
				break;
			case 35:
				LogStartPointUnit = (MMComboEdit)target;
				break;
			case 36:
				MMLabelLogEPoint = (MMLabel)target;
				break;
			case 37:
				txtLogEndPoint = (MMVariableEdit)target;
				break;
			case 38:
				MMLabelLogNPoint = (MMLabel)target;
				break;
			case 39:
				LogEndPointUnit = (MMComboEdit)target;
				break;
			case 40:
				MMSpinBoxLogNPoint = (MMSpinBox)target;
				break;
			case 41:
				MMLabelFactor = (MMLabel)target;
				break;
			case 42:
				txFactor = (MMVariableEdit)target;
				break;
			case 43:
				Mlist_label = (MMLabel)target;
				break;
			case 44:
				ListValueUnit = (MMComboEdit)target;
				break;
			case 45:
				grdList = (MMScrollArea)target;
				break;
			case 46:
				Parametric_Var = (MMGroupBox)target;
				break;
			case 47:
				cboVariable_AdvCollection2_Comb = (MMComboEdit)target;
				break;
			case 48:
				cboVariable_Unit2_Comb = (MMComboEdit)target;
				break;
			case 49:
				Enterval_label = (MMLabel)target;
				break;
			case 50:
				grdList1 = (MMScrollArea)target;
				break;
			case 51:
				Enter_Var = (MMGroupBox)target;
				break;
			case 52:
				Fixedstate_label = (MMLabel)target;
				break;
			case 53:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 54:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 55:
				cmdRunAnalysis = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	public class MMAPr_Anal_Mix_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAPr_Anal_Mix_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Anal_Mix_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_Mixture
{
	[ProgId("MMAPr_Anal_Mix.MMAPr_Anal_Mix_Out")]
	public class MMAPr_Anal_Mix_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabGeneralResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAPr_Anal_Mix_Out()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Mix_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_mixture/mmapr_anal_mix_out.xaml", UriKind.Relative);
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
				tabGeneralResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAnalysis_Gen_DBVari")]
	public class MMAnalysis_Gen_DBVari : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMOptionGroup OptionVarvalue;

		internal MMOptionButton OptionVarvalue_opt0;

		internal MMOptionButton OptionVarvalue_opt1;

		internal MMScrollAreaMS grdList;

		internal MMGroupBox MMFrame2;

		internal MMOptionGroup optTpointsIncr;

		internal MMOptionButton optTpointsIncr_opt0;

		internal MMSpinBox spnTNPOINT;

		internal MMOptionButton optTpointsIncr_opt1;

		internal MMValueEdit txtTIncr;

		internal MMLabel txtLower_label;

		internal MMVariableEdit txtLower;

		internal MMLabel txtUpper_label;

		internal MMVariableEdit txtUpper;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMAnalysis_Gen_DBVari()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_DBVari_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmanalysis_gen_dbvari.xaml", UriKind.Relative);
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
				OptionVarvalue = (MMOptionGroup)target;
				break;
			case 3:
				OptionVarvalue_opt0 = (MMOptionButton)target;
				break;
			case 4:
				OptionVarvalue_opt1 = (MMOptionButton)target;
				break;
			case 5:
				grdList = (MMScrollAreaMS)target;
				break;
			case 6:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 7:
				optTpointsIncr = (MMOptionGroup)target;
				break;
			case 8:
				optTpointsIncr_opt0 = (MMOptionButton)target;
				break;
			case 9:
				spnTNPOINT = (MMSpinBox)target;
				break;
			case 10:
				optTpointsIncr_opt1 = (MMOptionButton)target;
				break;
			case 11:
				txtTIncr = (MMValueEdit)target;
				break;
			case 12:
				txtLower_label = (MMLabel)target;
				break;
			case 13:
				txtLower = (MMVariableEdit)target;
				break;
			case 14:
				txtUpper_label = (MMLabel)target;
				break;
			case 15:
				txtUpper = (MMVariableEdit)target;
				break;
			case 16:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	public class MMAnalysis_Gen_In_Diag_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration sldProperty_var1_Property = CxvPropertyDeclaration.Register("sldProperty_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_LEVEL"
		});

		public static readonly CxvPropertyDeclaration sldSimulation_var1_Property = CxvPropertyDeclaration.Register("sldSimulation_var1", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SIM_LEVEL"
		});

		public static readonly CxvPropertyDeclaration Simulation_Property = CxvPropertyDeclaration.Register("Simulation", typeof(MMAnalysis_Gen_In_Diag_ViewModel), new CxvParameterProperty
		{
			Parameter = "SimulationLabel"
		});

		public object sldProperty_var1 => GetValue(sldProperty_var1_Property);

		public object sldSimulation_var1 => GetValue(sldSimulation_var1_Property);

		public object Simulation => GetValue(Simulation_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Calculation);
				}
				else
				{
					ResolveUpdateParameter("SimulationLabel", AspenTech.AspenPlus.Localization.Properties.Resources.MMAnalysis_Gen_In_Diag_ViewModel__SimulationLabel_Simulation);
				}
			}
			base.OnUpdateData();
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAnalysis_Gen_In_Diag")]
	public class MMAnalysis_Gen_In_Diag : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDiag;

		internal MMLabel lblTermErr;

		internal MMLabel lblFullDiag;

		internal MMLabel lblup0;

		internal MMLabel lblup4;

		internal MMLabel lblup10;

		internal MMLabel lblSimulation;

		internal MMSlider sldSimulation;

		internal MMLabel lblProperty;

		internal MMSlider sldProperty;

		internal MMLabel lbldown0;

		internal MMLabel lbldown4;

		internal MMLabel lbldown10;

		private bool _contentLoaded;

		public MMAnalysis_Gen_In_Diag()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_In_Diag_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmanalysis_gen_in_diag.xaml", UriKind.Relative);
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
				lblTermErr = (MMLabel)target;
				break;
			case 3:
				lblFullDiag = (MMLabel)target;
				break;
			case 4:
				lblup0 = (MMLabel)target;
				break;
			case 5:
				lblup4 = (MMLabel)target;
				break;
			case 6:
				lblup10 = (MMLabel)target;
				break;
			case 7:
				lblSimulation = (MMLabel)target;
				break;
			case 8:
				sldSimulation = (MMSlider)target;
				break;
			case 9:
				lblProperty = (MMLabel)target;
				break;
			case 10:
				sldProperty = (MMSlider)target;
				break;
			case 11:
				lbldown0 = (MMLabel)target;
				break;
			case 12:
				lbldown4 = (MMLabel)target;
				break;
			case 13:
				lbldown10 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	public class MMAnalysis_Gen_Out_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAnalysis_Gen_Out_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAnalysis_Gen_Out_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object accres => GetValue(accres_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAPr_Anal_Gen_Out")]
	public class MMAnalysis_Gen_Out : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabGeneralResults;

		internal MMTabItem tab0;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAnalysis_Gen_Out()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_Out_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmanalysis_gen_out.xaml", UriKind.Relative);
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
				tabGeneralResults = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAnalysis_Gen_Out_Resul")]
	public class MMAnalysis_Gen_Out_Resul : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraResults;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAnalysis_Gen_Out_Resul()
		{
			base.ViewModelType = typeof(MMAnalysis_Gen_Out_Resul_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmanalysis_gen_out_resul.xaml", UriKind.Relative);
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
				fraResults = (MMGroupBox)target;
				break;
			case 2:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	public class MMAPr_Anal_Gen_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration sys_Property = CxvPropertyDeclaration.Register("sys", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.STRM"
		});

		public static readonly CxvPropertyDeclaration vary_Property = CxvPropertyDeclaration.Register("vary", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.COMPVARY"
		});

		public static readonly CxvPropertyDeclaration tabu_Property = CxvPropertyDeclaration.Register("tabu", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.TABU"
		});

		public static readonly CxvPropertyDeclaration nphase_Property = CxvPropertyDeclaration.Register("nphase", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NPHASE"
		});

		public static readonly CxvPropertyDeclaration proper_Property = CxvPropertyDeclaration.Register("proper", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration accres_Property = CxvPropertyDeclaration.Register("accres", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.Prop Data.PROPTAB"
		});

		public static readonly CxvPropertyDeclaration entprop_Property = CxvPropertyDeclaration.Register("entprop", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPROP"
		});

		public static readonly CxvPropertyDeclaration entdiag_Property = CxvPropertyDeclaration.Register("entdiag", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIAG"
		});

		public static readonly CxvPropertyDeclaration row_Property = CxvPropertyDeclaration.Register("row", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvParameterProperty
		{
			Parameter = "row"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sys", "@nphase" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@vary" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@tabu" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@proper", "@nphase" },
			EnteredDataPaths = { "@entprop" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdiag" }
		});

		public static readonly CxvPropertyDeclaration tab6_var_Property = CxvPropertyDeclaration.Register("tab6_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public static readonly CxvPropertyDeclaration status_var_Property = CxvPropertyDeclaration.Register("status_var", typeof(MMAPr_Anal_Gen_In_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@accres" }
		});

		public object choice => GetValue(choice_Property);

		public object sys => GetValue(sys_Property);

		public object vary => GetValue(vary_Property);

		public object tabu => GetValue(tabu_Property);

		public object nphase => GetValue(nphase_Property);

		public object proper => GetValue(proper_Property);

		public object accres => GetValue(accres_Property);

		public object entprop => GetValue(entprop_Property);

		public object entdiag => GetValue(entdiag_Property);

		public object row => GetValue(row_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab6_var => GetValue(tab6_var_Property);

		public object status_var => GetValue(status_var_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAPr_Anal_Gen_In")]
	public class MMAPr_Anal_Gen_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAnalysisBinary;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab6;

		internal MMTabItem tabInfo;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAPr_Anal_Gen_In()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Gen_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmapr_anal_gen_in.xaml", UriKind.Relative);
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
				tabAnalysisBinary = (MMTabStrip)target;
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
				tab6 = (MMTabItem)target;
				break;
			case 8:
				tabInfo = (MMTabItem)target;
				break;
			case 9:
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAPr_Anal_Gen_In_System")]
	public class MMAPr_Anal_Gen_In_System : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInformation;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel3;

		internal MMLabel MMLabel5;

		internal MMGroupBox fraGenerate;

		internal MMOptionGroup optNumberOfCurves;

		internal MMOptionButton optNumberOfCurves_opt0;

		internal MMOptionButton optNumberOfCurves_opt1;

		internal MMGroupBox fraValidPhases;

		internal MMLabel MMLabel_5_label;

		internal MMComboEdit cboValidPhases;

		internal MMLabel spnMaximumIterations_label;

		internal MMSpinBox spnMaximumIterations;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		internal MMLabel cboFlashMethod_label;

		internal MMComboEdit cboFlashMethod;

		internal MMCheckBox chkRestart;

		internal MMGroupBox fraSystem;

		internal MMVariableEdit lbtuBasisOfFlow;

		internal MMScrollArea grdSystem;

		private bool _contentLoaded;

		public MMAPr_Anal_Gen_In_System()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Gen_In_System_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmapr_anal_gen_in_system.xaml", UriKind.Relative);
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
				fraInformation = (MMGroupBox)target;
				break;
			case 2:
				MMLabel2 = (MMLabel)target;
				break;
			case 3:
				MMLabel3 = (MMLabel)target;
				break;
			case 4:
				MMLabel5 = (MMLabel)target;
				break;
			case 5:
				fraGenerate = (MMGroupBox)target;
				break;
			case 6:
				optNumberOfCurves = (MMOptionGroup)target;
				break;
			case 7:
				optNumberOfCurves_opt0 = (MMOptionButton)target;
				break;
			case 8:
				optNumberOfCurves_opt1 = (MMOptionButton)target;
				break;
			case 9:
				fraValidPhases = (MMGroupBox)target;
				break;
			case 10:
				MMLabel_5_label = (MMLabel)target;
				break;
			case 11:
				cboValidPhases = (MMComboEdit)target;
				break;
			case 12:
				spnMaximumIterations_label = (MMLabel)target;
				break;
			case 13:
				spnMaximumIterations = (MMSpinBox)target;
				break;
			case 14:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 15:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			case 16:
				cboFlashMethod_label = (MMLabel)target;
				break;
			case 17:
				cboFlashMethod = (MMComboEdit)target;
				break;
			case 18:
				chkRestart = (MMCheckBox)target;
				break;
			case 19:
				fraSystem = (MMGroupBox)target;
				break;
			case 20:
				lbtuBasisOfFlow = (MMVariableEdit)target;
				break;
			case 21:
				grdSystem = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Analysis.APr_General
{
	[ProgId("MMAPr_Anal_Gen.MMAPr_Anal_Gen_In_Vari")]
	public class MMAPr_Anal_Gen_In_Vari : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraFixedStateVariable;

		internal MMComboEdit spcSpec1_combo;

		internal MMVariableEdit spcSpec1;

		internal MMComboEdit spcSpec2_combo;

		internal MMVariableEdit spcSpec2;

		internal MMGroupBox fraAdjustedVariables;

		internal MMScrollArea grdVariables;

		internal MMCmdButton cmdRangeList;

		private bool _contentLoaded;

		public MMAPr_Anal_Gen_In_Vari()
		{
			base.ViewModelType = typeof(MMAPr_Anal_Gen_In_Vari_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/analysis/apr_general/mmapr_anal_gen_in_vari.xaml", UriKind.Relative);
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
				fraFixedStateVariable = (MMGroupBox)target;
				break;
			case 2:
				spcSpec1_combo = (MMComboEdit)target;
				break;
			case 3:
				spcSpec1 = (MMVariableEdit)target;
				break;
			case 4:
				spcSpec2_combo = (MMComboEdit)target;
				break;
			case 5:
				spcSpec2 = (MMVariableEdit)target;
				break;
			case 6:
				fraAdjustedVariables = (MMGroupBox)target;
				break;
			case 7:
				grdVariables = (MMScrollArea)target;
				break;
			case 8:
				cmdRangeList = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Props
{
	public class MMUserParameter_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMUserParameter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MMUserParameter_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSELE"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMUserParameter_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global" },
			EnteredDataPaths = { "@entsele" }
		});

		public object global => GetValue(global_Property);

		public object entsele => GetValue(entsele_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Props
{
	[ProgId("MMUserParameter.MMUserParameter_In")]
	public class MMUserParameter_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMUserParameter_In()
		{
			base.ViewModelType = typeof(MMUserParameter_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/user-props/mmuserparameter_in.xaml", UriKind.Relative);
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Props
{
	[ProgId("MMUserParameter.MMUserParameter_In_Para")]
	public class MMUserParameter_In_Para : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraUserParametersUsedinUserPropertyModels;

		internal MMScrollArea grdUserParametersUsedInUserPropertyModels;

		internal MMCheckBox chkSysAllowed;

		private bool _contentLoaded;

		public MMUserParameter_In_Para()
		{
			base.ViewModelType = typeof(MMUserParameter_In_Para_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/user-props/mmuserparameter_in_para.xaml", UriKind.Relative);
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
				fraUserParametersUsedinUserPropertyModels = (MMGroupBox)target;
				break;
			case 2:
				grdUserParametersUsedInUserPropertyModels = (MMScrollArea)target;
				break;
			case 3:
				chkSysAllowed = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Property
{
	public class MMUserProperty_In_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMUserProperty_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration units_Property = CxvPropertyDeclaration.Register("units", typeof(MMUserProperty_In_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTUNITS"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMUserProperty_In_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMUserProperty_In_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@units" }
		});

		public object spec => GetValue(spec_Property);

		public object units => GetValue(units_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Property
{
	[ProgId("MMUserProperty.MMUserProperty_In")]
	public class MMUserProperty_In : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMUserProperty_In()
		{
			base.ViewModelType = typeof(MMUserProperty_In_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/user-property/mmuserproperty_in.xaml", UriKind.Relative);
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Property
{
	[ProgId("MMUserProperty.MMUserProperty_In_Spec")]
	public class MMUserProperty_In_Spec : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup optProperty;

		internal MMOptionButton optProperty_opt0;

		internal MMOptionButton optProperty_opt1;

		internal MMOptionGroup optBlendingMethod;

		internal MMOptionButton optBlendingMethod_opt0;

		internal MMOptionButton optBlendingMethod_opt1;

		internal MMOptionButton optBlendingMethod_opt2;

		internal MMOptionButton optBlendingMethod_opt3;

		internal MMLabel spnBlendingOption_label;

		internal MMSpinBox spnBlendingOption;

		internal MMLabel cboDefaultPropertyUsedForLightEnds_label;

		internal MMComboEdit cboDefaultPropertyUsedForLightEnds;

		internal MMCheckBox MMCheckBox2;

		internal MMLabel lbtuUserSubroutineName_label;

		internal MMVariableEdit lbtuUserSubroutineName;

		internal MMOptionGroup optStreamFlashCalculations;

		internal MMOptionButton optStreamFlashCalculations_opt0;

		internal MMOptionButton optStreamFlashCalculations_opt1;

		internal MMOptionButton optStreamFlashCalculations_opt2;

		internal MMOptionGroup optPropertyType;

		internal MMOptionButton optPropertyType_opt0;

		internal MMCheckBox chkUseLiquidVolumePercent;

		internal MMOptionButton optPropertyType_opt1;

		private bool _contentLoaded;

		public MMUserProperty_In_Spec()
		{
			base.ViewModelType = typeof(MMUserProperty_In_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/user-property/mmuserproperty_in_spec.xaml", UriKind.Relative);
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
				optProperty = (MMOptionGroup)target;
				break;
			case 2:
				optProperty_opt0 = (MMOptionButton)target;
				break;
			case 3:
				optProperty_opt1 = (MMOptionButton)target;
				break;
			case 4:
				optBlendingMethod = (MMOptionGroup)target;
				break;
			case 5:
				optBlendingMethod_opt0 = (MMOptionButton)target;
				break;
			case 6:
				optBlendingMethod_opt1 = (MMOptionButton)target;
				break;
			case 7:
				optBlendingMethod_opt2 = (MMOptionButton)target;
				break;
			case 8:
				optBlendingMethod_opt3 = (MMOptionButton)target;
				break;
			case 9:
				spnBlendingOption_label = (MMLabel)target;
				break;
			case 10:
				spnBlendingOption = (MMSpinBox)target;
				break;
			case 11:
				cboDefaultPropertyUsedForLightEnds_label = (MMLabel)target;
				break;
			case 12:
				cboDefaultPropertyUsedForLightEnds = (MMComboEdit)target;
				break;
			case 13:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 14:
				lbtuUserSubroutineName_label = (MMLabel)target;
				break;
			case 15:
				lbtuUserSubroutineName = (MMVariableEdit)target;
				break;
			case 16:
				optStreamFlashCalculations = (MMOptionGroup)target;
				break;
			case 17:
				optStreamFlashCalculations_opt0 = (MMOptionButton)target;
				break;
			case 18:
				optStreamFlashCalculations_opt1 = (MMOptionButton)target;
				break;
			case 19:
				optStreamFlashCalculations_opt2 = (MMOptionButton)target;
				break;
			case 20:
				optPropertyType = (MMOptionGroup)target;
				break;
			case 21:
				optPropertyType_opt0 = (MMOptionButton)target;
				break;
			case 22:
				chkUseLiquidVolumePercent = (MMCheckBox)target;
				break;
			case 23:
				optPropertyType_opt1 = (MMOptionButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Property
{
	public class MMUserProperty_In_Units_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration optUnits_MultiMap_Property = CxvPropertyDeclaration.Register("optUnits_MultiMap", typeof(MMUserProperty_In_Units_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "optUnits_optunits",
					DataPath = "@main.Input.OPT_UNIT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Units conversion performed by Aspen Plus",
					DisplayResourceKey = "MMUserProperty_In_Units_ViewModel__CxvMultiMapOption_Display_Units_conversion_performed_by_Aspen_Plu",
					Value = "optUnits_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optUnits_optunits",
							Value = "TYPE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Units conversion performed by user subroutine",
					DisplayResourceKey = "MMUserProperty_In_Units_ViewModel__CxvMultiMapOption_Display_Units_conversion_performed_by_user_subr",
					Value = "optUnits_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optUnits_optunits",
							Value = "LABEL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboUnitsType_var1_Property = CxvPropertyDeclaration.Register("cboUnitsType_var1", typeof(MMUserProperty_In_Units_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.UNIT_TYPE",
			Sorted = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTTYPE"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuUnitsLabel_var1_Property = CxvPropertyDeclaration.Register("lbtuUnitsLabel_var1", typeof(MMUserProperty_In_Units_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UNIT_LABEL",
			DisplayedCase = CxsDisplayedCase.Uppercase,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTLABEL"
			}
		});

		public static CxvPropertyDeclaration UnitTypeTitle_Property = CxvPropertyDeclaration.Register("UnitTypeTitle", typeof(MMUserProperty_In_Units_ViewModel), new CxvParameterProperty
		{
			Parameter = "UnitTypeTitle",
			Value = "Units conversion performed by Aspen Plus"
		});

		public object optUnits_MultiMap => GetValue(optUnits_MultiMap_Property);

		public object cboUnitsType_var1 => GetValue(cboUnitsType_var1_Property);

		public object lbtuUnitsLabel_var1 => GetValue(lbtuUnitsLabel_var1_Property);

		public object UnitTypeTitle => GetValue(UnitTypeTitle_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("UnitTypeTitle", AspenTech.AspenPlus.Localization.Properties.Resources.MMUserProperty_In_Units_ViewModel__CxvMultiMapOption_Display_Units_Convers_Apsen_Properties);
				}
				else
				{
					ResolveUpdateParameter("UnitTypeTitle", AspenTech.AspenPlus.Localization.Properties.Resources.MMUserProperty_In_Units_ViewModel__CxvMultiMapOption_Display_Units_conversion_performed_by_Aspen_Plu);
				}
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.User_Property
{
	[ProgId("MMUserProperty.MMUserProperty_In_Units")]
	public class MMUserProperty_In_Units : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup optUnits;

		internal MMOptionButton optUnits_opt0;

		internal MMLabel cboUnitsType_label;

		internal MMComboEdit cboUnitsType;

		internal MMOptionButton optUnits_opt1;

		internal MMLabel lbtuUnitsLabel_label;

		internal MMVariableEdit lbtuUnitsLabel;

		private bool _contentLoaded;

		public MMUserProperty_In_Units()
		{
			base.ViewModelType = typeof(MMUserProperty_In_Units_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/user-property/mmuserproperty_in_units.xaml", UriKind.Relative);
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
				optUnits = (MMOptionGroup)target;
				break;
			case 2:
				optUnits_opt0 = (MMOptionButton)target;
				break;
			case 3:
				cboUnitsType_label = (MMLabel)target;
				break;
			case 4:
				cboUnitsType = (MMComboEdit)target;
				break;
			case 5:
				optUnits_opt1 = (MMOptionButton)target;
				break;
			case 6:
				lbtuUnitsLabel_label = (MMLabel)target;
				break;
			case 7:
				lbtuUnitsLabel = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	public class MMAdv_Tabp_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMAdv_Tabp_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration reference_Property = CxvPropertyDeclaration.Register("reference", typeof(MMAdv_Tabp_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "reference"
		});

		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMAdv_Tabp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entref_Property = CxvPropertyDeclaration.Register("entref", typeof(MMAdv_Tabp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTREF"
		});

		public static readonly CxvPropertyDeclaration data_Property = CxvPropertyDeclaration.Register("data", typeof(MMAdv_Tabp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DATA"
		});

		public static readonly CxvPropertyDeclaration _ref_Property = CxvPropertyDeclaration.Register("_ref", typeof(MMAdv_Tabp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.REF"
		});

		public static readonly CxvPropertyDeclaration entdata_Property = CxvPropertyDeclaration.Register("entdata", typeof(MMAdv_Tabp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDATA"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAdv_Tabp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAdv_Tabp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@data" },
			EnteredDataPaths = { "@entdata" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAdv_Tabp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@_ref" },
			EnteredDataPaths = { "@entref" }
		});

		public object choice => GetValue(choice_Property);

		public object reference => GetValue(reference_Property);

		public object spec => GetValue(spec_Property);

		public object entref => GetValue(entref_Property);

		public object data => GetValue(data_Property);

		public object _ref => GetValue(_ref_Property);

		public object entdata => GetValue(entdata_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	[ProgId("MMAdv_Tabp.MMAdv_Tabp_Input")]
	public class MMAdv_Tabp_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabAdvancedTabPoly;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMAdv_Tabp_Input()
		{
			base.ViewModelType = typeof(MMAdv_Tabp_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/tabpoly/mmadv_tabp_input.xaml", UriKind.Relative);
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
				tabAdvancedTabPoly = (MMTabStrip)target;
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	[ProgId("MMAdv_Tabp.MMAdv_Tabp_Input_Data")]
	public class MMAdv_Tabp_Input_Data : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuComponent_label;

		internal MMAdvancedComboEdit mnuComponent;

		internal MMOptionGroup optTabPol;

		internal MMOptionButton optTabPol_opt0;

		internal MMOptionButton optTabPol_opt1;

		internal MMGroupBox fraTabularData;

		internal MMScrollAreaMS grdTabularData;

		internal MMGroupBox fraPolynomialCoefficients;

		internal MMScrollAreaManualLayout grdPolynomialCoefficients;

		private bool _contentLoaded;

		public MMAdv_Tabp_Input_Data()
		{
			base.ViewModelType = typeof(MMAdv_Tabp_Input_Data_ViewModel);
			InitializeComponent();
		}

		private void optTabPol_opt1_Checked(object sender, RoutedEventArgs e)
		{
			if (optTabPol_opt0.IsChecked == true)
			{
				fraTabularData.Visibility = Visibility.Visible;
				fraPolynomialCoefficients.Visibility = Visibility.Hidden;
			}
			else if (optTabPol_opt1.IsChecked == true)
			{
				fraTabularData.Visibility = Visibility.Hidden;
				fraPolynomialCoefficients.Visibility = Visibility.Visible;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/tabpoly/mmadv_tabp_input_data.xaml", UriKind.Relative);
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
				mnuComponent_label = (MMLabel)target;
				break;
			case 2:
				mnuComponent = (MMAdvancedComboEdit)target;
				break;
			case 3:
				optTabPol = (MMOptionGroup)target;
				break;
			case 4:
				optTabPol_opt0 = (MMOptionButton)target;
				optTabPol_opt0.Checked += optTabPol_opt1_Checked;
				break;
			case 5:
				optTabPol_opt1 = (MMOptionButton)target;
				optTabPol_opt1.Checked += optTabPol_opt1_Checked;
				break;
			case 6:
				fraTabularData = (MMGroupBox)target;
				break;
			case 7:
				grdTabularData = (MMScrollAreaMS)target;
				break;
			case 8:
				fraPolynomialCoefficients = (MMGroupBox)target;
				break;
			case 9:
				grdPolynomialCoefficients = (MMScrollAreaManualLayout)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	public class MMAdv_Tabp_Input_Ref_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraReferencePoints_state_Property = CxvPropertyDeclaration.Register("fraReferencePoints_state", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "reference",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration txtPressure_refPressure_Property = CxvPropertyDeclaration.Register("txtPressure_refPressure", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REF_P.@reference"
		});

		public static readonly CxvPropertyDeclaration txtGibbsFreeEnergy_var1_Property = CxvPropertyDeclaration.Register("txtGibbsFreeEnergy_var1", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REF_G.@reference"
		});

		public static readonly CxvPropertyDeclaration txtEntropy_var1_Property = CxvPropertyDeclaration.Register("txtEntropy_var1", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REF_S.@reference"
		});

		public static readonly CxvPropertyDeclaration txtEnthalpy_var1_Property = CxvPropertyDeclaration.Register("txtEnthalpy_var1", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REF_H.@reference"
		});

		public static readonly CxvPropertyDeclaration txtTemperature_var1_Property = CxvPropertyDeclaration.Register("txtTemperature_var1", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.REF_T.@reference"
		});

		public static readonly CxvPropertyDeclaration mnuComponentID_var2_Property = CxvPropertyDeclaration.Register("mnuComponentID_var2", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvParameterProperty
		{
			Parameter = "reference"
		});

		public static readonly CxvPropertyDeclaration mnuComponentID_var1_Property = CxvPropertyDeclaration.Register("mnuComponentID_var1", typeof(MMAdv_Tabp_Input_Ref_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.REF_T",
			SelectedItemBinding = "mnuComponentID_var2.Value",
			CreateNewPrompt = "Component:",
			CreateNewPromptResourceKey = "MMAdv_Tabp_Input_Ref_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_"
		});

		public object fraReferencePoints_state => GetValue(fraReferencePoints_state_Property);

		public object txtPressure_refPressure => GetValue(txtPressure_refPressure_Property);

		public object txtGibbsFreeEnergy_var1 => GetValue(txtGibbsFreeEnergy_var1_Property);

		public object txtEntropy_var1 => GetValue(txtEntropy_var1_Property);

		public object txtEnthalpy_var1 => GetValue(txtEnthalpy_var1_Property);

		public object txtTemperature_var1 => GetValue(txtTemperature_var1_Property);

		public object mnuComponentID_var2 => GetValue(mnuComponentID_var2_Property);

		public object mnuComponentID_var1 => GetValue(mnuComponentID_var1_Property);
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	[ProgId("MMAdv_Tabp.MMAdv_Tabp_Input_Ref")]
	public class MMAdv_Tabp_Input_Ref : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuComponentID_label;

		internal MMAdvancedComboEdit mnuComponentID;

		internal MMGroupBox fraReferencePoints;

		internal MMLabel lblTemperature;

		internal MMValueEdit txtTemperature;

		internal MMLabel lblEnthalpy;

		internal MMValueEdit txtEnthalpy;

		internal MMLabel lblEntropy;

		internal MMValueEdit txtEntropy;

		internal MMLabel lblGibbsFreeEnergy;

		internal MMValueEdit txtGibbsFreeEnergy;

		internal MMLabel lblPressure;

		internal MMValueEdit txtPressure;

		private bool _contentLoaded;

		public MMAdv_Tabp_Input_Ref()
		{
			base.ViewModelType = typeof(MMAdv_Tabp_Input_Ref_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/tabpoly/mmadv_tabp_input_ref.xaml", UriKind.Relative);
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
				mnuComponentID_label = (MMLabel)target;
				break;
			case 2:
				mnuComponentID = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraReferencePoints = (MMGroupBox)target;
				break;
			case 4:
				lblTemperature = (MMLabel)target;
				break;
			case 5:
				txtTemperature = (MMValueEdit)target;
				break;
			case 6:
				lblEnthalpy = (MMLabel)target;
				break;
			case 7:
				txtEnthalpy = (MMValueEdit)target;
				break;
			case 8:
				lblEntropy = (MMLabel)target;
				break;
			case 9:
				txtEntropy = (MMValueEdit)target;
				break;
			case 10:
				lblGibbsFreeEnergy = (MMLabel)target;
				break;
			case 11:
				txtGibbsFreeEnergy = (MMValueEdit)target;
				break;
			case 12:
				lblPressure = (MMLabel)target;
				break;
			case 13:
				txtPressure = (MMValueEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Tabpoly
{
	[ProgId("MMAdv_Tabp.MMAdv_Tabp_Input_Spec")]
	public class MMAdv_Tabp_Input_Spec : MMTabPage, IComponentConnector
	{
		internal MMLabel lblProperty;

		internal MMComboEdit cboPropertyName;

		internal MMLabel lblForPropertyMethod;

		internal MMHorizontalListEdit grdMethodToModify;

		internal MMGroupBox fraTabularData;

		internal MMLabel lblTabularBasis;

		internal MMComboEdit cboTabularBasis;

		internal MMCheckBox MMCheckBox1;

		internal MMGroupBox fraPolynomialData;

		internal MMLabel lblBasis;

		internal MMComboEdit cboPolynomialBasis;

		internal MMCheckBox MMCheckBox2;

		internal MMOptionGroup optDataGeneration;

		internal MMOptionButton optDataGeneration_opt0;

		internal MMOptionButton optDataGeneration_opt1;

		internal MMOptionButton optDataGeneration_opt2;

		internal MMOptionButton optDataGeneration_opt3;

		private bool _contentLoaded;

		public MMAdv_Tabp_Input_Spec()
		{
			base.ViewModelType = typeof(MMAdv_Tabp_Input_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/tabpoly/mmadv_tabp_input_spec.xaml", UriKind.Relative);
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
				lblProperty = (MMLabel)target;
				break;
			case 2:
				cboPropertyName = (MMComboEdit)target;
				break;
			case 3:
				lblForPropertyMethod = (MMLabel)target;
				break;
			case 4:
				grdMethodToModify = (MMHorizontalListEdit)target;
				break;
			case 5:
				fraTabularData = (MMGroupBox)target;
				break;
			case 6:
				lblTabularBasis = (MMLabel)target;
				break;
			case 7:
				cboTabularBasis = (MMComboEdit)target;
				break;
			case 8:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 9:
				fraPolynomialData = (MMGroupBox)target;
				break;
			case 10:
				lblBasis = (MMLabel)target;
				break;
			case 11:
				cboPolynomialBasis = (MMComboEdit)target;
				break;
			case 12:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 13:
				optDataGeneration = (MMOptionGroup)target;
				break;
			case 14:
				optDataGeneration_opt0 = (MMOptionButton)target;
				break;
			case 15:
				optDataGeneration_opt1 = (MMOptionButton)target;
				break;
			case 16:
				optDataGeneration_opt2 = (MMOptionButton)target;
				break;
			case 17:
				optDataGeneration_opt3 = (MMOptionButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Route
{
	public class MMRoutes_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration route_Property = CxvPropertyDeclaration.Register("route", typeof(MMRoutes_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMRoutes_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@route" }
		});

		public object route => GetValue(route_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Route
{
	[ProgId("MMRoutes.MMRoutes_Input")]
	public class MMRoutes_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabRoutes;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMRoutes_Input()
		{
			base.ViewModelType = typeof(MMRoutes_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/route/mmroutes_input.xaml", UriKind.Relative);
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
				tabRoutes = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Route
{
	[ProgId("MMRoutes.MMRoutes_Input_Routes")]
	public class MMRoutes_Input_Routes : MMTabPage, IComponentConnector
	{
		internal MMLabel cboMType_label;

		internal MMComboEdit cboMType;

		internal MMLabel cboMethodCode_label;

		internal MMComboEdit cboMethodCode;

		internal MMLabel cboSelectProperty_Name_label;

		internal MMComboEdit cboSelectProperty_Name;

		internal MMLabel cboCopyRouteFrom_label;

		internal MMComboEdit cboCopyRouteFrom;

		internal MMGroupBox fraSpecifyRequiredRoutesAndModels;

		internal MMScrollArea grdSelection;

		internal MMCmdButton cmdViewTree;

		internal MMScrollArea grdModels;

		internal MMCmdButton cmdOptionCodes;

		internal MMLabel labDummy2;

		private bool _contentLoaded;

		public MMRoutes_Input_Routes()
		{
			base.ViewModelType = typeof(MMRoutes_Input_Routes_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/route/mmroutes_input_routes.xaml", UriKind.Relative);
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
				cboMType_label = (MMLabel)target;
				break;
			case 2:
				cboMType = (MMComboEdit)target;
				break;
			case 3:
				cboMethodCode_label = (MMLabel)target;
				break;
			case 4:
				cboMethodCode = (MMComboEdit)target;
				break;
			case 5:
				cboSelectProperty_Name_label = (MMLabel)target;
				break;
			case 6:
				cboSelectProperty_Name = (MMComboEdit)target;
				break;
			case 7:
				cboCopyRouteFrom_label = (MMLabel)target;
				break;
			case 8:
				cboCopyRouteFrom = (MMComboEdit)target;
				break;
			case 9:
				fraSpecifyRequiredRoutesAndModels = (MMGroupBox)target;
				break;
			case 10:
				grdSelection = (MMScrollArea)target;
				break;
			case 11:
				cmdViewTree = (MMCmdButton)target;
				break;
			case 12:
				grdModels = (MMScrollArea)target;
				break;
			case 13:
				cmdOptionCodes = (MMCmdButton)target;
				break;
			case 14:
				labDummy2 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.Route
{
	[ProgId("MMRoutes.MMRoutes_OptCodeDB")]
	public class MMRoutes_OptCodeDB : MMTabPage, IComponentConnector
	{
		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMGroupBox fraOptionCodes;

		internal MMScrollAreaHorizontal MMScrollArea1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMRoutes_OptCodeDB()
		{
			base.ViewModelType = typeof(MMRoutes_OptCodeDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/route/mmroutes_optcodedb.xaml", UriKind.Relative);
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
				fraOptionCodes = (MMGroupBox)target;
				break;
			case 4:
				MMScrollArea1 = (MMScrollAreaHorizontal)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.NC_Props
{
	public class MMNCProps_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMNCProps_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration prop_Property = CxvPropertyDeclaration.Register("prop", typeof(MMNCProps_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entmain_Property = CxvPropertyDeclaration.Register("entmain", typeof(MMNCProps_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTMAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMNCProps_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@prop" },
			EnteredDataPaths = { "@entmain" }
		});

		public object choice => GetValue(choice_Property);

		public object prop => GetValue(prop_Property);

		public object entmain => GetValue(entmain_Property);

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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.NC_Props
{
	[ProgId("MMNCProps.MMNCProps_Input")]
	public class MMNCProps_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabNCProperty;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMNCProps_Input()
		{
			base.ViewModelType = typeof(MMNCProps_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/nc-props/mmncprops_input.xaml", UriKind.Relative);
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
				tabNCProperty = (MMTabStrip)target;
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
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.NC_Props
{
	[ProgId("MMNCProps.MMNCProps_Input_Meth")]
	public class MMNCProps_Input_Meth : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuComponent_label;

		internal MMAdvancedComboEdit mnuComponent;

		internal MMGroupBox fraPropertyModels;

		internal MMLabel lblModelName;

		internal MMLabel lblOptionCodeValue;

		internal MMScrollAreaHorizontal grdPropertyModels;

		internal MMGroupBox fraRequiredComponentAttributes;

		internal MMHorizontalListEdit grdRequiredComponentAttributes;

		private bool _contentLoaded;

		public MMNCProps_Input_Meth()
		{
			base.ViewModelType = typeof(MMNCProps_Input_Meth_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/nc-props/mmncprops_input_meth.xaml", UriKind.Relative);
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
				mnuComponent_label = (MMLabel)target;
				break;
			case 2:
				mnuComponent = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraPropertyModels = (MMGroupBox)target;
				break;
			case 4:
				lblModelName = (MMLabel)target;
				break;
			case 5:
				lblOptionCodeValue = (MMLabel)target;
				break;
			case 6:
				grdPropertyModels = (MMScrollAreaHorizontal)target;
				break;
			case 7:
				fraRequiredComponentAttributes = (MMGroupBox)target;
				break;
			case 8:
				grdRequiredComponentAttributes = (MMHorizontalListEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

namespace AspenTech.AspenPlus.MMForms.PhysicalProperties.Advanced.NC_Props
{
	[ProgId("MMNCProps.MMNCProps_Input_MethDB")]
	public class MMNCProps_Input_MethDB : MMTabPage, IComponentConnector
	{
		internal MMLabel lblComp;

		internal MMTextEdit MMTextBox1;

		internal MMGroupBox fraPropertyModels;

		internal MMLabel lblModelName;

		internal MMLabel lblOptionCodeValue;

		internal MMScrollAreaHorizontal grdPropertyModels;

		internal MMGroupBox fraRequiredComponentAttributes;

		internal MMHorizontalListEdit grdRequiredComponentAttributes;

		private bool _contentLoaded;

		public MMNCProps_Input_MethDB()
		{
			base.ViewModelType = typeof(MMNCProps_Input_MethDB_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.PhysicalProperties;component/advanced/nc-props/mmncprops_input_methdb.xaml", UriKind.Relative);
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
				lblComp = (MMLabel)target;
				break;
			case 2:
				MMTextBox1 = (MMTextEdit)target;
				break;
			case 3:
				fraPropertyModels = (MMGroupBox)target;
				break;
			case 4:
				lblModelName = (MMLabel)target;
				break;
			case 5:
				lblOptionCodeValue = (MMLabel)target;
				break;
			case 6:
				grdPropertyModels = (MMScrollAreaHorizontal)target;
				break;
			case 7:
				fraRequiredComponentAttributes = (MMGroupBox)target;
				break;
			case 8:
				grdRequiredComponentAttributes = (MMHorizontalListEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
