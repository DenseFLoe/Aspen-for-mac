using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using AspenTech.APED;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.Engineering.GridControls;
using AspenTech.Engineering.GridControls.EventArgs;
using AspenTech.Engineering.GridControls.Internal;
using AspenTech.Visualisation.CommonShell;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Components")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Components")]
[assembly: AssemblyCopyright("Copyright © Microsoft 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Pseudocomponents")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.AssayBlend")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Attr_Comps")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Attr_Scaling")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Comp_Groups")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Comp_Lists")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.HenryComponents")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.MoistureComponents")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Polymers")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.Specifications")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/components", "AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups")]
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
namespace AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups
{
	public class MMCompUni_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMCompUni_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GR"
		});

		public static readonly CxvPropertyDeclaration entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MMCompUni_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSELE"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompUni_Input_ViewModel), new CxvTabItemProperty
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
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMCompUni.MMCompUni_Input")]
	public class MMCompUni_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMCompUni_Input()
		{
			base.ViewModelType = typeof(MMCompUni_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/unifac-groups/mmcompuni_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMCompUni_Input_Group_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtGroupID_var1_Property = CxvPropertyDeclaration.Register("txtGroupID_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.GROUPNO.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration cboGroupNumber_var1_Property = CxvPropertyDeclaration.Register("cboGroupNumber_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.GROUPNO.@y",
				AllowNew = false,
				AllowEmptyOptions = true
			});

			public object txtGroupID_var1 => GetValue(txtGroupID_var1_Property);

			public object cboGroupNumber_var1 => GetValue(cboGroupNumber_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompUni_Input_Group_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.GROUPNO",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMCompUni.MMCompUni_Input_Group")]
	public class MMCompUni_Input_Group : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMCompUni_Input_Group()
		{
			base.ViewModelType = typeof(MMCompUni_Input_Group_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/unifac-groups/mmcompuni_input_group.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
namespace AspenTech.AspenPlus.MMForms.Components.Specifications
{
	public class MMComp_Spec_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@selection" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entpet" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entnc" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@compdb" },
			EnteredDataPaths = { "@entdb" }
		});

		public static readonly CxvPropertyDeclaration selection_Property = CxvPropertyDeclaration.Register("selection", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entpet_Property = CxvPropertyDeclaration.Register("entpet", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPET"
		});

		public static readonly CxvPropertyDeclaration entnc_Property = CxvPropertyDeclaration.Register("entnc", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTNC"
		});

		public static readonly CxvPropertyDeclaration entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Pure Databanks.CC Nodes.ENTDBANK"
		});

		public static readonly CxvPropertyDeclaration compdb_Property = CxvPropertyDeclaration.Register("compdb", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "Top.appModelV8.Pure Databanks.CC Nodes.COMPDBANK"
		});

		private string _tab3Header;

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object selection => GetValue(selection_Property);

		public object entpet => GetValue(entpet_Property);

		public object entnc => GetValue(entnc_Property);

		public object entdb => GetValue(entdb_Property);

		public object compdb => GetValue(compdb_Property);

		public string tab3Header
		{
			get
			{
				return _tab3Header;
			}
			set
			{
				_tab3Header = value;
				OnPropertyChanged("tab3Header");
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (this.GrInqdbProvider() == 0)
				{
					tab3Header = Resources.MMComp_Spec_Input_ViewModel__Tab3Header_SQL_Server_Database;
				}
				else if (this.GrInqdbProvider() == 1)
				{
					tab3Header = Resources.MMComp_Spec_Input_ViewModel__Tab3Header_PostgreSQL_Database;
				}
				else if (this.GrInqdbProvider() == 2)
				{
					tab3Header = Resources.MMComp_Spec_Input_ViewModel__Tab3Header_SQLite_Database;
				}
				else if (this.GrInqAped() == 1)
				{
					tab3Header = Resources.MMComp_Spec_Input_ViewModel__Tab3Header_Enterprise_Database;
				}
				else
				{
					tab3Header = Resources.MMComp_Spec_Input_ViewModel__Tab3Header_Databanks;
				}
				OnPropertyChanged("tab3Header");
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMComp_Spec.MMComp_Spec_Input")]
	public class MMComp_Spec_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabComponentSpec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMComp_Spec_Input()
		{
			base.ViewModelType = typeof(MMComp_Spec_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/specifications/mmcomp_spec_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMComp_Spec_Input_Databank_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMCheckRetrive_var1_Property = CxvPropertyDeclaration.Register("MMCheckRetrive_var1", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.@parent.@parent.Other Databanks.Input.AUTO_PARAM",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public static readonly CxvPropertyDeclaration LstpBinaryDataBank_filesymnam_Property = CxvPropertyDeclaration.Register("LstpBinaryDataBank_filesymnam", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.@parent.@parent.Other Databanks.Input.FILE_SYM_NAM",
			RestoreDefaultOnClear = true,
			SkipSemanticOnReorder = true
		});

		public static readonly CxvPropertyDeclaration lstpPureDataBanks_filesymnam_Property = CxvPropertyDeclaration.Register("lstpPureDataBanks_filesymnam", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.@parent.@parent.Pure Databanks.Input.FILE_SYM_NAM",
			RestoreDefaultOnClear = true,
			SkipSemanticOnReorder = true
		});

		private Visibility _checkRetriveVisibility;

		private Visibility _lstpBinaryDataBankVisibility;

		public object MMCheckRetrive_var1 => GetValue(MMCheckRetrive_var1_Property);

		public object LstpBinaryDataBank_filesymnam => GetValue(LstpBinaryDataBank_filesymnam_Property);

		public object lstpPureDataBanks_filesymnam => GetValue(lstpPureDataBanks_filesymnam_Property);

		public Visibility CheckRetriveVisibility
		{
			get
			{
				return _checkRetriveVisibility;
			}
			set
			{
				_checkRetriveVisibility = value;
				OnPropertyChanged("CheckRetriveVisibility");
			}
		}

		public Visibility LstpBinaryDataBankVisibility
		{
			get
			{
				return _lstpBinaryDataBankVisibility;
			}
			set
			{
				_lstpBinaryDataBankVisibility = value;
				OnPropertyChanged("LstpBinaryDataBankVisibility");
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (!base.IsInitialUpdate)
			{
				return;
			}
			int num = this.GrInqAped();
			int num2 = this.GrInqSysAutoParam();
			if (num == 0 || num2 == 1)
			{
				LstpBinaryDataBankVisibility = Visibility.Collapsed;
				if (num == 1)
				{
					CheckRetriveVisibility = Visibility.Visible;
				}
				else
				{
					CheckRetriveVisibility = Visibility.Collapsed;
				}
			}
			else
			{
				LstpBinaryDataBankVisibility = Visibility.Visible;
				CheckRetriveVisibility = Visibility.Visible;
			}
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			if (pd == MMCheckRetrive_var1_Property && subPropertyName == "Value" && this.GrInqAped() == 1)
			{
				CxvBooleanPropertyData cxvBooleanPropertyData = MMCheckRetrive_var1 as CxvBooleanPropertyData;
				LstpBinaryDataBankVisibility = ((cxvBooleanPropertyData.Value == true) ? Visibility.Collapsed : Visibility.Visible);
			}
			base.OnSubPropertyDataChanged(pd, subPropertyName);
		}
	}
	[ProgId("MMComp_Spec.MMComp_Spec_Input_Databank")]
	public class MMComp_Spec_Input_Databank : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpPureDataBanks;

		internal MMCheckBox MMCheckRetrive;

		internal MMListPicker LstpBinaryDataBank;

		private bool _contentLoaded;

		public MMComp_Spec_Input_Databank()
		{
			base.ViewModelType = typeof(MMComp_Spec_Input_Databank_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/specifications/mmcomp_spec_input_databank.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lstpPureDataBanks = (MMListPicker)target;
				break;
			case 2:
				MMCheckRetrive = (MMCheckBox)target;
				break;
			case 3:
				LstpBinaryDataBank = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMComp_Spec_Input_NonConven_ViewModel : MMTabPageViewModel
	{
		public class grdNonConventionalComponents_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtNonConventionalComponents_nonconv_Property = CxvPropertyDeclaration.Register("txtNonConventionalComponents_nonconv", typeof(grdNonConventionalComponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NONCONVID.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object txtNonConventionalComponents_nonconv => GetValue(txtNonConventionalComponents_nonconv_Property);
		}

		public static readonly CxvPropertyDeclaration grdNonConventionalComponents_GridData_Property = CxvPropertyDeclaration.Register("grdNonConventionalComponents_GridData", typeof(MMComp_Spec_Input_NonConven_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdNonConventionalComponents_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.NONCONVID",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdNonConventionalComponents_GridData => GetValue(grdNonConventionalComponents_GridData_Property);
	}
	[ProgId("MMComp_Spec.MMComp_Spec_Input_NonConven")]
	public class MMComp_Spec_Input_NonConven : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraNonConventionalComponents;

		internal MMScrollArea grdNonConventionalComponents;

		private bool _contentLoaded;

		public MMComp_Spec_Input_NonConven()
		{
			base.ViewModelType = typeof(MMComp_Spec_Input_NonConven_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/specifications/mmcomp_spec_input_nonconven.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraNonConventionalComponents = (MMGroupBox)target;
				break;
			case 2:
				grdNonConventionalComponents = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMComp_Spec_Input_Petroleum_ViewModel : MMTabPageViewModel
	{
		public class grdPseudocomponents_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtPseudocomponents_pseudocomp_Property = CxvPropertyDeclaration.Register("txtPseudocomponents_pseudocomp", typeof(grdPseudocomponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PSEUDOCOMPID.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object txtPseudocomponents_pseudocomp => GetValue(txtPseudocomponents_pseudocomp_Property);
		}

		public class grdBlend_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtBlend_blend_Property = CxvPropertyDeclaration.Register("txtBlend_blend", typeof(grdBlend_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.BLENDID.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object txtBlend_blend => GetValue(txtBlend_blend_Property);
		}

		public class grdAssay_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtAssay_assay_Property = CxvPropertyDeclaration.Register("txtAssay_assay", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ASSAYID.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object txtAssay_assay => GetValue(txtAssay_assay_Property);
		}

		private ICommand _cmdAssayLibrary_Command;

		public static readonly CxvPropertyDeclaration cmdAssayLibrary_Command_var1_Property = CxvPropertyDeclaration.Register("cmdAssayLibrary_Command_var1", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Import assay data",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Petroleum_ViewModel__CxvCmdButtonProperty_ToolTipText_Assay_Library"
		});

		public static readonly CxvPropertyDeclaration grdPseudocomponents_GridData_Property = CxvPropertyDeclaration.Register("grdPseudocomponents_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPseudocomponents_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PSEUDOCOMPID",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration grdBlend_GridData_Property = CxvPropertyDeclaration.Register("grdBlend_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdBlend_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.BLENDID",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration grdAssay_GridData_Property = CxvPropertyDeclaration.Register("grdAssay_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAssay_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.ASSAYID",
				UseChildId = true,
				Name = "y"
			}
		});

		public ICommand cmdAssayLibrary_Command
		{
			get
			{
				if (_cmdAssayLibrary_Command == null)
				{
					_cmdAssayLibrary_Command = new CxvDelegateCommand<object>(cmdAssayLibrary_CommandExecute);
				}
				return _cmdAssayLibrary_Command;
			}
		}

		public object cmdAssayLibrary_Command_var1 => GetValue(cmdAssayLibrary_Command_var1_Property);

		public object grdPseudocomponents_GridData => GetValue(grdPseudocomponents_GridData_Property);

		public object grdBlend_GridData => GetValue(grdBlend_GridData_Property);

		public object grdAssay_GridData => GetValue(grdAssay_GridData_Property);

		private void cmdAssayLibrary_CommandExecute(object parameter)
		{
			ImportAssay();
			UpdateAll();
		}
	}
	[ProgId("MMComp_Spec.MMComp_Spec_Input_Petroleum")]
	public class MMComp_Spec_Input_Petroleum : MMTabPage, IComponentConnector
	{
		internal MMCmdButton cmdAssayLibrary;

		internal MMGroupBox fraAssays;

		internal MMScrollArea grdAssay;

		internal MMGroupBox fraBlends;

		internal MMScrollArea grdBlend;

		internal MMGroupBox fraPseudocomponents;

		internal MMScrollArea grdPseudocomponents;

		private bool _contentLoaded;

		public MMComp_Spec_Input_Petroleum()
		{
			base.ViewModelType = typeof(MMComp_Spec_Input_Petroleum_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/specifications/mmcomp_spec_input_petroleum.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				cmdAssayLibrary = (MMCmdButton)target;
				break;
			case 2:
				fraAssays = (MMGroupBox)target;
				break;
			case 3:
				grdAssay = (MMScrollArea)target;
				break;
			case 4:
				fraBlends = (MMGroupBox)target;
				break;
			case 5:
				grdBlend = (MMScrollArea)target;
				break;
			case 6:
				fraPseudocomponents = (MMGroupBox)target;
				break;
			case 7:
				grdPseudocomponents = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMComp_Spec_Input_Selection_ViewModel : MMTabPageViewModel
	{
		public class grdComponents_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdComponents_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox1_type",
						DataPath = "@main.Input.TYPE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Conventional",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Conventional",
						Value = "MMComboBox1_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "CONV"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Solid",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Solid",
						Value = "MMComboBox1_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "SOLID"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Biocomponent",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Biocomponent",
						Value = "MMComboBox1_MultiMapOption_11",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "BIO"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Nonconventional",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Nonconventional",
						Value = "MMComboBox1_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "NC"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Pseudocomponent",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Pseudocomponent",
						Value = "MMComboBox1_MultiMapOption_4",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "PSEUDO"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Assay",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Assay",
						Value = "MMComboBox1_MultiMapOption_5",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "ASSAY"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Blend",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Blend",
						Value = "MMComboBox1_MultiMapOption_6",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "BLEND"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Hypothetical liquid",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Hypothetical_liquid",
						Value = "MMComboBox1_MultiMapOption_7",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "HYPO-LIQ"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Polymer",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Polymer",
						Value = "MMComboBox1_MultiMapOption_8",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "POLYMER"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Oligomer",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Oligomer",
						Value = "MMComboBox1_MultiMapOption_9",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "OLIGOMER"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Segment",
						DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Segment",
						Value = "MMComboBox1_MultiMapOption_10",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_type",
								Value = "SEGMENT"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtCompID_cid_Property = CxvPropertyDeclaration.Register("txtCompID_cid", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.TYPE.@y",
				IsEntered = false
			});

			public static readonly CxvPropertyDeclaration txt_Formula_name_Property = CxvPropertyDeclaration.Register("txt_Formula_name", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ANAME1.@y"
			});

			public static readonly CxvPropertyDeclaration txtComponentName_dbname_Property = CxvPropertyDeclaration.Register("txtComponentName_dbname", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.DBNAME1.@y"
			});

			public static readonly CxvPropertyDeclaration txt_Formula_CAS_Property = CxvPropertyDeclaration.Register("txt_Formula_CAS", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.CASN.@y"
			});

			public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

			public object txtCompID_cid => GetValue(txtCompID_cid_Property);

			public object txt_Formula_name => GetValue(txt_Formula_name_Property);

			public object txtComponentName_dbname => GetValue(txtComponentName_dbname_Property);

			public object txt_Formula_CAS => GetValue(txt_Formula_CAS_Property);
		}

		private ICommand _cmdFind_Command;

		private ICommand _cmdElecWizard_Command;

		private ICommand _cmdUserDefWizard_Command;

		private ICommand _cmdReorder_Command;

		private ICommand _cmdReview_Command;

		private ICommand bioLookupCommand;

		public static readonly CxvPropertyDeclaration grdComponents_GridData_Property = CxvPropertyDeclaration.Register("grdComponents_GridData", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdComponents_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.TYPE",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration cmdReview_var1_Property = CxvPropertyDeclaration.Register("cmdReview_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				SubConditions = 
				{
					new CxvLogicalTest
					{
						DataPath = "@main.@parent.@parent.Other Databanks.CC Nodes.LOADPURE"
					},
					new CxvLogicalTest
					{
						DataPath = "Top.AppModelV8",
						DataAttribute = "status_code",
						Operator = CxvLogicalOperator.NotEqual,
						Value = 4
					}
				}
			},
			ToolTipText = "Review available pure component parameters",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Review"
		});

		public static readonly CxvPropertyDeclaration CmdFind_Command_var1_Property = CxvPropertyDeclaration.Register("CmdFind_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Find components",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Find_Components"
		});

		public static readonly CxvPropertyDeclaration CmdElecWizard_Command_var1_Property = CxvPropertyDeclaration.Register("CmdElecWizard_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Electrolyte wizard",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Electrolyte_Wizard"
		});

		private ICommand _cmdSFEAssistant_Command;

		public static readonly CxvPropertyDeclaration CmdSFEAssistant_Command_var1_Property = CxvPropertyDeclaration.Register("CmdSFEAssistant_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Solid-Fluid Equilibrium assistant",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_SFE_Assistant"
		});

		public static readonly CxvPropertyDeclaration CmdUserDefWizard_Command_var1_Property = CxvPropertyDeclaration.Register("CmdUserDefWizard_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "User-defined component wizard",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_User_Defined"
		});

		public static readonly CxvPropertyDeclaration CmdReorder_Command_var1_Property = CxvPropertyDeclaration.Register("CmdReorder_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = "Change order of components",
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Reorder_Components"
		});

		public static readonly CxvPropertyDeclaration BioLookupVar_Property = CxvPropertyDeclaration.Register("BioLookupVar", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
		{
			ToolTipText = ApwnResources.BiomassLookupTooltip,
			ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Biomass_Loolup",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.@parent.Bio-Comps.CC Nodes.BIOLKP",
				Operator = CxvLogicalOperator.Equal,
				Value = 0
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.@parent.Bio-Comps.CC Nodes.BIOLKP",
				Operator = CxvLogicalOperator.Equal,
				Value = 0
			}
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

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

		public ICommand cmdElecWizard_Command
		{
			get
			{
				if (_cmdElecWizard_Command == null)
				{
					_cmdElecWizard_Command = new CxvDelegateCommand<object>(cmdElecWizard_CommandExecute);
				}
				return _cmdElecWizard_Command;
			}
		}

		public ICommand cmdUserDefWizard_Command
		{
			get
			{
				if (_cmdUserDefWizard_Command == null)
				{
					_cmdUserDefWizard_Command = new CxvDelegateCommand<object>(cmdUserDefWizard_CommandExecute);
				}
				return _cmdUserDefWizard_Command;
			}
		}

		public ICommand cmdReorder_Command
		{
			get
			{
				if (_cmdReorder_Command == null)
				{
					_cmdReorder_Command = new CxvDelegateCommand<object>(cmdReorder_CommandExecute);
				}
				return _cmdReorder_Command;
			}
		}

		public ICommand cmdReview_Command
		{
			get
			{
				if (_cmdReview_Command == null)
				{
					_cmdReview_Command = new CxvDelegateCommand<object>(cmdReview_CommandExecute);
				}
				return _cmdReview_Command;
			}
		}

		public ICommand BioLookupCommand
		{
			get
			{
				if (bioLookupCommand == null)
				{
					bioLookupCommand = new CxvDelegateCommand<object>(BioLookupCommandExecute);
				}
				return bioLookupCommand;
			}
		}

		public object grdComponents_GridData => GetValue(grdComponents_GridData_Property);

		public object cmdReview_var1 => GetValue(cmdReview_var1_Property);

		public object CmdFind_Command_var1 => GetValue(CmdFind_Command_var1_Property);

		public object CmdElecWizard_Command_var1 => GetValue(CmdElecWizard_Command_var1_Property);

		public ICommand cmdSFEAssistant_Command
		{
			get
			{
				if (_cmdSFEAssistant_Command == null)
				{
					_cmdSFEAssistant_Command = new CxvDelegateCommand<object>(cmdSFEAssistant_CommandExecute);
				}
				return _cmdSFEAssistant_Command;
			}
		}

		public object CmdSFEAssistant_Command_var1 => GetValue(CmdSFEAssistant_Command_var1_Property);

		public object CmdUserDefWizard_Command_var1 => GetValue(CmdUserDefWizard_Command_var1_Property);

		public object CmdReorder_Command_var1 => GetValue(CmdReorder_Command_var1_Property);

		public object BioLookupVar => GetValue(BioLookupVar_Property);

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

		private int FirstRowIndex
		{
			get
			{
				if (_SelectedRowIndexes != null && _SelectedRowIndexes.Count > 0)
				{
					return _SelectedRowIndexes[0] + 1;
				}
				return 1;
			}
		}

		private void BioLookupCommandExecute(object parameter)
		{
			if (!(grdComponents_GridData is CxvVectorPropertyData cxvVectorPropertyData))
			{
				return;
			}
			List<string> list = new List<string>();
			List<string> list2 = new List<string>();
			foreach (grdComponents_GridData_ItemTemplate item in cxvVectorPropertyData)
			{
				string text = (item.txtComponentName_dbname as CxvVariableData).Value.ToString();
				if (!string.IsNullOrEmpty(text))
				{
					string text2 = (item.MMComboBox1_MultiMap as CxvMultiMapPropertyData).Value?.ToString();
					if (text2 == "MMComboBox1_MultiMapOption_11")
					{
						list.Add(text);
					}
					else if (text2 == "MMComboBox1_MultiMapOption_2")
					{
						list2.Add(text);
					}
				}
			}
			if (base.UnityContainer != null)
			{
				IShellApplication shellApplication = base.UnityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				Window window = base.UnityContainer.Resolve<Window>("BiomassLookup", new ResolverOverride[3]
				{
					new ParameterOverride("biofeedstocks", list),
					new ParameterOverride("bioBaseCompounds", list2),
					new ParameterOverride("compoundsTotalCount", cxvVectorPropertyData.Count - 1)
				});
				if (shellApplication != null)
				{
					window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					window.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
				if (window.ShowDialog() == true)
				{
					UpdateDisplay();
					UpdateAll();
				}
			}
		}

		private void cmdFind_CommandExecute(object parameter)
		{
			Find();
		}

		public void Find()
		{
			if (this.GxSearchComponents(FirstRowIndex, "") == 2)
			{
				ShowMMMessageBoxEventArgs e = new ShowMMMessageBoxEventArgs
				{
					Title = Resources.MsgBox_Title_Confirm,
					Message = WpfFindComponentResources.EstimateParameters,
					MsgBoxButton = 1,
					MsgBoxImage = 0,
					DialogResult = 5
				};
				ShowMMMessageBox(e);
				if (e.DialogResult == 1)
				{
					ExpandDataPathAndSet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value", null, "PCES");
					GoToNode($"Properties!{ApwnResources.BrowserPropertyEstimation}");
					base.UnityContainer.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<RunEvent>().Publish(new RunEventArgs());
				}
			}
		}

		private void cmdElecWizard_CommandExecute(object parameter)
		{
			this.GxElectrolyteWizard();
		}

		private void cmdUserDefWizard_CommandExecute(object parameter)
		{
			this.GxUserDefWizard(FirstRowIndex);
		}

		private void cmdReorder_CommandExecute(object parameter)
		{
			if (!(grdComponents_GridData is CxvVectorPropertyData cxvVectorPropertyData))
			{
				return;
			}
			if (cxvVectorPropertyData.Count < 2)
			{
				ShowMessageBoxEventArgs args = new ShowMessageBoxEventArgs
				{
					Message = Resources.MMComp_Spec_Input_Selection_ViewModel__Reorder_Message1,
					MsgBoxButton = MessageBoxButton.OK,
					MsgBoxImage = MessageBoxImage.Asterisk,
					Title = Resources.MMComp_Spec_Input_Selection_ViewModel__Reorder_Title
				};
				ShowMessageBox(args);
				return;
			}
			for (int i = 0; i < cxvVectorPropertyData.Count - 1; i++)
			{
				if ((cxvVectorPropertyData[i] as grdComponents_GridData_ItemTemplate).txtCompID_cid is CxvVariableData cxvVariableData && (cxvVariableData.Value == null || string.IsNullOrEmpty(cxvVariableData.Value.ToString())))
				{
					ShowMessageBoxEventArgs args2 = new ShowMessageBoxEventArgs
					{
						Message = Resources.MMComp_Spec_Input_Selection_ViewModel__Reorder_Message2,
						MsgBoxButton = MessageBoxButton.OK,
						MsgBoxImage = MessageBoxImage.Asterisk,
						Title = Resources.MMComp_Spec_Input_Selection_ViewModel__Reorder_Title
					};
					ShowMessageBox(args2);
					return;
				}
			}
			string initialSelectedComponent = null;
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count > 0 && cxvVectorPropertyData[SelectedRowIndexes[0]] is grdComponents_GridData_ItemTemplate { txtCompID_cid: CxvVariableData txtCompID_cid })
			{
				initialSelectedComponent = txtCompID_cid.Value as string;
			}
			base.UnityContainer?.TryResolve<IEventAggregator>()?.GetEvent<OpenReorderComponentsDialogEvent>().Publish(new OpenReorderComponentsDialogEventArgs(initialSelectedComponent));
			UpdateDisplay();
		}

		private void cmdReview_CommandExecute(object parameter)
		{
			string empty = string.Empty;
			empty = ((!(CxsConverter.ValueToString(ExpandDataPathAndGet("Top.appModelV8.Setup.Main.Input.RUN_CLASS", "value")) == "ADA")) ? "Top.appModelV8.Setup.ReportOptions.Property-Report.Input.PARPLUS" : "Top.appModelV8.Setup.ReportOptions.ADA-Report.Input.PARAMS");
			object value = ExpandDataPathAndGet(empty, "value");
			this.GxReviewParameterMenuItem();
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("Top.appModelV8.Settings.copy_retrieved", "value"));
			ExpandDataPathAndSet(empty, "value", value);
			if (num == 1)
			{
				GoToNode($"Properties!{ApwnResources.BrowserMethods}.{ApwnResources.BrowserParameters}.{ApwnResources.BrowserPureComponents}.REVIEW-1");
			}
			else
			{
				GoToNode($"Properties!{ApwnResources.BrowserMethods}.{ApwnResources.BrowserParameters}.{ApwnResources.BrowserResults}");
			}
		}

		private void cmdSFEAssistant_CommandExecute(object parameter)
		{
			this.GxSFEAssistantMain();
		}
	}
	[ProgId("MMComp_Spec.MMComp_Spec_Input_Selection")]
	public class MMComp_Spec_Input_Selection : MMTabPage, IComponentConnector
	{
		private const string ComponentsGridDataRetrieverKey = "MMComp_Spec_Input_Selection";

		private bool _triedToResolveDataRetriever;

		internal MMLabel fra_DefineComponents;

		internal MMScrollAreaMS grdComponents;

		internal MMCmdButton cmdFind;

		internal MMCmdButton cmdElecWizard;

		internal MMCmdButton cmdSFEAssistant;

		internal MMCmdButton cmdUserDefWizard;

		internal MMCmdButton cmdReorder;

		internal MMCmdButton cmdReview;

		private bool _contentLoaded;

		public MMComp_Spec_Input_Selection()
		{
			base.ViewModelType = typeof(MMComp_Spec_Input_Selection_ViewModel);
			InitializeComponent();
			fra_DefineComponents.PreviewMouseDoubleClick += fra_DefineComponents_PreviewMouseDoubleClick;
		}

		private void fra_DefineComponents_PreviewMouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			if (base.ViewModel is MMComp_Spec_Input_Selection_ViewModel mMComp_Spec_Input_Selection_ViewModel)
			{
				mMComp_Spec_Input_Selection_ViewModel.Find();
			}
		}

		protected override void OnUnityContainerChanged(IUnityContainer oldContainer, IUnityContainer newContainer)
		{
			if (grdComponents.DataRetriever == null && newContainer != null && !_triedToResolveDataRetriever)
			{
				if (newContainer.IsRegistered<IMMScrollAreaMSDataRetriever>("MMComp_Spec_Input_Selection"))
				{
					grdComponents.DataRetriever = newContainer.Resolve<IMMScrollAreaMSDataRetriever>("MMComp_Spec_Input_Selection", Array.Empty<ResolverOverride>());
				}
				_triedToResolveDataRetriever = true;
			}
			base.OnUnityContainerChanged(oldContainer, newContainer);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/specifications/mmcomp_spec_input_selection.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fra_DefineComponents = (MMLabel)target;
				break;
			case 2:
				grdComponents = (MMScrollAreaMS)target;
				break;
			case 3:
				cmdFind = (MMCmdButton)target;
				break;
			case 4:
				cmdElecWizard = (MMCmdButton)target;
				break;
			case 5:
				cmdSFEAssistant = (MMCmdButton)target;
				break;
			case 6:
				cmdUserDefWizard = (MMCmdButton)target;
				break;
			case 7:
				cmdReorder = (MMCmdButton)target;
				break;
			case 8:
				cmdReview = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.Pseudocomponents
{
	public class MMPseudo_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration PseudoMain_Property = CxvPropertyDeclaration.Register("PseudoMain", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration wscid_Property = CxvPropertyDeclaration.Register("wscid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "wscid"
		});

		public static readonly CxvPropertyDeclaration vicid_Property = CxvPropertyDeclaration.Register("vicid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "vicid"
		});

		public static readonly CxvPropertyDeclaration vpcid_Property = CxvPropertyDeclaration.Register("vpcid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "vpcid"
		});

		public static readonly CxvPropertyDeclaration VAPOR_Property = CxvPropertyDeclaration.Register("VAPOR", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VAPOR"
		});

		public static readonly CxvPropertyDeclaration VISC_Property = CxvPropertyDeclaration.Register("VISC", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VISC"
		});

		public static readonly CxvPropertyDeclaration SOLU_Property = CxvPropertyDeclaration.Register("SOLU", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.SOLU"
		});

		public static readonly CxvPropertyDeclaration VPOPT_Property = CxvPropertyDeclaration.Register("VPOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VPOPT"
		});

		public static readonly CxvPropertyDeclaration VIOPT_Property = CxvPropertyDeclaration.Register("VIOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VIOPT"
		});

		public static readonly CxvPropertyDeclaration WSOPT_Property = CxvPropertyDeclaration.Register("WSOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.WSOPT"
		});

		public static readonly CxvPropertyDeclaration DISABLE_Property = CxvPropertyDeclaration.Register("DISABLE", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.CC Nodes.DISABLE"
		});

		public static readonly CxvPropertyDeclaration PSEUDOOPT_Property = CxvPropertyDeclaration.Register("PSEUDOOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.CC Nodes.PSEUDOOPT"
		});

		public static readonly CxvPropertyDeclaration _NOUSRPROP_Property = CxvPropertyDeclaration.Register("_NOUSRPROP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.NOUSRPROP"
		});

		public static readonly CxvPropertyDeclaration CPPROP_Property = CxvPropertyDeclaration.Register("CPPROP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.CPPROP"
		});

		public static readonly CxvPropertyDeclaration UNPP_Property = CxvPropertyDeclaration.Register("UNPP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.UNPP"
		});

		public static readonly CxvPropertyDeclaration strPID_Property = CxvPropertyDeclaration.Register("strPID", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "strPID"
		});

		public static readonly CxvPropertyDeclaration ENPP_Property = CxvPropertyDeclaration.Register("ENPP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.ENPP"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PseudoMain" },
			AccessibleDataPaths = { "@DISABLE" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@VAPOR" },
			AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
			EnteredDataPaths = { "@VPOPT" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@VISC" },
			AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
			EnteredDataPaths = { "@VIOPT" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SOLU" },
			AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
			EnteredDataPaths = { "@WSOPT" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CPPROP" },
			AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE", "@ENPP" },
			EnteredDataPaths = { "@UNPP" }
		});

		public object PseudoMain => GetValue(PseudoMain_Property);

		public object wscid => GetValue(wscid_Property);

		public object vicid => GetValue(vicid_Property);

		public object vpcid => GetValue(vpcid_Property);

		public object VAPOR => GetValue(VAPOR_Property);

		public object VISC => GetValue(VISC_Property);

		public object SOLU => GetValue(SOLU_Property);

		public object VPOPT => GetValue(VPOPT_Property);

		public object VIOPT => GetValue(VIOPT_Property);

		public object WSOPT => GetValue(WSOPT_Property);

		public object DISABLE => GetValue(DISABLE_Property);

		public object PSEUDOOPT => GetValue(PSEUDOOPT_Property);

		public object _NOUSRPROP => GetValue(_NOUSRPROP_Property);

		public object CPPROP => GetValue(CPPROP_Property);

		public object UNPP => GetValue(UNPP_Property);

		public object strPID => GetValue(strPID_Property);

		public object ENPP => GetValue(ENPP_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);
	}
	[ProgId("MMPseudo.MMPseudo_Input")]
	public class MMPseudo_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tab_MMPseudo_Input;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		private bool _contentLoaded;

		public MMPseudo_Input()
		{
			base.ViewModelType = typeof(MMPseudo_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tab_MMPseudo_Input = (MMTabStrip)target;
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPseudo_Input_Petro_ViewModel : MMTabPageViewModel
	{
		public class grdLEnds_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboCompID_var1_Property = CxvPropertyDeclaration.Register("cboCompID_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Properties.Input.VALUE.@strPID.@y"
			});

			public static readonly CxvPropertyDeclaration txtFRAC_var1_Property = CxvPropertyDeclaration.Register("txtFRAC_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.VALUE.@strPID.@y"
			});

			public object cboCompID_var1 => GetValue(cboCompID_var1_Property);

			public object txtFRAC_var1 => GetValue(txtFRAC_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLEnds_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Properties.Input.VALUE.@strPID",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration mnuPropType_var2_Property = CxvPropertyDeclaration.Register("mnuPropType_var2", typeof(MMPseudo_Input_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "strPID"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_CPPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_CPPROPB", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.CPPROP"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_UNPPB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNPPB", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.UNPP"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMPseudo_Input_Petro_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Properties.Input.VALUE",
			SelectedItemBinding = "mnuPropType_var2.Value",
			CreateNewPrompt = "Property type:",
			CreateNewPromptResourceKey = "MMPseudo_Input_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
			CompletePaths = { "@main.Properties.CC Nodes.CPPROP" },
			EnteredPaths = { "@main.Properties.CC Nodes.UNPP" }
		});

		public object grdLEnds_GridData => GetValue(grdLEnds_GridData_Property);

		public object mnuPropType_var2 => GetValue(mnuPropType_var2_Property);

		public object mnuPropType_CPPROPB => GetValue(mnuPropType_CPPROPB_Property);

		public object mnuPropType_UNPPB => GetValue(mnuPropType_UNPPB_Property);

		public object mnuPropType_var1 => GetValue(mnuPropType_var1_Property);
	}
	[ProgId("MMPseudo.MMPseudo_Input_Petro")]
	public class MMPseudo_Input_Petro : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuPropType_label;

		internal MMAdvancedComboEdit mnuPropType;

		internal MMGroupBox fraLEndsAnal;

		internal MMScrollArea grdLEnds;

		private bool _contentLoaded;

		public MMPseudo_Input_Petro()
		{
			base.ViewModelType = typeof(MMPseudo_Input_Petro_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input_petro.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mnuPropType_label = (MMLabel)target;
				break;
			case 2:
				mnuPropType = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraLEndsAnal = (MMGroupBox)target;
				break;
			case 4:
				grdLEnds = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPseudo_Input_Spec_ViewModel : MMTabPageViewModel
	{
		public class grdAdvanced_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtPCID_PCID_Property = CxvPropertyDeclaration.Register("txtPCID_PCID", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Specifications.Input.PCOPSETNAME.@y"
			});

			public static readonly CxvPropertyDeclaration cboOpSet_PCOPSETNAME_Property = CxvPropertyDeclaration.Register("cboOpSet_PCOPSETNAME", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Specifications.Input.PCOPSETNAME.@y"
			});

			public static readonly CxvPropertyDeclaration txtMW_MW_Property = CxvPropertyDeclaration.Register("txtMW_MW", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.MW.@y"
			});

			public static readonly CxvPropertyDeclaration txtLDEN_LDEN_Property = CxvPropertyDeclaration.Register("txtLDEN_LDEN", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.LDEN.@y"
			});

			public static readonly CxvPropertyDeclaration txtGRAV_GRAV_Property = CxvPropertyDeclaration.Register("txtGRAV_GRAV", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.GRAV.@y"
			});

			public static readonly CxvPropertyDeclaration txtAPI_API_Property = CxvPropertyDeclaration.Register("txtAPI_API", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.API.@y"
			});

			public static readonly CxvPropertyDeclaration txtNBP_NBP_Property = CxvPropertyDeclaration.Register("txtNBP_NBP", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.NBP.@y"
			});

			public object txtPCID_PCID => GetValue(txtPCID_PCID_Property);

			public object cboOpSet_PCOPSETNAME => GetValue(cboOpSet_PCOPSETNAME_Property);

			public object txtMW_MW => GetValue(txtMW_MW_Property);

			public object txtLDEN_LDEN => GetValue(txtLDEN_LDEN_Property);

			public object txtGRAV_GRAV => GetValue(txtGRAV_GRAV_Property);

			public object txtAPI_API => GetValue(txtAPI_API_Property);

			public object txtNBP_NBP => GetValue(txtNBP_NBP_Property);
		}

		public class grdBasic_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtPCID2_PCID_Property = CxvPropertyDeclaration.Register("txtPCID2_PCID", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Specifications.Input.NBP.@y"
			});

			public static readonly CxvPropertyDeclaration txtMW2_MW_Property = CxvPropertyDeclaration.Register("txtMW2_MW", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.MW.@y"
			});

			public static readonly CxvPropertyDeclaration txtNBP2_NBP_Property = CxvPropertyDeclaration.Register("txtNBP2_NBP", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Specifications.Input.NBP.@y"
			});

			public static readonly CxvPropertyDeclaration txtGravType_gravval_Property = CxvPropertyDeclaration.Register("txtGravType_gravval", typeof(grdBasic_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						DataPath = "@main.Specifications.Input.GRAVTYPE",
						Value = "GRAV",
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Specifications.Input.GRAV.@y"
						}
					},
					new CxvPropertyChoice
					{
						DataPath = "@main.Specifications.Input.GRAVTYPE",
						Value = "API",
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Specifications.Input.API.@y"
						}
					},
					new CxvPropertyChoice
					{
						DataPath = "@main.Specifications.Input.GRAVTYPE",
						Value = "LDEN",
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Specifications.Input.LDEN.@y"
						}
					}
				}
			});

			public object txtPCID2_PCID => GetValue(txtPCID2_PCID_Property);

			public object txtMW2_MW => GetValue(txtMW2_MW_Property);

			public object txtNBP2_NBP => GetValue(txtNBP2_NBP_Property);

			public object txtGravType_gravval => GetValue(txtGravType_gravval_Property);
		}

		public static readonly CxvPropertyDeclaration cboViewLayout_MultiMap_Property = CxvPropertyDeclaration.Register("cboViewLayout_MultiMap", typeof(MMPseudo_Input_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboViewLayout_VIEWLAYOUT",
					DataPath = "@main.Specifications.Input.VIEWLAYOUT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Basic layout",
					DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Basic_layout",
					Value = "cboViewLayout_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboViewLayout_VIEWLAYOUT",
							Value = "BASIC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Advanced layout",
					DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Advanced_layout",
					Value = "cboViewLayout_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboViewLayout_VIEWLAYOUT",
							Value = "ADVANCED"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.DISABLE"
			}
		});

		public static readonly CxvPropertyDeclaration lblView_state_Property = CxvPropertyDeclaration.Register("lblView_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvLabelProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.DISABLE"
			}
		});

		public static readonly CxvPropertyDeclaration fraAdvanced_state_Property = CxvPropertyDeclaration.Register("fraAdvanced_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.DISABLE"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.OPTIONA"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuLDen_LDenUnits_Property = CxvPropertyDeclaration.Register("lbtuLDen_LDenUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.Input.LDEN"
		});

		public static readonly CxvPropertyDeclaration lbtuTempUnits_TempUnits_Property = CxvPropertyDeclaration.Register("lbtuTempUnits_TempUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.Input.NBP"
		});

		public static readonly CxvPropertyDeclaration grdAdvanced_GridData_Property = CxvPropertyDeclaration.Register("grdAdvanced_GridData", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAdvanced_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Specifications.Input.PCOPSETNAME",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration fraBasic_state_Property = CxvPropertyDeclaration.Register("fraBasic_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.DISABLE"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.OPTIONB"
			}
		});

		public static readonly CxvPropertyDeclaration fraBasic_gravname_Property = CxvPropertyDeclaration.Register("fraBasic_gravname", typeof(MMPseudo_Input_Spec_ViewModel), new CxvParameterProperty
		{
			Parameter = "gravname"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_basicopset_Property = CxvPropertyDeclaration.Register("MMComboBox1_basicopset", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Specifications.Input.PCOPSETNAME.#0"
		});

		public static readonly CxvPropertyDeclaration grdBasic_GridData_Property = CxvPropertyDeclaration.Register("grdBasic_GridData", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdBasic_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Specifications.Input.PCOPSETNAME",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_TempUnits_Property = CxvPropertyDeclaration.Register("MMLBUText3_TempUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.Input.NBP"
		});

		public static readonly CxvPropertyDeclaration lbtuNBP_LDenUnits_Property = CxvPropertyDeclaration.Register("lbtuNBP_LDenUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Specifications.Input.LDEN",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Specifications.CC Nodes.OPT_DEN"
			}
		});

		public static readonly CxvPropertyDeclaration cboGravType_MultiMap_Property = CxvPropertyDeclaration.Register("cboGravType_MultiMap", typeof(MMPseudo_Input_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboGravType_gravtype",
					DataPath = "@main.Specifications.Input.GRAVTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "API Gravity",
					DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_API_Gravity",
					Value = "cboGravType_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboGravType_gravtype",
							Value = "API"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Specific gravity",
					DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
					Value = "cboGravType_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboGravType_gravtype",
							Value = "GRAV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Density",
					DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Density",
					Value = "cboGravType_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboGravType_gravtype",
							Value = "LDEN"
						}
					}
				}
			}
		});

		public object cboViewLayout_MultiMap => GetValue(cboViewLayout_MultiMap_Property);

		public object lblView_state => GetValue(lblView_state_Property);

		public object fraAdvanced_state => GetValue(fraAdvanced_state_Property);

		public object lbtuLDen_LDenUnits => GetValue(lbtuLDen_LDenUnits_Property);

		public object lbtuTempUnits_TempUnits => GetValue(lbtuTempUnits_TempUnits_Property);

		public object grdAdvanced_GridData => GetValue(grdAdvanced_GridData_Property);

		public object fraBasic_state => GetValue(fraBasic_state_Property);

		public object fraBasic_gravname => GetValue(fraBasic_gravname_Property);

		public object MMComboBox1_basicopset => GetValue(MMComboBox1_basicopset_Property);

		public object grdBasic_GridData => GetValue(grdBasic_GridData_Property);

		public object MMLBUText3_TempUnits => GetValue(MMLBUText3_TempUnits_Property);

		public object lbtuNBP_LDenUnits => GetValue(lbtuNBP_LDenUnits_Property);

		public object cboGravType_MultiMap => GetValue(cboGravType_MultiMap_Property);
	}
	[ProgId("MMPseudo.MMPseudo_Input_Spec")]
	public class MMPseudo_Input_Spec : MMTabPage, IComponentConnector
	{
		internal MMLabel lblView;

		internal MMComboEdit cboViewLayout;

		internal MMGroupBox fraAdvanced;

		internal MMScrollArea grdAdvanced;

		internal MMGroupBox fraBasic;

		internal MMLabel lblOpSetName;

		internal MMComboEdit MMComboBox1;

		internal MMScrollArea grdBasic;

		private bool _contentLoaded;

		public MMPseudo_Input_Spec()
		{
			base.ViewModelType = typeof(MMPseudo_Input_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblView = (MMLabel)target;
				break;
			case 2:
				cboViewLayout = (MMComboEdit)target;
				break;
			case 3:
				fraAdvanced = (MMGroupBox)target;
				break;
			case 4:
				grdAdvanced = (MMScrollArea)target;
				break;
			case 5:
				fraBasic = (MMGroupBox)target;
				break;
			case 6:
				lblOpSetName = (MMLabel)target;
				break;
			case 7:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 8:
				grdBasic = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPseudo_Input_Vapor_ViewModel : MMTabPageViewModel
	{
		public class grdVisc_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTemp_temp_Property = CxvPropertyDeclaration.Register("txtTemp_temp", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.TEMP.@vpcid.@y"
			});

			public static readonly CxvPropertyDeclaration txtVP_VP_Property = CxvPropertyDeclaration.Register("txtVP_VP", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.VP.@vpcid.@y"
			});

			public object txtTemp_temp => GetValue(txtTemp_temp_Property);

			public object txtVP_VP => GetValue(txtVP_VP_Property);
		}

		public static readonly CxvPropertyDeclaration fraVapor_state_Property = CxvPropertyDeclaration.Register("fraVapor_state", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "vpcid",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.Input.TEMP.@vpcid"
		});

		public static readonly CxvPropertyDeclaration lbtuVisc_var1_Property = CxvPropertyDeclaration.Register("lbtuVisc_var1", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.Input.VP.@vpcid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvParameterProperty
		{
			Parameter = "vpcid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VPCOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VPCOMP", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VPCOMP"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VAPOR2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VAPOR2", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VAPOR2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VPOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VPOPT2", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VPOPT2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Properties.Input.TEMP",
			SelectedItemBinding = "MMMenuButton1_target.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMPseudo_Input_Vapor_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
			CompletePaths = { "@main.Properties.CC Nodes.VPCOMP", "@main.Properties.CC Nodes.VAPOR2" },
			EnteredPaths = { "@main.Properties.CC Nodes.VPOPT2" }
		});

		public static readonly CxvPropertyDeclaration grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdVisc_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Properties.Input.@indexVar.@vpcid",
				UseChildId = true,
				Name = "y"
			},
			AllowCollectionChange = false
		});

		private EventHandler _maxCountDependencies_PropertyDependencyChangedHandler;

		private CxvPropertyWatch maxCountDependencies;

		public object fraVapor_state => GetValue(fraVapor_state_Property);

		public object lbtuTemp_var1 => GetValue(lbtuTemp_var1_Property);

		public object lbtuVisc_var1 => GetValue(lbtuVisc_var1_Property);

		public object MMMenuButton1_target => GetValue(MMMenuButton1_target_Property);

		public object MMMenuButton1_VPCOMP => GetValue(MMMenuButton1_VPCOMP_Property);

		public object MMMenuButton1_VAPOR2 => GetValue(MMMenuButton1_VAPOR2_Property);

		public object MMMenuButton1_VPOPT2 => GetValue(MMMenuButton1_VPOPT2_Property);

		public object MMMenuButton1_Selector => GetValue(MMMenuButton1_Selector_Property);

		public object grdVisc_GridData => GetValue(grdVisc_GridData_Property);

		private EventHandler maxCountDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_maxCountDependencies_PropertyDependencyChangedHandler == null)
				{
					_maxCountDependencies_PropertyDependencyChangedHandler = delegate
					{
						OnUpdateGridCount();
					};
				}
				return _maxCountDependencies_PropertyDependencyChangedHandler;
			}
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "MMMenuButton1_target" && subPropertyName == "Value" && MMMenuButton1_Selector is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData)
			{
				if (maxCountDependencies != null)
				{
					maxCountDependencies.PropertyDependencyChanged -= maxCountDependencies_PropertyDependencyChangedHandler;
				}
				if (maxCountDependencies != null)
				{
					maxCountDependencies.Clear();
				}
				else
				{
					maxCountDependencies = new CxvPropertyWatch();
				}
				string selectedItem = cxvAdvCollectionPropertyData.SelectedItem;
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.TEMP." + selectedItem, "child_count", null, maxCountDependencies));
				int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VP." + selectedItem, "child_count", null, maxCountDependencies));
				if (!maxCountDependencies.IsEmpty)
				{
					maxCountDependencies.PropertyDependencyChanged += maxCountDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					maxCountDependencies = null;
				}
				if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
				{
					ResolveUpdateParameter("indexVar", "VP");
				}
				else
				{
					ResolveUpdateParameter("indexVar", "TEMP");
				}
			}
		}

		private void OnUpdateGridCount()
		{
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.TEMP.@vpcid", "child_count", null, maxCountDependencies));
			int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VP.@vpcid", "child_count", null, maxCountDependencies));
			if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
			{
				ResolveUpdateParameter("indexVar", "VP");
			}
			else
			{
				ResolveUpdateParameter("indexVar", "TEMP");
			}
		}
	}
	[ProgId("MMPseudo.MMPseudo_Input_Vapor")]
	public class MMPseudo_Input_Vapor : MMTabPage, IComponentConnector
	{
		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMGroupBox fraVapor;

		internal MMScrollArea grdVisc;

		private bool _contentLoaded;

		public MMPseudo_Input_Vapor()
		{
			base.ViewModelType = typeof(MMPseudo_Input_Vapor_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input_vapor.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 2:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraVapor = (MMGroupBox)target;
				break;
			case 4:
				grdVisc = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPseudo_Input_Viscos_ViewModel : MMTabPageViewModel
	{
		public class grdVisc_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtTemp_temp_Property = CxvPropertyDeclaration.Register("txtTemp_temp", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.VITEMP.@vicid.@y"
			});

			public static readonly CxvPropertyDeclaration txtVisc_var1_Property = CxvPropertyDeclaration.Register("txtVisc_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.VISC.@vicid.@y"
			});

			public object txtTemp_temp => GetValue(txtTemp_temp_Property);

			public object txtVisc_var1 => GetValue(txtVisc_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraVisc_state_Property = CxvPropertyDeclaration.Register("fraVisc_state", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "vicid",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.Input.VITEMP.@vicid"
		});

		public static readonly CxvPropertyDeclaration lbtuVisc_var1_Property = CxvPropertyDeclaration.Register("lbtuVisc_var1", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.Input.VISC.@vicid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvParameterProperty
		{
			Parameter = "vicid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VICOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VICOMP", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VICOMP"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VISC2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VISC2", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VISC2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_VIOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VIOPT2", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.VIOPT2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Properties.Input.VITEMP",
			SelectedItemBinding = "MMMenuButton1_target.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMPseudo_Input_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
			CompletePaths = { "@main.Properties.CC Nodes.VICOMP", "@main.Properties.CC Nodes.VISC2" },
			EnteredPaths = { "@main.Properties.CC Nodes.VIOPT2" }
		});

		public static readonly CxvPropertyDeclaration grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdVisc_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Properties.Input.@indexVar.@vicid",
				UseChildId = true,
				Name = "y"
			},
			AllowCollectionChange = false
		});

		private EventHandler _maxCountDependencies_PropertyDependencyChangedHandler;

		private CxvPropertyWatch maxCountDependencies;

		public object fraVisc_state => GetValue(fraVisc_state_Property);

		public object lbtuTemp_var1 => GetValue(lbtuTemp_var1_Property);

		public object lbtuVisc_var1 => GetValue(lbtuVisc_var1_Property);

		public object MMMenuButton1_target => GetValue(MMMenuButton1_target_Property);

		public object MMMenuButton1_VICOMP => GetValue(MMMenuButton1_VICOMP_Property);

		public object MMMenuButton1_VISC2 => GetValue(MMMenuButton1_VISC2_Property);

		public object MMMenuButton1_VIOPT2 => GetValue(MMMenuButton1_VIOPT2_Property);

		public object MMMenuButton1_Selector => GetValue(MMMenuButton1_Selector_Property);

		public object grdVisc_GridData => GetValue(grdVisc_GridData_Property);

		private EventHandler maxCountDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_maxCountDependencies_PropertyDependencyChangedHandler == null)
				{
					_maxCountDependencies_PropertyDependencyChangedHandler = delegate
					{
						OnUpdateGridCount();
					};
				}
				return _maxCountDependencies_PropertyDependencyChangedHandler;
			}
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "MMMenuButton1_target" && subPropertyName == "Value" && MMMenuButton1_Selector is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData)
			{
				if (maxCountDependencies != null)
				{
					maxCountDependencies.PropertyDependencyChanged -= maxCountDependencies_PropertyDependencyChangedHandler;
				}
				if (maxCountDependencies != null)
				{
					maxCountDependencies.Clear();
				}
				else
				{
					maxCountDependencies = new CxvPropertyWatch();
				}
				string selectedItem = cxvAdvCollectionPropertyData.SelectedItem;
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VITEMP." + selectedItem, "child_count", null, maxCountDependencies));
				int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VISC." + selectedItem, "child_count", null, maxCountDependencies));
				if (!maxCountDependencies.IsEmpty)
				{
					maxCountDependencies.PropertyDependencyChanged += maxCountDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					maxCountDependencies = null;
				}
				if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
				{
					ResolveUpdateParameter("indexVar", "VISC");
				}
				else
				{
					ResolveUpdateParameter("indexVar", "VITEMP");
				}
			}
		}

		private void OnUpdateGridCount()
		{
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VITEMP.@vicid", "child_count", null, maxCountDependencies));
			int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.VISC.@vicid", "child_count", null, maxCountDependencies));
			if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
			{
				ResolveUpdateParameter("indexVar", "VISC");
			}
			else
			{
				ResolveUpdateParameter("indexVar", "VITEMP");
			}
		}
	}
	[ProgId("MMPseudo.MMPseudo_Input_Viscos")]
	public class MMPseudo_Input_Viscos : MMTabPage, IComponentConnector
	{
		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMGroupBox fraVisc;

		internal MMScrollArea grdVisc;

		private bool _contentLoaded;

		public MMPseudo_Input_Viscos()
		{
			base.ViewModelType = typeof(MMPseudo_Input_Viscos_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input_viscos.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 2:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraVisc = (MMGroupBox)target;
				break;
			case 4:
				grdVisc = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPseudo_Input_Water_ViewModel : MMTabPageViewModel
	{
		public class grdVisc_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtWaterSol_var1_Property = CxvPropertyDeclaration.Register("txtWaterSol_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.WSOL.@wscid.@y"
			});

			public static readonly CxvPropertyDeclaration txtTemp_var1_Property = CxvPropertyDeclaration.Register("txtTemp_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Properties.Input.MTEMP.@wscid.@y"
			});

			public object txtWaterSol_var1 => GetValue(txtWaterSol_var1_Property);

			public object txtTemp_var1 => GetValue(txtTemp_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraWater_state_Property = CxvPropertyDeclaration.Register("fraWater_state", typeof(MMPseudo_Input_Water_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "wscid",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.Input.MTEMP.@wscid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Water_ViewModel), new CxvParameterProperty
		{
			Parameter = "wscid"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_WSCOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_WSCOMP", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.WSCOMP"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_SOLU2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_SOLU2", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.SOLU2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_WSOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_WSOPT2", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Properties.CC Nodes.WSOPT2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Water_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Properties.Input.MTEMP",
			SelectedItemBinding = "MMMenuButton1_target.Value",
			CreateNewPrompt = "Component ID:",
			CreateNewPromptResourceKey = "MMPseudo_Input_Water_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
			CompletePaths = { "@main.Properties.CC Nodes.WSCOMP", "@main.Properties.CC Nodes.SOLU2" },
			EnteredPaths = { "@main.Properties.CC Nodes.WSOPT2" }
		});

		public static readonly CxvPropertyDeclaration grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Water_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdVisc_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Properties.Input.@indexVar.@wscid",
				UseChildId = true,
				Name = "y"
			},
			AllowCollectionChange = false
		});

		private EventHandler _maxCountDependencies_PropertyDependencyChangedHandler;

		private CxvPropertyWatch maxCountDependencies;

		public object fraWater_state => GetValue(fraWater_state_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMMenuButton1_target => GetValue(MMMenuButton1_target_Property);

		public object MMMenuButton1_WSCOMP => GetValue(MMMenuButton1_WSCOMP_Property);

		public object MMMenuButton1_SOLU2 => GetValue(MMMenuButton1_SOLU2_Property);

		public object MMMenuButton1_WSOPT2 => GetValue(MMMenuButton1_WSOPT2_Property);

		public object MMMenuButton1_Selector => GetValue(MMMenuButton1_Selector_Property);

		public object grdVisc_GridData => GetValue(grdVisc_GridData_Property);

		private EventHandler maxCountDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_maxCountDependencies_PropertyDependencyChangedHandler == null)
				{
					_maxCountDependencies_PropertyDependencyChangedHandler = delegate
					{
						OnUpdateGridCount();
					};
				}
				return _maxCountDependencies_PropertyDependencyChangedHandler;
			}
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "MMMenuButton1_target" && subPropertyName == "Value" && MMMenuButton1_Selector is CxvAdvCollectionPropertyData cxvAdvCollectionPropertyData)
			{
				if (maxCountDependencies != null)
				{
					maxCountDependencies.PropertyDependencyChanged -= maxCountDependencies_PropertyDependencyChangedHandler;
				}
				if (maxCountDependencies != null)
				{
					maxCountDependencies.Clear();
				}
				else
				{
					maxCountDependencies = new CxvPropertyWatch();
				}
				string selectedItem = cxvAdvCollectionPropertyData.SelectedItem;
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.MTEMP." + selectedItem, "child_count", null, maxCountDependencies));
				int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.WSOL." + selectedItem, "child_count", null, maxCountDependencies));
				if (!maxCountDependencies.IsEmpty)
				{
					maxCountDependencies.PropertyDependencyChanged += maxCountDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					maxCountDependencies = null;
				}
				if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
				{
					ResolveUpdateParameter("indexVar", "WSOL");
				}
				else
				{
					ResolveUpdateParameter("indexVar", "MTEMP");
				}
			}
		}

		private void OnUpdateGridCount()
		{
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.MTEMP.@wscid", "child_count", null, maxCountDependencies));
			int? num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Properties.Input.WSOL.@wscid", "child_count", null, maxCountDependencies));
			if ((num.HasValue && num2.HasValue && num.Value < num2.Value) || (!num.HasValue && num2.HasValue))
			{
				ResolveUpdateParameter("indexVar", "WSOL");
			}
			else
			{
				ResolveUpdateParameter("indexVar", "MTEMP");
			}
		}
	}
	[ProgId("MMPseudo.MMPseudo_Input_Water")]
	public class MMPseudo_Input_Water : MMTabPage, IComponentConnector
	{
		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMGroupBox fraWater;

		internal MMScrollArea grdVisc;

		private bool _contentLoaded;

		public MMPseudo_Input_Water()
		{
			base.ViewModelType = typeof(MMPseudo_Input_Water_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/pseudocomponents/mmpseudo_input_water.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 2:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraWater = (MMGroupBox)target;
				break;
			case 4:
				grdVisc = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.Polymers
{
	public class MMPolymers_Charact_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration CCSeg_Property = CxvPropertyDeclaration.Register("CCSeg", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SEGS"
		});

		public static readonly CxvPropertyDeclaration CCPolym_Property = CxvPropertyDeclaration.Register("CCPolym", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CATTS"
		});

		public static readonly CxvPropertyDeclaration CCOlig_Property = CxvPropertyDeclaration.Register("CCOlig", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.OLID"
		});

		public static readonly CxvPropertyDeclaration CCAtt_Property = CxvPropertyDeclaration.Register("CCAtt", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CAID"
		});

		public static readonly CxvPropertyDeclaration ENOlig_Property = CxvPropertyDeclaration.Register("ENOlig", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EXOLI"
		});

		public static readonly CxvPropertyDeclaration ENPol_Property = CxvPropertyDeclaration.Register("ENPol", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EXPOL"
		});

		public static readonly CxvPropertyDeclaration POLYCOM_Property = CxvPropertyDeclaration.Register("POLYCOM", typeof(MMPolymers_Charact_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYCOM"
		});

		public static readonly CxvPropertyDeclaration ENTOli_Property = CxvPropertyDeclaration.Register("ENTOli", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTOLI"
		});

		public static readonly CxvPropertyDeclaration ENTCat_Property = CxvPropertyDeclaration.Register("ENTCat", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCAT"
		});

		public static readonly CxvPropertyDeclaration OLIGD_Property = CxvPropertyDeclaration.Register("OLIGD", typeof(MMPolymers_Charact_ViewModel), new CxvParameterProperty
		{
			Parameter = "OLIGD"
		});

		public static readonly CxvPropertyDeclaration OLIG_Property = CxvPropertyDeclaration.Register("OLIG", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTPOL"
		});

		public static readonly CxvPropertyDeclaration CCSUB_Property = CxvPropertyDeclaration.Register("CCSUB", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CATTS.@POLYCOM"
		});

		public static readonly CxvPropertyDeclaration CCSUBC_Property = CxvPropertyDeclaration.Register("CCSUBC", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CAID.@CATID"
		});

		public static readonly CxvPropertyDeclaration ACCSEGD_Property = CxvPropertyDeclaration.Register("ACCSEGD", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ACCSEGD"
		});

		public static readonly CxvPropertyDeclaration ENTOpti_Property = CxvPropertyDeclaration.Register("ENTOpti", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTOPTI"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCSeg" },
			AccessibleDataPaths = { "@ACCSEGD" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCPolym" },
			AccessibleDataPaths = { "@ENPol" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCOlig" },
			AccessibleDataPaths = { "@ACCSEGD" },
			EnteredDataPaths = { "@ENTOli" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCAtt" },
			AccessibleDataPaths = { "@ENPol" },
			EnteredDataPaths = { "@ENTCat" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ENTOpti" }
		});

		public object CCSeg => GetValue(CCSeg_Property);

		public object CCPolym => GetValue(CCPolym_Property);

		public object CCOlig => GetValue(CCOlig_Property);

		public object CCAtt => GetValue(CCAtt_Property);

		public object ENOlig => GetValue(ENOlig_Property);

		public object ENPol => GetValue(ENPol_Property);

		public object POLYCOM => GetValue(POLYCOM_Property);

		public object ENTOli => GetValue(ENTOli_Property);

		public object ENTCat => GetValue(ENTCat_Property);

		public object OLIGD => GetValue(OLIGD_Property);

		public object OLIG => GetValue(OLIG_Property);

		public object CCSUB => GetValue(CCSUB_Property);

		public object CCSUBC => GetValue(CCSUBC_Property);

		public object ACCSEGD => GetValue(ACCSEGD_Property);

		public object ENTOpti => GetValue(ENTOpti_Property);

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
				ResolveUpdateParameter("NotNeedName", "NotNull");
				ResolveUpdateParameter("NotNeedType", "NotNull");
			}
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact")]
	public class MMPolymers_Charact : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPolymer;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPolymers_Charact()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabPolymer = (MMTabStrip)target;
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
	public class MMPolymers_Charact_Attrib_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdDone_Command;

		public static readonly CxvPropertyDeclaration lcbPolymer_PolValue_Property = CxvPropertyDeclaration.Register("lcbPolymer_PolValue", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "PolValue"
		});

		public static readonly CxvPropertyDeclaration chklPolAtt_var1_Property = CxvPropertyDeclaration.Register("chklPolAtt_var1", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.ATT_LISTP.@POLYCOM"
		});

		public static readonly CxvPropertyDeclaration lcbPolymer_var2_Property = CxvPropertyDeclaration.Register("lcbPolymer_var2", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYCOM",
			IsReadOnly = true
		});

		private readonly List<string> _initialCheckedNames = new List<string>();

		private readonly Dictionary<string, string> _valueOptions = new Dictionary<string, string>
		{
			{ "mmtogval0", "SFLOW" },
			{ "mmtogval1", "SFRAC" },
			{ "mmtogval2", "EFRAC" },
			{ "mmtogval3", "DPN" },
			{ "mmtogval4", "DPW" },
			{ "mmtogval5", "DPZ" },
			{ "mmtogval6", "PDI" },
			{ "mmtogval7", "MWN" },
			{ "mmtogval8", "MWW" },
			{ "mmtogval9", "MWZ" },
			{ "mmtogval10", "MWSEG" },
			{ "mmtogval11", "ZMOM" },
			{ "mmtogval12", "FMOM" },
			{ "mmtogval13", "SMOM" },
			{ "mmtogval14", "TMOM" },
			{ "mmtogval15", "LCB" },
			{ "mmtogval16", "SCB" },
			{ "mmtogval17", "FLCB" },
			{ "mmtogval18", "FSCB" },
			{ "mmtogval19", "PDV" },
			{ "mmtogval20", "PSDZMOM" },
			{ "mmtogval21", "PSDFMOM" },
			{ "mmtogval22", "PSDSMOM" },
			{ "mmtogval23", "PSDTMOM" },
			{ "mmtogval24", "VOLN" },
			{ "mmtogval25", "VOLV" },
			{ "mmtogval26", "VOLZ" },
			{ "mmtogval27", "DIAV" },
			{ "mmtogval28", "ATFLOW" },
			{ "mmtogval29", "ATFRAC" },
			{ "mmtogval30", "DYADFLOW" },
			{ "mmtogval31", "DYADFRAC" },
			{ "mmtogval32", "BLOCKN" },
			{ "mmtogval33", "HTHFLOW" },
			{ "mmtogval34", "HTHFRAC" },
			{ "mmtogval35", "CIS-FLOW" },
			{ "mmtogval36", "CIS-FRAC" },
			{ "mmtogval37", "TRANSFLO" },
			{ "mmtogval38", "TRANSFRA" },
			{ "mmtogval39", "VINYLFRA" },
			{ "mmtogval40", "TDBFLOW" },
			{ "mmtogval41", "TDBFRAC" },
			{ "mmtogval42", "XFLOW" },
			{ "mmtogval43", "XDENSITY" },
			{ "mmtogval44", "FRAGFLOW" },
			{ "mmtogval45", "LSFLOW" },
			{ "mmtogval46", "LSFRAC" },
			{ "mmtogval47", "LEFLOW" },
			{ "mmtogval48", "LEFRAC" },
			{ "mmtogval49", "LDPN" },
			{ "mmtogval50", "LDPW" },
			{ "mmtogval51", "LPDI" },
			{ "mmtogval52", "LMWN" },
			{ "mmtogval53", "LMWW" },
			{ "mmtogval54", "LMWSEG" },
			{ "mmtogval55", "LZMOM" },
			{ "mmtogval56", "LFMOM" },
			{ "mmtogval57", "LSMOM" },
			{ "mmtogval58", "LPFRAC" },
			{ "mmtogval59", "SSFLOW" },
			{ "mmtogval60", "SSFRAC" },
			{ "mmtogval61", "SEFRAC" },
			{ "mmtogval62", "SDPN" },
			{ "mmtogval63", "SDPW" },
			{ "mmtogval64", "SDPZ" },
			{ "mmtogval65", "SPDI" },
			{ "mmtogval66", "SMWN" },
			{ "mmtogval67", "SMWW" },
			{ "mmtogval68", "SMWZ" },
			{ "mmtogval69", "SMWSEG" },
			{ "mmtogval70", "SZMOM" },
			{ "mmtogval71", "SFMOM" },
			{ "mmtogval72", "SSMOM" },
			{ "mmtogval73", "STMOM" },
			{ "mmtogval74", "SLCB" },
			{ "mmtogval75", "SSCB" },
			{ "mmtogval76", "SFLCB" },
			{ "mmtogval77", "SFSCB" },
			{ "mmtogval78", "SPFRAC" },
			{ "mmtogval79", "SATFLOW" },
			{ "mmtogval80", "SATFRAC" },
			{ "mmtogval81", "SHTHFLOW" },
			{ "mmtogval82", "SHTHFRAC" },
			{ "mmtogval83", "STDBFLOW" },
			{ "mmtogval84", "STDBFRAC" },
			{ "mmtogval85", "LSSFLOW" },
			{ "mmtogval86", "LSSFRAC" },
			{ "mmtogval87", "LSEFLOW" },
			{ "mmtogval88", "LSEFRAC" },
			{ "mmtogval89", "LSDPN" },
			{ "mmtogval90", "LSDPW" },
			{ "mmtogval91", "LSPDI" },
			{ "mmtogval92", "LSMWN" },
			{ "mmtogval93", "LSMWW" },
			{ "mmtogval94", "LSMWSEG" },
			{ "mmtogval95", "LSZMOM" },
			{ "mmtogval96", "LSFMOM" },
			{ "mmtogval97", "LSSMOM" },
			{ "mmtogval98", "LSTMOM" },
			{ "mmtogval99", "LSPFRAC" },
			{ "mmtogval100", "ASFLOW" },
			{ "mmtogval101", "ASFRAC" },
			{ "mmtogval102", "AEFLOW" },
			{ "mmtogval103", "AEFRAC" },
			{ "mmtogval104", "ADPN" },
			{ "mmtogval105", "ADPW" },
			{ "mmtogval106", "APDI" },
			{ "mmtogval107", "AMWN" },
			{ "mmtogval108", "AMWW" },
			{ "mmtogval109", "AMWSEG" },
			{ "mmtogval110", "AZMOM" },
			{ "mmtogval111", "AFMOM" },
			{ "mmtogval112", "ASMOM" },
			{ "mmtogval113", "APFRAC" },
			{ "mmtogval114", "ASSFLOW" },
			{ "mmtogval115", "ASSFRAC" },
			{ "mmtogval116", "ASEFLOW" },
			{ "mmtogval117", "ASEFRAC" },
			{ "mmtogval118", "ASDPN" },
			{ "mmtogval119", "ASDPW" },
			{ "mmtogval120", "ASPDI" },
			{ "mmtogval121", "ASMWN" },
			{ "mmtogval122", "ASMWW" },
			{ "mmtogval123", "ASMWSEG" },
			{ "mmtogval124", "ASZMOM" },
			{ "mmtogval125", "ASFMOM" },
			{ "mmtogval126", "ASSMOM" },
			{ "mmtogval127", "ASTMOM" },
			{ "mmtogval128", "ASPFRAC" },
			{ "mmtogval129", "DSEFLOW" },
			{ "mmtogval130", "DSSFLOW" },
			{ "mmtogval131", "DSSMOM" },
			{ "mmtogval132", "DSTMOM" },
			{ "mmtogval133", "CACLASS0" },
			{ "mmtogval134", "CAUSR1" },
			{ "mmtogval135", "CAUSR2" },
			{ "mmtogval136", "CAUSR3" },
			{ "mmtogval137", "CAUSR4" },
			{ "mmtogval138", "CAUSR5" },
			{ "mmtogval139", "CAUSRA" },
			{ "mmtogval140", "CAUSRB" },
			{ "mmtogval141", "CAUSRC" },
			{ "mmtogval142", "CAUSRD" },
			{ "mmtogval143", "CAUSRE" },
			{ "mmtogval144", "ZECR" },
			{ "mmtogval145", "FECR" },
			{ "mmtogval146", "SECR" },
			{ "mmtogval147", "ZMCR" },
			{ "mmtogval148", "FMCR" },
			{ "mmtogval149", "SMCR" },
			{ "mmtogval150", "ZSCR" },
			{ "mmtogval151", "FSCR" },
			{ "mmtogval152", "SSCR" }
		};

		public ICommand cmdDone_Command
		{
			get
			{
				if (_cmdDone_Command == null)
				{
					_cmdDone_Command = new CxvDelegateCommand<object>(cmdDone_CommandExecute);
				}
				return _cmdDone_Command;
			}
		}

		public object lcbPolymer_PolValue => GetValue(lcbPolymer_PolValue_Property);

		public object chklPolAtt_var1 => GetValue(chklPolAtt_var1_Property);

		public object lcbPolymer_var2 => GetValue(lcbPolymer_var2_Property);

		private void cmdDone_CommandExecute(object parameter)
		{
			Done(closeForm: true);
		}

		internal void Done(bool closeForm)
		{
			List<string> list = new List<string>();
			if (base.View is MMPolymers_Charact_Attrib mMPolymers_Charact_Attrib)
			{
				StackPanel stackPanel = null;
				if (mMPolymers_Charact_Attrib.fraAttrList.Content is ScrollViewer scrollViewer)
				{
					stackPanel = scrollViewer.Content as StackPanel;
				}
				foreach (object child in stackPanel.Children)
				{
					if (child is MMCheckBox { IsChecked: not null, IsChecked: var isChecked } mMCheckBox && isChecked.Value)
					{
						list.Add(mMCheckBox.Name);
					}
				}
			}
			List<string> list2 = new List<string>();
			List<string> list3 = new List<string>();
			foreach (string initialCheckedName in _initialCheckedNames)
			{
				if (!list.Contains(initialCheckedName))
				{
					list2.Add(initialCheckedName);
				}
			}
			foreach (string item in list)
			{
				if (!_initialCheckedNames.Contains(item))
				{
					list3.Add(item);
				}
			}
			if (list2.Count == 0 && list3.Count == 0)
			{
				if (closeForm)
				{
					CloseForm();
				}
				return;
			}
			int currentIdIndex = 0;
			Collection<string> childIDs = GetChildIDs();
			if (childIDs != null && childIDs.Count > 0)
			{
				string text = childIDs[childIDs.Count - 1];
				if (text.StartsWith("#", StringComparison.Ordinal))
				{
					currentIdIndex = int.Parse(text.Substring(1)) + 1;
				}
			}
			if (list2.Count == 0 && list3.Count != 0)
			{
				base.ResolvedCxsProvider.BatchSet(new CxsBatchRequestData(list3.Select((string name) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTP.@POLYCOM.#" + currentIdIndex++), "value", null, _valueOptions[name]))));
			}
			else if (list2.Count != 0 && list3.Count == 0)
			{
				List<string> childValues = GetChildValues();
				IEnumerable<int> rows = list2.Select((string name) => childValues.IndexOf(_valueOptions[name]));
				DeleteChildren("@main.Input.ATT_LISTP.@POLYCOM", rows, null, silently: true);
			}
			else if (list2.Count != 0 && list3.Count != 0)
			{
				List<string> childValues2 = GetChildValues();
				IEnumerable<int> rows2 = list2.Select((string name) => childValues2.IndexOf(_valueOptions[name]));
				DeleteChildren("@main.Input.ATT_LISTP.@POLYCOM", rows2, null, silently: true);
				currentIdIndex -= list2.Count;
				base.ResolvedCxsProvider.BatchSet(new CxsBatchRequestData(list3.Select((string name) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTP.@POLYCOM.#" + currentIdIndex++), "value", null, _valueOptions[name]))));
			}
			if (!string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.CAT_GROUP.@POLYCOM", "value"))))
			{
				ExpandDataPathAndSet("@main.Input.MODIFIED.@POLYCOM", "value", "YES");
			}
			if (closeForm)
			{
				CloseForm();
				return;
			}
			_initialCheckedNames.Clear();
			_initialCheckedNames.AddRange(list);
		}

		private Collection<string> GetChildIDs()
		{
			return CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.ATT_LISTP.@POLYCOM", "child_ids"));
		}

		private List<string> GetChildValues()
		{
			List<string> list = new List<string>();
			Collection<string> childIDs = GetChildIDs();
			if (childIDs != null && childIDs.Count > 0)
			{
				object[] array = base.ResolvedCxsProvider.BatchGet(new CxsBatchRequestData(childIDs.Select((string id) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTP.@POLYCOM." + id), "value"))));
				if (array != null && array.Length != 0)
				{
					IEnumerable<string> enumerable = array.Cast<string>();
					if (enumerable != null)
					{
						list.AddRange(enumerable.ToList());
					}
				}
			}
			return list;
		}

		protected override void OnViewChanged()
		{
			base.OnViewChanged();
			if (!(base.View is MMPolymers_Charact_Attrib mMPolymers_Charact_Attrib))
			{
				return;
			}
			List<string> childValues = GetChildValues();
			if (childValues == null || childValues.Count() <= 0)
			{
				return;
			}
			StackPanel stackPanel = null;
			if (mMPolymers_Charact_Attrib.fraAttrList.Content is ScrollViewer scrollViewer)
			{
				stackPanel = scrollViewer.Content as StackPanel;
			}
			if (stackPanel == null)
			{
				return;
			}
			foreach (object child in stackPanel.Children)
			{
				if (child is MMCheckBox mMCheckBox && childValues.Contains(_valueOptions[mMCheckBox.Name]))
				{
					mMCheckBox.IsChecked = true;
					_initialCheckedNames.Add(mMCheckBox.Name);
				}
			}
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Attrib")]
	public class MMPolymers_Charact_Attrib : MMTabPage, IComponentConnector
	{
		internal MMLabel lblAttrList;

		internal MMValueEdit lcbPolymer;

		internal MMGroupBox fraAttrList;

		internal MMCheckBox mmtogval0;

		internal MMCheckBox mmtogval1;

		internal MMCheckBox mmtogval2;

		internal MMCheckBox mmtogval3;

		internal MMCheckBox mmtogval4;

		internal MMCheckBox mmtogval5;

		internal MMCheckBox mmtogval6;

		internal MMCheckBox mmtogval7;

		internal MMCheckBox mmtogval8;

		internal MMCheckBox mmtogval9;

		internal MMCheckBox mmtogval10;

		internal MMCheckBox mmtogval11;

		internal MMCheckBox mmtogval12;

		internal MMCheckBox mmtogval13;

		internal MMCheckBox mmtogval14;

		internal MMCheckBox mmtogval15;

		internal MMCheckBox mmtogval16;

		internal MMCheckBox mmtogval17;

		internal MMCheckBox mmtogval18;

		internal MMCheckBox mmtogval19;

		internal MMCheckBox mmtogval20;

		internal MMCheckBox mmtogval21;

		internal MMCheckBox mmtogval22;

		internal MMCheckBox mmtogval23;

		internal MMCheckBox mmtogval24;

		internal MMCheckBox mmtogval25;

		internal MMCheckBox mmtogval26;

		internal MMCheckBox mmtogval27;

		internal MMCheckBox mmtogval28;

		internal MMCheckBox mmtogval29;

		internal MMCheckBox mmtogval30;

		internal MMCheckBox mmtogval31;

		internal MMCheckBox mmtogval32;

		internal MMCheckBox mmtogval33;

		internal MMCheckBox mmtogval34;

		internal MMCheckBox mmtogval35;

		internal MMCheckBox mmtogval36;

		internal MMCheckBox mmtogval37;

		internal MMCheckBox mmtogval38;

		internal MMCheckBox mmtogval39;

		internal MMCheckBox mmtogval40;

		internal MMCheckBox mmtogval41;

		internal MMCheckBox mmtogval42;

		internal MMCheckBox mmtogval43;

		internal MMCheckBox mmtogval44;

		internal MMCheckBox mmtogval45;

		internal MMCheckBox mmtogval46;

		internal MMCheckBox mmtogval47;

		internal MMCheckBox mmtogval48;

		internal MMCheckBox mmtogval49;

		internal MMCheckBox mmtogval50;

		internal MMCheckBox mmtogval51;

		internal MMCheckBox mmtogval52;

		internal MMCheckBox mmtogval53;

		internal MMCheckBox mmtogval54;

		internal MMCheckBox mmtogval55;

		internal MMCheckBox mmtogval56;

		internal MMCheckBox mmtogval57;

		internal MMCheckBox mmtogval58;

		internal MMCheckBox mmtogval59;

		internal MMCheckBox mmtogval60;

		internal MMCheckBox mmtogval61;

		internal MMCheckBox mmtogval62;

		internal MMCheckBox mmtogval63;

		internal MMCheckBox mmtogval64;

		internal MMCheckBox mmtogval65;

		internal MMCheckBox mmtogval66;

		internal MMCheckBox mmtogval67;

		internal MMCheckBox mmtogval68;

		internal MMCheckBox mmtogval69;

		internal MMCheckBox mmtogval70;

		internal MMCheckBox mmtogval71;

		internal MMCheckBox mmtogval72;

		internal MMCheckBox mmtogval73;

		internal MMCheckBox mmtogval74;

		internal MMCheckBox mmtogval75;

		internal MMCheckBox mmtogval76;

		internal MMCheckBox mmtogval77;

		internal MMCheckBox mmtogval78;

		internal MMCheckBox mmtogval79;

		internal MMCheckBox mmtogval80;

		internal MMCheckBox mmtogval81;

		internal MMCheckBox mmtogval82;

		internal MMCheckBox mmtogval83;

		internal MMCheckBox mmtogval84;

		internal MMCheckBox mmtogval85;

		internal MMCheckBox mmtogval86;

		internal MMCheckBox mmtogval87;

		internal MMCheckBox mmtogval88;

		internal MMCheckBox mmtogval89;

		internal MMCheckBox mmtogval90;

		internal MMCheckBox mmtogval91;

		internal MMCheckBox mmtogval92;

		internal MMCheckBox mmtogval93;

		internal MMCheckBox mmtogval94;

		internal MMCheckBox mmtogval95;

		internal MMCheckBox mmtogval96;

		internal MMCheckBox mmtogval97;

		internal MMCheckBox mmtogval98;

		internal MMCheckBox mmtogval99;

		internal MMCheckBox mmtogval100;

		internal MMCheckBox mmtogval101;

		internal MMCheckBox mmtogval102;

		internal MMCheckBox mmtogval103;

		internal MMCheckBox mmtogval104;

		internal MMCheckBox mmtogval105;

		internal MMCheckBox mmtogval106;

		internal MMCheckBox mmtogval107;

		internal MMCheckBox mmtogval108;

		internal MMCheckBox mmtogval109;

		internal MMCheckBox mmtogval110;

		internal MMCheckBox mmtogval111;

		internal MMCheckBox mmtogval112;

		internal MMCheckBox mmtogval113;

		internal MMCheckBox mmtogval114;

		internal MMCheckBox mmtogval115;

		internal MMCheckBox mmtogval116;

		internal MMCheckBox mmtogval117;

		internal MMCheckBox mmtogval118;

		internal MMCheckBox mmtogval119;

		internal MMCheckBox mmtogval120;

		internal MMCheckBox mmtogval121;

		internal MMCheckBox mmtogval122;

		internal MMCheckBox mmtogval123;

		internal MMCheckBox mmtogval124;

		internal MMCheckBox mmtogval125;

		internal MMCheckBox mmtogval126;

		internal MMCheckBox mmtogval127;

		internal MMCheckBox mmtogval128;

		internal MMCheckBox mmtogval129;

		internal MMCheckBox mmtogval130;

		internal MMCheckBox mmtogval131;

		internal MMCheckBox mmtogval132;

		internal MMCheckBox mmtogval133;

		internal MMCheckBox mmtogval134;

		internal MMCheckBox mmtogval135;

		internal MMCheckBox mmtogval136;

		internal MMCheckBox mmtogval137;

		internal MMCheckBox mmtogval138;

		internal MMCheckBox mmtogval139;

		internal MMCheckBox mmtogval140;

		internal MMCheckBox mmtogval141;

		internal MMCheckBox mmtogval142;

		internal MMCheckBox mmtogval143;

		internal MMCheckBox mmtogval144;

		internal MMCheckBox mmtogval145;

		internal MMCheckBox mmtogval146;

		internal MMCheckBox mmtogval147;

		internal MMCheckBox mmtogval148;

		internal MMCheckBox mmtogval149;

		internal MMCheckBox mmtogval150;

		internal MMCheckBox mmtogval151;

		internal MMCheckBox mmtogval152;

		internal MMNextButton btnnext;

		internal MMCmdButton cmdDone;

		private bool _contentLoaded;

		public MMPolymers_Charact_Attrib()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Attrib_ViewModel);
			InitializeComponent();
		}

		private void btnnext_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			if (base.ViewModel is MMPolymers_Charact_Attrib_ViewModel mMPolymers_Charact_Attrib_ViewModel)
			{
				mMPolymers_Charact_Attrib_ViewModel.Done(closeForm: false);
				OnNextButtonClicked();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_attrib.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblAttrList = (MMLabel)target;
				break;
			case 2:
				lcbPolymer = (MMValueEdit)target;
				break;
			case 3:
				fraAttrList = (MMGroupBox)target;
				break;
			case 4:
				mmtogval0 = (MMCheckBox)target;
				break;
			case 5:
				mmtogval1 = (MMCheckBox)target;
				break;
			case 6:
				mmtogval2 = (MMCheckBox)target;
				break;
			case 7:
				mmtogval3 = (MMCheckBox)target;
				break;
			case 8:
				mmtogval4 = (MMCheckBox)target;
				break;
			case 9:
				mmtogval5 = (MMCheckBox)target;
				break;
			case 10:
				mmtogval6 = (MMCheckBox)target;
				break;
			case 11:
				mmtogval7 = (MMCheckBox)target;
				break;
			case 12:
				mmtogval8 = (MMCheckBox)target;
				break;
			case 13:
				mmtogval9 = (MMCheckBox)target;
				break;
			case 14:
				mmtogval10 = (MMCheckBox)target;
				break;
			case 15:
				mmtogval11 = (MMCheckBox)target;
				break;
			case 16:
				mmtogval12 = (MMCheckBox)target;
				break;
			case 17:
				mmtogval13 = (MMCheckBox)target;
				break;
			case 18:
				mmtogval14 = (MMCheckBox)target;
				break;
			case 19:
				mmtogval15 = (MMCheckBox)target;
				break;
			case 20:
				mmtogval16 = (MMCheckBox)target;
				break;
			case 21:
				mmtogval17 = (MMCheckBox)target;
				break;
			case 22:
				mmtogval18 = (MMCheckBox)target;
				break;
			case 23:
				mmtogval19 = (MMCheckBox)target;
				break;
			case 24:
				mmtogval20 = (MMCheckBox)target;
				break;
			case 25:
				mmtogval21 = (MMCheckBox)target;
				break;
			case 26:
				mmtogval22 = (MMCheckBox)target;
				break;
			case 27:
				mmtogval23 = (MMCheckBox)target;
				break;
			case 28:
				mmtogval24 = (MMCheckBox)target;
				break;
			case 29:
				mmtogval25 = (MMCheckBox)target;
				break;
			case 30:
				mmtogval26 = (MMCheckBox)target;
				break;
			case 31:
				mmtogval27 = (MMCheckBox)target;
				break;
			case 32:
				mmtogval28 = (MMCheckBox)target;
				break;
			case 33:
				mmtogval29 = (MMCheckBox)target;
				break;
			case 34:
				mmtogval30 = (MMCheckBox)target;
				break;
			case 35:
				mmtogval31 = (MMCheckBox)target;
				break;
			case 36:
				mmtogval32 = (MMCheckBox)target;
				break;
			case 37:
				mmtogval33 = (MMCheckBox)target;
				break;
			case 38:
				mmtogval34 = (MMCheckBox)target;
				break;
			case 39:
				mmtogval35 = (MMCheckBox)target;
				break;
			case 40:
				mmtogval36 = (MMCheckBox)target;
				break;
			case 41:
				mmtogval37 = (MMCheckBox)target;
				break;
			case 42:
				mmtogval38 = (MMCheckBox)target;
				break;
			case 43:
				mmtogval39 = (MMCheckBox)target;
				break;
			case 44:
				mmtogval40 = (MMCheckBox)target;
				break;
			case 45:
				mmtogval41 = (MMCheckBox)target;
				break;
			case 46:
				mmtogval42 = (MMCheckBox)target;
				break;
			case 47:
				mmtogval43 = (MMCheckBox)target;
				break;
			case 48:
				mmtogval44 = (MMCheckBox)target;
				break;
			case 49:
				mmtogval45 = (MMCheckBox)target;
				break;
			case 50:
				mmtogval46 = (MMCheckBox)target;
				break;
			case 51:
				mmtogval47 = (MMCheckBox)target;
				break;
			case 52:
				mmtogval48 = (MMCheckBox)target;
				break;
			case 53:
				mmtogval49 = (MMCheckBox)target;
				break;
			case 54:
				mmtogval50 = (MMCheckBox)target;
				break;
			case 55:
				mmtogval51 = (MMCheckBox)target;
				break;
			case 56:
				mmtogval52 = (MMCheckBox)target;
				break;
			case 57:
				mmtogval53 = (MMCheckBox)target;
				break;
			case 58:
				mmtogval54 = (MMCheckBox)target;
				break;
			case 59:
				mmtogval55 = (MMCheckBox)target;
				break;
			case 60:
				mmtogval56 = (MMCheckBox)target;
				break;
			case 61:
				mmtogval57 = (MMCheckBox)target;
				break;
			case 62:
				mmtogval58 = (MMCheckBox)target;
				break;
			case 63:
				mmtogval59 = (MMCheckBox)target;
				break;
			case 64:
				mmtogval60 = (MMCheckBox)target;
				break;
			case 65:
				mmtogval61 = (MMCheckBox)target;
				break;
			case 66:
				mmtogval62 = (MMCheckBox)target;
				break;
			case 67:
				mmtogval63 = (MMCheckBox)target;
				break;
			case 68:
				mmtogval64 = (MMCheckBox)target;
				break;
			case 69:
				mmtogval65 = (MMCheckBox)target;
				break;
			case 70:
				mmtogval66 = (MMCheckBox)target;
				break;
			case 71:
				mmtogval67 = (MMCheckBox)target;
				break;
			case 72:
				mmtogval68 = (MMCheckBox)target;
				break;
			case 73:
				mmtogval69 = (MMCheckBox)target;
				break;
			case 74:
				mmtogval70 = (MMCheckBox)target;
				break;
			case 75:
				mmtogval71 = (MMCheckBox)target;
				break;
			case 76:
				mmtogval72 = (MMCheckBox)target;
				break;
			case 77:
				mmtogval73 = (MMCheckBox)target;
				break;
			case 78:
				mmtogval74 = (MMCheckBox)target;
				break;
			case 79:
				mmtogval75 = (MMCheckBox)target;
				break;
			case 80:
				mmtogval76 = (MMCheckBox)target;
				break;
			case 81:
				mmtogval77 = (MMCheckBox)target;
				break;
			case 82:
				mmtogval78 = (MMCheckBox)target;
				break;
			case 83:
				mmtogval79 = (MMCheckBox)target;
				break;
			case 84:
				mmtogval80 = (MMCheckBox)target;
				break;
			case 85:
				mmtogval81 = (MMCheckBox)target;
				break;
			case 86:
				mmtogval82 = (MMCheckBox)target;
				break;
			case 87:
				mmtogval83 = (MMCheckBox)target;
				break;
			case 88:
				mmtogval84 = (MMCheckBox)target;
				break;
			case 89:
				mmtogval85 = (MMCheckBox)target;
				break;
			case 90:
				mmtogval86 = (MMCheckBox)target;
				break;
			case 91:
				mmtogval87 = (MMCheckBox)target;
				break;
			case 92:
				mmtogval88 = (MMCheckBox)target;
				break;
			case 93:
				mmtogval89 = (MMCheckBox)target;
				break;
			case 94:
				mmtogval90 = (MMCheckBox)target;
				break;
			case 95:
				mmtogval91 = (MMCheckBox)target;
				break;
			case 96:
				mmtogval92 = (MMCheckBox)target;
				break;
			case 97:
				mmtogval93 = (MMCheckBox)target;
				break;
			case 98:
				mmtogval94 = (MMCheckBox)target;
				break;
			case 99:
				mmtogval95 = (MMCheckBox)target;
				break;
			case 100:
				mmtogval96 = (MMCheckBox)target;
				break;
			case 101:
				mmtogval97 = (MMCheckBox)target;
				break;
			case 102:
				mmtogval98 = (MMCheckBox)target;
				break;
			case 103:
				mmtogval99 = (MMCheckBox)target;
				break;
			case 104:
				mmtogval100 = (MMCheckBox)target;
				break;
			case 105:
				mmtogval101 = (MMCheckBox)target;
				break;
			case 106:
				mmtogval102 = (MMCheckBox)target;
				break;
			case 107:
				mmtogval103 = (MMCheckBox)target;
				break;
			case 108:
				mmtogval104 = (MMCheckBox)target;
				break;
			case 109:
				mmtogval105 = (MMCheckBox)target;
				break;
			case 110:
				mmtogval106 = (MMCheckBox)target;
				break;
			case 111:
				mmtogval107 = (MMCheckBox)target;
				break;
			case 112:
				mmtogval108 = (MMCheckBox)target;
				break;
			case 113:
				mmtogval109 = (MMCheckBox)target;
				break;
			case 114:
				mmtogval110 = (MMCheckBox)target;
				break;
			case 115:
				mmtogval111 = (MMCheckBox)target;
				break;
			case 116:
				mmtogval112 = (MMCheckBox)target;
				break;
			case 117:
				mmtogval113 = (MMCheckBox)target;
				break;
			case 118:
				mmtogval114 = (MMCheckBox)target;
				break;
			case 119:
				mmtogval115 = (MMCheckBox)target;
				break;
			case 120:
				mmtogval116 = (MMCheckBox)target;
				break;
			case 121:
				mmtogval117 = (MMCheckBox)target;
				break;
			case 122:
				mmtogval118 = (MMCheckBox)target;
				break;
			case 123:
				mmtogval119 = (MMCheckBox)target;
				break;
			case 124:
				mmtogval120 = (MMCheckBox)target;
				break;
			case 125:
				mmtogval121 = (MMCheckBox)target;
				break;
			case 126:
				mmtogval122 = (MMCheckBox)target;
				break;
			case 127:
				mmtogval123 = (MMCheckBox)target;
				break;
			case 128:
				mmtogval124 = (MMCheckBox)target;
				break;
			case 129:
				mmtogval125 = (MMCheckBox)target;
				break;
			case 130:
				mmtogval126 = (MMCheckBox)target;
				break;
			case 131:
				mmtogval127 = (MMCheckBox)target;
				break;
			case 132:
				mmtogval128 = (MMCheckBox)target;
				break;
			case 133:
				mmtogval129 = (MMCheckBox)target;
				break;
			case 134:
				mmtogval130 = (MMCheckBox)target;
				break;
			case 135:
				mmtogval131 = (MMCheckBox)target;
				break;
			case 136:
				mmtogval132 = (MMCheckBox)target;
				break;
			case 137:
				mmtogval133 = (MMCheckBox)target;
				break;
			case 138:
				mmtogval134 = (MMCheckBox)target;
				break;
			case 139:
				mmtogval135 = (MMCheckBox)target;
				break;
			case 140:
				mmtogval136 = (MMCheckBox)target;
				break;
			case 141:
				mmtogval137 = (MMCheckBox)target;
				break;
			case 142:
				mmtogval138 = (MMCheckBox)target;
				break;
			case 143:
				mmtogval139 = (MMCheckBox)target;
				break;
			case 144:
				mmtogval140 = (MMCheckBox)target;
				break;
			case 145:
				mmtogval141 = (MMCheckBox)target;
				break;
			case 146:
				mmtogval142 = (MMCheckBox)target;
				break;
			case 147:
				mmtogval143 = (MMCheckBox)target;
				break;
			case 148:
				mmtogval144 = (MMCheckBox)target;
				break;
			case 149:
				mmtogval145 = (MMCheckBox)target;
				break;
			case 150:
				mmtogval146 = (MMCheckBox)target;
				break;
			case 151:
				mmtogval147 = (MMCheckBox)target;
				break;
			case 152:
				mmtogval148 = (MMCheckBox)target;
				break;
			case 153:
				mmtogval149 = (MMCheckBox)target;
				break;
			case 154:
				mmtogval150 = (MMCheckBox)target;
				break;
			case 155:
				mmtogval151 = (MMCheckBox)target;
				break;
			case 156:
				mmtogval152 = (MMCheckBox)target;
				break;
			case 157:
				btnnext = (MMNextButton)target;
				btnnext.PreviewMouseLeftButtonUp += btnnext_PreviewMouseLeftButtonUp;
				break;
			case 158:
				cmdDone = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Charact_Attribc_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdDone_Command;

		public static readonly CxvPropertyDeclaration cboAttCatID_CatValue_Property = CxvPropertyDeclaration.Register("cboAttCatID_CatValue", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
		{
			DataPath = "CatValue"
		});

		public static readonly CxvPropertyDeclaration chklCatAtt_var1_Property = CxvPropertyDeclaration.Register("chklCatAtt_var1", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.ATT_LISTC.@CATID"
		});

		public static readonly CxvPropertyDeclaration chklIniAtt_var1_Property = CxvPropertyDeclaration.Register("chklIniAtt_var1", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.ATT_LISTC.@CATID"
		});

		public static readonly CxvPropertyDeclaration S1Visibility_Property = CxvPropertyDeclaration.Register("S1Visibility", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvLogicalProperty
		{
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Input.SITCOM",
					Operator = CxvLogicalOperator.NotEqual,
					Value = "CATALYST"
				}
			}
		});

		public static readonly CxvPropertyDeclaration S2Visibility_Property = CxvPropertyDeclaration.Register("S2Visibility", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvLogicalProperty
		{
			Tests = 
			{
				new CxvLogicalTest
				{
					DataPath = "@main.Input.SITCOM",
					Operator = CxvLogicalOperator.Equal,
					Value = "CATALYST"
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboAttCatID_var2_Property = CxvPropertyDeclaration.Register("cboAttCatID_var2", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvParameterProperty
		{
			Parameter = "CATID",
			IsReadOnly = true
		});

		private readonly List<string> _initialCheckedNames1 = new List<string>();

		private readonly List<string> _initialCheckedNames2 = new List<string>();

		private Collection<string> _childIDs;

		private List<string> _childValues;

		private readonly Dictionary<string, string> _valueOptions1 = new Dictionary<string, string>
		{
			{ "mmtogval0", "PT0FLOW" },
			{ "mmtogval1", "CIONFLOW" },
			{ "mmtogval2", "P0FLOW" }
		};

		private readonly Dictionary<string, string> _valueOptions2 = new Dictionary<string, string>
		{
			{ "mmtogval3", "CPSFLOW" },
			{ "mmtogval4", "CPSFRAC" },
			{ "mmtogval5", "CVSFLOW" },
			{ "mmtogval6", "CVSFRAC" },
			{ "mmtogval7", "CISFLOW" },
			{ "mmtogval8", "CISFRAC" },
			{ "mmtogval9", "CDSFLOW" },
			{ "mmtogval10", "CDSFRAC" },
			{ "mmtogval11", "CMSFLOW" },
			{ "mmtogval12", "CMSFRAC" }
		};

		public ICommand cmdDone_Command
		{
			get
			{
				if (_cmdDone_Command == null)
				{
					_cmdDone_Command = new CxvDelegateCommand<object>(cmdDone_CommandExecute);
				}
				return _cmdDone_Command;
			}
		}

		public object cboAttCatID_CatValue => GetValue(cboAttCatID_CatValue_Property);

		public object chklCatAtt_var1 => GetValue(chklCatAtt_var1_Property);

		public object chklIniAtt_var1 => GetValue(chklIniAtt_var1_Property);

		public object S1Visibility => GetValue(S1Visibility_Property);

		public object S2Visibility => GetValue(S2Visibility_Property);

		public object cboAttCatID_var2 => GetValue(cboAttCatID_var2_Property);

		private Collection<string> ChildIDs
		{
			get
			{
				if (_childIDs == null)
				{
					_childIDs = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.ATT_LISTC.@CATID", "child_ids"));
				}
				return _childIDs;
			}
		}

		private List<string> ChildValues
		{
			get
			{
				if (_childValues == null && ChildIDs != null && ChildIDs.Count > 0)
				{
					object[] array = base.ResolvedCxsProvider.BatchGet(new CxsBatchRequestData(ChildIDs.Select((string id) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTC.@CATID." + id), "value"))));
					if (array != null && array.Length != 0)
					{
						IEnumerable<string> enumerable = array.Cast<string>();
						if (enumerable != null)
						{
							_childValues = enumerable.ToList();
						}
					}
				}
				return _childValues;
			}
		}

		private void cmdDone_CommandExecute(object parameter)
		{
			Done(closeForm: true);
		}

		internal void Done(bool closeForm)
		{
			bool? flag = (bool?)this.ResolveViewPropertyPath("S1Visibility.Value");
			if (flag.HasValue && flag.Value)
			{
				CommonDone(0, _valueOptions1, _initialCheckedNames1, closeForm);
			}
			else
			{
				CommonDone(1, _valueOptions2, _initialCheckedNames2, closeForm);
			}
		}

		private void CommonDone(int spindex, Dictionary<string, string> valueOptions, List<string> initialCheckedNames, bool closeForm)
		{
			List<string> list = new List<string>();
			if (base.View is MMPolymers_Charact_Attribc mMPolymers_Charact_Attribc)
			{
				StackPanel stackPanel = null;
				if ((mMPolymers_Charact_Attribc.fraAttrList.Content as ScrollViewer).Content is Grid grid)
				{
					stackPanel = grid.Children[spindex] as StackPanel;
				}
				foreach (object child in stackPanel.Children)
				{
					if (child is MMCheckBox { IsChecked: not null, IsChecked: var isChecked } mMCheckBox && isChecked.Value)
					{
						list.Add(mMCheckBox.Name);
					}
				}
			}
			List<string> list2 = new List<string>();
			List<string> list3 = new List<string>();
			foreach (string initialCheckedName in initialCheckedNames)
			{
				if (!list.Contains(initialCheckedName))
				{
					list2.Add(initialCheckedName);
				}
			}
			foreach (string item in list)
			{
				if (!initialCheckedNames.Contains(item))
				{
					list3.Add(item);
				}
			}
			if (list2.Count == 0 && list3.Count == 0)
			{
				if (closeForm)
				{
					CloseForm();
				}
				return;
			}
			int currentIdIndex = 0;
			if (ChildIDs != null && ChildIDs.Count > 0)
			{
				string text = ChildIDs[ChildIDs.Count - 1];
				if (text.StartsWith("#", StringComparison.Ordinal))
				{
					currentIdIndex = int.Parse(text.Substring(1)) + 1;
				}
			}
			if (list2.Count == 0 && list3.Count != 0)
			{
				base.ResolvedCxsProvider.BatchSet(new CxsBatchRequestData(list3.Select((string name) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTC.@CATID.#" + currentIdIndex++), "value", null, valueOptions[name]))));
			}
			else if (list2.Count != 0 && list3.Count == 0)
			{
				IEnumerable<int> rows = list2.Select((string name) => ChildValues.IndexOf(valueOptions[name]));
				DeleteChildren("@main.Input.ATT_LISTC.@CATID", rows, null, silently: true);
			}
			else if (list2.Count != 0 && list3.Count != 0)
			{
				IEnumerable<int> rows2 = list2.Select((string name) => ChildValues.IndexOf(valueOptions[name]));
				DeleteChildren("@main.Input.ATT_LISTC.@CATID", rows2, null, silently: true);
				currentIdIndex -= list2.Count;
				base.ResolvedCxsProvider.BatchSet(new CxsBatchRequestData(list3.Select((string name) => new CxsBatchRequest(ExpandDataPath("@main.Input.ATT_LISTC.@CATID.#" + currentIdIndex++), "value", null, valueOptions[name]))));
			}
			if (!string.IsNullOrEmpty(CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.CAT_GROUP.@POLYCOM", "value"))))
			{
				ExpandDataPathAndSet("@main.Input.MODIFIED.@POLYCOM", "value", "YES");
			}
			if (closeForm)
			{
				CloseForm();
			}
		}

		protected override void OnViewChanged()
		{
			base.OnViewChanged();
			if (!(base.View is MMPolymers_Charact_Attribc mMPolymers_Charact_Attribc) || ChildValues == null || ChildValues.Count() <= 0)
			{
				return;
			}
			StackPanel stackPanel = null;
			StackPanel stackPanel2 = null;
			if (mMPolymers_Charact_Attribc.fraAttrList.Content is ScrollViewer { Content: Grid content } && content.Children.Count == 2)
			{
				stackPanel = content.Children[0] as StackPanel;
				stackPanel2 = content.Children[1] as StackPanel;
			}
			if (stackPanel == null || stackPanel2 == null)
			{
				return;
			}
			foreach (object child in stackPanel.Children)
			{
				if (child is MMCheckBox mMCheckBox && ChildValues.Contains(_valueOptions1[mMCheckBox.Name]))
				{
					mMCheckBox.IsChecked = true;
					_initialCheckedNames1.Add(mMCheckBox.Name);
				}
			}
			foreach (object child2 in stackPanel2.Children)
			{
				if (child2 is MMCheckBox mMCheckBox2 && ChildValues.Contains(_valueOptions2[mMCheckBox2.Name]))
				{
					mMCheckBox2.IsChecked = true;
					_initialCheckedNames2.Add(mMCheckBox2.Name);
				}
			}
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Attribc")]
	public class MMPolymers_Charact_Attribc : MMTabPage, IComponentConnector
	{
		internal MMLabel lblAttrList;

		internal MMValueEdit cboAttCatID;

		internal MMGroupBox fraAttrList;

		internal StackPanel sp1;

		internal MMCheckBox mmtogval0;

		internal MMCheckBox mmtogval1;

		internal MMCheckBox mmtogval2;

		internal StackPanel sp2;

		internal MMCheckBox mmtogval3;

		internal MMCheckBox mmtogval4;

		internal MMCheckBox mmtogval5;

		internal MMCheckBox mmtogval6;

		internal MMCheckBox mmtogval7;

		internal MMCheckBox mmtogval8;

		internal MMCheckBox mmtogval9;

		internal MMCheckBox mmtogval10;

		internal MMCheckBox mmtogval11;

		internal MMCheckBox mmtogval12;

		internal MMNextButton btnNext;

		internal MMCmdButton cmdDone;

		private bool _contentLoaded;

		public MMPolymers_Charact_Attribc()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Attribc_ViewModel);
			InitializeComponent();
		}

		private void btnNext_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			if (base.ViewModel is MMPolymers_Charact_Attribc_ViewModel mMPolymers_Charact_Attribc_ViewModel)
			{
				mMPolymers_Charact_Attribc_ViewModel.Done(closeForm: false);
				OnNextButtonClicked();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_attribc.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblAttrList = (MMLabel)target;
				break;
			case 2:
				cboAttCatID = (MMValueEdit)target;
				break;
			case 3:
				fraAttrList = (MMGroupBox)target;
				break;
			case 4:
				sp1 = (StackPanel)target;
				break;
			case 5:
				mmtogval0 = (MMCheckBox)target;
				break;
			case 6:
				mmtogval1 = (MMCheckBox)target;
				break;
			case 7:
				mmtogval2 = (MMCheckBox)target;
				break;
			case 8:
				sp2 = (StackPanel)target;
				break;
			case 9:
				mmtogval3 = (MMCheckBox)target;
				break;
			case 10:
				mmtogval4 = (MMCheckBox)target;
				break;
			case 11:
				mmtogval5 = (MMCheckBox)target;
				break;
			case 12:
				mmtogval6 = (MMCheckBox)target;
				break;
			case 13:
				mmtogval7 = (MMCheckBox)target;
				break;
			case 14:
				mmtogval8 = (MMCheckBox)target;
				break;
			case 15:
				mmtogval9 = (MMCheckBox)target;
				break;
			case 16:
				mmtogval10 = (MMCheckBox)target;
				break;
			case 17:
				mmtogval11 = (MMCheckBox)target;
				break;
			case 18:
				mmtogval12 = (MMCheckBox)target;
				break;
			case 19:
				btnNext = (MMNextButton)target;
				btnNext.PreviewMouseLeftButtonUp += btnNext_PreviewMouseLeftButtonUp;
				break;
			case 20:
				cmdDone = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Charact_Catal_ViewModel : MMTabPageViewModel
	{
		public class grdCatAtt_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdCatAtt_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdCatAtt_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvFixedCountIndexBasis
				{
					FixedCount = 3,
					Name = "Col"
				}
			});

			public object inner => GetValue(inner_Property);
		}

		public class grdCatAtt_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public object txtCatAtt_Attrib
			{
				get
				{
					string empty = string.Empty;
					object obj = ResolveParameter("CATID");
					if (obj == null)
					{
						return null;
					}
					empty = obj.ToString();
					int? num = CxsConverter.ValueToInt32(ResolveParameter("Row"));
					int? num2 = CxsConverter.ValueToInt32(ResolveParameter("Col"));
					if (num.HasValue && num2.HasValue)
					{
						return new CxvVariableData(this, new CxvVariableProperty
						{
							DataPath = "@main.Input.ATT_LISTC." + empty + ".#" + (num.Value * 3 + num2.Value).ToString(CultureInfo.CurrentCulture)
						});
					}
					return null;
				}
			}
		}

		private ICommand _cmdCatEdit_Command;

		public static readonly CxvPropertyDeclaration mnuCatID_Save_Property = CxvPropertyDeclaration.Register("mnuCatID_Save", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvParameterProperty
		{
			Parameter = "CATID"
		});

		public static readonly CxvPropertyDeclaration mnuCatID_List_Property = CxvPropertyDeclaration.Register("mnuCatID_List", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.ATT_LISTC",
			SelectedItemBinding = "mnuCatID_Save.Value",
			CreateNewPrompt = "Comp ID:",
			CreateNewPromptResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Comp_ID_",
			CompletePaths = { "CAID1", "CATT2" },
			EnteredPaths = { "ENTCAT" }
		});

		public static readonly CxvPropertyDeclaration spnNsite_var1_Property = CxvPropertyDeclaration.Register("spnNsite_var1", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NSITES",
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CATID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lblNsite_state_Property = CxvPropertyDeclaration.Register("lblNsite_state", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvLabelProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CATID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lbtuMxSite_var1_Property = CxvPropertyDeclaration.Register("lbtuMxSite_var1", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MXSITE.@CATID",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTSCO"
			}
		});

		public static readonly CxvPropertyDeclaration fraCatAtt_state_Property = CxvPropertyDeclaration.Register("fraCatAtt_state", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "CATID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration NumRow_Property = CxvPropertyDeclaration.Register("NumRow", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.ATT_LISTC.@CATID"
		});

		public static readonly CxvPropertyDeclaration fraSitComp_MultiMap_Property = CxvPropertyDeclaration.Register("fraSitComp_MultiMap", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "fraSitComp_var1",
					DataPath = "@main.Input.SITCOM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Ziegler-Natta catalyst",
					DisplayResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvMultiMapOption_Display_Ziegler_Natta_catalyst",
					Value = "fraSitComp_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "fraSitComp_var1",
							Value = "CATALYST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Ionic initiator",
					DisplayResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvMultiMapOption_Display_Ionic_initiator",
					Value = "fraSitComp_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "fraSitComp_var1",
							Value = "INITIATOR"
						}
					}
				}
			}
		});

		private CxvPropertyWatch varDefnDependencies;

		private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

		public ICommand cmdCatEdit_Command
		{
			get
			{
				if (_cmdCatEdit_Command == null)
				{
					_cmdCatEdit_Command = new CxvDelegateCommand<object>(cmdCatEdit_CommandExecute);
				}
				return _cmdCatEdit_Command;
			}
		}

		public object mnuCatID_Save => GetValue(mnuCatID_Save_Property);

		public object mnuCatID_List => GetValue(mnuCatID_List_Property);

		public object spnNsite_var1 => GetValue(spnNsite_var1_Property);

		public object lblNsite_state => GetValue(lblNsite_state_Property);

		public object lbtuMxSite_var1 => GetValue(lbtuMxSite_var1_Property);

		public object fraCatAtt_state => GetValue(fraCatAtt_state_Property);

		public object NumRow => GetValue(NumRow_Property);

		public object fraSitComp_MultiMap => GetValue(fraSitComp_MultiMap_Property);

		public object grdCatAtt_GridData => new CxvVectorPropertyData(this, new CxvVectorProperty
		{
			ItemType = typeof(grdCatAtt_GridData_ItemTemplate),
			IndexBasis = new CxvFixedCountIndexBasis
			{
				FixedCount = GetRowsCount(),
				Name = "Row"
			}
		});

		private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
				{
					_varDefnDependencies_PropertyDependencyChangedHandler = delegate
					{
						OnPropertyChanged("grdCatAtt_GridData");
					};
				}
				return _varDefnDependencies_PropertyDependencyChangedHandler;
			}
		}

		private void cmdCatEdit_CommandExecute(object parameter)
		{
			OpenSubform();
		}

		private void OpenSubform()
		{
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMPolymers.MMPolymers_Charact_Attribc";
			e.LegacyFlags = 0;
			e.HelpId = 20;
			e.HelpFile = "polyfrms.hlp";
			e.ShowPrompts = false;
			e.ShortName = Resources.MMPolymers_Charact_Catal_ViewModel__SubForm_ShortName;
			e.CompleteDataPaths = new string[1] { "CAID" };
			DisplayFormEventArgs e2 = e;
			e2.Parameters.Add("CATID", ResolveParameter("CATID"));
			DisplayForm(e2);
			UpdateAll();
			OnPropertyChanged("grdCatAtt_GridData");
		}

		private int GetRowsCount()
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
			string empty = string.Empty;
			object obj = ResolveParameter("CATID");
			if (obj == null)
			{
				return 0;
			}
			empty = obj.ToString();
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.ATT_LISTC." + empty, "child_count", null, varDefnDependencies));
			if (!varDefnDependencies.IsEmpty)
			{
				varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
			}
			else
			{
				varDefnDependencies = null;
			}
			if (num.HasValue)
			{
				if (num.Value % 3 <= 0)
				{
					return num.Value / 3;
				}
				return num.Value / 3 + 1;
			}
			return 0;
		}

		protected override void OnViewChanged()
		{
			base.OnViewChanged();
			if (base.View is MMPolymers_Charact_Catal mMPolymers_Charact_Catal)
			{
				mMPolymers_Charact_Catal.fraSitComp_opt0.PreviewMouseDown -= fraSitComp_opt0_PreviewMouseDown;
				mMPolymers_Charact_Catal.fraSitComp_opt1.PreviewMouseDown -= fraSitComp_opt1_PreviewMouseDown;
				mMPolymers_Charact_Catal.fraSitComp_opt0.PreviewMouseDown += fraSitComp_opt0_PreviewMouseDown;
				mMPolymers_Charact_Catal.fraSitComp_opt1.PreviewMouseDown += fraSitComp_opt1_PreviewMouseDown;
				mMPolymers_Charact_Catal.grdCatAtt.PreviewMouseLeftButtonUp -= grdCatAtt_PreviewMouseLeftButtonUp;
				mMPolymers_Charact_Catal.grdCatAtt.PreviewMouseLeftButtonUp += grdCatAtt_PreviewMouseLeftButtonUp;
			}
		}

		private void grdCatAtt_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			OpenSubform();
		}

		private void fraSitComp_opt1_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
			MMOptionButton mMOptionButton = sender as MMOptionButton;
			if (!mMOptionButton.IsChecked.HasValue || !mMOptionButton.IsChecked.Value)
			{
				bool? flag = OnSelectionChanged(e, 1);
				if (flag.HasValue && flag.Value)
				{
					mMOptionButton.IsChecked = true;
				}
			}
		}

		private void fraSitComp_opt0_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
			MMOptionButton mMOptionButton = sender as MMOptionButton;
			if (!mMOptionButton.IsChecked.HasValue || !mMOptionButton.IsChecked.Value)
			{
				bool? flag = OnSelectionChanged(e, 0);
				if (flag.HasValue && flag.Value)
				{
					mMOptionButton.IsChecked = true;
				}
			}
		}

		private bool? OnSelectionChanged(MouseButtonEventArgs e, int pindex)
		{
			ShowMessageBoxEventArgs e2 = new ShowMessageBoxEventArgs
			{
				Message = Resources.MMPolymers_Charact_Catal_ViewModel__SelectionChanged_Message,
				MsgBoxButton = MessageBoxButton.YesNo,
				MsgBoxImage = MessageBoxImage.Question,
				Title = Resources.MMPolymers_Charact_Catal_ViewModel__SelectionChanged_Title
			};
			ShowMessageBox(e2);
			if (e2.DialogResult == MessageBoxResult.Yes)
			{
				string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.ATT_LISTC", "child_ids"));
				if (array != null && array.Length != 0)
				{
					DeleteChildren("@main.Input.ATT_LISTC", array, silently: true);
				}
				OnPropertyChanged("mnuCatID_List");
				OnPropertyChanged("spnNsite_var1");
				OnPropertyChanged("grdCatAtt_GridData");
			}
			else
			{
				ExpandDataPathAndSet("@main.Input.SITCOM", "value", (pindex == 0) ? "INITIATOR" : "CATALYST");
			}
			return e2.DialogResult == MessageBoxResult.Yes;
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd == mnuCatID_List_Property && subPropertyName == "SelectedItem")
			{
				OnPropertyChanged("grdCatAtt_GridData");
			}
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Catal")]
	public class MMPolymers_Charact_Catal : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup fraSitComp;

		internal MMOptionButton fraSitComp_opt0;

		internal MMOptionButton fraSitComp_opt1;

		internal MMGroupBox fraCatalyst;

		internal MMLabel mnuCatID_label;

		internal MMLabel lblNsite;

		internal MMLabel lbtuMxSite_label;

		internal MMAdvancedComboEdit mnuCatID;

		internal MMSpinBox spnNsite;

		internal MMVariableEdit lbtuMxSite;

		internal MMGroupBox fraCatAtt;

		internal MMScrollArea grdCatAtt;

		internal MMCmdButton cmdCatEdit;

		private bool _contentLoaded;

		public MMPolymers_Charact_Catal()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Catal_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_catal.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraSitComp = (MMOptionGroup)target;
				break;
			case 2:
				fraSitComp_opt0 = (MMOptionButton)target;
				break;
			case 3:
				fraSitComp_opt1 = (MMOptionButton)target;
				break;
			case 4:
				fraCatalyst = (MMGroupBox)target;
				break;
			case 5:
				mnuCatID_label = (MMLabel)target;
				break;
			case 6:
				lblNsite = (MMLabel)target;
				break;
			case 7:
				lbtuMxSite_label = (MMLabel)target;
				break;
			case 8:
				mnuCatID = (MMAdvancedComboEdit)target;
				break;
			case 9:
				spnNsite = (MMSpinBox)target;
				break;
			case 10:
				lbtuMxSite = (MMVariableEdit)target;
				break;
			case 11:
				fraCatAtt = (MMGroupBox)target;
				break;
			case 12:
				grdCatAtt = (MMScrollArea)target;
				break;
			case 13:
				cmdCatEdit = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Charact_Oligom_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Input.NUMBER.#0",
					UseChildId = true,
					Name = "Seg"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.NUMBER.@Olig",
				IsReadOnly = true
			});

			public object inner => GetValue(inner_Property);

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NUMBER.@Olig.@Seg"
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NUMBER.@Olig.@Seg",
				ExposeAs = CxvVariableTypeCode.IdWithOptions
			});

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPolymers_Charact_Oligom_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.NUMBER",
				UseChildId = true,
				Name = "Olig"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Oligom")]
	public class MMPolymers_Charact_Oligom : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMPolymers_Charact_Oligom()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Oligom_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_oligom.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMPolymers_Charact_Options_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spnNsite_var1_Property = CxvPropertyDeclaration.Register("spnNsite_var1", typeof(MMPolymers_Charact_Options_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.N_BIFUN_INIT"
		});

		public static readonly CxvPropertyDeclaration chkSolidPol_var1_Property = CxvPropertyDeclaration.Register("chkSolidPol_var1", typeof(MMPolymers_Charact_Options_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.CHKSOLIDPOL",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public static readonly CxvPropertyDeclaration MMLBUText_Threshold_Property = CxvPropertyDeclaration.Register("MMLBUText_Threshold", typeof(MMPolymers_Charact_Options_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SP_THRESHOLD"
		});

		public static readonly CxvPropertyDeclaration MMFrameOption_state_Property = CxvPropertyDeclaration.Register("MMFrameOption_state", typeof(MMPolymers_Charact_Options_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EXPOL"
			}
		});

		public static CxvPropertyDeclaration _OptionVisible_Property = CxvPropertyDeclaration.Register("_OptionVisible", typeof(MMPolymers_Charact_Options_ViewModel), new CxvParameterProperty
		{
			Parameter = "_OptionVisible"
		});

		public object spnNsite_var1 => GetValue(spnNsite_var1_Property);

		public object chkSolidPol_var1 => GetValue(chkSolidPol_var1_Property);

		public object MMLBUText_Threshold => GetValue(MMLBUText_Threshold_Property);

		public object MMFrameOption_state => GetValue(MMFrameOption_state_Property);

		public object _OptionVisible => GetValue(_OptionVisible_Property);

		protected override void OnUpdateData()
		{
			if (base.IsInitialUpdate)
			{
				if (GetProductCode() == 2)
				{
					ResolveUpdateParameter("_OptionVisible", "0");
				}
				else
				{
					ResolveUpdateParameter("_OptionVisible", "1");
				}
			}
			base.OnUpdateData();
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Options")]
	public class MMPolymers_Charact_Options : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraBiFuncSpec;

		internal MMLabel lblNBiInit;

		internal MMSpinBox spnNsite;

		internal MMGroupBox fraSolidPolymer;

		internal MMCheckBox chkSolidPol;

		internal MMLabel Threshold;

		internal MMVariableEdit MMLBUText_Threshold;

		private bool _contentLoaded;

		public MMPolymers_Charact_Options()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Options_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_options.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraBiFuncSpec = (MMGroupBox)target;
				break;
			case 2:
				lblNBiInit = (MMLabel)target;
				break;
			case 3:
				spnNsite = (MMSpinBox)target;
				break;
			case 4:
				fraSolidPolymer = (MMGroupBox)target;
				break;
			case 5:
				chkSolidPol = (MMCheckBox)target;
				break;
			case 6:
				Threshold = (MMLabel)target;
				break;
			case 7:
				MMLBUText_Threshold = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Charact_Polymer_ViewModel : MMTabPageViewModel
	{
		public class grdPolAtt_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPolAtt_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdPolAtt_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvFixedCountIndexBasis
				{
					FixedCount = 5,
					Name = "Col"
				}
			});

			public object inner => GetValue(inner_Property);
		}

		public class grdPolAtt_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public object txtPolAtt_Attrib
			{
				get
				{
					string empty = string.Empty;
					object obj = ResolveParameter("POLYCOM");
					empty = ((obj != null) ? obj.ToString() : "#0");
					int? num = CxsConverter.ValueToInt32(ResolveParameter("Row"));
					int? num2 = CxsConverter.ValueToInt32(ResolveParameter("Col"));
					if (num.HasValue && num2.HasValue)
					{
						return new CxvVariableData(this, new CxvVariableProperty
						{
							DataPath = "@main.Input.ATT_LISTP." + empty + ".#" + (num.Value * 5 + num2.Value).ToString(CultureInfo.CurrentCulture),
							IsReadOnly = false,
							IsCalculated = true
						});
					}
					return null;
				}
			}
		}

		private ICommand _cmdEdit_Command;

		public static readonly CxvPropertyDeclaration lblModified_state_Property = CxvPropertyDeclaration.Register("lblModified_state", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvLabelProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GMOD.@POLYCOM"
			}
		});

		public static readonly CxvPropertyDeclaration cboAttrGroup_MultiMap_Property = CxvPropertyDeclaration.Register("cboAttrGroup_MultiMap", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboAttrGroup_var1",
					DataPath = "@main.Input.CAT_GROUP.@POLYCOM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Minimum selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_min_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Minimum_selection",
					Value = "cboAttrGroup_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "MIN-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Properties selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_prop_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Properties_selection",
					Value = "cboAttrGroup_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "PROP-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Emulsion selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_emul_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Emulsion_selection",
					Value = "cboAttrGroup_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "EMUL-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Anionic selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_anion_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Anionic_selection",
					Value = "cboAttrGroup_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "ANION-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cationic selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_cation_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Cationic_selection",
					Value = "cboAttrGroup_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "CATION-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Free-radical selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_free_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Free_radical_selection",
					Value = "cboAttrGroup_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "FREE-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Pyrolysis selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_pyro_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Pyrolysis_selection",
					Value = "cboAttrGroup_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "PYRO-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Step-growth selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_step_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Step_growth_selection",
					Value = "cboAttrGroup_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "STEP-CAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Ziegler-Natta selection",
					Prompt = ApwnComboPromptResource.polymers_cat_group_zieg_cat_prompt,
					DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Ziegler_Natta_selection",
					Value = "cboAttrGroup_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboAttrGroup_var1",
							Value = "ZIEG-CAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration Pol_Property = CxvPropertyDeclaration.Register("Pol", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYCOM"
		});

		public static readonly CxvPropertyDeclaration mnuPolymer_View_Property = CxvPropertyDeclaration.Register("mnuPolymer_View", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYCOM"
		});

		public static readonly CxvPropertyDeclaration mnuPolymer_Catts_Property = CxvPropertyDeclaration.Register("mnuPolymer_Catts", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CATTS"
		});

		public static readonly CxvPropertyDeclaration mnuPolymer_List_Property = CxvPropertyDeclaration.Register("mnuPolymer_List", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.ATT_LISTP",
			SelectedItemBinding = "mnuPolymer_View.Value",
			CreateNewPrompt = "Polymer ID",
			CreateNewPromptResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Polymer_ID",
			CompletePaths = { "CATTS" }
		});

		private CxvPropertyWatch varDefnDependencies;

		private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

		private Visibility _lblModified_Visibility;

		public ICommand cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new CxvDelegateCommand<object>(cmdEdit_CommandExecute);
				}
				return _cmdEdit_Command;
			}
		}

		public object lblModified_state => GetValue(lblModified_state_Property);

		public object cboAttrGroup_MultiMap => GetValue(cboAttrGroup_MultiMap_Property);

		public object Pol => GetValue(Pol_Property);

		public object mnuPolymer_View => GetValue(mnuPolymer_View_Property);

		public object mnuPolymer_Catts => GetValue(mnuPolymer_Catts_Property);

		public object mnuPolymer_List => GetValue(mnuPolymer_List_Property);

		public object grdPolAtt_GridData => new CxvVectorPropertyData(this, new CxvVectorProperty
		{
			ItemType = typeof(grdPolAtt_GridData_ItemTemplate),
			IndexBasis = new CxvFixedCountIndexBasis
			{
				FixedCount = GetRowsCount(),
				Name = "Row"
			}
		});

		private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
		{
			get
			{
				if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
				{
					_varDefnDependencies_PropertyDependencyChangedHandler = delegate
					{
						OnPropertyChanged("grdPolAtt_GridData");
					};
				}
				return _varDefnDependencies_PropertyDependencyChangedHandler;
			}
		}

		public Visibility lblModified_Visibility
		{
			get
			{
				return _lblModified_Visibility;
			}
			set
			{
				_lblModified_Visibility = value;
				OnPropertyChanged("lblModified_Visibility");
			}
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			OpenSubform();
		}

		private void OpenSubform()
		{
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormProgId = "MMPolymers.MMPolymers_Charact_Attrib";
			e.ShortName = Resources.MMPolymers_Charact_Polymer_ViewModel__PolymerAttributes_ShortName;
			e.PreferredHeight = 520;
			e.CompleteDataPaths = new string[1] { "@main.CC Nodes.CATTS.@POLYCOM" };
			e.HelpFile = "polyfrms.hlp";
			e.HelpId = 10;
			DisplayFormEventArgs e2 = e;
			e2.Parameters.Add("POLYCOM", ResolveParameter("POLYCOM"));
			DisplayForm(e2);
			UpdateAll();
			OnPropertyChanged("grdPolAtt_GridData");
			RefreshModifiedVisibility();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if ((pd == cboAttrGroup_MultiMap_Property && subPropertyName == "SelectedItem") || (pd.Name == "mnuPolymer_View" && subPropertyName == "Value"))
			{
				OnPropertyChanged("grdPolAtt_GridData");
			}
		}

		private int GetRowsCount()
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
			string empty = string.Empty;
			object obj = ResolveParameter("POLYCOM");
			empty = ((obj != null) ? obj.ToString() : "#0");
			int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.ATT_LISTP." + empty, "child_count", null, varDefnDependencies));
			if (!varDefnDependencies.IsEmpty)
			{
				varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
			}
			else
			{
				varDefnDependencies = null;
			}
			if (num.HasValue)
			{
				if (num.Value % 5 <= 0)
				{
					return num.Value / 5;
				}
				return num.Value / 5 + 1;
			}
			return 0;
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				RefreshModifiedVisibility();
			}
		}

		private void RefreshModifiedVisibility()
		{
			string empty = string.Empty;
			object obj = ResolveParameter("POLYCOM");
			empty = ((obj != null) ? obj.ToString() : "#0");
			if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.MODIFIED." + empty, "value")) == "YES")
			{
				lblModified_Visibility = Visibility.Visible;
			}
			else
			{
				lblModified_Visibility = Visibility.Collapsed;
			}
		}

		protected override void OnViewChanged()
		{
			base.OnViewChanged();
			if (base.View is MMPolymers_Charact_Polymer mMPolymers_Charact_Polymer)
			{
				mMPolymers_Charact_Polymer.grdPolAtt.PreviewMouseLeftButtonUp -= grdPolAtt_PreviewMouseLeftButtonUp;
				mMPolymers_Charact_Polymer.grdPolAtt.PreviewMouseLeftButtonUp += grdPolAtt_PreviewMouseLeftButtonUp;
			}
		}

		private void grdPolAtt_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
		}
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Polymer")]
	public class MMPolymers_Charact_Polymer : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuPolymer_label;

		internal MMAdvancedComboEdit mnuPolymer;

		internal MMGroupBox fraAttrPol;

		internal MMGroupBox fraAttSel;

		internal MMLabel cboAttrGroup_label;

		internal MMComboEdit cboAttrGroup;

		internal MMLabel lblModified;

		internal MMGroupBox fraAttList;

		internal MMScrollAreaMS grdPolAtt;

		internal MMCmdButton cmdEdit;

		internal MMLabel MMLabel2;

		internal MMLabel MMLabel1;

		private bool _contentLoaded;

		public MMPolymers_Charact_Polymer()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Polymer_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_polymer.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mnuPolymer_label = (MMLabel)target;
				break;
			case 2:
				mnuPolymer = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraAttrPol = (MMGroupBox)target;
				break;
			case 4:
				fraAttSel = (MMGroupBox)target;
				break;
			case 5:
				cboAttrGroup_label = (MMLabel)target;
				break;
			case 6:
				cboAttrGroup = (MMComboEdit)target;
				break;
			case 7:
				lblModified = (MMLabel)target;
				break;
			case 8:
				fraAttList = (MMGroupBox)target;
				break;
			case 9:
				grdPolAtt = (MMScrollAreaMS)target;
				break;
			case 10:
				cmdEdit = (MMCmdButton)target;
				break;
			case 11:
				MMLabel2 = (MMLabel)target;
				break;
			case 12:
				MMLabel1 = (MMLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Charact_Segment_ViewModel : MMTabPageViewModel
	{
		public class grdSegment_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboSegType_var1_Property = CxvPropertyDeclaration.Register("cboSegType_var1", typeof(grdSegment_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.SEG_TYPE.@Segment"
			});

			public static readonly CxvPropertyDeclaration txtSegID_var1_Property = CxvPropertyDeclaration.Register("txtSegID_var1", typeof(grdSegment_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.SEG_TYPE.@Segment"
			});

			public object cboSegType_var1 => GetValue(cboSegType_var1_Property);

			public object txtSegID_var1 => GetValue(txtSegID_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdSegment_GridData_Property = CxvPropertyDeclaration.Register("grdSegment_GridData", typeof(MMPolymers_Charact_Segment_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSegment_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.SEG_TYPE",
				UseChildId = true,
				Name = "Segment"
			}
		});

		public object grdSegment_GridData => GetValue(grdSegment_GridData_Property);
	}
	[ProgId("MMPolymers.MMPolymers_Charact_Segment")]
	public class MMPolymers_Charact_Segment : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraSegments;

		internal MMScrollArea grdSegment;

		private bool _contentLoaded;

		public MMPolymers_Charact_Segment()
		{
			base.ViewModelType = typeof(MMPolymers_Charact_Segment_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_charact_segment.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraSegments = (MMGroupBox)target;
				break;
			case 2:
				grdSegment = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPolymers_Distrib_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration CCDistr_Property = CxvPropertyDeclaration.Register("CCDistr", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DISTRI",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EXPOL"
			}
		});

		public static readonly CxvPropertyDeclaration EXPOL_Property = CxvPropertyDeclaration.Register("EXPOL", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EXPOL"
		});

		public static readonly CxvPropertyDeclaration POLYDIS_Property = CxvPropertyDeclaration.Register("POLYDIS", typeof(MMPolymers_Distrib_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYDIS"
		});

		public static readonly CxvPropertyDeclaration ENTDis_Property = CxvPropertyDeclaration.Register("ENTDis", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTDIS",
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EXPOL"
			}
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPolymers_Distrib_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCDistr" },
			AccessibleDataPaths = { "@EXPOL" },
			EnteredDataPaths = { "@ENTDis" }
		});

		public object CCDistr => GetValue(CCDistr_Property);

		public object EXPOL => GetValue(EXPOL_Property);

		public object POLYDIS => GetValue(POLYDIS_Property);

		public object ENTDis => GetValue(ENTDis_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMPolymers.MMPolymers_Distrib")]
	public class MMPolymers_Distrib : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabDistrib;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMPolymers_Distrib()
		{
			base.ViewModelType = typeof(MMPolymers_Distrib_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_distrib.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabDistrib = (MMTabStrip)target;
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
	public class MMPolymers_Distrib_Distrib_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration chkGPC_var1_Property = CxvPropertyDeclaration.Register("chkGPC_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.FUNCLOG.@POLYDIS",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public static readonly CxvPropertyDeclaration lbtuNpoints_var1_Property = CxvPropertyDeclaration.Register("lbtuNpoints_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NPOINTS.@POLYDIS"
		});

		public static readonly CxvPropertyDeclaration lbtuUpper_var1_Property = CxvPropertyDeclaration.Register("lbtuUpper_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UPPER.@POLYDIS"
		});

		public static readonly CxvPropertyDeclaration mnuPolymer_Save_Property = CxvPropertyDeclaration.Register("mnuPolymer_Save", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvParameterProperty
		{
			Parameter = "POLYDIS"
		});

		public static readonly CxvPropertyDeclaration mnuPolymer_List_Property = CxvPropertyDeclaration.Register("mnuPolymer_List", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.DISTTYPE",
			SelectedItemBinding = "mnuPolymer_Save.Value",
			CompletePaths = { "DISTRI" },
			EnteredPaths = { "ENTDIS" }
		});

		public static readonly CxvPropertyDeclaration GPEnabled_Property = CxvPropertyDeclaration.Register("GPEnabled", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.DISTTYPE",
			DataAttribute = "has_children",
			Operator = CxvLogicalOperator.Equal,
			Value = "1"
		});

		public object chkGPC_var1 => GetValue(chkGPC_var1_Property);

		public object lbtuNpoints_var1 => GetValue(lbtuNpoints_var1_Property);

		public object lbtuUpper_var1 => GetValue(lbtuUpper_var1_Property);

		public object mnuPolymer_Save => GetValue(mnuPolymer_Save_Property);

		public object mnuPolymer_List => GetValue(mnuPolymer_List_Property);

		public object GPEnabled => GetValue(GPEnabled_Property);
	}
	[ProgId("MMPolymers.MMPolymers_Distrib_Distrib")]
	public class MMPolymers_Distrib_Distrib : MMTabPage, IComponentConnector
	{
		internal MMLabel lblViewPol;

		internal MMAdvancedComboEdit mnuPolymer;

		internal MMGroupBox fraDplot;

		internal MMLabel lbtuNpoints_label;

		internal MMVariableEdit lbtuNpoints;

		internal MMLabel lbtuUpper_label;

		internal MMVariableEdit lbtuUpper;

		internal MMCheckBox chkGPC;

		private bool _contentLoaded;

		public MMPolymers_Distrib_Distrib()
		{
			base.ViewModelType = typeof(MMPolymers_Distrib_Distrib_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/polymers/mmpolymers_distrib_distrib.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblViewPol = (MMLabel)target;
				break;
			case 2:
				mnuPolymer = (MMAdvancedComboEdit)target;
				break;
			case 3:
				fraDplot = (MMGroupBox)target;
				break;
			case 4:
				lbtuNpoints_label = (MMLabel)target;
				break;
			case 5:
				lbtuNpoints = (MMVariableEdit)target;
				break;
			case 6:
				lbtuUpper_label = (MMLabel)target;
				break;
			case 7:
				lbtuUpper = (MMVariableEdit)target;
				break;
			case 8:
				chkGPC = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization
{
	public class MMADAset_Analys_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration PPROP_Property = CxvPropertyDeclaration.Register("PPROP", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Blend Options.CC Nodes.PPROP"
		});

		public static readonly CxvPropertyDeclaration ADA_Property = CxvPropertyDeclaration.Register("ADA", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.CC Nodes.ADA"
		});

		public static readonly CxvPropertyDeclaration ADAOPT_Property = CxvPropertyDeclaration.Register("ADAOPT", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.CC Nodes.ADAOPT"
		});

		public static readonly CxvPropertyDeclaration PPROPOPT_Property = CxvPropertyDeclaration.Register("PPROPOPT", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Blend Options.CC Nodes.PPROPOPT"
		});

		public static readonly CxvPropertyDeclaration ADAADV_Property = CxvPropertyDeclaration.Register("ADAADV", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.CC Nodes.ADAADV"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@ADA" },
			EnteredDataPaths = { "@ADAOPT" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PPROP" },
			EnteredDataPaths = { "@PPROPOPT" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@ADAADV" }
		});

		public object PPROP => GetValue(PPROP_Property);

		public object ADA => GetValue(ADA_Property);

		public object ADAOPT => GetValue(ADAOPT_Property);

		public object PPROPOPT => GetValue(PPROPOPT_Property);

		public object ADAADV => GetValue(ADAADV_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMADASet.MMADAset_Analys")]
	public class MMADAset_Analys : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabADAset_Analys;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		private bool _contentLoaded;

		public MMADAset_Analys()
		{
			base.ViewModelType = typeof(MMADAset_Analys_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmadaset_analys.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabADAset_Analys = (MMTabStrip)target;
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
	public class MMADAset_Analys_Advanc_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLBUText1_MW_INTGR_H_Property = CxvPropertyDeclaration.Register("MMLBUText1_MW_INTGR_H", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.Input.MW_INTGR_H"
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Assay Procedures.Input.SPLINE_FIT",
			DisplayedCase = CxsDisplayedCase.Lowercase
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_TBP_GEN",
					DataPath = "@main.Assay Procedures.Input.TBP_GEN"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Aspen Plus",
					DisplayResourceKey = "MMADAset_Analys_Advanc_ViewModel__CxvMultiMapOption_Display_Aspen_Plus",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_TBP_GEN",
							Value = "ASPEN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RefSYS",
					DisplayResourceKey = "MMADAset_Analys_Advanc_ViewModel__CxvMultiMapOption_Display_RefSYS",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_TBP_GEN",
							Value = "REFSYS"
						}
					}
				}
			}
		});

		public object MMLBUText1_MW_INTGR_H => GetValue(MMLBUText1_MW_INTGR_H_Property);

		public object MMComboBox4_var1 => GetValue(MMComboBox4_var1_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);
	}
	[ProgId("MMADASet.MMADAset_Analys_Advanc")]
	public class MMADAset_Analys_Advanc : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		private bool _contentLoaded;

		public MMADAset_Analys_Advanc()
		{
			base.ViewModelType = typeof(MMADAset_Analys_Advanc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmadaset_analys_advanc.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				MMComboBox4_label = (MMLabel)target;
				break;
			case 3:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 4:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 6:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMADAset_Analys_Assay_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraDistil_state_Property = CxvPropertyDeclaration.Register("fraDistil_state", typeof(MMADAset_Analys_Assay_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Assay Procedures.CC Nodes.PROCA"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox4_d1160_meth",
					DataPath = "@main.Assay Procedures.Input.D1160_METH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "API63",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API63",
					Value = "MMComboBox4_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_d1160_meth",
							Value = "API63"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PML",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_PML",
					Value = "MMComboBox4_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_d1160_meth",
							Value = "PML"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_D86_METH",
					DataPath = "@main.Assay Procedures.Input.D86_METH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "API87",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API87",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "API87"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API92",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API92",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "API92"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API94",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API94",
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "API94"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Edmister",
					Value = "MMComboBox2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "EDMISTER"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister-Okamato",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Edmister_Okamato",
					Value = "MMComboBox2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "ED-OK"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PML",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_PML_1",
					Value = "MMComboBox2_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_D86_METH",
							Value = "PML"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox3_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox3_d2887_meth",
					DataPath = "@main.Assay Procedures.Input.D2887_METH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "API87",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API87_1",
					Value = "MMComboBox3_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox3_d2887_meth",
							Value = "API87"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API94",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API94_1",
					Value = "MMComboBox3_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox3_d2887_meth",
							Value = "API94"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "TBPWT",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_TBPWT",
					Value = "MMComboBox3_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox3_d2887_meth",
							Value = "TBPWT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration fraCurve_state_Property = CxvPropertyDeclaration.Register("fraCurve_state", typeof(MMADAset_Analys_Assay_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.Assay Procedures.CC Nodes.PROCA"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_method",
					DataPath = "@main.Assay Procedures.Input.EXTRAP_METH"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Probability",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Probability",
					Value = "MMComboBox1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_method",
							Value = "PROBABILITY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Quadratic",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Quadratic",
					Value = "MMComboBox1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_method",
							Value = "QUADRATIC"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_ep_Property = CxvPropertyDeclaration.Register("MMLBUText2_ep", typeof(MMADAset_Analys_Assay_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.Input.EP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_ibp_Property = CxvPropertyDeclaration.Register("MMLBUText1_ibp", typeof(MMADAset_Analys_Assay_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Assay Procedures.Input.IBP"
		});

		public static readonly CxvPropertyDeclaration ogrADAprocedure_MultiMap_Property = CxvPropertyDeclaration.Register("ogrADAprocedure_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrADAprocedure_procedure",
					DataPath = "@main.Assay Procedures.Input.PROCEDURE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Current version",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Version_9_or_later",
					Value = "ogrADAprocedure_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrADAprocedure_procedure",
							Value = "REL9"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Legacy version",
					DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Version_8_or_earlier",
					Value = "ogrADAprocedure_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrADAprocedure_procedure",
							Value = "PRE-REL9"
						}
					}
				}
			}
		});

		public object fraDistil_state => GetValue(fraDistil_state_Property);

		public object MMComboBox4_MultiMap => GetValue(MMComboBox4_MultiMap_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object MMComboBox3_MultiMap => GetValue(MMComboBox3_MultiMap_Property);

		public object fraCurve_state => GetValue(fraCurve_state_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object MMLBUText2_ep => GetValue(MMLBUText2_ep_Property);

		public object MMLBUText1_ibp => GetValue(MMLBUText1_ibp_Property);

		public object ogrADAprocedure_MultiMap => GetValue(ogrADAprocedure_MultiMap_Property);
	}
	[ProgId("MMADASet.MMADAset_Analys_Assay")]
	public class MMADAset_Analys_Assay : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrADAprocedure;

		internal MMOptionButton ogrADAprocedure_opt0;

		internal MMOptionButton ogrADAprocedure_opt1;

		internal MMGroupBox fraCurve;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox fraDistil;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox3_label;

		internal MMComboEdit MMComboBox3;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		private bool _contentLoaded;

		public MMADAset_Analys_Assay()
		{
			base.ViewModelType = typeof(MMADAset_Analys_Assay_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmadaset_analys_assay.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				ogrADAprocedure = (MMOptionGroup)target;
				break;
			case 2:
				ogrADAprocedure_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogrADAprocedure_opt1 = (MMOptionButton)target;
				break;
			case 4:
				fraCurve = (MMGroupBox)target;
				break;
			case 5:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 6:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 7:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 8:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 9:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 10:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 11:
				fraDistil = (MMGroupBox)target;
				break;
			case 12:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 13:
				MMComboBox2 = (MMComboEdit)target;
				break;
			case 14:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 15:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 16:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 17:
				MMComboBox4 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMADAset_Analys_Blend_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_PPROP_Property = CxvPropertyDeclaration.Register("MMComboBox1_PPROP", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Blend Options.Input.PROP_NAME.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox3_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox3_MultiMap", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox3_var1",
						DataPath = "@main.Blend Options.Input.EXTRAPOLATE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Yes",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Yes",
						Value = "MMComboBox3_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox3_var1",
								Value = "YES"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "No",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_No",
						Value = "MMComboBox3_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox3_var1",
								Value = "NO"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Blend Options.Input.BLEND_OPTION.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox2_var1",
						DataPath = "@main.Blend Options.Input.BLEND_METHOD.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "StdVol",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_StdVol",
						Value = "MMComboBox2_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox2_var1",
								Value = "STDVOL"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Mass",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Mass",
						Value = "MMComboBox2_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox2_var1",
								Value = "MASS"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Mole",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Mole",
						Value = "MMComboBox2_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox2_var1",
								Value = "MOLE"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "User",
						DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_User",
						Value = "MMComboBox2_MultiMapOption_4",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox2_var1",
								Value = "USER"
							}
						}
					}
				}
			});

			public object MMComboBox1_PPROP => GetValue(MMComboBox1_PPROP_Property);

			public object MMComboBox3_MultiMap => GetValue(MMComboBox3_MultiMap_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMADAset_Analys_Blend_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Blend Options.Input.PROP_NAME",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMADASet.MMADAset_Analys_Blend")]
	public class MMADAset_Analys_Blend : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraBlendOpt;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMADAset_Analys_Blend()
		{
			base.ViewModelType = typeof(MMADAset_Analys_Blend_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmadaset_analys_blend.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraBlendOpt = (MMGroupBox)target;
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
	public class MMPCCalc_Gen_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration PCMAIN_Property = CxvPropertyDeclaration.Register("PCMAIN", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration CUTS_Property = CxvPropertyDeclaration.Register("CUTS", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CUTS"
		});

		public static readonly CxvPropertyDeclaration NAMING_Property = CxvPropertyDeclaration.Register("NAMING", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NAMING"
		});

		public static readonly CxvPropertyDeclaration CUTOPT_Property = CxvPropertyDeclaration.Register("CUTOPT", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CUTOPT"
		});

		public static readonly CxvPropertyDeclaration NAMEOPT_Property = CxvPropertyDeclaration.Register("NAMEOPT", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.NAMEOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PCMAIN" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CUTS" },
			EnteredDataPaths = { "@CUTOPT" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@NAMING" },
			EnteredDataPaths = { "@NAMEOPT" }
		});

		public object PCMAIN => GetValue(PCMAIN_Property);

		public object CUTS => GetValue(CUTS_Property);

		public object NAMING => GetValue(NAMING_Property);

		public object CUTOPT => GetValue(CUTOPT_Property);

		public object NAMEOPT => GetValue(NAMEOPT_Property);

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
	[ProgId("MMADASet.MMPCCalc_Gen")]
	public class MMPCCalc_Gen : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabPC_Generation;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPCCalc_Gen()
		{
			base.ViewModelType = typeof(MMPCCalc_Gen_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_gen.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabPC_Generation = (MMTabStrip)target;
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
	public class MMPCCalc_Gen_Cuts_ViewModel : MMTabPageViewModel
	{
		public class grdRANGE_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtNInc_NINC_Property = CxvPropertyDeclaration.Register("txtNInc_NINC", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NINC.@y"
			});

			public static readonly CxvPropertyDeclaration txtIncr_INCR_Property = CxvPropertyDeclaration.Register("txtIncr_INCR", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.INCR.@y"
			});

			public static readonly CxvPropertyDeclaration txtUpper_UTEMP_Property = CxvPropertyDeclaration.Register("txtUpper_UTEMP", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UTEMP.@y"
			});

			public static readonly CxvPropertyDeclaration txtUpper_UTEMP2_Property = CxvPropertyDeclaration.Register("txtUpper_UTEMP2", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UTEMP.@y"
			});

			public object txtNInc_NINC => GetValue(txtNInc_NINC_Property);

			public object txtIncr_INCR => GetValue(txtIncr_INCR_Property);

			public object txtUpper_UTEMP => GetValue(txtUpper_UTEMP_Property);

			public object txtUpper_UTEMP2 => GetValue(txtUpper_UTEMP2_Property);

			public object txtLower_LTEMP
			{
				get
				{
					int num = Convert.ToInt32(ResolveParameter("y").ToString().Replace("#", ""));
					if (num == 0)
					{
						return ResolveViewPropertyPath("lbtuTEMP_1_LTEMP_Value", null);
					}
					CxvVariableData obj = ResolveViewPropertyPath("grdRANGE_GridData[" + (num - 1) + "].txtUpper_UTEMP2", null) as CxvVariableData;
					obj.IsReadOnly = true;
					return obj;
				}
			}
		}

		public class grdLIST_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCutTemp_var1_Property = CxvPropertyDeclaration.Register("txtCutTemp_var1", typeof(grdLIST_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LIST.@y"
			});

			public object txtCutTemp_var1 => GetValue(txtCutTemp_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraRANGE_state_Property = CxvPropertyDeclaration.Register("fraRANGE_state", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GENOPTB"
			}
		});

		public static readonly CxvPropertyDeclaration grdRANGE_GridData_Property = CxvPropertyDeclaration.Register("grdRANGE_GridData", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdRANGE_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.UTEMP",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration fraLIST_state_Property = CxvPropertyDeclaration.Register("fraLIST_state", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GENOPTA"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuCutTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuCutTemp_var1", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIST"
		});

		public static readonly CxvPropertyDeclaration grdLIST_GridData_Property = CxvPropertyDeclaration.Register("grdLIST_GridData", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLIST_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.LIST",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_PC_GEN_OPT_Property = CxvPropertyDeclaration.Register("MMComboBox1_PC_GEN_OPT", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrPCGenOpt",
					DataPath = "@main.Input.PC_GEN_OPT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "In-Range",
					DisplayResourceKey = "PCGenOpt_In_Range",
					Value = "ogrPCGenOpt_Range",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrPCGenOpt",
							Value = "IN-RANGE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "All",
					DisplayResourceKey = "PCGenOpt_All",
					Value = "ogrPCGenOpt_All",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrPCGenOpt",
							Value = "ALL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_OPT_CUTS",
					DataPath = "@main.Input.OPT_CUTS"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "List of cuts",
					DisplayResourceKey = "MMPCCalc_Gen_Cuts_ViewModel__CxvMultiMapOption_Display_List_of_cuts",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_OPT_CUTS",
							Value = "LIST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Range and increments",
					DisplayResourceKey = "MMPCCalc_Gen_Cuts_ViewModel__CxvMultiMapOption_Display_Range_and_increments",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_OPT_CUTS",
							Value = "RANGE"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTEMP_1_LTEMP_Units_Property = CxvPropertyDeclaration.Register("lbtuTEMP_1_LTEMP_Units", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UTEMP",
			ExtraDataPaths = { "@main.Input.LTEMP", "@main.Input.INCR" }
		});

		public static readonly CxvPropertyDeclaration lbtuTEMP_1_LTEMP_Value_Property = CxvPropertyDeclaration.Register("lbtuTEMP_1_LTEMP_Value", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LTEMP"
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_1_UTEMP_Units_Property = CxvPropertyDeclaration.Register("lbtuTemp_1_UTEMP_Units", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.UTEMP"
		});

		public static readonly CxvPropertyDeclaration lbtuIncrement_INCR_Property = CxvPropertyDeclaration.Register("lbtuIncrement_INCR", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.INCR"
		});

		public object fraRANGE_state => GetValue(fraRANGE_state_Property);

		public object grdRANGE_GridData => GetValue(grdRANGE_GridData_Property);

		public object fraLIST_state => GetValue(fraLIST_state_Property);

		public object lbtuCutTemp_var1 => GetValue(lbtuCutTemp_var1_Property);

		public object grdLIST_GridData => GetValue(grdLIST_GridData_Property);

		public object MMComboBox1_PC_GEN_OPT => GetValue(MMComboBox1_PC_GEN_OPT_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object lbtuTEMP_1_LTEMP_Units => GetValue(lbtuTEMP_1_LTEMP_Units_Property);

		public object lbtuTEMP_1_LTEMP_Value => GetValue(lbtuTEMP_1_LTEMP_Value_Property);

		public object lbtuTemp_1_UTEMP_Units
		{
			get
			{
				CxvVariableData obj = GetValue(lbtuTemp_1_UTEMP_Units_Property) as CxvVariableData;
				obj.IsEnabled = false;
				return obj;
			}
		}

		public object lbtuIncrement_INCR
		{
			get
			{
				CxvVariableData obj = GetValue(lbtuIncrement_INCR_Property) as CxvVariableData;
				obj.IsEnabled = false;
				return obj;
			}
		}
	}
	[ProgId("MMADASet.MMPCCalc_Gen_Cuts")]
	public class MMPCCalc_Gen_Cuts : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox fraRANGE;

		internal MMScrollArea grdRANGE;

		internal MMGroupBox fraLIST;

		internal MMScrollArea grdLIST;

		private bool _contentLoaded;

		public MMPCCalc_Gen_Cuts()
		{
			base.ViewModelType = typeof(MMPCCalc_Gen_Cuts_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_gen_cuts.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				fraRANGE = (MMGroupBox)target;
				break;
			case 7:
				grdRANGE = (MMScrollArea)target;
				break;
			case 8:
				fraLIST = (MMGroupBox)target;
				break;
			case 9:
				grdLIST = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCCalc_Gen_Naming_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_PC_LIST_Property = CxvPropertyDeclaration.Register("MMTextBox2_PC_LIST", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PC_LIST.@x",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object MMTextBox2_PC_LIST => GetValue(MMTextBox2_PC_LIST_Property);
		}

		public class grdLIST_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtLIST_PC_LIST_Property = CxvPropertyDeclaration.Register("txtLIST_PC_LIST", typeof(grdLIST_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PC_LIST.@x",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public object txtLIST_PC_LIST => GetValue(txtLIST_PC_LIST_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				base.OnSubPropertyDataChanged(pd, subPropertyName);
				if (!base.IsInitialUpdate && pd.Name == "txtLIST_PC_LIST" && subPropertyName == "Value")
				{
					(base.Parent as MMPCCalc_Gen_Naming_ViewModel).MyUpdate();
				}
			}
		}

		public class PreviewTemplate
		{
			public CellData PCName { get; set; }

			public CellData LTemp { get; set; }

			public CellData UTemp { get; set; }
		}

		public class CellData
		{
			public object Value { get; set; }

			public bool IsReadOnly => true;

			public bool? IsEnabled => false;
		}

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.PCNAME",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GENPCNM"
			}
		});

		public static readonly CxvPropertyDeclaration optOption2_MultiMap_Property = CxvPropertyDeclaration.Register("optOption2_MultiMap", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "optOption2_option",
					DataPath = "@main.Input.OPTION"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Estimated boiling point",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Estimated_boiling_point",
					Value = "optOption2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption2_option",
							Value = "NBP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Lower cut temperature",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Lower_cut_temperature",
					Value = "optOption2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption2_option",
							Value = "ROUND-DOWN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Upper cut temperature",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Upper_cut_temperature",
					Value = "optOption2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption2_option",
							Value = "ROUND-UP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Numbers starting from:",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Numbers_starting_from_",
					Value = "optOption2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption2_option",
							Value = "NUMBERED"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User defined list",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_User_defined_list",
					Value = "optOption2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption2_option",
							Value = "LIST"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PCYES"
			}
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PC_LIST",
				UseChildId = true,
				Name = "x"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTIONF"
			}
		});

		public static readonly CxvPropertyDeclaration MMTextBox1_First_No_Property = CxvPropertyDeclaration.Register("MMTextBox1_First_No", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FIRST_NO",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTIONE"
			}
		});

		public static readonly CxvPropertyDeclaration optOption1_MultiMap_Property = CxvPropertyDeclaration.Register("optOption1_MultiMap", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "optOption1_option",
					DataPath = "@main.Input.OPTION"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Calculated boiling point",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Calculated_boiling_point",
					Value = "optOption1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption1_option",
							Value = "NBP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Lower cut temperature",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Lower_cut_temperature_1",
					Value = "optOption1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption1_option",
							Value = "ROUND-DOWN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Upper cut temperature",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Upper_cut_temperature_1",
					Value = "optOption1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption1_option",
							Value = "ROUND-UP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Numbers starting from:",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Numbers_starting_from__1",
					Value = "optOption1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption1_option",
							Value = "NUMBERED"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User defined list",
					DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_User_defined_list_1",
					Value = "optOption1_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "optOption1_option",
							Value = "LIST"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PCNO"
			}
		});

		public static readonly CxvPropertyDeclaration txtFirstNo_First_No_Property = CxvPropertyDeclaration.Register("txtFirstNo_First_No", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FIRST_NO",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTIONE"
			}
		});

		public static readonly CxvPropertyDeclaration grdLIST_GridData_Property = CxvPropertyDeclaration.Register("grdLIST_GridData", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLIST_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PC_LIST",
				UseChildId = true,
				Name = "x"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.OPTIONF"
			}
		});

		private int _numRows;

		private ICxsDataWatch _optionWatch;

		private ICxsDataWatch _itemsWatch;

		private ObservableCollection<PreviewTemplate> _PreviewSource = new ObservableCollection<PreviewTemplate>();

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object optOption2_MultiMap => GetValue(optOption2_MultiMap_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);

		public object MMTextBox1_First_No => GetValue(MMTextBox1_First_No_Property);

		public object optOption1_MultiMap => GetValue(optOption1_MultiMap_Property);

		public object txtFirstNo_First_No => GetValue(txtFirstNo_First_No_Property);

		public object grdLIST_GridData => GetValue(grdLIST_GridData_Property);

		public ObservableCollection<PreviewTemplate> PreviewSource
		{
			get
			{
				return _PreviewSource;
			}
			set
			{
				_PreviewSource = value;
			}
		}

		private void MyUpdate()
		{
			if (_itemsWatch != null)
			{
				_itemsWatch.ValuesChanged -= _itemsWatch_ValuesChanged;
				_itemsWatch.Unload();
				_itemsWatch = null;
			}
			_itemsWatch = CreateCxsWatch();
			PreviewSource.Clear();
			string text = null;
			double num = double.NaN;
			string text2 = null;
			string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.PCNAME", "value"));
			string text4 = null;
			double CutLower = double.NaN;
			int CutLength = 0;
			List<double> list = new List<double>();
			List<double> list2 = new List<double>();
			List<int> list3 = new List<int>();
			bool flag = false;
			string text5 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.OPT_CUTS", "value"));
			if (!(text5 == "LIST"))
			{
				if (text5 == "RANGE")
				{
					text4 = CxsConverter.ValueToString(GetValueInF("LTEMP"));
					if (!string.IsNullOrEmpty(text4))
					{
						CutLower = CxsConverter.ValueToDouble(text4).Value;
						CutLength = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.UTEMP", "child_count")).GetValueOrDefault() - 1;
						for (int i = 0; i <= CutLength; i++)
						{
							_itemsWatch.AddWatch(ExpandDataPath("@main.Input.UTEMP.#" + i), "value");
							text4 = CxsConverter.ValueToString(GetValueInF("UTEMP.#" + i));
							if (!string.IsNullOrEmpty(text4))
							{
								list.Add(CxsConverter.ValueToDouble(text4).Value);
							}
							else
							{
								list.Add(0.0);
							}
							_itemsWatch.AddWatch(ExpandDataPath("@main.Input.NINC.#" + i), "value");
							text4 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.NINC.#" + i, "value"));
							if (!string.IsNullOrEmpty(text4))
							{
								list3.Add(CxsConverter.ValueToInt32(text4).Value);
							}
							else
							{
								list3.Add(0);
							}
							_itemsWatch.AddWatch(ExpandDataPath("@main.Input.INCR.#" + i), "value");
							text4 = CxsConverter.ValueToString(GetValueInF("INCR.#" + i));
							if (!string.IsNullOrEmpty(text4))
							{
								list2.Add(CxsConverter.ValueToDouble(text4).Value);
							}
							else
							{
								list2.Add(0.0);
							}
						}
						flag = true;
					}
					else
					{
						SetDefaultCutsList(ref CutLength, ref CutLower, list, list2, list3);
						flag = true;
					}
				}
				else
				{
					_numRows = 0;
					flag = false;
				}
			}
			else
			{
				int valueOrDefault = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.LIST", "child_count")).GetValueOrDefault();
				if (valueOrDefault > 0)
				{
					_numRows = valueOrDefault - 1;
					PreviewSource.Clear();
					for (int j = 0; j < _numRows; j++)
					{
						PreviewTemplate previewTemplate = new PreviewTemplate();
						previewTemplate.LTemp = new CellData
						{
							Value = GetValueInF("LIST.#" + j)
						};
						if (valueOrDefault > 1)
						{
							previewTemplate.UTemp = new CellData
							{
								Value = GetValueInF("LIST.#" + (j + 1))
							};
						}
						else
						{
							previewTemplate.UTemp = previewTemplate.LTemp;
						}
						PreviewSource.Add(previewTemplate);
					}
					flag = false;
				}
				else
				{
					SetDefaultCutsList(ref CutLength, ref CutLower, list, list2, list3);
					flag = true;
				}
			}
			if (flag)
			{
				PreviewSource.Clear();
				_numRows = 0;
				num = CutLower;
				for (int k = 0; k <= CutLength && k < list3.Count; k++)
				{
					if (list3[k] != 0)
					{
						list2[k] = (list[k] - num) / (double)list3[k];
					}
					else if (list2[k] == 0.0)
					{
						break;
					}
					do
					{
						PreviewTemplate previewTemplate2 = new PreviewTemplate();
						previewTemplate2.LTemp = new CellData
						{
							Value = num
						};
						num += list2[k];
						previewTemplate2.UTemp = new CellData
						{
							Value = num
						};
						PreviewSource.Add(previewTemplate2);
						_numRows++;
					}
					while (num < list[k]);
					num = list[k];
				}
			}
			text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.OPTION", "value"));
			text2 = text;
			if (!(text == "NBP"))
			{
				switch (text)
				{
				case "ROUND-DOWN":
				{
					for (int n = 0; n < _numRows; n++)
					{
						if (text3 == "YES")
						{
							PreviewSource[n].PCName = new CellData
							{
								Value = ExpandDataPathAndGet("@main.Input.PC_LIST.#" + n, "value")
							};
						}
						else
						{
							PreviewSource[n].PCName = new CellData
							{
								Value = "PC" + Math.Floor(double.Parse(PreviewSource[n].LTemp.Value.ToString())) + "F"
							};
						}
					}
					break;
				}
				case "ROUND-UP":
				{
					for (int num4 = 0; num4 < _numRows; num4++)
					{
						if (text3 == "YES")
						{
							PreviewSource[num4].PCName = new CellData
							{
								Value = ExpandDataPathAndGet("@main.Input.PC_LIST.#" + num4, "value")
							};
						}
						else
						{
							PreviewSource[num4].PCName = new CellData
							{
								Value = "PC" + Math.Floor(double.Parse(PreviewSource[num4].UTemp.Value.ToString())) + "F"
							};
						}
					}
					break;
				}
				case "NUMBERED":
				{
					int valueOrDefault2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.FIRST_NO", "value")).GetValueOrDefault();
					for (int m = 0; m < _numRows; m++)
					{
						if (text3 == "YES")
						{
							PreviewSource[m].PCName = new CellData
							{
								Value = ExpandDataPathAndGet("@main.Input.PC_LIST.#" + m, "value")
							};
						}
						else
						{
							PreviewSource[m].PCName = new CellData
							{
								Value = "PC" + (valueOrDefault2 + m)
							};
						}
					}
					break;
				}
				case "LIST":
				{
					int num2 = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.PC_LIST", "child_count")).Value - 1;
					int num3 = 0;
					num3 = ((num2 <= _numRows) ? num2 : _numRows);
					for (int l = 0; l <= num3; l++)
					{
						if (l < PreviewSource.Count)
						{
							PreviewSource[l].PCName = new CellData
							{
								Value = ExpandDataPathAndGet("@main.Input.PC_LIST.#" + l, "value")
							};
						}
					}
					break;
				}
				}
			}
			else if (text3 == "YES")
			{
				for (int num5 = 0; num5 < _numRows; num5++)
				{
					PreviewSource[num5].PCName = new CellData
					{
						Value = ExpandDataPathAndGet("@main.Input.PC_LIST.#" + num5, "value")
					};
				}
			}
			if (text2 == "NBP" && text3 == "NO")
			{
				PreviewSource.Clear();
			}
			_ = _itemsWatch.Values;
			_itemsWatch.ValuesChanged += _itemsWatch_ValuesChanged;
		}

		private void _itemsWatch_ValuesChanged(object sender, EventArgs e)
		{
			MyUpdate();
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				MyUpdate();
				string text = ExpandDataPath("@main.Input.OPT_CUTS");
				if (!string.IsNullOrEmpty(text))
				{
					_optionWatch = CreateCxsWatch();
					_optionWatch.AddWatch(text, "value");
					_optionWatch.AddWatch(ExpandDataPath("@main.Input.LIST"), "child_count");
					_optionWatch.AddWatch(ExpandDataPath("@main.Input.UTEMP"), "child_count");
					_ = _optionWatch.Values;
					_optionWatch.ValuesChanged += _optionWatch_ValuesChanged;
				}
			}
		}

		public override void Unload()
		{
			base.Unload();
			if (_optionWatch != null)
			{
				_optionWatch.ValuesChanged -= _optionWatch_ValuesChanged;
				_optionWatch.Unload();
				_optionWatch = null;
			}
			if (_itemsWatch != null)
			{
				_itemsWatch.ValuesChanged -= _itemsWatch_ValuesChanged;
				_itemsWatch.Unload();
				_itemsWatch = null;
			}
		}

		private void _optionWatch_ValuesChanged(object sender, EventArgs e)
		{
			MyUpdate();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (!base.IsInitialUpdate)
			{
				if (pd.Name == "optOption2_MultiMap" && subPropertyName == "Value")
				{
					MyUpdate();
				}
				else if (pd.Name == "optOption1_MultiMap" && subPropertyName == "Value")
				{
					MyUpdate();
				}
				else if (pd.Name == "MMCheckBox1_var1" && subPropertyName == "Value")
				{
					MyUpdate();
				}
				else if (pd.Name == "MMTextBox1_First_No" && subPropertyName == "Value")
				{
					MyUpdate();
				}
			}
		}

		private static void SetDefaultCutsList(ref int CutLength, ref double CutLower, List<double> CutUpper, List<double> CutIncr, List<int> CutNInc)
		{
			CutLength = 2;
			CutLower = 100.0;
			CutUpper.Add(800.0);
			CutUpper.Add(1200.0);
			CutUpper.Add(1600.0);
			CutIncr.Add(25.0);
			CutIncr.Add(50.0);
			CutIncr.Add(100.0);
			CutNInc.Add(0);
			CutNInc.Add(0);
			CutNInc.Add(0);
		}

		private object GetValueInF(string path)
		{
			return ExpandDataPathAndGet("@main.Input." + path, "value", "F");
		}
	}
	[ProgId("MMADASet.MMPCCalc_Gen_Naming")]
	public class MMPCCalc_Gen_Naming : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup optOption2;

		internal MMOptionButton optOption2_opt0;

		internal MMOptionButton optOption2_opt1;

		internal MMOptionButton optOption2_opt2;

		internal MMOptionButton optOption2_opt3;

		internal MMValueEdit MMTextBox1;

		internal MMOptionButton optOption2_opt4;

		internal MMScrollArea MMScrollArea1;

		internal MMOptionGroup optOption1;

		internal MMOptionButton optOption1_opt0;

		internal MMOptionButton optOption1_opt1;

		internal MMOptionButton optOption1_opt2;

		internal MMOptionButton optOption1_opt3;

		internal MMValueEdit txtFirstNo;

		internal MMOptionButton optOption1_opt4;

		internal MMScrollArea grdLIST;

		internal MMCheckBox MMCheckBox1;

		internal MMGroupBox fraNames;

		internal MMScrollArea grdPreview;

		private bool _contentLoaded;

		public MMPCCalc_Gen_Naming()
		{
			base.ViewModelType = typeof(MMPCCalc_Gen_Naming_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_gen_naming.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				optOption2 = (MMOptionGroup)target;
				break;
			case 2:
				optOption2_opt0 = (MMOptionButton)target;
				break;
			case 3:
				optOption2_opt1 = (MMOptionButton)target;
				break;
			case 4:
				optOption2_opt2 = (MMOptionButton)target;
				break;
			case 5:
				optOption2_opt3 = (MMOptionButton)target;
				break;
			case 6:
				MMTextBox1 = (MMValueEdit)target;
				break;
			case 7:
				optOption2_opt4 = (MMOptionButton)target;
				break;
			case 8:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			case 9:
				optOption1 = (MMOptionGroup)target;
				break;
			case 10:
				optOption1_opt0 = (MMOptionButton)target;
				break;
			case 11:
				optOption1_opt1 = (MMOptionButton)target;
				break;
			case 12:
				optOption1_opt2 = (MMOptionButton)target;
				break;
			case 13:
				optOption1_opt3 = (MMOptionButton)target;
				break;
			case 14:
				txtFirstNo = (MMValueEdit)target;
				break;
			case 15:
				optOption1_opt4 = (MMOptionButton)target;
				break;
			case 16:
				grdLIST = (MMScrollArea)target;
				break;
			case 17:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 18:
				fraNames = (MMGroupBox)target;
				break;
			case 19:
				grdPreview = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCCalc_Gen_Spec_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_wf_Property = CxvPropertyDeclaration.Register("MMTextBox1_wf", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.WF.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_AID_Property = CxvPropertyDeclaration.Register("MMComboBox1_AID", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.WF.@y"
			});

			public object MMTextBox1_wf => GetValue(MMTextBox1_wf_Property);

			public object MMComboBox1_AID => GetValue(MMComboBox1_AID_Property);
		}

		public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMPCCalc_Gen_Spec_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.PCOPSETNAME"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Gen_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.WF",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMADASet.MMPCCalc_Gen_Spec")]
	public class MMPCCalc_Gen_Spec : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		internal MMGroupBox MMFrame2;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		private bool _contentLoaded;

		public MMPCCalc_Gen_Spec()
		{
			base.ViewModelType = typeof(MMPCCalc_Gen_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_gen_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
			case 3:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 4:
				MMComboBox2_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox2 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCCalc_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration kvisc_Property = CxvPropertyDeclaration.Register("kvisc", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.KVISC"
		});

		public static readonly CxvPropertyDeclaration visc_Property = CxvPropertyDeclaration.Register("visc", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.VISC"
		});

		public static readonly CxvPropertyDeclaration PPPROP_Property = CxvPropertyDeclaration.Register("PPPROP", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.Prop Data.PPPROP"
		});

		public static readonly CxvPropertyDeclaration visctype_Property = CxvPropertyDeclaration.Register("visctype", typeof(MMPCCalc_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "visctype"
		});

		public static readonly CxvPropertyDeclaration my_visc_Property = CxvPropertyDeclaration.Register("my_visc", typeof(MMPCCalc_Result_ViewModel), new CxvParameterProperty
		{
			Parameter = "my_visc"
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCCalc_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@PPPROP" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCCalc_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@kvisc", "@visc" }
		});

		public object kvisc => GetValue(kvisc_Property);

		public object visc => GetValue(visc_Property);

		public object PPPROP => GetValue(PPPROP_Property);

		public object visctype => GetValue(visctype_Property);

		public object my_visc => GetValue(my_visc_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMADASet.MMPCCalc_Result")]
	public class MMPCCalc_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMPCCalc_Result()
		{
			base.ViewModelType = typeof(MMPCCalc_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCCalc_Result_Petrop_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@TRAYoutp",
					UseChildId = true,
					Name = "y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@TRAYoutp.#0.@z",
				ExposeAs = CxvVariableTypeCode.Id
			});

			public object inner => GetValue(inner_Property);

			public object MMTextBox8_var1 => GetValue(MMTextBox8_var1_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@TRAYoutp.@y.@z"
			});

			private CxvPropertyWatch varDefnDependencies;

			private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMLBUText_units
			{
				get
				{
					CxvVariableProperty property = new CxvVariableProperty
					{
						DataPath = "@TRAYoutp.@y.@z"
					};
					return new CxvVariableData(this, property);
				}
			}

			public object MMLBUText_unitsHeader
			{
				get
				{
					string dataPath = "@TRAYoutp.@y";
					CxvVariableProperty property = new CxvVariableProperty
					{
						DataPath = dataPath,
						ExposeAs = CxvVariableTypeCode.IdThreeLevel
					};
					return new CxvVariableData(this, property);
				}
			}

			public object MMLBUText_value => new CxvManualVariableData
			{
				Value = GetMMLBUText_value()
			};

			private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
			{
				get
				{
					if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
					{
						_varDefnDependencies_PropertyDependencyChangedHandler = delegate
						{
							OnPropertyChanged("MMLBUText_value");
						};
					}
					return _varDefnDependencies_PropertyDependencyChangedHandler;
				}
			}

			private string GetMMLBUText_value()
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
				string units = CxsConverter.ValueToString(ExpandDataPathAndGet("@TRAYoutp.@y.@z", "uom", null, varDefnDependencies));
				if (!varDefnDependencies.IsEmpty)
				{
					varDefnDependencies.PropertyDependencyChanged += varDefnDependencies_PropertyDependencyChangedHandler;
				}
				else
				{
					varDefnDependencies = null;
				}
				return CxsConverter.ValueToString(ExpandDataPathAndGet("@TRAYoutp.@y.@z", "value", units));
			}
		}

		public static readonly CxvPropertyDeclaration TRAYoutp_Property = CxvPropertyDeclaration.Register("TRAYoutp", typeof(MMPCCalc_Result_Petrop_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.Prop Data.PPPROP"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Result_Petrop_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@TRAYoutp.#0",
				UseChildId = true,
				Name = "z"
			}
		});

		public object TRAYoutp => GetValue(TRAYoutp_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMADASet.MMPCCalc_Result_Petrop")]
	public class MMPCCalc_Result_Petrop : MMTabPage, IComponentConnector
	{
		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMPCCalc_Result_Petrop()
		{
			base.ViewModelType = typeof(MMPCCalc_Result_Petrop_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_result_petrop.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMPCCalc_Result_Summary_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox8_sg_Property = CxvPropertyDeclaration.Register("MMTextBox8_sg", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.VAL2.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_COMP_NAMES_Property = CxvPropertyDeclaration.Register("MMTextBox1_COMP_NAMES", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.COMP_NAMES.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox7_PCMX_Property = CxvPropertyDeclaration.Register("MMTextBox7_PCMX", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.PCMX.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox6_TCMX_Property = CxvPropertyDeclaration.Register("MMTextBox6_TCMX", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.TCMX.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox5_MW_Property = CxvPropertyDeclaration.Register("MMTextBox5_MW", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.MW.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox4_sg_Property = CxvPropertyDeclaration.Register("MMTextBox4_sg", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.SG.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_API_Property = CxvPropertyDeclaration.Register("MMTextBox3_API", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.API.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_NBP_Property = CxvPropertyDeclaration.Register("MMTextBox2_NBP", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Results.Output.VAL1.@y"
			});

			public object MMTextBox8_sg => GetValue(MMTextBox8_sg_Property);

			public object MMTextBox1_COMP_NAMES => GetValue(MMTextBox1_COMP_NAMES_Property);

			public object MMTextBox7_PCMX => GetValue(MMTextBox7_PCMX_Property);

			public object MMTextBox6_TCMX => GetValue(MMTextBox6_TCMX_Property);

			public object MMTextBox5_MW => GetValue(MMTextBox5_MW_Property);

			public object MMTextBox4_sg => GetValue(MMTextBox4_sg_Property);

			public object MMTextBox3_API => GetValue(MMTextBox3_API_Property);

			public object MMTextBox2_NBP => GetValue(MMTextBox2_NBP_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText3_PC_Units_Property = CxvPropertyDeclaration.Register("MMLBUText3_PC_Units", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.PCMX"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_TCUnits_Property = CxvPropertyDeclaration.Register("MMLBUText2_TCUnits", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.TCMX"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_NBPUnits_Property = CxvPropertyDeclaration.Register("MMLBUText1_NBPUnits", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.VAL1"
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Results.Output.COMP_NAMES",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMLBUText3_PC_Units => GetValue(MMLBUText3_PC_Units_Property);

		public object MMLBUText2_TCUnits => GetValue(MMLBUText2_TCUnits_Property);

		public object MMLBUText1_NBPUnits => GetValue(MMLBUText1_NBPUnits_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMADASet.MMPCCalc_Result_Summary")]
	public class MMPCCalc_Result_Summary : MMTabPage, IComponentConnector
	{
		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMPCCalc_Result_Summary()
		{
			base.ViewModelType = typeof(MMPCCalc_Result_Summary_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_result_summary.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMPCCalc_Result_Viscos_ViewModel : MMTabPageViewModel
	{
		public class grdMyVisc_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtViscosity_var1_Property = CxvPropertyDeclaration.Register("txtViscosity_var1", typeof(grdMyVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@dec_xsp.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdMyVisc_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@dec_xsp.#0",
					UseChildId = true,
					Name = "x"
				}
			});

			public object txtViscosity_var1 => GetValue(txtViscosity_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtComponent_var1_Property = CxvPropertyDeclaration.Register("txtComponent_var1", typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "x"
			});

			public static readonly CxvPropertyDeclaration txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@dec_xsp.@y.@x"
			});

			public object txtComponent_var1 => GetValue(txtComponent_var1_Property);

			public object txtValue_var1 => GetValue(txtValue_var1_Property);
		}

		private class ColumnHeaderConverter : IValueConverter
		{
			public static ColumnHeaderConverter Converter = new ColumnHeaderConverter();

			public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
			{
				return value?.ToString().Replace("\"", "");
			}

			public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
			{
				throw new NotImplementedException();
			}
		}

		public static readonly CxvPropertyDeclaration Advcbo_var1_Property = CxvPropertyDeclaration.Register("Advcbo_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvParameterProperty
		{
			Parameter = "visctype"
		});

		public static readonly CxvPropertyDeclaration lbtuViscUnit_var1_Property = CxvPropertyDeclaration.Register("lbtuViscUnit_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.VISC"
		});

		public static readonly CxvPropertyDeclaration dec_xsp_Property = CxvPropertyDeclaration.Register("dec_xsp", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.@my_visc"
		});

		public static readonly CxvPropertyDeclaration grdMyVisc_GridData_Property = CxvPropertyDeclaration.Register("grdMyVisc_GridData", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdMyVisc_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@dec_xsp",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuKViscUnit_var1_Property = CxvPropertyDeclaration.Register("lbtuKViscUnit_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Results.Output.KVISC"
		});

		public static readonly CxvPropertyDeclaration Advcbo_AdvCollection_Property = CxvPropertyDeclaration.Register("Advcbo_AdvCollection", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvPropertySelector
		{
			Choices = 
			{
				new CxvPropertyChoice
				{
					Operator = CxvLogicalOperator.And,
					Conditions = 
					{
						new CxvLogicalTest
						{
							DataPath = "@main.Results.Output.VISC",
							Operator = CxvLogicalOperator.GreaterThan,
							DataAttribute = "child_count",
							Value = 0
						},
						new CxvLogicalTest
						{
							DataPath = "@main.Results.Output.KVISC",
							Operator = CxvLogicalOperator.GreaterThan,
							DataAttribute = "child_count",
							Value = 0
						}
					},
					Property = new CxvAdvCollectionProperty
					{
						UseItemsCollection = true,
						Items = 
						{
							new CxvAdvCollectionItem
							{
								Display = "Absolute viscosity",
								DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Absolute_viscosity"
							},
							new CxvAdvCollectionItem
							{
								Display = "Kinematic viscosity",
								DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
							}
						},
						SelectedItemBinding = "Advcbo_var1.Value",
						CreateNewPrompt = "Type:",
						CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
						IsCalculated = true
					}
				},
				new CxvPropertyChoice
				{
					Conditions = 
					{
						new CxvLogicalTest
						{
							DataPath = "@main.Results.Output.KVISC",
							Operator = CxvLogicalOperator.GreaterThan,
							DataAttribute = "child_count",
							Value = 0
						}
					},
					Property = new CxvAdvCollectionProperty
					{
						UseItemsCollection = true,
						Items = 
						{
							new CxvAdvCollectionItem
							{
								Display = "Kinematic viscosity",
								DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
							}
						},
						SelectedItemBinding = "Advcbo_var1.Value",
						CreateNewPrompt = "Type:",
						CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
						IsCalculated = true
					}
				},
				new CxvPropertyChoice
				{
					IsDefaultChoice = true,
					Property = new CxvAdvCollectionProperty
					{
						UseItemsCollection = true,
						Items = 
						{
							new CxvAdvCollectionItem
							{
								Display = "Absolute viscosity",
								DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Absolute_viscosity"
							}
						},
						SelectedItemBinding = "Advcbo_var1.Value",
						CreateNewPrompt = "Type:",
						CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
						IsCalculated = true
					}
				}
			}
		});

		private string _viscosityCaption = string.Format(Resources.MMPCCalc_Result_Viscos_ViewModel__ViscosityCaption, string.Empty);

		private CxvPropertyWatch _unitWatch;

		private Visibility _visc_Visibility;

		private Visibility _kvisc_Visibility;

		public object Advcbo_var1 => GetValue(Advcbo_var1_Property);

		public object lbtuViscUnit_var1 => GetValue(lbtuViscUnit_var1_Property);

		public object dec_xsp => GetValue(dec_xsp_Property);

		public object grdMyVisc_GridData => GetValue(grdMyVisc_GridData_Property);

		public object lbtuKViscUnit_var1 => GetValue(lbtuKViscUnit_var1_Property);

		public object Advcbo_AdvCollection => GetValue(Advcbo_AdvCollection_Property);

		public string ViscosityCaption
		{
			get
			{
				return _viscosityCaption;
			}
			set
			{
				_viscosityCaption = value;
				OnPropertyChanged("ViscosityCaption");
			}
		}

		public Visibility Visc_Visibility
		{
			get
			{
				return _visc_Visibility;
			}
			set
			{
				_visc_Visibility = value;
				OnPropertyChanged("Visc_Visibility");
			}
		}

		public Visibility KVisc_Visibility
		{
			get
			{
				return _kvisc_Visibility;
			}
			set
			{
				_kvisc_Visibility = value;
				OnPropertyChanged("KVisc_Visibility");
			}
		}

		public IValueConverter LabelConverter => ColumnHeaderConverter.Converter;

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "Advcbo_var1" && subPropertyName == "Value")
			{
				UpdateUI();
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				UpdateUI();
			}
		}

		private void UpdateUI()
		{
			if (_unitWatch == null)
			{
				_unitWatch = new CxvPropertyWatch();
			}
			else
			{
				_unitWatch.PropertyDependencyChanged -= _unitWatch_PropertyDependencyChanged;
				_unitWatch.Clear();
			}
			string text = CxsConverter.ValueToString(this.ResolveViewPropertyPath("Advcbo_var1.Value"));
			if (text == "Absolute viscosity" || text == Resources.MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Absolute_viscosity)
			{
				ResolveUpdateParameter("my_visc", "VISC");
				Visc_Visibility = Visibility.Visible;
				KVisc_Visibility = Visibility.Collapsed;
				ViscosityCaption = string.Format(Resources.MMPCCalc_Result_Viscos_ViewModel__ViscosityCaption, CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Results.Output.RTV_UNIT", "value", null, _unitWatch)));
			}
			else if (text == "Kinematic viscosity" || text == Resources.MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity)
			{
				ResolveUpdateParameter("my_visc", "KVISC");
				Visc_Visibility = Visibility.Collapsed;
				KVisc_Visibility = Visibility.Visible;
				ViscosityCaption = string.Format(Resources.MMPCCalc_Result_Viscos_ViewModel__ViscosityCaption, CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Results.Output.RTKV_UNIT", "value", null, _unitWatch)));
			}
			if (!_unitWatch.IsEmpty)
			{
				_unitWatch.PropertyDependencyChanged += _unitWatch_PropertyDependencyChanged;
			}
		}

		private void _unitWatch_PropertyDependencyChanged(object sender, EventArgs e)
		{
			UpdateUI();
		}
	}
	[ProgId("MMADASet.MMPCCalc_Result_Viscos")]
	public class MMPCCalc_Result_Viscos : MMTabPage, IComponentConnector
	{
		internal MMLabel Advcbo_label;

		internal MMComboEdit Advcbo;

		internal MMLabel lbtuViscUnit_label;

		internal MMLabel lbtuKViscUnit_label;

		internal MMVariableEdit lbtuViscUnit;

		internal MMVariableEdit lbtuKViscUnit;

		internal MMGroupBox fraViscosityResults;

		internal MMScrollArea grdMyVisc;

		private bool _contentLoaded;

		public MMPCCalc_Result_Viscos()
		{
			base.ViewModelType = typeof(MMPCCalc_Result_Viscos_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpccalc_result_viscos.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				Advcbo_label = (MMLabel)target;
				break;
			case 2:
				Advcbo = (MMComboEdit)target;
				break;
			case 3:
				lbtuViscUnit_label = (MMLabel)target;
				break;
			case 4:
				lbtuKViscUnit_label = (MMLabel)target;
				break;
			case 5:
				lbtuViscUnit = (MMVariableEdit)target;
				break;
			case 6:
				lbtuKViscUnit = (MMVariableEdit)target;
				break;
			case 7:
				fraViscosityResults = (MMGroupBox)target;
				break;
			case 8:
				grdMyVisc = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCProp_Spec_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration PCMAIN_Property = CxvPropertyDeclaration.Register("PCMAIN", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration MAINOPT_Property = CxvPropertyDeclaration.Register("MAINOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAINOPT"
		});

		public static readonly CxvPropertyDeclaration EOSOPT_Property = CxvPropertyDeclaration.Register("EOSOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOSOPT"
		});

		public static readonly CxvPropertyDeclaration HEATOPT_Property = CxvPropertyDeclaration.Register("HEATOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.HEATOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PCMAIN" },
			EnteredDataPaths = { "@MAINOPT" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@HEATOPT" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@EOSOPT" }
		});

		public object PCMAIN => GetValue(PCMAIN_Property);

		public object MAINOPT => GetValue(MAINOPT_Property);

		public object EOSOPT => GetValue(EOSOPT_Property);

		public object HEATOPT => GetValue(HEATOPT_Property);

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
	[ProgId("MMADASet.MMPCProp_Spec")]
	public class MMPCProp_Spec : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabMMPCProp_Spec;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMPCProp_Spec()
		{
			base.ViewModelType = typeof(MMPCProp_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpcprop_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabMMPCProp_Spec = (MMTabStrip)target;
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
	public class MMPCProp_Spec_EOS_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboVCBWR_MultiMap_Property = CxvPropertyDeclaration.Register("cboVCBWR_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboVCBWR_VCBWR",
					DataPath = "@main.Input.VCBWR"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
					Value = "cboVCBWR_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVCBWR_VCBWR",
							Value = "VCSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCBWRU",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU",
					Value = "cboVCBWR_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVCBWR_VCBWR",
							Value = "VCBWRUSR"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboTCBWR_MultiMap_Property = CxvPropertyDeclaration.Register("cboTCBWR_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboTCBWR_TCBWR",
					DataPath = "@main.Input.TCBWR"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al__1",
					Value = "cboTCBWR_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTCBWR_TCBWR",
							Value = "TCSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCBWRU",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU_1",
					Value = "cboTCBWR_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboTCBWR_TCBWR",
							Value = "TCBWRUSR"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboBWRGMA_MultiMap_Property = CxvPropertyDeclaration.Register("cboBWRGMA_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboBWRGMA_BWRGMA",
					DataPath = "@main.Input.BWRGMA"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al__2",
					Value = "cboBWRGMA_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboBWRGMA_BWRGMA",
							Value = "GMASTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCBWRU",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU_2",
					Value = "cboBWRGMA_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboBWRGMA_BWRGMA",
							Value = "GMAUSR"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboRKSKIJ_MultiMap_Property = CxvPropertyDeclaration.Register("cboRKSKIJ_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboRKSKIJ_RKSKIJ",
					DataPath = "@main.Input.RKSKIJ"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "API, 3rd Ed.",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_API__3rd_Ed_",
					Value = "cboRKSKIJ_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRKSKIJ_RKSKIJ",
							Value = "API78"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API, 5th Ed.",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_API__5th_Ed_",
					Value = "cboRKSKIJ_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRKSKIJ_RKSKIJ",
							Value = "API87"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCRKIU",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCRKIU",
					Value = "cboRKSKIJ_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRKSKIJ_RKSKIJ",
							Value = "KIJUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCRKIU2",
					DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCRKIU2",
					Value = "cboRKSKIJ_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRKSKIJ_RKSKIJ",
							Value = "KIJUSR2"
						}
					}
				}
			}
		});

		public object cboVCBWR_MultiMap => GetValue(cboVCBWR_MultiMap_Property);

		public object cboTCBWR_MultiMap => GetValue(cboTCBWR_MultiMap_Property);

		public object cboBWRGMA_MultiMap => GetValue(cboBWRGMA_MultiMap_Property);

		public object cboRKSKIJ_MultiMap => GetValue(cboRKSKIJ_MultiMap_Property);
	}
	[ProgId("MMADASet.MMPCProp_Spec_EOS")]
	public class MMPCProp_Spec_EOS : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraEOS;

		internal MMLabel cboRKSKIJ_label;

		internal MMComboEdit cboRKSKIJ;

		internal MMLabel cboBWRGMA_label;

		internal MMComboEdit cboBWRGMA;

		internal MMLabel cboTCBWR_label;

		internal MMComboEdit cboTCBWR;

		internal MMLabel cboVCBWR_label;

		internal MMComboEdit cboVCBWR;

		private bool _contentLoaded;

		public MMPCProp_Spec_EOS()
		{
			base.ViewModelType = typeof(MMPCProp_Spec_EOS_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpcprop_spec_eos.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraEOS = (MMGroupBox)target;
				break;
			case 2:
				cboRKSKIJ_label = (MMLabel)target;
				break;
			case 3:
				cboRKSKIJ = (MMComboEdit)target;
				break;
			case 4:
				cboBWRGMA_label = (MMLabel)target;
				break;
			case 5:
				cboBWRGMA = (MMComboEdit)target;
				break;
			case 6:
				cboTCBWR_label = (MMLabel)target;
				break;
			case 7:
				cboTCBWR = (MMComboEdit)target;
				break;
			case 8:
				cboVCBWR_label = (MMLabel)target;
				break;
			case 9:
				cboVCBWR = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCProp_Spec_Heat_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboCPIG_MultiMap_Property = CxvPropertyDeclaration.Register("cboCPIG_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboCPIG_CPIG",
					DataPath = "@main.Input.CPIG"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee",
					Value = "cboCPIG_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Tsang-Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen",
					Value = "cboCPIG_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
					Value = "cboCPIG_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cavett",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Cavett",
					Value = "cboCPIG_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGCAVT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Mathias and Monks",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Mathias_and_Monks",
					Value = "cboCPIG_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPMM"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCCPGU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCCPGU",
					Value = "cboCPIG_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API Hybrid",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API_Hybrid",
					Value = "cboCPIG_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGAPI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Simplified-Lee-Kesler",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Simplified_Lee_Kesler",
					Value = "cboCPIG_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGSKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Cavett",
					Value = "cboCPIG_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCPIG_CPIG",
							Value = "CPIGHYS"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboDHVL_MultiMap_Property = CxvPropertyDeclaration.Register("cboDHVL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDHVL_DHVL",
					DataPath = "@main.Input.DHVL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vetere",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Vetere",
					Value = "cboDHVL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHVL_DHVL",
							Value = "DHVLVET"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCDHVU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDHVU",
					Value = "cboDHVL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHVL_DHVL",
							Value = "DHVLUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kistiakowsky",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Kistiakowsky",
					Value = "cboDHVL_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHVL_DHVL",
							Value = "DHVLKIST"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboDHFORM_MultiMap_Property = CxvPropertyDeclaration.Register("cboDHFORM_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDHFORM_DHFORM",
					DataPath = "@main.Input.DHFORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Defaults to zero",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Defaults_to_zero",
					Value = "cboDHFORM_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMZERO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister",
					Value = "cboDHFORM_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMONT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCDHFU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDHFU",
					Value = "cboDHFORM_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister-API",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API",
					Value = "cboDHFORM_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMAPI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister-API97",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API97",
					Value = "cboDHFORM_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMONT2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Default",
					Value = "cboDHFORM_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMHYS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation",
					Value = "cboDHFORM_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDHFORM_DHFORM",
							Value = "DHFMEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboDGFORM_MultiMap_Property = CxvPropertyDeclaration.Register("cboDGFORM_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDGFORM_DGFORM",
					DataPath = "@main.Input.DGFORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Defaults to zero",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Defaults_to_zero_1",
					Value = "cboDGFORM_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDGFORM_DGFORM",
							Value = "DGFMZERO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCDGFU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDGFU",
					Value = "cboDGFORM_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDGFORM_DGFORM",
							Value = "DGFMUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_1",
					Value = "cboDGFORM_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDGFORM_DGFORM",
							Value = "DGFMONT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister-API97",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API97_1",
					Value = "cboDGFORM_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDGFORM_DGFORM",
							Value = "DGFMONT2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_1",
					Value = "cboDGFORM_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDGFORM_DGFORM",
							Value = "DGFMEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboWATSOL_MultiMap_Property = CxvPropertyDeclaration.Register("cboWATSOL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboWATSOL_WATSOL",
					DataPath = "@main.Input.WATSOL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Aspen model",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_model",
					Value = "cboWATSOL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWATSOL_WATSOL",
							Value = "WSOLASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API, Kerosene line",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API__Kerosene_line",
					Value = "cboWATSOL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWATSOL_WATSOL",
							Value = "KEROSENE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCWSLU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCWSLU",
					Value = "cboWATSOL_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWATSOL_WATSOL",
							Value = "WSOLUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API,  procedure 9A1.5",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API___procedure_9A1_5",
					Value = "cboWATSOL_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWATSOL_WATSOL",
							Value = "WSOLAPI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCWSLU2",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCWSLU2",
					Value = "cboWATSOL_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboWATSOL_WATSOL",
							Value = "WSOLUSR2"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboHCSOL_MultiMap_Property = CxvPropertyDeclaration.Register("cboHCSOL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboHCSOL_HCSOL",
					DataPath = "@main.Input.HCSOL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Aspen model",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_model_1",
					Value = "cboHCSOL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboHCSOL_HCSOL",
							Value = "HSOLASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCHSLU",
					DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCHSLU",
					Value = "cboHCSOL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboHCSOL_HCSOL",
							Value = "HSOLUSR"
						}
					}
				}
			}
		});

		public object cboCPIG_MultiMap => GetValue(cboCPIG_MultiMap_Property);

		public object cboDHVL_MultiMap => GetValue(cboDHVL_MultiMap_Property);

		public object cboDHFORM_MultiMap => GetValue(cboDHFORM_MultiMap_Property);

		public object cboDGFORM_MultiMap => GetValue(cboDGFORM_MultiMap_Property);

		public object cboWATSOL_MultiMap => GetValue(cboWATSOL_MultiMap_Property);

		public object cboHCSOL_MultiMap => GetValue(cboHCSOL_MultiMap_Property);
	}
	[ProgId("MMADASet.MMPCProp_Spec_Heat")]
	public class MMPCProp_Spec_Heat : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraThermo;

		internal MMLabel cboCPIG_label;

		internal MMComboEdit cboCPIG;

		internal MMLabel cboDHVL_label;

		internal MMComboEdit cboDHVL;

		internal MMLabel cboDHFORM_label;

		internal MMComboEdit cboDHFORM;

		internal MMLabel cboDGFORM_label;

		internal MMComboEdit cboDGFORM;

		internal MMLabel cboWATSOL_label;

		internal MMComboEdit cboWATSOL;

		internal MMLabel cboHCSOL_label;

		internal MMComboEdit cboHCSOL;

		private bool _contentLoaded;

		public MMPCProp_Spec_Heat()
		{
			base.ViewModelType = typeof(MMPCProp_Spec_Heat_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpcprop_spec_heat.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraThermo = (MMGroupBox)target;
				break;
			case 2:
				cboCPIG_label = (MMLabel)target;
				break;
			case 3:
				cboCPIG = (MMComboEdit)target;
				break;
			case 4:
				cboDHVL_label = (MMLabel)target;
				break;
			case 5:
				cboDHVL = (MMComboEdit)target;
				break;
			case 6:
				cboDHFORM_label = (MMLabel)target;
				break;
			case 7:
				cboDHFORM = (MMComboEdit)target;
				break;
			case 8:
				cboDGFORM_label = (MMLabel)target;
				break;
			case 9:
				cboDGFORM = (MMComboEdit)target;
				break;
			case 10:
				cboWATSOL_label = (MMLabel)target;
				break;
			case 11:
				cboWATSOL = (MMComboEdit)target;
				break;
			case 12:
				cboHCSOL_label = (MMLabel)target;
				break;
			case 13:
				cboHCSOL = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMPCProp_Spec_Spec_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboMUL_MultiMap_Property = CxvPropertyDeclaration.Register("cboMUL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboMUL_MUL",
					DataPath = "@main.Input.MUL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Watson",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Watson",
					Value = "cboMUL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMUL_MUL",
							Value = "MULWAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCMULU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMULU",
					Value = "cboMUL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMUL_MUL",
							Value = "MULUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCMULU2",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMULU2",
					Value = "cboMUL_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMUL_MUL",
							Value = "MULUSR2"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboVL_MultiMap_Property = CxvPropertyDeclaration.Register("cboVL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboVL_VL",
					DataPath = "@main.Input.VL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Rackett",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Rackett",
					Value = "cboVL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVL_VL",
							Value = "VLRKT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cavett",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett",
					Value = "cboVL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVL_VL",
							Value = "VLCAVT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCVOLU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCVOLU",
					Value = "cboVL_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVL_VL",
							Value = "VLUSR"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboPL_MultiMap_Property = CxvPropertyDeclaration.Register("cboPL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPL_PL",
					DataPath = "@main.Input.PL"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Maxwell-Bonnell",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell",
					Value = "cboPL_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLMB"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Tsang-SWAP",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_SWAP",
					Value = "cboPL_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLSWAP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee",
					Value = "cboPL_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCPLU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCPLU",
					Value = "cboPL_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "BK-10 model",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_BK_10_model",
					Value = "cboPL_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "BK-10"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee (For compatibility)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee__For_compatibility_",
					Value = "cboPL_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLKLMOD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Maxwell-Bonnell (For compatibility 1)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell__For_compatibility_1_",
					Value = "cboPL_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLPSMOD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Maxwell-Bonnell (For compatibility 2)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell__For_compatibility_2_",
					Value = "cboPL_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPL_PL",
							Value = "PLMBMOD"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboOMEGA_MultiMap_Property = CxvPropertyDeclaration.Register("cboOMEGA_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboOMEGA_OMEGA",
					DataPath = "@main.Input.OMEGA"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Defining relation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Defining_relation",
					Value = "cboOMEGA_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMEGADEF"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_1",
					Value = "cboOMEGA_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMEGAKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCOMGU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCOMGU",
					Value = "cboOMEGA_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMEGAUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Robinson-Peng",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng",
					Value = "cboOMEGA_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMEGAPR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Lee and Kesler, Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Lee_and_Kesler__Aspen",
					Value = "cboOMEGA_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "KL-ASPEN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Edmister",
					Value = "cboOMEGA_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMGEDMIS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Lee-Kesler",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Lee_Kesler",
					Value = "cboOMEGA_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMGEXTLK"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Twu generalized",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_generalized",
					Value = "cboOMEGA_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMGTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen extended Twu generalized",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_extended_Twu_generalized",
					Value = "cboOMEGA_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMGXTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS extended Twu generalized",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_extended_Twu_generalized",
					Value = "cboOMEGA_MultiMapOption_10",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMHYSTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation",
					Value = "cboOMEGA_MultiMapOption_11",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboOMEGA_OMEGA",
							Value = "OMGEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_BASE_Property = CxvPropertyDeclaration.Register("MMComboBox1_BASE", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.BASE"
		});

		public static readonly CxvPropertyDeclaration cboCT_MultiMap_Property = CxvPropertyDeclaration.Register("cboCT_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboCT_TC",
					DataPath = "@main.Input.TC"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Riazi (1980)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980__1",
					Value = "cboCT_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCRZI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Tsang-Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen_1",
					Value = "cboCT_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al__1",
					Value = "cboCT_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cavett",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett_2",
					Value = "cboCT_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCCAVT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_3",
					Value = "cboCT_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCTCU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCTCU",
					Value = "cboCT_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Riazi (1986)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986__1",
					Value = "cboCT_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCRZAPI5"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_2",
					Value = "cboCT_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Robinson-Peng",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng_2",
					Value = "cboCT_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCPR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "WINN correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation_1",
					Value = "cboCT_MultiMapOption_10",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCWINN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Twu 1",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu_1",
					Value = "cboCT_MultiMapOption_11",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCXTWU1"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Twu 2",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu_2",
					Value = "cboCT_MultiMapOption_12",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCXTWU2"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Cavett",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Cavett",
					Value = "cboCT_MultiMapOption_13",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCEXTCAV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu",
					Value = "cboCT_MultiMapOption_14",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCHYSTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_1",
					Value = "cboCT_MultiMapOption_15",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboCT_TC",
							Value = "TCEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboMW_MultiMap_Property = CxvPropertyDeclaration.Register("cboMW_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboMW_MW",
					DataPath = "@main.Input.MW"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Riazi (1980)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980__2",
					Value = "cboMW_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWRZI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Tsang-Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen_2",
					Value = "cboMW_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al__2",
					Value = "cboMW_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_4",
					Value = "cboMW_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Hariu and Sage",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Hariu_and_Sage",
					Value = "cboMW_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWHS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCMWU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMWU",
					Value = "cboMW_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Riazi (1986)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986__2",
					Value = "cboMW_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWRZAPI5"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Riazi (1986), heavy petro.",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986___heavy_petro_",
					Value = "cboMW_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWRZH"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Harui and Sage-Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Harui_and_Sage_Aspen",
					Value = "cboMW_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "HS-Aspen"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "WINN correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation_2",
					Value = "cboMW_MultiMapOption_10",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWWINN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
					Value = "cboMW_MultiMapOption_11",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWEXTTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended API (Riazi, 1980)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_API__Riazi__1980_",
					Value = "cboMW_MultiMapOption_12",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWEXTAPI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_1",
					Value = "cboMW_MultiMapOption_13",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWHYSTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_2",
					Value = "cboMW_MultiMapOption_14",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboMW_MW",
							Value = "MWEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboVC_MultiMap_Property = CxvPropertyDeclaration.Register("cboVC_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboVC_VC",
					DataPath = "@main.Input.VC"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Riedel",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riedel",
					Value = "cboVC_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCRDL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Brule et al.",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
					Value = "cboVC_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCSTAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCVCU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCVCU",
					Value = "cboVC_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu",
					Value = "cboVC_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Edmister",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Edmister_1",
					Value = "cboVC_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCEDMIS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Lee-Kesler",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Lee_Kesler",
					Value = "cboVC_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
					Value = "cboVC_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCEXTTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_2",
					Value = "cboVC_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCHYSTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_3",
					Value = "cboVC_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboVC_VC",
							Value = "VCEDL"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboPC_MultiMap_Property = CxvPropertyDeclaration.Register("cboPC_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPC_PC",
					DataPath = "@main.Input.PC"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Riazi (1980)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980_",
					Value = "cboPC_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCRZI"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Tsang-Aspen",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen",
					Value = "cboPC_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCASPN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Cavett",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett_1",
					Value = "cboPC_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCCAVT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kesler and Lee",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_2",
					Value = "cboPC_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCKL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "User routine PCPCU",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCPCU",
					Value = "cboPC_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCUSR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Riazi (1986)",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986_",
					Value = "cboPC_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCRZAPI5"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_1",
					Value = "cboPC_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Robinson-Peng",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng_1",
					Value = "cboPC_MultiMapOption_8",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCPR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "WINN correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation",
					Value = "cboPC_MultiMapOption_9",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCWINN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
					Value = "cboPC_MultiMapOption_10",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCEXTTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Extended Edmister",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Edmister",
					Value = "cboPC_MultiMapOption_11",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCEXTEDM"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Aspen HYSYS Extended Twu",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_3",
					Value = "cboPC_MultiMapOption_12",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCHYSTWU"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EDL-CHEF correlation",
					DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_4",
					Value = "cboPC_MultiMapOption_13",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboPC_PC",
							Value = "PCEDL"
						}
					}
				}
			}
		});

		public object cboMUL_MultiMap => GetValue(cboMUL_MultiMap_Property);

		public object cboVL_MultiMap => GetValue(cboVL_MultiMap_Property);

		public object cboPL_MultiMap => GetValue(cboPL_MultiMap_Property);

		public object cboOMEGA_MultiMap => GetValue(cboOMEGA_MultiMap_Property);

		public object MMComboBox1_BASE => GetValue(MMComboBox1_BASE_Property);

		public object cboCT_MultiMap => GetValue(cboCT_MultiMap_Property);

		public object cboMW_MultiMap => GetValue(cboMW_MultiMap_Property);

		public object cboVC_MultiMap => GetValue(cboVC_MultiMap_Property);

		public object cboPC_MultiMap => GetValue(cboPC_MultiMap_Property);
	}
	[ProgId("MMADASet.MMPCProp_Spec_Spec")]
	public class MMPCProp_Spec_Spec : MMTabPage, IComponentConnector
	{
		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox MMFrame1;

		internal MMLabel cboMW_label;

		internal MMComboEdit cboMW;

		internal MMLabel cboCT_label;

		internal MMComboEdit cboCT;

		internal MMLabel cboPC_label;

		internal MMComboEdit cboPC;

		internal MMLabel cboVC_label;

		internal MMComboEdit cboVC;

		internal MMLabel cboOMEGA_label;

		internal MMComboEdit cboOMEGA;

		internal MMLabel cboPL_label;

		internal MMComboEdit cboPL;

		internal MMLabel cboVL_label;

		internal MMComboEdit cboVL;

		internal MMLabel cboMUL_label;

		internal MMComboEdit cboMUL;

		private bool _contentLoaded;

		public MMPCProp_Spec_Spec()
		{
			base.ViewModelType = typeof(MMPCProp_Spec_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/petroleumcharacterization/mmpcprop_spec_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				MMFrame1 = (MMGroupBox)target;
				break;
			case 4:
				cboMW_label = (MMLabel)target;
				break;
			case 5:
				cboMW = (MMComboEdit)target;
				break;
			case 6:
				cboCT_label = (MMLabel)target;
				break;
			case 7:
				cboCT = (MMComboEdit)target;
				break;
			case 8:
				cboPC_label = (MMLabel)target;
				break;
			case 9:
				cboPC = (MMComboEdit)target;
				break;
			case 10:
				cboVC_label = (MMLabel)target;
				break;
			case 11:
				cboVC = (MMComboEdit)target;
				break;
			case 12:
				cboOMEGA_label = (MMLabel)target;
				break;
			case 13:
				cboOMEGA = (MMComboEdit)target;
				break;
			case 14:
				cboPL_label = (MMLabel)target;
				break;
			case 15:
				cboPL = (MMComboEdit)target;
				break;
			case 16:
				cboVL_label = (MMLabel)target;
				break;
			case 17:
				cboVL = (MMComboEdit)target;
				break;
			case 18:
				cboMUL_label = (MMLabel)target;
				break;
			case 19:
				cboMUL = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.MoistureComponents
{
	public class MoistComps_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MoistComps_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSELE"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MoistComps_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsele" }
		});

		public object entsele => GetValue(entsele_Property);

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
	[ProgId("MMMoistComps.MoistComps_Input")]
	public class MoistComps_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MoistComps_Input()
		{
			base.ViewModelType = typeof(MoistComps_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/moisturecomponents/moistcomps_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MoistComps_Input_Select_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MoistComps_Input_Select_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.COMP",
			AllowSort = false
		});

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);
	}
	[ProgId("MMMoistComps.MoistComps_Input_Select")]
	public class MoistComps_Input_Select : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MoistComps_Input_Select()
		{
			base.ViewModelType = typeof(MoistComps_Input_Select_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/moisturecomponents/moistcomps_input_select.xaml", UriKind.Relative);
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
namespace AspenTech.AspenPlus.MMForms.Components.HenryComponents
{
	public class MMHenryComps_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration hc_Property = CxvPropertyDeclaration.Register("hc", typeof(MMHenryComps_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHenryComps_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@hc" }
		});

		public object hc => GetValue(hc_Property);

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
	[ProgId("MMHenryComps.MMHenryComps_Input")]
	public class MMHenryComps_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabHenryComps;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMHenryComps_Input()
		{
			base.ViewModelType = typeof(MMHenryComps_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/henrycomponents/mmhenrycomps_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabHenryComps = (MMTabStrip)target;
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
	public class MMHenryComps_Input_HenryC_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMHenryComps_Input_HenryC_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.CID",
			AllowSort = false
		});

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);
	}
	[ProgId("MMHenryComps.MMHenryComps_Input_HenryC")]
	public class MMHenryComps_Input_HenryC : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMHenryComps_Input_HenryC()
		{
			base.ViewModelType = typeof(MMHenryComps_Input_HenryC_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/henrycomponents/mmhenrycomps_input_henryc.xaml", UriKind.Relative);
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
	public class MMHenryComps_Input_RewHen_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMHenryComps_Input_RewHen_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.CID",
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
	[ProgId("MMHenryComps.MMHenryComps_Input_RewHen")]
	public class MMHenryComps_Input_RewHen : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMHenryComps_Input_RewHen()
		{
			base.ViewModelType = typeof(MMHenryComps_Input_RewHen_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/henrycomponents/mmhenrycomps_input_rewhen.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
}
namespace AspenTech.AspenPlus.MMForms.Components.Comp_Lists
{
	public class MMComplst_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration OVERALL_Property = CxvPropertyDeclaration.Register("OVERALL", typeof(MMComplst_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.OVERALL"
		});

		public static readonly CxvPropertyDeclaration ENTCID_Property = CxvPropertyDeclaration.Register("ENTCID", typeof(MMComplst_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTCID"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMComplst_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@OVERALL" },
			EnteredDataPaths = { "@ENTCID" }
		});

		public object OVERALL => GetValue(OVERALL_Property);

		public object ENTCID => GetValue(ENTCID_Property);

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
	[ProgId("MMComplst.MMComplst_Input")]
	public class MMComplst_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMComplst_Input()
		{
			base.ViewModelType = typeof(MMComplst_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/comp-lists/mmcomplst_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMComplst_Input_Selection_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMLabel_state_Property = CxvPropertyDeclaration.Register("MMLabel_state", typeof(MMComplst_Input_Selection_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CMPLST"
			}
		});

		public static readonly CxvPropertyDeclaration MMGroupBox_state_Property = CxvPropertyDeclaration.Register("MMGroupBox_state", typeof(MMComplst_Input_Selection_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GCMPLST"
			}
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMComplst_Input_Selection_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.CID"
		});

		public object MMLabel_state => GetValue(MMLabel_state_Property);

		public object MMGroupBox_state => GetValue(MMGroupBox_state_Property);

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				int num = 0;
				if (CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "id")) == "GLOBAL")
				{
					num = 1;
				}
				string dataPath = "@main.Input.GCOMP_LIST";
				ExpandDataPathAndSet(dataPath, "value", num);
			}
		}
	}
	[ProgId("MMComplst.MMComplst_Input_Selection")]
	public class MMComplst_Input_Selection : MMTabPage, IComponentConnector
	{
		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMComplst_Input_Selection()
		{
			base.ViewModelType = typeof(MMComplst_Input_Selection_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/comp-lists/mmcomplst_input_selection.xaml", UriKind.Relative);
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
namespace AspenTech.AspenPlus.MMForms.Components.Comp_Groups
{
	public class MMCompgrp_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMCompgrp_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration sele_Property = CxvPropertyDeclaration.Register("sele", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entlist_Property = CxvPropertyDeclaration.Register("entlist", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTLIST.@choice"
		});

		public static readonly CxvPropertyDeclaration entrange_Property = CxvPropertyDeclaration.Register("entrange", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTRANGE.@choice"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompgrp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sele" },
			EnteredDataPaths = { "@entlist" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMCompgrp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@sele" },
			EnteredDataPaths = { "@entrange" }
		});

		public object choice => GetValue(choice_Property);

		public object sele => GetValue(sele_Property);

		public object entlist => GetValue(entlist_Property);

		public object entrange => GetValue(entrange_Property);

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
	[ProgId("MMCompgrp.MMCompgrp_Input")]
	public class MMCompgrp_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMCompgrp_Input()
		{
			base.ViewModelType = typeof(MMCompgrp_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/comp-groups/mmcompgrp_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMCompgrp_Input_Range_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.T2.@choice.@y"
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.T2.@choice.@y"
			});

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMCompgrp_Input_Range_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMCompgrp_Input_Range_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.L1",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMCompgrp_Input_Range_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
			CompletePaths = { "MAIN3" },
			EnteredPaths = { "ENTRANGE" }
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMCompgrp_Input_Range_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.COMPLI.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompgrp_Input_Range_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.T2.@choice",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMCompgrp.MMCompgrp_Input_Range")]
	public class MMCompgrp_Input_Range : MMTabPage, IComponentConnector
	{
		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMGroupBox MMFrame2;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMCompgrp_Input_Range()
		{
			base.ViewModelType = typeof(MMCompgrp_Input_Range_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/comp-groups/mmcompgrp_input_range.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 2:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMFrame2 = (MMGroupBox)target;
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
	public class MMCompgrp_Input_Selection_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.COMP.@choice",
			TrueValue = "NONE",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.L1",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMCompgrp_Input_Selection_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
			CompletePaths = { "MAIN4" },
			EnteredPaths = { "ENTLIST" }
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_state_Property = CxvPropertyDeclaration.Register("MMListPicker1_state", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.COMPLI.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.L1.@choice",
			AllowSort = false
		});

		public static readonly CxvPropertyDeclaration CheckBox_Enabled_Property = CxvPropertyDeclaration.Register("CheckBox_Enabled", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvLogicalProperty
		{
			Value = true,
			Operator = CxvLogicalOperator.And,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "choice",
					Operator = CxvLogicalOperator.IsNotNull
				},
				new CxvLogicalTest
				{
					Parameter = "choice",
					Operator = CxvLogicalOperator.NotEqual,
					Value = string.Empty
				},
				new CxvLogicalTest
				{
					Parameter = "choice",
					Operator = CxvLogicalOperator.NotEqual,
					Value = DBNull.Value
				}
			}
		});

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object MMListPicker1_state => GetValue(MMListPicker1_state_Property);

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		public object CheckBox_Enabled => GetValue(CheckBox_Enabled_Property);
	}
	[ProgId("MMCompgrp.MMCompgrp_Input_Selection")]
	public class MMCompgrp_Input_Selection : MMTabPage, IComponentConnector
	{
		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMCheckBox MMCheckBox1;

		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMCompgrp_Input_Selection()
		{
			base.ViewModelType = typeof(MMCompgrp_Input_Selection_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/comp-groups/mmcompgrp_input_selection.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 2:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 4:
				MMListPicker1 = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.Bio_Comps
{
	internal class BioFeedDB
	{
		private IDatabank _databank;

		private ICompoundManager _compoundManager;

		private IPropertyValueManager _propertyValueManager;

		private static readonly Dictionary<string, Compound> _bioCompounds = new Dictionary<string, Compound>();

		private static readonly Dictionary<string, Compound> _baseCompounds = new Dictionary<string, Compound>();

		private string DatabaseName = "APESV";

		private const string BioFeedDatabankName = "BIOFEED";

		public Dictionary<string, Compound> BioCompounds => _bioCompounds;

		public Dictionary<string, Compound> BaseCompounds => _baseCompounds;

		public BioFeedDB()
		{
			try
			{
				if (_bioCompounds.Count == 0)
				{
					SetupSearch(DatabaseName, "BIOFEED");
					SetupBaseAndBioComponents();
				}
			}
			catch (Exception)
			{
			}
		}

		private void SetupSearch(string databaseName, string databankName)
		{
			DatabaseCollection databaseCollection = new DatabaseCollection();
			string appPwd = "ATVIEWER";
			databaseCollection.InitializeFromConfigurationFile(null, appPwd);
			if (databaseCollection.Count == 0)
			{
				return;
			}
			IDatabase database = null;
			foreach (IDatabase item in databaseCollection)
			{
				if (item != null && item.Alias.StartsWith(DatabaseName))
				{
					database = item;
					break;
				}
			}
			if (database == null)
			{
				foreach (IDatabase item2 in databaseCollection)
				{
					item2.EnumerateDatabanks(out var Databanks);
					foreach (IDatabank item3 in Databanks)
					{
						if (item3.Name.Equals("BIOFEED", StringComparison.InvariantCultureIgnoreCase))
						{
							database = item2;
							DatabaseName = item2.Alias;
							_databank = item3;
							break;
						}
					}
					if (_databank != null)
					{
						break;
					}
				}
			}
			else
			{
				database.EnumerateDatabanks(out var Databanks2);
				foreach (IDatabank item4 in Databanks2)
				{
					if (item4.Name.Equals("BIOFEED", StringComparison.InvariantCultureIgnoreCase))
					{
						_databank = item4;
						break;
					}
				}
			}
			if (database != null)
			{
				_compoundManager = (database as ISupportsCompounds)?.CompoundManager;
				_propertyValueManager = (database as ISupportsPropertyValues)?.PropertyValueManager;
			}
		}

		private void SetupBaseAndBioComponents()
		{
			_compoundManager.GetAllCompounds(_databank, out var compounds);
			IPropertyValue propertyValue = null;
			foreach (FoundCompounds item in compounds)
			{
				string text = null;
				string alias = null;
				string cASRN = null;
				string text2 = null;
				ICollection identifierValues = item.IdentifierValues;
				if (identifierValues != null && identifierValues.Count > 0)
				{
					Array array = Array.CreateInstance(typeof(IIdentifierValue), identifierValues.Count);
					identifierValues.CopyTo(array, 0);
					foreach (IIdentifierValue item2 in array)
					{
						if (item2 != null)
						{
							string[] array2 = (string[])item2.ValueList;
							switch (item2.Identifier.Name)
							{
							case "NAME":
								text = array2[0];
								break;
							case "ALIAS":
								alias = array2[0];
								break;
							case "casrn":
								cASRN = array2[0];
								break;
							}
						}
					}
				}
				ICollection propertyValues = item.PropertyValues;
				if (propertyValues != null && propertyValues.Count > 0)
				{
					Array array3 = Array.CreateInstance(typeof(IPropertyValue), propertyValues.Count);
					propertyValues.CopyTo(array3, 0);
					foreach (IPropertyValue item3 in array3)
					{
						if (item3 != null && item3 != null && item3.Value != null && item3.Property.Name == "COMPCLASS" && ((string[])item3.Value).Length != 0)
						{
							text2 = ((string[])item3.Value)[0].ToUpper();
						}
					}
				}
				if (!string.IsNullOrEmpty(text2) && text2.Equals("BIOCOMPONENTS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !_bioCompounds.ContainsKey(text))
				{
					_propertyValueManager.GetUnaryPropertyValue(_databank, text, "NAME", "BIONO", out propertyValue);
					double[] array4 = (double[])propertyValue.Value;
					List<double> list = new List<double>();
					if (array4 != null)
					{
						foreach (double num in array4)
						{
							if (Convert.ToDouble(num) != 0.0 && num != 1E+35)
							{
								list.Add(num);
							}
						}
					}
					_bioCompounds.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						BioNos = list.ToArray()
					});
				}
				if (!string.IsNullOrEmpty(text2) && text2.Equals("SOLIDS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !_baseCompounds.ContainsKey(text))
				{
					_propertyValueManager.GetUnaryPropertyValue(_databank, text, "NAME", "BIOPOS", out propertyValue);
					string bioPos = ((double[])propertyValue.Value)[0].ToString();
					_baseCompounds.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						BioPos = bioPos
					});
				}
			}
			Dictionary<string, Compound> dictionary = _baseCompounds.ToDictionary((KeyValuePair<string, Compound> x) => x.Value.BioPos, (KeyValuePair<string, Compound> x) => x.Value);
			foreach (string key in _bioCompounds.Keys)
			{
				_propertyValueManager.GetUnaryPropertyValue(_databank, key, "NAME", "BIOID", out propertyValue);
				double[] array5 = propertyValue.Value as double[];
				List<string> list2 = new List<string>();
				if (array5 != null)
				{
					for (int num2 = 0; num2 < array5.Length; num2++)
					{
						double num3 = array5[num2];
						if (num3 != 1E+35)
						{
							string text3 = num3.ToString();
							if (Convert.ToInt32(text3) > 0)
							{
								string name = dictionary[text3].Name;
								list2.Add(name);
							}
						}
					}
				}
				_bioCompounds[key].BioIds = list2.ToArray();
			}
		}
	}
	public class Compound
	{
		public string CASRN { get; set; }

		public string Name { get; set; }

		public string Alias { get; set; }

		public string BioPos { get; set; }

		public string[] BioIds { get; set; }

		public double[] BioNos { get; set; }
	}
	public class MMBioComp_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MASSSUM_Property = CxvPropertyDeclaration.Register("MASSSUM", typeof(MMBioComp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MASSSUM"
		});

		public static readonly CxvPropertyDeclaration ENTBIO_Property = CxvPropertyDeclaration.Register("ENTBIO", typeof(MMBioComp_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBIO"
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBioComp_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@MASSSUM" },
			EnteredDataPaths = { "@ENTBIO" }
		});

		public object MASSSUM => GetValue(MASSSUM_Property);

		public object ENTBIO => GetValue(ENTBIO_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMBioComp.MMBioComp_Input")]
	public class MMBioComp_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab1;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMBioComp_Input()
		{
			base.ViewModelType = typeof(MMBioComp_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/bio-comps/mmbiocomp_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBioComp_Input_Biofeed_ViewModel : MMTabPageViewModel
	{
		public List<Compound> BioCompounds
		{
			get
			{
				List<Compound> list = new List<Compound>();
				string[] array = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.@parent.Specifications.Input.ANAME", "child_ids"));
				Dictionary<string, string> dictionary = new Dictionary<string, string>();
				if (array != null)
				{
					string[] array2 = array;
					foreach (string text in array2)
					{
						string value = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.@parent.Specifications.Input.DBNAME." + text, "value"));
						dictionary.Add(text, value);
					}
				}
				Dictionary<string, string> dictAliasNames = new Dictionary<string, string>();
				foreach (KeyValuePair<string, string> item in dictionary)
				{
					if (!dictAliasNames.ContainsKey(item.Value))
					{
						dictAliasNames.Add(item.Value, item.Key);
					}
				}
				string[] array3 = CxsConverter.ValueToStringArray(ExpandDataPathAndGet("@main.Input.PHASE", "child_ids"));
				if (array3 != null)
				{
					BioFeedDB bioFeedDB = new BioFeedDB();
					string[] array2 = array3;
					foreach (string text2 in array2)
					{
						if (!dictionary.ContainsKey(text2))
						{
							continue;
						}
						string text3 = dictionary[text2];
						if (!bioFeedDB.BioCompounds.ContainsKey(text3))
						{
							continue;
						}
						Compound compound = new Compound
						{
							Name = text3,
							Alias = text2,
							BioIds = bioFeedDB.BioCompounds[text3].BioIds,
							BioNos = bioFeedDB.BioCompounds[text3].BioNos
						};
						if (compound.BioIds != null)
						{
							compound.BioIds = compound.BioIds.Select((string x) => (!dictAliasNames.ContainsKey(x)) ? x : dictAliasNames[x]).ToArray();
						}
						list.Add(compound);
					}
				}
				return list;
			}
		}
	}
	public class MMBioComp_Input_Spec_ViewModel : MMTabPageViewModel
	{
		public class grdPhase_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCompID_var1_Property = CxvPropertyDeclaration.Register("txtCompID_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.PHASE.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration Phase_var1_Property = CxvPropertyDeclaration.Register("Phase_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "Phase_var1",
						DataPath = "@main.Input.PHASE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = FormsComponentsResources.Liquid,
						Prompt = PromptResources.FILEPNUM_953_Prompt_3,
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "Phase_var1",
								Value = "L"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = FormsComponentsResources.Solid,
						Prompt = PromptResources.FILEPNUM_953_Prompt_4,
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "Phase_var1",
								Value = "S"
							}
						}
					}
				}
			});

			public static CxvPropertyDeclaration chkEnabled_var1_Property = CxvPropertyDeclaration.Register("chkEnabled_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvBooleanProperty
			{
				DataPath = "@main.Input.TYPE_LIST.@y",
				TrueValue = "BIOSTATE",
				FalseValue = "NO",
				DefaultValue = false,
				ReadOnlyIfProxy = true
			});

			public static readonly CxvPropertyDeclaration MMComboBasis_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBasis_MultiMap", typeof(grdPhase_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBasis",
						DataPath = "@main.Input.INPUT_BASIS.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = FormsComponentsResources.NumberOfAtoms,
						Prompt = PromptResources.FILEPNUM_953_Prompt_11,
						Value = "MMComboBasis_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBasis",
								Value = "NOATOM"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = FormsComponentsResources.MassPercentage,
						Prompt = PromptResources.FILEPNUM_953_Prompt_12,
						Value = "MMComboBasis_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBasis",
								Value = "MASS"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = FormsComponentsResources.MolarPercentage,
						Prompt = PromptResources.FILEPNUM_953_Prompt_13,
						Value = "MMComboBasis_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBasis",
								Value = "MOLAR"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtCarbon_var1_Property = CxvPropertyDeclaration.Register("txtCarbon_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.NOATOM1.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.VALUES1.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.MOLEPERCENT1.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtHydrogen_var1_Property = CxvPropertyDeclaration.Register("txtHydrogen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.NOATOM2.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.VALUES2.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.MOLEPERCENT2.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtOxygen_var1_Property = CxvPropertyDeclaration.Register("txtOxygen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.NOATOM3.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.VALUES3.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.MOLEPERCENT3.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtNitrogen_var1_Property = CxvPropertyDeclaration.Register("txtNitrogen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.NOATOM4.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.VALUES4.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.MOLEPERCENT4.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtAsh_var1_Property = CxvPropertyDeclaration.Register("txtAsh_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.NOATOM5.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.VALUES5.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.MOLEPERCENT5.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "",
							IsReadOnly = true,
							IsEnabledCondition = new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "NOATOM",
								Operator = CxvLogicalOperator.NotEqual
							}
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MASS",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.SUM_MASS.@y",
							IsReadOnly = true
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.Input.INPUT_BASIS.@y",
								Value = "MOLAR",
								Operator = CxvLogicalOperator.Equal
							}
						},
						Operator = CxvLogicalOperator.And,
						Property = new CxvVariableProperty
						{
							DataPath = "@main.Input.SUM_MOLE.@y",
							IsReadOnly = true
						}
					}
				}
			});

			public object txtCompID_var1 => GetValue(txtCompID_var1_Property);

			public object Phase_var1 => GetValue(Phase_var1_Property);

			public object chkEnabled_var1 => GetValue(chkEnabled_var1_Property);

			public object MMComboBasis_MultiMap => GetValue(MMComboBasis_MultiMap_Property);

			public object txtCarbon_var1 => GetValue(txtCarbon_var1_Property);

			public object txtHydrogen_var1 => GetValue(txtHydrogen_var1_Property);

			public object txtOxygen_var1 => GetValue(txtOxygen_var1_Property);

			public object txtNitrogen_var1 => GetValue(txtNitrogen_var1_Property);

			public object txtAsh_var1 => GetValue(txtAsh_var1_Property);

			public object txtTotal_var1 => GetValue(txtTotal_var1_Property);
		}

		public class grdMolar_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCompIDMolar_var1_Property = CxvPropertyDeclaration.Register("txtCompIDMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.PHASE.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtCarbonMolar_var1_Property = CxvPropertyDeclaration.Register("txtCarbonMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NOATOMCBASE1.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtHydrogenMolar_var1_Property = CxvPropertyDeclaration.Register("txtHydrogenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NOATOMCBASE2.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtOxygenMolar_var1_Property = CxvPropertyDeclaration.Register("txtOxygenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NOATOMCBASE3.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtNitrogenMolar_var1_Property = CxvPropertyDeclaration.Register("txtNitrogenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NOATOMCBASE4.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtAshMolar_var1_Property = CxvPropertyDeclaration.Register("txtAshMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.NOATOMCBASE5.@y",
				IsReadOnly = true
			});

			public object txtCompIDMolar_var1 => GetValue(txtCompIDMolar_var1_Property);

			public object txtCarbonMolar_var1 => GetValue(txtCarbonMolar_var1_Property);

			public object txtHydrogenMolar_var1 => GetValue(txtHydrogenMolar_var1_Property);

			public object txtOxygenMolar_var1 => GetValue(txtOxygenMolar_var1_Property);

			public object txtNitrogenMolar_var1 => GetValue(txtNitrogenMolar_var1_Property);

			public object txtAshMolar_var1 => GetValue(txtAshMolar_var1_Property);
		}

		public class grdMass_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCompIDMass_var1_Property = CxvPropertyDeclaration.Register("txtCompIDMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.PHASE.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtCarbonMass_var1_Property = CxvPropertyDeclaration.Register("txtCarbonMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VALUES1.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtHydrogenMass_var1_Property = CxvPropertyDeclaration.Register("txtHydrogenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VALUES2.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtOxygenMass_var1_Property = CxvPropertyDeclaration.Register("txtOxygenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VALUES3.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtNitrogenMass_var1_Property = CxvPropertyDeclaration.Register("txtNitrogenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VALUES4.@y",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration txtAshMass_var1_Property = CxvPropertyDeclaration.Register("txtAshMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VALUES5.@y",
				IsReadOnly = true
			});

			public object txtCompIDMass_var1 => GetValue(txtCompIDMass_var1_Property);

			public object txtCarbonMass_var1 => GetValue(txtCarbonMass_var1_Property);

			public object txtHydrogenMass_var1 => GetValue(txtHydrogenMass_var1_Property);

			public object txtOxygenMass_var1 => GetValue(txtOxygenMass_var1_Property);

			public object txtNitrogenMass_var1 => GetValue(txtNitrogenMass_var1_Property);

			public object txtAshMass_var1 => GetValue(txtAshMass_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdPhase_GridData_Property = CxvPropertyDeclaration.Register("grdPhase_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPhase_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PHASE",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration grdMolar_GridData_Property = CxvPropertyDeclaration.Register("grdMolar_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdMolar_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PHASE",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration grdMass_GridData_Property = CxvPropertyDeclaration.Register("grdMass_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdMass_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PHASE",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdPhase_GridData => GetValue(grdPhase_GridData_Property);

		public object grdMolar_GridData => GetValue(grdMolar_GridData_Property);

		public object grdMass_GridData => GetValue(grdMass_GridData_Property);
	}
	[ProgId("MMBioComp.MMBioComp_Input_Spec")]
	public class MMBioComp_Input_Spec : MMTabPage, IComponentConnector
	{
		internal MMLabel Component;

		internal MMScrollAreaMS gridPhase;

		internal MMLabel Molar;

		internal MMScrollAreaMS gridMolar;

		internal MMLabel Mass;

		internal MMScrollAreaMS gridMass;

		private bool _contentLoaded;

		public MMBioComp_Input_Spec()
		{
			base.ViewModelType = typeof(MMBioComp_Input_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/bio-comps/mmbiocomp_input_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				Component = (MMLabel)target;
				break;
			case 2:
				gridPhase = (MMScrollAreaMS)target;
				break;
			case 3:
				Molar = (MMLabel)target;
				break;
			case 4:
				gridMolar = (MMScrollAreaMS)target;
				break;
			case 5:
				Mass = (MMLabel)target;
				break;
			case 6:
				gridMass = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBioComp_Input_Biofeed : MMTabPage, IComponentConnector
	{
		private readonly IUnityContainer _unityContainer;

		private ICxsDataWatch _watch;

		internal StackPanel stackPanel;

		private bool _contentLoaded;

		public MMBioComp_Input_Biofeed(IUnityContainer unityContainer)
		{
			base.ViewModelType = typeof(MMBioComp_Input_Biofeed_ViewModel);
			InitializeComponent();
			base.Loaded += MMBioComp_Input_Biofeed_Loaded;
			_unityContainer = unityContainer;
		}

		private void MMBioComp_Input_Biofeed_Loaded(object sender, RoutedEventArgs e)
		{
			if (base.ViewModel is MMBioComp_Input_Biofeed_ViewModel mMBioComp_Input_Biofeed_ViewModel && _watch == null)
			{
				Refresh();
				CxsDataProvider cxsDataProvider = _unityContainer.Resolve<CxsDataProvider>(Array.Empty<ResolverOverride>());
				_watch = cxsDataProvider.CreateWatch();
				string path = mMBioComp_Input_Biofeed_ViewModel.ExpandDataPath("@main.Input.PHASE");
				_watch.AddWatch(path, "child_ids");
				_watch.ValuesChanged += watch_ValuesChanged;
			}
		}

		private void watch_ValuesChanged(object sender, EventArgs e)
		{
			try
			{
				Refresh();
			}
			catch (Exception)
			{
			}
		}

		private void Refresh()
		{
			if (!(base.ViewModel is MMBioComp_Input_Biofeed_ViewModel mMBioComp_Input_Biofeed_ViewModel))
			{
				return;
			}
			stackPanel.Children.Clear();
			foreach (Compound bioCompound in mMBioComp_Input_Biofeed_ViewModel.BioCompounds)
			{
				GridControl gridControl = new GridControl
				{
					SortingMode = SortingMode.NotAllowed,
					AllowRowReorder = false,
					AllowColumnChooser = false,
					AllowRecordFiltering = false,
					AllowColumnReorder = false,
					HorizontalAlignment = HorizontalAlignment.Left,
					Margin = new Thickness(0.0, 0.0, 0.0, 20.0)
				};
				gridControl.DefaultContextMenuOpening += GridControl_DefaultContextMenuOpening;
				List<DataColumn> list = new List<DataColumn>();
				list.Add(new DataColumn
				{
					Header = FormsComponentsResources.ComponentID,
					Width = 100.0
				});
				string[] bioIds = bioCompound.BioIds;
				foreach (string header in bioIds)
				{
					list.Add(new DataColumn
					{
						Header = header,
						Width = 100.0,
						Tooltip = FormsComponentsResources.ComponentIDForBiobaseComponent
					});
				}
				DataTable parentDataTable = (gridControl.DataSource = new DataTable(list));
				List<DataRow> list2 = new List<DataRow>();
				DataRow dataRow = new DataRow(parentDataTable);
				dataRow[0] = DataRow.CreateDataCell(bioCompound.Alias, isReadOnly: true);
				dataRow[0].Tooltip = FormsComponentsResources.ComponentIDForBiofeedstockComponent;
				for (int j = 1; j <= bioCompound.BioNos.Length; j++)
				{
					dataRow[j] = DataRow.CreateDataCell(bioCompound.BioNos[j - 1], isReadOnly: true);
				}
				list2.Add(dataRow);
				gridControl.DataSource.UpdateRows(list2);
				stackPanel.Children.Add(gridControl);
			}
		}

		private void GridControl_DefaultContextMenuOpening(object sender, DefaultContextMenuEventArgs e)
		{
			e.DefaultContextMenu.Items.Add(new MenuItem
			{
				Icon = new Image
				{
					Source = ImageSourceHelper.Copy16
				},
				Command = ApplicationCommands.Copy,
				CommandTarget = e.GridControl
			});
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/bio-comps/mmbiocomp_input_biofeed.xaml", UriKind.Relative);
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
				stackPanel = (StackPanel)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.Attr_Scaling
{
	public class MMAttrScal_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration compid_Property = CxvPropertyDeclaration.Register("compid", typeof(MMAttrScal_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "compid"
		});

		public static readonly CxvPropertyDeclaration CCMAIN_Property = CxvPropertyDeclaration.Register("CCMAIN", typeof(MMAttrScal_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration ENTSC_Property = CxvPropertyDeclaration.Register("ENTSC", typeof(MMAttrScal_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAttrScal_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@CCMAIN" },
			EnteredDataPaths = { "@ENTSC" }
		});

		public object compid => GetValue(compid_Property);

		public object CCMAIN => GetValue(CCMAIN_Property);

		public object ENTSC => GetValue(ENTSC_Property);

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
	[ProgId("MMAttrScal.MMAttrScal_Input")]
	public class MMAttrScal_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMAttrScal_Input()
		{
			base.ViewModelType = typeof(MMAttrScal_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/attr-scaling/mmattrscal_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMAttrScal_Input_Create_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.SCALE.@compid.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.UPPER.@compid.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.SCALE.@compid.@y"
			});

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea_GridData", typeof(MMAttrScal_Input_Create_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.SCALE.@compid",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo2_var2_Property = CxvPropertyDeclaration.Register("MMAdvCombo2_var2", typeof(MMAttrScal_Input_Create_ViewModel), new CxvParameterProperty
		{
			Parameter = "compid"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo2_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo2_var1", typeof(MMAttrScal_Input_Create_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.SCALE",
			SelectedItemBinding = "MMAdvCombo2_var2.Value",
			CreateNewPrompt = "Component ID",
			CreateNewPromptResourceKey = "MMAttrScal_Input_Create_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID"
		});

		public object MMScrollArea_GridData => GetValue(MMScrollArea_GridData_Property);

		public object MMAdvCombo2_var2 => GetValue(MMAdvCombo2_var2_Property);

		public object MMAdvCombo2_var1 => GetValue(MMAdvCombo2_var1_Property);
	}
	[ProgId("MMAttrScal.MMAttrScal_Input_Create")]
	public class MMAttrScal_Input_Create : MMTabPage, IComponentConnector
	{
		internal MMLabel MMAdvCombo2_label;

		internal MMAdvancedComboEdit MMAdvCombo2;

		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea;

		private bool _contentLoaded;

		public MMAttrScal_Input_Create()
		{
			base.ViewModelType = typeof(MMAttrScal_Input_Create_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/attr-scaling/mmattrscal_input_create.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMAdvCombo2_label = (MMLabel)target;
				break;
			case 2:
				MMAdvCombo2 = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 4:
				MMScrollArea = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Components.Attr_Comps
{
	public class MMCompAttr_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration global_Property = CxvPropertyDeclaration.Register("global", typeof(MMCompAttr_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration entspec_Property = CxvPropertyDeclaration.Register("entspec", typeof(MMCompAttr_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTSPEC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompAttr_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@global" },
			EnteredDataPaths = { "@entspec" }
		});

		public object global => GetValue(global_Property);

		public object entspec => GetValue(entspec_Property);

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
	[ProgId("MMCompAttr.MMCompAttr_Input")]
	public class MMCompAttr_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMCompAttr_Input()
		{
			base.ViewModelType = typeof(MMCompAttr_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/attr-comps/mmcompattr_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMCompAttr_Input_Create_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.TYPE_LIST.@y"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CompAttrChildCountIndexBasis
				{
					DataPath = "@main.Input.TYPE_LIST.@y",
					UseChildId = true,
					Name = "uid"
				},
				AllowCollectionChange = false
			});

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.TYPE_LIST.@y.@uid"
			});

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompAttr_Input_Create_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.TYPE_LIST",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	public class CompAttrChildCountIndexBasis : CxvChildCountIndexBasis
	{
		public override CxvIndexBasisBaseData CreateData(ICxvViewDataContainer dataContainer, CxvPropertyWatch dependencies)
		{
			return new CompAttrChildCountIndexBasisData(this, dataContainer);
		}
	}
	public class CompAttrChildCountIndexBasisData : CxvChildCountIndexBasisData
	{
		private bool? _isSecondProxy;

		public override int Count
		{
			get
			{
				if (!_isSecondProxy.HasValue)
				{
					string text = base.DataContainer.ExpandDataPath(base.IndexBasis.DataPath);
					if (text != null)
					{
						if (CxsConverter.ValueToBoolean(base.DataContainer.ResolvedCxsProvider.BatchGet(text, "is_proxy", null)) ?? false)
						{
							_isSecondProxy = true;
							SetChildIds(null, null);
							return 0;
						}
						_isSecondProxy = false;
					}
				}
				if (_isSecondProxy ?? false)
				{
					return 0;
				}
				return base.Count;
			}
		}

		public CompAttrChildCountIndexBasisData(CxvChildCountIndexBasis indexBasis, ICxvViewDataContainer dataContainer)
			: base(indexBasis, dataContainer)
		{
		}
	}
	[ProgId("MMCompAttr.MMCompAttr_Input_Create")]
	public class MMCompAttr_Input_Create : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMCompAttr_Input_Create()
		{
			base.ViewModelType = typeof(MMCompAttr_Input_Create_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/attr-comps/mmcompattr_input_create.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
namespace AspenTech.AspenPlus.MMForms.Components.AssayBlend
{
	public class MMAssay_BasicD_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration ASSAYMAIN_Property = CxvPropertyDeclaration.Register("ASSAYMAIN", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration FRAC1_Property = CxvPropertyDeclaration.Register("FRAC1", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FRAC1"
		});

		public static readonly CxvPropertyDeclaration MW_Property = CxvPropertyDeclaration.Register("MW", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MW"
		});

		public static readonly CxvPropertyDeclaration OPTIONAL_Property = CxvPropertyDeclaration.Register("OPTIONAL", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.OPTIONAL"
		});

		public static readonly CxvPropertyDeclaration MWOPT_Property = CxvPropertyDeclaration.Register("MWOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MWOPT"
		});

		public static readonly CxvPropertyDeclaration GUOPT_Property = CxvPropertyDeclaration.Register("GUOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GUOPT"
		});

		public static readonly CxvPropertyDeclaration LEOPT_Property = CxvPropertyDeclaration.Register("LEOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.LEOPT"
		});

		public static readonly CxvPropertyDeclaration GRAVUOPK_Property = CxvPropertyDeclaration.Register("GRAVUOPK", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GRAV_UOPK"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@ASSAYMAIN" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@FRAC1" },
			EnteredDataPaths = { "@LEOPT" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@GRAVUOPK" },
			EnteredDataPaths = { "@GUOPT" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@MW" },
			EnteredDataPaths = { "@MWOPT" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@OPTIONAL" }
		});

		public object ASSAYMAIN => GetValue(ASSAYMAIN_Property);

		public object FRAC1 => GetValue(FRAC1_Property);

		public object MW => GetValue(MW_Property);

		public object OPTIONAL => GetValue(OPTIONAL_Property);

		public object MWOPT => GetValue(MWOPT_Property);

		public object GUOPT => GetValue(GUOPT_Property);

		public object LEOPT => GetValue(LEOPT_Property);

		public object GRAVUOPK => GetValue(GRAVUOPK_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD")]
	public class MMAssay_BasicD : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabMMAssay_BasicData;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMAssay_BasicD()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabMMAssay_BasicData = (MMTabStrip)target;
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
	public class MMAssay_BasicD_Distl_ViewModel : MMTabPageViewModel
	{
		public class grdDistCurve_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration _txtPCTDIST_PCT_DIST_Property = CxvPropertyDeclaration.Register("_txtPCTDIST_PCT_DIST", typeof(grdDistCurve_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.TEMP.@y"
			});

			public static readonly CxvPropertyDeclaration txtTEMP_var1_Property = CxvPropertyDeclaration.Register("txtTEMP_var1", typeof(grdDistCurve_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.TEMP.@y"
			});

			public object _txtPCTDIST_PCT_DIST => GetValue(_txtPCTDIST_PCT_DIST_Property);

			public object txtTEMP_var1 => GetValue(txtTEMP_var1_Property);
		}

		public static readonly CxvPropertyDeclaration cboDCurve_MultiMap_Property = CxvPropertyDeclaration.Register("cboDCurve_MultiMap", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDCurve_DISTTYPE",
					DataPath = "@main.Input.DISTTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "ASTM D86",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D86",
					Value = "cboDCurve_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "D86"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "ASTM D1160",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D1160",
					Value = "cboDCurve_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "D1160"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "True boiling point (liquid volume basis)",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_True_boiling_point__liquid_volume_basis_",
					Value = "cboDCurve_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "TBPLV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "True boiling point (weight basis)",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_True_boiling_point__weight_basis_",
					Value = "cboDCurve_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "TBPWT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vacuum (liquid volume basis)",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Vacuum__liquid_volume_basis_",
					Value = "cboDCurve_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "VACLV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vacuum (weight basis)",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Vacuum__weight_basis_",
					Value = "cboDCurve_MultiMapOption_6",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "VACWT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "ASTM D2887",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D2887",
					Value = "cboDCurve_MultiMapOption_7",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDCurve_DISTTYPE",
							Value = "D2887"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP"
		});

		public static readonly CxvPropertyDeclaration grdDistCurve_GridData_Property = CxvPropertyDeclaration.Register("grdDistCurve_GridData", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdDistCurve_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.TEMP",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration grdBulkGrav_MultiMap_Property = CxvPropertyDeclaration.Register("grdBulkGrav_MultiMap", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "grdBulkGrav_GRAVTYPE",
					DataPath = "@main.Input.OPT_GRAVTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Specific gravity",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
					Value = "grdBulkGrav_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "grdBulkGrav_GRAVTYPE",
							Value = "GRAV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API gravity",
					DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_API_gravity",
					Value = "grdBulkGrav_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "grdBulkGrav_GRAVTYPE",
							Value = "API"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration txtAPI_API_Property = CxvPropertyDeclaration.Register("txtAPI_API", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.API",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GTYPEB"
			}
		});

		public static readonly CxvPropertyDeclaration txtGravVal_GRAV_Property = CxvPropertyDeclaration.Register("txtGravVal_GRAV", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GRAV",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GTYPEA"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VACPRES",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VPRESENABLE"
			}
		});

		public object cboDCurve_MultiMap => GetValue(cboDCurve_MultiMap_Property);

		public object lbtuTemp_var1 => GetValue(lbtuTemp_var1_Property);

		public object grdDistCurve_GridData => GetValue(grdDistCurve_GridData_Property);

		public object grdBulkGrav_MultiMap => GetValue(grdBulkGrav_MultiMap_Property);

		public object txtAPI_API => GetValue(txtAPI_API_Property);

		public object txtGravVal_GRAV => GetValue(txtGravVal_GRAV_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD_Distl")]
	public class MMAssay_BasicD_Distl : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDCurve;

		internal MMLabel MMLabel1;

		internal MMComboEdit cboDCurve;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMOptionGroup grdBulkGrav;

		internal MMOptionButton grdBulkGrav_opt0;

		internal MMValueEdit txtGravVal;

		internal MMOptionButton grdBulkGrav_opt1;

		internal MMValueEdit txtAPI;

		internal MMScrollAreaMS grdDistCurve;

		private bool _contentLoaded;

		public MMAssay_BasicD_Distl()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_Distl_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd_distl.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraDCurve = (MMGroupBox)target;
				break;
			case 2:
				MMLabel1 = (MMLabel)target;
				break;
			case 3:
				cboDCurve = (MMComboEdit)target;
				break;
			case 4:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 5:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 6:
				grdBulkGrav = (MMOptionGroup)target;
				break;
			case 7:
				grdBulkGrav_opt0 = (MMOptionButton)target;
				break;
			case 8:
				txtGravVal = (MMValueEdit)target;
				break;
			case 9:
				grdBulkGrav_opt1 = (MMOptionButton)target;
				break;
			case 10:
				txtAPI = (MMValueEdit)target;
				break;
			case 11:
				grdDistCurve = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_BasicD_Grav_ViewModel : MMTabPageViewModel
	{
		public class grdAPI_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtAPI_APICURVE_Property = CxvPropertyDeclaration.Register("txtAPI_APICURVE", typeof(grdAPI_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.MID_API.@y"
			});

			public static readonly CxvPropertyDeclaration txtAPIPctDist_PctDist_Property = CxvPropertyDeclaration.Register("txtAPIPctDist_PctDist", typeof(grdAPI_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.MID_API.@y"
			});

			public object txtAPI_APICURVE => GetValue(txtAPI_APICURVE_Property);

			public object txtAPIPctDist_PctDist => GetValue(txtAPIPctDist_PctDist_Property);
		}

		public class grdSG_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtSGvalue_var1_Property = CxvPropertyDeclaration.Register("txtSGvalue_var1", typeof(grdSG_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.MID_GRAV.@y"
			});

			public static readonly CxvPropertyDeclaration txtSGMidDist_var1_Property = CxvPropertyDeclaration.Register("txtSGMidDist_var1", typeof(grdSG_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.MID_GRAV.@y"
			});

			public object txtSGvalue_var1 => GetValue(txtSGvalue_var1_Property);

			public object txtSGMidDist_var1 => GetValue(txtSGMidDist_var1_Property);
		}

		public class grdUOPK_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtUOPK_UOPK_Property = CxvPropertyDeclaration.Register("txtUOPK_UOPK", typeof(grdUOPK_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.MID_UOPK.@y"
			});

			public static readonly CxvPropertyDeclaration txtUOPKPctDist_MidPct_Property = CxvPropertyDeclaration.Register("txtUOPKPctDist_MidPct", typeof(grdUOPK_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.MID_UOPK.@y"
			});

			public object txtUOPK_UOPK => GetValue(txtUOPK_UOPK_Property);

			public object txtUOPKPctDist_MidPct => GetValue(txtUOPKPctDist_MidPct_Property);
		}

		public static readonly CxvPropertyDeclaration ogrType_MultiMap_Property = CxvPropertyDeclaration.Register("ogrType_MultiMap", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrType_curvetype",
					DataPath = "@main.Input.GRAVTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Specific gravity",
					DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
					Value = "ogrType_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrType_curvetype",
							Value = "GRAV"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "API gravity",
					DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_API_gravity",
					Value = "ogrType_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrType_curvetype",
							Value = "API"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "UOPK",
					DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_UOPK",
					Value = "ogrType_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrType_curvetype",
							Value = "UOPK"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration fraAPIGrav_state_Property = CxvPropertyDeclaration.Register("fraAPIGrav_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GRAVTYPEB"
			}
		});

		public static readonly CxvPropertyDeclaration grdAPI_GridData_Property = CxvPropertyDeclaration.Register("grdAPI_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAPI_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.MID_API",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration fraSpecGrav_state_Property = CxvPropertyDeclaration.Register("fraSpecGrav_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GRAVTYPEA"
			}
		});

		public static readonly CxvPropertyDeclaration grdSG_GridData_Property = CxvPropertyDeclaration.Register("grdSG_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSG_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.MID_GRAV",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration fraUOPK_state_Property = CxvPropertyDeclaration.Register("fraUOPK_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.UOPKENABLE"
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.GRAVTYPEC"
			}
		});

		public static readonly CxvPropertyDeclaration grdUOPK_GridData_Property = CxvPropertyDeclaration.Register("grdUOPK_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdUOPK_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.MID_UOPK",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuAPIBulk_API_Property = CxvPropertyDeclaration.Register("lbtuAPIBulk_API", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.API",
			IsReadOnly = true
		});

		public static readonly CxvPropertyDeclaration lbtuGSBulk_var1_Property = CxvPropertyDeclaration.Register("lbtuGSBulk_var1", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.GRAV",
			IsReadOnly = true
		});

		public object ogrType_MultiMap => GetValue(ogrType_MultiMap_Property);

		public object fraAPIGrav_state => GetValue(fraAPIGrav_state_Property);

		public object grdAPI_GridData => GetValue(grdAPI_GridData_Property);

		public object fraSpecGrav_state => GetValue(fraSpecGrav_state_Property);

		public object grdSG_GridData => GetValue(grdSG_GridData_Property);

		public object fraUOPK_state => GetValue(fraUOPK_state_Property);

		public object grdUOPK_GridData => GetValue(grdUOPK_GridData_Property);

		public object lbtuAPIBulk_API => GetValue(lbtuAPIBulk_API_Property);

		public object lbtuGSBulk_var1 => GetValue(lbtuGSBulk_var1_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD_Grav")]
	public class MMAssay_BasicD_Grav : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrType;

		internal MMOptionButton ogrType_opt0;

		internal MMOptionButton ogrType_opt1;

		internal MMOptionButton ogrType_opt2;

		internal MMGroupBox fraAPIGrav;

		internal MMLabel lbtuAPIBulk_label;

		internal MMVariableEdit lbtuAPIBulk;

		internal MMScrollArea grdAPI;

		internal MMGroupBox fraSpecGrav;

		internal MMLabel lbtuGSBulk_label;

		internal MMVariableEdit lbtuGSBulk;

		internal MMScrollArea grdSG;

		internal MMGroupBox fraUOPK;

		internal MMLabel lbtuUOPKBulk_label;

		internal MMVariableEdit lbtuUOPKBulk;

		internal MMScrollArea grdUOPK;

		private bool _contentLoaded;

		public MMAssay_BasicD_Grav()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_Grav_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd_grav.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				ogrType = (MMOptionGroup)target;
				break;
			case 2:
				ogrType_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogrType_opt1 = (MMOptionButton)target;
				break;
			case 4:
				ogrType_opt2 = (MMOptionButton)target;
				break;
			case 5:
				fraAPIGrav = (MMGroupBox)target;
				break;
			case 6:
				lbtuAPIBulk_label = (MMLabel)target;
				break;
			case 7:
				lbtuAPIBulk = (MMVariableEdit)target;
				break;
			case 8:
				grdAPI = (MMScrollArea)target;
				break;
			case 9:
				fraSpecGrav = (MMGroupBox)target;
				break;
			case 10:
				lbtuGSBulk_label = (MMLabel)target;
				break;
			case 11:
				lbtuGSBulk = (MMVariableEdit)target;
				break;
			case 12:
				grdSG = (MMScrollArea)target;
				break;
			case 13:
				fraUOPK = (MMGroupBox)target;
				break;
			case 14:
				lbtuUOPKBulk_label = (MMLabel)target;
				break;
			case 15:
				lbtuUOPKBulk = (MMVariableEdit)target;
				break;
			case 16:
				grdUOPK = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_BasicD_LEnds_ViewModel : MMTabPageViewModel
	{
		public class grdLEnds_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration cboCompID_cid_Property = CxvPropertyDeclaration.Register("cboCompID_cid", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.FRAC.@y"
			});

			public static readonly CxvPropertyDeclaration txtMW_LEBMW_Property = CxvPropertyDeclaration.Register("txtMW_LEBMW", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LEBMW.@y"
			});

			public static readonly CxvPropertyDeclaration txtGRAV_LEBGRAV_Property = CxvPropertyDeclaration.Register("txtGRAV_LEBGRAV", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.LEBGRAV.@y"
			});

			public static readonly CxvPropertyDeclaration txtFRAC_FRAC_Property = CxvPropertyDeclaration.Register("txtFRAC_FRAC", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FRAC.@y"
			});

			public object cboCompID_cid => GetValue(cboCompID_cid_Property);

			public object txtMW_LEBMW => GetValue(txtMW_LEBMW_Property);

			public object txtGRAV_LEBGRAV => GetValue(txtGRAV_LEBGRAV_Property);

			public object txtFRAC_FRAC => GetValue(txtFRAC_FRAC_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FRAC"
		});

		public static readonly CxvPropertyDeclaration grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLEnds_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuLEFRAC_LE_FRAC_Property = CxvPropertyDeclaration.Register("lbtuLEFRAC_LE_FRAC", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LE_FRAC"
		});

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object grdLEnds_GridData => GetValue(grdLEnds_GridData_Property);

		public object lbtuLEFRAC_LE_FRAC => GetValue(lbtuLEFRAC_LE_FRAC_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD_LEnds")]
	public class MMAssay_BasicD_LEnds : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuLEFRAC_label;

		internal MMVariableEdit lbtuLEFRAC;

		internal MMGroupBox fraLEndsAnal;

		internal MMScrollArea grdLEnds;

		private bool _contentLoaded;

		public MMAssay_BasicD_LEnds()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_LEnds_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd_lends.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuLEFRAC_label = (MMLabel)target;
				break;
			case 2:
				lbtuLEFRAC = (MMVariableEdit)target;
				break;
			case 3:
				fraLEndsAnal = (MMGroupBox)target;
				break;
			case 4:
				grdLEnds = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_BasicD_MW_ViewModel : MMTabPageViewModel
	{
		public class grdMWMW_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtMW_MW_MW_Property = CxvPropertyDeclaration.Register("txtMW_MW_MW", typeof(grdMWMW_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.MW_MW.@y"
			});

			public static readonly CxvPropertyDeclaration txtPCTDIST_PctDist_Property = CxvPropertyDeclaration.Register("txtPCTDIST_PctDist", typeof(grdMWMW_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.MW_MW.@y"
			});

			public object txtMW_MW_MW => GetValue(txtMW_MW_MW_Property);

			public object txtPCTDIST_PctDist => GetValue(txtPCTDIST_PctDist_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMAssay_BasicD_MW_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MW"
		});

		public static readonly CxvPropertyDeclaration grdMWMW_GridData_Property = CxvPropertyDeclaration.Register("grdMWMW_GridData", typeof(MMAssay_BasicD_MW_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdMWMW_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.MW_MW",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object grdMWMW_GridData => GetValue(grdMWMW_GridData_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD_MW")]
	public class MMAssay_BasicD_MW : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraMWData;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMScrollArea grdMWMW;

		private bool _contentLoaded;

		public MMAssay_BasicD_MW()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_MW_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd_mw.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraMWData = (MMGroupBox)target;
				break;
			case 2:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 3:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 4:
				grdMWMW = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_BasicD_Option_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.MATCH_LTENDS",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox3_CRACK_OPT_Property = CxvPropertyDeclaration.Register("MMCheckBox3_CRACK_OPT", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.CRACK_OPT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.DTYPED86"
			},
			DisabledPrompt = Resources.MMAssay_BasicD_Option_ViewModel__MMCheckBox3_CRACK_OPT_Property_DisabledPrompt
		});

		public static readonly CxvPropertyDeclaration chkASTM_D86_OPT_D86_Property = CxvPropertyDeclaration.Register("chkASTM_D86_OPT_D86", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_D86",
			TrueValue = "D86",
			FalseValue = "NOD86",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CHKOND86"
			}
		});

		public static readonly CxvPropertyDeclaration chkASTM_D1160_OPT_D1160_Property = CxvPropertyDeclaration.Register("chkASTM_D1160_OPT_D1160", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_D1160",
			TrueValue = "D1160",
			FalseValue = "NOD1160",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CHKOND1160"
			}
		});

		public static readonly CxvPropertyDeclaration _chkVacuum_opt_vaclv_Property = CxvPropertyDeclaration.Register("_chkVacuum_opt_vaclv", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_VACLV",
			TrueValue = "VACLV",
			FalseValue = "NOVACLV",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.CHKONVACLV"
			}
		});

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object MMCheckBox3_CRACK_OPT => GetValue(MMCheckBox3_CRACK_OPT_Property);

		public object chkASTM_D86_OPT_D86 => GetValue(chkASTM_D86_OPT_D86_Property);

		public object chkASTM_D1160_OPT_D1160 => GetValue(chkASTM_D1160_OPT_D1160_Property);

		public object _chkVacuum_opt_vaclv => GetValue(_chkVacuum_opt_vaclv_Property);
	}
	[ProgId("MMAssay.MMAssay_BasicD_Option")]
	public class MMAssay_BasicD_Option : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraOpt_Data;

		internal MMCheckBox MMCheckBox3;

		internal MMCheckBox MMCheckBox4;

		internal MMGroupBox fraRep_as;

		internal MMCheckBox chkASTM_D86;

		internal MMCheckBox chkASTM_D1160;

		internal MMCheckBox chkVacuum;

		private bool _contentLoaded;

		public MMAssay_BasicD_Option()
		{
			base.ViewModelType = typeof(MMAssay_BasicD_Option_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_basicd_option.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraOpt_Data = (MMGroupBox)target;
				break;
			case 2:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 3:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			case 4:
				fraRep_as = (MMGroupBox)target;
				break;
			case 5:
				chkASTM_D86 = (MMCheckBox)target;
				break;
			case 6:
				chkASTM_D1160 = (MMCheckBox)target;
				break;
			case 7:
				chkVacuum = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_List2D_ViewModel : MMTabPageViewModel
	{
		public class grdChild_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.@y"
			});

			public static readonly CxvPropertyDeclaration txtType_VarCol1_Property = CxvPropertyDeclaration.Register("txtType_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "type",
				IsReadOnly = true
			});

			public static readonly CxvPropertyDeclaration cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.@y",
				DataAttribute = "status",
				IsReadOnly = true
			});

			public object txtName_var1 => GetValue(txtName_var1_Property);

			public object txtType_VarCol1
			{
				get
				{
					CxvVariableData cxvVariableData = GetValue(txtType_VarCol1_Property) as CxvVariableData;
					if (cxvVariableData != null && cxvVariableData.Value != null && !string.IsNullOrEmpty(cxvVariableData.Value.ToString()))
					{
						string localizedCol = GetLocalizedCol1("rectype_Assay_Blend_" + cxvVariableData.Value.ToString(), cxvVariableData.Value.ToString());
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
		private sealed class SelectedIdsEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string currentId;

			private int initialThreadId;

			public MMAssay_List2D_ViewModel owner;

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
					MMAssay_List2D_ViewModel mMAssay_List2D_ViewModel = owner;
					switch (num)
					{
					default:
						completedNormally = true; return false;
					case 0:
						state = -1;
						gridData = mMAssay_List2D_ViewModel.grdChild_GridData as IList;
						rowIndexes = mMAssay_List2D_ViewModel.SelectedRowIndexes.GetEnumerator();
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

		private ICommand _cmdImport_Command;

		private ICommand _cmdAdd_Command;

		public static CxvPropertyDeclaration cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main",
			Operator = CxvLogicalOperator.CanInvokeAction,
			Value = "InsertChild"
		});

		private ICommand _cmdEdit_Command;

		public static CxvPropertyDeclaration cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
		{
			PropertyPath = "AllSelectedRecordsCount",
			Operator = CxvLogicalOperator.Equal,
			Value = 1
		});

		private ICommand _cmdDelete_Command;

		public static CxvPropertyDeclaration cmdDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDeleteCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
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

		private ICommand _cmdRename_Command;

		public static CxvPropertyDeclaration cmdRenameCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRenameCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
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

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _SelectedRowIndexes;

		public static readonly CxvPropertyDeclaration grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMAssay_List2D_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdChild_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main",
				UseChildId = true,
				Name = "y",
				ProxyRow = false
			},
			AllowCollectionChange = false
		});

		public ICommand cmdImport_Command
		{
			get
			{
				if (_cmdImport_Command == null)
				{
					_cmdImport_Command = new CxvDelegateCommand<object>(cmdImport_CommandExecute);
				}
				return _cmdImport_Command;
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
					_cmdDelete_Command = new CxvDelegateCommand<object>(cmdDelete_CommandExecute, this, cmdDeleteCanExecuteProperty.Name + ".Value");
				}
				return _cmdDelete_Command;
			}
		}

		public CxvLogicalPropertyData cmdDeleteCanExecute => GetValue(cmdDeleteCanExecuteProperty) as CxvLogicalPropertyData;

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

		private void cmdRename_CommandExecute(object parameter)
		{
			if (AllSelectedRecordsCount != 1)
			{
				return;
			}
			string parentPath = CxsConverter.ValueToString(ResolveParameter("main", null));
			List<string> list = new List<string>();
			foreach (string selectedId in GetSelectedIds())
			{
				list.Add(selectedId);
			}
			string text = "";
			foreach (string item in list)
			{
				text = item;
				ShowRenameChildDialog(parentPath, ref text);
			}
		}

		private void cmdImport_CommandExecute(object parameter)
		{
			ImportAssay();
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
			_ = base.IsInitialUpdate;
		}
	}
	[ProgId("MMAssay.MMAssay_List2D")]
	public class MMAssay_List2D : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdChild;

		internal MMCmdButton cmdAdd;

		internal MMCmdButton cmdEdit;

		internal MMCmdButton cmdDelete;

		internal MMCmdButton cmdRename;

		internal MMCmdButton cmdImport;

		private bool _contentLoaded;

		public MMAssay_List2D()
		{
			base.ViewModelType = typeof(MMAssay_List2D_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_list2d.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				cmdRename = (MMCmdButton)target;
				break;
			case 6:
				cmdImport = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_Proper_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration VISC_Property = CxvPropertyDeclaration.Register("VISC", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.VISC"
		});

		public static readonly CxvPropertyDeclaration PropIDX_Property = CxvPropertyDeclaration.Register("PropIDX", typeof(MMAssay_Proper_ViewModel), new CxvParameterProperty
		{
			Parameter = "PropIDX"
		});

		public static readonly CxvPropertyDeclaration PRCV_Property = CxvPropertyDeclaration.Register("PRCV", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.PRCV"
		});

		public static readonly CxvPropertyDeclaration PRCVOPT_Property = CxvPropertyDeclaration.Register("PRCVOPT", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.PRCVOPT"
		});

		public static readonly CxvPropertyDeclaration VISCOPT_Property = CxvPropertyDeclaration.Register("VISCOPT", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.VISCOPT"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_Proper_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@PRCV" },
			EnteredDataPaths = { "@PRCVOPT" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_Proper_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@VISC" },
			EnteredDataPaths = { "@VISCOPT" }
		});

		public object VISC => GetValue(VISC_Property);

		public object PropIDX => GetValue(PropIDX_Property);

		public object PRCV => GetValue(PRCV_Property);

		public object PRCVOPT => GetValue(PRCVOPT_Property);

		public object VISCOPT => GetValue(VISCOPT_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMAssay.MMAssay_Proper")]
	public class MMAssay_Proper : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabMMAssay_Proper;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		private bool _contentLoaded;

		public MMAssay_Proper()
		{
			base.ViewModelType = typeof(MMAssay_Proper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_proper.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabMMAssay_Proper = (MMTabStrip)target;
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
	public class MMAssay_Proper_Petro_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_PROP_VALUE_Property = CxvPropertyDeclaration.Register("MMTextBox2_PROP_VALUE", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PROP_VALUE.@PropIDX.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_PMID_PCT_Property = CxvPropertyDeclaration.Register("MMTextBox1_PMID_PCT", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PMID_PCT.@PropIDX.@y"
			});

			public object MMTextBox2_PROP_VALUE => GetValue(MMTextBox2_PROP_VALUE_Property);

			public object MMTextBox1_PMID_PCT => GetValue(MMTextBox1_PMID_PCT_Property);
		}

		public static readonly CxvPropertyDeclaration mnuPropType_target_Property = CxvPropertyDeclaration.Register("mnuPropType_target", typeof(MMAssay_Proper_Petro_ViewModel), new CxvParameterProperty
		{
			Parameter = "PropIDX"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
		{
			DataPath = "var1"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_PropType_Property = CxvPropertyDeclaration.Register("mnuPropType_PropType", typeof(MMAssay_Proper_Petro_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.BULKVAL",
			SelectedItemBinding = "mnuPropType_target.Value",
			CreateNewPrompt = "Property type:",
			CreateNewPromptResourceKey = "MMAssay_Proper_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
			CompletePaths = { "PCCOMP", "PCCOMP2", "PRCVOPT" },
			EnteredPaths = { "UENTPRCV" }
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAssay_Proper_Petro_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "PropIDX",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PMID_PCT.@PropIDX",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_BULKVAL_Property = CxvPropertyDeclaration.Register("MMLBUText1_BULKVAL", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.BULKVAL.@PropIDX"
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_PROPUNITS_Property = CxvPropertyDeclaration.Register("MMLBUText3_PROPUNITS", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PROP_UNITS.@PropIDX",
			IsReadOnly = true
		});

		public object mnuPropType_target => GetValue(mnuPropType_target_Property);

		public object mnuPropType_var1 => GetValue(mnuPropType_var1_Property);

		public object mnuPropType_PropType => GetValue(mnuPropType_PropType_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);

		public object MMLBUText1_BULKVAL => GetValue(MMLBUText1_BULKVAL_Property);

		public object MMLBUText3_PROPUNITS => GetValue(MMLBUText3_PROPUNITS_Property);
	}
	[ProgId("MMAssay.MMAssay_Proper_Petro")]
	public class MMAssay_Proper_Petro : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuPropType_label;

		internal MMAdvancedComboEdit mnuPropType;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMAssay_Proper_Petro()
		{
			base.ViewModelType = typeof(MMAssay_Proper_Petro_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_proper_petro.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mnuPropType_label = (MMLabel)target;
				break;
			case 2:
				mnuPropType = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 4:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 5:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 6:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 7:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 8:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_Proper_Visc_ViewModel : MMTabPageViewModel
	{
		public class grdAVisc_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtAVisc_VISCOSITY_Property = CxvPropertyDeclaration.Register("txtAVisc_VISCOSITY", typeof(grdAVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.VISCOSITY.@tempid.@y"
			});

			public static readonly CxvPropertyDeclaration txtMidPctAvisc_MidPct_Property = CxvPropertyDeclaration.Register("txtMidPctAvisc_MidPct", typeof(grdAVisc_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.VISCOSITY.@tempid.@y"
			});

			public object txtAVisc_VISCOSITY => GetValue(txtAVisc_VISCOSITY_Property);

			public object txtMidPctAvisc_MidPct => GetValue(txtMidPctAvisc_MidPct_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_MidPct_Property = CxvPropertyDeclaration.Register("MMTextBox2_MidPct", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.RealId,
				DataPath = "@main.Input.KVISCOSITY.@ktempid.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_KVISCOSITY_Property = CxvPropertyDeclaration.Register("MMTextBox1_KVISCOSITY", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.KVISCOSITY.@ktempid.@y"
			});

			public object MMTextBox2_MidPct => GetValue(MMTextBox2_MidPct_Property);

			public object MMTextBox1_KVISCOSITY => GetValue(MMTextBox1_KVISCOSITY_Property);
		}

		public static readonly CxvPropertyDeclaration ogrType_MultiMap_Property = CxvPropertyDeclaration.Register("ogrType_MultiMap", typeof(MMAssay_Proper_Visc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ogrType_opt_visc",
					DataPath = "@main.Input.OPT_VISC"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Absolute viscosity",
					DisplayResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvMultiMapOption_Display_Absolute_viscosity",
					Value = "ogrType_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrType_opt_visc",
							Value = "VISC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Kinematic viscosity",
					DisplayResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvMultiMapOption_Display_Kinematic_viscosity",
					Value = "ogrType_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ogrType_opt_visc",
							Value = "KVISC"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration fraAVisc_state_Property = CxvPropertyDeclaration.Register("fraAVisc_state", typeof(MMAssay_Proper_Visc_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VEN"
			}
		});

		public static readonly CxvPropertyDeclaration fraAVisc_tempid_Property = CxvPropertyDeclaration.Register("fraAVisc_tempid", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
		{
			Parameter = "tempid"
		});

		public static readonly CxvPropertyDeclaration mnuAVISCtemp_target_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_target", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
		{
			Parameter = "tempid"
		});

		public static readonly CxvPropertyDeclaration mnuAVISCtemp_AVCOMP_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_AVCOMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.AVCOMP"
		});

		public static readonly CxvPropertyDeclaration lbtuViscTemp_ViscUnits_Property = CxvPropertyDeclaration.Register("lbtuViscTemp_ViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VISCOSITY.@tempid"
		});

		public static readonly CxvPropertyDeclaration grdAVisc_GridData_Property = CxvPropertyDeclaration.Register("grdAVisc_GridData", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAVisc_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.VISCOSITY.@tempid",
				UseChildId = true,
				Name = "y"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.TEMPEXISTS"
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAssay_Proper_Visc_ViewModel), new CxvGroupBoxProperty
		{
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.KVEN"
			}
		});

		public static readonly CxvPropertyDeclaration MMFrame1_tempid_Property = CxvPropertyDeclaration.Register("MMFrame1_tempid", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
		{
			Parameter = "tempid"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_KViscUnits_Property = CxvPropertyDeclaration.Register("MMLBUText2_KViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.KVISCOSITY.@tempid"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_AVCOMP_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_AVCOMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.KVCOMP"
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_KVISCTEMP_Property = CxvPropertyDeclaration.Register("MMLBUText1_KVISCTEMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.KVISCTEMP"
		});

		public static readonly CxvPropertyDeclaration lbtuATemp_VISCTEMP_Property = CxvPropertyDeclaration.Register("lbtuATemp_VISCTEMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VISCTEMP"
		});

		public static readonly CxvPropertyDeclaration ViscUnits_Property = CxvPropertyDeclaration.Register("ViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VISCOSITY"
		});

		public static readonly CxvPropertyDeclaration KViscUnits_Property = CxvPropertyDeclaration.Register("KViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.KVISCOSITY"
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
		{
			Parameter = "ktempid"
		});

		public static readonly CxvPropertyDeclaration mnuAVISCtemp_viscosity_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_viscosity", typeof(MMAssay_Proper_Visc_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.VISCTEMP",
			SelectedItemBinding = "mnuAVISCtemp_target.Value",
			CreateNewPrompt = "Temperature:",
			CreateNewPromptResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Temperature_",
			CreateNewInputMask = 1,
			CompletePaths = { "AVCOMP", "NVISC" },
			DisplayValues = true
		});

		public static readonly CxvPropertyDeclaration MMAdvCombo1_viscosity_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_viscosity", typeof(MMAssay_Proper_Visc_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.KVISCTEMP",
			SelectedItemBinding = "MMAdvCombo1_target.Value",
			CreateNewInputMask = 1,
			CreateNewPrompt = "Temperature:",
			CreateNewPromptResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Temperature__1",
			CompletePaths = { "KVCOMP", "NKVISC" },
			DisplayValues = true
		});

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.KVISCOSITY.@ktempid",
				UseChildId = true,
				Name = "y"
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.KTEMPEXISTS"
			}
		});

		public object ogrType_MultiMap => GetValue(ogrType_MultiMap_Property);

		public object fraAVisc_state => GetValue(fraAVisc_state_Property);

		public object fraAVisc_tempid => GetValue(fraAVisc_tempid_Property);

		public object mnuAVISCtemp_target => GetValue(mnuAVISCtemp_target_Property);

		public object mnuAVISCtemp_AVCOMP => GetValue(mnuAVISCtemp_AVCOMP_Property);

		public object lbtuViscTemp_ViscUnits => GetValue(lbtuViscTemp_ViscUnits_Property);

		public object grdAVisc_GridData => GetValue(grdAVisc_GridData_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMFrame1_tempid => GetValue(MMFrame1_tempid_Property);

		public object MMLBUText2_KViscUnits => GetValue(MMLBUText2_KViscUnits_Property);

		public object MMAdvCombo1_AVCOMP => GetValue(MMAdvCombo1_AVCOMP_Property);

		public object MMLBUText1_KVISCTEMP => GetValue(MMLBUText1_KVISCTEMP_Property);

		public object lbtuATemp_VISCTEMP => GetValue(lbtuATemp_VISCTEMP_Property);

		public object ViscUnits => GetValue(ViscUnits_Property);

		public object KViscUnits => GetValue(KViscUnits_Property);

		public object MMAdvCombo1_target => GetValue(MMAdvCombo1_target_Property);

		public object mnuAVISCtemp_viscosity => GetValue(mnuAVISCtemp_viscosity_Property);

		public object MMAdvCombo1_viscosity => GetValue(MMAdvCombo1_viscosity_Property);

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMAssay.MMAssay_Proper_Visc")]
	public class MMAssay_Proper_Visc : MMTabPage, IComponentConnector
	{
		internal MMOptionGroup ogrType;

		internal MMOptionButton ogrType_opt0;

		internal MMOptionButton ogrType_opt1;

		internal MMGroupBox fraAVisc;

		internal MMLabel mnuAVISCtemp_label;

		internal MMAdvancedComboEdit mnuAVISCtemp;

		internal MMVariableEdit lbtuATemp;

		internal MMScrollArea grdAVisc;

		internal MMGroupBox MMFrame1;

		internal MMLabel MMAdvCombo1_label;

		internal MMAdvancedComboEdit MMAdvCombo1;

		internal MMVariableEdit MMLBUText1;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMAssay_Proper_Visc()
		{
			base.ViewModelType = typeof(MMAssay_Proper_Visc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_proper_visc.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				ogrType = (MMOptionGroup)target;
				break;
			case 2:
				ogrType_opt0 = (MMOptionButton)target;
				break;
			case 3:
				ogrType_opt1 = (MMOptionButton)target;
				break;
			case 4:
				fraAVisc = (MMGroupBox)target;
				break;
			case 5:
				mnuAVISCtemp_label = (MMLabel)target;
				break;
			case 6:
				mnuAVISCtemp = (MMAdvancedComboEdit)target;
				break;
			case 7:
				lbtuATemp = (MMVariableEdit)target;
				break;
			case 8:
				grdAVisc = (MMScrollArea)target;
				break;
			case 9:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 10:
				MMAdvCombo1_label = (MMLabel)target;
				break;
			case 11:
				MMAdvCombo1 = (MMAdvancedComboEdit)target;
				break;
			case 12:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 13:
				MMScrollArea1 = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration ACCPSEUDO_Property = CxvPropertyDeclaration.Register("ACCPSEUDO", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.COMPID"
		});

		public static readonly CxvPropertyDeclaration ACCCURVE_Property = CxvPropertyDeclaration.Register("ACCCURVE", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.DIST_RATIO"
		});

		public static readonly CxvPropertyDeclaration ACCLENDS_Property = CxvPropertyDeclaration.Register("ACCLENDS", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TLVCONC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCLENDS" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCPSEUDO" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCCURVE" }
		});

		public object ACCPSEUDO => GetValue(ACCPSEUDO_Property);

		public object ACCCURVE => GetValue(ACCCURVE_Property);

		public object ACCLENDS => GetValue(ACCLENDS_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMAssay.MMAssay_Result")]
	public class MMAssay_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResults;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMAssay_Result()
		{
			base.ViewModelType = typeof(MMAssay_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabResults = (MMTabStrip)target;
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
	public class MMAssay_Result_Curve_ViewModel : MMTabPageViewModel
	{
		public class grdResults_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCol_5_var1_Property = CxvPropertyDeclaration.Register("txtCol_5_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col5.@y"
			});

			public static readonly CxvPropertyDeclaration txtCol_4_var1_Property = CxvPropertyDeclaration.Register("txtCol_4_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col4.@y"
			});

			public static readonly CxvPropertyDeclaration txtCol_3_var1_Property = CxvPropertyDeclaration.Register("txtCol_3_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col3.@y"
			});

			public static readonly CxvPropertyDeclaration txtCol_2_var1_Property = CxvPropertyDeclaration.Register("txtCol_2_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col2.@y"
			});

			public static readonly CxvPropertyDeclaration txtCol_1_var1_Property = CxvPropertyDeclaration.Register("txtCol_1_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col1.@y"
			});

			public static readonly CxvPropertyDeclaration txtCol_0_var1_Property = CxvPropertyDeclaration.Register("txtCol_0_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.@col0.@y"
			});

			public static readonly CxvPropertyDeclaration txtDistilled_DIST_RATIO_Property = CxvPropertyDeclaration.Register("txtDistilled_DIST_RATIO", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.DIST_RATIO.@y"
			});

			public object txtCol_5_var1 => GetValue(txtCol_5_var1_Property);

			public object txtCol_4_var1 => GetValue(txtCol_4_var1_Property);

			public object txtCol_3_var1 => GetValue(txtCol_3_var1_Property);

			public object txtCol_2_var1 => GetValue(txtCol_2_var1_Property);

			public object txtCol_1_var1 => GetValue(txtCol_1_var1_Property);

			public object txtCol_0_var1 => GetValue(txtCol_0_var1_Property);

			public object txtDistilled_DIST_RATIO => GetValue(txtDistilled_DIST_RATIO_Property);
		}

		public static readonly CxvPropertyDeclaration fraCurve_col1_Property = CxvPropertyDeclaration.Register("fraCurve_col1", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col1"
		});

		public static readonly CxvPropertyDeclaration fraCurve_col2_Property = CxvPropertyDeclaration.Register("fraCurve_col2", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col2"
		});

		public static readonly CxvPropertyDeclaration fraCurve_col3_Property = CxvPropertyDeclaration.Register("fraCurve_col3", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col3"
		});

		public static readonly CxvPropertyDeclaration fraCurve_col0_Property = CxvPropertyDeclaration.Register("fraCurve_col0", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col0"
		});

		public static readonly CxvPropertyDeclaration fraCurve_col4_Property = CxvPropertyDeclaration.Register("fraCurve_col4", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col4"
		});

		public static readonly CxvPropertyDeclaration fraCurve_col5_Property = CxvPropertyDeclaration.Register("fraCurve_col5", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "col5"
		});

		public static readonly CxvPropertyDeclaration lbtuDensity_DENSITY_Property = CxvPropertyDeclaration.Register("lbtuDensity_DENSITY", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.DENSITY"
		});

		public static readonly CxvPropertyDeclaration lbtuMW_MW_Property = CxvPropertyDeclaration.Register("lbtuMW_MW", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MW"
		});

		public static readonly CxvPropertyDeclaration grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMAssay_Result_Curve_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdResults_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.DIST_RATIO",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuAPI_API_Property = CxvPropertyDeclaration.Register("lbtuAPI_API", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.API"
		});

		public static readonly CxvPropertyDeclaration lbtuSG_SG_Property = CxvPropertyDeclaration.Register("lbtuSG_SG", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.SG"
		});

		public static readonly CxvPropertyDeclaration FirstCol_Label_Property = CxvPropertyDeclaration.Register("FirstCol_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "FirstColLabel"
		});

		public static readonly CxvPropertyDeclaration Col0_PRES_Property = CxvPropertyDeclaration.Register("Col0_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TBP_PRES"
		});

		public static readonly CxvPropertyDeclaration Col0_Units_Property = CxvPropertyDeclaration.Register("Col0_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col0"
		});

		public static readonly CxvPropertyDeclaration Col0_Label_Property = CxvPropertyDeclaration.Register("Col0_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col0Label"
		});

		public static readonly CxvPropertyDeclaration Col0_Used_Property = CxvPropertyDeclaration.Register("Col0_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col0Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration Col1_PRES_Property = CxvPropertyDeclaration.Register("Col1_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.D86_PRES"
		});

		public static readonly CxvPropertyDeclaration Col1_Units_Property = CxvPropertyDeclaration.Register("Col1_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col1"
		});

		public static readonly CxvPropertyDeclaration Col1_Label_Property = CxvPropertyDeclaration.Register("Col1_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col1Label"
		});

		public static readonly CxvPropertyDeclaration Col1_Used_Property = CxvPropertyDeclaration.Register("Col1_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col1Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration Col2_PRES_Property = CxvPropertyDeclaration.Register("Col2_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.D1160_PRES"
		});

		public static readonly CxvPropertyDeclaration Col2_Units_Property = CxvPropertyDeclaration.Register("Col2_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col2"
		});

		public static readonly CxvPropertyDeclaration Col2_Label_Property = CxvPropertyDeclaration.Register("Col2_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col2Label"
		});

		public static readonly CxvPropertyDeclaration Col2_Used_Property = CxvPropertyDeclaration.Register("Col2_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col2Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration Col3_PRES_Property = CxvPropertyDeclaration.Register("Col3_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.VAC_PRES"
		});

		public static readonly CxvPropertyDeclaration Col3_Units_Property = CxvPropertyDeclaration.Register("Col3_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col3"
		});

		public static readonly CxvPropertyDeclaration Col3_Label_Property = CxvPropertyDeclaration.Register("Col3_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col3Label"
		});

		public static readonly CxvPropertyDeclaration Col3_Used_Property = CxvPropertyDeclaration.Register("Col3_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col3Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration Col4_PRES_Property = CxvPropertyDeclaration.Register("Col4_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.D86E_PRES"
		});

		public static readonly CxvPropertyDeclaration Col4_Units_Property = CxvPropertyDeclaration.Register("Col4_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col4"
		});

		public static readonly CxvPropertyDeclaration Col4_Label_Property = CxvPropertyDeclaration.Register("Col4_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col4Label"
		});

		public static readonly CxvPropertyDeclaration Col4_Used_Property = CxvPropertyDeclaration.Register("Col4_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col4Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration Col5_PRES_Property = CxvPropertyDeclaration.Register("Col5_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.D2887_PRES"
		});

		public static readonly CxvPropertyDeclaration Col5_Units_Property = CxvPropertyDeclaration.Register("Col5_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.@col5"
		});

		public static readonly CxvPropertyDeclaration Col5_Label_Property = CxvPropertyDeclaration.Register("Col5_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col5Label"
		});

		public static readonly CxvPropertyDeclaration Col5_Used_Property = CxvPropertyDeclaration.Register("Col5_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
		{
			Parameter = "Col5Used",
			Value = false
		});

		public static readonly CxvPropertyDeclaration lblPresUnit_VAR_UNIT_Property = CxvPropertyDeclaration.Register("lblPresUnit_VAR_UNIT", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.VAR_UNIT"
		});

		public object fraCurve_col1 => GetValue(fraCurve_col1_Property);

		public object fraCurve_col2 => GetValue(fraCurve_col2_Property);

		public object fraCurve_col3 => GetValue(fraCurve_col3_Property);

		public object fraCurve_col0 => GetValue(fraCurve_col0_Property);

		public object fraCurve_col4 => GetValue(fraCurve_col4_Property);

		public object fraCurve_col5 => GetValue(fraCurve_col5_Property);

		public object lbtuDensity_DENSITY => GetValue(lbtuDensity_DENSITY_Property);

		public object lbtuMW_MW => GetValue(lbtuMW_MW_Property);

		public object grdResults_GridData => GetValue(grdResults_GridData_Property);

		public object lbtuAPI_API => GetValue(lbtuAPI_API_Property);

		public object lbtuSG_SG => GetValue(lbtuSG_SG_Property);

		public object FirstCol_Label => GetValue(FirstCol_Label_Property);

		public object Col0_PRES => GetValue(Col0_PRES_Property);

		public object Col0_Units => GetValue(Col0_Units_Property);

		public object Col0_Label => GetValue(Col0_Label_Property);

		public object Col0_Used => GetValue(Col0_Used_Property);

		public object Col1_PRES => GetValue(Col1_PRES_Property);

		public object Col1_Units => GetValue(Col1_Units_Property);

		public object Col1_Label => GetValue(Col1_Label_Property);

		public object Col1_Used => GetValue(Col1_Used_Property);

		public object Col2_PRES => GetValue(Col2_PRES_Property);

		public object Col2_Units => GetValue(Col2_Units_Property);

		public object Col2_Label => GetValue(Col2_Label_Property);

		public object Col2_Used => GetValue(Col2_Used_Property);

		public object Col3_PRES => GetValue(Col3_PRES_Property);

		public object Col3_Units => GetValue(Col3_Units_Property);

		public object Col3_Label => GetValue(Col3_Label_Property);

		public object Col3_Used => GetValue(Col3_Used_Property);

		public object Col4_PRES => GetValue(Col4_PRES_Property);

		public object Col4_Units => GetValue(Col4_Units_Property);

		public object Col4_Label => GetValue(Col4_Label_Property);

		public object Col4_Used => GetValue(Col4_Used_Property);

		public object Col5_PRES => GetValue(Col5_PRES_Property);

		public object Col5_Units => GetValue(Col5_Units_Property);

		public object Col5_Label => GetValue(Col5_Label_Property);

		public object Col5_Used => GetValue(Col5_Used_Property);

		public object lblPresUnit_VAR_UNIT => GetValue(lblPresUnit_VAR_UNIT_Property);

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			int counter = 0;
			SetField("TBPLV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_TBPLV);
			SetField("TBPWT", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_TBPWT);
			SetField("D86LV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_D86LV);
			SetField("D1160LV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_D1160LV);
			SetField("VACLV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_VACLV);
			SetField("VACWT", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_VACWT);
			SetField("D86ELV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_D86ELV);
			SetField("D2887LV", ref counter, Resources.MMAssay_Result_Curve_ViewModel__FieldLable_D2887LV);
			ResolveUpdateParameter("FirstColLabel", string.Format(Resources.MMAssay_Result_Curve_ViewModel__FirstColLabel, this.ResolveViewPropertyPath("lblPresUnit_VAR_UNIT.Value").ToString()));
		}

		private void SetField(string var, ref int counter, string label)
		{
			if (CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Output." + var, "child_count")).Value > 0)
			{
				ResolveUpdateParameter("col" + counter, var);
				ResolveUpdateParameter("Col" + counter + "Label", label);
				ResolveUpdateParameter("Col" + counter + "Used", true);
				counter++;
			}
		}
	}
	[ProgId("MMAssay.MMAssay_Result_Curve")]
	public class MMAssay_Result_Curve : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuSG_label;

		internal MMVariableEdit lbtuSG;

		internal MMLabel lbtuDensity_label;

		internal MMVariableEdit lbtuDensity;

		internal MMLabel lbtuAPI_label;

		internal MMVariableEdit lbtuAPI;

		internal MMLabel lbtuMW_label;

		internal MMVariableEdit lbtuMW;

		internal MMScrollAreaMS grdResults;

		private bool _contentLoaded;

		public MMAssay_Result_Curve()
		{
			base.ViewModelType = typeof(MMAssay_Result_Curve_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_result_curve.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuSG_label = (MMLabel)target;
				break;
			case 2:
				lbtuSG = (MMVariableEdit)target;
				break;
			case 3:
				lbtuDensity_label = (MMLabel)target;
				break;
			case 4:
				lbtuDensity = (MMVariableEdit)target;
				break;
			case 5:
				lbtuAPI_label = (MMLabel)target;
				break;
			case 6:
				lbtuAPI = (MMVariableEdit)target;
				break;
			case 7:
				lbtuMW_label = (MMLabel)target;
				break;
			case 8:
				lbtuMW = (MMVariableEdit)target;
				break;
			case 9:
				grdResults = (MMScrollAreaMS)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_Result_Light_ViewModel : MMTabPageViewModel
	{
		public class grdAssay_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_TLVCONC_Property = CxvPropertyDeclaration.Register("MMTextBox1_TLVCONC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.TLVCONC.@y"
			});

			public static readonly CxvPropertyDeclaration txtMoleFrac_MOLEFRAC_Property = CxvPropertyDeclaration.Register("txtMoleFrac_MOLEFRAC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MOLEFRAC.@y"
			});

			public static readonly CxvPropertyDeclaration txtWtPct_MASSFRAC_Property = CxvPropertyDeclaration.Register("txtWtPct_MASSFRAC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MASSFRAC.@y"
			});

			public static readonly CxvPropertyDeclaration txtVolPct_TLVCONC_Property = CxvPropertyDeclaration.Register("txtVolPct_TLVCONC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.TLVCONC.@y"
			});

			public object MMTextBox1_TLVCONC => GetValue(MMTextBox1_TLVCONC_Property);

			public object txtMoleFrac_MOLEFRAC => GetValue(txtMoleFrac_MOLEFRAC_Property);

			public object txtWtPct_MASSFRAC => GetValue(txtWtPct_MASSFRAC_Property);

			public object txtVolPct_TLVCONC => GetValue(txtVolPct_TLVCONC_Property);
		}

		public static readonly CxvPropertyDeclaration txtMoleFracTotla_TOT_MOL_FRAC_Property = CxvPropertyDeclaration.Register("txtMoleFracTotla_TOT_MOL_FRAC", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TOT_MOL_FRAC"
		});

		public static readonly CxvPropertyDeclaration txtWtPctTotla_TOT_WT_PCT_Property = CxvPropertyDeclaration.Register("txtWtPctTotla_TOT_WT_PCT", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TOT_WT_PCT"
		});

		public static readonly CxvPropertyDeclaration txtVolPctTotal_TOT_LV_PCT_Property = CxvPropertyDeclaration.Register("txtVolPctTotal_TOT_LV_PCT", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TOT_LV_PCT"
		});

		public static readonly CxvPropertyDeclaration lbtuMW_MW_Property = CxvPropertyDeclaration.Register("lbtuMW_MW", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.MW2"
		});

		public static readonly CxvPropertyDeclaration lbtuDensity_DENSITY_Property = CxvPropertyDeclaration.Register("lbtuDensity_DENSITY", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.DENSITY2"
		});

		public static readonly CxvPropertyDeclaration lbtuAPIGrav_API_Property = CxvPropertyDeclaration.Register("lbtuAPIGrav_API", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.API2"
		});

		public static readonly CxvPropertyDeclaration lbtuSpecGrav_SG_Property = CxvPropertyDeclaration.Register("lbtuSpecGrav_SG", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.SG2"
		});

		public static readonly CxvPropertyDeclaration grdAssay_GridData_Property = CxvPropertyDeclaration.Register("grdAssay_GridData", typeof(MMAssay_Result_Light_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdAssay_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.TLVCONC",
				UseChildId = true,
				Name = "y"
			}
		});

		public object txtMoleFracTotla_TOT_MOL_FRAC => GetValue(txtMoleFracTotla_TOT_MOL_FRAC_Property);

		public object txtWtPctTotla_TOT_WT_PCT => GetValue(txtWtPctTotla_TOT_WT_PCT_Property);

		public object txtVolPctTotal_TOT_LV_PCT => GetValue(txtVolPctTotal_TOT_LV_PCT_Property);

		public object lbtuMW_MW => GetValue(lbtuMW_MW_Property);

		public object lbtuDensity_DENSITY => GetValue(lbtuDensity_DENSITY_Property);

		public object lbtuAPIGrav_API => GetValue(lbtuAPIGrav_API_Property);

		public object lbtuSpecGrav_SG => GetValue(lbtuSpecGrav_SG_Property);

		public object grdAssay_GridData => GetValue(grdAssay_GridData_Property);
	}
	[ProgId("MMAssay.MMAssay_Result_Light")]
	public class MMAssay_Result_Light : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuSpecGrav_label;

		internal MMVariableEdit lbtuSpecGrav;

		internal MMLabel lbtuDensity_label;

		internal MMVariableEdit lbtuDensity;

		internal MMLabel lbtuAPIGrav_label;

		internal MMVariableEdit lbtuAPIGrav;

		internal MMLabel lbtuMW_label;

		internal MMVariableEdit lbtuMW;

		internal MMScrollArea grdAssay;

		internal MMScrollAreaManualLayout MMScrollArea1;

		private bool _contentLoaded;

		public MMAssay_Result_Light()
		{
			base.ViewModelType = typeof(MMAssay_Result_Light_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_result_light.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuSpecGrav_label = (MMLabel)target;
				break;
			case 2:
				lbtuSpecGrav = (MMVariableEdit)target;
				break;
			case 3:
				lbtuDensity_label = (MMLabel)target;
				break;
			case 4:
				lbtuDensity = (MMVariableEdit)target;
				break;
			case 5:
				lbtuAPIGrav_label = (MMLabel)target;
				break;
			case 6:
				lbtuAPIGrav = (MMVariableEdit)target;
				break;
			case 7:
				lbtuMW_label = (MMLabel)target;
				break;
			case 8:
				lbtuMW = (MMVariableEdit)target;
				break;
			case 9:
				grdAssay = (MMScrollArea)target;
				break;
			case 10:
				MMScrollArea1 = (MMScrollAreaManualLayout)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMAssay_Result_Pseudo_ViewModel : MMTabPageViewModel
	{
		public class grdPCBreakdown_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCID_CID_Property = CxvPropertyDeclaration.Register("txtCID_CID", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COMPID.@y"
			});

			public static readonly CxvPropertyDeclaration txtMolePct_MOLEFRAC_Property = CxvPropertyDeclaration.Register("txtMolePct_MOLEFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MOLEFRAC2.@y"
			});

			public static readonly CxvPropertyDeclaration txtWtPct_MASSFRAC_Property = CxvPropertyDeclaration.Register("txtWtPct_MASSFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.MASSFRAC2.@y"
			});

			public static readonly CxvPropertyDeclaration txtVolPCt_VOLFRAC_Property = CxvPropertyDeclaration.Register("txtVolPCt_VOLFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.VOLFRAC.@y"
			});

			public object txtCID_CID => GetValue(txtCID_CID_Property);

			public object txtMolePct_MOLEFRAC => GetValue(txtMolePct_MOLEFRAC_Property);

			public object txtWtPct_MASSFRAC => GetValue(txtWtPct_MASSFRAC_Property);

			public object txtVolPCt_VOLFRAC => GetValue(txtVolPCt_VOLFRAC_Property);
		}

		public static readonly CxvPropertyDeclaration grdPCBreakdown_GridData_Property = CxvPropertyDeclaration.Register("grdPCBreakdown_GridData", typeof(MMAssay_Result_Pseudo_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdPCBreakdown_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.COMPID",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdPCBreakdown_GridData => GetValue(grdPCBreakdown_GridData_Property);
	}
	[ProgId("MMAssay.MMAssay_Result_Pseudo")]
	public class MMAssay_Result_Pseudo : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdPCBreakdown;

		private bool _contentLoaded;

		public MMAssay_Result_Pseudo()
		{
			base.ViewModelType = typeof(MMAssay_Result_Pseudo_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmassay_result_pseudo.xaml", UriKind.Relative);
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
				grdPCBreakdown = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMBlend_Mixtur_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration BLND_Property = CxvPropertyDeclaration.Register("BLND", typeof(MMBlend_Mixtur_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BLND"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlend_Mixtur_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@BLND" }
		});

		public object BLND => GetValue(BLND_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMAssay.MMBlend_Mixtur")]
	public class MMBlend_Mixtur : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabMixture;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMBlend_Mixtur()
		{
			base.ViewModelType = typeof(MMBlend_Mixtur_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmblend_mixtur.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabMixture = (MMTabStrip)target;
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
	public class MMBlend_Mixtur_Spec_ViewModel : MMTabPageViewModel
	{
		public class grdBlendComposition_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtPct_Basis_Frac_Property = CxvPropertyDeclaration.Register("txtPct_Basis_Frac", typeof(grdBlendComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.BASIS_FRAC.@y"
			});

			public static readonly CxvPropertyDeclaration cboAID_AID_Property = CxvPropertyDeclaration.Register("cboAID_AID", typeof(grdBlendComposition_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.BASIS_FRAC.@y"
			});

			public object txtPct_Basis_Frac => GetValue(txtPct_Basis_Frac_Property);

			public object cboAID_AID => GetValue(cboAID_AID_Property);
		}

		public static readonly CxvPropertyDeclaration MMLBUText1_BASIS_FRAC_Property = CxvPropertyDeclaration.Register("MMLBUText1_BASIS_FRAC", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.BASIS_FRAC"
		});

		public static readonly CxvPropertyDeclaration grdBlendComposition_GridData_Property = CxvPropertyDeclaration.Register("grdBlendComposition_GridData", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdBlendComposition_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.BASIS_FRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration chkVacuum_var1_Property = CxvPropertyDeclaration.Register("chkVacuum_var1", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_VACLV",
			TrueValue = "VACLV",
			FalseValue = "NOVACLV"
		});

		public static readonly CxvPropertyDeclaration chkASTM_D1160_OPT_D1160_Property = CxvPropertyDeclaration.Register("chkASTM_D1160_OPT_D1160", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_D1160",
			TrueValue = "D1160",
			FalseValue = "NOD1160"
		});

		public static readonly CxvPropertyDeclaration chkASTM_D86_OPT_D86_Property = CxvPropertyDeclaration.Register("chkASTM_D86_OPT_D86", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.OPT_D86",
			TrueValue = "D86",
			FalseValue = "NOD86"
		});

		public object MMLBUText1_BASIS_FRAC => GetValue(MMLBUText1_BASIS_FRAC_Property);

		public object grdBlendComposition_GridData => GetValue(grdBlendComposition_GridData_Property);

		public object chkVacuum_var1 => GetValue(chkVacuum_var1_Property);

		public object chkASTM_D1160_OPT_D1160 => GetValue(chkASTM_D1160_OPT_D1160_Property);

		public object chkASTM_D86_OPT_D86 => GetValue(chkASTM_D86_OPT_D86_Property);
	}
	[ProgId("MMAssay.MMBlend_Mixtur_Spec")]
	public class MMBlend_Mixtur_Spec : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraBlendFraction;

		internal MMScrollArea grdBlendComposition;

		internal MMGroupBox fraRep_as;

		internal MMCheckBox chkASTM_D86;

		internal MMCheckBox chkASTM_D1160;

		internal MMCheckBox chkVacuum;

		private bool _contentLoaded;

		public MMBlend_Mixtur_Spec()
		{
			base.ViewModelType = typeof(MMBlend_Mixtur_Spec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmblend_mixtur_spec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraBlendFraction = (MMGroupBox)target;
				break;
			case 2:
				grdBlendComposition = (MMScrollArea)target;
				break;
			case 3:
				fraRep_as = (MMGroupBox)target;
				break;
			case 4:
				chkASTM_D86 = (MMCheckBox)target;
				break;
			case 5:
				chkASTM_D1160 = (MMCheckBox)target;
				break;
			case 6:
				chkVacuum = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMBlend_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration ACCLENDS_Property = CxvPropertyDeclaration.Register("ACCLENDS", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.TLVCONC"
		});

		public static readonly CxvPropertyDeclaration ACCPSEUDO_Property = CxvPropertyDeclaration.Register("ACCPSEUDO", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.COMPID"
		});

		public static readonly CxvPropertyDeclaration ACCCURVE_Property = CxvPropertyDeclaration.Register("ACCCURVE", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.DIST_RATIO"
		});

		public static readonly CxvPropertyDeclaration ACCBLEND_Property = CxvPropertyDeclaration.Register("ACCBLEND", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.COMPFRAC"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCLENDS" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCPSEUDO" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCCURVE" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@ACCBLEND" }
		});

		public object ACCLENDS => GetValue(ACCLENDS_Property);

		public object ACCPSEUDO => GetValue(ACCPSEUDO_Property);

		public object ACCCURVE => GetValue(ACCCURVE_Property);

		public object ACCBLEND => GetValue(ACCBLEND_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);
	}
	[ProgId("MMAssay.MMBlend_Result")]
	public class MMBlend_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResults;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMBlend_Result()
		{
			base.ViewModelType = typeof(MMBlend_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmblend_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabResults = (MMTabStrip)target;
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
	public class MMBlend_Result_Blend_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_COMPID_Property = CxvPropertyDeclaration.Register("MMTextBox1_COMPID", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.COMPFRAC.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_COMPTYPE_Property = CxvPropertyDeclaration.Register("MMTextBox3_COMPTYPE", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COMPTYPE.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_COMPFRAC_Property = CxvPropertyDeclaration.Register("MMTextBox2_COMPFRAC", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COMPFRAC.@y"
			});

			public object MMTextBox1_COMPID => GetValue(MMTextBox1_COMPID_Property);

			public object MMTextBox3_COMPTYPE => GetValue(MMTextBox3_COMPTYPE_Property);

			public object MMTextBox2_COMPFRAC => GetValue(MMTextBox2_COMPFRAC_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMBlend_Result_Blend_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.COMPFRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMAssay.MMBlend_Result_Blend")]
	public class MMBlend_Result_Blend : MMTabPage, IComponentConnector
	{
		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMBlend_Result_Blend()
		{
			base.ViewModelType = typeof(MMBlend_Result_Blend_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmblend_result_blend.xaml", UriKind.Relative);
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
				MMScrollArea1 = (MMScrollArea)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class MMLeprop_Specif_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration strPID_Property = CxvPropertyDeclaration.Register("strPID", typeof(MMLeprop_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "strPID"
		});

		public static readonly CxvPropertyDeclaration UNLEPROP_Property = CxvPropertyDeclaration.Register("UNLEPROP", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UNLEPROP"
		});

		public static readonly CxvPropertyDeclaration UNLEPPBAS_Property = CxvPropertyDeclaration.Register("UNLEPPBAS", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UNLEPPBAS"
		});

		public static readonly CxvPropertyDeclaration CPLEPROP_Property = CxvPropertyDeclaration.Register("CPLEPROP", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CPLEPROP"
		});

		public static readonly CxvPropertyDeclaration AAAAA_Property = CxvPropertyDeclaration.Register("AAAAA", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.AAAAA"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMLeprop_Specif_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@AAAAA", "@CPLEPROP" },
			EnteredDataPaths = { "@UNLEPPBAS", "@UNLEPROP" }
		});

		public object strPID => GetValue(strPID_Property);

		public object UNLEPROP => GetValue(UNLEPROP_Property);

		public object UNLEPPBAS => GetValue(UNLEPPBAS_Property);

		public object CPLEPROP => GetValue(CPLEPROP_Property);

		public object AAAAA => GetValue(AAAAA_Property);

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
	[ProgId("MMAssay.MMLeprop_Specif")]
	public class MMLeprop_Specif : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMLeprop_Specif()
		{
			base.ViewModelType = typeof(MMLeprop_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmleprop_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMLeprop_Specif_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdLEnds_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtFRAC_var1_Property = CxvPropertyDeclaration.Register("txtFRAC_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.PROP_VALUE.@strPID.@y"
			});

			public static readonly CxvPropertyDeclaration cboCompID_var1_Property = CxvPropertyDeclaration.Register("cboCompID_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.IdWithOptions,
				DataPath = "@main.Input.PROP_VALUE.@strPID.@y"
			});

			public object txtFRAC_var1 => GetValue(txtFRAC_var1_Property);

			public object cboCompID_var1 => GetValue(cboCompID_var1_Property);
		}

		public static readonly CxvPropertyDeclaration grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdLEnds_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.PROP_VALUE.@strPID",
				UseChildId = true,
				Name = "y"
			}
		});

		public static readonly CxvPropertyDeclaration mnuPropType_var2_Property = CxvPropertyDeclaration.Register("mnuPropType_var2", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "strPID"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_UNLEPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNLEPROPB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UNLEPROP"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_UNLEPPBASB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNLEPPBASB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UNLEPPBAS"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_CPLEPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_CPLEPROPB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.CPLEPROP"
		});

		public static readonly CxvPropertyDeclaration mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.PROP_VALUE",
			SelectedItemBinding = "mnuPropType_var2.Value",
			CreateNewPrompt = "Property type:",
			CreateNewPromptResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
			CompletePaths = { "@main.CC Nodes.CPLEPROP" },
			EnteredPaths = { "@main.CC Nodes.UNLEPROP", "@main.CC Nodes.UNLEPPBAS" }
		});

		public static CxvPropertyDeclaration ShowBasis_Property = CxvPropertyDeclaration.Register("ShowBasis", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvLogicalProperty
		{
			Operator = CxvLogicalOperator.Or,
			Tests = 
			{
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "SULFUR"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "BASIC-N2"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "HYDROGEN"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "OXYGEN"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "METAL"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "PARAFFIN"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "NAPHTHEN"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "OLEFIN"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "AROMATIC"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "CARBON"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "MERCAPTA"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "TOTAL-N2"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "IRON"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "NICKEL"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "VANADIUM"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "COCARBON"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "ASPHALTE"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "BROMINE"
				},
				new CxvLogicalTest
				{
					Parameter = "strPID",
					Value = "CETANE"
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox4_var1",
					DataPath = "@main.Input.PROP_BASIS.@strPID"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Mass",
					DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_Mass",
					Value = "MMComboBox4_MultiMapOption_1",
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
					DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_Mole",
					Value = "MMComboBox4_MultiMapOption_2",
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
					DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_StdVol",
					Value = "MMComboBox4_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox4_var1",
							Value = "STDVOL"
						}
					}
				}
			},
			IsVisibleCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.HASBASIS.@strPID"
			}
		});

		public object grdLEnds_GridData => GetValue(grdLEnds_GridData_Property);

		public object mnuPropType_var2 => GetValue(mnuPropType_var2_Property);

		public object mnuPropType_UNLEPROPB => GetValue(mnuPropType_UNLEPROPB_Property);

		public object mnuPropType_UNLEPPBASB => GetValue(mnuPropType_UNLEPPBASB_Property);

		public object mnuPropType_CPLEPROPB => GetValue(mnuPropType_CPLEPROPB_Property);

		public object mnuPropType_var1 => GetValue(mnuPropType_var1_Property);

		public object ShowBasis => GetValue(ShowBasis_Property);

		public object MMComboBox4_MultiMap => GetValue(MMComboBox4_MultiMap_Property);
	}
	[ProgId("MMAssay.MMLeprop_Specif_Specif")]
	public class MMLeprop_Specif_Specif : MMTabPage, IComponentConnector
	{
		internal MMLabel mnuPropType_label;

		internal MMAdvancedComboEdit mnuPropType;

		internal MMLabel MMComboBox4_label;

		internal MMComboEdit MMComboBox4;

		internal MMGroupBox fraLEndsAnal;

		internal MMScrollArea grdLEnds;

		private bool _contentLoaded;

		public MMLeprop_Specif_Specif()
		{
			base.ViewModelType = typeof(MMLeprop_Specif_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Components;component/assayblend/mmleprop_specif_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mnuPropType_label = (MMLabel)target;
				break;
			case 2:
				mnuPropType = (MMAdvancedComboEdit)target;
				break;
			case 3:
				MMComboBox4_label = (MMLabel)target;
				break;
			case 4:
				MMComboBox4 = (MMComboEdit)target;
				break;
			case 5:
				fraLEndsAnal = (MMGroupBox)target;
				break;
			case 6:
				grdLEnds = (MMScrollArea)target;
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

// 0x0600000b AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_ViewModel..ctor
// public MMCompUni_Input_ViewModel()
// {
// }

// 0x0600000c AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompUni_Input_ViewModel()
// {
// 	global_Property = CxvPropertyDeclaration.Register("global", typeof(MMCompUni_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GR"
// 	});
// 	entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MMCompUni_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTSELE"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompUni_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@global" },
// 		EnteredDataPaths = { "@entsele" }
// 	});
// }

// 0x06000011 AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_Group_ViewModel..ctor
// public MMCompUni_Input_Group_ViewModel()
// {
// }

// 0x06000012 AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_Group_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompUni_Input_Group_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompUni_Input_Group_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.GROUPNO",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000022 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_ViewModel..ctor
// public MMComp_Spec_Input_ViewModel()
// {
// }

// 0x06000023 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComp_Spec_Input_ViewModel()
// {
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@selection" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entpet" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entnc" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMComp_Spec_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@compdb" },
// 		EnteredDataPaths = { "@entdb" }
// 	});
// 	selection_Property = CxvPropertyDeclaration.Register("selection", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	entpet_Property = CxvPropertyDeclaration.Register("entpet", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTPET"
// 	});
// 	entnc_Property = CxvPropertyDeclaration.Register("entnc", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTNC"
// 	});
// 	entdb_Property = CxvPropertyDeclaration.Register("entdb", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Pure Databanks.CC Nodes.ENTDBANK"
// 	});
// 	compdb_Property = CxvPropertyDeclaration.Register("compdb", typeof(MMComp_Spec_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "Top.appModelV8.Pure Databanks.CC Nodes.COMPDBANK"
// 	});
// }

// 0x06000030 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Databank_ViewModel..ctor
// public MMComp_Spec_Input_Databank_ViewModel()
// {
// }

// 0x06000031 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Databank_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComp_Spec_Input_Databank_ViewModel()
// {
// 	MMCheckRetrive_var1_Property = CxvPropertyDeclaration.Register("MMCheckRetrive_var1", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.@parent.@parent.Other Databanks.Input.AUTO_PARAM",
// 		TrueValue = "YES",
// 		FalseValue = "NO"
// 	});
// 	LstpBinaryDataBank_filesymnam_Property = CxvPropertyDeclaration.Register("LstpBinaryDataBank_filesymnam", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.@parent.@parent.Other Databanks.Input.FILE_SYM_NAM",
// 		RestoreDefaultOnClear = true,
// 		SkipSemanticOnReorder = true
// 	});
// 	lstpPureDataBanks_filesymnam_Property = CxvPropertyDeclaration.Register("lstpPureDataBanks_filesymnam", typeof(MMComp_Spec_Input_Databank_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.@parent.@parent.Pure Databanks.Input.FILE_SYM_NAM",
// 		RestoreDefaultOnClear = true,
// 		SkipSemanticOnReorder = true
// 	});
// }

// 0x06000036 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_NonConven_ViewModel..ctor
// public MMComp_Spec_Input_NonConven_ViewModel()
// {
// }

// 0x06000037 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_NonConven_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComp_Spec_Input_NonConven_ViewModel()
// {
// 	grdNonConventionalComponents_GridData_Property = CxvPropertyDeclaration.Register("grdNonConventionalComponents_GridData", typeof(MMComp_Spec_Input_NonConven_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdNonConventionalComponents_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.NONCONVID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000041 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel..ctor
// public MMComp_Spec_Input_Petroleum_ViewModel()
// {
// }

// 0x06000042 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComp_Spec_Input_Petroleum_ViewModel()
// {
// 	cmdAssayLibrary_Command_var1_Property = CxvPropertyDeclaration.Register("cmdAssayLibrary_Command_var1", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "Import assay data",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Petroleum_ViewModel__CxvCmdButtonProperty_ToolTipText_Assay_Library"
// 	});
// 	grdPseudocomponents_GridData_Property = CxvPropertyDeclaration.Register("grdPseudocomponents_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPseudocomponents_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PSEUDOCOMPID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	grdBlend_GridData_Property = CxvPropertyDeclaration.Register("grdBlend_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdBlend_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.BLENDID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	grdAssay_GridData_Property = CxvPropertyDeclaration.Register("grdAssay_GridData", typeof(MMComp_Spec_Input_Petroleum_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAssay_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.ASSAYID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000062 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Selection_ViewModel..ctor
// public MMComp_Spec_Input_Selection_ViewModel()
// {
// }

// 0x06000063 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Selection_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMComp_Spec_Input_Selection_ViewModel()
// {
// 	grdComponents_GridData_Property = CxvPropertyDeclaration.Register("grdComponents_GridData", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdComponents_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.TYPE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	cmdReview_var1_Property = CxvPropertyDeclaration.Register("cmdReview_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			SubConditions = 
// 			{
// 				new CxvLogicalTest
// 				{
// 					DataPath = "@main.@parent.@parent.Other Databanks.CC Nodes.LOADPURE"
// 				},
// 				new CxvLogicalTest
// 				{
// 					DataPath = "Top.AppModelV8",
// 					DataAttribute = "status_code",
// 					Operator = CxvLogicalOperator.NotEqual,
// 					Value = 4
// 				}
// 			}
// 		},
// 		ToolTipText = "Review available pure component parameters",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Review"
// 	});
// 	CmdFind_Command_var1_Property = CxvPropertyDeclaration.Register("CmdFind_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "Find components",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Find_Components"
// 	});
// 	CmdElecWizard_Command_var1_Property = CxvPropertyDeclaration.Register("CmdElecWizard_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "Electrolyte wizard",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Electrolyte_Wizard"
// 	});
// 	CmdSFEAssistant_Command_var1_Property = CxvPropertyDeclaration.Register("CmdSFEAssistant_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "Solid-Fluid Equilibrium assistant",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_SFE_Assistant"
// 	});
// 	CmdUserDefWizard_Command_var1_Property = CxvPropertyDeclaration.Register("CmdUserDefWizard_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "User-defined component wizard",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_User_Defined"
// 	});
// 	CmdReorder_Command_var1_Property = CxvPropertyDeclaration.Register("CmdReorder_Command_var1", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = "Change order of components",
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Reorder_Components"
// 	});
// 	BioLookupVar_Property = CxvPropertyDeclaration.Register("BioLookupVar", typeof(MMComp_Spec_Input_Selection_ViewModel), new CxvCmdButtonProperty
// 	{
// 		ToolTipText = ApwnResources.BiomassLookupTooltip,
// 		ToolTipTextResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvCmdButtonProperty_ToolTipText_Biomass_Loolup",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.@parent.Bio-Comps.CC Nodes.BIOLKP",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = 0
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.@parent.Bio-Comps.CC Nodes.BIOLKP",
// 			Operator = CxvLogicalOperator.Equal,
// 			Value = 0
// 		}
// 	});
// }

// 0x0600007f AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_ViewModel..ctor
// public MMPseudo_Input_ViewModel()
// {
// }

// 0x06000080 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_ViewModel()
// {
// 	PseudoMain_Property = CxvPropertyDeclaration.Register("PseudoMain", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.CC Nodes.MAIN"
// 	});
// 	wscid_Property = CxvPropertyDeclaration.Register("wscid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "wscid"
// 	});
// 	vicid_Property = CxvPropertyDeclaration.Register("vicid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vicid"
// 	});
// 	vpcid_Property = CxvPropertyDeclaration.Register("vpcid", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vpcid"
// 	});
// 	VAPOR_Property = CxvPropertyDeclaration.Register("VAPOR", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VAPOR"
// 	});
// 	VISC_Property = CxvPropertyDeclaration.Register("VISC", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VISC"
// 	});
// 	SOLU_Property = CxvPropertyDeclaration.Register("SOLU", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.SOLU"
// 	});
// 	VPOPT_Property = CxvPropertyDeclaration.Register("VPOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VPOPT"
// 	});
// 	VIOPT_Property = CxvPropertyDeclaration.Register("VIOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VIOPT"
// 	});
// 	WSOPT_Property = CxvPropertyDeclaration.Register("WSOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.WSOPT"
// 	});
// 	DISABLE_Property = CxvPropertyDeclaration.Register("DISABLE", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.CC Nodes.DISABLE"
// 	});
// 	PSEUDOOPT_Property = CxvPropertyDeclaration.Register("PSEUDOOPT", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.CC Nodes.PSEUDOOPT"
// 	});
// 	_NOUSRPROP_Property = CxvPropertyDeclaration.Register("_NOUSRPROP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.NOUSRPROP"
// 	});
// 	CPPROP_Property = CxvPropertyDeclaration.Register("CPPROP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.CPPROP"
// 	});
// 	UNPP_Property = CxvPropertyDeclaration.Register("UNPP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.UNPP"
// 	});
// 	strPID_Property = CxvPropertyDeclaration.Register("strPID", typeof(MMPseudo_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "strPID"
// 	});
// 	ENPP_Property = CxvPropertyDeclaration.Register("ENPP", typeof(MMPseudo_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.ENPP"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PseudoMain" },
// 		AccessibleDataPaths = { "@DISABLE" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@VAPOR" },
// 		AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
// 		EnteredDataPaths = { "@VPOPT" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@VISC" },
// 		AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
// 		EnteredDataPaths = { "@VIOPT" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@SOLU" },
// 		AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE" },
// 		EnteredDataPaths = { "@WSOPT" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMPseudo_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CPPROP" },
// 		AccessibleDataPaths = { "@_NOUSRPROP", "@DISABLE", "@ENPP" },
// 		EnteredDataPaths = { "@UNPP" }
// 	});
// }

// 0x06000089 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Petro_ViewModel..ctor
// public MMPseudo_Input_Petro_ViewModel()
// {
// }

// 0x0600008a AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Petro_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_Petro_ViewModel()
// {
// 	grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLEnds_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Properties.Input.VALUE.@strPID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	mnuPropType_var2_Property = CxvPropertyDeclaration.Register("mnuPropType_var2", typeof(MMPseudo_Input_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "strPID"
// 	});
// 	mnuPropType_CPPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_CPPROPB", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.CPPROP"
// 	});
// 	mnuPropType_UNPPB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNPPB", typeof(MMPseudo_Input_Petro_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.UNPP"
// 	});
// 	mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMPseudo_Input_Petro_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Properties.Input.VALUE",
// 		SelectedItemBinding = "mnuPropType_var2.Value",
// 		CreateNewPrompt = "Property type:",
// 		CreateNewPromptResourceKey = "MMPseudo_Input_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
// 		CompletePaths = { "@main.Properties.CC Nodes.CPPROP" },
// 		EnteredPaths = { "@main.Properties.CC Nodes.UNPP" }
// 	});
// }

// 0x0600009b AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel..ctor
// public MMPseudo_Input_Spec_ViewModel()
// {
// }

// 0x0600009c AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_Spec_ViewModel()
// {
// 	cboViewLayout_MultiMap_Property = CxvPropertyDeclaration.Register("cboViewLayout_MultiMap", typeof(MMPseudo_Input_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboViewLayout_VIEWLAYOUT",
// 				DataPath = "@main.Specifications.Input.VIEWLAYOUT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Basic layout",
// 				DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Basic_layout",
// 				Value = "cboViewLayout_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboViewLayout_VIEWLAYOUT",
// 						Value = "BASIC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Advanced layout",
// 				DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Advanced_layout",
// 				Value = "cboViewLayout_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboViewLayout_VIEWLAYOUT",
// 						Value = "ADVANCED"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.DISABLE"
// 		}
// 	});
// 	lblView_state_Property = CxvPropertyDeclaration.Register("lblView_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvLabelProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.DISABLE"
// 		}
// 	});
// 	fraAdvanced_state_Property = CxvPropertyDeclaration.Register("fraAdvanced_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.DISABLE"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.OPTIONA"
// 		}
// 	});
// 	lbtuLDen_LDenUnits_Property = CxvPropertyDeclaration.Register("lbtuLDen_LDenUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.LDEN"
// 	});
// 	lbtuTempUnits_TempUnits_Property = CxvPropertyDeclaration.Register("lbtuTempUnits_TempUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.NBP"
// 	});
// 	grdAdvanced_GridData_Property = CxvPropertyDeclaration.Register("grdAdvanced_GridData", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAdvanced_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Specifications.Input.PCOPSETNAME",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	fraBasic_state_Property = CxvPropertyDeclaration.Register("fraBasic_state", typeof(MMPseudo_Input_Spec_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.DISABLE"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.OPTIONB"
// 		}
// 	});
// 	fraBasic_gravname_Property = CxvPropertyDeclaration.Register("fraBasic_gravname", typeof(MMPseudo_Input_Spec_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "gravname"
// 	});
// 	MMComboBox1_basicopset_Property = CxvPropertyDeclaration.Register("MMComboBox1_basicopset", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Specifications.Input.PCOPSETNAME.#0"
// 	});
// 	grdBasic_GridData_Property = CxvPropertyDeclaration.Register("grdBasic_GridData", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdBasic_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Specifications.Input.PCOPSETNAME",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	MMLBUText3_TempUnits_Property = CxvPropertyDeclaration.Register("MMLBUText3_TempUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.NBP"
// 	});
// 	lbtuNBP_LDenUnits_Property = CxvPropertyDeclaration.Register("lbtuNBP_LDenUnits", typeof(MMPseudo_Input_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.LDEN",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Specifications.CC Nodes.OPT_DEN"
// 		}
// 	});
// 	cboGravType_MultiMap_Property = CxvPropertyDeclaration.Register("cboGravType_MultiMap", typeof(MMPseudo_Input_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboGravType_gravtype",
// 				DataPath = "@main.Specifications.Input.GRAVTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "API Gravity",
// 				DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_API_Gravity",
// 				Value = "cboGravType_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboGravType_gravtype",
// 						Value = "API"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Specific gravity",
// 				DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
// 				Value = "cboGravType_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboGravType_gravtype",
// 						Value = "GRAV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Density",
// 				DisplayResourceKey = "MMPseudo_Input_Spec_ViewModel__CxvMultiMapOption_Display_Density",
// 				Value = "cboGravType_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboGravType_gravtype",
// 						Value = "LDEN"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x060000ac AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Vapor_ViewModel..ctor
// public MMPseudo_Input_Vapor_ViewModel()
// {
// }

// 0x060000ad AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Vapor_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_Vapor_ViewModel()
// {
// 	fraVapor_state_Property = CxvPropertyDeclaration.Register("fraVapor_state", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "vpcid",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.TEMP.@vpcid"
// 	});
// 	lbtuVisc_var1_Property = CxvPropertyDeclaration.Register("lbtuVisc_var1", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VP.@vpcid"
// 	});
// 	MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vpcid"
// 	});
// 	MMMenuButton1_VPCOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VPCOMP", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VPCOMP"
// 	});
// 	MMMenuButton1_VAPOR2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VAPOR2", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VAPOR2"
// 	});
// 	MMMenuButton1_VPOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VPOPT2", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VPOPT2"
// 	});
// 	MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Properties.Input.TEMP",
// 		SelectedItemBinding = "MMMenuButton1_target.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMPseudo_Input_Vapor_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
// 		CompletePaths = { "@main.Properties.CC Nodes.VPCOMP", "@main.Properties.CC Nodes.VAPOR2" },
// 		EnteredPaths = { "@main.Properties.CC Nodes.VPOPT2" }
// 	});
// 	grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Vapor_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdVisc_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Properties.Input.@indexVar.@vpcid",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060000be AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Viscos_ViewModel..ctor
// public MMPseudo_Input_Viscos_ViewModel()
// {
// }

// 0x060000bf AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Viscos_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_Viscos_ViewModel()
// {
// 	fraVisc_state_Property = CxvPropertyDeclaration.Register("fraVisc_state", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "vicid",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VITEMP.@vicid"
// 	});
// 	lbtuVisc_var1_Property = CxvPropertyDeclaration.Register("lbtuVisc_var1", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VISC.@vicid"
// 	});
// 	MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vicid"
// 	});
// 	MMMenuButton1_VICOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VICOMP", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VICOMP"
// 	});
// 	MMMenuButton1_VISC2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VISC2", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VISC2"
// 	});
// 	MMMenuButton1_VIOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_VIOPT2", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.VIOPT2"
// 	});
// 	MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Properties.Input.VITEMP",
// 		SelectedItemBinding = "MMMenuButton1_target.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMPseudo_Input_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
// 		CompletePaths = { "@main.Properties.CC Nodes.VICOMP", "@main.Properties.CC Nodes.VISC2" },
// 		EnteredPaths = { "@main.Properties.CC Nodes.VIOPT2" }
// 	});
// 	grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Viscos_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdVisc_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Properties.Input.@indexVar.@vicid",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060000cf AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Water_ViewModel..ctor
// public MMPseudo_Input_Water_ViewModel()
// {
// }

// 0x060000d0 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Water_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPseudo_Input_Water_ViewModel()
// {
// 	fraWater_state_Property = CxvPropertyDeclaration.Register("fraWater_state", typeof(MMPseudo_Input_Water_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "wscid",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.MTEMP.@wscid"
// 	});
// 	MMMenuButton1_target_Property = CxvPropertyDeclaration.Register("MMMenuButton1_target", typeof(MMPseudo_Input_Water_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "wscid"
// 	});
// 	MMMenuButton1_WSCOMP_Property = CxvPropertyDeclaration.Register("MMMenuButton1_WSCOMP", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.WSCOMP"
// 	});
// 	MMMenuButton1_SOLU2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_SOLU2", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.SOLU2"
// 	});
// 	MMMenuButton1_WSOPT2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_WSOPT2", typeof(MMPseudo_Input_Water_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.CC Nodes.WSOPT2"
// 	});
// 	MMMenuButton1_Selector_Property = CxvPropertyDeclaration.Register("MMMenuButton1_Selector", typeof(MMPseudo_Input_Water_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Properties.Input.MTEMP",
// 		SelectedItemBinding = "MMMenuButton1_target.Value",
// 		CreateNewPrompt = "Component ID:",
// 		CreateNewPromptResourceKey = "MMPseudo_Input_Water_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID_",
// 		CompletePaths = { "@main.Properties.CC Nodes.WSCOMP", "@main.Properties.CC Nodes.SOLU2" },
// 		EnteredPaths = { "@main.Properties.CC Nodes.WSOPT2" }
// 	});
// 	grdVisc_GridData_Property = CxvPropertyDeclaration.Register("grdVisc_GridData", typeof(MMPseudo_Input_Water_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdVisc_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Properties.Input.@indexVar.@wscid",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060000ea AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_ViewModel..ctor
// public MMPolymers_Charact_ViewModel()
// {
// }

// 0x060000eb AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_ViewModel()
// {
// 	CCSeg_Property = CxvPropertyDeclaration.Register("CCSeg", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SEGS"
// 	});
// 	CCPolym_Property = CxvPropertyDeclaration.Register("CCPolym", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CATTS"
// 	});
// 	CCOlig_Property = CxvPropertyDeclaration.Register("CCOlig", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.OLID"
// 	});
// 	CCAtt_Property = CxvPropertyDeclaration.Register("CCAtt", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CAID"
// 	});
// 	ENOlig_Property = CxvPropertyDeclaration.Register("ENOlig", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EXOLI"
// 	});
// 	ENPol_Property = CxvPropertyDeclaration.Register("ENPol", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EXPOL"
// 	});
// 	POLYCOM_Property = CxvPropertyDeclaration.Register("POLYCOM", typeof(MMPolymers_Charact_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYCOM"
// 	});
// 	ENTOli_Property = CxvPropertyDeclaration.Register("ENTOli", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTOLI"
// 	});
// 	ENTCat_Property = CxvPropertyDeclaration.Register("ENTCat", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTCAT"
// 	});
// 	OLIGD_Property = CxvPropertyDeclaration.Register("OLIGD", typeof(MMPolymers_Charact_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "OLIGD"
// 	});
// 	OLIG_Property = CxvPropertyDeclaration.Register("OLIG", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTPOL"
// 	});
// 	CCSUB_Property = CxvPropertyDeclaration.Register("CCSUB", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CATTS.@POLYCOM"
// 	});
// 	CCSUBC_Property = CxvPropertyDeclaration.Register("CCSUBC", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CAID.@CATID"
// 	});
// 	ACCSEGD_Property = CxvPropertyDeclaration.Register("ACCSEGD", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ACCSEGD"
// 	});
// 	ENTOpti_Property = CxvPropertyDeclaration.Register("ENTOpti", typeof(MMPolymers_Charact_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTOPTI"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCSeg" },
// 		AccessibleDataPaths = { "@ACCSEGD" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCPolym" },
// 		AccessibleDataPaths = { "@ENPol" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCOlig" },
// 		AccessibleDataPaths = { "@ACCSEGD" },
// 		EnteredDataPaths = { "@ENTOli" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCAtt" },
// 		AccessibleDataPaths = { "@ENPol" },
// 		EnteredDataPaths = { "@ENTCat" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMPolymers_Charact_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ENTOpti" }
// 	});
// }

// 0x060000f8 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attrib_ViewModel..ctor
// using System.Collections.Generic;
//
// public MMPolymers_Charact_Attrib_ViewModel()
// {
// 	_initialCheckedNames = new List<string>();
// 	_valueOptions = new Dictionary<string, string>
// 	{
// 		{ "mmtogval0", "SFLOW" },
// 		{ "mmtogval1", "SFRAC" },
// 		{ "mmtogval2", "EFRAC" },
// 		{ "mmtogval3", "DPN" },
// 		{ "mmtogval4", "DPW" },
// 		{ "mmtogval5", "DPZ" },
// 		{ "mmtogval6", "PDI" },
// 		{ "mmtogval7", "MWN" },
// 		{ "mmtogval8", "MWW" },
// 		{ "mmtogval9", "MWZ" },
// 		{ "mmtogval10", "MWSEG" },
// 		{ "mmtogval11", "ZMOM" },
// 		{ "mmtogval12", "FMOM" },
// 		{ "mmtogval13", "SMOM" },
// 		{ "mmtogval14", "TMOM" },
// 		{ "mmtogval15", "LCB" },
// 		{ "mmtogval16", "SCB" },
// 		{ "mmtogval17", "FLCB" },
// 		{ "mmtogval18", "FSCB" },
// 		{ "mmtogval19", "PDV" },
// 		{ "mmtogval20", "PSDZMOM" },
// 		{ "mmtogval21", "PSDFMOM" },
// 		{ "mmtogval22", "PSDSMOM" },
// 		{ "mmtogval23", "PSDTMOM" },
// 		{ "mmtogval24", "VOLN" },
// 		{ "mmtogval25", "VOLV" },
// 		{ "mmtogval26", "VOLZ" },
// 		{ "mmtogval27", "DIAV" },
// 		{ "mmtogval28", "ATFLOW" },
// 		{ "mmtogval29", "ATFRAC" },
// 		{ "mmtogval30", "DYADFLOW" },
// 		{ "mmtogval31", "DYADFRAC" },
// 		{ "mmtogval32", "BLOCKN" },
// 		{ "mmtogval33", "HTHFLOW" },
// 		{ "mmtogval34", "HTHFRAC" },
// 		{ "mmtogval35", "CIS-FLOW" },
// 		{ "mmtogval36", "CIS-FRAC" },
// 		{ "mmtogval37", "TRANSFLO" },
// 		{ "mmtogval38", "TRANSFRA" },
// 		{ "mmtogval39", "VINYLFRA" },
// 		{ "mmtogval40", "TDBFLOW" },
// 		{ "mmtogval41", "TDBFRAC" },
// 		{ "mmtogval42", "XFLOW" },
// 		{ "mmtogval43", "XDENSITY" },
// 		{ "mmtogval44", "FRAGFLOW" },
// 		{ "mmtogval45", "LSFLOW" },
// 		{ "mmtogval46", "LSFRAC" },
// 		{ "mmtogval47", "LEFLOW" },
// 		{ "mmtogval48", "LEFRAC" },
// 		{ "mmtogval49", "LDPN" },
// 		{ "mmtogval50", "LDPW" },
// 		{ "mmtogval51", "LPDI" },
// 		{ "mmtogval52", "LMWN" },
// 		{ "mmtogval53", "LMWW" },
// 		{ "mmtogval54", "LMWSEG" },
// 		{ "mmtogval55", "LZMOM" },
// 		{ "mmtogval56", "LFMOM" },
// 		{ "mmtogval57", "LSMOM" },
// 		{ "mmtogval58", "LPFRAC" },
// 		{ "mmtogval59", "SSFLOW" },
// 		{ "mmtogval60", "SSFRAC" },
// 		{ "mmtogval61", "SEFRAC" },
// 		{ "mmtogval62", "SDPN" },
// 		{ "mmtogval63", "SDPW" },
// 		{ "mmtogval64", "SDPZ" },
// 		{ "mmtogval65", "SPDI" },
// 		{ "mmtogval66", "SMWN" },
// 		{ "mmtogval67", "SMWW" },
// 		{ "mmtogval68", "SMWZ" },
// 		{ "mmtogval69", "SMWSEG" },
// 		{ "mmtogval70", "SZMOM" },
// 		{ "mmtogval71", "SFMOM" },
// 		{ "mmtogval72", "SSMOM" },
// 		{ "mmtogval73", "STMOM" },
// 		{ "mmtogval74", "SLCB" },
// 		{ "mmtogval75", "SSCB" },
// 		{ "mmtogval76", "SFLCB" },
// 		{ "mmtogval77", "SFSCB" },
// 		{ "mmtogval78", "SPFRAC" },
// 		{ "mmtogval79", "SATFLOW" },
// 		{ "mmtogval80", "SATFRAC" },
// 		{ "mmtogval81", "SHTHFLOW" },
// 		{ "mmtogval82", "SHTHFRAC" },
// 		{ "mmtogval83", "STDBFLOW" },
// 		{ "mmtogval84", "STDBFRAC" },
// 		{ "mmtogval85", "LSSFLOW" },
// 		{ "mmtogval86", "LSSFRAC" },
// 		{ "mmtogval87", "LSEFLOW" },
// 		{ "mmtogval88", "LSEFRAC" },
// 		{ "mmtogval89", "LSDPN" },
// 		{ "mmtogval90", "LSDPW" },
// 		{ "mmtogval91", "LSPDI" },
// 		{ "mmtogval92", "LSMWN" },
// 		{ "mmtogval93", "LSMWW" },
// 		{ "mmtogval94", "LSMWSEG" },
// 		{ "mmtogval95", "LSZMOM" },
// 		{ "mmtogval96", "LSFMOM" },
// 		{ "mmtogval97", "LSSMOM" },
// 		{ "mmtogval98", "LSTMOM" },
// 		{ "mmtogval99", "LSPFRAC" },
// 		{ "mmtogval100", "ASFLOW" },
// 		{ "mmtogval101", "ASFRAC" },
// 		{ "mmtogval102", "AEFLOW" },
// 		{ "mmtogval103", "AEFRAC" },
// 		{ "mmtogval104", "ADPN" },
// 		{ "mmtogval105", "ADPW" },
// 		{ "mmtogval106", "APDI" },
// 		{ "mmtogval107", "AMWN" },
// 		{ "mmtogval108", "AMWW" },
// 		{ "mmtogval109", "AMWSEG" },
// 		{ "mmtogval110", "AZMOM" },
// 		{ "mmtogval111", "AFMOM" },
// 		{ "mmtogval112", "ASMOM" },
// 		{ "mmtogval113", "APFRAC" },
// 		{ "mmtogval114", "ASSFLOW" },
// 		{ "mmtogval115", "ASSFRAC" },
// 		{ "mmtogval116", "ASEFLOW" },
// 		{ "mmtogval117", "ASEFRAC" },
// 		{ "mmtogval118", "ASDPN" },
// 		{ "mmtogval119", "ASDPW" },
// 		{ "mmtogval120", "ASPDI" },
// 		{ "mmtogval121", "ASMWN" },
// 		{ "mmtogval122", "ASMWW" },
// 		{ "mmtogval123", "ASMWSEG" },
// 		{ "mmtogval124", "ASZMOM" },
// 		{ "mmtogval125", "ASFMOM" },
// 		{ "mmtogval126", "ASSMOM" },
// 		{ "mmtogval127", "ASTMOM" },
// 		{ "mmtogval128", "ASPFRAC" },
// 		{ "mmtogval129", "DSEFLOW" },
// 		{ "mmtogval130", "DSSFLOW" },
// 		{ "mmtogval131", "DSSMOM" },
// 		{ "mmtogval132", "DSTMOM" },
// 		{ "mmtogval133", "CACLASS0" },
// 		{ "mmtogval134", "CAUSR1" },
// 		{ "mmtogval135", "CAUSR2" },
// 		{ "mmtogval136", "CAUSR3" },
// 		{ "mmtogval137", "CAUSR4" },
// 		{ "mmtogval138", "CAUSR5" },
// 		{ "mmtogval139", "CAUSRA" },
// 		{ "mmtogval140", "CAUSRB" },
// 		{ "mmtogval141", "CAUSRC" },
// 		{ "mmtogval142", "CAUSRD" },
// 		{ "mmtogval143", "CAUSRE" },
// 		{ "mmtogval144", "ZECR" },
// 		{ "mmtogval145", "FECR" },
// 		{ "mmtogval146", "SECR" },
// 		{ "mmtogval147", "ZMCR" },
// 		{ "mmtogval148", "FMCR" },
// 		{ "mmtogval149", "SMCR" },
// 		{ "mmtogval150", "ZSCR" },
// 		{ "mmtogval151", "FSCR" },
// 		{ "mmtogval152", "SSCR" }
// 	};
// 	base..ctor();
// }

// 0x060000f9 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attrib_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Attrib_ViewModel()
// {
// 	lcbPolymer_PolValue_Property = CxvPropertyDeclaration.Register("lcbPolymer_PolValue", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "PolValue"
// 	});
// 	chklPolAtt_var1_Property = CxvPropertyDeclaration.Register("chklPolAtt_var1", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTP.@POLYCOM"
// 	});
// 	lcbPolymer_var2_Property = CxvPropertyDeclaration.Register("lcbPolymer_var2", typeof(MMPolymers_Charact_Attrib_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYCOM",
// 		IsReadOnly = true
// 	});
// }

// 0x0600010c AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attribc_ViewModel..ctor
// using System.Collections.Generic;
//
// public MMPolymers_Charact_Attribc_ViewModel()
// {
// 	_initialCheckedNames1 = new List<string>();
// 	_initialCheckedNames2 = new List<string>();
// 	_valueOptions1 = new Dictionary<string, string>
// 	{
// 		{ "mmtogval0", "PT0FLOW" },
// 		{ "mmtogval1", "CIONFLOW" },
// 		{ "mmtogval2", "P0FLOW" }
// 	};
// 	_valueOptions2 = new Dictionary<string, string>
// 	{
// 		{ "mmtogval3", "CPSFLOW" },
// 		{ "mmtogval4", "CPSFRAC" },
// 		{ "mmtogval5", "CVSFLOW" },
// 		{ "mmtogval6", "CVSFRAC" },
// 		{ "mmtogval7", "CISFLOW" },
// 		{ "mmtogval8", "CISFRAC" },
// 		{ "mmtogval9", "CDSFLOW" },
// 		{ "mmtogval10", "CDSFRAC" },
// 		{ "mmtogval11", "CMSFLOW" },
// 		{ "mmtogval12", "CMSFRAC" }
// 	};
// 	base..ctor();
// }

// 0x0600010d AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attribc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Attribc_ViewModel()
// {
// 	cboAttCatID_CatValue_Property = CxvPropertyDeclaration.Register("cboAttCatID_CatValue", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "CatValue"
// 	});
// 	chklCatAtt_var1_Property = CxvPropertyDeclaration.Register("chklCatAtt_var1", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTC.@CATID"
// 	});
// 	chklIniAtt_var1_Property = CxvPropertyDeclaration.Register("chklIniAtt_var1", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTC.@CATID"
// 	});
// 	S1Visibility_Property = CxvPropertyDeclaration.Register("S1Visibility", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvLogicalProperty
// 	{
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main.Input.SITCOM",
// 				Operator = CxvLogicalOperator.NotEqual,
// 				Value = "CATALYST"
// 			}
// 		}
// 	});
// 	S2Visibility_Property = CxvPropertyDeclaration.Register("S2Visibility", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvLogicalProperty
// 	{
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main.Input.SITCOM",
// 				Operator = CxvLogicalOperator.Equal,
// 				Value = "CATALYST"
// 			}
// 		}
// 	});
// 	cboAttCatID_var2_Property = CxvPropertyDeclaration.Register("cboAttCatID_var2", typeof(MMPolymers_Charact_Attribc_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "CATID",
// 		IsReadOnly = true
// 	});
// }

// 0x06000127 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Catal_ViewModel..ctor
// public MMPolymers_Charact_Catal_ViewModel()
// {
// }

// 0x06000128 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Catal_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Catal_ViewModel()
// {
// 	mnuCatID_Save_Property = CxvPropertyDeclaration.Register("mnuCatID_Save", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "CATID"
// 	});
// 	mnuCatID_List_Property = CxvPropertyDeclaration.Register("mnuCatID_List", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTC",
// 		SelectedItemBinding = "mnuCatID_Save.Value",
// 		CreateNewPrompt = "Comp ID:",
// 		CreateNewPromptResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Comp_ID_",
// 		CompletePaths = { "CAID1", "CATT2" },
// 		EnteredPaths = { "ENTCAT" }
// 	});
// 	spnNsite_var1_Property = CxvPropertyDeclaration.Register("spnNsite_var1", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NSITES",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CATID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lblNsite_state_Property = CxvPropertyDeclaration.Register("lblNsite_state", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvLabelProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CATID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lbtuMxSite_var1_Property = CxvPropertyDeclaration.Register("lbtuMxSite_var1", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MXSITE.@CATID",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.OPTSCO"
// 		}
// 	});
// 	fraCatAtt_state_Property = CxvPropertyDeclaration.Register("fraCatAtt_state", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "CATID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	NumRow_Property = CxvPropertyDeclaration.Register("NumRow", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTC.@CATID"
// 	});
// 	fraSitComp_MultiMap_Property = CxvPropertyDeclaration.Register("fraSitComp_MultiMap", typeof(MMPolymers_Charact_Catal_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "fraSitComp_var1",
// 				DataPath = "@main.Input.SITCOM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Ziegler-Natta catalyst",
// 				DisplayResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvMultiMapOption_Display_Ziegler_Natta_catalyst",
// 				Value = "fraSitComp_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "fraSitComp_var1",
// 						Value = "CATALYST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Ionic initiator",
// 				DisplayResourceKey = "MMPolymers_Charact_Catal_ViewModel__CxvMultiMapOption_Display_Ionic_initiator",
// 				Value = "fraSitComp_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "fraSitComp_var1",
// 						Value = "INITIATOR"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x0600012e AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel..ctor
// public MMPolymers_Charact_Oligom_ViewModel()
// {
// }

// 0x0600012f AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Oligom_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPolymers_Charact_Oligom_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.NUMBER",
// 			UseChildId = true,
// 			Name = "Olig"
// 		}
// 	});
// }

// 0x06000139 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Options_ViewModel..ctor
// public MMPolymers_Charact_Options_ViewModel()
// {
// }

// 0x0600013a AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Options_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Options_ViewModel()
// {
// 	spnNsite_var1_Property = CxvPropertyDeclaration.Register("spnNsite_var1", typeof(MMPolymers_Charact_Options_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.N_BIFUN_INIT"
// 	});
// 	chkSolidPol_var1_Property = CxvPropertyDeclaration.Register("chkSolidPol_var1", typeof(MMPolymers_Charact_Options_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.CHKSOLIDPOL",
// 		TrueValue = "YES",
// 		FalseValue = "NO"
// 	});
// 	MMLBUText_Threshold_Property = CxvPropertyDeclaration.Register("MMLBUText_Threshold", typeof(MMPolymers_Charact_Options_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SP_THRESHOLD"
// 	});
// 	MMFrameOption_state_Property = CxvPropertyDeclaration.Register("MMFrameOption_state", typeof(MMPolymers_Charact_Options_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EXPOL"
// 		}
// 	});
// 	_OptionVisible_Property = CxvPropertyDeclaration.Register("_OptionVisible", typeof(MMPolymers_Charact_Options_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "_OptionVisible"
// 	});
// }

// 0x06000151 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Polymer_ViewModel..ctor
// public MMPolymers_Charact_Polymer_ViewModel()
// {
// }

// 0x06000152 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Polymer_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMPolymers_Charact_Polymer_ViewModel()
// {
// 	lblModified_state_Property = CxvPropertyDeclaration.Register("lblModified_state", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvLabelProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GMOD.@POLYCOM"
// 		}
// 	});
// 	cboAttrGroup_MultiMap_Property = CxvPropertyDeclaration.Register("cboAttrGroup_MultiMap", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboAttrGroup_var1",
// 				DataPath = "@main.Input.CAT_GROUP.@POLYCOM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Minimum selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_min_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Minimum_selection",
// 				Value = "cboAttrGroup_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "MIN-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Properties selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_prop_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Properties_selection",
// 				Value = "cboAttrGroup_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "PROP-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Emulsion selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_emul_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Emulsion_selection",
// 				Value = "cboAttrGroup_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "EMUL-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Anionic selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_anion_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Anionic_selection",
// 				Value = "cboAttrGroup_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "ANION-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cationic selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_cation_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Cationic_selection",
// 				Value = "cboAttrGroup_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "CATION-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Free-radical selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_free_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Free_radical_selection",
// 				Value = "cboAttrGroup_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "FREE-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Pyrolysis selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_pyro_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Pyrolysis_selection",
// 				Value = "cboAttrGroup_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "PYRO-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Step-growth selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_step_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Step_growth_selection",
// 				Value = "cboAttrGroup_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "STEP-CAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Ziegler-Natta selection",
// 				Prompt = ApwnComboPromptResource.polymers_cat_group_zieg_cat_prompt,
// 				DisplayResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvMultiMapOption_Display_Ziegler_Natta_selection",
// 				Value = "cboAttrGroup_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboAttrGroup_var1",
// 						Value = "ZIEG-CAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	Pol_Property = CxvPropertyDeclaration.Register("Pol", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYCOM"
// 	});
// 	mnuPolymer_View_Property = CxvPropertyDeclaration.Register("mnuPolymer_View", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYCOM"
// 	});
// 	mnuPolymer_Catts_Property = CxvPropertyDeclaration.Register("mnuPolymer_Catts", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CATTS"
// 	});
// 	mnuPolymer_List_Property = CxvPropertyDeclaration.Register("mnuPolymer_List", typeof(MMPolymers_Charact_Polymer_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.ATT_LISTP",
// 		SelectedItemBinding = "mnuPolymer_View.Value",
// 		CreateNewPrompt = "Polymer ID",
// 		CreateNewPromptResourceKey = "MMPolymers_Charact_Polymer_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Polymer_ID",
// 		CompletePaths = { "CATTS" }
// 	});
// }

// 0x06000158 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Segment_ViewModel..ctor
// public MMPolymers_Charact_Segment_ViewModel()
// {
// }

// 0x06000159 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Segment_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Charact_Segment_ViewModel()
// {
// 	grdSegment_GridData_Property = CxvPropertyDeclaration.Register("grdSegment_GridData", typeof(MMPolymers_Charact_Segment_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSegment_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.SEG_TYPE",
// 			UseChildId = true,
// 			Name = "Segment"
// 		}
// 	});
// }

// 0x06000162 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Distrib_ViewModel..ctor
// public MMPolymers_Distrib_ViewModel()
// {
// }

// 0x06000163 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Distrib_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Distrib_ViewModel()
// {
// 	CCDistr_Property = CxvPropertyDeclaration.Register("CCDistr", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DISTRI",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EXPOL"
// 		}
// 	});
// 	EXPOL_Property = CxvPropertyDeclaration.Register("EXPOL", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EXPOL"
// 	});
// 	POLYDIS_Property = CxvPropertyDeclaration.Register("POLYDIS", typeof(MMPolymers_Distrib_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYDIS"
// 	});
// 	ENTDis_Property = CxvPropertyDeclaration.Register("ENTDis", typeof(MMPolymers_Distrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTDIS",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EXPOL"
// 		}
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPolymers_Distrib_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCDistr" },
// 		AccessibleDataPaths = { "@EXPOL" },
// 		EnteredDataPaths = { "@ENTDis" }
// 	});
// }

// 0x0600016d AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Distrib_Distrib_ViewModel..ctor
// public MMPolymers_Distrib_Distrib_ViewModel()
// {
// }

// 0x0600016e AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Distrib_Distrib_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPolymers_Distrib_Distrib_ViewModel()
// {
// 	chkGPC_var1_Property = CxvPropertyDeclaration.Register("chkGPC_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.FUNCLOG.@POLYDIS",
// 		TrueValue = "YES",
// 		FalseValue = "NO"
// 	});
// 	lbtuNpoints_var1_Property = CxvPropertyDeclaration.Register("lbtuNpoints_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NPOINTS.@POLYDIS"
// 	});
// 	lbtuUpper_var1_Property = CxvPropertyDeclaration.Register("lbtuUpper_var1", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@POLYDIS"
// 	});
// 	mnuPolymer_Save_Property = CxvPropertyDeclaration.Register("mnuPolymer_Save", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "POLYDIS"
// 	});
// 	mnuPolymer_List_Property = CxvPropertyDeclaration.Register("mnuPolymer_List", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.DISTTYPE",
// 		SelectedItemBinding = "mnuPolymer_Save.Value",
// 		CompletePaths = { "DISTRI" },
// 		EnteredPaths = { "ENTDIS" }
// 	});
// 	GPEnabled_Property = CxvPropertyDeclaration.Register("GPEnabled", typeof(MMPolymers_Distrib_Distrib_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.DISTTYPE",
// 		DataAttribute = "has_children",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = "1"
// 	});
// }

// 0x0600017a AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_ViewModel..ctor
// public MMADAset_Analys_ViewModel()
// {
// }

// 0x0600017b AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMADAset_Analys_ViewModel()
// {
// 	PPROP_Property = CxvPropertyDeclaration.Register("PPROP", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Blend Options.CC Nodes.PPROP"
// 	});
// 	ADA_Property = CxvPropertyDeclaration.Register("ADA", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.CC Nodes.ADA"
// 	});
// 	ADAOPT_Property = CxvPropertyDeclaration.Register("ADAOPT", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.CC Nodes.ADAOPT"
// 	});
// 	PPROPOPT_Property = CxvPropertyDeclaration.Register("PPROPOPT", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Blend Options.CC Nodes.PPROPOPT"
// 	});
// 	ADAADV_Property = CxvPropertyDeclaration.Register("ADAADV", typeof(MMADAset_Analys_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.CC Nodes.ADAADV"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@ADA" },
// 		EnteredDataPaths = { "@ADAOPT" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PPROP" },
// 		EnteredDataPaths = { "@PPROPOPT" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMADAset_Analys_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@ADAADV" }
// 	});
// }

// 0x06000182 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Advanc_ViewModel..ctor
// public MMADAset_Analys_Advanc_ViewModel()
// {
// }

// 0x06000183 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Advanc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMADAset_Analys_Advanc_ViewModel()
// {
// 	MMLBUText1_MW_INTGR_H_Property = CxvPropertyDeclaration.Register("MMLBUText1_MW_INTGR_H", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.Input.MW_INTGR_H"
// 	});
// 	MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Assay Procedures.Input.SPLINE_FIT",
// 		DisplayedCase = CxsDisplayedCase.Lowercase
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMADAset_Analys_Advanc_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_TBP_GEN",
// 				DataPath = "@main.Assay Procedures.Input.TBP_GEN"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen Plus",
// 				DisplayResourceKey = "MMADAset_Analys_Advanc_ViewModel__CxvMultiMapOption_Display_Aspen_Plus",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_TBP_GEN",
// 						Value = "ASPEN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RefSYS",
// 				DisplayResourceKey = "MMADAset_Analys_Advanc_ViewModel__CxvMultiMapOption_Display_RefSYS",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_TBP_GEN",
// 						Value = "REFSYS"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000190 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Assay_ViewModel..ctor
// public MMADAset_Analys_Assay_ViewModel()
// {
// }

// 0x06000191 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Assay_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMADAset_Analys_Assay_ViewModel()
// {
// 	fraDistil_state_Property = CxvPropertyDeclaration.Register("fraDistil_state", typeof(MMADAset_Analys_Assay_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Assay Procedures.CC Nodes.PROCA"
// 		}
// 	});
// 	MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox4_d1160_meth",
// 				DataPath = "@main.Assay Procedures.Input.D1160_METH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "API63",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API63",
// 				Value = "MMComboBox4_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_d1160_meth",
// 						Value = "API63"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PML",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_PML",
// 				Value = "MMComboBox4_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_d1160_meth",
// 						Value = "PML"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_D86_METH",
// 				DataPath = "@main.Assay Procedures.Input.D86_METH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "API87",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API87",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "API87"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API92",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API92",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "API92"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API94",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API94",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "API94"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Edmister",
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "EDMISTER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister-Okamato",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Edmister_Okamato",
// 				Value = "MMComboBox2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "ED-OK"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PML",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_PML_1",
// 				Value = "MMComboBox2_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_D86_METH",
// 						Value = "PML"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox3_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox3_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox3_d2887_meth",
// 				DataPath = "@main.Assay Procedures.Input.D2887_METH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "API87",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API87_1",
// 				Value = "MMComboBox3_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox3_d2887_meth",
// 						Value = "API87"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API94",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_API94_1",
// 				Value = "MMComboBox3_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox3_d2887_meth",
// 						Value = "API94"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "TBPWT",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_TBPWT",
// 				Value = "MMComboBox3_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox3_d2887_meth",
// 						Value = "TBPWT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	fraCurve_state_Property = CxvPropertyDeclaration.Register("fraCurve_state", typeof(MMADAset_Analys_Assay_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.Assay Procedures.CC Nodes.PROCA"
// 		}
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_method",
// 				DataPath = "@main.Assay Procedures.Input.EXTRAP_METH"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Probability",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Probability",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_method",
// 						Value = "PROBABILITY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Quadratic",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Quadratic",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_method",
// 						Value = "QUADRATIC"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText2_ep_Property = CxvPropertyDeclaration.Register("MMLBUText2_ep", typeof(MMADAset_Analys_Assay_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.Input.EP"
// 	});
// 	MMLBUText1_ibp_Property = CxvPropertyDeclaration.Register("MMLBUText1_ibp", typeof(MMADAset_Analys_Assay_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Assay Procedures.Input.IBP"
// 	});
// 	ogrADAprocedure_MultiMap_Property = CxvPropertyDeclaration.Register("ogrADAprocedure_MultiMap", typeof(MMADAset_Analys_Assay_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrADAprocedure_procedure",
// 				DataPath = "@main.Assay Procedures.Input.PROCEDURE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Current version",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Version_9_or_later",
// 				Value = "ogrADAprocedure_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrADAprocedure_procedure",
// 						Value = "REL9"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Legacy version",
// 				DisplayResourceKey = "MMADAset_Analys_Assay_ViewModel__CxvMultiMapOption_Display_Version_8_or_earlier",
// 				Value = "ogrADAprocedure_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrADAprocedure_procedure",
// 						Value = "PRE-REL9"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000196 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Blend_ViewModel..ctor
// public MMADAset_Analys_Blend_ViewModel()
// {
// }

// 0x06000197 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Blend_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMADAset_Analys_Blend_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMADAset_Analys_Blend_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Blend Options.Input.PROP_NAME",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060001a4 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_ViewModel..ctor
// public MMPCCalc_Gen_ViewModel()
// {
// }

// 0x060001a5 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Gen_ViewModel()
// {
// 	PCMAIN_Property = CxvPropertyDeclaration.Register("PCMAIN", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	CUTS_Property = CxvPropertyDeclaration.Register("CUTS", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CUTS"
// 	});
// 	NAMING_Property = CxvPropertyDeclaration.Register("NAMING", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.NAMING"
// 	});
// 	CUTOPT_Property = CxvPropertyDeclaration.Register("CUTOPT", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CUTOPT"
// 	});
// 	NAMEOPT_Property = CxvPropertyDeclaration.Register("NAMEOPT", typeof(MMPCCalc_Gen_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.NAMEOPT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PCMAIN" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CUTS" },
// 		EnteredDataPaths = { "@CUTOPT" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCCalc_Gen_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@NAMING" },
// 		EnteredDataPaths = { "@NAMEOPT" }
// 	});
// }

// 0x060001b4 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel..ctor
// public MMPCCalc_Gen_Cuts_ViewModel()
// {
// }

// 0x060001b5 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Gen_Cuts_ViewModel()
// {
// 	fraRANGE_state_Property = CxvPropertyDeclaration.Register("fraRANGE_state", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GENOPTB"
// 		}
// 	});
// 	grdRANGE_GridData_Property = CxvPropertyDeclaration.Register("grdRANGE_GridData", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdRANGE_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.UTEMP",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	fraLIST_state_Property = CxvPropertyDeclaration.Register("fraLIST_state", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GENOPTA"
// 		}
// 	});
// 	lbtuCutTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuCutTemp_var1", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIST"
// 	});
// 	grdLIST_GridData_Property = CxvPropertyDeclaration.Register("grdLIST_GridData", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLIST_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.LIST",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	MMComboBox1_PC_GEN_OPT_Property = CxvPropertyDeclaration.Register("MMComboBox1_PC_GEN_OPT", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrPCGenOpt",
// 				DataPath = "@main.Input.PC_GEN_OPT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "In-Range",
// 				DisplayResourceKey = "PCGenOpt_In_Range",
// 				Value = "ogrPCGenOpt_Range",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrPCGenOpt",
// 						Value = "IN-RANGE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "All",
// 				DisplayResourceKey = "PCGenOpt_All",
// 				Value = "ogrPCGenOpt_All",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrPCGenOpt",
// 						Value = "ALL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_OPT_CUTS",
// 				DataPath = "@main.Input.OPT_CUTS"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "List of cuts",
// 				DisplayResourceKey = "MMPCCalc_Gen_Cuts_ViewModel__CxvMultiMapOption_Display_List_of_cuts",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_OPT_CUTS",
// 						Value = "LIST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Range and increments",
// 				DisplayResourceKey = "MMPCCalc_Gen_Cuts_ViewModel__CxvMultiMapOption_Display_Range_and_increments",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_OPT_CUTS",
// 						Value = "RANGE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuTEMP_1_LTEMP_Units_Property = CxvPropertyDeclaration.Register("lbtuTEMP_1_LTEMP_Units", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UTEMP",
// 		ExtraDataPaths = { "@main.Input.LTEMP", "@main.Input.INCR" }
// 	});
// 	lbtuTEMP_1_LTEMP_Value_Property = CxvPropertyDeclaration.Register("lbtuTEMP_1_LTEMP_Value", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LTEMP"
// 	});
// 	lbtuTemp_1_UTEMP_Units_Property = CxvPropertyDeclaration.Register("lbtuTemp_1_UTEMP_Units", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UTEMP"
// 	});
// 	lbtuIncrement_INCR_Property = CxvPropertyDeclaration.Register("lbtuIncrement_INCR", typeof(MMPCCalc_Gen_Cuts_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INCR"
// 	});
// }

// 0x060001ca AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel..ctor
// using System.Collections.ObjectModel;
//
// public MMPCCalc_Gen_Naming_ViewModel()
// {
// 	_PreviewSource = new ObservableCollection<PreviewTemplate>();
// 	base..ctor();
// }

// 0x060001cb AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Gen_Naming_ViewModel()
// {
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.PCNAME",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GENPCNM"
// 		}
// 	});
// 	optOption2_MultiMap_Property = CxvPropertyDeclaration.Register("optOption2_MultiMap", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "optOption2_option",
// 				DataPath = "@main.Input.OPTION"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Estimated boiling point",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Estimated_boiling_point",
// 				Value = "optOption2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption2_option",
// 						Value = "NBP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Lower cut temperature",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Lower_cut_temperature",
// 				Value = "optOption2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption2_option",
// 						Value = "ROUND-DOWN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Upper cut temperature",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Upper_cut_temperature",
// 				Value = "optOption2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption2_option",
// 						Value = "ROUND-UP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Numbers starting from:",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Numbers_starting_from_",
// 				Value = "optOption2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption2_option",
// 						Value = "NUMBERED"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User defined list",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_User_defined_list",
// 				Value = "optOption2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption2_option",
// 						Value = "LIST"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PCYES"
// 		}
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PC_LIST",
// 			UseChildId = true,
// 			Name = "x"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.OPTIONF"
// 		}
// 	});
// 	MMTextBox1_First_No_Property = CxvPropertyDeclaration.Register("MMTextBox1_First_No", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FIRST_NO",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.OPTIONE"
// 		}
// 	});
// 	optOption1_MultiMap_Property = CxvPropertyDeclaration.Register("optOption1_MultiMap", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "optOption1_option",
// 				DataPath = "@main.Input.OPTION"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Calculated boiling point",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Calculated_boiling_point",
// 				Value = "optOption1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption1_option",
// 						Value = "NBP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Lower cut temperature",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Lower_cut_temperature_1",
// 				Value = "optOption1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption1_option",
// 						Value = "ROUND-DOWN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Upper cut temperature",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Upper_cut_temperature_1",
// 				Value = "optOption1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption1_option",
// 						Value = "ROUND-UP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Numbers starting from:",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_Numbers_starting_from__1",
// 				Value = "optOption1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption1_option",
// 						Value = "NUMBERED"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User defined list",
// 				DisplayResourceKey = "MMPCCalc_Gen_Naming_ViewModel__CxvMultiMapOption_Display_User_defined_list_1",
// 				Value = "optOption1_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "optOption1_option",
// 						Value = "LIST"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PCNO"
// 		}
// 	});
// 	txtFirstNo_First_No_Property = CxvPropertyDeclaration.Register("txtFirstNo_First_No", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FIRST_NO",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.OPTIONE"
// 		}
// 	});
// 	grdLIST_GridData_Property = CxvPropertyDeclaration.Register("grdLIST_GridData", typeof(MMPCCalc_Gen_Naming_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLIST_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PC_LIST",
// 			UseChildId = true,
// 			Name = "x"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.OPTIONF"
// 		}
// 	});
// }

// 0x060001d1 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Spec_ViewModel..ctor
// public MMPCCalc_Gen_Spec_ViewModel()
// {
// }

// 0x060001d2 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Gen_Spec_ViewModel()
// {
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMPCCalc_Gen_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.PCOPSETNAME"
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Gen_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.WF",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060001dd AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_ViewModel..ctor
// public MMPCCalc_Result_ViewModel()
// {
// }

// 0x060001de AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Result_ViewModel()
// {
// 	kvisc_Property = CxvPropertyDeclaration.Register("kvisc", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.KVISC"
// 	});
// 	visc_Property = CxvPropertyDeclaration.Register("visc", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.VISC"
// 	});
// 	PPPROP_Property = CxvPropertyDeclaration.Register("PPPROP", typeof(MMPCCalc_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.Prop Data.PPPROP"
// 	});
// 	visctype_Property = CxvPropertyDeclaration.Register("visctype", typeof(MMPCCalc_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "visctype"
// 	});
// 	my_visc_Property = CxvPropertyDeclaration.Register("my_visc", typeof(MMPCCalc_Result_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "my_visc"
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCCalc_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@PPPROP" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCCalc_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@kvisc", "@visc" }
// 	});
// }

// 0x060001e4 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel..ctor
// public MMPCCalc_Result_Petrop_ViewModel()
// {
// }

// 0x060001e5 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Result_Petrop_ViewModel()
// {
// 	TRAYoutp_Property = CxvPropertyDeclaration.Register("TRAYoutp", typeof(MMPCCalc_Result_Petrop_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.Prop Data.PPPROP"
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Result_Petrop_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@TRAYoutp.#0",
// 			UseChildId = true,
// 			Name = "z"
// 		}
// 	});
// }

// 0x060001ed AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Summary_ViewModel..ctor
// public MMPCCalc_Result_Summary_ViewModel()
// {
// }

// 0x060001ee AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Summary_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Result_Summary_ViewModel()
// {
// 	MMLBUText3_PC_Units_Property = CxvPropertyDeclaration.Register("MMLBUText3_PC_Units", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.PCMX"
// 	});
// 	MMLBUText2_TCUnits_Property = CxvPropertyDeclaration.Register("MMLBUText2_TCUnits", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.TCMX"
// 	});
// 	MMLBUText1_NBPUnits_Property = CxvPropertyDeclaration.Register("MMLBUText1_NBPUnits", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.VAL1"
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMPCCalc_Result_Summary_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Results.Output.COMP_NAMES",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000203 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel..ctor
// using AspenTech.AspenPlus.Localization.Properties;
//
// public MMPCCalc_Result_Viscos_ViewModel()
// {
// 	_viscosityCaption = string.Format(Resources.MMPCCalc_Result_Viscos_ViewModel__ViscosityCaption, string.Empty);
// 	base..ctor();
// }

// 0x06000204 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCCalc_Result_Viscos_ViewModel()
// {
// 	Advcbo_var1_Property = CxvPropertyDeclaration.Register("Advcbo_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "visctype"
// 	});
// 	lbtuViscUnit_var1_Property = CxvPropertyDeclaration.Register("lbtuViscUnit_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.VISC"
// 	});
// 	dec_xsp_Property = CxvPropertyDeclaration.Register("dec_xsp", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.@my_visc"
// 	});
// 	grdMyVisc_GridData_Property = CxvPropertyDeclaration.Register("grdMyVisc_GridData", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMyVisc_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@dec_xsp",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	lbtuKViscUnit_var1_Property = CxvPropertyDeclaration.Register("lbtuKViscUnit_var1", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.KVISC"
// 	});
// 	Advcbo_AdvCollection_Property = CxvPropertyDeclaration.Register("Advcbo_AdvCollection", typeof(MMPCCalc_Result_Viscos_ViewModel), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Operator = CxvLogicalOperator.And,
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Results.Output.VISC",
// 						Operator = CxvLogicalOperator.GreaterThan,
// 						DataAttribute = "child_count",
// 						Value = 0
// 					},
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Results.Output.KVISC",
// 						Operator = CxvLogicalOperator.GreaterThan,
// 						DataAttribute = "child_count",
// 						Value = 0
// 					}
// 				},
// 				Property = new CxvAdvCollectionProperty
// 				{
// 					UseItemsCollection = true,
// 					Items = 
// 					{
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "Absolute viscosity",
// 							DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Absolute_viscosity"
// 						},
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "Kinematic viscosity",
// 							DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
// 						}
// 					},
// 					SelectedItemBinding = "Advcbo_var1.Value",
// 					CreateNewPrompt = "Type:",
// 					CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
// 					IsCalculated = true
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Results.Output.KVISC",
// 						Operator = CxvLogicalOperator.GreaterThan,
// 						DataAttribute = "child_count",
// 						Value = 0
// 					}
// 				},
// 				Property = new CxvAdvCollectionProperty
// 				{
// 					UseItemsCollection = true,
// 					Items = 
// 					{
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "Kinematic viscosity",
// 							DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Kinematic_viscosity"
// 						}
// 					},
// 					SelectedItemBinding = "Advcbo_var1.Value",
// 					CreateNewPrompt = "Type:",
// 					CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
// 					IsCalculated = true
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				IsDefaultChoice = true,
// 				Property = new CxvAdvCollectionProperty
// 				{
// 					UseItemsCollection = true,
// 					Items = 
// 					{
// 						new CxvAdvCollectionItem
// 						{
// 							Display = "Absolute viscosity",
// 							DisplayResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionItem_Display_Absolute_viscosity"
// 						}
// 					},
// 					SelectedItemBinding = "Advcbo_var1.Value",
// 					CreateNewPrompt = "Type:",
// 					CreateNewPromptResourceKey = "MMPCCalc_Result_Viscos_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Type_",
// 					IsCalculated = true
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000210 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_ViewModel..ctor
// public MMPCProp_Spec_ViewModel()
// {
// }

// 0x06000211 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCProp_Spec_ViewModel()
// {
// 	PCMAIN_Property = CxvPropertyDeclaration.Register("PCMAIN", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	MAINOPT_Property = CxvPropertyDeclaration.Register("MAINOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAINOPT"
// 	});
// 	EOSOPT_Property = CxvPropertyDeclaration.Register("EOSOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOSOPT"
// 	});
// 	HEATOPT_Property = CxvPropertyDeclaration.Register("HEATOPT", typeof(MMPCProp_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.HEATOPT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PCMAIN" },
// 		EnteredDataPaths = { "@MAINOPT" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@HEATOPT" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMPCProp_Spec_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@EOSOPT" }
// 	});
// }

// 0x06000219 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_EOS_ViewModel..ctor
// public MMPCProp_Spec_EOS_ViewModel()
// {
// }

// 0x0600021a AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_EOS_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCProp_Spec_EOS_ViewModel()
// {
// 	cboVCBWR_MultiMap_Property = CxvPropertyDeclaration.Register("cboVCBWR_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboVCBWR_VCBWR",
// 				DataPath = "@main.Input.VCBWR"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
// 				Value = "cboVCBWR_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVCBWR_VCBWR",
// 						Value = "VCSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCBWRU",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU",
// 				Value = "cboVCBWR_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVCBWR_VCBWR",
// 						Value = "VCBWRUSR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboTCBWR_MultiMap_Property = CxvPropertyDeclaration.Register("cboTCBWR_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboTCBWR_TCBWR",
// 				DataPath = "@main.Input.TCBWR"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al__1",
// 				Value = "cboTCBWR_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTCBWR_TCBWR",
// 						Value = "TCSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCBWRU",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU_1",
// 				Value = "cboTCBWR_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboTCBWR_TCBWR",
// 						Value = "TCBWRUSR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboBWRGMA_MultiMap_Property = CxvPropertyDeclaration.Register("cboBWRGMA_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboBWRGMA_BWRGMA",
// 				DataPath = "@main.Input.BWRGMA"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_Brule_et_al__2",
// 				Value = "cboBWRGMA_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboBWRGMA_BWRGMA",
// 						Value = "GMASTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCBWRU",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCBWRU_2",
// 				Value = "cboBWRGMA_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboBWRGMA_BWRGMA",
// 						Value = "GMAUSR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboRKSKIJ_MultiMap_Property = CxvPropertyDeclaration.Register("cboRKSKIJ_MultiMap", typeof(MMPCProp_Spec_EOS_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboRKSKIJ_RKSKIJ",
// 				DataPath = "@main.Input.RKSKIJ"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "API, 3rd Ed.",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_API__3rd_Ed_",
// 				Value = "cboRKSKIJ_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRKSKIJ_RKSKIJ",
// 						Value = "API78"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API, 5th Ed.",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_API__5th_Ed_",
// 				Value = "cboRKSKIJ_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRKSKIJ_RKSKIJ",
// 						Value = "API87"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCRKIU",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCRKIU",
// 				Value = "cboRKSKIJ_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRKSKIJ_RKSKIJ",
// 						Value = "KIJUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCRKIU2",
// 				DisplayResourceKey = "MMPCProp_Spec_EOS_ViewModel__CxvMultiMapOption_Display_User_routine_PCRKIU2",
// 				Value = "cboRKSKIJ_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRKSKIJ_RKSKIJ",
// 						Value = "KIJUSR2"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000224 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_Heat_ViewModel..ctor
// public MMPCProp_Spec_Heat_ViewModel()
// {
// }

// 0x06000225 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_Heat_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCProp_Spec_Heat_ViewModel()
// {
// 	cboCPIG_MultiMap_Property = CxvPropertyDeclaration.Register("cboCPIG_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboCPIG_CPIG",
// 				DataPath = "@main.Input.CPIG"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee",
// 				Value = "cboCPIG_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Tsang-Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen",
// 				Value = "cboCPIG_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
// 				Value = "cboCPIG_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cavett",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Cavett",
// 				Value = "cboCPIG_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGCAVT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mathias and Monks",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Mathias_and_Monks",
// 				Value = "cboCPIG_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPMM"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCCPGU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCCPGU",
// 				Value = "cboCPIG_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API Hybrid",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API_Hybrid",
// 				Value = "cboCPIG_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGAPI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Simplified-Lee-Kesler",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Simplified_Lee_Kesler",
// 				Value = "cboCPIG_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGSKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Cavett",
// 				Value = "cboCPIG_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCPIG_CPIG",
// 						Value = "CPIGHYS"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboDHVL_MultiMap_Property = CxvPropertyDeclaration.Register("cboDHVL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDHVL_DHVL",
// 				DataPath = "@main.Input.DHVL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vetere",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Vetere",
// 				Value = "cboDHVL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHVL_DHVL",
// 						Value = "DHVLVET"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCDHVU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDHVU",
// 				Value = "cboDHVL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHVL_DHVL",
// 						Value = "DHVLUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kistiakowsky",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Kistiakowsky",
// 				Value = "cboDHVL_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHVL_DHVL",
// 						Value = "DHVLKIST"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboDHFORM_MultiMap_Property = CxvPropertyDeclaration.Register("cboDHFORM_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDHFORM_DHFORM",
// 				DataPath = "@main.Input.DHFORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Defaults to zero",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Defaults_to_zero",
// 				Value = "cboDHFORM_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMZERO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister",
// 				Value = "cboDHFORM_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMONT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCDHFU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDHFU",
// 				Value = "cboDHFORM_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister-API",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API",
// 				Value = "cboDHFORM_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMAPI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister-API97",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API97",
// 				Value = "cboDHFORM_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMONT2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Default",
// 				Value = "cboDHFORM_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMHYS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation",
// 				Value = "cboDHFORM_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDHFORM_DHFORM",
// 						Value = "DHFMEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboDGFORM_MultiMap_Property = CxvPropertyDeclaration.Register("cboDGFORM_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDGFORM_DGFORM",
// 				DataPath = "@main.Input.DGFORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Defaults to zero",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Defaults_to_zero_1",
// 				Value = "cboDGFORM_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDGFORM_DGFORM",
// 						Value = "DGFMZERO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCDGFU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCDGFU",
// 				Value = "cboDGFORM_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDGFORM_DGFORM",
// 						Value = "DGFMUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_1",
// 				Value = "cboDGFORM_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDGFORM_DGFORM",
// 						Value = "DGFMONT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister-API97",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Edmister_API97_1",
// 				Value = "cboDGFORM_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDGFORM_DGFORM",
// 						Value = "DGFMONT2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_1",
// 				Value = "cboDGFORM_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDGFORM_DGFORM",
// 						Value = "DGFMEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboWATSOL_MultiMap_Property = CxvPropertyDeclaration.Register("cboWATSOL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboWATSOL_WATSOL",
// 				DataPath = "@main.Input.WATSOL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen model",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_model",
// 				Value = "cboWATSOL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboWATSOL_WATSOL",
// 						Value = "WSOLASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API, Kerosene line",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API__Kerosene_line",
// 				Value = "cboWATSOL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboWATSOL_WATSOL",
// 						Value = "KEROSENE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCWSLU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCWSLU",
// 				Value = "cboWATSOL_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboWATSOL_WATSOL",
// 						Value = "WSOLUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API,  procedure 9A1.5",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_API___procedure_9A1_5",
// 				Value = "cboWATSOL_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboWATSOL_WATSOL",
// 						Value = "WSOLAPI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCWSLU2",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCWSLU2",
// 				Value = "cboWATSOL_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboWATSOL_WATSOL",
// 						Value = "WSOLUSR2"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboHCSOL_MultiMap_Property = CxvPropertyDeclaration.Register("cboHCSOL_MultiMap", typeof(MMPCProp_Spec_Heat_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboHCSOL_HCSOL",
// 				DataPath = "@main.Input.HCSOL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen model",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_Aspen_model_1",
// 				Value = "cboHCSOL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboHCSOL_HCSOL",
// 						Value = "HSOLASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCHSLU",
// 				DisplayResourceKey = "MMPCProp_Spec_Heat_ViewModel__CxvMultiMapOption_Display_User_routine_PCHSLU",
// 				Value = "cboHCSOL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboHCSOL_HCSOL",
// 						Value = "HSOLUSR"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000232 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_Spec_ViewModel..ctor
// public MMPCProp_Spec_Spec_ViewModel()
// {
// }

// 0x06000233 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCProp_Spec_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMPCProp_Spec_Spec_ViewModel()
// {
// 	cboMUL_MultiMap_Property = CxvPropertyDeclaration.Register("cboMUL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboMUL_MUL",
// 				DataPath = "@main.Input.MUL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Watson",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Watson",
// 				Value = "cboMUL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMUL_MUL",
// 						Value = "MULWAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCMULU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMULU",
// 				Value = "cboMUL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMUL_MUL",
// 						Value = "MULUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCMULU2",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMULU2",
// 				Value = "cboMUL_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMUL_MUL",
// 						Value = "MULUSR2"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboVL_MultiMap_Property = CxvPropertyDeclaration.Register("cboVL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboVL_VL",
// 				DataPath = "@main.Input.VL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Rackett",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Rackett",
// 				Value = "cboVL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVL_VL",
// 						Value = "VLRKT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cavett",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett",
// 				Value = "cboVL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVL_VL",
// 						Value = "VLCAVT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCVOLU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCVOLU",
// 				Value = "cboVL_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVL_VL",
// 						Value = "VLUSR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboPL_MultiMap_Property = CxvPropertyDeclaration.Register("cboPL_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPL_PL",
// 				DataPath = "@main.Input.PL"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Maxwell-Bonnell",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell",
// 				Value = "cboPL_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLMB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Tsang-SWAP",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_SWAP",
// 				Value = "cboPL_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLSWAP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee",
// 				Value = "cboPL_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCPLU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCPLU",
// 				Value = "cboPL_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "BK-10 model",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_BK_10_model",
// 				Value = "cboPL_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "BK-10"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee (For compatibility)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee__For_compatibility_",
// 				Value = "cboPL_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLKLMOD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Maxwell-Bonnell (For compatibility 1)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell__For_compatibility_1_",
// 				Value = "cboPL_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLPSMOD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Maxwell-Bonnell (For compatibility 2)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Maxwell_Bonnell__For_compatibility_2_",
// 				Value = "cboPL_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPL_PL",
// 						Value = "PLMBMOD"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboOMEGA_MultiMap_Property = CxvPropertyDeclaration.Register("cboOMEGA_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboOMEGA_OMEGA",
// 				DataPath = "@main.Input.OMEGA"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Defining relation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Defining_relation",
// 				Value = "cboOMEGA_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMEGADEF"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_1",
// 				Value = "cboOMEGA_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMEGAKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCOMGU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCOMGU",
// 				Value = "cboOMEGA_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMEGAUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Robinson-Peng",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng",
// 				Value = "cboOMEGA_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMEGAPR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Lee and Kesler, Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Lee_and_Kesler__Aspen",
// 				Value = "cboOMEGA_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "KL-ASPEN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Edmister",
// 				Value = "cboOMEGA_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMGEDMIS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Lee-Kesler",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Lee_Kesler",
// 				Value = "cboOMEGA_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMGEXTLK"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Twu generalized",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_generalized",
// 				Value = "cboOMEGA_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMGTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen extended Twu generalized",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_extended_Twu_generalized",
// 				Value = "cboOMEGA_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMGXTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS extended Twu generalized",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_extended_Twu_generalized",
// 				Value = "cboOMEGA_MultiMapOption_10",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMHYSTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation",
// 				Value = "cboOMEGA_MultiMapOption_11",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboOMEGA_OMEGA",
// 						Value = "OMGEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox1_BASE_Property = CxvPropertyDeclaration.Register("MMComboBox1_BASE", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.BASE"
// 	});
// 	cboCT_MultiMap_Property = CxvPropertyDeclaration.Register("cboCT_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboCT_TC",
// 				DataPath = "@main.Input.TC"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1980)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980__1",
// 				Value = "cboCT_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCRZI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Tsang-Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen_1",
// 				Value = "cboCT_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al__1",
// 				Value = "cboCT_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cavett",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett_2",
// 				Value = "cboCT_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCCAVT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_3",
// 				Value = "cboCT_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCTCU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCTCU",
// 				Value = "cboCT_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1986)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986__1",
// 				Value = "cboCT_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCRZAPI5"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_2",
// 				Value = "cboCT_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Robinson-Peng",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng_2",
// 				Value = "cboCT_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCPR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "WINN correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation_1",
// 				Value = "cboCT_MultiMapOption_10",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCWINN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Twu 1",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu_1",
// 				Value = "cboCT_MultiMapOption_11",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCXTWU1"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Twu 2",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu_2",
// 				Value = "cboCT_MultiMapOption_12",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCXTWU2"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Cavett",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Cavett",
// 				Value = "cboCT_MultiMapOption_13",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCEXTCAV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu",
// 				Value = "cboCT_MultiMapOption_14",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCHYSTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_1",
// 				Value = "cboCT_MultiMapOption_15",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboCT_TC",
// 						Value = "TCEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboMW_MultiMap_Property = CxvPropertyDeclaration.Register("cboMW_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboMW_MW",
// 				DataPath = "@main.Input.MW"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1980)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980__2",
// 				Value = "cboMW_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWRZI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Tsang-Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen_2",
// 				Value = "cboMW_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al__2",
// 				Value = "cboMW_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_4",
// 				Value = "cboMW_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Hariu and Sage",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Hariu_and_Sage",
// 				Value = "cboMW_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWHS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCMWU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCMWU",
// 				Value = "cboMW_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1986)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986__2",
// 				Value = "cboMW_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWRZAPI5"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1986), heavy petro.",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986___heavy_petro_",
// 				Value = "cboMW_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWRZH"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Harui and Sage-Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Harui_and_Sage_Aspen",
// 				Value = "cboMW_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "HS-Aspen"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "WINN correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation_2",
// 				Value = "cboMW_MultiMapOption_10",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWWINN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
// 				Value = "cboMW_MultiMapOption_11",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWEXTTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended API (Riazi, 1980)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_API__Riazi__1980_",
// 				Value = "cboMW_MultiMapOption_12",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWEXTAPI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_1",
// 				Value = "cboMW_MultiMapOption_13",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWHYSTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_2",
// 				Value = "cboMW_MultiMapOption_14",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboMW_MW",
// 						Value = "MWEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboVC_MultiMap_Property = CxvPropertyDeclaration.Register("cboVC_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboVC_VC",
// 				DataPath = "@main.Input.VC"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riedel",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riedel",
// 				Value = "cboVC_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCRDL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Brule et al.",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Brule_et_al_",
// 				Value = "cboVC_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCSTAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCVCU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCVCU",
// 				Value = "cboVC_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu",
// 				Value = "cboVC_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Edmister",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Edmister_1",
// 				Value = "cboVC_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCEDMIS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Lee-Kesler",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Lee_Kesler",
// 				Value = "cboVC_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
// 				Value = "cboVC_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCEXTTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_2",
// 				Value = "cboVC_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCHYSTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_3",
// 				Value = "cboVC_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboVC_VC",
// 						Value = "VCEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboPC_MultiMap_Property = CxvPropertyDeclaration.Register("cboPC_MultiMap", typeof(MMPCProp_Spec_Spec_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPC_PC",
// 				DataPath = "@main.Input.PC"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1980)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1980_",
// 				Value = "cboPC_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCRZI"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Tsang-Aspen",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Tsang_Aspen",
// 				Value = "cboPC_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCASPN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Cavett",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Cavett_1",
// 				Value = "cboPC_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCCAVT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kesler and Lee",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Kesler_and_Lee_2",
// 				Value = "cboPC_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCKL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User routine PCPCU",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_User_routine_PCPCU",
// 				Value = "cboPC_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCUSR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Riazi (1986)",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Riazi__1986_",
// 				Value = "cboPC_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCRZAPI5"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Twu_1",
// 				Value = "cboPC_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Robinson-Peng",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Robinson_Peng_1",
// 				Value = "cboPC_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCPR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "WINN correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_WINN_correlation",
// 				Value = "cboPC_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCWINN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Twu",
// 				Value = "cboPC_MultiMapOption_10",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCEXTTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Extended Edmister",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Extended_Edmister",
// 				Value = "cboPC_MultiMapOption_11",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCEXTEDM"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Aspen HYSYS Extended Twu",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_Aspen_HYSYS_Extended_Twu_3",
// 				Value = "cboPC_MultiMapOption_12",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCHYSTWU"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EDL-CHEF correlation",
// 				DisplayResourceKey = "MMPCProp_Spec_Spec_ViewModel__CxvMultiMapOption_Display_EDL_CHEF_correlation_4",
// 				Value = "cboPC_MultiMapOption_13",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPC_PC",
// 						Value = "PCEDL"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x0600023a AspenTech.AspenPlus.MMForms.Components.MoistureComponents.MoistComps_Input_ViewModel..ctor
// public MoistComps_Input_ViewModel()
// {
// }

// 0x0600023b AspenTech.AspenPlus.MMForms.Components.MoistureComponents.MoistComps_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MoistComps_Input_ViewModel()
// {
// 	entsele_Property = CxvPropertyDeclaration.Register("entsele", typeof(MoistComps_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTSELE"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MoistComps_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entsele" }
// 	});
// }

// 0x06000240 AspenTech.AspenPlus.MMForms.Components.MoistureComponents.MoistComps_Input_Select_ViewModel..ctor
// public MoistComps_Input_Select_ViewModel()
// {
// }

// 0x06000241 AspenTech.AspenPlus.MMForms.Components.MoistureComponents.MoistComps_Input_Select_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MoistComps_Input_Select_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MoistComps_Input_Select_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.COMP",
// 		AllowSort = false
// 	});
// }

// 0x06000248 AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_ViewModel..ctor
// public MMHenryComps_Input_ViewModel()
// {
// }

// 0x06000249 AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHenryComps_Input_ViewModel()
// {
// 	hc_Property = CxvPropertyDeclaration.Register("hc", typeof(MMHenryComps_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMHenryComps_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@hc" }
// 	});
// }

// 0x0600024e AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_HenryC_ViewModel..ctor
// public MMHenryComps_Input_HenryC_ViewModel()
// {
// }

// 0x0600024f AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_HenryC_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHenryComps_Input_HenryC_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMHenryComps_Input_HenryC_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.CID",
// 		AllowSort = false
// 	});
// }

// 0x06000256 AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_RewHen_ViewModel..ctor
// public MMHenryComps_Input_RewHen_ViewModel()
// {
// }

// 0x06000257 AspenTech.AspenPlus.MMForms.Components.HenryComponents.MMHenryComps_Input_RewHen_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMHenryComps_Input_RewHen_ViewModel()
// {
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMHenryComps_Input_RewHen_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.CID",
// 		AllowSort = false
// 	});
// }

// 0x0600025f AspenTech.AspenPlus.MMForms.Components.Comp_Lists.MMComplst_Input_ViewModel..ctor
// public MMComplst_Input_ViewModel()
// {
// }

// 0x06000260 AspenTech.AspenPlus.MMForms.Components.Comp_Lists.MMComplst_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComplst_Input_ViewModel()
// {
// 	OVERALL_Property = CxvPropertyDeclaration.Register("OVERALL", typeof(MMComplst_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.OVERALL"
// 	});
// 	ENTCID_Property = CxvPropertyDeclaration.Register("ENTCID", typeof(MMComplst_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTCID"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMComplst_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@OVERALL" },
// 		EnteredDataPaths = { "@ENTCID" }
// 	});
// }

// 0x06000268 AspenTech.AspenPlus.MMForms.Components.Comp_Lists.MMComplst_Input_Selection_ViewModel..ctor
// public MMComplst_Input_Selection_ViewModel()
// {
// }

// 0x06000269 AspenTech.AspenPlus.MMForms.Components.Comp_Lists.MMComplst_Input_Selection_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMComplst_Input_Selection_ViewModel()
// {
// 	MMLabel_state_Property = CxvPropertyDeclaration.Register("MMLabel_state", typeof(MMComplst_Input_Selection_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CMPLST"
// 		}
// 	});
// 	MMGroupBox_state_Property = CxvPropertyDeclaration.Register("MMGroupBox_state", typeof(MMComplst_Input_Selection_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GCMPLST"
// 		}
// 	});
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMComplst_Input_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.CID"
// 	});
// }

// 0x06000274 AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_ViewModel..ctor
// public MMCompgrp_Input_ViewModel()
// {
// }

// 0x06000275 AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompgrp_Input_ViewModel()
// {
// 	choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMCompgrp_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	sele_Property = CxvPropertyDeclaration.Register("sele", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	entlist_Property = CxvPropertyDeclaration.Register("entlist", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTLIST.@choice"
// 	});
// 	entrange_Property = CxvPropertyDeclaration.Register("entrange", typeof(MMCompgrp_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTRANGE.@choice"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompgrp_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@sele" },
// 		EnteredDataPaths = { "@entlist" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMCompgrp_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@sele" },
// 		EnteredDataPaths = { "@entrange" }
// 	});
// }

// 0x0600027d AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Range_ViewModel..ctor
// public MMCompgrp_Input_Range_ViewModel()
// {
// }

// 0x0600027e AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Range_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompgrp_Input_Range_ViewModel()
// {
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMCompgrp_Input_Range_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMCompgrp_Input_Range_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.L1",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMCompgrp_Input_Range_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
// 		CompletePaths = { "MAIN3" },
// 		EnteredPaths = { "ENTRANGE" }
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMCompgrp_Input_Range_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.COMPLI.@choice"
// 		}
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompgrp_Input_Range_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.T2.@choice",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000288 AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Selection_ViewModel..ctor
// public MMCompgrp_Input_Selection_ViewModel()
// {
// }

// 0x06000289 AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Selection_ViewModel..cctor
// using System;
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompgrp_Input_Selection_ViewModel()
// {
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.COMP.@choice",
// 		TrueValue = "NONE",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.L1",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMCompgrp_Input_Selection_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
// 		CompletePaths = { "MAIN4" },
// 		EnteredPaths = { "ENTLIST" }
// 	});
// 	MMListPicker1_state_Property = CxvPropertyDeclaration.Register("MMListPicker1_state", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.COMPLI.@choice"
// 		}
// 	});
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.L1.@choice",
// 		AllowSort = false
// 	});
// 	CheckBox_Enabled_Property = CxvPropertyDeclaration.Register("CheckBox_Enabled", typeof(MMCompgrp_Input_Selection_ViewModel), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Operator = CxvLogicalOperator.And,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "choice",
// 				Operator = CxvLogicalOperator.IsNotNull
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "choice",
// 				Operator = CxvLogicalOperator.NotEqual,
// 				Value = string.Empty
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "choice",
// 				Operator = CxvLogicalOperator.NotEqual,
// 				Value = DBNull.Value
// 			}
// 		}
// 	});
// }

// 0x06000292 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.BioFeedDB..cctor
// using System.Collections.Generic;
//
// static BioFeedDB()
// {
// 	_bioCompounds = new Dictionary<string, Compound>();
// 	_baseCompounds = new Dictionary<string, Compound>();
// }

// 0x0600029f AspenTech.AspenPlus.MMForms.Components.Bio_Comps.Compound..ctor
// public Compound()
// {
// }

// 0x060002a3 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_ViewModel..ctor
// public MMBioComp_Input_ViewModel()
// {
// }

// 0x060002a4 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBioComp_Input_ViewModel()
// {
// 	MASSSUM_Property = CxvPropertyDeclaration.Register("MASSSUM", typeof(MMBioComp_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MASSSUM"
// 	});
// 	ENTBIO_Property = CxvPropertyDeclaration.Register("ENTBIO", typeof(MMBioComp_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBIO"
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBioComp_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@MASSSUM" },
// 		EnteredDataPaths = { "@ENTBIO" }
// 	});
// }

// 0x060002a9 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Biofeed_ViewModel..ctor
// public MMBioComp_Input_Biofeed_ViewModel()
// {
// }

// 0x060002ad AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel..ctor
// public MMBioComp_Input_Spec_ViewModel()
// {
// }

// 0x060002ae AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBioComp_Input_Spec_ViewModel()
// {
// 	grdPhase_GridData_Property = CxvPropertyDeclaration.Register("grdPhase_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPhase_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PHASE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	grdMolar_GridData_Property = CxvPropertyDeclaration.Register("grdMolar_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMolar_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PHASE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	grdMass_GridData_Property = CxvPropertyDeclaration.Register("grdMass_GridData", typeof(MMBioComp_Input_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMass_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PHASE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060002be AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_ViewModel..ctor
// public MMAttrScal_Input_ViewModel()
// {
// }

// 0x060002bf AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAttrScal_Input_ViewModel()
// {
// 	compid_Property = CxvPropertyDeclaration.Register("compid", typeof(MMAttrScal_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "compid"
// 	});
// 	CCMAIN_Property = CxvPropertyDeclaration.Register("CCMAIN", typeof(MMAttrScal_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	ENTSC_Property = CxvPropertyDeclaration.Register("ENTSC", typeof(MMAttrScal_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTSC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAttrScal_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@CCMAIN" },
// 		EnteredDataPaths = { "@ENTSC" }
// 	});
// }

// 0x060002c6 AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_Create_ViewModel..ctor
// public MMAttrScal_Input_Create_ViewModel()
// {
// }

// 0x060002c7 AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_Create_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAttrScal_Input_Create_ViewModel()
// {
// 	MMScrollArea_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea_GridData", typeof(MMAttrScal_Input_Create_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.SCALE.@compid",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	MMAdvCombo2_var2_Property = CxvPropertyDeclaration.Register("MMAdvCombo2_var2", typeof(MMAttrScal_Input_Create_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "compid"
// 	});
// 	MMAdvCombo2_var1_Property = CxvPropertyDeclaration.Register("MMAdvCombo2_var1", typeof(MMAttrScal_Input_Create_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.SCALE",
// 		SelectedItemBinding = "MMAdvCombo2_var2.Value",
// 		CreateNewPrompt = "Component ID",
// 		CreateNewPromptResourceKey = "MMAttrScal_Input_Create_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Component_ID"
// 	});
// }

// 0x060002cf AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_ViewModel..ctor
// public MMCompAttr_Input_ViewModel()
// {
// }

// 0x060002d0 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompAttr_Input_ViewModel()
// {
// 	global_Property = CxvPropertyDeclaration.Register("global", typeof(MMCompAttr_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	entspec_Property = CxvPropertyDeclaration.Register("entspec", typeof(MMCompAttr_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTSPEC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMCompAttr_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@global" },
// 		EnteredDataPaths = { "@entspec" }
// 	});
// }

// 0x060002d5 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel..ctor
// public MMCompAttr_Input_Create_ViewModel()
// {
// }

// 0x060002d6 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMCompAttr_Input_Create_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMCompAttr_Input_Create_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.TYPE_LIST",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060002d8 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.CompAttrChildCountIndexBasis..ctor
// public CompAttrChildCountIndexBasis()
// {
// }

// 0x060002eb AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_ViewModel..ctor
// public MMAssay_BasicD_ViewModel()
// {
// }

// 0x060002ec AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_BasicD_ViewModel()
// {
// 	ASSAYMAIN_Property = CxvPropertyDeclaration.Register("ASSAYMAIN", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	FRAC1_Property = CxvPropertyDeclaration.Register("FRAC1", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FRAC1"
// 	});
// 	MW_Property = CxvPropertyDeclaration.Register("MW", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MW"
// 	});
// 	OPTIONAL_Property = CxvPropertyDeclaration.Register("OPTIONAL", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.OPTIONAL"
// 	});
// 	MWOPT_Property = CxvPropertyDeclaration.Register("MWOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MWOPT"
// 	});
// 	GUOPT_Property = CxvPropertyDeclaration.Register("GUOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GUOPT"
// 	});
// 	LEOPT_Property = CxvPropertyDeclaration.Register("LEOPT", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.LEOPT"
// 	});
// 	GRAVUOPK_Property = CxvPropertyDeclaration.Register("GRAVUOPK", typeof(MMAssay_BasicD_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GRAV_UOPK"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@ASSAYMAIN" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@FRAC1" },
// 		EnteredDataPaths = { "@LEOPT" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@GRAVUOPK" },
// 		EnteredDataPaths = { "@GUOPT" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@MW" },
// 		EnteredDataPaths = { "@MWOPT" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMAssay_BasicD_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@OPTIONAL" }
// 	});
// }

// 0x060002f7 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Distl_ViewModel..ctor
// public MMAssay_BasicD_Distl_ViewModel()
// {
// }

// 0x060002f8 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Distl_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_BasicD_Distl_ViewModel()
// {
// 	cboDCurve_MultiMap_Property = CxvPropertyDeclaration.Register("cboDCurve_MultiMap", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDCurve_DISTTYPE",
// 				DataPath = "@main.Input.DISTTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "ASTM D86",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D86",
// 				Value = "cboDCurve_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "D86"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "ASTM D1160",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D1160",
// 				Value = "cboDCurve_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "D1160"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "True boiling point (liquid volume basis)",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_True_boiling_point__liquid_volume_basis_",
// 				Value = "cboDCurve_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "TBPLV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "True boiling point (weight basis)",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_True_boiling_point__weight_basis_",
// 				Value = "cboDCurve_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "TBPWT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vacuum (liquid volume basis)",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Vacuum__liquid_volume_basis_",
// 				Value = "cboDCurve_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "VACLV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vacuum (weight basis)",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Vacuum__weight_basis_",
// 				Value = "cboDCurve_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "VACWT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "ASTM D2887",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_ASTM_D2887",
// 				Value = "cboDCurve_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDCurve_DISTTYPE",
// 						Value = "D2887"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP"
// 	});
// 	grdDistCurve_GridData_Property = CxvPropertyDeclaration.Register("grdDistCurve_GridData", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdDistCurve_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.TEMP",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	grdBulkGrav_MultiMap_Property = CxvPropertyDeclaration.Register("grdBulkGrav_MultiMap", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "grdBulkGrav_GRAVTYPE",
// 				DataPath = "@main.Input.OPT_GRAVTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Specific gravity",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
// 				Value = "grdBulkGrav_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "grdBulkGrav_GRAVTYPE",
// 						Value = "GRAV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API gravity",
// 				DisplayResourceKey = "MMAssay_BasicD_Distl_ViewModel__CxvMultiMapOption_Display_API_gravity",
// 				Value = "grdBulkGrav_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "grdBulkGrav_GRAVTYPE",
// 						Value = "API"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtAPI_API_Property = CxvPropertyDeclaration.Register("txtAPI_API", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.API",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GTYPEB"
// 		}
// 	});
// 	txtGravVal_GRAV_Property = CxvPropertyDeclaration.Register("txtGravVal_GRAV", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GRAV",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GTYPEA"
// 		}
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMAssay_BasicD_Distl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VACPRES",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VPRESENABLE"
// 		}
// 	});
// }

// 0x06000305 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel..ctor
// public MMAssay_BasicD_Grav_ViewModel()
// {
// }

// 0x06000306 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_BasicD_Grav_ViewModel()
// {
// 	ogrType_MultiMap_Property = CxvPropertyDeclaration.Register("ogrType_MultiMap", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrType_curvetype",
// 				DataPath = "@main.Input.GRAVTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Specific gravity",
// 				DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_Specific_gravity",
// 				Value = "ogrType_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrType_curvetype",
// 						Value = "GRAV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "API gravity",
// 				DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_API_gravity",
// 				Value = "ogrType_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrType_curvetype",
// 						Value = "API"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "UOPK",
// 				DisplayResourceKey = "MMAssay_BasicD_Grav_ViewModel__CxvMultiMapOption_Display_UOPK",
// 				Value = "ogrType_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrType_curvetype",
// 						Value = "UOPK"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	fraAPIGrav_state_Property = CxvPropertyDeclaration.Register("fraAPIGrav_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GRAVTYPEB"
// 		}
// 	});
// 	grdAPI_GridData_Property = CxvPropertyDeclaration.Register("grdAPI_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAPI_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.MID_API",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	fraSpecGrav_state_Property = CxvPropertyDeclaration.Register("fraSpecGrav_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GRAVTYPEA"
// 		}
// 	});
// 	grdSG_GridData_Property = CxvPropertyDeclaration.Register("grdSG_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSG_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.MID_GRAV",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	fraUOPK_state_Property = CxvPropertyDeclaration.Register("fraUOPK_state", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.UOPKENABLE"
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GRAVTYPEC"
// 		}
// 	});
// 	grdUOPK_GridData_Property = CxvPropertyDeclaration.Register("grdUOPK_GridData", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdUOPK_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.MID_UOPK",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	lbtuAPIBulk_API_Property = CxvPropertyDeclaration.Register("lbtuAPIBulk_API", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.API",
// 		IsReadOnly = true
// 	});
// 	lbtuGSBulk_var1_Property = CxvPropertyDeclaration.Register("lbtuGSBulk_var1", typeof(MMAssay_BasicD_Grav_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.GRAV",
// 		IsReadOnly = true
// 	});
// }

// 0x0600030d AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_LEnds_ViewModel..ctor
// public MMAssay_BasicD_LEnds_ViewModel()
// {
// }

// 0x0600030e AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_LEnds_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_BasicD_LEnds_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FRAC"
// 	});
// 	grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLEnds_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	lbtuLEFRAC_LE_FRAC_Property = CxvPropertyDeclaration.Register("lbtuLEFRAC_LE_FRAC", typeof(MMAssay_BasicD_LEnds_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LE_FRAC"
// 	});
// }

// 0x06000314 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_MW_ViewModel..ctor
// public MMAssay_BasicD_MW_ViewModel()
// {
// }

// 0x06000315 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_MW_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_BasicD_MW_ViewModel()
// {
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMAssay_BasicD_MW_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MW"
// 	});
// 	grdMWMW_GridData_Property = CxvPropertyDeclaration.Register("grdMWMW_GridData", typeof(MMAssay_BasicD_MW_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMWMW_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.MW_MW",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x0600031e AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Option_ViewModel..ctor
// public MMAssay_BasicD_Option_ViewModel()
// {
// }

// 0x0600031f AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Option_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMAssay_BasicD_Option_ViewModel()
// {
// 	MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.MATCH_LTENDS",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMCheckBox3_CRACK_OPT_Property = CxvPropertyDeclaration.Register("MMCheckBox3_CRACK_OPT", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.CRACK_OPT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.DTYPED86"
// 		},
// 		DisabledPrompt = Resources.MMAssay_BasicD_Option_ViewModel__MMCheckBox3_CRACK_OPT_Property_DisabledPrompt
// 	});
// 	chkASTM_D86_OPT_D86_Property = CxvPropertyDeclaration.Register("chkASTM_D86_OPT_D86", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_D86",
// 		TrueValue = "D86",
// 		FalseValue = "NOD86",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CHKOND86"
// 		}
// 	});
// 	chkASTM_D1160_OPT_D1160_Property = CxvPropertyDeclaration.Register("chkASTM_D1160_OPT_D1160", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_D1160",
// 		TrueValue = "D1160",
// 		FalseValue = "NOD1160",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CHKOND1160"
// 		}
// 	});
// 	_chkVacuum_opt_vaclv_Property = CxvPropertyDeclaration.Register("_chkVacuum_opt_vaclv", typeof(MMAssay_BasicD_Option_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_VACLV",
// 		TrueValue = "VACLV",
// 		FalseValue = "NOVACLV",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.CHKONVACLV"
// 		}
// 	});
// }

// 0x06000333 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel.add_AllSelectedRecordsCountChanged
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

// 0x06000334 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel.remove_AllSelectedRecordsCountChanged
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

// 0x0600033b AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel..ctor
// public MMAssay_List2D_ViewModel()
// {
// }

// 0x0600033c AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_List2D_ViewModel()
// {
// 	cmdAddCanExecuteProperty = CxvPropertyDeclaration.Register("cmdAddCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main",
// 		Operator = CxvLogicalOperator.CanInvokeAction,
// 		Value = "InsertChild"
// 	});
// 	cmdEditCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
// 	{
// 		PropertyPath = "AllSelectedRecordsCount",
// 		Operator = CxvLogicalOperator.Equal,
// 		Value = 1
// 	});
// 	cmdDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdDeleteCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
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
// 	cmdRenameCanExecuteProperty = CxvPropertyDeclaration.Register("cmdRenameCanExecute", typeof(MMAssay_List2D_ViewModel), new CxvLogicalProperty
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
// 	grdChild_GridData_Property = CxvPropertyDeclaration.Register("grdChild_GridData", typeof(MMAssay_List2D_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdChild_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main",
// 			UseChildId = true,
// 			Name = "y",
// 			ProxyRow = false
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x06000347 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_ViewModel..ctor
// public MMAssay_Proper_ViewModel()
// {
// }

// 0x06000348 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Proper_ViewModel()
// {
// 	VISC_Property = CxvPropertyDeclaration.Register("VISC", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.VISC"
// 	});
// 	PropIDX_Property = CxvPropertyDeclaration.Register("PropIDX", typeof(MMAssay_Proper_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "PropIDX"
// 	});
// 	PRCV_Property = CxvPropertyDeclaration.Register("PRCV", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.PRCV"
// 	});
// 	PRCVOPT_Property = CxvPropertyDeclaration.Register("PRCVOPT", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.PRCVOPT"
// 	});
// 	VISCOPT_Property = CxvPropertyDeclaration.Register("VISCOPT", typeof(MMAssay_Proper_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.VISCOPT"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_Proper_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@PRCV" },
// 		EnteredDataPaths = { "@PRCVOPT" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_Proper_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@VISC" },
// 		EnteredDataPaths = { "@VISCOPT" }
// 	});
// }

// 0x06000353 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Petro_ViewModel..ctor
// public MMAssay_Proper_Petro_ViewModel()
// {
// }

// 0x06000354 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Petro_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Proper_Petro_ViewModel()
// {
// 	mnuPropType_target_Property = CxvPropertyDeclaration.Register("mnuPropType_target", typeof(MMAssay_Proper_Petro_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "PropIDX"
// 	});
// 	mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "var1"
// 	});
// 	mnuPropType_PropType_Property = CxvPropertyDeclaration.Register("mnuPropType_PropType", typeof(MMAssay_Proper_Petro_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.BULKVAL",
// 		SelectedItemBinding = "mnuPropType_target.Value",
// 		CreateNewPrompt = "Property type:",
// 		CreateNewPromptResourceKey = "MMAssay_Proper_Petro_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
// 		CompletePaths = { "PCCOMP", "PCCOMP2", "PRCVOPT" },
// 		EnteredPaths = { "UENTPRCV" }
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAssay_Proper_Petro_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "PropIDX",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PMID_PCT.@PropIDX",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	MMLBUText1_BULKVAL_Property = CxvPropertyDeclaration.Register("MMLBUText1_BULKVAL", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BULKVAL.@PropIDX"
// 	});
// 	MMLBUText3_PROPUNITS_Property = CxvPropertyDeclaration.Register("MMLBUText3_PROPUNITS", typeof(MMAssay_Proper_Petro_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PROP_UNITS.@PropIDX",
// 		IsReadOnly = true
// 	});
// }

// 0x0600036b AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel..ctor
// public MMAssay_Proper_Visc_ViewModel()
// {
// }

// 0x0600036c AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Proper_Visc_ViewModel()
// {
// 	ogrType_MultiMap_Property = CxvPropertyDeclaration.Register("ogrType_MultiMap", typeof(MMAssay_Proper_Visc_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ogrType_opt_visc",
// 				DataPath = "@main.Input.OPT_VISC"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Absolute viscosity",
// 				DisplayResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvMultiMapOption_Display_Absolute_viscosity",
// 				Value = "ogrType_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrType_opt_visc",
// 						Value = "VISC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Kinematic viscosity",
// 				DisplayResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvMultiMapOption_Display_Kinematic_viscosity",
// 				Value = "ogrType_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ogrType_opt_visc",
// 						Value = "KVISC"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	fraAVisc_state_Property = CxvPropertyDeclaration.Register("fraAVisc_state", typeof(MMAssay_Proper_Visc_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VEN"
// 		}
// 	});
// 	fraAVisc_tempid_Property = CxvPropertyDeclaration.Register("fraAVisc_tempid", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "tempid"
// 	});
// 	mnuAVISCtemp_target_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_target", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "tempid"
// 	});
// 	mnuAVISCtemp_AVCOMP_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_AVCOMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.AVCOMP"
// 	});
// 	lbtuViscTemp_ViscUnits_Property = CxvPropertyDeclaration.Register("lbtuViscTemp_ViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VISCOSITY.@tempid"
// 	});
// 	grdAVisc_GridData_Property = CxvPropertyDeclaration.Register("grdAVisc_GridData", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAVisc_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.VISCOSITY.@tempid",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.TEMPEXISTS"
// 		}
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMAssay_Proper_Visc_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.KVEN"
// 		}
// 	});
// 	MMFrame1_tempid_Property = CxvPropertyDeclaration.Register("MMFrame1_tempid", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "tempid"
// 	});
// 	MMLBUText2_KViscUnits_Property = CxvPropertyDeclaration.Register("MMLBUText2_KViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.KVISCOSITY.@tempid"
// 	});
// 	MMAdvCombo1_AVCOMP_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_AVCOMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.KVCOMP"
// 	});
// 	MMLBUText1_KVISCTEMP_Property = CxvPropertyDeclaration.Register("MMLBUText1_KVISCTEMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.KVISCTEMP"
// 	});
// 	lbtuATemp_VISCTEMP_Property = CxvPropertyDeclaration.Register("lbtuATemp_VISCTEMP", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VISCTEMP"
// 	});
// 	ViscUnits_Property = CxvPropertyDeclaration.Register("ViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VISCOSITY"
// 	});
// 	KViscUnits_Property = CxvPropertyDeclaration.Register("KViscUnits", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.KVISCOSITY"
// 	});
// 	MMAdvCombo1_target_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_target", typeof(MMAssay_Proper_Visc_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "ktempid"
// 	});
// 	mnuAVISCtemp_viscosity_Property = CxvPropertyDeclaration.Register("mnuAVISCtemp_viscosity", typeof(MMAssay_Proper_Visc_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.VISCTEMP",
// 		SelectedItemBinding = "mnuAVISCtemp_target.Value",
// 		CreateNewPrompt = "Temperature:",
// 		CreateNewPromptResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Temperature_",
// 		CreateNewInputMask = 1,
// 		CompletePaths = { "AVCOMP", "NVISC" },
// 		DisplayValues = true
// 	});
// 	MMAdvCombo1_viscosity_Property = CxvPropertyDeclaration.Register("MMAdvCombo1_viscosity", typeof(MMAssay_Proper_Visc_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.KVISCTEMP",
// 		SelectedItemBinding = "MMAdvCombo1_target.Value",
// 		CreateNewInputMask = 1,
// 		CreateNewPrompt = "Temperature:",
// 		CreateNewPromptResourceKey = "MMAssay_Proper_Visc_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Temperature__1",
// 		CompletePaths = { "KVCOMP", "NKVISC" },
// 		DisplayValues = true
// 	});
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMAssay_Proper_Visc_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.KVISCOSITY.@ktempid",
// 			UseChildId = true,
// 			Name = "y"
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.KTEMPEXISTS"
// 		}
// 	});
// }

// 0x06000376 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_ViewModel..ctor
// public MMAssay_Result_ViewModel()
// {
// }

// 0x06000377 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Result_ViewModel()
// {
// 	ACCPSEUDO_Property = CxvPropertyDeclaration.Register("ACCPSEUDO", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPID"
// 	});
// 	ACCCURVE_Property = CxvPropertyDeclaration.Register("ACCCURVE", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.DIST_RATIO"
// 	});
// 	ACCLENDS_Property = CxvPropertyDeclaration.Register("ACCLENDS", typeof(MMAssay_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TLVCONC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCLENDS" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCPSEUDO" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMAssay_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCCURVE" }
// 	});
// }

// 0x060003a2 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Curve_ViewModel..ctor
// public MMAssay_Result_Curve_ViewModel()
// {
// }

// 0x060003a3 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Curve_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Result_Curve_ViewModel()
// {
// 	fraCurve_col1_Property = CxvPropertyDeclaration.Register("fraCurve_col1", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col1"
// 	});
// 	fraCurve_col2_Property = CxvPropertyDeclaration.Register("fraCurve_col2", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col2"
// 	});
// 	fraCurve_col3_Property = CxvPropertyDeclaration.Register("fraCurve_col3", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col3"
// 	});
// 	fraCurve_col0_Property = CxvPropertyDeclaration.Register("fraCurve_col0", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col0"
// 	});
// 	fraCurve_col4_Property = CxvPropertyDeclaration.Register("fraCurve_col4", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col4"
// 	});
// 	fraCurve_col5_Property = CxvPropertyDeclaration.Register("fraCurve_col5", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "col5"
// 	});
// 	lbtuDensity_DENSITY_Property = CxvPropertyDeclaration.Register("lbtuDensity_DENSITY", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.DENSITY"
// 	});
// 	lbtuMW_MW_Property = CxvPropertyDeclaration.Register("lbtuMW_MW", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MW"
// 	});
// 	grdResults_GridData_Property = CxvPropertyDeclaration.Register("grdResults_GridData", typeof(MMAssay_Result_Curve_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdResults_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.DIST_RATIO",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	lbtuAPI_API_Property = CxvPropertyDeclaration.Register("lbtuAPI_API", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.API"
// 	});
// 	lbtuSG_SG_Property = CxvPropertyDeclaration.Register("lbtuSG_SG", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.SG"
// 	});
// 	FirstCol_Label_Property = CxvPropertyDeclaration.Register("FirstCol_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "FirstColLabel"
// 	});
// 	Col0_PRES_Property = CxvPropertyDeclaration.Register("Col0_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TBP_PRES"
// 	});
// 	Col0_Units_Property = CxvPropertyDeclaration.Register("Col0_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col0"
// 	});
// 	Col0_Label_Property = CxvPropertyDeclaration.Register("Col0_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col0Label"
// 	});
// 	Col0_Used_Property = CxvPropertyDeclaration.Register("Col0_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col0Used",
// 		Value = false
// 	});
// 	Col1_PRES_Property = CxvPropertyDeclaration.Register("Col1_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.D86_PRES"
// 	});
// 	Col1_Units_Property = CxvPropertyDeclaration.Register("Col1_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col1"
// 	});
// 	Col1_Label_Property = CxvPropertyDeclaration.Register("Col1_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col1Label"
// 	});
// 	Col1_Used_Property = CxvPropertyDeclaration.Register("Col1_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col1Used",
// 		Value = false
// 	});
// 	Col2_PRES_Property = CxvPropertyDeclaration.Register("Col2_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.D1160_PRES"
// 	});
// 	Col2_Units_Property = CxvPropertyDeclaration.Register("Col2_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col2"
// 	});
// 	Col2_Label_Property = CxvPropertyDeclaration.Register("Col2_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col2Label"
// 	});
// 	Col2_Used_Property = CxvPropertyDeclaration.Register("Col2_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col2Used",
// 		Value = false
// 	});
// 	Col3_PRES_Property = CxvPropertyDeclaration.Register("Col3_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.VAC_PRES"
// 	});
// 	Col3_Units_Property = CxvPropertyDeclaration.Register("Col3_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col3"
// 	});
// 	Col3_Label_Property = CxvPropertyDeclaration.Register("Col3_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col3Label"
// 	});
// 	Col3_Used_Property = CxvPropertyDeclaration.Register("Col3_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col3Used",
// 		Value = false
// 	});
// 	Col4_PRES_Property = CxvPropertyDeclaration.Register("Col4_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.D86E_PRES"
// 	});
// 	Col4_Units_Property = CxvPropertyDeclaration.Register("Col4_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col4"
// 	});
// 	Col4_Label_Property = CxvPropertyDeclaration.Register("Col4_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col4Label"
// 	});
// 	Col4_Used_Property = CxvPropertyDeclaration.Register("Col4_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col4Used",
// 		Value = false
// 	});
// 	Col5_PRES_Property = CxvPropertyDeclaration.Register("Col5_PRES", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.D2887_PRES"
// 	});
// 	Col5_Units_Property = CxvPropertyDeclaration.Register("Col5_Units", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col5"
// 	});
// 	Col5_Label_Property = CxvPropertyDeclaration.Register("Col5_Label", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col5Label"
// 	});
// 	Col5_Used_Property = CxvPropertyDeclaration.Register("Col5_Used", typeof(MMAssay_Result_Curve_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Col5Used",
// 		Value = false
// 	});
// 	lblPresUnit_VAR_UNIT_Property = CxvPropertyDeclaration.Register("lblPresUnit_VAR_UNIT", typeof(MMAssay_Result_Curve_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.VAR_UNIT"
// 	});
// }

// 0x060003af AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Light_ViewModel..ctor
// public MMAssay_Result_Light_ViewModel()
// {
// }

// 0x060003b0 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Light_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Result_Light_ViewModel()
// {
// 	txtMoleFracTotla_TOT_MOL_FRAC_Property = CxvPropertyDeclaration.Register("txtMoleFracTotla_TOT_MOL_FRAC", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TOT_MOL_FRAC"
// 	});
// 	txtWtPctTotla_TOT_WT_PCT_Property = CxvPropertyDeclaration.Register("txtWtPctTotla_TOT_WT_PCT", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TOT_WT_PCT"
// 	});
// 	txtVolPctTotal_TOT_LV_PCT_Property = CxvPropertyDeclaration.Register("txtVolPctTotal_TOT_LV_PCT", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TOT_LV_PCT"
// 	});
// 	lbtuMW_MW_Property = CxvPropertyDeclaration.Register("lbtuMW_MW", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MW2"
// 	});
// 	lbtuDensity_DENSITY_Property = CxvPropertyDeclaration.Register("lbtuDensity_DENSITY", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.DENSITY2"
// 	});
// 	lbtuAPIGrav_API_Property = CxvPropertyDeclaration.Register("lbtuAPIGrav_API", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.API2"
// 	});
// 	lbtuSpecGrav_SG_Property = CxvPropertyDeclaration.Register("lbtuSpecGrav_SG", typeof(MMAssay_Result_Light_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.SG2"
// 	});
// 	grdAssay_GridData_Property = CxvPropertyDeclaration.Register("grdAssay_GridData", typeof(MMAssay_Result_Light_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdAssay_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.TLVCONC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060003b5 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Pseudo_ViewModel..ctor
// public MMAssay_Result_Pseudo_ViewModel()
// {
// }

// 0x060003b6 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Pseudo_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMAssay_Result_Pseudo_ViewModel()
// {
// 	grdPCBreakdown_GridData_Property = CxvPropertyDeclaration.Register("grdPCBreakdown_GridData", typeof(MMAssay_Result_Pseudo_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPCBreakdown_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060003bc AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_ViewModel..ctor
// public MMBlend_Mixtur_ViewModel()
// {
// }

// 0x060003bd AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlend_Mixtur_ViewModel()
// {
// 	BLND_Property = CxvPropertyDeclaration.Register("BLND", typeof(MMBlend_Mixtur_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.BLND"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlend_Mixtur_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@BLND" }
// 	});
// }

// 0x060003c6 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_Spec_ViewModel..ctor
// public MMBlend_Mixtur_Spec_ViewModel()
// {
// }

// 0x060003c7 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_Spec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlend_Mixtur_Spec_ViewModel()
// {
// 	MMLBUText1_BASIS_FRAC_Property = CxvPropertyDeclaration.Register("MMLBUText1_BASIS_FRAC", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BASIS_FRAC"
// 	});
// 	grdBlendComposition_GridData_Property = CxvPropertyDeclaration.Register("grdBlendComposition_GridData", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdBlendComposition_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.BASIS_FRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	chkVacuum_var1_Property = CxvPropertyDeclaration.Register("chkVacuum_var1", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_VACLV",
// 		TrueValue = "VACLV",
// 		FalseValue = "NOVACLV"
// 	});
// 	chkASTM_D1160_OPT_D1160_Property = CxvPropertyDeclaration.Register("chkASTM_D1160_OPT_D1160", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_D1160",
// 		TrueValue = "D1160",
// 		FalseValue = "NOD1160"
// 	});
// 	chkASTM_D86_OPT_D86_Property = CxvPropertyDeclaration.Register("chkASTM_D86_OPT_D86", typeof(MMBlend_Mixtur_Spec_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.OPT_D86",
// 		TrueValue = "D86",
// 		FalseValue = "NOD86"
// 	});
// }

// 0x060003d3 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_ViewModel..ctor
// public MMBlend_Result_ViewModel()
// {
// }

// 0x060003d4 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlend_Result_ViewModel()
// {
// 	ACCLENDS_Property = CxvPropertyDeclaration.Register("ACCLENDS", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TLVCONC"
// 	});
// 	ACCPSEUDO_Property = CxvPropertyDeclaration.Register("ACCPSEUDO", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPID"
// 	});
// 	ACCCURVE_Property = CxvPropertyDeclaration.Register("ACCCURVE", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.DIST_RATIO"
// 	});
// 	ACCBLEND_Property = CxvPropertyDeclaration.Register("ACCBLEND", typeof(MMBlend_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCLENDS" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCPSEUDO" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCCURVE" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMBlend_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@ACCBLEND" }
// 	});
// }

// 0x060003d9 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_Blend_ViewModel..ctor
// public MMBlend_Result_Blend_ViewModel()
// {
// }

// 0x060003da AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_Blend_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMBlend_Result_Blend_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMBlend_Result_Blend_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPFRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060003e5 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_ViewModel..ctor
// public MMLeprop_Specif_ViewModel()
// {
// }

// 0x060003e6 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMLeprop_Specif_ViewModel()
// {
// 	strPID_Property = CxvPropertyDeclaration.Register("strPID", typeof(MMLeprop_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "strPID"
// 	});
// 	UNLEPROP_Property = CxvPropertyDeclaration.Register("UNLEPROP", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UNLEPROP"
// 	});
// 	UNLEPPBAS_Property = CxvPropertyDeclaration.Register("UNLEPPBAS", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UNLEPPBAS"
// 	});
// 	CPLEPROP_Property = CxvPropertyDeclaration.Register("CPLEPROP", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CPLEPROP"
// 	});
// 	AAAAA_Property = CxvPropertyDeclaration.Register("AAAAA", typeof(MMLeprop_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.AAAAA"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMLeprop_Specif_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@AAAAA", "@CPLEPROP" },
// 		EnteredDataPaths = { "@UNLEPPBAS", "@UNLEPROP" }
// 	});
// }

// 0x060003f2 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_Specif_ViewModel..ctor
// public MMLeprop_Specif_Specif_ViewModel()
// {
// }

// 0x060003f3 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMLeprop_Specif_Specif_ViewModel()
// {
// 	grdLEnds_GridData_Property = CxvPropertyDeclaration.Register("grdLEnds_GridData", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdLEnds_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.PROP_VALUE.@strPID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	mnuPropType_var2_Property = CxvPropertyDeclaration.Register("mnuPropType_var2", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "strPID"
// 	});
// 	mnuPropType_UNLEPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNLEPROPB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UNLEPROP"
// 	});
// 	mnuPropType_UNLEPPBASB_Property = CxvPropertyDeclaration.Register("mnuPropType_UNLEPPBASB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UNLEPPBAS"
// 	});
// 	mnuPropType_CPLEPROPB_Property = CxvPropertyDeclaration.Register("mnuPropType_CPLEPROPB", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.CPLEPROP"
// 	});
// 	mnuPropType_var1_Property = CxvPropertyDeclaration.Register("mnuPropType_var1", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.PROP_VALUE",
// 		SelectedItemBinding = "mnuPropType_var2.Value",
// 		CreateNewPrompt = "Property type:",
// 		CreateNewPromptResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Property_type_",
// 		CompletePaths = { "@main.CC Nodes.CPLEPROP" },
// 		EnteredPaths = { "@main.CC Nodes.UNLEPROP", "@main.CC Nodes.UNLEPPBAS" }
// 	});
// 	ShowBasis_Property = CxvPropertyDeclaration.Register("ShowBasis", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvLogicalProperty
// 	{
// 		Operator = CxvLogicalOperator.Or,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "SULFUR"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "BASIC-N2"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "HYDROGEN"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "OXYGEN"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "METAL"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "PARAFFIN"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "NAPHTHEN"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "OLEFIN"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "AROMATIC"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "CARBON"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "MERCAPTA"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "TOTAL-N2"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "IRON"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "NICKEL"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "VANADIUM"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "COCARBON"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "ASPHALTE"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "BROMINE"
// 			},
// 			new CxvLogicalTest
// 			{
// 				Parameter = "strPID",
// 				Value = "CETANE"
// 			}
// 		}
// 	});
// 	MMComboBox4_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox4_MultiMap", typeof(MMLeprop_Specif_Specif_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox4_var1",
// 				DataPath = "@main.Input.PROP_BASIS.@strPID"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mass",
// 				DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_Mass",
// 				Value = "MMComboBox4_MultiMapOption_1",
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
// 				DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_Mole",
// 				Value = "MMComboBox4_MultiMapOption_2",
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
// 				DisplayResourceKey = "MMLeprop_Specif_Specif_ViewModel__CxvMultiMapOption_Display_StdVol",
// 				Value = "MMComboBox4_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox4_var1",
// 						Value = "STDVOL"
// 					}
// 				}
// 			}
// 		},
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.HASBASIS.@strPID"
// 		}
// 	});
// }

// 0x060003f9 AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_Group_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060003fa AspenTech.AspenPlus.MMForms.Components.UNIFAC_Groups.MMCompUni_Input_Group_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	txtGroupID_var1_Property = CxvPropertyDeclaration.Register("txtGroupID_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.GROUPNO.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboGroupNumber_var1_Property = CxvPropertyDeclaration.Register("cboGroupNumber_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.GROUPNO.@y",
// 		AllowNew = false,
// 		AllowEmptyOptions = true
// 	});
// }

// 0x060003fc AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_NonConven_ViewModel+grdNonConventionalComponents_GridData_ItemTemplate..ctor
// public grdNonConventionalComponents_GridData_ItemTemplate()
// {
// }

// 0x060003fd AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_NonConven_ViewModel+grdNonConventionalComponents_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdNonConventionalComponents_GridData_ItemTemplate()
// {
// 	txtNonConventionalComponents_nonconv_Property = CxvPropertyDeclaration.Register("txtNonConventionalComponents_nonconv", typeof(grdNonConventionalComponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NONCONVID.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x060003ff AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdPseudocomponents_GridData_ItemTemplate..ctor
// public grdPseudocomponents_GridData_ItemTemplate()
// {
// }

// 0x06000400 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdPseudocomponents_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPseudocomponents_GridData_ItemTemplate()
// {
// 	txtPseudocomponents_pseudocomp_Property = CxvPropertyDeclaration.Register("txtPseudocomponents_pseudocomp", typeof(grdPseudocomponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PSEUDOCOMPID.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x06000402 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdBlend_GridData_ItemTemplate..ctor
// public grdBlend_GridData_ItemTemplate()
// {
// }

// 0x06000403 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdBlend_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdBlend_GridData_ItemTemplate()
// {
// 	txtBlend_blend_Property = CxvPropertyDeclaration.Register("txtBlend_blend", typeof(grdBlend_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BLENDID.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x06000405 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdAssay_GridData_ItemTemplate..ctor
// public grdAssay_GridData_ItemTemplate()
// {
// }

// 0x06000406 AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Petroleum_ViewModel+grdAssay_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAssay_GridData_ItemTemplate()
// {
// 	txtAssay_assay_Property = CxvPropertyDeclaration.Register("txtAssay_assay", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ASSAYID.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x0600040c AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Selection_ViewModel+grdComponents_GridData_ItemTemplate..ctor
// public grdComponents_GridData_ItemTemplate()
// {
// }

// 0x0600040d AspenTech.AspenPlus.MMForms.Components.Specifications.MMComp_Spec_Input_Selection_ViewModel+grdComponents_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdComponents_GridData_ItemTemplate()
// {
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdComponents_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_type",
// 				DataPath = "@main.Input.TYPE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Conventional",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Conventional",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "CONV"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Solid",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "SOLID"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Biocomponent",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Biocomponent",
// 				Value = "MMComboBox1_MultiMapOption_11",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "BIO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Nonconventional",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Nonconventional",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "NC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Pseudocomponent",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Pseudocomponent",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "PSEUDO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Assay",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Assay",
// 				Value = "MMComboBox1_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "ASSAY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Blend",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Blend",
// 				Value = "MMComboBox1_MultiMapOption_6",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "BLEND"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Hypothetical liquid",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Hypothetical_liquid",
// 				Value = "MMComboBox1_MultiMapOption_7",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "HYPO-LIQ"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Polymer",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Polymer",
// 				Value = "MMComboBox1_MultiMapOption_8",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "POLYMER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Oligomer",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Oligomer",
// 				Value = "MMComboBox1_MultiMapOption_9",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "OLIGOMER"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Segment",
// 				DisplayResourceKey = "MMComp_Spec_Input_Selection_ViewModel__CxvMultiMapOption_Display_Segment",
// 				Value = "MMComboBox1_MultiMapOption_10",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_type",
// 						Value = "SEGMENT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtCompID_cid_Property = CxvPropertyDeclaration.Register("txtCompID_cid", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.TYPE.@y",
// 		IsEntered = false
// 	});
// 	txt_Formula_name_Property = CxvPropertyDeclaration.Register("txt_Formula_name", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ANAME1.@y"
// 	});
// 	txtComponentName_dbname_Property = CxvPropertyDeclaration.Register("txtComponentName_dbname", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DBNAME1.@y"
// 	});
// 	txt_Formula_CAS_Property = CxvPropertyDeclaration.Register("txt_Formula_CAS", typeof(grdComponents_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CASN.@y"
// 	});
// }

// 0x06000410 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Petro_ViewModel+grdLEnds_GridData_ItemTemplate..ctor
// public grdLEnds_GridData_ItemTemplate()
// {
// }

// 0x06000411 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Petro_ViewModel+grdLEnds_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLEnds_GridData_ItemTemplate()
// {
// 	cboCompID_var1_Property = CxvPropertyDeclaration.Register("cboCompID_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Properties.Input.VALUE.@strPID.@y"
// 	});
// 	txtFRAC_var1_Property = CxvPropertyDeclaration.Register("txtFRAC_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VALUE.@strPID.@y"
// 	});
// }

// 0x06000419 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel+grdAdvanced_GridData_ItemTemplate..ctor
// public grdAdvanced_GridData_ItemTemplate()
// {
// }

// 0x0600041a AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel+grdAdvanced_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAdvanced_GridData_ItemTemplate()
// {
// 	txtPCID_PCID_Property = CxvPropertyDeclaration.Register("txtPCID_PCID", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Specifications.Input.PCOPSETNAME.@y"
// 	});
// 	cboOpSet_PCOPSETNAME_Property = CxvPropertyDeclaration.Register("cboOpSet_PCOPSETNAME", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Specifications.Input.PCOPSETNAME.@y"
// 	});
// 	txtMW_MW_Property = CxvPropertyDeclaration.Register("txtMW_MW", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.MW.@y"
// 	});
// 	txtLDEN_LDEN_Property = CxvPropertyDeclaration.Register("txtLDEN_LDEN", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.LDEN.@y"
// 	});
// 	txtGRAV_GRAV_Property = CxvPropertyDeclaration.Register("txtGRAV_GRAV", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.GRAV.@y"
// 	});
// 	txtAPI_API_Property = CxvPropertyDeclaration.Register("txtAPI_API", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.API.@y"
// 	});
// 	txtNBP_NBP_Property = CxvPropertyDeclaration.Register("txtNBP_NBP", typeof(grdAdvanced_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.NBP.@y"
// 	});
// }

// 0x0600041f AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel+grdBasic_GridData_ItemTemplate..ctor
// public grdBasic_GridData_ItemTemplate()
// {
// }

// 0x06000420 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Spec_ViewModel+grdBasic_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdBasic_GridData_ItemTemplate()
// {
// 	txtPCID2_PCID_Property = CxvPropertyDeclaration.Register("txtPCID2_PCID", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Specifications.Input.NBP.@y"
// 	});
// 	txtMW2_MW_Property = CxvPropertyDeclaration.Register("txtMW2_MW", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.MW.@y"
// 	});
// 	txtNBP2_NBP_Property = CxvPropertyDeclaration.Register("txtNBP2_NBP", typeof(grdBasic_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Specifications.Input.NBP.@y"
// 	});
// 	txtGravType_gravval_Property = CxvPropertyDeclaration.Register("txtGravType_gravval", typeof(grdBasic_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.Specifications.Input.GRAVTYPE",
// 				Value = "GRAV",
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Specifications.Input.GRAV.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.Specifications.Input.GRAVTYPE",
// 				Value = "API",
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Specifications.Input.API.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.Specifications.Input.GRAVTYPE",
// 				Value = "LDEN",
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Specifications.Input.LDEN.@y"
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000423 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Vapor_ViewModel+grdVisc_GridData_ItemTemplate..ctor
// public grdVisc_GridData_ItemTemplate()
// {
// }

// 0x06000424 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Vapor_ViewModel+grdVisc_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdVisc_GridData_ItemTemplate()
// {
// 	txtTemp_temp_Property = CxvPropertyDeclaration.Register("txtTemp_temp", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.TEMP.@vpcid.@y"
// 	});
// 	txtVP_VP_Property = CxvPropertyDeclaration.Register("txtVP_VP", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VP.@vpcid.@y"
// 	});
// }

// 0x06000427 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Viscos_ViewModel+grdVisc_GridData_ItemTemplate..ctor
// public grdVisc_GridData_ItemTemplate()
// {
// }

// 0x06000428 AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Viscos_ViewModel+grdVisc_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdVisc_GridData_ItemTemplate()
// {
// 	txtTemp_temp_Property = CxvPropertyDeclaration.Register("txtTemp_temp", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VITEMP.@vicid.@y"
// 	});
// 	txtVisc_var1_Property = CxvPropertyDeclaration.Register("txtVisc_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.VISC.@vicid.@y"
// 	});
// }

// 0x0600042b AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Water_ViewModel+grdVisc_GridData_ItemTemplate..ctor
// public grdVisc_GridData_ItemTemplate()
// {
// }

// 0x0600042c AspenTech.AspenPlus.MMForms.Components.Pseudocomponents.MMPseudo_Input_Water_ViewModel+grdVisc_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdVisc_GridData_ItemTemplate()
// {
// 	txtWaterSol_var1_Property = CxvPropertyDeclaration.Register("txtWaterSol_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.WSOL.@wscid.@y"
// 	});
// 	txtTemp_var1_Property = CxvPropertyDeclaration.Register("txtTemp_var1", typeof(grdVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Properties.Input.MTEMP.@wscid.@y"
// 	});
// }

// 0x0600042d AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attrib_ViewModel+<>c__DisplayClass10_0..ctor
// public <>c__DisplayClass10_0()
// {
// }

// 0x06000430 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attrib_ViewModel+<>c__DisplayClass10_1..ctor
// public <>c__DisplayClass10_1()
// {
// }

// 0x06000432 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attrib_ViewModel+<>c__DisplayClass10_2..ctor
// public <>c__DisplayClass10_2()
// {
// }

// 0x06000434 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Attribc_ViewModel+<>c__DisplayClass23_0..ctor
// public <>c__DisplayClass23_0()
// {
// }

// 0x0600043a AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Catal_ViewModel+grdCatAtt_GridData_ItemTemplate..ctor
// public grdCatAtt_GridData_ItemTemplate()
// {
// }

// 0x0600043b AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Catal_ViewModel+grdCatAtt_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdCatAtt_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdCatAtt_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdCatAtt_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvFixedCountIndexBasis
// 		{
// 			FixedCount = 3,
// 			Name = "Col"
// 		}
// 	});
// }

// 0x0600043d AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Catal_ViewModel+grdCatAtt_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdCatAtt_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000440 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000441 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.NUMBER.#0",
// 			UseChildId = true,
// 			Name = "Seg"
// 		}
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.NUMBER.@Olig",
// 		IsReadOnly = true
// 	});
// }

// 0x06000444 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000445 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Oligom_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NUMBER.@Olig.@Seg"
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NUMBER.@Olig.@Seg",
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions
// 	});
// }

// 0x06000447 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Polymer_ViewModel+grdPolAtt_GridData_ItemTemplate..ctor
// public grdPolAtt_GridData_ItemTemplate()
// {
// }

// 0x06000448 AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Polymer_ViewModel+grdPolAtt_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPolAtt_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdPolAtt_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdPolAtt_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvFixedCountIndexBasis
// 		{
// 			FixedCount = 5,
// 			Name = "Col"
// 		}
// 	});
// }

// 0x0600044a AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Polymer_ViewModel+grdPolAtt_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdPolAtt_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x0600044d AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Segment_ViewModel+grdSegment_GridData_ItemTemplate..ctor
// public grdSegment_GridData_ItemTemplate()
// {
// }

// 0x0600044e AspenTech.AspenPlus.MMForms.Components.Polymers.MMPolymers_Charact_Segment_ViewModel+grdSegment_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSegment_GridData_ItemTemplate()
// {
// 	cboSegType_var1_Property = CxvPropertyDeclaration.Register("cboSegType_var1", typeof(grdSegment_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.SEG_TYPE.@Segment"
// 	});
// 	txtSegID_var1_Property = CxvPropertyDeclaration.Register("txtSegID_var1", typeof(grdSegment_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.SEG_TYPE.@Segment"
// 	});
// }

// 0x06000453 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Blend_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000454 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMADAset_Analys_Blend_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMComboBox1_PPROP_Property = CxvPropertyDeclaration.Register("MMComboBox1_PPROP", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Blend Options.Input.PROP_NAME.@y"
// 	});
// 	MMComboBox3_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox3_MultiMap", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox3_var1",
// 				DataPath = "@main.Blend Options.Input.EXTRAPOLATE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox3_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox3_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox3_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox3_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Blend Options.Input.BLEND_OPTION.@y"
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Blend Options.Input.BLEND_METHOD.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "StdVol",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_StdVol",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "STDVOL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mass",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Mass",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "MASS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mole",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_Mole",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "MOLE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "User",
// 				DisplayResourceKey = "MMADAset_Analys_Blend_ViewModel__CxvMultiMapOption_Display_User",
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "USER"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x0600045a AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel+grdRANGE_GridData_ItemTemplate..ctor
// public grdRANGE_GridData_ItemTemplate()
// {
// }

// 0x0600045b AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel+grdRANGE_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdRANGE_GridData_ItemTemplate()
// {
// 	txtNInc_NINC_Property = CxvPropertyDeclaration.Register("txtNInc_NINC", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NINC.@y"
// 	});
// 	txtIncr_INCR_Property = CxvPropertyDeclaration.Register("txtIncr_INCR", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.INCR.@y"
// 	});
// 	txtUpper_UTEMP_Property = CxvPropertyDeclaration.Register("txtUpper_UTEMP", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UTEMP.@y"
// 	});
// 	txtUpper_UTEMP2_Property = CxvPropertyDeclaration.Register("txtUpper_UTEMP2", typeof(grdRANGE_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UTEMP.@y"
// 	});
// }

// 0x0600045d AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel+grdLIST_GridData_ItemTemplate..ctor
// public grdLIST_GridData_ItemTemplate()
// {
// }

// 0x0600045e AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Cuts_ViewModel+grdLIST_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLIST_GridData_ItemTemplate()
// {
// 	txtCutTemp_var1_Property = CxvPropertyDeclaration.Register("txtCutTemp_var1", typeof(grdLIST_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIST.@y"
// 	});
// }

// 0x06000460 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000461 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox2_PC_LIST_Property = CxvPropertyDeclaration.Register("MMTextBox2_PC_LIST", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PC_LIST.@x",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x06000464 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+grdLIST_GridData_ItemTemplate..ctor
// public grdLIST_GridData_ItemTemplate()
// {
// }

// 0x06000465 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+grdLIST_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLIST_GridData_ItemTemplate()
// {
// 	txtLIST_PC_LIST_Property = CxvPropertyDeclaration.Register("txtLIST_PC_LIST", typeof(grdLIST_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PC_LIST.@x",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// }

// 0x0600046c AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+PreviewTemplate..ctor
// public PreviewTemplate()
// {
// }

// 0x06000471 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Naming_ViewModel+CellData..ctor
// public CellData()
// {
// }

// 0x06000474 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Spec_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000475 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Gen_Spec_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox1_wf_Property = CxvPropertyDeclaration.Register("MMTextBox1_wf", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.WF.@y"
// 	});
// 	MMComboBox1_AID_Property = CxvPropertyDeclaration.Register("MMComboBox1_AID", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.WF.@y"
// 	});
// }

// 0x06000478 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000479 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@TRAYoutp",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	MMTextBox8_var1_Property = CxvPropertyDeclaration.Register("MMTextBox8_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@TRAYoutp.#0.@z",
// 		ExposeAs = CxvVariableTypeCode.Id
// 	});
// }

// 0x06000480 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000481 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Petrop_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@TRAYoutp.@y.@z"
// 	});
// }

// 0x0600048b AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Summary_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x0600048c AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Summary_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox8_sg_Property = CxvPropertyDeclaration.Register("MMTextBox8_sg", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.VAL2.@y"
// 	});
// 	MMTextBox1_COMP_NAMES_Property = CxvPropertyDeclaration.Register("MMTextBox1_COMP_NAMES", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.COMP_NAMES.@y"
// 	});
// 	MMTextBox7_PCMX_Property = CxvPropertyDeclaration.Register("MMTextBox7_PCMX", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.PCMX.@y"
// 	});
// 	MMTextBox6_TCMX_Property = CxvPropertyDeclaration.Register("MMTextBox6_TCMX", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.TCMX.@y"
// 	});
// 	MMTextBox5_MW_Property = CxvPropertyDeclaration.Register("MMTextBox5_MW", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.MW.@y"
// 	});
// 	MMTextBox4_sg_Property = CxvPropertyDeclaration.Register("MMTextBox4_sg", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.SG.@y"
// 	});
// 	MMTextBox3_API_Property = CxvPropertyDeclaration.Register("MMTextBox3_API", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.API.@y"
// 	});
// 	MMTextBox2_NBP_Property = CxvPropertyDeclaration.Register("MMTextBox2_NBP", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Results.Output.VAL1.@y"
// 	});
// }

// 0x0600048f AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+grdMyVisc_GridData_ItemTemplate..ctor
// public grdMyVisc_GridData_ItemTemplate()
// {
// }

// 0x06000490 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+grdMyVisc_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMyVisc_GridData_ItemTemplate()
// {
// 	txtViscosity_var1_Property = CxvPropertyDeclaration.Register("txtViscosity_var1", typeof(grdMyVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@dec_xsp.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdMyVisc_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@dec_xsp.#0",
// 			UseChildId = true,
// 			Name = "x"
// 		}
// 	});
// }

// 0x06000493 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000494 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	txtComponent_var1_Property = CxvPropertyDeclaration.Register("txtComponent_var1", typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "x"
// 	});
// 	txtValue_var1_Property = CxvPropertyDeclaration.Register("txtValue_var1", typeof(grdMyVisc_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@dec_xsp.@y.@x"
// 	});
// }

// 0x06000497 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+ColumnHeaderConverter..ctor
// public ColumnHeaderConverter()
// {
// }

// 0x06000498 AspenTech.AspenPlus.MMForms.Components.PetroleumCharacterization.MMPCCalc_Result_Viscos_ViewModel+ColumnHeaderConverter..cctor
// static ColumnHeaderConverter()
// {
// 	Converter = new ColumnHeaderConverter();
// }

// 0x0600049b AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Range_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x0600049c AspenTech.AspenPlus.MMForms.Components.Comp_Groups.MMCompgrp_Input_Range_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.T2.@choice.@y"
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.T2.@choice.@y"
// 	});
// }

// 0x0600049d AspenTech.AspenPlus.MMForms.Components.Bio_Comps.BioFeedDB+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600049e AspenTech.AspenPlus.MMForms.Components.Bio_Comps.BioFeedDB+<>c..ctor
// public <>c()
// {
// }

// 0x060004a1 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Biofeed_ViewModel+<>c__DisplayClass1_0..ctor
// public <>c__DisplayClass1_0()
// {
// }

// 0x060004ad AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdPhase_GridData_ItemTemplate..ctor
// public grdPhase_GridData_ItemTemplate()
// {
// }

// 0x060004ae AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdPhase_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static grdPhase_GridData_ItemTemplate()
// {
// 	txtCompID_var1_Property = CxvPropertyDeclaration.Register("txtCompID_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.PHASE.@y",
// 		IsReadOnly = true
// 	});
// 	Phase_var1_Property = CxvPropertyDeclaration.Register("Phase_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "Phase_var1",
// 				DataPath = "@main.Input.PHASE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = FormsComponentsResources.Liquid,
// 				Prompt = PromptResources.FILEPNUM_953_Prompt_3,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Phase_var1",
// 						Value = "L"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = FormsComponentsResources.Solid,
// 				Prompt = PromptResources.FILEPNUM_953_Prompt_4,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "Phase_var1",
// 						Value = "S"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	chkEnabled_var1_Property = CxvPropertyDeclaration.Register("chkEnabled_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.TYPE_LIST.@y",
// 		TrueValue = "BIOSTATE",
// 		FalseValue = "NO",
// 		DefaultValue = false,
// 		ReadOnlyIfProxy = true
// 	});
// 	MMComboBasis_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBasis_MultiMap", typeof(grdPhase_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBasis",
// 				DataPath = "@main.Input.INPUT_BASIS.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = FormsComponentsResources.NumberOfAtoms,
// 				Prompt = PromptResources.FILEPNUM_953_Prompt_11,
// 				Value = "MMComboBasis_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBasis",
// 						Value = "NOATOM"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = FormsComponentsResources.MassPercentage,
// 				Prompt = PromptResources.FILEPNUM_953_Prompt_12,
// 				Value = "MMComboBasis_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBasis",
// 						Value = "MASS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = FormsComponentsResources.MolarPercentage,
// 				Prompt = PromptResources.FILEPNUM_953_Prompt_13,
// 				Value = "MMComboBasis_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBasis",
// 						Value = "MOLAR"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtCarbon_var1_Property = CxvPropertyDeclaration.Register("txtCarbon_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.NOATOM1.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.VALUES1.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.MOLEPERCENT1.@y"
// 				}
// 			}
// 		}
// 	});
// 	txtHydrogen_var1_Property = CxvPropertyDeclaration.Register("txtHydrogen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.NOATOM2.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.VALUES2.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.MOLEPERCENT2.@y"
// 				}
// 			}
// 		}
// 	});
// 	txtOxygen_var1_Property = CxvPropertyDeclaration.Register("txtOxygen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.NOATOM3.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.VALUES3.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.MOLEPERCENT3.@y"
// 				}
// 			}
// 		}
// 	});
// 	txtNitrogen_var1_Property = CxvPropertyDeclaration.Register("txtNitrogen_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.NOATOM4.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.VALUES4.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.MOLEPERCENT4.@y"
// 				}
// 			}
// 		}
// 	});
// 	txtAsh_var1_Property = CxvPropertyDeclaration.Register("txtAsh_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.NOATOM5.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.VALUES5.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.MOLEPERCENT5.@y"
// 				}
// 			}
// 		}
// 	});
// 	txtTotal_var1_Property = CxvPropertyDeclaration.Register("txtTotal_var1", typeof(grdPhase_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "",
// 					IsReadOnly = true,
// 					IsEnabledCondition = new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "NOATOM",
// 						Operator = CxvLogicalOperator.NotEqual
// 					}
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MASS",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.SUM_MASS.@y",
// 					IsReadOnly = true
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.Input.INPUT_BASIS.@y",
// 						Value = "MOLAR",
// 						Operator = CxvLogicalOperator.Equal
// 					}
// 				},
// 				Operator = CxvLogicalOperator.And,
// 				Property = new CxvVariableProperty
// 				{
// 					DataPath = "@main.Input.SUM_MOLE.@y",
// 					IsReadOnly = true
// 				}
// 			}
// 		}
// 	});
// }

// 0x060004b5 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdMolar_GridData_ItemTemplate..ctor
// public grdMolar_GridData_ItemTemplate()
// {
// }

// 0x060004b6 AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdMolar_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMolar_GridData_ItemTemplate()
// {
// 	txtCompIDMolar_var1_Property = CxvPropertyDeclaration.Register("txtCompIDMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.PHASE.@y",
// 		IsReadOnly = true
// 	});
// 	txtCarbonMolar_var1_Property = CxvPropertyDeclaration.Register("txtCarbonMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NOATOMCBASE1.@y",
// 		IsReadOnly = true
// 	});
// 	txtHydrogenMolar_var1_Property = CxvPropertyDeclaration.Register("txtHydrogenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NOATOMCBASE2.@y",
// 		IsReadOnly = true
// 	});
// 	txtOxygenMolar_var1_Property = CxvPropertyDeclaration.Register("txtOxygenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NOATOMCBASE3.@y",
// 		IsReadOnly = true
// 	});
// 	txtNitrogenMolar_var1_Property = CxvPropertyDeclaration.Register("txtNitrogenMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NOATOMCBASE4.@y",
// 		IsReadOnly = true
// 	});
// 	txtAshMolar_var1_Property = CxvPropertyDeclaration.Register("txtAshMolar_var1", typeof(grdMolar_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NOATOMCBASE5.@y",
// 		IsReadOnly = true
// 	});
// }

// 0x060004bd AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdMass_GridData_ItemTemplate..ctor
// public grdMass_GridData_ItemTemplate()
// {
// }

// 0x060004be AspenTech.AspenPlus.MMForms.Components.Bio_Comps.MMBioComp_Input_Spec_ViewModel+grdMass_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMass_GridData_ItemTemplate()
// {
// 	txtCompIDMass_var1_Property = CxvPropertyDeclaration.Register("txtCompIDMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.PHASE.@y",
// 		IsReadOnly = true
// 	});
// 	txtCarbonMass_var1_Property = CxvPropertyDeclaration.Register("txtCarbonMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUES1.@y",
// 		IsReadOnly = true
// 	});
// 	txtHydrogenMass_var1_Property = CxvPropertyDeclaration.Register("txtHydrogenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUES2.@y",
// 		IsReadOnly = true
// 	});
// 	txtOxygenMass_var1_Property = CxvPropertyDeclaration.Register("txtOxygenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUES3.@y",
// 		IsReadOnly = true
// 	});
// 	txtNitrogenMass_var1_Property = CxvPropertyDeclaration.Register("txtNitrogenMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUES4.@y",
// 		IsReadOnly = true
// 	});
// 	txtAshMass_var1_Property = CxvPropertyDeclaration.Register("txtAshMass_var1", typeof(grdMass_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VALUES5.@y",
// 		IsReadOnly = true
// 	});
// }

// 0x060004c2 AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_Create_ViewModel+MMScrollArea_GridData_ItemTemplate..ctor
// public MMScrollArea_GridData_ItemTemplate()
// {
// }

// 0x060004c3 AspenTech.AspenPlus.MMForms.Components.Attr_Scaling.MMAttrScal_Input_Create_ViewModel+MMScrollArea_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea_GridData_ItemTemplate()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.SCALE.@compid.@y"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.UPPER.@compid.@y"
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SCALE.@compid.@y"
// 	});
// }

// 0x060004c6 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060004c7 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.TYPE_LIST.@y"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CompAttrChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.TYPE_LIST.@y",
// 			UseChildId = true,
// 			Name = "uid"
// 		},
// 		AllowCollectionChange = false
// 	});
// }

// 0x060004c9 AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060004ca AspenTech.AspenPlus.MMForms.Components.Attr_Comps.MMCompAttr_Input_Create_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.TYPE_LIST.@y.@uid"
// 	});
// }

// 0x060004cd AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Distl_ViewModel+grdDistCurve_GridData_ItemTemplate..ctor
// public grdDistCurve_GridData_ItemTemplate()
// {
// }

// 0x060004ce AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Distl_ViewModel+grdDistCurve_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdDistCurve_GridData_ItemTemplate()
// {
// 	_txtPCTDIST_PCT_DIST_Property = CxvPropertyDeclaration.Register("_txtPCTDIST_PCT_DIST", typeof(grdDistCurve_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.TEMP.@y"
// 	});
// 	txtTEMP_var1_Property = CxvPropertyDeclaration.Register("txtTEMP_var1", typeof(grdDistCurve_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@y"
// 	});
// }

// 0x060004d1 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdAPI_GridData_ItemTemplate..ctor
// public grdAPI_GridData_ItemTemplate()
// {
// }

// 0x060004d2 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdAPI_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAPI_GridData_ItemTemplate()
// {
// 	txtAPI_APICURVE_Property = CxvPropertyDeclaration.Register("txtAPI_APICURVE", typeof(grdAPI_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MID_API.@y"
// 	});
// 	txtAPIPctDist_PctDist_Property = CxvPropertyDeclaration.Register("txtAPIPctDist_PctDist", typeof(grdAPI_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.MID_API.@y"
// 	});
// }

// 0x060004d5 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdSG_GridData_ItemTemplate..ctor
// public grdSG_GridData_ItemTemplate()
// {
// }

// 0x060004d6 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdSG_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSG_GridData_ItemTemplate()
// {
// 	txtSGvalue_var1_Property = CxvPropertyDeclaration.Register("txtSGvalue_var1", typeof(grdSG_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MID_GRAV.@y"
// 	});
// 	txtSGMidDist_var1_Property = CxvPropertyDeclaration.Register("txtSGMidDist_var1", typeof(grdSG_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.MID_GRAV.@y"
// 	});
// }

// 0x060004d9 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdUOPK_GridData_ItemTemplate..ctor
// public grdUOPK_GridData_ItemTemplate()
// {
// }

// 0x060004da AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_Grav_ViewModel+grdUOPK_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdUOPK_GridData_ItemTemplate()
// {
// 	txtUOPK_UOPK_Property = CxvPropertyDeclaration.Register("txtUOPK_UOPK", typeof(grdUOPK_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MID_UOPK.@y"
// 	});
// 	txtUOPKPctDist_MidPct_Property = CxvPropertyDeclaration.Register("txtUOPKPctDist_MidPct", typeof(grdUOPK_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.MID_UOPK.@y"
// 	});
// }

// 0x060004df AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_LEnds_ViewModel+grdLEnds_GridData_ItemTemplate..ctor
// public grdLEnds_GridData_ItemTemplate()
// {
// }

// 0x060004e0 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_LEnds_ViewModel+grdLEnds_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLEnds_GridData_ItemTemplate()
// {
// 	cboCompID_cid_Property = CxvPropertyDeclaration.Register("cboCompID_cid", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.FRAC.@y"
// 	});
// 	txtMW_LEBMW_Property = CxvPropertyDeclaration.Register("txtMW_LEBMW", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LEBMW.@y"
// 	});
// 	txtGRAV_LEBGRAV_Property = CxvPropertyDeclaration.Register("txtGRAV_LEBGRAV", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LEBGRAV.@y"
// 	});
// 	txtFRAC_FRAC_Property = CxvPropertyDeclaration.Register("txtFRAC_FRAC", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FRAC.@y"
// 	});
// }

// 0x060004e3 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_MW_ViewModel+grdMWMW_GridData_ItemTemplate..ctor
// public grdMWMW_GridData_ItemTemplate()
// {
// }

// 0x060004e4 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_BasicD_MW_ViewModel+grdMWMW_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdMWMW_GridData_ItemTemplate()
// {
// 	txtMW_MW_MW_Property = CxvPropertyDeclaration.Register("txtMW_MW_MW", typeof(grdMWMW_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MW_MW.@y"
// 	});
// 	txtPCTDIST_PctDist_Property = CxvPropertyDeclaration.Register("txtPCTDIST_PctDist", typeof(grdMWMW_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.MW_MW.@y"
// 	});
// }

// 0x060004ea AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel+grdChild_GridData_ItemTemplate..ctor
// public grdChild_GridData_ItemTemplate()
// {
// }

// 0x060004eb AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_List2D_ViewModel+grdChild_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdChild_GridData_ItemTemplate()
// {
// 	txtName_var1_Property = CxvPropertyDeclaration.Register("txtName_var1", typeof(grdChild_GridData_ItemTemplate), new CxvCustomTooltipProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.@y"
// 	});
// 	txtType_VarCol1_Property = CxvPropertyDeclaration.Register("txtType_VarCol1", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y",
// 		DataAttribute = "type",
// 		IsReadOnly = true
// 	});
// 	cboStatus_Status_Property = CxvPropertyDeclaration.Register("cboStatus_Status", typeof(grdChild_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.@y",
// 		DataAttribute = "status",
// 		IsReadOnly = true
// 	});
// }

// 0x060004f7 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Petro_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060004f8 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Petro_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox2_PROP_VALUE_Property = CxvPropertyDeclaration.Register("MMTextBox2_PROP_VALUE", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PROP_VALUE.@PropIDX.@y"
// 	});
// 	MMTextBox1_PMID_PCT_Property = CxvPropertyDeclaration.Register("MMTextBox1_PMID_PCT", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PMID_PCT.@PropIDX.@y"
// 	});
// }

// 0x060004fb AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel+grdAVisc_GridData_ItemTemplate..ctor
// public grdAVisc_GridData_ItemTemplate()
// {
// }

// 0x060004fc AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel+grdAVisc_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAVisc_GridData_ItemTemplate()
// {
// 	txtAVisc_VISCOSITY_Property = CxvPropertyDeclaration.Register("txtAVisc_VISCOSITY", typeof(grdAVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VISCOSITY.@tempid.@y"
// 	});
// 	txtMidPctAvisc_MidPct_Property = CxvPropertyDeclaration.Register("txtMidPctAvisc_MidPct", typeof(grdAVisc_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.VISCOSITY.@tempid.@y"
// 	});
// }

// 0x060004ff AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000500 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Proper_Visc_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox2_MidPct_Property = CxvPropertyDeclaration.Register("MMTextBox2_MidPct", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.RealId,
// 		DataPath = "@main.Input.KVISCOSITY.@ktempid.@y"
// 	});
// 	MMTextBox1_KVISCOSITY_Property = CxvPropertyDeclaration.Register("MMTextBox1_KVISCOSITY", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.KVISCOSITY.@ktempid.@y"
// 	});
// }

// 0x06000508 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Curve_ViewModel+grdResults_GridData_ItemTemplate..ctor
// public grdResults_GridData_ItemTemplate()
// {
// }

// 0x06000509 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Curve_ViewModel+grdResults_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdResults_GridData_ItemTemplate()
// {
// 	txtCol_5_var1_Property = CxvPropertyDeclaration.Register("txtCol_5_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col5.@y"
// 	});
// 	txtCol_4_var1_Property = CxvPropertyDeclaration.Register("txtCol_4_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col4.@y"
// 	});
// 	txtCol_3_var1_Property = CxvPropertyDeclaration.Register("txtCol_3_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col3.@y"
// 	});
// 	txtCol_2_var1_Property = CxvPropertyDeclaration.Register("txtCol_2_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col2.@y"
// 	});
// 	txtCol_1_var1_Property = CxvPropertyDeclaration.Register("txtCol_1_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col1.@y"
// 	});
// 	txtCol_0_var1_Property = CxvPropertyDeclaration.Register("txtCol_0_var1", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.@col0.@y"
// 	});
// 	txtDistilled_DIST_RATIO_Property = CxvPropertyDeclaration.Register("txtDistilled_DIST_RATIO", typeof(grdResults_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.DIST_RATIO.@y"
// 	});
// }

// 0x0600050e AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Light_ViewModel+grdAssay_GridData_ItemTemplate..ctor
// public grdAssay_GridData_ItemTemplate()
// {
// }

// 0x0600050f AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Light_ViewModel+grdAssay_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdAssay_GridData_ItemTemplate()
// {
// 	MMTextBox1_TLVCONC_Property = CxvPropertyDeclaration.Register("MMTextBox1_TLVCONC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.TLVCONC.@y"
// 	});
// 	txtMoleFrac_MOLEFRAC_Property = CxvPropertyDeclaration.Register("txtMoleFrac_MOLEFRAC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MOLEFRAC.@y"
// 	});
// 	txtWtPct_MASSFRAC_Property = CxvPropertyDeclaration.Register("txtWtPct_MASSFRAC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MASSFRAC.@y"
// 	});
// 	txtVolPct_TLVCONC_Property = CxvPropertyDeclaration.Register("txtVolPct_TLVCONC", typeof(grdAssay_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.TLVCONC.@y"
// 	});
// }

// 0x06000514 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Pseudo_ViewModel+grdPCBreakdown_GridData_ItemTemplate..ctor
// public grdPCBreakdown_GridData_ItemTemplate()
// {
// }

// 0x06000515 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMAssay_Result_Pseudo_ViewModel+grdPCBreakdown_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdPCBreakdown_GridData_ItemTemplate()
// {
// 	txtCID_CID_Property = CxvPropertyDeclaration.Register("txtCID_CID", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPID.@y"
// 	});
// 	txtMolePct_MOLEFRAC_Property = CxvPropertyDeclaration.Register("txtMolePct_MOLEFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MOLEFRAC2.@y"
// 	});
// 	txtWtPct_MASSFRAC_Property = CxvPropertyDeclaration.Register("txtWtPct_MASSFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.MASSFRAC2.@y"
// 	});
// 	txtVolPCt_VOLFRAC_Property = CxvPropertyDeclaration.Register("txtVolPCt_VOLFRAC", typeof(grdPCBreakdown_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.VOLFRAC.@y"
// 	});
// }

// 0x06000518 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_Spec_ViewModel+grdBlendComposition_GridData_ItemTemplate..ctor
// public grdBlendComposition_GridData_ItemTemplate()
// {
// }

// 0x06000519 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Mixtur_Spec_ViewModel+grdBlendComposition_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdBlendComposition_GridData_ItemTemplate()
// {
// 	txtPct_Basis_Frac_Property = CxvPropertyDeclaration.Register("txtPct_Basis_Frac", typeof(grdBlendComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BASIS_FRAC.@y"
// 	});
// 	cboAID_AID_Property = CxvPropertyDeclaration.Register("cboAID_AID", typeof(grdBlendComposition_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.BASIS_FRAC.@y"
// 	});
// }

// 0x0600051d AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_Blend_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x0600051e AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMBlend_Result_Blend_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox1_COMPID_Property = CxvPropertyDeclaration.Register("MMTextBox1_COMPID", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.COMPFRAC.@y"
// 	});
// 	MMTextBox3_COMPTYPE_Property = CxvPropertyDeclaration.Register("MMTextBox3_COMPTYPE", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPTYPE.@y"
// 	});
// 	MMTextBox2_COMPFRAC_Property = CxvPropertyDeclaration.Register("MMTextBox2_COMPFRAC", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC.@y"
// 	});
// }

// 0x06000521 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_Specif_ViewModel+grdLEnds_GridData_ItemTemplate..ctor
// public grdLEnds_GridData_ItemTemplate()
// {
// }

// 0x06000522 AspenTech.AspenPlus.MMForms.Components.AssayBlend.MMLeprop_Specif_Specif_ViewModel+grdLEnds_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdLEnds_GridData_ItemTemplate()
// {
// 	txtFRAC_var1_Property = CxvPropertyDeclaration.Register("txtFRAC_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PROP_VALUE.@strPID.@y"
// 	});
// 	cboCompID_var1_Property = CxvPropertyDeclaration.Register("cboCompID_var1", typeof(grdLEnds_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.IdWithOptions,
// 		DataPath = "@main.Input.PROP_VALUE.@strPID.@y"
// 	});
// }
