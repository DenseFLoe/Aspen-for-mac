using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Principal;
using System.Text;
using System.Web.UI;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Navigation;
using System.Xml;
using System.Xml.Linq;
using ASPENABOUTBOXLib;
using ASPENSPLASHLib;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: AssemblyFileVersion("27.0.0.25")]
[assembly: Guid("1B090395-1634-48C7-9EE7-63D78EA07A8A")]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyInformationalVersion("8.1.0.0")]
[assembly: AssemblyTitle("Aspen Assistant")]
[assembly: AssemblyDescription("Assistant display assembly")]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.0", FrameworkDisplayName = ".NET Framework 4")]
[assembly: AssemblyProduct("aspenONE core component")]
[assembly: ComVisible(false)]
[assembly: AssemblyCompany("Aspen Technology Inc")]
[assembly: AssemblyConfiguration("Release")]
[assembly: AssemblyCopyright("Copyright © 2004 - 2013 Aspen Technology Inc")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace AspenTech.Visualisation.Controls.Assistant
{
	public static class Aspen
	{
		public enum VersionSource
		{
			ExecutingAssembly,
			CallingAssembly,
			EntryAssembly
		}

		private static Assembly Assembly(VersionSource source)
		{
			return source switch
			{
				VersionSource.CallingAssembly => System.Reflection.Assembly.GetCallingAssembly(), 
				VersionSource.EntryAssembly => System.Reflection.Assembly.GetEntryAssembly(), 
				VersionSource.ExecutingAssembly => System.Reflection.Assembly.GetExecutingAssembly(), 
				_ => throw new ArgumentOutOfRangeException("source"), 
			};
		}

		public static void About(VersionSource source)
		{
			AspenAboutBox aspenAboutBox = (AspenAboutBox)Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid("55E3D11A-F9BB-4C89-B8B8-1344CB67F182")));
			Assembly assembly = Assembly(source);
			FileVersionInfo versionInfo = FileVersionInfo.GetVersionInfo(assembly.Location);
			aspenAboutBox.AppCopyright = versionInfo.LegalCopyright;
			aspenAboutBox.AppName = versionInfo.FileDescription;
			aspenAboutBox.AppVersion = versionInfo.FileVersion;
			string text = versionInfo.LegalCopyright.Trim();
			string text2 = string.Empty;
			bool flag = true;
			string text3 = text;
			foreach (char c in text3)
			{
				if (char.IsDigit(c))
				{
					text2 += c;
					continue;
				}
				if (!string.IsNullOrWhiteSpace(text2))
				{
					short num = short.Parse(text2, NumberStyles.Integer, CultureInfo.InvariantCulture);
					if (num > 1900 && num < 2200)
					{
						if (flag)
						{
							aspenAboutBox.BeginCopyDate = text2;
							flag = false;
						}
						aspenAboutBox.EndCopyDate = text2;
					}
				}
				text2 = string.Empty;
			}
			string text4 = versionInfo.ProductVersion;
			for (int num2 = text4.Count((char x) => x == '.'); num2 < 3; num2++)
			{
				text4 += ".0";
			}
			aspenAboutBox.ExternalVersion = text4;
			aspenAboutBox.Show();
		}

		public static void Splash(VersionSource source)
		{
			SplashWindow splashWindow = (SplashWindow)Activator.CreateInstance(Type.GetTypeFromCLSID(new Guid("5EC5EB43-13E3-11D3-840D-000000000000")));
			Assembly assembly = Assembly(source);
			FileVersionInfo versionInfo = FileVersionInfo.GetVersionInfo(assembly.Location);
			_ = versionInfo.ProductVersion;
			string text = versionInfo.LegalCopyright.Trim();
			short num = 0;
			short num2 = 0;
			string text2 = string.Empty;
			string text3 = text;
			foreach (char c in text3)
			{
				if (char.IsDigit(c))
				{
					text2 += c;
					continue;
				}
				if (!string.IsNullOrWhiteSpace(text2))
				{
					short num3 = short.Parse(text2, NumberStyles.Integer, CultureInfo.InvariantCulture);
					if (num3 > 1900 && num3 < 2200)
					{
						num = num2;
						num2 = num3;
					}
				}
				text2 = string.Empty;
			}
			if (num == 0)
			{
				num = num2;
			}
			if (num == 0)
			{
				num = (num2 = (short)DateTime.Now.Year);
			}
			List<string> list = versionInfo.ProductVersion.Split('.').ToList();
			while (list.Count > 3)
			{
				list.RemoveAt(3);
			}
			if (list.Count == 3 && list[2] == "0")
			{
				list.RemoveAt(2);
			}
			if (list.Count == 1)
			{
				list.Add("0");
			}
			splashWindow.ShowSplash2(versionInfo.FileDescription, versionInfo.Comments, string.Join(".", list), num, num2, null);
		}
	}
}
namespace AspenTech.Visualisation.Controls.Assistant.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "10.0.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
	[DebuggerNonUserCode]
	[CompilerGenerated]
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			get
			{
				if (object.ReferenceEquals(resourceMan, null))
				{
					ResourceManager resourceManager = new ResourceManager("AspenTech.Visualisation.Controls.Assistant.Properties.Resources", typeof(Resources).Assembly);
					resourceMan = resourceManager;
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		internal Resources()
		{
		}
	}
}
namespace AspenTech.Visualisation.Controls.Assistant
{
	internal delegate void GenericCommandExecute(object parameter);
	internal delegate bool GenericCommandCanExecute(object parameter);
	internal class GenericCommandHandler : ICommand, INotifyPropertyChanged
	{
		private GenericCommandExecute _execute;

		private GenericCommandCanExecute _canExecute;

		private object _tag;

		private string _toolTip;

		public object Tag
		{
			get
			{
				return _tag;
			}
			set
			{
				if (_tag != value)
				{
					_tag = value;
					RaisePropertyChanged("Tag");
				}
			}
		}

		public string ToolTip
		{
			get
			{
				return _toolTip;
			}
			set
			{
				if (_toolTip != value)
				{
					_toolTip = value;
					RaisePropertyChanged("ToolTip");
				}
			}
		}

		public event EventHandler CanExecuteChanged;

		public event PropertyChangedEventHandler PropertyChanged;

		public GenericCommandHandler(GenericCommandExecute execute)
		{
			_execute = execute;
		}

		public GenericCommandHandler(GenericCommandCanExecute canExecute, GenericCommandExecute execute)
		{
			_canExecute = canExecute;
			_execute = execute;
		}

		public void RaiseCanExecuteChanged()
		{
			this.CanExecuteChanged?.Invoke(this, EventArgs.Empty);
		}

		public bool CanExecute(object parameter)
		{
			if (_canExecute != null)
			{
				return _canExecute(parameter);
			}
			return true;
		}

		public void Execute(object parameter)
		{
			if (_execute != null)
			{
				_execute(parameter);
			}
		}

		private void RaisePropertyChanged(string property)
		{
			this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
		}
	}
	[Flags]
	internal enum HtmlStyle
	{
		includeTitle = 1,
		liveOptions = 2,
		processManualLink = 4
	}
	internal static class Renderer
	{
		internal static void RenderStyleFile(HtmlTextWriter writer, string fileName)
		{
			string path = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), fileName);
			if (File.Exists(path))
			{
				writer.AddAttribute(HtmlTextWriterAttribute.Type, "text/css");
				writer.RenderBeginTag("style");
				writer.Write(File.ReadAllText(path));
				writer.RenderEndTag();
			}
		}

		internal static void RenderAssistantInfo(HtmlTextWriter writer, AssistRoot root)
		{
			writer.RenderBeginTag(HtmlTextWriterTag.Hr);
			writer.RenderEndTag();
			writer.AddAttribute(HtmlTextWriterAttribute.Class, "infoBlock");
			writer.RenderBeginTag(HtmlTextWriterTag.Table);
			if (!string.IsNullOrWhiteSpace(root.Copyright))
			{
				writer.RenderBeginTag(HtmlTextWriterTag.Tr);
				writer.WriteTagText(HtmlTextWriterTag.Th, "Copyright:");
				writer.WriteTagText(HtmlTextWriterTag.Td, root.Copyright);
				writer.RenderEndTag();
			}
			if (!string.IsNullOrWhiteSpace(root.Author))
			{
				writer.RenderBeginTag(HtmlTextWriterTag.Tr);
				writer.WriteTagText(HtmlTextWriterTag.Th, "Author:");
				writer.WriteTagText(HtmlTextWriterTag.Td, root.Author);
				writer.RenderEndTag();
			}
			writer.RenderBeginTag(HtmlTextWriterTag.Tr);
			writer.WriteTagText(HtmlTextWriterTag.Th, "Build date:");
			writer.WriteTagText(HtmlTextWriterTag.Td, root.BuildDate.ToString());
			writer.RenderEndTag();
			writer.RenderEndTag();
		}

		internal static void RenderGenerationInfo(HtmlTextWriter writer)
		{
			writer.RenderBeginTag(HtmlTextWriterTag.Hr);
			writer.RenderEndTag();
			writer.AddAttribute(HtmlTextWriterAttribute.Class, "infoBlock");
			writer.RenderBeginTag(HtmlTextWriterTag.Table);
			writer.RenderBeginTag(HtmlTextWriterTag.Tr);
			writer.WriteTagText(HtmlTextWriterTag.Th, "User:");
			writer.WriteTagText(HtmlTextWriterTag.Td, Environment.UserDomainName + "\\" + Environment.UserName);
			writer.RenderEndTag();
			writer.RenderBeginTag(HtmlTextWriterTag.Tr);
			writer.WriteTagText(HtmlTextWriterTag.Th, "Computer:");
			writer.WriteTagText(HtmlTextWriterTag.Td, Environment.MachineName);
			writer.RenderEndTag();
			writer.RenderBeginTag(HtmlTextWriterTag.Tr);
			writer.WriteTagText(HtmlTextWriterTag.Th, "Generated:");
			writer.WriteTagText(HtmlTextWriterTag.Td, DateTime.Now.ToString());
			writer.RenderEndTag();
			writer.RenderEndTag();
		}

		internal static void RenderAsHtml(HtmlTextWriter html, AssistRoot root, HtmlStyle style, string linkPrefix, string highlightOption)
		{
			if (html == null)
			{
				throw new ArgumentNullException("html");
			}
			if (root != null)
			{
				if (style.HasFlag(HtmlStyle.includeTitle))
				{
					html.WriteTagText(HtmlTextWriterTag.H2, root.Caption);
				}
				RenderExplanations(html, root);
			}
		}

		internal static void RenderAsHtml(HtmlTextWriter html, AssistScreen screen, HtmlStyle style, string linkPrefix, string highlightOption)
		{
			if (html == null)
			{
				throw new ArgumentNullException("html");
			}
			if (screen == null)
			{
				return;
			}
			if (style.HasFlag(HtmlStyle.includeTitle))
			{
				html.WriteTagText(HtmlTextWriterTag.H2, screen.Caption);
			}
			RenderExplanations(html, screen);
			html.RenderBeginTag(HtmlTextWriterTag.Ul);
			foreach (AssistOption option in screen.Options)
			{
				if (!string.IsNullOrWhiteSpace(option.Caption))
				{
					html.RenderBeginTag(HtmlTextWriterTag.Li);
					bool flag = string.Compare(highlightOption, option.Id, StringComparison.OrdinalIgnoreCase) == 0;
					if (flag)
					{
						html.RenderBeginTag(HtmlTextWriterTag.B);
					}
					if (style.HasFlag(HtmlStyle.liveOptions))
					{
						html.AddAttribute(HtmlTextWriterAttribute.Href, linkPrefix + "/" + screen.Id + "/" + option.Id);
						html.RenderBeginTag(HtmlTextWriterTag.A);
					}
					else
					{
						html.RenderBeginTag(HtmlTextWriterTag.U);
					}
					html.WriteEncodedText(option.Caption);
					html.RenderEndTag();
					if (flag)
					{
						html.Write(" &#10004;");
					}
					RenderExplanations(html, option);
					if (flag)
					{
						html.RenderEndTag();
					}
					html.RenderEndTag();
				}
			}
			html.RenderEndTag();
		}

		private static void RenderExplanations(HtmlTextWriter html, AssistBase item)
		{
			if (item == null || item.Explanation == null || item.Explanation.Count <= 0)
			{
				return;
			}
			if (item.Explanation[0].StartsWith("<html", StringComparison.InvariantCultureIgnoreCase))
			{
				for (int i = 0; i < item.Explanation.Count - 1; i++)
				{
					string text = item.Explanation[i];
					int num;
					if (i == 0)
					{
						num = text.IndexOf('>');
						text = ((num <= 0) ? string.Empty : text.Substring(num + 1));
					}
					num = text.IndexOf("</html", StringComparison.InvariantCultureIgnoreCase);
					if (num < 0)
					{
						html.Write(text);
						continue;
					}
					html.Write(text.Substring(0, num));
					break;
				}
				return;
			}
			foreach (string item2 in item.Explanation)
			{
				html.WriteTagText(HtmlTextWriterTag.P, item2);
			}
		}
	}
	public abstract class AssistBasic
	{
		public string Id { get; set; }

		internal XName RootElementName { get; private set; }

		internal abstract XElement DehydrateToXml();

		internal abstract void HydrateFromXml(XElement root);

		public AssistBasic(XName rootElementName)
		{
			RootElementName = rootElementName;
		}
	}
	public abstract class AssistBase : AssistBasic
	{
		public string Caption { get; set; }

		public IList<string> Explanation { get; private set; }

		public AssistRoot Root { get; protected set; }

		protected AssistBase(AssistRoot root, XName rootElementName)
			: base(rootElementName)
		{
			Root = root;
			Explanation = new List<string>();
			Caption = null;
		}

		protected void ExplanationsToXml(XElement parent)
		{
			foreach (string item in Explanation)
			{
				parent.Add(new XElement(XmlConstants.Elements.Explanation, item));
			}
		}

		protected void ExplanationsFromXml(XElement parent)
		{
			foreach (XElement item in parent.Elements(XmlConstants.Elements.Explanation))
			{
				Explanation.Add(item.Value);
			}
		}

		public void Change()
		{
			if (Root != null)
			{
				Root.Changed = true;
				Root.BuildDate = DateTime.Now;
			}
		}
	}
	public class AssistRoot : AssistBase
	{
		public AssistScreens Screens { get; private set; }

		public string Filename { get; private set; }

		public bool Changed { get; set; }

		public string First { get; set; }

		public string Author { get; set; }

		public string AuthorId { get; set; }

		public string Version { get; set; }

		public string ModifierId { get; set; }

		public string CurrentUserId { get; set; }

		public string Copyright { get; set; }

		public DateTime BuildDate { get; set; }

		public IDictionary<string, string> Translations { get; private set; }

		public AssistRoot()
			: this(Guid.NewGuid().ToString() + " " + Environment.UserName)
		{
		}

		public AssistRoot(string currentUserId)
			: base(null, XmlConstants.Elements.Assistant)
		{
			Translations = new Dictionary<string, string>();
			base.Id = "A1";
			base.Caption = "Assistant " + base.Id;
			Copyright = "Copyright Aspen Technology Inc";
			Changed = false;
			AuthorId = currentUserId;
			ModifierId = currentUserId;
			CurrentUserId = currentUserId;
			base.Root = this;
			Screens = new AssistScreens();
		}

		public void Save(bool saveAs)
		{
			if (saveAs || string.IsNullOrWhiteSpace(Filename))
			{
				SaveFileDialog saveFileDialog = new SaveFileDialog();
				saveFileDialog.Title = "Save assistant definition";
				saveFileDialog.Filter = "Assistant files (*." + Constants.AssistantExtension + ",*." + Constants.AssistantExtensionExtended + ")|*." + Constants.AssistantExtension + ",*." + Constants.AssistantExtensionExtended + "|All files (*.*)|*.*";
				saveFileDialog.FilterIndex = 0;
				saveFileDialog.FileName = Filename;
				saveFileDialog.DefaultExt = Constants.AssistantExtension;
				saveFileDialog.CheckPathExists = true;
				saveFileDialog.CheckFileExists = false;
				SaveFileDialog saveFileDialog2 = saveFileDialog;
				if ((!saveFileDialog2.ShowDialog()) ?? true)
				{
					return;
				}
				Filename = Filename;
			}
			File.WriteAllText(Filename, SaveString());
			Changed = false;
		}

		public void Load(bool showDialog)
		{
			if (Changed)
			{
				switch (MessageBox.Show("Existing information not saved. Would you like to save it first?", "Data not saved", MessageBoxButton.YesNoCancel))
				{
				case MessageBoxResult.Yes:
					Save(saveAs: false);
					break;
				case MessageBoxResult.Cancel:
					return;
				}
			}
			if (showDialog || string.IsNullOrWhiteSpace(Filename))
			{
				OpenFileDialog openFileDialog = new OpenFileDialog();
				openFileDialog.Title = "Save assistant definition";
				openFileDialog.Filter = "Assistant files (*." + Constants.AssistantExtension + ",*." + Constants.AssistantExtensionExtended + ")|*." + Constants.AssistantExtension + ",*." + Constants.AssistantExtensionExtended + "|All files (*.*)|*.*";
				openFileDialog.FilterIndex = 0;
				openFileDialog.CheckFileExists = true;
				openFileDialog.CheckPathExists = true;
				openFileDialog.FileName = Filename;
				openFileDialog.DefaultExt = Constants.AssistantExtension;
				OpenFileDialog openFileDialog2 = openFileDialog;
				if ((!openFileDialog2.ShowDialog()) ?? true)
				{
					return;
				}
				Filename = Filename;
			}
			LoadFile(Filename);
		}

		public void LoadString(string text)
		{
			XDocument xDocument = XDocument.Parse(text);
			HydrateFromXml(xDocument.Root);
			Changed = false;
		}

		public void LoadFile(string fileName)
		{
			LoadString(File.ReadAllText(fileName));
			Filename = fileName;
		}

		public string SaveString()
		{
			StringBuilder stringBuilder = new StringBuilder();
			using (XmlWriter writer = XmlWriter.Create(stringBuilder, new XmlWriterSettings
			{
				Indent = true,
				Encoding = Encoding.UTF8
			}))
			{
				DehydrateToXml().WriteTo(writer);
			}
			Changed = false;
			return stringBuilder.ToString();
		}

		public void FromXml(XElement root)
		{
			HydrateFromXml(root);
		}

		internal override void HydrateFromXml(XElement root)
		{
			if (root.Name != XmlConstants.Elements.Assistant)
			{
				throw new ArgumentOutOfRangeException("root");
			}
			int num = root.Attribute(XmlConstants.Attributes.Version).Value(-1);
			if (num < Constants.VersionBack)
			{
				throw new ArgumentOutOfRangeException("root", $"File version {num}, but only backward compatible to {Constants.VersionBack}");
			}
			num = root.Attribute(XmlConstants.Attributes.Backwards).Value(-1);
			if (num > Constants.VersionNow)
			{
				throw new ArgumentOutOfRangeException("root", string.Format("File version is backward compatible to {1}, not {0}", num, Constants.VersionNow));
			}
			XElement xElement = root.Element(XmlConstants.Elements.Author);
			Author = xElement.Value;
			AuthorId = xElement.Attribute(XmlConstants.Attributes.Id).Value(string.Empty);
			XElement xElement2 = root.Element(XmlConstants.Elements.Modifier);
			ModifierId = xElement2.Attribute(XmlConstants.Attributes.Id).Value(string.Empty);
			int num2 = root.Element(XmlConstants.Elements.BuildDate).Value(0);
			BuildDate = new DateTime(num2 / 10000, num2 / 100 % 100, num2 % 100);
			Copyright = root.Element(XmlConstants.Elements.Copyright).Value(string.Empty);
			First = root.Element(XmlConstants.Elements.First).Value(string.Empty);
			base.Caption = root.Element(XmlConstants.Elements.Caption).Value(string.Empty);
			ExplanationsFromXml(root);
			foreach (XElement item in root.Elements(XmlConstants.Elements.Screen))
			{
				AssistScreen assistScreen = new AssistScreen(this);
				assistScreen.HydrateFromXml(item);
				Screens.Add(assistScreen);
			}
			Translations.Clear();
			foreach (XElement item2 in root.Elements(XmlConstants.Elements.Translations))
			{
				foreach (XElement item3 in item2.Elements(XmlConstants.Elements.Translation))
				{
					Translations[item3.Attribute(XmlConstants.Attributes.TranslationKey).Value] = item3.Attribute(XmlConstants.Attributes.TranslationValue).Value;
				}
			}
			Changed = false;
		}

		internal override XElement DehydrateToXml()
		{
			XElement xElement = new XElement(XmlConstants.Elements.Assistant, new XAttribute(XmlConstants.Attributes.Id, base.Id), new XAttribute(XmlConstants.Attributes.Version, Constants.VersionNow), new XAttribute(XmlConstants.Attributes.Backwards, Constants.VersionBack), new XElement(XmlConstants.Elements.Author, new XAttribute(XmlConstants.Attributes.Id, AuthorId), Author), new XElement(XmlConstants.Elements.Modifier, new XAttribute(XmlConstants.Attributes.Id, ModifierId)), new XElement(XmlConstants.Elements.BuildDate, BuildDate.ToString("yyyyMMdd", CultureInfo.InvariantCulture)), new XElement(XmlConstants.Elements.Version, BuildDate.ToString("yyyyMMdd", CultureInfo.InvariantCulture)), new XElement(XmlConstants.Elements.BuildDate, BuildDate.ToString("yyyyMMdd", CultureInfo.InvariantCulture)), new XElement(XmlConstants.Elements.BuildDate, BuildDate.ToString("yyyyMMdd", CultureInfo.InvariantCulture)), new XElement(XmlConstants.Elements.BuildDate, BuildDate.ToString("yyyyMMdd", CultureInfo.InvariantCulture)));
			ExplanationsToXml(xElement);
			if (Translations.Count > 0)
			{
				XElement xElement2 = new XElement(XmlConstants.Elements.Translations);
				foreach (KeyValuePair<string, string> translation in Translations)
				{
					xElement2.Add(new XElement(XmlConstants.Elements.Translation, new XAttribute(XmlConstants.Attributes.TranslationKey, translation.Key), new XAttribute(XmlConstants.Attributes.TranslationValue, translation.Value)));
				}
				xElement.Add(xElement2);
			}
			return xElement;
		}
	}
	public class AssistScreens : List<AssistScreen>
	{
	}
	internal interface IAssistantViewModel : INotifyPropertyChanged
	{
		string ScreenId { get; set; }

		IScreenViewModel Screen { get; }

		IRootViewModel Root { get; }

		ICommand SelectCommand { get; }

		ICommand RedoCommand { get; }

		ICommand UndoCommand { get; }

		string RenderToHtml(RenderTarget target);

		string RenderAllToHtml(RenderTarget target);
	}
	internal class AssistantViewModel : IAssistantViewModel, INotifyPropertyChanged
	{
		private AssistRoot _root;

		private AssistScreen _screen;

		private Dictionary<string, string> _selected = new Dictionary<string, string>();

		private GenericCommandHandler _selectCommand;

		private GenericCommandHandler _redoCommand;

		private GenericCommandHandler _undoCommand;

		private ObservableCollection<AssistScreen> _history = new ObservableCollection<AssistScreen>();

		public string ScreenId
		{
			get
			{
				return _screen.Id;
			}
			set
			{
				if (_root == null || !(((_screen == null) ? null : _screen.Id) != value))
				{
					return;
				}
				AssistScreen assistScreen = _root.Screens.FirstOrDefault((AssistScreen x) => x.Id == value);
				if (assistScreen == null)
				{
					return;
				}
				for (int num = 0; num < _history.Count; num++)
				{
					if (_history[num] == assistScreen)
					{
						while (num < _history.Count)
						{
							_history.RemoveAt(num);
						}
						break;
					}
				}
				_history.Add(assistScreen);
				SelectScreen(assistScreen);
			}
		}

		public IRootViewModel Root { get; private set; }

		public IScreenViewModel Screen { get; private set; }

		public ICommand SelectCommand
		{
			get
			{
				if (_selectCommand == null)
				{
					_selectCommand = new GenericCommandHandler(delegate(object param)
					{
						Find(param as string, out var _, out var option);
						return option != null;
					}, delegate(object param)
					{
						Find(param as string, out var screen, out var option);
						if (screen != null && option != null)
						{
							_selected[screen.Id] = option.Id;
							Execute(option);
						}
					});
				}
				return _selectCommand;
			}
		}

		public ICommand RedoCommand
		{
			get
			{
				if (_redoCommand == null)
				{
					_redoCommand = new GenericCommandHandler((object param) => DefaultOption(_screen, includeSelections: true) != null, delegate
					{
						AssistOption assistOption = DefaultOption(_screen, includeSelections: true);
						if (assistOption != null)
						{
							Execute(assistOption);
						}
					});
					_redoCommand.ToolTip = OptionCaption(DefaultOption(_screen, includeSelections: true));
				}
				return _redoCommand;
			}
		}

		public ICommand UndoCommand
		{
			get
			{
				if (_undoCommand == null)
				{
					_undoCommand = new GenericCommandHandler((object param) => _history.Count > 1, delegate
					{
						AssistScreen screen = _history[_history.Count - 2];
						_history.RemoveAt(_history.Count - 1);
						SelectScreen(screen);
					});
					_undoCommand.ToolTip = ((_history.Count > 1) ? _history[_history.Count - 2].Caption : null);
				}
				return _undoCommand;
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		internal AssistantViewModel(AssistRoot assistant)
		{
			_root = assistant;
			_selected.Clear();
			Root = new RootViewModel(_root);
			_selected.Add(_root.Id, _root.First);
		}

		private void Find(string path, out AssistScreen screen, out AssistOption option)
		{
			screen = null;
			option = null;
			if (string.IsNullOrWhiteSpace(path))
			{
				return;
			}
			if (path.StartsWith("assist:", StringComparison.OrdinalIgnoreCase))
			{
				path = path.Remove(0, 7);
			}
			if (path.StartsWith("/"))
			{
				path = path.Remove(0, 1);
			}
			int pos = path.IndexOf('/');
			if (pos > 0)
			{
				screen = _root.Screens.FirstOrDefault((AssistScreen x) => x.Id == path.Substring(0, pos));
				if (screen != null)
				{
					option = screen.Options.FirstOrDefault((AssistOption x) => x.Id == path.Substring(pos + 1));
				}
			}
			else
			{
				screen = _root.Screens.FirstOrDefault((AssistScreen x) => x.Id == path);
			}
		}

		private AssistOption DefaultOption(AssistScreen screen, bool includeSelections)
		{
			if (screen == null)
			{
				return new AssistOption(_root);
			}
			if (screen.Options.Count == 1)
			{
				return screen.Options[0];
			}
			if (includeSelections)
			{
				if (_selected.TryGetValue(screen.Id, out var opt))
				{
					return screen.Options.FirstOrDefault((AssistOption x) => x.Id == opt);
				}
			}
			return null;
		}

		private string OptionCaption(AssistOption option)
		{
			if (option == null)
			{
				return null;
			}
			StringBuilder stringBuilder = new StringBuilder();
			if (option.Caption != null)
			{
				stringBuilder.Append(option.Caption);
			}
			stringBuilder.AppendLine();
			switch (option.Action)
			{
			case Action.Goto:
			case Action.GotoButton:
			{
				AssistScreen assistScreen = _root.Screens.FirstOrDefault((AssistScreen x) => x.Id == option.Command);
				if (assistScreen != null && !string.IsNullOrWhiteSpace(assistScreen.Caption))
				{
					stringBuilder.Append(assistScreen.Caption);
				}
				break;
			}
			}
			if (stringBuilder.Length == 0)
			{
				return null;
			}
			string text = stringBuilder.ToString().Trim();
			if (string.IsNullOrWhiteSpace(text))
			{
				return null;
			}
			return text;
		}

		private void SelectScreen(AssistScreen screen)
		{
			Screen = new ScreenViewModel(_screen = screen);
			DoPropertyChanged("ScreenId");
			DoPropertyChanged("Screen");
			if (_redoCommand != null)
			{
				_redoCommand.ToolTip = OptionCaption(DefaultOption(screen, includeSelections: true));
				_redoCommand.RaiseCanExecuteChanged();
			}
			if (_undoCommand != null)
			{
				_undoCommand.ToolTip = ((_history.Count > 1) ? _history[_history.Count - 2].Caption : null);
				_undoCommand.RaiseCanExecuteChanged();
			}
		}

		public string RenderToHtml(RenderTarget target)
		{
			StringBuilder stringBuilder = new StringBuilder();
			using (StringWriter writer = new StringWriter(stringBuilder))
			{
				using HtmlTextWriter htmlTextWriter = new HtmlTextWriter(writer);
				try
				{
					htmlTextWriter.RenderBeginTag("html");
					htmlTextWriter.AddAttribute("http-equiv", "Content-Type");
					htmlTextWriter.AddAttribute("content", "text/html;charset=utf-16");
					htmlTextWriter.RenderBeginTag("meta");
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderBeginTag("head");
					htmlTextWriter.WriteTagText(HtmlTextWriterTag.Title, (_screen == null) ? _root.Caption : _screen.Caption);
					Renderer.RenderStyleFile(htmlTextWriter, "AspenTech.Visualisation.Controls.Assistant." + target.ToString() + ".css");
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderBeginTag("body");
					if (_screen == null)
					{
						Renderer.RenderAsHtml(htmlTextWriter, _root, HtmlStyle.liveOptions, "assist:", _root.First);
					}
					else
					{
						_selected.TryGetValue(_screen.Id, out var value);
						Renderer.RenderAsHtml(htmlTextWriter, _screen, HtmlStyle.liveOptions, "assist:", value);
					}
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderEndTag();
				}
				finally
				{
					htmlTextWriter.Close();
				}
			}
			return stringBuilder.ToString();
		}

		public string RenderAllToHtml(RenderTarget target)
		{
			StringBuilder stringBuilder = new StringBuilder();
			using (StringWriter writer = new StringWriter(stringBuilder))
			{
				using HtmlTextWriter htmlTextWriter = new HtmlTextWriter(writer);
				try
				{
					htmlTextWriter.RenderBeginTag("html");
					htmlTextWriter.AddAttribute("http-equiv", "Content-Type");
					htmlTextWriter.AddAttribute("content", "text/html;charset=utf-16");
					htmlTextWriter.RenderBeginTag("meta");
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderBeginTag("head");
					htmlTextWriter.WriteTagText(HtmlTextWriterTag.Title, _root.Caption);
					Renderer.RenderStyleFile(htmlTextWriter, "AspenTech.Visualisation.Controls.Assistant." + target.ToString() + ".css");
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderBeginTag("body");
					Renderer.RenderAsHtml(htmlTextWriter, _root, HtmlStyle.includeTitle, "assist:", _root.First);
					foreach (AssistScreen item in _history)
					{
						_selected.TryGetValue(item.Id, out var value);
						Renderer.RenderAsHtml(htmlTextWriter, item, HtmlStyle.includeTitle, "assist:", value);
					}
					Renderer.RenderAssistantInfo(htmlTextWriter, _root);
					if (target == RenderTarget.Report)
					{
						Renderer.RenderGenerationInfo(htmlTextWriter);
					}
					htmlTextWriter.RenderEndTag();
					htmlTextWriter.RenderEndTag();
				}
				finally
				{
					htmlTextWriter.Close();
				}
			}
			return stringBuilder.ToString();
		}

		private string Comma(ref string text)
		{
			if (text == null)
			{
				return null;
			}
			if (text.StartsWith("\""))
			{
				int num = text.IndexOf("\"", 1);
				if (num > 0 && (num == text.Length - 1 || text[num + 1] == ','))
				{
					string result = text.Substring(1, num - 1);
					text = text.Substring(num + 2);
					return result;
				}
			}
			return Token(',', ref text);
		}

		private string Token(char delimiter, ref string text)
		{
			if (text == null)
			{
				return null;
			}
			int num = text.IndexOf(delimiter);
			if (num < 0)
			{
				string result = text;
				text = null;
				return result;
			}
			string result2 = text.Substring(0, num);
			text = text.Substring(num + 1);
			return result2;
		}

		private void Execute(AssistOption option)
		{
			try
			{
				switch (option.Action)
				{
				case Action.Goto:
				case Action.GotoButton:
					ScreenId = option.Command;
					break;
				case Action.Browse:
				{
					string text6 = option.Command;
					if (text6.StartsWith("SHOW(", StringComparison.OrdinalIgnoreCase))
					{
						text6 = text6.Remove(0, 5);
						if (text6.EndsWith(")"))
						{
							text6 = text6.Substring(0, text6.Length - 2);
						}
					}
					string text7 = Comma(ref text6);
					if (string.IsNullOrWhiteSpace(text6))
					{
						text6 = text7;
						text7 = "Text";
					}
					string text8 = Comma(ref text6);
					ProManLink proManLink = new ProManLink();
					proManLink.Action("Assist: " + option.Root.Id, option.Root.Version, proManLink.StringToAction(text7), Comma(ref text8), text6);
					break;
				}
				case Action.Assistant:
				{
					int num = option.Command.IndexOf(',');
					string text9;
					string fileName;
					if (num > 0)
					{
						text9 = option.Command.Substring(num + 1);
						fileName = option.Command.Substring(0, num);
					}
					else
					{
						text9 = null;
						fileName = option.Command;
					}
					string text10 = FindFile(fileName, option.Root.Filename);
					if (text10 != null)
					{
						AssistRoot assistRoot = new AssistRoot(option.Root.CurrentUserId);
						assistRoot.LoadFile(text10);
						AssistantDialog assistantDialog = new AssistantDialog();
						assistantDialog.Assistant = assistRoot;
						if (text9 != null)
						{
							assistRoot.CurrentUserId = text9;
						}
						assistantDialog.ShowDialog();
					}
					break;
				}
				case Action.Run:
				case Action.Internet:
					Process.Start(option.Command);
					break;
				case Action.Exec:
				{
					string text = option.Command;
					string text2 = null;
					string text3 = string.Empty;
					while (!string.IsNullOrWhiteSpace(text))
					{
						string text4;
						string text5;
						if (text[0] == '\'')
						{
							text = text.Substring(1);
							text4 = Token('\'', ref text);
							text5 = "'";
						}
						else if (text[0] == '"')
						{
							text = text.Substring(1);
							text4 = Token('"', ref text);
							text5 = "\"";
						}
						else
						{
							text4 = Token(' ', ref text);
							text5 = string.Empty;
						}
						if (text2 == null)
						{
							text2 = (File.Exists(text4) ? text4 : FindFile(text4, option.Root.Filename));
							continue;
						}
						if (text4.StartsWith("{$"))
						{
							text4 = FindFile(text4, option.Root.Filename);
							if (string.IsNullOrWhiteSpace(text5) && text4.Contains(' '))
							{
								text5 = "\"";
							}
						}
						text3 = text3 + " " + text5 + text4 + text5;
					}
					Process.Start(text2, text3.Trim());
					break;
				}
				case Action.Note:
					break;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message + "\r\n\r\nSee log file for details.");
			}
		}

		private static string FindFile(string fileName, string baseFile)
		{
			if (Path.IsPathRooted(fileName))
			{
				if (File.Exists(fileName))
				{
					return fileName;
				}
			}
			else
			{
				if (fileName.StartsWith("{"))
				{
					int num = fileName.IndexOf('}');
					if (num > 0)
					{
						fileName = fileName.Substring(num + 1);
						if (fileName.StartsWith("\\"))
						{
							fileName = fileName.Remove(0, 1);
						}
					}
				}
				string text;
				if (!string.IsNullOrWhiteSpace(baseFile))
				{
					text = Path.Combine(Path.GetDirectoryName(baseFile), fileName);
					if (File.Exists(text))
					{
						return text;
					}
				}
				if (AppDomain.CurrentDomain != null)
				{
					text = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, fileName);
					if (File.Exists(text))
					{
						return text;
					}
				}
				text = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), fileName);
				if (File.Exists(text))
				{
					return text;
				}
				text = Path.Combine(Path.GetDirectoryName(Assembly.GetEntryAssembly().Location), fileName);
				if (File.Exists(text))
				{
					return text;
				}
				text = Environment.GetEnvironmentVariable("Path");
				if (!string.IsNullOrWhiteSpace(text))
				{
					string[] array = text.Split(';');
					foreach (string path in array)
					{
						text = Path.Combine(path, fileName);
						if (File.Exists(text))
						{
							return text;
						}
					}
				}
			}
			return null;
		}

		private void DoPropertyChanged(string property)
		{
			this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
		}
	}
	internal interface IRootViewModel
	{
		string Title { get; }
	}
	internal class RootViewModel : IRootViewModel
	{
		private AssistRoot _root;

		public string Title => _root.Caption;

		internal RootViewModel(AssistRoot root)
		{
			_root = root;
		}
	}
	internal interface IScreenViewModel
	{
		string Title { get; }
	}
	internal class ScreenViewModel : IScreenViewModel
	{
		private AssistScreen _screen;

		public string Title => _screen.Caption;

		public string Id => _screen.Id;

		internal ScreenViewModel(AssistScreen screen)
		{
			_screen = screen;
		}
	}
	public enum Action
	{
		NoOperation,
		Goto,
		GotoButton,
		Assistant,
		Run,
		Browse,
		Internet,
		Note,
		Exec
	}
	public class AssistOption : AssistBase
	{
		public Action Action { get; set; }

		public string Command { get; set; }

		public AssistScreen Parent { get; private set; }

		public AssistOption(AssistScreen parent)
			: base(parent.Root, XmlConstants.Elements.Option)
		{
			Parent = parent;
			int num = 0;
			string text = parent.Id + ".";
			foreach (AssistOption option in parent.Options)
			{
				if (option.Id.StartsWith(text) && int.TryParse(option.Id.Substring(text.Length), NumberStyles.Integer, CultureInfo.InvariantCulture, out var result))
				{
					num = Math.Max(num, result);
				}
			}
			base.Id = Parent.Id + "." + (num + 1);
		}

		public AssistOption(AssistRoot root)
			: base(root, null)
		{
			Parent = null;
			Action = Action.Goto;
			Command = root.First;
			base.Caption = root.Caption;
			foreach (string item in root.Explanation)
			{
				base.Explanation.Add(item);
			}
		}

		internal override void HydrateFromXml(XElement root)
		{
			if (root.Name != XmlConstants.Elements.Option)
			{
				throw new ArgumentOutOfRangeException("root");
			}
			base.Id = root.Attribute(XmlConstants.Attributes.Id).Value(string.Empty);
			base.Caption = root.Element(XmlConstants.Elements.Caption).Value(string.Empty);
			ExplanationsFromXml(root);
			XElement xElement = root.Element(XmlConstants.Elements.Action);
			if (xElement == null)
			{
				Action = Action.NoOperation;
				Command = string.Empty;
			}
			else
			{
				Action = (Action)Enum.Parse(typeof(Action), xElement.Attribute(XmlConstants.Attributes.ActionType).Value(Action.NoOperation.ToString()), ignoreCase: true);
				Command = xElement.Attribute(XmlConstants.Attributes.Command).Value(string.Empty);
			}
		}

		internal override XElement DehydrateToXml()
		{
			XElement xElement = new XElement(XmlConstants.Elements.Option, new XAttribute(XmlConstants.Attributes.Id, base.Id), new XElement(XmlConstants.Elements.Caption, base.Caption));
			ExplanationsToXml(xElement);
			if (Action != Action.NoOperation)
			{
				xElement.Add(new XElement(XmlConstants.Elements.Action, new XAttribute(XmlConstants.Attributes.ActionType, Action.ToString().ToUpperInvariant()), new XAttribute(XmlConstants.Attributes.Command, Command)));
			}
			return xElement;
		}
	}
	public enum ProManAction
	{
		Text,
		Search,
		Structure,
		Content,
		Home,
		Login,
		Reindex,
		Support
	}
	internal class ProManBrowser
	{
		internal string Title { get; private set; }

		internal string Name { get; private set; }

		internal string Url { get; private set; }

		internal ProManBrowser(string name, string title, string url)
		{
			Name = name;
			Title = title;
			Url = url;
		}
	}
	internal class ProManBrowsers
	{
		private static ProManBrowsers _global;

		internal IList<ProManBrowser> Browsers { get; private set; }

		internal ProManBrowser CurrentBrowser { get; set; }

		internal static ProManBrowsers Global
		{
			get
			{
				if (_global == null)
				{
					_global = new ProManBrowsers();
					try
					{
						_global.TryBaseKey("Software\\AspenTech");
						_global.AddBrowsers(Registry.LocalMachine, "Software\\AspenTech\\Aspen Process Manual");
						_global.AddBrowsers(Registry.CurrentUser, "Software\\AEA Technology\\BaSYS\\ProMan\\Global");
						try
						{
							string value = WindowsIdentity.GetCurrent().User.Value;
							_global.TryBaseKey("Software\\Microsoft\\Internet Explorer\\InternetRegistry\\REGISTRY\\USER\\" + value + "\\Software\\AspenTech");
						}
						catch (Exception)
						{
						}
					}
					catch (Exception)
					{
					}
				}
				return _global;
			}
		}

		private void TryBaseKey(string key)
		{
			_global.AddBrowsers(Registry.CurrentUser, key + "\\Aspen Process Manual");
			_global.AddBrowsers(Registry.CurrentUser, key + "\\Process Manual\\Provider");
			if (_global.CurrentBrowser != null)
			{
				return;
			}
			string current = null;
			using (RegistryKey registryKey = Registry.CurrentUser.OpenSubKey(key + "\\Aspen Process Manual"))
			{
				if (registryKey != null)
				{
					current = registryKey.GetValue("Provider.Current") as string;
					if (string.IsNullOrWhiteSpace(current))
					{
						current = registryKey.GetValue("Provider.LastAccess") as string;
					}
				}
			}
			_global.CurrentBrowser = _global.Browsers.FirstOrDefault((ProManBrowser x) => x.Name == current) ?? _global.Browsers.FirstOrDefault();
		}

		internal ProManBrowsers()
		{
			Browsers = new List<ProManBrowser>();
		}

		private void AddBrowsers(RegistryKey key, string path)
		{
			using RegistryKey registryKey = key.OpenSubKey(path, writable: false);
			if (registryKey == null)
			{
				return;
			}
			string[] valueNames = registryKey.GetValueNames();
			string value;
			for (int i = 0; i < valueNames.Length; i++)
			{
				value = valueNames[i];
				if (registryKey.GetValue(value) is string text)
				{
					int num = text.IndexOf(',');
					if (num > 0 && !Browsers.Any((ProManBrowser x) => x.Name == value))
					{
						Browsers.Add(new ProManBrowser(value, text.Substring(0, num), text.Substring(num + 1)));
					}
				}
			}
		}
	}
	public class ProManLink
	{
		private static string[] _actionNames = new string[9] { "None", "Text", "Structure", "Search", "Topic", "Home", "Login", "ReIndex", "Support" };

		private static string[] _dataNames = new string[4] { "None", "Topic", "Structure", "Content" };

		internal bool IsCustomisable => ProManBrowsers.Global.Browsers.Count > 1;

		public bool IsOk => ProManBrowsers.Global.Browsers.Count > 0;

		public int ProviderCount => ProManBrowsers.Global.Browsers.Count;

		public string ProviderActive
		{
			get
			{
				if (ProManBrowsers.Global.CurrentBrowser != null)
				{
					return ProManBrowsers.Global.CurrentBrowser.Name;
				}
				return null;
			}
			set
			{
				foreach (ProManBrowser browser in ProManBrowsers.Global.Browsers)
				{
					if (browser.Name == value)
					{
						ProManBrowsers.Global.CurrentBrowser = browser;
					}
				}
			}
		}

		public void Action(string source, string version, ProManAction action, string code, string data)
		{
			string url = GetUrl(source, version, action, code, data);
			if (!string.IsNullOrWhiteSpace(url))
			{
				Process.Start(url);
			}
		}

		internal string GetUrl(string source, string version, ProManAction action, string code, string data)
		{
			ProManBrowser currentBrowser = ProManBrowsers.Global.CurrentBrowser;
			if (currentBrowser != null)
			{
				string text;
				switch (action)
				{
				case ProManAction.Text:
					text = "TEXT";
					break;
				case ProManAction.Structure:
					text = "STRUCTURE";
					break;
				case ProManAction.Search:
					text = "SEARCH";
					break;
				case ProManAction.Home:
					text = "HOME";
					break;
				case ProManAction.Login:
					text = "LOGIN";
					break;
				case ProManAction.Reindex:
					text = "REINDEX";
					break;
				case ProManAction.Support:
					text = "SUPPORT";
					break;
				default:
					return null;
				}
				return Render(currentBrowser.Url, code, code, text, source, version, data);
			}
			return null;
		}

		private string Render(string format, params string[] values)
		{
			StringBuilder stringBuilder = new StringBuilder();
			if (!string.IsNullOrWhiteSpace(format))
			{
				int num = 0;
				while (num < format.Length)
				{
					if (format[num] == '%')
					{
						num++;
						if (num == format.Length || format[num] == '%')
						{
							stringBuilder.Append('%');
							continue;
						}
						int num2 = format.IndexOf('s', num);
						if (num2 < 0)
						{
							num2 = format.Length;
						}
						string text = format.Substring(num, num2 - num);
						num = num2 + 1;
						int num3 = text.IndexOf(':');
						int num4 = XmlConvert.ToInt32(text.Substring(0, (num3 < 0) ? text.Length : num3));
						if (num4 >= 0 && num4 < values.Length)
						{
							stringBuilder.Append(values[num4]);
						}
					}
					else if (format[num] == '{')
					{
						int num5 = format.IndexOf('}', num);
						if (num5 < 0)
						{
							num5 = format.Length;
						}
						int num6 = XmlConvert.ToInt32(format.Substring(num + 1, num5 - num - 1));
						if (num6 >= 0 && num6 < values.Length)
						{
							stringBuilder.Append(values[num6]);
						}
						num = num5 + 1;
					}
					else
					{
						stringBuilder.Append(format[num++]);
					}
				}
			}
			if (stringBuilder.Length <= 0)
			{
				return null;
			}
			return stringBuilder.ToString();
		}

		public string Data(string source, string version, ProManAction action, string code, string data)
		{
			ProManBrowser currentBrowser = ProManBrowsers.Global.CurrentBrowser;
			if (currentBrowser != null)
			{
				string text;
				switch (action)
				{
				case ProManAction.Content:
					text = "CONTENTDATA";
					break;
				case ProManAction.Structure:
					text = "STRUCTUREDATA";
					break;
				default:
					return null;
				}
				WebRequest webRequest = WebRequest.Create(Render(currentBrowser.Url, code, code, text, source, version, data));
				webRequest.Credentials = CredentialCache.DefaultCredentials;
				using WebResponse webResponse = webRequest.GetResponse();
				using StreamReader streamReader = new StreamReader(webResponse.GetResponseStream());
				return streamReader.ReadToEnd();
			}
			return null;
		}

		internal string ActionToString(ProManAction action)
		{
			return action.ToString();
		}

		internal ProManAction StringToAction(string action)
		{
			return (ProManAction)Enum.Parse(typeof(ProManAction), action, ignoreCase: true);
		}

		public string ProviderTitle(int index)
		{
			if (index < 0 || index >= ProManBrowsers.Global.Browsers.Count)
			{
				return null;
			}
			return ProManBrowsers.Global.Browsers[index].Title;
		}

		public string ProviderId(int index)
		{
			if (index < 0 || index >= ProManBrowsers.Global.Browsers.Count)
			{
				return null;
			}
			return ProManBrowsers.Global.Browsers[index].Name;
		}
	}
	internal static class Extensions
	{
		internal static string Value(this XAttribute attribute, string defaultValue)
		{
			if (attribute == null)
			{
				return defaultValue;
			}
			return attribute.Value;
		}

		internal static int Value(this XAttribute attribute, int defaultValue)
		{
			if (attribute == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToInt32(attribute.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static long Value(this XAttribute attribute, long defaultValue)
		{
			if (attribute == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToInt64(attribute.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static Guid Value(this XAttribute attribute, Guid defaultValue)
		{
			if (attribute == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToGuid(attribute.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static string Value(this XElement element, string defaultValue)
		{
			if (element == null)
			{
				return defaultValue;
			}
			return element.Value;
		}

		internal static int Value(this XElement element, int defaultValue)
		{
			if (element == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToInt32(element.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static long Value(this XElement element, long defaultValue)
		{
			if (element == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToInt64(element.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static Guid Value(this XElement element, Guid defaultValue)
		{
			if (element == null)
			{
				return defaultValue;
			}
			try
			{
				return XmlConvert.ToGuid(element.Value);
			}
			catch
			{
				return defaultValue;
			}
		}

		internal static HtmlTextWriter WriteTagText(this HtmlTextWriter writer, HtmlTextWriterTag tag, string text)
		{
			writer.RenderBeginTag(tag);
			writer.WriteEncodedText(text);
			writer.RenderEndTag();
			return writer;
		}
	}
	public class AssistScreen : AssistBase
	{
		public AssistOptions Options { get; private set; }

		public AssistRoot Parent { get; private set; }

		public AssistScreen(AssistRoot root)
			: base(root, XmlConstants.Elements.Screen)
		{
			Parent = root;
			Options = new AssistOptions();
			int num = 0;
			foreach (AssistScreen screen in root.Screens)
			{
				if (screen.Id.StartsWith("S") && int.TryParse(screen.Id.Substring(1), NumberStyles.Integer, CultureInfo.InvariantCulture, out var result))
				{
					num = Math.Max(num, result);
				}
			}
			base.Caption = "Screen " + (num + 1);
			base.Id = "S" + (num + 1);
			Change();
		}

		internal override void HydrateFromXml(XElement root)
		{
			if (root.Name != XmlConstants.Elements.Screen)
			{
				throw new ArgumentOutOfRangeException("root");
			}
			base.Caption = root.Element(XmlConstants.Elements.Caption).Value(string.Empty);
			base.Id = root.Attribute(XmlConstants.Attributes.Id).Value(string.Empty);
			ExplanationsFromXml(root);
			foreach (XElement item in root.Elements(XmlConstants.Elements.Option))
			{
				AssistOption assistOption = new AssistOption(this);
				assistOption.HydrateFromXml(item);
				Options.Add(assistOption);
			}
		}

		internal override XElement DehydrateToXml()
		{
			XElement xElement = new XElement(XmlConstants.Elements.Screen);
			if (!string.IsNullOrWhiteSpace(base.Id))
			{
				xElement.Add(new XAttribute(XmlConstants.Attributes.Id, base.Id));
			}
			xElement.Add(new XElement(XmlConstants.Elements.Caption), base.Caption);
			ExplanationsToXml(xElement);
			foreach (AssistOption option in Options)
			{
				xElement.Add(option.DehydrateToXml());
			}
			return xElement;
		}
	}
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public class AssistantDialog : Window, IComponentConnector
	{
		private List<string> _deleteTheseFiles = new List<string>();

		internal AssistantControl AssistantControl;

		internal Button AboutButton;

		internal Button ReportButton;

		internal Button CloseButton;

		private bool _contentLoaded;

		public AssistRoot Assistant
		{
			get
			{
				return AssistantControl.Assistant;
			}
			set
			{
				AssistantControl.Assistant = value;
				Translate();
			}
		}

		public string CurrentScreen
		{
			get
			{
				return AssistantControl.CurrentScreen;
			}
			set
			{
				AssistantControl.CurrentScreen = value;
			}
		}

		public AssistantDialog()
		{
			InitializeComponent();
		}

		private void CloseButton_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void AboutButton_Click(object sender, RoutedEventArgs e)
		{
			Aspen.About(Aspen.VersionSource.CallingAssembly);
		}

		private void ReportButton_Click(object sender, RoutedEventArgs e)
		{
			string contents = AssistantControl.AssistantViewModel.RenderAllToHtml(RenderTarget.Report);
			string tempPath = Path.GetTempPath();
			string text;
			do
			{
				text = Path.Combine(tempPath, Guid.NewGuid().ToString() + ".html");
			}
			while (File.Exists(text));
			_deleteTheseFiles.Add(text);
			File.WriteAllText(text, contents);
			Process.Start(text);
		}

		private void ClearDeleteFiles()
		{
			string[] array = _deleteTheseFiles.ToArray();
			_deleteTheseFiles.Clear();
			string[] array2 = array;
			foreach (string path in array2)
			{
				if (File.Exists(path))
				{
					try
					{
						File.Delete(path);
					}
					catch
					{
					}
				}
			}
		}

		private void Translate()
		{
			AboutButton.Content = Translate("About…");
			ReportButton.Content = Translate("Report…");
			CloseButton.Content = Translate("Close");
			base.Title = Translate("Assistant") + " - " + Assistant.Caption;
		}

		private string Translate(string text)
		{
			if (Assistant != null && Assistant.Translations.TryGetValue(text, out var value))
			{
				return value;
			}
			return text;
		}

		private void Window_Closing(object sender, CancelEventArgs e)
		{
			ClearDeleteFiles();
		}

		[DebuggerNonUserCode]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.Assistant.W1;component/controls/assistantdialog.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				((AssistantDialog)target).Closing += Window_Closing;
				break;
			case 2:
				AssistantControl = (AssistantControl)target;
				break;
			case 3:
				AboutButton = (Button)target;
				AboutButton.Click += AboutButton_Click;
				break;
			case 4:
				ReportButton = (Button)target;
				ReportButton.Click += ReportButton_Click;
				break;
			case 5:
				CloseButton = (Button)target;
				CloseButton.Click += CloseButton_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public class AssistantControl : System.Windows.Controls.UserControl, IComponentConnector
	{
		private AssistRoot _root;

		internal WebBrowser webBrowser;

		private bool _contentLoaded;

		public AssistRoot Assistant
		{
			get
			{
				return _root;
			}
			set
			{
				if (_root == value)
				{
					return;
				}
				_root = value;
				IAssistantViewModel assistantViewModel = base.DataContext as IAssistantViewModel;
				if (assistantViewModel != value)
				{
					if (base.DataContext != null)
					{
						assistantViewModel.PropertyChanged -= ModelPropertyChanged;
					}
					if (_root != null)
					{
						assistantViewModel = (IAssistantViewModel)(base.DataContext = new AssistantViewModel(_root));
						assistantViewModel.PropertyChanged += ModelPropertyChanged;
						ShowScreen();
					}
					else
					{
						base.DataContext = null;
					}
				}
			}
		}

		internal IAssistantViewModel AssistantViewModel => (IAssistantViewModel)base.DataContext;

		public string CurrentScreen
		{
			get
			{
				if (AssistantViewModel == null)
				{
					return null;
				}
				return AssistantViewModel.ScreenId;
			}
			set
			{
				if (AssistantViewModel != null)
				{
					AssistantViewModel.ScreenId = value;
				}
			}
		}

		public AssistantControl()
		{
			InitializeComponent();
		}

		private void ModelPropertyChanged(object sender, PropertyChangedEventArgs e)
		{
			string propertyName;
			if ((propertyName = e.PropertyName) != null && propertyName == "Screen")
			{
				ShowScreen();
			}
		}

		private void ShowScreen()
		{
			string text = AssistantViewModel.RenderToHtml(RenderTarget.Screen);
			webBrowser.NavigateToString(text);
		}

		private void webBrowser_Navigating(object sender, NavigatingCancelEventArgs e)
		{
			Uri uri = e.Uri;
			if (uri != null && uri.Scheme == "assist")
			{
				if (AssistantViewModel.SelectCommand.CanExecute(uri.ToString()))
				{
					AssistantViewModel.SelectCommand.Execute(uri.ToString());
				}
				e.Cancel = true;
			}
		}

		[DebuggerNonUserCode]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.Assistant.W1;component/controls/assistantcontrol.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[EditorBrowsable(EditorBrowsableState.Never)]
		[DebuggerNonUserCode]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				webBrowser = (WebBrowser)target;
				webBrowser.Navigating += webBrowser_Navigating;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	internal enum RenderTarget
	{
		Screen,
		Report
	}
	public class BoolOpacityConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if ((bool)value)
			{
				return 1.0;
			}
			return parameter;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	internal static class XmlConstants
	{
		internal static class Elements
		{
			internal static readonly XName Assistant = Namespace + "ASSISTANT";

			internal static readonly XName Caption = Namespace + "CAPTION";

			internal static readonly XName Author = Namespace + "AUTHOR";

			internal static readonly XName Action = Namespace + "ACTION";

			internal static readonly XName Explanation = Namespace + "DESCRIPTION";

			internal static readonly XName Screen = Namespace + "SCREEN";

			internal static readonly XName Option = Namespace + "OPTION";

			internal static readonly XName First = Namespace + "FIRST";

			internal static readonly XName BuildDate = Namespace + "BUILDDATE";

			internal static readonly XName Copyright = Namespace + "COPYRIGHT";

			internal static readonly XName Modifier = Namespace + "MODIFIER";

			internal static readonly XName Version = "VERSION";

			internal static readonly XName Notes = "NOTES";

			internal static readonly XName Translations = "TRANSLATIONS";

			internal static readonly XName Translation = "ITEM";
		}

		internal static class Attributes
		{
			internal static readonly XName Id = "NAME";

			internal static readonly XName Code = "CODE";

			internal static readonly XName Command = "COMMAND";

			internal static readonly XName ActionType = "TYPE";

			internal static readonly XName Version = "VERSION";

			internal static readonly XName Backwards = "BACKWARDS";

			internal static readonly XName NoteName = "NAME";

			internal static readonly XName NoteType = "TYPE";

			internal static readonly XName NoteId = "ID";

			internal static readonly XName TranslationKey = "KEY";

			internal static readonly XName TranslationValue = "TEXT";
		}

		internal static readonly XNamespace Namespace = "";
	}
	internal static class Constants
	{
		internal static readonly string AssistantExtension = "amf";

		internal static readonly string AssistantExtensionExtended = "amfx";

		internal static int VersionBack = 0;

		internal static int VersionNow = 2;
	}
	public class AssistOptions : List<AssistOption>
	{
	}
}
namespace ASPENABOUTBOXLib
{
	[ComImport]
	[TypeIdentifier]
	[Guid("70BBA394-4F38-421A-BDB4-89D022A2515A")]
	[CompilerGenerated]
	[CoClass(typeof(object))]
	public interface AspenAboutBox : IAspenAboutBox
	{
	}
	[ComImport]
	[Guid("70BBA394-4F38-421A-BDB4-89D022A2515A")]
	[CompilerGenerated]
	[TypeIdentifier]
	public interface IAspenAboutBox
	{
		[DispId(1)]
		void Show();

		string AppName
		{
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(2)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		string AppCopyright
		{
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(3)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		string BeginCopyDate
		{
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(4)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		string EndCopyDate
		{
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(5)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		string AppVersion
		{
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(6)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		string ExternalVersion
		{
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[DispId(7)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}
	}
}
namespace ASPENSPLASHLib
{
	[ComImport]
	[Guid("5EC5EB42-13E3-11D3-840D-000000000000")]
	[CoClass(typeof(object))]
	[TypeIdentifier]
	[CompilerGenerated]
	public interface SplashWindow : ISplashWindow
	{
	}
	[ComImport]
	[TypeIdentifier]
	[Guid("5EC5EB42-13E3-11D3-840D-000000000000")]
	[CompilerGenerated]
	public interface ISplashWindow
	{
		void _VtblGap1_9();

		[DispId(10)]
		void ShowSplash2([In][MarshalAs(UnmanagedType.BStr)] string bstrTitle, [In][MarshalAs(UnmanagedType.BStr)] string bstrSubtitle, [In][MarshalAs(UnmanagedType.BStr)] string bstrVersion, [In] short nCopyrightFrom, [In] short nCopyrightTo, [In][MarshalAs(UnmanagedType.BStr)] string bstrLicensee);
	}
}
