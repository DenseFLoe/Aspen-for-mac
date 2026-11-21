using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Net;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.Versioning;
using System.Security;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xml.Linq;
using AspenTech.Visualisation.Controls.StartPage.Properties;
using AspenTech.Visualisation.Controls.Support.Commands;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/visualisation/startpage", "AspenTech.Visualisation.Controls.StartPage")]
[assembly: XmlnsPrefix("http://schemas.aspentech.com/xaml/presentation/visualisation/startpage", "atStartPage")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyCompany("AspenTech Inc.")]
[assembly: AssemblyConfiguration("Release")]
[assembly: AssemblyDescription("AspenTech Start Page")]
[assembly: AssemblyFileVersion("31.0.0.5")]
[assembly: AssemblyInformationalVersion("V14.0")]
[assembly: AssemblyProduct("Visualisation.Controls")]
[assembly: AssemblyTitle("AspenTech.Visualisation.Controls.StartPage.Wpf")]
[assembly: AssemblyVersion("31.0.0.5")]
namespace AspenTech.Visualisation.Controls.StartPage
{
	public class GetStartedSidebar : UserControl, IComponentConnector, IStyleConnector
	{
		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(GetStartedSidebar), new PropertyMetadata(string.Empty, null));

		public static readonly DependencyProperty WhatsNewImageProperty = DependencyProperty.Register("WhatsNewImage", typeof(ImageSource), typeof(GetStartedSidebar), new PropertyMetadata(null, OnWhatsNewImagePropertyChanged));

		public static readonly DependencyProperty WhatsNewCommandProperty = DependencyProperty.Register("WhatsNewCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnWhatsNewCommandPropertyChanged));

		public static readonly DependencyProperty TutorialsCommandProperty = DependencyProperty.Register("TutorialsCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnTutorialsCommandPropertyChanged));

		public static readonly DependencyProperty TrainingCommandProperty = DependencyProperty.Register("TrainingCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnTrainingCommandPropertyChanged));

		public static readonly DependencyProperty DocumentationCommandProperty = DependencyProperty.Register("DocumentationCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnDocumentationCommandPropertyChanged));

		public static readonly DependencyProperty SearchCommandProperty = DependencyProperty.Register("SearchCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnSearchCommandPropertyChanged));

		public static readonly DependencyProperty CustomerSupportCommandProperty = DependencyProperty.Register("CustomerSupportCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnCustomerSupportCommandPropertyChanged));

		private static readonly DependencyPropertyKey LinksPropertyKey = DependencyProperty.RegisterReadOnly("Links", typeof(IEnumerable), typeof(GetStartedSidebar), new PropertyMetadata(null));

		public static readonly DependencyProperty LinksProperty = LinksPropertyKey.DependencyProperty;

		internal GetStartedSidebar _root;

		private bool _contentLoaded;

		public string Title
		{
			get
			{
				return GetValue(TitleProperty) as string;
			}
			set
			{
				SetValue(TitleProperty, value);
			}
		}

		public ImageSource WhatsNewImage
		{
			get
			{
				return GetValue(WhatsNewImageProperty) as ImageSource;
			}
			set
			{
				SetValue(WhatsNewImageProperty, value);
			}
		}

		public ICommand WhatsNewCommand
		{
			get
			{
				return GetValue(WhatsNewCommandProperty) as ICommand;
			}
			set
			{
				SetValue(WhatsNewCommandProperty, value);
			}
		}

		public ICommand TutorialsCommand
		{
			get
			{
				return GetValue(TutorialsCommandProperty) as ICommand;
			}
			set
			{
				SetValue(TutorialsCommandProperty, value);
			}
		}

		public ICommand TrainingCommand
		{
			get
			{
				return GetValue(TrainingCommandProperty) as ICommand;
			}
			set
			{
				SetValue(TrainingCommandProperty, value);
			}
		}

		public ICommand DocumentationCommand
		{
			get
			{
				return GetValue(DocumentationCommandProperty) as ICommand;
			}
			set
			{
				SetValue(DocumentationCommandProperty, value);
			}
		}

		public ICommand SearchCommand
		{
			get
			{
				return GetValue(SearchCommandProperty) as ICommand;
			}
			set
			{
				SetValue(SearchCommandProperty, value);
			}
		}

		public ICommand CustomerSupportCommand
		{
			get
			{
				return GetValue(CustomerSupportCommandProperty) as ICommand;
			}
			set
			{
				SetValue(CustomerSupportCommandProperty, value);
			}
		}

		public IEnumerable Links
		{
			get
			{
				return GetValue(LinksProperty) as IEnumerable;
			}
			private set
			{
				SetValue(LinksPropertyKey, value);
			}
		}

		public GetStartedSidebar()
		{
			Title = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.GetStartedTitle;
			InitializeComponent();
		}

		private static void OnWhatsNewImagePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnWhatsNewCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnTutorialsCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnTrainingCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnDocumentationCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnSearchCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private static void OnCustomerSupportCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is GetStartedSidebar getStartedSidebar)
			{
				getStartedSidebar.RefreshLinks();
			}
		}

		private void RefreshLinks()
		{
			ObservableCollection<LinkItem> observableCollection = new ObservableCollection<LinkItem>();
			if (WhatsNewCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.WhatsNewText,
					ImageSource = WhatsNewImage,
					ClickAction = delegate
					{
						WhatsNewCommand.Execute(null);
					}
				});
			}
			if (SearchCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.SearchText,
					ImageSource = ImageResources.Search,
					ClickAction = delegate
					{
						SearchCommand.Execute(null);
					}
				});
			}
			if (TutorialsCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.TutorialsText,
					ImageSource = ImageResources.Tutorials,
					ClickAction = delegate
					{
						TutorialsCommand.Execute(null);
					}
				});
			}
			if (TrainingCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.TrainingText,
					ImageSource = ImageResources.Training,
					ClickAction = delegate
					{
						TrainingCommand.Execute(null);
					}
				});
			}
			if (DocumentationCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.DocumentationText,
					ImageSource = ImageResources.Documentation,
					ClickAction = delegate
					{
						DocumentationCommand.Execute(null);
					}
				});
			}
			if (CustomerSupportCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.CustomerSupportText,
					ImageSource = ImageResources.CustomerSupport,
					ClickAction = delegate
					{
						CustomerSupportCommand.Execute(null);
					}
				});
			}
			Links = observableCollection;
		}

		private void Hyperlink_Click(object sender, RoutedEventArgs e)
		{
			if (sender is Hyperlink { DataContext: LinkItem { ClickAction: not null } dataContext })
			{
				dataContext.ClickAction(dataContext);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.StartPage.Wpf;V31.0.0.5;component/getstartedsidebar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				_root = (GetStartedSidebar)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				((Hyperlink)target).Click += Hyperlink_Click;
			}
		}
	}
	public static class ImageResources
	{
		private static readonly string ThisAssemblyName = Assembly.GetAssembly(typeof(ImageResources)).FullName;

		private static readonly Dictionary<string, ImageSource> _imageSources = new Dictionary<string, ImageSource>();

		public static ImageSource NewFile_16 => GetImageSource("New_16.png");

		public static ImageSource NewFile_32 => GetImageSource("New_32.png");

		public static ImageSource OpenOtherFile_16 => GetImageSource("Open_16.png");

		public static ImageSource OpenOtherFile_32 => GetImageSource("Open_32.png");

		public static ImageSource Search => GetImageSource("Search_16.png");

		public static ImageSource Training => GetImageSource("Training_32.png");

		public static ImageSource Tutorials => GetImageSource("Video_32.png");

		public static ImageSource CustomerSupport => GetImageSource("CustomerSupport_32.png");

		public static ImageSource Documentation => GetImageSource("OnlineDocumentation_16.png");

		private static ImageSource GetImageSource(string imageFileName)
		{
			ImageSource value = null;
			if (!_imageSources.TryGetValue(imageFileName, out value))
			{
				string uriString = "pack://application:,,,/" + ThisAssemblyName + ";component/images/" + imageFileName;
				try
				{
					BitmapImage bitmapImage = new BitmapImage();
					bitmapImage.BeginInit();
					bitmapImage.UriSource = new Uri(uriString, UriKind.Absolute);
					bitmapImage.EndInit();
					if (bitmapImage.CanFreeze)
					{
						bitmapImage.Freeze();
					}
					value = bitmapImage;
				}
				catch (Exception)
				{
				}
				if (value != null)
				{
					_imageSources[imageFileName] = value;
				}
			}
			return value;
		}
	}
	public class LinkItem : INotifyPropertyChanged
	{
		private string _text;

		private string _toolTip;

		private ImageSource _imageSource;

		public string Text
		{
			get
			{
				return _text;
			}
			set
			{
				_text = value;
				OnPropertyChanged("Text");
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
				_toolTip = value;
				OnPropertyChanged("ToolTip");
			}
		}

		public ImageSource ImageSource
		{
			get
			{
				return _imageSource;
			}
			set
			{
				_imageSource = value;
				OnPropertyChanged("ImageSource");
				OnPropertyChanged("ImageVisibility");
			}
		}

		public Visibility ImageVisibility
		{
			get
			{
				if (_imageSource == null)
				{
					return Visibility.Collapsed;
				}
				return Visibility.Visible;
			}
		}

		public object Tag { get; set; }

		public Action<LinkItem> ClickAction { get; set; }

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string name)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(name));
			}
		}
	}
	public class LinkGroup : INotifyPropertyChanged
	{
		private string _title;

		private ObservableCollection<LinkItem> _links = new ObservableCollection<LinkItem>();

		public string Title
		{
			get
			{
				return _title;
			}
			set
			{
				_title = value;
				OnPropertyChanged("Title");
				OnPropertyChanged("TitleVisibility");
			}
		}

		public Visibility TitleVisibility
		{
			get
			{
				if (!string.IsNullOrEmpty(_title))
				{
					return Visibility.Visible;
				}
				return Visibility.Collapsed;
			}
		}

		public ICollection<LinkItem> Links => _links;

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string name)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(name));
			}
		}
	}
	public class LinkGroupSidebar : UserControl, IComponentConnector, IStyleConnector
	{
		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(LinkGroupSidebar), new PropertyMetadata(string.Empty, null));

		private ObservableCollection<LinkItem> _links = new ObservableCollection<LinkItem>();

		internal LinkGroupSidebar _root;

		private bool _contentLoaded;

		public string Title
		{
			get
			{
				return GetValue(TitleProperty) as string;
			}
			set
			{
				SetValue(TitleProperty, value);
			}
		}

		public ICollection<LinkItem> Links => _links;

		public Action<LinkItem> DefaultClickAction { get; set; }

		public LinkGroupSidebar()
		{
			InitializeComponent();
		}

		private void Hyperlink_Click(object sender, RoutedEventArgs e)
		{
			if (sender is Hyperlink { DataContext: LinkItem dataContext })
			{
				if (dataContext.ClickAction != null)
				{
					dataContext.ClickAction(dataContext);
				}
				else if (DefaultClickAction != null)
				{
					DefaultClickAction(dataContext);
				}
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.StartPage.Wpf;V31.0.0.5;component/linkgroupsidebar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				_root = (LinkGroupSidebar)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				((Hyperlink)target).Click += Hyperlink_Click;
			}
		}
	}
	public class MRUFile : INotifyPropertyChanged
	{
		private string _filePath;

		private string _fileName;

		private ImageSource _fileImage;

		public string FilePath
		{
			get
			{
				return _filePath;
			}
			set
			{
				_filePath = value;
				if (!string.IsNullOrEmpty(_filePath) && string.IsNullOrEmpty(FileName))
				{
					string text = Path.GetFileName(_filePath);
					if (string.IsNullOrEmpty(text))
					{
						text = _filePath;
					}
					FileName = text;
				}
				OnPropertyChanged("FilePath");
			}
		}

		public string FileName
		{
			get
			{
				return _fileName;
			}
			set
			{
				_fileName = value;
				OnPropertyChanged("FileName");
			}
		}

		public ImageSource FileImage
		{
			get
			{
				return _fileImage;
			}
			set
			{
				_fileImage = value;
				OnPropertyChanged("FileImage");
			}
		}

		public Action<MRUFile> OpenAction { get; set; }

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string name)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(name));
			}
		}
	}
	public class MRUSidebar : UserControl, IComponentConnector, IStyleConnector
	{
		private ObservableCollection<MRUFile> _mruFiles = new ObservableCollection<MRUFile>();

		public static readonly DependencyProperty OpenOtherFileTextProperty = DependencyProperty.Register("OpenOtherFileText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("Open...", null));

		public static readonly DependencyProperty NewFileTextProperty = DependencyProperty.Register("NewFileText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("New...", null));

		public static readonly DependencyProperty RecentFilesTextProperty = DependencyProperty.Register("RecentFilesText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("Recent", null));

		public static readonly DependencyProperty NewFileCommandProperty = DependencyProperty.Register("NewFileCommand", typeof(ICommand), typeof(MRUSidebar), new PropertyMetadata(null, OnNewFileCommandPropertyChanged));

		public static readonly DependencyProperty OpenOtherFileCommandProperty = DependencyProperty.Register("OpenOtherFileCommand", typeof(ICommand), typeof(MRUSidebar), new PropertyMetadata(null, OnOpenOtherFileCommandPropertyChanged));

		private static readonly DependencyPropertyKey NewAndOpenLinksPropertyKey = DependencyProperty.RegisterReadOnly("NewAndOpenLinks", typeof(IEnumerable), typeof(MRUSidebar), new PropertyMetadata(null));

		public static readonly DependencyProperty NewAndOpenLinksProperty = NewAndOpenLinksPropertyKey.DependencyProperty;

		private ObservableCollection<LinkItem> _newAndOpenLinks = new ObservableCollection<LinkItem>();

		internal MRUSidebar _root;

		private bool _contentLoaded;

		public ICollection<MRUFile> MRUFiles => _mruFiles;

		public string OpenOtherFileText
		{
			get
			{
				return GetValue(OpenOtherFileTextProperty) as string;
			}
			set
			{
				SetValue(OpenOtherFileTextProperty, value);
			}
		}

		public string NewFileText
		{
			get
			{
				return GetValue(NewFileTextProperty) as string;
			}
			set
			{
				SetValue(NewFileTextProperty, value);
			}
		}

		public string RecentFilesText
		{
			get
			{
				return GetValue(RecentFilesTextProperty) as string;
			}
			set
			{
				SetValue(RecentFilesTextProperty, value);
			}
		}

		public ICommand NewFileCommand
		{
			get
			{
				return GetValue(NewFileCommandProperty) as ICommand;
			}
			set
			{
				SetValue(NewFileCommandProperty, value);
			}
		}

		public ICommand OpenOtherFileCommand
		{
			get
			{
				return GetValue(OpenOtherFileCommandProperty) as ICommand;
			}
			set
			{
				SetValue(OpenOtherFileCommandProperty, value);
			}
		}

		public IEnumerable NewAndOpenLinks
		{
			get
			{
				return GetValue(NewAndOpenLinksProperty) as IEnumerable;
			}
			private set
			{
				SetValue(NewAndOpenLinksPropertyKey, value);
			}
		}

		public Action<MRUFile> DefaultOpenAction { get; set; }

		public MRUSidebar()
		{
			RecentFilesText = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.RecentFilesText;
			NewFileText = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.NewFileText;
			OpenOtherFileText = AspenTech.Visualisation.Controls.StartPage.Properties.Resources.OpenOtherFileText;
			InitializeComponent();
		}

		private static void OnNewFileCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is MRUSidebar mRUSidebar)
			{
				mRUSidebar.RefreshNewAndOpenLinks();
			}
		}

		private static void OnOpenOtherFileCommandPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is MRUSidebar mRUSidebar)
			{
				mRUSidebar.RefreshNewAndOpenLinks();
			}
		}

		private void RefreshNewAndOpenLinks()
		{
			ObservableCollection<LinkItem> observableCollection = new ObservableCollection<LinkItem>();
			if (NewFileCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = NewFileText,
					ImageSource = ImageResources.NewFile_16,
					ClickAction = delegate
					{
						NewFileCommand.Execute(null);
					}
				});
			}
			if (OpenOtherFileCommand != null)
			{
				observableCollection.Add(new LinkItem
				{
					Text = OpenOtherFileText,
					ImageSource = ImageResources.OpenOtherFile_16,
					ClickAction = delegate
					{
						OpenOtherFileCommand.Execute(null);
					}
				});
			}
			NewAndOpenLinks = observableCollection;
		}

		private void FileLink_Click(object sender, RoutedEventArgs e)
		{
			if (sender is Hyperlink { DataContext: MRUFile dataContext })
			{
				if (dataContext.OpenAction != null)
				{
					dataContext.OpenAction(dataContext);
				}
				else if (DefaultOpenAction != null)
				{
					DefaultOpenAction(dataContext);
				}
			}
		}

		private void Hyperlink_Click(object sender, RoutedEventArgs e)
		{
			if (sender is Hyperlink { DataContext: LinkItem { ClickAction: not null } dataContext })
			{
				dataContext.ClickAction(dataContext);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.StartPage.Wpf;V31.0.0.5;component/mrusidebar.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				_root = (MRUSidebar)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 2:
				((Hyperlink)target).Click += FileLink_Click;
				break;
			case 3:
				((Hyperlink)target).Click += Hyperlink_Click;
				break;
			}
		}
	}
	public class RssFeedItem : INotifyPropertyChanged
	{
		private string _link;

		private string _pubdate;

		private string _description;

		private string _title;

		public string Title
		{
			get
			{
				return _title;
			}
			set
			{
				_title = value;
				OnPropertyChanged("Title");
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

		public string PubDate
		{
			get
			{
				return _pubdate;
			}
			set
			{
				_pubdate = value;
				OnPropertyChanged("PubDate");
			}
		}

		public string Link
		{
			get
			{
				return _link;
			}
			set
			{
				_link = value;
				OnPropertyChanged("Link");
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string name)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(name));
			}
		}
	}
	public class RssFeed : INotifyPropertyChanged
	{
		private string _title;

		private Uri _feedUri;

		private bool _canEditFeed;

		private double _feedUpdateFrequency = 600000.0;

		private bool _credentialsInputRequired;

		private string _credentialsUserName;

		private SecureString _credentialsPassword;

		private string _statusMessage;

		private ObservableCollection<RssFeedItem> _feedItems;

		private bool _initialRefreshCalled;

		private RssFeedRequest _currentRequest;

		private DispatcherTimer _feedUpdateTimer;

		private Dispatcher _updateDispatcher;

		public string Title
		{
			get
			{
				return _title;
			}
			set
			{
				_title = value;
				OnPropertyChanged("Title");
			}
		}

		public Uri FeedUri
		{
			get
			{
				return _feedUri;
			}
			set
			{
				if (!(_feedUri != value))
				{
					return;
				}
				_feedUri = value;
				if (FeedItems != null)
				{
					FeedItems.Clear();
				}
				OnPropertyChanged("FeedUri");
				if (_feedUri != null)
				{
					StatusMessage = Resources.FeedStatus_WaitingForData;
					if (_initialRefreshCalled)
					{
						RefreshFeedCommand.Execute(null);
					}
				}
				else
				{
					StatusMessage = Resources.FeedStatus_NoFeedSpecified;
				}
			}
		}

		public bool CanEditFeed
		{
			get
			{
				return _canEditFeed;
			}
			set
			{
				_canEditFeed = value;
				OnPropertyChanged("CanEditFeed");
			}
		}

		public double FeedUpdateFrequency
		{
			get
			{
				return _feedUpdateFrequency;
			}
			set
			{
				if (_feedUpdateFrequency != value)
				{
					_feedUpdateFrequency = value;
					OnFeedUpdateFrequencyChanged();
				}
			}
		}

		public bool CredentialsInputRequired
		{
			get
			{
				return _credentialsInputRequired;
			}
			set
			{
				if (_credentialsInputRequired != value)
				{
					_credentialsInputRequired = value;
					OnPropertyChanged("CredentialsInputRequired");
				}
			}
		}

		public string CredentialsUserName
		{
			get
			{
				return _credentialsUserName;
			}
			set
			{
				if (value != _credentialsUserName)
				{
					_credentialsUserName = value;
					OnPropertyChanged("CredentialsUserName");
				}
			}
		}

		public SecureString CredentialsPassword
		{
			get
			{
				return _credentialsPassword;
			}
			set
			{
				if (value != _credentialsPassword)
				{
					_credentialsPassword = value;
					OnPropertyChanged("CredentialsPassword");
				}
			}
		}

		public string StatusMessage
		{
			get
			{
				return _statusMessage;
			}
			set
			{
				if (_statusMessage != value)
				{
					_statusMessage = value;
					OnPropertyChanged("StatusMessage");
				}
			}
		}

		public ObservableCollection<RssFeedItem> FeedItems
		{
			get
			{
				return _feedItems;
			}
			private set
			{
				_feedItems = value;
				OnPropertyChanged("FeedItems");
			}
		}

		public ICommand RefreshFeedCommand { get; private set; }

		public ICommand OpenRssLinkCommand { get; private set; }

		public Action<Uri> OpenRssLinkAction { get; set; }

		public event PropertyChangedEventHandler PropertyChanged;

		public RssFeed()
		{
			InitializeCommands();
			StatusMessage = Resources.FeedStatus_NoFeedSpecified;
		}

		private void InitializeCommands()
		{
			RefreshFeedCommand = new ActionCommand(ExecuteRefreshFeedCommand);
			OpenRssLinkCommand = new ActionCommand<object>(ExecuteOpenRssLinkCommand);
		}

		private void OnFeedUpdateFrequencyChanged()
		{
			OnPropertyChanged("FeedUpdateFrequency");
			if (_feedUpdateTimer != null)
			{
				StopFeedUpdateTimer();
				StartFeedUpdateTimer(_updateDispatcher);
			}
		}

		private void ExecuteRefreshFeedCommand()
		{
			_initialRefreshCalled = true;
			if (_currentRequest != null)
			{
				_currentRequest.Cancel();
				_currentRequest = null;
			}
			CredentialsInputRequired = false;
			if (FeedUri == null)
			{
				StatusMessage = Resources.FeedStatus_NoFeedSpecified;
				return;
			}
			if (FeedItems == null || FeedItems.Count == 0)
			{
				StatusMessage = Resources.FeedStatus_WaitingForData;
			}
			RssFeedRequest request = new RssFeedRequest
			{
				Feed = this
			};
			_currentRequest = request;
			request.FetchRssFeedItemsAsync().ContinueWith(delegate(Task t)
			{
				RefreshFeedAsyncComplete(t, request);
			}, TaskScheduler.FromCurrentSynchronizationContext());
		}

		private void RefreshFeedAsyncComplete(Task task, RssFeedRequest request)
		{
			if (request == _currentRequest)
			{
				_currentRequest = null;
			}
			Exception ex = null;
			if (task.IsFaulted)
			{
				ex = task.Exception;
			}
			if (request.IsCancellationRequested)
			{
				return;
			}
			if (ex == null)
			{
				StatusMessage = string.Empty;
				FeedItems = request.FeedItems;
				return;
			}
			IEnumerable<Exception> enumerable = null;
			enumerable = ((!(ex is AggregateException ex2)) ? ((IEnumerable<Exception>)new Exception[1] { ex }) : ((IEnumerable<Exception>)ex2.Flatten().InnerExceptions));
			foreach (Exception item in enumerable)
			{
				if (item is WebException { Response: HttpWebResponse { StatusCode: HttpStatusCode.Unauthorized } })
				{
					StatusMessage = string.Empty;
					CredentialsInputRequired = true;
					break;
				}
				StatusMessage = item.Message;
			}
		}

		private void ExecuteOpenRssLinkCommand(object param)
		{
			Uri uri = param as Uri;
			if (uri == null)
			{
				return;
			}
			if (OpenRssLinkAction != null)
			{
				OpenRssLinkAction(uri);
				return;
			}
			try
			{
				Process.Start(uri.ToString());
			}
			catch (Exception ex)
			{
				MessageBox.Show($"Unable to launch browser: {ex.Message}", "Open Link", MessageBoxButton.OK, MessageBoxImage.Exclamation);
			}
		}

		public void StartFeedUpdateTimer(Dispatcher dispatcher)
		{
			if (_feedUpdateTimer != null)
			{
				return;
			}
			double feedUpdateFrequency = FeedUpdateFrequency;
			if (feedUpdateFrequency <= 0.0)
			{
				return;
			}
			_updateDispatcher = dispatcher;
			_feedUpdateTimer = new DispatcherTimer(DispatcherPriority.ApplicationIdle);
			_feedUpdateTimer.Interval = TimeSpan.FromMilliseconds(feedUpdateFrequency);
			_feedUpdateTimer.Tick += _feedUpdateTimer_Tick;
			_feedUpdateTimer.Start();
			if (FeedItems == null)
			{
				if (_updateDispatcher != null)
				{
					_updateDispatcher.BeginInvoke(DispatcherPriority.ApplicationIdle, new EventHandler(_feedUpdateTimer_Tick), _feedUpdateTimer, EventArgs.Empty);
				}
				else
				{
					_feedUpdateTimer_Tick(_feedUpdateTimer, EventArgs.Empty);
				}
			}
		}

		public void StopFeedUpdateTimer()
		{
			if (_feedUpdateTimer != null)
			{
				_feedUpdateTimer.Stop();
				_feedUpdateTimer = null;
			}
		}

		private void _feedUpdateTimer_Tick(object sender, EventArgs args)
		{
			if (_updateDispatcher != null)
			{
				_updateDispatcher.VerifyAccess();
			}
			RefreshFeedCommand.Execute(null);
		}

		private void OnPropertyChanged(string name)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(name));
			}
		}
	}
	public class RssFeedRequest
	{
		private CancellationTokenSource _cancellationTokenSource;

		private CancellationToken _cancellationToken;

		public RssFeed Feed { get; set; }

		public ObservableCollection<RssFeedItem> FeedItems { get; set; }

		public bool IsCancellationRequested
		{
			get
			{
				_ = _cancellationToken;
				return _cancellationToken.IsCancellationRequested;
			}
		}

		public void Cancel()
		{
			if (_cancellationTokenSource != null)
			{
				_cancellationTokenSource.Cancel();
			}
		}

		public Task FetchRssFeedItemsAsync()
		{
			_cancellationTokenSource = new CancellationTokenSource();
			_cancellationToken = _cancellationTokenSource.Token;
			return Task.Factory.StartNew(GetWebResponseAsync, _cancellationToken);
		}

		private void GetWebResponseAsync()
		{
			_cancellationToken.ThrowIfCancellationRequested();
			WebRequest webRequest = WebRequest.Create(Feed.FeedUri);
			ICredentials credentials = CredentialCache.DefaultCredentials;
			if (!string.IsNullOrEmpty(Feed.CredentialsUserName))
			{
				string[] array = Feed.CredentialsUserName.Split(new char[1] { '\\' }, 2);
				credentials = ((array.Length >= 2) ? new NetworkCredential(array[1], Feed.CredentialsPassword, array[0]) : new NetworkCredential(Feed.CredentialsUserName, Feed.CredentialsPassword));
			}
			webRequest.Credentials = credentials;
			Task<WebResponse>.Factory.FromAsync(webRequest.BeginGetResponse, webRequest.EndGetResponse, null, TaskCreationOptions.AttachedToParent).ContinueWith(GetResponseBuffer, _cancellationToken, TaskContinuationOptions.AttachedToParent, TaskScheduler.Current);
		}

		private void GetResponseBuffer(Task<WebResponse> antecedent)
		{
			WebResponse webResponse = antecedent.Result;
			if (_cancellationToken.IsCancellationRequested)
			{
				webResponse.Close();
				_cancellationToken.ThrowIfCancellationRequested();
			}
			Stream responseStream = webResponse.GetResponseStream();
			byte[] buffer = new byte[2048];
			MemoryStream memoryStream = new MemoryStream();
			Task<int>.Factory.FromAsync(responseStream.BeginRead, responseStream.EndRead, buffer, 0, buffer.Length, null, TaskCreationOptions.AttachedToParent).ContinueWith(delegate(Task<int> t)
			{
				CollectResponse(t, webResponse, memoryStream, buffer);
			}, _cancellationToken, TaskContinuationOptions.AttachedToParent, TaskScheduler.Current);
		}

		private void CollectResponse(Task<int> antecedent, WebResponse webResponse, MemoryStream memoryStream, byte[] buffer)
		{
			if (_cancellationToken.IsCancellationRequested)
			{
				webResponse.Close();
				_cancellationToken.ThrowIfCancellationRequested();
			}
			int result = antecedent.Result;
			if (result > 0)
			{
				memoryStream.Write(buffer, 0, result);
				Stream responseStream = webResponse.GetResponseStream();
				Task<int>.Factory.FromAsync(responseStream.BeginRead, responseStream.EndRead, buffer, 0, buffer.Length, null, TaskCreationOptions.AttachedToParent).ContinueWith(delegate(Task<int> t)
				{
					CollectResponse(t, webResponse, memoryStream, buffer);
				}, _cancellationToken, TaskContinuationOptions.AttachedToParent, TaskScheduler.Current);
			}
			else
			{
				webResponse.Close();
				memoryStream.Seek(0L, SeekOrigin.Begin);
				ParseResponse(memoryStream);
			}
		}

		private void ParseResponse(Stream responseDataStream)
		{
			ObservableCollection<RssFeedItem> observableCollection = new ObservableCollection<RssFeedItem>();
			try
			{
				XDocument xDocument = XDocument.Load(responseDataStream, LoadOptions.None);
				if (string.Equals(xDocument.Root.Name.LocalName, "RSS", StringComparison.OrdinalIgnoreCase))
				{
					XElement xElement = xDocument.Root.Element("channel");
					if (xElement != null)
					{
						foreach (XElement item in xElement.Descendants("item"))
						{
							XElement xElement2 = item.Element("title");
							XElement xElement3 = item.Element("description");
							XElement xElement4 = item.Element("link");
							XElement xElement5 = item.Element("pubDate");
							string text = ((xElement5 != null) ? xElement5.Value.Trim() : string.Empty);
							if (!string.IsNullOrEmpty(text) && DateTime.TryParse(text, CultureInfo.InvariantCulture, DateTimeStyles.AssumeLocal, out var result))
							{
								text = result.ToString("D", CultureInfo.CurrentCulture);
							}
							observableCollection.Add(new RssFeedItem
							{
								Title = ReplaceHtmlEscapeCodes((xElement2 != null) ? xElement2.Value.Trim() : string.Empty),
								Description = ReplaceHtmlEscapeCodes((xElement3 != null) ? xElement3.Value.Trim() : string.Empty),
								Link = ((xElement4 != null) ? xElement4.Value.Trim() : string.Empty),
								PubDate = text
							});
						}
					}
				}
				else
				{
					if (!string.Equals(xDocument.Root.Name.LocalName, "feed", StringComparison.OrdinalIgnoreCase))
					{
						throw new Exception(Resources.FeedStatus_NotAnRSSorAtomFeed);
					}
					XNamespace xNamespace = xDocument.Root.Name.Namespace;
					foreach (XElement item2 in xDocument.Root.Descendants(xNamespace.GetName("entry")))
					{
						XElement xElement6 = item2.Element(xNamespace.GetName("title"));
						XElement xElement7 = item2.Element(xNamespace.GetName("summary"));
						XElement xElement8 = item2.Element(xNamespace.GetName("link"));
						XElement xElement9 = item2.Element(xNamespace.GetName("issued"));
						string link = string.Empty;
						if (xElement8 != null)
						{
							XAttribute xAttribute = xElement8.Attribute("href");
							if (xAttribute != null)
							{
								link = xAttribute.Value.Trim();
							}
						}
						string text2 = ((xElement9 != null) ? xElement9.Value.Trim() : string.Empty);
						if (!string.IsNullOrEmpty(text2) && DateTime.TryParse(text2, CultureInfo.InvariantCulture, DateTimeStyles.AssumeLocal, out var result2))
						{
							text2 = result2.ToString("D", CultureInfo.CurrentCulture);
						}
						observableCollection.Add(new RssFeedItem
						{
							Title = ReplaceHtmlEscapeCodes((xElement6 != null) ? xElement6.Value.Trim() : string.Empty),
							Description = ReplaceHtmlEscapeCodes((xElement7 != null) ? xElement7.Value.Trim() : string.Empty),
							Link = link,
							PubDate = text2
						});
					}
				}
			}
			catch (Exception innerException)
			{
				throw new Exception(Resources.FeedStatus_NotAnRSSorAtomFeed, innerException);
			}
			FeedItems = observableCollection;
		}

		private string ReplaceHtmlEscapeCodes(string value)
		{
			if (string.IsNullOrEmpty(value))
			{
				return value;
			}
			value = value.Replace("&nbsp;", " ");
			value = value.Replace("&amp;", "&");
			value = value.Replace("&lt;", "<");
			value = value.Replace("&gt;", ">");
			return value;
		}
	}
	public class RssFeedView : UserControl, IComponentConnector, IStyleConnector
	{
		public static readonly DependencyProperty RssFeedProperty = DependencyProperty.Register("RssFeed", typeof(RssFeed), typeof(RssFeedView), new PropertyMetadata(null, OnRssFeedPropertyChanged));

		internal RssFeedView _root;

		internal TextBox _feedUriTextBox;

		internal TextBox _txtBoxUserName;

		internal PasswordBox _txtBoxPassword;

		private bool _contentLoaded;

		public RssFeed RssFeed
		{
			get
			{
				return GetValue(RssFeedProperty) as RssFeed;
			}
			set
			{
				SetValue(RssFeedProperty, value);
			}
		}

		public RssFeedView()
		{
			RssFeed = new RssFeed();
			InitializeComponent();
			ExtraInitialize();
		}

		public RssFeedView(RssFeed feed)
		{
			RssFeed = ((feed != null) ? feed : new RssFeed());
			InitializeComponent();
			ExtraInitialize();
		}

		private void ExtraInitialize()
		{
			base.Loaded += RssFeedView_Loaded;
			base.Unloaded += RssFeedView_Unloaded;
			_txtBoxPassword.PasswordChanged += _txtBoxPassword_PasswordChanged;
			_feedUriTextBox.KeyDown += _feedUriTextBox_KeyDown;
		}

		private void _feedUriTextBox_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.Key == Key.Return)
			{
				_feedUriTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateSource();
				if (RssFeed != null)
				{
					RssFeed.RefreshFeedCommand.Execute(null);
				}
				e.Handled = true;
			}
		}

		private void RssFeedView_Loaded(object sender, RoutedEventArgs e)
		{
			if (RssFeed != null)
			{
				RssFeed.StartFeedUpdateTimer(base.Dispatcher);
			}
		}

		private void RssFeedView_Unloaded(object sender, RoutedEventArgs e)
		{
			if (RssFeed != null)
			{
				RssFeed.StopFeedUpdateTimer();
			}
		}

		private void _txtBoxPassword_PasswordChanged(object sender, RoutedEventArgs e)
		{
			if (RssFeed != null)
			{
				RssFeed.CredentialsPassword = _txtBoxPassword.SecurePassword;
			}
		}

		private static void OnRssFeedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is RssFeedView rssFeedView)
			{
				rssFeedView.OnRssFeedChanged(args.OldValue as RssFeed, args.NewValue as RssFeed);
			}
		}

		protected virtual void OnRssFeedChanged(RssFeed oldValue, RssFeed newValue)
		{
		}

		private void RssLink_Click(object sender, RoutedEventArgs e)
		{
			Hyperlink hyperlink = sender as Hyperlink;
			RssFeed.OpenRssLinkCommand.Execute(hyperlink.NavigateUri);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.StartPage.Wpf;V31.0.0.5;component/rssfeedview.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 1:
				_root = (RssFeedView)target;
				break;
			case 3:
				_feedUriTextBox = (TextBox)target;
				break;
			case 4:
				_txtBoxUserName = (TextBox)target;
				break;
			case 5:
				_txtBoxPassword = (PasswordBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 2)
			{
				((Hyperlink)target).Click += RssLink_Click;
			}
		}
	}
	public class StartPageUriConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				return value;
			}
			return value.ToString();
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			_ = DependencyProperty.UnsetValue;
			string text = value as string;
			if (!string.IsNullOrEmpty(text))
			{
				try
				{
					new Uri(text);
				}
				catch (Exception)
				{
				}
			}
			return value;
		}
	}
	public class StartPage : UserControl, IComponentConnector, IStyleConnector
	{
		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(StartPage));

		internal Grid LayoutRoot;

		internal Grid _sidebar;

		internal TabControl _tabControl;

		private bool _contentLoaded;

		public string Title
		{
			get
			{
				return GetValue(TitleProperty) as string;
			}
			set
			{
				SetValue(TitleProperty, value);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public TabControl TabControl => _tabControl;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public Grid Sidebar => _sidebar;

		public StartPage()
		{
			base.DataContext = this;
			InitializeComponent();
		}

		private void LinkItem_Click(object sender, RoutedEventArgs e)
		{
			if ((sender as Hyperlink).DataContext is LinkItem { ClickAction: not null } linkItem)
			{
				linkItem.ClickAction(linkItem);
			}
		}

		public void AddSidebarView(GridLength height, FrameworkElement view)
		{
			if (view != null)
			{
				Sidebar.RowDefinitions.Add(new RowDefinition
				{
					Height = height
				});
				Grid.SetRow(view, Sidebar.RowDefinitions.Count - 1);
				Sidebar.Children.Add(view);
			}
		}

		public void AddRssFeed(RssFeed feed)
		{
			RssFeedView rssFeedView = new RssFeedView(feed);
			TabItem tabItem = new TabItem
			{
				Content = rssFeedView
			};
			BindingOperations.SetBinding(tabItem, HeaderedContentControl.HeaderProperty, new Binding
			{
				Source = rssFeedView,
				Path = new PropertyPath("RssFeed.Title"),
				Mode = BindingMode.OneWay
			});
			_tabControl.Items.Add(tabItem);
		}

		public void AddCustomTab(TabItem tab)
		{
			if (tab != null)
			{
				_tabControl.Items.Add(tab);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.Controls.StartPage.Wpf;V31.0.0.5;component/startpage.xaml", UriKind.Relative);
				Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			switch (connectionId)
			{
			case 2:
				LayoutRoot = (Grid)target;
				break;
			case 3:
				_sidebar = (Grid)target;
				break;
			case 4:
				_tabControl = (TabControl)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IStyleConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				((Hyperlink)target).Click += LinkItem_Click;
			}
		}
	}
}
namespace AspenTech.Visualisation.Controls.StartPage.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
	[DebuggerNonUserCode]
	[CompilerGenerated]
	public class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static ResourceManager ResourceManager
		{
			get
			{
				if (resourceMan == null)
				{
					resourceMan = new ResourceManager("AspenTech.Visualisation.Controls.StartPage.Properties.Resources", typeof(Resources).Assembly);
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		public static CultureInfo Culture
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

		public static string ButtonRefresh => ResourceManager.GetString("ButtonRefresh", resourceCulture);

		public static string CredentialsPasswordLabel => ResourceManager.GetString("CredentialsPasswordLabel", resourceCulture);

		public static string CredentialsUserNameLabel => ResourceManager.GetString("CredentialsUserNameLabel", resourceCulture);

		public static string CustomerSupportText => ResourceManager.GetString("CustomerSupportText", resourceCulture);

		public static string DocumentationText => ResourceManager.GetString("DocumentationText", resourceCulture);

		public static string EnterCredentialsHelp => ResourceManager.GetString("EnterCredentialsHelp", resourceCulture);

		public static string FeedLabel => ResourceManager.GetString("FeedLabel", resourceCulture);

		public static string FeedStatus_EmptyFeed => ResourceManager.GetString("FeedStatus_EmptyFeed", resourceCulture);

		public static string FeedStatus_NoFeedSpecified => ResourceManager.GetString("FeedStatus_NoFeedSpecified", resourceCulture);

		public static string FeedStatus_NotAnRSSorAtomFeed => ResourceManager.GetString("FeedStatus_NotAnRSSorAtomFeed", resourceCulture);

		public static string FeedStatus_WaitingForData => ResourceManager.GetString("FeedStatus_WaitingForData", resourceCulture);

		public static string GetStartedTitle => ResourceManager.GetString("GetStartedTitle", resourceCulture);

		public static string NewFileText => ResourceManager.GetString("NewFileText", resourceCulture);

		public static string OpenOtherFileText => ResourceManager.GetString("OpenOtherFileText", resourceCulture);

		public static string RecentFilesText => ResourceManager.GetString("RecentFilesText", resourceCulture);

		public static string SearchText => ResourceManager.GetString("SearchText", resourceCulture);

		public static string String1 => ResourceManager.GetString("String1", resourceCulture);

		public static string TrainingText => ResourceManager.GetString("TrainingText", resourceCulture);

		public static string TutorialsText => ResourceManager.GetString("TutorialsText", resourceCulture);

		public static string WhatsNewText => ResourceManager.GetString("WhatsNewText", resourceCulture);

		internal Resources()
		{
		}
	}
}

// Coverage appendix for compiler-folded declarations and MethodDef implementations.
// The active C# above contains the reconstructed high-level forms. The comments below retain
// metadata names and show the expansions of methods that lack a direct declaration or sequence point in those forms.
// 0x02000010 AspenTech.Visualisation.Controls.StartPage.RssFeed+<>c__DisplayClass43_0
//   0x04000055 field: AspenTech.Visualisation.Controls.StartPage.RssFeed <>4__this
//   0x04000056 field: AspenTech.Visualisation.Controls.StartPage.RssFeedRequest request
// 0x02000011 AspenTech.Visualisation.Controls.StartPage.RssFeedRequest+<>c__DisplayClass13_0
//   0x04000057 field: AspenTech.Visualisation.Controls.StartPage.RssFeedRequest <>4__this
//   0x04000058 field: System.Net.WebResponse webResponse
//   0x04000059 field: System.IO.MemoryStream memoryStream
//   0x0400005a field: System.Byte[] buffer
// 0x02000012 AspenTech.Visualisation.Controls.StartPage.RssFeedRequest+<>c__DisplayClass14_0
//   0x0400005b field: AspenTech.Visualisation.Controls.StartPage.RssFeedRequest <>4__this
//   0x0400005c field: System.Net.WebResponse webResponse
//   0x0400005d field: System.IO.MemoryStream memoryStream
//   0x0400005e field: System.Byte[] buffer

// 0x06000020 AspenTech.Visualisation.Controls.StartPage.GetStartedSidebar..cctor
// using System.Collections;
// using System.Windows;
// using System.Windows.Input;
// using System.Windows.Media;
//
// static GetStartedSidebar()
// {
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(GetStartedSidebar), new PropertyMetadata(string.Empty, null));
// 	WhatsNewImageProperty = DependencyProperty.Register("WhatsNewImage", typeof(ImageSource), typeof(GetStartedSidebar), new PropertyMetadata(null, OnWhatsNewImagePropertyChanged));
// 	WhatsNewCommandProperty = DependencyProperty.Register("WhatsNewCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnWhatsNewCommandPropertyChanged));
// 	TutorialsCommandProperty = DependencyProperty.Register("TutorialsCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnTutorialsCommandPropertyChanged));
// 	TrainingCommandProperty = DependencyProperty.Register("TrainingCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnTrainingCommandPropertyChanged));
// 	DocumentationCommandProperty = DependencyProperty.Register("DocumentationCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnDocumentationCommandPropertyChanged));
// 	SearchCommandProperty = DependencyProperty.Register("SearchCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnSearchCommandPropertyChanged));
// 	CustomerSupportCommandProperty = DependencyProperty.Register("CustomerSupportCommand", typeof(ICommand), typeof(GetStartedSidebar), new PropertyMetadata(null, OnCustomerSupportCommandPropertyChanged));
// 	LinksPropertyKey = DependencyProperty.RegisterReadOnly("Links", typeof(IEnumerable), typeof(GetStartedSidebar), new PropertyMetadata(null));
// 	LinksProperty = LinksPropertyKey.DependencyProperty;
// }

// 0x06000031 AspenTech.Visualisation.Controls.StartPage.ImageResources..cctor
// using System.Collections.Generic;
// using System.Reflection;
// using System.Windows.Media;
//
// static ImageResources()
// {
// 	ThisAssemblyName = Assembly.GetAssembly(typeof(ImageResources)).FullName;
// 	_imageSources = new Dictionary<string, ImageSource>();
// }

// 0x0600003d AspenTech.Visualisation.Controls.StartPage.LinkItem.add_PropertyChanged
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

// 0x0600003e AspenTech.Visualisation.Controls.StartPage.LinkItem.remove_PropertyChanged
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

// 0x06000040 AspenTech.Visualisation.Controls.StartPage.LinkItem..ctor
// public LinkItem()
// {
// }

// 0x06000045 AspenTech.Visualisation.Controls.StartPage.LinkGroup.add_PropertyChanged
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

// 0x06000046 AspenTech.Visualisation.Controls.StartPage.LinkGroup.remove_PropertyChanged
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

// 0x06000048 AspenTech.Visualisation.Controls.StartPage.LinkGroup..ctor
// using System.Collections.ObjectModel;
//
// public LinkGroup()
// {
// 	_links = new ObservableCollection<LinkItem>();
// 	base..ctor();
// }

// 0x06000053 AspenTech.Visualisation.Controls.StartPage.LinkGroupSidebar..cctor
// using System.Windows;
//
// static LinkGroupSidebar()
// {
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(LinkGroupSidebar), new PropertyMetadata(string.Empty, null));
// }

// 0x0600005c AspenTech.Visualisation.Controls.StartPage.MRUFile.add_PropertyChanged
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

// 0x0600005d AspenTech.Visualisation.Controls.StartPage.MRUFile.remove_PropertyChanged
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

// 0x0600005f AspenTech.Visualisation.Controls.StartPage.MRUFile..ctor
// public MRUFile()
// {
// }

// 0x06000078 AspenTech.Visualisation.Controls.StartPage.MRUSidebar..cctor
// using System.Collections;
// using System.Windows;
// using System.Windows.Input;
//
// static MRUSidebar()
// {
// 	OpenOtherFileTextProperty = DependencyProperty.Register("OpenOtherFileText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("Open...", null));
// 	NewFileTextProperty = DependencyProperty.Register("NewFileText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("New...", null));
// 	RecentFilesTextProperty = DependencyProperty.Register("RecentFilesText", typeof(string), typeof(MRUSidebar), new PropertyMetadata("Recent", null));
// 	NewFileCommandProperty = DependencyProperty.Register("NewFileCommand", typeof(ICommand), typeof(MRUSidebar), new PropertyMetadata(null, OnNewFileCommandPropertyChanged));
// 	OpenOtherFileCommandProperty = DependencyProperty.Register("OpenOtherFileCommand", typeof(ICommand), typeof(MRUSidebar), new PropertyMetadata(null, OnOpenOtherFileCommandPropertyChanged));
// 	NewAndOpenLinksPropertyKey = DependencyProperty.RegisterReadOnly("NewAndOpenLinks", typeof(IEnumerable), typeof(MRUSidebar), new PropertyMetadata(null));
// 	NewAndOpenLinksProperty = NewAndOpenLinksPropertyKey.DependencyProperty;
// }

// 0x06000083 AspenTech.Visualisation.Controls.StartPage.RssFeedItem.add_PropertyChanged
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

// 0x06000084 AspenTech.Visualisation.Controls.StartPage.RssFeedItem.remove_PropertyChanged
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

// 0x06000086 AspenTech.Visualisation.Controls.StartPage.RssFeedItem..ctor
// public RssFeedItem()
// {
// }

// 0x060000a8 AspenTech.Visualisation.Controls.StartPage.RssFeed.add_PropertyChanged
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

// 0x060000a9 AspenTech.Visualisation.Controls.StartPage.RssFeed.remove_PropertyChanged
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

// 0x060000b7 AspenTech.Visualisation.Controls.StartPage.RssFeedRequest..ctor
// public RssFeedRequest()
// {
// }

// 0x060000c7 AspenTech.Visualisation.Controls.StartPage.RssFeedView..cctor
// using System.Windows;
//
// static RssFeedView()
// {
// 	RssFeedProperty = DependencyProperty.Register("RssFeed", typeof(RssFeed), typeof(RssFeedView), new PropertyMetadata(null, OnRssFeedPropertyChanged));
// }

// 0x060000ca AspenTech.Visualisation.Controls.StartPage.StartPageUriConverter..ctor
// public StartPageUriConverter()
// {
// }

// 0x060000d7 AspenTech.Visualisation.Controls.StartPage.StartPage..cctor
// using System.Windows;
//
// static StartPage()
// {
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(StartPage));
// }

// 0x060000f0 AspenTech.Visualisation.Controls.StartPage.RssFeed+<>c__DisplayClass43_0..ctor
// public <>c__DisplayClass43_0()
// {
// }

// 0x060000f2 AspenTech.Visualisation.Controls.StartPage.RssFeedRequest+<>c__DisplayClass13_0..ctor
// public <>c__DisplayClass13_0()
// {
// }

// 0x060000f4 AspenTech.Visualisation.Controls.StartPage.RssFeedRequest+<>c__DisplayClass14_0..ctor
// public <>c__DisplayClass14_0()
// {
// }
