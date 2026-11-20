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
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Markup;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenCxs.CxsViewModel.ViewData;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.Localization.Properties;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.ViewModelExtensions;
using AspenTech.WpfControls.Engineering;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Blocks.Mix_Split")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Blocks.Mix_Split")]
[assembly: AssemblyCopyright("Copyright © AspenTech 2009 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/mix_split", "AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/mix_split", "AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/mix_split", "AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/mix_split", "AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/mix_split", "AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit")]
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
namespace AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit
{
	public class MMSsplit_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SPEC"
		});

		public static readonly CxvPropertyDeclaration defkey_Property = CxvPropertyDeclaration.Register("defkey", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DEFK"
		});

		public static readonly CxvPropertyDeclaration keyloc_Property = CxvPropertyDeclaration.Register("keyloc", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.KEYLOC"
		});

		public static readonly CxvPropertyDeclaration entflsh_Property = CxvPropertyDeclaration.Register("entflsh", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLSH"
		});

		public static readonly CxvPropertyDeclaration entkey_Property = CxvPropertyDeclaration.Register("entkey", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTKEY"
		});

		public static readonly CxvPropertyDeclaration STRMID_Property = CxvPropertyDeclaration.Register("STRMID", typeof(MMSsplit_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "STRMID"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entflsh" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@defkey" },
			AccessibleDataPaths = { "@keyloc" },
			EnteredDataPaths = { "@entkey" }
		});

		public object spec => GetValue(spec_Property);

		public object defkey => GetValue(defkey_Property);

		public object keyloc => GetValue(keyloc_Property);

		public object entflsh => GetValue(entflsh_Property);

		public object entkey => GetValue(entkey_Property);

		public object STRMID => GetValue(STRMID_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMSsplit.MMSsplit_Input")]
	public class MMSsplit_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSsplit_Input()
		{
			base.ViewModelType = typeof(MMSsplit_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSsplit_Input_FlashO_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Input.NPHASE"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Input.PHASE"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var3",
					DataPath = "@main.Input.BLKOPFREWAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_e",
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
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations. ",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations. ",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__a",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES"
		});

		public static readonly CxvPropertyDeclaration lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL"
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT"
		});

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object lbtuTol_var1 => GetValue(lbtuTol_var1_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);
	}
	[ProgId("MMSsplit.MMSsplit_Input_FlashO")]
	public class MMSsplit_Input_FlashO : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmSpec;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMGroupBox frmConv;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTol_label;

		internal MMVariableEdit lbtuTol;

		private bool _contentLoaded;

		public MMSsplit_Input_FlashO()
		{
			base.ViewModelType = typeof(MMSsplit_Input_FlashO_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_input_flasho.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				frmSpec = (MMGroupBox)target;
				break;
			case 2:
				lbtuPres_label = (MMLabel)target;
				break;
			case 3:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 4:
				cboPhase_label = (MMLabel)target;
				break;
			case 5:
				cboPhase = (MMComboEdit)target;
				break;
			case 6:
				frmConv = (MMGroupBox)target;
				break;
			case 7:
				spnMaxit_label = (MMLabel)target;
				break;
			case 8:
				spnMaxit = (MMSpinBox)target;
				break;
			case 9:
				lbtuTol_label = (MMLabel)target;
				break;
			case 10:
				lbtuTol = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSsplit_Input_KeyCom_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraKeyComps_KEY_Property = CxvPropertyDeclaration.Register("fraKeyComps_KEY", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvParameterProperty
		{
			Parameter = "KEY"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvParameterProperty
		{
			Parameter = "KEY"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.COMPS",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Key component number:",
			CreateNewPromptResourceKey = "MMSsplit_Input_KeyCom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Key_component_number_",
			CompletePaths = { "DEFK1" }
		});

		public static readonly CxvPropertyDeclaration lstpComps_state_Property = CxvPropertyDeclaration.Register("lstpComps_state", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "KEY",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration lstpComps_var1_Property = CxvPropertyDeclaration.Register("lstpComps_var1", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.COMPS.@KEY"
		});

		public object fraKeyComps_KEY => GetValue(fraKeyComps_KEY_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object lstpComps_state => GetValue(lstpComps_state_Property);

		public object lstpComps_var1 => GetValue(lstpComps_var1_Property);
	}
	[ProgId("MMSsplit.MMSsplit_Input_KeyCom")]
	public class MMSsplit_Input_KeyCom : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraKeyComps;

		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMListPicker lstpComps;

		private bool _contentLoaded;

		public MMSsplit_Input_KeyCom()
		{
			base.ViewModelType = typeof(MMSsplit_Input_KeyCom_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_input_keycom.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraKeyComps = (MMGroupBox)target;
				break;
			case 2:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 3:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 4:
				lstpComps = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSsplit_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdSplit_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtStream_var1_Property = CxvPropertyDeclaration.Register("txtStream_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FRAC.@STRMID.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration txtKey_var1_Property = CxvPropertyDeclaration.Register("txtKey_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.BASIS_KEYNO.@STRMID.@y"
			});

			public static readonly CxvPropertyDeclaration spcSpec_Property = CxvPropertyDeclaration.Register("spcSpec", typeof(grdSplit_GridData_ItemTemplate), new CxvSpecProperty
			{
				Options = 
				{
					new CxvSpecOption
					{
						Display = "Split fraction",
						DisplayResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
						DataPath = "@main.Input.FRAC.@STRMID.@y"
					},
					new CxvSpecOption
					{
						Display = "Flow",
						DisplayResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
						DataPath = "@main.Input.BASIS_FLOW.@STRMID.@y",
						BasisPath = "@main.Input.FLOW_BASIS.@STRMID.@y"
					}
				}
			});

			public object txtStream_var1 => GetValue(txtStream_var1_Property);

			public object txtKey_var1 => GetValue(txtKey_var1_Property);

			public object spcSpec => GetValue(spcSpec_Property);
		}

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSsplit_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "STRMID"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSsplit_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FRAC",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Stream names:",
			CreateNewPromptResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_names_"
		});

		public static readonly CxvPropertyDeclaration grdSplit_GridData_Property = CxvPropertyDeclaration.Register("grdSplit_GridData", typeof(MMSsplit_Input_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSplit_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FRAC.@STRMID",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object grdSplit_GridData => GetValue(grdSplit_GridData_Property);
	}
	[ProgId("MMSsplit.MMSsplit_Input_Specif")]
	public class MMSsplit_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMMenuButton1_label;

		internal MMComboEdit MMMenuButton1;

		internal MMScrollArea grdSplit;

		private bool _contentLoaded;

		public MMSsplit_Input_Specif()
		{
			base.ViewModelType = typeof(MMSsplit_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_input_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				MMMenuButton1 = (MMComboEdit)target;
				break;
			case 4:
				grdSplit = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSsplit_Result_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMSsplit.MMSsplit_Result")]
	public class MMSsplit_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMSsplit_Result()
		{
			base.ViewModelType = typeof(MMSsplit_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSsplit_Result_Summar_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_0_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_0_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.STREAMFRAC.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Output.STREAMFRAC.#0",
					UseChildId = true,
					Name = "x"
				}
			});

			public object MMTextBox1_0_var1 => GetValue(MMTextBox1_0_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_1_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "x"
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.STREAMFRAC.@y.@x"
			});

			public object MMTextBox1_1_var1 => GetValue(MMTextBox1_1_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSsplit_Result_Summar_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.STREAMFRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMSsplit.MMSsplit_Result_Summar")]
	public class MMSsplit_Result_Summar : MMTabPage, IComponentConnector
	{
		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMSsplit_Result_Summar()
		{
			base.ViewModelType = typeof(MMSsplit_Result_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/ssplit/mmssplit_result_summar.xaml", UriKind.Relative);
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
}
namespace AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep
{
	public class MMSep_Blocko_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKPR"
		});

		public static readonly CxvPropertyDeclaration entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKSI"
		});

		public static readonly CxvPropertyDeclaration entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKDG"
		});

		public static readonly CxvPropertyDeclaration entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKRP"
		});

		public static readonly CxvPropertyDeclaration genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GENBLKOP"
		});

		public static readonly CxvPropertyDeclaration entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTIPT"
		});

		public static readonly CxvPropertyDeclaration entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTADD"
		});

		public static readonly CxvPropertyDeclaration entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTEOMOD"
		});

		public static readonly CxvPropertyDeclaration entopopt_Property = CxvPropertyDeclaration.Register("entopopt", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTOPOPT"
		});

		public static readonly CxvPropertyDeclaration eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EODEF"
		});

		public static readonly CxvPropertyDeclaration eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT"
		});

		public static readonly CxvPropertyDeclaration varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMSep_Blocko_ViewModel), new CxvParameterProperty
		{
			Parameter = "varno"
		});

		public static readonly CxvPropertyDeclaration sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMENT"
		});

		public static readonly CxvPropertyDeclaration smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMSPEC"
		});

		public static readonly CxvPropertyDeclaration l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.L2CP2"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@blkops", "@genblk" },
			EnteredDataPaths = { "@entpro" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsim" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdia" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@l2cp2", "@smspec" },
			EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@entopopt", "@sment" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@eodef" },
			EnteredDataPaths = { "@eoent" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entrep" }
		});

		public object blkops => GetValue(blkops_Property);

		public object entpro => GetValue(entpro_Property);

		public object entsim => GetValue(entsim_Property);

		public object entdia => GetValue(entdia_Property);

		public object entrep => GetValue(entrep_Property);

		public object genblk => GetValue(genblk_Property);

		public object entitp => GetValue(entitp_Property);

		public object entadd => GetValue(entadd_Property);

		public object entmod => GetValue(entmod_Property);

		public object entopopt => GetValue(entopopt_Property);

		public object eodef => GetValue(eodef_Property);

		public object eoent => GetValue(eoent_Property);

		public object varno => GetValue(varno_Property);

		public object sment => GetValue(sment_Property);

		public object smspec => GetValue(smspec_Property);

		public object l2cp2 => GetValue(l2cp2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);
	}
	[ProgId("MMSep.MMSep_BlockO")]
	public class MMSep_Blocko : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMSep_Blocko()
		{
			base.ViewModelType = typeof(MMSep_Blocko_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_blocko.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMSep_Eoopti_Model_ViewModel : MMTabPageViewModel
	{
		public class grdScMeth_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FILE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase,
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.FILESC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.LOCALSCRIPT.@y",
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.LOCASC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MultimapOptionScriptType",
						DataPath = "@main.Input.SC_TYPE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Localscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
						Value = "LOCALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "LOCALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Globalscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
						Value = "GLOBALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "GLOBALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "File",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
						Value = "FILE",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "FILE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.GLOBALSCRIPT.@y",
				DisplayedCase = CxsDisplayedCase.Lowercase,
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.GLOBSC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.USER_METHOD.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox5_var1",
						DataPath = "@main.Input.SC_METHOD.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "INIT",
						DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
						Value = "MMComboBox5_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "INIT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "PRESOLVE",
						DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
						Value = "MMComboBox5_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "PRESOLVE"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "POSTSOLVE",
						DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
						Value = "MMComboBox5_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "POSTSOLVE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.GLOBSC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.GLOBALSCRIPT.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.LOCASC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.LOCALSCRIPT.@y"
						}
					}
				}
			});

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

			public object MMComboBox4_var1 => GetValue(MMComboBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMComboBox5_MultiMap => GetValue(MMComboBox5_MultiMap_Property);

			public object ID => GetValue(ID_Property);
		}

		private ICommand _cmdAddOpt_Command;

		private ICommand _cmdAddVar_Command;

		private ICommand _cmdAddInput_Command;

		private ICommand _cmdOutStr_Command;

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSep_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
		{
			DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMSep_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
					DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
					DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_COMPS_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_COMPS"
		});

		public static readonly CxvPropertyDeclaration cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RTOPT"
			}
		});

		public static readonly CxvPropertyDeclaration grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdScMeth_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.SC_METHOD",
				UseChildId = true,
				Name = "y"
			}
		});

		private DelegateCommand<object> _cmdEdit_Command;

		private ObservableCollection<int> _selectedRowIndexes;

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

		public ICommand cmdAddVar_Command
		{
			get
			{
				if (_cmdAddVar_Command == null)
				{
					_cmdAddVar_Command = new CxvDelegateCommand<object>(cmdAddVar_CommandExecute);
				}
				return _cmdAddVar_Command;
			}
		}

		public ICommand cmdAddInput_Command
		{
			get
			{
				if (_cmdAddInput_Command == null)
				{
					_cmdAddInput_Command = new CxvDelegateCommand<object>(cmdAddInput_CommandExecute);
				}
				return _cmdAddInput_Command;
			}
		}

		public ICommand cmdOutStr_Command
		{
			get
			{
				if (_cmdOutStr_Command == null)
				{
					_cmdOutStr_Command = new CxvDelegateCommand<object>(cmdOutStr_CommandExecute);
				}
				return _cmdOutStr_Command;
			}
		}

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMComboBox6_MultiMap => GetValue(MMComboBox6_MultiMap_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cmdAddVar_var1 => GetValue(cmdAddVar_var1_Property);

		public object grdScMeth_GridData => GetValue(grdScMeth_GridData_Property);

		public DelegateCommand<object> cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new DelegateCommand<object>(cmdEdit_CommandExecute, cmdEdit_CommandCanExecute);
				}
				return _cmdEdit_Command;
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
					_selectedRowIndexes = value;
					_selectedRowIndexes.CollectionChanged -= delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
					_selectedRowIndexes.CollectionChanged += delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
				}
			}
		}

		private void cmdAddOpt_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddOpt",
				LegacyFlags = 0,
				HelpId = 177,
				HelpFile = "common.hlp",
				ShowPrompts = true,
				CompleteDataPaths = new string[1] { "@main.CC Nodes.l2cp2" },
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AdditionalOptions
			});
		}

		private void cmdAddVar_CommandExecute(object parameter)
		{
			string text = ExpandDataPathAndGet("@main", "type") as string;
			if (!string.IsNullOrEmpty(text))
			{
				DisplayFormEventArgs e = new DisplayFormEventArgs();
				e.LegacyFlags = 0;
				switch (text.ToUpperInvariant())
				{
				case "MIXER":
					e.FormProgId = "MMMixer.MMMixer_RTOpt_Input";
					break;
				case "HEATER":
				case "FLASH2":
					e.FormProgId = "MMFlash2.MMFlash2_RTOpt_Input";
					break;
				case "FSPLIT":
					e.FormProgId = "MMFSplit.MMFSplit_RTOpt_Input";
					break;
				case "STRVAR":
				case "FEEDBL":
					e.FormProgId = "MMStrvar.MMStrvar_RTOpt_Input";
					break;
				case "RADFRAC":
					e.FormProgId = "MMRadfrac.MMRadfrac_RTOpt";
					e.LegacyFlags = 4;
					break;
				}
				if (!string.IsNullOrEmpty(e.FormProgId))
				{
					e.HelpId = 186;
					e.HelpFile = "Common.hlp";
					e.ShowPrompts = true;
					e.ShortName = Resources.MMSep_Eoopti_Model_ViewModel_EOOptions;
					DisplayForm(e);
				}
			}
		}

		private void cmdAddInput_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddInp",
				LegacyFlags = 0,
				HelpId = 193,
				HelpFile = "common.hlp",
				ShowPrompts = true,
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AddInput
			});
		}

		private void cmdOutStr_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMSep.MMSep_Eoopti_OutStr",
				LegacyFlags = 0,
				HelpId = 17,
				HelpFile = "Common.hlp",
				ShowPrompts = true,
				ShortName = Resources.MMSep_Eoopti_Model_ViewModel_EOOptions_Outlet_stream_components,
				ResizeMode = ResizeMode.CanResize
			});
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (_selectedRowIndexes.Count != 1)
			{
				return;
			}
			int num = _selectedRowIndexes[0];
			if (num < 0)
			{
				return;
			}
			grdScMeth_GridData_ItemTemplate container = (grdScMeth_GridData as IList)[num] as grdScMeth_GridData_ItemTemplate;
			string strA = container.ResolveViewPropertyPath("MMComboBox2_var1.Value") as string;
			string text = container.ResolveViewPropertyPath("ID.Value") as string;
			string text2 = CxsConverter.ValueToString(ResolveParameter("main", null));
			int num2 = text2.LastIndexOf("Data");
			text2 = ((num2 <= 0) ? "Top.appModelV8" : text2.Substring(0, num2 + 4));
			text2 += ".EO Configuration.";
			if (string.Compare(strA, "LOCALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_LocScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_LocalScript
					};
					string text3 = text2 + "Local Scripts.";
					e.Parameters.Add("Input", text3 + text + ".Input");
					DisplayForm(e);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
			else if (string.Compare(strA, "GLOBALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e2 = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_GloScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_GlobalScript
					};
					string text4 = text2 + "Global Scripts.";
					e2.Parameters.Add("Input", text4 + text + ".Input");
					DisplayForm(e2);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
		}

		private bool cmdEdit_CommandCanExecute(object parameter)
		{
			if (_selectedRowIndexes != null && _selectedRowIndexes.Count == 1)
			{
				int num = _selectedRowIndexes[0];
				IList list = grdScMeth_GridData as IList;
				if (num >= 0 && num < list.Count - 1)
				{
					return string.Compare((list[num] as grdScMeth_GridData_ItemTemplate).ResolveViewPropertyPath("MMComboBox2_var1.Value") as string, "File", StringComparison.InvariantCultureIgnoreCase) != 0;
				}
			}
			return false;
		}
	}
	[ProgId("MMSep.MMSep_EOOpti_Model")]
	public class MMSep_Eoopti_Model : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMLBUText10_label;

		internal MMVariableEdit MMLBUText10;

		internal MMCmdButton cmdAddOpt;

		internal MMCmdButton cmdAddVar;

		internal MMCmdButton cmdAddInput;

		internal MMCmdButton cmdOutStr;

		internal MMGroupBox MMFrame2;

		internal MMScrollArea grdScMeth;

		internal MMCmdButton cmdEdit;

		private bool _contentLoaded;

		public MMSep_Eoopti_Model()
		{
			base.ViewModelType = typeof(MMSep_Eoopti_Model_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_eoopti_model.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
			case 9:
				cmdAddVar = (MMCmdButton)target;
				break;
			case 10:
				cmdAddInput = (MMCmdButton)target;
				break;
			case 11:
				cmdOutStr = (MMCmdButton)target;
				break;
			case 12:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 13:
				grdScMeth = (MMScrollArea)target;
				break;
			case 14:
				cmdEdit = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep_Eoopti_OutStr_ViewModel : MMTabPageViewModel
	{
		public class scaStreamCGI_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtStream_stream_Property = CxvPropertyDeclaration.Register("txtStream_stream", typeof(scaStreamCGI_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.STR_COMPS.@y"
			});

			public static readonly CxvPropertyDeclaration cboCGID_str_comps_Property = CxvPropertyDeclaration.Register("cboCGID_str_comps", typeof(scaStreamCGI_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.STR_COMPS.@y"
			});

			public object txtStream_stream => GetValue(txtStream_stream_Property);

			public object cboCGID_str_comps => GetValue(cboCGID_str_comps_Property);
		}

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration scaStreamCGI_GridData_Property = CxvPropertyDeclaration.Register("scaStreamCGI_GridData", typeof(MMSep_Eoopti_OutStr_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(scaStreamCGI_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.STR_COMPS",
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

		public object scaStreamCGI_GridData => GetValue(scaStreamCGI_GridData_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}
	}
	[ProgId("MMSep.MMSep_EOOpti_OutStr")]
	public class MMSep_Eoopti_OutStr : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmStreamCG;

		internal MMScrollArea scaStreamCGI;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMSep_Eoopti_OutStr()
		{
			base.ViewModelType = typeof(MMSep_Eoopti_OutStr_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_eoopti_outstr.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				frmStreamCG = (MMGroupBox)target;
				break;
			case 2:
				scaStreamCGI = (MMScrollArea)target;
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
	public class MMSep_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAINS"
		});

		public static readonly CxvPropertyDeclaration outfl_Property = CxvPropertyDeclaration.Register("outfl", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FLMAIN"
		});

		public static readonly CxvPropertyDeclaration entfd_Property = CxvPropertyDeclaration.Register("entfd", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFEED"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMSep_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration entutl_Property = CxvPropertyDeclaration.Register("entutl", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTUTL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entfd" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@outfl" },
			EnteredDataPaths = { "@entfls" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@utlred" },
			EnteredDataPaths = { "@entutl" }
		});

		public static readonly CxvPropertyDeclaration utlred_Property = CxvPropertyDeclaration.Register("utlred", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UTLRED"
		});

		public object spec => GetValue(spec_Property);

		public object outfl => GetValue(outfl_Property);

		public object entfd => GetValue(entfd_Property);

		public object entfls => GetValue(entfls_Property);

		public object choice => GetValue(choice_Property);

		public object entutl => GetValue(entutl_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object utlred => GetValue(utlred_Property);
	}
	[ProgId("MMSep.MMSep_Input")]
	public class MMSep_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSep_Input()
		{
			base.ViewModelType = typeof(MMSep_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMSep_Input_Feedfl_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSep_Input_Feedfl_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Input.NPHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Input.PHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var3",
					DataPath = "@main.Input.BLKOPFREWAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exis",
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
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_in",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_co",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__are",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__are",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__ar",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES1"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL1"
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT1"
		});

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);
	}
	[ProgId("MMSep.MMSep_Input_Feedfl")]
	public class MMSep_Input_Feedfl : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInlet;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMGroupBox fraFlashconv;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		private bool _contentLoaded;

		public MMSep_Input_Feedfl()
		{
			base.ViewModelType = typeof(MMSep_Input_Feedfl_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_input_feedfl.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraInlet = (MMGroupBox)target;
				break;
			case 2:
				lbtuPres_label = (MMLabel)target;
				break;
			case 3:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 4:
				cboPhase_label = (MMLabel)target;
				break;
			case 5:
				cboPhase = (MMComboEdit)target;
				break;
			case 6:
				fraFlashconv = (MMGroupBox)target;
				break;
			case 7:
				spnMaxit_label = (MMLabel)target;
				break;
			case 8:
				spnMaxit = (MMSpinBox)target;
				break;
			case 9:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep_Input_Outlet_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMFrame3_state_Property = CxvPropertyDeclaration.Register("MMFrame3_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.KOD.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTol_display_Property = CxvPropertyDeclaration.Register("lbtuTol_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL.@choice"
		});

		public static readonly CxvPropertyDeclaration spnMaxit_display_Property = CxvPropertyDeclaration.Register("spnMaxit_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT.@choice"
		});

		public static readonly CxvPropertyDeclaration MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.KOD.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuTest_var1_Property = CxvPropertyDeclaration.Register("lbtuTest_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.T_EST.@choice",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.TEST.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuPest_var1_Property = CxvPropertyDeclaration.Register("lbtuPest_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.P_EST.@choice",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.PEST.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration mnbStreamName_target_Property = CxvPropertyDeclaration.Register("mnbStreamName_target", typeof(MMSep_Input_Outlet_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration mnbStreamName_display_Property = CxvPropertyDeclaration.Register("mnbStreamName_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.NPHASE",
			SelectedItemBinding = "mnbStreamName_target.Value",
			CreateNewPrompt = "Stream:",
			CreateNewPromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_",
			CompletePaths = { "FLSP" }
		});

		public static readonly CxvPropertyDeclaration fraFlashSpec_state_Property = CxvPropertyDeclaration.Register("fraFlashSpec_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.KOD.@choice"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSep_Input_Outlet_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_nphase",
					DataPath = "@main.Input.NPHASE.@choice"
				},
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_phase",
					DataPath = "@main.Input.PHASE.@choice"
				},
				new CxvMultiMapVariable
				{
					Name = "MMComboBox1_freewater",
					DataPath = "@main.Input.FREE_WATER.@choice"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "MMComboBox1_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase",
							Value = "V"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "MMComboBox1_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "MMComboBox1_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exis",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase",
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "MMComboBox1_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_in",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "MMComboBox1_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_co",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "3"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "MMComboBox1_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are_",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "MMComboBox1_MultiMapOption_7",
					Prompt = "3 liquid phases (vapor, organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_liquid_phases__vapor__organic_and_pure_wate",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "MMComboBox1_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__are",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "1"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase",
							Value = "L"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "MMComboBox1_MultiMapOption_9",
					Prompt = "3 liquid phases (vapor, organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_liquid_phases__vapor__organic_and_dirty_wat",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_nphase",
							Value = "2"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_phase"
						},
						new CxvMultiMapValue
						{
							Variable = "MMComboBox1_freewater",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DELT.@choice"
		});

		public static readonly CxvPropertyDeclaration lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TEMP.@choice"
		});

		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES.@choice"
		});

		public static readonly CxvPropertyDeclaration lbtuVfrac_var1_Property = CxvPropertyDeclaration.Register("lbtuVfrac_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRAC.@choice"
		});

		public static readonly CxvPropertyDeclaration chkFlashStream_var1_Property = CxvPropertyDeclaration.Register("chkFlashStream_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.KODE.@choice",
			FalseValue = "NOFLASH",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "choice",
				Operator = CxvLogicalOperator.IdExists
			},
			DisabledPrompt = Resources.MMSep_Input_Outlet_ViewModel_chkFlashStream_var1_DisabledPrompt
		});

		public object MMFrame3_state => GetValue(MMFrame3_state_Property);

		public object lbtuTol_display => GetValue(lbtuTol_display_Property);

		public object spnMaxit_display => GetValue(spnMaxit_display_Property);

		public object MMFrame2_state => GetValue(MMFrame2_state_Property);

		public object lbtuTest_var1 => GetValue(lbtuTest_var1_Property);

		public object lbtuPest_var1 => GetValue(lbtuPest_var1_Property);

		public object mnbStreamName_target => GetValue(mnbStreamName_target_Property);

		public object mnbStreamName_display => GetValue(mnbStreamName_display_Property);

		public object fraFlashSpec_state => GetValue(fraFlashSpec_state_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object lbtuTemp_var1 => GetValue(lbtuTemp_var1_Property);

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object lbtuVfrac_var1 => GetValue(lbtuVfrac_var1_Property);

		public object chkFlashStream_var1 => GetValue(chkFlashStream_var1_Property);
	}
	[ProgId("MMSep.MMSep_Input_Outlet")]
	public class MMSep_Input_Outlet : MMTabPage, IComponentConnector
	{
		internal MMLabel mnbStreamName_label;

		internal MMAdvancedComboEdit mnbStreamName;

		internal MMCheckBox chkFlashStream;

		internal MMGroupBox fraFlashSpec;

		internal MMLabel lbtuTemp_label;

		internal MMVariableEdit lbtuTemp;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel lbtuVfrac_label;

		internal MMVariableEdit lbtuVfrac;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMGroupBox MMFrame2;

		internal MMLabel lbtuTest_label;

		internal MMVariableEdit lbtuTest;

		internal MMLabel lbtuPest_label;

		internal MMVariableEdit lbtuPest;

		internal MMGroupBox MMFrame3;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTol_label;

		internal MMVariableEdit lbtuTol;

		private bool _contentLoaded;

		public MMSep_Input_Outlet()
		{
			base.ViewModelType = typeof(MMSep_Input_Outlet_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_input_outlet.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mnbStreamName_label = (MMLabel)target;
				break;
			case 2:
				mnbStreamName = (MMAdvancedComboEdit)target;
				break;
			case 3:
				chkFlashStream = (MMCheckBox)target;
				break;
			case 4:
				fraFlashSpec = (MMGroupBox)target;
				break;
			case 5:
				lbtuTemp_label = (MMLabel)target;
				break;
			case 6:
				lbtuTemp = (MMVariableEdit)target;
				break;
			case 7:
				lbtuPres_label = (MMLabel)target;
				break;
			case 8:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 9:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 11:
				lbtuVfrac_label = (MMLabel)target;
				break;
			case 12:
				lbtuVfrac = (MMVariableEdit)target;
				break;
			case 13:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 14:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 15:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 16:
				lbtuTest_label = (MMLabel)target;
				break;
			case 17:
				lbtuTest = (MMVariableEdit)target;
				break;
			case 18:
				lbtuPest_label = (MMLabel)target;
				break;
			case 19:
				lbtuPest = (MMVariableEdit)target;
				break;
			case 20:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 21:
				spnMaxit_label = (MMLabel)target;
				break;
			case 22:
				spnMaxit = (MMSpinBox)target;
				break;
			case 23:
				lbtuTol_label = (MMLabel)target;
				break;
			case 24:
				lbtuTol = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdSpecs_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSpecs_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FRACS.@Stream.@Substr.@y"
			});

			public static readonly CxvPropertyDeclaration MMSpec1_Property = CxvPropertyDeclaration.Register("MMSpec1", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
			{
				Options = 
				{
					new CxvSpecOption
					{
						Display = "Split fraction",
						DisplayResourceKey = "MMSep_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
						DataPath = "@main.Input.FRACS.@Stream.@Substr.@y"
					},
					new CxvSpecOption
					{
						Display = "Flow",
						DisplayResourceKey = "MMSep_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
						DataPath = "@main.Input.FLOWS.@Stream.@Substr.@y",
						BasisPath = "@main.Input.FLOWBASIS.@Stream.@Substr.@y"
					}
				}
			});

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMSpec1 => GetValue(MMSpec1_Property);
		}

		public static readonly CxvPropertyDeclaration fraSpec_Stream_Property = CxvPropertyDeclaration.Register("fraSpec_Stream", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Stream"
		});

		public static readonly CxvPropertyDeclaration fraSpec_Substr_Property = CxvPropertyDeclaration.Register("fraSpec_Substr", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMSep_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FRACS.@Stream",
			SelectedItemBinding = "MMMenuButton2_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMSep_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Stream"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FRACS",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Outlet stream:",
			CreateNewPromptResourceKey = "MMSep_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Outlet_stream_"
		});

		public static readonly CxvPropertyDeclaration grdSpecs_GridData_Property = CxvPropertyDeclaration.Register("grdSpecs_GridData", typeof(MMSep_Input_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSpecs_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FRACS.@Stream.@Substr",
				UseChildId = true,
				Name = "y"
			}
		});

		public object fraSpec_Stream => GetValue(fraSpec_Stream_Property);

		public object fraSpec_Substr => GetValue(fraSpec_Substr_Property);

		public object MMMenuButton2_var2 => GetValue(MMMenuButton2_var2_Property);

		public object MMMenuButton2_var1 => GetValue(MMMenuButton2_var1_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object grdSpecs_GridData => GetValue(grdSpecs_GridData_Property);
	}
	[ProgId("MMSep.MMSep_Input_Specif")]
	public class MMSep_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraSpec;

		internal MMLabel MMMenuButton1_label;

		internal MMComboEdit MMMenuButton1;

		internal MMLabel MMMenuButton2_label;

		internal MMComboEdit MMMenuButton2;

		internal MMScrollArea grdSpecs;

		private bool _contentLoaded;

		public MMSep_Input_Specif()
		{
			base.ViewModelType = typeof(MMSep_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_input_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraSpec = (MMGroupBox)target;
				break;
			case 2:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 3:
				MMMenuButton1 = (MMComboEdit)target;
				break;
			case 4:
				MMMenuButton2_label = (MMLabel)target;
				break;
			case 5:
				MMMenuButton2 = (MMComboEdit)target;
				break;
			case 6:
				grdSpecs = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration utlusage_Property = CxvPropertyDeclaration.Register("utlusage", typeof(MMSep_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.UTL_USAGE"
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@utlusage" }
		});

		public object utlusage => GetValue(utlusage_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMSep.MMSep_Result")]
	public class MMSep_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResult;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMSep_Result()
		{
			base.ViewModelType = typeof(MMSep_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabResult = (MMTabStrip)target;
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
	public class MMSep_Result_Summar_ViewModel : MMTabPageViewModel
	{
		public class grdSpltFrac_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCompId_var1_Property = CxvPropertyDeclaration.Register("txtCompId_var1", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.COMPFRAC.@Substr2.@yy"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Output.COMPFRAC.@Substr2.#0",
					UseChildId = true,
					Name = "xx"
				}
			});

			public object txtCompId_var1 => GetValue(txtCompId_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtStreamId_var1_Property = CxvPropertyDeclaration.Register("txtStreamId_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "xx"
			});

			public static readonly CxvPropertyDeclaration txtCompfrac_var1_Property = CxvPropertyDeclaration.Register("txtCompfrac_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COMPFRAC.@Substr2.@yy.@xx"
			});

			public object txtStreamId_var1 => GetValue(txtStreamId_var1_Property);

			public object txtCompfrac_var1 => GetValue(txtCompfrac_var1_Property);
		}

		public static readonly CxvPropertyDeclaration fraFracRes_Substr2_Property = CxvPropertyDeclaration.Register("fraFracRes_Substr2", typeof(MMSep_Result_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep_Result_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep_Result_Summar_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Output.COMPFRAC",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMSep_Result_Summar_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
		});

		public static readonly CxvPropertyDeclaration grdSpltFrac_GridData_Property = CxvPropertyDeclaration.Register("grdSpltFrac_GridData", typeof(MMSep_Result_Summar_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSpltFrac_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.COMPFRAC.@Substr2",
				UseChildId = true,
				Name = "yy"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDuty_var1_Property = CxvPropertyDeclaration.Register("lbtuDuty_var1", typeof(MMSep_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.QCALC"
		});

		public object fraFracRes_Substr2 => GetValue(fraFracRes_Substr2_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object grdSpltFrac_GridData => GetValue(grdSpltFrac_GridData_Property);

		public object lbtuDuty_var1 => GetValue(lbtuDuty_var1_Property);
	}
	[ProgId("MMSep.MMSep_Result_Summar")]
	public class MMSep_Result_Summar : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuDuty_label;

		internal MMVariableEdit lbtuDuty;

		internal MMGroupBox fraFracRes;

		internal MMLabel MMMenuButton1_label;

		internal MMComboEdit MMMenuButton1;

		internal MMScrollArea grdSpltFrac;

		private bool _contentLoaded;

		public MMSep_Result_Summar()
		{
			base.ViewModelType = typeof(MMSep_Result_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep/mmsep_result_summar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuDuty_label = (MMLabel)target;
				break;
			case 2:
				lbtuDuty = (MMVariableEdit)target;
				break;
			case 3:
				fraFracRes = (MMGroupBox)target;
				break;
			case 4:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 5:
				MMMenuButton1 = (MMComboEdit)target;
				break;
			case 6:
				grdSpltFrac = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2
{
	public class MMSep2_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAINS"
		});

		public static readonly CxvPropertyDeclaration flash_Property = CxvPropertyDeclaration.Register("flash", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FLMAIN"
		});

		public static readonly CxvPropertyDeclaration entfd_Property = CxvPropertyDeclaration.Register("entfd", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFEED"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMSep2_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration entutl_Property = CxvPropertyDeclaration.Register("entutl", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTUTL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entfd" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@flash" },
			EnteredDataPaths = { "@entfls" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@utlred" },
			EnteredDataPaths = { "@entutl" }
		});

		public static readonly CxvPropertyDeclaration utlred_Property = CxvPropertyDeclaration.Register("utlred", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UTLRED"
		});

		public object spec => GetValue(spec_Property);

		public object flash => GetValue(flash_Property);

		public object entfd => GetValue(entfd_Property);

		public object entfls => GetValue(entfls_Property);

		public object choice => GetValue(choice_Property);

		public object entutl => GetValue(entutl_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object utlred => GetValue(utlred_Property);
	}
	[ProgId("MMSep2.MMSep2_Input")]
	public class MMSep2_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMSep2_Input()
		{
			base.ViewModelType = typeof(MMSep2_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep2/mmsep2_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMSep2_Input_Feedfl_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT1"
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL1"
		});

		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES1"
		});

		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Input.NPHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Input.PHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var3",
					DataPath = "@main.Input.BLKOPFREWAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exi",
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
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_i",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_c",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__ar",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__ar",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__a",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);
	}
	[ProgId("MMSep2.MMSep2_Input_Feedfl")]
	public class MMSep2_Input_Feedfl : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInlet;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMGroupBox fraFlashconv;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		private bool _contentLoaded;

		public MMSep2_Input_Feedfl()
		{
			base.ViewModelType = typeof(MMSep2_Input_Feedfl_ViewModel);
			InitializeComponent();
		}

		protected override void DoFocusFirstControl()
		{
			if (lbtuPres.Template.FindName("textBox", lbtuPres) is Control control && control.Template.FindName("PART_editControl", control) is Control element)
			{
				Keyboard.Focus(element);
			}
			base.DoFocusFirstControl();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep2/mmsep2_input_feedfl.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraInlet = (MMGroupBox)target;
				break;
			case 2:
				lbtuPres_label = (MMLabel)target;
				break;
			case 3:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 4:
				cboPhase_label = (MMLabel)target;
				break;
			case 5:
				cboPhase = (MMComboEdit)target;
				break;
			case 6:
				fraFlashconv = (MMGroupBox)target;
				break;
			case 7:
				spnMaxit_label = (MMLabel)target;
				break;
			case 8:
				spnMaxit = (MMSpinBox)target;
				break;
			case 9:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 10:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep2_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdSpecs_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSpecs_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FRACS.@Substr.@Stream.@y"
			});

			public static readonly CxvPropertyDeclaration spcSpec1_Property = CxvPropertyDeclaration.Register("spcSpec1", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
			{
				Options = 
				{
					new CxvSpecOption
					{
						Display = "Split fraction",
						DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_1",
						DataPath = "@main.Input.FRACS.@Substr.@Stream.@y"
					},
					new CxvSpecOption
					{
						Display = "Flow",
						DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Flow_1",
						DataPath = "@main.Input.FLOWS.@Substr.@Stream.@y",
						BasisPath = "@main.Input.FLOWBASIS.@Substr.@Stream.@y"
					}
				}
			});

			public static readonly CxvPropertyDeclaration spcSpec2_Property = CxvPropertyDeclaration.Register("spcSpec2", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
			{
				Options = 
				{
					new CxvSpecOption
					{
						Display = "Mole frac",
						DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Mole_frac",
						DataPath = "@main.Input.MFFRAC.@Substr.@Stream.@y"
					},
					new CxvSpecOption
					{
						Display = "Mass frac",
						DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Mass_frac",
						DataPath = "@main.Input.MAFRAC.@Substr.@Stream.@y"
					}
				}
			});

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object spcSpec1 => GetValue(spcSpec1_Property);

			public object spcSpec2 => GetValue(spcSpec2_Property);
		}

		public static readonly CxvPropertyDeclaration fraInput_Substr_Property = CxvPropertyDeclaration.Register("fraInput_Substr", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr"
		});

		public static readonly CxvPropertyDeclaration fraInput_Stream_Property = CxvPropertyDeclaration.Register("fraInput_Stream", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Stream"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Stream"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FRACS.@Substr",
			SelectedItemBinding = "MMMenuButton2_var2.Value",
			CreateNewPrompt = "Outlet stream:",
			CreateNewPromptResourceKey = "MMSep2_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Outlet_stream_"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FRACS",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMSep2_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
		});

		public static readonly CxvPropertyDeclaration spcStream_Property = CxvPropertyDeclaration.Register("spcStream", typeof(MMSep2_Input_Specif_ViewModel), new CxvSpecProperty
		{
			Options = 
			{
				new CxvSpecOption
				{
					Display = "Split fraction",
					DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
					DataPath = "@main.Input.FRAC.@Substr.@Stream"
				},
				new CxvSpecOption
				{
					Display = "Flow",
					DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
					DataPath = "@main.Input.FLOW.@Substr.@Stream",
					BasisPath = "@main.Input.FLOW_BASIS.@Substr.@Stream"
				}
			}
		});

		public static readonly CxvPropertyDeclaration spcStream_var1_Property = CxvPropertyDeclaration.Register("spcStream_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FRAC.@Substr.@Stream"
		});

		public static readonly CxvPropertyDeclaration spcStream_var2_Property = CxvPropertyDeclaration.Register("spcStream_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW.@Substr.@Stream"
		});

		public static readonly CxvPropertyDeclaration spcStream_var3_Property = CxvPropertyDeclaration.Register("spcStream_var3", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW_BASIS.@Substr.@Stream"
		});

		public static readonly CxvPropertyDeclaration grdSpecs_GridData_Property = CxvPropertyDeclaration.Register("grdSpecs_GridData", typeof(MMSep2_Input_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSpecs_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FRACS.@Substr.@Stream",
				UseChildId = true,
				Name = "y"
			}
		});

		public object fraInput_Substr => GetValue(fraInput_Substr_Property);

		public object fraInput_Stream => GetValue(fraInput_Stream_Property);

		public object MMMenuButton2_var2 => GetValue(MMMenuButton2_var2_Property);

		public object MMMenuButton2_var1 => GetValue(MMMenuButton2_var1_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object spcStream => GetValue(spcStream_Property);

		public object spcStream_var1 => GetValue(spcStream_var1_Property);

		public object spcStream_var2 => GetValue(spcStream_var2_Property);

		public object spcStream_var3 => GetValue(spcStream_var3_Property);

		public object grdSpecs_GridData => GetValue(grdSpecs_GridData_Property);
	}
	[ProgId("MMSep2.MMSep2_Input_Specif")]
	public class MMSep2_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInput;

		internal MMLabel MMMenuButton1_label;

		internal MMComboEdit MMMenuButton1;

		internal MMLabel MMMenuButton2_label;

		internal MMComboEdit MMMenuButton2;

		internal MMLabel lblStrSpec;

		internal MMComboEdit spcStream_combo;

		internal MMScrollArea grdSpecs;

		private bool _contentLoaded;

		public MMSep2_Input_Specif()
		{
			base.ViewModelType = typeof(MMSep2_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep2/mmsep2_input_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraInput = (MMGroupBox)target;
				break;
			case 2:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 3:
				MMMenuButton1 = (MMComboEdit)target;
				break;
			case 4:
				MMMenuButton2_label = (MMLabel)target;
				break;
			case 5:
				MMMenuButton2 = (MMComboEdit)target;
				break;
			case 6:
				lblStrSpec = (MMLabel)target;
				break;
			case 7:
				spcStream_combo = (MMComboEdit)target;
				break;
			case 8:
				grdSpecs = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMSep2_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration utlusage_Property = CxvPropertyDeclaration.Register("utlusage", typeof(MMSep2_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.UTL_USAGE"
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep2_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@utlusage" }
		});

		public object utlusage => GetValue(utlusage_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMSep2.MMSep2_Result")]
	public class MMSep2_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabResult;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMSep2_Result()
		{
			base.ViewModelType = typeof(MMSep2_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep2/mmsep2_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabResult = (MMTabStrip)target;
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
	public class MMSep2_Result_Summar_ViewModel : MMTabPageViewModel
	{
		public class grdSpltFrac_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtCompId_var1_Property = CxvPropertyDeclaration.Register("txtCompId_var1", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.COMPFRAC.@Substr2.@yy"
			});

			public static readonly CxvPropertyDeclaration inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVectorProperty
			{
				ItemType = typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate),
				IndexBasis = new CxvChildCountIndexBasis
				{
					DataPath = "@main.Output.COMPFRAC.@Substr2.#0",
					UseChildId = true,
					Name = "xx"
				}
			});

			public object txtCompId_var1 => GetValue(txtCompId_var1_Property);

			public object inner => GetValue(inner_Property);
		}

		public class grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration txtStreamId_var1_Property = CxvPropertyDeclaration.Register("txtStreamId_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
			{
				Parameter = "xx"
			});

			public static readonly CxvPropertyDeclaration txtCompfrac_var1_Property = CxvPropertyDeclaration.Register("txtCompfrac_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.COMPFRAC.@Substr2.@yy.@xx"
			});

			public object txtStreamId_var1 => GetValue(txtStreamId_var1_Property);

			public object txtCompfrac_var1 => GetValue(txtCompfrac_var1_Property);
		}

		public static readonly CxvPropertyDeclaration lbtuDuty_var1_Property = CxvPropertyDeclaration.Register("lbtuDuty_var1", typeof(MMSep2_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.QCALC"
		});

		public static readonly CxvPropertyDeclaration fraFracRes_Substr2_Property = CxvPropertyDeclaration.Register("fraFracRes_Substr2", typeof(MMSep2_Result_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep2_Result_Summar_ViewModel), new CxvParameterProperty
		{
			Parameter = "Substr2"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep2_Result_Summar_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Output.COMPFRAC",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMSep2_Result_Summar_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
		});

		public static readonly CxvPropertyDeclaration grdSpltFrac_GridData_Property = CxvPropertyDeclaration.Register("grdSpltFrac_GridData", typeof(MMSep2_Result_Summar_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSpltFrac_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.COMPFRAC.@Substr2",
				UseChildId = true,
				Name = "yy"
			}
		});

		public object lbtuDuty_var1 => GetValue(lbtuDuty_var1_Property);

		public object fraFracRes_Substr2 => GetValue(fraFracRes_Substr2_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);

		public object grdSpltFrac_GridData => GetValue(grdSpltFrac_GridData_Property);
	}
	[ProgId("MMSep2.MMSep2_Result_Summar")]
	public class MMSep2_Result_Summar : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuDuty_label;

		internal MMVariableEdit lbtuDuty;

		internal MMGroupBox fraFracRes;

		internal MMLabel MMMenuButton1_label;

		internal MMComboEdit MMMenuButton1;

		internal MMScrollArea grdSpltFrac;

		private bool _contentLoaded;

		public MMSep2_Result_Summar()
		{
			base.ViewModelType = typeof(MMSep2_Result_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/sep2/mmsep2_result_summar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuDuty_label = (MMLabel)target;
				break;
			case 2:
				lbtuDuty = (MMVariableEdit)target;
				break;
			case 3:
				fraFracRes = (MMGroupBox)target;
				break;
			case 4:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 5:
				MMMenuButton1 = (MMComboEdit)target;
				break;
			case 6:
				grdSpltFrac = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer
{
	public class MMMixer_AddInp_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMDescription1_var1_Property = CxvPropertyDeclaration.Register("MMDescription1_var1", typeof(MMMixer_AddInp_ViewModel), new CxvDescriptionProperty
		{
			DataPath = "@main.Input.ADDINPUT"
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

		public object MMDescription1_var1 => GetValue(MMDescription1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}
	}
	[ProgId("MMMixer.MMMixer_AddInp")]
	public class MMMixer_AddInp : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMDescription MMDescription1;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMixer_AddInp()
		{
			base.ViewModelType = typeof(MMMixer_AddInp_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_addinp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				MMDescription1 = (MMDescription)target;
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
	public class MMMixer_AddOpt_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration lbtuTempTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTempTol_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.EO_TEMP_TOL"
		});

		public static readonly CxvPropertyDeclaration lbtuFlowTol1_var1_Property = CxvPropertyDeclaration.Register("lbtuFlowTol1_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW_TOL"
		});

		public static readonly CxvPropertyDeclaration lbtuFlowTol2_var1_Property = CxvPropertyDeclaration.Register("lbtuFlowTol2_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FLOW_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VFRAC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRAC_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VFRAC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.VFRACX_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.VFRAC"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox15_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox15_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox15_var1",
					DataPath = "@main.Input.MIN_PRES"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Block pressure",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox15_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_yes_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox15_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Minimum pressure",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox15_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_no_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox15_var1",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "First pressure",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_First",
					Value = "MMComboBox15_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_first_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox15_var1",
							Value = "FIRST"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES_TOL"
		});

		public static readonly CxvPropertyDeclaration MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.EO_COMP_TOL"
		});

		public static readonly CxvPropertyDeclaration MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.SFRAC_TOL",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SFRC"
			}
		});

		public static readonly CxvPropertyDeclaration MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DUTY_TOL"
		});

		public static readonly CxvPropertyDeclaration cboEOFormu3_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu3_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboEOFormu3_var1",
					DataPath = "@main.Input.EO_FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard",
					Value = "cboEOFormu3_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu3_var1",
							Value = "STANDARD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EO-PML",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML",
					Value = "cboEOFormu3_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu3_var1",
							Value = "EOPML"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboSoluMeth2_MultiMap_Property = CxvPropertyDeclaration.Register("cboSoluMeth2_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboSoluMeth2_var1",
					DataPath = "@main.Input.SOLVE_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Closed; use Perturbation layer around closed model",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_mod",
					Value = "cboSoluMeth2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth2_var1",
							Value = "PERTURBATION"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Ignore; ignore block during EO solution",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Ignore__ignore_block_during_EO_solution",
					Value = "cboSoluMeth2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth2_var1",
							Value = "DO-NOT-CREAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboEOFormu2_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu2_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboEOFormu2_var1",
					DataPath = "@main.Input.EO_FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard_1",
					Value = "cboEOFormu2_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.eo_options_eo_form_standard_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu2_var1",
							Value = "STANDARD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EO-PML",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML_1",
					Value = "cboEOFormu2_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_eo_form_eopml_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu2_var1",
							Value = "EOPML"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RT-Opt 10.0",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0",
					Value = "cboEOFormu2_MultiMapOption_3",
					Prompt = ApwnComboPromptResource.eo_options_eo_form_molefrac_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu2_var1",
							Value = "MOLEFRAC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RT-Opt 3.0",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_3_0",
					Value = "cboEOFormu2_MultiMapOption_4",
					Prompt = ApwnComboPromptResource.eo_options_eo_form_moleflow_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu2_var1",
							Value = "MOLEFLOW"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox7_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox7_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox7_var1",
					DataPath = "@main.Input.ON_SMEO_DIFF"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Use-closed",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Use_closed",
					Value = "MMComboBox7_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox7_var1",
							Value = "USE-CLOSED"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Use-open",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Use_open",
					Value = "MMComboBox7_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox7_var1",
							Value = "USE-OPEN"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration ChemMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ChemMethod_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "ChemMethodComboBox_var1",
					DataPath = "@main.Input.CHEM_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Product",
					DisplayResourceKey = ApwnResources.MMEOOption_AddOpt_ChemMethod_Product,
					Value = "ChemMethodComboBox_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ChemMethodComboBox_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Logarithmic",
					DisplayResourceKey = ApwnResources.MMEOOption_AddOpt_ChemMethod_Logarithmic,
					Value = "ChemMethodComboBox_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "ChemMethodComboBox_var1",
							Value = "YES-LOG"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_1",
					Value = "MMComboBox11_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.eo_options_always_inst_yes_prompt,
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_1",
					Value = "MMComboBox11_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_always_inst_no_prompt,
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

		public static readonly CxvPropertyDeclaration MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NEG_COMP_CHK"
		});

		public static readonly CxvPropertyDeclaration MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.NEG_FLOW_CHK"
		});

		public static readonly CxvPropertyDeclaration cboEOFormu1_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboEOFormu1_var1",
					DataPath = "@main.Input.EO_FORM"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Standard",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard_2",
					Value = "cboEOFormu1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu1_var1",
							Value = "STANDARD"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EO-PML",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML_2",
					Value = "cboEOFormu1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu1_var1",
							Value = "EOPML"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "RT-Opt 10.0",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0_1",
					Value = "cboEOFormu1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboEOFormu1_var1",
							Value = "MOLEFRAC"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Analytical",
					Value = "MMComboBox1_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.design_spec_deriv_method_analytical_prompt,
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Numerical",
					Value = "MMComboBox1_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.design_spec_deriv_method_numerical_prompt,
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
					Value = "MMComboBox1_MultiMapOption_3",
					Prompt = ApwnComboPromptResource.design_spec_deriv_method_update_analy_prompt,
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
					Value = "MMComboBox1_MultiMapOption_4",
					Prompt = ApwnComboPromptResource.design_spec_deriv_method_update_numer_prompt,
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

		public static readonly CxvPropertyDeclaration cboSoluMeth1_MultiMap_Property = CxvPropertyDeclaration.Register("cboSoluMeth1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboSoluMeth1_var1",
					DataPath = "@main.Input.SOLVE_METHOD"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with information messages",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_informati",
					Value = "cboSoluMeth1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth1_var1",
							Value = "OPEN-PERT-IN"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure use Perturbation with warning messages",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warning_m",
					Value = "cboSoluMeth1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth1_var1",
							Value = "OPEN-PERT-WA"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Open; on failure stop with error messages",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
					Value = "cboSoluMeth1_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth1_var1",
							Value = "OPEN-NOPERT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Closed; use Perturbation layer around closed model",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_mod_1",
					Value = "cboSoluMeth1_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth1_var1",
							Value = "PERTURBATION"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Neither; ignore block during EO solution",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
					Value = "cboSoluMeth1_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboSoluMeth1_var1",
							Value = "DO-NOT-CREAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox17_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox17_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_2",
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_2",
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

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_PHASE_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox9_var1",
					DataPath = "@main.Input.INLET_PHASE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "MMComboBox9_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.eo_options_inlet_phase_v_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "V"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "MMComboBox9_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_inlet_phase_l_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "L"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Mixed",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Mixed",
					Value = "MMComboBox9_MultiMapOption_3",
					Prompt = ApwnComboPromptResource.eo_options_inlet_phase_mixed_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox9_var1",
							Value = "MIXED"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox10_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox10_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_PML",
					Value = "MMComboBox10_MultiMapOption_1",
					Prompt = ApwnComboPromptResource.eo_options_flash_form_pml_prompt,
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Smoothing",
					Value = "MMComboBox10_MultiMapOption_2",
					Prompt = ApwnComboPromptResource.eo_options_flash_form_smoothing_prompt,
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

		public static readonly CxvPropertyDeclaration MMComboBox12_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox12_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Auto",
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_None",
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_CompID",
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

		public static readonly CxvPropertyDeclaration MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_L2_COMP",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.L2CP1"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox8_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_3",
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
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_3",
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

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_HEAVY_KEY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_LIGHT_KEY"
		});

		public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_DEP_COMPS"
		});

		public static readonly CxvPropertyDeclaration MMComboBox14_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox14_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox14_var1",
					DataPath = "@main.Input.SPARSITY"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Temperature & pressure",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature___pressure",
					Value = "MMComboBox14_MultiMapOption_1",
					Prompt = PromptResources.FILEPNUM_34_Prompt_100,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox14_var1",
							Value = "COMP-INDEP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Temperature, pressure & composition",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition",
					Value = "MMComboBox14_MultiMapOption_2",
					Prompt = PromptResources.FILEPNUM_34_Prompt_101,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox14_var1",
							Value = "FULL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Temperature, pressure & composition for water",
					DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition_for_water",
					Value = "MMComboBox14_MultiMapOption_3",
					Prompt = PromptResources.FILEPNUM_34_Prompt_102,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox14_var1",
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

		private bool _lbtuTempTol_Enabled;

		private Visibility _cboSoluMeth1_Visibility;

		private Visibility _cboSoluMeth2_Visibility;

		private Visibility _cboEOFormu1_Visibility;

		private Visibility _cboEOFormu2_Visibility;

		private Visibility _cboEOFormu3_Visibility;

		private Visibility _lbtuFlowTol1_Visibility;

		private Visibility _lbtuFlowTol2_Visibility;

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

		public object lbtuFlowTol1_var1 => GetValue(lbtuFlowTol1_var1_Property);

		public object lbtuFlowTol2_var1 => GetValue(lbtuFlowTol2_var1_Property);

		public object MMLBUText3_var1 => GetValue(MMLBUText3_var1_Property);

		public object MMLBUText4_var1 => GetValue(MMLBUText4_var1_Property);

		public object MMComboBox15_MultiMap => GetValue(MMComboBox15_MultiMap_Property);

		public object MMLBUText6_var1 => GetValue(MMLBUText6_var1_Property);

		public object MMLBUText8_var1 => GetValue(MMLBUText8_var1_Property);

		public object MMLBUText7_var1 => GetValue(MMLBUText7_var1_Property);

		public object MMLBUText9_var1 => GetValue(MMLBUText9_var1_Property);

		public object cboEOFormu3_MultiMap => GetValue(cboEOFormu3_MultiMap_Property);

		public object cboSoluMeth2_MultiMap => GetValue(cboSoluMeth2_MultiMap_Property);

		public object cboEOFormu2_MultiMap => GetValue(cboEOFormu2_MultiMap_Property);

		public object MMComboBox7_MultiMap => GetValue(MMComboBox7_MultiMap_Property);

		public object ChemMethod_MultiMap => GetValue(ChemMethod_MultiMap_Property);

		public object MMComboBox11_MultiMap => GetValue(MMComboBox11_MultiMap_Property);

		public object MMLBUText1_var1 => GetValue(MMLBUText1_var1_Property);

		public object MMLBUText2_var1 => GetValue(MMLBUText2_var1_Property);

		public object cboEOFormu1_MultiMap => GetValue(cboEOFormu1_MultiMap_Property);

		public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

		public object cboSoluMeth1_MultiMap => GetValue(cboSoluMeth1_MultiMap_Property);

		public object MMComboBox17_MultiMap => GetValue(MMComboBox17_MultiMap_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox9_MultiMap => GetValue(MMComboBox9_MultiMap_Property);

		public object MMComboBox10_MultiMap => GetValue(MMComboBox10_MultiMap_Property);

		public object MMComboBox12_MultiMap => GetValue(MMComboBox12_MultiMap_Property);

		public object MMComboBox13_var1 => GetValue(MMComboBox13_var1_Property);

		public object MMComboBox8_MultiMap => GetValue(MMComboBox8_MultiMap_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMComboBox5_var1 => GetValue(MMComboBox5_var1_Property);

		public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

		public object MMComboBox14_MultiMap => GetValue(MMComboBox14_MultiMap_Property);

		public bool lbtuTempTol_Enabled
		{
			get
			{
				return _lbtuTempTol_Enabled;
			}
			set
			{
				if (value != _lbtuTempTol_Enabled)
				{
					_lbtuTempTol_Enabled = value;
					OnPropertyChanged("lbtuTempTol_Enabled");
				}
			}
		}

		public Visibility cboSoluMeth1_Visibility
		{
			get
			{
				return _cboSoluMeth1_Visibility;
			}
			set
			{
				if (value != _cboSoluMeth1_Visibility)
				{
					_cboSoluMeth1_Visibility = value;
					OnPropertyChanged("cboSoluMeth1_Visibility");
				}
			}
		}

		public Visibility cboSoluMeth2_Visibility
		{
			get
			{
				return _cboSoluMeth2_Visibility;
			}
			set
			{
				if (value != _cboSoluMeth2_Visibility)
				{
					_cboSoluMeth2_Visibility = value;
					OnPropertyChanged("cboSoluMeth2_Visibility");
				}
			}
		}

		public Visibility cboEOFormu1_Visibility
		{
			get
			{
				return _cboEOFormu1_Visibility;
			}
			set
			{
				if (value != _cboEOFormu1_Visibility)
				{
					_cboEOFormu1_Visibility = value;
					OnPropertyChanged("cboEOFormu1_Visibility");
				}
			}
		}

		public Visibility cboEOFormu2_Visibility
		{
			get
			{
				return _cboEOFormu2_Visibility;
			}
			set
			{
				if (value != _cboEOFormu2_Visibility)
				{
					_cboEOFormu2_Visibility = value;
					OnPropertyChanged("cboEOFormu2_Visibility");
				}
			}
		}

		public Visibility cboEOFormu3_Visibility
		{
			get
			{
				return _cboEOFormu3_Visibility;
			}
			set
			{
				if (value != _cboEOFormu3_Visibility)
				{
					_cboEOFormu3_Visibility = value;
					OnPropertyChanged("cboEOFormu3_Visibility");
				}
			}
		}

		public Visibility lbtuFlowTol1_Visibility
		{
			get
			{
				return _lbtuFlowTol1_Visibility;
			}
			set
			{
				if (value != _lbtuFlowTol1_Visibility)
				{
					_lbtuFlowTol1_Visibility = value;
					OnPropertyChanged("lbtuFlowTol1_Visibility");
				}
			}
		}

		public Visibility lbtuFlowTol2_Visibility
		{
			get
			{
				return _lbtuFlowTol2_Visibility;
			}
			set
			{
				if (value != _lbtuFlowTol2_Visibility)
				{
					_lbtuFlowTol2_Visibility = value;
					OnPropertyChanged("lbtuFlowTol2_Visibility");
				}
			}
		}

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (!base.IsInitialUpdate)
			{
				return;
			}
			string text = CxsConverter.ValueToString(ExpandDataPathAndGet("@main", "type"));
			if (!string.IsNullOrEmpty(text))
			{
				text = text.ToUpperInvariant();
			}
			if (text == "ANALYZER" || text == "DECANTER" || text == "COMPR" || text == "PUMP" || text == "RYIELD" || text == "RSTOIC" || text == "EXTRACT" || text == "RCSTR" || text == "VALVE" || text == "SEP" || text == "SEP2" || text == "RSTOIC" || text == "RYIELD" || text == "REQUIL" || text == "RADFRAC")
			{
				cboSoluMeth1_Visibility = Visibility.Visible;
				cboSoluMeth2_Visibility = Visibility.Collapsed;
				cboEOFormu1_Visibility = Visibility.Collapsed;
				cboEOFormu2_Visibility = Visibility.Collapsed;
				cboEOFormu3_Visibility = Visibility.Visible;
				lbtuFlowTol1_Visibility = Visibility.Visible;
				lbtuFlowTol2_Visibility = Visibility.Collapsed;
				return;
			}
			switch (text)
			{
			case "USER":
			case "USER2":
				cboSoluMeth1_Visibility = Visibility.Collapsed;
				cboSoluMeth2_Visibility = Visibility.Visible;
				break;
			case "HXFLUX":
			case "PETROFRAC":
			case "FLASH3":
			case "HEATX":
				cboSoluMeth1_Visibility = Visibility.Visible;
				cboSoluMeth2_Visibility = Visibility.Collapsed;
				cboEOFormu1_Visibility = Visibility.Visible;
				cboEOFormu2_Visibility = Visibility.Collapsed;
				cboEOFormu3_Visibility = Visibility.Collapsed;
				lbtuFlowTol1_Visibility = Visibility.Visible;
				lbtuFlowTol2_Visibility = Visibility.Collapsed;
				break;
			case "MIXER":
			case "FSPLIT":
			case "FLASH2":
			case "HEATER":
			case "RADFRAC":
			case "USER3":
			case "ACMUSER3":
				cboSoluMeth1_Visibility = Visibility.Visible;
				cboSoluMeth2_Visibility = Visibility.Collapsed;
				cboEOFormu1_Visibility = Visibility.Collapsed;
				cboEOFormu2_Visibility = Visibility.Visible;
				cboEOFormu3_Visibility = Visibility.Collapsed;
				if (text == "HEATER")
				{
					lbtuFlowTol1_Visibility = Visibility.Collapsed;
					lbtuFlowTol2_Visibility = Visibility.Visible;
				}
				else
				{
					lbtuFlowTol1_Visibility = Visibility.Visible;
					lbtuFlowTol2_Visibility = Visibility.Collapsed;
				}
				break;
			default:
				cboSoluMeth1_Visibility = Visibility.Visible;
				cboSoluMeth2_Visibility = Visibility.Collapsed;
				cboEOFormu1_Visibility = Visibility.Collapsed;
				cboEOFormu2_Visibility = Visibility.Visible;
				cboEOFormu3_Visibility = Visibility.Collapsed;
				if (text == "MHEATX")
				{
					lbtuTempTol_Enabled = true;
					cboEOFormu2_Visibility = Visibility.Collapsed;
					cboEOFormu3_Visibility = Visibility.Visible;
				}
				break;
			}
		}
	}
	[ProgId("MMMixer.MMMixer_AddOpt")]
	public class MMMixer_AddOpt : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel cboSoluMeth2_label;

		internal MMLabel cboSoluMeth1_label;

		internal MMComboEdit cboSoluMeth2;

		internal MMComboEdit cboSoluMeth1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel cboEOFormu3_label;

		internal MMLabel cboEOFormu2_label;

		internal MMLabel cboEOFormu1_label;

		internal MMComboEdit cboEOFormu3;

		internal MMComboEdit cboEOFormu2;

		internal MMComboEdit cboEOFormu1;

		internal MMLabel MMLBUText1_label;

		internal MMVariableEdit MMLBUText1;

		internal MMLabel MMLBUText2_label;

		internal MMVariableEdit MMLBUText2;

		internal MMLabel MMComboBox11_label;

		internal MMComboEdit MMComboBox11;

		internal MMLabel MMComboBox7_label;

		internal MMComboEdit MMComboBox7;

		internal MMLabel ChemMethod_label;

		internal MMComboEdit ChemMethodComboBox;

		internal MMGroupBox MMFrame3;

		internal MMLabel MMComboBox14_label;

		internal MMComboEdit MMComboBox14;

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

		internal MMLabel MMComboBox9_label;

		internal MMComboEdit MMComboBox9;

		internal MMLabel MMComboBox12_label;

		internal MMComboEdit MMComboBox12;

		internal MMLabel MMComboBox13_label;

		internal MMComboEdit MMComboBox13;

		internal MMGroupBox MMFrame4;

		internal MMLabel MMLBUText4_label;

		internal MMVariableEdit MMLBUText4;

		internal MMLabel MMLBUText3_label;

		internal MMVariableEdit MMLBUText3;

		internal MMLabel MMLBUText7_label;

		internal MMVariableEdit MMLBUText7;

		internal MMLabel MMLBUText8_label;

		internal MMVariableEdit MMLBUText8;

		internal MMLabel lbtuFlowTol1_label;

		internal MMLabel lbtuFlowTol2_label;

		internal MMVariableEdit lbtuFlowTol1;

		internal MMVariableEdit lbtuFlowTol2;

		internal MMLabel MMLBUText6_label;

		internal MMVariableEdit MMLBUText6;

		internal MMLabel MMComboBox15_label;

		internal MMComboEdit MMComboBox15;

		internal MMLabel MMLBUText9_label;

		internal MMVariableEdit MMLBUText9;

		internal MMLabel lbtuTempTol_label;

		internal MMVariableEdit lbtuTempTol;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMixer_AddOpt()
		{
			base.ViewModelType = typeof(MMMixer_AddOpt_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_addopt.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				cboSoluMeth2_label = (MMLabel)target;
				break;
			case 3:
				cboSoluMeth1_label = (MMLabel)target;
				break;
			case 4:
				cboSoluMeth2 = (MMComboEdit)target;
				break;
			case 5:
				cboSoluMeth1 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox1_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox1 = (MMComboEdit)target;
				break;
			case 8:
				cboEOFormu3_label = (MMLabel)target;
				break;
			case 9:
				cboEOFormu2_label = (MMLabel)target;
				break;
			case 10:
				cboEOFormu1_label = (MMLabel)target;
				break;
			case 11:
				cboEOFormu3 = (MMComboEdit)target;
				break;
			case 12:
				cboEOFormu2 = (MMComboEdit)target;
				break;
			case 13:
				cboEOFormu1 = (MMComboEdit)target;
				break;
			case 14:
				MMLBUText1_label = (MMLabel)target;
				break;
			case 15:
				MMLBUText1 = (MMVariableEdit)target;
				break;
			case 16:
				MMLBUText2_label = (MMLabel)target;
				break;
			case 17:
				MMLBUText2 = (MMVariableEdit)target;
				break;
			case 18:
				MMComboBox11_label = (MMLabel)target;
				break;
			case 19:
				MMComboBox11 = (MMComboEdit)target;
				break;
			case 20:
				MMComboBox7_label = (MMLabel)target;
				break;
			case 21:
				MMComboBox7 = (MMComboEdit)target;
				break;
			case 22:
				ChemMethod_label = (MMLabel)target;
				break;
			case 23:
				ChemMethodComboBox = (MMComboEdit)target;
				break;
			case 24:
				MMFrame3 = (MMGroupBox)target;
				break;
			case 25:
				MMComboBox14_label = (MMLabel)target;
				break;
			case 26:
				MMComboBox14 = (MMComboEdit)target;
				break;
			case 27:
				MMComboBox3_label = (MMLabel)target;
				break;
			case 28:
				MMComboBox3 = (MMComboEdit)target;
				break;
			case 29:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 30:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 31:
				MMComboBox6_label = (MMLabel)target;
				break;
			case 32:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 33:
				MMComboBox8_label = (MMLabel)target;
				break;
			case 34:
				MMComboBox8 = (MMComboEdit)target;
				break;
			case 35:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 36:
				MMComboBox17_label = (MMLabel)target;
				break;
			case 37:
				MMComboBox17 = (MMComboEdit)target;
				break;
			case 38:
				MMLBUText10_label = (MMLabel)target;
				break;
			case 39:
				MMLBUText10 = (MMVariableEdit)target;
				break;
			case 40:
				MMComboBox10_label = (MMLabel)target;
				break;
			case 41:
				MMComboBox10 = (MMComboEdit)target;
				break;
			case 42:
				MMComboBox9_label = (MMLabel)target;
				break;
			case 43:
				MMComboBox9 = (MMComboEdit)target;
				break;
			case 44:
				MMComboBox12_label = (MMLabel)target;
				break;
			case 45:
				MMComboBox12 = (MMComboEdit)target;
				break;
			case 46:
				MMComboBox13_label = (MMLabel)target;
				break;
			case 47:
				MMComboBox13 = (MMComboEdit)target;
				break;
			case 48:
				MMFrame4 = (MMGroupBox)target;
				break;
			case 49:
				MMLBUText4_label = (MMLabel)target;
				break;
			case 50:
				MMLBUText4 = (MMVariableEdit)target;
				break;
			case 51:
				MMLBUText3_label = (MMLabel)target;
				break;
			case 52:
				MMLBUText3 = (MMVariableEdit)target;
				break;
			case 53:
				MMLBUText7_label = (MMLabel)target;
				break;
			case 54:
				MMLBUText7 = (MMVariableEdit)target;
				break;
			case 55:
				MMLBUText8_label = (MMLabel)target;
				break;
			case 56:
				MMLBUText8 = (MMVariableEdit)target;
				break;
			case 57:
				lbtuFlowTol1_label = (MMLabel)target;
				break;
			case 58:
				lbtuFlowTol2_label = (MMLabel)target;
				break;
			case 59:
				lbtuFlowTol1 = (MMVariableEdit)target;
				break;
			case 60:
				lbtuFlowTol2 = (MMVariableEdit)target;
				break;
			case 61:
				MMLBUText6_label = (MMLabel)target;
				break;
			case 62:
				MMLBUText6 = (MMVariableEdit)target;
				break;
			case 63:
				MMComboBox15_label = (MMLabel)target;
				break;
			case 64:
				MMComboBox15 = (MMComboEdit)target;
				break;
			case 65:
				MMLBUText9_label = (MMLabel)target;
				break;
			case 66:
				MMLBUText9 = (MMVariableEdit)target;
				break;
			case 67:
				lbtuTempTol_label = (MMLabel)target;
				break;
			case 68:
				lbtuTempTol = (MMVariableEdit)target;
				break;
			case 69:
				cmdClose = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Blocko_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKPR"
		});

		public static readonly CxvPropertyDeclaration entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKSI"
		});

		public static readonly CxvPropertyDeclaration entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKDG"
		});

		public static readonly CxvPropertyDeclaration entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKRP"
		});

		public static readonly CxvPropertyDeclaration genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GENBLKOP"
		});

		public static readonly CxvPropertyDeclaration entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTIPT"
		});

		public static readonly CxvPropertyDeclaration entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTADD"
		});

		public static readonly CxvPropertyDeclaration entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTEOMOD"
		});

		public static readonly CxvPropertyDeclaration smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMSPEC"
		});

		public static readonly CxvPropertyDeclaration sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMENT"
		});

		public static readonly CxvPropertyDeclaration varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMMixer_Blocko_ViewModel), new CxvParameterProperty
		{
			Parameter = "varno"
		});

		public static readonly CxvPropertyDeclaration eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EODEF"
		});

		public static readonly CxvPropertyDeclaration eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT"
		});

		public static readonly CxvPropertyDeclaration l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.L2CP2"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@blkops", "@genblk" },
			EnteredDataPaths = { "@entpro" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsim" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdia" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@l2cp2", "@smspec" },
			EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@sment" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@eodef" },
			EnteredDataPaths = { "@eoent" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entrep" }
		});

		public object blkops => GetValue(blkops_Property);

		public object entpro => GetValue(entpro_Property);

		public object entsim => GetValue(entsim_Property);

		public object entdia => GetValue(entdia_Property);

		public object entrep => GetValue(entrep_Property);

		public object genblk => GetValue(genblk_Property);

		public object entitp => GetValue(entitp_Property);

		public object entadd => GetValue(entadd_Property);

		public object entmod => GetValue(entmod_Property);

		public object smspec => GetValue(smspec_Property);

		public object sment => GetValue(sment_Property);

		public object varno => GetValue(varno_Property);

		public object eodef => GetValue(eodef_Property);

		public object eoent => GetValue(eoent_Property);

		public object l2cp2 => GetValue(l2cp2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);
	}
	[ProgId("MMMixer.MMMixer_Blocko")]
	public class MMMixer_Blocko : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMMixer_Blocko()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMMixer_Blocko_Diagno_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMMixer.MMMixer_Blocko_Diagno")]
	public class MMMixer_Blocko_Diagno : MMTabPage, IComponentConnector
	{
		private bool _contentLoaded;

		public MMMixer_Blocko_Diagno()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_Diagno_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_diagno.xaml", UriKind.Relative);
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
	public class MMMixer_Blocko_Proper_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMMixer.MMMixer_Blocko_Proper")]
	public class MMMixer_Blocko_Proper : MMTabPage, IComponentConnector
	{
		private bool _contentLoaded;

		public MMMixer_Blocko_Proper()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_Proper_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_proper.xaml", UriKind.Relative);
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
	public class MMMixer_Blocko_Report_ViewModel : MMTabPageViewModel
	{
		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				ResolveUpdateParameter("TBal_ChkBox", "1");
				ResolveUpdateParameter("CBal_ChkBox", "1");
			}
		}
	}
	[ProgId("MMMixer.MMMixer_Blocko_Report")]
	public class MMMixer_Blocko_Report : MMTabPage, IComponentConnector
	{
		private bool _contentLoaded;

		public MMMixer_Blocko_Report()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_Report_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_report.xaml", UriKind.Relative);
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
	public class MMMixer_Blocko_Simula_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMMixer.MMMixer_Blocko_Simula")]
	public class MMMixer_Blocko_Simula : MMTabPage, IComponentConnector
	{
		private bool _contentLoaded;

		public MMMixer_Blocko_Simula()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_Simula_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_simula.xaml", UriKind.Relative);
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
	public class MMMixer_Blocko_VarVec_ViewModel : MMTabPageViewModel
	{
		public class grdDefine_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdDefine_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox1_var1",
						DataPath = "@main.Input.FVN_VARTYPE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "EO Var",
						DisplayResourceKey = "MMMixer_Blocko_VarVec_ViewModel__CxvMultiMapOption_Display_EO_Var",
						Value = "MMComboBox1_MultiMapOption_1",
						Prompt = PromptResources.FILEPNUM_17_Prompt_3,
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "BLOCK-VAR"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "EO Vec",
						DisplayResourceKey = "MMMixer_Blocko_VarVec_ViewModel__CxvMultiMapOption_Display_EO_Vec",
						Value = "MMComboBox1_MultiMapOption_2",
						Prompt = PromptResources.FILEPNUM_17_Prompt_4,
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox1_var1",
								Value = "BLOCK-VEC"
							}
						}
					}
				}
			});

			private string[] PromptLabel = new string[6];

			private string[] PromptVariable = new string[6];

			private string[] PromptVec = new string[6];

			private EventHandler _varDefnDependencies_PropertyDependencyChangedHandler;

			private CxvPropertyWatch varDefnDependencies;

			public object MMComboBox1_MultiMap => GetValue(MMComboBox1_MultiMap_Property);

			public object txtVarDefn_VarDefn => new CxvManualVariableData
			{
				Value = Get_txtVarDefn_VarDefn_Value(),
				IsReadOnly = true,
				IsCalculated = false,
				IsEnabled = false
			};

			private EventHandler varDefnDependencies_PropertyDependencyChangedHandler
			{
				get
				{
					if (_varDefnDependencies_PropertyDependencyChangedHandler == null)
					{
						_varDefnDependencies_PropertyDependencyChangedHandler = delegate
						{
							OnPropertyChanged("txtVarDefn_VarDefn");
						};
					}
					return _varDefnDependencies_PropertyDependencyChangedHandler;
				}
			}

			protected override void OnUpdateData()
			{
				base.OnUpdateData();
				if (base.IsInitialUpdate)
				{
					PromptLabel[0] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Variable;
					PromptVariable[0] = "FVN_VARIABLE";
					PromptLabel[1] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Sentence;
					PromptVariable[1] = "FVN_SENTENCE";
					PromptLabel[2] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID1;
					PromptVariable[2] = "FVN_ID1";
					PromptLabel[3] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID2;
					PromptVariable[3] = "FVN_ID2";
					PromptLabel[4] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID3;
					PromptVariable[4] = "FVN_ID3";
					PromptLabel[5] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Element;
					PromptVariable[5] = "FVN_ELEM";
					PromptVec[0] = "FVC_VARIABLE";
					PromptVec[1] = "FVC_SENTENCE";
					PromptVec[2] = "FVN_ID1";
					PromptVec[3] = "FVN_ID2";
					PromptVec[4] = "FVN_ID3";
					PromptVec[5] = "FVN_ELEM";
				}
			}

			private string Get_txtVarDefn_VarDefn_Value()
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
				string text = CxsConverter.ValueToString(ResolveParameter("y"));
				if (string.IsNullOrEmpty(text))
				{
					return null;
				}
				int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE", "child_count", null, varDefnDependencies));
				if (!num.HasValue)
				{
					return null;
				}
				if (text.StartsWith("#", StringComparison.Ordinal) && text.Length > 1)
				{
					int result = 0;
					if (int.TryParse(text.Substring(1), out result) && result >= num.Value)
					{
						return null;
					}
				}
				string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + text, "value", null, varDefnDependencies));
				string[] array = new string[6];
				if (text2 == "BLOCK-VAR")
				{
					for (int i = 0; i <= 5; i++)
					{
						string text3 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + PromptVariable[i] + "." + text, "value", null, varDefnDependencies));
						if (!string.IsNullOrEmpty(text3))
						{
							array[i] = PromptLabel[i] + text3 + " ";
						}
					}
				}
				else
				{
					for (int j = 0; j <= 5; j++)
					{
						string text4 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input." + PromptVec[j] + "." + text, "value", null, varDefnDependencies));
						if (!string.IsNullOrEmpty(text4))
						{
							array[j] = PromptLabel[j] + text4 + " ";
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
				return array[0] + array[1] + array[2] + array[3] + array[4] + array[5];
			}
		}

		public static readonly CxvPropertyDeclaration fraDefine_choice_Property = CxvPropertyDeclaration.Register("fraDefine_choice", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvParameterProperty
		{
			Parameter = "choice"
		});

		public static readonly CxvPropertyDeclaration NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.FVN_VARTYPE.0"
		});

		public static readonly CxvPropertyDeclaration grdDefine_GridData_Property = CxvPropertyDeclaration.Register("grdDefine_GridData", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdDefine_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FVN_VARTYPE",
				UseChildId = true,
				Name = "y"
			}
		});

		private DelegateCommand<object> _cmdEdit_Command;

		private CxvPropertyWatch _watcher = new CxvPropertyWatch();

		private DelegateCommand<object> _cmdDelete_Command;

		public static CxvPropertyDeclaration cmdEditDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditDeleteCanExecute", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.FVN_VARTYPE",
			DataAttribute = "child_count",
			Operator = CxvLogicalOperator.GreaterThan,
			Value = 0
		});

		private int _allSelectedRecordsCount;

		private ObservableCollection<int> _selectedRowIndexes;

		public object fraDefine_choice => GetValue(fraDefine_choice_Property);

		public object NumCol => GetValue(NumCol_Property);

		public object grdDefine_GridData => GetValue(grdDefine_GridData_Property);

		public DelegateCommand<object> cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new DelegateCommand<object>(cmdEdit_CommandExecute, cmdEdit_CommandCanExecute);
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
					_cmdDelete_Command = new DelegateCommand<object>(cmdDelete_CommandExecute, cmdDelete_CommandCanExecute);
				}
				return _cmdDelete_Command;
			}
		}

		public object cmdEditDeleteCanExecute => GetValue(cmdEditDeleteCanExecuteProperty);

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
				}
			}
		}

		private bool cmdEdit_CommandCanExecute(object parameter)
		{
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1 && (cmdEditDeleteCanExecute as CxvLogicalPropertyData).Value)
			{
				return GetRowCount() - SelectedRowIndexes[0] != 1;
			}
			return false;
		}

		private int GetRowCount()
		{
			return CxsConverter.ValueToInt32(ResolveViewPropertyPath("grdDefine_GridData.Count", _watcher)).GetValueOrDefault();
		}

		private bool cmdDelete_CommandCanExecute(object parameter)
		{
			if (SelectedRowIndexes != null && SelectedRowIndexes.Count == 1 && (cmdEditDeleteCanExecute as CxvLogicalPropertyData).Value)
			{
				return GetRowCount() - SelectedRowIndexes[0] != 1;
			}
			return false;
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (_allSelectedRecordsCount <= 0)
			{
				ShowMessageBox(new ShowMessageBoxEventArgs
				{
					Message = Resources.MMMixer_Blocko_VarVec_ViewModel_SelectVariableToEdit,
					Title = Resources.MMMixer_Blocko_VarVec_ViewModel_EditVariable
				});
				return;
			}
			DisplayFormEventArgs e = new DisplayFormEventArgs();
			e.FormType = typeof(MMMixer_Blocko_VarWiz);
			e.LegacyFlags = 0;
			e.HelpId = 13;
			e.HelpFile = "common.hlp";
			e.ShowPrompts = true;
			e.ShortName = Resources.MMMixer_Blocko_VarVec_ViewModel_VariableDefinition;
			e.CompleteDataPaths = new string[1] { "@main.CC Nodes.EODEF" };
			DisplayFormEventArgs e2 = e;
			e2.Parameters.Add("varno", "#" + _selectedRowIndexes[0]);
			DisplayForm(e2);
			UpdateAll();
		}

		private void cmdDelete_CommandExecute(object parameter)
		{
			if (_allSelectedRecordsCount == 0)
			{
				ShowMessageBox(new ShowMessageBoxEventArgs
				{
					Message = Resources.MMMixer_Blocko_VarVec_ViewModel_SelectVariableToDelete,
					Title = Resources.MMMixer_Blocko_VarVec_ViewModel_DeleteVariable
				});
				return;
			}
			IOrderedEnumerable<int> rows = _selectedRowIndexes.OrderBy((int index) => index);
			IEnumerable<string> ids = _selectedRowIndexes.OrderBy((int index) => index).Select(delegate(int index)
			{
				int num = index;
				return CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE.#" + num, "value"));
			});
			DeleteChildren("@main.Input.FVN_VARTYPE", rows, ids);
			UpdateDisplay();
			UpdateAll();
		}

		private void _selectedRowIndexes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			RefreshButtonStatus();
		}

		private void RefreshButtonStatus()
		{
			cmdEdit_Command.RaiseCanExecuteChanged();
			cmdDelete_Command.RaiseCanExecuteChanged();
		}
	}
	[ProgId("MMMixer.MMMixer_Blocko_VarVec")]
	public class MMMixer_Blocko_VarVec : MMTabPage, IComponentConnector
	{
		internal MMScrollArea grdDefine;

		internal MMCmdButton cmdEdit;

		internal MMCmdButton cmdDelete;

		private bool _contentLoaded;

		public MMMixer_Blocko_VarVec()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_VarVec_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_varvec.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				grdDefine = (MMScrollArea)target;
				break;
			case 2:
				cmdEdit = (MMCmdButton)target;
				break;
			case 3:
				cmdDelete = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Blocko_VarWiz_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdFind_Command;

		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow0_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow0", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow0"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow1_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow1"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow2_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow2"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow3_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow3"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_inputnode_Property = CxvPropertyDeclaration.Register("frmVarDef_inputnode", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow4_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow4"
		});

		public static readonly CxvPropertyDeclaration frmVarDef_vwrow5_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "vwrow5"
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_1_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow1.@varno"
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_5_var5_Property = CxvPropertyDeclaration.Register("txtRowsvw_5_var5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow5.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_4_var4_Property = CxvPropertyDeclaration.Register("txtRowsvw_4_var4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow4.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_2_var2_Property = CxvPropertyDeclaration.Register("cboRowsvw_2_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow2.@varno"
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_0_var0_Property = CxvPropertyDeclaration.Register("cboRowsvw_0_var0_MultiMap", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboRowsvw_0_var0",
					DataPath = "@main.Input.@vwrow0.@varno"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "QCALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Qcalc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_qcalc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "QCALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "NET-DUTY",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Net_duty",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_net_duty_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "NET-DUTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "MAXIT",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Maxit",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_maxit_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "MAXIT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "TOL",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Tol",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_tol_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "TOL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "NPOINT",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Npoint",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_npoint_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "NPOINT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "INCR",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Incr",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_incr_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "INCR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PDROP",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pdrop",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pdrop_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "PDROP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DPP-CALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpp_calc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpp_calc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DPP-CALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "UTIL-USAGE",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Util_usage",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_util_usage_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "UTIL-USAGE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "ELEC-USAGE",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Elec_usage",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_elec_usage_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "ELEC-USAGE"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "UTIL-COST",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Util_cost",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_util_cost_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "UTIL-COST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "TCALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Tcalc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_tcalc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "TCALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PCALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pcalc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pcalc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "PCALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "VCALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Vcalc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_vcalc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "VCALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DPCALC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpcalc",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpcalc_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DPCALC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "TEMP",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Temp",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_temp_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "TEMP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "PRES",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pres",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pres_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "PRES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "VFRAC",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Vfrac",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_vfrac_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "VFRAC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DUTY",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Duty",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_duty_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DUTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DELT",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Delt",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_delt_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DELT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DEGSUB",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Degsub",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_degsub_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DEGSUB"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DEGSUP",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Degsup",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_degsup_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DEGSUP"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "T-EST",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_T_est",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_t_est_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "T-EST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "P-EST",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_P_est",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_p_est_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "P-EST"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "DPPARM",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpparm",
					Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpparm_prompt,
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboRowsvw_0_var0",
							Value = "DPPARM"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboType_MultiMap_Property = CxvPropertyDeclaration.Register("cboType_MultiMap", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboType_eotype",
					DataPath = "@main.Input.FVN_VARTYPE.@varno"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "EO Var",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var",
					Value = "cboType_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboType_eotype",
							Value = "BLOCK-VAR"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "EO Vec",
					DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Vec",
					Value = "cboType_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboType_eotype",
							Value = "BLOCK-VEC"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_5_var5_Property = CxvPropertyDeclaration.Register("cboRowsvw_5_var5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow5.@varno"
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_4_var4_Property = CxvPropertyDeclaration.Register("cboRowsvw_4_var4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow4.@varno"
		});

		public static readonly CxvPropertyDeclaration cboRowsvw_3_var3_Property = CxvPropertyDeclaration.Register("cboRowsvw_3_var3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.@vwrow3.@varno"
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_0_var0_Property = CxvPropertyDeclaration.Register("txtRowsvw_0_var0", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow0.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_1_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow1.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_2_var2_Property = CxvPropertyDeclaration.Register("txtRowsvw_2_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow2.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration txtRowsvw_3_var3_Property = CxvPropertyDeclaration.Register("txtRowsvw_3_var3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.@vwrow3.@varno",
			DisplayedCase = CxsDisplayedCase.Uppercase
		});

		public static readonly CxvPropertyDeclaration mbvnum_var2_Property = CxvPropertyDeclaration.Register("mbvnum_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
		{
			Parameter = "varno"
		});

		public static readonly CxvPropertyDeclaration mbvnum_eodef_Property = CxvPropertyDeclaration.Register("mbvnum_eodef", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EODEF"
		});

		public static readonly CxvPropertyDeclaration mbvnum_var1_Property = CxvPropertyDeclaration.Register("mbvnum_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.FVN",
			SelectedItemBinding = "mbvnum_var2.Value",
			CreateNewPrompt = "Variable number:",
			CreateNewPromptResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Variable_number_",
			CompletePaths = { "@main.CC Nodes.EODEF" }
		});

		private string[,] initialvary = new string[2, 14];

		private string[] initialtext = new string[14];

		private ObservableCollection<string> _lblrowsvw_Captions = new ObservableCollection<string>(new string[6] { "row0", "row1", "row2", "row3", "row4", "row5" });

		private ObservableCollection<Visibility> _cboRowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);

		private ObservableCollection<Visibility> _txtRowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);

		private ObservableCollection<Visibility> _lblrowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);

		private ObservableCollection<bool> _cboRowsvw_Enabled = new ObservableCollection<bool>(new bool[6] { true, true, true, true, true, true });

		private Visibility _cmdFind_Visibility;

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

		public object frmVarDef_vwrow0 => GetValue(frmVarDef_vwrow0_Property);

		public object frmVarDef_vwrow1 => GetValue(frmVarDef_vwrow1_Property);

		public object frmVarDef_vwrow2 => GetValue(frmVarDef_vwrow2_Property);

		public object frmVarDef_vwrow3 => GetValue(frmVarDef_vwrow3_Property);

		public object frmVarDef_inputnode => GetValue(frmVarDef_inputnode_Property);

		public object frmVarDef_vwrow4 => GetValue(frmVarDef_vwrow4_Property);

		public object frmVarDef_vwrow5 => GetValue(frmVarDef_vwrow5_Property);

		public object cboRowsvw_1_var1 => GetValue(cboRowsvw_1_var1_Property);

		public object txtRowsvw_5_var5 => GetValue(txtRowsvw_5_var5_Property);

		public object txtRowsvw_4_var4 => GetValue(txtRowsvw_4_var4_Property);

		public object cboRowsvw_2_var2 => GetValue(cboRowsvw_2_var2_Property);

		public object cboRowsvw_0_var0 => GetValue(cboRowsvw_0_var0_Property);

		public object cboType_MultiMap => GetValue(cboType_MultiMap_Property);

		public object cboRowsvw_5_var5 => GetValue(cboRowsvw_5_var5_Property);

		public object cboRowsvw_4_var4 => GetValue(cboRowsvw_4_var4_Property);

		public object cboRowsvw_3_var3 => GetValue(cboRowsvw_3_var3_Property);

		public object txtRowsvw_0_var0 => GetValue(txtRowsvw_0_var0_Property);

		public object txtRowsvw_1_var1 => GetValue(txtRowsvw_1_var1_Property);

		public object txtRowsvw_2_var2 => GetValue(txtRowsvw_2_var2_Property);

		public object txtRowsvw_3_var3 => GetValue(txtRowsvw_3_var3_Property);

		public object mbvnum_var2 => GetValue(mbvnum_var2_Property);

		public object mbvnum_eodef => GetValue(mbvnum_eodef_Property);

		public object mbvnum_var1 => GetValue(mbvnum_var1_Property);

		public ObservableCollection<string> lblrowsvw_Captions
		{
			get
			{
				return _lblrowsvw_Captions;
			}
			set
			{
				_lblrowsvw_Captions = value;
			}
		}

		public ObservableCollection<Visibility> cboRowsvw_Visibilities
		{
			get
			{
				return _cboRowsvw_Visibilities;
			}
			set
			{
				_cboRowsvw_Visibilities = value;
			}
		}

		public ObservableCollection<Visibility> txtRowsvw_Visibilities
		{
			get
			{
				return _txtRowsvw_Visibilities;
			}
			set
			{
				_txtRowsvw_Visibilities = value;
			}
		}

		public ObservableCollection<Visibility> lblrowsvw_Visibilities
		{
			get
			{
				return _lblrowsvw_Visibilities;
			}
			set
			{
				_lblrowsvw_Visibilities = value;
			}
		}

		public ObservableCollection<bool> cboRowsvw_Enabled
		{
			get
			{
				return _cboRowsvw_Enabled;
			}
			set
			{
				_cboRowsvw_Enabled = value;
			}
		}

		public Visibility cmdFind_Visibility
		{
			get
			{
				return _cmdFind_Visibility;
			}
			set
			{
				if (value != _cmdFind_Visibility)
				{
					_cmdFind_Visibility = value;
					OnPropertyChanged("cmdFind_Visibility");
				}
			}
		}

		private void cmdFind_CommandExecute(object parameter)
		{
			string text = CxsConverter.ValueToString(ResolveParameter("varno"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + text, "value"));
			Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input.FVN", "child_ids"));
			if (text2 == "BLOCK-VAR")
			{
				this.GxSearchVariable(ExpandDataPath("@main"), collection.IndexOf(text) + 1, "", "", "BLOCK-VAR");
			}
			else if (text2 == "BLOCK-VEC")
			{
				this.GxSearchVariable(ExpandDataPath("@main"), collection.IndexOf(text) + 1, "", "", "BLOCK-VEC");
			}
			UpdateAll();
			UpdateDisplay();
			if (base.View is MMMixer_Blocko_VarWiz mMMixer_Blocko_VarWiz)
			{
				Keyboard.Focus(mMMixer_Blocko_VarWiz.cboRowsvw_0.Template.FindName("PART_editControl", mMMixer_Blocko_VarWiz.cboRowsvw_0) as FrameworkElement);
			}
		}

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd.Name == "cboType_MultiMap" && subPropertyName == "Value")
			{
				Display2();
			}
			else if (pd.Name == "mbvnum_var2" && subPropertyName == "Value")
			{
				if ((string)ResolveParameter("varno") == "<New>")
				{
					int? num = CxsConverter.ValueToInt32(ExpandDataPathAndGet("@main.Input.FVN", "child_count"));
					AddChild("@main.Input.FVN", -1);
					ResolveUpdateParameter("varno", "#" + num.Value);
				}
				Display2();
			}
			else if (subPropertyName == "Value")
			{
				Display2();
			}
		}

		private void Display2()
		{
			string text = CxsConverter.ValueToString(ResolveParameter("varno"));
			string text2 = CxsConverter.ValueToString(ExpandDataPathAndGet("@main.Input.FVN_VARTYPE." + text, "value"));
			int num = 0;
			if (string.IsNullOrEmpty(text))
			{
				return;
			}
			int num2 = 0;
			if (text2 == "BLOCK-VEC")
			{
				num2 = 1;
			}
			for (int i = 0; i <= 5; i++)
			{
				string text3 = initialvary[num2, i];
				Collection<string> collection = CxsConverter.ValueToStringCollection(ExpandDataPathAndGet("@main.Input." + text3, "child_ids"));
				if (collection == null || !collection.Contains(text))
				{
					continue;
				}
				bool? flag = CxsConverter.ValueToBoolean(ExpandDataPathAndGet("@main.Input." + text3 + "." + text, "can_enter"));
				if (!flag.HasValue || !flag.Value)
				{
					continue;
				}
				lblrowsvw_Visibilities[num] = Visibility.Visible;
				lblrowsvw_Captions[num] = initialtext[i];
				if (i == 1)
				{
					cboRowsvw_Enabled[num] = false;
				}
				if (ExpandDataPathAndGet("@main.Input." + text3 + "." + text, "option_list") == DBNull.Value)
				{
					cboRowsvw_Visibilities[num] = Visibility.Collapsed;
					txtRowsvw_Visibilities[num] = Visibility.Visible;
				}
				else
				{
					cboRowsvw_Visibilities[num] = Visibility.Visible;
					txtRowsvw_Visibilities[num] = Visibility.Collapsed;
				}
				if (num == 0)
				{
					cmdFind_Visibility = cboRowsvw_Visibilities[0];
				}
				if (base.View is MMMixer_Blocko_VarWiz mMMixer_Blocko_VarWiz)
				{
					mMMixer_Blocko_VarWiz.FindName("txtRowsvw_" + num);
					if (mMMixer_Blocko_VarWiz.FindName("cboRowsvw_" + num) is MMComboEdit mMComboEdit)
					{
						if (initialtext[i] == Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Sentence)
						{
							mMComboEdit.DisplayAsTextBox = true;
						}
						else
						{
							mMComboEdit.DisplayAsTextBox = false;
						}
					}
				}
				ResolveUpdateParameter("vwrow" + num, text3);
				num++;
			}
			for (int j = num; j <= 5; j++)
			{
				lblrowsvw_Visibilities[j] = Visibility.Collapsed;
				cboRowsvw_Visibilities[j] = Visibility.Collapsed;
				txtRowsvw_Visibilities[j] = Visibility.Collapsed;
			}
			OnPropertyChanged("lblrowsvw_Visibilities");
			OnPropertyChanged("lblrowsvw_Captions");
			OnPropertyChanged("cboRowsvw_Enabled");
			OnPropertyChanged("cboRowsvw_Visibilities");
			OnPropertyChanged("txtRowsvw_Visibilities");
			OnPropertyChanged("cmdFind_Visibility");
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				initialvary[0, 0] = "FVN_VARIABLE";
				initialvary[0, 1] = "FVN_SENTENCE";
				initialvary[0, 2] = "FVN_ID1";
				initialvary[0, 3] = "FVN_ID2";
				initialvary[0, 4] = "FVN_ID3";
				initialvary[0, 5] = "FVN_ELEM";
				initialvary[1, 0] = "FVC_VARIABLE";
				initialvary[1, 1] = "FVC_SENTENCE";
				initialvary[1, 2] = "FVC_ID1";
				initialvary[1, 3] = "FVC_ID2";
				initialvary[1, 4] = "";
				initialvary[1, 5] = "";
				initialtext[0] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Variable;
				initialtext[1] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Sentence;
				initialtext[2] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID1;
				initialtext[3] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID2;
				initialtext[4] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_ID3;
				initialtext[5] = Resources.MMMixer_Blocko_VarVec_ViewModel_PropmtLabel_Element;
				Display2();
			}
		}
	}
	[ProgId("MMMixer.MMMixer_Blocko_VarWiz")]
	public class MMMixer_Blocko_VarWiz : MMTabPage, IComponentConnector
	{
		internal MMLabel mbvnum_label;

		internal MMAdvancedComboEdit mbvnum;

		internal MMGroupBox frmVarDef;

		internal MMLabel cboType_label;

		internal MMComboEdit cboType;

		internal MMLabel lblrowsvw_0;

		internal MMComboEdit cboRowsvw_0;

		internal MMTextEdit txtRowsvw_0;

		internal MMFindButton cmdFind;

		internal MMLabel lblrowsvw_1;

		internal MMComboEdit cboRowsvw_1;

		internal MMTextEdit txtRowsvw_1;

		internal MMLabel lblrowsvw_2;

		internal MMComboEdit cboRowsvw_2;

		internal MMTextEdit txtRowsvw_2;

		internal MMLabel lblrowsvw_3;

		internal MMComboEdit cboRowsvw_3;

		internal MMTextEdit txtRowsvw_3;

		internal MMLabel lblrowsvw_4;

		internal MMTextEdit txtRowsvw_4;

		internal MMComboEdit cboRowsvw_4;

		internal MMLabel lblrowsvw_5;

		internal MMTextEdit txtRowsvw_5;

		internal MMComboEdit cboRowsvw_5;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMixer_Blocko_VarWiz()
		{
			base.ViewModelType = typeof(MMMixer_Blocko_VarWiz_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_blocko_varwiz.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				mbvnum_label = (MMLabel)target;
				break;
			case 2:
				mbvnum = (MMAdvancedComboEdit)target;
				break;
			case 3:
				frmVarDef = (MMGroupBox)target;
				break;
			case 4:
				cboType_label = (MMLabel)target;
				break;
			case 5:
				cboType = (MMComboEdit)target;
				break;
			case 6:
				lblrowsvw_0 = (MMLabel)target;
				break;
			case 7:
				cboRowsvw_0 = (MMComboEdit)target;
				break;
			case 8:
				txtRowsvw_0 = (MMTextEdit)target;
				break;
			case 9:
				cmdFind = (MMFindButton)target;
				break;
			case 10:
				lblrowsvw_1 = (MMLabel)target;
				break;
			case 11:
				cboRowsvw_1 = (MMComboEdit)target;
				break;
			case 12:
				txtRowsvw_1 = (MMTextEdit)target;
				break;
			case 13:
				lblrowsvw_2 = (MMLabel)target;
				break;
			case 14:
				cboRowsvw_2 = (MMComboEdit)target;
				break;
			case 15:
				txtRowsvw_2 = (MMTextEdit)target;
				break;
			case 16:
				lblrowsvw_3 = (MMLabel)target;
				break;
			case 17:
				cboRowsvw_3 = (MMComboEdit)target;
				break;
			case 18:
				txtRowsvw_3 = (MMTextEdit)target;
				break;
			case 19:
				lblrowsvw_4 = (MMLabel)target;
				break;
			case 20:
				txtRowsvw_4 = (MMTextEdit)target;
				break;
			case 21:
				cboRowsvw_4 = (MMComboEdit)target;
				break;
			case 22:
				lblrowsvw_5 = (MMLabel)target;
				break;
			case 23:
				txtRowsvw_5 = (MMTextEdit)target;
				break;
			case 24:
				cboRowsvw_5 = (MMComboEdit)target;
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
	public class MMMixer_Dynam_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration dyncsh0_Property = CxvPropertyDeclaration.Register("dyncsh0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DYNCSH0"
		});

		public static readonly CxvPropertyDeclaration dyncsh1_Property = CxvPropertyDeclaration.Register("dyncsh1", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DYNCSH1"
		});

		public static readonly CxvPropertyDeclaration ucsh0_Property = CxvPropertyDeclaration.Register("ucsh0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UCSH0"
		});

		public static readonly CxvPropertyDeclaration ucsh1_Property = CxvPropertyDeclaration.Register("ucsh1", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UCSH1"
		});

		public static readonly CxvPropertyDeclaration sht0_Property = CxvPropertyDeclaration.Register("sht0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SHT0"
		});

		public static readonly CxvPropertyDeclaration dyncsh2_Property = CxvPropertyDeclaration.Register("dyncsh2", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DYNCSH2"
		});

		public static readonly CxvPropertyDeclaration ucsh2_Property = CxvPropertyDeclaration.Register("ucsh2", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UCSH2"
		});

		public static readonly CxvPropertyDeclaration sht123_Property = CxvPropertyDeclaration.Register("sht123", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SHT123"
		});

		public static readonly CxvPropertyDeclaration ucsh3_Property = CxvPropertyDeclaration.Register("ucsh3", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UCSH3"
		});

		public static readonly CxvPropertyDeclaration ucsh4_Property = CxvPropertyDeclaration.Register("ucsh4", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.UCSH4"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@dyncsh0" },
			AccessibleDataPaths = { "@sht0" },
			EnteredDataPaths = { "@ucsh0" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@dyncsh1" },
			AccessibleDataPaths = { "@sht123" },
			EnteredDataPaths = { "@ucsh1" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@dyncsh2" },
			AccessibleDataPaths = { "@sht123" },
			EnteredDataPaths = { "@ucsh2" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@sht123" },
			EnteredDataPaths = { "@ucsh3" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@sht123" },
			EnteredDataPaths = { "@ucsh4" }
		});

		public object dyncsh0 => GetValue(dyncsh0_Property);

		public object dyncsh1 => GetValue(dyncsh1_Property);

		public object ucsh0 => GetValue(ucsh0_Property);

		public object ucsh1 => GetValue(ucsh1_Property);

		public object sht0 => GetValue(sht0_Property);

		public object dyncsh2 => GetValue(dyncsh2_Property);

		public object ucsh2 => GetValue(ucsh2_Property);

		public object sht123 => GetValue(sht123_Property);

		public object ucsh3 => GetValue(ucsh3_Property);

		public object ucsh4 => GetValue(ucsh4_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam")]
	public class MMMixer_Dynam : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabDynam;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		private bool _contentLoaded;

		public MMMixer_Dynam()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabDynam = (MMTabStrip)target;
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
	public class MMMixer_Dynam_Cont_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration FraDynCont_level2cont_Property = CxvPropertyDeclaration.Register("FraDynCont_level2cont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LEVEL2CONT"
		});

		public static readonly CxvPropertyDeclaration ChkDynContll_level2cont_Property = CxvPropertyDeclaration.Register("ChkDynContll_level2cont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.LEVEL2CONT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.FREE4"
			}
		});

		public static readonly CxvPropertyDeclaration ChkDynContp_prescont_Property = CxvPropertyDeclaration.Register("ChkDynContp_prescont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.PRESCONT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT4F1"
			}
		});

		public static readonly CxvPropertyDeclaration ChkDynContl_levelcont_Property = CxvPropertyDeclaration.Register("ChkDynContl_levelcont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.LEVELCONT",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT4F2"
			}
		});

		public object FraDynCont_level2cont => GetValue(FraDynCont_level2cont_Property);

		public object ChkDynContll_level2cont => GetValue(ChkDynContll_level2cont_Property);

		public object ChkDynContp_prescont => GetValue(ChkDynContp_prescont_Property);

		public object ChkDynContl_levelcont => GetValue(ChkDynContl_levelcont_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam_Cont")]
	public class MMMixer_Dynam_Cont : MMTabPage, IComponentConnector
	{
		internal MMGroupBox FraDynCont;

		internal MMCheckBox ChkDynContp;

		internal MMCheckBox ChkDynContl;

		internal MMCheckBox ChkDynContll;

		private bool _contentLoaded;

		public MMMixer_Dynam_Cont()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_Cont_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam_cont.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				FraDynCont = (MMGroupBox)target;
				break;
			case 2:
				ChkDynContp = (MMCheckBox)target;
				break;
			case 3:
				ChkDynContl = (MMCheckBox)target;
				break;
			case 4:
				ChkDynContll = (MMCheckBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Dynam_Eqht_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration FraDynEqpenv_state_Property = CxvPropertyDeclaration.Register("FraDynEqpenv_state", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT2F3"
			}
		});

		public static readonly CxvPropertyDeclaration LbtuDynEqpEnvU_htceqp_Property = CxvPropertyDeclaration.Register("LbtuDynEqpEnvU_htceqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.HTCEQP"
		});

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT2F2"
			}
		});

		public static readonly CxvPropertyDeclaration LbtuDynEqpHCCp_cpeqp_Property = CxvPropertyDeclaration.Register("LbtuDynEqpHCCp_cpeqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.CPEQP"
		});

		public static readonly CxvPropertyDeclaration lbtuDynEqpHCM_masseqp_Property = CxvPropertyDeclaration.Register("lbtuDynEqpHCM_masseqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MASSEQP"
		});

		public static readonly CxvPropertyDeclaration ChkDynEqHT2_ht2env_Property = CxvPropertyDeclaration.Register("ChkDynEqHT2_ht2env", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.HT2ENV",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false,
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT2O2"
			}
		});

		public static readonly CxvPropertyDeclaration ChkDynEqHT1_eqphcp_Property = CxvPropertyDeclaration.Register("ChkDynEqHT1_eqphcp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.EQPHCP",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public object FraDynEqpenv_state => GetValue(FraDynEqpenv_state_Property);

		public object LbtuDynEqpEnvU_htceqp => GetValue(LbtuDynEqpEnvU_htceqp_Property);

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object LbtuDynEqpHCCp_cpeqp => GetValue(LbtuDynEqpHCCp_cpeqp_Property);

		public object lbtuDynEqpHCM_masseqp => GetValue(lbtuDynEqpHCM_masseqp_Property);

		public object ChkDynEqHT2_ht2env => GetValue(ChkDynEqHT2_ht2env_Property);

		public object ChkDynEqHT1_eqphcp => GetValue(ChkDynEqHT1_eqphcp_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam_Eqht")]
	public class MMMixer_Dynam_Eqht : MMTabPage, IComponentConnector
	{
		internal MMGroupBox FraDynEqht;

		internal MMCheckBox ChkDynEqHT1;

		internal MMCheckBox ChkDynEqHT2;

		internal MMGroupBox MMFrame1;

		internal MMLabel lbtuDynEqpHCM_label;

		internal MMVariableEdit lbtuDynEqpHCM;

		internal MMLabel LbtuDynEqpHCCp_label;

		internal MMVariableEdit LbtuDynEqpHCCp;

		internal MMGroupBox FraDynEqpenv;

		internal MMLabel LbtuDynEqpEnvU_label;

		internal MMVariableEdit LbtuDynEqpEnvU;

		private bool _contentLoaded;

		public MMMixer_Dynam_Eqht()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_Eqht_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam_eqht.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				FraDynEqht = (MMGroupBox)target;
				break;
			case 2:
				ChkDynEqHT1 = (MMCheckBox)target;
				break;
			case 3:
				ChkDynEqHT2 = (MMCheckBox)target;
				break;
			case 4:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 5:
				lbtuDynEqpHCM_label = (MMLabel)target;
				break;
			case 6:
				lbtuDynEqpHCM = (MMVariableEdit)target;
				break;
			case 7:
				LbtuDynEqpHCCp_label = (MMLabel)target;
				break;
			case 8:
				LbtuDynEqpHCCp = (MMVariableEdit)target;
				break;
			case 9:
				FraDynEqpenv = (MMGroupBox)target;
				break;
			case 10:
				LbtuDynEqpEnvU_label = (MMLabel)target;
				break;
			case 11:
				LbtuDynEqpEnvU = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Dynam_Init_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraDynInitSpec_state_Property = CxvPropertyDeclaration.Register("fraDynInitSpec_state", typeof(MMMixer_Dynam_Init_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT1F1"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynInitLiq1frac_liq1frac_Property = CxvPropertyDeclaration.Register("lbtuDynInitLiq1frac_liq1frac", typeof(MMMixer_Dynam_Init_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIQ1FRAC",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.FREE3"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynInitLiqfrac_liqfrac_Property = CxvPropertyDeclaration.Register("lbtuDynInitLiqfrac_liqfrac", typeof(MMMixer_Dynam_Init_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LIQFRAC"
		});

		public object fraDynInitSpec_state => GetValue(fraDynInitSpec_state_Property);

		public object lbtuDynInitLiq1frac_liq1frac => GetValue(lbtuDynInitLiq1frac_liq1frac_Property);

		public object lbtuDynInitLiqfrac_liqfrac => GetValue(lbtuDynInitLiqfrac_liqfrac_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam_Init")]
	public class MMMixer_Dynam_Init : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraDynInitSpec;

		internal MMLabel lbtuDynInitLiqfrac_label;

		internal MMVariableEdit lbtuDynInitLiqfrac;

		internal MMLabel lbtuDynInitLiq1frac_label;

		internal MMVariableEdit lbtuDynInitLiq1frac;

		private bool _contentLoaded;

		public MMMixer_Dynam_Init()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_Init_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam_init.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraDynInitSpec = (MMGroupBox)target;
				break;
			case 2:
				lbtuDynInitLiqfrac_label = (MMLabel)target;
				break;
			case 3:
				lbtuDynInitLiqfrac = (MMVariableEdit)target;
				break;
			case 4:
				lbtuDynInitLiq1frac_label = (MMLabel)target;
				break;
			case 5:
				lbtuDynInitLiq1frac = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Dynam_Vessel_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraDynVesselGeom_state_Property = CxvPropertyDeclaration.Register("fraDynVesselGeom_state", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT0F1"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynVesselGeomD_diameter_Property = CxvPropertyDeclaration.Register("lbtuDynVesselGeomD_diameter", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.DIAMETER"
		});

		public static readonly CxvPropertyDeclaration lbtuDynVesselGeomL_length_Property = CxvPropertyDeclaration.Register("lbtuDynVesselGeomL_length", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.LENGTH"
		});

		public static readonly CxvPropertyDeclaration cboDynVesselGeom_MultiMap_Property = CxvPropertyDeclaration.Register("cboDynVesselGeom_MultiMap", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDynVesselGeom_htype",
					DataPath = "@main.Input.HTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Elliptical",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Elliptical",
					Value = "cboDynVesselGeom_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselGeom_htype",
							Value = "ELLIPTICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Hemispherical",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Hemispherical",
					Value = "cboDynVesselGeom_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselGeom_htype",
							Value = "HEMISPHERICAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Flat",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Flat",
					Value = "cboDynVesselGeom_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselGeom_htype",
							Value = "FLAT"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration cboDynVesselType_MultiMap_Property = CxvPropertyDeclaration.Register("cboDynVesselType_MultiMap", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboDynVesselType_mtype",
					DataPath = "@main.Input.MTYPE"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Instantaneous",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Instantaneous",
					Value = "cboDynVesselType_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselType_mtype",
							Value = "INSTANTANEOUS"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Horizontal",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Horizontal",
					Value = "cboDynVesselType_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselType_mtype",
							Value = "HORIZONTAL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vertical",
					DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Vertical",
					Value = "cboDynVesselType_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "cboDynVesselType_mtype",
							Value = "VERTICAL"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT0C1"
			}
		});

		public object fraDynVesselGeom_state => GetValue(fraDynVesselGeom_state_Property);

		public object lbtuDynVesselGeomD_diameter => GetValue(lbtuDynVesselGeomD_diameter_Property);

		public object lbtuDynVesselGeomL_length => GetValue(lbtuDynVesselGeomL_length_Property);

		public object cboDynVesselGeom_MultiMap => GetValue(cboDynVesselGeom_MultiMap_Property);

		public object cboDynVesselType_MultiMap => GetValue(cboDynVesselType_MultiMap_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam_Vessel")]
	public class MMMixer_Dynam_Vessel : MMTabPage, IComponentConnector
	{
		internal MMLabel cboDynVesselType_label;

		internal MMComboEdit cboDynVesselType;

		internal MMGroupBox fraDynVesselGeom;

		internal MMLabel cboDynVesselGeom_label;

		internal MMComboEdit cboDynVesselGeom;

		internal MMLabel lbtuDynVesselGeomL_label;

		internal MMVariableEdit lbtuDynVesselGeomL;

		internal MMLabel lbtuDynVesselGeomD_label;

		internal MMVariableEdit lbtuDynVesselGeomD;

		private bool _contentLoaded;

		public MMMixer_Dynam_Vessel()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_Vessel_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam_vessel.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				cboDynVesselType_label = (MMLabel)target;
				break;
			case 2:
				cboDynVesselType = (MMComboEdit)target;
				break;
			case 3:
				fraDynVesselGeom = (MMGroupBox)target;
				break;
			case 4:
				cboDynVesselGeom_label = (MMLabel)target;
				break;
			case 5:
				cboDynVesselGeom = (MMComboEdit)target;
				break;
			case 6:
				lbtuDynVesselGeomL_label = (MMLabel)target;
				break;
			case 7:
				lbtuDynVesselGeomL = (MMVariableEdit)target;
				break;
			case 8:
				lbtuDynVesselGeomD_label = (MMLabel)target;
				break;
			case 9:
				lbtuDynVesselGeomD = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Dynam_VWall_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration frmDynVWHT_state_Property = CxvPropertyDeclaration.Register("frmDynVWHT_state", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT3F1"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynVWL3_wallhtcdry_Property = CxvPropertyDeclaration.Register("lbtuDynVWL3_wallhtcdry", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.WALLHTCDRY",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT3L3"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynVWL2_wallhtcwet_Property = CxvPropertyDeclaration.Register("lbtuDynVWL2_wallhtcwet", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.WALLHTCWET",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT3L2"
			}
		});

		public static readonly CxvPropertyDeclaration lbtuDynVWL1_wallhtc_Property = CxvPropertyDeclaration.Register("lbtuDynVWL1_wallhtc", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.WALLHTC",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.SHT3L1"
			}
		});

		public static readonly CxvPropertyDeclaration chkDynVWHT_wetht_Property = CxvPropertyDeclaration.Register("chkDynVWHT_wetht", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.WETHT",
			TrueValue = "YES",
			FalseValue = "NO"
		});

		public object frmDynVWHT_state => GetValue(frmDynVWHT_state_Property);

		public object lbtuDynVWL3_wallhtcdry => GetValue(lbtuDynVWL3_wallhtcdry_Property);

		public object lbtuDynVWL2_wallhtcwet => GetValue(lbtuDynVWL2_wallhtcwet_Property);

		public object lbtuDynVWL1_wallhtc => GetValue(lbtuDynVWL1_wallhtc_Property);

		public object chkDynVWHT_wetht => GetValue(chkDynVWHT_wetht_Property);
	}
	[ProgId("MMMixer.MMMixer_Dynam_VWall")]
	public class MMMixer_Dynam_VWall : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmDynVWHT;

		internal MMCheckBox chkDynVWHT;

		internal MMLabel lbtuDynVWL1_label;

		internal MMVariableEdit lbtuDynVWL1;

		internal MMLabel lbtuDynVWL2_label;

		internal MMVariableEdit lbtuDynVWL2;

		internal MMLabel lbtuDynVWL3_label;

		internal MMVariableEdit lbtuDynVWL3;

		private bool _contentLoaded;

		public MMMixer_Dynam_VWall()
		{
			base.ViewModelType = typeof(MMMixer_Dynam_VWall_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_dynam_vwall.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				frmDynVWHT = (MMGroupBox)target;
				break;
			case 2:
				chkDynVWHT = (MMCheckBox)target;
				break;
			case 3:
				lbtuDynVWL1_label = (MMLabel)target;
				break;
			case 4:
				lbtuDynVWL1 = (MMVariableEdit)target;
				break;
			case 5:
				lbtuDynVWL2_label = (MMLabel)target;
				break;
			case 6:
				lbtuDynVWL2 = (MMVariableEdit)target;
				break;
			case 7:
				lbtuDynVWL3_label = (MMLabel)target;
				break;
			case 8:
				lbtuDynVWL3 = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Eoopti_Model_ViewModel : MMTabPageViewModel
	{
		public class grdScMeth_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox5_var1",
						DataPath = "@main.Input.SC_METHOD.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "INIT",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
						Value = "MMComboBox5_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "INIT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "PRESOLVE",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
						Value = "MMComboBox5_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "PRESOLVE"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "POSTSOLVE",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
						Value = "MMComboBox5_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "POSTSOLVE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.USER_METHOD.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.GLOBALSCRIPT.@y",
				DisplayedCase = CxsDisplayedCase.Lowercase,
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.GLOBSC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MultimapOptionScriptType",
						DataPath = "@main.Input.SC_TYPE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Localscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
						Value = "LOCALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "LOCALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Globalscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
						Value = "GLOBALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "GLOBALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "File",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
						Value = "FILE",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "FILE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.LOCALSCRIPT.@y",
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.LOCASC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FILE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase,
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.FILESC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.GLOBSC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.GLOBALSCRIPT.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.LOCASC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.LOCALSCRIPT.@y"
						}
					}
				}
			});

			public object MMComboBox5_MultiMap => GetValue(MMComboBox5_MultiMap_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMComboBox4_var1 => GetValue(MMComboBox4_var1_Property);

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

			public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object ID => GetValue(ID_Property);
		}

		private ICommand _cmdAddOpt_Command;

		private ICommand _cmdAddVar_Command;

		private ICommand _cmdAddInput_Command;

		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
		{
			DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
		});

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_COMPS_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
					DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
					DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_COMPS"
		});

		public static readonly CxvPropertyDeclaration cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RTOPT"
			}
		});

		public static readonly CxvPropertyDeclaration grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdScMeth_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.SC_METHOD",
				UseChildId = true,
				Name = "y"
			}
		});

		private ICommand _cmdBrowse_Command;

		private bool _blkType = true;

		private DelegateCommand<object> _cmdEdit_Command;

		private ObservableCollection<int> _selectedRowIndexes;

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

		public ICommand cmdAddVar_Command
		{
			get
			{
				if (_cmdAddVar_Command == null)
				{
					_cmdAddVar_Command = new CxvDelegateCommand<object>(cmdAddVar_CommandExecute);
				}
				return _cmdAddVar_Command;
			}
		}

		public ICommand cmdAddInput_Command
		{
			get
			{
				if (_cmdAddInput_Command == null)
				{
					_cmdAddInput_Command = new CxvDelegateCommand<object>(cmdAddInput_CommandExecute);
				}
				return _cmdAddInput_Command;
			}
		}

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox6_MultiMap => GetValue(MMComboBox6_MultiMap_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cmdAddVar_var1 => GetValue(cmdAddVar_var1_Property);

		public object grdScMeth_GridData => GetValue(grdScMeth_GridData_Property);

		public ICommand cmdBrowse_Command
		{
			get
			{
				if (_cmdBrowse_Command == null)
				{
					_cmdBrowse_Command = new CxvDelegateCommand<object>(cmdBrowse_CommandExecute);
				}
				return _cmdBrowse_Command;
			}
		}

		public bool BlkType
		{
			get
			{
				string text = ExpandDataPathAndGet("@main", "type") as string;
				if (!string.IsNullOrEmpty(text) && text.ToUpperInvariant() == "QTVEC")
				{
					_blkType = false;
				}
				return _blkType;
			}
		}

		public DelegateCommand<object> cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new DelegateCommand<object>(cmdEdit_CommandExecute, cmdEdit_CommandCanExecute);
				}
				return _cmdEdit_Command;
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
					_selectedRowIndexes = value;
					_selectedRowIndexes.CollectionChanged -= delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
					_selectedRowIndexes.CollectionChanged += delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
				}
			}
		}

		private void cmdBrowse_CommandExecute(object parameter)
		{
			AesXamValueEditBrowse aesXamValueEditBrowse = parameter as AesXamValueEditBrowse;
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.RestoreDirectory = true;
			if (aesXamValueEditBrowse.Value != null && !string.IsNullOrEmpty(aesXamValueEditBrowse.Value.ToString()))
			{
				openFileDialog.FileName = aesXamValueEditBrowse.Value.ToString();
			}
			if (openFileDialog.ShowDialog().Value)
			{
				aesXamValueEditBrowse.Value = openFileDialog.FileName;
			}
		}

		private void cmdAddOpt_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddOpt",
				LegacyFlags = 0,
				HelpId = 177,
				HelpFile = "common.hlp",
				ShowPrompts = true,
				CompleteDataPaths = new string[1] { "@main.CC Nodes.l2cp2" },
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AdditionalOptions
			});
		}

		private void cmdAddVar_CommandExecute(object parameter)
		{
			string text = ExpandDataPathAndGet("@main", "type") as string;
			if (!string.IsNullOrEmpty(text))
			{
				DisplayFormEventArgs e = new DisplayFormEventArgs();
				e.LegacyFlags = 0;
				switch (text.ToUpperInvariant())
				{
				case "MIXER":
					e.FormProgId = "MMMixer.MMMixer_RTOpt_Input";
					break;
				case "FLASH2":
				case "HEATER":
					e.FormProgId = "MMFlash2.MMFlash2_RTOpt_Input";
					break;
				case "FSPLIT":
					e.FormProgId = "MMFSplit.MMFSplit_RTOpt_Input";
					break;
				case "FEEDBL":
				case "ANALYZER":
					e.FormProgId = "MMStrvar.MMStrvar_RTOpt_Input";
					break;
				case "RADFRAC":
					e.FormProgId = "MMRadfrac.MMRadfrac_RTOpt";
					e.LegacyFlags = 4;
					break;
				}
				if (!string.IsNullOrEmpty(e.FormProgId))
				{
					e.HelpId = 186;
					e.HelpFile = "Common.hlp";
					e.ShowPrompts = true;
					e.ShortName = Resources.MMFsplit_Eoopti_Model_ViewModel_AddtionalVariables;
					DisplayForm(e);
				}
			}
		}

		private void cmdAddInput_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddInp",
				LegacyFlags = 0,
				HelpId = 193,
				HelpFile = "common.hlp",
				ShowPrompts = true,
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AddInput
			});
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (_selectedRowIndexes.Count != 1)
			{
				return;
			}
			int num = _selectedRowIndexes[0];
			if (num < 0)
			{
				return;
			}
			grdScMeth_GridData_ItemTemplate container = (grdScMeth_GridData as IList)[num] as grdScMeth_GridData_ItemTemplate;
			string strA = container.ResolveViewPropertyPath("MMComboBox2_var1.Value") as string;
			string text = container.ResolveViewPropertyPath("ID.Value") as string;
			string text2 = CxsConverter.ValueToString(ResolveParameter("main", null));
			int num2 = text2.LastIndexOf("Data");
			text2 = ((num2 <= 0) ? "Top.appModelV8" : text2.Substring(0, num2 + 4));
			text2 += ".EO Configuration.";
			if (string.Compare(strA, "LOCALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_LocScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_LocalScript
					};
					string text3 = text2 + "Local Scripts.";
					e.Parameters.Add("Input", text3 + text + ".Input");
					DisplayForm(e);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
			else if (string.Compare(strA, "GLOBALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e2 = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_GloScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_GlobalScript
					};
					string text4 = text2 + "Global Scripts.";
					e2.Parameters.Add("Input", text4 + text + ".Input");
					DisplayForm(e2);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
		}

		private bool cmdEdit_CommandCanExecute(object parameter)
		{
			if (_selectedRowIndexes != null && _selectedRowIndexes.Count == 1)
			{
				int num = _selectedRowIndexes[0];
				IList list = grdScMeth_GridData as IList;
				if (num >= 0 && num < list.Count - 1)
				{
					string text = (list[num] as grdScMeth_GridData_ItemTemplate).ResolveViewPropertyPath("MMComboBox2_var1.Value") as string;
					if (!string.IsNullOrEmpty(text))
					{
						return string.Compare(text, "File", StringComparison.InvariantCultureIgnoreCase) != 0;
					}
					return false;
				}
			}
			return false;
		}
	}
	[ProgId("MMMixer.MMMixer_Eoopti_Model")]
	public class MMMixer_Eoopti_Model : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMLBUText10_label;

		internal MMVariableEdit MMLBUText10;

		internal MMCmdButton cmdAddOpt;

		internal MMCmdButton cmdAddVar;

		internal MMCmdButton cmdAddInput;

		internal MMGroupBox MMFrame2;

		internal MMScrollArea grdScMeth;

		internal MMCmdButton cmdEdit;

		private bool _contentLoaded;

		public MMMixer_Eoopti_Model()
		{
			base.ViewModelType = typeof(MMMixer_Eoopti_Model_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_eoopti_model.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
			case 9:
				cmdAddVar = (MMCmdButton)target;
				break;
			case 10:
				cmdAddInput = (MMCmdButton)target;
				break;
			case 11:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 12:
				grdScMeth = (MMScrollArea)target;
				break;
			case 13:
				cmdEdit = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_EOPort_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration id2_Property = CxvPropertyDeclaration.Register("id2", typeof(MMMixer_EOPort_ViewModel), new CxvParameterProperty
		{
			Parameter = "id2"
		});

		public static readonly CxvPropertyDeclaration eopt1_Property = CxvPropertyDeclaration.Register("eopt1", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOPT1.@id"
		});

		public static readonly CxvPropertyDeclaration eoent1_Property = CxvPropertyDeclaration.Register("eoent1", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT1.@id"
		});

		public static readonly CxvPropertyDeclaration eoent2_Property = CxvPropertyDeclaration.Register("eoent2", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT2.@id"
		});

		public static readonly CxvPropertyDeclaration eopt4_Property = CxvPropertyDeclaration.Register("eopt4", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOPT4.@id"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_EOPort_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@eopt1", "@eopt4" },
			EnteredDataPaths = { "@eoent1" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_EOPort_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@eoent2" }
		});

		public object id2 => GetValue(id2_Property);

		public object eopt1 => GetValue(eopt1_Property);

		public object eoent1 => GetValue(eoent1_Property);

		public object eoent2 => GetValue(eoent2_Property);

		public object eopt4 => GetValue(eopt4_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMMixer.MMMixer_EOPort")]
	public class MMMixer_EOPort : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		private bool _contentLoaded;

		public MMMixer_EOPort()
		{
			base.ViewModelType = typeof(MMMixer_EOPort_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_eoport.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_EOPort_Advanc_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvGroupBoxProperty
		{
			DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_PT_COMP.@id.@id2",
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EOPT2.@id.@id2"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox5_var1",
					DataPath = "@main.Input.EO_PT_PHASE.@id.@id2"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "MMComboBox5_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox5_var1",
							Value = "V"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "MMComboBox5_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox5_var1",
							Value = "L"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "MMComboBox5_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox5_var1",
							Value = "VL"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "MMComboBox5_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox5_var1",
							Value = "VLW"
						}
					}
				}
			},
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.EOPT2.@id.@id2"
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox2_var1",
					DataPath = "@main.Input.EO_PT_TYPE.@id.@id2"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Material stream (flow basis)",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Material_stream__flow_basis_",
					Value = "MMComboBox2_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "MOLE-FLOW"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Material stream (fraction basis)",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Material_stream__fraction_basis_",
					Value = "MMComboBox2_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "MOLE-FRAC"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Heat stream",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Heat_stream",
					Value = "MMComboBox2_MultiMapOption_3",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "HEAT"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Work stream",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Work_stream",
					Value = "MMComboBox2_MultiMapOption_4",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "WORK"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Generic collection",
					DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Generic_collection",
					Value = "MMComboBox2_MultiMapOption_5",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox2_var1",
							Value = "GENERIC"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox2_Enabled_Property = CxvPropertyDeclaration.Register("MMComboBox2_Enabled", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvLogicalProperty
		{
			DataPath = "@main.Input.EO_PT_VALUE.@id",
			DataAttribute = "child_count",
			Operator = CxvLogicalOperator.GreaterThan,
			Value = 0
		});

		public object MMFrame1_state => GetValue(MMFrame1_state_Property);

		public object MMComboBox6_var1 => GetValue(MMComboBox6_var1_Property);

		public object MMComboBox5_MultiMap => GetValue(MMComboBox5_MultiMap_Property);

		public object MMComboBox2_MultiMap => GetValue(MMComboBox2_MultiMap_Property);

		public object MMComboBox2_Enabled => GetValue(MMComboBox2_Enabled_Property);

		protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
		{
			base.OnSubPropertyDataChanged(pd, subPropertyName);
			if (pd == MMComboBox2_Enabled_Property && subPropertyName == "Value")
			{
				if (MMComboBox2_Enabled is CxvLogicalPropertyData { Value: not false })
				{
					ResolveUpdateParameter("id2", "#0");
				}
				else
				{
					ResolveUpdateParameter("id2", null);
				}
			}
		}

		protected override void OnUpdateData()
		{
			base.OnUpdateData();
			if (base.IsInitialUpdate)
			{
				if (MMComboBox2_Enabled is CxvLogicalPropertyData { Value: not false })
				{
					ResolveUpdateParameter("id2", "#0");
				}
				else
				{
					ResolveUpdateParameter("id2", null);
				}
			}
		}
	}
	[ProgId("MMMixer.MMMixer_EOPort_Advanc")]
	public class MMMixer_EOPort_Advanc : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1;

		internal MMLabel MMComboBox2_label;

		internal MMComboEdit MMComboBox2;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMComboBox5_label;

		internal MMComboEdit MMComboBox5;

		internal MMLabel MMAdvCombo1_label;

		internal MMComboEdit MMAdvCombo1;

		private bool _contentLoaded;

		public MMMixer_EOPort_Advanc()
		{
			base.ViewModelType = typeof(MMMixer_EOPort_Advanc_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_eoport_advanc.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				MMComboBox6_label = (MMLabel)target;
				break;
			case 5:
				MMComboBox6 = (MMComboEdit)target;
				break;
			case 6:
				MMComboBox5_label = (MMLabel)target;
				break;
			case 7:
				MMComboBox5 = (MMComboEdit)target;
				break;
			case 8:
				MMAdvCombo1_label = (MMLabel)target;
				break;
			case 9:
				MMAdvCombo1 = (MMComboEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_EOPort_ObjMan_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration SubobjectNode_Property = CxvPropertyDeclaration.Register("SubobjectNode", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main"
		});

		public static readonly CxvPropertyDeclaration eoent1_Property = CxvPropertyDeclaration.Register("eoent1", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT1"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@SubobjectNode" },
			EnteredDataPaths = { "@eoent1" }
		});

		public object SubobjectNode => GetValue(SubobjectNode_Property);

		public object eoent1 => GetValue(eoent1_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMMixer.MMMixer_EOPort_ObjMan")]
	public class MMMixer_EOPort_ObjMan : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMTabStrip1;

		internal MMTabItem tab0;

		private bool _contentLoaded;

		public MMMixer_EOPort_ObjMan()
		{
			base.ViewModelType = typeof(MMMixer_EOPort_ObjMan_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_eoport_objman.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMMixer_EOPort_Setup_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.EO_PT_PHYSQT.@id.@y",
				DisplayedCase = CxsDisplayedCase.Lowercase,
				Sorted = true
			});

			public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvBooleanProperty
			{
				DataPath = "@main.Input.THRU.@id.@y",
				TrueValue = "YES",
				FalseValue = "NO",
				DefaultValue = false
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.EO_PT_VALUE.@id.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.EO_PT_VALUE.@id.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.EO_PT_UOM.@id.@y",
				Sorted = true,
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.EOPT3.@id.@y"
				}
			});

			public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

			public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMMixer_EOPort_Setup_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.EO_PT_VALUE.@id",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMMixer.MMMixer_EOPort_Setup")]
	public class MMMixer_EOPort_Setup : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame2;

		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMMixer_EOPort_Setup()
		{
			base.ViewModelType = typeof(MMMixer_EOPort_Setup_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_eoport_setup.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMMixer_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MN2"
		});

		public static readonly CxvPropertyDeclaration phase_Property = CxvPropertyDeclaration.Register("phase", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.FREE2"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration flasho_Property = CxvPropertyDeclaration.Register("flasho", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.HEATWORK1"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@phase", "@spec" },
			AccessibleDataPaths = { "@flasho" },
			EnteredDataPaths = { "@entfls" }
		});

		public object spec => GetValue(spec_Property);

		public object phase => GetValue(phase_Property);

		public object entfls => GetValue(entfls_Property);

		public object flasho => GetValue(flasho_Property);

		public object tab0_var => GetValue(tab0_var_Property);
	}
	[ProgId("MMMixer.MMMixer_Input")]
	public class MMMixer_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMMixer_Input()
		{
			base.ViewModelType = typeof(MMMixer_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMMixer_Input_Flasho_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMMixer_Input_Flasho_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Input.NPHASE"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Input.PHASE"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var3",
					DataPath = "@main.Input.BLKOPFREWAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_ex",
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
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__ar",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__a",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__a",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES"
		});

		public static readonly CxvPropertyDeclaration lbtuTolerance_var1_Property = CxvPropertyDeclaration.Register("lbtuTolerance_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL"
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT"
		});

		public static readonly CxvPropertyDeclaration lbtuTempEst_var1_Property = CxvPropertyDeclaration.Register("lbtuTempEst_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.T_EST"
		});

		private bool _rentry;

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object lbtuTolerance_var1 => GetValue(lbtuTolerance_var1_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);

		public object lbtuTempEst_var1 => GetValue(lbtuTempEst_var1_Property);

		protected override void OnUpdateData()
		{
			if (_rentry)
			{
				return;
			}
			_rentry = true;
			if (base.IsInitialUpdate)
			{
				string path = ExpandDataPath("@main") + ".Input.VISITED";
				if ((CxsConverter.ValueToInt32(base.ResolvedCxsProvider.BatchGet(path, "value", null)) ?? 0) == 0)
				{
					base.ResolvedCxsProvider.BatchSet(path, "value", null, 1);
				}
			}
			base.OnUpdateData();
			_rentry = false;
		}
	}
	[ProgId("MMMixer.MMMixer_Input_Flasho")]
	public class MMMixer_Input_Flasho : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraSpecif;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMGroupBox fraTempest;

		internal MMVariableEdit lbtuTempEst;

		internal MMGroupBox fraFlashOptions;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTolerance_label;

		internal MMVariableEdit lbtuTolerance;

		private bool _contentLoaded;

		public MMMixer_Input_Flasho()
		{
			base.ViewModelType = typeof(MMMixer_Input_Flasho_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_input_flasho.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraSpecif = (MMGroupBox)target;
				break;
			case 2:
				lbtuPres_label = (MMLabel)target;
				break;
			case 3:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 4:
				cboPhase_label = (MMLabel)target;
				break;
			case 5:
				cboPhase = (MMComboEdit)target;
				break;
			case 6:
				fraTempest = (MMGroupBox)target;
				break;
			case 7:
				lbtuTempEst = (MMVariableEdit)target;
				break;
			case 8:
				fraFlashOptions = (MMGroupBox)target;
				break;
			case 9:
				spnMaxit_label = (MMLabel)target;
				break;
			case 10:
				spnMaxit = (MMSpinBox)target;
				break;
			case 11:
				lbtuTolerance_label = (MMLabel)target;
				break;
			case 12:
				lbtuTolerance = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Result_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration b_temp_Property = CxvPropertyDeclaration.Register("b_temp", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.B_TEMP"
		});

		public static readonly CxvPropertyDeclaration b_pres_Property = CxvPropertyDeclaration.Register("b_pres", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.B_PRES"
		});

		public static readonly CxvPropertyDeclaration bal1_Property = CxvPropertyDeclaration.Register("bal1", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.BAL_MOLI_TFL"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@b_temp", "@b_pres" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Result_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@bal1" }
		});

		public object b_temp => GetValue(b_temp_Property);

		public object b_pres => GetValue(b_pres_Property);

		public object bal1 => GetValue(bal1_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);
	}
	[ProgId("MMMixer.MMMixer_Result")]
	public class MMMixer_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMMixer_Result()
		{
			base.ViewModelType = typeof(MMMixer_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_Result_Summar_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtu1stLiq_var1_Property = CxvPropertyDeclaration.Register("lbtu1stLiq_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.LIQ_RATIO"
		});

		public static readonly CxvPropertyDeclaration lbtuVaporFrac_var1_Property = CxvPropertyDeclaration.Register("lbtuVaporFrac_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.B_VFRAC"
		});

		public static readonly CxvPropertyDeclaration lbtuOutPres_var1_Property = CxvPropertyDeclaration.Register("lbtuOutPres_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.B_PRES"
		});

		public static readonly CxvPropertyDeclaration lbtuOutTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuOutTemp_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.B_TEMP"
		});

		public static readonly CxvPropertyDeclaration lbtuPdrop_var1_Property = CxvPropertyDeclaration.Register("lbtuPdrop_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Output.PDROP"
		});

		public object lbtu1stLiq_var1 => GetValue(lbtu1stLiq_var1_Property);

		public object lbtuVaporFrac_var1 => GetValue(lbtuVaporFrac_var1_Property);

		public object lbtuOutPres_var1 => GetValue(lbtuOutPres_var1_Property);

		public object lbtuOutTemp_var1 => GetValue(lbtuOutTemp_var1_Property);

		public object lbtuPdrop_var1 => GetValue(lbtuPdrop_var1_Property);
	}
	[ProgId("MMMixer.MMMixer_Result_Summar")]
	public class MMMixer_Result_Summar : MMTabPage, IComponentConnector
	{
		internal MMLabel lbtuOutTemp_label;

		internal MMVariableEdit lbtuOutTemp;

		internal MMLabel lbtuOutPres_label;

		internal MMVariableEdit lbtuOutPres;

		internal MMLabel lbtuVaporFrac_label;

		internal MMVariableEdit lbtuVaporFrac;

		internal MMLabel lbtu1stLiq_label;

		internal MMVariableEdit lbtu1stLiq;

		internal MMLabel lbtuPdrop_label;

		internal MMVariableEdit lbtuPdrop;

		private bool _contentLoaded;

		public MMMixer_Result_Summar()
		{
			base.ViewModelType = typeof(MMMixer_Result_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_result_summar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lbtuOutTemp_label = (MMLabel)target;
				break;
			case 2:
				lbtuOutTemp = (MMVariableEdit)target;
				break;
			case 3:
				lbtuOutPres_label = (MMLabel)target;
				break;
			case 4:
				lbtuOutPres = (MMVariableEdit)target;
				break;
			case 5:
				lbtuVaporFrac_label = (MMLabel)target;
				break;
			case 6:
				lbtuVaporFrac = (MMVariableEdit)target;
				break;
			case 7:
				lbtu1stLiq_label = (MMLabel)target;
				break;
			case 8:
				lbtu1stLiq = (MMVariableEdit)target;
				break;
			case 9:
				lbtuPdrop_label = (MMLabel)target;
				break;
			case 10:
				lbtuPdrop = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMMixer_RTOpt_Input_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMMixer_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_DPI",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMMixer_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_PRES",
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

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			UpdateAll();
			CloseForm();
		}
	}
	[ProgId("MMMixer.MMMixer_RTOpt_Input")]
	public class MMMixer_RTOpt_Input : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraInlet;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox2;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMMixer_RTOpt_Input()
		{
			base.ViewModelType = typeof(MMMixer_RTOpt_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/mixer/mmmixer_rtopt_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraInlet = (MMGroupBox)target;
				break;
			case 2:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 3:
				MMCheckBox2 = (MMCheckBox)target;
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
namespace AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit
{
	public class MMFsplit_Blocko_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.BKOP"
		});

		public static readonly CxvPropertyDeclaration entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKPR"
		});

		public static readonly CxvPropertyDeclaration entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKSI"
		});

		public static readonly CxvPropertyDeclaration entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKDG"
		});

		public static readonly CxvPropertyDeclaration entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTBLKRP"
		});

		public static readonly CxvPropertyDeclaration genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.GENBLKOP"
		});

		public static readonly CxvPropertyDeclaration entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTIPT"
		});

		public static readonly CxvPropertyDeclaration entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTADD"
		});

		public static readonly CxvPropertyDeclaration entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTEOMOD"
		});

		public static readonly CxvPropertyDeclaration smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMSPEC"
		});

		public static readonly CxvPropertyDeclaration sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.SMENT"
		});

		public static readonly CxvPropertyDeclaration eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EODEF"
		});

		public static readonly CxvPropertyDeclaration eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.EOENT"
		});

		public static readonly CxvPropertyDeclaration varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMFsplit_Blocko_ViewModel), new CxvParameterProperty
		{
			Parameter = "varno"
		});

		public static readonly CxvPropertyDeclaration l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.L2CP2"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@blkops", "@genblk" },
			EnteredDataPaths = { "@entpro" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entsim" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entdia" }
		});

		public static readonly CxvPropertyDeclaration tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@l2cp2", "@smspec" },
			EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@sment" }
		});

		public static readonly CxvPropertyDeclaration tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@eodef" },
			EnteredDataPaths = { "@eoent" }
		});

		public static readonly CxvPropertyDeclaration tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
		{
			EnteredDataPaths = { "@entrep" }
		});

		public object blkops => GetValue(blkops_Property);

		public object entpro => GetValue(entpro_Property);

		public object entsim => GetValue(entsim_Property);

		public object entdia => GetValue(entdia_Property);

		public object entrep => GetValue(entrep_Property);

		public object genblk => GetValue(genblk_Property);

		public object entitp => GetValue(entitp_Property);

		public object entadd => GetValue(entadd_Property);

		public object entmod => GetValue(entmod_Property);

		public object smspec => GetValue(smspec_Property);

		public object sment => GetValue(sment_Property);

		public object eodef => GetValue(eodef_Property);

		public object eoent => GetValue(eoent_Property);

		public object varno => GetValue(varno_Property);

		public object l2cp2 => GetValue(l2cp2_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);

		public object tab3_var => GetValue(tab3_var_Property);

		public object tab4_var => GetValue(tab4_var_Property);

		public object tab5_var => GetValue(tab5_var_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Blocko")]
	public class MMFsplit_Blocko : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tab3;

		internal MMTabItem tab4;

		internal MMTabItem tab5;

		private bool _contentLoaded;

		public MMFsplit_Blocko()
		{
			base.ViewModelType = typeof(MMFsplit_Blocko_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_blocko.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
	public class MMFsplit_Eoopti_Model_ViewModel : MMTabPageViewModel
	{
		public class grdScMeth_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.LOCALSCRIPT.@y",
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.LOCASC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MultimapOptionScriptType",
						DataPath = "@main.Input.SC_TYPE.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "Localscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
						Value = "LOCALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "LOCALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "Globalscript",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
						Value = "GLOBALSCRIPT",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "GLOBALSCRIPT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "File",
						DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
						Value = "FILE",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MultimapOptionScriptType",
								Value = "FILE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.String,
				DataPath = "@main.Input.GLOBALSCRIPT.@y",
				DisplayedCase = CxsDisplayedCase.Lowercase,
				IsVisibleCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.GLOBSC.@y"
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.USER_METHOD.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase
			});

			public static readonly CxvPropertyDeclaration MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
			{
				Variables = 
				{
					new CxvMultiMapVariable
					{
						Name = "MMComboBox5_var1",
						DataPath = "@main.Input.SC_METHOD.@y"
					}
				},
				Options = 
				{
					new CxvMultiMapOption
					{
						Display = "INIT",
						DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
						Value = "MMComboBox5_MultiMapOption_1",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "INIT"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "PRESOLVE",
						DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
						Value = "MMComboBox5_MultiMapOption_2",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "PRESOLVE"
							}
						}
					},
					new CxvMultiMapOption
					{
						Display = "POSTSOLVE",
						DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
						Value = "MMComboBox5_MultiMapOption_3",
						Values = 
						{
							new CxvMultiMapValue
							{
								Variable = "MMComboBox5_var1",
								Value = "POSTSOLVE"
							}
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.GLOBSC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.GLOBALSCRIPT.@y"
						}
					},
					new CxvPropertyChoice
					{
						Conditions = 
						{
							new CxvLogicalTest
							{
								DataPath = "@main.CC_Nodes.LOCASC.@y"
							}
						},
						Property = new CxvVariableProperty
						{
							ExposeAs = CxvVariableTypeCode.String,
							DataPath = "@main.Input.LOCALSCRIPT.@y"
						}
					}
				}
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.FILE.@y",
				DisplayedCase = CxsDisplayedCase.Uppercase,
				IsEnabledCondition = new CxvLogicalTest
				{
					DataPath = "@main.CC Nodes.FILESC.@y"
				}
			});

			public object MMComboBox3_var1 => GetValue(MMComboBox3_var1_Property);

			public object MMComboBox2_var1 => GetValue(MMComboBox2_var1_Property);

			public object MMComboBox4_var1 => GetValue(MMComboBox4_var1_Property);

			public object MMTextBox3_var1 => GetValue(MMTextBox3_var1_Property);

			public object MMComboBox5_MultiMap => GetValue(MMComboBox5_MultiMap_Property);

			public object ID => GetValue(ID_Property);

			public object MMTextBox2_var1 => GetValue(MMTextBox2_var1_Property);
		}

		private ICommand _cmdAddOpt_Command;

		private ICommand _cmdAddVar_Command;

		private ICommand _cmdAddInput_Command;

		public static readonly CxvPropertyDeclaration MMFrame1_0_state_Property = CxvPropertyDeclaration.Register("MMFrame1_0_state", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
		{
			DisabledPrompt = Resources.MMFsplit_Eoopti_Model_ViewModel_MMframe1_0_state_DisabledPrompt
		});

		public static readonly CxvPropertyDeclaration MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
					DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
					DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
					DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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

		public static readonly CxvPropertyDeclaration MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.AUTO_COMPS_T"
		});

		public static readonly CxvPropertyDeclaration MMComboBox8_1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_1_MultiMap", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "MMComboBox8_1_var1",
					DataPath = "@main.Input.SPLIT_RATIO"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Yes",
					DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Yes",
					Value = "MMComboBox8_1_MultiMapOption_1",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox8_1_var1",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "No",
					DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No",
					Value = "MMComboBox8_1_MultiMapOption_2",
					Values = 
					{
						new CxvMultiMapValue
						{
							Variable = "MMComboBox8_1_var1",
							Value = "NO"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.String,
			DataPath = "@main.Input.EO_COMPS"
		});

		public static readonly CxvPropertyDeclaration cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				DataPath = "@main.CC Nodes.RTOPT"
			}
		});

		public static readonly CxvPropertyDeclaration grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdScMeth_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.SC_METHOD",
				UseChildId = true,
				Name = "y"
			}
		});

		private ICommand _cmdBrowse_Command;

		private DelegateCommand<object> _cmdEdit_Command;

		private ObservableCollection<int> _selectedRowIndexes;

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

		public ICommand cmdAddVar_Command
		{
			get
			{
				if (_cmdAddVar_Command == null)
				{
					_cmdAddVar_Command = new CxvDelegateCommand<object>(cmdAddVar_CommandExecute);
				}
				return _cmdAddVar_Command;
			}
		}

		public ICommand cmdAddInput_Command
		{
			get
			{
				if (_cmdAddInput_Command == null)
				{
					_cmdAddInput_Command = new CxvDelegateCommand<object>(cmdAddInput_CommandExecute);
				}
				return _cmdAddInput_Command;
			}
		}

		public object MMFrame1_0_state => GetValue(MMFrame1_0_state_Property);

		public object MMComboBox6_MultiMap => GetValue(MMComboBox6_MultiMap_Property);

		public object MMLBUText10_var1 => GetValue(MMLBUText10_var1_Property);

		public object MMComboBox8_1_MultiMap => GetValue(MMComboBox8_1_MultiMap_Property);

		public object MMComboBox1_var1 => GetValue(MMComboBox1_var1_Property);

		public object cmdAddVar_var1 => GetValue(cmdAddVar_var1_Property);

		public object grdScMeth_GridData => GetValue(grdScMeth_GridData_Property);

		public ICommand cmdBrowse_Command
		{
			get
			{
				if (_cmdBrowse_Command == null)
				{
					_cmdBrowse_Command = new CxvDelegateCommand<object>(cmdBrowse_CommandExecute);
				}
				return _cmdBrowse_Command;
			}
		}

		public DelegateCommand<object> cmdEdit_Command
		{
			get
			{
				if (_cmdEdit_Command == null)
				{
					_cmdEdit_Command = new DelegateCommand<object>(cmdEdit_CommandExecute, cmdEdit_CommandCanExecute);
				}
				return _cmdEdit_Command;
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
					_selectedRowIndexes = value;
					_selectedRowIndexes.CollectionChanged -= delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
					_selectedRowIndexes.CollectionChanged += delegate
					{
						cmdEdit_Command.RaiseCanExecuteChanged();
					};
				}
			}
		}

		private void cmdBrowse_CommandExecute(object parameter)
		{
			AesXamValueEditBrowse aesXamValueEditBrowse = parameter as AesXamValueEditBrowse;
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.RestoreDirectory = true;
			if (aesXamValueEditBrowse.Value != null && !string.IsNullOrEmpty(aesXamValueEditBrowse.Value.ToString()))
			{
				openFileDialog.FileName = aesXamValueEditBrowse.Value.ToString();
			}
			if (openFileDialog.ShowDialog().Value)
			{
				aesXamValueEditBrowse.Value = openFileDialog.FileName;
			}
		}

		private void cmdAddOpt_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddOpt",
				LegacyFlags = 0,
				HelpId = 177,
				HelpFile = "Common.hlp",
				ShowPrompts = true,
				CompleteDataPaths = new string[1] { "@main.CC Nodes.l2cp2" },
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AdditionalOptions
			});
		}

		private void cmdAddVar_CommandExecute(object parameter)
		{
			string text = ExpandDataPathAndGet("@main", "type") as string;
			if (!string.IsNullOrEmpty(text))
			{
				DisplayFormEventArgs e = new DisplayFormEventArgs();
				e.LegacyFlags = 0;
				switch (text.ToUpperInvariant())
				{
				case "MIXER":
					e.FormProgId = "MMMixer.MMMixer_RTOpt_Input";
					break;
				case "HEATER":
				case "FLASH2":
					e.FormProgId = "MMFlash2.MMFlash2_RTOpt_Input";
					break;
				case "FSPLIT":
					e.FormProgId = "MMFSplit.MMFSplit_RTOpt_Input";
					break;
				case "STRVAR":
				case "FEEDBL":
					e.FormProgId = "MMStrvar.MMStrvar_RTOpt_Input";
					break;
				case "RADFRAC":
					e.FormProgId = "MMRadfrac.MMRadfrac_RTOpt";
					e.LegacyFlags = 4;
					break;
				}
				if (!string.IsNullOrEmpty(e.FormProgId))
				{
					e.HelpId = 186;
					e.HelpFile = "Common.hlp";
					e.ShowPrompts = true;
					e.ShortName = Resources.MMFsplit_Eoopti_Model_ViewModel_AddtionalVariables;
					DisplayForm(e);
				}
			}
		}

		private void cmdAddInput_CommandExecute(object parameter)
		{
			DisplayForm(new DisplayFormEventArgs
			{
				FormProgId = "MMMixer.MMMixer_AddInp",
				LegacyFlags = 0,
				HelpId = 193,
				HelpFile = "Common.hlp",
				ShowPrompts = true,
				ShortName = Resources.MMHeatx_Eoopti_Model_ViewModel_AddInput
			});
		}

		private void cmdEdit_CommandExecute(object parameter)
		{
			if (_selectedRowIndexes.Count != 1)
			{
				return;
			}
			int num = _selectedRowIndexes[0];
			if (num < 0)
			{
				return;
			}
			grdScMeth_GridData_ItemTemplate container = (grdScMeth_GridData as IList)[num] as grdScMeth_GridData_ItemTemplate;
			string strA = container.ResolveViewPropertyPath("MMComboBox2_var1.Value") as string;
			string text = container.ResolveViewPropertyPath("ID.Value") as string;
			string text2 = CxsConverter.ValueToString(ResolveParameter("main", null));
			int num2 = text2.LastIndexOf("Data");
			text2 = ((num2 <= 0) ? "Top.appModelV8" : text2.Substring(0, num2 + 4));
			text2 += ".EO Configuration.";
			if (string.Compare(strA, "LOCALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_LocScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_LocalScript
					};
					string text3 = text2 + "Local Scripts.";
					e.Parameters.Add("Input", text3 + text + ".Input");
					DisplayForm(e);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
			else if (string.Compare(strA, "GLOBALSCRIPT", StringComparison.OrdinalIgnoreCase) == 0)
			{
				if (!string.IsNullOrEmpty(text))
				{
					DisplayFormEventArgs e2 = new DisplayFormEventArgs
					{
						FormProgId = "MMScMethod.MMScMethod_Setup_GloScr",
						LegacyFlags = 0,
						HelpId = 166,
						HelpFile = "eoconf.hlp",
						ShowPrompts = true,
						ShortName = Resources.MMACMModel_Blocko_EOOptions_GlobalScript
					};
					string text4 = text2 + "Global Scripts.";
					e2.Parameters.Add("Input", text4 + text + ".Input");
					DisplayForm(e2);
				}
				else
				{
					ShowMessageBox(new ShowMessageBoxEventArgs
					{
						Message = Resources.MMACMModel_Blocko_EOOptions_SpecifyGlobalScriptID,
						Title = Resources.MMACMModel_Blocko_EOOptions_EditVariable
					});
				}
			}
		}

		private bool cmdEdit_CommandCanExecute(object parameter)
		{
			if (_selectedRowIndexes != null && _selectedRowIndexes.Count == 1)
			{
				int num = _selectedRowIndexes[0];
				IList list = grdScMeth_GridData as IList;
				if (num >= 0 && num < list.Count - 1)
				{
					return string.Compare((list[num] as grdScMeth_GridData_ItemTemplate).ResolveViewPropertyPath("MMComboBox2_var1.Value") as string, "File", StringComparison.InvariantCultureIgnoreCase) != 0;
				}
			}
			return false;
		}
	}
	[ProgId("MMFsplit.MMFsplit_Eoopti_Model")]
	public class MMFsplit_Eoopti_Model : MMTabPage, IComponentConnector
	{
		internal MMGroupBox MMFrame1_0;

		internal MMLabel MMComboBox1_label;

		internal MMComboEdit MMComboBox1;

		internal MMLabel MMComboBox6_label;

		internal MMComboEdit MMComboBox6;

		internal MMLabel MMLBUText10_label;

		internal MMVariableEdit MMLBUText10;

		internal MMLabel MMComboBox8_1_label;

		internal MMComboEdit MMComboBox8_1;

		internal MMCmdButton cmdAddOpt;

		internal MMCmdButton cmdAddVar;

		internal MMCmdButton cmdAddInput;

		internal MMGroupBox MMFrame2;

		internal MMScrollArea grdScMeth;

		internal MMCmdButton cmdEdit;

		private bool _contentLoaded;

		public MMFsplit_Eoopti_Model()
		{
			base.ViewModelType = typeof(MMFsplit_Eoopti_Model_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_eoopti_model.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				MMFrame1_0 = (MMGroupBox)target;
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
				MMComboBox8_1_label = (MMLabel)target;
				break;
			case 9:
				MMComboBox8_1 = (MMComboEdit)target;
				break;
			case 10:
				cmdAddOpt = (MMCmdButton)target;
				break;
			case 11:
				cmdAddVar = (MMCmdButton)target;
				break;
			case 12:
				cmdAddInput = (MMCmdButton)target;
				break;
			case 13:
				MMFrame2 = (MMGroupBox)target;
				break;
			case 14:
				grdScMeth = (MMScrollArea)target;
				break;
			case 15:
				cmdEdit = (MMCmdButton)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Input_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.MAIN"
		});

		public static readonly CxvPropertyDeclaration keycomp_Property = CxvPropertyDeclaration.Register("keycomp", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.DEFK"
		});

		public static readonly CxvPropertyDeclaration keylck1_Property = CxvPropertyDeclaration.Register("keylck1", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.KEY"
		});

		public static readonly CxvPropertyDeclaration entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTFLASH"
		});

		public static readonly CxvPropertyDeclaration entkey_Property = CxvPropertyDeclaration.Register("entkey", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.ENTKEY"
		});

		public static readonly CxvPropertyDeclaration key_Property = CxvPropertyDeclaration.Register("key", typeof(MMFsplit_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "key"
		});

		public static readonly CxvPropertyDeclaration stid_Property = CxvPropertyDeclaration.Register("stid", typeof(MMFsplit_Input_ViewModel), new CxvParameterProperty
		{
			Parameter = "stid"
		});

		public static readonly CxvPropertyDeclaration flasho_Property = CxvPropertyDeclaration.Register("flasho", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.CC Nodes.HEATWORK"
		});

		public static readonly CxvPropertyDeclaration tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@spec" }
		});

		public static readonly CxvPropertyDeclaration tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
		{
			AccessibleDataPaths = { "@flasho" },
			EnteredDataPaths = { "@entfls" }
		});

		public static readonly CxvPropertyDeclaration tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
		{
			CompleteDataPaths = { "@keycomp" },
			AccessibleDataPaths = { "@keylck1" },
			EnteredDataPaths = { "@entkey" }
		});

		public object spec => GetValue(spec_Property);

		public object keycomp => GetValue(keycomp_Property);

		public object keylck1 => GetValue(keylck1_Property);

		public object entfls => GetValue(entfls_Property);

		public object entkey => GetValue(entkey_Property);

		public object key => GetValue(key_Property);

		public object stid => GetValue(stid_Property);

		public object flasho => GetValue(flasho_Property);

		public object tab0_var => GetValue(tab0_var_Property);

		public object tab1_var => GetValue(tab1_var_Property);

		public object tab2_var => GetValue(tab2_var_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Input")]
	public class MMFsplit_Input : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip MMSSTab1;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tab2;

		internal MMTabItem tabInfo;

		private bool _contentLoaded;

		public MMFsplit_Input()
		{
			base.ViewModelType = typeof(MMFsplit_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabInfo = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Input_Flasho_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.PRES1"
		});

		public static readonly CxvPropertyDeclaration cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvMultiMapProperty
		{
			Variables = 
			{
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var1",
					DataPath = "@main.Input.NPHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var2",
					DataPath = "@main.Input.PHASE1"
				},
				new CxvMultiMapVariable
				{
					Name = "cboPhase_var3",
					DataPath = "@main.Input.BLKOPFREWAT"
				}
			},
			Options = 
			{
				new CxvMultiMapOption
				{
					Display = "Vapor-Only",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
					Value = "cboPhase_MultiMapOption_1",
					Prompt = "Only a vapor phase exists.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-Only",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
					Value = "cboPhase_MultiMapOption_2",
					Prompt = "Only a single liquid phase exists.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Solid-Only",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
					Value = "cboPhase_MultiMapOption_3",
					Prompt = "Only pure salts (electrolytes) or solids exist.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_e",
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
							Value = "S"
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
					Value = "cboPhase_MultiMapOption_4",
					Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-Liquid",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
					Value = "cboPhase_MultiMapOption_5",
					Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "NO"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-FreeWater",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_6",
					Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__a",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-FreeWater",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
					Value = "cboPhase_MultiMapOption_7",
					Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "YES"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Liquid-DirtyWater",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_8",
					Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				},
				new CxvMultiMapOption
				{
					Display = "Vapor-Liquid-DirtyWater",
					DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
					Value = "cboPhase_MultiMapOption_9",
					Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
					PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water_",
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
						},
						new CxvMultiMapValue
						{
							Variable = "cboPhase_var3",
							Value = "DIRTY"
						}
					}
				}
			}
		});

		public static readonly CxvPropertyDeclaration spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.MAXIT1"
		});

		public static readonly CxvPropertyDeclaration lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
		{
			DataPath = "@main.Input.TOL1"
		});

		public object lbtuPres_var1 => GetValue(lbtuPres_var1_Property);

		public object cboPhase_MultiMap => GetValue(cboPhase_MultiMap_Property);

		public object spnMaxit_var1 => GetValue(spnMaxit_var1_Property);

		public object lbtuTol_var1 => GetValue(lbtuTol_var1_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Input_Flasho")]
	public class MMFsplit_Input_Flasho : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmSpec;

		internal MMLabel lbtuPres_label;

		internal MMVariableEdit lbtuPres;

		internal MMLabel cboPhase_label;

		internal MMComboEdit cboPhase;

		internal MMGroupBox frmConv;

		internal MMLabel spnMaxit_label;

		internal MMSpinBox spnMaxit;

		internal MMLabel lbtuTol_label;

		internal MMVariableEdit lbtuTol;

		private bool _contentLoaded;

		public MMFsplit_Input_Flasho()
		{
			base.ViewModelType = typeof(MMFsplit_Input_Flasho_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_input_flasho.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				frmSpec = (MMGroupBox)target;
				break;
			case 2:
				lbtuPres_label = (MMLabel)target;
				break;
			case 3:
				lbtuPres = (MMVariableEdit)target;
				break;
			case 4:
				cboPhase_label = (MMLabel)target;
				break;
			case 5:
				cboPhase = (MMComboEdit)target;
				break;
			case 6:
				frmConv = (MMGroupBox)target;
				break;
			case 7:
				spnMaxit_label = (MMLabel)target;
				break;
			case 8:
				spnMaxit = (MMSpinBox)target;
				break;
			case 9:
				lbtuTol_label = (MMLabel)target;
				break;
			case 10:
				lbtuTol = (MMVariableEdit)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Input_Keycom_ViewModel : MMTabPageViewModel
	{
		public static readonly CxvPropertyDeclaration fraKeyComps_KEY_Property = CxvPropertyDeclaration.Register("fraKeyComps_KEY", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
		{
			Parameter = "KEY"
		});

		public static readonly CxvPropertyDeclaration fraKeyComps_STID_Property = CxvPropertyDeclaration.Register("fraKeyComps_STID", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
		{
			Parameter = "STID"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
		{
			Parameter = "STID"
		});

		public static readonly CxvPropertyDeclaration MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.COMPS.@KEY",
			SelectedItemBinding = "MMMenuButton2_var2.Value",
			CreateNewPrompt = "Substream:",
			CreateNewPromptResourceKey = "MMFsplit_Input_Keycom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
			CreateNewInputMask = 2,
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "KEY",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
		{
			Parameter = "KEY"
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_state_Property = CxvPropertyDeclaration.Register("MMListPicker1_state", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvGroupBoxProperty
		{
			IsEnabledCondition = new CxvLogicalTest
			{
				Parameter = "STID",
				Operator = CxvLogicalOperator.IdExists
			}
		});

		public static readonly CxvPropertyDeclaration MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "@main.Input.COMPS.@KEY.@STID",
			AllowSort = false
		});

		public static readonly CxvPropertyDeclaration MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvAdvCollectionProperty
		{
			DataPath = "@main.Input.COMPS",
			SelectedItemBinding = "MMMenuButton1_var2.Value",
			CreateNewInputMask = 0,
			CreateNewPrompt = "Key component number:",
			CreateNewPromptResourceKey = "MMFsplit_Input_Keycom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Key_component_number_",
			CompletePaths = { "DEFK1" }
		});

		public object fraKeyComps_KEY => GetValue(fraKeyComps_KEY_Property);

		public object fraKeyComps_STID => GetValue(fraKeyComps_STID_Property);

		public object MMMenuButton2_var2 => GetValue(MMMenuButton2_var2_Property);

		public object MMMenuButton2_var1 => GetValue(MMMenuButton2_var1_Property);

		public object MMMenuButton1_var2 => GetValue(MMMenuButton1_var2_Property);

		public object MMListPicker1_state => GetValue(MMListPicker1_state_Property);

		public object MMListPicker1_var1 => GetValue(MMListPicker1_var1_Property);

		public object MMMenuButton1_var1 => GetValue(MMMenuButton1_var1_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Input_Keycom")]
	public class MMFsplit_Input_Keycom : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraKeyComps;

		internal MMLabel MMMenuButton1_label;

		internal MMAdvancedComboEdit MMMenuButton1;

		internal MMLabel MMMenuButton2_label;

		internal MMComboEdit MMMenuButton2;

		internal MMListPicker MMListPicker1;

		private bool _contentLoaded;

		public MMFsplit_Input_Keycom()
		{
			base.ViewModelType = typeof(MMFsplit_Input_Keycom_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_input_keycom.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraKeyComps = (MMGroupBox)target;
				break;
			case 2:
				MMMenuButton1_label = (MMLabel)target;
				break;
			case 3:
				MMMenuButton1 = (MMAdvancedComboEdit)target;
				break;
			case 4:
				MMMenuButton2_label = (MMLabel)target;
				break;
			case 5:
				MMMenuButton2 = (MMComboEdit)target;
				break;
			case 6:
				MMListPicker1 = (MMListPicker)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Input_Specif_ViewModel : MMTabPageViewModel
	{
		public class grdSplit_GridData_ItemTemplate : MMViewModel
		{
			public static CxvPropertyDeclaration txtStream_var1_Property = CxvPropertyDeclaration.Register("txtStream_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Input.FRAC.@y"
			});

			public static CxvPropertyDeclaration splitSpec_Property = CxvPropertyDeclaration.Register("splitSpec", typeof(grdSplit_GridData_ItemTemplate), new CxvPropertySelector
			{
				Choices = 
				{
					new CxvPropertyChoice
					{
						DataPath = "@main.CC_Nodes.HEATWORK",
						Property = new CxvSpecProperty
						{
							Options = 
							{
								new CxvSpecOption
								{
									Display = "Split fraction",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_2",
									DataPath = "@main.Input.FRAC.@y"
								},
								new CxvSpecOption
								{
									Display = "Flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
									DataPath = "@main.Input.BASIS_FLOW.@y",
									BasisPath = "@main.Input.FLOW_BASIS.@y"
								},
								new CxvSpecOption
								{
									Display = "Actual volume flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Actual_volume_flow",
									DataPath = "@main.Input.VOL_FLOW.@y"
								},
								new CxvSpecOption
								{
									Display = "Limit flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Limit_flow",
									DataPath = "@main.Input.BASIS_LIMIT.@y",
									BasisPath = "@main.Input.LIMIT_BASIS.@y"
								},
								new CxvSpecOption
								{
									Display = "Volume limit flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Volume_limit_flow",
									DataPath = "@main.Input.VOL_LIMIT.@y"
								},
								new CxvSpecOption
								{
									Display = "Cum limit flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Cum_limit_flow",
									DataPath = "@main.Input.BASIS_C_LIM.@y",
									BasisPath = "@main.Input.C_LIM_BASIS.@y"
								},
								new CxvSpecOption
								{
									Display = "Cum volume limit flow",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Cum_volume_limit_flow",
									DataPath = "@main.Input.VOL_C_LIM.@y"
								},
								new CxvSpecOption
								{
									Display = "Residual fraction",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Residual_fraction",
									DataPath = "@main.Input.R_FRAC.@y"
								}
							}
						}
					},
					new CxvPropertyChoice
					{
						DataPath = "@main.CC_Nodes.HASWORK1",
						Property = new CxvSpecProperty
						{
							Options = 
							{
								new CxvSpecOption
								{
									Display = "Split fraction",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
									DataPath = "@main.Input.FRAC.@y"
								},
								new CxvSpecOption
								{
									Display = "Power",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Power",
									DataPath = "@main.Input.POWER.@y",
									BasisPath = "@main.Input.POWER.@y"
								}
							}
						}
					},
					new CxvPropertyChoice
					{
						DataPath = "@main.CC_Nodes.HASPOWER1",
						Property = new CxvSpecProperty
						{
							Options = 
							{
								new CxvSpecOption
								{
									Display = "Split fraction",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
									DataPath = "@main.Input.FRAC.@y"
								},
								new CxvSpecOption
								{
									Display = "Power",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Power",
									DataPath = "@main.Input.POWER.@y",
									BasisPath = "@main.Input.POWER.@y"
								}
							}
						}
					},
					new CxvPropertyChoice
					{
						DataPath = "@main.CC_Nodes.HASHEAT1",
						Property = new CxvSpecProperty
						{
							Options = 
							{
								new CxvSpecOption
								{
									Display = "Split fraction",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_1",
									DataPath = "@main.Input.FRAC.@y"
								},
								new CxvSpecOption
								{
									Display = "Heat Duty",
									DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Heat_duty",
									DataPath = "@main.Input.DUTY.@y",
									BasisPath = "@main.Input.FLOW_BASIS.@y"
								}
							}
						}
					}
				}
			});

			public static CxvPropertyDeclaration txtKey_Enable_Property = CxvPropertyDeclaration.Register("txtKey_Enable", typeof(grdSplit_GridData_ItemTemplate), new CxvLogicalProperty
			{
				Value = true,
				Tests = 
				{
					new CxvLogicalTest
					{
						DataPath = "@main.CC Nodes.HEATWORK2"
					}
				}
			});

			public static CxvPropertyDeclaration txtKey_var1_Property = CxvPropertyDeclaration.Register("txtKey_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.BASIS_KEYNO.@y"
			});

			public static CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Input.ORDER.@y"
			});

			public object txtStream_var1 => GetValue(txtStream_var1_Property);

			public object splitSpec => GetValue(splitSpec_Property);

			public object txtKey_Enable => GetValue(txtKey_Enable_Property);

			public object txtKey_var1 => GetValue(txtKey_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			protected override void OnSubPropertyDataChanged(CxvPropertyDeclaration pd, string subPropertyName)
			{
				base.OnSubPropertyDataChanged(pd, subPropertyName);
				if (pd.Name == "txtKey_var1" && subPropertyName == "Value" && !base.IsInitialUpdate && txtKey_var1 is CxvVariableData { Value: null })
				{
					(splitSpec as CxvSpecPropertyData).RefreshOptions();
				}
			}
		}

		public static readonly CxvPropertyDeclaration grdSplit_GridData_Property = CxvPropertyDeclaration.Register("grdSplit_GridData", typeof(MMFsplit_Input_Specif_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(grdSplit_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Input.FRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public object grdSplit_GridData => GetValue(grdSplit_GridData_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Input_Specif")]
	public class MMFsplit_Input_Specif : MMTabPage, IComponentConnector
	{
		internal MMGroupBox frmFlow;

		internal MMScrollArea grdSplit;

		private bool _contentLoaded;

		public MMFsplit_Input_Specif()
		{
			base.ViewModelType = typeof(MMFsplit_Input_Specif_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_input_specif.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				frmFlow = (MMGroupBox)target;
				break;
			case 2:
				grdSplit = (MMScrollArea)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Result_ViewModel : MMTabPageViewModel
	{
	}
	[ProgId("MMFsplit.MMFsplit_Result")]
	public class MMFsplit_Result : MMTabTemplate, IComponentConnector
	{
		internal MMTabStrip tabInput;

		internal MMTabItem tab0;

		internal MMTabItem tab1;

		internal MMTabItem tabStatus;

		private bool _contentLoaded;

		public MMFsplit_Result()
		{
			base.ViewModelType = typeof(MMFsplit_Result_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_result.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
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
				tabStatus = (MMTabItem)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class MMFsplit_Result_Summar_ViewModel : MMTabPageViewModel
	{
		public class MMScrollArea1_GridData_ItemTemplate : MMViewModel
		{
			public static readonly CxvPropertyDeclaration MMTextBox2_1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.STREAM_ORDER.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				ExposeAs = CxvVariableTypeCode.Id,
				DataPath = "@main.Output.STREAMFRAC.@y"
			});

			public static readonly CxvPropertyDeclaration MMTextBox2_0_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_0_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
			{
				DataPath = "@main.Output.STREAMFRAC.@y"
			});

			public object MMTextBox2_1_var1 => GetValue(MMTextBox2_1_var1_Property);

			public object MMTextBox1_var1 => GetValue(MMTextBox1_var1_Property);

			public object MMTextBox2_0_var1 => GetValue(MMTextBox2_0_var1_Property);
		}

		public static readonly CxvPropertyDeclaration MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMFsplit_Result_Summar_ViewModel), new CxvVectorProperty
		{
			ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
			IndexBasis = new CxvChildCountIndexBasis
			{
				DataPath = "@main.Output.STREAMFRAC",
				UseChildId = true,
				Name = "y"
			}
		});

		public object MMScrollArea1_GridData => GetValue(MMScrollArea1_GridData_Property);
	}
	[ProgId("MMFsplit.MMFsplit_Result_Summar")]
	public class MMFsplit_Result_Summar : MMTabPage, IComponentConnector
	{
		internal MMScrollArea MMScrollArea1;

		private bool _contentLoaded;

		public MMFsplit_Result_Summar()
		{
			base.ViewModelType = typeof(MMFsplit_Result_Summar_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_result_summar.xaml", UriKind.Relative);
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
	public class MMFsplit_RTOpt_Input_ViewModel : MMTabPageViewModel
	{
		private ICommand _cmdClose_Command;

		public static readonly CxvPropertyDeclaration MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_RESI_FRA",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = false
		});

		public static readonly CxvPropertyDeclaration MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_SPLT_FRA",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_PRES",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_DPI",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_STDV_FLO",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox5_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox5_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_MASS_FLO",
			TrueValue = "YES",
			FalseValue = "NO",
			DefaultValue = true
		});

		public static readonly CxvPropertyDeclaration MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
		{
			DataPath = "@main.Input.SPC_MOLE_FLO",
			TrueValue = "YES",
			FalseValue = "NO",
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

		public object MMCheckBox7_var1 => GetValue(MMCheckBox7_var1_Property);

		public object MMCheckBox4_var1 => GetValue(MMCheckBox4_var1_Property);

		public object MMCheckBox3_var1 => GetValue(MMCheckBox3_var1_Property);

		public object MMCheckBox2_var1 => GetValue(MMCheckBox2_var1_Property);

		public object MMCheckBox6_var1 => GetValue(MMCheckBox6_var1_Property);

		public object MMCheckBox5_var1 => GetValue(MMCheckBox5_var1_Property);

		public object MMCheckBox1_var1 => GetValue(MMCheckBox1_var1_Property);

		private void cmdClose_CommandExecute(object parameter)
		{
			CloseForm();
		}
	}
	[ProgId("MMFsplit.MMFsplit_RTOpt_Input")]
	public class MMFsplit_RTOpt_Input : MMTabPage, IComponentConnector
	{
		internal MMGroupBox fraState;

		internal MMCheckBox MMCheckBox3;

		internal MMCheckBox MMCheckBox2;

		internal MMGroupBox MMFrame1;

		internal MMCheckBox MMCheckBox1;

		internal MMCheckBox MMCheckBox5;

		internal MMCheckBox MMCheckBox6;

		internal MMGroupBox fraOpen;

		internal MMCheckBox MMCheckBox4;

		internal MMCheckBox MMCheckBox7;

		internal MMCmdButton cmdClose;

		private bool _contentLoaded;

		public MMFsplit_RTOpt_Input()
		{
			base.ViewModelType = typeof(MMFsplit_RTOpt_Input_ViewModel);
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split;component/fsplit/mmfsplit_rtopt_input.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				fraState = (MMGroupBox)target;
				break;
			case 2:
				MMCheckBox3 = (MMCheckBox)target;
				break;
			case 3:
				MMCheckBox2 = (MMCheckBox)target;
				break;
			case 4:
				MMFrame1 = (MMGroupBox)target;
				break;
			case 5:
				MMCheckBox1 = (MMCheckBox)target;
				break;
			case 6:
				MMCheckBox5 = (MMCheckBox)target;
				break;
			case 7:
				MMCheckBox6 = (MMCheckBox)target;
				break;
			case 8:
				fraOpen = (MMGroupBox)target;
				break;
			case 9:
				MMCheckBox4 = (MMCheckBox)target;
				break;
			case 10:
				MMCheckBox7 = (MMCheckBox)target;
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

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000006 XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x06000010 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_ViewModel..ctor
// public MMSsplit_Input_ViewModel()
// {
// }

// 0x06000011 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSsplit_Input_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SPEC"
// 	});
// 	defkey_Property = CxvPropertyDeclaration.Register("defkey", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DEFK"
// 	});
// 	keyloc_Property = CxvPropertyDeclaration.Register("keyloc", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.KEYLOC"
// 	});
// 	entflsh_Property = CxvPropertyDeclaration.Register("entflsh", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFLSH"
// 	});
// 	entkey_Property = CxvPropertyDeclaration.Register("entkey", typeof(MMSsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTKEY"
// 	});
// 	STRMID_Property = CxvPropertyDeclaration.Register("STRMID", typeof(MMSsplit_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "STRMID"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entflsh" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@defkey" },
// 		AccessibleDataPaths = { "@keyloc" },
// 		EnteredDataPaths = { "@entkey" }
// 	});
// }

// 0x06000019 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_FlashO_ViewModel..ctor
// public MMSsplit_Input_FlashO_ViewModel()
// {
// }

// 0x0600001a AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_FlashO_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSsplit_Input_FlashO_ViewModel()
// {
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Input.NPHASE"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Input.PHASE"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var3",
// 				DataPath = "@main.Input.BLKOPFREWAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_e",
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
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations. ",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations. ",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__a",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSsplit_Input_FlashO_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES"
// 	});
// 	lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL"
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSsplit_Input_FlashO_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT"
// 	});
// }

// 0x06000023 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_KeyCom_ViewModel..ctor
// public MMSsplit_Input_KeyCom_ViewModel()
// {
// }

// 0x06000024 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_KeyCom_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSsplit_Input_KeyCom_ViewModel()
// {
// 	fraKeyComps_KEY_Property = CxvPropertyDeclaration.Register("fraKeyComps_KEY", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "KEY"
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "KEY"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.COMPS",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Key component number:",
// 		CreateNewPromptResourceKey = "MMSsplit_Input_KeyCom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Key_component_number_",
// 		CompletePaths = { "DEFK1" }
// 	});
// 	lstpComps_state_Property = CxvPropertyDeclaration.Register("lstpComps_state", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "KEY",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	lstpComps_var1_Property = CxvPropertyDeclaration.Register("lstpComps_var1", typeof(MMSsplit_Input_KeyCom_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.COMPS.@KEY"
// 	});
// }

// 0x0600002b AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_Specif_ViewModel..ctor
// public MMSsplit_Input_Specif_ViewModel()
// {
// }

// 0x0600002c AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSsplit_Input_Specif_ViewModel()
// {
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSsplit_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "STRMID"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSsplit_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FRAC",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Stream names:",
// 		CreateNewPromptResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_names_"
// 	});
// 	grdSplit_GridData_Property = CxvPropertyDeclaration.Register("grdSplit_GridData", typeof(MMSsplit_Input_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSplit_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FRAC.@STRMID",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000030 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_ViewModel..ctor
// public MMSsplit_Result_ViewModel()
// {
// }

// 0x06000035 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel..ctor
// public MMSsplit_Result_Summar_ViewModel()
// {
// }

// 0x06000036 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSsplit_Result_Summar_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMSsplit_Result_Summar_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.STREAMFRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000050 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Blocko_ViewModel..ctor
// public MMSep_Blocko_ViewModel()
// {
// }

// 0x06000051 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Blocko_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Blocko_ViewModel()
// {
// 	blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.BKOP"
// 	});
// 	entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKPR"
// 	});
// 	entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKSI"
// 	});
// 	entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKDG"
// 	});
// 	entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKRP"
// 	});
// 	genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GENBLKOP"
// 	});
// 	entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTIPT"
// 	});
// 	entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTADD"
// 	});
// 	entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTEOMOD"
// 	});
// 	entopopt_Property = CxvPropertyDeclaration.Register("entopopt", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTOPOPT"
// 	});
// 	eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EODEF"
// 	});
// 	eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT"
// 	});
// 	varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMSep_Blocko_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "varno"
// 	});
// 	sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMENT"
// 	});
// 	smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMSPEC"
// 	});
// 	l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMSep_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.L2CP2"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@blkops", "@genblk" },
// 		EnteredDataPaths = { "@entpro" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entsim" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entdia" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@l2cp2", "@smspec" },
// 		EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@entopopt", "@sment" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@eodef" },
// 		EnteredDataPaths = { "@eoent" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMSep_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entrep" }
// 	});
// }

// 0x06000068 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_Model_ViewModel..ctor
// public MMSep_Eoopti_Model_ViewModel()
// {
// }

// 0x06000069 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_Model_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMSep_Eoopti_Model_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMSep_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
// 	{
// 		DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
// 	});
// 	MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMSep_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_COMPS_T"
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_COMPS"
// 	});
// 	cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMSep_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.RTOPT"
// 		}
// 	});
// 	grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMSep_Eoopti_Model_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdScMeth_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.SC_METHOD",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000072 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_OutStr_ViewModel..ctor
// public MMSep_Eoopti_OutStr_ViewModel()
// {
// }

// 0x06000073 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_OutStr_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Eoopti_OutStr_ViewModel()
// {
// 	scaStreamCGI_GridData_Property = CxvPropertyDeclaration.Register("scaStreamCGI_GridData", typeof(MMSep_Eoopti_OutStr_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(scaStreamCGI_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.STR_COMPS",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000082 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_ViewModel..ctor
// public MMSep_Input_ViewModel()
// {
// }

// 0x06000083 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Input_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAINS"
// 	});
// 	outfl_Property = CxvPropertyDeclaration.Register("outfl", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FLMAIN"
// 	});
// 	entfd_Property = CxvPropertyDeclaration.Register("entfd", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFEED"
// 	});
// 	entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFLASH"
// 	});
// 	choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMSep_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	entutl_Property = CxvPropertyDeclaration.Register("entutl", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTUTL"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entfd" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@outfl" },
// 		EnteredDataPaths = { "@entfls" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@utlred" },
// 		EnteredDataPaths = { "@entutl" }
// 	});
// 	utlred_Property = CxvPropertyDeclaration.Register("utlred", typeof(MMSep_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UTLRED"
// 	});
// }

// 0x0600008b AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Feedfl_ViewModel..ctor
// public MMSep_Input_Feedfl_ViewModel()
// {
// }

// 0x0600008c AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Feedfl_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Input_Feedfl_ViewModel()
// {
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSep_Input_Feedfl_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Input.NPHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Input.PHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var3",
// 				DataPath = "@main.Input.BLKOPFREWAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exis",
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
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_in",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_co",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__are",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__are",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__ar",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES1"
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL1"
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSep_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT1"
// 	});
// }

// 0x0600009f AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Outlet_ViewModel..ctor
// public MMSep_Input_Outlet_ViewModel()
// {
// }

// 0x060000a0 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Outlet_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMSep_Input_Outlet_ViewModel()
// {
// 	MMFrame3_state_Property = CxvPropertyDeclaration.Register("MMFrame3_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.KOD.@choice"
// 		}
// 	});
// 	lbtuTol_display_Property = CxvPropertyDeclaration.Register("lbtuTol_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL.@choice"
// 	});
// 	spnMaxit_display_Property = CxvPropertyDeclaration.Register("spnMaxit_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT.@choice"
// 	});
// 	MMFrame2_state_Property = CxvPropertyDeclaration.Register("MMFrame2_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.KOD.@choice"
// 		}
// 	});
// 	lbtuTest_var1_Property = CxvPropertyDeclaration.Register("lbtuTest_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.T_EST.@choice",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.TEST.@choice"
// 		}
// 	});
// 	lbtuPest_var1_Property = CxvPropertyDeclaration.Register("lbtuPest_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.P_EST.@choice",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.PEST.@choice"
// 		}
// 	});
// 	mnbStreamName_target_Property = CxvPropertyDeclaration.Register("mnbStreamName_target", typeof(MMSep_Input_Outlet_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	mnbStreamName_display_Property = CxvPropertyDeclaration.Register("mnbStreamName_display", typeof(MMSep_Input_Outlet_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.NPHASE",
// 		SelectedItemBinding = "mnbStreamName_target.Value",
// 		CreateNewPrompt = "Stream:",
// 		CreateNewPromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Stream_",
// 		CompletePaths = { "FLSP" }
// 	});
// 	fraFlashSpec_state_Property = CxvPropertyDeclaration.Register("fraFlashSpec_state", typeof(MMSep_Input_Outlet_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.KOD.@choice"
// 		}
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMSep_Input_Outlet_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_nphase",
// 				DataPath = "@main.Input.NPHASE.@choice"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_phase",
// 				DataPath = "@main.Input.PHASE.@choice"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_freewater",
// 				DataPath = "@main.Input.FREE_WATER.@choice"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase",
// 						Value = "V"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exis",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase",
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_in",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "MMComboBox1_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_co",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "3"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "MMComboBox1_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are_",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "MMComboBox1_MultiMapOption_7",
// 				Prompt = "3 liquid phases (vapor, organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_liquid_phases__vapor__organic_and_pure_wate",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "MMComboBox1_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__are",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "1"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase",
// 						Value = "L"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "MMComboBox1_MultiMapOption_9",
// 				Prompt = "3 liquid phases (vapor, organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep_Input_Outlet_ViewModel__CxvMultiMapOption_Prompt_3_liquid_phases__vapor__organic_and_dirty_wat",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_nphase",
// 						Value = "2"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_phase"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_freewater",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DELT.@choice"
// 	});
// 	lbtuTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuTemp_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TEMP.@choice"
// 	});
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES.@choice"
// 	});
// 	lbtuVfrac_var1_Property = CxvPropertyDeclaration.Register("lbtuVfrac_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRAC.@choice"
// 	});
// 	chkFlashStream_var1_Property = CxvPropertyDeclaration.Register("chkFlashStream_var1", typeof(MMSep_Input_Outlet_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.KODE.@choice",
// 		FalseValue = "NOFLASH",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "choice",
// 			Operator = CxvLogicalOperator.IdExists
// 		},
// 		DisabledPrompt = Resources.MMSep_Input_Outlet_ViewModel_chkFlashStream_var1_DisabledPrompt
// 	});
// }

// 0x060000ab AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Specif_ViewModel..ctor
// public MMSep_Input_Specif_ViewModel()
// {
// }

// 0x060000ac AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Input_Specif_ViewModel()
// {
// 	fraSpec_Stream_Property = CxvPropertyDeclaration.Register("fraSpec_Stream", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Stream"
// 	});
// 	fraSpec_Substr_Property = CxvPropertyDeclaration.Register("fraSpec_Substr", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr"
// 	});
// 	MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr"
// 	});
// 	MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMSep_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FRACS.@Stream",
// 		SelectedItemBinding = "MMMenuButton2_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMSep_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Stream"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FRACS",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Outlet stream:",
// 		CreateNewPromptResourceKey = "MMSep_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Outlet_stream_"
// 	});
// 	grdSpecs_GridData_Property = CxvPropertyDeclaration.Register("grdSpecs_GridData", typeof(MMSep_Input_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpecs_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FRACS.@Stream.@Substr",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060000b2 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_ViewModel..ctor
// public MMSep_Result_ViewModel()
// {
// }

// 0x060000b3 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Result_ViewModel()
// {
// 	utlusage_Property = CxvPropertyDeclaration.Register("utlusage", typeof(MMSep_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.UTL_USAGE"
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@utlusage" }
// 	});
// }

// 0x060000bc AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel..ctor
// public MMSep_Result_Summar_ViewModel()
// {
// }

// 0x060000bd AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep_Result_Summar_ViewModel()
// {
// 	fraFracRes_Substr2_Property = CxvPropertyDeclaration.Register("fraFracRes_Substr2", typeof(MMSep_Result_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr2"
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep_Result_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr2"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep_Result_Summar_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMSep_Result_Summar_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
// 	});
// 	grdSpltFrac_GridData_Property = CxvPropertyDeclaration.Register("grdSpltFrac_GridData", typeof(MMSep_Result_Summar_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpltFrac_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPFRAC.@Substr2",
// 			UseChildId = true,
// 			Name = "yy"
// 		}
// 	});
// 	lbtuDuty_var1_Property = CxvPropertyDeclaration.Register("lbtuDuty_var1", typeof(MMSep_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.QCALC"
// 	});
// }

// 0x060000cc AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_ViewModel..ctor
// public MMSep2_Input_ViewModel()
// {
// }

// 0x060000cd AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep2_Input_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAINS"
// 	});
// 	flash_Property = CxvPropertyDeclaration.Register("flash", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FLMAIN"
// 	});
// 	entfd_Property = CxvPropertyDeclaration.Register("entfd", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFEED"
// 	});
// 	entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFLASH"
// 	});
// 	choice_Property = CxvPropertyDeclaration.Register("choice", typeof(MMSep2_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	entutl_Property = CxvPropertyDeclaration.Register("entutl", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTUTL"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entfd" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@flash" },
// 		EnteredDataPaths = { "@entfls" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMSep2_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@utlred" },
// 		EnteredDataPaths = { "@entutl" }
// 	});
// 	utlred_Property = CxvPropertyDeclaration.Register("utlred", typeof(MMSep2_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UTLRED"
// 	});
// }

// 0x060000d5 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Feedfl_ViewModel..ctor
// public MMSep2_Input_Feedfl_ViewModel()
// {
// }

// 0x060000d6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Feedfl_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep2_Input_Feedfl_ViewModel()
// {
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT1"
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL1"
// 	});
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES1"
// 	});
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMSep2_Input_Feedfl_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Input.NPHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Input.PHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var3",
// 				DataPath = "@main.Input.BLKOPFREWAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_exi",
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
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_i",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_c",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__are",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__ar",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__ar",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMSep2_Input_Feedfl_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__a",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x060000e6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Specif_ViewModel..ctor
// public MMSep2_Input_Specif_ViewModel()
// {
// }

// 0x060000e7 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep2_Input_Specif_ViewModel()
// {
// 	fraInput_Substr_Property = CxvPropertyDeclaration.Register("fraInput_Substr", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr"
// 	});
// 	fraInput_Stream_Property = CxvPropertyDeclaration.Register("fraInput_Stream", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Stream"
// 	});
// 	MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Stream"
// 	});
// 	MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FRACS.@Substr",
// 		SelectedItemBinding = "MMMenuButton2_var2.Value",
// 		CreateNewPrompt = "Outlet stream:",
// 		CreateNewPromptResourceKey = "MMSep2_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Outlet_stream_"
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FRACS",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMSep2_Input_Specif_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
// 	});
// 	spcStream_Property = CxvPropertyDeclaration.Register("spcStream", typeof(MMSep2_Input_Specif_ViewModel), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Split fraction",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
// 				DataPath = "@main.Input.FRAC.@Substr.@Stream"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Flow",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
// 				DataPath = "@main.Input.FLOW.@Substr.@Stream",
// 				BasisPath = "@main.Input.FLOW_BASIS.@Substr.@Stream"
// 			}
// 		}
// 	});
// 	spcStream_var1_Property = CxvPropertyDeclaration.Register("spcStream_var1", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FRAC.@Substr.@Stream"
// 	});
// 	spcStream_var2_Property = CxvPropertyDeclaration.Register("spcStream_var2", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW.@Substr.@Stream"
// 	});
// 	spcStream_var3_Property = CxvPropertyDeclaration.Register("spcStream_var3", typeof(MMSep2_Input_Specif_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW_BASIS.@Substr.@Stream"
// 	});
// 	grdSpecs_GridData_Property = CxvPropertyDeclaration.Register("grdSpecs_GridData", typeof(MMSep2_Input_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpecs_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FRACS.@Substr.@Stream",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060000ed AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_ViewModel..ctor
// public MMSep2_Result_ViewModel()
// {
// }

// 0x060000ee AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep2_Result_ViewModel()
// {
// 	utlusage_Property = CxvPropertyDeclaration.Register("utlusage", typeof(MMSep2_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.UTL_USAGE"
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMSep2_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@utlusage" }
// 	});
// }

// 0x060000f7 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel..ctor
// public MMSep2_Result_Summar_ViewModel()
// {
// }

// 0x060000f8 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMSep2_Result_Summar_ViewModel()
// {
// 	lbtuDuty_var1_Property = CxvPropertyDeclaration.Register("lbtuDuty_var1", typeof(MMSep2_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.QCALC"
// 	});
// 	fraFracRes_Substr2_Property = CxvPropertyDeclaration.Register("fraFracRes_Substr2", typeof(MMSep2_Result_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr2"
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMSep2_Result_Summar_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "Substr2"
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMSep2_Result_Summar_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMSep2_Result_Summar_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_"
// 	});
// 	grdSpltFrac_GridData_Property = CxvPropertyDeclaration.Register("grdSpltFrac_GridData", typeof(MMSep2_Result_Summar_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpltFrac_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPFRAC.@Substr2",
// 			UseChildId = true,
// 			Name = "yy"
// 		}
// 	});
// }

// 0x060000ff AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_AddInp_ViewModel..ctor
// public MMMixer_AddInp_ViewModel()
// {
// }

// 0x06000100 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_AddInp_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_AddInp_ViewModel()
// {
// 	MMDescription1_var1_Property = CxvPropertyDeclaration.Register("MMDescription1_var1", typeof(MMMixer_AddInp_ViewModel), new CxvDescriptionProperty
// 	{
// 		DataPath = "@main.Input.ADDINPUT"
// 	});
// }

// 0x06000137 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_AddOpt_ViewModel..ctor
// public MMMixer_AddOpt_ViewModel()
// {
// }

// 0x06000138 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_AddOpt_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMixer_AddOpt_ViewModel()
// {
// 	lbtuTempTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTempTol_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.EO_TEMP_TOL"
// 	});
// 	lbtuFlowTol1_var1_Property = CxvPropertyDeclaration.Register("lbtuFlowTol1_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW_TOL"
// 	});
// 	lbtuFlowTol2_var1_Property = CxvPropertyDeclaration.Register("lbtuFlowTol2_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FLOW_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VFRAC"
// 		}
// 	});
// 	MMLBUText3_var1_Property = CxvPropertyDeclaration.Register("MMLBUText3_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRAC_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VFRAC"
// 		}
// 	});
// 	MMLBUText4_var1_Property = CxvPropertyDeclaration.Register("MMLBUText4_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.VFRACX_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.VFRAC"
// 		}
// 	});
// 	MMComboBox15_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox15_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox15_var1",
// 				DataPath = "@main.Input.MIN_PRES"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Block pressure",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox15_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_yes_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox15_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Minimum pressure",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox15_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_no_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox15_var1",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "First pressure",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_First",
// 				Value = "MMComboBox15_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_mo_min_pres_first_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox15_var1",
// 						Value = "FIRST"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMLBUText6_var1_Property = CxvPropertyDeclaration.Register("MMLBUText6_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES_TOL"
// 	});
// 	MMLBUText8_var1_Property = CxvPropertyDeclaration.Register("MMLBUText8_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.EO_COMP_TOL"
// 	});
// 	MMLBUText7_var1_Property = CxvPropertyDeclaration.Register("MMLBUText7_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.SFRAC_TOL",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SFRC"
// 		}
// 	});
// 	MMLBUText9_var1_Property = CxvPropertyDeclaration.Register("MMLBUText9_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DUTY_TOL"
// 	});
// 	cboEOFormu3_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu3_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboEOFormu3_var1",
// 				DataPath = "@main.Input.EO_FORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard",
// 				Value = "cboEOFormu3_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu3_var1",
// 						Value = "STANDARD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO-PML",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML",
// 				Value = "cboEOFormu3_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu3_var1",
// 						Value = "EOPML"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboSoluMeth2_MultiMap_Property = CxvPropertyDeclaration.Register("cboSoluMeth2_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboSoluMeth2_var1",
// 				DataPath = "@main.Input.SOLVE_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Closed; use Perturbation layer around closed model",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_mod",
// 				Value = "cboSoluMeth2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth2_var1",
// 						Value = "PERTURBATION"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Ignore; ignore block during EO solution",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Ignore__ignore_block_during_EO_solution",
// 				Value = "cboSoluMeth2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth2_var1",
// 						Value = "DO-NOT-CREAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboEOFormu2_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu2_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboEOFormu2_var1",
// 				DataPath = "@main.Input.EO_FORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard_1",
// 				Value = "cboEOFormu2_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.eo_options_eo_form_standard_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu2_var1",
// 						Value = "STANDARD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO-PML",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML_1",
// 				Value = "cboEOFormu2_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_eo_form_eopml_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu2_var1",
// 						Value = "EOPML"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RT-Opt 10.0",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0",
// 				Value = "cboEOFormu2_MultiMapOption_3",
// 				Prompt = ApwnComboPromptResource.eo_options_eo_form_molefrac_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu2_var1",
// 						Value = "MOLEFRAC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RT-Opt 3.0",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_3_0",
// 				Value = "cboEOFormu2_MultiMapOption_4",
// 				Prompt = ApwnComboPromptResource.eo_options_eo_form_moleflow_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu2_var1",
// 						Value = "MOLEFLOW"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox7_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox7_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox7_var1",
// 				DataPath = "@main.Input.ON_SMEO_DIFF"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Use-closed",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Use_closed",
// 				Value = "MMComboBox7_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox7_var1",
// 						Value = "USE-CLOSED"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Use-open",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Use_open",
// 				Value = "MMComboBox7_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox7_var1",
// 						Value = "USE-OPEN"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	ChemMethod_MultiMap_Property = CxvPropertyDeclaration.Register("ChemMethod_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "ChemMethodComboBox_var1",
// 				DataPath = "@main.Input.CHEM_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Product",
// 				DisplayResourceKey = ApwnResources.MMEOOption_AddOpt_ChemMethod_Product,
// 				Value = "ChemMethodComboBox_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ChemMethodComboBox_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Logarithmic",
// 				DisplayResourceKey = ApwnResources.MMEOOption_AddOpt_ChemMethod_Logarithmic,
// 				Value = "ChemMethodComboBox_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "ChemMethodComboBox_var1",
// 						Value = "YES-LOG"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox11_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox11_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_1",
// 				Value = "MMComboBox11_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.eo_options_always_inst_yes_prompt,
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_1",
// 				Value = "MMComboBox11_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_always_inst_no_prompt,
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
// 	MMLBUText1_var1_Property = CxvPropertyDeclaration.Register("MMLBUText1_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NEG_COMP_CHK"
// 	});
// 	MMLBUText2_var1_Property = CxvPropertyDeclaration.Register("MMLBUText2_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.NEG_FLOW_CHK"
// 	});
// 	cboEOFormu1_MultiMap_Property = CxvPropertyDeclaration.Register("cboEOFormu1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboEOFormu1_var1",
// 				DataPath = "@main.Input.EO_FORM"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Standard",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Standard_2",
// 				Value = "cboEOFormu1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu1_var1",
// 						Value = "STANDARD"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO-PML",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_EO_PML_2",
// 				Value = "cboEOFormu1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu1_var1",
// 						Value = "EOPML"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "RT-Opt 10.0",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_RT_Opt_10_0_1",
// 				Value = "cboEOFormu1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboEOFormu1_var1",
// 						Value = "MOLEFRAC"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Analytical",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.design_spec_deriv_method_analytical_prompt,
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Numerical",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.design_spec_deriv_method_numerical_prompt,
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Analytical_",
// 				Value = "MMComboBox1_MultiMapOption_3",
// 				Prompt = ApwnComboPromptResource.design_spec_deriv_method_update_analy_prompt,
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Update__Numerical_",
// 				Value = "MMComboBox1_MultiMapOption_4",
// 				Prompt = ApwnComboPromptResource.design_spec_deriv_method_update_numer_prompt,
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
// 	cboSoluMeth1_MultiMap_Property = CxvPropertyDeclaration.Register("cboSoluMeth1_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboSoluMeth1_var1",
// 				DataPath = "@main.Input.SOLVE_METHOD"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with information messages",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_informati",
// 				Value = "cboSoluMeth1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth1_var1",
// 						Value = "OPEN-PERT-IN"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure use Perturbation with warning messages",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_use_Perturbation_with_warning_m",
// 				Value = "cboSoluMeth1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth1_var1",
// 						Value = "OPEN-PERT-WA"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Open; on failure stop with error messages",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Open__on_failure_stop_with_error_messages",
// 				Value = "cboSoluMeth1_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth1_var1",
// 						Value = "OPEN-NOPERT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Closed; use Perturbation layer around closed model",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Closed__use_Perturbation_layer_around_closed_mod_1",
// 				Value = "cboSoluMeth1_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth1_var1",
// 						Value = "PERTURBATION"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Neither; ignore block during EO solution",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Neither__ignore_block_during_EO_solution",
// 				Value = "cboSoluMeth1_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboSoluMeth1_var1",
// 						Value = "DO-NOT-CREAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox17_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox17_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_2",
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_2",
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
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_PHASE_T"
// 	});
// 	MMComboBox9_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox9_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox9_var1",
// 				DataPath = "@main.Input.INLET_PHASE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "MMComboBox9_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.eo_options_inlet_phase_v_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "V"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "MMComboBox9_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_inlet_phase_l_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "L"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Mixed",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Mixed",
// 				Value = "MMComboBox9_MultiMapOption_3",
// 				Prompt = ApwnComboPromptResource.eo_options_inlet_phase_mixed_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox9_var1",
// 						Value = "MIXED"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox10_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox10_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_PML",
// 				Value = "MMComboBox10_MultiMapOption_1",
// 				Prompt = ApwnComboPromptResource.eo_options_flash_form_pml_prompt,
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Smoothing",
// 				Value = "MMComboBox10_MultiMapOption_2",
// 				Prompt = ApwnComboPromptResource.eo_options_flash_form_smoothing_prompt,
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
// 	MMComboBox12_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox12_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Auto",
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_None",
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_CompID",
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
// 	MMComboBox13_var1_Property = CxvPropertyDeclaration.Register("MMComboBox13_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_L2_COMP",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.L2CP1"
// 		}
// 	});
// 	MMComboBox8_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Yes_3",
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
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_No_3",
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
// 	MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_HEAVY_KEY"
// 	});
// 	MMComboBox5_var1_Property = CxvPropertyDeclaration.Register("MMComboBox5_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_LIGHT_KEY"
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMMixer_AddOpt_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_DEP_COMPS"
// 	});
// 	MMComboBox14_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox14_MultiMap", typeof(MMMixer_AddOpt_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox14_var1",
// 				DataPath = "@main.Input.SPARSITY"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature & pressure",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature___pressure",
// 				Value = "MMComboBox14_MultiMapOption_1",
// 				Prompt = PromptResources.FILEPNUM_34_Prompt_100,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox14_var1",
// 						Value = "COMP-INDEP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature, pressure & composition",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition",
// 				Value = "MMComboBox14_MultiMapOption_2",
// 				Prompt = PromptResources.FILEPNUM_34_Prompt_101,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox14_var1",
// 						Value = "FULL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Temperature, pressure & composition for water",
// 				DisplayResourceKey = "MMMixer_AddOpt_ViewModel__CxvMultiMapOption_Display_Temperature__pressure___composition_for_water",
// 				Value = "MMComboBox14_MultiMapOption_3",
// 				Prompt = PromptResources.FILEPNUM_34_Prompt_102,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox14_var1",
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

// 0x06000151 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_ViewModel..ctor
// public MMMixer_Blocko_ViewModel()
// {
// }

// 0x06000152 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Blocko_ViewModel()
// {
// 	blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.BKOP"
// 	});
// 	entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKPR"
// 	});
// 	entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKSI"
// 	});
// 	entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKDG"
// 	});
// 	entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKRP"
// 	});
// 	genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GENBLKOP"
// 	});
// 	entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTIPT"
// 	});
// 	entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTADD"
// 	});
// 	entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTEOMOD"
// 	});
// 	smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMSPEC"
// 	});
// 	sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMENT"
// 	});
// 	varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMMixer_Blocko_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "varno"
// 	});
// 	eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EODEF"
// 	});
// 	eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT"
// 	});
// 	l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMMixer_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.L2CP2"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@blkops", "@genblk" },
// 		EnteredDataPaths = { "@entpro" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entsim" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entdia" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@l2cp2", "@smspec" },
// 		EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@sment" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@eodef" },
// 		EnteredDataPaths = { "@eoent" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMMixer_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entrep" }
// 	});
// }

// 0x06000156 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_Diagno_ViewModel..ctor
// public MMMixer_Blocko_Diagno_ViewModel()
// {
// }

// 0x0600015a AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_Proper_ViewModel..ctor
// public MMMixer_Blocko_Proper_ViewModel()
// {
// }

// 0x0600015f AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_Report_ViewModel..ctor
// public MMMixer_Blocko_Report_ViewModel()
// {
// }

// 0x06000163 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_Simula_ViewModel..ctor
// public MMMixer_Blocko_Simula_ViewModel()
// {
// }

// 0x06000178 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel..ctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// public MMMixer_Blocko_VarVec_ViewModel()
// {
// 	_watcher = new CxvPropertyWatch();
// 	base..ctor();
// }

// 0x06000179 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Blocko_VarVec_ViewModel()
// {
// 	fraDefine_choice_Property = CxvPropertyDeclaration.Register("fraDefine_choice", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "choice"
// 	});
// 	NumCol_Property = CxvPropertyDeclaration.Register("NumCol", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FVN_VARTYPE.0"
// 	});
// 	grdDefine_GridData_Property = CxvPropertyDeclaration.Register("grdDefine_GridData", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdDefine_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FVN_VARTYPE",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// 	cmdEditDeleteCanExecuteProperty = CxvPropertyDeclaration.Register("cmdEditDeleteCanExecute", typeof(MMMixer_Blocko_VarVec_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.FVN_VARTYPE",
// 		DataAttribute = "child_count",
// 		Operator = CxvLogicalOperator.GreaterThan,
// 		Value = 0
// 	});
// }

// 0x060001a8 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarWiz_ViewModel..ctor
// using System.Collections.ObjectModel;
// using System.Windows;
//
// public MMMixer_Blocko_VarWiz_ViewModel()
// {
// 	initialvary = new string[2, 14];
// 	initialtext = new string[14];
// 	_lblrowsvw_Captions = new ObservableCollection<string>(new string[6] { "row0", "row1", "row2", "row3", "row4", "row5" });
// 	_cboRowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);
// 	_txtRowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);
// 	_lblrowsvw_Visibilities = new ObservableCollection<Visibility>(new Visibility[6]);
// 	_cboRowsvw_Enabled = new ObservableCollection<bool>(new bool[6] { true, true, true, true, true, true });
// 	base..ctor();
// }

// 0x060001a9 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarWiz_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static MMMixer_Blocko_VarWiz_ViewModel()
// {
// 	frmVarDef_vwrow0_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow0", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow0"
// 	});
// 	frmVarDef_vwrow1_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow1"
// 	});
// 	frmVarDef_vwrow2_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow2"
// 	});
// 	frmVarDef_vwrow3_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow3"
// 	});
// 	frmVarDef_inputnode_Property = CxvPropertyDeclaration.Register("frmVarDef_inputnode", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input"
// 	});
// 	frmVarDef_vwrow4_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow4"
// 	});
// 	frmVarDef_vwrow5_Property = CxvPropertyDeclaration.Register("frmVarDef_vwrow5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "vwrow5"
// 	});
// 	cboRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("cboRowsvw_1_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow1.@varno"
// 	});
// 	txtRowsvw_5_var5_Property = CxvPropertyDeclaration.Register("txtRowsvw_5_var5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow5.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	txtRowsvw_4_var4_Property = CxvPropertyDeclaration.Register("txtRowsvw_4_var4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow4.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	cboRowsvw_2_var2_Property = CxvPropertyDeclaration.Register("cboRowsvw_2_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow2.@varno"
// 	});
// 	cboRowsvw_0_var0_Property = CxvPropertyDeclaration.Register("cboRowsvw_0_var0_MultiMap", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboRowsvw_0_var0",
// 				DataPath = "@main.Input.@vwrow0.@varno"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "QCALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Qcalc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_qcalc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "QCALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "NET-DUTY",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Net_duty",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_net_duty_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "NET-DUTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "MAXIT",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Maxit",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_maxit_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "MAXIT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "TOL",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Tol",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_tol_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "TOL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "NPOINT",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Npoint",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_npoint_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "NPOINT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "INCR",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Incr",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_incr_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "INCR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PDROP",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pdrop",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pdrop_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "PDROP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DPP-CALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpp_calc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpp_calc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DPP-CALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "UTIL-USAGE",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Util_usage",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_util_usage_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "UTIL-USAGE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "ELEC-USAGE",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Elec_usage",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_elec_usage_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "ELEC-USAGE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "UTIL-COST",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Util_cost",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_util_cost_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "UTIL-COST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "TCALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Tcalc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_tcalc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "TCALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PCALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pcalc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pcalc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "PCALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "VCALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Vcalc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_vcalc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "VCALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DPCALC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpcalc",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpcalc_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DPCALC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "TEMP",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Temp",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_temp_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "TEMP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PRES",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Pres",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_pres_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "PRES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "VFRAC",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Vfrac",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_vfrac_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "VFRAC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DUTY",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Duty",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_duty_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DUTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DELT",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Delt",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_delt_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DELT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DEGSUB",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Degsub",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_degsub_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DEGSUB"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DEGSUP",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Degsup",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_degsup_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DEGSUP"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "T-EST",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_T_est",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_t_est_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "T-EST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "P-EST",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_P_est",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_p_est_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "P-EST"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "DPPARM",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var_Dpparm",
// 				Prompt = ApwnComboPromptResource.design_spec_fvn_variable_dpparm_prompt,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboRowsvw_0_var0",
// 						Value = "DPPARM"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboType_MultiMap_Property = CxvPropertyDeclaration.Register("cboType_MultiMap", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboType_eotype",
// 				DataPath = "@main.Input.FVN_VARTYPE.@varno"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO Var",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Var",
// 				Value = "cboType_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboType_eotype",
// 						Value = "BLOCK-VAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO Vec",
// 				DisplayResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvMultiMapOption_Display_EO_Vec",
// 				Value = "cboType_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboType_eotype",
// 						Value = "BLOCK-VEC"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboRowsvw_5_var5_Property = CxvPropertyDeclaration.Register("cboRowsvw_5_var5", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow5.@varno"
// 	});
// 	cboRowsvw_4_var4_Property = CxvPropertyDeclaration.Register("cboRowsvw_4_var4", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow4.@varno"
// 	});
// 	cboRowsvw_3_var3_Property = CxvPropertyDeclaration.Register("cboRowsvw_3_var3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.@vwrow3.@varno"
// 	});
// 	txtRowsvw_0_var0_Property = CxvPropertyDeclaration.Register("txtRowsvw_0_var0", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow0.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	txtRowsvw_1_var1_Property = CxvPropertyDeclaration.Register("txtRowsvw_1_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow1.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	txtRowsvw_2_var2_Property = CxvPropertyDeclaration.Register("txtRowsvw_2_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow2.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	txtRowsvw_3_var3_Property = CxvPropertyDeclaration.Register("txtRowsvw_3_var3", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.@vwrow3.@varno",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	mbvnum_var2_Property = CxvPropertyDeclaration.Register("mbvnum_var2", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "varno"
// 	});
// 	mbvnum_eodef_Property = CxvPropertyDeclaration.Register("mbvnum_eodef", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EODEF"
// 	});
// 	mbvnum_var1_Property = CxvPropertyDeclaration.Register("mbvnum_var1", typeof(MMMixer_Blocko_VarWiz_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.FVN",
// 		SelectedItemBinding = "mbvnum_var2.Value",
// 		CreateNewPrompt = "Variable number:",
// 		CreateNewPromptResourceKey = "MMMixer_Blocko_VarWiz_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Variable_number_",
// 		CompletePaths = { "@main.CC Nodes.EODEF" }
// 	});
// }

// 0x060001bc AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_ViewModel..ctor
// public MMMixer_Dynam_ViewModel()
// {
// }

// 0x060001bd AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_ViewModel()
// {
// 	dyncsh0_Property = CxvPropertyDeclaration.Register("dyncsh0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DYNCSH0"
// 	});
// 	dyncsh1_Property = CxvPropertyDeclaration.Register("dyncsh1", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DYNCSH1"
// 	});
// 	ucsh0_Property = CxvPropertyDeclaration.Register("ucsh0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UCSH0"
// 	});
// 	ucsh1_Property = CxvPropertyDeclaration.Register("ucsh1", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UCSH1"
// 	});
// 	sht0_Property = CxvPropertyDeclaration.Register("sht0", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SHT0"
// 	});
// 	dyncsh2_Property = CxvPropertyDeclaration.Register("dyncsh2", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DYNCSH2"
// 	});
// 	ucsh2_Property = CxvPropertyDeclaration.Register("ucsh2", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UCSH2"
// 	});
// 	sht123_Property = CxvPropertyDeclaration.Register("sht123", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SHT123"
// 	});
// 	ucsh3_Property = CxvPropertyDeclaration.Register("ucsh3", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UCSH3"
// 	});
// 	ucsh4_Property = CxvPropertyDeclaration.Register("ucsh4", typeof(MMMixer_Dynam_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.UCSH4"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@dyncsh0" },
// 		AccessibleDataPaths = { "@sht0" },
// 		EnteredDataPaths = { "@ucsh0" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@dyncsh1" },
// 		AccessibleDataPaths = { "@sht123" },
// 		EnteredDataPaths = { "@ucsh1" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@dyncsh2" },
// 		AccessibleDataPaths = { "@sht123" },
// 		EnteredDataPaths = { "@ucsh2" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@sht123" },
// 		EnteredDataPaths = { "@ucsh3" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMMixer_Dynam_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@sht123" },
// 		EnteredDataPaths = { "@ucsh4" }
// 	});
// }

// 0x060001c5 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Cont_ViewModel..ctor
// public MMMixer_Dynam_Cont_ViewModel()
// {
// }

// 0x060001c6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Cont_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_Cont_ViewModel()
// {
// 	FraDynCont_level2cont_Property = CxvPropertyDeclaration.Register("FraDynCont_level2cont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LEVEL2CONT"
// 	});
// 	ChkDynContll_level2cont_Property = CxvPropertyDeclaration.Register("ChkDynContll_level2cont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.LEVEL2CONT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FREE4"
// 		}
// 	});
// 	ChkDynContp_prescont_Property = CxvPropertyDeclaration.Register("ChkDynContp_prescont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.PRESCONT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT4F1"
// 		}
// 	});
// 	ChkDynContl_levelcont_Property = CxvPropertyDeclaration.Register("ChkDynContl_levelcont", typeof(MMMixer_Dynam_Cont_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.LEVELCONT",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT4F2"
// 		}
// 	});
// }

// 0x060001d1 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Eqht_ViewModel..ctor
// public MMMixer_Dynam_Eqht_ViewModel()
// {
// }

// 0x060001d2 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Eqht_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_Eqht_ViewModel()
// {
// 	FraDynEqpenv_state_Property = CxvPropertyDeclaration.Register("FraDynEqpenv_state", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT2F3"
// 		}
// 	});
// 	LbtuDynEqpEnvU_htceqp_Property = CxvPropertyDeclaration.Register("LbtuDynEqpEnvU_htceqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.HTCEQP"
// 	});
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT2F2"
// 		}
// 	});
// 	LbtuDynEqpHCCp_cpeqp_Property = CxvPropertyDeclaration.Register("LbtuDynEqpHCCp_cpeqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.CPEQP"
// 	});
// 	lbtuDynEqpHCM_masseqp_Property = CxvPropertyDeclaration.Register("lbtuDynEqpHCM_masseqp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MASSEQP"
// 	});
// 	ChkDynEqHT2_ht2env_Property = CxvPropertyDeclaration.Register("ChkDynEqHT2_ht2env", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.HT2ENV",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT2O2"
// 		}
// 	});
// 	ChkDynEqHT1_eqphcp_Property = CxvPropertyDeclaration.Register("ChkDynEqHT1_eqphcp", typeof(MMMixer_Dynam_Eqht_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.EQPHCP",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// }

// 0x060001d9 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Init_ViewModel..ctor
// public MMMixer_Dynam_Init_ViewModel()
// {
// }

// 0x060001da AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Init_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_Init_ViewModel()
// {
// 	fraDynInitSpec_state_Property = CxvPropertyDeclaration.Register("fraDynInitSpec_state", typeof(MMMixer_Dynam_Init_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT1F1"
// 		}
// 	});
// 	lbtuDynInitLiq1frac_liq1frac_Property = CxvPropertyDeclaration.Register("lbtuDynInitLiq1frac_liq1frac", typeof(MMMixer_Dynam_Init_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIQ1FRAC",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FREE3"
// 		}
// 	});
// 	lbtuDynInitLiqfrac_liqfrac_Property = CxvPropertyDeclaration.Register("lbtuDynInitLiqfrac_liqfrac", typeof(MMMixer_Dynam_Init_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LIQFRAC"
// 	});
// }

// 0x060001e3 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Vessel_ViewModel..ctor
// public MMMixer_Dynam_Vessel_ViewModel()
// {
// }

// 0x060001e4 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_Vessel_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_Vessel_ViewModel()
// {
// 	fraDynVesselGeom_state_Property = CxvPropertyDeclaration.Register("fraDynVesselGeom_state", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT0F1"
// 		}
// 	});
// 	lbtuDynVesselGeomD_diameter_Property = CxvPropertyDeclaration.Register("lbtuDynVesselGeomD_diameter", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.DIAMETER"
// 	});
// 	lbtuDynVesselGeomL_length_Property = CxvPropertyDeclaration.Register("lbtuDynVesselGeomL_length", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.LENGTH"
// 	});
// 	cboDynVesselGeom_MultiMap_Property = CxvPropertyDeclaration.Register("cboDynVesselGeom_MultiMap", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDynVesselGeom_htype",
// 				DataPath = "@main.Input.HTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Elliptical",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Elliptical",
// 				Value = "cboDynVesselGeom_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselGeom_htype",
// 						Value = "ELLIPTICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Hemispherical",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Hemispherical",
// 				Value = "cboDynVesselGeom_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselGeom_htype",
// 						Value = "HEMISPHERICAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Flat",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Flat",
// 				Value = "cboDynVesselGeom_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselGeom_htype",
// 						Value = "FLAT"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	cboDynVesselType_MultiMap_Property = CxvPropertyDeclaration.Register("cboDynVesselType_MultiMap", typeof(MMMixer_Dynam_Vessel_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboDynVesselType_mtype",
// 				DataPath = "@main.Input.MTYPE"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Instantaneous",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Instantaneous",
// 				Value = "cboDynVesselType_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselType_mtype",
// 						Value = "INSTANTANEOUS"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Horizontal",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Horizontal",
// 				Value = "cboDynVesselType_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselType_mtype",
// 						Value = "HORIZONTAL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vertical",
// 				DisplayResourceKey = "MMMixer_Dynam_Vessel_ViewModel__CxvMultiMapOption_Display_Vertical",
// 				Value = "cboDynVesselType_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboDynVesselType_mtype",
// 						Value = "VERTICAL"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT0C1"
// 		}
// 	});
// }

// 0x060001ed AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_VWall_ViewModel..ctor
// public MMMixer_Dynam_VWall_ViewModel()
// {
// }

// 0x060001ee AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Dynam_VWall_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Dynam_VWall_ViewModel()
// {
// 	frmDynVWHT_state_Property = CxvPropertyDeclaration.Register("frmDynVWHT_state", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT3F1"
// 		}
// 	});
// 	lbtuDynVWL3_wallhtcdry_Property = CxvPropertyDeclaration.Register("lbtuDynVWL3_wallhtcdry", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.WALLHTCDRY",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT3L3"
// 		}
// 	});
// 	lbtuDynVWL2_wallhtcwet_Property = CxvPropertyDeclaration.Register("lbtuDynVWL2_wallhtcwet", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.WALLHTCWET",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT3L2"
// 		}
// 	});
// 	lbtuDynVWL1_wallhtc_Property = CxvPropertyDeclaration.Register("lbtuDynVWL1_wallhtc", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.WALLHTC",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.SHT3L1"
// 		}
// 	});
// 	chkDynVWHT_wetht_Property = CxvPropertyDeclaration.Register("chkDynVWHT_wetht", typeof(MMMixer_Dynam_VWall_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.WETHT",
// 		TrueValue = "YES",
// 		FalseValue = "NO"
// 	});
// }

// 0x06000206 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Eoopti_Model_ViewModel..ctor
// public MMMixer_Eoopti_Model_ViewModel()
// {
// 	_blkType = true;
// 	base..ctor();
// }

// 0x06000207 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Eoopti_Model_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMMixer_Eoopti_Model_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
// 	{
// 		DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
// 	});
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_COMPS_T"
// 	});
// 	MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_COMPS"
// 	});
// 	cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.RTOPT"
// 		}
// 	});
// 	grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMMixer_Eoopti_Model_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdScMeth_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.SC_METHOD",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000214 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_ViewModel..ctor
// public MMMixer_EOPort_ViewModel()
// {
// }

// 0x06000215 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_EOPort_ViewModel()
// {
// 	id2_Property = CxvPropertyDeclaration.Register("id2", typeof(MMMixer_EOPort_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "id2"
// 	});
// 	eopt1_Property = CxvPropertyDeclaration.Register("eopt1", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOPT1.@id"
// 	});
// 	eoent1_Property = CxvPropertyDeclaration.Register("eoent1", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT1.@id"
// 	});
// 	eoent2_Property = CxvPropertyDeclaration.Register("eoent2", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT2.@id"
// 	});
// 	eopt4_Property = CxvPropertyDeclaration.Register("eopt4", typeof(MMMixer_EOPort_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOPT4.@id"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_EOPort_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@eopt1", "@eopt4" },
// 		EnteredDataPaths = { "@eoent1" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_EOPort_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@eoent2" }
// 	});
// }

// 0x06000220 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Advanc_ViewModel..ctor
// public MMMixer_EOPort_Advanc_ViewModel()
// {
// }

// 0x06000221 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Advanc_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMMixer_EOPort_Advanc_ViewModel()
// {
// 	MMFrame1_state_Property = CxvPropertyDeclaration.Register("MMFrame1_state", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvGroupBoxProperty
// 	{
// 		DisabledPrompt = Resources.MMMixer_Eoopti_Model_ViewModel_MMFrame1_state_DisabledPrompt
// 	});
// 	MMComboBox6_var1_Property = CxvPropertyDeclaration.Register("MMComboBox6_var1", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_PT_COMP.@id.@id2",
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EOPT2.@id.@id2"
// 		}
// 	});
// 	MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox5_var1",
// 				DataPath = "@main.Input.EO_PT_PHASE.@id.@id2"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "MMComboBox5_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "V"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "MMComboBox5_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "L"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "MMComboBox5_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "VL"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "MMComboBox5_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "VLW"
// 					}
// 				}
// 			}
// 		},
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EOPT2.@id.@id2"
// 		}
// 	});
// 	MMComboBox2_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox2_MultiMap", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox2_var1",
// 				DataPath = "@main.Input.EO_PT_TYPE.@id.@id2"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Material stream (flow basis)",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Material_stream__flow_basis_",
// 				Value = "MMComboBox2_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "MOLE-FLOW"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Material stream (fraction basis)",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Material_stream__fraction_basis_",
// 				Value = "MMComboBox2_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "MOLE-FRAC"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Heat stream",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Heat_stream",
// 				Value = "MMComboBox2_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "HEAT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Work stream",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Work_stream",
// 				Value = "MMComboBox2_MultiMapOption_4",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "WORK"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Generic collection",
// 				DisplayResourceKey = "MMMixer_EOPort_Advanc_ViewModel__CxvMultiMapOption_Display_Generic_collection",
// 				Value = "MMComboBox2_MultiMapOption_5",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox2_var1",
// 						Value = "GENERIC"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox2_Enabled_Property = CxvPropertyDeclaration.Register("MMComboBox2_Enabled", typeof(MMMixer_EOPort_Advanc_ViewModel), new CxvLogicalProperty
// 	{
// 		DataPath = "@main.Input.EO_PT_VALUE.@id",
// 		DataAttribute = "child_count",
// 		Operator = CxvLogicalOperator.GreaterThan,
// 		Value = 0
// 	});
// }

// 0x06000228 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_ObjMan_ViewModel..ctor
// public MMMixer_EOPort_ObjMan_ViewModel()
// {
// }

// 0x06000229 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_ObjMan_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_EOPort_ObjMan_ViewModel()
// {
// 	SubobjectNode_Property = CxvPropertyDeclaration.Register("SubobjectNode", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main"
// 	});
// 	eoent1_Property = CxvPropertyDeclaration.Register("eoent1", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT1"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_EOPort_ObjMan_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@SubobjectNode" },
// 		EnteredDataPaths = { "@eoent1" }
// 	});
// }

// 0x0600022e AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Setup_ViewModel..ctor
// public MMMixer_EOPort_Setup_ViewModel()
// {
// }

// 0x0600022f AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Setup_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_EOPort_Setup_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMMixer_EOPort_Setup_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.EO_PT_VALUE.@id",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x06000238 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Input_ViewModel..ctor
// public MMMixer_Input_ViewModel()
// {
// }

// 0x06000239 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Input_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MN2"
// 	});
// 	phase_Property = CxvPropertyDeclaration.Register("phase", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.FREE2"
// 	});
// 	entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFLASH"
// 	});
// 	flasho_Property = CxvPropertyDeclaration.Register("flasho", typeof(MMMixer_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.HEATWORK1"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@phase", "@spec" },
// 		AccessibleDataPaths = { "@flasho" },
// 		EnteredDataPaths = { "@entfls" }
// 	});
// }

// 0x06000243 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Input_Flasho_ViewModel..ctor
// public MMMixer_Input_Flasho_ViewModel()
// {
// }

// 0x06000244 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Input_Flasho_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Input_Flasho_ViewModel()
// {
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMMixer_Input_Flasho_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Input.NPHASE"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Input.PHASE"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var3",
// 				DataPath = "@main.Input.BLKOPFREWAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_ex",
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
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__ar",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__a",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__a",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMMixer_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water__",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES"
// 	});
// 	lbtuTolerance_var1_Property = CxvPropertyDeclaration.Register("lbtuTolerance_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL"
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT"
// 	});
// 	lbtuTempEst_var1_Property = CxvPropertyDeclaration.Register("lbtuTempEst_var1", typeof(MMMixer_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.T_EST"
// 	});
// }

// 0x0600024d AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Result_ViewModel..ctor
// public MMMixer_Result_ViewModel()
// {
// }

// 0x0600024e AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Result_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Result_ViewModel()
// {
// 	b_temp_Property = CxvPropertyDeclaration.Register("b_temp", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.B_TEMP"
// 	});
// 	b_pres_Property = CxvPropertyDeclaration.Register("b_pres", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.B_PRES"
// 	});
// 	bal1_Property = CxvPropertyDeclaration.Register("bal1", typeof(MMMixer_Result_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.BAL_MOLI_TFL"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMMixer_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@b_temp", "@b_pres" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMMixer_Result_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@bal1" }
// 	});
// }

// 0x06000257 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Result_Summar_ViewModel..ctor
// public MMMixer_Result_Summar_ViewModel()
// {
// }

// 0x06000258 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Result_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_Result_Summar_ViewModel()
// {
// 	lbtu1stLiq_var1_Property = CxvPropertyDeclaration.Register("lbtu1stLiq_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.LIQ_RATIO"
// 	});
// 	lbtuVaporFrac_var1_Property = CxvPropertyDeclaration.Register("lbtuVaporFrac_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.B_VFRAC"
// 	});
// 	lbtuOutPres_var1_Property = CxvPropertyDeclaration.Register("lbtuOutPres_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.B_PRES"
// 	});
// 	lbtuOutTemp_var1_Property = CxvPropertyDeclaration.Register("lbtuOutTemp_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.B_TEMP"
// 	});
// 	lbtuPdrop_var1_Property = CxvPropertyDeclaration.Register("lbtuPdrop_var1", typeof(MMMixer_Result_Summar_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.PDROP"
// 	});
// }

// 0x06000260 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_RTOpt_Input_ViewModel..ctor
// public MMMixer_RTOpt_Input_ViewModel()
// {
// }

// 0x06000261 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_RTOpt_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMMixer_RTOpt_Input_ViewModel()
// {
// 	MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMMixer_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_DPI",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMMixer_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_PRES",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// }

// 0x0600027a AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Blocko_ViewModel..ctor
// public MMFsplit_Blocko_ViewModel()
// {
// }

// 0x0600027b AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Blocko_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Blocko_ViewModel()
// {
// 	blkops_Property = CxvPropertyDeclaration.Register("blkops", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.BKOP"
// 	});
// 	entpro_Property = CxvPropertyDeclaration.Register("entpro", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKPR"
// 	});
// 	entsim_Property = CxvPropertyDeclaration.Register("entsim", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKSI"
// 	});
// 	entdia_Property = CxvPropertyDeclaration.Register("entdia", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKDG"
// 	});
// 	entrep_Property = CxvPropertyDeclaration.Register("entrep", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTBLKRP"
// 	});
// 	genblk_Property = CxvPropertyDeclaration.Register("genblk", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.GENBLKOP"
// 	});
// 	entitp_Property = CxvPropertyDeclaration.Register("entitp", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTIPT"
// 	});
// 	entadd_Property = CxvPropertyDeclaration.Register("entadd", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTADD"
// 	});
// 	entmod_Property = CxvPropertyDeclaration.Register("entmod", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTEOMOD"
// 	});
// 	smspec_Property = CxvPropertyDeclaration.Register("smspec", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMSPEC"
// 	});
// 	sment_Property = CxvPropertyDeclaration.Register("sment", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.SMENT"
// 	});
// 	eodef_Property = CxvPropertyDeclaration.Register("eodef", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EODEF"
// 	});
// 	eoent_Property = CxvPropertyDeclaration.Register("eoent", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.EOENT"
// 	});
// 	varno_Property = CxvPropertyDeclaration.Register("varno", typeof(MMFsplit_Blocko_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "varno"
// 	});
// 	l2cp2_Property = CxvPropertyDeclaration.Register("l2cp2", typeof(MMFsplit_Blocko_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.L2CP2"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@blkops", "@genblk" },
// 		EnteredDataPaths = { "@entpro" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entsim" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entdia" }
// 	});
// 	tab3_var_Property = CxvPropertyDeclaration.Register("tab3_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@l2cp2", "@smspec" },
// 		EnteredDataPaths = { "@entadd", "@entitp", "@entmod", "@sment" }
// 	});
// 	tab4_var_Property = CxvPropertyDeclaration.Register("tab4_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@eodef" },
// 		EnteredDataPaths = { "@eoent" }
// 	});
// 	tab5_var_Property = CxvPropertyDeclaration.Register("tab5_var", typeof(MMFsplit_Blocko_ViewModel), new CxvTabItemProperty
// 	{
// 		EnteredDataPaths = { "@entrep" }
// 	});
// }

// 0x06000293 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Eoopti_Model_ViewModel..ctor
// public MMFsplit_Eoopti_Model_ViewModel()
// {
// }

// 0x06000294 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Eoopti_Model_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization.Properties;
//
// static MMFsplit_Eoopti_Model_ViewModel()
// {
// 	MMFrame1_0_state_Property = CxvPropertyDeclaration.Register("MMFrame1_0_state", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvGroupBoxProperty
// 	{
// 		DisabledPrompt = Resources.MMFsplit_Eoopti_Model_ViewModel_MMframe1_0_state_DisabledPrompt
// 	});
// 	MMComboBox6_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox6_MultiMap", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvMultiMapProperty
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
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Always",
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
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No_model_comps",
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
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Never",
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
// 	MMLBUText10_var1_Property = CxvPropertyDeclaration.Register("MMLBUText10_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.AUTO_COMPS_T"
// 	});
// 	MMComboBox8_1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox8_1_MultiMap", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox8_1_var1",
// 				DataPath = "@main.Input.SPLIT_RATIO"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Yes",
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Yes",
// 				Value = "MMComboBox8_1_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox8_1_var1",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "No",
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_No",
// 				Value = "MMComboBox8_1_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox8_1_var1",
// 						Value = "NO"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_COMPS"
// 	});
// 	cmdAddVar_var1_Property = CxvPropertyDeclaration.Register("cmdAddVar_var1", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvCmdButtonProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.RTOPT"
// 		}
// 	});
// 	grdScMeth_GridData_Property = CxvPropertyDeclaration.Register("grdScMeth_GridData", typeof(MMFsplit_Eoopti_Model_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdScMeth_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.SC_METHOD",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060002a5 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_ViewModel..ctor
// public MMFsplit_Input_ViewModel()
// {
// }

// 0x060002a6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Input_ViewModel()
// {
// 	spec_Property = CxvPropertyDeclaration.Register("spec", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.MAIN"
// 	});
// 	keycomp_Property = CxvPropertyDeclaration.Register("keycomp", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.DEFK"
// 	});
// 	keylck1_Property = CxvPropertyDeclaration.Register("keylck1", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.KEY"
// 	});
// 	entfls_Property = CxvPropertyDeclaration.Register("entfls", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTFLASH"
// 	});
// 	entkey_Property = CxvPropertyDeclaration.Register("entkey", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.ENTKEY"
// 	});
// 	key_Property = CxvPropertyDeclaration.Register("key", typeof(MMFsplit_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "key"
// 	});
// 	stid_Property = CxvPropertyDeclaration.Register("stid", typeof(MMFsplit_Input_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "stid"
// 	});
// 	flasho_Property = CxvPropertyDeclaration.Register("flasho", typeof(MMFsplit_Input_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.CC Nodes.HEATWORK"
// 	});
// 	tab0_var_Property = CxvPropertyDeclaration.Register("tab0_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@spec" }
// 	});
// 	tab1_var_Property = CxvPropertyDeclaration.Register("tab1_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		AccessibleDataPaths = { "@flasho" },
// 		EnteredDataPaths = { "@entfls" }
// 	});
// 	tab2_var_Property = CxvPropertyDeclaration.Register("tab2_var", typeof(MMFsplit_Input_ViewModel), new CxvTabItemProperty
// 	{
// 		CompleteDataPaths = { "@keycomp" },
// 		AccessibleDataPaths = { "@keylck1" },
// 		EnteredDataPaths = { "@entkey" }
// 	});
// }

// 0x060002ae AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Flasho_ViewModel..ctor
// public MMFsplit_Input_Flasho_ViewModel()
// {
// }

// 0x060002af AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Flasho_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Input_Flasho_ViewModel()
// {
// 	lbtuPres_var1_Property = CxvPropertyDeclaration.Register("lbtuPres_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.PRES1"
// 	});
// 	cboPhase_MultiMap_Property = CxvPropertyDeclaration.Register("cboPhase_MultiMap", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var1",
// 				DataPath = "@main.Input.NPHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var2",
// 				DataPath = "@main.Input.PHASE1"
// 			},
// 			new CxvMultiMapVariable
// 			{
// 				Name = "cboPhase_var3",
// 				DataPath = "@main.Input.BLKOPFREWAT"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Only",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Only",
// 				Value = "cboPhase_MultiMapOption_1",
// 				Prompt = "Only a vapor phase exists.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_vapor_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-Only",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_Only",
// 				Value = "cboPhase_MultiMapOption_2",
// 				Prompt = "Only a single liquid phase exists.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_a_single_liquid_phase_exists_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Solid-Only",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Solid_Only",
// 				Value = "cboPhase_MultiMapOption_3",
// 				Prompt = "Only pure salts (electrolytes) or solids exist.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_Only_pure_salts__electrolytes__or_solids_e",
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
// 						Value = "S"
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid",
// 				Value = "cboPhase_MultiMapOption_4",
// 				Prompt = "2 phases (vapor and liquid) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_phases__vapor_and_liquid__are_considered",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-Liquid",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_Liquid",
// 				Value = "cboPhase_MultiMapOption_5",
// 				Prompt = "3 phases (vapor and two liquid phases) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor_and_two_liquid_phases__are",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "NO"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-FreeWater",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_6",
// 				Prompt = "2 liquid phases (organic and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_pure_water__a",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-FreeWater",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_FreeWater",
// 				Value = "cboPhase_MultiMapOption_7",
// 				Prompt = "3 phases (vapor, organic, and pure water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_pure_water__",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "YES"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Liquid-DirtyWater",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_8",
// 				Prompt = "2 liquid phases (organic and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_2_liquid_phases__organic_and_dirty_water__",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Vapor-Liquid-DirtyWater",
// 				DisplayResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Display_Vapor_Liquid_DirtyWater",
// 				Value = "cboPhase_MultiMapOption_9",
// 				Prompt = "3 phases (vapor, organic, and dirty water) are considered in phase equilibrium calculations.",
// 				PromptResourceKey = "MMFsplit_Input_Flasho_ViewModel__CxvMultiMapOption_Prompt_3_phases__vapor__organic__and_dirty_water_",
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
// 					},
// 					new CxvMultiMapValue
// 					{
// 						Variable = "cboPhase_var3",
// 						Value = "DIRTY"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	spnMaxit_var1_Property = CxvPropertyDeclaration.Register("spnMaxit_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.MAXIT1"
// 	});
// 	lbtuTol_var1_Property = CxvPropertyDeclaration.Register("lbtuTol_var1", typeof(MMFsplit_Input_Flasho_ViewModel), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.TOL1"
// 	});
// }

// 0x060002bb AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Keycom_ViewModel..ctor
// public MMFsplit_Input_Keycom_ViewModel()
// {
// }

// 0x060002bc AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Keycom_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Input_Keycom_ViewModel()
// {
// 	fraKeyComps_KEY_Property = CxvPropertyDeclaration.Register("fraKeyComps_KEY", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "KEY"
// 	});
// 	fraKeyComps_STID_Property = CxvPropertyDeclaration.Register("fraKeyComps_STID", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "STID"
// 	});
// 	MMMenuButton2_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var2", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "STID"
// 	});
// 	MMMenuButton2_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton2_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.COMPS.@KEY",
// 		SelectedItemBinding = "MMMenuButton2_var2.Value",
// 		CreateNewPrompt = "Substream:",
// 		CreateNewPromptResourceKey = "MMFsplit_Input_Keycom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Substream_",
// 		CreateNewInputMask = 2,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "KEY",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	MMMenuButton1_var2_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var2", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvParameterProperty
// 	{
// 		Parameter = "KEY"
// 	});
// 	MMListPicker1_state_Property = CxvPropertyDeclaration.Register("MMListPicker1_state", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvGroupBoxProperty
// 	{
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			Parameter = "STID",
// 			Operator = CxvLogicalOperator.IdExists
// 		}
// 	});
// 	MMListPicker1_var1_Property = CxvPropertyDeclaration.Register("MMListPicker1_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "@main.Input.COMPS.@KEY.@STID",
// 		AllowSort = false
// 	});
// 	MMMenuButton1_var1_Property = CxvPropertyDeclaration.Register("MMMenuButton1_var1", typeof(MMFsplit_Input_Keycom_ViewModel), new CxvAdvCollectionProperty
// 	{
// 		DataPath = "@main.Input.COMPS",
// 		SelectedItemBinding = "MMMenuButton1_var2.Value",
// 		CreateNewInputMask = 0,
// 		CreateNewPrompt = "Key component number:",
// 		CreateNewPromptResourceKey = "MMFsplit_Input_Keycom_ViewModel__CxvAdvCollectionProperty_CreateNewPrompt_Key_component_number_",
// 		CompletePaths = { "DEFK1" }
// 	});
// }

// 0x060002c1 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Specif_ViewModel..ctor
// public MMFsplit_Input_Specif_ViewModel()
// {
// }

// 0x060002c2 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Specif_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Input_Specif_ViewModel()
// {
// 	grdSplit_GridData_Property = CxvPropertyDeclaration.Register("grdSplit_GridData", typeof(MMFsplit_Input_Specif_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSplit_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Input.FRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060002c6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Result_ViewModel..ctor
// public MMFsplit_Result_ViewModel()
// {
// }

// 0x060002cb AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Result_Summar_ViewModel..ctor
// public MMFsplit_Result_Summar_ViewModel()
// {
// }

// 0x060002cc AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Result_Summar_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_Result_Summar_ViewModel()
// {
// 	MMScrollArea1_GridData_Property = CxvPropertyDeclaration.Register("MMScrollArea1_GridData", typeof(MMFsplit_Result_Summar_ViewModel), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.STREAMFRAC",
// 			UseChildId = true,
// 			Name = "y"
// 		}
// 	});
// }

// 0x060002d9 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_RTOpt_Input_ViewModel..ctor
// public MMFsplit_RTOpt_Input_ViewModel()
// {
// }

// 0x060002da AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_RTOpt_Input_ViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMFsplit_RTOpt_Input_ViewModel()
// {
// 	MMCheckBox7_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox7_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_RESI_FRA",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMCheckBox4_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox4_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_SPLT_FRA",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox3_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox3_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_PRES",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox2_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox2_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_DPI",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox6_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox6_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_STDV_FLO",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox5_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox5_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_MASS_FLO",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = true
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMFsplit_RTOpt_Input_ViewModel), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.SPC_MOLE_FLO",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// }

// 0x060002e1 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_Specif_ViewModel+grdSplit_GridData_ItemTemplate..ctor
// public grdSplit_GridData_ItemTemplate()
// {
// }

// 0x060002e2 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Input_Specif_ViewModel+grdSplit_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSplit_GridData_ItemTemplate()
// {
// 	txtStream_var1_Property = CxvPropertyDeclaration.Register("txtStream_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FRAC.@STRMID.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	txtKey_var1_Property = CxvPropertyDeclaration.Register("txtKey_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BASIS_KEYNO.@STRMID.@y"
// 	});
// 	spcSpec_Property = CxvPropertyDeclaration.Register("spcSpec", typeof(grdSplit_GridData_ItemTemplate), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Split fraction",
// 				DisplayResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
// 				DataPath = "@main.Input.FRAC.@STRMID.@y"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Flow",
// 				DisplayResourceKey = "MMSsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
// 				DataPath = "@main.Input.BASIS_FLOW.@STRMID.@y",
// 				BasisPath = "@main.Input.FLOW_BASIS.@STRMID.@y"
// 			}
// 		}
// 	});
// }

// 0x060002e5 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x060002e6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox1_0_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_0_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.STREAMFRAC.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.STREAMFRAC.#0",
// 			UseChildId = true,
// 			Name = "x"
// 		}
// 	});
// }

// 0x060002e9 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x060002ea AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Ssplit.MMSsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	MMTextBox1_1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_1_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "x"
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.STREAMFRAC.@y.@x"
// 	});
// }

// 0x060002f2 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..ctor
// public grdScMeth_GridData_ItemTemplate()
// {
// }

// 0x060002f3 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdScMeth_GridData_ItemTemplate()
// {
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FILE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FILESC.@y"
// 		}
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.LOCALSCRIPT.@y",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.LOCASC.@y"
// 		}
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MultimapOptionScriptType",
// 				DataPath = "@main.Input.SC_TYPE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Localscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
// 				Value = "LOCALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "LOCALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Globalscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
// 				Value = "GLOBALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "GLOBALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "File",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
// 				Value = "FILE",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "FILE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.GLOBALSCRIPT.@y",
// 		DisplayedCase = CxsDisplayedCase.Lowercase,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GLOBSC.@y"
// 		}
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.USER_METHOD.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox5_var1",
// 				DataPath = "@main.Input.SC_METHOD.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "INIT",
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
// 				Value = "MMComboBox5_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "INIT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PRESOLVE",
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
// 				Value = "MMComboBox5_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "PRESOLVE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "POSTSOLVE",
// 				DisplayResourceKey = "MMSep_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
// 				Value = "MMComboBox5_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "POSTSOLVE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.GLOBSC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.GLOBALSCRIPT.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.LOCASC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.LOCALSCRIPT.@y"
// 				}
// 			}
// 		}
// 	});
// }

// 0x060002f6 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_OutStr_ViewModel+scaStreamCGI_GridData_ItemTemplate..ctor
// public scaStreamCGI_GridData_ItemTemplate()
// {
// }

// 0x060002f7 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Eoopti_OutStr_ViewModel+scaStreamCGI_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static scaStreamCGI_GridData_ItemTemplate()
// {
// 	txtStream_stream_Property = CxvPropertyDeclaration.Register("txtStream_stream", typeof(scaStreamCGI_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.STR_COMPS.@y"
// 	});
// 	cboCGID_str_comps_Property = CxvPropertyDeclaration.Register("cboCGID_str_comps", typeof(scaStreamCGI_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.STR_COMPS.@y"
// 	});
// }

// 0x060002fa AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Specif_ViewModel+grdSpecs_GridData_ItemTemplate..ctor
// public grdSpecs_GridData_ItemTemplate()
// {
// }

// 0x060002fb AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Input_Specif_ViewModel+grdSpecs_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpecs_GridData_ItemTemplate()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSpecs_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FRACS.@Stream.@Substr.@y"
// 	});
// 	MMSpec1_Property = CxvPropertyDeclaration.Register("MMSpec1", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Split fraction",
// 				DisplayResourceKey = "MMSep_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
// 				DataPath = "@main.Input.FRACS.@Stream.@Substr.@y"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Flow",
// 				DisplayResourceKey = "MMSep_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
// 				DataPath = "@main.Input.FLOWS.@Stream.@Substr.@y",
// 				BasisPath = "@main.Input.FLOWBASIS.@Stream.@Substr.@y"
// 			}
// 		}
// 	});
// }

// 0x060002fe AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate..ctor
// public grdSpltFrac_GridData_ItemTemplate()
// {
// }

// 0x060002ff AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpltFrac_GridData_ItemTemplate()
// {
// 	txtCompId_var1_Property = CxvPropertyDeclaration.Register("txtCompId_var1", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.COMPFRAC.@Substr2.@yy"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPFRAC.@Substr2.#0",
// 			UseChildId = true,
// 			Name = "xx"
// 		}
// 	});
// }

// 0x06000302 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000303 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep.MMSep_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	txtStreamId_var1_Property = CxvPropertyDeclaration.Register("txtStreamId_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "xx"
// 	});
// 	txtCompfrac_var1_Property = CxvPropertyDeclaration.Register("txtCompfrac_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC.@Substr2.@yy.@xx"
// 	});
// }

// 0x06000307 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Specif_ViewModel+grdSpecs_GridData_ItemTemplate..ctor
// public grdSpecs_GridData_ItemTemplate()
// {
// }

// 0x06000308 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Input_Specif_ViewModel+grdSpecs_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpecs_GridData_ItemTemplate()
// {
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSpecs_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FRACS.@Substr.@Stream.@y"
// 	});
// 	spcSpec1_Property = CxvPropertyDeclaration.Register("spcSpec1", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Split fraction",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_1",
// 				DataPath = "@main.Input.FRACS.@Substr.@Stream.@y"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Flow",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Flow_1",
// 				DataPath = "@main.Input.FLOWS.@Substr.@Stream.@y",
// 				BasisPath = "@main.Input.FLOWBASIS.@Substr.@Stream.@y"
// 			}
// 		}
// 	});
// 	spcSpec2_Property = CxvPropertyDeclaration.Register("spcSpec2", typeof(grdSpecs_GridData_ItemTemplate), new CxvSpecProperty
// 	{
// 		Options = 
// 		{
// 			new CxvSpecOption
// 			{
// 				Display = "Mole frac",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Mole_frac",
// 				DataPath = "@main.Input.MFFRAC.@Substr.@Stream.@y"
// 			},
// 			new CxvSpecOption
// 			{
// 				Display = "Mass frac",
// 				DisplayResourceKey = "MMSep2_Input_Specif_ViewModel__CxvSpecOption_Display_Mass_frac",
// 				DataPath = "@main.Input.MAFRAC.@Substr.@Stream.@y"
// 			}
// 		}
// 	});
// }

// 0x0600030b AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate..ctor
// public grdSpltFrac_GridData_ItemTemplate()
// {
// }

// 0x0600030c AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpltFrac_GridData_ItemTemplate()
// {
// 	txtCompId_var1_Property = CxvPropertyDeclaration.Register("txtCompId_var1", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.COMPFRAC.@Substr2.@yy"
// 	});
// 	inner_Property = CxvPropertyDeclaration.Register("inner", typeof(grdSpltFrac_GridData_ItemTemplate), new CxvVectorProperty
// 	{
// 		ItemType = typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate),
// 		IndexBasis = new CxvChildCountIndexBasis
// 		{
// 			DataPath = "@main.Output.COMPFRAC.@Substr2.#0",
// 			UseChildId = true,
// 			Name = "xx"
// 		}
// 	});
// }

// 0x0600030f AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate..ctor
// public grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate()
// {
// }

// 0x06000310 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Sep2.MMSep2_Result_Summar_ViewModel+grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate()
// {
// 	txtStreamId_var1_Property = CxvPropertyDeclaration.Register("txtStreamId_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvParameterProperty
// 	{
// 		Parameter = "xx"
// 	});
// 	txtCompfrac_var1_Property = CxvPropertyDeclaration.Register("txtCompfrac_var1", typeof(grdSpltFrac_GridData_ItemTemplate_inner_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.COMPFRAC.@Substr2.@yy.@xx"
// 	});
// }

// 0x06000316 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel+grdDefine_GridData_ItemTemplate..ctor
// public grdDefine_GridData_ItemTemplate()
// {
// 	PromptLabel = new string[6];
// 	PromptVariable = new string[6];
// 	PromptVec = new string[6];
// 	base..ctor();
// }

// 0x06000317 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel+grdDefine_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
// using AspenTech.AspenPlus.Localization;
//
// static grdDefine_GridData_ItemTemplate()
// {
// 	MMComboBox1_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox1_MultiMap", typeof(grdDefine_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox1_var1",
// 				DataPath = "@main.Input.FVN_VARTYPE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO Var",
// 				DisplayResourceKey = "MMMixer_Blocko_VarVec_ViewModel__CxvMultiMapOption_Display_EO_Var",
// 				Value = "MMComboBox1_MultiMapOption_1",
// 				Prompt = PromptResources.FILEPNUM_17_Prompt_3,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "BLOCK-VAR"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "EO Vec",
// 				DisplayResourceKey = "MMMixer_Blocko_VarVec_ViewModel__CxvMultiMapOption_Display_EO_Vec",
// 				Value = "MMComboBox1_MultiMapOption_2",
// 				Prompt = PromptResources.FILEPNUM_17_Prompt_4,
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox1_var1",
// 						Value = "BLOCK-VEC"
// 					}
// 				}
// 			}
// 		}
// 	});
// }

// 0x06000319 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031a AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Blocko_VarVec_ViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000324 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..ctor
// public grdScMeth_GridData_ItemTemplate()
// {
// }

// 0x06000325 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdScMeth_GridData_ItemTemplate()
// {
// 	MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox5_var1",
// 				DataPath = "@main.Input.SC_METHOD.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "INIT",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
// 				Value = "MMComboBox5_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "INIT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PRESOLVE",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
// 				Value = "MMComboBox5_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "PRESOLVE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "POSTSOLVE",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
// 				Value = "MMComboBox5_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "POSTSOLVE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.USER_METHOD.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.GLOBALSCRIPT.@y",
// 		DisplayedCase = CxsDisplayedCase.Lowercase,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GLOBSC.@y"
// 		}
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MultimapOptionScriptType",
// 				DataPath = "@main.Input.SC_TYPE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Localscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
// 				Value = "LOCALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "LOCALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Globalscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
// 				Value = "GLOBALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "GLOBALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "File",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
// 				Value = "FILE",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "FILE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.LOCALSCRIPT.@y",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.LOCASC.@y"
// 		}
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FILE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FILESC.@y"
// 		}
// 	});
// 	ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.GLOBSC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.GLOBALSCRIPT.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.LOCASC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.LOCALSCRIPT.@y"
// 				}
// 			}
// 		}
// 	});
// }

// 0x0600032b AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Setup_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x0600032c AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Mixer.MMMixer_EOPort_Setup_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_PT_PHYSQT.@id.@y",
// 		DisplayedCase = CxsDisplayedCase.Lowercase,
// 		Sorted = true
// 	});
// 	MMCheckBox1_var1_Property = CxvPropertyDeclaration.Register("MMCheckBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvBooleanProperty
// 	{
// 		DataPath = "@main.Input.THRU.@id.@y",
// 		TrueValue = "YES",
// 		FalseValue = "NO",
// 		DefaultValue = false
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.EO_PT_VALUE.@id.@y"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.EO_PT_VALUE.@id.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMComboBox1_var1_Property = CxvPropertyDeclaration.Register("MMComboBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.EO_PT_UOM.@id.@y",
// 		Sorted = true,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.EOPT3.@id.@y"
// 		}
// 	});
// }

// 0x06000334 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..ctor
// public grdScMeth_GridData_ItemTemplate()
// {
// }

// 0x06000335 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Eoopti_Model_ViewModel+grdScMeth_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdScMeth_GridData_ItemTemplate()
// {
// 	MMComboBox3_var1_Property = CxvPropertyDeclaration.Register("MMComboBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.LOCALSCRIPT.@y",
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.LOCASC.@y"
// 		}
// 	});
// 	MMComboBox2_var1_Property = CxvPropertyDeclaration.Register("MMComboBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MultimapOptionScriptType",
// 				DataPath = "@main.Input.SC_TYPE.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "Localscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Localscript",
// 				Value = "LOCALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "LOCALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "Globalscript",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_Globalscript",
// 				Value = "GLOBALSCRIPT",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "GLOBALSCRIPT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "File",
// 				DisplayResourceKey = "MMMixer_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_File",
// 				Value = "FILE",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MultimapOptionScriptType",
// 						Value = "FILE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	MMComboBox4_var1_Property = CxvPropertyDeclaration.Register("MMComboBox4_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.String,
// 		DataPath = "@main.Input.GLOBALSCRIPT.@y",
// 		DisplayedCase = CxsDisplayedCase.Lowercase,
// 		IsVisibleCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.GLOBSC.@y"
// 		}
// 	});
// 	MMTextBox3_var1_Property = CxvPropertyDeclaration.Register("MMTextBox3_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.USER_METHOD.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase
// 	});
// 	MMComboBox5_MultiMap_Property = CxvPropertyDeclaration.Register("MMComboBox5_MultiMap", typeof(grdScMeth_GridData_ItemTemplate), new CxvMultiMapProperty
// 	{
// 		Variables = 
// 		{
// 			new CxvMultiMapVariable
// 			{
// 				Name = "MMComboBox5_var1",
// 				DataPath = "@main.Input.SC_METHOD.@y"
// 			}
// 		},
// 		Options = 
// 		{
// 			new CxvMultiMapOption
// 			{
// 				Display = "INIT",
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_INIT",
// 				Value = "MMComboBox5_MultiMapOption_1",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "INIT"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "PRESOLVE",
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_PRESOLVE",
// 				Value = "MMComboBox5_MultiMapOption_2",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "PRESOLVE"
// 					}
// 				}
// 			},
// 			new CxvMultiMapOption
// 			{
// 				Display = "POSTSOLVE",
// 				DisplayResourceKey = "MMFsplit_Eoopti_Model_ViewModel__CxvMultiMapOption_Display_POSTSOLVE",
// 				Value = "MMComboBox5_MultiMapOption_3",
// 				Values = 
// 				{
// 					new CxvMultiMapValue
// 					{
// 						Variable = "MMComboBox5_var1",
// 						Value = "POSTSOLVE"
// 					}
// 				}
// 			}
// 		}
// 	});
// 	ID_Property = CxvPropertyDeclaration.Register("ID", typeof(grdScMeth_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.GLOBSC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.GLOBALSCRIPT.@y"
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				Conditions = 
// 				{
// 					new CxvLogicalTest
// 					{
// 						DataPath = "@main.CC_Nodes.LOCASC.@y"
// 					}
// 				},
// 				Property = new CxvVariableProperty
// 				{
// 					ExposeAs = CxvVariableTypeCode.String,
// 					DataPath = "@main.Input.LOCALSCRIPT.@y"
// 				}
// 			}
// 		}
// 	});
// 	MMTextBox2_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_var1", typeof(grdScMeth_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.FILE.@y",
// 		DisplayedCase = CxsDisplayedCase.Uppercase,
// 		IsEnabledCondition = new CxvLogicalTest
// 		{
// 			DataPath = "@main.CC Nodes.FILESC.@y"
// 		}
// 	});
// }

// 0x0600033c AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Specif_ViewModel+grdSplit_GridData_ItemTemplate..ctor
// public grdSplit_GridData_ItemTemplate()
// {
// }

// 0x0600033d AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Input_Specif_ViewModel+grdSplit_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static grdSplit_GridData_ItemTemplate()
// {
// 	txtStream_var1_Property = CxvPropertyDeclaration.Register("txtStream_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Input.FRAC.@y"
// 	});
// 	splitSpec_Property = CxvPropertyDeclaration.Register("splitSpec", typeof(grdSplit_GridData_ItemTemplate), new CxvPropertySelector
// 	{
// 		Choices = 
// 		{
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.CC_Nodes.HEATWORK",
// 				Property = new CxvSpecProperty
// 				{
// 					Options = 
// 					{
// 						new CxvSpecOption
// 						{
// 							Display = "Split fraction",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_2",
// 							DataPath = "@main.Input.FRAC.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Flow",
// 							DataPath = "@main.Input.BASIS_FLOW.@y",
// 							BasisPath = "@main.Input.FLOW_BASIS.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Actual volume flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Actual_volume_flow",
// 							DataPath = "@main.Input.VOL_FLOW.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Limit flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Limit_flow",
// 							DataPath = "@main.Input.BASIS_LIMIT.@y",
// 							BasisPath = "@main.Input.LIMIT_BASIS.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Volume limit flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Volume_limit_flow",
// 							DataPath = "@main.Input.VOL_LIMIT.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Cum limit flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Cum_limit_flow",
// 							DataPath = "@main.Input.BASIS_C_LIM.@y",
// 							BasisPath = "@main.Input.C_LIM_BASIS.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Cum volume limit flow",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Cum_volume_limit_flow",
// 							DataPath = "@main.Input.VOL_C_LIM.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Residual fraction",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Residual_fraction",
// 							DataPath = "@main.Input.R_FRAC.@y"
// 						}
// 					}
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.CC_Nodes.HASWORK1",
// 				Property = new CxvSpecProperty
// 				{
// 					Options = 
// 					{
// 						new CxvSpecOption
// 						{
// 							Display = "Split fraction",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
// 							DataPath = "@main.Input.FRAC.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Power",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Power",
// 							DataPath = "@main.Input.POWER.@y",
// 							BasisPath = "@main.Input.POWER.@y"
// 						}
// 					}
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.CC_Nodes.HASPOWER1",
// 				Property = new CxvSpecProperty
// 				{
// 					Options = 
// 					{
// 						new CxvSpecOption
// 						{
// 							Display = "Split fraction",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction",
// 							DataPath = "@main.Input.FRAC.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Power",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Power",
// 							DataPath = "@main.Input.POWER.@y",
// 							BasisPath = "@main.Input.POWER.@y"
// 						}
// 					}
// 				}
// 			},
// 			new CxvPropertyChoice
// 			{
// 				DataPath = "@main.CC_Nodes.HASHEAT1",
// 				Property = new CxvSpecProperty
// 				{
// 					Options = 
// 					{
// 						new CxvSpecOption
// 						{
// 							Display = "Split fraction",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Split_fraction_1",
// 							DataPath = "@main.Input.FRAC.@y"
// 						},
// 						new CxvSpecOption
// 						{
// 							Display = "Heat Duty",
// 							DisplayResourceKey = "MMFsplit_Input_Specif_ViewModel__CxvSpecOption_Display_Heat_duty",
// 							DataPath = "@main.Input.DUTY.@y",
// 							BasisPath = "@main.Input.FLOW_BASIS.@y"
// 						}
// 					}
// 				}
// 			}
// 		}
// 	});
// 	txtKey_Enable_Property = CxvPropertyDeclaration.Register("txtKey_Enable", typeof(grdSplit_GridData_ItemTemplate), new CxvLogicalProperty
// 	{
// 		Value = true,
// 		Tests = 
// 		{
// 			new CxvLogicalTest
// 			{
// 				DataPath = "@main.CC Nodes.HEATWORK2"
// 			}
// 		}
// 	});
// 	txtKey_var1_Property = CxvPropertyDeclaration.Register("txtKey_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.BASIS_KEYNO.@y"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(grdSplit_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Input.ORDER.@y"
// 	});
// }

// 0x06000341 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate..ctor
// public MMScrollArea1_GridData_ItemTemplate()
// {
// }

// 0x06000342 AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.Fsplit.MMFsplit_Result_Summar_ViewModel+MMScrollArea1_GridData_ItemTemplate..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static MMScrollArea1_GridData_ItemTemplate()
// {
// 	MMTextBox2_1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.STREAM_ORDER.@y"
// 	});
// 	MMTextBox1_var1_Property = CxvPropertyDeclaration.Register("MMTextBox1_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.Id,
// 		DataPath = "@main.Output.STREAMFRAC.@y"
// 	});
// 	MMTextBox2_0_var1_Property = CxvPropertyDeclaration.Register("MMTextBox2_0_var1", typeof(MMScrollArea1_GridData_ItemTemplate), new CxvVariableProperty
// 	{
// 		DataPath = "@main.Output.STREAMFRAC.@y"
// 	});
// }
