using System;
using System.CodeDom.Compiler;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Resources;
using System.Windows.Threading;
using AspenTech.Visualisation.Controls.Assistant;
using Microsoft.Win32;

[assembly: AssemblyCompany("Aspen Technology Inc")]
[assembly: AssemblyProduct("aspenONE core component")]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyAssociatedContentFile("icon.ico")]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyTitle("AspenTech.Visualisation.Assistant.Run")]
[assembly: AssemblyDescription("Assistant display executable")]
[assembly: AssemblyConfiguration("Release")]
[assembly: Guid("848ec83d-3ca7-4d61-8879-cab72d6ee8c7")]
[assembly: CompilationRelaxations(8)]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: AssemblyCopyright("Copyright © 2004 - 2013 Aspen Technology Inc")]
[assembly: AssemblyInformationalVersion("8.1.0.0")]
[assembly: AssemblyFileVersion("27.0.0.25")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyVersion("1.0.0.0")]
namespace AspenTech.Visualisation.Assistant.Run;

[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
public class App : Application
{
	private void Application_Startup(object sender, StartupEventArgs e)
	{
		if (e.Args.Length == 0)
		{
			Aspen.Splash(Aspen.VersionSource.ExecutingAssembly);
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Title = "Select assistant file";
			openFileDialog.DefaultExt = "amf";
			openFileDialog.Filter = "Assistant files (*.amf)|*.amf|All files|*.*";
			openFileDialog.CheckFileExists = true;
			openFileDialog.CheckPathExists = true;
			OpenFileDialog openFileDialog2 = openFileDialog;
			if (openFileDialog2.ShowDialog() ?? false)
			{
				AssistRoot assistRoot = new AssistRoot();
				assistRoot.LoadFile(openFileDialog2.FileName);
				AssistantDialog assistantDialog = new AssistantDialog();
				assistantDialog.Assistant = assistRoot;
				assistantDialog.ShowDialog();
			}
		}
		else
		{
			string[] args = e.Args;
			foreach (string fileName in args)
			{
				AssistRoot assistRoot2 = new AssistRoot();
				assistRoot2.LoadFile(fileName);
				AssistantDialog assistantDialog2 = new AssistantDialog();
				assistantDialog2.Assistant = assistRoot2;
				assistantDialog2.ShowDialog();
			}
		}
	}

	private void Application_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
	{
	}

	[DebuggerNonUserCode]
	public void InitializeComponent()
	{
		base.Startup += Application_Startup;
		base.DispatcherUnhandledException += Application_DispatcherUnhandledException;
	}

	[STAThread]
	[DebuggerNonUserCode]
	public static void Main()
	{
		App app = new App();
		app.InitializeComponent();
		app.Run();
	}
}
