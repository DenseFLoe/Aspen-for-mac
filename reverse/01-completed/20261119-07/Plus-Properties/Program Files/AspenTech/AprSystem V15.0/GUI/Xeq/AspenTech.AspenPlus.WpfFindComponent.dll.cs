using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Media;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using AspenTech.APED;
using AspenTech.APED.Core;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenCxs.CxsViewModel.CompositeEvents;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.CompositeEvents;
using AspenTech.AspenPlus.MMControls.Dialogs;
using AspenTech.AspenPlus.MMControls.Properties;
using AspenTech.AspenPlus.MMControls.Scripting;
using AspenTech.AspenPlus.MMDialogs;
using AspenTech.AspenPlus.ModelLibrary.Controls;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Visualisation.CommonShell;
using AspenTech.Visualisation.Controls.Support.Commands;
using AspenTech.WpfControls.Engineering;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.WpfFindComponent")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("Aspen Plus")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, INC. 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("f33b492e-084d-4ed6-a191-f2291bd0aad8")]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
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
namespace AspenTech.AspenPlus.WpfFindComponent
{
	public class CompoundsTabViewModel : INotifyPropertyChanged
	{
		private CompoundsTab _view;

		private bool bSupportBlankSearch = true;

		private static string dbProvider = string.Empty;

		private static string dbMessage = string.Empty;

		private string _root = "";

		private int Sidrow;

		private int DisplayMax = 500;

		private int FindTotal;

		public static List<string> APNames = new List<string>
		{
			"AP065", "APV70", "APV71", "APV72", "APV73", "APV732", "APV80", "APV82", "APV84", "APV86",
			"APV88", "APV90", "APV100", "APV110", "APV120", "APV121", "APV140", "APV150"
		};

		public static List<string> APPUREDatabankNames = new List<string>
		{
			"PURE11", "PURE12", "PURE13", "PURE20", "PURE22", "PURE24", "PURE25", "PURE26", "PURE27", "PURE28",
			"PURE32", "PURE35", "PURE36", "PURE37", "PURE38", "PURE39", "PURE40", "PURE41"
		};

		private string _componentSearchText;

		private string _statusText;

		private ObservableCollection<string> _compClasses = new ObservableCollection<string>();

		private readonly Dictionary<string, string> _compClassesDict = new Dictionary<string, string>
		{
			{
				ApwnResources.CompundClass_All,
				"All"
			},
			{
				ApwnResources.CompundClass_Methylalkanes,
				"Methylalkanes"
			},
			{
				ApwnResources.CompundClass_Dimethylalkanes,
				"Dimethylalkanes"
			},
			{
				ApwnResources.CompundClass_OtherAlkanes,
				"Other-alkanes"
			},
			{
				ApwnResources.CompundClass_Cycloalkanes,
				"Cycloalkanes"
			},
			{
				ApwnResources.CompundClass_Alkylcyclopentanes,
				"Alkylcyclopentanes"
			},
			{
				ApwnResources.CompundClass_Alkylcyclohexanes,
				"Alkylcyclohexanes"
			},
			{
				ApwnResources.CompundClass_MultiringCycloalkanes,
				"Multiring-cycloalkanes"
			},
			{
				ApwnResources.CompundClass_1Alkenes,
				"1-Alkenes"
			},
			{
				ApwnResources.CompundClass_234Alkenes,
				"2,3,4-Alkenes"
			},
			{
				ApwnResources.CompundClass_Methylalkenes,
				"Methylalkenes"
			},
			{
				ApwnResources.CompundClass_EthylhigherAlkenes,
				"Ethyl/higher-alkenes"
			},
			{
				ApwnResources.CompundClass_Cycloalkenes,
				"Cycloalkenes"
			},
			{
				ApwnResources.CompundClass_Dialkenes,
				"Dialkenes"
			},
			{
				ApwnResources.CompundClass_Alkynes,
				"Alkynes"
			},
			{
				ApwnResources.CompundClass_nAlkylbenzenes,
				"n-Alkylbenzenes"
			},
			{
				ApwnResources.CompundClass_OtherAlkylbenzenes,
				"Other-alkylbenzenes"
			},
			{
				ApwnResources.CompundClass_OtherMonoaromatics,
				"Other-monoaromatics"
			},
			{
				ApwnResources.CompundClass_Naphthalenes,
				"Naphthalenes"
			},
			{
				ApwnResources.CompundClass_OtherCondensedRings,
				"Other-condensed-rings"
			},
			{
				ApwnResources.CompundClass_DiphenylPolyaromatics,
				"Diphenyl/polyaromatics"
			},
			{
				ApwnResources.CompundClass_Terpenes,
				"Terpenes"
			},
			{
				ApwnResources.CompundClass_OtherHydrocarbonRings,
				"Other-hydrocarbon-rings"
			},
			{
				ApwnResources.CompundClass_InorganicGases,
				"Inorganic-gases"
			},
			{
				ApwnResources.CompundCLass_Aldehydes,
				"Aldehydes"
			},
			{
				ApwnResources.CompundClass_Ketones,
				"Ketones"
			},
			{
				ApwnResources.CompundClass_nAlcohols,
				"n-Alcohols"
			},
			{
				ApwnResources.CompundClass_OtherAliphaticAlcohols,
				"Other-aliphatic-alcohols"
			},
			{
				ApwnResources.CompundClass_CycloaliphaticAlcohols,
				"Cycloaliphatic-alcohols"
			},
			{
				ApwnResources.CompundClass_AromaticAlcohols,
				"Aromatic-alcohols"
			},
			{
				ApwnResources.CompundClass_Polyols,
				"Polyols"
			},
			{
				ApwnResources.CompundClass_nAliphaticacids,
				"n-Aliphatic-acids"
			},
			{
				ApwnResources.CompundClass_Otheraliphaticacids,
				"Other-aliphatic-acids"
			},
			{
				ApwnResources.CompundClass_Dicarboxylicacids,
				"Dicarboxylic-acids"
			},
			{
				ApwnResources.CompundClass_Aromaticcarboxylicacids,
				"Aromatic-carboxylic-acids"
			},
			{
				ApwnResources.CompundClass_Anhydrides,
				"Anhydrides"
			},
			{
				ApwnResources.CompundClass_Formates,
				"Formates"
			},
			{
				ApwnResources.CompundClass_Acetates,
				"Acetates"
			},
			{
				ApwnResources.CompundClass_Propionatesandbutyrates,
				"Propionates-and-butyrates"
			},
			{
				ApwnResources.CompundClass_Othersaturatedaliphaticesters,
				"Other-saturated-aliphatic-esters"
			},
			{
				ApwnResources.CompundClass_Unsaturatedaliphaticesters,
				"Unsaturated-aliphatic-esters"
			},
			{
				ApwnResources.CompundClass_Aromaticesters,
				"Aromatic-esters"
			},
			{
				ApwnResources.CompundClass_Aliphaticethers,
				"Aliphatic-ethers"
			},
			{
				ApwnResources.CompundClass_Otherethersdiethers,
				"Other-ethers/diethers"
			},
			{
				ApwnResources.CompundClass_Epoxides,
				"Epoxides"
			},
			{
				ApwnResources.CompundClass_Peroxides,
				"Peroxides"
			},
			{
				ApwnResources.CompundClass_C1C2aliphaticchlorides,
				"C1/C2-aliphatic-chlorides"
			},
			{
				ApwnResources.CompundClass_C3higheraliphaticchlorides,
				"C3/higher-aliphatic-chlorides"
			},
			{
				ApwnResources.CompundClass_Aromaticchlorides,
				"Aromatic-chlorides"
			},
			{
				ApwnResources.CompundClass_CHBrcompounds,
				"C,H,Br-compounds"
			},
			{
				ApwnResources.CompundClass_CHIcompounds,
				"C,H,I-compounds"
			},
			{
				ApwnResources.CompundClass_CHFcompounds,
				"C,H,F-compounds"
			},
			{
				ApwnResources.CompundClass_CHmultihalogencompounds,
				"C,H,multihalogen-compounds"
			},
			{
				ApwnResources.CompundClass_nAliphaticprimaryamines,
				"n-Aliphatic-primary-amines"
			},
			{
				ApwnResources.CompundClass_Otheraliphaticamines,
				"Other-aliphatic-amines"
			},
			{
				ApwnResources.CompundClass_Aromaticamines,
				"Aromatic-amines"
			},
			{
				ApwnResources.CompundClass_Otheraminesimines,
				"Other-amines/imines"
			},
			{
				ApwnResources.CompundClass_Nitriles,
				"Nitriles"
			},
			{
				ApwnResources.CompundClass_CHNO2compounds,
				"C,H,NO2-compounds"
			},
			{
				ApwnResources.CompundClass_Isocyanatesdiisocyanates,
				"Isocyanates/diisocyanates"
			},
			{
				ApwnResources.CompundClass_Mercaptans,
				"Mercaptans"
			},
			{
				ApwnResources.CompundClass_Sulfidesthiophenes,
				"Sulfides/thiophenes"
			},
			{
				ApwnResources.CompundClass_Polyfunctionalacids,
				"Polyfunctional-acids"
			},
			{
				ApwnResources.CompundClass_Polyfunctionalesters,
				"Polyfunctional-esters"
			},
			{
				ApwnResources.CompundClass_OtherpolyfunctionalCHO,
				"Other-polyfunctional-C,H,O"
			},
			{
				ApwnResources.CompundClass_Polyfunctionalnitriles,
				"Polyfunctional-nitriles"
			},
			{
				ApwnResources.CompundClass_Nitroamines,
				"Nitroamines"
			},
			{
				ApwnResources.CompundClass_Polyfunctionalamidesamines,
				"Polyfunctional-amides/amines"
			},
			{
				ApwnResources.CompundClass_PolyfunctionalCHON,
				"Polyfunctional-C,H,O,N"
			},
			{
				ApwnResources.CompundClass_PolyfunctionalCHOS,
				"Polyfunctional-C,H,O,S"
			},
			{
				ApwnResources.CompundClass_PolyfunctionalCHOhalide,
				"Polyfunctional-C,H,O,halide"
			},
			{
				ApwnResources.CompundClass_PolyfunctionalCHNhalideO,
				"Polyfunctional-C,H,N,halide,(O)"
			},
			{
				ApwnResources.CompundClass_Otherpolyfunctionalorganics,
				"Other-polyfunctional-organics"
			},
			{
				ApwnResources.CompundClass_Elements,
				"Elements"
			},
			{
				ApwnResources.CompundClass_Silanessiloxanes,
				"Silanes/siloxanes"
			},
			{
				ApwnResources.CompundClass_Organicinorganiccompounds,
				"Organic/inorganic-compounds"
			},
			{
				ApwnResources.CompundClass_Inorganicacids,
				"Inorganic-acids"
			},
			{
				ApwnResources.CompundClass_Inorganicbases,
				"Inorganic-bases"
			},
			{
				ApwnResources.CompundClass_Organicsalts,
				"Organic-salts"
			},
			{
				ApwnResources.CompundClass_Sodiumsalts,
				"Sodium-salts"
			},
			{
				ApwnResources.CompundClass_Otherinorganicsalts,
				"Other-inorganic-salts"
			},
			{
				ApwnResources.CompundClass_Inorganichalides,
				"Inorganic-halides"
			},
			{
				ApwnResources.CompundClass_Otherinorganics,
				"Other-inorganics"
			},
			{
				ApwnResources.CompundClass_Polyacrylics,
				"Polyacrylics"
			},
			{
				ApwnResources.CompundClass_Polyamides,
				"Polyamides"
			},
			{
				ApwnResources.CompundClass_Polydienes,
				"Polydienes"
			},
			{
				ApwnResources.CompundClass_Polyesters,
				"Polyesters"
			},
			{
				ApwnResources.CompundClass_Polyethers,
				"Polyethers"
			},
			{
				ApwnResources.CompundClass_Polyhalogenhydrocarbons,
				"Polyhalogen-hydrocarbons"
			},
			{
				ApwnResources.CompundClass_Polyimides,
				"Polyimides"
			},
			{
				ApwnResources.CompundClass_Polyolefins,
				"Polyolefins"
			},
			{
				ApwnResources.CompundClass_Polypeptides,
				"Polypeptides"
			},
			{
				ApwnResources.CompundClass_Polysaccharides,
				"Polysaccharides"
			},
			{
				ApwnResources.CompundClass_Polysulfides,
				"Polysulfides"
			},
			{
				ApwnResources.CompundClass_Polyureas,
				"Polyureas"
			},
			{
				ApwnResources.CompundClass_Polyurethanes,
				"Polyurethanes"
			},
			{
				ApwnResources.CompundClass_Polyvinyls,
				"Polyvinyls"
			},
			{
				ApwnResources.CompundClass_Silicones,
				"Silicones"
			},
			{
				ApwnResources.CompundClass_Otherpolymers,
				"Other-polymers"
			},
			{
				ApwnResources.CompundClass_Polymersegments,
				"Polymer-segments"
			},
			{
				ApwnResources.CompundClass_Initiators,
				"Initiators"
			},
			{
				ApwnResources.CompundClass_nAlkanes,
				"n-Alkanes"
			},
			{
				ApwnResources.CompundClass_Biocomponents,
				"Biocomponents"
			},
			{
				ApwnResources.CompundClass_Ionicliquids,
				"Ionic-liquids"
			},
			{
				ApwnResources.CompundClass_Solids,
				"Solids"
			}
		};

		private string _selectedCompClass;

		private string _selectedUnit;

		private string _bpHeader;

		private bool _searchActive;

		private bool _threadActive;

		private SafeObservableCollection<DbankComponentItem> _foundComponents = new SafeObservableCollection<DbankComponentItem>();

		private IList _selectedFoundComponents;

		public int SearchType = 1;

		private bool _beginWithChecked;

		private bool _containsChecked = true;

		private bool _equalsChecked;

		public List<string> DBankList = new List<string>();

		private string _bpFrom;

		private string _bpTo;

		private string _mwFrom;

		private string _mwTo;

		private DelegateCommand<object> _findCommand;

		private DelegateCommand<object> _newSearchCommand;

		private DelegateCommand<object> _addCommand;

		public string ComponentSearchText
		{
			get
			{
				return _componentSearchText;
			}
			set
			{
				_componentSearchText = value;
				OnPropertyChanged("ComponentSearchText");
			}
		}

		public string StatusText
		{
			get
			{
				return _statusText;
			}
			set
			{
				_statusText = value;
				OnPropertyChanged("StatusText");
			}
		}

		public ObservableCollection<string> CompClasses => _compClasses;

		public string SelectedCompClass
		{
			get
			{
				return _selectedCompClass;
			}
			set
			{
				_selectedCompClass = value;
				OnPropertyChanged("SelectedCompClass");
			}
		}

		public ObservableCollection<string> Units => new ObservableCollection<string> { "F", "K", "C", "R" };

		public string SelectedUnit
		{
			get
			{
				return _selectedUnit;
			}
			set
			{
				_selectedUnit = value;
				OnPropertyChanged("SelectedUnit");
			}
		}

		public string BPHeader
		{
			get
			{
				return _bpHeader;
			}
			set
			{
				_bpHeader = value;
				OnPropertyChanged("BPHeader");
			}
		}

		public bool SearchActive
		{
			get
			{
				return _searchActive;
			}
			set
			{
				_searchActive = value;
				(FindCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
				(NewSearchCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public bool ThreadActive
		{
			get
			{
				return _threadActive;
			}
			set
			{
				_threadActive = value;
			}
		}

		public SafeObservableCollection<DbankComponentItem> FoundComponents
		{
			get
			{
				return _foundComponents;
			}
			set
			{
				if (_foundComponents != null)
				{
					_foundComponents = value;
					OnPropertyChanged("FoundComponents");
				}
			}
		}

		public IList SelectedFoundComponents
		{
			get
			{
				return _selectedFoundComponents;
			}
			set
			{
				_selectedFoundComponents = value;
				OnPropertyChanged("SelectedFoundComponents");
				(AddCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public bool BeginWithChecked
		{
			get
			{
				return _beginWithChecked;
			}
			set
			{
				_beginWithChecked = value;
				if (_beginWithChecked)
				{
					SearchType = 0;
				}
				OnPropertyChanged("BeginWithChecked");
			}
		}

		public bool ContainsChecked
		{
			get
			{
				return _containsChecked;
			}
			set
			{
				_containsChecked = value;
				if (_containsChecked)
				{
					SearchType = 1;
				}
				OnPropertyChanged("ContainsChecked");
			}
		}

		public bool EqualsChecked
		{
			get
			{
				return _equalsChecked;
			}
			set
			{
				_equalsChecked = value;
				if (_equalsChecked)
				{
					SearchType = 2;
					OnPropertyChanged("EqualsChecked");
				}
			}
		}

		public string BPFrom
		{
			get
			{
				return _bpFrom;
			}
			set
			{
				_bpFrom = value;
				OnPropertyChanged("BPFrom");
			}
		}

		public double? BPFromValue
		{
			get
			{
				if (string.IsNullOrEmpty(_bpFrom))
				{
					return null;
				}
				if (double.TryParse(_bpFrom, out var result))
				{
					return result;
				}
				return null;
			}
		}

		public string BPTo
		{
			get
			{
				return _bpTo;
			}
			set
			{
				_bpTo = value;
				OnPropertyChanged("BPTo");
			}
		}

		public double? BPToValue
		{
			get
			{
				if (string.IsNullOrEmpty(_bpTo))
				{
					return null;
				}
				if (double.TryParse(_bpTo, out var result))
				{
					return result;
				}
				return null;
			}
		}

		public string MWFrom
		{
			get
			{
				return _mwFrom;
			}
			set
			{
				_mwFrom = value;
				OnPropertyChanged("MWFrom");
			}
		}

		public double? MWFromValue
		{
			get
			{
				if (string.IsNullOrEmpty(_mwFrom))
				{
					return null;
				}
				if (double.TryParse(_mwFrom, out var result))
				{
					return result;
				}
				return null;
			}
		}

		public string MWTo
		{
			get
			{
				return _mwTo;
			}
			set
			{
				_mwTo = value;
				OnPropertyChanged("MWTo");
			}
		}

		public double? MWToValue
		{
			get
			{
				if (string.IsNullOrEmpty(_mwTo))
				{
					return null;
				}
				if (double.TryParse(_mwTo, out var result))
				{
					return result;
				}
				return null;
			}
		}

		public ICommand FindCommand
		{
			get
			{
				if (_findCommand == null)
				{
					_findCommand = new DelegateCommand<object>(ExecuteFindCommand, CanExecuteFindCommand);
				}
				return _findCommand;
			}
		}

		public ICommand NewSearchCommand
		{
			get
			{
				if (_newSearchCommand == null)
				{
					_newSearchCommand = new DelegateCommand<object>(ExecuteNewSearchCommand, CanExecuteNewSearchCommand);
				}
				return _newSearchCommand;
			}
		}

		public ICommand AddCommand
		{
			get
			{
				if (_addCommand == null)
				{
					_addCommand = new DelegateCommand<object>(ExecuteAddCommand, CanExecuteAddCommand);
				}
				return _addCommand;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}

		public CompoundsTabViewModel(string pRoot, int lRow, string szSearchText, CompoundsTab view)
		{
			_view = view;
			_root = pRoot;
			Sidrow = lRow;
			ComponentSearchText = szSearchText;
			foreach (string item in _compClassesDict.Keys.OrderBy((string p) => p))
			{
				CompClasses.Add(item);
			}
			SelectedCompClass = CompClasses[CompClasses.IndexOf(ApwnResources.CompundClass_All)];
			int nUnit = 0;
			SmgeHelper.SMgetglobalunitM(22, ref nUnit);
			switch (nUnit)
			{
			case 2:
				SelectedUnit = Units[0];
				break;
			case 4:
				SelectedUnit = Units[2];
				break;
			case 5:
				SelectedUnit = Units[3];
				break;
			default:
				SelectedUnit = Units[1];
				break;
			}
			BPHeader = string.Format(WpfFindComponentResources.BPHeader, _selectedUnit);
			if (!ScriptingSupport.Enabled || !ScriptingSupport.ScriptRunning)
			{
				return;
			}
			FetchSelectedDBanks();
			ComponentSearchThread();
			ScriptingSupport.Result = null;
			List<string> list = new List<string>();
			if (FoundComponents != null)
			{
				foreach (DbankComponentItem foundComponent in FoundComponents)
				{
					list.Add(foundComponent.DbName);
				}
				ScriptingSupport.Result = list;
			}
			if (ScriptingSupport.DialogArgs == null)
			{
				return;
			}
			List<string> list2 = (from item in ScriptingSupport.DialogArgs
				where string.Compare(item.Name, "CompName", StringComparison.OrdinalIgnoreCase) == 0
				select item.Value as string).ToList();
			if (FoundComponents == null || list2 == null)
			{
				return;
			}
			List<DbankComponentItem> list3 = new List<DbankComponentItem>();
			foreach (DbankComponentItem fc in FoundComponents)
			{
				if (!string.IsNullOrEmpty(list2.Find((string p) => string.Compare(p, fc.DbName, StringComparison.OrdinalIgnoreCase) == 0)))
				{
					list3.Add(fc);
				}
			}
			if (list3.Count <= 0)
			{
				return;
			}
			foreach (DbankComponentItem item2 in list3)
			{
				InsertComponent(item2);
			}
			if (FindComponentModule.Container != null)
			{
				FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateDisplayEvent>().Publish(new UpdateDisplayEventArgs
				{
					Sender = this
				});
			}
		}

		private bool IsAsciiCharacters(string s)
		{
			if (!string.IsNullOrEmpty(s))
			{
				char[] array = s.ToCharArray();
				for (int i = 0; i < array.Length; i++)
				{
					if ((uint)array[i] > 255u)
					{
						return false;
					}
				}
			}
			return true;
		}

		private void ExecuteFindCommand(object arg)
		{
			CheckSelectedDBanks();
			if (string.Equals(SelectedCompClass, "All") || string.Equals(SelectedCompClass, "すべて(A)") || string.Equals(SelectedCompClass, "Все") || string.Equals(SelectedCompClass, "全部"))
			{
				if (string.IsNullOrEmpty(ComponentSearchText) && MWFrom == null && MWTo == null && BPFrom == null && BPTo == null && !bSupportBlankSearch)
				{
					MMMessageBox.Show(WpfFindComponentResources.CompoundsTab_Msg, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				}
				else if (!IsAsciiCharacters(ComponentSearchText) && MWFrom == null && MWTo == null && BPFrom == null && BPTo == null)
				{
					MMMessageBox.Show(WpfFindComponentResources.CompundNameInvalid, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				}
				else
				{
					FindTotal = 0;
					StatusText = "";
					lock (DBankList)
					{
						FetchSelectedDBanks();
						Thread thread = new Thread(ComponentSearchThread);
						thread.CurrentCulture = Thread.CurrentThread.CurrentCulture;
						thread.CurrentUICulture = Thread.CurrentThread.CurrentUICulture;
						thread.Start();
					}
				}
			}
			else
			{
				FindTotal = 0;
				StatusText = "";
				lock (DBankList)
				{
					FetchSelectedDBanks();
					Thread thread2 = new Thread(ComponentSearchThread);
					thread2.CurrentCulture = Thread.CurrentThread.CurrentCulture;
					thread2.CurrentUICulture = Thread.CurrentThread.CurrentUICulture;
					thread2.Start();
				}
			}
			if (_view != null)
			{
				_view.txtContainValue.Focus();
			}
		}

		private bool CanExecuteFindCommand(object arg)
		{
			return !SearchActive;
		}

		private void ExecuteNewSearchCommand(object arg)
		{
			SearchActive = false;
			FoundComponents.Clear();
			StatusText = "";
			ComponentSearchText = "";
			SelectedCompClass = CompClasses[CompClasses.IndexOf(ApwnResources.CompundClass_All)];
			MWFrom = null;
			MWTo = null;
			BPFrom = null;
			BPTo = null;
			BPHeader = string.Format(WpfFindComponentResources.BPHeader, _selectedUnit);
			if (_view != null)
			{
				_view.txtContainValue.Focus();
			}
		}

		private bool CanExecuteNewSearchCommand(object arg)
		{
			return !SearchActive;
		}

		private void ExecuteAddCommand(object arg)
		{
			if (SelectedFoundComponents == null)
			{
				return;
			}
			for (int i = 0; i < SelectedFoundComponents.Count; i++)
			{
				int selectedRow = -1;
				if (i == 0)
				{
					selectedRow = Sidrow;
				}
				object obj = SelectedFoundComponents[i];
				InsertComponent(obj as DbankComponentItem, selectedRow);
			}
			if (FindComponentModule.Container != null)
			{
				FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<UpdateDisplayEvent>().Publish(new UpdateDisplayEventArgs
				{
					Sender = this
				});
			}
		}

		private bool CanExecuteAddCommand(object arg)
		{
			if (SelectedFoundComponents != null)
			{
				return SelectedFoundComponents.Count > 0;
			}
			return false;
		}

		private void CheckSelectedDBanks()
		{
			bSupportBlankSearch = true;
			string databank = string.Empty;
			if (SmgeHelper.SMgetdbanksM(out databank, bFirst: true) == 0)
			{
				return;
			}
			while (SmgeHelper.SMgetdbanksM(out databank, bFirst: false) != 0)
			{
				string[] array = databank.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
				if (array.Length <= 1 || !bSupportBlankSearch)
				{
					continue;
				}
				if (array[0].StartsWith("NISTV") || array[0].StartsWith("FACTV") || array[0].StartsWith("APLDB"))
				{
					bSupportBlankSearch = false;
					break;
				}
				if (array[0].StartsWith("APV"))
				{
					if (array[1].StartsWith("PURE") || array[1].StartsWith("AQUEOUS") || array[1].StartsWith("INORGANIC") || array[1].StartsWith("SOLIDS"))
					{
						bSupportBlankSearch = false;
						break;
					}
					bSupportBlankSearch = true;
				}
				else
				{
					if (APPUREDatabankNames.Contains(array[1]) || array[1].StartsWith("AQUEOUS") || array[1].StartsWith("SOLIDS") || array[1].StartsWith("INORGANIC") || array[1].StartsWith("FACTPCD") || array[1].CompareTo("NIST-HOC") == 0 || array[1].StartsWith("NIST-TRC") || array[1].StartsWith("NIST-EOS") || array[1].StartsWith("NIST-IG") || array[1].StartsWith("NIST-RK"))
					{
						bSupportBlankSearch = false;
						break;
					}
					bSupportBlankSearch = true;
				}
			}
		}

		private void FetchSelectedDBanks()
		{
			DBankList.Clear();
			if (SmgeHelper.SMgetdbanksM(out var databank, bFirst: true) != 0)
			{
				while (SmgeHelper.SMgetdbanksM(out databank, bFirst: false) != 0)
				{
					DBankList.Add(databank);
				}
			}
		}

		private bool FetchComponent(string root, string dbkName, int nSearchProp, string propertyValue)
		{
			DbankComponentItem pComponent = null;
			if (SmgeHelper.SMfetchdbkM(dbkName, out pComponent, 1) != 0)
			{
				double? num = -1E+35;
				double? num2 = 1E+35;
				if (BPFromValue.HasValue)
				{
					num = ConvertBPUnitsToK(BPFromValue.Value);
				}
				if (BPToValue.HasValue)
				{
					num2 = ConvertBPUnitsToK(BPToValue.Value);
				}
				while (SmgeHelper.SMfetchdbkM("", out pComponent, 0) != 0)
				{
					if (!SearchActive)
					{
						return false;
					}
					if (!string.IsNullOrEmpty(propertyValue) && (nSearchProp != 0 || (!pComponent.DbName.StartsWith(propertyValue) && !pComponent.Formula.StartsWith(propertyValue))) && (nSearchProp != 2 || (!pComponent.DbName.Equals(propertyValue) && !pComponent.Formula.Equals(propertyValue))) && (nSearchProp != 1 || (!pComponent.DbName.Contains(propertyValue) && !pComponent.Formula.Contains(propertyValue))))
					{
						continue;
					}
					int nCalledSynonym = 0;
					if (SmgeHelper.SMfindsynonymM(pComponent.Formula, propertyValue, 0, out var pSynonym, ref nCalledSynonym) != 0)
					{
						pComponent.Synonym = pSynonym;
					}
					if ((MWFromValue.HasValue && MWToValue.HasValue && pComponent.MW != 0.0 && (pComponent.MW < MWFromValue.Value || pComponent.MW > MWToValue.Value)) || (BPFromValue.HasValue && BPToValue.HasValue && pComponent.BP != 0.0 && (pComponent.BP < num || pComponent.BP > num2)) || (!SelectedCompClass.Equals(ApwnResources.CompundClass_All, StringComparison.InvariantCultureIgnoreCase) && !SelectedCompClass.Equals(pComponent.CompClass, StringComparison.InvariantCultureIgnoreCase)) || FoundComponents.Contains(pComponent))
					{
						continue;
					}
					FindTotal++;
					if (FoundComponents.Count < DisplayMax)
					{
						if (pComponent != null)
						{
							pComponent.BP = ConvertBPUnits(pComponent.BP.Value);
						}
						pComponent.Databank = dbkName;
						_view.Dispatcher.Invoke((Action<DbankComponentItem>)delegate(DbankComponentItem db)
						{
							FoundComponents.Add(db);
						}, pComponent);
					}
				}
			}
			return true;
		}

		private bool FetchComponentAPED(string root, int nSearchProp, string propertyValue, ref string dbVersion)
		{
			dbVersion = "";
			if (nSearchProp == -1)
			{
				return false;
			}
			if (!SearchActive)
			{
				return false;
			}
			AspenTech.APED.IDatabaseCollection databaseCollection = new AspenTech.APED.DatabaseCollection();
			string appPwd = "ATVIEWER";
			databaseCollection.InitializeFromConfigurationFile(null, appPwd);
			if (databaseCollection.Count == 0)
			{
				dbVersion = "Aspen Properties Enterprise Databases inaccessible.";
				return false;
			}
			AspenTech.APED.IDatabase database = null;
			AspenTech.APED.ICompoundManager compoundManager = null;
			foreach (AspenTech.APED.IDatabase item in databaseCollection)
			{
				if (item != null)
				{
					database = item;
					break;
				}
			}
			if (database == null)
			{
				return false;
			}
			if (database is AspenTech.APED.ISupportsCompounds supportsCompounds)
			{
				compoundManager = supportsCompounds.CompoundManager;
			}
			if (database is AspenTech.APED.ISupportsProperties supportsProperties)
			{
				_ = supportsProperties.PropertyManager;
			}
			if (!SearchActive)
			{
				return false;
			}
			string text = "MW";
			string text2 = "TB";
			SortedList sortedList = null;
			ArrayList arrayList = null;
			string[] array = null;
			string compclassToSearch = null;
			if (MWFromValue.HasValue || MWToValue.HasValue || BPFromValue.HasValue || BPToValue.HasValue)
			{
				sortedList = new SortedList();
				arrayList = new ArrayList();
			}
			if (MWFromValue.HasValue || MWToValue.HasValue)
			{
				arrayList.Add(text);
				double num = 1E+35;
				double num2 = 1E+35;
				if (MWFromValue.HasValue)
				{
					num = MWFromValue.Value;
				}
				if (MWToValue.HasValue)
				{
					num2 = MWToValue.Value;
				}
				sortedList.Add(text, new double[2] { num, num2 });
			}
			if (BPFromValue.HasValue || BPToValue.HasValue)
			{
				arrayList.Add(text2);
				double? num3 = 1E+35;
				double? num4 = 1E+35;
				if (BPFromValue.HasValue)
				{
					num3 = ConvertBPUnitsToK(BPFromValue.Value);
				}
				if (BPToValue.HasValue)
				{
					num4 = ConvertBPUnitsToK(BPToValue.Value);
				}
				sortedList.Add(text2, new double[2]
				{
					(!num3.HasValue) ? 0.0 : num3.Value,
					(!num4.HasValue) ? 0.0 : num4.Value
				});
			}
			if (!string.IsNullOrEmpty(SelectedCompClass) && !SelectedCompClass.Equals(ApwnResources.CompundClass_All, StringComparison.InvariantCultureIgnoreCase))
			{
				compclassToSearch = _compClassesDict[SelectedCompClass];
			}
			if (arrayList != null)
			{
				array = new string[arrayList.Count];
				for (int i = 0; i < arrayList.Count; i++)
				{
					array[i] = (string)arrayList[i];
				}
			}
			if (!SearchActive)
			{
				return false;
			}
			ArrayList uniqueCompNames = new ArrayList();
			if (DBankList.Count == 0)
			{
				ICollection matches = null;
				compoundManager.Find(null, nSearchProp, propertyValue, compclassToSearch, sortedList, array, out matches);
				if (!SearchActive)
				{
					return false;
				}
				if (matches != null && matches.Count > 0)
				{
					ProcessMatches(matches, nSearchProp, propertyValue, text, text2, compclassToSearch, uniqueCompNames);
				}
			}
			else
			{
				ArrayList arrayList2 = new ArrayList();
				Hashtable hashtable = new Hashtable();
				foreach (string dBank in DBankList)
				{
					int num5 = dBank.IndexOf(' ');
					string strB = dBank.Substring(0, num5);
					string strB2 = dBank.Substring(num5 + 1, dBank.Length - num5 - 1);
					AspenTech.APED.IDatabank value = null;
					foreach (AspenTech.APED.IDatabase item2 in databaseCollection)
					{
						if (item2.Alias.CompareTo(strB) != 0)
						{
							continue;
						}
						AspenTech.APED.IDatabankCollection Databanks = null;
						item2.EnumerateDatabanks(out Databanks);
						foreach (AspenTech.APED.IDatabank item3 in Databanks)
						{
							if (item3.Name.CompareTo(strB2) == 0)
							{
								value = item3;
								break;
							}
						}
						if (!arrayList2.Contains(item2))
						{
							arrayList2.Add(item2);
							ArrayList arrayList3 = new ArrayList();
							arrayList3.Add(value);
							hashtable.Add(item2, arrayList3);
						}
						else
						{
							((ArrayList)hashtable[item2]).Add(value);
						}
					}
				}
				for (int j = 0; j < arrayList2.Count; j++)
				{
					if (FoundComponents.Count >= DisplayMax)
					{
						break;
					}
					AspenTech.APED.IDatabase database4 = (AspenTech.APED.IDatabase)arrayList2[j];
					ArrayList listDatabanks = (ArrayList)hashtable[database4];
					if (APNames.Contains(database4.Alias))
					{
						GetPureDatabanks(ref listDatabanks);
					}
					if (database4 is AspenTech.APED.ISupportsCompounds supportsCompounds2)
					{
						compoundManager = supportsCompounds2.CompoundManager;
					}
					ICollection matches = null;
					compoundManager.Find(listDatabanks, nSearchProp, propertyValue, compclassToSearch, sortedList, array, out matches);
					if (!SearchActive)
					{
						FoundComponents.Clear();
						return false;
					}
					if (matches != null && matches.Count > 0)
					{
						ProcessMatches(matches, nSearchProp, propertyValue, text, text2, compclassToSearch, uniqueCompNames);
					}
				}
			}
			if (!SearchActive)
			{
				FoundComponents.Clear();
				return false;
			}
			return true;
		}

		private bool FetchComponentAPEDPG(string root, int nSearchProp, string propertyValue, ref string dbVersion)
		{
			dbVersion = "";
			if (nSearchProp == -1)
			{
				return false;
			}
			if (!SearchActive)
			{
				return false;
			}
			AspenTech.APED.Core.IDatabaseCollection databaseCollection = new AspenTech.APED.Core.DatabaseCollection();
			string appView = "ATVIEWER";
			dbMessage = databaseCollection.InitializeFromConfigurationFile(appView, "postgres");
			if (databaseCollection.Count == 0)
			{
				dbVersion = "Aspen Properties Enterprise Databases inaccessible.";
				return false;
			}
			AspenTech.APED.Core.IDatabase database = null;
			AspenTech.APED.Core.ICompoundManager compoundManager = null;
			foreach (AspenTech.APED.Core.IDatabase item in databaseCollection)
			{
				if (item != null)
				{
					database = item;
					break;
				}
			}
			if (database == null)
			{
				return false;
			}
			if (database is AspenTech.APED.Core.ISupportsCompounds supportsCompounds)
			{
				compoundManager = supportsCompounds.CompoundManager;
			}
			if (database is AspenTech.APED.Core.ISupportsProperties supportsProperties)
			{
				_ = supportsProperties.PropertyManager;
			}
			if (!SearchActive)
			{
				return false;
			}
			string text = "MW";
			string text2 = "TB";
			SortedList sortedList = null;
			ArrayList arrayList = null;
			string[] array = null;
			string compclassToSearch = null;
			if (MWFromValue.HasValue || MWToValue.HasValue || BPFromValue.HasValue || BPToValue.HasValue)
			{
				sortedList = new SortedList();
				arrayList = new ArrayList();
			}
			if (MWFromValue.HasValue || MWToValue.HasValue)
			{
				arrayList.Add(text);
				double num = 1E+35;
				double num2 = 1E+35;
				if (MWFromValue.HasValue)
				{
					num = MWFromValue.Value;
				}
				if (MWToValue.HasValue)
				{
					num2 = MWToValue.Value;
				}
				sortedList.Add(text, new double[2] { num, num2 });
			}
			if (BPFromValue.HasValue || BPToValue.HasValue)
			{
				arrayList.Add(text2);
				double? num3 = 1E+35;
				double? num4 = 1E+35;
				if (BPFromValue.HasValue)
				{
					num3 = ConvertBPUnitsToK(BPFromValue.Value);
				}
				if (BPToValue.HasValue)
				{
					num4 = ConvertBPUnitsToK(BPToValue.Value);
				}
				sortedList.Add(text2, new double[2]
				{
					(!num3.HasValue) ? 0.0 : num3.Value,
					(!num4.HasValue) ? 0.0 : num4.Value
				});
			}
			if (!string.IsNullOrEmpty(SelectedCompClass) && !SelectedCompClass.Equals(ApwnResources.CompundClass_All, StringComparison.InvariantCultureIgnoreCase))
			{
				compclassToSearch = _compClassesDict[SelectedCompClass];
			}
			if (arrayList != null)
			{
				array = new string[arrayList.Count];
				for (int i = 0; i < arrayList.Count; i++)
				{
					array[i] = (string)arrayList[i];
				}
			}
			if (!SearchActive)
			{
				return false;
			}
			ArrayList uniqueCompNames = new ArrayList();
			if (DBankList.Count == 0)
			{
				ICollection matches = null;
				compoundManager.Find(null, nSearchProp, propertyValue, compclassToSearch, sortedList, array, out matches);
				if (!SearchActive)
				{
					return false;
				}
				if (matches != null && matches.Count > 0)
				{
					ProcessMatchesPG(matches, nSearchProp, propertyValue, text, text2, compclassToSearch, uniqueCompNames);
				}
			}
			else
			{
				ArrayList arrayList2 = new ArrayList();
				Hashtable hashtable = new Hashtable();
				foreach (string dBank in DBankList)
				{
					int num5 = dBank.IndexOf(' ');
					string strB = dBank.Substring(0, num5);
					string strB2 = dBank.Substring(num5 + 1, dBank.Length - num5 - 1);
					AspenTech.APED.Core.IDatabank value = null;
					foreach (AspenTech.APED.Core.IDatabase item2 in databaseCollection)
					{
						if (item2.Alias.CompareTo(strB) != 0)
						{
							continue;
						}
						AspenTech.APED.Core.IDatabankCollection Databanks = null;
						item2.EnumerateDatabanks(out Databanks);
						foreach (AspenTech.APED.Core.IDatabank item3 in Databanks)
						{
							if (item3.Name.CompareTo(strB2) == 0)
							{
								value = item3;
								break;
							}
						}
						if (!arrayList2.Contains(item2))
						{
							arrayList2.Add(item2);
							ArrayList arrayList3 = new ArrayList();
							arrayList3.Add(value);
							hashtable.Add(item2, arrayList3);
						}
						else
						{
							((ArrayList)hashtable[item2]).Add(value);
						}
					}
				}
				for (int j = 0; j < arrayList2.Count; j++)
				{
					if (FoundComponents.Count >= DisplayMax)
					{
						break;
					}
					AspenTech.APED.Core.IDatabase database4 = (AspenTech.APED.Core.IDatabase)arrayList2[j];
					ArrayList listDatabanks = (ArrayList)hashtable[database4];
					if (APNames.Contains(database4.Alias))
					{
						GetPureDatabanksPG(ref listDatabanks);
					}
					if (database4 is AspenTech.APED.Core.ISupportsCompounds supportsCompounds2)
					{
						compoundManager = supportsCompounds2.CompoundManager;
					}
					ICollection matches = null;
					compoundManager.Find(listDatabanks, nSearchProp, propertyValue, compclassToSearch, sortedList, array, out matches);
					if (!SearchActive)
					{
						FoundComponents.Clear();
						return false;
					}
					if (matches != null && matches.Count > 0)
					{
						ProcessMatchesPG(matches, nSearchProp, propertyValue, text, text2, compclassToSearch, uniqueCompNames);
					}
				}
			}
			if (!SearchActive)
			{
				FoundComponents.Clear();
				return false;
			}
			return true;
		}

		private void GetPureDatabanks(ref ArrayList listDatabanks)
		{
			ArrayList obj = listDatabanks;
			int num = 0;
			int num2 = 0;
			string strB = "";
			foreach (AspenTech.APED.IDatabank item in obj)
			{
				if (APPUREDatabankNames.Contains(item.Name))
				{
					num2++;
					int num3 = Convert.ToInt32(item.Name.Substring(4, 2));
					if (num3 > num)
					{
						num = num3;
						strB = item.Name;
					}
				}
			}
			if (num2 <= 1)
			{
				return;
			}
			ArrayList arrayList = new ArrayList();
			foreach (AspenTech.APED.IDatabank listDatabank in listDatabanks)
			{
				if (APPUREDatabankNames.Contains(listDatabank.Name))
				{
					if (listDatabank.Name.CompareTo(strB) == 0)
					{
						arrayList.Add(listDatabank);
					}
				}
				else
				{
					arrayList.Add(listDatabank);
				}
			}
			listDatabanks.Clear();
			listDatabanks = arrayList;
		}

		private void GetPureDatabanksPG(ref ArrayList listDatabanks)
		{
			ArrayList obj = listDatabanks;
			int num = 0;
			int num2 = 0;
			string strB = "";
			foreach (AspenTech.APED.Core.IDatabank item in obj)
			{
				if (APPUREDatabankNames.Contains(item.Name))
				{
					num2++;
					int num3 = Convert.ToInt32(item.Name.Substring(4, 2));
					if (num3 > num)
					{
						num = num3;
						strB = item.Name;
					}
				}
			}
			if (num2 <= 1)
			{
				return;
			}
			ArrayList arrayList = new ArrayList();
			foreach (AspenTech.APED.Core.IDatabank listDatabank in listDatabanks)
			{
				if (APPUREDatabankNames.Contains(listDatabank.Name))
				{
					if (listDatabank.Name.CompareTo(strB) == 0)
					{
						arrayList.Add(listDatabank);
					}
				}
				else
				{
					arrayList.Add(listDatabank);
				}
			}
			listDatabanks.Clear();
			listDatabanks = arrayList;
		}

		private void MatchesByDBOrder(ICollection inMatches, out ICollection outMatches)
		{
			outMatches = inMatches;
		}

		private void MatchesByDBOrderPG(ICollection inMatches, out ICollection outMatches)
		{
			outMatches = inMatches;
		}

		private void ProcessMatches(ICollection matches, int radioOption, string searchStr, string firstName, string secondName, string compclassToSearch, ArrayList uniqueCompNames)
		{
			ICollection outMatches = null;
			MatchesByDBOrder(matches, out outMatches);
			IEnumerator enumerator = outMatches.GetEnumerator();
			while (enumerator.MoveNext())
			{
				AspenTech.APED.FoundCompounds foundCompounds = (AspenTech.APED.FoundCompounds)enumerator.Current;
				string compound1Name = foundCompounds.Compound.Compound1Name;
				if (uniqueCompNames.Contains(compound1Name))
				{
					continue;
				}
				FindTotal++;
				if (FoundComponents.Count >= DisplayMax)
				{
					continue;
				}
				string text = "";
				string text2 = "";
				string text3 = "";
				string text4 = "";
				string text5 = "";
				AspenTech.APED.IDatabank databank = foundCompounds.Databank;
				if (databank != null)
				{
					text5 = databank.Database.Alias + "." + databank.Name;
				}
				string text6 = "";
				double num = 1E+35;
				double num2 = 1E+35;
				ICollection identifierValues = foundCompounds.IdentifierValues;
				ICollection propertyValues = foundCompounds.PropertyValues;
				if (identifierValues != null && identifierValues.Count > 0)
				{
					Array array = Array.CreateInstance(typeof(AspenTech.APED.IIdentifierValue), identifierValues.Count);
					identifierValues.CopyTo(array, 0);
					for (int i = 0; i < array.Length; i++)
					{
						AspenTech.APED.IIdentifierValue identifierValue = (AspenTech.APED.IIdentifierValue)array.GetValue(i);
						if (identifierValue == null)
						{
							continue;
						}
						string[] array2 = (string[])identifierValue.ValueList;
						switch (identifierValue.Identifier.Name)
						{
						case "NAME":
							text = array2[0];
							break;
						case "ALIAS":
							text2 = array2[0];
							break;
						case "CASRN":
							if (!array2[0].StartsWith("876543-"))
							{
								text3 = array2[0];
							}
							break;
						case "SYNONYM":
						{
							text4 = array2[0];
							for (int j = 0; j < array2.Length; j++)
							{
								if (!(array2[j] != ""))
								{
									continue;
								}
								switch (radioOption)
								{
								case 0:
									if (!array2[j].ToUpper().StartsWith(searchStr.ToUpper()))
									{
										continue;
									}
									text4 = array2[j];
									break;
								case 1:
									if (array2[j].ToUpper().IndexOf(searchStr.ToUpper()) == -1)
									{
										continue;
									}
									text4 = array2[j];
									break;
								case 2:
									if (!array2[j].ToUpper().Equals(searchStr.ToUpper()))
									{
										continue;
									}
									text4 = array2[j];
									break;
								default:
									continue;
								}
								break;
							}
							if (text4.Length > 2)
							{
								break;
							}
							text4 = "";
							for (int k = 0; k < array2.Length; k++)
							{
								if (array2[k].Length > 2)
								{
									text4 = array2[k];
									break;
								}
							}
							break;
						}
						}
					}
				}
				if (propertyValues != null && propertyValues.Count > 0)
				{
					Array array3 = Array.CreateInstance(typeof(AspenTech.APED.IPropertyValue), propertyValues.Count);
					propertyValues.CopyTo(array3, 0);
					for (int l = 0; l < array3.Length; l++)
					{
						AspenTech.APED.IPropertyValue propertyValue = (AspenTech.APED.IPropertyValue)array3.GetValue(l);
						if (propertyValue == null || propertyValue == null || propertyValue.Value == null)
						{
							continue;
						}
						AspenTech.APED.IProperty property = propertyValue.Property;
						if (property.Name == "COMPCLASS")
						{
							if (((string[])propertyValue.Value).Length != 0)
							{
								text6 = ((string[])propertyValue.Value)[0].ToUpper();
							}
							continue;
						}
						if (firstName != "" && property.Name == firstName)
						{
							num = Convert.ToDouble(propertyValue.Value);
						}
						if (secondName != "" && property.Name == secondName)
						{
							num2 = Convert.ToDouble(propertyValue.Value);
						}
					}
				}
				DbankComponentItem dbankComponentItem = new DbankComponentItem();
				if (!string.IsNullOrEmpty(text))
				{
					dbankComponentItem.DbName = text;
				}
				if (!string.IsNullOrEmpty(text2))
				{
					dbankComponentItem.Formula = text2;
				}
				if (!string.IsNullOrEmpty(text5))
				{
					dbankComponentItem.Databank = text5;
				}
				if (!string.IsNullOrEmpty(text3))
				{
					dbankComponentItem.Casno = text3;
				}
				if (!string.IsNullOrEmpty(text6))
				{
					dbankComponentItem.CompClass = text6;
				}
				if (!string.IsNullOrEmpty(text4))
				{
					dbankComponentItem.Synonym = text4;
				}
				if (num < 1E+35)
				{
					dbankComponentItem.MW = num;
				}
				if (num2 < 1E+35)
				{
					dbankComponentItem.BP = ConvertBPUnits(num2);
				}
				if (!FoundComponents.Contains(dbankComponentItem))
				{
					_view.Dispatcher.Invoke((Action<DbankComponentItem>)delegate(DbankComponentItem db2)
					{
						FoundComponents.Add(db2);
					}, dbankComponentItem);
				}
				uniqueCompNames.Add(compound1Name);
			}
		}

		private void ProcessMatchesPG(ICollection matches, int radioOption, string searchStr, string firstName, string secondName, string compclassToSearch, ArrayList uniqueCompNames)
		{
			ICollection outMatches = null;
			MatchesByDBOrderPG(matches, out outMatches);
			IEnumerator enumerator = outMatches.GetEnumerator();
			while (enumerator.MoveNext())
			{
				AspenTech.APED.Core.FoundCompounds foundCompounds = (AspenTech.APED.Core.FoundCompounds)enumerator.Current;
				string compound1Name = foundCompounds.Compound.Compound1Name;
				if (uniqueCompNames.Contains(compound1Name))
				{
					continue;
				}
				FindTotal++;
				if (FoundComponents.Count >= DisplayMax)
				{
					continue;
				}
				string text = "";
				string text2 = "";
				string text3 = "";
				string text4 = "";
				string text5 = "";
				AspenTech.APED.Core.IDatabank databank = foundCompounds.Databank;
				if (databank != null)
				{
					text5 = databank.Database.Alias + "." + databank.Name;
				}
				string text6 = "";
				double num = 1E+35;
				double num2 = 1E+35;
				ICollection identifierValues = foundCompounds.IdentifierValues;
				ICollection propertyValues = foundCompounds.PropertyValues;
				if (identifierValues != null && identifierValues.Count > 0)
				{
					Array array = Array.CreateInstance(typeof(AspenTech.APED.Core.IIdentifierValue), identifierValues.Count);
					identifierValues.CopyTo(array, 0);
					for (int i = 0; i < array.Length; i++)
					{
						AspenTech.APED.Core.IIdentifierValue identifierValue = (AspenTech.APED.Core.IIdentifierValue)array.GetValue(i);
						if (identifierValue == null)
						{
							continue;
						}
						string[] array2 = (string[])identifierValue.ValueList;
						switch (identifierValue.Identifier.Name)
						{
						case "NAME":
							text = array2[0];
							break;
						case "ALIAS":
							text2 = array2[0];
							break;
						case "CASRN":
							if (!array2[0].StartsWith("876543-"))
							{
								text3 = array2[0];
							}
							break;
						case "SYNONYM":
						{
							text4 = array2[0];
							for (int j = 0; j < array2.Length; j++)
							{
								if (!(array2[j] != ""))
								{
									continue;
								}
								switch (radioOption)
								{
								case 0:
									if (!array2[j].ToUpper().StartsWith(searchStr.ToUpper()))
									{
										continue;
									}
									text4 = array2[j];
									break;
								case 1:
									if (array2[j].ToUpper().IndexOf(searchStr.ToUpper()) == -1)
									{
										continue;
									}
									text4 = array2[j];
									break;
								case 2:
									if (!array2[j].ToUpper().Equals(searchStr.ToUpper()))
									{
										continue;
									}
									text4 = array2[j];
									break;
								default:
									continue;
								}
								break;
							}
							if (text4.Length > 2)
							{
								break;
							}
							text4 = "";
							for (int k = 0; k < array2.Length; k++)
							{
								if (array2[k].Length > 2)
								{
									text4 = array2[k];
									break;
								}
							}
							break;
						}
						}
					}
				}
				if (propertyValues != null && propertyValues.Count > 0)
				{
					Array array3 = Array.CreateInstance(typeof(AspenTech.APED.Core.IPropertyValue), propertyValues.Count);
					propertyValues.CopyTo(array3, 0);
					for (int l = 0; l < array3.Length; l++)
					{
						AspenTech.APED.Core.IPropertyValue propertyValue = (AspenTech.APED.Core.IPropertyValue)array3.GetValue(l);
						if (propertyValue == null || propertyValue == null || propertyValue.Value == null)
						{
							continue;
						}
						AspenTech.APED.Core.IProperty property = propertyValue.Property;
						if (property.Name == "COMPCLASS")
						{
							if (((string[])propertyValue.Value).Length != 0)
							{
								text6 = ((string[])propertyValue.Value)[0].ToUpper();
							}
							continue;
						}
						if (firstName != "" && property.Name == firstName)
						{
							num = Convert.ToDouble(propertyValue.Value);
						}
						if (secondName != "" && property.Name == secondName)
						{
							num2 = Convert.ToDouble(propertyValue.Value);
						}
					}
				}
				DbankComponentItem dbankComponentItem = new DbankComponentItem();
				if (!string.IsNullOrEmpty(text))
				{
					dbankComponentItem.DbName = text;
				}
				if (!string.IsNullOrEmpty(text2))
				{
					dbankComponentItem.Formula = text2;
				}
				if (!string.IsNullOrEmpty(text5))
				{
					dbankComponentItem.Databank = text5;
				}
				if (!string.IsNullOrEmpty(text3))
				{
					dbankComponentItem.Casno = text3;
				}
				if (!string.IsNullOrEmpty(text6))
				{
					dbankComponentItem.CompClass = text6;
				}
				if (!string.IsNullOrEmpty(text4))
				{
					dbankComponentItem.Synonym = text4;
				}
				if (num < 1E+35)
				{
					dbankComponentItem.MW = num;
				}
				if (num2 < 1E+35)
				{
					dbankComponentItem.BP = ConvertBPUnits(num2);
				}
				if (!FoundComponents.Contains(dbankComponentItem))
				{
					_view.Dispatcher.Invoke((Action<DbankComponentItem>)delegate(DbankComponentItem db2)
					{
						FoundComponents.Add(db2);
					}, dbankComponentItem);
				}
				uniqueCompNames.Add(compound1Name);
			}
		}

		private double? ConvertBPUnits(double dbBP)
		{
			if (dbBP == 1E+35)
			{
				return null;
			}
			if (SelectedUnit.CompareTo("K") == 0)
			{
				return dbBP;
			}
			double value = 0.0;
			switch (SelectedUnit)
			{
			case "F":
				value = (dbBP - 255.37222) * 1.8;
				break;
			case "C":
				value = dbBP - 273.15;
				break;
			case "R":
				value = dbBP * 1.8;
				break;
			}
			return Truncate(value, 6);
		}

		private double? ConvertBPUnitsToK(double dbBP)
		{
			if (dbBP == 1E+35)
			{
				return null;
			}
			if (SelectedUnit.CompareTo("K") == 0)
			{
				return dbBP;
			}
			double value = 0.0;
			switch (SelectedUnit)
			{
			case "F":
				value = dbBP / 1.8 + 255.37222;
				break;
			case "C":
				value = dbBP + 273.15;
				break;
			case "R":
				value = dbBP / 1.8;
				break;
			}
			return Truncate(value, 6);
		}

		private decimal Truncate(decimal value, int decimals)
		{
			decimal num = (decimal)Math.Pow(10.0, decimals);
			return Math.Truncate(num * value) / num;
		}

		private double Truncate(double value, int decimals)
		{
			return (double)Truncate((decimal)value, decimals);
		}

		private bool InsertComponent(DbankComponentItem dbank, int selectedRow = -1)
		{
			if (dbank == null)
			{
				return false;
			}
			if (SmgeHelper.SMinsertcompM(dbank.Databank, dbank.DbName, selectedRow) != 0)
			{
				_view.Container.AddedSuccessfully = true;
			}
			return true;
		}

		private int GetCurrentTime()
		{
			DateTime now = DateTime.Now;
			return now.Hour * 3600 + now.Minute * 60 + now.Second;
		}

		public void ComponentSearchThread()
		{
			int currentTime = GetCurrentTime();
			SearchActive = true;
			ThreadActive = true;
			bool flag = true;
			BPHeader = string.Format(WpfFindComponentResources.BPHeader, _selectedUnit);
			FoundComponents.Clear();
			string dbVersion = "";
			if (APEDInstalled.GetapedM() != 0)
			{
				if (string.IsNullOrEmpty(dbProvider))
				{
					dbProvider = SystemEnvironment.GetDBProvider;
				}
				flag = ((!(dbProvider.ToLowerInvariant() == "postgres")) ? FetchComponentAPED("Aped", SearchType, ComponentSearchText.ToUpper(), ref dbVersion) : FetchComponentAPEDPG("Aped", SearchType, ComponentSearchText.ToUpper(), ref dbVersion));
			}
			else
			{
				foreach (string dBank in DBankList)
				{
					if (FoundComponents.Count >= DisplayMax)
					{
						break;
					}
					StatusText = string.Format(WpfFindComponentResources.SearchingDatabank, dBank);
					flag = FetchComponent("Happ", dBank, SearchType, ComponentSearchText.ToUpper());
					if (!flag)
					{
						break;
					}
				}
			}
			int num = GetCurrentTime() - currentTime;
			string text = "";
			text = ((num > 1) ? (" (" + num + " seconds)") : (" (" + num + " second)"));
			if (FoundComponents.Count == 0)
			{
				StatusText = WpfFindComponentResources.NoMatch + text;
			}
			else if (num <= 1)
			{
				if (FoundComponents.Count < FindTotal)
				{
					StatusText = string.Format(WpfFindComponentResources.TooManyMatches, FoundComponents.Count, num, FoundComponents.Count);
				}
				else
				{
					StatusText = string.Format(WpfFindComponentResources.MatchesFound, FoundComponents.Count, num);
				}
			}
			else if (FoundComponents.Count < FindTotal)
			{
				StatusText = string.Format(WpfFindComponentResources.TooManyMatches1, FoundComponents.Count, num, FoundComponents.Count);
			}
			else
			{
				StatusText = string.Format(WpfFindComponentResources.MatchesFound1, FoundComponents.Count, num);
			}
			if (!flag)
			{
				if (APEDInstalled.GetapedM() != 0)
				{
					StatusText = StatusText + ". " + dbVersion + "       " + WpfFindComponentResources.SearchAborted;
				}
				else
				{
					StatusText = StatusText + "       " + WpfFindComponentResources.SearchAborted;
				}
			}
			SearchActive = false;
			ThreadActive = false;
		}
	}
	public class SafeObservableCollection<T> : ObservableCollection<T>
	{
		public override event NotifyCollectionChangedEventHandler CollectionChanged;

		protected override void OnCollectionChanged(NotifyCollectionChangedEventArgs e)
		{
			using (BlockReentrancy())
			{
				NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler = CollectionChanged;
				if (notifyCollectionChangedEventHandler == null)
				{
					return;
				}
				Delegate[] invocationList = notifyCollectionChangedEventHandler.GetInvocationList();
				for (int i = 0; i < invocationList.Length; i++)
				{
					NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler2 = (NotifyCollectionChangedEventHandler)invocationList[i];
					if (notifyCollectionChangedEventHandler2.Target is DispatcherObject dispatcherObject && !dispatcherObject.CheckAccess())
					{
						dispatcherObject.Dispatcher.Invoke(DispatcherPriority.DataBind, notifyCollectionChangedEventHandler2, this, e);
					}
					else
					{
						notifyCollectionChangedEventHandler2(this, e);
					}
				}
			}
		}
	}
	public class CompoundsTab : UserControl, IComponentConnector, IStyleConnector
	{
		private string _root = "";

		private int _row;

		private string _searchText = "";

		private GridViewColumnHeader _lastHeaderClicked;

		private ListSortDirection _lastDirection;

		internal RadioButton radioBeginWith;

		internal RadioButton radioContains;

		internal TextBox txtContainValue;

		internal RadioButton radioEquals;

		internal ComboBox cboCompoundClass;

		internal Label lblMW;

		internal NullableTextBox txtMWFrom;

		internal NullableTextBox txtMWTo;

		internal Label lblTB;

		internal NullableTextBox txtBPFrom;

		internal NullableTextBox txtBPTo;

		internal ComboBox cboBpUnit;

		internal Button btnFind;

		internal Button btnNewSearch;

		internal Button btnHelp;

		internal ListViewEx lstComps;

		internal Button btnAdd;

		internal TextBlock txtStatus;

		private bool _contentLoaded;

		public FindComounds Container { get; private set; }

		public CompoundsTab(string root, int lRow, string searchText, FindComounds container)
		{
			InitializeComponent();
			_root = root;
			_row = lRow;
			_searchText = searchText;
			Container = container;
			base.Loaded += CompoundsTab_Loaded;
		}

		private void CompoundsTab_Loaded(object sender, RoutedEventArgs e)
		{
			if (base.DataContext == null)
			{
				base.DataContext = new CompoundsTabViewModel(_root, _row, _searchText, this);
			}
			txtContainValue.Focus();
		}

		private void ListView_ColumnHeaderClicked(object sender, RoutedEventArgs e)
		{
			if (!(e.OriginalSource is GridViewColumnHeader { Role: not GridViewColumnHeaderRole.Padding } gridViewColumnHeader))
			{
				return;
			}
			ListSortDirection listSortDirection = ((gridViewColumnHeader == _lastHeaderClicked && _lastDirection == ListSortDirection.Ascending) ? ListSortDirection.Descending : ListSortDirection.Ascending);
			int num = (lstComps.View as GridView).Columns.IndexOf(gridViewColumnHeader.Column);
			string text = null;
			switch (num)
			{
			case 0:
				text = "DbName";
				break;
			case 1:
				text = "Formula";
				break;
			case 2:
				text = "Databank";
				break;
			case 3:
				text = "Synonym";
				break;
			case 4:
				text = "MW";
				break;
			case 5:
				text = "BP";
				break;
			case 6:
				text = "Casno";
				break;
			case 7:
				text = "CompClass";
				break;
			}
			if (!string.IsNullOrEmpty(text))
			{
				Sort(text, listSortDirection, sender as ListView);
				if (listSortDirection == ListSortDirection.Ascending)
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowUp"] as DataTemplate;
				}
				else
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowDown"] as DataTemplate;
				}
				if (_lastHeaderClicked != null && _lastHeaderClicked != gridViewColumnHeader)
				{
					_lastHeaderClicked.Column.HeaderTemplate = null;
				}
				_lastHeaderClicked = gridViewColumnHeader;
				_lastDirection = listSortDirection;
			}
		}

		private void Sort(string sortBy, ListSortDirection direction, ListView lstView)
		{
			ICollectionView defaultView = CollectionViewSource.GetDefaultView(lstView.ItemsSource);
			defaultView.SortDescriptions.Clear();
			SortDescription item = new SortDescription(sortBy, direction);
			defaultView.SortDescriptions.Add(item);
			defaultView.Refresh();
		}

		private void ListViewItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			if (btnAdd.Command != null && btnAdd.Command.CanExecute(null))
			{
				btnAdd.Command.Execute(null);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/compoundstab.xaml", UriKind.Relative);
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
				radioBeginWith = (RadioButton)target;
				break;
			case 2:
				radioContains = (RadioButton)target;
				break;
			case 3:
				txtContainValue = (TextBox)target;
				break;
			case 4:
				radioEquals = (RadioButton)target;
				break;
			case 5:
				cboCompoundClass = (ComboBox)target;
				break;
			case 6:
				lblMW = (Label)target;
				break;
			case 7:
				txtMWFrom = (NullableTextBox)target;
				break;
			case 8:
				txtMWTo = (NullableTextBox)target;
				break;
			case 9:
				lblTB = (Label)target;
				break;
			case 10:
				txtBPFrom = (NullableTextBox)target;
				break;
			case 11:
				txtBPTo = (NullableTextBox)target;
				break;
			case 12:
				cboBpUnit = (ComboBox)target;
				break;
			case 13:
				btnFind = (Button)target;
				break;
			case 14:
				btnNewSearch = (Button)target;
				break;
			case 15:
				btnHelp = (Button)target;
				break;
			case 16:
				lstComps = (ListViewEx)target;
				lstComps.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			case 18:
				btnAdd = (Button)target;
				break;
			case 19:
				txtStatus = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 17)
			{
				EventSetter eventSetter = new EventSetter();
				eventSetter.Event = Control.MouseDoubleClickEvent;
				eventSetter.Handler = new MouseButtonEventHandler(ListViewItem_MouseDoubleClick);
				((Style)target).Setters.Add(eventSetter);
			}
		}
	}
	public class NullableTextBox : TextBox
	{
		protected override void OnTextChanged(TextChangedEventArgs e)
		{
			if (string.IsNullOrEmpty(base.Text))
			{
				base.Text = null;
			}
			base.OnTextChanged(e);
		}

		private static string GetSystemDecimalSymbol()
		{
			return 0.1.ToString().Replace("0", string.Empty).Replace("1", string.Empty);
		}

		protected override void OnPreviewKeyDown(KeyEventArgs e)
		{
			string systemDecimalSymbol = GetSystemDecimalSymbol();
			if (e.Key == Key.Decimal && systemDecimalSymbol == ",")
			{
				RaiseEvent(new TextCompositionEventArgs(e.Device, new TextComposition(InputManager.Current, this, ","))
				{
					RoutedEvent = UIElement.TextInputEvent
				});
				e.Handled = true;
			}
			else if (e.Key == Key.OemPeriod && systemDecimalSymbol != ".")
			{
				e.Handled = true;
			}
			else if (e.Key == Key.OemComma && systemDecimalSymbol != ",")
			{
				e.Handled = true;
			}
			base.OnPreviewKeyDown(e);
		}
	}
	public class DoubleStringDisplayConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				return value;
			}
			return value.ToString().Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol());
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class TextBoxExTextConverter : IMultiValueConverter
	{
		private TextBoxEx control;

		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values.Length != 2 || !(values[0] is string) || !(values[1] is TextBoxEx) || values[0] == null)
			{
				return values[0];
			}
			control = values[1] as TextBoxEx;
			if (control.ParseStyle == ParsStyles.FLOAT)
			{
				return values[0].ToString().Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol());
			}
			return values[0];
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			object[] array = new object[2] { null, null };
			if (control != null && control.ParseStyle == ParsStyles.FLOAT && value != null)
			{
				array[0] = value.ToString().Replace(MaskingAndValidatingHelper.GetSystemDecimalSymbol(), ".");
			}
			else
			{
				array[0] = value;
			}
			return array;
		}
	}
	internal class CreatePropertyViewModel : INotifyPropertyChanged
	{
		private string _propertySetID;

		private string _description = "";

		private string _propertyForSearch = "";

		private ObservableCollection<PropertySetItem> _availableProps = new ObservableCollection<PropertySetItem>();

		private readonly ObservableCollection<PropertySetItem> _acceptedProps = new ObservableCollection<PropertySetItem>();

		private IEnumerable<PropertyItem> _allProperties;

		private bool _IsSearchPure;

		private bool _isIncludeRefsys;

		private ICommand _searchCommand;

		private bool _isSearchInPending;

		private ICommand _addCommand;

		private ICommand _removeCommand;

		private ICommand _MoveUpCommand;

		private ICommand _moveDownCommand;

		private ApwnCommand<object> _commandOnOK;

		public string PropertySetID
		{
			get
			{
				return _propertySetID;
			}
			set
			{
				_propertySetID = value;
				OnPropertyChanged("PropertySetID");
			}
		}

		public string Description
		{
			get
			{
				return _description;
			}
			set
			{
				_description = value;
				OnPropertyChanged("Description");
			}
		}

		public string PropertyForSearch
		{
			get
			{
				return _propertyForSearch;
			}
			set
			{
				_propertyForSearch = value;
				OnPropertyChanged("PropertyForSearch");
				Executed_SearchCommand(null);
			}
		}

		public ObservableCollection<PropertySetItem> AvailableProps
		{
			get
			{
				return _availableProps;
			}
			set
			{
				_availableProps = value;
				OnPropertyChanged("AvailableProps");
			}
		}

		public ObservableCollection<PropertySetItem> AcceptedProps => _acceptedProps;

		public bool IsSearchPure
		{
			get
			{
				return _IsSearchPure;
			}
			set
			{
				if (_IsSearchPure != value)
				{
					_IsSearchPure = value;
					_allProperties = null;
					Executed_SearchCommand(null);
				}
			}
		}

		public bool IsIncludeRefsys
		{
			get
			{
				return _isIncludeRefsys;
			}
			set
			{
				if (_isIncludeRefsys != value)
				{
					_isIncludeRefsys = value;
					_allProperties = null;
					Executed_SearchCommand(null);
				}
			}
		}

		public ICommand SearchCommand
		{
			get
			{
				if (_searchCommand == null)
				{
					_searchCommand = new DelegateCommand<object>(Executed_SearchCommand, CanExecute_SearchCommand);
				}
				return _searchCommand;
			}
		}

		public ICommand AddCommand
		{
			get
			{
				if (_addCommand == null)
				{
					_addCommand = new DelegateCommand<object>(Executed_AddCommand, CanExecute_AddCommand);
				}
				return _addCommand;
			}
		}

		public ICommand RemoveCommand
		{
			get
			{
				if (_removeCommand == null)
				{
					_removeCommand = new DelegateCommand<object>(Executed_RemoveCommand, CanExecute_RemoveCommand);
				}
				return _removeCommand;
			}
		}

		public ICommand MoveUpCommand
		{
			get
			{
				if (_MoveUpCommand == null)
				{
					_MoveUpCommand = new ApwnCommand<object>(Executed_MoveUpCommand, CanExcute_MoveUpCommand);
				}
				return _MoveUpCommand;
			}
		}

		public ICommand MoveDownCommand
		{
			get
			{
				if (_moveDownCommand == null)
				{
					_moveDownCommand = new ApwnCommand<object>(MoveDownCommand_Executed, MoveDownCommand_CanExecute);
				}
				return _moveDownCommand;
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new ApwnCommand<object>(ExecuteCommandOnOK, CanExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		internal void Reset()
		{
			_availableProps.Clear();
			_acceptedProps.Clear();
			_allProperties = null;
		}

		internal void Executed_SearchCommand(object args)
		{
			if (_isSearchInPending)
			{
				return;
			}
			_isSearchInPending = true;
			Dispatcher.CurrentDispatcher.BeginInvoke(DispatcherPriority.ApplicationIdle, (Action)delegate
			{
				if (_allProperties == null)
				{
					_allProperties = SmgeHelper.FetchAllProperties(IsSearchPure, !IsIncludeRefsys);
				}
				ObservableCollection<PropertySetItem> observableCollection = new ObservableCollection<PropertySetItem>();
				foreach (PropertyItem prop in SmgeHelper.GetMatchedProperties(PropertyForSearch, _allProperties))
				{
					observableCollection.Add(new PropertySetItem
					{
						Name = prop.Name,
						Alias = prop.Alias,
						IsChecked = (AcceptedProps.FirstOrDefault((PropertySetItem p) => p.Name == prop.Name && p.Alias == prop.Alias) != null)
					});
				}
				AvailableProps = observableCollection;
				_isSearchInPending = false;
			});
		}

		private bool CanExecute_SearchCommand(object args)
		{
			return true;
		}

		private void Executed_AddCommand(object args)
		{
			CheckBox checkBox = args as CheckBox;
			if (checkBox != null && (checkBox.IsChecked ?? false))
			{
				if (AcceptedProps.Count > 0)
				{
					int checkbox = SmgeHelper.SMchkmultipleM(-1);
					if (checkbox == 1)
					{
						OpenMessageBox.Show(WpfFindComponentResources.MultipleProperties, WpfFindComponentResources.MultiplePropertiesText, WpfFindComponentResources.OK, "", "", "", "", 0, ref checkbox);
						if (checkbox == 1)
						{
							SmgeHelper.SMchkmultipleM(0);
						}
						else
						{
							SmgeHelper.SMchkmultipleM(1);
						}
					}
				}
				PropertySetItem prop = checkBox.DataContext as PropertySetItem;
				if (prop == null)
				{
					return;
				}
				if (AcceptedProps.FirstOrDefault((PropertySetItem p) => p.Name == prop.Name && p.Alias == prop.Alias) == null)
				{
					if (SmgeHelper.SMchkpropM(prop.Alias) != 0)
					{
						string arg = prop.Name.Replace("\t", string.Empty);
						MMMessageBox.Show(string.Format(WpfFindComponentResources.PropertyHasInPropSet, arg), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
						prop.IsChecked = false;
					}
					else
					{
						AcceptedProps.Insert(0, prop);
					}
				}
				else
				{
					MMMessageBox.Show(string.Format(WpfFindComponentResources.PropertyHasSelected, prop.Name), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				}
				return;
			}
			PropertySetItem prop2 = checkBox.DataContext as PropertySetItem;
			if (prop2 != null)
			{
				PropertySetItem propertySetItem = AcceptedProps.FirstOrDefault((PropertySetItem p) => p.Name == prop2.Name && p.Alias == prop2.Alias);
				if (propertySetItem != null)
				{
					AcceptedProps.Remove(propertySetItem);
				}
			}
		}

		private bool CanExecute_AddCommand(object args)
		{
			return true;
		}

		private void Executed_RemoveCommand(object args)
		{
			PropertySetItem prop = args as PropertySetItem;
			if (prop != null && AcceptedProps.Contains(prop))
			{
				PropertySetItem propertySetItem = AvailableProps.FirstOrDefault((PropertySetItem p) => p.Name == prop.Name && p.Alias == prop.Alias);
				if (propertySetItem != null)
				{
					propertySetItem.IsChecked = false;
				}
				AcceptedProps.Remove(prop);
			}
		}

		private bool CanExecute_RemoveCommand(object args)
		{
			return true;
		}

		private void Executed_MoveUpCommand(object args)
		{
			if (args != null && args.GetType() == typeof(int))
			{
				int num = (int)args;
				AcceptedProps.Move(num, num - 1);
			}
		}

		private bool CanExcute_MoveUpCommand(object args)
		{
			if (args != null && args.GetType() == typeof(int))
			{
				return (int)args > 0;
			}
			return false;
		}

		private void MoveDownCommand_Executed(object args)
		{
			if (args != null && args.GetType() == typeof(int))
			{
				int num = (int)args;
				AcceptedProps.Move(num, num + 1);
			}
		}

		private bool MoveDownCommand_CanExecute(object args)
		{
			if (args != null && args.GetType() == typeof(int))
			{
				int num = (int)args;
				if (num >= 0)
				{
					return num < AcceptedProps.Count - 1;
				}
				return false;
			}
			return false;
		}

		internal void SortAcceptedAcceptedProps(string headerName, ListSortDirection direction)
		{
			IOrderedEnumerable<PropertySetItem> orderedEnumerable = null;
			if (headerName == WpfFindComponentResources.PhyPropName1)
			{
				orderedEnumerable = ((direction != ListSortDirection.Ascending) ? AcceptedProps.OrderByDescending((PropertySetItem p) => p.Name) : AcceptedProps.OrderBy((PropertySetItem p) => p.Name));
			}
			else if (headerName == WpfFindComponentResources.Alias)
			{
				orderedEnumerable = ((direction != ListSortDirection.Ascending) ? AcceptedProps.OrderByDescending((PropertySetItem p) => p.Alias) : AcceptedProps.OrderBy((PropertySetItem p) => p.Alias));
			}
			if (orderedEnumerable == null)
			{
				return;
			}
			List<PropertySetItem> list = new List<PropertySetItem>();
			foreach (PropertySetItem item in orderedEnumerable)
			{
				list.Add(new PropertySetItem
				{
					Name = item.Name,
					Alias = item.Alias,
					IsChecked = item.IsChecked
				});
			}
			AcceptedProps.Clear();
			foreach (PropertySetItem item2 in list)
			{
				AcceptedProps.Add(new PropertySetItem
				{
					Name = item2.Name,
					Alias = item2.Alias,
					IsChecked = item2.IsChecked
				});
			}
		}

		private void ExecuteCommandOnOK(object arg)
		{
			CreateProperty createProperty = arg as CreateProperty;
			if (createProperty != null && !createProperty.SearchPropertyOnly && !string.IsNullOrEmpty(createProperty.txtPropertyID.Text) && createProperty.ExistingIds.Contains(createProperty.txtPropertyID.Text))
			{
				MMMessageBox.Show(createProperty, string.Format(ApwDlgRes.PropSetAlreadyExists, createProperty.txtPropertyID.Text), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return;
			}
			foreach (PropertySetItem acceptedProp in AcceptedProps)
			{
				SmgeHelper.SMinsertpropM(acceptedProp.Alias);
			}
			if (createProperty != null)
			{
				createProperty.IsCancelled = false;
				createProperty.Close();
			}
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			if (arg is CreateProperty createProperty)
			{
				if (createProperty.SearchPropertyOnly)
				{
					return AcceptedProps.Count > 0;
				}
				if (createProperty.txtPropertyID != null)
				{
					if (AcceptedProps.Count > 0)
					{
						return !string.IsNullOrEmpty(createProperty.txtPropertyID.Text);
					}
					return false;
				}
			}
			return AcceptedProps.Count > 0;
		}

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	internal class PropertySetItem : INotifyPropertyChanged
	{
		private bool _isChecked;

		public string Name { get; set; }

		public string Alias { get; set; }

		public bool IsChecked
		{
			get
			{
				return _isChecked;
			}
			set
			{
				_isChecked = value;
				OnPropertyChanged("IsChecked");
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	public class BiomassLookup : Window, IComponentConnector
	{
		internal BiomassLookup biomassLookup;

		internal ListBox leftListBox;

		internal ListBox rightListBox;

		private bool _contentLoaded;

		public BiomassLookup(IUnityContainer container, List<string> biofeedstocks, List<string> bioBaseCompounds, int compoundsTotalCount)
		{
			InitializeComponent();
			base.DataContext = new BiomassLookupViewModel(biofeedstocks, bioBaseCompounds, compoundsTotalCount);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/biomasslookup.xaml", UriKind.Relative);
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
				biomassLookup = (BiomassLookup)target;
				break;
			case 2:
				leftListBox = (ListBox)target;
				break;
			case 3:
				rightListBox = (ListBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class BiomassLookupViewModel : MMViewModel
	{
		private AspenTech.APED.IDatabank _databank;

		private AspenTech.APED.ICompoundManager _compoundManager;

		private AspenTech.APED.IPropertyValueManager _propertyValueManager;

		private AspenTech.APED.Core.IDatabank _databankPG;

		private AspenTech.APED.Core.ICompoundManager _compoundManagerPG;

		private AspenTech.APED.Core.IPropertyValueManager _propertyValueManagerPG;

		private static string dbProvider = string.Empty;

		private static string dbMessage = string.Empty;

		private static string DatabaseName = "APESV";

		private const string DatabankName = "BIOFEED";

		private readonly List<string> _biofeedstocks;

		private readonly List<string> _bioBaseCompounds;

		private readonly int _compoundsTotalCount;

		private readonly List<string> _availableBioBaseCompounds = new List<string>();

		private readonly List<string> _selectedBioBaseCompounds = new List<string>();

		private DelegateCommand<object> okCommand;

		private DelegateCommand<object> cancelCommand;

		public IEnumerable<string> AvailableBioBaseCompounds => _availableBioBaseCompounds.OrderBy((string x) => x);

		public IEnumerable<string> SelectedBioBaseCompounds => _selectedBioBaseCompounds.OrderBy((string x) => x);

		public ICommand OKCommand
		{
			get
			{
				if (okCommand == null)
				{
					okCommand = new DelegateCommand<object>(ExecuteOKCommand, CanExecuteOKCommand);
				}
				return okCommand;
			}
		}

		public ICommand CancelCommand
		{
			get
			{
				if (cancelCommand == null)
				{
					cancelCommand = new DelegateCommand<object>(ExecuteCancelCommand);
				}
				return cancelCommand;
			}
		}

		public BiomassLookupViewModel(List<string> biofeedstocks, List<string> bioBaseCompounds, int compoundsTotalCount)
		{
			try
			{
				_biofeedstocks = biofeedstocks;
				_bioBaseCompounds = bioBaseCompounds;
				_compoundsTotalCount = compoundsTotalCount;
				if (string.IsNullOrEmpty(dbProvider))
				{
					dbProvider = SystemEnvironment.GetDBProvider;
				}
				if (dbProvider.ToLowerInvariant() == "postgres")
				{
					SetupSearchPG(DatabaseName, "BIOFEED");
					if (_databankPG != null)
					{
						SetupBaseAndBiostockComponentsPG();
					}
				}
				else
				{
					SetupSearch(DatabaseName, "BIOFEED");
					if (_databank != null)
					{
						SetupBaseAndBiostockComponents();
					}
				}
			}
			catch (Exception)
			{
			}
		}

		private void SetupSearch(string databaseName, string databankName)
		{
			AspenTech.APED.DatabaseCollection databaseCollection = new AspenTech.APED.DatabaseCollection();
			string appPwd = "ATVIEWER";
			databaseCollection.InitializeFromConfigurationFile(null, appPwd);
			if (databaseCollection.Count == 0)
			{
				return;
			}
			AspenTech.APED.IDatabase database = null;
			foreach (AspenTech.APED.IDatabase item in databaseCollection)
			{
				if (item != null && item.Alias.StartsWith(DatabaseName))
				{
					database = item;
					break;
				}
			}
			if (database == null)
			{
				foreach (AspenTech.APED.IDatabase item2 in databaseCollection)
				{
					item2.EnumerateDatabanks(out var Databanks);
					foreach (AspenTech.APED.IDatabank item3 in Databanks)
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
				foreach (AspenTech.APED.IDatabank item4 in Databanks2)
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
				_compoundManager = (database as AspenTech.APED.ISupportsCompounds)?.CompoundManager;
				_propertyValueManager = (database as AspenTech.APED.ISupportsPropertyValues)?.PropertyValueManager;
			}
		}

		private void SetupSearchPG(string databaseName, string databankName)
		{
			AspenTech.APED.Core.DatabaseCollection databaseCollection = new AspenTech.APED.Core.DatabaseCollection();
			string appView = "ATVIEWER";
			dbMessage = databaseCollection.InitializeFromConfigurationFile(appView, "postgres");
			if (databaseCollection.Count == 0)
			{
				return;
			}
			AspenTech.APED.Core.IDatabase database = null;
			foreach (AspenTech.APED.Core.IDatabase item in databaseCollection)
			{
				if (item != null && item.Alias.StartsWith(DatabaseName))
				{
					database = item;
					break;
				}
			}
			if (database == null)
			{
				foreach (AspenTech.APED.Core.IDatabase item2 in databaseCollection)
				{
					item2.EnumerateDatabanks(out var Databanks);
					foreach (AspenTech.APED.Core.IDatabank item3 in Databanks)
					{
						if (item3.Name.Equals("BIOFEED", StringComparison.InvariantCultureIgnoreCase))
						{
							database = item2;
							DatabaseName = item2.Alias;
							_databankPG = item3;
							break;
						}
					}
					if (_databankPG != null)
					{
						break;
					}
				}
			}
			else
			{
				database.EnumerateDatabanks(out var Databanks2);
				foreach (AspenTech.APED.Core.IDatabank item4 in Databanks2)
				{
					if (item4.Name.Equals("BIOFEED", StringComparison.InvariantCultureIgnoreCase))
					{
						_databankPG = item4;
						break;
					}
				}
			}
			if (database != null)
			{
				_compoundManagerPG = (database as AspenTech.APED.Core.ISupportsCompounds)?.CompoundManager;
				_propertyValueManagerPG = (database as AspenTech.APED.Core.ISupportsPropertyValues)?.PropertyValueManager;
			}
		}

		private Dictionary<string, Compound> ProcessAllCompoundsFromBIOFEED()
		{
			Dictionary<string, Compound> dictionary = new Dictionary<string, Compound>();
			_compoundManager.GetAllCompounds(_databank, out var compounds);
			foreach (AspenTech.APED.FoundCompounds item in compounds)
			{
				string text = null;
				string alias = null;
				string cASRN = null;
				string text2 = null;
				ICollection identifierValues = item.IdentifierValues;
				if (identifierValues != null && identifierValues.Count > 0)
				{
					Array array = Array.CreateInstance(typeof(AspenTech.APED.IIdentifierValue), identifierValues.Count);
					identifierValues.CopyTo(array, 0);
					foreach (AspenTech.APED.IIdentifierValue item2 in array)
					{
						if (item2 != null)
						{
							string[] array2 = (string[])item2.ValueList;
							switch (item2.Identifier.Name)
							{
							case "NAME":
								text = array2[0];
								break;
							case "alias":
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
					Array array3 = Array.CreateInstance(typeof(AspenTech.APED.IPropertyValue), propertyValues.Count);
					propertyValues.CopyTo(array3, 0);
					foreach (AspenTech.APED.IPropertyValue item3 in array3)
					{
						if (item3 != null && item3 != null && item3.Value != null && item3.Property.Name == "COMPCLASS" && ((string[])item3.Value).Length != 0)
						{
							text2 = ((string[])item3.Value)[0].ToUpper();
						}
					}
				}
				AspenTech.APED.IPropertyValue propertyValue2 = null;
				if (!string.IsNullOrEmpty(text2) && text2.Equals("BIOCOMPONENTS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !dictionary.ContainsKey(text))
				{
					dictionary.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						CompoundClass = CompoundClasses.BioComponents
					});
				}
				if (!string.IsNullOrEmpty(text2) && text2.Equals("SOLIDS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !dictionary.ContainsKey(text))
				{
					_propertyValueManager.GetUnaryPropertyValue(_databank, text, "NAME", "BIOPOS", out propertyValue2);
					string bioPos = ((double[])propertyValue2.Value)[0].ToString();
					dictionary.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						BioPos = bioPos,
						CompoundClass = CompoundClasses.Solids
					});
				}
			}
			return dictionary;
		}

		private Dictionary<string, Compound> ProcessAllCompoundsFromBIOFEEDPG()
		{
			Dictionary<string, Compound> dictionary = new Dictionary<string, Compound>();
			_compoundManagerPG.GetAllCompounds(_databankPG, out var compounds);
			foreach (AspenTech.APED.Core.FoundCompounds item in compounds)
			{
				string text = null;
				string alias = null;
				string cASRN = null;
				string text2 = null;
				ICollection identifierValues = item.IdentifierValues;
				if (identifierValues != null && identifierValues.Count > 0)
				{
					Array array = Array.CreateInstance(typeof(AspenTech.APED.Core.IIdentifierValue), identifierValues.Count);
					identifierValues.CopyTo(array, 0);
					foreach (AspenTech.APED.Core.IIdentifierValue item2 in array)
					{
						if (item2 != null)
						{
							string[] array2 = (string[])item2.ValueList;
							switch (item2.Identifier.Name)
							{
							case "NAME":
								text = array2[0];
								break;
							case "alias":
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
					Array array3 = Array.CreateInstance(typeof(AspenTech.APED.Core.IPropertyValue), propertyValues.Count);
					propertyValues.CopyTo(array3, 0);
					foreach (AspenTech.APED.Core.IPropertyValue item3 in array3)
					{
						if (item3 != null && item3 != null && item3.Value != null && item3.Property.Name == "COMPCLASS" && ((string[])item3.Value).Length != 0)
						{
							text2 = ((string[])item3.Value)[0].ToUpper();
						}
					}
				}
				AspenTech.APED.Core.IPropertyValue propertyValue2 = null;
				if (!string.IsNullOrEmpty(text2) && text2.Equals("BIOCOMPONENTS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !dictionary.ContainsKey(text))
				{
					dictionary.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						CompoundClass = CompoundClasses.BioComponents
					});
				}
				if (!string.IsNullOrEmpty(text2) && text2.Equals("SOLIDS", StringComparison.InvariantCultureIgnoreCase) && !string.IsNullOrEmpty(text) && !dictionary.ContainsKey(text))
				{
					_propertyValueManagerPG.GetUnaryPropertyValue(_databankPG, text, "NAME", "BIOPOS", out propertyValue2);
					string bioPos = ((double[])propertyValue2.Value)[0].ToString();
					dictionary.Add(text, new Compound
					{
						Name = text,
						Alias = alias,
						CASRN = cASRN,
						BioPos = bioPos,
						CompoundClass = CompoundClasses.Solids
					});
				}
			}
			return dictionary;
		}

		private void SetupBaseAndBiostockComponents()
		{
			Dictionary<string, Compound> dictionary = ProcessAllCompoundsFromBIOFEED();
			dictionary.Values.Where((Compound x) => x.CompoundClass == CompoundClasses.BioComponents);
			Dictionary<string, Compound> dictionary2 = dictionary.Where((KeyValuePair<string, Compound> x) => x.Value.CompoundClass == CompoundClasses.Solids).ToDictionary((KeyValuePair<string, Compound> x) => x.Value.BioPos, (KeyValuePair<string, Compound> x) => x.Value);
			if (_biofeedstocks != null)
			{
				foreach (string biofeedstock in _biofeedstocks)
				{
					_propertyValueManager.GetUnaryPropertyValue(_databank, biofeedstock, "NAME", "BIOID", out var propertyValue);
					if (propertyValue == null || !(propertyValue.Value is double[] array))
					{
						continue;
					}
					for (int num = 0; num < array.Length; num++)
					{
						double num2 = array[num];
						if (num2 == 1E+35)
						{
							continue;
						}
						string text = num2.ToString();
						if (Convert.ToInt32(text) > 0)
						{
							string name = dictionary2[text].Name;
							if (!_selectedBioBaseCompounds.Contains(name))
							{
								_selectedBioBaseCompounds.Add(name);
							}
						}
					}
				}
			}
			foreach (KeyValuePair<string, Compound> item in dictionary2)
			{
				_availableBioBaseCompounds.Add(item.Value.Name);
			}
		}

		private void SetupBaseAndBiostockComponentsPG()
		{
			Dictionary<string, Compound> dictionary = ProcessAllCompoundsFromBIOFEEDPG();
			dictionary.Values.Where((Compound x) => x.CompoundClass == CompoundClasses.BioComponents);
			Dictionary<string, Compound> dictionary2 = dictionary.Where((KeyValuePair<string, Compound> x) => x.Value.CompoundClass == CompoundClasses.Solids).ToDictionary((KeyValuePair<string, Compound> x) => x.Value.BioPos, (KeyValuePair<string, Compound> x) => x.Value);
			if (_biofeedstocks != null)
			{
				foreach (string biofeedstock in _biofeedstocks)
				{
					_propertyValueManagerPG.GetUnaryPropertyValue(_databankPG, biofeedstock, "NAME", "BIOID", out var propertyValue);
					if (propertyValue == null || !(propertyValue.Value is double[] array))
					{
						continue;
					}
					for (int num = 0; num < array.Length; num++)
					{
						double num2 = array[num];
						if (num2 == 1E+35)
						{
							continue;
						}
						string text = num2.ToString();
						if (Convert.ToInt32(text) > 0)
						{
							string name = dictionary2[text].Name;
							if (!_selectedBioBaseCompounds.Contains(name))
							{
								_selectedBioBaseCompounds.Add(name);
							}
						}
					}
				}
			}
			foreach (KeyValuePair<string, Compound> item in dictionary2)
			{
				_availableBioBaseCompounds.Add(item.Value.Name);
			}
		}

		private void ExecuteOKCommand(object arg)
		{
			IOrderedEnumerable<string> orderedEnumerable = from x in _selectedBioBaseCompounds.Except(_bioBaseCompounds)
				orderby x
				select x;
			if (orderedEnumerable == null || orderedEnumerable.Count() <= 0 || !(arg is BiomassLookup biomassLookup))
			{
				return;
			}
			int num = _compoundsTotalCount;
			foreach (string item in orderedEnumerable)
			{
				num++;
				SmgeHelper.SMinsertcompM("BIOFEED", item, num);
			}
			biomassLookup.DialogResult = true;
			biomassLookup.Close();
		}

		private bool CanExecuteOKCommand(object arg)
		{
			IEnumerable<string> enumerable = _selectedBioBaseCompounds.Except(_bioBaseCompounds);
			if (enumerable != null)
			{
				return enumerable.Count() > 0;
			}
			return false;
		}

		private void ExecuteCancelCommand(object arg)
		{
			(arg as BiomassLookup)?.Close();
		}
	}
	public class Compound
	{
		public string CASRN { get; set; }

		public string Name { get; set; }

		public string Alias { get; set; }

		public string BioPos { get; set; }

		public CompoundClasses CompoundClass { get; set; }
	}
	public enum CompoundClasses : short
	{
		BioComponents,
		Solids
	}
	public class HeaderDisplayConverter : IValueConverter
	{
		public string HeaderFormat { get; set; }

		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is int num)
			{
				return string.Format(HeaderFormat, num);
			}
			return string.Empty;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class DatabanksTabViewModel : MMViewModel
	{
		public static readonly CxvPropertyDeclaration lstpPureDataBanks_filesymnam_Property = CxvPropertyDeclaration.Register("lstpPureDataBanks_filesymnam", typeof(DatabanksTabViewModel), new CxvVariableProperty
		{
			ExposeAs = CxvVariableTypeCode.List,
			DataPath = "Top.appModelV8.Pure Databanks.Input.FILE_SYM_NAM",
			SkipSemanticOnReorder = true,
			RestoreDefaultOnClear = true
		});

		public object lstpPureDataBanks_filesymnam => GetValue(lstpPureDataBanks_filesymnam_Property);
	}
	public class DatabanksTab : MMTabPage, IComponentConnector
	{
		internal MMListPicker lstpPureDataBanks;

		private bool _contentLoaded;

		public DatabanksTab(IUnityContainer container)
		{
			InitializeComponent();
			base.ViewModelType = typeof(DatabanksTabViewModel);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/databankstab.xaml", UriKind.Relative);
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
				lstpPureDataBanks = (MMListPicker)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class ElectrolyteForm10 : WizardControlItem, IComponentConnector
	{
		internal GroupBox grpSimID;

		internal RadioButton radioTrueComponent;

		internal RadioButton radioApparentComponent;

		internal GroupBox grpElecPID;

		internal TextBox txtChemID;

		internal TextBox txtHenryID;

		internal Label lblStatus;

		private bool _contentLoaded;

		public ElectrolyteForm10()
		{
			InitializeComponent();
			base.Loaded += ElectrolyteForm10_Loaded;
		}

		private void ElectrolyteForm10_Loaded(object sender, RoutedEventArgs e)
		{
			grpSimID.IsEnabled = false;
			ElecWizardMain.g_approach = 1;
			if (ElecWizardMain.g_eform12nextcheck == 0)
			{
				radioApparentComponent.IsEnabled = true;
				radioTrueComponent.IsEnabled = true;
				grpSimID.IsEnabled = true;
				radioTrueComponent.IsChecked = true;
			}
			else if (ElecWizardMain.g_eform12nextcheck == 1)
			{
				radioApparentComponent.IsEnabled = false;
				radioTrueComponent.IsEnabled = false;
			}
			txtChemID.Text = ElecWizardMain.g_chem_record_name;
			txtHenryID.Text = ElecWizardMain.g_hcomp_record_name;
			base.CanBackward = true;
			base.CanForward = true;
			base.CanFinish = false;
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			base.Cursor = Cursors.Wait;
			if (ElecWizardMain.g_eform12nextcheck == 0)
			{
				ElecWizardMain.g_dbankmsgs |= 6;
				SmgeHelper.WriteElecWizardFlagM(1);
				SmgeHelper.WriteChemRecordM(ElecWizardMain.g_chem_record_name, ref ElecWizardMain.g_dbankmsgs, ElecWizardMain.g_approach, 1, ElecWizardMain.g_refStateFlag);
				if (!string.IsNullOrEmpty(SmgeHelper.HasHcompCompsM(0)))
				{
					SmgeHelper.WriteHcompRecordM(ElecWizardMain.g_hcomp_record_name, 1);
					ElecWizardMain.g_dbankmsgs |= 8;
				}
				if (!string.IsNullOrEmpty(ElecWizardMain.g_optSet))
				{
					SmgeHelper.SetGlobalOpsetM(ElecWizardMain.g_optSet, "");
				}
				else
				{
					SmgeHelper.SetGlobalOpsetM("ELECNRTL", "");
				}
			}
			else if (ElecWizardMain.g_eform12nextcheck == 1)
			{
				SmgeHelper.WriteChemRecordM(ElecWizardMain.g_chem_record_name, ref ElecWizardMain.g_dbankmsgs, 0, 0, ElecWizardMain.g_refStateFlag);
				if (!string.IsNullOrEmpty(SmgeHelper.HasHcompCompsM(0)))
				{
					SmgeHelper.WriteHcompRecordM(ElecWizardMain.g_hcomp_record_name, 0);
				}
			}
			base.Cursor = Cursors.Arrow;
			return base.OnForward(targetItem);
		}

		protected override bool OnFinished()
		{
			return base.OnFinished();
		}

		private void radioTrueComponent_Checked(object sender, RoutedEventArgs e)
		{
			ElecWizardMain.g_approach = 1;
		}

		private void radioApparentComponent_Checked(object sender, RoutedEventArgs e)
		{
			ElecWizardMain.g_approach = 0;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/electrolyteform10.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				grpSimID = (GroupBox)target;
				break;
			case 2:
				radioTrueComponent = (RadioButton)target;
				radioTrueComponent.Checked += radioTrueComponent_Checked;
				break;
			case 3:
				radioApparentComponent = (RadioButton)target;
				radioApparentComponent.Checked += radioApparentComponent_Checked;
				break;
			case 4:
				grpElecPID = (GroupBox)target;
				break;
			case 5:
				txtChemID = (TextBox)target;
				break;
			case 6:
				txtHenryID = (TextBox)target;
				break;
			case 7:
				lblStatus = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ElectrolyteForm11 : WizardControlItem, IComponentConnector
	{
		private int _setbasecomps;

		private int _totalbcomp;

		private bool _hasLoaded;

		internal ListBox lstAvailableComp;

		internal Button btnMove;

		internal Button btnMoveAll;

		internal Button btnRemove;

		internal Button btnClearAll;

		internal ListBox lstSelectedComp;

		internal RadioButton radioHydroniumIon;

		internal RadioButton radioHydrogenIon;

		internal CheckBox chkSaltFormation;

		internal CheckBox chkWaterDissociation;

		internal CheckBox chkIceFormation;

		private bool _contentLoaded;

		public ElectrolyteForm11()
		{
			InitializeComponent();
			base.Loaded += ElectrolyteForm11_Loaded;
		}

		private void ElectrolyteForm11_Loaded(object sender, RoutedEventArgs e)
		{
			ElecWizardMain.g_reactions = 0;
			SmgeHelper.SetGenNewCompsM(1);
			if (SmgeHelper.GetBaseCompsM() == 0)
			{
				return;
			}
			if (SmgeHelper.CheckWaterM() == 0 && ElecWizardMain.g_refStateFlag == 0)
			{
				MMMessageBox.Show(WpfFindComponentResources.WaterMessage, WpfFindComponentResources.WaterRequired);
				return;
			}
			_setbasecomps = 1;
			if (!_hasLoaded)
			{
				btnClearAll.IsEnabled = false;
				btnRemove.IsEnabled = false;
				IList<string> avialbleComps;
				int totalbcomp = SmgeHelper.CollectBaseAvailComponentsM(out avialbleComps);
				lstAvailableComp.Items.Clear();
				foreach (string item in avialbleComps)
				{
					lstAvailableComp.Items.Add(item);
				}
				lstSelectedComp.Items.Clear();
				_totalbcomp = totalbcomp;
				_hasLoaded = true;
				radioHydroniumIon.IsChecked = true;
				chkSaltFormation.IsChecked = true;
			}
			else
			{
				SmgeHelper.SetAllSpecsSelected(1, 0);
				int count = lstSelectedComp.Items.Count;
				for (int i = 0; i < count; i++)
				{
					SmgeHelper.SetSpecsSelected(lstSelectedComp.Items[i].ToString(), 1, 1);
				}
				UpdateButtonsStatus();
			}
			radioHydroniumIon.IsEnabled = true;
			radioHydrogenIon.IsEnabled = true;
			chkWaterDissociation.IsEnabled = true;
			chkIceFormation.IsEnabled = true;
			if (ElecWizardMain.g_refStateFlag == 0)
			{
				MoveWaterComponent();
			}
			lstAvailableComp.SelectedIndex = 0;
			Update();
		}

		private void MoveWaterComponent()
		{
			if (_setbasecomps != 0 && !CheckBufFromSelComponents("H2O"))
			{
				lstSelectedComp.Items.Add("H2O");
				int count = lstAvailableComp.Items.Count;
				int i;
				for (i = 0; i < count && !(lstAvailableComp.Items[i].ToString() == "H2O"); i++)
				{
				}
				if (i < count)
				{
					lstAvailableComp.Items.RemoveAt(i);
				}
				count = lstSelectedComp.Items.Count;
				if (count > 0)
				{
					base.CanForward = true;
				}
				SmgeHelper.SetSpecsSelected("H2O", 1, 1);
				Update();
			}
		}

		private void Update()
		{
			SmgeHelper.ClearAllocatedRxnSpaceM();
			if (radioHydroniumIon.IsChecked.Value)
			{
				SmgeHelper.SetHydroniumIsH_M(0);
			}
			else
			{
				SmgeHelper.SetHydroniumIsH_M(1);
			}
			if (chkSaltFormation.IsChecked.Value)
			{
				SmgeHelper.SetIncludeSaltM(1);
			}
			else
			{
				SmgeHelper.SetIncludeSaltM(0);
			}
			if (chkWaterDissociation.IsChecked.Value)
			{
				SmgeHelper.SetWaterDissocM(1);
			}
			else
			{
				SmgeHelper.SetWaterDissocM(0);
			}
			if (chkIceFormation.IsChecked.Value)
			{
				SmgeHelper.SetIceFormationM(1);
			}
			else
			{
				SmgeHelper.SetIceFormationM(0);
			}
			SmgeHelper.RxnInitM();
			SmgeHelper.GenRxnsAfreshM();
			ElecWizardMain.g_reactions = ((SmgeHelper.GetNumRxnsPossibleM() != 0) ? 1 : 0);
			base.CanBackward = true;
		}

		private void btnMove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || lstAvailableComp.SelectedItems.Count < 1)
			{
				return;
			}
			base.CanForward = true;
			List<string> list = new List<string>();
			foreach (string selectedItem in lstAvailableComp.SelectedItems)
			{
				list.Add(selectedItem);
				if (!FindSelectedStrings(selectedItem))
				{
					lstSelectedComp.Items.Add(selectedItem);
					lstSelectedComp.SelectedItem = selectedItem;
					SmgeHelper.SetSpecsSelected(selectedItem, 1, 1);
				}
			}
			int num = 0;
			foreach (string item in list)
			{
				num = lstAvailableComp.Items.IndexOf(item);
				lstAvailableComp.Items.Remove(item);
			}
			int count = lstAvailableComp.Items.Count;
			if (num < count)
			{
				lstAvailableComp.SelectedIndex = num;
			}
			else if (count > 0)
			{
				lstAvailableComp.SelectedIndex = count - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private void UpdateButtonsStatus()
		{
			if (lstAvailableComp.Items.Count > 0)
			{
				btnMove.IsEnabled = true;
				btnMoveAll.IsEnabled = true;
			}
			else
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
			}
			if (lstSelectedComp.Items.Count > 0)
			{
				btnRemove.IsEnabled = true;
				btnClearAll.IsEnabled = true;
			}
			else
			{
				btnRemove.IsEnabled = false;
				btnClearAll.IsEnabled = false;
			}
		}

		private bool FindSelectedStrings(string str)
		{
			foreach (string item in (IEnumerable)lstSelectedComp.Items)
			{
				if (item.Equals(str))
				{
					return true;
				}
			}
			return false;
		}

		private void btnMoveAll_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0)
			{
				return;
			}
			if (lstAvailableComp.Items.Count <= 0)
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
				return;
			}
			base.CanForward = true;
			foreach (string item in (IEnumerable)lstAvailableComp.Items)
			{
				if (!CheckBufFromSelComponents(item))
				{
					lstSelectedComp.Items.Add(item);
					SmgeHelper.SetSpecsSelected(item, 1, 1);
				}
			}
			lstAvailableComp.Items.Clear();
			UpdateButtonsStatus();
			lstSelectedComp.SelectedIndex = 0;
			lstSelectedComp.Focus();
			Update();
		}

		private bool CheckBufFromSelComponents(string str)
		{
			return lstSelectedComp.Items.Contains(str);
		}

		private bool CheckBufFromAveComponents(string str)
		{
			return lstAvailableComp.Items.Contains(str);
		}

		protected override void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			base.OnEnter(previousItem, positiveDirection);
		}

		private void btnRemove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || lstSelectedComp.Items.Count <= 0)
			{
				return;
			}
			int count = lstSelectedComp.SelectedItems.Count;
			List<string> list = new List<string>();
			foreach (string selectedItem in lstSelectedComp.SelectedItems)
			{
				if (selectedItem.Equals("H2O") && count == 1 && ElecWizardMain.g_refStateFlag == 0)
				{
					MMMessageBox.Show(WpfFindComponentResources.H2O_Message, WpfFindComponentResources.ElectrolyteWizard);
					continue;
				}
				list.Add(selectedItem);
				if (!CheckBufFromAveComponents(selectedItem))
				{
					lstAvailableComp.Items.Add(selectedItem);
					lstAvailableComp.SelectedItem = selectedItem;
				}
				SmgeHelper.SetSpecsSelected(selectedItem, 1, 0);
			}
			int num = 0;
			foreach (string item in list)
			{
				num = lstSelectedComp.Items.IndexOf(item);
				lstSelectedComp.Items.Remove(item);
			}
			int count2 = lstSelectedComp.Items.Count;
			if (num < count2)
			{
				lstSelectedComp.SelectedIndex = num;
			}
			else if (count2 > 0)
			{
				lstSelectedComp.SelectedIndex = count2 - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private void btnClearAll_Click(object sender, RoutedEventArgs e)
		{
			foreach (string item in (IEnumerable)lstSelectedComp.Items)
			{
				lstAvailableComp.Items.Add(item);
			}
			lstSelectedComp.Items.Clear();
			SmgeHelper.SetAllSpecsSelected(1, 0);
			btnClearAll.IsEnabled = false;
			if (ElecWizardMain.g_refStateFlag == 0)
			{
				MoveWaterComponent();
			}
			UpdateButtonsStatus();
			Update();
			lstAvailableComp.Focus();
			if (lstAvailableComp.Items.Count > 0)
			{
				lstAvailableComp.SelectedIndex = 0;
			}
		}

		private void radioHydroniumIon_Click(object sender, RoutedEventArgs e)
		{
			Update();
		}

		private void radioHydrogenIon_Click(object sender, RoutedEventArgs e)
		{
			Update();
		}

		private void chkSaltFormation_Click(object sender, RoutedEventArgs e)
		{
			Update();
		}

		private void chkWaterDissociation_Click(object sender, RoutedEventArgs e)
		{
			Update();
		}

		private void chkIceFormation_Click(object sender, RoutedEventArgs e)
		{
			Update();
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			if (ElecWizardMain.g_reactions == 0)
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.NoReactionsAvailable, WpfFindComponentResources.No_Reactions_Available_Title);
				return false;
			}
			return base.OnForward(targetItem);
		}

		private void lstAvailableComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnMove_Click(sender, e);
					break;
				}
			}
		}

		private void lstSelectedComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnRemove_Click(sender, e);
					break;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/electrolyteform11.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lstAvailableComp = (ListBox)target;
				lstAvailableComp.MouseDoubleClick += lstAvailableComp_MouseDoubleClick;
				break;
			case 2:
				btnMove = (Button)target;
				btnMove.Click += btnMove_Click;
				break;
			case 3:
				btnMoveAll = (Button)target;
				btnMoveAll.Click += btnMoveAll_Click;
				break;
			case 4:
				btnRemove = (Button)target;
				btnRemove.Click += btnRemove_Click;
				break;
			case 5:
				btnClearAll = (Button)target;
				btnClearAll.Click += btnClearAll_Click;
				break;
			case 6:
				lstSelectedComp = (ListBox)target;
				lstSelectedComp.MouseDoubleClick += lstSelectedComp_MouseDoubleClick;
				break;
			case 7:
				radioHydroniumIon = (RadioButton)target;
				radioHydroniumIon.Click += radioHydroniumIon_Click;
				break;
			case 8:
				radioHydrogenIon = (RadioButton)target;
				radioHydrogenIon.Click += radioHydrogenIon_Click;
				break;
			case 9:
				chkSaltFormation = (CheckBox)target;
				chkSaltFormation.Click += chkSaltFormation_Click;
				break;
			case 10:
				chkWaterDissociation = (CheckBox)target;
				chkWaterDissociation.Click += chkWaterDissociation_Click;
				break;
			case 11:
				chkIceFormation = (CheckBox)target;
				chkIceFormation.Click += chkIceFormation_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ElectrolyteForm12 : WizardControlItem, INotifyPropertyChanged, IComponentConnector
	{
		private int _boxVar;

		private int _checkboxgvar;

		private bool bInit;

		private bool _isGenHenryChemChecked;

		internal ListBox lstAqueousSpecies;

		internal ListBox lstSalts;

		internal ListBox lstReactions;

		internal Button btnRemove;

		internal RadioButton radioGenSpecRxns;

		internal ComboBox cboOptSet;

		internal RadioButton radioGenChemHenry;

		internal CheckBox chkGenHenryChem;

		internal Label lblStatus;

		private bool _contentLoaded;

		public bool IsGenHenryChemChecked
		{
			get
			{
				return _isGenHenryChemChecked;
			}
			set
			{
				_isGenHenryChemChecked = value;
				if (!value)
				{
					_checkboxgvar = 0;
					base.CanForward = false;
					base.CanFinish = true;
					base.CanBackward = true;
					lblStatus.Content = WpfFindComponentResources.FinishMessage;
				}
				else
				{
					_checkboxgvar = 1;
					base.CanForward = true;
					base.CanFinish = false;
					base.CanBackward = true;
					lblStatus.Content = WpfFindComponentResources.NextMessage;
				}
				OnPropertyChanged("IsGenHenryChemChecked");
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public ElectrolyteForm12()
		{
			InitializeComponent();
			base.Loaded += ElectrolyteForm12_Loaded;
		}

		private void ElectrolyteForm12_Loaded(object sender, RoutedEventArgs e)
		{
			bInit = true;
			base.DataContext = this;
			base.CanBackward = true;
			radioGenSpecRxns.IsChecked = true;
			radioGenChemHenry.IsChecked = false;
			lblStatus.Content = WpfFindComponentResources.NextMessage;
			CollectAll();
			if (lstAqueousSpecies.Items.Count > 0)
			{
				lstAqueousSpecies.SelectedIndex = 0;
			}
			int selectedIndex = cboOptSet.SelectedIndex;
			cboOptSet.Items.Clear();
			if (ElecWizardMain.g_refStateFlag != 0)
			{
				cboOptSet.Items.Add("ENRTL-SR");
			}
			else
			{
				cboOptSet.Items.Add("ELECNRTL");
				cboOptSet.Items.Add("ENRTL-RK");
			}
			if (selectedIndex > -1 && selectedIndex < cboOptSet.Items.Count)
			{
				cboOptSet.SelectedIndex = selectedIndex;
			}
			else
			{
				cboOptSet.SelectedIndex = 0;
			}
			ElecWizardMain.g_optSet = cboOptSet.SelectedItem.ToString();
			bInit = false;
		}

		private void CollectAll()
		{
			ResetAllListBoxes();
			foreach (string item in SmgeHelper.CollectAqueousSpeciesM())
			{
				lstAqueousSpecies.Items.Add(item);
			}
			foreach (string item2 in SmgeHelper.CollectSaltsM())
			{
				lstSalts.Items.Add(item2);
			}
			foreach (string item3 in SmgeHelper.CollectReactionsM())
			{
				lstReactions.Items.Add(item3);
			}
			if (lstAqueousSpecies.Items.Count == 0 && lstSalts.Items.Count == 0 && lstReactions.Items.Count == 0)
			{
				btnRemove.IsEnabled = false;
				base.CanForward = false;
				base.CanBackward = true;
				radioGenSpecRxns.IsEnabled = false;
				radioGenChemHenry.IsEnabled = false;
				lblStatus.Content = WpfFindComponentResources.BackMessage;
			}
			else
			{
				btnRemove.IsEnabled = true;
				base.CanForward = true;
				radioGenSpecRxns.IsEnabled = true;
				radioGenChemHenry.IsEnabled = true;
			}
		}

		private void btnRemove_Click(object sender, RoutedEventArgs e)
		{
			if (_boxVar == 1)
			{
				if (lstAqueousSpecies.Items.Count <= 0 || lstAqueousSpecies.SelectedItems.Count <= 0)
				{
					return;
				}
				foreach (string selectedItem in lstAqueousSpecies.SelectedItems)
				{
					SmgeHelper.SetSpecsSelected(selectedItem, 2, 1);
				}
				ResetAllListBoxes();
				SmgeHelper.ExcludeAqM();
				CollectAll();
			}
			else if (_boxVar == 2)
			{
				if (lstSalts.Items.Count <= 0 || lstSalts.SelectedItems.Count <= 0)
				{
					return;
				}
				foreach (string selectedItem2 in lstSalts.SelectedItems)
				{
					SmgeHelper.SetSpecsSelected(selectedItem2, 3, 1);
				}
				ResetAllListBoxes();
				SmgeHelper.ExcludeSaltM();
				CollectAll();
			}
			else
			{
				if (_boxVar != 3 || lstReactions.Items.Count <= 0 || lstReactions.SelectedItems.Count <= 0)
				{
					return;
				}
				foreach (string selectedItem3 in lstReactions.SelectedItems)
				{
					SmgeHelper.SetRxnSelected(selectedItem3, 1);
				}
				ResetAllListBoxes();
				SmgeHelper.RemRxnsM();
				CollectAll();
			}
		}

		private void ResetAllListBoxes()
		{
			lstAqueousSpecies.Items.Clear();
			lstSalts.Items.Clear();
			lstReactions.Items.Clear();
		}

		private void lstAqueousSpecies_GotFocus(object sender, RoutedEventArgs e)
		{
			if (lstAqueousSpecies.Items.Count > 0)
			{
				_boxVar = 1;
				lstSalts.SelectedIndex = -1;
				lstReactions.SelectedIndex = -1;
			}
		}

		private void lstSalts_GotFocus(object sender, RoutedEventArgs e)
		{
			if (lstSalts.Items.Count > 0)
			{
				_boxVar = 2;
				lstAqueousSpecies.SelectedIndex = -1;
				lstReactions.SelectedIndex = -1;
			}
		}

		private void lstReactions_GotFocus(object sender, RoutedEventArgs e)
		{
			if (lstReactions.Items.Count > 0)
			{
				_boxVar = 3;
				lstAqueousSpecies.SelectedIndex = -1;
				lstSalts.SelectedIndex = -1;
			}
		}

		private void radioGenSpecRxns_Checked(object sender, RoutedEventArgs e)
		{
			IsGenHenryChemChecked = false;
			_checkboxgvar = 0;
			base.CanForward = true;
			base.CanBackward = true;
			base.CanFinish = false;
			lblStatus.Content = WpfFindComponentResources.NextMessage;
			ElecWizardMain.g_eform12nextcheck = 0;
		}

		private void radioGenChemHenry_Checked(object sender, RoutedEventArgs e)
		{
			IsGenHenryChemChecked = true;
			_checkboxgvar = 1;
			base.CanForward = true;
			base.CanFinish = false;
			base.CanBackward = true;
			lblStatus.Content = WpfFindComponentResources.NextMessage;
			ElecWizardMain.g_eform12nextcheck = 1;
		}

		private void cboOptSet_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (!bInit && cboOptSet.SelectedItem != null)
			{
				ElecWizardMain.g_optSet = cboOptSet.SelectedItem.ToString();
			}
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			ElecWizardMain.g_chem_record_name = "";
			ElecWizardMain.g_hcomp_record_name = "";
			ElecWizardMain.g_dbankmsgs = 0;
			ElecWizardMain.g_setglobal = 0;
			if (ElecWizardMain.g_eform12nextcheck == 0 && !ElecWizardMain.GenerateSpeciesReactions())
			{
				return false;
			}
			if (ElecWizardMain.g_eform12nextcheck == 1 && !ElecWizardMain.GenerateChemHenrySpecs())
			{
				return false;
			}
			return base.OnForward(targetItem);
		}

		protected override bool OnBackward(WizardControlItem targetItem)
		{
			ElecWizardMain.ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			return base.OnBackward(targetItem);
		}

		protected override bool OnFinished()
		{
			ElecWizardMain.g_dbankmsgs = 0;
			ElecWizardMain.g_setglobal = 0;
			base.Cursor = Cursors.Wait;
			if (ElecWizardMain.g_eform12nextcheck == 1 && !IsGenHenryChemChecked)
			{
				SmgeHelper.WriteNewBaseCompsM(ref ElecWizardMain.g_dbankmsgs, 0);
			}
			base.Cursor = Cursors.Arrow;
			ResetAllListBoxes();
			return base.OnFinished();
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/electrolyteform12.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lstAqueousSpecies = (ListBox)target;
				lstAqueousSpecies.GotFocus += lstAqueousSpecies_GotFocus;
				break;
			case 2:
				lstSalts = (ListBox)target;
				lstSalts.GotFocus += lstSalts_GotFocus;
				break;
			case 3:
				lstReactions = (ListBox)target;
				lstReactions.GotFocus += lstReactions_GotFocus;
				break;
			case 4:
				btnRemove = (Button)target;
				btnRemove.Click += btnRemove_Click;
				break;
			case 5:
				radioGenSpecRxns = (RadioButton)target;
				radioGenSpecRxns.Checked += radioGenSpecRxns_Checked;
				break;
			case 6:
				cboOptSet = (ComboBox)target;
				cboOptSet.SelectionChanged += cboOptSet_SelectionChanged;
				break;
			case 7:
				radioGenChemHenry = (RadioButton)target;
				radioGenChemHenry.Checked += radioGenChemHenry_Checked;
				break;
			case 8:
				chkGenHenryChem = (CheckBox)target;
				break;
			case 9:
				lblStatus = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ElectrolyteForm7 : WizardControlItem, IComponentConnector
	{
		private bool _hasLoaded;

		internal GroupBox grpDBank;

		internal Label lblSelDatabase;

		internal ComboBox cboDBSelect;

		internal Label lblRefState;

		internal ComboBox cboRefStateSelect;

		internal TextBlock LinkTip;

		private bool _contentLoaded;

		public ElectrolyteForm7()
		{
			InitializeComponent();
			base.Loaded += ElectrolyteForm7_Loaded;
		}

		private void ElectrolyteForm7_Loaded(object sender, RoutedEventArgs e)
		{
			int num = SmgeHelper.GetTotalNumberOfReacDatabanksM();
			string[] reacBankArr = new string[num];
			if (SmgeHelper.GetReacDatabanksListM(ref reacBankArr) == 0)
			{
				num = 0;
			}
			if (reacBankArr.Length != 0)
			{
				Array.Sort(reacBankArr);
				Array.Reverse(reacBankArr);
			}
			cboRefStateSelect.IsEnabled = true;
			if (!_hasLoaded)
			{
				cboRefStateSelect.ItemsSource = new string[2]
				{
					WpfFindComponentResources.Form7_Unsymmetric,
					WpfFindComponentResources.Form7_Symmetric
				};
				cboRefStateSelect.SelectedIndex = 0;
				_hasLoaded = true;
			}
			if (ElecWizardMain.g_localUsedAped != 0 && num != 0)
			{
				cboDBSelect.IsEnabled = true;
				lblSelDatabase.Content = WpfFindComponentResources.SeldatabaseText1;
				grpDBank.Header = WpfFindComponentResources.DBankCaption1;
				cboDBSelect.ItemsSource = reacBankArr;
				cboDBSelect.SelectedIndex = 0;
				SmgeHelper.GetReacDatabankM(reacBankArr[0], 1);
			}
			else
			{
				cboDBSelect.Visibility = Visibility.Hidden;
				lblSelDatabase.Content = WpfFindComponentResources.SeldatabaseText2;
				grpDBank.Header = WpfFindComponentResources.DBankCaption2;
			}
			base.CanForward = true;
			base.CanCancel = true;
		}

		private void cboDBSelect_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			SmgeHelper.GetReacDatabankM(cboDBSelect.SelectedItem.ToString(), 1);
		}

		private void cboRefStateSelect_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			int g_refStateFlag = 0;
			if (cboRefStateSelect.SelectedIndex == 1)
			{
				g_refStateFlag = 1;
			}
			ElecWizardMain.g_refStateFlag = g_refStateFlag;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/electrolyteform7.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				grpDBank = (GroupBox)target;
				break;
			case 2:
				lblSelDatabase = (Label)target;
				break;
			case 3:
				cboDBSelect = (ComboBox)target;
				cboDBSelect.SelectionChanged += cboDBSelect_SelectionChanged;
				break;
			case 4:
				lblRefState = (Label)target;
				break;
			case 5:
				cboRefStateSelect = (ComboBox)target;
				cboRefStateSelect.SelectionChanged += cboRefStateSelect_SelectionChanged;
				break;
			case 6:
				LinkTip = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ElectrolyteForm6 : WizardControlItem, IComponentConnector
	{
		internal GroupBox grpProperties;

		internal Label lblPM;

		internal TextBox txtBaseOption;

		internal Label lblSM;

		internal TextBox txtSimApproach;

		internal Label lblCID;

		internal TextBox txtChemID;

		internal Label lblHID;

		internal TextBox txtHenryID;

		internal TextBlock lblFinishElec;

		internal Button btnReviewHenryList;

		internal Button btnModifyAddRxns;

		internal Label lblStatus;

		private bool _contentLoaded;

		public ElectrolyteForm6()
		{
			InitializeComponent();
			base.Loaded += ElectrolyteForm6_Loaded;
		}

		private void ElectrolyteForm6_Loaded(object sender, RoutedEventArgs e)
		{
			List<string> list = new List<string>();
			list.Add(WpfFindComponentResources.ElecHelp0 + Environment.NewLine + Environment.NewLine);
			list.Add("");
			list.Add("");
			list.Add("");
			list.Add(WpfFindComponentResources.ElecHelp4 + Environment.NewLine + Environment.NewLine);
			list.Add(WpfFindComponentResources.ElecHelp5 + Environment.NewLine + Environment.NewLine);
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < 6; i++)
			{
				if ((ElecWizardMain.g_dbankmsgs & (1 << i)) != 0)
				{
					stringBuilder.Append(list[i]);
				}
			}
			lblFinishElec.Text = stringBuilder.ToString();
			if (ElecWizardMain.g_eform12nextcheck == 0)
			{
				grpProperties.IsEnabled = true;
				if (!string.IsNullOrEmpty(ElecWizardMain.g_optSet))
				{
					txtBaseOption.Text = ElecWizardMain.g_optSet;
				}
				else
				{
					txtBaseOption.Text = "ELECNRTL";
				}
				if (ElecWizardMain.g_approach == 0)
				{
					txtSimApproach.Text = WpfFindComponentResources.ApparentComponent;
				}
				else if (ElecWizardMain.g_approach == 1)
				{
					txtSimApproach.Text = WpfFindComponentResources.TrueComponent;
				}
				txtChemID.Text = ElecWizardMain.g_chem_record_name;
				txtHenryID.Text = ElecWizardMain.g_hcomp_record_name;
			}
			else if (ElecWizardMain.g_eform12nextcheck == 1)
			{
				txtBaseOption.Text = "";
				txtSimApproach.Text = "";
				txtChemID.Text = "";
				txtHenryID.Text = "";
				grpProperties.IsEnabled = false;
			}
			else if (ElecWizardMain.g_eform12nextcheck == 2)
			{
				txtBaseOption.Text = "";
				txtSimApproach.Text = "";
				txtChemID.Text = "";
				txtHenryID.Text = "";
				grpProperties.IsEnabled = false;
			}
			base.CanFinish = true;
			base.CanBackward = false;
			base.CanCancel = false;
		}

		private void btnReviewHenryList_Click(object sender, RoutedEventArgs e)
		{
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMHenryComps.MMHenryComps_Input_RewHen"),
				DialogTitle = string.Format(WpfFindComponentResources.Title_ReviewHenry, ElecWizardMain.g_hcomp_record_name),
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Components.Henry-Comps." + ElecWizardMain.g_hcomp_record_name);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
		}

		private void btnModifyAddRxns_Click(object sender, RoutedEventArgs e)
		{
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMChemistry.MMChemistry_InputC"),
				DialogTitle = string.Format(WpfFindComponentResources.Title_ReviewChemistry, ElecWizardMain.g_chem_record_name),
				PreferredHeight = 510,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			string text = "";
			text = ((!MMVersionHelper.MVIsAspenProperties()) ? ("Top.appModelV8.Reactions.Chemistry." + ElecWizardMain.g_chem_record_name) : ("Top.appModelV8.Chemistry." + ElecWizardMain.g_chem_record_name));
			e2.FormParameters.Add("main", text);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
		}

		protected override bool OnFinished()
		{
			ElecWizardMain.g_dbankmsgs = 0;
			ElecWizardMain.g_setglobal = 0;
			ElecWizardMain.g_approach = 1;
			ElecWizardMain.g_eform12nextcheck = 0;
			ElecWizardMain.g_chem_record_name = "";
			ElecWizardMain.g_hcomp_record_name = "";
			return base.OnFinished();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/electrolyteform6.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				grpProperties = (GroupBox)target;
				break;
			case 2:
				lblPM = (Label)target;
				break;
			case 3:
				txtBaseOption = (TextBox)target;
				break;
			case 4:
				lblSM = (Label)target;
				break;
			case 5:
				txtSimApproach = (TextBox)target;
				break;
			case 6:
				lblCID = (Label)target;
				break;
			case 7:
				txtChemID = (TextBox)target;
				break;
			case 8:
				lblHID = (Label)target;
				break;
			case 9:
				txtHenryID = (TextBox)target;
				break;
			case 10:
				lblFinishElec = (TextBlock)target;
				break;
			case 11:
				btnReviewHenryList = (Button)target;
				btnReviewHenryList.Click += btnReviewHenryList_Click;
				break;
			case 12:
				btnModifyAddRxns = (Button)target;
				btnModifyAddRxns.Click += btnModifyAddRxns_Click;
				break;
			case 13:
				lblStatus = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ElecWizardMain : Window, IComponentConnector
	{
		public static int g_refStateFlag;

		public static int g_localUsedAped;

		public static int g_reactions;

		public static string g_optSet;

		public static string g_chem_record_name;

		public static string g_hcomp_record_name;

		public static int g_dbankmsgs;

		public static int g_setglobal;

		public static int g_approach;

		public static int g_eform12nextcheck;

		private ElectrolyteForm7 welcomePage = new ElectrolyteForm7();

		private ElectrolyteForm11 stepPage1 = new ElectrolyteForm11();

		private ElectrolyteForm12 stepPage2 = new ElectrolyteForm12();

		private ElectrolyteForm10 stepPage3 = new ElectrolyteForm10();

		private ElectrolyteForm6 stepPage4 = new ElectrolyteForm6();

		internal WizardControl theWizard;

		internal Button buttonCancel;

		private bool _contentLoaded;

		public static bool GenerateSpeciesReactions()
		{
			string title = MMVersionHelper.MVGetI18nProductNameM();
			g_chem_record_name = "GLOBAL";
			if (SmgeHelper.HasChemRecordM(g_chem_record_name) != 0)
			{
				do
				{
					switch (MMMessageBox.Show(string.Format(WpfFindComponentResources.ChemistryExists, g_chem_record_name), WpfFindComponentResources.ChemistryExistsTitle, MMMessageBoxButton.YesNoCancel, MMMessageBoxImage.Question))
					{
					case MMMessageBoxResult.Cancel:
						return false;
					case MMMessageBoxResult.No:
					{
						OneIdDialog oneIdDialog = new OneIdDialog(FindComponentModule.Container, WpfFindComponentResources.EnterChemID, "", null, OneIdDialog.maskType.IS_ID, title);
						bool? flag = oneIdDialog.ShowDialog();
						if (flag.HasValue && flag.Value)
						{
							g_chem_record_name = oneIdDialog.NewID;
							continue;
						}
						return false;
					}
					default:
						continue;
					case MMMessageBoxResult.Yes:
						break;
					}
					break;
				}
				while (SmgeHelper.HasChemRecordM(g_chem_record_name) != 0);
			}
			g_hcomp_record_name = "GLOBAL";
			if (!string.IsNullOrEmpty(SmgeHelper.HasHcompCompsM(0)) && SmgeHelper.HasHcompRecordM(g_hcomp_record_name) != 0)
			{
				do
				{
					switch (MMMessageBox.Show(string.Format(WpfFindComponentResources.HenryCompExists, g_hcomp_record_name), WpfFindComponentResources.HenryCompExistsTitle, MMMessageBoxButton.YesNoCancel, MMMessageBoxImage.Question))
					{
					case MMMessageBoxResult.Cancel:
						return false;
					case MMMessageBoxResult.No:
					{
						OneIdDialog oneIdDialog2 = new OneIdDialog(FindComponentModule.Container, WpfFindComponentResources.EnterHenryID, "", null, OneIdDialog.maskType.IS_ID, title);
						bool? flag2 = oneIdDialog2.ShowDialog();
						if (flag2.HasValue && flag2.Value)
						{
							g_hcomp_record_name = oneIdDialog2.NewID;
							continue;
						}
						return false;
					}
					default:
						continue;
					case MMMessageBoxResult.Yes:
						break;
					}
					break;
				}
				while (SmgeHelper.HasHcompRecordM(g_hcomp_record_name) != 0);
			}
			return true;
		}

		public static bool GenerateChemHenrySpecs()
		{
			string title = MMVersionHelper.MVGetI18nProductNameM();
			int num = 0;
			do
			{
				g_chem_record_name = "";
				OneIdDialog oneIdDialog = new OneIdDialog(FindComponentModule.Container, WpfFindComponentResources.EnterChemID, "", null, OneIdDialog.maskType.IS_ID, title);
				bool? flag = oneIdDialog.ShowDialog();
				if (flag.HasValue && flag.Value)
				{
					g_chem_record_name = oneIdDialog.NewID;
					if (string.IsNullOrEmpty(g_chem_record_name))
					{
						continue;
					}
					if (g_chem_record_name.Contains(' '))
					{
						MMMessageBox.Show(WpfFindComponentResources.BlankNotAllowedForChemistryID, WpfFindComponentResources.ElectrolyteWizard, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						continue;
					}
					num = 0;
					if (SmgeHelper.HasChemRecordM(g_chem_record_name) != 0)
					{
						switch (MMMessageBox.Show(string.Format(WpfFindComponentResources.ChemistryExists, g_hcomp_record_name), WpfFindComponentResources.ChemistryExistsTitle, MMMessageBoxButton.YesNoCancel, MMMessageBoxImage.Question))
						{
						case MMMessageBoxResult.Cancel:
							return false;
						case MMMessageBoxResult.No:
							num = 1;
							continue;
						default:
							continue;
						case MMMessageBoxResult.Yes:
							break;
						}
						break;
					}
					continue;
				}
				return false;
			}
			while (num != 0);
			num = 0;
			if (!string.IsNullOrEmpty(SmgeHelper.HasHcompCompsM(0)))
			{
				do
				{
					g_hcomp_record_name = "";
					OneIdDialog oneIdDialog2 = new OneIdDialog(FindComponentModule.Container, WpfFindComponentResources.EnterHenryID, "", null, OneIdDialog.maskType.IS_ID, title);
					bool? flag2 = oneIdDialog2.ShowDialog();
					if (flag2.HasValue && flag2.Value)
					{
						g_hcomp_record_name = oneIdDialog2.NewID;
						if (string.IsNullOrEmpty(g_hcomp_record_name))
						{
							continue;
						}
						if (g_hcomp_record_name.Contains(' '))
						{
							MMMessageBox.Show(WpfFindComponentResources.BlankNotAllowedForHenryID, WpfFindComponentResources.ElectrolyteWizard, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
							continue;
						}
						num = 0;
						if (SmgeHelper.HasHcompRecordM(g_hcomp_record_name) != 0)
						{
							switch (MMMessageBox.Show(string.Format(WpfFindComponentResources.HenryCompExists, g_hcomp_record_name), WpfFindComponentResources.HenryCompExistsTitle, MMMessageBoxButton.YesNoCancel, MMMessageBoxImage.Question))
							{
							case MMMessageBoxResult.Cancel:
								return false;
							case MMMessageBoxResult.No:
								num = 1;
								continue;
							default:
								continue;
							case MMMessageBoxResult.Yes:
								break;
							}
							break;
						}
						continue;
					}
					return false;
				}
				while (num != 0);
			}
			return true;
		}

		public static void ResetAll()
		{
			SmgeHelper.SetAllSpecsSelected(2, 0);
			SmgeHelper.SetAllSpecsSelected(3, 0);
			SmgeHelper.SetAllRxnsSelected(0);
		}

		public ElecWizardMain(int localUseAped)
		{
			g_localUsedAped = localUseAped;
			InitializeComponent();
			theWizard.Items.Add(welcomePage);
			theWizard.Items.Add(stepPage1);
			theWizard.Items.Add(stepPage2);
			theWizard.Items.Add(stepPage3);
			theWizard.Items.Add(stepPage4);
		}

		private void theWizard_Finished(object sender, RoutedEventArgs e)
		{
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/elecwizardmain.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				theWizard = (WizardControl)target;
				theWizard.Finished += theWizard_Finished;
				break;
			case 2:
				buttonCancel = (Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class FindComounds : Window, IComponentConnector
	{
		private string _root = "";

		private int _row;

		private string _searchText = "";

		private IUnityContainer _container;

		internal TabControl tabControl1;

		internal TabItem tabCompounds;

		internal TabItem tabDatabanks;

		internal TabItem tabPubChem;

		internal Button btnClose;

		private bool _contentLoaded;

		public bool? AddedSuccessfully { get; set; }

		public FindComounds(string root, int lRow, string searchText)
		{
			InitializeComponent();
			_root = root;
			_row = lRow;
			_searchText = searchText;
			base.Loaded += FindComounds_Loaded;
			base.Unloaded += FindComounds_Unloaded;
			base.Closing += FindComounds_Closing;
		}

		private void FindComounds_Loaded(object sender, RoutedEventArgs e)
		{
			int num;
			if (ScriptingSupport.Enabled)
			{
				num = (ScriptingSupport.ScriptRunning ? 1 : 0);
				if (num != 0)
				{
					int num2 = ScriptingSupport.DialogArgs.Find("SearchText");
					if (num2 >= 0)
					{
						_searchText = ScriptingSupport.DialogArgs[num2].Value as string;
					}
				}
			}
			else
			{
				num = 0;
			}
			tabCompounds.Content = new CompoundsTab(_root, _row, _searchText, this);
			_container = FindComponentModule.Container.CreateChildContainer();
			_container.RegisterInstance(FindComponentModule.Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>()), new ExternallyControlledLifetimeManager());
			_container.RegisterType(typeof(CxvSharedParameters), new ContainerControlledLifetimeManager());
			_container.RegisterType(typeof(CxsDataProvider), new ContainerControlledLifetimeManager());
			_container.RegisterType<IEventAggregator, RoutingEventAggregator>(new ContainerControlledLifetimeManager(), Array.Empty<InjectionMember>());
			_container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<BatchSetCompletedEvent>().Subscribe(OnBatchSetCompleted);
			tabDatabanks.Content = _container.Resolve<DatabanksTab>(Array.Empty<ResolverOverride>());
			tabPubChem.Content = new PubChemTab();
			if (num != 0)
			{
				base.Dispatcher.BeginInvoke((Action)delegate
				{
					AddedSuccessfully = true;
					Thread.Sleep(2000);
					Close();
				}, DispatcherPriority.Input);
			}
		}

		private void FindComounds_Unloaded(object sender, RoutedEventArgs e)
		{
			if (_container != null)
			{
				_container.Dispose();
				_container = null;
			}
		}

		private void FindComounds_Closing(object sender, CancelEventArgs e)
		{
			if (!(sender is FindComounds))
			{
				return;
			}
			try
			{
				(sender as FindComounds).DialogResult = AddedSuccessfully;
			}
			catch (Exception ex)
			{
				System.Windows.MessageBox.Show(ex.Message);
			}
		}

		private void btnClose_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void OnBatchSetCompleted(BatchSetCompletedEventArgs args)
		{
			if (_container != null)
			{
				_container.Resolve<CxsDataProvider>(Array.Empty<ResolverOverride>()).UpdateDataCache();
			}
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<BatchSetCompletedEvent>().Publish(args);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/findcomounds.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				tabControl1 = (TabControl)target;
				break;
			case 2:
				tabCompounds = (TabItem)target;
				break;
			case 3:
				tabDatabanks = (TabItem)target;
				break;
			case 4:
				tabPubChem = (TabItem)target;
				break;
			case 5:
				btnClose = (Button)target;
				btnClose.Click += btnClose_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[ComVisible(true)]
	[Guid("834E6AAE-84B8-4386-99A6-5D8D01FF4F39")]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IFindComponentDriver
	{
		int ShowUpwardComp1(int hideCancel);

		int ShowUpwardComp(int hideCancel, int bkpver);

		int ShowNewPureCompParam(out string param);

		void Show(string dialogName);

		int ShowDialog(string dialogName);

		int ShowUserDefinedWizard(int nSidrow);

		int ShowElecWizard(int localUseAped);

		int ShowSFEAssistant(int localUseAped);

		int ShowSFEAssistantMain(int localUseAped);

		int ShowSearchProperty(string szPropertyValue);

		int ShowSearchComponent(string root, int lRow, string searchText);

		void ShowUpgradeRetired(int localUseAped, out int bstate);
	}
	[ComVisible(true)]
	[Guid("09DC53C4-47A0-4AE0-9422-5675D014F182")]
	[ProgId("AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class FindComponentDriver : IFindComponentDriver
	{
		private const string PropertySetPath = "Top.appModelV8.Properties.Prop-Sets";

		private static bool? dbFoundForElectrolyteWizard;

		private static bool? dbFoundForSFEAssistant;

		private static string dbProvider = string.Empty;

		private static string dbMessage = string.Empty;

		private IList<Type> lstDialogs = new List<Type>();

		public int ShowUpwardComp1(int hideCancel)
		{
			UpwardComp1 upwardComp = new UpwardComp1(hideCancel);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					upwardComp.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					if (shellApplication.ActiveWindow != null)
					{
						upwardComp.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
				}
			}
			upwardComp.ShowDialog();
			if (upwardComp.DialogResult.HasValue && !upwardComp.DialogResult.Value && upwardComp.ResultCode == 0)
			{
				container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CancelOpenDocumentEvent>().Publish(new CancelOpenDocumentEventArgs
				{
					Source = "ShowUpwardComp1"
				});
			}
			return upwardComp.ResultCode;
		}

		public int ShowUpwardComp(int hideCancel, int bkpver)
		{
			UpwardComp upwardComp = new UpwardComp(hideCancel, bkpver);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					upwardComp.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					upwardComp.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			upwardComp.ShowDialog();
			if (upwardComp.DialogResult.HasValue && !upwardComp.DialogResult.Value && upwardComp.ResultCode == 0)
			{
				container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<CancelOpenDocumentEvent>().Publish(new CancelOpenDocumentEventArgs
				{
					Source = "ShowUpwardComp1"
				});
			}
			return upwardComp.ResultCode;
		}

		public int ShowNewPureCompParam(out string param)
		{
			NewPureCompParam newPureCompParam = new NewPureCompParam();
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					newPureCompParam.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					newPureCompParam.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag = newPureCompParam.ShowDialog();
			if (flag.HasValue && flag.Value)
			{
				param = (newPureCompParam.DataContext as NewPureCompParamViewModel).Param;
				return 1;
			}
			param = "";
			return 0;
		}

		public FindComponentDriver()
		{
			lstDialogs.Add(typeof(ReorderComp));
		}

		public void Show(string dialogName)
		{
			Window window = null;
			Type type = GetType(dialogName);
			if (type != null)
			{
				window = (Window)Activator.CreateInstance(type);
			}
			window?.Show();
		}

		public int ShowDialog(string dialogName)
		{
			Window window = null;
			Type type = GetType(dialogName);
			if (type != null)
			{
				window = (Window)Activator.CreateInstance(type);
			}
			if (window != null)
			{
				IUnityContainer container = FindComponentModule.Container;
				if (container != null)
				{
					IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
					if (shellApplication != null)
					{
						window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
						window.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
				}
				bool? flag = window.ShowDialog();
				if (flag.HasValue && flag.Value)
				{
					return 1;
				}
			}
			return 0;
		}

		public Type GetType(string name)
		{
			foreach (Type lstDialog in lstDialogs)
			{
				string text = lstDialog.ToString().ToUpper();
				int num = text.LastIndexOf('.');
				if (num != -1)
				{
					text = text.Substring(num + 1, text.Length - num - 1);
				}
				if (text == name.ToUpper())
				{
					return lstDialog;
				}
			}
			return null;
		}

		public int ShowUserDefinedWizard(int nSidrow)
		{
			UserDefinedCompWizardMain userDefinedCompWizardMain = new UserDefinedCompWizardMain(nSidrow);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					userDefinedCompWizardMain.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag = userDefinedCompWizardMain.ShowDialog();
			if (!flag.HasValue || !flag.Value)
			{
				return 0;
			}
			return 1;
		}

		public int ShowElecWizard(int localUseAped)
		{
			if (!dbFoundForElectrolyteWizard.HasValue)
			{
				if (string.IsNullOrEmpty(dbProvider))
				{
					dbProvider = SystemEnvironment.GetDBProvider;
				}
				if (dbProvider.ToLowerInvariant() == "postgres")
				{
					AspenTech.APED.Core.IDatabaseCollection databaseCollection = new AspenTech.APED.Core.DatabaseCollection();
					string appView = "ATVIEWER";
					dbMessage = databaseCollection.InitializeFromConfigurationFile(appView, "postgres");
					bool flag = false;
					if (databaseCollection.Count > 0)
					{
						Regex regex = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.Core.IDatabase item in databaseCollection)
						{
							if (regex.IsMatch(item.Alias))
							{
								flag = true;
								break;
							}
						}
					}
					if (!flag)
					{
						dbFoundForElectrolyteWizard = false;
					}
					else
					{
						dbFoundForElectrolyteWizard = true;
					}
				}
				else
				{
					AspenTech.APED.IDatabaseCollection databaseCollection2 = new AspenTech.APED.DatabaseCollection();
					string appPwd = "ATVIEWER";
					dbMessage = databaseCollection2.InitializeFromConfigurationFile(null, appPwd);
					bool flag2 = false;
					if (databaseCollection2.Count > 0)
					{
						Regex regex2 = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.IDatabase item2 in databaseCollection2)
						{
							if (regex2.IsMatch(item2.Alias))
							{
								flag2 = true;
								break;
							}
						}
					}
					if (!flag2)
					{
						dbFoundForElectrolyteWizard = false;
					}
					else
					{
						dbFoundForElectrolyteWizard = true;
					}
				}
			}
			if (dbFoundForElectrolyteWizard != true)
			{
				MMMessageBox.Show(Application.Current.MainWindow, string.Format(WpfFindComponentResources.MsgBox_MissingAPVDBForElectrolytes_Message, CompoundsTabViewModel.APNames[CompoundsTabViewModel.APNames.Count - 1]), WpfFindComponentResources.MsgBox_MissingAPVDB_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return 0;
			}
			ElecWizardMain elecWizardMain = new ElecWizardMain(localUseAped);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					elecWizardMain.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag3 = elecWizardMain.ShowDialog();
			if (!flag3.HasValue || !flag3.Value)
			{
				return 0;
			}
			return 1;
		}

		public int ShowSearchProperty(string szPropertyValue)
		{
			CreateProperty defaultCreatePropertyDialog = CreateProperty.DefaultCreatePropertyDialog;
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					defaultCreatePropertyDialog.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag = defaultCreatePropertyDialog.ShowDialog();
			if (!flag.HasValue || !flag.Value)
			{
				return 0;
			}
			return 1;
		}

		public int ShowSearchComponent(string root, int lRow, string searchText)
		{
			FindComounds findComounds = new FindComounds(root, lRow, searchText);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					findComounds.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag = findComounds.ShowDialog();
			if (findComounds.tabPubChem.Content is PubChemTab { DataContext: PubChemTabViewModel { AddedSuccessfully: var addedSuccessfully } } && addedSuccessfully == true)
			{
				return 2;
			}
			if (!flag.HasValue || !flag.Value)
			{
				return 0;
			}
			return 1;
		}

		public void ShowUpgradeRetired(int localUseAped, out int bstate)
		{
			UpgradeRetired upgradeRetired = new UpgradeRetired(localUseAped);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					upgradeRetired.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			upgradeRetired.ShowDialog();
			bstate = upgradeRetired.State;
		}

		public int ShowSFEAssistant(int localUseAped)
		{
			if (!dbFoundForSFEAssistant.HasValue)
			{
				if (string.IsNullOrEmpty(dbProvider))
				{
					dbProvider = SystemEnvironment.GetDBProvider;
				}
				if (dbProvider.ToLowerInvariant() == "postgres")
				{
					AspenTech.APED.Core.IDatabaseCollection databaseCollection = new AspenTech.APED.Core.DatabaseCollection();
					string appView = "ATVIEWER";
					dbMessage = databaseCollection.InitializeFromConfigurationFile(appView, "postgres");
					bool flag = false;
					if (databaseCollection.Count > 0)
					{
						Regex regex = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.Core.IDatabase item in databaseCollection)
						{
							if (regex.IsMatch(item.Alias))
							{
								flag = true;
								break;
							}
						}
					}
					if (!flag)
					{
						dbFoundForSFEAssistant = false;
					}
					else
					{
						dbFoundForSFEAssistant = true;
					}
				}
				else
				{
					AspenTech.APED.IDatabaseCollection databaseCollection2 = new AspenTech.APED.DatabaseCollection();
					string appPwd = "ATVIEWER";
					dbMessage = databaseCollection2.InitializeFromConfigurationFile(null, appPwd);
					bool flag2 = false;
					if (databaseCollection2.Count > 0)
					{
						Regex regex2 = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.IDatabase item2 in databaseCollection2)
						{
							if (regex2.IsMatch(item2.Alias))
							{
								flag2 = true;
								break;
							}
						}
					}
					if (!flag2)
					{
						dbFoundForSFEAssistant = false;
					}
					else
					{
						dbFoundForSFEAssistant = true;
					}
				}
			}
			if (dbFoundForSFEAssistant != true)
			{
				MMMessageBox.Show(Application.Current.MainWindow, string.Format(WpfFindComponentResources.MsgBox_MissingAPVDBForElectrolytes_Message, CompoundsTabViewModel.APNames[CompoundsTabViewModel.APNames.Count - 1]), WpfFindComponentResources.MsgBox_MissingAPVDB_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return 0;
			}
			SFEAssistant sFEAssistant = new SFEAssistant(localUseAped);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					sFEAssistant.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag3 = sFEAssistant.ShowDialog();
			if (!flag3.HasValue || !flag3.Value)
			{
				return 0;
			}
			return 1;
		}

		public int ShowSFEAssistantMain(int localUseAped)
		{
			if (!dbFoundForSFEAssistant.HasValue)
			{
				if (string.IsNullOrEmpty(dbProvider))
				{
					dbProvider = SystemEnvironment.GetDBProvider;
				}
				if (dbProvider.ToLowerInvariant() == "postgres")
				{
					AspenTech.APED.Core.IDatabaseCollection databaseCollection = new AspenTech.APED.Core.DatabaseCollection();
					string appView = "ATVIEWER";
					dbMessage = databaseCollection.InitializeFromConfigurationFile(appView, "postgres");
					bool flag = false;
					if (databaseCollection.Count > 0)
					{
						Regex regex = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.Core.IDatabase item in databaseCollection)
						{
							if (regex.IsMatch(item.Alias))
							{
								flag = true;
								break;
							}
						}
					}
					if (!flag)
					{
						dbFoundForSFEAssistant = false;
					}
					else
					{
						dbFoundForSFEAssistant = true;
					}
				}
				else
				{
					AspenTech.APED.IDatabaseCollection databaseCollection2 = new AspenTech.APED.DatabaseCollection();
					string appPwd = "ATVIEWER";
					dbMessage = databaseCollection2.InitializeFromConfigurationFile(null, appPwd);
					bool flag2 = false;
					if (databaseCollection2.Count > 0)
					{
						Regex regex2 = new Regex("^APV[0-9]+$");
						foreach (AspenTech.APED.IDatabase item2 in databaseCollection2)
						{
							if (regex2.IsMatch(item2.Alias))
							{
								flag2 = true;
								break;
							}
						}
					}
					if (!flag2)
					{
						dbFoundForSFEAssistant = false;
					}
					else
					{
						dbFoundForSFEAssistant = true;
					}
				}
			}
			if (dbFoundForSFEAssistant != true)
			{
				MMMessageBox.Show(Application.Current.MainWindow, string.Format(WpfFindComponentResources.MsgBox_MissingAPVDBForElectrolytes_Message, CompoundsTabViewModel.APNames[CompoundsTabViewModel.APNames.Count - 1]), WpfFindComponentResources.MsgBox_MissingAPVDB_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return 0;
			}
			SFEAssistantMain sFEAssistantMain = new SFEAssistantMain(localUseAped);
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					sFEAssistantMain.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool? flag3 = sFEAssistantMain.ShowDialog();
			if (!flag3.HasValue || !flag3.Value)
			{
				return 0;
			}
			return 1;
		}
	}
	[Module(ModuleName = "AspenTech.AspenPlus.WpfFindComponent.FindComponentModule")]
	public class FindComponentModule : IModule
	{
		public const string ModuleName = "AspenTech.AspenPlus.WpfFindComponent.FindComponentModule";

		public static IUnityContainer Container { get; private set; }

		public FindComponentModule(IUnityContainer container)
		{
			Container = container;
		}

		public void Initialize()
		{
			Container.RegisterType(typeof(Window), typeof(BiomassLookup), "BiomassLookup");
		}
	}
	public class FindProperty : Window, IComponentConnector, IStyleConnector
	{
		private string _propertyValue = "";

		private GridViewColumnHeader _lastHeaderClicked;

		private ListSortDirection _lastDirection;

		internal FindProperty findPropertyWindow;

		internal GroupBox grpStep1;

		internal TextBox txtProperty;

		internal Button btnSearch;

		internal CheckBox chkSearchPure;

		internal CheckBox chkRefSys;

		internal GroupBox grStep2;

		internal ListViewEx lstProperty;

		internal Button btnAdd;

		internal GroupBox grpStep3;

		internal ListViewEx lstAcceptedProperty;

		internal Button btnRemove;

		internal Button btnOK;

		internal Button btnCancel;

		internal Button btnHelp;

		private bool _contentLoaded;

		public FindProperty(string szPropertyValue)
		{
			InitializeComponent();
			_propertyValue = szPropertyValue;
			base.Loaded += FindProperty_Loaded;
		}

		private void FindProperty_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = new FindPropertyViewModel(_propertyValue);
		}

		private void ListView_ColumnHeaderClicked(object sender, RoutedEventArgs e)
		{
			if (e.OriginalSource is GridViewColumnHeader { Role: not GridViewColumnHeaderRole.Padding } gridViewColumnHeader)
			{
				ListSortDirection listSortDirection = ((gridViewColumnHeader == _lastHeaderClicked && _lastDirection == ListSortDirection.Ascending) ? ListSortDirection.Descending : ListSortDirection.Ascending);
				string sortBy = gridViewColumnHeader.Column.Header as string;
				Sort(sortBy, listSortDirection, sender as ListView);
				if (listSortDirection == ListSortDirection.Ascending)
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowUp"] as DataTemplate;
				}
				else
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowDown"] as DataTemplate;
				}
				if (_lastHeaderClicked != null && _lastHeaderClicked != gridViewColumnHeader)
				{
					_lastHeaderClicked.Column.HeaderTemplate = null;
				}
				_lastHeaderClicked = gridViewColumnHeader;
				_lastDirection = listSortDirection;
			}
		}

		private void Sort(string sortBy, ListSortDirection direction, ListView lstView)
		{
			if (sortBy == WpfFindComponentResources.PhyPropName)
			{
				sortBy = "Name";
			}
			else if (sortBy == WpfFindComponentResources.Alias)
			{
				sortBy = "Alias";
			}
			ICollectionView defaultView = CollectionViewSource.GetDefaultView(lstView.ItemsSource);
			defaultView.SortDescriptions.Clear();
			SortDescription item = new SortDescription(sortBy, direction);
			defaultView.SortDescriptions.Add(item);
			defaultView.Refresh();
		}

		private void ListViewItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			btnAdd.Command.Execute(null);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/findproperty.xaml", UriKind.Relative);
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
				findPropertyWindow = (FindProperty)target;
				break;
			case 2:
				grpStep1 = (GroupBox)target;
				break;
			case 3:
				txtProperty = (TextBox)target;
				break;
			case 4:
				btnSearch = (Button)target;
				break;
			case 5:
				chkSearchPure = (CheckBox)target;
				break;
			case 6:
				chkRefSys = (CheckBox)target;
				break;
			case 7:
				grStep2 = (GroupBox)target;
				break;
			case 8:
				lstProperty = (ListViewEx)target;
				lstProperty.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			case 10:
				btnAdd = (Button)target;
				break;
			case 11:
				grpStep3 = (GroupBox)target;
				break;
			case 12:
				lstAcceptedProperty = (ListViewEx)target;
				lstAcceptedProperty.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			case 13:
				btnRemove = (Button)target;
				break;
			case 14:
				btnOK = (Button)target;
				break;
			case 15:
				btnCancel = (Button)target;
				break;
			case 16:
				btnHelp = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 9)
			{
				EventSetter eventSetter = new EventSetter();
				eventSetter.Event = Control.MouseDoubleClickEvent;
				eventSetter.Handler = new MouseButtonEventHandler(ListViewItem_MouseDoubleClick);
				((Style)target).Setters.Add(eventSetter);
			}
		}
	}
	public class ListViewEx : ListView
	{
		public static readonly DependencyProperty BindableSelectedItemsProperty = DependencyProperty.Register("BindableSelectedItems", typeof(IList), typeof(ListViewEx));

		public IList BindableSelectedItems
		{
			get
			{
				return (IList)GetValue(BindableSelectedItemsProperty);
			}
			set
			{
				SetValue(BindableSelectedItemsProperty, value);
			}
		}

		protected override void OnSelectionChanged(SelectionChangedEventArgs e)
		{
			BindableSelectedItems = base.SelectedItems;
			base.OnSelectionChanged(e);
		}
	}
	public class FindPropertyViewModel : INotifyPropertyChanged
	{
		private ObservableCollection<PropertyItem> _avlialableProps = new ObservableCollection<PropertyItem>();

		private ObservableCollection<PropertyItem> _acceptedProps = new ObservableCollection<PropertyItem>();

		private string _propertyForSearch;

		private IList _selectedAvliableProps;

		private IList _selectedAcceptedProps;

		private ICommand _searchCommand;

		private ICommand _addCommand;

		private ICommand _removeCommand;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public ObservableCollection<PropertyItem> AvlialableProps => _avlialableProps;

		public ObservableCollection<PropertyItem> AcceptedProps => _acceptedProps;

		public string PropertyForSearch
		{
			get
			{
				return _propertyForSearch;
			}
			set
			{
				_propertyForSearch = value;
				OnPropertyChanged("PropertyForSearch");
			}
		}

		public bool IsSearchPure { get; set; }

		public bool IsIncludeRefsys { get; set; }

		public IList SelectedAvliableProps
		{
			get
			{
				return _selectedAvliableProps;
			}
			set
			{
				_selectedAvliableProps = value;
				OnPropertyChanged("SelectedAvliableProps");
				(AddCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public IList SelectedAcceptedProps
		{
			get
			{
				return _selectedAcceptedProps;
			}
			set
			{
				_selectedAcceptedProps = value;
				OnPropertyChanged("SelectedAcceptedProps");
				(RemoveCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ICommand SearchCommand
		{
			get
			{
				if (_searchCommand == null)
				{
					_searchCommand = new DelegateCommand<object>(Executed_SearchCommand, CanExecute_SearchCommand);
				}
				return _searchCommand;
			}
		}

		public ICommand AddCommand
		{
			get
			{
				if (_addCommand == null)
				{
					_addCommand = new DelegateCommand<object>(Executed_AddCommand, CanExecute_AddCommand);
				}
				return _addCommand;
			}
		}

		public ICommand RemoveCommand
		{
			get
			{
				if (_removeCommand == null)
				{
					_removeCommand = new DelegateCommand<object>(Executed_RemoveCommand, CanExecute_RemoveCommand);
				}
				return _removeCommand;
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK, CanExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public ICommand CommandOnCancel
		{
			get
			{
				if (_commandOnCancel == null)
				{
					_commandOnCancel = new DelegateCommand<object>(ExecuteCommandOnCancel);
				}
				return _commandOnCancel;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}

		public FindPropertyViewModel(string propertyValue)
		{
			PropertyForSearch = propertyValue;
		}

		private void Executed_SearchCommand(object args)
		{
			AvlialableProps.Clear();
			foreach (PropertyItem item in SmgeHelper.FetchPropertiesM(PropertyForSearch, IsSearchPure, IsIncludeRefsys))
			{
				AvlialableProps.Add(item);
			}
		}

		private bool CanExecute_SearchCommand(object args)
		{
			return true;
		}

		private void Executed_AddCommand(object args)
		{
			if (SelectedAvliableProps != null && SelectedAvliableProps.Count + AcceptedProps.Count > 1)
			{
				int checkbox = SmgeHelper.SMchkmultipleM(-1);
				if (checkbox == 1)
				{
					OpenMessageBox.Show(WpfFindComponentResources.MultipleProperties, WpfFindComponentResources.MultiplePropertiesText, WpfFindComponentResources.OK, "", "", "", "", 0, ref checkbox);
					if (checkbox == 1)
					{
						SmgeHelper.SMchkmultipleM(0);
					}
					else
					{
						SmgeHelper.SMchkmultipleM(1);
					}
				}
			}
			foreach (object selectedAvliableProp in SelectedAvliableProps)
			{
				if (!(selectedAvliableProp is PropertyItem propertyItem))
				{
					continue;
				}
				if (!AcceptedProps.Contains(propertyItem))
				{
					if (SmgeHelper.SMchkpropM(propertyItem.Alias) != 0)
					{
						MMMessageBox.Show(string.Format(WpfFindComponentResources.PropertyHasInPropSet, propertyItem.Name), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					}
					else
					{
						AcceptedProps.Add(propertyItem);
					}
				}
				else
				{
					MMMessageBox.Show(string.Format(WpfFindComponentResources.PropertyHasSelected, propertyItem.Name), MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				}
			}
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecute_AddCommand(object args)
		{
			if (SelectedAvliableProps != null)
			{
				return SelectedAvliableProps.Count > 0;
			}
			return false;
		}

		private void Executed_RemoveCommand(object args)
		{
			List<PropertyItem> list = new List<PropertyItem>();
			foreach (object selectedAcceptedProp in SelectedAcceptedProps)
			{
				if (selectedAcceptedProp is PropertyItem item && AcceptedProps.Contains(item))
				{
					list.Add(item);
				}
			}
			foreach (PropertyItem item2 in list)
			{
				AcceptedProps.Remove(item2);
			}
			(CommandOnOK as DelegateCommand<object>).RaiseCanExecuteChanged();
		}

		private bool CanExecute_RemoveCommand(object args)
		{
			if (SelectedAcceptedProps != null)
			{
				return SelectedAcceptedProps.Count > 0;
			}
			return false;
		}

		private void ExecuteCommandOnOK(object arg)
		{
			foreach (PropertyItem acceptedProp in AcceptedProps)
			{
				SmgeHelper.SMinsertpropM(acceptedProp.Alias);
			}
			if (arg is Window window)
			{
				window.DialogResult = true;
				window.Close();
			}
		}

		private bool CanExecuteCommandOnOK(object arg)
		{
			return AcceptedProps.Count > 0;
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			if (arg is Window window)
			{
				window.DialogResult = false;
				window.Close();
			}
		}
	}
	public class NewPureCompParamViewModel : INotifyPropertyChanged
	{
		private class ParamAndClass
		{
			public string csParamList { get; set; }

			public int iClassification { get; set; }

			public ParamAndClass(string _csParamList, int _iClassification)
			{
				csParamList = _csParamList;
				iClassification = _iClassification;
			}
		}

		private static readonly int NUM_T_DEP_CLASSES = 35;

		private static readonly string[] csClassNames = new string[35]
		{
			WpfFindComponentResources.ClassName0,
			WpfFindComponentResources.ClassName1,
			WpfFindComponentResources.ClassName2,
			WpfFindComponentResources.ClassName3,
			WpfFindComponentResources.ClassName4,
			WpfFindComponentResources.ClassName5,
			WpfFindComponentResources.ClassName6,
			WpfFindComponentResources.ClassName7,
			WpfFindComponentResources.ClassName8,
			WpfFindComponentResources.ClassName9,
			WpfFindComponentResources.ClassName10,
			WpfFindComponentResources.ClassName11,
			WpfFindComponentResources.ClassName12,
			WpfFindComponentResources.ClassName13,
			WpfFindComponentResources.ClassName14,
			WpfFindComponentResources.ClassName15,
			WpfFindComponentResources.ClassName16,
			WpfFindComponentResources.ClassName17,
			WpfFindComponentResources.ClassName18,
			WpfFindComponentResources.ClassName19,
			WpfFindComponentResources.ClassName20,
			WpfFindComponentResources.ClassName21,
			WpfFindComponentResources.ClassName22,
			WpfFindComponentResources.ClassName23,
			WpfFindComponentResources.ClassName24,
			WpfFindComponentResources.ClassName25,
			WpfFindComponentResources.ClassName26,
			WpfFindComponentResources.ClassName27,
			WpfFindComponentResources.ClassName28,
			WpfFindComponentResources.ClassName29,
			WpfFindComponentResources.ClassName30,
			WpfFindComponentResources.ClassName31,
			WpfFindComponentResources.ClassName32,
			WpfFindComponentResources.ClassName33,
			WpfFindComponentResources.ClassName34
		};

		private static readonly int Alpha_function_for_equations_of_state = 0;

		private static readonly int Aqueous_heat_capacity = 1;

		private static readonly int Atom_count = 2;

		private static readonly int BWRS_parameters = 3;

		private static readonly int Dielectric_constant = 4;

		private static readonly int Flory_Huggins_size_parameter = 5;

		private static readonly int Heat_of_vaporization = 6;

		private static readonly int Helgeson_model_parameters = 7;

		private static readonly int HF_model_parameters = 8;

		private static readonly int Ideal_gas_heat_capacity = 9;

		private static readonly int Liquid_heat_capacity = 10;

		private static readonly int Liquid_molar_volume = 11;

		private static readonly int Liquid_thermal_conductivity = 12;

		private static readonly int Liquid_vapor_pressure = 13;

		private static readonly int Liquid_viscosity = 14;

		private static readonly int Liquid_viscosity_for_electrolytes = 15;

		private static readonly int Molecular_parameters = 16;

		private static readonly int Nothnagel_parameters = 17;

		private static readonly int Number_of_atoms_in_molecule = 18;

		private static readonly int Solid_heat_capacity = 19;

		private static readonly int Solid_molar_volume = 20;

		private static readonly int Solid_thermal_conductivity = 21;

		private static readonly int Solid_vapor_pressure = 22;

		private static readonly int Submodel_selection_option = 23;

		private static readonly int Surface_tension = 24;

		private static readonly int UNIFAC_group_count = 25;

		private static readonly int van_Krevelen_crystalline_heat_capacity = 26;

		private static readonly int van_Krevelen_density = 27;

		private static readonly int van_Krevelen_group_count = 28;

		private static readonly int van_Krevelen_thermal_conductivity = 29;

		private static readonly int Vapor_thermal_conductivity = 30;

		private static readonly int Vapor_viscosity = 31;

		private static readonly int Solubility = 32;

		private static readonly int NRTL_SAC_eNRTL_SAC = 33;

		private static readonly int COSMO_SAC = 34;

		private readonly int NUM_T_DEP_PARAM = 167;

		private static readonly ParamAndClass[] ParamClassList = new ParamAndClass[167]
		{
			new ParamAndClass("AHGPAR-1", Helgeson_model_parameters),
			new ParamAndClass("ATOMNO-1", Atom_count),
			new ParamAndClass("BWRSA-1", BWRS_parameters),
			new ParamAndClass("CHGPAR-1", Helgeson_model_parameters),
			new ParamAndClass("CPAQ0-1", Aqueous_heat_capacity),
			new ParamAndClass("CPCVK-1", van_Krevelen_crystalline_heat_capacity),
			new ParamAndClass("CPCVKM-1", van_Krevelen_crystalline_heat_capacity),
			new ParamAndClass("CPDIEC-1", Dielectric_constant),
			new ParamAndClass("CPIAPI-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIG-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIGDP-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIGDS-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIGPO-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIGYM-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIALE-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPITML-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIWEO-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIXP1-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIXP2-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPIXP3-1", Ideal_gas_heat_capacity),
			new ParamAndClass("CPLBPS-1", Liquid_heat_capacity),
			new ParamAndClass("CPLDIP-1", Liquid_heat_capacity),
			new ParamAndClass("CPLPDS-1", Liquid_heat_capacity),
			new ParamAndClass("CPLIKC-1", Liquid_heat_capacity),
			new ParamAndClass("CPLPO-1", Liquid_heat_capacity),
			new ParamAndClass("CPLTDE-1", Liquid_heat_capacity),
			new ParamAndClass("CPLTML-1", Liquid_heat_capacity),
			new ParamAndClass("CPLVK-1", Liquid_heat_capacity),
			new ParamAndClass("CPLVKM-1", Liquid_heat_capacity),
			new ParamAndClass("CPLXP1-1", Liquid_heat_capacity),
			new ParamAndClass("CPLXP2-1", Liquid_heat_capacity),
			new ParamAndClass("BIOCP-1", Solid_heat_capacity),
			new ParamAndClass("CPSDIP-1", Solid_heat_capacity),
			new ParamAndClass("CPSPO-1", Solid_heat_capacity),
			new ParamAndClass("CPSPO1-1", Solid_heat_capacity),
			new ParamAndClass("CPSTML-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP1-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP2-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP3-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP4-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP5-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP6-1", Solid_heat_capacity),
			new ParamAndClass("CPSXP7-1", Solid_heat_capacity),
			new ParamAndClass("DHVLDP-1", Heat_of_vaporization),
			new ParamAndClass("DHVLDS-1", Heat_of_vaporization),
			new ParamAndClass("DHVLPO-1", Heat_of_vaporization),
			new ParamAndClass("DHVLTD-1", Heat_of_vaporization),
			new ParamAndClass("DHVLWT-1", Heat_of_vaporization),
			new ParamAndClass("DNCVK-1", van_Krevelen_density),
			new ParamAndClass("DNCVKM-1", van_Krevelen_density),
			new ParamAndClass("DNGVK-1", van_Krevelen_density),
			new ParamAndClass("DNGVKM-1", van_Krevelen_density),
			new ParamAndClass("DNLCOS-1", Liquid_molar_volume),
			new ParamAndClass("DNLDIP-1", Liquid_molar_volume),
			new ParamAndClass("DNLEXS-1", Liquid_molar_volume),
			new ParamAndClass("DNLPDS-1", Liquid_molar_volume),
			new ParamAndClass("DNLRAC-1", Liquid_molar_volume),
			new ParamAndClass("DNLTML-1", Liquid_molar_volume),
			new ParamAndClass("RHOML-1", Liquid_molar_volume),
			new ParamAndClass("DNLVK-1", van_Krevelen_density),
			new ParamAndClass("DNLVKM-1", van_Krevelen_density),
			new ParamAndClass("DNSDIP-1", Solid_molar_volume),
			new ParamAndClass("DNSTML-1", Solid_molar_volume),
			new ParamAndClass("RHOMS-1", Solid_molar_volume),
			new ParamAndClass("ECPIG-1", Ideal_gas_heat_capacity),
			new ParamAndClass("ESHFK-1", HF_model_parameters),
			new ParamAndClass("FHSIZE-1", Flory_Huggins_size_parameter),
			new ParamAndClass("IONMOB-1", Liquid_viscosity_for_electrolytes),
			new ParamAndClass("IONMUB-1", Liquid_viscosity_for_electrolytes),
			new ParamAndClass("IONTHG-1", Helgeson_model_parameters),
			new ParamAndClass("KLDIP-1", Liquid_thermal_conductivity),
			new ParamAndClass("KLPDS-1", Liquid_thermal_conductivity),
			new ParamAndClass("KLPO-1", Liquid_thermal_conductivity),
			new ParamAndClass("KLPPDS-1", Liquid_thermal_conductivity),
			new ParamAndClass("KLTMLP-1", Liquid_thermal_conductivity),
			new ParamAndClass("KLVKC-1", van_Krevelen_thermal_conductivity),
			new ParamAndClass("KLVKG-1", van_Krevelen_thermal_conductivity),
			new ParamAndClass("KLVKL-1", van_Krevelen_thermal_conductivity),
			new ParamAndClass("KSPOLY-1", Solid_thermal_conductivity),
			new ParamAndClass("KVDIP-1", Vapor_thermal_conductivity),
			new ParamAndClass("KVPDS-1", Vapor_thermal_conductivity),
			new ParamAndClass("KVPO-1", Vapor_thermal_conductivity),
			new ParamAndClass("KVTMLP-1", Vapor_thermal_conductivity),
			new ParamAndClass("LJPAR-1", Molecular_parameters),
			new ParamAndClass("LNPR1-1", Liquid_vapor_pressure),
			new ParamAndClass("LNPR2-1", Liquid_vapor_pressure),
			new ParamAndClass("LNVP1-1", Liquid_vapor_pressure),
			new ParamAndClass("LNVPEQ-1", Liquid_vapor_pressure),
			new ParamAndClass("LOGPR1-1", Liquid_vapor_pressure),
			new ParamAndClass("LOGPR2-1", Liquid_vapor_pressure),
			new ParamAndClass("LOGVP1-1", Liquid_vapor_pressure),
			new ParamAndClass("MULAND-1", Liquid_viscosity),
			new ParamAndClass("MULBPS-1", Liquid_viscosity),
			new ParamAndClass("MULDIP-1", Liquid_viscosity),
			new ParamAndClass("MULIKC-1", Liquid_viscosity),
			new ParamAndClass("MULMH-1", Liquid_viscosity),
			new ParamAndClass("MULMK-1", Liquid_viscosity),
			new ParamAndClass("MULNVE-1", Liquid_viscosity),
			new ParamAndClass("MULPDS-1", Liquid_viscosity),
			new ParamAndClass("MULPO-1", Liquid_viscosity),
			new ParamAndClass("MULPPD-1", Liquid_viscosity),
			new ParamAndClass("MULVK-1", Liquid_viscosity),
			new ParamAndClass("MUVCEB-1", Vapor_viscosity),
			new ParamAndClass("MUVDIP-1", Vapor_viscosity),
			new ParamAndClass("MUVPDS-1", Vapor_viscosity),
			new ParamAndClass("MUVPO-1", Vapor_viscosity),
			new ParamAndClass("MUVSUT-1", Vapor_viscosity),
			new ParamAndClass("MUVTML-1", Vapor_viscosity),
			new ParamAndClass("NATOM-1", Number_of_atoms_in_molecule),
			new ParamAndClass("NOATOM-1", Atom_count),
			new ParamAndClass("NTHA-1", Nothnagel_parameters),
			new ParamAndClass("NTHK-1", Nothnagel_parameters),
			new ParamAndClass("PDSNEL-1", Vapor_thermal_conductivity),
			new ParamAndClass("PLPO-1", Liquid_vapor_pressure),
			new ParamAndClass("PLTDEP-1", Liquid_vapor_pressure),
			new ParamAndClass("PLXANT-1", Liquid_vapor_pressure),
			new ParamAndClass("PRGLP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("PRMCP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("PRSRP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("PRTWUP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("PSANT-1", Solid_vapor_pressure),
			new ParamAndClass("PSXANT-1", Solid_vapor_pressure),
			new ParamAndClass("PSTDEP-1", Solid_vapor_pressure),
			new ParamAndClass("PSTMLP-1", Solid_vapor_pressure),
			new ParamAndClass("RACKET-1", Liquid_molar_volume),
			new ParamAndClass("RKSMCP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("RKSSRP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("SIGDIP-1", Surface_tension),
			new ParamAndClass("SIGIST-1", Surface_tension),
			new ParamAndClass("SIGP14-1", Surface_tension),
			new ParamAndClass("SIGPDS-1", Surface_tension),
			new ParamAndClass("SIGPO-1", Surface_tension),
			new ParamAndClass("SIGTDE-1", Surface_tension),
			new ParamAndClass("SRKGLP-1", Alpha_function_for_equations_of_state),
			new ParamAndClass("STKPAR-1", Molecular_parameters),
			new ParamAndClass("THRSWT-1", Submodel_selection_option),
			new ParamAndClass("TRNSWT-1", Submodel_selection_option),
			new ParamAndClass("UFGRP-1", UNIFAC_group_count),
			new ParamAndClass("UFGRP-2", UNIFAC_group_count),
			new ParamAndClass("UFGRPD-1", UNIFAC_group_count),
			new ParamAndClass("UFGRPL-1", UNIFAC_group_count),
			new ParamAndClass("VKGRP-1", van_Krevelen_group_count),
			new ParamAndClass("VLBROC-1", Liquid_molar_volume),
			new ParamAndClass("VLPO-1", Liquid_molar_volume),
			new ParamAndClass("VLTAIT-1", Liquid_molar_volume),
			new ParamAndClass("VSPO-1", Solid_molar_volume),
			new ParamAndClass("VSPOLY-1", Solid_molar_volume),
			new ParamAndClass("WAGNER-1", Liquid_vapor_pressure),
			new ParamAndClass("WAGN25-1", Liquid_vapor_pressure),
			new ParamAndClass("WATSOL-1", Solubility),
			new ParamAndClass("HCSOL-1", Solubility),
			new ParamAndClass("XYZE-1", NRTL_SAC_eNRTL_SAC),
			new ParamAndClass("SGPRF1-1", COSMO_SAC),
			new ParamAndClass("SGPRF2-1", COSMO_SAC),
			new ParamAndClass("SGPRF3-1", COSMO_SAC),
			new ParamAndClass("SGPRF4-1", COSMO_SAC),
			new ParamAndClass("SGPRF5-1", COSMO_SAC),
			new ParamAndClass("SGPRF6-1", COSMO_SAC),
			new ParamAndClass("SGPRF7-1", COSMO_SAC),
			new ParamAndClass("SGPRE1-1", COSMO_SAC),
			new ParamAndClass("SGPRE2-1", COSMO_SAC),
			new ParamAndClass("SGPRE3-1", COSMO_SAC),
			new ParamAndClass("SGPRE4-1", COSMO_SAC),
			new ParamAndClass("SGPRE5-1", COSMO_SAC),
			new ParamAndClass("SGPRE6-1", COSMO_SAC),
			new ParamAndClass("SGPRE7-1", COSMO_SAC),
			new ParamAndClass("MRKZRA-1", Liquid_molar_volume)
		};

		private string _param;

		private string _prompt;

		private bool _isParamReadonly;

		private Visibility _labelDefaultVisible;

		private Visibility _labelTDependentVisible;

		private bool _isScalarChecked;

		private bool _isCorrelationChecked;

		private bool _isNonconvChecked;

		private ObservableCollection<TreeNode> _treeNodeList = new ObservableCollection<TreeNode>();

		private TreeNode _selectedTreeNode;

		private List<string> PromptArray = new List<string>();

		private int _paramType;

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		public string Param
		{
			get
			{
				return _param;
			}
			set
			{
				_param = value;
				OnPropertyChanged("Param");
			}
		}

		public string Prompt
		{
			get
			{
				return _prompt;
			}
			set
			{
				_prompt = value;
				OnPropertyChanged("Prompt");
			}
		}

		public bool IsParamReadonly
		{
			get
			{
				return _isParamReadonly;
			}
			set
			{
				_isParamReadonly = value;
				OnPropertyChanged("IsParamReadonly");
			}
		}

		public Visibility LabelDefaultVisible
		{
			get
			{
				return _labelDefaultVisible;
			}
			set
			{
				_labelDefaultVisible = value;
				OnPropertyChanged("LabelDefaultVisible");
			}
		}

		public Visibility LabelTDependentVisible
		{
			get
			{
				return _labelTDependentVisible;
			}
			set
			{
				_labelTDependentVisible = value;
				OnPropertyChanged("LabelTDependentVisible");
			}
		}

		public bool IsScalarChecked
		{
			get
			{
				return _isScalarChecked;
			}
			set
			{
				_isScalarChecked = value;
				OnPropertyChanged("IsScalarChecked");
				if (value)
				{
					_paramType = 0;
					IsParamReadonly = false;
					LabelTDependentVisible = Visibility.Collapsed;
					LabelDefaultVisible = Visibility.Visible;
					TreeNodeList.Clear();
					Prompt = "";
					Param = SmgeHelper.SMgetpurescalarIDM();
				}
			}
		}

		public bool IsCorrelationChecked
		{
			get
			{
				return _isCorrelationChecked;
			}
			set
			{
				_isCorrelationChecked = value;
				OnPropertyChanged("IsCorrelationChecked");
				if (!value)
				{
					return;
				}
				IsParamReadonly = true;
				LabelTDependentVisible = Visibility.Visible;
				LabelDefaultVisible = Visibility.Collapsed;
				TreeNodeList.Clear();
				_paramType = 1;
				int num = -1;
				string paramname = "";
				string prompt = "";
				bool flag = false;
				if (SmgeHelper.SMlistparamsM(1, out paramname, 1, out prompt) != 0)
				{
					while (SmgeHelper.SMlistparamsM(1, out paramname, 0, out prompt) != 0)
					{
						flag = false;
						PromptArray.Add(prompt);
						int promptIndex = PromptArray.IndexOf(prompt);
						for (int i = 0; i < NUM_T_DEP_PARAM; i++)
						{
							if (!ParamClassList[i].csParamList.StartsWith(paramname))
							{
								continue;
							}
							flag = true;
							num = ParamClassList[i].iClassification;
							if (num != 25 && num != 2)
							{
								string text = csClassNames[num];
								TreeNode treeNode = FindItemInTree(text);
								if (treeNode == null)
								{
									treeNode = new TreeNode(text);
									TreeNodeList.Add(treeNode);
								}
								treeNode.Nodes.Add(new TreeNode(paramname, promptIndex));
							}
						}
						if (!flag)
						{
							string text = WpfFindComponentResources.ClassName_Miscellaneous;
							TreeNode treeNode2 = FindItemInTree(text);
							if (treeNode2 == null)
							{
								treeNode2 = new TreeNode(text);
								TreeNodeList.Add(treeNode2);
							}
							treeNode2.Nodes.Add(new TreeNode(paramname, promptIndex));
						}
					}
				}
				List<TreeNode> list = TreeNodeList.OrderBy((TreeNode p) => p.Text).ToList();
				TreeNodeList.Clear();
				foreach (TreeNode item in list)
				{
					TreeNodeList.Add(item);
				}
				Param = "";
			}
		}

		public bool IsNonconvChecked
		{
			get
			{
				return _isNonconvChecked;
			}
			set
			{
				_isNonconvChecked = value;
				OnPropertyChanged("IsNonconvChecked");
				if (value)
				{
					_paramType = 2;
					TreeNodeList.Clear();
					IsParamReadonly = false;
					LabelTDependentVisible = Visibility.Collapsed;
					LabelDefaultVisible = Visibility.Visible;
					Prompt = "";
					Param = SmgeHelper.SMgetNCIDM();
				}
			}
		}

		public ObservableCollection<TreeNode> TreeNodeList => _treeNodeList;

		public object SelectedTreeNode
		{
			get
			{
				return _selectedTreeNode;
			}
			set
			{
				_selectedTreeNode = value as TreeNode;
				OnPropertyChanged("SelectedTreeNode");
				if (_selectedTreeNode != null && _selectedTreeNode.PromptIndex >= 0 && _selectedTreeNode.PromptIndex < PromptArray.Count)
				{
					Param = _selectedTreeNode.Text;
					Prompt = PromptArray[_selectedTreeNode.PromptIndex];
				}
				else
				{
					Param = "";
					Prompt = "";
				}
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public ICommand CommandOnCancel
		{
			get
			{
				if (_commandOnCancel == null)
				{
					_commandOnCancel = new DelegateCommand<object>(ExecuteCommandOnCancel);
				}
				return _commandOnCancel;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public NewPureCompParamViewModel()
		{
			PromptArray.Clear();
			IsScalarChecked = true;
		}

		private TreeNode FindItemInTree(string csText)
		{
			return TreeNodeList.FirstOrDefault((TreeNode p) => p.Text.Equals(csText));
		}

		private void ExecuteCommandOnOK(object arg)
		{
			Window window = arg as Window;
			if (string.IsNullOrEmpty(Param))
			{
				MMMessageBox.Show(window, WpfFindComponentResources.SpecifyParameterID, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return;
			}
			if (Regex.IsMatch(Param, "[^\\u0000-\\u007F]"))
			{
				MMMessageBox.Show(window, Resources.CannotInputNonASCIICharAsID, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return;
			}
			if (SmgeHelper.SMCreateRecordM(_paramType, Param, out var errbuf) == 0)
			{
				MMMessageBox.Show(window, errbuf, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Information);
				return;
			}
			window.DialogResult = true;
			window.Close();
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			Window obj = arg as Window;
			obj.DialogResult = false;
			obj.Close();
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}
	}
	public class TreeNode
	{
		private ObservableCollection<TreeNode> _nodes = new ObservableCollection<TreeNode>();

		public int PromptIndex { get; set; }

		public string Text { get; set; }

		public ObservableCollection<TreeNode> Nodes => _nodes;

		public TreeNode(string _text, int _promptIndex = -1)
		{
			Text = _text;
			PromptIndex = _promptIndex;
		}

		public override string ToString()
		{
			return Text;
		}
	}
	public class TreeViewEx : TreeView
	{
		public static readonly DependencyProperty BindableSelectedItemProperty = DependencyProperty.Register("BindableSelectedItem", typeof(object), typeof(TreeViewEx));

		public object BindableSelectedItem
		{
			get
			{
				return GetValue(BindableSelectedItemProperty);
			}
			set
			{
				SetValue(BindableSelectedItemProperty, value);
			}
		}

		protected override void OnSelectedItemChanged(RoutedPropertyChangedEventArgs<object> e)
		{
			BindableSelectedItem = base.SelectedItem;
			base.OnSelectedItemChanged(e);
		}
	}
	public class NewPureCompParam : Window, IComponentConnector
	{
		internal NewPureCompParam newPureCompParamWindow;

		internal GroupBox grpSelectType1;

		internal RadioButton radioScalar;

		internal RadioButton radioCorrelation;

		internal RadioButton radioNonconventional;

		internal TreeViewEx treeParameter;

		internal TextBox txtPrompt;

		internal Label lblDefault;

		internal Label lblTDependent;

		internal TextBox txtNewOrDefault;

		internal Button btnOK;

		internal Button btnCancel;

		private bool _contentLoaded;

		public NewPureCompParam()
		{
			InitializeComponent();
			base.Loaded += NewPureCompParam_Loaded;
		}

		private void NewPureCompParam_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = new NewPureCompParamViewModel();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/newpurecompparam.xaml", UriKind.Relative);
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
				newPureCompParamWindow = (NewPureCompParam)target;
				break;
			case 2:
				grpSelectType1 = (GroupBox)target;
				break;
			case 3:
				radioScalar = (RadioButton)target;
				break;
			case 4:
				radioCorrelation = (RadioButton)target;
				break;
			case 5:
				radioNonconventional = (RadioButton)target;
				break;
			case 6:
				treeParameter = (TreeViewEx)target;
				break;
			case 7:
				txtPrompt = (TextBox)target;
				break;
			case 8:
				lblDefault = (Label)target;
				break;
			case 9:
				lblTDependent = (Label)target;
				break;
			case 10:
				txtNewOrDefault = (TextBox)target;
				break;
			case 11:
				btnOK = (Button)target;
				break;
			case 12:
				btnCancel = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PagingControl : UserControl, IComponentConnector
	{
		private const int AroundCount = 2;

		private const int PageItemsCount = 9;

		private int _maxPage = 1;

		public static readonly DependencyProperty LoadCompleteProperty = DependencyProperty.Register("LoadComplete", typeof(bool), typeof(PagingControl), new PropertyMetadata(true));

		public static readonly DependencyProperty MaxAllowedPageProperty = DependencyProperty.Register("MaxAllowedPage", typeof(int), typeof(PagingControl), new PropertyMetadata(1, OnMaxAllowedPageChanged));

		private readonly ObservableCollection<PageItem> pageItems = new ObservableCollection<PageItem>();

		public static readonly DependencyProperty SelectedPageProperty = DependencyProperty.Register("SelectedPage", typeof(int?), typeof(PagingControl), new PropertyMetadata(1, OnSelectedPageChanged));

		private DelegateCommand<object> prePageCommand;

		private DelegateCommand<object> nextPageCommand;

		internal ListBox pageListBox;

		private bool _contentLoaded;

		public bool LoadComplete
		{
			get
			{
				return (bool)GetValue(LoadCompleteProperty);
			}
			set
			{
				SetValue(LoadCompleteProperty, value);
				(NextPageCommand as DelegateCommand<object>)?.RaiseCanExecuteChanged();
			}
		}

		public int MaxAllowedPage
		{
			get
			{
				return (int)GetValue(MaxAllowedPageProperty);
			}
			set
			{
				SetValue(MaxAllowedPageProperty, value);
			}
		}

		public ObservableCollection<PageItem> PageItems => pageItems;

		public int? SelectedPage
		{
			get
			{
				return (int?)GetValue(SelectedPageProperty);
			}
			set
			{
				SetValue(SelectedPageProperty, value);
			}
		}

		public ICommand PrePageCommand
		{
			get
			{
				if (prePageCommand == null)
				{
					prePageCommand = new DelegateCommand<object>(ExecutePrePageCommand, CanExecutePrePageCommand);
				}
				return prePageCommand;
			}
		}

		public ICommand NextPageCommand
		{
			get
			{
				if (nextPageCommand == null)
				{
					nextPageCommand = new DelegateCommand<object>(ExecuteNextPageCommand, CanExecuteNextPageCommand);
				}
				return nextPageCommand;
			}
		}

		private static void OnMaxAllowedPageChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			PagingControl pagingControl = d as PagingControl;
			(pagingControl.NextPageCommand as DelegateCommand<object>)?.RaiseCanExecuteChanged();
			if ((int)e.NewValue < pagingControl._maxPage)
			{
				pagingControl._maxPage = (int)e.NewValue;
				pagingControl.RefreshPageItems();
			}
		}

		private static void OnSelectedPageChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			int? newValue = (int?)e.NewValue;
			PagingControl pagingControl = d as PagingControl;
			if (newValue.HasValue && pagingControl.PageItems.Count > 0)
			{
				PageItem pageItem = pagingControl.PageItems.FirstOrDefault((PageItem x) => x.Id == newValue);
				if (pageItem == null || pageItem.IsEllipsis)
				{
					pagingControl.RefreshPageItems();
				}
			}
			(pagingControl.PrePageCommand as DelegateCommand<object>)?.RaiseCanExecuteChanged();
			(pagingControl.NextPageCommand as DelegateCommand<object>)?.RaiseCanExecuteChanged();
		}

		private bool CanExecutePrePageCommand(object arg)
		{
			if (SelectedPage.HasValue)
			{
				return SelectedPage.Value != 1;
			}
			return false;
		}

		private async void ExecutePrePageCommand(object arg)
		{
			try
			{
				SelectedPage--;
			}
			catch (Exception)
			{
			}
		}

		private bool CanExecuteNextPageCommand(object arg)
		{
			if (LoadComplete && SelectedPage.HasValue)
			{
				return SelectedPage.Value != MaxAllowedPage;
			}
			return false;
		}

		private async void ExecuteNextPageCommand(object arg)
		{
			try
			{
				LoadComplete = false;
				PageItem pageItem = PageItems.LastOrDefault();
				if (pageItem != null && pageItem.Id == SelectedPage)
				{
					_maxPage++;
				}
				SelectedPage++;
				LoadComplete = true;
			}
			catch (Exception)
			{
				LoadComplete = true;
			}
		}

		public PagingControl()
		{
			InitializeComponent();
			RefreshPageItems();
			base.PreviewKeyDown += PagingControl_PreviewKeyDown;
		}

		private void PagingControl_PreviewKeyDown(object sender, KeyEventArgs e)
		{
			if (e.Key == Key.Left)
			{
				if (PrePageCommand.CanExecute(null))
				{
					PrePageCommand.Execute(null);
				}
			}
			else if (e.Key == Key.Right && NextPageCommand.CanExecute(null))
			{
				NextPageCommand.Execute(null);
			}
		}

		private void RefreshPageItems()
		{
			int num = SelectedPage ?? 1;
			if (num > MaxAllowedPage)
			{
				num = 1;
			}
			PageItems.Clear();
			if (_maxPage <= 9)
			{
				for (int i = 1; i <= _maxPage; i++)
				{
					PageItems.Add(new PageItem
					{
						Id = i
					});
				}
			}
			else
			{
				int num2 = 6;
				int num3 = _maxPage - 4 - 2;
				PageItems.Add(new PageItem
				{
					Id = 1
				});
				if (num < num2)
				{
					for (int j = 2; j <= 7; j++)
					{
						PageItems.Add(new PageItem
						{
							Id = j
						});
					}
					PageItems.Add(new PageItem
					{
						Id = 9,
						IsEllipsis = true
					});
				}
				else if (num > num3)
				{
					int num4 = _maxPage - 9 + 1;
					PageItems.Add(new PageItem
					{
						Id = num4,
						IsEllipsis = true
					});
					for (int k = 2; k <= 7; k++)
					{
						PageItems.Add(new PageItem
						{
							Id = num4 + k
						});
					}
				}
				else
				{
					PageItems.Add(new PageItem
					{
						Id = num - 2 - 2,
						IsEllipsis = true
					});
					for (int l = -2; l <= 2; l++)
					{
						PageItems.Add(new PageItem
						{
							Id = num + l
						});
					}
					PageItems.Add(new PageItem
					{
						Id = num + 2 + 2,
						IsEllipsis = true
					});
				}
				PageItems.Add(new PageItem
				{
					Id = _maxPage
				});
			}
			if (!SelectedPage.HasValue || SelectedPage.Value != num)
			{
				SelectedPage = num;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/pagingcontrol.xaml", UriKind.Relative);
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
				pageListBox = (ListBox)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class PageItem
	{
		public int Id { get; set; }

		public bool IsEllipsis { get; set; }

		public string Text
		{
			get
			{
				if (!IsEllipsis)
				{
					return Id.ToString();
				}
				return "...";
			}
		}
	}
	public class PubChemTabViewModel : INotifyPropertyChanged
	{
		private List<string> _allCompoundNames;

		private HashSet<PubChemCompound> _allValidCompounds;

		private readonly ConcurrentDictionary<int, List<PubChemCompound>> _allCompounds = new ConcurrentDictionary<int, List<PubChemCompound>>();

		private string searchText;

		private readonly ObservableCollection<PubChemCompound> compounds = new ObservableCollection<PubChemCompound>();

		private int maxAllowedPage = 1;

		private bool searchComplete = true;

		private bool loadComplete = true;

		private int? selectedPage;

		private string statusText = string.Empty;

		private MoleculeDrawingProxyHelper proxyHelper;

		private IList selectedComponents;

		private static readonly CancellationTokenSource cts = new CancellationTokenSource();

		private DelegateCommand<object> searchCommand;

		private DelegateCommand<object> addCommand;

		private DelegateCommand<object> viewCompoundCommand;

		public string SearchText
		{
			get
			{
				return searchText;
			}
			set
			{
				searchText = value;
				OnPropertyChanged("SearchText");
				(SearchCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ObservableCollection<PubChemCompound> Compounds => compounds;

		public int MaxAllowedPage
		{
			get
			{
				return maxAllowedPage;
			}
			set
			{
				maxAllowedPage = value;
				OnPropertyChanged("MaxAllowedPage");
			}
		}

		public bool SearchComplete
		{
			get
			{
				return searchComplete;
			}
			set
			{
				searchComplete = value;
				OnPropertyChanged("SearchComplete");
				(SearchCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public bool LoadComplete
		{
			get
			{
				return loadComplete;
			}
			set
			{
				loadComplete = value;
				OnPropertyChanged("LoadComplete");
			}
		}

		public int? SelectedPage
		{
			get
			{
				return selectedPage;
			}
			set
			{
				selectedPage = value;
				OnPropertyChanged("SelectedPage");
				if (selectedPage.HasValue && LoadComplete)
				{
					GotoPage(selectedPage.Value);
				}
			}
		}

		public int PageSize { get; } = 5;

		public bool? AddedSuccessfully { get; set; }

		public string StatusText
		{
			get
			{
				return statusText;
			}
			set
			{
				statusText = value;
				OnPropertyChanged("StatusText");
			}
		}

		private MoleculeDrawingProxyHelper ProxyHelper
		{
			get
			{
				if (proxyHelper == null)
				{
					proxyHelper = new MoleculeDrawingProxyHelper();
				}
				return proxyHelper;
			}
		}

		public IList SelectedComponents
		{
			get
			{
				return selectedComponents;
			}
			set
			{
				selectedComponents = value;
				OnPropertyChanged("SelectedComponents");
				(AddCommand as DelegateCommand<object>).RaiseCanExecuteChanged();
			}
		}

		public ICommand SearchCommand
		{
			get
			{
				if (searchCommand == null)
				{
					searchCommand = new DelegateCommand<object>(ExecuteSearchCommand, CanExecuteSearchCommand);
				}
				return searchCommand;
			}
		}

		public ICommand AddCommand
		{
			get
			{
				if (addCommand == null)
				{
					addCommand = new DelegateCommand<object>(ExecuteAddCommand, CanExecuteAddCommand);
				}
				return addCommand;
			}
		}

		public ICommand ViewCompoundCommand
		{
			get
			{
				if (viewCompoundCommand == null)
				{
					viewCompoundCommand = new DelegateCommand<object>(ExecuteViewCompoundCommand, CanExecuteViewCompoundCommand);
				}
				return viewCompoundCommand;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		protected void OnPropertyChanged([CallerMemberName] string name = null)
		{
			this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
		}

		private async void GotoPage(int pageId)
		{
			if (_allCompoundNames == null)
			{
				return;
			}
			try
			{
				LoadComplete = false;
				Compounds.Clear();
				if (_allCompounds.ContainsKey(pageId))
				{
					foreach (PubChemCompound item in _allCompounds[pageId])
					{
						Compounds.Add(item);
					}
				}
				else
				{
					int index = 0;
					if (pageId > 1)
					{
						index = _allCompounds[pageId - 1].ElementAt(PageSize - 1).Index + 1;
					}
					while (Compounds.Count < PageSize && index < _allCompoundNames.Count)
					{
						PubChemCompound pubChemCompound = await PubChemAgent.GetCompoundDataAsync(_allCompoundNames.ElementAt(index));
						if (pubChemCompound != null && !_allValidCompounds.Contains(pubChemCompound))
						{
							pubChemCompound.Index = index;
							Compounds.Add(pubChemCompound);
							_allValidCompounds.Add(pubChemCompound);
						}
						index++;
					}
					if (index < _allCompoundNames.Count)
					{
						MaxAllowedPage++;
					}
					_allCompounds.TryAdd(pageId, Compounds.ToList());
				}
				LoadComplete = true;
			}
			catch (Exception)
			{
				LoadComplete = true;
			}
		}

		private bool CanExecuteSearchCommand(object arg)
		{
			if (!string.IsNullOrEmpty(SearchText))
			{
				return SearchComplete;
			}
			return false;
		}

		private async void ExecuteSearchCommand(object arg)
		{
			try
			{
				SearchComplete = false;
				Compounds.Clear();
				MaxAllowedPage = 1;
				_allCompounds.Clear();
				StatusText = WpfFindComponentResources.Loading;
				_allCompoundNames = await PubChemAgent.SearchCompounds(SearchText);
				_allValidCompounds = new HashSet<PubChemCompound>();
				if (_allCompoundNames == null || _allCompoundNames.Count == 0)
				{
					StatusText = WpfFindComponentResources.NoMatch;
				}
				else
				{
					StatusText = string.Format(WpfFindComponentResources.PubChemMatchesFound, _allCompoundNames.Count);
				}
				SelectedPage = 1;
				SearchComplete = true;
			}
			catch (Exception)
			{
				SearchComplete = true;
			}
		}

		private bool CanExecuteAddCommand(object arg)
		{
			if (SelectedComponents != null)
			{
				return SelectedComponents.Count > 0;
			}
			return false;
		}

		private async void ExecuteAddCommand(object arg)
		{
			try
			{
				ProxyHelper.ImportCompounds(SelectedComponents);
				AddedSuccessfully = true;
			}
			catch (Exception)
			{
			}
		}

		private bool CanExecuteViewCompoundCommand(object arg)
		{
			if (SelectedComponents != null)
			{
				return SelectedComponents.Count > 0;
			}
			return false;
		}

		private void ExecuteViewCompoundCommand(object arg)
		{
			try
			{
				PubChemCompound pubChemCompound = SelectedComponents[0] as PubChemCompound;
				Process.Start($"https://pubchem.ncbi.nlm.nih.gov/compound/{pubChemCompound.CID}");
			}
			catch (Exception)
			{
			}
		}
	}
	public class PubChemCompound : IEquatable<object>
	{
		public int Index { get; set; }

		public string Name { get; set; }

		public int CID { get; set; }

		public string MolecularFormula { get; set; }

		public string MolecularWeight { get; set; }

		public string CanonicalSMILES { get; set; }

		public string IsomericSMILES { get; set; }

		public string InChI { get; set; }

		public string InChIKey { get; set; }

		public string IUPACName { get; set; }

		public string Title { get; set; }

		public BitmapImage Image { get; set; }

		public override bool Equals(object other)
		{
			if (other == null)
			{
				return false;
			}
			if (this == other)
			{
				return true;
			}
			if (other is PubChemCompound pubChemCompound)
			{
				if (CID == pubChemCompound.CID)
				{
					return InChIKey == pubChemCompound.InChIKey;
				}
				return false;
			}
			return false;
		}

		public override int GetHashCode()
		{
			return CID.GetHashCode() ^ InChIKey.GetHashCode();
		}
	}
	public class MoleculeDrawingProxyHelper
	{
		private IUnityContainer _container;

		private readonly MMViewModel _viewModel;

		private IMoleculeDrawingProxy moleDrawProxy;

		private IMoleculeDrawingProxy MoleDrawProxy
		{
			get
			{
				if (moleDrawProxy == null && _container != null)
				{
					moleDrawProxy = _container.Resolve<IMoleculeDrawingProxy>(Array.Empty<ResolverOverride>());
				}
				return moleDrawProxy;
			}
		}

		public MoleculeDrawingProxyHelper()
		{
			_container = FindComponentModule.Container;
			_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
		}

		public void ImportMolStructure(string compId, string smiles)
		{
			string[] molStrings = MoleDrawProxy.GenerateMolStringsFromSMILES(smiles);
			SaveMolStructure(compId, molStrings);
			CalcBonds(compId, molStrings);
		}

		private void SaveMolStructure(string compId, string[] molStrings)
		{
			if (molStrings == null)
			{
				return;
			}
			string text = string.Join(Environment.NewLine, molStrings);
			if (!string.IsNullOrEmpty(text))
			{
				text = MoleDrawProxy.CompressText(text);
			}
			List<string> list = SplitCompressedTextIntoLines(text);
			string text2 = "Top.appModelV8.Properties.Molecular Structure." + compId + ".Input.MOLSTRUCT";
			int num = CxsConverter.ValueToInt32(_viewModel.ExpandDataPathAndGet(text2, "child_count")) ?? 0;
			if (num > 0)
			{
				for (int num2 = num - 1; num2 >= 0; num2--)
				{
					_viewModel.DeleteChild(text2, num2);
				}
			}
			for (int i = 0; i < list.Count; i++)
			{
				_viewModel.AddChild(text2, i);
				_viewModel.ExpandDataPathAndSet($"{text2}.#{i}", "value", list[i]);
			}
		}

		private List<string> SplitCompressedTextIntoLines(string input)
		{
			List<string> list = new List<string>();
			if (!string.IsNullOrEmpty(input))
			{
				for (int i = 0; i < input.Length; i += 80)
				{
					int num = Math.Min(i + 80 - 1, input.Length - 1);
					string item = input.Substring(i, num - i + 1);
					list.Add(item);
				}
			}
			return list;
		}

		private void CalcBonds(string compId, string[] molStrings)
		{
			if (molStrings == null)
			{
				return;
			}
			MoleDrawProxy.GenerateConnectionTable(molStrings, out var startAtomIndexes, out var endAtomIndexes, out var startAtomSymbols, out var endAtomSymbols, out var bondTypes, out var formulaAtomSymbols, out var formularAtomCounts);
			string text = "Top.appModelV8.Properties.Molecular Structure." + compId + ".Input";
			string[] array = CxsConverter.ValueToStringArray(_viewModel.ExpandDataPathAndGet(text + ".NOATOM", "child_ids"));
			if (array != null)
			{
				_viewModel.DeleteChildren(text + ".NOATOM", array, silently: true);
			}
			if (formulaAtomSymbols != null && formularAtomCounts != null && formulaAtomSymbols.Length == formularAtomCounts.Length)
			{
				for (int i = 0; i < formulaAtomSymbols.Length; i++)
				{
					_viewModel.AddChild(text + ".NOATOM", i);
					_viewModel.ExpandDataPathAndSet($"{text}.NOATOM.#{i}", "value", formularAtomCounts[i]);
					_viewModel.ExpandDataPathAndSet($"{text}.NOATOM.#{i}", "id", formulaAtomSymbols[i].ToUpperInvariant());
				}
			}
			array = CxsConverter.ValueToStringArray(_viewModel.ExpandDataPathAndGet(text + ".DISPATOM1", "child_ids"));
			if (array != null)
			{
				_viewModel.DeleteChildren(text + ".DISPATOM1", array, silently: true);
			}
			if (startAtomIndexes == null || endAtomIndexes == null || startAtomSymbols == null || endAtomSymbols == null || bondTypes == null)
			{
				return;
			}
			int num = startAtomIndexes.Length;
			if (endAtomIndexes.Length != num || startAtomSymbols.Length != num || endAtomSymbols.Length != num || bondTypes.Length != num)
			{
				return;
			}
			for (int j = 0; j < num; j++)
			{
				_viewModel.AddChild(text + ".DISPATOM1", j);
				_viewModel.ExpandDataPathAndSet($"{text}.ATOM1.#{j}", "value", startAtomIndexes[j]);
				_viewModel.ExpandDataPathAndSet($"{text}.DISPATOM1.#{j}", "value", startAtomSymbols[j].ToUpperInvariant());
				_viewModel.ExpandDataPathAndSet($"{text}.ATOM2.#{j}", "value", endAtomIndexes[j]);
				_viewModel.ExpandDataPathAndSet($"{text}.DISPATOM2.#{j}", "value", endAtomSymbols[j].ToUpperInvariant());
				int num2 = bondTypes[j];
				string text2 = string.Empty;
				switch (num2)
				{
				case 1:
					text2 = "S";
					break;
				case 2:
					text2 = "D";
					break;
				case 3:
					text2 = "T";
					break;
				}
				_viewModel.ExpandDataPathAndSet($"{text}.BONDTYPE.#{j}", "value", text2.ToUpperInvariant());
			}
		}

		public void ImportCompounds(IEnumerable compounds)
		{
			string text = "Top.appModelV8.Components.Specifications.Input.TYPE";
			string[] array = CxsConverter.ValueToStringArray(FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>()).ExpandDataPathAndGet(text, "child_ids"));
			int num = ((array != null) ? array.Length : 0);
			List<string> list = new List<string>();
			if (array != null)
			{
				list.AddRange(array);
			}
			foreach (PubChemCompound compound in compounds)
			{
				_viewModel.InvokeAction(text, "InsertChild", true, num.ToString());
				string defaultName = GetDefaultName(list);
				if (_viewModel.ExpandDataPathAndSet(text + $".#{num++}", "id", defaultName))
				{
					list.Add(defaultName);
					ImportMolStructure(defaultName, compound.IsomericSMILES);
				}
			}
		}

		private string GetDefaultName(List<string> existingNames)
		{
			int num = 1;
			string empty = string.Empty;
			do
			{
				empty = $"PUG-{num}";
				num++;
			}
			while (num <= 9999 && existingNames != null && existingNames.Contains(empty));
			return empty;
		}
	}
	public class PubChemAgent
	{
		internal class Status
		{
			public int Code { get; set; }
		}

		internal class DictionaryTerms
		{
			public List<string> Compound { get; set; }
		}

		internal class QueryModel
		{
			public Status Statuse { get; set; }

			public int Total { get; set; }

			public DictionaryTerms Dictionary_Terms { get; set; }
		}

		internal class PropertyTable
		{
			public List<PropertyValues> Properties { get; set; }
		}

		internal class PropertyValues
		{
			public int CID { get; set; }

			public string MolecularFormula { get; set; }

			public string MolecularWeight { get; set; }

			public string CanonicalSMILES { get; set; }

			public string IsomericSMILES { get; set; }

			public string InChI { get; set; }

			public string InChIKey { get; set; }

			public string IUPACName { get; set; }

			public string Title { get; set; }
		}

		internal class CompoundModel
		{
			public PropertyTable PropertyTable { get; set; }
		}

		private static readonly HttpClient ApiClient;

		private const string BaseURL = "https://pubchem.ncbi.nlm.nih.gov/";

		static PubChemAgent()
		{
			ApiClient = new HttpClient();
			ApiClient.BaseAddress = new Uri("https://pubchem.ncbi.nlm.nih.gov/");
			ApiClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
		}

		private static async Task<T> ReadContentAsAsync<T>(string url) where T : class
		{
			int attempts = 0;
			int max_attempts = 3;
			T result = null;
			while (attempts < max_attempts)
			{
				using (HttpResponseMessage response = await ApiClient.GetAsync(url))
				{
					if (response.IsSuccessStatusCode)
					{
						result = ((!(typeof(T) == typeof(byte[]))) ? (await response.Content.ReadAsAsync<T>()) : ((await response.Content.ReadAsByteArrayAsync()) as T));
					}
					else if (HttpStatusCode.ServiceUnavailable == response.StatusCode)
					{
						int num = attempts + 1;
						attempts = num;
						Thread.Sleep(250);
						continue;
					}
				}
				break;
			}
			return result;
		}

		public static async Task<List<string>> SearchCompounds(string query)
		{
			if (string.IsNullOrEmpty(query))
			{
				throw new ArgumentNullException("query");
			}
			List<string> compounds = new List<string>();
			if (query.Any((char x) => x != ' ' || !char.IsDigit(x)))
			{
				string[] array = query.Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
				string[] array2 = array;
				foreach (string cid in array2)
				{
					if (!compounds.Contains(cid))
					{
						CompoundModel compoundModel = await ReadContentAsAsync<CompoundModel>("rest/pug/compound/cid/" + cid + "/property/Title/JSON");
						if (compoundModel != null && compoundModel.PropertyTable.Properties.Count == 1)
						{
							compoundModel.PropertyTable.Properties.FirstOrDefault();
							compounds.Add(cid);
						}
					}
				}
			}
			int num2 = 1000;
			num2 = ((compounds.Count != 0) ? (num2 - compounds.Count) : num2);
			List<string> list = (await ReadContentAsAsync<QueryModel>($"rest/autocomplete/compound/{query}/json?limit={num2}")).Dictionary_Terms?.Compound;
			if (list != null)
			{
				compounds = compounds.Concat(list).ToList();
			}
			return compounds;
		}

		public static async Task<PubChemCompound> GetCompoundDataAsync(string nameOrCid)
		{
			if (string.IsNullOrWhiteSpace(nameOrCid))
			{
				throw new ArgumentNullException("nameOrCid");
			}
			PubChemCompound compound = null;
			string url = (long.TryParse(nameOrCid, out var result) ? ($"rest/pug/compound/cid/{result}/property/" + "MolecularFormula,MolecularWeight,IUPACName,CanonicalSMILES,IsomericSMILES,InChI,InChIKey,Title/JSON") : ("rest/pug/compound/name/" + nameOrCid + "/property/MolecularFormula,MolecularWeight,IUPACName,CanonicalSMILES,IsomericSMILES,InChI,InChIKey,Title/JSON"));
			CompoundModel compoundModel = await ReadContentAsAsync<CompoundModel>(url);
			if (compoundModel != null && compoundModel.PropertyTable.Properties.Count > 0)
			{
				PropertyValues propertyValues = compoundModel.PropertyTable.Properties.FirstOrDefault();
				compound = new PubChemCompound
				{
					CID = propertyValues.CID,
					Name = nameOrCid,
					MolecularFormula = propertyValues.MolecularFormula,
					MolecularWeight = propertyValues.MolecularWeight,
					IUPACName = propertyValues.IUPACName,
					CanonicalSMILES = propertyValues.CanonicalSMILES,
					IsomericSMILES = propertyValues.IsomericSMILES,
					InChI = propertyValues.InChI,
					InChIKey = propertyValues.InChIKey,
					Title = propertyValues.Title
				};
			}
			if (compound != null)
			{
				if (compound.CID == 6209)
				{
					compound.IsomericSMILES = "CN(CCO)(Cl)(C)C";
				}
				url = $"rest/pug/compound/cid/{compound.CID}/PNG";
				byte[] buffer = await ReadContentAsAsync<byte[]>(url);
				BitmapImage bitmapImage = new BitmapImage();
				using (MemoryStream memoryStream = new MemoryStream(buffer))
				{
					memoryStream.Position = 0L;
					bitmapImage.BeginInit();
					bitmapImage.CreateOptions = BitmapCreateOptions.PreservePixelFormat;
					bitmapImage.CacheOption = BitmapCacheOption.OnLoad;
					bitmapImage.StreamSource = memoryStream;
					bitmapImage.EndInit();
				}
				compound.Image = bitmapImage;
			}
			return compound;
		}
	}
	public class PubChemTab : UserControl, IComponentConnector
	{
		internal Button searchButton;

		private bool _contentLoaded;

		public PubChemTab()
		{
			InitializeComponent();
			base.DataContext = new PubChemTabViewModel();
		}

		private void SearchTextBox_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.Key == Key.Return && searchButton.Command.CanExecute(null))
			{
				searchButton.Command.Execute(null);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/pubchemtab.xaml", UriKind.Relative);
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
				((TextBox)target).KeyDown += SearchTextBox_KeyDown;
				break;
			case 2:
				searchButton = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ReorderComp : Window, IComponentConnector
	{
		internal ReorderComp reorderCompWindow;

		internal ListBox lvSelectedComps;

		internal Button btnUp;

		internal Button btnDown;

		internal Button btnOK;

		internal Button btnClose;

		private bool _contentLoaded;

		public ICommand MoveUpCommand { get; }

		public ICommand MoveDownCommand { get; }

		public ICommand OKCommand { get; }

		public ICommand CancelCommand { get; }

		public ObservableCollection<string> Components { get; } = new ObservableCollection<string>();

		private List<string> OriginalComponents { get; } = new List<string>();

		private IList SelectedComponents => lvSelectedComps.SelectedItems;

		private List<(string ComponentA, string ComponentB)> MovingHistory { get; } = new List<(string, string)>();

		public ReorderComp()
		{
			InitializeComponent();
			MoveUpCommand = new RelayActionCommand<object>(MoveUpCommand_Executed, MoveUpCommand_CanExecute);
			MoveDownCommand = new RelayActionCommand<object>(MoveDownCommand_Executed, MoveDownCommand_CanExecute);
			OKCommand = new RelayActionCommand<object>(OKCommand_Executed, OKCommand_CanExecute);
			CancelCommand = new RelayActionCommand<object>(CancelCommand_Executed, CancelCommand_CanExecute);
			LoadComponents();
		}

		private void LoadComponents()
		{
			Components.Clear();
			string nextcomp = string.Empty;
			SmgeHelper.ListUserDefCompM(ref nextcomp, 1);
			while (!string.IsNullOrEmpty(nextcomp))
			{
				Components.Add(nextcomp);
				SmgeHelper.ListUserDefCompM(ref nextcomp, 0);
			}
			OriginalComponents.Clear();
			OriginalComponents.AddRange(Components);
		}

		public void InitialSelectedComponent(string initialSelectedComponent)
		{
			if (!string.IsNullOrWhiteSpace(initialSelectedComponent) && Components.Contains(initialSelectedComponent))
			{
				lvSelectedComps.SelectedItems.Add(initialSelectedComponent);
				lvSelectedComps.ScrollIntoView(initialSelectedComponent);
			}
		}

		private void MoveUpCommand_Executed(object parameter)
		{
			int num = 0;
			IEnumerable<(string, int)> enumerable = from string x in SelectedComponents
				let index = Components.IndexOf(x)
				orderby index
				select (Component: x, Index: index);
			foreach (var item in enumerable)
			{
				if (item.Item2 > num)
				{
					MoveComponent(item.Item2, item.Item2 - 1);
					num = item.Item2;
				}
				else
				{
					num = item.Item2 + 1;
				}
			}
			lvSelectedComps.ScrollIntoView(enumerable.First().Item1);
		}

		private bool MoveUpCommand_CanExecute(object parameter)
		{
			return SumSelectedComponentsIndexes() > SumMinIndexes(SelectedComponents.Count);
		}

		private void MoveDownCommand_Executed(object parameter)
		{
			int num = Components.Count - 1;
			IEnumerable<(string, int)> enumerable = from string x in SelectedComponents
				let index = Components.IndexOf(x)
				orderby index descending
				select (Component: x, Index: index);
			foreach (var item in enumerable)
			{
				if (item.Item2 < num)
				{
					MoveComponent(item.Item2, item.Item2 + 1);
					num = item.Item2;
				}
				else
				{
					num = item.Item2 - 1;
				}
			}
			lvSelectedComps.ScrollIntoView(enumerable.First().Item1);
		}

		private bool MoveDownCommand_CanExecute(object parameter)
		{
			return SumSelectedComponentsIndexes() < SumMaxIndexes(SelectedComponents.Count, Components.Count);
		}

		private void OKCommand_Executed(object parameter)
		{
			if (!Components.SequenceEqual(OriginalComponents))
			{
				foreach (var item in MovingHistory)
				{
					var (cid, cid2) = item;
					SmgeHelper.SMreorderM(ref cid, ref cid2);
				}
			}
			Close();
		}

		private bool OKCommand_CanExecute(object parameter)
		{
			return true;
		}

		private void CancelCommand_Executed(object parameter)
		{
			Close();
		}

		private bool CancelCommand_CanExecute(object parameter)
		{
			return true;
		}

		private void MoveComponent(int fromIndex, int toIndex)
		{
			string item = Components[fromIndex];
			string item2 = Components[toIndex];
			MovingHistory.Add((item, item2));
			Components.Move(fromIndex, toIndex);
		}

		private int SumSelectedComponentsIndexes()
		{
			int num = 0;
			foreach (string selectedComponent in SelectedComponents)
			{
				int num2 = Components.IndexOf(selectedComponent);
				if (num2 >= 0)
				{
					num += num2;
				}
			}
			return num;
		}

		private static int SumMinIndexes(int indexCount)
		{
			int num = 0;
			for (int i = 0; i < indexCount; i++)
			{
				num += i;
			}
			return num;
		}

		private static int SumMaxIndexes(int indexCount, int totalCount)
		{
			int num = 0;
			int num2 = totalCount - indexCount;
			for (int num3 = totalCount - 1; num3 >= num2; num3--)
			{
				num += num3;
			}
			return num;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/reordercomp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				reorderCompWindow = (ReorderComp)target;
				break;
			case 2:
				lvSelectedComps = (ListBox)target;
				break;
			case 3:
				btnUp = (Button)target;
				break;
			case 4:
				btnDown = (Button)target;
				break;
			case 5:
				btnOK = (Button)target;
				break;
			case 6:
				btnClose = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SFEAssistantViewModel : INotifyPropertyChanged
	{
		private string _chempath = "";

		private string _saltcalckeqpath = "";

		private MMViewModel _viewModel;

		private static int dbankmsgs;

		private string _componentid = "componentid";

		private string _promptmessage = "desName";

		private string _chemName = "";

		private string _existchemName = "";

		private bool _isNewChemistryChecked = true;

		private bool _isExistChemistryChecked;

		private List<string> _existingchemistryList = new List<string>();

		private DelegateCommand<object> _commandOnOK;

		private DelegateCommand<object> _commandOnCancel;

		private IUnityContainer UnityContainer { get; set; }

		public string Componentid
		{
			get
			{
				return _componentid;
			}
			set
			{
				_componentid = value;
				_promptmessage = value;
				OnPropertyChanged("Componentid");
			}
		}

		public string Promptmessage
		{
			get
			{
				return _promptmessage;
			}
			set
			{
				_promptmessage = value;
				OnPropertyChanged("Promptmessage");
			}
		}

		public string ChemName
		{
			get
			{
				return _chemName;
			}
			set
			{
				_chemName = value;
				OnPropertyChanged("ChemName");
			}
		}

		public string ExistChemName
		{
			get
			{
				return _existchemName;
			}
			set
			{
				_existchemName = value;
				OnPropertyChanged("ExistChemName");
			}
		}

		public bool IsNewChemistryChecked
		{
			get
			{
				return _isNewChemistryChecked;
			}
			set
			{
				_isNewChemistryChecked = value;
				OnPropertyChanged("IsNewChemistryChecked");
			}
		}

		public bool IsExistChemistryChecked
		{
			get
			{
				return _isExistChemistryChecked;
			}
			set
			{
				_isExistChemistryChecked = value;
				OnPropertyChanged("IsExistChemistryChecked");
			}
		}

		public List<string> ExistingChemistry
		{
			get
			{
				return _existingchemistryList;
			}
			set
			{
				_existingchemistryList = value;
				OnPropertyChanged("ExistingChemistry");
			}
		}

		public ICommand CommandOnOK
		{
			get
			{
				if (_commandOnOK == null)
				{
					_commandOnOK = new DelegateCommand<object>(ExecuteCommandOnOK);
				}
				return _commandOnOK;
			}
		}

		public ICommand CommandOnCancel
		{
			get
			{
				if (_commandOnCancel == null)
				{
					_commandOnCancel = new DelegateCommand<object>(ExecuteCommandOnCancel);
				}
				return _commandOnCancel;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private List<string> getListValue(object components)
		{
			List<string> list = new List<string>();
			Collection<string> collection = CxsConverter.ValueToStringCollection(components);
			if (collection != null)
			{
				foreach (string item in collection)
				{
					list.Add(item);
				}
			}
			return list;
		}

		public SFEAssistantViewModel(IUnityContainer container)
		{
			try
			{
				UnityContainer = container;
				dbankmsgs = 0;
				dbankmsgs |= 6;
				_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
				Collection<string> collection = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet("Top.appModelV8.Reactions.Chemistry", "child_ids"));
				if (collection == null)
				{
					return;
				}
				foreach (string item in collection)
				{
					_existingchemistryList.Add(item);
				}
				ExistChemName = collection[0].ToString().Trim();
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		private static void ResetAll()
		{
			SmgeHelper.SetAllSpecsSelected(2, 0);
			SmgeHelper.SetAllSpecsSelected(3, 0);
			SmgeHelper.SetAllRxnsSelected(0);
		}

		private void GenerateChemisty(string chemistryname)
		{
			SmgeHelper.WriteChemRecordM(chemistryname.Trim().ToUpper(), ref dbankmsgs, 0, 1, 1);
			_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
			_chempath = $"Top.appModelV8.Reactions.Chemistry.{chemistryname.Trim().ToUpper()}.Input.CALC_KEQ";
			Collection<string> collection = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet(_chempath, "child_ids"));
			if (collection != null)
			{
				foreach (string item in collection)
				{
					_saltcalckeqpath = $"Top.appModelV8.Reactions.Chemistry.{chemistryname.Trim().ToUpper()}.Input.CALC_KEQ.{item}";
					Collection<string> collection2 = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet(_saltcalckeqpath, "option_list"));
					if (collection2 != null)
					{
						string value = collection2[1].ToString();
						_viewModel.ExpandDataPathAndSet(_saltcalckeqpath, "value", value);
					}
				}
			}
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
		}

		private void ExecuteCommandOnOK(object arg)
		{
			Window window = arg as Window;
			try
			{
				if (IsNewChemistryChecked)
				{
					if (string.IsNullOrEmpty(ChemName.Trim().ToUpper()))
					{
						MMMessageBox.Show(WpfFindComponentResources.ChemistryNameMessage, WpfFindComponentResources.SFEAssistantTitle);
						return;
					}
					if (SmgeHelper.HasChemRecordM(ChemName.Trim().ToUpper()) == 0)
					{
						GenerateChemisty(ChemName.Trim().ToUpper());
						window.Close();
						return;
					}
					MMMessageBoxResult mMMessageBoxResult = MMMessageBox.Show(string.Format(WpfFindComponentResources.ChemistryExists, ChemName.Trim().ToUpper()), WpfFindComponentResources.ChemistryExistsTitle, MMMessageBoxButton.YesNoCancel, MMMessageBoxImage.Question);
					if (mMMessageBoxResult != MMMessageBoxResult.Cancel && mMMessageBoxResult != MMMessageBoxResult.No && mMMessageBoxResult == MMMessageBoxResult.Yes)
					{
						GenerateChemisty(ChemName.Trim().ToUpper());
						window.Close();
					}
				}
				else
				{
					GenerateChemisty(ExistChemName.Trim().ToUpper());
					window.Close();
				}
			}
			catch (Exception ex)
			{
				_ = ex.Message;
				ResetAll();
				SmgeHelper.ClearAllocatedRxnSpaceM();
				window.Close();
			}
		}

		private void ExecuteCommandOnCancel(object arg)
		{
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			(arg as Window).Close();
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}
	}
	public class SFEAssistantMain : Window, IComponentConnector
	{
		public static int localUsedAped;

		private bool _isOKVisable;

		public ObservableCollection<SFEComponentData> arraySelectedComponent = new ObservableCollection<SFEComponentData>();

		internal WizardControl theWizard;

		internal Button buttonCancel;

		internal Button cmdBack;

		internal Button cmdForward;

		internal Button cmdOK;

		private bool _contentLoaded;

		public bool IsOKVisable
		{
			get
			{
				return _isOKVisable;
			}
			set
			{
				_isOKVisable = value;
				if (_isOKVisable)
				{
					cmdOK.Visibility = Visibility.Visible;
					cmdBack.Visibility = Visibility.Visible;
					cmdForward.Visibility = Visibility.Collapsed;
				}
				else
				{
					cmdOK.Visibility = Visibility.Collapsed;
					cmdBack.Visibility = Visibility.Visible;
					cmdForward.Visibility = Visibility.Visible;
				}
			}
		}

		public SFEAssistantMain(int localUseAped)
		{
			SFEAssistantStep1 item = new SFEAssistantStep1(this);
			SFEAssistantStep2 item2 = new SFEAssistantStep2(this);
			Application.Current.Properties["isOKVisable"] = "false";
			localUsedAped = localUseAped;
			InitializeComponent();
			theWizard.Items.Add(item);
			theWizard.Items.Add(item2);
			IsOKVisable = false;
		}

		public static void ResetAll()
		{
			SmgeHelper.SetAllSpecsSelected(2, 0);
			SmgeHelper.SetAllSpecsSelected(3, 0);
			SmgeHelper.SetAllRxnsSelected(0);
		}

		private void theWizard_Finished(object sender, RoutedEventArgs e)
		{
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/sfeassistantmain.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				theWizard = (WizardControl)target;
				theWizard.Finished += theWizard_Finished;
				break;
			case 2:
				buttonCancel = (Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			case 3:
				cmdBack = (Button)target;
				break;
			case 4:
				cmdForward = (Button)target;
				break;
			case 5:
				cmdOK = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SFEComponentData
	{
		public string ComponentID { get; set; }

		public string ComponentName { get; set; }

		public string ComponentAlias { get; set; }

		public string ComponentDes { get; set; }

		public string SolidID { get; set; }
	}
	public class SFEAssistantStep1 : WizardControlItem, IComponentConnector
	{
		private ObservableCollection<SFEComponentData> arrayAvailableComponent = new ObservableCollection<SFEComponentData>();

		private ObservableCollection<SFEComponentData> arraySelectedComponent = new ObservableCollection<SFEComponentData>();

		private int _setbasecomps;

		private int _totalbcomp;

		private bool _hasLoaded;

		private MMViewModel _viewModel;

		private SFEAssistantMain sfeass;

		public int Reactions;

		public List<string> Componentnames = new List<string>();

		private bool _isVisable;

		internal ListBox lstAvailableComp;

		internal Button btnMove;

		internal Button btnMoveAll;

		internal Button btnRemove;

		internal Button btnClearAll;

		internal ListBox lstSelectedComp;

		private bool _contentLoaded;

		public bool IsVisable
		{
			get
			{
				return _isVisable;
			}
			set
			{
				_isVisable = value;
			}
		}

		public SFEAssistantStep1(SFEAssistantMain sfe)
		{
			sfeass = sfe;
			InitializeComponent();
			base.Loaded += SFEAssistantStep1_Loaded;
		}

		private void SFEAssistantStep1_Loaded(object sender, RoutedEventArgs e)
		{
			try
			{
				InitializeComponent();
				string[] reacBankArr = new string[SmgeHelper.GetTotalNumberOfReacDatabanksM()];
				SmgeHelper.GetReacDatabanksListM(ref reacBankArr);
				if (reacBankArr.Length != 0)
				{
					Array.Sort(reacBankArr);
					Array.Reverse(reacBankArr);
				}
				SmgeHelper.GetReacDatabankM(reacBankArr[0], 1);
				SmgeHelper.SetGenNewCompsM(1);
				if (SmgeHelper.GetBaseCompsM() == 0)
				{
					return;
				}
				_setbasecomps = 1;
				if (!_hasLoaded)
				{
					btnClearAll.IsEnabled = false;
					btnRemove.IsEnabled = false;
					IList<string> avialbleComps;
					int totalbcomp = SmgeHelper.CollectBaseAvailComponentsM(out avialbleComps);
					_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
					Collection<string> collection = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet("Top.appModelV8.Components.Specifications.Input.TYPE", "child_ids"));
					if (collection != null)
					{
						foreach (string item in collection)
						{
							SFEComponentData sFEComponentData = new SFEComponentData();
							sFEComponentData.ComponentID = item;
							string dataPath = $"Top.appModelV8.Components.Specifications.Input.TYPE.{item}";
							string strA = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath, "value"));
							if (string.Compare(strA, "CONV") == 0 || string.Compare(strA, "PSEUDO") == 0 || string.Compare(strA, "OLIGOMER") == 0)
							{
								string dataPath2 = $"Top.appModelV8.Components.Specifications.Input.DBNAME1.{item}";
								string arg = (sFEComponentData.ComponentName = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath2, "value")));
								dataPath2 = $"Top.appModelV8.Components.Specifications.Input.ANAME1.{item}";
								string arg2 = (sFEComponentData.ComponentAlias = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath2, "value")));
								sFEComponentData.ComponentDes = $"{arg2}  {arg}";
								arrayAvailableComponent.Add(sFEComponentData);
							}
						}
					}
					lstSelectedComp.Items.Clear();
					_totalbcomp = totalbcomp;
					_hasLoaded = true;
				}
				else
				{
					SmgeHelper.SetAllSpecsSelected(1, 0);
					int count = lstSelectedComp.Items.Count;
					for (int i = 0; i < count; i++)
					{
						SmgeHelper.SetSpecsSelected(arraySelectedComponent[i].ComponentAlias, 1, 1);
					}
					UpdateButtonsStatus();
				}
				lstAvailableComp.SelectedIndex = 0;
				Update();
				lstAvailableComp.ItemsSource = arrayAvailableComponent;
				lstSelectedComp.ItemsSource = arraySelectedComponent;
				base.CanForward = true;
				base.CanCancel = true;
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			if (lstSelectedComp.Items.Count == 0)
			{
				MMMessageBox.Show(WpfFindComponentResources.SFEAssistant_MissingComponent, WpfFindComponentResources.SFEAssistantTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return false;
			}
			SFEAssistantStep2.g_arraySelectedComponent = arraySelectedComponent;
			IsVisable = true;
			base.CanFinish = true;
			base.CanBackward = true;
			base.CanForward = false;
			sfeass.IsOKVisable = true;
			return base.OnForward(targetItem);
		}

		private void UpdateButtonsStatus()
		{
			if (lstAvailableComp.Items.Count > 0)
			{
				btnMove.IsEnabled = true;
				btnMoveAll.IsEnabled = true;
			}
			else
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
			}
			if (lstSelectedComp.Items.Count > 0)
			{
				btnRemove.IsEnabled = true;
				btnClearAll.IsEnabled = true;
			}
			else
			{
				btnRemove.IsEnabled = false;
				btnClearAll.IsEnabled = false;
			}
		}

		private void btnRemove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || arraySelectedComponent.Count <= 0)
			{
				return;
			}
			int count = arraySelectedComponent.Count;
			ObservableCollection<SFEComponentData> observableCollection = new ObservableCollection<SFEComponentData>();
			foreach (SFEComponentData selectedItem in lstSelectedComp.SelectedItems)
			{
				string componentID = selectedItem.ComponentID;
				if (componentID.Equals("H2O") && count == 1)
				{
					MMMessageBox.Show(WpfFindComponentResources.H2O_Message, WpfFindComponentResources.SFEAssistantTitle);
					continue;
				}
				observableCollection.Add(selectedItem);
				if (!CheckBufFromAveComponents(componentID))
				{
					arrayAvailableComponent.Add(selectedItem);
					lstAvailableComp.SelectedItem = componentID;
				}
			}
			int num = 0;
			foreach (SFEComponentData item in observableCollection)
			{
				num = lstSelectedComp.Items.IndexOf(item);
				arraySelectedComponent.Remove(item);
			}
			int count2 = lstSelectedComp.Items.Count;
			if (num < count2)
			{
				lstSelectedComp.SelectedIndex = num;
			}
			else if (count2 > 0)
			{
				lstSelectedComp.SelectedIndex = count2 - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private bool FindSelectedStrings(string str)
		{
			if (arraySelectedComponent.Count > 0)
			{
				foreach (SFEComponentData item in arraySelectedComponent)
				{
					if (item.ComponentID.Equals(str))
					{
						return true;
					}
				}
			}
			return false;
		}

		private void btnMove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || arrayAvailableComponent.Count < 1)
			{
				return;
			}
			ObservableCollection<SFEComponentData> observableCollection = new ObservableCollection<SFEComponentData>();
			foreach (SFEComponentData selectedItem in lstAvailableComp.SelectedItems)
			{
				string str = selectedItem.ComponentID.ToString();
				observableCollection.Add(selectedItem);
				if (!FindSelectedStrings(str))
				{
					arraySelectedComponent.Add(selectedItem);
					lstSelectedComp.SelectedItem = selectedItem;
				}
			}
			int num = 0;
			foreach (SFEComponentData item in observableCollection)
			{
				num = lstAvailableComp.Items.IndexOf(item);
				arrayAvailableComponent.Remove(item);
			}
			int count = lstAvailableComp.Items.Count;
			if (num < count)
			{
				lstAvailableComp.SelectedIndex = num;
			}
			else if (count > 0)
			{
				lstAvailableComp.SelectedIndex = count - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private void btnMoveAll_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0)
			{
				return;
			}
			if (lstAvailableComp.Items.Count <= 0)
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
				return;
			}
			foreach (SFEComponentData item in (IEnumerable)lstAvailableComp.Items)
			{
				if (!CheckBufFromSelComponents(item.ComponentID))
				{
					arraySelectedComponent.Add(item);
				}
			}
			arrayAvailableComponent.Clear();
			UpdateButtonsStatus();
			lstSelectedComp.SelectedIndex = 0;
			lstSelectedComp.Focus();
			Update();
		}

		private void btnClearAll_Click(object sender, RoutedEventArgs e)
		{
			foreach (SFEComponentData item in arraySelectedComponent)
			{
				arrayAvailableComponent.Add(item);
			}
			arraySelectedComponent.Clear();
			btnClearAll.IsEnabled = false;
			UpdateButtonsStatus();
			lstAvailableComp.Focus();
			if (arraySelectedComponent.Count > 0)
			{
				lstAvailableComp.SelectedIndex = 0;
			}
		}

		private void lstAvailableComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnMove_Click(sender, e);
					break;
				}
			}
		}

		private void lstSelectedComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnRemove_Click(sender, e);
					break;
				}
			}
		}

		private bool CheckBufFromSelComponents(string str)
		{
			return lstSelectedComp.Items.Contains(str);
		}

		private bool CheckBufFromAveComponents(string str)
		{
			return lstAvailableComp.Items.Contains(str);
		}

		private void Update()
		{
			SmgeHelper.ClearAllocatedRxnSpaceM();
			SmgeHelper.SetHydroniumIsH_M(1);
			SmgeHelper.SetIncludeSaltM(1);
			SmgeHelper.RxnInitM();
			SmgeHelper.GenRxnsAfreshM();
			Reactions = ((SmgeHelper.GetNumRxnsPossibleM() != 0) ? 1 : 0);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/sfeassistantstep1.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lstAvailableComp = (ListBox)target;
				lstAvailableComp.MouseDoubleClick += lstAvailableComp_MouseDoubleClick;
				break;
			case 2:
				btnMove = (Button)target;
				btnMove.Click += btnMove_Click;
				break;
			case 3:
				btnMoveAll = (Button)target;
				btnMoveAll.Click += btnMoveAll_Click;
				break;
			case 4:
				btnRemove = (Button)target;
				btnRemove.Click += btnRemove_Click;
				break;
			case 5:
				btnClearAll = (Button)target;
				btnClearAll.Click += btnClearAll_Click;
				break;
			case 6:
				lstSelectedComp = (ListBox)target;
				lstSelectedComp.MouseDoubleClick += lstSelectedComp_MouseDoubleClick;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SFEAssistantStep2 : WizardControlItem, INotifyPropertyChanged, IComponentConnector, IStyleConnector
	{
		private int tbTextLength = 8;

		private bool _hasLoaded;

		private MMViewModel _viewModel;

		private static int dbankmsgs = 0;

		private bool _isglobalchecked;

		private string _globalChemistry = "";

		private string _chemistrypath = "";

		private int _productType = 1;

		private SFEAssistantMain sfeass;

		public static ObservableCollection<SFEComponentData> g_arraySelectedComponent = new ObservableCollection<SFEComponentData>();

		public ObservableCollection<SFEComponentData> solidComponentList = new ObservableCollection<SFEComponentData>();

		internal DataGrid grdSolidComponent;

		internal RadioButton radioNewChemistry;

		internal TextBox txtChemName;

		internal RadioButton radioExistChemistry;

		internal ComboBox cmbexistingChemistry;

		internal CheckBox globalChecked;

		internal Label labelglobal;

		private bool _contentLoaded;

		public bool IsGlobalChecked
		{
			get
			{
				return _isglobalchecked;
			}
			set
			{
				_isglobalchecked = value;
				OnPropertyChanged("IsGlobalChecked");
			}
		}

		public string GlobalChemistry
		{
			get
			{
				return _globalChemistry;
			}
			set
			{
				_globalChemistry = value;
				OnPropertyChanged("GlobalChemistry");
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public SFEAssistantStep2(SFEAssistantMain sfe)
		{
			sfeass = sfe;
			InitializeComponent();
			base.Loaded += SFEAssistantStep2_Loaded;
		}

		private void SFEAssistantStep2_Loaded(object sender, RoutedEventArgs e)
		{
			_productType = MMVersionHelper.MVGetProductCodeM();
			_chemistrypath = "Top.appModelV8.Reactions.Chemistry";
			if (_productType == 2)
			{
				_chemistrypath = "Top.appModelV8.Chemistry";
			}
			_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
			string dataPath = "Top.appModelV8.Properties.Specifications.Input.GCHEMISTRY";
			_globalChemistry = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath, "value"));
			if (!_hasLoaded)
			{
				Collection<string> collection = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet(_chemistrypath, "child_ids"));
				if (collection != null)
				{
					cmbexistingChemistry.Items.Clear();
					foreach (string item in collection)
					{
						cmbexistingChemistry.Items.Add(item);
					}
					cmbexistingChemistry.SelectedValue = collection[0].ToString().Trim();
					cmbexistingChemistry.SelectedIndex = 0;
					radioExistChemistry.IsEnabled = true;
				}
				else
				{
					radioExistChemistry.IsEnabled = false;
				}
				cmbexistingChemistry.IsEnabled = false;
				radioNewChemistry.IsEnabled = true;
				txtChemName.IsEnabled = true;
				string text = _viewModel.ExpandDataPathAndGet(_chemistrypath, "default_name") as string;
				txtChemName.Text = text;
				globalChecked.IsEnabled = true;
				if (string.IsNullOrEmpty(_globalChemistry))
				{
					globalChecked.IsChecked = true;
					IsGlobalChecked = true;
				}
				else
				{
					globalChecked.IsChecked = false;
					IsGlobalChecked = false;
				}
				_hasLoaded = true;
				sfeass.cmdOK.Focus();
			}
			solidComponentList.Clear();
			foreach (SFEComponentData item2 in g_arraySelectedComponent)
			{
				SFEComponentData sFEComponentData = new SFEComponentData();
				if (item2.ComponentID.Trim().Length <= 5)
				{
					sFEComponentData.SolidID = $"{item2.ComponentID.Trim()}(S)";
				}
				else
				{
					string text2 = item2.ComponentName.Trim();
					if (string.IsNullOrEmpty(text2))
					{
						sFEComponentData.SolidID = $"{item2.ComponentID.Substring(0, 5).Trim().ToUpper()}(S)";
					}
					else
					{
						text2 = text2.Substring(0, 5);
						sFEComponentData.SolidID = $"{text2}(S)";
					}
				}
				sFEComponentData.ComponentID = item2.ComponentID;
				sFEComponentData.ComponentName = item2.ComponentName;
				sFEComponentData.ComponentAlias = item2.ComponentAlias;
				solidComponentList.Add(sFEComponentData);
			}
			grdSolidComponent.ItemsSource = solidComponentList;
			base.CanFinish = true;
			dbankmsgs = 0;
			dbankmsgs |= 6;
			if (!Window.GetWindow(grdSolidComponent).IsVisible)
			{
				Window.GetWindow(grdSolidComponent).Show();
			}
			grdSolidComponent.UpdateLayout();
		}

		private static void ResetAll()
		{
			SmgeHelper.SetAllSpecsSelected(2, 0);
			SmgeHelper.SetAllSpecsSelected(3, 0);
			SmgeHelper.SetAllRxnsSelected(0);
		}

		private void GenerateReaction(string chemistryName)
		{
			string text = string.Format(_chemistrypath + ".{0}.Input.SALT_COEF", chemistryName);
			int num = 0;
			_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
			string[] array = CxsConverter.ValueToStringArray(_viewModel.ExpandDataPathAndGet(text, "child_ids"));
			bool flag = false;
			foreach (SFEComponentData solidComponent in solidComponentList)
			{
				string text2 = solidComponent.SolidID.Trim().ToUpper();
				string value = solidComponent.ComponentID.Trim().ToUpper();
				flag = false;
				if (array != null)
				{
					num = array.Length;
					string[] array2 = array;
					for (int i = 0; i < array2.Length; i++)
					{
						if (array2[i] == text2)
						{
							flag = true;
							break;
						}
					}
				}
				if (!flag)
				{
					_viewModel.AddChild(text, num);
					string dataPath = $"{text}.#{num}";
					_viewModel.ExpandDataPathAndSet(dataPath, "id", text2);
					string text3 = $"{text}.{text2}";
					_viewModel.AddChild(text3, 0);
					string dataPath2 = $"{text3}.#{0}";
					_viewModel.ExpandDataPathAndSet(dataPath2, "id", value);
					_viewModel.ExpandDataPathAndSet(dataPath2, "value", 1);
					string arg = string.Format(_chemistrypath + ".{0}.Input.SALT_OPTION", chemistryName);
					string dataPath3 = $"{arg}.{text2}";
					_viewModel.ExpandDataPathAndSet(dataPath3, "value", "NO");
				}
			}
		}

		private void GenerateComponent()
		{
			string value = "SOLID";
			_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
			int count = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet("Top.appModelV8.Components.Specifications.Input.TYPE", "child_ids")).Count;
			CxvActionResult cxvActionResult = _viewModel.InvokeAction("Top.appModelV8.Custom Actions", "GetDoNotAskAgain", false);
			int? num = (cxvActionResult.Succeeded ? CxsConverter.ValueToInt32(cxvActionResult.Result) : new int?(0));
			if (num.HasValue && num.Value != 0)
			{
				_viewModel.InvokeAction("Top.appModelV8.Custom Actions", "SetDoNotAskAgain", false, 0);
			}
			CxvActionResult cxvActionResult2 = _viewModel.InvokeAction("Top.appModelV8.Custom Actions", "GetSMupdatParam", false);
			int? num2 = (cxvActionResult2.Succeeded ? CxsConverter.ValueToInt32(cxvActionResult2.Result) : new int?(0));
			if (num2.HasValue && num2.Value != 0)
			{
				_viewModel.InvokeAction("Top.appModelV8.Custom Actions", "SetSMupdatParam", false, 0);
			}
			foreach (SFEComponentData solidComponent in solidComponentList)
			{
				string text = solidComponent.SolidID.Trim();
				string dataPath = $"Top.appModelV8.Components.Specifications.Input.TYPE.#{count++}";
				_viewModel.ExpandDataPathAndSet(dataPath, "id", text);
				dataPath = $"Top.appModelV8.Components.Specifications.Input.TYPE.{text}";
				_viewModel.ExpandDataPathAndSet(dataPath, "value", value);
				string componentName = solidComponent.ComponentName;
				dataPath = $"Top.appModelV8.Components.Specifications.Input.DBNAME1.{text}";
				_viewModel.ExpandDataPathAndSet(dataPath, "value", componentName);
				string componentAlias = solidComponent.ComponentAlias;
				dataPath = $"Top.appModelV8.Components.Specifications.Input.ANAME1.{text}";
				_viewModel.ExpandDataPathAndSet(dataPath, "value", componentAlias);
			}
			if (num.HasValue && num.Value != 0)
			{
				_viewModel.InvokeAction("Top.appModelV8.Custom Actions", "SetDoNotAskAgain", false, num.Value);
			}
			if (num2.HasValue && num2.Value != 0)
			{
				_viewModel.InvokeAction("Top.appModelV8.Custom Actions", "SetSMupdatParam", false, num2.Value);
			}
		}

		private void GenerateChemisty(string chemistryname)
		{
			if (IsGlobalChecked)
			{
				SmgeHelper.WriteChemRecordM(chemistryname.Trim().ToUpper(), ref dbankmsgs, 1, 1, 1);
				string dataPath = "Top.appModelV8.Properties.Specifications.Input.GTRUE_COMPS";
				_viewModel.ExpandDataPathAndSet(dataPath, "value", "YES");
			}
			else
			{
				SmgeHelper.WriteChemRecordM(chemistryname.Trim().ToUpper(), ref dbankmsgs, 1, 0, 1);
			}
			if (radioNewChemistry.IsChecked == true)
			{
				string dataPath2 = string.Format(_chemistrypath + ".{0}.Input.GAMMA_BASIS", chemistryname.Trim().ToUpper());
				_viewModel.ExpandDataPathAndSet(dataPath2, "value", null);
			}
			ResetAll();
			SmgeHelper.ClearAllocatedRxnSpaceM();
		}

		protected override bool OnBackward(WizardControlItem targetItem)
		{
			sfeass.IsOKVisable = false;
			return base.OnBackward(targetItem);
		}

		protected override bool OnFinished()
		{
			string sFEAssistantTitle = WpfFindComponentResources.SFEAssistantTitle;
			foreach (SFEComponentData solidComponent in solidComponentList)
			{
				if (string.IsNullOrEmpty(solidComponent.SolidID.Trim()))
				{
					MMMessageBox.Show(WpfFindComponentResources.SFEAssistant_MissingSolidComponent, sFEAssistantTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					return false;
				}
			}
			if ((radioNewChemistry.IsChecked == true && string.IsNullOrEmpty(txtChemName.Text.Trim())) || (radioExistChemistry.IsChecked == true && cmbexistingChemistry.Items.Count <= 0))
			{
				MMMessageBox.Show(WpfFindComponentResources.SFEAssistant_MissingChemistryID, sFEAssistantTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				return false;
			}
			for (int i = 0; i < solidComponentList.Count - 1; i++)
			{
				for (int j = i + 1; j < solidComponentList.Count - 1; j++)
				{
					if (solidComponentList[i].SolidID.Trim().Equals(solidComponentList[j].SolidID.Trim()))
					{
						MMMessageBox.Show(string.Format(WpfFindComponentResources.SFEAssistant_RepeatSolidComponent, solidComponentList[j].SolidID.Trim().ToUpper()), sFEAssistantTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
						return false;
					}
				}
			}
			string text = "";
			if (radioNewChemistry.IsChecked == true)
			{
				text = txtChemName.Text.Trim().ToUpper();
			}
			else if (radioExistChemistry.IsChecked == true)
			{
				text = cmbexistingChemistry.SelectedValue.ToString().Trim().ToUpper();
			}
			if (string.IsNullOrEmpty(text))
			{
				MMMessageBox.Show(WpfFindComponentResources.ChemistryNameMessage, WpfFindComponentResources.SFEAssistantTitle);
				return false;
			}
			if (SmgeHelper.HasChemRecordM(text) == 0)
			{
				GenerateComponent();
				GenerateChemisty(text);
				GenerateReaction(text);
			}
			else
			{
				if (radioExistChemistry.IsChecked != true)
				{
					MMMessageBox.Show(string.Format(WpfFindComponentResources.ChemistryExists, text), WpfFindComponentResources.ChemistryExistsTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					return false;
				}
				GenerateComponent();
				GenerateReaction(text);
				if (IsGlobalChecked)
				{
					string dataPath = "Top.appModelV8.Properties.Specifications.Input.GCHEMISTRY";
					_viewModel.ExpandDataPathAndSet(dataPath, "value", text);
				}
			}
			return base.OnFinished();
		}

		private void globalChemistryStatus()
		{
			globalChecked.IsEnabled = true;
			if (!string.IsNullOrEmpty(_globalChemistry) && cmbexistingChemistry.SelectedItem != null && string.Compare(cmbexistingChemistry.SelectedItem.ToString(), _globalChemistry) == 0)
			{
				globalChecked.IsEnabled = false;
			}
		}

		private void cmbexistingChemistry_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			globalChemistryStatus();
		}

		private void radioNewChemistry_Click(object sender, RoutedEventArgs e)
		{
			txtChemName.IsEnabled = true;
			cmbexistingChemistry.IsEnabled = false;
			globalChecked.IsEnabled = true;
		}

		private void radioExistChemistry_Click(object sender, RoutedEventArgs e)
		{
			txtChemName.IsEnabled = false;
			cmbexistingChemistry.IsEnabled = true;
			txtChemName.Clear();
			globalChemistryStatus();
		}

		private void globalChecked_Click(object sender, RoutedEventArgs e)
		{
			if (globalChecked.IsChecked == true)
			{
				IsGlobalChecked = true;
			}
			else
			{
				IsGlobalChecked = false;
			}
		}

		public virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChangedEventHandler propertyChangedEventHandler = this.PropertyChanged;
			if (propertyChangedEventHandler != null)
			{
				PropertyChangedEventArgs e = new PropertyChangedEventArgs(propertyName);
				propertyChangedEventHandler(this, e);
			}
		}

		private void SetBackground()
		{
			BrushConverter brushConverter = new BrushConverter();
			for (int i = 0; i < grdSolidComponent.Items.Count; i++)
			{
				if (i % 2 != 0)
				{
					((DataGridRow)grdSolidComponent.ItemContainerGenerator.ContainerFromIndex(i)).Background = (Brush)brushConverter.ConvertFrom("#FFF4F9FD");
				}
			}
		}

		private void grdSolidComponent_CellEditEnding(object sender, DataGridCellEditEndingEventArgs e)
		{
			string sFEAssistantTitle = WpfFindComponentResources.SFEAssistantTitle;
			string text = (e.EditingElement as TextBox).Text.Trim().ToUpper();
			int index = e.Row.GetIndex();
			for (int i = 0; i < solidComponentList.Count; i++)
			{
				if (i != index && text.Equals(solidComponentList[i].SolidID.Trim()))
				{
					MMMessageBox.Show(string.Format(WpfFindComponentResources.SFEAssistant_RepeatSolidComponent, text), sFEAssistantTitle, MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
					(e.EditingElement as TextBox).Text = "";
					break;
				}
			}
		}

		private bool ValidName(string newValue)
		{
			if (newValue != null && newValue.Length > 0)
			{
				if (!char.IsLetterOrDigit(newValue[0]))
				{
					return false;
				}
				if (newValue != null && newValue.Length > 0)
				{
					char[] array = newValue.ToCharArray();
					for (int i = 0; i < array.Length; i++)
					{
						char c = array[i];
						if (!char.IsLetterOrDigit(c) && !c.ToString().Equals("$") && !c.ToString().Equals("&") && !c.ToString().Equals("*") && !c.ToString().Equals("(") && !c.ToString().Equals(")") && !c.ToString().Equals("+") && !c.ToString().Equals("{") && !c.ToString().Equals("}") && !c.ToString().Equals("-") && !c.ToString().Equals("=") && !c.ToString().Equals("]") && !c.ToString().Equals("[") && !c.ToString().Equals(":") && !c.ToString().Equals(">") && !c.ToString().Equals("<"))
						{
							return false;
						}
					}
				}
			}
			return true;
		}

		private void TextBox_PreviewKeyDown(object sender, KeyEventArgs e)
		{
			if (e.Key == Key.Space)
			{
				e.Handled = true;
			}
		}

		private void TextBox_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			TextBox textBox = sender as TextBox;
			int caretIndex = textBox.CaretIndex;
			textBox.Text = textBox.Text.Trim().ToUpper();
			StringBuilder stringBuilder = new StringBuilder(textBox.Text.Trim().ToUpper());
			if (textBox.SelectedText.Trim().Length > 0)
			{
				stringBuilder.Replace(textBox.SelectedText, e.Text.Trim().ToUpper());
			}
			else
			{
				stringBuilder.Insert(caretIndex, e.Text.Trim().ToUpper());
			}
			if (stringBuilder.Length > tbTextLength || !ValidName(stringBuilder.ToString()))
			{
				e.Handled = true;
			}
			else
			{
				e.Handled = false;
			}
		}

		private void TextBox_TextChanged(object sender, EventArgs e)
		{
			TextBox textBox = sender as TextBox;
			int caretIndex = textBox.CaretIndex;
			if (!string.IsNullOrEmpty(textBox.Text.Trim()))
			{
				if (textBox.Text.Contains(" "))
				{
					string text = textBox.Text.Replace(" ", "");
					textBox.Text = text;
					textBox.Select(caretIndex, 0);
				}
				else if (textBox.Text.Length == 1)
				{
					if (!char.IsLetterOrDigit(textBox.Text.Trim().ToString()[0]))
					{
						textBox.Text = "";
						return;
					}
					textBox.Text = textBox.Text[0].ToString().ToUpper();
					textBox.Select(2, 1);
				}
			}
			else
			{
				textBox.Text = "";
				textBox.Select(1, 1);
			}
		}

		private void HandleCanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			if (e.Command != ApplicationCommands.Paste || string.IsNullOrEmpty(ClipboardWrapper.GetText().Trim().ToUpper()))
			{
				return;
			}
			string text = ClipboardWrapper.GetText().Trim().ToUpper();
			if (!string.IsNullOrEmpty(text))
			{
				if (!ValidName(text))
				{
					e.CanExecute = false;
					e.Handled = true;
				}
				else
				{
					e.CanExecute = true;
					e.Handled = true;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/sfeassistantstep2.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				grdSolidComponent = (DataGrid)target;
				grdSolidComponent.AddHandler(CommandManager.PreviewCanExecuteEvent, new CanExecuteRoutedEventHandler(HandleCanExecute));
				grdSolidComponent.CellEditEnding += grdSolidComponent_CellEditEnding;
				break;
			case 3:
				radioNewChemistry = (RadioButton)target;
				radioNewChemistry.Click += radioNewChemistry_Click;
				break;
			case 4:
				txtChemName = (TextBox)target;
				break;
			case 5:
				radioExistChemistry = (RadioButton)target;
				radioExistChemistry.Click += radioExistChemistry_Click;
				break;
			case 6:
				cmbexistingChemistry = (ComboBox)target;
				cmbexistingChemistry.SelectionChanged += cmbexistingChemistry_SelectionChanged;
				break;
			case 7:
				globalChecked = (CheckBox)target;
				globalChecked.Click += globalChecked_Click;
				break;
			case 8:
				labelglobal = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				EventSetter eventSetter = new EventSetter();
				eventSetter.Event = UIElement.PreviewTextInputEvent;
				eventSetter.Handler = new TextCompositionEventHandler(TextBox_PreviewTextInput);
				((Style)target).Setters.Add(eventSetter);
				eventSetter = new EventSetter();
				eventSetter.Event = UIElement.PreviewKeyDownEvent;
				eventSetter.Handler = new KeyEventHandler(TextBox_PreviewKeyDown);
				((Style)target).Setters.Add(eventSetter);
				eventSetter = new EventSetter();
				eventSetter.Event = TextBoxBase.TextChangedEvent;
				eventSetter.Handler = new TextChangedEventHandler(TextBox_TextChanged);
				((Style)target).Setters.Add(eventSetter);
			}
		}
	}
	public class TextBoxEx : TextBox
	{
		private ParsStyles _parseStyle;

		private int VARTYPE;

		public ParsStyles ParseStyle
		{
			get
			{
				return _parseStyle;
			}
			set
			{
				_parseStyle = value;
				if (_parseStyle == ParsStyles.FLOAT)
				{
					VARTYPE = 1;
				}
				else if (_parseStyle == ParsStyles.LETTERS)
				{
					VARTYPE = 2;
				}
			}
		}

		static TextBoxEx()
		{
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(TextBoxEx), new FrameworkPropertyMetadata(typeof(TextBoxEx)));
		}

		protected override void OnPreviewTextInput(TextCompositionEventArgs e)
		{
			int length = base.Text.Length;
			string text = base.Text;
			char c = e.Text[0];
			if (VARTYPE == 2)
			{
				if (length == 0 && !char.IsLetterOrDigit(c) && c != '\r' && c != '\b')
				{
					e.Handled = true;
				}
				else if (length > 0 && !char.IsLetterOrDigit(c) && c != '$' && c != ',' && c != ':' && c != '+' && c != '-' && c != ';' && c != '/' && c != '=' && c != '*' && c != '.' && c != '&' && c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}' && c != '<' && c != '>' && c != '\r' && c != '\b')
				{
					e.Handled = true;
				}
			}
			else if (VARTYPE == 1)
			{
				char c2 = MaskingAndValidatingHelper.GetSystemDecimalSymbol()[0];
				if ((c < '0' || c > '9') && c != c2 && c != '.' && c != '\b' && c != '-' && c != '+' && c != 'd' && c != 'D' && c != 'e' && c != 'E')
				{
					e.Handled = true;
				}
				if ((c == '.' && text.Contains('.')) || (c == c2 && text.Contains(c2)) || (c == 'e' && (text.Contains('e') || text.Contains('E') || text.Contains('d') || text.Contains('D'))) || (c == 'd' && (text.Contains('e') || text.Contains('E') || text.Contains('d') || text.Contains('D'))) || (c == 'E' && (text.Contains('e') || text.Contains('E') || text.Contains('d') || text.Contains('D'))) || (c == 'D' && (text.Contains('e') || text.Contains('E') || text.Contains('d') || text.Contains('D'))))
				{
					e.Handled = true;
				}
			}
			base.OnPreviewTextInput(e);
		}

		protected override void OnPreviewKeyDown(KeyEventArgs e)
		{
			if (VARTYPE == 1)
			{
				if (e.Key == Key.OemPeriod)
				{
					if (MaskingAndValidatingHelper.GetSystemDecimalSymbol() != ".")
					{
						e.Handled = true;
					}
				}
				else if (e.Key == Key.OemComma && MaskingAndValidatingHelper.GetSystemDecimalSymbol() != ",")
				{
					e.Handled = true;
				}
			}
			if (e.Handled)
			{
				SystemSounds.Asterisk.Play();
			}
			base.OnPreviewKeyDown(e);
		}
	}
	public enum ParsStyles
	{
		NUMBERS = 1,
		LETTERS = 2,
		OTHERCHARS = 3,
		FLOAT = 4,
		ALL = 100
	}
	public class UpgradeRetired : Window, IComponentConnector
	{
		internal TextBlock lblDesc;

		internal CheckBox chkUpgrade;

		internal Button btnOK;

		private bool _contentLoaded;

		public int State { get; private set; }

		public UpgradeRetired(int localUseAped)
		{
			InitializeComponent();
			State = 1;
			chkUpgrade.IsChecked = true;
			string empty = string.Empty;
			empty = ((!SystemEnvironment.IsAspenProperties) ? (WpfFindComponentResources.UpgradeRetiredDesc + Environment.NewLine) : (WpfFindComponentResources.UpgradeRetiredDesc_AProp + Environment.NewLine));
			empty = ((localUseAped != 0) ? (empty + WpfFindComponentResources.UpgradeRetiredDesc_Aped) : (empty + WpfFindComponentResources.UpgradeRetiredDesc_Legacy));
			lblDesc.Text = empty;
			base.Loaded += UpgradeRetired_Loaded;
		}

		private void UpgradeRetired_Loaded(object sender, RoutedEventArgs e)
		{
			base.Topmost = true;
			base.Topmost = false;
			Focus();
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void chkUpgrade_Click(object sender, RoutedEventArgs e)
		{
			if (chkUpgrade.IsChecked.HasValue && chkUpgrade.IsChecked.Value)
			{
				State = 1;
			}
			else
			{
				State = 0;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/upgraderetired.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblDesc = (TextBlock)target;
				break;
			case 2:
				chkUpgrade = (CheckBox)target;
				chkUpgrade.Click += chkUpgrade_Click;
				break;
			case 3:
				btnOK = (Button)target;
				btnOK.Click += btnOK_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UpwardComp : Window, IComponentConnector
	{
		private int _hideCancel;

		private int _bkpVersion;

		internal TextBlock lblComp;

		internal RadioButton radioMaitain;

		internal RadioButton radioFollow;

		internal StackPanel pnlNewFeatures;

		internal CheckBox chkNew1;

		internal TextBlock txtNewDataBankInstead;

		internal CheckBox chkNew2;

		internal CheckBox chkNew3;

		internal CheckBox chkNew4;

		internal CheckBox chkNew5;

		internal Button btnOK;

		internal Button btnCancel;

		internal Button btnHelp;

		private bool _contentLoaded;

		public int ResultCode { get; private set; }

		public UpwardComp(int hideCancel, int bkpver)
		{
			_hideCancel = hideCancel;
			_bkpVersion = bkpver;
			InitializeComponent();
			base.Loaded += UpwardComp_Loaded;
		}

		private void UpwardComp_Loaded(object sender, RoutedEventArgs e)
		{
			lblComp.Text = string.Format(WpfFindComponentResources.UpwardComp1Text, MMVersionHelper.MVGetProductNameWithExternalVersionM());
			btnCancel.Visibility = ((_hideCancel != 0) ? Visibility.Collapsed : Visibility.Visible);
			string arg = "PURE41";
			string arg2 = "PURE40";
			txtNewDataBankInstead.Text = string.Format(WpfFindComponentResources.NewDatabankInstead, arg, arg2);
			radioMaitain.IsChecked = true;
			base.Topmost = true;
			base.Topmost = false;
			Focus();
		}

		private void radioMaitain_Checked(object sender, RoutedEventArgs e)
		{
			chkNew1.IsEnabled = false;
			chkNew2.IsEnabled = false;
			chkNew3.IsEnabled = false;
			chkNew4.IsEnabled = false;
			chkNew5.IsEnabled = false;
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				CxsCase cxsCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
				try
				{
					chkNew1.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_pure_com") == 1;
					chkNew2.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_prop_opt") == 1;
					chkNew3.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_bin_par") == 1;
					chkNew4.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_ada") == 1;
					chkNew5.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_mwcalc") == 1;
				}
				catch (Exception)
				{
				}
			}
		}

		private void radioFollow_Checked(object sender, RoutedEventArgs e)
		{
			chkNew1.IsEnabled = true;
			chkNew2.IsEnabled = true;
			chkNew3.IsEnabled = true;
			chkNew4.IsEnabled = true;
			chkNew5.IsEnabled = true;
			IUnityContainer container = FindComponentModule.Container;
			if (container != null)
			{
				CxsCase cxsCase = container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
				try
				{
					chkNew1.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_pure_com") == 1;
					chkNew2.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_prop_opt") == 1;
					chkNew3.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_bin_par") == 1;
					chkNew4.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_ada") == 1;
					chkNew5.IsChecked = (int)cxsCase.InvokeAction("Top.appModelV8.Custom Actions", "GetSEsettingvalue", "new_mwcalc") == 1;
				}
				catch (Exception)
				{
				}
			}
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			ResultCode = 0;
			Close();
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			if (radioMaitain.IsChecked.HasValue && radioMaitain.IsChecked.Value)
			{
				ResultCode = -1;
			}
			else
			{
				int num = 0;
				for (int i = 0; i < 5; i++)
				{
					if ((pnlNewFeatures.Children[i] as CheckBox).IsChecked.Value)
					{
						if (i == 0)
						{
							num |= 1;
						}
						if (i == 1)
						{
							num |= 2;
						}
						if (i == 2)
						{
							num |= 4;
						}
						if (i == 3)
						{
							num |= 8;
						}
						if (i == 4)
						{
							num |= 0x10;
						}
					}
				}
				ResultCode = num;
			}
			if (base.DialogResult != true)
			{
				base.DialogResult = true;
			}
			else
			{
				Close();
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			if (ResultCode == 0)
			{
				MMMessageBoxResult mMMessageBoxResult = ((MMVersionHelper.MVGetProductCodeM() != 2) ? MMMessageBox.Show(WpfFindComponentResources.CloseAPlus, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.YesNo, MMMessageBoxImage.Question) : MMMessageBox.Show(WpfFindComponentResources.CloseAProperties, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.YesNo, MMMessageBoxImage.Question));
				if (mMMessageBoxResult == MMMessageBoxResult.Yes)
				{
					ResultCode = 0;
					base.DialogResult = false;
				}
				else
				{
					e.Cancel = true;
				}
			}
			base.OnClosing(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/upwardcomp.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				lblComp = (TextBlock)target;
				break;
			case 2:
				radioMaitain = (RadioButton)target;
				radioMaitain.Checked += radioMaitain_Checked;
				break;
			case 3:
				radioFollow = (RadioButton)target;
				radioFollow.Checked += radioFollow_Checked;
				break;
			case 4:
				pnlNewFeatures = (StackPanel)target;
				break;
			case 5:
				chkNew1 = (CheckBox)target;
				break;
			case 6:
				txtNewDataBankInstead = (TextBlock)target;
				break;
			case 7:
				chkNew2 = (CheckBox)target;
				break;
			case 8:
				chkNew3 = (CheckBox)target;
				break;
			case 9:
				chkNew4 = (CheckBox)target;
				break;
			case 10:
				chkNew5 = (CheckBox)target;
				break;
			case 11:
				btnOK = (Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 12:
				btnCancel = (Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			case 13:
				btnHelp = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class RadioButtonHeaderGroupBox : GroupBox
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
	public class UpwardComp1 : Window, IComponentConnector
	{
		private int _hideCancel;

		internal TextBlock lblComp;

		internal RadioButton radioMantain;

		internal RadioButton radioFollow;

		internal TextBlock txtFollow;

		internal Button btnOK;

		internal Button btnCancel;

		internal Button btnHelp;

		private bool _contentLoaded;

		public string HelpFile => "userguide1.chm";

		public int ResultCode { get; private set; }

		[DllImport("User32")]
		private static extern IntPtr GetWindowLongPtr(IntPtr hWnd, int index);

		[DllImport("User32")]
		private static extern IntPtr SetWindowLongPtr(IntPtr hWnd, int index, IntPtr newStyle);

		public UpwardComp1()
		{
			InitializeComponent();
		}

		public UpwardComp1(int hideCancel)
		{
			InitializeComponent();
			_hideCancel = hideCancel;
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = this;
			lblComp.Text = string.Format(WpfFindComponentResources.UpwardComp1Text, MMVersionHelper.MVGetProductNameWithExternalVersionM());
			btnCancel.Visibility = ((_hideCancel != 0) ? Visibility.Collapsed : Visibility.Visible);
			int count = CompoundsTabViewModel.APPUREDatabankNames.Count;
			string arg = CompoundsTabViewModel.APPUREDatabankNames[count - 1];
			string arg2 = CompoundsTabViewModel.APPUREDatabankNames[count - 2];
			txtFollow.Text = string.Format(WpfFindComponentResources.RadioFollowLabel, arg, arg2);
			base.Topmost = true;
			base.Topmost = false;
			if (ScriptingSupport.Enabled && (ScriptingSupport.ScriptRunning || ScriptingSupport.DialogArgs.Find("item") >= 0))
			{
				ResultCode = -1;
				base.DialogResult = true;
				if (ScriptingSupport.DialogArgs.Find("item") >= 0)
				{
					ScriptingSupport.DialogArgs.Clear();
				}
				Close();
			}
			Focus();
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			if (_hideCancel != 0)
			{
				long num = 65536L;
				long num2 = 131072L;
				long num3 = 524288L;
				int index = -16;
				IntPtr handle = new WindowInteropHelper(this).Handle;
				long num4 = GetWindowLongPtr(handle, index).ToInt64();
				IntPtr newStyle = new IntPtr(num4 & ~num & ~num2 & ~num3);
				SetWindowLongPtr(handle, index, newStyle);
			}
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			ResultCode = 0;
			Close();
		}

		private void btnOK_Click(object sender, RoutedEventArgs e)
		{
			if (radioMantain.IsChecked.HasValue && radioMantain.IsChecked.Value)
			{
				ResultCode = -1;
			}
			else
			{
				ResultCode = 1;
			}
			base.DialogResult = true;
			Close();
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			if (ResultCode == 0)
			{
				MMMessageBoxResult mMMessageBoxResult = ((MMVersionHelper.MVGetProductCodeM() != 2) ? MMMessageBox.Show(WpfFindComponentResources.CloseAPlus, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.YesNo, MMMessageBoxImage.Question) : MMMessageBox.Show(WpfFindComponentResources.CloseAProperties, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.YesNo, MMMessageBoxImage.Question));
				if (mMMessageBoxResult == MMMessageBoxResult.Yes)
				{
					ResultCode = 0;
					base.DialogResult = false;
				}
				else
				{
					e.Cancel = true;
				}
			}
			base.OnClosing(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/upwardcomp1.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				((UpwardComp1)target).Loaded += Window_Loaded;
				break;
			case 2:
				lblComp = (TextBlock)target;
				break;
			case 3:
				radioMantain = (RadioButton)target;
				break;
			case 4:
				radioFollow = (RadioButton)target;
				break;
			case 5:
				txtFollow = (TextBlock)target;
				break;
			case 6:
				btnOK = (Button)target;
				btnOK.Click += btnOK_Click;
				break;
			case 7:
				btnCancel = (Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			case 8:
				btnHelp = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class CreateProperty : Window, IComponentConnector
	{
		private readonly CreatePropertyViewModel _vm;

		private const string PropertySetPath = "Top.appModelV8.Properties.Prop-Sets";

		private readonly List<string> _existingIds = new List<string>();

		private static CreateProperty _defaultCreatePropertyDialog;

		private bool _searchPropertyOnly = true;

		private string _defaultPropertySetID;

		private bool _isCancelled = true;

		private GridViewColumnHeader _lastHeaderClicked;

		private ListSortDirection _lastDirection;

		internal CreateProperty createPropertyWindow;

		internal Grid Grid_3;

		internal TextBox txtPropertyID;

		internal TextBox txtDesc;

		internal Grid Grid_4;

		internal CheckBox chkSearchPure;

		internal SearchBox txtProperty;

		internal CheckBox chkRefSys;

		internal GroupBox grpStep3;

		internal ListView lstProperty;

		internal GroupBox grpStep4;

		internal ListView lstAcceptedProperty;

		internal Button btnUp;

		internal Button btnDown;

		internal Button btnOK;

		private bool _contentLoaded;

		public static CreateProperty DefaultCreatePropertyDialog
		{
			get
			{
				if (_defaultCreatePropertyDialog == null)
				{
					_defaultCreatePropertyDialog = new CreateProperty();
				}
				return _defaultCreatePropertyDialog;
			}
		}

		public bool SearchPropertyOnly
		{
			get
			{
				return _searchPropertyOnly;
			}
			set
			{
				_searchPropertyOnly = value;
				UpdateControlVisibility();
			}
		}

		public List<string> ExistingIds => _existingIds;

		public string Description
		{
			get
			{
				if (_vm != null)
				{
					return _vm.Description;
				}
				return null;
			}
		}

		public string DefaultPropertySetID
		{
			get
			{
				return _defaultPropertySetID;
			}
			set
			{
				_defaultPropertySetID = value;
				if (_vm != null)
				{
					_vm.PropertySetID = _defaultPropertySetID;
				}
			}
		}

		public string CurrentPropertySetID => _vm.PropertySetID;

		public bool IsCancelled
		{
			get
			{
				return _isCancelled;
			}
			set
			{
				_isCancelled = value;
			}
		}

		public CreateProperty()
		{
			InitializeComponent();
			_vm = new CreatePropertyViewModel();
			base.DataContext = _vm;
			base.IsVisibleChanged += CreateProperty_IsVisibleChanged;
			base.Loaded += CreateProperty_Loaded;
		}

		private void CreateProperty_Loaded(object sender, RoutedEventArgs e)
		{
			UpdateControlVisibility();
		}

		private void CreateProperty_IsVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
		{
			if (e.NewValue != null && (bool)e.NewValue)
			{
				UpdateControlVisibility();
				_isCancelled = true;
				_vm.Executed_SearchCommand(null);
			}
		}

		protected override void OnPreviewKeyDown(KeyEventArgs e)
		{
			base.OnPreviewKeyDown(e);
			if (e.Key == Key.Escape)
			{
				Close();
			}
		}

		private void UpdateControlVisibility()
		{
			if (base.IsLoaded)
			{
				if (SearchPropertyOnly)
				{
					Grid_3.Visibility = Visibility.Collapsed;
					base.Title = WpfFindComponentResources.FindProperties;
				}
				else
				{
					Grid_3.Visibility = Visibility.Visible;
					base.Title = WpfFindComponentResources.SearchPhyProp1;
				}
			}
		}

		private void ListView_ColumnHeaderClicked(object sender, RoutedEventArgs e)
		{
			GridViewColumnHeader gridViewColumnHeader = e.OriginalSource as GridViewColumnHeader;
			ListView listView = sender as ListView;
			if (gridViewColumnHeader != null && gridViewColumnHeader.Role != GridViewColumnHeaderRole.Padding)
			{
				ListSortDirection listSortDirection = ((gridViewColumnHeader == _lastHeaderClicked && _lastDirection == ListSortDirection.Ascending) ? ListSortDirection.Descending : ListSortDirection.Ascending);
				string text = gridViewColumnHeader.Column.Header as string;
				if (listView.Name == "lstProperty")
				{
					Sort(text, listSortDirection, sender as ListView);
				}
				else if (listView.Name == "lstAcceptedProperty")
				{
					_vm.SortAcceptedAcceptedProps(text, listSortDirection);
				}
				if (listSortDirection == ListSortDirection.Ascending)
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowUp"] as DataTemplate;
				}
				else
				{
					gridViewColumnHeader.Column.HeaderTemplate = base.Resources["HeaderTemplateArrowDown"] as DataTemplate;
				}
				if (_lastHeaderClicked != null && _lastHeaderClicked != gridViewColumnHeader)
				{
					_lastHeaderClicked.Column.HeaderTemplate = null;
				}
				_lastHeaderClicked = gridViewColumnHeader;
				_lastDirection = listSortDirection;
			}
		}

		private void Sort(string sortBy, ListSortDirection direction, ListView lstView)
		{
			if (!string.IsNullOrEmpty(sortBy))
			{
				if (sortBy == WpfFindComponentResources.PhyPropName1)
				{
					sortBy = "Name";
				}
				else if (sortBy == WpfFindComponentResources.Alias)
				{
					sortBy = "Alias";
				}
				ICollectionView defaultView = CollectionViewSource.GetDefaultView(lstView.ItemsSource);
				defaultView.SortDescriptions.Clear();
				SortDescription item = new SortDescription(sortBy, direction);
				defaultView.SortDescriptions.Add(item);
				defaultView.Refresh();
			}
		}

		private void txtPropertyID_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			_ = txtPropertyID.Text;
			string text = e.Text;
			if (string.IsNullOrEmpty(text))
			{
				return;
			}
			if (txtPropertyID.SelectionStart == 0)
			{
				if (!char.IsLetterOrDigit(text[0]))
				{
					e.Handled = true;
				}
				return;
			}
			char[] array = text.ToCharArray();
			foreach (char c in array)
			{
				if (!char.IsLetterOrDigit(c) && c != ',' && c != '$' && c != ':' && c != '+' && c != '-' && c != '\r' && c != '\b')
				{
					e.Handled = true;
					break;
				}
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			e.Cancel = true;
			Reset();
			Hide();
		}

		private void Reset()
		{
			if (lstProperty.View is GridView { Columns: not null } gridView)
			{
				foreach (GridViewColumn column in gridView.Columns)
				{
					column.HeaderTemplate = null;
				}
			}
			if (lstAcceptedProperty.View is GridView { Columns: not null } gridView2)
			{
				foreach (GridViewColumn column2 in gridView2.Columns)
				{
					column2.HeaderTemplate = null;
				}
			}
			SearchPropertyOnly = true;
			_existingIds.Clear();
			_vm.Reset();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/createproperty.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				createPropertyWindow = (CreateProperty)target;
				break;
			case 2:
				Grid_3 = (Grid)target;
				break;
			case 3:
				txtPropertyID = (TextBox)target;
				txtPropertyID.PreviewTextInput += txtPropertyID_PreviewTextInput;
				break;
			case 4:
				txtDesc = (TextBox)target;
				break;
			case 5:
				Grid_4 = (Grid)target;
				break;
			case 6:
				chkSearchPure = (CheckBox)target;
				break;
			case 7:
				txtProperty = (SearchBox)target;
				break;
			case 8:
				chkRefSys = (CheckBox)target;
				break;
			case 9:
				grpStep3 = (GroupBox)target;
				break;
			case 10:
				lstProperty = (ListView)target;
				lstProperty.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			case 11:
				grpStep4 = (GroupBox)target;
				break;
			case 12:
				lstAcceptedProperty = (ListView)target;
				lstAcceptedProperty.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(ListView_ColumnHeaderClicked));
				break;
			case 13:
				btnUp = (Button)target;
				break;
			case 14:
				btnDown = (Button)target;
				break;
			case 15:
				btnOK = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ComponentData
	{
		public string ComponentID { get; set; }

		public string ComponentDes { get; set; }
	}
	public class SFEAssistant : Window, IComponentConnector
	{
		private ObservableCollection<ComponentData> arrayAvailableComponent = new ObservableCollection<ComponentData>();

		private ObservableCollection<ComponentData> arraySelectedComponent = new ObservableCollection<ComponentData>();

		private int _setbasecomps;

		private int _totalbcomp;

		private bool _hasLoaded;

		private static int _localUsedAped;

		private MMViewModel _viewModel;

		public int Reactions;

		public List<string> Componentnames = new List<string>();

		internal SFEAssistant sFEAssistantWindow;

		internal ListBox lstAvailableComp;

		internal Button btnMove;

		internal Button btnMoveAll;

		internal Button btnRemove;

		internal Button btnClearAll;

		internal ListBox lstSelectedComp;

		internal RadioButton radioNewChemistry;

		internal TextBox txtChemName;

		internal RadioButton radioExistChemistry;

		internal ComboBox cmbexistingChemistry;

		internal Button btnClose;

		internal Button btnOK;

		private bool _contentLoaded;

		public SFEAssistant(int localUseAped)
		{
			try
			{
				InitializeComponent();
				_localUsedAped = localUseAped;
				string[] reacBankArr = new string[SmgeHelper.GetTotalNumberOfReacDatabanksM()];
				SmgeHelper.GetReacDatabanksListM(ref reacBankArr);
				if (reacBankArr.Length != 0)
				{
					Array.Sort(reacBankArr);
					Array.Reverse(reacBankArr);
				}
				SmgeHelper.GetReacDatabankM(reacBankArr[0], 1);
				SmgeHelper.SetGenNewCompsM(1);
				if (SmgeHelper.GetBaseCompsM() == 0)
				{
					return;
				}
				_setbasecomps = 1;
				if (!_hasLoaded)
				{
					btnClearAll.IsEnabled = false;
					btnRemove.IsEnabled = false;
					IList<string> avialbleComps;
					int totalbcomp = SmgeHelper.CollectBaseAvailComponentsM(out avialbleComps);
					_viewModel = FindComponentModule.Container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
					Collection<string> collection = CxsConverter.ValueToStringCollection(_viewModel.ExpandDataPathAndGet("Top.appModelV8.Components.Specifications.Input.TYPE", "child_ids"));
					if (collection != null)
					{
						foreach (string item in collection)
						{
							ComponentData componentData = new ComponentData
							{
								ComponentID = item
							};
							string dataPath = $"Top.appModelV8.Components.Specifications.Input.DBNAME1.{item}";
							string arg = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath, "value"));
							dataPath = $"Top.appModelV8.Components.Specifications.Input.ANAME1.{item}";
							string arg2 = CxsConverter.ValueToString(_viewModel.ExpandDataPathAndGet(dataPath, "value"));
							componentData.ComponentDes = $"{arg2}  {arg}";
							arrayAvailableComponent.Add(componentData);
						}
					}
					lstSelectedComp.Items.Clear();
					_totalbcomp = totalbcomp;
					_hasLoaded = true;
				}
				lstAvailableComp.SelectedIndex = 0;
				Update();
				base.Loaded += SFEAssistant_Loaded;
				lstAvailableComp.ItemsSource = arrayAvailableComponent;
				lstSelectedComp.ItemsSource = arraySelectedComponent;
			}
			catch (Exception ex)
			{
				_ = ex.Message;
			}
		}

		private void SFEAssistant_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = new SFEAssistantViewModel(FindComponentModule.Container);
		}

		private void UpdateButtonsStatus()
		{
			if (lstAvailableComp.Items.Count > 0)
			{
				btnMove.IsEnabled = true;
				btnMoveAll.IsEnabled = true;
			}
			else
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
			}
			if (lstSelectedComp.Items.Count > 0)
			{
				btnRemove.IsEnabled = true;
				btnClearAll.IsEnabled = true;
			}
			else
			{
				btnRemove.IsEnabled = false;
				btnClearAll.IsEnabled = false;
			}
		}

		private void btnRemove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || lstSelectedComp.Items.Count <= 0)
			{
				return;
			}
			int count = lstSelectedComp.SelectedItems.Count;
			ObservableCollection<ComponentData> observableCollection = new ObservableCollection<ComponentData>();
			foreach (ComponentData selectedItem in lstSelectedComp.SelectedItems)
			{
				string componentID = selectedItem.ComponentID;
				if (componentID.Equals("H2O") && count == 1)
				{
					MMMessageBox.Show(WpfFindComponentResources.H2O_Message, WpfFindComponentResources.SFEAssistantTitle);
					continue;
				}
				observableCollection.Add(selectedItem);
				if (!CheckBufFromAveComponents(componentID))
				{
					arrayAvailableComponent.Add(selectedItem);
					lstAvailableComp.SelectedItem = componentID;
				}
				SmgeHelper.SetSpecsSelected(componentID, 1, 0);
			}
			int num = 0;
			foreach (ComponentData item in observableCollection)
			{
				num = lstSelectedComp.Items.IndexOf(item);
				arraySelectedComponent.Remove(item);
			}
			int count2 = lstSelectedComp.Items.Count;
			if (num < count2)
			{
				lstSelectedComp.SelectedIndex = num;
			}
			else if (count2 > 0)
			{
				lstSelectedComp.SelectedIndex = count2 - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private bool FindSelectedStrings(string str)
		{
			foreach (ComponentData item in (IEnumerable)lstSelectedComp.Items)
			{
				if (item.ComponentID.Equals(str))
				{
					return true;
				}
			}
			return false;
		}

		private void btnMove_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0 || lstAvailableComp.SelectedItems.Count < 1)
			{
				return;
			}
			ObservableCollection<ComponentData> observableCollection = new ObservableCollection<ComponentData>();
			foreach (ComponentData selectedItem in lstAvailableComp.SelectedItems)
			{
				string text = selectedItem.ComponentID.ToString();
				observableCollection.Add(selectedItem);
				if (!FindSelectedStrings(text))
				{
					arraySelectedComponent.Add(selectedItem);
					lstSelectedComp.SelectedItem = selectedItem;
					SmgeHelper.SetSpecsSelected(text, 1, 1);
				}
			}
			int num = 0;
			foreach (ComponentData item in observableCollection)
			{
				num = lstAvailableComp.Items.IndexOf(item);
				arrayAvailableComponent.Remove(item);
			}
			int count = lstAvailableComp.Items.Count;
			if (num < count)
			{
				lstAvailableComp.SelectedIndex = num;
			}
			else if (count > 0)
			{
				lstAvailableComp.SelectedIndex = count - 1;
			}
			UpdateButtonsStatus();
			Update();
		}

		private void btnMoveAll_Click(object sender, RoutedEventArgs e)
		{
			if (_setbasecomps == 0)
			{
				return;
			}
			if (lstAvailableComp.Items.Count <= 0)
			{
				btnMove.IsEnabled = false;
				btnMoveAll.IsEnabled = false;
				return;
			}
			foreach (ComponentData item in (IEnumerable)lstAvailableComp.Items)
			{
				if (!CheckBufFromSelComponents(item.ComponentID))
				{
					arraySelectedComponent.Add(item);
					SmgeHelper.SetSpecsSelected(item.ComponentID, 1, 1);
				}
			}
			arrayAvailableComponent.Clear();
			UpdateButtonsStatus();
			lstSelectedComp.SelectedIndex = 0;
			lstSelectedComp.Focus();
			Update();
		}

		private void btnClearAll_Click(object sender, RoutedEventArgs e)
		{
			foreach (ComponentData item in (IEnumerable)lstSelectedComp.Items)
			{
				arrayAvailableComponent.Add(item);
			}
			arraySelectedComponent.Clear();
			SmgeHelper.SetAllSpecsSelected(1, 0);
			btnClearAll.IsEnabled = false;
			UpdateButtonsStatus();
			lstAvailableComp.Focus();
			if (lstAvailableComp.Items.Count > 0)
			{
				lstAvailableComp.SelectedIndex = 0;
			}
		}

		private void lstAvailableComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnMove_Click(sender, e);
					break;
				}
			}
		}

		private void lstSelectedComp_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			for (DependencyObject dependencyObject = e.OriginalSource as DependencyObject; dependencyObject != null; dependencyObject = VisualTreeHelper.GetParent(dependencyObject))
			{
				if (dependencyObject is ListBoxItem)
				{
					btnRemove_Click(sender, e);
					break;
				}
			}
		}

		private bool CheckBufFromSelComponents(string str)
		{
			return lstSelectedComp.Items.Contains(str);
		}

		private bool CheckBufFromAveComponents(string str)
		{
			return lstAvailableComp.Items.Contains(str);
		}

		private void Update()
		{
			SmgeHelper.ClearAllocatedRxnSpaceM();
			SmgeHelper.SetHydroniumIsH_M(1);
			SmgeHelper.SetIncludeSaltM(1);
			SmgeHelper.SetWaterDissocM(1);
			SmgeHelper.SetIceFormationM(0);
			SmgeHelper.RxnInitM();
			SmgeHelper.GenRxnsAfreshM();
			Reactions = ((SmgeHelper.GetNumRxnsPossibleM() != 0) ? 1 : 0);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/sfeassistant.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				sFEAssistantWindow = (SFEAssistant)target;
				break;
			case 2:
				lstAvailableComp = (ListBox)target;
				lstAvailableComp.MouseDoubleClick += lstAvailableComp_MouseDoubleClick;
				break;
			case 3:
				btnMove = (Button)target;
				btnMove.Click += btnMove_Click;
				break;
			case 4:
				btnMoveAll = (Button)target;
				btnMoveAll.Click += btnMoveAll_Click;
				break;
			case 5:
				btnRemove = (Button)target;
				btnRemove.Click += btnRemove_Click;
				break;
			case 6:
				btnClearAll = (Button)target;
				btnClearAll.Click += btnClearAll_Click;
				break;
			case 7:
				lstSelectedComp = (ListBox)target;
				lstSelectedComp.MouseDoubleClick += lstSelectedComp_MouseDoubleClick;
				break;
			case 8:
				radioNewChemistry = (RadioButton)target;
				break;
			case 9:
				txtChemName = (TextBox)target;
				break;
			case 10:
				radioExistChemistry = (RadioButton)target;
				break;
			case 11:
				cmbexistingChemistry = (ComboBox)target;
				break;
			case 12:
				btnClose = (Button)target;
				break;
			case 13:
				btnOK = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UserDefinedComp0 : WizardControlItem, IComponentConnector
	{
		internal TextBoxEx txtCompID;

		internal ComboBox cboType;

		internal TextBoxEx tbFormula;

		internal GroupBox grpCompTypeText;

		internal TextBlock txtReqParams;

		private bool _contentLoaded;

		public int CurrentRecord { get; private set; }

		public UserDefinedComp0(int index)
		{
			InitializeComponent();
			CurrentRecord = index;
			Init();
		}

		private bool Init()
		{
			string cid = "";
			string formula = "";
			string type = "";
			SmgeHelper.GetComponentM(ref cid, ref formula, ref type, CurrentRecord);
			switch (type)
			{
			case "CONV":
			case "NC":
			case "SOLID":
				if (!string.IsNullOrEmpty(cid))
				{
					txtCompID.Text = cid;
					UserDefinedCompWizardMain.g_CompIdText = cid;
				}
				if (!string.IsNullOrEmpty(formula))
				{
					tbFormula.Text = formula;
					UserDefinedCompWizardMain.g_CompFormula = formula;
				}
				switch (type)
				{
				case "CONV":
					UserDefinedCompWizardMain.g_CompType = "Conventional";
					break;
				case "NC":
					UserDefinedCompWizardMain.g_CompType = "Nonconventional";
					UserDefinedCompWizardMain.g_Curstr = UserDefinedCompWizardMain.g_CompIdText;
					UserDefinedCompWizardMain.g_Curset = 1;
					break;
				case "SOLID":
					UserDefinedCompWizardMain.g_CompType = "Solid";
					break;
				}
				break;
			}
			txtCompID.Text = UserDefinedCompWizardMain.g_CompIdText;
			tbFormula.Text = UserDefinedCompWizardMain.g_CompFormula;
			SetDefaultComboTypeText();
			txtCompID.ParseStyle = ParsStyles.LETTERS;
			tbFormula.ParseStyle = ParsStyles.LETTERS;
			return true;
		}

		private void SetDefaultComboTypeText()
		{
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				grpCompTypeText.Header = WpfFindComponentResources.ConventionalsText;
				cboType.SelectedIndex = 0;
				tbFormula.IsEnabled = true;
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Nonconventional")
			{
				grpCompTypeText.Header = WpfFindComponentResources.NonConventionalsText;
				cboType.SelectedIndex = 2;
				tbFormula.IsEnabled = false;
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				grpCompTypeText.Header = WpfFindComponentResources.SolidsText;
				cboType.SelectedIndex = 1;
				tbFormula.IsEnabled = true;
			}
		}

		private void SetDefaultStaticComboText(int index)
		{
			switch (index)
			{
			case 0:
				grpCompTypeText.Header = WpfFindComponentResources.ConventionalsText;
				txtReqParams.Text = WpfFindComponentResources.ConvReqParams;
				tbFormula.IsEnabled = true;
				break;
			case 2:
				grpCompTypeText.Header = WpfFindComponentResources.NonConventionalsText;
				txtReqParams.Text = WpfFindComponentResources.NonconvReqParams;
				tbFormula.IsEnabled = false;
				break;
			case 1:
				grpCompTypeText.Header = WpfFindComponentResources.SolidsText;
				txtReqParams.Text = WpfFindComponentResources.SolidReqParams;
				tbFormula.IsEnabled = true;
				break;
			}
		}

		private void SetCompIDButtonStatus(string compidtext)
		{
			UserDefinedCompWizardMain.g_CompIdText = compidtext;
			if (string.IsNullOrEmpty(compidtext))
			{
				base.CanForward = false;
				base.CanFinish = false;
			}
			else
			{
				base.CanForward = true;
				base.CanFinish = true;
			}
		}

		private void cboType_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			SetDefaultStaticComboText(cboType.SelectedIndex);
			switch (cboType.SelectedIndex)
			{
			case 0:
				UserDefinedCompWizardMain.g_CompType = "Conventional";
				break;
			case 2:
				UserDefinedCompWizardMain.g_CompType = "Nonconventional";
				break;
			case 1:
				UserDefinedCompWizardMain.g_CompType = "Solid";
				break;
			}
			if (string.IsNullOrEmpty(UserDefinedCompWizardMain.g_CompIdText))
			{
				base.CanForward = false;
				base.CanFinish = false;
			}
			else
			{
				base.CanForward = true;
				base.CanFinish = true;
			}
		}

		private void txtCompID_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_CompIdText = "";
			string text = txtCompID.Text.ToUpper();
			txtCompID.Text = text;
			SetCompIDButtonStatus(text);
			if (string.IsNullOrEmpty(UserDefinedCompWizardMain.g_CompIdText))
			{
				UserDefinedCompWizardMain.g_CompFormula = "";
				tbFormula.Text = "";
			}
		}

		private void tbFormula_TextChanged(object sender, TextChangedEventArgs e)
		{
			string text = tbFormula.Text.ToUpper();
			tbFormula.Text = text;
			UserDefinedCompWizardMain.g_CompFormula = text.Replace(" ", "");
			if (string.IsNullOrEmpty(UserDefinedCompWizardMain.g_CompIdText))
			{
				base.CanForward = false;
				base.CanFinish = false;
			}
			else
			{
				base.CanForward = true;
				base.CanFinish = true;
			}
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			if (Regex.IsMatch(UserDefinedCompWizardMain.g_CompIdText, "[^\\u0000-\\u007F]") || Regex.IsMatch(UserDefinedCompWizardMain.g_CompFormula, "[^\\u0000-\\u007F]"))
			{
				MaskingAndValidatingHelper.PopupNoneAsciiCharMsg();
				return false;
			}
			int num;
			if (UserDefinedCompWizardMain.g_CompType == "Nonconventional")
			{
				num = ProcessNext();
				if (num == 1 && UserDefinedCompWizardMain.g_storecompflag != -1)
				{
					UserDefinedCompWizardMain.UpdateWizard();
				}
				else
				{
					MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.CannotChangeCompType, ApwnResources.UserDefWizard_Title);
				}
				UserDefinedCompWizardMain.g_storecompflag = 0;
				return false;
			}
			num = ProcessNext();
			if (num == 1 && UserDefinedCompWizardMain.g_storecompflag == -2)
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.CannotChangeCompType, ApwnResources.UserDefWizard_Title);
				UserDefinedCompWizardMain.g_storecompflag = 0;
				return false;
			}
			if (num == 0)
			{
				return false;
			}
			if (targetItem is UserDefinedComp1 userDefinedComp)
			{
				userDefinedComp.Init();
			}
			return base.OnForward(targetItem);
		}

		public int ProcessNext()
		{
			string formula = "";
			string type = "";
			int num = 0;
			if (string.IsNullOrEmpty(UserDefinedCompWizardMain.g_CompIdText))
			{
				return 0;
			}
			if (UserDefinedCompWizardMain.g_CompIdText.Contains(" "))
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.BlankNotAllowdForCompID, ApwnResources.UserDefWizard_Title);
				return 0;
			}
			int num2;
			if (UserDefinedCompWizardMain.g_CompType == "Nonconventional")
			{
				if (UserDefinedCompWizardMain.g_loadformflag == 0)
				{
					if (!UserDefinedCompWizardMain.ComponentIDPresent())
					{
						return 0;
					}
					num2 = UserDefinedCompWizardMain.WriteUserDefComp();
					switch (num2)
					{
					case 0:
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.SetNCCompIDError, ApwnResources.UserDefWizard_Title);
						UserDefinedCompWizardMain.g_storecompflag = num2;
						return 0;
					case -1:
						SmgeHelper.GetComponentM(ref UserDefinedCompWizardMain.g_CompIdText, ref formula, ref type, -1);
						if (type == "NC")
						{
							UserDefinedCompWizardMain.g_storecompflag = 0;
						}
						else
						{
							UserDefinedCompWizardMain.g_storecompflag = num2;
						}
						break;
					}
					return 1;
				}
				if (UserDefinedCompWizardMain.g_loadformflag == 1)
				{
					return 1;
				}
			}
			if (UserDefinedCompWizardMain.g_CompFormula.Contains(" "))
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.BlankNotAllowdForCompFormula, ApwnResources.UserDefWizard_Title);
				return 0;
			}
			if (!UserDefinedCompWizardMain.ComponentIDPresent())
			{
				return 0;
			}
			if (!UserDefinedCompWizardMain.FormulaPresent(Window.GetWindow(this)))
			{
				return 0;
			}
			num2 = UserDefinedCompWizardMain.WriteUserDefComp();
			if (num2 == 0)
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.SetConvSolidCompIDError, ApwnResources.UserDefWizard_Title);
				UserDefinedCompWizardMain.g_storecompflag = num2;
				return 0;
			}
			SmgeHelper.GetComponentM(ref UserDefinedCompWizardMain.g_CompIdText, ref formula, ref type, -1);
			if (type == "CONV" && UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				num = 1;
			}
			else if (type == "SOLID" && UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				num = 1;
			}
			switch (num)
			{
			case 0:
				UserDefinedCompWizardMain.g_storecompflag = -2;
				return 1;
			case 1:
				UserDefinedCompWizardMain.g_storecompflag = num2;
				UserDefinedCompWizardMain.ReadParameters();
				return 1;
			default:
				return 1;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/userdefinedcomp0.xaml", UriKind.Relative);
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
				txtCompID = (TextBoxEx)target;
				break;
			case 2:
				cboType = (ComboBox)target;
				cboType.SelectionChanged += cboType_SelectionChanged;
				break;
			case 3:
				tbFormula = (TextBoxEx)target;
				break;
			case 4:
				grpCompTypeText = (GroupBox)target;
				break;
			case 5:
				txtReqParams = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UserDefinedComp1 : WizardControlItem, IComponentConnector
	{
		internal Grid grdConv;

		internal Label txtCompID;

		internal Label txtFormula;

		internal GroupBox grpMoleStruct;

		internal Button btnDrawStru;

		internal TextBlock txtInputStru;

		internal Button btnImportStru;

		internal TextBlock txtInputCon;

		internal GroupBox grpConvProp;

		internal TextBoxEx txtMolecularWeight;

		internal TextBoxEx txtNbp;

		internal ComboBox cboUnbp;

		internal TextBoxEx txtSG;

		internal TextBoxEx txtEOF;

		internal ComboBox cboUEof;

		internal TextBoxEx txtFEOF;

		internal ComboBox cboUFEof;

		internal GroupBox grpSolidProp;

		internal TextBoxEx txtMolecularWeight_Solid;

		internal TextBoxEx txtNbp_Solid;

		internal ComboBox cboUnbp_Solid;

		internal TextBoxEx txtEOF_Solid;

		internal ComboBox cboUEof_Solid;

		internal TextBoxEx txtFEOF_Solid;

		internal ComboBox cboUFEof_Solid;

		private bool _contentLoaded;

		public UserDefinedComp1()
		{
			InitializeComponent();
			Init();
		}

		public bool Init()
		{
			txtCompID.Content = UserDefinedCompWizardMain.g_CompIdText;
			txtFormula.Content = UserDefinedCompWizardMain.g_CompFormula;
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				base.Title = WpfFindComponentResources.UserDefComp1Caption_Conv;
				grpMoleStruct.Visibility = Visibility.Visible;
				grpConvProp.Visibility = Visibility.Visible;
				grpSolidProp.Visibility = Visibility.Collapsed;
				txtNbp.Text = UserDefinedCompWizardMain.g_EditCompNbp;
				txtMolecularWeight.Text = UserDefinedCompWizardMain.g_EditCompMw;
				txtSG.Text = UserDefinedCompWizardMain.g_EditSpecificGravity;
				txtEOF.Text = UserDefinedCompWizardMain.g_EditEnthalpy;
				txtFEOF.Text = UserDefinedCompWizardMain.g_EditFreenergy;
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				base.Title = WpfFindComponentResources.UserDefComp1Caption_Solid;
				grpMoleStruct.Visibility = Visibility.Collapsed;
				grpConvProp.Visibility = Visibility.Collapsed;
				grpSolidProp.Visibility = Visibility.Visible;
				txtNbp_Solid.Text = UserDefinedCompWizardMain.g_EditCompNbp;
				txtMolecularWeight_Solid.Text = UserDefinedCompWizardMain.g_EditCompMw;
				txtEOF_Solid.Text = UserDefinedCompWizardMain.g_EditEnthalpy;
				txtFEOF_Solid.Text = UserDefinedCompWizardMain.g_EditFreenergy;
			}
			base.CanFinish = true;
			base.CanForward = true;
			base.CanBackward = true;
			if (UserDefinedCompWizardMain.g_ieditcompnbp == -1 || UserDefinedCompWizardMain.g_ieditenthalpy == -1 || UserDefinedCompWizardMain.g_ieditfreenergy == -1)
			{
				SmgeHelper.GetDefaultUnitsM(ref UserDefinedCompWizardMain.g_ieditcompnbp, ref UserDefinedCompWizardMain.g_ieditenthalpy, ref UserDefinedCompWizardMain.g_ieditfreenergy);
				if (UserDefinedCompWizardMain.g_ieditcompnbp >= 3)
				{
					UserDefinedCompWizardMain.g_ieditcompnbp--;
				}
			}
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				cboUnbp.SelectedIndex = UserDefinedCompWizardMain.g_ieditcompnbp - 1;
				cboUEof.SelectedIndex = UserDefinedCompWizardMain.g_ieditenthalpy - 1;
				cboUFEof.SelectedIndex = UserDefinedCompWizardMain.g_ieditfreenergy - 1;
			}
			else
			{
				cboUnbp_Solid.SelectedIndex = UserDefinedCompWizardMain.g_ieditcompnbp - 1;
				cboUEof_Solid.SelectedIndex = UserDefinedCompWizardMain.g_ieditenthalpy - 1;
				cboUFEof_Solid.SelectedIndex = UserDefinedCompWizardMain.g_ieditfreenergy - 1;
			}
			if (UserDefinedCompWizardMain.g_iHasMolStru == 1)
			{
				base.CanFinish = true;
			}
			else if (UserDefinedCompWizardMain.g_iHasMolStru == 2)
			{
				btnDrawStru.IsEnabled = true;
				base.CanFinish = false;
				txtInputStru.Text = WpfFindComponentResources.InputDraw;
			}
			else if (UserDefinedCompWizardMain.g_iHasMolStru == 3)
			{
				btnImportStru.IsEnabled = true;
				base.CanFinish = true;
				txtInputCon.Text = WpfFindComponentResources.InputCon;
			}
			txtNbp.ParseStyle = ParsStyles.FLOAT;
			txtMolecularWeight.ParseStyle = ParsStyles.FLOAT;
			txtSG.ParseStyle = ParsStyles.FLOAT;
			txtEOF.ParseStyle = ParsStyles.FLOAT;
			txtFEOF.ParseStyle = ParsStyles.FLOAT;
			txtNbp_Solid.ParseStyle = ParsStyles.FLOAT;
			txtMolecularWeight_Solid.ParseStyle = ParsStyles.FLOAT;
			txtEOF_Solid.ParseStyle = ParsStyles.FLOAT;
			txtFEOF_Solid.ParseStyle = ParsStyles.FLOAT;
			return true;
		}

		private void cboUnbp_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditcompnbp = cboUnbp.SelectedIndex + 1;
		}

		private void cboUEof_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditenthalpy = cboUEof.SelectedIndex + 1;
		}

		private void cboUFEof_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditfreenergy = cboUFEof.SelectedIndex + 1;
		}

		private void cboUnbp_Solid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditcompnbp = cboUnbp_Solid.SelectedIndex + 1;
		}

		private void cboUEof_Solid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditenthalpy = cboUEof_Solid.SelectedIndex + 1;
		}

		private void cboUFEof_Solid_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_ieditfreenergy = cboUFEof_Solid.SelectedIndex + 1;
		}

		private void txtEOF_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditEnthalpy = txtEOF.Text;
		}

		private void txtFEOF_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditFreenergy = txtFEOF.Text;
		}

		private void txtMolecularWeight_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditCompMw = txtMolecularWeight.Text;
			base.CanForward = true;
			base.CanFinish = true;
			base.CanBackward = true;
		}

		private void txtNbp_TextChanged(object sender, TextChangedEventArgs e)
		{
			base.CanForward = true;
			base.CanFinish = true;
			base.CanBackward = true;
			UserDefinedCompWizardMain.g_EditCompNbp = txtNbp.Text;
			string g_CompIdText = UserDefinedCompWizardMain.g_CompIdText;
			int num = 0;
			num = SmgeHelper.IsMolFileExistM(g_CompIdText);
			if (UserDefinedCompWizardMain.g_iHasMolStru > 0 && num > 0)
			{
				txtInputStru.Text = WpfFindComponentResources.MolStruAvailable;
			}
		}

		private void txtSG_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditSpecificGravity = txtSG.Text;
		}

		private void txtMolecularWeight_Solid_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditCompMw = txtMolecularWeight_Solid.Text;
		}

		private void txtNbp_Solid_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditCompNbp = txtNbp_Solid.Text;
		}

		private void txtEOF_Solid_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditEnthalpy = txtEOF_Solid.Text;
		}

		private void txtFEOF_Solid_TextChanged(object sender, TextChangedEventArgs e)
		{
			UserDefinedCompWizardMain.g_EditFreenergy = txtFEOF_Solid.Text;
		}

		private void txtNbp_LostFocus(object sender, RoutedEventArgs e)
		{
		}

		private void txtMolecularWeight_LostFocus(object sender, RoutedEventArgs e)
		{
		}

		private void txtMolecularWeight_Solid_LostFocus(object sender, RoutedEventArgs e)
		{
		}

		private void txtNbp_Solid_LostFocus(object sender, RoutedEventArgs e)
		{
		}

		private bool ValidateNbp(string range)
		{
			if (string.IsNullOrEmpty(range))
			{
				return true;
			}
			double result = 0.0;
			int num = 0;
			int length = range.Length;
			if (length == 1 && range[0] == '0')
			{
				num = 1;
			}
			if (range[0] == '0' || range[0] == '-' || range[0] == '+')
			{
				for (int i = 0; i < length; i++)
				{
					num = 0;
					if (range[i] != '0' && range[i] != '.')
					{
						break;
					}
					num = 1;
				}
				if (num != 0)
				{
					result = 0.0;
				}
			}
			if (num == 0)
			{
				bool flag = double.TryParse(range.Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol()), out result);
				if (flag)
				{
					if (UserDefinedCompWizardMain.g_ieditcompnbp == 1)
					{
						if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_K_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_K_HIGH)
						{
							MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_K_Range, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
							return false;
						}
					}
					else if (UserDefinedCompWizardMain.g_ieditcompnbp == 2)
					{
						if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_F_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_F_HIGH)
						{
							MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_F_Range, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
							return false;
						}
					}
					else if (UserDefinedCompWizardMain.g_ieditcompnbp == 3)
					{
						if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_C_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_C_HIGH)
						{
							MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_C_Range, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
							return false;
						}
					}
					else if (UserDefinedCompWizardMain.g_ieditcompnbp == 4 && (result < UserDefinedCompWizardMain.EDITNBP_UNIT_R_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_R_HIGH))
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_R_Range, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					}
				}
				if (!flag)
				{
					MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_K_Range, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
					return false;
				}
			}
			return true;
		}

		private bool ValidateMW(string range)
		{
			if (string.IsNullOrEmpty(range))
			{
				return true;
			}
			double result = 0.0;
			int num = 0;
			int length = range.Length;
			if (length == 1 && range[0] == '0')
			{
				num = 1;
			}
			if (range[0] == '0' || range[0] == '-' || range[0] == '+')
			{
				for (int i = 0; i < length; i++)
				{
					num = 0;
					if (range[i] != '0' && range[i] != '.')
					{
						break;
					}
					num = 1;
				}
				if (num != 0)
				{
					result = 0.0;
				}
			}
			if (num == 0 && !double.TryParse(range.Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol()), out result))
			{
				MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Invalid_MolWeight, ApwnResources.UserDefinedComp1_Error_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
				return false;
			}
			return true;
		}

		private bool ValidateAll()
		{
			if (UserDefinedCompWizardMain.g_CompType == "Conventional" || UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				int num = 4;
				for (int i = 0; i <= num; i++)
				{
					string text = "";
					int num2 = 0;
					int num3 = 0;
					int num4 = 0;
					switch (i)
					{
					case 0:
						text = UserDefinedCompWizardMain.g_EditCompNbp;
						break;
					case 1:
						text = UserDefinedCompWizardMain.g_EditCompMw;
						break;
					case 2:
						text = UserDefinedCompWizardMain.g_EditSpecificGravity;
						break;
					case 3:
						text = UserDefinedCompWizardMain.g_EditEnthalpy;
						break;
					case 4:
						text = UserDefinedCompWizardMain.g_EditFreenergy;
						break;
					}
					if (string.IsNullOrEmpty(text))
					{
						continue;
					}
					double result;
					if (text == "0")
					{
						num4 = 1;
					}
					else if (text[0] == '0' || text[0] == '-' || text[0] == '+')
					{
						num2 = text.Length;
						for (num3 = 1; num3 < num2; num3++)
						{
							num4 = 0;
							if (text[num3] != '0' && text[num3] != '.')
							{
								break;
							}
							num4 = 1;
							if (num2 == 2 && text[0] != '0')
							{
								num4 = 0;
							}
						}
						if (num4 != 0)
						{
							result = 0.0;
						}
					}
					if (num4 != 0)
					{
						continue;
					}
					bool flag = double.TryParse(text.Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol()), out result);
					switch (i)
					{
					case 0:
						if (flag)
						{
							if (UserDefinedCompWizardMain.g_ieditcompnbp == 1)
							{
								if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_K_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_K_HIGH)
								{
									MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_K_Range, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
									return false;
								}
							}
							else if (UserDefinedCompWizardMain.g_ieditcompnbp == 2)
							{
								if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_F_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_F_HIGH)
								{
									MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_F_Range, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
									return false;
								}
							}
							else if (UserDefinedCompWizardMain.g_ieditcompnbp == 3)
							{
								if (result < UserDefinedCompWizardMain.EDITNBP_UNIT_C_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_C_HIGH)
								{
									MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_C_Range, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
									return false;
								}
							}
							else if (UserDefinedCompWizardMain.g_ieditcompnbp == 4 && (result < UserDefinedCompWizardMain.EDITNBP_UNIT_R_LOW || result > UserDefinedCompWizardMain.EDITNBP_UNIT_R_HIGH))
							{
								MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Unit_R_Range, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
								return false;
							}
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Invalid_NBP, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					case 1:
						if (flag)
						{
							if (result < UserDefinedCompWizardMain.EDITMW_UNIT_LOW || result > UserDefinedCompWizardMain.EDITMW_UNIT_HIGH)
							{
								MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.MW_UNIT_RANGE, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
								return false;
							}
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.Invalid_MolWeight, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					case 2:
						if (flag)
						{
							if (result < UserDefinedCompWizardMain.EDITSG_UNIT_LOW || result > UserDefinedCompWizardMain.EDITSG_UNIT_HIGH)
							{
								MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.SG_UNIT_RANGE, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
								return false;
							}
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.INVALID_SG, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					case 3:
						if (flag)
						{
							if (result < UserDefinedCompWizardMain.EDITDHF_UNIT_LOW || result > UserDefinedCompWizardMain.EDITDHF_UNIT_HIGH)
							{
								MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.DHF_UNIT_RANGE, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
								return false;
							}
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.INVALID_DHF, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					case 4:
						if (flag)
						{
							if (result < UserDefinedCompWizardMain.EDITDGF_UNIT_LOW || result > UserDefinedCompWizardMain.EDITDGF_UNIT_HIGH)
							{
								MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.DGF_UNIT_RANGE, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
								return false;
							}
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.INVALID_DGF, WpfFindComponentResources.Error, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return false;
					}
				}
			}
			return true;
		}

		private void btnDrawStru_Click(object sender, RoutedEventArgs e)
		{
			string[] molefileContentAsLines = new string[0];
			IMolecularEditorPresenter molecularEditorPresenter = null;
			try
			{
				molecularEditorPresenter = FindComponentModule.Container.Resolve<IMolecularEditorPresenter>(Array.Empty<ResolverOverride>());
			}
			catch
			{
			}
			if (molecularEditorPresenter != null)
			{
				string cid = UserDefinedCompWizardMain.g_CompIdText;
				int num = 0;
				bool flag = false;
				num = SmgeHelper.IsMolFileExistM(cid);
				if (num > 0)
				{
					flag = true;
				}
				if (flag)
				{
					string[] ExistMolString = new string[num];
					SmgeHelper.GetMolFileExistM(cid, ref ExistMolString);
					string text = "";
					string[] array = ExistMolString;
					foreach (string text2 in array)
					{
						text += text2;
					}
					try
					{
						molefileContentAsLines = MoleStructCompressor.DecompressText(text).Split('\n');
					}
					catch (Exception)
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.CannotDecompress);
					}
				}
				int fragmentConsistency = -1;
				string[] array2 = new string[0];
				string[] molefileContentAsLines2 = new string[0];
				string fragmentName = "";
				bool changed = false;
				array2 = ((!flag) ? molecularEditorPresenter.OpenMolecularEditor(molefileContentAsLines2, forTDE: true, ref fragmentName, out fragmentConsistency, out changed) : molecularEditorPresenter.OpenMolecularEditor(molefileContentAsLines, forTDE: true, ref fragmentName, out fragmentConsistency, out changed));
				string text3 = "";
				string text4 = "";
				if (fragmentConsistency == 0 || fragmentConsistency == 1 || fragmentConsistency == 2 || fragmentConsistency == 3)
				{
					if (fragmentName == "")
					{
						fragmentName = "Formula";
					}
					string[] array = array2;
					foreach (string text5 in array)
					{
						text3 = text3 + text5 + "\n";
					}
					try
					{
						text4 = MoleStructCompressor.CompressText(text3);
					}
					catch (Exception)
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.CannotCompress);
					}
					int length = text4.Length;
					int num2 = length / 80 + 1;
					string[] CmprsMolString = new string[num2];
					for (int j = 0; j < num2; j++)
					{
						StringBuilder stringBuilder = new StringBuilder();
						int num3 = length - j * 80;
						if (num3 > 80)
						{
							num3 = 80;
						}
						string value = text4.Substring(j * 80, num3);
						stringBuilder.Append(value);
						stringBuilder.Append('\0');
						CmprsMolString[j] = stringBuilder.ToString();
					}
					string molfilepath = "";
					if (fragmentConsistency != 3)
					{
						SmgeHelper.SetMolFilePathM(ref cid, ref molfilepath, ref CmprsMolString, num2);
					}
					_ = 0;
					UserDefinedCompWizardMain.g_iHasMolStru = 1;
					txtInputCon.Text = "";
					switch (fragmentConsistency)
					{
					case 0:
						txtInputStru.Text = WpfFindComponentResources.InputStruText0;
						break;
					case 1:
						txtInputStru.Text = WpfFindComponentResources.InputStruText1;
						break;
					case 2:
						txtInputStru.Text = WpfFindComponentResources.InputStruText2;
						break;
					case 3:
						txtInputStru.Text = WpfFindComponentResources.InputStruText3;
						break;
					}
				}
				else
				{
					txtInputStru.Text = WpfFindComponentResources.SturctureNotDrawn;
					txtInputCon.Text = "";
					UserDefinedCompWizardMain.g_iHasMolStru = 0;
				}
			}
			else
			{
				MMMessageBox.Show(ApwnResources.FailLoadMolecularError, MMVersionHelper.MVGetI18nProductNameM(), MMMessageBoxButton.OK, MMMessageBoxImage.Exclamation);
				string g_CompFormula = UserDefinedCompWizardMain.g_CompFormula;
				if (UserDefinedCompWizardMain.g_iHasMolStru == 3)
				{
					SmgeHelper.DelStructM(ref UserDefinedCompWizardMain.g_CompIdText);
					txtInputCon.Text = "";
				}
				if (string.IsNullOrEmpty(g_CompFormula))
				{
					UserDefinedCompWizardMain.g_iHasMolStru = 2;
					base.CanFinish = false;
					UserDefinedCompWizardMain.g_CompFormula = g_CompFormula;
					txtInputStru.Text = WpfFindComponentResources.InputDraw;
					txtInputCon.Text = "";
				}
			}
		}

		private void btnImportStru_Click(object sender, RoutedEventArgs e)
		{
			string dialogTitle = ApwnResources.BrowserMolecularStructure + " - " + UserDefinedCompWizardMain.g_CompIdText;
			UserDefinedCompWizardMain.g_loadformflag = 0;
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMProp_Most.MMProp_Most_Input"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument,
				ResizeMode = ResizeMode.CanResize,
				PreferredHeight = 530,
				PreferredWidth = 1159
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Molecular Structure." + UserDefinedCompWizardMain.g_CompIdText);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_loadformflag = 1;
			UserDefinedCompWizardMain.g_molecularformflag = 1;
			UserDefinedCompWizardMain.g_iHasMolStru = 3;
			txtInputCon.Text = "";
			txtInputStru.Text = WpfFindComponentResources.InputCon;
		}

		protected override bool OnBackward(WizardControlItem targetItem)
		{
			UserDefinedCompWizardMain.DeleteUserDefComp();
			return base.OnBackward(targetItem);
		}

		protected override bool OnForward(WizardControlItem targetItem)
		{
			if (!ValidateAll())
			{
				return false;
			}
			if (targetItem == null)
			{
				return true;
			}
			if (targetItem is UserDefinedComp2 userDefinedComp)
			{
				userDefinedComp.Init();
				userDefinedComp.Title = base.Title;
				UserDefinedCompWizardMain.WriteNodeParameters();
			}
			return base.OnForward(targetItem);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/userdefinedcomp1.xaml", UriKind.Relative);
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
				grdConv = (Grid)target;
				break;
			case 2:
				txtCompID = (Label)target;
				break;
			case 3:
				txtFormula = (Label)target;
				break;
			case 4:
				grpMoleStruct = (GroupBox)target;
				break;
			case 5:
				btnDrawStru = (Button)target;
				btnDrawStru.Click += btnDrawStru_Click;
				break;
			case 6:
				txtInputStru = (TextBlock)target;
				break;
			case 7:
				btnImportStru = (Button)target;
				btnImportStru.Click += btnImportStru_Click;
				break;
			case 8:
				txtInputCon = (TextBlock)target;
				break;
			case 9:
				grpConvProp = (GroupBox)target;
				break;
			case 10:
				txtMolecularWeight = (TextBoxEx)target;
				break;
			case 11:
				txtNbp = (TextBoxEx)target;
				break;
			case 12:
				cboUnbp = (ComboBox)target;
				cboUnbp.SelectionChanged += cboUnbp_SelectionChanged;
				break;
			case 13:
				txtSG = (TextBoxEx)target;
				break;
			case 14:
				txtEOF = (TextBoxEx)target;
				break;
			case 15:
				cboUEof = (ComboBox)target;
				cboUEof.SelectionChanged += cboUEof_SelectionChanged;
				break;
			case 16:
				txtFEOF = (TextBoxEx)target;
				break;
			case 17:
				cboUFEof = (ComboBox)target;
				cboUFEof.SelectionChanged += cboUFEof_SelectionChanged;
				break;
			case 18:
				grpSolidProp = (GroupBox)target;
				break;
			case 19:
				txtMolecularWeight_Solid = (TextBoxEx)target;
				break;
			case 20:
				txtNbp_Solid = (TextBoxEx)target;
				break;
			case 21:
				cboUnbp_Solid = (ComboBox)target;
				cboUnbp_Solid.SelectionChanged += cboUnbp_Solid_SelectionChanged;
				break;
			case 22:
				txtEOF_Solid = (TextBoxEx)target;
				break;
			case 23:
				cboUEof_Solid = (ComboBox)target;
				cboUEof_Solid.SelectionChanged += cboUEof_Solid_SelectionChanged;
				break;
			case 24:
				txtFEOF_Solid = (TextBoxEx)target;
				break;
			case 25:
				cboUFEof_Solid = (ComboBox)target;
				cboUFEof_Solid.SelectionChanged += cboUFEof_Solid_SelectionChanged;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UserDefinedComp2 : WizardControlItem, IComponentConnector
	{
		internal Button btnLRHO;

		internal Button btnVP;

		internal Button btnVPC;

		internal Button btnHC;

		internal Button btnHCC;

		internal Label lblLRHO;

		internal Label lblSVPD;

		internal Label lblSVPC;

		internal Label lblSHCD;

		internal Label lblSHCC;

		internal RadioButton radioEstde;

		internal Button btnTDE;

		internal RadioButton radioEsaspen;

		private bool _contentLoaded;

		public UserDefinedComp2()
		{
			InitializeComponent();
			Init();
		}

		public void Init()
		{
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				lblSHCD.Content = WpfFindComponentResources.ShcdText_Conv;
				lblSHCC.Content = WpfFindComponentResources.ShccText_Conv;
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				lblSHCD.Content = WpfFindComponentResources.ShcdText_Solid;
				lblSHCC.Content = WpfFindComponentResources.ShccText_Solid;
			}
			base.CanFinish = true;
			base.CanBackward = true;
			UserDefinedCompWizardMain.g_loadformflag = 0;
			SmgeHelper.SMestiUserDefM(-1);
			btnTDE.IsEnabled = false;
			if (UserDefinedCompWizardMain.g_iHasMolStru == 0)
			{
				radioEstde.IsEnabled = false;
				btnTDE.IsEnabled = false;
				radioEsaspen.IsChecked = true;
				SmgeHelper.SMestiUserDefM(1);
			}
			else if (UserDefinedCompWizardMain.g_iHasMolStru == 1)
			{
				radioEstde.IsEnabled = true;
				radioEstde.IsChecked = true;
				btnTDE.IsEnabled = true;
				base.CanFinish = false;
			}
			else if (UserDefinedCompWizardMain.g_iHasMolStru == 3)
			{
				if (SmgeHelper.IsMolFileExistM(UserDefinedCompWizardMain.g_CompIdText) > 0)
				{
					radioEstde.IsEnabled = true;
				}
				else
				{
					radioEstde.IsEnabled = false;
				}
				radioEstde.IsChecked = false;
				radioEsaspen.IsChecked = true;
				btnTDE.IsEnabled = false;
				base.CanFinish = true;
				SmgeHelper.SMestiUserDefM(1);
			}
		}

		protected override bool OnBackward(WizardControlItem targetItem)
		{
			UserDefinedCompWizardMain.ReadParameters();
			return base.OnBackward(targetItem);
		}

		private void btnHC_Click(object sender, RoutedEventArgs e)
		{
			string propname = "";
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				propname = "CPIG";
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				propname = "CPS";
			}
			string dialogTitle = WpfFindComponentResources.Header_HC + " - " + UserDefinedCompWizardMain.g_CompIdText;
			string nameofrec = "";
			if (SmgeHelper.ChkDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) == 0)
			{
				while (true)
				{
					IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfFindComponentResources.EnterID, WpfFindComponentResources.EnterHeatID, IDBoxDlg.IDType.ID);
					iDBoxDlg.Owner = Window.GetWindow(this);
					if (!iDBoxDlg.ShowDialog().Value)
					{
						return;
					}
					nameofrec = iDBoxDlg.ID;
					if (nameofrec.Contains(" "))
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.BlankNotAllowedForRecordID, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return;
					}
					if (!string.IsNullOrEmpty(nameofrec))
					{
						if (SmgeHelper.CreateDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) != -1)
						{
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.HeatIDAlreadyExist, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
					}
				}
			}
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMData_Pure.MMData_Pure_Input"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Data." + nameofrec);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_iHasHc = 1;
		}

		private void btnHCC_Click(object sender, RoutedEventArgs e)
		{
			string dialogTitle = "";
			string nameofrec = "";
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				dialogTitle = WpfFindComponentResources.IdealGasHeatCapacityPolynomialCoefficientsTitle + " - " + UserDefinedCompWizardMain.g_CompIdText;
				UserDefinedCompWizardMain.g_loadformflag = 0;
				nameofrec = "CPIG-1";
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				dialogTitle = WpfFindComponentResources.SolidHeatCapacityPolynomialCoefficientsTitle + " - " + UserDefinedCompWizardMain.g_CompIdText;
				UserDefinedCompWizardMain.g_loadformflag = 0;
				nameofrec = "CPSPO1-1";
			}
			SmgeHelper.CreateRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText);
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMParam_PureCor.MMParam_PureCor_In_Para"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Parameters.Pure Components." + nameofrec);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_iHasHcC = 1;
		}

		private void btnLRHO_Click(object sender, RoutedEventArgs e)
		{
			string propname = "";
			string nameofrec = "";
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				propname = "VL";
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				propname = "VS";
			}
			string dialogTitle = WpfFindComponentResources.MolarVolumeDataTitle + " - " + UserDefinedCompWizardMain.g_CompIdText;
			if (SmgeHelper.ChkDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) == 0)
			{
				while (true)
				{
					IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfFindComponentResources.EnterID, WpfFindComponentResources.EnterLiquidID, IDBoxDlg.IDType.ID);
					iDBoxDlg.Owner = Window.GetWindow(this);
					if (!iDBoxDlg.ShowDialog().Value)
					{
						return;
					}
					nameofrec = iDBoxDlg.ID;
					if (nameofrec.Contains(" "))
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.BlankNotAllowedForRecordID, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return;
					}
					if (!string.IsNullOrEmpty(nameofrec))
					{
						if (SmgeHelper.CreateDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) != -1)
						{
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.LiquidIDAlreadyExist, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
					}
				}
			}
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMData_Pure.MMData_Pure_Input"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Data." + nameofrec);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_iHasLrho = 1;
		}

		private void btnVP_Click(object sender, RoutedEventArgs e)
		{
			string propname = "";
			string nameofrec = "";
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				propname = "PL";
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				propname = "PS";
			}
			string dialogTitle = WpfFindComponentResources.Header_VP + " - " + UserDefinedCompWizardMain.g_CompIdText;
			if (SmgeHelper.ChkDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) == 0)
			{
				while (true)
				{
					IDBoxDlg iDBoxDlg = new IDBoxDlg(WpfFindComponentResources.EnterID, WpfFindComponentResources.EnterVaporID, IDBoxDlg.IDType.ID);
					iDBoxDlg.Owner = Window.GetWindow(this);
					if (!iDBoxDlg.ShowDialog().Value)
					{
						return;
					}
					nameofrec = iDBoxDlg.ID;
					if (nameofrec.Contains(" "))
					{
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.BlankNotAllowedForRecordID, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
						return;
					}
					if (!string.IsNullOrEmpty(nameofrec))
					{
						if (SmgeHelper.CreateDataRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText, ref propname) != -1)
						{
							break;
						}
						MMMessageBox.Show(Window.GetWindow(this), WpfFindComponentResources.VaporIDAlreadyExist, ApwnResources.UserDefWizard_Title, MMMessageBoxButton.OK, MMMessageBoxImage.Error);
					}
				}
			}
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMData_Pure.MMData_Pure_Input"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Data." + nameofrec);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_iHasVp = 1;
		}

		private void btnVPC_Click(object sender, RoutedEventArgs e)
		{
			string dialogTitle = "";
			string nameofrec = "";
			if (UserDefinedCompWizardMain.g_CompType == "Conventional")
			{
				dialogTitle = WpfFindComponentResources.SvpcText_Conv_Header + " - " + UserDefinedCompWizardMain.g_CompIdText;
				UserDefinedCompWizardMain.g_loadformflag = 0;
				nameofrec = "PLXANT-1";
			}
			else if (UserDefinedCompWizardMain.g_CompType == "Solid")
			{
				dialogTitle = WpfFindComponentResources.SvpcText_Conv_Header + "-" + UserDefinedCompWizardMain.g_CompIdText;
				UserDefinedCompWizardMain.g_loadformflag = 0;
				nameofrec = "PSXANT-1";
			}
			SmgeHelper.CreateRecordM(ref nameofrec, ref UserDefinedCompWizardMain.g_CompIdText);
			DriveDialogEventArgs e2 = new DriveDialogEventArgs
			{
				DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMParam_PureCor.MMParam_PureCor_In_Para"),
				DialogTitle = dialogTitle,
				Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
			};
			e2.FormParameters.Add("main", "Top.appModelV8.Properties.Parameters.Pure Components." + nameofrec);
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e2);
			UserDefinedCompWizardMain.g_iHasVpC = 1;
		}

		private void btnTDE_Click(object sender, RoutedEventArgs e)
		{
			TDEPureDataEventArgs e2 = new TDEPureDataEventArgs();
			e2.Name = UserDefinedCompWizardMain.g_CompIdText;
			e2.iHasMolStru = UserDefinedCompWizardMain.g_iHasMolStru;
			e2.iHasscale = 1;
			e2.iHasLiqRho = UserDefinedCompWizardMain.g_iHasLrho;
			e2.iHasVapPres = UserDefinedCompWizardMain.g_iHasVp;
			e2.iHasAntoine = UserDefinedCompWizardMain.g_iHasVpC;
			e2.iHasCpData = UserDefinedCompWizardMain.g_iHasHc;
			e2.iHasCpCoe = UserDefinedCompWizardMain.g_iHasHcC;
			e2.Formula = UserDefinedCompWizardMain.g_CompFormula;
			FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<RetrieveTDEPureDataEvent>().Publish(e2);
			base.CanFinish = true;
			base.ParentWizard.Finish();
		}

		private void radioEsaspen_Click(object sender, RoutedEventArgs e)
		{
			btnTDE.IsEnabled = false;
			SmgeHelper.SMestiUserDefM(1);
			base.CanFinish = true;
		}

		private void radioEstde_Click(object sender, RoutedEventArgs e)
		{
			btnTDE.IsEnabled = true;
			SmgeHelper.SMestiUserDefM(0);
			base.CanFinish = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/userdefinedcomp2.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				btnLRHO = (Button)target;
				btnLRHO.Click += btnLRHO_Click;
				break;
			case 2:
				btnVP = (Button)target;
				btnVP.Click += btnVP_Click;
				break;
			case 3:
				btnVPC = (Button)target;
				btnVPC.Click += btnVPC_Click;
				break;
			case 4:
				btnHC = (Button)target;
				btnHC.Click += btnHC_Click;
				break;
			case 5:
				btnHCC = (Button)target;
				btnHCC.Click += btnHCC_Click;
				break;
			case 6:
				lblLRHO = (Label)target;
				break;
			case 7:
				lblSVPD = (Label)target;
				break;
			case 8:
				lblSVPC = (Label)target;
				break;
			case 9:
				lblSHCD = (Label)target;
				break;
			case 10:
				lblSHCC = (Label)target;
				break;
			case 11:
				radioEstde = (RadioButton)target;
				radioEstde.Click += radioEstde_Click;
				break;
			case 12:
				btnTDE = (Button)target;
				btnTDE.Click += btnTDE_Click;
				break;
			case 13:
				radioEsaspen = (RadioButton)target;
				radioEsaspen.Click += radioEsaspen_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UserDefinedCompWizardMain : Window, IComponentConnector
	{
		private UserDefinedComp0 comp0;

		private UserDefinedComp1 comp1;

		private UserDefinedComp2 comp2;

		public static List<string> g_existingCompList = new List<string>();

		public static string g_CompIdText = "";

		public static string g_CompType = "Conventional";

		public static string g_CompFormula = "";

		public static string g_EditCompNbp = "";

		public static string g_EditCompMw = "";

		public static string g_EditSpecificGravity = "";

		public static string g_EditEnthalpy = "";

		public static string g_EditFreenergy = "";

		public static string g_FormTitle = "";

		public static string g_Curstr = "";

		public static byte g_Curset = 0;

		public static byte g_loadformflag = 0;

		public static byte g_molecularformflag = 0;

		public static int g_ieditcompnbp = -1;

		public static int g_ieditenthalpy = -1;

		public static int g_ieditfreenergy = -1;

		public static int g_storecompflag = 0;

		public static int g_iHasMolStru = 0;

		public static int g_iHasLrho = 0;

		public static int g_iHasVp = 0;

		public static int g_iHasVpC = 0;

		public static int g_iHasHc = 0;

		public static int g_iHasHcC = 0;

		public static int g_m_IsTDEButton = 0;

		public static readonly double EDITNBP_UNIT_K_LOW = 0.0;

		public static readonly double EDITNBP_UNIT_K_HIGH = 100000.0;

		public static readonly double EDITNBP_UNIT_F_LOW = -459.67;

		public static readonly double EDITNBP_UNIT_F_HIGH = 179540.0;

		public static readonly double EDITNBP_UNIT_C_LOW = -273.15;

		public static readonly double EDITNBP_UNIT_C_HIGH = 99726.9;

		public static readonly double EDITNBP_UNIT_R_LOW = 0.0;

		public static readonly double EDITNBP_UNIT_R_HIGH = 180000.0;

		public static readonly double EDITMW_UNIT_LOW = 0.0;

		public static readonly double EDITMW_UNIT_HIGH = 1E+35;

		public static readonly double EDITSG_UNIT_LOW = 0.0;

		public static readonly double EDITSG_UNIT_HIGH = 3.0;

		public static readonly double EDITDHF_UNIT_LOW = -1E+35;

		public static readonly double EDITDHF_UNIT_HIGH = 1E+35;

		public static readonly double EDITDGF_UNIT_LOW = -1E+35;

		public static readonly double EDITDGF_UNIT_HIGH = 1E+35;

		internal WizardControl theWizard;

		internal Button buttonCancel;

		private bool _contentLoaded;

		public int CurrentRecord { get; private set; }

		public UserDefinedCompWizardMain()
		{
			InitializeComponent();
		}

		public UserDefinedCompWizardMain(int index)
			: this()
		{
			InitStaticMembers();
			CurrentRecord = index;
			comp0 = new UserDefinedComp0(CurrentRecord);
			comp1 = new UserDefinedComp1();
			comp2 = new UserDefinedComp2();
			theWizard.Items.Add(comp0);
			theWizard.Items.Add(comp1);
			theWizard.Items.Add(comp2);
		}

		private void InitStaticMembers()
		{
			g_CompIdText = "";
			g_CompType = "Conventional";
			g_CompFormula = "";
			g_EditCompNbp = "";
			g_EditCompMw = "";
			g_EditSpecificGravity = "";
			g_EditEnthalpy = "";
			g_EditFreenergy = "";
			g_FormTitle = "";
			g_Curstr = "";
			g_Curset = 0;
			g_loadformflag = 0;
			g_molecularformflag = 0;
			g_ieditcompnbp = -1;
			g_ieditenthalpy = -1;
			g_ieditfreenergy = -1;
			g_storecompflag = 0;
			g_iHasMolStru = 0;
			g_iHasLrho = 0;
			g_iHasVp = 0;
			g_iHasVpC = 0;
			g_iHasHc = 0;
			g_iHasHcC = 0;
			g_m_IsTDEButton = 0;
			g_existingCompList.Clear();
			string nextcomp = string.Empty;
			SmgeHelper.ListUserDefCompM(ref nextcomp, 1);
			if (!string.IsNullOrEmpty(nextcomp))
			{
				g_existingCompList.Add(nextcomp);
			}
			while (!string.IsNullOrEmpty(nextcomp))
			{
				SmgeHelper.ListUserDefCompM(ref nextcomp, 0);
				g_existingCompList.Add(nextcomp);
			}
		}

		public static bool ComponentIDPresent()
		{
			if (string.IsNullOrEmpty(g_CompIdText))
			{
				return false;
			}
			SmgeHelper.CheckifCIDisUsedM(ref g_CompIdText);
			return true;
		}

		public static bool FormulaPresent(Window ownerWnd)
		{
			if ((g_CompType == "Conventional" || g_CompType == "Solid") && SmgeHelper.CheckFormulaInDBM(ref g_CompFormula) == 1)
			{
				int checkbox = 0;
				if (OpenMessageBox.Show(WpfFindComponentResources.AliasExist, WpfFindComponentResources.FormulaMsgBox, WpfFindComponentResources.OK, WpfFindComponentResources.Cancel, "", "", "", 1, ref checkbox, -1, ownerWnd) != 1)
				{
					return false;
				}
				return true;
			}
			return true;
		}

		public static int WriteUserDefComp()
		{
			string type = "";
			int num = 0;
			if (g_CompType == "Conventional")
			{
				type = "CONV";
				num = 1;
			}
			else if (g_CompType == "Nonconventional")
			{
				type = "NC";
				num = 2;
			}
			else if (g_CompType == "Solid")
			{
				type = "SOLID";
				num = 1;
			}
			int result = 0;
			switch (num)
			{
			case 1:
				result = SmgeHelper.SetUserDefCompM(ref g_CompIdText, ref type, ref g_CompFormula);
				break;
			case 2:
			{
				string formula = "";
				result = SmgeHelper.SetUserDefCompM(ref g_CompIdText, ref type, ref formula);
				break;
			}
			}
			return result;
		}

		public static int ReadUserDefComp(string str)
		{
			string type = "";
			string formula = "";
			int result = SmgeHelper.SetUserDefCompM(ref str, ref type, ref formula);
			switch (type)
			{
			case "CONV":
				g_CompType = "Conventional";
				break;
			case "NC":
				g_CompType = "Nonconventional";
				break;
			case "SOLID":
				g_CompType = "Solid";
				break;
			}
			g_CompFormula = formula;
			return result;
		}

		public static bool DeleteUserDefComp()
		{
			if (string.IsNullOrEmpty(g_CompIdText))
			{
				return false;
			}
			if (g_storecompflag == 1)
			{
				SmgeHelper.DeleteCompM(ref g_CompIdText);
				g_storecompflag = 0;
				return true;
			}
			if (g_CompType == "Nonconventional" && !g_existingCompList.Contains(g_CompIdText))
			{
				SmgeHelper.DeleteCompM(ref g_CompIdText);
			}
			return true;
		}

		public static void ReadParameters()
		{
			if (g_storecompflag == 1)
			{
				g_EditCompNbp = "";
				g_EditCompMw = "";
				g_EditSpecificGravity = "";
				g_EditEnthalpy = "";
				g_EditFreenergy = "";
			}
			else
			{
				if (g_storecompflag != -1)
				{
					return;
				}
				string text = "";
				string value = "";
				int unitindex = 0;
				if (g_ieditcompnbp == -1 || g_ieditenthalpy == -1 || g_ieditfreenergy == -1)
				{
					SmgeHelper.GetDefaultUnitsM(ref g_ieditcompnbp, ref g_ieditenthalpy, ref g_ieditfreenergy);
					if (g_ieditcompnbp >= 3)
					{
						g_ieditcompnbp--;
					}
				}
				text = "MW";
				SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
				if (!string.IsNullOrEmpty(value))
				{
					g_EditCompMw = value;
				}
				text = "TB";
				SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
				if (!string.IsNullOrEmpty(value))
				{
					g_EditCompNbp = value;
					g_ieditcompnbp = unitindex;
					if (g_ieditcompnbp >= 3)
					{
						g_ieditcompnbp--;
					}
				}
				if (g_CompType == "Conventional")
				{
					text = "SG";
					SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
					if (!string.IsNullOrEmpty(value))
					{
						g_EditSpecificGravity = value;
					}
					text = "DHFORM";
					SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
					if (!string.IsNullOrEmpty(value))
					{
						g_EditEnthalpy = value;
						g_ieditenthalpy = unitindex;
					}
					text = "DGFORM";
					SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
					if (!string.IsNullOrEmpty(value))
					{
						g_EditFreenergy = value;
						g_ieditfreenergy = unitindex;
					}
				}
				else if (g_CompType == "Solid")
				{
					text = "DHSFRM";
					SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
					if (!string.IsNullOrEmpty(value))
					{
						g_EditEnthalpy = value;
						g_ieditenthalpy = unitindex;
					}
					text = "DGSFRM";
					SmgeHelper.GetParameterM(ref text, ref g_CompIdText, ref value, ref unitindex);
					if (!string.IsNullOrEmpty(value))
					{
						g_EditFreenergy = value;
						g_ieditfreenergy = unitindex;
					}
				}
			}
		}

		public static void UpdateWizard()
		{
			if (g_CompType == "Nonconventional")
			{
				string dialogTitle = $"{WpfFindComponentResources.Nonconventional_component}-{g_CompIdText}";
				g_loadformflag = 0;
				SmgeHelper.SetNCDummyM(ref g_CompIdText);
				DriveDialogEventArgs e = new DriveDialogEventArgs
				{
					DialogType = FindComponentModule.Container.Resolve<MMFormsCatalog>(Array.Empty<ResolverOverride>()).LookupControlType("MMNCProps.MMNCProps_Input_MethDB"),
					DialogTitle = dialogTitle,
					Doc = FindComponentModule.Container.Resolve<IApwnApplication>(Array.Empty<ResolverOverride>()).ActiveDocument
				};
				e.FormParameters.Add("main", "Top.appModelV8.Properties.Advanced.NC-Props");
				FindComponentModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>()).GetEvent<DriveDialogEvent>().Publish(e);
				g_loadformflag = 1;
			}
		}

		public static void WriteNodeParameters()
		{
			bool flag = false;
			int num = 0;
			double result = 0.0;
			string text = "";
			string text2 = "";
			string value = "";
			int unitindex = 0;
			if (g_CompType == "Conventional")
			{
				num = g_ieditcompnbp - 1;
				if (num >= 2)
				{
					num++;
				}
				if (!string.IsNullOrEmpty(g_EditCompNbp))
				{
					bool num2 = ValidateEditBoxString(ref g_EditCompNbp);
					flag = double.TryParse(g_EditCompNbp, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num2 && flag)
					{
						g_EditCompNbp = text;
					}
				}
				text2 = "TB";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditCompNbp, StringComparison.InvariantCulture) || unitindex != num + 1)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompNbp, num + 1);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditCompNbp))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompNbp, num + 1);
				}
				if (!string.IsNullOrEmpty(g_EditCompMw))
				{
					bool num3 = ValidateEditBoxString(ref g_EditCompMw);
					flag = double.TryParse(g_EditCompMw, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num3 && flag)
					{
						g_EditCompMw = text;
					}
					text2 = "MW";
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompMw, 0);
				}
				if (!string.IsNullOrEmpty(g_EditSpecificGravity))
				{
					bool num4 = ValidateEditBoxString(ref g_EditSpecificGravity);
					flag = double.TryParse(g_EditSpecificGravity, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num4 && flag)
					{
						g_EditSpecificGravity = text;
					}
				}
				text2 = "SG";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditSpecificGravity, StringComparison.InvariantCulture))
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditSpecificGravity, 0);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditSpecificGravity))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditSpecificGravity, 0);
				}
				if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					bool num5 = ValidateEditBoxString(ref g_EditEnthalpy);
					flag = double.TryParse(g_EditEnthalpy, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num5)
					{
						g_EditEnthalpy = text;
					}
				}
				text2 = "DHFORM";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditEnthalpy, StringComparison.InvariantCulture) || unitindex != g_ieditenthalpy)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditEnthalpy, g_ieditenthalpy);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditEnthalpy, g_ieditenthalpy);
				}
				if (!string.IsNullOrEmpty(g_EditFreenergy))
				{
					bool num6 = ValidateEditBoxString(ref g_EditFreenergy);
					flag = double.TryParse(g_EditFreenergy, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num6 && flag)
					{
						g_EditFreenergy = text;
					}
				}
				text2 = "DGFORM";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditFreenergy, StringComparison.InvariantCulture) || unitindex != g_ieditfreenergy)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditFreenergy, g_ieditfreenergy);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditFreenergy, g_ieditfreenergy);
				}
			}
			else
			{
				if (!(g_CompType == "Solid"))
				{
					return;
				}
				num = g_ieditcompnbp - 1;
				if (num >= 2)
				{
					num++;
				}
				if (!string.IsNullOrEmpty(g_EditCompMw))
				{
					bool num7 = ValidateEditBoxString(ref g_EditCompMw);
					flag = double.TryParse(g_EditCompMw, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num7 && flag)
					{
						g_EditCompMw = text;
					}
				}
				text2 = "MW";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditCompMw))
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompMw, 0);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditCompMw))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompMw, 0);
				}
				if (!string.IsNullOrEmpty(g_EditCompNbp))
				{
					bool num8 = ValidateEditBoxString(ref g_EditCompNbp);
					flag = double.TryParse(g_EditCompNbp, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num8)
					{
						g_EditCompNbp = text;
					}
				}
				text2 = "TB";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditCompNbp) || unitindex != num + 1)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompNbp, num + 1);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditCompNbp))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditCompNbp, num + 1);
				}
				if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					bool num9 = ValidateEditBoxString(ref g_EditEnthalpy);
					flag = double.TryParse(g_EditEnthalpy, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num9)
					{
						g_EditEnthalpy = text;
					}
				}
				text2 = "DHSFRM";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditEnthalpy) || unitindex != g_ieditenthalpy)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditEnthalpy, g_ieditenthalpy);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditEnthalpy, g_ieditenthalpy);
				}
				if (!string.IsNullOrEmpty(g_EditFreenergy))
				{
					bool num10 = ValidateEditBoxString(ref g_EditFreenergy);
					flag = double.TryParse(g_EditFreenergy, NumberStyles.AllowDecimalPoint, NumberFormatInfo.InvariantInfo, out result);
					text = result.ToString();
					if (!num10)
					{
						g_EditFreenergy = text;
					}
				}
				text2 = "DGSFRM";
				if (SmgeHelper.GetParameterM(ref text2, ref g_CompIdText, ref value, ref unitindex) != 0)
				{
					if (!value.Equals(g_EditFreenergy, StringComparison.InvariantCulture) || unitindex != g_ieditfreenergy)
					{
						SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditFreenergy, g_ieditfreenergy);
					}
				}
				else if (!string.IsNullOrEmpty(g_EditEnthalpy))
				{
					SmgeHelper.SetParameterM(ref text2, ref g_CompIdText, ref g_EditFreenergy, g_ieditfreenergy);
				}
			}
		}

		public static bool ValidateEditBoxString(ref string str)
		{
			str.Replace('d', 'e');
			str.Replace('D', 'e');
			double result;
			return double.TryParse(str.Replace(".", MaskingAndValidatingHelper.GetSystemDecimalSymbol()), out result);
		}

		private void theWizard_Finished(object sender, RoutedEventArgs e)
		{
			int num = 0;
			if (Regex.IsMatch(g_CompIdText, "[^\\u0000-\\u007F]") || Regex.IsMatch(g_CompFormula, "[^\\u0000-\\u007F]"))
			{
				MaskingAndValidatingHelper.PopupNoneAsciiCharMsg();
				return;
			}
			if (g_CompType == "Nonconventional")
			{
				if (theWizard.CurrentItem != comp0)
				{
					return;
				}
				num = comp0.ProcessNext();
				if (num == 1 && g_storecompflag != -1)
				{
					if (g_loadformflag != 0)
					{
						MMMessageBox.Show(this, WpfFindComponentResources.SavePropData, WpfFindComponentResources.SavePropDataTitle);
					}
					base.DialogResult = true;
					Close();
				}
				else
				{
					MMMessageBox.Show(this, WpfFindComponentResources.CannotChangeCompType, ApwnResources.UserDefWizard_Title);
					g_storecompflag = 0;
				}
				return;
			}
			if (theWizard.CurrentItem == comp0)
			{
				num = comp0.ProcessNext();
				if (num == 1 && g_storecompflag == -2)
				{
					MMMessageBox.Show(this, WpfFindComponentResources.CannotChangeCompType, ApwnResources.UserDefWizard_Title);
					g_storecompflag = 0;
					base.DialogResult = true;
					Close();
					return;
				}
				if (num == 0)
				{
					return;
				}
			}
			else if (theWizard.CurrentItem == comp1)
			{
				WriteNodeParameters();
			}
			else if (theWizard.CurrentItem == comp2)
			{
				MMMessageBox.Show(this, WpfFindComponentResources.SaveingPropertyData, WpfFindComponentResources.SaveingPropertyDataCaption);
				WriteNodeParameters();
			}
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			DeleteUserDefComp();
			InitStaticMembers();
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfFindComponent;component/userdefinedcompwizardmain.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				theWizard = (WizardControl)target;
				theWizard.Finished += theWizard_Finished;
				break;
			case 2:
				buttonCancel = (Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}

// Coverage appendix for compiler-folded declarations and MethodDef implementations.
// The active C# above contains the reconstructed high-level forms. The comments below retain
// metadata names and show the expansions of methods that lack a direct declaration or sequence point in those forms.
// 0x02000002 <>f__AnonymousType0`2
//   0x04000001 field: `0 <x>i__Field
//   0x04000002 field: `1 <index>i__Field
//   0x17000001 property: `0 x
//   0x17000002 property: `1 index
// 0x0200003e AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c
//   0x0400027a field: AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c <>9
//   0x0400027b field: System.Func`2[[System.String],[System.String]] <>9__8_0
//   0x0400027c field: System.Func`2[[AspenTech.AspenPlus.MMControls.Scripting.DialogArg],[System.Boolean]] <>9__8_1
//   0x0400027d field: System.Func`2[[AspenTech.AspenPlus.MMControls.Scripting.DialogArg],[System.String]] <>9__8_2
// 0x0200003f AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c__DisplayClass8_0
//   0x0400027e field: AspenTech.AspenPlus.UnmanagedWrapper.DbankComponentItem fc
// 0x02000040 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c
//   0x0400027f field: AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c <>9
//   0x04000280 field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.PropertySetItem],[System.String]] <>9__55_0
//   0x04000281 field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.PropertySetItem],[System.String]] <>9__55_1
//   0x04000282 field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.PropertySetItem],[System.String]] <>9__55_2
//   0x04000283 field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.PropertySetItem],[System.String]] <>9__55_3
// 0x02000041 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass33_0
//   0x04000284 field: AspenTech.AspenPlus.UnmanagedWrapper.PropertyItem prop
// 0x02000042 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass38_0
//   0x04000285 field: AspenTech.AspenPlus.WpfFindComponent.PropertySetItem prop
// 0x02000043 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass38_1
//   0x04000286 field: AspenTech.AspenPlus.WpfFindComponent.PropertySetItem prop
// 0x02000044 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass43_0
//   0x04000287 field: AspenTech.AspenPlus.WpfFindComponent.PropertySetItem prop
// 0x02000045 AspenTech.AspenPlus.WpfFindComponent.BiomassLookupViewModel+<>c
//   0x04000288 field: AspenTech.AspenPlus.WpfFindComponent.BiomassLookupViewModel+<>c <>9
//   0x04000289 field: System.Func`2[[System.String],[System.String]] <>9__15_0
//   0x0400028a field: System.Func`2[[System.String],[System.String]] <>9__18_0
//   0x0400028b field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.Compound],[System.Boolean]] <>9__24_0
//   0x0400028c field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[System.Boolean]] <>9__24_1
//   0x0400028d field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[System.String]] <>9__24_2
//   0x0400028e field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[AspenTech.AspenPlus.WpfFindComponent.Compound]] <>9__24_3
//   0x0400028f field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.Compound],[System.Boolean]] <>9__25_0
//   0x04000290 field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[System.Boolean]] <>9__25_1
//   0x04000291 field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[System.String]] <>9__25_2
//   0x04000292 field: System.Func`2[[System.Collections.Generic.KeyValuePair`2[[System.String],[AspenTech.AspenPlus.WpfFindComponent.Compound]]],[AspenTech.AspenPlus.WpfFindComponent.Compound]] <>9__25_3
//   0x04000293 field: System.Func`2[[System.String],[System.String]] <>9__29_0
// 0x02000047 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c
//   0x04000296 field: AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c <>9
//   0x04000297 field: System.Func`2[[AspenTech.AspenPlus.WpfFindComponent.TreeNode],[System.String]] <>9__68_0
// 0x02000048 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c__DisplayClass76_0
//   0x04000298 field: System.String csText
// 0x02000049 AspenTech.AspenPlus.WpfFindComponent.PagingControl+<>c__DisplayClass19_0
//   0x04000299 field: System.Nullable`1[[System.Int32]] newValue
// 0x0200004a AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecuteNextPageCommand>d__29
//   0x0400029a field: System.Int32 <>1__state
//   0x0400029b field: System.Runtime.CompilerServices.AsyncVoidMethodBuilder <>t__builder
//   0x0400029c field: AspenTech.AspenPlus.WpfFindComponent.PagingControl <>4__this
// 0x0200004b AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecutePrePageCommand>d__24
//   0x0400029d field: System.Int32 <>1__state
//   0x0400029e field: System.Runtime.CompilerServices.AsyncVoidMethodBuilder <>t__builder
//   0x0400029f field: AspenTech.AspenPlus.WpfFindComponent.PagingControl <>4__this
// 0x0200004c AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteAddCommand>d__59
//   0x040002a0 field: System.Int32 <>1__state
//   0x040002a1 field: System.Runtime.CompilerServices.AsyncVoidMethodBuilder <>t__builder
//   0x040002a2 field: AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel <>4__this
// 0x0200004d AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteSearchCommand>d__54
//   0x040002a3 field: System.Int32 <>1__state
//   0x040002a4 field: System.Runtime.CompilerServices.AsyncVoidMethodBuilder <>t__builder
//   0x040002a5 field: AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel <>4__this
//   0x040002a6 field: System.Runtime.CompilerServices.TaskAwaiter`1[[System.Collections.Generic.List`1[[System.String]]]] <>u__1
// 0x0200004e AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<GotoPage>d__30
//   0x040002a7 field: System.Int32 <>1__state
//   0x040002a8 field: System.Runtime.CompilerServices.AsyncVoidMethodBuilder <>t__builder
//   0x040002a9 field: AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel <>4__this
//   0x040002aa field: System.Int32 pageId
//   0x040002ab field: System.Int32 <index>5__2
//   0x040002ac field: System.Runtime.CompilerServices.TaskAwaiter`1[[AspenTech.AspenPlus.WpfFindComponent.PubChemCompound]] <>u__1
// 0x02000055 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<>c
//   0x040002bd field: AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<>c <>9
//   0x040002be field: System.Func`2[[System.Char],[System.Boolean]] <>9__10_0
// 0x02000056 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<GetCompoundDataAsync>d__11
//   0x040002bf field: System.Int32 <>1__state
//   0x040002c0 field: System.Runtime.CompilerServices.AsyncTaskMethodBuilder`1[[AspenTech.AspenPlus.WpfFindComponent.PubChemCompound]] <>t__builder
//   0x040002c1 field: System.String nameOrCid
//   0x040002c2 field: AspenTech.AspenPlus.WpfFindComponent.PubChemCompound <compound>5__2
//   0x040002c3 field: System.Runtime.CompilerServices.TaskAwaiter`1[[AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+CompoundModel]] <>u__1
//   0x040002c4 field: System.Runtime.CompilerServices.TaskAwaiter`1[[System.Byte[]]] <>u__2
// 0x02000057 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<ReadContentAsAsync>d__9`1
//   0x040002c5 field: System.Int32 <>1__state
//   0x040002c6 field: System.Runtime.CompilerServices.AsyncTaskMethodBuilder`1[[`0]] <>t__builder
//   0x040002c7 field: System.String url
//   0x040002c8 field: System.Int32 <attempts>5__2
//   0x040002c9 field: System.Int32 <max_attempts>5__3
//   0x040002ca field: `0 <result>5__4
//   0x040002cb field: System.Net.Http.HttpResponseMessage <response>5__5
//   0x040002cc field: System.Runtime.CompilerServices.TaskAwaiter`1[[System.Net.Http.HttpResponseMessage]] <>u__1
//   0x040002cd field: System.Runtime.CompilerServices.TaskAwaiter`1[[System.Byte[]]] <>u__2
//   0x040002ce field: System.Runtime.CompilerServices.TaskAwaiter`1[[`0]] <>u__3
// 0x02000058 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<SearchCompounds>d__10
//   0x040002cf field: System.Int32 <>1__state
//   0x040002d0 field: System.Runtime.CompilerServices.AsyncTaskMethodBuilder`1[[System.Collections.Generic.List`1[[System.String]]]] <>t__builder
//   0x040002d1 field: System.String query
//   0x040002d2 field: System.Collections.Generic.List`1[[System.String]] <compounds>5__2
//   0x040002d3 field: System.String[] <>7__wrap2
//   0x040002d4 field: System.Int32 <>7__wrap3
//   0x040002d5 field: System.String <cid>5__5
//   0x040002d6 field: System.Runtime.CompilerServices.TaskAwaiter`1[[AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+CompoundModel]] <>u__1
//   0x040002d7 field: System.Runtime.CompilerServices.TaskAwaiter`1[[AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+QueryModel]] <>u__2
// 0x02000059 AspenTech.AspenPlus.WpfFindComponent.ReorderComp+<>c
//   0x040002d8 field: AspenTech.AspenPlus.WpfFindComponent.ReorderComp+<>c <>9
//   0x040002d9 field: System.Func`2[[<>f__AnonymousType0`2[[System.String],[System.Int32]]],[System.Int32]] <>9__26_1
//   0x040002da field: System.Func`2[[<>f__AnonymousType0`2[[System.String],[System.Int32]]],[System.ValueTuple`2[[System.String],[System.Int32]]]] <>9__26_2
//   0x040002db field: System.Func`2[[<>f__AnonymousType0`2[[System.String],[System.Int32]]],[System.Int32]] <>9__28_1
//   0x040002dc field: System.Func`2[[<>f__AnonymousType0`2[[System.String],[System.Int32]]],[System.ValueTuple`2[[System.String],[System.Int32]]]] <>9__28_2

// 0x06000001 <>f__AnonymousType0`2.get_x
// {
// 	return <x>i__Field;
// }

// 0x06000002 <>f__AnonymousType0`2.get_index
// {
// 	return <index>i__Field;
// }

// 0x06000003 <>f__AnonymousType0`2..ctor
// using System.Diagnostics;
//
// [DebuggerHidden]
// public <>f__AnonymousType0(<x>j__TPar x, <index>j__TPar index)
// {
// 	<x>i__Field = x;
// 	<index>i__Field = index;
// }

// 0x06000004 <>f__AnonymousType0`2.Equals
// using System.Collections.Generic;
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override bool Equals(object value)
// {
// 	global::<>f__AnonymousType0<<x>j__TPar, <index>j__TPar> anon = value as global::<>f__AnonymousType0<<x>j__TPar, <index>j__TPar>;
// 	if (this != anon)
// 	{
// 		if (anon != null && EqualityComparer<<x>j__TPar>.Default.Equals(<x>i__Field, anon.<x>i__Field))
// 		{
// 			return EqualityComparer<<index>j__TPar>.Default.Equals(<index>i__Field, anon.<index>i__Field);
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
// 	return (-1133558220 * -1521134295 + EqualityComparer<<x>j__TPar>.Default.GetHashCode(<x>i__Field)) * -1521134295 + EqualityComparer<<index>j__TPar>.Default.GetHashCode(<index>i__Field);
// }

// 0x06000006 <>f__AnonymousType0`2.ToString
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override string ToString()
// {
// 	object[] array = new object[2];
// 	<x>j__TPar val = <x>i__Field;
// 	array[0] = ((val != null) ? val.ToString() : null);
// 	<index>j__TPar val2 = <index>i__Field;
// 	array[1] = ((val2 != null) ? val2.ToString() : null);
// 	return string.Format(null, "{{ x = {0}, index = {1} }}", array);
// }

// 0x0600000c XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x0600000d AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel.add_PropertyChanged
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

// 0x0600000e AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel.remove_PropertyChanged
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

// 0x06000053 AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel..cctor
// using System.Collections.Generic;
//
// static CompoundsTabViewModel()
// {
// 	dbProvider = string.Empty;
// 	dbMessage = string.Empty;
// 	APNames = new List<string>
// 	{
// 		"AP065", "APV70", "APV71", "APV72", "APV73", "APV732", "APV80", "APV82", "APV84", "APV86",
// 		"APV88", "APV90", "APV100", "APV110", "APV120", "APV121", "APV140", "APV150"
// 	};
// 	APPUREDatabankNames = new List<string>
// 	{
// 		"PURE11", "PURE12", "PURE13", "PURE20", "PURE22", "PURE24", "PURE25", "PURE26", "PURE27", "PURE28",
// 		"PURE32", "PURE35", "PURE36", "PURE37", "PURE38", "PURE39", "PURE40", "PURE41"
// 	};
// }

// 0x06000057 AspenTech.AspenPlus.WpfFindComponent.SafeObservableCollection`1.add_CollectionChanged
// using System;
// using System.Collections.Specialized;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler = CollectionChanged;
// 	NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler2;
// 	do
// 	{
// 		notifyCollectionChangedEventHandler2 = notifyCollectionChangedEventHandler;
// 		NotifyCollectionChangedEventHandler value2 = (NotifyCollectionChangedEventHandler)Delegate.Combine(notifyCollectionChangedEventHandler2, value);
// 		notifyCollectionChangedEventHandler = Interlocked.CompareExchange(ref CollectionChanged, value2, notifyCollectionChangedEventHandler2);
// 	}
// 	while ((object)notifyCollectionChangedEventHandler != notifyCollectionChangedEventHandler2);
// }

// 0x06000058 AspenTech.AspenPlus.WpfFindComponent.SafeObservableCollection`1.remove_CollectionChanged
// using System;
// using System.Collections.Specialized;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler = CollectionChanged;
// 	NotifyCollectionChangedEventHandler notifyCollectionChangedEventHandler2;
// 	do
// 	{
// 		notifyCollectionChangedEventHandler2 = notifyCollectionChangedEventHandler;
// 		NotifyCollectionChangedEventHandler value2 = (NotifyCollectionChangedEventHandler)Delegate.Remove(notifyCollectionChangedEventHandler2, value);
// 		notifyCollectionChangedEventHandler = Interlocked.CompareExchange(ref CollectionChanged, value2, notifyCollectionChangedEventHandler2);
// 	}
// 	while ((object)notifyCollectionChangedEventHandler != notifyCollectionChangedEventHandler2);
// }

// 0x0600005a AspenTech.AspenPlus.WpfFindComponent.SafeObservableCollection`1..ctor
// public SafeObservableCollection()
// {
// }

// 0x06000069 AspenTech.AspenPlus.WpfFindComponent.NullableTextBox..ctor
// public NullableTextBox()
// {
// }

// 0x0600006c AspenTech.AspenPlus.WpfFindComponent.DoubleStringDisplayConverter..ctor
// public DoubleStringDisplayConverter()
// {
// }

// 0x0600006f AspenTech.AspenPlus.WpfFindComponent.TextBoxExTextConverter..ctor
// public TextBoxExTextConverter()
// {
// }

// 0x06000091 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel.add_PropertyChanged
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

// 0x06000092 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel.remove_PropertyChanged
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

// 0x06000094 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel..ctor
// using System.Collections.ObjectModel;
//
// public CreatePropertyViewModel()
// {
// 	_description = "";
// 	_propertyForSearch = "";
// 	_availableProps = new ObservableCollection<PropertySetItem>();
// 	_acceptedProps = new ObservableCollection<PropertySetItem>();
// 	base..ctor();
// }

// 0x0600009c AspenTech.AspenPlus.WpfFindComponent.PropertySetItem.add_PropertyChanged
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

// 0x0600009d AspenTech.AspenPlus.WpfFindComponent.PropertySetItem.remove_PropertyChanged
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

// 0x0600009f AspenTech.AspenPlus.WpfFindComponent.PropertySetItem..ctor
// public PropertySetItem()
// {
// }

// 0x060000b2 AspenTech.AspenPlus.WpfFindComponent.BiomassLookupViewModel..cctor
// static BiomassLookupViewModel()
// {
// 	dbProvider = string.Empty;
// 	dbMessage = string.Empty;
// 	DatabaseName = "APESV";
// }

// 0x060000bd AspenTech.AspenPlus.WpfFindComponent.Compound..ctor
// public Compound()
// {
// }

// 0x060000c2 AspenTech.AspenPlus.WpfFindComponent.HeaderDisplayConverter..ctor
// public HeaderDisplayConverter()
// {
// }

// 0x060000c4 AspenTech.AspenPlus.WpfFindComponent.DatabanksTabViewModel..ctor
// public DatabanksTabViewModel()
// {
// }

// 0x060000c5 AspenTech.AspenPlus.WpfFindComponent.DatabanksTabViewModel..cctor
// using AspenTech.AspenCxs.CxsViewModel;
//
// static DatabanksTabViewModel()
// {
// 	lstpPureDataBanks_filesymnam_Property = CxvPropertyDeclaration.Register("lstpPureDataBanks_filesymnam", typeof(DatabanksTabViewModel), new CxvVariableProperty
// 	{
// 		ExposeAs = CxvVariableTypeCode.List,
// 		DataPath = "Top.appModelV8.Pure Databanks.Input.FILE_SYM_NAM",
// 		SkipSemanticOnReorder = true,
// 		RestoreDefaultOnClear = true
// 	});
// }

// 0x060000f8 AspenTech.AspenPlus.WpfFindComponent.ElectrolyteForm12.add_PropertyChanged
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

// 0x060000f9 AspenTech.AspenPlus.WpfFindComponent.ElectrolyteForm12.remove_PropertyChanged
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

// 0x06000137 AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver..cctor
// static FindComponentDriver()
// {
// 	dbProvider = string.Empty;
// 	dbMessage = string.Empty;
// }

// 0x06000148 AspenTech.AspenPlus.WpfFindComponent.ListViewEx..ctor
// public ListViewEx()
// {
// }

// 0x06000149 AspenTech.AspenPlus.WpfFindComponent.ListViewEx..cctor
// using System.Collections;
// using System.Windows;
//
// static ListViewEx()
// {
// 	BindableSelectedItemsProperty = DependencyProperty.Register("BindableSelectedItems", typeof(IList), typeof(ListViewEx));
// }

// 0x0600014a AspenTech.AspenPlus.WpfFindComponent.FindPropertyViewModel.add_PropertyChanged
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

// 0x0600014b AspenTech.AspenPlus.WpfFindComponent.FindPropertyViewModel.remove_PropertyChanged
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

// 0x06000181 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel.add_PropertyChanged
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

// 0x06000182 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel.remove_PropertyChanged
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

// 0x06000184 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel..cctor
// using AspenTech.AspenPlus.Localization;
//
// static NewPureCompParamViewModel()
// {
// 	NUM_T_DEP_CLASSES = 35;
// 	csClassNames = new string[35]
// 	{
// 		WpfFindComponentResources.ClassName0,
// 		WpfFindComponentResources.ClassName1,
// 		WpfFindComponentResources.ClassName2,
// 		WpfFindComponentResources.ClassName3,
// 		WpfFindComponentResources.ClassName4,
// 		WpfFindComponentResources.ClassName5,
// 		WpfFindComponentResources.ClassName6,
// 		WpfFindComponentResources.ClassName7,
// 		WpfFindComponentResources.ClassName8,
// 		WpfFindComponentResources.ClassName9,
// 		WpfFindComponentResources.ClassName10,
// 		WpfFindComponentResources.ClassName11,
// 		WpfFindComponentResources.ClassName12,
// 		WpfFindComponentResources.ClassName13,
// 		WpfFindComponentResources.ClassName14,
// 		WpfFindComponentResources.ClassName15,
// 		WpfFindComponentResources.ClassName16,
// 		WpfFindComponentResources.ClassName17,
// 		WpfFindComponentResources.ClassName18,
// 		WpfFindComponentResources.ClassName19,
// 		WpfFindComponentResources.ClassName20,
// 		WpfFindComponentResources.ClassName21,
// 		WpfFindComponentResources.ClassName22,
// 		WpfFindComponentResources.ClassName23,
// 		WpfFindComponentResources.ClassName24,
// 		WpfFindComponentResources.ClassName25,
// 		WpfFindComponentResources.ClassName26,
// 		WpfFindComponentResources.ClassName27,
// 		WpfFindComponentResources.ClassName28,
// 		WpfFindComponentResources.ClassName29,
// 		WpfFindComponentResources.ClassName30,
// 		WpfFindComponentResources.ClassName31,
// 		WpfFindComponentResources.ClassName32,
// 		WpfFindComponentResources.ClassName33,
// 		WpfFindComponentResources.ClassName34
// 	};
// 	Alpha_function_for_equations_of_state = 0;
// 	Aqueous_heat_capacity = 1;
// 	Atom_count = 2;
// 	BWRS_parameters = 3;
// 	Dielectric_constant = 4;
// 	Flory_Huggins_size_parameter = 5;
// 	Heat_of_vaporization = 6;
// 	Helgeson_model_parameters = 7;
// 	HF_model_parameters = 8;
// 	Ideal_gas_heat_capacity = 9;
// 	Liquid_heat_capacity = 10;
// 	Liquid_molar_volume = 11;
// 	Liquid_thermal_conductivity = 12;
// 	Liquid_vapor_pressure = 13;
// 	Liquid_viscosity = 14;
// 	Liquid_viscosity_for_electrolytes = 15;
// 	Molecular_parameters = 16;
// 	Nothnagel_parameters = 17;
// 	Number_of_atoms_in_molecule = 18;
// 	Solid_heat_capacity = 19;
// 	Solid_molar_volume = 20;
// 	Solid_thermal_conductivity = 21;
// 	Solid_vapor_pressure = 22;
// 	Submodel_selection_option = 23;
// 	Surface_tension = 24;
// 	UNIFAC_group_count = 25;
// 	van_Krevelen_crystalline_heat_capacity = 26;
// 	van_Krevelen_density = 27;
// 	van_Krevelen_group_count = 28;
// 	van_Krevelen_thermal_conductivity = 29;
// 	Vapor_thermal_conductivity = 30;
// 	Vapor_viscosity = 31;
// 	Solubility = 32;
// 	NRTL_SAC_eNRTL_SAC = 33;
// 	COSMO_SAC = 34;
// 	ParamClassList = new ParamAndClass[167]
// 	{
// 		new ParamAndClass("AHGPAR-1", Helgeson_model_parameters),
// 		new ParamAndClass("ATOMNO-1", Atom_count),
// 		new ParamAndClass("BWRSA-1", BWRS_parameters),
// 		new ParamAndClass("CHGPAR-1", Helgeson_model_parameters),
// 		new ParamAndClass("CPAQ0-1", Aqueous_heat_capacity),
// 		new ParamAndClass("CPCVK-1", van_Krevelen_crystalline_heat_capacity),
// 		new ParamAndClass("CPCVKM-1", van_Krevelen_crystalline_heat_capacity),
// 		new ParamAndClass("CPDIEC-1", Dielectric_constant),
// 		new ParamAndClass("CPIAPI-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIG-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIGDP-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIGDS-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIGPO-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIGYM-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIALE-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPITML-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIWEO-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIXP1-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIXP2-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPIXP3-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("CPLBPS-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLDIP-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLPDS-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLIKC-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLPO-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLTDE-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLTML-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLVK-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLVKM-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLXP1-1", Liquid_heat_capacity),
// 		new ParamAndClass("CPLXP2-1", Liquid_heat_capacity),
// 		new ParamAndClass("BIOCP-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSDIP-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSPO-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSPO1-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSTML-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP1-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP2-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP3-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP4-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP5-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP6-1", Solid_heat_capacity),
// 		new ParamAndClass("CPSXP7-1", Solid_heat_capacity),
// 		new ParamAndClass("DHVLDP-1", Heat_of_vaporization),
// 		new ParamAndClass("DHVLDS-1", Heat_of_vaporization),
// 		new ParamAndClass("DHVLPO-1", Heat_of_vaporization),
// 		new ParamAndClass("DHVLTD-1", Heat_of_vaporization),
// 		new ParamAndClass("DHVLWT-1", Heat_of_vaporization),
// 		new ParamAndClass("DNCVK-1", van_Krevelen_density),
// 		new ParamAndClass("DNCVKM-1", van_Krevelen_density),
// 		new ParamAndClass("DNGVK-1", van_Krevelen_density),
// 		new ParamAndClass("DNGVKM-1", van_Krevelen_density),
// 		new ParamAndClass("DNLCOS-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLDIP-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLEXS-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLPDS-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLRAC-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLTML-1", Liquid_molar_volume),
// 		new ParamAndClass("RHOML-1", Liquid_molar_volume),
// 		new ParamAndClass("DNLVK-1", van_Krevelen_density),
// 		new ParamAndClass("DNLVKM-1", van_Krevelen_density),
// 		new ParamAndClass("DNSDIP-1", Solid_molar_volume),
// 		new ParamAndClass("DNSTML-1", Solid_molar_volume),
// 		new ParamAndClass("RHOMS-1", Solid_molar_volume),
// 		new ParamAndClass("ECPIG-1", Ideal_gas_heat_capacity),
// 		new ParamAndClass("ESHFK-1", HF_model_parameters),
// 		new ParamAndClass("FHSIZE-1", Flory_Huggins_size_parameter),
// 		new ParamAndClass("IONMOB-1", Liquid_viscosity_for_electrolytes),
// 		new ParamAndClass("IONMUB-1", Liquid_viscosity_for_electrolytes),
// 		new ParamAndClass("IONTHG-1", Helgeson_model_parameters),
// 		new ParamAndClass("KLDIP-1", Liquid_thermal_conductivity),
// 		new ParamAndClass("KLPDS-1", Liquid_thermal_conductivity),
// 		new ParamAndClass("KLPO-1", Liquid_thermal_conductivity),
// 		new ParamAndClass("KLPPDS-1", Liquid_thermal_conductivity),
// 		new ParamAndClass("KLTMLP-1", Liquid_thermal_conductivity),
// 		new ParamAndClass("KLVKC-1", van_Krevelen_thermal_conductivity),
// 		new ParamAndClass("KLVKG-1", van_Krevelen_thermal_conductivity),
// 		new ParamAndClass("KLVKL-1", van_Krevelen_thermal_conductivity),
// 		new ParamAndClass("KSPOLY-1", Solid_thermal_conductivity),
// 		new ParamAndClass("KVDIP-1", Vapor_thermal_conductivity),
// 		new ParamAndClass("KVPDS-1", Vapor_thermal_conductivity),
// 		new ParamAndClass("KVPO-1", Vapor_thermal_conductivity),
// 		new ParamAndClass("KVTMLP-1", Vapor_thermal_conductivity),
// 		new ParamAndClass("LJPAR-1", Molecular_parameters),
// 		new ParamAndClass("LNPR1-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LNPR2-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LNVP1-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LNVPEQ-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LOGPR1-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LOGPR2-1", Liquid_vapor_pressure),
// 		new ParamAndClass("LOGVP1-1", Liquid_vapor_pressure),
// 		new ParamAndClass("MULAND-1", Liquid_viscosity),
// 		new ParamAndClass("MULBPS-1", Liquid_viscosity),
// 		new ParamAndClass("MULDIP-1", Liquid_viscosity),
// 		new ParamAndClass("MULIKC-1", Liquid_viscosity),
// 		new ParamAndClass("MULMH-1", Liquid_viscosity),
// 		new ParamAndClass("MULMK-1", Liquid_viscosity),
// 		new ParamAndClass("MULNVE-1", Liquid_viscosity),
// 		new ParamAndClass("MULPDS-1", Liquid_viscosity),
// 		new ParamAndClass("MULPO-1", Liquid_viscosity),
// 		new ParamAndClass("MULPPD-1", Liquid_viscosity),
// 		new ParamAndClass("MULVK-1", Liquid_viscosity),
// 		new ParamAndClass("MUVCEB-1", Vapor_viscosity),
// 		new ParamAndClass("MUVDIP-1", Vapor_viscosity),
// 		new ParamAndClass("MUVPDS-1", Vapor_viscosity),
// 		new ParamAndClass("MUVPO-1", Vapor_viscosity),
// 		new ParamAndClass("MUVSUT-1", Vapor_viscosity),
// 		new ParamAndClass("MUVTML-1", Vapor_viscosity),
// 		new ParamAndClass("NATOM-1", Number_of_atoms_in_molecule),
// 		new ParamAndClass("NOATOM-1", Atom_count),
// 		new ParamAndClass("NTHA-1", Nothnagel_parameters),
// 		new ParamAndClass("NTHK-1", Nothnagel_parameters),
// 		new ParamAndClass("PDSNEL-1", Vapor_thermal_conductivity),
// 		new ParamAndClass("PLPO-1", Liquid_vapor_pressure),
// 		new ParamAndClass("PLTDEP-1", Liquid_vapor_pressure),
// 		new ParamAndClass("PLXANT-1", Liquid_vapor_pressure),
// 		new ParamAndClass("PRGLP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("PRMCP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("PRSRP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("PRTWUP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("PSANT-1", Solid_vapor_pressure),
// 		new ParamAndClass("PSXANT-1", Solid_vapor_pressure),
// 		new ParamAndClass("PSTDEP-1", Solid_vapor_pressure),
// 		new ParamAndClass("PSTMLP-1", Solid_vapor_pressure),
// 		new ParamAndClass("RACKET-1", Liquid_molar_volume),
// 		new ParamAndClass("RKSMCP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("RKSSRP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("SIGDIP-1", Surface_tension),
// 		new ParamAndClass("SIGIST-1", Surface_tension),
// 		new ParamAndClass("SIGP14-1", Surface_tension),
// 		new ParamAndClass("SIGPDS-1", Surface_tension),
// 		new ParamAndClass("SIGPO-1", Surface_tension),
// 		new ParamAndClass("SIGTDE-1", Surface_tension),
// 		new ParamAndClass("SRKGLP-1", Alpha_function_for_equations_of_state),
// 		new ParamAndClass("STKPAR-1", Molecular_parameters),
// 		new ParamAndClass("THRSWT-1", Submodel_selection_option),
// 		new ParamAndClass("TRNSWT-1", Submodel_selection_option),
// 		new ParamAndClass("UFGRP-1", UNIFAC_group_count),
// 		new ParamAndClass("UFGRP-2", UNIFAC_group_count),
// 		new ParamAndClass("UFGRPD-1", UNIFAC_group_count),
// 		new ParamAndClass("UFGRPL-1", UNIFAC_group_count),
// 		new ParamAndClass("VKGRP-1", van_Krevelen_group_count),
// 		new ParamAndClass("VLBROC-1", Liquid_molar_volume),
// 		new ParamAndClass("VLPO-1", Liquid_molar_volume),
// 		new ParamAndClass("VLTAIT-1", Liquid_molar_volume),
// 		new ParamAndClass("VSPO-1", Solid_molar_volume),
// 		new ParamAndClass("VSPOLY-1", Solid_molar_volume),
// 		new ParamAndClass("WAGNER-1", Liquid_vapor_pressure),
// 		new ParamAndClass("WAGN25-1", Liquid_vapor_pressure),
// 		new ParamAndClass("WATSOL-1", Solubility),
// 		new ParamAndClass("HCSOL-1", Solubility),
// 		new ParamAndClass("XYZE-1", NRTL_SAC_eNRTL_SAC),
// 		new ParamAndClass("SGPRF1-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF2-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF3-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF4-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF5-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF6-1", COSMO_SAC),
// 		new ParamAndClass("SGPRF7-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE1-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE2-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE3-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE4-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE5-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE6-1", COSMO_SAC),
// 		new ParamAndClass("SGPRE7-1", COSMO_SAC),
// 		new ParamAndClass("MRKZRA-1", Liquid_molar_volume)
// 	};
// }

// 0x0600018f AspenTech.AspenPlus.WpfFindComponent.TreeViewEx..ctor
// public TreeViewEx()
// {
// }

// 0x06000190 AspenTech.AspenPlus.WpfFindComponent.TreeViewEx..cctor
// using System.Windows;
//
// static TreeViewEx()
// {
// 	BindableSelectedItemProperty = DependencyProperty.Register("BindableSelectedItem", typeof(object), typeof(TreeViewEx));
// }

// 0x060001aa AspenTech.AspenPlus.WpfFindComponent.PagingControl..cctor
// using System.Windows;
//
// static PagingControl()
// {
// 	LoadCompleteProperty = DependencyProperty.Register("LoadComplete", typeof(bool), typeof(PagingControl), new PropertyMetadata(true));
// 	MaxAllowedPageProperty = DependencyProperty.Register("MaxAllowedPage", typeof(int), typeof(PagingControl), new PropertyMetadata(1, OnMaxAllowedPageChanged));
// 	SelectedPageProperty = DependencyProperty.Register("SelectedPage", typeof(int?), typeof(PagingControl), new PropertyMetadata(1, OnSelectedPageChanged));
// }

// 0x060001b0 AspenTech.AspenPlus.WpfFindComponent.PageItem..ctor
// public PageItem()
// {
// }

// 0x060001b1 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel.add_PropertyChanged
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

// 0x060001b2 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel.remove_PropertyChanged
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

// 0x060001d1 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel..ctor
// using System.Collections.Concurrent;
// using System.Collections.Generic;
// using System.Collections.ObjectModel;
//
// public PubChemTabViewModel()
// {
// 	_allCompounds = new ConcurrentDictionary<int, List<PubChemCompound>>();
// 	compounds = new ObservableCollection<PubChemCompound>();
// 	maxAllowedPage = 1;
// 	searchComplete = true;
// 	loadComplete = true;
// 	<PageSize>k__BackingField = 5;
// 	statusText = string.Empty;
// 	base..ctor();
// }

// 0x060001d2 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel..cctor
// using System.Threading;
//
// static PubChemTabViewModel()
// {
// 	cts = new CancellationTokenSource();
// }

// 0x060001ed AspenTech.AspenPlus.WpfFindComponent.PubChemCompound..ctor
// public PubChemCompound()
// {
// }

// 0x060001fa AspenTech.AspenPlus.WpfFindComponent.PubChemAgent..ctor
// public PubChemAgent()
// {
// }

// 0x06000233 AspenTech.AspenPlus.WpfFindComponent.SFEAssistantViewModel.add_PropertyChanged
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

// 0x06000234 AspenTech.AspenPlus.WpfFindComponent.SFEAssistantViewModel.remove_PropertyChanged
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

// 0x06000248 AspenTech.AspenPlus.WpfFindComponent.SFEComponentData..ctor
// public SFEComponentData()
// {
// }

// 0x0600026c AspenTech.AspenPlus.WpfFindComponent.SFEAssistantStep2.add_PropertyChanged
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

// 0x0600026d AspenTech.AspenPlus.WpfFindComponent.SFEAssistantStep2.remove_PropertyChanged
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

// 0x06000279 AspenTech.AspenPlus.WpfFindComponent.SFEAssistantStep2..cctor
// using System.Collections.ObjectModel;
//
// static SFEAssistantStep2()
// {
// 	dbankmsgs = 0;
// 	g_arraySelectedComponent = new ObservableCollection<SFEComponentData>();
// }

// 0x0600027a AspenTech.AspenPlus.WpfFindComponent.TextBoxEx..ctor
// public TextBoxEx()
// {
// }

// 0x06000294 AspenTech.AspenPlus.WpfFindComponent.RadioButtonHeaderGroupBox..ctor
// public RadioButtonHeaderGroupBox()
// {
// }

// 0x060002bd AspenTech.AspenPlus.WpfFindComponent.ComponentData..ctor
// public ComponentData()
// {
// }

// 0x0600031a AspenTech.AspenPlus.WpfFindComponent.UserDefinedCompWizardMain..cctor
// using System.Collections.Generic;
//
// static UserDefinedCompWizardMain()
// {
// 	g_existingCompList = new List<string>();
// 	g_CompIdText = "";
// 	g_CompType = "Conventional";
// 	g_CompFormula = "";
// 	g_EditCompNbp = "";
// 	g_EditCompMw = "";
// 	g_EditSpecificGravity = "";
// 	g_EditEnthalpy = "";
// 	g_EditFreenergy = "";
// 	g_FormTitle = "";
// 	g_Curstr = "";
// 	g_Curset = 0;
// 	g_loadformflag = 0;
// 	g_molecularformflag = 0;
// 	g_ieditcompnbp = -1;
// 	g_ieditenthalpy = -1;
// 	g_ieditfreenergy = -1;
// 	g_storecompflag = 0;
// 	g_iHasMolStru = 0;
// 	g_iHasLrho = 0;
// 	g_iHasVp = 0;
// 	g_iHasVpC = 0;
// 	g_iHasHc = 0;
// 	g_iHasHcC = 0;
// 	g_m_IsTDEButton = 0;
// 	EDITNBP_UNIT_K_LOW = 0.0;
// 	EDITNBP_UNIT_K_HIGH = 100000.0;
// 	EDITNBP_UNIT_F_LOW = -459.67;
// 	EDITNBP_UNIT_F_HIGH = 179540.0;
// 	EDITNBP_UNIT_C_LOW = -273.15;
// 	EDITNBP_UNIT_C_HIGH = 99726.9;
// 	EDITNBP_UNIT_R_LOW = 0.0;
// 	EDITNBP_UNIT_R_HIGH = 180000.0;
// 	EDITMW_UNIT_LOW = 0.0;
// 	EDITMW_UNIT_HIGH = 1E+35;
// 	EDITSG_UNIT_LOW = 0.0;
// 	EDITSG_UNIT_HIGH = 3.0;
// 	EDITDHF_UNIT_LOW = -1E+35;
// 	EDITDHF_UNIT_HIGH = 1E+35;
// 	EDITDGF_UNIT_LOW = -1E+35;
// 	EDITDGF_UNIT_HIGH = 1E+35;
// }

// 0x0600031b AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031c AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000320 AspenTech.AspenPlus.WpfFindComponent.CompoundsTabViewModel+<>c__DisplayClass8_0..ctor
// public <>c__DisplayClass8_0()
// {
// }

// 0x06000322 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000323 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000328 AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass33_0..ctor
// public <>c__DisplayClass33_0()
// {
// }

// 0x0600032a AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass38_0..ctor
// public <>c__DisplayClass38_0()
// {
// }

// 0x0600032c AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass38_1..ctor
// public <>c__DisplayClass38_1()
// {
// }

// 0x0600032e AspenTech.AspenPlus.WpfFindComponent.CreatePropertyViewModel+<>c__DisplayClass43_0..ctor
// public <>c__DisplayClass43_0()
// {
// }

// 0x06000330 AspenTech.AspenPlus.WpfFindComponent.BiomassLookupViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000331 AspenTech.AspenPlus.WpfFindComponent.BiomassLookupViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000342 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000343 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c..ctor
// public <>c()
// {
// }

// 0x06000345 AspenTech.AspenPlus.WpfFindComponent.NewPureCompParamViewModel+<>c__DisplayClass76_0..ctor
// public <>c__DisplayClass76_0()
// {
// }

// 0x06000347 AspenTech.AspenPlus.WpfFindComponent.PagingControl+<>c__DisplayClass19_0..ctor
// public <>c__DisplayClass19_0()
// {
// }

// 0x06000349 AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecuteNextPageCommand>d__29.MoveNext
// using System;
// using System.Linq;
//
// private void MoveNext()
// {
// 	PagingControl pagingControl = <>4__this;
// 	try
// 	{
// 		try
// 		{
// 			pagingControl.LoadComplete = false;
// 			PageItem pageItem = pagingControl.PageItems.LastOrDefault();
// 			if (pageItem != null && pageItem.Id == pagingControl.SelectedPage)
// 			{
// 				pagingControl._maxPage++;
// 			}
// 			pagingControl.SelectedPage++;
// 			pagingControl.LoadComplete = true;
// 		}
// 		catch (Exception)
// 		{
// 			pagingControl.LoadComplete = true;
// 		}
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x0600034a AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecuteNextPageCommand>d__29.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x0600034b AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecutePrePageCommand>d__24.MoveNext
// using System;
//
// private void MoveNext()
// {
// 	PagingControl pagingControl = <>4__this;
// 	try
// 	{
// 		try
// 		{
// 			pagingControl.SelectedPage--;
// 		}
// 		catch (Exception)
// 		{
// 		}
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x0600034c AspenTech.AspenPlus.WpfFindComponent.PagingControl+<ExecutePrePageCommand>d__24.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x0600034d AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteAddCommand>d__59.MoveNext
// using System;
//
// private void MoveNext()
// {
// 	PubChemTabViewModel pubChemTabViewModel = <>4__this;
// 	try
// 	{
// 		try
// 		{
// 			pubChemTabViewModel.ProxyHelper.ImportCompounds(pubChemTabViewModel.SelectedComponents);
// 			pubChemTabViewModel.AddedSuccessfully = true;
// 		}
// 		catch (Exception)
// 		{
// 		}
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x0600034e AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteAddCommand>d__59.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x0600034f AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteSearchCommand>d__54.MoveNext
// using System;
// using System.Collections.Generic;
// using System.Runtime.CompilerServices;
// using AspenTech.AspenPlus.Localization;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	PubChemTabViewModel pubChemTabViewModel = <>4__this;
// 	try
// 	{
// 		try
// 		{
// 			TaskAwaiter<List<string>> awaiter;
// 			if (num != 0)
// 			{
// 				pubChemTabViewModel.SearchComplete = false;
// 				pubChemTabViewModel.Compounds.Clear();
// 				pubChemTabViewModel.MaxAllowedPage = 1;
// 				pubChemTabViewModel._allCompounds.Clear();
// 				pubChemTabViewModel.StatusText = WpfFindComponentResources.Loading;
// 				awaiter = PubChemAgent.SearchCompounds(pubChemTabViewModel.SearchText).GetAwaiter();
// 				if (!awaiter.IsCompleted)
// 				{
// 					num = (<>1__state = 0);
// 					<>u__1 = awaiter;
// 					<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 					return;
// 				}
// 			}
// 			else
// 			{
// 				awaiter = <>u__1;
// 				<>u__1 = default(TaskAwaiter<List<string>>);
// 				num = (<>1__state = -1);
// 			}
// 			List<string> result = awaiter.GetResult();
// 			pubChemTabViewModel._allCompoundNames = result;
// 			pubChemTabViewModel._allValidCompounds = new HashSet<PubChemCompound>();
// 			if (pubChemTabViewModel._allCompoundNames == null || pubChemTabViewModel._allCompoundNames.Count == 0)
// 			{
// 				pubChemTabViewModel.StatusText = WpfFindComponentResources.NoMatch;
// 			}
// 			else
// 			{
// 				pubChemTabViewModel.StatusText = string.Format(WpfFindComponentResources.PubChemMatchesFound, pubChemTabViewModel._allCompoundNames.Count);
// 			}
// 			pubChemTabViewModel.SelectedPage = 1;
// 			pubChemTabViewModel.SearchComplete = true;
// 		}
// 		catch (Exception)
// 		{
// 			pubChemTabViewModel.SearchComplete = true;
// 		}
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x06000350 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<ExecuteSearchCommand>d__54.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x06000351 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<GotoPage>d__30.MoveNext
// using System;
// using System.Collections.Generic;
// using System.Linq;
// using System.Runtime.CompilerServices;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	PubChemTabViewModel pubChemTabViewModel = <>4__this;
// 	try
// 	{
// 		if (num == 0 || pubChemTabViewModel._allCompoundNames != null)
// 		{
// 			try
// 			{
// 				if (num != 0)
// 				{
// 					pubChemTabViewModel.LoadComplete = false;
// 					pubChemTabViewModel.Compounds.Clear();
// 					if (pubChemTabViewModel._allCompounds.ContainsKey(pageId))
// 					{
// 						List<PubChemCompound>.Enumerator enumerator = pubChemTabViewModel._allCompounds[pageId].GetEnumerator();
// 						try
// 						{
// 							while (enumerator.MoveNext())
// 							{
// 								PubChemCompound current = enumerator.Current;
// 								pubChemTabViewModel.Compounds.Add(current);
// 							}
// 						}
// 						finally
// 						{
// 							if (num < 0)
// 							{
// 								((IDisposable)enumerator/*cast due to .constrained prefix*//*cast due to .constrained prefix*/).Dispose();
// 							}
// 						}
// 						goto IL_0200;
// 					}
// 					<index>5__2 = 0;
// 					if (pageId > 1)
// 					{
// 						<index>5__2 = pubChemTabViewModel._allCompounds[pageId - 1].ElementAt(pubChemTabViewModel.PageSize - 1).Index + 1;
// 					}
// 					goto IL_0199;
// 				}
// 				TaskAwaiter<PubChemCompound> awaiter = <>u__1;
// 				<>u__1 = default(TaskAwaiter<PubChemCompound>);
// 				num = (<>1__state = -1);
// 				goto IL_0143;
// 				IL_0199:
// 				if (pubChemTabViewModel.Compounds.Count < pubChemTabViewModel.PageSize && <index>5__2 < pubChemTabViewModel._allCompoundNames.Count)
// 				{
// 					awaiter = PubChemAgent.GetCompoundDataAsync(pubChemTabViewModel._allCompoundNames.ElementAt(<index>5__2)).GetAwaiter();
// 					if (!awaiter.IsCompleted)
// 					{
// 						num = (<>1__state = 0);
// 						<>u__1 = awaiter;
// 						<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 						return;
// 					}
// 					goto IL_0143;
// 				}
// 				if (<index>5__2 < pubChemTabViewModel._allCompoundNames.Count)
// 				{
// 					pubChemTabViewModel.MaxAllowedPage++;
// 				}
// 				pubChemTabViewModel._allCompounds.TryAdd(pageId, pubChemTabViewModel.Compounds.ToList());
// 				goto IL_0200;
// 				IL_0143:
// 				PubChemCompound result = awaiter.GetResult();
// 				if (result != null && !pubChemTabViewModel._allValidCompounds.Contains(result))
// 				{
// 					result.Index = <index>5__2;
// 					pubChemTabViewModel.Compounds.Add(result);
// 					pubChemTabViewModel._allValidCompounds.Add(result);
// 				}
// 				<index>5__2++;
// 				goto IL_0199;
// 				IL_0200:
// 				pubChemTabViewModel.LoadComplete = true;
// 			}
// 			catch (Exception)
// 			{
// 				pubChemTabViewModel.LoadComplete = true;
// 			}
// 		}
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<>t__builder.SetResult();
// }

// 0x06000352 AspenTech.AspenPlus.WpfFindComponent.PubChemTabViewModel+<GotoPage>d__30.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x06000355 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+Status..ctor
// public Status()
// {
// }

// 0x06000358 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+DictionaryTerms..ctor
// public DictionaryTerms()
// {
// }

// 0x0600035f AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+QueryModel..ctor
// public QueryModel()
// {
// }

// 0x06000362 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+PropertyTable..ctor
// public PropertyTable()
// {
// }

// 0x06000375 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+PropertyValues..ctor
// public PropertyValues()
// {
// }

// 0x06000378 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+CompoundModel..ctor
// public CompoundModel()
// {
// }

// 0x06000379 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600037a AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<>c..ctor
// public <>c()
// {
// }

// 0x0600037c AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<GetCompoundDataAsync>d__11.MoveNext
// using System;
// using System.IO;
// using System.Linq;
// using System.Runtime.CompilerServices;
// using System.Windows.Media.Imaging;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	PubChemCompound result4;
// 	try
// 	{
// 		TaskAwaiter<byte[]> awaiter;
// 		TaskAwaiter<CompoundModel> awaiter2;
// 		if (num != 0)
// 		{
// 			if (num == 1)
// 			{
// 				awaiter = <>u__2;
// 				<>u__2 = default(TaskAwaiter<byte[]>);
// 				num = (<>1__state = -1);
// 				goto IL_0231;
// 			}
// 			if (string.IsNullOrWhiteSpace(nameOrCid))
// 			{
// 				throw new ArgumentNullException("nameOrCid");
// 			}
// 			<compound>5__2 = null;
// 			long result;
// 			string url = (long.TryParse(nameOrCid, out result) ? ($"rest/pug/compound/cid/{result}/property/" + "MolecularFormula,MolecularWeight,IUPACName,CanonicalSMILES,IsomericSMILES,InChI,InChIKey,Title/JSON") : ("rest/pug/compound/name/" + nameOrCid + "/property/MolecularFormula,MolecularWeight,IUPACName,CanonicalSMILES,IsomericSMILES,InChI,InChIKey,Title/JSON"));
// 			awaiter2 = ReadContentAsAsync<CompoundModel>(url).GetAwaiter();
// 			if (!awaiter2.IsCompleted)
// 			{
// 				num = (<>1__state = 0);
// 				<>u__1 = awaiter2;
// 				<>t__builder.AwaitUnsafeOnCompleted(ref awaiter2, ref this);
// 				return;
// 			}
// 		}
// 		else
// 		{
// 			awaiter2 = <>u__1;
// 			<>u__1 = default(TaskAwaiter<CompoundModel>);
// 			num = (<>1__state = -1);
// 		}
// 		CompoundModel result2 = awaiter2.GetResult();
// 		if (result2 != null && result2.PropertyTable.Properties.Count > 0)
// 		{
// 			PropertyValues propertyValues = result2.PropertyTable.Properties.FirstOrDefault();
// 			<compound>5__2 = new PubChemCompound
// 			{
// 				CID = propertyValues.CID,
// 				Name = nameOrCid,
// 				MolecularFormula = propertyValues.MolecularFormula,
// 				MolecularWeight = propertyValues.MolecularWeight,
// 				IUPACName = propertyValues.IUPACName,
// 				CanonicalSMILES = propertyValues.CanonicalSMILES,
// 				IsomericSMILES = propertyValues.IsomericSMILES,
// 				InChI = propertyValues.InChI,
// 				InChIKey = propertyValues.InChIKey,
// 				Title = propertyValues.Title
// 			};
// 		}
// 		if (<compound>5__2 != null)
// 		{
// 			if (<compound>5__2.CID == 6209)
// 			{
// 				<compound>5__2.IsomericSMILES = "CN(CCO)(Cl)(C)C";
// 			}
// 			string url = $"rest/pug/compound/cid/{<compound>5__2.CID}/PNG";
// 			awaiter = ReadContentAsAsync<byte[]>(url).GetAwaiter();
// 			if (!awaiter.IsCompleted)
// 			{
// 				num = (<>1__state = 1);
// 				<>u__2 = awaiter;
// 				<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 				return;
// 			}
// 			goto IL_0231;
// 		}
// 		goto IL_0295;
// 		IL_0231:
// 		byte[] result3 = awaiter.GetResult();
// 		BitmapImage bitmapImage = new BitmapImage();
// 		MemoryStream memoryStream = new MemoryStream(result3);
// 		try
// 		{
// 			memoryStream.Position = 0L;
// 			bitmapImage.BeginInit();
// 			bitmapImage.CreateOptions = BitmapCreateOptions.PreservePixelFormat;
// 			bitmapImage.CacheOption = BitmapCacheOption.OnLoad;
// 			bitmapImage.StreamSource = memoryStream;
// 			bitmapImage.EndInit();
// 		}
// 		finally
// 		{
// 			if (num < 0)
// 			{
// 				((IDisposable)memoryStream)?.Dispose();
// 			}
// 		}
// 		<compound>5__2.Image = bitmapImage;
// 		goto IL_0295;
// 		IL_0295:
// 		result4 = <compound>5__2;
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<compound>5__2 = null;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<compound>5__2 = null;
// 	<>t__builder.SetResult(result4);
// }

// 0x0600037d AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<GetCompoundDataAsync>d__11.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x0600037e AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<ReadContentAsAsync>d__9`1.MoveNext
// using System;
// using System.Net;
// using System.Net.Http;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	T result4;
// 	try
// 	{
// 		if (num != 0)
// 		{
// 			if ((uint)(num - 1) <= 1u)
// 			{
// 				goto IL_00a0;
// 			}
// 			<attempts>5__2 = 0;
// 			<max_attempts>5__3 = 3;
// 			<result>5__4 = null;
// 			goto IL_021b;
// 		}
// 		TaskAwaiter<HttpResponseMessage> awaiter = <>u__1;
// 		<>u__1 = default(TaskAwaiter<HttpResponseMessage>);
// 		num = (<>1__state = -1);
// 		goto IL_0090;
// 		IL_00a0:
// 		try
// 		{
// 			TaskAwaiter<byte[]> awaiter2;
// 			if (num == 1)
// 			{
// 				awaiter2 = <>u__2;
// 				<>u__2 = default(TaskAwaiter<byte[]>);
// 				num = (<>1__state = -1);
// 				goto IL_0137;
// 			}
// 			TaskAwaiter<T> awaiter3;
// 			if (num == 2)
// 			{
// 				awaiter3 = <>u__3;
// 				<>u__3 = default(TaskAwaiter<T>);
// 				num = (<>1__state = -1);
// 				goto IL_01b5;
// 			}
// 			if (<response>5__5.IsSuccessStatusCode)
// 			{
// 				if (typeof(T) == typeof(byte[]))
// 				{
// 					awaiter2 = <response>5__5.Content.ReadAsByteArrayAsync().GetAwaiter();
// 					if (!awaiter2.IsCompleted)
// 					{
// 						num = (<>1__state = 1);
// 						<>u__2 = awaiter2;
// 						<>t__builder.AwaitUnsafeOnCompleted(ref awaiter2, ref this);
// 						return;
// 					}
// 					goto IL_0137;
// 				}
// 				awaiter3 = <response>5__5.Content.ReadAsAsync<T>().GetAwaiter();
// 				if (!awaiter3.IsCompleted)
// 				{
// 					num = (<>1__state = 2);
// 					<>u__3 = awaiter3;
// 					<>t__builder.AwaitUnsafeOnCompleted(ref awaiter3, ref this);
// 					return;
// 				}
// 				goto IL_01b5;
// 			}
// 			if (HttpStatusCode.ServiceUnavailable == <response>5__5.StatusCode)
// 			{
// 				int num2 = <attempts>5__2 + 1;
// 				<attempts>5__2 = num2;
// 				Thread.Sleep(250);
// 				goto IL_0214;
// 			}
// 			goto end_IL_00a0;
// 			IL_0137:
// 			byte[] result = awaiter2.GetResult();
// 			<result>5__4 = result as T;
// 			goto end_IL_00a0;
// 			IL_01b5:
// 			T result2 = awaiter3.GetResult();
// 			<result>5__4 = result2;
// 			end_IL_00a0:;
// 		}
// 		finally
// 		{
// 			if (num < 0 && <response>5__5 != null)
// 			{
// 				((IDisposable)<response>5__5).Dispose();
// 			}
// 		}
// 		goto IL_022c;
// 		IL_0090:
// 		HttpResponseMessage result3 = awaiter.GetResult();
// 		<response>5__5 = result3;
// 		goto IL_00a0;
// 		IL_0214:
// 		<response>5__5 = null;
// 		goto IL_021b;
// 		IL_021b:
// 		if (<attempts>5__2 < <max_attempts>5__3)
// 		{
// 			awaiter = ApiClient.GetAsync(url).GetAwaiter();
// 			if (!awaiter.IsCompleted)
// 			{
// 				num = (<>1__state = 0);
// 				<>u__1 = awaiter;
// 				<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 				return;
// 			}
// 			goto IL_0090;
// 		}
// 		goto IL_022c;
// 		IL_022c:
// 		result4 = <result>5__4;
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<result>5__4 = null;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<result>5__4 = null;
// 	<>t__builder.SetResult(result4);
// }

// 0x0600037f AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<ReadContentAsAsync>d__9`1.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x06000380 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<SearchCompounds>d__10.MoveNext
// using System;
// using System.Collections.Generic;
// using System.Linq;
// using System.Runtime.CompilerServices;
//
// private void MoveNext()
// {
// 	int num = <>1__state;
// 	List<string> result2;
// 	try
// 	{
// 		TaskAwaiter<QueryModel> awaiter;
// 		if (num != 0)
// 		{
// 			if (num != 1)
// 			{
// 				if (string.IsNullOrEmpty(query))
// 				{
// 					throw new ArgumentNullException("query");
// 				}
// 				<compounds>5__2 = new List<string>();
// 				if (query.Any(<>c.<>9__10_0 ?? (<>c.<>9__10_0 = <>c.<>9.<SearchCompounds>b__10_0)))
// 				{
// 					string[] array = query.Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
// 					<>7__wrap2 = array;
// 					<>7__wrap3 = 0;
// 					goto IL_0180;
// 				}
// 				goto IL_019a;
// 			}
// 			awaiter = <>u__2;
// 			<>u__2 = default(TaskAwaiter<QueryModel>);
// 			num = (<>1__state = -1);
// 			goto IL_022a;
// 		}
// 		TaskAwaiter<CompoundModel> awaiter2 = <>u__1;
// 		<>u__1 = default(TaskAwaiter<CompoundModel>);
// 		num = (<>1__state = -1);
// 		goto IL_0127;
// 		IL_0127:
// 		CompoundModel result = awaiter2.GetResult();
// 		if (result != null && result.PropertyTable.Properties.Count == 1)
// 		{
// 			result.PropertyTable.Properties.FirstOrDefault();
// 			<compounds>5__2.Add(<cid>5__5);
// 		}
// 		<cid>5__5 = null;
// 		goto IL_0172;
// 		IL_0172:
// 		<>7__wrap3++;
// 		goto IL_0180;
// 		IL_0180:
// 		if (<>7__wrap3 < <>7__wrap2.Length)
// 		{
// 			<cid>5__5 = <>7__wrap2[<>7__wrap3];
// 			if (!<compounds>5__2.Contains(<cid>5__5))
// 			{
// 				awaiter2 = ReadContentAsAsync<CompoundModel>("rest/pug/compound/cid/" + <cid>5__5 + "/property/Title/JSON").GetAwaiter();
// 				if (!awaiter2.IsCompleted)
// 				{
// 					num = (<>1__state = 0);
// 					<>u__1 = awaiter2;
// 					<>t__builder.AwaitUnsafeOnCompleted(ref awaiter2, ref this);
// 					return;
// 				}
// 				goto IL_0127;
// 			}
// 			goto IL_0172;
// 		}
// 		<>7__wrap2 = null;
// 		goto IL_019a;
// 		IL_022a:
// 		List<string> list = awaiter.GetResult().Dictionary_Terms?.Compound;
// 		if (list != null)
// 		{
// 			<compounds>5__2 = <compounds>5__2.Concat(list).ToList();
// 		}
// 		result2 = <compounds>5__2;
// 		goto end_IL_0007;
// 		IL_019a:
// 		int num2 = 1000;
// 		num2 = ((<compounds>5__2.Count != 0) ? (num2 - <compounds>5__2.Count) : num2);
// 		awaiter = ReadContentAsAsync<QueryModel>($"rest/autocomplete/compound/{query}/json?limit={num2}").GetAwaiter();
// 		if (!awaiter.IsCompleted)
// 		{
// 			num = (<>1__state = 1);
// 			<>u__2 = awaiter;
// 			<>t__builder.AwaitUnsafeOnCompleted(ref awaiter, ref this);
// 			return;
// 		}
// 		goto IL_022a;
// 		end_IL_0007:;
// 	}
// 	catch (Exception exception)
// 	{
// 		<>1__state = -2;
// 		<compounds>5__2 = null;
// 		<>t__builder.SetException(exception);
// 		return;
// 	}
// 	<>1__state = -2;
// 	<compounds>5__2 = null;
// 	<>t__builder.SetResult(result2);
// }

// 0x06000381 AspenTech.AspenPlus.WpfFindComponent.PubChemAgent+<SearchCompounds>d__10.SetStateMachine
// using System.Diagnostics;
// using System.Runtime.CompilerServices;
//
// [DebuggerHidden]
// private void SetStateMachine(IAsyncStateMachine stateMachine)
// {
// 	<>t__builder.SetStateMachine(stateMachine);
// }

// 0x06000382 AspenTech.AspenPlus.WpfFindComponent.ReorderComp+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000383 AspenTech.AspenPlus.WpfFindComponent.ReorderComp+<>c..ctor
// public <>c()
// {
// }
