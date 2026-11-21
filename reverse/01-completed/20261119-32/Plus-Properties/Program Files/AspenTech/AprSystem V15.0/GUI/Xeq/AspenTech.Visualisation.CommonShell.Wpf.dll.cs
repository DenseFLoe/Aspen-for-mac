#define TRACE
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xaml;
using System.Xml;
using AspenTech.Visualisation.CommonShell.AspenHelpAboutInterop;
using AspenTech.Visualisation.CommonShell.AspenSplashInterop;
using AspenTech.Visualisation.CommonShell.AutomationPeers;
using AspenTech.Visualisation.CommonShell.Internal;
using AspenTech.Visualisation.CommonShell.RibbonSupport;
using AspenTech.Visualisation.CommonShell.RibbonTools;
using AspenTech.Visualisation.Controls.Support;
using AspenTech.Visualisation.Controls.Support.AutomationPeers;
using AspenTech.Visualisation.Controls.Support.Commands;
using Infragistics.Shared;
using Infragistics.Windows;
using Infragistics.Windows.Controls;
using Infragistics.Windows.DockManager;
using Infragistics.Windows.DockManager.Events;
using Infragistics.Windows.Editors;
using Infragistics.Windows.OutlookBar;
using Infragistics.Windows.OutlookBar.Events;
using Infragistics.Windows.Ribbon;
using Infragistics.Windows.Ribbon.Events;
using Microsoft.Practices.Composite;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Logging;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Regions;
using Microsoft.Practices.Composite.Regions;
using Microsoft.Practices.Composite.UnityExtensions;
using Microsoft.Practices.Unity;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.MainAssembly)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/visualisation/commonshell", "AspenTech.Visualisation.CommonShell")]
[assembly: XmlnsDefinition("http://schemas.aspentech.com/xaml/presentation/visualisation/commonshell", "AspenTech.Visualisation.CommonShell.RibbonTools")]
[assembly: XmlnsPrefix("http://schemas.aspentech.com/xaml/presentation/visualisation/commonshell", "atShell")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyCompany("AspenTech Inc.")]
[assembly: AssemblyConfiguration("Release")]
[assembly: AssemblyDescription("Common Shell")]
[assembly: AssemblyFileVersion("31.0.0.5")]
[assembly: AssemblyInformationalVersion("V14.0")]
[assembly: AssemblyProduct("Visualisation.Controls")]
[assembly: AssemblyTitle("AspenTech.Visualisation.CommonShell.Wpf")]
[assembly: AssemblyVersion("31.0.0.5")]
namespace AspenTech.Visualisation.CommonShell
{
	public static class AspenHelpAbout
	{
		public static void ShowAboutDialog(string appName, string externalVersion, string internalVersion, string beginCopyright, string endCopyright)
		{
			ShowAboutDialog(appName, externalVersion, internalVersion, beginCopyright, endCopyright, string.Empty);
		}

		public static void ShowAboutDialog(string appName, string externalVersion, string internalVersion, string beginCopyright, string endCopyright, string additionalLegalText)
		{
			try
			{
				Type typeFromCLSID = Type.GetTypeFromCLSID(new Guid("55E3D11A-F9BB-4c89-B8B8-1344CB67F182"));
				if (!(typeFromCLSID == null) && Activator.CreateInstance(typeFromCLSID) is IAspenAboutBox aspenAboutBox)
				{
					aspenAboutBox.AppName = appName;
					aspenAboutBox.AppVersion = internalVersion;
					aspenAboutBox.ExternalVersion = externalVersion;
					aspenAboutBox.BeginCopyDate = beginCopyright;
					aspenAboutBox.EndCopyDate = endCopyright;
					if (!string.IsNullOrEmpty(additionalLegalText))
					{
						string legal = aspenAboutBox.Legal;
						legal += additionalLegalText;
						aspenAboutBox.Legal = legal;
					}
					aspenAboutBox.Show();
				}
			}
			catch (Exception)
			{
			}
		}
	}
	public static class AspenSplashScreen
	{
		public static void ShowSplashScreen(string title, string subtitle, string externalVersion, short copyrightFrom, short copyrightTo, string licenseChecks)
		{
			try
			{
				Type typeFromCLSID = Type.GetTypeFromCLSID(new Guid("5ec5eb43-13e3-11d3-840d-000000000000"));
				if (!(typeFromCLSID == null))
				{
					if (Activator.CreateInstance(typeFromCLSID) is ISplashWindow splashWindow)
					{
						splashWindow.ShowSplash2(title, subtitle, externalVersion, copyrightFrom, copyrightTo, "");
					}
					if (!string.IsNullOrEmpty(licenseChecks) && Activator.CreateInstance(typeFromCLSID) is ISplashWindow splashWindow2)
					{
						splashWindow2.CheckLicenseExpiration(licenseChecks);
					}
				}
			}
			catch (Exception)
			{
			}
		}
	}
	public abstract class CommonShellApplication : IShellApplication, INotifyPropertyChanged
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<IShellMainWindow, bool> CachedCallback38_0;

			internal bool ShowNewMainWindowCallback38_0(IShellMainWindow w)
			{
				return (w as Window).IsActive;
			}
		}

		private IUnityContainer _container;

		private Collection<IShellMainWindow> _mainWindows = new Collection<IShellMainWindow>();

		private ReadOnlyCollection<IShellMainWindow> _mainWindowsReadOnly;

		private ShellWorkspaceFolder _rootWorkspaceFolder = new ShellWorkspaceFolder();

		public IUnityContainer Container => _container;

		public System.Windows.Point? FirstWindowPos { get; set; }

		public System.Windows.Size? FirstWindowSize { get; set; }

		public WindowState? FirstWindowState { get; set; }

		public string RibbonQATCustomization { get; set; }

		public bool? RibbonQATLocationAboveRibbon { get; set; }

		protected abstract Type ShellMainWindowType { get; }

		public IShellMainWindow ActiveWindow
		{
			get
			{
				if (_mainWindows.Count <= 0)
				{
					return null;
				}
				return _mainWindows[0];
			}
			private set
			{
				if (value == null)
				{
					throw new ArgumentNullException("value");
				}
				if (_mainWindows.Count == 0 || _mainWindows[0] != value)
				{
					_mainWindows.Remove(value);
					_mainWindows.Insert(0, value);
					OnPropertyChanged("ActiveWindow");
				}
			}
		}

		public ReadOnlyCollection<IShellMainWindow> MainWindows
		{
			get
			{
				if (_mainWindowsReadOnly == null)
				{
					_mainWindowsReadOnly = new ReadOnlyCollection<IShellMainWindow>(_mainWindows);
				}
				return _mainWindowsReadOnly;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ShellWorkspaceFolder RootWorkspaceFolder => _rootWorkspaceFolder;

		public event PropertyChangedEventHandler PropertyChanged;

		protected CommonShellApplication(IUnityContainer container)
		{
			_container = container;
		}

		protected virtual void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}

		public IShellMainWindow ShowNewMainWindow()
		{
			return ShowNewMainWindow(null, null, null);
		}

		public IShellMainWindow ShowNewMainWindow(System.Windows.Point? preferredPosition, System.Windows.Size? preferredSize, WindowState? preferredState)
		{
			if (_mainWindows.Count == 0)
			{
				if (!preferredPosition.HasValue)
				{
					preferredPosition = FirstWindowPos;
				}
				if (!preferredSize.HasValue)
				{
					preferredSize = FirstWindowSize;
				}
				if (!preferredState.HasValue)
				{
					preferredState = FirstWindowState;
				}
			}
			else if (!preferredSize.HasValue)
			{
				Window window = _mainWindows.FirstOrDefault(CachedDelegates.CachedCallback38_0 ?? (CachedDelegates.CachedCallback38_0 = CachedDelegates.Instance.ShowNewMainWindowCallback38_0)) as Window;
				if (window == null)
				{
					window = _mainWindows[0] as Window;
				}
				preferredSize = new System.Windows.Size(window.Width, window.Height);
			}
			IUnityContainer unityContainer = Container.CreateChildContainer();
			unityContainer.AddNewExtension<UnityBootstrapperExtension>();
			unityContainer.AddNewExtension<RoutingEventAggregatorUnityExtension>();
			unityContainer.RegisterType<IEventAggregator, RoutingEventAggregator>(new ContainerControlledLifetimeManager(), Array.Empty<InjectionMember>());
			Type shellMainWindowType = ShellMainWindowType;
			unityContainer.RegisterType(typeof(IShellMainWindow), shellMainWindowType, new ContainerControlledLifetimeManager());
			ConfigureWindowContainer(unityContainer);
			IShellMainWindow shellMainWindow = unityContainer.Resolve<IShellMainWindow>(Array.Empty<ResolverOverride>());
			if (!(shellMainWindow is CommonShellWindow commonShellWindow))
			{
				throw new CommonShellException("The IShellMainWindow implementation must derive from CommonShellWindow");
			}
			RegionManager.SetRegionManager(commonShellWindow, unityContainer.Resolve<IRegionManager>(Array.Empty<ResolverOverride>()));
			RegionManager.UpdateRegions();
			AttachShellWindowEventHandlers(commonShellWindow);
			if (preferredState.HasValue)
			{
				commonShellWindow.WindowState = preferredState.Value;
			}
			if (preferredSize.HasValue)
			{
				if (preferredSize.Value.Width > commonShellWindow.MinWidth)
				{
					commonShellWindow.Width = preferredSize.Value.Width;
				}
				if (preferredSize.Value.Height > commonShellWindow.MinHeight)
				{
					commonShellWindow.Height = preferredSize.Value.Height;
				}
			}
			Rectangle virtualScreen = SystemInformation.VirtualScreen;
			if (commonShellWindow.Width > (double)virtualScreen.Width || commonShellWindow.Height > (double)virtualScreen.Height)
			{
				Rectangle workingArea = Screen.PrimaryScreen.WorkingArea;
				commonShellWindow.Top = workingArea.Top;
				commonShellWindow.Left = workingArea.Left;
				commonShellWindow.Width = workingArea.Width;
				commonShellWindow.Height = workingArea.Height;
			}
			else
			{
				if (preferredPosition.HasValue)
				{
					commonShellWindow.Left = preferredPosition.Value.X;
					commonShellWindow.Top = preferredPosition.Value.Y;
				}
				if (commonShellWindow.Left > (double)(virtualScreen.Left + virtualScreen.Width))
				{
					commonShellWindow.Left = (double)(virtualScreen.Left + virtualScreen.Width) - commonShellWindow.Width;
				}
				else if (commonShellWindow.Left + commonShellWindow.Width < (double)virtualScreen.Left)
				{
					commonShellWindow.Left = virtualScreen.Left;
				}
				if (commonShellWindow.Top > (double)(virtualScreen.Top + virtualScreen.Height))
				{
					commonShellWindow.Top = (double)(virtualScreen.Top + virtualScreen.Height) - commonShellWindow.Height;
				}
				else if (commonShellWindow.Top + commonShellWindow.Height < (double)virtualScreen.Top)
				{
					commonShellWindow.Top = virtualScreen.Top;
				}
			}
			_mainWindows.Add(shellMainWindow);
			commonShellWindow.Show();
			return shellMainWindow;
		}

		protected void AttachShellWindowEventHandlers(CommonShellWindow window)
		{
			if (window != null)
			{
				window.Closed += OnShellMainWindowClosed;
				window.Activated += OnShellMainWindowActivated;
			}
		}

		protected void DetachShellWindowEventHandlers(CommonShellWindow window)
		{
			if (window != null)
			{
				window.Closed -= OnShellMainWindowClosed;
				window.Activated -= OnShellMainWindowActivated;
			}
		}

		protected virtual void OnShellMainWindowActivated(object sender, EventArgs e)
		{
			ActiveWindow = sender as CommonShellWindow;
		}

		protected virtual void OnShellMainWindowClosed(object sender, EventArgs e)
		{
			if (sender is CommonShellWindow commonShellWindow)
			{
				DetachShellWindowEventHandlers(commonShellWindow);
				_mainWindows.Remove(commonShellWindow);
				commonShellWindow.Container.Dispose();
			}
		}

		public string SaveShellSettings()
		{
			CommonShellSettings commonShellSettings = SaveShellSettingsData();
			if (commonShellSettings == null)
			{
				return string.Empty;
			}
			return System.Windows.Markup.XamlWriter.Save(commonShellSettings);
		}

		public CommonShellSettings SaveShellSettingsData()
		{
			CommonShellSettings commonShellSettings = ConstructShellSettingsObject();
			if (commonShellSettings != null)
			{
				OnSaveShellSettings(commonShellSettings);
			}
			return commonShellSettings;
		}

		public void RestoreShellSettings(string settings)
		{
			CommonShellSettings commonShellSettings = null;
			try
			{
				using StringReader input = new StringReader(settings);
				commonShellSettings = System.Windows.Markup.XamlReader.Load(new XmlTextReader(input)) as CommonShellSettings;
			}
			catch (Exception)
			{
			}
			if (commonShellSettings != null)
			{
				RestoreShellSettings(commonShellSettings);
			}
		}

		protected virtual CommonShellSettings ConstructShellSettingsObject()
		{
			return new CommonShellSettings();
		}

		protected virtual void OnSaveShellSettings(CommonShellSettings settings)
		{
			if (settings != null)
			{
				if (ActiveWindow is CommonShellWindow commonShellWindow)
				{
					commonShellWindow.InternalSaveShellSettings(settings);
				}
				settings.SavedWorkspaces = RootWorkspaceFolder;
			}
		}

		public virtual void RestoreShellSettings(CommonShellSettings settings)
		{
			if (settings == null)
			{
				return;
			}
			if (settings.SavedWorkspaces != null)
			{
				RootWorkspaceFolder.Folders.Clear();
				foreach (ShellWorkspaceFolder folder in settings.SavedWorkspaces.Folders)
				{
					RootWorkspaceFolder.Folders.Add(folder);
				}
				RootWorkspaceFolder.Workspaces.Clear();
				foreach (ShellWorkspace workspace in settings.SavedWorkspaces.Workspaces)
				{
					RootWorkspaceFolder.Workspaces.Add(workspace);
				}
			}
			if (ActiveWindow is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.InternalRestoreShellSettings(settings);
			}
		}

		protected virtual void ConfigureWindowContainer(IUnityContainer windowContainer)
		{
		}
	}
	public class CommonShellAppResources : ResourceDictionary, IComponentConnector
	{
		private bool _contentLoaded;

		public CommonShellAppResources()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.CommonShell.Wpf;V31.0.0.5;component/commonshellappresources.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	public class CommonShellBootstrapper : UnityBootstrapper
	{
		private ILoggerFacade _logger;

		protected override ILoggerFacade LoggerFacade => _logger;

		public CommonShellBootstrapper()
		{
			_logger = new TraceLogger();
			InfragisticsResourceCustomizer.SetCustomizedStrings();
		}

		protected override void ConfigureContainer()
		{
			base.Container.AddNewExtension<RoutingEventAggregatorUnityExtension>();
			RegisterTypeIfMissing(typeof(ICommonShellViewRegistry), typeof(CommonShellViewRegistry), registerAsSingleton: true);
			RegisterTypeIfMissing(typeof(IEventAggregator), typeof(RoutingEventAggregator), registerAsSingleton: true);
			RegisterTypeIfMissing(typeof(IScreenFactoryCatalog), typeof(ScreenFactoryCatalog), registerAsSingleton: true);
			base.ConfigureContainer();
		}

		protected sealed override DependencyObject CreateShell()
		{
			return null;
		}

		protected override RegionAdapterMappings ConfigureRegionAdapterMappings()
		{
			return base.ConfigureRegionAdapterMappings();
		}

		public virtual void ShowMainWindow()
		{
			if (!base.Container.IsTypeRegistered(typeof(IShellApplication)))
			{
				throw new CommonShellException("The application has not registered its derivative of CommonShellApplication with the unity container");
			}
			base.Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ShowNewMainWindow();
		}
	}
	public class CommonShellContentHost : RibbonWindowContentHost
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<RibbonTabItem, bool> CachedCallback48_0;

			public static Func<RibbonGroup, bool> CachedCallback48_1;

			public static Func<RibbonGroup, bool> CachedCallback48_2;

			internal bool InjectCommonShellRibbonControlsCallback48_0(RibbonTabItem tab)
			{
				return tab.Name == "View";
			}

			internal bool InjectCommonShellRibbonControlsCallback48_1(RibbonGroup g)
			{
				return g.Id == "Layout";
			}

			internal bool InjectCommonShellRibbonControlsCallback48_2(RibbonGroup g)
			{
				return g.Id == "Window";
			}
		}

		[CompilerGenerated]
		private sealed class Capture50_0
		{
			public XamRibbon ribbon;

			internal void ribbon_LoadedCallback0()
			{
				FixupOffice2010QATStyle(ribbon);
			}
		}

		public static readonly DependencyProperty SuppressAllShellRibbonButtonsProperty = DependencyProperty.Register("SuppressAllShellRibbonButtons", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));

		public static readonly DependencyProperty SuppressAllShellRibbonAddInsProperty = DependencyProperty.Register("SuppressAllShellRibbonAddIns", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));

		public static readonly DependencyProperty SuppressWorkspaceButtonsProperty = DependencyProperty.Register("SuppressWorkspaceButtons", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));

		public static readonly DependencyProperty SuppressHelpButtonProperty = DependencyProperty.Register("SuppressHelpButton", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));

		public static readonly DependencyProperty SuppressCloseDocumentButtonProperty = DependencyProperty.Register("SuppressCloseDocumentButton", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));

		public static readonly DependencyProperty ContainerProperty = DependencyProperty.Register("Container", typeof(IUnityContainer), typeof(CommonShellContentHost), new PropertyMetadata(null, OnContainerPropertyChanged));

		private IShellApplication _shellApplication;

		protected static readonly DependencyPropertyKey NavigatorBarPropertyKey = DependencyProperty.RegisterReadOnly("NavigatorBar", typeof(NavigatorBar), typeof(CommonShellContentHost), new PropertyMetadata(null));

		public static readonly DependencyProperty NavigatorBarProperty = NavigatorBarPropertyKey.DependencyProperty;

		protected static readonly DependencyPropertyKey ScreenManagerPropertyKey = DependencyProperty.RegisterReadOnly("ScreenManager", typeof(ScreenManager), typeof(CommonShellContentHost), new PropertyMetadata(null));

		public static readonly DependencyProperty ScreenManagerProperty = ScreenManagerPropertyKey.DependencyProperty;

		protected static readonly DependencyProperty ActivationContentProperty = DependencyProperty.Register("ActivationContent", typeof(FrameworkElement), typeof(CommonShellContentHost), new PropertyMetadata(null));

		private bool _postTabItemContentAdded;

		private bool _commonShellRibbonControlsAdded;

		private bool _processedShellRibbonAddIns;

		internal SwitchLayoutTool SwitchLayoutTool;

		public bool SuppressAllShellRibbonButtons
		{
			get
			{
				return (bool)GetValue(SuppressAllShellRibbonButtonsProperty);
			}
			set
			{
				SetValue(SuppressAllShellRibbonButtonsProperty, value);
			}
		}

		public bool SuppressAllShellRibbonAddIns
		{
			get
			{
				return (bool)GetValue(SuppressAllShellRibbonAddInsProperty);
			}
			set
			{
				SetValue(SuppressAllShellRibbonAddInsProperty, value);
			}
		}

		public bool SuppressWorkspaceButtons
		{
			get
			{
				return (bool)GetValue(SuppressWorkspaceButtonsProperty);
			}
			set
			{
				SetValue(SuppressWorkspaceButtonsProperty, value);
			}
		}

		public bool SuppressHelpButton
		{
			get
			{
				return (bool)GetValue(SuppressHelpButtonProperty);
			}
			set
			{
				SetValue(SuppressHelpButtonProperty, value);
			}
		}

		public bool SuppressCloseDocumentButton
		{
			get
			{
				return (bool)GetValue(SuppressCloseDocumentButtonProperty);
			}
			set
			{
				SetValue(SuppressCloseDocumentButtonProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer Container
		{
			get
			{
				return GetValue(ContainerProperty) as IUnityContainer;
			}
			set
			{
				SetValue(ContainerProperty, value);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		[Microsoft.Practices.Unity.Dependency]
		public IShellApplication ShellApplication
		{
			get
			{
				return _shellApplication;
			}
			set
			{
				_ = _shellApplication;
				_shellApplication = value;
				_ = _shellApplication;
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public NavigatorBar NavigatorBar
		{
			get
			{
				return GetValue(NavigatorBarProperty) as NavigatorBar;
			}
			protected set
			{
				SetValue(NavigatorBarPropertyKey, value);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ScreenManager ScreenManager
		{
			get
			{
				return GetValue(ScreenManagerProperty) as ScreenManager;
			}
			protected set
			{
				SetValue(ScreenManagerPropertyKey, value);
			}
		}

		public FrameworkElement ActivationContent
		{
			get
			{
				return GetValue(ActivationContentProperty) as FrameworkElement;
			}
			set
			{
				SetValue(ActivationContentProperty, value);
			}
		}

		public CommonShellContentHost()
		{
			InitializeCommonShellContent();
			base.Loaded += CommonShellContentHost_Loaded;
		}

		private void CommonShellContentHost_Loaded(object sender, RoutedEventArgs e)
		{
			InjectCommonShellRibbonControls();
			AddContentFromShellRibbonAddIns();
			FixFileCaptionDisplayIssue();
			if (!InjectPostTabItemContent())
			{
				base.Dispatcher.BeginInvoke(new Func<bool>(InjectPostTabItemContent), DispatcherPriority.Normal);
			}
		}

		private void FixFileCaptionDisplayIssue()
		{
			if (base.Ribbon.Template.FindName("rootVisual", base.Ribbon) is Grid grid && grid.ColumnDefinitions.Count == 3)
			{
				grid.ColumnDefinitions[2].MaxWidth = 150.0;
			}
		}

		private static void OnContainerPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellContentHost commonShellContentHost)
			{
				commonShellContentHost.OnContainerChanged(args.OldValue as IUnityContainer, args.NewValue as IUnityContainer);
			}
		}

		protected virtual void OnContainerChanged(IUnityContainer oldValue, IUnityContainer newValue)
		{
			if (oldValue == null && newValue != null)
			{
				if (NavigatorBar != null)
				{
					newValue.BuildUp(NavigatorBar);
				}
				if (ScreenManager != null)
				{
					newValue.BuildUp(ScreenManager);
				}
			}
		}

		private void InitializeCommonShellContent()
		{
			if (base.Ribbon == null)
			{
				base.Ribbon = new XamRibbon();
			}
			if (NavigatorBar == null)
			{
				NavigatorBar = new NavigatorBar
				{
					Name = "PART_NavigatorBar"
				};
			}
			if (ScreenManager == null)
			{
				ScreenManager = new ScreenManager
				{
					Name = "PART_ScreenManager"
				};
			}
			ContentPresenter contentPresenter = new ContentPresenter();
			BindingOperations.SetBinding(contentPresenter, ContentPresenter.ContentProperty, new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath(ActivationContentProperty),
				Mode = BindingMode.OneWay
			});
			Grid element = new Grid
			{
				RowDefinitions = 
				{
					new RowDefinition
					{
						Height = new GridLength(1.0, GridUnitType.Auto)
					},
					new RowDefinition
					{
						Height = new GridLength(1.0, GridUnitType.Star)
					}
				},
				Children = 
				{
					(UIElement)contentPresenter,
					(UIElement)ScreenManager
				}
			};
			Grid.SetRow(contentPresenter, 0);
			Grid.SetRow(ScreenManager, 1);
			base.Content = new Grid
			{
				ColumnDefinitions = 
				{
					new ColumnDefinition
					{
						Width = new GridLength(1.0, GridUnitType.Auto)
					},
					new ColumnDefinition
					{
						Width = new GridLength(1.0, GridUnitType.Star)
					}
				},
				Children = 
				{
					(UIElement)element,
					(UIElement)NavigatorBar
				}
			};
			Grid.SetColumn(NavigatorBar, 0);
			Grid.SetColumn(element, 1);
			base.StatusBar = new System.Windows.Controls.Primitives.StatusBar();
			ScreenZoomControl content = new ScreenZoomControl
			{
				Name = "PART_ZoomControl"
			};
			StatusBarItem statusBarItem = new StatusBarItem
			{
				Name = "PART_StatusBar",
				Content = content
			};
			DockPanel.SetDock(statusBarItem, Dock.Right);
			base.StatusBar.Items.Add(statusBarItem);
			TextBlock textBlock = new TextBlock
			{
				Name = "PART_StatusText"
			};
			BindingOperations.SetBinding(textBlock, TextBlock.TextProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("StatusText"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(textBlock, TextBlock.ForegroundProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("StatusTextForeground"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(textBlock, TextBlock.BackgroundProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("StatusTextBackground"),
				Mode = BindingMode.OneWay
			});
			base.StatusBar.Items.Add(new StatusBarItem
			{
				Content = textBlock
			});
		}

		public void InjectCommonShellRibbonControls()
		{
			if (SuppressAllShellRibbonButtons || _commonShellRibbonControlsAdded)
			{
				return;
			}
			_commonShellRibbonControlsAdded = true;
			XamRibbon ribbon = base.Ribbon;
			if (ribbon == null)
			{
				return;
			}
			if (string.IsNullOrEmpty(ribbon.Theme))
			{
				ribbon.Theme = "Office2010Blue";
			}
			if (ribbon.ApplicationMenu != null && ribbon.ApplicationMenu.Image == null)
			{
				if (ribbon.Theme == "Scenic" || ribbon.Theme == "Office2010Blue")
				{
					ribbon.ApplicationMenu.Caption = CommonShellResources.FileMenuCaption;
				}
				else
				{
					ribbon.ApplicationMenu.Image = ImageResources.AspenLeafOfficeButton_32;
				}
			}
			if (ribbon.Resources == null)
			{
				ribbon.Resources = new ResourceDictionary();
			}
			if (!FixupOffice2010QATStyle(ribbon))
			{
				ribbon.Loaded += ribbon_Loaded;
			}
			RibbonTabItem ribbonTabItem = ribbon.Tabs.FirstOrDefault(CachedDelegates.CachedCallback48_0 ?? (CachedDelegates.CachedCallback48_0 = CachedDelegates.Instance.InjectCommonShellRibbonControlsCallback48_0));
			if (ribbonTabItem == null)
			{
				ribbonTabItem = new RibbonTabItem
				{
					Name = "View",
					Header = CommonShellResources.ViewRibbonTabCaption
				};
				ribbon.Tabs.Add(ribbonTabItem);
			}
			if (!SuppressWorkspaceButtons)
			{
				RibbonGroup ribbonGroup = ribbonTabItem.RibbonGroups.FirstOrDefault(CachedDelegates.CachedCallback48_1 ?? (CachedDelegates.CachedCallback48_1 = CachedDelegates.Instance.InjectCommonShellRibbonControlsCallback48_1));
				if (ribbonGroup == null)
				{
					ribbonGroup = new RibbonGroup
					{
						Id = "Layout",
						Caption = CommonShellResources.LayoutTabGroupCaption
					};
					ribbonTabItem.RibbonGroups.Add(ribbonGroup);
				}
				if (!SuppressWorkspaceButtons)
				{
					SaveLayoutTool saveLayoutTool = new SaveLayoutTool
					{
						Id = "Layout:SaveLayout",
						Name = "PART_SaveLayout"
					};
					RibbonGroup.SetMaximumSize(saveLayoutTool, RibbonToolSizingMode.ImageAndTextLarge);
					ribbonGroup.Items.Add(saveLayoutTool);
				}
				if (!SuppressWorkspaceButtons)
				{
					SwitchLayoutTool = new SwitchLayoutTool
					{
						Id = "Layout:SwitchLayout",
						Name = "PART_SwitchLayout"
					};
					RibbonGroup.SetMaximumSize(SwitchLayoutTool, RibbonToolSizingMode.ImageAndTextLarge);
					ribbonGroup.Items.Add(SwitchLayoutTool);
				}
				ribbonGroup.DialogBoxLauncherTool = new ManageSavedLayoutsTool
				{
					Id = "Layout:ManageLayout",
					Name = "PART_ManageLayout"
				};
			}
			RibbonGroup ribbonGroup2 = ribbonTabItem.RibbonGroups.FirstOrDefault(CachedDelegates.CachedCallback48_2 ?? (CachedDelegates.CachedCallback48_2 = CachedDelegates.Instance.InjectCommonShellRibbonControlsCallback48_2));
			if (ribbonGroup2 == null)
			{
				ribbonGroup2 = new RibbonGroup
				{
					Id = "Window",
					Caption = CommonShellResources.WindowTabGroupCaption
				};
				ribbonTabItem.RibbonGroups.Add(ribbonGroup2);
			}
			if (CommonShellPreferences.MultipleMainWindowsEnabled)
			{
				NewMainWindowTool newMainWindowTool = new NewMainWindowTool
				{
					Id = "Window:NewWindow",
					Name = "PART_NewWindowTool"
				};
				RibbonGroup.SetMaximumSize(newMainWindowTool, RibbonToolSizingMode.ImageAndTextLarge);
				ribbonGroup2.Items.Add(newMainWindowTool);
			}
			ToolHorizontalWrapPanel toolHorizontalWrapPanel = new ToolHorizontalWrapPanel();
			toolHorizontalWrapPanel.MinRows = 2;
			ribbonGroup2.Items.Add(toolHorizontalWrapPanel);
			ButtonGroup buttonGroup = new ButtonGroup();
			toolHorizontalWrapPanel.Children.Add(buttonGroup);
			ScreenNavigateBackwardTool screenNavigateBackwardTool = new ScreenNavigateBackwardTool
			{
				Id = "Window:NavigateBack",
				Name = "PART_NavigateBackwardTool"
			};
			RibbonGroup.SetMaximumSize(screenNavigateBackwardTool, RibbonToolSizingMode.ImageOnly);
			buttonGroup.Children.Add(screenNavigateBackwardTool);
			ScreenNavigateForwardTool screenNavigateForwardTool = new ScreenNavigateForwardTool
			{
				Id = "Window:NavigateForward",
				Name = "PART_NavigateForwardTool"
			};
			RibbonGroup.SetMaximumSize(screenNavigateForwardTool, RibbonToolSizingMode.ImageOnly);
			buttonGroup.Children.Add(screenNavigateForwardTool);
			ButtonGroup buttonGroup2 = new ButtonGroup();
			toolHorizontalWrapPanel.Children.Add(buttonGroup2);
			SynchronizeNavigationBarTool synchronizeNavigationBarTool = new SynchronizeNavigationBarTool
			{
				Id = "Window:SyncNavPane",
				Name = "PART_SyncNavPaneTool"
			};
			RibbonGroup.SetMaximumSize(synchronizeNavigationBarTool, RibbonToolSizingMode.ImageOnly);
			buttonGroup2.Children.Add(synchronizeNavigationBarTool);
			SwitchScreenTool switchScreenTool = new SwitchScreenTool
			{
				Id = "Window:SwitchScreen",
				Name = "PART_SwitchScreenTool"
			};
			RibbonGroup.SetMaximumSize(switchScreenTool, RibbonToolSizingMode.ImageOnly);
			buttonGroup2.Children.Add(switchScreenTool);
		}

		public virtual void AddContentFromShellRibbonAddIns()
		{
			if (SuppressAllShellRibbonAddIns || !(Window.GetWindow(this) is CommonShellWindow { Container: not null } commonShellWindow))
			{
				return;
			}
			XamRibbon ribbon = base.Ribbon;
			if (ribbon == null || _processedShellRibbonAddIns)
			{
				return;
			}
			_processedShellRibbonAddIns = true;
			foreach (IShellRibbonAddIn item in commonShellWindow.Container.ResolveAll<IShellRibbonAddIn>(Array.Empty<ResolverOverride>()))
			{
				try
				{
					item.AddContentToRibbon(commonShellWindow, ribbon);
				}
				catch (Exception)
				{
				}
			}
		}

		private void ribbon_Loaded(object sender, RoutedEventArgs e)
		{
			Capture50_0 Capture50Local = new Capture50_0();
			Capture50Local.ribbon = sender as XamRibbon;
			if (Capture50Local.ribbon != null)
			{
				if (FixupOffice2010QATStyle(Capture50Local.ribbon))
				{
					Capture50Local.ribbon.Loaded -= ribbon_Loaded;
				}
				else
				{
					base.Dispatcher.BeginInvoke(new Action(Capture50Local.ribbon_LoadedCallback0), DispatcherPriority.SystemIdle);
				}
			}
		}

		protected static bool FixupOffice2010QATStyle(XamRibbon ribbon)
		{
			if (ribbon == null)
			{
				return false;
			}
			if (!(Infragistics.Windows.Utilities.GetDescendantFromType(ribbon, typeof(QuickAccessToolbar), allowSubclassOfType: false) is QuickAccessToolbar parent))
			{
				return false;
			}
			Grid grid = Infragistics.Windows.Utilities.GetDescendantFromName(parent, "ToolsArea") as Grid;
			if (Infragistics.Windows.Utilities.GetDescendantFromName(parent, "PART_QuickAccessToolbarPanel") is QuickAccessToolbarPanel quickAccessToolbarPanel && grid != null)
			{
				grid.Effect = new DropShadowEffect
				{
					BlurRadius = 5.0,
					Color = Colors.White,
					ShadowDepth = 0.0,
					Opacity = 0.7
				};
				quickAccessToolbarPanel.Effect = new DropShadowEffect
				{
					BlurRadius = 5.0,
					Color = Colors.White,
					ShadowDepth = 0.0
				};
			}
			return true;
		}

		internal bool InjectPostTabItemContent()
		{
			if (_postTabItemContentAdded)
			{
				return true;
			}
			CommonShellWindow commonShellWindow = FindParentWindow();
			if (commonShellWindow == null)
			{
				return false;
			}
			XamRibbon ribbon = base.Ribbon;
			if (ribbon == null)
			{
				return false;
			}
			XamTabControl xamTabControl = (XamTabControl)AspenTech.Visualisation.Controls.Support.Utilities.GetDescendantFromType(ribbon, typeof(XamTabControl), allowSubclassOfType: true);
			if (xamTabControl == null)
			{
				return false;
			}
			_postTabItemContentAdded = true;
			StackPanel stackPanel = new StackPanel
			{
				Orientation = System.Windows.Controls.Orientation.Horizontal
			};
			ExpandCollapseRibbonTool element = new ExpandCollapseRibbonTool
			{
				Name = "PART_ExpandCollapseRibbon"
			};
			stackPanel.Children.Add(element);
			if (!SuppressHelpButton)
			{
				HelpButtonTool element2 = new HelpButtonTool
				{
					Name = "PART_HelpButton"
				};
				stackPanel.Children.Add(element2);
			}
			if (!SuppressCloseDocumentButton)
			{
				CloseDocumentTool element3 = new CloseDocumentTool
				{
					Name = "PART_CloseDocumentButton"
				};
				stackPanel.Children.Add(element3);
			}
			commonShellWindow.InternalCustomizeRibbonPostTabContent(stackPanel);
			xamTabControl.PostTabItemContent = stackPanel;
			return true;
		}

		private CommonShellWindow FindParentWindow()
		{
			CommonShellWindow commonShellWindow = null;
			for (FrameworkElement frameworkElement = base.Parent as FrameworkElement; frameworkElement != null; frameworkElement = frameworkElement.Parent as FrameworkElement)
			{
				commonShellWindow = frameworkElement as CommonShellWindow;
				if (commonShellWindow != null)
				{
					break;
				}
			}
			return commonShellWindow;
		}
	}
	public static class CommonShellModuleExtensions
	{
		private class InnerModuleInfoLoader : MarshalByRefObject
		{
			[CompilerGenerated]
			private sealed class Capture6_0
			{
				public InnerModuleInfoLoader owner;

				public DirectoryInfo directory;

				internal Assembly GetModuleInfosCallback0(object sender, ResolveEventArgs args)
				{
					return owner.OnReflectionOnlyResolve(args, directory);
				}
			}

			[Serializable]
			[CompilerGenerated]
			private sealed class CachedDelegates
			{
				public static readonly CachedDelegates Instance = new CachedDelegates();

				public static Func<Assembly, bool> CachedCallback6_1;

				public static Func<Type, bool> CachedCallback7_2;

				internal bool GetModuleInfosCallback6_1(Assembly asm)
				{
					return asm.FullName == typeof(IModule).Assembly.FullName;
				}

				internal bool GetNotAllreadyLoadedModuleInfosCallback7_2(Type t)
				{
					return !t.IsAbstract;
				}
			}

			[CompilerGenerated]
			private sealed class Capture7_0
			{
				public Type IModuleType;

				public Func<Type, bool> CachedCallback1;

				internal bool GetNotAllreadyLoadedModuleInfosCallback1(Type t)
				{
					return t != IModuleType;
				}
			}

			[CompilerGenerated]
			private sealed class Capture7_1
			{
				public FileInfo file;

				internal bool GetNotAllreadyLoadedModuleInfosCallback0(Assembly loadedAssembly)
				{
					return string.Equals(Path.GetFileName(loadedAssembly.Location), file.Name, StringComparison.OrdinalIgnoreCase);
				}
			}

			[CompilerGenerated]
			private sealed class ModuleInfoEnumerator : IEnumerable<ModuleInfo>, IEnumerable, IEnumerator<ModuleInfo>, IDisposable, IEnumerator
			{
				private int iteratorState;

				private ModuleInfo currentItem;

				private int initialThreadId;

				private Type IModuleType;

				public Type initialImoduletype;

				private DirectoryInfo directory;

				public DirectoryInfo initialDirectory;

				public InnerModuleInfoLoader owner;

				private Capture7_0 moduleTypeFilter;

				private Assembly[] loadedAssemblies;

				private FileInfo[] iteratorStorage2;

				private int iteratorStorage3;

				private IEnumerator<Type> iteratorStorage4;

				ModuleInfo IEnumerator<ModuleInfo>.Current
				{
					[DebuggerHidden]
					get
					{
						return currentItem;
					}
				}

				object IEnumerator.Current
				{
					[DebuggerHidden]
					get
					{
						return currentItem;
					}
				}

				[DebuggerHidden]
				public ModuleInfoEnumerator(int iteratorState)
				{
					this.iteratorState = iteratorState;
					initialThreadId = Environment.CurrentManagedThreadId;
				}

				[DebuggerHidden]
				void IDisposable.Dispose()
				{
					int num = iteratorState;
					if (num == -3 || num == 1)
					{
						try
						{
						}
						finally
						{
							DisposeRegion1();
						}
					}
				}

				bool IEnumerator.MoveNext()
				{
					bool completedNormally = false;
					try
					{
						int num = iteratorState;
						InnerModuleInfoLoader innerModuleInfoLoader = owner;
						if (num != 0)
						{
							if (num != 1)
							{
								completedNormally = true;
								return false;
							}
							iteratorState = -3;
							goto IL_020c;
						}
						iteratorState = -1;
						moduleTypeFilter = new Capture7_0();
						moduleTypeFilter.IModuleType = IModuleType;
						if (directory == null || !directory.Exists)
						{
							completedNormally = true;
							return false;
						}
						FileInfo[] files = directory.GetFiles("*.dll", SearchOption.TopDirectoryOnly);
						if (files == null || files.Length == 0)
						{
							completedNormally = true;
							return false;
						}
						loadedAssemblies = AppDomain.CurrentDomain.ReflectionOnlyGetAssemblies();
						iteratorStorage2 = files;
						iteratorStorage3 = 0;
						goto IL_0234;
						IL_0226:
						iteratorStorage3++;
						goto IL_0234;
						IL_0234:
						if (iteratorStorage3 < iteratorStorage2.Length)
						{
							Capture7_1 Capture7Local = new Capture7_1
							{
								file = iteratorStorage2[iteratorStorage3]
							};
							if (!(loadedAssemblies.FirstOrDefault(Capture7Local.GetNotAllreadyLoadedModuleInfosCallback0) != null) && (innerModuleInfoLoader.Filter == null || innerModuleInfoLoader.Filter(Capture7Local.file)))
							{
								Assembly assembly = null;
								try
								{
									assembly = Assembly.ReflectionOnlyLoadFrom(Capture7Local.file.FullName);
								}
								catch (Exception ex)
								{
									Trace.TraceWarning(string.Format(CultureInfo.CurrentCulture, "Exception while loading modules from assembly {0}: {1}", Capture7Local.file.FullName, ex.Message));
								}
								if (assembly != null)
								{
									iteratorStorage4 = assembly.GetExportedTypes().Where(moduleTypeFilter.IModuleType.IsAssignableFrom).Where(moduleTypeFilter.CachedCallback1 ?? (moduleTypeFilter.CachedCallback1 = moduleTypeFilter.GetNotAllreadyLoadedModuleInfosCallback1))
										.Where(CachedDelegates.CachedCallback7_2 ?? (CachedDelegates.CachedCallback7_2 = CachedDelegates.Instance.GetNotAllreadyLoadedModuleInfosCallback7_2))
										.GetEnumerator();
									iteratorState = -3;
									goto IL_020c;
								}
							}
							goto IL_0226;
						}
						iteratorStorage2 = null;
						completedNormally = true;
						return false;
						IL_020c:
						if (iteratorStorage4.MoveNext())
						{
							Type current = iteratorStorage4.Current;
							currentItem = CreateModuleInfo(current);
							iteratorState = 1;
							completedNormally = true;
							return true;
						}
						DisposeRegion1();
						iteratorStorage4 = null;
						goto IL_0226;
					}
					finally
					{
						// The original fault clause disposes the iterator on an exceptional exit.
						if (!completedNormally) ((IDisposable)this).Dispose();
					}
				}


				private void DisposeRegion1()
				{
					iteratorState = -1;
					if (iteratorStorage4 != null)
					{
						iteratorStorage4.Dispose();
					}
				}

				[DebuggerHidden]
				void IEnumerator.Reset()
				{
					throw new NotSupportedException();
				}

				[DebuggerHidden]
				IEnumerator<ModuleInfo> IEnumerable<ModuleInfo>.GetEnumerator()
				{
					ModuleInfoEnumerator enumerator;
					if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
					{
						iteratorState = 0;
						enumerator = this;
					}
					else
					{
						enumerator = new ModuleInfoEnumerator(0)
						{
							owner = owner
						};
					}
					enumerator.directory = initialDirectory;
					enumerator.IModuleType = initialImoduletype;
					return enumerator;
				}

				[DebuggerHidden]
				IEnumerator IEnumerable.GetEnumerator()
				{
					return ((IEnumerable<ModuleInfo>)this).GetEnumerator();
				}
			}

			[CompilerGenerated]
			private sealed class Capture8_0
			{
				public ResolveEventArgs args;

				internal bool OnReflectionOnlyResolveCallback0(Assembly asm)
				{
					return string.Equals(asm.FullName, args.Name, StringComparison.OrdinalIgnoreCase);
				}
			}

			public Func<FileInfo, bool> Filter { get; set; }

			public void Prepare()
			{
				Assembly[] assemblies = AppDomain.CurrentDomain.GetAssemblies();
				foreach (Assembly assembly in assemblies)
				{
					if (assembly is AssemblyBuilder)
					{
						continue;
					}
					string text = string.Empty;
					try
					{
						text = assembly.Location;
					}
					catch (Exception)
					{
					}
					if (!string.IsNullOrEmpty(text))
					{
						try
						{
							Assembly.ReflectionOnlyLoadFrom(text);
						}
						catch (Exception)
						{
						}
					}
				}
			}

			public ModuleInfo[] GetModuleInfos(string path)
			{
				Capture6_0 Capture6Local = new Capture6_0();
				Capture6Local.owner = this;
				ModuleInfo[] result = null;
				Capture6Local.directory = new DirectoryInfo(path);
				ResolveEventHandler value = Capture6Local.GetModuleInfosCallback0;
				AppDomain.CurrentDomain.ReflectionOnlyAssemblyResolve += value;
				try
				{
					Type type = AppDomain.CurrentDomain.ReflectionOnlyGetAssemblies().First(CachedDelegates.CachedCallback6_1 ?? (CachedDelegates.CachedCallback6_1 = CachedDelegates.Instance.GetModuleInfosCallback6_1)).GetType(typeof(IModule).FullName);
					IEnumerable<ModuleInfo> notAllreadyLoadedModuleInfos = GetNotAllreadyLoadedModuleInfos(Capture6Local.directory, type);
					if (notAllreadyLoadedModuleInfos != null)
					{
						result = notAllreadyLoadedModuleInfos.ToArray();
					}
				}
				finally
				{
					AppDomain.CurrentDomain.ReflectionOnlyAssemblyResolve -= value;
				}
				return result;
			}

			[IteratorStateMachine(typeof(ModuleInfoEnumerator))]
			private IEnumerable<ModuleInfo> GetNotAllreadyLoadedModuleInfos(DirectoryInfo directory, Type IModuleType)
			{
				return new ModuleInfoEnumerator(-2)
				{
					owner = this,
					initialDirectory = directory,
					initialImoduletype = IModuleType
				};
			}

			private Assembly OnReflectionOnlyResolve(ResolveEventArgs args, DirectoryInfo directory)
			{
				Capture8_0 Capture8Local = new Capture8_0();
				Capture8Local.args = args;
				Assembly assembly = AppDomain.CurrentDomain.ReflectionOnlyGetAssemblies().FirstOrDefault(Capture8Local.OnReflectionOnlyResolveCallback0);
				if (assembly != null)
				{
					return assembly;
				}
				AssemblyName assemblyName = new AssemblyName(Capture8Local.args.Name);
				string text = Path.Combine(directory.FullName, assemblyName.Name + ".dll");
				if (File.Exists(text))
				{
					return Assembly.ReflectionOnlyLoadFrom(text);
				}
				return Assembly.ReflectionOnlyLoad(Capture8Local.args.Name);
			}
		}

		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<Type, bool> CachedCallback0_0;

			public static Func<Type, bool> CachedCallback0_1;

			public static Func<Type, ModuleInfo> CachedCallback0_2;

			public static Func<CustomAttributeData, bool> CachedCallback1_0;

			public static Func<CustomAttributeData, bool> CachedCallback1_1;

			internal bool AddModulesFromAssemblyCallback0_0(Type t)
			{
				return t != typeof(IModule);
			}

			internal bool AddModulesFromAssemblyCallback0_1(Type t)
			{
				return !t.IsAbstract;
			}

			internal ModuleInfo AddModulesFromAssemblyCallback0_2(Type t)
			{
				return CreateModuleInfo(t);
			}

			internal bool CreateModuleInfoCallback1_0(CustomAttributeData cad)
			{
				return cad.Constructor.DeclaringType.FullName == typeof(ModuleAttribute).FullName;
			}

			internal bool CreateModuleInfoCallback1_1(CustomAttributeData cad)
			{
				return cad.Constructor.DeclaringType.FullName == typeof(ModuleDependencyAttribute).FullName;
			}
		}

		[CompilerGenerated]
		private sealed class Capture3_0
		{
			public IEnumerable<string> exclusions;

			internal bool AddModulesFromDirectoryCallback0(FileInfo file)
			{
				Capture3_1 Capture3Local = new Capture3_1
				{
					file = file
				};
				return exclusions.FirstOrDefault(Capture3Local.AddModulesFromDirectoryCallback1) == null;
			}
		}

		[CompilerGenerated]
		private sealed class Capture3_1
		{
			public FileInfo file;

			internal bool AddModulesFromDirectoryCallback1(string exclusion)
			{
				return string.Equals(exclusion, file.Name, StringComparison.OrdinalIgnoreCase);
			}
		}

		public static void AddModulesFromAssembly(this ModuleCatalog catalog, Assembly asm)
		{
			if (catalog == null || asm == null)
			{
				return;
			}
			foreach (ModuleInfo item in asm.GetExportedTypes().Where(typeof(IModule).IsAssignableFrom).Where(CachedDelegates.CachedCallback0_0 ?? (CachedDelegates.CachedCallback0_0 = CachedDelegates.Instance.AddModulesFromAssemblyCallback0_0))
				.Where(CachedDelegates.CachedCallback0_1 ?? (CachedDelegates.CachedCallback0_1 = CachedDelegates.Instance.AddModulesFromAssemblyCallback0_1))
				.Select(CachedDelegates.CachedCallback0_2 ?? (CachedDelegates.CachedCallback0_2 = CachedDelegates.Instance.AddModulesFromAssemblyCallback0_2)))
			{
				catalog.AddModule(item);
			}
		}

		public static ModuleInfo CreateModuleInfo(Type type)
		{
			if (type == null)
			{
				return null;
			}
			string name = type.Name;
			bool flag = false;
			CustomAttributeData customAttributeData = CustomAttributeData.GetCustomAttributes(type).FirstOrDefault(CachedDelegates.CachedCallback1_0 ?? (CachedDelegates.CachedCallback1_0 = CachedDelegates.Instance.CreateModuleInfoCallback1_0));
			if (customAttributeData != null)
			{
				foreach (CustomAttributeNamedArgument namedArgument in customAttributeData.NamedArguments)
				{
					switch (namedArgument.MemberInfo.Name)
					{
					case "ModuleName":
						name = (string)namedArgument.TypedValue.Value;
						break;
					case "OnDemand":
						flag = (bool)namedArgument.TypedValue.Value;
						break;
					case "StartupLoaded":
						flag = !(bool)namedArgument.TypedValue.Value;
						break;
					}
				}
			}
			ModuleInfo moduleInfo = new ModuleInfo(name, type.AssemblyQualifiedName)
			{
				InitializationMode = (flag ? InitializationMode.OnDemand : InitializationMode.WhenAvailable),
				Ref = type.Assembly.CodeBase
			};
			foreach (CustomAttributeData item in CustomAttributeData.GetCustomAttributes(type).Where(CachedDelegates.CachedCallback1_1 ?? (CachedDelegates.CachedCallback1_1 = CachedDelegates.Instance.CreateModuleInfoCallback1_1)))
			{
				moduleInfo.DependsOn.Add((string)item.ConstructorArguments[0].Value);
			}
			return moduleInfo;
		}

		public static void AddModulesFromDirectory(this ModuleCatalog catalog, string directory)
		{
			catalog.AddModulesFromDirectoryWithFilter(directory, null);
		}

		public static void AddModulesFromDirectory(this ModuleCatalog catalog, string directory, IEnumerable<string> exclusions)
		{
			Capture3_0 Capture3Local = new Capture3_0();
			Capture3Local.exclusions = exclusions;
			Func<FileInfo, bool> filter = Capture3Local.AddModulesFromDirectoryCallback0;
			catalog.AddModulesFromDirectoryWithFilter(directory, filter);
		}

		public static void AddModulesFromDirectoryWithFilter(this ModuleCatalog catalog, string directory, Func<FileInfo, bool> filter)
		{
			if (catalog == null || string.IsNullOrEmpty(directory))
			{
				return;
			}
			InnerModuleInfoLoader innerModuleInfoLoader = new InnerModuleInfoLoader();
			innerModuleInfoLoader.Filter = filter;
			innerModuleInfoLoader.Prepare();
			ModuleInfo[] moduleInfos = innerModuleInfoLoader.GetModuleInfos(directory);
			if (moduleInfos != null)
			{
				ModuleInfo[] array = moduleInfos;
				foreach (ModuleInfo moduleInfo in array)
				{
					catalog.AddModule(moduleInfo);
				}
			}
		}

		public static bool DefaultAssemblyInclusionFilter(FileInfo info)
		{
			if (info == null)
			{
				return false;
			}
			if (info.Name.StartsWith("Microsoft.Practices.", StringComparison.OrdinalIgnoreCase))
			{
				return false;
			}
			if (info.Name.StartsWith("InfragisticsWPF4.", StringComparison.OrdinalIgnoreCase))
			{
				return false;
			}
			if (info.Name.StartsWith("AspenTech.Visualisation.", StringComparison.OrdinalIgnoreCase) && !info.Name.StartsWith("AspenTech.Visualisation.CommonShell.CommonScreens", StringComparison.OrdinalIgnoreCase))
			{
				return false;
			}
			return true;
		}
	}
	public class CommonShellSettings
	{
		public ShellWorkspace CurrentWorkspace { get; set; }

		public ShellWorkspaceFolder SavedWorkspaces { get; set; }

		public ShellWorkspaceCollection NavigatorGroupWorkspaces { get; set; }

		public CommonShellSettings()
		{
			NavigatorGroupWorkspaces = new ShellWorkspaceCollection();
		}

		public bool ShouldSerializeCurrentWorkspace()
		{
			return CurrentWorkspace != null;
		}

		public bool ShouldSerializeSavedWorkspaces()
		{
			return SavedWorkspaces != null;
		}

		public bool ShouldSerializeNavigatorGroupWorkspaces()
		{
			if (NavigatorGroupWorkspaces != null)
			{
				return NavigatorGroupWorkspaces.Count > 0;
			}
			return false;
		}
	}
	internal class CommonShellViewRegistry : ICommonShellViewRegistry
	{
		[CompilerGenerated]
		private sealed class Capture1_0
		{
			public CommonShellViewRegistry owner;

			public Type navigationView;

			internal object RegisterViewWithRegionCallback0(IUnityContainer container)
			{
				return owner.CreateInstance(container, navigationView);
			}
		}

		private readonly ListDictionary<string, Func<IUnityContainer, object>> _registeredContent = new ListDictionary<string, Func<IUnityContainer, object>>();

		public void RegisterViewWithRegion(string region, Type navigationView)
		{
			Capture1_0 Capture1Local = new Capture1_0();
			Capture1Local.owner = this;
			Capture1Local.navigationView = navigationView;
			RegisterViewWithRegion(region, Capture1Local.RegisterViewWithRegionCallback0);
		}

		public void RegisterViewWithRegion(string region, Func<IUnityContainer, object> getContentDelegate)
		{
			_registeredContent.Add(region, getContentDelegate);
		}

		public IEnumerable<object> GetContents(IUnityContainer container, string region)
		{
			List<object> list = new List<object>();
			foreach (Func<IUnityContainer, object> item in _registeredContent[region])
			{
				list.Add(item(container));
			}
			return list;
		}

		protected virtual object CreateInstance(IUnityContainer container, Type type)
		{
			return container.Resolve(type);
		}
	}
	public class CommonShellWindow : XamRibbonWindow, IShellMainWindow, IWeakEventListener
	{
		public delegate bool ValidateLayoutNameDelegate(string name, ICollection<string> existingNames, bool canReplaceExisting, out string message);

		[CompilerGenerated]
		private sealed class Capture71_0
		{
			public CommonShellWindow owner;

			public UpdateStatusTextEventArgs args;

			internal void OnUpdateStatusTextEventCallback0()
			{
				owner.RefreshStatusText(args.Text, args.TextForeground, args.TextBackground, args.SuppressUIUpdate);
			}
		}

		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Action CachedCallback74_0;

			public static Func<ScreenContentControl, bool> CachedCallback159_0;

			public static Func<ScreenContentControl, bool> CachedCallback160_0;

			public static Func<ShellWorkspace, string> CachedCallback188_0;

			internal void RefreshStatusTextCallback74_0()
			{
			}

			internal bool CloseAllScreensCallback159_0(ScreenContentControl s)
			{
				return true;
			}

			internal bool ForceCloseAllScreensCallback160_0(ScreenContentControl s)
			{
				return true;
			}

			internal string ExecuteSaveScreenLayoutCommandCallback188_0(ShellWorkspace l)
			{
				return l.Name;
			}
		}

		[CompilerGenerated]
		private sealed class Capture144_0
		{
			public ShowScreenEventArgs args;

			public Func<ScreenContentControl, bool> CachedCallback2;

			internal bool ShowScreenCallback0(ScreenContentControl s)
			{
				return s.SatisfiesScreenRequirements(args.ScreenFactoryKey, args.ScreenSubject);
			}

			internal bool ShowScreenCallback1(ScreenContentControl s)
			{
				return s.SatisfiesScreenRequirements(args.ScreenFactoryKey, args.ScreenSubject);
			}

			internal bool ShowScreenCallback2(ScreenContentControl s)
			{
				return s.SatisfiesScreenRequirements(args.ScreenFactoryKey, args.ScreenSubject);
			}
		}

		[CompilerGenerated]
		private sealed class Capture188_0
		{
			public string layoutName;

			internal bool ExecuteSaveScreenLayoutCommandCallback1(ShellWorkspace l)
			{
				return string.Equals(l.Name, layoutName, StringComparison.CurrentCulture);
			}
		}

		[CompilerGenerated]
		private sealed class Capture197_0
		{
			public ShellWorkspace workspace;

			internal bool RestoreScreenLayoutFromWorkspaceCallback0(NavigatorView g)
			{
				return g.Key == workspace.NavigationGroupToSelect;
			}
		}

		[CompilerGenerated]
		private sealed class Capture251_0
		{
			public QatPlaceholderToolType? toolType;

			public string targetId;

			internal bool ApplySavedQATCustomizationCallback0(QatPlaceholderTool p)
			{
				if (p.TargetType == toolType.Value)
				{
					return string.Equals(p.TargetId, targetId, StringComparison.OrdinalIgnoreCase);
				}
				return false;
			}
		}

		[CompilerGenerated]
		private sealed class Capture260_0
		{
			public ShellWorkspace workspace;

			internal bool OnRestoreShellSettingsCallback0(NavigatorView g)
			{
				return string.Equals(g.Key, workspace.Name, StringComparison.Ordinal);
			}
		}

		public static readonly RoutedUICommand SynchronizeNavigationBarCommand;

		public static readonly RoutedUICommand NewWindowCommand;

		private bool _isFirstOnLoadCall = true;

		public static readonly DependencyProperty IsClosingProperty;

		public static readonly DependencyProperty IsClosedProperty;

		public static readonly DependencyProperty AutoSynchronizeNavigationBarProperty;

		protected static readonly DependencyProperty ShowSelectedScreenOnGroupChangeProperty;

		private bool _isFirstNavigationGroupSelection = true;

		private bool _synchronizingNavigationBarWithActiveScreen;

		public static readonly DependencyProperty ApplicationProperty;

		public static readonly DependencyProperty StatusTextForegroundProperty;

		public static readonly DependencyProperty StatusTextDefaultForegroundProperty;

		public static readonly DependencyProperty StatusTextBackgroundProperty;

		public static readonly DependencyProperty StatusTextDefaultBackgroundProperty;

		public static readonly DependencyProperty StatusTextProperty;

		public static readonly DependencyProperty CloseDocumentCommandProperty;

		public static readonly DependencyProperty CloseDocumentButtonVisibilityProperty;

		private IEventAggregator _eventAggregator;

		public static readonly DependencyProperty DefaultFloatingScreenSizeProperty;

		public static readonly DependencyProperty ZoomToFitDefaultVisibilityProperty;

		internal static readonly DependencyPropertyKey ActiveScreenPropertyKey;

		public static readonly DependencyProperty ActiveScreenProperty;

		internal static readonly DependencyPropertyKey ActiveDocumentScreenPropertyKey;

		public static readonly DependencyProperty ActiveDocumentScreenProperty;

		private static readonly DependencyPropertyKey ActiveBackwardNavigationHistoryPropertyKey;

		public static readonly DependencyProperty ActiveBackwardNavigationHistoryProperty;

		private static readonly DependencyPropertyKey ActiveForwardNavigationHistoryPropertyKey;

		public static readonly DependencyProperty ActiveForwardNavigationHistoryProperty;

		private bool _ignoreActiveScreenChange;

		private bool _ignoreActiveScreenChangeOnce;

		public static readonly DependencyProperty ContextualRibbonColorContrastSetProperty;

		private ContextualRibbonManager _ribbonManager;

		public static readonly DependencyProperty ContainerProperty;

		private ValidateLayoutNameDelegate _customValidateLayoutName;

		private ActionCommand _saveScreenLayoutCommand;

		private ActionCommand<object> _switchWorkspaceCommand;

		private ActionCommand<object> _manageSavedLayoutsCommand;

		private ActionCommand<object> _moveToNewWindowCommand;

		private ActionCommand<object> _moveToNextWindowCommand;

		private ActionCommand<object> _moveToPreviousWindowCommand;

		private ActionCommand _focusNextUISectionCommand;

		private ActionCommand _focusPreviousUISectionCommand;

		private MethodInfo _ribbonSetModeMethod;

		private object _ribbonSetModeParameter;

		private bool _ignoreRibbonQatChanges;

		public bool IsClosing
		{
			get
			{
				return (bool)GetValue(IsClosingProperty);
			}
			set
			{
				SetValue(IsClosingProperty, value);
			}
		}

		public bool IsClosed
		{
			get
			{
				return (bool)GetValue(IsClosedProperty);
			}
			set
			{
				SetValue(IsClosedProperty, value);
			}
		}

		public Action InitialScreenDisplayAction { get; set; }

		public bool AutoSynchronizeNavigationBar
		{
			get
			{
				return (bool)GetValue(AutoSynchronizeNavigationBarProperty);
			}
			set
			{
				SetValue(AutoSynchronizeNavigationBarProperty, value);
			}
		}

		public bool SynchronizingNavigationBarWithActiveScreen => _synchronizingNavigationBarWithActiveScreen;

		public bool? ShowSelectedScreenOnGroupChange
		{
			get
			{
				return (bool?)GetValue(ShowSelectedScreenOnGroupChangeProperty);
			}
			set
			{
				SetValue(ShowSelectedScreenOnGroupChangeProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IShellApplication Application
		{
			get
			{
				return GetValue(ApplicationProperty) as IShellApplication;
			}
			set
			{
				SetValue(ApplicationProperty, value);
			}
		}

		public System.Windows.Media.Brush StatusTextForeground
		{
			get
			{
				return GetValue(StatusTextForegroundProperty) as System.Windows.Media.Brush;
			}
			set
			{
				SetValue(StatusTextForegroundProperty, value);
			}
		}

		public System.Windows.Media.Brush StatusTextDefaultForeground
		{
			get
			{
				return GetValue(StatusTextDefaultForegroundProperty) as System.Windows.Media.Brush;
			}
			set
			{
				SetValue(StatusTextDefaultForegroundProperty, value);
			}
		}

		public System.Windows.Media.Brush StatusTextBackground
		{
			get
			{
				return GetValue(StatusTextBackgroundProperty) as System.Windows.Media.Brush;
			}
			set
			{
				SetValue(StatusTextBackgroundProperty, value);
			}
		}

		public System.Windows.Media.Brush StatusTextDefaultBackground
		{
			get
			{
				return GetValue(StatusTextDefaultBackgroundProperty) as System.Windows.Media.Brush;
			}
			set
			{
				SetValue(StatusTextDefaultBackgroundProperty, value);
			}
		}

		public string StatusText
		{
			get
			{
				return GetValue(StatusTextProperty) as string;
			}
			set
			{
				SetValue(StatusTextProperty, value);
			}
		}

		public ICommand CloseDocumentCommand
		{
			get
			{
				return GetValue(CloseDocumentCommandProperty) as ICommand;
			}
			set
			{
				SetValue(CloseDocumentCommandProperty, value);
			}
		}

		public Visibility CloseDocumentButtonVisibility
		{
			get
			{
				return (Visibility)GetValue(CloseDocumentButtonVisibilityProperty);
			}
			set
			{
				SetValue(CloseDocumentButtonVisibilityProperty, value);
			}
		}

		public CommonShellContentHost ContentHost
		{
			get
			{
				if (base.Content == null)
				{
					return null;
				}
				return (base.Content as CommonShellContentHost) ?? throw new CommonShellException("Content for CommonShellWindow must be a CommonShellContentHost");
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IEventAggregator EventAggregator
		{
			get
			{
				return _eventAggregator;
			}
			set
			{
				if (_eventAggregator != value)
				{
					IEventAggregator eventAggregator = _eventAggregator;
					_eventAggregator = value;
					OnEventAggregatorChanged(eventAggregator, value);
				}
			}
		}

		public System.Windows.Size DefaultFloatingScreenSize
		{
			get
			{
				return (System.Windows.Size)GetValue(DefaultFloatingScreenSizeProperty);
			}
			set
			{
				SetValue(DefaultFloatingScreenSizeProperty, value);
			}
		}

		public Visibility ZoomToFitDefaultVisibility
		{
			get
			{
				return (Visibility)GetValue(ZoomToFitDefaultVisibilityProperty);
			}
			set
			{
				SetValue(ZoomToFitDefaultVisibilityProperty, value);
			}
		}

		public ScreenContentControl ActiveScreen
		{
			get
			{
				return GetValue(ActiveScreenProperty) as ScreenContentControl;
			}
			private set
			{
				SetValue(ActiveScreenPropertyKey, value);
			}
		}

		public ScreenContentControl ActiveDocumentScreen
		{
			get
			{
				return GetValue(ActiveDocumentScreenProperty) as ScreenContentControl;
			}
			private set
			{
				SetValue(ActiveDocumentScreenPropertyKey, value);
			}
		}

		public ScreenNavigationHistoryCollection ActiveBackwardNavigationHistory
		{
			get
			{
				return GetValue(ActiveBackwardNavigationHistoryProperty) as ScreenNavigationHistoryCollection;
			}
			private set
			{
				SetValue(ActiveBackwardNavigationHistoryPropertyKey, value);
			}
		}

		public ScreenNavigationHistoryCollection ActiveForwardNavigationHistory
		{
			get
			{
				return GetValue(ActiveForwardNavigationHistoryProperty) as ScreenNavigationHistoryCollection;
			}
			private set
			{
				SetValue(ActiveForwardNavigationHistoryPropertyKey, value);
			}
		}

		public IColorContrastSet ContextualRibbonColorContrastSet
		{
			get
			{
				return GetValue(ContextualRibbonColorContrastSetProperty) as IColorContrastSet;
			}
			set
			{
				SetValue(ContextualRibbonColorContrastSetProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer Container
		{
			get
			{
				return GetValue(ContainerProperty) as IUnityContainer;
			}
			set
			{
				SetValue(ContainerProperty, value);
			}
		}

		public NavigatorBar NavigatorBar
		{
			get
			{
				if (ContentHost == null)
				{
					return null;
				}
				return ContentHost.NavigatorBar;
			}
		}

		public ScreenManager ScreenManager
		{
			get
			{
				if (ContentHost == null)
				{
					return null;
				}
				return ContentHost.ScreenManager;
			}
		}

		public XamRibbon Ribbon
		{
			get
			{
				if (ContentHost == null)
				{
					return null;
				}
				return ContentHost.Ribbon;
			}
		}

		public ValidateLayoutNameDelegate CustomValidateLayoutName
		{
			get
			{
				return _customValidateLayoutName;
			}
			set
			{
				_customValidateLayoutName = value;
			}
		}

		public ICommand SaveScreenLayoutCommand
		{
			get
			{
				if (_saveScreenLayoutCommand == null)
				{
					_saveScreenLayoutCommand = new ActionCommand(ExecuteSaveScreenLayoutCommand);
				}
				return _saveScreenLayoutCommand;
			}
		}

		public ICommand SwitchWorkspaceCommand
		{
			get
			{
				if (_switchWorkspaceCommand == null)
				{
					_switchWorkspaceCommand = new ActionCommand<object>(ExecuteSwitchWorkspaceCommand);
				}
				return _switchWorkspaceCommand;
			}
		}

		public ICommand ManageSavedLayoutsCommand
		{
			get
			{
				if (_manageSavedLayoutsCommand == null)
				{
					_manageSavedLayoutsCommand = new ActionCommand<object>(ExecuteManageSavedLayoutsCommand);
				}
				return _manageSavedLayoutsCommand;
			}
		}

		public ICommand MoveToNewWindowCommand
		{
			get
			{
				if (_moveToNewWindowCommand == null)
				{
					_moveToNewWindowCommand = new ActionCommand<object>(ExecuteMoveToNewWindowCommand);
				}
				return _moveToNewWindowCommand;
			}
		}

		public ICommand MoveToNextWindowCommand
		{
			get
			{
				if (_moveToNextWindowCommand == null)
				{
					_moveToNextWindowCommand = new ActionCommand<object>(ExecuteMoveToNextWindowCommand);
				}
				return _moveToNextWindowCommand;
			}
		}

		public ICommand MoveToPreviousWindowCommand
		{
			get
			{
				if (_moveToPreviousWindowCommand == null)
				{
					_moveToPreviousWindowCommand = new ActionCommand<object>(ExecuteMoveToPreviousWindowCommand);
				}
				return _moveToPreviousWindowCommand;
			}
		}

		public ICommand FocusNextUISectionCommand
		{
			get
			{
				if (_focusNextUISectionCommand == null)
				{
					_focusNextUISectionCommand = new ActionCommand(ExecuteFocusNextUISectionCommand);
				}
				return _focusNextUISectionCommand;
			}
		}

		public ICommand FocusPreviousUISectionCommand
		{
			get
			{
				if (_focusPreviousUISectionCommand == null)
				{
					_focusPreviousUISectionCommand = new ActionCommand(ExecuteFocusPreviousUISectionCommand);
				}
				return _focusPreviousUISectionCommand;
			}
		}

		protected bool IgnoreRibbonQATChanges
		{
			get
			{
				return _ignoreRibbonQatChanges;
			}
			set
			{
				_ignoreRibbonQatChanges = value;
			}
		}

		static CommonShellWindow()
		{
			SynchronizeNavigationBarCommand = new RoutedUICommand("Synchronize Navigation Bar", "SynchronizeNavigationBar", typeof(CommonShellWindow));
			NewWindowCommand = new RoutedUICommand("New Window", "New Window", typeof(CommonShellWindow));
			IsClosingProperty = DependencyProperty.Register("IsClosing", typeof(bool), typeof(CommonShellWindow), null);
			IsClosedProperty = DependencyProperty.Register("IsClosed", typeof(bool), typeof(CommonShellWindow), null);
			AutoSynchronizeNavigationBarProperty = DependencyProperty.Register("AutoSynchronizeNavigationBar", typeof(bool), typeof(CommonShellWindow), new PropertyMetadata(true));
			ShowSelectedScreenOnGroupChangeProperty = DependencyProperty.Register("ShowSelectedScreenOnGroupChange", typeof(bool?), typeof(CommonShellWindow), new FrameworkPropertyMetadata(null));
			ApplicationProperty = DependencyProperty.Register("Application", typeof(IShellApplication), typeof(CommonShellWindow), null);
			StatusTextForegroundProperty = DependencyProperty.Register("StatusTextForeground", typeof(System.Windows.Media.Brush), typeof(CommonShellWindow), new FrameworkPropertyMetadata(null));
			StatusTextDefaultForegroundProperty = DependencyProperty.Register("StatusTextDefaultForeground", typeof(System.Windows.Media.Brush), typeof(CommonShellWindow), new FrameworkPropertyMetadata(null, OnStatusTextDefaultForegroundPropertyChanged));
			StatusTextBackgroundProperty = DependencyProperty.Register("StatusTextBackground", typeof(System.Windows.Media.Brush), typeof(CommonShellWindow), new FrameworkPropertyMetadata(System.Windows.Media.Brushes.Transparent));
			StatusTextDefaultBackgroundProperty = DependencyProperty.Register("StatusTextDefaultBackground", typeof(System.Windows.Media.Brush), typeof(CommonShellWindow), new FrameworkPropertyMetadata(System.Windows.Media.Brushes.Transparent, OnStatusTextDefaultBackgroundPropertyChanged));
			StatusTextProperty = DependencyProperty.Register("StatusText", typeof(string), typeof(CommonShellWindow));
			CloseDocumentCommandProperty = DependencyProperty.Register("CloseDocumentCommand", typeof(ICommand), typeof(CommonShellWindow));
			CloseDocumentButtonVisibilityProperty = DependencyProperty.Register("CloseDocumentButtonVisibility", typeof(Visibility), typeof(CommonShellWindow), new PropertyMetadata(Visibility.Collapsed));
			DefaultFloatingScreenSizeProperty = DependencyProperty.Register("DefaultFloatingScreenSize", typeof(System.Windows.Size), typeof(CommonShellWindow), new PropertyMetadata(new System.Windows.Size(600.0, 400.0)));
			ZoomToFitDefaultVisibilityProperty = DependencyProperty.Register("ZoomToFitDefaultVisibility", typeof(Visibility), typeof(CommonShellWindow), new FrameworkPropertyMetadata(Visibility.Collapsed));
			ActiveScreenPropertyKey = DependencyProperty.RegisterReadOnly("ActiveScreen", typeof(ScreenContentControl), typeof(CommonShellWindow), new PropertyMetadata(null, OnActiveScreenPropertyChanged));
			ActiveScreenProperty = ActiveScreenPropertyKey.DependencyProperty;
			ActiveDocumentScreenPropertyKey = DependencyProperty.RegisterReadOnly("ActiveDocumentScreen", typeof(ScreenContentControl), typeof(CommonShellWindow), new PropertyMetadata(null, OnActiveDocumentScreenPropertyChanged));
			ActiveDocumentScreenProperty = ActiveDocumentScreenPropertyKey.DependencyProperty;
			ActiveBackwardNavigationHistoryPropertyKey = DependencyProperty.RegisterReadOnly("ActiveBackwardNavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(CommonShellWindow), new PropertyMetadata(null));
			ActiveBackwardNavigationHistoryProperty = ActiveBackwardNavigationHistoryPropertyKey.DependencyProperty;
			ActiveForwardNavigationHistoryPropertyKey = DependencyProperty.RegisterReadOnly("ActiveForwardNavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(CommonShellWindow), new PropertyMetadata(null));
			ActiveForwardNavigationHistoryProperty = ActiveForwardNavigationHistoryPropertyKey.DependencyProperty;
			ContextualRibbonColorContrastSetProperty = DependencyProperty.Register("ContextualRibbonColorContrastSet", typeof(IColorContrastSet), typeof(CommonShellContentHost));
			ContainerProperty = DependencyProperty.Register("Container", typeof(IUnityContainer), typeof(CommonShellWindow), new PropertyMetadata(null, OnContainerPropertyChanged));
			CommandManager.RegisterClassCommandBinding(typeof(CommonShellWindow), new CommandBinding(SynchronizeNavigationBarCommand, OnSynchronizeNavigationBarCommandExecuted, OnSynchronizeNavigationBarCommandCanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(CommonShellWindow), new CommandBinding(NewWindowCommand, OnNewWindowCommandExecuted, OnNewWindowCommandCanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(CommonShellWindow), new CommandBinding(ApplicationCommands.Help, OnShowHelpCommandExecuted, OnShowHelpCommandCanExecute));
		}

		public CommonShellWindow()
		{
			base.ResizeMode = ResizeMode.CanResizeWithGrip;
			if (base.Resources != null)
			{
				base.Resources = new ResourceDictionary();
			}
			base.Resources.MergedDictionaries.Add(new CommonShellWindowResourceDictionary());
			base.Loaded += OnLoaded;
			base.InputBindings.Add(new InputBinding(FocusNextUISectionCommand, new KeyGesture(Key.F6)));
			base.InputBindings.Add(new InputBinding(FocusPreviousUISectionCommand, new KeyGesture(Key.F6, ModifierKeys.Shift)));
		}

		protected override AutomationPeer OnCreateAutomationPeer()
		{
			return new CommonShellWindowAutomationPeer(this);
		}

		protected virtual void OnLoaded(object sender, RoutedEventArgs e)
		{
			if (_isFirstOnLoadCall)
			{
				_isFirstOnLoadCall = false;
				OnFirstLoad();
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			bool isClosing = IsClosing;
			try
			{
				base.OnClosing(e);
				if ((e != null && e.Cancel) || ScreenManager == null)
				{
					return;
				}
				foreach (ScreenContentControl item in ScreenManager.SelectScreens(null, includeInternal: true))
				{
					ScreenManager.OnScreenClosing(item, e);
					if (e != null && e.Cancel)
					{
						break;
					}
				}
			}
			finally
			{
				IsClosing = isClosing;
			}
		}

		protected override void OnClosed(EventArgs e)
		{
			IsClosed = true;
			base.OnClosed(e);
			if (ScreenManager == null)
			{
				return;
			}
			foreach (ScreenContentControl item in ScreenManager.SelectScreens(null, includeInternal: true))
			{
				ScreenManager.OnScreenClosed(item);
			}
		}

		protected virtual void OnFirstLoad()
		{
			InitializeNavigationBarViews();
			CommonShellContentHost contentHost = ContentHost;
			if (contentHost != null)
			{
				contentHost.InjectCommonShellRibbonControls();
				contentHost.InjectPostTabItemContent();
			}
			XamRibbon ribbon = Ribbon;
			if (ribbon != null)
			{
				INotifyCollectionChanged items = ribbon.QuickAccessToolbar.Items;
				if (items != null)
				{
					CollectionChangedEventManager.AddListener(items, this);
				}
				CommonShellApplication commonShellApplication = Application as CommonShellApplication;
				if (!string.IsNullOrEmpty(commonShellApplication.RibbonQATCustomization))
				{
					base.Dispatcher.BeginInvoke(new Action<string>(ApplySavedQATCustomization), DispatcherPriority.Background, commonShellApplication.RibbonQATCustomization);
				}
				if (commonShellApplication.RibbonQATLocationAboveRibbon.HasValue)
				{
					if (commonShellApplication.RibbonQATLocationAboveRibbon.Value)
					{
						ribbon.QuickAccessToolbarLocation = QuickAccessToolbarLocation.AboveRibbon;
					}
					else
					{
						ribbon.QuickAccessToolbarLocation = QuickAccessToolbarLocation.BelowRibbon;
					}
				}
			}
			if (InitialScreenDisplayAction != null)
			{
				InitialScreenDisplayAction();
			}
		}

		internal void InternalCustomizeRibbonPostTabContent(StackPanel panel)
		{
			CustomizeRibbonPostTabContent(panel);
		}

		protected virtual void CustomizeRibbonPostTabContent(StackPanel panel)
		{
		}

		protected virtual void InitializeNavigationBarViews()
		{
			foreach (object content in Container.Resolve<ICommonShellViewRegistry>(Array.Empty<ResolverOverride>()).GetContents(Container, CommonShellRegions.NavigatorRegion))
			{
				if (content is NavigatorView item)
				{
					NavigatorBar.NavigatorViews.Add(item);
				}
			}
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			(PresentationSource.FromVisual(this) as HwndSource).AddHook(WndProc);
		}

		private IntPtr WndProc(IntPtr hWnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
		{
			if (ActiveDocumentScreen != null && msg == 7)
			{
				XamRibbon xamRibbon = ((base.Content is CommonShellContentHost commonShellContentHost) ? commonShellContentHost.Ribbon : null);
				if (xamRibbon != null)
				{
					System.Windows.Point? trueMousePosition = AspenTech.Visualisation.CommonShell.Internal.NativeMethods.GetTrueMousePosition(xamRibbon);
					if (trueMousePosition.HasValue && trueMousePosition.Value.X >= 0.0 && trueMousePosition.Value.X <= xamRibbon.ActualWidth && trueMousePosition.Value.Y >= 0.0 && trueMousePosition.Value.Y <= xamRibbon.ActualHeight)
					{
						_ignoreActiveScreenChangeOnce = true;
					}
				}
			}
			return IntPtr.Zero;
		}

		public void SynchronizeNavigationBar()
		{
			NavigatorBar navigatorBar = NavigatorBar;
			if (navigatorBar != null)
			{
				bool synchronizingNavigationBarWithActiveScreen = _synchronizingNavigationBarWithActiveScreen;
				try
				{
					_synchronizingNavigationBarWithActiveScreen = true;
					navigatorBar.SyncWithScreen(ActiveDocumentScreen);
				}
				finally
				{
					_synchronizingNavigationBarWithActiveScreen = synchronizingNavigationBarWithActiveScreen;
				}
			}
		}

		public virtual bool CanSynchronizeNavigationBar()
		{
			ScreenContentControl activeDocumentScreen = ActiveDocumentScreen;
			if (activeDocumentScreen != null)
			{
				return !string.IsNullOrEmpty(activeDocumentScreen.NavigationGroupKey);
			}
			return false;
		}

		internal void NotifyOnSelectedNavigationGroupChanging(SelectedNavigationGroupChangingEventArgs eventArgs)
		{
			OnSelectedNavigationGroupChanging(eventArgs);
		}

		internal void NotifyOnSelectedNavigationGroupChanged(NavigatorView oldGroup, NavigatorView newGroup)
		{
			OnSelectedNavigationGroupChanged(oldGroup, newGroup);
		}

		protected virtual void OnSelectedNavigationGroupChanging(SelectedNavigationGroupChangingEventArgs eventArgs)
		{
		}

		protected virtual void OnSelectedNavigationGroupChanged(NavigatorView oldGroup, NavigatorView newGroup)
		{
			bool isFirstNavigationGroupSelection = _isFirstNavigationGroupSelection;
			_isFirstNavigationGroupSelection = false;
			if (_synchronizingNavigationBarWithActiveScreen || (isFirstNavigationGroupSelection && InitialScreenDisplayAction != null))
			{
				return;
			}
			switch (CommonShellPreferences.NavigationMode)
			{
			case ShellNavigationMode.MixedViews:
			case ShellNavigationMode.MixedViewsNoAutoOpen:
			{
				bool? flag = ShowSelectedScreenOnGroupChange;
				if (!flag.HasValue)
				{
					flag = CommonShellPreferences.NavigationMode != ShellNavigationMode.MixedViewsNoAutoOpen;
				}
				if (flag ?? true)
				{
					newGroup?.ShowCurrentScreen();
				}
				break;
			}
			case ShellNavigationMode.ExclusiveViews:
				if (oldGroup != null)
				{
					ShellWorkspace newWorkspace = GetNewWorkspace();
					SaveScreenLayoutToWorkspace(newWorkspace);
					OnScreenLayoutSaved(newWorkspace);
					newWorkspace.NavigationGroupToSelect = oldGroup.Key;
					oldGroup.DefaultWorkspace = newWorkspace;
				}
				if (newGroup != null)
				{
					ShellWorkspace defaultWorkspace = newGroup.DefaultWorkspace;
					if (defaultWorkspace != null)
					{
						RestoreScreenLayoutFromWorkspace(defaultWorkspace);
					}
					else
					{
						CloseAllScreens();
					}
				}
				break;
			}
		}

		private static void OnStatusTextDefaultForegroundPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.StatusTextForeground = args.NewValue as System.Windows.Media.Brush;
			}
		}

		private static void OnStatusTextDefaultBackgroundPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.StatusTextBackground = args.NewValue as System.Windows.Media.Brush;
			}
		}

		private void OnUpdateStatusTextEvent(UpdateStatusTextEventArgs args)
		{
			Capture71_0 Capture71Local = new Capture71_0();
			Capture71Local.owner = this;
			Capture71Local.args = args;
			if (Dispatcher.CurrentDispatcher != base.Dispatcher)
			{
				base.Dispatcher.Invoke(Capture71Local.OnUpdateStatusTextEventCallback0);
			}
			else
			{
				RefreshStatusText(Capture71Local.args.Text, Capture71Local.args.TextForeground, Capture71Local.args.TextBackground, Capture71Local.args.SuppressUIUpdate);
			}
		}

		public void RefreshStatusText(string text)
		{
			RefreshStatusText(text, null, null, suppressUIUpdate: false);
		}

		public void RefreshStatusText(string text, System.Windows.Media.Brush textForeground, System.Windows.Media.Brush textBackground)
		{
			RefreshStatusText(text, textForeground, textBackground, suppressUIUpdate: false);
		}

		public virtual void RefreshStatusText(string text, System.Windows.Media.Brush textForeground, System.Windows.Media.Brush textBackground, bool suppressUIUpdate)
		{
			if (textBackground == null)
			{
				textBackground = StatusTextDefaultBackground;
			}
			if (textForeground == null)
			{
				textForeground = StatusTextDefaultForeground;
			}
			if (textBackground == null || textForeground == null)
			{
				System.Windows.Controls.Primitives.StatusBar statusBar = ((base.Content is CommonShellContentHost commonShellContentHost) ? commonShellContentHost.StatusBar : null);
				if (statusBar != null)
				{
					if (textBackground == null)
					{
						textBackground = statusBar.Background;
					}
					if (textForeground == null)
					{
						textForeground = statusBar.Foreground;
					}
				}
			}
			StatusText = text;
			StatusTextForeground = textForeground;
			StatusTextBackground = textBackground;
			if (!suppressUIUpdate)
			{
				try
				{
					base.Dispatcher.Invoke(DispatcherPriority.Render, CachedDelegates.CachedCallback74_0 ?? (CachedDelegates.CachedCallback74_0 = CachedDelegates.Instance.RefreshStatusTextCallback74_0));
				}
				catch (InvalidOperationException)
				{
				}
			}
		}

		protected virtual void OnEventAggregatorChanged(IEventAggregator oldValue, IEventAggregator newValue)
		{
			if (oldValue != null)
			{
				oldValue.GetEvent<ShowScreenEvent>().Unsubscribe(ShowScreen);
				oldValue.GetEvent<UpdateStatusTextEvent>().Unsubscribe(OnUpdateStatusTextEvent);
			}
			if (newValue != null)
			{
				newValue.GetEvent<ShowScreenEvent>().Subscribe(ShowScreen);
				newValue.GetEvent<UpdateStatusTextEvent>().Subscribe(OnUpdateStatusTextEvent);
			}
		}

		private static void OnActiveScreenPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.OnActiveScreenChanged(args.OldValue as ScreenContentControl, args.NewValue as ScreenContentControl);
			}
		}

		protected virtual void OnActiveScreenChanged(ScreenContentControl oldScreen, ScreenContentControl newScreen)
		{
			if (EventAggregator != null)
			{
				EventAggregator.GetEvent<ActiveScreenChangedEvent>().Publish(new ActiveScreenChangedEventArgs
				{
					Screen = ActiveScreen
				});
			}
		}

		private static void OnActiveDocumentScreenPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.OnActiveDocumentScreenChanged(args.OldValue as ScreenContentControl, args.NewValue as ScreenContentControl);
			}
		}

		protected virtual void OnActiveDocumentScreenChanged(ScreenContentControl oldScreen, ScreenContentControl newScreen)
		{
			if (AutoSynchronizeNavigationBar)
			{
				SynchronizeNavigationBar();
			}
			UpdateScreenContextualRibbons();
			UpdateActiveNavigationHistory();
			if (EventAggregator != null)
			{
				EventAggregator.GetEvent<ActiveDocumentScreenChangedEvent>().Publish(new ActiveDocumentScreenChangedEventArgs
				{
					Screen = ActiveDocumentScreen
				});
			}
		}

		public void NavigateActiveHistoryBackward()
		{
			ScreenManager.NavigateBackward(ActiveDocumentScreen, null);
		}

		public void NavigateActiveHistoryBackward(ScreenNavigationHistoryItem item)
		{
			ScreenManager.NavigateBackward(ActiveDocumentScreen, item);
		}

		public void NavigateHistoryBackward(ScreenContentControl referenceScreen)
		{
			ScreenManager.NavigateBackward(referenceScreen, null);
		}

		public void NavigateHistoryBackward(ScreenContentControl referenceScreen, ScreenNavigationHistoryItem item)
		{
			ScreenManager.NavigateBackward(referenceScreen, item);
		}

		public void NavigateActiveHistoryForward()
		{
			ScreenManager.NavigateForward(ActiveDocumentScreen, null);
		}

		public void NavigateActiveHistoryForward(ScreenNavigationHistoryItem item)
		{
			ScreenManager.NavigateForward(ActiveDocumentScreen, item);
		}

		public void NavigateHistoryForward(ScreenContentControl referenceScreen)
		{
			ScreenManager.NavigateForward(referenceScreen, null);
		}

		public void NavigateHistoryForward(ScreenContentControl referenceScreen, ScreenNavigationHistoryItem item)
		{
			ScreenManager.NavigateForward(referenceScreen, item);
		}

		private void UpdateActiveNavigationHistory()
		{
			ScreenNavigationHistoryCollection forwardHistory = null;
			ScreenNavigationHistoryCollection backwardHistory = null;
			ScreenManager.GetNavigationHistoryFromScreen(ActiveDocumentScreen, out forwardHistory, out backwardHistory);
			if (forwardHistory != ActiveForwardNavigationHistory)
			{
				ActiveForwardNavigationHistory = forwardHistory;
			}
			if (backwardHistory != ActiveBackwardNavigationHistory)
			{
				ActiveBackwardNavigationHistory = backwardHistory;
			}
		}

		public void ForceRefreshActiveScreen()
		{
			_ignoreActiveScreenChange = false;
			RefreshActiveScreenProperties();
		}

		internal void RefreshActiveScreenProperties()
		{
			if (_ignoreActiveScreenChangeOnce)
			{
				_ignoreActiveScreenChangeOnce = false;
			}
			else if (!_ignoreActiveScreenChange)
			{
				ScreenContentControl screenContentControl = ScreenManager.FindActiveScreen(includeInternal: false);
				if (ActiveScreen != screenContentControl)
				{
					ActiveScreen = screenContentControl;
				}
				ScreenContentControl screenContentControl2 = ScreenManager.FindActiveDocumentScreen(includeInternal: false);
				if (ActiveDocumentScreen != screenContentControl2)
				{
					ActiveDocumentScreen = screenContentControl2;
				}
			}
		}

		private void UpdateScreenContextualRibbons()
		{
			ScreenContentControl activeDocumentScreen = ActiveDocumentScreen;
			if (activeDocumentScreen == null && _ribbonManager == null)
			{
				return;
			}
			if (_ribbonManager == null)
			{
				XamRibbon xamRibbon = ((base.Content is CommonShellContentHost commonShellContentHost) ? commonShellContentHost.Ribbon : null);
				if (xamRibbon != null)
				{
					_ribbonManager = new ContextualRibbonManager(xamRibbon, UpdateScreenContextualRibbonsCallback135_0);
				}
			}
			if (_ribbonManager != null)
			{
				_ribbonManager.ActiveScreen = activeDocumentScreen;
			}
		}

		protected virtual System.Windows.Media.Color GetContextualRibbonColor(string ribbonId)
		{
			if (ContextualRibbonColorContrastSet == null)
			{
				ColorContrastSetStrategy strategy = ColorContrastSetStrategy.NotBlackOrWhite | ColorContrastSetStrategy.NotGreyScale | ColorContrastSetStrategy.NotLight | ColorContrastSetStrategy.AlwaysAvoid | ColorContrastSetStrategy.HighContrast;
				List<System.Windows.Media.Color> list = new List<System.Windows.Media.Color>
				{
					Colors.Black,
					Colors.White
				};
				XamRibbon xamRibbon = ((base.Content is CommonShellContentHost commonShellContentHost) ? commonShellContentHost.Ribbon : null);
				if (xamRibbon != null)
				{
					SolidColorBrush solidColorBrush = xamRibbon.Background as SolidColorBrush;
					LinearGradientBrush linearGradientBrush = xamRibbon.Background as LinearGradientBrush;
					if (solidColorBrush != null)
					{
						list.Add(solidColorBrush.Color);
					}
					else if (linearGradientBrush != null)
					{
						foreach (GradientStop gradientStop in linearGradientBrush.GradientStops)
						{
							list.Add(gradientStop.Color);
						}
					}
				}
				ContextualRibbonColorContrastSet = new ColorContrastSet(strategy, list.ToArray());
			}
			return ContextualRibbonColorContrastSet.Find(ribbonId);
		}

		public void OpenNewScreenDocumentTab()
		{
			ScreenManager.OpenNewScreenDocumentTab();
		}

		public virtual ShowScreenEventArgs SelectContentForNewScreenTab(ScreenContentControl activeScreen)
		{
			return new ShowScreenEventArgs
			{
				ScreenFactoryKey = "EmptyScreen"
			};
		}

		public void ShowScreen(ShowScreenEventArgs args)
		{
			Capture144_0 Capture144Local = new Capture144_0();
			Capture144Local.args = args;
			if (Capture144Local.args == null)
			{
				return;
			}
			CommonShellWindow commonShellWindow = null;
			ScreenContentControl screenContentControl = null;
			switch (Capture144Local.args.ReuseExisting)
			{
			case ShowScreenReuseOptions.CurrentWindow:
				screenContentControl = FindScreen(Capture144Local.ShowScreenCallback0);
				break;
			case ShowScreenReuseOptions.AllWindows:
				screenContentControl = FindScreen(Capture144Local.ShowScreenCallback1);
				if (screenContentControl != null)
				{
					break;
				}
				foreach (IShellMainWindow mainWindow in Application.MainWindows)
				{
					if (mainWindow is CommonShellWindow commonShellWindow2)
					{
						screenContentControl = commonShellWindow2.FindScreen(Capture144Local.CachedCallback2 ?? (Capture144Local.CachedCallback2 = Capture144Local.ShowScreenCallback2));
						if (screenContentControl != null)
						{
							commonShellWindow = commonShellWindow2;
							break;
						}
					}
				}
				break;
			}
			if (screenContentControl != null)
			{
				if (commonShellWindow == null || commonShellWindow == this)
				{
					ActivateScreen(screenContentControl);
					return;
				}
				commonShellWindow.Activate();
				commonShellWindow.ActivateScreen(screenContentControl);
				return;
			}
			BeforeShowScreenEventArgs e = new BeforeShowScreenEventArgs
			{
				ShowScreenEvent = Capture144Local.args
			};
			EventAggregator.GetEvent<BeforeShowScreenEvent>().Publish(e);
			if (e.Cancel)
			{
				return;
			}
			if (Capture144Local.args.CreateNewWindow)
			{
				if (Application.ShowNewMainWindow() is CommonShellWindow { ScreenManager: not null } commonShellWindow3)
				{
					commonShellWindow3.ScreenManager.ShowScreen(Capture144Local.args);
				}
			}
			else
			{
				ScreenManager.ShowScreen(Capture144Local.args);
			}
		}

		public void ShowScreen(string screenFactoryKey)
		{
			ShowScreen(new ShowScreenEventArgs
			{
				ScreenFactoryKey = screenFactoryKey
			});
		}

		public void ShowScreen(string screenFactoryKey, ScreenSubject screenSubject)
		{
			ShowScreen(new ShowScreenEventArgs
			{
				ScreenFactoryKey = screenFactoryKey,
				ScreenSubject = screenSubject
			});
		}

		public void ActivateScreen(ScreenContentControl screen)
		{
			ScreenManager.ActivateScreen(screen);
		}

		public ScreenContentControl FindNamedPaneScreen(string name)
		{
			return ScreenManager.FindScreenByPaneName(name, includeInternal: false);
		}

		public ScreenContentControl FindScreen(Func<ScreenContentControl, bool> matchMethod)
		{
			return ScreenManager.FindScreen(matchMethod, includeInternal: false);
		}

		public IEnumerable<ScreenContentControl> SelectScreens(Func<ScreenContentControl, bool> filter)
		{
			return ScreenManager.SelectScreens(filter, includeInternal: false);
		}

		public void ForEachScreen(Action<ScreenContentControl> action)
		{
			ScreenManager.ForEachScreen(action, includeInternal: false);
		}

		public void CloseScreen(ScreenContentControl screen)
		{
			CloseScreen(screen, null);
		}

		public void CloseScreen(ScreenContentControl screen, CancelEventArgs cancelArgs)
		{
			ScreenManager.CloseScreen(screen, cancelArgs, forceClose: false);
		}

		public void ForceCloseScreen(ScreenContentControl screen)
		{
			ScreenManager.CloseScreen(screen, null, forceClose: true);
		}

		public void CloseScreens(Func<ScreenContentControl, bool> filter)
		{
			CloseScreens(filter, null);
		}

		public void CloseScreens(Func<ScreenContentControl, bool> filter, CancelEventArgs cancelArgs)
		{
			bool ignoreActiveScreenChange = _ignoreActiveScreenChange;
			try
			{
				_ignoreActiveScreenChange = true;
				ScreenManager.CloseScreens(filter, cancelArgs, forceClose: false, includeInternal: false);
			}
			finally
			{
				_ignoreActiveScreenChange = ignoreActiveScreenChange;
			}
			RefreshActiveScreenProperties();
		}

		public void ForceCloseScreens(Func<ScreenContentControl, bool> filter)
		{
			bool ignoreActiveScreenChange = _ignoreActiveScreenChange;
			try
			{
				_ignoreActiveScreenChange = true;
				ScreenManager.CloseScreens(filter, null, forceClose: true, includeInternal: false);
			}
			finally
			{
				_ignoreActiveScreenChange = ignoreActiveScreenChange;
			}
			RefreshActiveScreenProperties();
		}

		public void CloseAllScreens()
		{
			CloseAllScreens(null);
		}

		public void CloseAllScreens(CancelEventArgs cancelArgs)
		{
			CloseScreens(CachedDelegates.CachedCallback159_0 ?? (CachedDelegates.CachedCallback159_0 = CachedDelegates.Instance.CloseAllScreensCallback159_0), cancelArgs);
		}

		public void ForceCloseAllScreens()
		{
			ForceCloseScreens(CachedDelegates.CachedCallback160_0 ?? (CachedDelegates.CachedCallback160_0 = CachedDelegates.Instance.ForceCloseAllScreensCallback160_0));
		}

		public void CloseNamedPane(string name)
		{
			CloseNamedPane(name, null);
		}

		public void CloseNamedPane(string name, CancelEventArgs cancelArgs)
		{
			ScreenManager.CloseNamedPane(name, cancelArgs, forceClose: false);
		}

		public void ForceCloseNamedPane(string name)
		{
			ScreenManager.CloseNamedPane(name, null, forceClose: true);
		}

		protected virtual void OnScreenClosing(ScreenContentControl screen, CancelEventArgs args)
		{
			if (screen != null)
			{
				if (args == null)
				{
					args = new CancelEventArgs();
				}
				screen.RaiseClosing(args);
				if (!args.Cancel)
				{
					ScreenClosingEventArgs e = new ScreenClosingEventArgs
					{
						Screen = screen,
						Cancel = false
					};
					EventAggregator.GetEvent<ScreenClosingEvent>().Publish(e);
					args.Cancel = e.Cancel;
				}
			}
		}

		public void RaiseScreenClosing(ScreenContentControl screen, CancelEventArgs args)
		{
			OnScreenClosing(screen, args);
		}

		protected virtual void OnScreenClosed(ScreenContentControl screen)
		{
			if (screen != null)
			{
				screen.RaiseClosed(EventArgs.Empty);
				EventAggregator.GetEvent<ScreenClosedEvent>().Publish(new ScreenClosedEventArgs
				{
					Screen = screen
				});
				RefreshActiveScreenProperties();
			}
		}

		internal void RaiseScreenClosed(ScreenContentControl screen)
		{
			OnScreenClosed(screen);
		}

		private static void OnContainerPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.OnContainerChanged(args.OldValue as IUnityContainer, args.NewValue as IUnityContainer);
			}
		}

		protected virtual void OnContainerChanged(IUnityContainer oldValue, IUnityContainer newValue)
		{
			if (oldValue == null && newValue != null && ContentHost != null)
			{
				newValue.BuildUp(ContentHost);
			}
		}

		private void ExecuteSaveScreenLayoutCommand()
		{
			ShellWorkspaceCollection workspaces = Application.RootWorkspaceFolder.Workspaces;
			IEnumerable<string> source = workspaces.Select(CachedDelegates.CachedCallback188_0 ?? (CachedDelegates.CachedCallback188_0 = CachedDelegates.Instance.ExecuteSaveScreenLayoutCommandCallback188_0));
			SaveWorkspaceLayoutDialog saveWorkspaceLayoutDialog = new SaveWorkspaceLayoutDialog(this, source.ToList());
			if (saveWorkspaceLayoutDialog.ShowDialog() != true)
			{
				return;
			}
			try
			{
				Capture188_0 Capture188Local = new Capture188_0();
				bool overwriteExisting = false;
				Capture188Local.layoutName = saveWorkspaceLayoutDialog.ValidatedLayoutName(out overwriteExisting);
				ShellWorkspace shellWorkspace = null;
				bool flag = false;
				if (overwriteExisting)
				{
					shellWorkspace = workspaces.FirstOrDefault(Capture188Local.ExecuteSaveScreenLayoutCommandCallback1);
				}
				if (shellWorkspace == null)
				{
					shellWorkspace = GetNewWorkspace();
					shellWorkspace.Name = Capture188Local.layoutName;
					flag = true;
				}
				SaveScreenLayoutToWorkspace(shellWorkspace);
				if (flag)
				{
					workspaces.Add(shellWorkspace);
				}
				ContentHost.SwitchLayoutTool?.RefreshMenu();
				OnScreenLayoutSaved(shellWorkspace);
			}
			catch (Exception)
			{
			}
		}

		protected virtual void OnScreenLayoutSaved(ShellWorkspace layout)
		{
		}

		public void SaveScreenLayoutToWorkspace(ShellWorkspace workspace)
		{
			if (workspace == null)
			{
				throw new ArgumentNullException("workspace");
			}
			ScreenManager.SaveScreenLayoutToWorkspace(workspace);
			NavigatorBar navigatorBar = NavigatorBar;
			if (navigatorBar != null)
			{
				workspace.IsNavigationPaneMinimized = navigatorBar.IsMinimized;
			}
			XamRibbon ribbon = Ribbon;
			if (ribbon != null)
			{
				workspace.IsRibbonMinimized = ribbon.IsMinimized;
			}
			if (ActiveDocumentScreen != null)
			{
				workspace.NavigationGroupToSelect = ActiveDocumentScreen.NavigationGroupKey;
			}
			if (string.IsNullOrEmpty(workspace.NavigationGroupToSelect) && NavigatorBar != null && NavigatorBar.SelectedGroup != null)
			{
				workspace.NavigationGroupToSelect = NavigatorBar.SelectedGroup.Key;
			}
			if (ContentHost.ActivationContent is IWorkspacePersist workspacePersist)
			{
				workspace.ActivationBarState = workspacePersist.Save();
			}
		}

		private void ExecuteSwitchWorkspaceCommand(object arg)
		{
			if (arg is ShellWorkspace shellWorkspace)
			{
				ExecuteSwitchWorkspaceEventArgs e = new ExecuteSwitchWorkspaceEventArgs
				{
					NewWorkspace = shellWorkspace,
					IsCancellable = true
				};
				OnExecuteSwitchWorkspaceCommand(e);
				if (!e.Cancel)
				{
					RestoreScreenLayoutFromWorkspace(shellWorkspace);
				}
			}
		}

		protected virtual void OnExecuteSwitchWorkspaceCommand(ExecuteSwitchWorkspaceEventArgs args)
		{
			EventAggregator.GetEvent<ExecuteSwitchWorkspaceEvent>().Publish(args);
		}

		public void RestoreScreenLayoutFromWorkspace(ShellWorkspace workspace)
		{
			RestoreScreenLayoutFromWorkspace(workspace, null, forceClose: false);
		}

		public void RestoreScreenLayoutFromWorkspace(ShellWorkspace workspace, CancelEventArgs cancelArgs, bool forceClose)
		{
			Capture197_0 Capture197Local = new Capture197_0();
			Capture197Local.workspace = workspace;
			if (Capture197Local.workspace == null)
			{
				return;
			}
			if (cancelArgs == null)
			{
				cancelArgs = new CancelEventArgs();
			}
			RestoringScreenLayoutFromWorkspaceEventArgs e = new RestoringScreenLayoutFromWorkspaceEventArgs
			{
				Workspace = Capture197Local.workspace,
				IsCancellable = !forceClose
			};
			OnRestoringScreenLayoutFromWorkspace(e);
			if (!forceClose && e.Cancel)
			{
				cancelArgs.Cancel = true;
				return;
			}
			NavigatorView navigatorView = null;
			ShellWorkspace shellWorkspace = null;
			if (CommonShellPreferences.NavigationMode == ShellNavigationMode.ExclusiveViews)
			{
				navigatorView = NavigatorBar.SelectedGroup;
				if (navigatorView != null)
				{
					shellWorkspace = GetNewWorkspace();
					SaveScreenLayoutToWorkspace(shellWorkspace);
					OnScreenLayoutSaved(shellWorkspace);
				}
			}
			bool ignoreActiveScreenChange = _ignoreActiveScreenChange;
			try
			{
				_ignoreActiveScreenChange = true;
				ScreenManager.RestoreScreenLayoutFromWorkspace(Capture197Local.workspace, cancelArgs, forceClose);
			}
			finally
			{
				_ignoreActiveScreenChange = ignoreActiveScreenChange;
			}
			if (!forceClose && cancelArgs.Cancel)
			{
				return;
			}
			if (Capture197Local.workspace.IsRibbonMinimized.HasValue)
			{
				XamRibbon ribbon = Ribbon;
				if (ribbon != null)
				{
					ribbon.IsMinimized = Capture197Local.workspace.IsRibbonMinimized.Value;
				}
			}
			if (Capture197Local.workspace.IsNavigationPaneMinimized.HasValue)
			{
				NavigatorBar navigatorBar = NavigatorBar;
				if (navigatorBar != null)
				{
					navigatorBar.IsMinimized = Capture197Local.workspace.IsNavigationPaneMinimized.Value;
				}
			}
			NavigatorBar navigatorBar2 = NavigatorBar;
			if (navigatorBar2 != null && !string.IsNullOrEmpty(Capture197Local.workspace.NavigationGroupToSelect))
			{
				NavigatorView navigatorView2 = navigatorBar2.NavigatorViews.FirstOrDefault(Capture197Local.RestoreScreenLayoutFromWorkspaceCallback0);
				if (navigatorView2 != null && !navigatorView2.IsSelected)
				{
					bool synchronizingNavigationBarWithActiveScreen = _synchronizingNavigationBarWithActiveScreen;
					try
					{
						_synchronizingNavigationBarWithActiveScreen = true;
						navigatorView2.IsSelected = true;
					}
					finally
					{
						_synchronizingNavigationBarWithActiveScreen = synchronizingNavigationBarWithActiveScreen;
					}
				}
			}
			if (Capture197Local.workspace.ActivationBarState != null && ContentHost.ActivationContent is IWorkspacePersist workspacePersist)
			{
				workspacePersist.Restore(Capture197Local.workspace.ActivationBarState);
			}
			RefreshActiveScreenProperties();
			if (CommonShellPreferences.NavigationMode == ShellNavigationMode.ExclusiveViews && navigatorView != null && NavigatorBar.SelectedGroup != navigatorView)
			{
				navigatorView.DefaultWorkspace = shellWorkspace;
			}
			Rectangle virtualScreen = SystemInformation.VirtualScreen;
			Rect rect = new Rect(virtualScreen.Left, virtualScreen.Top, virtualScreen.Width, virtualScreen.Height);
			foreach (object ownedWindow in base.OwnedWindows)
			{
				if (ownedWindow is Window window && !new Rect(window.Left, window.Top, window.Width, window.Height).IntersectsWith(rect))
				{
					if (window.Left > (double)(virtualScreen.Left + virtualScreen.Width))
					{
						window.Left = (double)(virtualScreen.Left + virtualScreen.Width) - window.Width;
					}
					else if (window.Left + window.Width < (double)virtualScreen.Left)
					{
						window.Left = virtualScreen.Left;
					}
					if (window.Top > (double)(virtualScreen.Top + virtualScreen.Height))
					{
						window.Top = (double)(virtualScreen.Top + virtualScreen.Height) - window.Height;
					}
					else if (window.Top + window.Height < (double)virtualScreen.Top)
					{
						window.Top = virtualScreen.Top;
					}
				}
			}
		}

		protected virtual void OnRestoringScreenLayoutFromWorkspace(RestoringScreenLayoutFromWorkspaceEventArgs eventArgs)
		{
			EventAggregator.GetEvent<RestoringScreenLayoutFromWorkspaceEvent>().Publish(eventArgs);
		}

		private void ExecuteManageSavedLayoutsCommand(object arg)
		{
			ManageSavedLayoutsDialog manageSavedLayoutsDialog = new ManageSavedLayoutsDialog();
			manageSavedLayoutsDialog.Owner = this;
			manageSavedLayoutsDialog.ShellWindow = this;
			manageSavedLayoutsDialog.WindowStartupLocation = WindowStartupLocation.CenterOwner;
			manageSavedLayoutsDialog.ShowDialog();
		}

		internal void ScreenLayoutDeleted(ShellWorkspace layout)
		{
			ContentHost.SwitchLayoutTool?.RefreshMenu();
			OnScreenLayoutDeleted(layout);
		}

		protected virtual void OnScreenLayoutDeleted(ShellWorkspace layout)
		{
		}

		internal void ScreenLayoutRenamed(ShellWorkspace layout, string oldName)
		{
			ContentHost.SwitchLayoutTool?.RefreshMenu();
			OnScreenLayoutRenamed(layout, oldName);
		}

		protected virtual void OnScreenLayoutRenamed(ShellWorkspace layout, string oldName)
		{
		}

		private void ExecuteMoveToNewWindowCommand(object param)
		{
			ScreenContentControl screen = ((param != null) ? (param as ScreenContentControl) : ActiveDocumentScreen);
			MoveScreenToNewWindow(screen);
		}

		private void ExecuteMoveToNextWindowCommand(object param)
		{
			if (Application.MainWindows.Count < 2)
			{
				return;
			}
			ScreenContentControl screen = ((param != null) ? (param as ScreenContentControl) : ActiveDocumentScreen);
			int num = 0;
			using (IEnumerator<IShellMainWindow> enumerator = Application.MainWindows.GetEnumerator())
			{
				while (enumerator.MoveNext() && enumerator.Current != this)
				{
					num++;
				}
			}
			num = ((num < Application.MainWindows.Count - 1) ? (num + 1) : 0);
			IShellMainWindow shellMainWindow = Application.MainWindows[num];
			MoveScreenToWindow(screen, shellMainWindow as CommonShellWindow);
		}

		private void ExecuteMoveToPreviousWindowCommand(object param)
		{
			if (Application.MainWindows.Count < 2)
			{
				return;
			}
			ScreenContentControl screen = ((param != null) ? (param as ScreenContentControl) : ActiveDocumentScreen);
			int num = 0;
			using (IEnumerator<IShellMainWindow> enumerator = Application.MainWindows.GetEnumerator())
			{
				while (enumerator.MoveNext() && enumerator.Current != this)
				{
					num++;
				}
			}
			num = ((num != 0) ? (num - 1) : (Application.MainWindows.Count - 1));
			IShellMainWindow shellMainWindow = Application.MainWindows[num];
			MoveScreenToWindow(screen, shellMainWindow as CommonShellWindow);
		}

		public void MoveScreenToNewWindow(ScreenContentControl screen)
		{
			MoveScreenToNewWindow(screen, null);
		}

		public void MoveScreenToNewWindow(ScreenContentControl screen, ScreenLocation? defaultLocation)
		{
			if (screen != null && Application.ShowNewMainWindow() is CommonShellWindow window)
			{
				MoveScreenToWindow(screen, window, defaultLocation);
			}
		}

		public void MoveScreenToWindow(ScreenContentControl screen, CommonShellWindow window, ScreenLocation? defaultLocation = null)
		{
			if (screen != null && window != null)
			{
				string paneName = string.Empty;
				ContentPane contentPane = ScreenManager.FindContentPaneForScreen(screen);
				if (contentPane != null && !ScreenManager.IsAnonymousPane(contentPane))
				{
					paneName = contentPane.Name;
				}
				ScreenManager.DetachScreen(screen);
				window.ScreenManager.ReshowScreen(screen, paneName, defaultLocation.GetValueOrDefault(), null);
			}
		}

		public void MoveScreen(ScreenContentControl screen, ScreenLocation screenLocation)
		{
			MoveScreen(screen, screenLocation, null);
		}

		public void MoveScreen(ScreenContentControl screen, ScreenLocation screenLocation, System.Windows.Size? preferredSize)
		{
			ScreenManager.MoveScreen(screen, screenLocation, preferredSize);
		}

		protected void ExecuteFocusNextUISectionCommand()
		{
			FocusNextUISection(reverseDirection: false);
		}

		protected virtual void ExecuteFocusPreviousUISectionCommand()
		{
			FocusNextUISection(reverseDirection: true);
		}

		protected virtual void FocusNextUISection(bool reverseDirection)
		{
			List<KeyValuePair<FrameworkElement, Action>> list = new List<KeyValuePair<FrameworkElement, Action>>
			{
				new KeyValuePair<FrameworkElement, Action>(NavigatorBar, FocusNextUISectionCallback232_0),
				new KeyValuePair<FrameworkElement, Action>(ScreenManager, FocusNextUISectionCallback232_1),
				new KeyValuePair<FrameworkElement, Action>(Ribbon, FocusNextUISectionCallback232_2)
			};
			int num = 0;
			for (int i = 0; i < list.Count; i++)
			{
				if (list[i].Key != null && list[i].Key.IsKeyboardFocusWithin)
				{
					num = i;
					break;
				}
			}
			for (int j = 0; j < list.Count - 1; j++)
			{
				int num2 = num;
				if (reverseDirection)
				{
					num2 -= j + 1;
					if (num2 < 0)
					{
						num2 += list.Count;
					}
				}
				else
				{
					num2 += j + 1;
					if (num2 >= list.Count)
					{
						num2 -= list.Count;
					}
				}
				KeyValuePair<FrameworkElement, Action> keyValuePair = list[num2];
				if (keyValuePair.Key != null && keyValuePair.Key.IsVisible)
				{
					keyValuePair.Value();
					break;
				}
			}
		}

		protected void FocusOnScreenManager()
		{
			if (ScreenManager != null)
			{
				ScreenManager.FocusOnActiveElement();
			}
		}

		protected void FocusOnNavigatorBar()
		{
			if (NavigatorBar != null)
			{
				NavigatorBar.FocusOnActiveElement();
			}
		}

		protected void FocusOnRibbon()
		{
			XamRibbon ribbon = Ribbon;
			if (ribbon == null)
			{
				return;
			}
			if (_ribbonSetModeMethod == null)
			{
				try
				{
					MethodInfo[] methods = ribbon.GetType().GetMethods(BindingFlags.Instance | BindingFlags.NonPublic);
					foreach (MethodInfo methodInfo in methods)
					{
						if (!(methodInfo.Name == "SetMode"))
						{
							continue;
						}
						ParameterInfo[] parameters = methodInfo.GetParameters();
						if (parameters != null && parameters.Length == 1 && parameters[0].ParameterType.IsEnum)
						{
							object obj = Enum.Parse(parameters[0].ParameterType, "KeyTipsActive");
							if (obj != null)
							{
								_ribbonSetModeMethod = methodInfo;
								_ribbonSetModeParameter = obj;
								break;
							}
						}
					}
				}
				catch (Exception)
				{
				}
			}
			if (!(_ribbonSetModeMethod != null))
			{
				return;
			}
			try
			{
				_ribbonSetModeMethod.Invoke(ribbon, new object[1] { _ribbonSetModeParameter });
			}
			catch (Exception)
			{
			}
		}

		public void NavigateTo(string navigationGroup, string navigationPath, ShowScreenOptions options)
		{
			NavigatorBar.NavigateTo(navigationGroup, navigationPath, options);
		}

		private static void OnSynchronizeNavigationBarCommandExecuted(object sender, ExecutedRoutedEventArgs args)
		{
			if (sender is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.SynchronizeNavigationBar();
			}
		}

		private static void OnSynchronizeNavigationBarCommandCanExecute(object sender, CanExecuteRoutedEventArgs args)
		{
			args.CanExecute = (sender as CommonShellWindow)?.CanSynchronizeNavigationBar() ?? false;
		}

		private static void OnNewWindowCommandExecuted(object sender, ExecutedRoutedEventArgs args)
		{
			(sender as CommonShellWindow).Container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ShowNewMainWindow();
		}

		private static void OnNewWindowCommandCanExecute(object sender, CanExecuteRoutedEventArgs args)
		{
			args.CanExecute = true;
		}

		private static void OnShowHelpCommandExecuted(object sender, ExecutedRoutedEventArgs args)
		{
			(sender as CommonShellWindow).ExecuteShowHelp();
		}

		private static void OnShowHelpCommandCanExecute(object sender, CanExecuteRoutedEventArgs args)
		{
			CommonShellWindow commonShellWindow = sender as CommonShellWindow;
			args.CanExecute = commonShellWindow.CanExecuteShowHelp();
		}

		public virtual void ExecuteShowHelp()
		{
		}

		public virtual bool CanExecuteShowHelp()
		{
			return true;
		}

		internal void OpenNavigatorViewInNewTab(NavigatorView view)
		{
			if (view != null)
			{
				ScreenManager.OpenNewScreenDocumentTab();
				view.IsSelected = true;
				view.ShowCurrentScreen();
			}
		}

		internal void OpenNavigatorViewInNewWindow(NavigatorView view)
		{
			if (view == null || !(Application.ShowNewMainWindow() is CommonShellWindow commonShellWindow))
			{
				return;
			}
			foreach (NavigatorView navigatorView in commonShellWindow.NavigatorBar.NavigatorViews)
			{
				if (string.Equals(navigatorView.Key, view.Key, StringComparison.Ordinal))
				{
					navigatorView.IsSelected = true;
					navigatorView.ShowCurrentScreen();
					break;
				}
			}
		}

		protected virtual void SaveQATCustomization()
		{
			if (Application is CommonShellApplication commonShellApplication)
			{
				commonShellApplication.RibbonQATCustomization = SerializeQATCustomization();
			}
		}

		protected virtual string SerializeQATCustomization()
		{
			XamRibbon ribbon = Ribbon;
			if (ribbon == null)
			{
				return string.Empty;
			}
			StringBuilder stringBuilder = new StringBuilder();
			foreach (object item in (IEnumerable)ribbon.QuickAccessToolbar.Items)
			{
				if (!(item is QatPlaceholderTool qatPlaceholderTool))
				{
					continue;
				}
				if (qatPlaceholderTool.TargetType == QatPlaceholderToolType.Tool)
				{
					string ribbonToolId = GetRibbonToolId(qatPlaceholderTool.Target as IRibbonTool);
					if (!string.IsNullOrEmpty(ribbonToolId))
					{
						if (stringBuilder.Length > 0)
						{
							stringBuilder.Append('|');
						}
						stringBuilder.Append("tool=");
						stringBuilder.Append(ribbonToolId);
					}
					continue;
				}
				string ribbonGroupId = GetRibbonGroupId(qatPlaceholderTool.Target as RibbonGroup);
				if (!string.IsNullOrEmpty(ribbonGroupId))
				{
					if (stringBuilder.Length > 0)
					{
						stringBuilder.Append('|');
					}
					stringBuilder.Append("group=");
					stringBuilder.Append(ribbonGroupId);
				}
			}
			return stringBuilder.ToString();
		}

		protected virtual void ApplySavedQATCustomization(string serializedQAT)
		{
			if (string.IsNullOrEmpty(serializedQAT))
			{
				return;
			}
			XamRibbon ribbon = Ribbon;
			if (ribbon == null)
			{
				return;
			}
			bool ignoreRibbonQATChanges = IgnoreRibbonQATChanges;
			try
			{
				IgnoreRibbonQATChanges = true;
				List<QatPlaceholderTool> list = new List<QatPlaceholderTool>();
				foreach (object item in (IEnumerable)ribbon.QuickAccessToolbar.Items)
				{
					if (item is QatPlaceholderTool qatPlaceholderTool && !string.IsNullOrEmpty(qatPlaceholderTool.TargetId))
					{
						list.Add(qatPlaceholderTool);
					}
				}
				foreach (QatPlaceholderTool item2 in list)
				{
					ribbon.QuickAccessToolbar.Items.Remove(item2);
				}
				string[] array = serializedQAT.Split('|');
				foreach (string text in array)
				{
					Capture251_0 Capture251Local = new Capture251_0();
					Capture251Local.targetId = string.Empty;
					Capture251Local.toolType = null;
					if (text.StartsWith("tool=", StringComparison.OrdinalIgnoreCase))
					{
						Capture251Local.targetId = text.Substring("tool=".Length);
						Capture251Local.toolType = QatPlaceholderToolType.Tool;
					}
					else if (text.StartsWith("group=", StringComparison.OrdinalIgnoreCase))
					{
						Capture251Local.targetId = text.Substring("group=".Length);
						Capture251Local.toolType = QatPlaceholderToolType.RibbonGroup;
					}
					if (Capture251Local.toolType.HasValue)
					{
						QatPlaceholderTool qatPlaceholderTool2 = list.FirstOrDefault(Capture251Local.ApplySavedQATCustomizationCallback0);
						if (qatPlaceholderTool2 == null)
						{
							qatPlaceholderTool2 = ((Capture251Local.toolType.Value != QatPlaceholderToolType.Tool) ? GetQATToolPlaceholderFromGroupId(Capture251Local.targetId) : GetQATToolPlaceholderFromToolId(Capture251Local.targetId));
						}
						if (qatPlaceholderTool2 != null)
						{
							ribbon.QuickAccessToolbar.Items.Add(qatPlaceholderTool2);
						}
					}
				}
			}
			finally
			{
				IgnoreRibbonQATChanges = ignoreRibbonQATChanges;
			}
		}

		protected virtual QatPlaceholderTool GetQATToolPlaceholderFromGroupId(string groupId)
		{
			XamRibbon ribbon = Ribbon;
			if (ribbon == null)
			{
				return null;
			}
			foreach (RibbonTabItem tab in ribbon.Tabs)
			{
				foreach (RibbonGroup ribbonGroup in tab.RibbonGroups)
				{
					string ribbonGroupId = GetRibbonGroupId(ribbonGroup);
					if (string.Equals(ribbonGroupId, groupId))
					{
						return new QatPlaceholderTool(ribbonGroupId, QatPlaceholderToolType.RibbonGroup);
					}
				}
			}
			foreach (ContextualTabGroup contextualTabGroup in ribbon.ContextualTabGroups)
			{
				foreach (RibbonTabItem tab2 in contextualTabGroup.Tabs)
				{
					foreach (RibbonGroup ribbonGroup2 in tab2.RibbonGroups)
					{
						if (string.Equals(ribbonGroup2.Id, groupId))
						{
							return new QatPlaceholderTool(ribbonGroup2.Id, QatPlaceholderToolType.RibbonGroup);
						}
					}
				}
			}
			return null;
		}

		protected virtual QatPlaceholderTool GetQATToolPlaceholderFromToolId(string toolId)
		{
			XamRibbon ribbon = Ribbon;
			if (ribbon == null)
			{
				return null;
			}
			if (ribbon.ApplicationMenu != null && FindRibbonToolWithId(ribbon.ApplicationMenu, toolId) != null)
			{
				return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
			}
			if (ribbon.ApplicationMenu2010 != null && FindRibbonToolWithId(ribbon.ApplicationMenu2010, toolId) != null)
			{
				return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
			}
			foreach (RibbonTabItem tab in ribbon.Tabs)
			{
				foreach (RibbonGroup ribbonGroup in tab.RibbonGroups)
				{
					foreach (object item in (IEnumerable)ribbonGroup.Items)
					{
						if (FindRibbonToolWithId(item, toolId) != null)
						{
							return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
						}
					}
					if (ribbonGroup.DialogBoxLauncherTool != null && FindRibbonToolWithId(ribbonGroup.DialogBoxLauncherTool, toolId) != null)
					{
						return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
					}
				}
			}
			foreach (ContextualTabGroup contextualTabGroup in ribbon.ContextualTabGroups)
			{
				foreach (RibbonTabItem tab2 in contextualTabGroup.Tabs)
				{
					foreach (RibbonGroup ribbonGroup2 in tab2.RibbonGroups)
					{
						foreach (object item2 in (IEnumerable)ribbonGroup2.Items)
						{
							if (FindRibbonToolWithId(item2, toolId) != null)
							{
								return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
							}
						}
						if (ribbonGroup2.DialogBoxLauncherTool != null && FindRibbonToolWithId(ribbonGroup2.DialogBoxLauncherTool, toolId) != null)
						{
							return new QatPlaceholderTool(toolId, QatPlaceholderToolType.Tool);
						}
					}
				}
			}
			return null;
		}

		protected IRibbonTool FindRibbonToolWithId(object scope, string id)
		{
			if (scope is IRibbonTool ribbonTool)
			{
				string ribbonToolId = GetRibbonToolId(ribbonTool);
				if (string.Equals(id, ribbonToolId, StringComparison.OrdinalIgnoreCase))
				{
					return ribbonTool;
				}
			}
			if (scope is ItemsControl itemsControl)
			{
				foreach (object item in (IEnumerable)itemsControl.Items)
				{
					IRibbonTool ribbonTool2 = FindRibbonToolWithId(item, id);
					if (ribbonTool2 != null)
					{
						return ribbonTool2;
					}
				}
			}
			if (scope is System.Windows.Controls.Panel { Children: not null } panel)
			{
				foreach (object child in panel.Children)
				{
					IRibbonTool ribbonTool2 = FindRibbonToolWithId(child, id);
					if (ribbonTool2 != null)
					{
						return ribbonTool2;
					}
				}
			}
			return null;
		}

		protected virtual string GetRibbonGroupId(RibbonGroup group)
		{
			if (group == null)
			{
				return string.Empty;
			}
			return group.Id;
		}

		protected virtual string GetRibbonToolId(IRibbonTool tool)
		{
			if (tool == null)
			{
				return string.Empty;
			}
			if (tool is ButtonTool buttonTool)
			{
				return buttonTool.Id;
			}
			if (tool is ToggleButtonTool toggleButtonTool)
			{
				return toggleButtonTool.Id;
			}
			if (tool is RadioButtonTool radioButtonTool)
			{
				return radioButtonTool.Id;
			}
			if (tool is CheckBoxTool checkBoxTool)
			{
				return checkBoxTool.Id;
			}
			if (tool is TextEditorTool textEditorTool)
			{
				return textEditorTool.Id;
			}
			if (tool is MaskedEditorTool maskedEditorTool)
			{
				return maskedEditorTool.Id;
			}
			if (tool is ComboEditorTool comboEditorTool)
			{
				return comboEditorTool.Id;
			}
			if (tool is MenuTool menuTool)
			{
				return menuTool.Id;
			}
			return string.Empty;
		}

		internal void InternalSaveShellSettings(CommonShellSettings settings)
		{
			OnSaveShellSettings(settings);
		}

		internal void InternalRestoreShellSettings(CommonShellSettings settings)
		{
			OnRestoreShellSettings(settings);
		}

		protected virtual void OnSaveShellSettings(CommonShellSettings settings)
		{
			if (settings == null)
			{
				return;
			}
			ShellWorkspace newWorkspace = GetNewWorkspace();
			SaveScreenLayoutToWorkspace(newWorkspace);
			OnScreenLayoutSaved(newWorkspace);
			settings.CurrentWorkspace = newWorkspace;
			if (CommonShellPreferences.NavigationMode != ShellNavigationMode.ExclusiveViews)
			{
				return;
			}
			foreach (NavigatorView navigatorView in NavigatorBar.NavigatorViews)
			{
				if (navigatorView.DefaultWorkspace != null && !string.IsNullOrEmpty(navigatorView.Key) && navigatorView != NavigatorBar.SelectedGroup)
				{
					if (settings.NavigatorGroupWorkspaces == null)
					{
						settings.NavigatorGroupWorkspaces = new ShellWorkspaceCollection();
					}
					ShellWorkspace shellWorkspace = navigatorView.DefaultWorkspace.DeepCopy();
					shellWorkspace.Name = navigatorView.Key;
					settings.NavigatorGroupWorkspaces.Add(shellWorkspace);
				}
			}
		}

		protected void OnRestoreShellSettings(CommonShellSettings settings)
		{
			if (settings == null)
			{
				return;
			}
			if (settings.NavigatorGroupWorkspaces != null)
			{
				using IEnumerator<ShellWorkspace> enumerator = settings.NavigatorGroupWorkspaces.GetEnumerator();
				while (enumerator.MoveNext())
				{
					Capture260_0 Capture260Local = new Capture260_0();
					Capture260Local.workspace = enumerator.Current;
					NavigatorView navigatorView = NavigatorBar.NavigatorViews.FirstOrDefault(Capture260Local.OnRestoreShellSettingsCallback0);
					if (navigatorView != null)
					{
						navigatorView.DefaultWorkspace = Capture260Local.workspace;
					}
				}
			}
			if (settings.CurrentWorkspace != null)
			{
				RestoreScreenLayoutFromWorkspace(settings.CurrentWorkspace);
			}
		}

		protected virtual ShellWorkspace GetNewWorkspace()
		{
			return new ShellWorkspace();
		}

		public virtual bool ReceiveWeakEvent(Type managerType, object sender, EventArgs e)
		{
			bool result = false;
			if (managerType == typeof(CollectionChangedEventManager))
			{
				if (!IgnoreRibbonQATChanges)
				{
					XamRibbon ribbon = Ribbon;
					if (ribbon != null && sender == ribbon.QuickAccessToolbar.Items)
					{
						SaveQATCustomization();
					}
				}
				result = true;
			}
			return result;
		}

		[CompilerGenerated]
		private System.Windows.Media.Color UpdateScreenContextualRibbonsCallback135_0(string caption)
		{
			return GetContextualRibbonColor(caption);
		}

		[CompilerGenerated]
		private void FocusNextUISectionCallback232_0()
		{
			FocusOnNavigatorBar();
		}

		[CompilerGenerated]
		private void FocusNextUISectionCallback232_1()
		{
			FocusOnScreenManager();
		}

		[CompilerGenerated]
		private void FocusNextUISectionCallback232_2()
		{
			FocusOnRibbon();
		}
	}
	public class CommonShellWindowResourceDictionary : ResourceDictionary, IComponentConnector
	{
		private bool _contentLoaded;

		public CommonShellWindowResourceDictionary()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.CommonShell.Wpf;V31.0.0.5;component/commonshellwindowresourcedictionary.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	public class EmptyScreenContentControl : ScreenContentControl
	{
		public static string FactoryKey => "EmptyScreen";

		public EmptyScreenContentControl()
		{
			base.Header = CommonShellResources.EmptyScreenContent_Header;
		}
	}
	public class RestoredScreenPlaceholder : ScreenContentControl
	{
		public static string FactoryKey => "RestoredScreenPlaceholder";

		public RestoredScreenPlaceholder()
		{
			base.Header = CommonShellResources.RestoredScreen_Header;
		}
	}
	public class ClosedScreenPlaceholder : ScreenContentControl
	{
		public static string FactoryKey => "ClosedScreenPlaceholder";

		public ClosedScreenPlaceholder()
		{
			base.Header = "Closed Screen";
			base.ScreenFactoryKey = FactoryKey;
		}
	}
	public static class ImageResources
	{
		private static readonly string ThisAssemblyName = Assembly.GetAssembly(typeof(ImageResources)).FullName;

		private static readonly Dictionary<string, ImageSource> _imageSources = new Dictionary<string, ImageSource>();

		public static ImageSource AspenLeafOfficeButton_32 => GetImageSource("AspenLeafOfficeButton_32.png");

		public static ImageSource NavigationSync_32 => GetImageSource("NavigationSync_32.png");

		public static ImageSource NavigationSync_16 => GetImageSource("NavigationSync_16.png");

		public static ImageSource NavigateForward_32 => GetImageSource("NavigateForward_32.png");

		public static ImageSource NavigateForward_16 => GetImageSource("NavigateForward_16.png");

		public static ImageSource NavigateBackward_32 => GetImageSource("NavigateBackward_32.png");

		public static ImageSource NavigateBackward_16 => GetImageSource("NavigateBackward_16.png");

		public static ImageSource ScreenLayoutSave_32 => GetImageSource("ScreenLayoutSave_32.png");

		public static ImageSource ScreenLayoutSave_16 => GetImageSource("ScreenLayoutSave_16.png");

		public static ImageSource ScreenLayoutSwitch_32 => GetImageSource("ScreenLayoutSwitch_32.png");

		public static ImageSource ScreenLayoutSwitch_16 => GetImageSource("ScreenLayoutSwitch_16.png");

		public static ImageSource ScreenSwitch_32 => GetImageSource("ScreenSwitch_32.png");

		public static ImageSource ScreenSwitch_16 => GetImageSource("ScreenSwitch_16.png");

		public static ImageSource WindowNew_32 => GetImageSource("WindowNew_32.png");

		public static ImageSource WindowNew_16 => GetImageSource("WindowNew_16.png");

		public static ImageSource Help_16 => GetImageSource("Help_16.png");

		public static ImageSource Zoom_16 => GetImageSource("Zoom_16.png");

		public static ImageSource Zoom_32 => GetImageSource("Zoom_32.png");

		public static ImageSource ZoomIn_32 => GetImageSource("ZoomIn_32.png");

		public static ImageSource ZoomIn_16 => GetImageSource("ZoomIn_16.png");

		public static ImageSource ZoomOut_16 => GetImageSource("ZoomOut_16.png");

		public static ImageSource ZoomOut_32 => GetImageSource("ZoomOut_32.png");

		public static ImageSource Zoom100Pct_16 => GetImageSource("Zoom100Pct_16.png");

		public static ImageSource Zoom100Pct_32 => GetImageSource("Zoom100Pct_32.png");

		public static ImageSource ZoomToFit_16 => GetImageSource("ZoomToFit_16.png");

		public static ImageSource ZoomToFit_32 => GetImageSource("ZoomToFit_32.png");

		public static ImageSource ZoomSliderZoomToFit_16 => GetImageSource("ZoomSliderZoomToFit_16.png");

		public static ImageSource RibbonCollapse_16 => GetImageSource("RibbonCollapse_16.png");

		public static ImageSource RibbonExpand_16 => GetImageSource("RibbonExpand_16.png");

		public static ImageSource RibbonCloseDocument_16 => GetImageSource("RibbonCloseDocument_16.png");

		public static ImageSource ManageLayouts_16 => GetImageSource("ManageLayouts_16.png");

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
	public static class InfragisticsResourceCustomizer
	{
		public static void SetCustomizedStrings()
		{
			SetDockManagerStrings();
			SetOutlookBarStrings();
			SetRibbonStrings();
		}

		public static void SetDockManagerStrings()
		{
			ResourceCustomizer customizer = Infragistics.Windows.DockManager.Resources.Customizer;
			customizer.SetCustomizedString("CloseAllButThisPaneMenuItem", CommonShellResources.IgDockManager_CloseAllButThisPaneMenuItem);
			customizer.SetCustomizedString("CloseButtonToolTip", CommonShellResources.IgDockManager_CloseButtonToolTip);
			customizer.SetCustomizedString("ClosePaneMenuItem", CommonShellResources.IgDockManager_ClosePaneMenuItem);
			customizer.SetCustomizedString("DockablePaneMenuItem", CommonShellResources.IgDockManager_DockablePaneMenuItem);
			customizer.SetCustomizedString("DocumentFilesMenuToolTip", CommonShellResources.IgDockManager_DocumentFilesMenuToolTip);
			customizer.SetCustomizedString("DocumentPaneMenuItem", CommonShellResources.IgDockManager_DocumentPaneMenuItem);
			customizer.SetCustomizedString("DocumentShowNavigatorToolTip", CommonShellResources.IgDockManager_DocumentShowNavigatorToolTip);
			customizer.SetCustomizedString("FloatingPaneMenuItem", CommonShellResources.IgDockManager_FloatingPaneMenuItem);
			customizer.SetCustomizedString("HidePaneMenuItem", CommonShellResources.IgDockManager_HidePaneMenuItem);
			customizer.SetCustomizedString("MoveToNewHorizontalGroupPaneMenuItem", CommonShellResources.IgDockManager_MoveToNewHorizontalGroupPaneMenuItem);
			customizer.SetCustomizedString("MoveToNewVerticalGroupPaneMenuItem", CommonShellResources.IgDockManager_MoveToNewVerticalGroupPaneMenuItem);
			customizer.SetCustomizedString("MoveToNextGroupPaneMenuItem", CommonShellResources.IgDockManager_MoveToNextGroupPaneMenuItem);
			customizer.SetCustomizedString("MoveToPreviousGroupPaneMenuItem", CommonShellResources.IgDockManager_MoveToPreviousGroupPaneMenuItem);
			customizer.SetCustomizedString("PaneNavigatorActiveFilesLabel", CommonShellResources.IgDockManager_PaneNavigatorActiveFilesLabel);
			customizer.SetCustomizedString("PaneNavigatorActiveToolWindowsLabel", CommonShellResources.IgDockManager_PaneNavigatorActiveToolWindowsLabel);
			customizer.SetCustomizedString("PinButtonToolTip", CommonShellResources.IgDockManager_PinButtonToolTip);
			customizer.SetCustomizedString("PinPaneMenuItem", CommonShellResources.IgDockManager_PinPaneMenuItem);
			customizer.SetCustomizedString("PositionMenuToolTip", CommonShellResources.IgDockManager_PositionMenuToolTip);
		}

		public static void SetOutlookBarStrings()
		{
			ResourceCustomizer customizer = Infragistics.Windows.OutlookBar.Resources.Customizer;
			customizer.SetCustomizedString("AddOrRemoveButtonsMenuItemHeader", CommonShellResources.IgOutlookBar_AddOrRemoveButtonsMenuItemHeader);
			customizer.SetCustomizedString("MinimizeButtonExpandTooltip", CommonShellResources.IgOutlookBar_MinimizeButtonExpandTooltip);
			customizer.SetCustomizedString("MinimizeButtonMinimizeTooltip", CommonShellResources.IgOutlookBar_MinimizeButtonMinimizeTooltip);
			customizer.SetCustomizedString("NavigationAreaOptionsMenuItemHeader", CommonShellResources.IgOutlookBar_NavigationAreaOptionsMenuItemHeader);
			customizer.SetCustomizedString("NavigationPaneMinimizedText", CommonShellResources.IgOutlookBar_NavigationPaneMinimizedText);
			customizer.SetCustomizedString("NavigationPaneMinimizedTooltip", CommonShellResources.IgOutlookBar_NavigationPaneMinimizedTooltip);
			customizer.SetCustomizedString("NavigationPaneOptionsControlCancelButton", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlCancelButton);
			customizer.SetCustomizedString("NavigationPaneOptionsControlMoveDownButton", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlMoveDownButton);
			customizer.SetCustomizedString("NavigationPaneOptionsControlMoveUpButton", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlMoveUpButton);
			customizer.SetCustomizedString("NavigationPaneOptionsControlOkButton", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlOkButton);
			customizer.SetCustomizedString("NavigationPaneOptionsControlOrderLabel", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlOrderLabel);
			customizer.SetCustomizedString("NavigationPaneOptionsControlResetButton", CommonShellResources.IgOutlookBar_NavigationPaneOptionsControlResetButton);
			customizer.SetCustomizedString("NavigationPaneOptionsDialogTitle", CommonShellResources.IgOutlookBar_NavigationPaneOptionsDialogTitle);
			customizer.SetCustomizedString("OverflowMenuButtonTooltip", CommonShellResources.IgOutlookBar_OverflowMenuButtonTooltip);
			customizer.SetCustomizedString("ShowFewerButtonsMenuItemHeader", CommonShellResources.IgOutlookBar_ShowFewerButtonsMenuItemHeader);
			customizer.SetCustomizedString("ShowMoreButtonsMenuItemHeader", CommonShellResources.IgOutlookBar_ShowMoreButtonsMenuItemHeader);
		}

		public static void SetRibbonStrings()
		{
			ResourceCustomizer customizer = Infragistics.Windows.Ribbon.Resources.Customizer;
			customizer.SetCustomizedString("ApplicationMenuDefaultKeyTip", CommonShellResources.IgRibbon_ApplicationMenuDefaultKeyTip);
			customizer.SetCustomizedString("ContextualTabGroupString", CommonShellResources.IgRibbon_ContextualTabGroupString);
			customizer.SetCustomizedString("ContextualTabGroupTabAutoGeneratePrefix", CommonShellResources.IgRibbon_ContextualTabGroupTabAutoGeneratePrefix);
			customizer.SetCustomizedString("Qat_QuickCustomizeMenu_MinimizeRibbon", CommonShellResources.IgRibbon_Qat_QuickCustomizeMenu_MinimizeRibbon);
			customizer.SetCustomizedString("Qat_QuickCustomizeMenu_ShowAboveRibbon", CommonShellResources.IgRibbon_Qat_QuickCustomizeMenu_ShowAboveRibbon);
			customizer.SetCustomizedString("Qat_QuickCustomizeMenu_ShowBelowRibbon", CommonShellResources.IgRibbon_Qat_QuickCustomizeMenu_ShowBelowRibbon);
			customizer.SetCustomizedString("Qat_QuickCustomizeMenu_Title", CommonShellResources.IgRibbon_Qat_QuickCustomizeMenu_Title);
			customizer.SetCustomizedString("QuickCustomizeOverflowButtonKeyTip", CommonShellResources.IgRibbon_QuickCustomizeOverflowButtonKeyTip);
			customizer.SetCustomizedString("RibbonGroupAutoGeneratePrefix", CommonShellResources.IgRibbon_RibbonGroupAutoGeneratePrefix);
			customizer.SetCustomizedString("ToolContextMenu_AddGalleryToQat", CommonShellResources.IgRibbon_ToolContextMenu_AddGalleryToQat);
			customizer.SetCustomizedString("ToolContextMenu_AddToQat", CommonShellResources.IgRibbon_ToolContextMenu_AddToQat);
			customizer.SetCustomizedString("ToolContextMenu_MinimizeRibbon", CommonShellResources.IgRibbon_ToolContextMenu_MinimizeRibbon);
			customizer.SetCustomizedString("ToolContextMenu_RemoveFromQat", CommonShellResources.IgRibbon_ToolContextMenu_RemoveFromQat);
			customizer.SetCustomizedString("ToolContextMenu_ShowQatAboveRibbon", CommonShellResources.IgRibbon_ToolContextMenu_ShowQatAboveRibbon);
			customizer.SetCustomizedString("ToolContextMenu_ShowQatBelowRibbon", CommonShellResources.IgRibbon_ToolContextMenu_ShowQatBelowRibbon);
		}
	}
	internal static class NativeMethods
	{
		[DllImport("user32.dll")]
		internal static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
	}
	[TemplatePart(Name = "PART_OutlookBar", Type = typeof(XamOutlookBar))]
	public class NavigatorBar : System.Windows.Controls.Control
	{
		[CompilerGenerated]
		private sealed class Capture23_0
		{
			public XamOutlookBar outlookBar;

			internal void NavigatorViews_CollectionChangedCallback0(OutlookBarGroup g)
			{
				outlookBar.Groups.Remove(g);
			}
		}

		[CompilerGenerated]
		private sealed class Capture23_1
		{
			public NavigatorView view;

			internal bool NavigatorViews_CollectionChangedCallback1(OutlookBarGroup g)
			{
				return g.Content == view;
			}
		}

		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<NavigatorView, bool> CachedCallback48_0;

			internal bool _outlookBar_SelectedGroupChangedCallback48_0(NavigatorView g)
			{
				return g.IsSelected;
			}
		}

		[CompilerGenerated]
		private sealed class Capture50_0
		{
			public string navGroupKey;

			internal bool SyncWithScreenCallback0(NavigatorView g)
			{
				return g.Key == navGroupKey;
			}
		}

		private Style _navigatorToggleButtonStyle;

		public static readonly RoutedUICommand OpenNewTabCommand;

		public static readonly RoutedUICommand OpenNewWindowCommand;

		public static readonly DependencyProperty IsMinimizedProperty;

		public static readonly DependencyProperty ContainerProperty;

		protected static readonly DependencyPropertyKey NavigatorViewsPropertyKey;

		public static readonly DependencyProperty NavigatorViewsProperty;

		protected static readonly DependencyPropertyKey SelectedGroupPropertyKey;

		public static readonly DependencyProperty SelectedGroupProperty;

		public static readonly RoutedEvent SelectedGroupChangedEvent;

		private XamOutlookBar _outlookBar;

		public bool IsMinimized
		{
			get
			{
				return (bool)GetValue(IsMinimizedProperty);
			}
			set
			{
				SetValue(IsMinimizedProperty, value);
			}
		}

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer Container
		{
			get
			{
				return GetValue(ContainerProperty) as IUnityContainer;
			}
			set
			{
				SetValue(ContainerProperty, value);
			}
		}

		public NavigatorViewCollection NavigatorViews
		{
			get
			{
				return GetValue(NavigatorViewsProperty) as NavigatorViewCollection;
			}
			private set
			{
				SetValue(NavigatorViewsPropertyKey, value);
			}
		}

		public NavigatorView SelectedGroup
		{
			get
			{
				return GetValue(SelectedGroupProperty) as NavigatorView;
			}
			private set
			{
				SetValue(SelectedGroupPropertyKey, value);
			}
		}

		private XamOutlookBar Part_OutlookBar
		{
			get
			{
				return _outlookBar;
			}
			set
			{
				if (_outlookBar != value)
				{
					if (_outlookBar != null)
					{
						_outlookBar.SelectedGroupChanged -= _outlookBar_SelectedGroupChanged;
					}
					_outlookBar = value;
					if (_outlookBar != null)
					{
						_outlookBar.SelectedGroupChanged += _outlookBar_SelectedGroupChanged;
						_outlookBar.SelectedGroupChanging += _outlookBar_SelectedGroupChanging;
						_navigatorToggleButtonStyle = _outlookBar.FindResource(XamOutlookBar.NavigationPaneToggleButtonStyleKey) as Style;
					}
					InitializeOutlookBarGroups();
				}
			}
		}

		public event RoutedEventHandler SelectedGroupChanged
		{
			add
			{
				AddHandler(SelectedGroupChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectedGroupChangedEvent, value);
			}
		}

		public event EventHandler<SelectedNavigationGroupChangingEventArgs> SelectedGroupChanging;

		static NavigatorBar()
		{
			OpenNewTabCommand = new RoutedUICommand("Open in new tab", "OpenNewTab", typeof(NavigatorBar));
			OpenNewWindowCommand = new RoutedUICommand("Open in new window", "OpenNewWindow", typeof(NavigatorBar));
			IsMinimizedProperty = DependencyProperty.Register("IsMinimized", typeof(bool), typeof(NavigatorBar), new PropertyMetadata(false));
			ContainerProperty = DependencyProperty.Register("Container", typeof(IUnityContainer), typeof(NavigatorBar), new PropertyMetadata(null, OnContainerPropertyChanged));
			NavigatorViewsPropertyKey = DependencyProperty.RegisterReadOnly("NavigatorViews", typeof(NavigatorViewCollection), typeof(NavigatorBar), new FrameworkPropertyMetadata(null));
			NavigatorViewsProperty = NavigatorViewsPropertyKey.DependencyProperty;
			SelectedGroupPropertyKey = DependencyProperty.RegisterReadOnly("SelectedGroup", typeof(NavigatorView), typeof(NavigatorBar), new FrameworkPropertyMetadata(null, OnSelectedGroupPropertyChanged));
			SelectedGroupProperty = SelectedGroupPropertyKey.DependencyProperty;
			SelectedGroupChangedEvent = EventManager.RegisterRoutedEvent("SelectedGroupChanged", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(NavigatorBar));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(NavigatorBar), new FrameworkPropertyMetadata(typeof(NavigatorBar)));
			CommandManager.RegisterClassCommandBinding(typeof(NavigatorBar), new CommandBinding(OpenNewTabCommand, OnOpenNewTabCommandExecuted, OnOpenNewTabCommandCanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(NavigatorBar), new CommandBinding(OpenNewWindowCommand, OnOpenNewWindowCommandExecuted, OnOpenNewWindowCommandCanExecute));
		}

		protected override AutomationPeer OnCreateAutomationPeer()
		{
			return new NavigatorBarAutomationPeer(this);
		}

		private static void OnOpenNewTabCommandExecuted(object sender, ExecutedRoutedEventArgs args)
		{
			CommonShellWindow commonShellWindow = Window.GetWindow(sender as DependencyObject) as CommonShellWindow;
			NavigatorView navigatorView = args.Parameter as NavigatorView;
			if (commonShellWindow != null && navigatorView != null)
			{
				commonShellWindow.OpenNavigatorViewInNewTab(navigatorView);
			}
		}

		private static void OnOpenNewTabCommandCanExecute(object sender, CanExecuteRoutedEventArgs args)
		{
			CommonShellWindow commonShellWindow = Window.GetWindow(sender as DependencyObject) as CommonShellWindow;
			NavigatorView navigatorView = args.Parameter as NavigatorView;
			args.CanExecute = commonShellWindow != null && navigatorView != null;
		}

		private static void OnOpenNewWindowCommandExecuted(object sender, ExecutedRoutedEventArgs args)
		{
			CommonShellWindow commonShellWindow = Window.GetWindow(sender as DependencyObject) as CommonShellWindow;
			NavigatorView navigatorView = args.Parameter as NavigatorView;
			if (commonShellWindow != null && navigatorView != null)
			{
				commonShellWindow.OpenNavigatorViewInNewWindow(navigatorView);
			}
		}

		private static void OnOpenNewWindowCommandCanExecute(object sender, CanExecuteRoutedEventArgs args)
		{
			CommonShellWindow commonShellWindow = Window.GetWindow(sender as DependencyObject) as CommonShellWindow;
			NavigatorView navigatorView = args.Parameter as NavigatorView;
			args.CanExecute = commonShellWindow != null && navigatorView != null;
		}

		public NavigatorBar()
		{
			NavigatorViews = new NavigatorViewCollection();
			NavigatorViews.CollectionChanged += NavigatorViews_CollectionChanged;
			AddHandler(NavigatorView.MinimizedItemsChangedEvent, new RoutedEventHandler(NavigatorView_MinimizedItemsChanged));
		}

		private void NavigatorView_MinimizedItemsChanged(object sender, RoutedEventArgs e)
		{
			NavigatorView minimizedToggleButtonStyle = e.OriginalSource as NavigatorView;
			SetMinimizedToggleButtonStyle(minimizedToggleButtonStyle);
		}

		protected override void OnContextMenuOpening(ContextMenuEventArgs e)
		{
			if (e == null)
			{
				return;
			}
			object value = GetValue(FrameworkElement.ContextMenuProperty);
			if (value != null && value != DependencyProperty.UnsetValue)
			{
				base.OnContextMenuOpening(e);
				return;
			}
			System.Windows.Controls.ContextMenu contextMenu = null;
			if (GetAncestor<SelectedGroupHeader>(e.OriginalSource as DependencyObject) != null)
			{
				contextMenu = new System.Windows.Controls.ContextMenu();
			}
			OutlookBarGroup ancestor = GetAncestor<OutlookBarGroup>(e.OriginalSource as DependencyObject);
			if (ancestor != null)
			{
				NavigatorView navigatorView = ancestor.Content as NavigatorView;
				CommonShellWindow commonShellWindow = Window.GetWindow(this) as CommonShellWindow;
				if (navigatorView != null && commonShellWindow != null)
				{
					contextMenu = new System.Windows.Controls.ContextMenu();
					if (CommonShellPreferences.NavigationMode != ShellNavigationMode.ExclusiveViews)
					{
						contextMenu.Items.Add(new System.Windows.Controls.MenuItem
						{
							Command = OpenNewTabCommand,
							CommandParameter = navigatorView,
							CommandTarget = this
						});
					}
					if (CommonShellPreferences.MultipleMainWindowsEnabled)
					{
						contextMenu.Items.Add(new System.Windows.Controls.MenuItem
						{
							Command = OpenNewWindowCommand,
							CommandParameter = navigatorView,
							CommandTarget = this
						});
					}
				}
			}
			if (contextMenu != null && contextMenu.Items.Count > 0)
			{
				contextMenu.IsOpen = true;
			}
			base.OnContextMenuOpening(e);
		}

		private T GetAncestor<T>(DependencyObject d) where T : class
		{
			DependencyObject dependencyObject = d;
			while (true)
			{
				if (dependencyObject == null)
				{
					return null;
				}
				if (dependencyObject == this)
				{
					return null;
				}
				if (typeof(T).IsInstanceOfType(dependencyObject))
				{
					break;
				}
				dependencyObject = VisualTreeHelper.GetParent(dependencyObject);
			}
			return dependencyObject as T;
		}

		private static void OnContainerPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is NavigatorBar navigatorBar)
			{
				navigatorBar.OnContainerChanged(args.OldValue as IUnityContainer, args.NewValue as IUnityContainer);
			}
		}

		protected virtual void OnContainerChanged(IUnityContainer oldValue, IUnityContainer newValue)
		{
		}

		private void NavigatorViews_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			Capture23_0 Capture23Local = new Capture23_0();
			Capture23Local.outlookBar = Part_OutlookBar;
			if (Capture23Local.outlookBar == null)
			{
				return;
			}
			List<OutlookBarGroup> list = new List<OutlookBarGroup>();
			foreach (OutlookBarGroup group in Capture23Local.outlookBar.Groups)
			{
				if (!NavigatorViews.Contains(group.Content as NavigatorView))
				{
					list.Add(group);
				}
			}
			list.ForEach(Capture23Local.NavigatorViews_CollectionChangedCallback0);
			int num = 0;
			using IEnumerator<NavigatorView> enumerator2 = NavigatorViews.GetEnumerator();
			while (enumerator2.MoveNext())
			{
				Capture23_1 Capture23_2 = new Capture23_1();
				Capture23_2.view = enumerator2.Current;
				if (num >= Capture23Local.outlookBar.Groups.Count || Capture23Local.outlookBar.Groups[num].Content != Capture23_2.view)
				{
					OutlookBarGroup outlookBarGroup = Capture23Local.outlookBar.Groups.FirstOrDefault(Capture23_2.NavigatorViews_CollectionChangedCallback1);
					if (outlookBarGroup != null)
					{
						Capture23Local.outlookBar.Groups.Remove(outlookBarGroup);
					}
					else
					{
						outlookBarGroup = CreateOutlookBarGroup(Capture23_2.view);
					}
					Capture23Local.outlookBar.Groups.Insert(num, outlookBarGroup);
				}
				num++;
			}
		}

		private static void OnSelectedGroupPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is NavigatorBar navigatorBar)
			{
				navigatorBar.OnSelectedGroupChanged(args.OldValue as NavigatorView, args.NewValue as NavigatorView);
			}
		}

		protected virtual void OnSelectedGroupChanged(NavigatorView oldValue, NavigatorView newValue)
		{
			if (Window.GetWindow(this) is CommonShellWindow commonShellWindow)
			{
				commonShellWindow.NotifyOnSelectedNavigationGroupChanged(oldValue, newValue);
			}
			RaiseEvent(new RoutedEventArgs(SelectedGroupChangedEvent));
		}

		private void _outlookBar_SelectedGroupChanging(object sender, SelectedGroupChangingEventArgs args)
		{
			SelectedNavigationGroupChangingEventArgs e = new SelectedNavigationGroupChangingEventArgs();
			if (args.CurrentSelectedOutlookBarGroup != null)
			{
				e.CurrentGroup = args.CurrentSelectedOutlookBarGroup.Content as NavigatorView;
			}
			if (args.NewSelectedOutlookBarGroup != null)
			{
				e.NewGroup = args.NewSelectedOutlookBarGroup.Content as NavigatorView;
			}
			if (Window.GetWindow(this) is CommonShellWindow commonShellWindow)
			{
				e.IsFromScreenSynchronization = commonShellWindow.SynchronizingNavigationBarWithActiveScreen;
				commonShellWindow.NotifyOnSelectedNavigationGroupChanging(e);
				if (e.Cancel)
				{
					args.Cancel = true;
					return;
				}
			}
			if (this.SelectedGroupChanging != null)
			{
				this.SelectedGroupChanging(this, e);
				if (e.Cancel)
				{
					args.Cancel = true;
				}
			}
		}

		private void _outlookBar_SelectedGroupChanged(object sender, RoutedEventArgs e)
		{
			NavigatorView selectedGroup = null;
			NavigatorViewCollection navigatorViews = NavigatorViews;
			if (navigatorViews != null)
			{
				selectedGroup = navigatorViews.FirstOrDefault(CachedDelegates.CachedCallback48_0 ?? (CachedDelegates.CachedCallback48_0 = CachedDelegates.Instance._outlookBar_SelectedGroupChangedCallback48_0));
			}
			SelectedGroup = selectedGroup;
		}

		public override void OnApplyTemplate()
		{
			base.OnApplyTemplate();
			Part_OutlookBar = GetTemplateChild("PART_OutlookBar") as XamOutlookBar;
		}

		public void SyncWithScreen(ScreenContentControl activeScreen)
		{
			Capture50_0 Capture50Local = new Capture50_0();
			Capture50Local.navGroupKey = ((activeScreen != null) ? activeScreen.NavigationGroupKey : string.Empty);
			NavigatorView navigatorView = ((!string.IsNullOrEmpty(Capture50Local.navGroupKey)) ? NavigatorViews.FirstOrDefault(Capture50Local.SyncWithScreenCallback0) : null);
			if (navigatorView == null)
			{
				navigatorView = SelectedGroup;
			}
			if (navigatorView != null && navigatorView.SynchronizeWithScreen(activeScreen))
			{
				navigatorView.IsSelected = true;
			}
		}

		public void AddNavigatorView(NavigatorView group)
		{
			NavigatorViews?.Add(group);
		}

		public void RemoveNavigatorView(NavigatorView group)
		{
			NavigatorViews?.Remove(group);
		}

		private void InitializeOutlookBarGroups()
		{
			Part_OutlookBar.Groups.Clear();
			if (Part_OutlookBar == null)
			{
				return;
			}
			foreach (NavigatorView navigatorView in NavigatorViews)
			{
				Part_OutlookBar.Groups.Add(CreateOutlookBarGroup(navigatorView));
			}
		}

		private OutlookBarGroup CreateOutlookBarGroup(NavigatorView view)
		{
			SetMinimizedToggleButtonStyle(view);
			OutlookBarGroup outlookBarGroup = new OutlookBarGroup();
			outlookBarGroup.Content = view;
			outlookBarGroup.SetBinding(OutlookBarGroup.IsSelectedProperty, new System.Windows.Data.Binding
			{
				Source = view,
				Path = new PropertyPath(NavigatorView.IsSelectedProperty),
				Mode = BindingMode.TwoWay
			});
			outlookBarGroup.SetBinding(HeaderedContentControl.HeaderProperty, new System.Windows.Data.Binding
			{
				Source = view,
				Path = new PropertyPath(NavigatorView.HeaderProperty),
				Mode = BindingMode.OneWay
			});
			outlookBarGroup.SetBinding(OutlookBarGroup.LargeImageProperty, new System.Windows.Data.Binding
			{
				Source = view,
				Path = new PropertyPath(NavigatorView.LargeImageProperty),
				Mode = BindingMode.OneWay
			});
			outlookBarGroup.SetBinding(OutlookBarGroup.SmallImageProperty, new System.Windows.Data.Binding
			{
				Source = view,
				Path = new PropertyPath(NavigatorView.SmallImageProperty),
				Mode = BindingMode.OneWay
			});
			return outlookBarGroup;
		}

		private void SetMinimizedToggleButtonStyle(NavigatorView view)
		{
			if (_navigatorToggleButtonStyle == null)
			{
				return;
			}
			foreach (ToggleButton item in view.MinimizedItems.OfType<ToggleButton>())
			{
				item.Style = _navigatorToggleButtonStyle;
			}
		}

		public void NavigateTo(string navigationGroup, string navigationPath, ShowScreenOptions options)
		{
			foreach (NavigatorView navigatorView in NavigatorViews)
			{
				if (navigatorView.Key == navigationGroup)
				{
					navigatorView.IsSelected = true;
					navigatorView.NavigateTo(navigationPath, options);
				}
			}
		}

		public void FocusOnActiveElement()
		{
			NavigatorView selectedGroup = SelectedGroup;
			if (selectedGroup != null)
			{
				selectedGroup.FocusOnPrimaryElement();
			}
			else
			{
				Focus();
			}
		}
	}
	public class RibbonCaptionStyleDictionary : ResourceDictionary, IComponentConnector
	{
		private bool _contentLoaded;

		public RibbonCaptionStyleDictionary()
		{
			InitializeComponent();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.CommonShell.Wpf;V31.0.0.5;component/ribboncaptionstyledictionary.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			_contentLoaded = true;
		}
	}
	public class ScreenFactoryCatalog : IScreenFactoryCatalog
	{
		private Dictionary<string, IScreenFactory> _factories = new Dictionary<string, IScreenFactory>();

		public ScreenFactoryCatalog()
		{
			RegisterScreenFactory("EmptyScreen", typeof(EmptyScreenContentControl));
			RegisterScreenFactory("TrackingScreenPanel", typeof(TrackingScreenPanelControl));
			RegisterScreenFactory(ClosedScreenPlaceholder.FactoryKey, typeof(ClosedScreenPlaceholder));
		}

		public void RegisterScreenFactory(IScreenFactory factory)
		{
			if (factory != null)
			{
				string key = factory.Key;
				_factories[key] = factory;
			}
		}

		public void RegisterScreenFactory(string key, Func<IUnityContainer, ScreenSubject, ScreenState, ScreenContentControl> createScreenFunction)
		{
			RegisterScreenFactory(new DelegateScreenFactory(key, createScreenFunction));
		}

		public void RegisterScreenFactory(string key, Type screenType)
		{
			RegisterScreenFactory(new DelegateScreenFactory(key, screenType));
		}

		public IScreenFactory FindScreenFactory(string key)
		{
			if (string.IsNullOrEmpty(key))
			{
				return null;
			}
			IScreenFactory value = null;
			_factories.TryGetValue(key, out value);
			return value;
		}

		public ScreenContentControl CreateScreen(IUnityContainer container, string screenKey, ScreenSubject screenSubject, ScreenState screenState)
		{
			IScreenFactory screenFactory = FindScreenFactory(screenKey);
			ScreenContentControl screenContentControl = null;
			if (screenFactory != null)
			{
				screenContentControl = screenFactory.CreateScreen(container, screenSubject, screenState);
			}
			else if (container != null)
			{
				try
				{
					screenContentControl = container.Resolve<ScreenContentControl>(screenKey, Array.Empty<ResolverOverride>());
				}
				catch (Exception)
				{
				}
				screenContentControl?.InitializeScreen(container, screenSubject, screenState);
			}
			return screenContentControl;
		}
	}
	[TemplatePart(Name = "PART_DockManager", Type = typeof(XamDockManager))]
	public class ScreenManager : System.Windows.Controls.Control
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<ScreenContentControl, bool> CachedCallback43_0;

			public static Func<ScreenContentControl, bool> CachedCallback86_0;

			internal bool FindActiveDocumentScreenCallback43_0(ScreenContentControl s)
			{
				return s.IsDocumentScreen;
			}

			internal bool RestoreScreenLayoutFromWorkspaceCallback86_0(ScreenContentControl s)
			{
				return true;
			}
		}

		[CompilerGenerated]
		private sealed class Capture45_0
		{
			public ContentPane pane;

			internal void ActivateContentPaneCallback0()
			{
				ToolWindow toolWindow = ToolWindow.GetToolWindow(pane);
				if (toolWindow != null)
				{
					Window window = Window.GetWindow(toolWindow);
					if (window != null && window.WindowState == WindowState.Minimized)
					{
						NativeMethods.ShowWindow(new WindowInteropHelper(window).Handle, 9);
					}
				}
			}
		}

		[CompilerGenerated]
		private sealed class Capture46_0
		{
			public ScreenContentControl screen;

			internal bool ActivateScreenCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == screen;
			}
		}

		[CompilerGenerated]
		private sealed class Capture48_0
		{
			public ScreenContentControl screen;

			internal bool DetachScreenCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == screen;
			}
		}

		[CompilerGenerated]
		private sealed class Capture49_0
		{
			public ScreenContentControl screen;

			internal bool CloseScreenCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == screen;
			}
		}

		[CompilerGenerated]
		private sealed class ScreenEnumerator : IEnumerable<ScreenContentControl>, IEnumerable, IEnumerator<ScreenContentControl>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private ScreenContentControl currentItem;

			private int initialThreadId;

			public ScreenManager owner;

			private bool includeInternal;

			public bool initialIncludeinternal;

			private Func<ScreenContentControl, bool> filter;

			public Func<ScreenContentControl, bool> initialFilter;

			private IEnumerator<ContentPane> iteratorStorage1;

			ScreenContentControl IEnumerator<ScreenContentControl>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public ScreenEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = iteratorState;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeRegion1();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ScreenManager screenManager = owner;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true;
							return false;
						}
						iteratorState = -3;
					}
					else
					{
						iteratorState = -1;
						XamDockManager part_DockManager = screenManager.Part_DockManager;
						if (part_DockManager == null)
						{
							goto IL_00b4;
						}
						iteratorStorage1 = part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder).GetEnumerator();
						iteratorState = -3;
					}
					while (iteratorStorage1.MoveNext())
					{
						ScreenContentControl screen = GetScreen(iteratorStorage1.Current, includeInternal);
						if (screen != null && (filter == null || filter(screen)))
						{
							currentItem = screen;
							iteratorState = 1;
							completedNormally = true;
							return true;
						}
					}
					DisposeRegion1();
					iteratorStorage1 = null;
					goto IL_00b4;
					IL_00b4:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault clause disposes the iterator on an exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeRegion1()
			{
				iteratorState = -1;
				if (iteratorStorage1 != null)
				{
					iteratorStorage1.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<ScreenContentControl> IEnumerable<ScreenContentControl>.GetEnumerator()
			{
				ScreenEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new ScreenEnumerator(0)
					{
						owner = owner
					};
				}
				enumerator.filter = initialFilter;
				enumerator.includeInternal = initialIncludeinternal;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<ScreenContentControl>)this).GetEnumerator();
			}
		}

		[CompilerGenerated]
		private sealed class Capture57_0
		{
			public string name;

			internal bool FindContentPaneByNameCallback0(ContentPane pane)
			{
				return pane.Name == name;
			}
		}

		[CompilerGenerated]
		private sealed class Capture58_0
		{
			public ScreenContentControl screen;

			internal bool FindContentPaneForScreenCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == screen;
			}
		}

		[CompilerGenerated]
		private sealed class Capture80_0
		{
			public ScreenContentControl screen;

			internal bool GetNavigationHistoryFromScreenCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == screen;
			}
		}

		[CompilerGenerated]
		private sealed class Capture81_0
		{
			public ScreenContentControl referenceScreen;

			public ScreenNavigationHistoryItem item;

			internal bool NavigateBackwardCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == referenceScreen;
			}

			internal bool NavigateBackwardCallback1(ScreenNavigationHistoryItem i)
			{
				return i == item;
			}
		}

		[CompilerGenerated]
		private sealed class Capture82_0
		{
			public ScreenContentControl referenceScreen;

			public ScreenNavigationHistoryItem item;

			internal bool NavigateForwardCallback0(ContentPane pane)
			{
				return GetScreen(pane, includeInternal: true) == referenceScreen;
			}

			internal bool NavigateForwardCallback1(ScreenNavigationHistoryItem i)
			{
				return i == item;
			}
		}

		[CompilerGenerated]
		private sealed class ContentPaneEnumerator : IEnumerable<ContentPane>, IEnumerable, IEnumerator<ContentPane>, IDisposable, IEnumerator
		{
			private int iteratorState;

			private ContentPane currentItem;

			private int initialThreadId;

			private SplitPane splitPane;

			public SplitPane initialSplitpane;

			public ScreenManager owner;

			private IEnumerator<FrameworkElement> iteratorStorage1;

			private IEnumerator<ContentPane> iteratorStorage2;

			private IEnumerator iteratorStorage3;

			ContentPane IEnumerator<ContentPane>.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return currentItem;
				}
			}

			[DebuggerHidden]
			public ContentPaneEnumerator(int iteratorState)
			{
				this.iteratorState = iteratorState;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = iteratorState;
				if ((uint)(num - -5) > 2u && (uint)(num - 1) > 2u)
				{
					return;
				}
				try
				{
					switch (num)
					{
					case -4:
					case 1:
						try
						{
							break;
						}
						finally
						{
							DisposeRegion2();
						}
					case -5:
					case 2:
						try
						{
							break;
						}
						finally
						{
							DisposeRegion3();
						}
					}
				}
				finally
				{
					DisposeRegion1();
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = iteratorState;
					ScreenManager screenManager = owner;
					TabGroupPane tabGroupPane;
					SplitPane splitPane;
					switch (num)
					{
					default:
						completedNormally = true;
						return false;
					case 0:
						iteratorState = -1;
						iteratorStorage1 = this.splitPane.Panes.GetEnumerator();
						iteratorState = -3;
						goto IL_01a2;
					case 1:
						iteratorState = -4;
						goto IL_00da;
					case 2:
						iteratorState = -5;
						goto IL_0167;
					case 3:
						{
							iteratorState = -3;
							goto IL_01a2;
						}
						IL_01a2:
						while (true)
						{
							if (iteratorStorage1.MoveNext())
							{
								FrameworkElement current = iteratorStorage1.Current;
								FrameworkElement obj = ((!(current is ContentPanePlaceholder contentPanePlaceholder)) ? current : contentPanePlaceholder.Pane);
								ContentPane contentPane = obj as ContentPane;
								tabGroupPane = obj as TabGroupPane;
								splitPane = obj as SplitPane;
								if (splitPane != null)
								{
									break;
								}
								if (tabGroupPane == null)
								{
									if (contentPane != null)
									{
										currentItem = contentPane;
										iteratorState = 3;
										completedNormally = true;
										return true;
									}
									continue;
								}
								goto IL_0100;
							}
							DisposeRegion1();
							iteratorStorage1 = null;
							completedNormally = true;
							return false;
						}
						iteratorStorage2 = screenManager.EnumerateContentPanesInSplitPane(splitPane).GetEnumerator();
						iteratorState = -4;
						goto IL_00da;
						IL_0100:
						iteratorStorage3 = ((IEnumerable)tabGroupPane.Items).GetEnumerator();
						iteratorState = -5;
						goto IL_0167;
						IL_00da:
						if (iteratorStorage2.MoveNext())
						{
							ContentPane current2 = iteratorStorage2.Current;
							currentItem = current2;
							iteratorState = 1;
							completedNormally = true;
							return true;
						}
						DisposeRegion2();
						iteratorStorage2 = null;
						goto IL_01a2;
						IL_0167:
						while (iteratorStorage3.MoveNext())
						{
							object current3 = iteratorStorage3.Current;
							if (((!(current3 is ContentPanePlaceholder contentPanePlaceholder2)) ? current3 : contentPanePlaceholder2.Pane) is ContentPane contentPane2)
							{
								currentItem = contentPane2;
								iteratorState = 2;
								completedNormally = true;
								return true;
							}
						}
						DisposeRegion3();
						iteratorStorage3 = null;
						goto IL_01a2;
					}
				}
				finally
				{
					// The original fault clause disposes the iterator on an exceptional exit.
					if (!completedNormally) ((IDisposable)this).Dispose();
				}
			}


			private void DisposeRegion1()
			{
				iteratorState = -1;
				if (iteratorStorage1 != null)
				{
					iteratorStorage1.Dispose();
				}
			}

			private void DisposeRegion2()
			{
				iteratorState = -3;
				if (iteratorStorage2 != null)
				{
					iteratorStorage2.Dispose();
				}
			}

			private void DisposeRegion3()
			{
				iteratorState = -3;
				if (iteratorStorage3 is IDisposable disposable)
				{
					disposable.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<ContentPane> IEnumerable<ContentPane>.GetEnumerator()
			{
				ContentPaneEnumerator enumerator;
				if (iteratorState == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					iteratorState = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new ContentPaneEnumerator(0)
					{
						owner = owner
					};
				}
				enumerator.splitPane = initialSplitpane;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<ContentPane>)this).GetEnumerator();
			}
		}

		public static readonly RoutedUICommand OpenNewScreenDocumentTabCommand;

		public static readonly RoutedUICommand CloseScreenDocumentTabCommand;

		private static string anonymousScreenPrefix;

		internal static readonly DependencyProperty ForceCloseProperty;

		private IScreenFactoryCatalog _screenFactoryCatalog;

		private CommonShellWindow _shellWindow;

		private XamDockManager _dockManager;

		private int _windowOffsetIndex;

		private static readonly System.Windows.Point[] _windowOffsets;

		private const int SW_RESTORE = 9;

		public static readonly DependencyProperty ForwardNavigationHistoryProperty;

		public static readonly DependencyProperty BackwardNavigationHistoryProperty;

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer Container { get; set; }

		[Microsoft.Practices.Unity.Dependency]
		public IScreenFactoryCatalog ScreenFactoryCatalog
		{
			get
			{
				if (_screenFactoryCatalog == null && Container != null)
				{
					_screenFactoryCatalog = Container.Resolve<IScreenFactoryCatalog>(Array.Empty<ResolverOverride>());
				}
				return _screenFactoryCatalog;
			}
			set
			{
				_screenFactoryCatalog = value;
			}
		}

		public CommonShellWindow ShellWindow
		{
			get
			{
				if (_shellWindow == null && Container != null)
				{
					_shellWindow = Container.Resolve<IShellMainWindow>(Array.Empty<ResolverOverride>()) as CommonShellWindow;
				}
				return _shellWindow;
			}
			set
			{
				_shellWindow = value;
			}
		}

		private XamDockManager Part_DockManager
		{
			get
			{
				return _dockManager;
			}
			set
			{
				if (_dockManager == value)
				{
					return;
				}
				if (_dockManager != null)
				{
					_dockManager.ActivePaneChanged -= dockManager_OnActivePaneChanged;
					if (_dockManager.HasDocumentContentHost)
					{
						(_dockManager.Content as DocumentContentHost).ActiveDocumentChanged -= docHost_ActiveDocumentChanged;
					}
				}
				_dockManager = value;
				if (_dockManager != null)
				{
					_dockManager.ActivePaneChanged += dockManager_OnActivePaneChanged;
					if (!_dockManager.HasDocumentContentHost)
					{
						_dockManager.Content = new DocumentContentHost();
					}
					(_dockManager.Content as DocumentContentHost).ActiveDocumentChanged += docHost_ActiveDocumentChanged;
				}
			}
		}

		static ScreenManager()
		{
			OpenNewScreenDocumentTabCommand = new RoutedUICommand("New Tab", "New Tab", typeof(ScreenManager));
			CloseScreenDocumentTabCommand = new RoutedUICommand("Close Tab", "Close Tab", typeof(ScreenManager));
			anonymousScreenPrefix = "_AnonymousScreen";
			ForceCloseProperty = DependencyProperty.RegisterAttached("ForceClose", typeof(bool), typeof(ScreenManager), null);
			_windowOffsets = new System.Windows.Point[4]
			{
				new System.Windows.Point(20.0, 20.0),
				new System.Windows.Point(60.0, 60.0),
				new System.Windows.Point(100.0, 100.0),
				new System.Windows.Point(140.0, 140.0)
			};
			ForwardNavigationHistoryProperty = DependencyProperty.RegisterAttached("ForwardNavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenManager), new PropertyMetadata(null));
			BackwardNavigationHistoryProperty = DependencyProperty.RegisterAttached("BackwardNavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenManager), new PropertyMetadata(null));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(ScreenManager), new FrameworkPropertyMetadata(typeof(ScreenManager)));
		}

		public ScreenManager()
		{
			base.CommandBindings.Add(new CommandBinding(OpenNewScreenDocumentTabCommand, ExecuteOpenNewScreenDocumentTabCommand));
			base.CommandBindings.Add(new CommandBinding(CloseScreenDocumentTabCommand, ExecuteCloseScreenDocumentTabCommand));
		}

		protected override AutomationPeer OnCreateAutomationPeer()
		{
			return new ScreenManagerAutomationPeer(this);
		}

		private void docHost_ActiveDocumentChanged(object sender, RoutedPropertyChangedEventArgs<ContentPane> e)
		{
			ShellWindow?.RefreshActiveScreenProperties();
		}

		private void dockManager_OnActivePaneChanged(object sender, RoutedPropertyChangedEventArgs<ContentPane> e)
		{
			ShellWindow?.RefreshActiveScreenProperties();
		}

		public override void OnApplyTemplate()
		{
			base.OnApplyTemplate();
			Part_DockManager = GetTemplateChild("PART_DockManager") as XamDockManager;
		}

		private void ExecuteOpenNewScreenDocumentTabCommand(object sender, ExecutedRoutedEventArgs args)
		{
			TabGroupPane tabGroup = args.Parameter as TabGroupPane;
			OpenNewScreenDocumentTab(tabGroup);
		}

		private void ExecuteCloseScreenDocumentTabCommand(object sender, ExecutedRoutedEventArgs args)
		{
			if (args.Parameter is PaneTabItem { Pane: { } pane })
			{
				pane.ExecuteCommand(ContentPaneCommands.Close);
			}
		}

		public void OpenNewScreenDocumentTab()
		{
			OpenNewScreenDocumentTab(null);
		}

		private void OpenNewScreenDocumentTab(TabGroupPane tabGroup)
		{
			ContentPane contentPane = null;
			contentPane = ((tabGroup == null) ? SelectTargetTabContentPane() : (tabGroup.SelectedItem as ContentPane));
			ScreenContentControl activeScreen = ((contentPane != null && CanCloneScreen(contentPane)) ? GetScreen(contentPane, includeInternal: false) : null);
			CommonShellWindow shellWindow = ShellWindow;
			ShowScreenEventArgs e = null;
			if (shellWindow == null)
			{
				return;
			}
			e = shellWindow.SelectContentForNewScreenTab(activeScreen);
			if (!CanAddNewDocumentTab(e) || e == null)
			{
				return;
			}
			ContentPane contentPane2 = CreateScreenContentPane(string.Empty);
			LoadScreen(contentPane2, e.ScreenFactoryKey, e.ScreenSubject, e.ScreenState);
			if (tabGroup == null)
			{
				tabGroup = contentPane?.Parent as TabGroupPane;
				if (tabGroup == null)
				{
					tabGroup = new TabGroupPane();
					SplitPane splitPane = new SplitPane();
					splitPane.Panes.Add(tabGroup);
					if (contentPane != null)
					{
						tabGroup.Items.Add(contentPane);
					}
					(Part_DockManager.Content as DocumentContentHost).Panes.Add(splitPane);
				}
			}
			tabGroup.Items.Add(contentPane2);
			contentPane2.Activate();
		}

		internal static bool IsAnonymousPane(ContentPane contentPane)
		{
			if (contentPane == null)
			{
				return true;
			}
			return string.Compare(contentPane.Name, 0, anonymousScreenPrefix, 0, anonymousScreenPrefix.Length, StringComparison.Ordinal) == 0;
		}

		internal static bool CanCloneScreen(ContentPane contentPane)
		{
			if (contentPane == null)
			{
				return false;
			}
			if (!IsAnonymousPane(contentPane))
			{
				return false;
			}
			return GetScreen(contentPane, includeInternal: false)?.AllowCloning ?? false;
		}

		private bool CanAddNewDocumentTab(ShowScreenEventArgs initialContentArgs)
		{
			BeforeAddDocumentTabEventArgs e = new BeforeAddDocumentTabEventArgs
			{
				InitialTabContent = initialContentArgs
			};
			ShellWindow.EventAggregator.GetEvent<BeforeAddDocumentTabEvent>().Publish(e);
			return !e.Cancel;
		}

		public void ShowScreen(ShowScreenEventArgs args)
		{
			if (args == null)
			{
				return;
			}
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			try
			{
				Mouse.OverrideCursor = System.Windows.Input.Cursors.Wait;
				XamDockManager part_DockManager = Part_DockManager;
				if (part_DockManager == null)
				{
					return;
				}
				if (!string.IsNullOrEmpty(args.PaneName))
				{
					ContentPane contentPane = FindContentPaneByName(args.PaneName);
					if (contentPane != null)
					{
						LoadScreen(contentPane, args.ScreenFactoryKey, args.ScreenSubject, args.ScreenState, addToHistory: true, args.ForceRedisplay);
						if (contentPane.Visibility != Visibility.Visible)
						{
							contentPane.Visibility = Visibility.Visible;
							if (contentPane.PaneLocation == PaneLocation.Floating)
							{
								contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
							}
							else if (contentPane.IsPinned)
							{
								contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
							}
							else
							{
								contentPane.ExecuteCommand(ContentPaneCommands.Flyout);
							}
						}
						else if (contentPane.IsPinned)
						{
							contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
						}
						else
						{
							contentPane.ExecuteCommand(ContentPaneCommands.Flyout);
						}
						return;
					}
				}
				ContentPane contentPane2 = null;
				if (args.InitialLocation == ScreenLocation.TabbedDocument)
				{
					bool flag = args.CreateNewTab;
					if (!part_DockManager.HasDocumentContentHost)
					{
						part_DockManager.Content = new DocumentContentHost();
					}
					DocumentContentHost documentContentHost = part_DockManager.Content as DocumentContentHost;
					contentPane2 = SelectTargetTabContentPane();
					if (!flag && contentPane2 != null)
					{
						string text = (IsAnonymousPane(contentPane2) ? string.Empty : contentPane2.Name);
						if (!string.IsNullOrEmpty(args.PaneName) && string.Equals(text, args.PaneName))
						{
							flag = false;
						}
						else if (!string.IsNullOrEmpty(text))
						{
							flag = true;
						}
						else if (!string.IsNullOrEmpty(args.PaneName))
						{
							flag = true;
						}
						else
						{
							ScreenContentControl screen = GetScreen(contentPane2, includeInternal: false);
							if (screen != null && !screen.CanReplaceScreen())
							{
								flag = true;
							}
						}
					}
					if (contentPane2 == null || flag)
					{
						if (!CanAddNewDocumentTab(args))
						{
							return;
						}
						TabGroupPane tabGroupPane = contentPane2?.Parent as TabGroupPane;
						if (tabGroupPane == null)
						{
							tabGroupPane = new TabGroupPane();
							SplitPane splitPane = new SplitPane();
							splitPane.Panes.Add(tabGroupPane);
							if (contentPane2 != null)
							{
								tabGroupPane.Items.Add(contentPane2);
							}
							documentContentHost.Panes.Add(splitPane);
						}
						contentPane2 = CreateScreenContentPane(args.PaneName);
						tabGroupPane.Items.Add(contentPane2);
					}
					LoadScreen(contentPane2, args.ScreenFactoryKey, args.ScreenSubject, args.ScreenState, addToHistory: true, args.ForceRedisplay);
					GetScreen(contentPane2, includeInternal: false)?.OnOpening(new ScreenOpeningEventArgs
					{
						InitialWindowSize = args.InitialSize
					});
				}
				else
				{
					InitialPaneLocation initialPaneLocation = InitialPaneLocation.DockedRight;
					bool flag2 = false;
					switch (args.InitialLocation)
					{
					case ScreenLocation.DockedLeft:
						initialPaneLocation = InitialPaneLocation.DockedLeft;
						break;
					case ScreenLocation.DockedRight:
						initialPaneLocation = InitialPaneLocation.DockedRight;
						break;
					case ScreenLocation.DockedBottom:
						initialPaneLocation = InitialPaneLocation.DockedBottom;
						break;
					case ScreenLocation.DockedTop:
						initialPaneLocation = InitialPaneLocation.DockedTop;
						break;
					case ScreenLocation.DockableFloating:
						initialPaneLocation = InitialPaneLocation.DockableFloating;
						flag2 = true;
						break;
					case ScreenLocation.FloatingOnly:
						initialPaneLocation = InitialPaneLocation.FloatingOnly;
						flag2 = true;
						break;
					}
					SplitPane splitPane2 = new SplitPane();
					XamDockManager.SetInitialLocation(splitPane2, initialPaneLocation);
					contentPane2 = CreateScreenContentPane(args.PaneName);
					if (args.ShowPinned.HasValue && !flag2)
					{
						contentPane2.IsPinned = args.ShowPinned.Value;
					}
					LoadScreen(contentPane2, args.ScreenFactoryKey, args.ScreenSubject, args.ScreenState, addToHistory: true, args.ForceRedisplay);
					System.Windows.Size size = args.InitialSize;
					ScreenContentControl screen2 = GetScreen(contentPane2, includeInternal: false);
					if (screen2 != null)
					{
						ScreenOpeningEventArgs e = new ScreenOpeningEventArgs
						{
							InitialWindowSize = size
						};
						screen2.OnOpening(e);
						size = e.InitialWindowSize;
					}
					if (flag2)
					{
						if (size.IsEmpty || size.Width <= 0.0 || size.Height <= 0.0)
						{
							CommonShellWindow shellWindow = ShellWindow;
							if (shellWindow != null)
							{
								size = shellWindow.DefaultFloatingScreenSize;
							}
						}
						if (!size.IsEmpty && size.Width > 0.0 && size.Height > 0.0)
						{
							if (CommonShellPreferences.FloatingPanesWaitForLoad)
							{
								XamDockManager.SetFloatingSize(splitPane2, System.Windows.Size.Empty);
								splitPane2.Height = size.Height;
								splitPane2.Width = size.Width;
							}
							else
							{
								XamDockManager.SetFloatingSize(splitPane2, size);
							}
						}
					}
					else
					{
						switch (initialPaneLocation)
						{
						case InitialPaneLocation.DockedTop:
						case InitialPaneLocation.DockedBottom:
							if (!size.IsEmpty && size.Height > 0.0)
							{
								splitPane2.Height = size.Height;
							}
							break;
						case InitialPaneLocation.DockedLeft:
						case InitialPaneLocation.DockedRight:
							if (!size.IsEmpty && size.Width > 0.0)
							{
								splitPane2.Width = size.Width;
							}
							break;
						}
					}
					if (flag2)
					{
						if (args.FloatingPaneInitialPosition.HasValue)
						{
							XamDockManager.SetFloatingLocation(splitPane2, args.FloatingPaneInitialPosition);
						}
						else
						{
							System.Windows.Point value = new System.Windows.Point(0.0, 0.0);
							if (ShellWindow != null && ShellWindow.Ribbon != null)
							{
								value = ShellWindow.Ribbon.PointToScreen(new System.Windows.Point(0.0, 0.0));
								value.Y += 140.0;
							}
							value.Y += _windowOffsets[_windowOffsetIndex].Y;
							value.X += _windowOffsets[_windowOffsetIndex].X;
							_windowOffsetIndex++;
							if (_windowOffsetIndex == 4)
							{
								_windowOffsetIndex = 0;
							}
							XamDockManager.SetFloatingLocation(splitPane2, value);
						}
					}
					splitPane2.Panes.Add(contentPane2);
					Part_DockManager.Panes.Add(splitPane2);
					if (flag2 && CommonShellPreferences.FloatingPanesWaitForLoad)
					{
						if (splitPane2.ActualHeight > 0.0 && splitPane2.ActualWidth > 0.0)
						{
							XamDockManager.SetFloatingSize(splitPane2, new System.Windows.Size(splitPane2.ActualWidth, splitPane2.ActualHeight));
							Window window = Window.GetWindow(splitPane2);
							if (window != null)
							{
								window.SizeToContent = SizeToContent.Manual;
								window.Height = window.ActualHeight;
								window.Width = window.ActualWidth;
							}
						}
						else if (!size.IsEmpty && size.Width > 0.0 && size.Height > 0.0)
						{
							XamDockManager.SetFloatingSize(splitPane2, size);
							Window window2 = Window.GetWindow(splitPane2);
							if (window2 != null)
							{
								window2.Height = size.Height;
								window2.Width = size.Width;
							}
						}
						splitPane2.ClearValue(FrameworkElement.HeightProperty);
						splitPane2.ClearValue(FrameworkElement.WidthProperty);
					}
				}
				if (!string.IsNullOrEmpty(args.PaneName))
				{
					contentPane2.Name = args.PaneName;
				}
				contentPane2.Activate();
			}
			finally
			{
				Mouse.OverrideCursor = overrideCursor;
			}
		}

		private ContentPane SelectTargetTabContentPane()
		{
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return null;
			}
			if (!(part_DockManager.Content is DocumentContentHost { ActiveDocument: var contentPane }))
			{
				return null;
			}
			if (contentPane != null && contentPane.Content is ClosedScreenPlaceholder)
			{
				contentPane = null;
				foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
				{
					if (pane.PaneLocation == PaneLocation.Document && !(pane.Content is ClosedScreenPlaceholder))
					{
						contentPane = pane;
					}
				}
			}
			return contentPane;
		}

		internal void ReshowScreen(ScreenContentControl screen, string paneName, ScreenLocation initialLocation, System.Windows.Size? preferredSize)
		{
			if (screen == null)
			{
				return;
			}
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return;
			}
			if (!string.IsNullOrEmpty(paneName))
			{
				ContentPane contentPane = FindContentPaneByName(paneName);
				if (contentPane != null)
				{
					LoadScreen(contentPane, screen);
					if (contentPane.Visibility != Visibility.Visible)
					{
						if (contentPane.PaneLocation == PaneLocation.Floating)
						{
							contentPane.Visibility = Visibility.Visible;
							contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
						}
						else
						{
							contentPane.IsPinned = true;
							contentPane.Visibility = Visibility.Visible;
							contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
						}
					}
					else if (contentPane.IsPinned)
					{
						contentPane.ExecuteCommand(ContentPaneCommands.ActivatePane);
					}
					else
					{
						contentPane.ExecuteCommand(ContentPaneCommands.Flyout);
					}
					return;
				}
			}
			ContentPane contentPane2 = null;
			if (initialLocation == ScreenLocation.TabbedDocument)
			{
				if (!part_DockManager.HasDocumentContentHost)
				{
					part_DockManager.Content = new DocumentContentHost();
				}
				DocumentContentHost documentContentHost = part_DockManager.Content as DocumentContentHost;
				TabGroupPane tabGroupPane = SelectTargetTabContentPane()?.Parent as TabGroupPane;
				if (tabGroupPane == null)
				{
					tabGroupPane = new TabGroupPane();
					SplitPane splitPane = new SplitPane();
					splitPane.Panes.Add(tabGroupPane);
					if (contentPane2 != null)
					{
						tabGroupPane.Items.Add(contentPane2);
					}
					documentContentHost.Panes.Add(splitPane);
				}
				contentPane2 = CreateScreenContentPane(paneName);
				tabGroupPane.Items.Add(contentPane2);
				LoadScreen(contentPane2, screen);
			}
			else
			{
				InitialPaneLocation initialPaneLocation = InitialPaneLocation.DockedRight;
				switch (initialLocation)
				{
				case ScreenLocation.DockedLeft:
					initialPaneLocation = InitialPaneLocation.DockedLeft;
					break;
				case ScreenLocation.DockedRight:
					initialPaneLocation = InitialPaneLocation.DockedRight;
					break;
				case ScreenLocation.DockedBottom:
					initialPaneLocation = InitialPaneLocation.DockedBottom;
					break;
				case ScreenLocation.DockedTop:
					initialPaneLocation = InitialPaneLocation.DockedTop;
					break;
				case ScreenLocation.DockableFloating:
					initialPaneLocation = InitialPaneLocation.DockableFloating;
					break;
				case ScreenLocation.FloatingOnly:
					initialPaneLocation = InitialPaneLocation.FloatingOnly;
					break;
				}
				SplitPane splitPane2 = new SplitPane();
				XamDockManager.SetInitialLocation(splitPane2, initialPaneLocation);
				contentPane2 = CreateScreenContentPane(paneName);
				LoadScreen(contentPane2, screen);
				System.Windows.Size value = (preferredSize.HasValue ? preferredSize.Value : System.Windows.Size.Empty);
				switch (initialPaneLocation)
				{
				case InitialPaneLocation.DockableFloating:
				case InitialPaneLocation.FloatingOnly:
					if (value.IsEmpty || value.Width <= 0.0 || value.Height <= 0.0)
					{
						CommonShellWindow shellWindow = ShellWindow;
						if (shellWindow != null)
						{
							value = shellWindow.DefaultFloatingScreenSize;
						}
					}
					if (!value.IsEmpty && value.Width > 0.0 && value.Height > 0.0)
					{
						XamDockManager.SetFloatingSize(splitPane2, value);
					}
					break;
				case InitialPaneLocation.DockedTop:
				case InitialPaneLocation.DockedBottom:
					if (!value.IsEmpty && value.Height > 0.0)
					{
						splitPane2.Height = value.Height;
					}
					break;
				case InitialPaneLocation.DockedLeft:
				case InitialPaneLocation.DockedRight:
					if (!value.IsEmpty && value.Width > 0.0)
					{
						splitPane2.Width = value.Width;
					}
					break;
				}
				Part_DockManager.Panes.Add(splitPane2);
				splitPane2.Panes.Add(contentPane2);
			}
			if (!string.IsNullOrEmpty(paneName))
			{
				contentPane2.Name = paneName;
			}
			contentPane2.Activate();
		}

		public static ScreenContentControl GetScreen(ContentControl pane, bool includeInternal)
		{
			if (pane == null)
			{
				return null;
			}
			ScreenContentControl screenContentControl = pane.Content as ScreenContentControl;
			if (!includeInternal && IsInternalScreen(screenContentControl))
			{
				screenContentControl = null;
			}
			return screenContentControl;
		}

		private static bool IsInternalScreen(ScreenContentControl screen)
		{
			if (!(screen is ClosedScreenPlaceholder))
			{
				return screen is RestoredScreenPlaceholder;
			}
			return true;
		}

		protected void LoadScreen(ContentPane pane, string screenFactoryKey, ScreenSubject screenSubject, ScreenState screenState, bool addToHistory = true, bool forceRedisplay = true)
		{
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			CommonShellWindow shellWindow = ShellWindow;
			try
			{
				Mouse.OverrideCursor = System.Windows.Input.Cursors.Wait;
				ScreenContentControl screen = GetScreen(pane, includeInternal: false);
				if (screen != null && !forceRedisplay && screen.SatisfiesScreenRequirements(screenFactoryKey, screenSubject))
				{
					return;
				}
				if (screen != null)
				{
					CancelEventArgs e = new CancelEventArgs();
					OnScreenClosing(screen, e);
					if (e.Cancel)
					{
						return;
					}
				}
				if (addToHistory && screen != null && !(screen is EmptyScreenContentControl))
				{
					ScreenNavigationHistoryCollection screenNavigationHistoryCollection = EnsureBackwardNavigationHistory(pane);
					screenNavigationHistoryCollection.Insert(0, new ScreenNavigationHistoryItem
					{
						Header = screen.Header,
						ScreenFactoryKey = screen.ScreenFactoryKey,
						ScreenSubject = screen.ScreenSubject,
						ScreenState = screen.SaveState()
					});
					screenNavigationHistoryCollection.PruneHistory();
					GetForwardNavigationHistory(pane)?.Clear();
				}
				if (screen != null)
				{
					OnScreenClosed(screen);
				}
				ScreenContentControl screenContentControl = ScreenFactoryCatalog.CreateScreen(Container, screenFactoryKey, screenSubject, screenState);
				if (screenContentControl != null)
				{
					screenContentControl.ScreenFactoryKey = screenFactoryKey;
					if (screenContentControl.ScreenSubject == null)
					{
						screenContentControl.ScreenSubject = screenSubject;
					}
					if (pane != null)
					{
						pane.Content = screenContentControl;
					}
				}
				shellWindow?.RefreshActiveScreenProperties();
			}
			finally
			{
				Mouse.OverrideCursor = overrideCursor;
			}
		}

		private void LoadScreen(ContentPane pane, ScreenContentControl newScreen, bool addToHistory = true)
		{
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			CommonShellWindow shellWindow = ShellWindow;
			try
			{
				Mouse.OverrideCursor = System.Windows.Input.Cursors.Wait;
				ScreenContentControl screen = GetScreen(pane, includeInternal: false);
				if (screen == newScreen)
				{
					return;
				}
				if (screen != null)
				{
					CancelEventArgs e = new CancelEventArgs();
					OnScreenClosing(screen, e);
					if (e.Cancel)
					{
						return;
					}
				}
				if (addToHistory && screen != null && !(screen is EmptyScreenContentControl))
				{
					ScreenNavigationHistoryCollection screenNavigationHistoryCollection = EnsureBackwardNavigationHistory(pane);
					screenNavigationHistoryCollection.Insert(0, new ScreenNavigationHistoryItem
					{
						Header = screen.Header,
						ScreenFactoryKey = screen.ScreenFactoryKey,
						ScreenSubject = screen.ScreenSubject,
						ScreenState = screen.SaveState()
					});
					screenNavigationHistoryCollection.PruneHistory();
					GetForwardNavigationHistory(pane)?.Clear();
				}
				if (screen != null && shellWindow != null)
				{
					OnScreenClosed(screen);
				}
				if (newScreen != null && pane != null)
				{
					pane.Content = newScreen;
				}
				shellWindow?.RefreshActiveScreenProperties();
			}
			finally
			{
				Mouse.OverrideCursor = overrideCursor;
			}
		}

		public ScreenContentControl FindActiveScreen(bool includeInternal)
		{
			return SelectScreens(null, includeInternal).FirstOrDefault();
		}

		public ScreenContentControl FindActiveDocumentScreen(bool includeInternal)
		{
			return SelectScreens(CachedDelegates.CachedCallback43_0 ?? (CachedDelegates.CachedCallback43_0 = CachedDelegates.Instance.FindActiveDocumentScreenCallback43_0), includeInternal).FirstOrDefault();
		}

		private void ActivateContentPane(ContentPane pane)
		{
			Capture45_0 Capture45Local = new Capture45_0();
			Capture45Local.pane = pane;
			if (Capture45Local.pane != null)
			{
				Capture45Local.pane.ExecuteCommand(ContentPaneCommands.ActivatePane);
				base.Dispatcher.BeginInvoke(new Action(Capture45Local.ActivateContentPaneCallback0));
				Capture45Local.pane.Activate();
			}
		}

		public void ActivateScreen(ScreenContentControl screen)
		{
			Capture46_0 Capture46Local = new Capture46_0();
			Capture46Local.screen = screen;
			ContentPane contentPane = FindContentPane(Capture46Local.ActivateScreenCallback0);
			if (contentPane != null)
			{
				ActivateContentPane(contentPane);
			}
		}

		public void ActivateNamedPane(string paneName)
		{
			ContentPane contentPane = FindContentPaneByName(paneName);
			if (contentPane != null)
			{
				ActivateContentPane(contentPane);
			}
		}

		public void DetachScreen(ScreenContentControl screen)
		{
			Capture48_0 Capture48Local = new Capture48_0();
			Capture48Local.screen = screen;
			if (Capture48Local.screen != null)
			{
				ContentPane contentPane = FindContentPane(Capture48Local.DetachScreenCallback0);
				if (contentPane != null)
				{
					contentPane.Content = null;
					contentPane.ExecuteCommand(ContentPaneCommands.Close);
				}
			}
		}

		public void CloseScreen(ScreenContentControl screen, CancelEventArgs cancelArgs, bool forceClose)
		{
			Capture49_0 Capture49Local = new Capture49_0();
			Capture49Local.screen = screen;
			if (Capture49Local.screen != null)
			{
				ContentPane contentPane = FindContentPane(Capture49Local.CloseScreenCallback0);
				CloseContentPane(contentPane, cancelArgs, forceClose);
			}
		}

		public void MoveScreen(ScreenContentControl screen, ScreenLocation screenLocation, System.Windows.Size? preferredSize)
		{
			if (screen == null)
			{
				return;
			}
			string paneName = string.Empty;
			ContentPane contentPane = FindContentPaneForScreen(screen);
			if (contentPane != null)
			{
				if (!IsAnonymousPane(contentPane))
				{
					paneName = contentPane.Name;
				}
				contentPane.Content = null;
				contentPane.CloseAction = PaneCloseAction.RemovePane;
				contentPane.ExecuteCommand(ContentPaneCommands.Close);
			}
			ReshowScreen(screen, paneName, screenLocation, preferredSize);
		}

		public void CloseScreens(Func<ScreenContentControl, bool> filter, CancelEventArgs cancelArgs, bool forceClose, bool includeInternal)
		{
			if (filter == null)
			{
				return;
			}
			if (cancelArgs == null)
			{
				cancelArgs = new CancelEventArgs();
			}
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return;
			}
			List<ContentPane> list = new List<ContentPane>();
			foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
			{
				ScreenContentControl screen = GetScreen(pane, includeInternal);
				if (screen != null && filter(screen))
				{
					list.Add(pane);
				}
			}
			foreach (ContentPane item in list)
			{
				CloseContentPane(item, cancelArgs, forceClose);
				if (cancelArgs.Cancel && !forceClose)
				{
					break;
				}
			}
		}

		public void CloseNamedPane(string name, CancelEventArgs cancelArgs, bool forceClose)
		{
			ContentPane contentPane = FindContentPaneByName(name);
			CloseContentPane(contentPane, cancelArgs, forceClose);
		}

		private void CloseContentPane(ContentPane contentPane, CancelEventArgs cancelArgs, bool forceClose)
		{
			if (contentPane == null)
			{
				return;
			}
			ScreenContentControl screen = GetScreen(contentPane, includeInternal: true);
			if (screen != null && !forceClose)
			{
				if (cancelArgs == null)
				{
					cancelArgs = new CancelEventArgs();
				}
				OnScreenClosing(screen, cancelArgs);
				if (cancelArgs.Cancel)
				{
					return;
				}
			}
			try
			{
				contentPane.SetValue(ForceCloseProperty, true);
				contentPane.ExecuteCommand(ContentPaneCommands.Close);
			}
			finally
			{
				contentPane.SetValue(ForceCloseProperty, false);
			}
		}

		public ScreenContentControl FindScreen(Func<ScreenContentControl, bool> matchMethod, bool includeInternal)
		{
			return SelectScreens(matchMethod, includeInternal).FirstOrDefault();
		}

		[IteratorStateMachine(typeof(ScreenEnumerator))]
		public IEnumerable<ScreenContentControl> SelectScreens(Func<ScreenContentControl, bool> filter, bool includeInternal)
		{
			return new ScreenEnumerator(-2)
			{
				owner = this,
				initialFilter = filter,
				initialIncludeinternal = includeInternal
			};
		}

		public ScreenContentControl FindScreenByPaneName(string name, bool includeInternal)
		{
			return GetScreen(FindContentPaneByName(name), includeInternal);
		}

		internal ContentPane FindContentPaneByName(string name)
		{
			Capture57_0 Capture57Local = new Capture57_0();
			Capture57Local.name = name;
			if (string.IsNullOrEmpty(Capture57Local.name))
			{
				return null;
			}
			return FindContentPane(Capture57Local.FindContentPaneByNameCallback0);
		}

		internal ContentPane FindContentPaneForScreen(ScreenContentControl screen)
		{
			Capture58_0 Capture58Local = new Capture58_0();
			Capture58Local.screen = screen;
			if (Capture58Local.screen == null)
			{
				return null;
			}
			return FindContentPane(Capture58Local.FindContentPaneForScreenCallback0);
		}

		internal ContentPane FindContentPane(Func<ContentPane, bool> matchFunc)
		{
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return null;
			}
			foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
			{
				if (pane != null && (matchFunc == null || matchFunc(pane)))
				{
					return pane;
				}
			}
			return null;
		}

		public void ForEachScreen(Action<ScreenContentControl> action, bool includeInternal)
		{
			if (action == null)
			{
				return;
			}
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return;
			}
			foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
			{
				ScreenContentControl screen = GetScreen(pane, includeInternal);
				if (screen != null)
				{
					action(screen);
				}
			}
		}

		protected virtual ContentPane CreateScreenContentPane(string paneName)
		{
			ContentPane contentPane = new ContentPane();
			if (string.IsNullOrEmpty(paneName))
			{
				bool flag = false;
				int num = 1;
				while (!flag)
				{
					paneName = anonymousScreenPrefix + num.ToString(CultureInfo.InvariantCulture);
					flag = true;
					foreach (ContentPane pane in Part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
					{
						if (pane.Name == paneName)
						{
							flag = false;
							break;
						}
					}
					num++;
				}
			}
			contentPane.Name = paneName;
			ConfigureContentPane(contentPane);
			return contentPane;
		}

		private void ConfigureContentPane(ContentPane contentPane)
		{
			BindingOperations.SetBinding(contentPane, HeaderedContentControl.HeaderProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.Header")
			});
			BindingOperations.SetBinding(contentPane, ContentPane.ImageProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.HeaderImage")
			});
			BindingOperations.SetBinding(contentPane, ContentPane.AllowDockingProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.AllowDocking"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(contentPane, ContentPane.AllowFloatingOnlyProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.AllowFloating"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(contentPane, ContentPane.AllowInDocumentHostProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.AllowInDocumentHost"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(contentPane, ContentPane.AllowCloseProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.AllowClose"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(contentPane, ContentPane.SaveInLayoutProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Content.SaveInLayout"),
				Mode = BindingMode.OneWay
			});
			if (!string.IsNullOrEmpty(contentPane.Name) && contentPane.Name.StartsWith(anonymousScreenPrefix, StringComparison.Ordinal))
			{
				contentPane.CloseAction = PaneCloseAction.RemovePane;
			}
			else
			{
				contentPane.CloseAction = PaneCloseAction.HidePane;
			}
			contentPane.Closing += contentPane_Closing;
			contentPane.Closed += contentPane_Closed;
			contentPane.PreviewMouseDown += contentPane_PreviewMouseDown;
			contentPane.OptionsMenuOpening += OnContentPaneOptionsMenuOpening;
		}

		private void OnContentPaneOptionsMenuOpening(object sender, PaneOptionsMenuOpeningEventArgs e)
		{
			if (!(sender is ContentPane { Content: ScreenContentControl content } contentPane))
			{
				return;
			}
			int count = e.Items.Count;
			ControlTemplate template = null;
			Style style = null;
			for (int num = e.Items.Count - 1; num >= 0; num--)
			{
				System.Windows.Controls.MenuItem menuItem = e.Items[num] as System.Windows.Controls.MenuItem;
				if (e.Items[num] is Separator separator)
				{
					style = separator.Style;
					template = separator.Template;
				}
				if (menuItem != null)
				{
					if (!IsMenuItemAllowedForScreen(contentPane, content, menuItem))
					{
						e.Items.RemoveAt(num);
					}
					else if (menuItem.Command == ContentPaneCommands.CloseAllButThis)
					{
						menuItem.Header = CommonShellResources.CloseOtherTabs_Header;
					}
				}
			}
			if (count != e.Items.Count)
			{
				RemoveUnneededSeparators(e.Items);
			}
			if (CommonShellPreferences.MultipleMainWindowsEnabled && content.IsDocumentScreen)
			{
				if (!(e.Items[e.Items.Count - 1] is Separator))
				{
					e.Items.Add(new Separator
					{
						Style = style,
						Template = template
					});
				}
				e.Items.Add(new System.Windows.Controls.MenuItem
				{
					Header = CommonShellResources.MoveToNewWindow_Caption,
					ToolTip = CommonShellResources.MoveToNewWindow_Tooltip,
					Command = ShellWindow.MoveToNewWindowCommand,
					CommandParameter = content
				});
				if (ShellWindow.Application.MainWindows.Count > 1)
				{
					e.Items.Add(new System.Windows.Controls.MenuItem
					{
						Header = CommonShellResources.MoveToNextWindow_Caption,
						ToolTip = CommonShellResources.MoveToNextWindow_Tooltip,
						Command = ShellWindow.MoveToNextWindowCommand,
						CommandParameter = content
					});
					e.Items.Add(new System.Windows.Controls.MenuItem
					{
						Header = CommonShellResources.MoveToPreviousWindow_Caption,
						ToolTip = CommonShellResources.MoveToPreviousWindow_Tooltip,
						Command = ShellWindow.MoveToPreviousWindowCommand,
						CommandParameter = content
					});
				}
			}
			content.OnContentPaneOptionsMenuOpening(e.Items);
		}

		private static void RemoveUnneededSeparators(IList items)
		{
			while (items.Count > 0 && items[0] is Separator)
			{
				items.RemoveAt(0);
			}
			while (items.Count > 0 && items[items.Count - 1] is Separator)
			{
				items.RemoveAt(items.Count - 1);
			}
			for (int num = items.Count - 2; num > 0; num--)
			{
				if (items[num] is Separator && items[num - 1] is Separator)
				{
					items.RemoveAt(num);
				}
			}
		}

		private static bool IsMenuItemAllowedForScreen(ContentPane contentPane, ScreenContentControl screen, System.Windows.Controls.MenuItem menuItem)
		{
			if (menuItem.Command == ContentPaneCommands.Close)
			{
				if (screen.AllowHiding)
				{
					if (string.Equals(menuItem.Header.ToString(), Infragistics.Windows.DockManager.Resources.GetString("ClosePaneMenuItem")))
					{
						return false;
					}
				}
				else if (string.Equals(menuItem.Header.ToString(), Infragistics.Windows.DockManager.Resources.GetString("HidePaneMenuItem")))
				{
					return false;
				}
			}
			else if (menuItem.Command == ContentPaneCommands.TogglePinnedState)
			{
				PaneLocation paneLocation = contentPane.PaneLocation;
				if ((uint)(paneLocation - 5) <= 1u || paneLocation == PaneLocation.Document)
				{
					return false;
				}
			}
			return true;
		}

		private void contentPane_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
			ContentPane contentPane = sender as ContentPane;
			if (contentPane.IsActivePane)
			{
				CommonShellWindow shellWindow = ShellWindow;
				if (shellWindow != null && ShellWindow.ActiveScreen != contentPane.Content)
				{
					shellWindow.RefreshActiveScreenProperties();
				}
			}
		}

		internal void OnScreenClosing(ScreenContentControl screen, CancelEventArgs args)
		{
			if (screen != null)
			{
				CommonShellWindow shellWindow = ShellWindow;
				if (shellWindow != null)
				{
					shellWindow.RaiseScreenClosing(screen, args);
				}
				else
				{
					screen.RaiseClosing(args);
				}
			}
		}

		internal void OnScreenClosed(ScreenContentControl screen)
		{
			if (screen != null)
			{
				CommonShellWindow shellWindow = ShellWindow;
				if (shellWindow != null)
				{
					shellWindow.RaiseScreenClosed(screen);
				}
				else
				{
					screen.RaiseClosed(EventArgs.Empty);
				}
			}
		}

		private void contentPane_Closing(object sender, PaneClosingEventArgs args)
		{
			if (sender is ContentPane contentPane && !(bool)contentPane.GetValue(ForceCloseProperty))
			{
				ScreenContentControl screen = GetScreen(contentPane, includeInternal: true);
				if (screen != null)
				{
					CancelEventArgs e = new CancelEventArgs();
					OnScreenClosing(screen, e);
					args.Cancel = e.Cancel;
				}
			}
		}

		private void contentPane_Closed(object sender, PaneClosedEventArgs args)
		{
			ContentPane obj = sender as ContentPane;
			ScreenContentControl screen = GetScreen(obj, includeInternal: true);
			OnScreenClosed(screen);
			obj.Content = new ClosedScreenPlaceholder();
			if (obj != Part_DockManager.ActivePane)
			{
				base.Dispatcher.BeginInvoke(new Action<ContentPane>(ReactivateAndDisplayPane), DispatcherPriority.Render, Part_DockManager.ActivePane);
			}
		}

		private void ReactivateAndDisplayPane(ContentPane pane)
		{
			if (pane != null)
			{
				pane.Activate();
				pane.BringIntoView();
			}
		}

		public static ScreenNavigationHistoryCollection GetForwardNavigationHistory(DependencyObject target)
		{
			if (target == null)
			{
				return null;
			}
			return target.GetValue(ForwardNavigationHistoryProperty) as ScreenNavigationHistoryCollection;
		}

		public static void SetForwardNavigationHistory(DependencyObject target, ScreenNavigationHistoryCollection value)
		{
			target?.SetValue(ForwardNavigationHistoryProperty, value);
		}

		public static ScreenNavigationHistoryCollection EnsureForwardNavigationHistory(DependencyObject target)
		{
			ScreenNavigationHistoryCollection screenNavigationHistoryCollection = GetForwardNavigationHistory(target);
			if (screenNavigationHistoryCollection == null)
			{
				screenNavigationHistoryCollection = new ScreenNavigationHistoryCollection();
				SetForwardNavigationHistory(target, screenNavigationHistoryCollection);
			}
			return screenNavigationHistoryCollection;
		}

		public static ScreenNavigationHistoryCollection GetBackwardNavigationHistory(DependencyObject target)
		{
			if (target == null)
			{
				return null;
			}
			return target.GetValue(BackwardNavigationHistoryProperty) as ScreenNavigationHistoryCollection;
		}

		public static void SetBackwardNavigationHistory(DependencyObject target, ScreenNavigationHistoryCollection value)
		{
			target?.SetValue(BackwardNavigationHistoryProperty, value);
		}

		public static ScreenNavigationHistoryCollection EnsureBackwardNavigationHistory(DependencyObject target)
		{
			ScreenNavigationHistoryCollection screenNavigationHistoryCollection = GetBackwardNavigationHistory(target);
			if (screenNavigationHistoryCollection == null)
			{
				screenNavigationHistoryCollection = new ScreenNavigationHistoryCollection();
				SetBackwardNavigationHistory(target, screenNavigationHistoryCollection);
			}
			return screenNavigationHistoryCollection;
		}

		public void GetNavigationHistoryFromScreen(ScreenContentControl screen, out ScreenNavigationHistoryCollection forwardHistory, out ScreenNavigationHistoryCollection backwardHistory)
		{
			Capture80_0 Capture80Local = new Capture80_0();
			Capture80Local.screen = screen;
			forwardHistory = null;
			backwardHistory = null;
			if (Capture80Local.screen != null)
			{
				ContentPane contentPane = FindContentPane(Capture80Local.GetNavigationHistoryFromScreenCallback0);
				if (contentPane != null)
				{
					forwardHistory = GetForwardNavigationHistory(contentPane);
					backwardHistory = GetBackwardNavigationHistory(contentPane);
				}
			}
		}

		public void NavigateBackward(ScreenContentControl referenceScreen, ScreenNavigationHistoryItem item)
		{
			Capture81_0 Capture81Local = new Capture81_0();
			Capture81Local.referenceScreen = referenceScreen;
			Capture81Local.item = item;
			ContentPane contentPane = FindContentPane(Capture81Local.NavigateBackwardCallback0);
			if (contentPane == null)
			{
				return;
			}
			ScreenContentControl screen = GetScreen(contentPane, includeInternal: false);
			ScreenNavigationHistoryCollection backwardNavigationHistory = GetBackwardNavigationHistory(contentPane);
			if (backwardNavigationHistory == null || backwardNavigationHistory.Count == 0 || (Capture81Local.item != null && backwardNavigationHistory.FirstOrDefault(Capture81Local.NavigateBackwardCallback1) == null))
			{
				return;
			}
			ScreenNavigationHistoryCollection screenNavigationHistoryCollection = EnsureForwardNavigationHistory(contentPane);
			if (screen != null)
			{
				screenNavigationHistoryCollection.Insert(0, new ScreenNavigationHistoryItem
				{
					Header = screen.Header,
					ScreenFactoryKey = screen.ScreenFactoryKey,
					ScreenSubject = screen.ScreenSubject,
					ScreenState = screen.SaveState()
				});
			}
			if (Capture81Local.item != null)
			{
				while (backwardNavigationHistory.Count > 0 && backwardNavigationHistory[0] != Capture81Local.item)
				{
					ScreenNavigationHistoryItem item2 = backwardNavigationHistory[0];
					backwardNavigationHistory.RemoveAt(0);
					screenNavigationHistoryCollection.Insert(0, item2);
				}
			}
			ScreenNavigationHistoryItem screenNavigationHistoryItem = backwardNavigationHistory[0];
			backwardNavigationHistory.RemoveAt(0);
			LoadScreen(contentPane, screenNavigationHistoryItem.ScreenFactoryKey, screenNavigationHistoryItem.ScreenSubject, screenNavigationHistoryItem.ScreenState, addToHistory: false);
		}

		public void NavigateForward(ScreenContentControl referenceScreen, ScreenNavigationHistoryItem item)
		{
			Capture82_0 Capture82Local = new Capture82_0();
			Capture82Local.referenceScreen = referenceScreen;
			Capture82Local.item = item;
			ContentPane contentPane = FindContentPane(Capture82Local.NavigateForwardCallback0);
			if (contentPane == null)
			{
				return;
			}
			ScreenContentControl screen = GetScreen(contentPane, includeInternal: false);
			ScreenNavigationHistoryCollection forwardNavigationHistory = GetForwardNavigationHistory(contentPane);
			if (forwardNavigationHistory == null || forwardNavigationHistory.Count == 0 || (Capture82Local.item != null && forwardNavigationHistory.FirstOrDefault(Capture82Local.NavigateForwardCallback1) == null))
			{
				return;
			}
			ScreenNavigationHistoryCollection screenNavigationHistoryCollection = EnsureBackwardNavigationHistory(contentPane);
			if (screen != null)
			{
				screenNavigationHistoryCollection.Insert(0, new ScreenNavigationHistoryItem
				{
					Header = screen.Header,
					ScreenFactoryKey = screen.ScreenFactoryKey,
					ScreenSubject = screen.ScreenSubject,
					ScreenState = screen.SaveState()
				});
			}
			if (Capture82Local.item != null)
			{
				while (forwardNavigationHistory.Count > 0 && forwardNavigationHistory[0] != Capture82Local.item)
				{
					ScreenNavigationHistoryItem item2 = forwardNavigationHistory[0];
					forwardNavigationHistory.RemoveAt(0);
					screenNavigationHistoryCollection.Insert(0, item2);
				}
			}
			ScreenNavigationHistoryItem screenNavigationHistoryItem = forwardNavigationHistory[0];
			forwardNavigationHistory.RemoveAt(0);
			LoadScreen(contentPane, screenNavigationHistoryItem.ScreenFactoryKey, screenNavigationHistoryItem.ScreenSubject, screenNavigationHistoryItem.ScreenState, addToHistory: false);
		}

		public void FocusOnActiveElement()
		{
			if (_dockManager != null)
			{
				if (_dockManager.ActivePane == null)
				{
					_dockManager.Focus();
				}
				else
				{
					_dockManager.ActivePane.Activate();
				}
			}
			else
			{
				Focus();
			}
		}

		[IteratorStateMachine(typeof(ContentPaneEnumerator))]
		private IEnumerable<ContentPane> EnumerateContentPanesInSplitPane(SplitPane splitPane)
		{
			return new ContentPaneEnumerator(-2)
			{
				owner = this,
				initialSplitpane = splitPane
			};
		}

		public void SaveScreenLayoutToWorkspace(ShellWorkspace workspace)
		{
			if (workspace == null)
			{
				return;
			}
			workspace.Layout = string.Empty;
			workspace.Screens.Clear();
			if (workspace == null)
			{
				return;
			}
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return;
			}
			workspace.Layout = part_DockManager.SaveLayout();
			foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
			{
				ScreenContentControl screen = GetScreen(pane, includeInternal: true);
				if (screen != null && screen.SaveInLayout)
				{
					workspace.Screens.Add(new WorkspaceScreenData
					{
						PaneName = pane.Name,
						ScreenFactoryKey = screen.ScreenFactoryKey,
						ScreenSubject = screen.ScreenSubject,
						ScreenState = screen.SaveState()
					});
				}
			}
		}

		public void RestoreScreenLayoutFromWorkspace(ShellWorkspace workspace, CancelEventArgs cancelArgs, bool forceClose)
		{
			XamDockManager part_DockManager = Part_DockManager;
			if (part_DockManager == null)
			{
				return;
			}
			Dictionary<string, System.Windows.Size> dictionary = new Dictionary<string, System.Windows.Size>();
			try
			{
				if (cancelArgs == null)
				{
					cancelArgs = new CancelEventArgs();
				}
				CloseScreens(CachedDelegates.CachedCallback86_0 ?? (CachedDelegates.CachedCallback86_0 = CachedDelegates.Instance.RestoreScreenLayoutFromWorkspaceCallback86_0), cancelArgs, forceClose, includeInternal: true);
				if (cancelArgs.Cancel && !forceClose)
				{
					return;
				}
				part_DockManager.Panes.Clear();
				(part_DockManager.Content as DocumentContentHost).Panes.Clear();
				if (workspace == null || string.IsNullOrEmpty(workspace.Layout))
				{
					return;
				}
				if (CommonShellPreferences.FloatingPanesWaitForLoad)
				{
					part_DockManager.FloatingWindowVisibility = FloatingWindowVisibility.Collapsed;
				}
				part_DockManager.InitializePaneContent += dockManager_InitializePaneContent;
				try
				{
					part_DockManager.LoadLayout(workspace.Layout);
				}
				finally
				{
					part_DockManager.InitializePaneContent -= dockManager_InitializePaneContent;
				}
				if (!part_DockManager.HasDocumentContentHost)
				{
					part_DockManager.Content = new DocumentContentHost();
				}
				foreach (ContentPane pane in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
				{
					ConfigureContentPane(pane);
				}
				foreach (WorkspaceScreenData screen in workspace.Screens)
				{
					if (string.IsNullOrEmpty(screen.ScreenFactoryKey))
					{
						continue;
					}
					ContentPane contentPane = FindContentPaneByName(screen.PaneName);
					if (contentPane != null)
					{
						ScreenState screenState = screen.ScreenState;
						if (screenState == null)
						{
							screenState = new ScreenState();
						}
						screenState.IsRestoreFromSavedLayout = true;
						try
						{
							LoadScreen(contentPane, screen.ScreenFactoryKey, screen.ScreenSubject, screen.ScreenState);
						}
						catch (Exception)
						{
						}
					}
				}
				List<ContentPane> list = new List<ContentPane>();
				foreach (ContentPane pane2 in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
				{
					if (pane2 != null && (pane2.Content == null || pane2.Content is RestoredScreenPlaceholder))
					{
						list.Add(pane2);
					}
				}
				foreach (ContentPane item in list)
				{
					item.CloseAction = PaneCloseAction.RemovePane;
					item.ExecuteCommand(ContentPaneCommands.Close);
				}
				if (!CommonShellPreferences.FloatingPanesWaitForLoad)
				{
					return;
				}
				foreach (ContentPane pane3 in part_DockManager.GetPanes(PaneNavigationOrder.ActivationOrder))
				{
					if (pane3 == null || string.IsNullOrWhiteSpace(pane3.Name))
					{
						continue;
					}
					PaneLocation paneLocation = XamDockManager.GetPaneLocation(pane3);
					if ((paneLocation == PaneLocation.Floating || paneLocation == PaneLocation.FloatingOnly) && !dictionary.ContainsKey(pane3.Name) && pane3.Parent is SplitPane splitPane)
					{
						System.Windows.Size floatingSize = XamDockManager.GetFloatingSize(splitPane);
						if (!floatingSize.IsEmpty && floatingSize.Width > 0.0 && floatingSize.Height > 0.0)
						{
							dictionary.Add(pane3.Name, floatingSize);
							XamDockManager.SetFloatingSize(splitPane, System.Windows.Size.Empty);
							splitPane.Height = floatingSize.Height;
							splitPane.Width = floatingSize.Width;
						}
					}
				}
			}
			finally
			{
				if (CommonShellPreferences.FloatingPanesWaitForLoad)
				{
					part_DockManager.FloatingWindowVisibility = FloatingWindowVisibility.Visible;
					foreach (KeyValuePair<string, System.Windows.Size> item2 in dictionary)
					{
						ContentPane contentPane2 = FindContentPaneByName(item2.Key);
						if (contentPane2 != null && contentPane2.Parent is SplitPane splitPane2)
						{
							System.Windows.Size value = item2.Value;
							if (splitPane2.ActualHeight > 0.0 && splitPane2.ActualWidth > 0.0)
							{
								XamDockManager.SetFloatingSize(splitPane2, new System.Windows.Size(splitPane2.ActualWidth, splitPane2.ActualHeight));
							}
							else if (!value.IsEmpty && value.Width > 0.0 && value.Height > 0.0)
							{
								XamDockManager.SetFloatingSize(splitPane2, value);
							}
							splitPane2.ClearValue(FrameworkElement.HeightProperty);
							splitPane2.ClearValue(FrameworkElement.WidthProperty);
						}
					}
				}
			}
		}

		private void dockManager_InitializePaneContent(object sender, InitializePaneContentEventArgs e)
		{
			e.NewPane.Content = new RestoredScreenPlaceholder();
		}
	}
	public class ScreenNavigationHistoryItem
	{
		public string Header { get; set; }

		public string ScreenFactoryKey { get; set; }

		public ScreenSubject ScreenSubject { get; set; }

		public ScreenState ScreenState { get; set; }
	}
	public class ScreenNavigationHistoryCollection : ObservableCollection<ScreenNavigationHistoryItem>
	{
		private const int MaxHistoryDepth = 50;

		public void PruneHistory()
		{
			while (base.Count > 50)
			{
				RemoveAt(base.Count - 1);
			}
		}
	}
	public class ScreenZoomTextConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null || value == DependencyProperty.UnsetValue || value.GetType() != typeof(double))
			{
				return "100%";
			}
			return ((int)Math.Round((double)value * 100.0)).ToString(CultureInfo.CurrentCulture) + "%";
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	[TemplatePart(Name = "PART_Slider", Type = typeof(Slider))]
	public class ScreenZoomControl : System.Windows.Controls.Control
	{
		public static readonly DependencyProperty ScreenProperty;

		public static readonly DependencyProperty ZoomMinimumProperty;

		public static readonly DependencyProperty ZoomMaximumProperty;

		public static readonly DependencyProperty ZoomSmallChangeProperty;

		public static readonly DependencyProperty ZoomLargeChangeProperty;

		public static readonly DependencyProperty ZoomProperty;

		private BoundCommand _boundZoomInCommand;

		private BoundCommand _boundZoomOutCommand;

		private BoundCommand _boundShowZoomDialogCommand;

		private BoundCommand _boundZoomToFitCommand;

		public static readonly DependencyProperty ZoomToFitDefaultVisibilityProperty;

		public static readonly DependencyProperty ZoomToFitVisibilityProperty;

		public static readonly DependencyProperty SliderValueProperty;

		public static readonly DependencyProperty SliderSmallChangeProperty;

		public static readonly DependencyProperty SliderLargeChangeProperty;

		private bool _ignoreRefreshZoomValue;

		private bool _ignoreRefreshSliderValue;

		public static readonly DependencyProperty ZoomEnabledProperty;

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public double ZoomMinimum
		{
			get
			{
				return (double)GetValue(ZoomMinimumProperty);
			}
			set
			{
				SetValue(ZoomMinimumProperty, value);
			}
		}

		public double ZoomMaximum
		{
			get
			{
				return (double)GetValue(ZoomMaximumProperty);
			}
			set
			{
				SetValue(ZoomMaximumProperty, value);
			}
		}

		public double ZoomSmallChange
		{
			get
			{
				return (double)GetValue(ZoomSmallChangeProperty);
			}
			set
			{
				SetValue(ZoomSmallChangeProperty, value);
			}
		}

		public double ZoomLargeChange
		{
			get
			{
				return (double)GetValue(ZoomLargeChangeProperty);
			}
			set
			{
				SetValue(ZoomLargeChangeProperty, value);
			}
		}

		public double Zoom
		{
			get
			{
				return (double)GetValue(ZoomProperty);
			}
			set
			{
				SetValue(ZoomProperty, value);
			}
		}

		public ICommand ZoomInCommand => _boundZoomInCommand;

		public ICommand ZoomOutCommand => _boundZoomOutCommand;

		public ICommand ShowZoomDialogCommand => _boundShowZoomDialogCommand;

		public ICommand ZoomToFitCommand => _boundZoomToFitCommand;

		public Visibility ZoomToFitDefaultVisibility
		{
			get
			{
				return (Visibility)GetValue(ZoomToFitDefaultVisibilityProperty);
			}
			set
			{
				SetValue(ZoomToFitDefaultVisibilityProperty, value);
			}
		}

		public Visibility ZoomToFitVisibility
		{
			get
			{
				return (Visibility)GetValue(ZoomToFitVisibilityProperty);
			}
			set
			{
				SetValue(ZoomToFitVisibilityProperty, value);
			}
		}

		public double SliderMinimum => 0.0;

		public double SliderMaximum => 1.0;

		public double SliderMidpoint => (SliderMinimum + SliderMaximum) / 2.0;

		public double ZoomMidpoint => 1.0;

		public double SliderValue
		{
			get
			{
				return (double)GetValue(SliderValueProperty);
			}
			set
			{
				SetValue(SliderValueProperty, value);
			}
		}

		public double SliderSmallChange
		{
			get
			{
				return (double)GetValue(SliderSmallChangeProperty);
			}
			set
			{
				SetValue(SliderSmallChangeProperty, value);
			}
		}

		public double SliderLargeChange
		{
			get
			{
				return (double)GetValue(SliderLargeChangeProperty);
			}
			set
			{
				SetValue(SliderLargeChangeProperty, value);
			}
		}

		public bool ZoomEnabled
		{
			get
			{
				return (bool)GetValue(ZoomEnabledProperty);
			}
			set
			{
				SetValue(ZoomEnabledProperty, value);
			}
		}

		static ScreenZoomControl()
		{
			ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(OnScreenPropertyChanged));
			ZoomMinimumProperty = DependencyProperty.Register("ZoomMinimum", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.1, OnZoomMinimumPropertyChanged));
			ZoomMaximumProperty = DependencyProperty.Register("ZoomMaximum", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(4.0, OnZoomMaximumPropertyChanged));
			ZoomSmallChangeProperty = DependencyProperty.Register("ZoomSmallChange", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.1, OnZoomSmallChangePropertyChanged));
			ZoomLargeChangeProperty = DependencyProperty.Register("ZoomLargeChange", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.1, OnZoomLargeChangePropertyChanged));
			ZoomProperty = DependencyProperty.Register("Zoom", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(1.0, OnZoomPropertyChanged));
			ZoomToFitDefaultVisibilityProperty = DependencyProperty.Register("ZoomToFitDefaultVisibility", typeof(Visibility), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(Visibility.Collapsed, OnZoomToFitDefaultVisibilityPropertyChanged));
			ZoomToFitVisibilityProperty = DependencyProperty.Register("ZoomToFitVisibility", typeof(Visibility), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(Visibility.Collapsed));
			SliderValueProperty = DependencyProperty.Register("SliderValue", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.5, OnSliderValuePropertyChanged));
			SliderSmallChangeProperty = DependencyProperty.Register("SliderSmallChange", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.1));
			SliderLargeChangeProperty = DependencyProperty.Register("SliderLargeChange", typeof(double), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(0.1));
			ZoomEnabledProperty = DependencyProperty.Register("ZoomEnabled", typeof(bool), typeof(ScreenZoomControl), new FrameworkPropertyMetadata(false));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(ScreenZoomControl), new FrameworkPropertyMetadata(typeof(ScreenZoomControl)));
		}

		public ScreenZoomControl()
		{
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.Zoom"),
				Mode = BindingMode.TwoWay
			});
			BindingOperations.SetBinding(this, ZoomMaximumProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomMaximum"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomMinimumProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomMinimum"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomEnabledProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomEnabled"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomSmallChangeProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomSmallChange"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomLargeChangeProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomLargeChange"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ZoomToFitDefaultVisibilityProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ZoomToFitDefaultVisibility"),
				Mode = BindingMode.OneWay
			});
			_boundZoomInCommand = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomInCommand"),
				Mode = BindingMode.OneWay
			});
			_boundZoomOutCommand = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomOutCommand"),
				Mode = BindingMode.OneWay
			});
			_boundShowZoomDialogCommand = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ShowZoomDialogCommand"),
				Mode = BindingMode.OneWay
			});
			_boundZoomToFitCommand = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomToFitCommand"),
				Mode = BindingMode.OneWay
			});
			_boundZoomToFitCommand.CommandChanged += _zoomToFitCommand_CommandChanged;
		}

		protected override AutomationPeer OnCreateAutomationPeer()
		{
			return new ScreenZoomControlAutomationPeer(this);
		}

		private static void OnScreenPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnScreenChanged(e.OldValue as ScreenContentControl, e.NewValue as ScreenContentControl);
			}
		}

		protected virtual void OnScreenChanged(ScreenContentControl oldScreen, ScreenContentControl newScreen)
		{
		}

		private static void OnZoomMinimumPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnZoomMinimumChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		private void OnZoomMinimumChanged(double oldValue, double newValue)
		{
			RefreshSliderValue();
		}

		private static void OnZoomMaximumPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnZoomMaximumChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		private void OnZoomMaximumChanged(double oldValue, double newValue)
		{
			RefreshSliderValue();
		}

		private static void OnZoomSmallChangePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnZoomSmallChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		protected virtual void OnZoomSmallChanged(double oldValue, double newValue)
		{
			RefreshSliderStepSizes();
		}

		private static void OnZoomLargeChangePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnZoomLargeChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		protected virtual void OnZoomLargeChanged(double oldValue, double newValue)
		{
			RefreshSliderStepSizes();
		}

		private static void OnZoomPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnZoomChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		protected virtual void OnZoomChanged(double oldValue, double newValue)
		{
			RefreshSliderValue();
		}

		private void _zoomToFitCommand_CommandChanged(object sender, EventArgs e)
		{
			UpdateZoomToFitVisibility();
		}

		private static void OnZoomToFitDefaultVisibilityPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.UpdateZoomToFitVisibility();
			}
		}

		private void UpdateZoomToFitVisibility()
		{
			ZoomToFitVisibility = ((_boundZoomToFitCommand.Command == null) ? ZoomToFitDefaultVisibility : Visibility.Visible);
		}

		private static void OnSliderValuePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenZoomControl screenZoomControl)
			{
				screenZoomControl.OnSliderValueChanged((double)args.OldValue, (double)args.NewValue);
			}
		}

		private void OnSliderValueChanged(double oldValue, double newValue)
		{
			RefreshZoomValue();
		}

		private void RefreshSliderValue()
		{
			if (_ignoreRefreshSliderValue)
			{
				return;
			}
			bool ignoreRefreshZoomValue = _ignoreRefreshZoomValue;
			try
			{
				_ignoreRefreshZoomValue = true;
				if (Zoom <= ZoomMinimum)
				{
					SliderValue = 0.0;
				}
				else if (Zoom >= ZoomMaximum)
				{
					SliderValue = 1.0;
				}
				else if (ZoomMinimum >= ZoomMidpoint || ZoomMaximum <= ZoomMidpoint)
				{
					SliderValue = (Zoom - ZoomMinimum) / (ZoomMaximum - ZoomMinimum);
				}
				else if (Zoom <= ZoomMidpoint)
				{
					SliderValue = SliderMinimum + (SliderMidpoint - SliderMinimum) * (Zoom - ZoomMinimum) / (ZoomMidpoint - ZoomMinimum);
				}
				else
				{
					SliderValue = SliderMidpoint + (SliderMaximum - SliderMidpoint) * (Zoom - ZoomMidpoint) / (ZoomMaximum - ZoomMidpoint);
				}
			}
			finally
			{
				_ignoreRefreshZoomValue = ignoreRefreshZoomValue;
			}
			RefreshSliderStepSizes();
		}

		private void RefreshZoomValue()
		{
			if (_ignoreRefreshZoomValue)
			{
				return;
			}
			bool ignoreRefreshSliderValue = _ignoreRefreshSliderValue;
			try
			{
				_ignoreRefreshSliderValue = true;
				if (SliderValue <= SliderMinimum)
				{
					Zoom = ZoomMinimum;
				}
				else if (SliderValue >= SliderMaximum)
				{
					Zoom = ZoomMaximum;
				}
				else if (ZoomMinimum >= ZoomMidpoint || ZoomMaximum <= ZoomMidpoint)
				{
					Zoom = ZoomMinimum + SliderValue * (ZoomMaximum - ZoomMinimum);
				}
				else if (SliderValue <= SliderMidpoint)
				{
					Zoom = ZoomMinimum + (ZoomMidpoint - ZoomMinimum) * (SliderValue - SliderMinimum) / (SliderMidpoint - SliderMinimum);
				}
				else
				{
					Zoom = ZoomMidpoint + (ZoomMaximum - ZoomMidpoint) * (SliderValue - SliderMidpoint) / (SliderMaximum - SliderMidpoint);
				}
			}
			finally
			{
				_ignoreRefreshSliderValue = ignoreRefreshSliderValue;
			}
			RefreshSliderStepSizes();
		}

		private void RefreshSliderStepSizes()
		{
			if (ZoomMinimum >= ZoomMidpoint || ZoomMaximum <= ZoomMidpoint)
			{
				SliderSmallChange = ZoomSmallChange * (SliderMaximum - SliderMinimum) / (ZoomMaximum - ZoomMinimum);
				SliderLargeChange = ZoomLargeChange * (SliderMaximum - SliderMinimum) / (ZoomMaximum - ZoomMinimum);
			}
			else if (Zoom <= ZoomMidpoint)
			{
				SliderSmallChange = ZoomSmallChange * (SliderMidpoint - SliderMinimum) / (ZoomMidpoint - ZoomMinimum);
				SliderLargeChange = ZoomLargeChange * (SliderMidpoint - SliderMinimum) / (ZoomMidpoint - ZoomMinimum);
			}
			else
			{
				SliderSmallChange = ZoomSmallChange * (SliderMaximum - SliderMidpoint) / (ZoomMaximum - ZoomMidpoint);
				SliderLargeChange = ZoomLargeChange * (SliderMaximum - SliderMidpoint) / (ZoomMaximum - ZoomMidpoint);
			}
		}
	}
	public class SelectedNavigationGroupChangingEventArgs : EventArgs
	{
		public NavigatorView CurrentGroup { get; set; }

		public NavigatorView NewGroup { get; set; }

		public bool Cancel { get; set; }

		public bool IsFromScreenSynchronization { get; set; }
	}
}
namespace AspenTech.Visualisation.CommonShell.RibbonTools
{
	public class CloseDocumentTool : ButtonTool
	{
		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(CloseDocumentTool), new PropertyMetadata(null, ShellWindowPropertyChanged));

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public CloseDocumentTool()
		{
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.CloseDocumentTool_Tooltip_Header,
				Content = CommonShellResources.CloseDocumentTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.RibbonCloseDocument_16;
			BindingOperations.SetBinding(this, ShellWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, UIElement.VisibilityProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("CloseDocumentButtonVisibility"),
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(this, "ShellWindow.CloseDocumentCommand");
		}

		private static void ShellWindowPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is CloseDocumentTool closeDocumentTool)
			{
				closeDocumentTool.OnShellWindowChanged(args.OldValue as CommonShellWindow, args.NewValue as CommonShellWindow);
			}
		}

		protected virtual void OnShellWindowChanged(CommonShellWindow oldValue, CommonShellWindow newValue)
		{
		}
	}
	public class ExpandCollapseRibbonTool : ButtonTool
	{
		public static readonly DependencyProperty IsRibbonMinimizedProperty = DependencyProperty.Register("IsRibbonMinimized", typeof(bool), typeof(ExpandCollapseRibbonTool), new PropertyMetadata(false, OnIsRibbonMinimizedPropertyChanged));

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public bool IsRibbonMinimized
		{
			get
			{
				return (bool)GetValue(IsRibbonMinimizedProperty);
			}
			set
			{
				SetValue(IsRibbonMinimizedProperty, value);
			}
		}

		public ExpandCollapseRibbonTool()
		{
			RefreshToolTipAndImage();
			BindingOperations.SetBinding(this, IsRibbonMinimizedProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(XamRibbon),
					AncestorLevel = 1
				},
				Path = new PropertyPath("IsMinimized"),
				Mode = BindingMode.TwoWay
			});
			base.Command = new ActionCommand(ConstructorCallback0_0);
		}

		private static void OnIsRibbonMinimizedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ExpandCollapseRibbonTool expandCollapseRibbonTool)
			{
				expandCollapseRibbonTool.OnIsRibbonMinimizedChanged((bool)args.OldValue, (bool)args.NewValue);
			}
		}

		protected virtual void OnIsRibbonMinimizedChanged(bool oldValue, bool newValue)
		{
			RefreshToolTipAndImage();
		}

		private void RefreshToolTipAndImage()
		{
			if (IsRibbonMinimized)
			{
				base.ToolTip = new XamRibbonScreenTip
				{
					Header = CommonShellResources.RibbonExpand_Tooltip_Header,
					Content = CommonShellResources.RibbonExpand_Tooltip_Content,
					FooterSeparatorVisibility = Visibility.Collapsed
				};
				base.LargeImage = ImageResources.RibbonExpand_16;
			}
			else
			{
				base.ToolTip = new XamRibbonScreenTip
				{
					Header = CommonShellResources.RibbonMinimize_Tooltip_Header,
					Content = CommonShellResources.RibbonMinimize_Tooltip_Content,
					FooterSeparatorVisibility = Visibility.Collapsed
				};
				base.LargeImage = ImageResources.RibbonCollapse_16;
			}
		}

		[CompilerGenerated]
		private void ConstructorCallback0_0()
		{
			IsRibbonMinimized = !IsRibbonMinimized;
		}
	}
	public class HelpButtonTool : ButtonTool
	{
		public HelpButtonTool()
		{
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.HelpButtonTool_Tooltip_Header,
				Content = CommonShellResources.HelpButtonTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.Help_16;
			base.Command = ApplicationCommands.Help;
		}
	}
	public class ManageSavedLayoutsDialog : Window, IComponentConnector
	{
		[CompilerGenerated]
		private sealed class Capture16_0
		{
			public ShellWorkspace selectedLayout;

			internal bool ExecuteRenameCommandCallback0(ShellWorkspace l)
			{
				return l != selectedLayout;
			}
		}

		[CompilerGenerated]
		private sealed class Capture16_1
		{
			public string layoutName;

			internal bool ExecuteRenameCommandCallback2(ShellWorkspace l)
			{
				return string.Equals(l.Name, layoutName, StringComparison.CurrentCulture);
			}
		}

		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<ShellWorkspace, string> CachedCallback16_1;

			public static Func<ShellWorkspace, string> CachedCallback40_0;

			internal string ExecuteRenameCommandCallback16_1(ShellWorkspace l)
			{
				return l.Name;
			}

			internal string ExecuteImportCommandCallback40_0(ShellWorkspace l)
			{
				return l.Name;
			}
		}

		[CompilerGenerated]
		private sealed class Capture40_0
		{
			public string layoutName;

			internal bool ExecuteImportCommandCallback1(ShellWorkspace l)
			{
				return string.Equals(l.Name, layoutName, StringComparison.CurrentCulture);
			}
		}

		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(ManageSavedLayoutsDialog), new PropertyMetadata(null, OnShellWindowPropertyChanged));

		internal ManageSavedLayoutsDialog root;

		internal System.Windows.Controls.ListBox _listBox;

		internal System.Windows.Controls.Button _renameButton;

		internal System.Windows.Controls.Button _moveUpButton;

		internal System.Windows.Controls.Button _moveDownButton;

		internal System.Windows.Controls.Button _deleteButton;

		internal System.Windows.Controls.Button _importButton;

		internal System.Windows.Controls.Button _exportButton;

		internal System.Windows.Controls.Button _closeButton;

		private bool _contentLoaded;

		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public ICommand RenameCommand { get; private set; }

		public ICommand DeleteCommand { get; private set; }

		public ICommand MoveUpCommand { get; private set; }

		public ICommand MoveDownCommand { get; private set; }

		public ICommand ImportCommand { get; private set; }

		public ICommand ExportCommand { get; private set; }

		public ManageSavedLayoutsDialog()
		{
			InitializeCommands();
			InitializeComponent();
			base.SourceInitialized += OnSourceInitialized;
			base.Loaded += OnLoaded;
		}

		private void OnLoaded(object sender, RoutedEventArgs e)
		{
			base.MinWidth = base.ActualWidth;
			base.MinHeight = base.ActualHeight;
		}

		private void _listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			RefreshCommands();
		}

		private void OnSourceInitialized(object sender, EventArgs e)
		{
			WindowHelpers.HideMinimizeAndMaximizeButtons(this);
		}

		private void InitializeCommands()
		{
			RenameCommand = new ActionCommand(ExecuteRenameCommand, CanExecuteRenameCommand);
			DeleteCommand = new ActionCommand(ExecuteDeleteCommand, CanExecuteDeleteCommand);
			MoveUpCommand = new ActionCommand(ExecuteMoveUpCommand, CanExecuteMoveUpCommand);
			MoveDownCommand = new ActionCommand(ExecuteMoveDownCommand, CanExecuteMoveDownCommand);
			ImportCommand = new ActionCommand(ExecuteImportCommand, CanExecuteImportCommand);
			ExportCommand = new ActionCommand(ExecuteExportCommand, CanExecuteExportCommand);
		}

		private void RefreshCommands()
		{
			(RenameCommand as ActionCommand).RaiseCanExecuteChanged();
			(DeleteCommand as ActionCommand).RaiseCanExecuteChanged();
			(MoveUpCommand as ActionCommand).RaiseCanExecuteChanged();
			(MoveDownCommand as ActionCommand).RaiseCanExecuteChanged();
			(ImportCommand as ActionCommand).RaiseCanExecuteChanged();
			(ExportCommand as ActionCommand).RaiseCanExecuteChanged();
		}

		private static void OnShellWindowPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ManageSavedLayoutsDialog manageSavedLayoutsDialog)
			{
				manageSavedLayoutsDialog.OnShellWindowChanged(args.OldValue as CommonShellWindow, args.NewValue as CommonShellWindow);
			}
		}

		protected virtual void OnShellWindowChanged(CommonShellWindow oldValue, CommonShellWindow newValue)
		{
			if (newValue != null)
			{
				base.Owner = ShellWindow;
				base.Icon = ShellWindow.Icon;
			}
		}

		private void ExecuteRenameCommand()
		{
			if (_listBox.SelectedItems == null || _listBox.SelectedItems.Count != 1)
			{
				return;
			}
			Capture16_0 Capture16Local = new Capture16_0();
			ShellWorkspaceCollection workspaces = ShellWindow.Application.RootWorkspaceFolder.Workspaces;
			Capture16Local.selectedLayout = _listBox.SelectedItems[0] as ShellWorkspace;
			if (Capture16Local.selectedLayout == null)
			{
				return;
			}
			IEnumerable<string> source = workspaces.Where(Capture16Local.ExecuteRenameCommandCallback0).Select(CachedDelegates.CachedCallback16_1 ?? (CachedDelegates.CachedCallback16_1 = CachedDelegates.Instance.ExecuteRenameCommandCallback16_1));
			SaveWorkspaceLayoutDialog saveWorkspaceLayoutDialog = new SaveWorkspaceLayoutDialog(ShellWindow, source.ToList(), isRename: true, Capture16Local.selectedLayout.Name)
			{
				Owner = this
			};
			if (saveWorkspaceLayoutDialog.ShowDialog() != true)
			{
				return;
			}
			Capture16_1 Capture16_2 = new Capture16_1();
			bool overwriteExisting = false;
			Capture16_2.layoutName = saveWorkspaceLayoutDialog.ValidatedLayoutName(out overwriteExisting);
			if (string.IsNullOrEmpty(Capture16_2.layoutName))
			{
				return;
			}
			if (overwriteExisting)
			{
				ShellWorkspace shellWorkspace = workspaces.FirstOrDefault(Capture16_2.ExecuteRenameCommandCallback2);
				if (shellWorkspace != null)
				{
					workspaces.Remove(shellWorkspace);
				}
			}
			string name = Capture16Local.selectedLayout.Name;
			Capture16Local.selectedLayout.Name = Capture16_2.layoutName;
			ShellWindow.ScreenLayoutRenamed(Capture16Local.selectedLayout, name);
		}

		private bool CanExecuteRenameCommand()
		{
			if (_listBox.SelectedItems != null)
			{
				return _listBox.SelectedItems.Count == 1;
			}
			return false;
		}

		private void ExecuteDeleteCommand()
		{
			if (_listBox.SelectedItems != null && _listBox.SelectedItems.Count > 0)
			{
				List<ShellWorkspace> list = new List<ShellWorkspace>();
				StringBuilder stringBuilder = new StringBuilder();
				bool flag = true;
				foreach (object selectedItem in _listBox.SelectedItems)
				{
					if (selectedItem is ShellWorkspace shellWorkspace)
					{
						list.Add(shellWorkspace);
						if (!flag)
						{
							stringBuilder.Append(", ");
						}
						stringBuilder.Append(shellWorkspace.Name);
						flag = false;
					}
				}
				if (list.Count > 0 && System.Windows.MessageBox.Show(this, string.Format(CultureInfo.CurrentCulture, CommonShellResources.ManageSavedLayouts_DeleteConfirmationText, stringBuilder.ToString()), CommonShellResources.ManageSavedLayouts_DeleteConfirmationTitle, MessageBoxButton.OKCancel, MessageBoxImage.Question, MessageBoxResult.OK) == MessageBoxResult.OK)
				{
					foreach (ShellWorkspace item in list)
					{
						ShellWindow.ScreenLayoutDeleted(item);
						ShellWindow.Application.RootWorkspaceFolder.Workspaces.Remove(item);
					}
				}
			}
			RefreshCommands();
		}

		private bool CanExecuteDeleteCommand()
		{
			return _listBox.SelectedItems.Count > 0;
		}

		private void ExecuteMoveUpCommand()
		{
			if (_listBox.SelectedItems != null && _listBox.SelectedItems.Count == 1 && _listBox.SelectedItems[0] is ShellWorkspace item)
			{
				ShellWorkspaceCollection workspaces = ShellWindow.Application.RootWorkspaceFolder.Workspaces;
				int num = workspaces.IndexOf(item);
				if (num > 0)
				{
					workspaces.RemoveAt(num);
					workspaces.Insert(num - 1, item);
					_listBox.SelectedIndex = num - 1;
				}
				RefreshCommands();
			}
		}

		private bool CanExecuteMoveUpCommand()
		{
			if (_listBox.SelectedItems != null && _listBox.SelectedItems.Count == 1)
			{
				return _listBox.SelectedIndex > 0;
			}
			return false;
		}

		private void ExecuteMoveDownCommand()
		{
			if (_listBox.SelectedItems != null && _listBox.SelectedItems.Count == 1 && _listBox.SelectedItems[0] is ShellWorkspace item)
			{
				ShellWorkspaceCollection workspaces = ShellWindow.Application.RootWorkspaceFolder.Workspaces;
				int num = workspaces.IndexOf(item);
				if (num >= 0 && num < workspaces.Count - 1)
				{
					workspaces.RemoveAt(num);
					workspaces.Insert(num + 1, item);
					_listBox.SelectedIndex = num + 1;
				}
				RefreshCommands();
			}
		}

		private bool CanExecuteMoveDownCommand()
		{
			if (_listBox.SelectedItems == null || _listBox.SelectedItems.Count != 1)
			{
				return false;
			}
			ShellWorkspaceCollection workspaces = ShellWindow.Application.RootWorkspaceFolder.Workspaces;
			if (_listBox.SelectedIndex >= 0)
			{
				return _listBox.SelectedIndex < workspaces.Count - 1;
			}
			return false;
		}

		private void ExecuteImportCommand()
		{
			Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
			openFileDialog.CheckFileExists = true;
			openFileDialog.CheckPathExists = true;
			openFileDialog.Filter = CommonShellResources.ManageSavedLayouts_ScreenLayout + " (*" + CommonShellPreferences.ScreenLayoutFileExtension + ") | *" + CommonShellPreferences.ScreenLayoutFileExtension + ";";
			openFileDialog.Title = CommonShellResources.ManageSavedLayouts_ImportTitle;
			if (openFileDialog.ShowDialog() == true)
			{
				string fileName = openFileDialog.FileName;
				if (File.Exists(fileName))
				{
					try
					{
						if (XamlServices.Parse(File.ReadAllText(fileName)) is ShellWorkspace[] array && array.Length != 0)
						{
							ShellWorkspaceCollection workspaces = ShellWindow.Application.RootWorkspaceFolder.Workspaces;
							IEnumerable<string> source = workspaces.Select(CachedDelegates.CachedCallback40_0 ?? (CachedDelegates.CachedCallback40_0 = CachedDelegates.Instance.ExecuteImportCommandCallback40_0));
							ShellWorkspace[] array2 = array;
							foreach (ShellWorkspace shellWorkspace in array2)
							{
								if (source.Contains(shellWorkspace.Name))
								{
									SaveWorkspaceLayoutDialog saveWorkspaceLayoutDialog = new SaveWorkspaceLayoutDialog(ShellWindow, source.ToList(), isRename: false, shellWorkspace.Name);
									if (saveWorkspaceLayoutDialog.ShowDialog() != true)
									{
										continue;
									}
									Capture40_0 Capture40Local = new Capture40_0();
									bool overwriteExisting = false;
									Capture40Local.layoutName = saveWorkspaceLayoutDialog.ValidatedLayoutName(out overwriteExisting);
									if (overwriteExisting)
									{
										ShellWorkspace shellWorkspace2 = workspaces.FirstOrDefault(Capture40Local.ExecuteImportCommandCallback1);
										if (shellWorkspace2 != null)
										{
											workspaces.Remove(shellWorkspace2);
										}
									}
									shellWorkspace.Name = Capture40Local.layoutName;
									workspaces.Add(shellWorkspace);
								}
								else
								{
									workspaces.Add(shellWorkspace);
								}
							}
						}
					}
					catch (Exception ex)
					{
						System.Windows.MessageBox.Show(string.Format(CommonShellResources.ManageSavedLayouts_ImportFailed + " {0}", ex.Message), CommonShellResources.ManageSavedLayouts_ExportFailedTitle, MessageBoxButton.OK, MessageBoxImage.Hand);
					}
				}
			}
			RefreshCommands();
		}

		private bool CanExecuteImportCommand()
		{
			return true;
		}

		private void ExecuteExportCommand()
		{
			if (_listBox.SelectedItems == null || _listBox.SelectedItems.Count <= 0)
			{
				return;
			}
			Microsoft.Win32.SaveFileDialog saveFileDialog = new Microsoft.Win32.SaveFileDialog();
			saveFileDialog.AddExtension = true;
			saveFileDialog.CheckFileExists = false;
			saveFileDialog.CheckPathExists = true;
			saveFileDialog.DefaultExt = CommonShellPreferences.ScreenLayoutFileExtension;
			ShellWorkspace shellWorkspace = _listBox.SelectedItems[0] as ShellWorkspace;
			saveFileDialog.FileName = ((shellWorkspace != null) ? shellWorkspace.Name : "");
			saveFileDialog.Filter = CommonShellResources.ManageSavedLayouts_ScreenLayout + " (*" + CommonShellPreferences.ScreenLayoutFileExtension + ") | *" + CommonShellPreferences.ScreenLayoutFileExtension + ";";
			saveFileDialog.Title = CommonShellResources.ManageSavedLayouts_ExportTitle;
			saveFileDialog.ValidateNames = true;
			if (saveFileDialog.ShowDialog(ShellWindow) != true)
			{
				return;
			}
			try
			{
				List<ShellWorkspace> list = new List<ShellWorkspace>();
				foreach (object selectedItem in _listBox.SelectedItems)
				{
					if (selectedItem is ShellWorkspace item)
					{
						list.Add(item);
					}
				}
				File.WriteAllText(saveFileDialog.FileName, XamlServices.Save(list.ToArray()));
			}
			catch (Exception ex)
			{
				System.Windows.MessageBox.Show(string.Format(CommonShellResources.ManageSavedLayouts_ExportFailed + " {0}", ex.Message), CommonShellResources.ManageSavedLayouts_ExportFailedTitle, MessageBoxButton.OK, MessageBoxImage.Hand);
			}
		}

		private bool CanExecuteExportCommand()
		{
			if (_listBox.SelectedItems != null)
			{
				return _listBox.SelectedItems.Count > 0;
			}
			return false;
		}

		private void _closeButton_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.CommonShell.Wpf;V31.0.0.5;component/ribbontools/managesavedlayoutsdialog.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
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
				root = (ManageSavedLayoutsDialog)target;
				break;
			case 2:
				_listBox = (System.Windows.Controls.ListBox)target;
				_listBox.SelectionChanged += _listBox_SelectionChanged;
				break;
			case 3:
				_renameButton = (System.Windows.Controls.Button)target;
				break;
			case 4:
				_moveUpButton = (System.Windows.Controls.Button)target;
				break;
			case 5:
				_moveDownButton = (System.Windows.Controls.Button)target;
				break;
			case 6:
				_deleteButton = (System.Windows.Controls.Button)target;
				break;
			case 7:
				_importButton = (System.Windows.Controls.Button)target;
				break;
			case 8:
				_exportButton = (System.Windows.Controls.Button)target;
				break;
			case 9:
				_closeButton = (System.Windows.Controls.Button)target;
				_closeButton.Click += _closeButton_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ManageSavedLayoutsTool : ButtonTool
	{
		public ManageSavedLayoutsTool()
		{
			base.Caption = CommonShellResources.ManageSavedLayoutsTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ManageSavedLayoutsTool_Tooltip_Header,
				Content = CommonShellResources.ManageSavedLayoutsTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.SmallImage = ImageResources.ManageLayouts_16;
			BindingOperations.SetBinding(this, System.Windows.Controls.Primitives.ButtonBase.CommandProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ManageSavedLayoutsCommand"),
				Mode = BindingMode.OneWay
			});
		}
	}
	public class NewMainWindowTool : ButtonTool
	{
		public NewMainWindowTool()
		{
			base.Caption = CommonShellResources.NewMainWindowTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.NewMainWindowTool_Tooltip_Header,
				Content = CommonShellResources.NewMainWindowTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.WindowNew_32;
			base.SmallImage = ImageResources.WindowNew_16;
			base.Command = CommonShellWindow.NewWindowCommand;
		}
	}
	public class SaveWorkspaceLayoutDialog : Window, IComponentConnector
	{
		[CompilerGenerated]
		private sealed class Capture33_0
		{
			public string layoutName;

			internal bool RefreshNameIsValidCallback0(string s)
			{
				return string.Equals(layoutName, s, StringComparison.CurrentCulture);
			}
		}

		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SaveWorkspaceLayoutDialog));

		public static readonly DependencyProperty ExistingNamesProperty = DependencyProperty.Register("ExistingNames", typeof(ICollection<string>), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(null));

		public static readonly DependencyProperty CanReplaceExistingProperty = DependencyProperty.Register("CanReplaceExisting", typeof(bool), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(false, OnCanReplaceExistingPropertyChanged));

		public static readonly DependencyProperty MaxNameLengthProperty = DependencyProperty.Register("MaxNameLength", typeof(int), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(50));

		public static readonly DependencyProperty NameIsValidProperty = DependencyProperty.Register("NameIsValid", typeof(bool), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(false));

		internal SaveWorkspaceLayoutDialog root;

		internal XamComboEditor _layoutNameTextBox;

		internal System.Windows.Controls.CheckBox _checkReplaceExisting;

		internal System.Windows.Controls.Button _saveWorkspaceButton;

		internal System.Windows.Controls.Button _cancelSaveWorkspaceButton;

		internal TextBlock _errorText;

		private bool _contentLoaded;

		public bool IsRename { get; private set; }

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public ICollection<string> ExistingNames
		{
			get
			{
				return GetValue(ExistingNamesProperty) as ICollection<string>;
			}
			set
			{
				SetValue(ExistingNamesProperty, value);
			}
		}

		public string LayoutNameTrimmed
		{
			get
			{
				string text = _layoutNameTextBox.Value as string;
				if (!string.IsNullOrEmpty(text))
				{
					string text2 = text.TrimEnd();
					if (!string.IsNullOrEmpty(text2))
					{
						text = text2;
					}
				}
				return text;
			}
		}

		public bool CanReplaceExisting
		{
			get
			{
				return (bool)GetValue(CanReplaceExistingProperty);
			}
			set
			{
				SetValue(CanReplaceExistingProperty, value);
			}
		}

		public int MaxNameLength
		{
			get
			{
				return (int)GetValue(MaxNameLengthProperty);
			}
			set
			{
				SetValue(MaxNameLengthProperty, value);
			}
		}

		public bool NameIsValid
		{
			get
			{
				return (bool)GetValue(NameIsValidProperty);
			}
			set
			{
				SetValue(NameIsValidProperty, value);
			}
		}

		public SaveWorkspaceLayoutDialog()
		{
			InitializeComponent();
			ExtraInitialize();
		}

		public SaveWorkspaceLayoutDialog(CommonShellWindow window, IList<string> existingNames, bool isRename = false, string defaultName = "")
		{
			ExistingNames = existingNames;
			base.Owner = (ShellWindow = window);
			IsRename = isRename;
			InitializeComponent();
			_layoutNameTextBox.Text = defaultName;
			ExtraInitialize();
		}

		private void ExtraInitialize()
		{
			if (base.Owner != null)
			{
				base.Icon = base.Owner.Icon;
			}
			if (IsRename)
			{
				base.Title = CommonShellResources.RenameLayout_DialogTitle;
				_saveWorkspaceButton.Content = CommonShellResources.RenameLayout_RenameButton;
			}
			_saveWorkspaceButton.Click += saveWorkspaceButton_Click;
			_cancelSaveWorkspaceButton.Click += cancelSaveWorkspaceButton_Click;
			_layoutNameTextBox.TextChanged += _layoutNameTextBox_TextChanged;
			RefreshNameIsValid();
		}

		private void root_Loaded(object sender, RoutedEventArgs e)
		{
			_layoutNameTextBox.StartEditMode();
		}

		private void _layoutNameTextBox_TextChanged(object sender, RoutedPropertyChangedEventArgs<string> e)
		{
			RefreshNameIsValid();
		}

		private static void OnCanReplaceExistingPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is SaveWorkspaceLayoutDialog saveWorkspaceLayoutDialog)
			{
				saveWorkspaceLayoutDialog.OnCanReplaceExistingChanged((bool)args.OldValue, (bool)args.NewValue);
			}
		}

		protected virtual void OnCanReplaceExistingChanged(bool oldValue, bool newValue)
		{
			RefreshNameIsValid();
		}

		private void RefreshNameIsValid()
		{
			Capture33_0 Capture33Local = new Capture33_0();
			bool nameIsValid = true;
			Capture33Local.layoutName = LayoutNameTrimmed;
			string message = string.Empty;
			if (ShellWindow != null && ShellWindow.CustomValidateLayoutName != null)
			{
				nameIsValid = ShellWindow.CustomValidateLayoutName(Capture33Local.layoutName, ExistingNames, CanReplaceExisting, out message);
			}
			else if (string.IsNullOrEmpty(Capture33Local.layoutName))
			{
				nameIsValid = false;
			}
			else if (Capture33Local.layoutName.Length > MaxNameLength)
			{
				nameIsValid = false;
				message = CommonShellResources.SaveLayout_NameTooLong;
			}
			else if (!char.IsLetterOrDigit(Capture33Local.layoutName[0]))
			{
				nameIsValid = false;
				message = CommonShellResources.SaveLayout_NameMustStartWithLetterOrDigit;
			}
			else if (!CanReplaceExisting && ExistingNames != null && !string.IsNullOrEmpty(ExistingNames.FirstOrDefault(Capture33Local.RefreshNameIsValidCallback0)))
			{
				nameIsValid = false;
				message = CommonShellResources.SaveLayout_NameIsDuplicate;
			}
			_errorText.Text = message;
			_errorText.Visibility = (string.IsNullOrEmpty(message) ? Visibility.Collapsed : Visibility.Visible);
			NameIsValid = nameIsValid;
		}

		public string ValidatedLayoutName(out bool overwriteExisting)
		{
			overwriteExisting = false;
			if (!NameIsValid)
			{
				return string.Empty;
			}
			string layoutNameTrimmed = LayoutNameTrimmed;
			if (ExistingNames.Contains(layoutNameTrimmed))
			{
				if (!CanReplaceExisting)
				{
					return string.Empty;
				}
				overwriteExisting = true;
			}
			return layoutNameTrimmed;
		}

		private void cancelSaveWorkspaceButton_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void saveWorkspaceButton_Click(object sender, RoutedEventArgs e)
		{
			if (NameIsValid)
			{
				base.DialogResult = true;
				Close();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "5.0.17.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Visualisation.CommonShell.Wpf;V31.0.0.5;component/ribbontools/savelayoutdialog.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
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
				root = (SaveWorkspaceLayoutDialog)target;
				root.Loaded += root_Loaded;
				break;
			case 2:
				_layoutNameTextBox = (XamComboEditor)target;
				break;
			case 3:
				_checkReplaceExisting = (System.Windows.Controls.CheckBox)target;
				break;
			case 4:
				_saveWorkspaceButton = (System.Windows.Controls.Button)target;
				break;
			case 5:
				_cancelSaveWorkspaceButton = (System.Windows.Controls.Button)target;
				break;
			case 6:
				_errorText = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SaveLayoutTool : ButtonTool
	{
		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SaveLayoutTool), new PropertyMetadata(null, ShellWindowPropertyChanged));

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public SaveLayoutTool()
		{
			base.Caption = CommonShellResources.SaveLayoutTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.SaveLayoutTool_Tooltip_Header,
				Content = CommonShellResources.SaveLayoutTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.ScreenLayoutSave_32;
			base.SmallImage = ImageResources.ScreenLayoutSave_16;
			BindingOperations.SetBinding(this, ShellWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(this, "ShellWindow.SaveScreenLayoutCommand");
		}

		private static void ShellWindowPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is SaveLayoutTool saveLayoutTool)
			{
				saveLayoutTool.OnShellWindowChanged(args.OldValue as CommonShellWindow, args.NewValue as CommonShellWindow);
			}
		}

		protected virtual void OnShellWindowChanged(CommonShellWindow oldValue, CommonShellWindow newValue)
		{
		}
	}
	public class ScreenNavigateBackwardTool : MenuTool
	{
		public static readonly DependencyProperty MainWindowProperty = DependencyProperty.Register("MainWindow", typeof(CommonShellWindow), typeof(ScreenNavigateBackwardTool));

		public static readonly DependencyProperty NavigationHistoryProperty = DependencyProperty.Register("NavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenNavigateBackwardTool), new PropertyMetadata(null, NavigationHistoryPropertyChanged));

		private ObservableCollection<ToolMenuItem> _navigationHistoryItems = new ObservableCollection<ToolMenuItem>();

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow MainWindow
		{
			get
			{
				return GetValue(MainWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(MainWindowProperty, value);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ScreenNavigationHistoryCollection NavigationHistory
		{
			get
			{
				return GetValue(NavigationHistoryProperty) as ScreenNavigationHistoryCollection;
			}
			set
			{
				SetValue(NavigationHistoryProperty, value);
			}
		}

		public IEnumerable<ToolMenuItem> NavigationHistoryMenuItems => _navigationHistoryItems;

		public ScreenNavigateBackwardTool()
		{
			base.ButtonType = MenuToolButtonType.Segmented;
			base.Caption = CommonShellResources.ScreenNavigateBackwardsTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ScreenNavigateBackwardsTool_Tooltip_Header,
				Content = CommonShellResources.ScreenNavigateBackwardsTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.NavigateBackward_32;
			base.SmallImage = ImageResources.NavigateBackward_16;
			base.IsEnabled = false;
			base.Click += menuTool_Click;
			BindingOperations.SetBinding(this, MainWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, NavigationHistoryProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveBackwardNavigationHistory"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ItemsControl.ItemsSourceProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("NavigationHistoryMenuItems"),
				Mode = BindingMode.OneWay
			});
		}

		private static void NavigationHistoryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenNavigateBackwardTool screenNavigateBackwardTool)
			{
				screenNavigateBackwardTool.OnNavigationHistoryChanged(args.OldValue as ScreenNavigationHistoryCollection, args.NewValue as ScreenNavigationHistoryCollection);
			}
		}

		protected virtual void OnNavigationHistoryChanged(ScreenNavigationHistoryCollection oldValue, ScreenNavigationHistoryCollection newValue)
		{
			if (oldValue != null)
			{
				oldValue.CollectionChanged += NavigationHistory_CollectionChanged;
			}
			if (newValue != null)
			{
				newValue.CollectionChanged += NavigationHistory_CollectionChanged;
			}
			RefreshMenu();
		}

		private void NavigationHistory_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			RefreshMenu();
		}

		private void RefreshMenu()
		{
			try
			{
				_navigationHistoryItems.Clear();
				if (NavigationHistory != null)
				{
					foreach (ScreenNavigationHistoryItem item in NavigationHistory)
					{
						ToolMenuItem toolMenuItem = new ToolMenuItem
						{
							Header = item.Header,
							Tag = item
						};
						toolMenuItem.Click += toolMenuItem_Click;
						_navigationHistoryItems.Add(toolMenuItem);
					}
				}
				base.IsEnabled = _navigationHistoryItems.Count > 0;
			}
			catch (Exception)
			{
			}
		}

		private void toolMenuItem_Click(object sender, RoutedEventArgs e)
		{
			ScreenNavigationHistoryItem item = (sender as ToolMenuItem).Tag as ScreenNavigationHistoryItem;
			if (MainWindow != null)
			{
				MainWindow.NavigateActiveHistoryBackward(item);
			}
		}

		private void menuTool_Click(object sender, RoutedEventArgs e)
		{
			if (MainWindow != null)
			{
				MainWindow.NavigateActiveHistoryBackward(null);
			}
		}
	}
	public class ScreenNavigateForwardTool : MenuTool
	{
		public static readonly DependencyProperty MainWindowProperty = DependencyProperty.Register("MainWindow", typeof(CommonShellWindow), typeof(ScreenNavigateForwardTool));

		public static readonly DependencyProperty NavigationHistoryProperty = DependencyProperty.Register("NavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenNavigateForwardTool), new PropertyMetadata(null, NavigationHistoryPropertyChanged));

		private ObservableCollection<ToolMenuItem> _navigationHistoryItems = new ObservableCollection<ToolMenuItem>();

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow MainWindow
		{
			get
			{
				return GetValue(MainWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(MainWindowProperty, value);
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public ScreenNavigationHistoryCollection NavigationHistory
		{
			get
			{
				return GetValue(NavigationHistoryProperty) as ScreenNavigationHistoryCollection;
			}
			set
			{
				SetValue(NavigationHistoryProperty, value);
			}
		}

		public IEnumerable<ToolMenuItem> NavigationHistoryMenuItems => _navigationHistoryItems;

		public ScreenNavigateForwardTool()
		{
			base.ButtonType = MenuToolButtonType.Segmented;
			base.Caption = CommonShellResources.ScreenNavigateForwardsTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ScreenNavigateForwardsTool_Tooltip_Header,
				Content = CommonShellResources.ScreenNavigateForwardsTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.NavigateForward_32;
			base.SmallImage = ImageResources.NavigateForward_16;
			base.IsEnabled = false;
			base.Click += menuTool_Click;
			BindingOperations.SetBinding(this, MainWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, NavigationHistoryProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveForwardNavigationHistory"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, ItemsControl.ItemsSourceProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("NavigationHistoryMenuItems"),
				Mode = BindingMode.OneWay
			});
		}

		private static void NavigationHistoryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is ScreenNavigateForwardTool screenNavigateForwardTool)
			{
				screenNavigateForwardTool.OnNavigationHistoryChanged(args.OldValue as ScreenNavigationHistoryCollection, args.NewValue as ScreenNavigationHistoryCollection);
			}
		}

		protected virtual void OnNavigationHistoryChanged(ScreenNavigationHistoryCollection oldValue, ScreenNavigationHistoryCollection newValue)
		{
			if (oldValue != null)
			{
				oldValue.CollectionChanged += NavigationHistory_CollectionChanged;
			}
			if (newValue != null)
			{
				newValue.CollectionChanged += NavigationHistory_CollectionChanged;
			}
			RefreshMenu();
		}

		private void NavigationHistory_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			RefreshMenu();
		}

		private void RefreshMenu()
		{
			try
			{
				_navigationHistoryItems.Clear();
				if (NavigationHistory != null)
				{
					foreach (ScreenNavigationHistoryItem item in NavigationHistory)
					{
						ToolMenuItem toolMenuItem = new ToolMenuItem
						{
							Header = item.Header,
							Tag = item
						};
						toolMenuItem.Click += toolMenuItem_Click;
						_navigationHistoryItems.Add(toolMenuItem);
					}
				}
				base.IsEnabled = _navigationHistoryItems.Count > 0;
			}
			catch (Exception)
			{
			}
		}

		private void toolMenuItem_Click(object sender, RoutedEventArgs e)
		{
			ScreenNavigationHistoryItem item = (sender as ToolMenuItem).Tag as ScreenNavigationHistoryItem;
			if (MainWindow != null)
			{
				MainWindow.NavigateActiveHistoryForward(item);
			}
		}

		private void menuTool_Click(object sender, RoutedEventArgs e)
		{
			if (MainWindow != null)
			{
				MainWindow.NavigateActiveHistoryForward(null);
			}
		}
	}
	public class SwitchLayoutTool : MenuTool
	{
		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SwitchLayoutTool), new PropertyMetadata(null, ShellWindowPropertyChanged));

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public SwitchLayoutTool()
		{
			base.Caption = CommonShellResources.SwitchLayoutTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.SwitchLayoutTool_Tooltip_Header,
				Content = CommonShellResources.SwitchLayoutTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.ScreenLayoutSwitch_32;
			base.SmallImage = ImageResources.ScreenLayoutSwitch_16;
			base.IsEnabled = true;
			BindingOperations.SetBinding(this, ShellWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			base.Opening += menuTool_Opening;
		}

		private static void ShellWindowPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is SwitchLayoutTool switchLayoutTool)
			{
				switchLayoutTool.OnShellWindowChanged(args.OldValue as CommonShellWindow, args.NewValue as CommonShellWindow);
			}
		}

		protected virtual void OnShellWindowChanged(CommonShellWindow oldValue, CommonShellWindow newValue)
		{
			if (oldValue != null && oldValue.Application is CommonShellApplication commonShellApplication)
			{
				commonShellApplication.RootWorkspaceFolder.Folders.CollectionChanged -= shellApplication_WorkspaceFolderContentsChanged;
				commonShellApplication.RootWorkspaceFolder.Workspaces.CollectionChanged -= shellApplication_WorkspaceFolderContentsChanged;
			}
			if (newValue != null)
			{
				if (newValue.Application is CommonShellApplication commonShellApplication2)
				{
					commonShellApplication2.RootWorkspaceFolder.Folders.CollectionChanged += shellApplication_WorkspaceFolderContentsChanged;
					commonShellApplication2.RootWorkspaceFolder.Workspaces.CollectionChanged += shellApplication_WorkspaceFolderContentsChanged;
				}
				base.Command = newValue.SwitchWorkspaceCommand;
			}
			RefreshMenu();
		}

		private void menuTool_Opening(object sender, ToolOpeningEventArgs e)
		{
			RefreshMenu();
		}

		private void shellApplication_WorkspaceFolderContentsChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			RefreshMenu();
		}

		public void RefreshMenu()
		{
			try
			{
				base.Items.Clear();
				if (ShellWindow == null || !(ShellWindow.Application is CommonShellApplication { RootWorkspaceFolder: var rootWorkspaceFolder }))
				{
					return;
				}
				foreach (ShellWorkspaceFolder folder in rootWorkspaceFolder.Folders)
				{
					ToolMenuItem toolMenuItem = new ToolMenuItem
					{
						Header = new TextBlock
						{
							Text = rootWorkspaceFolder.Name
						}
					};
					AddWorkspaceMenuItems(toolMenuItem, folder);
					base.Items.Add(toolMenuItem);
				}
				foreach (ShellWorkspace workspace in rootWorkspaceFolder.Workspaces)
				{
					base.Items.Add(new ToolMenuItem
					{
						Header = new TextBlock
						{
							Text = workspace.Name
						},
						Command = ShellWindow.SwitchWorkspaceCommand,
						CommandParameter = workspace
					});
				}
			}
			catch (Exception)
			{
			}
		}

		private void AddWorkspaceMenuItems(ToolMenuItem tool, ShellWorkspaceFolder folder)
		{
			foreach (ShellWorkspaceFolder folder2 in folder.Folders)
			{
				ToolMenuItem toolMenuItem = new ToolMenuItem
				{
					Header = new TextBlock
					{
						Text = folder.Name
					}
				};
				AddWorkspaceMenuItems(toolMenuItem, folder2);
				tool.Items.Add(toolMenuItem);
			}
			foreach (ShellWorkspace workspace in folder.Workspaces)
			{
				tool.Items.Add(new ToolMenuItem
				{
					Header = new TextBlock
					{
						Text = workspace.Name
					},
					Command = ShellWindow.SwitchWorkspaceCommand,
					CommandParameter = workspace
				});
			}
		}
	}
	public class SwitchScreenTool : MenuTool
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<ScreenContentControl, bool> CachedCallback8_0;

			internal bool RefreshMenuCallback8_0(ScreenContentControl screen)
			{
				return screen.IsDocumentScreen;
			}
		}

		public static readonly DependencyProperty ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SwitchScreenTool), new PropertyMetadata(null, ShellWindowPropertyChanged));

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		public CommonShellWindow ShellWindow
		{
			get
			{
				return GetValue(ShellWindowProperty) as CommonShellWindow;
			}
			set
			{
				SetValue(ShellWindowProperty, value);
			}
		}

		public SwitchScreenTool()
		{
			base.ButtonType = MenuToolButtonType.DropDown;
			base.Caption = CommonShellResources.SwitchScreenTool_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.SwitchScreenTool_Tooltip_Header,
				Content = CommonShellResources.SwitchScreenTool_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.ScreenSwitch_32;
			base.SmallImage = ImageResources.ScreenSwitch_16;
			base.IsEnabled = false;
			BindingOperations.SetBinding(this, ShellWindowProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Mode = BindingMode.OneWay
			});
			base.Opening += menuTool_Opening;
		}

		private static void ShellWindowPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			if (d is SwitchScreenTool switchScreenTool)
			{
				switchScreenTool.OnShellWindowChanged(args.OldValue as CommonShellWindow, args.NewValue as CommonShellWindow);
			}
		}

		protected virtual void OnShellWindowChanged(CommonShellWindow oldValue, CommonShellWindow newValue)
		{
			RefreshMenu();
		}

		private void menuTool_Opening(object sender, ToolOpeningEventArgs e)
		{
			RefreshMenu();
		}

		private void RefreshMenu()
		{
			try
			{
				base.Items.Clear();
				CommonShellWindow shellWindow = ShellWindow;
				if (shellWindow == null)
				{
					return;
				}
				foreach (ScreenContentControl item in shellWindow.SelectScreens(CachedDelegates.CachedCallback8_0 ?? (CachedDelegates.CachedCallback8_0 = CachedDelegates.Instance.RefreshMenuCallback8_0)))
				{
					ToolMenuItem toolMenuItem = new ToolMenuItem
					{
						Header = item.Header,
						Tag = item
					};
					toolMenuItem.Click += menuItem_Click;
					base.Items.Add(toolMenuItem);
				}
				ToolMenuItem toolMenuItem2 = new ToolMenuItem
				{
					Header = CommonShellResources.SwitchScreenTool_MenuNewScreenTab_Header,
					ToolTip = CommonShellResources.SwitchScreenTool_MenuNewScreenTab_Tooltip
				};
				toolMenuItem2.Click += newWindowMenuItem_Click;
				base.Items.Add(toolMenuItem2);
				base.IsEnabled = base.Items.Count > 0;
			}
			catch (Exception)
			{
			}
		}

		private void menuItem_Click(object sender, RoutedEventArgs e)
		{
			ScreenContentControl screen = (sender as ToolMenuItem).Tag as ScreenContentControl;
			ShellWindow?.ActivateScreen(screen);
		}

		private void newWindowMenuItem_Click(object sender, RoutedEventArgs e)
		{
			ShellWindow?.OpenNewScreenDocumentTab();
		}
	}
	public class SynchronizeNavigationBarTool : ButtonTool
	{
		public SynchronizeNavigationBarTool()
		{
			base.Caption = CommonShellResources.SynchronizeNavigationBar_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.SynchronizeNavigationBar_Tooltip_Header,
				Content = CommonShellResources.SynchronizeNavigationBar_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			base.LargeImage = ImageResources.NavigationSync_32;
			base.SmallImage = ImageResources.NavigationSync_16;
			base.Command = CommonShellWindow.SynchronizeNavigationBarCommand;
		}
	}
	public class Zoom100PctTool : ButtonTool
	{
		public static readonly DependencyProperty ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(Zoom100PctTool));

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public Zoom100PctTool()
		{
			base.LargeImage = ImageResources.Zoom100Pct_32;
			base.SmallImage = ImageResources.Zoom100Pct_16;
			base.Caption = CommonShellResources.Zoom100Pct_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.Zoom100Pct_Tooltip_Header,
				Content = CommonShellResources.Zoom100Pct_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			BindingOperations.SetBinding(this, UIElement.IsEnabledProperty, new System.Windows.Data.Binding
			{
				RelativeSource = RelativeSource.Self,
				Path = new PropertyPath("Screen.ZoomEnabled"),
				Mode = BindingMode.OneWay,
				FallbackValue = false
			});
			base.Click += OnClick;
		}

		protected override bool ShouldSerializeProperty(DependencyProperty dp)
		{
			if (dp == ScreenProperty || dp == UIElement.IsEnabledProperty)
			{
				return false;
			}
			return base.ShouldSerializeProperty(dp);
		}

		private void OnClick(object sender, RoutedEventArgs e)
		{
			ScreenContentControl screen = Screen;
			if (screen != null)
			{
				screen.Zoom = 1.0;
			}
		}
	}
	public class ZoomDialogTool : ButtonTool
	{
		public static readonly DependencyProperty ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomDialogTool));

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public ZoomDialogTool()
		{
			base.LargeImage = ImageResources.Zoom_32;
			base.SmallImage = ImageResources.Zoom_16;
			base.Caption = CommonShellResources.ZoomDialog_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ZoomDialog_Tooltip_Header,
				Content = CommonShellResources.ZoomDialog_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ShowZoomDialogCommand"),
				Mode = BindingMode.OneWay
			});
		}

		protected override bool ShouldSerializeProperty(DependencyProperty dp)
		{
			if (dp == System.Windows.Controls.Primitives.ButtonBase.CommandProperty || dp == ScreenProperty)
			{
				return false;
			}
			return base.ShouldSerializeProperty(dp);
		}
	}
	public class ZoomInTool : ButtonTool
	{
		public static readonly DependencyProperty ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomInTool));

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public ZoomInTool()
		{
			base.LargeImage = ImageResources.ZoomIn_32;
			base.SmallImage = ImageResources.ZoomIn_16;
			base.Caption = CommonShellResources.ZoomIn_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ZoomIn_Tooltip_Header,
				Content = CommonShellResources.ZoomIn_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomInCommand"),
				Mode = BindingMode.OneWay
			});
		}

		protected override bool ShouldSerializeProperty(DependencyProperty dp)
		{
			if (dp == System.Windows.Controls.Primitives.ButtonBase.CommandProperty || dp == ScreenProperty)
			{
				return false;
			}
			return base.ShouldSerializeProperty(dp);
		}
	}
	public class ZoomOutTool : ButtonTool
	{
		public static readonly DependencyProperty ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomOutTool));

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public ZoomOutTool()
		{
			base.LargeImage = ImageResources.ZoomOut_32;
			base.SmallImage = ImageResources.ZoomOut_16;
			base.Caption = CommonShellResources.ZoomOut_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ZoomOut_Tooltip_Header,
				Content = CommonShellResources.ZoomOut_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomOutCommand"),
				Mode = BindingMode.OneWay
			});
		}

		protected override bool ShouldSerializeProperty(DependencyProperty dp)
		{
			if (dp == System.Windows.Controls.Primitives.ButtonBase.CommandProperty || dp == ScreenProperty)
			{
				return false;
			}
			return base.ShouldSerializeProperty(dp);
		}
	}
	public class ZoomToFitTool : ButtonTool
	{
		public static readonly DependencyProperty ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomToFitTool));

		public ScreenContentControl Screen
		{
			get
			{
				return GetValue(ScreenProperty) as ScreenContentControl;
			}
			set
			{
				SetValue(ScreenProperty, value);
			}
		}

		public ZoomToFitTool()
		{
			base.LargeImage = ImageResources.ZoomToFit_32;
			base.SmallImage = ImageResources.ZoomToFit_16;
			base.Caption = CommonShellResources.ZoomToFit_Caption;
			base.ToolTip = new XamRibbonScreenTip
			{
				Header = CommonShellResources.ZoomToFit_Tooltip_Header,
				Content = CommonShellResources.ZoomToFit_Tooltip_Content,
				FooterSeparatorVisibility = Visibility.Collapsed
			};
			BindingOperations.SetBinding(this, ScreenProperty, new System.Windows.Data.Binding
			{
				RelativeSource = new RelativeSource
				{
					Mode = RelativeSourceMode.FindAncestor,
					AncestorType = typeof(CommonShellWindow),
					AncestorLevel = 1
				},
				Path = new PropertyPath("ActiveDocumentScreen"),
				Mode = BindingMode.OneWay
			});
			base.Command = new BoundCommand(new System.Windows.Data.Binding
			{
				Source = this,
				Path = new PropertyPath("Screen.ZoomToFitCommand"),
				Mode = BindingMode.OneWay
			});
		}

		protected override bool ShouldSerializeProperty(DependencyProperty dp)
		{
			if (dp == ScreenProperty)
			{
				return false;
			}
			return base.ShouldSerializeProperty(dp);
		}
	}
}
namespace AspenTech.Visualisation.CommonShell.RibbonSupport
{
	internal class ContextualTabGroupReplacement : ContextualTabGroup
	{
		internal XamRibbon MergedRibbon { get; private set; }

		internal ContextualTabGroupReplacement(XamRibbon merged)
		{
			MergedRibbon = merged;
		}
	}
	internal class RibbonTabReplacement : RibbonTabItem
	{
		internal RibbonTabItem Replacement { get; set; }

		internal ICollection<RibbonTabItem> OriginalParentCollection { get; set; }
	}
	internal class RibbonGroupReplacement : RibbonGroup
	{
		internal RibbonGroup ReplacementGroupFromMergingTab { get; set; }

		internal RibbonGroup HostGroupBeingReplaced { get; set; }

		internal RibbonTabItem HostTab { get; set; }
	}
	internal class ContextualRibbonInternal : DependencyObject
	{
		internal static readonly DependencyProperty ActivatedContextualTabsProperty = DependencyProperty.RegisterAttached("IsRegisteredRibbon", typeof(List<string>), typeof(ContextualRibbonInternal), new PropertyMetadata(null));

		internal static List<string> GetActivatedContextualTabs(DependencyObject target)
		{
			return target.GetValue(ActivatedContextualTabsProperty) as List<string>;
		}

		internal static void SetActivatedContextualTabs(DependencyObject target, List<string> value)
		{
			target.SetValue(ActivatedContextualTabsProperty, value);
		}

		internal static bool RecordContextualTabActivation(ScreenContentControl screen, string contextId)
		{
			if (screen == null)
			{
				return false;
			}
			bool flag = true;
			List<string> activatedContextualTabs = GetActivatedContextualTabs(screen);
			if (activatedContextualTabs == null)
			{
				activatedContextualTabs = new List<string>();
				activatedContextualTabs.Add(contextId);
				SetActivatedContextualTabs(screen, activatedContextualTabs);
				flag = true;
			}
			else
			{
				flag = !activatedContextualTabs.Contains(contextId, StringComparer.Ordinal);
				if (flag)
				{
					activatedContextualTabs.Add(contextId);
				}
			}
			return flag;
		}
	}
	internal class ContextualRibbonManager : IWeakEventListener
	{
		[CompilerGenerated]
		private sealed class Capture25_0
		{
			public string name;

			public Func<RibbonTabItem, bool> CachedCallback1;

			internal bool TryToSelectRibbonTabCallback0(RibbonTabItem t)
			{
				if (t.Visibility == Visibility.Visible)
				{
					return string.Equals(GetTabKey(t), name, StringComparison.CurrentCulture);
				}
				return false;
			}

			internal bool TryToSelectRibbonTabCallback1(RibbonTabItem t)
			{
				return string.Compare(GetTabKey(t), name, StringComparison.OrdinalIgnoreCase) == 0;
			}
		}

		private ScreenContentControl _activeScreen;

		private readonly Func<string, System.Windows.Media.Color> _getContentColorFunc;

		private readonly Dictionary<string, string> _cachedTabSelection = new Dictionary<string, string>();

		private readonly List<XamRibbon> _mergedContextualRibbons = new List<XamRibbon>();

		private IEnumerable<object> _contextualRibbons;

		private bool _contextualRibbonUpdatePending;

		private IEnumerable<string> _requiredContextualTabs;

		private bool _visibleContextualTabsUpdatePending;

		private readonly XamRibbon _hostRibbon;

		public ScreenContentControl ActiveScreen
		{
			get
			{
				return _activeScreen;
			}
			set
			{
				if (_activeScreen == value)
				{
					return;
				}
				_activeScreen = value;
				IEnumerable<object> enumerable = null;
				IEnumerable<string> requiredContextualTabs = null;
				if (_activeScreen != null)
				{
					requiredContextualTabs = _activeScreen.RequiredContextualTabs;
					enumerable = _activeScreen.ContextualRibbons;
					if (enumerable == null)
					{
						enumerable = ContextualRibbon.GetContextualRibbons(_activeScreen);
					}
				}
				ContextualRibbons = enumerable;
				RequiredContextualTabs = requiredContextualTabs;
			}
		}

		private IEnumerable<string> RequiredContextualTabs
		{
			get
			{
				return _requiredContextualTabs;
			}
			set
			{
				if (_requiredContextualTabs != value)
				{
					if (_requiredContextualTabs is INotifyCollectionChanged source)
					{
						CollectionChangedEventManager.RemoveListener(source, this);
					}
					_requiredContextualTabs = value;
					if (_requiredContextualTabs is INotifyCollectionChanged source2)
					{
						CollectionChangedEventManager.AddListener(source2, this);
					}
					DelayUpdateVisibleContextualTabs();
				}
			}
		}

		private IEnumerable<object> ContextualRibbons
		{
			get
			{
				return _contextualRibbons;
			}
			set
			{
				if (_contextualRibbons != value)
				{
					if (_contextualRibbons is INotifyCollectionChanged source)
					{
						CollectionChangedEventManager.RemoveListener(source, this);
					}
					_contextualRibbons = value;
					if (_contextualRibbons is INotifyCollectionChanged source2)
					{
						CollectionChangedEventManager.AddListener(source2, this);
					}
					DelayUpdateContextualRibbons();
				}
			}
		}

		private string SelectedTabKey => GetTabKey(_hostRibbon.SelectedTab);

		public ContextualRibbonManager(XamRibbon hostRibbon, Func<string, System.Windows.Media.Color> getContentColorFunc)
		{
			_hostRibbon = hostRibbon;
			_getContentColorFunc = getContentColorFunc;
		}

		private void DelayUpdateVisibleContextualTabs()
		{
			if (!_visibleContextualTabsUpdatePending)
			{
				_visibleContextualTabsUpdatePending = true;
				_hostRibbon.Dispatcher.BeginInvoke(new Action(UpdateVisibleContextualTabs), DispatcherPriority.Normal);
			}
		}

		private void UpdateVisibleContextualTabs()
		{
			_visibleContextualTabsUpdatePending = false;
			string selectedTabKey = SelectedTabKey;
			List<ContextualTabGroup> list = new List<ContextualTabGroup>();
			foreach (ContextualTabGroup contextualTabGroup2 in _hostRibbon.ContextualTabGroups)
			{
				if (contextualTabGroup2 is ContextualTabGroupReplacement)
				{
					continue;
				}
				string key = contextualTabGroup2.Key;
				if (string.IsNullOrEmpty(key))
				{
					continue;
				}
				bool flag = false;
				if (_requiredContextualTabs != null)
				{
					foreach (string requiredContextualTab in _requiredContextualTabs)
					{
						if (string.Equals(requiredContextualTab, contextualTabGroup2.Key, StringComparison.OrdinalIgnoreCase))
						{
							flag = true;
							break;
						}
					}
				}
				if (flag)
				{
					list.Add(contextualTabGroup2);
				}
				else if (contextualTabGroup2.IsVisible)
				{
					if (IsTabOfTabGroup(selectedTabKey, contextualTabGroup2))
					{
						_cachedTabSelection[key] = selectedTabKey;
					}
					else
					{
						_cachedTabSelection.Remove(key);
					}
				}
				contextualTabGroup2.IsVisible = flag;
			}
			ContextualTabGroup contextualTabGroup = list.Where(UpdateVisibleContextualTabsCallback9_0).FirstOrDefault();
			foreach (ContextualTabGroup item in list)
			{
				bool flag2 = ContextualRibbonInternal.RecordContextualTabActivation(ActiveScreen, item.Key);
				if (contextualTabGroup != null)
				{
					continue;
				}
				switch (ContextualRibbon.GetRibbonFocusStrategy(item))
				{
				case ContextualRibbonFocusStrategy.FirstActivation:
					if (flag2)
					{
						contextualTabGroup = item;
					}
					break;
				case ContextualRibbonFocusStrategy.Always:
					contextualTabGroup = item;
					break;
				}
			}
			bool flag3 = false;
			if (contextualTabGroup != null)
			{
				if (!_cachedTabSelection.TryGetValue(contextualTabGroup.Key, out var value))
				{
					switch (ContextualRibbon.GetRibbonFocusStrategy(contextualTabGroup))
					{
					case ContextualRibbonFocusStrategy.FirstActivation:
					case ContextualRibbonFocusStrategy.Always:
						if (!IsTabOfTabGroup(selectedTabKey, contextualTabGroup))
						{
							value = (_cachedTabSelection[contextualTabGroup.Key] = FirstTabOfTabGroup(contextualTabGroup));
						}
						break;
					}
				}
				if (!string.IsNullOrWhiteSpace(value) && IsContextualTabFromTabGroup(contextualTabGroup, value))
				{
					flag3 = TryToSelectRibbonTab(value);
				}
			}
			if (!flag3)
			{
				TryToSelectRibbonTab(selectedTabKey);
			}
		}

		private void DelayUpdateContextualRibbons()
		{
			if (!_contextualRibbonUpdatePending)
			{
				_contextualRibbonUpdatePending = true;
				_hostRibbon.Dispatcher.BeginInvoke(new Action(UpdateContextualRibbons), DispatcherPriority.Normal);
			}
		}

		private void UpdateContextualRibbons()
		{
			try
			{
				TryUpdateContextualRibbons();
			}
			catch (Exception)
			{
			}
		}

		private void TryUpdateContextualRibbons()
		{
			_contextualRibbonUpdatePending = false;
			List<XamRibbon> list = new List<XamRibbon>();
			foreach (XamRibbon mergedContextualRibbon in _mergedContextualRibbons)
			{
				if (_contextualRibbons == null || !_contextualRibbons.Contains(mergedContextualRibbon))
				{
					list.Add(mergedContextualRibbon);
				}
			}
			foreach (XamRibbon item in list)
			{
				_mergedContextualRibbons.Remove(item);
				string ribbonContextId = ContextualRibbon.GetRibbonContextId(item);
				if (!string.IsNullOrEmpty(ribbonContextId))
				{
					_cachedTabSelection[ribbonContextId] = SelectedTabKey;
				}
				RemoveMergedRibbon(item);
			}
			if (_contextualRibbons == null)
			{
				return;
			}
			string selectedTabKey = SelectedTabKey;
			List<XamRibbon> list2 = new List<XamRibbon>();
			foreach (XamRibbon contextualRibbon in _contextualRibbons)
			{
				if (contextualRibbon == null || _mergedContextualRibbons.Contains(contextualRibbon))
				{
					continue;
				}
				string text = ContextualRibbon.GetRibbonContextId(contextualRibbon);
				if (string.IsNullOrEmpty(text))
				{
					text = ContextualRibbon.GetRibbonContextCaption(contextualRibbon);
					if (string.IsNullOrEmpty(text))
					{
						Trace.WriteLine(string.Format(CultureInfo.InvariantCulture, "Contextual Ribbon {0} has no ContextualRibbon.ContextId or ContextualRibbon.ContextCaption assigned", contextualRibbon.Name), "Warning");
						text = Guid.NewGuid().ToString();
					}
					ContextualRibbon.SetRibbonContextId(contextualRibbon, text);
				}
				bool flag = ContextualRibbonInternal.RecordContextualTabActivation(ActiveScreen, text);
				string value = string.Empty;
				_cachedTabSelection.TryGetValue(text, out value);
				if (string.IsNullOrEmpty(value))
				{
					_cachedTabSelection[text] = FirstTabOfRibbon(contextualRibbon);
				}
				else
				{
					switch (ContextualRibbon.GetRibbonFocusStrategy(contextualRibbon))
					{
					case ContextualRibbonFocusStrategy.FirstActivation:
						if (flag && !IsTabOfRibbon(value, contextualRibbon))
						{
							_cachedTabSelection[text] = FirstTabOfRibbon(contextualRibbon);
						}
						break;
					case ContextualRibbonFocusStrategy.Always:
						if (!IsTabOfRibbon(value, contextualRibbon))
						{
							_cachedTabSelection[text] = FirstTabOfRibbon(contextualRibbon);
						}
						break;
					}
				}
				list2.Add(contextualRibbon);
				_mergedContextualRibbons.Add(contextualRibbon);
				MergeRibbon(contextualRibbon);
			}
			bool flag2 = false;
			if (list2.Count > 0)
			{
				foreach (XamRibbon item2 in list2)
				{
					string ribbonContextId2 = ContextualRibbon.GetRibbonContextId(item2);
					string value2 = string.Empty;
					_cachedTabSelection.TryGetValue(ribbonContextId2, out value2);
					if (IsContextualTab(value2))
					{
						flag2 = TryToSelectRibbonTab(value2);
						if (flag2)
						{
							break;
						}
					}
				}
			}
			if (!flag2)
			{
				TryToSelectRibbonTab(selectedTabKey);
			}
		}

		private static string FirstTabOfTabGroup(ContextualTabGroup tabGroup)
		{
			if (tabGroup == null || tabGroup.Tabs == null)
			{
				return string.Empty;
			}
			foreach (RibbonTabItem tab in tabGroup.Tabs)
			{
				if (tab.Visibility == Visibility.Visible)
				{
					string tabKey = GetTabKey(tab);
					if (!string.IsNullOrEmpty(tabKey))
					{
						return tabKey;
					}
				}
			}
			return string.Empty;
		}

		private static string FirstTabOfRibbon(XamRibbon ribbon)
		{
			if (ribbon == null || ribbon.Tabs == null)
			{
				return string.Empty;
			}
			foreach (RibbonTabItem tab in ribbon.Tabs)
			{
				if (tab.Visibility == Visibility.Visible)
				{
					string tabKey = GetTabKey(tab);
					if (!string.IsNullOrEmpty(tabKey))
					{
						return tabKey;
					}
				}
			}
			return string.Empty;
		}

		private static bool IsTabOfTabGroup(string tabName, ContextualTabGroup tabGroup)
		{
			if (tabGroup == null || tabGroup.Tabs == null)
			{
				return false;
			}
			foreach (RibbonTabItem tab in tabGroup.Tabs)
			{
				if (tab.Visibility == Visibility.Visible)
				{
					string tabKey = GetTabKey(tab);
					if (string.Equals(tabName, tabKey, StringComparison.Ordinal))
					{
						return true;
					}
				}
			}
			return false;
		}

		private static bool IsTabOfRibbon(string tabName, XamRibbon ribbon)
		{
			if (ribbon == null || ribbon.Tabs == null)
			{
				return false;
			}
			foreach (RibbonTabItem tab in ribbon.Tabs)
			{
				if (tab.Visibility == Visibility.Visible)
				{
					string tabKey = GetTabKey(tab);
					if (string.Equals(tabName, tabKey, StringComparison.Ordinal))
					{
						return true;
					}
				}
			}
			return false;
		}

		private static string GetTabKey(RibbonTabItem tab)
		{
			string text = tab?.Name;
			if (string.IsNullOrWhiteSpace(text))
			{
				text = tab?.Header?.ToString() ?? string.Empty;
			}
			return text;
		}

		private static bool IsContextualTabFromTabGroup(ContextualTabGroup tabGroup, string name)
		{
			if (string.IsNullOrEmpty(name) || tabGroup == null)
			{
				return false;
			}
			foreach (RibbonTabItem tab in tabGroup.Tabs)
			{
				if (string.Equals(GetTabKey(tab), name, StringComparison.CurrentCulture))
				{
					return true;
				}
			}
			return false;
		}

		private bool IsContextualTab(string name)
		{
			if (string.IsNullOrEmpty(name) || _mergedContextualRibbons == null || _mergedContextualRibbons.Count == 0)
			{
				return false;
			}
			foreach (XamRibbon mergedContextualRibbon in _mergedContextualRibbons)
			{
				foreach (RibbonTabItem tab in mergedContextualRibbon.Tabs)
				{
					if (string.Equals(GetTabKey(tab), name, StringComparison.CurrentCulture))
					{
						return true;
					}
					if (tab is RibbonTabReplacement { Replacement: not null } ribbonTabReplacement && string.Equals(GetTabKey(ribbonTabReplacement.Replacement), name, StringComparison.CurrentCulture))
					{
						return true;
					}
				}
			}
			return false;
		}

		private bool TryToSelectRibbonTab(string name)
		{
			Capture25_0 Capture25Local = new Capture25_0();
			Capture25Local.name = name;
			if (_hostRibbon == null || _hostRibbon.IsMinimized)
			{
				return false;
			}
			if (string.IsNullOrEmpty(Capture25Local.name))
			{
				return false;
			}
			RibbonTabItem ribbonTabItem = _hostRibbon.Tabs.FirstOrDefault(Capture25Local.TryToSelectRibbonTabCallback0);
			if (ribbonTabItem != null)
			{
				ribbonTabItem.IsSelected = true;
				return true;
			}
			foreach (ContextualTabGroup contextualTabGroup in _hostRibbon.ContextualTabGroups)
			{
				ribbonTabItem = contextualTabGroup.Tabs.FirstOrDefault(Capture25Local.CachedCallback1 ?? (Capture25Local.CachedCallback1 = Capture25Local.TryToSelectRibbonTabCallback1));
				if (ribbonTabItem != null)
				{
					_hostRibbon.SelectedTab = ribbonTabItem;
					return true;
				}
			}
			return false;
		}

		private void RemoveMergedRibbon(XamRibbon ribbon)
		{
			for (int i = 0; i < _hostRibbon.ContextualTabGroups.Count; i++)
			{
				if (_hostRibbon.ContextualTabGroups[i] is ContextualTabGroupReplacement contextualTabGroupReplacement && contextualTabGroupReplacement.MergedRibbon == ribbon)
				{
					_hostRibbon.ContextualTabGroups.RemoveAt(i);
					break;
				}
			}
			for (int j = 0; j < ribbon.Tabs.Count; j++)
			{
				RibbonTabItem ribbonTabItem = ribbon.Tabs[j];
				if (ribbonTabItem is RibbonTabReplacement { Replacement: var replacement })
				{
					if (replacement.Parent is XamRibbon xamRibbon)
					{
						if (xamRibbon.Tabs.Contains(replacement))
						{
							xamRibbon.Tabs.Remove(replacement);
						}
						else
						{
							foreach (ContextualTabGroup contextualTabGroup in xamRibbon.ContextualTabGroups)
							{
								if (contextualTabGroup.Tabs.Contains(replacement))
								{
									contextualTabGroup.Tabs.Remove(replacement);
									break;
								}
							}
						}
					}
					ribbon.Tabs.RemoveAt(j);
					ribbon.Tabs.Insert(j, replacement);
					ribbonTabItem = replacement;
				}
				RibbonGroupCollection ribbonGroups = ribbonTabItem.RibbonGroups;
				for (int k = 0; k < ribbonGroups.Count; k++)
				{
					if (ribbonGroups[k] is RibbonGroupReplacement { ReplacementGroupFromMergingTab: var replacementGroupFromMergingTab } ribbonGroupReplacement)
					{
						ribbonGroupReplacement.HostTab.RibbonGroups.Remove(replacementGroupFromMergingTab);
						ribbonGroupReplacement.HostGroupBeingReplaced.Visibility = Visibility.Visible;
						ribbonGroups.RemoveAt(k);
						ribbonGroups.Insert(k, replacementGroupFromMergingTab);
					}
				}
			}
			for (int l = 0; l < _hostRibbon.ContextualTabGroups.Count; l++)
			{
				if (_hostRibbon.ContextualTabGroups[l] is ContextualTabGroupReplacement contextualTabGroupReplacement2 && contextualTabGroupReplacement2.MergedRibbon == ribbon)
				{
					_hostRibbon.ContextualTabGroups.RemoveAt(l);
					break;
				}
			}
		}

		private void MergeRibbon(XamRibbon mergingRibbon)
		{
			string ribbonContextCaption = ContextualRibbon.GetRibbonContextCaption(mergingRibbon);
			System.Windows.Media.Color? color = ContextualRibbon.GetRibbonContextColor(mergingRibbon);
			if (!color.HasValue)
			{
				color = GetContextualRibbonColor(ribbonContextCaption);
			}
			MergeRibbonTabs(mergingRibbon, ribbonContextCaption, color.Value, mergingRibbon.Tabs);
			foreach (ContextualTabGroup contextualTabGroup in mergingRibbon.ContextualTabGroups)
			{
				System.Windows.Media.Color contextColour = (contextualTabGroup.BaseBackColor.HasValue ? contextualTabGroup.BaseBackColor.Value : GetContextualRibbonColor(contextualTabGroup.Caption));
				MergeRibbonTabs(mergingRibbon, contextualTabGroup.Caption, contextColour, contextualTabGroup.Tabs);
			}
		}

		private void MergeRibbonTabs(XamRibbon mergingRibbon, string contextTitle, System.Windows.Media.Color contextColour, IList<RibbonTabItem> tabs)
		{
			ContextualTabGroup contextualTabGroup = null;
			for (int i = 0; i < tabs.Count; i++)
			{
				RibbonTabItem ribbonTabItem = tabs[i];
				if (ribbonTabItem is RibbonTabReplacement)
				{
					continue;
				}
				bool flag = true;
				RibbonGroupCollection ribbonGroups = ribbonTabItem.RibbonGroups;
				for (int j = 0; j < ribbonGroups.Count; j++)
				{
					if (!(ribbonGroups[j] is RibbonGroupReplacement) && !MergeGroupToHost(ribbonTabItem, j))
					{
						flag = false;
					}
				}
				if (!flag)
				{
					tabs.RemoveAt(i);
					tabs.Insert(i, new RibbonTabReplacement
					{
						Visibility = Visibility.Collapsed,
						Replacement = ribbonTabItem,
						OriginalParentCollection = tabs
					});
					if (contextualTabGroup == null)
					{
						contextualTabGroup = new ContextualTabGroupReplacement(mergingRibbon);
						contextualTabGroup.Caption = contextTitle;
						contextualTabGroup.BaseBackColor = contextColour;
						_hostRibbon.ContextualTabGroups.Add(contextualTabGroup);
					}
					ribbonTabItem.IsSelected = false;
					contextualTabGroup.Tabs.Add(ribbonTabItem);
				}
			}
		}

		private bool MergeGroupToHost(RibbonTabItem mergingTab, int mergeGroupIndex)
		{
			foreach (RibbonTabItem tab in _hostRibbon.Tabs)
			{
				if (MergeGroupToHostTab(tab, mergingTab, mergeGroupIndex))
				{
					return true;
				}
			}
			foreach (ContextualTabGroup contextualTabGroup in _hostRibbon.ContextualTabGroups)
			{
				foreach (RibbonTabItem tab2 in contextualTabGroup.Tabs)
				{
					if (MergeGroupToHostTab(tab2, mergingTab, mergeGroupIndex))
					{
						return true;
					}
				}
			}
			return false;
		}

		private static bool MergeGroupToHostTab(RibbonTabItem hostTab, RibbonTabItem mergingTab, int mergeGroupIndex)
		{
			RibbonGroup ribbonGroup = mergingTab.RibbonGroups[mergeGroupIndex];
			if (ribbonGroup.Visibility == Visibility.Collapsed)
			{
				return true;
			}
			string caption = ribbonGroup.Caption;
			if (string.IsNullOrEmpty(caption))
			{
				return false;
			}
			RibbonGroupCollection ribbonGroups = hostTab.RibbonGroups;
			RibbonGroupCollection ribbonGroups2 = mergingTab.RibbonGroups;
			for (int i = 0; i < ribbonGroups.Count; i++)
			{
				RibbonGroup ribbonGroup2 = ribbonGroups[i];
				if (ribbonGroup2.Caption == caption)
				{
					ribbonGroup2.Visibility = Visibility.Collapsed;
					ribbonGroups2.RemoveAt(mergeGroupIndex);
					ribbonGroups2.Insert(mergeGroupIndex, new RibbonGroupReplacement
					{
						Visibility = Visibility.Collapsed,
						ReplacementGroupFromMergingTab = ribbonGroup,
						HostGroupBeingReplaced = ribbonGroup2,
						HostTab = hostTab
					});
					ribbonGroups.Insert(i, ribbonGroup);
					return true;
				}
			}
			return false;
		}

		private System.Windows.Media.Color GetContextualRibbonColor(string ribbonId)
		{
			if (_getContentColorFunc == null)
			{
				return Colors.Blue;
			}
			return _getContentColorFunc(ribbonId);
		}

		public bool ReceiveWeakEvent(Type managerType, object sender, EventArgs e)
		{
			bool result = false;
			if (managerType == typeof(CollectionChangedEventManager))
			{
				result = true;
				if (sender == ContextualRibbons)
				{
					DelayUpdateContextualRibbons();
				}
				else if (sender == RequiredContextualTabs)
				{
					DelayUpdateVisibleContextualTabs();
				}
			}
			return result;
		}

		[CompilerGenerated]
		private bool UpdateVisibleContextualTabsCallback9_0(ContextualTabGroup t)
		{
			string value;
			return _cachedTabSelection.TryGetValue(t.Key, out value);
		}
	}
}
namespace AspenTech.Visualisation.CommonShell.Internal
{
	internal struct Win32Point
	{
		public int X;

		public int Y;
	}
	internal static class NativeMethods
	{
		[DllImport("user32.dll")]
		internal static extern int SetWindowLong(IntPtr hwnd, int index, int value);

		[DllImport("user32.dll")]
		internal static extern int GetWindowLong(IntPtr hwnd, int index);

		[DllImport("user32.dll")]
		[return: MarshalAs(UnmanagedType.Bool)]
		internal static extern bool GetCursorPos(ref Win32Point pt);

		public static System.Windows.Point? GetTrueMousePosition(Visual relativeTo)
		{
			if (PresentationSource.FromVisual(relativeTo) != null)
			{
				Win32Point pt = default(Win32Point);
				GetCursorPos(ref pt);
				return relativeTo.PointFromScreen(new System.Windows.Point(pt.X, pt.Y));
			}
			return null;
		}
	}
	internal static class WindowHelpers
	{
		internal static void HideMinimizeAndMaximizeButtons(Window window)
		{
			IntPtr handle = new WindowInteropHelper(window).Handle;
			long num = NativeMethods.GetWindowLong(handle, -16);
			NativeMethods.SetWindowLong(handle, -16, (int)(num & -131073 & -65537));
		}
	}
}
namespace AspenTech.Visualisation.CommonShell.AutomationPeers
{
	public class CommonShellWindowUIACommandProcessor : UIABaseCommandProcessor
	{
		public CommonShellWindowUIACommandProcessor(CommonShellWindow owner, IValueProvider baseValueProvider)
			: base(owner, baseValueProvider)
		{
		}
	}
	public class CommonShellWindowAutomationPeer : WindowAutomationPeer
	{
		private IValueProvider _valueProviderImpl;

		public CommonShellWindow CommonShellWindow => base.Owner as CommonShellWindow;

		public CommonShellWindowAutomationPeer(CommonShellWindow owner)
			: base(owner)
		{
		}

		protected override string GetClassNameCore()
		{
			return "CommonShellWindow";
		}

		public override object GetPattern(PatternInterface patternInterface)
		{
			object obj = null;
			if (patternInterface == PatternInterface.Value)
			{
				if (_valueProviderImpl == null)
				{
					_valueProviderImpl = new CommonShellWindowUIACommandProcessor(CommonShellWindow, base.GetPattern(patternInterface) as IValueProvider);
				}
				return _valueProviderImpl;
			}
			return base.GetPattern(patternInterface);
		}
	}
	public class NavigatorBarUIACommandProcessor : UIABaseCommandProcessor
	{
		private NavigatorBar NavigatorBar => base.Owner as NavigatorBar;

		public NavigatorBarUIACommandProcessor(NavigatorBar owner, IValueProvider baseValueProvider)
			: base(owner, baseValueProvider)
		{
		}

		protected override string ProcessUIACommand(string commandKey, string commandData)
		{
			if (string.IsNullOrEmpty(commandKey))
			{
				return null;
			}
			string text = null;
			if (commandKey.ToUpperInvariant() == "SELECTGROUP")
			{
				return ProcessSelectGroupCommand(commandData);
			}
			return base.ProcessUIACommand(commandKey, commandData);
		}

		private string ProcessSelectGroupCommand(string commandData)
		{
			foreach (NavigatorView navigatorView in NavigatorBar.NavigatorViews)
			{
				if (string.Equals(navigatorView.Key, commandData, StringComparison.Ordinal) || string.Equals(navigatorView.Header.ToString(), commandData, StringComparison.CurrentCulture))
				{
					navigatorView.IsSelected = true;
					return "true";
				}
			}
			return "false";
		}
	}
	public class NavigatorBarAutomationPeer : UIACustomControlAutomationPeer
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<FrameworkElement, string> CachedCallback0_0;

			public static Func<FrameworkElement, IValueProvider, IValueProvider> CachedCallback0_1;

			internal string ConstructorCallback0_0(FrameworkElement control)
			{
				return (control as NavigatorBar).Name;
			}

			internal IValueProvider ConstructorCallback0_1(FrameworkElement control, IValueProvider baseValueProvider)
			{
				return new NavigatorBarUIACommandProcessor(control as NavigatorBar, baseValueProvider);
			}
		}

		public NavigatorBarAutomationPeer(NavigatorBar owner)
			: base(owner)
		{
			base.ClassName = "NavigatorBar";
			base.GetNameFunction = CachedDelegates.CachedCallback0_0 ?? (CachedDelegates.CachedCallback0_0 = CachedDelegates.Instance.ConstructorCallback0_0);
			base.CreateCustomCommandProcessorFunction = CachedDelegates.CachedCallback0_1 ?? (CachedDelegates.CachedCallback0_1 = CachedDelegates.Instance.ConstructorCallback0_1);
		}
	}
	public class ScreenManagerUIACommandProcessor : UIABaseCommandProcessor
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<ScreenContentControl, bool> CachedCallback4_0;

			internal bool ProcessCloseAllScreensCommandCallback4_0(ScreenContentControl s)
			{
				return true;
			}
		}

		[CompilerGenerated]
		private sealed class Capture5_0
		{
			public string commandData;

			internal bool ProcessActivateScreenCommandCallback0(ScreenContentControl s)
			{
				return string.Equals(s.Header, commandData);
			}
		}

		private ScreenManager ScreenManager => base.Owner as ScreenManager;

		public ScreenManagerUIACommandProcessor(ScreenManager owner, IValueProvider baseValueProvider)
			: base(owner, baseValueProvider)
		{
		}

		protected override string ProcessUIACommand(string commandKey, string commandData)
		{
			if (string.IsNullOrEmpty(commandKey))
			{
				return null;
			}
			string text = null;
			string text2 = commandKey.ToUpperInvariant();
			if (!(text2 == "ACTIVATESCREEN"))
			{
				if (text2 == "CLOSEALLSCREENS")
				{
					return ProcessCloseAllScreensCommand(commandData);
				}
				return base.ProcessUIACommand(commandKey, commandData);
			}
			return ProcessActivateScreenCommand(commandData);
		}

		private string ProcessCloseAllScreensCommand(string commandData)
		{
			bool forceClose = false;
			if (string.Equals(commandData, "ForceClose", StringComparison.OrdinalIgnoreCase))
			{
				forceClose = true;
			}
			CancelEventArgs e = new CancelEventArgs();
			ScreenManager.CloseScreens(CachedDelegates.CachedCallback4_0 ?? (CachedDelegates.CachedCallback4_0 = CachedDelegates.Instance.ProcessCloseAllScreensCommandCallback4_0), e, forceClose, includeInternal: true);
			if (!e.Cancel)
			{
				return "true";
			}
			return "false";
		}

		private string ProcessActivateScreenCommand(string commandData)
		{
			Capture5_0 Capture5Local = new Capture5_0();
			Capture5Local.commandData = commandData;
			ScreenContentControl screenContentControl = ScreenManager.FindScreen(Capture5Local.ProcessActivateScreenCommandCallback0, includeInternal: true);
			if (screenContentControl != null)
			{
				screenContentControl.Activate();
				return "true";
			}
			return "false";
		}
	}
	public class ScreenManagerAutomationPeer : UIACustomControlAutomationPeer
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<FrameworkElement, string> CachedCallback0_0;

			public static Func<FrameworkElement, IValueProvider, IValueProvider> CachedCallback0_1;

			internal string ConstructorCallback0_0(FrameworkElement control)
			{
				return (control as ScreenManager).Name;
			}

			internal IValueProvider ConstructorCallback0_1(FrameworkElement control, IValueProvider baseValueProvider)
			{
				return new ScreenManagerUIACommandProcessor(control as ScreenManager, baseValueProvider);
			}
		}

		public ScreenManagerAutomationPeer(ScreenManager owner)
			: base(owner)
		{
			base.ClassName = "ScreenManager";
			base.GetNameFunction = CachedDelegates.CachedCallback0_0 ?? (CachedDelegates.CachedCallback0_0 = CachedDelegates.Instance.ConstructorCallback0_0);
			base.CreateCustomCommandProcessorFunction = CachedDelegates.CachedCallback0_1 ?? (CachedDelegates.CachedCallback0_1 = CachedDelegates.Instance.ConstructorCallback0_1);
		}
	}
	public class ScreenZoomControlAutomationPeer : UIACustomControlAutomationPeer
	{
		[Serializable]
		[CompilerGenerated]
		private sealed class CachedDelegates
		{
			public static readonly CachedDelegates Instance = new CachedDelegates();

			public static Func<FrameworkElement, string> CachedCallback0_0;

			internal string ConstructorCallback0_0(FrameworkElement control)
			{
				return (control as ScreenZoomControl).Name;
			}
		}

		public ScreenZoomControlAutomationPeer(ScreenZoomControl owner)
			: base(owner)
		{
			base.ClassName = "ScreenZoomControl";
			base.GetNameFunction = CachedDelegates.CachedCallback0_0 ?? (CachedDelegates.CachedCallback0_0 = CachedDelegates.Instance.ConstructorCallback0_0);
		}
	}
}
namespace AspenTech.Visualisation.CommonShell.AspenSplashInterop
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("5ec5eb42-13e3-11d3-840d-000000000000")]
	internal interface ISplashWindow
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void ShowSplash([In][MarshalAs(UnmanagedType.BStr)] string title, [In][MarshalAs(UnmanagedType.BStr)] string subtitle, [In][MarshalAs(UnmanagedType.I2)] short majorVersion, [In][MarshalAs(UnmanagedType.I2)] short minorVersion, [In][MarshalAs(UnmanagedType.I2)] short copyrightFrom, [In][MarshalAs(UnmanagedType.I2)] short copyrightTo, [In][MarshalAs(UnmanagedType.BStr)] string license);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetStatusText([In][MarshalAs(UnmanagedType.BStr)] string status);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetLicenseeText([In][MarshalAs(UnmanagedType.BStr)] string licensee);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void AddToRecentAppList([In][MarshalAs(UnmanagedType.BStr)] string appPath, [In][MarshalAs(UnmanagedType.BStr)] string appTitle);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void AddToRecentDocList([In][MarshalAs(UnmanagedType.BStr)] string documentPath, [In][MarshalAs(UnmanagedType.BStr)] string appOpenWith);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void TestUserRegistration();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void HideSplash();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void SetSplashTimeout([In][MarshalAs(UnmanagedType.I2)] short nTimeout);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void CheckLicenseExpiration([In][MarshalAs(UnmanagedType.BStr)] string license);

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void ShowSplash2([In][MarshalAs(UnmanagedType.BStr)] string title, [In][MarshalAs(UnmanagedType.BStr)] string subtitle, [In][MarshalAs(UnmanagedType.BStr)] string version, [In][MarshalAs(UnmanagedType.I2)] short copyrightFrom, [In][MarshalAs(UnmanagedType.I2)] short copyrightTo, [In][MarshalAs(UnmanagedType.BStr)] string license);
	}
}
namespace AspenTech.Visualisation.CommonShell.AspenHelpAboutInterop
{
	[ComImport]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	[Guid("70BBA394-4F38-421A-BDB4-89D022A2515A")]
	internal interface IAspenAboutBox
	{
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(1)]
		void Show();

		[DispId(2)]
		string AppName
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(2)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(2)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(3)]
		string AppCopyright
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(3)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(3)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(4)]
		string BeginCopyDate
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(4)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(4)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(5)]
		string EndCopyDate
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(5)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(5)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(6)]
		string AppVersion
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(6)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(6)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(7)]
		string ExternalVersion
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(7)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(7)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(8)]
		int LicenseView
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(8)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(8)]
			[param: In]
			set;
		}

		[DispId(9)]
		string Legal
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(9)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(9)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}

		[DispId(10)]
		string LicenseInfo
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(10)]
			[return: MarshalAs(UnmanagedType.BStr)]
			get;
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(10)]
			[param: In]
			[param: MarshalAs(UnmanagedType.BStr)]
			set;
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000006 AspenTech.Visualisation.CommonShell.CommonShellApplication.add_PropertyChanged
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

// 0x06000007 AspenTech.Visualisation.CommonShell.CommonShellApplication.remove_PropertyChanged
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

// 0x0600004e AspenTech.Visualisation.CommonShell.CommonShellContentHost..cctor
// using System.Windows;
// using Microsoft.Practices.Unity;
//
// static CommonShellContentHost()
// {
// 	SuppressAllShellRibbonButtonsProperty = DependencyProperty.Register("SuppressAllShellRibbonButtons", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));
// 	SuppressAllShellRibbonAddInsProperty = DependencyProperty.Register("SuppressAllShellRibbonAddIns", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));
// 	SuppressWorkspaceButtonsProperty = DependencyProperty.Register("SuppressWorkspaceButtons", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));
// 	SuppressHelpButtonProperty = DependencyProperty.Register("SuppressHelpButton", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));
// 	SuppressCloseDocumentButtonProperty = DependencyProperty.Register("SuppressCloseDocumentButton", typeof(bool), typeof(CommonShellContentHost), new PropertyMetadata(false));
// 	ContainerProperty = DependencyProperty.Register("Container", typeof(IUnityContainer), typeof(CommonShellContentHost), new PropertyMetadata(null, OnContainerPropertyChanged));
// 	NavigatorBarPropertyKey = DependencyProperty.RegisterReadOnly("NavigatorBar", typeof(NavigatorBar), typeof(CommonShellContentHost), new PropertyMetadata(null));
// 	NavigatorBarProperty = NavigatorBarPropertyKey.DependencyProperty;
// 	ScreenManagerPropertyKey = DependencyProperty.RegisterReadOnly("ScreenManager", typeof(ScreenManager), typeof(CommonShellContentHost), new PropertyMetadata(null));
// 	ScreenManagerProperty = ScreenManagerPropertyKey.DependencyProperty;
// 	ActivationContentProperty = DependencyProperty.Register("ActivationContent", typeof(FrameworkElement), typeof(CommonShellContentHost), new PropertyMetadata(null));
// }

// 0x0600005f AspenTech.Visualisation.CommonShell.CommonShellViewRegistry..ctor
// using System;
// using Microsoft.Practices.Composite;
// using Microsoft.Practices.Unity;
//
// public CommonShellViewRegistry()
// {
// 	_registeredContent = new ListDictionary<string, Func<IUnityContainer, object>>();
// 	base..ctor();
// }

// 0x06000148 AspenTech.Visualisation.CommonShell.ImageResources..cctor
// using System.Collections.Generic;
// using System.Reflection;
// using System.Windows.Media;
//
// static ImageResources()
// {
// 	ThisAssemblyName = Assembly.GetAssembly(typeof(ImageResources)).FullName;
// 	_imageSources = new Dictionary<string, ImageSource>();
// }

// 0x06000169 AspenTech.Visualisation.CommonShell.NavigatorBar.add_SelectedGroupChanging
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<SelectedNavigationGroupChangingEventArgs> eventHandler = this.SelectedGroupChanging;
// 	EventHandler<SelectedNavigationGroupChangingEventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<SelectedNavigationGroupChangingEventArgs> value2 = (EventHandler<SelectedNavigationGroupChangingEventArgs>)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.SelectedGroupChanging, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x0600016a AspenTech.Visualisation.CommonShell.NavigatorBar.remove_SelectedGroupChanging
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<SelectedNavigationGroupChangingEventArgs> eventHandler = this.SelectedGroupChanging;
// 	EventHandler<SelectedNavigationGroupChangingEventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<SelectedNavigationGroupChangingEventArgs> value2 = (EventHandler<SelectedNavigationGroupChangingEventArgs>)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.SelectedGroupChanging, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x060001ce AspenTech.Visualisation.CommonShell.ScreenNavigationHistoryItem..ctor
// public ScreenNavigationHistoryItem()
// {
// }

// 0x060001d0 AspenTech.Visualisation.CommonShell.ScreenNavigationHistoryCollection..ctor
// public ScreenNavigationHistoryCollection()
// {
// }

// 0x060001d3 AspenTech.Visualisation.CommonShell.ScreenZoomTextConverter..ctor
// public ScreenZoomTextConverter()
// {
// }

// 0x06000213 AspenTech.Visualisation.CommonShell.SelectedNavigationGroupChangingEventArgs..ctor
// public SelectedNavigationGroupChangingEventArgs()
// {
// }

// 0x06000219 AspenTech.Visualisation.CommonShell.RibbonTools.CloseDocumentTool..cctor
// using System.Windows;
//
// static CloseDocumentTool()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(CloseDocumentTool), new PropertyMetadata(null, ShellWindowPropertyChanged));
// }

// 0x06000220 AspenTech.Visualisation.CommonShell.RibbonTools.ExpandCollapseRibbonTool..cctor
// using System.Windows;
//
// static ExpandCollapseRibbonTool()
// {
// 	IsRibbonMinimizedProperty = DependencyProperty.Register("IsRibbonMinimized", typeof(bool), typeof(ExpandCollapseRibbonTool), new PropertyMetadata(false, OnIsRibbonMinimizedPropertyChanged));
// }

// 0x06000248 AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog..cctor
// using System.Windows;
//
// static ManageSavedLayoutsDialog()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(ManageSavedLayoutsDialog), new PropertyMetadata(null, OnShellWindowPropertyChanged));
// }

// 0x06000265 AspenTech.Visualisation.CommonShell.RibbonTools.SaveWorkspaceLayoutDialog..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static SaveWorkspaceLayoutDialog()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SaveWorkspaceLayoutDialog));
// 	ExistingNamesProperty = DependencyProperty.Register("ExistingNames", typeof(ICollection<string>), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(null));
// 	CanReplaceExistingProperty = DependencyProperty.Register("CanReplaceExisting", typeof(bool), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(false, OnCanReplaceExistingPropertyChanged));
// 	MaxNameLengthProperty = DependencyProperty.Register("MaxNameLength", typeof(int), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(50));
// 	NameIsValidProperty = DependencyProperty.Register("NameIsValid", typeof(bool), typeof(SaveWorkspaceLayoutDialog), new FrameworkPropertyMetadata(false));
// }

// 0x0600026b AspenTech.Visualisation.CommonShell.RibbonTools.SaveLayoutTool..cctor
// using System.Windows;
//
// static SaveLayoutTool()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SaveLayoutTool), new PropertyMetadata(null, ShellWindowPropertyChanged));
// }

// 0x06000278 AspenTech.Visualisation.CommonShell.RibbonTools.ScreenNavigateBackwardTool..cctor
// using System.Windows;
//
// static ScreenNavigateBackwardTool()
// {
// 	MainWindowProperty = DependencyProperty.Register("MainWindow", typeof(CommonShellWindow), typeof(ScreenNavigateBackwardTool));
// 	NavigationHistoryProperty = DependencyProperty.Register("NavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenNavigateBackwardTool), new PropertyMetadata(null, NavigationHistoryPropertyChanged));
// }

// 0x06000285 AspenTech.Visualisation.CommonShell.RibbonTools.ScreenNavigateForwardTool..cctor
// using System.Windows;
//
// static ScreenNavigateForwardTool()
// {
// 	MainWindowProperty = DependencyProperty.Register("MainWindow", typeof(CommonShellWindow), typeof(ScreenNavigateForwardTool));
// 	NavigationHistoryProperty = DependencyProperty.Register("NavigationHistory", typeof(ScreenNavigationHistoryCollection), typeof(ScreenNavigateForwardTool), new PropertyMetadata(null, NavigationHistoryPropertyChanged));
// }

// 0x0600028f AspenTech.Visualisation.CommonShell.RibbonTools.SwitchLayoutTool..cctor
// using System.Windows;
//
// static SwitchLayoutTool()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SwitchLayoutTool), new PropertyMetadata(null, ShellWindowPropertyChanged));
// }

// 0x06000299 AspenTech.Visualisation.CommonShell.RibbonTools.SwitchScreenTool..cctor
// using System.Windows;
//
// static SwitchScreenTool()
// {
// 	ShellWindowProperty = DependencyProperty.Register("ShellWindow", typeof(CommonShellWindow), typeof(SwitchScreenTool), new PropertyMetadata(null, ShellWindowPropertyChanged));
// }

// 0x060002a0 AspenTech.Visualisation.CommonShell.RibbonTools.Zoom100PctTool..cctor
// using System.Windows;
//
// static Zoom100PctTool()
// {
// 	ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(Zoom100PctTool));
// }

// 0x060002a5 AspenTech.Visualisation.CommonShell.RibbonTools.ZoomDialogTool..cctor
// using System.Windows;
//
// static ZoomDialogTool()
// {
// 	ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomDialogTool));
// }

// 0x060002aa AspenTech.Visualisation.CommonShell.RibbonTools.ZoomInTool..cctor
// using System.Windows;
//
// static ZoomInTool()
// {
// 	ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomInTool));
// }

// 0x060002af AspenTech.Visualisation.CommonShell.RibbonTools.ZoomOutTool..cctor
// using System.Windows;
//
// static ZoomOutTool()
// {
// 	ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomOutTool));
// }

// 0x060002b4 AspenTech.Visualisation.CommonShell.RibbonTools.ZoomToFitTool..cctor
// using System.Windows;
//
// static ZoomToFitTool()
// {
// 	ScreenProperty = DependencyProperty.Register("Screen", typeof(ScreenContentControl), typeof(ZoomToFitTool));
// }

// 0x060002bc AspenTech.Visualisation.CommonShell.RibbonSupport.RibbonTabReplacement..ctor
// public RibbonTabReplacement()
// {
// }

// 0x060002c3 AspenTech.Visualisation.CommonShell.RibbonSupport.RibbonGroupReplacement..ctor
// public RibbonGroupReplacement()
// {
// }

// 0x060002c7 AspenTech.Visualisation.CommonShell.RibbonSupport.ContextualRibbonInternal..ctor
// public ContextualRibbonInternal()
// {
// }

// 0x060002c8 AspenTech.Visualisation.CommonShell.RibbonSupport.ContextualRibbonInternal..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static ContextualRibbonInternal()
// {
// 	ActivatedContextualTabsProperty = DependencyProperty.RegisterAttached("IsRegisteredRibbon", typeof(List<string>), typeof(ContextualRibbonInternal), new PropertyMetadata(null));
// }

// 0x06000319 AspenTech.Visualisation.CommonShell.CommonShellApplication+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031a AspenTech.Visualisation.CommonShell.CommonShellApplication+<>c..ctor
// public <>c()
// {
// }

// 0x0600031c AspenTech.Visualisation.CommonShell.CommonShellContentHost+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600031d AspenTech.Visualisation.CommonShell.CommonShellContentHost+<>c..ctor
// public <>c()
// {
// }

// 0x06000321 AspenTech.Visualisation.CommonShell.CommonShellContentHost+<>c__DisplayClass50_0..ctor
// public <>c__DisplayClass50_0()
// {
// }

// 0x06000323 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader..ctor
// public InnerModuleInfoLoader()
// {
// }

// 0x0600032a AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600032b AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+<>c..ctor
// public <>c()
// {
// }

// 0x06000331 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+<>c__DisplayClass3_0..ctor
// public <>c__DisplayClass3_0()
// {
// }

// 0x06000333 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+<>c__DisplayClass3_1..ctor
// public <>c__DisplayClass3_1()
// {
// }

// 0x06000335 AspenTech.Visualisation.CommonShell.CommonShellViewRegistry+<>c__DisplayClass1_0..ctor
// public <>c__DisplayClass1_0()
// {
// }

// 0x0600033b AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass71_0..ctor
// public <>c__DisplayClass71_0()
// {
// }

// 0x0600033d AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600033e AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c..ctor
// public <>c()
// {
// }

// 0x06000343 AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass144_0..ctor
// public <>c__DisplayClass144_0()
// {
// }

// 0x06000347 AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass188_0..ctor
// public <>c__DisplayClass188_0()
// {
// }

// 0x06000349 AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass197_0..ctor
// public <>c__DisplayClass197_0()
// {
// }

// 0x0600034b AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass251_0..ctor
// public <>c__DisplayClass251_0()
// {
// }

// 0x0600034d AspenTech.Visualisation.CommonShell.CommonShellWindow+<>c__DisplayClass260_0..ctor
// public <>c__DisplayClass260_0()
// {
// }

// 0x0600034f AspenTech.Visualisation.CommonShell.NavigatorBar+<>c__DisplayClass23_0..ctor
// public <>c__DisplayClass23_0()
// {
// }

// 0x06000351 AspenTech.Visualisation.CommonShell.NavigatorBar+<>c__DisplayClass23_1..ctor
// public <>c__DisplayClass23_1()
// {
// }

// 0x06000353 AspenTech.Visualisation.CommonShell.NavigatorBar+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000354 AspenTech.Visualisation.CommonShell.NavigatorBar+<>c..ctor
// public <>c()
// {
// }

// 0x06000356 AspenTech.Visualisation.CommonShell.NavigatorBar+<>c__DisplayClass50_0..ctor
// public <>c__DisplayClass50_0()
// {
// }

// 0x06000358 AspenTech.Visualisation.CommonShell.ScreenManager+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000359 AspenTech.Visualisation.CommonShell.ScreenManager+<>c..ctor
// public <>c()
// {
// }

// 0x0600035c AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass45_0..ctor
// public <>c__DisplayClass45_0()
// {
// }

// 0x0600035e AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass46_0..ctor
// public <>c__DisplayClass46_0()
// {
// }

// 0x06000360 AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass48_0..ctor
// public <>c__DisplayClass48_0()
// {
// }

// 0x06000362 AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass49_0..ctor
// public <>c__DisplayClass49_0()
// {
// }

// 0x0600036d AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass57_0..ctor
// public <>c__DisplayClass57_0()
// {
// }

// 0x0600036f AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass58_0..ctor
// public <>c__DisplayClass58_0()
// {
// }

// 0x06000371 AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass80_0..ctor
// public <>c__DisplayClass80_0()
// {
// }

// 0x06000373 AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass81_0..ctor
// public <>c__DisplayClass81_0()
// {
// }

// 0x06000376 AspenTech.Visualisation.CommonShell.ScreenManager+<>c__DisplayClass82_0..ctor
// public <>c__DisplayClass82_0()
// {
// }

// 0x06000384 AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog+<>c__DisplayClass16_0..ctor
// public <>c__DisplayClass16_0()
// {
// }

// 0x06000386 AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog+<>c__DisplayClass16_1..ctor
// public <>c__DisplayClass16_1()
// {
// }

// 0x06000388 AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000389 AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog+<>c..ctor
// public <>c()
// {
// }

// 0x0600038c AspenTech.Visualisation.CommonShell.RibbonTools.ManageSavedLayoutsDialog+<>c__DisplayClass40_0..ctor
// public <>c__DisplayClass40_0()
// {
// }

// 0x0600038e AspenTech.Visualisation.CommonShell.RibbonTools.SaveWorkspaceLayoutDialog+<>c__DisplayClass33_0..ctor
// public <>c__DisplayClass33_0()
// {
// }

// 0x06000390 AspenTech.Visualisation.CommonShell.RibbonTools.SwitchScreenTool+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000391 AspenTech.Visualisation.CommonShell.RibbonTools.SwitchScreenTool+<>c..ctor
// public <>c()
// {
// }

// 0x06000393 AspenTech.Visualisation.CommonShell.RibbonSupport.ContextualRibbonManager+<>c__DisplayClass25_0..ctor
// public <>c__DisplayClass25_0()
// {
// }

// 0x06000396 AspenTech.Visualisation.CommonShell.AutomationPeers.NavigatorBarAutomationPeer+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000397 AspenTech.Visualisation.CommonShell.AutomationPeers.NavigatorBarAutomationPeer+<>c..ctor
// public <>c()
// {
// }

// 0x0600039a AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenManagerUIACommandProcessor+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600039b AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenManagerUIACommandProcessor+<>c..ctor
// public <>c()
// {
// }

// 0x0600039d AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenManagerUIACommandProcessor+<>c__DisplayClass5_0..ctor
// public <>c__DisplayClass5_0()
// {
// }

// 0x0600039f AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenManagerAutomationPeer+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003a0 AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenManagerAutomationPeer+<>c..ctor
// public <>c()
// {
// }

// 0x060003a3 AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenZoomControlAutomationPeer+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003a4 AspenTech.Visualisation.CommonShell.AutomationPeers.ScreenZoomControlAutomationPeer+<>c..ctor
// public <>c()
// {
// }

// 0x060003a6 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c__DisplayClass6_0..ctor
// public <>c__DisplayClass6_0()
// {
// }

// 0x060003a8 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060003a9 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c..ctor
// public <>c()
// {
// }

// 0x060003ac AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c__DisplayClass7_0..ctor
// public <>c__DisplayClass7_0()
// {
// }

// 0x060003ae AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c__DisplayClass7_1..ctor
// public <>c__DisplayClass7_1()
// {
// }

// 0x060003b9 AspenTech.Visualisation.CommonShell.CommonShellModuleExtensions+InnerModuleInfoLoader+<>c__DisplayClass8_0..ctor
// public <>c__DisplayClass8_0()
// {
// }
