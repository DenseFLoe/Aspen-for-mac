using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using AspenTech.AspenPlus.Localization;
using AspenTech.AspenPlus.WpfPropertyControl.DataHelper;
using AspenTech.AspenPlus.WpfPropertyControl.Images;
using AspenTech.WpfControls.Engineering;
using Infragistics.Controls.Editors;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("WpfPropertyControl")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("WpfPropertyControl")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("43da7be3-d755-404b-8252-f13f29388d41")]
[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenTech.AspenPlus.WpfPropertyControl.Images
{
	public static class ImageResources
	{
		private static readonly Dictionary<string, ImageSource> _imageSources = new Dictionary<string, ImageSource>();

		public static ImageSource Circle => GetImageSource("Circle.bmp");

		public static ImageSource CircleFill => GetImageSource("CircleFill.bmp");

		public static ImageSource CrisCross => GetImageSource("CrisCross.bmp");

		public static ImageSource Cross => GetImageSource("Cross.bmp");

		public static ImageSource Dashed => GetImageSource("Dashed.bmp");

		public static ImageSource DiagLeft => GetImageSource("DiagLeft.bmp");

		public static ImageSource DiagRight => GetImageSource("DiagRight.bmp");

		public static ImageSource Diamond => GetImageSource("Diamond.bmp");

		public static ImageSource DiamondFill => GetImageSource("DiamondFill.bmp");

		public static ImageSource DotDashed => GetImageSource("Dot-Dashed.bmp");

		public static ImageSource Dot1 => GetImageSource("Dot1.bmp");

		public static ImageSource Dot2 => GetImageSource("Dot2.bmp");

		public static ImageSource Dot3 => GetImageSource("Dot3.bmp");

		public static ImageSource Dotted => GetImageSource("Dotted.bmp");

		public static ImageSource HorizVert => GetImageSource("HorizVert.bmp");

		public static ImageSource Normal => GetImageSource("Normal.bmp");

		public static ImageSource Solid => GetImageSource("Solid.bmp");

		public static ImageSource Square => GetImageSource("Square.bmp");

		public static ImageSource SquareFill => GetImageSource("SquareFill.bmp");

		public static ImageSource StripeHoriz => GetImageSource("StripeHoriz.bmp");

		public static ImageSource StripeVert => GetImageSource("StripeVert.bmp");

		public static ImageSource Thick1 => GetImageSource("Thick1.bmp");

		public static ImageSource Thick2 => GetImageSource("Thick2.bmp");

		public static ImageSource Thick3 => GetImageSource("Thick3.bmp");

		public static ImageSource TriDown => GetImageSource("TriDown.bmp");

		public static ImageSource TriDownFill => GetImageSource("TriDownFill.bmp");

		public static ImageSource TriUp => GetImageSource("TriUp.bmp");

		public static ImageSource TriUpFill => GetImageSource("TriUpFill.bmp");

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
namespace AspenTech.AspenPlus.WpfPropertyControl.DataHelper
{
	public class AboutPage
	{
		public string ProductName { get; set; }

		public string Version { get; set; }

		public string Release { get; set; }
	}
	public class ComboItemClass
	{
		public ImageSource ImageValue { get; set; }

		public string TextValue { get; set; }

		public ComboItemClass(ImageSource image, string text)
		{
			ImageValue = image;
			TextValue = text;
		}
	}
	public class CurvesPage : INotifyPropertyChanged
	{
		private System.Windows.Media.Color m_Curve1ColourValue;

		private System.Windows.Media.Color m_Curve2ColourValue;

		public System.Windows.Media.Color Curve1ColourValue
		{
			get
			{
				if (m_Curve1ColourValue != Globals.GetColorByIndex(Curve1Colour))
				{
					m_Curve1ColourValue = Globals.GetColorByIndex(Curve1Colour);
				}
				return m_Curve1ColourValue;
			}
			set
			{
				if (m_Curve1ColourValue != value)
				{
					m_Curve1ColourValue = value;
					Curve1Colour = Globals.GetColorIndex(value);
					OnPropertyChanged("Curve1ColourValue");
				}
			}
		}

		public System.Windows.Media.Color Curve2ColourValue
		{
			get
			{
				if (m_Curve2ColourValue != Globals.GetColorByIndex(Curve2Colour))
				{
					m_Curve2ColourValue = Globals.GetColorByIndex(Curve2Colour);
				}
				return m_Curve2ColourValue;
			}
			set
			{
				if (m_Curve2ColourValue != value)
				{
					m_Curve2ColourValue = value;
					Curve2Colour = Globals.GetColorIndex(value);
					OnPropertyChanged("Curve2ColourValue");
				}
			}
		}

		public int Curve1Colour { get; set; }

		public int Curve2Colour { get; set; }

		public int Curve1Style { get; set; }

		public int Curve2Style { get; set; }

		public int Curve1MarkerStyle { get; set; }

		public int Curve2MarkerStyle { get; set; }

		public int Curve1MarkerSize { get; set; }

		public int Curve2MarkerSize { get; set; }

		public ObservableCollection<ComboItemClass> CurveStyleItemList => Globals.GetLineStyleList();

		public ObservableCollection<ComboItemClass> MarkerStyleItemList => Globals.GetMarkStyleList();

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}
	}
	public class EnvelopPage : INotifyPropertyChanged
	{
		private int m_VapMarkerSize;

		private int m_EnvPatern;

		private int m_LineStyle;

		private int m_LineMarkerStyle;

		private int m_VapMarkerStyle;

		private long m_EnvColourIndex;

		private System.Windows.Media.Color m_EnvColourValue;

		private long m_LineColourIndex;

		private System.Windows.Media.Color m_LineColourValue;

		public System.Windows.Media.Color EnvColorValue
		{
			get
			{
				if (m_EnvColourValue != Globals.GetColorByIndex((int)m_EnvColourIndex))
				{
					m_EnvColourValue = Globals.GetColorByIndex((int)m_EnvColourIndex);
				}
				return m_EnvColourValue;
			}
			set
			{
				if (m_EnvColourValue != value)
				{
					m_EnvColourValue = value;
					EnvColour = Globals.GetColorIndex(value);
					OnPropertyChanged("EnvColorValue");
				}
			}
		}

		public long EnvColour
		{
			get
			{
				return m_EnvColourIndex;
			}
			set
			{
				if (m_EnvColourIndex != value)
				{
					m_EnvColourIndex = value;
					EnvColorValue = Globals.GetColorByIndex((int)m_EnvColourIndex);
				}
			}
		}

		public System.Windows.Media.Color LineColorValue
		{
			get
			{
				if (m_LineColourValue != Globals.GetColorByIndex((int)m_LineColourIndex))
				{
					m_LineColourValue = Globals.GetColorByIndex((int)m_LineColourIndex);
				}
				return m_LineColourValue;
			}
			set
			{
				if (m_LineColourValue != value)
				{
					m_LineColourValue = value;
					LineColour = Globals.GetColorIndex(value);
					OnPropertyChanged("LineColorValue");
				}
			}
		}

		public long LineColour
		{
			get
			{
				return m_LineColourIndex;
			}
			set
			{
				if (m_LineColourIndex != value)
				{
					m_LineColourIndex = value;
					LineColorValue = Globals.GetColorByIndex((int)m_LineColourIndex);
				}
			}
		}

		public int EnvPatern
		{
			get
			{
				return m_EnvPatern;
			}
			set
			{
				if (m_EnvPatern != value)
				{
					m_EnvPatern = value;
					OnPropertyChanged("EnvPatern");
				}
			}
		}

		public int LineStyle
		{
			get
			{
				return m_LineStyle;
			}
			set
			{
				if (m_LineStyle != value)
				{
					m_LineStyle = value;
					OnPropertyChanged("LineStyle");
				}
			}
		}

		public int LineMarkerStyle
		{
			get
			{
				return m_LineMarkerStyle;
			}
			set
			{
				if (m_LineMarkerStyle != value)
				{
					m_LineMarkerStyle = value;
					OnPropertyChanged("LineMarkerStyle");
				}
			}
		}

		public int VapMarkerStyle
		{
			get
			{
				return m_VapMarkerStyle;
			}
			set
			{
				if (m_VapMarkerStyle != value)
				{
					m_VapMarkerStyle = value;
					OnPropertyChanged("VapMarkerStyle");
				}
			}
		}

		public int VapMarkerSize
		{
			get
			{
				return m_VapMarkerSize;
			}
			set
			{
				if (m_VapMarkerSize != value)
				{
					m_VapMarkerSize = value;
					OnPropertyChanged("VapMarkerSize");
				}
			}
		}

		public ObservableCollection<ComboItemClass> MarkerItemList => Globals.GetMarkStyleList();

		public ObservableCollection<ComboItemClass> EnvItemList => Globals.GetEnvPatternList();

		public ObservableCollection<ComboItemClass> LineItemList => Globals.GetLineStyleList();

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}
	}
	public class GeneralPage : INotifyPropertyChanged
	{
		private ObservableCollection<string> m_FontFamilies;

		private bool m_Coord;

		private bool m_BoilingPoint;

		private bool m_Transparent;

		private bool m_Stages;

		private string m_Font = string.Empty;

		private int m_FontSize;

		private long m_ToolBarPos;

		public bool Coord
		{
			get
			{
				return m_Coord;
			}
			set
			{
				if (m_Coord != value)
				{
					m_Coord = value;
					OnPropertyChanged("Coord");
				}
			}
		}

		public bool BoilingPoint
		{
			get
			{
				return m_BoilingPoint;
			}
			set
			{
				if (m_BoilingPoint != value)
				{
					m_BoilingPoint = value;
					OnPropertyChanged("BoilingPoint");
				}
			}
		}

		public bool Transparent
		{
			get
			{
				return m_Transparent;
			}
			set
			{
				if (m_Transparent != value)
				{
					m_Transparent = value;
					OnPropertyChanged("Transparent");
				}
			}
		}

		public bool Stages
		{
			get
			{
				return m_Stages;
			}
			set
			{
				if (m_Stages != value)
				{
					m_Stages = value;
					OnPropertyChanged("Stages");
				}
			}
		}

		public string Font
		{
			get
			{
				return m_Font;
			}
			set
			{
				if (m_Font != value)
				{
					m_Font = value;
					OnPropertyChanged("Font");
				}
			}
		}

		public int FontSize
		{
			get
			{
				return m_FontSize;
			}
			set
			{
				if (m_FontSize != value)
				{
					m_FontSize = value;
					OnPropertyChanged("FontSize");
				}
			}
		}

		public long ToolBarPos
		{
			get
			{
				return m_ToolBarPos;
			}
			set
			{
				m_ToolBarPos = value;
			}
		}

		public string ToolBarPosString
		{
			get
			{
				return ToolBarPositions[(int)ToolBarPos];
			}
			set
			{
				int num = ToolBarPositions.IndexOf(value);
				if (num != ToolBarPos)
				{
					ToolBarPos = num;
					OnPropertyChanged("ToolBarPosString");
				}
			}
		}

		public ObservableCollection<string> SystemFontFamilies => m_FontFamilies;

		public ObservableCollection<string> ToolBarPositions => new ObservableCollection<string>(new string[4]
		{
			WpfPropertyControlResources.R309_NoneString,
			WpfPropertyControlResources.R310_TopString,
			WpfPropertyControlResources.R311_BottomString,
			WpfPropertyControlResources.R312_RightString
		});

		public event PropertyChangedEventHandler PropertyChanged;

		public GeneralPage()
		{
			GetFontFamilies();
		}

		private void GetFontFamilies()
		{
			m_FontFamilies = new ObservableCollection<string>();
			System.Drawing.FontFamily[] families = System.Drawing.FontFamily.Families;
			foreach (System.Drawing.FontFamily fontFamily in families)
			{
				m_FontFamilies.Add(fontFamily.Name);
			}
		}

		private void OnPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	internal class Globals
	{
		public static readonly int SW_SHOWNORMAL = 1;

		public static readonly Collection<System.Windows.Media.Color> BuiltInColors = new Collection<System.Windows.Media.Color>
		{
			System.Windows.Media.Color.FromRgb(0, 0, 0),
			System.Windows.Media.Color.FromRgb(64, 64, 192),
			System.Windows.Media.Color.FromRgb(0, 128, 0),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, 64, 128),
			System.Windows.Media.Color.FromRgb(192, 64, 192),
			System.Windows.Media.Color.FromRgb(128, 128, 128),
			System.Windows.Media.Color.FromRgb(32, 160, 160),
			System.Windows.Media.Color.FromRgb(192, 192, 192),
			System.Windows.Media.Color.FromRgb(192, 192, 0),
			System.Windows.Media.Color.FromRgb(0, 0, byte.MaxValue),
			System.Windows.Media.Color.FromRgb(0, byte.MaxValue, 0),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, 0, 0),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, 0, byte.MaxValue),
			System.Windows.Media.Color.FromRgb(224, 224, 224),
			System.Windows.Media.Color.FromRgb(0, byte.MaxValue, byte.MaxValue),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, byte.MaxValue, 0),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, byte.MaxValue, byte.MaxValue),
			System.Windows.Media.Color.FromRgb(byte.MaxValue, 128, 0)
		};

		public static void FillColour(XamColorPicker myColorPicker)
		{
			ColorPalette colorPalette = new ColorPalette();
			for (int i = 0; i <= 9; i++)
			{
				colorPalette.Colors.Add(BuiltInColors[i]);
			}
			ColorPalette colorPalette2 = new ColorPalette();
			for (int j = 10; j < BuiltInColors.Count; j++)
			{
				colorPalette2.Colors.Add(BuiltInColors[j]);
			}
			myColorPicker.ColorPalettes.Clear();
			myColorPicker.ColorPalettes.Add(colorPalette);
			myColorPicker.ColorPalettes.Add(colorPalette2);
		}

		public static int GetColorIndex(System.Windows.Media.Color selectedColor)
		{
			int num = BuiltInColors.IndexOf(selectedColor);
			if (num < 0)
			{
				num = 0;
			}
			return num;
		}

		public static System.Windows.Media.Color GetColorByIndex(int selectedColorIndex)
		{
			if (selectedColorIndex >= 0 && selectedColorIndex < BuiltInColors.Count)
			{
				return BuiltInColors[selectedColorIndex];
			}
			return BuiltInColors[0];
		}

		public static long StartURL(string URL)
		{
			Process.Start(URL);
			return 0L;
		}

		public static ObservableCollection<ComboItemClass> GetMarkStyleList()
		{
			return new ObservableCollection<ComboItemClass>
			{
				new ComboItemClass(null, WpfPropertyControlResources.R104_NoneItemString),
				new ComboItemClass(ImageResources.Circle, "1"),
				new ComboItemClass(ImageResources.Square, "2"),
				new ComboItemClass(ImageResources.Diamond, "3"),
				new ComboItemClass(ImageResources.TriUp, "4"),
				new ComboItemClass(ImageResources.TriDown, "5"),
				new ComboItemClass(ImageResources.CircleFill, "6"),
				new ComboItemClass(ImageResources.SquareFill, "7"),
				new ComboItemClass(ImageResources.DiamondFill, "8"),
				new ComboItemClass(ImageResources.TriUpFill, "9"),
				new ComboItemClass(ImageResources.TriDownFill, "10"),
				new ComboItemClass(ImageResources.Cross, "11")
			};
		}

		public static ObservableCollection<ComboItemClass> GetEnvPatternList()
		{
			return new ObservableCollection<ComboItemClass>
			{
				new ComboItemClass(ImageResources.Solid, ""),
				new ComboItemClass(ImageResources.DiagLeft, ""),
				new ComboItemClass(ImageResources.HorizVert, ""),
				new ComboItemClass(ImageResources.CrisCross, ""),
				new ComboItemClass(ImageResources.DiagRight, ""),
				new ComboItemClass(ImageResources.StripeHoriz, ""),
				new ComboItemClass(ImageResources.StripeVert, ""),
				new ComboItemClass(ImageResources.Dot1, ""),
				new ComboItemClass(ImageResources.Dot2, ""),
				new ComboItemClass(ImageResources.Dot3, "")
			};
		}

		public static ObservableCollection<ComboItemClass> GetLineStyleList()
		{
			return new ObservableCollection<ComboItemClass>
			{
				new ComboItemClass(ImageResources.Normal, ""),
				new ComboItemClass(ImageResources.Dotted, ""),
				new ComboItemClass(ImageResources.Dashed, ""),
				new ComboItemClass(ImageResources.DotDashed, ""),
				new ComboItemClass(ImageResources.Thick1, ""),
				new ComboItemClass(ImageResources.Thick2, ""),
				new ComboItemClass(ImageResources.Thick3, "")
			};
		}
	}
	public enum Settings
	{
		set_AdjustYes,
		set_AdjustNo,
		set_AdjustDefault
	}
	public enum PageEnum
	{
		page_General,
		page_Azeotropes,
		page_Boundary,
		page_Envelope,
		page_Curves,
		page_Markers,
		page_FreeHand,
		page_MatBal,
		page_Product,
		page_Feed,
		page_Profiles,
		page_Decanter,
		page_ColumnVapor
	}
	public class LinePage : INotifyPropertyChanged
	{
		private int m_MarkerSize;

		private int m_LineStyle;

		private int m_MarkerStyle;

		private System.Windows.Media.Color m_LineColourValue;

		private long m_LineColourIndex;

		public System.Windows.Media.Color LineColourValue
		{
			get
			{
				if (m_LineColourValue != Globals.GetColorByIndex((int)m_LineColourIndex))
				{
					m_LineColourValue = Globals.GetColorByIndex((int)m_LineColourIndex);
				}
				return m_LineColourValue;
			}
			set
			{
				if (m_LineColourValue != value)
				{
					m_LineColourValue = value;
					LineColour = Globals.GetColorIndex(value);
					OnPropertyChanged("LineColourValue");
				}
			}
		}

		public long LineColour
		{
			get
			{
				return m_LineColourIndex;
			}
			set
			{
				if (m_LineColourIndex != value)
				{
					m_LineColourIndex = value;
					LineColourValue = Globals.GetColorByIndex((int)m_LineColourIndex);
				}
			}
		}

		public int MarkerSize
		{
			get
			{
				return m_MarkerSize;
			}
			set
			{
				if (m_MarkerSize != value)
				{
					m_MarkerSize = value;
					OnPropertyChanged("MarkerSize");
				}
			}
		}

		public int LineStyle
		{
			get
			{
				return m_LineStyle;
			}
			set
			{
				if (m_LineStyle != value)
				{
					m_LineStyle = value;
					OnPropertyChanged("LineStyle");
				}
			}
		}

		public int MarkerStyle
		{
			get
			{
				return m_MarkerStyle;
			}
			set
			{
				if (m_MarkerStyle != value)
				{
					m_MarkerStyle = value;
					OnPropertyChanged("MarkerStyle");
				}
			}
		}

		public ObservableCollection<ComboItemClass> MarkerItemList => Globals.GetMarkStyleList();

		public ObservableCollection<ComboItemClass> LineItemList => Globals.GetLineStyleList();

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}
	}
	public class MarkerPage : INotifyPropertyChanged
	{
		private int m_MarkerSize;

		private int m_MarkerStyleIndex;

		private long m_MarkerColorIndex;

		private System.Windows.Media.Color m_MarkerColorValue;

		public System.Windows.Media.Color MarkerColorValue
		{
			get
			{
				if (m_MarkerColorValue != Globals.GetColorByIndex((int)m_MarkerColorIndex))
				{
					m_MarkerColorValue = Globals.GetColorByIndex((int)m_MarkerColorIndex);
				}
				return m_MarkerColorValue;
			}
			set
			{
				if (m_MarkerColorValue != value)
				{
					m_MarkerColorValue = value;
					MarkerColour = Globals.GetColorIndex(value);
					OnPropertyChanged("MarkerColorValue");
				}
			}
		}

		public long MarkerColour
		{
			get
			{
				return m_MarkerColorIndex;
			}
			set
			{
				if (m_MarkerColorIndex != value)
				{
					m_MarkerColorIndex = value;
					MarkerColorValue = Globals.GetColorByIndex((int)m_MarkerColorIndex);
				}
			}
		}

		public int MarkerStyle
		{
			get
			{
				return m_MarkerStyleIndex;
			}
			set
			{
				if (m_MarkerStyleIndex != value)
				{
					m_MarkerStyleIndex = value;
					OnPropertyChanged("MarkerStyle");
				}
			}
		}

		public int MarkerSize
		{
			get
			{
				return m_MarkerSize;
			}
			set
			{
				if (m_MarkerSize != value)
				{
					m_MarkerSize = value;
					OnPropertyChanged("MarkerSize");
				}
			}
		}

		public ObservableCollection<ComboItemClass> ItemList => Globals.GetMarkStyleList();

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string propName)
		{
			if (this.PropertyChanged != null)
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}
	}
	public class PropPage
	{
		private AboutPage _objAboutProps = new AboutPage();

		private GeneralPage _objGeneralProps = new GeneralPage();

		private MarkerPage _objAzeoProps = new MarkerPage();

		private MarkerPage _objBoundayProps = new MarkerPage();

		private EnvelopPage _objEnvelopeProps = new EnvelopPage();

		private CurvesPage _objCurveProps = new CurvesPage();

		private MarkerPage _objMarkerProps = new MarkerPage();

		private LinePage _objFreeHandProps = new LinePage();

		private LinePage _objMatBalProps = new LinePage();

		private MarkerPage _objProductProps = new MarkerPage();

		private MarkerPage _objFeedProps = new MarkerPage();

		private CurvesPage _objProfilesProps = new CurvesPage();

		private LinePage _objDecanterProps = new LinePage();

		private MarkerPage _objColumnVapourProps = new MarkerPage();

		public AboutPage AboutProps
		{
			get
			{
				return _objAboutProps;
			}
			set
			{
				_objAboutProps = value;
			}
		}

		public GeneralPage GeneralProps
		{
			get
			{
				return _objGeneralProps;
			}
			set
			{
				_objGeneralProps = value;
			}
		}

		public MarkerPage AzeoProps
		{
			get
			{
				return _objAzeoProps;
			}
			set
			{
				_objAzeoProps = value;
			}
		}

		public MarkerPage BoundayProps
		{
			get
			{
				return _objBoundayProps;
			}
			set
			{
				_objBoundayProps = value;
			}
		}

		public EnvelopPage EnvelopeProps
		{
			get
			{
				return _objEnvelopeProps;
			}
			set
			{
				_objEnvelopeProps = value;
			}
		}

		public CurvesPage CurveProps
		{
			get
			{
				return _objCurveProps;
			}
			set
			{
				_objCurveProps = value;
			}
		}

		public MarkerPage MarkerProps
		{
			get
			{
				return _objMarkerProps;
			}
			set
			{
				_objMarkerProps = value;
			}
		}

		public LinePage FreeHandProps
		{
			get
			{
				return _objFreeHandProps;
			}
			set
			{
				_objFreeHandProps = value;
			}
		}

		public LinePage MatBalProps
		{
			get
			{
				return _objMatBalProps;
			}
			set
			{
				_objMatBalProps = value;
			}
		}

		public MarkerPage ProductProps
		{
			get
			{
				return _objProductProps;
			}
			set
			{
				_objProductProps = value;
			}
		}

		public MarkerPage FeedProps
		{
			get
			{
				return _objFeedProps;
			}
			set
			{
				_objFeedProps = value;
			}
		}

		public CurvesPage ProfilesProps
		{
			get
			{
				return _objProfilesProps;
			}
			set
			{
				_objProfilesProps = value;
			}
		}

		public LinePage DecanterProps
		{
			get
			{
				return _objDecanterProps;
			}
			set
			{
				_objDecanterProps = value;
			}
		}

		public MarkerPage ColumnVapourProps
		{
			get
			{
				return _objColumnVapourProps;
			}
			set
			{
				_objColumnVapourProps = value;
			}
		}
	}
}
namespace AspenTech.AspenPlus.WpfPropertyControl.Controls
{
	public class UsrCurvesPage : UserControl, IComponentConnector
	{
		private PageEnum m_PageType;

		internal GroupBox fraCurve;

		internal Label lblCurve1;

		internal Label lblCurve2;

		internal Label lblCurveColour;

		internal Label lblCurveStyle;

		internal Label lblCurveMarkerStyle;

		internal Label lblCurveMarkerSize;

		internal XamColorPicker cboCurve1Colour;

		internal XamColorPicker cboCurve2Colour;

		internal ComboBox cboCurve1Style;

		internal ComboBox cboCurve2Style;

		internal ComboBox cboCurve1MarkerStyle;

		internal ComboBox cboCurve2MarkerStyle;

		internal AesSpinBox txtCurve1MarkerSize;

		internal AesSpinBox txtCurve2MarkerSize;

		private bool _contentLoaded;

		public UsrCurvesPage(CurvesPage pageObject)
		{
			InitializeComponent();
			base.Loaded += UsrCurvesPage_Loaded;
			base.DataContext = pageObject;
			Globals.FillColour(cboCurve1Colour);
			Globals.FillColour(cboCurve2Colour);
		}

		private void UsrCurvesPage_Loaded(object sender, RoutedEventArgs e)
		{
			LoadCaptions();
		}

		public void SetPageType(PageEnum type)
		{
			m_PageType = type;
		}

		private void LoadCaptions()
		{
			switch (m_PageType)
			{
			case PageEnum.page_Curves:
				fraCurve.Header = WpfPropertyControlResources.R701_RDCString;
				lblCurve1.Content = WpfPropertyControlResources.R702_ResidueString;
				lblCurve2.Content = WpfPropertyControlResources.R703_DistiString;
				lblCurveColour.Content = WpfPropertyControlResources.R704_CCString;
				lblCurveStyle.Content = WpfPropertyControlResources.R705_CSString;
				lblCurveMarkerStyle.Content = WpfPropertyControlResources.R706_MarkerStyleString;
				lblCurveMarkerSize.Content = WpfPropertyControlResources.R707_MarkerSizeString;
				break;
			case PageEnum.page_Profiles:
				fraCurve.Header = WpfPropertyControlResources.R1301_SRPString;
				lblCurve1.Content = WpfPropertyControlResources.R1302_StrippingString;
				lblCurve2.Content = WpfPropertyControlResources.R1303_RectifyingString;
				lblCurveColour.Content = WpfPropertyControlResources.R704_CCString;
				lblCurveStyle.Content = WpfPropertyControlResources.R705_CSString;
				lblCurveMarkerStyle.Content = WpfPropertyControlResources.R706_MarkerStyleString;
				lblCurveMarkerSize.Content = WpfPropertyControlResources.R707_MarkerSizeString;
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
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrcurvespage.xaml", UriKind.Relative);
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
				fraCurve = (GroupBox)target;
				break;
			case 2:
				lblCurve1 = (Label)target;
				break;
			case 3:
				lblCurve2 = (Label)target;
				break;
			case 4:
				lblCurveColour = (Label)target;
				break;
			case 5:
				lblCurveStyle = (Label)target;
				break;
			case 6:
				lblCurveMarkerStyle = (Label)target;
				break;
			case 7:
				lblCurveMarkerSize = (Label)target;
				break;
			case 8:
				cboCurve1Colour = (XamColorPicker)target;
				break;
			case 9:
				cboCurve2Colour = (XamColorPicker)target;
				break;
			case 10:
				cboCurve1Style = (ComboBox)target;
				break;
			case 11:
				cboCurve2Style = (ComboBox)target;
				break;
			case 12:
				cboCurve1MarkerStyle = (ComboBox)target;
				break;
			case 13:
				cboCurve2MarkerStyle = (ComboBox)target;
				break;
			case 14:
				txtCurve1MarkerSize = (AesSpinBox)target;
				break;
			case 15:
				txtCurve2MarkerSize = (AesSpinBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrAboutPage : UserControl, IComponentConnector
	{
		private AboutPage _AboutPage = new AboutPage();

		internal AesGroupBox fraAbout;

		internal AesLabel lblGUIName;

		internal AesLabel lblProductName;

		internal AesLabel lblRelease;

		internal AesLabel lblVersion;

		internal Button cmdWebLink;

		internal AesLabel lblCompany;

		private bool _contentLoaded;

		public AboutPage AboutPage
		{
			get
			{
				return _AboutPage;
			}
			set
			{
				if (value != null)
				{
					_AboutPage = value;
					SetData();
				}
				else
				{
					_AboutPage = null;
				}
			}
		}

		public UsrAboutPage()
		{
			InitializeComponent();
			fraAbout.Header = WpfPropertyControlResources.R201_AboutString;
			lblGUIName.Content = WpfPropertyControlResources.R202_TitleString;
			lblCompany.Content = WpfPropertyControlResources.R205_CopyRightString + WpfPropertyControlResources.R206_ATCompamyString;
			cmdWebLink.Content = WpfPropertyControlResources.R207_ATWebLinkString;
		}

		private void cmdWebLink_Click(object sender, RoutedEventArgs e)
		{
			Globals.StartURL(WpfPropertyControlResources.R207_ATWebLinkString);
		}

		private void SetData()
		{
			lblProductName.Content = _AboutPage.ProductName;
			lblRelease.Content = WpfPropertyControlResources.R203_ReleaseString + _AboutPage.Release;
			lblVersion.Content = WpfPropertyControlResources.R204_VersionString + _AboutPage.Version;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usraboutpage.xaml", UriKind.Relative);
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
				fraAbout = (AesGroupBox)target;
				break;
			case 2:
				lblGUIName = (AesLabel)target;
				break;
			case 3:
				lblProductName = (AesLabel)target;
				break;
			case 4:
				lblRelease = (AesLabel)target;
				break;
			case 5:
				lblVersion = (AesLabel)target;
				break;
			case 6:
				cmdWebLink = (Button)target;
				cmdWebLink.Click += cmdWebLink_Click;
				break;
			case 7:
				lblCompany = (AesLabel)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrEnvelopePage : UserControl, IComponentConnector
	{
		internal AesGroupBox fraEnvelope;

		internal Label lblEnvColour;

		internal Label lblEnvPattern;

		internal Label lblLineColour;

		internal Label lblLineStyle;

		internal Label lblLineMarkerStyle;

		internal Label lblVapMarkerStyle;

		internal Label lblVapMarkerSize;

		internal XamColorPicker EnvColorPicker;

		internal ComboBox EnvPatternStyleEditor;

		internal XamColorPicker LineColorPicker;

		internal ComboBox LineStyleEditor;

		internal ComboBox LineMarkerEditor;

		internal ComboBox VapMarkerStyleEditor;

		private bool _contentLoaded;

		public UsrEnvelopePage(EnvelopPage pageObject)
		{
			InitializeComponent();
			base.DataContext = pageObject;
		}

		private void UserControl_Loaded(object sender, RoutedEventArgs e)
		{
			LoadCaptions();
			LoadColors();
		}

		private void LoadCaptions()
		{
			fraEnvelope.Header = WpfPropertyControlResources.R601_EATString;
			lblEnvColour.Content = WpfPropertyControlResources.R602_ECString;
			lblEnvPattern.Content = WpfPropertyControlResources.R603_EFPString;
			lblLineColour.Content = WpfPropertyControlResources.R604_TLCString;
			lblLineStyle.Content = WpfPropertyControlResources.R605_TLSString;
			lblLineMarkerStyle.Content = WpfPropertyControlResources.R606_TLMSString;
			lblVapMarkerStyle.Content = WpfPropertyControlResources.R607_VMSString;
			lblVapMarkerSize.Content = WpfPropertyControlResources.R608_MarkerSizeString;
		}

		private void LoadColors()
		{
			Globals.FillColour(EnvColorPicker);
			Globals.FillColour(LineColorPicker);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrenvelopepage.xaml", UriKind.Relative);
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
				((UsrEnvelopePage)target).Loaded += UserControl_Loaded;
				break;
			case 2:
				fraEnvelope = (AesGroupBox)target;
				break;
			case 3:
				lblEnvColour = (Label)target;
				break;
			case 4:
				lblEnvPattern = (Label)target;
				break;
			case 5:
				lblLineColour = (Label)target;
				break;
			case 6:
				lblLineStyle = (Label)target;
				break;
			case 7:
				lblLineMarkerStyle = (Label)target;
				break;
			case 8:
				lblVapMarkerStyle = (Label)target;
				break;
			case 9:
				lblVapMarkerSize = (Label)target;
				break;
			case 10:
				EnvColorPicker = (XamColorPicker)target;
				break;
			case 11:
				EnvPatternStyleEditor = (ComboBox)target;
				break;
			case 12:
				LineColorPicker = (XamColorPicker)target;
				break;
			case 13:
				LineStyleEditor = (ComboBox)target;
				break;
			case 14:
				LineMarkerEditor = (ComboBox)target;
				break;
			case 15:
				VapMarkerStyleEditor = (ComboBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrGeneralPage : UserControl, IComponentConnector
	{
		private GeneralPage m_GeneralPage;

		internal AesGroupBox fraGeneral;

		internal AesCheckBox chkCoord;

		internal AesCheckBox chkBoilingPoint;

		internal AesCheckBox chkTransparent;

		internal AesCheckBox chkStages;

		internal Label lblFont;

		internal Label lblFontSize;

		internal Label lblToolBarPos;

		private bool _contentLoaded;

		public GeneralPage GeneralPage => m_GeneralPage;

		public UsrGeneralPage(GeneralPage pageObject)
		{
			InitializeComponent();
			m_GeneralPage = pageObject;
		}

		private void UserControl_Loaded(object sender, RoutedEventArgs e)
		{
			base.DataContext = m_GeneralPage;
			LoadCaptions();
		}

		private void LoadCaptions()
		{
			fraGeneral.Header = WpfPropertyControlResources.R301_GeneralString;
			chkCoord.Content = WpfPropertyControlResources.R302_DisplayFeedbackString;
			chkBoilingPoint.Content = WpfPropertyControlResources.R303_BoilingPointInfoString;
			chkTransparent.Content = WpfPropertyControlResources.R304_TransparentLabelString;
			chkStages.Content = WpfPropertyControlResources.R305_StageDataString;
			lblFont.Content = WpfPropertyControlResources.R306_FontLabelString;
			lblFontSize.Content = WpfPropertyControlResources.R307_FontSizeString;
			lblToolBarPos.Content = WpfPropertyControlResources.R308_ToolbarPosString;
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrgeneralpage.xaml", UriKind.Relative);
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
				((UsrGeneralPage)target).Loaded += UserControl_Loaded;
				break;
			case 2:
				fraGeneral = (AesGroupBox)target;
				break;
			case 3:
				chkCoord = (AesCheckBox)target;
				break;
			case 4:
				chkBoilingPoint = (AesCheckBox)target;
				break;
			case 5:
				chkTransparent = (AesCheckBox)target;
				break;
			case 6:
				chkStages = (AesCheckBox)target;
				break;
			case 7:
				lblFont = (Label)target;
				break;
			case 8:
				lblFontSize = (Label)target;
				break;
			case 9:
				lblToolBarPos = (Label)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrLinePage : UserControl, IComponentConnector
	{
		private PageEnum m_PageType;

		internal AesGroupBox fraLine;

		internal Label lblLineColour;

		internal Label lblLineStyle;

		internal Label lblMarkerStyle;

		internal Label lblMarkerSize;

		internal XamColorPicker LineColorPicker;

		internal ComboBox LineStyleEditor;

		internal ComboBox LineMarkStyleEditor;

		private bool _contentLoaded;

		public UsrLinePage(LinePage pageObject)
		{
			InitializeComponent();
			base.DataContext = pageObject;
			LoadColors();
		}

		public void SetDataContext(LinePage page)
		{
			base.DataContext = page;
		}

		public void SetPageType(PageEnum type)
		{
			m_PageType = type;
		}

		private void LoadColors()
		{
			Globals.FillColour(LineColorPicker);
		}

		private void LoadCaptions()
		{
			switch (m_PageType)
			{
			case PageEnum.page_FreeHand:
				fraLine.Header = WpfPropertyControlResources.R901_FLinesString;
				lblLineColour.Content = WpfPropertyControlResources.R902_LCString;
				lblLineStyle.Content = WpfPropertyControlResources.R903_LSString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R904_LMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R905_LMSizeString;
				break;
			case PageEnum.page_MatBal:
			case PageEnum.page_Decanter:
				fraLine.Header = WpfPropertyControlResources.R1001_MBLString;
				lblLineColour.Content = WpfPropertyControlResources.R902_LCString;
				lblLineStyle.Content = WpfPropertyControlResources.R903_LSString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R904_LMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R905_LMSizeString;
				break;
			}
		}

		private void UserControl_Loaded(object sender, RoutedEventArgs e)
		{
			LoadCaptions();
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrlinepage.xaml", UriKind.Relative);
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
				((UsrLinePage)target).Loaded += UserControl_Loaded;
				break;
			case 2:
				fraLine = (AesGroupBox)target;
				break;
			case 3:
				lblLineColour = (Label)target;
				break;
			case 4:
				lblLineStyle = (Label)target;
				break;
			case 5:
				lblMarkerStyle = (Label)target;
				break;
			case 6:
				lblMarkerSize = (Label)target;
				break;
			case 7:
				LineColorPicker = (XamColorPicker)target;
				break;
			case 8:
				LineStyleEditor = (ComboBox)target;
				break;
			case 9:
				LineMarkStyleEditor = (ComboBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrMarkerPage : UserControl, IComponentConnector
	{
		private PageEnum m_PageType;

		internal AesGroupBox fraMarker;

		internal Label lblMarkerColour;

		internal Label lblMarkerStyle;

		internal Label lblMarkerSize;

		internal XamColorPicker MyColorPicker;

		internal ComboBox MyMarkStyleEditor;

		private bool _contentLoaded;

		public UsrMarkerPage(MarkerPage pageObject)
		{
			InitializeComponent();
			base.DataContext = pageObject;
		}

		public void SetDataContext(MarkerPage page)
		{
			base.DataContext = page;
		}

		public void SetPageType(PageEnum type)
		{
			m_PageType = type;
		}

		private void UserControl_Loaded(object sender, RoutedEventArgs e)
		{
			LoadCaptions();
			LoadColors();
		}

		private void LoadCaptions()
		{
			switch (m_PageType)
			{
			case PageEnum.page_Azeotropes:
				fraMarker.Header = WpfPropertyControlResources.R401_AzeotropesString;
				lblMarkerColour.Content = WpfPropertyControlResources.R402_BPMColorString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R403_BPMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R404_BPMSizeString;
				break;
			case PageEnum.page_Boundary:
				fraMarker.Header = WpfPropertyControlResources.R501_DistBoundaryString;
				lblMarkerColour.Content = WpfPropertyControlResources.R502_BoundaryColorString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R503_BMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R504_BMSizeString;
				break;
			case PageEnum.page_Markers:
				fraMarker.Header = WpfPropertyControlResources.R801_UMString;
				lblMarkerColour.Content = WpfPropertyControlResources.R802_UMCString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R803_UMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R804_UMSizeString;
				break;
			case PageEnum.page_Product:
				fraMarker.Header = WpfPropertyControlResources.R1101_PMString;
				lblMarkerColour.Content = WpfPropertyControlResources.R1102_PMColorString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R1103_PMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R1104_PMSizeString;
				break;
			case PageEnum.page_Feed:
				fraMarker.Header = WpfPropertyControlResources.R1201_FMString;
				lblMarkerColour.Content = WpfPropertyControlResources.R1202_FMColorString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R1203_FMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R1204_FMSizeString;
				break;
			case PageEnum.page_ColumnVapor:
				fraMarker.Header = WpfPropertyControlResources.R1501_CVString;
				lblMarkerColour.Content = WpfPropertyControlResources.R1502_CMCString;
				lblMarkerStyle.Content = WpfPropertyControlResources.R1503_CMStyleString;
				lblMarkerSize.Content = WpfPropertyControlResources.R1504_CMSizeString;
				break;
			}
		}

		private void LoadColors()
		{
			Globals.FillColour(MyColorPicker);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrmarkerpage.xaml", UriKind.Relative);
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
				((UsrMarkerPage)target).Loaded += UserControl_Loaded;
				break;
			case 2:
				fraMarker = (AesGroupBox)target;
				break;
			case 3:
				lblMarkerColour = (Label)target;
				break;
			case 4:
				lblMarkerStyle = (Label)target;
				break;
			case 5:
				lblMarkerSize = (Label)target;
				break;
			case 6:
				MyColorPicker = (XamColorPicker)target;
				break;
			case 7:
				MyMarkStyleEditor = (ComboBox)target;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
	public class UsrPropPage : UserControl, IComponentConnector
	{
		private UsrCurvesPage m_CurvesPage;

		private UsrEnvelopePage m_EnvelopePage;

		private UsrGeneralPage m_GeneralPage;

		private UsrLinePage m_LinePage;

		private UsrMarkerPage m_MarkerPage;

		private PageEnum _propStartPage;

		internal ListBox PropertyPageList;

		internal GridSplitter gridSplitter1;

		internal UserControl rightViewPanel;

		internal Button btnOk;

		internal Button btnDefault;

		internal Button btnCancel;

		private bool _contentLoaded;

		public Settings AdjustSettings { get; set; }

		public PropPage PropPage { get; set; }

		public PageEnum PropStartPage
		{
			get
			{
				return _propStartPage;
			}
			set
			{
				_propStartPage = value;
				PropertyPageList.SelectedIndex = (int)value;
			}
		}

		public event EventHandler OKButtonClick;

		public event EventHandler DefaultButtonClick;

		public event EventHandler CancelButtonClick;

		public UsrPropPage()
		{
			InitializeComponent();
			PropPage = new PropPage();
			LoadPropertyPageList();
		}

		private void UserControl_Loaded(object sender, RoutedEventArgs e)
		{
			LoadButtonText();
		}

		private void LoadPropertyPageList()
		{
			PropertyPageList.Items.Add(WpfPropertyControlResources.R301_GeneralString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R401_AzeotropesString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R501_DistBoundaryString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R601_EATString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R701_RDCString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R801_UMString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R901_FLinesString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1001_MBLString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1101_PMString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1201_FMString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1301_SRPString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1401_DecanterString);
			PropertyPageList.Items.Add(WpfPropertyControlResources.R1501_CVString);
			PropertyPageList.SelectedIndex = 0;
		}

		private void LoadButtonText()
		{
			btnOk.Content = WpfPropertyControlResources.R101_OKString;
			btnDefault.Content = WpfPropertyControlResources.R102_DefaultString;
			btnCancel.Content = WpfPropertyControlResources.R103_CancelString;
		}

		private void btnOk_Click(object sender, RoutedEventArgs e)
		{
			AdjustSettings = Settings.set_AdjustYes;
			OnOKButtonClick();
		}

		private void btnDefault_Click(object sender, RoutedEventArgs e)
		{
			AdjustSettings = Settings.set_AdjustDefault;
			OnDefaultButtonClick();
		}

		private void btnCancel_Click(object sender, RoutedEventArgs e)
		{
			AdjustSettings = Settings.set_AdjustNo;
			OnCancelButtonClick();
		}

		private void PropertyPageList_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			switch (PropertyPageList.SelectedIndex)
			{
			case 0:
				if (m_GeneralPage == null)
				{
					m_GeneralPage = new UsrGeneralPage(PropPage.GeneralProps);
				}
				rightViewPanel.Content = m_GeneralPage;
				break;
			case 1:
				m_MarkerPage = new UsrMarkerPage(PropPage.AzeoProps);
				m_MarkerPage.SetPageType(PageEnum.page_Azeotropes);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 2:
				m_MarkerPage = new UsrMarkerPage(PropPage.BoundayProps);
				m_MarkerPage.SetPageType(PageEnum.page_Boundary);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 3:
				m_EnvelopePage = new UsrEnvelopePage(PropPage.EnvelopeProps);
				rightViewPanel.Content = m_EnvelopePage;
				break;
			case 5:
				m_MarkerPage = new UsrMarkerPage(PropPage.MarkerProps);
				m_MarkerPage.SetPageType(PageEnum.page_Markers);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 6:
				m_LinePage = new UsrLinePage(PropPage.FreeHandProps);
				m_LinePage.SetPageType(PageEnum.page_FreeHand);
				rightViewPanel.Content = m_LinePage;
				break;
			case 7:
				m_LinePage = new UsrLinePage(PropPage.MatBalProps);
				m_LinePage.SetPageType(PageEnum.page_MatBal);
				rightViewPanel.Content = m_LinePage;
				break;
			case 8:
				m_MarkerPage = new UsrMarkerPage(PropPage.ProductProps);
				m_MarkerPage.SetPageType(PageEnum.page_Product);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 9:
				m_MarkerPage = new UsrMarkerPage(PropPage.FeedProps);
				m_MarkerPage.SetPageType(PageEnum.page_Feed);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 10:
				m_CurvesPage = new UsrCurvesPage(PropPage.ProfilesProps);
				m_CurvesPage.SetPageType(PageEnum.page_Profiles);
				rightViewPanel.Content = m_CurvesPage;
				break;
			case 11:
				m_LinePage = new UsrLinePage(PropPage.DecanterProps);
				m_LinePage.SetPageType(PageEnum.page_Decanter);
				rightViewPanel.Content = m_LinePage;
				break;
			case 12:
				m_MarkerPage = new UsrMarkerPage(PropPage.ColumnVapourProps);
				m_MarkerPage.SetPageType(PageEnum.page_ColumnVapor);
				rightViewPanel.Content = m_MarkerPage;
				break;
			case 4:
				m_CurvesPage = new UsrCurvesPage(PropPage.CurveProps);
				m_CurvesPage.SetPageType(PageEnum.page_Curves);
				rightViewPanel.Content = m_CurvesPage;
				break;
			default:
				rightViewPanel.Content = null;
				break;
			}
		}

		private void OnOKButtonClick()
		{
			if (this.OKButtonClick != null)
			{
				this.OKButtonClick(this, new EventArgs());
			}
		}

		private void OnDefaultButtonClick()
		{
			if (this.DefaultButtonClick != null)
			{
				this.DefaultButtonClick(this, new EventArgs());
			}
		}

		private void OnCancelButtonClick()
		{
			if (this.CancelButtonClick != null)
			{
				this.CancelButtonClick(this, new EventArgs());
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrproppage.xaml", UriKind.Relative);
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
				((UsrPropPage)target).Loaded += UserControl_Loaded;
				break;
			case 2:
				PropertyPageList = (ListBox)target;
				PropertyPageList.SelectionChanged += PropertyPageList_SelectionChanged;
				break;
			case 3:
				gridSplitter1 = (GridSplitter)target;
				break;
			case 4:
				rightViewPanel = (UserControl)target;
				break;
			case 5:
				btnOk = (Button)target;
				btnOk.Click += btnOk_Click;
				break;
			case 6:
				btnDefault = (Button)target;
				btnDefault.Click += btnDefault_Click;
				break;
			case 7:
				btnCancel = (Button)target;
				btnCancel.Click += btnCancel_Click;
				break;
			default:
				_contentLoaded = true;
				break;
			}
		}
	}
}
