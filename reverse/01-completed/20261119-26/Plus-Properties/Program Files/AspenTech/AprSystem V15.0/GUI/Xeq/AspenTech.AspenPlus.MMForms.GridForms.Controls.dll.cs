using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using System.Xml.Linq;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMForms.GridForms.Controls.Data;
using AspenTech.Engineering.GridControls;
using AspenTech.Engineering.GridControls.Internal;
using AspenTech.Visualisation.CommonImages;
using AspenTech.Visualisation.Controls.Support.Commands;
using Infragistics.Windows;
using Infragistics.Windows.Controls;
using Infragistics.Windows.DataPresenter;
using Infragistics.Windows.Editors;
using Infragistics.Windows.Editors.Events;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMForms.GridForms.Controls")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.MMForms.GridForms.Controls")]
[assembly: AssemblyCopyright("Copyright © Aspen Technolgy, Inc 2011 - 2024")]
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
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls
{
	public class BreadCrumbNavigator : Control
	{
		public static readonly RoutedCommand NodeTextClickedCommand;

		public static readonly RoutedCommand NodeDropDownClickedCommand;

		public static readonly DependencyProperty HeaderProperty;

		public static readonly DependencyProperty RootNodeProperty;

		public static readonly DependencyProperty SelectedNodeProperty;

		private static readonly DependencyPropertyKey TiledNodesPropertyKey;

		public static readonly DependencyProperty TiledNodesProperty;

		public static readonly RoutedEvent SelectedNodeChangedEvent;

		public string Header
		{
			get
			{
				return (string)GetValue(HeaderProperty);
			}
			set
			{
				SetValue(HeaderProperty, value);
			}
		}

		public BreadCrumbNode RootNode
		{
			get
			{
				return (BreadCrumbNode)GetValue(RootNodeProperty);
			}
			set
			{
				SetValue(RootNodeProperty, value);
			}
		}

		public BreadCrumbNode SelectedNode
		{
			get
			{
				return (BreadCrumbNode)GetValue(SelectedNodeProperty);
			}
			set
			{
				SetValue(SelectedNodeProperty, value);
			}
		}

		public IEnumerable<BreadCrumbNode> TiledNodes
		{
			get
			{
				return (IEnumerable<BreadCrumbNode>)GetValue(TiledNodesProperty);
			}
			private set
			{
				SetValue(TiledNodesPropertyKey, value);
			}
		}

		public event RoutedEventHandler SelectedNodeChanged
		{
			add
			{
				AddHandler(SelectedNodeChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectedNodeChangedEvent, value);
			}
		}

		static BreadCrumbNavigator()
		{
			NodeTextClickedCommand = new RoutedCommand("NodeTextClicked", typeof(BreadCrumbNavigator));
			NodeDropDownClickedCommand = new RoutedCommand("NodeDropDownClicked", typeof(BreadCrumbNavigator));
			HeaderProperty = DependencyProperty.Register("Header", typeof(string), typeof(BreadCrumbNavigator));
			RootNodeProperty = DependencyProperty.Register("RootNode", typeof(BreadCrumbNode), typeof(BreadCrumbNavigator), new FrameworkPropertyMetadata(OnRootNodePropertyChanged));
			SelectedNodeProperty = DependencyProperty.Register("SelectedNode", typeof(BreadCrumbNode), typeof(BreadCrumbNavigator), new FrameworkPropertyMetadata(OnSelectedNodePropertyChanged));
			TiledNodesPropertyKey = DependencyProperty.RegisterReadOnly("TiledNodes", typeof(IEnumerable<BreadCrumbNode>), typeof(BreadCrumbNavigator), null);
			TiledNodesProperty = TiledNodesPropertyKey.DependencyProperty;
			SelectedNodeChangedEvent = EventManager.RegisterRoutedEvent("SelectedNodeChanged", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(BreadCrumbNavigator));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(BreadCrumbNavigator), new FrameworkPropertyMetadata(typeof(BreadCrumbNavigator)));
			CommandManager.RegisterClassCommandBinding(typeof(BreadCrumbNavigator), new CommandBinding(NodeTextClickedCommand, NodeTextClickedCommand_Executed, NodeTextClickedCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(BreadCrumbNavigator), new CommandBinding(NodeDropDownClickedCommand, NodeDropDownClickedCommand_Executed, NodeDropDownClickedCommand_CanExecute));
		}

		protected virtual void OnRootNodeChanged(BreadCrumbNode oldValue, BreadCrumbNode newValue)
		{
			if (SelectedNode == null)
			{
				SelectedNode = RootNode;
				return;
			}
			BreadCrumbNode breadCrumbNode = FindByPath(SelectedNode.TextsPath);
			SelectedNode = breadCrumbNode ?? RootNode;
		}

		protected virtual void OnSelectedNodeChanged(BreadCrumbNode oldValue, BreadCrumbNode newValue)
		{
			TiledNodes = BuildTiledNodes();
			RaiseEvent(new RoutedEventArgs(SelectedNodeChangedEvent, this));
		}

		private BreadCrumbNode FindByPath(IEnumerable<string> textsPath)
		{
			if (textsPath != null && RootNode != null)
			{
				List<string> texts = textsPath.ToList();
				if (texts.Count >= 2)
				{
					BreadCrumbNode breadCrumbNode = RootNode;
					int i;
					for (i = 1; i < texts.Count; i++)
					{
						breadCrumbNode = breadCrumbNode.Children.FirstOrDefault((BreadCrumbNode x) => string.Equals(x.Text, texts[i], StringComparison.CurrentCulture));
						if (breadCrumbNode == null)
						{
							break;
						}
					}
					return breadCrumbNode;
				}
			}
			return null;
		}

		private IEnumerable<BreadCrumbNode> BuildTiledNodes()
		{
			List<BreadCrumbNode> list = new List<BreadCrumbNode>();
			for (BreadCrumbNode breadCrumbNode = SelectedNode; breadCrumbNode != null; breadCrumbNode = breadCrumbNode.Parent)
			{
				list.Insert(0, breadCrumbNode);
			}
			return list;
		}

		private void OpenDropDown(BreadCrumbNode node, object originalSource)
		{
			if (node == null || !node.HasChildren)
			{
				return;
			}
			ContextMenu contextMenu = new ContextMenu();
			foreach (BreadCrumbNode child in node.Children)
			{
				MenuItem newItem = new MenuItem
				{
					Header = child.Text,
					Command = NodeTextClickedCommand,
					CommandParameter = child,
					CommandTarget = this
				};
				contextMenu.Items.Add(newItem);
			}
			if (originalSource is UIElement placementTarget)
			{
				contextMenu.PlacementTarget = placementTarget;
				contextMenu.Placement = PlacementMode.Bottom;
			}
			contextMenu.IsOpen = true;
		}

		private static void OnRootNodePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as BreadCrumbNavigator).OnRootNodeChanged((BreadCrumbNode)e.OldValue, (BreadCrumbNode)e.NewValue);
		}

		private static void OnSelectedNodePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as BreadCrumbNavigator).OnSelectedNodeChanged((BreadCrumbNode)e.OldValue, (BreadCrumbNode)e.NewValue);
		}

		private static void NodeTextClickedCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as BreadCrumbNavigator).SelectedNode = e.Parameter as BreadCrumbNode;
		}

		private static void NodeTextClickedCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = true;
		}

		private static void NodeDropDownClickedCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as BreadCrumbNavigator).OpenDropDown(e.Parameter as BreadCrumbNode, e.OriginalSource);
		}

		private static void NodeDropDownClickedCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			e.CanExecute = true;
		}
	}
	public class BreadCrumbNode : DependencyObject
	{
		public static readonly DependencyProperty TextProperty = DependencyProperty.Register("Text", typeof(string), typeof(BreadCrumbNode));

		public static readonly DependencyProperty TagProperty = DependencyProperty.Register("Tag", typeof(object), typeof(BreadCrumbNode));

		private static readonly DependencyPropertyKey HasChildrenPropertyKey = DependencyProperty.RegisterReadOnly("HasChildren", typeof(bool), typeof(BreadCrumbNode), null);

		public static readonly DependencyProperty HasChildrenProperty = HasChildrenPropertyKey.DependencyProperty;

		public string Text
		{
			get
			{
				return (string)GetValue(TextProperty);
			}
			set
			{
				SetValue(TextProperty, value);
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

		[DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
		public BreadCrumbNodeCollection Children { get; private set; }

		public bool HasChildren
		{
			get
			{
				return (bool)GetValue(HasChildrenProperty);
			}
			private set
			{
				SetValue(HasChildrenPropertyKey, value);
			}
		}

		public BreadCrumbNode Parent { get; private set; }

		public IEnumerable<string> TextsPath
		{
			get
			{
				List<string> list = new List<string>();
				for (BreadCrumbNode breadCrumbNode = this; breadCrumbNode != null; breadCrumbNode = breadCrumbNode.Parent)
				{
					list.Insert(0, breadCrumbNode.Text);
				}
				return list;
			}
		}

		public BreadCrumbNode()
		{
			Children = new BreadCrumbNodeCollection(this);
		}

		internal void UpdateOnCollectionChanged()
		{
			foreach (BreadCrumbNode child in Children)
			{
				child.Parent = this;
			}
			HasChildren = Children.Count > 0;
		}
	}
	public class BreadCrumbNodeCollection : ObservableCollection<BreadCrumbNode>
	{
		private readonly BreadCrumbNode _parent;

		public BreadCrumbNodeCollection(BreadCrumbNode parent)
		{
			if (parent == null)
			{
				throw new ArgumentNullException("parent");
			}
			_parent = parent;
		}

		protected override void OnCollectionChanged(NotifyCollectionChangedEventArgs e)
		{
			_parent.UpdateOnCollectionChanged();
			base.OnCollectionChanged(e);
		}
	}
	public class CheckableComboBox : Control
	{
		private ToggleButton _dropdownButton;

		private readonly PopupSelector _popupSelector;

		private readonly ObservableCollection<CheckableItem> _popupItems;

		public static readonly DependencyProperty ItemsProperty;

		private static readonly DependencyPropertyKey SelectedItemsPropertyKey;

		public static readonly DependencyProperty SelectedItemsProperty;

		public static readonly DependencyProperty IsPopupOpenProperty;

		private static readonly DependencyPropertyKey TextPropertyKey;

		public static readonly DependencyProperty TextProperty;

		private static readonly DependencyPropertyKey DisplayedTextPropertyKey;

		public static readonly DependencyProperty DisplayedTextProperty;

		public static readonly DependencyProperty EmptyTextProperty;

		public static readonly DependencyProperty ItemsSplitterProperty;

		public static readonly DependencyProperty PopupWidthProperty;

		public static readonly DependencyProperty PopupHeightProperty;

		private static readonly DependencyPropertyKey IsPopupEnabledPropertyKey;

		public static readonly DependencyProperty IsPopupEnabledProperty;

		public static readonly RoutedEvent SelectionChangedEvent;

		public static readonly DependencyProperty SuppressSelectionChangedProperty;

		public IEnumerable Items
		{
			get
			{
				return (IEnumerable)GetValue(ItemsProperty);
			}
			set
			{
				SetValue(ItemsProperty, value);
			}
		}

		public ObservableCollection<object> SelectedItems
		{
			get
			{
				return (ObservableCollection<object>)GetValue(SelectedItemsProperty);
			}
			private set
			{
				SetValue(SelectedItemsPropertyKey, value);
			}
		}

		public bool IsPopupOpen
		{
			get
			{
				return (bool)GetValue(IsPopupOpenProperty);
			}
			set
			{
				SetValue(IsPopupOpenProperty, value);
			}
		}

		public string Text
		{
			get
			{
				return (string)GetValue(TextProperty);
			}
			private set
			{
				SetValue(TextPropertyKey, value);
			}
		}

		public string DisplayedText
		{
			get
			{
				return (string)GetValue(DisplayedTextProperty);
			}
			private set
			{
				SetValue(DisplayedTextPropertyKey, value);
			}
		}

		public string EmptyText
		{
			get
			{
				return (string)GetValue(EmptyTextProperty);
			}
			set
			{
				SetValue(EmptyTextProperty, value);
			}
		}

		public object ItemsSplitter
		{
			get
			{
				return GetValue(ItemsSplitterProperty);
			}
			set
			{
				SetValue(ItemsSplitterProperty, value);
			}
		}

		public double PopupWidth
		{
			get
			{
				return (double)GetValue(PopupWidthProperty);
			}
			set
			{
				SetValue(PopupWidthProperty, value);
			}
		}

		public double PopupHeight
		{
			get
			{
				return (double)GetValue(PopupHeightProperty);
			}
			set
			{
				SetValue(PopupHeightProperty, value);
			}
		}

		public bool IsPopupEnabled
		{
			get
			{
				return (bool)GetValue(IsPopupEnabledProperty);
			}
			private set
			{
				SetValue(IsPopupEnabledPropertyKey, value);
			}
		}

		public bool SuppressSelectionChanged
		{
			get
			{
				return (bool)GetValue(SuppressSelectionChangedProperty);
			}
			set
			{
				SetValue(SuppressSelectionChangedProperty, value);
			}
		}

		public event RoutedEventHandler SelectionChanged
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

		static CheckableComboBox()
		{
			ItemsProperty = DependencyProperty.Register("Items", typeof(IEnumerable), typeof(CheckableComboBox), new FrameworkPropertyMetadata(OnItemsPropertyChanged));
			SelectedItemsPropertyKey = DependencyProperty.RegisterReadOnly("SelectedItems", typeof(ObservableCollection<object>), typeof(CheckableComboBox), new FrameworkPropertyMetadata());
			SelectedItemsProperty = SelectedItemsPropertyKey.DependencyProperty;
			IsPopupOpenProperty = DependencyProperty.Register("IsPopupOpen", typeof(bool), typeof(CheckableComboBox));
			TextPropertyKey = DependencyProperty.RegisterReadOnly("Text", typeof(string), typeof(CheckableComboBox), new FrameworkPropertyMetadata(OnTextPropertyChanged));
			TextProperty = TextPropertyKey.DependencyProperty;
			DisplayedTextPropertyKey = DependencyProperty.RegisterReadOnly("DisplayedText", typeof(string), typeof(CheckableComboBox), new FrameworkPropertyMetadata());
			DisplayedTextProperty = DisplayedTextPropertyKey.DependencyProperty;
			EmptyTextProperty = DependencyProperty.Register("EmptyText", typeof(string), typeof(CheckableComboBox), new FrameworkPropertyMetadata(OnEmptyTextPropertyPropertyChanged));
			ItemsSplitterProperty = DependencyProperty.Register("ItemsSplitter", typeof(object), typeof(CheckableComboBox), new FrameworkPropertyMetadata(", ", OnItemsSplitterPropertyChanged));
			PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(CheckableComboBox), new FrameworkPropertyMetadata(200.0));
			PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(CheckableComboBox), new UIPropertyMetadata(250.0));
			IsPopupEnabledPropertyKey = DependencyProperty.RegisterReadOnly("IsPopupEnabled", typeof(bool), typeof(CheckableComboBox), null);
			IsPopupEnabledProperty = IsPopupEnabledPropertyKey.DependencyProperty;
			SelectionChangedEvent = EventManager.RegisterRoutedEvent("SelectionChanged", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(CheckableComboBox));
			SuppressSelectionChangedProperty = DependencyProperty.Register("SuppressSelectionChanged", typeof(bool), typeof(CheckableComboBox));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(CheckableComboBox), new FrameworkPropertyMetadata(typeof(CheckableComboBox)));
		}

		public CheckableComboBox()
		{
			_popupItems = new ObservableCollection<CheckableItem>();
			_popupSelector = new PopupSelector
			{
				StaysOpen = false,
				PlacementTarget = this,
				Items = _popupItems
			};
			_popupSelector.SetBinding(Popup.IsOpenProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(IsPopupOpenProperty),
				Mode = BindingMode.TwoWay
			});
			_popupSelector.SetBinding(PopupSelector.PopupWidthProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(PopupWidthProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.SetBinding(PopupSelector.PopupHeightProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(PopupHeightProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.Opened += _popupSelector_Opened;
			_popupSelector.Closed += _popupSelector_Closed;
			SelectedItems = new ObservableCollection<object>();
			SelectedItems.CollectionChanged += SelectedItems_CollectionChanged;
		}

		private void _popupSelector_Opened(object sender, System.EventArgs e)
		{
			if (_dropdownButton != null)
			{
				_dropdownButton.IsHitTestVisible = false;
			}
		}

		private void _popupSelector_Closed(object sender, System.EventArgs e)
		{
			base.Dispatcher.BeginInvoke((Action)delegate
			{
				if (_dropdownButton != null)
				{
					_dropdownButton.IsHitTestVisible = true;
				}
			}, DispatcherPriority.Loaded);
		}

		public override void OnApplyTemplate()
		{
			_dropdownButton = GetTemplateChild("PART_DropDownButton") as ToggleButton;
			base.OnApplyTemplate();
		}

		protected virtual void OnSelectionChanged()
		{
			RaiseEvent(new RoutedEventArgs(SelectionChangedEvent, this));
		}

		private void SelectedItems_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			foreach (CheckableItem popupItem in _popupItems)
			{
				popupItem.IsChecked = SelectedItems.Contains(popupItem.Content);
			}
			RefreshContent();
			if (!SuppressSelectionChanged)
			{
				OnSelectionChanged();
			}
		}

		protected virtual void OnItemsChanged(IEnumerable oldValue, IEnumerable newValue)
		{
			_popupItems.Where((CheckableItem x) => x.IsChecked).ToList();
			_popupItems.Clear();
			if (newValue != null)
			{
				foreach (object item in newValue)
				{
					if (item != null)
					{
						_popupItems.Add(new CheckableItem
						{
							Content = item,
							IsChecked = SelectedItems.Contains(item),
							IsCheckedChangedAction = OnCheckableItemIsCheckedChanged
						});
					}
				}
			}
			UpdatePopupEnabled();
		}

		public void ReInitialize(IEnumerable items, string serializedSelectedItems, bool suppressEvent)
		{
			bool suppressSelectionChanged = SuppressSelectionChanged;
			if (suppressEvent)
			{
				SuppressSelectionChanged = suppressEvent;
			}
			if (items != null)
			{
				Items = from object x in items
					where x != null
					select x;
			}
			else
			{
				Items = null;
			}
			SelectedItems.Clear();
			if (Items != null)
			{
				IEnumerable<object> source = Items.Cast<object>();
				foreach (string si in StringArraySerializer.Deserialize(serializedSelectedItems))
				{
					object obj = source.FirstOrDefault((object x) => string.Equals(x.ToString().Trim(), si.Trim(), StringComparison.CurrentCultureIgnoreCase));
					if (obj != null && !SelectedItems.Contains(obj))
					{
						SelectedItems.Add(obj);
					}
				}
			}
			SuppressSelectionChanged = suppressSelectionChanged;
		}

		private void UpdatePopupEnabled()
		{
			if (Items == null || Items.Cast<object>().Count() == 0)
			{
				if (IsPopupEnabled)
				{
					IsPopupEnabled = false;
				}
			}
			else if (!IsPopupEnabled)
			{
				IsPopupEnabled = true;
			}
		}

		private void OnCheckableItemIsCheckedChanged(CheckableItem item)
		{
			if (item != null)
			{
				if (item.IsChecked && !SelectedItems.Contains(item.Content))
				{
					SelectedItems.Add(item.Content);
				}
				if (!item.IsChecked && SelectedItems.Contains(item.Content))
				{
					SelectedItems.Remove(item.Content);
				}
			}
		}

		private void RefreshContent()
		{
			Text = StringArraySerializer.Serialize(SelectedItems.Select((object x) => x.ToString()));
		}

		private void RefreshDisplayedText()
		{
			List<string> list = StringArraySerializer.Deserialize(Text).ToList();
			if (list.Count == 0)
			{
				DisplayedText = EmptyText;
				return;
			}
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < list.Count; i++)
			{
				stringBuilder.Append(list[i]);
				if (i < list.Count - 1 && ItemsSplitter != null)
				{
					stringBuilder.Append(ItemsSplitter);
				}
			}
			DisplayedText = stringBuilder.ToString();
		}

		private static void OnItemsPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CheckableComboBox).OnItemsChanged((IEnumerable)e.OldValue, (IEnumerable)e.NewValue);
		}

		private static void OnTextPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CheckableComboBox).RefreshDisplayedText();
		}

		private static void OnEmptyTextPropertyPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CheckableComboBox).RefreshDisplayedText();
		}

		private static void OnItemsSplitterPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CheckableComboBox).RefreshContent();
		}
	}
	public class EditableListBox : Control
	{
		private ListBox _listBoxItems;

		public static readonly DependencyProperty HeaderProperty;

		private static readonly DependencyPropertyKey ItemsPropertyKey;

		public static readonly DependencyProperty ItemsProperty;

		private static readonly DependencyPropertyKey ItemsAsStringPropertyKey;

		public static readonly DependencyProperty ItemsAsStringProperty;

		public static readonly DependencyProperty MaskProperty;

		public static readonly DependencyProperty EditAsTypeProperty;

		public static readonly DependencyProperty SuppressEventProperty;

		public static readonly RoutedUICommand InsertCommand;

		public static readonly RoutedUICommand DeleteCommand;

		public static readonly RoutedUICommand MoveUpCommand;

		public static readonly RoutedUICommand MoveDownCommand;

		public static readonly RoutedEvent ItemsAsStringChangedEvent;

		public string Header
		{
			get
			{
				return (string)GetValue(HeaderProperty);
			}
			set
			{
				SetValue(HeaderProperty, value);
			}
		}

		public ObservableCollection<EditableListBoxItem> Items
		{
			get
			{
				return (ObservableCollection<EditableListBoxItem>)GetValue(ItemsProperty);
			}
			private set
			{
				SetValue(ItemsPropertyKey, value);
			}
		}

		public string ItemsAsString
		{
			get
			{
				return (string)GetValue(ItemsAsStringProperty);
			}
			private set
			{
				SetValue(ItemsAsStringPropertyKey, value);
			}
		}

		public string Mask
		{
			get
			{
				return (string)GetValue(MaskProperty);
			}
			set
			{
				SetValue(MaskProperty, value);
			}
		}

		public Type EditAsType
		{
			get
			{
				return (Type)GetValue(EditAsTypeProperty);
			}
			set
			{
				SetValue(EditAsTypeProperty, value);
			}
		}

		public bool SuppressEvent
		{
			get
			{
				return (bool)GetValue(SuppressEventProperty);
			}
			set
			{
				SetValue(SuppressEventProperty, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<string> ItemsAsStringChanged
		{
			add
			{
				AddHandler(ItemsAsStringChangedEvent, value);
			}
			remove
			{
				RemoveHandler(ItemsAsStringChangedEvent, value);
			}
		}

		static EditableListBox()
		{
			HeaderProperty = DependencyProperty.Register("Header", typeof(string), typeof(EditableListBox), new FrameworkPropertyMetadata(GridFormsResources.EditableListBox_DefaultHeader));
			ItemsPropertyKey = DependencyProperty.RegisterReadOnly("Items", typeof(ObservableCollection<EditableListBoxItem>), typeof(EditableListBox), new FrameworkPropertyMetadata());
			ItemsProperty = ItemsPropertyKey.DependencyProperty;
			ItemsAsStringPropertyKey = DependencyProperty.RegisterReadOnly("ItemsAsString", typeof(string), typeof(EditableListBox), new FrameworkPropertyMetadata(OnItemsAsStringPropertyChanged));
			ItemsAsStringProperty = ItemsAsStringPropertyKey.DependencyProperty;
			MaskProperty = DependencyProperty.Register("Mask", typeof(string), typeof(EditableListBox));
			EditAsTypeProperty = DependencyProperty.Register("EditAsType", typeof(Type), typeof(EditableListBox), new FrameworkPropertyMetadata(typeof(string)));
			SuppressEventProperty = DependencyProperty.Register("SuppressEvent", typeof(bool), typeof(EditableListBox));
			InsertCommand = new RoutedUICommand("Insert", "InsertCommand", typeof(EditableListBox), new InputGestureCollection
			{
				new KeyGesture(Key.Insert)
			});
			DeleteCommand = new RoutedUICommand("Delete", "DeleteCommand", typeof(EditableListBox), new InputGestureCollection
			{
				new KeyGesture(Key.Delete)
			});
			MoveUpCommand = new RoutedUICommand("Up", "MoveUpCommand", typeof(EditableListBox), new InputGestureCollection
			{
				new KeyGesture(Key.Up, ModifierKeys.Alt)
			});
			MoveDownCommand = new RoutedUICommand("Down", "MoveDownCommand", typeof(EditableListBox), new InputGestureCollection
			{
				new KeyGesture(Key.Down, ModifierKeys.Alt)
			});
			ItemsAsStringChangedEvent = EventManager.RegisterRoutedEvent("ItemsAsStringChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<string>), typeof(EditableListBox));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(EditableListBox), new FrameworkPropertyMetadata(typeof(EditableListBox)));
			CommandManager.RegisterClassCommandBinding(typeof(EditableListBox), new CommandBinding(InsertCommand, InsertCommand_Executed, InsertCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(EditableListBox), new CommandBinding(DeleteCommand, DeleteCommand_Executed, DeleteCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(EditableListBox), new CommandBinding(MoveUpCommand, MoveUpCommand_Executed, MoveUpCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(EditableListBox), new CommandBinding(MoveDownCommand, MoveDownCommand_Executed, MoveDownCommand_CanExecute));
		}

		public EditableListBox()
		{
			Items = new ObservableCollection<EditableListBoxItem>();
			Items.CollectionChanged += Items_CollectionChanged;
			AddHandler(ValueEditor.EditModeStartedEvent, new EventHandler<EditModeStartedEventArgs>(XamMaskedEditor_EditModeStarted));
		}

		private void XamMaskedEditor_EditModeStarted(object sender, EditModeStartedEventArgs e)
		{
			if (_listBoxItems != null && e.OriginalSource is XamMaskedEditor { DataContext: EditableListBoxItem dataContext } && Items.Contains(dataContext))
			{
				_listBoxItems.SelectedItem = dataContext;
			}
		}

		private void Items_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (e.NewItems != null)
			{
				foreach (EditableListBoxItem newItem in e.NewItems)
				{
					newItem.ParentListBox = this;
				}
			}
			UpdateItemsAsString();
		}

		public override void OnApplyTemplate()
		{
			_listBoxItems = GetTemplateChild("PART_ListBox") as ListBox;
			base.OnApplyTemplate();
		}

		public void ClearItems(bool suppressEvent = false)
		{
			bool suppressEvent2 = SuppressEvent;
			if (suppressEvent)
			{
				SuppressEvent = suppressEvent;
			}
			Items.Clear();
			SuppressEvent = suppressEvent2;
		}

		public void ReInitialize(string serializedSelectedItems, bool suppressEvent = false)
		{
			bool suppressEvent2 = SuppressEvent;
			if (suppressEvent)
			{
				SuppressEvent = suppressEvent;
			}
			Items.Clear();
			foreach (string item in StringArraySerializer.Deserialize(serializedSelectedItems).Distinct())
			{
				string text = TransformText(item);
				if (!string.IsNullOrWhiteSpace(text))
				{
					Items.Add(new EditableListBoxItem
					{
						Text = text
					});
				}
			}
			SuppressEvent = suppressEvent2;
		}

		protected virtual void OnItemsAsStringChanged(string oldString, string newString)
		{
			if (!SuppressEvent)
			{
				RaiseEvent(new RoutedPropertyChangedEventArgs<string>(oldString, newString, ItemsAsStringChangedEvent)
				{
					Source = this
				});
			}
		}

		protected internal virtual void OnSubItemTextChanged(EditableListBoxItem item, string oldText, string newText)
		{
			UpdateItemsAsString();
		}

		private void UpdateItemsAsString()
		{
			IEnumerable<string> array = from x in Items
				let y = TransformTextBack(x.Text)
				where !string.IsNullOrWhiteSpace(y)
				select y;
			ItemsAsString = StringArraySerializer.Serialize(array);
		}

		private string TransformText(string invariantText)
		{
			if (EditAsType == typeof(double))
			{
				double result = 0.0;
				if (double.TryParse(invariantText, NumberStyles.Number, CultureInfo.InvariantCulture, out result))
				{
					return result.ToString(CultureInfo.CurrentCulture);
				}
				return null;
			}
			return invariantText;
		}

		private string TransformTextBack(string text)
		{
			if (EditAsType == typeof(double))
			{
				double result = 0.0;
				if (double.TryParse(text, NumberStyles.Number, CultureInfo.CurrentCulture, out result))
				{
					return result.ToString(CultureInfo.InvariantCulture);
				}
				return null;
			}
			return text;
		}

		private static void InsertCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			EditableListBoxItem editableListBoxItem = null;
			EditableListBoxItem editableListBoxItem2 = editableListBox.Items.LastOrDefault();
			if (editableListBoxItem2 != null && string.IsNullOrWhiteSpace(editableListBoxItem2.Text))
			{
				editableListBoxItem = editableListBoxItem2;
			}
			else
			{
				editableListBoxItem = new EditableListBoxItem();
				editableListBox.Items.Add(editableListBoxItem);
			}
			editableListBox._listBoxItems.ScrollIntoView(editableListBoxItem);
			editableListBox._listBoxItems.SelectedItem = editableListBoxItem;
			if (editableListBox._listBoxItems.ItemContainerGenerator.ContainerFromItem(editableListBoxItem) is ListBoxItem { Content: XamMaskedEditor content })
			{
				content.StartEditMode();
				content.Focus();
			}
		}

		private static void InsertCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			e.CanExecute = editableListBox._listBoxItems != null;
		}

		private static void DeleteCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			foreach (EditableListBoxItem item in editableListBox._listBoxItems.SelectedItems.Cast<EditableListBoxItem>().ToList())
			{
				if (item != null && editableListBox.Items.Contains(item))
				{
					editableListBox.Items.Remove(item);
				}
			}
			editableListBox.UpdateItemsAsString();
		}

		private static void DeleteCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			e.CanExecute = editableListBox._listBoxItems != null && editableListBox._listBoxItems.SelectedItems.Count > 0;
		}

		private static void MoveUpCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			EditableListBox obj = sender as EditableListBox;
			MoveUp<EditableListBoxItem>(obj._listBoxItems);
			obj.UpdateItemsAsString();
		}

		private static void MoveUpCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			if (editableListBox._listBoxItems != null)
			{
				e.CanExecute = CanMoveUp<EditableListBoxItem>(editableListBox._listBoxItems);
			}
		}

		private static void MoveDownCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			EditableListBox obj = sender as EditableListBox;
			MoveDown<EditableListBoxItem>(obj._listBoxItems);
			obj.UpdateItemsAsString();
		}

		private static void MoveDownCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			EditableListBox editableListBox = sender as EditableListBox;
			if (editableListBox._listBoxItems != null)
			{
				e.CanExecute = CanMoveDown<EditableListBoxItem>(editableListBox._listBoxItems);
			}
		}

		private static void OnItemsAsStringPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as EditableListBox).OnItemsAsStringChanged((string)e.OldValue, (string)e.NewValue);
		}

		public static bool CanMoveUp<T>(ListBox targetListbox)
		{
			if (targetListbox == null)
			{
				return false;
			}
			return CanMoveUp(targetListbox.ItemsSource as ObservableCollection<T>, targetListbox.SelectedItems.Cast<T>());
		}

		public static bool CanMoveUp<T>(ObservableCollection<T> items, IEnumerable<T> selectedItems)
		{
			if (items == null || selectedItems == null)
			{
				return false;
			}
			List<T> list = selectedItems.ToList();
			if (list.Count > 0)
			{
				List<T> list2 = list.OrderBy((T x) => items.IndexOf(x)).ToList();
				int num = items.IndexOf(list2[0]);
				if (num > 0)
				{
					return true;
				}
				for (int num2 = 1; num2 < list2.Count; num2++)
				{
					int num3 = items.IndexOf(list2[num2]);
					if (num3 > num + 1)
					{
						return true;
					}
					num = num3;
				}
			}
			return false;
		}

		public static void MoveUp<T>(ListBox targetListbox)
		{
			if (targetListbox == null)
			{
				throw new ArgumentNullException("targetListbox");
			}
			object obj = MoveUp(targetListbox.ItemsSource as ObservableCollection<T>, targetListbox.SelectedItems.Cast<T>());
			if (obj != null)
			{
				targetListbox.ScrollIntoView(obj);
			}
		}

		public static object MoveUp<T>(ObservableCollection<T> items, IEnumerable<T> selectedItems)
		{
			if (items != null && selectedItems != null)
			{
				List<T> list = selectedItems.ToList();
				if (list.Count > 0)
				{
					List<T> list2 = list.OrderBy((T x) => items.IndexOf(x)).ToList();
					int num = items.IndexOf(list2[0]);
					int? num2 = null;
					if (num > 0)
					{
						num2 = 0;
					}
					else
					{
						for (int num3 = 1; num3 < list2.Count; num3++)
						{
							int num4 = items.IndexOf(list2[num3]);
							if (num4 > num + 1)
							{
								num2 = num3;
								break;
							}
							num = num4;
						}
					}
					if (num2.HasValue)
					{
						for (int num5 = num2.Value; num5 < list2.Count; num5++)
						{
							int num6 = items.IndexOf(list2[num5]);
							items.Move(num6, num6 - 1);
						}
						return list2[0];
					}
				}
			}
			return null;
		}

		public static bool CanMoveDown<T>(ListBox targetListbox)
		{
			if (targetListbox == null)
			{
				return false;
			}
			return CanMoveDown(targetListbox.ItemsSource as ObservableCollection<T>, targetListbox.SelectedItems.Cast<T>());
		}

		public static bool CanMoveDown<T>(ObservableCollection<T> items, IEnumerable<T> selectedItems)
		{
			if (items == null || selectedItems == null)
			{
				return false;
			}
			List<T> list = selectedItems.ToList();
			if (list.Count > 0)
			{
				List<T> list2 = list.OrderByDescending((T x) => items.IndexOf(x)).ToList();
				int num = items.IndexOf(list2[0]);
				if (num < items.Count - 1)
				{
					return true;
				}
				for (int num2 = 1; num2 < list2.Count; num2++)
				{
					int num3 = items.IndexOf(list2[num2]);
					if (num3 < num - 1)
					{
						return true;
					}
					num = num3;
				}
			}
			return false;
		}

		public static void MoveDown<T>(ListBox targetListbox)
		{
			if (targetListbox == null)
			{
				throw new ArgumentNullException("targetListbox");
			}
			if (targetListbox == null)
			{
				throw new ArgumentNullException("targetListbox");
			}
			object obj = MoveDown(targetListbox.ItemsSource as ObservableCollection<T>, targetListbox.SelectedItems.Cast<T>());
			if (obj != null)
			{
				targetListbox.ScrollIntoView(obj);
			}
		}

		public static object MoveDown<T>(ObservableCollection<T> items, IEnumerable<T> selectedItems)
		{
			if (items != null && selectedItems != null)
			{
				List<T> list = selectedItems.ToList();
				if (list.Count > 0)
				{
					List<T> list2 = list.OrderByDescending((T x) => items.IndexOf(x)).ToList();
					int num = items.IndexOf(list2[0]);
					int? num2 = null;
					if (num < items.Count - 1)
					{
						num2 = 0;
					}
					else
					{
						for (int num3 = 1; num3 < list2.Count; num3++)
						{
							int num4 = items.IndexOf(list2[num3]);
							if (num4 < num - 1)
							{
								num2 = num3;
								break;
							}
							num = num4;
						}
					}
					if (num2.HasValue)
					{
						for (int num5 = num2.Value; num5 < list2.Count; num5++)
						{
							int num6 = items.IndexOf(list2[num5]);
							items.Move(num6, num6 + 1);
						}
						return list2[0];
					}
				}
			}
			return null;
		}
	}
	public class PopupSelector : Popup, IComponentConnector
	{
		public static readonly DependencyProperty ItemsProperty = DependencyProperty.Register("Items", typeof(IEnumerable<CheckableItem>), typeof(PopupSelector));

		public static readonly DependencyProperty PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(PopupSelector), new FrameworkPropertyMetadata(200.0));

		public static readonly DependencyProperty PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(PopupSelector), new UIPropertyMetadata(250.0));

		internal ListBox theListBox;

		internal CheckBox checkBoxAll;

		private bool _contentLoaded;

		public IEnumerable<CheckableItem> Items
		{
			get
			{
				return (IEnumerable<CheckableItem>)GetValue(ItemsProperty);
			}
			set
			{
				SetValue(ItemsProperty, value);
			}
		}

		public double PopupWidth
		{
			get
			{
				return (double)GetValue(PopupWidthProperty);
			}
			set
			{
				SetValue(PopupWidthProperty, value);
			}
		}

		public double PopupHeight
		{
			get
			{
				return (double)GetValue(PopupHeightProperty);
			}
			set
			{
				SetValue(PopupHeightProperty, value);
			}
		}

		public PopupSelector()
		{
			InitializeComponent();
		}

		protected override void OnInitialized(System.EventArgs e)
		{
			theListBox.AddHandler(ButtonBase.ClickEvent, new RoutedEventHandler(CheckBox_Clicked));
			base.OnInitialized(e);
		}

		protected override void OnOpened(System.EventArgs e)
		{
			UpadteCheckAllButton();
			base.OnOpened(e);
		}

		private void CheckBox_Clicked(object sender, RoutedEventArgs e)
		{
			UpadteCheckAllButton();
		}

		private void UpadteCheckAllButton()
		{
			if (Items != null)
			{
				int num = Items.Count();
				int num2 = Items.Count((CheckableItem x) => x.IsChecked);
				if (num == num2)
				{
					checkBoxAll.IsChecked = true;
				}
				else if (num2 > 0)
				{
					checkBoxAll.IsChecked = null;
				}
				else
				{
					checkBoxAll.IsChecked = false;
				}
			}
		}

		private void DoCheckAll()
		{
			if (Items == null || !checkBoxAll.IsChecked.HasValue)
			{
				return;
			}
			foreach (CheckableItem item in Items)
			{
				item.IsChecked = checkBoxAll.IsChecked.Value;
			}
		}

		private void checkBoxAll_Click(object sender, RoutedEventArgs e)
		{
			DoCheckAll();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/popupselector.xaml", UriKind.Relative);
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
				theListBox = (ListBox)target;
				break;
			case 2:
				checkBoxAll = (CheckBox)target;
				checkBoxAll.Click += checkBoxAll_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class ScopeSelectionControl : UserControl, IComponentConnector
	{
		private readonly TreeViewPopupSelector _popupSelector;

		private static readonly DependencyPropertyKey ItemsPropertyKey = DependencyProperty.RegisterReadOnly("Items", typeof(ObservableCollection<TreeViewComboItem>), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata());

		public static readonly DependencyProperty ItemsProperty = ItemsPropertyKey.DependencyProperty;

		public static readonly DependencyProperty SelectedItemProperty = DependencyProperty.Register("SelectedItem", typeof(TreeViewComboItem), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata(OnSelectedItemPropertyChanged));

		public static readonly DependencyProperty IsPopupOpenProperty = DependencyProperty.Register("IsPopupOpen", typeof(bool), typeof(ScopeSelectionControl));

		public static readonly DependencyProperty PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata(200.0));

		public static readonly DependencyProperty PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(ScopeSelectionControl), new UIPropertyMetadata(250.0));

		public static readonly RoutedEvent SelectedItemChangedEvent = EventManager.RegisterRoutedEvent("SelectedItemChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<TreeViewComboItem>), typeof(ScopeSelectionControl));

		internal StackPanel spItemsList;

		private bool _contentLoaded;

		public ObservableCollection<TreeViewComboItem> Items
		{
			get
			{
				return (ObservableCollection<TreeViewComboItem>)GetValue(ItemsProperty);
			}
			private set
			{
				SetValue(ItemsPropertyKey, value);
			}
		}

		public TreeViewComboItem SelectedItem
		{
			get
			{
				return (TreeViewComboItem)GetValue(SelectedItemProperty);
			}
			set
			{
				SetValue(SelectedItemProperty, value);
			}
		}

		public bool IsPopupOpen
		{
			get
			{
				return (bool)GetValue(IsPopupOpenProperty);
			}
			set
			{
				SetValue(IsPopupOpenProperty, value);
			}
		}

		public double PopupWidth
		{
			get
			{
				return (double)GetValue(PopupWidthProperty);
			}
			set
			{
				SetValue(PopupWidthProperty, value);
			}
		}

		public double PopupHeight
		{
			get
			{
				return (double)GetValue(PopupHeightProperty);
			}
			set
			{
				SetValue(PopupHeightProperty, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<TreeViewComboItem> SelectedItemChanged
		{
			add
			{
				AddHandler(SelectedItemChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectedItemChangedEvent, value);
			}
		}

		public ScopeSelectionControl()
		{
			Items = new ObservableCollection<TreeViewComboItem>();
			_popupSelector = new TreeViewPopupSelector
			{
				StaysOpen = false,
				PlacementTarget = this
			};
			_popupSelector.SetBinding(TreeViewPopupSelector.ItemsProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(TreeViewComboBox.ItemsProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.SetBinding(Popup.IsOpenProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(TreeViewComboBox.IsPopupOpenProperty),
				Mode = BindingMode.TwoWay
			});
			_popupSelector.SetBinding(TreeViewPopupSelector.PopupWidthProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(TreeViewComboBox.PopupWidthProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.SetBinding(TreeViewPopupSelector.PopupHeightProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(TreeViewComboBox.PopupHeightProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.Opened += _popupSelector_Opened;
			_popupSelector.Closed += _popupSelector_Closed;
			InitializeComponent();
		}

		public void UpdateItems(IEnumerable<TreeViewComboItem> items)
		{
			if (items == null)
			{
				Items = new ObservableCollection<TreeViewComboItem>();
			}
			else
			{
				Items = new ObservableCollection<TreeViewComboItem>(items);
			}
		}

		private void _popupSelector_Opened(object sender, System.EventArgs e)
		{
		}

		private void _popupSelector_Closed(object sender, System.EventArgs e)
		{
			SelectedItem = _popupSelector.SelectedItem;
		}

		protected virtual void OnSelectedItemChanged(TreeViewComboItem oldSelected, TreeViewComboItem newSelected)
		{
			if (IsPopupOpen)
			{
				IsPopupOpen = false;
			}
			RaiseEvent(new RoutedEventArgs(SelectedItemChangedEvent, this));
		}

		private static void OnSelectedItemPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as ScopeSelectionControl).OnSelectedItemChanged((TreeViewComboItem)e.OldValue, (TreeViewComboItem)e.NewValue);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/scopeselectioncontrol.xaml", UriKind.Relative);
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
				spItemsList = (StackPanel)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
	public class SheetNameDialog : Window, IComponentConnector
	{
		private readonly Func<string, string> _checkNewNameFunc;

		internal TextBox textboxName;

		internal Button buttonOK;

		internal Button buttonCancel;

		private bool _contentLoaded;

		public string NewSheetName
		{
			get
			{
				return textboxName.Text.Trim();
			}
			set
			{
				textboxName.Text = value;
			}
		}

		public SheetNameDialog(Func<string, string> checkNewNameFunc)
		{
			if (checkNewNameFunc == null)
			{
				throw new ArgumentNullException("checkNewNameFunc");
			}
			_checkNewNameFunc = checkNewNameFunc;
			base.Loaded += SheetNameDialog_Loaded;
			InitializeComponent();
		}

		private void SheetNameDialog_Loaded(object sender, RoutedEventArgs e)
		{
			textboxName.SelectAll();
			textboxName.Focus();
		}

		private void textboxName_TextChanged(object sender, TextChangedEventArgs e)
		{
			buttonOK.IsEnabled = !string.IsNullOrEmpty(NewSheetName);
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			string text = _checkNewNameFunc(NewSheetName);
			if (!string.IsNullOrEmpty(text))
			{
				MMMessageBox.Show(this, text, GridFormsResources.SheetNameDialog_InvalidName_Title);
				return;
			}
			base.DialogResult = true;
			Close();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/sheetnamedialog.xaml", UriKind.Relative);
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
				textboxName = (TextBox)target;
				textboxName.TextChanged += textboxName_TextChanged;
				break;
			case 2:
				buttonOK = (Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 3:
				buttonCancel = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public static class StringArraySerializer
	{
		[CompilerGenerated]
		private sealed class XmlStringEnumerator : IEnumerable<string>, IEnumerable, IEnumerator<string>, IDisposable, IEnumerator
		{
			private int state;

			private string current;

			private int initialThreadId;

			private string input;

			public string initialInput;

			private IEnumerator<XElement> elements;

			string IEnumerator<string>.Current
			{
				[DebuggerHidden]
				get
				{
					return current;
				}
			}

			object IEnumerator.Current
			{
				[DebuggerHidden]
				get
				{
					return current;
				}
			}

			[DebuggerHidden]
			public XmlStringEnumerator(int state)
			{
				this.state = state;
				initialThreadId = Environment.CurrentManagedThreadId;
			}

			[DebuggerHidden]
			void IDisposable.Dispose()
			{
				int num = state;
				if (num == -3 || num == 1)
				{
					try
					{
					}
					finally
					{
						DisposeElements();
					}
				}
			}

			bool IEnumerator.MoveNext()
			{
				bool completedNormally = false;
				try
				{
					int num = state;
					if (num != 0)
					{
						if (num != 1)
						{
							completedNormally = true;
							return false;
						}
						state = -3;
					}
					else
					{
						state = -1;
						XElement xElement = null;
						try
						{
							xElement = XElement.Parse(input);
						}
						catch (Exception ex)
						{
							SystemEnvironment.LogDebug(ex.Message + "\n" + ex.StackTrace);
						}
						if (xElement == null)
						{
							goto IL_00bb;
						}
						elements = xElement.Elements().GetEnumerator();
						state = -3;
					}
					while (elements.MoveNext())
					{
						string value = elements.Current.Value;
						if (!string.IsNullOrEmpty(value))
						{
							current = value;
							state = 1;
							completedNormally = true;
							return true;
						}
					}
					DisposeElements();
					elements = null;
					IL_00bb:
					completedNormally = true;
					return false;
				}
				finally
				{
					// The original fault handler releases the enumerator on exceptional exit.
					if (!completedNormally)
					{
						((IDisposable)this).Dispose();
					}
				}
			}

			private void DisposeElements()
			{
				state = -1;
				if (elements != null)
				{
					elements.Dispose();
				}
			}

			[DebuggerHidden]
			void IEnumerator.Reset()
			{
				throw new NotSupportedException();
			}

			[DebuggerHidden]
			IEnumerator<string> IEnumerable<string>.GetEnumerator()
			{
				XmlStringEnumerator enumerator;
				if (state == -2 && initialThreadId == Environment.CurrentManagedThreadId)
				{
					state = 0;
					enumerator = this;
				}
				else
				{
					enumerator = new XmlStringEnumerator(0);
				}
				enumerator.input = initialInput;
				return enumerator;
			}

			[DebuggerHidden]
			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable<string>)this).GetEnumerator();
			}
		}

		private const string CommaAndBlankSpace = ", ";

		private const string RootNodeName = "array";

		private const string ElementNodeName = "word";

		private const string HeaderText = "<array>";

		private const string TailText = "</array>";

		public static IEnumerable<string> Deserialize(string input)
		{
			List<string> list = new List<string>();
			if (!string.IsNullOrWhiteSpace(input))
			{
				string input2 = input.Trim();
				if (IsXmlFormat(input2))
				{
					list.AddRange(FromXmlString(input2));
				}
				else
				{
					list.AddRange(FromCommaSeparatedString(input2));
				}
			}
			return list;
		}

		public static string Serialize(IEnumerable<string> array)
		{
			if (array != null && array.Any())
			{
				bool flag = !array.Any((string x) => x.Contains(','));
				if (!flag)
				{
					flag = !array.Any((string x) => x.Contains(", "));
				}
				if (flag)
				{
					return SaveToSeparatedString(array);
				}
				XElement xElement = new XElement("array");
				foreach (string item in array)
				{
					if (!string.IsNullOrEmpty(item))
					{
						xElement.Add(new XElement("word", item));
					}
				}
				return xElement.ToString(SaveOptions.DisableFormatting);
			}
			return null;
		}

		public static bool ArrayEquals(string x, string y)
		{
			bool flag = string.IsNullOrWhiteSpace(x);
			bool flag2 = string.IsNullOrWhiteSpace(y);
			if (flag && flag2)
			{
				return true;
			}
			if (flag || flag2)
			{
				return false;
			}
			if (string.Equals(x, y, StringComparison.InvariantCultureIgnoreCase))
			{
				return true;
			}
			IOrderedEnumerable<string> x2 = from s in Deserialize(x)
				orderby s
				select s;
			IOrderedEnumerable<string> y2 = from s in Deserialize(y)
				orderby s
				select s;
			return SequenceEquals(x2, y2);
		}

		public static bool SequenceEquals(IEnumerable<string> x, IEnumerable<string> y)
		{
			if (x == null && y == null)
			{
				return true;
			}
			if (x == null || y == null)
			{
				return false;
			}
			if (x == y)
			{
				return true;
			}
			return x.SequenceEqual(y, StringComparer.InvariantCultureIgnoreCase);
		}

		private static string SaveToSeparatedString(IEnumerable<string> array)
		{
			if (array != null && array.Any())
			{
				int num = 0;
				StringBuilder stringBuilder = new StringBuilder();
				foreach (string item in array)
				{
					if (num > 0)
					{
						stringBuilder.Append(", ");
					}
					if (item.Contains(",") || item.Contains(", "))
					{
						stringBuilder.AppendFormat("\"{0}\"", item);
					}
					else
					{
						stringBuilder.Append(item);
					}
					num++;
				}
				return stringBuilder.ToString();
			}
			return null;
		}

		private static bool IsXmlFormat(string input)
		{
			if (input.StartsWith("<array>", StringComparison.InvariantCultureIgnoreCase))
			{
				return input.EndsWith("</array>", StringComparison.InvariantCultureIgnoreCase);
			}
			return false;
		}

		[IteratorStateMachine(typeof(XmlStringEnumerator))]
		private static IEnumerable<string> FromXmlString(string input)
		{
			return new XmlStringEnumerator(-2)
			{
				initialInput = input
			};
		}

		private static IEnumerable<string> FromCommaSeparatedString(string input)
		{
			if (!input.Contains("\""))
			{
				if (input.Contains(", "))
				{
					return input.Split(new string[1] { ", " }, StringSplitOptions.RemoveEmptyEntries);
				}
				return input.Split(new char[1] { ',' }, StringSplitOptions.RemoveEmptyEntries);
			}
			int num = input.IndexOf("\"");
			int num2 = input.IndexOf("\"", num + 1);
			if (num >= 0 && num2 >= 0 && num2 < input.Length)
			{
				List<string> list = new List<string>();
				if (num > 0)
				{
					list.AddRange(FromCommaSeparatedString(input.Substring(0, num)));
				}
				list.Add(input.Substring(num + 1, num2 - num - 1));
				if (num2 < input.Length - 1)
				{
					list.AddRange(FromCommaSeparatedString(input.Substring(num2 + 1, input.Length - num2 - 1)));
				}
				return list;
			}
			return new List<string> { input };
		}
	}
	public class TreeViewComboBox : Control
	{
		private ToggleButton _dropdownButton;

		private readonly TreeViewPopupSelector _popupSelector;

		private static readonly DependencyPropertyKey ItemsPropertyKey;

		public static readonly DependencyProperty ItemsProperty;

		public static readonly DependencyProperty SelectedItemProperty;

		public static readonly DependencyProperty IsPopupOpenProperty;

		public static readonly DependencyProperty PopupWidthProperty;

		public static readonly DependencyProperty PopupHeightProperty;

		public static readonly RoutedEvent SelectedItemChangedEvent;

		public ObservableCollection<TreeViewComboItem> Items
		{
			get
			{
				return (ObservableCollection<TreeViewComboItem>)GetValue(ItemsProperty);
			}
			private set
			{
				SetValue(ItemsPropertyKey, value);
			}
		}

		public TreeViewComboItem SelectedItem
		{
			get
			{
				return (TreeViewComboItem)GetValue(SelectedItemProperty);
			}
			set
			{
				SetValue(SelectedItemProperty, value);
			}
		}

		public bool IsPopupOpen
		{
			get
			{
				return (bool)GetValue(IsPopupOpenProperty);
			}
			set
			{
				SetValue(IsPopupOpenProperty, value);
			}
		}

		public double PopupWidth
		{
			get
			{
				return (double)GetValue(PopupWidthProperty);
			}
			set
			{
				SetValue(PopupWidthProperty, value);
			}
		}

		public double PopupHeight
		{
			get
			{
				return (double)GetValue(PopupHeightProperty);
			}
			set
			{
				SetValue(PopupHeightProperty, value);
			}
		}

		public event RoutedPropertyChangedEventHandler<TreeViewComboItem> SelectedItemChanged
		{
			add
			{
				AddHandler(SelectedItemChangedEvent, value);
			}
			remove
			{
				RemoveHandler(SelectedItemChangedEvent, value);
			}
		}

		static TreeViewComboBox()
		{
			ItemsPropertyKey = DependencyProperty.RegisterReadOnly("Items", typeof(ObservableCollection<TreeViewComboItem>), typeof(TreeViewComboBox), new FrameworkPropertyMetadata());
			ItemsProperty = ItemsPropertyKey.DependencyProperty;
			SelectedItemProperty = DependencyProperty.Register("SelectedItem", typeof(TreeViewComboItem), typeof(TreeViewComboBox), new FrameworkPropertyMetadata(OnSelectedItemPropertyChanged));
			IsPopupOpenProperty = DependencyProperty.Register("IsPopupOpen", typeof(bool), typeof(TreeViewComboBox));
			PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(TreeViewComboBox), new FrameworkPropertyMetadata(200.0));
			PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(TreeViewComboBox), new UIPropertyMetadata(250.0));
			SelectedItemChangedEvent = EventManager.RegisterRoutedEvent("SelectedItemChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<TreeViewComboItem>), typeof(TreeViewComboBox));
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(TreeViewComboBox), new FrameworkPropertyMetadata(typeof(TreeViewComboBox)));
		}

		public TreeViewComboBox()
		{
			Items = new ObservableCollection<TreeViewComboItem>();
			_popupSelector = new TreeViewPopupSelector
			{
				StaysOpen = false,
				PlacementTarget = this
			};
			_popupSelector.SetBinding(TreeViewPopupSelector.ItemsProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(ItemsProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.SetBinding(Popup.IsOpenProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(IsPopupOpenProperty),
				Mode = BindingMode.TwoWay
			});
			_popupSelector.SetBinding(TreeViewPopupSelector.PopupWidthProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(PopupWidthProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.SetBinding(TreeViewPopupSelector.PopupHeightProperty, new Binding
			{
				Source = this,
				Path = new PropertyPath(PopupHeightProperty),
				Mode = BindingMode.OneWay
			});
			_popupSelector.Opened += _popupSelector_Opened;
			_popupSelector.Closed += _popupSelector_Closed;
		}

		public void UpdateItems(IEnumerable<TreeViewComboItem> items)
		{
			if (items == null)
			{
				Items = new ObservableCollection<TreeViewComboItem>();
			}
			else
			{
				Items = new ObservableCollection<TreeViewComboItem>(items);
			}
		}

		public override void OnApplyTemplate()
		{
			_dropdownButton = GetTemplateChild("PART_DropDownButton") as ToggleButton;
			base.OnApplyTemplate();
		}

		private void _popupSelector_Opened(object sender, System.EventArgs e)
		{
			if (_dropdownButton != null)
			{
				_dropdownButton.IsHitTestVisible = false;
			}
		}

		private void _popupSelector_Closed(object sender, System.EventArgs e)
		{
			SelectedItem = _popupSelector.SelectedItem;
			base.Dispatcher.BeginInvoke((Action)delegate
			{
				if (_dropdownButton != null)
				{
					_dropdownButton.IsHitTestVisible = true;
				}
			}, DispatcherPriority.Loaded);
		}

		protected virtual void OnSelectedItemChanged(TreeViewComboItem oldSelected, TreeViewComboItem newSelected)
		{
			if (IsPopupOpen)
			{
				IsPopupOpen = false;
			}
			RaiseEvent(new RoutedEventArgs(SelectedItemChangedEvent, this));
		}

		private static void OnSelectedItemPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as TreeViewComboBox).OnSelectedItemChanged((TreeViewComboItem)e.OldValue, (TreeViewComboItem)e.NewValue);
		}
	}
	public class TreeViewPopupSelector : Popup, IComponentConnector
	{
		public static readonly DependencyProperty ItemsProperty = DependencyProperty.Register("Items", typeof(IEnumerable<TreeViewComboItem>), typeof(TreeViewPopupSelector));

		public static readonly DependencyProperty PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata(200.0));

		public static readonly DependencyProperty PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata(250.0));

		private static readonly DependencyPropertyKey SelectedItemPropertyKey = DependencyProperty.RegisterReadOnly("SelectedItem", typeof(TreeViewComboItem), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata());

		public static readonly DependencyProperty SelectedItemProperty = SelectedItemPropertyKey.DependencyProperty;

		private bool _contentLoaded;

		public IEnumerable<TreeViewComboItem> Items
		{
			get
			{
				return (IEnumerable<TreeViewComboItem>)GetValue(ItemsProperty);
			}
			set
			{
				SetValue(ItemsProperty, value);
			}
		}

		public double PopupWidth
		{
			get
			{
				return (double)GetValue(PopupWidthProperty);
			}
			set
			{
				SetValue(PopupWidthProperty, value);
			}
		}

		public double PopupHeight
		{
			get
			{
				return (double)GetValue(PopupHeightProperty);
			}
			set
			{
				SetValue(PopupHeightProperty, value);
			}
		}

		public TreeViewComboItem SelectedItem
		{
			get
			{
				return (TreeViewComboItem)GetValue(SelectedItemProperty);
			}
			private set
			{
				SetValue(SelectedItemPropertyKey, value);
			}
		}

		public TreeViewPopupSelector()
		{
			InitializeComponent();
			AddHandler(System.Windows.Controls.TreeView.SelectedItemChangedEvent, new RoutedPropertyChangedEventHandler<object>(TreeView_SelectedItemChanged));
		}

		protected override void OnMouseLeftButtonUp(MouseButtonEventArgs e)
		{
			if (e.OriginalSource is DependencyObject descendant && Utilities.GetAncestorFromType(descendant, typeof(TreeViewItem), allowSubclassOfType: true) is TreeViewItem stopAtVisual && !(Utilities.GetAncestorFromType(descendant, typeof(ToggleButton), allowSubclassOfType: true, stopAtVisual) is ToggleButton))
			{
				base.Dispatcher.BeginInvoke((Action)delegate
				{
					base.IsOpen = false;
				});
			}
			base.OnMouseLeftButtonUp(e);
		}

		private void TreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			SelectedItem = e.NewValue as TreeViewComboItem;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/treeviewpopupselector.xaml", UriKind.Relative);
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
	public class VariableListDialog : Window, IComponentConnector
	{
		public static readonly DependencyProperty SelectionModeProperty = DependencyProperty.Register("SelectionMode", typeof(SelectionMode), typeof(VariableListDialog), new FrameworkPropertyMetadata(SelectionMode.Extended));

		public static readonly DependencyProperty DataSourceProperty = DependencyProperty.Register("DataSource", typeof(VLDataSource), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnDataSourcePropertyChanged));

		public static readonly DependencyProperty QueryStringProperty = DependencyProperty.Register("QueryString", typeof(string), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnQueryStringPropertyChanged));

		public static readonly DependencyProperty CanQueryProperty = DependencyProperty.Register("CanQuery", typeof(bool), typeof(VariableListDialog));

		public static readonly DependencyPropertyKey StatusTextPropertyKey = DependencyProperty.RegisterReadOnly("StatusText", typeof(string), typeof(VariableListDialog), new FrameworkPropertyMetadata());

		public static readonly DependencyProperty StatusTextProperty = StatusTextPropertyKey.DependencyProperty;

		public static readonly DependencyProperty SelectedBreadCrumbNodeProperty = DependencyProperty.Register("SelectedBreadCrumbNode", typeof(BreadCrumbNode), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnSelectedBreadCrumbNodePropertyChanged));

		public static readonly DependencyProperty ShowOnlyChangedProperty = DependencyProperty.Register("ShowOnlyChanged", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyChangedPropertyChanged));

		public static readonly DependencyProperty ShowOnlyMarkedProperty = DependencyProperty.Register("ShowOnlyMarked", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyMarkedPropertyChanged));

		public static readonly DependencyProperty ShowOnlyAtBoundsProperty = DependencyProperty.Register("ShowOnlyAtBounds", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyAtBoundsPropertyChanged));

		public static readonly RoutedEvent QueryStringChangedEvent = EventManager.RegisterRoutedEvent("QueryStringChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<string>), typeof(VariableListDialog));

		private bool _isUpdatingSelction;

		private ICommand _chooseColumnsCommand;

		private ICommand _selectCommand;

		private ICommand _queryCommand;

		internal BreadCrumbNavigator navigator;

		internal Border border;

		internal StackPanel sp_filters;

		internal Button buttonChooseColumns;

		internal CheckBox checkChanged;

		internal CheckBox checkMarked;

		internal CheckBox checkAtBounds;

		internal GridControl theGridControl;

		internal Button buttonCancel;

		internal Button buttonQuery;

		internal Button buttonSelect;

		private bool _contentLoaded;

		public SelectionMode SelectionMode
		{
			get
			{
				return (SelectionMode)GetValue(SelectionModeProperty);
			}
			set
			{
				SetValue(SelectionModeProperty, value);
			}
		}

		public VLDataSource DataSource
		{
			get
			{
				return (VLDataSource)GetValue(DataSourceProperty);
			}
			set
			{
				SetValue(DataSourceProperty, value);
			}
		}

		public string QueryString
		{
			get
			{
				return (string)GetValue(QueryStringProperty);
			}
			set
			{
				SetValue(QueryStringProperty, value);
			}
		}

		public bool CanQuery
		{
			get
			{
				return (bool)GetValue(CanQueryProperty);
			}
			set
			{
				SetValue(CanQueryProperty, value);
			}
		}

		public string StatusText
		{
			get
			{
				return (string)GetValue(StatusTextProperty);
			}
			private set
			{
				SetValue(StatusTextPropertyKey, value);
			}
		}

		public BreadCrumbNode SelectedBreadCrumbNode
		{
			get
			{
				return (BreadCrumbNode)GetValue(SelectedBreadCrumbNodeProperty);
			}
			set
			{
				SetValue(SelectedBreadCrumbNodeProperty, value);
			}
		}

		public bool ShowOnlyChanged
		{
			get
			{
				return (bool)GetValue(ShowOnlyChangedProperty);
			}
			set
			{
				SetValue(ShowOnlyChangedProperty, value);
			}
		}

		public bool ShowOnlyMarked
		{
			get
			{
				return (bool)GetValue(ShowOnlyMarkedProperty);
			}
			set
			{
				SetValue(ShowOnlyMarkedProperty, value);
			}
		}

		public bool ShowOnlyAtBounds
		{
			get
			{
				return (bool)GetValue(ShowOnlyAtBoundsProperty);
			}
			set
			{
				SetValue(ShowOnlyAtBoundsProperty, value);
			}
		}

		public IEnumerable<VLDataRow> SelectedItems
		{
			get
			{
				if (SelectedBreadCrumbNode != null)
				{
					return (SelectedBreadCrumbNode.Tag as VLDataNode).GetAllIncludedSelectedItems();
				}
				return new List<VLDataRow>();
			}
		}

		public ICommand ChooseColumnsCommand
		{
			get
			{
				if (_chooseColumnsCommand == null)
				{
					_chooseColumnsCommand = new RelayActionCommand(ChooseColumnsCommand_Exectued, ChooseColumnsCommand_CanExecute);
				}
				return _chooseColumnsCommand;
			}
		}

		public ICommand SelectCommand
		{
			get
			{
				if (_selectCommand == null)
				{
					_selectCommand = new RelayActionCommand(SelectCommand_Exectued, SelectCommand_CanExecute);
				}
				return _selectCommand;
			}
		}

		public ICommand QueryCommand
		{
			get
			{
				if (_queryCommand == null)
				{
					_queryCommand = new RelayActionCommand(QueryCommand_Exectued, QueryCommand_CanExecute);
				}
				return _queryCommand;
			}
		}

		public event RoutedPropertyChangedEventHandler<string> QueryStringChanged
		{
			add
			{
				AddHandler(QueryStringChangedEvent, value);
			}
			remove
			{
				RemoveHandler(QueryStringChangedEvent, value);
			}
		}

		public VariableListDialog()
		{
			InitializeComponent();
			theGridControl.SelectionChanged += theGridControl_SelectionChanged;
		}

		private void theGridControl_SelectionChanged(object sender, RoutedEventArgs e)
		{
			UpdateSelectedItems();
		}

		protected override void OnPreviewMouseDoubleClick(MouseButtonEventArgs e)
		{
			if ((e.OriginalSource as DependencyObject).GetAncestor<GridControlCell>(theGridControl) != null && SelectCommand_CanExecute())
			{
				SelectCommand_Exectued();
			}
			else
			{
				base.OnPreviewMouseDoubleClick(e);
			}
		}

		protected virtual void OnDataSourceChanged(VLDataSource oldValue, VLDataSource newValue)
		{
			UpdateHeaderItems();
			UpdateActiveSheetData(updateAnyway: true);
			UpdateStatusText();
		}

		protected virtual void OnQueryStringChanged(string oldValue, string newValue)
		{
			RaiseEvent(new RoutedPropertyChangedEventArgs<string>(oldValue, newValue, QueryStringChangedEvent)
			{
				Source = this
			});
			UpdateStatusText();
		}

		protected virtual void OnQuickFiltersChanged()
		{
			UpdateActiveSheetData(updateAnyway: true);
			UpdateStatusText();
		}

		private void ClearSortings()
		{
			theGridControl.SortingInfo.ClearSorts();
		}

		private void UpdateHeaderItems()
		{
			if (DataSource != null)
			{
				navigator.RootNode = CreateBreadCrumbNode(DataSource.RootNode);
			}
		}

		private BreadCrumbNode CreateBreadCrumbNode(VLDataNode rootNode)
		{
			BreadCrumbNode breadCrumbNode = new BreadCrumbNode
			{
				Text = rootNode.Header,
				Tag = rootNode
			};
			List<BreadCrumbNode> list = new List<BreadCrumbNode>();
			foreach (VLDataNode node in rootNode.Nodes)
			{
				list.Add(CreateBreadCrumbNode(node));
			}
			foreach (BreadCrumbNode item in list.OrderBy((BreadCrumbNode x) => x.Text))
			{
				breadCrumbNode.Children.Add(item);
			}
			return breadCrumbNode;
		}

		private void UpdateActiveSheetData(bool updateAnyway)
		{
			if (DataSource != null)
			{
				DataSource.UpdateGridData(SelectedBreadCrumbNode.Tag as VLDataNode, updateAnyway, ShowOnlyChanged, ShowOnlyMarked, ShowOnlyAtBounds);
				ClearSortings();
				theGridControl.InvalidateSorting();
			}
		}

		private void UpdateSelectedItems()
		{
			if (DataSource == null || theGridControl == null || _isUpdatingSelction)
			{
				return;
			}
			_isUpdatingSelction = true;
			if (DataSource.GridData != null)
			{
				foreach (VLDataRow row in DataSource.GridData.Rows)
				{
					row.IsSelected = false;
				}
			}
			foreach (VLDataRow selectedRow in theGridControl.SelectedRows)
			{
				selectedRow.IsSelected = true;
			}
			_isUpdatingSelction = false;
		}

		private void UpdateStatusText()
		{
			string variableListDialog_StatusFormat = GridFormsResources.VariableListDialog_StatusFormat;
			if (!string.IsNullOrWhiteSpace(QueryString) && DataSource != null)
			{
				int count = DataSource.RootNode.GetAllIncludedItems(ShowOnlyChanged, ShowOnlyMarked, ShowOnlyAtBounds).Count;
				StatusText = string.Format(variableListDialog_StatusFormat, QueryString, count);
			}
			else
			{
				StatusText = null;
			}
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void ChooseColumnsCommand_Exectued()
		{
			GridControl.DisplayColumnChooserCommand.Execute(null, theGridControl);
		}

		private bool ChooseColumnsCommand_CanExecute()
		{
			return true;
		}

		private void SelectCommand_Exectued()
		{
			base.DialogResult = true;
			Close();
		}

		private bool SelectCommand_CanExecute()
		{
			return SelectedItems.Count() > 0;
		}

		private void QueryCommand_Exectued()
		{
			bool flag = true;
			QueryableFieldItem defaultSelectedItem = null;
			IEnumerable<QueryableFieldItem> queryableFieldItems = GetQueryableFieldItems(out defaultSelectedItem);
			VariableQueryDialog variableQueryDialog = new VariableQueryDialog
			{
				QueryString = QueryString,
				Fields = queryableFieldItems,
				SelectedField = defaultSelectedItem,
				CanMatchWithModified = flag,
				CanMatchInObjectiveFunction = flag,
				Owner = this
			};
			bool? flag2 = variableQueryDialog.ShowDialog();
			if (flag2.HasValue && flag2.Value)
			{
				QueryString = variableQueryDialog.QueryString;
			}
		}

		private bool QueryCommand_CanExecute()
		{
			if (CanQuery && DataSource != null)
			{
				return DataSource.Columns.Count() > 0;
			}
			return false;
		}

		private IEnumerable<QueryableFieldItem> GetQueryableFieldItems(out QueryableFieldItem defaultSelectedItem)
		{
			List<QueryableFieldItem> list = new List<QueryableFieldItem>();
			defaultSelectedItem = null;
			foreach (VLDataColumn column in DataSource.Columns)
			{
				if (column.CanQuery)
				{
					QueryableFieldItem queryableFieldItem = new QueryableFieldItem
					{
						DisplayName = column.Header,
						EngineName = column.EngineName,
						ItemsSource = column.CellsItemsSource,
						DataType = column.DefaultDataType,
						CanModify = column.CanModify
					};
					list.Add(queryableFieldItem);
					if (column.IsKeyField && defaultSelectedItem == null)
					{
						defaultSelectedItem = queryableFieldItem;
					}
				}
			}
			return list;
		}

		private static void OnDataSourcePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableListDialog).OnDataSourceChanged((VLDataSource)e.OldValue, (VLDataSource)e.NewValue);
		}

		private static void OnQueryStringPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableListDialog).OnQueryStringChanged((string)e.OldValue, (string)e.NewValue);
		}

		private static void OnSelectedBreadCrumbNodePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			VariableListDialog variableListDialog = d as VariableListDialog;
			if (e.NewValue != null)
			{
				variableListDialog.UpdateActiveSheetData(updateAnyway: false);
			}
		}

		private static void OnShowOnlyChangedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableListDialog).OnQuickFiltersChanged();
		}

		private static void OnShowOnlyMarkedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableListDialog).OnQuickFiltersChanged();
		}

		private static void OnShowOnlyAtBoundsPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableListDialog).OnQuickFiltersChanged();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/variablelistdialog.xaml", UriKind.Relative);
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
				navigator = (BreadCrumbNavigator)target;
				break;
			case 2:
				border = (Border)target;
				break;
			case 3:
				sp_filters = (StackPanel)target;
				break;
			case 4:
				buttonChooseColumns = (Button)target;
				break;
			case 5:
				checkChanged = (CheckBox)target;
				break;
			case 6:
				checkMarked = (CheckBox)target;
				break;
			case 7:
				checkAtBounds = (CheckBox)target;
				break;
			case 8:
				theGridControl = (GridControl)target;
				break;
			case 9:
				buttonCancel = (Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			case 10:
				buttonQuery = (Button)target;
				break;
			case 11:
				buttonSelect = (Button)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class VLDataColumn : DataColumn
	{
		public string EngineName { get; set; }

		public bool IsKeyField { get; set; }

		public bool CanModify { get; set; }

		public bool CanQuery { get; set; }
	}
	public class VLDataRow : DataRow
	{
		public static readonly DependencyProperty HeaderProperty = DependencyProperty.Register("Header", typeof(string), typeof(VLDataRow));

		public static readonly DependencyProperty GeneralIndexProperty = DependencyProperty.Register("GeneralIndex", typeof(int), typeof(VLDataRow));

		public static readonly DependencyProperty IsSelectedProperty = DependencyProperty.Register("IsSelected", typeof(bool), typeof(VLDataRow));

		public string Header
		{
			get
			{
				return (string)GetValue(HeaderProperty);
			}
			set
			{
				SetValue(HeaderProperty, value);
			}
		}

		public int GeneralIndex
		{
			get
			{
				return (int)GetValue(GeneralIndexProperty);
			}
			set
			{
				SetValue(GeneralIndexProperty, value);
			}
		}

		public bool IsSelected
		{
			get
			{
				return (bool)GetValue(IsSelectedProperty);
			}
			set
			{
				SetValue(IsSelectedProperty, value);
			}
		}

		public bool IsChanged => GetColumnValue("MODIFIED", defaultValue: false);

		public bool IsMarked => GetColumnValue("MARKED", defaultValue: false);

		public bool IsAtBounds
		{
			get
			{
				double columnValue = GetColumnValue("VALUE", double.NaN);
				if (!double.IsNaN(columnValue))
				{
					double columnValue2 = GetColumnValue("UPPER", double.NaN);
					if (!double.IsNaN(columnValue2) && (IsRoughlyEqual(columnValue, columnValue2) || columnValue > columnValue2))
					{
						return true;
					}
					double columnValue3 = GetColumnValue("LOWER", double.NaN);
					if (!double.IsNaN(columnValue3) && (IsRoughlyEqual(columnValue, columnValue3) || columnValue < columnValue3))
					{
						return true;
					}
				}
				return false;
			}
		}

		public VLDataRow(IEnumerable<VLDataColumn> columns)
			: base(columns)
		{
		}

		private IDataCell GetCellValue(string engineName)
		{
			DataColumn dataColumn = base.Columns.FirstOrDefault((DataColumn x) => string.Equals(((VLDataColumn)x).EngineName, engineName, StringComparison.InvariantCultureIgnoreCase));
			if (dataColumn != null)
			{
				return base[dataColumn];
			}
			return null;
		}

		private T GetColumnValue<T>(string columnEngineName, T defaultValue)
		{
			IDataCell cellValue = GetCellValue(columnEngineName);
			if (cellValue != null)
			{
				return (T)cellValue.Value;
			}
			return defaultValue;
		}

		private static bool IsRoughlyEqual(double x, double y)
		{
			return Math.Abs(x - y) <= 1E-05;
		}
	}
	public class VLDataNode : INotifyPropertyChanged
	{
		private class VLDataNodeCollection : ObservableCollection<VLDataNode>
		{
			private readonly VLDataNode _parent;

			public VLDataNodeCollection(VLDataNode parent)
			{
				_parent = parent;
			}

			protected override void InsertItem(int index, VLDataNode item)
			{
				if (item != null)
				{
					item.Parent = _parent;
				}
				base.InsertItem(index, item);
			}

			protected override void RemoveItem(int index)
			{
				VLDataNode vLDataNode = base[index];
				if (vLDataNode != null)
				{
					vLDataNode.Parent = null;
				}
				base.RemoveItem(index);
			}
		}

		private string _header;

		private string _path;

		public string Header
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

		public string Path
		{
			get
			{
				if (string.IsNullOrEmpty(_path))
				{
					StringBuilder stringBuilder = new StringBuilder(Header);
					for (VLDataNode parent = Parent; parent != null; parent = parent.Parent)
					{
						stringBuilder.Insert(0, '.').Insert(0, parent.Header);
					}
					_path = stringBuilder.ToString();
				}
				return _path;
			}
		}

		public VLDataNode Parent { get; private set; }

		public ObservableCollection<VLDataRow> Items { get; private set; }

		public ObservableCollection<VLDataNode> Nodes { get; private set; }

		public bool HasNodes => Nodes.Count > 0;

		public event PropertyChangedEventHandler PropertyChanged;

		public VLDataNode()
		{
			Items = new ObservableCollection<VLDataRow>();
			Nodes = new VLDataNodeCollection(this);
			Nodes.CollectionChanged += Nodes_CollectionChanged;
		}

		public List<VLDataRow> GetAllIncludedItems(bool onlyChanged, bool onlyMarked, bool onlyAtBounds)
		{
			List<VLDataRow> list = new List<VLDataRow>();
			foreach (VLDataRow item in Items)
			{
				if ((!onlyChanged || item.IsChanged) && (!onlyMarked || item.IsMarked) && (!onlyAtBounds || item.IsAtBounds))
				{
					list.Add(item);
				}
			}
			foreach (VLDataNode node in Nodes)
			{
				list.AddRange(node.GetAllIncludedItems(onlyChanged, onlyMarked, onlyAtBounds));
			}
			return list;
		}

		public List<VLDataRow> GetAllIncludedSelectedItems()
		{
			List<VLDataRow> list = new List<VLDataRow>();
			foreach (VLDataRow item in Items)
			{
				if (item.IsSelected)
				{
					list.Add(item);
				}
			}
			foreach (VLDataNode node in Nodes)
			{
				list.AddRange(node.GetAllIncludedSelectedItems());
			}
			return list;
		}

		private void Nodes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			OnPropertyChanged("HasNodes");
		}

		protected virtual void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	public class VLDataSource
	{
		private class VLDataTable : DataTable
		{
			private VLDataSource _parentDataSource;

			public VLDataTable(VLDataSource parentDataSource)
				: base(parentDataSource.Columns)
			{
				_parentDataSource = parentDataSource;
			}

			protected override IDataCell OnCellValueQueried(DataRow row, DataColumn column)
			{
				VLDataCellValueRequestingEventArgs e = new VLDataCellValueRequestingEventArgs(row as VLDataRow, column as VLDataColumn);
				_parentDataSource.OnDataCellValueRequesting(e);
				if (e.Value != null)
				{
					return e.Value;
				}
				return base.OnCellValueQueried(row, column);
			}
		}

		public VLDataNode RootNode { get; private set; }

		public IEnumerable<VLDataColumn> Columns { get; private set; }

		public DataTable GridData { get; private set; }

		public event EventHandler<VLDataCellValueRequestingEventArgs> DataCellValueRequesting;

		public VLDataSource(VLDataNode rootNode, IEnumerable<VLDataColumn> columns)
		{
			if (rootNode == null)
			{
				throw new ArgumentNullException("rootNode");
			}
			if (columns == null)
			{
				throw new ArgumentNullException("columns");
			}
			RootNode = rootNode;
			Columns = columns;
			GridData = new VLDataTable(this);
		}

		public void UpdateGridData(VLDataNode selectedNode, bool updateAnyway, bool onlyChanged, bool onlyMarked, bool onlyAtBounds)
		{
			if (selectedNode == null)
			{
				throw new ArgumentNullException("selectedNode");
			}
			bool flag = GridData.Tag != selectedNode;
			if (updateAnyway || flag)
			{
				List<VLDataRow> allIncludedItems = selectedNode.GetAllIncludedItems(onlyChanged, onlyMarked, onlyAtBounds);
				GridData.UpdateRows(allIncludedItems);
				GridData.Tag = selectedNode;
			}
		}

		protected virtual void OnDataCellValueRequesting(VLDataCellValueRequestingEventArgs e)
		{
			if (this.DataCellValueRequesting != null)
			{
				this.DataCellValueRequesting(this, e);
			}
		}
	}
	public class VLDataCellValueRequestingEventArgs : System.EventArgs
	{
		public VLDataRow Row { get; private set; }

		public VLDataColumn Column { get; private set; }

		public IDataCell Value { get; set; }

		public VLDataCellValueRequestingEventArgs(VLDataRow row, VLDataColumn column)
		{
			Row = row;
			Column = column;
		}
	}
	public class VariableQueryDialog : Window, IComponentConnector
	{
		private static readonly string[] AllOperators;

		private static readonly string[] AllOperatorsForNumeric;

		public static readonly DependencyProperty SelectedTypeProperty;

		public static readonly DependencyProperty QueryStringProperty;

		public static readonly DependencyProperty CanMatchWithModifiedProperty;

		public static readonly DependencyProperty CanMatchInObjectiveFunctionProperty;

		public static readonly DependencyProperty SelectedFieldProperty;

		public static readonly DependencyProperty SelectedQueryOperatorProperty;

		public static readonly DependencyProperty SelectedQueryRightBoolProperty;

		public static readonly DependencyProperty SelectedQueryRightTextProperty;

		public static readonly DependencyProperty SelectedQueryRightItemProperty;

		public static readonly DependencyProperty SelectedObjectiveFunctionProperty;

		public static readonly DependencyProperty SelectedModifiedFieldProperty;

		public static readonly DependencyProperty FieldsProperty;

		private static readonly DependencyPropertyKey QueryOperatorsPropertyKey;

		public static readonly DependencyProperty QueryOperatorsProperty;

		public static readonly DependencyPropertyKey ModifiableFieldsPropertyKey;

		public static readonly DependencyProperty ModifiableFieldsProperty;

		public static readonly RoutedUICommand AddConditionCommand;

		public static readonly RoutedUICommand ClearCommand;

		private int _loadedTimes;

		internal ComboBox comboBoxVariable;

		internal ComboBox comboBoxOperator;

		internal ComboBox comboBoxOperatorRightBool;

		internal ComboBox comboBoxOperatorRightItem;

		internal TextBox textBoxRightText;

		internal ComboBox comboBoxModifiedAttr;

		internal TextBox textBoxObjFunc;

		internal Button buttonAddCondition;

		internal Button buttonClear;

		internal Button buttonOK;

		internal Button buttonCancel;

		internal Button buttonHelp;

		internal Button buttonConditionAnd;

		internal Button buttonConditionOr;

		internal Button buttonConditionNot;

		internal Button buttonConditionLeftBracket;

		internal Button buttonConditionRightBracket;

		internal TextBox textBoxQuery;

		private bool _contentLoaded;

		public IEnumerable<bool> BooleanValues => new bool[2] { true, false };

		public int SelectedType
		{
			get
			{
				return (int)GetValue(SelectedTypeProperty);
			}
			set
			{
				SetValue(SelectedTypeProperty, value);
			}
		}

		public string QueryString
		{
			get
			{
				return (string)GetValue(QueryStringProperty);
			}
			set
			{
				SetValue(QueryStringProperty, value);
			}
		}

		public bool CanMatchWithModified
		{
			get
			{
				return (bool)GetValue(CanMatchWithModifiedProperty);
			}
			set
			{
				SetValue(CanMatchWithModifiedProperty, value);
			}
		}

		public bool CanMatchInObjectiveFunction
		{
			get
			{
				return (bool)GetValue(CanMatchInObjectiveFunctionProperty);
			}
			set
			{
				SetValue(CanMatchInObjectiveFunctionProperty, value);
			}
		}

		public QueryableFieldItem SelectedField
		{
			get
			{
				return (QueryableFieldItem)GetValue(SelectedFieldProperty);
			}
			set
			{
				SetValue(SelectedFieldProperty, value);
			}
		}

		public string SelectedQueryOperator
		{
			get
			{
				return (string)GetValue(SelectedQueryOperatorProperty);
			}
			set
			{
				SetValue(SelectedQueryOperatorProperty, value);
			}
		}

		public bool SelectedQueryRightBool
		{
			get
			{
				return (bool)GetValue(SelectedQueryRightBoolProperty);
			}
			set
			{
				SetValue(SelectedQueryRightBoolProperty, value);
			}
		}

		public string SelectedQueryRightText
		{
			get
			{
				return (string)GetValue(SelectedQueryRightTextProperty);
			}
			set
			{
				SetValue(SelectedQueryRightTextProperty, value);
			}
		}

		public object SelectedQueryRightItem
		{
			get
			{
				return GetValue(SelectedQueryRightItemProperty);
			}
			set
			{
				SetValue(SelectedQueryRightItemProperty, value);
			}
		}

		public QueryableFieldItem SelectedModifiedField
		{
			get
			{
				return (QueryableFieldItem)GetValue(SelectedModifiedFieldProperty);
			}
			set
			{
				SetValue(SelectedModifiedFieldProperty, value);
			}
		}

		public string SelectedObjectiveFunction
		{
			get
			{
				return (string)GetValue(SelectedObjectiveFunctionProperty);
			}
			set
			{
				SetValue(SelectedObjectiveFunctionProperty, value);
			}
		}

		public IEnumerable<QueryableFieldItem> Fields
		{
			get
			{
				return (IEnumerable<QueryableFieldItem>)GetValue(FieldsProperty);
			}
			set
			{
				SetValue(FieldsProperty, value);
			}
		}

		public IEnumerable<string> QueryOperators
		{
			get
			{
				return (IEnumerable<string>)GetValue(QueryOperatorsProperty);
			}
			private set
			{
				SetValue(QueryOperatorsPropertyKey, value);
			}
		}

		public IEnumerable<QueryableFieldItem> ModifiableFields
		{
			get
			{
				return (IEnumerable<QueryableFieldItem>)GetValue(ModifiableFieldsProperty);
			}
			private set
			{
				SetValue(ModifiableFieldsPropertyKey, value);
			}
		}

		static VariableQueryDialog()
		{
			AllOperators = new string[2] { "=", "<>" };
			AllOperatorsForNumeric = new string[6] { "=", "<>", "<", "<=", ">", ">=" };
			SelectedTypeProperty = DependencyProperty.Register("SelectedType", typeof(int), typeof(VariableQueryDialog));
			QueryStringProperty = DependencyProperty.Register("QueryString", typeof(string), typeof(VariableQueryDialog));
			CanMatchWithModifiedProperty = DependencyProperty.Register("CanMatchWithModified", typeof(bool), typeof(VariableQueryDialog));
			CanMatchInObjectiveFunctionProperty = DependencyProperty.Register("CanMatchInObjectiveFunction", typeof(bool), typeof(VariableQueryDialog));
			SelectedFieldProperty = DependencyProperty.Register("SelectedField", typeof(QueryableFieldItem), typeof(VariableQueryDialog));
			SelectedQueryOperatorProperty = DependencyProperty.Register("SelectedQueryOperator", typeof(string), typeof(VariableQueryDialog), new FrameworkPropertyMetadata("="));
			SelectedQueryRightBoolProperty = DependencyProperty.Register("SelectedQueryRightBool", typeof(bool), typeof(VariableQueryDialog), new FrameworkPropertyMetadata(true));
			SelectedQueryRightTextProperty = DependencyProperty.Register("SelectedQueryRightText", typeof(string), typeof(VariableQueryDialog));
			SelectedQueryRightItemProperty = DependencyProperty.Register("SelectedQueryRightItem", typeof(object), typeof(VariableQueryDialog));
			SelectedObjectiveFunctionProperty = DependencyProperty.Register("SelectedObjectiveFunction", typeof(string), typeof(VariableQueryDialog));
			SelectedModifiedFieldProperty = DependencyProperty.Register("SelectedModifiedField", typeof(QueryableFieldItem), typeof(VariableQueryDialog));
			FieldsProperty = DependencyProperty.Register("Fields", typeof(IEnumerable<QueryableFieldItem>), typeof(VariableQueryDialog), new FrameworkPropertyMetadata(OnFieldsPropertyChanged));
			QueryOperatorsPropertyKey = DependencyProperty.RegisterReadOnly("QueryOperators", typeof(IEnumerable<string>), typeof(VariableQueryDialog), new FrameworkPropertyMetadata());
			QueryOperatorsProperty = QueryOperatorsPropertyKey.DependencyProperty;
			ModifiableFieldsPropertyKey = DependencyProperty.RegisterReadOnly("ModifiableFields", typeof(IEnumerable<QueryableFieldItem>), typeof(VariableQueryDialog), new PropertyMetadata());
			ModifiableFieldsProperty = ModifiableFieldsPropertyKey.DependencyProperty;
			AddConditionCommand = new RoutedUICommand(GridFormsResources.VariableQueryDialog_Button_AddCondition, "AddConditionCommand", typeof(VariableQueryDialog));
			ClearCommand = new RoutedUICommand(GridFormsResources.VariableQueryDialog_Button_Clear, "ClearCommand", typeof(VariableQueryDialog));
			CommandManager.RegisterClassCommandBinding(typeof(VariableQueryDialog), new CommandBinding(AddConditionCommand, AddConditionCommand_Executed, AddConditionCommand_CanExecute));
			CommandManager.RegisterClassCommandBinding(typeof(VariableQueryDialog), new CommandBinding(ClearCommand, ClearCommand_Executed, ClearCommand_CanExecute));
		}

		public VariableQueryDialog()
		{
			InitializeComponent();
			base.Loaded += VariableQueryDialog_Loaded;
		}

		private void VariableQueryDialog_Loaded(object sender, RoutedEventArgs e)
		{
			_loadedTimes++;
			if (_loadedTimes == 1 && !string.IsNullOrEmpty(textBoxQuery.Text))
			{
				textBoxQuery.SelectionStart = textBoxQuery.Text.Length;
			}
		}

		protected virtual void OnFieldsChanged(IEnumerable<QueryableFieldItem> oldValue, IEnumerable<QueryableFieldItem> newValue)
		{
			if (newValue == null)
			{
				ModifiableFields = null;
				return;
			}
			ModifiableFields = newValue.Where((QueryableFieldItem x) => x.CanModify);
		}

		private void buttonOK_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void buttonCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void buttonConditionAnd_Click(object sender, RoutedEventArgs e)
		{
			AppendQueryString("AND");
		}

		private void buttonConditionOr_Click(object sender, RoutedEventArgs e)
		{
			AppendQueryString("OR");
		}

		private void buttonConditionNot_Click(object sender, RoutedEventArgs e)
		{
			AppendQueryString("NOT");
		}

		private void buttonConditionLeftBracket_Click(object sender, RoutedEventArgs e)
		{
			AppendQueryString("(");
		}

		private void buttonConditionRightBracket_Click(object sender, RoutedEventArgs e)
		{
			AppendQueryString(")");
		}

		private void comboBoxVariable_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (SelectedField == null)
			{
				return;
			}
			if (SelectedField.DataType == typeof(int) || SelectedField.DataType == typeof(double))
			{
				QueryOperators = AllOperatorsForNumeric;
			}
			else
			{
				QueryOperators = AllOperators;
			}
			SelectedQueryOperator = QueryOperators.FirstOrDefault();
			if (SelectedField.DataType == typeof(bool))
			{
				comboBoxOperatorRightBool.Visibility = Visibility.Visible;
				comboBoxOperatorRightItem.Visibility = Visibility.Collapsed;
				textBoxRightText.Visibility = Visibility.Collapsed;
			}
			else if (SelectedField.ItemsSource != null)
			{
				comboBoxOperatorRightBool.Visibility = Visibility.Collapsed;
				comboBoxOperatorRightItem.Visibility = Visibility.Visible;
				textBoxRightText.Visibility = Visibility.Collapsed;
			}
			else
			{
				comboBoxOperatorRightBool.Visibility = Visibility.Collapsed;
				comboBoxOperatorRightItem.Visibility = Visibility.Collapsed;
				textBoxRightText.Visibility = Visibility.Visible;
			}
			base.Dispatcher.BeginInvoke((Action)delegate
			{
				if (SelectedField.ItemsSource != null)
				{
					SelectedQueryRightItem = SelectedField.ItemsSource.Cast<object>().FirstOrDefault();
				}
			}, DispatcherPriority.Loaded);
		}

		private bool CanAddCondition()
		{
			if (SelectedType == 0 && SelectedField != null && !string.IsNullOrWhiteSpace(SelectedQueryOperator))
			{
				if (SelectedField.DataType == typeof(bool))
				{
					return comboBoxOperatorRightBool.SelectedItem != null;
				}
				if (SelectedField.ItemsSource != null)
				{
					return SelectedQueryRightItem != null;
				}
				return !string.IsNullOrWhiteSpace(SelectedQueryRightText);
			}
			if (SelectedType == 1)
			{
				return SelectedModifiedField != null;
			}
			if (SelectedType == 2)
			{
				return !string.IsNullOrWhiteSpace(SelectedObjectiveFunction);
			}
			return false;
		}

		private void AddCondition()
		{
			string text = string.Empty;
			if (SelectedType == 0 && SelectedField != null && !string.IsNullOrWhiteSpace(SelectedQueryOperator))
			{
				text = ((SelectedField.DataType == typeof(bool)) ? $"{SelectedField.EngineName} {SelectedQueryOperator} {SelectedQueryRightBool.ToString().ToUpper()}" : ((SelectedField.ItemsSource == null) ? $"{SelectedField.EngineName} {SelectedQueryOperator} {SelectedQueryRightText}" : $"{SelectedField.EngineName} {SelectedQueryOperator} {SelectedQueryRightItem}"));
			}
			else if (SelectedType == 1)
			{
				text = $"IsModified({SelectedModifiedField.EngineName})";
			}
			else if (SelectedType == 2)
			{
				text = $"InObjective({SelectedObjectiveFunction})";
			}
			if (!string.IsNullOrWhiteSpace(text))
			{
				AppendQueryString(text);
			}
		}

		private void AppendQueryString(string text)
		{
			int selectionStart = textBoxQuery.SelectionStart;
			int startIndex = textBoxQuery.SelectionStart + textBoxQuery.SelectionLength;
			string text2 = textBoxQuery.Text.Substring(0, selectionStart);
			string text3 = textBoxQuery.Text.Substring(startIndex);
			if (string.IsNullOrWhiteSpace(QueryString))
			{
				QueryString = text;
				textBoxQuery.SelectionStart = QueryString.Length;
				return;
			}
			if (selectionStart == QueryString.Length)
			{
				QueryString = text2.Trim() + "\r\n" + text;
				textBoxQuery.SelectionStart = QueryString.Length;
				return;
			}
			QueryString = text2 + " " + text + " " + text3;
			textBoxQuery.SelectionStart = QueryString.Length - text3.Length;
		}

		private static void OnFieldsPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as VariableQueryDialog).OnFieldsChanged((IEnumerable<QueryableFieldItem>)e.OldValue, (IEnumerable<QueryableFieldItem>)e.NewValue);
		}

		private static void AddConditionCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as VariableQueryDialog).AddCondition();
		}

		private static void AddConditionCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			VariableQueryDialog variableQueryDialog = sender as VariableQueryDialog;
			e.CanExecute = variableQueryDialog.CanAddCondition();
		}

		private static void ClearCommand_Executed(object sender, ExecutedRoutedEventArgs e)
		{
			(sender as VariableQueryDialog).QueryString = string.Empty;
		}

		private static void ClearCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
		{
			VariableQueryDialog variableQueryDialog = sender as VariableQueryDialog;
			e.CanExecute = !string.IsNullOrEmpty(variableQueryDialog.QueryString);
		}

		protected override void OnPreviewGotKeyboardFocus(KeyboardFocusChangedEventArgs e)
		{
			base.OnPreviewGotKeyboardFocus(e);
			FrameworkElement frameworkElement = e.NewFocus as FrameworkElement;
			if (frameworkElement == textBoxRightText || frameworkElement == comboBoxModifiedAttr || frameworkElement == textBoxObjFunc || frameworkElement == comboBoxVariable || frameworkElement == comboBoxOperator)
			{
				buttonAddCondition.IsDefault = true;
				buttonOK.IsDefault = false;
			}
			else
			{
				buttonAddCondition.IsDefault = false;
				buttonOK.IsDefault = true;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMForms.GridForms.Controls;component/variablequerydialog.xaml", UriKind.Relative);
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
				comboBoxVariable = (ComboBox)target;
				comboBoxVariable.SelectionChanged += comboBoxVariable_SelectionChanged;
				break;
			case 2:
				comboBoxOperator = (ComboBox)target;
				break;
			case 3:
				comboBoxOperatorRightBool = (ComboBox)target;
				break;
			case 4:
				comboBoxOperatorRightItem = (ComboBox)target;
				break;
			case 5:
				textBoxRightText = (TextBox)target;
				break;
			case 6:
				comboBoxModifiedAttr = (ComboBox)target;
				break;
			case 7:
				textBoxObjFunc = (TextBox)target;
				break;
			case 8:
				buttonAddCondition = (Button)target;
				break;
			case 9:
				buttonClear = (Button)target;
				break;
			case 10:
				buttonOK = (Button)target;
				buttonOK.Click += buttonOK_Click;
				break;
			case 11:
				buttonCancel = (Button)target;
				buttonCancel.Click += buttonCancel_Click;
				break;
			case 12:
				buttonHelp = (Button)target;
				break;
			case 13:
				buttonConditionAnd = (Button)target;
				buttonConditionAnd.Click += buttonConditionAnd_Click;
				break;
			case 14:
				buttonConditionOr = (Button)target;
				buttonConditionOr.Click += buttonConditionOr_Click;
				break;
			case 15:
				buttonConditionNot = (Button)target;
				buttonConditionNot.Click += buttonConditionNot_Click;
				break;
			case 16:
				buttonConditionLeftBracket = (Button)target;
				buttonConditionLeftBracket.Click += buttonConditionLeftBracket_Click;
				break;
			case 17:
				buttonConditionRightBracket = (Button)target;
				buttonConditionRightBracket.Click += buttonConditionRightBracket_Click;
				break;
			case 18:
				textBoxQuery = (TextBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls.Internal
{
	public static class ImageSourceHelper
	{
		private static readonly CommonImages _commonImages = new CommonImages();

		private static readonly Dictionary<string, ImageSource> _imageSources = new Dictionary<string, ImageSource>();

		public static readonly ImageSource HierarchicalImageSource = GetCustomImageSource("HierarchicalTreeView16.png");

		public static readonly ImageSource VariablePrefixImageSource = GetCustomImageSource("Variable16.png");

		public static readonly ImageSource OpenFileImageSource = _commonImages.Open_16;

		public static readonly ImageSource CloseFileImageSource = _commonImages.ClosedFolder_16;

		public static CommonImages CommonShellImages => _commonImages;

		private static ImageSource GetCustomImageSource(string imageName)
		{
			if (!_imageSources.ContainsKey(imageName))
			{
				string fullName = Assembly.GetExecutingAssembly().FullName;
				string uriString = "pack://application:,,,/" + fullName + ";component/Images/" + imageName;
				BitmapImage bitmapImage = new BitmapImage();
				bitmapImage.BeginInit();
				bitmapImage.UriSource = new Uri(uriString, UriKind.Absolute);
				bitmapImage.EndInit();
				_imageSources[imageName] = bitmapImage;
			}
			return _imageSources[imageName];
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls.EventArgs
{
	public class CommandExecutingEventArgs : RoutedEventArgs
	{
		public ICommand Command { get; private set; }

		public bool Cancel { get; set; }

		public CommandExecutingEventArgs(ICommand command, RoutedEvent routedEvent, object source)
			: base(routedEvent, source)
		{
			if (command == null)
			{
				throw new ArgumentNullException("command");
			}
			Command = command;
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls.Data
{
	public class CheckableItem : DependencyObject
	{
		public static readonly DependencyProperty IsCheckedProperty = DependencyProperty.Register("IsChecked", typeof(bool), typeof(CheckableItem), new PropertyMetadata(OnIsCheckedPropertyChanged));

		public static readonly DependencyProperty ContentProperty = DependencyProperty.Register("Content", typeof(object), typeof(CheckableItem));

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

		public object Content
		{
			get
			{
				return GetValue(ContentProperty);
			}
			set
			{
				SetValue(ContentProperty, value);
			}
		}

		public Action<CheckableItem> IsCheckedChangedAction { get; set; }

		protected virtual void OnIsCheckedChanged(bool oldValue, bool newValue)
		{
			if (IsCheckedChangedAction != null)
			{
				IsCheckedChangedAction(this);
			}
		}

		private static void OnIsCheckedPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as CheckableItem).OnIsCheckedChanged((bool)e.OldValue, (bool)e.NewValue);
		}
	}
	public class EditableListBoxItem : DependencyObject
	{
		public static readonly DependencyProperty TextProperty = DependencyProperty.Register("Text", typeof(string), typeof(EditableListBoxItem), new PropertyMetadata(OnTextPropertyChanged));

		public string Text
		{
			get
			{
				return (string)GetValue(TextProperty);
			}
			set
			{
				SetValue(TextProperty, value);
			}
		}

		internal EditableListBox ParentListBox { get; set; }

		protected virtual void OnTextChanged(string oldText, string newText)
		{
			if (ParentListBox != null)
			{
				ParentListBox.OnSubItemTextChanged(this, oldText, newText);
			}
		}

		private static void OnTextPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			(d as EditableListBoxItem).OnTextChanged((string)e.OldValue, (string)e.NewValue);
		}
	}
	public class QueryableFieldItem
	{
		public string DisplayName { get; set; }

		public string EngineName { get; set; }

		public Type DataType { get; set; }

		public IEnumerable ItemsSource { get; set; }

		public bool CanModify { get; set; }
	}
	public class TreeViewComboItem : DependencyObject
	{
		private static readonly DependencyPropertyKey ChildrenPropertyKey = DependencyProperty.RegisterReadOnly("Children", typeof(ObservableCollection<TreeViewComboItem>), typeof(TreeViewComboItem), new PropertyMetadata());

		public static readonly DependencyProperty ChildrenProperty = ChildrenPropertyKey.DependencyProperty;

		public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(TreeViewComboItem));

		public static readonly DependencyProperty HeaderImageSourceProperty = DependencyProperty.Register("HeaderImageSource", typeof(ImageSource), typeof(TreeViewComboItem));

		public static readonly DependencyProperty ExpandedHeaderImageSourceProperty = DependencyProperty.Register("ExpandedHeaderImageSource", typeof(ImageSource), typeof(TreeViewComboItem));

		public static readonly DependencyProperty IsExpandedProperty = DependencyProperty.Register("IsExpanded", typeof(bool), typeof(TreeViewComboItem), new UIPropertyMetadata(true));

		public static readonly DependencyProperty IsSelectedProperty = DependencyProperty.Register("IsSelected", typeof(bool), typeof(TreeViewComboItem));

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

		public ImageSource HeaderImageSource
		{
			get
			{
				return (ImageSource)GetValue(HeaderImageSourceProperty);
			}
			set
			{
				SetValue(HeaderImageSourceProperty, value);
			}
		}

		public ImageSource ExpandedHeaderImageSource
		{
			get
			{
				return (ImageSource)GetValue(ExpandedHeaderImageSourceProperty);
			}
			set
			{
				SetValue(ExpandedHeaderImageSourceProperty, value);
			}
		}

		public ObservableCollection<TreeViewComboItem> Children
		{
			get
			{
				return (ObservableCollection<TreeViewComboItem>)GetValue(ChildrenProperty);
			}
			private set
			{
				SetValue(ChildrenPropertyKey, value);
			}
		}

		public bool IsExpanded
		{
			get
			{
				return (bool)GetValue(IsExpandedProperty);
			}
			set
			{
				SetValue(IsExpandedProperty, value);
			}
		}

		public bool IsSelected
		{
			get
			{
				return (bool)GetValue(IsSelectedProperty);
			}
			set
			{
				SetValue(IsSelectedProperty, value);
			}
		}

		public TreeViewComboItem()
		{
			Children = new ObservableCollection<TreeViewComboItem>();
		}
	}
}
namespace AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters
{
	internal class BooleanToFilterUITypeConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			bool? flag = value as bool?;
			if (flag.HasValue)
			{
				if (flag.Value)
				{
					return FilterUIType.FilterRecord;
				}
				return FilterUIType.LabelIcons;
			}
			return FilterUIType.Default;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class CellVirtualizationConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && value is bool)
			{
				if ((bool)value)
				{
					return CellContainerGenerationMode.Recycle;
				}
				return CellContainerGenerationMode.PreLoad;
			}
			return CellContainerGenerationMode.Recycle;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class FilterComboDisplayTextConverter : IMultiValueConverter
	{
		public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 3 && values[0] != DependencyProperty.UnsetValue && values[1] != DependencyProperty.UnsetValue && values[2] != DependencyProperty.UnsetValue)
			{
				ComparisonCondition comparisonCondition = values[1] as ComparisonCondition;
				string text = null;
				if (comparisonCondition != null && comparisonCondition.Value != null)
				{
					text = ((!(comparisonCondition.Value is SpecialFilterOperandBase)) ? comparisonCondition.Value.ToString() : ((SpecialFilterOperandBase)comparisonCondition.Value).DisplayContent.ToString());
				}
				if (values[2] is XamComboEditor xamComboEditor)
				{
					xamComboEditor.Text = text;
				}
				return text;
			}
			return null;
		}

		public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class HorizontalAlignmentConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null)
			{
				return (HorizontalAlignment)value switch
				{
					HorizontalAlignment.Center => TextAlignment.Center, 
					HorizontalAlignment.Right => TextAlignment.Right, 
					_ => TextAlignment.Left, 
				};
			}
			return TextAlignment.Left;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class RadioButtonValueConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue && parameter != DependencyProperty.UnsetValue)
			{
				if (parameter is string)
				{
					return string.Equals(value.ToString(), parameter as string, StringComparison.OrdinalIgnoreCase);
				}
				return value == parameter;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue && parameter != DependencyProperty.UnsetValue && (value as bool?).HasValue)
			{
				return parameter;
			}
			return DependencyProperty.UnsetValue;
		}
	}
	public class SelectionModeConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value is SelectionMode)
			{
				if ((SelectionMode)value == SelectionMode.Single)
				{
					return SelectionType.Single;
				}
				return SelectionType.Extended;
			}
			return SelectionType.Default;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class SortDirectionToSortStatusConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && value != DependencyProperty.UnsetValue)
			{
				ListSortDirection? listSortDirection = value as ListSortDirection?;
				if (listSortDirection.HasValue)
				{
					return (listSortDirection.Value == ListSortDirection.Ascending) ? SortStatus.Ascending : SortStatus.Descending;
				}
			}
			return SortStatus.NotSorted;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class TooltipToVisibilityConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && value != DependencyProperty.UnsetValue)
			{
				return Visibility.Visible;
			}
			return Visibility.Collapsed;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class ValueExistingConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != DependencyProperty.UnsetValue && value != null)
			{
				return true;
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class YesNoToBooleanConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && value != DependencyProperty.UnsetValue)
			{
				return string.Equals(value.ToString(), "YES", StringComparison.OrdinalIgnoreCase);
			}
			return false;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value != null && value != DependencyProperty.UnsetValue && value is bool)
			{
				if (!(bool)value)
				{
					return "NO";
				}
				return "YES";
			}
			return "NO";
		}
	}
	public class BooleanInvertConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			bool? flag = value as bool?;
			if (flag.HasValue)
			{
				return !flag.Value;
			}
			return DependencyProperty.UnsetValue;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class DoubleToDoubleConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			double? num = value as double?;
			if (num.HasValue)
			{
				double? num2 = GetDouble(parameter);
				if (num2.HasValue)
				{
					return num.Value * num2.Value;
				}
				return num.Value;
			}
			return 0.0;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}

		private double? GetDouble(object input)
		{
			if (input != null)
			{
				double? result = input as double?;
				if (result.HasValue)
				{
					return result;
				}
				string text = input.ToString();
				if (!string.IsNullOrWhiteSpace(text))
				{
					double result2 = 0.0;
					if (double.TryParse(text, out result2))
					{
						return result2;
					}
				}
			}
			return null;
		}
	}
	public class ObjectEqualConverter : IMultiValueConverter, IValueConverter
	{
		object IMultiValueConverter.Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
		{
			if (values != null && values.Length == 2)
			{
				return values[0] == values[1];
			}
			return false;
		}

		object[] IMultiValueConverter.ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}

		object IValueConverter.Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return value == parameter;
		}

		object IValueConverter.ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
	public class TypeToHorizontalAlignmentConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			Type type = value as Type;
			if (type != null && (type == typeof(int) || type == typeof(double)))
			{
				return HorizontalAlignment.Right;
			}
			return HorizontalAlignment.Left;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000001 <>f__AnonymousType0`2.get_x
// {
// 	return <x>i__Field;
// }

// 0x06000002 <>f__AnonymousType0`2.get_y
// {
// 	return <y>i__Field;
// }

// 0x06000003 <>f__AnonymousType0`2..ctor
// using System.Diagnostics;
//
// [DebuggerHidden]
// public <>f__AnonymousType0(<x>j__TPar x, <y>j__TPar y)
// {
// 	<x>i__Field = x;
// 	<y>i__Field = y;
// }

// 0x06000004 <>f__AnonymousType0`2.Equals
// using System.Collections.Generic;
// using System.Diagnostics;
//
// [DebuggerHidden]
// public override bool Equals(object value)
// {
// 	global::<>f__AnonymousType0<<x>j__TPar, <y>j__TPar> anon = value as global::<>f__AnonymousType0<<x>j__TPar, <y>j__TPar>;
// 	if (this != anon)
// 	{
// 		if (anon != null && EqualityComparer<<x>j__TPar>.Default.Equals(<x>i__Field, anon.<x>i__Field))
// 		{
// 			return EqualityComparer<<y>j__TPar>.Default.Equals(<y>i__Field, anon.<y>i__Field);
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
// 	return (959378729 * -1521134295 + EqualityComparer<<x>j__TPar>.Default.GetHashCode(<x>i__Field)) * -1521134295 + EqualityComparer<<y>j__TPar>.Default.GetHashCode(<y>i__Field);
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
// 	<y>j__TPar val2 = <y>i__Field;
// 	array[1] = ((val2 != null) ? val2.ToString() : null);
// 	return string.Format(null, "{{ x = {0}, y = {1} }}", array);
// }

// 0x0600000c XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x06000023 AspenTech.AspenPlus.MMForms.GridForms.Controls.BreadCrumbNavigator..ctor
// public BreadCrumbNavigator()
// {
// }

// 0x06000031 AspenTech.AspenPlus.MMForms.GridForms.Controls.BreadCrumbNode..cctor
// using System.Windows;
//
// static BreadCrumbNode()
// {
// 	TextProperty = DependencyProperty.Register("Text", typeof(string), typeof(BreadCrumbNode));
// 	TagProperty = DependencyProperty.Register("Tag", typeof(object), typeof(BreadCrumbNode));
// 	HasChildrenPropertyKey = DependencyProperty.RegisterReadOnly("HasChildren", typeof(bool), typeof(BreadCrumbNode), null);
// 	HasChildrenProperty = HasChildrenPropertyKey.DependencyProperty;
// }

// 0x06000099 AspenTech.AspenPlus.MMForms.GridForms.Controls.PopupSelector..cctor
// using System.Collections.Generic;
// using System.Windows;
// using AspenTech.AspenPlus.MMForms.GridForms.Controls.Data;
//
// static PopupSelector()
// {
// 	ItemsProperty = DependencyProperty.Register("Items", typeof(IEnumerable<CheckableItem>), typeof(PopupSelector));
// 	PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(PopupSelector), new FrameworkPropertyMetadata(200.0));
// 	PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(PopupSelector), new UIPropertyMetadata(250.0));
// }

// 0x060000ae AspenTech.AspenPlus.MMForms.GridForms.Controls.ScopeSelectionControl..cctor
// using System.Collections.ObjectModel;
// using System.Windows;
// using AspenTech.AspenPlus.MMForms.GridForms.Controls.Data;
//
// static ScopeSelectionControl()
// {
// 	ItemsPropertyKey = DependencyProperty.RegisterReadOnly("Items", typeof(ObservableCollection<TreeViewComboItem>), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata());
// 	ItemsProperty = ItemsPropertyKey.DependencyProperty;
// 	SelectedItemProperty = DependencyProperty.Register("SelectedItem", typeof(TreeViewComboItem), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata(OnSelectedItemPropertyChanged));
// 	IsPopupOpenProperty = DependencyProperty.Register("IsPopupOpen", typeof(bool), typeof(ScopeSelectionControl));
// 	PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(ScopeSelectionControl), new FrameworkPropertyMetadata(200.0));
// 	PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(ScopeSelectionControl), new UIPropertyMetadata(250.0));
// 	SelectedItemChangedEvent = EventManager.RegisterRoutedEvent("SelectedItemChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<TreeViewComboItem>), typeof(ScopeSelectionControl));
// }

// 0x060000e1 AspenTech.AspenPlus.MMForms.GridForms.Controls.TreeViewPopupSelector..cctor
// using System.Collections.Generic;
// using System.Windows;
// using AspenTech.AspenPlus.MMForms.GridForms.Controls.Data;
//
// static TreeViewPopupSelector()
// {
// 	ItemsProperty = DependencyProperty.Register("Items", typeof(IEnumerable<TreeViewComboItem>), typeof(TreeViewPopupSelector));
// 	PopupWidthProperty = DependencyProperty.Register("PopupWidth", typeof(double), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata(200.0));
// 	PopupHeightProperty = DependencyProperty.Register("PopupHeight", typeof(double), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata(250.0));
// 	SelectedItemPropertyKey = DependencyProperty.RegisterReadOnly("SelectedItem", typeof(TreeViewComboItem), typeof(TreeViewPopupSelector), new FrameworkPropertyMetadata());
// 	SelectedItemProperty = SelectedItemPropertyKey.DependencyProperty;
// }

// 0x06000118 AspenTech.AspenPlus.MMForms.GridForms.Controls.VariableListDialog..cctor
// using System.Windows;
// using System.Windows.Controls;
//
// static VariableListDialog()
// {
// 	SelectionModeProperty = DependencyProperty.Register("SelectionMode", typeof(SelectionMode), typeof(VariableListDialog), new FrameworkPropertyMetadata(SelectionMode.Extended));
// 	DataSourceProperty = DependencyProperty.Register("DataSource", typeof(VLDataSource), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnDataSourcePropertyChanged));
// 	QueryStringProperty = DependencyProperty.Register("QueryString", typeof(string), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnQueryStringPropertyChanged));
// 	CanQueryProperty = DependencyProperty.Register("CanQuery", typeof(bool), typeof(VariableListDialog));
// 	StatusTextPropertyKey = DependencyProperty.RegisterReadOnly("StatusText", typeof(string), typeof(VariableListDialog), new FrameworkPropertyMetadata());
// 	StatusTextProperty = StatusTextPropertyKey.DependencyProperty;
// 	SelectedBreadCrumbNodeProperty = DependencyProperty.Register("SelectedBreadCrumbNode", typeof(BreadCrumbNode), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnSelectedBreadCrumbNodePropertyChanged));
// 	ShowOnlyChangedProperty = DependencyProperty.Register("ShowOnlyChanged", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyChangedPropertyChanged));
// 	ShowOnlyMarkedProperty = DependencyProperty.Register("ShowOnlyMarked", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyMarkedPropertyChanged));
// 	ShowOnlyAtBoundsProperty = DependencyProperty.Register("ShowOnlyAtBounds", typeof(bool), typeof(VariableListDialog), new FrameworkPropertyMetadata(OnShowOnlyAtBoundsPropertyChanged));
// 	QueryStringChangedEvent = EventManager.RegisterRoutedEvent("QueryStringChanged", RoutingStrategy.Bubble, typeof(RoutedPropertyChangedEventHandler<string>), typeof(VariableListDialog));
// }

// 0x06000121 AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataColumn..ctor
// public VLDataColumn()
// {
// }

// 0x0600012f AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataRow..cctor
// using System.Windows;
//
// static VLDataRow()
// {
// 	HeaderProperty = DependencyProperty.Register("Header", typeof(string), typeof(VLDataRow));
// 	GeneralIndexProperty = DependencyProperty.Register("GeneralIndex", typeof(int), typeof(VLDataRow));
// 	IsSelectedProperty = DependencyProperty.Register("IsSelected", typeof(bool), typeof(VLDataRow));
// }

// 0x0600013a AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataNode.add_PropertyChanged
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

// 0x0600013b AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataNode.remove_PropertyChanged
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

// 0x06000147 AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataSource.add_DataCellValueRequesting
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<VLDataCellValueRequestingEventArgs> eventHandler = this.DataCellValueRequesting;
// 	EventHandler<VLDataCellValueRequestingEventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<VLDataCellValueRequestingEventArgs> value2 = (EventHandler<VLDataCellValueRequestingEventArgs>)Delegate.Combine(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.DataCellValueRequesting, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000148 AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataSource.remove_DataCellValueRequesting
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	EventHandler<VLDataCellValueRequestingEventArgs> eventHandler = this.DataCellValueRequesting;
// 	EventHandler<VLDataCellValueRequestingEventArgs> eventHandler2;
// 	do
// 	{
// 		eventHandler2 = eventHandler;
// 		EventHandler<VLDataCellValueRequestingEventArgs> value2 = (EventHandler<VLDataCellValueRequestingEventArgs>)Delegate.Remove(eventHandler2, value);
// 		eventHandler = Interlocked.CompareExchange(ref this.DataCellValueRequesting, value2, eventHandler2);
// 	}
// 	while ((object)eventHandler != eventHandler2);
// }

// 0x06000189 AspenTech.AspenPlus.MMForms.GridForms.Controls.Properties.Settings..ctor
// public Settings()
// {
// }

// 0x0600018a AspenTech.AspenPlus.MMForms.GridForms.Controls.Properties.Settings..cctor
// using System.Configuration;
//
// static Settings()
// {
// 	defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());
// }

// 0x0600018d AspenTech.AspenPlus.MMForms.GridForms.Controls.Internal.ImageSourceHelper..cctor
// using System.Collections.Generic;
// using System.Windows.Media;
// using AspenTech.Visualisation.CommonImages;
//
// static ImageSourceHelper()
// {
// 	_commonImages = new CommonImages();
// 	_imageSources = new Dictionary<string, ImageSource>();
// 	HierarchicalImageSource = GetCustomImageSource("HierarchicalTreeView16.png");
// 	VariablePrefixImageSource = GetCustomImageSource("Variable16.png");
// 	OpenFileImageSource = _commonImages.Open_16;
// 	CloseFileImageSource = _commonImages.ClosedFolder_16;
// }

// 0x0600019b AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.CheckableItem..ctor
// public CheckableItem()
// {
// }

// 0x0600019c AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.CheckableItem..cctor
// using System.Windows;
//
// static CheckableItem()
// {
// 	IsCheckedProperty = DependencyProperty.Register("IsChecked", typeof(bool), typeof(CheckableItem), new PropertyMetadata(OnIsCheckedPropertyChanged));
// 	ContentProperty = DependencyProperty.Register("Content", typeof(object), typeof(CheckableItem));
// }

// 0x060001a3 AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.EditableListBoxItem..ctor
// public EditableListBoxItem()
// {
// }

// 0x060001a4 AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.EditableListBoxItem..cctor
// using System.Windows;
//
// static EditableListBoxItem()
// {
// 	TextProperty = DependencyProperty.Register("Text", typeof(string), typeof(EditableListBoxItem), new PropertyMetadata(OnTextPropertyChanged));
// }

// 0x060001af AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.QueryableFieldItem..ctor
// public QueryableFieldItem()
// {
// }

// 0x060001bd AspenTech.AspenPlus.MMForms.GridForms.Controls.Data.TreeViewComboItem..cctor
// using System.Collections.ObjectModel;
// using System.Windows;
// using System.Windows.Media;
//
// static TreeViewComboItem()
// {
// 	ChildrenPropertyKey = DependencyProperty.RegisterReadOnly("Children", typeof(ObservableCollection<TreeViewComboItem>), typeof(TreeViewComboItem), new PropertyMetadata());
// 	ChildrenProperty = ChildrenPropertyKey.DependencyProperty;
// 	TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(TreeViewComboItem));
// 	HeaderImageSourceProperty = DependencyProperty.Register("HeaderImageSource", typeof(ImageSource), typeof(TreeViewComboItem));
// 	ExpandedHeaderImageSourceProperty = DependencyProperty.Register("ExpandedHeaderImageSource", typeof(ImageSource), typeof(TreeViewComboItem));
// 	IsExpandedProperty = DependencyProperty.Register("IsExpanded", typeof(bool), typeof(TreeViewComboItem), new UIPropertyMetadata(true));
// 	IsSelectedProperty = DependencyProperty.Register("IsSelected", typeof(bool), typeof(TreeViewComboItem));
// }

// 0x060001c0 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.BooleanToFilterUITypeConverter..ctor
// public BooleanToFilterUITypeConverter()
// {
// }

// 0x060001c3 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.CellVirtualizationConverter..ctor
// public CellVirtualizationConverter()
// {
// }

// 0x060001c6 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.FilterComboDisplayTextConverter..ctor
// public FilterComboDisplayTextConverter()
// {
// }

// 0x060001c9 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.HorizontalAlignmentConverter..ctor
// public HorizontalAlignmentConverter()
// {
// }

// 0x060001cc AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.RadioButtonValueConverter..ctor
// public RadioButtonValueConverter()
// {
// }

// 0x060001cf AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.SelectionModeConverter..ctor
// public SelectionModeConverter()
// {
// }

// 0x060001d2 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.SortDirectionToSortStatusConverter..ctor
// public SortDirectionToSortStatusConverter()
// {
// }

// 0x060001d5 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.TooltipToVisibilityConverter..ctor
// public TooltipToVisibilityConverter()
// {
// }

// 0x060001d8 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.ValueExistingConverter..ctor
// public ValueExistingConverter()
// {
// }

// 0x060001db AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.YesNoToBooleanConverter..ctor
// public YesNoToBooleanConverter()
// {
// }

// 0x060001de AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.BooleanInvertConverter..ctor
// public BooleanInvertConverter()
// {
// }

// 0x060001e2 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.DoubleToDoubleConverter..ctor
// public DoubleToDoubleConverter()
// {
// }

// 0x060001e7 AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.ObjectEqualConverter..ctor
// public ObjectEqualConverter()
// {
// }

// 0x060001ea AspenTech.AspenPlus.MMForms.GridForms.Controls.Converters.TypeToHorizontalAlignmentConverter..ctor
// public TypeToHorizontalAlignmentConverter()
// {
// }

// 0x060001eb AspenTech.AspenPlus.MMForms.GridForms.Controls.BreadCrumbNavigator+<>c__DisplayClass26_0..ctor
// public <>c__DisplayClass26_0()
// {
// }

// 0x060001ed AspenTech.AspenPlus.MMForms.GridForms.Controls.CheckableComboBox+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060001ee AspenTech.AspenPlus.MMForms.GridForms.Controls.CheckableComboBox+<>c..ctor
// public <>c()
// {
// }

// 0x060001f2 AspenTech.AspenPlus.MMForms.GridForms.Controls.CheckableComboBox+<>c__DisplayClass63_0..ctor
// public <>c__DisplayClass63_0()
// {
// }

// 0x060001f4 AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060001f5 AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c..ctor
// public <>c()
// {
// }

// 0x060001f8 AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c__DisplayClass57_0`1..ctor
// public <>c__DisplayClass57_0()
// {
// }

// 0x060001fa AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c__DisplayClass59_0`1..ctor
// public <>c__DisplayClass59_0()
// {
// }

// 0x060001fc AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c__DisplayClass61_0`1..ctor
// public <>c__DisplayClass61_0()
// {
// }

// 0x060001fe AspenTech.AspenPlus.MMForms.GridForms.Controls.EditableListBox+<>c__DisplayClass63_0`1..ctor
// public <>c__DisplayClass63_0()
// {
// }

// 0x06000200 AspenTech.AspenPlus.MMForms.GridForms.Controls.PopupSelector+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000201 AspenTech.AspenPlus.MMForms.GridForms.Controls.PopupSelector+<>c..ctor
// public <>c()
// {
// }

// 0x06000203 AspenTech.AspenPlus.MMForms.GridForms.Controls.StringArraySerializer+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000204 AspenTech.AspenPlus.MMForms.GridForms.Controls.StringArraySerializer+<>c..ctor
// public <>c()
// {
// }

// 0x06000212 AspenTech.AspenPlus.MMForms.GridForms.Controls.VariableListDialog+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x06000213 AspenTech.AspenPlus.MMForms.GridForms.Controls.VariableListDialog+<>c..ctor
// public <>c()
// {
// }

// 0x06000215 AspenTech.AspenPlus.MMForms.GridForms.Controls.VLDataRow+<>c__DisplayClass19_0..ctor
// public <>c__DisplayClass19_0()
// {
// }

// 0x0600021c AspenTech.AspenPlus.MMForms.GridForms.Controls.VariableQueryDialog+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x0600021d AspenTech.AspenPlus.MMForms.GridForms.Controls.VariableQueryDialog+<>c..ctor
// public <>c()
// {
// }
