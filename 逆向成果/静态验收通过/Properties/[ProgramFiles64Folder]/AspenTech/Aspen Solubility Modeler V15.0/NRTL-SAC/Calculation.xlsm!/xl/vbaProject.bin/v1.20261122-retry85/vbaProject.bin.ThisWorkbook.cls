Attribute VB_Name = "ThisWorkbook"
Attribute VB_Base = "0{00020819-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Option Explicit

Private Const myWelcomePage = "AspenSolubilityModeler"
Private Const sMajorVersionNumber = "41"
Private Const sMinorVersionNumber = "0"
Private Const sThirdVersionNumber = "0"
Private Const sBulidNumber = "1000" ' Dec 05, 2008 Jiangchu Liu,  need incremented by 1 everytime this module has been modified

Private mySecServer As clsServer2
Private myLicName As String
Private myCookie As Long
Private myCheck As Boolean

Enum slmLicStatus
    lsNoLic = 0
    lsPending = 1
    lsOK = 2
End Enum

Enum slmLicImportance
   lsNotCritical = 0
   lsCritical = 1
End Enum

Public n_Click, n_Click2 As Integer

Private Sub Workbook_open()

'Hide all sheets except "AspenSolubilityModeler"

Dim Sheet As Object
Dim sPkgFileName As String
Dim sFileName As String
Dim sPos As Long


On Error GoTo errorhandler

    For Each Sheet In Sheets
        Sheet.EnableCalculation = False
    Next

    ActiveSheet.EnableCalculation = True
    
    Sheets(myWelcomePage).Visible = xlSheetVisible
    
    For Each Sheet In Sheets
      If Not Sheet.Name = myWelcomePage Then
        Sheet.Visible = xlSheetVeryHidden
      End If
    Next
 
    n_Click = 0
    n_Click2 = 0
     
    With Application
        .Calculation = xlManual
        .MaxChange = 0.001
    End With
    
    gbAddinInstalled = CheckAddInInstalled1
    If gbAddinInstalled = False Then
    
        MsgBox "The Aspen Properties add-in is not enabled.  Please enable it using 'Aspen Excel Add-in Manager'." & _
                        " This workbook needs to close.", _
                        vbOKOnly, "Aspen Solubility Modeler Denial"
        Application.DisplayAlerts = False
        Application.ActiveWorkbook.Saved = True
        Application.Quit
        Exit Sub
    End If
    
    Application.Range("ToTriggerCalculation").Formula = "=A1+1"
    
    Range("VersionNumber").Value = sMajorVersionNumber & "." & sMinorVersionNumber & "." & sThirdVersionNumber & "." & sBulidNumber

    'Application.Cursor = xlDefault
    
'Check Aspen Solubility Modeler tracking license.
  Dim sLicVer As String
  Dim sErrString As String
   
'Initial
  Set mySecServer = New clsServer2
  myCookie = 0
  myLicName = "SLM_TR_PML_PLS_SOL" '"SLM_Solubility_Modeler"
  sLicVer = ""
  myCheck = False
  Application.Cursor = xlWait
  If mySecServer.SLMCheckoutLicense(myLicName, sLicVer, myCookie, lsCritical, sErrString) Then
      myCheck = True
      'MsgBox "Checkout ok"
  End If
  
  Application.Cursor = xlDefault
  
  Exit Sub
   
errorhandler:
Application.Cursor = xlDefault
'MsgBox "Workbook Open Error!"
        
End Sub
Private Sub Workbook_BeforeClose(Cancel As Boolean)

'To judge whether the workbook has been changed (or Saved yet).
Dim blFlagSaved As Boolean

blFlagSaved = ActiveWorkbook.Saved

'Hide all sheets except "AspenSolubilityModeler"

If Not ActiveSheet.Name = myWelcomePage Then
    Dim Sheet As Object
    With Sheets(myWelcomePage)
    .Visible = xlSheetVisible
    For Each Sheet In Sheets
      If Not Sheet.Name = myWelcomePage Then
        Sheet.Visible = xlSheetVeryHidden
      End If
    Next
    End With
End If

 Application.StatusBar = False
  
If blFlagSaved = True Then ActiveWorkbook.Saved = True
  
'Release Aspen Solubility Modeler tracking license.
  If myCookie <> 0 Then
    mySecServer.SLMReleaseLicense (myCookie)
    myCookie = 0
    'MsgBox "License is released"
  End If
      
End Sub

