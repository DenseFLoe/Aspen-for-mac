Attribute VB_Name = "Sheet3"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "cmdGoBackToWelcomePage, 71, 0, MSForms, CommandButton"
Private Sub Worksheet_Calculate()
'
' Macro recorded 12/30/2006 by Jiangchu Liu
' Resets the Y Axis Minimum to the value in named cell VLE_Y_Min
'
Dim MaximumScale, MinimumScale As Double

On Error GoTo errorhandler:


If ActiveSheet.CodeName = "Sheet3" Then

    Dim ActCellAddress As String
     
    ActCellAddress = ActiveCell.Address
    
    MaximumScale = 10 ^ (TrimtoTens(Application.WorksheetFunction.Max(Range("$j$8:$k$11"))) + 1)
    MinimumScale = 10 ^ TrimtoTens(Application.WorksheetFunction.Min(Range("$j$8:$k$11")))
    ActiveSheet.ChartObjects("Chart 1").Activate

    With ActiveChart.Axes(xlCategory)
             .ScaleType = xlLogarithmic
            .MinimumScaleIsAuto = False
            .MaximumScaleIsAuto = False
            .MinimumScale = MinimumScale
            .MaximumScale = MaximumScale
            .MinorUnitIsAuto = True
            .MajorUnitIsAuto = True
            .Crosses = xlAutomatic
            .ReversePlotOrder = False
            .DisplayUnit = xlNone
            .CrossesAt = MinimumScale
    End With
        Application.Run "getUnits"

    '   ActiveChart.Axes(xlValue).Select

    With ActiveChart.Axes(xlValue)
        .MinimumScaleIsAuto = False
        .ScaleType = xlLogarithmic
        .MaximumScaleIsAuto = False
        .MinimumScaleIsAuto = False
        .MinimumScale = MinimumScale
        .MaximumScale = MaximumScale
        .MinorUnitIsAuto = True
        .MajorUnitIsAuto = True
        .Crosses = xlAutomatic
        .ReversePlotOrder = False
        .DisplayUnit = xlNone
        .CrossesAt = MinimumScale
    End With

    ActiveChart.SeriesCollection(2).XValues = "={" & MinimumScale & "," & MaximumScale & "}"
    ActiveChart.SeriesCollection(2).Values = "={" & MinimumScale & "," & MaximumScale & "}"
    
    Range(ActCellAddress).Select
    
End If

Exit Sub

errorhandler:
MsgBox "Worksheet Calculation Error."

End Sub

Public Function TrimtoTens(x As Double)
Dim i As Integer
For i = -3 To 5
    If x / 10 ^ i > 0 And x / 10 ^ i < 1 Then
        TrimtoTens = i - 1
        Exit For
    End If
Next

End Function


Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet3" Then
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
'    Sheet3.EnableCalculation = False
'End Sub
Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub
