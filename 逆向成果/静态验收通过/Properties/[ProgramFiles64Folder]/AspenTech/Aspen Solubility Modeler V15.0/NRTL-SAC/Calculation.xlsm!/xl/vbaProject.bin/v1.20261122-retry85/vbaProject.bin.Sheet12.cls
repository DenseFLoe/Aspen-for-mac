Attribute VB_Name = "Sheet12"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "Pfsplot1, 1039, 0, PFSPLOTLib, Pfsplot"
Attribute VB_Control = "btnClear, 1036, 1, MSForms, CommandButton"
Attribute VB_Control = "btnDraw, 1035, 2, MSForms, CommandButton"
Attribute VB_Control = "cmdGoBackToWelcomePage, 1032, 3, MSForms, CommandButton"
Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet12" Then
  ActiveSheet.EnableCalculation = True
  ActiveSheet.Calculate
  ActiveSheet.EnableCalculation = False
End If
End Sub

Private Sub Worksheet_Activate()
    ActiveSheet.EnableCalculation = True
    ActiveSheet.Calculate
    ActiveSheet.EnableCalculation = False
End Sub
'Private Sub Worksheet_Deactivate()
'    Sheet12.EnableCalculation = False
'End Sub
Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub

Private Sub btnClear_Click()

On Error GoTo errorhandler

    With Pfsplot1
        .PlotType = 2
        .GridType = 3
        .SetAxisMode 1, 0, 2
        .SetAxisMode 2, 0, 1
        .SetAxisMode 2, 1, 1
        .Clear
        .SetLabel 0, Sheet12.Range("C5").Value & " Fraction" '"Solvent2 Fraction" '
        .SetLabel 1, Sheet12.Range("D5").Value & " Fraction" '"Solvent3 Fraction"
        .SetLabel 2, Sheet12.Range("b5").Value & " Fraction" '"Solvent1 Fraction"
        .AddText Sheet12.Range("C5").Value, 1#, 1.65, 0, 0, 0, 0, 0
        .AddText Sheet12.Range("B5").Value, -0.5, 1.65, 0, 0, 0, 0, 0
        .AddText Sheet12.Range("D5").Value, 0.43, -0.2, 0, 0, 0, 0, 0
        .Title = ""
    End With
    
Exit Sub

errorhandler:

MsgBox "Error in drawing the plot."

If Err.Number = 424 Then
    MsgBox "Please check whether ActiveX controls are enabled." _
    & Chr(13) & "If Excel 2007 is used, please make sure to enable all the ActiveX controls in the ActiveX Settings at the Trust Center and reopen the file.", , _
    "ActiveX control is not initialized."
End If


End Sub

'


Private Sub btnDraw_Click()

Dim X1(), X2(), X3() As Double
Dim SX2(), SX3() As Double
Dim EX2(), EX3() As Double

Dim i, j As Integer




On Error GoTo errorhandler

   Dim NofGA As Integer
   Dim NofLine As Integer
   
   NofGA = Range("GDensity").Value
   
    

    ReDim SX2(NofGA * NofGA), SX3(NofGA * NofGA), EX2(NofGA * NofGA), EX3(NofGA * NofGA) As Double
'       ReDim P(1 To NofPA + 1), BP(1 To NofPA), X1(NofGA, NofGA), X2(NofGA, NofGA), X3(NofGA, NofGA) As Double
'       ReDim BPX1(1 To NofPA), BPX2(1 To NofPA), BPX3(1 To NofPA)

    NofLine = 0
    
    For i = 0 To NofGA
            Range("D17").Value = 1 / NofGA * i
       For j = 0 To NofGA - i + 2
            Range("c17").Value = (1 - 1 / NofGA * i) * 1 / (NofGA - i + 2) * j
            Range("B17").Value = 1 - Range("D17").Value - Range("C17").Value
            Range("E17").Select
            ActiveCell.Formula = "=TPFlash3($B$5:$D$5,B17:D17,$B$7,$B$6,""beta"",$f$2)"
            
            If (Range("e17").Value <> 1) Then
                NofLine = NofLine + 1
                Range("b18:d18").Select
                ActiveCell.FormulaArray = "=TPFlash3($B$5:$D$5,B17:D17,$B$7,$B$6,""X:1"",$f$2)"
                Range("b19:d19").Select
                ActiveCell.FormulaArray = "=TPFlash3($B$5:$D$5,B17:D17,$B$7,$B$6,""X:2"",$f$2)"
                SX2(NofLine) = Range("C18").Value
                SX3(NofLine) = Range("D18").Value
                EX2(NofLine) = Range("C19").Value
                EX3(NofLine) = Range("D19").Value
            End If
       Next j
    Next i





With Pfsplot1

    .Clear
    .SetLabel 0, Sheet12.Range("C5").Value & " Fraction"
    .SetLabel 1, Sheet12.Range("D5").Value & " Fraction"
    .SetLabel 2, Sheet12.Range("B5").Value & " Fraction"
    .AddText Sheet12.Range("C5").Value, 1#, 1.65, 0, 0, 0, 0, 0
    .AddText Sheet12.Range("B5").Value, -0.5, 1.65, 0, 0, 0, 0, 0
    .AddText Sheet12.Range("D5").Value, 0.43, -0.2, 0, 0, 0, 0, 0
    .nxvariables = NofLine
    .nvariables = NofLine



    For i = 1 To NofLine

        .SetXData i, 0, SX2(i)
        .SetXData i, 1, EX2(i)
        .SetData i, 0, SX3(i)
        .SetData i, 1, EX3(i)
        .SetAttribute i - 1, 0, 6, 10
        .Redraw
    Next i

'    .SetAttribute 1, -1, 6, 0

End With

Exit Sub

errorhandler:

MsgBox "Error in drawing the plot."

If Err.Number = 424 Then
    MsgBox "Please check whether ActiveX controls are enabled." _
    & Chr(13) & "If Excel 2007 is used, please make sure to enable all the ActiveX controls in the ActiveX Settings at the Trust Center and reopen the file.", , _
    "ActiveX control is not initialized."
End If

End Sub
