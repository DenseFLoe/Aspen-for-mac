using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Interop;
using System.Windows.Media;
using AspenTech.AspenPlus.Infrastructure;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyFileVersion("41.0.0.614")]
[assembly: AssemblyTitle("PfsDotNetActiveXCtrl")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Aspen Technology, Inc.")]
[assembly: AssemblyProduct("PfsDotNetActiveXCtrl")]
[assembly: AssemblyCopyright("Copyright © Aspen Technology, Inc. 2012 - 2024, All Rights Reserved")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(true)]
[assembly: Guid("171c932e-ba6a-4af7-bad9-0e40d69ed06b")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.614")]
namespace PfsDotNetActiveXCtrl;

internal class CalcRenderWindow : Window
{
	protected override void OnSourceInitialized(EventArgs e)
	{
		base.OnSourceInitialized(e);
		if (PresentationSource.FromVisual(this) is HwndSource hwndSource)
		{
			hwndSource.CompositionTarget.BackgroundColor = Colors.White;
		}
	}
}
[Guid("ADFE0BFA-9ABD-44B8-8299-F81804F54FD0")]
[ComVisible(true)]
[InterfaceType(ComInterfaceType.InterfaceIsDual)]
public interface IEmbedObject
{
	void InsertWPFControl(object objCtrl, object objImage, bool bShowAsIcon);

	void ResizeAXWindow(int nLeft, int nTop, int nWidth, int nHeight);

	void ShowAsIcon(bool bShowAsIcon = true);

	void ShowAsTable(bool bShowAsTable = true);

	void CopyContent(int iFlag = 0);

	bool CanContentCopy(int iFlag = 0);

	bool CanZoom(int iFlag = 0);

	void Zoom(double factor);

	void RefreshControl(int iFlag = 0);

	void EnableTranspancy(bool bTranspancy);

	void GetContentSize(ref int nWidth, ref int nHeight);

	void FitToRegion(int iFlag = 0);

	void CompactView(int iFlag = 0);

	void GetCurrentZoomFactors(ref double dFactorX, ref double dFactorY);

	void LockZoom(bool bLock);

	void GetWPFHandle(ref int nHandle);

	void BeginPPSetting(bool bPrint);

	void EndPPSetting(bool bPrint);

	void UpdateAXData(int iFlag = 0);

	void ShowingAsIcon(bool bShowAsIcon);

	void ResetInternalStatus(int iFlag = 0);

	bool PreparePrintingData(string strCageKey);

	void DisposePrintingData(string strCageKey);

	void SetupDataGridCage(string strCageKey);

	void InitializeZoomFactor(double dZoomFactor);

	void SetEditMode(bool bEditMode);
}
[ProgId("AspenTech.AspenPlus.PfsDotNetActiveXCtrl.PFSEmbedWPFX.41.0")]
[ClassInterface(ClassInterfaceType.AutoDispatch)]
public class PFSEmbedWPF : System.Windows.Forms.UserControl, IEmbedObject
{
	private CalcRenderWindow m_wndWPF = new CalcRenderWindow();

	private IntPtr m_hwndWPF = IntPtr.Zero;

	private System.Windows.Controls.Control m_objEmbeddedCtrl;

	private System.Windows.Controls.Image m_imgCtrlIcon;

	private ScaleTransform m_stCfc = new ScaleTransform(1.0, 1.0);

	private ElementHost m_host;

	private bool m_bShowAsIcon;

	private bool m_bLockZoom;

	private double m_dFirstLevelMargin = 1.0;

	private double m_dSecondLevelMargin = 1.0;

	private double m_dScrollBarWidth = 17.0;

	private const int GWL_EXSTYLE = -20;

	private const int WS_EX_TRANSPARENT = 32;

	private const int WS_EX_LAYERED = 524288;

	private const int LWA_ALPHA = 2;

	private const int LOGPIXELSX = 88;

	private IContainer components;

	[DllImport("user32.dll")]
	public static extern IntPtr GetWindowLongPtr(IntPtr hwnd, int nIndex);

	[DllImport("user32.dll")]
	public static extern IntPtr SetWindowLongPtr(IntPtr hwnd, int nIndex, IntPtr dwNewLong);

	[DllImport("user32")]
	private static extern int SetLayeredWindowAttributes(IntPtr Handle, int crKey, byte bAlpha, int dwFlags);

	[DllImport("gdi32.dll")]
	public static extern int GetDeviceCaps(IntPtr hDC, int iIndex);

	[DllImport("user32.dll")]
	public static extern IntPtr GetDC(IntPtr hWnd);

	[DllImport("user32.dll")]
	public static extern int ReleaseDC(IntPtr hWnd, IntPtr hDC);

	private double PixelToDot(int nPixels)
	{
		IntPtr dC = GetDC(IntPtr.Zero);
		int deviceCaps = GetDeviceCaps(dC, 88);
		double result = 96.0 / (double)deviceCaps * (double)nPixels;
		ReleaseDC(IntPtr.Zero, dC);
		return result;
	}

	public PFSEmbedWPF()
	{
		InitializeComponent();
		base.Load += PFSEmbedWPF_Load;
		base.SizeChanged += PFSEmbedWPF_SizeChanged;
		m_wndWPF.WindowStyle = WindowStyle.None;
		m_wndWPF.ResizeMode = ResizeMode.NoResize;
		m_wndWPF.SizeToContent = SizeToContent.Manual;
		m_wndWPF.Margin = new Thickness(m_dFirstLevelMargin);
		m_wndWPF.Padding = new Thickness(m_dSecondLevelMargin);
		m_wndWPF.ShowActivated = false;
		m_wndWPF.Left = m_dFirstLevelMargin;
		m_wndWPF.Top = m_dFirstLevelMargin;
		m_wndWPF.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
		m_wndWPF.VerticalContentAlignment = VerticalAlignment.Center;
	}

	private void PFSEmbedWPF_Load(object sender, EventArgs e)
	{
		BackColor = System.Drawing.Color.Transparent;
		SetStyle(ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer, value: true);
	}

	private void PFSEmbedWPF_SizeChanged(object sender, EventArgs e)
	{
		if (m_objEmbeddedCtrl != null && !m_bShowAsIcon && m_wndWPF != null)
		{
			_ = m_hwndWPF;
			FitToRegion();
			if (m_wndWPF.Visibility == Visibility.Hidden)
			{
				m_wndWPF.Visibility = Visibility.Visible;
			}
		}
	}

	[DispId(1)]
	public void InsertWPFControl(object objCtrl, object objImage, bool bShowAsIcon)
	{
		m_imgCtrlIcon = objImage as System.Windows.Controls.Image;
		m_objEmbeddedCtrl = objCtrl as System.Windows.Controls.Control;
		m_objEmbeddedCtrl.LayoutTransform = m_stCfc;
		m_bShowAsIcon = bShowAsIcon;
		if (m_wndWPF.Visibility != Visibility.Visible)
		{
			m_wndWPF.Visibility = Visibility.Visible;
		}
		if (bShowAsIcon)
		{
			m_wndWPF.SizeToContent = SizeToContent.WidthAndHeight;
			m_wndWPF.Content = m_imgCtrlIcon;
			m_imgCtrlIcon.Width = PixelToDot(base.Width) - m_dFirstLevelMargin - m_dSecondLevelMargin;
			m_imgCtrlIcon.Height = PixelToDot(base.Height) - m_dFirstLevelMargin - m_dSecondLevelMargin;
		}
		else
		{
			m_wndWPF.SizeToContent = SizeToContent.Manual;
			m_wndWPF.Content = m_objEmbeddedCtrl;
		}
	}

	[DispId(2)]
	public void ResizeAXWindow(int nLeft, int nTop, int nWidth, int nHeight)
	{
		base.Left = nLeft;
		base.Top = nTop;
		base.Width = nWidth;
		base.Height = nHeight;
	}

	[DispId(3)]
	public void ShowAsIcon(bool bShowAsIcon)
	{
		m_bShowAsIcon = true;
		if (m_imgCtrlIcon != null)
		{
			m_wndWPF.SizeToContent = SizeToContent.WidthAndHeight;
			m_wndWPF.Content = null;
			m_wndWPF.Content = m_imgCtrlIcon;
			m_imgCtrlIcon.Width = PixelToDot(base.Width) - m_dFirstLevelMargin - m_dSecondLevelMargin;
			m_imgCtrlIcon.Height = PixelToDot(base.Height) - m_dFirstLevelMargin - m_dSecondLevelMargin;
		}
	}

	[DispId(4)]
	public void ShowAsTable(bool bShowAsTable)
	{
		m_bShowAsIcon = false;
		if (m_objEmbeddedCtrl != null)
		{
			m_wndWPF.SizeToContent = SizeToContent.Manual;
			m_wndWPF.Content = m_objEmbeddedCtrl;
			FitToRegion();
		}
	}

	[DispId(5)]
	public void CopyContent(int iFlag)
	{
		if (m_objEmbeddedCtrl != null)
		{
			IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
			if (val == null)
			{
				return;
			}
			val.CopyAXEmbeddedObjectContent();
		}
	}

	[DispId(6)]
	public bool CanContentCopy(int iFlag)
	{
		if (m_objEmbeddedCtrl == null || m_bShowAsIcon)
		{
			return false;
		}
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val == null)
		{
			return false;
		}
		return val.CanAXEmbeddedObjectCopy();
	}

	[DispId(7)]
	public bool CanZoom(int iFlag)
	{
		if (m_objEmbeddedCtrl == null)
		{
			return false;
		}
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val == null)
		{
			return false;
		}
		return val.SupportsZoom;
	}

	[DispId(8)]
	public void Zoom(double factor)
	{
		if (m_objEmbeddedCtrl == null)
		{
			return;
		}
		m_stCfc.ScaleX = factor;
		m_stCfc.ScaleY = factor;
	}

	[DispId(9)]
	public void RefreshControl(int iFlag)
	{
		if (m_wndWPF != null && m_wndWPF.Visibility == Visibility.Visible && m_wndWPF.Content is FrameworkElement frameworkElement)
		{
			frameworkElement.Visibility = Visibility.Hidden;
			frameworkElement.Visibility = Visibility.Visible;
		}
	}

	[DispId(10)]
	public void EnableTranspancy(bool bTranspancy)
	{
		IntPtr intPtr = GetWindowLongPtr(base.Handle, -20);
		long num = intPtr.ToInt64();
		if (bTranspancy)
		{
			num |= 0x20;
		}
		else
		{
			num &= -33;
		}
		SetWindowLongPtr(base.Handle, -20, new IntPtr(num));
		base.Visible = false;
		base.Visible = true;
	}

	[DispId(11)]
	public void GetContentSize(ref int nWidth, ref int nHeight)
	{
		if (m_objEmbeddedCtrl == null)
		{
			return;
		}
		IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val == null)
		{
			return;
		}
		val.GetContentSize(ref nWidth, ref nHeight);
	}

	[DispId(12)]
	public void FitToRegion(int iFlag = 0)
	{
		if (m_objEmbeddedCtrl != null && !m_bShowAsIcon && m_wndWPF != null && m_wndWPF.Visibility == Visibility.Visible)
		{
			m_wndWPF.Width = PixelToDot(base.Width) - m_dFirstLevelMargin * 2.0;
			m_wndWPF.Height = PixelToDot(base.Height) - m_dFirstLevelMargin * 2.0;
			int num = base.Width;
			int num2 = base.Height;
			int nWidth = 0;
			int nHeight = 0;
			GetContentSize(ref nWidth, ref nHeight);
			m_objEmbeddedCtrl.Width = (double)nWidth + m_dScrollBarWidth;
			m_objEmbeddedCtrl.Height = (double)nHeight + m_dScrollBarWidth;
			double num3 = 0.0;
			double num4 = 0.0;
			if ((double)nWidth != 0.0 && (double)nHeight != 0.0)
			{
				num3 = PixelToDot((int)((double)num - m_dFirstLevelMargin * 2.0 - m_dSecondLevelMargin * 2.0)) * 1.0 / m_objEmbeddedCtrl.Width;
				num4 = PixelToDot((int)((double)num2 - m_dFirstLevelMargin * 2.0 - m_dSecondLevelMargin * 2.0)) * 1.0 / m_objEmbeddedCtrl.Height;
				m_stCfc.ScaleX = num3;
				m_stCfc.ScaleY = num4;
			}
			m_wndWPF.UpdateLayout();
		}
	}

	[DispId(13)]
	public void CompactView(int iFlag = 0)
	{
		if (m_bShowAsIcon)
		{
			m_bShowAsIcon = false;
		}
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val == null)
		{
			return;
		}
		val.CompactView();
	}

	[DispId(14)]
	public void GetCurrentZoomFactors(ref double dFactorX, ref double dFactorY)
	{
		dFactorX = m_stCfc.ScaleX;
		dFactorY = m_stCfc.ScaleY;
	}

	[DispId(15)]
	public void LockZoom(bool bLock)
	{
		m_bLockZoom = bLock;
	}

	[DispId(16)]
	public void GetWPFHandle(ref int nHandle)
	{
		nHandle = 0;
		if (m_wndWPF != null)
		{
			m_wndWPF.Show();
			IntPtr intPtr = new WindowInteropHelper(m_wndWPF).Handle;
			m_hwndWPF = intPtr;
			nHandle = intPtr.ToInt32();
			m_wndWPF.Hide();
		}
		else
		{
			nHandle = 0;
		}
	}

	[DispId(17)]
	public void BeginPPSetting(bool bPrint)
	{
		if (m_host == null)
		{
			m_host = new ElementHost();
		}
		m_host.Parent = this;
		m_host.Dock = DockStyle.Fill;
		m_wndWPF.Content = null;
		m_wndWPF.Hide();
		if (m_bShowAsIcon)
		{
			m_host.Child = m_imgCtrlIcon;
		}
		else
		{
			m_host.Child = m_objEmbeddedCtrl;
		}
		Refresh();
	}

	[DispId(18)]
	public void EndPPSetting(bool bPrint)
	{
		if (m_host != null)
		{
			m_host.Child = null;
			m_host.Dock = DockStyle.None;
			m_host.Size = new System.Drawing.Size(0, 0);
			m_host.Dispose();
			m_host = null;
		}
		if (m_bShowAsIcon)
		{
			m_wndWPF.SizeToContent = SizeToContent.WidthAndHeight;
			m_wndWPF.Content = m_imgCtrlIcon;
			m_imgCtrlIcon.Width = base.Width;
			m_imgCtrlIcon.Height = base.Height;
		}
		else
		{
			m_wndWPF.SizeToContent = SizeToContent.Manual;
			m_wndWPF.Content = m_objEmbeddedCtrl;
		}
		m_wndWPF.Show();
		GC.Collect();
	}

	[DispId(19)]
	public void UpdateAXData(int iFlag)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.UpdateAXData();
		}
	}

	[DispId(20)]
	public void ShowingAsIcon(bool bShowAsIcon)
	{
		m_bShowAsIcon = true;
	}

	[DispId(21)]
	public void ResetInternalStatus(int iFlag)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.ResetInternalStatus();
		}
	}

	[DispId(22)]
	public bool PreparePrintingData(string strCageKey)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			return val.PreparePrintingData(strCageKey);
		}
		return false;
	}

	[DispId(23)]
	public void DisposePrintingData(string strCageKey)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.DisposePrintingData(strCageKey);
		}
	}

	[DispId(24)]
	public void SetupDataGridCage(string strCageKey)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.SetupDataGridCage(strCageKey);
		}
	}

	[DispId(25)]
	public void InitializeZoomFactor(double dZoomFactor)
	{
		if (m_stCfc != null)
		{
			m_stCfc.ScaleX = dZoomFactor;
			m_stCfc.ScaleY = dZoomFactor;
		}
	}

	[DispId(26)]
	public void SetEditMode(bool bEditMode)
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.IsEditMode = bEditMode;
		}
	}

	[DispId(27)]
	public void Close()
	{
IAXEmbeddedObject val = m_objEmbeddedCtrl as IAXEmbeddedObject;
		if (val != null)
		{
			val.Close();
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		base.SuspendLayout();
		base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		this.DoubleBuffered = true;
		base.Name = "PFSEmbedWPF";
		base.Size = new System.Drawing.Size(242, 176);
		base.ResumeLayout(false);
	}
}
