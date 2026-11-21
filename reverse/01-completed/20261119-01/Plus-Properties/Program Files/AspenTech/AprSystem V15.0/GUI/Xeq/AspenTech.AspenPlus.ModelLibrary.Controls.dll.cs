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
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Threading;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.ModelLibrary.Controls")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.ModelLibrary.Controls")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
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
namespace AspenTech.AspenPlus.ModelLibrary.Controls
{
	[ContentProperty("Categories")]
	public class BlockTableControl : Control
	{
		public static readonly DependencyProperty DockProperty;

		public static readonly DependencyProperty CategoriesProperty;

		public static readonly DependencyProperty SelectedIconProperty;

		public static readonly DependencyProperty CurrentCategoryProperty;

		public static readonly DependencyProperty ButtonSizeProperty;

		public static readonly DependencyProperty DefaultButtonBackgroundProperty;

		public static readonly DependencyProperty CheckedButtonBackgroundProperty;

		public static readonly RoutedEvent SelectedIconChangedEvent;

		public static readonly RoutedEvent CurrentCategoryChangedEvent;

		public Dock Dock
		{
			get
			{
				return (Dock)GetValue(DockProperty);
			}
			set
			{
				SetValue(DockProperty, value);
			}
		}

		public CategoryCollection Categories
		{
			get
			{
				return (CategoryCollection)GetValue(CategoriesProperty);
			}
			set
			{
				SetValue(CategoriesProperty, value);
			}
		}

		public Category CurrentCategory
		{
			get
			{
				return (Category)GetValue(CurrentCategoryProperty);
			}
			set
			{
				SetValue(CurrentCategoryProperty, value);
			}
		}

		public Size ButtonSize
		{
			get
			{
				return (Size)GetValue(ButtonSizeProperty);
			}
			set
			{
				SetValue(ButtonSizeProperty, value);
			}
		}

		public Icon SelectedIcon
		{
			get
			{
				return (Icon)GetValue(SelectedIconProperty);
			}
			set
			{
				SetValue(SelectedIconProperty, value);
			}
		}

		public Brush DefaultButtonBackground
		{
			get
			{
				return (Brush)GetValue(DefaultButtonBackgroundProperty);
			}
			set
			{
				SetValue(DefaultButtonBackgroundProperty, value);
			}
		}

		public Brush CheckedButtonBackground
		{
			get
			{
				return (Brush)GetValue(CheckedButtonBackgroundProperty);
			}
			set
			{
				SetValue(CheckedButtonBackgroundProperty, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<Icon> SelectedIconChanged
		{
			add
			{
				AddHandler(SelectedIconChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectedIconChangedEvent, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<Category> CurrentCategoryChanged
		{
			add
			{
				AddHandler(CurrentCategoryChangedEvent, value);
			}
			remove
			{
				RemoveHandler(CurrentCategoryChangedEvent, value);
			}
		}

		static BlockTableControl()
		{
			DockProperty = DependencyProperty.Register("Dock", typeof(Dock), typeof(BlockTableControl), new FrameworkPropertyMetadata(Dock.Bottom));
			CategoriesProperty = DependencyProperty.Register("Categories", typeof(CategoryCollection), typeof(BlockTableControl));
			SelectedIconProperty = DependencyProperty.Register("SelectedIcon", typeof(Icon), typeof(BlockTableControl), new FrameworkPropertyMetadata(OnSelectedIconPropertyChanged));
			CurrentCategoryProperty = DependencyProperty.Register("CurrentCategory", typeof(Category), typeof(BlockTableControl), new FrameworkPropertyMetadata(OnCurrentCategoryPropertyChanged));
			ButtonSizeProperty = DependencyProperty.Register("ButtonSize", typeof(Size), typeof(BlockTableControl), new FrameworkPropertyMetadata(new Size(90.0, 70.0)));
			DefaultButtonBackgroundProperty = DependencyProperty.Register("DefaultButtonBackground", typeof(Brush), typeof(BlockTableControl), new FrameworkPropertyMetadata(Brushes.LightGray));
			CheckedButtonBackgroundProperty = DependencyProperty.Register("CheckedButtonBackground", typeof(Brush), typeof(BlockTableControl), new FrameworkPropertyMetadata(Brushes.White));
			SelectedIconChangedEvent = EventManager.RegisterRoutedEvent("SelectedIconChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<Icon>), typeof(BlockTableControl));
			CurrentCategoryChangedEvent = EventManager.RegisterRoutedEvent("CurrentCategoryChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<Category>), typeof(BlockTableControl));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(BlockTableControl), new FrameworkPropertyMetadata(typeof(BlockTableControl)));
			EventManager.RegisterClassHandler(typeof(BlockTableControl), DropdownButton.ClickEvent, new RoutedEventHandler(DropdownButton_Click));
		}

		protected virtual void OnSelectedIconChanged(Icon oldSelected, Icon newSelected)
		{
			RaiseEvent(new RoutedPropertyChangedEventArgs<Icon>(oldSelected, newSelected, SelectedIconChangedEvent));
		}

		protected virtual void OnCurrentCategoryChanged(Category oldSelected, Category newSelected)
		{
			RaiseEvent(new RoutedPropertyChangedEventArgs<Category>(oldSelected, newSelected, CurrentCategoryChangedEvent));
		}

		private static void DropdownButton_Click(object sender, RoutedEventArgs e)
		{
			DropdownButton dropdownButton = e.OriginalSource as DropdownButton;
			(sender as BlockTableControl).SelectedIcon = dropdownButton.SelectedItem as Icon;
		}

		private static void OnSelectedIconPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			BlockTableControl blockTableControl = d as BlockTableControl;
			if (blockTableControl.SelectedIcon != null)
			{
				foreach (Category category in blockTableControl.Categories)
				{
					foreach (Model model in category.Models)
					{
						model.IsChecked = model == blockTableControl.SelectedIcon.Parent;
					}
				}
			}
			else
			{
				foreach (Category category2 in blockTableControl.Categories)
				{
					foreach (Model model2 in category2.Models)
					{
						model2.IsChecked = false;
					}
				}
			}
			blockTableControl.OnSelectedIconChanged(e.OldValue as Icon, e.NewValue as Icon);
		}

		private static void OnCurrentCategoryPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as BlockTableControl).OnCurrentCategoryChanged((Category)e.OldValue, (Category)e.NewValue);
		}
	}
	[ContentProperty("Models")]
	public class Category : NotifyPropertyChangedBase
	{
		private object _header;

		private object _name;

		private Model _selectedModel;

		private bool _isStreamCategory;

		public string HelpFile = "Palette.chm";

		public int HelpId { get; private set; }

		public object Header
		{
			get
			{
				return _header;
			}
			set
			{
				if (_header != value)
				{
					_header = value;
					OnPropertyChanged("Header");
				}
			}
		}

		public object Name
		{
			get
			{
				return _name;
			}
			set
			{
				if (_name != value)
				{
					if (string.IsNullOrEmpty((string)value))
					{
						_name = _header;
					}
					else
					{
						_name = value;
					}
					OnPropertyChanged("Name");
					SetHelpIdByName();
				}
			}
		}

		public bool IsStreamCategory
		{
			get
			{
				return _isStreamCategory;
			}
			set
			{
				if (_isStreamCategory != value)
				{
					_isStreamCategory = value;
					OnPropertyChanged("IsStreamCategory");
				}
			}
		}

		public Model SelectedModel
		{
			get
			{
				return _selectedModel;
			}
			set
			{
				if (_selectedModel != value)
				{
					_selectedModel = value;
					OnPropertyChanged("SelectedModel");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public ModelCollection Models { get; private set; }

		public object Data { get; set; }

		private void SetHelpIdByName()
		{
			switch (Header as string)
			{
			case "Mixers/Splitters":
				HelpId = 2;
				break;
			case "Separators":
				HelpId = 3;
				break;
			case "Exchangers":
				HelpId = 4;
				break;
			case "Columns":
				HelpId = 5;
				break;
			case "Reactors":
				HelpId = 6;
				break;
			case "Pressure Changers":
				HelpId = 7;
				break;
			case "Manipulators":
				HelpId = 8;
				break;
			case "Solids":
				HelpId = 9;
				break;
			case "Solids Separators":
				HelpId = 10;
				break;
			case "User Models":
				HelpId = 11;
				break;
			default:
				HelpId = 12;
				break;
			}
		}

		public Category()
		{
			Models = new ModelCollection(this);
		}
	}
	public class CategoryCollection : ObservableCollection<Category>
	{
	}
	public static class Extensions
	{
		public static DropdownButton GetMouseDropdownButton(this MouseEventArgs mouseEventArgs, Control control)
		{
			if (mouseEventArgs == null)
			{
				throw new ArgumentNullException("mouseEventArgs");
			}
			if (control == null)
			{
				throw new ArgumentNullException("control");
			}
			return GetAncestor<DropdownButton>(mouseEventArgs.OriginalSource as DependencyObject, control);
		}

		public static T GetAncestor<T>(DependencyObject d, DependencyObject parentLimit) where T : class
		{
			DependencyObject dependencyObject = d;
			while (true)
			{
				if (dependencyObject == null || dependencyObject == parentLimit)
				{
					return null;
				}
				if (typeof(T).IsInstanceOfType(dependencyObject))
				{
					break;
				}
				dependencyObject = ((!(dependencyObject is Visual)) ? LogicalTreeHelper.GetParent(dependencyObject) : VisualTreeHelper.GetParent(dependencyObject));
			}
			return dependencyObject as T;
		}
	}
	[ContentProperty("DrawingElement")]
	public class Icon : NotifyPropertyChangedBase
	{
		private object _header;

		private UIElement _drawingElement;

		public object Header
		{
			get
			{
				return _header;
			}
			set
			{
				if (_header != value)
				{
					_header = value;
					OnPropertyChanged("Header");
				}
			}
		}

		public UIElement DrawingElement
		{
			get
			{
				return _drawingElement;
			}
			set
			{
				if (_drawingElement != value)
				{
					_drawingElement = value;
					OnPropertyChanged("DrawingElement");
				}
			}
		}

		public Model Parent { get; internal set; }

		public object Data { get; set; }
	}
	public class IconCollection : ObservableCollection<Icon>
	{
		private readonly Model _parent;

		public IconCollection(Model parent)
		{
			if (parent == null)
			{
				throw new ArgumentNullException("parent");
			}
			_parent = parent;
		}

		protected override void InsertItem(int index, Icon item)
		{
			item.Parent = _parent;
			base.InsertItem(index, item);
		}
	}
	[ContentProperty("BlockCategories")]
	public class Library : NotifyPropertyChangedBase
	{
		private object _header;

		private Category _streamCategory;

		private Category _currentBlockCategory;

		public object Header
		{
			get
			{
				return _header;
			}
			set
			{
				if (_header != value)
				{
					_header = value;
					OnPropertyChanged("Header");
				}
			}
		}

		public Category StreamCategory
		{
			get
			{
				return _streamCategory;
			}
			set
			{
				if (_streamCategory != value)
				{
					_streamCategory = value;
					OnPropertyChanged("StreamCategory");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public CategoryCollection BlockCategories { get; private set; }

		public Category CurrentBlockCategory
		{
			get
			{
				return _currentBlockCategory;
			}
			set
			{
				if (_currentBlockCategory != value)
				{
					_currentBlockCategory = value;
					OnPropertyChanged("CurrentBlockCategory");
				}
			}
		}

		public object Data { get; set; }

		public Library()
		{
			BlockCategories = new CategoryCollection();
		}
	}
	[ContentProperty("Icons")]
	public class Model : NotifyPropertyChangedBase
	{
		private object _header;

		private bool _isChecked;

		private string _description;

		private Icon _selectedIcon;

		public object Header
		{
			get
			{
				return _header;
			}
			set
			{
				if (_header != value)
				{
					_header = value;
					OnPropertyChanged("Header");
				}
			}
		}

		public bool IsChecked
		{
			get
			{
				return _isChecked;
			}
			set
			{
				if (_isChecked != value)
				{
					_isChecked = value;
					OnPropertyChanged("IsChecked");
				}
			}
		}

		public string Description
		{
			get
			{
				if (string.IsNullOrEmpty(_description))
				{
					return null;
				}
				return _description;
			}
			set
			{
				if (_description != value)
				{
					_description = value;
					OnPropertyChanged("Description");
					OnPropertyChanged("Tooltip");
				}
			}
		}

		public string Tooltip
		{
			get
			{
				if (Parent != null && Parent.IsStreamCategory)
				{
					return Description;
				}
				string text = string.Empty;
				if (!string.IsNullOrEmpty(Description))
				{
					text += Description;
				}
				else if (!string.IsNullOrWhiteSpace(Header as string))
				{
					text += Header;
				}
				if (SelectedIcon != null)
				{
					string text2 = SelectedIcon.Header as string;
					if (!string.IsNullOrEmpty(text2))
					{
						text = text + " (" + text2 + ")";
					}
				}
				return text;
			}
		}

		public Icon SelectedIcon
		{
			get
			{
				return _selectedIcon;
			}
			set
			{
				if (_selectedIcon != value)
				{
					_selectedIcon = value;
					OnPropertyChanged("SelectedIcon");
					OnPropertyChanged("Tooltip");
				}
			}
		}

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public IconCollection Icons { get; private set; }

		public Category Parent { get; internal set; }

		public object Data { get; set; }

		public Model()
		{
			Icons = new IconCollection(this);
		}
	}
	public class ModelCollection : ObservableCollection<Model>
	{
		private readonly Category _parent;

		public ModelCollection(Category parent)
		{
			if (parent == null)
			{
				throw new ArgumentNullException("parent");
			}
			_parent = parent;
		}

		protected override void InsertItem(int index, Model item)
		{
			item.Parent = _parent;
			base.InsertItem(index, item);
		}
	}
	[ContentProperty("ModelLibrary")]
	[TemplatePart(Name = "PART_SelectorButton", Type = typeof(OptionButton))]
	[TemplatePart(Name = "PART_BlockTableControl", Type = typeof(BlockTableControl))]
	[TemplatePart(Name = "PART_StreamsDropdownButton", Type = typeof(DropdownButton))]
	public class ModelLibraryControl : Control
	{
		private BlockTableControl _theBlockTableControl;

		private const string PART_SelectorButton = "PART_SelectorButton";

		private const string PART_BlockTableControl = "PART_BlockTableControl";

		private const string PART_StreamsDropdownButton = "PART_StreamsDropdownButton";

		public static readonly DependencyProperty DockProperty;

		public static readonly DependencyProperty ModelLibraryProperty;

		public static readonly DependencyProperty IsOptionIconCheckedProperty;

		public static readonly DependencyProperty SelectedStreamModelProperty;

		public static readonly DependencyProperty SelectedBlockIconProperty;

		public static readonly DependencyProperty ButtonSizeProperty;

		public static readonly DependencyProperty DefaultButtonBackgroundProperty;

		public static readonly DependencyProperty CheckedButtonBackgroundProperty;

		public static readonly DependencyProperty CurrentBlockCategoryProperty;

		public static readonly RoutedEvent SelectionChangedEvent;

		public Dock Dock
		{
			get
			{
				return (Dock)GetValue(DockProperty);
			}
			set
			{
				SetValue(DockProperty, value);
			}
		}

		public Library ModelLibrary
		{
			get
			{
				return (Library)GetValue(ModelLibraryProperty);
			}
			set
			{
				SetValue(ModelLibraryProperty, value);
			}
		}

		public bool IsOptionIconChecked
		{
			get
			{
				return (bool)GetValue(IsOptionIconCheckedProperty);
			}
			set
			{
				SetValue(IsOptionIconCheckedProperty, value);
			}
		}

		public Model SelectedStreamModel
		{
			get
			{
				return (Model)GetValue(SelectedStreamModelProperty);
			}
			set
			{
				SetValue(SelectedStreamModelProperty, value);
			}
		}

		public Icon SelectedBlockIcon
		{
			get
			{
				return (Icon)GetValue(SelectedBlockIconProperty);
			}
			set
			{
				SetValue(SelectedBlockIconProperty, value);
			}
		}

		public Size ButtonSize
		{
			get
			{
				return (Size)GetValue(ButtonSizeProperty);
			}
			set
			{
				SetValue(ButtonSizeProperty, value);
			}
		}

		public Brush DefaultButtonBackground
		{
			get
			{
				return (Brush)GetValue(DefaultButtonBackgroundProperty);
			}
			set
			{
				SetValue(DefaultButtonBackgroundProperty, value);
			}
		}

		public Brush CheckedButtonBackground
		{
			get
			{
				return (Brush)GetValue(CheckedButtonBackgroundProperty);
			}
			set
			{
				SetValue(CheckedButtonBackgroundProperty, value);
			}
		}

		public Category CurrentBlockCategory
		{
			get
			{
				return (Category)GetValue(CurrentBlockCategoryProperty);
			}
			set
			{
				SetValue(CurrentBlockCategoryProperty, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<object> SelectionChanged
		{
			add
			{
				AddHandler(SelectionChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectionChangedEvent, value);
			}
		}

		static ModelLibraryControl()
		{
			DockProperty = DependencyProperty.Register("Dock", typeof(Dock), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(Dock.Bottom));
			ModelLibraryProperty = DependencyProperty.Register("ModelLibrary", typeof(Library), typeof(ModelLibraryControl));
			IsOptionIconCheckedProperty = DependencyProperty.Register("IsOptionIconChecked", typeof(bool), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(false, OnIsOptionIconCheckedPropertyChanged));
			SelectedStreamModelProperty = DependencyProperty.Register("SelectedStreamModel", typeof(Model), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(OnSelectedStreamModelPropertyChanged));
			SelectedBlockIconProperty = DependencyProperty.Register("SelectedBlockIcon", typeof(Icon), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(OnSelectedBlockIconPropertyChanged));
			ButtonSizeProperty = DependencyProperty.Register("ButtonSize", typeof(Size), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(new Size(90.0, 70.0)));
			DefaultButtonBackgroundProperty = DependencyProperty.Register("DefaultButtonBackground", typeof(Brush), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(Brushes.LightGray));
			CheckedButtonBackgroundProperty = DependencyProperty.Register("CheckedButtonBackground", typeof(Brush), typeof(ModelLibraryControl), new FrameworkPropertyMetadata(Brushes.White));
			CurrentBlockCategoryProperty = DependencyProperty.Register("CurrentBlockCategory", typeof(Category), typeof(ModelLibraryControl));
			SelectionChangedEvent = EventManager.RegisterRoutedEvent("SelectionChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<object>), typeof(ModelLibraryControl));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(ModelLibraryControl), new FrameworkPropertyMetadata(typeof(ModelLibraryControl)));
			EventManager.RegisterClassHandler(typeof(ModelLibraryControl), OptionButton.ClickEvent, new RoutedEventHandler(OptionButton_Click));
			EventManager.RegisterClassHandler(typeof(ModelLibraryControl), DropdownButton.ClickEvent, new RoutedEventHandler(DropdownButton_Click));
		}

		public override void OnApplyTemplate()
		{
			_theBlockTableControl = GetTemplateChild("PART_BlockTableControl") as BlockTableControl;
			base.OnApplyTemplate();
			_theBlockTableControl.CurrentCategoryChanged += _theBlockTableControl_CurrentCategoryChanged;
		}

		private void _theBlockTableControl_CurrentCategoryChanged(object sender, RoutedPropertyChangedEventArgs<Category> e)
		{
			if (_theBlockTableControl.CurrentCategory != null)
			{
				MMHelp.SetHelpFile(this, _theBlockTableControl.CurrentCategory.HelpFile);
				MMHelp.SetHelpId(this, _theBlockTableControl.CurrentCategory.HelpId);
			}
		}

		protected virtual void OnSelectionChanged(object oldSelection, object newSelection)
		{
			RaiseEvent(new RoutedPropertyChangedEventArgs<object>(oldSelection, newSelection, SelectionChangedEvent)
			{
				Source = this
			});
		}

		protected virtual void OnOnIsOptionIconCheckedChanged(bool oldValue, bool newValue)
		{
			if (newValue)
			{
				object oldSelectedObject = GetOldSelectedObject(SelectedStreamModel, SelectedBlockIcon, oldValue);
				SelectedStreamModel = null;
				SelectedBlockIcon = null;
				OnSelectionChanged(oldSelectedObject, newValue);
			}
		}

		protected virtual void OnSelectedStreamModelChanged(Model oldValue, Model newValue)
		{
			if (newValue != null)
			{
				object oldSelectedObject = GetOldSelectedObject(oldValue, SelectedBlockIcon, IsOptionIconChecked);
				IsOptionIconChecked = false;
				SelectedBlockIcon = null;
				OnSelectionChanged(oldSelectedObject, newValue);
			}
		}

		protected int ParseDescription(string sDescription, out string sModelName, out string sModelVersion)
		{
			int result = 0;
			sModelName = "";
			sModelVersion = "";
			string[] array = sDescription.Split(' ');
			if (array[0] != "ACM")
			{
				return result;
			}
			if (array[1] != "Model")
			{
				return result;
			}
			result = 2;
			if (array.Length >= 3)
			{
				sModelName = array[2];
				if (array.Length >= 7)
				{
					sModelVersion = array[6];
					if (File.Exists(Path.Combine(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), "AspenTech\\AES\\AM Models"), sModelVersion) + "\\" + sModelName + ".atmlz"))
					{
						result = 1;
					}
					return result;
				}
				return result;
			}
			return result;
		}

		protected virtual void OnSelectedBlockIconChanged(Icon oldValue, Icon newValue)
		{
			if (newValue == null)
			{
				return;
			}
			Category currentBlockCategory = CurrentBlockCategory;
			if (currentBlockCategory != null && currentBlockCategory.Name as string == "ACM Models")
			{
				string description = newValue.Parent.Description;
				if (!string.IsNullOrEmpty(description))
				{
					string sModelName = "";
					string sModelVersion = "";
					if (ParseDescription(description, out sModelName, out sModelVersion) == 2)
					{
						string _ = SorResources._638;
						string messageBoxText = string.Format(SorResources._639, sModelName, sModelVersion);
						string caption = _;
						MessageBox.Show(messageBoxText, caption, MessageBoxButton.OK, MessageBoxImage.Exclamation);
						IsOptionIconChecked = false;
						SelectedBlockIcon = null;
						return;
					}
				}
			}
			object oldSelectedObject = GetOldSelectedObject(SelectedStreamModel, oldValue, IsOptionIconChecked);
			IsOptionIconChecked = false;
			SelectedStreamModel = null;
			OnSelectionChanged(oldSelectedObject, newValue);
		}

		private object GetOldSelectedObject(Model oldModel, Icon oldIcon, bool oldChecked)
		{
			if (oldModel != null)
			{
				return oldModel;
			}
			if (oldIcon != null)
			{
				return oldIcon;
			}
			return oldChecked;
		}

		private static void OptionButton_Click(object sender, RoutedEventArgs e)
		{
			ModelLibraryControl modelLibraryControl = sender as ModelLibraryControl;
			if ((e.OriginalSource as OptionButton).Name == "PART_SelectorButton")
			{
				modelLibraryControl.IsOptionIconChecked = true;
			}
		}

		private static void DropdownButton_Click(object sender, RoutedEventArgs e)
		{
			ModelLibraryControl modelLibraryControl = sender as ModelLibraryControl;
			DropdownButton dropdownButton = e.OriginalSource as DropdownButton;
			if (dropdownButton.Name == "PART_StreamsDropdownButton")
			{
				modelLibraryControl.SelectedStreamModel = dropdownButton.SelectedItem as Model;
			}
		}

		private static void OnIsOptionIconCheckedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelLibraryControl).OnOnIsOptionIconCheckedChanged((bool)e.OldValue, (bool)e.NewValue);
		}

		private static void OnSelectedStreamModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelLibraryControl).OnSelectedStreamModelChanged((Model)e.OldValue, (Model)e.NewValue);
		}

		private static void OnSelectedBlockIconPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ModelLibraryControl).OnSelectedBlockIconChanged((Icon)e.OldValue, (Icon)e.NewValue);
		}
	}
	public class NotifyPropertyChangedBase : INotifyPropertyChanged
	{
		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	public class OptionButton : ContentControl
	{
		public static readonly DependencyProperty IsCheckedProperty;

		public static readonly DependencyProperty CheckedBackgroundProperty;

		public static readonly DependencyProperty ClickModeProperty;

		public static readonly RoutedEvent ClickEvent;

		public bool IsChecked
		{
			get
			{
				return (bool)GetValue(IsCheckedProperty);
			}
			set
			{
				SetValue(IsCheckedProperty, value);
			}
		}

		public Brush CheckedBackground
		{
			get
			{
				return (Brush)GetValue(CheckedBackgroundProperty);
			}
			set
			{
				SetValue(CheckedBackgroundProperty, value);
			}
		}

		public ClickMode ClickMode
		{
			get
			{
				return (ClickMode)GetValue(ClickModeProperty);
			}
			set
			{
				SetValue(ClickModeProperty, value);
			}
		}

		public event RoutedEventHandler Click
		{
			add
			{
				AddHandler(ClickEvent, value);
			}
			remove
			{
				RemoveHandler(ClickEvent, value);
			}
		}

		static OptionButton()
		{
			IsCheckedProperty = DependencyProperty.Register("IsChecked", typeof(bool), typeof(OptionButton));
			CheckedBackgroundProperty = DependencyProperty.Register("CheckedBackground", typeof(Brush), typeof(OptionButton), new FrameworkPropertyMetadata(Brushes.White));
			ClickModeProperty = DependencyProperty.Register("ClickMode", typeof(ClickMode), typeof(OptionButton), new FrameworkPropertyMetadata(ClickMode.Release));
			ClickEvent = EventManager.RegisterRoutedEvent("Click", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(OptionButton));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(OptionButton), new FrameworkPropertyMetadata(typeof(OptionButton)));
			FrameworkElement.MinWidthProperty.OverrideMetadata(typeof(OptionButton), new FrameworkPropertyMetadata(70.0));
			FrameworkElement.MinHeightProperty.OverrideMetadata(typeof(OptionButton), new FrameworkPropertyMetadata(70.0));
			Control.HorizontalContentAlignmentProperty.OverrideMetadata(typeof(OptionButton), new FrameworkPropertyMetadata(HorizontalAlignment.Stretch));
			Control.VerticalContentAlignmentProperty.OverrideMetadata(typeof(OptionButton), new FrameworkPropertyMetadata(VerticalAlignment.Stretch));
			EventManager.RegisterClassHandler(typeof(OptionButton), ButtonBase.ClickEvent, new RoutedEventHandler(Button_Click));
		}

		protected virtual void OnClick()
		{
			RaiseEvent(new RoutedEventArgs(ClickEvent, this));
		}

		private static void Button_Click(object sender, RoutedEventArgs e)
		{
			OptionButton obj = sender as OptionButton;
			if (obj.ClickMode == ClickMode.Press && Mouse.Captured != null)
			{
				Mouse.Captured.ReleaseMouseCapture();
			}
			obj.OnClick();
		}
	}
	[TemplatePart(Name = "PART_Popup", Type = typeof(Popup))]
	[TemplatePart(Name = "PART_Expander", Type = typeof(Expander))]
	public class DropdownButton : Selector
	{
		private const string PART_Expander = "PART_Expander";

		private const string PART_Popup = "PART_Popup";

		private const int DragValidLength = 10;

		private Popup _templatedPopup;

		private Expander _templatedExpander;

		public static readonly DependencyProperty IsCheckedProperty;

		public static readonly DependencyProperty ItemControlTemplateProperty;

		public static readonly DependencyProperty SelectedItemControlTemplateProperty;

		public static readonly DependencyProperty DefaultButtonBackgroundProperty;

		public static readonly DependencyProperty CheckedButtonBackgroundProperty;

		public static readonly RoutedEvent ClickEvent;

		public static readonly RoutedEvent PopupOpenedEvent;

		public static readonly DependencyProperty ButtonSizeProperty;

		public bool IsChecked
		{
			get
			{
				return (bool)GetValue(IsCheckedProperty);
			}
			set
			{
				SetValue(IsCheckedProperty, value);
			}
		}

		public ControlTemplate ItemControlTemplate
		{
			get
			{
				return (ControlTemplate)GetValue(ItemControlTemplateProperty);
			}
			set
			{
				SetValue(ItemControlTemplateProperty, value);
			}
		}

		public ControlTemplate SelectedItemControlTemplate
		{
			get
			{
				return (ControlTemplate)GetValue(SelectedItemControlTemplateProperty);
			}
			set
			{
				SetValue(SelectedItemControlTemplateProperty, value);
			}
		}

		public Brush DefaultButtonBackground
		{
			get
			{
				return (Brush)GetValue(DefaultButtonBackgroundProperty);
			}
			set
			{
				SetValue(DefaultButtonBackgroundProperty, value);
			}
		}

		public Brush CheckedButtonBackground
		{
			get
			{
				return (Brush)GetValue(CheckedButtonBackgroundProperty);
			}
			set
			{
				SetValue(CheckedButtonBackgroundProperty, value);
			}
		}

		public double ButtonSize
		{
			get
			{
				return (double)GetValue(ButtonSizeProperty);
			}
			set
			{
				SetValue(ButtonSizeProperty, value);
			}
		}

		public event RoutedEventHandler Click
		{
			add
			{
				AddHandler(ClickEvent, value);
			}
			remove
			{
				RemoveHandler(ClickEvent, value);
			}
		}

		public event RoutedEventHandler PopupOpened
		{
			add
			{
				AddHandler(PopupOpenedEvent, value);
			}
			remove
			{
				RemoveHandler(PopupOpenedEvent, value);
			}
		}

		static DropdownButton()
		{
			IsCheckedProperty = DependencyProperty.Register("IsChecked", typeof(bool), typeof(DropdownButton));
			ItemControlTemplateProperty = DependencyProperty.Register("ItemControlTemplate", typeof(ControlTemplate), typeof(DropdownButton));
			SelectedItemControlTemplateProperty = DependencyProperty.Register("SelectedItemControlTemplate", typeof(ControlTemplate), typeof(DropdownButton));
			DefaultButtonBackgroundProperty = DependencyProperty.Register("DefaultButtonBackground", typeof(Brush), typeof(DropdownButton), new FrameworkPropertyMetadata(Brushes.LightGray));
			CheckedButtonBackgroundProperty = DependencyProperty.Register("CheckedButtonBackground", typeof(Brush), typeof(DropdownButton), new FrameworkPropertyMetadata(Brushes.White));
			ClickEvent = EventManager.RegisterRoutedEvent("Click", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(DropdownButton));
			PopupOpenedEvent = EventManager.RegisterRoutedEvent("PopupOpened", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(DropdownButton));
			ButtonSizeProperty = DependencyProperty.Register("ButtonSize", typeof(double), typeof(DropdownButton), new UIPropertyMetadata(70.0));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(DropdownButton), new FrameworkPropertyMetadata(typeof(DropdownButton)));
			EventManager.RegisterClassHandler(typeof(DropdownButton), OptionButton.ClickEvent, new RoutedEventHandler(OptionButton_Click));
		}

		public override void OnApplyTemplate()
		{
			_templatedPopup = GetTemplateChild("PART_Popup") as Popup;
			if (_templatedPopup != null)
			{
				_templatedPopup.Opened += _templatedPopup_Opened;
				_templatedPopup.Closed += _templatedPopup_Closed;
			}
			_templatedExpander = GetTemplateChild("PART_Expander") as Expander;
			base.OnApplyTemplate();
		}

		private void _templatedPopup_Opened(object sender, EventArgs e)
		{
			OnPopupOpened();
			if (_templatedExpander != null)
			{
				_templatedExpander.IsHitTestVisible = false;
			}
		}

		private void _templatedPopup_Closed(object sender, EventArgs e)
		{
			if (_templatedExpander != null)
			{
				base.Dispatcher.BeginInvoke((Action)delegate
				{
					_templatedExpander.IsHitTestVisible = true;
				}, DispatcherPriority.Loaded);
			}
		}

		protected virtual void OnClick()
		{
			RaiseEvent(new RoutedEventArgs(ClickEvent, this));
		}

		protected virtual void OnPopupOpened()
		{
			RaiseEvent(new RoutedEventArgs(PopupOpenedEvent, this));
		}

		private static void OptionButton_Click(object sender, RoutedEventArgs e)
		{
			OptionButton optionButton = e.OriginalSource as OptionButton;
			DropdownButton dropdownButton = sender as DropdownButton;
			dropdownButton.SelectedItem = optionButton.Tag;
			dropdownButton.OnClick();
			if (dropdownButton._templatedPopup != null)
			{
				dropdownButton._templatedPopup.IsOpen = false;
			}
		}
	}
	[TemplatePart(Name = "PART_ScrollViewer", Type = typeof(ScrollViewer))]
	public class SlideBox : ContentControl
	{
		private ScrollViewer _scrollViewer;

		private const string PART_ScrollViewer = "PART_ScrollViewer";

		public static readonly DependencyProperty OrientationProperty;

		public static readonly DependencyProperty StepSizeProperty;

		public static readonly DependencyProperty ContentOffsetProperty;

		public static readonly RoutedUICommand MoveLeftCommand;

		public static readonly RoutedUICommand MoveRightCommand;

		public Orientation Orientation
		{
			get
			{
				return (Orientation)GetValue(OrientationProperty);
			}
			set
			{
				SetValue(OrientationProperty, value);
			}
		}

		public double StepSize
		{
			get
			{
				return (double)GetValue(StepSizeProperty);
			}
			set
			{
				SetValue(StepSizeProperty, value);
			}
		}

		public double ContentOffset
		{
			get
			{
				return (double)GetValue(ContentOffsetProperty);
			}
			set
			{
				SetValue(ContentOffsetProperty, value);
			}
		}

		public virtual bool CanMoveLeft
		{
			get
			{
				if (_scrollViewer != null)
				{
					if (Orientation == Orientation.Horizontal)
					{
						return _scrollViewer.HorizontalOffset > 0.0;
					}
					return _scrollViewer.VerticalOffset > 0.0;
				}
				return false;
			}
		}

		public virtual bool CanMoveRight
		{
			get
			{
				if (_scrollViewer != null)
				{
					if (Orientation == Orientation.Horizontal)
					{
						return _scrollViewer.ScrollableWidth > _scrollViewer.HorizontalOffset;
					}
					return _scrollViewer.ScrollableHeight > _scrollViewer.VerticalOffset;
				}
				return false;
			}
		}

		static SlideBox()
		{
			OrientationProperty = DependencyProperty.Register("Orientation", typeof(Orientation), typeof(SlideBox), new FrameworkPropertyMetadata(Orientation.Horizontal));
			StepSizeProperty = DependencyProperty.Register("StepSize", typeof(double), typeof(SlideBox), new FrameworkPropertyMetadata(74.0));
			ContentOffsetProperty = DependencyProperty.Register("ContentOffset", typeof(double), typeof(SlideBox), new FrameworkPropertyMetadata(0.0, OnContentOffsetPropertyChanged));
			MoveLeftCommand = new RoutedUICommand("Move Left", "MoveLeft", typeof(SlideBox));
			MoveRightCommand = new RoutedUICommand("Move Right", "MoveRight", typeof(SlideBox));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(SlideBox), new FrameworkPropertyMetadata(typeof(SlideBox)));
			CommandManager.RegisterClassCommandBinding(typeof(SlideBox), new CommandBinding(MoveLeftCommand, MoveLeftCommand_Executed, MoveLeftCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(SlideBox), new CommandBinding(MoveRightCommand, MoveRightCommand_Executed, MoveRightCommand_CanExecute));
		}

		public override void OnApplyTemplate()
		{
			_scrollViewer = GetTemplateChild("PART_ScrollViewer") as ScrollViewer;
			base.OnApplyTemplate();
		}

		protected virtual void OnContentOffsetChanged(double oldValue, double newValue)
		{
			if (_scrollViewer != null)
			{
				if (Orientation == Orientation.Horizontal)
				{
					_scrollViewer.ScrollToHorizontalOffset(newValue);
				}
				else
				{
					_scrollViewer.ScrollToVerticalOffset(newValue);
				}
				UpdateLayout();
			}
		}

		protected virtual void OnMovedLeft()
		{
			if (_scrollViewer != null)
			{
				if (Orientation == Orientation.Horizontal)
				{
					ChangeOffsetSlightly(_scrollViewer.HorizontalOffset, _scrollViewer.HorizontalOffset - StepSize);
				}
				else
				{
					ChangeOffsetSlightly(_scrollViewer.VerticalOffset, _scrollViewer.VerticalOffset - StepSize);
				}
			}
		}

		protected virtual void OnMovedRight()
		{
			if (_scrollViewer != null)
			{
				if (Orientation == Orientation.Horizontal)
				{
					ChangeOffsetSlightly(_scrollViewer.HorizontalOffset, _scrollViewer.HorizontalOffset + StepSize);
				}
				else
				{
					ChangeOffsetSlightly(_scrollViewer.VerticalOffset, _scrollViewer.VerticalOffset + StepSize);
				}
			}
		}

		private void ChangeOffsetSlightly(double startOffset, double endOffset)
		{
			DoubleAnimation doubleAnimation = new DoubleAnimation(startOffset, endOffset, new Duration(new TimeSpan(0, 0, 0, 0, 100)), FillBehavior.HoldEnd);
			Storyboard.SetTargetName(doubleAnimation, "PART_SlideBox");
			Storyboard.SetTargetProperty(doubleAnimation, new PropertyPath(ContentOffsetProperty));
			Storyboard storyboard = new Storyboard();
			storyboard.Children.Add(doubleAnimation);
			storyboard.Begin(this);
			if (_scrollViewer != null)
			{
				if (Orientation == Orientation.Horizontal)
				{
					_scrollViewer.ScrollToHorizontalOffset(endOffset);
				}
				else
				{
					_scrollViewer.ScrollToVerticalOffset(endOffset);
				}
				UpdateLayout();
			}
		}

		private static void MoveLeftCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as SlideBox).OnMovedLeft();
		}

		private static void MoveLeftCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			SlideBox slideBox = sender as SlideBox;
			e.CanExecute = slideBox.CanMoveLeft;
		}

		private static void MoveRightCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as SlideBox).OnMovedRight();
		}

		private static void MoveRightCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			SlideBox slideBox = sender as SlideBox;
			e.CanExecute = slideBox.CanMoveRight;
		}

		private static void OnContentOffsetPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as SlideBox).OnContentOffsetChanged((double)e.OldValue, (double)e.NewValue);
		}
	}
	[ContentProperty("Items")]
	public class WizardControl : Control
	{
		private int _loadedTimes;

		private readonly Stack<WizardControlItem> _nagivationHistory = new Stack<WizardControlItem>();

		private static readonly DependencyPropertyKey ItemsPropertyKey;

		public static readonly DependencyProperty ItemsProperty;

		private static readonly DependencyPropertyKey CurrentItemPropertyKey;

		public static readonly DependencyProperty CurrentItemProperty;

		private static readonly DependencyPropertyKey CanForwardPropertyKey;

		public static readonly DependencyProperty CanForwardProperty;

		private static readonly DependencyPropertyKey CanBackwardPropertyKey;

		public static readonly DependencyProperty CanBackwardProperty;

		private static readonly DependencyPropertyKey CanFinishPropertyKey;

		public static readonly DependencyProperty CanFinishProperty;

		private static readonly DependencyPropertyKey CanCancelPropertyKey;

		public static readonly DependencyProperty CanCancelProperty;

		public static readonly RoutedUICommand BackwardCommand;

		public static readonly RoutedUICommand ForwardCommand;

		public static readonly RoutedUICommand FinishCommand;

		public static readonly RoutedEvent FinishedEvent;

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public WizardControlItemCollection Items
		{
			get
			{
				return (WizardControlItemCollection)GetValue(ItemsProperty);
			}
			private set
			{
				SetValue(ItemsPropertyKey, value);
			}
		}

		public WizardControlItem CurrentItem
		{
			get
			{
				return (WizardControlItem)GetValue(CurrentItemProperty);
			}
			private set
			{
				SetValue(CurrentItemPropertyKey, value);
			}
		}

		public bool CanForward
		{
			get
			{
				return (bool)GetValue(CanForwardProperty);
			}
			private set
			{
				SetValue(CanForwardPropertyKey, value);
			}
		}

		public bool CanBackward
		{
			get
			{
				return (bool)GetValue(CanBackwardProperty);
			}
			private set
			{
				SetValue(CanBackwardPropertyKey, value);
			}
		}

		public bool CanFinish
		{
			get
			{
				return (bool)GetValue(CanFinishProperty);
			}
			private set
			{
				SetValue(CanFinishPropertyKey, value);
			}
		}

		public bool CanCancel
		{
			get
			{
				return (bool)GetValue(CanCancelProperty);
			}
			private set
			{
				SetValue(CanCancelPropertyKey, value);
			}
		}

		public event RoutedEventHandler Finished
		{
			add
			{
				AddHandler(FinishedEvent, value);
			}
			remove
			{
				RemoveHandler(FinishedEvent, value);
			}
		}

		static WizardControl()
		{
			ItemsPropertyKey = DependencyProperty.RegisterReadOnly("Items", typeof(WizardControlItemCollection), typeof(WizardControl), new FrameworkPropertyMetadata());
			ItemsProperty = ItemsPropertyKey.DependencyProperty;
			CurrentItemPropertyKey = DependencyProperty.RegisterReadOnly("CurrentItem", typeof(WizardControlItem), typeof(WizardControl), new FrameworkPropertyMetadata(OnWizardControlItemChanged));
			CurrentItemProperty = CurrentItemPropertyKey.DependencyProperty;
			CanForwardPropertyKey = DependencyProperty.RegisterReadOnly("CanForward", typeof(bool), typeof(WizardControl), new FrameworkPropertyMetadata(false));
			CanForwardProperty = CanForwardPropertyKey.DependencyProperty;
			CanBackwardPropertyKey = DependencyProperty.RegisterReadOnly("CanBackward", typeof(bool), typeof(WizardControl), new FrameworkPropertyMetadata(false));
			CanBackwardProperty = CanBackwardPropertyKey.DependencyProperty;
			CanFinishPropertyKey = DependencyProperty.RegisterReadOnly("CanFinish", typeof(bool), typeof(WizardControl), new FrameworkPropertyMetadata(false));
			CanFinishProperty = CanFinishPropertyKey.DependencyProperty;
			CanCancelPropertyKey = DependencyProperty.RegisterReadOnly("CanCancel", typeof(bool), typeof(WizardControl), new FrameworkPropertyMetadata(false));
			CanCancelProperty = CanCancelPropertyKey.DependencyProperty;
			BackwardCommand = new RoutedUICommand("Back", "BackwardCommand", typeof(WizardControl));
			ForwardCommand = new RoutedUICommand("Next", "ForwardCommand", typeof(WizardControl));
			FinishCommand = new RoutedUICommand("Finish", "FinishCommand", typeof(WizardControl));
			FinishedEvent = EventManager.RegisterRoutedEvent("Finished", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(WizardControl));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(WizardControl), new FrameworkPropertyMetadata(typeof(WizardControl)));
			CommandManager.RegisterClassCommandBinding(typeof(WizardControl), new CommandBinding(BackwardCommand, BackwardCommand_Executed, BackwardCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(WizardControl), new CommandBinding(ForwardCommand, ForwardCommand_Executed, ForwardCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(WizardControl), new CommandBinding(FinishCommand, FinishCommand_Executed, FinishCommand_CanExecute));
		}

		public WizardControl()
		{
			Items = new WizardControlItemCollection(this);
			base.Loaded += WizardControl_Loaded;
		}

		private void WizardControl_Loaded(object sender, RoutedEventArgs e)
		{
			if (_loadedTimes == 0)
			{
				if (CurrentItem == null)
				{
					CurrentItem = Items.FirstOrDefault();
				}
				if (CurrentItem != null && _nagivationHistory.Count == 0)
				{
					CurrentItem.OnEnter(null, positiveDirection: true);
				}
			}
			_loadedTimes++;
		}

		public void GoForward()
		{
			if (CanForward)
			{
				WizardControlItem currentItem = CurrentItem;
				WizardControlItem wizardControlItem = ((currentItem.ForwardItem != null) ? currentItem.ForwardItem : Items[Items.IndexOf(currentItem) + 1]);
				if (currentItem.OnForward(wizardControlItem))
				{
					_nagivationHistory.Push(currentItem);
					CurrentItem = wizardControlItem;
					wizardControlItem.OnEnter(currentItem, positiveDirection: true);
				}
			}
		}

		public void GoBackward()
		{
			if (CanBackward)
			{
				WizardControlItem currentItem = CurrentItem;
				WizardControlItem wizardControlItem = _nagivationHistory.Peek();
				if (currentItem.OnBackward(wizardControlItem))
				{
					_nagivationHistory.Pop();
					CurrentItem = wizardControlItem;
					wizardControlItem.OnEnter(currentItem, positiveDirection: false);
				}
			}
		}

		public void Finish()
		{
			if (!CanFinish)
			{
				return;
			}
			WizardControlItem currentItem = CurrentItem;
			if (currentItem != null && currentItem.GetType().Name.Equals("UserDefinedComp1") && !currentItem.OnForward(null))
			{
				return;
			}
			foreach (WizardControlItem item in Items)
			{
				if (!item.OnFinished())
				{
					return;
				}
			}
			OnFinished();
		}

		public void Reset()
		{
			CurrentItem = Items.FirstOrDefault();
			_nagivationHistory.Clear();
		}

		public void RefreshEnableStatus()
		{
			if (CurrentItem == null)
			{
				bool flag = (CanCancel = false);
				bool flag3 = (CanFinish = flag);
				bool canBackward = (CanForward = flag3);
				CanBackward = canBackward;
				return;
			}
			CanFinish = CurrentItem.CanFinish;
			if (Items.Contains(CurrentItem))
			{
				int num = Items.IndexOf(CurrentItem);
				CanForward = (CurrentItem.ForwardItem != null || num < Items.Count - 1) && CurrentItem.CanForward;
				CanCancel = CurrentItem.CanCancel;
				CanBackward = _nagivationHistory.Count > 0 && CurrentItem.CanBackward;
			}
			else
			{
				CanForward = CurrentItem.ForwardItem != null && CurrentItem.CanForward;
			}
		}

		protected virtual void OnFinished()
		{
			RaiseEvent(new RoutedEventArgs(FinishedEvent, this));
		}

		private static void OnWizardControlItemChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as WizardControl).RefreshEnableStatus();
		}

		private static void BackwardCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as WizardControl).GoBackward();
		}

		private static void BackwardCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			WizardControl wizardControl = sender as WizardControl;
			e.CanExecute = wizardControl.CanBackward;
		}

		private static void ForwardCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as WizardControl).GoForward();
		}

		private static void ForwardCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			WizardControl wizardControl = sender as WizardControl;
			e.CanExecute = wizardControl.CanForward;
		}

		private static void FinishCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as WizardControl).Finish();
		}

		private static void FinishCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			WizardControl wizardControl = sender as WizardControl;
			e.CanExecute = wizardControl.CanFinish;
		}
	}
	public class WizardControlItem : ContentControl
	{
		private int _enteredTimes;

		public static readonly DependencyProperty TitleProperty;

		public static readonly DependencyProperty CanForwardProperty;

		public static readonly DependencyProperty CanBackwardProperty;

		public static readonly DependencyProperty CanFinishProperty;

		public static readonly DependencyProperty CanCancelProperty;

		public static readonly DependencyProperty UseScrollViewerInsideProperty;

		public static readonly DependencyProperty ForwardItemProperty;

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

		public bool CanForward
		{
			get
			{
				return (bool)GetValue(CanForwardProperty);
			}
			set
			{
				SetValue(CanForwardProperty, value);
			}
		}

		public bool CanBackward
		{
			get
			{
				return (bool)GetValue(CanBackwardProperty);
			}
			set
			{
				SetValue(CanBackwardProperty, value);
			}
		}

		public bool CanFinish
		{
			get
			{
				return (bool)GetValue(CanFinishProperty);
			}
			set
			{
				SetValue(CanFinishProperty, value);
			}
		}

		public bool CanCancel
		{
			get
			{
				return (bool)GetValue(CanCancelProperty);
			}
			set
			{
				SetValue(CanCancelProperty, value);
			}
		}

		public bool UseScrollViewerInside
		{
			get
			{
				return (bool)GetValue(UseScrollViewerInsideProperty);
			}
			set
			{
				SetValue(UseScrollViewerInsideProperty, value);
			}
		}

		public WizardControlItem ForwardItem
		{
			get
			{
				return (WizardControlItem)GetValue(ForwardItemProperty);
			}
			set
			{
				SetValue(ForwardItemProperty, value);
			}
		}

		public WizardControl ParentWizard { get; internal set; }

		protected bool IsEnteredFirstTime { get; private set; }

		static WizardControlItem()
		{
			TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(WizardControlItem));
			CanForwardProperty = DependencyProperty.Register("CanForward", typeof(bool), typeof(WizardControlItem), new FrameworkPropertyMetadata(false, OnCanForwardPropertyChanged));
			CanBackwardProperty = DependencyProperty.Register("CanBackward", typeof(bool), typeof(WizardControlItem), new FrameworkPropertyMetadata(true, OnCanBackwardPropertyChanged));
			CanFinishProperty = DependencyProperty.Register("CanFinish", typeof(bool), typeof(WizardControlItem), new FrameworkPropertyMetadata(false, OnCanFinishPropertyChanged));
			CanCancelProperty = DependencyProperty.Register("CanCancel", typeof(bool), typeof(WizardControlItem), new FrameworkPropertyMetadata(true, OnCanCancelPropertyChanged));
			UseScrollViewerInsideProperty = DependencyProperty.Register("UseScrollViewerInside", typeof(bool), typeof(WizardControlItem), new FrameworkPropertyMetadata(false));
			ForwardItemProperty = DependencyProperty.Register("ForwardItem", typeof(WizardControlItem), typeof(WizardControlItem), new FrameworkPropertyMetadata(OnForwardItemPropertyChanged));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(WizardControlItem), new FrameworkPropertyMetadata(typeof(WizardControlItem)));
		}

		protected internal virtual void OnEnter(WizardControlItem previousItem, bool positiveDirection)
		{
			IsEnteredFirstTime = _enteredTimes == 0;
			_enteredTimes++;
		}

		protected internal virtual bool OnForward(WizardControlItem targetItem)
		{
			return true;
		}

		protected internal virtual bool OnBackward(WizardControlItem targetItem)
		{
			return true;
		}

		protected internal virtual bool OnFinished()
		{
			return true;
		}

		private static void OnCanForwardPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			WizardControlItem wizardControlItem = d as WizardControlItem;
			if (wizardControlItem.ParentWizard != null)
			{
				wizardControlItem.ParentWizard.RefreshEnableStatus();
			}
		}

		private static void OnCanBackwardPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			WizardControlItem wizardControlItem = d as WizardControlItem;
			if (wizardControlItem.ParentWizard != null)
			{
				wizardControlItem.ParentWizard.RefreshEnableStatus();
			}
		}

		private static void OnCanFinishPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			WizardControlItem wizardControlItem = d as WizardControlItem;
			if (wizardControlItem.ParentWizard != null)
			{
				wizardControlItem.ParentWizard.RefreshEnableStatus();
			}
		}

		private static void OnCanCancelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			WizardControlItem wizardControlItem = d as WizardControlItem;
			if (wizardControlItem.ParentWizard != null)
			{
				wizardControlItem.ParentWizard.RefreshEnableStatus();
			}
		}

		private static void OnForwardItemPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			WizardControlItem wizardControlItem = d as WizardControlItem;
			if (wizardControlItem.ParentWizard != null)
			{
				wizardControlItem.ParentWizard.RefreshEnableStatus();
			}
		}
	}
	public class WizardControlItemCollection : ObservableCollection<WizardControlItem>
	{
		private readonly WizardControl _parentWizard;

		public WizardControlItemCollection(WizardControl parentWizard)
		{
			if (parentWizard == null)
			{
				throw new ArgumentNullException("parentWizard");
			}
			_parentWizard = parentWizard;
		}

		protected override void InsertItem(int index, WizardControlItem item)
		{
			item.ParentWizard = _parentWizard;
			base.InsertItem(index, item);
		}

		protected override void RemoveItem(int index)
		{
			base.Items[index].ParentWizard = null;
			base.RemoveItem(index);
		}
	}
}
namespace AspenTech.AspenPlus.ModelLibrary.Controls.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
namespace AspenTech.AspenPlus.ModelLibrary.Controls.Converters
{
	[ValueConversion(typeof(int), typeof(double))]
	public class DropdownPopupWidthConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue)
			{
				int? num = value as int?;
				if (num.HasValue)
				{
					int num2 = (int)Math.Sqrt(num.Value);
					return (double)FrameworkElement.MinWidthProperty.GetMetadata(typeof(OptionButton)).DefaultValue * (double)num2 + (double)(num2 * 2 * 2);
				}
			}
			return 0.0;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	[ValueConversion(typeof(int), typeof(Visibility))]
	public class ExpanderVisibilityConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue)
			{
				int? num = value as int?;
				if (num.HasValue)
				{
					return (num.Value <= 1) ? Visibility.Collapsed : Visibility.Visible;
				}
			}
			return Visibility.Collapsed;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class PopupIconIsCheckedConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 3)
			{
				bool num = (bool)values[0];
				object obj = values[1];
				object obj2 = values[2];
				return num && obj == obj2;
			}
			return false;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class StreamIsCheckedConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 2)
			{
				Model model = values[0] as Model;
				if (values[1] is Model model2 && model != null)
				{
					return model == model2;
				}
			}
			return false;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}
