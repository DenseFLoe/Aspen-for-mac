using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("38.0.0.301")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.SaveMergeNNFiles")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.SaveMergeNNFiles")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, Inc.")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("08BFCD6C-29DB-4C52-870C-51139A6002F8")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("38.0.0.301")]
namespace AspenTech.AspenPlus.SaveMergeNNFiles;

public static class SaveMergeNNFiles
{
	public static void CSharpSaveMergennFiles(string filename, string values)
	{
		List<string> mergennFileNames = (from t in values.Split(',')
			select t.Trim()).ToList();
		SaveFiles(filename, mergennFileNames);
	}

	private static void SaveFiles(string fileName, List<string> mergennFileNames)
	{
		if (!File.Exists(fileName) || mergennFileNames == null)
		{
			return;
		}
		try
		{
			StringBuilder stringBuilder = null;
			foreach (string mergennFileName in mergennFileNames)
			{
				string text = mergennFileName;
				if (!File.Exists(text))
				{
					text = Path.GetFileName(text);
				}
				if (!File.Exists(text))
				{
					text = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\AspenTech\\AIModeling\\MergeNNFiles", text);
				}
				if (File.Exists(text))
				{
					if (stringBuilder == null)
					{
						stringBuilder = new StringBuilder();
						StreamReader streamReader = new StreamReader(fileName, Encoding.Default);
						stringBuilder.Append(streamReader.ReadToEnd());
						streamReader.Close();
					}
					AddFnnFile(stringBuilder, text);
				}
			}
			if (stringBuilder != null)
			{
				File.WriteAllText(fileName, stringBuilder.ToString(), Encoding.Default);
			}
		}
		catch (Exception)
		{
		}
	}

	private static void AddFnnFile(StringBuilder sb, string fnnFile)
	{
		sb.Append("$_FNN_FILE " + fnnFile + "\r\n");
		string value = Convert.ToBase64String(File.ReadAllBytes(fnnFile));
		sb.Append(value);
		sb.Append("\r\n$_END_FNN_FILE\r\n");
	}
}
