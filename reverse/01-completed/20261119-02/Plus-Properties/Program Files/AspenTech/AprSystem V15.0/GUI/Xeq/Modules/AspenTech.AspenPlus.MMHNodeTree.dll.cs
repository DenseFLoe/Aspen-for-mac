using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using AsepnTech.AspenPlus.MMHNodeTree.Images;
using AspenTech.AspenPlus.Happ;
using AspenTech.AspenPlus.MMHNodeTree.Properties;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.MMNodeTree")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("Aspen Plus")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenTech.AspenPlus.MMHNodeTree.Properties
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
					resourceMan = new ResourceManager("AspenTech.AspenPlus.MMHNodeTree.Properties.Resources", typeof(Resources).Assembly);
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

		internal static string DataSetText => ResourceManager.GetString("DataSetText", resourceCulture);

		internal static string MethodText => ResourceManager.GetString("MethodText", resourceCulture);

		internal static string ModelText => ResourceManager.GetString("ModelText", resourceCulture);

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
namespace AsepnTech.AspenPlus.MMHNodeTree
{
	public class NodeTree_ViewModel : INotifyPropertyChanged
	{
		private ObservableCollection<NodeTreeNode> _rootNode;

		private NodeTreeNode _selection;

		public ObservableCollection<NodeTreeNode> RootNode => _rootNode;

		public string Prompt { get; private set; }

		public bool ExpandOnBuild { get; private set; }

		internal NodeTreeNode Selection
		{
			get
			{
				return _selection;
			}
			set
			{
				_selection = value;
				Prompt = _selection.Prompt;
				this.PropertyChanged(this, new PropertyChangedEventArgs("Prompt"));
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public void Initialize(object root, bool expandOnBuild)
		{
			ExpandOnBuild = expandOnBuild;
			_rootNode = new ObservableCollection<NodeTreeNode>();
			_rootNode.Add(new NodeTreeNode(root as IHNode, this));
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs("RootNode"));
			}
		}
	}
	public class NodeTreeControl : UserControl, IComponentConnector
	{
		public static DependencyProperty ViewModelProperty = DependencyProperty.Register("ViewModel", typeof(NodeTree_ViewModel), typeof(NodeTreeControl), new FrameworkPropertyMetadata(null, OnViewModelPropertyChanged));

		private object _rootNode;

		internal TreeView nodeTree;

		internal TextBlock Prompt;

		private bool _contentLoaded;

		[Microsoft.Practices.Unity.Dependency]
		public NodeTree_ViewModel ViewModel
		{
			get
			{
				return GetValue(ViewModelProperty) as NodeTree_ViewModel;
			}
			set
			{
				SetValue(ViewModelProperty, value);
			}
		}

		public object RootNode
		{
			get
			{
				return _rootNode;
			}
			set
			{
				_rootNode = value;
				if (_rootNode != null)
				{
					ViewModel.Initialize(_rootNode, ExpandOnBuild);
				}
			}
		}

		public bool ExpandOnBuild { get; set; }

		[Microsoft.Practices.Unity.Dependency]
		public IUnityContainer UnityContainer { get; set; }

		public NodeTreeControl()
		{
			ExpandOnBuild = true;
			InitializeComponent();
		}

		private static void OnViewModelPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs args)
		{
			NodeTreeControl nodeTreeControl = d as NodeTreeControl;
			if (args.NewValue != null)
			{
				nodeTreeControl.DataContext = args.NewValue;
			}
		}

		private void UserControl_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
		}

		private void nodeTree_PreviewMouseDown(object sender, MouseButtonEventArgs e)
		{
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.MMHNodeTree;component/nodetree.xaml", UriKind.Relative);
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
				((NodeTreeControl)target).PreviewMouseDown += UserControl_PreviewMouseDown;
				break;
			case 2:
				nodeTree = (TreeView)target;
				break;
			case 3:
				Prompt = (TextBlock)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	[Module(ModuleName = "AspenTech.AspenPlus.MMNodeTree")]
	public class MMNodeTreeModule : IModule
	{
		public const string MMNodeTreeModuleName = "AspenTech.AspenPlus.MMNodeTree";

		public IUnityContainer Container { get; private set; }

		public MMNodeTreeModule(IUnityContainer container)
		{
			Container = container;
		}

		public void Initialize()
		{
			Container.RegisterType<UserControl, NodeTreeControl>("MMNodeTree", new TransientLifetimeManager(), Array.Empty<InjectionMember>());
		}
	}
	public class NodeTreeNode : INotifyPropertyChanged, IDisposable
	{
		private IHNode _node;

		private ObservableCollection<NodeTreeNode> _children;

		private NodeTree_ViewModel _tree;

		private bool _isExpanded;

		private string _text;

		private bool _isSelected;

		public ObservableCollection<NodeTreeNode> Children => _children;

		public bool IsExpanded
		{
			get
			{
				return _isExpanded;
			}
			set
			{
				_isExpanded = value;
			}
		}

		public string Text
		{
			get
			{
				return _text;
			}
			private set
			{
				_text = value;
			}
		}

		public ImageSource Image { get; private set; }

		internal string Prompt { get; set; }

		public bool IsSelected
		{
			get
			{
				return _isSelected;
			}
			set
			{
				_isSelected = value;
				if (_isSelected)
				{
					_tree.Selection = this;
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		public NodeTreeNode(IHNode node, NodeTree_ViewModel tree, bool top = true)
		{
			_node = node;
			_tree = tree;
			if (tree != null)
			{
				_isExpanded = tree.ExpandOnBuild;
			}
			if (_node == null)
			{
				return;
			}
			string arg = "";
			string arg2 = "";
			int? num = 0;
			string arg3 = "";
			try
			{
				arg = _node.get_Value(Type.Missing) as string;
				arg2 = _node.get_AttributeValue((short)24, Type.Missing) as string;
				arg3 = ((_node.get_AttributeValue((short)25, Type.Missing) as int?) ?? 1).ToString(CultureInfo.InvariantCulture);
			}
			catch (COMException)
			{
			}
			try
			{
				Prompt = _node.get_AttributeValue((short)19, Type.Missing) as string;
			}
			catch (COMException)
			{
			}
			IHNodeCol iHNodeCol = null;
			try
			{
				iHNodeCol = _node.Elements;
			}
			catch (COMException)
			{
			}
			if (iHNodeCol != null)
			{
				Text = string.Format(Resources.MethodText, arg, arg2, arg3);
				Image = ImageResources.Method;
				RefreshChildren(iHNodeCol);
				return;
			}
			if (top)
			{
				Text = string.Format(Resources.ModelText, arg, arg2, arg3);
			}
			else
			{
				Text = string.Format(Resources.DataSetText, arg, arg2, arg3);
			}
			Image = ImageResources.Model;
		}

		private void RefreshChildren(IHNodeCol elements)
		{
			_children = new ObservableCollection<NodeTreeNode>();
			foreach (IHNode element in elements)
			{
				_children.Add(new NodeTreeNode(element, _tree, top: false));
			}
		}

		public void Dispose()
		{
			if (_node != null)
			{
				Marshal.ReleaseComObject(_node);
				_node = null;
			}
		}
	}
}
namespace AsepnTech.AspenPlus.MMHNodeTree.Images
{
	internal class ImageResources
	{
		private static readonly Dictionary<string, ImageSource> _imageSources = new Dictionary<string, ImageSource>();

		public static ImageSource Model => GetImageSource("model.png");

		public static ImageSource Method => GetImageSource("method.png");

		private static ImageSource GetImageSource(string imageFileName)
		{
			if (!_imageSources.ContainsKey(imageFileName))
			{
				StringBuilder stringBuilder = new StringBuilder();
				stringBuilder.Append("pack://application:,,,/");
				stringBuilder.Append(typeof(ImageResources).Assembly.FullName);
				stringBuilder.Append(";component/Images/");
				stringBuilder.Append(imageFileName);
				_imageSources.Add(imageFileName, new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute)));
			}
			return _imageSources[imageFileName];
		}
	}
}
namespace AspenTech.AspenPlus.Happ
{
	[ComImport]
	[CompilerGenerated]
	[Guid("8E567522-F9BA-11CF-90B2-0000C0A810C4")]
	[TypeIdentifier]
	public interface IHNode
	{
		void _VtblGap1_6();

		// Indexed COM property Value, DispId 1610743814. See the Property/MethodSemantics rows in the IL.
		[SpecialName]
		[DispId(1610743814)]
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		object get_Value([In, Optional, MarshalAs(UnmanagedType.Struct)] object force);

		[SpecialName]
		[DispId(1610743814)]
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void set_Value([In, Optional, MarshalAs(UnmanagedType.Struct)] object force, [In, MarshalAs(UnmanagedType.Struct)] object Value);

		void _VtblGap2_4();

		// Indexed COM property AttributeValue, DispId 1610743820. See the Property/MethodSemantics rows in the IL.
		[SpecialName]
		[DispId(1610743820)]
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[return: MarshalAs(UnmanagedType.Struct)]
		object get_AttributeValue([In] short attrnumber, [In, Optional, MarshalAs(UnmanagedType.Struct)] object force);

		[SpecialName]
		[DispId(1610743820)]
		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		void set_AttributeValue([In] short attrnumber, [In, Optional, MarshalAs(UnmanagedType.Struct)] object force, [In, MarshalAs(UnmanagedType.Struct)] object Value);

		void _VtblGap3_4();

		[DispId(1610743826)]
		IHNodeCol Elements
		{
			[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
			[DispId(1610743826)]
			[return: MarshalAs(UnmanagedType.Interface)]
			get;
		}
	}
	[ComImport]
	[CompilerGenerated]
	[Guid("89E81F60-019A-11D0-9BE7-0000C05375D5")]
	[DefaultMember("Item")]
	[TypeIdentifier]
	public interface IHNodeCol : IEnumerable
	{
		void _VtblGap1_16();

		[MethodImpl(MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime)]
		[DispId(-4)]
		[return: MarshalAs(UnmanagedType.CustomMarshaler, MarshalType = "System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a")]
		new IEnumerator GetEnumerator();
	}
}
