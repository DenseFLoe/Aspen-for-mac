using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;
using AspenTech.AspenCxs;
using AspenTech.AspenCxs.CxsViewModel;
using AspenTech.AspenPlus.AddInContracts;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.AspenPlus.Infrastructure.Events;
using AspenTech.AspenPlus.Infrastructure.MvvmCore;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.MMControls;
using AspenTech.AspenPlus.MMControls.Dialogs;
using AspenTech.AspenPlus.Printing;
using AspenTech.AspenPlus.UnmanagedWrapper;
using AspenTech.Visualisation.CommonImages;
using AspenTech.Visualisation.CommonShell;
using Infragistics.Windows;
using Microsoft.Practices.Composite.Events;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Composite.Presentation.Commands;
using Microsoft.Practices.Composite.UnityExtensions;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.PfsDialogs")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.PfsDialogs")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, INC. 2010 - 2024, All rights reserved")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("2b832701-0e4d-449b-9633-3a25994d8910")]
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
namespace AspenTech.AspenPlus.PfsDialogs
{
	public class PFSColorStyleDialog : Window, IComponentConnector
	{
		private bool bStream;

		private bool bCanFill;

		private int iDefaultColor;

		private int iDefaultWidth;

		private int iDefaultStyle;

		internal StackPanel stackPanel0;

		internal StackPanel LineColorStackPanel;

		internal Label OutlineColorLabel;

		internal Rectangle LineColor0a;

		internal Rectangle LineColor1a;

		internal Rectangle LineColor2a;

		internal Rectangle LineColor3a;

		internal Rectangle LineColor4a;

		internal Rectangle LineColor5a;

		internal Rectangle LineColor6a;

		internal Rectangle LineColor7a;

		internal Rectangle LineColor8a;

		internal Rectangle LineColor9a;

		internal Rectangle LineColor10a;

		internal Rectangle LineColor11a;

		internal Rectangle LineColor12a;

		internal Rectangle LineColor13a;

		internal Rectangle LineColor14a;

		internal Rectangle LineColor15a;

		internal Rectangle LineColor0;

		internal Rectangle LineColor1;

		internal Rectangle LineColor2;

		internal Rectangle LineColor3;

		internal Rectangle LineColor4;

		internal Rectangle LineColor5;

		internal Rectangle LineColor6;

		internal Rectangle LineColor7;

		internal Rectangle LineColor8;

		internal Rectangle LineColor9;

		internal Rectangle LineColor10;

		internal Rectangle LineColor11;

		internal Rectangle LineColor12;

		internal Rectangle LineColor13;

		internal Rectangle LineColor14;

		internal Rectangle LineColor15;

		internal StackPanel FillColorStackPanel;

		internal Label FillColorLabel;

		internal Rectangle FillColor0a;

		internal Rectangle FillColor1a;

		internal Rectangle FillColor2a;

		internal Rectangle FillColor3a;

		internal Rectangle FillColor4a;

		internal Rectangle FillColor5a;

		internal Rectangle FillColor6a;

		internal Rectangle FillColor7a;

		internal Rectangle FillColor8a;

		internal Rectangle FillColor9a;

		internal Rectangle FillColor10a;

		internal Rectangle FillColor11a;

		internal Rectangle FillColor12a;

		internal Rectangle FillColor13a;

		internal Rectangle FillColor14a;

		internal Rectangle FillColor15a;

		internal Rectangle FillColor0;

		internal Rectangle FillColor1;

		internal Rectangle FillColor2;

		internal Rectangle FillColor3;

		internal Rectangle FillColor4;

		internal Rectangle FillColor5;

		internal Rectangle FillColor6;

		internal Rectangle FillColor7;

		internal Rectangle FillColor8;

		internal Rectangle FillColor9;

		internal Rectangle FillColor10;

		internal Rectangle FillColor11;

		internal Rectangle FillColor12;

		internal Rectangle FillColor13;

		internal Rectangle FillColor14;

		internal Rectangle FillColor15;

		internal Separator separator1;

		internal StackPanel LineWeightStyleStackPanel;

		internal StackPanel LineWeightStackPanel;

		internal Label LineWeightLabel;

		internal Rectangle LineWidth0a;

		internal Rectangle LineWidth1a;

		internal Rectangle LineWidth2a;

		internal Rectangle LineWidth3a;

		internal Rectangle LineWidth4a;

		internal Line LineWidth0b;

		internal Line LineWidth1b;

		internal Line LineWidth2b;

		internal Line LineWidth3b;

		internal Line LineWidth4b;

		internal Rectangle LineWidth0;

		internal Rectangle LineWidth1;

		internal Rectangle LineWidth2;

		internal Rectangle LineWidth3;

		internal Rectangle LineWidth4;

		internal StackPanel LineStyleStackPanel;

		internal Label LineStyleLabel;

		internal Rectangle LineStyle0a;

		internal Rectangle LineStyle1a;

		internal Rectangle LineStyle2a;

		internal Rectangle LineStyle3a;

		internal Rectangle LineStyle4a;

		internal Line LineStyle0b;

		internal Line LineStyle1b;

		internal Line LineStyle2b;

		internal Line LineStyle3b;

		internal Line LineStyle4b;

		internal Rectangle LineStyle0;

		internal Rectangle LineStyle1;

		internal Rectangle LineStyle2;

		internal Rectangle LineStyle3;

		internal Rectangle LineStyle4;

		internal StackPanel StreamOptionsStackPanel;

		internal Separator separator2;

		internal StackPanel PreviewsStackPanel;

		internal Label label3;

		internal Rectangle PreviewBox;

		internal Line StreamLine1;

		internal Line StreamLine2;

		internal Polyline StreamLabelBox;

		internal Label StreamLabel;

		internal CheckBox UseDefaultCheckBox;

		internal StackPanel AnnotationOptionsStackPanel;

		internal Separator separator3;

		internal StackPanel DecoratorStackPanel;

		internal CheckBox NoOutlineCheckBox;

		internal CheckBox NoFillCheckBox;

		internal Button btnOK;

		internal Button btnCancel;

		private bool _contentLoaded;

		public bool UseDefault { get; set; }

		public bool? NoOutline { get; set; }

		public bool? NoFill { get; set; }

		public int CurrentLineColor { get; set; }

		public int CurrentFillColor { get; set; }

		public int CurrentWidth { get; set; }

		public int CurrentStyle { get; set; }

		public PFSColorStyleDialog(bool bStream, bool bUsingDefault, int iDefaultColorOrHasOutline, int iDefaultWidthOrIsFilled, int iDefaultStyle, bool bCanFill, int iCurrentLineColor, int iCurrentFillColor, int iCurrentWidth, int iCurrentStyle)
		{
			this.bStream = bStream;
			UseDefault = bStream && bUsingDefault;
			this.bCanFill = !bStream && bCanFill;
			if (bStream)
			{
				iDefaultColor = iDefaultColorOrHasOutline;
				iDefaultWidth = iDefaultWidthOrIsFilled - 1;
				this.iDefaultStyle = iDefaultStyle;
			}
			else
			{
				if (iDefaultColorOrHasOutline < 0)
				{
					NoOutline = null;
				}
				else
				{
					NoOutline = iDefaultColorOrHasOutline == 0;
				}
				if (iDefaultWidthOrIsFilled < 0)
				{
					NoFill = null;
				}
				else
				{
					NoFill = iDefaultWidthOrIsFilled == 0;
				}
			}
			if (bStream || !bCanFill)
			{
				NoFill = true;
				NoOutline = false;
			}
			CurrentLineColor = iCurrentLineColor;
			CurrentFillColor = iCurrentFillColor;
			CurrentWidth = iCurrentWidth - 1;
			CurrentStyle = iCurrentStyle;
			InitializeComponent();
			UseDefaultCheckBox.IsChecked = UseDefault;
			if (!NoOutline.HasValue)
			{
				NoOutlineCheckBox.IsThreeState = true;
			}
			NoOutlineCheckBox.IsChecked = NoOutline;
			if (!NoFill.HasValue)
			{
				NoFillCheckBox.IsThreeState = true;
			}
			NoFillCheckBox.IsChecked = NoFill;
			NoOutlineCheckBox.IsEnabled = NoFill != true;
			NoFillCheckBox.IsEnabled = NoOutline != true;
			if (CurrentLineColor >= 0)
			{
				HighlightLineColor(CurrentLineColor);
			}
			if (CurrentFillColor >= 0)
			{
				HighlightFillColor(CurrentFillColor);
			}
			if (CurrentWidth >= 0)
			{
				HighlightWidth(CurrentWidth);
			}
			if (CurrentStyle >= 0)
			{
				HighlightStyle(CurrentStyle);
			}
			if (bStream)
			{
				UpdatePreview();
			}
			if (bStream || !bCanFill)
			{
				AnnotationOptionsStackPanel.Visibility = Visibility.Collapsed;
			}
			if (!bStream)
			{
				StreamOptionsStackPanel.Visibility = Visibility.Collapsed;
			}
			if (bStream || !bCanFill)
			{
				FillColorStackPanel.Visibility = Visibility.Collapsed;
			}
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void OnClickCancel(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void OnClickNoOutline(object sender, RoutedEventArgs e)
		{
			NoOutline = NoOutlineCheckBox.IsChecked;
			if (NoOutline == true)
			{
				if (CurrentLineColor >= 0)
				{
					UnHighlightLineColor(CurrentLineColor);
					CurrentLineColor = -1;
				}
			}
			else
			{
				CurrentLineColor = CurrentFillColor;
				if (CurrentLineColor >= 0)
				{
					HighlightLineColor(CurrentLineColor);
				}
			}
			NoFillCheckBox.IsEnabled = NoOutline != true;
		}

		private void OnClickNoFill(object sender, RoutedEventArgs e)
		{
			NoFill = NoFillCheckBox.IsChecked;
			if (NoFill == true)
			{
				if (CurrentFillColor >= 0)
				{
					UnHighlightFillColor(CurrentFillColor);
					CurrentFillColor = -1;
				}
			}
			else
			{
				CurrentFillColor = CurrentLineColor;
				if (CurrentFillColor >= 0)
				{
					HighlightFillColor(CurrentFillColor);
				}
			}
			NoOutlineCheckBox.IsEnabled = NoFill != true;
		}

		private void OnClickUseDefault(object sender, RoutedEventArgs e)
		{
			UseDefault = UseDefaultCheckBox.IsChecked.Value;
			if (UseDefault)
			{
				if (CurrentLineColor != iDefaultColor)
				{
					UnHighlightLineColor(CurrentLineColor);
					HighlightLineColor(iDefaultColor);
					CurrentLineColor = iDefaultColor;
				}
				if (CurrentWidth != iDefaultWidth)
				{
					UnHighlightWidth(CurrentWidth);
					HighlightWidth(iDefaultWidth);
					CurrentWidth = iDefaultWidth;
				}
				if (CurrentStyle != iDefaultStyle)
				{
					UnHighlightStyle(CurrentStyle);
					HighlightStyle(iDefaultStyle);
					CurrentStyle = iDefaultStyle;
				}
				UpdatePreview();
			}
		}

		private void HighlightLineColor(int iColor)
		{
			if (iColor >= 0)
			{
				string name = "LineColor" + iColor;
				Rectangle r = (Rectangle)FindName(name);
				HighlightRectangle(r);
			}
		}

		private void UnHighlightLineColor(int iColor)
		{
			if (iColor >= 0)
			{
				string name = "LineColor" + iColor;
				Rectangle r = (Rectangle)FindName(name);
				UnHighlightRectangle(r);
			}
		}

		private void HighlightFillColor(int iColor)
		{
			if (iColor >= 0)
			{
				string name = "FillColor" + iColor;
				Rectangle r = (Rectangle)FindName(name);
				HighlightRectangle(r);
			}
		}

		private void UnHighlightFillColor(int iColor)
		{
			if (iColor >= 0)
			{
				string name = "FillColor" + iColor;
				Rectangle r = (Rectangle)FindName(name);
				UnHighlightRectangle(r);
			}
		}

		private void HighlightWidth(int iWidth)
		{
			if (iWidth >= 0)
			{
				string name = "LineWidth" + iWidth;
				Rectangle r = (Rectangle)FindName(name);
				HighlightRectangle(r);
			}
		}

		private void UnHighlightWidth(int iWidth)
		{
			if (iWidth >= 0)
			{
				string name = "LineWidth" + iWidth;
				Rectangle r = (Rectangle)FindName(name);
				UnHighlightRectangle(r);
			}
		}

		private void HighlightStyle(int iStyle)
		{
			if (iStyle >= 0)
			{
				string name = "LineStyle" + iStyle;
				Rectangle r = (Rectangle)FindName(name);
				HighlightRectangle(r);
			}
		}

		private void UnHighlightStyle(int iStyle)
		{
			if (iStyle >= 0)
			{
				string name = "LineStyle" + iStyle;
				Rectangle r = (Rectangle)FindName(name);
				UnHighlightRectangle(r);
			}
		}

		private void HighlightRectangle(Rectangle r)
		{
			Rectangle obj = (Rectangle)FindName(r.Name + "a");
			r.Stroke = Brushes.White;
			obj.Stroke = Brushes.Red;
		}

		private void UnHighlightRectangle(Rectangle r)
		{
			Rectangle obj = (Rectangle)FindName(r.Name + "a");
			r.Stroke = Brushes.Black;
			obj.Stroke = Brushes.White;
		}

		private void OnMouseEnterLineColor(object sender, MouseEventArgs e)
		{
			HighlightRectangle((Rectangle)e.Source);
		}

		private void OnMouseLeaveLineColor(object sender, MouseEventArgs e)
		{
			Rectangle r = (Rectangle)e.Source;
			if (GetLineColorIndex(r) != CurrentLineColor)
			{
				UnHighlightRectangle(r);
			}
		}

		private void OnMouseLeftClickLineColor(object sender, MouseButtonEventArgs e)
		{
			int lineColorIndex = GetLineColorIndex((Rectangle)e.Source);
			if (lineColorIndex != CurrentLineColor && CurrentLineColor >= 0)
			{
				UnHighlightLineColor(CurrentLineColor);
			}
			CurrentLineColor = lineColorIndex;
			if (!bStream && NoOutline == true)
			{
				NoOutline = false;
				NoOutlineCheckBox.IsChecked = false;
			}
			if (bStream && UseDefault && CurrentLineColor != iDefaultColor)
			{
				UseDefault = false;
				UseDefaultCheckBox.IsChecked = false;
			}
			UpdatePreview();
		}

		private void OnMouseEnterFillColor(object sender, MouseEventArgs e)
		{
			HighlightRectangle((Rectangle)e.Source);
		}

		private void OnMouseLeaveFillColor(object sender, MouseEventArgs e)
		{
			Rectangle r = (Rectangle)e.Source;
			if (GetFillColorIndex(r) != CurrentFillColor)
			{
				UnHighlightRectangle(r);
			}
		}

		private void OnMouseLeftClickFillColor(object sender, MouseButtonEventArgs e)
		{
			int fillColorIndex = GetFillColorIndex((Rectangle)e.Source);
			if (fillColorIndex != CurrentFillColor && CurrentFillColor >= 0)
			{
				UnHighlightFillColor(CurrentFillColor);
			}
			CurrentFillColor = fillColorIndex;
			if (!bStream && NoFill == true)
			{
				NoFill = false;
				NoFillCheckBox.IsChecked = false;
			}
			UpdatePreview();
		}

		private void OnMouseEnterWidth(object sender, MouseEventArgs e)
		{
			HighlightRectangle((Rectangle)e.Source);
		}

		private void OnMouseLeaveWidth(object sender, MouseEventArgs e)
		{
			Rectangle r = (Rectangle)e.Source;
			if (GetWidthIndex(r) != CurrentWidth)
			{
				UnHighlightRectangle(r);
			}
		}

		private void OnMouseLeftClickWidth(object sender, MouseButtonEventArgs e)
		{
			int widthIndex = GetWidthIndex((Rectangle)e.Source);
			if (widthIndex != CurrentWidth && CurrentWidth >= 0)
			{
				UnHighlightWidth(CurrentWidth);
			}
			CurrentWidth = widthIndex;
			if (CurrentWidth != iDefaultWidth && UseDefault)
			{
				UseDefault = false;
				UseDefaultCheckBox.IsChecked = false;
			}
			UpdatePreview();
		}

		private void OnMouseEnterStyle(object sender, MouseEventArgs e)
		{
			HighlightRectangle((Rectangle)e.Source);
		}

		private void OnMouseLeaveStyle(object sender, MouseEventArgs e)
		{
			Rectangle r = (Rectangle)e.Source;
			if (GetStyleIndex(r) != CurrentStyle)
			{
				UnHighlightRectangle(r);
			}
		}

		private void OnMouseLeftClickStyle(object sender, MouseButtonEventArgs e)
		{
			int styleIndex = GetStyleIndex((Rectangle)e.Source);
			if (styleIndex != CurrentStyle && CurrentStyle >= 0)
			{
				UnHighlightStyle(CurrentStyle);
			}
			CurrentStyle = styleIndex;
			if (CurrentStyle != iDefaultStyle && UseDefault)
			{
				UseDefault = false;
				UseDefaultCheckBox.IsChecked = false;
			}
			UpdatePreview();
		}

		private int GetLineColorIndex(Rectangle r)
		{
			int result = -1;
			string text = "LineColor";
			if (r.Name.StartsWith(text))
			{
				try
				{
					result = Convert.ToInt32(r.Name.Substring(text.Length));
				}
				catch
				{
				}
			}
			return result;
		}

		private int GetFillColorIndex(Rectangle r)
		{
			int result = -1;
			string text = "FillColor";
			if (r.Name.StartsWith(text))
			{
				try
				{
					result = Convert.ToInt32(r.Name.Substring(text.Length));
				}
				catch
				{
				}
			}
			return result;
		}

		private int GetWidthIndex(Rectangle r)
		{
			int result = -1;
			string text = "LineWidth";
			if (r.Name.StartsWith(text))
			{
				try
				{
					result = Convert.ToInt32(r.Name.Substring(text.Length));
				}
				catch
				{
				}
			}
			return result;
		}

		private int GetStyleIndex(Rectangle r)
		{
			int result = -1;
			string text = "LineStyle";
			if (r.Name.StartsWith(text))
			{
				try
				{
					result = Convert.ToInt32(r.Name.Substring(text.Length));
				}
				catch
				{
				}
			}
			return result;
		}

		private void UpdatePreview()
		{
			if (bStream)
			{
				Brush brush;
				if (CurrentLineColor >= 0)
				{
					string name = "LineColor" + CurrentLineColor;
					brush = ((Rectangle)FindName(name)).Fill;
				}
				else
				{
					brush = Brushes.White;
				}
				StreamLine1.Stroke = brush;
				StreamLine2.Stroke = brush;
				StreamLabelBox.Stroke = brush;
				StreamLabel.Foreground = brush;
				int num = CurrentWidth + 1;
				StreamLine1.StrokeThickness = num;
				StreamLine2.StrokeThickness = num;
				StreamLabelBox.StrokeThickness = 1.0;
				DoubleCollection doubleCollection = new DoubleCollection();
				double num2 = 5.0 / (double)num;
				if (CurrentStyle == 2)
				{
					doubleCollection.Add(num2);
					doubleCollection.Add(num2);
				}
				else
				{
					doubleCollection.Add(num2 * 3.0);
					doubleCollection.Add(num2);
				}
				if (CurrentStyle >= 3)
				{
					doubleCollection.Add(num2);
					doubleCollection.Add(num2);
				}
				if (CurrentStyle == 4)
				{
					doubleCollection.Add(num2);
					doubleCollection.Add(num2);
				}
				if (CurrentStyle > 0)
				{
					StreamLine1.StrokeDashArray = doubleCollection;
					StreamLine2.StrokeDashArray = doubleCollection;
				}
				else
				{
					StreamLine1.StrokeDashArray = null;
					StreamLine2.StrokeDashArray = null;
				}
			}
		}

		public void ForTextColorSetting()
		{
			base.Title = "Color";
			OutlineColorLabel.Content = "Text Color";
			FillColorStackPanel.Visibility = Visibility.Collapsed;
			LineWeightStyleStackPanel.Visibility = Visibility.Collapsed;
			PreviewsStackPanel.Visibility = Visibility.Collapsed;
			DecoratorStackPanel.Visibility = Visibility.Collapsed;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfscolorstyledialog.xaml", UriKind.Relative);
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
				stackPanel0 = (StackPanel)target;
				break;
			case 2:
				LineColorStackPanel = (StackPanel)target;
				break;
			case 3:
				OutlineColorLabel = (Label)target;
				break;
			case 4:
				LineColor0a = (Rectangle)target;
				break;
			case 5:
				LineColor1a = (Rectangle)target;
				break;
			case 6:
				LineColor2a = (Rectangle)target;
				break;
			case 7:
				LineColor3a = (Rectangle)target;
				break;
			case 8:
				LineColor4a = (Rectangle)target;
				break;
			case 9:
				LineColor5a = (Rectangle)target;
				break;
			case 10:
				LineColor6a = (Rectangle)target;
				break;
			case 11:
				LineColor7a = (Rectangle)target;
				break;
			case 12:
				LineColor8a = (Rectangle)target;
				break;
			case 13:
				LineColor9a = (Rectangle)target;
				break;
			case 14:
				LineColor10a = (Rectangle)target;
				break;
			case 15:
				LineColor11a = (Rectangle)target;
				break;
			case 16:
				LineColor12a = (Rectangle)target;
				break;
			case 17:
				LineColor13a = (Rectangle)target;
				break;
			case 18:
				LineColor14a = (Rectangle)target;
				break;
			case 19:
				LineColor15a = (Rectangle)target;
				break;
			case 20:
				LineColor0 = (Rectangle)target;
				LineColor0.MouseEnter += OnMouseEnterLineColor;
				LineColor0.MouseLeave += OnMouseLeaveLineColor;
				LineColor0.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 21:
				LineColor1 = (Rectangle)target;
				LineColor1.MouseEnter += OnMouseEnterLineColor;
				LineColor1.MouseLeave += OnMouseLeaveLineColor;
				LineColor1.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 22:
				LineColor2 = (Rectangle)target;
				LineColor2.MouseEnter += OnMouseEnterLineColor;
				LineColor2.MouseLeave += OnMouseLeaveLineColor;
				LineColor2.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 23:
				LineColor3 = (Rectangle)target;
				LineColor3.MouseEnter += OnMouseEnterLineColor;
				LineColor3.MouseLeave += OnMouseLeaveLineColor;
				LineColor3.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 24:
				LineColor4 = (Rectangle)target;
				LineColor4.MouseEnter += OnMouseEnterLineColor;
				LineColor4.MouseLeave += OnMouseLeaveLineColor;
				LineColor4.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 25:
				LineColor5 = (Rectangle)target;
				LineColor5.MouseEnter += OnMouseEnterLineColor;
				LineColor5.MouseLeave += OnMouseLeaveLineColor;
				LineColor5.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 26:
				LineColor6 = (Rectangle)target;
				LineColor6.MouseEnter += OnMouseEnterLineColor;
				LineColor6.MouseLeave += OnMouseLeaveLineColor;
				LineColor6.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 27:
				LineColor7 = (Rectangle)target;
				LineColor7.MouseEnter += OnMouseEnterLineColor;
				LineColor7.MouseLeave += OnMouseLeaveLineColor;
				LineColor7.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 28:
				LineColor8 = (Rectangle)target;
				LineColor8.MouseEnter += OnMouseEnterLineColor;
				LineColor8.MouseLeave += OnMouseLeaveLineColor;
				LineColor8.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 29:
				LineColor9 = (Rectangle)target;
				LineColor9.MouseEnter += OnMouseEnterLineColor;
				LineColor9.MouseLeave += OnMouseLeaveLineColor;
				LineColor9.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 30:
				LineColor10 = (Rectangle)target;
				LineColor10.MouseEnter += OnMouseEnterLineColor;
				LineColor10.MouseLeave += OnMouseLeaveLineColor;
				LineColor10.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 31:
				LineColor11 = (Rectangle)target;
				LineColor11.MouseEnter += OnMouseEnterLineColor;
				LineColor11.MouseLeave += OnMouseLeaveLineColor;
				LineColor11.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 32:
				LineColor12 = (Rectangle)target;
				LineColor12.MouseEnter += OnMouseEnterLineColor;
				LineColor12.MouseLeave += OnMouseLeaveLineColor;
				LineColor12.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 33:
				LineColor13 = (Rectangle)target;
				LineColor13.MouseEnter += OnMouseEnterLineColor;
				LineColor13.MouseLeave += OnMouseLeaveLineColor;
				LineColor13.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 34:
				LineColor14 = (Rectangle)target;
				LineColor14.MouseEnter += OnMouseEnterLineColor;
				LineColor14.MouseLeave += OnMouseLeaveLineColor;
				LineColor14.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 35:
				LineColor15 = (Rectangle)target;
				LineColor15.MouseEnter += OnMouseEnterLineColor;
				LineColor15.MouseLeave += OnMouseLeaveLineColor;
				LineColor15.MouseLeftButtonDown += OnMouseLeftClickLineColor;
				break;
			case 36:
				FillColorStackPanel = (StackPanel)target;
				break;
			case 37:
				FillColorLabel = (Label)target;
				break;
			case 38:
				FillColor0a = (Rectangle)target;
				break;
			case 39:
				FillColor1a = (Rectangle)target;
				break;
			case 40:
				FillColor2a = (Rectangle)target;
				break;
			case 41:
				FillColor3a = (Rectangle)target;
				break;
			case 42:
				FillColor4a = (Rectangle)target;
				break;
			case 43:
				FillColor5a = (Rectangle)target;
				break;
			case 44:
				FillColor6a = (Rectangle)target;
				break;
			case 45:
				FillColor7a = (Rectangle)target;
				break;
			case 46:
				FillColor8a = (Rectangle)target;
				break;
			case 47:
				FillColor9a = (Rectangle)target;
				break;
			case 48:
				FillColor10a = (Rectangle)target;
				break;
			case 49:
				FillColor11a = (Rectangle)target;
				break;
			case 50:
				FillColor12a = (Rectangle)target;
				break;
			case 51:
				FillColor13a = (Rectangle)target;
				break;
			case 52:
				FillColor14a = (Rectangle)target;
				break;
			case 53:
				FillColor15a = (Rectangle)target;
				break;
			case 54:
				FillColor0 = (Rectangle)target;
				FillColor0.MouseEnter += OnMouseEnterFillColor;
				FillColor0.MouseLeave += OnMouseLeaveFillColor;
				FillColor0.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 55:
				FillColor1 = (Rectangle)target;
				FillColor1.MouseEnter += OnMouseEnterFillColor;
				FillColor1.MouseLeave += OnMouseLeaveFillColor;
				FillColor1.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 56:
				FillColor2 = (Rectangle)target;
				FillColor2.MouseEnter += OnMouseEnterFillColor;
				FillColor2.MouseLeave += OnMouseLeaveFillColor;
				FillColor2.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 57:
				FillColor3 = (Rectangle)target;
				FillColor3.MouseEnter += OnMouseEnterFillColor;
				FillColor3.MouseLeave += OnMouseLeaveFillColor;
				FillColor3.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 58:
				FillColor4 = (Rectangle)target;
				FillColor4.MouseEnter += OnMouseEnterFillColor;
				FillColor4.MouseLeave += OnMouseLeaveFillColor;
				FillColor4.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 59:
				FillColor5 = (Rectangle)target;
				FillColor5.MouseEnter += OnMouseEnterFillColor;
				FillColor5.MouseLeave += OnMouseLeaveFillColor;
				FillColor5.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 60:
				FillColor6 = (Rectangle)target;
				FillColor6.MouseEnter += OnMouseEnterFillColor;
				FillColor6.MouseLeave += OnMouseLeaveFillColor;
				FillColor6.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 61:
				FillColor7 = (Rectangle)target;
				FillColor7.MouseEnter += OnMouseEnterFillColor;
				FillColor7.MouseLeave += OnMouseLeaveFillColor;
				FillColor7.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 62:
				FillColor8 = (Rectangle)target;
				FillColor8.MouseEnter += OnMouseEnterFillColor;
				FillColor8.MouseLeave += OnMouseLeaveFillColor;
				FillColor8.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 63:
				FillColor9 = (Rectangle)target;
				FillColor9.MouseEnter += OnMouseEnterFillColor;
				FillColor9.MouseLeave += OnMouseLeaveFillColor;
				FillColor9.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 64:
				FillColor10 = (Rectangle)target;
				FillColor10.MouseEnter += OnMouseEnterFillColor;
				FillColor10.MouseLeave += OnMouseLeaveFillColor;
				FillColor10.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 65:
				FillColor11 = (Rectangle)target;
				FillColor11.MouseEnter += OnMouseEnterFillColor;
				FillColor11.MouseLeave += OnMouseLeaveFillColor;
				FillColor11.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 66:
				FillColor12 = (Rectangle)target;
				FillColor12.MouseEnter += OnMouseEnterFillColor;
				FillColor12.MouseLeave += OnMouseLeaveFillColor;
				FillColor12.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 67:
				FillColor13 = (Rectangle)target;
				FillColor13.MouseEnter += OnMouseEnterFillColor;
				FillColor13.MouseLeave += OnMouseLeaveFillColor;
				FillColor13.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 68:
				FillColor14 = (Rectangle)target;
				FillColor14.MouseEnter += OnMouseEnterFillColor;
				FillColor14.MouseLeave += OnMouseLeaveFillColor;
				FillColor14.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 69:
				FillColor15 = (Rectangle)target;
				FillColor15.MouseEnter += OnMouseEnterFillColor;
				FillColor15.MouseLeave += OnMouseLeaveFillColor;
				FillColor15.MouseLeftButtonDown += OnMouseLeftClickFillColor;
				break;
			case 70:
				separator1 = (Separator)target;
				break;
			case 71:
				LineWeightStyleStackPanel = (StackPanel)target;
				break;
			case 72:
				LineWeightStackPanel = (StackPanel)target;
				break;
			case 73:
				LineWeightLabel = (Label)target;
				break;
			case 74:
				LineWidth0a = (Rectangle)target;
				break;
			case 75:
				LineWidth1a = (Rectangle)target;
				break;
			case 76:
				LineWidth2a = (Rectangle)target;
				break;
			case 77:
				LineWidth3a = (Rectangle)target;
				break;
			case 78:
				LineWidth4a = (Rectangle)target;
				break;
			case 79:
				LineWidth0b = (Line)target;
				break;
			case 80:
				LineWidth1b = (Line)target;
				break;
			case 81:
				LineWidth2b = (Line)target;
				break;
			case 82:
				LineWidth3b = (Line)target;
				break;
			case 83:
				LineWidth4b = (Line)target;
				break;
			case 84:
				LineWidth0 = (Rectangle)target;
				LineWidth0.MouseEnter += OnMouseEnterWidth;
				LineWidth0.MouseLeave += OnMouseLeaveWidth;
				LineWidth0.MouseLeftButtonDown += OnMouseLeftClickWidth;
				break;
			case 85:
				LineWidth1 = (Rectangle)target;
				LineWidth1.MouseEnter += OnMouseEnterWidth;
				LineWidth1.MouseLeave += OnMouseLeaveWidth;
				LineWidth1.MouseLeftButtonDown += OnMouseLeftClickWidth;
				break;
			case 86:
				LineWidth2 = (Rectangle)target;
				LineWidth2.MouseEnter += OnMouseEnterWidth;
				LineWidth2.MouseLeave += OnMouseLeaveWidth;
				LineWidth2.MouseLeftButtonDown += OnMouseLeftClickWidth;
				break;
			case 87:
				LineWidth3 = (Rectangle)target;
				LineWidth3.MouseEnter += OnMouseEnterWidth;
				LineWidth3.MouseLeave += OnMouseLeaveWidth;
				LineWidth3.MouseLeftButtonDown += OnMouseLeftClickWidth;
				break;
			case 88:
				LineWidth4 = (Rectangle)target;
				LineWidth4.MouseEnter += OnMouseEnterWidth;
				LineWidth4.MouseLeave += OnMouseLeaveWidth;
				LineWidth4.MouseLeftButtonDown += OnMouseLeftClickWidth;
				break;
			case 89:
				LineStyleStackPanel = (StackPanel)target;
				break;
			case 90:
				LineStyleLabel = (Label)target;
				break;
			case 91:
				LineStyle0a = (Rectangle)target;
				break;
			case 92:
				LineStyle1a = (Rectangle)target;
				break;
			case 93:
				LineStyle2a = (Rectangle)target;
				break;
			case 94:
				LineStyle3a = (Rectangle)target;
				break;
			case 95:
				LineStyle4a = (Rectangle)target;
				break;
			case 96:
				LineStyle0b = (Line)target;
				break;
			case 97:
				LineStyle1b = (Line)target;
				break;
			case 98:
				LineStyle2b = (Line)target;
				break;
			case 99:
				LineStyle3b = (Line)target;
				break;
			case 100:
				LineStyle4b = (Line)target;
				break;
			case 101:
				LineStyle0 = (Rectangle)target;
				LineStyle0.MouseEnter += OnMouseEnterStyle;
				LineStyle0.MouseLeave += OnMouseLeaveStyle;
				LineStyle0.MouseLeftButtonDown += OnMouseLeftClickStyle;
				break;
			case 102:
				LineStyle1 = (Rectangle)target;
				LineStyle1.MouseEnter += OnMouseEnterStyle;
				LineStyle1.MouseLeave += OnMouseLeaveStyle;
				LineStyle1.MouseLeftButtonDown += OnMouseLeftClickStyle;
				break;
			case 103:
				LineStyle2 = (Rectangle)target;
				LineStyle2.MouseEnter += OnMouseEnterStyle;
				LineStyle2.MouseLeave += OnMouseLeaveStyle;
				LineStyle2.MouseLeftButtonDown += OnMouseLeftClickStyle;
				break;
			case 104:
				LineStyle3 = (Rectangle)target;
				LineStyle3.MouseEnter += OnMouseEnterStyle;
				LineStyle3.MouseLeave += OnMouseLeaveStyle;
				LineStyle3.MouseLeftButtonDown += OnMouseLeftClickStyle;
				break;
			case 105:
				LineStyle4 = (Rectangle)target;
				LineStyle4.MouseEnter += OnMouseEnterStyle;
				LineStyle4.MouseLeave += OnMouseLeaveStyle;
				LineStyle4.MouseLeftButtonDown += OnMouseLeftClickStyle;
				break;
			case 106:
				StreamOptionsStackPanel = (StackPanel)target;
				break;
			case 107:
				separator2 = (Separator)target;
				break;
			case 108:
				PreviewsStackPanel = (StackPanel)target;
				break;
			case 109:
				label3 = (Label)target;
				break;
			case 110:
				PreviewBox = (Rectangle)target;
				break;
			case 111:
				StreamLine1 = (Line)target;
				break;
			case 112:
				StreamLine2 = (Line)target;
				break;
			case 113:
				StreamLabelBox = (Polyline)target;
				break;
			case 114:
				StreamLabel = (Label)target;
				break;
			case 115:
				UseDefaultCheckBox = (CheckBox)target;
				UseDefaultCheckBox.Click += OnClickUseDefault;
				break;
			case 116:
				AnnotationOptionsStackPanel = (StackPanel)target;
				break;
			case 117:
				separator3 = (Separator)target;
				break;
			case 118:
				DecoratorStackPanel = (StackPanel)target;
				break;
			case 119:
				NoOutlineCheckBox = (CheckBox)target;
				NoOutlineCheckBox.Click += OnClickNoOutline;
				break;
			case 120:
				NoFillCheckBox = (CheckBox)target;
				NoFillCheckBox.Click += OnClickNoFill;
				break;
			case 121:
				btnOK = (Button)target;
				btnOK.Click += OnClickOk;
				break;
			case 122:
				btnCancel = (Button)target;
				btnCancel.Click += OnClickCancel;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSContextMenu
	{
		private ContextMenuExtender Menu;

		private Stack<MenuItem> SubMenuStack;

		private object pfsObject;

		private string m_strFlowsheetMode = string.Empty;

		private bool m_bInputOrResults;

		private const int IDR_OLEVERB_BEG = 8450;

		private const int IDR_OLEVERB_END = 8499;

		private const int IDR_OLEVERB_MID = 8480;

		private const int VERB_ABE = 19;

		private const int IDR_OLEVERB_ABE = 8469;

		private const int IDR_OLEVERB_ABE_MULTISELECT = 8499;

		private Dictionary<SplitMenuItem, List<int>> m_dicSplitMenuItem = new Dictionary<SplitMenuItem, List<int>>();

		private List<MenuItem> m_lstSplitSubMenuItem = new List<MenuItem>();

		private int m_NodeType = -1;

		private string m_NodePath;

		private string m_BlockType;

		private string m_ObjectNavigatorPath;

		private const int ID_STREAM_RECONNECT_SOURCE = 56049;

		private const int ID_STREAM_RECONNECT_DESTINATION = 56050;

		private const int ID_GROUP_RECONNECT_SOURCE = 56099;

		private const int ID_GROUP_RECONNECT_DESTINATION = 56100;

		private const int ID_STREAM_RESULTS = 8453;

		private const int ID_STREAM_CUSTOM_STREAM_RESULTS = 8458;

		private const int ID_BLOCK_STREAM_RESULTS = 8454;

		private const int ID_BLOCK_CUSTOM_STREAM_RESULTS = 8458;

		private int nCostingCmdId;

		private int nABECmdId;

		private const uint IDS_MENU_OLEVERB_CONVERTTOHEATER = 567u;

		private const uint IDS_MENU_OLEVERB_CONVERTTOHEATX = 568u;

		private const uint IDS_MENU_OLEVERB_COST = 570u;

		private const uint IDS_MENU_OLEVERB_ABE = 591u;

		private const uint IDS_MENU_OLEVERB_EXPAND = 1847u;

		private const uint IDS_MENU_OLEVERB_INPUT = 1848u;

		private const uint IDS_MENU_OLEVERB_RESULTS = 1849u;

		private const uint IDS_MENU_OLEVERB_STREAMRESULTS = 1850u;

		private const uint IDS_MENU_OLEVERB_CUSTOMSTREAMRESULTS = 1851u;

		private const uint IDS_MENU_OLEVERB_MODELS = 1852u;

		private const uint IDS_MENU_OLEVERB_RECONCILE = 1853u;

		private const uint IDS_MENU_OLEVERB_CHANGESECTION = 1854u;

		private const uint IDS_MENU_OLEVERB_ADDTOMODELLIBRARY = 1855u;

		private const uint IDS_MENU_OLEVERB_MOVESELECTION = 1856u;

		private const uint IDS_MENU_OLEVERB_IMPORT = 1857u;

		private const uint IDS_MENU_OLEVERB_EXPORT = 1858u;

		private const uint IDS_MENU_OLEVERB_ACTIVATE = 1859u;

		private const uint IDS_MENU_OLEVERB_DEACTIVATE = 1860u;

		private const uint IDS_MENU_OLEVERB_EOINCLUDE = 1861u;

		private const uint IDS_MENU_OLEVERB_EOEXCLUDE = 1862u;

		private const uint IDS_MENU_OLEVERB_EOSOLUTIONMETHOD = 1863u;

		private const uint IDS_MENU_OLEVERB_SMSOLUTIONMETHOD = 1864u;

		private const uint IDS_MENU_OLEVERB_CALCULATE = 1865u;

		private const uint IDS_MENU_OLEVERB_CONVERTTO = 1866u;

		private const uint IDS_MENU_OLEVERB_REVERT = 1867u;

		private const uint IDS_MENU_OLEVERB_EDITMODEL = 1868u;

		private const uint IDS_MENU_OLEVERB_ABOUT = 1869u;

		private const uint IDS_MENU_OLEVERB_HELP = 1870u;

		private const uint IDS_MENU_OLEVERB_VENDOR = 1871u;

		private SORRes sorRes;

		private ICommand _openStreamReportCommand;

		public ICommand OpenStreamReportCommand
		{
			get
			{
				if (_openStreamReportCommand == null)
				{
					_openStreamReportCommand = new DelegateCommand<object>(OpenStreamReportCommand_Executed, OpenStreamReportCommand_CanExecute);
				}
				return _openStreamReportCommand;
			}
		}

		public PFSContextMenu()
		{
			Menu = new ContextMenuExtender();
			Menu.Style = Application.Current.TryFindResource(typeof(ContextMenu)) as Style;
			SubMenuStack = new Stack<MenuItem>();
			nCostingCmdId = 0;
			nABECmdId = 0;
			sorRes = new SORRes();
		}

		~PFSContextMenu()
		{
			sorRes.Dispose();
		}

		public void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked, string strSubject)
		{
			if (m_NodeType == -1)
			{
				IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				if (eventAggregator != null)
				{
					PFSContextMenuItemBlockTypeRetrieveEventArgs e = new PFSContextMenuItemBlockTypeRetrieveEventArgs();
					eventAggregator.GetEvent<PFSContextMenuItemBlockTypeRetrieveEvent>().Publish(e);
					m_NodePath = e.NodePath;
					m_BlockType = e.BlockType;
					m_ObjectNavigatorPath = e.NavigatorPath;
					m_NodeType = e.NodeType;
					if (m_NodeType != 1 && m_NodeType != 2)
					{
						m_NodeType = 0;
					}
					QueryFlowsheetModeEventArgs e2 = new QueryFlowsheetModeEventArgs();
					eventAggregator.GetEvent<QueryFlowsheetModeEvent>().Publish(e2);
					m_strFlowsheetMode = e2.FlowsheetMode;
				}
			}
			if (m_strFlowsheetMode == "PSV")
			{
				if (nCmdId == 8452 || nCmdId == 8453)
				{
					m_bInputOrResults = true;
				}
				if (m_bInputOrResults && nCmdId != 8452 && nCmdId != 8453)
				{
					return;
				}
			}
			switch (nCmdId)
			{
			case 0:
			{
				Separator separator = new Separator();
				separator.Margin = new Thickness(0.0);
				if (SubMenuStack.Count == 0)
				{
					Menu.Items.Add(separator);
				}
				else
				{
					SubMenuStack.Peek().Items.Add(separator);
				}
				return;
			}
			case -2:
				SubMenuStack.Pop();
				return;
			case 8469:
			case 8499:
				if (!IsABEReady())
				{
					return;
				}
				break;
			}
			MenuItem menuItem = GenerateMenuItem(sUID, nCmdId, sItem, sIcon, bEnabled, bChecked, strSubject);
			menuItem.Uid = sUID;
			if (SubMenuStack.Count == 0)
			{
				Menu.Items.Add(menuItem);
			}
			else
			{
				SubMenuStack.Peek().Items.Add(menuItem);
			}
			if (nCmdId == -1)
			{
				SubMenuStack.Push(menuItem);
			}
		}

		private string getSorResString(uint ID)
		{
			return sorRes.GetString(ID)?.Replace("&", string.Empty);
		}

		private MenuItem GenerateMenuItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked, string strSubject)
		{
			string text = string.Empty;
			int num = sItem.IndexOf('\t');
			if (num >= 0)
			{
				text = sItem.Substring(num + 1);
				sItem = sItem.Substring(0, num);
			}
			MenuItem menuItem = new MenuItem();
			menuItem.Uid = sUID;
			if (nCmdId > 0)
			{
				menuItem.CommandParameter = nCmdId.ToString();
			}
			string strHeader = sItem;
			if (sItem.EndsWith("EOInclude"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("EOInclude"));
			}
			if (sItem.EndsWith("EOExclude"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("EOExclude"));
			}
			if (sItem.EndsWith("Activate"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("Activate"));
			}
			if (sItem.EndsWith("Deactivate"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("Deactivate"));
			}
			if (sItem.EndsWith("EOSolutionMethod"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("EOSolutionMethod"));
			}
			if (sItem.EndsWith("SMSolutionMethod"))
			{
				sItem = sItem.Substring(0, sItem.LastIndexOf("SMSolutionMethod"));
			}
			menuItem.Header = sItem.Replace('&', '_');
			_ = text != string.Empty;
			string text2 = sItem.Replace("&", string.Empty);
			bool flag = false;
			if (text2.EndsWith(getSorResString(570u)))
			{
				flag = true;
				nCostingCmdId = nCmdId;
			}
			if (text2.EndsWith(getSorResString(591u)))
			{
				nABECmdId = nCmdId;
			}
			int num2 = bEnabled;
			if (!IsHandledSpecifically(nCmdId, menuItem, strSubject))
			{
				if (flag && bEnabled != 0 && !ExtraEnabledCheckForCosting(bEnabled: true))
				{
					num2 = 0;
				}
				if ((nCmdId == 8469 || nCmdId == 8499) && !IsABEReady())
				{
					num2 = 0;
				}
				menuItem.IsEnabled = num2 != 0;
				menuItem.IsChecked = bChecked != 0;
				menuItem.Click += OnClickMenuItem;
			}
			if (string.Compare(sIcon, "Refresh_16") == 0 || string.Compare(sIcon, "Delete_16") == 0)
			{
				Image image = new Image();
				Type typeFromHandle = typeof(CommonImages);
				try
				{
					image.Source = (ImageSource)typeFromHandle.InvokeMember(sIcon, BindingFlags.GetProperty, null, CommonImages.Instance, null);
				}
				catch
				{
					image.Source = null;
				}
				if (image.Source != null)
				{
					menuItem.Icon = image;
				}
			}
			else
			{
				menuItem.Icon = AddMenuItemIconByIDorIconString(nCmdId, sIcon, strHeader, menuItem.IsEnabled);
			}
			return menuItem;
		}

		private void SetupSplitMenuItem()
		{
			if (m_strFlowsheetMode == "PSV")
			{
				return;
			}
			int result = 0;
			for (int i = 0; i < Menu.Items.Count; i++)
			{
				if (!(Menu.Items[i] is MenuItem menuItem))
				{
					continue;
				}
				List<MenuItem> list = new List<MenuItem>();
				if (menuItem == null || menuItem.CommandParameter != null)
				{
					continue;
				}
				foreach (object item in (IEnumerable)menuItem.Items)
				{
					if (item is MenuItem)
					{
						list.Add(item as MenuItem);
					}
				}
				foreach (object item2 in (IEnumerable)menuItem.Items)
				{
					if (!(item2 is MenuItem))
					{
						continue;
					}
					MenuItem menuItem2 = item2 as MenuItem;
					if (menuItem2.CommandParameter == null)
					{
						continue;
					}
					int.TryParse(menuItem2.CommandParameter.ToString(), out result);
					if (result <= 0 || !IsPullRightSplitMenuItem(result))
					{
						continue;
					}
					string header = ((menuItem.Header != null) ? menuItem.Header.ToString() : string.Empty);
					int insertIndex = Menu.Items.IndexOf(menuItem);
					menuItem.Items.Clear();
					Menu.Items.Remove(menuItem);
					SplitMenuItem splitMenuItem = new SplitMenuItem();
					splitMenuItem.Header = header;
					splitMenuItem.SplitMenuItemClick += SplitMenuItem_SplitMenuItemClick;
					if (result == 56050 || result == 56100)
					{
						CopyMenuItemSettings(splitMenuItem, menuItem2);
					}
					foreach (MenuItem item3 in list)
					{
						splitMenuItem.Items.Add(item3);
					}
					Menu.Items.Insert(insertIndex, splitMenuItem);
					break;
				}
			}
			RemoveCustomStreamResultMenuItems();
			SplitStreamResultMenuItemForHierarchy();
		}

		private void RemoveCustomStreamResultMenuItems()
		{
			if (m_NodeType == 1)
			{
				MenuItem menuItem = Menu.Items.OfType<MenuItem>().FirstOrDefault((MenuItem x) => string.Equals(x.CommandParameter as string, 8458.ToString()));
				if (menuItem != null)
				{
					Menu.Items.Remove(menuItem);
				}
			}
			else if (m_NodeType == 2)
			{
				MenuItem menuItem2 = Menu.Items.OfType<MenuItem>().FirstOrDefault((MenuItem x) => string.Equals(x.CommandParameter as string, 8458.ToString()));
				if (menuItem2 != null)
				{
					Menu.Items.Remove(menuItem2);
				}
			}
		}

		private void SplitStreamResultMenuItemForHierarchy()
		{
			if (m_NodeType != 1 || !string.Equals(m_BlockType, "HIERARCHY", StringComparison.OrdinalIgnoreCase))
			{
				return;
			}
			MenuItem menuItem = Menu.Items.OfType<MenuItem>().FirstOrDefault((MenuItem x) => string.Equals(x.CommandParameter as string, 8454.ToString()));
			if (menuItem == null)
			{
				return;
			}
			IStreamReportPresenter streamReportPresenter = UnityContainerHelper.TryResolve<IStreamReportPresenter>(PfsDialogsModule.Container);
			if (streamReportPresenter == null)
			{
				return;
			}
			IEnumerable<Tuple<string, object>> streamGroupsForHierarchyInFlowsheet = streamReportPresenter.GetStreamGroupsForHierarchyInFlowsheet();
			if (streamGroupsForHierarchyInFlowsheet == null || !streamGroupsForHierarchyInFlowsheet.Any())
			{
				return;
			}
			SplitMenuItem splitMenuItem = new SplitMenuItem
			{
				Header = menuItem.Header,
				CommandParameter = menuItem.CommandParameter
			};
			splitMenuItem.SplitMenuItemClick += SplitMenuItem_SplitMenuItemClick;
			foreach (Tuple<string, object> item in streamGroupsForHierarchyInFlowsheet)
			{
				MenuItem newItem = new MenuItem
				{
					Header = item.Item1,
					Command = OpenStreamReportCommand,
					CommandParameter = item.Item2
				};
				splitMenuItem.Items.Add(newItem);
			}
			Menu.Items.Insert(Menu.Items.IndexOf(menuItem), splitMenuItem);
			Menu.Items.Remove(menuItem);
		}

		private void OpenStreamReportCommand_Executed(object parameter)
		{
			UnityContainerHelper.TryResolve<IStreamReportPresenter>(PfsDialogsModule.Container)?.OpenStreamSummaryReport(FlowsheetContextType.HierarchyBlockSelected, m_ObjectNavigatorPath, parameter);
		}

		private bool OpenStreamReportCommand_CanExecute(object parameter)
		{
			return true;
		}

		private void CopyMenuItemSettings(MenuItem miDestination, MenuItem miSource)
		{
			if (miDestination != null && miSource != null)
			{
				if (miSource.Icon != null && miSource.Icon is Image)
				{
					Image image = new Image();
					image.Source = (miSource.Icon as Image).Source;
					miDestination.Icon = image;
				}
				miDestination.CommandParameter = miSource.CommandParameter;
				miDestination.IsEnabled = miSource.IsEnabled;
				miDestination.IsChecked = miSource.IsChecked;
			}
		}

		private bool IsPullRightSplitMenuItem(int nCommandID)
		{
			switch (nCommandID)
			{
			case 56099:
			case 56100:
				return true;
			case 56049:
			case 56050:
				return true;
			default:
				return false;
			}
		}

		private bool IsSplitMenuItem(int nCommandID)
		{
			if (m_NodeType == 1)
			{
				if (nCommandID == 8454 || nCommandID == 8458)
				{
					return true;
				}
			}
			else if (m_NodeType == 2 && (nCommandID == 8453 || nCommandID == 8458))
			{
				return true;
			}
			return false;
		}

		private Image AddMenuItemIcon(string strHeader, bool enable)
		{
			strHeader = strHeader.Replace("_", "");
			if (strHeader.Contains("Custom Stream Results"))
			{
				return GetContextItemIcon("HomeSummaryStreams16.ico", enable);
			}
			if (strHeader.Contains("Models"))
			{
				return GetContextItemIcon("GHomeSummaryModel16.ico", enable);
			}
			if (strHeader.Contains("Reconcile") || strHeader == "Reconcile Selected")
			{
				return GetContextItemIcon("HomeRunReconcile16.ico", enable);
			}
			if (strHeader.Contains("Move Selection"))
			{
				return GetContextItemIcon("HierarchyMoveSelection16.ico", enable);
			}
			if (strHeader.Contains("Add to Model Library"))
			{
				return GetContextItemIcon("DeveloperModelLibraryAddLibrary16.ico", enable);
			}
			if (strHeader.Contains("SM Deactivate") || strHeader == "Deactivate")
			{
				return GetContextItemIcon("Disable16.ico", enable);
			}
			if (strHeader.Contains("Cut"))
			{
				return GetContextItemIcon("Cut16.ico", enable);
			}
			if (strHeader.Contains("Copy"))
			{
				return GetContextItemIcon("Copy16.ico", enable);
			}
			if (strHeader.Contains("Rotate Left"))
			{
				return GetContextItemIcon("Rotateleft16.ico", enable);
			}
			if (strHeader.Contains("Rotate Right"))
			{
				return GetContextItemIcon("RotateRight16.ico", enable);
			}
			if (strHeader.Contains("Flip Horizontal"))
			{
				return GetContextItemIcon("FlipLeftRight16.ico", enable);
			}
			if (strHeader.Contains("Flip Vertical"))
			{
				return GetContextItemIcon("FlipUpDown16.ico", enable);
			}
			if (strHeader.Contains("Send to Back"))
			{
				return GetContextItemIcon("SendtoBack16.ico", enable);
			}
			if (strHeader.Contains("Bring to Front"))
			{
				return GetContextItemIcon("BringtoFront16.ico", enable);
			}
			if (strHeader.Contains("Zoom In"))
			{
				return GetContextItemIcon("ZoomIn16.ico", enable);
			}
			if (strHeader.Contains("Zoom Out"))
			{
				return GetContextItemIcon("ZoomOut16.ico", enable);
			}
			if (strHeader.Contains("Zoom to Fit"))
			{
				return GetContextItemIcon("ZoomFitToWindow16.ico", enable);
			}
			if (strHeader.Contains("Zoom Full"))
			{
				return GetContextItemIcon("ZoomFitToWindow16.ico", enable);
			}
			switch (strHeader)
			{
			case "Add Text":
				return GetContextItemIcon("AddText16.ico", enable);
			case "Pan":
				return GetContextItemIcon("Pan16.ico", enable);
			case "Print...":
				return GetContextItemIcon("FilePrint16.ico", enable);
			case "Print":
				return GetContextItemIcon("FilePrint16.ico", enable);
			case "Paste":
				return GetContextItemIcon("Paste16.ico", enable);
			case "Join Streams":
				return GetContextItemIcon("FlowsheetJoin16.ico", enable);
			case "Align Blocks":
				return GetContextItemIcon("FlowsheetAlign16.ico", enable);
			default:
				if (strHeader.Contains("Reroute Stream"))
				{
					return GetContextItemIcon("FlowsheetRerouteStream16.ico", enable);
				}
				return strHeader switch
				{
					"Ungroup" => GetContextItemIcon("Ungroup1.ico", enable), 
					"Group" => GetContextItemIcon("ObjectsGroup16.ico", enable), 
					"Find Object..." => GetContextItemIcon("Find16.ico", enable), 
					"Break Stream" => GetContextItemIcon("FlowsheetBreak16.ico", enable), 
					"Insert Block" => GetContextItemIcon("FlowsheetInsert16.ico", enable), 
					"Edit Legend" => GetContextItemIcon("EditLegend16.ico", enable), 
					"Y Axis Map" => GetContextItemIcon("YAxisMap16.ico", enable), 
					"Print Preview" => GetContextItemIcon("PrintPreview16.ico", enable), 
					"Page Setup" => GetContextItemIcon("PageSetup16.ico", enable), 
					_ => null, 
				};
			}
		}

		private Image AddMenuItemIconByIDorIconString(int nID, string strIcon, string strHeader, bool bEnable)
		{
			switch (nID)
			{
			case 8452:
				return GetInputOrResultIcon("Input");
			case 8453:
				return GetInputOrResultIcon("Result");
			case 8455:
				return GetContextItemIcon("HomeRunReconcile16.ico", bEnable);
			case 8456:
				return GetContextItemIcon("HierarchyMoveSelection16.ico", bEnable);
			case 8458:
				return GetContextItemIcon("HomeSummaryStreams16.ico", bEnable);
			case 8461:
			case 8485:
				return GetContextItemIcon("DeveloperModelLibraryAddLibrary16.ico", bEnable);
			case 8465:
				return GetContextItemIcon("FlowsheetBreak16.ico", bEnable);
			case 8466:
			case 8496:
				strHeader = strHeader.Replace("_", "");
				if (strHeader.EndsWith("Deactivate"))
				{
					return GetContextItemIcon("Disable16.ico", bEnable);
				}
				break;
			case 8497:
				return GetContextItemIcon("FlowsheetJoin16.ico", bEnable);
			case 8476:
				return GetContextItemIcon("FlowsheetInsert16.ico", bEnable);
			case 8478:
				return GetContextItemIcon("GHomeSummaryModel16.ico", bEnable);
			default:
				switch (strIcon)
				{
				case "ZoomIn_16":
					return GetContextItemIcon("ZoomIn16.ico", bEnable);
				case "ZoomOut_16":
					return GetContextItemIcon("ZoomOut16.ico", bEnable);
				case "ZoomFitToWindow_16":
					return GetContextItemIcon("ZoomFitToWindow16.ico", bEnable);
				case "Pan_16":
					return GetContextItemIcon("Pan16.ico", bEnable);
				case "Print_16":
					return GetContextItemIcon("FilePrint16.ico", bEnable);
				case "Find_16":
					return GetContextItemIcon("Find16.ico", bEnable);
				case "Paste_16":
					return GetContextItemIcon("Paste16.ico", bEnable);
				case "Cut_16":
					return GetContextItemIcon("Cut16.ico", bEnable);
				case "Copy_16":
					return GetContextItemIcon("Copy16.ico", bEnable);
				case "OrderSendToBack_16":
					return GetContextItemIcon("SendtoBack16.ico", bEnable);
				case "OrderBringToFront_16":
					return GetContextItemIcon("BringtoFront16.ico", bEnable);
				case "RotateLeft_16":
					return GetContextItemIcon("RotateLeft16.ico", bEnable);
				case "RotateRight_16":
					return GetContextItemIcon("RotateRight16.ico", bEnable);
				case "FlipLR_16":
					return GetContextItemIcon("FlipLeftRight16.ico", bEnable);
				case "FlipUD_16":
					return GetContextItemIcon("FlipUpDown16.ico", bEnable);
				case "StreamAlignBlocks_16":
					return GetContextItemIcon("FlowsheetAlign16.ico", bEnable);
				case "StreamReroute_16":
					return GetContextItemIcon("FlowsheetRerouteStream16.ico", bEnable);
				case "EditLegend_16":
					return GetContextItemIcon("EditLegend16.ico", bEnable);
				case "YAxisMap_16":
					return GetContextItemIcon("YAxisMap16.ico", bEnable);
				case "AddText_16":
					return GetContextItemIcon("AddText16.ico", bEnable);
				case "PrintPreview_16":
					return GetContextItemIcon("PrintPreview16.ico", bEnable);
				case "PageSetup_16":
					return GetContextItemIcon("PageSetup16.ico", bEnable);
				case "Group_16":
					return GetContextItemIcon("ObjectsGroup16.ico", bEnable);
				case "Ungroup_16":
					return GetContextItemIcon("Ungroup1.ico", bEnable);
				case "PrintPreview16":
					return GetContextItemIcon("PrintPreview16.ico", bEnable);
				case "FilePrint16":
					return GetContextItemIcon("FilePrint16.ico", bEnable);
				}
				break;
			case 8450:
			case 8451:
			case 8454:
			case 8457:
			case 8459:
			case 8460:
			case 8462:
			case 8463:
			case 8464:
			case 8467:
			case 8468:
			case 8469:
			case 8470:
			case 8471:
			case 8472:
			case 8473:
			case 8474:
			case 8475:
			case 8477:
			case 8479:
			case 8480:
			case 8481:
			case 8482:
			case 8483:
			case 8484:
			case 8486:
			case 8487:
			case 8488:
			case 8489:
			case 8490:
			case 8491:
			case 8492:
			case 8493:
			case 8494:
			case 8495:
			case 8498:
			case 8499:
				break;
			}
			return null;
		}

		private Image GetContextItemIcon(string strImage, bool enable)
		{
			Image image = new Image();
			BitmapImage bitmapImage = new BitmapImage(new Uri(string.Concat("pack://application:,,,/" + typeof(PFSContextMenu).Assembly.FullName + ";component/Images/", strImage), UriKind.RelativeOrAbsolute));
			if (enable)
			{
				image.Source = bitmapImage;
			}
			else
			{
				byte[] array = new byte[bitmapImage.PixelHeight * bitmapImage.PixelWidth * 4];
				byte[] array2 = new byte[array.Length];
				bitmapImage.CopyPixels(array, bitmapImage.PixelWidth * 4, 0);
				for (int i = 3; i < array.Length; i += 4)
				{
					int num = array[i - 3] + array[i - 2] + array[i - 1];
					if (num != 0)
					{
						num /= 3;
					}
					array2[i] = array[i];
					array2[i - 3] = (byte)num;
					array2[i - 2] = (byte)num;
					array2[i - 1] = (byte)num;
				}
				image.Source = BitmapSource.Create(bitmapImage.PixelWidth, bitmapImage.PixelHeight, 96.0, 96.0, PixelFormats.Bgra32, null, array2, bitmapImage.PixelWidth * 4);
			}
			return image;
		}

		private Image GetInputOrResultIcon(string strType)
		{
			Image image = new Image();
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				PFSContextMenuItemIconRetrieveEventArgs e = new PFSContextMenuItemIconRetrieveEventArgs(strType);
				eventAggregator.GetEvent<PFSContextMenuItemIconRetrieveEvent>().Publish(e);
				image.Source = e.StatusImage as ImageSource;
			}
			return image;
		}

		private bool ExtraEnabledCheckForCosting(bool bEnabled)
		{
			bool flag = bEnabled;
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				IsIPEInstalledRetrieveEventArgs e = new IsIPEInstalledRetrieveEventArgs();
				eventAggregator.GetEvent<IsIPEInstalledRetrieveEvent>().Publish(e);
				flag = e.IsIPEInstalled;
			}
			return bEnabled && flag;
		}

		private void DoPartialFlowsheetCosting()
		{
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				ShowPartialFlowsheetCostBlocksEventArgs payload = new ShowPartialFlowsheetCostBlocksEventArgs(null);
				eventAggregator.GetEvent<ShowPartialFlowsheetCostBlocksEvent>().Publish(payload);
			}
		}

		private void InvokeABE()
		{
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				ShowABEventArgs payload = new ShowABEventArgs();
				eventAggregator.GetEvent<ShowABEvent>().Publish(payload);
			}
		}

		private bool IsABEReady()
		{
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				IsABEReadyRetrieveEventArgs e = new IsABEReadyRetrieveEventArgs();
				eventAggregator.GetEvent<IsABEReadyRetrieveEvent>().Publish(e);
				return e.IsABEReady;
			}
			return false;
		}

		public void ShowMenu(object pfs)
		{
			pfsObject = pfs;
			SetupSplitMenuItem();
			DisableSubMenuIfPossible(Menu);
			Menu.Closed += Menu_Closed;
			PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>())?.GetEvent<PFSContextMenuShowEvent>().Publish(new PFSContextMenuShowEventArgs(Menu));
			Menu.IsOpen = true;
		}

		private void Menu_Closed(object sender, RoutedEventArgs e)
		{
			PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>())?.GetEvent<PFSContextMenuClosedEvent>().Publish(new PFSContextMenuClosedEventArgs());
		}

		private bool IsHandledSpecifically(int cmdID, MenuItem menuItem, string strSubject)
		{
			if (PfsDialogsModule.Container != null)
			{
				IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
				if (eventAggregator != null)
				{
					PFSContextMenuItemLoadedEventArgs args = new PFSContextMenuItemLoadedEventArgs(menuItem);
					args.CommandID = cmdID;
					args.Subject = strSubject;
					eventAggregator.GetEvent<PFSContextMenuItemLoadedEvent>().Publish(args);
					if (args.Handled)
					{
						menuItem.IsEnabled = args.CanExecute;
						menuItem.IsChecked = args.IsChecked;
						menuItem.Click += delegate
						{
							if (args.ExecutedAction != null)
							{
								args.ExecutedAction(args);
							}
						};
						return true;
					}
				}
			}
			return false;
		}

		private void OnClickMenuItem(object sender, RoutedEventArgs e)
		{
			MenuItem menuItem = sender as MenuItem;
			if (menuItem.CommandParameter == null)
			{
				return;
			}
			string value = menuItem.CommandParameter.ToString();
			int num = 0;
			try
			{
				num = Convert.ToInt32(value);
			}
			catch
			{
				num = 0;
			}
			if (num > 0)
			{
				if (num == nCostingCmdId)
				{
					DoPartialFlowsheetCosting();
					return;
				}
				if (num == nABECmdId)
				{
					InvokeABE();
					return;
				}
				object[] args = new object[1] { num };
				pfsObject.GetType().InvokeMember("InvokeMenuItem", BindingFlags.InvokeMethod, null, pfsObject, args);
			}
		}

		private void SplitMenuItem_SplitMenuItemClick(MenuItem e)
		{
			if (e != null && e.CommandParameter != null)
			{
				Menu.IsOpen = false;
				string value = e.CommandParameter.ToString();
				int num = 0;
				try
				{
					num = Convert.ToInt32(value);
				}
				catch
				{
					num = 0;
				}
				if (num > 0)
				{
					object[] args = new object[1] { num };
					pfsObject.GetType().InvokeMember("InvokeMenuItem", BindingFlags.InvokeMethod, null, pfsObject, args);
				}
			}
		}

		private void DisableSubMenuIfAllSubmenuItemsAreDisabled(MenuItem menuitem)
		{
			if (menuitem == null)
			{
				return;
			}
			ItemCollection items = menuitem.Items;
			if (items == null || items.Count == 0)
			{
				return;
			}
			bool isEnabled = false;
			foreach (object item in (IEnumerable)items)
			{
				if (item is MenuItem menuItem)
				{
					if (menuItem.IsEnabled)
					{
						DisableSubMenuIfAllSubmenuItemsAreDisabled(menuItem);
					}
					if (menuItem.IsEnabled)
					{
						isEnabled = true;
						break;
					}
				}
			}
			menuitem.IsEnabled = isEnabled;
		}

		private void DisableSubMenuIfPossible(ContextMenu objMenu)
		{
			foreach (object item in (IEnumerable)objMenu.Items)
			{
				if (item is MenuItem menuitem)
				{
					DisableSubMenuIfAllSubmenuItemsAreDisabled(menuitem);
				}
			}
		}
	}
	internal class ContextMenuExtender : ContextMenu
	{
		internal struct Win32Point
		{
			public int X;

			public int Y;
		}

		[DllImport("user32.dll")]
		[return: MarshalAs(UnmanagedType.Bool)]
		internal static extern bool GetCursorPos(ref Win32Point pt);

		protected override void OnMouseLeave(MouseEventArgs e)
		{
			base.OnMouseLeave(e);
			if (e.LeftButton != MouseButtonState.Pressed && e.RightButton != MouseButtonState.Pressed)
			{
				return;
			}
			Win32Point pt = default(Win32Point);
			GetCursorPos(ref pt);
			IEventAggregator eventAggregator = PfsDialogsModule.Container.Resolve<IEventAggregator>(Array.Empty<ResolverOverride>());
			if (eventAggregator != null)
			{
				string strMouseButtonType = string.Empty;
				if (e.LeftButton == MouseButtonState.Pressed)
				{
					strMouseButtonType = "MouseLeftButton";
				}
				else if (e.RightButton == MouseButtonState.Pressed)
				{
					strMouseButtonType = "MouseRightButton";
				}
				eventAggregator.GetEvent<PFSContextMenuClosedPositionEvent>().Publish(new PFSContextMenuClosedPositionEventArgs(pt.X, pt.Y, strMouseButtonType));
			}
		}
	}
	public class ControlVariableListDialog : Window, IComponentConnector
	{
		public class ControlVariable
		{
			public string Name { get; set; }

			public string Description { get; set; }
		}

		public List<ControlVariable> ControlVariableList;

		public string sControlVariableName = string.Empty;

		public int nVariableSelectedIndex = -1;

		internal ControlVariableListDialog dlg;

		internal Grid grid1;

		internal Button CVListOk;

		internal Button Cancel;

		internal DataGrid dgVariableList;

		private bool _contentLoaded;

		public void LoadControlVariableList(string sCtrlVarList)
		{
			if (sCtrlVarList == null || sCtrlVarList.Length <= 0)
			{
				return;
			}
			string[] array = sCtrlVarList.Split('|');
			ControlVariableList = new List<ControlVariable>();
			for (int i = 0; i < array.Length; i++)
			{
				string[] array2 = array[i].Split(',');
				ControlVariable controlVariable = new ControlVariable();
				controlVariable.Name = array2[0];
				if (array2.Length > 1)
				{
					controlVariable.Description = array2[1];
				}
				ControlVariableList.Add(controlVariable);
			}
		}

		public ControlVariableListDialog(bool bProcVars, string sVarInfoList)
		{
			LoadControlVariableList(sVarInfoList);
			InitializeComponent();
			base.Title = string.Format(WpfPfsDialogsResources.PFSControlVariableListDialog_Title, bProcVars ? WpfPfsDialogsResources.PFSControlVariableListDialog_Process : WpfPfsDialogsResources.PFSControlVariableListDialog_Manipulated);
			dgVariableList.ItemsSource = ControlVariableList;
			dgVariableList.SelectionChanged += ControlVariable_Selected;
			dgVariableList.MouseDoubleClick += ControlVariable_DoubleClicked;
			CVListOk.IsEnabled = nVariableSelectedIndex >= 0;
		}

		private void ControlVariable_Selected(object sender, SelectionChangedEventArgs e)
		{
			nVariableSelectedIndex = dgVariableList.SelectedIndex;
			if (nVariableSelectedIndex >= 0 && nVariableSelectedIndex < ControlVariableList.Count)
			{
				sControlVariableName = ControlVariableList[nVariableSelectedIndex].Name;
			}
			CVListOk.IsEnabled = nVariableSelectedIndex >= 0;
		}

		private void ControlVariable_DoubleClicked(object sender, MouseEventArgs e)
		{
			nVariableSelectedIndex = dgVariableList.SelectedIndex;
			if (nVariableSelectedIndex >= 0 && nVariableSelectedIndex < ControlVariableList.Count)
			{
				sControlVariableName = ControlVariableList[nVariableSelectedIndex].Name;
				base.DialogResult = true;
				Close();
			}
		}

		private void Ok_Click(object sender, RoutedEventArgs e)
		{
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfscontrolvariablelistdialog.xaml", UriKind.Relative);
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
				dlg = (ControlVariableListDialog)target;
				break;
			case 2:
				grid1 = (Grid)target;
				break;
			case 3:
				CVListOk = (Button)target;
				CVListOk.Click += Ok_Click;
				break;
			case 4:
				Cancel = (Button)target;
				break;
			case 5:
				dgVariableList = (DataGrid)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSCommonDialogs
	{
		private PFSContextMenu m_menuPFSContextMenu;

		public static Window GetOwningWindow()
		{
			IUnityContainer container = PfsDialogsModule.Container;
			Window window = null;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					if (shellApplication.ActiveWindow != null && shellApplication.ActiveWindow.ActiveScreen != null)
					{
						window = Window.GetWindow(shellApplication.ActiveWindow.ActiveScreen);
					}
					if (window == null)
					{
						window = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
					}
				}
			}
			return window;
		}

		public static void SetOwningWindow(Window Dlg)
		{
			Dlg.WindowStartupLocation = WindowStartupLocation.CenterOwner;
			Dlg.Owner = GetOwningWindow();
		}

		public int MessageBox(string contents, string caption, int buttons, int image)
		{
			return (int)MMMessageBox.Show(GetOwningWindow(), contents, caption, (MMMessageBoxButton)buttons, (MMMessageBoxImage)image);
		}

		public int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput)
		{
			PFSTextInputDialog pFSTextInputDialog = new PFSTextInputDialog(strCaption, strPrompt, strDefaultText, iUpper != 0, nLength);
			SetOwningWindow(pFSTextInputDialog);
			bool value = pFSTextInputDialog.ShowDialog().Value;
			strTextInput = pFSTextInputDialog.StrInput;
			return value ? 1 : 0;
		}

		public void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked, string strSubject)
		{
			if (m_menuPFSContextMenu == null)
			{
				m_menuPFSContextMenu = new PFSContextMenu();
			}
			m_menuPFSContextMenu.AddItem(sUID, nCmdId, sItem, sIcon, bEnabled, bChecked, strSubject);
		}

		public void ShowMenu(object pfs)
		{
			if (m_menuPFSContextMenu != null)
			{
				m_menuPFSContextMenu.ShowMenu(pfs);
			}
		}
	}
	[Guid("75A200A4-2842-4EAA-9737-F3CC7A3AB5F5")]
	[ComVisible(true)]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IPFSPlotDialogs
	{
		int MessageBox(string contents, string caption, int buttons, int image);

		int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput);

		int DoPageSetup(object pfs);

		int ShowEditLegendDialog(int iHint);

		void AddLegend(string strLegend);

		int GetLegend(int iIndex, out string strLegend);

		int ShowYAxisMapDialog(string sSingleAxisLabel, out int bConfigChanged);

		void AddVarName(string strVarName, string strDefaultLabel);

		void AddYAxisLabel(string strYAxislabel);

		void AddYAxisMapIndex(int iMapIndex);

		int GetYAxisLabel(int iIndex, out string strYAxisLabel);

		int GetYAxisMapIndex(int iIndex, out int iMapIndex);

		void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked);

		void ShowMenu(object pfs);
	}
	[ComVisible(true)]
	[Guid("1A208F0B-B3AC-4F5E-946E-4A843B7CC5FB")]
	[ProgId("AspenTech.AspenPlus.PfsDialogs.PFSPlotDialogs.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class PFSPlotDialogs : IPFSPlotDialogs
	{
		private PFSPlotEditLegendDialog m_dlgEditLegendDialog;

		private PFSPlotYAxisMapDialog m_dlgYAxisMapDialog;

		private PFSCommonDialogs m_dlgCommonDialogs;

		private object PFS { get; set; }

		private PrintPageSettings PrintSettings
		{
			get
			{
				PrintPageSettings printPageSettings = SystemEnvironment.ApplicationSettings.PrintSettingsForPlots;
				if (printPageSettings == null)
				{
					printPageSettings = new PrintPageSettings();
					printPageSettings.IsLandscape = true;
					PrintPageSettings printSettings = SystemEnvironment.ApplicationSettings.PrintSettings;
					if (printSettings != null)
					{
						printPageSettings.PaperSize = printSettings.PaperSize;
						printPageSettings.PaperSource = printSettings.PaperSource;
						if (printSettings.Margin.HasValue)
						{
							printPageSettings.Margin = printSettings.Margin.Value;
						}
					}
				}
				return printPageSettings;
			}
			set
			{
				SystemEnvironment.ApplicationSettings.PrintSettingsForPlots = value;
				object[] args = new object[5]
				{
					value.IsLandscape ? ((short)1) : ((short)0),
					value.Margin.HasValue ? value.Margin.Value.Left : 0.0,
					value.Margin.HasValue ? value.Margin.Value.Top : 0.0,
					value.Margin.HasValue ? value.Margin.Value.Right : 0.0,
					value.Margin.HasValue ? value.Margin.Value.Bottom : 0.0
				};
				PFS.GetType().InvokeMember("SetPrintSettings", BindingFlags.InvokeMethod, null, PFS, args);
			}
		}

		[DispId(1)]
		public int MessageBox(string contents, string caption, int buttons, int image)
		{
			return new PFSCommonDialogs().MessageBox(contents, caption, buttons, image);
		}

		[DispId(2)]
		public int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput)
		{
			return new PFSCommonDialogs().ShowTextInputDialog(strCaption, strPrompt, strDefaultText, iUpper, nLength, out strTextInput);
		}

		[DispId(10)]
		public int DoPageSetup(object pfs)
		{
			PFS = pfs;
			PrintPageSettings printSettings = SystemEnvironment.ApplicationSettings.PrintSettings;
			SystemEnvironment.ApplicationSettings.PrintSettings = PrintSettings;
			GenericPrinting.DoGenericPrintSetup();
			PrintSettings = SystemEnvironment.ApplicationSettings.PrintSettings;
			SystemEnvironment.ApplicationSettings.PrintSettings = printSettings;
			return 1;
		}

		[DispId(20)]
		public int ShowEditLegendDialog(int iHint)
		{
			if (m_dlgEditLegendDialog == null)
			{
				m_dlgEditLegendDialog = new PFSPlotEditLegendDialog();
			}
			PFSCommonDialogs.SetOwningWindow(m_dlgEditLegendDialog);
			return m_dlgEditLegendDialog.ShowDialog().Value ? 1 : 0;
		}

		[DispId(21)]
		public void AddLegend(string strLegend)
		{
			if (m_dlgEditLegendDialog == null)
			{
				m_dlgEditLegendDialog = new PFSPlotEditLegendDialog();
			}
			m_dlgEditLegendDialog.LegendsList.Add(new PFSPlotEditLegendDialog.Legend
			{
				LegendText = strLegend
			});
		}

		[DispId(22)]
		public int GetLegend(int iIndex, out string strLegend)
		{
			if (m_dlgEditLegendDialog == null || iIndex < 0)
			{
				strLegend = string.Empty;
				return 0;
			}
			strLegend = m_dlgEditLegendDialog.LegendsList.ElementAt(iIndex).LegendText;
			return 1;
		}

		[DispId(30)]
		public int ShowYAxisMapDialog(string sSingleAxisLabel, out int bConfigChanged)
		{
			if (m_dlgYAxisMapDialog == null)
			{
				m_dlgYAxisMapDialog = new PFSPlotYAxisMapDialog();
			}
			m_dlgYAxisMapDialog.sSingleAxisLabel = sSingleAxisLabel;
			IUnityContainer container = PfsDialogsModule.Container;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					m_dlgYAxisMapDialog.WindowStartupLocation = WindowStartupLocation.CenterOwner;
					m_dlgYAxisMapDialog.Owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			bool value = m_dlgYAxisMapDialog.ShowDialog().Value;
			bConfigChanged = (m_dlgYAxisMapDialog.bAxisConfigChanged ? 1 : 0);
			return value ? 1 : 0;
		}

		[DispId(31)]
		public void AddVarName(string strVarName, string strDefaultLabel)
		{
			if (m_dlgYAxisMapDialog == null)
			{
				m_dlgYAxisMapDialog = new PFSPlotYAxisMapDialog();
			}
			m_dlgYAxisMapDialog.scolVarNames.Add(strVarName);
			m_dlgYAxisMapDialog.scolVarDefaultLabels.Add(strDefaultLabel);
		}

		[DispId(32)]
		public void AddYAxisLabel(string strYAxislabel)
		{
			if (m_dlgYAxisMapDialog == null)
			{
				m_dlgYAxisMapDialog = new PFSPlotYAxisMapDialog();
			}
			m_dlgYAxisMapDialog.scolYaxisLabels.Add(strYAxislabel);
		}

		[DispId(33)]
		public void AddYAxisMapIndex(int iMapIndex)
		{
			if (m_dlgYAxisMapDialog == null)
			{
				m_dlgYAxisMapDialog = new PFSPlotYAxisMapDialog();
			}
			m_dlgYAxisMapDialog.icolYaxisMap.Add(iMapIndex);
		}

		[DispId(34)]
		public int GetYAxisLabel(int iIndex, out string strYAxisLabel)
		{
			if (m_dlgYAxisMapDialog == null || iIndex < 0 || iIndex >= m_dlgYAxisMapDialog.sColNewYaxisLabels.Count)
			{
				strYAxisLabel = string.Empty;
				return 0;
			}
			strYAxisLabel = m_dlgYAxisMapDialog.sColNewYaxisLabels[iIndex];
			return 1;
		}

		[DispId(35)]
		public int GetYAxisMapIndex(int iIndex, out int iMapIndex)
		{
			if (m_dlgYAxisMapDialog == null || iIndex < 0 || iIndex >= m_dlgYAxisMapDialog.iColNewYaxisMap.Count)
			{
				iMapIndex = -1;
				return 0;
			}
			iMapIndex = m_dlgYAxisMapDialog.iColNewYaxisMap[iIndex];
			return 1;
		}

		[DispId(40)]
		public void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked)
		{
			if (m_dlgCommonDialogs == null)
			{
				m_dlgCommonDialogs = new PFSCommonDialogs();
			}
			m_dlgCommonDialogs.AddItem(sUID, nCmdId, sItem, sIcon, bEnabled, bChecked, "");
		}

		[DispId(41)]
		public void ShowMenu(object pfs)
		{
			if (m_dlgCommonDialogs != null)
			{
				m_dlgCommonDialogs.ShowMenu(pfs);
			}
		}
	}
	[Guid("515B4D21-A5B4-46B7-95A3-699C35F7B385")]
	[ComVisible(true)]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IPFSFlowsheetDialogs
	{
		int MessageBox(string contents, string caption, int buttons, int image);

		void AddBookmark(string name, float scale, float xl, float xr, float yb, float yt);

		int ShowBookmarksDialog(float scale, float xl, float xr, float yb, float yt, out string name);

		int GetBookmarkCount();

		int GetBookmark(int index, out string name, out float scale, out float xl, out float xr, out float yb, out float yt);

		int ShowStreamDialog(int iDefaultColor, int iDefaultWidth, int iDefaultStyle, ref int iUsingDefault, ref int iCurrentLineColor, ref int iCurrentWidth, ref int iCurrentStyle);

		int ShowAnnotationDialog(int iCanFill, ref int iOutline, ref int iFilled, ref int iCurrentLineColor, ref int iCurrentFillColor, ref int iCurrentWidth, ref int iCurrentStyle);

		void ShowFindObjectsDialog(int iClientType, int iPFDMode, int iCenterView, int iZoomView, string sBlocksFilter, string sStreamsFilter, string sCurHierarchy, object pfs);

		void CloseFindObjectsDialog(bool status);

		void RefreshFindObjectsDialog(int iPFDMode, object pfs);

		void FindObjectsDialogAddHierarchy(string name, string sBlockList, string sStreamList);

		void FindObjectsDialogRemoveHierarchy(string name);

		void FindObjectsDialogClearHierarchyList();

		int ShowGridReminderDialog(int iHint);

		int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput);

		int ShowNumericInputDialog(string strCaption, string strPrompt, int nDefaultVal, int nMinVal, int nMaxVal, out int nNumVal);

		int ShowUniversalPortDialog(string strPortList, out int iPortIndex);

		void ShowUnplacedBlocksDialog(object pfs);

		void CloseUnplacedBlocksDialog(int bPlaceAllOnClose);

		void UnplacedBlocksDialogAddBlock(string strBlock);

		void UnplacedBlocksDialogRemoveBlock(string strBlock);

		void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked, string strSubject);

		void ShowMenu(object pfs);

		int ShowControlVariablesListDialog(int bProcVars, string sVarDescList, out string sControlVarName);
	}
	[ComVisible(true)]
	[Guid("436C8A12-A2AE-4F17-9031-6D1656DF8EDA")]
	[ProgId("AspenTech.AspenPlus.PfsDialogs.PFSFlowsheetDialogs.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class PFSFlowsheetDialogs : IPFSFlowsheetDialogs
	{
		private PFSBookmarksDialog BookmarksDlg;

		private PFSFindObjectsDialog m_dlgFindObjectsDialog;

		private static List<string> _pfsObjects = new List<string>
		{
			"Design-Spec", "Blocks", "Calculator", "Transfer", "Convergence", "Sensitivity", "Utilities", "Balance", "Pres-Relief", "Regression",
			"Sequence", "Measurement", "Connection"
		};

		private static List<string> _pfsPaths = new List<string>
		{
			"Blocks", "Utilities", "Flowsheeting Options.Calculator", "Flowsheeting Options.Design-Spec", "Flowsheeting Options.Transfer", "Flowsheeting Options.Balance", "Flowsheeting Options.Pres-Relief", "Flowsheeting Options.Measurement", "Model Analysis Tools.Sensitivity", "Model Analysis Tools.Data-Fit.Regression",
			"Convergence.Convergence", "Convergence.Sequence"
		};

		private static List<string> _sectionObjects = new List<string> { "Blocks", "Streams", "Section" };

		private static List<string> _sectionPaths = new List<string> { "Blocks", "Streams", "Flowsheet.Section" };

		private static List<string> _regressionOrReactions = new List<string> { "Regression", "Reactions" };

		private static List<string> _HcurvesNode = new List<string> { "Hcurves", "Condenser Hcurves", "Reboiler Hcurves", "Connect Stream Hcurves", "Hot Hcurves", "Cold Hcurves" };

		private PFSUnplacedBlocksDialog m_dlgUnplacedBlocksDialog;

		private PFSCommonDialogs m_dlgCommonDialogs;

		[DispId(1)]
		public int MessageBox(string contents, string caption, int buttons, int image)
		{
			return new PFSCommonDialogs().MessageBox(contents, caption, buttons, image);
		}

		[DispId(10)]
		public void AddBookmark(string name, float scale, float xl, float xr, float yb, float yt)
		{
			if (BookmarksDlg == null)
			{
				BookmarksDlg = new PFSBookmarksDialog();
			}
			Rect region = new Rect(xl, yb, xr - xl, yt - yb);
			BookmarkEntry entry = new BookmarkEntry(name, scale, region);
			BookmarksDlg.BookmarkList.InsertSorted(entry);
		}

		[DispId(11)]
		public int ShowBookmarksDialog(float scale, float xl, float xr, float yb, float yt, out string name)
		{
			if (BookmarksDlg == null)
			{
				BookmarksDlg = new PFSBookmarksDialog();
			}
			PFSCommonDialogs.SetOwningWindow(BookmarksDlg);
			MMHelp.SetHelpFile(BookmarksDlg, "userguide1.chm");
			MMHelp.SetHelpId(BookmarksDlg, 1489);
			Rect currentRegion = new Rect(xl, yb, xr - xl, yt - yb);
			BookmarksDlg.CurrentScale = scale;
			BookmarksDlg.CurrentRegion = currentRegion;
			bool value = BookmarksDlg.ShowDialog().Value;
			name = (value ? BookmarksDlg.BookmarkName : string.Empty);
			return value ? 1 : 0;
		}

		[DispId(12)]
		public int GetBookmarkCount()
		{
			if (BookmarksDlg == null)
			{
				return 0;
			}
			return BookmarksDlg.BookmarkList.Count();
		}

		[DispId(13)]
		public int GetBookmark(int index, out string name, out float scale, out float xl, out float xr, out float yb, out float yt)
		{
			if (BookmarksDlg == null || index < 0 || index >= BookmarksDlg.BookmarkList.Count())
			{
				name = string.Empty;
				scale = (xl = (xr = (yt = (yb = 0f))));
				return 0;
			}
			name = BookmarksDlg.BookmarkList[index].Name;
			scale = BookmarksDlg.BookmarkList[index].Scale;
			Rect region = BookmarksDlg.BookmarkList[index].Region;
			xl = (float)region.Left;
			xr = (float)region.Right;
			yb = (float)region.Top;
			yt = (float)region.Bottom;
			return 1;
		}

		[DispId(20)]
		public int ShowStreamDialog(int iDefaultColor, int iDefaultWidth, int iDefaultStyle, ref int iUsingDefault, ref int iCurrentLineColor, ref int iCurrentWidth, ref int iCurrentStyle)
		{
			PFSColorStyleDialog pFSColorStyleDialog = new PFSColorStyleDialog(bStream: true, iUsingDefault != 0, iDefaultColor, iDefaultWidth, iDefaultStyle, bCanFill: false, iCurrentLineColor, -1, iCurrentWidth, iCurrentStyle);
			PFSCommonDialogs.SetOwningWindow(pFSColorStyleDialog);
			bool value = pFSColorStyleDialog.ShowDialog().Value;
			if (value)
			{
				iUsingDefault = (pFSColorStyleDialog.UseDefault ? 1 : 0);
				iCurrentLineColor = pFSColorStyleDialog.CurrentLineColor;
				iCurrentWidth = pFSColorStyleDialog.CurrentWidth + 1;
				iCurrentStyle = pFSColorStyleDialog.CurrentStyle;
			}
			return value ? 1 : 0;
		}

		[DispId(21)]
		public int ShowAnnotationDialog(int iCanFill, ref int iOutline, ref int iFilled, ref int iCurrentLineColor, ref int iCurrentFillColor, ref int iCurrentWidth, ref int iCurrentStyle)
		{
			PFSColorStyleDialog pFSColorStyleDialog = new PFSColorStyleDialog(bStream: false, bUsingDefault: false, iOutline, iFilled, 0, iCanFill != 0, iCurrentLineColor, iCurrentFillColor, iCurrentWidth, iCurrentStyle);
			PFSCommonDialogs.SetOwningWindow(pFSColorStyleDialog);
			bool value = pFSColorStyleDialog.ShowDialog().Value;
			if (value)
			{
				if (!pFSColorStyleDialog.NoOutline.HasValue)
				{
					iOutline = -1;
				}
				else
				{
					iOutline = ((pFSColorStyleDialog.NoOutline != true) ? 1 : 0);
				}
				if (!pFSColorStyleDialog.NoFill.HasValue)
				{
					iFilled = -1;
				}
				else
				{
					iFilled = ((pFSColorStyleDialog.NoFill != true) ? 1 : 0);
				}
				iCurrentLineColor = pFSColorStyleDialog.CurrentLineColor;
				iCurrentFillColor = pFSColorStyleDialog.CurrentFillColor;
				iCurrentWidth = pFSColorStyleDialog.CurrentWidth + 1;
				iCurrentStyle = pFSColorStyleDialog.CurrentStyle;
			}
			return value ? 1 : 0;
		}

		[DispId(30)]
		public void ShowFindObjectsDialog(int iClientType, int iPFDMode, int iCenterView, int iZoomView, string sBlocksFilter, string sStreamsFilter, string sCurHierarchy, object pfs)
		{
			if (m_dlgFindObjectsDialog == null)
			{
				m_dlgFindObjectsDialog = new PFSFindObjectsDialog();
			}
			if (m_dlgFindObjectsDialog.IsDialogOpen)
			{
				return;
			}
			PFSCommonDialogs.SetOwningWindow(m_dlgFindObjectsDialog);
			m_dlgFindObjectsDialog.CenterView = iCenterView != 0;
			m_dlgFindObjectsDialog.ZoomView = iZoomView != 0;
			m_dlgFindObjectsDialog.PFDMode = iPFDMode != 0;
			m_dlgFindObjectsDialog.ClientType = iClientType;
			m_dlgFindObjectsDialog.PFSObject = pfs;
			int num = 0;
			while (num >= 0)
			{
				string empty = string.Empty;
				int num2 = num;
				num = sBlocksFilter.IndexOf(";", num2);
				if (num < 0)
				{
					empty = sBlocksFilter.Substring(num2);
				}
				else
				{
					empty = sBlocksFilter.Substring(num2, num - num2);
					num++;
				}
				if (empty.Length > 0)
				{
					m_dlgFindObjectsDialog.BlockFilterList.Add(empty);
				}
			}
			int num3 = 0;
			while (num3 >= 0)
			{
				string empty2 = string.Empty;
				int num4 = num3;
				num3 = sStreamsFilter.IndexOf(";", num4);
				if (num3 < 0)
				{
					empty2 = sStreamsFilter.Substring(num4);
				}
				else
				{
					empty2 = sStreamsFilter.Substring(num4, num3 - num4);
					num3++;
				}
				if (empty2.Length > 0)
				{
					m_dlgFindObjectsDialog.StreamFilterList.Add(empty2);
				}
			}
			m_dlgFindObjectsDialog.SetCurrentHierarchy(sCurHierarchy);
			m_dlgFindObjectsDialog.Show();
		}

		[DispId(31)]
		public void CloseFindObjectsDialog(bool status)
		{
			if (m_dlgFindObjectsDialog.IsDialogOpen)
			{
				m_dlgFindObjectsDialog.PFSObject = null;
				m_dlgFindObjectsDialog.Close();
			}
		}

		[DispId(32)]
		public void RefreshFindObjectsDialog(int iPFDMode, object pfs)
		{
			m_dlgFindObjectsDialog.PFDMode = iPFDMode != 0;
			m_dlgFindObjectsDialog.PFSObject = pfs;
			if (m_dlgFindObjectsDialog.IsDialogOpen)
			{
				m_dlgFindObjectsDialog.Refresh(bRefreshHierarchy: true);
			}
		}

		[DispId(33)]
		public void FindObjectsDialogAddHierarchy(string name, string sBlockList, string sStreamList)
		{
			if (m_dlgFindObjectsDialog == null)
			{
				m_dlgFindObjectsDialog = new PFSFindObjectsDialog();
			}
			HierarchyItem item = new HierarchyItem(name, sBlockList, sStreamList);
			m_dlgFindObjectsDialog.HierarchyList.InsertSorted(item);
		}

		[DispId(34)]
		public void FindObjectsDialogRemoveHierarchy(string name)
		{
			if (m_dlgFindObjectsDialog == null)
			{
				return;
			}
			int num = m_dlgFindObjectsDialog.HierarchyList.Find(name);
			if (num >= 0)
			{
				if (name == string.Empty)
				{
					m_dlgFindObjectsDialog.HierarchyList[num].BlockList = string.Empty;
					m_dlgFindObjectsDialog.HierarchyList[num].StreamList = string.Empty;
				}
				else
				{
					m_dlgFindObjectsDialog.HierarchyList.RemoveAt(num);
				}
				if (m_dlgFindObjectsDialog.IsDialogOpen)
				{
					m_dlgFindObjectsDialog.SetCurrentHierarchy(string.Empty);
				}
			}
		}

		[DispId(35)]
		public void FindObjectsDialogClearHierarchyList()
		{
			if (m_dlgFindObjectsDialog != null)
			{
				m_dlgFindObjectsDialog.HierarchyList.Clear();
				FindObjectsDialogAddHierarchy(string.Empty, string.Empty, string.Empty);
				if (m_dlgFindObjectsDialog.IsDialogOpen)
				{
					m_dlgFindObjectsDialog.SetCurrentHierarchy(string.Empty);
				}
			}
		}

		[DispId(40)]
		public int ShowGridReminderDialog(int iHint)
		{
			PFSGridReminderDialog pFSGridReminderDialog = new PFSGridReminderDialog();
			PFSCommonDialogs.SetOwningWindow(pFSGridReminderDialog);
			return pFSGridReminderDialog.ShowDialog().Value ? 1 : 0;
		}

		[DispId(60)]
		public int ShowNumericInputDialog(string strCaption, string strPrompt, int nDefaultVal, int nMinVal, int nMaxVal, out int nNumVal)
		{
			PFSNumericInputDialog pFSNumericInputDialog = new PFSNumericInputDialog(strCaption, strPrompt, nDefaultVal, nMinVal, nMaxVal);
			PFSCommonDialogs.SetOwningWindow(pFSNumericInputDialog);
			bool value = pFSNumericInputDialog.ShowDialog().Value;
			nNumVal = pFSNumericInputDialog.NumInput;
			return value ? 1 : 0;
		}

		private Collection<string> ExistingIds(string strCxsPath, MMViewModel viewModel)
		{
			string text;
			switch (CxsPath.LeafId(strCxsPath))
			{
			case "Blocks":
			case "Utilities":
				text = CxsPath.ParentPath(strCxsPath);
				break;
			case "Regression":
				text = CxsPath.ParentPath(CxsPath.ParentPath(CxsPath.ParentPath(strCxsPath)));
				break;
			default:
				text = CxsPath.ParentPath(CxsPath.ParentPath(strCxsPath));
				break;
			}
			if (string.IsNullOrEmpty(text))
			{
				return null;
			}
			CxsBatchRequestData cxsBatchRequestData = new CxsBatchRequestData();
			foreach (string pfsPath in _pfsPaths)
			{
				cxsBatchRequestData.AddRequest(new CxsBatchRequest(CxsPath.CombinePaths(text, pfsPath), "child_ids"));
			}
			object[] array = null;
			try
			{
				array = viewModel.ResolvedCxsProvider.BatchGet(cxsBatchRequestData);
			}
			catch (CxsException)
			{
			}
			if (array == null || array.Count() == 0)
			{
				return null;
			}
			Collection<string> collection = new Collection<string>();
			object[] array2 = array;
			for (int i = 0; i < array2.Length; i++)
			{
				string[] array3 = CxsConverter.ValueToStringArray(array2[i]);
				if (array3 == null || array3.Count() == 0)
				{
					continue;
				}
				string[] array4 = array3;
				foreach (string item in array4)
				{
					if (!collection.Contains(item))
					{
						collection.Add(item);
					}
				}
			}
			return collection;
		}

		[DispId(100)]
		public int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput)
		{
			IUnityContainer container = PfsDialogsModule.Container;
			MMViewModel mMViewModel = container.Resolve<MMViewModel>(Array.Empty<ResolverOverride>());
			OneIdDialog.maskType mask = OneIdDialog.maskType.IS_ID;
			string text = string.Empty;
			string text2 = "";
			string text3 = "";
			bool flag = strDefaultText.Contains("Data!Blocks!");
			if (flag)
			{
				text2 = "Blocks";
				text3 = strDefaultText.Replace("Data!Blocks!", "").Replace("@", "").Replace("!", ".");
				strDefaultText = strDefaultText.Substring(strDefaultText.LastIndexOf("!") + 1).Replace("@", "");
				if (!text3.Contains("."))
				{
					text = "Top.appModelV8." + text2 + "." + text3;
				}
				else
				{
					text = text3.Substring(0, text3.LastIndexOf("."));
					text = text.Replace(".", ".Data.Blocks.");
					text = text + ".Data." + text2 + "." + text3.Substring(text3.LastIndexOf(".") + 1);
					if (text.StartsWith("Data."))
					{
						text = text.Substring(5);
					}
					text = "Top.appModelV8.Blocks." + text;
				}
			}
			else
			{
				text2 = "Streams";
				strDefaultText = strDefaultText.Substring(strDefaultText.LastIndexOf("!") + 1).Replace("@", "");
			}
			OneIdDialog oneIdDialog = new OneIdDialog(container, strPrompt, strDefaultText, null, mask);
			oneIdDialog.Title = strCaption;
			if (flag)
			{
				oneIdDialog.ExistingIds = ExistingIds(text.Substring(0, text.LastIndexOf(".") + 1), mMViewModel);
				oneIdDialog.PathCheck = text.Substring(0, text.LastIndexOf("."));
				oneIdDialog.Provider = mMViewModel.ResolvedCxsProvider;
				if (oneIdDialog.ExistingIds != null && strDefaultText != null && oneIdDialog.ExistingIds.Contains(strDefaultText))
				{
					oneIdDialog.ExistingIds.Remove(strDefaultText);
				}
			}
			PFSCommonDialogs.SetOwningWindow(oneIdDialog);
			bool value = oneIdDialog.ShowDialog().Value;
			strTextInput = oneIdDialog.NewID;
			return value ? 1 : 0;
		}

		private void RefreshUnits(IUnityContainer uContainer)
		{
			CxsDataProvider cxsDataProvider = uContainer.Resolve<CxsDataProvider>(Array.Empty<ResolverOverride>());
			string path = "Top.appModelV8.Setup.Global.Input.INSET";
			string attribute = "value";
			string value = CxsConverter.ValueToString(cxsDataProvider.BatchGet(path, attribute, null));
			if (!string.IsNullOrEmpty(value))
			{
				HelperFuncs.SetForceRefreshForms(0);
				cxsDataProvider.BatchSet(path, attribute, null, "ENG");
				cxsDataProvider.BatchSet(path, attribute, null, value);
			}
		}

		[DispId(150)]
		public int ShowUniversalPortDialog(string strPortList, out int iPortIndex)
		{
			PFSUniversalPortDialog pFSUniversalPortDialog = new PFSUniversalPortDialog();
			PFSCommonDialogs.SetOwningWindow(pFSUniversalPortDialog);
			int num = 0;
			while (num >= 0)
			{
				string empty = string.Empty;
				int num2 = num;
				num = strPortList.IndexOf(";", num2);
				if (num < 0)
				{
					empty = strPortList.Substring(num2);
				}
				else
				{
					empty = strPortList.Substring(num2, num - num2);
					num++;
				}
				if (empty.Length > 0)
				{
					pFSUniversalPortDialog.PortsList.Add(empty);
				}
			}
			bool value = pFSUniversalPortDialog.ShowDialog().Value;
			iPortIndex = pFSUniversalPortDialog.SelectedPort;
			return value ? 1 : 0;
		}

		[DispId(160)]
		public void ShowUnplacedBlocksDialog(object pfs)
		{
			if (m_dlgUnplacedBlocksDialog == null)
			{
				m_dlgUnplacedBlocksDialog = new PFSUnplacedBlocksDialog();
			}
			if (!m_dlgUnplacedBlocksDialog.DialogOpen)
			{
				PFSCommonDialogs.SetOwningWindow(m_dlgUnplacedBlocksDialog);
				m_dlgUnplacedBlocksDialog.PfsObject = pfs;
				m_dlgUnplacedBlocksDialog.Show();
			}
		}

		[DispId(161)]
		public void CloseUnplacedBlocksDialog(int bPlaceAllOnClose)
		{
			if (m_dlgUnplacedBlocksDialog != null && m_dlgUnplacedBlocksDialog.DialogOpen)
			{
				m_dlgUnplacedBlocksDialog.PlaceAllOnClose = bPlaceAllOnClose != 0;
				m_dlgUnplacedBlocksDialog.Close();
			}
		}

		[DispId(162)]
		public void UnplacedBlocksDialogAddBlock(string strBlock)
		{
			if (m_dlgUnplacedBlocksDialog == null)
			{
				m_dlgUnplacedBlocksDialog = new PFSUnplacedBlocksDialog();
			}
			m_dlgUnplacedBlocksDialog.UnplacedBlocksList.InsertSorted(strBlock);
		}

		[DispId(163)]
		public void UnplacedBlocksDialogRemoveBlock(string strBlock)
		{
			if (m_dlgUnplacedBlocksDialog != null)
			{
				m_dlgUnplacedBlocksDialog.UnplacedBlocksList.Remove(strBlock);
			}
		}

		[DispId(170)]
		public void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked, string strSubject)
		{
			if (m_dlgCommonDialogs == null)
			{
				m_dlgCommonDialogs = new PFSCommonDialogs();
			}
			m_dlgCommonDialogs.AddItem(sUID, nCmdId, sItem, sIcon, bEnabled, bChecked, strSubject);
		}

		[DispId(171)]
		public void ShowMenu(object pfs)
		{
			if (m_dlgCommonDialogs != null)
			{
				m_dlgCommonDialogs.ShowMenu(pfs);
			}
		}

		[DispId(180)]
		public int ShowControlVariablesListDialog(int bProcVars, string sVarDescList, out string sControlVarName)
		{
			ControlVariableListDialog controlVariableListDialog = new ControlVariableListDialog(bProcVars != 0, sVarDescList);
			PFSCommonDialogs.SetOwningWindow(controlVariableListDialog);
			bool? flag = controlVariableListDialog.ShowDialog();
			sControlVarName = controlVariableListDialog.sControlVariableName;
			return (flag == true) ? 1 : 0;
		}
	}
	[Guid("CA5D98F7-50C3-4672-AF58-8A7743770389")]
	[ComVisible(true)]
	[InterfaceType(ComInterfaceType.InterfaceIsDual)]
	public interface IPFSIconEditorDialogs
	{
		int MessageBox(string contents, string caption, int buttons, int image);

		int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput);

		int ShowIconImportDXFDialog();

		void IconImportAddBlockText(string strBlockText);

		void IconImportAddEditText(string strEditText);

		int IconImportGetSelectedCount();

		int IconImportGetChecked();

		int IconImportGetEditString(out string strText);

		int IconImportGetBlockName(int iIndex, out string strBlockName);

		void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked);

		void ShowMenu(object pfs);
	}
	[ComVisible(true)]
	[Guid("B0E2BE84-76BD-4764-9D3A-BD94B205B912")]
	[ProgId("AspenTech.AspenPlus.PfsDialogs.PFSIconEditorDialogs.410")]
	[ClassInterface(ClassInterfaceType.AutoDual)]
	public class PFSIconEditorDialogs : IPFSIconEditorDialogs
	{
		private PFSIconImportDXFDialog m_dlgIconImportDXFDialog;

		private PFSCommonDialogs m_dlgCommonDialogs;

		[DispId(1)]
		public int MessageBox(string contents, string caption, int buttons, int image)
		{
			return new PFSCommonDialogs().MessageBox(contents, caption, buttons, image);
		}

		[DispId(2)]
		public int ShowTextInputDialog(string strCaption, string strPrompt, string strDefaultText, int iUpper, int nLength, out string strTextInput)
		{
			return new PFSCommonDialogs().ShowTextInputDialog(strCaption, strPrompt, strDefaultText, iUpper, nLength, out strTextInput);
		}

		[DispId(10)]
		public int ShowIconImportDXFDialog()
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				m_dlgIconImportDXFDialog = new PFSIconImportDXFDialog();
			}
			PFSCommonDialogs.SetOwningWindow(m_dlgIconImportDXFDialog);
			return m_dlgIconImportDXFDialog.ShowDialog().Value ? 1 : 0;
		}

		[DispId(11)]
		public void IconImportAddBlockText(string strBlockText)
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				m_dlgIconImportDXFDialog = new PFSIconImportDXFDialog();
			}
			m_dlgIconImportDXFDialog.BlockList.Add(new PFSIconImportDXFDialog.BlockLT
			{
				BlockText = strBlockText
			});
		}

		[DispId(12)]
		public void IconImportAddEditText(string strEditText)
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				m_dlgIconImportDXFDialog = new PFSIconImportDXFDialog();
			}
			m_dlgIconImportDXFDialog.sEditString = strEditText;
		}

		[DispId(13)]
		public int IconImportGetSelectedCount()
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				return 0;
			}
			return m_dlgIconImportDXFDialog.iNumSelected;
		}

		[DispId(14)]
		public int IconImportGetChecked()
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				return 0;
			}
			return m_dlgIconImportDXFDialog.iChecked;
		}

		[DispId(15)]
		public int IconImportGetEditString(out string strText)
		{
			if (m_dlgIconImportDXFDialog == null)
			{
				strText = string.Empty;
				return 0;
			}
			if (m_dlgIconImportDXFDialog.iChecked == 0)
			{
				strText = string.Empty;
				return 0;
			}
			strText = m_dlgIconImportDXFDialog.sEditString;
			return 1;
		}

		[DispId(16)]
		public int IconImportGetBlockName(int iIndex, out string strBlockName)
		{
			if (m_dlgIconImportDXFDialog == null || iIndex < 0)
			{
				strBlockName = string.Empty;
				return 0;
			}
			if (m_dlgIconImportDXFDialog.iNumSelected == 0)
			{
				strBlockName = "";
				return 0;
			}
			strBlockName = m_dlgIconImportDXFDialog.SelectedBlockList[iIndex];
			return 1;
		}

		[DispId(20)]
		public void AddItem(string sUID, int nCmdId, string sItem, string sIcon, int bEnabled, int bChecked)
		{
			if (m_dlgCommonDialogs == null)
			{
				m_dlgCommonDialogs = new PFSCommonDialogs();
			}
			m_dlgCommonDialogs.AddItem(sUID, nCmdId, sItem, sIcon, bEnabled, bChecked, "");
		}

		[DispId(21)]
		public void ShowMenu(object pfs)
		{
			if (m_dlgCommonDialogs != null)
			{
				m_dlgCommonDialogs.ShowMenu(pfs);
			}
		}
	}
	[Module(ModuleName = "AspenTech.AspenPlus.PfsDialogs.PfsDialogsModule")]
	public class PfsDialogsModule : IModule
	{
		public const string ModuleName = "AspenTech.AspenPlus.PfsDialogs.PfsDialogsModule";

		public static IUnityContainer Container { get; private set; }

		public PfsDialogsModule(IUnityContainer container)
		{
			Container = container;
		}

		public void Initialize()
		{
		}
	}
	public class PFSBookmarksDialog : Window, IComponentConnector
	{
		internal StackPanel stackPanel5;

		internal StackPanel stackPanel1;

		internal StackPanel stackPanel2;

		internal StackPanel stackPanel4;

		internal Label label1;

		internal ComboBox comboBox1;

		internal ListBox listBox1;

		internal StackPanel stackPanel3;

		internal Button addBtn;

		internal Button closeBtn;

		internal Button deleteBtn;

		internal Button gotoBtn;

		internal StackPanel stackPanel6;

		internal Label label2;

		internal Label regionText;

		private bool _contentLoaded;

		public BookmarkCollection BookmarkList { get; set; }

		public string BookmarkName { get; set; }

		public Rect CurrentRegion { get; set; }

		public float CurrentScale { get; set; }

		public PFSBookmarksDialog()
		{
			InitializeComponent();
			BookmarkList = new BookmarkCollection();
			BookmarkName = string.Empty;
			CurrentRegion = new Rect(0.0, 0.0, 1.0, 1.0);
			CurrentScale = 1f;
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			addBtn.IsEnabled = false;
			deleteBtn.IsEnabled = false;
			gotoBtn.IsEnabled = false;
		}

		private void OnClickAdd(object sender, RoutedEventArgs e)
		{
			if (BookmarkName.Length != 0 && BookmarkList.FindExact(BookmarkName) < 0)
			{
				BookmarkEntry entry = new BookmarkEntry(BookmarkName, CurrentScale, CurrentRegion);
				int num = BookmarkList.InsertSorted(entry);
				listBox1.SelectedIndex = num;
				comboBox1.SelectedIndex = -1;
				BookmarkName = string.Empty;
				addBtn.IsEnabled = false;
				deleteBtn.IsEnabled = true;
				gotoBtn.IsEnabled = true;
				regionText.Content = BookmarkList[num].RegionText;
			}
		}

		private void OnClickDelete(object sender, RoutedEventArgs e)
		{
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0 && selectedIndex < BookmarkList.Count())
			{
				BookmarkList.RemoveAt(selectedIndex);
			}
			BookmarkName = string.Empty;
		}

		private void OnClickClose(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		private void OnClickGoTo(object sender, RoutedEventArgs e)
		{
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0 && selectedIndex < BookmarkList.Count())
			{
				CurrentScale = BookmarkList[selectedIndex].Scale;
				CurrentRegion = BookmarkList[selectedIndex].Region;
				BookmarkName = BookmarkList[selectedIndex].Name;
				base.DialogResult = true;
				Close();
			}
		}

		private void OnListDoubleClick(object sender, MouseButtonEventArgs e)
		{
			OnClickGoTo(sender, null);
		}

		private void OnListSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0)
			{
				comboBox1.SelectedIndex = selectedIndex;
			}
			OnListOrCombSelectionChanged();
		}

		private void OnComboSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			int selectedIndex = comboBox1.SelectedIndex;
			if (selectedIndex >= 0)
			{
				listBox1.SelectedIndex = selectedIndex;
			}
			OnListOrCombSelectionChanged();
		}

		private void OnListOrCombSelectionChanged()
		{
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0 && selectedIndex < BookmarkList.Count())
			{
				if (comboBox1.SelectedIndex < 0)
				{
					BookmarkName = string.Empty;
				}
				else
				{
					BookmarkName = BookmarkList[selectedIndex].Name;
				}
				regionText.Content = BookmarkList[selectedIndex].RegionText;
			}
			addBtn.IsEnabled = false;
			deleteBtn.IsEnabled = selectedIndex >= 0;
			gotoBtn.IsEnabled = selectedIndex >= 0;
		}

		private void OnTextChanged(object sender, KeyEventArgs e)
		{
			addBtn.IsEnabled = BookmarkName.Length != 0;
			int num = -1;
			if (BookmarkName.Length > 0)
			{
				num = BookmarkList.FindPartial(BookmarkName);
			}
			gotoBtn.IsEnabled = num >= 0;
			if (num >= 0)
			{
				listBox1.SelectedIndex = num;
			}
		}

		private void comboBox1_Loaded(object sender, RoutedEventArgs e)
		{
			if (sender is ComboBox comboBox)
			{
				TextBox textBox = (TextBox)comboBox.Template.FindName("PART_EditableTextBox", comboBox);
				if (textBox != null)
				{
					textBox.MaxLength = 21;
				}
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsbookmarksdialog.xaml", UriKind.Relative);
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
				((PFSBookmarksDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				stackPanel5 = (StackPanel)target;
				break;
			case 3:
				stackPanel1 = (StackPanel)target;
				break;
			case 4:
				stackPanel2 = (StackPanel)target;
				break;
			case 5:
				stackPanel4 = (StackPanel)target;
				break;
			case 6:
				label1 = (Label)target;
				break;
			case 7:
				comboBox1 = (ComboBox)target;
				comboBox1.Loaded += comboBox1_Loaded;
				comboBox1.SelectionChanged += OnComboSelectionChanged;
				comboBox1.KeyUp += OnTextChanged;
				break;
			case 8:
				listBox1 = (ListBox)target;
				listBox1.SelectionChanged += OnListSelectionChanged;
				listBox1.MouseDoubleClick += OnListDoubleClick;
				break;
			case 9:
				stackPanel3 = (StackPanel)target;
				break;
			case 10:
				addBtn = (Button)target;
				addBtn.Click += OnClickAdd;
				break;
			case 11:
				closeBtn = (Button)target;
				closeBtn.Click += OnClickClose;
				break;
			case 12:
				deleteBtn = (Button)target;
				deleteBtn.Click += OnClickDelete;
				break;
			case 13:
				gotoBtn = (Button)target;
				gotoBtn.Click += OnClickGoTo;
				break;
			case 14:
				stackPanel6 = (StackPanel)target;
				break;
			case 15:
				label2 = (Label)target;
				break;
			case 16:
				regionText = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class BookmarkEntry
	{
		public string Name { get; set; }

		public float Scale { get; set; }

		public Rect Region { get; set; }

		public string RegionText => "(" + Region.Left.ToString("0.0") + "," + Region.Top.ToString("0.0") + ") --> (" + Region.Right.ToString("0.0") + "," + Region.Bottom.ToString("0.0") + ")";

		public BookmarkEntry(string name, float scale, Rect region)
		{
			Name = name;
			Scale = scale;
			Region = region;
		}
	}
	public class BookmarkCollection : ObservableCollection<BookmarkEntry>
	{
		public int InsertSorted(BookmarkEntry entry)
		{
			int result = -1;
			bool flag = false;
			for (int i = 0; i < this.Count(); i++)
			{
				int num = entry.Name.CompareTo(base[i].Name);
				if (num == 0)
				{
					flag = true;
					base[i].Region = entry.Region;
					base[i].Scale = entry.Scale;
					result = i;
					break;
				}
				if (num < 0)
				{
					Insert(i, entry);
					flag = true;
					result = i;
					break;
				}
			}
			if (!flag)
			{
				Add(entry);
				result = this.Count() - 1;
			}
			return result;
		}

		public int FindExact(string name)
		{
			bool flag = false;
			int i;
			for (i = 0; i < this.Count(); i++)
			{
				int num = name.CompareTo(base[i].Name);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					break;
				}
			}
			if (flag)
			{
				return i;
			}
			return -1;
		}

		public int FindPartial(string name)
		{
			bool flag = false;
			int i;
			for (i = 0; i < this.Count(); i++)
			{
				int num = name.CompareTo(base[i].Name);
				if (num <= 0)
				{
					if (num == 0 || base[i].Name.StartsWith(name))
					{
						flag = true;
					}
					break;
				}
			}
			if (flag)
			{
				return i;
			}
			return -1;
		}
	}
	public class PFSFindObjectsDialog : Window, IComponentConnector
	{
		private static string m_strCurrentBlockFilter = string.Empty;

		private static string m_strCurrentStreamFilter = string.Empty;

		private bool bFilterChanged;

		private bool bRefreshInProgress;

		private SortedNameList BlocksList;

		private SortedNameList StreamsList;

		private HierarchyItem CurHierarchy;

		private string sRootName = string.Empty;

		private static double lastLeft;

		private static double lastTop;

		private static double lastWidth;

		private static double lastHeight;

		internal Grid Grid1;

		internal Label HierarchyLabel;

		internal TreeView HierarchyTreeView;

		internal Label BlocksLabel;

		internal ListBox BlocksListBox;

		internal Label StreamsLabel;

		internal ListBox StreamsListBox;

		internal Grid OptionsStackPanel;

		internal CheckBox SubHierarchiesCheckBox;

		internal CheckBox CenterViewCheckBox;

		internal CheckBox ZoomViewCheckBox;

		internal Grid BlockFilterStackPanel;

		internal Label BlockFilterLabel;

		internal ComboBox BlockFilterComboBox;

		internal Grid StreamFilterStackPanel;

		internal Label StreamFilterLabel;

		internal ComboBox StreamFilterComboBox;

		internal StackPanel ButtonsStackPanel;

		internal Button ApplyFiltersButton;

		internal Button FindButton;

		internal Button CloseButton;

		private bool _contentLoaded;

		public int ClientType { get; set; }

		public bool CenterView { get; set; }

		public bool ZoomView { get; set; }

		public bool ShowSubHierarchies { get; set; }

		public bool PFDMode { get; set; }

		public bool IsDialogOpen { get; private set; }

		public string BlockFilter { get; set; }

		public string StreamFilter { get; set; }

		public object PFSObject { get; set; }

		public HierarchyItemList HierarchyList { get; set; }

		public ObjectNameList BlocksListFiltered { get; set; }

		public ObjectNameList StreamsListFiltered { get; set; }

		public ObservableCollection<string> BlockFilterList { get; set; }

		public ObservableCollection<string> StreamFilterList { get; set; }

		public PFSFindObjectsDialog()
		{
			InitializeComponent();
			IsDialogOpen = false;
			BlockFilter = string.Empty;
			StreamFilter = string.Empty;
			HierarchyList = new HierarchyItemList();
			BlocksListFiltered = new ObjectNameList();
			StreamsListFiltered = new ObjectNameList();
			BlocksList = new SortedNameList();
			StreamsList = new SortedNameList();
			BlockFilterList = new ObservableCollection<string>();
			StreamFilterList = new ObservableCollection<string>();
		}

		public void SetCurrentHierarchy(string sCurHierarchy)
		{
			int num = HierarchyList.Find(sCurHierarchy);
			if (num >= 0)
			{
				CurHierarchy = HierarchyList[num];
			}
		}

		public void Refresh(bool bRefreshHierarchy)
		{
			if (!IsDialogOpen || bRefreshInProgress)
			{
				return;
			}
			bRefreshInProgress = true;
			if (bRefreshHierarchy)
			{
				int num = 0;
				HierarchyTreeView.Items.Clear();
				TreeViewItem treeViewItem = new TreeViewItem();
				TreeViewItem treeViewItem2 = null;
				treeViewItem.Header = sRootName;
				HierarchyTreeView.Items.Add(treeViewItem);
				if (CurHierarchy.Name.Length == 0)
				{
					treeViewItem2 = treeViewItem;
				}
				TreeViewItem treeViewItem3 = treeViewItem;
				for (int i = 1; i < HierarchyList.Count; i++)
				{
					int num2 = 0;
					for (int num3 = HierarchyList[i].Name.IndexOf(".", 0); num3 >= 0; num3 = HierarchyList[i].Name.IndexOf(".", num3 + 1))
					{
						num2++;
					}
					if (num2 > num)
					{
						treeViewItem3 = treeViewItem;
						num++;
					}
					while (num2 < num)
					{
						treeViewItem3.IsExpanded = true;
						treeViewItem3 = (TreeViewItem)treeViewItem3.Parent;
						num--;
					}
					string name = HierarchyList[i].Name;
					int num4 = name.LastIndexOf(".");
					treeViewItem = new TreeViewItem();
					treeViewItem.Header = ((num4 >= 0) ? name.Substring(num4 + 1) : name);
					string customTooltipText = CustomTooltipHelper.GetCustomTooltipText("Blocks." + name.Replace(".", ".Data.Blocks."));
					treeViewItem.ToolTip = customTooltipText;
					treeViewItem3.Items.Add(treeViewItem);
					if (HierarchyList[i].Name == CurHierarchy.Name)
					{
						treeViewItem2 = treeViewItem;
					}
				}
				while (treeViewItem3 != null)
				{
					treeViewItem3.IsExpanded = true;
					object parent = treeViewItem3.Parent;
					treeViewItem3 = ((!(parent.GetType() == treeViewItem3.GetType())) ? null : ((TreeViewItem)parent));
				}
				if (PFDMode)
				{
					HierarchyTreeView.IsEnabled = false;
					SubHierarchiesCheckBox.IsEnabled = false;
				}
				if (treeViewItem2 != null)
				{
					treeViewItem2.IsSelected = true;
				}
			}
			BlocksListFiltered.Clear();
			StreamsListFiltered.Clear();
			if (ShowSubHierarchies)
			{
				string text = CurHierarchy.Name;
				if (text.Length > 0)
				{
					text += ".";
				}
				int length = text.Length;
				for (int j = 0; j < HierarchyList.Count; j++)
				{
					string name2 = HierarchyList[j].Name;
					if (name2 != CurHierarchy.Name && (name2.Length < length || name2.Substring(0, length) != text))
					{
						continue;
					}
					GetBlocksAndStreams(HierarchyList[j]);
					string text2 = string.Empty;
					if (name2 != CurHierarchy.Name)
					{
						text2 = name2.Substring(length);
					}
					for (int k = 0; k < BlocksList.Count; k++)
					{
						if (MatchFilter(BlocksList[k], BlockFilter))
						{
							string name3 = ((text2.Length <= 0) ? BlocksList[k] : (text2 + "." + BlocksList[k]));
							NameListItem nameListItem = new NameListItem(name3, text2.Length);
							string text3 = (string.IsNullOrEmpty(name2) ? string.Empty : ("Blocks." + name2.Replace(".", ".Data.Blocks.") + ".Data."));
							nameListItem.TooltipText = CustomTooltipHelper.GetCustomTooltipText(text3 + "Blocks." + BlocksList[k]);
							BlocksListFiltered.InsertSorted(nameListItem);
						}
					}
					for (int l = 0; l < StreamsList.Count; l++)
					{
						if (MatchFilter(StreamsList[l], StreamFilter))
						{
							string name4 = ((text2.Length <= 0) ? StreamsList[l] : (text2 + "." + StreamsList[l]));
							NameListItem nameListItem2 = new NameListItem(name4, text2.Length);
							string text4 = (string.IsNullOrEmpty(name2) ? string.Empty : ("Blocks." + name2.Replace(".", ".Data.Blocks.") + ".Data."));
							nameListItem2.TooltipText = CustomTooltipHelper.GetCustomTooltipText(text4 + "Streams." + StreamsList[l]);
							StreamsListFiltered.InsertSorted(nameListItem2);
						}
					}
				}
			}
			else
			{
				GetBlocksAndStreams(CurHierarchy);
				for (int m = 0; m < BlocksList.Count; m++)
				{
					if (MatchFilter(BlocksList[m], BlockFilter))
					{
						NameListItem nameListItem3 = new NameListItem(BlocksList[m], 0);
						string text5 = (string.IsNullOrEmpty(CurHierarchy.Name) ? string.Empty : ("Blocks." + CurHierarchy.Name.Replace(".", ".Data.Blocks.") + ".Data."));
						nameListItem3.TooltipText = CustomTooltipHelper.GetCustomTooltipText(text5 + "Blocks." + BlocksList[m]);
						BlocksListFiltered.InsertSorted(nameListItem3);
					}
				}
				for (int n = 0; n < StreamsList.Count; n++)
				{
					if (MatchFilter(StreamsList[n], StreamFilter))
					{
						NameListItem nameListItem4 = new NameListItem(StreamsList[n], 0);
						string text6 = (string.IsNullOrEmpty(CurHierarchy.Name) ? string.Empty : ("Blocks." + CurHierarchy.Name.Replace(".", ".Data.Blocks.") + ".Data."));
						nameListItem4.TooltipText = CustomTooltipHelper.GetCustomTooltipText(text6 + "Streams." + StreamsList[n]);
						StreamsListFiltered.InsertSorted(nameListItem4);
					}
				}
			}
			BlocksListBox.SelectedIndex = -1;
			StreamsListBox.SelectedIndex = -1;
			FindButton.IsEnabled = false;
			if (BlockFilterComboBox.Items.Contains(BlockFilter) && StreamFilterComboBox.Items.Contains(StreamFilter))
			{
				ApplyFiltersButton.IsEnabled = false;
			}
			bRefreshInProgress = false;
		}

		private void GetBlocksAndStreams(HierarchyItem hierItem)
		{
			BlocksList.Clear();
			StreamsList.Clear();
			string blockList = hierItem.BlockList;
			string streamList = hierItem.StreamList;
			int num = 0;
			while (num >= 0)
			{
				string empty = string.Empty;
				int num2 = num;
				num = blockList.IndexOf(";", num2);
				if (num < 0)
				{
					empty = blockList.Substring(num2);
				}
				else
				{
					empty = blockList.Substring(num2, num - num2);
					num++;
				}
				if (empty.Length > 0)
				{
					BlocksList.Add(empty);
				}
			}
			int num3 = 0;
			while (num3 >= 0)
			{
				string empty2 = string.Empty;
				int num4 = num3;
				num3 = streamList.IndexOf(";", num4);
				if (num3 < 0)
				{
					empty2 = streamList.Substring(num4);
				}
				else
				{
					empty2 = streamList.Substring(num4, num3 - num4);
					num3++;
				}
				if (empty2.Length > 0)
				{
					StreamsList.Add(empty2);
				}
			}
		}

		private bool MatchFilter(string sName, string sFilter)
		{
			Collection<string> collection = new Collection<string>();
			if (sFilter.Length <= 0)
			{
				sFilter = "*";
			}
			sName.ToUpper();
			sFilter.ToUpper();
			int length = sFilter.Length;
			int i;
			for (i = 0; i < length; i++)
			{
				if (sFilter[i] != '*')
				{
					int num = sFilter.IndexOf('*', i);
					if (num <= i)
					{
						collection.Add(sFilter.Substring(i));
						break;
					}
					collection.Add(sFilter.Substring(i, num - i));
					i = num;
				}
			}
			bool flag = sFilter[0] != '*';
			bool flag2 = sFilter[length - 1] != '*';
			bool result = true;
			length = sName.Length;
			int num2 = 0;
			for (i = 0; i < length; i++)
			{
				if (num2 >= collection.Count)
				{
					break;
				}
				if (collection[num2][0] == '?' || sName[i] == collection[num2][0])
				{
					int length2 = collection[num2].Length;
					if (i + length2 > length)
					{
						result = false;
						break;
					}
					int j;
					for (j = 1; j < length2 && (collection[num2][j] == '?' || sName[i + j] == collection[num2][j]); j++)
					{
					}
					if (j >= length2)
					{
						if (!((num2 > 0 || !flag) && num2 == collection.Count - 1 && flag2) || i + length2 >= length)
						{
							num2++;
							i += length2;
						}
					}
					else if (num2 == 0 && flag)
					{
						result = false;
						break;
					}
				}
				else if (i == 0 && flag)
				{
					result = false;
					break;
				}
			}
			if (num2 < collection.Count)
			{
				return false;
			}
			if (flag2 && i < length)
			{
				return false;
			}
			return result;
		}

		private void SaveFilters()
		{
			int num = BlockFilterList.IndexOf(BlockFilter.ToUpper());
			if (num >= 0)
			{
				BlockFilterComboBox.SelectedIndex = num;
			}
			else
			{
				BlockFilterList.Insert(0, BlockFilter.ToUpper());
				BlockFilterComboBox.SelectedIndex = 0;
			}
			num = StreamFilterList.IndexOf(StreamFilter.ToUpper());
			if (num >= 0)
			{
				StreamFilterComboBox.SelectedIndex = num;
				return;
			}
			StreamFilterList.Insert(0, StreamFilter.ToUpper());
			StreamFilterComboBox.SelectedIndex = 0;
		}

		private void SaveSettings()
		{
			if (PFSObject != null)
			{
				string text = string.Empty;
				for (int i = 0; i < BlockFilterList.Count; i++)
				{
					text = text + BlockFilterList[i] + ";";
				}
				string text2 = string.Empty;
				for (int j = 0; j < StreamFilterList.Count; j++)
				{
					text2 = text2 + StreamFilterList[j] + ";";
				}
				object[] args = new object[4]
				{
					CenterView ? 1 : 0,
					ZoomView ? 1 : 0,
					text,
					text2
				};
				PFSObject.GetType().InvokeMember("SaveFindObjectSettings", BindingFlags.InvokeMethod, null, PFSObject, args);
			}
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			if (lastLeft != 0.0)
			{
				base.Left = lastLeft;
				base.Top = lastTop;
				base.Width = lastWidth;
				base.Height = lastHeight;
			}
			SetComboBoxTextToUpperCase(BlockFilterComboBox);
			SetComboBoxTextToUpperCase(StreamFilterComboBox);
			IsDialogOpen = true;
			if (BlockFilterList.Count == 0)
			{
				BlockFilterList.Add("*");
			}
			int num = -1;
			num = BlockFilterList.IndexOf(m_strCurrentBlockFilter);
			BlockFilter = ((num > 0) ? BlockFilterList[num] : BlockFilterList[0]);
			BlockFilterComboBox.SelectedIndex = ((num > 0) ? num : 0);
			if (StreamFilterList.Count == 0)
			{
				StreamFilterList.Add("*");
			}
			int num2 = -1;
			num2 = StreamFilterList.IndexOf(m_strCurrentStreamFilter);
			StreamFilter = ((num2 > 0) ? StreamFilterList[num2] : StreamFilterList[0]);
			StreamFilterComboBox.SelectedIndex = ((num2 > 0) ? num2 : 0);
			sRootName = ((ClientType == 0) ? WpfPfsDialogsResources.PFSFindObjectsDialogRootFlowsheetAPlus : WpfPfsDialogsResources.PFSFindObjectsDialogRootFlowsheetACM);
			Refresh(bRefreshHierarchy: true);
		}

		private void OnDialogClosed(object sender, EventArgs e)
		{
			IsDialogOpen = false;
			if (PFSObject != null)
			{
				PFSObject.GetType().InvokeMember("FindObjectClosed", BindingFlags.InvokeMethod, null, PFSObject, null);
				PFSObject.GetType().InvokeMember("ResetFocus", BindingFlags.InvokeMethod, null, PFSObject, null);
			}
			lastLeft = base.Left;
			lastTop = base.Top;
			lastHeight = base.Height;
			lastWidth = base.Width;
		}

		private void OnClickClose(object sender, RoutedEventArgs e)
		{
			Close();
		}

		private void OnClickFind(object sender, RoutedEventArgs e)
		{
			string sFlowsheet = CurHierarchy.Name;
			string text = string.Empty;
			int num = 0;
			int selectedIndex = BlocksListBox.SelectedIndex;
			if (selectedIndex >= 0)
			{
				text = BlocksListFiltered[selectedIndex].Name;
				num = BlocksListFiltered[selectedIndex].PrefixLength;
			}
			else
			{
				selectedIndex = StreamsListBox.SelectedIndex;
				if (selectedIndex >= 0)
				{
					text = StreamsListFiltered[selectedIndex].Name;
					num = StreamsListFiltered[selectedIndex].PrefixLength;
				}
			}
			if (ShowSubHierarchies && num > 0)
			{
				sFlowsheet = ((CurHierarchy.Name.Length > 0) ? (CurHierarchy.Name + "." + text.Substring(0, num)) : text.Substring(0, num));
				text = text.Substring(num + 1);
			}
			FindSelectedObject(sFlowsheet);
		}

		private void FindSelectedObject(string sFlowsheet)
		{
			if (ShowScreen(sFlowsheet))
			{
				base.Dispatcher.BeginInvoke(new Action(SelectObject), DispatcherPriority.ApplicationIdle);
			}
			else
			{
				SelectObject();
			}
		}

		private void SelectObject()
		{
			string text = CurHierarchy.Name;
			string text2 = string.Empty;
			int num = 0;
			int num2 = 0;
			int selectedIndex = BlocksListBox.SelectedIndex;
			if (selectedIndex >= 0)
			{
				num2 = 1;
				text2 = BlocksListFiltered[selectedIndex].Name;
				num = BlocksListFiltered[selectedIndex].PrefixLength;
			}
			else
			{
				selectedIndex = StreamsListBox.SelectedIndex;
				if (selectedIndex >= 0)
				{
					num2 = 2;
					text2 = StreamsListFiltered[selectedIndex].Name;
					num = StreamsListFiltered[selectedIndex].PrefixLength;
				}
			}
			if (ShowSubHierarchies && num > 0)
			{
				text = ((CurHierarchy.Name.Length > 0) ? (CurHierarchy.Name + "." + text2.Substring(0, num)) : text2.Substring(0, num));
				text2 = text2.Substring(num + 1);
			}
			if (num2 > 0 && PFSObject != null)
			{
				object[] args = new object[5]
				{
					text,
					text2,
					num2,
					CenterView ? 1 : 0,
					ZoomView ? 1 : 0
				};
				if (PFSObject != null)
				{
					PFSObject.GetType().InvokeMember("SelectObject", BindingFlags.InvokeMethod, null, PFSObject, args);
				}
			}
		}

		private bool ShowScreen(string hierName)
		{
			bool result = false;
			IApwnDocument apwnDocument = PfsDialogsModule.Container.Resolve<IApwnDocument>(Array.Empty<ResolverOverride>());
			if (apwnDocument != null)
			{
				result = apwnDocument.ShowHierarchyScreen(hierName);
			}
			return result;
		}

		private void OnClickApplyFilters(object sender, RoutedEventArgs e)
		{
			if (bFilterChanged)
			{
				SaveCurrentFilters();
				SaveFilters();
				Refresh(bRefreshHierarchy: false);
				bFilterChanged = false;
				SaveSettings();
			}
		}

		private void SaveCurrentFilters()
		{
			if (string.IsNullOrEmpty(BlockFilter))
			{
				BlockFilter = "*";
			}
			if (string.IsNullOrEmpty(StreamFilter))
			{
				StreamFilter = "*";
			}
			m_strCurrentBlockFilter = BlockFilter;
			m_strCurrentStreamFilter = StreamFilter;
		}

		private void OnBlockFilterSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (IsDialogOpen)
			{
				int selectedIndex = BlockFilterComboBox.SelectedIndex;
				if (selectedIndex >= 0)
				{
					BlockFilter = BlockFilterList[selectedIndex];
					Refresh(bRefreshHierarchy: false);
					bFilterChanged = false;
					m_strCurrentBlockFilter = BlockFilter;
				}
			}
		}

		private void OnStreamFilterSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (IsDialogOpen)
			{
				int selectedIndex = StreamFilterComboBox.SelectedIndex;
				if (selectedIndex >= 0)
				{
					StreamFilter = StreamFilterList[selectedIndex];
					Refresh(bRefreshHierarchy: false);
					bFilterChanged = false;
					m_strCurrentStreamFilter = StreamFilter;
				}
			}
		}

		private void OnFilterTextChanged(object sender, KeyEventArgs e)
		{
			if (IsDialogOpen)
			{
				bFilterChanged = true;
				FindButton.IsEnabled = false;
				ApplyFiltersButton.IsEnabled = true;
				BlockFilter = BlockFilterComboBox.Text.ToUpper();
				StreamFilter = StreamFilterComboBox.Text.ToUpper();
			}
		}

		private void OnHierarchySelected(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (!IsDialogOpen || HierarchyTreeView.Items.Count <= 0)
			{
				return;
			}
			TreeViewItem treeViewItem = (TreeViewItem)e.NewValue;
			string text = treeViewItem.Header.ToString();
			if (text == sRootName)
			{
				text = string.Empty;
			}
			object parent = treeViewItem.Parent;
			while (parent.GetType() == treeViewItem.GetType())
			{
				treeViewItem = (TreeViewItem)parent;
				string text2 = treeViewItem.Header.ToString();
				if (text2 == sRootName)
				{
					break;
				}
				text = text2 + "." + text;
				parent = treeViewItem.Parent;
			}
			int num = HierarchyList.Find(text);
			if (num >= 0)
			{
				CurHierarchy = HierarchyList[num];
			}
			if (bFilterChanged)
			{
				SaveCurrentFilters();
				SaveFilters();
				bFilterChanged = false;
				SaveSettings();
			}
			Refresh(bRefreshHierarchy: false);
		}

		private void OnBlockSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (IsDialogOpen && BlocksListBox.SelectedIndex >= 0)
			{
				StreamsListBox.SelectedIndex = -1;
				FindButton.IsEnabled = true;
			}
		}

		private void OnStreamSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (IsDialogOpen && StreamsListBox.SelectedIndex >= 0)
			{
				BlocksListBox.SelectedIndex = -1;
				FindButton.IsEnabled = true;
			}
		}

		private void OnClickedShowSubHier(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				if (bFilterChanged)
				{
					SaveCurrentFilters();
					SaveFilters();
					bFilterChanged = false;
					SaveSettings();
				}
				Refresh(bRefreshHierarchy: false);
			}
		}

		private void OnClickedCenterView(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				if (bFilterChanged)
				{
					SaveCurrentFilters();
					SaveFilters();
					Refresh(bRefreshHierarchy: false);
					bFilterChanged = false;
				}
				SaveSettings();
			}
		}

		private void OnClickedZoomView(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				if (bFilterChanged)
				{
					SaveCurrentFilters();
					SaveFilters();
					Refresh(bRefreshHierarchy: false);
					bFilterChanged = false;
				}
				SaveSettings();
				CenterViewCheckBox.IsEnabled = !ZoomView;
			}
		}

		private void OnBlockListDoubleClick(object sender, MouseButtonEventArgs e)
		{
			OnClickFind(sender, null);
		}

		private void OnStreamListDoubleClick(object sender, MouseButtonEventArgs e)
		{
			OnClickFind(sender, null);
		}

		private void SetComboBoxTextToUpperCase(ComboBox cmbCtrl)
		{
			if (Utilities.GetDescendantFromName(cmbCtrl, "PART_EditableTextBox") is TextBox textBox)
			{
				textBox.CharacterCasing = CharacterCasing.Upper;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsfindobjectsdialog.xaml", UriKind.Relative);
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
				((PFSFindObjectsDialog)target).Loaded += OnDialogLoaded;
				((PFSFindObjectsDialog)target).Closed += OnDialogClosed;
				break;
			case 2:
				Grid1 = (Grid)target;
				break;
			case 3:
				HierarchyLabel = (Label)target;
				break;
			case 4:
				HierarchyTreeView = (TreeView)target;
				HierarchyTreeView.SelectedItemChanged += OnHierarchySelected;
				break;
			case 5:
				BlocksLabel = (Label)target;
				break;
			case 6:
				BlocksListBox = (ListBox)target;
				BlocksListBox.SelectionChanged += OnBlockSelectionChanged;
				BlocksListBox.MouseDoubleClick += OnBlockListDoubleClick;
				break;
			case 7:
				StreamsLabel = (Label)target;
				break;
			case 8:
				StreamsListBox = (ListBox)target;
				StreamsListBox.SelectionChanged += OnStreamSelectionChanged;
				StreamsListBox.MouseDoubleClick += OnStreamListDoubleClick;
				break;
			case 9:
				OptionsStackPanel = (Grid)target;
				break;
			case 10:
				SubHierarchiesCheckBox = (CheckBox)target;
				SubHierarchiesCheckBox.Click += OnClickedShowSubHier;
				break;
			case 11:
				CenterViewCheckBox = (CheckBox)target;
				CenterViewCheckBox.Click += OnClickedCenterView;
				break;
			case 12:
				ZoomViewCheckBox = (CheckBox)target;
				ZoomViewCheckBox.Click += OnClickedZoomView;
				break;
			case 13:
				BlockFilterStackPanel = (Grid)target;
				break;
			case 14:
				BlockFilterLabel = (Label)target;
				break;
			case 15:
				BlockFilterComboBox = (ComboBox)target;
				BlockFilterComboBox.KeyUp += OnFilterTextChanged;
				BlockFilterComboBox.SelectionChanged += OnBlockFilterSelectionChanged;
				break;
			case 16:
				StreamFilterStackPanel = (Grid)target;
				break;
			case 17:
				StreamFilterLabel = (Label)target;
				break;
			case 18:
				StreamFilterComboBox = (ComboBox)target;
				StreamFilterComboBox.KeyUp += OnFilterTextChanged;
				StreamFilterComboBox.SelectionChanged += OnStreamFilterSelectionChanged;
				break;
			case 19:
				ButtonsStackPanel = (StackPanel)target;
				break;
			case 20:
				ApplyFiltersButton = (Button)target;
				ApplyFiltersButton.Click += OnClickApplyFilters;
				break;
			case 21:
				FindButton = (Button)target;
				FindButton.Click += OnClickFind;
				break;
			case 22:
				CloseButton = (Button)target;
				CloseButton.Click += OnClickClose;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SortedNameList : Collection<string>
	{
		public void InsertSorted(string block)
		{
			bool flag = false;
			for (int i = 0; i < this.Count(); i++)
			{
				int num = block.CompareTo(base[i]);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					Insert(i, block);
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				Add(block);
			}
		}
	}
	public class NameListItem : ObservableObject
	{
		private string _tooltipText;

		public string Name { get; set; }

		public int PrefixLength { get; set; }

		public string TooltipText
		{
			get
			{
				return _tooltipText;
			}
			set
			{
				if (value != _tooltipText)
				{
					_tooltipText = value;
					PropertyHasChange();
				}
			}
		}

		public NameListItem(string name, int nPrefixLength)
		{
			Name = name;
			PrefixLength = nPrefixLength;
		}
	}
	public class ObjectNameList : ObservableCollection<NameListItem>
	{
		public void InsertSorted(NameListItem item)
		{
			bool flag = false;
			for (int i = 0; i < this.Count(); i++)
			{
				int num = item.Name.CompareTo(base[i].Name);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					Insert(i, item);
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				Add(item);
			}
		}

		public int Find(string name)
		{
			bool flag = false;
			int i;
			for (i = 0; i < this.Count(); i++)
			{
				int num = name.CompareTo(base[i].Name);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					break;
				}
			}
			if (flag)
			{
				return i;
			}
			return -1;
		}
	}
	public class HierarchyItem : ObservableObject
	{
		private string _tooltipText;

		public string Name { get; set; }

		public string TooltipText
		{
			get
			{
				return _tooltipText;
			}
			set
			{
				if (value != _tooltipText)
				{
					_tooltipText = value;
					PropertyHasChange();
				}
			}
		}

		public string BlockList { get; set; }

		public string StreamList { get; set; }

		public HierarchyItem(string name, string sBlockList, string sStreamList)
		{
			Name = name;
			BlockList = sBlockList;
			StreamList = sStreamList;
		}
	}
	public class HierarchyItemList : Collection<HierarchyItem>
	{
		public void InsertSorted(HierarchyItem item)
		{
			bool flag = false;
			for (int i = 0; i < this.Count(); i++)
			{
				int num = item.Name.CompareTo(base[i].Name);
				if (num == 0)
				{
					flag = true;
					base[i] = item;
					break;
				}
				if (num < 0)
				{
					Insert(i, item);
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				Add(item);
			}
		}

		public int Find(string name)
		{
			bool flag = false;
			int i;
			for (i = 0; i < this.Count(); i++)
			{
				int num = string.Compare(name, base[i].Name);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					break;
				}
			}
			if (flag)
			{
				return i;
			}
			return -1;
		}
	}
	internal static class CustomTooltipHelper
	{
		private static CxsCase dataProvider = PfsDialogsModule.Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());

		public static string GetCustomTooltipText(string path)
		{
			if (string.IsNullOrEmpty(path))
			{
				return null;
			}
			string text = null;
			string text2 = "Top.appModelV8." + path;
			string path2 = CxvCustomTooltipHelper.ResolveDescriptionPath(text2);
			string text3 = null;
			string text4 = null;
			string path3 = text2;
			try
			{
				text3 = dataProvider.BatchGet(path2, "value", string.Empty) as string;
				text = dataProvider.BatchGet(text2, "type", string.Empty) as string;
				text4 = dataProvider.BatchGet(path3, "status", string.Empty) as string;
			}
			catch (Exception)
			{
			}
			if (string.IsNullOrEmpty(text3) && string.IsNullOrEmpty(text) && string.IsNullOrEmpty(text4))
			{
				int num = -1;
				while (true)
				{
					int num2 = path.IndexOf("Data.Blocks.", (num >= 0) ? (num + 12) : 0);
					if (num2 <= 0)
					{
						break;
					}
					num = num2;
				}
				string[] array = new string[4] { "Flowsheeting Options.Design-Spec.", "Flowsheeting Options.Calculator.", "Flowsheeting Options.Transfer.", "Flowsheeting Options.Measurement." };
				foreach (string text5 in array)
				{
					if (num >= 0)
					{
						string text6 = path.Substring(0, num) + path.Substring(num).Replace("Data.Blocks.", "Data." + text5);
						text2 = "Top.appModelV8." + text6;
					}
					else
					{
						text2 = "Top.appModelV8." + text5 + path.Replace("Blocks.", "");
					}
					path2 = CxvCustomTooltipHelper.ResolveDescriptionPath(text2);
					try
					{
						text3 = dataProvider.BatchGet(path2, "value", string.Empty) as string;
						text = dataProvider.BatchGet(text2, "type", string.Empty) as string;
						text4 = dataProvider.BatchGet(text2, "status", string.Empty) as string;
					}
					catch (Exception)
					{
					}
					if (!string.IsNullOrEmpty(text3) || !string.IsNullOrEmpty(text) || !string.IsNullOrEmpty(text4))
					{
						break;
					}
				}
			}
			switch (text)
			{
			case "MATERIAL":
			case "HEAT":
			case "WORK":
				text = CxvCustomTooltipHelper.LocalizeSubobjectType(text);
				break;
			}
			return CxvCustomTooltipHelper.LocalizeObjectType(path) + (string.IsNullOrEmpty(text) ? string.Empty : (" (" + text + ")")) + (string.IsNullOrEmpty(text3) ? string.Empty : ("\n" + text3)) + (string.IsNullOrEmpty(text4) ? string.Empty : ("\n" + text4));
		}
	}
	public class PFSGridReminderDialog : Window, IComponentConnector
	{
		private bool bDontShowAgain;

		internal StackPanel stackPanel1;

		internal Label label1;

		internal Label label2;

		internal CheckBox checkBox1;

		internal Button btnOK;

		private bool _contentLoaded;

		public PFSGridReminderDialog()
		{
			InitializeComponent();
			checkBox1.IsChecked = false;
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			base.DialogResult = bDontShowAgain;
			Close();
		}

		private void OnClickDontShow(object sender, RoutedEventArgs e)
		{
			bDontShowAgain = !bDontShowAgain;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsgridreminderdialog.xaml", UriKind.Relative);
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
				stackPanel1 = (StackPanel)target;
				break;
			case 2:
				label1 = (Label)target;
				break;
			case 3:
				label2 = (Label)target;
				break;
			case 4:
				checkBox1 = (CheckBox)target;
				checkBox1.Click += OnClickDontShow;
				break;
			case 5:
				btnOK = (Button)target;
				btnOK.Click += OnClickOk;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSIconImportDXFDialog : Window, IComponentConnector
	{
		public class BlockLT
		{
			public string BlockText { get; set; }
		}

		public List<string> SelectedBlockList;

		internal ListBox listBox1;

		internal Button SelectAllBtn;

		internal Button UnselectAllBtn;

		internal Button OKBtn;

		internal Button CancelBtn;

		internal CheckBox checkBox1;

		internal TextBox textBox1;

		private bool _contentLoaded;

		public ObservableCollection<BlockLT> BlockList { get; set; }

		public string sEditString { get; set; }

		public int iNumSelected { get; set; }

		public int iChecked { get; set; }

		public bool IsDialogOpen { get; private set; }

		public PFSIconImportDXFDialog()
		{
			InitializeComponent();
			BlockList = new ObservableCollection<BlockLT>();
			SelectedBlockList = new List<string>();
			sEditString = "";
			IsDialogOpen = false;
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			if (!IsDialogOpen)
			{
				checkBox1.IsChecked = false;
				textBox1.IsEnabled = false;
				textBox1.Text = sEditString;
				SelectAllBtn.IsEnabled = true;
				UnselectAllBtn.IsEnabled = false;
				iNumSelected = 0;
				iChecked = 0;
				IsDialogOpen = true;
			}
		}

		private void checkBox1_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				if (checkBox1.IsChecked == true)
				{
					textBox1.IsEnabled = true;
				}
				else
				{
					textBox1.IsEnabled = false;
				}
			}
		}

		private void listBox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (IsDialogOpen)
			{
				int num = BlockList.Count();
				iNumSelected = listBox1.SelectedItems.Count;
				if (iNumSelected == 0)
				{
					SelectAllBtn.IsEnabled = true;
					UnselectAllBtn.IsEnabled = false;
				}
				else if (iNumSelected == num)
				{
					SelectAllBtn.IsEnabled = false;
					UnselectAllBtn.IsEnabled = true;
				}
				else
				{
					SelectAllBtn.IsEnabled = true;
					UnselectAllBtn.IsEnabled = true;
				}
			}
		}

		private void SelectAllBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				listBox1.SelectAll();
				SelectAllBtn.IsEnabled = false;
				UnselectAllBtn.IsEnabled = true;
				iNumSelected = BlockList.Count();
			}
		}

		private void UnselectAllBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				listBox1.UnselectAll();
				SelectAllBtn.IsEnabled = true;
				UnselectAllBtn.IsEnabled = false;
				iNumSelected = 0;
			}
		}

		private void OKBtn_Click(object sender, RoutedEventArgs e)
		{
			if (!IsDialogOpen)
			{
				return;
			}
			iNumSelected = listBox1.SelectedItems.Count;
			iChecked = 0;
			if (checkBox1.IsChecked == true)
			{
				iChecked = 1;
			}
			if (iNumSelected == 0 && iChecked == 0)
			{
				new PFSMessageBox().Show(WpfPfsDialogsResources.NothingSelected, WpfPfsDialogsResources.Warning, MessageBoxButton.OK, MessageBoxImage.Exclamation, MessageBoxResult.OK);
				return;
			}
			sEditString = textBox1.Text;
			for (int i = 0; i < iNumSelected; i++)
			{
				string blockText = ((BlockLT)listBox1.SelectedItems[i]).BlockText;
				SelectedBlockList.Add(blockText);
			}
			base.DialogResult = true;
			Close();
		}

		private void CancelBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				base.DialogResult = false;
				Close();
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsiconimportdxfdialog.xaml", UriKind.Relative);
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
				((PFSIconImportDXFDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				listBox1 = (ListBox)target;
				listBox1.SelectionChanged += listBox1_SelectionChanged;
				break;
			case 3:
				SelectAllBtn = (Button)target;
				SelectAllBtn.Click += SelectAllBtn_Click;
				break;
			case 4:
				UnselectAllBtn = (Button)target;
				UnselectAllBtn.Click += UnselectAllBtn_Click;
				break;
			case 5:
				OKBtn = (Button)target;
				OKBtn.Click += OKBtn_Click;
				break;
			case 6:
				CancelBtn = (Button)target;
				CancelBtn.Click += CancelBtn_Click;
				break;
			case 7:
				checkBox1 = (CheckBox)target;
				checkBox1.Click += checkBox1_Click;
				break;
			case 8:
				textBox1 = (TextBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSMessageBoxDialog : Window, IComponentConnector
	{
		internal StackPanel stackPanel1;

		internal Image IconImage;

		internal StackPanel stackPanel2;

		internal TextBlock Message;

		internal StackPanel ButtonsStackPanel;

		internal Button OKButton;

		internal Button YesButton;

		internal Button NoButton;

		internal Button CancelButton;

		private bool _contentLoaded;

		public MessageBoxResult ResultButton { get; set; }

		public PFSMessageBoxDialog(string message, string caption, MessageBoxButton buttons, MessageBoxImage image, MessageBoxResult defaultButton)
		{
			InitializeComponent();
			base.Title = ((caption == string.Empty) ? WpfPfsDialogsResources.Message : caption);
			Message.Text = ((message == string.Empty) ? WpfPfsDialogsResources.NoMessage : message);
			ResultButton = MessageBoxResult.None;
			switch (buttons)
			{
			case MessageBoxButton.OK:
				YesButton.Visibility = Visibility.Collapsed;
				NoButton.Visibility = Visibility.Collapsed;
				CancelButton.Visibility = Visibility.Collapsed;
				break;
			case MessageBoxButton.OKCancel:
				YesButton.Visibility = Visibility.Collapsed;
				NoButton.Visibility = Visibility.Collapsed;
				break;
			case MessageBoxButton.YesNo:
				OKButton.Visibility = Visibility.Collapsed;
				CancelButton.Visibility = Visibility.Collapsed;
				break;
			case MessageBoxButton.YesNoCancel:
				OKButton.Visibility = Visibility.Collapsed;
				break;
			}
			string text = "pack://application:,,,/" + typeof(PFSMessageBoxDialog).Assembly.FullName + ";component/Images/";
			switch (image)
			{
			case MessageBoxImage.None:
				IconImage.Visibility = Visibility.Collapsed;
				break;
			case MessageBoxImage.Asterisk:
				IconImage.Source = new BitmapImage(new Uri(text + "Asterisk.png"));
				break;
			case MessageBoxImage.Hand:
				IconImage.Source = new BitmapImage(new Uri(text + "Stop.png"));
				break;
			case MessageBoxImage.Exclamation:
				IconImage.Source = new BitmapImage(new Uri(text + "Exclamation.png"));
				break;
			case MessageBoxImage.Question:
				IconImage.Source = new BitmapImage(new Uri(text + "Question.png"));
				break;
			}
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			ResultButton = MessageBoxResult.OK;
			base.DialogResult = true;
			Close();
		}

		private void OnClickYes(object sender, RoutedEventArgs e)
		{
			ResultButton = MessageBoxResult.Yes;
			base.DialogResult = true;
			Close();
		}

		private void OnClickNo(object sender, RoutedEventArgs e)
		{
			ResultButton = MessageBoxResult.No;
			base.DialogResult = true;
			Close();
		}

		private void OnClickCancel(object sender, RoutedEventArgs e)
		{
			ResultButton = MessageBoxResult.Cancel;
			base.DialogResult = false;
			Close();
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			if (e.Key == Key.Escape)
			{
				OnClickCancel(null, e);
			}
			else
			{
				base.OnKeyDown(e);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsmessagebox.xaml", UriKind.Relative);
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
				stackPanel1 = (StackPanel)target;
				break;
			case 2:
				IconImage = (Image)target;
				break;
			case 3:
				stackPanel2 = (StackPanel)target;
				break;
			case 4:
				Message = (TextBlock)target;
				break;
			case 5:
				ButtonsStackPanel = (StackPanel)target;
				break;
			case 6:
				OKButton = (Button)target;
				OKButton.Click += OnClickOk;
				break;
			case 7:
				YesButton = (Button)target;
				YesButton.Click += OnClickYes;
				break;
			case 8:
				NoButton = (Button)target;
				NoButton.Click += OnClickNo;
				break;
			case 9:
				CancelButton = (Button)target;
				CancelButton.Click += OnClickCancel;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSMessageBox
	{
		public int MessageBox(string contents, string caption, int buttons, int image)
		{
			return (int)Show(contents, caption, (MessageBoxButton)buttons, (MessageBoxImage)image, MessageBoxResult.OK);
		}

		public MessageBoxResult Show(string contents, string caption)
		{
			return Show(contents, caption, MessageBoxButton.OK, MessageBoxImage.None, MessageBoxResult.OK);
		}

		public MessageBoxResult Show(string contents, string caption, MessageBoxButton buttons)
		{
			return Show(contents, caption, buttons, MessageBoxImage.None, MessageBoxResult.OK);
		}

		public MessageBoxResult Show(string contents, string caption, MessageBoxButton buttons, MessageBoxImage image)
		{
			return Show(contents, caption, buttons, image, MessageBoxResult.OK);
		}

		public MessageBoxResult Show(string contents, string caption, MessageBoxButton buttons, MessageBoxImage image, MessageBoxResult defaultResult)
		{
			IUnityContainer container = PfsDialogsModule.Container;
			Window owner = null;
			if (container != null)
			{
				IShellApplication shellApplication = container.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					owner = Window.GetWindow(shellApplication.ActiveWindow as DependencyObject);
				}
			}
			return (MessageBoxResult)MMMessageBox.Show(owner, contents, caption, (MMMessageBoxButton)buttons, (MMMessageBoxImage)image, showHelpButton: false, (int)defaultResult);
		}
	}
	public class PFSNumericInputDialog : Window, IComponentConnector
	{
		private string caption = "Numeric Input";

		private string prompt = "Enter value:";

		private string strValue = string.Empty;

		private int numValue;

		private int minValue;

		private int maxValue = int.MaxValue;

		internal StackPanel stackPanel1;

		internal TextBlock inputPrompt;

		internal DockPanel dockPanel1;

		internal TextBox inputText;

		internal ScrollBar scrollBar1;

		internal StackPanel stackPanel3;

		internal Button btnOK;

		internal Button btnCancel;

		private bool _contentLoaded;

		public string StrInput
		{
			get
			{
				return strValue;
			}
			set
			{
				strValue = value;
			}
		}

		public int NumInput
		{
			get
			{
				return numValue;
			}
			set
			{
				numValue = value;
			}
		}

		public PFSNumericInputDialog(string caption, string prompt, int defaultVal, int minVal = 0, int maxVal = int.MaxValue)
		{
			if (caption != null)
			{
				this.caption = caption;
			}
			if (prompt != null)
			{
				this.prompt = prompt;
			}
			numValue = ((defaultVal > minVal) ? defaultVal : minVal);
			if (numValue > maxVal)
			{
				numValue = maxVal;
			}
			minValue = minVal;
			maxValue = maxVal;
			InitializeComponent();
			base.Title = this.caption;
			inputPrompt.Text = this.prompt;
			strValue = numValue.ToString();
			scrollBar1.Minimum = -maxValue;
			scrollBar1.Maximum = -minValue;
			scrollBar1.Value = -numValue;
			scrollBar1.SmallChange = 1.0;
			scrollBar1.LargeChange = 1.0;
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			inputText.Text = strValue;
			inputText.CaretIndex = inputText.Text.Length;
			inputText.Focus();
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			bool flag = true;
			try
			{
				numValue = Convert.ToInt32(strValue);
			}
			catch
			{
				flag = false;
			}
			if (!flag)
			{
				MMMessageBox.Show(WpfPfsDialogsResources.PFSNumericInputDialogMsgInvalidNumber, caption);
				return;
			}
			if (numValue < minValue || numValue > maxValue)
			{
				MMMessageBox.Show(string.Format(WpfPfsDialogsResources.PFSNumericInputDialogMsgNumberRangeError, minValue, maxValue), caption);
				return;
			}
			base.DialogResult = true;
			Close();
		}

		private void OnClickCancel(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			numValue = minValue - 1;
			Close();
		}

		private void OnTextChanged(object sender, RoutedEventArgs e)
		{
			if (inputText.Text == string.Empty)
			{
				btnOK.IsEnabled = false;
			}
			else
			{
				btnOK.IsEnabled = true;
			}
		}

		private void OnScroll(object sender, ScrollEventArgs e)
		{
			numValue = -(int)scrollBar1.Value;
			strValue = numValue.ToString();
			inputText.Text = strValue;
		}

		private void OnPreviewKeyDown(object sender, KeyEventArgs e)
		{
			e.Handled = e.Key == Key.Space;
		}

		private void OnPreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			e.Handled = !char.IsDigit(e.Text[0]);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsnumericinputdialog.xaml", UriKind.Relative);
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
				((PFSNumericInputDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				stackPanel1 = (StackPanel)target;
				break;
			case 3:
				inputPrompt = (TextBlock)target;
				break;
			case 4:
				dockPanel1 = (DockPanel)target;
				break;
			case 5:
				inputText = (TextBox)target;
				inputText.TextChanged += OnTextChanged;
				inputText.PreviewTextInput += OnPreviewTextInput;
				inputText.PreviewKeyDown += OnPreviewKeyDown;
				break;
			case 6:
				scrollBar1 = (ScrollBar)target;
				scrollBar1.Scroll += OnScroll;
				break;
			case 7:
				stackPanel3 = (StackPanel)target;
				break;
			case 8:
				btnOK = (Button)target;
				btnOK.Click += OnClickOk;
				break;
			case 9:
				btnCancel = (Button)target;
				btnCancel.Click += OnClickCancel;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSPlotEditLegendDialog : Window, IComponentConnector
	{
		public class Legend
		{
			public string LegendText { get; set; }
		}

		internal Button btnOk;

		internal Button btnCancel;

		internal DataGrid dataGrid1;

		internal Label label1;

		private bool _contentLoaded;

		public ObservableCollection<Legend> LegendsList { get; set; }

		public bool IsDialogOpen { get; private set; }

		public PFSPlotEditLegendDialog()
		{
			InitializeComponent();
			LegendsList = new ObservableCollection<Legend>();
			IsDialogOpen = false;
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			dataGrid1.ItemsSource = LegendsList;
			IsDialogOpen = true;
		}

		private void btnOk_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			Close();
		}

		protected override void OnPreviewKeyDown(KeyEventArgs e)
		{
			if (e.Key == Key.F1)
			{
				SystemEnvironment.ShowHtmlHelp("userguide1.chm", 1160);
				e.Handled = true;
			}
			base.OnPreviewKeyDown(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsploteditlegenddialog.xaml", UriKind.Relative);
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
				((PFSPlotEditLegendDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				btnOk = (Button)target;
				btnOk.Click += btnOk_Click;
				break;
			case 3:
				btnCancel = (Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			case 4:
				dataGrid1 = (DataGrid)target;
				break;
			case 5:
				label1 = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSPlotYAxisMapDialog : Window, IComponentConnector
	{
		public class TreeNode
		{
			public string sNodeName;

			public bool bCreatedNodeName;

			public bool bExpended;

			public List<int> NodeVarIndexList { get; set; }

			public TreeNode()
			{
				sNodeName = "";
				bCreatedNodeName = false;
				bExpended = true;
				NodeVarIndexList = new List<int>();
			}
		}

		public class SelectedItemIndex
		{
			public int iNodeIndex;

			public int iLineIndex;

			public int iLastLine;

			public SelectedItemIndex()
			{
				iNodeIndex = -1;
				iLineIndex = -1;
				iLastLine = -1;
			}
		}

		public int miNumVar;

		public int miNumYaxis;

		public bool bAxisConfigChanged;

		public string sSingleAxisLabel = string.Empty;

		public SelectedItemIndex mSelItemIndex = new SelectedItemIndex();

		private string sAxisLabel = WpfPfsDialogsResources.YAxisLabel;

		internal Grid Grid1;

		internal TreeView mTreeView1;

		internal Button SingleYaxisBtn;

		internal Button IndividualYaxesBtn;

		internal Button AddAxisBtn;

		internal Button DeleteAxisBtn;

		internal Button UpBtn;

		internal Button DownBtn;

		internal Button OkBtn;

		internal Button CancelBtn;

		private bool _contentLoaded;

		public ObservableCollection<string> scolVarNames { get; set; }

		public ObservableCollection<string> scolVarDefaultLabels { get; set; }

		public ObservableCollection<string> scolYaxisLabels { get; set; }

		public ObservableCollection<int> icolYaxisMap { get; set; }

		public bool IsDialogOpen { get; private set; }

		public bool IsModified { get; private set; }

		public ObservableCollection<TreeNode> TreeViewNodes { get; set; }

		public ObservableCollection<string> sColNewYaxisLabels { get; set; }

		public ObservableCollection<int> iColNewYaxisMap { get; set; }

		public PFSPlotYAxisMapDialog()
		{
			InitializeComponent();
			scolVarNames = new ObservableCollection<string>();
			scolVarDefaultLabels = new ObservableCollection<string>();
			scolYaxisLabels = new ObservableCollection<string>();
			icolYaxisMap = new ObservableCollection<int>();
			TreeViewNodes = new ObservableCollection<TreeNode>();
			sColNewYaxisLabels = new ObservableCollection<string>();
			iColNewYaxisMap = new ObservableCollection<int>();
			IsDialogOpen = false;
			IsModified = false;
		}

		private int NumYaxis()
		{
			int count = icolYaxisMap.Count;
			int num = 0;
			for (int i = 0; i < count; i++)
			{
				if (num < icolYaxisMap[i])
				{
					num = icolYaxisMap[i];
				}
			}
			return num;
		}

		public void CreateOrgnlTreeViewNodes()
		{
			if (TreeViewNodes == null)
			{
				TreeViewNodes = new ObservableCollection<TreeNode>();
			}
			int num = NumYaxis();
			for (int i = 0; i < num; i++)
			{
				TreeNode item = new TreeNode();
				TreeViewNodes.Add(item);
			}
			int count = scolVarNames.Count;
			int num2 = 0;
			for (int j = 0; j < count; j++)
			{
				num2 = icolYaxisMap[j] - 1;
				TreeViewNodes[num2].NodeVarIndexList.Add(j);
				if (string.IsNullOrEmpty(TreeViewNodes[num2].sNodeName))
				{
					TreeViewNodes[num2].sNodeName = scolYaxisLabels[j];
				}
			}
			int count2 = TreeViewNodes.Count;
			for (int k = 0; k < count2; k++)
			{
				if (string.IsNullOrEmpty(TreeViewNodes[k].sNodeName))
				{
					if (TreeViewNodes[k].NodeVarIndexList.Count != 0)
					{
						int index = TreeViewNodes[k].NodeVarIndexList[0];
						TreeViewNodes[k].sNodeName = scolVarNames[index];
					}
					else
					{
						TreeViewNodes[k].sNodeName = GetYAxisLabel(k + 1);
						TreeViewNodes[k].bCreatedNodeName = true;
					}
				}
			}
		}

		public void RefreshTree()
		{
			GetTreeSelItemIndex();
			int iNodeIndex = mSelItemIndex.iNodeIndex;
			int iLineIndex = mSelItemIndex.iLineIndex;
			_ = mSelItemIndex.iLastLine;
			_ = mTreeView1.Items.Count;
			int count = TreeViewNodes.Count;
			for (int i = 0; i < count; i++)
			{
				if (TreeViewNodes[i].NodeVarIndexList.Count != 0)
				{
					int index = TreeViewNodes[i].NodeVarIndexList[0];
					TreeViewNodes[i].sNodeName = scolVarDefaultLabels[index];
					TreeViewNodes[i].bCreatedNodeName = false;
				}
			}
			CreateOrgnlTreeView(bf: false);
			for (int j = 0; j < count; j++)
			{
				if (j == iNodeIndex && iLineIndex == -1)
				{
					((TreeViewItem)mTreeView1.Items[j]).IsSelected = true;
				}
				if (j != iNodeIndex || iLineIndex < 0)
				{
					continue;
				}
				int count2 = TreeViewNodes[j].NodeVarIndexList.Count;
				for (int k = 0; k < count2; k++)
				{
					if (k == iLineIndex)
					{
						((TreeViewItem)mTreeView1.Items[j]).IsExpanded = true;
						((TreeViewItem)((TreeViewItem)mTreeView1.Items[j]).Items[k]).IsSelected = true;
					}
				}
			}
		}

		private string GetYAxisLabel(int i)
		{
			return string.Format(sAxisLabel, i);
		}

		private void CreateSingleYaxisView()
		{
			bAxisConfigChanged = true;
			IsModified = true;
			if (TreeViewNodes == null)
			{
				TreeViewNodes = new ObservableCollection<TreeNode>();
			}
			else
			{
				TreeViewNodes.Clear();
			}
			int count = scolVarNames.Count;
			TreeNode item = new TreeNode();
			TreeViewNodes.Add(item);
			for (int i = 0; i < count; i++)
			{
				TreeViewNodes[0].NodeVarIndexList.Add(i);
			}
			if (!string.IsNullOrEmpty(TreeViewNodes[0].sNodeName))
			{
				return;
			}
			if (scolYaxisLabels.Count > 0)
			{
				if (sSingleAxisLabel.Length > 0)
				{
					TreeViewNodes[0].sNodeName = sSingleAxisLabel;
				}
				else
				{
					TreeViewNodes[0].sNodeName = scolYaxisLabels[0];
				}
			}
			else
			{
				TreeViewNodes[0].bCreatedNodeName = true;
				TreeViewNodes[0].sNodeName = GetYAxisLabel(1);
			}
		}

		private void CreateIndividualYaxesView()
		{
			bAxisConfigChanged = true;
			IsModified = true;
			if (TreeViewNodes == null)
			{
				TreeViewNodes = new ObservableCollection<TreeNode>();
			}
			else
			{
				TreeViewNodes.Clear();
			}
			int count = scolVarNames.Count;
			for (int i = 0; i < count; i++)
			{
				TreeNode item = new TreeNode();
				TreeViewNodes.Add(item);
			}
			for (int j = 0; j < count; j++)
			{
				TreeViewNodes[j].NodeVarIndexList.Add(j);
				if (string.IsNullOrEmpty(TreeViewNodes[j].sNodeName))
				{
					TreeViewNodes[j].sNodeName = scolVarDefaultLabels[j];
				}
			}
			for (int k = 0; k < count; k++)
			{
				if (string.IsNullOrEmpty(TreeViewNodes[k].sNodeName))
				{
					TreeViewNodes[k].bCreatedNodeName = true;
					TreeViewNodes[k].sNodeName = GetYAxisLabel(k + 1);
				}
			}
		}

		public void CreateOrgnlTreeView(bool bf = true)
		{
			mTreeView1.BeginInit();
			if (mTreeView1.Items.Count != 0)
			{
				mTreeView1.Items.Clear();
			}
			int num = 0;
			int count = TreeViewNodes.Count;
			int num2 = 0;
			for (int i = 0; i < count; i++)
			{
				TreeViewItem treeViewItem = new TreeViewItem();
				treeViewItem.IsExpanded = TreeViewNodes[i].bExpended;
				treeViewItem.Header = TreeViewNodes[i].sNodeName;
				treeViewItem.Tag = TreeViewNodes[i].bCreatedNodeName;
				mTreeView1.Items.Add(treeViewItem);
				num = TreeViewNodes[i].NodeVarIndexList.Count;
				for (int j = 0; j < num; j++)
				{
					num2 = TreeViewNodes[i].NodeVarIndexList[j];
					TreeViewItem treeViewItem2 = new TreeViewItem();
					treeViewItem2.Header = scolVarNames[num2];
					treeViewItem2.Tag = num2;
					((TreeViewItem)mTreeView1.Items[i]).Items.Add(treeViewItem2);
				}
				for (int k = 0; k < num; k++)
				{
					TreeViewItem treeViewItem3 = (TreeViewItem)((TreeViewItem)mTreeView1.Items[i]).Items[k];
					if (scolVarDefaultLabels[(int)treeViewItem3.Tag] == (string)treeViewItem.Header)
					{
						((TreeViewItem)mTreeView1.Items[i]).Items.RemoveAt(k);
						((TreeViewItem)mTreeView1.Items[i]).Items.Insert(0, treeViewItem3);
					}
				}
			}
			mTreeView1.EndInit();
			if (bf)
			{
				SetButtons();
			}
		}

		public void GetTreeViewNowNodes()
		{
			if (TreeViewNodes == null)
			{
				TreeViewNodes = new ObservableCollection<TreeNode>();
			}
			else
			{
				TreeViewNodes.Clear();
			}
			if (mTreeView1.Items.Count == 0)
			{
				return;
			}
			int count = mTreeView1.Items.Count;
			for (int i = 0; i < count; i++)
			{
				TreeNode treeNode = new TreeNode();
				TreeViewItem treeViewItem = (TreeViewItem)mTreeView1.Items[i];
				treeNode.sNodeName = (string)treeViewItem.Header;
				treeNode.bCreatedNodeName = (bool)treeViewItem.Tag;
				treeNode.bExpended = treeViewItem.IsExpanded;
				int count2 = treeViewItem.Items.Count;
				for (int j = 0; j < count2; j++)
				{
					TreeViewItem treeViewItem2 = (TreeViewItem)treeViewItem.Items[j];
					treeNode.NodeVarIndexList.Add((int)treeViewItem2.Tag);
				}
				TreeViewNodes.Add(treeNode);
			}
		}

		private void SetButtons()
		{
			if (miNumVar == 1 && miNumYaxis == 1)
			{
				SingleYaxisBtn.IsEnabled = false;
				IndividualYaxesBtn.IsEnabled = false;
				AddAxisBtn.IsEnabled = false;
				UpBtn.IsEnabled = false;
				DownBtn.IsEnabled = false;
				DeleteAxisBtn.IsEnabled = false;
				return;
			}
			SetSingleYaxisBtn();
			SetIndividualYaxesBtn();
			SetAddAxisBtn();
			if (!HasSelected())
			{
				UpBtn.IsEnabled = false;
				DownBtn.IsEnabled = false;
				DeleteAxisBtn.IsEnabled = false;
				if (mSelItemIndex != null)
				{
					mSelItemIndex.iNodeIndex = -1;
					mSelItemIndex.iLineIndex = -1;
					mSelItemIndex.iLastLine = -1;
				}
			}
			else
			{
				GetTreeSelItemIndex();
				SetUpBtn();
				SetDownBtn();
				SetDeleteAxisBtn();
			}
		}

		private void GetTreeSelItemIndex()
		{
			if (mSelItemIndex == null)
			{
				mSelItemIndex = new SelectedItemIndex();
			}
			else
			{
				mSelItemIndex.iNodeIndex = -1;
				mSelItemIndex.iLineIndex = -1;
				mSelItemIndex.iLastLine = -1;
			}
			TreeViewItem treeViewItem = (TreeViewItem)mTreeView1.SelectedItem;
			int count = mTreeView1.Items.Count;
			for (int i = 0; i < count; i++)
			{
				TreeViewItem treeViewItem2 = (TreeViewItem)mTreeView1.Items[i];
				if (treeViewItem.Equals(treeViewItem2))
				{
					mSelItemIndex.iNodeIndex = i;
					break;
				}
				int count2 = treeViewItem2.Items.Count;
				for (int j = 0; j < count2; j++)
				{
					TreeViewItem obj = (TreeViewItem)treeViewItem2.Items[j];
					if (treeViewItem.Equals(obj))
					{
						mSelItemIndex.iNodeIndex = i;
						mSelItemIndex.iLineIndex = j;
						if (i == count - 1 && j == count2 - 1)
						{
							mSelItemIndex.iLastLine = 1;
						}
						break;
					}
				}
			}
		}

		private void SetSingleYaxisBtn()
		{
			if (mTreeView1.Items.Count == 1)
			{
				SingleYaxisBtn.IsEnabled = false;
			}
			else
			{
				SingleYaxisBtn.IsEnabled = true;
			}
		}

		private void SetIndividualYaxesBtn()
		{
			int num = HasEmptyNode();
			if (mTreeView1.Items.Count == miNumVar && num == -1)
			{
				IndividualYaxesBtn.IsEnabled = false;
			}
			else
			{
				IndividualYaxesBtn.IsEnabled = true;
			}
		}

		private void SetAddAxisBtn()
		{
			if (mTreeView1.Items.Count == miNumVar)
			{
				AddAxisBtn.IsEnabled = false;
			}
			else
			{
				AddAxisBtn.IsEnabled = true;
			}
		}

		private void SetUpBtn()
		{
			if (mSelItemIndex.iNodeIndex <= 0 && mSelItemIndex.iLineIndex < 0)
			{
				UpBtn.IsEnabled = false;
			}
			else if (mSelItemIndex.iNodeIndex == 0 && mSelItemIndex.iLineIndex == 0)
			{
				UpBtn.IsEnabled = false;
			}
			else
			{
				UpBtn.IsEnabled = true;
			}
		}

		private void SetDownBtn()
		{
			int count = mTreeView1.Items.Count;
			if (count == 1 && mSelItemIndex.iNodeIndex <= 0 && mSelItemIndex.iLineIndex < 0)
			{
				DownBtn.IsEnabled = false;
			}
			else if (count > 1 && mSelItemIndex.iNodeIndex == count - 1 && mSelItemIndex.iLineIndex < 0)
			{
				DownBtn.IsEnabled = false;
			}
			else if (mSelItemIndex.iNodeIndex >= 0 && mSelItemIndex.iLineIndex >= 0 && mSelItemIndex.iLastLine >= 0)
			{
				DownBtn.IsEnabled = false;
			}
			else
			{
				DownBtn.IsEnabled = true;
			}
		}

		private void SetDeleteAxisBtn()
		{
			int count = mTreeView1.Items.Count;
			if (count == 1 && mSelItemIndex.iNodeIndex == 0 && mSelItemIndex.iLineIndex < 0)
			{
				DeleteAxisBtn.IsEnabled = false;
			}
			else if (mSelItemIndex.iNodeIndex < 0)
			{
				DeleteAxisBtn.IsEnabled = false;
			}
			else if (count > 1 && mSelItemIndex.iNodeIndex >= 0 && mSelItemIndex.iLineIndex < 0)
			{
				DeleteAxisBtn.IsEnabled = true;
			}
			else
			{
				DeleteAxisBtn.IsEnabled = false;
			}
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			miNumVar = scolVarNames.Count;
			miNumYaxis = NumYaxis();
			CreateOrgnlTreeViewNodes();
			CreateOrgnlTreeView();
			SetButtons();
			IsDialogOpen = true;
		}

		private int HasEmptyNode()
		{
			int result = -1;
			int count = mTreeView1.Items.Count;
			for (int i = 0; i < count; i++)
			{
				if (((TreeViewItem)mTreeView1.Items[i]).Items.Count == 0)
				{
					result = i;
					break;
				}
			}
			return result;
		}

		private bool HasSelected()
		{
			bool result = false;
			if ((TreeViewItem)mTreeView1.SelectedItem != null)
			{
				result = true;
			}
			return result;
		}

		private void mTreeView1_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
		{
			if (IsDialogOpen)
			{
				SetButtons();
			}
		}

		private void SingleYaxisBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				CreateSingleYaxisView();
				CreateOrgnlTreeView();
			}
		}

		private void IndividualYaxesBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				CreateIndividualYaxesView();
				CreateOrgnlTreeView();
			}
		}

		private void AddAxisBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				bAxisConfigChanged = true;
				IsModified = true;
				TreeNode treeNode = new TreeNode();
				treeNode.bCreatedNodeName = true;
				int count = mTreeView1.Items.Count;
				treeNode.sNodeName = GetYAxisLabel(count + 1);
				TreeViewItem treeViewItem = new TreeViewItem();
				treeViewItem.IsExpanded = treeNode.bExpended;
				treeViewItem.Header = treeNode.sNodeName;
				treeViewItem.Tag = treeNode.bCreatedNodeName;
				mTreeView1.Items.Add(treeViewItem);
				mTreeView1.UpdateLayout();
				SetButtons();
			}
		}

		private void DeleteAxisBtn_Click(object sender, RoutedEventArgs e)
		{
			if (!IsDialogOpen)
			{
				return;
			}
			bAxisConfigChanged = true;
			IsModified = true;
			GetTreeSelItemIndex();
			int count = mTreeView1.Items.Count;
			int iNodeIndex = mSelItemIndex.iNodeIndex;
			if (count - 1 != iNodeIndex)
			{
				for (int i = iNodeIndex + 1; i < count; i++)
				{
					TreeViewItem treeViewItem = (TreeViewItem)mTreeView1.Items[i];
					if ((bool)treeViewItem.Tag)
					{
						treeViewItem.Header = GetYAxisLabel(i);
					}
				}
			}
			TreeViewItem treeViewItem2 = (TreeViewItem)mTreeView1.Items[iNodeIndex];
			TreeViewItem treeViewItem3 = ((iNodeIndex != 0) ? ((TreeViewItem)mTreeView1.Items[iNodeIndex - 1]) : ((TreeViewItem)mTreeView1.Items[iNodeIndex + 1]));
			int count2 = treeViewItem2.Items.Count;
			for (int j = 0; j < count2; j++)
			{
				TreeViewItem treeViewItem4 = new TreeViewItem();
				TreeViewItem treeViewItem5 = (TreeViewItem)treeViewItem2.Items[j];
				treeViewItem4.Header = treeViewItem5.Header;
				treeViewItem4.Tag = treeViewItem5.Tag;
				treeViewItem3.Items.Add(treeViewItem4);
			}
			mTreeView1.Items.RemoveAt(iNodeIndex);
			if (count2 > 0)
			{
				treeViewItem3.IsExpanded = true;
			}
			treeViewItem3.IsSelected = true;
			mTreeView1.UpdateLayout();
			SetButtons();
		}

		private void UpBtn_Click(object sender, RoutedEventArgs e)
		{
			if (!IsDialogOpen)
			{
				return;
			}
			IsModified = true;
			GetTreeSelItemIndex();
			int iNodeIndex = mSelItemIndex.iNodeIndex;
			int iLineIndex = mSelItemIndex.iLineIndex;
			_ = mSelItemIndex.iLastLine;
			_ = mTreeView1.Items.Count;
			if (iLineIndex >= 0 && iNodeIndex >= 0)
			{
				if (iLineIndex == 0 && iNodeIndex == 0)
				{
					return;
				}
				GetTreeViewNowNodes();
				if (iLineIndex == 0)
				{
					bAxisConfigChanged = true;
					TreeNode treeNode = TreeViewNodes[iNodeIndex];
					TreeNode treeNode2 = TreeViewNodes[iNodeIndex - 1];
					int num = treeNode.NodeVarIndexList[0];
					treeNode.NodeVarIndexList.RemoveAt(0);
					treeNode2.NodeVarIndexList.Add(num);
					if (treeNode2.bCreatedNodeName)
					{
						treeNode2.sNodeName = scolVarDefaultLabels[num];
						treeNode2.bCreatedNodeName = false;
					}
					CreateOrgnlTreeView(bf: false);
					TreeViewItem obj = (TreeViewItem)mTreeView1.Items[iNodeIndex - 1];
					obj.IsExpanded = true;
					int count = obj.Items.Count;
					((TreeViewItem)obj.Items[count - 1]).IsSelected = true;
				}
				else
				{
					TreeNode treeNode3 = TreeViewNodes[iNodeIndex];
					int num2 = iLineIndex;
					int index = num2 - 1;
					int value = treeNode3.NodeVarIndexList[num2];
					int value2 = treeNode3.NodeVarIndexList[index];
					treeNode3.NodeVarIndexList[num2] = value2;
					treeNode3.NodeVarIndexList[index] = value;
					CreateOrgnlTreeView(bf: false);
					((TreeViewItem)((TreeViewItem)mTreeView1.Items[iNodeIndex]).Items[index]).IsSelected = true;
				}
			}
			if (iLineIndex < 0 && iNodeIndex >= 0)
			{
				if (iLineIndex == 0)
				{
					return;
				}
				GetTreeViewNowNodes();
				int num3 = iNodeIndex;
				int num4 = iNodeIndex - 1;
				if (TreeViewNodes[num3].bCreatedNodeName)
				{
					TreeViewNodes[num3].sNodeName = GetYAxisLabel(num3);
				}
				if (TreeViewNodes[num4].bCreatedNodeName)
				{
					TreeViewNodes[num4].sNodeName = GetYAxisLabel(num3);
				}
				TreeViewNodes.Move(num3, num4);
				CreateOrgnlTreeView(bf: false);
				((TreeViewItem)mTreeView1.Items[num4]).IsSelected = true;
			}
			RefreshTree();
			SetButtons();
		}

		private void DownBtn_Click(object sender, RoutedEventArgs e)
		{
			if (!IsDialogOpen)
			{
				return;
			}
			IsModified = true;
			GetTreeSelItemIndex();
			int iNodeIndex = mSelItemIndex.iNodeIndex;
			int iLineIndex = mSelItemIndex.iLineIndex;
			int iLastLine = mSelItemIndex.iLastLine;
			int count = mTreeView1.Items.Count;
			if (iLineIndex >= 0 && iNodeIndex >= 0)
			{
				if (iLastLine > 0)
				{
					return;
				}
				GetTreeViewNowNodes();
				int count2 = TreeViewNodes[iNodeIndex].NodeVarIndexList.Count;
				if (iLineIndex == count2 - 1)
				{
					bAxisConfigChanged = true;
					TreeNode treeNode = TreeViewNodes[iNodeIndex];
					TreeNode treeNode2 = TreeViewNodes[iNodeIndex + 1];
					int num = treeNode.NodeVarIndexList[count2 - 1];
					treeNode.NodeVarIndexList.RemoveAt(count2 - 1);
					treeNode2.NodeVarIndexList.Insert(0, num);
					if (treeNode2.bCreatedNodeName)
					{
						treeNode2.sNodeName = scolVarDefaultLabels[num];
						treeNode2.bCreatedNodeName = false;
					}
					CreateOrgnlTreeView(bf: false);
					TreeViewItem obj = (TreeViewItem)mTreeView1.Items[iNodeIndex + 1];
					obj.IsExpanded = true;
					_ = obj.Items.Count;
					((TreeViewItem)obj.Items[0]).IsSelected = true;
				}
				else
				{
					TreeNode treeNode3 = TreeViewNodes[iNodeIndex];
					int num2 = iLineIndex;
					int index = num2 + 1;
					int value = treeNode3.NodeVarIndexList[num2];
					int value2 = treeNode3.NodeVarIndexList[index];
					treeNode3.NodeVarIndexList[num2] = value2;
					treeNode3.NodeVarIndexList[index] = value;
					CreateOrgnlTreeView(bf: false);
					((TreeViewItem)((TreeViewItem)mTreeView1.Items[iNodeIndex]).Items[index]).IsSelected = true;
				}
			}
			if (iLineIndex < 0 && iNodeIndex >= 0)
			{
				if (iNodeIndex == count - 1)
				{
					return;
				}
				GetTreeViewNowNodes();
				int num3 = iNodeIndex;
				int num4 = iNodeIndex + 1;
				if (TreeViewNodes[num3].bCreatedNodeName)
				{
					TreeViewNodes[num3].sNodeName = GetYAxisLabel(num4 + 1);
				}
				if (TreeViewNodes[num4].bCreatedNodeName)
				{
					TreeViewNodes[num4].sNodeName = GetYAxisLabel(num4 + 1);
				}
				TreeViewNodes.Move(num3, num4);
				CreateOrgnlTreeView(bf: false);
				((TreeViewItem)mTreeView1.Items[num4]).IsSelected = true;
			}
			RefreshTree();
			SetButtons();
		}

		private void GetNewYaxisLabelsAndMap()
		{
			if (sColNewYaxisLabels == null)
			{
				sColNewYaxisLabels = new ObservableCollection<string>();
			}
			else
			{
				sColNewYaxisLabels.Clear();
			}
			if (iColNewYaxisMap == null)
			{
				iColNewYaxisMap = new ObservableCollection<int>();
			}
			else
			{
				iColNewYaxisMap.Clear();
			}
			for (int i = 0; i < miNumVar; i++)
			{
				sColNewYaxisLabels.Add("");
				iColNewYaxisMap.Add(0);
			}
			int num = -1;
			while (HasEmptyNode() != -1)
			{
				num = HasEmptyNode();
				int count = mTreeView1.Items.Count;
				for (int j = num + 1; j < count; j++)
				{
					if ((bool)((TreeViewItem)mTreeView1.Items[j]).Tag)
					{
						((TreeViewItem)mTreeView1.Items[j]).Header = GetYAxisLabel(j);
					}
				}
				mTreeView1.Items.RemoveAt(num);
			}
			int count2 = mTreeView1.Items.Count;
			int num2 = 0;
			int num3 = 0;
			for (int k = 0; k < count2; k++)
			{
				TreeViewItem treeViewItem = (TreeViewItem)mTreeView1.Items[k];
				num2 = treeViewItem.Items.Count;
				for (int l = 0; l < num2; l++)
				{
					num3 = (int)((TreeViewItem)treeViewItem.Items[l]).Tag;
					sColNewYaxisLabels[num3] = (string)treeViewItem.Header;
					iColNewYaxisMap[num3] = k + 1;
				}
			}
		}

		private void ClearDuplicateLabels()
		{
			int count = sColNewYaxisLabels.Count;
			for (int i = 0; i < count - 1; i++)
			{
				string text = sColNewYaxisLabels[i];
				if (string.IsNullOrEmpty(text))
				{
					continue;
				}
				for (int j = i + 1; j < count; j++)
				{
					if (text == sColNewYaxisLabels[j])
					{
						sColNewYaxisLabels[j] = "";
					}
				}
			}
		}

		private void CancelBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				base.DialogResult = false;
				Close();
			}
		}

		private void OkBtn_Click(object sender, RoutedEventArgs e)
		{
			if (IsDialogOpen)
			{
				GetNewYaxisLabelsAndMap();
				base.DialogResult = IsModified;
				Close();
			}
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			base.OnKeyDown(e);
			switch (e.Key)
			{
			case Key.Escape:
				CancelBtn_Click(null, null);
				break;
			case Key.Return:
				OkBtn_Click(null, null);
				break;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsplotyaxismapdialog.xaml", UriKind.Relative);
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
				((PFSPlotYAxisMapDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				Grid1 = (Grid)target;
				break;
			case 3:
				mTreeView1 = (TreeView)target;
				mTreeView1.SelectedItemChanged += mTreeView1_SelectedItemChanged;
				break;
			case 4:
				SingleYaxisBtn = (Button)target;
				SingleYaxisBtn.Click += SingleYaxisBtn_Click;
				break;
			case 5:
				IndividualYaxesBtn = (Button)target;
				IndividualYaxesBtn.Click += IndividualYaxesBtn_Click;
				break;
			case 6:
				AddAxisBtn = (Button)target;
				AddAxisBtn.Click += AddAxisBtn_Click;
				break;
			case 7:
				DeleteAxisBtn = (Button)target;
				DeleteAxisBtn.Click += DeleteAxisBtn_Click;
				break;
			case 8:
				UpBtn = (Button)target;
				UpBtn.Click += UpBtn_Click;
				break;
			case 9:
				DownBtn = (Button)target;
				DownBtn.Click += DownBtn_Click;
				break;
			case 10:
				OkBtn = (Button)target;
				OkBtn.Click += OkBtn_Click;
				break;
			case 11:
				CancelBtn = (Button)target;
				CancelBtn.Click += CancelBtn_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSUniversalPortDialog : Window, IComponentConnector
	{
		internal ListBox PortsListBox;

		internal Button OKButton;

		private bool _contentLoaded;

		public ObservableCollection<string> PortsList { get; set; }

		public int SelectedPort { get; set; }

		public PFSUniversalPortDialog()
		{
			InitializeComponent();
			SelectedPort = -1;
			PortsList = new ObservableCollection<string>();
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			SelectedPort = ((PortsList.Count < 0) ? (-1) : 0);
			PortsListBox.SelectedIndex = SelectedPort;
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void OnPortSelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			SelectedPort = PortsListBox.SelectedIndex;
		}

		private void OnPortDoubleClick(object sender, MouseButtonEventArgs e)
		{
			SelectedPort = PortsListBox.SelectedIndex;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsuniversalportdialog.xaml", UriKind.Relative);
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
				((PFSUniversalPortDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				PortsListBox = (ListBox)target;
				PortsListBox.SelectionChanged += OnPortSelectionChanged;
				PortsListBox.MouseDoubleClick += OnPortDoubleClick;
				break;
			case 3:
				OKButton = (Button)target;
				OKButton.Click += OnClickOk;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class PFSUnplacedBlocksDialog : Window, IComponentConnector
	{
		private const string CF_PFS_UNPLACEDBLOCK = "PFS Unplaced BLOCK Format";

		private Point dragStartPt;

		private bool bDragStarted;

		internal Grid Grid1;

		internal Label label1;

		internal ListBox listBox1;

		internal Button placeAllBtn;

		internal Button placeNextBtn;

		private bool _contentLoaded;

		public bool DialogOpen { get; set; }

		public bool PlaceAllOnClose { get; set; }

		public object PfsObject { get; set; }

		public BlockNameList UnplacedBlocksList { get; set; }

		public PFSUnplacedBlocksDialog()
		{
			InitializeComponent();
			UnplacedBlocksList = new BlockNameList();
			PfsObject = null;
			DialogOpen = false;
			PlaceAllOnClose = true;
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			DialogOpen = true;
		}

		private void OnDialogClosed(object sender, EventArgs e)
		{
			DialogOpen = false;
			if (PfsObject != null && PlaceAllOnClose && UnplacedBlocksList.Count() > 0)
			{
				PfsObject.GetType().InvokeMember("PlaceAllBlocks", BindingFlags.InvokeMethod, null, PfsObject, null);
				UnplacedBlocksList.Clear();
			}
		}

		private void OnClickPlaceAll(object sender, RoutedEventArgs e)
		{
			if (PfsObject != null && UnplacedBlocksList.Count() > 0)
			{
				PfsObject.GetType().InvokeMember("PlaceAllBlocks", BindingFlags.InvokeMethod, null, PfsObject, null);
				UnplacedBlocksList.Clear();
			}
		}

		private void OnClickPlaceNext(object sender, RoutedEventArgs e)
		{
			if (UnplacedBlocksList.Count() <= 1)
			{
				OnClickPlaceAll(sender, e);
			}
			else if (PfsObject != null)
			{
				PfsObject.GetType().InvokeMember("PlaceNextBlock", BindingFlags.InvokeMethod, null, PfsObject, null);
			}
		}

		private void OnClickPlaceBlock(object sender, RoutedEventArgs e)
		{
			if (UnplacedBlocksList.Count() <= 1)
			{
				OnClickPlaceAll(sender, e);
				return;
			}
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0 && selectedIndex < UnplacedBlocksList.Count())
			{
				string text = UnplacedBlocksList[selectedIndex];
				if (PfsObject != null)
				{
					object[] args = new object[1] { text };
					PfsObject.GetType().InvokeMember("PlaceBlock", BindingFlags.InvokeMethod, null, PfsObject, args);
				}
				UnplacedBlocksList.RemoveAt(selectedIndex);
			}
		}

		private void DoDragDrop()
		{
			int selectedIndex = listBox1.SelectedIndex;
			if (selectedIndex >= 0 && selectedIndex < UnplacedBlocksList.Count())
			{
				string data = UnplacedBlocksList[selectedIndex];
				DataObject dataObject = new DataObject("PFS Unplaced BLOCK Format", data);
				dataObject.SetData("Text", data);
				DragDrop.DoDragDrop(this, dataObject, DragDropEffects.Copy | DragDropEffects.Move);
			}
		}

		private void OnPreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
		{
			dragStartPt = e.GetPosition(null);
			Point point = listBox1.TranslatePoint(new Point(0.0, 0.0), this);
			point.X = dragStartPt.X - point.X;
			point.Y = dragStartPt.Y - point.Y;
			if (listBox1.InputHitTest(point) != null)
			{
				bDragStarted = true;
			}
		}

		private void OnPreviewMouseMove(object sender, MouseEventArgs e)
		{
			Point position = e.GetPosition(null);
			Vector vector = dragStartPt - position;
			if (bDragStarted && e.LeftButton == MouseButtonState.Pressed && (Math.Abs(vector.X) > SystemParameters.MinimumHorizontalDragDistance || Math.Abs(vector.Y) > SystemParameters.MinimumVerticalDragDistance))
			{
				DoDragDrop();
				bDragStarted = false;
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfsunplcedblocksdialog.xaml", UriKind.Relative);
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
				((PFSUnplacedBlocksDialog)target).Loaded += OnDialogLoaded;
				((PFSUnplacedBlocksDialog)target).Closed += OnDialogClosed;
				((PFSUnplacedBlocksDialog)target).PreviewMouseLeftButtonDown += OnPreviewMouseLeftButtonDown;
				((PFSUnplacedBlocksDialog)target).PreviewMouseMove += OnPreviewMouseMove;
				break;
			case 2:
				Grid1 = (Grid)target;
				break;
			case 3:
				label1 = (Label)target;
				break;
			case 4:
				listBox1 = (ListBox)target;
				break;
			case 5:
				placeAllBtn = (Button)target;
				placeAllBtn.Click += OnClickPlaceAll;
				break;
			case 6:
				placeNextBtn = (Button)target;
				placeNextBtn.Click += OnClickPlaceNext;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class BlockNameList : ObservableCollection<string>
	{
		public void InsertSorted(string block)
		{
			bool flag = false;
			for (int i = 0; i < this.Count(); i++)
			{
				int num = block.CompareTo(base[i]);
				if (num == 0)
				{
					flag = true;
					break;
				}
				if (num < 0)
				{
					Insert(i, block);
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				Add(block);
			}
		}
	}
	public class PFSTextInputDialog : Window, IComponentConnector
	{
		private bool bUpperCase;

		private int max_length;

		internal StackPanel stackPanel1;

		internal TextBlock inputPrompt;

		internal TextBox inputText;

		internal StackPanel stackPanel2;

		internal Button btnOK;

		internal Button btnCancel;

		private bool _contentLoaded;

		public string StrInput { get; set; }

		public PFSTextInputDialog(string caption, string prompt, string default_text, bool upper = false, int length = 0)
		{
			InitializeComponent();
			StrInput = default_text;
			bUpperCase = upper;
			max_length = length;
			base.Title = ((caption == string.Empty) ? "Input" : caption);
			inputPrompt.Text = ((prompt == string.Empty) ? "Enter Text:" : prompt);
			if (StrInput == string.Empty)
			{
				btnOK.IsEnabled = false;
			}
		}

		private void OnDialogLoaded(object sender, RoutedEventArgs e)
		{
			if (bUpperCase)
			{
				inputText.CharacterCasing = CharacterCasing.Upper;
			}
			inputText.MaxLength = max_length;
			inputText.Text = StrInput;
			inputText.CaretIndex = inputText.Text.Length;
			inputText.SelectAll();
			inputText.Focus();
		}

		private void OnClickOk(object sender, RoutedEventArgs e)
		{
			base.DialogResult = true;
			Close();
		}

		private void OnClickCancel(object sender, RoutedEventArgs e)
		{
			base.DialogResult = false;
			StrInput = string.Empty;
			Close();
		}

		private void OnTextChanged(object sender, RoutedEventArgs e)
		{
			if (inputText.Text == string.Empty)
			{
				btnOK.IsEnabled = false;
			}
			else
			{
				btnOK.IsEnabled = true;
			}
		}

		protected override void OnKeyDown(KeyEventArgs e)
		{
			if (e.Key == Key.Escape)
			{
				OnClickCancel(null, e);
			}
			else
			{
				base.OnKeyDown(e);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.PfsDialogs;component/pfstextinputdialog.xaml", UriKind.Relative);
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
				((PFSTextInputDialog)target).Loaded += OnDialogLoaded;
				break;
			case 2:
				stackPanel1 = (StackPanel)target;
				break;
			case 3:
				inputPrompt = (TextBlock)target;
				break;
			case 4:
				inputText = (TextBox)target;
				inputText.TextChanged += OnTextChanged;
				break;
			case 5:
				stackPanel2 = (StackPanel)target;
				break;
			case 6:
				btnOK = (Button)target;
				btnOK.Click += OnClickOk;
				break;
			case 7:
				btnCancel = (Button)target;
				btnCancel.Click += OnClickCancel;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class SplitMenuItem : MenuItem
	{
		public delegate void SplitMenuItemClickHandler(MenuItem e);

		public event SplitMenuItemClickHandler SplitMenuItemClick;

		static SplitMenuItem()
		{
			FrameworkElement.DefaultStyleKeyProperty.OverrideMetadata(typeof(SplitMenuItem), new FrameworkPropertyMetadata(typeof(SplitMenuItem)));
		}

		public SplitMenuItem()
		{
			base.Loaded += SplitMenuItem_Loaded;
		}

		private void SplitMenuItem_Loaded(object sender, RoutedEventArgs e)
		{
			base.PreviewMouseLeftButtonUp += SplitMenuItem_PreviewMouseLeftButtonUp;
		}

		private void SplitMenuItem_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
		{
			if ((!(e.OriginalSource is Border) || !((e.OriginalSource as Border).Name == "SplitButton_Arrow")) && !(e.OriginalSource is Path) && (e.Source == null || !(e.Source is MenuItem { Role: MenuItemRole.SubmenuItem })) && this.SplitMenuItemClick != null)
			{
				this.SplitMenuItemClick(this);
			}
		}
	}
}

// Original MethodDefs folded into compiler-generated high-level C# forms.
// The following token-specific expansions are provided for static comparison with the companion IL listing.
// The reconstructed active declarations and their original source line locations appear above.

// 0x06000006 XamlGeneratedNamespace.GeneratedInternalTypeHelper..ctor
// public GeneratedInternalTypeHelper()
// {
// }

// 0x06000058 AspenTech.AspenPlus.PfsDialogs.ContextMenuExtender..ctor
// public ContextMenuExtender()
// {
// }

// 0x06000066 AspenTech.AspenPlus.PfsDialogs.PFSCommonDialogs..ctor
// public PFSCommonDialogs()
// {
// }

// 0x06000087 AspenTech.AspenPlus.PfsDialogs.PFSPlotDialogs..ctor
// public PFSPlotDialogs()
// {
// }

// 0x060000ba AspenTech.AspenPlus.PfsDialogs.PFSFlowsheetDialogs..ctor
// public PFSFlowsheetDialogs()
// {
// }

// 0x060000bb AspenTech.AspenPlus.PfsDialogs.PFSFlowsheetDialogs..cctor
// using System.Collections.Generic;
//
// static PFSFlowsheetDialogs()
// {
// 	_pfsObjects = new List<string>
// 	{
// 		"Design-Spec", "Blocks", "Calculator", "Transfer", "Convergence", "Sensitivity", "Utilities", "Balance", "Pres-Relief", "Regression",
// 		"Sequence", "Measurement", "Connection"
// 	};
// 	_pfsPaths = new List<string>
// 	{
// 		"Blocks", "Utilities", "Flowsheeting Options.Calculator", "Flowsheeting Options.Design-Spec", "Flowsheeting Options.Transfer", "Flowsheeting Options.Balance", "Flowsheeting Options.Pres-Relief", "Flowsheeting Options.Measurement", "Model Analysis Tools.Sensitivity", "Model Analysis Tools.Data-Fit.Regression",
// 		"Convergence.Convergence", "Convergence.Sequence"
// 	};
// 	_sectionObjects = new List<string> { "Blocks", "Streams", "Section" };
// 	_sectionPaths = new List<string> { "Blocks", "Streams", "Flowsheet.Section" };
// 	_regressionOrReactions = new List<string> { "Regression", "Reactions" };
// 	_HcurvesNode = new List<string> { "Hcurves", "Condenser Hcurves", "Reboiler Hcurves", "Connect Stream Hcurves", "Hot Hcurves", "Cold Hcurves" };
// }

// 0x060000d2 AspenTech.AspenPlus.PfsDialogs.PFSIconEditorDialogs..ctor
// public PFSIconEditorDialogs()
// {
// }

// 0x060000f5 AspenTech.AspenPlus.PfsDialogs.BookmarkCollection..ctor
// public BookmarkCollection()
// {
// }

// 0x06000133 AspenTech.AspenPlus.PfsDialogs.PFSFindObjectsDialog..cctor
// static PFSFindObjectsDialog()
// {
// 	m_strCurrentBlockFilter = string.Empty;
// 	m_strCurrentStreamFilter = string.Empty;
// }

// 0x06000134 AspenTech.AspenPlus.PfsDialogs.SortedNameList..ctor
// public SortedNameList()
// {
// }

// 0x0600013d AspenTech.AspenPlus.PfsDialogs.ObjectNameList..ctor
// public ObjectNameList()
// {
// }

// 0x06000149 AspenTech.AspenPlus.PfsDialogs.HierarchyItemList..ctor
// public HierarchyItemList()
// {
// }

// 0x0600014d AspenTech.AspenPlus.PfsDialogs.CustomTooltipHelper..cctor
// using System;
// using AspenTech.AspenCxs;
// using Microsoft.Practices.Unity;
//
// static CustomTooltipHelper()
// {
// 	dataProvider = PfsDialogsModule.Container.Resolve<CxsCase>(Array.Empty<ResolverOverride>());
// }

// 0x06000176 AspenTech.AspenPlus.PfsDialogs.PFSMessageBox..ctor
// public PFSMessageBox()
// {
// }

// 0x060001e2 AspenTech.AspenPlus.PfsDialogs.BlockNameList..ctor
// public BlockNameList()
// {
// }

// 0x060001ee AspenTech.AspenPlus.PfsDialogs.SplitMenuItem.add_SplitMenuItemClick
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	SplitMenuItemClickHandler splitMenuItemClickHandler = this.SplitMenuItemClick;
// 	SplitMenuItemClickHandler splitMenuItemClickHandler2;
// 	do
// 	{
// 		splitMenuItemClickHandler2 = splitMenuItemClickHandler;
// 		SplitMenuItemClickHandler value2 = (SplitMenuItemClickHandler)Delegate.Combine(splitMenuItemClickHandler2, value);
// 		splitMenuItemClickHandler = Interlocked.CompareExchange(ref this.SplitMenuItemClick, value2, splitMenuItemClickHandler2);
// 	}
// 	while ((object)splitMenuItemClickHandler != splitMenuItemClickHandler2);
// }

// 0x060001ef AspenTech.AspenPlus.PfsDialogs.SplitMenuItem.remove_SplitMenuItemClick
// using System;
// using System.Runtime.CompilerServices;
// using System.Threading;
//
// [CompilerGenerated]
// {
// 	SplitMenuItemClickHandler splitMenuItemClickHandler = this.SplitMenuItemClick;
// 	SplitMenuItemClickHandler splitMenuItemClickHandler2;
// 	do
// 	{
// 		splitMenuItemClickHandler2 = splitMenuItemClickHandler;
// 		SplitMenuItemClickHandler value2 = (SplitMenuItemClickHandler)Delegate.Remove(splitMenuItemClickHandler2, value);
// 		splitMenuItemClickHandler = Interlocked.CompareExchange(ref this.SplitMenuItemClick, value2, splitMenuItemClickHandler2);
// 	}
// 	while ((object)splitMenuItemClickHandler != splitMenuItemClickHandler2);
// }

// 0x060001f4 AspenTech.AspenPlus.PfsDialogs.PFSContextMenu+<>c..cctor
// static <>c()
// {
// 	<>9 = new <>c();
// }

// 0x060001f5 AspenTech.AspenPlus.PfsDialogs.PFSContextMenu+<>c..ctor
// public <>c()
// {
// }

// 0x060001f9 AspenTech.AspenPlus.PfsDialogs.PFSContextMenu+<>c__DisplayClass83_0..ctor
// public <>c__DisplayClass83_0()
// {
// }

// 0x060001ff AspenTech.AspenPlus.PfsDialogs.ControlVariableListDialog+ControlVariable..ctor
// public ControlVariable()
// {
// }

// 0x06000202 AspenTech.AspenPlus.PfsDialogs.PFSIconImportDXFDialog+BlockLT..ctor
// public BlockLT()
// {
// }

// 0x06000205 AspenTech.AspenPlus.PfsDialogs.PFSPlotEditLegendDialog+Legend..ctor
// public Legend()
// {
// }
