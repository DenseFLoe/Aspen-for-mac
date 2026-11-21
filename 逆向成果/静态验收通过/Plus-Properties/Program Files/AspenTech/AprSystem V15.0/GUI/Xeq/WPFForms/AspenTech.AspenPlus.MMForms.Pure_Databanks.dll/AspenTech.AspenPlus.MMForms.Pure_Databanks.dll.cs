using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Input;
using System.Windows.Markup;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.MMControls;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.Pure Databanks")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.Pure Databanks")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2010 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/aspenplus/forms/pure_databanks", "AspenTech.AspenPlus.MMForms.Pure_Databanks")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenTech.AspenPlus.MMForms.Pure_Databanks;

public class MMPureDataBank_Input_ViewModel : MMTabPageViewModel
{
	private ICommand _cmdClose_Command;

	public static readonly CxvPropertyDeclaration lstpPureDataBanks_filesymnam_Property = CxvPropertyDeclaration.Register("lstpPureDataBanks_filesymnam", typeof(MMPureDataBank_Input_ViewModel), new CxvVariableProperty
	{
		ExposeAs = CxvVariableTypeCode.List,
		DataPath = "@main.Input.FILE_SYM_NAM",
		RestoreDefaultOnClear = true
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

	public object lstpPureDataBanks_filesymnam => GetValue(lstpPureDataBanks_filesymnam_Property);

	private void cmdClose_CommandExecute(object parameter)
	{
		CloseForm();
	}
}
[ProgId("MMPureDataBank.MMPureDataBank_Input")]
public class MMPureDataBank_Input : MMTabPage, IComponentConnector
{
	internal MMListPicker lstpPureDataBanks;

	internal MMCmdButton cmdClose;

	private bool _contentLoaded;

	public MMPureDataBank_Input()
	{
		base.ViewModelType = typeof(MMPureDataBank_Input_ViewModel);
		InitializeComponent();
	}

	[DebuggerNonUserCode]
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public void InitializeComponent()
	{
		if (!_contentLoaded)
		{
			_contentLoaded = true;
			Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.Pure_Databanks;component/mmpuredatabank_input.xaml", UriKind.Relative);
			Application.LoadComponent(this, resourceLocator);
		}
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
			cmdClose = (MMCmdButton)target;
			break;
		default:
			_contentLoaded = true;
			break;
		}
	}
}
