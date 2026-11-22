Attribute VB_Name = "Sheet15"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "Pfsplot1, 1062, 1, PFSPLOTLib, Pfsplot"
Attribute VB_Control = "cmdGoBackToWelcomePage, 1037, 2, MSForms, CommandButton"
Attribute VB_Control = "cmdClear, 1027, 3, MSForms, CommandButton"
Attribute VB_Control = "cmdDrawTernaryPhaseDiagram, 1026, 4, MSForms, CommandButton"
Private n_Click As Integer



Private Sub cmdClear_Click()

On Error GoTo errorhandler

    With Pfsplot1
        .PlotType = 2
        .SetAxisMode 1, 0, 2
        .SetAxisMode 2, 0, 1
        .SetAxisMode 2, 1, 1
    
         .Clear
         
      '  .SetAxisMode 0, 0, 2
      '  .SetAxisMode 1, 1, 2
         
         .SetLabel 0, "Solvent2 Fraction"
         .SetLabel 1, "Drug Fraction"
         .SetLabel 2, "Solvent1 Fraction"
         .Title = ""
         
         .AddText "Solvent2", 1#, 1.65, 0, 0, 0, 0, 0
         .AddText "Solvent1", -0.5, 1.65, 0, 0, 0, 0, 0
         .AddText "Drug", 0.44, -0.2, 0, 0, 0, 0, 0
         
          .GridType = 3
        
         n_Click = 0

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

Private Sub cmdDrawTernaryPhaseDiagram_Click()
Dim n_rows As Integer
Dim n_columns As Integer
Dim a(30, 3) As Double

On Error GoTo errorhandler


n_Click = n_Click + 1

If crctslct() = False Then Exit Sub
 
With Pfsplot1

    .SetLabel 0, "Solvent2 Fraction"
    .SetLabel 1, "Drug Fraction"
    .SetLabel 2, "Solvent1 Fraction"
    .nxvariables = 20
    .nvariables = 20
    
 
    's = Excel.Application.ActiveCell.Address
    n_rows = Selection.Rows.Count
    n_columns = Selection.Columns.Count
    
    For i = 1 To n_rows
        For j = 1 To n_columns
        '  s = s & Chr(10)
            a(i, j) = Selection.Rows(i).Cells(j).Value
        Next j
    Next i


    For i = 1 To n_rows
 '  .SetLineAttribute 0, 255, 0, 0, 0, 0, 0
   
        .SetXData n_Click + 2, (i - 1), a(i, 2)
        .SetData n_Click + 2, (i - 1), 1 - a(i, 1) - a(i, 2)
 '      .SetLabel 0, "Solvent2 Fraction"
 '      .SetLabel 1, "Drug Fraction"
 '      .SetLabel 2, "Solvent1 Fraction"
    
 '      .Redraw
    Next i
End With
    
Exit Sub
    
'    Range("o60").Select
    

errorhandler:

MsgBox "Error in drawing the plot."

If Err.Number = 424 Then
    MsgBox "Please check whether ActiveX controls are enabled." _
    & Chr(13) & "If Excel 2007 is used, please make sure to enable all the ActiveX controls in the ActiveX Settings at the Trust Center and reopen the file.", , _
    "ActiveX control is not initialized."
End If

End Sub

Function crctslct() As Boolean
Dim ncolumn As Integer
    
    crctslct = True

    If InStr(Selection.Address, ",") > 1 Then
        MsgBox "It's not a continuous field, please select a continuous field¡£"
        n_Click = n_Click - 1
        crctslct = False
        Exit Function
    End If
    
    ncolumn = Selection.Columns.Count
    
    
    If ncolumn <> 2 And ncolumn <> 3 Then
        MsgBox ("Please select 2 or 3 columns of data.")
        n_Click = n_Click - 1
        crctslct = False
        Exit Function
    End If
    
End Function

Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet15" Then
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
'    Sheet15.EnableCalculation = False
'End Sub
Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub

