Attribute VB_Name = "Sheet11"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "cmdGoBackToWelcomePage, 54, 0, MSForms, CommandButton"
Private Sub Worksheet_Calculate()



On Error GoTo errorhandler

If ActiveSheet.CodeName = "Sheet11" Then

    Dim MaximumScale, MinimumScale As Double
    
    Dim ActCellAddress As String
    
    ActCellAddress = ActiveCell.Address

    MaximumScale = Application.WorksheetFunction.Max(Range("$g$80:$g$130"))
    MinimumScale = Application.WorksheetFunction.Min(Range("$g$80:$g$130"))

    ActiveSheet.ChartObjects("Chart 3").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale * 0.95
        .MaximumScale = MaximumScale * 1.05
        .CrossesAt = MinimumScale * 0.95
    End With

    MaximumScale = Application.WorksheetFunction.Max(Range("$k$80:$k$130"))
    MinimumScale = Application.WorksheetFunction.Min(Range("$k$80:$k$130"))

    ActiveSheet.ChartObjects("Chart 1").Activate



    With ActiveChart.Axes(xlValue)
       ' .MinimumScale = MinimumScale * 0.95
        .MinimumScale = 0
        .MaximumScale = MaximumScale * 1.05
       ' .CrossesAt = MinimumScale * 0.95
       .CrossesAt = 0
    End With
    
    Range(ActCellAddress).Select

End If

Exit Sub

errorhandler:

 MsgBox "Worksheet Calculation Error!"

End Sub

Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet11" Then
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
'    Sheet11.EnableCalculation = False
'End Sub
Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub

