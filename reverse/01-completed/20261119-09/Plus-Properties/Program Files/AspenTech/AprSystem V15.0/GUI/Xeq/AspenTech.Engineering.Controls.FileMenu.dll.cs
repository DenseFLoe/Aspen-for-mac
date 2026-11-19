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
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2022")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyFileVersion("15.0.0.0")]
[assembly: AssemblyTitle("AspenTech.Engineering.Controls.FileMenu")]
[assembly: AssemblyDescription("ENG commonly used file menu styling control.")]
[assembly: AssemblyProduct("AspenTech.Engineering.Controls.FileMenu")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("15.0.0.0")]
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
namespace AspenTech.Engineering.Controls.FileMenu
{
	public class AspenPlusTemplatesSelector : UserControl, IComponentConnector
	{
		public static readonly DependencyProperty TemplateUnitSetProperty = DependencyProperty.Register("TemplateUnitSet", typeof(string), typeof(AspenPlusTemplatesSelector), new PropertyMetadata("English"));

		internal ToggleButton MetC;

		internal FileMenuListView CatagoryList;

		internal FileMenuListView TemplateListView;

		private bool _contentLoaded;

		public string TemplateUnitSet
		{
			get
			{
				return (string)GetValue(TemplateUnitSetProperty);
			}
			set
			{
				SetValue(TemplateUnitSetProperty, value);
			}
		}

		public AspenPlusTemplatesSelector()
		{
			InitializeComponent();
			base.DataContextChanged += AspenPlusTemplatesSelector_DataContextChanged;
		}

		private void AspenPlusTemplatesSelector_DataContextChanged(object sender, DependencyPropertyChangedEventArgs e)
		{
			CatagoryList.SelectedIndex = 0;
		}

		private void FileMenuListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (e.AddedItems.Count <= 0 || !(e.AddedItems[0] is FileMenuItemData fileMenuItemData))
			{
				return;
			}
			foreach (FileMenuItemData child in fileMenuItemData.Children)
			{
				if (child.CommandParameter != null && child.CommandParameter.ToString().Contains(TemplateUnitSet))
				{
					return;
				}
			}
			TemplateUnitSet = "English";
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Engineering.Controls.FileMenu;component/aspenplustemplatesselector.xaml", UriKind.Relative);
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
				MetC = (ToggleButton)target;
				break;
			case 2:
				CatagoryList = (FileMenuListView)target;
				break;
			case 3:
				TemplateListView = (FileMenuListView)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class FilePathConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is string)
			{
				return Path.GetDirectoryName(value.ToString());
			}
			return string.Empty;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return new NotSupportedException();
		}
	}
	public class UnitSetSelectConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is string)
			{
				if (object.Equals(parameter, value.ToString()))
				{
					return true;
				}
				return false;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is bool)
			{
				_ = (bool)value;
				return parameter;
			}
			return DependencyProperty.UnsetValue;
		}
	}
	public class PlusTemplateUnitSetFilterConverter : IMultiValueConverter
	{
		public object Convert(object[] value, Type targetType, object parameter, CultureInfo culture)
		{
			List<FileMenuItemData> list = new List<FileMenuItemData>();
			if (value.Count() >= 2 && value[0] is IEnumerable<FileMenuItemData> enumerable && value[1] is string text)
			{
				foreach (FileMenuItemData item in enumerable)
				{
					if (item.CommandParameter == null)
					{
						continue;
					}
					string text2 = item.CommandParameter.ToString();
					if (text2.Contains(text))
					{
						list.Add(item);
						continue;
					}
					text2 = item.Description;
					if (text2.Contains(text))
					{
						list.Add(item);
					}
					else if (text2.Contains("Met-C-Bar Units") && text.Contains("Met-C"))
					{
						list.Add(item);
					}
					else if (!text2.Contains("English Units") && !text2.Contains("Metric Units") && !text2.Contains("Met-C-Bar Units"))
					{
						if (item.Title.Contains(text))
						{
							list.Add(item);
						}
						else if (!item.Title.Contains("English Units") && !item.Title.Contains("Metric Units") && !item.Title.Contains("Met-C-Bar Units"))
						{
							list.Add(item);
						}
					}
				}
			}
			return list;
		}

		public object[] ConvertBack(object value, Type[] targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class PlusListViewItemSelectedByUnitSetFilterConverter : IMultiValueConverter
	{
		public object Convert(object[] value, Type targetType, object parameter, CultureInfo culture)
		{
			List<FileMenuItemData> list = new List<FileMenuItemData>();
			if (value.Count() >= 2 && value[0] is IEnumerable<FileMenuItemData> enumerable && value[1] is string text)
			{
				foreach (FileMenuItemData item in enumerable)
				{
					if (item.CommandParameter == null)
					{
						continue;
					}
					string text2 = item.CommandParameter.ToString();
					if (text2.Contains(text))
					{
						list.Add(item);
						continue;
					}
					text2 = item.Description;
					if (text2.Contains(text))
					{
						list.Add(item);
					}
					else if (text2.Contains("Met-C-Bar Units") && text.Contains("Met-C"))
					{
						list.Add(item);
					}
					else if (!text2.Contains("English Units") && !text2.Contains("Metric Units") && !text2.Contains("Met-C-Bar Units"))
					{
						if (item.Title.Contains(text))
						{
							list.Add(item);
						}
						else if (!item.Title.Contains("English Units") && !item.Title.Contains("Metric Units") && !item.Title.Contains("Met-C-Bar Units"))
						{
							list.Add(item);
						}
					}
				}
			}
			return list.FirstOrDefault();
		}

		public object[] ConvertBack(object value, Type[] targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class ButtonDisplayConverterConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is bool)
			{
				if ((bool)value)
				{
					return Visibility.Visible;
				}
				return Visibility.Collapsed;
			}
			return Visibility.Collapsed;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class UnitOptionDisplayConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is IEnumerable<FileMenuItemData> enumerable && parameter is string value2)
			{
				foreach (FileMenuItemData item in enumerable)
				{
					if (item.CommandParameter != null && item.CommandParameter.ToString().Contains(value2))
					{
						return Visibility.Visible;
					}
				}
				return Visibility.Collapsed;
			}
			return Visibility.Collapsed;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class TooltipDisplayConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				if (string.IsNullOrEmpty(value.ToString()))
				{
					return false;
				}
				return true;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class SyncWidthConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is double num)
			{
				if (num - 17.0 > 0.0)
				{
					return num - 17.0;
				}
				return 0;
			}
			return 0;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class FileMenuControl : UserControl, IComponentConnector
	{
		internal StackPanel ContentPanel;

		private bool _contentLoaded;

		public FileMenuControl()
		{
			InitializeComponent();
			InitializeFileMenuManager();
		}

		public void Clear()
		{
			foreach (object child in ContentPanel.Children)
			{
				if (child is FileMenuItem { Content: FileMenuItemData content })
				{
					content.Clear();
				}
			}
		}

		private void InitializeFileMenuManager()
		{
			string[] names = Enum.GetNames(typeof(ItemTemplateType));
			int num = names.Length;
			for (int i = 0; i < num; i++)
			{
				DataTemplate template = FindResource(names[i]) as DataTemplate;
				FileMenuTemplateManager.SetBuildInTemplate(i + 1, template);
			}
		}

		public void SetData(List<FileMenuItemData> items)
		{
			foreach (FileMenuItemData item in items)
			{
				FileMenuItem fileMenuItem = new FileMenuItem
				{
					HorizontalAlignment = HorizontalAlignment.Left
				};
				fileMenuItem.Content = item;
				ContentPanel.Children.Add(fileMenuItem);
			}
		}

		public void AddData(List<FileMenuItemData> items)
		{
			foreach (FileMenuItemData item in items)
			{
				FileMenuItem fileMenuItem = new FileMenuItem();
				fileMenuItem.Content = item;
				ContentPanel.Children.Add(fileMenuItem);
			}
		}

		public void Update(List<FileMenuItemData> items)
		{
			List<FileMenuItemData> list = new List<FileMenuItemData>();
			foreach (FileMenuItemData item in items)
			{
				int num = -1;
				FileMenuItem fileMenuItem = null;
				foreach (object child in ContentPanel.Children)
				{
					num++;
					if (child is FileMenuItem { Content: FileMenuItemData content } fileMenuItem2 && string.Equals(content.Title, item.Title))
					{
						fileMenuItem = fileMenuItem2;
						break;
					}
				}
				if (fileMenuItem != null)
				{
					fileMenuItem.Content = item;
				}
				else
				{
					list.Add(item);
				}
			}
			AddData(list);
		}

		public void Remove(List<FileMenuItemData> items)
		{
			List<FileMenuItem> list = new List<FileMenuItem>();
			foreach (FileMenuItemData item in items)
			{
				foreach (object child in ContentPanel.Children)
				{
					if (child is FileMenuItem { Content: FileMenuItemData content } fileMenuItem && string.Equals(content.Title, item.Title))
					{
						list.Add(fileMenuItem);
						break;
					}
				}
			}
			foreach (FileMenuItem item2 in list)
			{
				ContentPanel.Children.Remove(item2);
			}
		}

		public void SetScale(double xscale, double yscale)
		{
			ContentPanel.RenderTransform = new ScaleTransform
			{
				ScaleX = xscale,
				ScaleY = yscale
			};
		}

		private void TabControl_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
		}

		private void WrapPanelListView_ScrollChanged(object sender, ScrollChangedEventArgs e)
		{
			MessageBox.Show("WrapPanelListView_ScrollChanged");
			e.Handled = false;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Engineering.Controls.FileMenu;component/filemenucontrol.xaml", UriKind.Relative);
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
				ContentPanel = (StackPanel)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class FileMenuItem : UserControl, IComponentConnector
	{
		private bool _contentLoaded;

		public FileMenuItem()
		{
			InitializeComponent();
			base.ContentTemplateSelector = new FileMenuItemTemplateSelector();
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			if (sender is ContentControl && (sender as ContentControl).DataContext is FileMenuItemData fileMenuItemData)
			{
				MessageBox.Show(fileMenuItemData.Title);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.Engineering.Controls.FileMenu;component/filemenuitem.xaml", UriKind.Relative);
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
	public class FileMenuItemTemplateSelector : DataTemplateSelector
	{
		public override DataTemplate SelectTemplate(object item, DependencyObject container)
		{
			if (item is FileMenuItemData && container is FrameworkElement)
			{
				return FileMenuTemplateManager.GetTemplate((item as FileMenuItemData).Type);
			}
			return base.SelectTemplate(item, container);
		}
	}
	public class BoolToTextConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			bool? flag = value as bool?;
			if (flag.HasValue && flag.Value)
			{
				return "T";
			}
			return "F";
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class BoolToExpandTextConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			bool? flag = value as bool?;
			if (flag.HasValue && flag.Value)
			{
				return "-";
			}
			return "+";
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return DependencyProperty.UnsetValue;
		}
	}
	public class ImageFormatConverter : IMultiValueConverter
	{
		public object Convert(object[] value, Type targetType, object parameter, CultureInfo culture)
		{
			bool? flag = value[1] as bool?;
			BitmapSource source = value[0] as BitmapImage;
			if (!flag.HasValue || !flag.Value)
			{
				return new FormatConvertedBitmap(source, PixelFormats.Gray32Float, null, 0.0);
			}
			return value[0];
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
	public class FileMenuItemData : DependencyObject
	{
		private double _defaultblockwidth = 280.0;

		private double _defaultbuttonfontsize = 14.0;

		private int _type;

		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty CommandProperty = DependencyProperty.Register("Command", typeof(ICommand), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty CommandParameterProperty = DependencyProperty.Register("CommandParameter", typeof(object), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty ImageProperty = DependencyProperty.Register("Image", typeof(ImageSource), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty DescriptionProperty = DependencyProperty.Register("Description", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty WidthProperty = DependencyProperty.Register("Width", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty HeightProperty = DependencyProperty.Register("Height", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty FontSizeProperty = DependencyProperty.Register("FontSize", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty UidProperty = DependencyProperty.Register("Uid", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty CommandTextProperty = DependencyProperty.Register("CommandText", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty TooltipProperty = DependencyProperty.Register("Tooltip", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public static readonly DependencyProperty TooltipTitleProperty = DependencyProperty.Register("TooltipTitle", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));

		public int Type
		{
			get
			{
				return _type;
			}
			set
			{
				_type = value;
				switch (_type)
				{
				case 1:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.15;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 3:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.5;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 6:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.5;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 5:
				case 16:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.5;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 4:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.5;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 2:
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 8:
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 7:
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 11:
				case 13:
					if (!Width.HasValue)
					{
						Width = _defaultblockwidth;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					break;
				case 14:
					if (!Width.HasValue)
					{
						Width = 150.0;
					}
					if (!FontSize.HasValue)
					{
						FontSize = _defaultbuttonfontsize;
					}
					if (!Height.HasValue)
					{
						Height = Width * 0.28;
					}
					break;
				case 9:
				case 10:
				case 12:
				case 15:
					break;
				}
			}
		}

		public string Title
		{
			get
			{
				return (string)GetValue(TitleProperty);
			}
			set
			{
				SetValue(TitleProperty, value);
			}
		}

		public ICommand Command
		{
			get
			{
				return (ICommand)GetValue(CommandProperty);
			}
			set
			{
				SetValue(CommandProperty, value);
			}
		}

		public object CommandParameter
		{
			get
			{
				return GetValue(CommandParameterProperty);
			}
			set
			{
				SetValue(CommandParameterProperty, value);
			}
		}

		public ImageSource Image
		{
			get
			{
				return (ImageSource)GetValue(ImageProperty);
			}
			set
			{
				SetValue(ImageProperty, value);
			}
		}

		public ObservableCollection<FileMenuItemData> Children { get; set; }

		public virtual string Description
		{
			get
			{
				return (string)GetValue(DescriptionProperty);
			}
			set
			{
				SetValue(DescriptionProperty, value);
			}
		}

		public double? Width
		{
			get
			{
				return (double?)GetValue(WidthProperty);
			}
			set
			{
				SetValue(WidthProperty, value);
			}
		}

		public double? Height
		{
			get
			{
				return (double?)GetValue(HeightProperty);
			}
			set
			{
				SetValue(HeightProperty, value);
			}
		}

		public double? FontSize
		{
			get
			{
				return (double?)GetValue(FontSizeProperty);
			}
			set
			{
				SetValue(FontSizeProperty, value);
			}
		}

		public string Uid
		{
			get
			{
				return (string)GetValue(UidProperty);
			}
			set
			{
				SetValue(UidProperty, value);
			}
		}

		public string CommandText
		{
			get
			{
				return (string)GetValue(CommandTextProperty);
			}
			set
			{
				SetValue(CommandTextProperty, value);
			}
		}

		public string Tooltip
		{
			get
			{
				return (string)GetValue(TooltipProperty);
			}
			set
			{
				SetValue(TooltipProperty, value);
			}
		}

		public string TooltipTitle
		{
			get
			{
				return (string)GetValue(TooltipTitleProperty);
			}
			set
			{
				SetValue(TooltipTitleProperty, value);
			}
		}

		public FileMenuItemData()
		{
			Children = new ObservableCollection<FileMenuItemData>();
		}

		public void Clear()
		{
			foreach (FileMenuItemData child in Children)
			{
				child.Clear();
			}
			Children.Clear();
			BindingOperations.ClearAllBindings(this);
		}

		public override string ToString()
		{
			return Title;
		}

		public void Update(List<FileMenuItemData> items)
		{
			List<FileMenuItemData> list = new List<FileMenuItemData>();
			foreach (FileMenuItemData item in items)
			{
				int num = -1;
				FileMenuItemData fileMenuItemData = null;
				foreach (FileMenuItemData child in Children)
				{
					num++;
					if (child != null)
					{
						FileMenuItemData fileMenuItemData2 = child;
						if (string.Equals(fileMenuItemData2.Title, item.Title))
						{
							fileMenuItemData = fileMenuItemData2;
							break;
						}
					}
				}
				if (fileMenuItemData != null)
				{
					Children[num] = item;
				}
				else
				{
					list.Add(item);
				}
			}
			AddData(list);
		}

		public void AddData(List<FileMenuItemData> items)
		{
			foreach (FileMenuItemData item in items)
			{
				Children.Add(item);
			}
		}

		public void Remove(List<FileMenuItemData> items)
		{
			List<FileMenuItemData> list = new List<FileMenuItemData>();
			foreach (FileMenuItemData item in items)
			{
				foreach (FileMenuItemData child in Children)
				{
					if (child != null)
					{
						FileMenuItemData fileMenuItemData = child;
						if (string.Equals(fileMenuItemData.Title, item.Title))
						{
							list.Add(fileMenuItemData);
							break;
						}
					}
				}
			}
			foreach (FileMenuItemData item2 in list)
			{
				Children.Remove(item2);
			}
		}
	}
	public class FileMenuListView : ListView
	{
		public FileMenuListView()
		{
			base.PreviewMouseWheel += FileMenuListView_PreviewMouseWheel;
		}

		private void FileMenuListView_PreviewMouseWheel(object sender, MouseWheelEventArgs e)
		{
			ScrollViewer scrollViewer = (new ListViewAutomationPeer(this).GetPattern(PatternInterface.Scroll) as ScrollViewerAutomationPeer).Owner as ScrollViewer;
			if (scrollViewer.ComputedVerticalScrollBarVisibility != Visibility.Visible || !(scrollViewer.VerticalOffset < scrollViewer.ScrollableHeight))
			{
				ScrollViewer ancestor = GetAncestor<ScrollViewer>(base.Parent);
				ancestor?.ScrollToVerticalOffset(ancestor.VerticalOffset - (double)e.Delta);
			}
		}

		protected override void OnMouseWheel(MouseWheelEventArgs e)
		{
			base.OnMouseWheel(e);
			e.Handled = false;
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
	public class FileMenuTabControl : TabControl
	{
		public static readonly DependencyProperty TemplateUnitSetProperty = DependencyProperty.Register("TemplateUnitSet", typeof(string), typeof(FileMenuTabControl), new PropertyMetadata("English"));

		public string TemplateUnitSet
		{
			get
			{
				return (string)GetValue(TemplateUnitSetProperty);
			}
			set
			{
				SetValue(TemplateUnitSetProperty, value);
			}
		}

		public FileMenuTabControl()
		{
			base.PreviewMouseLeftButtonDown += FileMenuTabControl_PreviewMouseLeftButtonDown;
			base.SelectionChanged += FileMenuTabControl_SelectionChanged;
		}

		private void FileMenuTabControl_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			if (!(e.OriginalSource is FrameworkElement))
			{
				return;
			}
			object dataContext = (e.OriginalSource as FrameworkElement).DataContext;
			if (dataContext is FileMenuItemData)
			{
				FileMenuItemData item = dataContext as FileMenuItemData;
				int num = base.Items.IndexOf(item);
				if (num >= 0 && base.SelectedIndex != num)
				{
					base.SelectedIndex = num;
				}
			}
		}

		private void FileMenuTabControl_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (!(e.OriginalSource is FileMenuTabControl) || e.AddedItems.Count <= 0 || !(e.AddedItems[0] is FileMenuItemData fileMenuItemData))
			{
				return;
			}
			foreach (FileMenuItemData child in fileMenuItemData.Children)
			{
				if (child.CommandParameter != null && child.CommandParameter.ToString().Contains(TemplateUnitSet))
				{
					return;
				}
			}
			TemplateUnitSet = "English";
		}

		private void FileMenuTabControl_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
		}
	}
	public class FileMenuTemplateManager
	{
		private static Dictionary<int, DataTemplate> _templateMap = new Dictionary<int, DataTemplate>
		{
			{ 1, null },
			{ 2, null },
			{ 3, null },
			{ 4, null },
			{ 5, null },
			{ 6, null },
			{ 7, null },
			{ 8, null },
			{ 9, null }
		};

		public static bool SetCustomTemplate(int type, DataTemplate template)
		{
			if (type <= 1000)
			{
				return false;
			}
			if (_templateMap.ContainsKey(type))
			{
				_templateMap[type] = template;
			}
			else
			{
				_templateMap.Add(type, template);
			}
			return true;
		}

		internal static bool SetBuildInTemplate(int type, DataTemplate template)
		{
			if (type > 1000)
			{
				return false;
			}
			if (_templateMap.ContainsKey(type))
			{
				_templateMap[type] = template;
			}
			else
			{
				_templateMap.Add(type, template);
			}
			return true;
		}

		public static DataTemplate GetTemplate(int type)
		{
			if (_templateMap.ContainsKey(type))
			{
				return _templateMap[type];
			}
			return null;
		}
	}
	public enum ItemTemplateType
	{
		CommandButtonTemplate = 1,
		WrapPanelListTemplate,
		ListViewItemWithImageTemplate,
		ListViewItemWithTextTemplate,
		ListViewItemWithImageAndCheckTemplate,
		ListViewItemWithImageAndMouseOverTemplate,
		DropDownListTemplate,
		WrapPanelTemplate,
		ImageAndTextListViewItemTemplate,
		TabControlWithWrapPanel,
		TabItemHeader,
		TabControlLeftSideWithWrapPanel,
		ListViewItemSelectWithCommandButton,
		HoverCommandItem,
		WrapPanelWithoutTitleTemplate,
		ListViewItemWithImageAndCheckBoxAndMouseOverTemplate,
		TwoLevelListWithContentPanel
	}
}
namespace AspenTech.Engineering.Controls.FileMenu.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "16.0.0.0")]
	[DebuggerNonUserCode]
	[CompilerGenerated]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			get
			{
				if (resourceMan == null)
				{
					resourceMan = new ResourceManager("AspenTech.Engineering.Controls.FileMenu.Properties.Resources", typeof(Resources).Assembly);
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
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}

// Coverage appendix for compiler-folded declarations and MethodDef implementations.
// The active C# above contains the reconstructed high-level forms. The comments below retain
// metadata names and show the expansions of methods that lack a direct declaration or sequence point in those forms.

// 0x06000006 XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x0600000f AspenTech.Engineering.Controls.FileMenu.AspenPlusTemplatesSelector..cctor
// using System.Windows;
//
// static AspenPlusTemplatesSelector()
// {
// 	TemplateUnitSetProperty = DependencyProperty.Register("TemplateUnitSet", typeof(string), typeof(AspenPlusTemplatesSelector), new PropertyMetadata("English"));
// }

// 0x06000012 AspenTech.Engineering.Controls.FileMenu.FilePathConverter..ctor
// public FilePathConverter()
// {
// }

// 0x06000015 AspenTech.Engineering.Controls.FileMenu.UnitSetSelectConverter..ctor
// public UnitSetSelectConverter()
// {
// }

// 0x06000018 AspenTech.Engineering.Controls.FileMenu.PlusTemplateUnitSetFilterConverter..ctor
// public PlusTemplateUnitSetFilterConverter()
// {
// }

// 0x0600001b AspenTech.Engineering.Controls.FileMenu.PlusListViewItemSelectedByUnitSetFilterConverter..ctor
// public PlusListViewItemSelectedByUnitSetFilterConverter()
// {
// }

// 0x0600001e AspenTech.Engineering.Controls.FileMenu.ButtonDisplayConverterConverter..ctor
// public ButtonDisplayConverterConverter()
// {
// }

// 0x06000021 AspenTech.Engineering.Controls.FileMenu.UnitOptionDisplayConverter..ctor
// public UnitOptionDisplayConverter()
// {
// }

// 0x06000024 AspenTech.Engineering.Controls.FileMenu.TooltipDisplayConverter..ctor
// public TooltipDisplayConverter()
// {
// }

// 0x06000027 AspenTech.Engineering.Controls.FileMenu.SyncWidthConverter..ctor
// public SyncWidthConverter()
// {
// }

// 0x06000039 AspenTech.Engineering.Controls.FileMenu.FileMenuItemTemplateSelector..ctor
// public FileMenuItemTemplateSelector()
// {
// }

// 0x0600003c AspenTech.Engineering.Controls.FileMenu.BoolToTextConverter..ctor
// public BoolToTextConverter()
// {
// }

// 0x0600003f AspenTech.Engineering.Controls.FileMenu.BoolToExpandTextConverter..ctor
// public BoolToExpandTextConverter()
// {
// }

// 0x06000042 AspenTech.Engineering.Controls.FileMenu.ImageFormatConverter..ctor
// public ImageFormatConverter()
// {
// }

// 0x06000065 AspenTech.Engineering.Controls.FileMenu.FileMenuItemData..cctor
// using System.Windows;
// using System.Windows.Input;
// using System.Windows.Media;
//
// static FileMenuItemData()
// {
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	CommandProperty = DependencyProperty.Register("Command", typeof(ICommand), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	CommandParameterProperty = DependencyProperty.Register("CommandParameter", typeof(object), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	ImageProperty = DependencyProperty.Register("Image", typeof(ImageSource), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	DescriptionProperty = DependencyProperty.Register("Description", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	WidthProperty = DependencyProperty.Register("Width", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	HeightProperty = DependencyProperty.Register("Height", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	FontSizeProperty = DependencyProperty.Register("FontSize", typeof(double?), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	UidProperty = DependencyProperty.Register("Uid", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	CommandTextProperty = DependencyProperty.Register("CommandText", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	TooltipProperty = DependencyProperty.Register("Tooltip", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// 	TooltipTitleProperty = DependencyProperty.Register("TooltipTitle", typeof(string), typeof(FileMenuItemData), new PropertyMetadata(null));
// }

// 0x06000070 AspenTech.Engineering.Controls.FileMenu.FileMenuTabControl..cctor
// using System.Windows;
//
// static FileMenuTabControl()
// {
// 	TemplateUnitSetProperty = DependencyProperty.Register("TemplateUnitSet", typeof(string), typeof(FileMenuTabControl), new PropertyMetadata("English"));
// }

// 0x06000074 AspenTech.Engineering.Controls.FileMenu.FileMenuTemplateManager..ctor
// public FileMenuTemplateManager()
// {
// }

// 0x06000075 AspenTech.Engineering.Controls.FileMenu.FileMenuTemplateManager..cctor
// using System.Collections.Generic;
// using System.Windows;
//
// static FileMenuTemplateManager()
// {
// 	_templateMap = new Dictionary<int, DataTemplate>
// 	{
// 		{ 1, null },
// 		{ 2, null },
// 		{ 3, null },
// 		{ 4, null },
// 		{ 5, null },
// 		{ 6, null },
// 		{ 7, null },
// 		{ 8, null },
// 		{ 9, null }
// 	};
// }

// 0x0600007b AspenTech.Engineering.Controls.FileMenu.Properties.Settings..ctor
// public Settings()
// {
// }

// 0x0600007c AspenTech.Engineering.Controls.FileMenu.Properties.Settings..cctor
// using System.Configuration;
//
// static Settings()
// {
// 	defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());
// }
