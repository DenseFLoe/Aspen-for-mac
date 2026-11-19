using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using AspenTech.Visualisation.CommonShell;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyTitle("AspenTech.Engineering.FlowsheetOverlay")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.Engineering.FlowsheetOverlay")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, Inc. 2013 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("2baefd8e-f64c-4e88-9918-0d34d39c430b")]
[assembly: AssemblyFileVersion("41.0.0.19")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.19")]
namespace AspenTech.Engineering.FlowsheetOverlay;

public enum ActivateOverlaysType
{
	_edrActivation,
	_economicsAnalysis
}
public class OverlayActivationDeactivationEvent : RoutedCompositePresentationEvent<OverlayActivationDeactivationEventArgs>
{
}
public class OverlayActivationDeactivationEventArgs : EventArgs
{
	public ActivateOverlaysType _activeOverlayType { get; set; }

	public bool _isActivating { get; set; }

	public OverlayActivationDeactivationEventArgs(bool bActivating, ActivateOverlaysType activeOverlayType)
	{
		_activeOverlayType = activeOverlayType;
		_isActivating = bActivating;
	}
}
internal delegate void Hover(object sender, bool isHoverIn);
internal class AnnotationCircle
{
	private UIElement _ellipse;

	private UIElement _hoverBox;

	private string _name;

	private IFlyover _flyover;

	private object _collection;

	private UIElement _parent;

	private double _strokeThickness = 3.0;

	private DoubleCollection _strokeDashArray = new DoubleCollection(new double[2] { 4.0, 2.0 });

	public UIElement Parent => _parent;

	public UIElement HoverBox => _hoverBox;

	internal event Hover MouseHover;

	internal AnnotationCircle(UIElement parent, double top, double left, SolidColorBrush colorBrush, bool solid, string name, IFlyover flyover, object currentCollection, double diameter = 30.0, bool isSolid = false)
	{
		_parent = parent;
		_name = name;
		_flyover = flyover;
		_collection = currentCollection;
		_ellipse = Draw(top, left, colorBrush, solid, diameter, isSolid);
		_ellipse.MouseEnter += _ellipse_MouseEnter;
		_ellipse.MouseLeave += _ellipse_MouseLeave;
		_ellipse.IsVisibleChanged += OnEllipseVisibleChanged;
	}

	private void OnEllipseVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
	{
		if (e.NewValue.Equals(false))
		{
			this.MouseHover(this, isHoverIn: false);
			_ellipse.IsVisibleChanged -= OnEllipseVisibleChanged;
		}
	}

	private void _ellipse_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
	{
		this.MouseHover(this, isHoverIn: false);
	}

	private void _ellipse_MouseEnter(object sender, System.Windows.Input.MouseEventArgs e)
	{
		if (_hoverBox == null)
		{
			_hoverBox = DrawHoverBox();
		}
		this.MouseHover(this, isHoverIn: true);
	}

	public UIElement Draw()
	{
		return _ellipse;
	}

	public UIElement Draw(double top, double left, SolidColorBrush colorBrush, bool glow, double diameter = 30.0, bool isSolid = false)
	{
		Ellipse ellipse = new Ellipse();
		ellipse.Height = diameter;
		ellipse.Width = diameter;
		ellipse.Fill = Brushes.Transparent;
		ellipse.StrokeThickness = _strokeThickness;
		Canvas.SetLeft(ellipse, left);
		Canvas.SetTop(ellipse, top);
		ellipse.Stroke = colorBrush;
		if (glow)
		{
			ellipse.Effect = new DropShadowEffect
			{
				ShadowDepth = 0.0,
				Opacity = 1.0,
				BlurRadius = 12.0,
				Color = Colors.Black
			};
		}
		if (!isSolid)
		{
			ellipse.StrokeDashArray = _strokeDashArray;
		}
		return ellipse;
	}

	private UIElement DrawHoverBox()
	{
		Popup popup = new Popup();
		if (_flyover != null)
		{
			popup.Child = _flyover.GetPopup(_name, _collection);
		}
		popup.PlacementTarget = _ellipse;
		popup.Placement = PlacementMode.MousePoint;
		return popup;
	}

	private UIElement DrawTextBlock(double left, double top, string text)
	{
		TextBlock textBlock = new TextBlock();
		Canvas.SetLeft(textBlock, left);
		Canvas.SetTop(textBlock, top);
		textBlock.Text = text;
		return textBlock;
	}
}
[Module(ModuleName = "AspenTech.Engineering.FlowsheetOverlay")]
public class FlowsheetOverlayModule : IModule
{
	public const string ModuleName = "AspenTech.Engineering.FlowsheetOverlay";

	private IUnityContainer _container;

	public FlowsheetOverlayModule(IUnityContainer container)
	{
		_container = container;
	}

	public void Initialize()
	{
		_container.RegisterType<IPFDHighlight, PFDHighlightProvider>(Array.Empty<InjectionMember>());
	}
}
public class FlowSheetTransparentOverlay : Window, IDisposable
{
	private enum GetWindow_Cmd : uint
	{
		GW_HWNDFIRST,
		GW_HWNDLAST,
		GW_HWNDNEXT,
		GW_HWNDPREV,
		GW_OWNER,
		GW_CHILD,
		GW_ENABLEDPOPUP
	}

	private WindowsFormsHost _flowsheet;

	private Canvas _overlay;

	private Canvas _flyoverOverlay;

	private DependencyPropertyChangedEventHandler OnFlowSheetVisibilityChangedHandler;

	private RoutedEventHandler OnFlowSheetLoadedHandler;

	public static readonly DependencyProperty ParentWindowProperty = DependencyProperty.RegisterAttached("ParentWindow", typeof(Window), typeof(FlowSheetTransparentOverlay), new UIPropertyMetadata(null, ParentWindowPropertyChanged));

	private static readonly IntPtr HWND_TOPMOST = new IntPtr(-1);

	private static readonly IntPtr HWND_NOTOPMOST = new IntPtr(-2);

	private static readonly IntPtr HWND_TOP = new IntPtr(0);

	private static readonly IntPtr HWND_BOTTOM = new IntPtr(1);

	private const uint SWP_NOSIZE = 1u;

	private const uint SWP_NOMOVE = 2u;

	private const uint SWP_NOZORDER = 4u;

	private const uint SWP_NOREDRAW = 8u;

	private const uint SWP_NOACTIVATE = 16u;

	private const uint SWP_ASYNCWINDOWPOS = 16384u;

	private const uint SWP_FRAMECHANGED = 32u;

	private const uint SWP_SHOWWINDOW = 64u;

	private const uint SWP_HIDEWINDOW = 128u;

	private const uint SWP_NOCOPYBITS = 256u;

	private const uint SWP_NOOWNERZORDER = 512u;

	private const uint SWP_NOSENDCHANGING = 1024u;

	public Window ParentWindow
	{
		get
		{
			return (Window)GetValue(ParentWindowProperty);
		}
		set
		{
			Window window = (Window)GetValue(ParentWindowProperty);
			if (window != null && window != value)
			{
				window.LocationChanged -= ParentLocationChanged;
				window.SizeChanged -= ParentSizeChanged;
				window.StateChanged -= ParentStateChanged;
			}
			SetValue(ParentWindowProperty, value);
		}
	}

	public Canvas Child => _overlay;

	public WindowsFormsHost Flowsheet
	{
		get
		{
			return _flowsheet;
		}
		set
		{
			if (_flowsheet != null)
			{
				_flowsheet.Loaded -= OnFlowSheetLoadedHandler;
				_flowsheet.IsVisibleChanged -= OnFlowSheetVisibilityChangedHandler;
			}
			_flowsheet = value;
			if (_flowsheet != null)
			{
				_flowsheet.Loaded += OnFlowSheetLoadedHandler;
				_flowsheet.IsVisibleChanged += OnFlowSheetVisibilityChangedHandler;
			}
		}
	}

	private static void ParentWindowPropertyChanged(DependencyObject source, DependencyPropertyChangedEventArgs e)
	{
		(source as FlowSheetTransparentOverlay).ParentWindowChanged();
	}

	private void ParentWindowChanged()
	{
		if (ParentWindow != null)
		{
			ParentWindow.LocationChanged += ParentLocationChanged;
			ParentWindow.SizeChanged += ParentSizeChanged;
			ParentWindow.StateChanged += ParentStateChanged;
		}
	}

	private void ParentLocationChanged(object sender, EventArgs e)
	{
		UpdatePosition();
	}

	private void ParentSizeChanged(object sender, EventArgs e)
	{
		UpdatePosition();
	}

	private void ParentStateChanged(object sender, EventArgs e)
	{
		if (ParentWindow != null && ParentWindow.Owner != null)
		{
			if (base.IsVisible && ParentWindow.Owner.WindowState.Equals(WindowState.Minimized))
			{
				Hide();
			}
			else if (!base.IsVisible && !ParentWindow.Owner.WindowState.Equals(WindowState.Minimized))
			{
				Show();
			}
		}
	}

	public FlowSheetTransparentOverlay()
	{
		_flyoverOverlay = new Canvas();
		_overlay = new Canvas();
		_overlay.HorizontalAlignment = System.Windows.HorizontalAlignment.Stretch;
		_overlay.VerticalAlignment = VerticalAlignment.Stretch;
		_overlay.Background = new SolidColorBrush(Colors.Transparent);
		_overlay.ClipToBounds = true;
		_overlay.Children.Add(_flyoverOverlay);
		_flyoverOverlay.HorizontalAlignment = System.Windows.HorizontalAlignment.Stretch;
		_flyoverOverlay.VerticalAlignment = VerticalAlignment.Stretch;
		_flyoverOverlay.Background = new SolidColorBrush(Colors.Transparent);
		_flyoverOverlay.ClipToBounds = true;
		System.Windows.Data.Binding binding = new System.Windows.Data.Binding
		{
			Source = _overlay,
			Path = new PropertyPath("ActualWidth")
		};
		System.Windows.Data.Binding binding2 = new System.Windows.Data.Binding
		{
			Source = _overlay,
			Path = new PropertyPath("ActualHeight")
		};
		_flyoverOverlay.SetBinding(FrameworkElement.WidthProperty, binding);
		_flyoverOverlay.SetBinding(FrameworkElement.HeightProperty, binding2);
		base.Background = new SolidColorBrush(Colors.Transparent);
		base.WindowStyle = WindowStyle.None;
		base.Content = _overlay;
		base.AllowsTransparency = true;
		base.ShowInTaskbar = false;
		base.ShowActivated = false;
		base.WindowStartupLocation = WindowStartupLocation.Manual;
		base.Topmost = false;
		base.Focusable = false;
		OnFlowSheetVisibilityChangedHandler = delegate(object o, DependencyPropertyChangedEventArgs e)
		{
			base.Dispatcher.BeginInvoke(new DependencyPropertyChangedEventHandler(OnFlowSheetVisibilityChanged), o, e);
		};
		OnFlowSheetLoadedHandler = delegate(object o, RoutedEventArgs e)
		{
			base.Dispatcher.BeginInvoke(new RoutedEventHandler(OnFlowSheetLoaded), o, e);
		};
	}

	public void UpdatePosition()
	{
		if (PresentationSource.FromVisual(this) is HwndSource hwndSource && Flowsheet != null && PresentationSource.FromVisual(Flowsheet) != null)
		{
			Point point = Flowsheet.PointToScreen(new Point(0.0, 0.0));
			int num = (int)(Flowsheet.RenderSize.Width - SystemParameters.VerticalScrollBarWidth);
			int num2 = (int)(Flowsheet.RenderSize.Height - SystemParameters.HorizontalScrollBarHeight);
			if (num < 0)
			{
				num = (int)Flowsheet.RenderSize.Width;
			}
			if (num2 < 0)
			{
				num2 = (int)Flowsheet.RenderSize.Height;
			}
			if (num == 0 || num2 == 0)
			{
				Hide();
			}
			else if (Flowsheet.IsVisible && !base.IsVisible)
			{
				Show();
			}
			SetWindowPos(hwndSource.Handle, HWND_NOTOPMOST, (int)point.X, (int)point.Y, num, num2, 16404u);
		}
	}

	public void UpdateParentWindow(Window newParent)
	{
		HwndSource hwndSource = PresentationSource.FromVisual(this) as HwndSource;
		ParentWindow = newParent;
		if (Flowsheet != null && hwndSource != null)
		{
			SetWindowLongPtr(new HandleRef(this, hwndSource.Handle), -8, Flowsheet.Handle);
		}
		UpdatePosition();
	}

	private void OnFlowSheetLoaded(object sender, EventArgs e)
	{
		if (sender is WindowsFormsHost windowsFormsHost)
		{
			if (windowsFormsHost.IsVisible && !base.IsVisible)
			{
				Show();
			}
			UpdatePosition();
		}
	}

	private void OnFlowSheetVisibilityChanged(object sender, DependencyPropertyChangedEventArgs e)
	{
		if (!(sender is WindowsFormsHost windowsFormsHost))
		{
			if (base.IsVisible)
			{
				Hide();
			}
		}
		else if (windowsFormsHost.IsVisible)
		{
			if (!base.IsVisible)
			{
				Show();
			}
		}
		else if (base.IsVisible)
		{
			Hide();
		}
	}

	protected override void OnSourceInitialized(EventArgs e)
	{
		base.OnSourceInitialized(e);
		(PresentationSource.FromVisual(this) as HwndSource).AddHook(HandleMessages);
	}

	private IntPtr HandleMessages(IntPtr hwnd, int msg, IntPtr wparam, IntPtr lparam, ref bool handled)
	{
		if ((msg == 70 || msg == 71) && Flowsheet != null)
		{
			HwndSource hwndSource = PresentationSource.FromVisual(this) as HwndSource;
			if (!(PresentationSource.FromVisual(Flowsheet) is HwndSource hwndSource2) || hwndSource == null)
			{
				return IntPtr.Zero;
			}
			IntPtr window = GetWindow(hwndSource2.Handle, GetWindow_Cmd.GW_HWNDPREV);
			SetWindowPos(hwndSource.Handle, window, 0, 0, 0, 0, 17939u);
		}
		return IntPtr.Zero;
	}

	public void Dispose()
	{
		if (PresentationSource.FromVisual(this) is HwndSource hwndSource)
		{
			hwndSource.RemoveHook(HandleMessages);
		}
		if (ParentWindow != null)
		{
			ParentWindow.LocationChanged -= ParentLocationChanged;
			ParentWindow.SizeChanged -= ParentSizeChanged;
			ParentWindow.StateChanged -= ParentStateChanged;
		}
		if (_flowsheet != null)
		{
			_flowsheet.Loaded -= OnFlowSheetLoadedHandler;
			_flowsheet.IsVisibleChanged -= OnFlowSheetVisibilityChangedHandler;
			_flowsheet = null;
		}
		base.Dispatcher.BeginInvoke(new MethodInvoker(base.Close));
	}

	public static IntPtr SetWindowLongPtr(HandleRef hWnd, int nIndex, IntPtr dwNewLong)
	{
		if (IntPtr.Size == 8)
		{
			return SetWindowLongPtr64(hWnd, nIndex, dwNewLong);
		}
		return new IntPtr(SetWindowLong32(hWnd, nIndex, dwNewLong.ToInt32()));
	}

	[DllImport("user32.dll")]
	private static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

	[DllImport("user32.dll", EntryPoint = "SetWindowLong")]
	private static extern int SetWindowLong32(HandleRef hWnd, int nIndex, int dwNewLong);

	[DllImport("user32.dll", EntryPoint = "SetWindowLongPtr")]
	private static extern IntPtr SetWindowLongPtr64(HandleRef hWnd, int nIndex, IntPtr dwNewLong);

	[DllImport("user32.dll", SetLastError = true)]
	private static extern IntPtr GetWindow(IntPtr hWnd, GetWindow_Cmd uCmd);

	[DllImport("user32.dll", SetLastError = true)]
	private static extern IntPtr SetFocus(IntPtr hWnd);
}
public interface IFlyover
{
	System.Windows.Controls.UserControl GetPopup(string key, object currentCollection);
}
public interface IPFDHighlight
{
	void RemoveHighlight(string name);

	void ClearHighlights();

	void Highlight(string name, bool glow, IDictionary<string, Color> colors, object currentCollection, IFlyover flyover, bool isSolid = true);

	void AddHighlights(bool glow, IDictionary<string, Color> colors, object currentCollection, IFlyover flyover, bool isSolid = true);

	void AddLegends();

	void ClearLegends();

	void Legend(string overlayName, bool isSelected);
}
public interface IOverlayLocationInfo
{
	Rect Rect { get; }
}
public interface IFlowsheetOverlay
{
	Canvas GetOverlay();

	IDictionary<string, IOverlayLocationInfo> GetLocationInfo();

	IDictionary<string, IOverlayLocationInfo> GetBlocksLocationInfo(List<string> blockNames);

	IDictionary<string, string> MapBlockNamesToHandles(List<string> blockNames);

	Size GetFlowsheetDesiredSize();

	Rect GetActivePaneBounds();
}
public interface IFlowsheetOverlayManager
{
	IList<string> Names { get; }

	IFlowsheetOverlay GetOverlay(string name);
}
public class OverlayRefreshEvent : RoutedCompositePresentationEvent<OverlayRefreshEventArgs>
{
}
public class OverlayRefreshEventArgs : EventArgs
{
	public string Name { get; set; }

	public OverlayRefreshEventArgs(string name)
	{
		Name = name;
	}
}
public class OverlayAddedEvent : RoutedCompositePresentationEvent<OverlayAddedEventArgs>
{
}
public class OverlayAddedEventArgs : EventArgs
{
	public string Name { get; set; }

	public OverlayAddedEventArgs(string name)
	{
		Name = name;
	}
}
internal class PFDHighlightProvider : IPFDHighlight
{
	private IUnityContainer _container;

	private IFlowsheetOverlayManager _overlayManager;

	private Image draggedImage;

	private Point mousePosition;

	private Point _startPoint;

	private double _originalLeft;

	private double _originalTop;

	private bool _isDown;

	private bool _isDragging;

	private Canvas _canvas;

	private SimpleCircleAdorner _overlayElement;

	private static Point _savedLegendPos;

	public PFDHighlightProvider(IUnityContainer container)
	{
		_container = container;
		ResolveOverlay();
	}

	private void ResolveOverlay()
	{
		_overlayManager = _container.Resolve<IFlowsheetOverlayManager>(Array.Empty<ResolverOverride>());
		_ = _overlayManager;
	}

	public void ClearHighlights()
	{
		foreach (string name in _overlayManager.Names)
		{
			Canvas canvas = _overlayManager.GetOverlay(name).GetOverlay().Children.OfType<Canvas>().FirstOrDefault();
			canvas?.Children.RemoveRange(0, canvas.Children.Count);
		}
	}

	public void AddHighlights(bool glow, IDictionary<string, Color> colors, object currentCollection, IFlyover flyover, bool isSolid = true)
	{
		ResolveOverlay();
		foreach (string name in _overlayManager.Names)
		{
			Highlight(name, glow, colors, currentCollection, flyover, isSolid);
		}
	}

	public void Highlight(string overlayName, bool glow, IDictionary<string, Color> colors, object currentCollection, IFlyover flyover, bool isSolid = true)
	{
		IFlowsheetOverlay overlay = _overlayManager.GetOverlay(overlayName);
		if (overlay == null)
		{
			return;
		}
		Canvas canvas = overlay.GetOverlay().Children.OfType<Canvas>().FirstOrDefault();
		canvas?.Children.RemoveRange(0, canvas.Children.Count);
		Rect activePaneBounds = overlay.GetActivePaneBounds();
		if (activePaneBounds != Rect.Empty && canvas != null)
		{
			canvas.Clip = new RectangleGeometry(activePaneBounds);
		}
		foreach (KeyValuePair<string, IOverlayLocationInfo> item in overlay.GetBlocksLocationInfo(colors.Keys.ToList()))
		{
			if (colors.ContainsKey(item.Key))
			{
				SolidColorBrush solidColorBrush = new SolidColorBrush();
				IOverlayLocationInfo value = item.Value;
				solidColorBrush.Color = colors[item.Key];
				double num = Math.Sqrt(value.Rect.Width * value.Rect.Width + value.Rect.Height * value.Rect.Height);
				double top = value.Rect.Top - (num - value.Rect.Height) / 2.0;
				double left = value.Rect.Left - (num - value.Rect.Width) / 2.0;
				if (canvas != null)
				{
					AnnotationCircle annotationCircle = new AnnotationCircle(canvas, top, left, solidColorBrush, glow, item.Key, flyover, currentCollection, num, isSolid);
					annotationCircle.MouseHover += MouseHover;
					canvas.Children.Add(annotationCircle.Draw());
				}
			}
		}
	}

	public void RemoveHighlight(string name)
	{
		Canvas canvas = _overlayManager.GetOverlay(name).GetOverlay().Children.OfType<Canvas>().FirstOrDefault();
		canvas?.Children.RemoveRange(0, canvas.Children.Count);
	}

	private void MouseHover(object sender, bool isHoverIn)
	{
		AnnotationCircle annotationCircle = sender as AnnotationCircle;
		_ = annotationCircle.Parent;
		if (isHoverIn && annotationCircle.HoverBox != null)
		{
			(annotationCircle.HoverBox as Popup).IsOpen = true;
		}
		else if (annotationCircle.HoverBox != null && !annotationCircle.HoverBox.IsMouseOver)
		{
			(annotationCircle.HoverBox as Popup).IsOpen = false;
		}
	}

	public void AddLegends()
	{
		_overlayManager = _container.Resolve<IFlowsheetOverlayManager>(Array.Empty<ResolverOverride>());
		if (_overlayManager == null)
		{
			return;
		}
		foreach (string name in _overlayManager.Names)
		{
			Legend(name, isSelected: false);
		}
	}

	public void Legend(string overlayName, bool isSelected)
	{
		IFlowsheetOverlay overlay = _overlayManager.GetOverlay(overlayName);
		if (overlay != null)
		{
			Canvas overlay2 = overlay.GetOverlay();
			Image image = overlay2.Children.OfType<Image>().FirstOrDefault();
			if (image != null)
			{
				overlay2.Children.Remove(image);
			}
			Image image2 = new Image();
			if (isSelected)
			{
				image2.Source = GetImageSource("legend_activation_selected.png");
			}
			else
			{
				image2.Source = GetImageSource("legend_activation_unselected.png");
			}
			if (_savedLegendPos.X != 0.0 && _savedLegendPos.Y != 0.0)
			{
				Canvas.SetTop(image2, _savedLegendPos.Y);
				Canvas.SetLeft(image2, _savedLegendPos.X);
			}
			else
			{
				Canvas.SetTop(image2, 10.0);
				Canvas.SetLeft(image2, overlay.GetFlowsheetDesiredSize().Width - 210.0);
			}
			image2.MouseEnter += Legend_MouseEnter;
			image2.MouseLeave += Legend_MouseLeave;
			overlay2.Children.Add(image2);
			overlay2.AllowDrop = true;
			overlay2.PreviewMouseLeftButtonDown += canvas_PreviewMouseLeftButtonDown;
			overlay2.PreviewMouseMove += canvas_PreviewMouseMove;
			overlay2.PreviewMouseLeftButtonUp += canvas_PreviewMouseLeftButtonUp;
		}
	}

	private void canvas_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
	{
		if (_isDown)
		{
			DragFinished(cancelled: false);
			e.Handled = true;
		}
	}

	private void DragFinished(bool cancelled)
	{
		Mouse.Capture(null);
		if (_isDragging)
		{
			AdornerLayer.GetAdornerLayer(_overlayElement.AdornedElement)?.Remove(_overlayElement);
			if (!cancelled)
			{
				Canvas.SetTop(draggedImage, _originalTop + _overlayElement.TopOffset);
				Canvas.SetLeft(draggedImage, _originalLeft + _overlayElement.LeftOffset);
				_savedLegendPos = new Point(Canvas.GetLeft(draggedImage), Canvas.GetTop(draggedImage));
			}
			draggedImage = null;
		}
		_isDragging = false;
		_isDown = false;
	}

	private void canvas_PreviewMouseMove(object sender, System.Windows.Input.MouseEventArgs e)
	{
		if (_isDown)
		{
			if (!_isDragging && (Math.Abs(e.GetPosition(_canvas).X - _startPoint.X) > SystemParameters.MinimumHorizontalDragDistance || Math.Abs(e.GetPosition(_canvas).Y - _startPoint.Y) > SystemParameters.MinimumVerticalDragDistance))
			{
				DragStarted();
			}
			if (_isDragging)
			{
				DragMoved();
			}
		}
	}

	private void DragMoved()
	{
		Point position = Mouse.GetPosition(_canvas);
		_overlayElement.LeftOffset = position.X - _startPoint.X;
		_overlayElement.TopOffset = position.Y - _startPoint.Y;
	}

	private void DragStarted()
	{
		_isDragging = true;
		_originalLeft = Canvas.GetLeft(draggedImage);
		_originalTop = Canvas.GetTop(draggedImage);
		_overlayElement = new SimpleCircleAdorner(draggedImage);
		AdornerLayer.GetAdornerLayer(draggedImage)?.Add(_overlayElement);
	}

	private void canvas_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
	{
		if (e.Source is Image image)
		{
			_isDown = true;
			_canvas = image.Parent as Canvas;
			_startPoint = e.GetPosition(_canvas);
			draggedImage = image;
			_canvas.CaptureMouse();
			e.Handled = true;
		}
	}

	private void Legend_MouseLeave(object sender, System.Windows.Input.MouseEventArgs e)
	{
		if (sender is Image image)
		{
			image.Source = GetImageSource("legend_activation_unselected.png");
		}
	}

	private void Legend_MouseEnter(object sender, System.Windows.Input.MouseEventArgs e)
	{
		if (sender is Image image)
		{
			image.Source = GetImageSource("legend_activation_selected.png");
		}
	}

	public void ClearLegends()
	{
		_overlayManager = _container.Resolve<IFlowsheetOverlayManager>(Array.Empty<ResolverOverride>());
		if (_overlayManager == null)
		{
			return;
		}
		foreach (string name in _overlayManager.Names)
		{
			IFlowsheetOverlay overlay = _overlayManager.GetOverlay(name);
			if (overlay == null)
			{
				break;
			}
			Canvas overlay2 = overlay.GetOverlay();
			Image image = overlay2.Children.OfType<Image>().FirstOrDefault();
			if (image != null)
			{
				overlay2.Children.Remove(image);
				_savedLegendPos.X = 0.0;
				_savedLegendPos.Y = 0.0;
			}
		}
	}

	private static ImageSource GetImageSource(string imageFileName)
	{
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.Append("pack://application:,,,/");
		stringBuilder.Append(typeof(PFDHighlightProvider).Assembly.FullName);
		stringBuilder.Append(";component/Images/");
		stringBuilder.Append(imageFileName);
		return new BitmapImage(new Uri(stringBuilder.ToString(), UriKind.RelativeOrAbsolute));
	}
}
public class SimpleCircleAdorner : Adorner
{
	private Rectangle _child;

	private double _leftOffset;

	private double _topOffset;

	protected override int VisualChildrenCount => 1;

	public double LeftOffset
	{
		get
		{
			return _leftOffset;
		}
		set
		{
			_leftOffset = value;
			UpdatePosition();
		}
	}

	public double TopOffset
	{
		get
		{
			return _topOffset;
		}
		set
		{
			_topOffset = value;
			UpdatePosition();
		}
	}

	public SimpleCircleAdorner(UIElement adornedElement)
		: base(adornedElement)
	{
		VisualBrush visualBrush = new VisualBrush(adornedElement);
		_child = new Rectangle();
		_child.Width = adornedElement.RenderSize.Width;
		_child.Height = adornedElement.RenderSize.Height;
		DoubleAnimation animation = new DoubleAnimation(0.3, 1.0, new Duration(TimeSpan.FromSeconds(1.0)))
		{
			AutoReverse = true,
			RepeatBehavior = RepeatBehavior.Forever
		};
		visualBrush.BeginAnimation(Brush.OpacityProperty, animation);
		_child.Fill = visualBrush;
	}

	protected override void OnRender(DrawingContext drawingContext)
	{
		Rect rectangle = new Rect(base.AdornedElement.DesiredSize);
		SolidColorBrush solidColorBrush = new SolidColorBrush(Colors.Green);
		solidColorBrush.Opacity = 0.2;
		Pen pen = new Pen(new SolidColorBrush(Colors.Navy), 1.5);
		double num = 5.0;
		drawingContext.DrawRectangle(solidColorBrush, pen, rectangle);
		drawingContext.DrawEllipse(solidColorBrush, pen, rectangle.TopLeft, num, num);
		drawingContext.DrawEllipse(solidColorBrush, pen, rectangle.TopRight, num, num);
		drawingContext.DrawEllipse(solidColorBrush, pen, rectangle.BottomLeft, num, num);
		drawingContext.DrawEllipse(solidColorBrush, pen, rectangle.BottomRight, num, num);
	}

	protected override Size MeasureOverride(Size constraint)
	{
		_child.Measure(constraint);
		return _child.DesiredSize;
	}

	protected override Size ArrangeOverride(Size finalSize)
	{
		_child.Arrange(new Rect(finalSize));
		return finalSize;
	}

	protected override Visual GetVisualChild(int index)
	{
		return _child;
	}

	private void UpdatePosition()
	{
		if (base.Parent is AdornerLayer adornerLayer)
		{
			adornerLayer.Update(base.AdornedElement);
		}
	}

	public override GeneralTransform GetDesiredTransform(GeneralTransform transform)
	{
		return new GeneralTransformGroup
		{
			Children = 
			{
				base.GetDesiredTransform(transform),
				(GeneralTransform)new TranslateTransform(_leftOffset, _topOffset)
			}
		};
	}
}

// Coverage appendix for compiler-folded declarations and MethodDef implementations.
// The active C# above contains the reconstructed high-level forms. The comments below retain
// metadata names and show the expansions of methods that lack a direct declaration or sequence point in those forms.

// 0x06000001 AspenTech.Engineering.FlowsheetOverlay.OverlayActivationDeactivationEvent..ctor
// public OverlayActivationDeactivationEvent()
// {
// }

// 0x0600000b AspenTech.Engineering.FlowsheetOverlay.AnnotationCircle.add_MouseHover
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	Hover hover = this.MouseHover;
// 	Hover hover2;
// 	do
// 	{
// 		hover2 = hover;
// 		Hover value2 = (Hover)Delegate.Combine(hover2, value);
// 		hover = Interlocked.CompareExchange(ref this.MouseHover, value2, hover2);
// 	}
// 	while ((object)hover != hover2);
// }

// 0x0600000c AspenTech.Engineering.FlowsheetOverlay.AnnotationCircle.remove_MouseHover
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	Hover hover = this.MouseHover;
// 	Hover hover2;
// 	do
// 	{
// 		hover2 = hover;
// 		Hover value2 = (Hover)Delegate.Remove(hover2, value);
// 		hover = Interlocked.CompareExchange(ref this.MouseHover, value2, hover2);
// 	}
// 	while ((object)hover != hover2);
// }

// 0x06000031 AspenTech.Engineering.FlowsheetOverlay.FlowSheetTransparentOverlay..cctor
// using System;
// using System.Windows;
//
// static FlowSheetTransparentOverlay()
// {
// 	ParentWindowProperty = DependencyProperty.RegisterAttached("ParentWindow", typeof(Window), typeof(FlowSheetTransparentOverlay), new UIPropertyMetadata(null, ParentWindowPropertyChanged));
// 	HWND_TOPMOST = new IntPtr(-1);
// 	HWND_NOTOPMOST = new IntPtr(-2);
// 	HWND_TOP = new IntPtr(0);
// 	HWND_BOTTOM = new IntPtr(1);
// }

// 0x06000045 AspenTech.Engineering.FlowsheetOverlay.OverlayRefreshEvent..ctor
// public OverlayRefreshEvent()
// {
// }

// 0x06000049 AspenTech.Engineering.FlowsheetOverlay.OverlayAddedEvent..ctor
// public OverlayAddedEvent()
// {
// }
