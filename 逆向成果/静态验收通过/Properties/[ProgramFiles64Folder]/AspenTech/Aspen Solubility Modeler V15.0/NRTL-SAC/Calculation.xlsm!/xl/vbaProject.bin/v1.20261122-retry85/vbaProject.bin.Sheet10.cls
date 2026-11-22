Attribute VB_Name = "Sheet10"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "cmdGoBackToWelcomePage, 1127, 0, MSForms, CommandButton"
Private Sub Worksheet_Activate()
    ActiveSheet.EnableCalculation = True
    ActiveSheet.Calculate
    ActiveSheet.EnableCalculation = False
End Sub
'Private Sub Worksheet_Deactivate()
'    Sheet10.EnableCalculation = False
'End Sub

Private Sub Worksheet_Calculate()

On Error GoTo errorhandler

If ActiveSheet.CodeName = "Sheet10" Then

    Dim MaximumScale, MinimumScale As Double
    
    Dim ActCellAddress As String
     
    ActCellAddress = ActiveCell.Address
    
    MaximumScale = Application.WorksheetFunction.Max(Range("$n$157:$o$177"))
    MinimumScale = Application.WorksheetFunction.Min(Range("$n$157:$o$177"))

    ActiveSheet.ChartObjects("Chart 1037").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = 0 'MinimumScale
        .MaximumScale = MaximumScale * 1.05
        .CrossesAt = 0 'MinimumScale
    End With

    MaximumScale = Application.WorksheetFunction.Max(Range("$e$157:$f$177"))
    MinimumScale = Application.WorksheetFunction.Min(Range("$e$157:$f$177"))

    ActiveSheet.ChartObjects("Chart 1071").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale * 0.95
        .MaximumScale = MaximumScale * 1.05
        .CrossesAt = MinimumScale * 0.95
    End With

    MaximumScale = Round(Application.WorksheetFunction.Max(Range("$r$157:$s$177")) + 0.5)
    MinimumScale = 1#

    ActiveSheet.ChartObjects("Chart 1077").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale
        .MaximumScale = MaximumScale
        .CrossesAt = MinimumScale
    End With

    MaximumScale = Round(Application.WorksheetFunction.Max(Range("$i$157:$j$177")) + 0.5)
    MinimumScale = 1#

    ActiveSheet.ChartObjects("Chart 1078").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale
        .MaximumScale = MaximumScale
        .CrossesAt = MinimumScale
    End With

    MaximumScale = Round(Application.WorksheetFunction.Max(Range("$t$157:$u$177")) + 0.5)
    MinimumScale = 0#

    ActiveSheet.ChartObjects("Chart 1084").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale
        .MaximumScale = MaximumScale
        .CrossesAt = MinimumScale
    End With

    MaximumScale = Round(Application.WorksheetFunction.Max(Range("$k$157:$l$177")) + 0.5)
    MinimumScale = 0#

    ActiveSheet.ChartObjects("Chart 1085").Activate



    With ActiveChart.Axes(xlValue)
        .MinimumScale = MinimumScale
        .MaximumScale = MaximumScale
        .CrossesAt = MinimumScale
    End With

  Range(ActCellAddress).Select

End If

Exit Sub

errorhandler:

 MsgBox "Worksheet Calculation Error!"

End Sub

Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet10" Then
  ActiveSheet.EnableCalculation = True
  ActiveSheet.Calculate
  ActiveSheet.EnableCalculation = False
End If
End Sub

Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub


