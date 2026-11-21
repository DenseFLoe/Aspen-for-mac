using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Media;
using AspenTech.CommonShell.Controls.Startup.Primitive;
using AspenTech.CommonShell.Controls.Startup.Properties;
using AspenTech.Visualisation.CommonShell;
using AspenTech.Visualisation.Controls.Support.Commands;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.UnityExtensions;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2022")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyFileVersion("14.0.0.0")]
[assembly: AssemblyTitle("AspenTech.CommonShell.Controls.Startup")]
[assembly: AssemblyDescription("Common shell extension library for ENG startup dialog.")]
[assembly: AssemblyProduct("AspenTech.CommonShell.Controls.Startup")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("14.0.0.0")]
namespace AspenTech.CommonShell.Controls.Startup
{
	public static class CommonShellWindowExtensions
	{
		public static void ShowStartupDialog(this IShellMainWindow window, StartupDialogOptions options, bool keepOpenedScreens = false)
		{
			if (window == null)
			{
				throw new ArgumentNullException("window");
			}
			if (options == null)
			{
				throw new ArgumentNullException("options");
			}
			if (!(window is CommonShellWindow commonShellWindow))
			{
				return;
			}
			if (!keepOpenedScreens)
			{
				commonShellWindow.ScreenManager?.CloseScreens((ScreenContentControl x) => true, null, forceClose: false, includeInternal: false);
			}
			StartupDialog startupDialog = GetLoadedStartupDialogs(window).FirstOrDefault();
			if (startupDialog == null)
			{
				StartupDialog dialog = new StartupDialog
				{
					Options = options
				};
				DisplayStartupDialog(commonShellWindow, dialog);
			}
			else
			{
				startupDialog.Options = options;
				DisplayStartupDialog(commonShellWindow, startupDialog);
			}
		}

		public static void CloseStartupDialog(this IShellMainWindow window)
		{
			if (window == null)
			{
				throw new ArgumentNullException("window");
			}
			if (window is CommonShellWindow commonShellWindow)
			{
				RemoveStartupDialog(commonShellWindow);
				commonShellWindow.ScreenManager.Visibility = Visibility.Visible;
			}
		}

		public static bool IsStartupDialogLoaded(this IShellMainWindow window)
		{
			if (window == null)
			{
				throw new ArgumentNullException("window");
			}
			return GetLoadedStartupDialogs(window).Any();
		}

		private static void DisplayStartupDialog(CommonShellWindow csw, StartupDialog dialog)
		{
			ScreenManager screenManager = csw.ScreenManager;
			if (screenManager.Parent is Grid grid)
			{
				Grid.SetRow(dialog, Grid.GetRow(screenManager));
				if (!grid.Children.Contains(dialog))
				{
					grid.Children.Add(dialog);
				}
			}
		}

		private static void RemoveStartupDialog(CommonShellWindow csw)
		{
			if (!(csw.ScreenManager.Parent is Grid grid))
			{
				return;
			}
			foreach (StartupDialog item in grid.Children.OfType<StartupDialog>().ToList())
			{
				grid.Children.Remove(item);
			}
		}

		private static IEnumerable<StartupDialog> GetLoadedStartupDialogs(IShellMainWindow window)
		{
			if (!(window is CommonShellWindow commonShellWindow) || !(commonShellWindow.ScreenManager.Parent is Grid grid))
			{
				yield break;
			}
			foreach (object child in grid.Children)
			{
				if (child is StartupDialog startupDialog)
				{
					yield return startupDialog;
				}
			}
		}
	}
	public class StartupDialog : Control
	{
		public static readonly DependencyProperty OptionsProperty;

		private IEventAggregator _usedEventAggregator;

		public StartupDialogOptions Options
		{
			get
			{
				return (StartupDialogOptions)GetValue(OptionsProperty);
			}
			set
			{
				SetValue(OptionsProperty, value);
			}
		}

		public ICommand CloseCommand { get; }

		static StartupDialog()
		{
			OptionsProperty = DependencyProperty.Register("Options", typeof(StartupDialogOptions), typeof(StartupDialog));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(StartupDialog), new FrameworkPropertyMetadata(typeof(StartupDialog)));
		}

		public StartupDialog()
		{
			base.Loaded += StartupDialog_Loaded;
			base.Unloaded += StartupDialog_Unloaded;
			CloseCommand = new RelayActionCommand(CloseCommand_Execute);
		}

		private void StartupDialog_Unloaded(object sender, RoutedEventArgs e)
		{
			if (_usedEventAggregator != null)
			{
				_usedEventAggregator.GetEvent<ActiveScreenChangedEvent>().Subscribe(OnActiveScreenChangedEvent);
			}
		}

		private void StartupDialog_Loaded(object sender, RoutedEventArgs e)
		{
			if (Window.GetWindow(this) is IShellMainWindow shellMainWindow)
			{
				IEventAggregator eventAggregator = shellMainWindow.Container?.TryResolve<IEventAggregator>();
				if (eventAggregator != null)
				{
					eventAggregator.GetEvent<ActiveScreenChangedEvent>().Subscribe(OnActiveScreenChangedEvent);
					_usedEventAggregator = eventAggregator;
				}
			}
		}

		private void OnActiveScreenChangedEvent(ActiveScreenChangedEventArgs args)
		{
			if (Window.GetWindow(this) is IShellMainWindow { ActiveScreen: not null } shellMainWindow)
			{
				shellMainWindow.CloseStartupDialog();
			}
		}

		private void CloseCommand_Execute()
		{
			if (Window.GetWindow(this) is IShellMainWindow window)
			{
				window.CloseStartupDialog();
			}
		}
	}
}
namespace AspenTech.CommonShell.Controls.Startup.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "16.0.0.0")]
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
					resourceMan = new ResourceManager("AspenTech.CommonShell.Controls.Startup.Properties.Resources", typeof(Resources).Assembly);
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

		public static string Button_New_Caption => ResourceManager.GetString("Button_New_Caption", resourceCulture);

		public static string Button_Open_Caption => ResourceManager.GetString("Button_Open_Caption", resourceCulture);

		public static string RecentFileList_Caption => ResourceManager.GetString("RecentFileList_Caption", resourceCulture);

		public static string RecentFileList_Placeholder => ResourceManager.GetString("RecentFileList_Placeholder", resourceCulture);

		public static string StartupDialog_Title => ResourceManager.GetString("StartupDialog_Title", resourceCulture);

		internal Resources()
		{
		}
	}
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
namespace AspenTech.CommonShell.Controls.Startup.Primitive
{
	public class FileItemsToVisibilityConverter : IValueConverter
	{
		public bool IsPositiveCheck { get; set; }

		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is IEnumerable<RecentFileItem> source && source.Any())
			{
				return (!IsPositiveCheck) ? Visibility.Collapsed : Visibility.Visible;
			}
			return IsPositiveCheck ? Visibility.Collapsed : Visibility.Visible;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class MouseOverToBackgroundConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is bool && (bool)value)
			{
				return parameter;
			}
			return Brushes.Transparent;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class FileItemModifiedTimeDisplayConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is DateTime dateTime)
			{
				return dateTime.ToString("MMMM dd yyyy");
			}
			return null;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class DialogTitleTextConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 2)
			{
				return (values[0] as string) ?? string.Format(Resources.StartupDialog_Title, values[1] as string);
			}
			return null;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class DialogTitleBackgroundConverter : IMultiValueConverter
	{
		private static readonly Brush DefaultTitleBackground = new LinearGradientBrush
		{
			StartPoint = new Point(0.5, 0.0),
			EndPoint = new Point(0.5, 1.0),
			GradientStops = new GradientStopCollection
			{
				new GradientStop((Color)ColorConverter.ConvertFromString("#FFA3A1E0"), 0.0),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FFDADAEE"), 0.228),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FF99A4A3"), 0.682),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FFE6EAE9"), 0.985)
			}
		};

		private static readonly Brush HYSYSTitleBackground = new LinearGradientBrush
		{
			StartPoint = new Point(0.5, 0.0),
			EndPoint = new Point(0.5, 1.0),
			GradientStops = new GradientStopCollection
			{
				new GradientStop((Color)ColorConverter.ConvertFromString("#FF2EAA97"), 0.0),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FF248F7F"), 0.228),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FF24B6A0"), 0.682),
				new GradientStop((Color)ColorConverter.ConvertFromString("#FF5BCCBB"), 0.985)
			}
		};

		private static readonly Brush APlusTitleBackground = new SolidColorBrush(Color.FromRgb(0, 163, 213));

		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 2)
			{
				if (values[0] is Brush result)
				{
					return result;
				}
				if (values[1] is string text)
				{
					if (text.ToLower().Contains("hysys"))
					{
						return HYSYSTitleBackground;
					}
					if (text.ToLower().Contains("plus"))
					{
						return APlusTitleBackground;
					}
				}
			}
			return DefaultTitleBackground;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class RecentFileClickedEventArgs : EventArgs
	{
		public RecentFileItem RecentFile { get; }

		public RecentFileClickedEventArgs(RecentFileItem recentFile)
		{
			RecentFile = recentFile ?? throw new ArgumentNullException("recentFile");
		}
	}
	public class IconButton : Button
	{
		public static readonly DependencyProperty IconProperty;

		public static readonly DependencyProperty CaptionProperty;

		public ImageSource Icon
		{
			get
			{
				return (ImageSource)GetValue(IconProperty);
			}
			set
			{
				SetValue(IconProperty, value);
			}
		}

		public string Caption
		{
			get
			{
				return (string)GetValue(CaptionProperty);
			}
			set
			{
				SetValue(CaptionProperty, value);
			}
		}

		static IconButton()
		{
			IconProperty = DependencyProperty.Register("Icon", typeof(ImageSource), typeof(IconButton));
			CaptionProperty = DependencyProperty.Register("Caption", typeof(string), typeof(IconButton));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(IconButton), new FrameworkPropertyMetadata(typeof(IconButton)));
		}
	}
	public class StartupDialogOptions : DependencyObject
	{
		public static readonly DependencyProperty DialogTitleProperty = DependencyProperty.Register("DialogTitle", typeof(string), typeof(StartupDialogOptions));

		public static readonly DependencyProperty ApplicationNameProperty = DependencyProperty.Register("ApplicationName", typeof(string), typeof(StartupDialogOptions));

		public static readonly DependencyProperty TitleBackgroundProperty = DependencyProperty.Register("TitleBackground", typeof(Brush), typeof(StartupDialogOptions), new PropertyMetadata());

		public static readonly DependencyProperty TitleForegroundProperty = DependencyProperty.Register("TitleForeground", typeof(Brush), typeof(StartupDialogOptions), new PropertyMetadata(Brushes.White));

		public static readonly DependencyProperty ButtonOpenCaptionProperty = DependencyProperty.Register("ButtonOpenCaption", typeof(string), typeof(StartupDialogOptions), new PropertyMetadata(Resources.Button_Open_Caption));

		public static readonly DependencyProperty ButtonNewCaptionProperty = DependencyProperty.Register("ButtonNewCaption", typeof(string), typeof(StartupDialogOptions), new PropertyMetadata(Resources.Button_New_Caption));

		public static readonly DependencyProperty RecentFilesListCaptionProperty = DependencyProperty.Register("RecentFilesListCaption", typeof(string), typeof(StartupDialogOptions), new PropertyMetadata(Resources.RecentFileList_Caption));

		public static readonly DependencyProperty RecentFilesPlaceholderTextProperty = DependencyProperty.Register("RecentFilesPlaceholderText", typeof(string), typeof(StartupDialogOptions), new PropertyMetadata(Resources.RecentFileList_Placeholder));

		public static readonly DependencyProperty RecentFilesProperty = DependencyProperty.Register("RecentFiles", typeof(IEnumerable<RecentFileItem>), typeof(StartupDialogOptions));

		public static readonly DependencyProperty TagProperty = DependencyProperty.Register("Tag", typeof(object), typeof(StartupDialogOptions));

		public string DialogTitle
		{
			get
			{
				return (string)GetValue(DialogTitleProperty);
			}
			set
			{
				SetValue(DialogTitleProperty, value);
			}
		}

		public string ApplicationName
		{
			get
			{
				return (string)GetValue(ApplicationNameProperty);
			}
			set
			{
				SetValue(ApplicationNameProperty, value);
			}
		}

		public Brush TitleBackground
		{
			get
			{
				return (Brush)GetValue(TitleBackgroundProperty);
			}
			set
			{
				SetValue(TitleBackgroundProperty, value);
			}
		}

		public Brush TitleForeground
		{
			get
			{
				return (Brush)GetValue(TitleForegroundProperty);
			}
			set
			{
				SetValue(TitleForegroundProperty, value);
			}
		}

		public string ButtonOpenCaption
		{
			get
			{
				return (string)GetValue(ButtonOpenCaptionProperty);
			}
			set
			{
				SetValue(ButtonOpenCaptionProperty, value);
			}
		}

		public string ButtonNewCaption
		{
			get
			{
				return (string)GetValue(ButtonNewCaptionProperty);
			}
			set
			{
				SetValue(ButtonNewCaptionProperty, value);
			}
		}

		public string RecentFilesListCaption
		{
			get
			{
				return (string)GetValue(RecentFilesListCaptionProperty);
			}
			set
			{
				SetValue(RecentFilesListCaptionProperty, value);
			}
		}

		public string RecentFilesPlaceholderText
		{
			get
			{
				return (string)GetValue(RecentFilesPlaceholderTextProperty);
			}
			set
			{
				SetValue(RecentFilesPlaceholderTextProperty, value);
			}
		}

		public IEnumerable<RecentFileItem> RecentFiles
		{
			get
			{
				return (IEnumerable<RecentFileItem>)GetValue(RecentFilesProperty);
			}
			set
			{
				SetValue(RecentFilesProperty, value);
			}
		}

		public object Tag
		{
			get
			{
				return GetValue(TagProperty);
			}
			set
			{
				SetValue(TagProperty, value);
			}
		}

		public event EventHandler ButtonOpenClicked;

		public event EventHandler ButtonNewClicked;

		public event EventHandler<RecentFileClickedEventArgs> RecentFileClicked;

		protected internal virtual void OnButtonOpenClicked()
		{
			this.ButtonOpenClicked?.Invoke(this, EventArgs.Empty);
		}

		protected internal virtual void OnButtonNewClicked()
		{
			this.ButtonNewClicked?.Invoke(this, EventArgs.Empty);
		}

		protected internal virtual void OnRecentFileClicked(RecentFileItem recentFile)
		{
			this.RecentFileClicked?.Invoke(this, new RecentFileClickedEventArgs(recentFile));
		}
	}
	public class StartupControl : Control
	{
		public static readonly DependencyProperty OptionsProperty;

		public static readonly DependencyProperty CloseCommandProperty;

		public StartupDialogOptions Options
		{
			get
			{
				return (StartupDialogOptions)GetValue(OptionsProperty);
			}
			set
			{
				SetValue(OptionsProperty, value);
			}
		}

		public ICommand CloseCommand
		{
			get
			{
				return (ICommand)GetValue(CloseCommandProperty);
			}
			set
			{
				SetValue(CloseCommandProperty, value);
			}
		}

		public ICommand OpenCommand { get; }

		public ICommand NewCommand { get; }

		public ICommand RecentFileCommand { get; }

		static StartupControl()
		{
			OptionsProperty = DependencyProperty.Register("Options", typeof(StartupDialogOptions), typeof(StartupControl));
			CloseCommandProperty = DependencyProperty.Register("CloseCommand", typeof(ICommand), typeof(StartupControl));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(StartupControl), new FrameworkPropertyMetadata(typeof(StartupControl)));
		}

		public StartupControl()
		{
			OpenCommand = new RelayActionCommand(OpenCommand_Execute);
			NewCommand = new RelayActionCommand(NewCommand_Execute);
			RecentFileCommand = new RelayActionCommand<object>(RecentFileCommand_Execute);
		}

		private void OpenCommand_Execute()
		{
			Options?.OnButtonOpenClicked();
		}

		private void NewCommand_Execute()
		{
			Options?.OnButtonNewClicked();
		}

		private void RecentFileCommand_Execute(object parameter)
		{
			Options?.OnRecentFileClicked(parameter as RecentFileItem);
		}
	}
	public class RecentFileItem
	{
		public string FilePath { get; }

		public ImageSource FileIcon { get; }

		public string FileName { get; }

		public DateTime? ModifiedTime { get; }

		public RecentFileItem(string filePath, ImageSource fileIcon)
		{
			FilePath = filePath ?? throw new ArgumentNullException("filePath");
			FileIcon = fileIcon ?? throw new ArgumentNullException("fileIcon");
			if (!string.IsNullOrWhiteSpace(FilePath))
			{
				FileName = Path.GetFileName(FilePath);
				if (File.Exists(FilePath))
				{
					ModifiedTime = File.GetLastAccessTime(FilePath);
				}
			}
		}
	}
	public class RecentFileListControl : Control
	{
		public static readonly DependencyProperty RecentFilesListCaptionProperty;

		public static readonly DependencyProperty RecentFilesPlaceholderTextProperty;

		public static readonly DependencyProperty RecentFilesProperty;

		public static readonly DependencyProperty RecentFileCommandProperty;

		public string RecentFilesListCaption
		{
			get
			{
				return (string)GetValue(RecentFilesListCaptionProperty);
			}
			set
			{
				SetValue(RecentFilesListCaptionProperty, value);
			}
		}

		public string RecentFilesPlaceholderText
		{
			get
			{
				return (string)GetValue(RecentFilesPlaceholderTextProperty);
			}
			set
			{
				SetValue(RecentFilesPlaceholderTextProperty, value);
			}
		}

		public IEnumerable<RecentFileItem> RecentFiles
		{
			get
			{
				return (IEnumerable<RecentFileItem>)GetValue(RecentFilesProperty);
			}
			set
			{
				SetValue(RecentFilesProperty, value);
			}
		}

		public ICommand RecentFileCommand
		{
			get
			{
				return (ICommand)GetValue(RecentFileCommandProperty);
			}
			set
			{
				SetValue(RecentFileCommandProperty, value);
			}
		}

		static RecentFileListControl()
		{
			RecentFilesListCaptionProperty = DependencyProperty.Register("RecentFilesListCaption", typeof(string), typeof(RecentFileListControl), new PropertyMetadata(AspenTech.CommonShell.Controls.Startup.Properties.Resources.RecentFileList_Caption));
			RecentFilesPlaceholderTextProperty = DependencyProperty.Register("RecentFilesPlaceholderText", typeof(string), typeof(RecentFileListControl), new PropertyMetadata(AspenTech.CommonShell.Controls.Startup.Properties.Resources.RecentFileList_Placeholder));
			RecentFilesProperty = DependencyProperty.Register("RecentFiles", typeof(IEnumerable<RecentFileItem>), typeof(RecentFileListControl));
			RecentFileCommandProperty = DependencyProperty.Register("RecentFileCommand", typeof(ICommand), typeof(RecentFileListControl));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(RecentFileListControl), new FrameworkPropertyMetadata(typeof(RecentFileListControl)));
		}

		protected override void OnMouseUp(MouseButtonEventArgs e)
		{
			ListBoxItem ancestor = GetAncestor<ListBoxItem>(e.OriginalSource as DependencyObject);
			if (ancestor != null && ancestor.DataContext is RecentFileItem parameter && RecentFileCommand != null && RecentFileCommand.CanExecute(parameter))
			{
				RecentFileCommand.Execute(parameter);
			}
			base.OnMouseUp(e);
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
	}
}
