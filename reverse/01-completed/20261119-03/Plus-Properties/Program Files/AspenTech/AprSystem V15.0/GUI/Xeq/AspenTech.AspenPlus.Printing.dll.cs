using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Drawing.Printing;
using System.Linq;
using System.Printing;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using AspenTech.AspenPlus.Infrastructure;
using AspenTech.Visualisation.CommonShell;
using Microsoft.Practices.Composite.Modularity;
using Microsoft.Practices.Unity;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("AspenTech.AspenPlus.Printing")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("AspenTech.AspenPlus.Printing")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology 2011 - 2024")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace AspenTech.AspenPlus.Printing
{
	public static class GenericPrinting
	{
		private const double DefaultDpi = 96.0;

		public static void DoGenericPrintSetup()
		{
			PageSetupDialog pageSetupDialog = new PageSetupDialog
			{
				PageSettings = PrintHelper.DefaultPageSettings
			};
			if (pageSetupDialog.ShowDialog() == DialogResult.OK)
			{
				PrintPageSettings printPageSettings = SystemEnvironment.ApplicationSettings.PrintSettings;
				if (printPageSettings == null)
				{
					PrintPageSettings printPageSettings2 = (SystemEnvironment.ApplicationSettings.PrintSettings = new PrintPageSettings());
					printPageSettings = printPageSettings2;
				}
				printPageSettings.PaperSize = pageSetupDialog.PageSettings.PaperSize.PaperName;
				printPageSettings.PaperSource = pageSetupDialog.PageSettings.PaperSource.SourceName;
				printPageSettings.IsLandscape = pageSetupDialog.PageSettings.Landscape;
				Margins margins = pageSetupDialog.PageSettings.Margins;
				printPageSettings.Margin = new Thickness(margins.Left, margins.Top, margins.Right, margins.Bottom);
			}
		}

		public static void DoGenericPrintPreview(IPrintSupport ps, IUnityContainer unityContainer)
		{
			if (ps == null)
			{
				throw new ArgumentNullException("ps");
			}
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			Window owner = unityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>()).ActiveWindow as Window;
			System.Windows.Input.Cursor overrideCursor = Mouse.OverrideCursor;
			Mouse.OverrideCursor = System.Windows.Input.Cursors.Wait;
			PageSettings defaultPageSettings = PrintHelper.DefaultPageSettings;
			Size size = new Size(PrintHelper.ConvertDotsToPixels(defaultPageSettings.PaperSize.Width), PrintHelper.ConvertDotsToPixels(defaultPageSettings.PaperSize.Height));
			Rect printableArea = (defaultPageSettings.PrintableArea.IsEmpty ? new Rect(size) : new Rect(PrintHelper.ConvertDotsToPixels(defaultPageSettings.PrintableArea.Left), PrintHelper.ConvertDotsToPixels(defaultPageSettings.PrintableArea.Top), PrintHelper.ConvertDotsToPixels(defaultPageSettings.PrintableArea.Width), PrintHelper.ConvertDotsToPixels(defaultPageSettings.PrintableArea.Height)));
			Thickness value = PrintHelper.ConvertMargins(defaultPageSettings.Margins);
			try
			{
				PrintPreviewWindow printPreviewWindow = new PrintPreviewWindow(PrintHelper.CreateFixedDocument(ps, printableArea, size, value, defaultPageSettings.Landscape));
				printPreviewWindow.Owner = owner;
				printPreviewWindow.Loaded += delegate
				{
					Mouse.OverrideCursor = System.Windows.Input.Cursors.Arrow;
				};
				printPreviewWindow.ShowDialog();
			}
			catch (InvalidOperationException)
			{
			}
			finally
			{
				Mouse.OverrideCursor = overrideCursor;
			}
		}

		public static void DoGenericPrint(IPrintSupport ps)
		{
			if (ps == null)
			{
				throw new ArgumentNullException("ps");
			}
			try
			{
				PageSettings defaultPageSettings = PrintHelper.DefaultPageSettings;
				Thickness value = PrintHelper.ConvertMargins(defaultPageSettings.Margins);
				System.Windows.Controls.PrintDialog printDialog = new System.Windows.Controls.PrintDialog();
				PrintQueue printQueue = printDialog.PrintQueue;
				PrintTicket printTicket = printDialog.PrintTicket;
				if (defaultPageSettings.PaperSize != null)
				{
					printTicket.PageMediaSize = PrintHelper.ConvertPaperSizeToPageMediaSize(defaultPageSettings.PaperSize, printQueue.GetPrintCapabilities(printTicket).PageMediaSizeCapability);
				}
				printTicket.PageOrientation = (defaultPageSettings.Landscape ? PageOrientation.Landscape : PageOrientation.Portrait);
				if (printDialog.ShowDialog() == true)
				{
					bool flag = printDialog.PrintTicket.PageOrientation == PageOrientation.Landscape;
					Size size = (flag ? new Size(printDialog.PrintableAreaHeight, printDialog.PrintableAreaWidth) : new Size(printDialog.PrintableAreaWidth, printDialog.PrintableAreaHeight));
					Rect printableArea = new Rect(size);
					FixedDocument fixedDocument = PrintHelper.CreateFixedDocument(ps, printableArea, size, value, flag);
					printDialog.PrintDocument(fixedDocument.DocumentPaginator, SystemEnvironment.ApplicationNameWithVersion);
				}
			}
			catch (InvalidOperationException)
			{
			}
		}
	}
	internal static class PrintHelper
	{
		private const double MinimumMagin = 15.0;

		public static PageSettings DefaultPageSettings
		{
			get
			{
				PrinterSettings printerSettings = new PrinterSettings();
				PageSettings pageSettings = new PageSettings(printerSettings);
				PrintPageSettings pps = SystemEnvironment.ApplicationSettings.PrintSettings;
				if (pps != null)
				{
					if (!string.IsNullOrEmpty(pps.PaperSize))
					{
						PaperSize paperSize = printerSettings.PaperSizes.OfType<PaperSize>().FirstOrDefault((PaperSize x) => string.Equals(x.PaperName, pps.PaperSize));
						if (paperSize != null)
						{
							pageSettings.PaperSize = paperSize;
						}
					}
					if (!string.IsNullOrEmpty(pps.PaperSource))
					{
						PaperSource paperSource = printerSettings.PaperSources.OfType<PaperSource>().FirstOrDefault((PaperSource x) => string.Equals(x.SourceName, pps.PaperSource));
						if (paperSource != null)
						{
							pageSettings.PaperSource = paperSource;
						}
					}
					pageSettings.Landscape = pps.IsLandscape;
					if (pps.Margin.HasValue)
					{
						Thickness value = pps.Margin.Value;
						pageSettings.Margins = new Margins((int)value.Left, (int)value.Right, (int)value.Top, (int)value.Bottom);
					}
				}
				return pageSettings;
			}
		}

		public static PageMediaSize ConvertPaperSizeToPageMediaSize(PaperSize paperSize, IEnumerable<PageMediaSize> pageMediaSizeCapability)
		{
			if (paperSize == null)
			{
				throw new ArgumentNullException("paperSize");
			}
			if (pageMediaSizeCapability == null)
			{
				throw new ArgumentNullException("pageMediaSizeCapability");
			}
			double y = ConvertDotsToPixels(paperSize.Width);
			double y2 = ConvertDotsToPixels(paperSize.Height);
			foreach (PageMediaSize item in pageMediaSizeCapability)
			{
				if (item.Width.HasValue && item.Height.HasValue && IsRoughlyEqual(item.Width.Value, y) && IsRoughlyEqual(item.Height.Value, y2))
				{
					return item;
				}
			}
			return null;
		}

		public static FixedDocument CreateFixedDocument(IPrintSupport ps, Rect printableArea, Size paperSize, Thickness? margin, bool landscape)
		{
			Size size = (landscape ? new Size(paperSize.Height, paperSize.Width) : new Size(paperSize.Width, paperSize.Height));
			Rect adjustedPrintableArea = (landscape ? new Rect(printableArea.Top, printableArea.Left, printableArea.Height, printableArea.Width) : printableArea);
			FixedDocument fixedDocument = new FixedDocument();
			fixedDocument.DocumentPaginator.PageSize = size;
			foreach (FrameworkElement item in GeneratePrintingElements(ps, size, adjustedPrintableArea, margin))
			{
				FixedPage child = new FixedPage
				{
					Width = size.Width,
					Height = size.Height,
					Children = { (UIElement)item }
				};
				fixedDocument.Pages.Add(new PageContent
				{
					Child = child
				});
			}
			return fixedDocument;
		}

		private static IEnumerable<FrameworkElement> GeneratePrintingElements(IPrintSupport ps, Size adjustedPaperSize, Rect adjustedPrintableArea, Thickness? margin)
		{
			Thickness borderPadding = CalculateBorderPadding(adjustedPrintableArea, adjustedPaperSize, margin);
			borderPadding = FixThickness(borderPadding);
			Size availablePrintSize = new Size(adjustedPaperSize.Width - borderPadding.Left - borderPadding.Right, adjustedPaperSize.Height - borderPadding.Top - borderPadding.Bottom);
			IEnumerable<FrameworkElement> enumerable = ps.GeneratePrintPages(availablePrintSize);
			if (enumerable == null)
			{
				yield break;
			}
			foreach (FrameworkElement item in enumerable)
			{
				item.HorizontalAlignment = System.Windows.HorizontalAlignment.Left;
				item.VerticalAlignment = VerticalAlignment.Top;
				yield return new Border
				{
					Width = adjustedPaperSize.Width,
					Height = adjustedPaperSize.Height,
					Padding = borderPadding,
					Child = item,
					Background = Brushes.White
				};
			}
		}

		private static Thickness CalculateBorderPadding(Rect adjustedPrintableArea, Size adjustedPaperSize, Thickness? margin)
		{
			double num = (double.IsNaN(adjustedPrintableArea.Left) ? 0.0 : adjustedPrintableArea.Left);
			double num2 = (double.IsNaN(adjustedPrintableArea.Top) ? 0.0 : adjustedPrintableArea.Top);
			double num3 = (double.IsNaN(adjustedPrintableArea.Width) ? adjustedPaperSize.Width : adjustedPrintableArea.Width);
			double num4 = (double.IsNaN(adjustedPrintableArea.Height) ? adjustedPaperSize.Height : adjustedPrintableArea.Height);
			double num5 = Math.Max(num, 15.0);
			double num6 = Math.Max(num2, 15.0);
			double num7 = Math.Max(adjustedPaperSize.Width - num3 - num, 15.0);
			double num8 = Math.Max(adjustedPaperSize.Height - num4 - num2, 15.0);
			if (margin.HasValue)
			{
				Thickness value = margin.Value;
				double num9 = Math.Max(num5, value.Left);
				double num10 = Math.Max(num6, value.Top);
				double num11 = Math.Max(num7, value.Right);
				double num12 = Math.Max(num8, value.Bottom);
				if (num9 + num11 >= adjustedPaperSize.Width)
				{
					num9 = num5;
					num11 = num7;
				}
				if (num10 + num12 >= adjustedPaperSize.Height)
				{
					num10 = num6;
					num12 = num8;
				}
				return new Thickness(num9, num10, num11, num12);
			}
			return new Thickness(num5, num6, num7, num8);
		}

		public static double ConvertDotsToPixels(double dots)
		{
			return dots * 0.96;
		}

		public static Thickness ConvertMargins(Margins mgs)
		{
			return new Thickness(ConvertDotsToPixels(mgs.Left), ConvertDotsToPixels(mgs.Top), ConvertDotsToPixels(mgs.Right), ConvertDotsToPixels(mgs.Bottom));
		}

		private static bool IsRoughlyEqual(double x, double y)
		{
			return Math.Abs(x - y) <= 1.0;
		}

		private static Thickness FixThickness(Thickness tn)
		{
			Thickness result = tn;
			if (double.IsInfinity(tn.Left) || double.IsNaN(tn.Left))
			{
				result.Left = 0.0;
			}
			if (double.IsInfinity(tn.Right) || double.IsNaN(tn.Right))
			{
				result.Right = 0.0;
			}
			if (double.IsInfinity(tn.Top) || double.IsNaN(tn.Top))
			{
				result.Top = 0.0;
			}
			if (double.IsInfinity(tn.Bottom) || double.IsNaN(tn.Bottom))
			{
				result.Bottom = 0.0;
			}
			return result;
		}
	}
	public class PrintingModule : IModule
	{
		private readonly IUnityContainer _unityContainer;

		public PrintingModule(IUnityContainer unityContainer)
		{
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			_unityContainer = unityContainer;
		}

		public void Initialize()
		{
			_unityContainer.RegisterType<IPrintPresenter, PrintPresenter>(new ContainerControlledLifetimeManager(), Array.Empty<InjectionMember>());
		}
	}
	public class PrintPresenter : IPrintPresenter
	{
		private readonly IUnityContainer _unityContainer;

		private IPrintSupport ActiveScreenToPrint
		{
			get
			{
				IShellApplication shellApplication = _unityContainer.Resolve<IShellApplication>(Array.Empty<ResolverOverride>());
				if (shellApplication != null)
				{
					IShellMainWindow activeWindow = shellApplication.ActiveWindow;
					if (activeWindow != null)
					{
						return activeWindow.ActiveDocumentScreen as IPrintSupport;
					}
				}
				return null;
			}
		}

		public bool CanPrint => ActiveScreenToPrint?.CanPrint ?? false;

		public bool CanPrintPreview => ActiveScreenToPrint?.CanPrintPreview ?? false;

		public bool CanPrintSetup => CanPrint;

		public PrintPresenter(IUnityContainer unityContainer)
		{
			if (unityContainer == null)
			{
				throw new ArgumentNullException("unityContainer");
			}
			_unityContainer = unityContainer;
		}

		public void DoPrint()
		{
			IPrintSupport activeScreenToPrint = ActiveScreenToPrint;
			if (activeScreenToPrint != null && !activeScreenToPrint.DoCustomPrint())
			{
				GenericPrinting.DoGenericPrint(activeScreenToPrint);
			}
		}

		public void DoPrintPreview()
		{
			IPrintSupport activeScreenToPrint = ActiveScreenToPrint;
			if (activeScreenToPrint != null && !activeScreenToPrint.DoCustomPrintPreview())
			{
				GenericPrinting.DoGenericPrintPreview(activeScreenToPrint, _unityContainer);
			}
		}

		public void DoPrintSetup()
		{
			IPrintSupport activeScreenToPrint = ActiveScreenToPrint;
			if (activeScreenToPrint == null || !activeScreenToPrint.DoCustomPrintSetup())
			{
				GenericPrinting.DoGenericPrintSetup();
			}
		}
	}
	public class PrintPreviewWindow : Window, IComponentConnector
	{
		private readonly FixedDocument _document;

		internal DocumentViewer theDocumentViewer;

		private bool _contentLoaded;

		public PrintPreviewWindow(FixedDocument document)
		{
			if (document == null)
			{
				throw new ArgumentNullException("document");
			}
			_document = document;
			InitializeComponent();
		}

		protected override void OnInitialized(EventArgs e)
		{
			theDocumentViewer.Document = _document;
			if (theDocumentViewer.Template.FindName("PART_FindToolBarHost", theDocumentViewer) is FrameworkElement frameworkElement)
			{
				frameworkElement.Visibility = Visibility.Collapsed;
			}
			base.OnInitialized(e);
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		public void InitializeComponent()
		{
			if (!_contentLoaded)
			{
				_contentLoaded = true;
				Uri resourceLocator = new Uri("/AspenTech.AspenPlus.Printing;component/printpreviewwindow.xaml", UriKind.Relative);
				System.Windows.Application.LoadComponent(this, resourceLocator);
			}
		}

		[DebuggerNonUserCode]
		[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
		[EditorBrowsable(EditorBrowsableState.Never)]
		void IComponentConnector.Connect(int connectionId, object target)
		{
			if (connectionId == 1)
			{
				theDocumentViewer = (DocumentViewer)target;
			}
			else
			{
				_contentLoaded = true;
			}
		}
	}
}
namespace AspenTech.AspenPlus.Printing.Properties
{
	[CompilerGenerated]
	[GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.10.0.0")]
	internal sealed class Settings : ApplicationSettingsBase
	{
		private static Settings defaultInstance = (Settings)SettingsBase.Synchronized(new Settings());

		public static Settings Default => defaultInstance;
	}
}
